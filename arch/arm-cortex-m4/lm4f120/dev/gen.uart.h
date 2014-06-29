#ifndef UART$0_H
#define UART$0_H
#include <stdio.h>
#include <hw/hw_uart.h>
#include <hw/hw_memmap.h>
#include <hw/hw_sysctl.h>

#include <dev/nvic.h>
#include <dev/cpu0.h>
#include <dev/conf_uart.h>
#include __uart$0_include

#include <core/interfaces/uart.h>
#include <core/types.h>

extern uint8_t uart$0_refcount;

static inline void uart$0_set_conf(uint32_t cpu_freq, Cuart *c)
{
	uint32_t bits;
	switch (c->bits) {
	case 5: bits = UART_LCRH_WLEN_5; break;
	case 6: bits = UART_LCRH_WLEN_6; break;
	case 7: bits = UART_LCRH_WLEN_7; break;
	default: // TODO: Make me generate an error, not default to 8bits.
	case 8: bits = UART_LCRH_WLEN_8; break;
	}

	// 1) Ensure UARTEN is cleared.
	HWREG(UART$0_BASE + UART_O_CTL) = 0;

	// 2) use SYSCLK.
	HWREG(UART$0_BASE + UART_O_CC) = 0;

	// 4) baud rate calculation
	HWREG(UART$0_BASE + UART_O_IBRD) = cpu0_freq() / (16.0 * c->baud);

	// 5) bits, parity, stop
	HWREG(UART$0_BASE + UART_O_LCRH) =
		  (bits & UART_LCRH_WLEN_M)
		| (c->stop ? UART_LCRH_STP2 : 0);

	// 6) enable uart (both TX & RX).
	HWREG(UART$0_BASE + UART_O_CTL) =
		  (UART_CTL_UARTEN)
		| (UART_CTL_RXE | UART_CTL_TXE);
}

static inline void uart$0_get_conf(uint32_t cpu_freq, Cuart *c)
{
	// take a snapshot. (volatile would cost extra)
	uint32_t flags = HWREG(UART$0_BASE + UART_O_LCRH); // flags.
	uint32_t ibr   = HWREG(UART$0_BASE + UART_O_IBRD); // baud rate register.

	switch (flags & UART_LCRH_WLEN_M) {
	case UART_LCRH_WLEN_5: c->bits = 5; break;
	case UART_LCRH_WLEN_6: c->bits = 6; break;
	case UART_LCRH_WLEN_7: c->bits = 7; break;
	case UART_LCRH_WLEN_8: c->bits = 8; break;
	}
	c->baud  = cpu0_freq() / (16 * ibr);
	c->stop = (flags == 2) & UART_LCRH_STP2;
	c->par   =((flags & UART_LCRH_PEN) ?
			(flags & UART_LCRH_EPS ? 'e' : 'o') : 'n');
}

/* breakpoint symbol: uart$0_ctor.isra.0 */
static inline void uart$0_ctor(
		uint32_t cpu_freq,
		uint32_t baud,
		uint8_t  bits,
		uint8_t  par,
		uint8_t  stop)
{
	if (uart$0_refcount++ != 0)
		return;

	// 1) clock the UART
	HWREG(SYSCTL_RCGCUART) |= SYSCTL_RCGCUART_R$0;

	// 2) clock the corresponding GPIO
	__uart$0_gpio(ctor)();

	// 3) configure gpio as AF
	__uart$0_gpio(set_afsel)(
			  (1 << __uart$0_pin_tx)
			| (1 <<__uart$0_pin_rx));

	// 4) configure gpio Pin CTL
#define X(p) __uart$0_gpio(set_pctl)(gpio_pctl_mask(__uart0_pin_ ## p), \
		gpio_pctl_entry(__uart0_pin_## p, __uart0_pin_## p ##_af))
	X(rx);
	X(tx);
#undef X
	// 5) configure UART regs.
	Cuart c = {
		.baud  = baud,
		.par   = par,
		.stop = stop,
		.bits  = bits,
	};
	uart$0_set_conf(cpu_freq, &c);
}

static inline void uart$0_dtor(void)
{
	if (uart$0_refcount == 0) {
		HWREG(SYSCTL_RCGCUART) &=~SYSCTL_RCGCUART_R$0;
		__uart$0_gpio(dtor)();
	} else --uart$0_refcount;
}

static inline int uart$0_get(void)
{
	uint32_t rx;
	while (HWREG(UART$0_BASE + UART_O_FR) & UART_FR_RXFE)
		;
	// 1) get the whole register.
	rx = HWREG(UART$0_BASE + UART_O_DR);

	// 2) check if something went wrong.
	if (rx &(~0xFF))
		return EOF;
	return rx & 0x00FF;
}

static inline int uart$0_put(int ch)
{
	// 1) wait for it to be done.
	while (HWREG(UART$0_BASE + UART_O_FR) & UART_FR_TXFF)
		;

	// 2) set the register.
	HWREG(UART$0_BASE + UART_O_DR) = (uint8_t) ch;
	return ch;
}

#endif /* UART$0_H */

#ifndef UART$0_H
#define UART$0_H
#include <stdio.h>
#include <hw/hw_uart.h>
#include <hw/hw_memmap.h>
#include <hw/hw_sysctl.h>

#include <dev/nvic.h>
#include <dev/cpu0.h>
#include <dev/gpio0.h>
#include <dev/conf_uart.h>

#include <core/interfaces/uart.h>
#include <core/types.h>

extern uint8_t uart$0_refcount;

static inline void uart$0_set_conf(struct uart_conf *c)
{
	uint32_t bits;
	switch (c->bits) {
	case 5: bits = UART_LCRH_WLEN_5;
	case 6: bits = UART_LCRH_WLEN_6;
	case 7: bits = UART_LCRH_WLEN_7;
	default: // TODO: Make me generate an error, not default to 8bits.
	case 8: bits = UART_LCRH_WLEN_8;
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

/* breakpoint symbol: uart$0_ctor.isra.0 */
static inline void uart$0_ctor(uint32_t baud, uint8_t bits, uint8_t par, uint8_t stop)
{
	if (uart$0_refcount++ != 0)
		return;

	// 1) clock the UART
	HWREG(SYSCTL_RCGCUART) |= SYSCTL_RCGCUART_R0;

	// 2) clock the corresponding GPIO
	__uart$0_gpio(ctor)();

	// 3) configure gpio as AF
	__uart$0_gpio(set_afsel)(__uart$0_pin_tx | __uart$0_pin_rx);

	// 4) configure gpio Pin CTL
#define X(p) __uart$0_gpio(set_pctl)(__uart$0_pin_ ## p, __uart$0_pin_## p ##_af);
	X(rx);
	X(tx);
#undef X
	// 5) configure UART regs.
	struct uart_conf c = {
		.baud = baud,
		.par  = par,
		.stop = stop,
		.bits = bits,
	};
	uart$0_set_conf(&c);
}

static inline void uart$0_dtor(void)
{
	if (uart$0_refcount == 0) {
		HWREG(SYSCTL_RCGCUART) &=~SYSCTL_RCGCUART_R0;
		__uart$0_gpio(dtor)();
	} else --uart$0_refcount;
}

static inline uint16_t uart$0_getchar(void)
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

static inline uint16_t uart$0_putchar(uint16_t ch)
{
	while (HWREG(UART$0_BASE + UART_O_FR) & UART_FR_TXFF)
		;
	HWREG(UART$0_BASE + UART_O_DR) = (uint8_t) ch;
	return ch;
}

#endif /* UART$0_H */

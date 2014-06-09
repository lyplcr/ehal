#ifndef UART0_H
#define UART0_H
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

extern uint8_t uart0_refcount;

static inline void uart0_set_baud(uint32_t cpufreq, uint32_t baud)
{
	float div= cpu0_freq() / (16.0 * baud);

	uint32_t idiv= div;

	HWREG(UART0_BASE + UART_O_IBRD) = idiv;
	/* TODO: find the bug in frac calculations. */
//	uint32_t fdiv= (uint32_t)((float)(div - idiv) * 64.0 + 0.5);
//	HWREG(UART0_BASE + UART_O_IBRD) = fdiv;
}

#if 0
static inline int uart0_set_opts(uint8_t bits, uint8_t par, uint8_t stop)
{
	// 1) bits in the word: [5:8] are valid.
	if (bits < 5 || bits > 8)
		return UART_EBITS;
	if (par != 'n' && par != 'o' && par != 'r')
		return UART_EPAR;
	if (stop != 1 && stop != 2)
		return UART_ESTOP;
	uint32_t bits_mask = (bits << 5);
	uint32_t par_mask;
	switch (par) {
	case 'o': 
	case 'e':
	default:
	}
}
#endif

/* breakpoint symbol: uart0_ctor.isra.0 */
static inline int uart0_ctor(uint32_t baud, uint8_t bits, uint8_t par, uint8_t stop)
{
	if (uart0_refcount++ != 0)
		return 0;
	// 1) clock uart and wait for it to take effect.
	HWREG(SYSCTL_RCGCUART) |= SYSCTL_RCGCUART_R0;
	while ((HWREG(SYSCTL_PRUART) & SYSCTL_PRUART_R0) == 0);
	// 2) use SYSCLK.
	HWREG(UART0_BASE + UART_O_CC) = 0;
	// 2) clock gpio.
	gpio0_ctor();
	// 3) (Rx: PA0, Tx: PA1) alternate function 1.
	gpio0_set_afsel(P1 | P0);
	gpio0_set_pctl( gpio_pctl_entry_mask(0) | gpio_pctl_entry_mask(1),
			gpio_pctl_entry(0, 1)   | gpio_pctl_entry(1, 1));
	// 4) baud rate calculation
	uart0_set_baud(cpu0_freq(), baud);
	// 5) 8N1
	HWREG(UART0_BASE + UART_O_LCRH) = UART_LCRH_WLEN_8;
	// 6) enable uart (both TX & RX).
	HWREG(UART0_BASE + UART_O_CTL) = UART_CTL_UARTEN
		| UART_CTL_RXE | UART_CTL_TXE;
	return 0;
}

static inline void uart0_dtor(void)
{
	if (--uart0_refcount != 0)
		return;
	HWREG(SYSCTL_RCGCUART) &=~SYSCTL_RCGCUART_R0;
	gpio0_dtor();
}

static inline uint16_t uart0_getchar(void)
{
	uint32_t rx;
	while (HWREG(UART0_BASE + UART_O_FR) & UART_FR_RXFE)
		;
	// 1) get the whole register.
	rx = HWREG(UART0_BASE + UART_O_DR);
	// 2) check if something went wrong.
	if (rx &(~0xFF))
		return EOF;
	return rx & 0x00FF;
}

static inline uint16_t uart0_putchar(uint16_t ch)
{
	while (HWREG(UART0_BASE + UART_O_FR) & UART_FR_TXFF)
		;
	HWREG(UART0_BASE + UART_O_DR) = (uint8_t) ch;
	return ch;
}

#endif /* USART0_H */

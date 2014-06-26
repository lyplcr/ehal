#ifndef UART_CONF_H
#define UART_CONF_H

#include <dev/gpio0.h>
#define __uart0_gpio(fn) gpio0_ ## fn
#define __uart0_pin_tx (P0)
#define __uart0_pin_rx (P1)

#define __uart0_pin_rx      (P1)
#define __uart0_pin_rx_af   ( 1)

#define __uart0_pin_tx      (P0)
#define __uart0_pin_tx_af   ( 1)

static inline float uart_calc_baud(uint32_t freq, uint32_t baud)
{
	return freq / (16.0 * baud);
}

static inline uint32_t uart_calc_fbaud(uint32_t freq, uint32_t baud)
{
	float f = uart_calc_baud(freq, baud);
	uint32_t i = f;
	return f = (i - f) * 64 + 0.5;
}

#endif /* UART_CONF_H */

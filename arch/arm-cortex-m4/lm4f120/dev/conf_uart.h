#ifndef UART_CONF_H
#define UART_CONF_H

#define _uart0_gpio gpio0
#define uart0_tx_pin         0
#define uart0_rx_pin         1

#define uart0_gpio_ctor      _uart0_gpio ## _ctor
#define uart0_gpio_set_afsel _uart0_gpio ## _afsel
#define uart0_gpio_set_pctl  _uart0_gpio ## _set_pctl

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

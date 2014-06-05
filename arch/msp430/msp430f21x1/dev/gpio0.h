#ifndef GPIO0_H
#define GPIO0_H
#include <stdint.h>
#include <msp430.h>

#include <lib/gpio_conf.h>
#include <core/interfaces/gpio.h>

static inline void gpio0_ctor(void)
{ /* nothing to do, it starts powered up. */
}

static inline void gpio0_dtor(void)
{
}

static inline void gpio0_set_in(uint8_t pins)
{
	P1DIR &= ~pins;
}

static inline void gpio0_set_out(uint8_t pins)
{
	P1DIR |= pins;
}

static inline void gpio0_set_dir(uint8_t pins, uint8_t in)
{
	bm_apply(P1DIR, pins,~in);
}

static inline uint8_t gpio0_read(void)
{
	return P1IN;
}

static inline void gpio0_set(uint8_t pins)
{
	P1OUT |= pins;
}

static inline void gpio0_clr(uint8_t pins)
{
	P1OUT &=~pins;
}

static inline void gpio0_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(P1OUT, pins, values);
}

static inline void gpio0_set_pullup(uint8_t pins)
{
	P1REN |= pins;
	P1OUT |= pins;
}

static inline void gpio0_clr_pullup(uint8_t pins)
{
	P1REN &=~pins;
}

static inline void gpio0_set_pulldown(uint8_t pins)
{
	P1REN |= pins;
	P1OUT &=~pins;
}

static inline void gpio0_clr_pulldown(uint8_t pins)
{
	P1REN &=~pins;
}

static inline void gpio0_set_edge_irq(uint8_t pins, uint8_t rise)
{
	P1IE |= pins;
	bm_apply(P1IES, pins, rise);
}

#endif /* GPIO0_H */

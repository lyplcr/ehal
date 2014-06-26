#ifndef GPIO$0_H
#define GPIO$0_H
#include <stdint.h>
#include <msp430.h>

#include <dev/conf_gpio.h>
#include <core/interfaces/gpio.h>

static inline void gpio$0_ctor(void)
{ /* nothing to do, it starts powered up. */
}

static inline void gpio$0_dtor(void)
{
}

static inline void gpio$0_set_in(uint8_t pins)
{
	P$1DIR &= ~pins;
}

static inline void gpio$0_set_out(uint8_t pins)
{
	P$1DIR |= pins;
}

static inline void gpio$0_set_dir(uint8_t pins, uint8_t in)
{
	bm_apply(P$1DIR, pins,~in);
}

static inline uint8_t gpio$0_read(void)
{
	return P$1IN;
}

static inline void gpio$0_set(uint8_t pins)
{
	P$1OUT |= pins;
}

static inline void gpio$0_clr(uint8_t pins)
{
	P$1OUT &=~pins;
}

static inline void gpio$0_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(P$1OUT, pins, values);
}

static inline void gpio$0_set_pullup(uint8_t pins)
{
	P$1REN |= pins;
	P$1OUT |= pins;
}

static inline void gpio$0_clr_pullup(uint8_t pins)
{
	P$1REN &=~pins;
}

static inline void gpio$0_set_pulldown(uint8_t pins)
{
	P$1REN |= pins;
	P$1OUT &=~pins;
}

static inline void gpio$0_clr_pulldown(uint8_t pins)
{
	P$1REN &=~pins;
}

static inline void gpio$0_set_edge_irq(uint8_t pins, uint8_t rise)
{
	P$1IE |= pins;
	bm_apply(P$1IES, pins, rise);
}

#endif /* GPIO$0_H */

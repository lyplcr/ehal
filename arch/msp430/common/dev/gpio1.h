#ifndef GPIO1_H
#define GPIO1_H
#include <stdint.h>
#include <core/ehal.h>
#include <msp430.h>

static inline void gpio1_ctor(void)
{ /* nothing to do, it starts powered up. */
}

static inline void gpio1_dtor(void)
{
}

static inline void gpio1_set_in(uint8_t pins)
{
	P2DIR &= ~pins;
}

static inline void gpio1_set_out(uint8_t pins)
{
	P2DIR |= pins;
}

static inline uint8_t gpio1_read(void)
{
	return P2IN;
}

static inline void gpio1_set(uint8_t pins)
{
	P2OUT |= pins;
}

static inline void gpio1_clr(uint8_t pins)
{
	P2OUT &=~pins;
}

static inline void gpio1_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(P2OUT, pins, values);
}

static inline void gpio1_set_pupd(uint8_t pins, uint8_t up)
{
	P2REN |= pins; /* pull (up/down) */
	bm_apply(P2OUT, pins, up);
}

static inline void gpio1_set_edge_irq(uint8_t pins, uint8_t rise)
{
	P2IE |= pins;
	bm_apply(P2IES, pins, rise);
}

#endif /* GPIO1_H */

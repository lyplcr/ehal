#include <stdint.h>
#include <core/ehal.h>
#include <msp430.h>

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

static inline void gpio0_set_pupd(uint8_t pins, uint8_t up)
{
	P1REN |= pins; /* pull (up/down) */
	bm_apply(P1OUT, pins, up);
}

static inline void gpio0_set_edge_irq(uint8_t pins, uint8_t rise)
{
	P1IE |= pins;
	bm_apply(P1IES, pins, rise);
}

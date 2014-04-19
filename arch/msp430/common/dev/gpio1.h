#include <stdint.h>
#include <core/ehal.h>
#include <msp430.h>

static inline void gpio1_ctor(void)
{ /* nothing to do, it starts powered up. */
}

static inline void gpio1_dtor(void)
{
}

static inline void gpio1_setin(uint8_t pins)
{
	P2DIR &= ~pins;
}

static inline void gpio1_setout(uint8_t pins)
{
	P2DIR |= pins;
}

static inline uint8_t gpio1_read(void)
{
	return P2IN;
}

static inline void gpio1_sethigh(uint8_t pins)
{
	P2OUT |= pins;
}

static inline void gpio1_setlow(uint8_t pins)
{
	P2OUT &=~pins;
}

static inline void gpio1_setto(uint8_t mask, uint8_t pins)
{
	bm_apply(P2OUT, mask, pins);
}

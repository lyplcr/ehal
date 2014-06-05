#ifndef GPIO!N_H
#define GPIO!N_H
#include <stdint.h>
#include <msp430.h>

#include <lib/gpio_conf.h>
#include <core/interfaces/gpio.h>

static inline void gpio!N_ctor(void)
{ /* nothing to do, it starts powered up. */
}

static inline void gpio!N_dtor(void)
{
}

static inline void gpio!N_set_in(uint8_t pins)
{
	P!TDIR &= ~pins;
}

static inline void gpio!N_set_out(uint8_t pins)
{
	P!TDIR |= pins;
}

static inline void gpio!N_set_dir(uint8_t pins, uint8_t in)
{
	bm_apply(P!TDIR, pins,~in);
}

static inline uint8_t gpio!N_read(void)
{
	return P!TIN;
}

static inline void gpio!N_set(uint8_t pins)
{
	P!TOUT |= pins;
}

static inline void gpio!N_clr(uint8_t pins)
{
	P!TOUT &=~pins;
}

static inline void gpio!N_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(P!TOUT, pins, values);
}

static inline void gpio!N_set_pullup(uint8_t pins)
{
	P!TREN |= pins;
	P!TOUT |= pins;
}

static inline void gpio!N_clr_pullup(uint8_t pins)
{
	P!TREN &=~pins;
}

static inline void gpio!N_set_pulldown(uint8_t pins)
{
	P!TREN |= pins;
	P!TOUT &=~pins;
}

static inline void gpio!N_clr_pulldown(uint8_t pins)
{
	P!TREN &=~pins;
}

static inline void gpio!N_set_edge_irq(uint8_t pins, uint8_t rise)
{
	P!TIE |= pins;
	bm_apply(P!TIES, pins, rise);
}

#endif /* GPIO!N_H */

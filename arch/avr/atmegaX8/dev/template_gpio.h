#ifndef GPIO!N_H
#define GPIO!N_H
#include <stdint.h>
#include <dev/conf_gpio.h>
#include <core/interfaces/gpio.h>
#include <avr/io.h>

/* DDR - Data Direction Register (In/Out)
 * PORT- Port Output data Register (High/Low);
 *       Pull-up selector if pin is input.
 * PIN - Port Input Register (High/Low) */

static inline void gpio!N_ctor(void)
{	/* Enable IRQ for gpio!N (pin masks need to be set). */
	PCICR |= (1<<PCIE!N);
}

static inline void gpio!N_dtor(void)
{	/* Disable IRQ for gpio!N. */
	PCICR &=~(1<<PCIE!N);
}

static inline void gpio!N_set_in(uint8_t pins)
{
	DDR!T &= ~pins;
}

static inline void gpio!N_set_out(uint8_t pins)
{
	DDR!T |= pins;
}

static inline void gpio!N_set_dir(uint8_t pins, uint8_t dir)
{
	bm_apply(DDR!T, pins, dir);
}

static inline uint8_t gpio!N_read(void)
{
	return PIN!T;
}

static inline void gpio!N_set(uint8_t pins)
{
	PORT!T |= pins;
}

static inline void gpio!N_clr(uint8_t pins)
{
	PORT!T &=~pins;
}

static inline void gpio!N_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(PORT!T, pins, values);
}

static inline void gpio!N_set_pullup(uint8_t pins)
{
	PORT!T |= pins;
}

static inline void gpio!N_clr_pullup(uint8_t pins)
{
	PORT!T &=~pins;
}

/* PCMSK!N - Pin Change Mask Register. (mask pin to trigger irq). */
static inline void gpio!N_set_edge_irq(uint8_t rise, uint8_t fall)
{
	extern uint8_t gpio!N_rise__;
	extern uint8_t gpio!N_fall__;

	/* emulate it. IRQ on either, dispatch on match. */
	gpio!N_rise__ = rise;
	gpio!N_fall__ = fall;
	PCMSK!N |= (rise | fall);
}

#endif /* GPIO!N_H */

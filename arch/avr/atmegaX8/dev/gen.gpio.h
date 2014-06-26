#ifndef GPIO$0_H
#define GPIO$0_H
#include <stdint.h>
#include <dev/conf_gpio.h>
#include <core/interfaces/gpio.h>
#include <avr/io.h>

/* DDR - Data Direction Register (In/Out)
 * PORT- Port Output data Register (High/Low);
 *       Pull-up selector if pin is input.
 * PIN - Port Input Register (High/Low) */

static inline void gpio$0_ctor(void)
{	/* Enable IRQ for gpio$0 (pin masks need to be set). */
	PCICR |= (1<<PCIE$0);
}

static inline void gpio$0_dtor(void)
{	/* Disable IRQ for gpio$0. */
	PCICR &=~(1<<PCIE$0);
}

static inline void gpio$0_set_in(uint8_t pins)
{
	DDR$1 &= ~pins;
}

static inline void gpio$0_set_out(uint8_t pins)
{
	DDR$1 |= pins;
}

static inline void gpio$0_set_dir(uint8_t pins, uint8_t dir)
{
	bm_apply(DDR$1, pins, dir);
}

static inline uint8_t gpio$0_read(void)
{
	return PIN$1;
}

static inline void gpio$0_set(uint8_t pins)
{
	PORT$1 |= pins;
}

static inline void gpio$0_clr(uint8_t pins)
{
	PORT$1 &=~pins;
}

static inline void gpio$0_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(PORT$1, pins, values);
}

static inline void gpio$0_set_pullup(uint8_t pins)
{
	PORT$1 |= pins;
}

static inline void gpio$0_clr_pullup(uint8_t pins)
{
	PORT$1 &=~pins;
}

/* PCMSK$0 - Pin Change Mask Register. (mask pin to trigger irq). */
static inline void gpio$0_set_edge_irq(uint8_t rise, uint8_t fall)
{
	extern uint8_t gpio$0_rise__;
	extern uint8_t gpio$0_fall__;

	/* emulate it. IRQ on either, dispatch on match. */
	gpio$0_rise__ = rise;
	gpio$0_fall__ = fall;
	PCMSK$0 |= (rise | fall);
}

#endif /* GPIO$0_H */

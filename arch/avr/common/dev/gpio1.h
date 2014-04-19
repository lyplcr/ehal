#ifndef GPIO1_H
#define GPIO1_H
#include <stdint.h>
#include <core/ehal.h>
#include <avr/io.h>

/* DDR - Data Direction Register (In/Out)
 * PORT- Port Output data Register (High/Low);
 *       Pull-up selector if pin is input.
 * PIN - Port Input Register (High/Low) */

static inline void gpio1_ctor(void)
{	/* Enable IRQ for gpio0 (pin masks need to be set). */
	PCICR |= (1<<PCIE1);
}

static inline void gpio1_dtor(void)
{	/* Disable IRQ for gpio0. */
	PCICR &=~(1<<PCIE1);
}

static inline void gpio1_set_in(uint8_t pins)
{
	DDRC &= ~pins;
}

static inline void gpio1_set_out(uint8_t pins)
{
	DDRC |= pins;
}

static inline uint8_t gpio1_read(void)
{
	return PINC;
}

static inline void gpio1_set(uint8_t pins)
{
	PORTC |= pins;
}

static inline void gpio1_clr(uint8_t pins)
{
	PORTC &=~pins;
}

static inline void gpio1_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(PORTC, pins, values);
}

static inline void gpio1_set_pupd(uint8_t pins, uint8_t up)
{	/* no pull-down in hardware */
	PORTC |= up;
}

/* PCMSK1 - Pin Change Mask Register. (mask pin to trigger irq). */
static inline void gpio1_set_edge_irq(uint8_t pins, uint8_t rise)
{	/* Only option is both edges (could be masked by software). */
	PCMSK1 |= pins;
}

#endif /* GPIO1_H */

#ifndef GPIO0_H
#define GPIO0_H
#include <stdint.h>
#include <core/ehal.h>
#include <avr/io.h>

/* DDR - Data Direction Register (In/Out)
 * PORT- Port Output data Register (High/Low);
 *       Pull-up selector if pin is input.
 * PIN - Port Input Register (High/Low) */

static inline void gpio0_ctor(void)
{	/* Enable IRQ for gpio0 (pin masks need to be set). */
	PCICR |= (1<<PCIE0);
}

static inline void gpio0_dtor(void)
{	/* Disable IRQ for gpio0. */
	PCICR &=~(1<<PCIE0);
}

static inline void gpio0_set_in(uint8_t pins)
{
	DDRB &= ~pins;
}

static inline void gpio0_set_out(uint8_t pins)
{
	DDRB |= pins;
}

static inline uint8_t gpio0_read(void)
{
	return PINB;
}

static inline void gpio0_set(uint8_t pins)
{
	PORTB |= pins;
}

static inline void gpio0_clr(uint8_t pins)
{
	PORTB &=~pins;
}

static inline void gpio0_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(PORTB, pins, values);
}

static inline void gpio0_set_pupd(uint8_t pins, uint8_t up)
{	/* no pull-down in hardware */
	PORTB |= up;
}

/* PCMSK0 - Pin Change Mask Register. (mask pin to trigger irq). */
static inline void gpio0_set_edge_irq(uint8_t pins, uint8_t rise)
{	/* Only option is both edges (could be masked by software). */
	PCMSK0 |= pins;
}

#endif /* GPIO0_H */

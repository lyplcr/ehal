#ifndef GPIO2_H
#define GPIO2_H
#include <stdint.h>
#include <core/ehal.h>
#include <avr/io.h>

/* DDR - Data Direction Register (In/Out)
 * PORT- Port Output data Register (High/Low);
 *       Pull-up selector if pin is input.
 * PIN - Port Input Register (High/Low) */

static inline void gpio2_ctor(void)
{	/* Enable IRQ for gpio2 (pin masks need to be set). */
	PCICR |= (1<<PCIE2);
}

static inline void gpio2_dtor(void)
{	/* Disable IRQ for gpio2. */
	PCICR &=~(1<<PCIE2);
}

static inline void gpio2_set_in(uint8_t pins)
{
	DDRD &= ~pins;
}

static inline void gpio2_set_out(uint8_t pins)
{
	DDRD |= pins;
}

static inline void gpio2_set_dir(uint8_t pins, uint8_t dir)
{
	bm_apply(DDRD, pins, dir);
}

static inline uint8_t gpio2_read(void)
{
	return PIND;
}

static inline void gpio2_set(uint8_t pins)
{
	PORTD |= pins;
}

static inline void gpio2_clr(uint8_t pins)
{
	PORTD &=~pins;
}

static inline void gpio2_set_to(uint8_t pins, uint8_t values)
{
	bm_apply(PORTD, pins, values);
}

static inline void gpio2_set_pullup(uint8_t pins)
{
	PORTD |= pins;
}

static inline void gpio2_clr_pullup(uint8_t pins)
{
	PORTD &=~pins;
}

/* PCMSK2 - Pin Change Mask Register. (mask pin to trigger irq). */
static inline void gpio2_set_edge_irq(uint8_t rise, uint8_t fall)
{	/* Only option is both edges (could be masked by software). */
	PCMSK2 |= (rise | fall);
}

#endif /* GPIO2_H */

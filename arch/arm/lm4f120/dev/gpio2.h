#ifndef GPIO2_H
#define GPIO2_H
#include <common/lm4f120h5qr.h>
#include <common/nvic.h>
#include <core/ehal.h>

/* Register summary:
 * SYSCTL_RGCG2_R   - enable peripherals in the BUS.
 * GPIO_PORT?_DIR_R - bitmask with direction for each pin. (in/out)
 * GPIO_PORT?_DEN_R - Digital ENable (put it into digital mode.
 * GPIO_PORT?_IS_R  - Interrupt Sense (edge=0 or level=1).
 * GPIO_PORT?_IM_R  - Interrupt Mask (enable=1 or disable=0).
 * GPIO_PORT?_ICR_R - Interrupt Mask (enable=1 or disable=0).
 */

/* keep track of ctors vs. dtors to turn off the periphera. */
extern uint8_t gpio2_refcount;

static inline void gpio2_ctor (void)
{
	gpio2_refcount++;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC;
	/* NVIC table: 2-9, p.102 of lm4f120h5qr datasheet.
	 * from: http://www.mouser.com/ds/2/405/lm4f120h5qr-124014.pdf */
	nvic_enable(2);
}

static inline void gpio2_dtor (void)
{
	if (--gpio2_refcount == 0) {
		SYSCTL_RCGC2_R &=~SYSCTL_RCGC2_GPIOC;
		nvic_disable(2);
	}
}

static inline void gpio2_set_in(uint8_t pins)
{
	GPIO_PORTC_DIR_R &=~pins;
	GPIO_PORTC_DEN_R |= pins;
}

static inline void gpio2_set_out(uint8_t pins)
{
	GPIO_PORTC_DIR_R |= pins;
	GPIO_PORTC_DEN_R |= pins;
}

static inline void gpio2_set_dir(uint8_t m, uint8_t v)
{
	bm_apply(GPIO_PORTC_DIR_R, m,~v);
	bm_apply(GPIO_PORTC_DEN_R, m,~v);
}

static inline void gpio2_set(uint8_t pins)
{
	GPIO_PORTC_DATA_R |= pins;
}

static inline void gpio2_clr(uint8_t pins)
{
	GPIO_PORTC_DATA_R &=~pins;
}

static inline void gpio2_set_to(uint8_t pins, uint8_t high)
{
	bm_apply(GPIO_PORTC_DATA_R, pins, high);
}

static inline uint8_t gpio2_read(void)
{
	return GPIO_PORTC_DATA_R;
}

static inline void gpio2_set_pullup(uint8_t pins)
{
	GPIO_PORTC_PUR_R |= pins;
	GPIO_PORTC_DR2R_R|= pins;
}

/* stubs */
static inline void gpio2_set_pulldown(uint8_t pins) {}
static inline void gpio2_set_edge_irq(uint8_t rise, uint8_t fall)
{
	GPIO_PORTC_IS_R   &=~(rise | fall); /* edge for everyone. */
	GPIO_PORTC_IBE_R  |= (rise & fall); /* IRQ on both edges. */
	GPIO_PORTC_IEV_R  &=~(fall);        /* only rising or falling. */
	GPIO_PORTC_IEV_R  |= (rise);        /* only rising or falling. */
	GPIO_PORTC_ICR_R  |= (rise | fall);
	GPIO_PORTC_IM_R   |= (rise | fall); /* pins will trigger IRQ. */
}

#endif /* GPIO2_H */

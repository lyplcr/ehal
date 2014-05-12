#ifndef GPIO!N_H
#define GPIO!N_H
#include <lm4f120h5qr.h>
#include <cortex-m4/nvic.h>
#include <dev/gpio_base.h>
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
extern uint8_t gpio!N_refcount;

static inline void gpio!N_ctor (void)
{
	gpio!N_refcount++;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIO!T;
	/* NVIC table: 2-9, p.102 of lm4f120h5qr datasheet.
	 * from: http://www.mouser.com/ds/2/405/lm4f120h5qr-124014.pdf */
	nvic_enable(GPIO!N_NVIC_ENTRY);
}

static inline void gpio!N_dtor (void)
{
	if (--gpio!N_refcount == 0) {
		SYSCTL_RCGC2_R &=~SYSCTL_RCGC2_GPIO!T;
		nvic_disable(GPIO!N_NVIC_ENTRY);
	}
}

static inline void gpio!N_set_in(uint8_t pins)
{
	GPIO_PORT!T_DIR_R &=~pins;
	GPIO_PORT!T_DEN_R |= pins;
}

static inline void gpio!N_set_out(uint8_t pins)
{
	GPIO_PORT!T_DIR_R |= pins;
	GPIO_PORT!T_DEN_R |= pins;
}

static inline void gpio!N_set_dir(uint8_t m, uint8_t v)
{
	bm_apply(GPIO_PORT!T_DIR_R, m,~v);
	bm_apply(GPIO_PORT!T_DEN_R, m,~v);
}

static inline void gpio!N_set(uint8_t pins)
{
	GPIO_PORT!T_DATA_R |= pins;
}

static inline void gpio!N_clr(uint8_t pins)
{
	GPIO_PORT!T_DATA_R &=~pins;
}

static inline void gpio!N_set_to(uint8_t pins, uint8_t high)
{
	bm_apply(GPIO_PORT!T_DATA_R, pins, high);
}

static inline uint8_t gpio!N_read(void)
{
	return GPIO_PORT!T_DATA_R;
}

static inline void gpio!N_set_pullup(uint8_t pins)
{
	GPIO_PORT!T_PUR_R |= pins;
	GPIO_PORT!T_DR2R_R|= pins;
}

/* stubs */
static inline void gpio!N_set_pulldown(uint8_t pins) {}
static inline void gpio!N_set_edge_irq(uint8_t rise, uint8_t fall)
{
	GPIO_PORT!T_IS_R   &=~(rise | fall); /* edge for everyone. */
	GPIO_PORT!T_IBE_R  |= (rise & fall); /* IRQ on both edges. */
	GPIO_PORT!T_IEV_R  &=~(fall);        /* only rising or falling. */
	GPIO_PORT!T_IEV_R  |= (rise);        /* only rising or falling. */
	GPIO_PORT!T_ICR_R  |= (rise | fall);
	GPIO_PORT!T_IM_R   |= (rise | fall); /* pins will trigger IRQ. */
}

#endif /* GPIO!N_H */

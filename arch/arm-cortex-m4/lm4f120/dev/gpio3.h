#ifndef GPIO3_H
#define GPIO3_H
#include <hw/hw_gpio.h>
#include <hw/hw_memmap.h>
#include <hw/hw_sysctl.h>

#include <dev/nvic.h>
#include <dev/gpio_conf.h>

#include <core/interfaces/gpio.h>
#include <core/types.h>

/* Register summary of APB mode:
 * SYSCTL_RGCG2_R   - enable peripherals in the BUS.
 * GPIO_PORT?_DIR_R - bitmask with direction for each pin. (in/out)
 * GPIO_PORT?_DEN_R - Digital ENable (put it into digital mode.
 * GPIO_PORT?_IS_R  - Interrupt Sense (edge=0 or level=1).
 * GPIO_PORT?_IM_R  - Interrupt Mask (enable=1 or disable=0).
 * GPIO_PORT?_ICR_R - Interrupt Mask (enable=1 or disable=0).
 */

/* keep track of ctors vs. dtors to turn off the periphera. */
extern uint8_t gpio3_refcount;

static inline void gpio3_ctor (void)
{
	if (gpio3_refcount++ != 0)
		return;
	HWREG(SYSCTL_RCGCGPIO) |= SYSCTL_RCGCGPIO_R3;
	HWREG(SYSCTL_GPIOHBCTL) |= SYSCTL_GPIOHBCTL_PORTD;
	/* NVIC table: 2-9, p.102 of lm4f120h5qr datasheet.
	 * from: http://www.mouser.com/ds/2/405/lm4f120h5qr-124014.pdf */
	nvic_enable(GPIO3_NVIC_ENTRY);

	while ((HWREG(SYSCTL_PRGPIO) & SYSCTL_PRGPIO_R3) == 0);
}

static inline void gpio3_dtor (void)
{
	if (--gpio3_refcount != 0)
		return;
	nvic_disable(GPIO3_NVIC_ENTRY);
	HWREG(SYSCTL_GPIOHBCTL) &=~SYSCTL_GPIOHBCTL_PORTD;
	HWREG(SYSCTL_RCGCGPIO) &=~SYSCTL_RCGCGPIO_R3;
}

static inline void gpio3_set_in(uint8_t pins)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DIR) &=~pins;
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DEN) |= pins;
}

static inline void gpio3_set_out(uint8_t pins)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DIR) |= pins;
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DEN) |= pins;
}

static inline void gpio3_set_dir(uint8_t pins, uint8_t in)
{
	gpio3_set_in(pins  &  in);
	gpio3_set_out(pins &(~in));
}

static inline void gpio3_set(uint8_t pins)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DATA + (pins << 2)) = pins;
}

static inline void gpio3_clr(uint8_t pins)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DATA + (pins << 2)) = 0;
}

static inline void gpio3_set_to(uint8_t pins, uint8_t high)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DATA + (pins << 2)) = high;
}

static inline uint8_t gpio3_read(void)
{
	return HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DATA);
}

static inline void gpio3_set_pullup(uint8_t pins)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_PUR)  |= pins;
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_DR2R) |= pins;
}

/* stubs */
static inline void gpio3_set_pulldown(uint8_t pins) {}
static inline void gpio3_set_edge_irq(uint8_t rise, uint8_t fall)
{
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_IS)  &=~(rise | fall); /* on edge */
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_IBE) |= (rise & fall); /* both edges */
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_IEV) &=~(fall); /* mark single edge */
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_IEV) |= (rise); /* same here */
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_ICR) |= (rise | fall); /* clear IRQs */
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_IM)  |= (rise | fall); /* will IRQ */
}

#endif /* GPIO3_H */

/* datasheet references are to:
 * http://www.mouser.com/ds/2/405/lm4f120h5qr-124014.pdf */

#ifndef GPIO$0_H
#define GPIO$0_H
#include <hw/hw_gpio.h>
#include <hw/hw_memmap.h>
#include <hw/hw_sysctl.h>

#include <dev/nvic.h>
#include <dev/conf_gpio.h>

#include <core/interfaces/gpio.h>
#include <core/types.h>

/* keep track of refcount it to turn off the peripheral only when all users have
 * finished. */
extern uint8_t gpio$0_refcount;

static inline void gpio$0_ctor (void)
{
	if (gpio$0_refcount++ != 0)
		return;
	// 1) clock gpio and put in AHB mode.
	HWREG(SYSCTL_RCGCGPIO) |= SYSCTL_RCGCGPIO_R$0;
	HWREG(SYSCTL_GPIOHBCTL) |= SYSCTL_GPIOHBCTL_PORT$1;
	// 2) ready to handle IRQs.
	nvic_enable(GPIO$0_NVIC_ENTRY);
	// 3) wait for clock to take effect.
	while ((HWREG(SYSCTL_PRGPIO) & SYSCTL_PRGPIO_R$0) == 0);
	// 4) all pins are digital.
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DEN) = 0xFF;
}

static inline void gpio$0_dtor (void)
{
	if (--gpio$0_refcount != 0)
		return;
	nvic_disable(GPIO$0_NVIC_ENTRY);
	HWREG(SYSCTL_GPIOHBCTL) &=~SYSCTL_GPIOHBCTL_PORT$1;
	HWREG(SYSCTL_RCGCGPIO) &=~SYSCTL_RCGCGPIO_R$0;
}

static inline void gpio$0_set_in(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DIR) &=~pins;
}

static inline void gpio$0_set_out(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DIR) |= pins;
}

static inline void gpio$0_set_dir(uint8_t pins, uint8_t in)
{
	gpio$0_set_in(pins  &  in);
	gpio$0_set_out(pins &(~in));
}

static inline void gpio$0_set(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DATA + (pins << 2)) = pins;
}

static inline void gpio$0_clr(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DATA + (pins << 2)) = 0;
}

static inline void gpio$0_set_to(uint8_t pins, uint8_t high)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DATA + (pins << 2)) = high;
}

static inline uint8_t gpio$0_read(void)
{
	return HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DATA);
}

static inline void gpio$0_set_pullup(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_PUR)  |= pins;
}

/* stubs */
static inline void gpio$0_set_pulldown(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_PDR)  |= pins;
}
static inline void gpio$0_set_edge_irq(uint8_t rise, uint8_t fall)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_IS)  &=~(rise | fall); /* on edge */
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_IBE) |= (rise & fall); /* both edges */
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_IEV) &=~(fall); /* mark single edge */
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_IEV) |= (rise); /* same here */
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_ICR) |= (rise | fall); /* clear IRQs */
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_IM)  |= (rise | fall); /* will IRQ */
}

/* Not in GPIO interface. (for other devices usage)
 * ========================================================================== */
static inline void gpio$0_set_afsel(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_AFSEL) |= pins;
}

/* mask is a bitmask in the format ([0..f] << (4*pin)) for each pin.
 *
 * NOTE: check datasheet: p.647 */

static inline void gpio$0_set_pctl(uint32_t mask, uint32_t value)
{
	bm_apply(HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_PCTL), mask, value);
}

static inline void gpio$0_set_adc_trigger(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_ADCCTL) |= pins;
}

static inline void gpio$0_set_dma_trigger(uint8_t pins)
{
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_DMACTL) |= pins;
}

#endif /* GPIO$0_H */

#include <dev/gpio2.h>

uint8_t gpio2_refcount=0;

__attribute__((weak))
void gpio2_irq(uint8_t pins) {}

void gpioC_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTC_AHB_BASE + GPIO_O_RIS);
	gpio2_irq(gpio2_read());
	HWREG(GPIO_PORTC_AHB_BASE + GPIO_O_ICR) = ris;
}

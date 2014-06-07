#include <dev/gpio4.h>

uint8_t gpio4_refcount=0;

__attribute__((weak))
void gpio4_irq(uint8_t pins) {}

void gpioE_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTE_AHB_BASE + GPIO_O_RIS);
	gpio4_irq(gpio4_read());
	HWREG(GPIO_PORTE_AHB_BASE + GPIO_O_ICR) = ris;
}

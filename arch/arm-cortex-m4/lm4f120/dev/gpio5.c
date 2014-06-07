#include <dev/gpio5.h>

uint8_t gpio5_refcount=0;

__attribute__((weak))
void gpio5_irq(uint8_t pins) {}

void gpioF_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTF_AHB_BASE + GPIO_O_RIS);
	gpio5_irq(gpio5_read());
	HWREG(GPIO_PORTF_AHB_BASE + GPIO_O_ICR) = ris;
}

#include <dev/gpio0.h>

uint8_t gpio0_refcount=0;

__attribute__((weak))
void gpio0_irq(uint8_t pins) {}

void gpioA_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTA_AHB_BASE + GPIO_O_RIS);
	gpio0_irq(gpio0_read());
	HWREG(GPIO_PORTA_AHB_BASE + GPIO_O_ICR) = ris;
}

#include <dev/gpio3.h>

uint8_t gpio3_refcount=0;

__attribute__((weak))
void gpio3_irq(uint8_t pins) {}

void gpioD_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_RIS);
	gpio3_irq(gpio3_read());
	HWREG(GPIO_PORTD_AHB_BASE + GPIO_O_ICR) = ris;
}

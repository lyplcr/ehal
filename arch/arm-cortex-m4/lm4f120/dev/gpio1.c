#include <dev/gpio1.h>

uint8_t gpio1_refcount=0;

__attribute__((weak))
void gpio1_irq(uint8_t pins) {}

void gpioB_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORTB_AHB_BASE + GPIO_O_RIS);
	gpio1_irq(gpio1_read());
	HWREG(GPIO_PORTB_AHB_BASE + GPIO_O_ICR) = ris;
}

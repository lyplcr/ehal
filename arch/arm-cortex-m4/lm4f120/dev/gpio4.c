#include <dev/gpio4.h>

uint8_t gpio4_refcount=0;

__attribute__((weak))
void gpio4_irq(uint8_t pins) {}

void gpioE_irq_handler(void)
{
	uint32_t ris = GPIO_PORTE_RIS_R;
	gpio4_irq(gpio4_read());
	GPIO_PORTE_ICR_R = ris; /* clear handled pins. */
}

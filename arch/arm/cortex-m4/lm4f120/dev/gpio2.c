#include <dev/gpio2.h>

uint8_t gpio2_refcount=0;

__attribute__((weak))
void gpio2_irq(uint8_t pins) {}

void gpioC_irq_handler(void)
{
	uint32_t ris = GPIO_PORTC_RIS_R;
	gpio2_irq(gpio2_read());
	GPIO_PORTC_ICR_R = ris; /* clear handled pins. */
}

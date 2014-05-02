#include <dev/gpio3.h>

uint8_t gpio3_refcount=0;

__attribute__((weak))
void gpio3_irq(uint8_t pins) {}

void gpioD_irq_handler(void)
{
	uint32_t ris = GPIO_PORTD_RIS_R;
	gpio3_irq(gpio3_read());
	GPIO_PORTD_ICR_R = ris; /* clear handled pins. */
}

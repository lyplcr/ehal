#include <dev/gpio0.h>

uint8_t gpio0_refcount=0;

__attribute__((weak))
void gpio0_irq(uint8_t pins) {}

void gpio0_irq_handler(void)
{
	uint32_t ris = GPIO_PORTA_RIS_R;
	gpio0_irq(gpio0_read());
	GPIO_PORTA_ICR_R = ris; /* clear handled pins. */
}

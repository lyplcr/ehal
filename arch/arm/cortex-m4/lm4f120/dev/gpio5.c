#include <dev/gpio5.h>

uint8_t gpio5_refcount=0;

__attribute__((weak))
void gpio5_irq(uint8_t pins) {}

void gpio5_irq_handler(void)
{
	uint32_t ris = GPIO_PORTF_RIS_R;
	gpio5_irq(gpio5_read());
	GPIO_PORTF_ICR_R = ris; /* clear handled pins. */
}

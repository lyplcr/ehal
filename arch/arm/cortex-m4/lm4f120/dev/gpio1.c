#include <dev/gpio1.h>

uint8_t gpio1_refcount=0;

__attribute__((weak))
void gpio1_irq(uint8_t pins) {}

void gpio1_irq_handler(void)
{
	uint32_t ris = GPIO_PORTB_RIS_R;
	gpio1_irq(gpio1_read());
	GPIO_PORTB_ICR_R = ris; /* clear handled pins. */
}

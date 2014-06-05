#include <dev/gpio!N.h>

uint8_t gpio!N_refcount=0;

__attribute__((weak))
void gpio!N_irq(uint8_t pins) {}

void gpio!T_irq_handler(void)
{
	uint32_t ris = GPIO_PORT!T_RIS_R;
	gpio!N_irq(gpio!N_read());
	GPIO_PORT!T_ICR_R = ris; /* clear handled pins. */
}

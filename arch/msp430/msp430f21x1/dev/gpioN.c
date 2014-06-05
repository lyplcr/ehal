#include <dev/gpio!N.h>

__attribute__((weak))
void gpio!N_irq(uint8_t v) {}

/* repass the IRQ to user. */
__attribute__((interrupt(PORT!T_VECTOR)))
void _gpio!N_irq_handler(void)
{
	uint8_t mask = P!TIFG;
	gpio!N_irq(gpio!N_read());
	P!TIFG &=~mask; /* clear trigger pins. */
}

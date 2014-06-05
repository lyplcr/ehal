#include <dev/gpio0.h>

__attribute__((weak))
void gpio0_irq(uint8_t v) {}

/* repass the IRQ to user. */
__attribute__((interrupt(PORT1_VECTOR)))
void _gpio0_irq_handler(void)
{
	uint8_t mask = P1IFG;
	gpio0_irq(gpio0_read());
	P1IFG &=~mask; /* clear trigger pins. */
}

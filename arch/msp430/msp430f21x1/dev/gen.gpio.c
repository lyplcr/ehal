#include <dev/gpio$0.h>

__attribute__((weak))
void gpio$0_irq(uint8_t v) {}

/* repass the IRQ to user. */
__attribute__((interrupt(PORT$1_VECTOR)))
void _gpio$0_irq_handler(void)
{
	uint8_t mask = P$1IFG;
	gpio$0_irq(gpio$0_read());
	P$1IFG &=~mask; /* clear trigger pins. */
}

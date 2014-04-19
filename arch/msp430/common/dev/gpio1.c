#include <core/ehal.h>
#include <dev/gpio1.h>

__attribute__((weak))
void gpio1_irq(uint8_t v) {}

/* repass the IRQ to user. */
__attribute__((interrupt(PORT2_VECTOR)))
void _gpio1_irq_handler(void)
{
	gpio1_irq(gpio1_read());
	P2IFG = 1; /* clear all flag */
}

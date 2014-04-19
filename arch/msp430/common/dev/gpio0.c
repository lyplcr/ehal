#include <core/ehal.h>
#include <dev/gpio0.h>

__attribute__((weak))
void gpio0_irq(uint8_t v) {}

/* repass the IRQ to user. */
__attribute__((interrupt(PORT1_VECTOR)))
void _gpio0_irq_handler(void)
{
	gpio0_irq(gpio0_read());
	P1IFG = 0; /* clear all flag */
}

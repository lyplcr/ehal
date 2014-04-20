#include <dev/gpio0.h>
#include <avr/interrupt.h>

__attribute__((weak))
void gpio0_irq(uint8_t v) {}

ISR(PCINT0_vect)
{
	gpio0_irq(gpio0_read());
}

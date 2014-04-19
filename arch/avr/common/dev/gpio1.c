#include <dev/gpio1.h>
#include <avr/interrupt.h>

__attribute__((weak))
void gpio1_irq(uint8_t v) {}

ISR(PCINT1_vect)
{
	gpio1_irq(gpio1_read());
}

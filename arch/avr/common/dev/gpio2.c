#include <dev/gpio2.h>
#include <avr/interrupt.h>

__attribute__((weak))
void gpio2_irq(uint8_t v) {}

ISR(PCINT2_vect)
{
	gpio2_irq(gpio2_read());
}

#include <dev/gpio!N.h>
#include <avr/interrupt.h>

__attribute__((weak))
void gpio!N_irq(uint8_t v) {}

ISR(PCINT!N_vect)
{
	gpio!N_irq(gpio!N_read());
}

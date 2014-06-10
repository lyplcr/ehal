#include <dev/gpio!N.h>
#include <avr/interrupt.h>

uint8_t gpio!N_rise__;
uint8_t gpio!N_fall__;

__attribute__((weak))
void gpio!N_irq(uint8_t v) {}

ISR(PCINT!N_vect)
{
	static uint8_t from;
	uint8_t to = gpio!N_read();
	uint8_t changed = from ^ to;

	/* simulate rise only and fall only IRQs. */
	if ((changed & gpio!N_rise__ &   to)) gpio!N_irq(to);
	if ((changed & gpio!N_fall__ & from)) gpio!N_irq(to);

	from = to;
}

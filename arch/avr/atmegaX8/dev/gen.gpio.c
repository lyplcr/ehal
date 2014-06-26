#include <dev/gpio$0.h>
#include <avr/interrupt.h>

uint8_t gpio$0_rise__;
uint8_t gpio$0_fall__;

__attribute__((weak))
void gpio$0_irq(uint8_t v) {}

ISR(PCINT$0_vect)
{
	static uint8_t from;
	uint8_t to = gpio$0_read();
	uint8_t changed = from ^ to;

	/* simulate rise only and fall only IRQs. */
	if ((changed & gpio$0_rise__ &   to)) gpio$0_irq(to);
	if ((changed & gpio$0_fall__ & from)) gpio$0_irq(to);

	from = to;
}

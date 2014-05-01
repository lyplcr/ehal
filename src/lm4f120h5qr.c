#include <stdint.h>
#include <dev/cpu0.h>
#include <dev/gpio5.h> /* portF */

/* All on portF */
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1
#define LED_B P2
#define LED_G P3
#define SW1   P4

void gpio5_irq(uint8_t pins)
{
	gpio5_set(LED_B);
}

__attribute__((used)) /* LTO is trying to remove main... */
int main(int argc, char *argv[]) {
	cpu0_ctor();
	gpio5_ctor();

	gpio5_set_out(LED_R|LED_G|LED_B);

	gpio5_set_in(SW1);
	gpio5_set_pullup(SW1);
	gpio5_set_edge_irq(0, SW1);
	NVIC_EN0_R = NVIC_EN0_INT30;  // (h) enable interrupt 30 in NVIC

	while (1) {
		/* make it blink on and off (using the button and IRQ) */
		volatile uint16_t i;
		i=0; while (--i);
		gpio5_clr(LED_B);
	}
	return 0;
}

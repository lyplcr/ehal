#include <dev/cpu0.h>
#include <dev/gpio5.h>
#include <dev/uart0.h>

/* All on portF */
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1
#define LED_B P2
#define LED_G P3
#define SW1   P4

uint8_t hex(uint8_t x)
{
	return "0123456789abcdef"[x & 0x0F];
}

int main(int argc, char *argv[])
{
	bool _r = false, _g = false, _b = false;

	cpu0_ctor();
	uart0_ctor(57600, 0, 0, 0);

	gpio5_ctor();
	gpio5_set_out(LED_R | LED_G | LED_B);

	for (;;) {
		uint16_t ch = uart0_getchar();

		if (ch != EOF) {
			uart0_putchar(ch);
			uart0_putchar(':');
			uart0_putchar('0');
			uart0_putchar('x');
			uart0_putchar(hex(ch >> 4));
			uart0_putchar(hex(ch >> 0));
			uart0_putchar('\r');
			uart0_putchar('\n');
		}

		if (ch == 'r') _r = !_r;
		if (ch == 'g') _g = !_g;
		if (ch == 'b') _b = !_b;

		gpio5_set_to(LED_R, _r ? LED_R : 0);
		gpio5_set_to(LED_G, _g ? LED_G : 0);
		gpio5_set_to(LED_B, _b ? LED_B : 0);
	}
	cpu0_dtor();
	return 0;
}

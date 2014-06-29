#include <dev/cpu0.h>
#include <dev/gpio5.h>
#include <dev/uart0.h>
#include <core/interfaces/uart.h>
extern const Iuart uart0;

/* All on portF / gpio5 */
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1
#define LED_B P2
#define LED_G P3
#define SW1   P4

uint8_t tohex(uint8_t x) { return "0123456789abcdef"[x & 0x0F]; }
void putchar_block(int (*put)(int), uint8_t x) { while (put(x) == EOF); }

void _puts(int (*put)(int), char *s)
{
	do {
		put(*s);
	} while (*s++);
}

void puthex(uint8_t ch, int (*put)(int)) {
	_puts(put, "0x");
	putchar_block(put, tohex(ch >> 4));
	putchar_block(put, tohex(ch >> 0));
	_puts(put, "\r\n");
}


int main(int argc, char *argv[])
{
	bool _r = false, _g = false, _b = false;

	cpu0_ctor();
	uart0_ctor(cpu0_freq(), 115200, 8, 'n', 1);

	gpio5_ctor();
	gpio5_set_out(LED_R | LED_G | LED_B);

	for (;;) {
		uint16_t ch = uart0.get();

		if (ch != EOF) puthex(ch, uart0_put);
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

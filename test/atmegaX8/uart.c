#include <dev/cpu0.h>
#include <dev/uart0.h>

int main(int argc, char *argv[])
{
	cpu0_ctor();
	uart0_ctor(9600, 8, 'n', 1);
	uart0_putchar('o');
	uart0_putchar('k');

	for (;;) {
		int ch = uart0_getchar();
		if (ch == EOF) {
		} else {
			uart0_putchar(ch);
		}
	}
	return 0;
}

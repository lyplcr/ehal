#include <dev/cpu0.h>
#include <dev/uart0.h>

int main(int argc, char *argv[])
{
	cpu0_ctor();
	uart0_ctor(cpu0_freq(), 19200, 8, 'n', 1);

	uart0_put('o');
	uart0_put('k');

	for (;;) {
		int ch = uart0_get();
		if (ch == EOF)
			continue;

		uart0_put(':');
		uart0_put(ch);
	}
	return 0;
}

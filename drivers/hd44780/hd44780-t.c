#include <stdio.h>

#include <core/interfaces/gpio.h>
#include <core/interfaces/uart.h>

#include <dev/cpu0.h>
#include <dev/gpio0.h>
#include <dev/uart0.h>

#include <drivers/hd44780/hd44780.h>

const static Iuart uart0 = {
	.ctor    = uart0_ctor,

	.put     = uart0_put,
	.get     = uart0_get,
};

const static Igpio gpio0 = {
	.ctor    = gpio0_ctor,
	.dtor    = gpio0_dtor,

	.read    = gpio0_read,
	.set_to  = gpio0_set_to,

	.set_in  = gpio0_set_in,
	.set_out = gpio0_set_out,
	.set_dir = gpio0_set_dir,

};

const static HD44780 display = {
	.ctl  = &gpio0,
	.data = &gpio0,

	.data0 = 0,
	.rs    = P4,
	.rw    = P5,
	.e     = P6,
};

void _puts(char *s, int (*put)(int ch, const void *arg), const void *arg)
{
	for (; *s; s++) {
		while (put(*s, arg) == EOF);
	}
}

int main(int argc, char *argv[])
{
	cpu0_ctor();
	uart0_ctor(cpu0_freq(), 19200, 8, 'n', 1);
	hd44780_ctor(&display);
	uart0_put(':');

	for (;;) {
		int c = uart0_get();
		if (c != EOF) {
			uart0_put(c);
		}
	}
	return 0;
}

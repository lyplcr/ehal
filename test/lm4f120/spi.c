#include <dev/cpu0.h>
#include <dev/spi0.h>
#include <dev/gpio5.h>

/* All on portF */
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1
#define LED_B P2
#define LED_G P3
#define SW1   P4

int main(int argc, char *argv[])
{
	cpu0_ctor();
	gpio5_ctor();
	gpio5_set_out(LED_R);
	spi0_ctor(cpu0_freq(), 8000000, SPI_MSB | 0, 8);

	uint8_t r = spi0_rw8(0xAA);
	if (r == 0xAA)
		gpio5_set(LED_R);

	cpu0_halt();
	return 0;
}

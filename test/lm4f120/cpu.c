#include <dev/cpu0.h>
#include <dev/gpio5.h>

/* All on portF */
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1
#define LED_B P2
#define LED_G P3
#define SW1   P4

static void _delay(int32_t count) {
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
	     : : [count]"r"(count) : "cc");
}

void delay_s(void)
{
	cpu0_busywait_ms(1000);
}

int main(int argc, char *argv[])
{
	cpu0_ctor();

	gpio5_ctor();

	gpio5_set_out(LED_R | LED_G | LED_B);

	for (;;) {
		gpio5_set(LED_R);
		delay_s();
		gpio5_clr(LED_R);
		delay_s();
	}
	cpu0_dtor();
	return 0;
}

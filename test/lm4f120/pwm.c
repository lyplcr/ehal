#include <dev/cpu0.h>
#include <dev/pwm0.h>
#include <dev/pwm1.h>
#include <dev/gpio5.h>

// gpio5
#define SW2   P0 /* hard masked by nmi. */
#define LED_R P1 // pwm0_b
#define LED_B P2 // pwm1_a
#define LED_G P3 // pwm1_b
#define SW1   P4

volatile uint16_t i=0, j=0;

int main(int argc, char *argv[])
{
	cpu0_ctor();

	pwm0_ctor(cpu0_freq(), 0);
	pwm1_ctor(cpu0_freq(), 0);

	//pwm1_load_a(0);
	//pwm1_load_b(65535);

	pwm0_up_to(1, 100);
	pwm1_up_to(0, 100);
	pwm1_up_to(1, 100);

	while (1) {
		pwm0_set_to(1, (i+ 0) % 100);
		pwm1_set_to(0, (i+33) % 100);
		pwm1_set_to(1, (i+67) % 100);

		j = 0; while (--j);
		i++;
	}
	return 0;
}

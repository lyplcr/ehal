#include <dev/pwm$0.h>
#include <core/interfaces/pwm.h>

uint8_t timer$0_refcount;

const Ipwm pwm$0 = {
	.ctor = pwm$0_ctor,
	.dtor = pwm$0_dtor,

	.set_to = pwm$0_set_to,
};

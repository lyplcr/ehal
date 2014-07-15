#ifndef PWM$0_H
#define PWM$0_H
#include <assert.h>
#include <stdint.h>

#include <hw/hw_timer.h>
#include <hw/hw_memmap.h>
#include <hw/hw_sysctl.h>

#include <dev/conf_pwm.h>
#include __pwm$0_include

#include <core/types.h>

extern uint8_t timer$0_refcount;

#define TIMER_CFG_USE_A_AND_B 0x04

// enabling both channels (A and B)
static inline void pwm$0_set_conf(void)
{
	// 1) Disable it to change.
	HWREG(TIMER$0_BASE + TIMER_O_CTL) = 0;
	// 2) (GPTMCFG) = 0x04;
	HWREG(TIMER$0_BASE + TIMER_O_CFG) = TIMER_CFG_USE_A_AND_B;
	// 3) (GPTMTnMR) = 
	//	TnAMS = 1
	//	TnCMR = 0
	//	TnMR  = 2
	HWREG(TIMER$0_BASE + TIMER_O_TAMR) =
		  TIMER_TAMR_TAAMS        // pwm mode. (as in not capture.)
		| TIMER_TAMR_TAMR_PERIOD; // periodic.
	HWREG(TIMER$0_BASE + TIMER_O_TBMR) =
		  TIMER_TBMR_TBAMS        // pwm mode. (as in not capture.)
		| TIMER_TBMR_TBMR_PERIOD; // periodic.
	// 4) (GPTMCTL) =
	//	TnPWML = 1 (for inverted output)
	
	// 5) (GPTMTnPR) = prescaler.

	// 6) configure interrupts.

	// 7) (GPTMTnILR) load start value.
	HWREG(TIMER$0_BASE + TIMER_O_TAILR) = 0;
	HWREG(TIMER$0_BASE + TIMER_O_TBILR) = 0;

	// 8) (GPTMTnMATCHR) load match value.
	HWREG(TIMER$0_BASE + TIMER_O_TAMATCHR) = 0;
	HWREG(TIMER$0_BASE + TIMER_O_TBMATCHR) = 0;

	// 9) (GPTMCTL) = TnEN (enable PWM) go!
	HWREG(TIMER$0_BASE + TIMER_O_CTL) =
		  TIMER_CTL_TAEN
		| TIMER_CTL_TBEN;

}

static inline void pwm$0_up_to(uint8_t channel, uint16_t v)
{
	switch (channel) {
	case 0: HWREG(TIMER$0_BASE + TIMER_O_TAILR) = v; break;
	case 1: HWREG(TIMER$0_BASE + TIMER_O_TBILR) = v; break;
	default:assert("My PWM only has 2 channels.");
	}
}

static inline void pwm$0_set_to(uint8_t channel, uint16_t v)
{
	switch (channel) {
	case 0: HWREG(TIMER$0_BASE + TIMER_O_TAMATCHR) = v; break;
	case 1: HWREG(TIMER$0_BASE + TIMER_O_TBMATCHR) = v; break;
	default:assert("My PWM only has 2 channels.");
	}
}

static inline uint8_t pwm$0_ctor(uint32_t cpu, uint32_t pwm)
{
	if (timer$0_refcount++ != 0)
		return 0;

	// 1) clock the TIMER
	HWREG(SYSCTL_RCGCTIMER) |= SYSCTL_RCGCTIMER_R$0;

	__pwm$0_gpio(ctor)();
	__pwm$0_gpio(set_afsel)(
			  (1 <<__pwm$0_pin_a)
			| (1 <<__pwm$0_pin_b));
#define X(p) __pwm$0_gpio(set_pctl)(gpio_pctl_mask(__pwm$0_pin_ ## p), \
		gpio_pctl_entry(__pwm$0_pin_## p, __pwm$0_pin_## p ##_af))
	X(a);
	X(b);
#undef X
	pwm$0_set_conf();

	// 2 channels per device.
	return 2;
}

static inline void pwm$0_dtor(void)
{
	if (timer$0_refcount == 0) {
		HWREG(SYSCTL_RCGCTIMER) &=~SYSCTL_RCGCTIMER_R$0;
		__pwm$0_gpio(dtor)();
	} else --timer$0_refcount;
}

#endif /* PWM$0_H */

#include <msp430.h>
#include <core/ehal.h>

static inline void cpu0_ctor(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	_BIS_SR(GIE);
}

static inline void cpu0_dtor(void)
{
}

static inline void cpu0_sleep_level(uint8_t level)
{
	switch (level) {
	case 4:	_BIS_SR(LPM4_bits); break;
	case 3: _BIS_SR(LPM3_bits); break;
	case 2: _BIS_SR(LPM2_bits); break;
	case 1: _BIS_SR(LPM1_bits); break;
	default:
	case 0: _BIS_SR(LPM0_bits); break;
	}
}

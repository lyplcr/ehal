#ifndef CPU0_H
#define CPU0_H

#include <avr/io.h>
#include <avr/interrupt.h>

static inline void cpu0_ctor(void)
{
	sei();
}

#endif /* CPU0_H */

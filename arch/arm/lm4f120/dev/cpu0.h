#ifndef CPU0_H
#define CPU0_H
#include <core/ehal.h>

static inline void cpu0_enable_interrupts(void)
{
	asm("CPSIE  I");
}

static inline void cpu0_disable_interrupts(void)
{
	asm("CPSID  I");
}

static inline void cpu0_ctor(void)
{
	cpu0_enable_interrupts();
}

#endif /* CPU0_H */

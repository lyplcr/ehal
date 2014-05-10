#ifndef CPU0_H
#define CPU0_H
#include <core/ehal.h>

static inline void cpu0_enable_irqs(void)
{
	asm("CPSIE  I");
}

static inline void cpu0_disable_irqs(void)
{
	asm("CPSID  I");
}

static inline void cpu0_halt(void)
{
	cpu0_disable_irqs();
	asm("WFI"); /* wait for irq. */
}

static inline void cpu0_ctor(void)
{
	cpu0_enable_irqs();
}

static inline void cpu0_dtor(void)
{
	cpu0_halt();
}


/* stubs, not required for milestone. */
static inline void cpu0_reset(void) {}
static inline void cpu0_busywait_ms(uint16_t ms) {}
static inline uint8_t cpu0_boot_cause(void) { return CPU_BOOT_INVALID; }

#endif /* CPU0_H */

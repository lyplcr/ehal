#ifndef CPU0_H
#define CPU0_H
#include <hw/hw_sysctl.h>
#include <core/types.h>
#include <core/interfaces/cpu.h>

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
	HWREG(SYSCTL_RCC) = SYSCTL_RCC_BYPASS
		| SYSCTL_RCC_XTAL_16MHZ				/* 16MHz */
		| SYSCTL_RCC_OSCSRC_MAIN			/* main clk */
		| SYSCTL_RCC_SYSDIV_4 | SYSCTL_RCC_USESYSDIV;	/* PLL @50MHz */
	// wait for the PLL to lock by polling PLLLRIS
	while ((HWREG(SYSCTL_RIS) & SYSCTL_RIS_PLLLRIS) == 0);
	HWREG(SYSCTL_RCC) &=~SYSCTL_RCC_BYPASS;

	cpu0_enable_irqs();
}

static inline void cpu0_dtor(void)
{
	cpu0_halt();
}

static inline uint32_t cpu0_freq(void)
{
	uint32_t freq = 50000000; /* 50MHz */
	return freq;
}

/* stubs, not required for milestone. */
static inline void cpu0_reset(void) {}

static void cpu0_delay_cycles(int32_t count)
{
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
	     : : [count]"r"(count) : "cc");
}

static inline void cpu0_busywait_ms(uint16_t ms)
{
	cpu0_delay_cycles(ms * 16000);
}

static inline uint8_t cpu0_boot_cause(void) { return 0; }

#endif /* CPU0_H */

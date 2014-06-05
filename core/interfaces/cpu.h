#ifndef CPU_H
#define CPU_H
#include <stdint.h>

#define CPU_BOOT_POWER_UP 0
#define CPU_BOOT_SOFT     1
#define CPU_BOOT_WDT      2
#define CPU_BOOT_HARD     3

struct cpu_interface {
	void    (*ctor)        (void); /**< init pll, irqs, etc... */
	void    (*dtor)        (void); /**< equivalent to halt. */
	void    (*halt)        (void); /**< or stall, stop the execution. */

	void    (*enable_irqs)(void);
	void    (*disable_irqs)(void);

	void    (*reset)       (void);
	void    (*busywait_ms) (uint16_t ms); /**< at least this. */
	uint8_t (*boot_cause)  (void);
};

#endif /* CPU_H */

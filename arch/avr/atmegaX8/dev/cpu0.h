#ifndef CPU0_H
#define CPU0_H

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 8000000
#endif
#include <util/delay.h>

extern uint8_t cpu0_irq_lock;

static inline void cpu0_halt(void)
{
	cli();
	while (1);
}

static inline void cpu0_ctor(void)
{
	sei();
}

__attribute__((always_inline))
static inline void cpu0_busywait_us(uint16_t us)
{
	_delay_us(us);
}

static inline void cpu0_dtor(void)
{
	cpu0_halt();
}

static inline void cpu0_enter_critical(void)
{
	if (cpu0_irq_lock++ == 0)
		cli();
}

static inline void cpu0_leave_critical(void)
{
	if (--cpu0_irq_lock == 0)
		sei();
}

static inline uint32_t cpu0_freq(void)
{
	return F_CPU;
}

#endif /* CPU0_H */

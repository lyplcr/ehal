#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>
#include <hw/hw_nvic.h>
#include <core/types.h>

static inline void nvic_enable(uint8_t irq)
{
	HWPTR(NVIC_EN0)[irq / 32] |= 1 << (irq & 0xFFFFFFFF);
}

static inline void nvic_disable(uint8_t irq)
{
	HWPTR(NVIC_DIS0)[irq / 32] |= 1 << (irq & 0xFFFFFFFF);
}

static inline void nvic_set_pending(uint8_t irq)
{
	HWPTR(NVIC_PEND0)[irq / 32] |= 1 << (irq & 0xFFFFFFFF);
}
static inline void nvic_clr_pending(uint8_t irq)
{
	HWPTR(NVIC_UNPEND0)[irq / 32] |= 1 << (irq & 0xFFFFFFFF);
}

static inline void nvic_active(uint8_t irq)
{
	HWPTR(NVIC_ACTIVE0)[irq / 32] |= 1 << (irq & 0xFFFFFFFF);
}

/* stub. */
static inline void nvic_set_prio(uint8_t irq, uint8_t prio) {}



#endif /* NVIC_H */

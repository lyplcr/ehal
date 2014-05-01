#ifndef NVIC_H
#define NVIC_H
#include <stdint.h>
#include <dev/hw/hw_nvic.h>

/* Contiguous register arrays.
 *
 * EN[0-4]     - interrupt set enable  (bits: 0-138)
 * DIS[0-4]    - interrupt clr enable  (bits: 0-138)
 * PEND[0-4]   - interrupt set pending (bits: 0-138)
 * UNPEND[0-4] - interrupt clr pending (bits: 0-138)
 * ACTIVE[0-4] - interrupt set active  (bits: 0-138) */

static inline void nvic_enable(uint8_t irq)
{
	((uint32_t *)NVIC_EN0)[irq / 32] |= 1 << irq;
}

static inline void nvic_disable(uint8_t irq)
{
	((uint32_t *)NVIC_DIS0)[irq / 32] |= 1 << irq;
}

static inline void nvic_set_pending(uint8_t irq)
{
	((uint32_t *)NVIC_PEND0)[irq / 32] |= 1 << irq;
}
static inline void nvic_clr_pending(uint8_t irq)
{
	((uint32_t *)NVIC_UNPEND0)[irq / 32] |= 1 << irq;
}

static inline void nvic_active(uint8_t irq)
{
	((uint32_t *)NVIC_ACTIVE0)[irq / 32] |= 1 << irq;
}

/* stub. */
static inline void nvic_set_prio(uint8_t irq, uint8_t prio) {}

#endif /* NVIC_H */

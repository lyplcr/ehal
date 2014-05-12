#ifndef NVIC_H
#define NVIC_H

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

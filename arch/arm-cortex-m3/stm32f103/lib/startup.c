#include <stdint.h>

// from linker script
extern uint32_t _stack_top;

void reset_irq_handler(void);
static void nmi_irq_handler(void);
static void hard_fault_irq_handler(void);
static void default_irq_handler(void);

extern int main(void);

__attribute__ ((used, section(".isr_vector")))
void (* const isr_vector[])(void) =
{
	&_stack_top,
	reset_irq_handler,                      // reset handler
	nmi_irq_handler,                        // NMI handler
	hard_fault_irq_handler,                 // hard fault handler
	default_irq_handler,                    // mem manage
	default_irq_handler,                    // bus fault
	default_irq_handler,                    // usage fault
	0,
	0,
	0,
	0,
	default_irq_handler,                    // svcall
	default_irq_handler,                    // debug monitor
	0,
	default_irq_handler,                    // pendsv
	default_irq_handler,                    // systick
};

		extern uint32_t _etext;
		extern uint32_t _sdata;
		extern uint32_t _edata;

		extern uint32_t _sbss;
		extern uint32_t _ebss;

__attribute__((used)) void
reset_irq_handler(void)
{
	{	/* .data, this is safe because data is always 4bytes aligned */
		uint32_t *src = &_etext, *dst = &_sdata;
		while (dst < &_edata)
			*dst++ = *src++;
	}
	{	/* .bss */
		uint32_t *dst = &_sbss;
		while (dst < &_ebss)
			*dst++ = 0;
	}
	main();
	for (;;);
}

static void
nmi_irq_handler(void)
{
	for (;;);
}

static void
hard_fault_irq_handler(void)
{
	for (;;);
}

static void
default_irq_handler(void)
{
	for (;;);
}

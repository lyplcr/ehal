#include <common/lm4f120h5qr.h>

void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

__attribute__((weak)) void GPIOA_irq_handler(void) {}
__attribute__((weak)) void GPIOB_irq_handler(void) {}
__attribute__((weak)) void GPIOC_irq_handler(void) {}
__attribute__((weak)) void GPIOD_irq_handler(void) {}
__attribute__((weak)) void GPIOE_irq_handler(void) {}
__attribute__((weak)) void GPIOF_irq_handler(void) {}
__attribute__((weak)) void GPIOG_irq_handler(void) {}
__attribute__((weak)) void GPIOH_irq_handler(void) {}

extern int main(void);

//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************
static unsigned long pulStack[128];

//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************
__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
	(void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),
	// The initial stack pointer
	ResetISR,                               // The reset handler
	NmiSR,                                  // The NMI handler
	FaultISR,                               // The hard fault handler
	IntDefaultHandler,                      // The MPU fault handler
	IntDefaultHandler,                      // The bus fault handler
	IntDefaultHandler,                      // The usage fault handler
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	IntDefaultHandler,                      // SVCall handler
	IntDefaultHandler,                      // Debug monitor handler
	0,                                      // Reserved
	IntDefaultHandler,                      // The PendSV handler
	IntDefaultHandler,                      // The SysTick handler
	GPIOA_irq_handler,                      // GPIO Port A
	GPIOB_irq_handler,                      // GPIO Port B
	GPIOC_irq_handler,                      // GPIO Port C
	GPIOD_irq_handler,                      // GPIO Port D
	GPIOE_irq_handler,                      // GPIO Port E
	IntDefaultHandler,                      // UART0 Rx and Tx
	IntDefaultHandler,                      // UART1 Rx and Tx
	IntDefaultHandler,                      // SSI0 Rx and Tx
	IntDefaultHandler,                      // I2C0 Master and Slave
	IntDefaultHandler,                      // PWM Fault
	IntDefaultHandler,                      // PWM Generator 0
	IntDefaultHandler,                      // PWM Generator 1
	IntDefaultHandler,                      // PWM Generator 2
	IntDefaultHandler,                      // Quadrature Encoder 0
	IntDefaultHandler,                      // ADC Sequence 0
	IntDefaultHandler,                      // ADC Sequence 1
	IntDefaultHandler,                      // ADC Sequence 2
	IntDefaultHandler,                      // ADC Sequence 3
	IntDefaultHandler,                      // Watchdog timer
	IntDefaultHandler,                      // Timer 0 subtimer A
	IntDefaultHandler,                      // Timer 0 subtimer B
	IntDefaultHandler,                      // Timer 1 subtimer A
	IntDefaultHandler,                      // Timer 1 subtimer B
	IntDefaultHandler,                      // Timer 2 subtimer A
	IntDefaultHandler,                      // Timer 2 subtimer B
	IntDefaultHandler,                      // Analog Comparator 0
	IntDefaultHandler,                      // Analog Comparator 1
	IntDefaultHandler,                      // Analog Comparator 2
	IntDefaultHandler,                      // System Control (PLL, OSC, BO)
	IntDefaultHandler,                      // FLASH Control
	GPIOF_irq_handler,                      // GPIO Port F
	GPIOG_irq_handler,                      // GPIO Port G
	GPIOH_irq_handler,                      // GPIO Port H
	IntDefaultHandler,                      // UART2 Rx and Tx
	IntDefaultHandler,                      // SSI1 Rx and Tx
	IntDefaultHandler,                      // Timer 3 subtimer A
	IntDefaultHandler,                      // Timer 3 subtimer B
	IntDefaultHandler,                      // I2C1 Master and Slave
	IntDefaultHandler,                      // Quadrature Encoder 1
	IntDefaultHandler,                      // CAN0
	IntDefaultHandler,                      // CAN1
	IntDefaultHandler,                      // CAN2
	IntDefaultHandler,                      // Ethernet
	IntDefaultHandler,                      // Hibernate
	IntDefaultHandler,                      // USB0
	IntDefaultHandler,                      // PWM Generator 3
	IntDefaultHandler,                      // uDMA Software Transfer
	IntDefaultHandler,                      // uDMA Error
	IntDefaultHandler,                      // ADC1 Sequence 0
	IntDefaultHandler,                      // ADC1 Sequence 1
	IntDefaultHandler,                      // ADC1 Sequence 2
	IntDefaultHandler,                      // ADC1 Sequence 3
	IntDefaultHandler,                      // I2S0
	IntDefaultHandler,                      // External Bus Interface 0
	IntDefaultHandler,                      // GPIO Port J
	IntDefaultHandler,                      // GPIO Port K
	IntDefaultHandler,                      // GPIO Port L
	IntDefaultHandler,                      // SSI2 Rx and Tx
	IntDefaultHandler,                      // SSI3 Rx and Tx
	IntDefaultHandler,                      // UART3 Rx and Tx
	IntDefaultHandler,                      // UART4 Rx and Tx
	IntDefaultHandler,                      // UART5 Rx and Tx
	IntDefaultHandler,                      // UART6 Rx and Tx
	IntDefaultHandler,                      // UART7 Rx and Tx
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	IntDefaultHandler,                      // I2C2 Master and Slave
	IntDefaultHandler,                      // I2C3 Master and Slave
	IntDefaultHandler,                      // Timer 4 subtimer A
	IntDefaultHandler,                      // Timer 4 subtimer B
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	IntDefaultHandler,                      // Timer 5 subtimer A
	IntDefaultHandler,                      // Timer 5 subtimer B
	IntDefaultHandler,                      // Wide Timer 0 subtimer A
	IntDefaultHandler,                      // Wide Timer 0 subtimer B
	IntDefaultHandler,                      // Wide Timer 1 subtimer A
	IntDefaultHandler,                      // Wide Timer 1 subtimer B
	IntDefaultHandler,                      // Wide Timer 2 subtimer A
	IntDefaultHandler,                      // Wide Timer 2 subtimer B
	IntDefaultHandler,                      // Wide Timer 3 subtimer A
	IntDefaultHandler,                      // Wide Timer 3 subtimer B
	IntDefaultHandler,                      // Wide Timer 4 subtimer A
	IntDefaultHandler,                      // Wide Timer 4 subtimer B
	IntDefaultHandler,                      // Wide Timer 5 subtimer A
	IntDefaultHandler,                      // Wide Timer 5 subtimer B
	IntDefaultHandler,                      // FPU
	IntDefaultHandler,                      // PECI 0
	IntDefaultHandler,                      // LPC 0
	IntDefaultHandler,                      // I2C4 Master and Slave
	IntDefaultHandler,                      // I2C5 Master and Slave
	IntDefaultHandler,                      // GPIO Port M
	IntDefaultHandler,                      // GPIO Port N
	IntDefaultHandler,                      // Quadrature Encoder 2
	IntDefaultHandler,                      // Fan 0
	0,                                      // Reserved
	IntDefaultHandler,                      // GPIO Port P (Summary or P0)
	IntDefaultHandler,                      // GPIO Port P1
	IntDefaultHandler,                      // GPIO Port P2
	IntDefaultHandler,                      // GPIO Port P3
	IntDefaultHandler,                      // GPIO Port P4
	IntDefaultHandler,                      // GPIO Port P5
	IntDefaultHandler,                      // GPIO Port P6
	IntDefaultHandler,                      // GPIO Port P7
	IntDefaultHandler,                      // GPIO Port Q (Summary or Q0)
	IntDefaultHandler,                      // GPIO Port Q1
	IntDefaultHandler,                      // GPIO Port Q2
	IntDefaultHandler,                      // GPIO Port Q3
	IntDefaultHandler,                      // GPIO Port Q4
	IntDefaultHandler,                      // GPIO Port Q5
	IntDefaultHandler,                      // GPIO Port Q6
	IntDefaultHandler,                      // GPIO Port Q7
	IntDefaultHandler,                      // GPIO Port R
	IntDefaultHandler,                      // GPIO Port S
	IntDefaultHandler,                      // PWM 1 Generator 0
	IntDefaultHandler,                      // PWM 1 Generator 1
	IntDefaultHandler,                      // PWM 1 Generator 2
	IntDefaultHandler,                      // PWM 1 Generator 3
	IntDefaultHandler                       // PWM 1 Fault
};

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where the
// the "data" and "bss" segments reside in memory.  The initializers for the
// for the "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************
extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss;
extern unsigned long _ebss;

//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.  Any fancy
// actions (such as making decisions based on the reset cause register, and
// resetting the bits in that register) are left solely in the hands of the
// application.
//
//*****************************************************************************
__attribute__((used)) void
ResetISR(void)
{
	unsigned long *src = &_etext, *dst = &_data;

	/* .data */
	while (dst < &_edata)
		*dst++ = *src++;
	/* .bss */
	__asm(	"    ldr     r0, =_bss\n"
		"    ldr     r1, =_ebss\n"
		"    mov     r2, #0\n"
		"    .thumb_func\n"
		"zero_loop:\n"
		"        cmp     r0, r1\n"
		"        it      lt\n"
		"        strlt   r2, [r0], #4\n"
		"        blt     zero_loop");

	/* full access to coprocessor before main. */
	NVIC_CPAC_R = (NVIC_CPAC_R & ~(NVIC_CPAC_CP10_M | NVIC_CPAC_CP11_M)) |
		NVIC_CPAC_CP10_FULL | NVIC_CPAC_CP11_FULL;
	main();
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a NMI.  This
// simply enters an infinite loop, preserving the system state for examination
// by a debugger.
//
//*****************************************************************************
static void
NmiSR(void)
{
	//
	// Enter an infinite loop.
	//
	while(1)
	{
	}
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
FaultISR(void)
{
	//
	// Enter an infinite loop.
	//
	while(1)
	{
	}
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
IntDefaultHandler(void)
{
	//
	// Go into an infinite loop.
	//
	while(1)
	{
	}
}

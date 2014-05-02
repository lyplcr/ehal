#include <common/lm4f120h5qr.h>

void reset_irq_handler(void);
static void NmiSR(void);
static void FaultISR(void);
static void default_irq_handler(void);

__attribute__((weak, alias("reset_irq_handler"))) void gpioA_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioB_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioC_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioD_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioE_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioF_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioG_irq_handler(void);
__attribute__((weak, alias("reset_irq_handler"))) void gpioH_irq_handler(void);

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
	reset_irq_handler,                      // The reset handler
	NmiSR,                                  // The NMI handler
	FaultISR,                               // The hard fault handler
	default_irq_handler,                    // The MPU fault handler
	default_irq_handler,                    // The bus fault handler
	default_irq_handler,                    // The usage fault handler
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	default_irq_handler,                    // SVCall handler
	default_irq_handler,                    // Debug monitor handler
	0,                                      // Reserved
	default_irq_handler,                    // The PendSV handler
	default_irq_handler,                    // The SysTick handler
	gpioA_irq_handler,                      // gpio Port A
	gpioB_irq_handler,                      // gpio Port B
	gpioC_irq_handler,                      // gpio Port C
	gpioD_irq_handler,                      // gpio Port D
	gpioE_irq_handler,                      // gpio Port E
	default_irq_handler,                    // UART0 Rx and Tx
	default_irq_handler,                    // UART1 Rx and Tx
	default_irq_handler,                    // SSI0 Rx and Tx
	default_irq_handler,                    // I2C0 Master and Slave
	default_irq_handler,                    // PWM Fault
	default_irq_handler,                    // PWM Generator 0
	default_irq_handler,                    // PWM Generator 1
	default_irq_handler,                    // PWM Generator 2
	default_irq_handler,                    // Quadrature Encoder 0
	default_irq_handler,                    // ADC Sequence 0
	default_irq_handler,                    // ADC Sequence 1
	default_irq_handler,                    // ADC Sequence 2
	default_irq_handler,                    // ADC Sequence 3
	default_irq_handler,                    // Watchdog timer
	default_irq_handler,                    // Timer 0 subtimer A
	default_irq_handler,                    // Timer 0 subtimer B
	default_irq_handler,                    // Timer 1 subtimer A
	default_irq_handler,                    // Timer 1 subtimer B
	default_irq_handler,                    // Timer 2 subtimer A
	default_irq_handler,                    // Timer 2 subtimer B
	default_irq_handler,                    // Analog Comparator 0
	default_irq_handler,                    // Analog Comparator 1
	default_irq_handler,                    // Analog Comparator 2
	default_irq_handler,                    // System Control (PLL, OSC, BO)
	default_irq_handler,                    // FLASH Control
	gpioF_irq_handler,                      // gpio Port F
	default_irq_handler,                    // gpio Port G
	default_irq_handler,                    // gpio Port H
	default_irq_handler,                    // UART2 Rx and Tx
	default_irq_handler,                    // SSI1 Rx and Tx
	default_irq_handler,                    // Timer 3 subtimer A
	default_irq_handler,                    // Timer 3 subtimer B
	default_irq_handler,                    // I2C1 Master and Slave
	default_irq_handler,                    // Quadrature Encoder 1
	default_irq_handler,                    // CAN0
	default_irq_handler,                    // CAN1
	default_irq_handler,                    // CAN2
	default_irq_handler,                    // Ethernet
	default_irq_handler,                    // Hibernate
	default_irq_handler,                    // USB0
	default_irq_handler,                    // PWM Generator 3
	default_irq_handler,                    // uDMA Software Transfer
	default_irq_handler,                    // uDMA Error
	default_irq_handler,                    // ADC1 Sequence 0
	default_irq_handler,                    // ADC1 Sequence 1
	default_irq_handler,                    // ADC1 Sequence 2
	default_irq_handler,                    // ADC1 Sequence 3
	default_irq_handler,                    // I2S0
	default_irq_handler,                    // External Bus Interface 0
	default_irq_handler,                    // gpio Port J
	default_irq_handler,                    // gpio Port K
	default_irq_handler,                    // gpio Port L
	default_irq_handler,                    // SSI2 Rx and Tx
	default_irq_handler,                    // SSI3 Rx and Tx
	default_irq_handler,                    // UART3 Rx and Tx
	default_irq_handler,                    // UART4 Rx and Tx
	default_irq_handler,                    // UART5 Rx and Tx
	default_irq_handler,                    // UART6 Rx and Tx
	default_irq_handler,                    // UART7 Rx and Tx
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	0,                                      // Reserved
	default_irq_handler,                    // I2C2 Master and Slave
	default_irq_handler,                    // I2C3 Master and Slave
	default_irq_handler,                    // Timer 4 subtimer A
	default_irq_handler,                    // Timer 4 subtimer B
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
	default_irq_handler,                    // Timer 5 subtimer A
	default_irq_handler,                    // Timer 5 subtimer B
	default_irq_handler,                    // Wide Timer 0 subtimer A
	default_irq_handler,                    // Wide Timer 0 subtimer B
	default_irq_handler,                    // Wide Timer 1 subtimer A
	default_irq_handler,                    // Wide Timer 1 subtimer B
	default_irq_handler,                    // Wide Timer 2 subtimer A
	default_irq_handler,                    // Wide Timer 2 subtimer B
	default_irq_handler,                    // Wide Timer 3 subtimer A
	default_irq_handler,                    // Wide Timer 3 subtimer B
	default_irq_handler,                    // Wide Timer 4 subtimer A
	default_irq_handler,                    // Wide Timer 4 subtimer B
	default_irq_handler,                    // Wide Timer 5 subtimer A
	default_irq_handler,                    // Wide Timer 5 subtimer B
	default_irq_handler,                    // FPU
	default_irq_handler,                    // PECI 0
	default_irq_handler,                    // LPC 0
	default_irq_handler,                    // I2C4 Master and Slave
	default_irq_handler,                    // I2C5 Master and Slave
	default_irq_handler,                    // gpio Port M
	default_irq_handler,                    // gpio Port N
	default_irq_handler,                    // Quadrature Encoder 2
	default_irq_handler,                    // Fan 0
	0,                                      // Reserved
	default_irq_handler,                    // gpio Port P (Summary or P0)
	default_irq_handler,                    // gpio Port P1
	default_irq_handler,                    // gpio Port P2
	default_irq_handler,                    // gpio Port P3
	default_irq_handler,                    // gpio Port P4
	default_irq_handler,                    // gpio Port P5
	default_irq_handler,                    // gpio Port P6
	default_irq_handler,                    // gpio Port P7
	default_irq_handler,                    // gpio Port Q (Summary or Q0)
	default_irq_handler,                    // gpio Port Q1
	default_irq_handler,                    // gpio Port Q2
	default_irq_handler,                    // gpio Port Q3
	default_irq_handler,                    // gpio Port Q4
	default_irq_handler,                    // gpio Port Q5
	default_irq_handler,                    // gpio Port Q6
	default_irq_handler,                    // gpio Port Q7
	default_irq_handler,                    // gpio Port R
	default_irq_handler,                    // gpio Port S
	default_irq_handler,                    // PWM 1 Generator 0
	default_irq_handler,                    // PWM 1 Generator 1
	default_irq_handler,                    // PWM 1 Generator 2
	default_irq_handler,                    // PWM 1 Generator 3
	default_irq_handler                     // PWM 1 Fault
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
reset_irq_handler(void)
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
default_irq_handler(void)
{
	//
	// Go into an infinite loop.
	//
	while(1)
	{
	}
}

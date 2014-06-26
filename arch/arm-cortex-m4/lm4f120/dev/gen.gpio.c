#include <dev/gpio$0.h>

uint8_t gpio$0_refcount=0;

__attribute__((weak))
void gpio$0_irq(uint8_t pins) {}

void gpio$1_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_RIS);
	gpio$0_irq(gpio$0_read());
	HWREG(GPIO_PORT$1_AHB_BASE + GPIO_O_ICR) = ris;
}

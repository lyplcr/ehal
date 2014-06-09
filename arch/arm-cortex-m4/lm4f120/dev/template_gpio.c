#include <dev/gpio!N.h>

uint8_t gpio!N_refcount=0;

__attribute__((weak))
void gpio!N_irq(uint8_t pins) {}

void gpio!T_irq_handler(void)
{
	uint32_t ris = HWREG(GPIO_PORT!T_AHB_BASE + GPIO_O_RIS);
	gpio!N_irq(gpio!N_read());
	HWREG(GPIO_PORT!T_AHB_BASE + GPIO_O_ICR) = ris;
}

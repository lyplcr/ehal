#ifndef SPI$0_H
#define SPI$0_H
#include <stdint.h>

#include <hw/hw_memmap.h>
#include <hw/hw_ssi.h>
#include <hw/hw_sysctl.h>

//#include <dev/nvic.h>
#include <dev/conf_spi.h>
#include __ssi$0_include

#include <core/interfaces/spi.h>
#include <core/types.h>

extern uint8_t spi$0_refcount;

static inline void spi$0_set_conf(uint32_t cpu_freq, Cspi *c)
{
	int div = __ssi_find_div(cpu_freq, c->clk);
	uint8_t scr = cpu_freq / (c->clk * div) -1;

	// 1) Ensure SSE bit is cleared.
	HWREG(SSI$0_BASE + SSI_O_CR1) = 0;

	// 3) clock source (using default: system clock)
	//HWREG(SSI$0_BASE + SSI_O_CC) = SSI_CC_CS_SYSPLL;

	// 4) clock prescaler (SSICPSR)
	HWREG(SSI$0_BASE + SSI_O_CPSR) = div;

	// 5) clock rate, pol, pha, bits,
	//	and protocol mode(Freescale SPI, TI SSF, MICROWIRE) (ignore.)
	HWREG(SSI$0_BASE + SSI_O_CR0) =
		  ((scr         << SSI_CR0_SCR_S) & SSI_CR0_SCR_M)
		| (((c->bits-1) << SSI_CR0_DSS_S) & SSI_CR0_DSS_M)
		| ((c->flags & SPI_CPHA) ? SSI_CR0_SPH : 0)
		| ((c->flags & SPI_CPOL) ? SSI_CR0_SPO : 0)
		;

	// 6) DMA (NOT USING)
	
	// 2.a) master.
	// 7) enable SSE bit.
	HWREG(SSI$0_BASE + SSI_O_CR1) =
		  (0 & SSI_CR1_MS)  // using master mode.
		| (SSI_CR1_SSE)     // enable SSI
		| (0 & SSI_CR1_LBM) // loop back mode.
		;
}

static inline void spi$0_get_conf(uint32_t cpu_freq, Cspi *c)
{
	uint32_t scr;
	uint32_t div;
	uint32_t flags = HWREG(SSI$0_BASE + SSI_O_CR0);

	// 1) grab bits.
	c->bits  = ((flags  & SSI_CR0_DSS_M) >> SSI_CR0_DSS_S) + 1;
	// 2) grab porality & phase.
	c->flags = ((flags & SSI_CR0_SPH) ? SPI_CPHA : 0)
		|  ((flags & SSI_CR0_SPO) ? SPI_CPOL : 0);
	// 3) grab clock.
	scr = (flags >> SSI_CR0_SCR_S) & SSI_CR0_SCR_M;
	div = HWREG(SSI$0_BASE + SSI_O_CPSR);
	c->clk   = __ssi_find_clk(cpu_freq, scr, div);
}

static inline void spi$0_ctor(uint32_t cpu_freq, uint32_t clk,
		uint8_t flags, uint8_t bits)
{
	if (spi$0_refcount++ != 0)
		return;

	// 1) clock the SSI
	HWREG(SYSCTL_RCGCSSI) |= SYSCTL_RCGCSSI_R$0;

	// 2) clock the corresponding GPIO
	__ssi$0_gpio(ctor)();

	// 3) configure gpio as AF
	__ssi$0_gpio(set_afsel)((1<<__ssi0_pin_clk)
			|	(1<<__ssi0_pin_fss)
			|	(1<<__ssi0_pin_mosi)
			|	(1<<__ssi0_pin_miso));

	// 4) configure gpio Pin CTL
#define X(p_) __ssi$0_gpio(set_pctl)(\
		gpio_pctl_mask(__ssi$0_pin_ ## p_), \
		gpio_pctl_entry(__ssi$0_pin_## p_, __ssi$0_pin_## p_ ##_af))
	X(clk);
	X(fss);
	X(mosi);
	X(miso);
#undef X
	// 5) configure SSI regs.
	Cspi c = {
		.clk   = clk,
		.flags = flags,
		.bits  = bits};
	spi$0_set_conf(cpu_freq, &c);
}

static inline void spi$0_dtor(void)
{
	if (spi$0_refcount == 0) {
		HWREG(SYSCTL_RCGCSSI) &=~SYSCTL_RCGCSSI_R$0;
		__ssi$0_gpio(dtor)();
	} else --spi$0_refcount;
}

static inline uint8_t spi$0_rw8(uint8_t w)
{
	// 1) start transmission.
	HWREG(SSI$0_BASE + SSI_O_DR) = w;
	// 2) block until finished.
	while (HWREG(SSI$0_BASE + SSI_O_SR) & SSI_SR_BSY);
	// 3) return byte
	return HWREG(SSI$0_BASE + SSI_O_DR);
}

#endif /* SPI0_H */

#ifndef CONF_SPI_H
#define CONF_SPI_H

/* From datasheet p. 914 */
/* SPI0 ===================================================================== */
#define __ssi0_include <dev/gpio0.h>
#define __ssi0_gpio(fn) gpio0_ ## fn

#define __ssi0_pin_clk       2
#define __ssi0_pin_clk_af    2
#define __ssi0_pin_fss       3
#define __ssi0_pin_fss_af    2
#define __ssi0_pin_miso      4
#define __ssi0_pin_miso_af   2
#define __ssi0_pin_mosi      5
#define __ssi0_pin_mosi_af   2

/* SPI1 ===================================================================== */
#define __ssi1_0_include <dev/gpio5.h>
#define __ssi1_0_gpio(fn) gpio5_ ## fn

#define __ssi1_0_pin_clk     2
#define __ssi1_0_pin_clk_af  2
#define __ssi1_0_pin_fss     3
#define __ssi1_0_pin_fss_af  2
#define __ssi1_0_pin_miso    0
#define __ssi1_0_pin_miso_af 2
#define __ssi1_0_pin_mosi    1
#define __ssi1_0_pin_mosi_af 2

/* opt1 --------------------------------------------------------------------- */
#define __ssi1_1_include <dev/gpio3.h>
#define __ssi1_1_gpio(fn) gpio3_ ## fn

#define __ssi1_1_pin_clk     2
#define __ssi1_1_pin_clk_af  2
#define __ssi1_1_pin_fss     3
#define __ssi1_1_pin_fss_af  2
#define __ssi1_1_pin_miso    0
#define __ssi1_1_pin_miso_af 2
#define __ssi1_1_pin_mosi    1
#define __ssi1_1_pin_mosi_af 2

/* (0 or 1) ----------------------------------------------------------------- */
#define __ssi1_include       __ssi1_## 0 ##_include
#define __ssi1_gpio(fn)      __ssi1_## 0 ##_gpio(fn)
#define __ssi1_pin_clk       __ssi1_## 0 ##_pin_clk
#define __ssi1_pin_clk_af    __ssi1_## 0 ##_pin_clk_af
#define __ssi1_pin_fss       __ssi1_## 0 ##_pin_fss
#define __ssi1_pin_fss_af    __ssi1_## 0 ##_pin_fss_af
#define __ssi1_pin_miso      __ssi1_## 0 ##_pin_miso
#define __ssi1_pin_miso_af   __ssi1_## 0 ##_pin_miso_af
#define __ssi1_pin_mosi      __ssi1_## 0 ##_pin_mosi
#define __ssi1_pin_mosi_af   __ssi1_## 0 ##_pin_mosi_af

/* SPI2 ===================================================================== */
#define __ssi2_include <dev/gpio1.h>
#define __ssi2_gpio(fn) gpio1_ ## fn

#define __ssi2_pin_clk       4
#define __ssi2_pin_clk_af    2
#define __ssi2_pin_fss       5
#define __ssi2_pin_fss_af    2
#define __ssi2_pin_miso      6
#define __ssi2_pin_miso_af   2
#define __ssi2_pin_mosi      7
#define __ssi2_pin_mosi_af   2

/* SPI3 ===================================================================== */
#define __ssi3_include <dev/gpio3.h>
#define __ssi3_gpio(fn) gpio3_ ## fn

#define __ssi3_pin_clk       0
#define __ssi3_pin_clk_af    1
#define __ssi3_pin_fss       1
#define __ssi3_pin_fss_af    1
#define __ssi3_pin_miso      2
#define __ssi3_pin_miso_af   1
#define __ssi3_pin_mosi      3
#define __ssi3_pin_mosi_af   1

/* ========================================================================== */

static inline int __ssi_find_div(uint32_t freq, uint32_t clk)
{
	// from datasheet:
	// SSIClk = SysClk / (CPSDVSR * (1 + SCR))
	// with restrictions:
	// 2 <= CPSDVSR <= 254 && (CPSDVSR % 2) == 0
	// 0 <= SCR     <= 255

	// find lowest div so that div A/B > 0; that is A > B.
	//       [  A  ]  [          B         ]
	// SCR = SysClk / (SSIClk * CPSDVSR) - 1
	for (uint8_t div=254; div > 2; div -= 2)
		if (freq > (clk * div) - 1)
			return div;
	return -1; // no match, failed to generate valid clock
}

static inline uint32_t __ssi_find_clk(uint32_t freq, uint32_t scr, uint32_t div)
{
	// from datasheet:
	// SSIClk = SysClk / (CPSDVSR * (1 + SCR))
	return freq / (div * (scr + 1));
}

#ifndef SSI_CR0_DSS_S
#define SSI_CR0_DSS_S (0)
#endif

#endif /* CONF_SPI_H */

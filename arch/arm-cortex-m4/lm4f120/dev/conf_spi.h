#ifndef CONF_SPI_H
#define CONF_SPI_H

#include <dev/gpio0.h>
#define __ssi0_gpio(fn) gpio0_ ## fn

#define __ssi0_pin_clk     (P2)
#define __ssi0_pin_clk_af  ( 2)

#define __ssi0_pin_fss     (P3)
#define __ssi0_pin_fss_af  ( 2)

#define __ssi0_pin_rx      (P4)
#define __ssi0_pin_rx_af   ( 2)

#define __ssi0_pin_tx      (P5)
#define __ssi0_pin_tx_af   ( 2)


#include <dev/gpio5.h>
#define __ssi1_gpio(fn) gpio5_ ## fn
//#define __ssi1_gpio(fn) gpio3_ ## fn

#include <dev/gpio1.h>
#define __ssi2_gpio(fn) gpio1_ ## fn

#include <dev/gpio3.h>
#define __ssi3_gpio(fn) gpio3_ ## fn

static inline int __ssi_find_div(uint32_t freq, uint32_t clk)
{
	// restrictions:
	// 2 <= CPSDVSR <= 254 && (CPSDVSR % 2) == 0
	// 0 <= SCR     <= 255

	// from datasheet:
	// SSIClk = SysClk / (CPSDVSR * (1 + SCR))

	// with some math:
	//       [  A  ]  [          B         ]
	// SCR = SysClk / (SSIClk * CPSDVSR) - 1
	for (uint16_t div=254; div > 2; div -= 2)
		if (freq < (clk * div) - 1)
			return div;
	return -1; // no match, failed to generate valid clock
}

#ifndef SSI_CR0_DSS_S
#define SSI_CR0_DSS_S (0)
#endif

#endif /* CONF_SPI_H */

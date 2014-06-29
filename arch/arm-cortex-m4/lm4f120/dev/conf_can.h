#ifndef CONF_CAN_H
#define CONF_CAN_H

/* from datasheet p. 1005 */

// TODO: PIN VALUES ARE WRONG!!

/* CAN0 ===================================================================== */
#define __can0_0_include   <dev/gpio5.h>
#define __can0_0_gpio(fn)  gpio5_ ## fn

#define __can0_0_pin_rx      0
#define __can0_0_pin_rx_af   3
#define __can0_0_pin_tx      3
#define __can0_0_pin_tx_af   3
/* opt1 --------------------------------------------------------------------- */
#define __can0_1_include   <dev/gpio5.h>
#define __can0_1_gpio(fn)  gpio5_ ## fn

#define __can0_1_pin_rx      0
#define __can0_1_pin_rx_af   3
#define __can0_1_pin_tx      3
#define __can0_1_pin_tx_af   3

/* opt2 --------------------------------------------------------------------- */
#define __can0_1_include   <dev/gpio5.h>
#define __can0_1_gpio(fn)  gpio5_ ## fn

#define __can0_1_pin_rx      0
#define __can0_1_pin_rx_af   3
#define __can0_1_pin_tx      3
#define __can0_1_pin_tx_af   3
/* (0, 1 or 2) -------------------------------------------------------------- */
#define __can0_include      __can0_## 0 ##_include
#define __can0_gpio(fn)     __can0_## 0 ##_gpio

#define __can0_pin_rx       __can0_## 0 ##_pin_rx
#define __can0_pin_rx_af    __can0_## 0 ##_pin_rx_af
#define __can0_pin_tx       __can0_## 0 ##_pin_tx
#define __can0_pin_tx_af    __can0_## 0 ##_pin_tx_af
/* ========================================================================== */

#endif /* CONF_CAN_H */

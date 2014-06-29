#ifndef UART_CONF_H
#define UART_CONF_H

/* From datasheet p. 851;
 * Ignoring cts/rts. */

/* UART0 ==================================================================== */
#define __uart0_include  <dev/gpio0.h>
#define __uart0_gpio(fn) gpio0_ ## fn

#define __uart0_pin_rx        0
#define __uart0_pin_rx_af     1
#define __uart0_pin_tx        1
#define __uart0_pin_tx_af     1

/* UART1 ==================================================================== */
#define __uart1_0_include  <dev/gpio1.h>
#define __uart1_0_gpio(fn) gpio1_ ## fn

#define __uart1_0_pin_rx      0
#define __uart1_0_pin_rx_af   1
#define __uart1_0_pin_tx      1
#define __uart1_0_pin_tx_af   1

/* opt1 --------------------------------------------------------------------- */
#define __uart1_1_include     <dev/gpio2.h>
#define __uart1_1_gpio(fn)    gpio2_ ## fn

#define __uart1_1_pin_rx      4
#define __uart1_1_pin_rx_af   2
#define __uart1_1_pin_tx      5
#define __uart1_1_pin_tx_af   2

/* (0 or 1) ----------------------------------------------------------------- */
#define __uart1_include       __uart1_## 0 ##_include
#define __uart1_gpio(fn)      __uart1_## 0 ##_gpio(fn)
#define __uart1_pin_rx        __uart1_## 0 ##_pin_rx
#define __uart1_pin_rx_af     __uart1_## 0 ##_pin_rx_af
#define __uart1_pin_tx        __uart1_## 0 ##_pin_tx
#define __uart1_pin_tx_af     __uart1_## 0 ##_pin_tx_af

/* UART2 ==================================================================== */
#define __uart2_include  <dev/gpio2.h>
#define __uart2_gpio(fn) gpio2_ ## fn
#define __uart2_pin_rx        6
#define __uart2_pin_rx_af     1

#define __uart2_pin_tx        7
#define __uart2_pin_tx_af     1

/* UART3 ==================================================================== */
#define __uart3_include  <dev/gpio2.h>
#define __uart3_gpio(fn) gpio2_ ## fn
#define __uart3_pin_rx        6
#define __uart3_pin_rx_af     1

#define __uart3_pin_tx        7
#define __uart3_pin_tx_af     1

/* UART4 ==================================================================== */
#define __uart4_include  <dev/gpio2.h>
#define __uart4_gpio(fn) gpio2_ ## fn
#define __uart4_pin_rx        4
#define __uart4_pin_rx_af     1

#define __uart4_pin_tx        5
#define __uart4_pin_tx_af     1

/* UART5 ==================================================================== */
#define __uart5_include  <dev/gpio4.h>
#define __uart5_gpio(fn) gpio4_ ## fn
#define __uart5_pin_rx        4
#define __uart5_pin_rx_af     1

#define __uart5_pin_tx        5
#define __uart5_pin_tx_af     1

/* UART6 ==================================================================== */
#define __uart6_include  <dev/gpio3.h>
#define __uart6_gpio(fn) gpio3_ ## fn
#define __uart6_pin_rx        4
#define __uart6_pin_rx_af     1

#define __uart6_pin_tx        5
#define __uart6_pin_tx_af     1

/* UART7 ==================================================================== */
#define __uart7_include  <dev/gpio4.h>
#define __uart7_gpio(fn) gpio4_ ## fn
#define __uart7_pin_rx        0
#define __uart7_pin_rx_af     1

#define __uart7_pin_tx        1
#define __uart7_pin_tx_af     1
/* ========================================================================== */
#endif /* UART_CONF_H */

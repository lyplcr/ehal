#ifndef CONF_PWM_H
#define CONF_PWM_H

/* From datasheet p. 610-611 */
/* PWM0 ===================================================================== */
#define __pwm0_0_include  <dev/gpio1.h>
#define __pwm0_0_gpio(fn) gpio1_ ## fn
#define __pwm0_0_pin_a    6
#define __pwm0_0_pin_a_af 7
#define __pwm0_0_pin_b    7
#define __pwm0_0_pin_b_af 7
/* opt1 --------------------------------------------------------------------- */
#define __pwm0_1_include  <dev/gpio5.h>
#define __pwm0_1_gpio(fn) gpio5_ ## fn
#define __pwm0_1_pin_a    0
#define __pwm0_1_pin_a_af 7
#define __pwm0_1_pin_b    1
#define __pwm0_1_pin_b_af 7
/* (0 or 1) ----------------------------------------------------------------- */
#define __pwm0_include  __pwm0_## 1 ##_include
#define __pwm0_gpio(fn) __pwm0_## 1 ##_gpio(fn)
#define __pwm0_pin_a    __pwm0_## 1 ##_pin_a
#define __pwm0_pin_a_af __pwm0_## 1 ##_pin_a_af
#define __pwm0_pin_b    __pwm0_## 1 ##_pin_b
#define __pwm0_pin_b_af __pwm0_## 1 ##_pin_b_af
/* PWM1 ===================================================================== */
#define __pwm1_0_include  <dev/gpio1.h>
#define __pwm1_0_gpio(fn) gpio1_ ## fn
#define __pwm1_0_pin_a    4
#define __pwm1_0_pin_a_af 7
#define __pwm1_0_pin_b    5
#define __pwm1_0_pin_b_af 7
/* opt1 --------------------------------------------------------------------- */
#define __pwm1_1_include  <dev/gpio5.h>
#define __pwm1_1_gpio(fn) gpio5_ ## fn
#define __pwm1_1_pin_a    2
#define __pwm1_1_pin_a_af 7
#define __pwm1_1_pin_b    3
#define __pwm1_1_pin_b_af 7
/* (0 or 1) ----------------------------------------------------------------- */
#define __pwm1_include  __pwm1_## 1 ##_include
#define __pwm1_gpio(fn) __pwm1_## 1 ##_gpio(fn)
#define __pwm1_pin_a    __pwm1_## 1 ##_pin_a
#define __pwm1_pin_a_af __pwm1_## 1 ##_pin_a_af
#define __pwm1_pin_b    __pwm1_## 1 ##_pin_b
#define __pwm1_pin_b_af __pwm1_## 1 ##_pin_b_af
/* PWM2 ===================================================================== */
// (TODO: fix case in which pin_a and pin_b in diferent GPIOs)
#define __pwm2_0_include  <dev/gpio1.h>
#define __pwm2_0_gpio(fn) gpio1_ ## fn
#define __pwm2_0_pin_a    0
#define __pwm2_0_pin_a_af 7
/* opt1 --------------------------------------------------------------------- */
#define __pwm2_1_include  <dev/gpio5.h>
#define __pwm2_1_gpio(fn) gpio5_ ## fn
#define __pwm2_1_pin_a    4
#define __pwm2_1_pin_a_af 7
/* (0 or 1) ----------------------------------------------------------------- */
#define __pwm2_include  __pwm2_## 0 ##_include
#define __pwm2_gpio(fn) __pwm2_## 0 ##_gpio(fn)
#define __pwm2_pin_a    __pwm2_## 0 ##_pin_a
#define __pwm2_pin_a_af __pwm2_## 0 ##_pin_a_af

#define __pwm2_pin_b      1
#define __pwm2_pin_b_af   7
/* PWM3 ===================================================================== */
#define __pwm3_include  <dev/gpio1.h>
#define __pwm3_gpio(fn) gpio1_ ## fn
#define __pwm3_pin_a      2
#define __pwm3_pin_a_af   7
#define __pwm3_pin_b      3
#define __pwm3_pin_b_af   7
/* PWM4 ===================================================================== */
#define __pwm4_include  <dev/gpio2.h>
#define __pwm4_gpio(fn) gpio2_ ## fn
#define __pwm4_pin_a      0
#define __pwm4_pin_a_af   7
#define __pwm4_pin_b      1
#define __pwm4_pin_b_af   7
/* PWM5 ===================================================================== */
#define __pwm5_include  <dev/gpio2.h>
#define __pwm5_gpio(fn) gpio2_ ## fn
#define __pwm5_pin_a      2
#define __pwm5_pin_a_af   7
#define __pwm5_pin_b      3
#define __pwm5_pin_b_af   7
/* ========================================================================== */

#endif /* CONF_PWM_H */

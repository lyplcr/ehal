#ifndef EHAL_H
#define EHAL_H

#include <stdint.h>

/* ========================================================================== */
/** Apply a bitmask \b v only on the \b m set bits of \b p, while the other bits
 * of p remain unchanged.
 * -------------------------------------------------------------------------- */
#define bm_apply(p, m, v) ((p) = ( (p) &~(m) ) | ( (m) & (v) ))

enum {
/* create entries P0 = (1<<0), P1 = (1<<1) ... */
#define P(i) P##i = (1<<(i))
	P(0), P(1), P(2), P(3), P(4), P(5), P(6), P(7)
#undef P
};
/* ========================================================================== */

typedef uint8_t gpio_mask;
struct gpio_interface {
	void (*ctor)(void);
	void (*dtor)(void);

	void (*set_in)  (gpio_mask pins);
	void (*set_out) (gpio_mask pins);

	void (*read)    (gpio_mask pins);
	void (*set)     (gpio_mask pins);
	void (*clr)     (gpio_mask pins);
	void (*set_to)  (gpio_mask pins, gpio_mask values);
	void (*set_pupd)(gpio_mask pu_pins, gpio_mask pd_pins);
};

#endif /* EHAL_H */
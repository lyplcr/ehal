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

/* devices ================================================================== */

/* cpu ---------------------------------------------------------------------- */
struct cpu_interface {
	void    (*ctor)      (void);
	void    (*dtor)      (void);

	void    (*reset)     (void);
	void    (*delay_ms)  (uint16_t ms);
	uint8_t (*boot_cause)(void);
};

/* gpio---------------------------------------------------------------------- */
/* some type... depends on the number of pins per port. */
typedef uint8_t gpio_mask;
struct gpio_interface {
	void (*ctor)(void);
	void (*dtor)(void);

	void (*set_in)       (gpio_mask pins);
	void (*set_out)      (gpio_mask pins);
	void (*set_dir)      (gpio_mask pins, gpio_mask in);

	void (*read)         (gpio_mask pins);
	void (*set)          (gpio_mask pins);
	void (*clr)          (gpio_mask pins);
	void (*set_to)       (gpio_mask pins, gpio_mask to);

	void (*set_pullup)   (gpio_mask pins);
	void (*clr_pullup)   (gpio_mask pins);

	void (*set_pulldown) (gpio_mask pins);
	void (*clr_pulldown) (gpio_mask pins);

	void (*set_pushpull) (gpio_mask pins);
	void (*set_opendrain)(gpio_mask pins);
};

struct spi_interface {
	void (*ctor)(uint8_t mode);
	void (*dtor)(void);

	uint8_t (*rw8)(uint8_t w);
};

#endif /* EHAL_H */

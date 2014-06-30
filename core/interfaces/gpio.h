#ifndef GPIO_H
#define GPIO_H
#include <core/bm.h>

enum {
/* create entries P0 = (1<<0), P1 = (1<<1) ... */
#define P(i) P##i = (1<<(i))
	P(0), P(1), P(2), P(3), P(4), P(5), P(6), P(7)
#undef P
};

typedef struct {
	void (*ctor)(void);
	void (*dtor)(void);

	void (*set_in)       (uint8_t pins);
	void (*set_out)      (uint8_t pins);
	void (*set_dir)      (uint8_t pins, uint8_t in);

	uint8_t (*read)      (void);
	void (*set)          (uint8_t pins);
	void (*clr)          (uint8_t pins);
	void (*set_to)       (uint8_t pins, uint8_t to);

	void (*set_pullup)   (uint8_t pins);
	void (*clr_pullup)   (uint8_t pins);

	void (*set_pulldown) (uint8_t pins);
	void (*clr_pulldown) (uint8_t pins);

	void (*set_pushpull) (uint8_t pins);
	void (*set_opendrain)(uint8_t pins);
	void (*set_edge_irq) (uint8_t rise, uint8_t fall);
} Igpio;

#endif /* GPIO_H */

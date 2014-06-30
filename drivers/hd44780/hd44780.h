#ifndef HD44780_H
#define HD44780_H
#include <core/interfaces/gpio.h>

typedef struct {
	const Igpio *data,
	      *ctl;
	uint8_t data0,
		rs,
		rw,
		e;
} HD44780;

// 4bits mode.
void hd44780_ctor(const HD44780 *hd);

int hd44780_put   (int ch, const HD44780 *hd);
int hd44780_put_nb(int ch, const HD44780 *hd);
int hd44780_get(const HD44780 *hd);

#endif /* HD44780_H */

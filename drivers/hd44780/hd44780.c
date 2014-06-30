#include <stdio.h>

/* what to do about this... */
#include <dev/cpu0.h>

#include "hd44780.h"
#include "hd44780_reg.h"
#include <core/interfaces/gpio.h>

static void    put_nibble(uint8_t ch, const HD44780 *hd);
static uint8_t get_nibble(const HD44780 *hd);

static void    put_byte  (uint8_t ch, const HD44780 *hd);
static uint8_t get_byte  (const HD44780 *hd);

static void    put_cmd   (uint8_t ch, const HD44780 *hd);
static uint8_t get_cmd   (const HD44780 *hd);
static void    put_data  (uint8_t ch, const HD44780 *hd);
static uint8_t get_data  (const HD44780 *hd);

void hd44780_ctor(const HD44780 *hd)
{
	hd->ctl->ctor();
	hd->ctl->set_out(hd->rs | hd->rw | hd->e);
	hd->ctl->set_to (hd->rs | hd->rw | hd->e,
			    0   |    0   | 0); // cmd mode.

	hd->data->ctor();
	hd->data->set_out(0x0F << hd->data0);

	// soft reset ----------------------------------------------------------
	// startup sequence for 4bits mode:
	//   o Display starts in 8bits mode.
	// 1) wait for at least 40ms, set to 8bits mode.
	cpu0_busywait_us(40000);
	put_nibble((CMD_FN_8PINS | CMD_FN_M) >> 4, hd);

	// 3) do it again after 4.1ms
	cpu0_busywait_us(4100);
	put_nibble((CMD_FN_8PINS | CMD_FN_M) >> 4, hd);

	// 4) do it again after 100us
	cpu0_busywait_us(100);
	put_nibble((CMD_FN_8PINS | CMD_FN_M) >> 4, hd);

	cpu0_busywait_us(100);
	put_nibble((CMD_FN_4PINS | CMD_FN_M) >> 4, hd);
	// ---------------------------------------------------------------------

	put_cmd(CMD_FN_4PINS
			| CMD_FN_1LINES
			| CMD_FN_M, hd);
	// 6) Turn it on.
	put_cmd(CMD_CTL_DISPLAY | CMD_CTL_M, hd);

	put_cmd(CMD_CLEAR, hd);
	put_cmd(CMD_HOME, hd);

	hd->ctl->set(hd->rs); // 7) switch to data mode rs:1, rw:0, e:0
}

int hd44780_put(int ch, const HD44780 *hd)
{
	while (hd44780_put_nb(ch, hd) == EOF);
	return ch;
}

int hd44780_put_nb(int ch, const HD44780 *hd)
{
	if (get_cmd(hd) & CMD_FLAGS_BUSY)
		return EOF;

	put_data(ch, hd);
	return ch;
}

int hd44780_get(const HD44780 *hd)
{
	return get_data(hd);
}

static void put_nibble(uint8_t ch, const HD44780 *hd)
{
	hd->data->set_to(0x0F << hd->data0, ch << hd->data0);

	hd->ctl->set(hd->e);
	hd->ctl->clr(hd->e);
}

static uint8_t get_nibble(const HD44780 *hd)
{
	uint8_t r;

	hd->ctl->set(hd->e);
	r = hd->data->read() >> hd->data0;
	hd->ctl->clr(hd->e);

	return r;
}

/* high 7-4, then low. */
static void put_byte(uint8_t ch, const HD44780 *hd)
{
	put_nibble(ch >> 4, hd);
	put_nibble(ch,      hd);
}

static uint8_t get_byte(const HD44780 *hd)
{
	uint8_t r;
	
	hd->data->set_in(0x0F << hd->data0);
	hd->ctl->set(hd->rw);
	r = (get_nibble(hd) << 4) | get_nibble(hd);
	hd->ctl->clr(hd->rw);
	hd->data->set_out(0x0F << hd->data0);

	return r;
}


static void put_cmd(uint8_t ch, const HD44780 *hd)
{
	while (get_cmd(hd) & CMD_FLAGS_BUSY)
		;

	hd->ctl->clr(hd->rs);
	put_byte(ch, hd);
	hd->ctl->set(hd->rs);

}

static void put_data(uint8_t ch, const HD44780 *hd)
{
	put_byte(ch, hd);
}

static uint8_t get_cmd(const HD44780 *hd)
{
	uint8_t r;
	hd->ctl->clr(hd->rs);
	r = get_byte(hd);
	hd->ctl->set(hd->rs);
	return r;
}

static uint8_t get_data(const HD44780 *hd)
{
	return get_byte(hd);
}

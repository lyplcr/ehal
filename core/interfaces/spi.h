#ifndef SPI_H
#define SPI_H
#include <stdint.h>

/* ctor flags. */
#define SPI_MSB        (0<<0)
#define SPI_LSB        (1<<0)
#define SPI_CPOL       (1<<2)
#define SPI_CPHA       (1<<1)

typedef struct {
	uint32_t clk;
	uint8_t flags;
	uint8_t bits;
} Cspi;

typedef struct {
	void (*ctor)(uint32_t cpu_freq,
			uint32_t clk,
			uint8_t flags,
			uint8_t bits);
	void (*dtor)(void);

	void (*set_conf)(uint32_t cpu_freq, Cspi *);
	void (*get_conf)(uint32_t cpu_freq, Cspi *);

	/* blocking Read/Write operation. */
	uint8_t (*rw8)(uint8_t w);
} Ispi;

#endif /* SPI_H */

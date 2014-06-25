#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include <stdint.h>

/* ctor flags. */
#define SPI_MSB        (0<<0)
#define SPI_LSB        (1<<0)
#define SPI_CPOL_LOW   (0<<1)
#define SPI_CPOL       (1<<1)
#define SPI_CPHA_1EDGE (1<<2)
#define SPI_CPHA       (1<<2)

/* Pass configuration as a tuple. */
struct spi_conf {
	uint32_t clk;
	uint8_t flags;
	uint8_t bits;
};

typedef struct {
	void (*ctor)(uint32_t clk, uint8_t flags, uint8_t bits);
	void (*dtor)(void);

	void (*set_conf)(struct spi_conf *);
	void (*get_conf)(struct spi_conf *);

	/* blocking Read/Write operation. */
	uint8_t (*rw8)(void);
} ISPI;
#endif /* SPI_INTERFACE_H */

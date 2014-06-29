#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
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
	void (*ctor)(uint32_t clk, uint8_t flags, uint8_t bits);
	void (*dtor)(void);

	void (*set_conf)(struct spi_conf *);
	void (*get_conf)(struct spi_conf *);

	/* blocking Read/Write operation. */
	uint8_t (*rw8)(void);
} Ispi;

#endif /* SPI_INTERFACE_H */

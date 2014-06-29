#include <dev/spi$0.h>

uint8_t spi$0_refcount;

Ispi spi$0 = {
	.ctor     = spi$0_ctor,
	.dtor     = spi$0_dtor,

	.set_conf = spi$0_set_conf,
	.get_conf = spi$0_get_conf,

	.rw8      = spi$0_rw8,
};

#include <dev/uart$0.h>

uint8_t uart$0_refcount;

const Iuart uart$0 = {
	.ctor = uart$0_ctor,
	.dtor = uart$0_dtor,

	.set_conf = uart$0_set_conf,
	.get_conf = uart$0_get_conf,

	.put  = uart$0_put,
	.get  = uart$0_get,
};

#include <stdio.h>
#include <core/ringbuf.h>

uint8_t _rxq_b[1<<4];
RingBuf rxq = RINGBUF_INIT(_rxq_b, 1<<4);

int main(int argc, char *argv[])
{
	ringbuf_put('h', &rxq);
	ringbuf_put('e', &rxq);
	ringbuf_put('l', &rxq);
	ringbuf_put('l', &rxq);
	ringbuf_put('o', &rxq);
	ringbuf_put('\n', &rxq);

	while (!ringbuf_isempty(&rxq))
		putchar(ringbuf_get(&rxq));

	return 0;
}

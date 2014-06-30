#ifndef CBUF_H
#define CBUF_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#define T struct ringbuf
typedef T RingBuf;

T {
	uint8_t *p;
	uint16_t head, tail, mask;
};

#define RINGBUF_INIT(_buf, _len) { \
	.p = (_buf), .mask = (_len) - 1, \
	.head = 0, .tail = 0, \
}

static inline uint16_t ringbuf_count(volatile T *b)
{
	assert(b && "invalid 'b' is NULL");
	return (b->head - b->tail) + b->mask+1;
}

static inline bool ringbuf_isfull(volatile T *b)
{
	assert(b && "invalid 'b' is NULL");
	return ringbuf_count(b) == 0;
}

static inline bool ringbuf_isempty(volatile T *b)
{
	assert(b && "invalid 'b' is NULL");
	return ringbuf_count(b) == b->mask+1;
}

static inline int ringbuf_put(int v, volatile T *b)
{
	assert(b && "invalid 'b' is NULL");
	assert(!ringbuf_isfull(b) && "buffer overflow");

	if (ringbuf_isfull(b))
		return EOF;

	b->p[b->tail++ & b->mask] = v;
	return v;
}

static inline int ringbuf_get(volatile T *b)
{
	assert(b && "invalid 'b' is NULL");
	assert(!ringbuf_isempty(b) && "buffer underflow");

	if (ringbuf_isempty(b))
		return EOF;

	return b->p[b->head++ & b->mask];
}

#undef T
#endif /* CBUF_H */

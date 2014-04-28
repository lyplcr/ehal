#ifndef CBUF_H
#define CBUF_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

struct cbuf {
	uint8_t *p;
	uint16_t head, tail, mask;
};

#define CBUF_INIT(_buf, _len) { \
	.p = (_buf), .mask = (_len) - 1, \
	.head = 0, .tail = 0, \
}

#define CBUF(_name, _len) \
	static uint8_t _name ## _B[1<<(_len)]; \
	struct cbuf _name = CBUF_INIT(_name ## _B, 1<<(_len))

#define STATIC_CBUF(_name, _len) \
	static uint8_t _name ## _B[1<<(_len)]; \
	static struct cbuf _name = CBUF_INIT(_name ## _B, 1<<(_len))

static inline bool cbuf_ctor(struct cbuf *b, uint8_t *p, uint16_t n)
{
	assert(b && "invalid 'b' is NULL");
	assert(p && "invalid 'p' is NULL");
	assert((n & (n-1)) == 0 && "'n' not a power of 2.");

	if ((n & (n-1)) == 0)
		return false;
	b->p = p;
	b->mask = n-1;
	b->head = b->tail = 0;
	return true;
}

static inline uint8_t *cbuf_dtor(struct cbuf *b, uint16_t *n)
{
	if (n) *n = b->mask+1;
	return b->p;
}

static inline uint16_t cbuf_count(struct cbuf *b)
{
	assert(b && "invalid 'b' is NULL");
	return (b->head - b->tail) + b->mask+1;
}

static inline bool cbuf_isfull(struct cbuf *b)
{
	assert(b && "invalid 'b' is NULL");
	return cbuf_count(b) == 0;
}

static inline bool cbuf_isempty(struct cbuf *b)
{
	assert(b && "invalid 'b' is NULL");
	return cbuf_count(b) == b->mask+1;
}

static inline void cbuf_put(struct cbuf *b, uint8_t v)
{
	assert(b && "invalid 'b' is NULL");
	assert(!cbuf_isfull(b) && "buffer overflow");
	/* if full, drop oldest value */
	if (cbuf_isfull(b)) b->head++;
	b->p[b->tail++ & b->mask] = v;
}

static inline uint8_t cbuf_get(struct cbuf *b)
{
	assert(b && "invalid 'b' is NULL");
	assert(!cbuf_isempty(b) && "buffer underflow");
	return b->p[b->head++ & b->mask];
}

#endif /* CBUF_H */

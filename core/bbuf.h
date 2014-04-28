#ifndef BBUF_H
#define BBUF_H

/** Bip Buffer implemented in C, got it from here.
 * http://www.codeproject.com/Articles/3479/The-Bip-Buffer-The-Circular-Buffer-with-a-Twist
 */

#include <stdint.h>
#include <stddef.h>

struct bbuf {
	uint8_t *p;
	uint16_t size;
	uint16_t ixa, sza;
	uint16_t ixb, szb;
	uint16_t ixres, szres;
};

static inline uint16_t bbufh_size(struct bbuf *b)
{
	return b->size;
}

static inline uint16_t bbufh_space_after_a(struct bbuf *b)
{
	return bbufh_size(b) - b->ixa - b->sza;
}

static inline uint16_t bbufh_b_free_space(struct bbuf *b)
{
	return b->ixa - b->ixb - b->szb;
}

static inline void bbuf_init(struct bbuf *b, uint8_t *p, uint16_t n)
{
	b->ixa = b->sza, b->ixb = b->szb = b->ixres = b->szres = 0;
	b->p = p;
	b->size = n;
}

static inline void bbuf_clear(struct bbuf *b)
{
	b->ixa = b->sza, b->ixb = b->szb = b->ixres = b->szres = 0;
}

static inline void bbuf_fini(struct bbuf *b) {
	b->ixa = b->sza, b->ixb = b->szb = b->ixres = b->szres = 0;
}

static inline void *bbuf_reserve(struct bbuf *b, uint16_t sz, uint16_t *res) {
	if (b->szb) { /* alocate on b if exists; we have two blocks going on */ 
		uint16_t free = bbufh_b_free_space(b);
		/* give back the available space, larger than size. */
		if (free == 0) return NULL;
		b->szres = free;
		*res = free;
		b->ixres = b->ixb + b->szb;
		return b->p + b->ixres;
	} else {
		uint16_t free = bbufh_space_after_a(b);
		if (free >= b->ixa) {
			if (free == 0) return NULL;
			b->szres = free;
			*res = free;
			b->ixres = b->ixa + b->sza;
			return b->p + b->ixres;
		} else {
			if (b->ixa == 0) return NULL;
			if (b->ixa < sz) sz = b->ixa;
			b->szres = sz;
			*res = sz;
			b->ixres = 0;
			return b->p;
		}
	}
}

static inline void bbuf_commit(struct bbuf *b, uint16_t sz) {
	if (sz == 0) { /* reset commit */
		b->szres = b->ixres = 0;
		return;
	}
	if (sz > b->szres) /* truncate to reserved value. */
		sz = b->szres;
	if (b->sza == 0 && b->szb == 0) { /* no blocks, create one in a */
		b->ixa = b->ixres;
		b->sza = sz;
	} else if (b->ixres == b->sza + b->ixa) {
		b->sza += sz;
	} else {
		b->szb += sz;
	}
	b->ixres = b->szres = 0;
}

static inline void *bbuf_map(struct bbuf *b, uint16_t *sz) {
	if (b->sza == 0) {
		return NULL;
	}
	*sz = b->sza;
	return b->p + b->ixa;
}

static inline void bbuf_release(struct bbuf *b, uint16_t sz) {
	if (sz >= b->sza) {
		b->ixa = b->ixb;
		b->sza = b->szb;
		b->ixb = b->szb = 0;
	} else {
		b->sza -= sz;
		b->ixa += sz;
	}
}

static inline uint16_t bbuf_get_commited_sz(struct bbuf *b) {
	return b->sza + b->szb;
}

#endif /* BBUF_H */


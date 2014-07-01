#ifndef EHAL_H
#define EHAL_H

#include <stdint.h>

#define bm_set(p, v) ((p) |= v)
#define bm_clr(p, v) ((p) &= v)
#define bm_tst(p, v) ((p) &  v)
#define bm_loop_until_set(p, v)   while ( bm_tst(p, v));
#define bm_loop_until_clear(p, v) while (!bm_tst(p, v));

/** Apply a bitmask \b v only on the \b m set bits of \b p, while the other bits
 * of p remain unchanged.
 * -------------------------------------------------------------------------- */
#define bm_apply(p, m, v) ((p) = ( (p) &~(m) ) | ( (m) & (v) ))

#endif /* EHAL_H */

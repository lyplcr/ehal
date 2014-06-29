#ifndef QUEUE_H
#define QUEUE_H
/* single linked list implementation of a queue. This implementation has a
 * twist. It uses 'next != self' to mark as enqueued (busy) and 'next == self'
 * to mark as not queued. This way _put will fail gracefuly.
 *
 * O(1) for put (enqueue).
 * O(1) for get (dequeue). */

#define T struct queue_entry
typedef T QueueEntry;

#define H struct queue_head
typedef H QueueHead;

T {
	T *next;
};

H {
	T *head, **tail;
};

/* A queue entry uses its own pointer as guard. */
#define QUEUE_ENTRY_INIT(name) { (name) }
#define QUEUE_HEAD_INIT(name)  { 0, &((name).head) }

/* -------------------------------------------------------------------------- */
static inline void queue_head_init(H *h)
{
	h->head = 0;
	h->tail = &h->head;
}

static inline void queue_entry_init(T *l)
{
	l->next = l;
}

/** Put a element on list tail.
 * Fails if the element is already on the list or uninitialized.
 *
 * @return true - success. false - failure.
 * @note Removal from the list automatically makes the element ready again. */
static inline void queue_put(T *l, H *h)
{
	if (l->next != l)
		return;
	l->next  = 0;
	*h->tail = l;
	h->tail  = &l->next;
}

/** Get a element from list head. */
static inline T *queue_get(H *h)
{
	T *l = h->head;

	if (!l)
		return 0;
	if (!l->next)
		h->tail = &h->head;
	h->head = l->next; /* restore NULL on last element. */
	queue_entry_init(l);
	return l;
}

static inline void queue_foreach_and_drop(H *h, void (*fn)(T *e))
{
	T *t, *e = h->head;
	queue_head_init(h);

	while (e) { /* this ordering makes entry available for reuse in fn. */
		t = e;
		e = e->next;
		queue_entry_init(t);
		fn(t);
	}
}

/* put & get for overloading types: The types must create the list as the first
 * field like so: 'struct queue _;' */
#define queue_t_put(l, h, t) (queue_put(&((t*)l)->_, h))
#define queue_t_get(h, t)   ((t *)queue_get(h))

#undef H
#undef T
#endif /* QUEUE_H */

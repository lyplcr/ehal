#ifndef JOBS_H
#define JOBS_H
#include <stdint.h>
#include <core/queue.h>

#define T struct job_entry_t
typedef T JobEntry;

#define H struct job_head_t
typedef H JobHead;

T {
	QueueEntry _;
	void (*run)(T *);
	intptr_t arg;
};

H {
	QueueHead _;
};

#define JOB_INIT(je_, run_, arg_) { \
	._ = QUEUE_INIT(je_), \
	.run = run_, \
	.arg = arg_, \
}

#define JOB_HEAD_INIT(jh_) { \
	._ = QUEUE_HEAD_INIT((jh_)._), \
}

static inline void job_init(T *j, void (*run)(T *j), intptr_t arg)
{
	queue_entry_init(&j->_);
	j->run = run;
	j->arg = arg;
}

static inline void job_schedule(H *_h, T *_j)
{
	QueueHead  *h = (QueueHead  *)_h;
	QueueEntry *e = (QueueEntry *)_j;
	queue_put(e, h);
}

static inline void __run_a_job(QueueEntry *_e)
{
	T *e = (T *)_e;
	e->run(e);
}

static inline void run_all_jobs(H *_h)
{
	QueueHead *h = (QueueHead *)_h;
	queue_foreach_and_drop(h, __run_a_job);
}

#undef H
#undef T
#endif /* JOBS_H */

/* Job is an abstraction of for scheduling bottom half (low level priority work)
 * from an IRQ.
 *
 * Process is something like:
 * 1) Create a job.
 *	* JOB(name, fn, arg); or
 *	* struct job name; + job_init(&name, fn, arg).
 * 2) When you have a bottom half to schedule.
 *	* job_schedule(&name, &my_jobs) or
 *	* g_job_schedule(name)
 * 3) Actually run pending jobs.
 *	* job_queue_run(&my_jobs)
 *	* g_job_queue_run()
 *
 * Some considerations:
 *
 * There are 2 main ways of using this lib.
 *	1 - One  job  for each irq. The IRQ will always spawn the same job.
 *		by put its input in a queue and give that to the job.
 *	2 - many jobs to many irqs. The IRQ will spawn a new job per input.
 * 1: The prefered way to use the lib.
 *	+ Allocations of job can be static.
 *	- Tricky handling of packet separation (may require 2 queues cmd+data)
 * 2: Another valid way.
 *	+ Easier to make.
 *	+ Handles packet separation well. (just pass an array as arg)
 *	- Requires a job pool for no malloc inside IRQ.
 *	- More cpu intensive (more function pointer calls)
 *
 * Some more considerations:
 * You can use a semaphore to create a blocking version of job_queue_run by:
 *	- sem_post on job_schedule.
 *	- sem_wait on job_queue_run.
 *
 * job_schedule  is O(1).
 * job_queue_run is O(n) for n elements. (Can only consume the whole queue.) */
#ifndef JOBS_H
#define JOBS_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* le job structure:
 * @next: Singly linked list (so that operations can be lock free).
 * @run:  Continuation of IRQ (bottom half).
 * @arg:  Parameter passed to run. */
struct job {
	struct job *next;
	void (*run)(intptr_t arg);
	intptr_t arg;
};

/* le job_queue. You might not need to know since there is one defined for the
 * g_ functions in jobs.c.
 * @head: Jobs pending (single linked list of jobs)
 * @tail: With pointer to tail. */
struct job_queue {
	struct job *head,
		   **tail;
};

/* Use the other one! (#define JOB)
 * Macro to make a job: static struct myjob = JOB_INIT(run, arg); */
#define JOB_INIT(_run, _arg) { \
	.next = NULL, \
	.run = _run, \
	.arg = _arg \
}

/* Macro to make a job: static JOB(myjob, run, arg); */
#define JOB(_name, _run, _arg) struct job _name = JOB_INIT(_run, _arg)

/* Initialize a job structure. */
static inline void job_init(struct job *j,
		void (*run)(intptr_t arg), intptr_t arg)
{
	j->next = NULL;
	j->run  = run;
	j->arg  = arg;
}

/* Set a job to run (sometime in the future.)
 *
 * @j:  Job we want to schedule.
 * @js: Job queue to put it. The task will execute on job_queue_run is called.
 * You might want to look at g_job_schedule with its global job_queue cousin. */
static inline bool job_schedule(struct job *j, struct job_queue *js)
{
	if (j->next)
		return false;
	j->next = NULL;
	*js->tail = j;
	js->tail = &j->next;
	return true;
}

/* -------------------------------------------------------------------------- */
/* Set a job_queue fields to sane values.
 * @js: job_queue to operate on.
 * @return true if any job was executed. */
static inline void job_queue_init(struct job_queue *js)
{
	js->head =  NULL;
	js->tail = &js->head;
}
#define JOB_QUEUE(_name) struct job_queue _name = { NULL, &(&_name)->head }

/* Run queued jobs. */
static inline bool job_queue_run(struct job_queue *js)
{
	struct job *j = js->head;

	if (j == NULL)
		return false;

	job_queue_init(js); /* it is ok to inser a job while doing this. */
	while (j) { /* this ordering enables a job to schedule itself. */
		struct job *t = j;
		j = j->next;
		t->next = NULL;
		t->run(t->arg);
	}
	return true;
}
#define job_setarg(_job, _arg) ((_job)->arg = (_arg))

/* operations on a global job_queue. */
bool g_job_schedule (struct job *j);
bool g_job_queue_run(void);

#endif /* JOBS_H */

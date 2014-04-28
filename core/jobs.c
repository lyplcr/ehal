#include "jobs.h"
#include <stddef.h>

#define JOB_QUEUE(_name) struct job_queue _name = { NULL, &(&_name)->head }
static  JOB_QUEUE(J);

bool g_job_schedule (struct job *j)
{
	return job_schedule(j, &J);
}

bool g_job_queue_run(void)
{
	return job_queue_run(&J);
}

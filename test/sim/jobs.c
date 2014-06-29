#include <stdio.h>
#include <core/jobs.h>

#define N 10
#define alloc() top++

void job_printer(JobEntry *e)
{
	printf("%ld\n", e->arg);
}

int main(int argc, char *argv[])
{
	JobHead h = JOB_HEAD_INIT(h);
	JobEntry _e[N], *top = _e, *e;


	for (int i=0; i<N; i++) {
		e = alloc();
		job_init(e, job_printer, e - _e);
		job_schedule(&h, e);
	}

	run_all_jobs(&h);
	return 0;
}

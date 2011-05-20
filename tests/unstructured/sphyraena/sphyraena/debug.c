/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

void sphyraena_timer_start()
{
        gettimeofday(&sphyraena_starttime, NULL);
}

double sphyraena_timer_stop()
{
        gettimeofday(&sphyraena_endtime, NULL);
        double start = sphyraena_starttime.tv_sec +
                (double)sphyraena_starttime.tv_usec * .000001;
        double end = sphyraena_endtime.tv_sec +
                (double)sphyraena_endtime.tv_usec * .000001;
	return (end - start);
}

double sphyraena_timer_end(const char* label)
{
	double time = sphyraena_timer_stop();
        printf("%s time: %f seconds\n", label, time);
	return time;
}

cudaError_t sphyraena_print_error()
{
	cudaError_t r = cudaGetLastError();

	if(r != cudaSuccess)
		fprintf(stderr, "cuda error: %s\n",
			cudaGetErrorString(r));

	return r;
}

void sphyraena_print_results(sphyraena *s, int n)
{
	printf("==== Results ===========================================================\n");
	printf(" Rows:		%i\n", s->results_cpu->rows);
	printf(" Columns:	%i\n", s->results_cpu->columns);
	printf(" Stride:	%i\n", s->results_cpu->stride);
	printf("========================================================================\n");

	sphyraena_results *res = s->results_cpu;

	int i, j;
	char *r = (char*) &res->r;

	for(i = 0; i < res->rows && i < n; i++) {
		for(j = 0; j < res->columns; j++)
			switch(res->types[j]) {
				case SPHYRAENA_INT :
					printf("%i\t", ((int*)(r + res->offsets[j]))[0]);
					break;
				case SPHYRAENA_FLOAT :
					printf("%f\t", ((float*)(r + res->offsets[j]))[0]);
					break;
				case SPHYRAENA_INT64 :
					printf("%li\t", ((long int*)(r + res->offsets[j]))[0]);
					break;
				case SPHYRAENA_DOUBLE :
					printf("%e\t", ((double*)(r + res->offsets[j]))[0]);
					break;
			}
		printf("\n");
		r += res->stride;
	}
}

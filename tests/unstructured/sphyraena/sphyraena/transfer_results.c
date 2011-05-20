/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

int sphyraena_transfer_results(sphyraena *s)
{
	cudaError_t r;

	r = cudaMemcpy(s->results_cpu, s->results_gpu, 
		sizeof(sphyraena_results), cudaMemcpyDeviceToHost);

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_CUDAMEMCPY;
	}

	/*r = cudaMemcpy(s->results_cpu->r,
		s->results_gpu + sizeof(sphyraena_results) / sizeof(sphyraena_results),
		s->results_cpu->rows * s->results_cpu->stride,
		cudaMemcpyDeviceToHost);*/
	r = cudaMemcpy(s->results_cpu,
		s->results_gpu,
		s->results_cpu->rows * s->results_cpu->stride + sizeof(sphyraena_results),
		cudaMemcpyDeviceToHost);

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_CUDAMEMCPY;
	}

	return SPHYRAENA_SUCCESS;
}

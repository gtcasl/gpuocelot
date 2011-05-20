/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

int sphyraena_transfer_data(sphyraena *s)
{
	int r;

#ifdef SPHY_DEBUG
	sphyraena_timer_start();
#endif

	// copy data from cpu to gpu
	r = cudaMemcpy(s->data_gpu, s->data_cpu->d, 
		s->data_cpu->rows * s->data_cpu->stride,
		cudaMemcpyHostToDevice);

#ifdef SPHY_DEBUG
	sphyraena_timer_end("cudaMemcpy");
#endif

	// check for cudaMemcpy error
	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_CUDAMEMCPY;
	}

	return SPHYRAENA_SUCCESS;
}


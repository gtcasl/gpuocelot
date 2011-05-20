/* ===========================================================================
 * Copyright 2010 Peter Brownlee Bakkum
 * Permission is provided to use this for research only.
 * ------------------------------------------------------------------------ */


#include "sphyraena.h"

int sphyraena_init(sphyraena *s, sqlite3 *db, size_t data_size, size_t results_size, int pinned_memory)
{
	// assign simple copies to state struct
	s->db		= db;
	s->data_size	= data_size;
	s->results_size	= results_size;
	s->pinned_memory = pinned_memory;

	cudaError_t r;
	int device;
	r = cudaGetDevice(&device);

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_DEVICE;
	}

	struct cudaDeviceProp prop;
	r = cudaGetDeviceProperties(&prop, device);

	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_DEVICE;
	}

	s->threads_per_block = SPHYRAENA_THREADSPERBLOCK;
	s->stream_width = SPHYRAENA_STREAMWIDTH;

#ifdef SPHY_DEBUG
	printf("==================================================\n");
	printf("Device Summary\n");
	printf(" name:			%s\n", prop.name);
	printf(" totalGlobalMem:	%u (%.2fGB)\n", (unsigned)prop.totalGlobalMem,
		(double)prop.totalGlobalMem / 1073741824.0);
	printf(" sharedMemPerBlock:	%u (%.2fKB)\n", (unsigned)prop.sharedMemPerBlock,
		(double)prop.sharedMemPerBlock / 1024.0);
	printf(" regsPerBlock:		%i\n", prop.regsPerBlock);
	printf(" warpSize:		%i\n", prop.warpSize);
	printf(" memPitch:		%u (%.2fKB)\n", (unsigned)prop.memPitch,
		(double)prop.memPitch / 1024.0);
	printf(" maxThreadsPerBlock:	%i\n", prop.maxThreadsPerBlock);
	printf(" maxThreadsDim:		%i %i %i\n", prop.maxThreadsDim[0],
		prop.maxThreadsDim[1], prop.maxThreadsDim[2]);
	printf(" maxGridSize:		%i %i %i\n", prop.maxGridSize[0],
		prop.maxGridSize[1], prop.maxGridSize[2]);
	printf(" totalConstMem:		%u (%.2fKB)\n", (unsigned)prop.totalConstMem,
		(double)prop.totalConstMem / 1024.0);
	printf(" major:			%i\n", prop.major);
	printf(" minor:			%i\n", prop.minor);
	printf(" clockRate:		%i\n", prop.clockRate);
	printf(" textureAlignment:	%u\n", (unsigned)prop.textureAlignment);
	printf(" deviceOverlap:		%i\n", prop.deviceOverlap);
	printf(" multiProcessorCount:	%i\n", prop.multiProcessorCount);
	printf(" kernelExecTimeoutEnabl:%i\n", prop.kernelExecTimeoutEnabled);
	printf(" integrated:		%i\n", prop.integrated);
	printf(" canMapHostMemory:	%i\n", prop.canMapHostMemory);
	printf(" computeMode:		%i\n", prop.computeMode);
	printf("==================================================\n");
	//int num_devices;
	//cudaGetDeviceCount(&num_devices);
	//printf(" num devices:		%i\n", num_devices);
#endif

	if(pinned_memory) {
		r = cudaMallocHost((void**)&s->data_cpu, data_size + sizeof(sphyraena_data));
		if(r != cudaSuccess) {
			fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
			return SPHYRAENA_ERR_MEM;
		}

		r = cudaMallocHost((void**)&s->results_cpu, results_size + sizeof(sphyraena_results));
		if(r != cudaSuccess) {
			fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
			return SPHYRAENA_ERR_MEM;
		}

		if((r = cudaMallocHost((void*)&s->stmt_cpu, sizeof(sphyraena_stmt))) != cudaSuccess) {
			fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
			return SPHYRAENA_ERR_MEM;
		}
	}
	else {

		// allocate memory for data and results on the cpu side
		s->data_cpu = malloc(data_size + sizeof(sphyraena_data));
		s->results_cpu = malloc(results_size + sizeof(sphyraena_results));
		s->stmt_cpu = malloc(sizeof(sphyraena_stmt));
		//memset(s->data_cpu->d, 0xDEADBEEF, data_size);

		// check to make sure mallocs were successful
		if(s->data_cpu == NULL || s->results_cpu == NULL ||
			s->stmt_cpu == NULL) {
			fprintf(stderr, "Mallocs failed");
			return SPHYRAENA_ERR_MEM;
		}
	}

	// allocate memory for data and results on the gpu side
	r = cudaMalloc((void**)&s->data_gpu, data_size);
	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_CUDAMALLOC;
	}

	r = cudaMalloc((void**)&s->results_gpu, results_size + sizeof(sphyraena_results));
	if(r != cudaSuccess) {
		fprintf(stderr, "Cuda error: %s\n", cudaGetErrorString(r));
		return SPHYRAENA_ERR_CUDAMALLOC;
	}

	return SPHYRAENA_SUCCESS;
}


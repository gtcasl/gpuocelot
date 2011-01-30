/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include <cutil_inline.h>


////////////////////////////////////////////////////////////////////////////////
// Global types and parameters
////////////////////////////////////////////////////////////////////////////////
#define VOTE_DATA_GROUP 4

////////////////////////////////////////////////////////////////////////////////
// CUDA Voting Kernel functions
////////////////////////////////////////////////////////////////////////////////
#include "simpleVote_kernel.cu"


// Generate the test pattern for Tests 1 and 2
void genVoteTestPattern(unsigned int *VOTE_PATTERN, int size)
{
	// For testing VOTE.Any (all of these threads will return 0)
	for (int i=0; i < size/4; i++)
		VOTE_PATTERN[i] = 0x00000000;

	// For testing VOTE.Any (1/2 these threads will return 1)
	for (int i=2*size/8; i < 4*size/8; i++)
		VOTE_PATTERN[i] = (i&0x01) ? i : 0;

	// For testing VOTE.all (1/2 of these threads will return 0)
	for (int i=2*size/4; i < 3*size/4; i++)
		VOTE_PATTERN[i] = (i&0x01) ? 0 : i;
	
	// For testing VOTE.all (all of these threads will return 1)
	for (int i=3*size/4; i < 4*size/4; i++)
		VOTE_PATTERN[i] = 0xffffffff;
}

int checkErrors1(unsigned int *h_result, int start, int end, int warp_size, char *voteType)
{
	int i, sum=0;

	for (sum=0, i=start; i < end; i++) {
		sum += h_result[i];
	}
	if (sum > 0) {
		printf("\t<%s>[%d - %d] = ", voteType, start, end-1);
		for (i=start; i < end; i++) {
			printf("%d", h_result[i]);
		}
		printf(" - FAILED!\n", sum);
	}
	return (sum>0);
}

int checkErrors2(unsigned int *h_result, int start, int end, int warp_size, char *voteType)
{
	int i, sum=0;

	for (sum=0, i=start; i < end; i++) {
		sum += h_result[i];
	}
	if (sum!=warp_size) {
		printf("\t<%s>[%d - %d] = ", voteType, start, end-1);
		for (i=start; i < end; i++) {
			printf("%d", h_result[i]);
		}
		printf(" - FAILED!\n");
	}
	return (sum!=warp_size);
}


// Verification code for Kernel #1
int checkResultsVoteAnyKernel1(unsigned int *h_result, int size, int warp_size)
{
	int error_count = 0;

	error_count += checkErrors1(h_result,                             0,   VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.Any");
	error_count += checkErrors2(h_result,   VOTE_DATA_GROUP*warp_size/4, 2*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.Any");
	error_count += checkErrors2(h_result, 2*VOTE_DATA_GROUP*warp_size/4, 3*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.Any");
	error_count += checkErrors2(h_result, 3*VOTE_DATA_GROUP*warp_size/4, 4*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.Any");

	return error_count;
}

// Verification code for Kernel #2
int checkResultsVoteAllKernel2(unsigned int *h_result, int size, int warp_size)
{
	int error_count = 0;

#if 1	// results behave differently because DEVICE_EMULATION has WARP size of 1
	error_count += checkErrors1(h_result,                             0,   VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors2(h_result,   VOTE_DATA_GROUP*warp_size/4, 2*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors2(h_result, 2*VOTE_DATA_GROUP*warp_size/4, 3*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors2(h_result, 3*VOTE_DATA_GROUP*warp_size/4, 4*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
#else
	error_count += checkErrors1(h_result,                             0,   VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors1(h_result,   VOTE_DATA_GROUP*warp_size/4, 2*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors1(h_result, 2*VOTE_DATA_GROUP*warp_size/4, 3*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
	error_count += checkErrors2(h_result, 3*VOTE_DATA_GROUP*warp_size/4, 4*VOTE_DATA_GROUP*warp_size/4, warp_size, "Vote.All");
#endif
	return error_count;
}

// Verification code for Kernel #3
int checkResultsVoteAnyKernel3(bool *hinfo, int size)
{
	int i, error_count = 0;

#if 1	// comparison is different due to DEVICE_EMULATION having a WARP size of 1
	for (i = 0; i < size * 3; i++)  {
      // All warps should be all zeros.
	  if (i >= 0 && i < size) {
		  if (hinfo[i] != false) {
			error_count++;
		  }
	  } else if (i >= size && i < 2*size) {
          if (hinfo[i] != true) {
            error_count++;
          }
	  } else if (i >= 2*size && i < 3*size) {
          if (hinfo[i] != true) {
            error_count++;
          }
	  }
	}
#else
	for (i = 0; i < size * 3; i++)  {
      switch(i % 3) {
        case 0:
          // First warp should be all zeros.
          if (hinfo[i] != (i >= size * 1)) {
            error_count++;
          }
          break;
        case 1:
          // First warp and half of second should be all zeros.
          if (hinfo[i] != (i >= size * 3 / 2)) {
            error_count++;
          }
          break;
        case 2:
          // First two warps should be all zeros.
          if (hinfo[i] != (i >= size * 2)) {
            error_count++;
          }
          break;
      }
    }
#endif
	printf((error_count == 0) ? "\tPASSED!\n" : "\tFAILED!\n");
	return error_count;
}

int main(int argc, char **argv)
{
    unsigned int *h_input, *h_result;
    unsigned int *d_input, *d_result;

    bool *dinfo = NULL, *hinfo = NULL;
	int error_count[3] = { 0, 0, 0 };
    
    cudaDeviceProp deviceProp;
    int dev, warp_size;

	// use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( dev = cutGetMaxGflopsDeviceId() );

    cutilSafeCall(cudaChooseDevice(&dev, &deviceProp));
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, 0));

#if 1
	warp_size = 1;
#else
	if ((deviceProp.major > 1 || deviceProp.minor >= 2))
	{
		printf("simpleVoteIntrinsics: Using Device %d: \"%s\"\n", dev, deviceProp.name);
	} else 
	{
		printf("simpleVoteIntrinsics: requires Compute Capability 1.2 or higher\n");
		printf("Aborting test\n");
		printf("TEST PASSED\n");
		cutilExit(argc,argv);
    }
	warp_size = deviceProp.warpSize;
#endif

    h_input  = (unsigned int *)malloc(             VOTE_DATA_GROUP*warp_size * sizeof(unsigned int));
    h_result = (unsigned int *)malloc(             VOTE_DATA_GROUP*warp_size * sizeof(unsigned int));
    cutilSafeCall( cudaMalloc((void **)&d_input,  VOTE_DATA_GROUP*warp_size * sizeof(unsigned int)) );
    cutilSafeCall( cudaMalloc((void **)&d_result, VOTE_DATA_GROUP*warp_size * sizeof(unsigned int)) );
	genVoteTestPattern(h_input, VOTE_DATA_GROUP*warp_size);
	cutilSafeCall( cudaMemcpy(d_input, h_input, VOTE_DATA_GROUP*warp_size * sizeof(unsigned int), cudaMemcpyHostToDevice) );

	// Start of Vote Any Test Kernel #1
	printf("[VOTE Kernel Test 1/3]\n");
	printf("\tRunning <<Vote.Any>> kernel1 ...\n");
	{
		cutilSafeCall( cudaThreadSynchronize() );
		dim3 gridBlock(VOTE_DATA_GROUP, 1);
		dim3 threadBlock(warp_size, 1);
		VoteAnyKernel1<<<gridBlock, threadBlock>>>(d_input, d_result, VOTE_DATA_GROUP*warp_size);
		cutilCheckMsg("VoteAnyKernel() execution failed\n");
		cutilSafeCall( cudaThreadSynchronize() );
	}
	cutilSafeCall( cudaMemcpy(h_result, d_result, VOTE_DATA_GROUP*warp_size * sizeof(unsigned int), cudaMemcpyDeviceToHost) );
	error_count[0] += checkResultsVoteAnyKernel1(h_result, VOTE_DATA_GROUP*warp_size, warp_size);

	// Start of Vote All Test Kernel #2
	printf("\n[VOTE Kernel Test 2/3]\n");
	printf("\tRunning <<Vote.All>> kernel2 ...\n");
	{
		cutilSafeCall( cudaThreadSynchronize() );
		dim3 gridBlock(VOTE_DATA_GROUP, 1);
		dim3 threadBlock(warp_size, 1);
	    VoteAllKernel2<<<gridBlock, threadBlock>>>(d_input, d_result, VOTE_DATA_GROUP*warp_size);
		cutilCheckMsg("VoteAllKernel() execution failed\n");
		cutilSafeCall( cudaThreadSynchronize() );
	}
	cutilSafeCall( cudaMemcpy(h_result, d_result, VOTE_DATA_GROUP*warp_size * sizeof(unsigned int), cudaMemcpyDeviceToHost) );
	error_count[1] += checkResultsVoteAllKernel2(h_result, VOTE_DATA_GROUP*warp_size, warp_size);

	// Second Vote Kernel Test #3 (both Any/All)
	hinfo = (bool *)calloc(warp_size * 3 * 3, sizeof(bool));
    cudaMalloc((void**)&dinfo, warp_size * 3 * 3 * sizeof(bool));
    cudaMemcpy(dinfo, hinfo, warp_size * 3 * 3 * sizeof(bool),
               cudaMemcpyHostToDevice);

	printf("\n[VOTE Kernel Test 3/3]\n");
	printf("\tRunning <<Vote.Any>> kernel3 ...\n");
	{
		cutilSafeCall( cudaThreadSynchronize() );
		VoteAnyKernel3<<<3, warp_size>>>(dinfo, warp_size);
		cutilSafeCall( cudaThreadSynchronize() );
	}

    cudaMemcpy(hinfo, dinfo, warp_size * 3 * 3 * sizeof(bool),
               cudaMemcpyDeviceToHost);

	error_count[2] = checkResultsVoteAnyKernel3(hinfo, warp_size * 3);

	printf("\n");
    if (error_count[0] == 0 && 
		error_count[1] == 0 &&
		error_count[2] == 0)
	{
        printf("TEST PASSED\n");
	}
	else {
        printf("TEST FAILED\n");      
	}
 
	// Now free these resources for Test #1,2
    cutilSafeCall( cudaFree(d_input) );
    cutilSafeCall( cudaFree(d_result) );
    free(h_input);
    free(h_result);

	// Free resources from Test #3
    free(hinfo); cudaFree(dinfo);
		
	printf("\tShutting down...\n");
    cudaThreadExit();
	cutilExit(argc, argv);
}

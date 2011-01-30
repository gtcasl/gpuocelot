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
#include <cuda.h>

/* Add two vectors on the GPU */

__global__ void vectorAddGPU(float *a, float *b, float *c, int N)
{
  int idx = blockIdx.x*blockDim.x + threadIdx.x;
  if (idx < N)
    c[idx] = a[idx] + b[idx];
}

int main(int argc, char **argv)
{
  int n, nelem, idev, deviceCount;
  char *device = NULL;
  unsigned int flags;
  size_t bytes;
  float *a, *b, *c;                      // Pinned memory allocated on the CPU
  float *d_a, *d_b, *d_c;                // Device pointers for mapped memory  
  float errorNorm, refNorm, ref, diff;
  cudaDeviceProp deviceProp;

  if(cutCheckCmdLineFlag(argc, (const char **)argv, "help"))
  {
    printf("Usage:  simpleZeroCopy [OPTION]\n\n");
    printf("Options:\n");
    printf("  --device=[device #]  Specify the device to be used\n");
    cutilExit(argc, argv);    
  }

  /* Get the device selected by the user or default to 0, and then set it. */

  if(cutGetCmdLineArgumentstr(argc, (const char**)argv, "device", &device))
  {
    cudaGetDeviceCount(&deviceCount);
    idev = atoi(device);
    if(idev >= deviceCount || idev < 0)
    {
      fprintf(stderr, "Invalid device number %d, using default device 0.\n",
              idev);
      idev = 0;
    }
  }
  else
  {
    idev = 0;
  }

  cutilSafeCall(cudaSetDevice(idev));

  /* Verify the selected device supports mapped memory and set the device
     flags for mapping host memory. */

  cutilSafeCall(cudaGetDeviceProperties(&deviceProp, idev));

#if CUDART_VERSION >= 2020
  if(!deviceProp.canMapHostMemory)
  {
    fprintf(stderr, "Device %d cannot map host memory!\n", idev);
    printf("Test PASSED");
    cutilExit(argc, argv);
  }
  cutilSafeCall(cudaSetDeviceFlags(cudaDeviceMapHost));
#else
  fprintf(stderr, "This CUDART version does not support <cudaDeviceProp.canMapHostMemory> field\n");
  printf("Test PASSED");
  cutilExit(argc, argv);
#endif

  /* Allocate mapped CPU memory. */

  nelem = 1048576;
  bytes = nelem*sizeof(float);
#if CUDART_VERSION >= 2020
  flags = cudaHostAllocMapped;
  cutilSafeCall(cudaHostAlloc((void **)&a, bytes, flags));
  cutilSafeCall(cudaHostAlloc((void **)&b, bytes, flags));
  cutilSafeCall(cudaHostAlloc((void **)&c, bytes, flags));
#endif
  /* Initialize the vectors. */

  for(n = 0; n < nelem; n++)
  {
    a[n] = rand() / (float)RAND_MAX;
    b[n] = rand() / (float)RAND_MAX;
  }

  /* Get the device pointers for the pinned CPU memory mapped into the GPU
     memory space. */

#if CUDART_VERSION >= 2020
  cutilSafeCall(cudaHostGetDevicePointer((void **)&d_a, (void *)a, 0));
  cutilSafeCall(cudaHostGetDevicePointer((void **)&d_b, (void *)b, 0));
  cutilSafeCall(cudaHostGetDevicePointer((void **)&d_c, (void *)c, 0));
#endif

  /* Call the GPU kernel using the device pointers for the mapped memory. */ 

  printf("Adding vectors using mapped CPU memory...\n");
  dim3 block(256);
  dim3 grid((unsigned int)ceil(nelem/(float)block.x));
  vectorAddGPU<<<grid, block>>>(d_a, d_b, d_c, nelem);  
  cutilSafeCall(cudaThreadSynchronize());
  cutilCheckMsg("vectorAddGPU() execution failed");

  /* Compare the results */

  printf("Checking the results...\n");
  errorNorm = 0.f;
  refNorm = 0.f;
  for(n = 0; n < nelem; n++)
  {
    ref = a[n] + b[n];
    diff = c[n] - ref;
    errorNorm += diff*diff;
    refNorm += ref*ref;
  }
  errorNorm = (float)sqrt((double)errorNorm);
  refNorm = (float)sqrt((double)refNorm);

  /* Memory clean up */

  printf("Releasing CPU memory...\n");
#if CUDART_VERSION >= 2020
  cutilSafeCall(cudaFreeHost(a));
  cutilSafeCall(cudaFreeHost(b));
  cutilSafeCall(cudaFreeHost(c));
#endif

  cudaThreadExit();

  printf("Test %s\n", (errorNorm/refNorm < 1.e-6f) ? "PASSED" : "FAILED");

  cutilExit(argc, argv);
}

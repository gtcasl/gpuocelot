/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

// includes, system
#include <stdio.h>
#include <stdlib.h>

// includes, project
#include <sdkHelper.h>  // helper for shared that are common to CUDA SDK samples
#include <shrQATest.h>  // This is for automated testing output (--qatest)
#include <shrUtils.h>

// includes CUDA
#include <cuda_runtime.h>
#include <cuda.h>

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors(cudaError err, const char *file, const int line )
{
    if(cudaSuccess != err)
    {
        fprintf(stderr, "%s(%i) : CUDA Runtime API error %d: %s.\n",file, line, (int)err, cudaGetErrorString( err ) );
        exit(-1);        
    }
}

// This will output the proper error string when calling cudaGetLastError
#define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

inline void __getLastCudaError(const char *errorMessage, const char *file, const int line )
{
    cudaError_t err = cudaGetLastError();
    if (cudaSuccess != err)
    {
        fprintf(stderr, "%s(%i) : getLastCudaError() CUDA error : %s : (%d) %s.\n",
        file, line, errorMessage, (int)err, cudaGetErrorString( err ) );
        exit(-1);
    }
}

// General GPU Device CUDA Initialization
int gpuDeviceInit(int devID)
{
    int deviceCount;
    checkCudaErrors(cudaGetDeviceCount(&deviceCount));

    if (deviceCount == 0)
    {
        fprintf(stderr, "gpuDeviceInit() CUDA error: no devices supporting CUDA.\n");
        exit(-1);
    }

    if (devID < 0)
       devID = 0;
        
    if (devID > deviceCount-1)
    {
        fprintf(stderr, "\n");
        fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
        fprintf(stderr, ">> gpuDeviceInit (-device=%d) is not a valid GPU device. <<\n", devID);
        fprintf(stderr, "\n");
        return -devID;
    }

    cudaDeviceProp deviceProp;
    checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );

    if (deviceProp.major < 1)
    {
        fprintf(stderr, "gpuDeviceInit(): GPU device does not support CUDA.\n");
        exit(-1);                                                  
    }
    
    checkCudaErrors( cudaSetDevice(devID) );
    printf("gpuDeviceInit() CUDA Device [%d]: \"%s\n", devID, deviceProp.name);

    return devID;
}

// This function returns the best GPU (with maximum GFLOPS)
int gpuGetMaxGflopsDeviceId()
{
    int current_device     = 0, sm_per_multiproc  = 0;
    int max_compute_perf   = 0, max_perf_device   = 0;
    int device_count       = 0, best_SM_arch      = 0;
    cudaDeviceProp deviceProp;
    cudaGetDeviceCount( &device_count );
    
    // Find the best major SM Architecture GPU device
    while (current_device < device_count)
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major > 0 && deviceProp.major < 9999)
        {
            best_SM_arch = MAX(best_SM_arch, deviceProp.major);
        }
        current_device++;
    }

    // Find the best CUDA capable GPU device
    current_device = 0;
    while( current_device < device_count )
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major == 9999 && deviceProp.minor == 9999)
        {
            sm_per_multiproc = 1;
        }
        else
        {
            sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
        }
        
        int compute_perf  = deviceProp.multiProcessorCount * sm_per_multiproc * deviceProp.clockRate;
        
    if( compute_perf  > max_compute_perf )
    {
            // If we find GPU with SM major > 2, search only these
            if ( best_SM_arch > 2 )
            {
                // If our device==dest_SM_arch, choose this, or else pass
                if (deviceProp.major == best_SM_arch)
                {
                    max_compute_perf  = compute_perf;
                    max_perf_device   = current_device;
                 }
            }
            else
            {
                max_compute_perf  = compute_perf;
                max_perf_device   = current_device;
             }
        }
        ++current_device;
    }
    return max_perf_device;
}


// Initialization code to find the best CUDA Device
int findCudaDevice(int argc, const char **argv)
{
    cudaDeviceProp deviceProp;
    int devID = 0;
    // If the command-line has a device number specified, use it
    if (checkCmdLineFlag(argc, argv, "device"))
    {
        devID = getCmdLineArgumentInt(argc, argv, "device=");
        if (devID < 0)
        {
            printf("Invalid command line parameter\n ");
            exit(-1);
        }
        else
        {
            devID = gpuDeviceInit(devID);
            if (devID < 0)
            {
                printf("exiting...\n");
                shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
                exit(-1);
            }
        }
    }
    else
    {
        // Otherwise pick the device with highest Gflops/s
        devID = gpuGetMaxGflopsDeviceId();
        checkCudaErrors( cudaSetDevice( devID ) );
        checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
        printf("GPU Device %d: \"%s\" with compute capability %d.%d\n\n", devID, deviceProp.name, deviceProp.major, deviceProp.minor);
    }
    return devID;
}
// end of CUDA Helper Functions

/* Add two vectors on the GPU */
__global__ void vectorAddGPU(float *a, float *b, float *c, int N)
{
  int idx = blockIdx.x*blockDim.x + threadIdx.x;
  if (idx < N)
    c[idx] = a[idx] + b[idx];
}

// Allocate generic memory with malloc() and pin it laster instead of using cudaHostAlloc()
bool bPinGenericMemory = false;

// Macro to aligned up to the memory size in question
#define MEMORY_ALIGNMENT  4096
#define ALIGN_UP(x,size) ( ((size_t)x+(size-1))&(~(size-1)) )

int main(int argc, char **argv)
{
  int n, nelem, deviceCount;
  int idev = 0; // use default device 0
  char *device = NULL;
  unsigned int flags;
  size_t bytes;
  float *a, *b, *c;                      // Pinned memory allocated on the CPU
  float *a_UA, *b_UA, *c_UA;             // Non-4K Aligned Pinned memory on the CPU
  float *d_a, *d_b, *d_c;                // Device pointers for mapped memory  
  float errorNorm, refNorm, ref, diff;
  cudaDeviceProp deviceProp;

  shrQAStart(argc, argv);

  if(checkCmdLineFlag(argc, (const char **)argv, "help"))
  {
    printf("Usage:  simpleZeroCopy [OPTION]\n\n");
    printf("Options:\n");
    printf("  --device=[device #]  Specify the device to be used\n");
    printf("  --use_generic_memory (optional) use generic page-aligned for system memory\n");
    shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
  }

  /* Get the device selected by the user or default to 0, and then set it. */
  if(getCmdLineArgumentString(argc, (const char**)argv, "device", &device))
  {
    cudaGetDeviceCount(&deviceCount);
    idev = atoi(device);
    if(idev >= deviceCount || idev < 0)
    {
      fprintf(stderr, "Device number %d is invalid, will use default CUDA device 0.\n", idev);
      idev = 0;
    }
  }
  
  if( checkCmdLineFlag( argc, (const char **)argv, "use_generic_memory") ) 
  {
#if defined(__APPLE__) || defined(MACOSX)
    bPinGenericMemory = false;  // Generic Pinning of System Paged memory is not currently supported on Mac OSX 
#else
    bPinGenericMemory = true;
#endif
  }

  if (bPinGenericMemory) {
     printf("> Using Generic System Paged Memory (malloc)\n");
  } else {
     printf("> Using CUDA Host Allocated (cudaHostAlloc)\n");
  }

  checkCudaErrors(cudaSetDevice(idev));

  /* Verify the selected device supports mapped memory and set the device
     flags for mapping host memory. */

  checkCudaErrors(cudaGetDeviceProperties(&deviceProp, idev));

#if CUDART_VERSION >= 2020
  if(!deviceProp.canMapHostMemory)
  {
    fprintf(stderr, "Device %d does not support mapping CPU host memory!\n", idev);
    cudaDeviceReset();	
    shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
  }
  checkCudaErrors(cudaSetDeviceFlags(cudaDeviceMapHost));
#else
    fprintf(stderr, "CUDART version %d.%d does not support <cudaDeviceProp.canMapHostMemory> field\n", , CUDART_VERSION/1000, (CUDART_VERSION%100)/10);
    cudaDeviceReset();	
    shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
#endif

#if CUDART_VERSION < 4000
  if (bPinGenericMemory)
  {
    fprintf(stderr, "CUDART version %d.%d does not support <cudaHostRegister> function\n", CUDART_VERSION/1000, (CUDART_VERSION%100)/10);
    cudaDeviceReset();	
    shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
  }
#endif

  /* Allocate mapped CPU memory. */

  nelem = 1048576;
  bytes = nelem*sizeof(float);
  if (bPinGenericMemory)
  {
#if CUDART_VERSION >= 4000
    a_UA = (float *) malloc( bytes + MEMORY_ALIGNMENT );
    b_UA = (float *) malloc( bytes + MEMORY_ALIGNMENT );
    c_UA = (float *) malloc( bytes + MEMORY_ALIGNMENT );

    // We need to ensure memory is aligned to 4K (so we will need to padd memory accordingly)
    a = (float *) ALIGN_UP( a_UA, MEMORY_ALIGNMENT );
    b = (float *) ALIGN_UP( b_UA, MEMORY_ALIGNMENT );
    c = (float *) ALIGN_UP( c_UA, MEMORY_ALIGNMENT );

    checkCudaErrors(cudaHostRegister(a, bytes, CU_MEMHOSTALLOC_DEVICEMAP));
    checkCudaErrors(cudaHostRegister(b, bytes, CU_MEMHOSTALLOC_DEVICEMAP));
    checkCudaErrors(cudaHostRegister(c, bytes, CU_MEMHOSTALLOC_DEVICEMAP));
#endif
  }
  else
  {
#if CUDART_VERSION >= 2020
    flags = cudaHostAllocMapped;
    checkCudaErrors(cudaHostAlloc((void **)&a, bytes, flags));
    checkCudaErrors(cudaHostAlloc((void **)&b, bytes, flags));
    checkCudaErrors(cudaHostAlloc((void **)&c, bytes, flags));
#endif
  }

  /* Initialize the vectors. */

  for(n = 0; n < nelem; n++)
  {
    a[n] = rand() / (float)RAND_MAX;
    b[n] = rand() / (float)RAND_MAX;
  }

  /* Get the device pointers for the pinned CPU memory mapped into the GPU
     memory space. */

#if CUDART_VERSION >= 2020
  checkCudaErrors(cudaHostGetDevicePointer((void **)&d_a, (void *)a, 0));
  checkCudaErrors(cudaHostGetDevicePointer((void **)&d_b, (void *)b, 0));
  checkCudaErrors(cudaHostGetDevicePointer((void **)&d_c, (void *)c, 0));
#endif

  /* Call the GPU kernel using the CPU pointers residing in CPU mapped memory. */ 
  printf("> vectorAddGPU kernel will add vectors using mapped CPU memory...\n");
  dim3 block(256);
  dim3 grid((unsigned int)ceil(nelem/(float)block.x));
  vectorAddGPU<<<grid, block>>>(d_a, d_b, d_c, nelem);  
  checkCudaErrors(cudaDeviceSynchronize());
  getLastCudaError("vectorAddGPU() execution failed");

  /* Compare the results */

  printf("> Checking the results from vectorAddGPU() ...\n");
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

  printf("> Releasing CPU memory...\n");
  if (bPinGenericMemory)
  {
#if CUDART_VERSION >= 4000
    checkCudaErrors(cudaHostUnregister(a));
    checkCudaErrors(cudaHostUnregister(b));
    checkCudaErrors(cudaHostUnregister(c));
    free(a_UA);
    free(b_UA);
    free(c_UA);
#endif
  }
  else
  {
#if CUDART_VERSION >= 2020
    checkCudaErrors(cudaFreeHost(a));
    checkCudaErrors(cudaFreeHost(b));
    checkCudaErrors(cudaFreeHost(c));
#endif
  }

  cudaDeviceReset();	
  shrQAFinishExit(argc, (const char **)argv, (errorNorm/refNorm < 1.e-6f) ? QA_PASSED : QA_FAILED);
}

/*
 * Copyright 1993-2011 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

/*
 * Demonstration of inline PTX (assembly language) usage in CUDA kernels
 */

#include <cutil_inline.h>

// includes, system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// includes, project
#include <sdkHelper.h>  // helper for shared that are common to CUDA SDK samples
#include <shrQATest.h>  // This is for automated testing output (--qatest)

using namespace std;

bool g_bQATest = false;

#ifdef STRCASECMP
#undef STRCASECMP
#endif
#ifdef STRNCASECMP
#undef STRNCASECMP
#endif

#ifdef _WIN32
   #define STRCASECMP  _stricmp
   #define STRNCASECMP _strnicmp
#else
   #define STRCASECMP  strcasecmp
   #define STRNCASECMP strncasecmp
#endif

#define ASSERT(x, msg, retcode) \
    if (!(x)) \
    { \
        cout << msg << " " << __FILE__ << ":" << __LINE__ << endl; \
        return retcode; \
    }


__global__ void sequence_gpu(int *d_ptr, int length)
{
    int elemID = blockIdx.x * blockDim.x + threadIdx.x;
    if (elemID < length)
    {
        unsigned int laneid;
        //This command gets the lane ID within the current warp
        asm("mov.u32 %0, %%laneid;" : "=r"(laneid));
        d_ptr[elemID] = laneid;
    }
}


void sequence_cpu(int *h_ptr, int length)
{
    for (int elemID=0; elemID<length; elemID++)
    {
        h_ptr[elemID] = elemID % 32;
    }
}

void processArgs(int argc, char **argv)
{
    for (int i=1; i < argc; i++) {
        if((!STRNCASECMP((argv[i]+1), "noprompt", 8)) || (!STRNCASECMP((argv[i]+2), "noprompt", 8)) )
        {
            g_bQATest = true;
        }
    }
}

int main(int argc, char **argv)
{

    shrQAStart(argc, argv);

    cout << "CUDA inline PTX assembler sample" << endl;
    cout << "================================" << endl;
    cout << "Self-test started" << endl;

    const int N = 1000;

    processArgs(argc, argv);
    
    int *d_ptr;
    ASSERT(cudaSuccess == cudaMalloc(&d_ptr, N * sizeof(int)), "Device allocation of " << N << " ints failed", -1);

    int *h_ptr;
    ASSERT(cudaSuccess == cudaMallocHost(&h_ptr, N * sizeof(int)), "Host allocation of " << N << " ints failed", -1);

    cout << "Memory allocated successfully" << endl;

    dim3 cudaBlockSize(256,1,1);
    dim3 cudaGridSize((N + cudaBlockSize.x - 1) / cudaBlockSize.x, 1, 1);
    sequence_gpu<<<cudaGridSize, cudaBlockSize>>>(d_ptr, N);
    ASSERT(cudaSuccess == cudaGetLastError(), "Kernel launch failed", -1);
    ASSERT(cudaSuccess == cudaDeviceSynchronize(), "Kernel synchronization failed", -1);

    sequence_cpu(h_ptr, N);

    cout << "CUDA and CPU algorithm implementations finished" << endl;

    int *h_d_ptr;
    ASSERT(cudaSuccess == cudaMallocHost(&h_d_ptr, N * sizeof(int)), "Host allocation of " << N << " ints failed", -1);
    ASSERT(cudaSuccess == cudaMemcpy(h_d_ptr, d_ptr, N * sizeof(int), cudaMemcpyDeviceToHost), "Copy of " << N << " ints from device to host failed", -1);
    bool bValid = true;
    for (int i=0; i<N && bValid; i++)
    {
        if (h_ptr[i] != h_d_ptr[i])
        {
            bValid = false;
        }
    }

    ASSERT(cudaSuccess == cudaFree(d_ptr), "Device deallocation failed", -1);
    ASSERT(cudaSuccess == cudaFreeHost(h_ptr), "Host deallocation failed", -1);
    ASSERT(cudaSuccess == cudaFreeHost(h_d_ptr), "Host deallocation failed", -1);

    cout << "Memory deallocated successfully" << endl;
    
    cudaDeviceReset();

    cout << "TEST Results " << endl;
    shrQAFinishExit(argc, (const char **)argv, (bValid ? QA_PASSED : QA_FAILED));
}

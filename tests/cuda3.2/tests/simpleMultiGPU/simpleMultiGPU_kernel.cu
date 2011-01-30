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

/*
 * This application demonstrates how to use the CUDA API to use multiple GPUs.
 *
 * There's one CUDA context per thread. To use multiple CUDA contexts you
 * have to create multiple threads. One for each GPU. For optimal performance,
 * the number of CPU cores should be equal to the number of GPUs in the system.
 *
 * Creating CPU threads has a certain overhead. So, this is only worth when you
 * have a significant amount of work to do per thread. It's also recommended to
 * create a pool of threads and reuse them to avoid this overhead.
 *
 * Note that in order to detect multiple GPUs in your system you have to disable
 * SLI in the nvidia control panel. Otherwise only one GPU is visible to the 
 * application. On the other side, you can still extend your desktop to screens 
 * attached to both GPUs.
 */


////////////////////////////////////////////////////////////////////////////////
// Simple reduction kernel.
// Refer to the 'reduction' CUDA SDK sample describing
// reduction optimization strategies
////////////////////////////////////////////////////////////////////////////////
__global__ static void reduceKernel(float *d_Result, float *d_Input, int N){
    const int     tid = blockIdx.x * blockDim.x + threadIdx.x;
    const int threadN = gridDim.x * blockDim.x;
    float sum = 0;
    for(int pos = tid; pos < N; pos += threadN)
        sum += d_Input[pos];

    d_Result[tid] = sum;
}

extern "C" 
void launch_reduceKernel(float *d_Result, float *d_Input, int N, int BLOCK_N, int THREAD_N) 
{
	reduceKernel<<<BLOCK_N, THREAD_N>>>(d_Result, d_Input, N);
}

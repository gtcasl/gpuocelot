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
 * This sample implements Mersenne Twister random number generator 
 * and Cartesian Box-Muller transformation on the GPU.
 * See supplied whitepaper for more explanations.
 */


// Utilities and system includes
#include <shrUtils.h>
#include <shrQATest.h>
#include <cutil_inline.h>

#include "MersenneTwister.h"

///////////////////////////////////////////////////////////////////////////////
// Common host and device function 
///////////////////////////////////////////////////////////////////////////////
//ceil(a / b)
extern "C" int iDivUp(int a, int b){
    return ((a % b) != 0) ? (a / b + 1) : (a / b);
}

//floor(a / b)
extern "C" int iDivDown(int a, int b){
    return a / b;
}

//Align a to nearest higher multiple of b
extern "C" int iAlignUp(int a, int b){
    return ((a % b) != 0) ?  (a - a % b + b) : a;
}

//Align a to nearest lower multiple of b
extern "C" int iAlignDown(int a, int b){
    return a - a % b;
}

///////////////////////////////////////////////////////////////////////////////
// Reference MT front-end and Box-Muller transform
///////////////////////////////////////////////////////////////////////////////
extern "C" void initMTRef(const char *fname);
extern "C" void RandomRef(float *h_Random, int NPerRng, unsigned int seed);
extern "C" void BoxMullerRef(float *h_Random, int NPerRng);

///////////////////////////////////////////////////////////////////////////////
// Fast GPU random number generator and Box-Muller transform
///////////////////////////////////////////////////////////////////////////////
#include "MersenneTwister_kernel.cu"

///////////////////////////////////////////////////////////////////////////////
// Data configuration
///////////////////////////////////////////////////////////////////////////////
const int    PATH_N = 24000000;
const int N_PER_RNG = iAlignUp(iDivUp(PATH_N, MT_RNG_COUNT), 2);
const int    RAND_N = MT_RNG_COUNT * N_PER_RNG;

const unsigned int SEED = 777;

#define DO_BOXMULLER
///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    // Start logs
    shrQAStart(argc, argv);

    shrSetLogFileName ("MersenneTwister.txt");
    shrLog("%s Starting...\n\n", argv[0]);

    float *d_Rand, 
          *h_RandCPU,
          *h_RandGPU;

    double rCPU, rGPU, delta, sum_delta, max_delta, sum_ref, L1norm, gpuTime;

    int i, j;
    unsigned int hTimer;

    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    shrLog("Initializing data for %i samples...\n", PATH_N);
        h_RandCPU  = (float *)malloc(RAND_N * sizeof(float));
        h_RandGPU  = (float *)malloc(RAND_N * sizeof(float));
        cutilSafeCall( cudaMalloc((void **)&d_Rand, RAND_N * sizeof(float)) );

    shrLog("Loading CPU and GPU twisters configurations...\n");
        const char *raw_path = shrFindFilePath("MersenneTwister.raw", argv[0]);
        const char *dat_path = shrFindFilePath("MersenneTwister.dat", argv[0]);
        initMTRef(raw_path);
        loadMTGPU(dat_path);
        seedMTGPU(SEED);

    shrLog("Generating random numbers on GPU...\n\n");
	int numIterations = 10;
	for (i = -1; i < numIterations; i++)
	{
		if (i == 0) 
		{
			cutilSafeCall( cutilDeviceSynchronize() );
			cutilCheckError( cutResetTimer(hTimer) );
			cutilCheckError( cutStartTimer(hTimer) );
		}
        RandomGPU<<<32, 128>>>(d_Rand, N_PER_RNG);
        cutilCheckMsg("RandomGPU() execution failed\n");
#ifdef DO_BOXMULLER        
        BoxMullerGPU<<<32, 128>>>(d_Rand, N_PER_RNG);
        cutilCheckMsg("BoxMullerGPU() execution failed\n");
#endif
    }
    cutilSafeCall( cutilDeviceSynchronize() );
    cutilCheckError( cutStopTimer(hTimer) );
    gpuTime = 1.0e-3 * cutGetTimerValue(hTimer)/(double)numIterations;
    shrLogEx(LOGBOTH | MASTER, 0, "MersenneTwister, Throughput = %.4f GNumbers/s, Time = %.5f s, Size = %u Numbers, NumDevsUsed = %u, Workgroup = %u\n", 
               1.0e-9 * RAND_N / gpuTime, gpuTime, RAND_N, 1, 128); 

    shrLog("\nReading back the results...\n");
        cutilSafeCall( cudaMemcpy(h_RandGPU, d_Rand, RAND_N * sizeof(float), cudaMemcpyDeviceToHost) );

    shrLog("Checking GPU results...\n");
        shrLog(" ...generating random numbers on CPU using reference generator\n");
        RandomRef(h_RandCPU, N_PER_RNG, SEED);

        #ifdef DO_BOXMULLER
            shrLog(" ...applying Box-Muller transformation on CPU\n");
            BoxMullerRef(h_RandCPU, N_PER_RNG);
        #endif

        shrLog(" ...comparing the results\n\n");
        max_delta = 0;
        sum_delta = 0;
        sum_ref   = 0;
        for(i = 0; i < MT_RNG_COUNT; i++)
            for(j = 0; j < N_PER_RNG; j++){
                rCPU = h_RandCPU[i * N_PER_RNG + j];
                rGPU = h_RandGPU[i + j * MT_RNG_COUNT];
                delta = fabs(rCPU - rGPU);
                sum_delta += delta;
                sum_ref   += fabs(rCPU);
                if(delta >= max_delta) max_delta = delta;
            }
    L1norm = (float)(sum_delta / sum_ref);
    shrLog("Max absolute error: %E\n", max_delta);
    shrLog("L1 norm: %E\n\n", L1norm);

    shrLog("Shutting down...\n");
        cutilSafeCall( cudaFree(d_Rand) );
        free(h_RandGPU);
        free(h_RandCPU);

    cutilCheckError( cutDeleteTimer( hTimer) );

    cutilDeviceReset();	
    shrQAFinishExit(argc, (const char**)argv, (L1norm < 1e-6) ? QA_PASSED : QA_FAILED);
}

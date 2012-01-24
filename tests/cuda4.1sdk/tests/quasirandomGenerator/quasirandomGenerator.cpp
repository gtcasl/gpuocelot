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


// Utilities and system includes
#include <shrUtils.h>
#include <shrQATest.h>
#include <cutil_inline.h>

#include <cuda_runtime.h>

#ifdef WIN32
#define strcasecmp strcmpi
#endif

#include "quasirandomGenerator_common.h"

////////////////////////////////////////////////////////////////////////////////
// CPU code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initQuasirandomGenerator(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION]
);

extern "C" float getQuasirandomValue(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION],
    int i,
    int dim
);

extern "C" double getQuasirandomValue63(INT64 i, int dim);
extern "C" double MoroInvCNDcpu(unsigned int p);

////////////////////////////////////////////////////////////////////////////////
// GPU code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initTable_SM10(unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION]);
extern "C" void quasirandomGenerator_SM10(float *d_Output, unsigned int seed, unsigned int N);
extern "C" void inverseCND_SM10(float *d_Output, unsigned int *d_Input, unsigned int N);
extern "C" void initTable_SM13(unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION]);
extern "C" void quasirandomGenerator_SM13(float *d_Output, unsigned int seed, unsigned int N);
extern "C" void inverseCND_SM13(float *d_Output, unsigned int *d_Input, unsigned int N);

const int N = 1048576;

int main(int argc, char **argv)
{
    // Start logs
    shrQAStart(argc, argv);

    shrSetLogFileName ("quasirandomGenerator.txt");
    shrLog("%s Starting...\n\n", argv[0]);
    
    unsigned int useDoublePrecision;

    char *precisionChoice;
    cutGetCmdLineArgumentstr(argc, (const char **)argv, "type", &precisionChoice);
    if(precisionChoice == NULL)
        useDoublePrecision = 0;
    else{
        if(!strcasecmp(precisionChoice, "double"))
            useDoublePrecision = 1;
        else
            useDoublePrecision = 0;
    }

    unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION];

    float
        *h_OutputGPU;

    float
        *d_Output;

    int
        dim, pos;

    double
        delta, ref, sumDelta, sumRef, L1norm, gpuTime;

    unsigned int hTimer;

    if(sizeof(INT64) != 8){
        shrLog("sizeof(INT64) != 8\n");
        return 0;
    }

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError(cutCreateTimer(&hTimer));

    int deviceIndex;
    cutilSafeCall(cudaGetDevice(&deviceIndex));
    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, deviceIndex));
    int version = deviceProp.major * 10 + deviceProp.minor;
    if(useDoublePrecision && version < 13){
        shrLog("Double precision not supported.\n");
        cutilDeviceReset();
        return 0;
    }

    shrLog("Allocating GPU memory...\n");
        cutilSafeCall( cudaMalloc((void **)&d_Output, QRNG_DIMENSIONS * N * sizeof(float)) );

    shrLog("Allocating CPU memory...\n");
        h_OutputGPU = (float *)malloc(QRNG_DIMENSIONS * N * sizeof(float));

    shrLog("Initializing QRNG tables...\n\n");
        initQuasirandomGenerator(tableCPU);
        if(useDoublePrecision)
            initTable_SM13(tableCPU);
        else
            initTable_SM10(tableCPU);

    shrLog("Testing QRNG...\n\n");
        cutilSafeCall( cudaMemset(d_Output, 0, QRNG_DIMENSIONS * N * sizeof(float)) );
		int numIterations = 20;
		for (int i = -1; i < numIterations; i++)
		{
			if (i == 0)
			{
				cutilSafeCall( cutilDeviceSynchronize() );
				cutilCheckError( cutResetTimer(hTimer) );
				cutilCheckError( cutStartTimer(hTimer) );
			}
            if(useDoublePrecision)
                quasirandomGenerator_SM13(d_Output, 0, N);
            else
                quasirandomGenerator_SM10(d_Output, 0, N);
		}
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        gpuTime = cutGetTimerValue(hTimer)/(double)numIterations*1e-3;
	shrLogEx(LOGBOTH | MASTER, 0, "quasirandomGenerator, Throughput = %.4f GNumbers/s, Time = %.5f s, Size = %u Numbers, NumDevsUsed = %u, Workgroup = %u\n", 
                (double)QRNG_DIMENSIONS * (double)N * 1.0E-9 / gpuTime, gpuTime, QRNG_DIMENSIONS*N, 1, 128*QRNG_DIMENSIONS); 

    shrLog("\nReading GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, QRNG_DIMENSIONS * N * sizeof(float), cudaMemcpyDeviceToHost) );

    shrLog("Comparing to the CPU results...\n\n");
        sumDelta = 0;
        sumRef = 0;
        for(dim = 0; dim < QRNG_DIMENSIONS; dim++)
            for(pos = 0; pos < N; pos++){
                ref       = getQuasirandomValue63(pos, dim);
                delta     = (double)h_OutputGPU[dim * N + pos] - ref;
                sumDelta += fabs(delta);
                sumRef   += fabs(ref);
            }
    shrLog("L1 norm: %E\n", sumDelta / sumRef);

    shrLog("\nTesting inverseCNDgpu()...\n\n");
        cutilSafeCall( cudaMemset(d_Output, 0, QRNG_DIMENSIONS * N * sizeof(float)) );
		for (int i = -1; i < numIterations; i++)
		{
			if (i == 0) 
			{
				cutilSafeCall( cutilDeviceSynchronize() );
				cutilCheckError( cutResetTimer(hTimer) );
				cutilCheckError( cutStartTimer(hTimer) );
			}
            if(useDoublePrecision)
                inverseCND_SM13(d_Output, NULL, QRNG_DIMENSIONS * N);
            else
                inverseCND_SM10(d_Output, NULL, QRNG_DIMENSIONS * N);
		}
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        gpuTime = cutGetTimerValue(hTimer)/(double)numIterations*1e-3;
	shrLogEx(LOGBOTH | MASTER, 0, "quasirandomGenerator-inverse, Throughput = %.4f GNumbers/s, Time = %.5f s, Size = %u Numbers, NumDevsUsed = %u, Workgroup = %u\n", 
                (double)QRNG_DIMENSIONS * (double)N * 1E-9 / gpuTime, gpuTime, QRNG_DIMENSIONS*N, 1, 128); 

    shrLog("Reading GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, QRNG_DIMENSIONS * N * sizeof(float), cudaMemcpyDeviceToHost) );

    shrLog("\nComparing to the CPU results...\n");
        sumDelta = 0;
        sumRef = 0;
        unsigned int distance = ((unsigned int)-1) / (QRNG_DIMENSIONS * N + 1);
        for(pos = 0; pos < QRNG_DIMENSIONS * N; pos++){
            unsigned int d = (pos + 1) * distance;
            ref       = MoroInvCNDcpu(d);
            delta     = (double)h_OutputGPU[pos] - ref;
            sumDelta += fabs(delta);
            sumRef   += fabs(ref);
        }
    shrLog("L1 norm: %E\n\n", L1norm = sumDelta / sumRef);

    shrLog("Shutting down...\n");
        cutilCheckError(cutDeleteTimer(hTimer));
        free(h_OutputGPU);
        cutilSafeCall( cudaFree(d_Output) );

    cutilDeviceReset();
    shrQAFinishExit(argc, (const char**)argv, (L1norm < 1E-6) ? QA_PASSED : QA_FAILED);
}

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
 * This sample implements 64-bin histogram calculation
 * of arbitrary-sized 8-bit data array
 */

// Utility and system includes
#include <shrUtils.h>
#include <shrQATest.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>

// project include
#include "histogram_common.h"

const int numRuns = 16;

static char *sSDKsample = "[histogram]\0";

int main(int argc, char **argv)
{
    uchar *h_Data;
    uint  *h_HistogramCPU, *h_HistogramGPU;
    uchar *d_Data;
    uint  *d_Histogram;
    uint hTimer;
    int PassFailFlag = 1;
    uint byteCount = 64 * 1048576;
    uint uiSizeMult = 1;

    cudaDeviceProp deviceProp;
    deviceProp.major = 0;
    deviceProp.minor = 0;
    int dev;

	shrQAStart(argc, argv);

	// set logfile name and start logs
    shrSetLogFileName ("histogram.txt");

    //Use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( shrCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
        dev = cutilDeviceInit(argc, argv);
        if (dev < 0) {
           printf("No CUDA Capable Devices found, exiting...\n");
           shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
        }
    } else {
        cudaSetDevice( dev = cutGetMaxGflopsDeviceId() );
        cutilSafeCall( cudaChooseDevice(&dev, &deviceProp) );
    }
    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, dev) );

	printf("CUDA device [%s] has %d Multi-Processors, Compute %d.%d\n", 
		deviceProp.name, deviceProp.multiProcessorCount, deviceProp.major, deviceProp.minor);

	int version = deviceProp.major * 0x10 + deviceProp.minor;

	if(version < 0x11) 
    {
        printf("There is no device supporting a minimum of CUDA compute capability 1.1 for this SDK sample\n");
        cutilDeviceReset();
		shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
    }

    cutilCheckError(cutCreateTimer(&hTimer));

    // Optional Command-line multiplier to increase size of array to histogram
    if (shrGetCmdLineArgumentu(argc, (const char**)argv, "sizemult", &uiSizeMult))
    {
        uiSizeMult = CLAMP(uiSizeMult, 1, 10);
        byteCount *= uiSizeMult;
    }

    shrLog("Initializing data...\n");
        shrLog("...allocating CPU memory.\n");
            h_Data         = (uchar *)malloc(byteCount);
            h_HistogramCPU = (uint  *)malloc(HISTOGRAM256_BIN_COUNT * sizeof(uint));
            h_HistogramGPU = (uint  *)malloc(HISTOGRAM256_BIN_COUNT * sizeof(uint));

        shrLog("...generating input data\n");
            srand(2009);
            for(uint i = 0; i < byteCount; i++) 
                h_Data[i] = rand() % 256;

        shrLog("...allocating GPU memory and copying input data\n\n");
            cutilSafeCall( cudaMalloc((void **)&d_Data, byteCount  ) );
            cutilSafeCall( cudaMalloc((void **)&d_Histogram, HISTOGRAM256_BIN_COUNT * sizeof(uint)  ) );
            cutilSafeCall( cudaMemcpy(d_Data, h_Data, byteCount, cudaMemcpyHostToDevice) );

    {
        shrLog("Starting up 64-bin histogram...\n\n");
            initHistogram64();

        shrLog("Running 64-bin GPU histogram for %u bytes (%u runs)...\n\n", byteCount, numRuns);
            for(int iter = -1; iter < numRuns; iter++){
                //iter == -1 -- warmup iteration
                if(iter == 0){
                    cutilSafeCall( cutilDeviceSynchronize() );
                    cutilCheckError( cutResetTimer(hTimer) );
                    cutilCheckError( cutStartTimer(hTimer) );
                }

                histogram64(d_Histogram, d_Data, byteCount);
            }

            cutilSafeCall( cutilDeviceSynchronize() );
            cutilCheckError(  cutStopTimer(hTimer));
            double dAvgSecs = 1.0e-3 * (double)cutGetTimerValue(hTimer) / (double)numRuns;
        shrLog("histogram64() time (average) : %.5f sec, %.4f MB/sec\n\n", dAvgSecs, ((double)byteCount * 1.0e-6) / dAvgSecs);
        shrLogEx(LOGBOTH | MASTER, 0, "histogram64, Throughput = %.4f MB/s, Time = %.5f s, Size = %u Bytes, NumDevsUsed = %u, Workgroup = %u\n", 
                (1.0e-6 * (double)byteCount / dAvgSecs), dAvgSecs, byteCount, 1, HISTOGRAM64_THREADBLOCK_SIZE); 

        shrLog("\nValidating GPU results...\n");
            shrLog(" ...reading back GPU results\n");
                cutilSafeCall( cudaMemcpy(h_HistogramGPU, d_Histogram, HISTOGRAM64_BIN_COUNT * sizeof(uint), cudaMemcpyDeviceToHost) );

            shrLog(" ...histogram64CPU()\n");
               histogram64CPU(
                    h_HistogramCPU,
                    h_Data,
                    byteCount
                );

            shrLog(" ...comparing the results...\n");
                for(uint i = 0; i < HISTOGRAM64_BIN_COUNT; i++)
                    if(h_HistogramGPU[i] != h_HistogramCPU[i]) PassFailFlag = 0;
            shrLog(PassFailFlag ? " ...64-bin histograms match\n\n" : " ***64-bin histograms do not match!!!***\n\n" );

        shrLog("Shutting down 64-bin histogram...\n\n\n");
            closeHistogram64();
    }

    {
        shrLog("Initializing 256-bin histogram...\n");
            initHistogram256();

        shrLog("Running 256-bin GPU histogram for %u bytes (%u runs)...\n\n", byteCount, numRuns);
            for(int iter = -1; iter < numRuns; iter++){
                //iter == -1 -- warmup iteration
                if(iter == 0){
                    cutilSafeCall( cutilDeviceSynchronize() );
                    cutilCheckError( cutResetTimer(hTimer) );
                    cutilCheckError( cutStartTimer(hTimer) );
                }

                histogram256(d_Histogram, d_Data, byteCount);
            }

            cutilSafeCall( cutilDeviceSynchronize() );
            cutilCheckError(  cutStopTimer(hTimer));
            double dAvgSecs = 1.0e-3 * (double)cutGetTimerValue(hTimer) / (double)numRuns;
        shrLog("histogram256() time (average) : %.5f sec, %.4f MB/sec\n\n", dAvgSecs, ((double)byteCount * 1.0e-6) / dAvgSecs);
        shrLogEx(LOGBOTH | MASTER, 0, "histogram256, Throughput = %.4f MB/s, Time = %.5f s, Size = %u Bytes, NumDevsUsed = %u, Workgroup = %u\n", 
                (1.0e-6 * (double)byteCount / dAvgSecs), dAvgSecs, byteCount, 1, HISTOGRAM256_THREADBLOCK_SIZE); 
                
        shrLog("\nValidating GPU results...\n");
            shrLog(" ...reading back GPU results\n");
                cutilSafeCall( cudaMemcpy(h_HistogramGPU, d_Histogram, HISTOGRAM256_BIN_COUNT * sizeof(uint), cudaMemcpyDeviceToHost) );

            shrLog(" ...histogram256CPU()\n");
                histogram256CPU(
                    h_HistogramCPU,
                    h_Data,
                    byteCount
                );

            shrLog(" ...comparing the results\n");
                for(uint i = 0; i < HISTOGRAM256_BIN_COUNT; i++)
                    if(h_HistogramGPU[i] != h_HistogramCPU[i]) PassFailFlag = 0;
            shrLog(PassFailFlag ? " ...256-bin histograms match\n\n" : " ***256-bin histograms do not match!!!***\n\n" );

        shrLog("Shutting down 256-bin histogram...\n\n\n");
            closeHistogram256();
    }

    shrLog("Shutting down...\n");
        cutilCheckError(cutDeleteTimer(hTimer));
        cutilSafeCall( cudaFree(d_Histogram) );
        cutilSafeCall( cudaFree(d_Data) );
        free(h_HistogramGPU);
        free(h_HistogramCPU);
        free(h_Data);

    cutilDeviceReset();
	shrLog("%s - Test Summary\n", sSDKsample);
    // pass or fail (for both 64 bit and 256 bit histograms)
    shrQAFinishExit(argc, (const char **)argv, (PassFailFlag ? QA_PASSED : QA_FAILED));
}

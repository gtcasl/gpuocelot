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
 
#include <shrUtils.h>
#include <shrQATest.h>
#include <cutil_inline.h>
#include <cuda_runtime.h>
#include "scan_common.h"

int main(int argc, char **argv)
{
    shrQAStart(argc, argv);
	
    // Start logs
    shrSetLogFileName ("scan.txt");
    
    //Use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    uint *d_Input, *d_Output;
    uint *h_Input, *h_OutputCPU, *h_OutputGPU;
    uint hTimer;
    const uint N = 13 * 1048576 / 2;

    shrLog("Allocating and initializing host arrays...\n");
        cutCreateTimer(&hTimer);
        h_Input     = (uint *)malloc(N * sizeof(uint));
        h_OutputCPU = (uint *)malloc(N * sizeof(uint));
        h_OutputGPU = (uint *)malloc(N * sizeof(uint));
        srand(2009);
        for(uint i = 0; i < N; i++)
            h_Input[i] = rand();

    shrLog("Allocating and initializing CUDA arrays...\n");
        cutilSafeCall( cudaMalloc((void **)&d_Input, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_Output, N * sizeof(uint)) );
        cutilSafeCall( cudaMemcpy(d_Input, h_Input, N * sizeof(uint), cudaMemcpyHostToDevice) );

    shrLog("Initializing CUDA-C scan...\n\n");
        initScan();

    int globalFlag = 1;
    size_t szWorkgroup;
    const int iCycles = 100;
    shrLog("*** Running GPU scan for short arrays (%d identical iterations)...\n\n", iCycles);
        for(uint arrayLength = MIN_SHORT_ARRAY_SIZE; arrayLength <= MAX_SHORT_ARRAY_SIZE; arrayLength <<= 1){
            shrLog("Running scan for %u elements (%u arrays)...\n", arrayLength, N / arrayLength);
                cutilSafeCall( cutilDeviceSynchronize() );
                cutResetTimer(hTimer);
                cutStartTimer(hTimer);
                for(int i = 0; i < iCycles; i++)
                {
                    szWorkgroup = scanExclusiveShort(d_Output, d_Input, N / arrayLength, arrayLength);
                }
                cutilSafeCall( cutilDeviceSynchronize());
                cutStopTimer(hTimer);
                double timerValue = 1.0e-3 * cutGetTimerValue(hTimer) / iCycles;

            shrLog("Validating the results...\n");
                shrLog("...reading back GPU results\n");
                    cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, N * sizeof(uint), cudaMemcpyDeviceToHost) );

                shrLog(" ...scanExclusiveHost()\n");
                    scanExclusiveHost(h_OutputCPU, h_Input, N / arrayLength, arrayLength);

                // Compare GPU results with CPU results and accumulate error for this test
                shrLog(" ...comparing the results\n");
                    int localFlag = 1;
                    for(uint i = 0; i < N; i++)
                    {
                        if(h_OutputCPU[i] != h_OutputGPU[i])
                        {
                            localFlag = 0;
                            break;
                        }
                    }

                // Log message on individual test result, then accumulate to global flag
                shrLog(" ...Results %s\n\n", (localFlag == 1) ? "Match" : "DON'T Match !!!");
                globalFlag = globalFlag && localFlag;

                // Data log
                if (arrayLength == MAX_SHORT_ARRAY_SIZE)
                {
                    shrLog("\n");
                    shrLogEx(LOGBOTH | MASTER, 0, "scan-Short, Throughput = %.4f MElements/s, Time = %.5f s, Size = %u Elements, NumDevsUsed = %u, Workgroup = %u\n", 
                           (1.0e-6 * (double)arrayLength/timerValue), timerValue, arrayLength, 1, szWorkgroup);
                    shrLog("\n");
                }
        }

    shrLog("***Running GPU scan for large arrays (%u identical iterations)...\n\n", iCycles);
        for(uint arrayLength = MIN_LARGE_ARRAY_SIZE; arrayLength <= MAX_LARGE_ARRAY_SIZE; arrayLength <<= 1){
            shrLog("Running scan for %u elements (%u arrays)...\n", arrayLength, N / arrayLength);
                cutilSafeCall( cutilDeviceSynchronize() );
                cutResetTimer(hTimer);
                cutStartTimer(hTimer);
                for(int i = 0; i < iCycles; i++)
                {
                    szWorkgroup = scanExclusiveLarge(d_Output, d_Input, N / arrayLength, arrayLength);
                }
                cutilSafeCall( cutilDeviceSynchronize() );
                cutStopTimer(hTimer);
                double timerValue = 1.0e-3 * cutGetTimerValue(hTimer) / iCycles;

            shrLog("Validating the results...\n");
                shrLog("...reading back GPU results\n");
                    cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, N * sizeof(uint), cudaMemcpyDeviceToHost) );

                shrLog("...scanExclusiveHost()\n");
                    scanExclusiveHost(h_OutputCPU, h_Input, N / arrayLength, arrayLength);

                // Compare GPU results with CPU results and accumulate error for this test
                shrLog(" ...comparing the results\n");
                    int localFlag = 1;
                    for(uint i = 0; i < N; i++)
                    {
                        if(h_OutputCPU[i] != h_OutputGPU[i])
                        {
                            localFlag = 0;
                            break;
                        }
                    }

                // Log message on individual test result, then accumulate to global flag
                shrLog(" ...Results %s\n\n", (localFlag == 1) ? "Match" : "DON'T Match !!!");
                globalFlag = globalFlag && localFlag;

                // Data log
                if (arrayLength == MAX_LARGE_ARRAY_SIZE)
                {
                    shrLog("\n");
                    shrLogEx(LOGBOTH | MASTER, 0, "scan-Large, Throughput = %.4f MElements/s, Time = %.5f s, Size = %u Elements, NumDevsUsed = %u, Workgroup = %u\n", 
                           (1.0e-6 * (double)arrayLength/timerValue), timerValue, arrayLength, 1, szWorkgroup);
                    shrLog("\n");
                }
        }


    shrLog("Shutting down...\n");
        closeScan();
        cutilSafeCall( cudaFree(d_Output));
        cutilSafeCall( cudaFree(d_Input));

        cutilCheckError( cutDeleteTimer(hTimer) );

        cutilDeviceReset();
    // pass or fail (cumulative... all tests in the loop)
		shrQAFinishExit(argc, (const char**)argv, (globalFlag ? QA_PASSED : QA_FAILED));
}

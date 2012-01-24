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
 * This sample evaluates fair call price for a
 * given set of European options using Monte Carlo approach.
 * See supplied whitepaper for more explanations.
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <shrQATest.h>
#include <multithreading.h>
#include "MonteCarlo_common.h"

int *pArgc = NULL;
char **pArgv = NULL;


#ifdef WIN32
#define strcasecmp strcmpi
#endif


////////////////////////////////////////////////////////////////////////////////
// Common functions
////////////////////////////////////////////////////////////////////////////////
float randFloat(float low, float high){
    float t = (float)rand() / (float)RAND_MAX;
    return (1.0f - t) * low + t * high;
}



///////////////////////////////////////////////////////////////////////////////
// CPU reference functions
///////////////////////////////////////////////////////////////////////////////
extern "C" void MonteCarloCPU(
    TOptionValue&   callValue,
    TOptionData optionData,
    float *h_Random,
    int pathN
);

//Black-Scholes formula for call options
extern "C" void BlackScholesCall(
    float& CallResult,
    TOptionData optionData
);

extern "C" double NormalDistribution(unsigned int i, unsigned int pathN);
extern "C" double MoroInvCND(double prob);



////////////////////////////////////////////////////////////////////////////////
// GPU kernel code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void MonteCarlo_SM10(TOptionPlan *plan, cudaStream_t stream=0);
extern "C" void inverseCND_SM10(float *d_Output, unsigned int *d_Input, unsigned int N, cudaStream_t stream=0 );
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void MonteCarlo_SM13(TOptionPlan *plan, cudaStream_t stream=0);
extern "C" void inverseCND_SM13(float *d_Output, unsigned int *d_Input, unsigned int N, cudaStream_t stream=0 );



////////////////////////////////////////////////////////////////////////////////
// GPU-driving host thread
////////////////////////////////////////////////////////////////////////////////
unsigned int useDoublePrecision;
//Timer
const int MAX_GPU_COUNT = 8;
unsigned int hTimer[MAX_GPU_COUNT];

static CUT_THREADPROC solverThread(TOptionPlan *plan)
{
    //Init GPU
    cutilSafeCall( cudaSetDevice(plan->device) );

    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, plan->device));
    int version = deviceProp.major * 10 + deviceProp.minor;
    if(useDoublePrecision && version < 13){
        printf("Double precision is not supported on device %i: %s\n", plan->device, deviceProp.name);
        shrQAFinishExit(*pArgc, (const char **)pArgv, QA_PASSED);
    } else {
        printf("solverThread() starting - GPU Device %i: %s\n", plan->device, deviceProp.name);
    }

    //Allocate memory for normally distributed samples
    cutilSafeCall( cudaMalloc(
        (void **)&plan->d_Samples,
        plan->pathN * sizeof(float)
    ) );

    //Start the timer
    cutilCheckError( cutStartTimer(hTimer[plan->device]) );

    //Generate normally distributed samples
    if(useDoublePrecision)
        inverseCND_SM13(plan->d_Samples, NULL, plan->pathN);
    else
        inverseCND_SM10(plan->d_Samples, NULL, plan->pathN);

    //Allocate intermediate memory for MC integrator
    if(useDoublePrecision)
        initMonteCarlo_SM13(plan);
    else
        initMonteCarlo_SM10(plan);

    //Main computations
        if(useDoublePrecision)
            MonteCarlo_SM13(plan);
        else
            MonteCarlo_SM10(plan);
    cutilSafeCall( cutilDeviceSynchronize() );

	//Stop the timer
    cutilCheckError( cutStopTimer(hTimer[plan->device]) );

    //Shut down this GPU
    if(useDoublePrecision)
        closeMonteCarlo_SM13(plan);
    else
        closeMonteCarlo_SM10(plan);
    cutilSafeCall( cudaFree(plan->d_Samples) );

	cudaStreamSynchronize(0);

    printf("solverThread() finished - GPU Device %d: %s\n", plan->device, deviceProp.name );
    cutilDeviceReset();
    CUT_THREADEND;
}

static void multiSolver(TOptionPlan *plan, int nPlans ){

    // allocate and initialize an array of stream handles
    cudaStream_t *streams = (cudaStream_t*) malloc(nPlans * sizeof(cudaStream_t));
    cudaEvent_t *events = (cudaEvent_t*)malloc(nPlans * sizeof(cudaEvent_t));
    for(int i = 0; i < nPlans; i++) {
        cutilSafeCall( cudaSetDevice(plan[i].device) );
        cutilSafeCall( cudaStreamCreate(&(streams[i])) );
        cutilSafeCall( cudaEventCreate(&(events[i])) );
    }

    //Init Each GPU
    // In CUDA 4.0 we can call cudaSetDevice multiple times to target each device
    // Set the device desired, then perform initializations on that device
   
    for( int i=0 ; i<nPlans ; i++ )  {
        // set the target device to perform initialization on
        cutilSafeCall( cudaSetDevice(plan[i].device) );
    
        cudaDeviceProp deviceProp;
        cutilSafeCall(cudaGetDeviceProperties(&deviceProp, plan[i].device));
        int version = deviceProp.major * 10 + deviceProp.minor;
        if(useDoublePrecision && version < 13){
            printf("Double precision is not supported on device %i: %s\n", 
	           plan[i].device, deviceProp.name);
            exit(0);
        }
        //Allocate intermediate memory for MC integrator
        if(useDoublePrecision)
            initMonteCarlo_SM13(&plan[i]);
        else
            initMonteCarlo_SM10(&plan[i]);

        //Allocate memory for normally distributed samples
        cutilSafeCall( cudaMalloc(
            (void **)&plan[i].d_Samples,
            plan[i].pathN * sizeof(float)
        ) );

    }
    //Start the timer
    cutilCheckError( cutResetTimer(hTimer[0]) );
    cutilCheckError( cutStartTimer(hTimer[0]) );

    for( int i=0; i<nPlans; i++ ) {
        cutilSafeCall( cudaSetDevice(plan[i].device) );

        //Generate normally distributed samples
        if(useDoublePrecision)
            inverseCND_SM13(plan[i].d_Samples, NULL, plan[i].pathN, streams[i]);
        else
            inverseCND_SM10(plan[i].d_Samples, NULL, plan[i].pathN, streams[i]);

        //Main computations
        if(useDoublePrecision)
            MonteCarlo_SM13(&plan[i], streams[i]);
        else
            MonteCarlo_SM10(&plan[i], streams[i]);

        cutilSafeCall( cudaEventRecord( events[i] ) );

    }

    for( int i=0; i<nPlans; i++ ) {
        cutilSafeCall( cudaSetDevice(plan[i].device) );
        //cutilSafeCall( cutilDeviceSynchronize() );
        cudaEventSynchronize( events[i] );
    }
    //Stop the timer
    cutilCheckError( cutStopTimer(hTimer[0]) );

    for( int i=0 ; i<nPlans ; i++ ) {
        cutilSafeCall( cudaSetDevice(plan[i].device) );

        //Shut down this GPU
        if(useDoublePrecision)
            closeMonteCarlo_SM13(&plan[i]);
        else
            closeMonteCarlo_SM10(&plan[i]);
        cutilSafeCall( cudaFree(plan[i].d_Samples) );
    }
}



///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
#define DO_CPU
#undef DO_CPU

#define PRINT_RESULTS
#undef PRINT_RESULTS


void usage()
{
    printf("--type=[double,single] --method=[threaded,streamed] [--help]\n");
    printf("Method=threaded: 1 CPU thread for each GPU     (applies for CUDA 3.0 and older)\n");
    printf("       streamed: 1 CPU thread handles all GPUs (requires CUDA 4.0 or newer)\n");
}


int main(int argc, char **argv)
{
    char *precisionChoice;
    char *multiMethodChoice;
    bool use_threads = true;
    bool bqatest = false;

	pArgc = &argc;
	pArgv = argv;

    shrQAStart(argc, argv);

    if (cutCheckCmdLineFlag(argc, (const char **)argv, "qatest") ) {
        bqatest = true;
    }
    cutGetCmdLineArgumentstr(argc, (const char **)argv, "type", &precisionChoice);
    cutGetCmdLineArgumentstr(argc, (const char **)argv, "method", &multiMethodChoice);
    if( cutCheckCmdLineFlag( argc, (const char **)argv, "h") || cutCheckCmdLineFlag(argc, (const char **)argv, "help") ) {
        usage();
        exit(0);
    }
    if(precisionChoice == NULL)
        useDoublePrecision = 0;
    else{
        if(!strcasecmp(precisionChoice, "double"))
            useDoublePrecision = 1;
        else
            useDoublePrecision = 0;
    }

    if( multiMethodChoice == NULL ) {
        use_threads = true;
    } else {
        if(!strcasecmp(multiMethodChoice, "threaded"))
            use_threads = true;
        else
            use_threads = false;
    }
    if( use_threads == false ) { 
        printf("Using single CPU thread for multiple GPUs\n");
    }
    

    // determine runtime version
    int runtimeVersion;
    cudaRuntimeGetVersion( &runtimeVersion );

    const int         OPT_N = 256;
    const int        PATH_N = 1 << 18;
    const unsigned int SEED = 777;

    //Input data array
    TOptionData optionData[OPT_N];
    //Final GPU MC results
    TOptionValue callValueGPU[OPT_N];
    //"Theoretical" call values by Black-Scholes formula
    float callValueBS[OPT_N];
    //Solver config
    TOptionPlan optionSolver[MAX_GPU_COUNT];
    //OS thread ID
    CUTThread threadID[MAX_GPU_COUNT];


    //GPU number present in the system
    int GPU_N;
    int gpuBase, gpuIndex;
    int i;

    float time;

    double delta, ref, sumDelta, sumRef, sumReserve;

    cutilSafeCall( cudaGetDeviceCount(&GPU_N) );
    for( int i=0; i<GPU_N; i++ ) {
       cutilCheckError( cutCreateTimer(&hTimer[i]) );        
       cutilCheckError( cutResetTimer(hTimer[i]) );
    }

#ifdef _EMU
	GPU_N = 1;
#endif
    printf("main(): generating input data...\n");
        srand(123);
        for(i=0; i < OPT_N; i++){
            optionData[i].S = randFloat(5.0f, 50.0f);
            optionData[i].X = randFloat(10.0f, 25.0f);
            optionData[i].T = randFloat(1.0f, 5.0f);
            optionData[i].R = 0.06f;
            optionData[i].V = 0.10f;
            callValueGPU[i].Expected   = -1.0f;
            callValueGPU[i].Confidence = -1.0f;
        }

    printf("main(): starting %i host threads...\n", GPU_N);
        //Get option count for each GPU
        for(i = 0; i < GPU_N; i++)
            optionSolver[i].optionCount = OPT_N / GPU_N;
        //Take into account cases with "odd" option counts
        for(i = 0; i < (OPT_N % GPU_N); i++)
            optionSolver[i].optionCount++;

        //Assign GPU option ranges
        gpuBase = 0;
        for(i = 0; i < GPU_N; i++){
            optionSolver[i].device     = i;
            optionSolver[i].optionData = optionData   + gpuBase;
            optionSolver[i].callValue  = callValueGPU + gpuBase;
            optionSolver[i].seed       = SEED;
            optionSolver[i].pathN      = PATH_N;
            gpuBase += optionSolver[i].optionCount;
        }


    if( use_threads || bqatest ) {
        //Start CPU thread for each GPU
        for(gpuIndex = 0; gpuIndex < GPU_N; gpuIndex++)
            threadID[gpuIndex] = cutStartThread((CUT_THREADROUTINE)solverThread, &optionSolver[gpuIndex]);
        printf("main(): waiting for GPU results...\n");
        cutWaitForThreads(threadID, GPU_N);
        //Stop the timer


    printf("main(): GPU statistics, threaded\n");
        for(i = 0; i < GPU_N; i++){
            cudaDeviceProp deviceProp;
            cutilSafeCall(cudaGetDeviceProperties(&deviceProp, optionSolver[i].device));
            printf("GPU Device #%i: %s\n", optionSolver[i].device, deviceProp.name);
            printf("Options         : %i\n", optionSolver[i].optionCount);
            printf("Simulation paths: %i\n", optionSolver[i].pathN);
            time = cutGetTimerValue(hTimer[i]);
            printf("Total time (ms.): %f\n", time);
            printf("Options per sec.: %f\n", OPT_N / (time * 0.001));
        }

    printf("main(): comparing Monte Carlo and Black-Scholes results...\n");
        sumDelta   = 0;
        sumRef     = 0;
        sumReserve = 0;
        for(i = 0; i < OPT_N; i++){
            BlackScholesCall(
                callValueBS[i],
                optionData[i]
            );
            delta     = fabs(callValueBS[i] - callValueGPU[i].Expected);
            ref       = callValueBS[i];
            sumDelta += delta;
            sumRef   += fabs(ref);
            if(delta > 1e-6) sumReserve += callValueGPU[i].Confidence / delta;
#ifdef PRINT_RESULTS
            printf("BS: %f; delta: %E\n", callValueBS[i], delta);
#endif

        }
        sumReserve /= OPT_N;
    }

    if( !use_threads || bqatest )  
    {
        multiSolver( optionSolver, GPU_N );

        printf("main(): GPU statistics, streamed\n");
        for(i = 0; i < GPU_N; i++){
            cudaDeviceProp deviceProp;
            cutilSafeCall(cudaGetDeviceProperties(&deviceProp, optionSolver[i].device));
            printf("GPU Device #%i: %s\n", optionSolver[i].device, deviceProp.name);
            printf("Options         : %i\n", optionSolver[i].optionCount);
            printf("Simulation paths: %i\n", optionSolver[i].pathN);
        }
        time = cutGetTimerValue(hTimer[0]);
        printf("\nTotal time (ms.): %f\n", time);
        printf("\tNote: This is elapsed time for all to compute.\n");
        printf("Options per sec.: %f\n", OPT_N / (time * 0.001));

        printf("main(): comparing Monte Carlo and Black-Scholes results...\n");
        sumDelta   = 0;
        sumRef     = 0;
        sumReserve = 0;
        for(i = 0; i < OPT_N; i++){
            BlackScholesCall(
                callValueBS[i],
                optionData[i]
            );
            delta     = fabs(callValueBS[i] - callValueGPU[i].Expected);
            ref       = callValueBS[i];
            sumDelta += delta;
            sumRef   += fabs(ref);
            if(delta > 1e-6) sumReserve += callValueGPU[i].Confidence / delta;
#ifdef PRINT_RESULTS
            printf("BS: %f; delta: %E\n", callValueBS[i], delta);
#endif

        }
        sumReserve /= OPT_N;
    }


#ifdef DO_CPU
    printf("main(): running CPU MonteCarlo...\n");
        TOptionValue callValueCPU;
        sumDelta = 0;
        sumRef   = 0;
        for(i = 0; i < OPT_N; i++){
            MonteCarloCPU(
                callValueCPU,
                optionData[i],
                NULL,
                PATH_N
            );
            delta     = fabs(callValueCPU.Expected - callValueGPU[i].Expected);
            ref       = callValueCPU.Expected;
            sumDelta += delta;
            sumRef   += fabs(ref);
            printf("Exp : %f | %f\t", callValueCPU.Expected,   callValueGPU[i].Expected);
            printf("Conf: %f | %f\n", callValueCPU.Confidence, callValueGPU[i].Confidence);
        }
    printf("L1 norm: %E\n", sumDelta / sumRef);
#endif

    printf("Shutting down...\n");
	for( int i=0; i<GPU_N; i++ ) {	
		cutilCheckError( cutDeleteTimer(hTimer[i]) );
        cutilSafeCall( cudaSetDevice(i) );
        cutilDeviceReset();
    }

    printf("Test Summary...\n");
    printf("L1 norm        : %E\n", sumDelta / sumRef);
    printf("Average reserve: %f\n", sumReserve);
    shrQAFinishExit(argc, (const char **)argv, (sumReserve > 1.0f) ? QA_PASSED : QA_FAILED);
}

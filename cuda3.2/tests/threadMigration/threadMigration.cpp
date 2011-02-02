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

/******************************************************************************
*
*   Module: threadMigration.cpp
*
*   Description:
*     Simple sample demonstrating multi-GPU/multithread functionality using 
*     the CUDA Context Management API.  This API allows the a CUDA context to be
*     associated with a CPU process.  CUDA Contexts have a one-to-one correspondence 
*     with host threads.  A host thread may have only one device context current 
*     at a time.
*
*    Refer to the CUDA programming guide 4.5.3.3 on Context Management
*
******************************************************************************/

#define MAXTHREADS  256
#define NUM_INTS    32

#ifdef _WIN32
  // Windows threads use different data structures
  #include <windows.h>
  DWORD rgdwThreadIds[MAXTHREADS];
  HANDLE rghThreads[MAXTHREADS];
  CRITICAL_SECTION g_cs;

  #define ENTERCRITICALSECTION EnterCriticalSection(&g_cs);
  #define LEAVECRITICALSECTION LeaveCriticalSection(&g_cs);
  #define STRICMP stricmp
#else

  // Includes POSIX thread headers for Linux thread support
  #include <pthread.h>
  #include <stdint.h>
  pthread_t rghThreads[MAXTHREADS];
  pthread_mutex_t g_mutex;

  #define ENTERCRITICALSECTION pthread_mutex_lock(&g_mutex);
  #define LEAVECRITICALSECTION pthread_mutex_unlock(&g_mutex);
  #define STRICMP strcasecmp
#endif

#include <stdlib.h>
#include <stdio.h>
#include <cuda.h>
#include <cutil_inline.h>

#include <iostream>
#include <cstring>

using namespace std;

int NumThreads;
int ThreadLaunchCount;

typedef struct _CUDAContext_st {
    CUcontext   hcuContext;
    CUmodule    hcuModule;
    CUfunction  hcuFunction;
    CUdeviceptr dptr;
    int        	deviceID;
    int        	threadNum;
} CUDAContext;

CUDAContext g_ThreadParams[MAXTHREADS];

bool gbAutoQuit = false;

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
int runTest(int argc, char** argv);

#define CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status) \
    if ( dptr ) cuMemFree( dptr ); \
    if ( hcuModule ) cuModuleUnload( hcuModule ); \
    if ( hcuContext ) cuCtxDetach( hcuContext ); \
    return status;

#define THREAD_QUIT \
    printf("Error\n"); \
    return 0;

bool inline
findModulePath(const char * module_file, string & module_path, char **argv, string & ptx_source)
{
    module_path = cutFindFilePath(module_file, argv[0]);
    if (module_path.empty()) {
       printf("> findModulePath could not find file: <%s> \n", module_file); 
       return false;
    } else {
       printf("> findModulePath found file at <%s>\n", module_path.c_str());

	   if (module_path.rfind(".ptx") != string::npos) {
		   FILE *fp = fopen(module_path.c_str(), "rb");
		   fseek(fp, 0, SEEK_END);
		   int file_size = ftell(fp);
           char *buf = new char[file_size+1];
           fseek(fp, 0, SEEK_SET);
           fread(buf, sizeof(char), file_size, fp);
           fclose(fp);
           buf[file_size] = '\0';
           ptx_source = buf;
           delete[] buf;
	   }
       return true;
    }
}

// This sample uses the Driver API interface.  The CUDA context needs
// to be setup and the CUDA module (CUBIN) is built by NVCC
static CUresult
InitCUDAContext( CUDAContext *pContext, CUdevice hcuDevice, int deviceID, char **argv )
{
    CUcontext  hcuContext  = 0;
    CUmodule   hcuModule   = 0;
    CUfunction hcuFunction = 0;
    CUdeviceptr dptr       = 0;
    CUdevprop devProps;

    // cuCtxCreate: Function works on floating contexts and current context
    CUresult status = cuCtxCreate( &hcuContext, 0, hcuDevice );
    if ( CUDA_SUCCESS != status ) {
        fprintf( stderr, "cuCtxCreate for <Thread=%d> failed %d\n", 
		        pContext->threadNum, status );
        CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
    }
    status = CUDA_ERROR_INVALID_IMAGE;

    if ( CUDA_SUCCESS != cuDeviceGetProperties( &devProps, hcuDevice ) ) {
        printf("cuDeviceGetProperties FAILED\n");
        CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
    }

    string module_path, ptx_source;

    if (!findModulePath ("threadMigration.ptx", module_path, argv, ptx_source)) {
       if (!findModulePath ("threadMigration.cubin", module_path, argv, ptx_source)) {
          fprintf( stderr, "> findModulePath could not find <threadMigration> ptx or cubin\n");
          CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
       }
    }

	if (module_path.rfind(".ptx") != string::npos) {
		// in this branch we use compilation with parameters
		const unsigned int jitNumOptions = 3;
		CUjit_option *jitOptions = new CUjit_option[jitNumOptions];
		void **jitOptVals = new void*[jitNumOptions];

		// set up size of compilation log buffer
		jitOptions[0] = CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES;
		int jitLogBufferSize = 1024;
		jitOptVals[0] = (void *)(size_t)jitLogBufferSize;

		// set up pointer to the compilation log buffer
		jitOptions[1] = CU_JIT_INFO_LOG_BUFFER;
		char *jitLogBuffer = new char[jitLogBufferSize];
		jitOptVals[1] = jitLogBuffer;

		// set up pointer to set the Maximum # of registers for a particular kernel
		jitOptions[2] = CU_JIT_MAX_REGISTERS;
		int jitRegCount = 32;
		jitOptVals[2] = (void *)(size_t)jitRegCount;

		status = cuModuleLoadDataEx(&hcuModule, ptx_source.c_str(), jitNumOptions, jitOptions, (void **)jitOptVals);
		printf("> PTX JIT log:\n%s\n", jitLogBuffer);

	} else {
		status = cuModuleLoad(&hcuModule, module_path.c_str());
		if ( CUDA_SUCCESS != status ) {
			fprintf( stderr, "cuModuleLoad failed %d\n", status );
			CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
		}
	}

    status = cuModuleGetFunction( &hcuFunction, hcuModule, "kernelFunction" );
    if ( CUDA_SUCCESS != status ) {
        fprintf( stderr, "cuModuleGetFunction failed %d\n", status );
        CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
    }

    status = cuMemAlloc( &dptr, NUM_INTS*sizeof(int) );
    if ( CUDA_SUCCESS != status ) {
        fprintf( stderr, "cuMemAlloc failed %d\n", status );
        CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
    }
    
    // Here we must release the CUDA context from the thread context 
    status = cuCtxPopCurrent( NULL );
    if ( CUDA_SUCCESS != status ) {
        fprintf( stderr, "cuCtxPopCurrent failed %d\n", status );
        CLEANUP_ON_ERROR(dptr, hcuModule, hcuContext, status);
    }

    pContext->hcuContext  = hcuContext;
    pContext->hcuModule   = hcuModule;
    pContext->hcuFunction = hcuFunction;
    pContext->dptr        = dptr;
    pContext->deviceID    = deviceID;
	
    return CUDA_SUCCESS;
}



// ThreadProc launches the CUDA kernel on a CUDA context.  
// We have more than one thread that talks to a CUDA context
#ifdef _WIN32
  DWORD WINAPI ThreadProc(CUDAContext *pParams)
#else
  void* ThreadProc(CUDAContext *pParams)
#endif
{
    int wrong = 0;
    int *pInt = 0;

    printf( "<CUDA Device=%d, Context=%p, Thread=%d> - ThreadProc() Launched...\n",
		pParams->deviceID, pParams->hcuContext, pParams->threadNum );

    // cuCtxPushCurrent: Attach the caller CUDA context to the thread context. 
    CUresult status = cuCtxPushCurrent( pParams->hcuContext );
    if ( CUDA_SUCCESS != status ) {
        THREAD_QUIT;
    }

    int offset = 0;

    void *dptr = (void *)(size_t)pParams->dptr;
    ALIGN_OFFSET(offset, __alignof(dptr)); 
    cutilDrvSafeCall( cuParamSetv( pParams->hcuFunction, offset, &dptr, sizeof(dptr) ) );
	offset += sizeof(dptr);

    cutilDrvSafeCall( cuParamSetSize( pParams->hcuFunction, offset ) );

    cutilDrvSafeCall( cuFuncSetBlockShape( pParams->hcuFunction, 32, 1, 1 ) );
    // cuLaunch: we kick off the CUDA "kernelFunction"
    status = cuLaunch( pParams->hcuFunction );
    if ( CUDA_SUCCESS != status ) {
        fprintf( stderr, "cuLaunch failed %d\n", status );
        THREAD_QUIT;
    }
    pInt = (int *) malloc(NUM_INTS*sizeof(int));
    if ( ! pInt )
        return 0;
    if ( CUDA_SUCCESS == cuMemcpyDtoH( pInt, pParams->dptr, NUM_INTS*sizeof(int) ) ) {
        for ( int i = 0; i < NUM_INTS; i++ ) {
            if ( pInt[i] != 32-i ) {
                printf("<CUDA Device=%d, Context=%p, Thread=%d> error [%d]=%d!\n", 
                       pParams->deviceID, pParams->hcuContext, 
                       pParams->threadNum, i, pInt[i] );
                wrong++;
            }
        }
        ENTERCRITICALSECTION
        if ( ! wrong ) ThreadLaunchCount += 1;
        LEAVECRITICALSECTION
    }
    free( pInt );
    fflush( stdout );
    cuMemFree( pParams->dptr );

    // cuCtxPopCurrent: Detach the current CUDA context from the calling thread.
    cuCtxPopCurrent( NULL );

    printf( "<CUDA Device=%d, Context=%p, Thread=%d> - ThreadProc() Finished!\n\n", 
	    pParams->deviceID, pParams->hcuContext, pParams->threadNum );

    return 0;
}

int FinalErrorCheck(int ThreadIndex, int NumThreads, int deviceCount)
{
    if ( ThreadLaunchCount != NumThreads*deviceCount ) {
        printf( "<Expected=%d, Actual=%d> ThreadLaunchCounts(s)\n", 
                NumThreads*deviceCount, ThreadLaunchCount );
        printf( "\nFAILED\n" );
        return 1;
    }
    else {
        // destroy floating contexts while unattached to threads
        ThreadIndex = 0;
        for ( int iDevice = 0; iDevice < deviceCount; iDevice++ ) {
           for ( int iThread = 0; iThread < NumThreads; iThread++, ThreadIndex++ ) {
              // cuCtxDestroy called on current context or a floating context
              if ( CUDA_SUCCESS != cuCtxDestroy( g_ThreadParams[ThreadIndex].hcuContext ) )
                 return 1;
           }
        }
        printf( "\nPASSED\n" );
        return 0;
    }
    return 0;
}

int 
main(int argc, char **argv)
{
    runTest(argc, argv);

    if( gbAutoQuit ) {
        exit(0);
    } else {
        cutilExit(argc, argv);
    }
}

int
runTest(int argc, char **argv)
{
    printf("[ threadMigration ] API test...\n" );
#ifdef _WIN32
    InitializeCriticalSection( &g_cs );
#else
    pthread_mutex_init(&g_mutex, NULL);
#endif
    // By default, we will launch 2 CUDA threads for each device
    NumThreads = 2;

    if (argc > 1) {
        // If we are doing the QAtest or automated testing, we quit without prompting
        for (int i=1; i < argc; i++) {
            if (!STRICMP(argv[i], "-qatest") || !STRICMP(argv[i], "-noprompt")) {
                gbAutoQuit = true;
                continue;
            }
            cutGetCmdLineArgumenti(argc, (const char**) argv, "n", &NumThreads);
            if ( NumThreads < 1 || NumThreads > 15 ) {
                printf("Usage: \"threadMigration -n=<threads>\", <threads> ranges 1-15\n" );
                return 1;
            }
        }
    }

    int deviceCount;
    int hcuDevice = 0;
    CUresult status;
    status = cuInit(0);
    if ( CUDA_SUCCESS != status )
        return 1;
    status = cuDeviceGetCount( &deviceCount );
    if ( CUDA_SUCCESS != status )
        return 1;

	printf( "> %d CUDA device(s), %d Thread(s)/device to launched\n\n", deviceCount, NumThreads );
    if ( deviceCount == 0 ) {
       return 1;
    }

    int ihThread = 0;
    int ThreadIndex = 0;
    for ( int iDevice = 0; iDevice < deviceCount; iDevice++ ) {
        char szName[256];
        status = cuDeviceGet( &hcuDevice, iDevice );
        if ( CUDA_SUCCESS != status )
            return 1;

        status = cuDeviceGetName( szName, 256, hcuDevice );
        if ( CUDA_SUCCESS != status )
            return 1;

        CUdevprop devProps;
        if ( CUDA_SUCCESS == cuDeviceGetProperties( &devProps, hcuDevice ) ) {
			int major = 0, minor = 0;
			cutilDrvSafeCallNoSync( cuDeviceComputeCapability(&major, &minor, hcuDevice) );
            printf("Device %d: \"%s\" (Compute %d.%d)\n", iDevice, szName, major, minor );
            printf("\tsharedMemPerBlock: %d\n", devProps.sharedMemPerBlock );
            printf("\tconstantMemory   : %d\n", devProps.totalConstantMemory );
            printf("\tregsPerBlock     : %d\n", devProps.regsPerBlock );
            printf("\tclockRate        : %d\n", devProps.clockRate );
            printf("\n");
        }

        for ( int iThread = 0; iThread < NumThreads; iThread++, ihThread++ ) {
            g_ThreadParams[ThreadIndex].threadNum = iThread;

            if ( CUDA_SUCCESS != InitCUDAContext( &g_ThreadParams[ThreadIndex], 
                                                  hcuDevice, iDevice, argv ) )  
            {
               return FinalErrorCheck(ThreadIndex, NumThreads, deviceCount);
            }
            else 
            {
	// Launch (NumThreads) for each CUDA context
#ifdef _WIN32        
              rghThreads[ThreadIndex] = CreateThread( NULL, 0, 
                                                     (LPTHREAD_START_ROUTINE) ThreadProc, 
                                                      &g_ThreadParams[ThreadIndex], 
                                                      0, &rgdwThreadIds[ThreadIndex] );
#else	// Assume we are running linux
              pthread_create(&rghThreads[ThreadIndex], NULL, 
                             (void *(*)(void*)) ThreadProc, &g_ThreadParams[ThreadIndex]);
#endif
              ThreadIndex += 1;
            }
        }
    }

    // Wait until all workers are done
#ifdef _WIN32
     WaitForMultipleObjects(ThreadIndex, rghThreads, TRUE, INFINITE );
#else
     for ( int i = 0; i < ThreadIndex; i++ )
        pthread_join(rghThreads[i], NULL);
#endif

    return FinalErrorCheck(ThreadIndex, NumThreads, deviceCount);
}

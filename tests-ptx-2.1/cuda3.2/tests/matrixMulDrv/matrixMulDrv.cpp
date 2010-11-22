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

/* Matrix multiplication: C = A * B.
 * Host code.
 *
 * This sample implements matrix multiplication using the CUDA driver API.
 * It has been written for clarity of exposition to illustrate various CUDA
 * programming principles, not with the goal of providing the most
 * performant generic kernel for matrix multiplication.
 *
 * CUBLAS provides high-performance matrix multiplication.
 * See also:
 * V. Volkov and J. Demmel, "Benchmarking GPUs to tune dense linear algebra,"
 * in Proc. 2008 ACM/IEEE Conf. on Superconducting (SC '08),
 * Piscataway, NJ: IEEE Press, 2008, pp. Art. 31:1-11. 
 *
 */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <cstring>

// includes, CUDA
#include <cuda.h>

// includes, project
#include <cutil_inline.h>
#include "matrixMul.h"

#define USE_64BIT_MEMORY_ADDRESS 0

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest(int argc, char** argv);
void randomInit(float*, int);

extern "C"
void computeGold(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

static CUresult initCUDA(int argc, char **argv, CUfunction *pMatrixMul );

////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////
CUdevice cuDevice;
CUcontext cuContext;
CUmodule cuModule;
size_t totalGlobalMem;

static char *sSDKsample = "matrixMulDrv (Driver API)";

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main(int argc, char** argv)
{
    printf("[ %s ]\n", sSDKsample);

    runTest(argc, argv);

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest(int argc, char** argv)
{
    // initialize CUDA
    CUfunction matrixMul = NULL;
    cutilDrvSafeCallNoSync(initCUDA(argc, argv, &matrixMul ));

    // set seed for rand()
    srand(2006);

    // allocate host memory for matrices A and B
    unsigned int size_A = WA * HA;
    unsigned int mem_size_A = sizeof(float) * size_A;
    float* h_A = (float*) malloc(mem_size_A);
    unsigned int size_B = WB * HB;
    unsigned int mem_size_B = sizeof(float) * size_B;
    float* h_B = (float*) malloc(mem_size_B);

    // initialize host memory
    randomInit(h_A, size_A);
    randomInit(h_B, size_B);

	// First reserve about 4GB of memory, so we ensure that all memory allocated afterwards is > 4GB
#if USE_64BIT_MEMORY_ADDRESS
    CUdeviceptr d_Mem[4];
    unsigned int mem_size = 1024*1024*1024;
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_Mem[0], mem_size ));
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_Mem[1], mem_size ));
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_Mem[2], mem_size ));
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_Mem[3], mem_size ));
#endif

    // allocate device memory
    CUdeviceptr d_A;
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_A, mem_size_A ));
    CUdeviceptr d_B;
    cutilDrvSafeCallNoSync(cuMemAlloc( &d_B, mem_size_B )); 

    // copy host memory to device
    cutilDrvSafeCallNoSync(cuMemcpyHtoD( d_A, h_A, mem_size_A ));
    cutilDrvSafeCallNoSync(cuMemcpyHtoD( d_B, h_B, mem_size_B ));

    // allocate device memory for result
    size_t size_C = WC * HC;
    size_t mem_size_C = sizeof(float) * size_C;

    CUdeviceptr d_C;
    cutilDrvSafeCallNoSync(cuMemAlloc(&d_C, mem_size_C));
    
    // allocate mem for the result on host side
    float* h_C = (float*) malloc(mem_size_C);

    // create and start timer
    unsigned int timer = 0;
    cutilCheckError(cutCreateTimer(&timer));
  
    // start the timer 
    cutilCheckError(cutStartTimer(timer));

    // setup execution parameters
    int offset = 0;

	{
		// If we are building for CUDA 3.1 toolkit, we will need to perform the pointer casting
		cutilDrvSafeCallNoSync(cuParamSetv( matrixMul, offset, &d_C, sizeof(d_C)));
		offset += sizeof(d_C);

		cutilDrvSafeCallNoSync(cuParamSetv( matrixMul, offset, &d_A, sizeof(d_A)));
		offset += sizeof(d_A);

		cutilDrvSafeCallNoSync(cuParamSetv( matrixMul, offset, &d_B, sizeof(d_B)));
		offset += sizeof(d_B);
	}

#if USE_64BIT_MEMORY_ADDRESS
	if (totalGlobalMem > (unsigned long long)4*1024*1024*1024L) {
		size_t Matrix_Width_A = (size_t)WA;
		size_t Matrix_Width_B = (size_t)WB;

		offset = (offset + __alignof(Matrix_Width_A) - 1) & ~(__alignof(Matrix_Width_A) - 1); // adjust offset alignment requirements
		cutilDrvSafeCallNoSync(cuParamSeti( matrixMul, offset, &Matrix_Width_A, sizeof(Matrix_Width_A) )); offset += sizeof(Matrix_Width_A);

		offset = (offset + __alignof(Matrix_Width_B) - 1) & ~(__alignof(Matrix_Width_B) - 1); // adjust offset alignment requirements
		cutilDrvSafeCallNoSync(cuParamSeti( matrixMul, offset, &Matrix_Width_B, sizeof(Matrix_Width_B) )); offset += sizeof(Matrix_Width_B);
	} else 
#endif
	{
		int Matrix_Width_A = WA;
		int Matrix_Width_B = WB;

		offset = (offset + __alignof(Matrix_Width_A) - 1) & ~(__alignof(Matrix_Width_A) - 1); // adjust offset alignment requirements
		cutilDrvSafeCallNoSync(cuParamSeti( matrixMul, offset, Matrix_Width_A )); offset += sizeof(Matrix_Width_A);

		offset = (offset + __alignof(Matrix_Width_B) - 1) & ~(__alignof(Matrix_Width_B) - 1); // adjust offset alignment requirements
		cutilDrvSafeCallNoSync(cuParamSeti( matrixMul, offset, Matrix_Width_B )); offset += sizeof(Matrix_Width_B);
	}

    cutilDrvSafeCallNoSync(cuParamSetSize( matrixMul, offset ));
    cutilDrvSafeCallNoSync(cuFuncSetBlockShape( matrixMul, BLOCK_SIZE, BLOCK_SIZE, 1 ));
    cutilDrvSafeCallNoSync(cuFuncSetSharedSize( matrixMul, 2*BLOCK_SIZE*BLOCK_SIZE*sizeof(float) ) );

    // set execution configuration for the CUDA kernel
    cutilDrvSafeCallNoSync(cuLaunchGrid( matrixMul, WC / BLOCK_SIZE, HC / BLOCK_SIZE ));

    // copy result from device to host
    cutilDrvSafeCallNoSync(cuMemcpyDtoH((void *) h_C, d_C, mem_size_C) );

    // stop and destroy timer
    cutilCheckError(cutStopTimer(timer));
    printf("Processing time: %f (ms)\n", cutGetTimerValue(timer));
    cutilCheckError(cutDeleteTimer(timer));

    // compute reference solution
    float* reference = (float*) malloc(mem_size_C);
    computeGold(reference, h_A, h_B, HA, WA, WB);

    // check result
    CUTBoolean res = cutCompareL2fe(reference, h_C, size_C, 1e-6f);
    printf("%s\n", (1 == res) ? "PASSED" : "FAILED");

    // clean up memory
#if USE_64BIT_MEMORY_ADDRESS
	cuMemFree(d_Mem[0]);
	cuMemFree(d_Mem[1]);
	cuMemFree(d_Mem[2]);
	cuMemFree(d_Mem[3]);
#endif

	free(h_A);
    free(h_B);
    free(h_C);
    free(reference);
    cutilDrvSafeCallNoSync(cuMemFree(d_A));
    cutilDrvSafeCallNoSync(cuMemFree(d_B));
    cutilDrvSafeCallNoSync(cuMemFree(d_C));
    cutilDrvSafeCallNoSync(cuCtxDetach(cuContext));
}

// Allocates a matrix with random float entries.
void randomInit(float* data, int size)
{
    for (int i = 0; i < size; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

bool inline
findModulePath(const char * module_file, string & module_path, char **argv, string & ptx_source)
{
    module_path = cutFindFilePath(module_file, argv[0]);
    if (module_path.empty()) {
       printf("> findModulePath file not found: <%s> \n", module_file); 
       return false;
    } else {
       printf("> findModulePath <%s>\n", module_path.c_str());

       if (module_path.rfind(".ptx") != string::npos) 
       {
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

static CUresult
initCUDA(int argc, char **argv, CUfunction *pMatrixMul )
{
    CUfunction cuFunction = 0;
    CUresult status;
    int major = 0, minor = 0, devID = 0;
    char deviceName[100];
    string module_path, ptx_source;

    cuDevice = cutilChooseCudaDeviceDrv(argc, argv, &devID);

    // get compute capabilities and the devicename
    cutilDrvSafeCallNoSync( cuDeviceComputeCapability(&major, &minor, cuDevice) );
    cutilDrvSafeCallNoSync( cuDeviceGetName(deviceName, 256, cuDevice) );
    printf("> GPU Device has SM %d.%d compute capability\n", major, minor);

    CU_SAFE_CALL_NO_SYNC( cuDeviceTotalMem(&totalGlobalMem, cuDevice) );
    printf("  Total amount of global memory:     %llu bytes\n", (unsigned long long)totalGlobalMem);
    printf("  64-bit Memory Address:             %s\n", (totalGlobalMem > (unsigned long long)4*1024*1024*1024L) ? "YES" : "NO");

    status = cuCtxCreate( &cuContext, 0, cuDevice );
    if ( CUDA_SUCCESS != status )
        goto Error;

    // first search for the module path before we load the results
    if (!findModulePath ("matrixMul_kernel.ptx", module_path, argv, ptx_source)) {
       if (!findModulePath ("matrixMul_kernel.cubin", module_path, argv, ptx_source)) {
           printf("> findModulePath could not find <matrixMul_kernel> ptx or cubin\n");
           status = CUDA_ERROR_NOT_FOUND;
           goto Error;
       }
    } else {
       printf("> initCUDA loading module: <%s>\n", module_path.c_str());
    }

	if (module_path.rfind("ptx") != string::npos) {
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

		status = cuModuleLoadDataEx(&cuModule, ptx_source.c_str(), jitNumOptions, jitOptions, (void **)jitOptVals);

		printf("> PTX JIT log:\n%s\n", jitLogBuffer);
	} else {
		status = cuModuleLoad(&cuModule, module_path.c_str());
	}

    if ( CUDA_SUCCESS != status ) {
        goto Error;
    }

#if USE_64BIT_MEMORY_ADDRESS
    if (totalGlobalMem > (unsigned long long)4*1024*1024*1024L) {
		status = cuModuleGetFunction( &cuFunction, cuModule, "matrixMul_64bit" );
	} else 
#endif
	{
		status = cuModuleGetFunction( &cuFunction, cuModule, "matrixMul" );
	}
    if ( CUDA_SUCCESS != status )
        goto Error;
	*pMatrixMul = cuFunction;
	
    return CUDA_SUCCESS;
Error:
	cuCtxDetach(cuContext);
    return status;
}



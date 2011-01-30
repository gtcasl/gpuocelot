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
 * This sample revisits matrix multiplication with CUDA task. The code of matrix
 * multiplication is exactly the same as in matrixMulDrv sample of this SDK. 
 * This sample, however, demonstrates how to link CUDA driver at runtime and 
 * how to perform JIT (just-in-time) compilation of CUDA kernel from PTX image,
 * stored in memory.
 * 
 * For more details on acquiring auto-generated sources refer README.TXT file 
 * in "extras" directory.
 *
 * Unlike CUBLAS, the sample doesn't address high-performance matrix 
 * multiplication. 
 */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, CUDA
#include "cuda_drvapi_dynlink.h"
#include "cutil_short.h"

// includes, project
#include "matrixMul.h"
#include "matrixMul_ptxdump.h"

extern "C" void computeGold(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

#if defined _MSC_VER
    #pragma warning (disable : 4312)
#endif


////////////////////////////////////////////////////////////////////////////////
// Globals
////////////////////////////////////////////////////////////////////////////////
CUcontext g_cuContext;
bool noprompt = false;

static const char *sSDKsample = "matrixMulDynlinkJIT (CUDA dynamic linking)";


////////////////////////////////////////////////////////////////////////////////
// Allocates a matrix with random float entries
////////////////////////////////////////////////////////////////////////////////
void randomInit(float* data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = rand() / (float)RAND_MAX;
    }
}

////////////////////////////////////////////////////////////////////////////////
// CUDA driver runtime linking and initialization
////////////////////////////////////////////////////////////////////////////////
CUresult initCUDA(int argc, char **argv, CUfunction *pMatrixMul)
{
    CUresult status;
    CUdevice cuDevice;
    CUmodule cuModule;
    CUfunction cuFunction;
    int major, minor, devID = 0;
    char deviceName[256];

	// link to cuda driver dynamically 
    status = cuInit(0);
    if (CUDA_SUCCESS != status) 
    {
        fprintf(stderr, "Fatal error dynamically loading the CUDA driver\n");
        exit(-1);
    }

	// This assumes that the user is attempting to specify a explicit device -device=n
	if (argc > 1) {
		bool bFound = false;
		for (int param=0; param < argc; param++) {
			if (!strncmp(argv[param], "-device", 7)) {
				int i=strlen(argv[1]);
				while (argv[1][i] != '=') 
				{
					i--;
				}
				devID = atoi(&argv[1][++i]);
				bFound = true;
			}
			if (bFound) 
				break;
		}
	}

	// get cuda-capable device count
    int deviceCount = 0;
    cutilDrvSafeCallNoSync(cuDeviceGetCount(&deviceCount));
    if (deviceCount == 0) 
    {
        fprintf(stderr, "Fatal error: no devices supporting CUDA\n");
        exit(-1);
    }
	if (devID < 0) devID = 0;
	if (devID > deviceCount -1) {
           fprintf(stderr, "initCUDA (Device=%d) invalid GPU device.  %d GPU device(s) detected.\n\n", devID, deviceCount);
           status = CUDA_ERROR_NOT_FOUND;
           goto Error;
	}

    // pick up device with zero ordinal (default, or devID)
    cutilDrvSafeCallNoSync(cuDeviceGet(&cuDevice, devID));

	// get compute capabilities and the devicename
	cutilDrvSafeCallNoSync( cuDeviceComputeCapability(&major, &minor, cuDevice) );
	cutilDrvSafeCallNoSync( cuDeviceGetName(deviceName, 256, cuDevice) );
	printf("> Device %d: \"%s\" with Compute %d.%d capability\n", cuDevice, deviceName, major, minor);

    // create context for picked device
    status = cuCtxCreate(&g_cuContext, 0, cuDevice);
    if (CUDA_SUCCESS != status)
    {
        goto Error;
    }

    // setup JIT compilation options and perform compilation
    {
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

        // compile with set parameters
        printf("> Compiling CUDA module\n");
        status = cuModuleLoadDataEx(&cuModule, matrixMul_ptxdump, jitNumOptions, jitOptions, (void **)jitOptVals);

        printf("> PTX JIT log:\n%s\n", jitLogBuffer);
        
        delete [] jitOptions;
        delete [] jitOptVals;
        delete [] jitLogBuffer;
    }

    if (CUDA_SUCCESS != status) 
    {
        printf ("Error while compiling PTX\n");
        goto Error;
    }

    // retrieve CUDA function from the compiled module
    status = cuModuleGetFunction(&cuFunction, cuModule, "matrixMul");
    if (CUDA_SUCCESS != status)
    {
        goto Error;
    }

    *pMatrixMul = cuFunction;
    return CUDA_SUCCESS;

Error:
    cuCtxDetach(g_cuContext);
    exit(0);
    return status;
}


////////////////////////////////////////////////////////////////////////////////
// Entry point
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    printf("[ %s ]\n", sSDKsample);

    // initialize CUDA
    CUfunction matrixMul = NULL;
    cutilDrvSafeCallNoSync(initCUDA(argc, argv, &matrixMul));

    // set seed for rand()
    srand(2006);

    // allocate host memory for matrices A and B
    size_t       size_A = WA * HA;
    size_t       mem_size_A = sizeof(float) * size_A;
	size_t       size_B = WB * HB;
    size_t       mem_size_B = sizeof(float) * size_B;

	float* h_A = (float*) malloc(mem_size_A);
    float* h_B = (float*) malloc(mem_size_B);

    // initialize host memory
    randomInit(h_A, size_A);
    randomInit(h_B, size_B);

    // allocate device memory
    CUdeviceptr d_A;
    cutilDrvSafeCallSync(cuMemAlloc(&d_A, mem_size_A));
    CUdeviceptr d_B;
    cutilDrvSafeCallSync(cuMemAlloc(&d_B, mem_size_B)); 

    // copy host memory to device
    cutilDrvSafeCallSync(cuMemcpyHtoD(d_A, h_A, mem_size_A));
    cutilDrvSafeCallSync(cuMemcpyHtoD(d_B, h_B, mem_size_B));

    // allocate device memory for result
	size_t       size_C = WC * HC;
    size_t       mem_size_C = sizeof(float) * size_C;

    CUdeviceptr d_C;
    cutilDrvSafeCallSync(cuMemAlloc(&d_C, mem_size_C));

    // allocate mem for the result on host side
    float* h_C = (float*) malloc(mem_size_C);

	int offset = 0;
	{
		// setup execution parameters
		cutilDrvSafeCallNoSync(cuParamSetv(matrixMul, offset, &d_C, sizeof(d_C)));
		offset += sizeof(d_C);

		cutilDrvSafeCallNoSync(cuParamSetv(matrixMul, offset, &d_A, sizeof(d_A)));
		offset += sizeof(d_A);

		cutilDrvSafeCallNoSync(cuParamSetv(matrixMul, offset, &d_B, sizeof(d_B)));
		offset += sizeof(d_B);
	}

    int Matrix_Width_A = WA;
    int Matrix_Width_B = WB;

    cutilDrvSafeCallNoSync(cuParamSeti(matrixMul, offset, Matrix_Width_A)); 
    offset += sizeof(Matrix_Width_A);

    cutilDrvSafeCallNoSync(cuParamSeti(matrixMul, offset, Matrix_Width_B)); 
    offset += sizeof(Matrix_Width_B);

    cutilDrvSafeCallNoSync(cuParamSetSize(matrixMul, offset));
    cutilDrvSafeCallNoSync(cuFuncSetBlockShape(matrixMul, BLOCK_SIZE, BLOCK_SIZE, 1));
    cutilDrvSafeCallNoSync(cuFuncSetSharedSize(matrixMul, 2*BLOCK_SIZE*BLOCK_SIZE*sizeof(float)));

    // set execution configuration for the CUDA kernel
    cutilDrvSafeCallSync(cuLaunchGrid(matrixMul, WC / BLOCK_SIZE, HC / BLOCK_SIZE));

    // copy result from device to host
    cutilDrvSafeCallSync(cuMemcpyDtoH((void *) h_C, d_C, mem_size_C));

    // compute reference solution
    float* reference = (float*) malloc(mem_size_C);
    computeGold(reference, h_A, h_B, HA, WA, WB);

    // check result
    float diff=0.0f;
    for (unsigned int i=0; i<size_C; i++)
    {
        float tmp = reference[i] - h_C[i];
        diff += tmp*tmp;
    }

    int res = (diff / (float)size_C < 1e-6f);
    printf("%s\n", (1 == res) ? "PASSED" : "FAILED");

    // clean up memory
	free(h_A);
    free(h_B);
    free(h_C);
    free(reference);
    cutilDrvSafeCallSync(cuMemFree(d_A));
    cutilDrvSafeCallSync(cuMemFree(d_B));
    cutilDrvSafeCallSync(cuMemFree(d_C));
    cutilDrvSafeCallNoSync(cuCtxDetach(g_cuContext));

    cutilExit();
}

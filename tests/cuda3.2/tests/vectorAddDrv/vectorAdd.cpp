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

/* Vector addition: C = A + B.
 *
 * This sample is a very basic sample that implements element by element
 * vector addition. It is the same as the sample illustrating Chapter 3
 * of the programming guide with some additions like error checking.
 *
 */

// Includes
#include <stdio.h>
#include <string.h>
#include <cuda.h>
#include <cutil_inline.h>

#include <iostream>
#include <cstring>

using namespace std;

// Variables
CUdevice cuDevice;
CUcontext cuContext;
CUmodule cuModule;
CUfunction vecAdd;
float* h_A;
float* h_B;
float* h_C;
CUdeviceptr d_A;
CUdeviceptr d_B;
CUdeviceptr d_C;
bool noprompt = false;

// Functions
void Cleanup(bool);
CUresult CleanupNoFailure();
void RandomInit(float*, int);
bool findModulePath(const char*, string &, char**, string &);
void ParseArguments(int, char**);

// Host code
int main(int argc, char** argv)
{
    printf("Vector Addition (Driver API)\n");
    int N = 50000, devID = 0;
    size_t       size = N * sizeof(float);

	CUresult error;
    ParseArguments(argc, argv);

    // Initialize
    error = cuInit(0);
    if (error != CUDA_SUCCESS) Cleanup(false);

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

    // Get number of devices supporting CUDA
    int deviceCount = 0;
    error = cuDeviceGetCount(&deviceCount);
    if (error != CUDA_SUCCESS) Cleanup(false);
    if (deviceCount == 0) {
        printf("There is no device supporting CUDA.\n");
        Cleanup(false);
    }
	if (devID < 0) devID = 0;
	if (devID > deviceCount-1) {
		fprintf(stderr, "(Device=%d) invalid GPU device.  %d GPU device(s) detected.\nexiting...\n", devID, deviceCount);
		CleanupNoFailure();
		exit(0);
	} else {
		int major, minor;
		char deviceName[100];
		cutilDrvSafeCallNoSync( cuDeviceComputeCapability(&major, &minor, devID) );
		cutilDrvSafeCallNoSync( cuDeviceGetName(deviceName, 256, devID) );
		printf("> Using Device %d: \"%s\" with Compute %d.%d capability\n", devID, deviceName, major, minor);
	}

    // pick up device with zero ordinal (default, or devID)
    error = cuDeviceGet(&cuDevice, devID);
    if (error != CUDA_SUCCESS) Cleanup(false);

    // Create context
    error = cuCtxCreate(&cuContext, 0, cuDevice);
    if (error != CUDA_SUCCESS) Cleanup(false);

    // first search for the module path before we load the results
    string module_path, ptx_source;

    if (!findModulePath ("vectorAdd.ptx", module_path, argv, ptx_source)) {
       if (!findModulePath ("vectorAdd.cubin", module_path, argv, ptx_source)) {
           printf("> findModulePath could not find <vectorAdd> ptx or cubin\n");
           Cleanup(false);
       }
    }
	else {
       printf("> initCUDA loading module: <%s>\n", module_path.c_str());
	}

    // Create module from binary file (PTX or CUBIN)
	if (module_path.rfind("ptx") != string::npos) 
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

		error = cuModuleLoadDataEx(&cuModule, ptx_source.c_str(), jitNumOptions, jitOptions, (void **)jitOptVals);

		printf("> PTX JIT log:\n%s\n", jitLogBuffer);
	} else {
		error = cuModuleLoad(&cuModule, module_path.c_str());
	}
    if (error != CUDA_SUCCESS) Cleanup(false);

    // Get function handle from module
    error = cuModuleGetFunction(&vecAdd, cuModule, "VecAdd");
    if (error != CUDA_SUCCESS) Cleanup(false);

    // Allocate input vectors h_A and h_B in host memory
    h_A = (float*)malloc(size);
    if (h_A == 0) Cleanup(false);
    h_B = (float*)malloc(size);
    if (h_B == 0) Cleanup(false);
    h_C = (float*)malloc(size);
    if (h_C == 0) Cleanup(false);
    
    // Initialize input vectors
    RandomInit(h_A, N);
    RandomInit(h_B, N);

    // Allocate vectors in device memory
    error = cuMemAlloc(&d_A, size);
    if (error != CUDA_SUCCESS) Cleanup(false);
    error = cuMemAlloc(&d_B, size);
    if (error != CUDA_SUCCESS) Cleanup(false);
    error = cuMemAlloc(&d_C, size);
    if (error != CUDA_SUCCESS) Cleanup(false);

    // Copy vectors from host memory to device memory
    error = cuMemcpyHtoD(d_A, h_A, size);
    if (error != CUDA_SUCCESS) Cleanup(false);
    error = cuMemcpyHtoD(d_B, h_B, size);
    if (error != CUDA_SUCCESS) Cleanup(false);

    // Invoke kernel
    #define ALIGN_UP(offset, alignment) \
        (offset) = ((offset) + (alignment) - 1) & ~((alignment) - 1)
    int offset = 0;

    error = cuParamSetv(vecAdd, offset, &d_A, sizeof(d_A));
    if (error != CUDA_SUCCESS) Cleanup(false);
    offset += sizeof(d_A);
    error = cuParamSetv(vecAdd, offset, &d_B, sizeof(d_B));
    if (error != CUDA_SUCCESS) Cleanup(false);
    offset += sizeof(d_B);
    error = cuParamSetv(vecAdd, offset, &d_C, sizeof(d_C));
    if (error != CUDA_SUCCESS) Cleanup(false);
    offset += sizeof(d_C);

    ALIGN_UP(offset, __alignof(N));
    error = cuParamSeti(vecAdd, offset, N);
    if (error != CUDA_SUCCESS) Cleanup(false);
    offset += sizeof(N);
    error = cuParamSetSize(vecAdd, offset);
    if (error != CUDA_SUCCESS) Cleanup(false);
    int threadsPerBlock = 256;
    int blocksPerGrid = 
        (N + threadsPerBlock - 1) / threadsPerBlock;
    error = cuFuncSetBlockShape(vecAdd, threadsPerBlock, 1, 1);
    if (error != CUDA_SUCCESS) Cleanup(false);
    error = cuLaunchGrid(vecAdd, blocksPerGrid, 1);
    if (error != CUDA_SUCCESS) Cleanup(false);

#ifdef _DEBUG
    error = cuCtxSynchronize();
    if (error != CUDA_SUCCESS) Cleanup(false);
#endif

    // Copy result from device memory to host memory
    // h_C contains the result in host memory
    error = cuMemcpyDtoH(h_C, d_C, size);
    if (error != CUDA_SUCCESS) Cleanup(false);
    
    // Verify result
    int i;
    for (i = 0; i < N; ++i) {
        float sum = h_A[i] + h_B[i];
        if (fabs(h_C[i] - sum) > 1e-7f)
            break;
    }
    printf("%s \n", (i == N) ? "PASSED" : "FAILED");
    
    Cleanup(true);
}

CUresult CleanupNoFailure()
{
	CUresult error;
        
    // Free device memory
    if (d_A)
        error = cuMemFree(d_A);
    if (d_B)
        error = cuMemFree(d_B);
    if (d_C)
        error = cuMemFree(d_C);

    // Free host memory
    if (h_A)
        free(h_A);
    if (h_B)
        free(h_B);
    if (h_C)
        free(h_C);
        
    error = cuCtxDetach(cuContext);

	return error;
}

void Cleanup(bool noError)
{
    CUresult error;
	error = CleanupNoFailure();

    if (!noError || error != CUDA_SUCCESS)
        printf("Function call failed\nFAILED\n");
    
    if (!noprompt) {
        printf("\nPress ENTER to exit...\n");
        fflush( stdout);
        fflush( stderr);
        getchar();
    }

    exit(0);
}



// Allocates an array with random float entries.
void RandomInit(float* data, int n)
{
    for (int i = 0; i < n; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

bool inline
findModulePath(const char *module_file, string & module_path, char **argv, string & ptx_source)
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

// Parse program arguments
void ParseArguments(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
        if (strcmp(argv[i], "--noprompt") == 0 ||
			strcmp(argv[i], "-noprompt") == 0) 
		{
            noprompt = true;
            break;
        }
}

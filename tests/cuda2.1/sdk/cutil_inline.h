#ifndef _CUTIL_INLINE_H_
#define _CUTIL_INLINE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cuda.h>
#include <cutil.h>
#include <cufft.h>
#include <cuda_runtime_api.h>


// We define these calls here, so the user doesn't need to include __FILE__ and __LINE__
// The advantage is the developers gets to use the inline function so they can debug
#define cutilDrvSafeCallNoSync(err)  __cuSafeCallNoSync  (err, __FILE__, __LINE__)
#define cutilDrvSafeCall(err)        __cuSafeCall        (err, __FILE__, __LINE__)
#define cutilDrvCtxSync()            __cuCtxSync         (__FILE__, __LINE__)
#define cutilSafeCallNoSync(err)     __cudaSafeCallNoSync(err, __FILE__, __LINE__)
#define cutilSafeCall(err)           __cudaSafeCall      (err, __FILE__, __LINE__)
#define cutilSafeThreadSync()        __cudaSafeThreadSync(__FILE__, __LINE__)
#define cufftSafeCall(err)           __cufftSafeCall     (err, __FILE__, __LINE__)
#define cutilCheckError(err)         __cutilCheckError   (err, __FILE__, __LINE__)
#define cutilCheckMsg(msg)           __cutilCheckMsg     (msg, __FILE__, __LINE__)
#define cutilSafeMalloc(mallocCall)  __cutilSafeMalloc   ((mallocCall), __FILE__, __LINE__)
#define cutilCondition(val)          __cutilCondition    (val, __FILE__, __LINE__)
#define cutilExit(argc, argv)        __cutilExit         (argc, argv)

#ifdef _DEBUG
   #if __DEVICE_EMULATION__
      #define cutilBankChecker(array, idx) (__cutilBankChecker (threadIdx.x, threadIdx.y, threadIdx.z, \
                                                               blockDim.x, blockDim.y, blockDim.z, \
                                                               #array, idx, __FILE__, __LINE__), \
                                                               array[idx])

   #else
      #define cutilBankChecker(array, idx) array[idx] 
   #endif
#else
      #define cutilBankChecker(array, idx) array[idx]
#endif

    // Interface for bank conflict checker
inline void __cutilBankChecker(unsigned int tidx, unsigned int tidy, unsigned int tidz,
                            unsigned int bdimx, unsigned int bdimy, unsigned int bdimz,
                            char *aname, int index, char *file, int line) 
{
    cutCheckBankAccess( tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
}

inline void __cutilCondition(int val, char *file, int line) 
{
    if( CUTFalse == cutCheckCondition( val, file, line ) ) {
        exit(EXIT_FAILURE);
    }
}

inline void __cutilExit(int argc, char **argv)
{
    if (!cutCheckCmdLineFlag(argc, (const char**)argv, "noprompt")) {
        printf("\nPress ENTER to exit...\n");
        fflush( stdout);
        fflush( stderr);
        getchar();
    }
    exit(EXIT_SUCCESS);
}



// This function returns the best GPU (with maximum GFLOPS)
inline int cutGetMaxGflopsDeviceId()
{
	int device_count = 0;
	cudaGetDeviceCount( &device_count );

	cudaDeviceProp device_properties;
	int max_gflops_device = 0;
	int max_gflops = 0;
	
	int current_device = 0;
	cudaGetDeviceProperties( &device_properties, current_device );
	max_gflops = device_properties.multiProcessorCount * device_properties.clockRate;
	++current_device;

	while( current_device < device_count )
	{
		cudaGetDeviceProperties( &device_properties, current_device );
		int gflops = device_properties.multiProcessorCount * device_properties.clockRate;
		if( gflops > max_gflops )
		{
			max_gflops        = gflops;
			max_gflops_device = current_device;
		}
		++current_device;
	}

	return max_gflops_device;
}

// These are the inline versions for all of the CUTIL functions
inline void __cuSafeCallNoSync( CUresult err, const char *file, const int line )
{
    do {
        if( CUDA_SUCCESS != err) {
            fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n",
                    err, file, line );
            exit(-1);
        }
    } while (0);
}
inline void __cuSafeCall( CUresult err, const char *file, const int line )
{
    __cuSafeCallNoSync( err, file, line );
}

inline void __cuCtxSync(const char *file, const int line )
{
    do {
        CUresult err = cuCtxSynchronize();
        if( CUDA_SUCCESS != err ) {
            fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n",
                    err, file, line );
            exit(-1);
        }
    } while (0);
}

inline void __cudaSafeCallNoSync( cudaError err, const char *file, const int line )
{
    do {
        if( cudaSuccess != err) {
            fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n",
                    file, line, cudaGetErrorString( err) );
            exit(-1);
        }
    } while (0);
}

inline void __cudaSafeCall( cudaError err, const char *file, const int line )
{
    do {
        if( cudaSuccess != err) {
            fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n",
                    file, line, cudaGetErrorString( err) );
            exit(-1);
        }
    } while (0);
}

inline void __cudaSafeThreadSync( const char *file, const int line )
{
    do {
        cudaError err = cudaThreadSynchronize();
        if ( cudaSuccess != err) {
            fprintf(stderr, "cudaThreadSynchronize() Driver API error in file '%s' in line %i : %s.\n",
                    file, line, cudaGetErrorString( err) );
            exit(-1);
        }
    } while (0);
}

inline void __cufftSafeCall( cufftResult err, const char *file, const int line )
{
    do {
        if( CUFFT_SUCCESS != err) {
            fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n",
                    file, line);
            exit(-1);
        }
    } while (0);
}

inline void __cutilCheckError( CUTBoolean err, const char *file, const int line )
{
    if( CUTTrue != err) {
        fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n",
                file, line);
        exit(-1);
    }
}
inline void __cutilCheckMsg( const char *errorMessage, const char *file, const int line )
{
    do {
        cudaError_t err = cudaGetLastError();
        if( cudaSuccess != err) {
            fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n",
                    errorMessage, file, line, cudaGetErrorString( err) );
            exit(-1);
        }
        err = cudaThreadSynchronize();
        if( cudaSuccess != err) {
            fprintf(stderr, "cutilCheckMsg cudaThreadSynchronize error: %s in file <%s>, line %i : %s.\n",
                    errorMessage, file, line, cudaGetErrorString( err) );
            exit(-1);
        }
    } while (0);
}
inline void __cutilSafeMalloc( void *pointer, const char *file, const int line )
{
    do {
        if( !(pointer)) {
            fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n",
                    file, line);
            exit(-1);
        }
    } while (0);
}

#if __DEVICE_EMULATION__
    inline void cutilDeviceInit(int ARGC, char **ARGV) { }
    inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV) { } 
#else
    inline void cutilDeviceInit(int ARGC, char **ARGV)
    {
        int deviceCount;
        cutilSafeCallNoSync(cudaGetDeviceCount(&deviceCount));
        if (deviceCount == 0) {
            fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
            exit(-1);
        }
        int dev = 0;
        cutGetCmdLineArgumenti(ARGC, (const char **) ARGV, "device", &dev);
	    if (dev < 0) dev = 0;\
        if (dev > deviceCount-1) dev = deviceCount - 1;
        cudaDeviceProp deviceProp;
        cutilSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev));
        if (deviceProp.major < 1) {
            fprintf(stderr, "cutil error: device does not support CUDA.\n");
            exit(-1);                                                  \
        }
        if (cutCheckCmdLineFlag(ARGC, (const char **) ARGV, "quiet") == CUTFalse)
            fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name);
        cutilSafeCall(cudaSetDevice(dev));
    }

    inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char ** ARGV) 
    {
        cuDevice = 0;
        int deviceCount = 0;
        CUresult err = cuInit(0);
        if (CUDA_SUCCESS == err)
            cutilDrvSafeCallNoSync(cuDeviceGetCount(&deviceCount));
        if (deviceCount == 0) {
            fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
            exit(-1);
        }
        int dev = 0;
        cutGetCmdLineArgumenti(ARGC, (const char **) ARGV, "device", &dev);
	    if (dev < 0) dev = 0;
        if (dev > deviceCount-1) dev = deviceCount - 1;
        cutilDrvSafeCallNoSync(cuDeviceGet(&cuDevice, dev));
        char name[100];
        cuDeviceGetName(name, 100, cuDevice);
        if (cutCheckCmdLineFlag(ARGC, (const char **) ARGV, "quiet") == CUTFalse)
            fprintf(stderr, "Using device %d: %s\n", dev, name);
    }
#endif


//! Check for CUDA context lost
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line ) 
{
    do {
        cudaError_t err = cudaGetLastError();
        if( cudaSuccess != err) {
            fprintf(stderr, "CUDA error: %s in file '%s' in line %i : %s.\n",
            errorMessage, file, line, cudaGetErrorString( err) );
            exit(-1);
        }
        err = cudaThreadSynchronize();
        if( cudaSuccess != err) {
            fprintf(stderr, "CCUDA error: %s in file '%s' in line %i : %s.\n",
            errorMessage, file, line, cudaGetErrorString( err) );
            exit(-1);
        }
    } while (0);
}


//! Check for CUDA context lost
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line ) 
{
    do { 
        CUresult err = cuCtxSynchronize();
        if( CUDA_ERROR_INVALID_CONTEXT != err) {
            fprintf(stderr, "Cuda error: %s in file '%s' in line %i\n",
                    errorMessage, file, line );
            exit(-1);
        }
        err = cuCtxSynchronize();
        if( CUDA_SUCCESS != err) {
            fprintf(stderr, "Cuda error: %s in file '%s' in line %i\n",
                    errorMessage, file, line );
            exit(-1);
        } 
    } while (0);
}

#endif // _CUTIL_INLINE_H_

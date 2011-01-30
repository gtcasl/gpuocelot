#ifndef _CUTIL_GL_INLINE_H_
#define _CUTIL_GL_INLINE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cuda.h>
#include <cutil.h>
#include <cufft.h>
#include <cuda_runtime_api.h>
#include <cuda_gl_interop.h>


#if __DEVICE_EMULATION__
    inline void cutilGLDeviceInit(int ARGC, char **ARGV) { }
    inline void cutilGLDeviceInitDrv(int cuDevice, int ARGC, char **ARGV) { } 
#else
    inline void cutilGLDeviceInit(int ARGC, char **ARGV)
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
        cutilSafeCall(cudaGLSetGLDevice(dev));
    }

    inline void cutilGLDeviceInitDrv(int cuDevice, int ARGC, char ** ARGV) 
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

#endif // _CUTIL_GL_INLINE_H_

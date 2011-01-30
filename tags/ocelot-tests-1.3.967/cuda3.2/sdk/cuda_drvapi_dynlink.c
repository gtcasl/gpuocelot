/*
 * Copyright 1993-2010 NVIDIA Corporation. All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

// With these flags defined, this source file will dynamically
// load the corresponding functions.  Disabled by default.
//#define CUDA_INIT_D3D9
//#define CUDA_INIT_D3D10
//#define CUDA_INIT_D3D11
//#define CUDA_INIT_OPENGL

#include <stdio.h>
#include "cuda_drvapi_dynlink.h"

tcuInit                               *_cuInit;
tcuDriverGetVersion                   *cuDriverGetVersion;
tcuDeviceGet                          *cuDeviceGet;
tcuDeviceGetCount                     *cuDeviceGetCount;
tcuDeviceGetName                      *cuDeviceGetName;
tcuDeviceComputeCapability            *cuDeviceComputeCapability;
tcuDeviceTotalMem                     *cuDeviceTotalMem;
tcuDeviceGetProperties                *cuDeviceGetProperties;
tcuDeviceGetAttribute                 *cuDeviceGetAttribute;
tcuCtxCreate                          *cuCtxCreate;
tcuCtxDestroy                         *cuCtxDestroy;
tcuCtxAttach                          *cuCtxAttach;
tcuCtxDetach                          *cuCtxDetach;
tcuCtxPushCurrent                     *cuCtxPushCurrent;
tcuCtxPopCurrent                      *cuCtxPopCurrent;
tcuCtxGetDevice                       *cuCtxGetDevice;
tcuCtxSynchronize                     *cuCtxSynchronize;
tcuModuleLoad                         *cuModuleLoad;
tcuModuleLoadData                     *cuModuleLoadData;
tcuModuleLoadDataEx                   *cuModuleLoadDataEx;
tcuModuleLoadFatBinary                *cuModuleLoadFatBinary;
tcuModuleUnload                       *cuModuleUnload;
tcuModuleGetFunction                  *cuModuleGetFunction;
tcuModuleGetGlobal                    *cuModuleGetGlobal;
tcuModuleGetTexRef                    *cuModuleGetTexRef;
tcuModuleGetSurfRef                   *cuModuleGetSurfRef;
tcuMemGetInfo                         *cuMemGetInfo;
tcuMemAlloc                           *cuMemAlloc;
tcuMemAllocPitch                      *cuMemAllocPitch;
tcuMemFree                            *cuMemFree;
tcuMemGetAddressRange                 *cuMemGetAddressRange;
tcuMemAllocHost                       *cuMemAllocHost;
tcuMemFreeHost                        *cuMemFreeHost;
tcuMemHostAlloc                       *cuMemHostAlloc;
tcuMemHostGetDevicePointer            *cuMemHostGetDevicePointer;
tcuMemHostGetFlags                    *cuMemHostGetFlags;
tcuMemcpyHtoD                         *cuMemcpyHtoD;
tcuMemcpyDtoH                         *cuMemcpyDtoH;
tcuMemcpyDtoD                         *cuMemcpyDtoD;
tcuMemcpyDtoA                         *cuMemcpyDtoA;
tcuMemcpyAtoD                         *cuMemcpyAtoD;
tcuMemcpyHtoA                         *cuMemcpyHtoA;
tcuMemcpyAtoH                         *cuMemcpyAtoH;
tcuMemcpyAtoA                         *cuMemcpyAtoA;
tcuMemcpy2D                           *cuMemcpy2D;
tcuMemcpy2DUnaligned                  *cuMemcpy2DUnaligned;
tcuMemcpy3D                           *cuMemcpy3D;
tcuMemcpyHtoDAsync                    *cuMemcpyHtoDAsync;
tcuMemcpyDtoHAsync                    *cuMemcpyDtoHAsync;
tcuMemcpyDtoDAsync                    *cuMemcpyDtoDAsync;
tcuMemcpyHtoAAsync                    *cuMemcpyHtoAAsync;
tcuMemcpyAtoHAsync                    *cuMemcpyAtoHAsync;
tcuMemcpy2DAsync                      *cuMemcpy2DAsync;
tcuMemcpy3DAsync                      *cuMemcpy3DAsync;
tcuMemsetD8                           *cuMemsetD8;
tcuMemsetD16                          *cuMemsetD16;
tcuMemsetD32                          *cuMemsetD32;
tcuMemsetD2D8                         *cuMemsetD2D8;
tcuMemsetD2D16                        *cuMemsetD2D16;
tcuMemsetD2D32                        *cuMemsetD2D32;
tcuFuncSetBlockShape                  *cuFuncSetBlockShape;
tcuFuncSetSharedSize                  *cuFuncSetSharedSize;
tcuFuncGetAttribute                   *cuFuncGetAttribute;
tcuFuncSetCacheConfig                 *cuFuncSetCacheConfig;
tcuArrayCreate                        *cuArrayCreate;
tcuArrayGetDescriptor                 *cuArrayGetDescriptor;
tcuArrayDestroy                       *cuArrayDestroy;
tcuArray3DCreate                      *cuArray3DCreate;
tcuArray3DGetDescriptor               *cuArray3DGetDescriptor;
tcuTexRefCreate                       *cuTexRefCreate;
tcuTexRefDestroy                      *cuTexRefDestroy;
tcuTexRefSetArray                     *cuTexRefSetArray;
tcuTexRefSetAddress                   *cuTexRefSetAddress;
tcuTexRefSetAddress2D                 *cuTexRefSetAddress2D;
tcuTexRefSetFormat                    *cuTexRefSetFormat;
tcuTexRefSetAddressMode               *cuTexRefSetAddressMode;
tcuTexRefSetFilterMode                *cuTexRefSetFilterMode;
tcuTexRefSetFlags                     *cuTexRefSetFlags;
tcuTexRefGetAddress                   *cuTexRefGetAddress;
tcuTexRefGetArray                     *cuTexRefGetArray;
tcuTexRefGetAddressMode               *cuTexRefGetAddressMode;
tcuTexRefGetFilterMode                *cuTexRefGetFilterMode;
tcuTexRefGetFormat                    *cuTexRefGetFormat;
tcuTexRefGetFlags                     *cuTexRefGetFlags;
tcuSurfRefSetArray                    *cuSurfRefSetArray;
tcuSurfRefGetArray                    *cuSurfRefGetArray;
tcuParamSetSize                       *cuParamSetSize;
tcuParamSeti                          *cuParamSeti;
tcuParamSetf                          *cuParamSetf;
tcuParamSetv                          *cuParamSetv;
tcuParamSetTexRef                     *cuParamSetTexRef;
tcuLaunch                             *cuLaunch;
tcuLaunchGrid                         *cuLaunchGrid;
tcuLaunchGridAsync                    *cuLaunchGridAsync;
tcuEventCreate                        *cuEventCreate;
tcuEventRecord                        *cuEventRecord;
tcuEventQuery                         *cuEventQuery;
tcuEventSynchronize                   *cuEventSynchronize;
tcuEventDestroy                       *cuEventDestroy;
tcuEventElapsedTime                   *cuEventElapsedTime;
tcuStreamCreate                       *cuStreamCreate;
tcuStreamQuery                        *cuStreamQuery;
tcuStreamSynchronize                  *cuStreamSynchronize;
tcuStreamDestroy                      *cuStreamDestroy;
tcuGraphicsUnregisterResource         *cuGraphicsUnregisterResource;
tcuGraphicsSubResourceGetMappedArray  *cuGraphicsSubResourceGetMappedArray;
tcuGraphicsResourceGetMappedPointer   *cuGraphicsResourceGetMappedPointer;
tcuGraphicsResourceSetMapFlags        *cuGraphicsResourceSetMapFlags;
tcuGraphicsMapResources               *cuGraphicsMapResources;
tcuGraphicsUnmapResources             *cuGraphicsUnmapResources;
tcuGetExportTable                     *cuGetExportTable;
tcuCtxSetLimit                        *cuCtxSetLimit;
tcuCtxGetLimit                        *cuCtxGetLimit;

#ifdef CUDA_INIT_D3D9
// D3D9/CUDA interop (CUDA 1.x compatible API). These functions
// are deprecated; please use the ones below
tcuD3D9Begin                          *cuD3D9Begin;
tcuD3D9End                            *cuD3DEnd;
tcuD3D9RegisterVertexBuffer           *cuD3D9RegisterVertexBuffer;
tcuD3D9MapVertexBuffer                *cuD3D9MapVertexBuffer;
tcuD3D9UnmapVertexBuffer              *cuD3D9UnmapVertexBuffer;
tcuD3D9UnregisterVertexBuffer         *cuD3D9UnregisterVertexBuffer;

// D3D9/CUDA interop (CUDA 2.x compatible)
tcuD3D9GetDirect3DDevice              *cuD3D9GetDirect3DDevice;
tcuD3D9RegisterResource               *cuD3D9RegisterResource;
tcuD3D9UnregisterResource             *cuD3D9UnregisterResource;
tcuD3D9MapResources                   *cuD3D9MapResources;
tcuD3D9UnmapResources                 *cuD3D9UnmapResources;
tcuD3D9ResourceSetMapFlags            *cuD3D9ResourceSetMapFlags;
tcuD3D9ResourceGetSurfaceDimensions   *cuD3D9ResourceGetSurfaceDimensions;
tcuD3D9ResourceGetMappedArray         *cuD3D9ResourceGetMappedArray;
tcuD3D9ResourceGetMappedPointer       *cuD3D9ResourceGetMappedPointer;
tcuD3D9ResourceGetMappedSize          *cuD3D9ResourceGetMappedSize;
tcuD3D9ResourceGetMappedPitch         *cuD3D9ResourceGetMappedPitch;

// D3D9/CUDA interop (CUDA 2.0+)
tcuD3D9GetDevice                      *cuD3D9GetDevice;
tcuD3D9CtxCreate                      *cuD3D9CtxCreate;
tcuGraphicsD3D9RegisterResource       *cuGraphicsD3D9RegisterResource;
#endif

#ifdef CUDA_INIT_D3D10
// D3D10/CUDA interop (CUDA 3.0+)
tcuD3D10GetDevice                     *cuD3D10GetDevice;
tcuD3D10CtxCreate                     *cuD3D10CtxCreate;
tcuGraphicsD3D10RegisterResource      *cuGraphicsD3D10RegisterResource;
#endif


#ifdef CUDA_INIT_D3D11
// D3D11/CUDA interop (CUDA 3.0+)
tcuD3D11GetDevice                     *cuD3D11GetDevice;
tcuD3D11CtxCreate                     *cuD3D11CtxCreate;
tcuGraphicsD3D11RegisterResource      *cuGraphicsD3D11RegisterResource;
#endif

// GL/CUDA interop
#ifdef CUDA_INIT_OPENGL
tcuGLCtxCreate                        *cuGLCtxCreate;
tcuGraphicsGLRegisterBuffer           *cuGraphicsGLRegisterBuffer;
tcuGraphicsGLRegisterImage            *cuGraphicsGLRegisterImage;
#ifdef _WIN32
tcuWGLGetDevice                       *cuWGLGetDevice;
#endif
#endif

#ifdef _WIN32
    #include <Windows.h>

    #ifdef UNICODE
    static LPCWSTR __CudaLibName = L"nvcuda.dll";
    #else
    static LPCSTR __CudaLibName = "nvcuda.dll";
    #endif

    typedef HMODULE CUDADRIVER;

    static CUresult LOAD_LIBRARY(CUDADRIVER *pInstance)
    {
        *pInstance = LoadLibrary(__CudaLibName);
        if (*pInstance == NULL)
        {
            printf("LoadLibrary \"%s\" failed!\n", __CudaLibName);
            return CUDA_ERROR_UNKNOWN;
        }
        return CUDA_SUCCESS;
    }

    #define GET_PROC_EX(name, alias, required)                              \
        alias = (t##name *)GetProcAddress(CudaDrvLib, #name);               \
        if (alias == NULL && required) {                                    \
            printf("Failed to find required function \"%s\" in %s\n",       \
                   #name, __CudaLibName);                                   \
            return CUDA_ERROR_UNKNOWN;                                      \
        }

#elif defined(__unix__) || defined(__APPLE__) || defined(__MACOSX)

    #include <dlfcn.h>

    #if defined(__APPLE__) || defined(__MACOSX)
    static char __CudaLibName[] = "/usr/local/cuda/lib/libcuda.dylib";
    #else
    static char __CudaLibName[] = "libcuda.so";
    #endif

    typedef void * CUDADRIVER;

    static CUresult LOAD_LIBRARY(CUDADRIVER *pInstance)
    {
        *pInstance = dlopen(__CudaLibName, RTLD_NOW);
        if (*pInstance == NULL)
        {
            printf("dlopen \"%s\" failed!\n", __CudaLibName);
            return CUDA_ERROR_UNKNOWN;
        }
        return CUDA_SUCCESS;
    }

    #define GET_PROC_EX(name, alias, required)                              \
        alias = (t##name *)dlsym(CudaDrvLib, #name);                        \
        if (alias == NULL && required) {                                    \
            printf("Failed to find required function \"%s\" in %s\n",       \
                    #name, __CudaLibName);                                  \
            return CUDA_ERROR_UNKNOWN;                                      \
        }

#else
#error unsupported platform
#endif

#define CHECKED_CALL(call)              \
    do {                                \
        CUresult result = (call);       \
        if (CUDA_SUCCESS != result) {   \
            return result;              \
        }                               \
    } while(0)

#define GET_PROC_REQUIRED(name) GET_PROC_EX(name,name,1)
#define GET_PROC_OPTIONAL(name) GET_PROC_EX(name,name,0)
#define GET_PROC(name) GET_PROC_REQUIRED(name)


CUresult CUDAAPI cuInit(unsigned int Flags)
{
    CUDADRIVER CudaDrvLib;
    int driverVer = 1000;

    CHECKED_CALL(LOAD_LIBRARY(&CudaDrvLib));

    // cuInit is required; alias it to _cuInit
    GET_PROC_EX(cuInit, _cuInit, 1);
    CHECKED_CALL(_cuInit(Flags));

    // available since 2.2. if not present, version 1.0 is assumed
    GET_PROC_OPTIONAL(cuDriverGetVersion);
    if (cuDriverGetVersion) {
        CHECKED_CALL(cuDriverGetVersion(&driverVer));
    }

    // fetch all function pointers
    GET_PROC(cuDeviceGet);
    GET_PROC(cuDeviceGetCount);
    GET_PROC(cuDeviceGetName);
    GET_PROC(cuDeviceComputeCapability);
    GET_PROC(cuDeviceTotalMem);
    GET_PROC(cuDeviceGetProperties);
    GET_PROC(cuDeviceGetAttribute);
    GET_PROC(cuCtxCreate);
    GET_PROC(cuCtxDestroy);
    GET_PROC(cuCtxAttach);
    GET_PROC(cuCtxDetach);
    GET_PROC(cuCtxPushCurrent);
    GET_PROC(cuCtxPopCurrent);
    GET_PROC(cuCtxGetDevice);
    GET_PROC(cuCtxSynchronize);
    GET_PROC(cuModuleLoad);
    GET_PROC(cuModuleLoadData);
    GET_PROC(cuModuleUnload);
    GET_PROC(cuModuleGetFunction);
    GET_PROC(cuModuleGetGlobal);
    GET_PROC(cuModuleGetTexRef);
    GET_PROC(cuMemGetInfo);
    GET_PROC(cuMemAlloc);
    GET_PROC(cuMemAllocPitch);
    GET_PROC(cuMemFree);
    GET_PROC(cuMemGetAddressRange);
    GET_PROC(cuMemAllocHost);
    GET_PROC(cuMemFreeHost);
    GET_PROC(cuMemHostAlloc);
    GET_PROC(cuMemHostGetDevicePointer);
    GET_PROC(cuMemcpyHtoD);
    GET_PROC(cuMemcpyDtoH);
    GET_PROC(cuMemcpyDtoD);
    GET_PROC(cuMemcpyDtoA);
    GET_PROC(cuMemcpyAtoD);
    GET_PROC(cuMemcpyHtoA);
    GET_PROC(cuMemcpyAtoH);
    GET_PROC(cuMemcpyAtoA);
    GET_PROC(cuMemcpy2D);
    GET_PROC(cuMemcpy2DUnaligned);
    GET_PROC(cuMemcpy3D);
    GET_PROC(cuMemcpyHtoDAsync);
    GET_PROC(cuMemcpyDtoHAsync);
    GET_PROC(cuMemcpyHtoAAsync);
    GET_PROC(cuMemcpyAtoHAsync);
    GET_PROC(cuMemcpy2DAsync);
    GET_PROC(cuMemcpy3DAsync);
    GET_PROC(cuMemsetD8);
    GET_PROC(cuMemsetD16);
    GET_PROC(cuMemsetD32);
    GET_PROC(cuMemsetD2D8);
    GET_PROC(cuMemsetD2D16);
    GET_PROC(cuMemsetD2D32);
    GET_PROC(cuFuncSetBlockShape);
    GET_PROC(cuFuncSetSharedSize);
    GET_PROC(cuFuncGetAttribute);
    GET_PROC(cuArrayCreate);
    GET_PROC(cuArrayGetDescriptor);
    GET_PROC(cuArrayDestroy);
    GET_PROC(cuArray3DCreate);
    GET_PROC(cuArray3DGetDescriptor);
    GET_PROC(cuTexRefCreate);
    GET_PROC(cuTexRefDestroy);
    GET_PROC(cuTexRefSetArray);
    GET_PROC(cuTexRefSetAddress);
    GET_PROC(cuTexRefSetAddress2D);
    GET_PROC(cuTexRefSetFormat);
    GET_PROC(cuTexRefSetAddressMode);
    GET_PROC(cuTexRefSetFilterMode);
    GET_PROC(cuTexRefSetFlags);
    GET_PROC(cuTexRefGetAddress);
    GET_PROC(cuTexRefGetArray);
    GET_PROC(cuTexRefGetAddressMode);
    GET_PROC(cuTexRefGetFilterMode);
    GET_PROC(cuTexRefGetFormat);
    GET_PROC(cuTexRefGetFlags);
    GET_PROC(cuParamSetSize);
    GET_PROC(cuParamSeti);
    GET_PROC(cuParamSetf);
    GET_PROC(cuParamSetv);
    GET_PROC(cuParamSetTexRef);
    GET_PROC(cuLaunch);
    GET_PROC(cuLaunchGrid);
    GET_PROC(cuLaunchGridAsync);
    GET_PROC(cuEventCreate);
    GET_PROC(cuEventRecord);
    GET_PROC(cuEventQuery);
    GET_PROC(cuEventSynchronize);
    GET_PROC(cuEventDestroy);
    GET_PROC(cuEventElapsedTime);
    GET_PROC(cuStreamCreate);
    GET_PROC(cuStreamQuery);
    GET_PROC(cuStreamSynchronize);
    GET_PROC(cuStreamDestroy);

    // The following functions are specific to CUDA versions
    if (driverVer >= 2010) {
        GET_PROC(cuModuleLoadDataEx);
        GET_PROC(cuModuleLoadFatBinary);
        #ifdef CUDA_INIT_OPENGL
        GET_PROC(cuGLCtxCreate);
        GET_PROC(cuGraphicsGLRegisterBuffer);
        GET_PROC(cuGraphicsGLRegisterImage);
        #  ifdef _WIN32
        GET_PROC(cuWGLGetDevice);
        #  endif
        #endif
        #ifdef CUDA_INIT_D3D9
        GET_PROC(cuD3D9GetDevice);
        GET_PROC(cuD3D9CtxCreate);
        GET_PROC(cuGraphicsD3D9RegisterResource);
        #endif
    }

    if (driverVer >= 2030) {
        GET_PROC(cuMemHostGetFlags);
        #ifdef CUDA_INIT_D3D10
        GET_PROC(cuD3D10GetDevice);
        GET_PROC(cuD3D10CtxCreate);
        GET_PROC(cuGraphicsD3D10RegisterResource);
        #endif
        #ifdef CUDA_INIT_OPENGL
        GET_PROC(cuGraphicsGLRegisterBuffer);
        GET_PROC(cuGraphicsGLRegisterImage);
        #endif
    }

    if (driverVer >= 3000) {
        GET_PROC(cuMemcpyDtoDAsync);
        GET_PROC(cuFuncSetCacheConfig);
        #ifdef CUDA_INIT_D3D11
        GET_PROC(cuD3D11GetDevice);
        GET_PROC(cuD3D11CtxCreate);
        GET_PROC(cuGraphicsD3D11RegisterResource);
        #endif
        GET_PROC(cuGraphicsUnregisterResource);
        GET_PROC(cuGraphicsSubResourceGetMappedArray);
        GET_PROC(cuGraphicsResourceGetMappedPointer);
        GET_PROC(cuGraphicsResourceSetMapFlags);
        GET_PROC(cuGraphicsMapResources);
        GET_PROC(cuGraphicsUnmapResources);
        GET_PROC(cuGetExportTable);
    }

    if (driverVer >= 3010) {
        GET_PROC(cuModuleGetSurfRef);
        GET_PROC(cuSurfRefSetArray);
        GET_PROC(cuSurfRefGetArray);
        GET_PROC(cuCtxSetLimit);
        GET_PROC(cuCtxGetLimit);
    }

    return CUDA_SUCCESS;
}


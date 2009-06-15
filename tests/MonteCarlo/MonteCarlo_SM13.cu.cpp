# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.cpp"
# 1 "MonteCarlo_SM13.cu"
# 233 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) {
# 245 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
}
# 152 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 1 3
# 69 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 1 3
# 54 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/host_defines.h" 1 3
# 55 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 1 3
# 42 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/device_types.h" 1 3
# 46 "/home/gdiamos/temp/cuda/bin//../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/driver_types.h" 1 3
# 59 "/home/gdiamos/temp/cuda/bin//../include/driver_types.h" 3
enum cudaError
{
  cudaSuccess = 0,
  cudaErrorMissingConfiguration,
  cudaErrorMemoryAllocation,
  cudaErrorInitializationError,
  cudaErrorLaunchFailure,
  cudaErrorPriorLaunchFailure,
  cudaErrorLaunchTimeout,
  cudaErrorLaunchOutOfResources,
  cudaErrorInvalidDeviceFunction,
  cudaErrorInvalidConfiguration,
  cudaErrorInvalidDevice,
  cudaErrorInvalidValue,
  cudaErrorInvalidPitchValue,
  cudaErrorInvalidSymbol,
  cudaErrorMapBufferObjectFailed,
  cudaErrorUnmapBufferObjectFailed,
  cudaErrorInvalidHostPointer,
  cudaErrorInvalidDevicePointer,
  cudaErrorInvalidTexture,
  cudaErrorInvalidTextureBinding,
  cudaErrorInvalidChannelDescriptor,
  cudaErrorInvalidMemcpyDirection,
  cudaErrorAddressOfConstant,
  cudaErrorTextureFetchFailed,
  cudaErrorTextureNotBound,
  cudaErrorSynchronizationError,
  cudaErrorInvalidFilterSetting,
  cudaErrorInvalidNormSetting,
  cudaErrorMixedDeviceExecution,
  cudaErrorCudartUnloading,
  cudaErrorUnknown,
  cudaErrorNotYetImplemented,
  cudaErrorMemoryValueTooLarge,
  cudaErrorInvalidResourceHandle,
  cudaErrorNotReady,
  cudaErrorInsufficientDriver,
  cudaErrorSetOnActiveProcess,
  cudaErrorStartupFailure = 0x7f,
  cudaErrorApiFailureBase = 10000
};


enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned,
  cudaChannelFormatKindUnsigned,
  cudaChannelFormatKindFloat,
  cudaChannelFormatKindNone
};


struct cudaChannelFormatDesc
{
  int x;
  int y;
  int z;
  int w;
  enum cudaChannelFormatKind f;
};


struct cudaArray;


enum cudaMemcpyKind
{
  cudaMemcpyHostToHost = 0,
  cudaMemcpyHostToDevice,
  cudaMemcpyDeviceToHost,
  cudaMemcpyDeviceToDevice
};


struct cudaPitchedPtr
{
  void *ptr;
  size_t pitch;
  size_t xsize;
  size_t ysize;
};


struct cudaExtent
{
  size_t width;
  size_t height;
  size_t depth;
};


struct cudaPos
{
  size_t x;
  size_t y;
  size_t z;
};


struct cudaMemcpy3DParms
{
  struct cudaArray *srcArray;
  struct cudaPos srcPos;
  struct cudaPitchedPtr srcPtr;

  struct cudaArray *dstArray;
  struct cudaPos dstPos;
  struct cudaPitchedPtr dstPtr;

  struct cudaExtent extent;
  enum cudaMemcpyKind kind;
};


struct cudaDeviceProp
{
  char name[256];
  size_t totalGlobalMem;
  size_t sharedMemPerBlock;
  int regsPerBlock;
  int warpSize;
  size_t memPitch;
  int maxThreadsPerBlock;
  int maxThreadsDim[3];
  int maxGridSize[3];
  int clockRate;
  size_t totalConstMem;
  int major;
  int minor;
  size_t textureAlignment;
  int deviceOverlap;
  int multiProcessorCount;
  int kernelExecTimeoutEnabled;
  int __cudaReserved[39];
};
# 224 "/home/gdiamos/temp/cuda/bin//../include/driver_types.h" 3
typedef enum cudaError cudaError_t;


typedef int cudaStream_t;


typedef int cudaEvent_t;
# 44 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/texture_types.h" 1 3
# 54 "/home/gdiamos/temp/cuda/bin//../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap,
  cudaAddressModeClamp
};


enum cudaTextureFilterMode
{
  cudaFilterModePoint,
  cudaFilterModeLinear
};


enum cudaTextureReadMode
{
  cudaReadModeElementType,
  cudaReadModeNormalizedFloat
};


struct textureReference
{
  int normalized;
  enum cudaTextureFilterMode filterMode;
  enum cudaTextureAddressMode addressMode[3];
  struct cudaChannelFormatDesc channelDesc;
  int __cudaReserved[16];
};
# 45 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/vector_types.h" 1 3
# 54 "/home/gdiamos/temp/cuda/bin//../include/vector_types.h" 3
struct char1
{
  signed char x;
};


struct uchar1
{
  unsigned char x;
};


struct char2
{
  signed char x, y;
};


struct uchar2
{
  unsigned char x, y;
};


struct char3
{
  signed char x, y, z;
};


struct uchar3
{
  unsigned char x, y, z;
};


struct char4
{
  signed char x, y, z, w;
};


struct uchar4
{
  unsigned char x, y, z, w;
};


struct short1
{
  short x;
};


struct ushort1
{
  unsigned short x;
};


struct short2
{
  short x, y;
};


struct ushort2
{
  unsigned short x, y;
};


struct short3
{
  short x, y, z;
};


struct ushort3
{
  unsigned short x, y, z;
};


struct short4
{
  short x, y, z, w;
};


struct ushort4
{
  unsigned short x, y, z, w;
};


struct int1
{
  int x;
};


struct uint1
{
  unsigned int x;
};


struct int2
{
  int x, y;
};


struct uint2
{
  unsigned int x, y;
};


struct int3
{
  int x, y, z;
};


struct uint3
{
  unsigned int x, y, z;
};


struct int4
{
  int x, y, z, w;
};


struct uint4
{
  unsigned int x, y, z, w;
};


struct long1
{
  long int x;
};


struct ulong1
{
  unsigned long x;
};


struct



      

                                             long2
{
  long int x, y;
};


struct



      

                                                      ulong2
{
  unsigned long int x, y;
};
# 262 "/home/gdiamos/temp/cuda/bin//../include/vector_types.h" 3
struct float1
{
  float x;
};


struct float2
{
  float x, y;
};


struct float3
{
  float x, y, z;
};


struct float4
{
  float x, y, z, w;
};


struct longlong1
{
  long long int x;
};


struct ulonglong1
{
  unsigned long long int x;
};


struct longlong2
{
  long long int x, y;
};


struct ulonglong2
{
  unsigned long long int x, y;
};


struct double1
{
  double x;
};


struct double2
{
  double x, y;
};
# 328 "/home/gdiamos/temp/cuda/bin//../include/vector_types.h" 3
typedef struct char1 char1;

typedef struct uchar1 uchar1;

typedef struct char2 char2;

typedef struct uchar2 uchar2;

typedef struct char3 char3;

typedef struct uchar3 uchar3;

typedef struct char4 char4;

typedef struct uchar4 uchar4;

typedef struct short1 short1;

typedef struct ushort1 ushort1;

typedef struct short2 short2;

typedef struct ushort2 ushort2;

typedef struct short3 short3;

typedef struct ushort3 ushort3;

typedef struct short4 short4;

typedef struct ushort4 ushort4;

typedef struct int1 int1;

typedef struct uint1 uint1;

typedef struct int2 int2;

typedef struct uint2 uint2;

typedef struct int3 int3;

typedef struct uint3 uint3;

typedef struct int4 int4;

typedef struct uint4 uint4;

typedef struct long1 long1;

typedef struct ulong1 ulong1;

typedef struct long2 long2;

typedef struct ulong2 ulong2;

typedef struct long3 long3;

typedef struct ulong3 ulong3;

typedef struct long4 long4;

typedef struct ulong4 ulong4;

typedef struct float1 float1;

typedef struct float2 float2;

typedef struct float3 float3;

typedef struct float4 float4;

typedef struct longlong1 longlong1;

typedef struct ulonglong1 ulonglong1;

typedef struct longlong2 longlong2;

typedef struct ulonglong2 ulonglong2;

typedef struct double1 double1;

typedef struct double2 double2;
# 419 "/home/gdiamos/temp/cuda/bin//../include/vector_types.h" 3
typedef struct dim3 dim3;


struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};
# 45 "/home/gdiamos/temp/cuda/bin//../include/builtin_types.h" 2 3
# 56 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 2 3
# 79 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 3
extern "C" {
# 88 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);
# 101 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);
# 116 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset , enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset , enum cudaMemcpyKind kind );







extern cudaError_t cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);







extern cudaError_t cudaMemset(void *mem, int c, size_t count);
extern cudaError_t cudaMemset2D(void *mem, size_t pitch, int c, size_t width, size_t height);







extern cudaError_t cudaGetSymbolAddress(void **devPtr, const char *symbol);
extern cudaError_t cudaGetSymbolSize(size_t *size, const char *symbol);







extern cudaError_t cudaGetDeviceCount(int *count);
extern cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
extern cudaError_t cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
extern cudaError_t cudaSetDevice(int device);
extern cudaError_t cudaGetDevice(int *device);







extern cudaError_t cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size );
extern cudaError_t cudaBindTextureToArray(const struct textureReference *texref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
extern cudaError_t cudaUnbindTexture(const struct textureReference *texref);
extern cudaError_t cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref);
extern cudaError_t cudaGetTextureReference(const struct textureReference **texref, const char *symbol);







extern cudaError_t cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array);
extern struct cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);







extern cudaError_t cudaGetLastError(void);
extern const char* cudaGetErrorString(cudaError_t error);







extern cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem , cudaStream_t stream );
extern cudaError_t cudaSetupArgument(const void *arg, size_t size, size_t offset);
extern cudaError_t cudaLaunch(const char *symbol);







extern cudaError_t cudaStreamCreate(cudaStream_t *stream);
extern cudaError_t cudaStreamDestroy(cudaStream_t stream);
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream);
extern cudaError_t cudaStreamQuery(cudaStream_t stream);







extern cudaError_t cudaEventCreate(cudaEvent_t *event);
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
extern cudaError_t cudaEventQuery(cudaEvent_t event);
extern cudaError_t cudaEventSynchronize(cudaEvent_t event);
extern cudaError_t cudaEventDestroy(cudaEvent_t event);
extern cudaError_t cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);







extern cudaError_t cudaSetDoubleForDevice(double *d);
extern cudaError_t cudaSetDoubleForHost(double *d);







extern cudaError_t cudaThreadExit(void);
extern cudaError_t cudaThreadSynchronize(void);


}
# 70 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/crt/storage_class.h" 1 3
# 71 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 2 3
# 88 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 89 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
# 90 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 91 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 92 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 101 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
# 105 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 116 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 117 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 118 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 119 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 120 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 121 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 122 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 125 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 133 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 134 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 135 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 136 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 137 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 138 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 139 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 140 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 148 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 149 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 157 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 158 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 166 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 167 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 168 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 169 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 170 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 178 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 179 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 180 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 181 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 182 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 190 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 191 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 199 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 200 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 208 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
# 209 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 210 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 218 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 219 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 220 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 221 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 229 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 230 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
# 231 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 232 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 233 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 234 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 242 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 243 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 251 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 252 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 58 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 59 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 60 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 61 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 63 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 64 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 65 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(char)) * 8);
# 70 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 72 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 74 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 75 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 76 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 78 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 79 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 81 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 82 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 83 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 85 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 86 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 88 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 89 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 90 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 92 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 93 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 95 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 96 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 97 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 99 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 100 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 102 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 103 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 104 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 106 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 107 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 109 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 110 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 111 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 113 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 114 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 116 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 117 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 118 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 120 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 121 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 123 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 124 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 125 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 127 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 128 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 130 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 131 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 132 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 134 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 135 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 137 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 138 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 139 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 141 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 142 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 144 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 145 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 146 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 148 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 149 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 151 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 152 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 153 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 155 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 156 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 158 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 159 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 160 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 162 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 163 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 165 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 166 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 167 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 169 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 170 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 172 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 173 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 174 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 176 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 177 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 179 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 180 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 181 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 183 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 184 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 186 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 187 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 188 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 190 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 191 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 193 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 194 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 195 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 197 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 198 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 200 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 201 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 202 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 204 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 205 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 207 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 208 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 209 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 211 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 212 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 214 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 215 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 216 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 218 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 219 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 221 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 222 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 223 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 225 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 226 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 228 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 229 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 230 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 232 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 233 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 235 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 236 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 237 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 239 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 240 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 302 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 303 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 304 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 306 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 307 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 309 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 310 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 311 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 313 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 314 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 316 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 317 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 318 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 320 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 321 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 323 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 324 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
{
# 325 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 327 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 328 "/home/gdiamos/temp/cuda/bin//../include/channel_descriptor.h"
}
# 54 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 55 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
{
# 56 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
auto cudaPitchedPtr s;
# 58 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(s.ptr) = d;
# 59 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(s.pitch) = p;
# 60 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(s.xsize) = xsz;
# 61 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(s.ysize) = ysz;
# 63 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
return s;
# 64 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
}
# 66 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 67 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
{
# 68 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
auto cudaPos p;
# 70 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(p.x) = x;
# 71 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(p.y) = y;
# 72 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(p.z) = z;
# 74 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
return p;
# 75 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
}
# 77 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 78 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
{
# 79 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
auto cudaExtent e;
# 81 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(e.width) = w;
# 82 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(e.height) = h;
# 83 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
(e.depth) = d;
# 85 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
return e;
# 86 "/home/gdiamos/temp/cuda/bin//../include/driver_functions.h"
}
# 54 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 55 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 56 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto char1 t; (t.x) = x; return t;
# 57 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 59 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 60 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 61 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uchar1 t; (t.x) = x; return t;
# 62 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 64 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 65 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 66 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto char2 t; (t.x) = x; (t.y) = y; return t;
# 67 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 69 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 70 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 71 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uchar2 t; (t.x) = x; (t.y) = y; return t;
# 72 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 74 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 75 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 76 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 77 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 79 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 80 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 81 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 82 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 84 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 85 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 86 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 87 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 89 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 90 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 91 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 92 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 94 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline short1 make_short1(short x)
# 95 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 96 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto short1 t; (t.x) = x; return t;
# 97 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 99 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 100 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 101 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ushort1 t; (t.x) = x; return t;
# 102 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 104 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 105 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 106 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto short2 t; (t.x) = x; (t.y) = y; return t;
# 107 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 109 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 110 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 111 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ushort2 t; (t.x) = x; (t.y) = y; return t;
# 112 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 114 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 115 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 116 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 117 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 119 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 120 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 121 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 122 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 124 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 125 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 126 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 127 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 129 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 130 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 131 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 132 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 134 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline int1 make_int1(int x)
# 135 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 136 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto int1 t; (t.x) = x; return t;
# 137 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 139 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 140 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 141 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uint1 t; (t.x) = x; return t;
# 142 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 144 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 145 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 146 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto int2 t; (t.x) = x; (t.y) = y; return t;
# 147 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 149 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 150 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 151 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uint2 t; (t.x) = x; (t.y) = y; return t;
# 152 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 154 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 155 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 156 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 157 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 159 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 160 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 161 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 162 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 164 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 165 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 166 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 167 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 169 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 170 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 171 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 172 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 174 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline long1 make_long1(long x)
# 175 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 176 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto long1 t; (t.x) = x; return t;
# 177 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 179 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 180 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 181 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ulong1 t; (t.x) = x; return t;
# 182 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 184 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 185 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 186 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto long2 t; (t.x) = x; (t.y) = y; return t;
# 187 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 189 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 190 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 191 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ulong2 t; (t.x) = x; (t.y) = y; return t;
# 192 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 218 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline float1 make_float1(float x)
# 219 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 220 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto float1 t; (t.x) = x; return t;
# 221 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 223 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 224 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 225 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto float2 t; (t.x) = x; (t.y) = y; return t;
# 226 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 228 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 229 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 230 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 231 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 233 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 234 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 235 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 236 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 238 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 239 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 240 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto longlong1 t; (t.x) = x; return t;
# 241 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 243 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 244 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 245 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ulonglong1 t; (t.x) = x; return t;
# 246 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 248 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 249 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 250 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto longlong2 t; (t.x) = x; (t.y) = y; return t;
# 251 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 253 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 254 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 255 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 256 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 258 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline double1 make_double1(double x)
# 259 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 260 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto double1 t; (t.x) = x; return t;
# 261 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 263 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 264 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
{
# 265 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
auto double2 t; (t.x) = x; (t.y) = y; return t;
# 266 "/home/gdiamos/temp/cuda/bin//../include/vector_functions.h"
}
# 31 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __u_char; }
# 32 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned short __u_short; }
# 33 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __u_int; }
# 34 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __u_long; }
# 37 "/usr/include/bits/types.h" 3
extern "C" { typedef signed char __int8_t; }
# 38 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __uint8_t; }
# 39 "/usr/include/bits/types.h" 3
extern "C" { typedef signed short __int16_t; }
# 40 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned short __uint16_t; }
# 41 "/usr/include/bits/types.h" 3
extern "C" { typedef signed int __int32_t; }
# 42 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __uint32_t; }
# 44 "/usr/include/bits/types.h" 3
extern "C" { typedef signed long __int64_t; }
# 45 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __uint64_t; }
# 53 "/usr/include/bits/types.h" 3
extern "C" { typedef long __quad_t; }
# 54 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __u_quad_t; }
# 134 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __dev_t; }
# 135 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __uid_t; }
# 136 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __gid_t; }
# 137 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __ino_t; }
# 138 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __ino64_t; }
# 139 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __mode_t; }
# 140 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __nlink_t; }
# 141 "/usr/include/bits/types.h" 3
extern "C" { typedef long __off_t; }
# 142 "/usr/include/bits/types.h" 3
extern "C" { typedef long __off64_t; }
# 143 "/usr/include/bits/types.h" 3
extern "C" { typedef int __pid_t; }
# 144 "/usr/include/bits/types.h" 3
extern "C" { typedef struct __fsid_t { int __val[2]; } __fsid_t; }
# 145 "/usr/include/bits/types.h" 3
extern "C" { typedef long __clock_t; }
# 146 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __rlim_t; }
# 147 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __rlim64_t; }
# 148 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __id_t; }
# 149 "/usr/include/bits/types.h" 3
extern "C" { typedef long __time_t; }
# 150 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __useconds_t; }
# 151 "/usr/include/bits/types.h" 3
extern "C" { typedef long __suseconds_t; }
# 153 "/usr/include/bits/types.h" 3
extern "C" { typedef int __daddr_t; }
# 154 "/usr/include/bits/types.h" 3
extern "C" { typedef long __swblk_t; }
# 155 "/usr/include/bits/types.h" 3
extern "C" { typedef int __key_t; }
# 158 "/usr/include/bits/types.h" 3
extern "C" { typedef int __clockid_t; }
# 161 "/usr/include/bits/types.h" 3
extern "C" { typedef void *__timer_t; }
# 164 "/usr/include/bits/types.h" 3
extern "C" { typedef long __blksize_t; }
# 169 "/usr/include/bits/types.h" 3
extern "C" { typedef long __blkcnt_t; }
# 170 "/usr/include/bits/types.h" 3
extern "C" { typedef long __blkcnt64_t; }
# 173 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsblkcnt_t; }
# 174 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsblkcnt64_t; }
# 177 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsfilcnt_t; }
# 178 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsfilcnt64_t; }
# 180 "/usr/include/bits/types.h" 3
extern "C" { typedef long __ssize_t; }
# 184 "/usr/include/bits/types.h" 3
extern "C" { typedef __off64_t __loff_t; }
# 185 "/usr/include/bits/types.h" 3
extern "C" { typedef __quad_t *__qaddr_t; }
# 186 "/usr/include/bits/types.h" 3
extern "C" { typedef char *__caddr_t; }
# 189 "/usr/include/bits/types.h" 3
extern "C" { typedef long __intptr_t; }
# 192 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __socklen_t; }
# 61 "/usr/include/time.h" 3
extern "C" { typedef __clock_t clock_t; }
# 77 "/usr/include/time.h" 3
extern "C" { typedef __time_t time_t; }
# 93 "/usr/include/time.h" 3
extern "C" { typedef __clockid_t clockid_t; }
# 105 "/usr/include/time.h" 3
extern "C" { typedef __timer_t timer_t; }
# 121 "/usr/include/time.h" 3
extern "C" { struct timespec {
# 123 "/usr/include/time.h" 3
__time_t tv_sec;
# 124 "/usr/include/time.h" 3
long tv_nsec;
# 125 "/usr/include/time.h" 3
}; }
# 134 "/usr/include/time.h" 3
extern "C" { struct tm {
# 136 "/usr/include/time.h" 3
int tm_sec;
# 137 "/usr/include/time.h" 3
int tm_min;
# 138 "/usr/include/time.h" 3
int tm_hour;
# 139 "/usr/include/time.h" 3
int tm_mday;
# 140 "/usr/include/time.h" 3
int tm_mon;
# 141 "/usr/include/time.h" 3
int tm_year;
# 142 "/usr/include/time.h" 3
int tm_wday;
# 143 "/usr/include/time.h" 3
int tm_yday;
# 144 "/usr/include/time.h" 3
int tm_isdst;
# 147 "/usr/include/time.h" 3
long tm_gmtoff;
# 148 "/usr/include/time.h" 3
const char *tm_zone;
# 153 "/usr/include/time.h" 3
}; }
# 162 "/usr/include/time.h" 3
extern "C" { struct itimerspec {
# 164 "/usr/include/time.h" 3
timespec it_interval;
# 165 "/usr/include/time.h" 3
timespec it_value;
# 166 "/usr/include/time.h" 3
}; }
# 169 "/usr/include/time.h" 3
struct sigevent;
# 175 "/usr/include/time.h" 3
extern "C" { typedef __pid_t pid_t; }
# 184 "/usr/include/time.h" 3
extern "C" __attribute__((__weak__)) clock_t clock() throw();
# 187 "/usr/include/time.h" 3
extern "C" time_t time(time_t *) throw();
# 190 "/usr/include/time.h" 3
extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__));
# 194 "/usr/include/time.h" 3
extern "C" time_t mktime(tm *) throw();
# 200 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw();
# 208 "/usr/include/time.h" 3
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw();
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef
# 28 "/usr/include/xlocale.h" 3
struct __locale_struct {
# 31 "/usr/include/xlocale.h" 3
struct locale_data *__locales[13];
# 34 "/usr/include/xlocale.h" 3
const unsigned short *__ctype_b;
# 35 "/usr/include/xlocale.h" 3
const int *__ctype_tolower;
# 36 "/usr/include/xlocale.h" 3
const int *__ctype_toupper;
# 39 "/usr/include/xlocale.h" 3
const char *__names[13];
# 40 "/usr/include/xlocale.h" 3
} *__locale_t; }
# 218 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw();
# 223 "/usr/include/time.h" 3
extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw();
# 232 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *) throw();
# 236 "/usr/include/time.h" 3
extern "C" tm *localtime(const time_t *) throw();
# 242 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 247 "/usr/include/time.h" 3
extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 254 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *) throw();
# 257 "/usr/include/time.h" 3
extern "C" char *ctime(const time_t *) throw();
# 265 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw();
# 269 "/usr/include/time.h" 3
extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw();
# 275 "/usr/include/time.h" 3
extern "C" { extern char *__tzname[2]; }
# 276 "/usr/include/time.h" 3
extern "C" { extern int __daylight; }
# 277 "/usr/include/time.h" 3
extern "C" { extern long __timezone; }
# 282 "/usr/include/time.h" 3
extern "C" { extern char *tzname[2]; }
# 286 "/usr/include/time.h" 3
extern "C" void tzset() throw();
# 290 "/usr/include/time.h" 3
extern "C" { extern int daylight; }
# 291 "/usr/include/time.h" 3
extern "C" { extern long timezone; }
# 297 "/usr/include/time.h" 3
extern "C" int stime(const time_t *) throw();
# 312 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *) throw();
# 315 "/usr/include/time.h" 3
extern "C" time_t timelocal(tm *) throw();
# 318 "/usr/include/time.h" 3
extern "C" int dysize(int) throw() __attribute__((__const__));
# 327 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *);
# 332 "/usr/include/time.h" 3
extern "C" int clock_getres(clockid_t, timespec *) throw();
# 335 "/usr/include/time.h" 3
extern "C" int clock_gettime(clockid_t, timespec *) throw();
# 338 "/usr/include/time.h" 3
extern "C" int clock_settime(clockid_t, const timespec *) throw();
# 346 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *);
# 351 "/usr/include/time.h" 3
extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw();
# 356 "/usr/include/time.h" 3
extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw();
# 361 "/usr/include/time.h" 3
extern "C" int timer_delete(timer_t) throw();
# 364 "/usr/include/time.h" 3
extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw();
# 369 "/usr/include/time.h" 3
extern "C" int timer_gettime(timer_t, itimerspec *) throw();
# 373 "/usr/include/time.h" 3
extern "C" int timer_getoverrun(timer_t) throw();
# 389 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 398 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 412 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__);
# 38 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw();
# 43 "/usr/include/string.h" 3
extern "C" void *memmove(void *, const void *, size_t) throw();
# 51 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 59 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();
# 62 "/usr/include/string.h" 3
extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));
# 66 "/usr/include/string.h" 3
extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 73 "/usr/include/string.h" 3
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__));
# 77 "/usr/include/string.h" 3
extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 84 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw();
# 87 "/usr/include/string.h" 3
extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw();
# 92 "/usr/include/string.h" 3
extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw();
# 95 "/usr/include/string.h" 3
extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw();
# 99 "/usr/include/string.h" 3
extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__));
# 102 "/usr/include/string.h" 3
extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__));
# 106 "/usr/include/string.h" 3
extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__));
# 109 "/usr/include/string.h" 3
extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw();
# 121 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));
# 124 "/usr/include/string.h" 3
extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw();
# 130 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__));
# 138 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__));
# 167 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int) throw() __attribute__((__pure__));
# 170 "/usr/include/string.h" 3
extern "C" char *strrchr(const char *, int) throw() __attribute__((__pure__));
# 177 "/usr/include/string.h" 3
extern "C" char *strchrnul(const char *, int) throw() __attribute__((__pure__));
# 184 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__));
# 188 "/usr/include/string.h" 3
extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__));
# 191 "/usr/include/string.h" 3
extern "C" char *strpbrk(const char *, const char *) throw() __attribute__((__pure__));
# 194 "/usr/include/string.h" 3
extern "C" char *strstr(const char *, const char *) throw() __attribute__((__pure__));
# 199 "/usr/include/string.h" 3
extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw();
# 205 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();
# 210 "/usr/include/string.h" 3
extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();
# 217 "/usr/include/string.h" 3
extern "C" char *strcasestr(const char *, const char *) throw() __attribute__((__pure__));
# 225 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__));
# 231 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();
# 234 "/usr/include/string.h" 3
extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();
# 242 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__));
# 249 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__));
# 256 "/usr/include/string.h" 3
extern "C" char *strerror(int) throw();
# 281 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw();
# 288 "/usr/include/string.h" 3
extern "C" char *strerror_l(int, __locale_t) throw();
# 294 "/usr/include/string.h" 3
extern "C" void __bzero(void *, size_t) throw();
# 298 "/usr/include/string.h" 3
extern "C" void bcopy(const void *, void *, size_t) throw();
# 302 "/usr/include/string.h" 3
extern "C" void bzero(void *, size_t) throw();
# 305 "/usr/include/string.h" 3
extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));
# 309 "/usr/include/string.h" 3
extern "C" char *index(const char *, int) throw() __attribute__((__pure__));
# 313 "/usr/include/string.h" 3
extern "C" char *rindex(const char *, int) throw() __attribute__((__pure__));
# 318 "/usr/include/string.h" 3
extern "C" int ffs(int) throw() __attribute__((__const__));
# 323 "/usr/include/string.h" 3
extern "C" int ffsl(long) throw() __attribute__((__const__));
# 325 "/usr/include/string.h" 3
extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 331 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__));
# 335 "/usr/include/string.h" 3
extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__));
# 342 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));
# 346 "/usr/include/string.h" 3
extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__));
# 354 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw();
# 361 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__));
# 365 "/usr/include/string.h" 3
extern "C" char *strsignal(int) throw();
# 368 "/usr/include/string.h" 3
extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw();
# 370 "/usr/include/string.h" 3
extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw();
# 375 "/usr/include/string.h" 3
extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();
# 378 "/usr/include/string.h" 3
extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();
# 383 "/usr/include/string.h" 3
extern "C" char *strfry(char *) throw();
# 386 "/usr/include/string.h" 3
extern "C" void *memfrob(void *, size_t) throw();
# 393 "/usr/include/string.h" 3
extern "C" char *basename(const char *) throw();
# 56 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();
# 59 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h"
extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();
# 62 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h"
extern "C" __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw();
# 65 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 67 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 69 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 71 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));
# 73 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));
# 76 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int min(int, int);
# 78 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);
# 80 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fminf(float, float) throw();
# 82 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmin(double, double) throw();
# 85 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int max(int, int);
# 87 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);
# 89 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();
# 91 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmax(double, double) throw();
# 94 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sin(double) throw();
# 96 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 99 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cos(double) throw();
# 101 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 104 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();
# 106 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 109 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tan(double) throw();
# 111 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 114 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sqrt(double) throw();
# 116 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sqrtf(float) throw();
# 119 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rsqrt(double);
# 121 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rsqrtf(float);
# 124 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp2(double) throw();
# 126 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp2f(float) throw();
# 129 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp10(double) throw();
# 131 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 134 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double expm1(double) throw();
# 136 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expm1f(float) throw();
# 139 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log2(double) throw();
# 141 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 144 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log10(double) throw();
# 146 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 149 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log(double) throw();
# 151 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 154 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log1p(double) throw();
# 156 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log1pf(float) throw();
# 159 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));
# 161 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));
# 164 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp(double) throw();
# 166 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 169 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cosh(double) throw();
# 171 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float coshf(float) throw();
# 174 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinh(double) throw();
# 176 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinhf(float) throw();
# 179 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tanh(double) throw();
# 181 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanhf(float) throw();
# 184 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acosh(double) throw();
# 186 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acoshf(float) throw();
# 189 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asinh(double) throw();
# 191 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinhf(float) throw();
# 194 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atanh(double) throw();
# 196 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanhf(float) throw();
# 199 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();
# 201 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();
# 204 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double logb(double) throw();
# 206 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logbf(float) throw();
# 209 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogb(double) throw();
# 211 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogbf(float) throw();
# 214 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();
# 216 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();
# 219 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();
# 221 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();
# 224 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();
# 226 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();
# 229 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));
# 231 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));
# 234 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lround(double) throw();
# 236 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lroundf(float) throw();
# 239 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llround(double) throw();
# 241 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llroundf(float) throw();
# 244 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rint(double) throw();
# 246 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rintf(float) throw();
# 249 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrint(double) throw();
# 251 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrintf(float) throw();
# 254 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrint(double) throw();
# 256 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrintf(float) throw();
# 259 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nearbyint(double) throw();
# 261 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();
# 264 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));
# 266 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));
# 269 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));
# 271 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));
# 274 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fdim(double, double) throw();
# 276 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();
# 279 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan2(double, double) throw();
# 281 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();
# 284 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan(double) throw();
# 286 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanf(float) throw();
# 289 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asin(double) throw();
# 291 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinf(float) throw();
# 294 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acos(double) throw();
# 296 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acosf(float) throw();
# 299 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double hypot(double, double) throw();
# 301 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();
# 304 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cbrt(double) throw();
# 306 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cbrtf(float) throw();
# 309 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double pow(double, double) throw();
# 311 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 314 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double modf(double, double *) throw();
# 316 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float modff(float, float *) throw();
# 319 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmod(double, double) throw();
# 321 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();
# 324 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remainder(double, double) throw();
# 326 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();
# 329 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();
# 331 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();
# 334 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erf(double) throw();
# 336 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erff(float) throw();
# 339 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfc(double) throw();
# 341 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcf(float) throw();
# 344 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double lgamma(double) throw();
# 346 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float lgammaf(float) throw();
# 349 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tgamma(double) throw();
# 351 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tgammaf(float) throw();
# 354 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));
# 356 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));
# 359 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));
# 361 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));
# 364 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));
# 366 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));
# 369 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 371 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 374 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
# 376 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 390 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 392 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 394 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__));
# 399 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__));
# 402 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();
# 404 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw();
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
# 32 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acos(double) throw(); extern "C" double __acos(double) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double asin(double) throw(); extern "C" double __asin(double) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atan(double) throw(); extern "C" double __atan(double) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cos(double) throw(); extern "C" double __cos(double) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sin(double) throw(); extern "C" double __sin(double) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tan(double) throw(); extern "C" double __tan(double) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cosh(double) throw(); extern "C" double __cosh(double) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sinh(double) throw(); extern "C" double __sinh(double) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tanh(double) throw(); extern "C" double __tanh(double) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acosh(double) throw(); extern "C" double __acosh(double) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double asinh(double) throw(); extern "C" double __asinh(double) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double atanh(double) throw(); extern "C" double __atanh(double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp(double) throw(); extern "C" double __exp(double) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log(double) throw(); extern "C" double __log(double) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log10(double) throw(); extern "C" double __log10(double) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp10(double) throw(); extern "C" double __exp10(double) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double expm1(double) throw(); extern "C" double __expm1(double) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log1p(double) throw(); extern "C" double __log1p(double) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double logb(double) throw(); extern "C" double __logb(double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp2(double) throw(); extern "C" double __exp2(double) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double log2(double) throw(); extern "C" double __log2(double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finite(double) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" double significand(double) throw(); extern "C" double __significand(double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnan(double) throw() __attribute__((__const__));
# 238 "/usr/include/bits/mathcalls.h" 3
extern "C" double j0(double) throw(); extern "C" double __j0(double) throw();
# 239 "/usr/include/bits/mathcalls.h" 3
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw();
# 240 "/usr/include/bits/mathcalls.h" 3
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw();
# 241 "/usr/include/bits/mathcalls.h" 3
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw();
# 242 "/usr/include/bits/mathcalls.h" 3
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw();
# 243 "/usr/include/bits/mathcalls.h" 3
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double erf(double) throw(); extern "C" double __erf(double) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double erfc(double) throw(); extern "C" double __erfc(double) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double rint(double) throw(); extern "C" double __rint(double) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrint(double) throw(); extern "C" long __lrint(double) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lround(double) throw(); extern "C" long __lround(double) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llround(double) throw(); extern "C" long long __llround(double) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassify(double) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acosf(float) throw(); extern "C" float __acosf(float) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float asinf(float) throw(); extern "C" float __asinf(float) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atanf(float) throw(); extern "C" float __atanf(float) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float coshf(float) throw(); extern "C" float __coshf(float) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float logbf(float) throw(); extern "C" float __logbf(float) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitef(float) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnanf(float) throw() __attribute__((__const__));
# 238 "/usr/include/bits/mathcalls.h" 3
extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw();
# 239 "/usr/include/bits/mathcalls.h" 3
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw();
# 240 "/usr/include/bits/mathcalls.h" 3
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw();
# 241 "/usr/include/bits/mathcalls.h" 3
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw();
# 242 "/usr/include/bits/mathcalls.h" 3
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw();
# 243 "/usr/include/bits/mathcalls.h" 3
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float erff(float) throw(); extern "C" float __erff(float) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float rintf(float) throw(); extern "C" float __rintf(float) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyf(float) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalbf(float, float) throw(); extern "C" float __scalbf(float, float) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double) throw(); extern "C" long double __acosl(long double) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" long double asinl(long double) throw(); extern "C" long double __asinl(long double) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atanl(long double) throw(); extern "C" long double __atanl(long double) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atan2l(long double, long double) throw(); extern "C" long double __atan2l(long double, long double) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cosl(long double) throw(); extern "C" long double __cosl(long double) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sinl(long double) throw(); extern "C" long double __sinl(long double) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tanl(long double) throw(); extern "C" long double __tanl(long double) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" long double coshl(long double) throw(); extern "C" long double __coshl(long double) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sinhl(long double) throw(); extern "C" long double __sinhl(long double) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tanhl(long double) throw(); extern "C" long double __tanhl(long double) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" void sincosl(long double, long double *, long double *) throw(); extern "C" void __sincosl(long double, long double *, long double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acoshl(long double) throw(); extern "C" long double __acoshl(long double) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" long double asinhl(long double) throw(); extern "C" long double __asinhl(long double) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" long double atanhl(long double) throw(); extern "C" long double __atanhl(long double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expl(long double) throw(); extern "C" long double __expl(long double) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" long double frexpl(long double, int *) throw(); extern "C" long double __frexpl(long double, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ldexpl(long double, int) throw(); extern "C" long double __ldexpl(long double, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" long double logl(long double) throw(); extern "C" long double __logl(long double) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log10l(long double) throw(); extern "C" long double __log10l(long double) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" long double modfl(long double, long double *) throw(); extern "C" long double __modfl(long double, long double *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp10l(long double) throw(); extern "C" long double __exp10l(long double) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" long double pow10l(long double) throw(); extern "C" long double __pow10l(long double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expm1l(long double) throw(); extern "C" long double __expm1l(long double) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log1pl(long double) throw(); extern "C" long double __log1pl(long double) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" long double logbl(long double) throw(); extern "C" long double __logbl(long double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp2l(long double) throw(); extern "C" long double __exp2l(long double) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" long double log2l(long double) throw(); extern "C" long double __log2l(long double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" long double powl(long double, long double) throw(); extern "C" long double __powl(long double, long double) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" long double sqrtl(long double) throw(); extern "C" long double __sqrtl(long double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" long double hypotl(long double, long double) throw(); extern "C" long double __hypotl(long double, long double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cbrtl(long double) throw(); extern "C" long double __cbrtl(long double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ceill(long double) throw() __attribute__((__const__)); extern "C" long double __ceill(long double) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fabsl(long double) throw() __attribute__((__const__)); extern "C" long double __fabsl(long double) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" long double floorl(long double) throw() __attribute__((__const__)); extern "C" long double __floorl(long double) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmodl(long double, long double) throw(); extern "C" long double __fmodl(long double, long double) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinfl(long double) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitel(long double) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" long double dreml(long double, long double) throw(); extern "C" long double __dreml(long double, long double) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" long double significandl(long double) throw(); extern "C" long double __significandl(long double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" long double copysignl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __copysignl(long double, long double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nanl(const char *) throw() __attribute__((__const__)); extern "C" long double __nanl(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 235 "/usr/include/bits/mathcalls.h" 3
extern "C" int isnanl(long double) throw() __attribute__((__const__));
# 238 "/usr/include/bits/mathcalls.h" 3
extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw();
# 239 "/usr/include/bits/mathcalls.h" 3
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw();
# 240 "/usr/include/bits/mathcalls.h" 3
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw();
# 241 "/usr/include/bits/mathcalls.h" 3
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw();
# 242 "/usr/include/bits/mathcalls.h" 3
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw();
# 243 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" long double lgammal_r(long double, int *) throw(); extern "C" long double __lgammal_r(long double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" long double rintl(long double) throw(); extern "C" long double __rintl(long double) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nextafterl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nextafterl(long double, long double) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nexttowardl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nexttowardl(long double, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" long double remainderl(long double, long double) throw(); extern "C" long double __remainderl(long double, long double) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbnl(long double, int) throw(); extern "C" long double __scalbnl(long double, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" int ilogbl(long double) throw(); extern "C" int __ilogbl(long double) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalblnl(long double, long) throw(); extern "C" long double __scalblnl(long double, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nearbyintl(long double) throw(); extern "C" long double __nearbyintl(long double) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" long double roundl(long double) throw() __attribute__((__const__)); extern "C" long double __roundl(long double) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" long double truncl(long double) throw() __attribute__((__const__)); extern "C" long double __truncl(long double) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" long double remquol(long double, long double, int *) throw(); extern "C" long double __remquol(long double, long double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrintl(long double) throw(); extern "C" long __lrintl(long double) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llrintl(long double) throw(); extern "C" long long __llrintl(long double) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" long lroundl(long double) throw(); extern "C" long __lroundl(long double) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" long long llroundl(long double) throw(); extern "C" long long __llroundl(long double) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fdiml(long double, long double) throw(); extern "C" long double __fdiml(long double, long double) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmaxl(long double, long double) throw(); extern "C" long double __fmaxl(long double, long double) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fminl(long double, long double) throw(); extern "C" long double __fminl(long double, long double) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyl(long double) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw();
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 199 "/usr/include/math.h" 3
enum __cuda_FP_NAN {
# 200 "/usr/include/math.h" 3
FP_NAN,
# 202 "/usr/include/math.h" 3
FP_INFINITE,
# 204 "/usr/include/math.h" 3
FP_ZERO,
# 206 "/usr/include/math.h" 3
FP_SUBNORMAL,
# 208 "/usr/include/math.h" 3
FP_NORMAL
# 210 "/usr/include/math.h" 3
};
# 291 "/usr/include/math.h" 3
extern "C" { typedef
# 285 "/usr/include/math.h" 3
enum {
# 286 "/usr/include/math.h" 3
_IEEE_ = (-1),
# 287 "/usr/include/math.h" 3
_SVID_,
# 288 "/usr/include/math.h" 3
_XOPEN_,
# 289 "/usr/include/math.h" 3
_POSIX_,
# 290 "/usr/include/math.h" 3
_ISOC_
# 291 "/usr/include/math.h" 3
} _LIB_VERSION_TYPE; }
# 296 "/usr/include/math.h" 3
extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; }
# 307 "/usr/include/math.h" 3
extern "C" { struct __exception {
# 312 "/usr/include/math.h" 3
int type;
# 313 "/usr/include/math.h" 3
char *name;
# 314 "/usr/include/math.h" 3
double arg1;
# 315 "/usr/include/math.h" 3
double arg2;
# 316 "/usr/include/math.h" 3
double retval;
# 317 "/usr/include/math.h" 3
}; }
# 320 "/usr/include/math.h" 3
extern "C" int matherr(__exception *) throw();
# 67 "/usr/include/bits/waitstatus.h" 3
extern "C" { union wait {
# 69 "/usr/include/bits/waitstatus.h" 3
int w_status;
# 71 "/usr/include/bits/waitstatus.h" 3
struct {
# 73 "/usr/include/bits/waitstatus.h" 3
unsigned __w_termsig:7;
# 74 "/usr/include/bits/waitstatus.h" 3
unsigned __w_coredump:1;
# 75 "/usr/include/bits/waitstatus.h" 3
unsigned __w_retcode:8;
# 76 "/usr/include/bits/waitstatus.h" 3
unsigned:16;
# 84 "/usr/include/bits/waitstatus.h" 3
} __wait_terminated;
# 86 "/usr/include/bits/waitstatus.h" 3
struct {
# 88 "/usr/include/bits/waitstatus.h" 3
unsigned __w_stopval:8;
# 89 "/usr/include/bits/waitstatus.h" 3
unsigned __w_stopsig:8;
# 90 "/usr/include/bits/waitstatus.h" 3
unsigned:16;
# 97 "/usr/include/bits/waitstatus.h" 3
} __wait_stopped;
# 98 "/usr/include/bits/waitstatus.h" 3
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 99 "/usr/include/stdlib.h" 3
struct div_t {
# 100 "/usr/include/stdlib.h" 3
int quot;
# 101 "/usr/include/stdlib.h" 3
int rem;
# 102 "/usr/include/stdlib.h" 3
} div_t; }
# 110 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 107 "/usr/include/stdlib.h" 3
struct ldiv_t {
# 108 "/usr/include/stdlib.h" 3
long quot;
# 109 "/usr/include/stdlib.h" 3
long rem;
# 110 "/usr/include/stdlib.h" 3
} ldiv_t; }
# 122 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 119 "/usr/include/stdlib.h" 3
struct lldiv_t {
# 120 "/usr/include/stdlib.h" 3
long long quot;
# 121 "/usr/include/stdlib.h" 3
long long rem;
# 122 "/usr/include/stdlib.h" 3
} lldiv_t; }
# 140 "/usr/include/stdlib.h" 3
extern "C" size_t __ctype_get_mb_cur_max() throw();
# 145 "/usr/include/stdlib.h" 3
extern "C" double atof(const char *) throw() __attribute__((__pure__));
# 148 "/usr/include/stdlib.h" 3
extern "C" int atoi(const char *) throw() __attribute__((__pure__));
# 151 "/usr/include/stdlib.h" 3
extern "C" long atol(const char *) throw() __attribute__((__pure__));
# 158 "/usr/include/stdlib.h" 3
extern "C" long long atoll(const char *) throw() __attribute__((__pure__));
# 165 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw();
# 173 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw();
# 176 "/usr/include/stdlib.h" 3
extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw();
# 184 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw();
# 188 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw();
# 196 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw();
# 201 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw();
# 210 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw();
# 215 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw();
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 244 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 250 "/usr/include/stdlib.h" 3
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 256 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 261 "/usr/include/stdlib.h" 3
extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw();
# 265 "/usr/include/stdlib.h" 3
extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw();
# 269 "/usr/include/stdlib.h" 3
extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw();
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long) throw();
# 314 "/usr/include/stdlib.h" 3
extern "C" long a64l(const char *) throw() __attribute__((__pure__));
# 35 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
# 36 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_short u_short; }
# 37 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_int u_int; }
# 38 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_long u_long; }
# 39 "/usr/include/sys/types.h" 3
extern "C" { typedef __quad_t quad_t; }
# 40 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_quad_t u_quad_t; }
# 41 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsid_t fsid_t; }
# 46 "/usr/include/sys/types.h" 3
extern "C" { typedef __loff_t loff_t; }
# 50 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino_t ino_t; }
# 57 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino64_t ino64_t; }
# 62 "/usr/include/sys/types.h" 3
extern "C" { typedef __dev_t dev_t; }
# 67 "/usr/include/sys/types.h" 3
extern "C" { typedef __gid_t gid_t; }
# 72 "/usr/include/sys/types.h" 3
extern "C" { typedef __mode_t mode_t; }
# 77 "/usr/include/sys/types.h" 3
extern "C" { typedef __nlink_t nlink_t; }
# 82 "/usr/include/sys/types.h" 3
extern "C" { typedef __uid_t uid_t; }
# 88 "/usr/include/sys/types.h" 3
extern "C" { typedef __off_t off_t; }
# 95 "/usr/include/sys/types.h" 3
extern "C" { typedef __off64_t off64_t; }
# 105 "/usr/include/sys/types.h" 3
extern "C" { typedef __id_t id_t; }
# 110 "/usr/include/sys/types.h" 3
extern "C" { typedef __ssize_t ssize_t; }
# 116 "/usr/include/sys/types.h" 3
extern "C" { typedef __daddr_t daddr_t; }
# 117 "/usr/include/sys/types.h" 3
extern "C" { typedef __caddr_t caddr_t; }
# 123 "/usr/include/sys/types.h" 3
extern "C" { typedef __key_t key_t; }
# 137 "/usr/include/sys/types.h" 3
extern "C" { typedef __useconds_t useconds_t; }
# 141 "/usr/include/sys/types.h" 3
extern "C" { typedef __suseconds_t suseconds_t; }
# 151 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long ulong; }
# 152 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned short ushort; }
# 153 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned uint; }
# 195 "/usr/include/sys/types.h" 3
extern "C" { typedef signed char int8_t; }
# 196 "/usr/include/sys/types.h" 3
extern "C" { typedef short int16_t; }
# 197 "/usr/include/sys/types.h" 3
extern "C" { typedef int int32_t; }
# 198 "/usr/include/sys/types.h" 3
extern "C" { typedef long int64_t; }
# 201 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned char u_int8_t; }
# 202 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned short u_int16_t; }
# 203 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned u_int32_t; }
# 204 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long u_int64_t; }
# 206 "/usr/include/sys/types.h" 3
extern "C" { typedef int register_t; }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32 "/usr/include/bits/sigset.h" 3
extern "C" { typedef
# 30 "/usr/include/bits/sigset.h" 3
struct __sigset_t {
# 31 "/usr/include/bits/sigset.h" 3
unsigned long __val[((1024) / ((8) * sizeof(unsigned long)))];
# 32 "/usr/include/bits/sigset.h" 3
} __sigset_t; }
# 38 "/usr/include/sys/select.h" 3
extern "C" { typedef __sigset_t sigset_t; }
# 69 "/usr/include/bits/time.h" 3
extern "C" { struct timeval {
# 71 "/usr/include/bits/time.h" 3
__time_t tv_sec;
# 72 "/usr/include/bits/time.h" 3
__suseconds_t tv_usec;
# 73 "/usr/include/bits/time.h" 3
}; }
# 55 "/usr/include/sys/select.h" 3
extern "C" { typedef long __fd_mask; }
# 78 "/usr/include/sys/select.h" 3
extern "C" { typedef
# 68 "/usr/include/sys/select.h" 3
struct fd_set {
# 72 "/usr/include/sys/select.h" 3
__fd_mask fds_bits[((1024) / ((8) * sizeof(__fd_mask)))];
# 78 "/usr/include/sys/select.h" 3
} fd_set; }
# 85 "/usr/include/sys/select.h" 3
extern "C" { typedef __fd_mask fd_mask; }
# 109 "/usr/include/sys/select.h" 3
extern "C" int select(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, timeval *__restrict__);
# 121 "/usr/include/sys/select.h" 3
extern "C" int pselect(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, const timespec *__restrict__, const __sigset_t *__restrict__);
# 31 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned gnu_dev_major(unsigned long long) throw();
# 34 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned gnu_dev_minor(unsigned long long) throw();
# 37 "/usr/include/sys/sysmacros.h" 3
extern "C" unsigned long long gnu_dev_makedev(unsigned, unsigned) throw();
# 228 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 235 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt_t blkcnt_t; }
# 239 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }
# 243 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 262 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
# 263 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
# 264 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 54 "/usr/include/bits/pthreadtypes.h" 3
union pthread_attr_t {
# 55 "/usr/include/bits/pthreadtypes.h" 3
char __size[56];
# 56 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 57 "/usr/include/bits/pthreadtypes.h" 3
} pthread_attr_t; }
# 65 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 61 "/usr/include/bits/pthreadtypes.h" 3
struct __pthread_internal_list {
# 63 "/usr/include/bits/pthreadtypes.h" 3
__pthread_internal_list *__prev;
# 64 "/usr/include/bits/pthreadtypes.h" 3
__pthread_internal_list *__next;
# 65 "/usr/include/bits/pthreadtypes.h" 3
} __pthread_list_t; }
# 104 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 77 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutex_t {
# 78 "/usr/include/bits/pthreadtypes.h" 3
struct __pthread_mutex_s {
# 80 "/usr/include/bits/pthreadtypes.h" 3
int __lock;
# 81 "/usr/include/bits/pthreadtypes.h" 3
unsigned __count;
# 82 "/usr/include/bits/pthreadtypes.h" 3
int __owner;
# 84 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nusers;
# 88 "/usr/include/bits/pthreadtypes.h" 3
int __kind;
# 90 "/usr/include/bits/pthreadtypes.h" 3
int __spins;
# 91 "/usr/include/bits/pthreadtypes.h" 3
__pthread_list_t __list;
# 101 "/usr/include/bits/pthreadtypes.h" 3
} __data;
# 102 "/usr/include/bits/pthreadtypes.h" 3
char __size[40];
# 103 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 104 "/usr/include/bits/pthreadtypes.h" 3
} pthread_mutex_t; }
# 110 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 107 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutexattr_t {
# 108 "/usr/include/bits/pthreadtypes.h" 3
char __size[4];
# 109 "/usr/include/bits/pthreadtypes.h" 3
int __align;
# 110 "/usr/include/bits/pthreadtypes.h" 3
} pthread_mutexattr_t; }
# 130 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 116 "/usr/include/bits/pthreadtypes.h" 3
union pthread_cond_t {
# 118 "/usr/include/bits/pthreadtypes.h" 3
struct {
# 119 "/usr/include/bits/pthreadtypes.h" 3
int __lock;
# 120 "/usr/include/bits/pthreadtypes.h" 3
unsigned __futex;
# 121 "/usr/include/bits/pthreadtypes.h" 3
unsigned long long __total_seq;
# 122 "/usr/include/bits/pthreadtypes.h" 3
unsigned long long __wakeup_seq;
# 123 "/usr/include/bits/pthreadtypes.h" 3
unsigned long long __woken_seq;
# 124 "/usr/include/bits/pthreadtypes.h" 3
void *__mutex;
# 125 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nwaiters;
# 126 "/usr/include/bits/pthreadtypes.h" 3
unsigned __broadcast_seq;
# 127 "/usr/include/bits/pthreadtypes.h" 3
} __data;
# 128 "/usr/include/bits/pthreadtypes.h" 3
char __size[48];
# 129 "/usr/include/bits/pthreadtypes.h" 3
long long __align;
# 130 "/usr/include/bits/pthreadtypes.h" 3
} pthread_cond_t; }
# 136 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 133 "/usr/include/bits/pthreadtypes.h" 3
union pthread_condattr_t {
# 134 "/usr/include/bits/pthreadtypes.h" 3
char __size[4];
# 135 "/usr/include/bits/pthreadtypes.h" 3
int __align;
# 136 "/usr/include/bits/pthreadtypes.h" 3
} pthread_condattr_t; }
# 140 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned pthread_key_t; }
# 144 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef int pthread_once_t; }
# 189 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 151 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlock_t {
# 154 "/usr/include/bits/pthreadtypes.h" 3
struct {
# 155 "/usr/include/bits/pthreadtypes.h" 3
int __lock;
# 156 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_readers;
# 157 "/usr/include/bits/pthreadtypes.h" 3
unsigned __readers_wakeup;
# 158 "/usr/include/bits/pthreadtypes.h" 3
unsigned __writer_wakeup;
# 159 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_readers_queued;
# 160 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_writers_queued;
# 161 "/usr/include/bits/pthreadtypes.h" 3
int __writer;
# 162 "/usr/include/bits/pthreadtypes.h" 3
int __shared;
# 163 "/usr/include/bits/pthreadtypes.h" 3
unsigned long __pad1;
# 164 "/usr/include/bits/pthreadtypes.h" 3
unsigned long __pad2;
# 167 "/usr/include/bits/pthreadtypes.h" 3
unsigned __flags;
# 168 "/usr/include/bits/pthreadtypes.h" 3
} __data;
# 187 "/usr/include/bits/pthreadtypes.h" 3
char __size[56];
# 188 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 189 "/usr/include/bits/pthreadtypes.h" 3
} pthread_rwlock_t; }
# 195 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 192 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlockattr_t {
# 193 "/usr/include/bits/pthreadtypes.h" 3
char __size[8];
# 194 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 195 "/usr/include/bits/pthreadtypes.h" 3
} pthread_rwlockattr_t; }
# 201 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 207 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrier_t {
# 208 "/usr/include/bits/pthreadtypes.h" 3
char __size[32];
# 209 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 210 "/usr/include/bits/pthreadtypes.h" 3
} pthread_barrier_t; }
# 216 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 213 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrierattr_t {
# 214 "/usr/include/bits/pthreadtypes.h" 3
char __size[4];
# 215 "/usr/include/bits/pthreadtypes.h" 3
int __align;
# 216 "/usr/include/bits/pthreadtypes.h" 3
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw();
# 330 "/usr/include/stdlib.h" 3
extern "C" void srandom(unsigned) throw();
# 336 "/usr/include/stdlib.h" 3
extern "C" char *initstate(unsigned, char *, size_t) throw();
# 341 "/usr/include/stdlib.h" 3
extern "C" char *setstate(char *) throw();
# 349 "/usr/include/stdlib.h" 3
extern "C" { struct random_data {
# 351 "/usr/include/stdlib.h" 3
int32_t *fptr;
# 352 "/usr/include/stdlib.h" 3
int32_t *rptr;
# 353 "/usr/include/stdlib.h" 3
int32_t *state;
# 354 "/usr/include/stdlib.h" 3
int rand_type;
# 355 "/usr/include/stdlib.h" 3
int rand_deg;
# 356 "/usr/include/stdlib.h" 3
int rand_sep;
# 357 "/usr/include/stdlib.h" 3
int32_t *end_ptr;
# 358 "/usr/include/stdlib.h" 3
}; }
# 360 "/usr/include/stdlib.h" 3
extern "C" int random_r(random_data *__restrict__, int32_t *__restrict__) throw();
# 363 "/usr/include/stdlib.h" 3
extern "C" int srandom_r(unsigned, random_data *) throw();
# 366 "/usr/include/stdlib.h" 3
extern "C" int initstate_r(unsigned, char *__restrict__, size_t, random_data *__restrict__) throw();
# 371 "/usr/include/stdlib.h" 3
extern "C" int setstate_r(char *__restrict__, random_data *__restrict__) throw();
# 380 "/usr/include/stdlib.h" 3
extern "C" int rand() throw();
# 382 "/usr/include/stdlib.h" 3
extern "C" void srand(unsigned) throw();
# 387 "/usr/include/stdlib.h" 3
extern "C" int rand_r(unsigned *) throw();
# 395 "/usr/include/stdlib.h" 3
extern "C" double drand48() throw();
# 396 "/usr/include/stdlib.h" 3
extern "C" double erand48(unsigned short [3]) throw();
# 399 "/usr/include/stdlib.h" 3
extern "C" long lrand48() throw();
# 400 "/usr/include/stdlib.h" 3
extern "C" long nrand48(unsigned short [3]) throw();
# 404 "/usr/include/stdlib.h" 3
extern "C" long mrand48() throw();
# 405 "/usr/include/stdlib.h" 3
extern "C" long jrand48(unsigned short [3]) throw();
# 409 "/usr/include/stdlib.h" 3
extern "C" void srand48(long) throw();
# 410 "/usr/include/stdlib.h" 3
extern "C" unsigned short *seed48(unsigned short [3]) throw();
# 412 "/usr/include/stdlib.h" 3
extern "C" void lcong48(unsigned short [7]) throw();
# 418 "/usr/include/stdlib.h" 3
extern "C" { struct drand48_data {
# 420 "/usr/include/stdlib.h" 3
unsigned short __x[3];
# 421 "/usr/include/stdlib.h" 3
unsigned short __old_x[3];
# 422 "/usr/include/stdlib.h" 3
unsigned short __c;
# 423 "/usr/include/stdlib.h" 3
unsigned short __init;
# 424 "/usr/include/stdlib.h" 3
unsigned long long __a;
# 425 "/usr/include/stdlib.h" 3
}; }
# 428 "/usr/include/stdlib.h" 3
extern "C" int drand48_r(drand48_data *__restrict__, double *__restrict__) throw();
# 430 "/usr/include/stdlib.h" 3
extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__, double *__restrict__) throw();
# 435 "/usr/include/stdlib.h" 3
extern "C" int lrand48_r(drand48_data *__restrict__, long *__restrict__) throw();
# 438 "/usr/include/stdlib.h" 3
extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 444 "/usr/include/stdlib.h" 3
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw();
# 447 "/usr/include/stdlib.h" 3
extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 453 "/usr/include/stdlib.h" 3
extern "C" int srand48_r(long, drand48_data *) throw();
# 456 "/usr/include/stdlib.h" 3
extern "C" int seed48_r(unsigned short [3], drand48_data *) throw();
# 459 "/usr/include/stdlib.h" 3
extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw();
# 471 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__));
# 473 "/usr/include/stdlib.h" 3
extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__));
# 485 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void *, size_t) throw();
# 488 "/usr/include/stdlib.h" 3
extern "C" void free(void *) throw();
# 493 "/usr/include/stdlib.h" 3
extern "C" void cfree(void *) throw();
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw();
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__));
# 507 "/usr/include/stdlib.h" 3
extern "C" int posix_memalign(void **, size_t, size_t) throw();
# 513 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute__((__noreturn__));
# 517 "/usr/include/stdlib.h" 3
extern "C" int atexit(void (*)(void)) throw();
# 523 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw();
# 531 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 538 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 545 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw();
# 550 "/usr/include/stdlib.h" 3
extern "C" char *__secure_getenv(const char *) throw();
# 557 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw();
# 563 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw();
# 567 "/usr/include/stdlib.h" 3
extern "C" int unsetenv(const char *) throw();
# 574 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 583 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *) throw();
# 594 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *);
# 604 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *);
# 614 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw();
# 625 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int);
# 635 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int);
# 645 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 652 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw();
# 662 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 670 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 673 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 677 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 683 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);
# 689 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t);
# 692 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *);
# 699 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 700 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 704 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 713 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));
# 715 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 721 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 735 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw();
# 741 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw();
# 747 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw();
# 753 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw();
# 756 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw();
# 759 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double, int, char *) throw();
# 765 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 768 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 772 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 776 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 787 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();
# 790 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 794 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t) throw();
# 798 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 801 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 812 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw();
# 823 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw();
# 832 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw();
# 840 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 848 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();
# 852 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int) throw();
# 857 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int) throw();
# 864 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw();
# 868 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 875 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 74 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 76 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container> class __normal_iterator;
# 79 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
}
# 81 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
namespace std __attribute__((visibility("default"))) {
# 83 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __true_type { };
# 84 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __false_type { };
# 86 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<bool >
# 87 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __truth_type {
# 88 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 91 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 92 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 96 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Sp, class _Tp>
# 97 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __traitor {
# 99 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
# 100 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef typename __truth_type< (((bool)_Sp::__value) || ((bool)_Tp::__value))> ::__type __type;
# 101 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 105 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Sp, class _Tp>
# 106 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __traitand {
# 108 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = (((bool)_Sp::__value) && ((bool)_Tp::__value))};
# 109 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef typename __truth_type< (((bool)_Sp::__value) && ((bool)_Tp::__value))> ::__type __type;
# 110 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 113 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class , class >
# 114 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __are_same {
# 116 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 117 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 118 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 120 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 121 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 123 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 124 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 125 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 128 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 129 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_void {
# 131 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 132 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 133 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 136 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_void< void> {
# 138 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 139 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 140 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 145 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 146 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_integer {
# 148 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 149 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 150 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 156 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {
# 158 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 159 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 160 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 163 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< char> {
# 165 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 166 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 167 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 170 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< signed char> {
# 172 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 173 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 174 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 177 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned char> {
# 179 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 180 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 181 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 185 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< wchar_t> {
# 187 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 188 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 189 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 193 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< short> {
# 195 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 196 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 197 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 200 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned short> {
# 202 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 203 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 204 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 207 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< int> {
# 209 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 210 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 211 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 214 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned> {
# 216 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 217 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 218 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 221 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long> {
# 223 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 224 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 225 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 228 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long> {
# 230 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 231 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 232 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 235 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long long> {
# 237 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 238 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 239 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 242 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long long> {
# 244 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 245 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 246 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 251 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 252 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_floating {
# 254 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 255 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 256 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 260 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_floating< float> {
# 262 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 263 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 264 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 267 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_floating< double> {
# 269 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 270 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 271 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 274 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_floating< long double> {
# 276 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 277 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 278 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 283 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 284 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 286 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 287 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 288 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 290 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 291 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 293 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 294 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 295 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 300 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 301 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 303 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 304 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 305 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 307 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container>
# 308 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 311 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 312 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 313 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 318 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 319 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 321 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 326 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 327 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 329 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 334 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 335 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 337 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 342 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 343 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_char {
# 345 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 346 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 347 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 350 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_char< char> {
# 352 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 353 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 354 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 358 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_char< wchar_t> {
# 360 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 361 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 362 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 365 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 366 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_byte {
# 368 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 369 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 370 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 373 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_byte< char> {
# 375 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 376 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 377 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 380 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_byte< signed char> {
# 382 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 383 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 384 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 387 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_byte< unsigned char> {
# 389 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value = 1};
# 390 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 391 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 396 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<class _Tp>
# 397 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
struct __is_move_iterator {
# 399 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
enum __cuda___value { __value};
# 400 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 401 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
};
# 415 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
}
# 43 "/usr/include/c++/4.3/ext/type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 46 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<bool , class >
# 47 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __enable_if {
# 48 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 50 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp>
# 51 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 52 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef _Tp __type; };
# 56 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<bool _Cond, class _Iftrue, class _Iffalse>
# 57 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __conditional_type {
# 58 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 60 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Iftrue, class _Iffalse>
# 61 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 62 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 66 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp>
# 67 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __add_unsigned {
# 70 "/usr/include/c++/4.3/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 73 "/usr/include/c++/4.3/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 74 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 77 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< char> {
# 78 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned char __type; };
# 81 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< signed char> {
# 82 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned char __type; };
# 85 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< short> {
# 86 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned short __type; };
# 89 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< int> {
# 90 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned __type; };
# 93 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< long> {
# 94 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned long __type; };
# 97 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< long long> {
# 98 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef unsigned long long __type; };
# 102 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< bool> ;
# 105 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __add_unsigned< wchar_t> ;
# 109 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp>
# 110 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __remove_unsigned {
# 113 "/usr/include/c++/4.3/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 116 "/usr/include/c++/4.3/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 117 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 120 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< char> {
# 121 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef signed char __type; };
# 124 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned char> {
# 125 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef signed char __type; };
# 128 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned short> {
# 129 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef short __type; };
# 132 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned> {
# 133 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef int __type; };
# 136 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long> {
# 137 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef long __type; };
# 140 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long long> {
# 141 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef long long __type; };
# 145 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< bool> ;
# 148 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<> struct __remove_unsigned< wchar_t> ;
# 152 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Type> inline bool
# 154 "/usr/include/c++/4.3/ext/type_traits.h" 3
__is_null_pointer(_Type *__ptr)
# 155 "/usr/include/c++/4.3/ext/type_traits.h" 3
{ return __ptr == 0; }
# 157 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Type> inline bool
# 159 "/usr/include/c++/4.3/ext/type_traits.h" 3
__is_null_pointer(_Type)
# 160 "/usr/include/c++/4.3/ext/type_traits.h" 3
{ return false; }
# 164 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp, bool = std::__is_integer< _Tp> ::__value>
# 165 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __promote {
# 166 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef double __type; };
# 168 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp>
# 169 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __promote< _Tp, false> {
# 170 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef _Tp __type; };
# 172 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp, class _Up>
# 173 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __promote_2 {
# 176 "/usr/include/c++/4.3/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 177 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 180 "/usr/include/c++/4.3/ext/type_traits.h" 3
public: typedef __typeof__((__type1() + __type2())) __type;
# 181 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 183 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp, class _Up, class _Vp>
# 184 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __promote_3 {
# 187 "/usr/include/c++/4.3/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 188 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 189 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 192 "/usr/include/c++/4.3/ext/type_traits.h" 3
public: typedef __typeof__(((__type1() + __type2()) + __type3())) __type;
# 193 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 195 "/usr/include/c++/4.3/ext/type_traits.h" 3
template<class _Tp, class _Up, class _Vp, class _Wp>
# 196 "/usr/include/c++/4.3/ext/type_traits.h" 3
struct __promote_4 {
# 199 "/usr/include/c++/4.3/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 200 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 201 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 202 "/usr/include/c++/4.3/ext/type_traits.h" 3
typedef typename __promote< _Wp, std::__is_integer< _Wp> ::__value> ::__type __type4;
# 205 "/usr/include/c++/4.3/ext/type_traits.h" 3
public: typedef __typeof__((((__type1() + __type2()) + __type3()) + __type4())) __type;
# 206 "/usr/include/c++/4.3/ext/type_traits.h" 3
};
# 208 "/usr/include/c++/4.3/ext/type_traits.h" 3
}
# 82 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {
# 86 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> extern inline _Tp __cmath_power(_Tp, unsigned);
# 89 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline _Tp
# 91 "/usr/include/c++/4.3/cmath" 3
__pow_helper(_Tp __x, int __n)
# 92 "/usr/include/c++/4.3/cmath" 3
{
# 93 "/usr/include/c++/4.3/cmath" 3
return (__n < 0) ? (((_Tp)(1)) / __cmath_power(__x, -__n)) : (__cmath_power(__x, __n));
# 96 "/usr/include/c++/4.3/cmath" 3
}
# 99 "/usr/include/c++/4.3/cmath" 3
inline double abs(double __x)
# 100 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabs(__x); }
# 103 "/usr/include/c++/4.3/cmath" 3
inline float abs(float __x)
# 104 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabsf(__x); }
# 107 "/usr/include/c++/4.3/cmath" 3
inline long double abs(long double __x)
# 108 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabsl(__x); }
# 110 "/usr/include/c++/4.3/cmath" 3
using ::acos;
# 113 "/usr/include/c++/4.3/cmath" 3
inline float acos(float __x)
# 114 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_acosf(__x); }
# 117 "/usr/include/c++/4.3/cmath" 3
inline long double acos(long double __x)
# 118 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_acosl(__x); }
# 120 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 123 "/usr/include/c++/4.3/cmath" 3
acos(_Tp __x)
# 124 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_acos(__x); }
# 126 "/usr/include/c++/4.3/cmath" 3
using ::asin;
# 129 "/usr/include/c++/4.3/cmath" 3
inline float asin(float __x)
# 130 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_asinf(__x); }
# 133 "/usr/include/c++/4.3/cmath" 3
inline long double asin(long double __x)
# 134 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_asinl(__x); }
# 136 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 139 "/usr/include/c++/4.3/cmath" 3
asin(_Tp __x)
# 140 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_asin(__x); }
# 142 "/usr/include/c++/4.3/cmath" 3
using ::atan;
# 145 "/usr/include/c++/4.3/cmath" 3
inline float atan(float __x)
# 146 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_atanf(__x); }
# 149 "/usr/include/c++/4.3/cmath" 3
inline long double atan(long double __x)
# 150 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_atanl(__x); }
# 152 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 155 "/usr/include/c++/4.3/cmath" 3
atan(_Tp __x)
# 156 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_atan(__x); }
# 158 "/usr/include/c++/4.3/cmath" 3
using ::atan2;
# 161 "/usr/include/c++/4.3/cmath" 3
inline float atan2(float __y, float __x)
# 162 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_atan2f(__y, __x); }
# 165 "/usr/include/c++/4.3/cmath" 3
inline long double atan2(long double __y, long double __x)
# 166 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_atan2l(__y, __x); }
# 168 "/usr/include/c++/4.3/cmath" 3
template<class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< typename __gnu_cxx::__enable_if< (__traitand< __is_arithmetic< _Tp> , __is_arithmetic< _Up> > ::__value), _Tp> ::__type, _Up> ::__type
# 174 "/usr/include/c++/4.3/cmath" 3
atan2(_Tp __y, _Up __x)
# 175 "/usr/include/c++/4.3/cmath" 3
{
# 176 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type;
# 177 "/usr/include/c++/4.3/cmath" 3
return atan2(((__type)(__y)), ((__type)(__x)));
# 178 "/usr/include/c++/4.3/cmath" 3
}
# 180 "/usr/include/c++/4.3/cmath" 3
using ::ceil;
# 183 "/usr/include/c++/4.3/cmath" 3
inline float ceil(float __x)
# 184 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ceilf(__x); }
# 187 "/usr/include/c++/4.3/cmath" 3
inline long double ceil(long double __x)
# 188 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ceill(__x); }
# 190 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 193 "/usr/include/c++/4.3/cmath" 3
ceil(_Tp __x)
# 194 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ceil(__x); }
# 196 "/usr/include/c++/4.3/cmath" 3
using ::cos;
# 199 "/usr/include/c++/4.3/cmath" 3
inline float cos(float __x)
# 200 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_cosf(__x); }
# 203 "/usr/include/c++/4.3/cmath" 3
inline long double cos(long double __x)
# 204 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_cosl(__x); }
# 206 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 209 "/usr/include/c++/4.3/cmath" 3
cos(_Tp __x)
# 210 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_cos(__x); }
# 212 "/usr/include/c++/4.3/cmath" 3
using ::cosh;
# 215 "/usr/include/c++/4.3/cmath" 3
inline float cosh(float __x)
# 216 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_coshf(__x); }
# 219 "/usr/include/c++/4.3/cmath" 3
inline long double cosh(long double __x)
# 220 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_coshl(__x); }
# 222 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 225 "/usr/include/c++/4.3/cmath" 3
cosh(_Tp __x)
# 226 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_cosh(__x); }
# 228 "/usr/include/c++/4.3/cmath" 3
using ::exp;
# 231 "/usr/include/c++/4.3/cmath" 3
inline float exp(float __x)
# 232 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_expf(__x); }
# 235 "/usr/include/c++/4.3/cmath" 3
inline long double exp(long double __x)
# 236 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_expl(__x); }
# 238 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 241 "/usr/include/c++/4.3/cmath" 3
exp(_Tp __x)
# 242 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_exp(__x); }
# 244 "/usr/include/c++/4.3/cmath" 3
using ::fabs;
# 247 "/usr/include/c++/4.3/cmath" 3
inline float fabs(float __x)
# 248 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabsf(__x); }
# 251 "/usr/include/c++/4.3/cmath" 3
inline long double fabs(long double __x)
# 252 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabsl(__x); }
# 254 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 257 "/usr/include/c++/4.3/cmath" 3
fabs(_Tp __x)
# 258 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fabs(__x); }
# 260 "/usr/include/c++/4.3/cmath" 3
using ::floor;
# 263 "/usr/include/c++/4.3/cmath" 3
inline float floor(float __x)
# 264 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_floorf(__x); }
# 267 "/usr/include/c++/4.3/cmath" 3
inline long double floor(long double __x)
# 268 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_floorl(__x); }
# 270 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 273 "/usr/include/c++/4.3/cmath" 3
floor(_Tp __x)
# 274 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_floor(__x); }
# 276 "/usr/include/c++/4.3/cmath" 3
using ::fmod;
# 279 "/usr/include/c++/4.3/cmath" 3
inline float fmod(float __x, float __y)
# 280 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fmodf(__x, __y); }
# 283 "/usr/include/c++/4.3/cmath" 3
inline long double fmod(long double __x, long double __y)
# 284 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_fmodl(__x, __y); }
# 286 "/usr/include/c++/4.3/cmath" 3
using ::frexp;
# 289 "/usr/include/c++/4.3/cmath" 3
inline float frexp(float __x, int *__exp)
# 290 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_frexpf(__x, __exp); }
# 293 "/usr/include/c++/4.3/cmath" 3
inline long double frexp(long double __x, int *__exp)
# 294 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_frexpl(__x, __exp); }
# 296 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 299 "/usr/include/c++/4.3/cmath" 3
frexp(_Tp __x, int *__exp)
# 300 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_frexp(__x, __exp); }
# 302 "/usr/include/c++/4.3/cmath" 3
using ::ldexp;
# 305 "/usr/include/c++/4.3/cmath" 3
inline float ldexp(float __x, int __exp)
# 306 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ldexpf(__x, __exp); }
# 309 "/usr/include/c++/4.3/cmath" 3
inline long double ldexp(long double __x, int __exp)
# 310 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ldexpl(__x, __exp); }
# 312 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 315 "/usr/include/c++/4.3/cmath" 3
ldexp(_Tp __x, int __exp)
# 316 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_ldexp(__x, __exp); }
# 318 "/usr/include/c++/4.3/cmath" 3
using ::log;
# 321 "/usr/include/c++/4.3/cmath" 3
inline float log(float __x)
# 322 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_logf(__x); }
# 325 "/usr/include/c++/4.3/cmath" 3
inline long double log(long double __x)
# 326 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_logl(__x); }
# 328 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 331 "/usr/include/c++/4.3/cmath" 3
log(_Tp __x)
# 332 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_log(__x); }
# 334 "/usr/include/c++/4.3/cmath" 3
using ::log10;
# 337 "/usr/include/c++/4.3/cmath" 3
inline float log10(float __x)
# 338 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_log10f(__x); }
# 341 "/usr/include/c++/4.3/cmath" 3
inline long double log10(long double __x)
# 342 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_log10l(__x); }
# 344 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 347 "/usr/include/c++/4.3/cmath" 3
log10(_Tp __x)
# 348 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_log10(__x); }
# 350 "/usr/include/c++/4.3/cmath" 3
using ::modf;
# 353 "/usr/include/c++/4.3/cmath" 3
inline float modf(float __x, float *__iptr)
# 354 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_modff(__x, __iptr); }
# 357 "/usr/include/c++/4.3/cmath" 3
inline long double modf(long double __x, long double *__iptr)
# 358 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_modfl(__x, __iptr); }
# 360 "/usr/include/c++/4.3/cmath" 3
using ::pow;
# 363 "/usr/include/c++/4.3/cmath" 3
inline float pow(float __x, float __y)
# 364 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_powf(__x, __y); }
# 367 "/usr/include/c++/4.3/cmath" 3
inline long double pow(long double __x, long double __y)
# 368 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_powl(__x, __y); }
# 372 "/usr/include/c++/4.3/cmath" 3
inline double pow(double __x, int __i)
# 373 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_powi(__x, __i); }
# 376 "/usr/include/c++/4.3/cmath" 3
inline float pow(float __x, int __n)
# 377 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_powif(__x, __n); }
# 380 "/usr/include/c++/4.3/cmath" 3
inline long double pow(long double __x, int __n)
# 381 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_powil(__x, __n); }
# 383 "/usr/include/c++/4.3/cmath" 3
template<class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< typename __gnu_cxx::__enable_if< (__traitand< __is_arithmetic< _Tp> , __is_arithmetic< _Up> > ::__value), _Tp> ::__type, _Up> ::__type
# 389 "/usr/include/c++/4.3/cmath" 3
pow(_Tp __x, _Up __y)
# 390 "/usr/include/c++/4.3/cmath" 3
{
# 391 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type;
# 392 "/usr/include/c++/4.3/cmath" 3
return pow(((__type)(__x)), ((__type)(__y)));
# 393 "/usr/include/c++/4.3/cmath" 3
}
# 395 "/usr/include/c++/4.3/cmath" 3
using ::sin;
# 398 "/usr/include/c++/4.3/cmath" 3
inline float sin(float __x)
# 399 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sinf(__x); }
# 402 "/usr/include/c++/4.3/cmath" 3
inline long double sin(long double __x)
# 403 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sinl(__x); }
# 405 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 408 "/usr/include/c++/4.3/cmath" 3
sin(_Tp __x)
# 409 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sin(__x); }
# 411 "/usr/include/c++/4.3/cmath" 3
using ::sinh;
# 414 "/usr/include/c++/4.3/cmath" 3
inline float sinh(float __x)
# 415 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sinhf(__x); }
# 418 "/usr/include/c++/4.3/cmath" 3
inline long double sinh(long double __x)
# 419 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sinhl(__x); }
# 421 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 424 "/usr/include/c++/4.3/cmath" 3
sinh(_Tp __x)
# 425 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sinh(__x); }
# 427 "/usr/include/c++/4.3/cmath" 3
using ::sqrt;
# 430 "/usr/include/c++/4.3/cmath" 3
inline float sqrt(float __x)
# 431 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sqrtf(__x); }
# 434 "/usr/include/c++/4.3/cmath" 3
inline long double sqrt(long double __x)
# 435 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sqrtl(__x); }
# 437 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 440 "/usr/include/c++/4.3/cmath" 3
sqrt(_Tp __x)
# 441 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_sqrt(__x); }
# 443 "/usr/include/c++/4.3/cmath" 3
using ::tan;
# 446 "/usr/include/c++/4.3/cmath" 3
inline float tan(float __x)
# 447 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tanf(__x); }
# 450 "/usr/include/c++/4.3/cmath" 3
inline long double tan(long double __x)
# 451 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tanl(__x); }
# 453 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 456 "/usr/include/c++/4.3/cmath" 3
tan(_Tp __x)
# 457 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tan(__x); }
# 459 "/usr/include/c++/4.3/cmath" 3
using ::tanh;
# 462 "/usr/include/c++/4.3/cmath" 3
inline float tanh(float __x)
# 463 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tanhf(__x); }
# 466 "/usr/include/c++/4.3/cmath" 3
inline long double tanh(long double __x)
# 467 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tanhl(__x); }
# 469 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_integer< _Tp> ::__value), double> ::__type
# 472 "/usr/include/c++/4.3/cmath" 3
tanh(_Tp __x)
# 473 "/usr/include/c++/4.3/cmath" 3
{ return __builtin_tanh(__x); }
# 475 "/usr/include/c++/4.3/cmath" 3
}
# 483 "/usr/include/c++/4.3/cmath" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 485 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline int
# 487 "/usr/include/c++/4.3/cmath" 3
__capture_fpclassify(_Tp __f) { return (sizeof(__f) == sizeof(float)) ? (__fpclassifyf(__f)) : ((sizeof(__f) == sizeof(double)) ? (__fpclassify(__f)) : (__fpclassifyl(__f))); }
# 489 "/usr/include/c++/4.3/cmath" 3
}
# 505 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {
# 507 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 510 "/usr/include/c++/4.3/cmath" 3
fpclassify(_Tp __f)
# 511 "/usr/include/c++/4.3/cmath" 3
{
# 512 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 513 "/usr/include/c++/4.3/cmath" 3
return __gnu_cxx::__capture_fpclassify(((__type)(__f)));
# 514 "/usr/include/c++/4.3/cmath" 3
}
# 516 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 519 "/usr/include/c++/4.3/cmath" 3
isfinite(_Tp __f)
# 520 "/usr/include/c++/4.3/cmath" 3
{
# 521 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 522 "/usr/include/c++/4.3/cmath" 3
return __builtin_isfinite(((__type)(__f)));
# 523 "/usr/include/c++/4.3/cmath" 3
}
# 525 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 528 "/usr/include/c++/4.3/cmath" 3
isinf(_Tp __f)
# 529 "/usr/include/c++/4.3/cmath" 3
{
# 530 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 531 "/usr/include/c++/4.3/cmath" 3
return __builtin_isinf(((__type)(__f)));
# 532 "/usr/include/c++/4.3/cmath" 3
}
# 534 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 537 "/usr/include/c++/4.3/cmath" 3
isnan(_Tp __f)
# 538 "/usr/include/c++/4.3/cmath" 3
{
# 539 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 540 "/usr/include/c++/4.3/cmath" 3
return __builtin_isnan(((__type)(__f)));
# 541 "/usr/include/c++/4.3/cmath" 3
}
# 543 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 546 "/usr/include/c++/4.3/cmath" 3
isnormal(_Tp __f)
# 547 "/usr/include/c++/4.3/cmath" 3
{
# 548 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 549 "/usr/include/c++/4.3/cmath" 3
return __builtin_isnormal(((__type)(__f)));
# 550 "/usr/include/c++/4.3/cmath" 3
}
# 552 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 555 "/usr/include/c++/4.3/cmath" 3
signbit(_Tp __f)
# 556 "/usr/include/c++/4.3/cmath" 3
{
# 557 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 558 "/usr/include/c++/4.3/cmath" 3
return __builtin_signbit(((__type)(__f)));
# 559 "/usr/include/c++/4.3/cmath" 3
}
# 561 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 564 "/usr/include/c++/4.3/cmath" 3
isgreater(_Tp __f1, _Tp __f2)
# 565 "/usr/include/c++/4.3/cmath" 3
{
# 566 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 567 "/usr/include/c++/4.3/cmath" 3
return __builtin_isgreater(((__type)(__f1)), ((__type)(__f2)));
# 568 "/usr/include/c++/4.3/cmath" 3
}
# 570 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 573 "/usr/include/c++/4.3/cmath" 3
isgreaterequal(_Tp __f1, _Tp __f2)
# 574 "/usr/include/c++/4.3/cmath" 3
{
# 575 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 576 "/usr/include/c++/4.3/cmath" 3
return __builtin_isgreaterequal(((__type)(__f1)), ((__type)(__f2)));
# 577 "/usr/include/c++/4.3/cmath" 3
}
# 579 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 582 "/usr/include/c++/4.3/cmath" 3
isless(_Tp __f1, _Tp __f2)
# 583 "/usr/include/c++/4.3/cmath" 3
{
# 584 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 585 "/usr/include/c++/4.3/cmath" 3
return __builtin_isless(((__type)(__f1)), ((__type)(__f2)));
# 586 "/usr/include/c++/4.3/cmath" 3
}
# 588 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 591 "/usr/include/c++/4.3/cmath" 3
islessequal(_Tp __f1, _Tp __f2)
# 592 "/usr/include/c++/4.3/cmath" 3
{
# 593 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 594 "/usr/include/c++/4.3/cmath" 3
return __builtin_islessequal(((__type)(__f1)), ((__type)(__f2)));
# 595 "/usr/include/c++/4.3/cmath" 3
}
# 597 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 600 "/usr/include/c++/4.3/cmath" 3
islessgreater(_Tp __f1, _Tp __f2)
# 601 "/usr/include/c++/4.3/cmath" 3
{
# 602 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 603 "/usr/include/c++/4.3/cmath" 3
return __builtin_islessgreater(((__type)(__f1)), ((__type)(__f2)));
# 604 "/usr/include/c++/4.3/cmath" 3
}
# 606 "/usr/include/c++/4.3/cmath" 3
template<class _Tp> inline typename __gnu_cxx::__enable_if< (__is_arithmetic< _Tp> ::__value), int> ::__type
# 609 "/usr/include/c++/4.3/cmath" 3
isunordered(_Tp __f1, _Tp __f2)
# 610 "/usr/include/c++/4.3/cmath" 3
{
# 611 "/usr/include/c++/4.3/cmath" 3
typedef typename __gnu_cxx::__promote< _Tp, __is_integer< _Tp> ::__value> ::__type __type;
# 612 "/usr/include/c++/4.3/cmath" 3
return __builtin_isunordered(((__type)(__f1)), ((__type)(__f2)));
# 613 "/usr/include/c++/4.3/cmath" 3
}
# 615 "/usr/include/c++/4.3/cmath" 3
}
# 40 "/usr/include/c++/4.3/bits/cmath.tcc" 3
namespace std __attribute__((visibility("default"))) {
# 42 "/usr/include/c++/4.3/bits/cmath.tcc" 3
template<class _Tp> inline _Tp
# 44 "/usr/include/c++/4.3/bits/cmath.tcc" 3
__cmath_power(_Tp __x, unsigned __n)
# 45 "/usr/include/c++/4.3/bits/cmath.tcc" 3
{
# 46 "/usr/include/c++/4.3/bits/cmath.tcc" 3
auto _Tp __y = ((__n % (2)) ? __x : ((_Tp)(1)));
# 48 "/usr/include/c++/4.3/bits/cmath.tcc" 3
while (__n >>= 1)
# 49 "/usr/include/c++/4.3/bits/cmath.tcc" 3
{
# 50 "/usr/include/c++/4.3/bits/cmath.tcc" 3
__x = __x * __x;
# 51 "/usr/include/c++/4.3/bits/cmath.tcc" 3
if (__n % (2)) {
# 52 "/usr/include/c++/4.3/bits/cmath.tcc" 3
__y = __y * __x; }
# 53 "/usr/include/c++/4.3/bits/cmath.tcc" 3
}
# 55 "/usr/include/c++/4.3/bits/cmath.tcc" 3
return __y;
# 56 "/usr/include/c++/4.3/bits/cmath.tcc" 3
}
# 58 "/usr/include/c++/4.3/bits/cmath.tcc" 3
}
# 54 "/usr/include/c++/4.3/cstddef" 3
namespace std __attribute__((visibility("default"))) {
# 56 "/usr/include/c++/4.3/cstddef" 3
using ::ptrdiff_t;
# 57 "/usr/include/c++/4.3/cstddef" 3
using ::size_t;
# 59 "/usr/include/c++/4.3/cstddef" 3
}
# 105 "/usr/include/c++/4.3/cstdlib" 3
namespace std __attribute__((visibility("default"))) {
# 107 "/usr/include/c++/4.3/cstdlib" 3
using ::div_t;
# 108 "/usr/include/c++/4.3/cstdlib" 3
using ::ldiv_t;
# 110 "/usr/include/c++/4.3/cstdlib" 3
using ::abort;
# 111 "/usr/include/c++/4.3/cstdlib" 3
using ::abs;
# 112 "/usr/include/c++/4.3/cstdlib" 3
using ::atexit;
# 113 "/usr/include/c++/4.3/cstdlib" 3
using ::atof;
# 114 "/usr/include/c++/4.3/cstdlib" 3
using ::atoi;
# 115 "/usr/include/c++/4.3/cstdlib" 3
using ::atol;
# 116 "/usr/include/c++/4.3/cstdlib" 3
using ::bsearch;
# 117 "/usr/include/c++/4.3/cstdlib" 3
using ::calloc;
# 118 "/usr/include/c++/4.3/cstdlib" 3
using ::div;
# 119 "/usr/include/c++/4.3/cstdlib" 3
using ::exit;
# 120 "/usr/include/c++/4.3/cstdlib" 3
using ::free;
# 121 "/usr/include/c++/4.3/cstdlib" 3
using ::getenv;
# 122 "/usr/include/c++/4.3/cstdlib" 3
using ::labs;
# 123 "/usr/include/c++/4.3/cstdlib" 3
using ::ldiv;
# 124 "/usr/include/c++/4.3/cstdlib" 3
using ::malloc;
# 126 "/usr/include/c++/4.3/cstdlib" 3
using ::mblen;
# 127 "/usr/include/c++/4.3/cstdlib" 3
using ::mbstowcs;
# 128 "/usr/include/c++/4.3/cstdlib" 3
using ::mbtowc;
# 130 "/usr/include/c++/4.3/cstdlib" 3
using ::qsort;
# 131 "/usr/include/c++/4.3/cstdlib" 3
using ::rand;
# 132 "/usr/include/c++/4.3/cstdlib" 3
using ::realloc;
# 133 "/usr/include/c++/4.3/cstdlib" 3
using ::srand;
# 134 "/usr/include/c++/4.3/cstdlib" 3
using ::strtod;
# 135 "/usr/include/c++/4.3/cstdlib" 3
using ::strtol;
# 136 "/usr/include/c++/4.3/cstdlib" 3
using ::strtoul;
# 137 "/usr/include/c++/4.3/cstdlib" 3
using ::system;
# 139 "/usr/include/c++/4.3/cstdlib" 3
using ::wcstombs;
# 140 "/usr/include/c++/4.3/cstdlib" 3
using ::wctomb;
# 144 "/usr/include/c++/4.3/cstdlib" 3
inline long abs(long __i) { return labs(__i); }
# 147 "/usr/include/c++/4.3/cstdlib" 3
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }
# 149 "/usr/include/c++/4.3/cstdlib" 3
}
# 162 "/usr/include/c++/4.3/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 165 "/usr/include/c++/4.3/cstdlib" 3
using ::lldiv_t;
# 171 "/usr/include/c++/4.3/cstdlib" 3
using ::_Exit;
# 175 "/usr/include/c++/4.3/cstdlib" 3
inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }
# 178 "/usr/include/c++/4.3/cstdlib" 3
using ::llabs;
# 181 "/usr/include/c++/4.3/cstdlib" 3
inline lldiv_t div(long long __n, long long __d)
# 182 "/usr/include/c++/4.3/cstdlib" 3
{ auto lldiv_t __q; (__q.quot) = __n / __d; (__q.rem) = __n % __d; return __q; }
# 184 "/usr/include/c++/4.3/cstdlib" 3
using ::lldiv;
# 195 "/usr/include/c++/4.3/cstdlib" 3
using ::atoll;
# 196 "/usr/include/c++/4.3/cstdlib" 3
using ::strtoll;
# 197 "/usr/include/c++/4.3/cstdlib" 3
using ::strtoull;
# 199 "/usr/include/c++/4.3/cstdlib" 3
using ::strtof;
# 200 "/usr/include/c++/4.3/cstdlib" 3
using ::strtold;
# 202 "/usr/include/c++/4.3/cstdlib" 3
}
# 204 "/usr/include/c++/4.3/cstdlib" 3
namespace std __attribute__((visibility("default"))) {
# 207 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::lldiv_t;
# 209 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::_Exit;
# 210 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::abs;
# 212 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::llabs;
# 213 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::div;
# 214 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::lldiv;
# 216 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::atoll;
# 217 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::strtof;
# 218 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::strtoll;
# 219 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::strtoull;
# 220 "/usr/include/c++/4.3/cstdlib" 3
using __gnu_cxx::strtold;
# 222 "/usr/include/c++/4.3/cstdlib" 3
}
# 424 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__));
# 426 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 428 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 438 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 463 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
namespace __gnu_cxx {
# 465 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 466 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 468 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
namespace std {
# 470 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 471 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 472 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 474 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::abs;
# 475 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::fabs;
# 476 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::ceil;
# 477 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::floor;
# 478 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::sqrt;
# 479 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::pow;
# 480 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::log;
# 481 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::log10;
# 482 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::fmod;
# 483 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::modf;
# 484 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::exp;
# 485 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::frexp;
# 486 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::ldexp;
# 487 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::asin;
# 488 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::sin;
# 489 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::sinh;
# 490 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::acos;
# 491 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::cos;
# 492 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::cosh;
# 493 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::atan;
# 494 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::atan2;
# 495 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::tan;
# 496 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
using std::tanh;
# 550 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
namespace std {
# 553 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 554 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 555 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 556 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 557 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 558 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 559 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 560 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 561 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 562 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 563 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 564 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 565 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 566 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 567 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 568 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 569 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 570 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 571 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 572 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 573 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 574 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 575 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 576 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 577 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 578 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 579 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 582 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 585 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float logb(float a)
# 586 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 587 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return logbf(a);
# 588 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 590 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline int ilogb(float a)
# 591 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 592 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return ilogbf(a);
# 593 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 595 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float scalbn(float a, int b)
# 596 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 597 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return scalbnf(a, b);
# 598 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 600 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float scalbln(float a, long b)
# 601 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 602 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return scalblnf(a, b);
# 603 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 605 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float exp2(float a)
# 606 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 607 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return exp2f(a);
# 608 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 610 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float exp10(float a)
# 611 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 612 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return exp10f(a);
# 613 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 615 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float expm1(float a)
# 616 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 617 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return expm1f(a);
# 618 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 620 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float log2(float a)
# 621 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 622 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return log2f(a);
# 623 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 625 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float log1p(float a)
# 626 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 627 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return log1pf(a);
# 628 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 630 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float rsqrt(float a)
# 631 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 632 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return rsqrtf(a);
# 633 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 635 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float acosh(float a)
# 636 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 637 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return acoshf(a);
# 638 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 640 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float asinh(float a)
# 641 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 642 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return asinhf(a);
# 643 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 645 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float atanh(float a)
# 646 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 647 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return atanhf(a);
# 648 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 650 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float hypot(float a, float b)
# 651 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 652 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return hypotf(a, b);
# 653 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 655 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float cbrt(float a)
# 656 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 657 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return cbrtf(a);
# 658 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 660 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 661 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 662 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
sincosf(a, sptr, cptr);
# 663 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 665 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float erf(float a)
# 666 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 667 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return erff(a);
# 668 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 670 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float erfc(float a)
# 671 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 672 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return erfcf(a);
# 673 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 675 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float lgamma(float a)
# 676 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 677 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return lgammaf(a);
# 678 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 680 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float tgamma(float a)
# 681 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 682 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return tgammaf(a);
# 683 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 685 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float copysign(float a, float b)
# 686 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 687 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return copysignf(a, b);
# 688 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 690 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double copysign(double a, float b)
# 691 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 692 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return copysign(a, (double)b);
# 693 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 695 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float copysign(float a, double b)
# 696 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 697 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return copysignf(a, (float)b);
# 698 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 700 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float nextafter(float a, float b)
# 701 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 702 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return nextafterf(a, b);
# 703 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 705 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float remainder(float a, float b)
# 706 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 707 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return remainderf(a, b);
# 708 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 710 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 711 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 712 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return remquof(a, b, quo);
# 713 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 715 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float round(float a)
# 716 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 717 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return roundf(a);
# 718 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 720 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline long lround(float a)
# 721 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 722 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return lroundf(a);
# 723 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 725 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline long long llround(float a)
# 726 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 727 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return llroundf(a);
# 728 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 730 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float trunc(float a)
# 731 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 732 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return truncf(a);
# 733 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 735 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float rint(float a)
# 736 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 737 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return rintf(a);
# 738 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 740 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline long lrint(float a)
# 741 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 742 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return lrintf(a);
# 743 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 745 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline long long llrint(float a)
# 746 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 747 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return llrintf(a);
# 748 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 750 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float nearbyint(float a)
# 751 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 752 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return nearbyintf(a);
# 753 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 755 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float fdim(float a, float b)
# 756 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 757 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fdimf(a, b);
# 758 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 760 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 761 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 762 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmaf(a, b, c);
# 763 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 765 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 766 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 767 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umin(a, b);
# 768 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 770 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 771 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 772 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umin((unsigned)a, b);
# 773 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 775 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 776 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 777 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umin(a, (unsigned)b);
# 778 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 780 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float min(float a, float b)
# 781 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 782 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fminf(a, b);
# 783 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 785 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double min(double a, double b)
# 786 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 787 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmin(a, b);
# 788 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 790 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double min(float a, double b)
# 791 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 792 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmin((double)a, b);
# 793 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 795 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double min(double a, float b)
# 796 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 797 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmin(a, (double)b);
# 798 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 800 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 801 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 802 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umax(a, b);
# 803 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 805 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 806 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 807 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umax((unsigned)a, b);
# 808 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 810 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 811 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 812 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return umax(a, (unsigned)b);
# 813 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 815 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline float max(float a, float b)
# 816 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 817 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmaxf(a, b);
# 818 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 820 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double max(double a, double b)
# 821 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 822 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmax(a, b);
# 823 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 825 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double max(float a, double b)
# 826 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 827 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmax((double)a, b);
# 828 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 830 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
static inline double max(double a, float b)
# 831 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
{
# 832 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
return fmax(a, (double)b);
# 833 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h"
}
# 59 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode = cudaReadModeElementType>
# 60 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
struct texture : public textureReference {
# 62 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 63 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 64 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 65 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
{
# 66 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->normalized) = norm;
# 67 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->filterMode) = fMode;
# 68 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[0]) = aMode;
# 69 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[1]) = aMode;
# 70 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[2]) = aMode;
# 71 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->channelDesc) = cudaCreateChannelDesc< T> ();
# 72 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
}
# 74 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 75 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 76 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 77 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
desc)
# 78 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
{
# 79 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->normalized) = norm;
# 80 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->filterMode) = fMode;
# 81 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[0]) = aMode;
# 82 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[1]) = aMode;
# 83 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
((this->addressMode)[2]) = aMode;
# 84 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
(this->channelDesc) = desc;
# 85 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
}
# 86 "/home/gdiamos/temp/cuda/bin//../include/cuda_texture_types.h"
};
# 77 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 78 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaSetupArgument(T
# 79 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
arg, size_t
# 80 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset)
# 82 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 83 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 84 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 94 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 95 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, const void *
# 96 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
src, size_t
# 97 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 98 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 99 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 101 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 102 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 103 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 105 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 106 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 107 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, const void *
# 108 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
src, size_t
# 109 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 110 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 111 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 113 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 114 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 115 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 117 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 118 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, const void *
# 119 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
src, size_t
# 120 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 121 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 122 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind, cudaStream_t
# 123 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
stream)
# 125 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 126 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 127 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 129 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 130 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 131 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, const void *
# 132 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
src, size_t
# 133 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 134 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 135 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind, cudaStream_t
# 136 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
stream)
# 138 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 139 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 140 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 148 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 149 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
dst, char *
# 150 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, size_t
# 151 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 152 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 153 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 155 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 156 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 157 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 159 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 160 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 161 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
dst, const T &
# 162 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, size_t
# 163 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 164 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 165 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 167 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 168 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 169 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 171 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 172 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
dst, char *
# 173 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, size_t
# 174 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 175 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 176 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind, cudaStream_t
# 177 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
stream)
# 179 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 180 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 181 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 183 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 184 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 185 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
dst, const T &
# 186 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol, size_t
# 187 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
count, size_t
# 188 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 189 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
kind, cudaStream_t
# 190 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
stream)
# 192 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 193 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 194 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 196 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 197 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
devPtr, char *
# 198 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol)
# 200 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 201 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 202 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 204 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 205 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 206 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
devPtr, const T &
# 207 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol)
# 209 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 210 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 211 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 219 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 220 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
size, char *
# 221 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol)
# 223 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 224 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 225 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 227 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 228 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 229 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
size, const T &
# 230 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol)
# 232 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 233 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 234 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 242 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 243 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 244 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 245 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex, const void *
# 246 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 247 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
desc, size_t
# 248 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 250 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 251 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, (&desc), size);
# 252 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 254 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 255 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 256 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 257 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex, const void *
# 258 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
devPtr, size_t
# 259 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 261 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 262 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 263 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 265 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 266 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 267 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex, const cudaArray *
# 268 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 269 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
desc)
# 271 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 272 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, (&desc));
# 273 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 275 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 276 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 277 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex, const cudaArray *
# 278 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
array)
# 280 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 281 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
auto cudaChannelFormatDesc desc;
# 282 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
auto cudaError_t err = cudaGetChannelDesc(&desc, array);
# 284 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
# 285 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 293 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 294 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 295 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex)
# 297 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 298 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 299 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 307 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 308 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 309 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 310 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
tex)
# 312 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 313 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 314 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 322 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 323 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
cudaLaunch(T *
# 324 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
symbol)
# 326 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
{
# 327 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
return cudaLaunch((const char *)symbol);
# 328 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h"
}
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;
# 49 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 90 "/usr/include/wchar.h" 3
extern "C" { typedef
# 79 "/usr/include/wchar.h" 3
struct __mbstate_t {
# 80 "/usr/include/wchar.h" 3
int __count;
# 82 "/usr/include/wchar.h" 3
union {
# 84 "/usr/include/wchar.h" 3
unsigned __wch;
# 88 "/usr/include/wchar.h" 3
char __wchb[4];
# 89 "/usr/include/wchar.h" 3
} __value;
# 90 "/usr/include/wchar.h" 3
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 23 "/usr/include/_G_config.h" 3
struct _G_fpos_t {
# 24 "/usr/include/_G_config.h" 3
__off_t __pos;
# 25 "/usr/include/_G_config.h" 3
__mbstate_t __state;
# 26 "/usr/include/_G_config.h" 3
} _G_fpos_t; }
# 31 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 28 "/usr/include/_G_config.h" 3
struct _G_fpos64_t {
# 29 "/usr/include/_G_config.h" 3
__off64_t __pos;
# 30 "/usr/include/_G_config.h" 3
__mbstate_t __state;
# 31 "/usr/include/_G_config.h" 3
} _G_fpos64_t; }
# 53 "/usr/include/_G_config.h" 3
extern "C" { typedef short _G_int16_t; }
# 54 "/usr/include/_G_config.h" 3
extern "C" { typedef int _G_int32_t; }
# 55 "/usr/include/_G_config.h" 3
extern "C" { typedef unsigned short _G_uint16_t; }
# 56 "/usr/include/_G_config.h" 3
extern "C" { typedef unsigned _G_uint32_t; }
# 43 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stdarg.h" 3
extern "C" { typedef __builtin_va_list __gnuc_va_list; }
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3
extern "C" { typedef void _IO_lock_t; }
# 186 "/usr/include/libio.h" 3
extern "C" { struct _IO_marker {
# 187 "/usr/include/libio.h" 3
_IO_marker *_next;
# 188 "/usr/include/libio.h" 3
_IO_FILE *_sbuf;
# 192 "/usr/include/libio.h" 3
int _pos;
# 203 "/usr/include/libio.h" 3
}; }
# 206 "/usr/include/libio.h" 3
enum __codecvt_result {
# 208 "/usr/include/libio.h" 3
__codecvt_ok,
# 209 "/usr/include/libio.h" 3
__codecvt_partial,
# 210 "/usr/include/libio.h" 3
__codecvt_error,
# 211 "/usr/include/libio.h" 3
__codecvt_noconv
# 212 "/usr/include/libio.h" 3
};
# 271 "/usr/include/libio.h" 3
extern "C" { struct _IO_FILE {
# 272 "/usr/include/libio.h" 3
int _flags;
# 277 "/usr/include/libio.h" 3
char *_IO_read_ptr;
# 278 "/usr/include/libio.h" 3
char *_IO_read_end;
# 279 "/usr/include/libio.h" 3
char *_IO_read_base;
# 280 "/usr/include/libio.h" 3
char *_IO_write_base;
# 281 "/usr/include/libio.h" 3
char *_IO_write_ptr;
# 282 "/usr/include/libio.h" 3
char *_IO_write_end;
# 283 "/usr/include/libio.h" 3
char *_IO_buf_base;
# 284 "/usr/include/libio.h" 3
char *_IO_buf_end;
# 286 "/usr/include/libio.h" 3
char *_IO_save_base;
# 287 "/usr/include/libio.h" 3
char *_IO_backup_base;
# 288 "/usr/include/libio.h" 3
char *_IO_save_end;
# 290 "/usr/include/libio.h" 3
_IO_marker *_markers;
# 292 "/usr/include/libio.h" 3
_IO_FILE *_chain;
# 294 "/usr/include/libio.h" 3
int _fileno;
# 298 "/usr/include/libio.h" 3
int _flags2;
# 300 "/usr/include/libio.h" 3
__off_t _old_offset;
# 304 "/usr/include/libio.h" 3
unsigned short _cur_column;
# 305 "/usr/include/libio.h" 3
signed char _vtable_offset;
# 306 "/usr/include/libio.h" 3
char _shortbuf[1];
# 310 "/usr/include/libio.h" 3
_IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3
__off64_t _offset;
# 328 "/usr/include/libio.h" 3
void *__pad1;
# 329 "/usr/include/libio.h" 3
void *__pad2;
# 330 "/usr/include/libio.h" 3
void *__pad3;
# 331 "/usr/include/libio.h" 3
void *__pad4;
# 332 "/usr/include/libio.h" 3
size_t __pad5;
# 334 "/usr/include/libio.h" 3
int _mode;
# 336 "/usr/include/libio.h" 3
char _unused2[((((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(size_t))];
# 338 "/usr/include/libio.h" 3
}; }
# 344 "/usr/include/libio.h" 3
struct _IO_FILE_plus;
# 346 "/usr/include/libio.h" 3
extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; }
# 347 "/usr/include/libio.h" 3
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; }
# 348 "/usr/include/libio.h" 3
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; }
# 364 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_read_fn(void *, char *, size_t); }
# 372 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_write_fn(void *, const char *, size_t); }
# 381 "/usr/include/libio.h" 3
extern "C" { typedef int __io_seek_fn(void *, __off64_t *, int); }
# 384 "/usr/include/libio.h" 3
extern "C" { typedef int __io_close_fn(void *); }
# 389 "/usr/include/libio.h" 3
extern "C" { typedef __io_read_fn cookie_read_function_t; }
# 390 "/usr/include/libio.h" 3
extern "C" { typedef __io_write_fn cookie_write_function_t; }
# 391 "/usr/include/libio.h" 3
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
# 392 "/usr/include/libio.h" 3
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401 "/usr/include/libio.h" 3
extern "C" { typedef
# 396 "/usr/include/libio.h" 3
struct _IO_cookie_io_functions_t {
# 397 "/usr/include/libio.h" 3
__io_read_fn *read;
# 398 "/usr/include/libio.h" 3
__io_write_fn *write;
# 399 "/usr/include/libio.h" 3
__io_seek_fn *seek;
# 400 "/usr/include/libio.h" 3
__io_close_fn *close;
# 401 "/usr/include/libio.h" 3
} _IO_cookie_io_functions_t; }
# 402 "/usr/include/libio.h" 3
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }
# 404 "/usr/include/libio.h" 3
struct _IO_cookie_file;
# 407 "/usr/include/libio.h" 3
extern "C" void _IO_cookie_init(_IO_cookie_file *, int, void *, _IO_cookie_io_functions_t);
# 416 "/usr/include/libio.h" 3
extern "C" int __underflow(_IO_FILE *);
# 417 "/usr/include/libio.h" 3
extern "C" int __uflow(_IO_FILE *);
# 418 "/usr/include/libio.h" 3
extern "C" int __overflow(_IO_FILE *, int);
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *);
# 459 "/usr/include/libio.h" 3
extern "C" int _IO_putc(int, _IO_FILE *);
# 460 "/usr/include/libio.h" 3
extern "C" int _IO_feof(_IO_FILE *) throw();
# 461 "/usr/include/libio.h" 3
extern "C" int _IO_ferror(_IO_FILE *) throw();
# 463 "/usr/include/libio.h" 3
extern "C" int _IO_peekc_locked(_IO_FILE *);
# 469 "/usr/include/libio.h" 3
extern "C" void _IO_flockfile(_IO_FILE *) throw();
# 470 "/usr/include/libio.h" 3
extern "C" void _IO_funlockfile(_IO_FILE *) throw();
# 471 "/usr/include/libio.h" 3
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw();
# 488 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__);
# 490 "/usr/include/libio.h" 3
extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 492 "/usr/include/libio.h" 3
extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
# 493 "/usr/include/libio.h" 3
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t);
# 495 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
# 496 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);
# 498 "/usr/include/libio.h" 3
extern "C" void _IO_free_backup_area(_IO_FILE *) throw();
# 80 "/usr/include/stdio.h" 3
extern "C" { typedef __gnuc_va_list va_list; }
# 91 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos_t fpos_t; }
# 97 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 145 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; }
# 146 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdout; }
# 147 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stderr; }
# 155 "/usr/include/stdio.h" 3
extern "C" int remove(const char *) throw();
# 157 "/usr/include/stdio.h" 3
extern "C" int rename(const char *, const char *) throw();
# 162 "/usr/include/stdio.h" 3
extern "C" int renameat(int, const char *, int, const char *) throw();
# 172 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 182 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64();
# 186 "/usr/include/stdio.h" 3
extern "C" char *tmpnam(char *) throw();
# 192 "/usr/include/stdio.h" 3
extern "C" char *tmpnam_r(char *) throw();
# 204 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__));
# 214 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE *);
# 219 "/usr/include/stdio.h" 3
extern "C" int fflush(FILE *);
# 229 "/usr/include/stdio.h" 3
extern "C" int fflush_unlocked(FILE *);
# 239 "/usr/include/stdio.h" 3
extern "C" int fcloseall();
# 249 "/usr/include/stdio.h" 3
extern "C" FILE *fopen(const char *__restrict__, const char *__restrict__);
# 255 "/usr/include/stdio.h" 3
extern "C" FILE *freopen(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 274 "/usr/include/stdio.h" 3
extern "C" FILE *fopen64(const char *__restrict__, const char *__restrict__);
# 276 "/usr/include/stdio.h" 3
extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 283 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int, const char *) throw();
# 289 "/usr/include/stdio.h" 3
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw();
# 294 "/usr/include/stdio.h" 3
extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 300 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 307 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();
# 311 "/usr/include/stdio.h" 3
extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 318 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();
# 322 "/usr/include/stdio.h" 3
extern "C" void setlinebuf(FILE *) throw();
# 331 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 337 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);
# 339 "/usr/include/stdio.h" 3
extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 346 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 352 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list);
# 354 "/usr/include/stdio.h" 3
extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 361 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();
# 365 "/usr/include/stdio.h" 3
extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 374 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 377 "/usr/include/stdio.h" 3
extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 380 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 390 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);
# 393 "/usr/include/stdio.h" 3
extern "C" int dprintf(int, const char *__restrict__, ...);
# 403 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 409 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);
# 411 "/usr/include/stdio.h" 3
extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 449 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 457 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);
# 461 "/usr/include/stdio.h" 3
extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 509 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
# 510 "/usr/include/stdio.h" 3
extern "C" int getc(FILE *);
# 516 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 528 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
# 529 "/usr/include/stdio.h" 3
extern "C" int getchar_unlocked();
# 539 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE *);
# 551 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
# 552 "/usr/include/stdio.h" 3
extern "C" int putc(int, FILE *);
# 558 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 572 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int, FILE *);
# 580 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
# 581 "/usr/include/stdio.h" 3
extern "C" int putchar_unlocked(int);
# 588 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);
# 591 "/usr/include/stdio.h" 3
extern "C" int putw(int, FILE *);
# 600 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 608 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 618 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 634 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 637 "/usr/include/stdio.h" 3
extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 647 "/usr/include/stdio.h" 3
extern "C" __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__);
# 658 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 664 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 671 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 678 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 684 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 695 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 706 "/usr/include/stdio.h" 3
extern "C" size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 708 "/usr/include/stdio.h" 3
extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 718 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);
# 723 "/usr/include/stdio.h" 3
extern "C" long ftell(FILE *);
# 728 "/usr/include/stdio.h" 3
extern "C" void rewind(FILE *);
# 742 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);
# 747 "/usr/include/stdio.h" 3
extern "C" __off_t ftello(FILE *);
# 767 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);
# 772 "/usr/include/stdio.h" 3
extern "C" int fsetpos(FILE *, const fpos_t *);
# 787 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int);
# 788 "/usr/include/stdio.h" 3
extern "C" __off64_t ftello64(FILE *);
# 789 "/usr/include/stdio.h" 3
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__);
# 790 "/usr/include/stdio.h" 3
extern "C" int fsetpos64(FILE *, const fpos64_t *);
# 795 "/usr/include/stdio.h" 3
extern "C" void clearerr(FILE *) throw();
# 797 "/usr/include/stdio.h" 3
extern "C" int feof(FILE *) throw();
# 799 "/usr/include/stdio.h" 3
extern "C" int ferror(FILE *) throw();
# 804 "/usr/include/stdio.h" 3
extern "C" void clearerr_unlocked(FILE *) throw();
# 805 "/usr/include/stdio.h" 3
extern "C" int feof_unlocked(FILE *) throw();
# 806 "/usr/include/stdio.h" 3
extern "C" int ferror_unlocked(FILE *) throw();
# 815 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
# 28 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const sys_errlist[]; }
# 31 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int _sys_nerr; }
# 32 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const _sys_errlist[]; }
# 827 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();
# 832 "/usr/include/stdio.h" 3
extern "C" int fileno_unlocked(FILE *) throw();
# 842 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 848 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 854 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 860 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);
# 865 "/usr/include/stdio.h" 3
struct obstack;
# 868 "/usr/include/stdio.h" 3
extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();
# 871 "/usr/include/stdio.h" 3
extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 882 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();
# 886 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE *) throw();
# 889 "/usr/include/stdio.h" 3
extern "C" void funlockfile(FILE *) throw();
# 52 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 54 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 55 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 56 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 57 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 58 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 59 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 60 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUevent_st *CUevent; }
# 61 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef struct CUstream_st *CUstream; }
# 78 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 72 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUctx_flags_enum {
# 73 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 74 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 75 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 76 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_CTX_SCHED_MASK,
# 77 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_CTX_FLAGS_MASK = 3
# 78 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUctx_flags; }
# 92 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 83 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUarray_format_enum {
# 84 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 85 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 86 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 87 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 88 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 89 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 90 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 91 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 92 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUarray_format; }
# 101 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 97 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUaddress_mode_enum {
# 98 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 99 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 100 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR
# 101 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUaddress_mode; }
# 109 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 106 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUfilter_mode_enum {
# 107 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 108 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 109 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUfilter_mode; }
# 135 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 114 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUdevice_attribute_enum {
# 115 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 116 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 117 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 118 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 119 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 120 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 121 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 122 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 123 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 124 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 125 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 126 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 127 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 128 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 129 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 130 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 132 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 133 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 134 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT
# 135 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUdevice_attribute; }
# 151 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 140 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
struct CUdevprop_st {
# 141 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int maxThreadsPerBlock;
# 142 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int maxThreadsDim[3];
# 143 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int maxGridSize[3];
# 144 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int sharedMemPerBlock;
# 145 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int totalConstantMemory;
# 146 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int SIMDWidth;
# 147 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int memPitch;
# 148 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int regsPerBlock;
# 149 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int clockRate;
# 150 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
int textureAlign;
# 151 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUdevprop; }
# 160 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 156 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUmemorytype_enum {
# 157 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 158 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 159 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 160 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUmemorytype; }
# 220 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 166 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUjit_option_enum {
# 169 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 178 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 182 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_WALL_TIME,
# 186 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 192 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 196 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 202 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 206 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 210 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 213 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_TARGET,
# 218 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 220 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUjit_option; }
# 231 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 225 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUjit_target_enum {
# 227 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 228 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 229 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 230 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_TARGET_COMPUTE_13
# 231 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUjit_target; }
# 244 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 236 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum CUjit_fallback_enum {
# 239 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_PREFER_PTX,
# 242 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CU_PREFER_BINARY
# 244 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUjit_fallback; }
# 289 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 252 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
enum cudaError_enum {
# 254 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_SUCCESS,
# 255 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 256 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 257 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 258 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 260 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 261 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 263 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 264 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 265 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 266 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 267 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 268 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 269 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 270 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 271 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 272 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 274 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 275 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 277 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 279 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 281 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 283 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 284 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 285 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 286 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 288 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 289 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUresult; }
# 300 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 308 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 309 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 310 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 311 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 312 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 313 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 314 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 322 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 323 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 324 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 325 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 326 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 327 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 328 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 329 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 338 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 339 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 340 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 341 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 342 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 343 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 344 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 345 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 353 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 355 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 356 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 364 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 365 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 367 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 368 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 381 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 382 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 385 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 388 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 389 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 392 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 393 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 396 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 418 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 400 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 402 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcXInBytes; unsigned srcY;
# 403 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUmemorytype srcMemoryType;
# 404 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
const void *srcHost;
# 405 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUdeviceptr srcDevice;
# 406 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray srcArray;
# 407 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcPitch;
# 409 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstXInBytes; unsigned dstY;
# 410 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUmemorytype dstMemoryType;
# 411 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
void *dstHost;
# 412 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUdeviceptr dstDevice;
# 413 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray dstArray;
# 414 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstPitch;
# 416 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned WidthInBytes;
# 417 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Height;
# 418 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUDA_MEMCPY2D; }
# 419 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 420 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 449 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 424 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 426 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcXInBytes; unsigned srcY; unsigned srcZ;
# 427 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcLOD;
# 428 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUmemorytype srcMemoryType;
# 429 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
const void *srcHost;
# 430 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUdeviceptr srcDevice;
# 431 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray srcArray;
# 432 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
void *reserved0;
# 433 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcPitch;
# 434 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned srcHeight;
# 436 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstXInBytes; unsigned dstY; unsigned dstZ;
# 437 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstLOD;
# 438 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUmemorytype dstMemoryType;
# 439 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
void *dstHost;
# 440 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUdeviceptr dstDevice;
# 441 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray dstArray;
# 442 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
void *reserved1;
# 443 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstPitch;
# 444 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned dstHeight;
# 446 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned WidthInBytes;
# 447 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Height;
# 448 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Depth;
# 449 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUDA_MEMCPY3D; }
# 450 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 465 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 467 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 471 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 473 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 477 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 480 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 487 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 488 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 489 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 491 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 492 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 493 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 502 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 503 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 526 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 512 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR {
# 516 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Width;
# 517 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Height;
# 522 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray_format Format;
# 525 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned NumChannels;
# 526 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 528 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 529 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 530 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 552 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" { typedef
# 533 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR {
# 537 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Width;
# 538 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Height;
# 539 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Depth;
# 543 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
CUarray_format Format;
# 546 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned NumChannels;
# 550 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
unsigned Flags;
# 552 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 553 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 554 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 561 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 562 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 564 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 567 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 568 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 570 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 571 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 572 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 580 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 581 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 582 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 583 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 584 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 585 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 593 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 594 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 595 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 596 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 597 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 608 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 609 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 610 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 617 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 618 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 619 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 620 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 621 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 622 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 629 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 630 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 631 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 632 "/home/gdiamos/temp/cuda/bin//../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 64 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
enum CUTBoolean {
# 66 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
CUTFalse,
# 67 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
CUTTrue
# 68 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
};
# 76 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" void cutFree(void *);
# 94 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 107 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 122 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 138 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 154 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 169 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 185 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 201 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 215 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 229 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 241 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 253 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 265 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 277 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 293 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 306 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 320 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 336 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 352 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 367 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 379 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 391 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 404 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 416 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 428 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 440 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 461 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 475 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 489 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 503 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 518 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 532 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 544 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 557 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 584 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 599 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 613 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 627 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 642 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 657 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 672 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 685 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 694 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 702 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 710 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 718 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 727 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 738 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 19 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 20 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 21 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 22 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
{
# 23 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 24 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_bankchecker.h"
}
# 162 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 164 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 165 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 166 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return x.x;
# 167 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 169 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 170 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 171 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return x.y;
# 172 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 174 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 175 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
r, float i)
# 176 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 177 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuFloatComplex res;
# 178 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
(res.x) = r;
# 179 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
(res.y) = i;
# 180 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return res;
# 181 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 183 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 184 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 185 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 186 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 187 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 188 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 189 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 190 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 192 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 194 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 195 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 196 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 197 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 199 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 206 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 207 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 208 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 209 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuFloatComplex prod;
# 210 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
prod = make_cuFloatComplex(cuCrealf(x) * cuCrealf(y) - cuCimagf(x) * cuCimagf(y), cuCrealf(x) * cuCimagf(y) + cuCimagf(x) * cuCrealf(y));
# 214 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return prod;
# 215 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 222 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 223 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 224 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 225 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuFloatComplex quot;
# 226 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float s = ((float)fabs((double)cuCrealf(y)) + (float)fabs((double)cuCimagf(y)));
# 228 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float oos = ((1.0F) / s);
# 229 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float ars = (cuCrealf(x) * oos);
# 230 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float ais = (cuCimagf(x) * oos);
# 231 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float brs = (cuCrealf(y) * oos);
# 232 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float bis = (cuCimagf(y) * oos);
# 233 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
s = brs * brs + bis * bis;
# 234 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
oos = (1.0F) / s;
# 235 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
quot = make_cuFloatComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);
# 237 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return quot;
# 238 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 248 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 249 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 250 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float a = cuCrealf(x);
# 251 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float b = cuCimagf(x);
# 252 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto float v; auto float w; auto float t;
# 253 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
a = (float)fabs(a);
# 254 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
b = (float)fabs(b);
# 255 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
if (a > b) {
# 256 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
v = a;
# 257 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
w = b;
# 258 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} else {
# 259 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
v = b;
# 260 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
w = a;
# 261 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 262 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = w / v;
# 263 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = (1.0F) + t * t;
# 264 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = v * (float)sqrt(t);
# 265 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 266 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = v + w;
# 267 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 268 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return t;
# 269 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 272 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 274 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 275 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 276 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return x.x;
# 277 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 279 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 280 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 281 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return x.y;
# 282 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 284 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 285 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
r, double i)
# 286 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 287 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuDoubleComplex res;
# 288 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
(res.x) = r;
# 289 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
(res.y) = i;
# 290 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return res;
# 291 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 293 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 294 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 295 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 296 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 298 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 299 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 300 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 301 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 303 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 305 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 306 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 307 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 308 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 310 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 317 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 318 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 319 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 320 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuDoubleComplex prod;
# 321 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
prod = make_cuDoubleComplex(cuCreal(x) * cuCreal(y) - cuCimag(x) * cuCimag(y), cuCreal(x) * cuCimag(y) + cuCimag(x) * cuCreal(y));
# 325 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return prod;
# 326 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 333 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 334 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 335 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 336 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto cuDoubleComplex quot;
# 337 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 338 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double oos = ((1.0) / s);
# 339 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double ars = (cuCreal(x) * oos);
# 340 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double ais = (cuCimag(x) * oos);
# 341 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double brs = (cuCreal(y) * oos);
# 342 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double bis = (cuCimag(y) * oos);
# 343 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
s = brs * brs + bis * bis;
# 344 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
oos = (1.0) / s;
# 345 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
quot = make_cuDoubleComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);
# 347 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return quot;
# 348 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 356 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 357 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 358 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double a = cuCreal(x);
# 359 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double b = cuCimag(x);
# 360 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
auto double v; auto double w; auto double t;
# 361 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
a = fabs(a);
# 362 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
b = fabs(b);
# 363 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
if (a > b) {
# 364 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
v = a;
# 365 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
w = b;
# 366 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} else {
# 367 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
v = b;
# 368 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
w = a;
# 369 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 370 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = w / v;
# 371 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = (1.0) + t * t;
# 372 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = v * sqrt(t);
# 373 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 374 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 375 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
t = v + w;
# 376 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 377 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return t;
# 378 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
} }
# 387 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 388 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 389 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
y)
# 390 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 391 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 392 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 395 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 396 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
c)
# 397 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 398 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 399 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 401 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 402 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
c)
# 403 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
{
# 404 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 405 "/home/gdiamos/temp/cuda/bin//../include/cuComplex.h"
}
# 74 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" { typedef
# 64 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
enum cufftResult_t {
# 65 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_SUCCESS,
# 66 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_INVALID_PLAN,
# 67 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_ALLOC_FAILED,
# 68 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_INVALID_TYPE,
# 69 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_INVALID_VALUE,
# 70 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_INTERNAL_ERROR,
# 71 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_EXEC_FAILED,
# 72 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_SETUP_FAILED,
# 73 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_INVALID_SIZE
# 74 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
} cufftResult; }
# 79 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 82 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 87 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 98 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" { typedef
# 94 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
enum cufftType_t {
# 95 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_R2C = 42,
# 96 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_C2R = 44,
# 97 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
CUFFT_C2C = 41
# 98 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
} cufftType; }
# 100 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 105 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 109 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 113 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 115 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 120 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 124 "/home/gdiamos/temp/cuda/bin//../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 22 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 23 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 24 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 25 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(1);
# 26 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 27 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 29 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 30 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 31 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 32 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 33 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fflush(stdout);
# 34 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fflush(stderr);
# 35 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
getchar();
# 36 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 37 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(0);
# 38 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 41 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 42 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 43 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int device_count = 0;
# 44 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 46 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto cudaDeviceProp device_properties;
# 47 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int max_gflops_device = 0;
# 48 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int max_gflops = 0;
# 50 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int current_device = 0;
# 51 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 52 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
max_gflops = device_properties.multiProcessorCount * device_properties.clockRate;
# 53 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
++current_device;
# 55 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
while (current_device < device_count)
# 56 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 57 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 58 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int gflops = (device_properties.multiProcessorCount * device_properties.clockRate);
# 59 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if (gflops > max_gflops)
# 60 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 61 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
max_gflops = gflops;
# 62 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
max_gflops_device = current_device;
# 63 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 64 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
++current_device;
# 65 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 67 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
return max_gflops_device;
# 68 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 70 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 71 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 72 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 73 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 75 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 76 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 77 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 79 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 80 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 81 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 82 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 84 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 85 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 86 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 88 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 89 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 90 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto cudaError err = cudaThreadSynchronize();
# 91 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 92 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 94 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 95 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 96 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 98 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 99 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 100 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 101 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 103 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 104 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 105 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 107 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 108 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 109 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 110 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 112 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 113 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 114 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 116 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 117 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 118 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto cudaError_t err = cudaGetLastError();
# 119 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 120 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 122 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 123 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 132 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 133 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 134 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 135 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if (!(pointer)) {
# 136 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 138 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 139 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 140 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 145 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 146 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 147 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int deviceCount;
# 148 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h", 148);
# 149 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 150 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 151 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 152 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 153 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto int dev = 0;
# 154 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 155 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
# 157 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto cudaDeviceProp deviceProp;
# 158 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h", 158);
# 159 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 160 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 161 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1); }
# 163 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 164 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 165 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h", 165);
# 166 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 171 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 172 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
{
# 173 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
auto cudaError_t err = cudaGetLastError();
# 174 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 175 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 177 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 178 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 179 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 180 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 183 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
exit(-1);
# 184 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 185 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_runtime.h"
}
# 16 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 17 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 18 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 19 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 21 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 22 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 23 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 24 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 25 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 26 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 27 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 29 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 30 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 31 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto CUresult err = cuCtxSynchronize();
# 32 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 33 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 35 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 36 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 37 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 39 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 40 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 41 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto CUresult err = cuCtxSynchronize();
# 42 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 43 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 44 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 46 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 47 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 48 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 54 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 55 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 56 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
cuDevice = 0;
# 57 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto int deviceCount = 0;
# 58 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto CUresult err = cuInit(0);
# 59 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 60 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h", 60); }
# 61 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 62 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 63 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 64 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 65 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto int dev = 0;
# 66 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 67 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 68 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
# 69 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h", 69);
# 70 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto char name[100];
# 71 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 72 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 73 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 74 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 78 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 79 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
{
# 80 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
auto CUresult err = cuCtxSynchronize();
# 81 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 82 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 84 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 85 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 86 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 87 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 88 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 90 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
exit(-1);
# 91 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 92 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline_drvapi.h"
}
# 12 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 13 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
{
# 14 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 2010 / 1000, 2010 % 100);
# 15 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_inline.h"
}
# 52 "realtype.h"
typedef double real;
# 52 "MonteCarlo_common.h"
typedef
# 46 "MonteCarlo_common.h"
struct TOptionData {
# 47 "MonteCarlo_common.h"
float S;
# 48 "MonteCarlo_common.h"
float X;
# 49 "MonteCarlo_common.h"
float T;
# 50 "MonteCarlo_common.h"
float R;
# 51 "MonteCarlo_common.h"
float V;
# 52 "MonteCarlo_common.h"
} TOptionData;
# 61 "MonteCarlo_common.h"
typedef
# 58 "MonteCarlo_common.h"
struct __attribute__((__aligned__(8))) TOptionValue {
# 59 "MonteCarlo_common.h"
float Expected;
# 60 "MonteCarlo_common.h"
float Confidence;
# 61 "MonteCarlo_common.h"
} TOptionValue;
# 85 "MonteCarlo_common.h"
typedef
# 64 "MonteCarlo_common.h"
struct TOptionPlan {
# 66 "MonteCarlo_common.h"
int device;
# 68 "MonteCarlo_common.h"
int optionCount;
# 71 "MonteCarlo_common.h"
TOptionData *optionData;
# 72 "MonteCarlo_common.h"
TOptionValue *callValue;
# 74 "MonteCarlo_common.h"
void *d_Buffer;
# 77 "MonteCarlo_common.h"
unsigned seed;
# 79 "MonteCarlo_common.h"
int pathN;
# 81 "MonteCarlo_common.h"
float *d_Samples;
# 84 "MonteCarlo_common.h"
float time;
# 85 "MonteCarlo_common.h"
} TOptionPlan;
# 73 "MonteCarlo_kernel.cuh"
typedef
# 68 "MonteCarlo_kernel.cuh"
struct __TOptionData {
# 69 "MonteCarlo_kernel.cuh"
real S;
# 70 "MonteCarlo_kernel.cuh"
real X;
# 71 "MonteCarlo_kernel.cuh"
real MuByT;
# 72 "MonteCarlo_kernel.cuh"
real VBySqrtT;
# 73 "MonteCarlo_kernel.cuh"
} __TOptionData;
# 74 "MonteCarlo_kernel.cuh"
static __TOptionData __shadow_d_OptionData[2048];
# 80 "MonteCarlo_kernel.cuh"
typedef
# 77 "MonteCarlo_kernel.cuh"
struct __TOptionValue {
# 78 "MonteCarlo_kernel.cuh"
real Expected;
# 79 "MonteCarlo_kernel.cuh"
real Confidence;
# 80 "MonteCarlo_kernel.cuh"
} __TOptionValue;
# 81 "MonteCarlo_kernel.cuh"
static __TOptionValue __shadow_d_CallValue[2048];

# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h" 1

extern "C" {


static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *, float *, int);
# 17 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h"
}
# 84 "MonteCarlo_kernel.cuh" 2


# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h" 1

extern "C" {





static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi(float *, int);
# 17 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h"
}
# 87 "MonteCarlo_kernel.cuh" 2


# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h" 1

extern "C" {
# 11 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h"
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei(__TOptionValue *, int);





}
# 90 "MonteCarlo_kernel.cuh" 2
# 228 "MonteCarlo_kernel.cuh"
static void initMonteCarloGPU(TOptionPlan *plan) {
# 229 "MonteCarlo_kernel.cuh"
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
# 230 "MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 231 "MonteCarlo_kernel.cuh"
auto const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 232 "MonteCarlo_kernel.cuh"
auto const int accumN = (256 * blocksPerOption);
# 233 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMalloc((void **)(&(plan->d_Buffer)), (accumN * plan->optionCount) * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 236);
# 237 "MonteCarlo_kernel.cuh"
}
# 238 "MonteCarlo_kernel.cuh"
}
# 241 "MonteCarlo_kernel.cuh"
static void closeMonteCarloGPU(TOptionPlan *plan) {
# 242 "MonteCarlo_kernel.cuh"
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
# 243 "MonteCarlo_kernel.cuh"
if (doMultiBlock) { __cudaSafeCall(cudaFree(plan->d_Buffer), "MonteCarlo_kernel.cuh", 243); }
# 244 "MonteCarlo_kernel.cuh"
}
# 247 "MonteCarlo_kernel.cuh"
static void MonteCarloGPU(TOptionPlan *plan) {
# 248 "MonteCarlo_kernel.cuh"
auto __TOptionData h_OptionData[2048];
# 249 "MonteCarlo_kernel.cuh"
auto __TOptionValue h_CallValue[2048];
# 251 "MonteCarlo_kernel.cuh"
if (((plan->optionCount) <= 0) || ((plan->optionCount) > 2048)) {
# 252 "MonteCarlo_kernel.cuh"
printf("MonteCarloGPU(): bad option count.\n");
# 253 "MonteCarlo_kernel.cuh"
return;
# 254 "MonteCarlo_kernel.cuh"
}
# 256 "MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 257 "MonteCarlo_kernel.cuh"
auto const double T = (((plan->optionData)[i]).T);
# 258 "MonteCarlo_kernel.cuh"
auto const double R = (((plan->optionData)[i]).R);
# 259 "MonteCarlo_kernel.cuh"
auto const double V = (((plan->optionData)[i]).V);
# 260 "MonteCarlo_kernel.cuh"
auto const double MuByT = ((R - ((0.5) * V) * V) * T);
# 261 "MonteCarlo_kernel.cuh"
auto const double VBySqrtT = (V * sqrt(T));
# 262 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).S) = (real)(((plan->optionData)[i]).S);
# 263 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).X) = (real)(((plan->optionData)[i]).X);
# 264 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).MuByT) = (real)MuByT;
# 265 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).VBySqrtT) = (real)VBySqrtT;
# 266 "MonteCarlo_kernel.cuh"
}
# 268 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyToSymbol(__shadow_d_OptionData, h_OptionData, plan->optionCount * sizeof(__TOptionData)), "MonteCarlo_kernel.cuh", 272);
# 274 "MonteCarlo_kernel.cuh"
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
# 275 "MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 276 "MonteCarlo_kernel.cuh"
auto const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 277 "MonteCarlo_kernel.cuh"
auto const int accumN = (256 * blocksPerOption);
# 278 "MonteCarlo_kernel.cuh"
auto const dim3 gridMain(blocksPerOption, plan->optionCount);
# 279 "MonteCarlo_kernel.cuh"
cudaConfigureCall(gridMain, 256) ? ((void)0) : __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi((__TOptionValue *)(plan->d_Buffer), plan->d_Samples, plan->pathN);
# 284 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloKernel() execution failed\n", "MonteCarlo_kernel.cuh", 284);
# 285 "MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : __device_stub__Z16MonteCarloReduceP14__TOptionValuei((__TOptionValue *)(plan->d_Buffer), accumN);
# 289 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloReduce() execution failed\n", "MonteCarlo_kernel.cuh", 289);
# 290 "MonteCarlo_kernel.cuh"
} else {
# 291 "MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : __device_stub__Z27MonteCarloOneBlockPerOptionPfi(plan->d_Samples, plan->pathN);
# 295 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloOneBlockPerOption() execution failed\n", "MonteCarlo_kernel.cuh", 295);
# 296 "MonteCarlo_kernel.cuh"
}
# 297 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyFromSymbol(h_CallValue, __shadow_d_CallValue, plan->optionCount * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 301);
# 303 "MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 304 "MonteCarlo_kernel.cuh"
auto const double RT = (((plan->optionData)[i]).R * ((plan->optionData)[i]).T);
# 305 "MonteCarlo_kernel.cuh"
auto const double sum = (((h_CallValue)[i]).Expected);
# 306 "MonteCarlo_kernel.cuh"
auto const double sum2 = (((h_CallValue)[i]).Confidence);
# 307 "MonteCarlo_kernel.cuh"
auto const double pathN = (plan->pathN);
# 309 "MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Expected) = (float)((exp(-RT) * sum) / pathN);
# 311 "MonteCarlo_kernel.cuh"
auto double stdDev = sqrt((pathN * sum2 - sum * sum) / (pathN * (pathN - (1))));
# 313 "MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Confidence) = (float)(((exp(-RT) * (1.959999999999999964)) * stdDev) / sqrt(pathN));
# 314 "MonteCarlo_kernel.cuh"
}
# 315 "MonteCarlo_kernel.cuh"
}

# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h" 1

extern "C" {
# 14 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.h"
static void __device_stub__Z16inverseCNDKernelPfS_j(float *, float *, unsigned);


}
# 318 "MonteCarlo_kernel.cuh" 2
# 274 "quasirandomGenerator_kernel.cuh"
static void inverseCNDgpu(float *d_Output, float *d_Input, unsigned N) {
# 275 "quasirandomGenerator_kernel.cuh"
cudaConfigureCall(128, 128) ? ((void)0) : __device_stub__Z16inverseCNDKernelPfS_j(d_Output, d_Input, N);
# 276 "quasirandomGenerator_kernel.cuh"
__cutilCheckMsg("inverseCNDKernel() execution failed.\n", "quasirandomGenerator_kernel.cuh", 276);
# 277 "quasirandomGenerator_kernel.cuh"
}
# 44 "MonteCarlo_SM13.cu"
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan) {
# 45 "MonteCarlo_SM13.cu"
initMonteCarloGPU(plan);
# 46 "MonteCarlo_SM13.cu"
}
# 48 "MonteCarlo_SM13.cu"
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan) {
# 49 "MonteCarlo_SM13.cu"
closeMonteCarloGPU(plan);
# 50 "MonteCarlo_SM13.cu"
}
# 52 "MonteCarlo_SM13.cu"
extern "C" void MonteCarlo_SM13(TOptionPlan *plan) {
# 53 "MonteCarlo_SM13.cu"
MonteCarloGPU(plan);
# 54 "MonteCarlo_SM13.cu"
}
# 56 "MonteCarlo_SM13.cu"
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned N) {
# 57 "MonteCarlo_SM13.cu"
inverseCNDgpu(d_Output, d_Input, N);
# 58 "MonteCarlo_SM13.cu"
}

# 1 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_0000150a_00000000-6_MonteCarlo_SM13.fatbin.c" 1
# 1 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h" 1
# 83 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
extern "C" {
# 97 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* debug;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 144 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 157 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
typedef struct __cudaFatCudaBinaryRec {
    unsigned long magic;
    unsigned long version;
    unsigned long gpuInfoVersion;
    char* key;
    char* ident;
    char* usageMode;
    __cudaFatPtxEntry *ptx;
    __cudaFatCubinEntry *cubin;
    __cudaFatDebugEntry *debug;
    void* debugInfo;
    unsigned int flags;
    __cudaFatSymbol *exported;
    __cudaFatSymbol *imported;
    struct __cudaFatCudaBinaryRec *dependends;
} __cudaFatCudaBinary;
# 191 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 214 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 225 "/home/gdiamos/temp/cuda/bin//../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_0000150a_00000000-6_MonteCarlo_SM13.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x636f6c65720a7d6eull,
0x6d616e09090a7b20ull,0x64203d2020202065ull,0x6c61566c6c61435full,0x67657309090a6575ull,
0x72203d20656d616eull,0x7309090a636f6c65ull,0x3d20206d756e6765ull,0x666f09090a343120ull,
0x203d202074657366ull,0x6574796209090a30ull,0x3233203d20202073ull,0x6f630a7d0a383637ull,
0x090a7b207374736eull,0x202020656d616e09ull,0x74704f5f64203d20ull,0x0a617461446e6f69ull,
0x6d616e6765730909ull,0x736e6f63203d2065ull,0x6e67657309090a74ull,0x0a30203d20206d75ull,
0x74657366666f0909ull,0x09090a30203d2020ull,0x2020207365747962ull,0x0a3633353536203dull,
0x7b2065646f630a7dull,0x3d20656d616e090aull,0x6e6f4d36315a5f20ull,0x4b6f6c7261436574ull,
0x3431506c656e7265ull,0x6f6974704f545f5full,0x665065756c61566eull,0x206d656d6c090a69ull,
0x656d73090a30203dull,0x090a3633203d206dull,0x32203d2020676572ull,0x2020726162090a38ull,
0x6e6f63090a30203dull,0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,
0x756e676573090909ull,0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,
0x2020736574796209ull,0x09090a3432203d20ull,0x09090a7b206d656dull,0x6666666666783009ull,
0x3030783020333063ull,0x3020303030303030ull,0x3030303030303478ull,0x3030303078302030ull,
0x09090a2037333030ull,0x3030303030783009ull,0x6333783020303030ull,0x0a20303030303039ull,
0x090a7d090a7d0909ull,0x2065646f636e6962ull,0x3031783009090a7bull,0x3020353032303030ull,
0x3837343030303478ull,0x3030306178302030ull,0x3078302035303030ull,0x2030383730303034ull,
0x303036783009090aull,0x7830203935633431ull,0x3038373430323030ull,0x3830303031783020ull,
0x3030783020393030ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302064303038ull,
0x2033303030303030ull,0x3164363130337830ull,0x3263367830206466ull,0x090a203863376330ull,
0x6636303061783009ull,0x3030783020333030ull,0x3020303030303030ull,0x3365343030306178ull,
0x3032343078302031ull,0x09090a2030383730ull,0x3438323030317830ull,0x3030317830203030ull,
0x7830203430363830ull,0x3330306536303031ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3038313530303078ull,0x3030306378302035ull,0x3178302030383730ull,0x2031343230303030ull,
0x3734303030347830ull,0x783009090a203038ull,0x3933633232303033ull,0x3030313463783020ull,
0x3431783020303837ull,0x3020313138303030ull,0x3837633030343278ull,0x31783009090a2030ull,
0x2035316130303034ull,0x3763303034327830ull,0x3034317830203038ull,0x7830203931633030ull,
0x3038376330303432ull,0x3431783009090a20ull,0x3020643165303030ull,0x3837633030343278ull,
0x3031303478302030ull,0x3078302035333834ull,0x2030383730303230ull,0x303431783009090aull,
0x7830203132303030ull,0x3038376330303432ull,0x3030303431783020ull,0x3432783020353232ull,
0x0a20303837633030ull,0x3030343178300909ull,0x3278302039323430ull,0x2030383763303034ull,
0x3630303034317830ull,0x3034327830206432ull,0x090a203038376330ull,0x6330303032783009ull,
0x3430783020643563ull,0x3020303837383332ull,0x3661313230303378ull,0x3031346378302031ull,
0x09090a2030383730ull,0x6361643030327830ull,0x3031327830203436ull,0x7830203836306664ull,
0x3933653265303064ull,0x3030633038783020ull,0x3009090a20303837ull,0x3363313030306178ull,
0x3034346378302039ull,0x3178302030383730ull,0x2031343038663230ull,0x3361666566307830ull,
0x783009090a206639ull,0x3534303832303031ull,0x3638303430783020ull,0x3065783020376532ull,
0x3020393363313630ull,0x3837303130303478ull,0x65783009090a2030ull,0x2064666431303130ull,
0x3730313030657830ull,0x3030617830203863ull,0x7830203330303336ull,0x3030303030303030ull,
0x3031783009090a20ull,0x3020333030343230ull,0x3031303030303078ull,0x3030303178302030ull,
0x3078302039333038ull,0x2033303030303030ull,0x303031783009090aull,0x7830206433303830ull,
0x3330303066663730ull,0x3336303031783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3231303178300909ull,0x3078302031343038ull,0x2037303364323564ull,0x3038303130317830ull,
0x3063307830203534ull,0x090a203339343738ull,0x3130313065783009ull,0x3065783020646664ull,
0x3020386337633030ull,0x3030623230303178ull,0x3030303078302033ull,0x09090a2030303130ull,
0x3038303030317830ull,0x3030307830203933ull,0x7830203330303030ull,0x6433303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3030333630303178ull,0x3030303078302033ull,
0x3178302030383730ull,0x2031343038653330ull,0x3862323536307830ull,0x783009090a206632ull,
0x3534303837303031ull,0x3766663330783020ull,0x3065783020373531ull,0x3020313463313031ull,
0x3837303030303878ull,0x61783009090a2030ull,0x2031343032303030ull,0x3734303463637830ull,
0x3030617830203038ull,0x7830206436303230ull,0x3038373436343838ull,0x3033783009090a20ull,
0x3020646637333038ull,0x6337303134633678ull,0x3030313278302038ull,0x3078302064363633ull,
0x2030303563303434ull,0x303031783009090aull,0x7830203934383030ull,0x3030356330343432ull,
0x3030303031783020ull,0x3432783020643461ull,0x0a20303035633034ull,0x3030303178300909ull,
0x3278302039343230ull,0x2030383263303434ull,0x3430303030317830ull,0x3434327830206434ull,
0x090a203038326330ull,0x3866323031783009ull,0x6630783020313530ull,0x3020663933616665ull,
0x3530383230303178ull,0x6566623078302035ull,0x09090a2037653236ull,0x3032343130657830ull,
0x3030347830203933ull,0x7830203038373833ull,0x3135303866333031ull,0x3933623330783020ull,
0x3009090a20333038ull,0x3530386531303178ull,0x3763623078302035ull,0x6578302062636261ull,
0x2039333032343130ull,0x3738333030347830ull,0x783009090a203038ull,0x3134303864323031ull,
0x3566636330783020ull,0x3031783020626238ull,0x3020353430386633ull,0x3066313265333078ull,
0x31783009090a2037ull,0x2031353038663230ull,0x3363366164307830ull,0x3030317830206262ull,
0x7830203535303831ull,0x6264666135653330ull,0x3065783009090a20ull,0x3020313463313031ull,
0x3837303530303478ull,0x3632303178302030ull,0x3078302031353038ull,0x2066303866303666ull,
0x313031783009090aull,0x7830203535303835ull,0x3765373239653330ull,0x3130313065783020ull,
0x3034783020313463ull,0x0a20303837303530ull,0x3632303178300909ull,0x3078302031353038ull,
0x2037366432306638ull,0x3038613130317830ull,0x6533307830203535ull,0x090a206664313763ull,
0x3130313065783009ull,0x3034783020313463ull,0x3020303837303530ull,0x3530383032303178ull,
0x6233313078302031ull,0x09090a2066343938ull,0x3038303230317830ull,0x6533307830203535ull,
0x7830206231306166ull,0x3134633130313065ull,0x3035303034783020ull,0x3009090a20303837ull,
0x3530383830303178ull,0x3364313078302031ull,0x3178302062376661ull,0x2035353038303230ull,
0x3061326633307830ull,0x783009090a206231ull,0x3134633130313065ull,0x3035303034783020ull,
0x3031783020303837ull,0x3020313530386332ull,0x3161336336313078ull,0x31783009090a2066ull,
0x2035353038633230ull,0x6336356633307830ull,0x3130657830203731ull,0x7830203134633130ull,
0x3038373035303034ull,0x3031783009090a20ull,0x3020313530383132ull,0x3139303131313078ull,
0x3131303178302037ull,0x3078302035353038ull,0x2033313131386633ull,0x313065783009090aull,
0x7830203134633130ull,0x3038373035303034ull,0x3831303031783020ull,0x3530783020313530ull,
0x0a20663435353535ull,0x3531303178300909ull,0x3078302035353038ull,0x2037353535616633ull,
0x6331303130657830ull,0x3030347830203134ull,0x090a203038373035ull,0x3866323031783009ull,
0x3530783020313530ull,0x3020373535353535ull,0x3530383531303178ull,0x6366333078302035ull,
0x09090a2037353535ull,0x6331303130657830ull,0x3030347830203134ull,0x7830203038373035ull,
0x3135303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3530383030303178ull,
0x6566333078302035ull,0x6578302033303030ull,0x2031346331303130ull,0x3730353030347830ull,
0x783009090a203038ull,0x3134633130313065ull,0x3030303038783020ull,0x3065783020303837ull,
0x3020393330326530ull,0x3837383330303478ull,0x31783009090a2030ull,0x2031343866303030ull,
0x3763333034307830ull,0x3330327830203038ull,0x7830203534366265ull,0x6633303030303030ull,
0x3033783009090a20ull,0x3020353432323431ull,0x3837303031346378ull,0x3031306578302030ull,
0x3478302039336331ull,0x2030383730343030ull,0x303065783009090aull,0x7830203933343265ull,
0x3038373030303038ull,0x3138303065783020ull,0x3834783020313463ull,0x0a20323837383230ull,
0x3030303178300909ull,0x3078302039333038ull,0x2033303030303030ull,0x3038303030317830ull,
0x3030307830206433ull,0x090a203330303030ull,0x3330303032783009ull,0x3430783020353632ull,
0x3020303837343330ull,0x3330326530306578ull,0x3030306378302039ull,0x09090a2030383730ull,
0x3333613130337830ull,0x3063367830206466ull,0x7830203863373430ull,0x3930633130303065ull,
0x3830303036783020ull,0x3009090a20303837ull,0x3063316530306578ull,0x3030303478302031ull,
0x3278302030383730ull,0x2064353033303030ull,0x3763353034307830ull,0x783009090a203038ull,
0x3330303931303031ull,0x3030303030783020ull,0x3031783020303832ull,0x3020333030663630ull,
0x3837303030303078ull,0x31783009090a2030ull,0x2030323232303031ull,0x3832383031347830ull,
0x3130347830203433ull,0x7830203131303362ull,0x3238373030303030ull,0x3036783009090a20ull,
0x3020313132336131ull,0x3837303130303078ull,0x3031303378302030ull,0x6378302031313830ull,
0x2030383730303134ull,0x313036783009090aull,0x7830203131303361ull,0x3038373031303030ull,
0x3030303032783020ull,0x3430783020313138ull,0x0a20303837383530ull,0x3430303378300909ull,
0x6378302031313830ull,0x2030383730303134ull,0x3863303030327830ull,0x3234307830203131ull,
0x090a203038373031ull,0x3065303064783009ull,0x3061783020393038ull,0x3020303837303038ull,
0x3038383830303278ull,0x3030303078302039ull,0x09090a2033303030ull,0x3430653030647830ull,
0x3830617830203130ull,0x090a203138373030ull,0x65646f630a7d0a7dull,0x656d616e090a7b20ull,
0x4d36315a5f203d20ull,0x6c72614365746e6full,0x506563756465526full,0x74704f545f5f3431ull,
0x65756c61566e6f69ull,0x206d656d6c090a69ull,0x656d73090a30203dull,0x38323134203d206dull,
0x3d2020676572090aull,0x726162090a363120ull,0x63090a31203d2020ull,0x090a7b2074736e6full,
0x6d616e6765730909ull,0x736e6f63203d2065ull,0x6765730909090a74ull,0x31203d20206d756eull,
0x7366666f0909090aull,0x0a30203d20207465ull,0x7365747962090909ull,0x0a3631203d202020ull,
0x0a7b206d656d0909ull,0x3030307830090909ull,0x7830206666303030ull,0x6637303030303030ull,
0x3030303030783020ull,0x3030783020663330ull,0x0a20663130303030ull,0x090a7d090a7d0909ull,
0x2065646f636e6962ull,0x3061783009090a7bull,0x3020353130303030ull,0x3837303030343078ull,
0x3038303378302030ull,0x3678302031306130ull,0x2030643763303463ull,0x303061783009090aull,
0x7830206466313030ull,0x3863373431306330ull,0x6632303061783020ull,0x3030783020333030ull,
0x0a20303030303030ull,0x3030303178300909ull,0x3078302031316130ull,0x2030383763333036ull,
0x3066323030317830ull,0x3030307830203330ull,0x090a203030313130ull,0x3030303031783009ull,
0x3434783020313063ull,0x3020303837633030ull,0x3063343130303478ull,0x3032303078302035ull,
0x09090a2030383730ull,0x3230303130337830ull,0x3134637830203530ull,0x7830203038373030ull,
0x6431323430303061ull,0x3030323430783020ull,0x3009090a20303837ull,0x3063343030303678ull,
0x3032303078302035ull,0x3178302030383734ull,0x2039313830303030ull,0x3763333034307830ull,
0x783009090a203038ull,0x3130383033303033ull,0x3030313463783020ull,0x3033783020303837ull,
0x3020353365303330ull,0x3837303031346378ull,0x33783009090a2030ull,0x2035303230343030ull,
0x3730303134637830ull,0x3230327830203038ull,0x7830203133303830ull,0x3338303030303030ull,
0x3032783009090a20ull,0x3020643230383032ull,0x3030303030303078ull,0x3030303278302033ull,
0x3078302039333863ull,0x2030383734303234ull,0x303031783009090aull,0x7830203930303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3030783020643030ull,0x0a20333030303030ull,
0x3530303378300909ull,0x3678302064666463ull,0x2038643763303263ull,0x3034323030617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3832303031783009ull,0x3031783020383261ull,
0x3020303034383030ull,0x3036303030303178ull,0x3330363078302035ull,0x09090a2030383763ull,
0x3034323030317830ull,0x3030307830203330ull,0x7830203038323130ull,0x3132633034303033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3363313030303278ull,0x3230343078302064ull,
0x6478302030383730ull,0x2031326531653030ull,0x3730303830387830ull,0x783009090a203038ull,
0x3930303130303065ull,0x3830303036783020ull,0x3032783020303837ull,0x3020313265393830ull,
0x3030303030303078ull,0x64783009090a2033ull,0x2031323031653030ull,0x3730303830387830ull,
0x3030657830203038ull,0x7830203130303130ull,0x3038373030303036ull,0x3032783009090a20ull,
0x3020393234393030ull,0x3130303030303078ull,0x6130303378302033ull,0x3678302064666463ull,
0x2038643730313263ull,0x303032783009090aull,0x7830206433653930ull,0x3330313030303030ull,
0x6231303031783020ull,0x3030783020333030ull,0x0a20303832313030ull,0x3030303078300909ull,
0x6378302035303831ull,0x2032383730303030ull,0x3030303034307830ull,0x3234657830203130ull,
0x090a203038373830ull,0x3030303430783009ull,0x3465783020313032ull,0x3020303837633032ull,
0x3036313030303078ull,0x3030306378302035ull,0x09090a2030383730ull,0x6130303030327830ull,
0x3034307830203531ull,0x7830203038376331ull,0x3130303030303430ull,0x3030323465783020ull,
0x3009090a20303837ull,0x3032303030343078ull,0x3032346578302031ull,0x3378302030383734ull,
0x2064666230303830ull,0x3763303463367830ull,0x783009090a203864ull,0x3831653836303032ull,
0x3962303032783020ull,0x3032783020633261ull,0x3020313361313030ull,0x3837303330343078ull,
0x31783009090a2030ull,0x2033303032313030ull,0x3231303030307830ull,0x3030667830203038ull,
0x7830203130303030ull,0x3230303030303065ull,0x3061783009090a20ull,0x3020333030663930ull,
0x3030303030303078ull,0x3030303178302030ull,0x3078302031303830ull,0x2030383763333034ull,
0x303031783009090aull,0x7830203330306639ull,0x3030313030303030ull,0x6666313638783020ull,
0x3030783020333065ull,0x0a20303030303030ull,0x3138303378300909ull,0x3678302064663130ull,
0x2038633730313463ull,0x3035343030617830ull,0x3030307830203330ull,0x090a203030303030ull,
0x3534303031783009ull,0x3030783020333030ull,0x3020303832303030ull,0x3030303330303078ull,
0x3030306378302035ull,0x09090a2030383730ull,0x3031343034317830ull,0x3034347830203930ull,
0x7830203038376330ull,0x6430323134303431ull,0x6330303434783020ull,0x3009090a20303837ull,
0x3130313630343178ull,0x3030343478302039ull,0x3178302030383763ull,0x2064313231363034ull,
0x3763303034347830ull,0x783009090a203038ull,0x3930343030303065ull,0x3831303036783020ull,
0x3430783020303837ull,0x3020313030313430ull,0x3837383032346578ull,0x30783009090a2030ull,
0x2031303231343034ull,0x3763303234657830ull,0x3035317830203038ull,0x7830203830306630ull,
0x6330326630303531ull,0x3431783009090a20ull,0x3020393130313230ull,0x3837633030343478ull,
0x3230343178302030ull,0x3478302064313231ull,0x2030383763303034ull,0x303065783009090aull,
0x7830203930343030ull,0x3038373831303036ull,0x3130303430783020ull,0x3465783020313030ull,
0x0a20303837383032ull,0x3030343078300909ull,0x6578302031303231ull,0x2030383763303234ull,
0x3030303030667830ull,0x3030657830203130ull,0x090a203230303030ull,0x6666313638783009ull,
0x3030783020333065ull,0x3020303030303030ull,0x6631303238303378ull,0x3134633678302064ull,
0x09090a2038633730ull,0x3038353030617830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3330303835303031ull,0x3030303030783020ull,0x3009090a20303832ull,0x3030303330303078ull,
0x3030306378302035ull,0x3178302030383730ull,0x2039303031343034ull,0x3763303034347830ull,
0x783009090a203038ull,0x6430323134303431ull,0x6330303434783020ull,0x3431783020303837ull,
0x3020393130313530ull,0x3837633030343478ull,0x31783009090a2030ull,0x2064313231353034ull,
0x3763303034347830ull,0x3030657830203038ull,0x7830203930343030ull,0x3038373831303036ull,
0x3430783009090a20ull,0x3020313030313430ull,0x3837383032346578ull,0x3430343078302030ull,
0x6578302031303231ull,0x2030383763303234ull,0x303531783009090aull,0x7830203830306630ull,
0x6330326630303531ull,0x3131303431783020ull,0x3434783020393130ull,0x0a20303837633030ull,
0x3130343178300909ull,0x3478302064313231ull,0x2030383763303034ull,0x3430303030657830ull,
0x3030367830203930ull,0x090a203038373831ull,0x3130303430783009ull,0x3465783020313030ull,
0x3020303837383032ull,0x3032313030343078ull,0x3032346578302031ull,0x09090a2030383763ull,
0x3030303030667830ull,0x3030657830203130ull,0x7830203230303030ull,0x3330656666313638ull,
0x3030303030783020ull,0x3009090a20303030ull,0x6631303338303378ull,0x3134633678302064ull,
0x6178302038633730ull,0x2033303062393030ull,0x3030303030307830ull,0x783009090a203030ull,
0x3330306239303031ull,0x3030303030783020ull,0x3030783020303832ull,0x3020353030303330ull,
0x3837303030306378ull,0x31783009090a2030ull,0x2039303031343034ull,0x3763303034347830ull,
0x3034317830203038ull,0x7830206430323134ull,0x3038376330303434ull,0x3431783009090a20ull,
0x3020393130393430ull,0x3837633030343478ull,0x3430343178302030ull,0x3478302064313239ull,
0x2030383763303034ull,0x303065783009090aull,0x7830203132343030ull,0x3038373831303036ull,
0x3134303430783020ull,0x3465783020313030ull,0x0a20303837303232ull,0x3430343078300909ull,
0x6578302031303231ull,0x2030383734323234ull,0x3066303035317830ull,0x3035317830203830ull,
0x090a206330326630ull,0x3930303431783009ull,0x3434783020393130ull,0x3020303837633030ull,
0x3132393030343178ull,0x3030343478302064ull,0x09090a2030383763ull,0x3430303030657830ull,
0x3030367830203931ull,0x7830203038373831ull,0x3130303130303430ull,0x3831323465783020ull,
0x3009090a20303837ull,0x3032313030343078ull,0x3132346578302031ull,0x3178302030383763ull,
0x2039303035343034ull,0x3763303034347830ull,0x783009090a203038ull,0x6430323534303431ull,
0x6330303434783020ull,0x3065783020303837ull,0x3020313230313030ull,0x3837383030303678ull,
0x30783009090a2030ull,0x2031303031343034ull,0x3730323234657830ull,0x3034307830203038ull,
0x7830203130323134ull,0x3038373432323465ull,0x3431783009090a20ull,0x3020393030353030ull,
0x3837633030343478ull,0x3030343178302030ull,0x3478302064303235ull,0x2030383763303034ull,
0x303065783009090aull,0x7830203931633030ull,0x3038373830303036ull,0x3130303430783020ull,
0x3465783020313030ull,0x0a20303837383132ull,0x3030343078300909ull,0x6578302031303231ull,
0x2030383763313234ull,0x3033343034317830ull,0x3034347830203930ull,0x090a203038376330ull,
0x3334303431783009ull,0x3434783020643032ull,0x3020303837633030ull,0x3230313030306578ull,
0x3030303678302031ull,0x09090a2030383738ull,0x3031343034307830ull,0x3234657830203130ull,
0x7830203038373032ull,0x3130323134303430ull,0x3432323465783020ull,0x3009090a20303837ull,
0x3030333030343178ull,0x3030343478302039ull,0x3178302030383763ull,0x2064303233303034ull,
0x3763303034347830ull,0x783009090a203038ull,0x3931633030303065ull,0x3830303036783020ull,
0x3430783020303837ull,0x3020313030313030ull,0x3837383132346578ull,0x30783009090a2030ull,
0x2031303231303034ull,0x3763313234657830ull,0x3034317830203038ull,0x7830203930303234ull,
0x3038376330303434ull,0x3431783009090a20ull,0x3020643032323430ull,0x3837633030343478ull,
0x3030306578302030ull,0x3678302031323031ull,0x2030383738303030ull,0x303430783009090aull,
0x7830203130303134ull,0x3038373032323465ull,0x3134303430783020ull,0x3465783020313032ull,
0x0a20303837343232ull,0x3030343178300909ull,0x3478302039303032ull,0x2030383763303034ull,
0x3232303034317830ull,0x3034347830206430ull,0x090a203038376330ull,0x3030303065783009ull,
0x3036783020393163ull,0x3020303837383030ull,0x3030313030343078ull,0x3132346578302031ull,
0x09090a2030383738ull,0x3231303034307830ull,0x3234657830203130ull,0x7830203038376331ull,
0x3930383134303431ull,0x6330303434783020ull,0x3009090a20303837ull,0x3061313430343178ull,
0x3030343478302064ull,0x6578302030383763ull,0x2031323031303030ull,0x3738303030367830ull,
0x783009090a203038ull,0x3130303134303430ull,0x3032323465783020ull,0x3430783020303837ull,
0x3020313032313430ull,0x3837343232346578ull,0x31783009090a2030ull,0x2038303866303035ull,
0x6166303035317830ull,0x3030657830206330ull,0x7830203931633030ull,0x3038373830303036ull,
0x3430783009090a20ull,0x3020313030313030ull,0x3837383132346578ull,0x3030343078302030ull,
0x6578302031303231ull,0x2030383763313234ull,0x303431783009090aull,0x7830203930343134ull,
0x3038376330303434ull,0x3134303431783020ull,0x3434783020643036ull,0x0a20303837633030ull,
0x3030306578300909ull,0x3678302039303031ull,0x2030383738303030ull,0x3031343034307830ull,
0x3234657830203130ull,0x090a203038373830ull,0x3134303430783009ull,0x3465783020313032ull,
0x3020303837633032ull,0x3034663030353178ull,0x3030353178302038ull,0x09090a2063303666ull,
0x6330303030657830ull,0x3030367830203930ull,0x7830203038373830ull,0x3130303130303430ull,
0x3830323465783020ull,0x3009090a20303837ull,0x3032313030343078ull,0x3032346578302031ull,
0x6678302030383763ull,0x2031303030303030ull,0x3030303030657830ull,0x783009090a203230ull,
0x3130303830303032ull,0x3030303030783020ull,0x3033783020333130ull,0x3020646631303038ull,
0x6337633034633678ull,0x31783009090a2038ull,0x2033303033333030ull,0x3230303030307830ull,
0x3730337830203038ull,0x7830206466393063ull,0x6163373431303436ull,0x3033783009090a20ull,
0x3020333030303030ull,0x3832303030303078ull,0x3030306178302030ull,0x3078302031306334ull,
0x2030383730303234ull,0x303033783009090aull,0x7830203930303034ull,0x3038373030313463ull,
0x3134303031783020ull,0x3434783020313030ull,0x0a20303837633030ull,0x3430303178300909ull,
0x3478302035303231ull,0x2030383763303034ull,0x3430303031327830ull,0x3837307830203930ull,
0x090a203038373030ull,0x3065303064783009ull,0x3061783020313034ull,0x3020303837303038ull,
0x3030663030313178ull,0x3030313178302030ull,0x09090a2034303266ull,0x3438383030327830ull,
0x3030307830203930ull,0x7830203330303030ull,0x3130343065303064ull,0x3030383061783020ull,
0x0a7d090a20313837ull,0x7b2065646f630a7dull,0x3d20656d616e090aull,0x766e6936315a5f20ull,
0x4b444e4365737265ull,0x5366506c656e7265ull,0x6d656d6c090a6a5full,0x6d73090a30203d20ull,
0x0a3633203d206d65ull,0x203d202067657209ull,0x20726162090a3532ull,0x6f63090a30203d20ull,
0x09090a7b2074736eull,0x656d616e67657309ull,0x74736e6f63203d20ull,0x6e6765730909090aull,
0x0a31203d20206d75ull,0x657366666f090909ull,0x090a30203d202074ull,0x2073657479620909ull,
0x090a3231203d2020ull,0x090a7b206d656d09ull,0x3030303078300909ull,0x3878302066663730ull,
0x2066666666663030ull,0x3030306666337830ull,0x0a7d09090a203030ull,0x636e6962090a7d09ull,
0x09090a7b2065646full,0x6463633730337830ull,0x3234367830206466ull,0x7830203863373830ull,
0x6466666363373033ull,0x3830323436783020ull,0x3009090a20386332ull,0x3063343030306178ull,
0x3032343078302035ull,0x6178302030383730ull,0x2031333234303030ull,0x3730303234307830ull,
0x783009090a203038ull,0x3130303030303061ull,0x3030303430783020ull,0x3031783020303837ull,
0x3020333030383332ull,0x3832303030303078ull,0x36783009090a2030ull,0x2031343831313030ull,
0x3730303030367830ull,0x3130337830203038ull,0x7830206466316430ull,0x3863376330323436ull,
0x3033783009090a20ull,0x3020333030303030ull,0x3832303030303078ull,0x3030306178302030ull,
0x3078302031303834ull,0x2030383730303234ull,0x303034783009090aull,0x7830206434383130ull,
0x3038373031303030ull,0x3232303033783020ull,0x3463783020393430ull,0x0a20303837303031ull,
0x3230303378300909ull,0x6378302035343632ull,0x2030383730303134ull,0x6363303030327830ull,
0x3234307830203130ull,0x090a203038373834ull,0x3065303064783009ull,0x3038783020313030ull,
0x3020303837303063ull,0x3130383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x6633307830203531ull,0x7830203330303066ull,0x3930303030303061ull,
0x3030343463783020ull,0x3009090a20303837ull,0x6635303430306578ull,0x3130306578302064ull,
0x3178302038633738ull,0x2031303038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3530303830303031ull,0x3030303030783020ull,0x3065783020333030ull,0x3020646635303030ull,
0x3431633030306578ull,0x61783009090a2038ull,0x2033303030333230ull,0x3030303030307830ull,
0x3030317830203030ull,0x7830203330306231ull,0x3030313030303030ull,0x3031783009090a20ull,
0x3020313030383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302035303038ull,
0x2033303038666666ull,0x323031783009090aull,0x7830203330303033ull,0x3038373030303030ull,
0x3830303031783020ull,0x3030783020313030ull,0x0a20333030303030ull,0x3030303178300909ull,
0x3078302035303038ull,0x2033303030656662ull,0x3038313230317830ull,0x6561307830203131ull,
0x090a206661373431ull,0x3837303031783009ull,0x3330783020353130ull,0x3020373165616466ull,
0x3334303030306578ull,0x3030303678302031ull,0x09090a2030383730ull,0x3931343030657830ull,
0x3130657830206466ull,0x7830203863373430ull,0x3330306632323061ull,0x3030303030783020ull,
0x3009090a20303030ull,0x3030323430303178ull,0x3030303078302033ull,0x6578302030303130ull,
0x2031313831633030ull,0x3730303030387830ull,0x783009090a203038ull,0x3931303838333031ull,
0x3733373530783020ull,0x3031783020373737ull,0x3020643130383932ull,0x3037393330633078ull,
0x31783009090a2066ull,0x2039303038633330ull,0x6333373463307830ull,0x3130317830206636ull,
0x7830206430303832ull,0x3332623434303430ull,0x3031783009090a20ull,0x3020313230383730ull,
0x6138353530323078ull,0x3033303178302037ull,0x3078302035323038ull,0x2066623039303034ull,
0x333031783009090aull,0x7830203130303864ull,0x3735653130373030ull,0x3866323031783020ull,
0x6330783020353030ull,0x0a20666630353330ull,0x3630306578300909ull,0x3478302039303830ull,
0x2030383738303030ull,0x3830383030657830ull,0x3030347830203132ull,0x090a203038373030ull,
0x3865313031783009ull,0x6130783020393130ull,0x3020663361343565ull,0x3130383033303178ull,
0x3330633078302064ull,0x09090a2037643932ull,0x3038633230317830ull,0x3139307830203130ull,
0x7830203330353138ull,0x3530303837313031ull,0x3733303430783020ull,0x3009090a20373531ull,
0x3034303430306578ull,0x3130303478302039ull,0x6578302030383738ull,0x2031323830383030ull,
0x3730303030347830ull,0x783009090a203038ull,0x3931303864303031ull,0x3832623130783020ull,
0x3031783020333236ull,0x3020643130383331ull,0x6430343030343078ull,0x31783009090a2062ull,
0x2031303038643230ull,0x3035353630307830ull,0x3330317830203337ull,0x7830203530303830ull,
0x3732663032306330ull,0x3065783009090a20ull,0x3020393034303430ull,0x3837383130303478ull,
0x3830306578302030ull,0x3478302039313830ull,0x2030383730303030ull,0x303031783009090aull,
0x7830203130303830ull,0x3330303030303030ull,0x3830303031783020ull,0x3330783020353030ull,
0x0a20333030306666ull,0x3230306578300909ull,0x3878302039303831ull,0x2030383730303030ull,
0x3830363030657830ull,0x3030347830203131ull,0x090a203038373030ull,0x3831303031783009ull,
0x3031783020303034ull,0x3020343036383030ull,0x3038383130303178ull,0x3030303178302038ull,
0x09090a2063306138ull,0x3062363430327830ull,0x3030307830203330ull,0x7830203038373030ull,
0x3330306632323031ull,0x3030303030783020ull,0x3009090a20303837ull,0x3030383030303178ull,
0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x6466393130303065ull,0x3031303065783020ull,0x3061783020386337ull,
0x3020333030663032ull,0x3030303030303078ull,0x31783009090a2030ull,0x2033303064323130ull,
0x3130303030307830ull,0x3030317830203030ull,0x7830203130303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020353030383030ull,0x3030306666333078ull,0x3030306578302033ull,
0x3678302039303430ull,0x2030383730303034ull,0x303031783009090aull,0x7830203931303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3730783020643130ull,0x0a20333030306666ull,
0x3030306178300909ull,0x6378302031313430ull,0x2030383734303534ull,0x3438313030317830ull,
0x3030317830203030ull,0x090a203430363830ull,0x3036303065783009ull,0x3065783020646639ull,
0x3020386337633030ull,0x3030396230306178ull,0x3030303078302033ull,0x09090a2030303030ull,
0x3033353030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x3930343030303065ull,
0x3830303036783020ull,0x3009090a20303837ull,0x3030396230303178ull,0x3030303078302033ull,
0x3178302030383730ull,0x2039313038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x6431303830303031ull,0x3030303030783020ull,0x3065783020333030ull,0x3020646635303630ull,
0x6337343030306578ull,0x31783009090a2038ull,0x2033303061353030ull,0x3130303030307830ull,
0x3030317830203030ull,0x7830203930303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643030383030ull,0x3030386666663078ull,0x6230303178302033ull,0x3078302033303039ull,
0x2030383730303030ull,0x303031783009090aull,0x7830203931303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3030783020643130ull,0x0a20333030303030ull,0x3630306578300909ull,
0x6578302064663530ull,0x2038633738303030ull,0x3031363030317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3830303031783009ull,0x3030783020393030ull,0x3020333030303030ull,
0x3030383030303178ull,0x6666663078302064ull,0x09090a2033303030ull,0x3039623030317830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3931303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3130383030303178ull,0x6666373078302064ull,0x6578302033303030ull,
0x2064663930363030ull,0x3738303030657830ull,0x783009090a203863ull,0x3330303636303031ull,
0x3030303030783020ull,0x3031783020303031ull,0x3020333030396230ull,0x3837303030303078ull,
0x31783009090a2030ull,0x2031313038303030ull,0x3030303030307830ull,0x3030317830203330ull,
0x7830203531303830ull,0x3330303031303030ull,0x3065783009090a20ull,0x3020646635303430ull,
0x6337343030306578ull,0x3730306178302038ull,0x3078302033303031ull,0x2030303030303030ull,
0x303031783009090aull,0x7830203330303037ull,0x3030313030303030ull,0x3830303031783020ull,
0x3030783020313030ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302035303038ull,
0x2033303030353334ull,0x3430303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3861303031783009ull,0x6630783020393030ull,0x3020666666666666ull,0x3030313730303178ull,
0x3030303078302033ull,0x09090a2030383730ull,0x3866303030317830ull,0x3035307830203930ull,
0x7830203038376333ull,0x3131323031383064ull,0x3030343430783020ull,0x3009090a20323837ull,
0x3032303431303378ull,0x3031636578302064ull,0x6478302030383730ull,0x2035303830323830ull,
0x3734303434307830ull,0x783009090a203038ull,0x6430363030383064ull,0x3030343430783020ull,
0x3031783020303837ull,0x3020313130386430ull,0x6233663736363078ull,0x31783009090a2066ull,
0x2035313038653130ull,0x6136666633307830ull,0x3030317830206230ull,0x7830203833303830ull,
0x6333323831303031ull,0x3032783009090a20ull,0x3020313034303030ull,0x3837633030343078ull,
0x3430306578302030ull,0x6578302064666431ull,0x2038633730313030ull,0x303061783009090aull,
0x7830203330303138ull,0x3030303030303030ull,0x3831303032783020ull,0x6630783020313530ull,
0x0a20336366666666ull,0x3830303178300909ull,0x3078302033303031ull,0x2030303130303030ull,
0x6339303030317830ull,0x3030317830203030ull,0x090a203430653931ull,0x3830303032783009ull,
0x6630783020353032ull,0x3020333030306666ull,0x3538613130303278ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3038303030317830ull,0x3030317830203833ull,0x7830206333323831ull,
0x3130303030303066ull,0x3030303065783020ull,0x3009090a20323030ull,0x3030383030303178ull,
0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,0x3030666633307830ull,
0x783009090a203330ull,0x3130633130303065ull,0x3030303036783020ull,0x3031783020303837ull,
0x3020303030383030ull,0x3032383130303178ull,0x32783009090a2034ull,0x2033303064343530ull,
0x3730303030307830ull,0x3030617830203038ull,0x7830203930383230ull,0x3038373031343434ull,
0x3031783009090a20ull,0x3020313130383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302035313038ull,0x2033303030666662ull,0x303065783009090aull,0x7830203931633130ull,
0x3038373031303036ull,0x3830303031783020ull,0x3031783020303130ull,0x0a20343132383130ull,
0x3430306578300909ull,0x3878302031306330ull,0x2030383730303030ull,0x3030303030657830ull,
0x3030367830203132ull,0x090a203038373030ull,0x3865313031783009ull,0x3330783020313030ull,
0x3020336630386561ull,0x3030386230303178ull,0x6265333078302035ull,0x09090a2033383331ull,
0x3038343030317830ull,0x6238307830203933ull,0x7830203362386137ull,0x6433303835323031ull,
0x3064653330783020ull,0x3009090a20336565ull,0x3230313830306578ull,0x3030303878302039ull,
0x6578302030383730ull,0x2031303431303030ull,0x3738333030347830ull,0x783009090a203038ull,
0x3933303866323031ull,0x3230663930783020ull,0x3031783020373736ull,0x3020643330383632ull,
0x3262336665333078ull,0x65783009090a2037ull,0x2031303431303030ull,0x3738333030347830ull,
0x3130317830203038ull,0x7830203933303836ull,0x3739306261396130ull,0x3031783009090a20ull,
0x3020643330386230ull,0x3534373166333078ull,0x3030306578302066ull,0x3478302031303431ull,
0x2030383738333030ull,0x313031783009090aull,0x7830203933303834ull,0x3731356231643230ull,
0x3837303031783020ull,0x3330783020643330ull,0x0a20663137633366ull,0x3030306578300909ull,
0x3478302031303431ull,0x2030383738333030ull,0x3038643230317830ull,0x3239307830203933ull,
0x090a203337656233ull,0x3834323031783009ull,0x3330783020643330ull,0x3020333934323666ull,
0x3034313030306578ull,0x3330303478302031ull,0x09090a2030383738ull,0x3038343030317830ull,
0x3939307830203933ull,0x7830206633613939ull,0x6433303839313031ull,0x3938663330783020ull,
0x3009090a20623939ull,0x3034313030306578ull,0x3330303478302031ull,0x3178302030383738ull,
0x2039333038343130ull,0x3535353535307830ull,0x783009090a203735ull,0x6433303835313031ull,
0x3562663330783020ull,0x3065783020373535ull,0x3020393334313030ull,0x3837383330303478ull,
0x65783009090a2030ull,0x2031303031303030ull,0x3738313034367830ull,0x3030327830203038ull,
0x7830203530323830ull,0x3330303031303030ull,0x3065783009090a20ull,0x3020393234316530ull,
0x3837303030303878ull,0x3030303178302030ull,0x3178302038333038ull,0x2063333238303030ull,
0x303033783009090aull,0x7830203135386130ull,0x3330303030303030ull,0x3866323031783020ull,
0x6630783020313030ull,0x0a20663933616665ull,0x3230303178300909ull,0x3078302035303038ull,
0x2037653236656633ull,0x3031363030657830ull,0x3034347830203933ull,0x090a203038373833ull,
0x3230303061783009ull,0x3434783020313538ull,0x3020303837303134ull,0x3134303030306578ull,
0x3230303478302039ull,0x09090a2030383730ull,0x3031613030657830ull,0x3030387830203932ull,
0x7830203038373030ull,0x3130383230303065ull,0x3831303034783020ull,0x3009090a20303837ull,
0x3138306530306578ull,0x3230303478302031ull,0x6578302030383738ull,0x2031303031303030ull,
0x3730303034367830ull,0x783009090a203038ull,0x3131383030303065ull,0x3030303836783020ull,
0x3031783020303837ull,0x3020313030386633ull,0x3038393362333078ull,0x31783009090a2033ull,
0x2035303038653130ull,0x6261376333307830ull,0x3030657830206263ull,0x7830203130343030ull,
0x3038373031303034ull,0x3065783009090a20ull,0x3020393063303030ull,0x3837303030303678ull,
0x3030306178302030ull,0x6578302031313430ull,0x2032383734303434ull,0x303061783009090aull,
0x7830203931343030ull,0x3038373430353463ull,0x3830303031783020ull,0x3030783020313230ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302035323038ull,0x2033303030666637ull,
0x3838313030317830ull,0x3030317830203030ull,0x090a203430613830ull,0x3038303065783009ull,
0x3065783020646664ull,0x3020386337633030ull,0x3030623231306178ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3034633030317830ull,0x3030307830203330ull,0x7830203038323030ull,
0x3130343030303065ull,0x3830303036783020ull,0x3009090a20303837ull,0x3030303030306178ull,
0x3034346578302031ull,0x3178302030383734ull,0x2033303062323130ull,0x3730303030307830ull,
0x783009090a203038ull,0x3930303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020643030383030ull,0x3030303030303078ull,0x65783009090a2033ull,0x2064663930323030ull,
0x3734303030657830ull,0x3030317830203863ull,0x7830203330306263ull,0x3030313030303030ull,
0x3031783009090a20ull,0x3020313030383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302035303038ull,0x2033303038666666ull,0x313031783009090aull,0x7830203330306232ull,
0x3038373030303030ull,0x3830303031783020ull,0x3030783020393030ull,0x0a20333030303030ull,
0x3030303178300909ull,0x3078302064303038ull,0x2033303030303030ull,0x3930323030657830ull,
0x3030657830206466ull,0x090a203863373830ull,0x3264303031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x6666307830203530ull,0x7830203330303066ull,0x3330306232313031ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030383030303178ull,0x3030303078302039ull,
0x3178302033303030ull,0x2064303038303030ull,0x3030666637307830ull,0x783009090a203330ull,
0x6466643032303065ull,0x3830303065783020ull,0x3031783020386337ull,0x3020333030386430ull,
0x3031303030303078ull,0x31783009090a2030ull,0x2030303838303030ull,0x6138313030317830ull,
0x3130317830203430ull,0x7830203330306232ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020393030383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302064303038ull,
0x2033303030313030ull,0x303065783009090aull,0x7830206466393032ull,0x3863373430303065ull,
0x3365303061783020ull,0x3030783020333030ull,0x0a20303030303030ull,0x6530303178300909ull,
0x3078302033303032ull,0x2030303130303030ull,0x3038303030317830ull,0x3030307830203130ull,
0x090a203330303030ull,0x3830303031783009ull,0x3430783020353030ull,0x3020333030303533ull,
0x3038303030306578ull,0x3030303878302031ull,0x09090a2030383730ull,0x3038613030317830ull,
0x6666307830203930ull,0x7830206666666666ull,0x3330303365303031ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3038663030303178ull,0x3330343078302039ull,0x6478302030383763ull,
0x2031313230313830ull,0x3730303434307830ull,0x783009090a203238ull,0x6430323034313033ull,
0x3030316365783020ull,0x3064783020303837ull,0x3020353038303238ull,0x3837343034343078ull,
0x64783009090a2030ull,0x2064303630303830ull,0x3730303434307830ull,0x3030317830203038ull,
0x7830203131303864ull,0x6662336637363630ull,0x3031783009090a20ull,0x3020353130386531ull,
0x3061366666333078ull,0x3030303178302062ull,0x3178302038333038ull,0x2063333238313030ull,
0x303032783009090aull,0x7830203130343030ull,0x3038376330303430ull,0x3134303065783020ull,
0x3065783020646664ull,0x0a20386337303130ull,0x6630306178300909ull,0x3078302033303033ull,
0x2030303030303030ull,0x3038313030327830ull,0x6666307830203135ull,0x090a203363666666ull,
0x3366303031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3063393030303178ull,
0x3030303178302030ull,0x09090a2034306539ull,0x3238303030327830ull,0x6666307830203530ull,
0x7830203330303066ull,0x3135386131303032ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3330383130303178ull,0x3030303178302038ull,0x6678302063333238ull,0x2031303030303030ull,
0x3030303030657830ull,0x783009090a203230ull,0x3130303830303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020353030383030ull,0x3030306666333078ull,0x65783009090a2033ull,
0x2031306331303030ull,0x3730303030367830ull,0x3030317830203038ull,0x7830203030303830ull,
0x3430323831303031ull,0x3032783009090a20ull,0x3020333030643435ull,0x3837303030303078ull,
0x3030306178302030ull,0x3478302039303832ull,0x2030383730313434ull,0x303031783009090aull,
0x7830203131303830ull,0x3330303030303030ull,0x3830303031783020ull,0x6230783020353130ull,
0x0a20333030306666ull,0x3030306578300909ull,0x3678302039316331ull,0x2030383730313030ull,
0x3038303030317830ull,0x3030317830203031ull,0x090a203431323830ull,0x3034303065783009ull,
0x3038783020313063ull,0x3020303837303030ull,0x3230303030306578ull,0x3030303678302031ull,
0x09090a2030383730ull,0x3038653130317830ull,0x6133307830203130ull,0x7830203366303865ull,
0x3530303862303031ull,0x3162653330783020ull,0x3009090a20333833ull,0x3330383430303178ull,
0x3762383078302039ull,0x3178302033623861ull,0x2064333038353230ull,0x6530646533307830ull,
0x783009090a203365ull,0x3932303138303065ull,0x3030303038783020ull,0x3065783020303837ull,
0x3020313034313030ull,0x3837383330303478ull,0x31783009090a2030ull,0x2039333038663230ull,
0x3632306639307830ull,0x3230317830203737ull,0x7830206433303836ull,0x3732623366653330ull,
0x3065783009090a20ull,0x3020313034313030ull,0x3837383330303478ull,0x3631303178302030ull,
0x3078302039333038ull,0x2037393062613961ull,0x303031783009090aull,0x7830206433303862ull,
0x6635343731663330ull,0x3130303065783020ull,0x3034783020313034ull,0x0a20303837383330ull,
0x3431303178300909ull,0x3078302039333038ull,0x2037313562316432ull,0x3038373030317830ull,
0x6633307830206433ull,0x090a206631376333ull,0x3130303065783009ull,0x3034783020313034ull,
0x3020303837383330ull,0x3330386432303178ull,0x3332393078302039ull,0x09090a2033376562ull,
0x3038343230317830ull,0x6633307830206433ull,0x7830203339343236ull,0x3130343130303065ull,
0x3833303034783020ull,0x3009090a20303837ull,0x3330383430303178ull,0x3939393078302039ull,
0x3178302066336139ull,0x2064333038393130ull,0x3939386633307830ull,0x783009090a206239ull,
0x3130343130303065ull,0x3833303034783020ull,0x3031783020303837ull,0x3020393330383431ull,
0x3535353535353078ull,0x31783009090a2037ull,0x2064333038353130ull,0x3535626633307830ull,
0x3030657830203735ull,0x7830203933343130ull,0x3038373833303034ull,0x3065783009090a20ull,
0x3020313030313030ull,0x3837383130343678ull,0x3030303278302030ull,0x3078302035303238ull,
0x2033303030313030ull,0x303065783009090aull,0x7830203932343165ull,0x3038373030303038ull,
0x3831303031783020ull,0x3031783020383330ull,0x0a20633332383030ull,0x3030303378300909ull,
0x3078302031353861ull,0x2033303030303030ull,0x3038663230317830ull,0x6566307830203130ull,
0x090a206639336166ull,0x3832303031783009ull,0x3330783020353030ull,0x3020376532366566ull,
0x3330313630306578ull,0x3330343478302039ull,0x09090a2030383738ull,0x3832303030617830ull,
0x3434347830203135ull,0x7830203038373031ull,0x3931343030303065ull,0x3032303034783020ull,
0x3009090a20303837ull,0x3230316130306578ull,0x3030303878302039ull,0x6578302030383730ull,
0x2031303832303030ull,0x3738313030347830ull,0x783009090a203038ull,0x3131383065303065ull,
0x3832303034783020ull,0x3065783020303837ull,0x3020313030313030ull,0x3837303030343678ull,
0x65783009090a2030ull,0x2031313830303030ull,0x3730303038367830ull,0x3330317830203038ull,
0x7830203130303866ull,0x3330383933623330ull,0x3031783009090a20ull,0x3020353030386531ull,
0x6362613763333078ull,0x3030306578302062ull,0x3478302031303430ull,0x2030383730313030ull,
0x303065783009090aull,0x7830203130633030ull,0x3038373030303036ull,0x3030303066783020ull,
0x3065783020313030ull,0x0a20323030303030ull,0x3032303178300909ull,0x3078302033303066ull,
0x2030383730303030ull,0x3430303030617830ull,0x3534637830203131ull,0x090a203038373430ull,
0x3830303031783009ull,0x3030783020393130ull,0x3020333030303030ull,0x3130383030303178ull,
0x6666373078302064ull,0x09090a2033303030ull,0x3438303030317830ull,0x3030317830203030ull,
0x7830203430363831ull,0x6466393036303065ull,0x6330303065783020ull,0x3009090a20386337ull,
0x3030633931306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303036333130ull,
0x3230303030307830ull,0x783009090a203038ull,0x3930343030303065ull,0x3830303036783020ull,
0x3031783020303837ull,0x3020333030633931ull,0x3837303030303078ull,0x31783009090a2030ull,
0x2039313038303030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830206431303830ull,
0x3330303030303030ull,0x3065783009090a20ull,0x3020646635303630ull,0x6337343030306578ull,
0x3331303178302038ull,0x3078302033303064ull,0x2030303130303030ull,0x303031783009090aull,
0x7830203930303830ull,0x3330303030303030ull,0x3830303031783020ull,0x6630783020643030ull,
0x0a20333030386666ull,0x3931303178300909ull,0x3078302033303063ull,0x2030383730303030ull,
0x3038303030317830ull,0x3030307830203931ull,0x090a203330303030ull,0x3830303031783009ull,
0x3030783020643130ull,0x3020333030303030ull,0x6635303630306578ull,0x3030306578302064ull,
0x09090a2038633738ull,0x3034343130317830ull,0x3030307830203330ull,0x7830203030313030ull,
0x3930303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3030383030303178ull,
0x6666663078302064ull,0x3178302033303030ull,0x2033303063393130ull,0x3730303030307830ull,
0x783009090a203038ull,0x3931303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020643130383030ull,0x3030306666373078ull,0x65783009090a2033ull,0x2064663930363030ull,
0x3738303030657830ull,0x3130317830203863ull,0x7830203330303934ull,0x3030313030303030ull,
0x3031783009090a20ull,0x3020333030633931ull,0x3837303030303078ull,0x3030303178302030ull,
0x3078302031313038ull,0x2033303030303030ull,0x303031783009090aull,0x7830203531303830ull,
0x3330303031303030ull,0x3034303065783020ull,0x3065783020646635ull,0x0a20386337343030ull,
0x3531306178300909ull,0x3078302033303034ull,0x2030303030303030ull,0x3033353130317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3830303031783009ull,0x3030783020313030ull,
0x3020333030303030ull,0x3030383030303178ull,0x3533343078302035ull,0x09090a2033303030ull,
0x3430303030657830ull,0x3030387830203130ull,0x7830203038373030ull,0x3930303861303031ull,
0x6666666630783020ull,0x3009090a20666666ull,0x3030343531303178ull,0x3030303078302033ull,
0x3178302030383730ull,0x2039303866303030ull,0x3763333034307830ull,0x783009090a203038ull,
0x3131323031383064ull,0x3030343430783020ull,0x3033783020323837ull,0x3020643032303431ull,
0x3837303031636578ull,0x64783009090a2030ull,0x2035303830323830ull,0x3734303434307830ull,
0x3830647830203038ull,0x7830206430363030ull,0x3038373030343430ull,0x3031783009090a20ull,
0x3020313130386430ull,0x6233663736363078ull,0x6531303178302066ull,0x3078302035313038ull,
0x2062306136666633ull,0x303031783009090aull,0x7830203833303830ull,0x6333323831303031ull,
0x3030303032783020ull,0x3430783020313034ull,0x0a20303837633030ull,0x3430306578300909ull,
0x6578302064666431ull,0x2038633730313030ull,0x3034363130617830ull,0x3030307830203330ull,
0x090a203030303030ull,0x3831303032783009ull,0x6630783020313530ull,0x3020336366666666ull,
0x3030343631303178ull,0x3030303078302033ull,0x09090a2030303130ull,0x6339303030317830ull,
0x3030317830203030ull,0x7830203430653930ull,0x3530323830303032ull,0x3066666630783020ull,
0x3009090a20333030ull,0x3538613130303278ull,0x3030303078302031ull,0x3178302033303030ull,
0x2038333038313030ull,0x3238303030317830ull,0x783009090a206333ull,0x3130303030303066ull,
0x3030303065783020ull,0x3031783020323030ull,0x3020313030383030ull,0x3030303030303078ull,
0x31783009090a2033ull,0x2035303038303030ull,0x3030666633307830ull,0x3030657830203330ull,
0x7830203130633130ull,0x3038373030303036ull,0x3031783009090a20ull,0x3020303030383030ull,
0x3032383130303178ull,0x3435303278302034ull,0x3078302033303064ull,0x2030383730303030ull,
0x303061783009090aull,0x7830203930383230ull,0x3038373031343434ull,0x3830303031783020ull,
0x3030783020313130ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302035313038ull,
0x2033303030666662ull,0x6331303030657830ull,0x3030367830203931ull,0x090a203038373031ull,
0x3830303031783009ull,0x3031783020303130ull,0x3020343132383030ull,0x3063303430306578ull,
0x3030303878302031ull,0x09090a2030383730ull,0x3030303030657830ull,0x3030367830203132ull,
0x7830203038373030ull,0x3130303865313031ull,0x3865613330783020ull,0x3009090a20336630ull,
0x3030386230303178ull,0x6265333078302035ull,0x3178302033383331ull,0x2039333038343030ull,
0x3861376238307830ull,0x783009090a203362ull,0x6433303835323031ull,0x3064653330783020ull,
0x3065783020336565ull,0x3020393230313830ull,0x3837303030303878ull,0x65783009090a2030ull,
0x2031303431303030ull,0x3738333030347830ull,0x3230317830203038ull,0x7830203933303866ull,
0x3737363230663930ull,0x3031783009090a20ull,0x3020643330383632ull,0x3262336665333078ull,
0x3030306578302037ull,0x3478302031303431ull,0x2030383738333030ull,0x313031783009090aull,
0x7830203933303836ull,0x3739306261396130ull,0x3862303031783020ull,0x3330783020643330ull,
0x0a20663534373166ull,0x3030306578300909ull,0x3478302031303431ull,0x2030383738333030ull,
0x3038343130317830ull,0x6432307830203933ull,0x090a203731356231ull,0x3837303031783009ull,
0x3330783020643330ull,0x3020663137633366ull,0x3034313030306578ull,0x3330303478302031ull,
0x09090a2030383738ull,0x3038643230317830ull,0x3239307830203933ull,0x7830203337656233ull,
0x6433303834323031ull,0x3236663330783020ull,0x3009090a20333934ull,0x3034313030306578ull,
0x3330303478302031ull,0x3178302030383738ull,0x2039333038343030ull,0x6139393939307830ull,
0x783009090a206633ull,0x6433303839313031ull,0x3938663330783020ull,0x3065783020623939ull,
0x3020313034313030ull,0x3837383330303478ull,0x31783009090a2030ull,0x2039333038343130ull,
0x3535353535307830ull,0x3130317830203735ull,0x7830206433303835ull,0x3735353562663330ull,
0x3065783009090a20ull,0x3020393334313030ull,0x3837383330303478ull,0x3030306578302030ull,
0x3678302031303031ull,0x2030383738313034ull,0x303032783009090aull,0x7830203530323830ull,
0x3330303031303030ull,0x3165303065783020ull,0x3038783020393234ull,0x0a20303837303030ull,
0x3130303178300909ull,0x3178302038333038ull,0x2063333238303030ull,0x3861303030337830ull,
0x3030307830203135ull,0x090a203330303030ull,0x3866323031783009ull,0x6630783020313030ull,
0x3020663933616665ull,0x3030383230303178ull,0x6566333078302035ull,0x09090a2037653236ull,
0x3031363030657830ull,0x3034347830203933ull,0x7830203038373833ull,0x3135383230303061ull,
0x3031343434783020ull,0x3009090a20303837ull,0x3134303030306578ull,0x3230303478302039ull,
0x6578302030383730ull,0x2039323031613030ull,0x3730303030387830ull,0x783009090a203038ull,
0x3130383230303065ull,0x3831303034783020ull,0x3065783020303837ull,0x3020313138306530ull,
0x3837383230303478ull,0x65783009090a2030ull,0x2031303031303030ull,0x3730303034367830ull,
0x3030657830203038ull,0x7830203131383030ull,0x3038373030303836ull,0x3031783009090a20ull,
0x3020313030386633ull,0x3038393362333078ull,0x6531303178302033ull,0x3078302035303038ull,
0x2062636261376333ull,0x303065783009090aull,0x7830203130343030ull,0x3038373031303034ull,
0x3030303065783020ull,0x3036783020393063ull,0x0a20303837303030ull,0x3030306178300909ull,
0x6578302031313430ull,0x2032383734303434ull,0x3430303030617830ull,0x3534637830203931ull,
0x090a203038373430ull,0x3830303031783009ull,0x3030783020313230ull,0x3020333030303030ull,
0x3230383030303178ull,0x6666373078302035ull,0x09090a2033303030ull,0x3838303030317830ull,
0x3030317830203030ull,0x7830203430613831ull,0x6466643038303065ull,0x6330303065783020ull,
0x3009090a20386337ull,0x3030653032306178ull,0x3030303078302033ull,0x3178302030303030ull,
0x2033303037613130ull,0x3230303030307830ull,0x783009090a203038ull,0x3130343030303065ull,
0x3830303036783020ull,0x3061783020303837ull,0x3020313030303030ull,0x3837343034346578ull,
0x31783009090a2030ull,0x2033303065303230ull,0x3730303030307830ull,0x3030317830203038ull,
0x7830203930303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643030383030ull,
0x3030303030303078ull,0x3230306578302033ull,0x6578302064663930ull,0x2038633734303030ull,
0x313031783009090aull,0x7830203330306561ull,0x3030313030303030ull,0x3830303031783020ull,
0x3030783020313030ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302035303038ull,
0x2033303038666666ull,0x3065303230317830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3830303031783009ull,0x3030783020393030ull,0x3020333030303030ull,0x3030383030303178ull,
0x3030303078302064ull,0x09090a2033303030ull,0x3930323030657830ull,0x3030657830206466ull,
0x7830203863373830ull,0x3330303562313031ull,0x3030303030783020ull,0x3009090a20303031ull,
0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,
0x3030666666307830ull,0x783009090a203330ull,0x3330306530323031ull,0x3030303030783020ull,
0x3031783020303837ull,0x3020393030383030ull,0x3030303030303078ull,0x31783009090a2033ull,
0x2064303038303030ull,0x3030666637307830ull,0x3030657830203330ull,0x7830206466643032ull,
0x3863373830303065ull,0x3031783009090a20ull,0x3020333030626231ull,0x3031303030303078ull,
0x3030303178302030ull,0x3178302030303838ull,0x2034306138303030ull,0x323031783009090aull,
0x7830203330306530ull,0x3038373030303030ull,0x3830303031783020ull,0x3030783020393030ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302064303038ull,0x2033303030313030ull,
0x3930323030657830ull,0x3030657830206466ull,0x090a203863373430ull,0x3663313061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030356331303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,
0x3530303830303031ull,0x3035333430783020ull,0x3009090a20333030ull,0x3038303030306578ull,
0x3030303878302031ull,0x3178302030383730ull,0x2039303038613030ull,0x6666666666307830ull,
0x783009090a206666ull,0x3330303663313031ull,0x3030303030783020ull,0x3031783020303837ull,
0x3020393038663030ull,0x3837633330353078ull,0x64783009090a2030ull,0x2031313230313830ull,
0x3730303434307830ull,0x3130337830203238ull,0x7830206430323034ull,0x3038373030316365ull,
0x3064783009090a20ull,0x3020353038303238ull,0x3837343034343078ull,0x3038306478302030ull,
0x3078302064303630ull,0x2030383730303434ull,0x303031783009090aull,0x7830203131303864ull,
0x6662336637363630ull,0x3865313031783020ull,0x3330783020353130ull,0x0a20623061366666ull,
0x3030303178300909ull,0x3178302038333038ull,0x2063333238303030ull,0x3430303030327830ull,
0x3034307830203130ull,0x090a203038376330ull,0x3134303065783009ull,0x3065783020646664ull,
0x3020386337303130ull,0x3030366431306178ull,0x3030303078302033ull,0x09090a2030303030ull,
0x3038313030327830ull,0x6666307830203135ull,0x7830203363666666ull,0x3330303664313031ull,
0x3030303030783020ull,0x3009090a20303031ull,0x3063393130303178ull,0x3030303178302030ull,
0x3278302034306539ull,0x2035303238303030ull,0x3030666666307830ull,0x783009090a203330ull,
0x3135386131303032ull,0x3030303030783020ull,0x3031783020333030ull,0x3020383330383030ull,
0x3332383130303178ull,0x66783009090a2063ull,0x2031303030303030ull,0x3030303030657830ull,
0x3030317830203230ull,0x7830203130303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020353030383030ull,0x3030306666333078ull,0x3030306578302033ull,0x3678302031306331ull,
0x2030383730303030ull,0x303031783009090aull,0x7830203030303830ull,0x3430323830303031ull,
0x6434353032783020ull,0x3030783020333030ull,0x0a20303837303030ull,0x3030306178300909ull,
0x3478302039303832ull,0x2030383730313434ull,0x3038303030317830ull,0x3030307830203131ull,
0x090a203330303030ull,0x3830303031783009ull,0x6230783020353130ull,0x3020333030306666ull,
0x3163313030306578ull,0x3130303678302039ull,0x09090a2030383730ull,0x3038313030317830ull,
0x3030317830203031ull,0x7830203431323830ull,0x3130633034303065ull,0x3030303038783020ull,
0x3009090a20303837ull,0x3230303030306578ull,0x3030303678302031ull,0x3178302030383730ull,
0x2031303038653130ull,0x3038656133307830ull,0x783009090a203366ull,0x3530303862303031ull,
0x3162653330783020ull,0x3031783020333833ull,0x3020393330383430ull,0x6238613762383078ull,
0x31783009090a2033ull,0x2064333038353230ull,0x6530646533307830ull,0x3030657830203365ull,
0x7830203932303138ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313034313030ull,
0x3837383330303478ull,0x6632303178302030ull,0x3078302039333038ull,0x2037373632306639ull,
0x323031783009090aull,0x7830206433303836ull,0x3732623366653330ull,0x3130303065783020ull,
0x3034783020313034ull,0x0a20303837383330ull,0x3631303178300909ull,0x3078302039333038ull,
0x2037393062613961ull,0x3038623030317830ull,0x6633307830206433ull,0x090a206635343731ull,
0x3130303065783009ull,0x3034783020313034ull,0x3020303837383330ull,0x3330383431303178ull,
0x3164323078302039ull,0x09090a2037313562ull,0x3038373030317830ull,0x6633307830206433ull,
0x7830206631376333ull,0x3130343130303065ull,0x3833303034783020ull,0x3009090a20303837ull,
0x3330386432303178ull,0x3332393078302039ull,0x3178302033376562ull,0x2064333038343230ull,
0x3432366633307830ull,0x783009090a203339ull,0x3130343130303065ull,0x3833303034783020ull,
0x3031783020303837ull,0x3020393330383430ull,0x3361393939393078ull,0x31783009090a2066ull,
0x2064333038393130ull,0x3939386633307830ull,0x3030657830206239ull,0x7830203130343130ull,
0x3038373833303034ull,0x3031783009090a20ull,0x3020393330383431ull,0x3535353535353078ull,
0x3531303178302037ull,0x3078302064333038ull,0x2037353535626633ull,0x303065783009090aull,
0x7830203933343130ull,0x3038373833303034ull,0x3130303065783020ull,0x3436783020313030ull,
0x0a20303837383130ull,0x3030303278300909ull,0x3078302035303238ull,0x2033303030313030ull,
0x3431653030657830ull,0x3030387830203932ull,0x090a203038373030ull,0x3830303031783009ull,
0x3031783020383330ull,0x3020633332383130ull,0x3538613030303378ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3038663230317830ull,0x6566307830203130ull,0x7830206639336166ull,
0x3530303832303031ull,0x3665663330783020ull,0x3009090a20376532ull,0x3330313630306578ull,
0x3330343478302039ull,0x6178302030383738ull,0x2031353832303030ull,0x3730313434347830ull,
0x783009090a203038ull,0x3931343030303065ull,0x3032303034783020ull,0x3065783020303837ull,
0x3020393230316130ull,0x3837303030303878ull,0x65783009090a2030ull,0x2031303832303030ull,
0x3738313030347830ull,0x3030657830203038ull,0x7830203131383065ull,0x3038373832303034ull,
0x3065783009090a20ull,0x3020313030313030ull,0x3837303030343678ull,0x3030306578302030ull,
0x3678302031313830ull,0x2030383730303038ull,0x333031783009090aull,0x7830203130303866ull,
0x3330383933623330ull,0x3865313031783020ull,0x3330783020353030ull,0x0a20626362613763ull,
0x3030306578300909ull,0x3478302031303430ull,0x2030383730313030ull,0x6330303030657830ull,
0x3030367830203130ull,0x090a203038373030ull,0x3030303066783009ull,0x3065783020313030ull,
0x3020323030303030ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x3038643230317830ull,0x6130307830203131ull,0x7830206235643230ull,0x3531303835303031ull,
0x6139653330783020ull,0x3009090a20663339ull,0x3030383631303178ull,0x3930373078302039ull,
0x3178302037623762ull,0x2064303038353130ull,0x3633396533307830ull,0x783009090a206631ull,
0x3131303034303065ull,0x3830303034783020ull,0x3031783020303837ull,0x3020393030383830ull,
0x3238356635303078ull,0x31783009090a2033ull,0x2064303038323330ull,0x6430306633307830ull,
0x3030657830206265ull,0x7830203131303034ull,0x3038373830303034ull,0x3031783009090a20ull,
0x3020393030383630ull,0x3838396130613078ull,0x6532303178302037ull,0x3078302064303038ull,
0x2033366539336633ull,0x303065783009090aull,0x7830203131303034ull,0x3038373830303034ull,
0x3835303031783020ull,0x6530783020393030ull,0x0a20623736653335ull,0x3330303178300909ull,
0x3078302064303038ull,0x2037363766366633ull,0x3030343030657830ull,0x3030347830203131ull,
0x090a203038373830ull,0x3837333031783009ull,0x3730783020393030ull,0x3020333234346533ull,
0x3030386432303178ull,0x3966333078302064ull,0x09090a2062653463ull,0x3030343030657830ull,
0x3030347830203131ull,0x7830203038373830ull,0x3930303836303031ull,0x3936363230783020ull,
0x3009090a20623630ull,0x3030383730303178ull,0x6366333078302064ull,0x6578302033353934ull,
0x2031313030343030ull,0x3738303030347830ull,0x783009090a203038ull,0x3930303831333031ull,
0x6238666330783020ull,0x3031783020333163ull,0x3020643030383630ull,0x6333666566333078ull,
0x65783009090a2066ull,0x2039313030343030ull,0x3738303030347830ull,0x3230317830203038ull,
0x7830203930303864ull,0x3733303465336330ull,0x3031783009090a20ull,0x3020643030383233ull,
0x3939356466333078ull,0x3030303178302033ull,0x3078302031313038ull,0x2033303030303030ull,
0x303031783009090aull,0x7830203531303830ull,0x3330303030303030ull,0x3036303065783020ull,
0x3034783020393030ull,0x0a20303837383030ull,0x3430306578300909ull,0x6578302064663931ull,
0x2038633734303030ull,0x3438303030317830ull,0x3030317830203030ull,0x090a203430363830ull,
0x3030303061783009ull,0x3465783020313034ull,0x3020303832343034ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x3632303030327830ull,0x3034307830203134ull,
0x7830203238373034ull,0x3530303030303061ull,0x3430343063783020ull,0x3009090a20303837ull,
0x3038633030303278ull,0x3432343078302031ull,0x3378302030383738ull,0x2064663164303130ull,
0x3730313234367830ull,0x783009090a203863ull,0x3530303065303064ull,0x3030633061783020ull,
0x3032783020303837ull,0x3020393434323030ull,0x3837343430343078ull,0x31783009090a2030ull,
0x2033303064303030ull,0x3230303030307830ull,0x3030337830203038ull,0x7830203330303030ull,
0x3038373030303030ull,0x3036783009090a20ull,0x3020393438313130ull,0x3837303030303678ull,
0x3231303378302030ull,0x3678302064663164ull,0x2038633763303234ull,0x303033783009090aull,
0x7830203330303030ull,0x3038323030303030ull,0x6631303132783020ull,0x3030783020313030ull,
0x0a20333030303030ull,0x3030306178300909ull,0x3478302031303030ull,0x2030383730303434ull,
0x3038313030317830ull,0x3030317830203030ull,0x090a203430323830ull,0x3430303061783009ull,
0x3430783020353338ull,0x3020303837303032ull,0x3030643435303278ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3831643030347830ull,0x3030307830203535ull,0x7830203038373031ull,
0x3135343232303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3461323230303378ull,
0x3031346378302064ull,0x3178302030383730ull,0x2030343038303030ull,0x3238313030317830ull,
0x783009090a203434ull,0x3130346131303032ull,0x3030303030783020ull,0x3061783020333030ull,
0x3020313030303030ull,0x3837303034343478ull,0x31783009090a2030ull,0x2031313038303030ull,
0x3030303030307830ull,0x3030317830203330ull,0x7830203531303830ull,0x3330303066663330ull,
0x3065783009090a20ull,0x3020393030303031ull,0x3837303030303878ull,0x3430306578302030ull,
0x6578302064663530ull,0x2038633738313030ull,0x303031783009090aull,0x7830203130303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3030783020353030ull,0x0a20333030303030ull,
0x3030306578300909ull,0x6578302064663530ull,0x2038343163303030ull,0x3033363430617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3235323031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x6666307830203530ull,0x7830203330303866ull,0x3330303336343031ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030383030303178ull,0x3030303078302031ull,
0x3178302033303030ull,0x2035303038303030ull,0x3030656662307830ull,0x783009090a203330ull,
0x3131303831323031ull,0x3431656130783020ull,0x3031783020666137ull,0x3020353130383730ull,
0x3165616466333078ull,0x65783009090a2037ull,0x2031333430303030ull,0x3730303030367830ull,
0x3030657830203038ull,0x7830206466393134ull,0x3863373430313065ull,0x3061783009090a20ull,
0x3020333030323634ull,0x3030303030303078ull,0x3732303178302030ull,0x3078302033303039ull,
0x2030303130303030ull,0x303065783009090aull,0x7830203130383163ull,0x3038373030303038ull,
0x3838333031783020ull,0x3530783020393030ull,0x0a20373737373337ull,0x3932303178300909ull,
0x3078302064303038ull,0x2066303739333063ull,0x3038633330317830ull,0x3463307830203131ull,
0x090a206636633337ull,0x3832313031783009ull,0x3430783020353130ull,0x3020333262343430ull,
0x3230383730303178ull,0x3530323078302031ull,0x09090a2037613835ull,0x3038303330317830ull,
0x3034307830203532ull,0x7830206662303930ull,0x3931303864333031ull,0x3130373030783020ull,
0x3009090a20373565ull,0x3130386632303178ull,0x3330633078302064ull,0x6578302066663035ull,
0x2039303030323030ull,0x3730313030347830ull,0x783009090a203038ull,0x3132303038303065ull,
0x3831303034783020ull,0x3031783020303837ull,0x3020313130386531ull,0x3361343565613078ull,
0x31783009090a2066ull,0x2035313038303330ull,0x3932333063307830ull,0x3230317830203764ull,
0x7830203931303863ull,0x3330353138313930ull,0x3031783009090a20ull,0x3020643130383731ull,
0x3531373330343078ull,0x3030306578302037ull,0x3478302039303430ull,0x2030383730313030ull,
0x303065783009090aull,0x7830203132303038ull,0x3038373831303034ull,0x3864303031783020ull,
0x3130783020313130ull,0x0a20333236383262ull,0x3331303178300909ull,0x3078302035313038ull,
0x2062643034303034ull,0x3038643230317830ull,0x3630307830203931ull,0x090a203337303535ull,
0x3830333031783009ull,0x6330783020643130ull,0x3020373266303230ull,0x3034303030306578ull,
0x3130303478302039ull,0x09090a2030383730ull,0x3030383030657830ull,0x3030347830203931ull,
0x7830203038373831ull,0x3131303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3130383030303178ull,0x6666333078302035ull,0x6578302033303030ull,0x2039303831323030ull,
0x3730303030387830ull,0x783009090a203038ull,0x3131303036303065ull,0x3031303034783020ull,
0x3031783020303837ull,0x3020303034383030ull,0x3036383030303178ull,0x31783009090a2034ull,
0x2038303838313030ull,0x6138303030317830ull,0x3430327830206330ull,0x7830203330306236ull,
0x3038373030303030ull,0x3031783009090a20ull,0x3020333030323634ull,0x3837303030303078ull,
0x3030303178302030ull,0x3078302031303038ull,0x2033303030303030ull,0x303031783009090aull,
0x7830203530303830ull,0x3330303030303030ull,0x3130303065783020ull,0x3065783020646639ull,
0x0a20386337303130ull,0x3434306178300909ull,0x3078302033303032ull,0x2030303030303030ull,
0x3032363330317830ull,0x3030307830203330ull,0x090a203030313030ull,0x3830303031783009ull,
0x3030783020313030ull,0x3020333030303030ull,0x3030383030303178ull,0x6666333078302035ull,
0x09090a2033303030ull,0x3430303030657830ull,0x3034367830203930ull,0x7830203038373030ull,
0x3931303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3130383030303178ull,
0x6666373078302064ull,0x6178302033303030ull,0x2031313430303030ull,0x3734303534637830ull,
0x783009090a203038ull,0x3030343830303031ull,0x3831303031783020ull,0x3065783020343036ull,
0x3020646639303630ull,0x6337633030306578ull,0x61783009090a2038ull,0x2033303066653230ull,
0x3030303030307830ull,0x3230317830203030ull,0x7830203330306138ull,0x3038323030303030ull,
0x3065783009090a20ull,0x3020393034303030ull,0x3837383030303678ull,0x6532303178302030ull,
0x3078302033303066ull,0x2030383730303030ull,0x303031783009090aull,0x7830203931303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3030783020643130ull,0x0a20333030303030ull,
0x3630306578300909ull,0x6578302064663530ull,0x2038633734303030ull,0x3031393230317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3830303031783009ull,0x3030783020393030ull,
0x3020333030303030ull,0x3030383030303178ull,0x6666663078302064ull,0x09090a2033303038ull,
0x3066653230317830ull,0x3030307830203330ull,0x7830203038373030ull,0x3931303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3130383030303178ull,0x3030303078302064ull,
0x6578302033303030ull,0x2064663530363030ull,0x3738303030657830ull,0x783009090a203863ull,
0x3330303839323031ull,0x3030303030783020ull,0x3031783020303031ull,0x3020393030383030ull,
0x3030303030303078ull,0x31783009090a2033ull,0x2064303038303030ull,0x3030666666307830ull,
0x3230317830203330ull,0x7830203330306665ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020393130383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302064313038ull,
0x2033303030666637ull,0x303065783009090aull,0x7830206466393036ull,0x3863373830303065ull,
0x6439323031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x6532303178300909ull,
0x3078302033303066ull,0x2030383730303030ull,0x3038303030317830ull,0x3030307830203131ull,
0x090a203330303030ull,0x3830303031783009ull,0x3030783020353130ull,0x3020333030303130ull,
0x6635303430306578ull,0x3030306578302064ull,0x09090a2038633734ull,0x3038613230617830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3330303761323031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,
0x2035303038303030ull,0x3030353334307830ull,0x783009090a203330ull,0x3130343030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020313130386130ull,0x6666666666663078ull,
0x31783009090a2066ull,0x2033303038613230ull,0x3730303030307830ull,0x3030317830203038ull,
0x7830203131386630ull,0x3038376333303430ull,0x3064783009090a20ull,0x3020643032303138ull,
0x3837303034343078ull,0x3431303378302032ull,0x6578302039303230ull,0x2030383730303163ull,
0x383064783009090aull,0x7830203530363032ull,0x3038373430343430ull,0x3030383064783020ull,
0x3430783020353134ull,0x0a20303837303034ull,0x6430303178300909ull,0x3078302039303038ull,
0x2066623366373636ull,0x3038653130317830ull,0x6633307830206430ull,0x090a206230613666ull,
0x3830303031783009ull,0x3031783020383330ull,0x3020633332383130ull,0x3038303030303278ull,
0x3130343078302031ull,0x09090a2030383734ull,0x6431323030657830ull,0x3030657830206466ull,
0x7830203863373031ull,0x3330303862323061ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3630383130303278ull,0x6666663078302031ull,0x3178302033636666ull,0x2033303038623230ull,
0x3130303030307830ull,0x783009090a203030ull,0x3030633930303031ull,0x3930303031783020ull,
0x3032783020343065ull,0x3020353032383030ull,0x3030306666663078ull,0x32783009090a2033ull,
0x2031363062313030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830203833303831ull,
0x6333323830303031ull,0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,
0x3030303178302032ull,0x3078302031303038ull,0x2033303030303030ull,0x303031783009090aull,
0x7830203530303830ull,0x3330303066663330ull,0x3130303065783020ull,0x3036783020313063ull,
0x0a20303837303030ull,0x3030303178300909ull,0x3178302030303038ull,0x2034303238313030ull,
0x3064343530327830ull,0x3030307830203330ull,0x090a203038373030ull,0x3830303031783009ull,
0x3030783020393030ull,0x3020333030303030ull,0x3030383030303178ull,0x6666623078302064ull,
0x09090a2033303030ull,0x6331303030657830ull,0x3030367830203131ull,0x7830203038373830ull,
0x3830303830303031ull,0x3830303031783020ull,0x3009090a20633032ull,0x3038303230306578ull,
0x3030303878302031ull,0x6578302030383730ull,0x2039313030303030ull,0x3730303030367830ull,
0x783009090a203038ull,0x3132303865313031ull,0x3865613330783020ull,0x3031783020336630ull,
0x3020353230386230ull,0x3833316265333078ull,0x31783009090a2033ull,0x2039323038343030ull,
0x3861376238307830ull,0x3230317830203362ull,0x7830206432303835ull,0x3365653064653330ull,
0x3065783009090a20ull,0x3020313063303630ull,0x3837303030303878ull,0x3830306578302030ull,
0x3478302031323030ull,0x2030383738323030ull,0x323031783009090aull,0x7830203932303866ull,
0x3737363230663930ull,0x3836323031783020ull,0x3330783020643230ull,0x0a20373262336665ull,
0x3830306578300909ull,0x3478302031323030ull,0x2030383738323030ull,0x3038363130317830ull,
0x3961307830203932ull,0x090a203739306261ull,0x3862303031783009ull,0x3330783020643230ull,
0x3020663534373166ull,0x3230303830306578ull,0x3230303478302031ull,0x09090a2030383738ull,
0x3038343130317830ull,0x6432307830203932ull,0x7830203731356231ull,0x6432303837303031ull,
0x6333663330783020ull,0x3009090a20663137ull,0x3230303830306578ull,0x3230303478302031ull,
0x3178302030383738ull,0x2039323038643230ull,0x6562333239307830ull,0x783009090a203337ull,
0x6432303834323031ull,0x3236663330783020ull,0x3065783020333934ull,0x3020313230303830ull,
0x3837383230303478ull,0x31783009090a2030ull,0x2039323038343030ull,0x6139393939307830ull,
0x3130317830206633ull,0x7830206432303839ull,0x6239393938663330ull,0x3065783009090a20ull,
0x3020313230303830ull,0x3837383230303478ull,0x3431303178302030ull,0x3078302039323038ull,
0x2037353535353535ull,0x313031783009090aull,0x7830206432303835ull,0x3735353562663330ull,
0x3038303065783020ull,0x3034783020313230ull,0x0a20303837383230ull,0x3030306178300909ull,
0x3478302039323033ull,0x2030383730313434ull,0x3030383030657830ull,0x3030387830203132ull,
0x090a203038373030ull,0x3030303065783009ull,0x3436783020313063ull,0x3020303837303130ull,
0x3032383030303278ull,0x3130303078302035ull,0x09090a2033303030ull,0x6330343030657830ull,
0x3034347830203130ull,0x7830203038373030ull,0x3131633038303065ull,0x3030303038783020ull,
0x3009090a20303837ull,0x3330623030303378ull,0x3030303078302039ull,0x3178302033303030ull,
0x2031323038663230ull,0x3361666566307830ull,0x783009090a206639ull,0x3532303832303031ull,
0x3665663330783020ull,0x3065783020376532ull,0x3020393034303030ull,0x3837303130303478ull,
0x61783009090a2030ull,0x2031316331303030ull,0x3730313434347830ull,0x3030657830203038ull,
0x7830203130343138ull,0x3038373831303034ull,0x3065783009090a20ull,0x3020313138303830ull,
0x3837303030303478ull,0x3030306578302030ull,0x3678302031316330ull,0x2030383730313034ull,
0x303065783009090aull,0x7830203131343030ull,0x3038373031303836ull,0x3866333031783020ull,
0x3330783020393030ull,0x0a20333038393362ull,0x6531303178300909ull,0x3078302064303038ull,
0x2062636261376333ull,0x3431323030657830ull,0x3030347830203930ull,0x090a203038373031ull,
0x3030303065783009ull,0x3036783020393030ull,0x3020303837383030ull,0x3134303030306178ull,
0x3034346578302031ull,0x09090a2032383734ull,0x3430303030617830ull,0x3534637830203931ull,
0x7830203038373430ull,0x3132303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3230383030303178ull,0x6666373078302035ull,0x3178302033303030ull,0x2030303838313030ull,
0x6138303030317830ull,0x783009090a203430ull,0x6466643038303065ull,0x6330303065783020ull,
0x3061783020386337ull,0x3020333030303633ull,0x3030303030303078ull,0x31783009090a2030ull,
0x2033303061663230ull,0x3230303030307830ull,0x3030657830203038ull,0x7830203130343030ull,
0x3038373830303036ull,0x3061783009090a20ull,0x3020313030303030ull,0x3837343034346578ull,
0x3633303178302030ull,0x3078302033303030ull,0x2030383730303030ull,0x303031783009090aull,
0x7830203930303830ull,0x3330303030303030ull,0x3830303031783020ull,0x3030783020643030ull,
0x0a20333030303030ull,0x3230306578300909ull,0x6578302064663930ull,0x2038633734303030ull,
0x3031303330317830ull,0x3030307830203330ull,0x090a203030313030ull,0x3830303031783009ull,
0x3030783020313030ull,0x3020333030303030ull,0x3030383030303178ull,0x6666663078302035ull,
0x09090a2033303038ull,0x3030363330317830ull,0x3030307830203330ull,0x7830203038373030ull,
0x3930303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3030383030303178ull,
0x3030303078302064ull,0x6578302033303030ull,0x2064663930323030ull,0x3738303030657830ull,
0x783009090a203863ull,0x3330303830333031ull,0x3030303030783020ull,0x3031783020303031ull,
0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2035303038303030ull,
0x3030666666307830ull,0x3330317830203330ull,0x7830203330303036ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020393030383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302064303038ull,0x2033303030666637ull,0x303065783009090aull,0x7830206466643032ull,
0x3863373830303065ull,0x6530333031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303178300909ull,0x3178302030303838ull,0x2034306138313030ull,0x3030363330317830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3830303031783009ull,0x3030783020393030ull,
0x3020333030303030ull,0x3030383030303178ull,0x3130303078302064ull,0x09090a2033303030ull,
0x3930323030657830ull,0x3030657830206466ull,0x7830203863373430ull,0x3330303931333061ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3030383133303178ull,0x3030303078302033ull,
0x3178302030303130ull,0x2031303038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3530303830303031ull,0x3035333430783020ull,0x3065783020333030ull,0x3020313038303030ull,
0x3837303030303878ull,0x31783009090a2030ull,0x2031313038613030ull,0x6666666666307830ull,
0x3330317830206666ull,0x7830203330303931ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020313138663030ull,0x3837633330343078ull,0x3138306478302030ull,0x3078302064303230ull,
0x2032383730303434ull,0x313033783009090aull,0x7830203930323034ull,0x3038373030316365ull,
0x3032383064783020ull,0x3430783020353036ull,0x0a20303837343034ull,0x3038306478300909ull,
0x3078302035313430ull,0x2030383730303434ull,0x3038643030317830ull,0x3636307830203930ull,
0x090a206662336637ull,0x3865313031783009ull,0x3330783020643030ull,0x3020623061366666ull,
0x3330383030303178ull,0x3130303178302038ull,0x09090a2063333238ull,0x3830303030327830ull,
0x3034307830203130ull,0x7830203038373431ull,0x6466643132303065ull,0x3031303065783020ull,
0x3009090a20386337ull,0x3030393233306178ull,0x3030303078302033ull,0x3278302030303030ull,
0x2031363038313030ull,0x6666666666307830ull,0x783009090a203363ull,0x3330303932333031ull,
0x3030303030783020ull,0x3031783020303031ull,0x3020303063393030ull,0x3065393030303178ull,
0x32783009090a2034ull,0x2035303238303030ull,0x3030666666307830ull,0x3030327830203330ull,
0x7830203136306231ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020383330383130ull,
0x3332383030303178ull,0x3030306678302063ull,0x6578302031303030ull,0x2032303030303030ull,
0x303031783009090aull,0x7830203130303830ull,0x3330303030303030ull,0x3830303031783020ull,
0x3330783020353030ull,0x0a20333030306666ull,0x3030306578300909ull,0x3678302031306331ull,
0x2030383730303030ull,0x3038303030317830ull,0x3030317830203030ull,0x090a203430323831ull,
0x6434353032783009ull,0x3030783020333030ull,0x3020303837303030ull,0x3030383030303178ull,
0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,0x6662307830206430ull,
0x7830203330303066ull,0x3131633130303065ull,0x3830303036783020ull,0x3009090a20303837ull,
0x3030383030303178ull,0x3030303178302038ull,0x6578302063303238ull,0x2031303830323030ull,
0x3730303030387830ull,0x783009090a203038ull,0x3931303030303065ull,0x3030303036783020ull,
0x3031783020303837ull,0x3020313230386531ull,0x6630386561333078ull,0x31783009090a2033ull,
0x2035323038623030ull,0x3331626533307830ull,0x3030317830203338ull,0x7830203932303834ull,
0x3362386137623830ull,0x3031783009090a20ull,0x3020643230383532ull,0x6565306465333078ull,
0x3630306578302033ull,0x3878302031306330ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203132303038ull,0x3038373832303034ull,0x3866323031783020ull,0x3930783020393230ull,
0x0a20373736323066ull,0x3632303178300909ull,0x3078302064323038ull,0x2037326233666533ull,
0x3030383030657830ull,0x3030347830203132ull,0x090a203038373832ull,0x3836313031783009ull,
0x6130783020393230ull,0x3020373930626139ull,0x3230386230303178ull,0x3166333078302064ull,
0x09090a2066353437ull,0x3030383030657830ull,0x3030347830203132ull,0x7830203038373832ull,
0x3932303834313031ull,0x6231643230783020ull,0x3009090a20373135ull,0x3230383730303178ull,
0x3366333078302064ull,0x6578302066313763ull,0x2031323030383030ull,0x3738323030347830ull,
0x783009090a203038ull,0x3932303864323031ull,0x6233323930783020ull,0x3031783020333765ull,
0x3020643230383432ull,0x3934323666333078ull,0x65783009090a2033ull,0x2031323030383030ull,
0x3738323030347830ull,0x3030317830203038ull,0x7830203932303834ull,0x6633613939393930ull,
0x3031783009090a20ull,0x3020643230383931ull,0x3939393866333078ull,0x3830306578302062ull,
0x3478302031323030ull,0x2030383738323030ull,0x313031783009090aull,0x7830203932303834ull,
0x3735353535353530ull,0x3835313031783020ull,0x3330783020643230ull,0x0a20373535356266ull,
0x3830306578300909ull,0x3478302031323030ull,0x2030383738323030ull,0x3033303030617830ull,
0x3434347830203932ull,0x090a203038373031ull,0x3038303065783009ull,0x3038783020313230ull,
0x3020303837303030ull,0x3063303030306578ull,0x3130343678302031ull,0x09090a2030383730ull,
0x3238303030327830ull,0x3030307830203530ull,0x7830203330303031ull,0x3130633034303065ull,
0x3030303434783020ull,0x3009090a20303837ull,0x3163303830306578ull,0x3030303878302031ull,
0x3378302030383730ull,0x2039333062303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3132303866323031ull,0x6166656630783020ull,0x3031783020663933ull,0x3020353230383230ull,
0x6532366566333078ull,0x65783009090a2037ull,0x2039303430303030ull,0x3730313030347830ull,
0x3030617830203038ull,0x7830203131633130ull,0x3038373031343434ull,0x3065783009090a20ull,
0x3020313034313830ull,0x3837383130303478ull,0x3830306578302030ull,0x3478302031313830ull,
0x2030383730303030ull,0x303065783009090aull,0x7830203131633030ull,0x3038373031303436ull,
0x3030303065783020ull,0x3836783020313134ull,0x0a20303837303130ull,0x6633303178300909ull,
0x3078302039303038ull,0x2033303839336233ull,0x3038653130317830ull,0x6333307830206430ull,
0x090a206263626137ull,0x3132303065783009ull,0x3034783020393034ull,0x3020303837303130ull,
0x3030303030306578ull,0x3030303678302031ull,0x09090a2030383738ull,0x3030303030667830ull,
0x3030657830203130ull,0x7830203230303030ull,0x3330303234343031ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3134303030306178ull,0x3035346378302031ull,0x3178302030383734ull,
0x2039313038303030ull,0x3030303030307830ull,0x783009090a203330ull,0x6431303830303031ull,
0x3066663730783020ull,0x3031783020333030ull,0x3020303034383130ull,0x3036383030303178ull,
0x65783009090a2034ull,0x2064663930363030ull,0x3763303030657830ull,0x3330617830203863ull,
0x7830203330303064ull,0x3030303030303030ull,0x3031783009090a20ull,0x3020333030623633ull,
0x3832303030303078ull,0x3030306578302030ull,0x3678302039303430ull,0x2030383738303030ull,
0x333031783009090aull,0x7830203330303064ull,0x3038373030303030ull,0x3830303031783020ull,
0x3030783020393130ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302064313038ull,
0x2033303030303030ull,0x3530363030657830ull,0x3030657830206466ull,0x090a203863373430ull,
0x3237333031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3030383030303178ull,
0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,0x6666307830206430ull,
0x7830203330303866ull,0x3330303064333031ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3130383030303178ull,0x3030303078302039ull,0x3178302033303030ull,0x2064313038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6466353036303065ull,0x3830303065783020ull,
0x3031783020386337ull,0x3020333030393733ull,0x3031303030303078ull,0x31783009090a2030ull,
0x2039303038303030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830206430303830ull,
0x3330303066666630ull,0x3031783009090a20ull,0x3020333030306433ull,0x3837303030303078ull,
0x3030303178302030ull,0x3078302039313038ull,0x2033303030303030ull,0x303031783009090aull,
0x7830206431303830ull,0x3330303066663730ull,0x3036303065783020ull,0x3065783020646639ull,
0x0a20386337383030ull,0x3733303178300909ull,0x3078302033303065ull,0x2030303130303030ull,
0x3030643330317830ull,0x3030307830203330ull,0x090a203038373030ull,0x3830303031783009ull,
0x3030783020313130ull,0x3020333030303030ull,0x3130383030303178ull,0x3130303078302035ull,
0x09090a2033303030ull,0x3530343030657830ull,0x3030657830206466ull,0x7830203863373430ull,
0x3330303938333061ull,0x3030303030783020ull,0x3009090a20303030ull,0x3030383833303178ull,
0x3030303078302033ull,0x3178302030303130ull,0x2031303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3530303830303031ull,0x3035333430783020ull,0x3065783020333030ull,
0x3020313034303030ull,0x3837303030303878ull,0x31783009090a2030ull,0x2031313038613030ull,
0x6666666666307830ull,0x3330317830206666ull,0x7830203330303938ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020313138663030ull,0x3837633330343078ull,0x3138306478302030ull,
0x3078302064303230ull,0x2032383730303434ull,0x313033783009090aull,0x7830203930323034ull,
0x3038373030316365ull,0x3032383064783020ull,0x3430783020353036ull,0x0a20303837343034ull,
0x3038306478300909ull,0x3078302035313430ull,0x2030383730303434ull,0x3038643030317830ull,
0x3636307830203930ull,0x090a206662336637ull,0x3865313031783009ull,0x3330783020643030ull,
0x3020623061366666ull,0x3330383130303178ull,0x3030303178302038ull,0x09090a2063333238ull,
0x3830303030327830ull,0x3034307830203130ull,0x7830203038373431ull,0x6466643132303065ull,
0x3031303065783020ull,0x3009090a20386337ull,0x3030393933306178ull,0x3030303078302033ull,
0x3278302030303030ull,0x2031363038313030ull,0x6666666666307830ull,0x783009090a203363ull,
0x3330303939333031ull,0x3030303030783020ull,0x3031783020303031ull,0x3020303063393030ull,
0x3065393130303178ull,0x32783009090a2034ull,0x2035303238303030ull,0x3030666666307830ull,
0x3030327830203330ull,0x7830203136306231ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020383330383030ull,0x3332383030303178ull,0x3030306678302063ull,0x6578302031303030ull,
0x2032303030303030ull,0x303031783009090aull,0x7830203130303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3330783020353030ull,0x0a20333030306666ull,0x3030306578300909ull,
0x3678302031306331ull,0x2030383730303030ull,0x3038313030317830ull,0x3030317830203030ull,
0x090a203430323830ull,0x6434353032783009ull,0x3030783020333030ull,0x3020303837303030ull,
0x3030383030303178ull,0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,
0x6662307830206430ull,0x7830203330303066ull,0x3131633130303065ull,0x3830303036783020ull,
0x3009090a20303837ull,0x3030383030303178ull,0x3130303178302038ull,0x6578302063303238ull,
0x2031303830323030ull,0x3730303030387830ull,0x783009090a203038ull,0x3931303030303065ull,
0x3030303036783020ull,0x3031783020303837ull,0x3020313230386531ull,0x6630386561333078ull,
0x31783009090a2033ull,0x2035323038623030ull,0x3331626533307830ull,0x3030317830203338ull,
0x7830203932303834ull,0x3362386137623830ull,0x3031783009090a20ull,0x3020643230383532ull,
0x6565306465333078ull,0x3630306578302033ull,0x3878302031306330ull,0x2030383730303030ull,
0x303065783009090aull,0x7830203132303038ull,0x3038373832303034ull,0x3866323031783020ull,
0x3930783020393230ull,0x0a20373736323066ull,0x3632303178300909ull,0x3078302064323038ull,
0x2037326233666533ull,0x3030383030657830ull,0x3030347830203132ull,0x090a203038373832ull,
0x3836313031783009ull,0x6130783020393230ull,0x3020373930626139ull,0x3230386230303178ull,
0x3166333078302064ull,0x09090a2066353437ull,0x3030383030657830ull,0x3030347830203132ull,
0x7830203038373832ull,0x3932303834313031ull,0x6231643230783020ull,0x3009090a20373135ull,
0x3230383730303178ull,0x3366333078302064ull,0x6578302066313763ull,0x2031323030383030ull,
0x3738323030347830ull,0x783009090a203038ull,0x3932303864323031ull,0x6233323930783020ull,
0x3031783020333765ull,0x3020643230383432ull,0x3934323666333078ull,0x65783009090a2033ull,
0x2031323030383030ull,0x3738323030347830ull,0x3030317830203038ull,0x7830203932303834ull,
0x6633613939393930ull,0x3031783009090a20ull,0x3020643230383931ull,0x3939393866333078ull,
0x3830306578302062ull,0x3478302031323030ull,0x2030383738323030ull,0x313031783009090aull,
0x7830203932303834ull,0x3735353535353530ull,0x3835313031783020ull,0x3330783020643230ull,
0x0a20373535356266ull,0x3830306578300909ull,0x3478302031323030ull,0x2030383738323030ull,
0x3033303030617830ull,0x3434347830203932ull,0x090a203038373031ull,0x3038303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3063303030306578ull,0x3130343678302031ull,
0x09090a2030383730ull,0x3238303030327830ull,0x3030307830203530ull,0x7830203330303031ull,
0x3130633034303065ull,0x3030303434783020ull,0x3009090a20303837ull,0x3163303830306578ull,
0x3030303878302031ull,0x3378302030383730ull,0x2039333062303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3132303866323031ull,0x6166656630783020ull,0x3031783020663933ull,
0x3020353230383230ull,0x6532366566333078ull,0x65783009090a2037ull,0x2039303430303030ull,
0x3730313030347830ull,0x3030617830203038ull,0x7830203131633130ull,0x3038373031343434ull,
0x3065783009090a20ull,0x3020313034313830ull,0x3837383130303478ull,0x3830306578302030ull,
0x3478302031313830ull,0x2030383730303030ull,0x303065783009090aull,0x7830203131633030ull,
0x3038373031303436ull,0x3030303065783020ull,0x3836783020313134ull,0x0a20303837303130ull,
0x6633303178300909ull,0x3078302039303038ull,0x2033303839336233ull,0x3038653130317830ull,
0x6333307830206430ull,0x090a206263626137ull,0x3132303065783009ull,0x3034783020393034ull,
0x3020303837303130ull,0x3030303030306578ull,0x3030303678302039ull,0x09090a2030383738ull,
0x3430303030617830ull,0x3434657830203131ull,0x7830203238373430ull,0x3931343030303061ull,
0x3430353463783020ull,0x3009090a20303837ull,0x3230383030303178ull,0x3030303078302031ull,
0x3178302033303030ull,0x2035323038303030ull,0x3030666637307830ull,0x783009090a203330ull,
0x3030383830303031ull,0x3830303031783020ull,0x3065783020343061ull,0x3020646664303830ull,
0x6337633030306578ull,0x61783009090a2038ull,0x2033303031343430ull,0x3030303030307830ull,
0x3330317830203030ull,0x7830203330306264ull,0x3038323030303030ull,0x3065783009090a20ull,
0x3020313034303030ull,0x3837383030303678ull,0x3030306178302030ull,0x6578302031303030ull,
0x2030383734303434ull,0x343031783009090aull,0x7830203330303134ull,0x3038373030303030ull,
0x3830303031783020ull,0x3030783020393030ull,0x0a20333030303030ull,0x3030303178300909ull,
0x3078302064303038ull,0x2033303030303030ull,0x3930323030657830ull,0x3030657830206466ull,
0x090a203863373430ull,0x3265333031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3030383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,0x3038303030317830ull,
0x6666307830203530ull,0x7830203330303866ull,0x3330303134343031ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3030383030303178ull,0x3030303078302039ull,0x3178302033303030ull,
0x2064303038303030ull,0x3030303030307830ull,0x783009090a203330ull,0x6466393032303065ull,
0x3830303065783020ull,0x3031783020386337ull,0x3020333030396533ull,0x3031303030303078ull,
0x31783009090a2030ull,0x2031303038303030ull,0x3030303030307830ull,0x3030317830203330ull,
0x7830203530303830ull,0x3330303066666630ull,0x3031783009090a20ull,0x3020333030313434ull,
0x3837303030303078ull,0x3030303178302030ull,0x3078302039303038ull,0x2033303030303030ull,
0x303031783009090aull,0x7830206430303830ull,0x3330303066663730ull,0x3032303065783020ull,
0x3065783020646664ull,0x0a20386337383030ull,0x6533303178300909ull,0x3078302033303066ull,
0x2030303130303030ull,0x3838313030317830ull,0x3030317830203030ull,0x090a203430613830ull,
0x3134343031783009ull,0x3030783020333030ull,0x3020303837303030ull,0x3030383030303178ull,
0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,0x3030307830206430ull,
0x7830203330303031ull,0x6466393032303065ull,0x3430303065783020ull,0x3009090a20386337ull,
0x3030616633306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303039663330ull,
0x3130303030307830ull,0x783009090a203030ull,0x3130303830303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020353030383030ull,0x3030303533343078ull,0x65783009090a2033ull,
0x2031303830303030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203131303861ull,
0x6666666666666630ull,0x3031783009090a20ull,0x3020333030616633ull,0x3837303030303078ull,
0x3030303178302030ull,0x3078302031313866ull,0x2030383763333034ull,0x383064783009090aull,
0x7830206430323031ull,0x3238373030343430ull,0x3034313033783020ull,0x6365783020393032ull,
0x0a20303837303031ull,0x3238306478300909ull,0x3078302035303630ull,0x2030383734303434ull,
0x3430303830647830ull,0x3434307830203531ull,0x090a203038373030ull,0x3864303031783009ull,
0x3630783020393030ull,0x3020666233663736ull,0x3030386531303178ull,0x6666333078302064ull,
0x09090a2062306136ull,0x3038313030317830ull,0x3030317830203833ull,0x7830206333323830ull,
0x3130383030303032ull,0x3431303430783020ull,0x3009090a20303837ull,0x6664313230306578ull,
0x3130306578302064ull,0x6178302038633730ull,0x2033303061303430ull,0x3030303030307830ull,
0x783009090a203030ull,0x3136303831303032ull,0x6666666630783020ull,0x3031783020336366ull,
0x3020333030613034ull,0x3031303030303078ull,0x31783009090a2030ull,0x2030306339303030ull,
0x6539313030317830ull,0x3030327830203430ull,0x7830203530323830ull,0x3330303066666630ull,
0x3032783009090a20ull,0x3020313630623130ull,0x3030303030303078ull,0x3030303178302033ull,
0x3178302038333038ull,0x2063333238303030ull,0x303066783009090aull,0x7830203130303030ull,
0x3230303030303065ull,0x3830303031783020ull,0x3030783020313030ull,0x0a20333030303030ull,
0x3030303178300909ull,0x3078302035303038ull,0x2033303030666633ull,0x6331303030657830ull,
0x3030367830203130ull,0x090a203038373030ull,0x3831303031783009ull,0x3031783020303030ull,
0x3020343032383030ull,0x3030643435303278ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3038303030317830ull,0x3030307830203930ull,0x7830203330303030ull,0x6430303830303031ull,
0x3066666230783020ull,0x3009090a20333030ull,0x3163313030306578ull,0x3030303678302031ull,
0x3178302030383738ull,0x2038303038303030ull,0x3238313030317830ull,0x783009090a206330ull,
0x3130383032303065ull,0x3030303038783020ull,0x3065783020303837ull,0x3020393130303030ull,
0x3837303030303678ull,0x31783009090a2030ull,0x2031323038653130ull,0x3038656133307830ull,
0x3030317830203366ull,0x7830203532303862ull,0x3338333162653330ull,0x3031783009090a20ull,
0x3020393230383430ull,0x6238613762383078ull,0x3532303178302033ull,0x3078302064323038ull,
0x2033656530646533ull,0x303065783009090aull,0x7830203130633036ull,0x3038373030303038ull,
0x3038303065783020ull,0x3034783020313230ull,0x0a20303837383230ull,0x6632303178300909ull,
0x3078302039323038ull,0x2037373632306639ull,0x3038363230317830ull,0x6533307830206432ull,
0x090a203732623366ull,0x3038303065783009ull,0x3034783020313230ull,0x3020303837383230ull,
0x3230383631303178ull,0x6139613078302039ull,0x09090a2037393062ull,0x3038623030317830ull,
0x6633307830206432ull,0x7830206635343731ull,0x3132303038303065ull,0x3832303034783020ull,
0x3009090a20303837ull,0x3230383431303178ull,0x3164323078302039ull,0x3178302037313562ull,
0x2064323038373030ull,0x3763336633307830ull,0x783009090a206631ull,0x3132303038303065ull,
0x3832303034783020ull,0x3031783020303837ull,0x3020393230386432ull,0x3765623332393078ull,
0x31783009090a2033ull,0x2064323038343230ull,0x3432366633307830ull,0x3030657830203339ull,
0x7830203132303038ull,0x3038373832303034ull,0x3031783009090a20ull,0x3020393230383430ull,
0x3361393939393078ull,0x3931303178302066ull,0x3078302064323038ull,0x2062393939386633ull,
0x303065783009090aull,0x7830203132303038ull,0x3038373832303034ull,0x3834313031783020ull,
0x3530783020393230ull,0x0a20373535353535ull,0x3531303178300909ull,0x3078302064323038ull,
0x2037353535626633ull,0x3030383030657830ull,0x3030347830203132ull,0x090a203038373832ull,
0x3330303061783009ull,0x3434783020393230ull,0x3020303837303134ull,0x3230303830306578ull,
0x3030303878302031ull,0x09090a2030383730ull,0x6330303030657830ull,0x3034367830203130ull,
0x7830203038373031ull,0x3530323830303032ull,0x3031303030783020ull,0x3009090a20333030ull,
0x3063303430306578ull,0x3030343478302031ull,0x6578302030383730ull,0x2031316330383030ull,
0x3730303030387830ull,0x783009090a203038ull,0x3933306230303033ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020313230386632ull,0x3933616665663078ull,0x31783009090a2066ull,
0x2035323038323030ull,0x3236656633307830ull,0x3030657830203765ull,0x7830203930343030ull,
0x3038373031303034ull,0x3061783009090a20ull,0x3020313163313030ull,0x3837303134343478ull,
0x3830306578302030ull,0x3478302031303431ull,0x2030383738313030ull,0x303065783009090aull,
0x7830203131383038ull,0x3038373030303034ull,0x3030303065783020ull,0x3436783020313163ull,
0x0a20303837303130ull,0x3030306578300909ull,0x3678302031313430ull,0x2030383730313038ull,
0x3038663330317830ull,0x6233307830203930ull,0x090a203330383933ull,0x3865313031783009ull,
0x3330783020643030ull,0x3020626362613763ull,0x3034313230306578ull,0x3130303478302039ull,
0x09090a2030383730ull,0x3030303030657830ull,0x3030367830203130ull,0x7830203038373830ull,
0x3130303030303066ull,0x3030303065783020ull,0x3009090a20323030ull,0x3030303030306678ull,
0x3030306578302031ull,0x3178302032303030ull,0x2031313038643230ull,0x6432306130307830ull,
0x783009090a206235ull,0x3531303835303031ull,0x6139653330783020ull,0x3031783020663339ull,
0x3020393030383631ull,0x6237623930373078ull,0x31783009090a2037ull,0x2064303038353130ull,
0x3633396533307830ull,0x3030657830206631ull,0x7830203131303034ull,0x3038373830303034ull,
0x3031783009090a20ull,0x3020393030383830ull,0x3238356635303078ull,0x3233303178302033ull,
0x3078302064303038ull,0x2062656430306633ull,0x303065783009090aull,0x7830203131303034ull,
0x3038373830303034ull,0x3836303031783020ull,0x6130783020393030ull,0x0a20373838396130ull,
0x6532303178300909ull,0x3078302064303038ull,0x2033366539336633ull,0x3030343030657830ull,
0x3030347830203131ull,0x090a203038373830ull,0x3835303031783009ull,0x6530783020393030ull,
0x3020623736653335ull,0x3030383330303178ull,0x3666333078302064ull,0x09090a2037363766ull,
0x3030343030657830ull,0x3030347830203131ull,0x7830203038373830ull,0x3930303837333031ull,
0x3465333730783020ull,0x3009090a20333234ull,0x3030386432303178ull,0x3966333078302064ull,
0x6578302062653463ull,0x2031313030343030ull,0x3738303030347830ull,0x783009090a203038ull,
0x3930303836303031ull,0x3936363230783020ull,0x3031783020623630ull,0x3020643030383730ull,
0x3539346366333078ull,0x65783009090a2033ull,0x2031313030343030ull,0x3738303030347830ull,
0x3330317830203038ull,0x7830203930303831ull,0x3331636238666330ull,0x3031783009090a20ull,
0x3020643030383630ull,0x6333666566333078ull,0x3430306578302066ull,0x3478302039303030ull,
0x2030383738303030ull,0x323031783009090aull,0x7830203131303864ull,0x3733303465336330ull,
0x3832333031783020ull,0x3330783020353130ull,0x0a20333939356466ull,0x3030303178300909ull,
0x3078302039313038ull,0x2033303030303030ull,0x3038303030317830ull,0x3030307830206431ull,
0x090a203330303030ull,0x3032303065783009ull,0x3034783020393030ull,0x3020303837303130ull,
0x6639313630306578ull,0x3030306578302064ull,0x09090a2038633734ull,0x3438303030317830ull,
0x3030317830203030ull,0x7830203430363830ull,0x3130343030303061ull,0x3430343465783020ull,
0x3009090a20303832ull,0x3030303030306678ull,0x3030306578302031ull,0x3278302032303030ull,
0x2039346132303030ull,0x3738343034307830ull,0x783009090a203238ull,0x3530303030303061ull,
0x3430343063783020ull,0x3032783020303837ull,0x3020313038633030ull,0x3837303532343078ull,
0x33783009090a2030ull,0x2064663164323130ull,0x3730313234367830ull,0x3030647830203863ull,
0x7830203530303065ull,0x3038373030633061ull,0x3032783009090a20ull,0x3020313538323030ull,
0x3837633430343078ull,0x3432303178302030ull,0x3078302033303034ull,0x2030383230303030ull,
0x303033783009090aull,0x7830203330303030ull,0x3038373030303030ull,0x3030303031783020ull,
0x3630783020313134ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302035313630ull,
0x2030383763333034ull,0x3030303030317830ull,0x3036307830203931ull,0x090a203038376333ull,
0x3030303031783009ull,0x3430783020643132ull,0x3020303837633330ull,0x3230303030303178ull,
0x3330363078302039ull,0x09090a2030383763ull,0x3230303030317830ull,0x3034307830206432ull,
0x7830203038376333ull,0x3133343030303031ull,0x6333303630783020ull,0x3009090a20303837ull,
0x3336303030303178ull,0x3330343078302035ull,0x3378302030383763ull,0x2039303630343130ull,
0x3730303134657830ull,0x783009090a203038ull,0x3130303866333031ull,0x3030303030783020ull,
0x3064783020663730ull,0x3020393034303030ull,0x3837303030343078ull,0x32783009090a2030ull,
0x2039333438663330ull,0x6666666666307830ull,0x3130337830206666ull,0x7830203530323034ull,
0x3038373030313465ull,0x3064783009090a20ull,0x3020313032303030ull,0x3837303030343078ull,
0x6633303278302030ull,0x3078302064333038ull,0x2066666666666666ull,0x303031783009090aull,
0x7830203935303830ull,0x3330303030303030ull,0x3865333031783020ull,0x3030783020313030ull,
0x0a20663730303030ull,0x3030303378300909ull,0x3678302064666631ull,0x2038633738313034ull,
0x6431303030337830ull,0x3034367830206466ull,0x090a203834313831ull,0x3364343061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030336434303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x6330303030617830ull,0x3534637830203930ull,0x7830203038373430ull,
0x3130303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3030383030303178ull,
0x6666373078302035ull,0x6578302033303030ull,0x2064663530303030ull,0x3763303030657830ull,
0x783009090a203863ull,0x3330303938343031ull,0x3030303030783020ull,0x3031783020303832ull,
0x3020313034313030ull,0x3837633330363078ull,0x31783009090a2030ull,0x2035303038303030ull,
0x3038303030307830ull,0x3030647830203330ull,0x7830203530363131ull,0x3038373430303430ull,
0x3033783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,0x3030306178302030ull,
0x6378302039303830ull,0x2030383734303534ull,0x303031783009090aull,0x7830203130303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3730783020353030ull,0x0a20333030306666ull,
0x3030306578300909ull,0x6578302064663530ull,0x2038633763303030ull,0x3032393430317830ull,
0x3030307830203330ull,0x090a203038323030ull,0x3130303031783009ull,0x3430783020313038ull,
0x3020303837633330ull,0x3030383030303178ull,0x3030303078302035ull,0x09090a2033303038ull,
0x6131313030647830ull,0x3034307830203530ull,0x7830203038373430ull,0x3330303030303033ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030383030303178ull,0x3030303078302031ull,
0x3178302033303030ull,0x2035303038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3132633030303065ull,0x3830303065783020ull,0x3031783020303837ull,0x3020313030383030ull,
0x3030303030303078ull,0x61783009090a2033ull,0x2039306330303030ull,0x3734303534637830ull,
0x3030317830203038ull,0x7830203530303830ull,0x3330303030303030ull,0x3065783009090a20ull,
0x3020313038303030ull,0x3837383030306578ull,0x3030306478302030ull,0x3078302031323031ull,
0x2030383730303034ull,0x303031783009090aull,0x7830203130303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3730783020353030ull,0x0a20333030306666ull,0x3030306578300909ull,
0x6578302035323430ull,0x2030383738303030ull,0x3830303030617830ull,0x3534637830203930ull,
0x090a203038373430ull,0x3030303065783009ull,0x3065783020313034ull,0x3020303837383030ull,
0x3032313030306478ull,0x3030343078302031ull,0x09090a2030383730ull,0x3131303030647830ull,
0x3034307830206466ull,0x7830203863373430ull,0x3330303561343031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,
0x2035303038303030ull,0x3038666666307830ull,0x783009090a203330ull,0x3330303030303033ull,
0x3030303030783020ull,0x3061783020303837ull,0x3020313238303030ull,0x3837343035346378ull,
0x31783009090a2030ull,0x2031303038303030ull,0x3030303030307830ull,0x3030317830203330ull,
0x7830203530303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020393030383030ull,
0x3030303030303078ull,0x3030303178302033ull,0x3078302064303038ull,0x2033303030666637ull,
0x303065783009090aull,0x7830206466313132ull,0x3863373830303065ull,0x3030303065783020ull,
0x3065783020646664ull,0x0a20383431383030ull,0x6234303178300909ull,0x3078302033303032ull,
0x2030303130303030ull,0x3631643030647830ull,0x3034307830203130ull,0x090a203038373830ull,
0x3830303031783009ull,0x3830783020353030ull,0x3020333030303030ull,0x3030303130306478ull,
0x3030343078302035ull,0x09090a2030383730ull,0x3038303030317830ull,0x3030307830203130ull,
0x7830203330303030ull,0x3330303030303033ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3263303030306178ull,0x3035346378302031ull,0x3178302030383734ull,0x2031303038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x3530303830303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020393030383030ull,0x3030303030303078ull,0x31783009090a2033ull,
0x2064303038303030ull,0x3030666637307830ull,0x3030657830203330ull,0x7830206466313132ull,
0x3863373830303065ull,0x3065783009090a20ull,0x3020646639303030ull,0x3431383030306578ull,
0x6334303178302038ull,0x3078302033303031ull,0x2030303130303030ull,0x303064783009090aull,
0x7830203130363164ull,0x3038373830303430ull,0x3830303031783020ull,0x3830783020353030ull,
0x0a20333030303030ull,0x3130306478300909ull,0x3078302031303030ull,0x2030383730303034ull,
0x3038303030317830ull,0x6637307830203530ull,0x090a203330303066ull,0x3031303064783009ull,
0x3430783020353030ull,0x3020303837343030ull,0x3030383030303178ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3030303030337830ull,0x3030307830203330ull,0x7830203038373030ull,
0x3130303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x6666313030303378ull,
0x3030633678302064ull,0x6178302038633734ull,0x2033303039633430ull,0x3030303030307830ull,
0x783009090a203030ull,0x3330303963343031ull,0x3030303030783020ull,0x3031783020303031ull,
0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2035303038303030ull,
0x3030353334307830ull,0x3030657830203330ull,0x7830203932633030ull,0x3038373030303038ull,
0x3031783009090a20ull,0x3020393530386130ull,0x6666666666663078ull,0x3030306678302066ull,
0x6578302031303030ull,0x2032303030303030ull,0x303031783009090aull,0x7830203130303830ull,
0x3330303030303030ull,0x3130303033783020ull,0x6336783020646664ull,0x0a20386337343030ull,
0x6434306178300909ull,0x3078302033303032ull,0x2030303030303030ull,0x3032643430317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3830303031783009ull,0x3030783020313030ull,
0x3020333030303030ull,0x3030383030303178ull,0x3533343078302035ull,0x09090a2033303030ull,
0x3830303030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3935636136333032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3030303030306678ull,0x3030306578302031ull,
0x3178302032303030ull,0x2031303831303030ull,0x3763333036307830ull,0x783009090a203238ull,
0x3133633932303032ull,0x6666666630783020ull,0x3033783020336366ull,0x3020353038313431ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2035306131303430ull,0x3734303034307830ull,
0x3030617830203038ull,0x7830203930303030ull,0x3038373436343063ull,0x3039783009090a20ull,
0x3020393034303030ull,0x3837303030303078ull,0x3030303178302030ull,0x3078302039313431ull,
0x2030383763333034ull,0x303032783009090aull,0x7830203533653932ull,0x3363666666666630ull,
0x3030303061783020ull,0x3463783020313134ull,0x0a20303837303034ull,0x3030303178300909ull,
0x3078302039303038ull,0x2033303030303030ull,0x3038303030317830ull,0x6633307830206430ull,
0x090a203330303066ull,0x3030303065783009ull,0x3434783020313238ull,0x3020303837383030ull,
0x3330313830306578ull,0x3030303878302039ull,0x09090a2030383730ull,0x3830383030657830ull,
0x3030347830203132ull,0x7830203038373031ull,0x3132633138303065ull,0x3032303034783020ull,
0x3009090a20303837ull,0x3030303830306578ull,0x3030343478302039ull,0x6578302030383738ull,
0x2039303031323030ull,0x3730323030347830ull,0x783009090a203038ull,0x6431613134313033ull,
0x3030313463783020ull,0x3032783020303837ull,0x3020643136313034ull,0x3837633130343078ull,
0x65783009090a2030ull,0x2031316330343030ull,0x3730303030387830ull,0x3030657830203038ull,
0x7830203932383030ull,0x3038373831303434ull,0x3065783009090a20ull,0x3020313134313830ull,
0x3837303130303478ull,0x3030306578302030ull,0x3478302031303830ull,0x2030383738313034ull,
0x303065783009090aull,0x7830203931303032ull,0x3038373031303034ull,0x3030303031783020ull,
0x3630783020313265ull,0x0a20303837633330ull,0x3431303378300909ull,0x6578302064316530ull,
0x2030383730303134ull,0x3038663330317830ull,0x3030307830203532ull,0x090a206637303030ull,
0x3039303064783009ull,0x3430783020643165ull,0x3020303837303030ull,0x3165383130303278ull,
0x6666663078302064ull,0x09090a2033636666ull,0x3831303030337830ull,0x3034307830203532ull,
0x7830203038373433ull,0x3532653030303032ull,0x3432303430783020ull,0x3009090a20303837ull,
0x3232313030303278ull,0x3530343078302039ull,0x3278302030383738ull,0x2035323439653330ull,
0x3030303030307830ull,0x783009090a206633ull,0x6432303864333031ull,0x3030303030783020ull,
0x3033783020663730ull,0x3020646633316230ull,0x6337633030343678ull,0x61783009090a2038ull,
0x2033303061343530ull,0x3030303030307830ull,0x3430317830203030ull,0x7830203330306466ull,
0x3030313030303030ull,0x3031783009090a20ull,0x3020313063303030ull,0x3837633330343078ull,
0x3034303278302030ull,0x3078302035303431ull,0x2030383763313034ull,0x313033783009090aull,
0x7830203530323034ull,0x3038373030313463ull,0x3130303032783020ull,0x3430783020353030ull,
0x0a20303837343030ull,0x3435303178300909ull,0x3078302033303061ull,0x2030383730303030ull,
0x3038663330317830ull,0x3030307830203931ull,0x090a206633303030ull,0x3136303033783009ull,
0x6336783020646635ull,0x3020386337303130ull,0x3030393435306178ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3037303530317830ull,0x3030307830203330ull,0x7830203030313030ull,
0x3130303830303031ull,0x3030303830783020ull,0x3009090a20333030ull,0x3030313030306478ull,
0x3030343078302031ull,0x3178302030383730ull,0x2035303038303030ull,0x3030666637307830ull,
0x783009090a203330ull,0x3530303031303064ull,0x3430303430783020ull,0x3031783020303837ull,
0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2033303039343530ull,
0x3730303030307830ull,0x3030317830203038ull,0x7830203931303830ull,0x3330303030303830ull,
0x3064783009090a20ull,0x3020643230313630ull,0x3837303030343078ull,0x6330303178302030ull,
0x3078302039313038ull,0x2066626666666666ull,0x303033783009090aull,0x7830206466353136ull,
0x3863373430306336ull,0x3834353061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x3135303178300909ull,0x3078302033303030ull,0x2030303130303030ull,0x3038303030317830ull,
0x3030307830203130ull,0x090a203330303030ull,0x3130303031783009ull,0x3630783020353036ull,
0x3020303837633330ull,0x3030383435303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3030323030657830ull,0x3830347830203132ull,0x7830203038373031ull,0x3931303032303065ull,
0x3031343034783020ull,0x3009090a20303837ull,0x3130313630306578ull,0x3330306578302039ull,
0x6178302030383734ull,0x2039316330303030ull,0x3734313063327830ull,0x783009090a203038ull,
0x3130303032303065ull,0x3031633034783020ull,0x3031783020303837ull,0x3020393030386633ull,
0x6666663030303078ull,0x64783009090a2066ull,0x2035303230323030ull,0x3730303034307830ull,
0x3030317830203038ull,0x7830203930303830ull,0x3330303031303030ull,0x3064783009090a20ull,
0x3020353032303230ull,0x3837343030343078ull,0x6633303278302030ull,0x3078302039303439ull,
0x2066333030303030ull,0x303033783009090aull,0x7830203930343830ull,0x3330303030303030ull,
0x3830323031783020ull,0x3030783020643030ull,0x0a20333030303030ull,0x3330303378300909ull,
0x3678302064663530ull,0x2038633738313063ull,0x3036323530617830ull,0x3030307830203330ull,
0x090a203030303030ull,0x3632353031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3030383030303178ull,0x3030303078302064ull,0x09090a2033303030ull,0x3030333030337830ull,
0x3063367830203130ull,0x7830203038373431ull,0x3130303030303061ull,0x3431306332783020ull,
0x3009090a20303837ull,0x3163303030306478ull,0x3030343078302039ull,0x3178302030383734ull,
0x2031303230303030ull,0x3763333034307830ull,0x783009090a203038ull,0x3530303830303031ull,
0x3030303030783020ull,0x3032783020333030ull,0x3020393034383032ull,0x6666666666663078ull,
0x66783009090a2066ull,0x2031303030303030ull,0x3030303030657830ull,0x3030317830203230ull,
0x7830206430303830ull,0x3330303030303030ull,0x3033783009090a20ull,0x3020646635303330ull,
0x6337343130633678ull,0x3032303378302038ull,0x3078302064303438ull,0x2033303030303030ull,
0x303033783009090aull,0x7830203531323033ull,0x3038363030303463ull,0x3032303033783020ull,
0x3465783020313130ull,0x0a20303836303030ull,0x3330303378300909ull,0x6378302064303030ull,
0x2030383630303034ull,0x3830353030647830ull,0x3034307830203130ull,0x090a203038363430ull,
0x3830303031783009ull,0x3030783020313130ull,0x3020333030303030ull,0x3036303430303378ull,
0x3130633678302064ull,0x09090a2030383634ull,0x3630303030617830ull,0x3063327830206430ull,
0x7830203038363431ull,0x3931633033303064ull,0x3430303430783020ull,0x3009090a20303836ull,
0x3032303230303378ull,0x3030346578302035ull,0x3178302030383630ull,0x2039303038313030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6430303032303064ull,0x3030303430783020ull,
0x3033783020303837ull,0x3020313030303130ull,0x3837303031346578ull,0x33783009090a2030ull,
0x2031313230663130ull,0x3730303134637830ull,0x3030647830203038ull,0x7830203130303034ull,
0x3038373430303430ull,0x3064783009090a20ull,0x3020393030303230ull,0x3837303030343078ull,
0x3230306478302030ull,0x3078302039306330ull,0x2030383734303034ull,0x303064783009090aull,
0x7830203930363032ull,0x3038373030303430ull,0x3031303033783020ull,0x3465783020353032ull,
0x0a20303837303031ull,0x3030303178300909ull,0x3078302064303038ull,0x2033303030303030ull,
0x3530333030337830ull,0x3063367830206466ull,0x090a203863373431ull,0x3734353061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030373435303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3038313030327830ull,0x3030307830203130ull,0x7830203330303030ull,
0x3930303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x6631303230303378ull,
0x3030633678302064ull,0x6178302038633738ull,0x2033303036343530ull,0x3030303030307830ull,
0x783009090a203030ull,0x3330303634353031ull,0x3030303030783020ull,0x3032783020303031ull,
0x3020353032383130ull,0x3030303030303078ull,0x66783009090a2033ull,0x2031303030303030ull,
0x3030303030657830ull,0x3030647830203230ull,0x7830203530323062ull,0x3238373430303430ull,
0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,0x3030306678302032ull,
0x6578302031303030ull,0x2032303030303030ull,0x303066783009090aull,0x7830203130303030ull,
0x3230303030303065ull,0x3030303033783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3030306678300909ull,0x6578302031303030ull,0x2030303030303030ull,0x3038303030317830ull,
0x6637307830203930ull,0x090a203330303066ull,0x3032303064783009ull,0x3430783020393032ull,
0x3020303837303030ull,0x3534303431303378ull,0x3031346578302039ull,0x09090a2030383730ull,
0x3038643330317830ull,0x3030307830203930ull,0x7830206637303030ull,0x3532636166333032ull,
0x6666666630783020ull,0x3009090a20666666ull,0x6633313230303378ull,0x3030343678302064ull,
0x6178302038633763ull,0x2033303032653530ull,0x3030303030307830ull,0x783009090a203030ull,
0x3930303030303031ull,0x6333303630783020ull,0x3031783020303837ull,0x3020643032303030ull,
0x3837633330343078ull,0x31783009090a2030ull,0x2031323230303030ull,0x3763333036307830ull,
0x3530317830203038ull,0x7830203330306237ull,0x3038323030303030ull,0x3031783009090a20ull,
0x3020313138663030ull,0x3837633330343078ull,0x3030303178302030ull,0x3078302035313038ull,
0x2033303030666637ull,0x303061783009090aull,0x7830203931343030ull,0x3038373430353463ull,
0x3036303065783020ull,0x3065783020646639ull,0x0a20386337383130ull,0x3030303178300909ull,
0x3078302031313866ull,0x2030383763333036ull,0x3038303030317830ull,0x6637307830203531ull,
0x090a203330303066ull,0x3236353031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3030383030303178ull,0x3030303078302035ull,0x09090a2033303038ull,0x3031313030647830ull,
0x3034307830203530ull,0x7830203038373430ull,0x3330303265353031ull,0x3030303030783020ull,
0x3009090a20303837ull,0x6639303630306578ull,0x3030306578302064ull,0x3178302038633738ull,
0x2033303038363530ull,0x3130303030307830ull,0x783009090a203030ull,0x3130303830303031ull,
0x3030303830783020ull,0x3064783020333030ull,0x3020353030313030ull,0x3837303030343078ull,
0x31783009090a2030ull,0x2031303866303030ull,0x3763333034307830ull,0x3530317830203038ull,
0x7830203330303265ull,0x3038373030303030ull,0x3031783009090a20ull,0x3020313138663030ull,
0x3837633330363078ull,0x3030303178302030ull,0x3078302035313866ull,0x2030383763333034ull,
0x303065783009090aull,0x7830206466353034ull,0x3863373830303065ull,0x3237353031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303178300909ull,0x3078302031303038ull,
0x2033303030303038ull,0x3031303030647830ull,0x3034307830203130ull,0x090a203038373030ull,
0x3830303031783009ull,0x3730783020353030ull,0x3020333030306666ull,0x3030303130306478ull,
0x3030343078302035ull,0x09090a2030383734ull,0x3866303030317830ull,0x3036307830203130ull,
0x7830203038376333ull,0x3330303265353031ull,0x3030303030783020ull,0x3009090a20303837ull,
0x6633316337303378ull,0x3130633678302064ull,0x3178302038633738ull,0x2033303039373530ull,
0x3230303030307830ull,0x783009090a203038ull,0x3130303830303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020353030383030ull,0x3030303533343078ull,0x65783009090a2033ull,
0x2031303430303030ull,0x3730303030387830ull,0x3330317830203038ull,0x7830206435303836ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020333030633735ull,0x3837303030303078ull,
0x3030303178302030ull,0x3078302064353866ull,0x2030383763333034ull,0x353031783009090aull,
0x7830203330306337ull,0x3038373030303030ull,0x6630303031783020ull,0x3630783020643538ull,
0x0a20303837633330ull,0x3130303278300909ull,0x3078302039306361ull,0x2033636666666666ull,
0x3430343130337830ull,0x3134637830203930ull,0x090a203038373030ull,0x3030343032783009ull,
0x3430783020353032ull,0x3020303837383030ull,0x3030303030306178ull,0x3634306378302039ull,
0x09090a2030383734ull,0x3430303030397830ull,0x3030307830203931ull,0x7830203038373030ull,
0x3930303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3030383030303178ull,
0x6666333078302064ull,0x6178302033303030ull,0x2031313030303030ull,0x3734303434657830ull,
0x783009090a203038ull,0x3130633030303061ull,0x3030343463783020ull,0x3065783020303837ull,
0x3020393138303030ull,0x3837383030303478ull,0x65783009090a2030ull,0x2039326330303030ull,
0x3730303030347830ull,0x3030657830203038ull,0x7830203132633036ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020393230316130ull,0x3837383230303478ull,0x6130306578302030ull,
0x3478302031323830ull,0x2030383738303030ull,0x303065783009090aull,0x7830203132343138ull,
0x3038373832303034ull,0x3061303065783020ull,0x3034783020313063ull,0x0a20303837303030ull,
0x3030306578300909ull,0x3478302031313830ull,0x2030383738303030ull,0x3038303030317830ull,
0x6637307830203931ull,0x090a203330303066ull,0x3038303065783009ull,0x3034783020393038ull,
0x3020303837303030ull,0x3136303630306478ull,0x3030343078302039ull,0x09090a2030383730ull,
0x6330343130337830ull,0x3134657830203931ull,0x7830203038373030ull,0x6431633230303033ull,
0x3831303430783020ull,0x3009090a20303837ull,0x3265303030303278ull,0x3530343078302064ull,
0x3178302030383763ull,0x2039323038643330ull,0x3030303030307830ull,0x783009090a206637ull,
0x6431363965333032ull,0x3030303030783020ull,0x3033783020663330ull,0x3020646666306130ull,
0x6337303130343678ull,0x61783009090a2038ull,0x2033303031653530ull,0x3030303030307830ull,
0x3530317830203030ull,0x7830203330306539ull,0x3038323030303030ull,0x3032783009090a20ull,
0x3020313036313034ull,0x3837383130343078ull,0x6633303278302030ull,0x3078302031303038ull,
0x2066333030303030ull,0x313033783009090aull,0x7830203130303034ull,0x3038373030313463ull,
0x3030303032783020ull,0x3430783020353036ull,0x0a20303837303030ull,0x3030303178300909ull,
0x3078302031303430ull,0x2030383763333034ull,0x3031653530317830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3866333031783009ull,0x3030783020393030ull,0x3020663330303030ull,
0x6637313230303378ull,0x3030633678302064ull,0x09090a2038633763ull,0x3037613530317830ull,
0x3030307830203330ull,0x7830203038323030ull,0x3130303830303031ull,0x3030303830783020ull,
0x3009090a20333030ull,0x3036303030306478ull,0x3030343078302031ull,0x3178302030383730ull,
0x2035303038303030ull,0x3030666637307830ull,0x783009090a203330ull,0x3530303031303064ull,
0x3430303430783020ull,0x3031783020303837ull,0x3020313038663030ull,0x3837633330363078ull,
0x31783009090a2030ull,0x2033303031653530ull,0x3730303030307830ull,0x3030317830203038ull,
0x7830203930303863ull,0x6662666666666630ull,0x3031783009090a20ull,0x3020393130383030ull,
0x3030303030383078ull,0x3230303378302033ull,0x3678302064663731ull,0x2038633738313063ull,
0x303064783009090aull,0x7830203932363036ull,0x3038373030303430ull,0x6661353031783020ull,
0x3030783020333030ull,0x0a20303832303030ull,0x3030303178300909ull,0x3078302031303866ull,
0x2030383763333034ull,0x3431303030317830ull,0x3036307830203530ull,0x090a203038376333ull,
0x3165353031783009ull,0x3030783020333030ull,0x3020303837303030ull,0x3038303830306578ull,
0x3034303478302039ull,0x09090a2030383730ull,0x3830383030657830ull,0x3830347830203931ull,
0x7830203038373030ull,0x3130383038303065ull,0x3030633034783020ull,0x3009090a20303837ull,
0x3130386633303178ull,0x3030303078302031ull,0x6478302066666666ull,0x2035313230343030ull,
0x3730303034307830ull,0x783009090a203038ull,0x3530363931303033ull,0x6666666630783020ull,
0x3031783020336366ull,0x3020313230383030ull,0x3030303130303078ull,0x31783009090a2033ull,
0x2031313038663130ull,0x3030303030307830ull,0x3030657830203330ull,0x7830206430343036ull,
0x3038373431303065ull,0x3064783009090a20ull,0x3020393061303830ull,0x3837343030343078ull,
0x3430303378302030ull,0x3678302064663330ull,0x2038633763303063ull,0x353061783009090aull,
0x7830203330303363ull,0x3030303030303030ull,0x3030303061783020ull,0x6332783020313136ull,
0x0a20303837343130ull,0x6335303178300909ull,0x3078302033303033ull,0x2030383230303030ull,
0x3030633730337830ull,0x3063367830203130ull,0x090a203038373431ull,0x3030303061783009ull,
0x6332783020313030ull,0x3020303837343130ull,0x3138303030306478ull,0x3030343078302031ull,
0x09090a2030383734ull,0x3238303230327830ull,0x6666307830203530ull,0x7830206666666666ull,
0x3130343030303031ull,0x6333303430783020ull,0x3009090a20303837ull,0x3038663030303178ull,
0x3330363078302039ull,0x3378302030383763ull,0x2064663330633730ull,0x3738303063367830ull,
0x783009090a206163ull,0x3330306663353061ull,0x3030303030783020ull,0x3031783020303030ull,
0x3020333030666335ull,0x3832303030303078ull,0x33783009090a2030ull,0x2064303238303230ull,
0x3030303030307830ull,0x3030337830203330ull,0x7830203531303033ull,0x3038373030303463ull,
0x3033783009090a20ull,0x3020353161306337ull,0x3837343130633678ull,0x3330303378302030ull,
0x6378302039313430ull,0x2030383730303034ull,0x303033783009090aull,0x7830203130303031ull,
0x3038373030303465ull,0x3030303061783020ull,0x6332783020643061ull,0x0a20303837343130ull,
0x3130303378300909ull,0x6578302039303430ull,0x2030383730303034ull,0x3030363030647830ull,
0x3034307830203130ull,0x090a203038373430ull,0x3033303064783009ull,0x3430783020313138ull,
0x3020303837343030ull,0x3030303130303378ull,0x3031346578302035ull,0x09090a2032383730ull,
0x3430663130337830ull,0x3134637830206430ull,0x7830203038373030ull,0x6430323033303064ull,
0x3430303430783020ull,0x3009090a20303837ull,0x3030383130303178ull,0x3030303078302035ull,
0x6478302033303030ull,0x2035313630313030ull,0x3730303034307830ull,0x783009090a203038ull,
0x3130303031303064ull,0x3030303430783020ull,0x3064783020303837ull,0x3020353038303530ull,
0x3837343030343078ull,0x64783009090a2030ull,0x2064663130313030ull,0x3730303034307830ull,
0x3530617830203863ull,0x7830203330306664ull,0x3030303030303030ull,0x3033783009090a20ull,
0x3020313034303130ull,0x3837303031346578ull,0x6435303178302030ull,0x3078302033303066ull,
0x2030303130303030ull,0x303031783009090aull,0x7830203530303831ull,0x3330303030303030ull,
0x3030303032783020ull,0x3430783020643036ull,0x0a20306337343030ull,0x3130303278300909ull,
0x3078302035303038ull,0x2033303030303030ull,0x3030303030317830ull,0x3034307830203530ull,
0x090a203038366333ull,0x3030303031783009ull,0x3630783020313032ull,0x3020303837633330ull,
0x3034313030306478ull,0x3030343078302035ull,0x09090a2032383734ull,0x3630303030317830ull,
0x3034307830203130ull,0x7830203038376333ull,0x3130303030303066ull,0x3030303065783020ull,
0x3009090a20323030ull,0x3030303030306678ull,0x3030306578302031ull,0x3378302032303030ull,
0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,0x3130303030303066ull,
0x3030303065783020ull,0x0a7d090a20313030ull,0x7b2065646f630a7dull,0x3d20656d616e090aull,
0x6e6f4d37325a5f20ull,0x4f6f6c7261436574ull,0x506b636f6c42656eull,0x6e6f6974704f7265ull,
0x656d6c090a696650ull,0x73090a30203d206dull,0x3134203d206d656dull,0x20676572090a3832ull,
0x62090a3033203d20ull,0x0a31203d20207261ull,0x7b2074736e6f6309ull,0x6e6765730909090aull,
0x6f63203d20656d61ull,0x730909090a74736eull,0x3d20206d756e6765ull,0x666f0909090a3120ull,
0x203d202074657366ull,0x7479620909090a30ull,0x34203d2020207365ull,0x206d656d09090a30ull,
0x3078300909090a7bull,0x2066663030303030ull,0x6366666666667830ull,0x3030307830203330ull,
0x7830206637303030ull,0x6633303030303030ull,0x3078300909090a20ull,0x2066313030303030ull,
0x3030303030307830ull,0x3030347830203030ull,0x7830203030303030ull,0x3733303030303030ull,
0x3078300909090a20ull,0x2030303030303030ull,0x3030303963337830ull,0x0a7d09090a203030ull,
0x636e6962090a7d09ull,0x09090a7b2065646full,0x3030303030617830ull,0x3034307830203535ull,
0x7830203038373030ull,0x3130613230383033ull,0x6330346336783020ull,0x3009090a20306437ull,
0x6631303030306178ull,0x3130633078302064ull,0x6178302038633734ull,0x2033303065373030ull,
0x3030303030307830ull,0x783009090a203030ull,0x3135613230303031ull,0x6333303630783020ull,
0x3031783020303837ull,0x3020333030653730ull,0x3031313030303078ull,0x61783009090a2030ull,
0x2031306334303030ull,0x3730303234307830ull,0x3030617830203038ull,0x7830203936323430ull,
0x3038373030323430ull,0x3030783009090a20ull,0x3020353030303530ull,0x3837303030306378ull,
0x3330303378302030ull,0x6378302031303832ull,0x2030383730303134ull,0x303031783009090aull,
0x7830203536383230ull,0x3038376333303430ull,0x3333303033783020ull,0x3463783020313634ull,
0x0a20303837303031ull,0x3032303278300909ull,0x3078302064353038ull,0x2033383030303030ull,
0x3038303230327830ull,0x3030307830203935ull,0x090a203330303030ull,0x3030303431783009ull,
0x3432783020313138ull,0x3020303837633030ull,0x3161303030343178ull,0x3030343278302035ull,
0x09090a2030383763ull,0x6330303034317830ull,0x3034327830203931ull,0x7830203038376330ull,
0x6431653030303431ull,0x6330303432783020ull,0x3009090a20303837ull,0x3230303030343178ull,
0x3030343278302031ull,0x3178302030383763ull,0x2035323230303034ull,0x3763303034327830ull,
0x783009090a203038ull,0x3932343030303431ull,0x6330303432783020ull,0x3431783020303837ull,
0x3020643236303030ull,0x3837633030343278ull,0x31783009090a2030ull,0x2039303038303030ull,
0x3030303030307830ull,0x3030317830203330ull,0x7830206430303830ull,0x3330303030303030ull,
0x3033783009090a20ull,0x3020646664633531ull,0x6437633032633678ull,0x3730306178302038ull,
0x3078302033303033ull,0x2030303030303030ull,0x303031783009090aull,0x7830206336616132ull,
0x3030343830303031ull,0x3030303031783020ull,0x3630783020353036ull,0x0a20303837633330ull,
0x3730303178300909ull,0x3078302033303033ull,0x2030383231303030ull,0x3233323030337830ull,
0x3134637830203133ull,0x090a203038373030ull,0x6330303032783009ull,0x3430783020313738ull,
0x3020303837303332ull,0x3338336530306478ull,0x3063303878302031ull,0x09090a2030383730ull,
0x3831303030617830ull,0x3434637830203133ull,0x7830203038373030ull,0x3933303866323031ull,
0x6166656630783020ull,0x3009090a20663933ull,0x3330383230303178ull,0x3830343078302064ull,
0x6578302037653236ull,0x2031333831363030ull,0x3730313030347830ull,0x783009090a203038ull,
0x6466393165303065ull,0x3031303065783020ull,0x3061783020386437ull,0x3020333030393630ull,
0x3030303030303078ull,0x31783009090a2030ull,0x2033303061323030ull,0x3131303030307830ull,
0x3030317830203030ull,0x7830203133303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020353330383030ull,0x3030306666373078ull,0x3630303178302033ull,0x3078302033303039ull,
0x2030383730303030ull,0x313031783009090aull,0x7830203933303832ull,0x3730336432356430ull,
0x3830313031783020ull,0x6330783020643330ull,0x0a20333934373830ull,0x6530306578300909ull,
0x6578302064663931ull,0x2038643763303030ull,0x3031333030317830ull,0x3030307830203330ull,
0x090a203030313130ull,0x3830303031783009ull,0x3030783020313330ull,0x3020333030303030ull,
0x3330383030303178ull,0x3030303078302035ull,0x09090a2033303030ull,0x3039363030317830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3933303865333031ull,0x6232353630783020ull,
0x3009090a20663238ull,0x3330383730303178ull,0x6666333078302064ull,0x6578302037353137ull,
0x2039333831653030ull,0x3730303030387830ull,0x783009090a203038ull,0x3933633130303061ull,
0x3430346363783020ull,0x3061783020303837ull,0x3020353763313030ull,0x3837343634383878ull,
0x33783009090a2030ull,0x2064666233313830ull,0x3730313463367830ull,0x3031327830203864ull,
0x7830203537613330ull,0x3030356431343430ull,0x3031783009090a20ull,0x3020313430313030ull,
0x3035643034343278ull,0x3030303178302030ull,0x3278302035343231ull,0x2030303564303434ull,
0x303031783009090aull,0x7830203134613030ull,0x3038326430343432ull,0x3030303031783020ull,
0x3432783020353463ull,0x0a20303832643034ull,0x6632303178300909ull,0x3078302039343038ull,
0x2066393361666566ull,0x3038323030317830ull,0x6662307830206434ull,0x090a203765323665ull,
0x3132313065783009ull,0x3034783020313363ull,0x3020303837303330ull,0x3430386633303178ull,
0x3362333078302039ull,0x09090a2033303839ull,0x3038653130317830ull,0x6362307830206434ull,
0x7830206263626137ull,0x3133633132313065ull,0x3033303034783020ull,0x3009090a20303837ull,
0x3330386432303178ull,0x6663633078302039ull,0x3178302062623835ull,0x2064333038663330ull,
0x6631326533307830ull,0x783009090a203730ull,0x3934303866323031ull,0x6336616430783020ull,
0x3031783020626233ull,0x3020643430383130ull,0x6466613565333078ull,0x65783009090a2062ull,
0x2039333831653030ull,0x3738343030347830ull,0x3230317830203038ull,0x7830203934303836ull,
0x6630386630366630ull,0x3031783009090a20ull,0x3020643430383531ull,0x6537323965333078ull,
0x6530306578302037ull,0x3478302039333831ull,0x2030383738343030ull,0x323031783009090aull,
0x7830203934303836ull,0x3736643230663830ull,0x3861313031783020ull,0x3330783020643430ull,
0x0a20666431376365ull,0x6530306578300909ull,0x3478302039333831ull,0x2030383738343030ull,
0x3038303230317830ull,0x3331307830203934ull,0x090a206634393862ull,0x3830323031783009ull,
0x3330783020643430ull,0x3020623130616665ull,0x3338316530306578ull,0x3430303478302039ull,
0x09090a2030383738ull,0x3038383030317830ull,0x6431307830203934ull,0x7830206237666133ull,
0x6434303830323031ull,0x6132663330783020ull,0x3009090a20623130ull,0x3338316530306578ull,
0x3430303478302039ull,0x3178302030383738ull,0x2039343038633230ull,0x6133633631307830ull,
0x783009090a206631ull,0x6434303863323031ull,0x3635663330783020ull,0x3065783020373163ull,
0x3020393338316530ull,0x3837383430303478ull,0x31783009090a2030ull,0x2039343038313230ull,
0x3930313131307830ull,0x3130317830203731ull,0x7830206434303831ull,0x3331313138663330ull,
0x3065783009090a20ull,0x3020393338316530ull,0x3837383430303478ull,0x3130303178302030ull,
0x3078302039343038ull,0x2066343535353535ull,0x313031783009090aull,0x7830206434303835ull,
0x3735353561663330ull,0x3165303065783020ull,0x3034783020393338ull,0x0a20303837383430ull,
0x6632303178300909ull,0x3078302039343038ull,0x2037353535353535ull,0x3038353130317830ull,
0x6633307830206434ull,0x090a203735353563ull,0x3165303065783009ull,0x3034783020393338ull,
0x3020303837383430ull,0x3430383030303178ull,0x3030303078302039ull,0x09090a2033303030ull,
0x3038303030317830ull,0x6633307830206434ull,0x7830203330303065ull,0x3933383165303065ull,
0x3834303034783020ull,0x3009090a20303837ull,0x3338316530306578ull,0x3030303878302039ull,
0x6578302030383730ull,0x2031336331633030ull,0x3730333030347830ull,0x783009090a203038ull,
0x3933386630303031ull,0x6333303430783020ull,0x3032783020303837ull,0x3020643361626533ull,
0x3330303030303078ull,0x33783009090a2066ull,0x2064336531343130ull,0x3730303134637830ull,
0x3030657830203038ull,0x7830203133383165ull,0x3038373833303034ull,0x3065783009090a20ull,
0x3020313330326330ull,0x3837303030303878ull,0x3830306578302030ull,0x3478302039333831ull,
0x2032383738323038ull,0x303031783009090aull,0x7830203133303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3030783020353330ull,0x0a20333030303030ull,0x3030303278300909ull,
0x3078302064363662ull,0x2033313030303030ull,0x6331633030657830ull,0x3030637830203133ull,
0x090a203038373030ull,0x6362313033783009ull,0x6336783020646664ull,0x3020386437303132ull,
0x3038313030306578ull,0x3030303678302039ull,0x09090a2030383738ull,0x3831633030657830ull,
0x3030347830203130ull,0x7830203038373030ull,0x3137386230303032ull,0x3030303030783020ull,
0x3009090a20333430ull,0x3030663130303178ull,0x3030303078302033ull,0x3078302030383231ull,
0x2035306532303030ull,0x3730303030637830ull,0x783009090a203238ull,0x3130303030303430ull,
0x3830323465783020ull,0x3430783020303837ull,0x3020313032303030ull,0x3837633032346578ull,
0x30783009090a2030ull,0x2035306332303030ull,0x3730303030637830ull,0x3030327830203038ull,
0x7830203535613230ull,0x3038373836303430ull,0x3430783009090a20ull,0x3020313030303030ull,
0x3837303032346578ull,0x3030343078302030ull,0x6578302031303230ull,0x2030383734303234ull,
0x383033783009090aull,0x7830206466623230ull,0x3864376330346336ull,0x6239313032783020ull,
0x3032783020343634ull,0x0a20383530623631ull,0x3030303278300909ull,0x3078302064353033ull,
0x2030383763353034ull,0x3036313030317830ull,0x3030307830203330ull,0x090a203038323130ull,
0x3030303066783009ull,0x3065783020313030ull,0x3020323030303030ull,0x3030656530306178ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3832303030317830ull,0x3034307830203130ull,
0x7830203038376333ull,0x3330306565303031ull,0x3030303030783020ull,0x3009090a20303031ull,
0x3065666631363878ull,0x3030303078302033ull,0x3378302030303030ull,0x2064663130323830ull,
0x3730313463367830ull,0x783009090a203863ull,0x3330303439303061ull,0x3030303030783020ull,
0x3031783020303030ull,0x3020333030343930ull,0x3832303030303078ull,0x30783009090a2030ull,
0x2035303030333030ull,0x3730303030637830ull,0x3034317830203038ull,0x7830203930303134ull,
0x3038376330303434ull,0x3431783009090a20ull,0x3020643032313430ull,0x3837633030343478ull,
0x3630343178302030ull,0x3478302031313031ull,0x2030383763303034ull,0x303431783009090aull,
0x7830203531323136ull,0x3038376330303434ull,0x3030303065783020ull,0x3036783020393034ull,
0x0a20303837303130ull,0x3430343078300909ull,0x6578302031303031ull,0x2030383738303234ull,
0x3231343034307830ull,0x3234657830203130ull,0x090a203038376330ull,0x6630303531783009ull,
0x3531783020383030ull,0x3020633032663030ull,0x3130313230343178ull,0x3030343478302031ull,
0x09090a2030383763ull,0x3231323034317830ull,0x3034347830203531ull,0x7830203038376330ull,
0x3930343030303065ull,0x3031303036783020ull,0x3009090a20303837ull,0x3030313030343078ull,
0x3032346578302031ull,0x3078302030383738ull,0x2031303231303034ull,0x3763303234657830ull,
0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,0x3638783020323030ull,
0x3020333065666631ull,0x3030303030303078ull,0x33783009090a2030ull,0x2064663130333830ull,
0x3730313463367830ull,0x3030617830203863ull,0x7830203330303761ull,0x3030303030303030ull,
0x3031783009090a20ull,0x3020333030376130ull,0x3832303030303078ull,0x3330303078302030ull,
0x6378302035303030ull,0x2030383730303030ull,0x303431783009090aull,0x7830203930303134ull,
0x3038376330303434ull,0x3134303431783020ull,0x3434783020643032ull,0x0a20303837633030ull,
0x3530343178300909ull,0x3478302031313031ull,0x2030383763303034ull,0x3231353034317830ull,
0x3034347830203531ull,0x090a203038376330ull,0x3030303065783009ull,0x3036783020393034ull,
0x3020303837303130ull,0x3030313430343078ull,0x3032346578302031ull,0x09090a2030383738ull,
0x3231343034307830ull,0x3234657830203130ull,0x7830203038376330ull,0x3830306630303531ull,
0x6630303531783020ull,0x3009090a20633032ull,0x3130313130343178ull,0x3030343478302031ull,
0x3178302030383763ull,0x2035313231313034ull,0x3763303034347830ull,0x783009090a203038ull,
0x3930343030303065ull,0x3031303036783020ull,0x3430783020303837ull,0x3020313030313030ull,
0x3837383032346578ull,0x30783009090a2030ull,0x2031303231303034ull,0x3763303234657830ull,
0x3030667830203038ull,0x7830203130303030ull,0x3230303030303065ull,0x3638783009090a20ull,
0x3020333065666631ull,0x3030303030303078ull,0x3438303378302030ull,0x3678302064663130ull,
0x2038633730313463ull,0x303061783009090aull,0x7830203330306165ull,0x3030303030303030ull,
0x6165303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3330303078300909ull,
0x6378302035303030ull,0x2030383730303030ull,0x3031343034317830ull,0x3034347830203930ull,
0x090a203038376330ull,0x3134303431783009ull,0x3434783020643032ull,0x3020303837633030ull,
0x3130393430343178ull,0x3030343478302031ull,0x09090a2030383763ull,0x3239343034317830ull,
0x3034347830203531ull,0x7830203038376330ull,0x3931343030303065ull,0x3031303036783020ull,
0x3009090a20303837ull,0x3030313430343078ull,0x3132346578302031ull,0x3078302030383738ull,
0x2031303231343034ull,0x3763313234657830ull,0x783009090a203038ull,0x3830306630303531ull,
0x6630303531783020ull,0x3431783020633032ull,0x3020313130393030ull,0x3837633030343478ull,
0x31783009090a2030ull,0x2035313239303034ull,0x3763303034347830ull,0x3030657830203038ull,
0x7830203131343030ull,0x3038373031303036ull,0x3430783009090a20ull,0x3020313030313030ull,
0x3837303132346578ull,0x3030343078302030ull,0x6578302031303231ull,0x2030383734313234ull,
0x303431783009090aull,0x7830203930303534ull,0x3038376330303434ull,0x3534303431783020ull,
0x3434783020643032ull,0x0a20303837633030ull,0x3030306578300909ull,0x3678302039316330ull,
0x2030383738303030ull,0x3031343034307830ull,0x3234657830203130ull,0x090a203038373831ull,
0x3134303430783009ull,0x3465783020313032ull,0x3020303837633132ull,0x3030353030343178ull,
0x3030343478302039ull,0x09090a2030383763ull,0x3235303034317830ull,0x3034347830206430ull,
0x7830203038376330ull,0x3131383030303065ull,0x3830303036783020ull,0x3009090a20303837ull,
0x3030313030343078ull,0x3132346578302031ull,0x3078302030383730ull,0x2031303231303034ull,
0x3734313234657830ull,0x783009090a203038ull,0x3930303334303431ull,0x6330303434783020ull,
0x3431783020303837ull,0x3020643032333430ull,0x3837633030343478ull,0x65783009090a2030ull,
0x2039316330303030ull,0x3738303030367830ull,0x3034307830203038ull,0x7830203130303134ull,
0x3038373831323465ull,0x3430783009090a20ull,0x3020313032313430ull,0x3837633132346578ull,
0x3030343178302030ull,0x3478302039303033ull,0x2030383763303034ull,0x303431783009090aull,
0x7830206430323330ull,0x3038376330303434ull,0x3030303065783020ull,0x3036783020313138ull,
0x0a20303837383030ull,0x3030343078300909ull,0x6578302031303031ull,0x2030383730313234ull,
0x3231303034307830ull,0x3234657830203130ull,0x090a203038373431ull,0x3234303431783009ull,
0x3434783020393030ull,0x3020303837633030ull,0x3032323430343178ull,0x3030343478302064ull,
0x09090a2030383763ull,0x6330303030657830ull,0x3030367830203931ull,0x7830203038373830ull,
0x3130303134303430ull,0x3831323465783020ull,0x3009090a20303837ull,0x3032313430343078ull,
0x3132346578302031ull,0x3178302030383763ull,0x2039303032303034ull,0x3763303034347830ull,
0x783009090a203038ull,0x6430323230303431ull,0x6330303434783020ull,0x3065783020303837ull,
0x3020313138303030ull,0x3837383030303678ull,0x30783009090a2030ull,0x2031303031303034ull,
0x3730313234657830ull,0x3034307830203038ull,0x7830203130323130ull,0x3038373431323465ull,
0x3431783009090a20ull,0x3020393038313430ull,0x3837633030343478ull,0x3430343178302030ull,
0x3478302064306131ull,0x2030383763303034ull,0x303065783009090aull,0x7830203931633030ull,
0x3038373830303036ull,0x3134303430783020ull,0x3465783020313030ull,0x0a20303837383132ull,
0x3430343078300909ull,0x6578302031303231ull,0x2030383763313234ull,0x3866303035317830ull,
0x3035317830203830ull,0x090a206330616630ull,0x3030303065783009ull,0x3036783020313138ull,
0x3020303837383030ull,0x3030313030343078ull,0x3132346578302031ull,0x09090a2030383730ull,
0x3231303034307830ull,0x3234657830203130ull,0x7830203038373431ull,0x3930343134303431ull,
0x6330303434783020ull,0x3009090a20303837ull,0x3036313430343178ull,0x3030343478302064ull,
0x6578302030383763ull,0x2039306330303030ull,0x3738303030367830ull,0x783009090a203038ull,
0x3130303134303430ull,0x3830323465783020ull,0x3430783020303837ull,0x3020313032313430ull,
0x3837633032346578ull,0x31783009090a2030ull,0x2038303466303035ull,0x3666303035317830ull,
0x3030657830206330ull,0x7830203930383030ull,0x3038373830303036ull,0x3430783009090a20ull,
0x3020313030313030ull,0x3837383032346578ull,0x3030343078302030ull,0x6578302031303231ull,
0x2030383763303234ull,0x303066783009090aull,0x7830203130303030ull,0x3230303030303065ull,
0x3830303032783020ull,0x3030783020313030ull,0x0a20333130303030ull,0x3038303378300909ull,
0x3678302064663130ull,0x2038633763303463ull,0x3032383030317830ull,0x3030307830203330ull,
0x090a203038323030ull,0x3263373033783009ull,0x3436783020646639ull,0x3020616337343130ull,
0x3030303030303378ull,0x3030303078302033ull,0x09090a2030383230ull,0x6334303030617830ull,
0x3234307830203130ull,0x7830203038373030ull,0x3930303034303033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3030313430303178ull,0x3030343478302031ull,0x3178302030383763ull,
0x2035303231343030ull,0x3763303034347830ull,0x783009090a203038ull,0x3930343030303132ull,
0x3030383730783020ull,0x3064783020303837ull,0x3020313034306530ull,0x3837303038306178ull,
0x31783009090a2030ull,0x2030303066303031ull,0x3266303031317830ull,0x3030327830203430ull,
0x7830203930343838ull,0x3330303030303030ull,0x3064783009090a20ull,0x3020313034306530ull,
0x3837303038306178ull,0x0a7d0a7d090a2031ull,0x0000000000000000ull
};


}



extern "C" {


static const unsigned long long __deviceText_$compute_13$[] = {
0x6f69737265762e09ull,0x2e090a332e31206eull,0x7320746567726174ull,0x2f2f090a33315f6dull,
0x656c69706d6f6320ull,0x2f20687469772064ull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,
0x6f2f616475632f70ull,0x696c2f34366e6570ull,0x2f090a65622f2f62ull,0x6e65706f766e202full,
0x746c697562206363ull,0x38303032206e6f20ull,0x0a0a33302d32312dull,0x752e206765722e09ull,
0x313c617225203233ull,0x65722e090a3b3e37ull,0x25203436752e2067ull,0x3b3e37313c616472ull,
0x2e206765722e090aull,0x3c61662520323366ull,0x722e090a3b3e3731ull,0x203436662e206765ull,
0x3e37313c61646625ull,0x206765722e090a3bull,0x767225203233752eull,0x722e090a3b3e353cull,
0x203436752e206765ull,0x3b3e353c76647225ull,0x2e206765722e090aull,0x3c76662520323366ull,
0x65722e090a3b3e35ull,0x25203436662e2067ull,0x0a3b3e353c766466ull,0x2d2d2d2f2f090a0aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x6d6f43202f2f090aull,
0x2f20676e696c6970ull,0x78706d742f706d74ull,0x31303030305f7466ull,0x303030305f613035ull,
0x5f37312d30303030ull,0x72614365746e6f4dull,0x2e33314d535f6f6cull,0x2820692e33707063ull,
0x4263632f706d742full,0x5565586d5a2e2349ull,0x2d2d2f2f090a296bull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2f2f090a0a2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x704f202f2f090a2dull,0x090a3a736e6f6974ull,
0x2d2d2d2d2d2d2f2full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f090a2d2d2d2d2dull,
0x656772615420202full,0x49202c7874703a74ull,0x33315f6d733a4153ull,0x6e6169646e45202cull,
0x2c656c7474696c3aull,0x7265746e696f5020ull,0x34363a657a695320ull,0x4f2d20202f2f090aull,
0x6d6974704f280933ull,0x206e6f6974617a69ull,0x090a296c6576656cull,0x0930672d20202f2full,
0x6c20677562654428ull,0x2f090a296c657665ull,0x2809326d2d20202full,0x612074726f706552ull,
0x6569726f73697664ull,0x2d2d2f2f090a2973ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x6c69662e090a0a2dull,0x6f633c2209310965ull,0x696c2d646e616d6dull,
0x662e090a223e656eull,0x2f22093209656c69ull,0x78706d742f706d74ull,0x31303030305f7466ull,
0x303030305f613035ull,0x5f36312d30303030ull,0x72614365746e6f4dull,0x2e33314d535f6f6cull,
0x2e32656661647563ull,0x662e090a22757067ull,0x4d22093309656c69ull,0x6c72614365746e6full,
0x6c656e72656b5f6full,0x2e090a226875632eull,0x22093409656c6966ull,0x62696c2f7273752full,
0x3638782f6363672full,0x756e696c2d34365full,0x2e342f756e672d78ull,0x6c636e692f332e33ull,
0x646474732f656475ull,0x2e090a22682e6665ull,0x22093509656c6966ull,0x64672f656d6f682full,
0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,
0x697665642f747263ull,0x69746e75725f6563ull,0x2e090a22682e656dull,0x22093609656c6966ull,
0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,
0x2f6564756c636e69ull,0x6665645f74736f68ull,0x0a22682e73656e69ull,0x3709656c69662e09ull,
0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,
0x64756c636e692f2eull,0x69746c6975622f65ull,0x2e73657079745f6eull,0x6c69662e090a2268ull,
0x6f682f2209380965ull,0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,
0x636e692f2e2e2f2full,0x7665642f6564756cull,0x657079745f656369ull,0x662e090a22682e73ull,
0x2f22093909656c69ull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,0x622f616475632f70ull,
0x692f2e2e2f2f6e69ull,0x642f6564756c636eull,0x79745f7265766972ull,0x090a22682e736570ull,
0x303109656c69662eull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,
0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x7275747865742f65ull,0x2e73657079745f65ull,
0x6c69662e090a2268ull,0x682f220931310965ull,0x616964672f656d6full,0x706d65742f736f6dull,
0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x65762f6564756c63ull,0x7079745f726f7463ull,
0x2e090a22682e7365ull,0x09323109656c6966ull,0x672f656d6f682f22ull,0x742f736f6d616964ull,
0x616475632f706d65ull,0x2e2e2f2f6e69622full,0x6564756c636e692full,0x5f6563697665642full,
0x705f68636e75616cull,0x726574656d617261ull,0x662e090a22682e73ull,0x2209333109656c69ull,
0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,
0x2f6564756c636e69ull,0x726f74732f747263ull,0x73616c635f656761ull,0x662e090a22682e73ull,
0x2209343109656c69ull,0x636e692f7273752full,0x7469622f6564756cull,0x2e73657079742f73ull,
0x6c69662e090a2268ull,0x752f220935310965ull,0x756c636e692f7273ull,0x2e656d69742f6564ull,
0x6c69662e090a2268ull,0x6572220936310965ull,0x682e657079746c61ull,0x656c69662e090a22ull,
0x6e6f4d2209373109ull,0x5f6f6c7261436574ull,0x6f69746375646572ull,0x090a226875632e6eull,
0x383109656c69662eull,0x7269736175712209ull,0x6e65476d6f646e61ull,0x6b5f726f74617265ull,
0x75632e6c656e7265ull,0x6c69662e090a2268ull,0x682f220939310965ull,0x616964672f656d6full,
0x706d65742f736f6dull,0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x6f632f6564756c63ull,
0x6e75665f6e6f6d6dull,0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209303209ull,
0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,
0x7472632f6564756cull,0x616d5f636e75662full,0x090a22682e6f7263ull,0x313209656c69662eull,
0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,
0x64756c636e692f2eull,0x665f6874616d2f65ull,0x736e6f6974636e75ull,0x69662e090a22682eull,
0x2f2209323209656cull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,0x622f616475632f70ull,
0x692f2e2e2f2f6e69ull,0x642f6564756c636eull,0x75665f6563697665ull,0x2e736e6f6974636eull,
0x6c69662e090a2268ull,0x682f220933320965ull,0x616964672f656d6full,0x706d65742f736f6dull,
0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x616d2f6564756c63ull,0x74736e6f635f6874ull,
0x0a22682e73746e61ull,0x3209656c69662e09ull,0x656d6f682f220934ull,0x736f6d616964672full,
0x75632f706d65742full,0x2f2f6e69622f6164ull,0x756c636e692f2e2eull,0x31315f6d732f6564ull,
0x5f63696d6f74615full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209353209656c69ull,
0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,
0x2f6564756c636e69ull,0x74615f32315f6d73ull,0x6e75665f63696d6full,0x682e736e6f697463ull,
0x656c69662e090a22ull,0x6f682f2209363209ull,0x6d616964672f656dull,0x2f706d65742f736full,
0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x5f6d732f6564756cull,0x6c62756f645f3331ull,
0x6974636e75665f65ull,0x090a22682e736e6full,0x373209656c69662eull,0x2f656d6f682f2209ull,
0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,
0x7275747865742f65ull,0x5f68637465665f65ull,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209383209656c69ull,0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,
0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x6e75665f6874616dull,0x645f736e6f697463ull,
0x2e337874705f6c62ull,0x6f632e090a0a2268ull,0x696c612e2074736eull,0x38622e2038206e67ull,
0x6f6974704f5f6420ull,0x35365b617461446eull,0x2e090a3b5d363335ull,0x2e206c61626f6c67ull,
0x2038206e67696c61ull,0x61435f642038622eull,0x5b65756c61566c6cull,0x0a3b5d3836373233ull,
0x7972746e652e090aull,0x6e6f4d36315a5f20ull,0x4b6f6c7261436574ull,0x3431506c656e7265ull,
0x6f6974704f545f5full,0x665065756c61566eull,0x722e090a7b090a69ull,0x203631752e206765ull,
0x0a3b3e353c687225ull,0x752e206765722e09ull,0x38313c7225203233ull,0x6765722e090a3b3eull,
0x7225203436752e20ull,0x090a3b3e36313c64ull,0x33662e206765722eull,0x3b3e333c66252032ull,
0x2e206765722e090aull,0x3c64662520343666ull,0x722e090a3b3e3134ull,0x646572702e206765ull,
0x0a3b3e373c702520ull,0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,
0x746e6f4d36315a5full,0x654b6f6c72614365ull,0x5f3431506c656e72ull,0x6e6f6974704f545full,
0x69665065756c6156ull,0x65666675425f645full,0x7261702e090a3b72ull,0x203436752e206d61ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6c72614365746e6full,0x506c656e72654b6full,
0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x61535f645f696650ull,0x090a3b73656c706dull,
0x2e206d617261702eull,0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x65746e6f4d36315aull,
0x72654b6f6c726143ull,0x5f5f3431506c656eull,0x566e6f6974704f54ull,0x5f69665065756c61ull,
0x090a3b4e68746170ull,0x31093309636f6c2eull,0x424c240a30093231ull,0x4d36315a5f5f3142ull,
0x6c72614365746e6full,0x506c656e72654b6full,0x74704f545f5f3431ull,0x65756c61566e6f69ull,
0x6c2e090a3a696650ull,0x393231093309636full,0x2e766f6d090a3009ull,0x6872250920363175ull,
0x6469746e25202c31ull,0x20202020203b782eull,0x090a202f2f092020ull,0x203631752e766f6dull,
0x25202c3268722509ull,0x3b782e6469617463ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x3631752e65646977ull,0x25202c3172250920ull,0x687225202c326872ull,0x090a202f2f093b31ull,
0x2e3233752e747663ull,0x3272250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,
0x2e646461090a202full,0x3372250920323375ull,0x25202c327225202cull,0x20202020203b3172ull,
0x090a202f2f092020ull,0x2e3233732e747663ull,0x3472250920363175ull,0x646961746325202cull,
0x2f092020203b792eull,0x2e766f6d090a202full,0x6872250920363175ull,0x6174636e25202c33ull,
0x2020203b782e6469ull,0x090a202f2f092020ull,0x6d617261702e646cull,0x722509203233732eull,
0x75635f5f5b202c35ull,0x5f5f6d7261706164ull,0x65746e6f4d36315aull,0x72654b6f6c726143ull,
0x5f5f3431506c656eull,0x566e6f6974704f54ull,0x5f69665065756c61ull,0x093b5d4e68746170ull,
0x34313a6469202f2full,0x616475635f5f2038ull,0x315a5f5f6d726170ull,0x614365746e6f4d36ull,
0x656e72654b6f6c72ull,0x4f545f5f3431506cull,0x6c61566e6f697470ull,0x61705f6966506575ull,
0x0a3078302b4e6874ull,0x656c2e7074657309ull,0x702509203233732eull,0x202c357225202c31ull,
0x092020203b337225ull,0x766f6d090a202f2full,0x662509203436662eull,0x30306430202c3164ull,
0x3030303030303030ull,0x093b303030303030ull,0x6f6d090a30202f2full,0x2509203436662e76ull,
0x306430202c326466ull,0x3030303030303030ull,0x3b30303030303030ull,0x40090a30202f2f09ull,
0x2061726220317025ull,0x325f305f744c2409ull,0x2020202020203b38ull,0x2f2f092020202020ull,
0x772e6c756d090a20ull,0x203631752e656469ull,0x7225202c36722509ull,0x31687225202c3368ull,
0x61090a202f2f093bull,0x09203233732e6464ull,0x367225202c377225ull,0x20203b337225202cull,
0x2f2f092020202020ull,0x732e646461090a20ull,0x2c38722509203233ull,0x7225202c35722520ull,
0x2020202020203b36ull,0x63090a202f2f0920ull,0x752e3436732e7476ull,0x3164722509203233ull,
0x20203b367225202cull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,
0x647225202c326472ull,0x2020203b34202c31ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x75635f5f5b202c33ull,0x5f5f6d7261706164ull,0x65746e6f4d36315aull,
0x72654b6f6c726143ull,0x5f5f3431506c656eull,0x566e6f6974704f54ull,0x5f69665065756c61ull,
0x656c706d61535f64ull,0x69202f2f093b5d73ull,0x5f5f203435313a64ull,0x6d72617061647563ull,
0x6e6f4d36315a5f5full,0x4b6f6c7261436574ull,0x3431506c656e7265ull,0x6f6974704f545f5full,
0x665065756c61566eull,0x706d61535f645f69ull,0x0a3078302b73656cull,0x3436752e74766309ull,
0x722509203233732eull,0x3b337225202c3464ull,0x0920202020202020ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x25202c3564722509ull,0x203b34202c346472ull,0x0a202f2f09202020ull,
0x3436752e64646109ull,0x202c366472250920ull,0x7225202c33647225ull,0x09202020203b3564ull,
0x766f6d090a202f2full,0x722509203436752eull,0x704f5f64202c3764ull,0x617461446e6f6974ull,
0x0a202f2f0920203bull,0x3436732e74766309ull,0x722509203233732eull,0x3b347225202c3864ull,
0x0920202020202020ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x25202c3964722509ull,
0x3b3233202c386472ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c30316472250920ull,
0x25202c3764722520ull,0x092020203b396472ull,0x2e646c090a202f2full,0x36662e74736e6f63ull,
0x2c33646625092034ull,0x2b30316472255b20ull,0x202f2f093b5d3631ull,0x64203535313a6469ull,
0x446e6f6974704f5full,0x0a3078302b617461ull,0x736e6f632e646c09ull,0x2509203436662e74ull,
0x72255b202c346466ull,0x3b5d34322b303164ull,0x313a6469202f2f09ull,0x74704f5f64203635ull,
0x2b617461446e6f69ull,0x2e646c090a307830ull,0x36662e74736e6f63ull,0x2c35646625092034ull,
0x2b30316472255b20ull,0x69202f2f093b5d30ull,0x5f64203735313a64ull,0x61446e6f6974704full,
0x090a3078302b6174ull,0x74736e6f632e646cull,0x662509203436662eull,0x6472255b202c3664ull,
0x2f093b5d382b3031ull,0x3835313a6469202full,0x6f6974704f5f6420ull,0x78302b617461446eull,
0x5f305f744c240a30ull,0x3c2f2f200a3a3032ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x39323120656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,
0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,
0x0a30093033310933ull,0x626f6c672e646c09ull,0x09203233662e6c61ull,0x72255b202c316625ull,
0x09203b5d302b3664ull,0x35313a6469202f2full,0x662e747663090a39ull,0x09203233662e3436ull,
0x6625202c37646625ull,0x2020202020203b31ull,0x2e090a202f2f0920ull,0x3331093309636f6cull,
0x64616d090a300931ull,0x662509203436662eull,0x37646625202c3864ull,0x202c34646625202cull,
0x2f2f093b33646625ull,0x662e766f6d090a20ull,0x3964662509203436ull,0x363830346430202cull,
0x6166656632346532ull,0x2f2f093b66653933ull,0x3338372e39303720ull,0x672e70746573090aull,
0x2509203436662e74ull,0x38646625202c3270ull,0x203b39646625202cull,0x2140090a202f2f09ull,
0x2061726220327025ull,0x325f305f744c2409ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3932312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x6f6d090a30325f30ull,
0x2509203436662e76ull,0x6430202c30316466ull,0x3030303030666637ull,0x3030303030303030ull,
0x666e69202f2f093bull,0x6e752e617262090aull,0x305f744c24092069ull,0x20202020203b315full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x200a3a31325f305full,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393231ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e766f6d090a3032ull,0x6466250920343666ull,
0x30636430202c3131ull,0x3564303139343738ull,0x093b323530336432ull,0x2e3534372d202f2full,
0x746573090a333331ull,0x3436662e656c2e70ull,0x25202c3370250920ull,0x646625202c386466ull,
0x0a202f2f093b3131ull,0x6220337025214009ull,0x5f744c2409206172ull,0x2020203b33325f30ull,
0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x39323120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x0a30325f305f744cull,0x3436662e766f6d09ull,0x2c30316466250920ull,0x3030303030643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x752e617262090a30ull,0x5f744c240920696eull,
0x202020203b315f30ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x0a3a33325f305f74ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39323120ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x6f6c2e090a30325full,
0x3835370938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x66336430202c3231ull,
0x3536373435313766ull,0x093b656632386232ull,0x3234342e31202f2full,0x662e6c756d090a37ull,
0x3164662509203436ull,0x2c38646625202c33ull,0x203b323164662520ull,0x63090a202f2f0920ull,
0x662e696e722e7476ull,0x09203436662e3436ull,0x25202c3431646625ull,0x2f2f093b33316466ull,
0x722e747663090a20ull,0x662e3233732e697aull,0x2c39722509203436ull,0x203b343164662520ull,
0x6d090a202f2f0920ull,0x09203233732e766full,0x7225202c30317225ull,0x2020202020203b39ull,
0x2f2f092020202020ull,0x752e766f6d090a20ull,0x3131722509203233ull,0x3b313230312d202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x732e74672e707465ull,0x2c34702509203233ull,
0x7225202c39722520ull,0x2f2f0920203b3131ull,0x2034702540090a20ull,0x744c240920617262ull,
0x20203b36325f305full,0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3932ull,
0x64656c6562616c20ull,0x325f305f744c2420ull,0x09636f6c2e090a30ull,0x3009333637093832ull,
0x33732e646461090aull,0x2c30317225092032ull,0x3535202c39722520ull,0x202020202020203bull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x6430202c35316466ull,0x3030303030396333ull,
0x3030303030303030ull,0x352e35202f2f093bull,0x37312d6532313135ull,0x6e752e617262090aull,
0x305f744c24092069ull,0x202020203b35325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x200a3a36325f305full,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393231ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x2e766f6d090a3032ull,0x6466250920343666ull,0x30346430202c3531ull,0x3030303030303030ull,
0x093b303030303030ull,0x744c240a32202f2full,0x200a3a35325f305full,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393231ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x636f6c2e090a3032ull,0x0939383309383209ull,
0x662e766f6d090a30ull,0x3164662509203436ull,0x6566626430202c36ull,0x6665663234653236ull,
0x2f093b6665393361ull,0x3339362e302d202full,0x64616d090a373431ull,0x203436662e6e722eull,
0x202c373164662509ull,0x25202c3431646625ull,0x6625202c36316466ull,0x0a202f2f093b3864ull,
0x3436662e766f6d09ull,0x2c38316466250920ull,0x6261376362643020ull,0x3839336233653963ull,
0x202f2f093b663330ull,0x35303931332e322dull,0x616d090a37312d65ull,0x3436662e6e722e64ull,
0x2c39316466250920ull,0x202c343164662520ull,0x25202c3831646625ull,0x2f2f093b37316466ull,
0x662e766f6d090a20ull,0x3264662509203436ull,0x3265336430202c30ull,0x6663636637306631ull,
0x2f093b6461623835ull,0x343838302e32202full,0x6d090a39302d6533ull,0x09203436662e766full,
0x30202c3132646625ull,0x3864666135653364ull,0x6162336336616431ull,0x2e32202f2f093b66ull,
0x302d653636333135ull,0x722e64616d090a38ull,0x2509203436662e6eull,0x6625202c32326466ull,
0x646625202c303264ull,0x32646625202c3931ull,0x090a202f2f093b31ull,0x203436662e766f6dull,
0x202c333264662509ull,0x6537323965336430ull,0x3038663036663535ull,0x32202f2f093b3665ull,
0x2d6535373535372eull,0x2e64616d090a3730ull,0x09203436662e6e72ull,0x25202c3432646625ull,
0x6625202c32326466ull,0x646625202c393164ull,0x0a202f2f093b3332ull,0x383209636f6c2e09ull,
0x090a300930393309ull,0x203436662e766f6dull,0x202c353264662509ull,0x6431376365336430ull,
0x3664323066386164ull,0x32202f2f093b3636ull,0x2d6532373535372eull,0x2e64616d090a3630ull,
0x09203436662e6e72ull,0x25202c3432646625ull,0x6625202c34326466ull,0x646625202c393164ull,
0x0a202f2f093b3532ull,0x383209636f6c2e09ull,0x090a300931393309ull,0x203436662e766f6dull,
0x202c363264662509ull,0x3130616665336430ull,0x3439386233313061ull,0x32202f2f093b3065ull,
0x2d6536313038342eull,0x2e64616d090a3530ull,0x09203436662e6e72ull,0x25202c3432646625ull,
0x6625202c34326466ull,0x646625202c393164ull,0x0a202f2f093b3632ull,0x383209636f6c2e09ull,
0x090a300932393309ull,0x203436662e766f6dull,0x202c373264662509ull,0x3130613266336430ull,
0x3766613364313061ull,0x30202f2f093b3838ull,0x343839313030302eull,0x2e64616d090a3331ull,
0x09203436662e6e72ull,0x25202c3432646625ull,0x6625202c34326466ull,0x646625202c393164ull,
0x0a202f2f093b3732ull,0x383209636f6c2e09ull,0x090a300933393309ull,0x203436662e766f6dull,
0x202c383264662509ull,0x3163363566336430ull,0x3161336336316336ull,0x30202f2f093b6365ull,
0x383838333130302eull,0x722e64616d090a39ull,0x2509203436662e6eull,0x6625202c34326466ull,
0x646625202c343264ull,0x32646625202c3931ull,0x090a202f2f093b38ull,0x09383209636f6c2eull,
0x6d090a3009343933ull,0x09203436662e766full,0x30202c3932646625ull,0x3131313138663364ull,
0x3631393031313131ull,0x2e30202f2f093b31ull,0x3333333333383030ull,0x6e722e64616d090aull,
0x662509203436662eull,0x646625202c343264ull,0x31646625202c3432ull,0x3932646625202c39ull,
0x2e090a202f2f093bull,0x3309383209636f6cull,0x6f6d090a30093539ull,0x2509203436662e76ull,
0x6430202c30336466ull,0x3535353535616633ull,0x3163343535353535ull,0x302e30202f2f093bull,
0x090a373636363134ull,0x662e6e722e64616dull,0x3264662509203436ull,0x3432646625202c34ull,
0x2c3931646625202cull,0x093b303364662520ull,0x6f6c2e090a202f2full,0x3639330938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x66336430202c3133ull,0x3535353535353563ull,
0x093b663635353535ull,0x3636312e30202f2full,0x64616d090a373636ull,0x203436662e6e722eull,
0x202c343264662509ull,0x25202c3432646625ull,0x6625202c39316466ull,0x202f2f093b313364ull,
0x3209636f6c2e090aull,0x0a30093739330938ull,0x3436662e766f6d09ull,0x2c32336466250920ull,
0x3030656633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x64616d090a352e30ull,
0x203436662e6e722eull,0x202c343264662509ull,0x25202c3432646625ull,0x6625202c39316466ull,
0x202f2f093b323364ull,0x3209636f6c2e090aull,0x0a30093939330938ull,0x3436662e6c756d09ull,
0x2c33336466250920ull,0x202c393164662520ull,0x09203b3432646625ull,0x64616d090a202f2full,
0x203436662e6e722eull,0x202c343264662509ull,0x25202c3333646625ull,0x6625202c39316466ull,
0x202f2f093b393164ull,0x3209636f6c2e090aull,0x0a30093238370938ull,0x3233732e64646109ull,
0x202c323172250920ull,0x3031202c30317225ull,0x09202020203b3232ull,0x6c6873090a202f2full,
0x722509203233622eull,0x32317225202c3331ull,0x2020203b3032202cull,0x0a202f2f09202020ull,
0x3233732e766f6d09ull,0x202c343172250920ull,0x2020202020203b30ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203436622eull,0x72257b202c343364ull,0x7d333172252c3431ull,
0x0a202f2f0920203bull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x32646625202c3533ull,
0x3433646625202c34ull,0x3b3433646625202cull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x6625202c30316466ull,0x646625202c353164ull,0x202f2f09203b3533ull,0x315f305f744c240aull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39323120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x2e090a30325f305full,
0x3331093309636f6cull,0x6c756d090a300932ull,0x662509203436662eull,0x646625202c363364ull,
0x35646625202c3031ull,0x0a202f2f0920203bull,0x3436662e62757309ull,0x2c37336466250920ull,
0x202c363364662520ull,0x0920203b36646625ull,0x766f6d090a202f2full,0x662509203436662eull,
0x306430202c383364ull,0x3030303030303030ull,0x3b30303030303030ull,0x6d090a30202f2f09ull,
0x09203436662e7861ull,0x25202c3933646625ull,0x6625202c37336466ull,0x2f2f09203b383364ull,
0x662e646461090a20ull,0x3264662509203436ull,0x2c3933646625202cull,0x20203b3264662520ull,
0x2e090a202f2f0920ull,0x3331093309636f6cull,0x64616d090a300933ull,0x662509203436662eull,
0x33646625202c3164ull,0x3933646625202c39ull,0x093b31646625202cull,0x646461090a202f2full,
0x722509203233732eull,0x202c377225202c37ull,0x202020203b367225ull,0x0a202f2f09202020ull,
0x3436752e64646109ull,0x202c366472250920ull,0x7225202c32647225ull,0x09202020203b3664ull,
0x746573090a202f2full,0x3233732e746c2e70ull,0x25202c3570250920ull,0x3b387225202c3772ull,
0x0a202f2f09202020ull,0x7262203570254009ull,0x305f744c24092061ull,0x202020203b30325full,
0x0920202020202020ull,0x617262090a202f2full,0x4c240920696e752eull,0x203b38315f305f74ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x38325f305f744c24ull,0x772e6c756d090a3aull,
0x203631752e656469ull,0x7225202c36722509ull,0x31687225202c3368ull,0x4c240a202f2f093bull,
0x0a3a38315f305f74ull,0x093309636f6c2e09ull,0x6c090a3009353331ull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x635f5f5b202c3131ull,0x5f6d726170616475ull,0x746e6f4d36315a5full,
0x654b6f6c72614365ull,0x5f3431506c656e72ull,0x6e6f6974704f545full,0x69665065756c6156ull,
0x65666675425f645full,0x69202f2f093b5d72ull,0x5f5f203036313a64ull,0x6d72617061647563ull,
0x6e6f4d36315a5f5full,0x4b6f6c7261436574ull,0x3431506c656e7265ull,0x6f6974704f545f5full,
0x665065756c61566eull,0x666675425f645f69ull,0x090a3078302b7265ull,0x732e6f6c2e6c756dull,
0x3531722509203233ull,0x25202c347225202cull,0x2f092020203b3672ull,0x2e646461090a202full,
0x3172250920323373ull,0x202c337225202c36ull,0x2020203b35317225ull,0x090a202f2f092020ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x36317225202c3231ull,0x2f0920202020203bull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3331647225ull,0x3631202c32316472ull,
0x090a202f2f09203bull,0x203436752e646461ull,0x202c343164722509ull,0x25202c3131647225ull,
0x2f09203b33316472ull,0x672e7473090a202full,0x36662e6c61626f6cull,0x316472255b092034ull,
0x6625202c5d302b34ull,0x69202f2f093b3264ull,0x73090a3136313a64ull,0x6c61626f6c672e74ull,
0x255b09203436662eull,0x2c5d382b34316472ull,0x2f093b3164662520ull,0x3236313a6469202full,
0x3309636f6c2e090aull,0x090a300936333109ull,0x2020203b74697865ull,0x2020202020202020ull,
0x2020202020202020ull,0x2f09202020202020ull,0x6557444c240a202full,0x4d36315a5f5f646eull,
0x6c72614365746e6full,0x506c656e72654b6full,0x74704f545f5f3431ull,0x65756c61566e6f69ull,
0x207d090a3a696650ull,0x4d36315a5f202f2full,0x6c72614365746e6full,0x506c656e72654b6full,
0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x652e090a0a696650ull,0x325a5f207972746eull,
0x614365746e6f4d37ull,0x6c42656e4f6f6c72ull,0x704f7265506b636full,0x0a6966506e6f6974ull,
0x6765722e090a7b09ull,0x7225203233752e20ull,0x2e090a3b3e39333cull,0x3436752e20676572ull,
0x3e38323c64722520ull,0x206765722e090a3bull,0x3c6625203233662eull,0x65722e090a3b3e33ull,
0x25203436662e2067ull,0x0a3b3e33373c6466ull,0x702e206765722e09ull,0x313c702520646572ull,
0x61702e090a3b3e34ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x37325a5f5f6d7261ull,
0x72614365746e6f4dull,0x6f6c42656e4f6f6cull,0x74704f7265506b63ull,0x645f6966506e6f69ull,
0x73656c706d61535full,0x617261702e090a3bull,0x5f203233732e206dull,0x726170616475635full,
0x6f4d37325a5f5f6dull,0x6f6c72614365746eull,0x6b636f6c42656e4full,0x6f6974704f726550ull,
0x7461705f6966506eull,0x68732e090a3b4e68ull,0x6c612e2064657261ull,0x622e2038206e6769ull,
0x616475635f5f2038ull,0x43326d75535f735full,0x34343338396c6c61ull,0x0a3b5d383430325bull,
0x6465726168732e09ull,0x206e67696c612e20ull,0x5f5f2038622e2038ull,0x535f735f61647563ull,
0x30316c6c61436d75ull,0x3430325b32393330ull,0x6f6c2e090a3b5d38ull,0x0939343109330963ull,
0x5f3142424c240a30ull,0x746e6f4d37325a5full,0x6e4f6f6c72614365ull,0x65506b636f6c4265ull,
0x506e6f6974704f72ull,0x6f6c2e090a3a6966ull,0x0934363109330963ull,0x732e747663090a30ull,
0x09203631752e3233ull,0x697425202c317225ull,0x202020203b782e64ull,0x6d090a202f2f0920ull,
0x09203233732e766full,0x317225202c327225ull,0x202020202020203bull,0x2f2f092020202020ull,
0x732e766f6d090a20ull,0x2c33722509203233ull,0x2020203b35353220ull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e656c2e707465ull,0x2c31702509203233ull,0x7225202c31722520ull,
0x2f2f092020203b33ull,0x3170252140090a20ull,0x4c24092061726220ull,0x203b39365f315f74ull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203436752e766full,0x5f5f202c31647225ull,
0x535f735f61647563ull,0x396c6c6143326d75ull,0x2f2f093b34343338ull,0x752e766f6d090a20ull,
0x3264722509203436ull,0x616475635f5f202cull,0x61436d75535f735full,0x3239333030316c6cull,
0x6d090a202f2f093bull,0x09203436752e766full,0x5f64202c33647225ull,0x61446e6f6974704full,
0x2f2f0920203b6174ull,0x732e747663090a20ull,0x09203631752e3233ull,0x746325202c347225ull,
0x20203b782e646961ull,0x63090a202f2f0920ull,0x732e3436732e7476ull,0x3464722509203233ull,
0x20203b347225202cull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,
0x647225202c356472ull,0x20203b3233202c34ull,0x61090a202f2f0920ull,0x09203436752e6464ull,
0x7225202c36647225ull,0x35647225202c3364ull,0x2f2f09202020203bull,0x6f632e646c090a20ull,
0x203436662e74736eull,0x5b202c3164662509ull,0x5d36312b36647225ull,0x3a6469202f2f093bull,
0x704f5f6420313632ull,0x617461446e6f6974ull,0x646c090a3078302bull,0x662e74736e6f632eull,
0x3264662509203436ull,0x2b366472255b202cull,0x202f2f093b5d3432ull,0x64203236323a6469ull,
0x446e6f6974704f5full,0x0a3078302b617461ull,0x736e6f632e646c09ull,0x2509203436662e74ull,
0x72255b202c336466ull,0x09203b5d302b3664ull,0x36323a6469202f2full,0x6974704f5f642033ull,
0x302b617461446e6full,0x632e646c090a3078ull,0x3436662e74736e6full,0x202c346466250920ull,
0x5d382b366472255bull,0x6469202f2f09203bull,0x4f5f64203436323aull,0x7461446e6f697470ull,
0x63090a3078302b61ull,0x732e3436752e7476ull,0x3764722509203233ull,0x20203b317225202cull,
0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3864722509203436ull,0x203b37647225202cull,
0x2020202020202020ull,0x63090a202f2f0920ull,0x752e3233752e7476ull,0x2c35722509203631ull,
0x782e6469746e2520ull,0x2f2f09202020203bull,0x732e747663090a20ull,0x09203233752e3436ull,
0x7225202c39647225ull,0x2020202020203b35ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x3031647225092034ull,0x202c37647225202cull,0x2f2f092020203b38ull,0x6c2e6c756d090a20ull,
0x2509203436752e6full,0x7225202c31316472ull,0x20203b38202c3964ull,0x61090a202f2f0920ull,
0x09203436752e6464ull,0x25202c3231647225ull,0x7225202c30316472ull,0x2f2f0920203b3264ull,
0x752e646461090a20ull,0x3164722509203436ull,0x3031647225202c33ull,0x203b31647225202cull,
0x6c090a202f2f0920ull,0x2e6d617261702e64ull,0x3672250920323373ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x4365746e6f4d3732ull,0x42656e4f6f6c7261ull,0x4f7265506b636f6cull,
0x6966506e6f697470ull,0x3b5d4e687461705full,0x323a6469202f2f09ull,0x6475635f5f203535ull,
0x5a5f5f6d72617061ull,0x4365746e6f4d3732ull,0x42656e4f6f6c7261ull,0x4f7265506b636f6cull,
0x6966506e6f697470ull,0x302b4e687461705full,0x315f744c240a3078ull,0x2f2f200a3a31375full,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x363120656e696c20ull,0x697473656e202c34ull,
0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,0x6e6f697461726574ull,
0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x3009363631093309ull,0x33732e766f6d090aull,
0x202c377225092032ull,0x202020203b327225ull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33732e65672e7074ull,0x202c327025092032ull,0x367225202c327225ull,0x202f2f092020203bull,
0x36662e766f6d090aull,0x2c35646625092034ull,0x3030303030643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x662e766f6d090a30ull,0x3664662509203436ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x32702540090a3020ull,0x4c24092061726220ull,
0x203b36395f315f74ull,0x2020202020202020ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c343631ull,
0x656c6562616c2064ull,0x5f315f744c242064ull,0x2e627573090a3137ull,0x3872250920323373ull,
0x25202c367225202cull,0x20202020203b3272ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x7225202c39722509ull,0x203b353532202c38ull,0x2f09202020202020ull,0x2e726873090a202full,
0x3172250920323373ull,0x202c397225202c30ull,0x20202020203b3133ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x32202c3131722509ull,0x20202020203b3535ull,0x2f09202020202020ull,
0x2e646e61090a202full,0x3172250920323362ull,0x2c30317225202c32ull,0x20203b3131722520ull,
0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3331722509ull,0x397225202c323172ull,
0x2f0920202020203bull,0x2e726873090a202full,0x3172250920323373ull,0x2c33317225202c34ull,
0x20202020203b3820ull,0x090a202f2f092020ull,0x6d617261702e646cull,0x722509203436752eull,
0x5f5f5b202c343164ull,0x6d72617061647563ull,0x6e6f4d37325a5f5full,0x4f6f6c7261436574ull,
0x506b636f6c42656eull,0x6e6f6974704f7265ull,0x61535f645f696650ull,0x093b5d73656c706dull,
0x36323a6469202f2full,0x616475635f5f2035ull,0x325a5f5f6d726170ull,0x614365746e6f4d37ull,
0x6c42656e4f6f6c72ull,0x704f7265506b636full,0x5f6966506e6f6974ull,0x656c706d61535f64ull,
0x6d090a3078302b73ull,0x36752e6f6c2e6c75ull,0x3531647225092034ull,0x202c38647225202cull,
0x2f2f092020203b34ull,0x752e646461090a20ull,0x3164722509203436ull,0x3431647225202c36ull,
0x3b3531647225202cull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3436ull,0x64656c6562616c20ull,
0x375f315f744c2420ull,0x732e766f6d090a31ull,0x3531722509203233ull,0x203b34317225202cull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x0a3a34375f315f74ull,0x706f6f6c3c2f2f20ull,
0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c36363120ull,0x656420676e697473ull,
0x202c32203a687470ull,0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,
0x2e090a6e776f6e6bull,0x3631093309636f6cull,0x2e646c090a300937ull,0x662e6c61626f6c67ull,
0x2c31662509203233ull,0x2b36316472255b20ull,0x69202f2f093b5d30ull,0x63090a3636323a64ull,
0x662e3436662e7476ull,0x3764662509203233ull,0x20203b316625202cull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x0a30093836310933ull,0x3436662e64616d09ull,0x202c386466250920ull,
0x6625202c37646625ull,0x31646625202c3264ull,0x6d090a202f2f093bull,0x09203436662e766full,
0x6430202c39646625ull,0x3234653236383034ull,0x6665393361666566ull,0x393037202f2f093bull,
0x6573090a3338372eull,0x36662e74672e7074ull,0x202c337025092034ull,0x6625202c38646625ull,
0x202f2f09203b3964ull,0x203370252140090aull,0x744c240920617262ull,0x20203b35375f315full,
0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363120656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,
0x34375f315f744c24ull,0x36662e766f6d090aull,0x3031646625092034ull,0x306666376430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x7262090a666e6920ull,0x240920696e752e61ull,
0x203b315f315f744cull,0x2020202020202020ull,0x202f2f0920202020ull,0x375f315f744c240aull,
0x6c3c2f2f200a3a35ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36363120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x090a34375f315f74ull,
0x203436662e766f6dull,0x202c313164662509ull,0x3934373830636430ull,0x3033643235643031ull,
0x2d202f2f093b3235ull,0x0a3333312e353437ull,0x656c2e7074657309ull,0x702509203436662eull,
0x2c38646625202c34ull,0x093b313164662520ull,0x252140090a202f2full,0x0920617262203470ull,
0x37375f315f744c24ull,0x202020202020203bull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36363120ull,
0x6c6562616c206461ull,0x315f744c24206465ull,0x766f6d090a34375full,0x662509203436662eull,
0x306430202c303164ull,0x3030303030303030ull,0x3b30303030303030ull,0x62090a30202f2f09ull,
0x0920696e752e6172ull,0x3b315f315f744c24ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x5f315f744c240a20ull,0x3c2f2f200a3a3737ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36363120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x0a34375f315f744cull,0x383209636f6c2e09ull,0x090a300938353709ull,0x203436662e766f6dull,
0x202c323164662509ull,0x3531376666336430ull,0x3238623235363734ull,0x31202f2f093b6566ull,
0x6d090a373234342eull,0x09203436662e6c75ull,0x25202c3331646625ull,0x646625202c386466ull,
0x2f2f0920203b3231ull,0x722e747663090a20ull,0x662e3436662e696eull,0x3164662509203436ull,
0x3331646625202c34ull,0x63090a202f2f093bull,0x732e697a722e7476ull,0x09203436662e3233ull,
0x6625202c36317225ull,0x2f2f09203b343164ull,0x732e766f6d090a20ull,0x3731722509203233ull,
0x203b36317225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233752e766full,
0x312d202c38317225ull,0x202020203b313230ull,0x2f2f092020202020ull,0x2e70746573090a20ull,
0x09203233732e7467ull,0x317225202c357025ull,0x3b38317225202c36ull,0x40090a202f2f0920ull,
0x2061726220357025ull,0x385f315f744c2409ull,0x2020202020203b30ull,0x2f2f092020202020ull,
0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36363120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x2e090a34375f315full,
0x3709383209636f6cull,0x6461090a30093336ull,0x2509203233732e64ull,0x317225202c373172ull,
0x20203b3535202c36ull,0x202f2f0920202020ull,0x36662e766f6d090aull,0x3531646625092034ull,
0x303963336430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x32313135352e3520ull,
0x7262090a37312d65ull,0x240920696e752e61ull,0x3b39375f315f744cull,0x2020202020202020ull,
0x202f2f0920202020ull,0x385f315f744c240aull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36363120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x090a34375f315f74ull,0x203436662e766f6dull,0x202c353164662509ull,
0x3030303030346430ull,0x3030303030303030ull,0x32202f2f093b3030ull,0x375f315f744c240aull,
0x6c3c2f2f200a3a39ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36363120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x090a34375f315f74ull,
0x09383209636f6c2eull,0x6d090a3009393833ull,0x09203436662e766full,0x30202c3631646625ull,
0x3465323665666264ull,0x6539336166656632ull,0x302d202f2f093b66ull,0x0a3734313339362eull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3731ull,0x3631646625202c34ull,
0x093b38646625202cull,0x766f6d090a202f2full,0x662509203436662eull,0x626430202c383164ull,
0x3365396362613763ull,0x3b66333038393362ull,0x332e322d202f2f09ull,0x37312d6535303931ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c393164ull,0x31646625202c3431ull,
0x3731646625202c38ull,0x6d090a202f2f093bull,0x09203436662e766full,0x30202c3032646625ull,
0x3730663132653364ull,0x6162383566636366ull,0x2e32202f2f093b64ull,0x302d653334383830ull,
0x662e766f6d090a39ull,0x3264662509203436ull,0x3565336430202c31ull,0x3661643138646661ull,
0x2f093b6661623363ull,0x363331352e32202full,0x6d090a38302d6536ull,0x36662e6e722e6461ull,
0x3232646625092034ull,0x2c3032646625202cull,0x202c393164662520ull,0x2f093b3132646625ull,
0x2e766f6d090a202full,0x6466250920343666ull,0x65336430202c3332ull,0x3666353565373239ull,
0x093b366530386630ull,0x3535372e32202f2full,0x090a37302d653537ull,0x662e6e722e64616dull,
0x3264662509203436ull,0x3232646625202c34ull,0x2c3931646625202cull,0x093b333264662520ull,
0x6f6c2e090a202f2full,0x3039330938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,
0x65336430202c3532ull,0x6638616464313763ull,0x093b363636643230ull,0x3535372e32202f2full,
0x090a36302d653237ull,0x662e6e722e64616dull,0x3264662509203436ull,0x3432646625202c34ull,
0x2c3931646625202cull,0x093b353264662520ull,0x6f6c2e090a202f2full,0x3139330938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x65336430202c3632ull,0x3331306131306166ull,
0x093b306534393862ull,0x3038342e32202f2full,0x090a35302d653631ull,0x662e6e722e64616dull,
0x3264662509203436ull,0x3432646625202c34ull,0x2c3931646625202cull,0x093b363264662520ull,
0x6f6c2e090a202f2full,0x3239330938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,
0x66336430202c3732ull,0x6431306131306132ull,0x093b383837666133ull,0x3030302e30202f2full,
0x090a333134383931ull,0x662e6e722e64616dull,0x3264662509203436ull,0x3432646625202c34ull,
0x2c3931646625202cull,0x093b373264662520ull,0x6f6c2e090a202f2full,0x3339330938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x66336430202c3832ull,0x3631633631633635ull,
0x093b636531613363ull,0x3130302e30202f2full,0x6d090a3938383833ull,0x36662e6e722e6461ull,
0x3432646625092034ull,0x2c3432646625202cull,0x202c393164662520ull,0x2f093b3832646625ull,
0x636f6c2e090a202full,0x0934393309383209ull,0x662e766f6d090a30ull,0x3264662509203436ull,
0x3866336430202c39ull,0x3131313131313131ull,0x2f093b3136313930ull,0x333830302e30202full,
0x616d090a33333333ull,0x3436662e6e722e64ull,0x2c34326466250920ull,0x202c343264662520ull,
0x25202c3931646625ull,0x2f2f093b39326466ull,0x09636f6c2e090a20ull,0x3009353933093832ull,
0x36662e766f6d090aull,0x3033646625092034ull,0x356166336430202cull,0x3535353535353535ull,
0x2f2f093b31633435ull,0x36363134302e3020ull,0x2e64616d090a3736ull,0x09203436662e6e72ull,
0x25202c3432646625ull,0x6625202c34326466ull,0x646625202c393164ull,0x0a202f2f093b3033ull,
0x383209636f6c2e09ull,0x090a300936393309ull,0x203436662e766f6dull,0x202c313364662509ull,
0x3535356366336430ull,0x3535353535353535ull,0x30202f2f093b6636ull,0x0a3736363636312eull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x32646625202c3432ull,0x3931646625202c34ull,
0x3b3133646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300937ull,
0x662509203436662eull,0x336430202c323364ull,0x3030303030306566ull,0x3b30303030303030ull,
0x0a352e30202f2f09ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x32646625202c3432ull,
0x3931646625202c34ull,0x3b3233646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x6c756d090a300939ull,0x662509203436662eull,0x646625202c333364ull,0x32646625202c3931ull,
0x0a202f2f09203b34ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x33646625202c3432ull,
0x3931646625202c33ull,0x3b3931646625202cull,0x6c2e090a202f2f09ull,0x383709383209636full,
0x646461090a300932ull,0x722509203233732eull,0x37317225202c3931ull,0x203b32323031202cull,
0x0a202f2f09202020ull,0x3233622e6c687309ull,0x202c303272250920ull,0x3032202c39317225ull,
0x092020202020203bull,0x766f6d090a202f2full,0x722509203233732eull,0x20203b30202c3132ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x3436622e766f6d09ull,0x2c34336466250920ull,
0x252c313272257b20ull,0x0920203b7d303272ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x202c353364662509ull,0x25202c3432646625ull,0x6625202c34336466ull,0x202f2f093b343364ull,
0x36662e6c756d090aull,0x3031646625092034ull,0x2c3531646625202cull,0x203b353364662520ull,
0x744c240a202f2f09ull,0x2f200a3a315f315full,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3636ull,0x64656c6562616c20ull,
0x375f315f744c2420ull,0x09636f6c2e090a34ull,0x0a30093936310933ull,0x3436662e6c756d09ull,
0x2c36336466250920ull,0x202c303164662520ull,0x0920203b33646625ull,0x627573090a202f2full,
0x662509203436662eull,0x646625202c373364ull,0x34646625202c3633ull,0x0a202f2f0920203bull,
0x3436662e766f6d09ull,0x2c38336466250920ull,0x3030303030643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x662e78616d090a30ull,0x3364662509203436ull,0x3733646625202c39ull,
0x3b3833646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x6625202c36646625ull,
0x646625202c393364ull,0x2f2f092020203b36ull,0x09636f6c2e090a20ull,0x0a30093037310933ull,
0x3436662e64616d09ull,0x202c356466250920ull,0x25202c3933646625ull,0x6625202c39336466ull,
0x0a202f2f093b3564ull,0x3233732e64646109ull,0x25202c3772250920ull,0x3b363532202c3772ull,
0x0920202020202020ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c363164ull,
0x34323031202c3631ull,0x0a202f2f0920203bull,0x746c2e7074657309ull,0x702509203233732eull,
0x202c377225202c36ull,0x092020203b367225ull,0x702540090a202f2full,0x2409206172622036ull,
0x3b34375f315f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c34363120ull,
0x6c6562616c206461ull,0x315f744c24206465ull,0x617262090a31375full,0x4c240920696e752eull,
0x203b32375f315f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x36395f315f744c24ull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c34363120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x4c240a31375f315full,
0x0a3a32375f315f74ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c34363120ull,0x6c6562616c206461ull,0x315f744c24206465ull,
0x6f6c2e090a31375full,0x0932373109330963ull,0x68732e7473090a30ull,0x3436662e64657261ull,
0x32316472255b0920ull,0x646625202c5d302bull,0x6469202f2f093b36ull,0x635f5f203736323aull,
0x75535f735f616475ull,0x3030316c6c61436dull,0x0a3078302b323933ull,0x093309636f6c2e09ull,
0x73090a3009333731ull,0x6465726168732e74ull,0x255b09203436662eull,0x2c5d302b33316472ull,
0x2f093b3564662520ull,0x3836323a6469202full,0x5f616475635f5f20ull,0x6143326d75535f73ull,
0x2b34343338396c6cull,0x646461090a307830ull,0x722509203233752eull,0x202c327225202c32ull,
0x202020203b357225ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x202c386472250920ull,
0x7225202c39647225ull,0x09202020203b3864ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c333164ull,0x31647225202c3131ull,0x0a202f2f09203b33ull,0x3436752e64646109ull,
0x2c32316472250920ull,0x202c313164722520ull,0x09203b3231647225ull,0x766f6d090a202f2full,
0x722509203233752eull,0x3b353532202c3232ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x656c2e7074657309ull,0x702509203233732eull,0x202c327225202c37ull,0x0920203b32327225ull,
0x702540090a202f2full,0x2409206172622037ull,0x3b31375f315f744cull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x39365f315f744c24ull,0x09636f6c2e090a3aull,0x0a30093837310933ull,
0x3436752e766f6d09ull,0x202c316472250920ull,0x735f616475635f5full,0x6c6143326d75535full,
0x093b34343338396cull,0x766f6d090a202f2full,0x722509203436752eull,0x75635f5f202c3264ull,
0x6d75535f735f6164ull,0x333030316c6c6143ull,0x0a202f2f093b3239ull,0x373109636f6c2e09ull,
0x6d090a3009333809ull,0x09203233732e766full,0x7225202c33327225ull,0x2020202020203b31ull,
0x2f2f092020202020ull,0x3170252140090a20ull,0x4c24092061726220ull,0x203b33385f315f74ull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,0x3135202c34327225ull,
0x2020202020203b31ull,0x2f2f092020202020ull,0x732e627573090a20ull,0x3532722509203233ull,
0x202c34327225202cull,0x202020203b317225ull,0x73090a202f2f0920ull,0x09203233732e7268ull,
0x7225202c36327225ull,0x203b3133202c3532ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3732722509203233ull,0x20203b353532202cull,0x2020202020202020ull,0x61090a202f2f0920ull,
0x09203233622e646eull,0x7225202c38327225ull,0x37327225202c3632ull,0x2f2f09202020203bull,
0x732e646461090a20ull,0x3932722509203233ull,0x202c38327225202cull,0x2020203b35327225ull,
0x73090a202f2f0920ull,0x09203233732e7268ull,0x7225202c30337225ull,0x20203b38202c3932ull,
0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3133722509203233ull,0x203b30337225202cull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x0a3a35385f315f74ull,0x706f6f6c3c2f2f20ull,
0x6220706f6f4c203eull,0x656e696c2079646full,0x73656e202c333820ull,0x70656420676e6974ull,
0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,0x6b6e75203a736e6full,
0x6c2e090a6e776f6eull,0x343809373109636full,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x2020202020202020ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09373109636f6c2eull,
0x6f6d090a30093538ull,0x2509203233752e76ull,0x373231202c323372ull,0x202020202020203bull,
0x202f2f0920202020ull,0x672e70746573090aull,0x2509203233732e74ull,0x33327225202c3870ull,
0x203b32337225202cull,0x2540090a202f2f09ull,0x0920617262203870ull,0x36385f315f744c24ull,
0x202020202020203bull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x6568202c33382065ull,0x6c6562616c206461ull,
0x315f744c24206465ull,0x6f6c2e090a35385full,0x0935350937310963ull,0x752e747663090a30ull,
0x09203233732e3436ull,0x25202c3731647225ull,0x202020203b333272ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3831647225092034ull,0x2c3731647225202cull,0x2f2f0920203b3820ull,
0x752e646461090a20ull,0x3164722509203436ull,0x3831647225202c39ull,0x203b32647225202cull,
0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203436662eull,0x72255b202c303464ull,
0x093b5d302b393164ull,0x36323a6469202f2full,0x616475635f5f2039ull,0x61436d75535f735full,
0x3239333030316c6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x6466250920343666ull,
0x6472255b202c3134ull,0x5d343230312b3931ull,0x3a6469202f2f093bull,0x75635f5f20303732ull,
0x6d75535f735f6164ull,0x333030316c6c6143ull,0x090a3078302b3239ull,0x203436662e646461ull,
0x202c323464662509ull,0x25202c3034646625ull,0x2f09203b31346466ull,0x732e7473090a202full,
0x36662e6465726168ull,0x316472255b092034ull,0x6625202c5d302b39ull,0x202f2f093b323464ull,
0x5f203137323a6469ull,0x5f735f616475635full,0x316c6c61436d7553ull,0x78302b3239333030ull,
0x752e646461090a30ull,0x3264722509203436ull,0x3831647225202c30ull,0x203b31647225202cull,
0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203436662eull,0x72255b202c333464ull,
0x093b5d302b303264ull,0x37323a6469202f2full,0x616475635f5f2032ull,0x43326d75535f735full,
0x34343338396c6c61ull,0x646c090a3078302bull,0x2e6465726168732eull,0x6466250920343666ull,
0x6472255b202c3434ull,0x5d343230312b3032ull,0x3a6469202f2f093bull,0x75635f5f20333732ull,
0x6d75535f735f6164ull,0x3338396c6c614332ull,0x090a3078302b3434ull,0x203436662e646461ull,
0x202c353464662509ull,0x25202c3334646625ull,0x2f09203b34346466ull,0x732e7473090a202full,
0x36662e6465726168ull,0x326472255b092034ull,0x6625202c5d302b30ull,0x202f2f093b353464ull,
0x5f203437323a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,0x78302b3434333839ull,
0x5f315f744c240a30ull,0x3c2f2f200a3a3638ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x2c333820656e696cull,0x616c206461656820ull,0x4c242064656c6562ull,
0x090a35385f315f74ull,0x636e79732e726162ull,0x202020203b300920ull,0x2020202020202020ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3372250920323375ull,0x20203b3336202c33ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x2e74672e70746573ull,0x3970250920323373ull,
0x202c33327225202cull,0x2f09203b33337225ull,0x39702540090a202full,0x4c24092061726220ull,
0x203b38385f315f74ull,0x2020202020202020ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x64616568202c3338ull,
0x64656c6562616c20ull,0x385f315f744c2420ull,0x09636f6c2e090a35ull,0x0a30093635093731ull,
0x3436752e74766309ull,0x722509203233732eull,0x327225202c313264ull,0x0920202020203b33ull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c383164722509ull,0x38202c3132647225ull,
0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c39316472250920ull,0x202c383164722520ull,
0x0920203b32647225ull,0x2e646c090a202f2full,0x662e646572616873ull,0x3464662509203436ull,
0x316472255b202c36ull,0x2f2f093b5d302b39ull,0x203537323a646920ull,0x735f616475635f5full,
0x6c6c61436d75535full,0x302b323933303031ull,0x732e646c090a3078ull,0x36662e6465726168ull,
0x3734646625092034ull,0x39316472255b202cull,0x2f093b5d3231352bull,0x3637323a6469202full,
0x5f616475635f5f20ull,0x6c61436d75535f73ull,0x2b3239333030316cull,0x646461090a307830ull,
0x662509203436662eull,0x646625202c383464ull,0x34646625202c3634ull,0x0a202f2f09203b37ull,
0x726168732e747309ull,0x09203436662e6465ull,0x302b39316472255bull,0x3834646625202c5dull,
0x3a6469202f2f093bull,0x75635f5f20373732ull,0x6d75535f735f6164ull,0x333030316c6c6143ull,
0x090a3078302b3239ull,0x203436752e646461ull,0x202c303264722509ull,0x25202c3831647225ull,
0x2f0920203b316472ull,0x732e646c090a202full,0x36662e6465726168ull,0x3934646625092034ull,
0x30326472255b202cull,0x202f2f093b5d302bull,0x5f203837323a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x78302b3434333839ull,0x68732e646c090a30ull,0x3436662e64657261ull,
0x2c30356466250920ull,0x2b30326472255b20ull,0x2f2f093b5d323135ull,0x203937323a646920ull,
0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,0x2e646461090a3078ull,
0x6466250920343666ull,0x34646625202c3135ull,0x3035646625202c39ull,0x090a202f2f09203bull,
0x65726168732e7473ull,0x5b09203436662e64ull,0x5d302b3032647225ull,0x3b3135646625202cull,
0x323a6469202f2f09ull,0x6475635f5f203038ull,0x326d75535f735f61ull,0x343338396c6c6143ull,
0x4c240a3078302b34ull,0x0a3a38385f315f74ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x616568202c333820ull,0x656c6562616c2064ull,
0x5f315f744c242064ull,0x2e726162090a3538ull,0x3b300920636e7973ull,0x2020202020202020ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233752e766f6dull,0x33202c3433722509ull,
0x2020202020203b31ull,0x2f09202020202020ull,0x70746573090a202full,0x203233732e74672eull,
0x25202c3031702509ull,0x337225202c333272ull,0x090a202f2f093b34ull,0x7262203031702540ull,
0x315f744c24092061ull,0x202020203b30395full,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x202c333820656e69ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x2e090a35385f315full,0x3609373109636f6cull,
0x747663090a300932ull,0x3233732e3436752eull,0x2c32326472250920ull,0x20203b3332722520ull,
0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x32647225202c3831ull,
0x0920203b38202c32ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c393164ull,
0x32647225202c3831ull,0x0a202f2f0920203bull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3235646625ull,0x5d302b3931647225ull,0x3a6469202f2f093bull,0x75635f5f20313832ull,
0x6d75535f735f6164ull,0x333030316c6c6143ull,0x090a3078302b3239ull,0x65726168732e646cull,
0x2509203436662e64ull,0x255b202c33356466ull,0x3635322b39316472ull,0x6469202f2f093b5dull,
0x635f5f203238323aull,0x75535f735f616475ull,0x3030316c6c61436dull,0x0a3078302b323933ull,
0x3436662e64646109ull,0x2c34356466250920ull,0x202c323564662520ull,0x09203b3335646625ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3931ull,
0x2f2f093b34356466ull,0x203338323a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,
0x302b323933303031ull,0x2e646461090a3078ull,0x6472250920343675ull,0x31647225202c3032ull,
0x3b31647225202c38ull,0x090a202f2f092020ull,0x65726168732e646cull,0x2509203436662e64ull,
0x255b202c35356466ull,0x3b5d302b30326472ull,0x323a6469202f2f09ull,0x6475635f5f203438ull,
0x326d75535f735f61ull,0x343338396c6c6143ull,0x6c090a3078302b34ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c363564ull,0x5d3635322b303264ull,0x3a6469202f2f093bull,
0x75635f5f20353832ull,0x6d75535f735f6164ull,0x3338396c6c614332ull,0x090a3078302b3434ull,
0x203436662e646461ull,0x202c373564662509ull,0x25202c3535646625ull,0x2f09203b36356466ull,
0x732e7473090a202full,0x36662e6465726168ull,0x326472255b092034ull,0x6625202c5d302b30ull,
0x202f2f093b373564ull,0x5f203638323a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,
0x78302b3434333839ull,0x09636f6c2e090a30ull,0x0a30093336093731ull,0x726168732e646c09ull,
0x09203436662e6465ull,0x5b202c3835646625ull,0x32312b3931647225ull,0x69202f2f093b5d38ull,
0x5f5f203738323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b32393330ull,
0x36662e646461090aull,0x3435646625092034ull,0x2c3835646625202cull,0x203b343564662520ull,
0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,0x202c5d302b393164ull,
0x2f093b3435646625ull,0x3838323a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3239333030316cull,0x2e646c090a307830ull,0x662e646572616873ull,0x3564662509203436ull,
0x326472255b202c39ull,0x093b5d3832312b30ull,0x38323a6469202f2full,0x616475635f5f2039ull,
0x43326d75535f735full,0x34343338396c6c61ull,0x6461090a3078302bull,0x2509203436662e64ull,
0x6625202c37356466ull,0x646625202c393564ull,0x202f2f09203b3735ull,0x6168732e7473090aull,
0x203436662e646572ull,0x2b30326472255b09ull,0x35646625202c5d30ull,0x6469202f2f093b37ull,
0x635f5f203039323aull,0x75535f735f616475ull,0x38396c6c6143326dull,0x0a3078302b343433ull,
0x373109636f6c2e09ull,0x6c090a3009343609ull,0x6465726168732e64ull,0x662509203436662eull,
0x72255b202c303664ull,0x3b5d34362b393164ull,0x323a6469202f2f09ull,0x6475635f5f203139ull,
0x436d75535f735f61ull,0x39333030316c6c61ull,0x61090a3078302b32ull,0x09203436662e6464ull,
0x25202c3435646625ull,0x6625202c30366466ull,0x2f2f09203b343564ull,0x68732e7473090a20ull,
0x3436662e64657261ull,0x39316472255b0920ull,0x646625202c5d302bull,0x69202f2f093b3435ull,
0x5f5f203239323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b32393330ull,
0x6168732e646c090aull,0x203436662e646572ull,0x202c313664662509ull,0x362b30326472255bull,
0x69202f2f093b5d34ull,0x5f5f203339323a64ull,0x535f735f61647563ull,0x396c6c6143326d75ull,
0x3078302b34343338ull,0x36662e646461090aull,0x3735646625092034ull,0x2c3136646625202cull,
0x203b373564662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,
0x202c5d302b303264ull,0x2f093b3735646625ull,0x3439323a6469202full,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x2b34343338396c6cull,0x6f6c2e090a307830ull,0x0935360937310963ull,
0x68732e646c090a30ull,0x3436662e64657261ull,0x2c32366466250920ull,0x2b39316472255b20ull,
0x202f2f093b5d3233ull,0x5f203539323a6469ull,0x5f735f616475635full,0x316c6c61436d7553ull,
0x78302b3239333030ull,0x662e646461090a30ull,0x3564662509203436ull,0x3236646625202c34ull,
0x3b3435646625202cull,0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203436662eull,
0x2c5d302b39316472ull,0x093b343564662520ull,0x39323a6469202f2full,0x616475635f5f2036ull,
0x61436d75535f735full,0x3239333030316c6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x6466250920343666ull,0x6472255b202c3336ull,0x093b5d32332b3032ull,0x39323a6469202f2full,
0x616475635f5f2037ull,0x43326d75535f735full,0x34343338396c6c61ull,0x6461090a3078302bull,
0x2509203436662e64ull,0x6625202c37356466ull,0x646625202c333664ull,0x202f2f09203b3735ull,
0x6168732e7473090aull,0x203436662e646572ull,0x2b30326472255b09ull,0x35646625202c5d30ull,
0x6469202f2f093b37ull,0x635f5f203839323aull,0x75535f735f616475ull,0x38396c6c6143326dull,
0x0a3078302b343433ull,0x373109636f6c2e09ull,0x6c090a3009363609ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c343664ull,0x3b5d36312b393164ull,0x323a6469202f2f09ull,
0x6475635f5f203939ull,0x436d75535f735f61ull,0x39333030316c6c61ull,0x61090a3078302b32ull,
0x09203436662e6464ull,0x25202c3435646625ull,0x6625202c34366466ull,0x2f2f09203b343564ull,
0x68732e7473090a20ull,0x3436662e64657261ull,0x39316472255b0920ull,0x646625202c5d302bull,
0x69202f2f093b3435ull,0x5f5f203030333a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,
0x3078302b32393330ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c353664662509ull,
0x312b30326472255bull,0x69202f2f093b5d36ull,0x5f5f203130333a64ull,0x535f735f61647563ull,
0x396c6c6143326d75ull,0x3078302b34343338ull,0x36662e646461090aull,0x3735646625092034ull,
0x2c3536646625202cull,0x203b373564662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920343666ull,0x202c5d302b303264ull,0x2f093b3735646625ull,0x3230333a6469202full,
0x5f616475635f5f20ull,0x6143326d75535f73ull,0x2b34343338396c6cull,0x6f6c2e090a307830ull,
0x0937360937310963ull,0x68732e646c090a30ull,0x3436662e64657261ull,0x2c36366466250920ull,
0x2b39316472255b20ull,0x69202f2f093b5d38ull,0x5f5f203330333a64ull,0x535f735f61647563ull,
0x30316c6c61436d75ull,0x3078302b32393330ull,0x36662e646461090aull,0x3736646625092034ull,
0x2c3636646625202cull,0x203b343564662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920343666ull,0x202c5d302b393164ull,0x2f093b3736646625ull,0x3430333a6469202full,
0x5f616475635f5f20ull,0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e646c090a307830ull,
0x662e646572616873ull,0x3664662509203436ull,0x326472255b202c38ull,0x2f2f093b5d382b30ull,
0x203530333a646920ull,0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,
0x2e646461090a3078ull,0x6466250920343666ull,0x36646625202c3936ull,0x3735646625202c38ull,
0x090a202f2f09203bull,0x65726168732e7473ull,0x5b09203436662e64ull,0x5d302b3032647225ull,
0x3b3936646625202cull,0x333a6469202f2f09ull,0x6475635f5f203630ull,0x326d75535f735f61ull,
0x343338396c6c6143ull,0x4c240a3078302b34ull,0x0a3a30395f315f74ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x616568202c333820ull,
0x656c6562616c2064ull,0x5f315f744c242064ull,0x636f6c2e090a3538ull,0x3009353809373109ull,
0x33732e646461090aull,0x2c33327225092032ull,0x32202c3332722520ull,0x20202020203b3635ull,
0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x353532202c353372ull,0x202020202020203bull,
0x202f2f0920202020ull,0x6c2e70746573090aull,0x2509203233732e65ull,0x327225202c313170ull,
0x3b35337225202c33ull,0x2540090a202f2f09ull,0x2061726220313170ull,0x385f315f744c2409ull,
0x2020202020203b35ull,0x202f2f0920202020ull,0x385f315f744c240aull,0x636f6c2e090a3a33ull,
0x3009383731093309ull,0x33752e766f6d090aull,0x2c36337225092032ull,0x20202020203b3020ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33752e656e2e7074ull,0x2c32317025092032ull,
0x7225202c31722520ull,0x202f2f09203b3633ull,0x203231702540090aull,0x744c240920617262ull,
0x20203b33395f315full,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x313831093309636full,
0x2e766f6d090a3009ull,0x6472250920343675ull,0x61435f64202c3332ull,0x3b65756c61566c6cull,
0x090a202f2f092020ull,0x2e3233732e747663ull,0x3372250920363175ull,0x6961746325202c37ull,
0x2f0920203b782e64ull,0x2e747663090a202full,0x203233732e343673ull,0x202c343264722509ull,
0x2020203b37337225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,
0x3432647225202c35ull,0x2f09203b3631202cull,0x2e646461090a202full,0x6472250920343675ull,
0x32647225202c3632ull,0x3532647225202c33ull,0x090a202f2f09203bull,0x65726168732e646cull,
0x2509203436662e64ull,0x5f5b202c30376466ull,0x5f735f616475635full,0x316c6c61436d7553ull,
0x5d302b3239333030ull,0x3a6469202f2f093bull,0x75635f5f20373033ull,0x6d75535f735f6164ull,
0x333030316c6c6143ull,0x090a3078302b3239ull,0x61626f6c672e7473ull,0x5b09203436662e6cull,
0x5d302b3632647225ull,0x3b3037646625202cull,0x333a6469202f2f09ull,0x6c61435f64203830ull,
0x302b65756c61566cull,0x732e646c090a3078ull,0x36662e6465726168ull,0x3137646625092034ull,
0x6475635f5f5b202cull,0x326d75535f735f61ull,0x343338396c6c6143ull,0x2f2f093b5d302b34ull,
0x203930333a646920ull,0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,
0x672e7473090a3078ull,0x36662e6c61626f6cull,0x326472255b092034ull,0x6625202c5d382b36ull,
0x202f2f093b313764ull,0x64203031333a6469ull,0x6c61566c6c61435full,0x240a3078302b6575ull,
0x3a33395f315f744cull,0x3309636f6c2e090aull,0x090a300933383109ull,0x2020203b74697865ull,
0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,0x6557444c240a202full,
0x4d37325a5f5f646eull,0x6c72614365746e6full,0x636f6c42656e4f6full,0x6974704f7265506bull,
0x090a3a6966506e6full,0x325a5f202f2f207dull,0x614365746e6f4d37ull,0x6c42656e4f6f6c72ull,
0x704f7265506b636full,0x0a6966506e6f6974ull,0x7972746e652e090aull,0x6e6f4d36315a5f20ull,
0x526f6c7261436574ull,0x3431506563756465ull,0x6f6974704f545f5full,0x0a6965756c61566eull,
0x6765722e090a7b09ull,0x7225203233752e20ull,0x2e090a3b3e34333cull,0x3436752e20676572ull,
0x3e37323c64722520ull,0x206765722e090a3bull,0x646625203436662eull,0x2e090a3b3e38333cull,
0x6572702e20676572ull,0x3e31313c70252064ull,0x617261702e090a3bull,0x5f203436752e206dull,
0x726170616475635full,0x6f4d36315a5f5f6dull,0x6f6c72614365746eull,0x3150656375646552ull,
0x6974704f545f5f34ull,0x6965756c61566e6full,0x65666675425f645full,0x7261702e090a3b72ull,
0x203233732e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6c72614365746e6full,
0x506563756465526full,0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x4e6d756363615f69ull,
0x726168732e090a3bull,0x67696c612e206465ull,0x2038622e2038206eull,0x735f616475635f5full,
0x6c6143326d75535full,0x5b3635343230316cull,0x090a3b5d38343032ull,0x206465726168732eull,
0x38206e67696c612eull,0x635f5f2038622e20ull,0x75535f735f616475ull,0x3430316c6c61436dull,
0x383430325b343035ull,0x636f6c2e090a3b5dull,0x3009333931093309ull,0x5f5f3142424c240aull,
0x65746e6f4d36315aull,0x6465526f6c726143ull,0x5f5f343150656375ull,0x566e6f6974704f54ull,
0x090a3a6965756c61ull,0x32093309636f6c2eull,0x7663090a30093230ull,0x31752e3233732e74ull,
0x202c317225092036ull,0x203b782e64697425ull,0x202f2f0920202020ull,0x33732e766f6d090aull,
0x202c327225092032ull,0x202020203b317225ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x3b353532202c3372ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x6c2e70746573090aull,0x2509203233732e65ull,0x2c317225202c3170ull,0x2020203b33722520ull,
0x2140090a202f2f09ull,0x2061726220317025ull,0x355f325f744c2409ull,0x2020202020203b36ull,
0x202f2f0920202020ull,0x36752e766f6d090aull,0x2c31647225092034ull,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x3635343230316c6cull,0x6d090a202f2f093bull,0x09203436752e766full,
0x5f5f202c32647225ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x2f2f093b34303534ull,
0x61702e646c090a20ull,0x203233752e6d6172ull,0x5f5b202c34722509ull,0x726170616475635full,
0x6f4d36315a5f5f6dull,0x6f6c72614365746eull,0x3150656375646552ull,0x6974704f545f5f34ull,
0x6965756c61566e6full,0x5d4e6d756363615full,0x3a6469202f2f093bull,0x75635f5f20313631ull,
0x5f5f6d7261706164ull,0x65746e6f4d36315aull,0x6465526f6c726143ull,0x5f5f343150656375ull,
0x566e6f6974704f54ull,0x63615f6965756c61ull,0x3078302b4e6d7563ull,0x7261702e646c090aull,
0x09203436752e6d61ull,0x5f5b202c33647225ull,0x726170616475635full,0x6f4d36315a5f5f6dull,
0x6f6c72614365746eull,0x3150656375646552ull,0x6974704f545f5f34ull,0x6965756c61566e6full,
0x65666675425f645full,0x69202f2f093b5d72ull,0x5f5f203336313a64ull,0x6d72617061647563ull,
0x6e6f4d36315a5f5full,0x526f6c7261436574ull,0x3431506563756465ull,0x6f6974704f545f5full,
0x5f6965756c61566eull,0x7265666675425f64ull,0x7663090a3078302bull,0x31752e3233752e74ull,
0x202c357225092036ull,0x782e646961746325ull,0x202f2f092020203bull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x202c357225202c36ull,0x202020203b347225ull,0x7663090a202f2f09ull,
0x33752e3436752e74ull,0x2c34647225092032ull,0x2020203b36722520ull,0x202f2f0920202020ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x34647225202c3564ull,0x2020203b3631202cull,
0x6461090a202f2f09ull,0x2509203436752e64ull,0x647225202c366472ull,0x3b35647225202c33ull,
0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233732e34ull,0x317225202c376472ull,
0x202020202020203bull,0x6f6d090a202f2f09ull,0x2509203436732e76ull,0x647225202c386472ull,
0x2020202020203b37ull,0x202f2f0920202020ull,0x33752e747663090aull,0x2509203631752e32ull,
0x69746e25202c3772ull,0x202020203b782e64ull,0x7663090a202f2f09ull,0x33752e3436732e74ull,
0x2c39647225092032ull,0x2020203b37722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c303164ull,0x2020203b38202c37ull,0x756d090a202f2f09ull,
0x3436752e6f6c2e6cull,0x2c31316472250920ull,0x38202c3964722520ull,0x202f2f092020203bull,
0x36752e646461090aull,0x3231647225092034ull,0x2c3031647225202cull,0x20203b3264722520ull,
0x6461090a202f2f09ull,0x2509203436752e64ull,0x7225202c33316472ull,0x647225202c303164ull,
0x202f2f0920203b31ull,0x355f325f744c240aull,0x6c3c2f2f200a3a38ull,0x6f6f4c203e706f6full,
0x6c2079646f622070ull,0x2c32303220656e69ull,0x676e697473656e20ull,0x203a687470656420ull,
0x6d69747365202c31ull,0x6574692064657461ull,0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,
0x3309636f6c2e090aull,0x090a300934303209ull,0x203233732e766f6dull,0x7225202c38722509ull,
0x2020202020203b32ull,0x2f09202020202020ull,0x70746573090a202full,0x203233732e65672eull,
0x7225202c32702509ull,0x203b347225202c32ull,0x090a202f2f092020ull,0x203436662e766f6dull,
0x30202c3164662509ull,0x3030303030303064ull,0x3030303030303030ull,0x0a30202f2f093b30ull,
0x3436662e766f6d09ull,0x202c326466250920ull,0x3030303030306430ull,0x3030303030303030ull,
0x30202f2f093b3030ull,0x622032702540090aull,0x5f744c2409206172ull,0x2020203b37375f32ull,
0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x303220656e696c20ull,0x2064616568202c32ull,0x2064656c6562616cull,
0x38355f325f744c24ull,0x33732e627573090aull,0x202c397225092032ull,0x327225202c347225ull,
0x202020202020203bull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x397225202c303172ull,
0x20203b353532202cull,0x202f2f0920202020ull,0x33732e726873090aull,0x2c31317225092032ull,
0x33202c3031722520ull,0x2020202020203b31ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,
0x353532202c323172ull,0x202020202020203bull,0x202f2f0920202020ull,0x33622e646e61090aull,
0x2c33317225092032ull,0x25202c3131722520ull,0x202020203b323172ull,0x6461090a202f2f09ull,
0x2509203233732e64ull,0x317225202c343172ull,0x3b30317225202c33ull,0x202f2f0920202020ull,
0x33732e726873090aull,0x2c35317225092032ull,0x38202c3431722520ull,0x202020202020203bull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c34316472250920ull,0x31202c3864722520ull,
0x202f2f0920203b36ull,0x36732e646461090aull,0x3531647225092034ull,0x202c36647225202cull,
0x20203b3431647225ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x303220656e696c20ull,0x2064616568202c32ull,0x2064656c6562616cull,
0x38355f325f744c24ull,0x33732e766f6d090aull,0x2c36317225092032ull,0x20203b3531722520ull,
0x2020202020202020ull,0x744c240a202f2f09ull,0x200a3a31365f325full,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c343032ull,0x70656420676e6974ull,
0x65202c32203a6874ull,0x646574616d697473ull,0x6974617265746920ull,0x6b6e75203a736e6full,
0x6c2e090a6e776f6eull,0x363032093309636full,0x672e646c090a3009ull,0x36662e6c61626f6cull,
0x2c33646625092034ull,0x2b35316472255b20ull,0x69202f2f093b5d30ull,0x61090a3536313a64ull,
0x09203436662e6464ull,0x6625202c32646625ull,0x32646625202c3364ull,0x2f2f09202020203bull,
0x09636f6c2e090a20ull,0x0a30093730320933ull,0x626f6c672e646c09ull,0x09203436662e6c61ull,
0x255b202c34646625ull,0x3b5d382b35316472ull,0x313a6469202f2f09ull,0x2e646461090a3636ull,
0x6466250920343666ull,0x2c34646625202c31ull,0x20203b3164662520ull,0x090a202f2f092020ull,
0x203233732e646461ull,0x7225202c38722509ull,0x203b363532202c38ull,0x2f09202020202020ull,
0x2e646461090a202full,0x6472250920343673ull,0x31647225202c3531ull,0x3b36393034202c35ull,
0x090a202f2f092020ull,0x2e746c2e70746573ull,0x3370250920323373ull,0x25202c387225202cull,
0x2f092020203b3472ull,0x33702540090a202full,0x4c24092061726220ull,0x203b31365f325f74ull,
0x2020202020202020ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323032ull,0x656c6562616c2064ull,
0x5f325f744c242064ull,0x2e617262090a3835ull,0x744c240920696e75ull,0x20203b39355f325full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3a37375f325f744cull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3230322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x744c240a38355f32ull,0x200a3a39355f325full,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c323032ull,0x656c6562616c2064ull,0x5f325f744c242064ull,0x636f6c2e090a3835ull,
0x3009393032093309ull,0x6168732e7473090aull,0x203436662e646572ull,0x2b32316472255b09ull,
0x32646625202c5d30ull,0x3a6469202f2f093bull,0x75635f5f20373631ull,0x6d75535f735f6164ull,
0x353430316c6c6143ull,0x090a3078302b3430ull,0x32093309636f6c2eull,0x7473090a30093031ull,
0x2e6465726168732eull,0x72255b0920343666ull,0x202c5d302b333164ull,0x2f2f093b31646625ull,
0x203836313a646920ull,0x735f616475635f5full,0x6c6143326d75535full,0x2b3635343230316cull,
0x646461090a307830ull,0x722509203233752eull,0x202c327225202c32ull,0x202020203b377225ull,
0x0a202f2f09202020ull,0x3436752e64646109ull,0x202c386472250920ull,0x7225202c39647225ull,
0x09202020203b3864ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c333164ull,
0x31647225202c3131ull,0x0a202f2f09203b33ull,0x3436752e64646109ull,0x2c32316472250920ull,
0x202c313164722520ull,0x09203b3231647225ull,0x766f6d090a202f2full,0x722509203233752eull,
0x3b353532202c3731ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,
0x702509203233732eull,0x202c327225202c34ull,0x0920203b37317225ull,0x702540090a202f2full,
0x2409206172622034ull,0x3b38355f325f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x36355f325f744c24ull,0x09636f6c2e090a3aull,0x0a30093531320933ull,0x3436752e766f6d09ull,
0x202c316472250920ull,0x735f616475635f5full,0x6c6143326d75535full,0x3b3635343230316cull,
0x6f6d090a202f2f09ull,0x2509203436752e76ull,0x635f5f202c326472ull,0x75535f735f616475ull,
0x3430316c6c61436dull,0x202f2f093b343035ull,0x3109636f6c2e090aull,0x090a300933380937ull,
0x203233732e766f6dull,0x25202c3831722509ull,0x20202020203b3172ull,0x2f09202020202020ull,
0x70252140090a202full,0x2409206172622031ull,0x3b34365f325f744cull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x35202c3931722509ull,0x20202020203b3131ull,
0x2f09202020202020ull,0x2e627573090a202full,0x3272250920323373ull,0x2c39317225202c30ull,
0x2020203b31722520ull,0x090a202f2f092020ull,0x203233732e726873ull,0x25202c3132722509ull,
0x3b3133202c303272ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3272250920323373ull,
0x203b353532202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233622e646e61ull,
0x25202c3332722509ull,0x327225202c313272ull,0x2f09202020203b32ull,0x2e646461090a202full,
0x3272250920323373ull,0x2c33327225202c34ull,0x20203b3032722520ull,0x090a202f2f092020ull,
0x203233732e726873ull,0x25202c3532722509ull,0x203b38202c343272ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3272250920323373ull,0x3b35327225202c36ull,0x2020202020202020ull,
0x240a202f2f092020ull,0x3a36365f325f744cull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x656e202c33382065ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,
0x3809373109636f6cull,0x726162090a300934ull,0x300920636e79732eull,0x202020202020203bull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x373109636f6c2e09ull,0x6d090a3009353809ull,
0x09203233752e766full,0x3231202c37327225ull,0x2020202020203b37ull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e7467ull,0x317225202c357025ull,0x3b37327225202c38ull,
0x40090a202f2f0920ull,0x2061726220357025ull,0x365f325f744c2409ull,0x2020202020203b37ull,
0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x68202c333820656eull,0x6562616c20646165ull,0x5f744c242064656cull,
0x6c2e090a36365f32ull,0x353509373109636full,0x2e747663090a3009ull,0x203233732e343675ull,
0x202c363164722509ull,0x2020203b38317225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x3631647225202c37ull,0x2f0920203b38202cull,0x2e646461090a202full,
0x6472250920343675ull,0x31647225202c3831ull,0x3b32647225202c37ull,0x090a202f2f092020ull,
0x65726168732e646cull,0x2509203436662e64ull,0x72255b202c356466ull,0x093b5d302b383164ull,
0x36313a6469202f2full,0x616475635f5f2039ull,0x61436d75535f735full,0x3430353430316c6cull,
0x646c090a3078302bull,0x2e6465726168732eull,0x6466250920343666ull,0x316472255b202c36ull,
0x3b5d343230312b38ull,0x313a6469202f2f09ull,0x6475635f5f203037ull,0x436d75535f735f61ull,
0x30353430316c6c61ull,0x61090a3078302b34ull,0x09203436662e6464ull,0x6625202c37646625ull,
0x36646625202c3564ull,0x2f2f09202020203bull,0x68732e7473090a20ull,0x3436662e64657261ull,
0x38316472255b0920ull,0x646625202c5d302bull,0x6469202f2f093b37ull,0x635f5f203137313aull,
0x75535f735f616475ull,0x3430316c6c61436dull,0x0a3078302b343035ull,0x3436752e64646109ull,
0x2c39316472250920ull,0x202c373164722520ull,0x0920203b31647225ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3864662509203436ull,0x39316472255b202cull,0x202f2f093b5d302bull,
0x5f203237313a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,0x302b363534323031ull,
0x732e646c090a3078ull,0x36662e6465726168ull,0x2c39646625092034ull,0x2b39316472255b20ull,
0x2f093b5d34323031ull,0x3337313a6469202full,0x5f616475635f5f20ull,0x6143326d75535f73ull,
0x3635343230316c6cull,0x6461090a3078302bull,0x2509203436662e64ull,0x6625202c30316466ull,
0x39646625202c3864ull,0x202f2f092020203bull,0x6168732e7473090aull,0x203436662e646572ull,
0x2b39316472255b09ull,0x31646625202c5d30ull,0x6469202f2f093b30ull,0x635f5f203437313aull,
0x75535f735f616475ull,0x30316c6c6143326dull,0x3078302b36353432ull,0x365f325f744c240aull,
0x6c3c2f2f200a3a37ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x202c333820656e69ull,0x62616c2064616568ull,0x744c242064656c65ull,0x62090a36365f325full,
0x20636e79732e7261ull,0x20202020203b3009ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x752e766f6d090a20ull,0x3832722509203233ull,0x2020203b3336202cull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e74672e707465ull,0x2c36702509203233ull,0x25202c3831722520ull,
0x2f2f09203b383272ull,0x2036702540090a20ull,0x744c240920617262ull,0x20203b39365f325full,
0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3820656e696c2079ull,0x2064616568202c33ull,0x2064656c6562616cull,
0x36365f325f744c24ull,0x3109636f6c2e090aull,0x090a300936350937ull,0x2e3436752e747663ull,
0x6472250920323373ull,0x38317225202c3032ull,0x2f0920202020203bull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x25202c3731647225ull,0x3b38202c30326472ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x202c383164722509ull,0x25202c3731647225ull,0x2f0920203b326472ull,
0x732e646c090a202full,0x36662e6465726168ull,0x3131646625092034ull,0x38316472255b202cull,
0x202f2f093b5d302bull,0x5f203537313a6469ull,0x5f735f616475635full,0x316c6c61436d7553ull,
0x78302b3430353430ull,0x68732e646c090a30ull,0x3436662e64657261ull,0x2c32316466250920ull,
0x2b38316472255b20ull,0x2f2f093b5d323135ull,0x203637313a646920ull,0x735f616475635f5full,
0x6c6c61436d75535full,0x302b343035343031ull,0x2e646461090a3078ull,0x6466250920343666ull,
0x31646625202c3331ull,0x3231646625202c31ull,0x090a202f2f09203bull,0x65726168732e7473ull,
0x5b09203436662e64ull,0x5d302b3831647225ull,0x3b3331646625202cull,0x313a6469202f2f09ull,
0x6475635f5f203737ull,0x436d75535f735f61ull,0x30353430316c6c61ull,0x61090a3078302b34ull,
0x09203436752e6464ull,0x25202c3931647225ull,0x7225202c37316472ull,0x2f2f0920203b3164ull,
0x68732e646c090a20ull,0x3436662e64657261ull,0x2c34316466250920ull,0x2b39316472255b20ull,
0x69202f2f093b5d30ull,0x5f5f203837313a64ull,0x535f735f61647563ull,0x316c6c6143326d75ull,
0x78302b3635343230ull,0x68732e646c090a30ull,0x3436662e64657261ull,0x2c35316466250920ull,
0x2b39316472255b20ull,0x2f2f093b5d323135ull,0x203937313a646920ull,0x735f616475635f5full,
0x6c6143326d75535full,0x2b3635343230316cull,0x646461090a307830ull,0x662509203436662eull,
0x646625202c363164ull,0x31646625202c3431ull,0x0a202f2f09203b35ull,0x726168732e747309ull,
0x09203436662e6465ull,0x302b39316472255bull,0x3631646625202c5dull,0x3a6469202f2f093bull,
0x75635f5f20303831ull,0x6d75535f735f6164ull,0x3230316c6c614332ull,0x0a3078302b363534ull,
0x39365f325f744c24ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x68202c333820656eull,0x6562616c20646165ull,0x5f744c242064656cull,
0x6162090a36365f32ull,0x0920636e79732e72ull,0x2020202020203b30ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c39327225092032ull,0x202020203b313320ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e74672e7074ull,0x202c377025092032ull,
0x7225202c38317225ull,0x202f2f09203b3932ull,0x622037702540090aull,0x5f744c2409206172ull,
0x2020203b31375f32ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x333820656e696c20ull,0x6c2064616568202cull,
0x242064656c656261ull,0x0a36365f325f744cull,0x373109636f6c2e09ull,0x63090a3009323609ull,
0x732e3436752e7476ull,0x3264722509203233ull,0x3b38317225202c31ull,0x2f2f092020202020ull,
0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c37316472ull,0x203b38202c313264ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3831647225ull,0x7225202c37316472ull,
0x2f2f0920203b3264ull,0x68732e646c090a20ull,0x3436662e64657261ull,0x2c37316466250920ull,
0x2b38316472255b20ull,0x69202f2f093b5d30ull,0x5f5f203138313a64ull,0x535f735f61647563ull,
0x30316c6c61436d75ull,0x3078302b34303534ull,0x6168732e646c090aull,0x203436662e646572ull,
0x202c383164662509ull,0x322b38316472255bull,0x202f2f093b5d3635ull,0x5f203238313a6469ull,
0x5f735f616475635full,0x316c6c61436d7553ull,0x78302b3430353430ull,0x662e646461090a30ull,
0x3164662509203436ull,0x3731646625202c39ull,0x3b3831646625202cull,0x73090a202f2f0920ull,
0x6465726168732e74ull,0x255b09203436662eull,0x2c5d302b38316472ull,0x093b393164662520ull,
0x38313a6469202f2full,0x616475635f5f2033ull,0x61436d75535f735full,0x3430353430316c6cull,
0x6461090a3078302bull,0x2509203436752e64ull,0x7225202c39316472ull,0x647225202c373164ull,
0x202f2f0920203b31ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c303264662509ull,
0x302b39316472255bull,0x6469202f2f093b5dull,0x635f5f203438313aull,0x75535f735f616475ull,
0x30316c6c6143326dull,0x3078302b36353432ull,0x6168732e646c090aull,0x203436662e646572ull,
0x202c313264662509ull,0x322b39316472255bull,0x202f2f093b5d3635ull,0x5f203538313a6469ull,
0x5f735f616475635full,0x6c6c6143326d7553ull,0x302b363534323031ull,0x2e646461090a3078ull,
0x6466250920343666ull,0x32646625202c3232ull,0x3132646625202c30ull,0x090a202f2f09203bull,
0x65726168732e7473ull,0x5b09203436662e64ull,0x5d302b3931647225ull,0x3b3232646625202cull,
0x313a6469202f2f09ull,0x6475635f5f203638ull,0x326d75535f735f61ull,0x343230316c6c6143ull,
0x090a3078302b3635ull,0x09373109636f6c2eull,0x646c090a30093336ull,0x2e6465726168732eull,
0x6466250920343666ull,0x6472255b202c3332ull,0x3b5d3832312b3831ull,0x313a6469202f2f09ull,
0x6475635f5f203738ull,0x436d75535f735f61ull,0x30353430316c6c61ull,0x61090a3078302b34ull,
0x09203436662e6464ull,0x25202c3931646625ull,0x6625202c33326466ull,0x2f2f09203b393164ull,
0x68732e7473090a20ull,0x3436662e64657261ull,0x38316472255b0920ull,0x646625202c5d302bull,
0x69202f2f093b3931ull,0x5f5f203838313a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,
0x3078302b34303534ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c343264662509ull,
0x312b39316472255bull,0x202f2f093b5d3832ull,0x5f203938313a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x302b363534323031ull,0x2e646461090a3078ull,0x6466250920343666ull,
0x32646625202c3232ull,0x3232646625202c34ull,0x090a202f2f09203bull,0x65726168732e7473ull,
0x5b09203436662e64ull,0x5d302b3931647225ull,0x3b3232646625202cull,0x313a6469202f2f09ull,
0x6475635f5f203039ull,0x326d75535f735f61ull,0x343230316c6c6143ull,0x090a3078302b3635ull,
0x09373109636f6c2eull,0x646c090a30093436ull,0x2e6465726168732eull,0x6466250920343666ull,
0x6472255b202c3532ull,0x093b5d34362b3831ull,0x39313a6469202f2full,0x616475635f5f2031ull,
0x61436d75535f735full,0x3430353430316c6cull,0x6461090a3078302bull,0x2509203436662e64ull,
0x6625202c39316466ull,0x646625202c353264ull,0x202f2f09203b3931ull,0x6168732e7473090aull,
0x203436662e646572ull,0x2b38316472255b09ull,0x31646625202c5d30ull,0x6469202f2f093b39ull,
0x635f5f203239313aull,0x75535f735f616475ull,0x3430316c6c61436dull,0x0a3078302b343035ull,
0x726168732e646c09ull,0x09203436662e6465ull,0x5b202c3632646625ull,0x34362b3931647225ull,
0x6469202f2f093b5dull,0x635f5f203339313aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x36662e646461090aull,0x3232646625092034ull,0x2c3632646625202cull,
0x203b323264662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,
0x202c5d302b393164ull,0x2f093b3232646625ull,0x3439313a6469202full,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x3635343230316c6cull,0x6c2e090a3078302bull,0x353609373109636full,
0x732e646c090a3009ull,0x36662e6465726168ull,0x3732646625092034ull,0x38316472255b202cull,
0x2f2f093b5d32332bull,0x203539313a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,
0x302b343035343031ull,0x2e646461090a3078ull,0x6466250920343666ull,0x32646625202c3931ull,
0x3931646625202c37ull,0x090a202f2f09203bull,0x65726168732e7473ull,0x5b09203436662e64ull,
0x5d302b3831647225ull,0x3b3931646625202cull,0x313a6469202f2f09ull,0x6475635f5f203639ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x6c090a3078302b34ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c383264ull,0x3b5d32332b393164ull,0x313a6469202f2f09ull,
0x6475635f5f203739ull,0x326d75535f735f61ull,0x343230316c6c6143ull,0x090a3078302b3635ull,
0x203436662e646461ull,0x202c323264662509ull,0x25202c3832646625ull,0x2f09203b32326466ull,
0x732e7473090a202full,0x36662e6465726168ull,0x316472255b092034ull,0x6625202c5d302b39ull,
0x202f2f093b323264ull,0x5f203839313a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,
0x302b363534323031ull,0x636f6c2e090a3078ull,0x3009363609373109ull,0x6168732e646c090aull,
0x203436662e646572ull,0x202c393264662509ull,0x312b38316472255bull,0x69202f2f093b5d36ull,
0x5f5f203939313a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b34303534ull,
0x36662e646461090aull,0x3931646625092034ull,0x2c3932646625202cull,0x203b393164662520ull,
0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,0x202c5d302b383164ull,
0x2f093b3931646625ull,0x3030323a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3430353430316cull,0x2e646c090a307830ull,0x662e646572616873ull,0x3364662509203436ull,
0x316472255b202c30ull,0x2f093b5d36312b39ull,0x3130323a6469202full,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x3635343230316c6cull,0x6461090a3078302bull,0x2509203436662e64ull,
0x6625202c32326466ull,0x646625202c303364ull,0x202f2f09203b3232ull,0x6168732e7473090aull,
0x203436662e646572ull,0x2b39316472255b09ull,0x32646625202c5d30ull,0x6469202f2f093b32ull,
0x635f5f203230323aull,0x75535f735f616475ull,0x30316c6c6143326dull,0x3078302b36353432ull,
0x3109636f6c2e090aull,0x090a300937360937ull,0x65726168732e646cull,0x2509203436662e64ull,
0x255b202c31336466ull,0x3b5d382b38316472ull,0x323a6469202f2f09ull,0x6475635f5f203330ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x61090a3078302b34ull,0x09203436662e6464ull,
0x25202c3233646625ull,0x6625202c31336466ull,0x2f2f09203b393164ull,0x68732e7473090a20ull,
0x3436662e64657261ull,0x38316472255b0920ull,0x646625202c5d302bull,0x69202f2f093b3233ull,
0x5f5f203430323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b34303534ull,
0x6168732e646c090aull,0x203436662e646572ull,0x202c333364662509ull,0x382b39316472255bull,
0x6469202f2f093b5dull,0x635f5f203530323aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x36662e646461090aull,0x3433646625092034ull,0x2c3333646625202cull,
0x203b323264662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,
0x202c5d302b393164ull,0x2f093b3433646625ull,0x3630323a6469202full,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x3635343230316c6cull,0x744c240a3078302bull,0x200a3a31375f325full,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x64616568202c3338ull,0x64656c6562616c20ull,0x365f325f744c2420ull,0x09636f6c2e090a36ull,
0x0a30093538093731ull,0x3233732e64646109ull,0x202c383172250920ull,0x3532202c38317225ull,
0x0920202020203b36ull,0x766f6d090a202f2full,0x722509203233752eull,0x3b353532202c3033ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,0x702509203233732eull,
0x2c38317225202c38ull,0x09203b3033722520ull,0x702540090a202f2full,0x2409206172622038ull,
0x3b36365f325f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,0x34365f325f744c24ull,
0x09636f6c2e090a3aull,0x0a30093531320933ull,0x3233752e766f6d09ull,0x202c313372250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x746573090a202f2full,0x3233752e656e2e70ull,
0x25202c3970250920ull,0x31337225202c3172ull,0x0a202f2f0920203bull,0x7262203970254009ull,
0x325f744c24092061ull,0x202020203b34375full,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x0938313209330963ull,0x752e766f6d090a30ull,0x3264722509203436ull,0x6c61435f64202c32ull,
0x203b65756c61566cull,0x63090a202f2f0920ull,0x752e3233752e7476ull,0x3233722509203631ull,
0x646961746325202cull,0x2f2f0920203b782eull,0x752e747663090a20ull,0x09203233752e3436ull,
0x25202c3332647225ull,0x202020203b323372ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x3432647225092034ull,0x2c3332647225202cull,0x2f2f09203b363120ull,0x752e646461090a20ull,
0x3264722509203436ull,0x3232647225202c35ull,0x3b3432647225202cull,0x6c090a202f2f0920ull,
0x6465726168732e64ull,0x662509203436662eull,0x5f5f5b202c353364ull,0x535f735f61647563ull,
0x30316c6c61436d75ull,0x3b5d302b34303534ull,0x323a6469202f2f09ull,0x6475635f5f203730ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x73090a3078302b34ull,0x6c61626f6c672e74ull,
0x255b09203436662eull,0x2c5d302b35326472ull,0x093b353364662520ull,0x30323a6469202f2full,
0x6c6c61435f642038ull,0x78302b65756c6156ull,0x68732e646c090a30ull,0x3436662e64657261ull,
0x2c36336466250920ull,0x616475635f5f5b20ull,0x43326d75535f735full,0x35343230316c6c61ull,
0x2f2f093b5d302b36ull,0x203930323a646920ull,0x735f616475635f5full,0x6c6143326d75535full,
0x2b3635343230316cull,0x2e7473090a307830ull,0x662e6c61626f6c67ull,0x6472255b09203436ull,
0x25202c5d382b3532ull,0x2f2f093b36336466ull,0x203031323a646920ull,0x61566c6c61435f64ull,
0x0a3078302b65756cull,0x34375f325f744c24ull,0x09636f6c2e090a3aull,0x0a30093032320933ull,
0x20203b7469786509ull,0x2020202020202020ull,0x2020202020202020ull,0x0920202020202020ull,
0x57444c240a202f2full,0x36315a5f5f646e65ull,0x72614365746e6f4dull,0x6563756465526f6cull,
0x704f545f5f343150ull,0x756c61566e6f6974ull,0x2f207d090a3a6965ull,0x6f4d36315a5f202full,
0x6f6c72614365746eull,0x3150656375646552ull,0x6974704f545f5f34ull,0x6965756c61566e6full,
0x72746e652e090a0aull,0x6e6936315a5f2079ull,0x444e436573726576ull,0x66506c656e72654bull,
0x090a7b090a6a5f53ull,0x33752e206765722eull,0x3638313c72252032ull,0x6765722e090a3b3eull,
0x7225203436752e20ull,0x090a3b3e37313c64ull,0x33662e206765722eull,0x3b3e353c66252032ull,
0x2e206765722e090aull,0x3c64662520343666ull,0x2e090a3b3e313134ull,0x6572702e20676572ull,
0x3e33363c70252064ull,0x617261702e090a3bull,0x5f203436752e206dull,0x726170616475635full,
0x6e6936315a5f5f6dull,0x444e436573726576ull,0x66506c656e72654bull,0x754f5f645f6a5f53ull,
0x2e090a3b74757074ull,0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,
0x737265766e693631ull,0x6e72654b444e4365ull,0x5f6a5f5366506c65ull,0x3b7475706e495f64ull,
0x6d617261702e090aull,0x5f5f203233752e20ull,0x6d72617061647563ull,0x766e6936315a5f5full,
0x4b444e4365737265ull,0x5366506c656e7265ull,0x4e687461705f6a5full,0x09636f6c2e090a3bull,
0x3009313532093831ull,0x5f5f3142424c240aull,0x7265766e6936315aull,0x72654b444e436573ull,
0x6a5f5366506c656eull,0x61702e646c090a3aull,0x203233752e6d6172ull,0x5f5b202c31722509ull,
0x726170616475635full,0x6e6936315a5f5f6dull,0x444e436573726576ull,0x66506c656e72654bull,
0x687461705f6a5f53ull,0x69202f2f093b5d4eull,0x5f20373731313a64ull,0x726170616475635full,
0x6e6936315a5f5f6dull,0x444e436573726576ull,0x66506c656e72654bull,0x687461705f6a5f53ull,
0x63090a3078302b4eull,0x752e3233752e7476ull,0x2c32722509203631ull,0x3b782e6469742520ull,
0x2f2f092020202020ull,0x752e747663090a20ull,0x09203631752e3233ull,0x746325202c337225ull,
0x20203b782e646961ull,0x63090a202f2f0920ull,0x752e3233752e7476ull,0x2c34722509203631ull,
0x782e6469746e2520ull,0x2f2f09202020203bull,0x61702e646c090a20ull,0x203436752e6d6172ull,
0x5b202c3164722509ull,0x6170616475635f5full,0x6936315a5f5f6d72ull,0x4e4365737265766eull,
0x506c656e72654b44ull,0x495f645f6a5f5366ull,0x2f093b5d7475706eull,0x3831313a6469202full,
0x616475635f5f2031ull,0x315a5f5f6d726170ull,0x65737265766e6936ull,0x656e72654b444e43ull,
0x645f6a5f5366506cull,0x302b7475706e495full,0x2e766f6d090a3078ull,0x6472250920343675ull,
0x2020203b30202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e71652e70746573ull,
0x3170250920343675ull,0x202c31647225202cull,0x2f09203b32647225ull,0x31702540090a202full,
0x4c24092061726220ull,0x3b3330325f335f74ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09383109636f6c2eull,0x6d090a3009393532ull,0x2e6f6c2e34326c75ull,0x3572250920323375ull,
0x25202c347225202cull,0x2f2f0920203b3372ull,0x752e646461090a20ull,0x2c36722509203233ull,
0x7225202c35722520ull,0x2020202020203b32ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x367225202c377225ull,0x202020202020203bull,0x2f2f092020202020ull,0x2e70746573090a20ull,
0x09203233752e6567ull,0x367225202c327025ull,0x20203b317225202cull,0x40090a202f2f0920ull,
0x2061726220327025ull,0x325f335f744c2409ull,0x20202020203b3236ull,0x2f2f092020202020ull,
0x752e747663090a20ull,0x09203631752e3233ull,0x636e25202c387225ull,0x203b782e64696174ull,
0x6d090a202f2f0920ull,0x2e6f6c2e34326c75ull,0x3972250920323375ull,0x25202c347225202cull,
0x2f2f0920203b3872ull,0x752e747663090a20ull,0x09203233752e3436ull,0x7225202c33647225ull,
0x2020202020203b36ull,0x63090a202f2f0920ull,0x752e3436732e7476ull,0x3464722509203233ull,
0x20203b397225202cull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,
0x647225202c356472ull,0x2020203b34202c33ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x2c36647225092034ull,0x34202c3464722520ull,0x2f2f09202020203bull,0x61702e646c090a20ull,
0x203436752e6d6172ull,0x5b202c3764722509ull,0x6170616475635f5full,0x6936315a5f5f6d72ull,
0x4e4365737265766eull,0x506c656e72654b44ull,0x4f5f645f6a5f5366ull,0x093b5d7475707475ull,
0x31313a6469202f2full,0x6475635f5f203437ull,0x5a5f5f6d72617061ull,0x737265766e693631ull,
0x6e72654b444e4365ull,0x5f6a5f5366506c65ull,0x74757074754f5f64ull,0x744c240a3078302bull,
0x0a3a3630325f335full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x6c2e090a30363220ull,0x363209383109636full,0x646461090a300930ull,0x722509203436752eull,
0x35647225202c3864ull,0x203b31647225202cull,0x0a202f2f09202020ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x72255b202c316625ull,0x09203b5d302b3864ull,0x31313a6469202f2full,
0x2e747663090a3338ull,0x203233662e343666ull,0x25202c3164662509ull,0x20202020203b3166ull,
0x090a202f2f092020ull,0x09383109636f6c2eull,0x6d090a3009313632ull,0x09203436662e766full,
0x6430202c32646625ull,0x3030303030666633ull,0x3030303030303030ull,0x090a31202f2f093bull,
0x752e65672e746573ull,0x09203436662e3233ull,0x6625202c30317225ull,0x32646625202c3164ull,
0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c31317225ull,0x20202020203b3031ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3364662509203436ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x2e746573090a3020ull,0x662e3233752e656cull,
0x3231722509203436ull,0x202c31646625202cull,0x2f2f093b33646625ull,0x732e67656e090a20ull,
0x3331722509203233ull,0x203b32317225202cull,0x2020202020202020ull,0x6f090a202f2f0920ull,
0x2509203233622e72ull,0x317225202c343172ull,0x3b33317225202c31ull,0x2f2f092020202020ull,
0x752e766f6d090a20ull,0x3531722509203233ull,0x202020203b30202cull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e71652e707465ull,0x2c33702509203233ull,0x25202c3431722520ull,
0x2f2f09203b353172ull,0x2033702540090a20ull,0x744c240920617262ull,0x203b3730325f335full,
0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x325f335f744c2420ull,0x2e766f6d090a3630ull,0x6466250920343666ull,0x6666666430202c34ull,
0x3030303030303038ull,0x2f093b3030303030ull,0x62090a6e616e202full,0x0920696e752e6172ull,
0x31315f335f744c24ull,0x202020202020203bull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x2f2f200a3a373032ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,0x30325f335f744c24ull,
0x09636f6c2e090a36ull,0x3009333231093831ull,0x36662e766f6d090aull,0x2c35646625092034ull,
0x3030656662643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x6461090a352e302dull,
0x2509203436662e64ull,0x646625202c366466ull,0x3b35646625202c31ull,0x202f2f0920202020ull,
0x36662e736261090aull,0x2c37646625092034ull,0x20203b3664662520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x336430202c386466ull,0x6137343165616466ull,
0x3b31656137343165ull,0x32342e30202f2f09ull,0x6c2e70746573090aull,0x2509203436662e74ull,
0x37646625202c3470ull,0x203b38646625202cull,0x2140090a202f2f09ull,0x2061726220347025ull,
0x325f335f744c2409ull,0x20202020203b3031ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3630325f33ull,0x3109383109636f6cull,
0x756d090a30093532ull,0x2509203436662e6cull,0x646625202c396466ull,0x3b36646625202c36ull,
0x202f2f0920202020ull,0x36662e766f6d090aull,0x3031646625092034ull,0x343030346430202cull,
0x3832623133396430ull,0x2f2f093b64303236ull,0x33363630352e3220ull,0x36662e766f6d090aull,
0x3131646625092034ull,0x323330636430202cull,0x3435656130376439ull,0x2f2f093b65643361ull,
0x3531362e38312d20ull,0x36662e766f6d090aull,0x3231646625092034ull,0x343430346430202cull,
0x3337346332313262ull,0x2f2f093b63663663ull,0x323139332e313420ull,0x36662e766f6d090aull,
0x3331646625092034ull,0x393330636430202cull,0x3733373539653037ull,0x2f2f093b38373737ull,
0x3134342e35322d20ull,0x662e64616d090a31ull,0x3164662509203436ull,0x2c39646625202c34ull,
0x202c333164662520ull,0x2f093b3231646625ull,0x2e64616d090a202full,0x6466250920343666ull,
0x31646625202c3531ull,0x2c39646625202c34ull,0x093b313164662520ull,0x64616d090a202f2full,
0x662509203436662eull,0x646625202c363164ull,0x39646625202c3531ull,0x3b3031646625202cull,
0x756d090a202f2f09ull,0x2509203436662e6cull,0x6625202c37316466ull,0x31646625202c3664ull,
0x202f2f0920203b36ull,0x36662e766f6d090aull,0x3831646625092034ull,0x306666336430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x2e766f6d090a3120ull,0x6466250920343666ull,
0x30636430202c3931ull,0x3630303732663032ull,0x093b643237303535ull,0x37342e382d202f2full,
0x766f6d090a313533ull,0x662509203436662eull,0x346430202c303264ull,0x3937353531373330ull,
0x3b63323035313831ull,0x302e3332202f2f09ull,0x766f6d090a343338ull,0x662509203436662eull,
0x636430202c313264ull,0x3066656630353330ull,0x3b64373565313037ull,0x2e31322d202f2f09ull,
0x6f6d090a32323630ull,0x2509203436662e76ull,0x6430202c32326466ull,0x3066623039303034ull,
0x3734613835353032ull,0x312e33202f2f093bull,0x616d090a33383033ull,0x2509203436662e64ull,
0x6625202c33326466ull,0x32646625202c3964ull,0x3132646625202c32ull,0x6d090a202f2f093bull,
0x09203436662e6461ull,0x25202c3432646625ull,0x6625202c33326466ull,0x32646625202c3964ull,
0x090a202f2f093b30ull,0x203436662e64616dull,0x202c353264662509ull,0x25202c3432646625ull,
0x646625202c396466ull,0x0a202f2f093b3931ull,0x3436662e64616d09ull,0x2c36326466250920ull,
0x202c353264662520ull,0x6625202c39646625ull,0x202f2f093b383164ull,0x36662e766964090aull,
0x3732646625092034ull,0x2c3731646625202cull,0x203b363264662520ull,0x7262090a202f2f09ull,
0x240920696e752e61ull,0x3930325f335f744cull,0x202020202020203bull,0x202f2f0920202020ull,
0x325f335f744c240aull,0x3c2f2f200a3a3031ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3630325f335f744cull,0x36662e766f6d090aull,0x3832646625092034ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e74672eull,
0x6625202c35702509ull,0x32646625202c3664ull,0x090a202f2f093b38ull,0x7262203570252140ull,
0x335f744c24092061ull,0x2020203b3231325full,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x0a3630325f335f74ull,0x383209636f6c2e09ull,
0x090a300930343509ull,0x203436662e766f6dull,0x202c393264662509ull,0x3030306666336430ull,
0x3030303030303030ull,0x31202f2f093b3030ull,0x36662e627573090aull,0x3033646625092034ull,
0x2c3932646625202cull,0x20203b3164662520ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,
0x3172252c36317225ull,0x33646625202c7d37ull,0x202f2f0920203b30ull,0x3209636f6c2e090aull,
0x0a30093134350938ull,0x3436622e766f6d09ull,0x2c383172257b0920ull,0x25202c7d39317225ull,
0x0920203b30336466ull,0x6f6c2e090a202f2full,0x3234350938320963ull,0x2e736261090a3009ull,
0x6466250920343666ull,0x33646625202c3133ull,0x2020202020203b30ull,0x090a202f2f092020ull,
0x203436662e766f6dull,0x202c323364662509ull,0x3030306666376430ull,0x3030303030303030ull,
0x69202f2f093b3030ull,0x70746573090a666eull,0x203436662e656c2eull,0x6625202c36702509ull,
0x646625202c313364ull,0x0a202f2f093b3233ull,0x7262203670254009ull,0x335f744c24092061ull,
0x2020203b3331325full,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3630325f335f744cull,0x36662e646461090aull,0x3333646625092034ull,
0x2c3033646625202cull,0x203b303364662520ull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3b36315f335f744cull,0x2020202020202020ull,0x202f2f0920202020ull,0x325f335f744c240aull,
0x3c2f2f200a3a3331ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,
0x36662e766f6d090aull,0x3433646625092034ull,0x303030306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e746c2eull,0x6625202c37702509ull,
0x646625202c303364ull,0x0a202f2f093b3433ull,0x6220377025214009ull,0x5f744c2409206172ull,
0x20203b3531325f33ull,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3630325f335f744cull,0x36662e766f6d090aull,0x3333646625092034ull,
0x386666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x7262090a6e616e20ull,
0x240920696e752e61ull,0x3b36315f335f744cull,0x2020202020202020ull,0x202f2f0920202020ull,
0x325f335f744c240aull,0x3c2f2f200a3a3531ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3630325f335f744cull,0x36662e766f6d090aull,0x3533646625092034ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e71652eull,
0x6625202c38702509ull,0x646625202c303364ull,0x0a202f2f093b3533ull,0x6220387025214009ull,
0x5f744c2409206172ull,0x20203b3731325f33ull,0x0920202020202020ull,0x3c2f2f200a202f2full,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,0x36662e766f6d090aull,
0x3333646625092034ull,0x306666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,
0x62090a666e692d20ull,0x0920696e752e6172ull,0x36315f335f744c24ull,0x202020202020203bull,
0x2f2f092020202020ull,0x5f335f744c240a20ull,0x2f2f200a3a373132ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x30325f335f744c24ull,0x09636f6c2e090a36ull,0x3009343535093832ull,
0x36662e766f6d090aull,0x3633646625092034ull,0x306666376430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x6573090a666e6920ull,0x36662e71652e7074ull,0x202c397025092034ull,
0x25202c3133646625ull,0x2f2f093b36336466ull,0x3970252140090a20ull,0x4c24092061726220ull,
0x3b3931325f335f74ull,0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,
0x64656c6562616c20ull,0x325f335f744c2420ull,0x2e766f6d090a3630ull,0x6466250920343666ull,
0x33646625202c3333ull,0x2020202020203b30ull,0x090a202f2f092020ull,0x20696e752e617262ull,
0x315f335f744c2409ull,0x2020202020203b36ull,0x2f09202020202020ull,0x335f744c240a202full,
0x2f200a3a3931325full,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,0x325f335f744c2420ull,
0x2e766f6d090a3630ull,0x6466250920343666ull,0x30306430202c3733ull,0x3030303030303031ull,
0x093b303030303030ull,0x3532322e32202f2full,0x0a3830332d653730ull,0x746c2e7074657309ull,
0x702509203436662eull,0x33646625202c3031ull,0x3733646625202c30ull,0x40090a202f2f093bull,
0x7262203031702521ull,0x335f744c24092061ull,0x2020203b3232325full,0x2f2f092020202020ull,
0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x090a3630325f335full,
0x09383209636f6c2eull,0x6d090a3009313635ull,0x09203436662e766full,0x30202c3833646625ull,
0x3030303035333464ull,0x3030303030303030ull,0x2e31202f2f093b30ull,0x312b653434313038ull,
0x662e6c756d090a36ull,0x3364662509203436ull,0x3033646625202c39ull,0x3b3833646625202cull,
0x6d090a202f2f0920ull,0x09203436622e766full,0x72252c303272257bull,0x646625202c7d3731ull,
0x2f2f0920203b3933ull,0x09636f6c2e090a20ull,0x3009323635093832ull,0x36622e766f6d090aull,
0x383172257b092034ull,0x202c7d313272252cull,0x20203b3933646625ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x34352d202c323272ull,0x202020202020203bull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x2020203b3132325full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x0a3a3232325f335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6f6d090a3630325full,0x2509203233732e76ull,0x203b30202c323272ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x325f335f744c240aull,0x3c2f2f200a3a3132ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,0x3209636f6c2e090aull,
0x0a30093736350938ull,0x3233732e72687309ull,0x202c333272250920ull,0x3032202c37317225ull,
0x092020202020203bull,0x646e61090a202f2full,0x722509203233622eull,0x33327225202c3432ull,
0x203b37343032202cull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c353272250920ull,
0x7225202c32327225ull,0x09202020203b3432ull,0x627573090a202f2full,0x722509203233732eull,
0x35327225202c3232ull,0x203b33323031202cull,0x0a202f2f09202020ull,0x383209636f6c2e09ull,
0x090a300938363509ull,0x203233622e646e61ull,0x25202c3632722509ull,0x31322d202c373172ull,
0x3337303533343634ull,0x6f090a202f2f093bull,0x2509203233622e72ull,0x327225202c373272ull,
0x3632373031202c36ull,0x2f093b3834323339ull,0x2e766f6d090a202full,0x6466250920343662ull,
0x3172257b202c3034ull,0x3b7d373272252c38ull,0x090a202f2f092020ull,0x203436662e766f6dull,
0x202c313464662509ull,0x20203b3034646625ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x66336430202c3234ull,0x3636653930613666ull,0x093b646362336637ull,
0x3431342e31202f2full,0x70746573090a3132ull,0x203436662e74672eull,0x25202c3131702509ull,
0x6625202c30346466ull,0x202f2f093b323464ull,0x313170252140090aull,0x4c24092061726220ull,
0x3b3332325f335f74ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x30325f335f744c24ull,0x09636f6c2e090a36ull,0x3009303735093832ull,
0x36622e766f6d090aull,0x383272257b092034ull,0x202c7d393272252cull,0x20203b3034646625ull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x327225202c303372ull,0x3538343031202c39ull,
0x202f2f09203b3637ull,0x36622e766f6d090aull,0x313372257b092034ull,0x202c7d323372252cull,
0x20203b3034646625ull,0x6f6d090a202f2f09ull,0x2509203436622e76ull,0x257b202c31346466ull,
0x303372252c313372ull,0x202f2f0920203b7dull,0x3209636f6c2e090aull,0x0a30093137350938ull,
0x3233732e64646109ull,0x202c323272250920ull,0x3b31202c32327225ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x200a3a3332325f33ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6f6c2e090a363032ull,0x3538350938320963ull,0x2e766f6d090a3009ull,
0x6466250920343666ull,0x66626430202c3334ull,0x3030303030303066ull,0x093b303030303030ull,
0x61090a312d202f2full,0x09203436662e6464ull,0x25202c3434646625ull,0x6625202c31346466ull,
0x2f2f09203b333464ull,0x662e766f6d090a20ull,0x3464662509203436ull,0x6666336430202c35ull,
0x3030303030303030ull,0x2f093b3030303030ull,0x646461090a31202full,0x662509203436662eull,
0x646625202c363464ull,0x34646625202c3134ull,0x0a202f2f09203b35ull,0x3436662e70637209ull,
0x2c37346466250920ull,0x203b363464662520ull,0x0920202020202020ull,0x6c756d090a202f2full,
0x662509203436662eull,0x646625202c383464ull,0x34646625202c3434ull,0x0a202f2f09203b37ull,
0x3436662e64646109ull,0x2c39346466250920ull,0x202c383464662520ull,0x09203b3834646625ull,
0x6c756d090a202f2full,0x662509203436662eull,0x646625202c303564ull,0x34646625202c3934ull,
0x0a202f2f09203b39ull,0x3436662e766f6d09ull,0x2c31356466250920ull,0x3331626533643020ull,
0x3038656133623038ull,0x202f2f093b653166ull,0x6533333632302e31ull,0x766f6d090a36302dull,
0x662509203436662eull,0x336430202c323564ull,0x3835326565306465ull,0x3b34306238613762ull,
0x33302e34202f2f09ull,0x0a36302d65393436ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x35646625202c3335ull,0x3035646625202c31ull,0x3b3235646625202cull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x6430202c34356466ull,0x3636326233666533ull,0x6636373632306639ull,
0x382e31202f2f093bull,0x35302d6534343837ull,0x6e722e64616d090aull,0x662509203436662eull,
0x646625202c353564ull,0x35646625202c3335ull,0x3435646625202c30ull,0x6d090a202f2f093bull,
0x09203436662e766full,0x30202c3635646625ull,0x6335343731663364ull,0x3539306261396162ull,
0x2e38202f2f093b36ull,0x302d653138373738ull,0x722e64616d090a35ull,0x2509203436662e6eull,
0x6625202c37356466ull,0x646625202c353564ull,0x35646625202c3035ull,0x090a202f2f093b36ull,
0x203436662e766f6dull,0x202c383564662509ull,0x3137633366336430ull,0x3135623164323763ull,
0x30202f2f093b3435ull,0x303433343030302eull,0x2e64616d090a3832ull,0x09203436662e6e72ull,
0x25202c3935646625ull,0x6625202c37356466ull,0x646625202c303564ull,0x0a202f2f093b3835ull,
0x383209636f6c2e09ull,0x090a300936383509ull,0x203436662e766f6dull,0x202c303664662509ull,
0x3934323666336430ull,0x3765623332393432ull,0x30202f2f093b6432ull,0x313233323230302eull,
0x722e64616d090a34ull,0x2509203436662e6eull,0x6625202c39356466ull,0x646625202c393564ull,
0x36646625202c3035ull,0x090a202f2f093b30ull,0x09383209636f6c2eull,0x6d090a3009373835ull,
0x09203436662e766full,0x30202c3136646625ull,0x3939393938663364ull,0x6333613939393939ull,
0x2e30202f2f093b34ull,0x616d090a35323130ull,0x3436662e6e722e64ull,0x2c39356466250920ull,
0x202c393564662520ull,0x25202c3035646625ull,0x2f2f093b31366466ull,0x09636f6c2e090a20ull,
0x3009383835093832ull,0x36662e766f6d090aull,0x3236646625092034ull,0x356266336430202cull,
0x3535353535353535ull,0x2f2f093b34353535ull,0x33333338302e3020ull,0x2e64616d090a3333ull,
0x09203436662e6e72ull,0x25202c3935646625ull,0x6625202c39356466ull,0x646625202c303564ull,
0x0a202f2f093b3236ull,0x383209636f6c2e09ull,0x090a300934393509ull,0x203436662e6c756dull,
0x202c333664662509ull,0x25202c3035646625ull,0x2f09203b39356466ull,0x2e6c756d090a202full,
0x6466250920343666ull,0x34646625202c3935ull,0x3336646625202c39ull,0x090a202f2f09203bull,
0x09383209636f6c2eull,0x63090a3009343036ull,0x36662e6e722e7476ull,0x2509203233732e34ull,
0x7225202c34366466ull,0x2f2f0920203b3232ull,0x662e627573090a20ull,0x3664662509203436ull,
0x3434646625202c35ull,0x3b3934646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3636646625ull,0x3465323665663364ull,0x6539336166656632ull,0x2e30202f2f093b66ull,
0x090a373431333936ull,0x662e6e722e64616dull,0x3664662509203436ull,0x3436646625202c37ull,
0x2c3636646625202cull,0x093b393464662520ull,0x766f6d090a202f2full,0x662509203436662eull,
0x336430202c383664ull,0x3365396362613763ull,0x3b66333038393362ull,0x31332e32202f2f09ull,
0x0a37312d65353039ull,0x3436662e67656e09ull,0x2c39366466250920ull,0x203b393464662520ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x257b09203436622eull,0x343372252c333372ull,
0x3536646625202c7dull,0x0a202f2f0920203bull,0x3233732e64646109ull,0x202c353372250920ull,
0x3031202c34337225ull,0x09203b3637353834ull,0x766f6d090a202f2full,0x257b09203436622eull,
0x373372252c363372ull,0x3536646625202c7dull,0x0a202f2f0920203bull,0x3436622e766f6d09ull,
0x2c30376466250920ull,0x252c363372257b20ull,0x0920203b7d353372ull,0x64616d090a202f2full,
0x203436662e6e722eull,0x202c313764662509ull,0x25202c3936646625ull,0x6625202c34346466ull,
0x202f2f093b303764ull,0x36662e64616d090aull,0x3237646625092034ull,0x2c3137646625202cull,
0x202c373464662520ull,0x2f093b3935646625ull,0x2e67656e090a202full,0x3372250920323373ull,
0x3b32327225202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,0x662e6e722e747663ull,
0x09203233732e3436ull,0x25202c3337646625ull,0x2f0920203b383372ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x66336430202c3437ull,0x6566323465323665ull,0x093b666539336166ull,
0x3339362e30202f2full,0x64616d090a373431ull,0x203436662e6e722eull,0x202c353764662509ull,
0x25202c3337646625ull,0x6625202c34376466ull,0x202f2f093b373664ull,0x36662e627573090aull,
0x3637646625092034ull,0x2c3537646625202cull,0x203b393464662520ull,0x7573090a202f2f09ull,
0x2509203436662e62ull,0x6625202c37376466ull,0x646625202c323764ull,0x202f2f09203b3637ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c383764ull,0x36646625202c3436ull,
0x3737646625202c38ull,0x61090a202f2f093bull,0x09203436662e6464ull,0x25202c3333646625ull,
0x6625202c37366466ull,0x2f2f09203b383764ull,0x5f335f744c240a20ull,0x3c2f2f200a3a3631ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,0x3209636f6c2e090aull,
0x0a30093034350938ull,0x3436662e67656e09ull,0x2c39376466250920ull,0x203b333364662520ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x257b09203436622eull,0x373172252c393372ull,
0x3937646625202c7dull,0x0a202f2f0920203bull,0x383209636f6c2e09ull,0x090a300931343509ull,
0x203436622e766f6dull,0x252c383172257b09ull,0x6625202c7d303472ull,0x2f0920203b393764ull,
0x636f6c2e090a202full,0x0932343509383209ull,0x662e736261090a30ull,0x3864662509203436ull,
0x3333646625202c30ull,0x202020202020203bull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3138646625ull,0x3030303066663764ull,0x3030303030303030ull,0x6e69202f2f093b30ull,
0x2e70746573090a66ull,0x09203436662e656cull,0x6625202c32317025ull,0x646625202c303864ull,
0x0a202f2f093b3138ull,0x6220323170254009ull,0x5f744c2409206172ull,0x20203b3532325f33ull,
0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3630325f335f744cull,0x36662e646461090aull,0x3238646625092034ull,0x2c3333646625202cull,
0x203b333364662520ull,0x656e090a202f2f09ull,0x2509203436662e67ull,0x6625202c33386466ull,
0x202020203b323864ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x202020203b38315full,0x2020202020202020ull,0x744c240a202f2f09ull,0x0a3a3532325f335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c30363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x6f6d090a3630325full,
0x2509203436662e76ull,0x6430202c34386466ull,0x3030303030303030ull,0x3030303030303030ull,
0x090a30202f2f093bull,0x2e746c2e70746573ull,0x3170250920343666ull,0x3937646625202c33ull,
0x3b3438646625202cull,0x2140090a202f2f09ull,0x6172622033317025ull,0x5f335f744c240920ull,
0x202020203b373232ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x6d090a3630325f33ull,0x09203436662e766full,0x30202c3338646625ull,
0x3030303866666664ull,0x3030303030303030ull,0x616e202f2f093b30ull,0x752e617262090a6eull,
0x5f744c240920696eull,0x2020203b38315f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x3a3732325f335f74ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x6d090a3630325f33ull,0x09203436662e766full,0x30202c3538646625ull,0x3030303030303064ull,
0x3030303030303030ull,0x0a30202f2f093b30ull,0x71652e7074657309ull,0x702509203436662eull,
0x37646625202c3431ull,0x3538646625202c39ull,0x40090a202f2f093bull,0x7262203431702521ull,
0x335f744c24092061ull,0x2020203b3932325full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3630325f335full,0x203436662e766f6dull,
0x202c333864662509ull,0x3030306666666430ull,0x3030303030303030ull,0x2d202f2f093b3030ull,
0x617262090a666e69ull,0x4c240920696e752eull,0x203b38315f335f74ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x32325f335f744c24ull,0x6c3c2f2f200a3a39ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3630325f335f74ull,0x383209636f6c2e09ull,0x090a300934353509ull,
0x203436662e766f6dull,0x202c363864662509ull,0x3030306666376430ull,0x3030303030303030ull,
0x69202f2f093b3030ull,0x70746573090a666eull,0x203436662e71652eull,0x25202c3531702509ull,
0x6625202c30386466ull,0x202f2f093b363864ull,0x353170252140090aull,0x4c24092061726220ull,
0x3b3133325f335f74ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x30325f335f744c24ull,0x662e766f6d090a36ull,0x3864662509203436ull,
0x3937646625202c33ull,0x202020202020203bull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x38315f335f744c24ull,0x202020202020203bull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x2f2f200a3a313332ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,0x30325f335f744c24ull,
0x662e766f6d090a36ull,0x3864662509203436ull,0x3130306430202c37ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x303532322e32202full,0x090a3830332d6537ull,0x2e746c2e70746573ull,
0x3170250920343666ull,0x3937646625202c36ull,0x3b3738646625202cull,0x2140090a202f2f09ull,
0x6172622036317025ull,0x5f335f744c240920ull,0x202020203b343332ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3630325f33ull,
0x3509383209636f6cull,0x6f6d090a30093136ull,0x2509203436662e76ull,0x6430202c38386466ull,
0x3030303030353334ull,0x3030303030303030ull,0x382e31202f2f093bull,0x36312b6534343130ull,
0x36662e6c756d090aull,0x3938646625092034ull,0x2c3937646625202cull,0x203b383864662520ull,
0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x3172252c31347225ull,0x38646625202c7d37ull,
0x202f2f0920203b39ull,0x3209636f6c2e090aull,0x0a30093236350938ull,0x3436622e766f6d09ull,
0x2c383172257b0920ull,0x25202c7d32347225ull,0x0920203b39386466ull,0x766f6d090a202f2full,
0x722509203233732eull,0x3b34352d202c3232ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x696e752e61726209ull,0x5f335f744c240920ull,0x202020203b333332ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x200a3a3433325f33ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x766f6d090a363032ull,0x722509203233732eull,0x20203b30202c3232ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x33325f335f744c24ull,0x6c3c2f2f200a3a33ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x0a3630325f335f74ull,0x383209636f6c2e09ull,
0x090a300937363509ull,0x203233732e726873ull,0x25202c3334722509ull,0x3b3032202c373172ull,
0x2f09202020202020ull,0x2e646e61090a202full,0x3472250920323362ull,0x2c33347225202c34ull,
0x20203b3734303220ull,0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3534722509ull,
0x347225202c323272ull,0x2f09202020203b34ull,0x2e627573090a202full,0x3272250920323373ull,
0x2c35347225202c32ull,0x20203b3332303120ull,0x090a202f2f092020ull,0x09383209636f6c2eull,
0x61090a3009383635ull,0x09203233622e646eull,0x7225202c36327225ull,0x3431322d202c3731ull,
0x3b33373035333436ull,0x726f090a202f2f09ull,0x722509203233622eull,0x36327225202c3634ull,
0x393632373031202cull,0x2f2f093b38343233ull,0x622e766f6d090a20ull,0x3964662509203436ull,
0x383172257b202c30ull,0x203b7d363472252cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x25202c3134646625ull,0x2020203b30396466ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,
0x3964662509203436ull,0x6666336430202c31ull,0x3736366539306136ull,0x2f093b6463623366ull,
0x323431342e31202full,0x2e70746573090a31ull,0x09203436662e7467ull,0x6625202c37317025ull,
0x646625202c303964ull,0x0a202f2f093b3139ull,0x2037317025214009ull,0x744c240920617262ull,
0x203b3533325f335full,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3630325f335f744cull,0x3209636f6c2e090aull,0x0a30093037350938ull,
0x3436622e766f6d09ull,0x2c373472257b0920ull,0x25202c7d38347225ull,0x0920203b30396466ull,
0x627573090a202f2full,0x722509203233732eull,0x38347225202c3934ull,0x373538343031202cull,
0x0a202f2f09203b36ull,0x3436622e766f6d09ull,0x2c303572257b0920ull,0x25202c7d31357225ull,
0x0920203b30396466ull,0x766f6d090a202f2full,0x662509203436622eull,0x72257b202c313464ull,
0x7d393472252c3035ull,0x0a202f2f0920203bull,0x383209636f6c2e09ull,0x090a300931373509ull,
0x203233732e646461ull,0x25202c3232722509ull,0x203b31202c323272ull,0x2f09202020202020ull,
0x335f744c240a202full,0x2f200a3a3533325full,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x325f335f744c2420ull,0x636f6c2e090a3630ull,0x0935383509383209ull,0x662e766f6d090a30ull,
0x3964662509203436ull,0x6666626430202c32ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x6461090a312d202full,0x2509203436662e64ull,0x6625202c34346466ull,0x646625202c313464ull,
0x202f2f09203b3239ull,0x36662e766f6d090aull,0x3339646625092034ull,0x306666336430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x2e646461090a3120ull,0x6466250920343666ull,
0x34646625202c3439ull,0x3339646625202c31ull,0x090a202f2f09203bull,0x203436662e706372ull,
0x202c373464662509ull,0x20203b3439646625ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x6466250920343666ull,0x34646625202c3834ull,0x3734646625202c34ull,0x090a202f2f09203bull,
0x203436662e646461ull,0x202c393464662509ull,0x25202c3834646625ull,0x2f09203b38346466ull,
0x2e6c756d090a202full,0x6466250920343666ull,0x34646625202c3035ull,0x3934646625202c39ull,
0x090a202f2f09203bull,0x203436662e766f6dull,0x202c353964662509ull,0x3833316265336430ull,
0x6630386561336230ull,0x31202f2f093b6531ull,0x2d6533333632302eull,0x2e766f6d090a3630ull,
0x6466250920343666ull,0x65336430202c3639ull,0x6238353265653064ull,0x093b343062386137ull,
0x3633302e34202f2full,0x090a36302d653934ull,0x662e6e722e64616dull,0x3964662509203436ull,
0x3539646625202c37ull,0x2c3035646625202cull,0x093b363964662520ull,0x766f6d090a202f2full,
0x662509203436662eull,0x336430202c383964ull,0x3936363262336665ull,0x3b66363736323066ull,
0x37382e31202f2f09ull,0x0a35302d65343438ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x39646625202c3939ull,0x3035646625202c37ull,0x3b3839646625202cull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3030316466ull,0x6335343731663364ull,0x3539306261396162ull,
0x2e38202f2f093b36ull,0x302d653138373738ull,0x722e64616d090a35ull,0x2509203436662e6eull,
0x25202c3130316466ull,0x6625202c39396466ull,0x646625202c303564ull,0x202f2f093b303031ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x3366336430202c32ull,0x3164323763313763ull,
0x2f093b3435313562ull,0x343030302e30202full,0x6d090a3832303433ull,0x36662e6e722e6461ull,
0x3935646625092034ull,0x313031646625202cull,0x2c3035646625202cull,0x3b32303164662520ull,
0x6c2e090a202f2f09ull,0x383509383209636full,0x766f6d090a300936ull,0x662509203436662eull,
0x6430202c33303164ull,0x3432393432366633ull,0x6432376562333239ull,0x302e30202f2f093bull,
0x0a34313233323230ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x35646625202c3935ull,
0x3035646625202c39ull,0x333031646625202cull,0x2e090a202f2f093bull,0x3509383209636f6cull,
0x6f6d090a30093738ull,0x2509203436662e76ull,0x30202c3430316466ull,0x3939393938663364ull,
0x6333613939393939ull,0x2e30202f2f093b34ull,0x616d090a35323130ull,0x3436662e6e722e64ull,
0x2c39356466250920ull,0x202c393564662520ull,0x25202c3035646625ull,0x2f093b3430316466ull,
0x636f6c2e090a202full,0x0938383509383209ull,0x662e766f6d090a30ull,0x3164662509203436ull,
0x66336430202c3530ull,0x3535353535353562ull,0x093b343535353535ull,0x3338302e30202f2full,
0x616d090a33333333ull,0x3436662e6e722e64ull,0x2c39356466250920ull,0x202c393564662520ull,
0x25202c3035646625ull,0x2f093b3530316466ull,0x636f6c2e090a202full,0x0934393509383209ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x35646625202c3630ull,0x3935646625202c30ull,
0x6d090a202f2f093bull,0x09203436662e6c75ull,0x25202c3935646625ull,0x6625202c39346466ull,
0x2f2f093b36303164ull,0x09636f6c2e090a20ull,0x3009343036093832ull,0x6e722e747663090aull,
0x3233732e3436662eull,0x2c34366466250920ull,0x20203b3232722520ull,0x7573090a202f2f09ull,
0x2509203436662e62ull,0x6625202c35366466ull,0x646625202c343464ull,0x202f2f09203b3934ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x6566336430202c37ull,0x6665663234653236ull,
0x2f093b6665393361ull,0x313339362e30202full,0x2e64616d090a3734ull,0x09203436662e6e72ull,
0x25202c3736646625ull,0x6625202c34366466ull,0x6625202c37303164ull,0x202f2f093b393464ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x3763336430202c38ull,0x3362336539636261ull,
0x2f093b6633303839ull,0x303931332e32202full,0x6e090a37312d6535ull,0x09203436662e6765ull,
0x202c393031646625ull,0x20203b3934646625ull,0x2f2f092020202020ull,0x622e766f6d090a20ull,
0x3572257b09203436ull,0x2c7d333572252c32ull,0x203b353664662520ull,0x61090a202f2f0920ull,
0x09203233732e6464ull,0x7225202c34357225ull,0x38343031202c3335ull,0x2f2f09203b363735ull,
0x622e766f6d090a20ull,0x3572257b09203436ull,0x2c7d363572252c35ull,0x203b353664662520ull,
0x6d090a202f2f0920ull,0x09203436622e766full,0x202c303131646625ull,0x72252c353572257bull,
0x2f2f09203b7d3435ull,0x722e64616d090a20ull,0x2509203436662e6eull,0x25202c3131316466ull,
0x25202c3930316466ull,0x6625202c34346466ull,0x2f2f093b30313164ull,0x662e64616d090a20ull,
0x3164662509203436ull,0x31646625202c3231ull,0x34646625202c3131ull,0x3935646625202c37ull,
0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c37357225ull,0x20202020203b3232ull,
0x2f2f092020202020ull,0x722e747663090a20ull,0x33732e3436662e6eull,0x3131646625092032ull,
0x3b37357225202c33ull,0x6d090a202f2f0920ull,0x09203436662e766full,0x202c343131646625ull,
0x6532366566336430ull,0x3933616665663234ull,0x30202f2f093b6665ull,0x0a3734313339362eull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x646625202c353131ull,0x646625202c333131ull,
0x646625202c343131ull,0x0a202f2f093b3736ull,0x3436662e62757309ull,0x3631316466250920ull,
0x353131646625202cull,0x3b3934646625202cull,0x7573090a202f2f09ull,0x2509203436662e62ull,
0x25202c3731316466ull,0x25202c3231316466ull,0x2f093b3631316466ull,0x2e64616d090a202full,
0x09203436662e6e72ull,0x25202c3837646625ull,0x6625202c34366466ull,0x6625202c38303164ull,
0x2f2f093b37313164ull,0x662e646461090a20ull,0x3864662509203436ull,0x3736646625202c33ull,
0x3b3837646625202cull,0x4c240a202f2f0920ull,0x0a3a38315f335f74ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x6c2e090a3630325full,0x323109383109636full,
0x766f6d090a300938ull,0x662509203436662eull,0x646625202c373264ull,0x20202020203b3338ull,
0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f335f744c240920ull,0x202020203b313132ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x200a3a3231325f33ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x6f6c2e090a363032ull,0x3034350938320963ull,
0x2e766f6d090a3009ull,0x72257b0920343662ull,0x7d373172252c3835ull,0x203b31646625202cull,
0x090a202f2f092020ull,0x09383209636f6c2eull,0x6d090a3009313435ull,0x09203436622e766full,
0x72252c383172257bull,0x646625202c7d3935ull,0x2f2f092020203b31ull,0x09636f6c2e090a20ull,
0x3009323435093832ull,0x36662e736261090aull,0x3131646625092034ull,0x3b31646625202c38ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x30202c3931316466ull,
0x3030303066663764ull,0x3030303030303030ull,0x6e69202f2f093b30ull,0x2e70746573090a66ull,
0x09203436662e656cull,0x6625202c38317025ull,0x6625202c38313164ull,0x2f2f093b39313164ull,
0x3831702540090a20ull,0x4c24092061726220ull,0x3b3733325f335f74ull,0x2020202020202020ull,
0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,0x325f335f744c2420ull,
0x2e646461090a3630ull,0x6466250920343666ull,0x646625202c303231ull,0x3b31646625202c31ull,
0x090a202f2f092020ull,0x20696e752e617262ull,0x315f335f744c2409ull,0x2020202020203b32ull,
0x2f09202020202020ull,0x335f744c240a202full,0x2f200a3a3733325full,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,
0x64656c6562616c20ull,0x325f335f744c2420ull,0x2e766f6d090a3630ull,0x6466250920343666ull,
0x306430202c313231ull,0x3030303030303030ull,0x3b30303030303030ull,0x73090a30202f2f09ull,
0x662e746c2e707465ull,0x3931702509203436ull,0x202c31646625202cull,0x093b313231646625ull,
0x252140090a202f2full,0x2061726220393170ull,0x325f335f744c2409ull,0x20202020203b3933ull,
0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x6f6d090a3630325full,0x2509203436662e76ull,0x30202c3032316466ull,0x3030303866666664ull,
0x3030303030303030ull,0x616e202f2f093b30ull,0x752e617262090a6eull,0x5f744c240920696eull,
0x2020203b32315f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x3a3933325f335f74ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x6d090a3630325f33ull,
0x09203436662e766full,0x202c323231646625ull,0x3030303030306430ull,0x3030303030303030ull,
0x30202f2f093b3030ull,0x652e70746573090aull,0x2509203436662e71ull,0x646625202c303270ull,
0x3231646625202c31ull,0x090a202f2f093b32ull,0x6220303270252140ull,0x5f744c2409206172ull,
0x20203b3134325f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3630325f335f74ull,0x3436662e766f6d09ull,0x3032316466250920ull,
0x306666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x62090a666e692d20ull,
0x0920696e752e6172ull,0x32315f335f744c24ull,0x202020202020203bull,0x2f2f092020202020ull,
0x5f335f744c240a20ull,0x2f2f200a3a313432ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,
0x30325f335f744c24ull,0x09636f6c2e090a36ull,0x3009343535093832ull,0x36662e766f6d090aull,
0x3231646625092034ull,0x6666376430202c33ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x73090a666e69202full,0x662e71652e707465ull,0x3132702509203436ull,0x383131646625202cull,
0x333231646625202cull,0x40090a202f2f093bull,0x7262203132702521ull,0x335f744c24092061ull,
0x2020203b3334325full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3630325f335full,0x203436662e766f6dull,0x2c30323164662509ull,
0x20203b3164662520ull,0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,
0x20203b32315f335full,0x2020202020202020ull,0x240a202f2f092020ull,0x3334325f335f744cull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x090a3630325f335full,
0x203436662e766f6dull,0x2c34323164662509ull,0x3030313030643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x6537303532322e32ull,0x6573090a3830332dull,0x36662e746c2e7074ull,
0x2c32327025092034ull,0x25202c3164662520ull,0x2f093b3432316466ull,0x70252140090a202full,
0x0920617262203232ull,0x34325f335f744c24ull,0x2020202020203b36ull,0x200a202f2f092020ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x6f6c2e090a363032ull,
0x3136350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x346430202c353231ull,
0x3030303030303533ull,0x3b30303030303030ull,0x30382e31202f2f09ull,0x0a36312b65343431ull,
0x3436662e6c756d09ull,0x3632316466250920ull,0x202c31646625202cull,0x093b353231646625ull,
0x766f6d090a202f2full,0x257b09203436622eull,0x373172252c303672ull,0x3231646625202c7dull,
0x0a202f2f09203b36ull,0x383209636f6c2e09ull,0x090a300932363509ull,0x203436622e766f6dull,
0x252c383172257b09ull,0x6625202c7d313672ull,0x2f09203b36323164ull,0x2e766f6d090a202full,
0x3272250920323373ull,0x203b34352d202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x325f335f744c2409ull,0x20202020203b3534ull,0x2f09202020202020ull,
0x335f744c240a202full,0x2f200a3a3634325full,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x325f335f744c2420ull,0x2e766f6d090a3630ull,0x3272250920323373ull,0x2020203b30202c32ull,
0x2020202020202020ull,0x240a202f2f092020ull,0x3534325f335f744cull,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3630325f335full,0x09383209636f6c2eull,
0x73090a3009373635ull,0x09203233732e7268ull,0x7225202c32367225ull,0x203b3032202c3731ull,
0x2f2f092020202020ull,0x622e646e61090a20ull,0x3336722509203233ull,0x202c32367225202cull,
0x2020203b37343032ull,0x61090a202f2f0920ull,0x09203233732e6464ull,0x7225202c34367225ull,
0x33367225202c3232ull,0x2f2f09202020203bull,0x732e627573090a20ull,0x3232722509203233ull,
0x202c34367225202cull,0x2020203b33323031ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,
0x6e61090a30093836ull,0x2509203233622e64ull,0x317225202c363272ull,0x363431322d202c37ull,
0x093b333730353334ull,0x2e726f090a202f2full,0x3672250920323362ull,0x2c36327225202c35ull,
0x3339363237303120ull,0x202f2f093b383432ull,0x36622e766f6d090aull,0x3231646625092034ull,
0x383172257b202c37ull,0x203b7d353672252cull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x6625202c31346466ull,0x2020203b37323164ull,0x202f2f0920202020ull,0x36662e766f6d090aull,
0x3231646625092034ull,0x6666336430202c38ull,0x3736366539306136ull,0x2f093b6463623366ull,
0x323431342e31202full,0x2e70746573090a31ull,0x09203436662e7467ull,0x6625202c33327025ull,
0x6625202c37323164ull,0x2f2f093b38323164ull,0x3270252140090a20ull,0x2409206172622033ull,
0x3734325f335f744cull,0x202020202020203bull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,
0x64656c6562616c20ull,0x325f335f744c2420ull,0x636f6c2e090a3630ull,0x0930373509383209ull,
0x622e766f6d090a30ull,0x3672257b09203436ull,0x2c7d373672252c36ull,0x3b37323164662520ull,
0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c38367225ull,0x38343031202c3736ull,
0x2f2f09203b363735ull,0x622e766f6d090a20ull,0x3672257b09203436ull,0x2c7d303772252c39ull,
0x3b37323164662520ull,0x6d090a202f2f0920ull,0x09203436622e766full,0x7b202c3134646625ull,
0x3672252c39367225ull,0x2f2f0920203b7d38ull,0x09636f6c2e090a20ull,0x3009313735093832ull,
0x33732e646461090aull,0x2c32327225092032ull,0x31202c3232722520ull,0x202020202020203bull,
0x744c240a202f2f09ull,0x0a3a3734325f335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6c2e090a3630325full,0x383509383209636full,0x766f6d090a300935ull,
0x662509203436662eull,0x6430202c39323164ull,0x3030303030666662ull,0x3030303030303030ull,
0x0a312d202f2f093bull,0x3436662e64646109ull,0x2c34346466250920ull,0x202c313464662520ull,
0x093b393231646625ull,0x766f6d090a202f2full,0x662509203436662eull,0x6430202c30333164ull,
0x3030303030666633ull,0x3030303030303030ull,0x090a31202f2f093bull,0x203436662e646461ull,
0x2c31333164662509ull,0x202c313464662520ull,0x093b303331646625ull,0x706372090a202f2full,
0x662509203436662eull,0x646625202c373464ull,0x202020203b313331ull,0x0a202f2f09202020ull,
0x3436662e6c756d09ull,0x2c38346466250920ull,0x202c343464662520ull,0x09203b3734646625ull,
0x646461090a202f2full,0x662509203436662eull,0x646625202c393464ull,0x34646625202c3834ull,
0x0a202f2f09203b38ull,0x3436662e6c756d09ull,0x2c30356466250920ull,0x202c393464662520ull,
0x09203b3934646625ull,0x766f6d090a202f2full,0x662509203436662eull,0x6430202c32333164ull,
0x6230383331626533ull,0x6531663038656133ull,0x302e31202f2f093bull,0x36302d6533333632ull,
0x36662e766f6d090aull,0x3331646625092034ull,0x6465336430202c33ull,0x3762383532656530ull,
0x2f093b3430623861ull,0x343633302e34202full,0x6d090a36302d6539ull,0x36662e6e722e6461ull,
0x3331646625092034ull,0x3331646625202c34ull,0x3035646625202c32ull,0x333331646625202cull,
0x6d090a202f2f093bull,0x09203436662e766full,0x202c353331646625ull,0x3262336665336430ull,
0x3736323066393636ull,0x31202f2f093b6636ull,0x2d6534343837382eull,0x2e64616d090a3530ull,
0x09203436662e6e72ull,0x202c363331646625ull,0x202c343331646625ull,0x25202c3035646625ull,
0x2f093b3533316466ull,0x2e766f6d090a202full,0x6466250920343666ull,0x336430202c373331ull,
0x6162633534373166ull,0x3b36353930626139ull,0x37382e38202f2f09ull,0x0a35302d65313837ull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x646625202c383331ull,0x646625202c363331ull,
0x31646625202c3035ull,0x0a202f2f093b3733ull,0x3436662e766f6d09ull,0x3933316466250920ull,
0x633366336430202cull,0x6231643237633137ull,0x2f2f093b34353135ull,0x33343030302e3020ull,
0x616d090a38323034ull,0x3436662e6e722e64ull,0x2c39356466250920ull,0x2c38333164662520ull,
0x202c303564662520ull,0x093b393331646625ull,0x6f6c2e090a202f2full,0x3638350938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x336430202c303431ull,0x3934323934323666ull,
0x3b64323765623332ull,0x30302e30202f2f09ull,0x090a343132333232ull,0x662e6e722e64616dull,
0x3564662509203436ull,0x3935646625202c39ull,0x2c3035646625202cull,0x3b30343164662520ull,
0x6c2e090a202f2f09ull,0x383509383209636full,0x766f6d090a300937ull,0x662509203436662eull,
0x6430202c31343164ull,0x3939393939386633ull,0x3463336139393939ull,0x302e30202f2f093bull,
0x64616d090a353231ull,0x203436662e6e722eull,0x202c393564662509ull,0x25202c3935646625ull,
0x6625202c30356466ull,0x2f2f093b31343164ull,0x09636f6c2e090a20ull,0x3009383835093832ull,
0x36662e766f6d090aull,0x3431646625092034ull,0x6266336430202c32ull,0x3535353535353535ull,
0x2f093b3435353535ull,0x333338302e30202full,0x64616d090a333333ull,0x203436662e6e722eull,
0x202c393564662509ull,0x25202c3935646625ull,0x6625202c30356466ull,0x2f2f093b32343164ull,
0x09636f6c2e090a20ull,0x3009343935093832ull,0x36662e6c756d090aull,0x3431646625092034ull,
0x3035646625202c33ull,0x3b3935646625202cull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x6625202c39356466ull,0x646625202c393464ull,0x202f2f093b333431ull,0x3209636f6c2e090aull,
0x0a30093430360938ull,0x2e6e722e74766309ull,0x203233732e343666ull,0x202c343664662509ull,
0x0920203b32327225ull,0x627573090a202f2full,0x662509203436662eull,0x646625202c353664ull,
0x34646625202c3434ull,0x0a202f2f09203b39ull,0x3436662e766f6d09ull,0x3434316466250920ull,
0x366566336430202cull,0x6166656632346532ull,0x2f2f093b66653933ull,0x34313339362e3020ull,
0x722e64616d090a37ull,0x2509203436662e6eull,0x6625202c37366466ull,0x646625202c343664ull,
0x646625202c343431ull,0x0a202f2f093b3934ull,0x3436662e766f6d09ull,0x3534316466250920ull,
0x613763336430202cull,0x3933623365396362ull,0x2f2f093b66333038ull,0x35303931332e3220ull,
0x656e090a37312d65ull,0x2509203436662e67ull,0x25202c3634316466ull,0x2020203b39346466ull,
0x202f2f0920202020ull,0x36622e766f6d090aull,0x313772257b092034ull,0x202c7d323772252cull,
0x20203b3536646625ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x377225202c333772ull,
0x3538343031202c32ull,0x202f2f09203b3637ull,0x36622e766f6d090aull,0x343772257b092034ull,
0x202c7d353772252cull,0x20203b3536646625ull,0x6f6d090a202f2f09ull,0x2509203436622e76ull,
0x7b202c3734316466ull,0x3772252c34377225ull,0x202f2f09203b7d33ull,0x6e722e64616d090aull,
0x662509203436662eull,0x6625202c38343164ull,0x6625202c36343164ull,0x646625202c343464ull,
0x202f2f093b373431ull,0x36662e64616d090aull,0x3431646625092034ull,0x3431646625202c39ull,
0x3734646625202c38ull,0x3b3935646625202cull,0x656e090a202f2f09ull,0x2509203233732e67ull,
0x327225202c363772ull,0x2020202020203b32ull,0x202f2f0920202020ull,0x6e722e747663090aull,
0x3233732e3436662eull,0x3035316466250920ull,0x203b36377225202cull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3135316466ull,0x3465323665663364ull,0x6539336166656632ull,
0x2e30202f2f093b66ull,0x090a373431333936ull,0x662e6e722e64616dull,0x3164662509203436ull,
0x31646625202c3235ull,0x31646625202c3035ull,0x36646625202c3135ull,0x090a202f2f093b37ull,
0x203436662e627573ull,0x2c33353164662509ull,0x2c32353164662520ull,0x093b393464662520ull,
0x627573090a202f2full,0x662509203436662eull,0x6625202c34353164ull,0x6625202c39343164ull,
0x2f2f093b33353164ull,0x722e64616d090a20ull,0x2509203436662e6eull,0x6625202c38376466ull,
0x646625202c343664ull,0x646625202c353431ull,0x202f2f093b343531ull,0x36662e646461090aull,
0x3231646625092034ull,0x3736646625202c30ull,0x3b3837646625202cull,0x744c240a202f2f09ull,
0x200a3a32315f335full,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6f6c2e090a363032ull,0x3034350938320963ull,0x2e67656e090a3009ull,0x6466250920343666ull,
0x646625202c353531ull,0x202020203b303231ull,0x090a202f2f092020ull,0x203436622e766f6dull,
0x252c373772257b09ull,0x6625202c7d373172ull,0x2f09203b35353164ull,0x636f6c2e090a202full,
0x0931343509383209ull,0x622e766f6d090a30ull,0x3172257b09203436ull,0x2c7d383772252c38ull,
0x3b35353164662520ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,0x6261090a30093234ull,
0x2509203436662e73ull,0x25202c3635316466ull,0x20203b3032316466ull,0x202f2f0920202020ull,
0x36662e766f6d090aull,0x3531646625092034ull,0x6666376430202c37ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x73090a666e69202full,0x662e656c2e707465ull,0x3432702509203436ull,
0x363531646625202cull,0x373531646625202cull,0x40090a202f2f093bull,0x6172622034327025ull,
0x5f335f744c240920ull,0x202020203b393432ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3630325f335full,0x203436662e646461ull,
0x2c38353164662509ull,0x2c30323164662520ull,0x3b30323164662520ull,0x656e090a202f2f09ull,
0x2509203436662e67ull,0x25202c3935316466ull,0x20203b3835316466ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x202020203b34315full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x0a3a3934325f335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6f6d090a3630325full,0x2509203436662e76ull,0x30202c3036316466ull,
0x3030303030303064ull,0x3030303030303030ull,0x0a30202f2f093b30ull,0x746c2e7074657309ull,
0x702509203436662eull,0x31646625202c3532ull,0x31646625202c3535ull,0x0a202f2f093b3036ull,
0x2035327025214009ull,0x744c240920617262ull,0x203b3135325f335full,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,
0x36662e766f6d090aull,0x3531646625092034ull,0x6666666430202c39ull,0x3030303030303038ull,
0x2f093b3030303030ull,0x62090a6e616e202full,0x0920696e752e6172ull,0x34315f335f744c24ull,
0x202020202020203bull,0x2f2f092020202020ull,0x5f335f744c240a20ull,0x2f2f200a3a313532ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,
0x2064616568202c30ull,0x2064656c6562616cull,0x30325f335f744c24ull,0x662e766f6d090a36ull,
0x3164662509203436ull,0x30306430202c3136ull,0x3030303030303030ull,0x093b303030303030ull,
0x6573090a30202f2full,0x36662e71652e7074ull,0x2c36327025092034ull,0x2c35353164662520ull,
0x3b31363164662520ull,0x2140090a202f2f09ull,0x6172622036327025ull,0x5f335f744c240920ull,
0x202020203b333532ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x6d090a3630325f33ull,0x09203436662e766full,0x202c393531646625ull,
0x3030306666666430ull,0x3030303030303030ull,0x2d202f2f093b3030ull,0x617262090a666e69ull,
0x4c240920696e752eull,0x203b34315f335f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x35325f335f744c24ull,0x6c3c2f2f200a3a33ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x0a3630325f335f74ull,0x383209636f6c2e09ull,0x090a300934353509ull,0x203436662e766f6dull,
0x2c32363164662509ull,0x3030666637643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x746573090a666e69ull,0x3436662e71652e70ull,0x202c373270250920ull,0x202c363531646625ull,
0x093b323631646625ull,0x252140090a202f2full,0x2061726220373270ull,0x325f335f744c2409ull,
0x20202020203b3535ull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6f6d090a3630325full,0x2509203436662e76ull,0x25202c3935316466ull,
0x20203b3535316466ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x202020203b34315full,0x2020202020202020ull,0x744c240a202f2f09ull,0x0a3a3535325f335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c30363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x6f6d090a3630325full,
0x2509203436662e76ull,0x30202c3336316466ull,0x3030303031303064ull,0x3030303030303030ull,
0x2e32202f2f093b30ull,0x332d653730353232ull,0x70746573090a3830ull,0x203436662e746c2eull,
0x25202c3832702509ull,0x25202c3535316466ull,0x2f093b3336316466ull,0x70252140090a202full,
0x0920617262203832ull,0x35325f335f744c24ull,0x2020202020203b38ull,0x200a202f2f092020ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x6f6c2e090a363032ull,
0x3136350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x346430202c343631ull,
0x3030303030303533ull,0x3b30303030303030ull,0x30382e31202f2f09ull,0x0a36312b65343431ull,
0x3436662e6c756d09ull,0x3536316466250920ull,0x353531646625202cull,0x343631646625202cull,
0x6d090a202f2f093bull,0x09203436622e766full,0x72252c393772257bull,0x646625202c7d3731ull,
0x2f2f09203b353631ull,0x09636f6c2e090a20ull,0x3009323635093832ull,0x36622e766f6d090aull,
0x383172257b092034ull,0x202c7d303872252cull,0x203b353631646625ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x34352d202c323272ull,0x202020202020203bull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x2020203b3735325full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x0a3a3835325f335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6f6d090a3630325full,0x2509203233732e76ull,0x203b30202c323272ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x325f335f744c240aull,0x3c2f2f200a3a3735ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,0x3209636f6c2e090aull,
0x0a30093736350938ull,0x3233732e72687309ull,0x202c313872250920ull,0x3032202c37317225ull,
0x092020202020203bull,0x646e61090a202f2full,0x722509203233622eull,0x31387225202c3238ull,
0x203b37343032202cull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c333872250920ull,
0x7225202c32327225ull,0x09202020203b3238ull,0x627573090a202f2full,0x722509203233732eull,
0x33387225202c3232ull,0x203b33323031202cull,0x0a202f2f09202020ull,0x383209636f6c2e09ull,
0x090a300938363509ull,0x203233622e646e61ull,0x25202c3632722509ull,0x31322d202c373172ull,
0x3337303533343634ull,0x6f090a202f2f093bull,0x2509203233622e72ull,0x327225202c343872ull,
0x3632373031202c36ull,0x2f093b3834323339ull,0x2e766f6d090a202full,0x6466250920343662ull,
0x72257b202c363631ull,0x7d343872252c3831ull,0x090a202f2f09203bull,0x203436662e766f6dull,
0x202c313464662509ull,0x203b363631646625ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c373631ull,0x3665393061366666ull,0x3b64636233663736ull,
0x31342e31202f2f09ull,0x746573090a313234ull,0x3436662e74672e70ull,0x202c393270250920ull,
0x202c363631646625ull,0x093b373631646625ull,0x252140090a202f2full,0x2061726220393270ull,
0x325f335f744c2409ull,0x20202020203b3935ull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x6c2e090a3630325full,0x373509383209636full,
0x766f6d090a300930ull,0x257b09203436622eull,0x363872252c353872ull,0x3631646625202c7dull,
0x0a202f2f09203b36ull,0x3233732e62757309ull,0x202c373872250920ull,0x3031202c36387225ull,
0x09203b3637353834ull,0x766f6d090a202f2full,0x257b09203436622eull,0x393872252c383872ull,
0x3631646625202c7dull,0x0a202f2f09203b36ull,0x3436622e766f6d09ull,0x2c31346466250920ull,
0x252c383872257b20ull,0x0920203b7d373872ull,0x6f6c2e090a202f2full,0x3137350938320963ull,
0x2e646461090a3009ull,0x3272250920323373ull,0x2c32327225202c32ull,0x20202020203b3120ull,
0x240a202f2f092020ull,0x3935325f335f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3630325f335full,0x09383209636f6c2eull,0x6d090a3009353835ull,
0x09203436662e766full,0x202c383631646625ull,0x3030306666626430ull,0x3030303030303030ull,
0x2d202f2f093b3030ull,0x662e646461090a31ull,0x3464662509203436ull,0x3134646625202c34ull,
0x383631646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,0x202c393631646625ull,
0x3030306666336430ull,0x3030303030303030ull,0x31202f2f093b3030ull,0x36662e646461090aull,
0x3731646625092034ull,0x3134646625202c30ull,0x393631646625202cull,0x72090a202f2f093bull,
0x09203436662e7063ull,0x25202c3734646625ull,0x20203b3037316466ull,0x2f2f092020202020ull,
0x662e6c756d090a20ull,0x3464662509203436ull,0x3434646625202c38ull,0x3b3734646625202cull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3934646625ull,0x6625202c38346466ull,
0x2f2f09203b383464ull,0x662e6c756d090a20ull,0x3564662509203436ull,0x3934646625202c30ull,
0x3b3934646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,0x202c313731646625ull,
0x3833316265336430ull,0x6630386561336230ull,0x31202f2f093b6531ull,0x2d6533333632302eull,
0x2e766f6d090a3630ull,0x6466250920343666ull,0x336430202c323731ull,0x3835326565306465ull,
0x3b34306238613762ull,0x33302e34202f2f09ull,0x0a36302d65393436ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x646625202c333731ull,0x646625202c313731ull,0x31646625202c3035ull,
0x0a202f2f093b3237ull,0x3436662e766f6d09ull,0x3437316466250920ull,0x336665336430202cull,
0x3230663936363262ull,0x2f2f093b66363736ull,0x34343837382e3120ull,0x616d090a35302d65ull,
0x3436662e6e722e64ull,0x3537316466250920ull,0x333731646625202cull,0x2c3035646625202cull,
0x3b34373164662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x30202c3637316466ull,
0x6335343731663364ull,0x3539306261396162ull,0x2e38202f2f093b36ull,0x302d653138373738ull,
0x722e64616d090a35ull,0x2509203436662e6eull,0x25202c3737316466ull,0x25202c3537316466ull,
0x6625202c30356466ull,0x2f2f093b36373164ull,0x662e766f6d090a20ull,0x3164662509203436ull,
0x66336430202c3837ull,0x6432376331376333ull,0x093b343531356231ull,0x3030302e30202f2full,
0x090a383230343334ull,0x662e6e722e64616dull,0x3564662509203436ull,0x3731646625202c39ull,
0x3035646625202c37ull,0x383731646625202cull,0x2e090a202f2f093bull,0x3509383209636f6cull,
0x6f6d090a30093638ull,0x2509203436662e76ull,0x30202c3937316466ull,0x3239343236663364ull,
0x3237656233323934ull,0x2e30202f2f093b64ull,0x3431323332323030ull,0x6e722e64616d090aull,
0x662509203436662eull,0x646625202c393564ull,0x35646625202c3935ull,0x3731646625202c30ull,
0x090a202f2f093b39ull,0x09383209636f6c2eull,0x6d090a3009373835ull,0x09203436662e766full,
0x202c303831646625ull,0x3939393866336430ull,0x3361393939393939ull,0x30202f2f093b3463ull,
0x6d090a353231302eull,0x36662e6e722e6461ull,0x3935646625092034ull,0x2c3935646625202cull,
0x202c303564662520ull,0x093b303831646625ull,0x6f6c2e090a202f2full,0x3838350938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x336430202c313831ull,0x3535353535356266ull,
0x3b34353535353535ull,0x38302e30202f2f09ull,0x6d090a3333333333ull,0x36662e6e722e6461ull,
0x3935646625092034ull,0x2c3935646625202cull,0x202c303564662520ull,0x093b313831646625ull,
0x6f6c2e090a202f2full,0x3439350938320963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x646625202c323831ull,0x35646625202c3035ull,0x090a202f2f093b39ull,0x203436662e6c756dull,
0x202c393564662509ull,0x25202c3934646625ull,0x2f093b3238316466ull,0x636f6c2e090a202full,
0x0934303609383209ull,0x722e747663090a30ull,0x33732e3436662e6eull,0x3436646625092032ull,
0x203b32327225202cull,0x73090a202f2f0920ull,0x09203436662e6275ull,0x25202c3536646625ull,
0x6625202c34346466ull,0x2f2f09203b393464ull,0x662e766f6d090a20ull,0x3164662509203436ull,
0x66336430202c3338ull,0x6566323465323665ull,0x093b666539336166ull,0x3339362e30202f2full,
0x64616d090a373431ull,0x203436662e6e722eull,0x202c373664662509ull,0x25202c3436646625ull,
0x25202c3338316466ull,0x2f2f093b39346466ull,0x662e766f6d090a20ull,0x3164662509203436ull,
0x63336430202c3438ull,0x6233653963626137ull,0x093b663330383933ull,0x3931332e32202f2full,
0x090a37312d653530ull,0x203436662e67656eull,0x2c35383164662509ull,0x203b393464662520ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x72257b0920343662ull,0x7d313972252c3039ull,
0x3b3536646625202cull,0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3239722509ull,
0x343031202c313972ull,0x2f09203b36373538ull,0x2e766f6d090a202full,0x72257b0920343662ull,
0x7d343972252c3339ull,0x3b3536646625202cull,0x090a202f2f092020ull,0x203436622e766f6dull,
0x2c36383164662509ull,0x252c333972257b20ull,0x2f09203b7d323972ull,0x2e64616d090a202full,
0x09203436662e6e72ull,0x202c373831646625ull,0x202c353831646625ull,0x25202c3434646625ull,
0x2f093b3638316466ull,0x2e64616d090a202full,0x6466250920343666ull,0x646625202c383831ull,
0x646625202c373831ull,0x35646625202c3734ull,0x090a202f2f093b39ull,0x203233732e67656eull,
0x25202c3539722509ull,0x202020203b323272ull,0x2f09202020202020ull,0x2e747663090a202full,
0x732e3436662e6e72ull,0x3164662509203233ull,0x35397225202c3938ull,0x090a202f2f09203bull,
0x203436662e766f6dull,0x2c30393164662509ull,0x3236656633643020ull,0x3361666566323465ull,
0x202f2f093b666539ull,0x3734313339362e30ull,0x6e722e64616d090aull,0x662509203436662eull,
0x6625202c31393164ull,0x6625202c39383164ull,0x6625202c30393164ull,0x202f2f093b373664ull,
0x36662e627573090aull,0x3931646625092034ull,0x3931646625202c32ull,0x3934646625202c31ull,
0x73090a202f2f093bull,0x09203436662e6275ull,0x202c333931646625ull,0x202c383831646625ull,
0x093b323931646625ull,0x64616d090a202f2full,0x203436662e6e722eull,0x202c383764662509ull,
0x25202c3436646625ull,0x25202c3438316466ull,0x2f093b3339316466ull,0x2e646461090a202full,
0x6466250920343666ull,0x646625202c393531ull,0x37646625202c3736ull,0x240a202f2f093b38ull,
0x3a34315f335f744cull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x2e090a3630325f33ull,0x3109383109636f6cull,0x6f6d090a30093033ull,0x2509203436662e76ull,
0x6625202c37326466ull,0x2020203b39353164ull,0x202f2f0920202020ull,0x325f335f744c240aull,
0x3c2f2f200a3a3131ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3630325f335f744cull,
0x3109636f6c2e090aull,0x0a30093233310938ull,0x3436662e766f6d09ull,0x3439316466250920ull,
0x356466336430202cull,0x3465336332333939ull,0x2f2f093b64363330ull,0x37343733332e3020ull,
0x662e766f6d090a35ull,0x3164662509203436ull,0x66336430202c3539ull,0x6663366363336665ull,
0x093b313331636238ull,0x3637392e30202f2full,0x766f6d090a393631ull,0x662509203436662eull,
0x6430202c36393164ull,0x3730353934636633ull,0x3638363039363632ull,0x312e30202f2f093bull,
0x6d090a3839373036ull,0x09203436662e766full,0x202c373931646625ull,0x6534633966336430ull,
0x3234346533376461ull,0x30202f2f093b3733ull,0x393334363732302eull,0x36662e766f6d090aull,
0x3931646625092034ull,0x3666336430202c38ull,0x3335653334363766ull,0x2f093b3538373665ull,
0x383330302e30202full,0x6f6d090a37353034ull,0x2509203436662e76ull,0x30202c3939316466ull,
0x3236653933663364ull,0x3438383961306165ull,0x2e30202f2f093b36ull,0x3931353933303030ull,
0x36662e766f6d090aull,0x3032646625092034ull,0x3066336430202c30ull,0x6635303262656430ull,
0x2f093b3830323835ull,0x363731322e33202full,0x6d090a35302d6538ull,0x09203436662e766full,
0x202c313032646625ull,0x3136333965336430ull,0x6237623930373564ull,0x32202f2f093b3635ull,
0x2d6537313838382eull,0x2e766f6d090a3730ull,0x6466250920343666ull,0x336430202c323032ull,
0x3035633339613965ull,0x3b64613564323061ull,0x36392e33202f2f09ull,0x0a37302d65323330ull,
0x3436662e64616d09ull,0x3330326466250920ull,0x323032646625202cull,0x2c3732646625202cull,
0x3b31303264662520ull,0x616d090a202f2f09ull,0x2509203436662e64ull,0x25202c3430326466ull,
0x6625202c37326466ull,0x6625202c33303264ull,0x2f2f093b30303264ull,0x662e64616d090a20ull,
0x3264662509203436ull,0x32646625202c3530ull,0x3032646625202c37ull,0x3931646625202c34ull,
0x090a202f2f093b39ull,0x203436662e64616dull,0x2c36303264662509ull,0x202c373264662520ull,
0x202c353032646625ull,0x093b383931646625ull,0x64616d090a202f2full,0x662509203436662eull,
0x6625202c37303264ull,0x646625202c373264ull,0x646625202c363032ull,0x202f2f093b373931ull,
0x36662e64616d090aull,0x3032646625092034ull,0x3732646625202c38ull,0x373032646625202cull,
0x363931646625202cull,0x6d090a202f2f093bull,0x09203436662e6461ull,0x202c393032646625ull,
0x25202c3732646625ull,0x25202c3830326466ull,0x2f093b3539316466ull,0x2e64616d090a202full,
0x6466250920343666ull,0x32646625202c3732ull,0x3032646625202c37ull,0x3931646625202c39ull,
0x090a202f2f093b34ull,0x203436662e67656eull,0x2c30313264662509ull,0x203b373264662520ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x6466250920343666ull,0x306430202c313132ull,
0x3030303030303030ull,0x3b30303030303030ull,0x73090a30202f2f09ull,0x662e746c2e707465ull,
0x3033702509203436ull,0x202c36646625202cull,0x093b313132646625ull,0x6c6573090a202f2full,
0x2509203436662e70ull,0x6625202c37326466ull,0x6625202c30313264ull,0x337025202c373264ull,
0x240a202f2f093b30ull,0x3930325f335f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3630325f335full,0x203436662e766f6dull,0x25202c3464662509ull,
0x2020203b37326466ull,0x2f09202020202020ull,0x335f744c240a202full,0x2f2f200a3a31315full,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,
0x2064616568202c30ull,0x2064656c6562616cull,0x30325f335f744c24ull,0x09636f6c2e090a36ull,
0x3009313632093831ull,0x6e722e747663090aull,0x3436662e3233662eull,0x25202c3266250920ull,
0x202020203b346466ull,0x6461090a202f2f09ull,0x2509203436752e64ull,0x647225202c396472ull,
0x3b37647225202c35ull,0x202f2f0920202020ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,
0x302b396472255b09ull,0x203b326625202c5dull,0x313a6469202f2f09ull,0x646461090a343831ull,
0x722509203233752eull,0x202c397225202c37ull,0x202020203b377225ull,0x0a202f2f09202020ull,
0x3436752e64646109ull,0x202c356472250920ull,0x7225202c35647225ull,0x09202020203b3664ull,
0x746573090a202f2full,0x3233752e746c2e70ull,0x202c313370250920ull,0x317225202c377225ull,
0x0a202f2f0920203bull,0x6220313370254009ull,0x5f744c2409206172ull,0x20203b3630325f33ull,
0x0920202020202020ull,0x617262090a202f2full,0x4c240920696e752eull,0x3b3236325f335f74ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x30325f335f744c24ull,0x636f6c2e090a3a33ull,
0x0937363209383109ull,0x34326c756d090a30ull,0x203233752e6f6c2eull,0x25202c3639722509ull,
0x3b337225202c3472ull,0x61090a202f2f0920ull,0x09203233752e6464ull,0x7225202c37397225ull,
0x3b327225202c3639ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3839722509203233ull,
0x203b37397225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,0x752e65672e707465ull,
0x3233702509203233ull,0x202c37397225202cull,0x2f2f09203b317225ull,0x3233702540090a20ull,
0x4c24092061726220ull,0x3b3236325f335f74ull,0x2020202020202020ull,0x63090a202f2f0920ull,
0x752e3436752e7476ull,0x3164722509203233ull,0x3b37397225202c30ull,0x2f2f092020202020ull,
0x752e747663090a20ull,0x09203631752e3233ull,0x6e25202c39397225ull,0x3b782e6469617463ull,
0x6d090a202f2f0920ull,0x2e6f6c2e34326c75ull,0x3172250920323375ull,0x2c347225202c3030ull,
0x2f093b3939722520ull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3131647225ull,
0x3b34202c30316472ull,0x090a202f2f092020ull,0x2e3436732e747663ull,0x6472250920323375ull,
0x30317225202c3231ull,0x2f09202020203b30ull,0x2e646461090a202full,0x3172250920323375ull,
0x2c317225202c3130ull,0x20202020203b3120ull,0x090a202f2f092020ull,0x662e6e722e747663ull,
0x09203233752e3436ull,0x202c323132646625ull,0x2f093b3130317225ull,0x2e706372090a202full,
0x6466250920343666ull,0x646625202c333132ull,0x202020203b323132ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3164722509203436ull,0x3231647225202c33ull,0x2f0920203b34202cull,
0x702e646c090a202full,0x3436752e6d617261ull,0x2c34316472250920ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x65737265766e6936ull,0x656e72654b444e43ull,0x645f6a5f5366506cull,
0x5d74757074754f5full,0x3a6469202f2f093bull,0x635f5f2034373131ull,0x5f6d726170616475ull,
0x65766e6936315a5full,0x654b444e43657372ull,0x5f5366506c656e72ull,0x7074754f5f645f6aull,
0x240a3078302b7475ull,0x3436325f335f744cull,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,
0x696c2079646f6220ull,0x090a39363220656eull,0x09383109636f6c2eull,0x61090a3009393632ull,
0x09203233752e6464ull,0x25202c3230317225ull,0x203b31202c383972ull,0x2f2f092020202020ull,
0x722e747663090a20ull,0x33752e3436662e6eull,0x3132646625092032ull,0x3230317225202c34ull,
0x6d090a202f2f093bull,0x09203436662e6c75ull,0x202c353132646625ull,0x202c343132646625ull,
0x093b333132646625ull,0x766f6d090a202f2full,0x662509203436662eull,0x6430202c36313264ull,
0x3030303030666633ull,0x3030303030303030ull,0x090a31202f2f093bull,0x752e65672e746573ull,
0x09203436662e3233ull,0x25202c3330317225ull,0x25202c3531326466ull,0x2f093b3631326466ull,
0x2e67656e090a202full,0x3172250920323373ull,0x30317225202c3430ull,0x2020202020203b33ull,
0x090a202f2f092020ull,0x203436662e766f6dull,0x2c37313264662509ull,0x3030303030643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x6c2e746573090a30ull,0x36662e3233752e65ull,
0x3530317225092034ull,0x353132646625202cull,0x373132646625202cull,0x6e090a202f2f093bull,
0x09203233732e6765ull,0x25202c3630317225ull,0x2020203b35303172ull,0x2f2f092020202020ull,
0x33622e726f090a20ull,0x3730317225092032ull,0x2c3430317225202cull,0x203b363031722520ull,
0x6d090a202f2f0920ull,0x09203233752e766full,0x30202c3830317225ull,0x202020202020203bull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e7165ull,0x7225202c33337025ull,
0x317225202c373031ull,0x0a202f2f093b3830ull,0x6220333370254009ull,0x5f744c2409206172ull,
0x20203b3536325f33ull,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3436325f335f744cull,0x36662e766f6d090aull,0x3132646625092034ull,
0x6666666430202c38ull,0x3030303030303038ull,0x2f093b3030303030ull,0x62090a6e616e202full,
0x0920696e752e6172ull,0x3b315f335f744c24ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x5f335f744c240a20ull,0x2f2f200a3a353632ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,
0x36325f335f744c24ull,0x09636f6c2e090a34ull,0x3009333231093831ull,0x36662e766f6d090aull,
0x3132646625092034ull,0x6566626430202c39ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x090a352e302d202full,0x203436662e646461ull,0x2c30323264662509ull,0x2c35313264662520ull,
0x3b39313264662520ull,0x6261090a202f2f09ull,0x2509203436662e73ull,0x25202c3132326466ull,
0x20203b3032326466ull,0x202f2f0920202020ull,0x36662e766f6d090aull,0x3232646625092034ull,
0x6466336430202c32ull,0x3165613734316561ull,0x2f093b3165613734ull,0x090a32342e30202full,
0x2e746c2e70746573ull,0x3370250920343666ull,0x3232646625202c34ull,0x3232646625202c31ull,
0x090a202f2f093b32ull,0x6220343370252140ull,0x5f744c2409206172ull,0x20203b3836325f33ull,
0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x0a3436325f335f74ull,0x383109636f6c2e09ull,0x090a300935323109ull,0x203436662e6c756dull,
0x2c33323264662509ull,0x2c30323264662520ull,0x3b30323264662520ull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3432326466ull,0x3964303430303464ull,0x3032363832623133ull,
0x2e32202f2f093b64ull,0x6d090a3336363035ull,0x09203436662e766full,0x202c353232646625ull,
0x6439323330636430ull,0x3361343565613037ull,0x2d202f2f093b6564ull,0x090a3531362e3831ull,
0x203436662e766f6dull,0x2c36323264662509ull,0x6234343034643020ull,0x6333373463323132ull,
0x202f2f093b636636ull,0x0a323139332e3134ull,0x3436662e766f6d09ull,0x3732326466250920ull,
0x393330636430202cull,0x3733373539653037ull,0x2f2f093b38373737ull,0x3134342e35322d20ull,
0x662e64616d090a31ull,0x3264662509203436ull,0x32646625202c3832ull,0x32646625202c3332ull,
0x32646625202c3732ull,0x0a202f2f093b3632ull,0x3436662e64616d09ull,0x3932326466250920ull,
0x383232646625202cull,0x333232646625202cull,0x353232646625202cull,0x6d090a202f2f093bull,
0x09203436662e6461ull,0x202c303332646625ull,0x202c393232646625ull,0x202c333232646625ull,
0x093b343232646625ull,0x6c756d090a202f2full,0x662509203436662eull,0x6625202c31333264ull,
0x6625202c30323264ull,0x2f2f093b30333264ull,0x662e766f6d090a20ull,0x3264662509203436ull,
0x66336430202c3233ull,0x3030303030303066ull,0x093b303030303030ull,0x6f6d090a31202f2full,
0x2509203436662e76ull,0x30202c3333326466ull,0x3732663032306364ull,0x3237303535363030ull,
0x382d202f2f093b64ull,0x090a31353337342eull,0x203436662e766f6dull,0x2c34333264662509ull,
0x3137333034643020ull,0x3531383139373535ull,0x202f2f093b633230ull,0x0a343338302e3332ull,
0x3436662e766f6d09ull,0x3533326466250920ull,0x353330636430202cull,0x3130373066656630ull,
0x2f2f093b64373565ull,0x3236302e31322d20ull,0x662e766f6d090a32ull,0x3264662509203436ull,
0x30346430202c3633ull,0x3032306662303930ull,0x093b373461383535ull,0x3033312e33202f2full,
0x2e64616d090a3338ull,0x6466250920343666ull,0x646625202c373332ull,0x646625202c333232ull,
0x646625202c363332ull,0x202f2f093b353332ull,0x36662e64616d090aull,0x3332646625092034ull,
0x3332646625202c38ull,0x3232646625202c37ull,0x3332646625202c33ull,0x090a202f2f093b34ull,
0x203436662e64616dull,0x2c39333264662509ull,0x2c38333264662520ull,0x2c33323264662520ull,
0x3b33333264662520ull,0x616d090a202f2f09ull,0x2509203436662e64ull,0x25202c3034326466ull,
0x25202c3933326466ull,0x25202c3332326466ull,0x2f093b3233326466ull,0x2e766964090a202full,
0x6466250920343666ull,0x32646625202c3732ull,0x32646625202c3133ull,0x0a202f2f093b3034ull,
0x696e752e61726209ull,0x5f335f744c240920ull,0x202020203b373632ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x200a3a3836325f33ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x766f6d090a343632ull,0x662509203436662eull,0x6430202c31343264ull,
0x3030303030303030ull,0x3030303030303030ull,0x090a30202f2f093bull,0x2e74672e70746573ull,
0x3370250920343666ull,0x3232646625202c35ull,0x3432646625202c30ull,0x090a202f2f093b31ull,
0x6220353370252140ull,0x5f744c2409206172ull,0x20203b3037325f33ull,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x383209636f6c2e09ull,0x090a300930343509ull,0x203436662e766f6dull,0x2c32343264662509ull,
0x3030666633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x662e627573090a31ull,
0x3264662509203436ull,0x32646625202c3334ull,0x32646625202c3234ull,0x0a202f2f093b3531ull,
0x3436622e766f6d09ull,0x39303172257b0920ull,0x202c7d373172252cull,0x093b333432646625ull,
0x6f6c2e090a202f2full,0x3134350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,
0x30313172252c3831ull,0x3432646625202c7dull,0x090a202f2f093b33ull,0x09383209636f6c2eull,
0x61090a3009323435ull,0x09203436662e7362ull,0x202c343432646625ull,0x203b333432646625ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3264662509203436ull,0x66376430202c3534ull,
0x3030303030303066ull,0x093b303030303030ull,0x090a666e69202f2full,0x2e656c2e70746573ull,
0x3370250920343666ull,0x3432646625202c36ull,0x3432646625202c34ull,0x090a202f2f093b35ull,
0x7262203633702540ull,0x335f744c24092061ull,0x2020203b3137325full,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x3436662e64646109ull,0x2c33336466250920ull,0x2c33343264662520ull,0x3b33343264662520ull,
0x7262090a202f2f09ull,0x240920696e752e61ull,0x203b365f335f744cull,0x2020202020202020ull,
0x202f2f0920202020ull,0x325f335f744c240aull,0x3c2f2f200a3a3137ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3436325f335f744cull,0x36662e766f6d090aull,0x3432646625092034ull,
0x3030306430202c36ull,0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a30202full,
0x3436662e746c2e70ull,0x202c373370250920ull,0x202c333432646625ull,0x093b363432646625ull,
0x252140090a202f2full,0x2061726220373370ull,0x325f335f744c2409ull,0x20202020203b3337ull,
0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x6f6d090a3436325full,0x2509203436662e76ull,0x6430202c33336466ull,0x3030303038666666ull,
0x3030303030303030ull,0x6e616e202f2f093bull,0x6e752e617262090aull,0x335f744c24092069ull,
0x20202020203b365full,0x2020202020202020ull,0x744c240a202f2f09ull,0x0a3a3337325f335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x6f6d090a3436325full,
0x2509203436662e76ull,0x30202c3734326466ull,0x3030303030303064ull,0x3030303030303030ull,
0x0a30202f2f093b30ull,0x71652e7074657309ull,0x702509203436662eull,0x32646625202c3833ull,
0x32646625202c3334ull,0x0a202f2f093b3734ull,0x2038337025214009ull,0x744c240920617262ull,
0x203b3537325f335full,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3436325f335f744cull,0x36662e766f6d090aull,0x3333646625092034ull,
0x306666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x62090a666e692d20ull,
0x0920696e752e6172ull,0x3b365f335f744c24ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x5f335f744c240a20ull,0x2f2f200a3a353732ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,
0x36325f335f744c24ull,0x09636f6c2e090a34ull,0x3009343535093832ull,0x36662e766f6d090aull,
0x3432646625092034ull,0x6666376430202c38ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x73090a666e69202full,0x662e71652e707465ull,0x3933702509203436ull,0x343432646625202cull,
0x383432646625202cull,0x40090a202f2f093bull,0x7262203933702521ull,0x335f744c24092061ull,
0x2020203b3737325full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3436325f335full,0x203436662e766f6dull,0x202c333364662509ull,
0x203b333432646625ull,0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,
0x2020203b365f335full,0x2020202020202020ull,0x240a202f2f092020ull,0x3737325f335f744cull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x090a3436325f335full,
0x203436662e766f6dull,0x2c39343264662509ull,0x3030313030643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x6537303532322e32ull,0x6573090a3830332dull,0x36662e746c2e7074ull,
0x2c30347025092034ull,0x2c33343264662520ull,0x3b39343264662520ull,0x2140090a202f2f09ull,
0x6172622030347025ull,0x5f335f744c240920ull,0x202020203b303832ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3436325f33ull,
0x3509383209636f6cull,0x6f6d090a30093136ull,0x2509203436662e76ull,0x30202c3035326466ull,
0x3030303035333464ull,0x3030303030303030ull,0x2e31202f2f093b30ull,0x312b653434313038ull,
0x662e6c756d090a36ull,0x3264662509203436ull,0x32646625202c3135ull,0x32646625202c3334ull,
0x0a202f2f093b3035ull,0x3436622e766f6d09ull,0x31313172257b0920ull,0x202c7d373172252cull,
0x093b313532646625ull,0x6f6c2e090a202f2full,0x3236350938320963ull,0x2e766f6d090a3009ull,
0x72257b0920343662ull,0x32313172252c3831ull,0x3532646625202c7dull,0x090a202f2f093b31ull,
0x203233732e766f6dull,0x2d202c3232722509ull,0x20202020203b3435ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x203b3937325f335full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3038325f335f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3436325f335full,0x203233732e766f6dull,0x30202c3232722509ull,
0x202020202020203bull,0x2f09202020202020ull,0x335f744c240a202full,0x2f200a3a3937325full,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3936ull,0x64656c6562616c20ull,0x325f335f744c2420ull,0x636f6c2e090a3436ull,
0x0937363509383209ull,0x732e726873090a30ull,0x3131722509203233ull,0x2c37317225202c33ull,
0x202020203b303220ull,0x61090a202f2f0920ull,0x09203233622e646eull,0x25202c3431317225ull,
0x3032202c33313172ull,0x2f2f0920203b3734ull,0x732e646461090a20ull,0x3131722509203233ull,
0x2c32327225202c35ull,0x203b343131722520ull,0x73090a202f2f0920ull,0x09203233732e6275ull,
0x7225202c32327225ull,0x323031202c353131ull,0x2f2f092020203b33ull,0x09636f6c2e090a20ull,
0x3009383635093832ull,0x33622e646e61090aull,0x2c36327225092032ull,0x2d202c3731722520ull,
0x3035333436343132ull,0x0a202f2f093b3337ull,0x203233622e726f09ull,0x202c363131722509ull,
0x3031202c36327225ull,0x3834323339363237ull,0x6d090a202f2f093bull,0x09203436622e766full,
0x202c323532646625ull,0x72252c383172257bull,0x2f2f093b7d363131ull,0x662e766f6d090a20ull,
0x3464662509203436ull,0x3532646625202c31ull,0x2020202020203b32ull,0x6d090a202f2f0920ull,
0x09203436662e766full,0x202c333532646625ull,0x3061366666336430ull,0x6233663736366539ull,
0x31202f2f093b6463ull,0x090a31323431342eull,0x2e74672e70746573ull,0x3470250920343666ull,
0x3532646625202c31ull,0x3532646625202c32ull,0x090a202f2f093b33ull,0x6220313470252140ull,
0x5f744c2409206172ull,0x20203b3138325f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,0x383209636f6c2e09ull,
0x090a300930373509ull,0x203436622e766f6dull,0x2c37313172257b09ull,0x202c7d3831317225ull,
0x093b323532646625ull,0x627573090a202f2full,0x722509203233732eull,0x317225202c393131ull,
0x38343031202c3831ull,0x202f2f093b363735ull,0x36622e766f6d090aull,0x323172257b092034ull,
0x7d31323172252c30ull,0x323532646625202cull,0x6d090a202f2f093bull,0x09203436622e766full,
0x7b202c3134646625ull,0x72252c3032317225ull,0x2f2f093b7d393131ull,0x09636f6c2e090a20ull,
0x3009313735093832ull,0x33732e646461090aull,0x2c32327225092032ull,0x31202c3232722520ull,
0x202020202020203bull,0x744c240a202f2f09ull,0x0a3a3138325f335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x6c2e090a3436325full,0x383509383209636full,
0x766f6d090a300935ull,0x662509203436662eull,0x6430202c34353264ull,0x3030303030666662ull,
0x3030303030303030ull,0x0a312d202f2f093bull,0x3436662e64646109ull,0x2c34346466250920ull,
0x202c313464662520ull,0x093b343532646625ull,0x766f6d090a202f2full,0x662509203436662eull,
0x6430202c35353264ull,0x3030303030666633ull,0x3030303030303030ull,0x090a31202f2f093bull,
0x203436662e646461ull,0x2c36353264662509ull,0x202c313464662520ull,0x093b353532646625ull,
0x706372090a202f2full,0x662509203436662eull,0x646625202c373464ull,0x202020203b363532ull,
0x0a202f2f09202020ull,0x3436662e6c756d09ull,0x2c38346466250920ull,0x202c343464662520ull,
0x09203b3734646625ull,0x646461090a202f2full,0x662509203436662eull,0x646625202c393464ull,
0x34646625202c3834ull,0x0a202f2f09203b38ull,0x3436662e6c756d09ull,0x2c30356466250920ull,
0x202c393464662520ull,0x09203b3934646625ull,0x766f6d090a202f2full,0x662509203436662eull,
0x6430202c37353264ull,0x6230383331626533ull,0x6531663038656133ull,0x302e31202f2f093bull,
0x36302d6533333632ull,0x36662e766f6d090aull,0x3532646625092034ull,0x6465336430202c38ull,
0x3762383532656530ull,0x2f093b3430623861ull,0x343633302e34202full,0x6d090a36302d6539ull,
0x36662e6e722e6461ull,0x3532646625092034ull,0x3532646625202c39ull,0x3035646625202c37ull,
0x383532646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,0x202c303632646625ull,
0x3262336665336430ull,0x3736323066393636ull,0x31202f2f093b6636ull,0x2d6534343837382eull,
0x2e64616d090a3530ull,0x09203436662e6e72ull,0x202c313632646625ull,0x202c393532646625ull,
0x25202c3035646625ull,0x2f093b3036326466ull,0x2e766f6d090a202full,0x6466250920343666ull,
0x336430202c323632ull,0x6162633534373166ull,0x3b36353930626139ull,0x37382e38202f2f09ull,
0x0a35302d65313837ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x646625202c333632ull,
0x646625202c313632ull,0x32646625202c3035ull,0x0a202f2f093b3236ull,0x3436662e766f6d09ull,
0x3436326466250920ull,0x633366336430202cull,0x6231643237633137ull,0x2f2f093b34353135ull,
0x33343030302e3020ull,0x616d090a38323034ull,0x3436662e6e722e64ull,0x2c39356466250920ull,
0x2c33363264662520ull,0x202c303564662520ull,0x093b343632646625ull,0x6f6c2e090a202f2full,
0x3638350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x336430202c353632ull,
0x3934323934323666ull,0x3b64323765623332ull,0x30302e30202f2f09ull,0x090a343132333232ull,
0x662e6e722e64616dull,0x3564662509203436ull,0x3935646625202c39ull,0x2c3035646625202cull,
0x3b35363264662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,0x766f6d090a300937ull,
0x662509203436662eull,0x6430202c36363264ull,0x3939393939386633ull,0x3463336139393939ull,
0x302e30202f2f093bull,0x64616d090a353231ull,0x203436662e6e722eull,0x202c393564662509ull,
0x25202c3935646625ull,0x6625202c30356466ull,0x2f2f093b36363264ull,0x09636f6c2e090a20ull,
0x3009383835093832ull,0x36662e766f6d090aull,0x3632646625092034ull,0x6266336430202c37ull,
0x3535353535353535ull,0x2f093b3435353535ull,0x333338302e30202full,0x64616d090a333333ull,
0x203436662e6e722eull,0x202c393564662509ull,0x25202c3935646625ull,0x6625202c30356466ull,
0x2f2f093b37363264ull,0x09636f6c2e090a20ull,0x3009343935093832ull,0x36662e6c756d090aull,
0x3632646625092034ull,0x3035646625202c38ull,0x3b3935646625202cull,0x756d090a202f2f09ull,
0x2509203436662e6cull,0x6625202c39356466ull,0x646625202c393464ull,0x202f2f093b383632ull,
0x3209636f6c2e090aull,0x0a30093430360938ull,0x2e6e722e74766309ull,0x203233732e343666ull,
0x202c343664662509ull,0x0920203b32327225ull,0x627573090a202f2full,0x662509203436662eull,
0x646625202c353664ull,0x34646625202c3434ull,0x0a202f2f09203b39ull,0x3436662e766f6d09ull,
0x3936326466250920ull,0x366566336430202cull,0x6166656632346532ull,0x2f2f093b66653933ull,
0x34313339362e3020ull,0x722e64616d090a37ull,0x2509203436662e6eull,0x6625202c37366466ull,
0x646625202c343664ull,0x646625202c393632ull,0x0a202f2f093b3934ull,0x3436662e766f6d09ull,
0x3037326466250920ull,0x613763336430202cull,0x3933623365396362ull,0x2f2f093b66333038ull,
0x35303931332e3220ull,0x656e090a37312d65ull,0x2509203436662e67ull,0x25202c3137326466ull,
0x2020203b39346466ull,0x202f2f0920202020ull,0x36622e766f6d090aull,0x323172257b092034ull,
0x7d33323172252c32ull,0x3b3536646625202cull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x7225202c34323172ull,0x343031202c333231ull,0x2f2f093b36373538ull,0x622e766f6d090a20ull,
0x3172257b09203436ull,0x36323172252c3532ull,0x3536646625202c7dull,0x6d090a202f2f093bull,
0x09203436622e766full,0x202c323732646625ull,0x252c35323172257bull,0x2f093b7d34323172ull,
0x2e64616d090a202full,0x09203436662e6e72ull,0x202c333732646625ull,0x202c313732646625ull,
0x25202c3434646625ull,0x2f093b3237326466ull,0x2e64616d090a202full,0x6466250920343666ull,
0x646625202c343732ull,0x646625202c333732ull,0x35646625202c3734ull,0x090a202f2f093b39ull,
0x203233732e67656eull,0x202c373231722509ull,0x2020203b32327225ull,0x2f09202020202020ull,
0x2e747663090a202full,0x732e3436662e6e72ull,0x3264662509203233ull,0x32317225202c3537ull,
0x090a202f2f093b37ull,0x203436662e766f6dull,0x2c36373264662509ull,0x3236656633643020ull,
0x3361666566323465ull,0x202f2f093b666539ull,0x3734313339362e30ull,0x6e722e64616d090aull,
0x662509203436662eull,0x6625202c37373264ull,0x6625202c35373264ull,0x6625202c36373264ull,
0x202f2f093b373664ull,0x36662e627573090aull,0x3732646625092034ull,0x3732646625202c38ull,
0x3934646625202c37ull,0x73090a202f2f093bull,0x09203436662e6275ull,0x202c393732646625ull,
0x202c343732646625ull,0x093b383732646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x202c383764662509ull,0x25202c3436646625ull,0x25202c3037326466ull,0x2f093b3937326466ull,
0x2e646461090a202full,0x6466250920343666ull,0x36646625202c3333ull,0x3837646625202c37ull,
0x240a202f2f09203bull,0x0a3a365f335f744cull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6c2e090a3436325full,0x343509383209636full,0x67656e090a300930ull,
0x662509203436662eull,0x6625202c30383264ull,0x202020203b333364ull,0x0a202f2f09202020ull,
0x3436622e766f6d09ull,0x38323172257b0920ull,0x202c7d373172252cull,0x093b303832646625ull,
0x6f6c2e090a202f2full,0x3134350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,
0x39323172252c3831ull,0x3832646625202c7dull,0x090a202f2f093b30ull,0x09383209636f6c2eull,
0x61090a3009323435ull,0x09203436662e7362ull,0x202c313832646625ull,0x20203b3333646625ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3264662509203436ull,0x66376430202c3238ull,
0x3030303030303066ull,0x093b303030303030ull,0x090a666e69202f2full,0x2e656c2e70746573ull,
0x3470250920343666ull,0x3832646625202c32ull,0x3832646625202c31ull,0x090a202f2f093b32ull,
0x7262203234702540ull,0x335f744c24092061ull,0x2020203b3338325full,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x3436662e64646109ull,0x3338326466250920ull,0x2c3333646625202cull,0x093b333364662520ull,
0x67656e090a202f2full,0x662509203436662eull,0x646625202c333864ull,0x202020203b333832ull,
0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f335f744c240920ull,0x2020202020203b38ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x200a3a3338325f33ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x766f6d090a343632ull,0x662509203436662eull,
0x6430202c34383264ull,0x3030303030303030ull,0x3030303030303030ull,0x090a30202f2f093bull,
0x2e746c2e70746573ull,0x3470250920343666ull,0x3832646625202c33ull,0x3832646625202c30ull,
0x090a202f2f093b34ull,0x6220333470252140ull,0x5f744c2409206172ull,0x20203b3538325f33ull,
0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x0a3436325f335f74ull,0x3436662e766f6d09ull,0x2c33386466250920ull,0x3038666666643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x617262090a6e616eull,0x4c240920696e752eull,
0x20203b385f335f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x38325f335f744c24ull,
0x6c3c2f2f200a3a35ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x3436662e766f6d09ull,0x3538326466250920ull,0x303030306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e71652eull,0x25202c3434702509ull,
0x25202c3038326466ull,0x2f093b3538326466ull,0x70252140090a202full,0x0920617262203434ull,
0x38325f335f744c24ull,0x2020202020203b37ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x766f6d090a343632ull,0x662509203436662eull,
0x666430202c333864ull,0x3030303030306666ull,0x3b30303030303030ull,0x666e692d202f2f09ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x20202020203b385full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x0a3a3738325f335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x6c2e090a3436325full,0x353509383209636full,0x766f6d090a300934ull,
0x662509203436662eull,0x6430202c36383264ull,0x3030303030666637ull,0x3030303030303030ull,
0x666e69202f2f093bull,0x652e70746573090aull,0x2509203436662e71ull,0x646625202c353470ull,
0x646625202c313832ull,0x202f2f093b363832ull,0x353470252140090aull,0x4c24092061726220ull,
0x3b3938325f335f74ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,
0x2064656c6562616cull,0x36325f335f744c24ull,0x662e766f6d090a34ull,0x3864662509203436ull,
0x3832646625202c33ull,0x2020202020203b30ull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x3b385f335f744c24ull,0x2020202020202020ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x2f2f200a3a393832ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363220656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,0x36325f335f744c24ull,
0x662e766f6d090a34ull,0x3264662509203436ull,0x30306430202c3738ull,0x3030303030303031ull,
0x093b303030303030ull,0x3532322e32202f2full,0x0a3830332d653730ull,0x746c2e7074657309ull,
0x702509203436662eull,0x32646625202c3634ull,0x32646625202c3038ull,0x0a202f2f093b3738ull,
0x2036347025214009ull,0x744c240920617262ull,0x203b3239325f335full,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3436325f335f744cull,
0x3209636f6c2e090aull,0x0a30093136350938ull,0x3436662e766f6d09ull,0x3838326466250920ull,
0x303533346430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x34343130382e3120ull,
0x756d090a36312b65ull,0x2509203436662e6cull,0x25202c3938326466ull,0x25202c3038326466ull,
0x2f093b3838326466ull,0x2e766f6d090a202full,0x72257b0920343662ull,0x373172252c303331ull,
0x3832646625202c7dull,0x090a202f2f093b39ull,0x09383209636f6c2eull,0x6d090a3009323635ull,
0x09203436622e766full,0x72252c383172257bull,0x6625202c7d313331ull,0x2f2f093b39383264ull,
0x732e766f6d090a20ull,0x3232722509203233ull,0x20203b34352d202cull,0x2020202020202020ull,
0x62090a202f2f0920ull,0x0920696e752e6172ull,0x39325f335f744c24ull,0x2020202020203b31ull,
0x2f2f092020202020ull,0x5f335f744c240a20ull,0x2f2f200a3a323932ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,
0x2064656c6562616cull,0x36325f335f744c24ull,0x732e766f6d090a34ull,0x3232722509203233ull,
0x202020203b30202cull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x3a3139325f335f74ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3436325f33ull,
0x3509383209636f6cull,0x6873090a30093736ull,0x2509203233732e72ull,0x7225202c32333172ull,
0x203b3032202c3731ull,0x202f2f0920202020ull,0x33622e646e61090aull,0x3333317225092032ull,
0x2c3233317225202cull,0x20203b3734303220ull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x7225202c34333172ull,0x33317225202c3232ull,0x202f2f0920203b33ull,0x33732e627573090aull,
0x2c32327225092032ull,0x202c343331722520ull,0x2020203b33323031ull,0x6c2e090a202f2f09ull,
0x363509383209636full,0x646e61090a300938ull,0x722509203233622eull,0x37317225202c3632ull,
0x34363431322d202cull,0x2f093b3337303533ull,0x622e726f090a202full,0x3331722509203233ull,
0x2c36327225202c35ull,0x3339363237303120ull,0x202f2f093b383432ull,0x36622e766f6d090aull,
0x3932646625092034ull,0x383172257b202c30ull,0x3b7d35333172252cull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x6625202c31346466ull,0x2020203b30393264ull,0x202f2f0920202020ull,
0x36662e766f6d090aull,0x3932646625092034ull,0x6666336430202c31ull,0x3736366539306136ull,
0x2f093b6463623366ull,0x323431342e31202full,0x2e70746573090a31ull,0x09203436662e7467ull,
0x6625202c37347025ull,0x6625202c30393264ull,0x2f2f093b31393264ull,0x3470252140090a20ull,
0x2409206172622037ull,0x3339325f335f744cull,0x202020202020203bull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3936ull,0x64656c6562616c20ull,0x325f335f744c2420ull,0x636f6c2e090a3436ull,
0x0930373509383209ull,0x622e766f6d090a30ull,0x3172257b09203436ull,0x37333172252c3633ull,
0x3932646625202c7dull,0x090a202f2f093b30ull,0x203233732e627573ull,0x202c383331722509ull,
0x31202c3733317225ull,0x093b363735383430ull,0x766f6d090a202f2full,0x257b09203436622eull,
0x3172252c39333172ull,0x646625202c7d3034ull,0x202f2f093b303932ull,0x36622e766f6d090aull,
0x3134646625092034ull,0x39333172257b202cull,0x3b7d38333172252cull,0x6c2e090a202f2f09ull,
0x373509383209636full,0x646461090a300931ull,0x722509203233732eull,0x32327225202c3232ull,
0x202020203b31202cull,0x0a202f2f09202020ull,0x39325f335f744c24ull,0x6c3c2f2f200a3a33ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,0x383209636f6c2e09ull,
0x090a300935383509ull,0x203436662e766f6dull,0x2c32393264662509ull,0x3030666662643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x2e646461090a312dull,0x6466250920343666ull,
0x34646625202c3434ull,0x3932646625202c31ull,0x090a202f2f093b32ull,0x203436662e766f6dull,
0x2c33393264662509ull,0x3030666633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x662e646461090a31ull,0x3264662509203436ull,0x34646625202c3439ull,0x3932646625202c31ull,
0x090a202f2f093b33ull,0x203436662e706372ull,0x202c373464662509ull,0x203b343932646625ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x6466250920343666ull,0x34646625202c3834ull,
0x3734646625202c34ull,0x090a202f2f09203bull,0x203436662e646461ull,0x202c393464662509ull,
0x25202c3834646625ull,0x2f09203b38346466ull,0x2e6c756d090a202full,0x6466250920343666ull,
0x34646625202c3035ull,0x3934646625202c39ull,0x090a202f2f09203bull,0x203436662e766f6dull,
0x2c35393264662509ull,0x3331626533643020ull,0x3038656133623038ull,0x202f2f093b653166ull,
0x6533333632302e31ull,0x766f6d090a36302dull,0x662509203436662eull,0x6430202c36393264ull,
0x3532656530646533ull,0x3430623861376238ull,0x302e34202f2f093bull,0x36302d6539343633ull,
0x6e722e64616d090aull,0x662509203436662eull,0x6625202c37393264ull,0x6625202c35393264ull,
0x646625202c303564ull,0x202f2f093b363932ull,0x36662e766f6d090aull,0x3932646625092034ull,
0x6665336430202c38ull,0x3066393636326233ull,0x2f093b6636373632ull,0x343837382e31202full,
0x6d090a35302d6534ull,0x36662e6e722e6461ull,0x3932646625092034ull,0x3932646625202c39ull,
0x3035646625202c37ull,0x383932646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,
0x202c303033646625ull,0x3534373166336430ull,0x3930626139616263ull,0x38202f2f093b3635ull,
0x2d6531383737382eull,0x2e64616d090a3530ull,0x09203436662e6e72ull,0x202c313033646625ull,
0x202c393932646625ull,0x25202c3035646625ull,0x2f093b3030336466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c323033ull,0x3237633137633366ull,0x3b34353135623164ull,
0x30302e30202f2f09ull,0x0a38323034333430ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x33646625202c3935ull,0x35646625202c3130ull,0x3033646625202c30ull,0x090a202f2f093b32ull,
0x09383209636f6c2eull,0x6d090a3009363835ull,0x09203436662e766full,0x202c333033646625ull,
0x3934323666336430ull,0x3765623332393432ull,0x30202f2f093b6432ull,0x313233323230302eull,
0x722e64616d090a34ull,0x2509203436662e6eull,0x6625202c39356466ull,0x646625202c393564ull,
0x33646625202c3035ull,0x0a202f2f093b3330ull,0x383209636f6c2e09ull,0x090a300937383509ull,
0x203436662e766f6dull,0x2c34303364662509ull,0x3939386633643020ull,0x6139393939393939ull,
0x202f2f093b346333ull,0x090a353231302e30ull,0x662e6e722e64616dull,0x3564662509203436ull,
0x3935646625202c39ull,0x2c3035646625202cull,0x3b34303364662520ull,0x6c2e090a202f2f09ull,
0x383509383209636full,0x766f6d090a300938ull,0x662509203436662eull,0x6430202c35303364ull,
0x3535353535626633ull,0x3435353535353535ull,0x302e30202f2f093bull,0x090a333333333338ull,
0x662e6e722e64616dull,0x3564662509203436ull,0x3935646625202c39ull,0x2c3035646625202cull,
0x3b35303364662520ull,0x6c2e090a202f2f09ull,0x393509383209636full,0x6c756d090a300934ull,
0x662509203436662eull,0x6625202c36303364ull,0x646625202c303564ull,0x0a202f2f093b3935ull,
0x3436662e6c756d09ull,0x2c39356466250920ull,0x202c393464662520ull,0x093b363033646625ull,
0x6f6c2e090a202f2full,0x3430360938320963ull,0x2e747663090a3009ull,0x732e3436662e6e72ull,
0x3664662509203233ull,0x3b32327225202c34ull,0x090a202f2f092020ull,0x203436662e627573ull,
0x202c353664662509ull,0x25202c3434646625ull,0x2f09203b39346466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c373033ull,0x6632346532366566ull,0x3b66653933616665ull,
0x39362e30202f2f09ull,0x616d090a37343133ull,0x3436662e6e722e64ull,0x2c37366466250920ull,
0x202c343664662520ull,0x202c373033646625ull,0x2f093b3934646625ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c383033ull,0x3365396362613763ull,0x3b66333038393362ull,
0x31332e32202f2f09ull,0x0a37312d65353039ull,0x3436662e67656e09ull,0x3930336466250920ull,
0x3b3934646625202cull,0x0920202020202020ull,0x766f6d090a202f2full,0x257b09203436622eull,
0x3172252c31343172ull,0x646625202c7d3234ull,0x0a202f2f093b3536ull,0x3233732e64646109ull,
0x2c33343172250920ull,0x202c323431722520ull,0x3b36373538343031ull,0x6f6d090a202f2f09ull,
0x7b09203436622e76ull,0x72252c3434317225ull,0x6625202c7d353431ull,0x202f2f093b353664ull,
0x36622e766f6d090aull,0x3133646625092034ull,0x343172257b202c30ull,0x7d33343172252c34ull,
0x6d090a202f2f093bull,0x36662e6e722e6461ull,0x3133646625092034ull,0x3033646625202c31ull,
0x3434646625202c39ull,0x303133646625202cull,0x6d090a202f2f093bull,0x09203436662e6461ull,
0x202c323133646625ull,0x202c313133646625ull,0x25202c3734646625ull,0x2f2f093b39356466ull,
0x732e67656e090a20ull,0x3431722509203233ull,0x3b32327225202c36ull,0x2020202020202020ull,
0x63090a202f2f0920ull,0x36662e6e722e7476ull,0x2509203233732e34ull,0x25202c3331336466ull,
0x2f2f093b36343172ull,0x662e766f6d090a20ull,0x3364662509203436ull,0x66336430202c3431ull,
0x6566323465323665ull,0x093b666539336166ull,0x3339362e30202f2full,0x64616d090a373431ull,
0x203436662e6e722eull,0x2c35313364662509ull,0x2c33313364662520ull,0x2c34313364662520ull,
0x093b373664662520ull,0x627573090a202f2full,0x662509203436662eull,0x6625202c36313364ull,
0x6625202c35313364ull,0x202f2f093b393464ull,0x36662e627573090aull,0x3133646625092034ull,
0x3133646625202c37ull,0x3133646625202c32ull,0x090a202f2f093b36ull,0x662e6e722e64616dull,
0x3764662509203436ull,0x3436646625202c38ull,0x383033646625202cull,0x373133646625202cull,
0x61090a202f2f093bull,0x09203436662e6464ull,0x25202c3338646625ull,0x6625202c37366466ull,
0x2f2f09203b383764ull,0x5f335f744c240a20ull,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3436325f335f74ull,0x383109636f6c2e09ull,0x090a300938323109ull,
0x203436662e766f6dull,0x202c373264662509ull,0x20203b3338646625ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x203b3936325f335full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3037325f335f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x090a3436325f335full,0x09383209636f6c2eull,0x6d090a3009303435ull,
0x09203436622e766full,0x252c37343172257bull,0x6625202c7d373172ull,0x2f2f093b35313264ull,
0x09636f6c2e090a20ull,0x3009313435093832ull,0x36622e766f6d090aull,0x383172257b092034ull,
0x2c7d38343172252cull,0x3b35313264662520ull,0x6c2e090a202f2f09ull,0x343509383209636full,
0x736261090a300932ull,0x662509203436662eull,0x6625202c38313364ull,0x2020203b35313264ull,
0x0a202f2f09202020ull,0x3436662e766f6d09ull,0x3931336466250920ull,0x306666376430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x6573090a666e6920ull,0x36662e656c2e7074ull,
0x2c38347025092034ull,0x2c38313364662520ull,0x3b39313364662520ull,0x2540090a202f2f09ull,
0x2061726220383470ull,0x325f335f744c2409ull,0x20202020203b3539ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x61090a3436325f33ull,
0x09203436662e6464ull,0x202c303231646625ull,0x202c353132646625ull,0x093b353132646625ull,
0x617262090a202f2full,0x4c240920696e752eull,0x20203b325f335f74ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x39325f335f744c24ull,0x6c3c2f2f200a3a35ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3436325f335f74ull,0x3436662e766f6d09ull,0x3032336466250920ull,
0x303030306430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3020ull,
0x203436662e746c2eull,0x25202c3934702509ull,0x25202c3531326466ull,0x2f093b3032336466ull,
0x70252140090a202full,0x0920617262203934ull,0x39325f335f744c24ull,0x2020202020203b37ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x766f6d090a343632ull,0x662509203436662eull,0x6430202c30323164ull,0x3030303038666666ull,
0x3030303030303030ull,0x6e616e202f2f093bull,0x6e752e617262090aull,0x335f744c24092069ull,
0x20202020203b325full,0x2020202020202020ull,0x744c240a202f2f09ull,0x0a3a3739325f335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x6f6d090a3436325full,
0x2509203436662e76ull,0x30202c3132336466ull,0x3030303030303064ull,0x3030303030303030ull,
0x0a30202f2f093b30ull,0x71652e7074657309ull,0x702509203436662eull,0x32646625202c3035ull,
0x33646625202c3531ull,0x0a202f2f093b3132ull,0x2030357025214009ull,0x744c240920617262ull,
0x203b3939325f335full,0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3436325f335f744cull,0x36662e766f6d090aull,0x3231646625092034ull,
0x6666666430202c30ull,0x3030303030303030ull,0x2f093b3030303030ull,0x090a666e692d202full,
0x20696e752e617262ull,0x325f335f744c2409ull,0x202020202020203bull,0x2f09202020202020ull,
0x335f744c240a202full,0x2f200a3a3939325full,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,
0x325f335f744c2420ull,0x636f6c2e090a3436ull,0x0934353509383209ull,0x662e766f6d090a30ull,
0x3364662509203436ull,0x66376430202c3232ull,0x3030303030303066ull,0x093b303030303030ull,
0x090a666e69202f2full,0x2e71652e70746573ull,0x3570250920343666ull,0x3133646625202c31ull,
0x3233646625202c38ull,0x090a202f2f093b32ull,0x6220313570252140ull,0x5f744c2409206172ull,
0x20203b3130335f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3436325f335f74ull,0x3436662e766f6d09ull,0x3032316466250920ull,
0x353132646625202cull,0x092020202020203bull,0x617262090a202f2full,0x4c240920696e752eull,
0x20203b325f335f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x30335f335f744c24ull,
0x6c3c2f2f200a3a31ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x3436662e766f6d09ull,0x3332336466250920ull,0x303130306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x37303532322e3220ull,0x73090a3830332d65ull,0x662e746c2e707465ull,
0x3235702509203436ull,0x353132646625202cull,0x333233646625202cull,0x40090a202f2f093bull,
0x7262203235702521ull,0x335f744c24092061ull,0x2020203b3430335full,0x2f2f092020202020ull,
0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x090a3436325f335full,
0x09383209636f6c2eull,0x6d090a3009313635ull,0x09203436662e766full,0x202c343233646625ull,
0x3030303533346430ull,0x3030303030303030ull,0x31202f2f093b3030ull,0x2b6534343130382eull,
0x2e6c756d090a3631ull,0x6466250920343666ull,0x646625202c353233ull,0x646625202c353132ull,
0x202f2f093b343233ull,0x36622e766f6d090aull,0x343172257b092034ull,0x2c7d373172252c39ull,
0x3b35323364662520ull,0x6c2e090a202f2f09ull,0x363509383209636full,0x766f6d090a300932ull,
0x257b09203436622eull,0x353172252c383172ull,0x33646625202c7d30ull,0x0a202f2f093b3532ull,
0x3233732e766f6d09ull,0x202c323272250920ull,0x202020203b34352dull,0x0920202020202020ull,
0x617262090a202f2full,0x4c240920696e752eull,0x3b3330335f335f74ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x30335f335f744c24ull,0x6c3c2f2f200a3a34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3436325f335f74ull,0x3233732e766f6d09ull,0x202c323272250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x5f744c240a202f2full,0x200a3a3330335f33ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x6f6c2e090a343632ull,
0x3736350938320963ull,0x2e726873090a3009ull,0x3172250920323373ull,0x37317225202c3135ull,
0x2020203b3032202cull,0x090a202f2f092020ull,0x203233622e646e61ull,0x202c323531722509ull,
0x32202c3135317225ull,0x2f0920203b373430ull,0x2e646461090a202full,0x3172250920323373ull,
0x32327225202c3335ull,0x3b3235317225202cull,0x090a202f2f092020ull,0x203233732e627573ull,
0x25202c3232722509ull,0x3031202c33353172ull,0x2f092020203b3332ull,0x636f6c2e090a202full,
0x0938363509383209ull,0x622e646e61090a30ull,0x3632722509203233ull,0x202c37317225202cull,
0x353334363431322dull,0x202f2f093b333730ull,0x3233622e726f090aull,0x2c34353172250920ull,
0x31202c3632722520ull,0x3432333936323730ull,0x090a202f2f093b38ull,0x203436622e766f6dull,
0x2c36323364662509ull,0x252c383172257b20ull,0x2f093b7d34353172ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x33646625202c3134ull,0x20202020203b3632ull,0x090a202f2f092020ull,
0x203436662e766f6dull,0x2c37323364662509ull,0x6136666633643020ull,0x3366373636653930ull,
0x202f2f093b646362ull,0x0a31323431342e31ull,0x74672e7074657309ull,0x702509203436662eull,
0x33646625202c3335ull,0x33646625202c3632ull,0x0a202f2f093b3732ull,0x2033357025214009ull,
0x744c240920617262ull,0x203b3530335f335full,0x0920202020202020ull,0x3c2f2f200a202f2full,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3436325f335f744cull,0x3209636f6c2e090aull,
0x0a30093037350938ull,0x3436622e766f6d09ull,0x35353172257b0920ull,0x2c7d36353172252cull,
0x3b36323364662520ull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x7225202c37353172ull,
0x343031202c363531ull,0x2f2f093b36373538ull,0x622e766f6d090a20ull,0x3172257b09203436ull,
0x39353172252c3835ull,0x3233646625202c7dull,0x090a202f2f093b36ull,0x203436622e766f6dull,
0x202c313464662509ull,0x252c38353172257bull,0x2f093b7d37353172ull,0x636f6c2e090a202full,
0x0931373509383209ull,0x732e646461090a30ull,0x3232722509203233ull,0x202c32327225202cull,
0x2020202020203b31ull,0x4c240a202f2f0920ull,0x3a3530335f335f74ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3936322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3436325f33ull,0x3509383209636f6cull,
0x6f6d090a30093538ull,0x2509203436662e76ull,0x30202c3832336466ull,0x3030303066666264ull,
0x3030303030303030ull,0x312d202f2f093b30ull,0x36662e646461090aull,0x3434646625092034ull,
0x2c3134646625202cull,0x3b38323364662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3932336466ull,0x3030303066663364ull,0x3030303030303030ull,0x0a31202f2f093b30ull,
0x3436662e64646109ull,0x3033336466250920ull,0x2c3134646625202cull,0x3b39323364662520ull,
0x6372090a202f2f09ull,0x2509203436662e70ull,0x6625202c37346466ull,0x2020203b30333364ull,
0x202f2f0920202020ull,0x36662e6c756d090aull,0x3834646625092034ull,0x2c3434646625202cull,
0x203b373464662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x6625202c39346466ull,
0x646625202c383464ull,0x202f2f09203b3834ull,0x36662e6c756d090aull,0x3035646625092034ull,
0x2c3934646625202cull,0x203b393464662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3133336466ull,0x3038333162653364ull,0x3166303865613362ull,0x2e31202f2f093b65ull,
0x302d653333363230ull,0x662e766f6d090a36ull,0x3364662509203436ull,0x65336430202c3233ull,
0x6238353265653064ull,0x093b343062386137ull,0x3633302e34202f2full,0x090a36302d653934ull,
0x662e6e722e64616dull,0x3364662509203436ull,0x33646625202c3333ull,0x35646625202c3133ull,
0x3333646625202c30ull,0x090a202f2f093b32ull,0x203436662e766f6dull,0x2c34333364662509ull,
0x6233666533643020ull,0x3632306639363632ull,0x202f2f093b663637ull,0x6534343837382e31ull,
0x64616d090a35302dull,0x203436662e6e722eull,0x2c35333364662509ull,0x2c33333364662520ull,
0x202c303564662520ull,0x093b343333646625ull,0x766f6d090a202f2full,0x662509203436662eull,
0x6430202c36333364ull,0x6263353437316633ull,0x3635393062613961ull,0x382e38202f2f093bull,
0x35302d6531383737ull,0x6e722e64616d090aull,0x662509203436662eull,0x6625202c37333364ull,
0x6625202c35333364ull,0x646625202c303564ull,0x202f2f093b363333ull,0x36662e766f6d090aull,
0x3333646625092034ull,0x3366336430202c38ull,0x3164323763313763ull,0x2f093b3435313562ull,
0x343030302e30202full,0x6d090a3832303433ull,0x36662e6e722e6461ull,0x3935646625092034ull,
0x373333646625202cull,0x2c3035646625202cull,0x3b38333364662520ull,0x6c2e090a202f2f09ull,
0x383509383209636full,0x766f6d090a300936ull,0x662509203436662eull,0x6430202c39333364ull,
0x3432393432366633ull,0x6432376562333239ull,0x302e30202f2f093bull,0x0a34313233323230ull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x35646625202c3935ull,0x3035646625202c39ull,
0x393333646625202cull,0x2e090a202f2f093bull,0x3509383209636f6cull,0x6f6d090a30093738ull,
0x2509203436662e76ull,0x30202c3034336466ull,0x3939393938663364ull,0x6333613939393939ull,
0x2e30202f2f093b34ull,0x616d090a35323130ull,0x3436662e6e722e64ull,0x2c39356466250920ull,
0x202c393564662520ull,0x25202c3035646625ull,0x2f093b3034336466ull,0x636f6c2e090a202full,
0x0938383509383209ull,0x662e766f6d090a30ull,0x3364662509203436ull,0x66336430202c3134ull,
0x3535353535353562ull,0x093b343535353535ull,0x3338302e30202f2full,0x616d090a33333333ull,
0x3436662e6e722e64ull,0x2c39356466250920ull,0x202c393564662520ull,0x25202c3035646625ull,
0x2f093b3134336466ull,0x636f6c2e090a202full,0x0934393509383209ull,0x662e6c756d090a30ull,
0x3364662509203436ull,0x35646625202c3234ull,0x3935646625202c30ull,0x6d090a202f2f093bull,
0x09203436662e6c75ull,0x25202c3935646625ull,0x6625202c39346466ull,0x2f2f093b32343364ull,
0x09636f6c2e090a20ull,0x3009343036093832ull,0x6e722e747663090aull,0x3233732e3436662eull,
0x2c34366466250920ull,0x20203b3232722520ull,0x7573090a202f2f09ull,0x2509203436662e62ull,
0x6625202c35366466ull,0x646625202c343464ull,0x202f2f09203b3934ull,0x36662e766f6d090aull,
0x3433646625092034ull,0x6566336430202c33ull,0x6665663234653236ull,0x2f093b6665393361ull,
0x313339362e30202full,0x2e64616d090a3734ull,0x09203436662e6e72ull,0x25202c3736646625ull,
0x6625202c34366466ull,0x6625202c33343364ull,0x202f2f093b393464ull,0x36662e766f6d090aull,
0x3433646625092034ull,0x3763336430202c34ull,0x3362336539636261ull,0x2f093b6633303839ull,
0x303931332e32202full,0x6e090a37312d6535ull,0x09203436662e6765ull,0x202c353433646625ull,
0x20203b3934646625ull,0x2f2f092020202020ull,0x622e766f6d090a20ull,0x3172257b09203436ull,
0x31363172252c3036ull,0x3536646625202c7dull,0x61090a202f2f093bull,0x09203233732e6464ull,
0x25202c3236317225ull,0x3031202c31363172ull,0x2f093b3637353834ull,0x2e766f6d090a202full,
0x72257b0920343662ull,0x363172252c333631ull,0x36646625202c7d34ull,0x090a202f2f093b35ull,
0x203436622e766f6dull,0x2c36343364662509ull,0x2c33363172257b20ull,0x093b7d3236317225ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x2c37343364662509ull,0x2c35343364662520ull,
0x202c343464662520ull,0x093b363433646625ull,0x64616d090a202f2full,0x662509203436662eull,
0x6625202c38343364ull,0x6625202c37343364ull,0x646625202c373464ull,0x0a202f2f093b3935ull,
0x3233732e67656e09ull,0x2c35363172250920ull,0x20203b3232722520ull,0x0920202020202020ull,
0x747663090a202f2full,0x2e3436662e6e722eull,0x6466250920323373ull,0x317225202c393433ull,
0x0a202f2f093b3536ull,0x3436662e766f6d09ull,0x3035336466250920ull,0x366566336430202cull,
0x6166656632346532ull,0x2f2f093b66653933ull,0x34313339362e3020ull,0x722e64616d090a37ull,
0x2509203436662e6eull,0x25202c3135336466ull,0x25202c3934336466ull,0x25202c3035336466ull,
0x2f2f093b37366466ull,0x662e627573090a20ull,0x3364662509203436ull,0x33646625202c3235ull,
0x34646625202c3135ull,0x090a202f2f093b39ull,0x203436662e627573ull,0x2c33353364662509ull,
0x2c38343364662520ull,0x3b32353364662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c38376466250920ull,0x202c343664662520ull,0x202c343433646625ull,0x093b333533646625ull,
0x646461090a202f2full,0x662509203436662eull,0x6625202c30323164ull,0x646625202c373664ull,
0x0a202f2f093b3837ull,0x3a325f335f744c24ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3936322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x2e090a3436325f33ull,0x3509383209636f6cull,0x656e090a30093034ull,
0x2509203436662e67ull,0x25202c3435336466ull,0x20203b3032316466ull,0x202f2f0920202020ull,
0x36622e766f6d090aull,0x363172257b092034ull,0x2c7d373172252c36ull,0x3b34353364662520ull,
0x6c2e090a202f2f09ull,0x343509383209636full,0x766f6d090a300931ull,0x257b09203436622eull,
0x363172252c383172ull,0x33646625202c7d37ull,0x0a202f2f093b3435ull,0x383209636f6c2e09ull,
0x090a300932343509ull,0x203436662e736261ull,0x2c35353364662509ull,0x3b30323164662520ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x6466250920343666ull,0x376430202c363533ull,
0x3030303030306666ull,0x3b30303030303030ull,0x0a666e69202f2f09ull,0x656c2e7074657309ull,
0x702509203436662eull,0x33646625202c3435ull,0x33646625202c3535ull,0x0a202f2f093b3635ull,
0x6220343570254009ull,0x5f744c2409206172ull,0x20203b3730335f33ull,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3436325f335f744cull,
0x36662e646461090aull,0x3533646625092034ull,0x3231646625202c37ull,0x3231646625202c30ull,
0x090a202f2f093b30ull,0x203436662e67656eull,0x2c39353164662509ull,0x3b37353364662520ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x2020203b345f335full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3730335f335f744cull,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3436325f335full,0x203436662e766f6dull,
0x2c38353364662509ull,0x3030303030643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x2e70746573090a30ull,0x09203436662e746cull,0x6625202c35357025ull,0x6625202c34353364ull,
0x2f2f093b38353364ull,0x3570252140090a20ull,0x2409206172622035ull,0x3930335f335f744cull,
0x202020202020203bull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,
0x325f335f744c2420ull,0x2e766f6d090a3436ull,0x6466250920343666ull,0x666430202c393531ull,
0x3030303030386666ull,0x3b30303030303030ull,0x0a6e616e202f2f09ull,0x696e752e61726209ull,
0x5f335f744c240920ull,0x2020202020203b34ull,0x0920202020202020ull,0x5f744c240a202f2full,
0x200a3a3930335f33ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x766f6d090a343632ull,0x662509203436662eull,0x6430202c39353364ull,0x3030303030303030ull,
0x3030303030303030ull,0x090a30202f2f093bull,0x2e71652e70746573ull,0x3570250920343666ull,
0x3533646625202c36ull,0x3533646625202c34ull,0x090a202f2f093b39ull,0x6220363570252140ull,
0x5f744c2409206172ull,0x20203b3131335f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,0x3436662e766f6d09ull,
0x3935316466250920ull,0x306666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,
0x62090a666e692d20ull,0x0920696e752e6172ull,0x3b345f335f744c24ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x5f335f744c240a20ull,0x2f2f200a3a313133ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,
0x2064656c6562616cull,0x36325f335f744c24ull,0x09636f6c2e090a34ull,0x3009343535093832ull,
0x36662e766f6d090aull,0x3633646625092034ull,0x6666376430202c30ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x73090a666e69202full,0x662e71652e707465ull,0x3735702509203436ull,
0x353533646625202cull,0x303633646625202cull,0x40090a202f2f093bull,0x7262203735702521ull,
0x335f744c24092061ull,0x2020203b3331335full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3436325f335full,0x203436662e766f6dull,
0x2c39353164662509ull,0x3b34353364662520ull,0x2f09202020202020ull,0x2e617262090a202full,
0x744c240920696e75ull,0x2020203b345f335full,0x2020202020202020ull,0x240a202f2f092020ull,
0x3331335f335f744cull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x090a3436325f335full,0x203436662e766f6dull,0x2c31363364662509ull,0x3030313030643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x6537303532322e32ull,0x6573090a3830332dull,
0x36662e746c2e7074ull,0x2c38357025092034ull,0x2c34353364662520ull,0x3b31363364662520ull,
0x2140090a202f2f09ull,0x6172622038357025ull,0x5f335f744c240920ull,0x202020203b363133ull,
0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x2e090a3436325f33ull,0x3509383209636f6cull,0x6f6d090a30093136ull,0x2509203436662e76ull,
0x30202c3236336466ull,0x3030303035333464ull,0x3030303030303030ull,0x2e31202f2f093b30ull,
0x312b653434313038ull,0x662e6c756d090a36ull,0x3364662509203436ull,0x33646625202c3336ull,
0x33646625202c3435ull,0x0a202f2f093b3236ull,0x3436622e766f6d09ull,0x38363172257b0920ull,
0x202c7d373172252cull,0x093b333633646625ull,0x6f6c2e090a202f2full,0x3236350938320963ull,
0x2e766f6d090a3009ull,0x72257b0920343662ull,0x39363172252c3831ull,0x3633646625202c7dull,
0x090a202f2f093b33ull,0x203233732e766f6dull,0x2d202c3232722509ull,0x20202020203b3435ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x203b3531335f335full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3631335f335f744cull,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3436325f335full,0x203233732e766f6dull,
0x30202c3232722509ull,0x202020202020203bull,0x2f09202020202020ull,0x335f744c240a202full,
0x2f200a3a3531335full,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,0x325f335f744c2420ull,
0x636f6c2e090a3436ull,0x0937363509383209ull,0x732e726873090a30ull,0x3731722509203233ull,
0x2c37317225202c30ull,0x202020203b303220ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x25202c3137317225ull,0x3032202c30373172ull,0x2f2f0920203b3734ull,0x732e646461090a20ull,
0x3731722509203233ull,0x2c32327225202c32ull,0x203b313731722520ull,0x73090a202f2f0920ull,
0x09203233732e6275ull,0x7225202c32327225ull,0x323031202c323731ull,0x2f2f092020203b33ull,
0x09636f6c2e090a20ull,0x3009383635093832ull,0x33622e646e61090aull,0x2c36327225092032ull,
0x2d202c3731722520ull,0x3035333436343132ull,0x0a202f2f093b3337ull,0x203233622e726f09ull,
0x202c333731722509ull,0x3031202c36327225ull,0x3834323339363237ull,0x6d090a202f2f093bull,
0x09203436622e766full,0x202c343633646625ull,0x72252c383172257bull,0x2f2f093b7d333731ull,
0x662e766f6d090a20ull,0x3464662509203436ull,0x3633646625202c31ull,0x2020202020203b34ull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x202c353633646625ull,0x3061366666336430ull,
0x6233663736366539ull,0x31202f2f093b6463ull,0x090a31323431342eull,0x2e74672e70746573ull,
0x3570250920343666ull,0x3633646625202c39ull,0x3633646625202c34ull,0x090a202f2f093b35ull,
0x6220393570252140ull,0x5f744c2409206172ull,0x20203b3731335f33ull,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x383209636f6c2e09ull,0x090a300930373509ull,0x203436622e766f6dull,0x2c34373172257b09ull,
0x202c7d3537317225ull,0x093b343633646625ull,0x627573090a202f2full,0x722509203233732eull,
0x317225202c363731ull,0x38343031202c3537ull,0x202f2f093b363735ull,0x36622e766f6d090aull,
0x373172257b092034ull,0x7d38373172252c37ull,0x343633646625202cull,0x6d090a202f2f093bull,
0x09203436622e766full,0x7b202c3134646625ull,0x72252c3737317225ull,0x2f2f093b7d363731ull,
0x09636f6c2e090a20ull,0x3009313735093832ull,0x33732e646461090aull,0x2c32327225092032ull,
0x31202c3232722520ull,0x202020202020203bull,0x744c240a202f2f09ull,0x0a3a3731335f335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x6c2e090a3436325full,
0x383509383209636full,0x766f6d090a300935ull,0x662509203436662eull,0x6430202c36363364ull,
0x3030303030666662ull,0x3030303030303030ull,0x0a312d202f2f093bull,0x3436662e64646109ull,
0x2c34346466250920ull,0x202c313464662520ull,0x093b363633646625ull,0x766f6d090a202f2full,
0x662509203436662eull,0x6430202c37363364ull,0x3030303030666633ull,0x3030303030303030ull,
0x090a31202f2f093bull,0x203436662e646461ull,0x2c38363364662509ull,0x202c313464662520ull,
0x093b373633646625ull,0x706372090a202f2full,0x662509203436662eull,0x646625202c373464ull,
0x202020203b383633ull,0x0a202f2f09202020ull,0x3436662e6c756d09ull,0x2c38346466250920ull,
0x202c343464662520ull,0x09203b3734646625ull,0x646461090a202f2full,0x662509203436662eull,
0x646625202c393464ull,0x34646625202c3834ull,0x0a202f2f09203b38ull,0x3436662e6c756d09ull,
0x2c30356466250920ull,0x202c393464662520ull,0x09203b3934646625ull,0x766f6d090a202f2full,
0x662509203436662eull,0x6430202c39363364ull,0x6230383331626533ull,0x6531663038656133ull,
0x302e31202f2f093bull,0x36302d6533333632ull,0x36662e766f6d090aull,0x3733646625092034ull,
0x6465336430202c30ull,0x3762383532656530ull,0x2f093b3430623861ull,0x343633302e34202full,
0x6d090a36302d6539ull,0x36662e6e722e6461ull,0x3733646625092034ull,0x3633646625202c31ull,
0x3035646625202c39ull,0x303733646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,
0x202c323733646625ull,0x3262336665336430ull,0x3736323066393636ull,0x31202f2f093b6636ull,
0x2d6534343837382eull,0x2e64616d090a3530ull,0x09203436662e6e72ull,0x202c333733646625ull,
0x202c313733646625ull,0x25202c3035646625ull,0x2f093b3237336466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c343733ull,0x6162633534373166ull,0x3b36353930626139ull,
0x37382e38202f2f09ull,0x0a35302d65313837ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x646625202c353733ull,0x646625202c333733ull,0x33646625202c3035ull,0x0a202f2f093b3437ull,
0x3436662e766f6d09ull,0x3637336466250920ull,0x633366336430202cull,0x6231643237633137ull,
0x2f2f093b34353135ull,0x33343030302e3020ull,0x616d090a38323034ull,0x3436662e6e722e64ull,
0x2c39356466250920ull,0x2c35373364662520ull,0x202c303564662520ull,0x093b363733646625ull,
0x6f6c2e090a202f2full,0x3638350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,
0x336430202c373733ull,0x3934323934323666ull,0x3b64323765623332ull,0x30302e30202f2f09ull,
0x090a343132333232ull,0x662e6e722e64616dull,0x3564662509203436ull,0x3935646625202c39ull,
0x2c3035646625202cull,0x3b37373364662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,
0x766f6d090a300937ull,0x662509203436662eull,0x6430202c38373364ull,0x3939393939386633ull,
0x3463336139393939ull,0x302e30202f2f093bull,0x64616d090a353231ull,0x203436662e6e722eull,
0x202c393564662509ull,0x25202c3935646625ull,0x6625202c30356466ull,0x2f2f093b38373364ull,
0x09636f6c2e090a20ull,0x3009383835093832ull,0x36662e766f6d090aull,0x3733646625092034ull,
0x6266336430202c39ull,0x3535353535353535ull,0x2f093b3435353535ull,0x333338302e30202full,
0x64616d090a333333ull,0x203436662e6e722eull,0x202c393564662509ull,0x25202c3935646625ull,
0x6625202c30356466ull,0x2f2f093b39373364ull,0x09636f6c2e090a20ull,0x3009343935093832ull,
0x36662e6c756d090aull,0x3833646625092034ull,0x3035646625202c30ull,0x3b3935646625202cull,
0x756d090a202f2f09ull,0x2509203436662e6cull,0x6625202c39356466ull,0x646625202c393464ull,
0x202f2f093b303833ull,0x3209636f6c2e090aull,0x0a30093430360938ull,0x2e6e722e74766309ull,
0x203233732e343666ull,0x202c343664662509ull,0x0920203b32327225ull,0x627573090a202f2full,
0x662509203436662eull,0x646625202c353664ull,0x34646625202c3434ull,0x0a202f2f09203b39ull,
0x3436662e766f6d09ull,0x3138336466250920ull,0x366566336430202cull,0x6166656632346532ull,
0x2f2f093b66653933ull,0x34313339362e3020ull,0x722e64616d090a37ull,0x2509203436662e6eull,
0x6625202c37366466ull,0x646625202c343664ull,0x646625202c313833ull,0x0a202f2f093b3934ull,
0x3436662e766f6d09ull,0x3238336466250920ull,0x613763336430202cull,0x3933623365396362ull,
0x2f2f093b66333038ull,0x35303931332e3220ull,0x656e090a37312d65ull,0x2509203436662e67ull,
0x25202c3338336466ull,0x2020203b39346466ull,0x202f2f0920202020ull,0x36622e766f6d090aull,
0x373172257b092034ull,0x7d30383172252c39ull,0x3b3536646625202cull,0x6461090a202f2f09ull,
0x2509203233732e64ull,0x7225202c31383172ull,0x343031202c303831ull,0x2f2f093b36373538ull,
0x622e766f6d090a20ull,0x3172257b09203436ull,0x33383172252c3238ull,0x3536646625202c7dull,
0x6d090a202f2f093bull,0x09203436622e766full,0x202c343833646625ull,0x252c32383172257bull,
0x2f093b7d31383172ull,0x2e64616d090a202full,0x09203436662e6e72ull,0x202c353833646625ull,
0x202c333833646625ull,0x25202c3434646625ull,0x2f093b3438336466ull,0x2e64616d090a202full,
0x6466250920343666ull,0x646625202c363833ull,0x646625202c353833ull,0x35646625202c3734ull,
0x090a202f2f093b39ull,0x203233732e67656eull,0x202c343831722509ull,0x2020203b32327225ull,
0x2f09202020202020ull,0x2e747663090a202full,0x732e3436662e6e72ull,0x3364662509203233ull,
0x38317225202c3738ull,0x090a202f2f093b34ull,0x203436662e766f6dull,0x2c38383364662509ull,
0x3236656633643020ull,0x3361666566323465ull,0x202f2f093b666539ull,0x3734313339362e30ull,
0x6e722e64616d090aull,0x662509203436662eull,0x6625202c39383364ull,0x6625202c37383364ull,
0x6625202c38383364ull,0x202f2f093b373664ull,0x36662e627573090aull,0x3933646625092034ull,
0x3833646625202c30ull,0x3934646625202c39ull,0x73090a202f2f093bull,0x09203436662e6275ull,
0x202c313933646625ull,0x202c363833646625ull,0x093b303933646625ull,0x64616d090a202f2full,
0x203436662e6e722eull,0x202c383764662509ull,0x25202c3436646625ull,0x25202c3238336466ull,
0x2f093b3139336466ull,0x2e646461090a202full,0x6466250920343666ull,0x646625202c393531ull,
0x37646625202c3736ull,0x240a202f2f093b38ull,0x0a3a345f335f744cull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x6c2e090a3436325full,0x333109383109636full,
0x766f6d090a300930ull,0x662509203436662eull,0x646625202c373264ull,0x202020203b393531ull,
0x0a202f2f09202020ull,0x36325f335f744c24ull,0x6c3c2f2f200a3a39ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3436325f335f74ull,0x383109636f6c2e09ull,0x090a300932333109ull,
0x203436662e766f6dull,0x2c32393364662509ull,0x3935646633643020ull,0x3034653363323339ull,
0x202f2f093b643633ull,0x3537343733332e30ull,0x36662e766f6d090aull,0x3933646625092034ull,
0x6566336430202c33ull,0x3866633663633366ull,0x2f093b3133316362ull,0x313637392e30202full,
0x2e766f6d090a3936ull,0x6466250920343666ull,0x336430202c343933ull,0x3237303539346366ull,
0x3b36383630393636ull,0x36312e30202f2f09ull,0x6f6d090a38393730ull,0x2509203436662e76ull,
0x30202c3539336466ull,0x6165346339663364ull,0x3332343465333764ull,0x2e30202f2f093b37ull,
0x0a39333436373230ull,0x3436662e766f6d09ull,0x3639336466250920ull,0x663666336430202cull,
0x6533356533343637ull,0x2f2f093b35383736ull,0x34383330302e3020ull,0x766f6d090a373530ull,
0x662509203436662eull,0x6430202c37393364ull,0x6532366539336633ull,0x3634383839613061ull,
0x302e30202f2f093bull,0x0a39313539333030ull,0x3436662e766f6d09ull,0x3839336466250920ull,
0x303066336430202cull,0x3566353032626564ull,0x2f2f093b38303238ull,0x38363731322e3320ull,
0x6f6d090a35302d65ull,0x2509203436662e76ull,0x30202c3939336466ull,0x6431363339653364ull,
0x3562376239303735ull,0x2e32202f2f093b36ull,0x302d653731383838ull,0x662e766f6d090a37ull,
0x3464662509203436ull,0x65336430202c3030ull,0x6130356333396139ull,0x093b646135643230ull,
0x3036392e33202f2full,0x090a37302d653233ull,0x203436662e64616dull,0x2c31303464662509ull,
0x2c30303464662520ull,0x202c373264662520ull,0x093b393933646625ull,0x64616d090a202f2full,
0x662509203436662eull,0x6625202c32303464ull,0x646625202c373264ull,0x646625202c313034ull,
0x202f2f093b383933ull,0x36662e64616d090aull,0x3034646625092034ull,0x3732646625202c33ull,
0x323034646625202cull,0x373933646625202cull,0x6d090a202f2f093bull,0x09203436662e6461ull,
0x202c343034646625ull,0x25202c3732646625ull,0x25202c3330346466ull,0x2f093b3639336466ull,
0x2e64616d090a202full,0x6466250920343666ull,0x646625202c353034ull,0x34646625202c3732ull,
0x33646625202c3430ull,0x0a202f2f093b3539ull,0x3436662e64616d09ull,0x3630346466250920ull,
0x2c3732646625202cull,0x2c35303464662520ull,0x3b34393364662520ull,0x616d090a202f2f09ull,
0x2509203436662e64ull,0x25202c3730346466ull,0x6625202c37326466ull,0x6625202c36303464ull,
0x2f2f093b33393364ull,0x662e64616d090a20ull,0x3264662509203436ull,0x3732646625202c37ull,
0x373034646625202cull,0x323933646625202cull,0x6e090a202f2f093bull,0x09203436662e6765ull,
0x202c383034646625ull,0x20203b3732646625ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,
0x3464662509203436ull,0x30306430202c3930ull,0x3030303030303030ull,0x093b303030303030ull,
0x6573090a30202f2full,0x36662e746c2e7074ull,0x2c30367025092034ull,0x2c30323264662520ull,
0x3b39303464662520ull,0x6573090a202f2f09ull,0x09203436662e706cull,0x25202c3732646625ull,
0x25202c3830346466ull,0x7025202c37326466ull,0x0a202f2f093b3036ull,0x36325f335f744c24ull,
0x6c3c2f2f200a3a37ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x0a3436325f335f74ull,
0x3436662e766f6d09ull,0x3831326466250920ull,0x3b3732646625202cull,0x0920202020202020ull,
0x5f744c240a202f2full,0x2f2f200a3a315f33ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,
0x36325f335f744c24ull,0x09636f6c2e090a34ull,0x3009393632093831ull,0x6e722e747663090aull,
0x3436662e3233662eull,0x25202c3366250920ull,0x20203b3831326466ull,0x6461090a202f2f09ull,
0x2509203436752e64ull,0x7225202c35316472ull,0x647225202c313164ull,0x202f2f09203b3431ull,
0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b35316472255b09ull,0x3b336625202c5d30ull,
0x313a6469202f2f09ull,0x646461090a353831ull,0x722509203233752eull,0x30317225202c3839ull,
0x3b38397225202c30ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c31316472250920ull,
0x202c313164722520ull,0x09203b3331647225ull,0x746573090a202f2full,0x3233752e746c2e70ull,
0x202c313670250920ull,0x7225202c38397225ull,0x0a202f2f09203b31ull,0x6220313670254009ull,
0x5f744c2409206172ull,0x20203b3436325f33ull,0x0920202020202020ull,0x5f744c240a202f2full,
0x240a3a3236325f33ull,0x3230325f335f744cull,0x09636f6c2e090a3aull,0x3009323732093831ull,
0x203b74697865090aull,0x2020202020202020ull,0x2020202020202020ull,0x2020202020202020ull,
0x444c240a202f2f09ull,0x315a5f5f646e6557ull,0x65737265766e6936ull,0x656e72654b444e43ull,
0x0a3a6a5f5366506cull,0x5a5f202f2f207d09ull,0x737265766e693631ull,0x6e72654b444e4365ull,
0x0a6a5f5366506c65ull,0x000000000000000aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"9f0710a8d3bcd72f",(char*)"MonteCarlo_SM13.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0};
# 5 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 2
# 1 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 1
# 74 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h"
# 1 "/home/gdiamos/temp/cuda/bin//../include/host_defines.h" 1
# 75 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 2
# 100 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h"
extern "C" {


extern void** __cudaRegisterFatBinary(
  void *fatCubin
);

extern void __cudaUnregisterFatBinary(
  void **fatCubinHandle
);

extern void __cudaRegisterVar(
        void **fatCubinHandle,
        char *hostVar,
        char *deviceAddress,
  const char *deviceName,
        int ext,
        int size,
        int constant,
        int global
);

extern void __cudaRegisterTexture(
        void **fatCubinHandle,
  const struct textureReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int norm,
        int ext
);

extern void __cudaRegisterShared(
  void **fatCubinHandle,
  void **devicePtr
);

extern void __cudaRegisterSharedVar(
  void **fatCubinHandle,
  void **devicePtr,
  size_t size,
  size_t alignment,
  int storage
);

extern void __cudaRegisterFunction(
        void **fatCubinHandle,
  const char *hostFun,
        char *deviceFun,
  const char *deviceName,
        int thread_limit,
        uint3 *tid,
        uint3 *bid,
        dim3 *bDim,
        dim3 *gDim,
        int *wSize
);


}




extern int atexit(void(*)(void)) throw();







static void **__cudaFatCubinHandle;

static void __cudaUnregisterBinaryUtil(void)
{
  __cudaUnregisterFatBinary(__cudaFatCubinHandle);
}
# 215 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h"
# 1 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h" 1
# 68 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h"
# 1 "/home/gdiamos/temp/cuda/bin//../include/crt/func_macro.h" 1 3
# 69 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h" 2

static clock_t __cuda_clock(void)
{
  return clock();
}

static void *__cuda_memset(void *s, int c, size_t n)
{
  return memset(s, c, n);
}

static void *__cuda_memcpy(void *d, const void *s, size_t n)
{
  return memcpy(d, s, n);
}
# 93 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h"
# 1 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 1 3
# 844 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
extern __attribute__((__weak__)) int __cuda_error_not_implememted(void); int __cuda_error_not_implememted(void);
# 900 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static int __cuda_abs(int a)
{
  return abs(a);
}

static float __cuda_fabsf(float a)
{
  return fabsf(a);
}

static long long int __cuda_llabs(long long int a)
{

  return ::llabs(a);



}

static float __cuda_exp2f(float a)
{
  return exp2f(a);
}

# 1 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 1 3
# 347 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/math_constants.h" 1 3
# 348 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 2 3



static int __cuda___isnan(double a);
static int __cuda___isnanf(float a);
static int __double2int_rz(double);
static unsigned int __double2uint_rz(double);
static long long int __double2ll_rz(double);
static unsigned long long int __double2ull_rz(double);
# 370 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
static int __mulhi(int a, int b)
{
  long long int c = (long long int)a * (long long int)b;

  return (int)(c >> 32);
}

static unsigned int __umulhi(unsigned int a, unsigned int b)
{
  unsigned long long int c = (unsigned long long int)a * (unsigned long long int)b;

  return (unsigned int)(c >> 32);
}

static unsigned long long int __umul64hi(unsigned long long int a, unsigned long long int b)
{
  unsigned int a_lo = (unsigned int)a;
  unsigned long long int a_hi = a >> 32;
  unsigned int b_lo = (unsigned int)b;
  unsigned long long int b_hi = b >> 32;
  unsigned long long int m1 = a_lo * b_hi;
  unsigned long long int m2 = a_hi * b_lo;
  unsigned int carry;

  carry = (0ULL + __umulhi(a_lo, b_lo) + (unsigned int)m1 + (unsigned int)m2) >> 32;

  return a_hi * b_hi + (m1 >> 32) + (m2 >> 32) + carry;
}

static long long int __mul64hi(long long int a, long long int b)
{
  long long int res;
  res = __umul64hi(a, b);
  if (a < 0LL) res = res - b;
  if (b < 0LL) res = res - a;
  return res;
}

static float __saturatef(float a)
{
  return a >= 1.0f ? 1.0f : a <= 0.0f ? 0.0f : a;
}

static unsigned int __sad(int a, int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static unsigned int __usad(unsigned int a, unsigned int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static int __mul24(int a, int b)
{

  a &= 0xffffff;
  a = (a & 0x800000) != 0 ? a | ~0xffffff : a;
  b &= 0xffffff;
  b = (b & 0x800000) != 0 ? b | ~0xffffff : b;


  return a * b;
}

static unsigned int __umul24(unsigned int a, unsigned int b)
{

  a &= 0xffffff;
  b &= 0xffffff;


  return a * b;
}

static float __int_as_float(int a)
{
  volatile union {int a; float b;} u;

  u.a = a;

  return u.b;
}

static int __float_as_int(float a)
{
  volatile union {float a; int b;} u;

  u.a = a;

  return u.b;
}

static long long int __internal_float2ll_kernel(float a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  ia = __float_as_int(a);
  shift = 189 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)(((ia << 8) | 0x80000000) >> 1) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundMinInf && t != 0ULL && ia > 0x80000000) {
    res++;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL && (int)ia > 0) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)-(long long int)res;
  return (long long int)res;
}

static int __internal_float2int(float a, enum cudaRoundMode rndMode)
{
  return (int)__internal_float2ll_kernel(a, 2147483647LL, -2147483648LL, 0LL, rndMode);
}

static int __float2int_rz(float a)
{



  return __internal_float2int(a, cudaRoundZero);

}

static int __float2int_ru(float a)
{
  return __internal_float2int(a, cudaRoundPosInf);
}

static int __float2int_rd(float a)
{
  return __internal_float2int(a, cudaRoundMinInf);
}

static int __float2int_rn(float a)
{
  return __internal_float2int(a, cudaRoundNearest);
}

static long long int __internal_float2ll(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static long long int __float2ll_rz(float a)
{



  return __internal_float2ll(a, cudaRoundZero);

}

static long long int __float2ll_ru(float a)
{
  return __internal_float2ll(a, cudaRoundPosInf);
}

static long long int __float2ll_rd(float a)
{
  return __internal_float2ll(a, cudaRoundMinInf);
}

static long long int __float2ll_rn(float a)
{
  return __internal_float2ll(a, cudaRoundNearest);
}

static unsigned long long int __internal_float2ull_kernel(float a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;
  ia = __float_as_int(a);
  shift = 190 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)((ia << 8) | 0x80000000) << 32;
  if (shift >= 64) {
    t = res >> (int)(shift > 64);
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL) {
    res++;
  }
  return res;
}

static unsigned int __internal_float2uint(float a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_float2ull_kernel(a, 4294967295U, 0U, rndMode);
}

static unsigned int __float2uint_rz(float a)
{



  return __internal_float2uint(a, cudaRoundZero);

}

static unsigned int __float2uint_ru(float a)
{
  return __internal_float2uint(a, cudaRoundPosInf);
}

static unsigned int __float2uint_rd(float a)
{
  return __internal_float2uint(a, cudaRoundMinInf);
}

static unsigned int __float2uint_rn(float a)
{
  return __internal_float2uint(a, cudaRoundNearest);
}

static unsigned long long int __internal_float2ull(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static unsigned long long int __float2ull_rz(float a)
{



  return __internal_float2ull(a, cudaRoundZero);

}

static unsigned long long int __float2ull_ru(float a)
{
  return __internal_float2ull(a, cudaRoundPosInf);
}

static unsigned long long int __float2ull_rd(float a)
{
  return __internal_float2ull(a, cudaRoundMinInf);
}

static unsigned long long int __float2ull_rn(float a)
{
  return __internal_float2ull(a, cudaRoundNearest);
}

static int __internal_normalize64(unsigned long long int *a)
{
  int lz = 0;

  if ((*a & 0xffffffff00000000ULL) == 0ULL) {
    *a <<= 32;
    lz += 32;
  }
  if ((*a & 0xffff000000000000ULL) == 0ULL) {
    *a <<= 16;
    lz += 16;
  }
  if ((*a & 0xff00000000000000ULL) == 0ULL) {
    *a <<= 8;
    lz += 8;
  }
  if ((*a & 0xf000000000000000ULL) == 0ULL) {
    *a <<= 4;
    lz += 4;
  }
  if ((*a & 0xC000000000000000ULL) == 0ULL) {
    *a <<= 2;
    lz += 2;
  }
  if ((*a & 0x8000000000000000ULL) == 0ULL) {
    *a <<= 1;
    lz += 1;
  }
  return lz;
}

static int __internal_normalize(unsigned int *a)
{
  unsigned long long int t = (unsigned long long int)*a;
  int lz = __internal_normalize64(&t);

  *a = (unsigned int)(t >> 32);

  return lz - 32;
}

static float __internal_int2float_kernel(int a, enum cudaRoundMode rndMode)
{
  volatile union {
    float f;
    unsigned int i;
  } res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  if (a < 0) res.i = (unsigned int)-a;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (a < 0) res.i |= 0x80000000;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.f;
}

static float __int2float_rz(int a)
{
  return __internal_int2float_kernel(a, cudaRoundZero);
}

static float __int2float_ru(int a)
{
  return __internal_int2float_kernel(a, cudaRoundPosInf);
}

static float __int2float_rd(int a)
{
  return __internal_int2float_kernel(a, cudaRoundMinInf);
}

static float __int2float_rn(int a)
{



  return __internal_int2float_kernel(a, cudaRoundNearest);

}

static float __internal_uint2float_kernel(unsigned int a, enum cudaRoundMode rndMode)
{
  volatile union {
    float f;
    unsigned int i;
  } res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.f;
}

static float __uint2float_rz(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundZero);
}

static float __uint2float_ru(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundPosInf);
}

static float __uint2float_rd(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundMinInf);
}

static float __uint2float_rn(unsigned int a)
{



  return __internal_uint2float_kernel(a, cudaRoundNearest);

}

static float __ll2float_rn(long long int a)
{
  return (float)a;
}

static float __ull2float_rn(unsigned long long int a)
{



  unsigned long long int temp;
  unsigned int res, t;
  int shift;
  if (a == 0ULL) return 0.0f;
  temp = a;
  shift = __internal_normalize64(&temp);
  temp = (temp >> 8) | ((temp & 0xffULL) ? 1ULL : 0ULL);
  res = (unsigned int)(temp >> 32);
  t = (unsigned int)temp;
  res += (127 + 62 - shift) << 23;
  res += t == 0x80000000 ? res & 1 : t >> 31;
  return __int_as_float(res);

}

static float __internal_fmul_kernel(float a, float b, int rndNearest)
{
  unsigned long long product;
  volatile union {
    float f;
    unsigned int i;
  } xx, yy;
  unsigned expo_x, expo_y;

  xx.f = a;
  yy.f = b;

  expo_y = 0xFF;
  expo_x = expo_y & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
multiply:
    expo_x = expo_x + expo_y;
    expo_y = xx.i ^ yy.i;
    xx.i = xx.i & 0x00ffffff;
    yy.i = yy.i << 8;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i | 0x80000000;

    product = ((unsigned long long)xx.i) * yy.i;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xx.i = (unsigned int)(product >> 32);
    yy.i = (unsigned int)(product & 0xffffffff);

    if (xx.i < 0x00800000) {
      xx.i = (xx.i << 1) | (yy.i >> 31);
      yy.i = (yy.i << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i | expo_y;
      xx.i = xx.i + (expo_x << 23);

      if (yy.i < 0x80000000) return xx.f;
      xx.i += (((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31))
               && rndNearest);
      return xx.f;
    } else if ((int)expo_x >= 254) {

      xx.i = (expo_y | 0x7F800000) - (!rndNearest);
      return xx.f;
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      if (expo_x > 25) {

        xx.i = expo_y;
        return xx.f;
      } else {
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31))
                 && rndNearest);
        return xx.f;
      }
    }
  } else {
    product = xx.i ^ yy.i;
    product = product & 0x80000000;
    if (!(xx.i & 0x7fffffff)) {
      if (expo_y != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_y = yy.i << 1;
      if (expo_y == 0xFF000000) {
        xx.i = expo_y | 0x00C00000;
      } else {
        xx.i = yy.i | 0x00400000;
      }
      return xx.f;
    }
    if (!(yy.i & 0x7fffffff)) {
      if (expo_x != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_x = xx.i << 1;
      if (expo_x == 0xFF000000) {
        xx.i = expo_x | 0x00C00000;
      } else {
        xx.i = xx.i | 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {
      expo_y++;
      expo_x++;
      if (expo_x == 0) {
        expo_y |= xx.i & 0x80000000;




        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        xx.i = (xx.i >> 8) | (expo_y & 0x80000000);
        expo_y &= ~0x80000000;
        expo_y--;
        goto multiply;
      }
      if (expo_y == 0) {
        expo_x |= yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        yy.i = (yy.i >> 8) | (expo_x & 0x80000000);
        expo_x &= ~0x80000000;
        expo_x--;
        goto multiply;
      }
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xFF000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xFF000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    xx.i = (unsigned int)product | 0x7f800000;
    return xx.f;
  }
}

static float __internal_fadd_kernel(float a, float b, int rndNearest)
{
  volatile union {
    float f;
    unsigned int i;
  } xx, yy;
  unsigned int expo_x;
  unsigned int expo_y;
  unsigned int temp;

  xx.f = a;
  yy.f = b;


  expo_y = yy.i << 1;
  if (expo_y > (xx.i << 1)) {
    expo_y = xx.i;
    xx.i = yy.i;
    yy.i = expo_y;
  }

  temp = 0xff;
  expo_x = temp & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {

add:
    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xx.i ^ yy.i;
    xx.i = xx.i & ~0x7f000000;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i & ~0xff000000;
    yy.i = yy.i | 0x00800000;

    if ((int)temp < 0) {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      temp = (unsigned int)(-((int)temp));
      xx.i = xx.i - (yy.i >> expo_y) - (temp ? 1 : 0);
      if (xx.i & 0x00800000) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i & ~0x00800000;
          xx.i = (xx.i + (expo_x << 23)) + 0x00800000;
          if (temp < 0x80000000) return xx.f;
          xx.i += (((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31))
                   && rndNearest);
          return xx.f;
        }
      } else {
        if ((temp | (xx.i << 1)) == 0) {

          xx.i = 0;
          return xx.f;
        }

        yy.i = xx.i & 0x80000000;
        do {
          xx.i = (xx.i << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xx.i & 0x00800000));
        xx.i = xx.i | yy.i;
      }
    } else {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      xx.i = xx.i + (yy.i >> expo_y);
      if (!(xx.i & 0x01000000)) {
        if (expo_x <= 0xFD) {
          expo_y = xx.i & 1;
          xx.i = xx.i + (expo_x << 23);
          if (temp < 0x80000000) return xx.f;
          xx.i += (((temp == 0x80000000) ? expo_y : (temp >> 31))
                   && rndNearest);
          return xx.f;
        }
      } else {

        temp = (xx.i << 31) | (temp >> 1);

        xx.i = ((xx.i & 0x80000000) | (xx.i >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      expo_y = xx.i & 1;
      xx.i += (((temp == 0x80000000) ? expo_y : (temp >> 31))
               && rndNearest);
      xx.i = xx.i + (expo_x << 23);
      return xx.f;
    }
    if ((int)expo_x >= 254) {

        xx.i = ((xx.i & 0x80000000) | 0x7f800000) - (!rndNearest);
        return xx.f;
    }

    expo_y = expo_x + 32;
    yy.i = xx.i & 0x80000000;
    xx.i = xx.i & ~0xff000000;

    expo_x = (unsigned int)(-((int)expo_x));
    temp = xx.i << expo_y | ((temp) ? 1 : 0);
    xx.i = yy.i | (xx.i >> expo_x);
    xx.i += (((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31))
             && rndNearest);
    return xx.f;
  } else {

    if (!(yy.i << 1)) {
      if (xx.i == 0x80000000) {
          xx.i = yy.i;
      }
      if ((xx.i << 1) > 0xff000000) {
          xx.i |= 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {

      if (expo_x == (unsigned int) -1) {
        temp = xx.i & 0x80000000;
        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        expo_x++;
        xx.i = (xx.i >> 8) | temp;
      }
      if (expo_y == (unsigned int) -1) {
        temp = yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        expo_y++;
        yy.i = (yy.i >> 8) | temp;
      }
      goto add;
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xff000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xff000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    if ((expo_x == 0xff000000) && (expo_y == 0xff000000)) {




      expo_x = xx.i ^ yy.i;
      xx.i = xx.i | ((expo_x) ? 0xffc00000 : 0);
      return xx.f;
    }

    if (expo_y == 0xff000000) {
      xx.i = yy.i;
    }
    return xx.f;
  }
}

static float __fadd_rz(float a, float b)
{
  return __internal_fadd_kernel(a, b, 0);
}

static float __fmul_rz(float a, float b)
{
  return __internal_fmul_kernel(a, b, 0);
}

static float __fadd_rn(float a, float b)
{
  return __internal_fadd_kernel(a, b, 1);
}

static float __fmul_rn(float a, float b)
{
  return __internal_fmul_kernel(a, b, 1);
}

static void __brkpt(int c)
{

}
# 1164 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 1185 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
static void __trap(void)
{
  __builtin_trap();
}
# 1207 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
static float __fdividef(float a, float b)
{






  if (__cuda_fabsf(b) > 8.507059173e37f) {
    if (__cuda_fabsf(a) <= 3.402823466e38f) {
      return ((a / b) / 3.402823466e38f) / 3.402823466e38f;
    } else {
      return __int_as_float(0x7fffffff);
    }
  } else {
    return a / b;
  }

}

static float __sinf(float a)
{
  return sinf(a);
}

static float __cosf(float a)
{
  return cosf(a);
}

static float __log2f(float a)
{
  return log2f(a);
}







static float __internal_accurate_fdividef(float a, float b)
{
  if (__cuda_fabsf(b) > 8.507059173e37f) {
    a *= .25f;
    b *= .25f;
  }
  return __fdividef(a, b);
}

static float __tanf(float a)
{



  return __sinf(a) / __cosf(a);

}

static void __sincosf(float a, float *sptr, float *cptr)
{



  *sptr = __sinf(a);
  *cptr = __cosf(a);

}

static float __expf(float a)
{



  return __cuda_exp2f(a * 1.442695041f);

}

static float __exp10f(float a)
{



  return __cuda_exp2f(a * 3.321928094f);

}

static float __log10f(float a)
{



  return 0.301029996f * __log2f(a);

}

static float __logf(float a)
{



  return 0.693147181f * __log2f(a);

}

static float __powf(float a, float b)
{



  return __cuda_exp2f(b * __log2f(a));

}

static float fdividef(float a, float b)
{





  return __internal_accurate_fdividef(a, b);

}

static int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static int __clzll(long long int a)
{
  int ahi = ((int)((unsigned long long)a >> 32));
  int alo = ((int)((unsigned long long)a & 0xffffffffULL));
  int res;
  if (ahi) {
      res = 0;
  } else {
      res = 32;
      ahi = alo;
  }
  res = res + __clz(ahi);
  return res;
}

static int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}

static int __popcll(unsigned long long int a)
{
  unsigned int ahi = ((unsigned int)(a >> 32));
  unsigned int alo = ((unsigned int)(a & 0xffffffffULL));
  alo = alo - ((alo >> 1) & 0x55555555);
  alo = (alo & 0x33333333) + ((alo >> 2) & 0x33333333);
  ahi = ahi - ((ahi >> 1) & 0x55555555);
  ahi = (ahi & 0x33333333) + ((ahi >> 2) & 0x33333333);
  alo = alo + ahi;
  alo = (alo & 0x0f0f0f0f) + ((alo >> 4) & 0x0f0f0f0f);
  alo = ((__umul24(alo, 0x808080) << 1) + alo) >> 24;
  return alo;
}
# 1426 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
static double fdivide(double a, double b)
{
  return a / b;
}



static int __internal_double2int(double a, enum cudaRoundMode rndMode);
static unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode);
static long long int __internal_double2ll(double a, enum cudaRoundMode rndMode);
static unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode);

static int __double2int_rz(double a)
{
  return __internal_double2int(a, cudaRoundZero);
}

static unsigned int __double2uint_rz(double a)
{
  return __internal_double2uint(a, cudaRoundZero);
}

static long long int __double2ll_rz(double a)
{
  return __internal_double2ll(a, cudaRoundZero);
}

static unsigned long long int __double2ull_rz(double a)
{
  return __internal_double2ull(a, cudaRoundZero);
}
# 1470 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/sm_11_atomic_functions.h" 1 3
# 257 "/home/gdiamos/temp/cuda/bin//../include/sm_11_atomic_functions.h" 3
static int __iAtomicAdd(int *address, int val)
{
  int old = *address;

  *address = old + val;

  return old;
}

static unsigned int __uAtomicAdd(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old + val;

  return old;
}

static int __iAtomicExch(int *address, int val)
{
  int old = *address;

  *address = val;

  return old;
}

static unsigned int __uAtomicExch(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = val;

  return old;
}

static float __fAtomicExch(float *address, float val)
{
  float old = *address;

  *address = val;

  return old;
}

static int __iAtomicMin(int *address, int val)
{
  int old = *address;

  *address = old < val ? old : val;

  return old;
}

static unsigned int __uAtomicMin(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old < val ? old : val;

  return old;
}

static int __iAtomicMax(int *address, int val)
{
  int old = *address;

  *address = old > val ? old : val;

  return old;
}

static unsigned int __uAtomicMax(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old > val ? old : val;

  return old;
}

static unsigned int __uAtomicInc(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = (old >= val) ? 0 : old + 1;

  return old;
}

static unsigned int __uAtomicDec(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = ((old == 0) | (old > val)) ? val : (old - 1);

  return old;
}

static int __iAtomicAnd(int *address, int val)
{
  int old = *address;

  *address = old & val;

  return old;
}

static unsigned int __uAtomicAnd(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old & val;

  return old;
}

static int __iAtomicOr(int *address, int val)
{
  int old = *address;

  *address = old | val;

  return old;
}

static unsigned int __uAtomicOr(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old | val;

  return old;
}

static int __iAtomicXor(int *address, int val)
{
  int old = *address;

  *address = old ^ val;

  return old;
}

static unsigned int __uAtomicXor(unsigned int *address, unsigned int val)
{
  unsigned int old = *address;

  *address = old ^ val;

  return old;
}

static int __iAtomicCAS(int *address, int compare, int val)
{
  int old = *address;

  *address = old == compare ? val : old;

  return old;
}

static unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  unsigned int old = *address;

  *address = old == compare ? val : old;

  return old;
}
# 1471 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/sm_12_atomic_functions.h" 1 3
# 118 "/home/gdiamos/temp/cuda/bin//../include/sm_12_atomic_functions.h" 3
static unsigned long long int __ullAtomicAdd(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old = *address;

  *address = old + val;

  return old;
}

static unsigned long long int __ullAtomicExch(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old = *address;

  *address = val;

  return old;
}

static unsigned long long int __ullAtomicCAS(unsigned long long int *address, unsigned long long int compare, unsigned long long int val)
{
  unsigned long long int old = *address;

  *address = old == compare ? val : old;

  return old;
}



static int __any(int cond)
{
  return cond;
}

static int __all(int cond)
{
  return cond;
}
# 1472 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/sm_13_double_functions.h" 1 3
# 266 "/home/gdiamos/temp/cuda/bin//../include/sm_13_double_functions.h" 3
static double __longlong_as_double(long long int a)
{
  volatile union {long long int a; double b;} u;

  u.a = a;

  return u.b;
}

static long long int __double_as_longlong(double a)
{
  volatile union {double a; long long int b;} u;

  u.a = a;

  return u.b;
}

static float __internal_double2float_kernel(double a)
{
  volatile union {
    double d;
    unsigned long long int i;
  } xx;
  volatile union {
    float f;
    unsigned int i;
  } res;
  int shift;
  xx.d = a;
  if (xx.i == 0) return 0.0f;
  res.i = (((unsigned int) (xx.i >> 32)) & 0x80000000);
  if ((xx.i & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
    if ((xx.i & 0x7fffffffffffffffULL) > 0x7ff0000000000000ULL) {

      res.i = 0x7f8fffff;
    } else {

      res.i |= 0x7f800000;
    }
    return res.f;
  }
  shift = ((int) ((xx.i >> 52) & 0x7ff)) - 1023;

  xx.i = (xx.i & 0x000fffffffffffffULL);
  if (shift >= 128) {
    res.i |= 0x7f7fffff;
    return res.f;
  }
  if (shift <= -127) {
    if (shift < -180) {

      xx.i = 0;
    } else {
      xx.i |= 0x0010000000000000ULL;
      xx.i >>= 127 + shift;
    }
  } else {
    res.i |= (unsigned int) (127 + shift) << 23;
  }
  res.i |= ((unsigned int) (xx.i >> 29)) & 0x007fffff;
  xx.i &= 0x1fffffff;
  return res.f;
}

static double __internal_ll2double_kernel(long long int a, enum cudaRoundMode rndMode)
{
  volatile union {
    double d;
    unsigned long long int i;
  } res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  if (a < 0) res.i = (unsigned long long int)-a;
  shift = __internal_normalize64((unsigned long long int*)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if (a < 0) res.i |= 0x8000000000000000ULL;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.d;
}

static double __internal_ull2double_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  volatile union {
    double d;
    unsigned long long int i;
  } res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  shift = __internal_normalize64((unsigned long long int *)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.d;
}

static long long int __internal_double2ll_kernel(double a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  volatile union {
    double d;
    unsigned long long int i;
  } xx, res;
  unsigned long long int t = 0;
  int shift;

  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  shift = (int) (1023 + 62 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL) >> 1;
  if (shift >= 64) {
    t = res.i;
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t &&
          (xx.i > 0x8000000000000000ULL)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && ((long long int)xx.i > 0)) {
    res.i++;
  }
  if ((long long int)xx.i < 0) {
    res.i = (unsigned long long int)(-(long long int)res.i);
  }
  return res.i;
}

static unsigned long long int __internal_double2ull_kernel(double a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  volatile union {
    double d;
    unsigned long long int i;
  } xx, res;
  unsigned long long int t = 0;
  int shift;
  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;

  if (a == 0.0) return 0LL;
  shift = (int) (1023 + 63 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL);
  if (shift >= 64) {
    t = res.i >> (int)(shift > 64);
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.i;
}

static int __double2hiint(double a)
{
  volatile union {
    double d;
    signed int i[2];
  } cvt;

  cvt.d = a;

  return cvt.i[1];
}

static int __double2loint(double a)
{
  volatile union {
    double d;
    signed int i[2];
  } cvt;

  cvt.d = a;

  return cvt.i[0];
}

static double __hiloint2double(int a, int b)
{
  volatile union {
    double d;
    signed int i[2];
  } cvt;

  cvt.i[0] = b;
  cvt.i[1] = a;

  return cvt.d;
}

static float __double2float_rn(double a)
{
  return (float)a;
}

static float __double2float_rz(double a)
{
  return __internal_double2float_kernel(a);
}

static int __internal_double2int(double a, enum cudaRoundMode rndMode)
{
  return (int)__internal_double2ll_kernel(a, 2147483647LL, -2147483648LL, -2147483648LL, rndMode);
}

static int __double2int_rn(double a)
{
  return __internal_double2int(a, cudaRoundNearest);
}

static int __double2int_ru(double a)
{
  return __internal_double2int(a, cudaRoundPosInf);
}

static int __double2int_rd(double a)
{
  return __internal_double2int(a, cudaRoundMinInf);
}

static unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_double2ull_kernel(a, 4294967295ULL, 2147483648ULL, rndMode);
}

static unsigned int __double2uint_rn(double a)
{
  return __internal_double2uint(a, cudaRoundNearest);
}

static unsigned int __double2uint_ru(double a)
{
  return __internal_double2uint(a, cudaRoundPosInf);
}

static unsigned int __double2uint_rd(double a)
{
  return __internal_double2uint(a, cudaRoundMinInf);
}

static long long int __internal_double2ll(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static long long int __double2ll_rn(double a)
{
  return __internal_double2ll(a, cudaRoundNearest);
}

static long long int __double2ll_ru(double a)
{
  return __internal_double2ll(a, cudaRoundPosInf);
}

static long long int __double2ll_rd(double a)
{
  return __internal_double2ll(a, cudaRoundMinInf);
}

static unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static unsigned long long int __double2ull_rn(double a)
{
  return __internal_double2ull(a, cudaRoundNearest);
}

static unsigned long long int __double2ull_ru(double a)
{
  return __internal_double2ull(a, cudaRoundPosInf);
}

static unsigned long long int __double2ull_rd(double a)
{
  return __internal_double2ull(a, cudaRoundMinInf);
}

static double __int2double_rn(int a)
{
  return (double)a;
}

static double __uint2double_rn(unsigned int a)
{
  return (double)a;
}

static double __ll2double_rn(long long int a)
{
  return (double)a;
}

static double __ll2double_rz(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundZero);
}

static double __ll2double_rd(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundMinInf);
}

static double __ll2double_ru(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundPosInf);
}

static double __ull2double_rn(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundNearest);
}

static double __ull2double_rz(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundZero);
}

static double __ull2double_rd(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundMinInf);
}

static double __ull2double_ru(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundPosInf);
}





static double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
{



  struct {
    unsigned int lo;
    unsigned int hi;
  } xx, yy, zz, ww;
  unsigned int s, t, u, prod0, prod1, prod2, prod3, expo_x, expo_y, expo_z;

  xx.hi = __double2hiint(x);
  xx.lo = __double2loint(x);
  yy.hi = __double2hiint(y);
  yy.lo = __double2loint(y);
  zz.hi = __double2hiint(z);
  zz.lo = __double2loint(z);

  expo_z = 0x7FF;
  t = xx.hi >> 20;
  expo_x = expo_z & t;
  expo_x = expo_x - 1;
  t = yy.hi >> 20;
  expo_y = expo_z & t;
  expo_y = expo_y - 1;
  t = zz.hi >> 20;
  expo_z = expo_z & t;
  expo_z = expo_z - 1;

  if (!((expo_x <= 0x7FD) &&
        (expo_y <= 0x7FD) &&
        (expo_z <= 0x7FD))) {





    if (((yy.hi << 1) | (yy.lo != 0)) > 0xffe00000) {
      yy.hi |= 0x00080000;
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) > 0xffe00000) {
      zz.hi |= 0x00080000;
      return __hiloint2double(zz.hi, zz.lo);
    }
    if (((xx.hi << 1) | (xx.lo != 0)) > 0xffe00000) {
      xx.hi |= 0x00080000;
      return __hiloint2double(xx.hi, xx.lo);
    }
# 690 "/home/gdiamos/temp/cuda/bin//../include/sm_13_double_functions.h" 3
    if (((((xx.hi << 1) | xx.lo) == 0) &&
         (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000)) ||
        ((((yy.hi << 1) | yy.lo) == 0) &&
         (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000))) {
      xx.hi = 0xfff80000;
      xx.lo = 0x00000000;
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      if ((((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) ||
          (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000)) {
        if ((int)(xx.hi ^ yy.hi ^ zz.hi) < 0) {
          xx.hi = 0xfff80000;
          xx.lo = 0x00000000;
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
    }




    if (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000) {
      xx.hi = xx.hi ^ (yy.hi & 0x80000000);
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) {
      yy.hi = yy.hi ^ (xx.hi & 0x80000000);
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      return __hiloint2double(zz.hi, zz.lo);
    }





    if ((zz.hi == 0x80000000) && (zz.lo == 0)) {
      if ((((xx.hi << 1) | xx.lo) == 0) ||
          (((yy.hi << 1) | yy.lo) == 0)) {
        if ((int)(xx.hi ^ yy.hi) < 0) {
          return __hiloint2double(zz.hi, zz.lo);
        }
      }
    }



    if ((((zz.hi << 1) | zz.lo) == 0) &&
        ((((xx.hi << 1) | xx.lo) == 0) ||
         (((yy.hi << 1) | yy.lo) == 0))) {
      if (rndMode == cudaRoundMinInf) {
        return __hiloint2double((xx.hi ^ yy.hi ^ zz.hi) & 0x80000000, zz.lo);
      } else {
        zz.hi &= 0x7fffffff;
        return __hiloint2double(zz.hi, zz.lo);
      }
    }




    if ((((xx.hi << 1) | xx.lo) == 0) ||
        (((yy.hi << 1) | yy.lo) == 0)) {
      return __hiloint2double(zz.hi, zz.lo);
    }

    if (expo_x == 0xffffffff) {
      expo_x++;
      t = xx.hi & 0x80000000;
      s = xx.lo >> 21;
      xx.lo = xx.lo << 11;
      xx.hi = xx.hi << 11;
      xx.hi = xx.hi | s;
      if (!xx.hi) {
        xx.hi = xx.lo;
        xx.lo = 0;
        expo_x -= 32;
      }
      while ((int)xx.hi > 0) {
        s = xx.lo >> 31;
        xx.lo = xx.lo + xx.lo;
        xx.hi = xx.hi + xx.hi;
        xx.hi = xx.hi | s;
        expo_x--;
      }
      xx.lo = (xx.lo >> 11);
      xx.lo |= (xx.hi << 21);
      xx.hi = (xx.hi >> 11) | t;
    }
    if (expo_y == 0xffffffff) {
      expo_y++;
      t = yy.hi & 0x80000000;
      s = yy.lo >> 21;
      yy.lo = yy.lo << 11;
      yy.hi = yy.hi << 11;
      yy.hi = yy.hi | s;
      if (!yy.hi) {
        yy.hi = yy.lo;
        yy.lo = 0;
        expo_y -= 32;
      }
      while ((int)yy.hi > 0) {
        s = yy.lo >> 31;
        yy.lo = yy.lo + yy.lo;
        yy.hi = yy.hi + yy.hi;
        yy.hi = yy.hi | s;
        expo_y--;
      }
      yy.lo = (yy.lo >> 11);
      yy.lo |= (yy.hi << 21);
      yy.hi = (yy.hi >> 11) | t;
    }
    if (expo_z == 0xffffffff) {
      expo_z++;
      t = zz.hi & 0x80000000;
      s = zz.lo >> 21;
      zz.lo = zz.lo << 11;
      zz.hi = zz.hi << 11;
      zz.hi = zz.hi | s;
      if (!zz.hi) {
        zz.hi = zz.lo;
        zz.lo = 0;
        expo_z -= 32;
      }
      while ((int)zz.hi > 0) {
        s = zz.lo >> 31;
        zz.lo = zz.lo + zz.lo;
        zz.hi = zz.hi + zz.hi;
        zz.hi = zz.hi | s;
        expo_z--;
      }
      zz.lo = (zz.lo >> 11);
      zz.lo |= (zz.hi << 21);
      zz.hi = (zz.hi >> 11) | t;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx.hi ^ yy.hi;
  t = xx.lo >> 21;
  xx.lo = xx.lo << 11;
  xx.hi = xx.hi << 11;
  xx.hi = xx.hi | t;
  yy.hi = yy.hi & 0x000fffff;
  xx.hi = xx.hi | 0x80000000;
  yy.hi = yy.hi | 0x00100000;

  prod0 = xx.lo * yy.lo;
  prod1 = __umulhi (xx.lo, yy.lo);
  prod2 = xx.hi * yy.lo;
  prod3 = xx.lo * yy.hi;
  prod1 += prod2;
  t = prod1 < prod2;
  prod1 += prod3;
  t += prod1 < prod3;
  prod2 = __umulhi (xx.hi, yy.lo);
  prod3 = __umulhi (xx.lo, yy.hi);
  prod2 += prod3;
  s = prod2 < prod3;
  prod3 = xx.hi * yy.hi;
  prod2 += prod3;
  s += prod2 < prod3;
  prod2 += t;
  s += prod2 < t;
  prod3 = __umulhi (xx.hi, yy.hi) + s;

  yy.lo = prod0;
  yy.hi = prod1;
  xx.lo = prod2;
  xx.hi = prod3;
  expo_x = expo_x - (1023 - 2);
  expo_y = expo_y & 0x80000000;

  if (xx.hi < 0x00100000) {
    s = xx.lo >> 31;
    s = (xx.hi << 1) + s;
    xx.hi = s;
    s = yy.hi >> 31;
    s = (xx.lo << 1) + s;
    xx.lo = s;
    s = yy.lo >> 31;
    s = (yy.hi << 1) + s;
    yy.hi = s;
    s = yy.lo << 1;
    yy.lo = s;
    expo_x--;
  }

  t = 0;
  if (((zz.hi << 1) | zz.lo) != 0) {

    s = zz.hi & 0x80000000;

    zz.hi &= 0x000fffff;
    zz.hi |= 0x00100000;
    ww.hi = 0;
    ww.lo = 0;


    if ((int)expo_z > (int)expo_x) {
      t = expo_z;
      expo_z = expo_x;
      expo_x = t;
      t = zz.hi;
      zz.hi = xx.hi;
      xx.hi = t;
      t = zz.lo;
      zz.lo = xx.lo;
      xx.lo = t;
      t = ww.hi;
      ww.hi = yy.hi;
      yy.hi = t;
      t = ww.lo;
      ww.lo = yy.lo;
      yy.lo = t;
      t = expo_y;
      expo_y = s;
      s = t;
    }



    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 107) {

      t = 0;
      while (expo_z >= 32) {
        t = ww.lo | (t != 0);
        ww.lo = ww.hi;
        ww.hi = zz.lo;
        zz.lo = zz.hi;
        zz.hi = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        t = (t >> expo_z) | (ww.lo << (32 - expo_z)) |
                ((t << (32 - expo_z)) != 0);
        ww.lo = (ww.lo >> expo_z) | (ww.hi << (32 - expo_z));
        ww.hi = (ww.hi >> expo_z) | (zz.lo << (32 - expo_z));
        zz.lo = (zz.lo >> expo_z) | (zz.hi << (32 - expo_z));
        zz.hi = (zz.hi >> expo_z);
      }
    } else {
      t = 1;
      ww.lo = 0;
      ww.hi = 0;
      zz.lo = 0;
      zz.hi = 0;
    }
    if ((int)u < 0) {

      t = (unsigned)(-(int)t);
      s = (t != 0);
      u = yy.lo - s;
      s = u > yy.lo;
      yy.lo = u - ww.lo;
      s += yy.lo > u;
      u = yy.hi - s;
      s = u > yy.hi;
      yy.hi = u - ww.hi;
      s += yy.hi > u;
      u = xx.lo - s;
      s = u > xx.lo;
      xx.lo = u - zz.lo;
      s += xx.lo > u;
      xx.hi = (xx.hi - zz.hi) - s;
      if (!(xx.hi | xx.lo | yy.hi | yy.lo | t)) {

        if (rndMode == cudaRoundMinInf) {
          return __hiloint2double(0x80000000, xx.lo);
        } else {
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
      if ((int)xx.hi < 0) {



        t = ~t;
        yy.lo = ~yy.lo;
        yy.hi = ~yy.hi;
        xx.lo = ~xx.lo;
        xx.hi = ~xx.hi;
        if (++t == 0) {
          if (++yy.lo == 0) {
            if (++yy.hi == 0) {
              if (++xx.lo == 0) {
              ++xx.hi;
              }
            }
          }
        }
        expo_y ^= 0x80000000;
      }


      while (!(xx.hi & 0x00100000)) {
        xx.hi = (xx.hi << 1) | (xx.lo >> 31);
        xx.lo = (xx.lo << 1) | (yy.hi >> 31);
        yy.hi = (yy.hi << 1) | (yy.lo >> 31);
        yy.lo = (yy.lo << 1);
        expo_x--;
      }
    } else {

      yy.lo = yy.lo + ww.lo;
      s = yy.lo < ww.lo;
      yy.hi = yy.hi + s;
      u = yy.hi < s;
      yy.hi = yy.hi + ww.hi;
      u += yy.hi < ww.hi;
      xx.lo = xx.lo + u;
      s = xx.lo < u;
      xx.lo = xx.lo + zz.lo;
      s += xx.lo < zz.lo;
      xx.hi = xx.hi + zz.hi + s;
      if (xx.hi & 0x00200000) {
        t = t | (yy.lo << 31);
        yy.lo = (yy.lo >> 1) | (yy.hi << 31);
        yy.hi = (yy.hi >> 1) | (xx.lo << 31);
        xx.lo = (xx.lo >> 1) | (xx.hi << 31);
        xx.hi = ((xx.hi & 0x80000000) | (xx.hi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  t = yy.lo | (t != 0);
  t = yy.hi | (t != 0);

  xx.hi |= expo_y;
  if (expo_x <= 0x7FD) {

    xx.hi = xx.hi & ~0x00100000;
    s = xx.lo & 1;
    u = xx.lo;
    if (rndMode == cudaRoundNearest) {
      xx.lo += (t == 0x80000000) ? s : (t >> 31);
    } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
               ((rndMode == cudaRoundMinInf) && t && expo_y)) {
      xx.lo += 1;
    }
    xx.hi += (u > xx.lo);
    xx.hi += ((expo_x + 1) << 20);
    return __hiloint2double(xx.hi, xx.lo);
  } else if ((int)expo_x >= 2046) {

    if ((rndMode == cudaRoundNearest) ||
        ((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      xx.hi = (xx.hi & 0x80000000) | 0x7ff00000;
      xx.lo = 0;
    } else {
      xx.hi = (xx.hi & 0x80000000) | 0x7fefffff;
      xx.lo = 0xffffffff;
    }
    return __hiloint2double(xx.hi, xx.lo);
  }

  expo_x = (unsigned)(-(int)expo_x);
  if (expo_x > 54) {

    if (((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      return __hiloint2double(xx.hi & 0x80000000, 1);
    } else {
      return __hiloint2double(xx.hi & 0x80000000, 0);
    }
  }
  yy.hi = xx.hi & 0x80000000;
  xx.hi = xx.hi & ~0xffe00000;
  if (expo_x >= 32) {
    t = xx.lo | (t != 0);
    xx.lo = xx.hi;
    xx.hi = 0;
    expo_x -= 32;
  }
  if (expo_x) {
    t = (t >> expo_x) | (xx.lo << (32 - expo_x)) | (t != 0);
    xx.lo = (xx.lo >> expo_x) | (xx.hi << (32 - expo_x));
    xx.hi = (xx.hi >> expo_x);
  }
  expo_x = xx.lo & 1;
  u = xx.lo;
  if (rndMode == cudaRoundNearest) {
    xx.lo += (t == 0x80000000) ? expo_x : (t >> 31);
  } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
             ((rndMode == cudaRoundMinInf) && t && expo_y)) {
    xx.lo += 1;
  }
  xx.hi += (u > xx.lo);
  xx.hi |= yy.hi;
  return __hiloint2double(xx.hi, xx.lo);
}

static double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static double __dadd_rz(double a, double b)
{
  return __fma_rz(a, 1.0, b);
}

static double __dadd_ru(double a, double b)
{
  return __fma_ru(a, 1.0, b);
}

static double __dadd_rd(double a, double b)
{
  return __fma_rd(a, 1.0, b);
}

static double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, 0.0);
}

static double __dadd_rn(double a, double b)
{
  return __fma_rn(a, 1.0, b);
}

static double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, __longlong_as_double(0x8000000000000000ULL));
}
# 1473 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 2 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/texture_fetch_functions.h" 1 3
# 1910 "/home/gdiamos/temp/cuda/bin//../include/texture_fetch_functions.h" 3
extern void __cudaTextureFetch(const void *tex, void *index, int integer, void *val);

static int4 __itexfetchi(const void *tex, int4 index)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static uint4 __utexfetchi(const void *tex, int4 index)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static float4 __ftexfetchi(const void *tex, int4 index)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static int4 __itexfetch(const void *tex, float4 index, int dim)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static uint4 __utexfetch(const void *tex, float4 index, int dim)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static float4 __ftexfetch(const void *tex, float4 index, int dim)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}
# 1474 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 2 3
# 925 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 2 3


static int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 949 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
extern __attribute__((__weak__)) int min(int a, int b); int min(int a, int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) unsigned int umin(unsigned int a, unsigned int b); unsigned int umin(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) int max(int a, int b); int max(int a, int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak__)) unsigned int umax(unsigned int a, unsigned int b); unsigned int umax(unsigned int a, unsigned int b)
{
  return a > b ? a : b;
}
# 1035 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static float __internal_nearbyintf(float a)
{
  float fa = fabsf(a);

  if (fa >= 8388608.0f) {
    return a;
  } else {
    volatile float u = 8388608.0f + fa;

    u = u - 8388608.0f;
    return copysignf(u, a);
  }
}

static float __internal_fminf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;

  cvta.f = a;
  cvtb.f = b;
  if ((cvta.i << 1) > 0xff000000) return b;
  if ((cvtb.i << 1) > 0xff000000) return a;
  if ((cvta.i | cvtb.i) == 0x80000000) {
    return __int_as_float(0x80000000);
  }
  return a < b ? a : b;
}

static float __internal_fmaxf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;

  cvta.f = a;
  cvtb.f = b;
  if ((cvta.i << 1) > 0xff000000) return b;
  if ((cvtb.i << 1) > 0xff000000) return a;
  if ((cvta.f == 0.0f) && (cvtb.f == 0.0f)) {
    cvta.i &= cvtb.i;
    return cvta.f;
  }
  return a > b ? a : b;
}
# 1123 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static long int __cuda_labs(long int a)
{
  return labs(a);
}

static float __cuda_ceilf(float a)
{
  return ceilf(a);
}

static float __cuda_floorf(float a)
{
  return floorf(a);
}

static float __cuda_sqrtf(float a)
{
   return sqrtf(a);
}

static float __cuda_rsqrtf(float a)
{
   return 1.0f / sqrtf(a);
}

static float __cuda_truncf(float a)
{
  return truncf(a);
}

static int __cuda_max(int a, int b)
{
  return max(a, b);
}

static int __cuda_min(int a, int b)
{
  return min(a, b);
}

static unsigned int __cuda_umax(unsigned int a, unsigned int b)
{
  return umax(a, b);
}

static unsigned int __cuda_umin(unsigned int a, unsigned int b)
{
  return umin(a, b);
}

static long long int __cuda_llrintf(float a)
{



  return __float2ll_rn(a);

}

static long int __cuda_lrintf(float a)
{




  return (long int)__cuda_llrintf(a);




}

static float __cuda_nearbyintf(float a)
{





  return __internal_nearbyintf(a);

}

static float __cuda_fmaxf(float a, float b)
{





  return __internal_fmaxf(a, b);

}

static float __cuda_fminf(float a, float b)
{





  return __internal_fminf(a, b);

}
# 1244 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1258 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static int __cuda___isinff(float a)
{
  return __cuda_fabsf(a) == __int_as_float(0x7f800000);
}

static int __cuda___isnanf(float a)
{
  return !(__cuda_fabsf(a) <= __int_as_float(0x7f800000));
}

static float __cuda_nextafterf(float a, float b)
{
  unsigned int ia;
  unsigned int ib;
  ia = __float_as_int(a);
  ib = __float_as_int(b);




  if (__cuda___isnanf(a) || __cuda___isnanf(b)) return a + b;
  if (__int_as_float (ia | ib) == 0.0f) return __int_as_float(ib);





  if (__int_as_float(ia) == 0.0f) {
    return __cuda_copysignf(__int_as_float(0x00000001), b);
  }

  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  a = __int_as_float(ia);





  return a;
}

static float __cuda_nanf(const char *tagp)
{

  return __int_as_float(0x7fffffff);
}


static float __internal_atanhf_kernel(float a_1, float a_2)
{
  float a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 1.566305595598990E-001f/64.0f;
  t = t * a2 + 1.995081856004762E-001f/16.0f;
  t = t * a2 + 3.333382699617026E-001f/4.0f;
  t = t * a2;
  t = t * a + a_2;
  t = t + a_1;
  return t;
}




static float __internal_atanf_kernel(float a)
{
  float t4, t0, t1;

  t4 = a * a;
  t0 = - 5.674867153f;
  t0 = t4 * - 0.823362947f + t0;
  t0 = t0 * t4 - 6.565555096f;
  t0 = t0 * t4;
  t0 = t0 * a;
  t1 = t4 + 11.33538818f;
  t1 = t1 * t4 + 28.84246826f;
  t1 = t1 * t4 + 19.69667053f;
  t1 = 1.0f / t1;
  a = t0 * t1 + a;
  return a;
}


static float __internal_tan_kernel(float a)
{
  float a2, s, t;

  a2 = a * a;
  t = 4.114678393115178E-003f * a2 - 8.231194034909670E-001f;
  s = a2 - 2.469348886157666E+000f;
  s = 1.0f / s;
  t = t * s;
  t = t * a2;
  t = t * a + a;
  return t;
}

static float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia, e;
  ia = __float_as_int(a);

  if ((ia < 0x00800000) || (ia > 0x7f7fffff)) {
    return __logf(a);
  }

  m = __int_as_float((ia & 0x807fffff) | 0x3f800000);
  e = ((unsigned)ia >> 23) - 127;
  if (m > 1.414213562f) {
    m = m * 0.5f;
    e = e + 1;
  }
  t = m - 1.0f;
  z = m + 1.0f;
  z = t / z;
  z = -t * z;
  z = __internal_atanhf_kernel(t, z);
  z = (float)e * 0.693147181f + z;
  return z;
}

static float2 __internal_log_ep(float a)
{
  float2 res;
  int expo;
  float m;
  float log_hi, log_lo;
  float t_hi, t_lo;
  float f, g, u, v, q;



  float r, s, e;

  expo = (__float_as_int(a) >> 23) & 0xff;


  if (expo == 0) {
    a *= 16777216.0f;
    expo = (__float_as_int(a) >> 23) & 0xff;
    expo -= 24;
  }

  expo -= 127;
  m = __int_as_float((__float_as_int(a) & 0x807fffff) | 0x3f800000);
  if (m > 1.414213562f) {
    m = m * 0.5f;
    expo = expo + 1;
  }






  f = m - 1.0f;
  g = m + 1.0f;
  g = 1.0f / g;
  u = 2.0f * f * g;
  v = u * u;
  q = 1.49356810919559350E-001f/64.0f;
  q = q * v + 1.99887797540072460E-001f/16.0f;
  q = q * v + 3.33333880955515580E-001f/4.0f;
  q = q * v;
  q = q * u;
  log_hi = __int_as_float(__float_as_int(u) & 0xfffff000);
  v = __int_as_float(__float_as_int(f) & 0xfffff000);
  u = 2.0f * (f - log_hi);
  f = f - v;
  u = u - log_hi * v;
  u = u - log_hi * f;
  u = g * u;



  r = log_hi + u;
  s = u - (r - log_hi);
  log_hi = r;
  log_lo = s;

  r = log_hi + q;
  s = ((log_hi - r) + q) + log_lo;
  log_hi = e = r + s;
  log_lo = (r - e) + s;


  t_hi = expo * 0.6931457519f;
  t_lo = expo * 1.4286067653e-6f;


  r = t_hi + log_hi;
  s = (((t_hi - r) + log_hi) + log_lo) + t_lo;
  res.y = e = r + s;
  res.x = (r - e) + s;
  return res;
}

static float __internal_accurate_log2f(float a)
{
  return 1.442695041f * __internal_accurate_logf(a);
}




static float2 __internal_dsmul (float2 x, float2 y)
{
    float2 z;

    volatile float up, vp, u1, u2, v1, v2, mh, ml;



    up = x.y * 4097.0f;
    u1 = (x.y - up) + up;
    u2 = x.y - u1;
    vp = y.y * 4097.0f;
    v1 = (y.y - vp) + vp;
    v2 = y.y - v1;
    mh = __fmul_rn(x.y,y.y);
    ml = (((u1 * v1 - mh) + u1 * v2) + u2 * v1) + u2 * v2;
    ml = (__fmul_rn(x.y,y.x) + __fmul_rn(x.x,y.y)) + ml;
    z.y = up = mh + ml;
    z.x = (mh - up) + ml;
    return z;
}


static unsigned int __cudart_i2opi_f [] = {
  0x3c439041,
  0xdb629599,
  0xf534ddc0,
  0xfc2757d1,
  0x4e441529,
  0xa2f9836e,
};


static float __internal_trig_reduction_kernel(float a, int *quadrant)
{
  float j;
  int q;
  if (__cuda_fabsf(a) > 48039.0f) {

    unsigned int ia = __float_as_int(a);
    unsigned int s = ia & 0x80000000;
    unsigned int result[7];
    unsigned int phi, plo;
    unsigned int hi, lo;
    unsigned int e;
    int idx;
    e = ((ia >> 23) & 0xff) - 128;
    ia = (ia << 8) | 0x80000000;

    idx = 4 - (e >> 5);
    hi = 0;



    for (q = 0; q < 6; q++) {
      plo = __cudart_i2opi_f[q] * ia;
      phi = __umulhi (__cudart_i2opi_f[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q] = lo;
    }
    result[q] = hi;
    e = e & 31;



    hi = result[idx+2];
    lo = result[idx+1];
    if (e) {
      q = 32 - e;
      hi = (hi << e) | (lo >> q);
      lo = (lo << e) | (result[idx] >> q);
    }
    q = hi >> 30;

    hi = (hi << 2) | (lo >> 30);
    lo = (lo << 2);
    e = (hi + (lo > 0)) > 0x80000000;
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned int t;
      hi = ~hi;
      lo = -(int)lo;
      t = (lo == 0);
      hi += t;
      s = s ^ 0x80000000;
    }
    *quadrant = q;

    e = 0;
    while ((int)hi > 0) {
      hi = (hi << 1) | (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xc90fdaa2;
    hi = __umulhi(hi, 0xc90fdaa2);
    if ((int)hi > 0) {
      hi = (hi << 1) | (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | (((e + 126) << 23) + (hi >> 8) + ((hi << 24) >= 0x80000000));
    return __int_as_float(ia);
  }
  q = __float2int_rn(a * 0.636619772f);
  j = (float)q;
  a = a - j * 1.5703125000000000e+000f;
  a = a - j * 4.8351287841796875e-004f;
  a = a - j * 3.1385570764541626e-007f;
  a = a - j * 6.0771005065061922e-011f;
  *quadrant = q;
  return a;
}
# 1597 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
static float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = a - j * 0.6931457519f;
  z = z - j * 1.4286067653e-6f;
  z = z * 1.442695041f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j + scale);
  return z;
}

static float __internal_accurate_expf(float a)
{
  float z;
  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a > 105.0f) z = __int_as_float(0x7f800000);
  return z;
}

static float __internal_accurate_exp10f(float a)
{
  float j, z;
  j = __cuda_truncf(a * 3.321928094f);
  z = a - j * 3.0102920532226563e-001f;
  z = z - j * 7.9034171557301747e-007f;
  z = z * 3.321928094f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j);
  if (a < -46.0f) z = 0.0f;
  if (a > 46.0f) z = __int_as_float(0x7f800000);
  return z;
}

static float __internal_lgammaf_pos(float a)
{
  float sum;
  float s, t;

  if (a == __int_as_float(0x7f800000)) {
    return a;
  }
  if (a >= 3.0f) {
    if (a >= 7.8f) {



      s = 1.0f / a;
      t = s * s;
      sum = 0.77783067e-3f;
      sum = sum * t - 0.2777655457e-2f;
      sum = sum * t + 0.83333273853e-1f;
      sum = sum * s + 0.918938533204672f;
      s = 0.5f * __internal_accurate_logf(a);
      t = a - 0.5f;
      s = s * t;
      t = s - a;
      s = __fadd_rn(s, sum);
      t = t + s;
      return t;
    } else {
      a = a - 3.0f;
      s = - 7.488903254816711E+002f;
      s = s * a - 1.234974215949363E+004f;
      s = s * a - 4.106137688064877E+004f;
      s = s * a - 4.831066242492429E+004f;
      s = s * a - 1.430333998207429E+005f;
      t = a - 2.592509840117874E+002f;
      t = t * a - 1.077717972228532E+004f;
      t = t * a - 9.268505031444956E+004f;
      t = t * a - 2.063535768623558E+005f;
      t = s / t;
      t = t + a;
      return t;
    }
  } else if (a >= 1.5f) {
    a = a - 2.0f;
    t = + 4.959849168282574E-005f;
    t = t * a - 2.208948403848352E-004f;
    t = t * a + 5.413142447864599E-004f;
    t = t * a - 1.204516976842832E-003f;
    t = t * a + 2.884251838546602E-003f;
    t = t * a - 7.382757963931180E-003f;
    t = t * a + 2.058131963026755E-002f;
    t = t * a - 6.735248600734503E-002f;
    t = t * a + 3.224670187176319E-001f;
    t = t * a + 4.227843368636472E-001f;
    t = t * a;
    return t;
  } else if (a >= 0.7f) {
    a = 1.0f - a;
    t = + 4.588266515364258E-002f;
    t = t * a + 1.037396712740616E-001f;
    t = t * a + 1.228036339653591E-001f;
    t = t * a + 1.275242157462838E-001f;
    t = t * a + 1.432166835245778E-001f;
    t = t * a + 1.693435824224152E-001f;
    t = t * a + 2.074079329483975E-001f;
    t = t * a + 2.705875136435339E-001f;
    t = t * a + 4.006854436743395E-001f;
    t = t * a + 8.224669796332661E-001f;
    t = t * a + 5.772156651487230E-001f;
    t = t * a;
    return t;
  } else {
    t = + 3.587515669447039E-003f;
    t = t * a - 5.471285428060787E-003f;
    t = t * a - 4.462712795343244E-002f;
    t = t * a + 1.673177015593242E-001f;
    t = t * a - 4.213597883575600E-002f;
    t = t * a - 6.558672843439567E-001f;
    t = t * a + 5.772153712885004E-001f;
    t = t * a;
    t = t * a + a;
    return -__internal_accurate_logf(t);
  }
}


static float __internal_sin_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = - 1.95152959e-4f;
  z = z * x2 + 8.33216087e-3f;
  z = z * x2 - 1.66666546e-1f;
  z = z * x2;
  z = z * x + x;

  return z;
}


static float __internal_cos_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = 2.44331571e-5f;
  z = z * x2 - 1.38873163e-3f;
  z = z * x2 + 4.16666457e-2f;
  z = z * x2 - 5.00000000e-1f;
  z = z * x2 + 1.00000000e+0f;
  return z;
}

static float __internal_accurate_sinf(float a)
{
  float z;
  int i;

  if ((__cuda___isinff(a)) || (a == 0.0f)) {
    return __fmul_rn (a, 0.0f);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}







static float __cuda_rintf(float a)
{



  return __cuda_nearbyintf(a);

}

static float __cuda_sinf(float a)
{





  return __internal_accurate_sinf(a);

}

static float __cuda_cosf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __int_as_float(0x7fffffff);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  i++;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;

}

static float __cuda_tanf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __int_as_float(0x7fffffff);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  z = __internal_tan_kernel(z);
  if (i & 1) {
    z = -1.0f / z;
  }
  return z;

}

static float __cuda_log2f(float a)
{





  return __internal_accurate_log2f(a);

}

static float __cuda_expf(float a)
{





  return __internal_accurate_expf(a);

}

static float __cuda_exp10f(float a)
{





  return __internal_accurate_exp10f(a);

}

static float __cuda_coshf(float a)
{
  float z;

  a = __cuda_fabsf(a);
  z = __internal_expf_kernel(a, -2.0f);
  z = 2.0f * z + 0.125f / z;
  if (a >= 90.0f) {
    z = __int_as_float(0x7f800000);
  }
  return z;
}

static float __cuda_sinhf(float a)
{
  float s, z;

  s = a;
  a = __cuda_fabsf(a);
  if (a < 1.0f) {
    float a2 = a * a;

    z = 2.816951222e-6f;
    z = z * a2 + 1.983615978e-4f;
    z = z * a2 + 8.333350058e-3f;
    z = z * a2 + 1.666666650e-1f;
    z = z * a2;
    z = z * a + a;
  } else {
    z = __internal_expf_kernel(a, -2.0f);
    z = 2.0f * z - 0.125f / z;
    if (a >= 90.0f) {
      z = __int_as_float(0x7f800000);
    }
  }
  return __cuda_copysignf(z, s);
}

static float __cuda_tanhf(float a)
{
  float s, t;

  t = __cuda_fabsf(a);
  if (t < 0.55f) {
    float z, z2;
    z = t;
    z2 = z * z;
    t = 1.643758066599993e-2f;
    t = t * z2 - 5.267181327760551e-2f;
    t = t * z2 + 1.332072505223051e-1f;
    t = t * z2 - 3.333294663641083e-1f;
    t = t * z2;
    s = t * z + z;
  } else {
    s = 1.0f - 2.0f / (__internal_expf_kernel(2.0f * t, 0.0f) + 1.0f);
    if (t >= 88.0f) {
      s = 1.0f;
    }
  }
  return __cuda_copysignf(s, a);
}

static float __cuda_atan2f(float a, float b)
{



  float t0, t1, t3, fa, fb;



  fb = __cuda_fabsf(b);
  fa = __cuda_fabsf(a);

  if (fa == 0.0f && fb == 0.0f) {
    t3 = __cuda___signbitf(b) ? 3.141592654f : 0;
  } else if ((fa == __int_as_float(0x7f800000)) && (fb == __int_as_float(0x7f800000))) {
    t3 = __cuda___signbitf(b) ? 2.356194490f : 0.785398163f;
  } else {

    if (fb < fa) {
      t0 = fa;
      t1 = fb;
    } else {
      t0 = fb;
      t1 = fa;
    }
    t3 = __internal_accurate_fdividef(t1, t0);
    t3 = __internal_atanf_kernel(t3);

    if (fa > fb) t3 = 1.570796327f - t3;
    if (b < 0.0f) t3 = 3.141592654f - t3;
  }
  t3 = __cuda_copysignf(t3, a);

  return t3;

}

static float __cuda_atanf(float a)
{
  float t0, t1;


  t0 = __cuda_fabsf(a);
  t1 = t0;
  if (t0 > 1.0f) {
    t1 = 1.0f / t1;
  }

  t1 = __internal_atanf_kernel(t1);

  if (t0 > 1.0f) {
    t1 = 1.570796327f - t1;
  }
  return __cuda_copysignf(t1, a);
}


static float __internal_asinf_kernel(float a)
{
  float t2, t3, t4;

  t2 = a * a;
  t3 = - 0.501162291f;
  t3 = t3 * t2 + 0.915201485f;
  t3 = t3 * t2;
  t3 = t3 * a;
  t4 = t2 - 5.478654385f;
  t4 = t4 * t2 + 5.491230488f;
  t4 = 1.0f / t4;
  a = t3 * t4 + a;
  return a;
}

static float __cuda_asinf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.575f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t2 = -2.0f * t1 + 1.570796327f;
  if (t0 > 0.575f) {
    t1 = t2;
  }
  return __cuda_copysignf(t1, a);
}

static float __cuda_acosf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.575f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t1 = t0 > 0.575f ? 2.0f * t1 : 1.570796327f - t1;
  if (__cuda___signbitf(a)) {
    t1 = 3.141592654f - t1;
  }
  return t1;
}

static float __cuda_logf(float a)
{





  return __internal_accurate_logf(a);

}

static float __cuda_log10f(float a)
{





  return 0.434294482f * __internal_accurate_logf(a);

}

static float __cuda_log1pf(float a)
{



  float t;




  if (a >= -0.394f && a <= 0.65f) {

    t = a + 2.0f;
    t = a / t;
    t = -a * t;
    t = __internal_atanhf_kernel (a, t);
  } else {
    t = __internal_accurate_logf (1.0f + a);
  }
  return t;

}

static float __cuda_acoshf(float a)
{



  float t;

  t = a - 1.0f;
  if (__cuda_fabsf(t) > 8388608.0f) {

    return 0.693147181f + __internal_accurate_logf(a);
  } else {
    t = t + __cuda_sqrtf(a * t + t);
    return __cuda_log1pf(t);
  }

}

static float __cuda_asinhf(float a)
{



  float fa, oofa, t;

  fa = __cuda_fabsf(a);
  if (fa > 8.507059173e37f) {
    t = 0.693147181f + __logf(fa);
  } else {
    oofa = 1.0f / fa;
    t = fa + fa / (oofa + __cuda_sqrtf(1.0f + oofa * oofa));
    t = __cuda_log1pf(t);
  }
  return __cuda_copysignf(t, a);

}

static float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = (2.0f * fa) / (1.0f - fa);
  t = 0.5f * __cuda_log1pf(t);
  return __cuda_copysignf(t, a);

}

static float __cuda_expm1f(float a)
{
  float t, z, j, u;

  t = __cuda_rintf (a * 1.442695041f);
  z = a - t * 0.6931457519f;
  z = z - t * 1.4286067653e-6f;

  if (__cuda_fabsf(a) < 0.41f) {
    z = a;
    t = 0.0f;
  }

  j = t;
  if (t == 128.0f) j = j - 1.0f;

  u = 1.38795078474044430E-003f;
  u = u * z + 8.38241261853264930E-003f;
  u = u * z + 4.16678317762833940E-002f;
  u = u * z + 1.66663978874356580E-001f;
  u = u * z + 4.99999940395997040E-001f;
  u = u * z;
  u = u * z + z;
  if (a == 0.0f) u = a;

  z = __cuda_exp2f (j);
  a = z - 1.0f;
  if (a != 0.0f) u = u * z + a;
  if (t == 128.0f) u = u + u;

  if (j > 128.0f) u = __int_as_float(0x7f800000);
  if (j < -25.0f) u = -1.0f;
  return u;
}

static float __cuda_hypotf(float a, float b)
{



  float v, w, t;

  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);

  if (a > b) {
    v = a;
    w = b;
  } else {
    v = b;
    w = a;
  }
  t = __internal_accurate_fdividef(w, v);
  t = 1.0f + t * t;
  t = v * __cuda_sqrtf(t);
  if (v == 0.0f) {
    t = v + w;
  }
  if ((v == __int_as_float(0x7f800000)) || (w == __int_as_float(0x7f800000))) {
    t = __int_as_float(0x7f800000);
  }
  return t;

}

static float __cuda_cbrtf(float a)
{



  float s, t;

  s = __cuda_fabsf(a);
  if ((a == 0.0f) || (s == __int_as_float(0x7f800000))) {
    return a;
  }
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t - (t - (s / (t * t))) * 0.333333333f;
  if (__cuda___signbitf(a)) {
     t = -t;
  }
  return t;

}

static float __cuda_erff(float a)
{
  float t, r, q;

  t = __cuda_fabsf(a);
  if (t < 1.0f) {
    t = t * t;
    r = -5.58510127926029810E-004f;
    r = r * t + 4.90688891415893070E-003f;
    r = r * t - 2.67027980930150640E-002f;
    r = r * t + 1.12799056505903940E-001f;
    r = r * t - 3.76122956138427440E-001f;
    r = r * t + 1.12837911712623450E+000f;
    a = a * r;
  } else if (t <= __int_as_float(0x7f800000)) {



    q = 0.3275911f * t + 1.0f;
    q = 1.0f / q;
    r = 1.061405429f;
    r = r * q - 1.453152027f;
    r = r * q + 1.421413741f;
    r = r * q - 0.284496736f;
    r = r * q + 0.254829592f;
    r = r * q;
    q = __internal_expf_kernel(-a * a, 0.0f);
    r = 1.0f - q * r;
    if (t >= 5.5f) {
      r = 1.0f;
    }
    a = __int_as_float (__float_as_int(r) | (__float_as_int(a) & 0x80000000));
  }
  return a;
}

static float __cuda_erfcf(float a)
{
  if (a <= 0.55f) {
    return 1.0f - __cuda_erff(a);
  } else if (a > 10.0f) {
    return 0.0f;
  } else {
    float p;
    float q;
    float h;
    float l;




    p = + 4.014893410762552E-006f;
    p = p * a + 5.640401259462436E-001f;
    p = p * a + 2.626649872281140E+000f;
    p = p * a + 5.486372652389673E+000f;
    p = p * a + 5.250714831459401E+000f;
    q = a + 4.651376250488319E+000f;
    q = q * a + 1.026302828878470E+001f;
    q = q * a + 1.140762166021288E+001f;
    q = q * a + 5.251211619089947E+000f;

    h = 1.0f / q;
    q = 2.0f * h - q * h * h;
    p = p * q;

    h = __int_as_float(__float_as_int(a) & 0xfffff000);
    l = __fadd_rn (a, -h);
    q = __fmul_rn (-h, h);
    q = __internal_expf_kernel(q, 0.0f);
    a = a + h;
    l = l * a;
    h = __internal_expf_kernel(-l, 0.0f);
    q = q * h;
    p = p * q;
    return p;
  }
}

static float __cuda_lgammaf(float a)
{
  float t;
  float i;
  int quot;
  t = __internal_lgammaf_pos(__cuda_fabsf(a));
  if (a >= 0.0f) return t;
  a = __cuda_fabsf(a);
  i = __cuda_floorf(a);
  if (a == i) return __int_as_float(0x7f800000);
  if (a < 1e-19f) return -__internal_accurate_logf(a);
  i = __cuda_rintf (2.0f * a);
  quot = (int)i;
  i = a - 0.5f * i;
  i = i * 3.141592654f;
  if (quot & 1) {
    i = __internal_cos_kernel(i);
  } else {
    i = __internal_sin_kernel(i);
  }
  i = __cuda_fabsf(i);
  t = 1.144729886f - __internal_accurate_logf(i * a) - t;
  return t;
}

static float __cuda_ldexpf(float a, int b)
{



  float fa = __cuda_fabsf(a);

  if ((fa == 0.0f) || (fa == __int_as_float(0x7f800000)) || (b == 0)) {
    return a;
  }
  else if (__cuda_abs(b) < 126) {
    return a * __cuda_exp2f((float)b);
  }
  else if (__cuda_abs(b) < 252) {
    int bhalf = b / 2;
    return a * __cuda_exp2f((float)bhalf) * __cuda_exp2f((float)(b - bhalf));
  }
  else {
    int bquarter = b / 4;
    float t = __cuda_exp2f((float)bquarter);
    return a * t * t * t * __cuda_exp2f((float)(b - 3 * bquarter));
  }

}

static float __cuda_scalbnf(float a, int b)
{




  return __cuda_ldexpf(a, b);

}

static float __cuda_scalblnf(float a, long int b)
{



  int t;
  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return __cuda_scalbnf(a, t);

}

static float __cuda_frexpf(float a, int *b)
{
  float fa = __cuda_fabsf(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < 1.175494351e-38f) {
    a *= 16777216.0f;
    denorm = 24;
  } else {
    denorm = 0;
  }
  expo = ((__float_as_int(a) >> 23) & 0xff);
  if ((fa == 0.0f) || (expo == 0xff)) {
    expo = 0;
    a = a + a;
  } else {
    expo = expo - denorm - 126;
    a = __int_as_float(((__float_as_int(a) & 0x807fffff) | 0x3f000000));
  }
  *b = expo;
  return a;
}

static float __cuda_modff(float a, float *b)
{



  float t;
  if (__cuda___finitef(a)) {
    t = __cuda_truncf(a);
    *b = t;
    t = a - t;
    return __cuda_copysignf(t, a);
  } else if (__cuda___isinff(a)) {
    t = 0.0f;
    *b = a;
    return __cuda_copysignf(t, a);
  } else {
    *b = a;
    return a;
  }

}

static float __cuda_fmodf(float a, float b)
{



  float orig_a = a;
  float orig_b = b;
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __int_as_float(0x7fffffff);
  } else if (a >= b) {


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }







    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5f;
    }
    return __cuda_copysignf(a, orig_a);
  } else {
    return orig_a;
  }

}

static float __cuda_remainderf(float a, float b)
{

  float twoa = 0.0f;
  unsigned int quot0 = 0;
  float orig_a = a;
  float orig_b = b;

  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __int_as_float(0x7fffffff);
  } else if (a >= b) {

    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2509 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        twoa = (2.0f * a - scaled_b) - scaled_b;
        a -= scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5f;
    }
  }


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
    a = __cuda_copysignf (a, -1.0f);
  }
# 2541 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static float __cuda_remquof(float a, float b, int* quo)
{
  float twoa = 0.0f;
  unsigned int quot = 0;
  unsigned int sign;
  float orig_a = a;
  float orig_b = b;


  sign = 0 - (__cuda___signbitf(a) != __cuda___signbitf(b));
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    *quo = quot;
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    *quo = quot;
    return __int_as_float(0x7fffffff);
  } else if (a >= b) {


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2594 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        twoa = (2.0f * a - scaled_b) - scaled_b;
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5f;
    }
  }


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
    a = __cuda_copysignf (a, -1.0f);
  }
# 2629 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static float __cuda_fmaf(float a, float b, float c)
{
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);
# 2655 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return __int_as_float(0x7fffffff);
    }
    if ((zz << 1) > 0xff000000) {
      return __int_as_float(0x7fffffff);
    }
    if ((xx << 1) > 0xff000000) {
      return __int_as_float(0x7fffffff);
    }
# 2690 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return __int_as_float(0x7fffffff);
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return __int_as_float(0x7fffffff);
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }

    if (expo_x == (unsigned int)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned int)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned int)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  s = __umulhi(xx, yy);
  yy = xx * yy;
  xx = s;
  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;


  if (xx < 0x00800000) {
      xx = (xx << 1) | (yy >> 31);
      yy = (yy << 1);
      expo_x--;
  }
  temp = 0;
  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }
    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        return __int_as_float(xx);
      }
      if ((int)xx < 0) {



        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    s = xx & 1;
    xx += (temp == 0x80000000) ? s : (temp >> 31);
    xx = xx + (expo_x << 23);
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {

    xx = expo_y | 0x7f800000;
    return __int_as_float(xx);
  }

  expo_x = (unsigned int)(-(int)expo_x);
  if (expo_x > 25) {

    return __int_as_float(expo_y);
  }
  yy = (xx << (32 - expo_x)) | ((yy) ? 1 : 0);
  xx = expo_y + (xx >> expo_x);
  xx = xx + ((yy==0x80000000) ? (xx & 1) : (yy >> 31));
  xx |= expo_y;




  return __int_as_float(xx);
}

static float __internal_accurate_powf(float a, float b)
{
  float2 loga, prod;



  float t;



  loga = __internal_log_ep(a);


  if (__cuda_fabsf(b) > 1.0e34f) b *= 1.220703125e-4f;
  prod.y = b;
  prod.x = 0.0f;
  prod = __internal_dsmul (prod, loga);


  if (__float_as_int(prod.y) == 0x42b17218) {
    prod.y = __int_as_float(__float_as_int(prod.y) - 1);
    prod.x = prod.x + __int_as_float(0x37000000);
  }


  t = __cuda_expf(prod.y);

  if (t != __int_as_float(0x7f800000)) {



    t = t * prod.x + t;
  }
  return t;
}

static float __cuda_powif(float a, int b)
{
  unsigned int e = __cuda_abs(b);
  float r = 1.0f;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0f/r : r;
    }
    a = a * a;
  }
}

static double __cuda_powi(double a, int b)
{
  unsigned int e = __cuda_abs(b);
  double r = 1.0;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0/r : r;
    }
    a = a * a;
  }
}

static float __cuda_powf(float a, float b)
{





  int bIsOddInteger;
  float t;
  if (a == 1.0f || b == 0.0f) {
    return 1.0f;
  }
  if (__cuda___isnanf(a) || __cuda___isnanf(b)) {
    return a + b;
  }
  if (a == __int_as_float(0x7f800000)) {
    return __cuda___signbitf(b) ? 0.0f : __int_as_float(0x7f800000);
  }
  if (__cuda___isinff(b)) {
    if (a == -1.0f) {
      return 1.0f;
    }
    t = (__cuda_fabsf(a) > 1.0f) ? __int_as_float(0x7f800000) : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t;
  }
  bIsOddInteger = (b - (2.0f * floorf(0.5f * b))) == 1.0f;
  if (a == 0.0f) {
    t = bIsOddInteger ? a : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t;
  }
  if (a == -__int_as_float(0x7f800000)) {
    t = (b < 0.0f) ? -1.0f/a : -a;
    if (bIsOddInteger) {
      t = __int_as_float(__float_as_int(t) ^ 0x80000000);
    }
    return t;
  }
  if ((a < 0.0f) && (b != __cuda_truncf(b))) {
    return __int_as_float(0x7fffffff);
  }
  t = __cuda_fabsf(a);
  t = __internal_accurate_powf(t, b);
  if ((a < 0.0f) && bIsOddInteger) {
    t = __int_as_float(__float_as_int(t) ^ 0x80000000);
  }
  return t;

}


static float __internal_tgammaf_kernel(float a)
{
  float t;
  t = - 1.05767296987211380E-003f;
  t = t * a + 7.09279059435508670E-003f;
  t = t * a - 9.65347121958557050E-003f;
  t = t * a - 4.21736613253687960E-002f;
  t = t * a + 1.66542401247154280E-001f;
  t = t * a - 4.20043267827838460E-002f;
  t = t * a - 6.55878234051332940E-001f;
  t = t * a + 5.77215696929794240E-001f;
  t = t * a + 1.00000000000000000E+000f;
  return t;
}





static float __cuda_tgammaf(float a)
{
  float s, xx, x=a;
  if (x >= 0.0f) {
    if (x > 36.0f) x = 36.0f;
    s = 1.0f;
    xx = x;
    if (x > 34.03f) {
      xx -= 1.0f;
    }
    while (xx > 1.5f) {
      xx = xx - 1.0f;
      s = s * xx;
    }
    if (x >= 0.5f) {
      xx = xx - 1.0f;
    }
    xx = __internal_tgammaf_kernel(xx);
    if (x < 0.5f) {
      xx = xx * x;
    }
    s = s / xx;
    if (x > 34.03f) {

      xx = x - 1.0f;
      s = s * xx;
    }
    return s;
  } else {
    if (x == __cuda_floorf(x)) {
      x = __int_as_float(0x7fffffff);

      return x;

    }
    if (x < -41.1f) x = -41.1f;
    xx = x;
    if (x < -34.03f) {
      xx += 6.0f;
    }
    s = xx;
    while (xx < -0.5f) {
      xx = xx + 1.0f;
      s = s * xx;
    }
    xx = __internal_tgammaf_kernel(xx);
    s = s * xx;
    s = 1.0f / s;
    if (x < -34.03f) {
      xx = x;
      xx *= (x + 1.0f);
      xx *= (x + 2.0f);
      xx *= (x + 3.0f);
      xx *= (x + 4.0f);
      xx *= (x + 5.0f);
      xx = 1.0f / xx;
      s = s * xx;
      if ((a < -42.0f) && !(((int)a)&1)) {
        s = __int_as_float(0x80000000);
      }
    }
    return s;
  }
}

static float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  if (fa > 8388608.0f) {
    return a;
  } else {
    float u = __cuda_floorf(fa + 0.5f);
    if (fa < 0.5f) u = 0.0f;
    return __cuda_copysignf(u, a);
  }

}

static long long int __internal_llroundf_kernel(float a)
{
  unsigned long long int res, t = 0LL;
  int shift;
  unsigned int ia = __float_as_int(a);
  if ((ia << 1) > 0xff000000) return 0LL;
  if ((int)ia >= 0x5f000000) return 0x7fffffffffffffffLL;
  if (ia >= 0xdf000000) return 0x8000000000000000LL;
  shift = 189 - ((ia >> 23) & 0xff);
  res = ((long long int)(((ia << 8) | 0x80000000) >> 1)) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (t >= 0x8000000000000000LL) {
      res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)(-(long long int)res);
  return (long long int)res;
}

static long long int __cuda_llroundf(float a)
{



  return __internal_llroundf_kernel(a);

}

static long int __cuda_lroundf(float a)
{




  return (long int)__cuda_llroundf(a);
# 3192 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
}

static float __cuda_fdimf(float a, float b)
{
  float t;
  t = a - b;
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static int __cuda_ilogbf(float a)
{
  unsigned int i;
  int expo;
  a = __cuda_fabsf(a);
  if (a <= 1.175494351e-38f) {

    if (a == 0.0f) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    } else {
      expo = -126;
      i = __float_as_int(a);
      i = i << 8;
      while ((int)i >= 0) {
        expo--;
        i = i + i;
      }
    }
  } else {
    i = __float_as_int(a);
    expo = ((int)((i >> 23) & 0xff)) - 127;
    if ((i == 0x7f800000)) {
      expo = ((int)((unsigned int)-1 >> 1));
    }
    if ((i > 0x7f800000)) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    }
  }
  return expo;
}

static float __cuda_logbf(float a)
{



  unsigned int i;
  int expo;
  float res;

  if (__cuda___isnanf(a)) return a + a;

  a = __cuda_fabsf(a);
  if (a <= 1.175494351e-38f) {

    if (a == 0.0f) {
      res = -__int_as_float(0x7f800000);
    } else {
      expo = -126;
      i = __float_as_int(a);
      i = i << 8;
      while ((int)i >= 0) {
        expo--;
        i = i + i;
      }
      res = (float)expo;
    }
  } else {
    i = __float_as_int(a);
    expo = ((int)((i >> 23) & 0xff)) - 127;
    res = (float)expo;
    if ((i >= 0x7f800000)) {

      res = a + a;
    }
  }
  return res;

}

static void __cuda_sincosf(float a, float *sptr, float *cptr)
{





  float t, u, s, c;
  int quadrant;
  if (__cuda___isinff(a)) {
    *sptr = __int_as_float(0x7fffffff);
    *cptr = __int_as_float(0x7fffffff);
    return;
  }
  if (a == 0.0f) {
    *sptr = a;
    *cptr = 1.0f;
    return;
  }
  t = __internal_trig_reduction_kernel(a, &quadrant);
  u = __internal_cos_kernel(t);
  t = __internal_sin_kernel(t);
  if (quadrant & 1) {
    s = u;
    c = t;
  } else {
    s = t;
    c = u;
  }
  if (quadrant & 2) {
    s = -s;
  }
  quadrant++;
  if (quadrant & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;

}
# 3323 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}
# 3861 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx3.h" 1 3
# 59 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx3.h" 3
static double __cuda_fabs(double a)
{
  return fabs(a);
}

static double __cuda_fmax(double a, double b)
{

  volatile union {
    double d;
    unsigned long long int l;
  } cvta, cvtb;
  cvta.d = a;
  cvtb.d = b;
  if ((cvtb.l << 1) > 0xffe0000000000000ULL) return a;
  if ((cvta.l << 1) > 0xffe0000000000000ULL) return b;
  if ((cvta.d == 0.0) && (cvtb.d == 0.0)) {
    cvta.l &= cvtb.l;
    return cvta.d;
  }
  return a > b ? a : b;



}

static double __cuda_fmin(double a, double b)
{

  volatile union {
    double d;
    unsigned long long int l;
  } cvta, cvtb;
  cvta.d = a;
  cvtb.d = b;
  if ((cvtb.l << 1) > 0xffe0000000000000ULL) return a;
  if ((cvta.l << 1) > 0xffe0000000000000ULL) return b;
  if ((cvta.l | cvtb.l) == 0x8000000000000000ULL) {
    return __longlong_as_double(0x8000000000000000ULL) ;
  }
  return a < b ? a : b;



}

static double __cuda_ceil(double a)
{
  return ceil(a);
}

static double __cuda_floor(double a)
{
  return floor(a);
}

static double __cuda_trunc(double a)
{
  return trunc(a);
}

static double __cuda_nearbyint(double a)
{



  double res = nearbyint(a);





  return res;

}







static double __cuda_rint(double a)
{
  return __cuda_nearbyint(a);
}

static long int __cuda_lrint(double a)
{

  return (long int)__double2ll_rn(a);



}

static long long int __cuda_llrint(double a)
{
  return __double2ll_rn(a);
}

static int __cuda___signbit(double a)
{
  return (int)((unsigned int)__double2hiint(a) >> 31);
}

static int __cuda___finite(double a)
{
  return __cuda_fabs(a) < __longlong_as_double(0x7ff0000000000000ULL);
}

static int __cuda___isinf(double a)
{
  return __cuda_fabs(a) == __longlong_as_double(0x7ff0000000000000ULL);
}

static int __cuda___isnan(double a)
{
  return !(__cuda_fabs(a) <= __longlong_as_double(0x7ff0000000000000ULL));
}

static double __cuda_copysign(double a, double b)
{
  int alo, ahi, bhi;

  bhi = __double2hiint(b);
  alo = __double2loint(a);
  ahi = __double2hiint(a);
  ahi = (bhi & 0x80000000) | (ahi & ~0x80000000);
  return __hiloint2double(ahi, alo);
}


static unsigned long long int __cudart_i2opi_d [] = {
  0x6bfb5fb11f8d5d08ULL,
  0x3d0739f78a5292eaULL,
  0x7527bac7ebe5f17bULL,
  0x4f463f669e5fea2dULL,
  0x6d367ecf27cb09b7ULL,
  0xef2f118b5a0a6d1fULL,
  0x1ff897ffde05980fULL,
  0x9c845f8bbdf9283bULL,
  0x3991d639835339f4ULL,
  0xe99c7026b45f7e41ULL,
  0xe88235f52ebb4484ULL,
  0xfe1deb1cb129a73eULL,
  0x06492eea09d1921cULL,
  0xb7246e3a424dd2e0ULL,
  0xfe5163abdebbc561ULL,
  0xdb6295993c439041ULL,
  0xfc2757d1f534ddc0ULL,
  0xa2f9836e4e441529ULL,
};

static double __internal_trig_reduction_kerneld(double a, int *quadrant)
{
  double j;
  int q;
  if (__cuda_fabs(a) > 2147483648.0) {

    unsigned long long int ia;
    unsigned long long int s;
    unsigned long long int result[5];
    unsigned long long int phi, plo;
    unsigned long long int hi, lo;
    unsigned int e;
    int idx;

    ia = __double_as_longlong(a);
    s = ia & 0x8000000000000000ULL;
    e = (unsigned int)(((ia >> 52) & 0x7ff) - 1024);
    ia = (ia << 11) | 0x8000000000000000ULL;

    idx = 16 - (e >> 6);
    hi = 0;



    for (q = (idx-1); q < min(18,idx+3); q++) {
      plo = __cudart_i2opi_d[q] * ia;
      phi = __umul64hi (__cudart_i2opi_d[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q-(idx-1)] = lo;
    }
    result[q-(idx-1)] = hi;
    e = e & 63;



    hi = result[3];
    lo = result[2];
    if (e) {
      q = 64 - e;
      hi = (hi << e) | (lo >> q);
      lo = (lo << e) | (result[1] >> q);
    }
    q = (int)(hi >> 62);

    hi = (hi << 2) | (lo >> 62);
    lo = (lo << 2);
    e = (hi | (lo > 0)) > 0x8000000000000000ULL;
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned long long int t;
      hi = ~hi;
      lo = -(long long int)lo;
      t = (lo == 0ULL);
      hi += t;
      s = s ^ 0x8000000000000000ULL;
    }
    *quadrant = q;

    e = 0;
    while ((long long int)hi > 0) {
      hi = (hi << 1) | (lo >> 63);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xC90FDAA22168C235ULL;
    hi = __umul64hi (hi, 0xC90FDAA22168C235ULL);
    if ((long long int)hi > 0) {
      hi = (hi << 1) | (lo >> 63);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | ((((unsigned long long int)(e + 1022)) << 52) + (hi >> 11) +
              ((hi << 53) >= 0x8000000000000000ULL));
    return __longlong_as_double(ia);
  }

  q = __double2int_rn (a * 6.3661977236758138e-1);
  j = (double)q;




  a = __fma_rn (-j, 1.5707963267948966e+000, a);
  a = __fma_rn (-j, 6.1232339957367574e-017, a);
  a = __fma_rn (-j, 8.4784276603688985e-032, a);
  *quadrant = q;
  return a;
}


static double __internal_sin_kerneld(double x)
{
  double x2, z;
  x2 = x * x;
  z = 1.5896230157221844E-010;
  z = __fma_rn (z, x2, -2.5050747762850355E-008);
  z = __fma_rn (z, x2, 2.7557313621385676E-006);
  z = __fma_rn (z, x2, -1.9841269829589539E-004);
  z = __fma_rn (z, x2, 8.3333333333221182E-003);
  z = __fma_rn (z, x2, -1.6666666666666630E-001);
  z = z * x2;
  z = __fma_rn (z, x, x);
  return z;
}


static double __internal_cos_kerneld(double x)
{
  double x2, z;
  x2 = x * x;
  z = -1.136788825395985E-011;
  z = __fma_rn (z, x2, 2.087588480545065E-009);
  z = __fma_rn (z, x2, -2.755731555403950E-007);
  z = __fma_rn (z, x2, 2.480158729365970E-005);
  z = __fma_rn (z, x2, -1.388888888888074E-003);
  z = __fma_rn (z, x2, 4.166666666666664E-002);
  z = __fma_rn (z, x2, -5.000000000000000E-001);
  z = __fma_rn (z, x2, 1.000000000000000E+000);
  return z;
}


static double __internal_tan_kerneld(double x, int i)
{
  double x2, z, q;
  x2 = x * x;
  z = 9.8006287203286300E-006;
  z = __fma_rn (z, x2, -2.4279526494179897E-005);
  z = __fma_rn (z, x2, 4.8644173130937162E-005);
  z = __fma_rn (z, x2, -2.5640012693782273E-005);
  z = __fma_rn (z, x2, 6.7223984330880073E-005);
  z = __fma_rn (z, x2, 8.3559287318211639E-005);
  z = __fma_rn (z, x2, 2.4375039850848564E-004);
  z = __fma_rn (z, x2, 5.8886487754856672E-004);
  z = __fma_rn (z, x2, 1.4560454844672040E-003);
  z = __fma_rn (z, x2, 3.5921008885857180E-003);
  z = __fma_rn (z, x2, 8.8632379218613715E-003);
  z = __fma_rn (z, x2, 2.1869488399337889E-002);
  z = __fma_rn (z, x2, 5.3968253972902704E-002);
  z = __fma_rn (z, x2, 1.3333333333325342E-001);
  z = __fma_rn (z, x2, 3.3333333333333381E-001);
  z = z * x2;
  q = __fma_rn (z, x, x);
  if (i) {
    double s = q - x;
    double w = __fma_rn (z, x, -s);
    z = 1.0 / q;
    z = -z;
    s = __fma_rn (q, z, 1.0);
    q = __fma_rn (z, __fma_rn (z, w, s), z);
  }
  return q;
}

static double __cuda_sqrt(double a)
{
  return sqrt(a);
}

static double __cuda_rsqrt(double a)
{

    return 1.0 / sqrt(a);



}


static double __internal_expm1_kernel (double a)
{
  double t;
  t = 2.08842685477913050E-009;
  t = __fma_rn (t, a, 2.51366409033551950E-008);
  t = __fma_rn (t, a, 2.75574612072447230E-007);
  t = __fma_rn (t, a, 2.75571539284473460E-006);
  t = __fma_rn (t, a, 2.48015869443077950E-005);
  t = __fma_rn (t, a, 1.98412699878799470E-004);
  t = __fma_rn (t, a, 1.38888888892029890E-003);
  t = __fma_rn (t, a, 8.33333333327662860E-003);
  t = __fma_rn (t, a, 4.16666666666656370E-002);
  t = __fma_rn (t, a, 1.66666666666667380E-001);
  t = __fma_rn (t, a, 5.00000000000000000E-001);
  t = t * a;
  t = __fma_rn (t, a, a);
  return t;
}


static double __internal_atanh_kernel (double a_1, double a_2)
{
  double a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 7.597322383488143E-002/65536.0;
  t = __fma_rn (t, a2, 6.457518383364042E-002/16384.0);
  t = __fma_rn (t, a2, 7.705685707267146E-002/4096.0);
  t = __fma_rn (t, a2, 9.090417561104036E-002/1024.0);
  t = __fma_rn (t, a2, 1.111112158368149E-001/256.0);
  t = __fma_rn (t, a2, 1.428571416261528E-001/64.0);
  t = __fma_rn (t, a2, 2.000000000069858E-001/16.0);
  t = __fma_rn (t, a2, 3.333333333333198E-001/4.0);
  t = t * a2;
  t = __fma_rn (t, a, a_2);
  t = t + a_1;
  return t;
}

static double __internal_exp2i_kernel(int b)
{
  return __hiloint2double((b + 1023) << 20, 0);
}

static double __internal_half(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi - 0x00100000, ilo);
}

static double __internal_twice(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi + 0x00100000, ilo);
}

static double __cuda_sin(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a) || (a == 0.0)) {
    return __dmul_rn(a, 0.0);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  if (i & 1) {
    z = __internal_cos_kerneld(z);
  } else {
    z = __internal_sin_kerneld(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static double __cuda_cos(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a)) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  i++;
  if (i & 1) {
    z = __internal_cos_kerneld(z);
  } else {
    z = __internal_sin_kerneld(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static void __cuda_sincos(double a, double *sptr, double *cptr)
{
  double t, u, s, c;
  int i;
  if (__cuda___isinf(a)) {
    *sptr = __longlong_as_double(0xfff8000000000000ULL);
    *cptr = __longlong_as_double(0xfff8000000000000ULL);
    return;
  }
  if (a == 0.0) {
    *sptr = a;
    *cptr = 1.0;
    return;
  }
  t = __internal_trig_reduction_kerneld(a, &i);
  u = __internal_cos_kerneld(t);
  t = __internal_sin_kerneld(t);
  if (i & 1) {
    s = u;
    c = t;
  } else {
    s = t;
    c = u;
  }
  if (i & 2) {
    s = -s;
  }
  i++;
  if (i & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;
}

static double __cuda_tan(double a)
{
  double z;
  int i;
  if (__cuda___isinf(a)) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  z = __internal_trig_reduction_kerneld(a, &i);

  z = __internal_tan_kerneld(z, i & 1);
  return z;
}

static double __cuda_log(double a)
{
  double m, f, g, u, v, tmp, q, ulo, log_lo, log_hi;
  int ihi, ilo;
  int e = 0;

  ihi = __double2hiint(a);
  ilo = __double2loint(a);
  if (__cuda___isnan(a)) {
    return a + a;
  }

  if (a < 0.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }

  if (a == 0) {
    return -__longlong_as_double(0x7ff0000000000000ULL);
  }

  if (__cuda___isinf(a)) {
    return a;
  }

  if (a < 2.22507385850720140e-308) {
    a = a * 18014398509481984.0;
    e = -54;
    ihi = __double2hiint(a);
    ilo = __double2loint(a);
  }



  e += ((ihi >> 20) & 0x7ff) - 1023;
  m = __hiloint2double ((ihi & 0x800fffff) | 0x3ff00000, ilo);
  if (m > 1.4142135623730951e+0) {
    m = __internal_half(m);
    e = e + 1;
  }

  f = m - 1.0;
  g = m + 1.0;
  g = 1.0 / g;
  u = f * g;
  u = u + u;

  v = u * u;
  q = 6.7261411553826339E-2/65536.0;
  q = __fma_rn (q, v, 6.6133829643643394E-2/16384.0);
  q = __fma_rn (q, v, 7.6940931149150890E-2/4096.0);
  q = __fma_rn (q, v, 9.0908745692137444E-2/1024.0);
  q = __fma_rn (q, v, 1.1111111499059706E-1/256.0);
  q = __fma_rn (q, v, 1.4285714283305975E-1/64.0);
  q = __fma_rn (q, v, 2.0000000000007223E-1/16.0);
  q = __fma_rn (q, v, 3.3333333333333326E-1/4.0);
  tmp = __internal_twice (f - u);
  tmp = __fma_rn (-u, f, tmp);
  ulo = g * tmp;

  q = q * v;
  q = q * u;

  log_hi = u;
  log_lo = ulo + q;

  q = __fma_rn ( e, 6.9314718055994529e-1, log_hi);
  tmp = __fma_rn (-e, 6.9314718055994529e-1, q);
  tmp = tmp - log_hi;
  log_hi = q;
  log_lo = log_lo - tmp;
  log_lo = __fma_rn (e, 2.3190468138462996e-17, log_lo);
  return log_hi + log_lo;
}


static double2 __internal_ddadd_xgty (double2 x, double2 y)
{
    double2 z;

    volatile double r, s, e;



    r = x.y + y.y;
    e = x.y - r;
    s = ((e + y.y) + y.x) + x.x;
    z.y = e = r + s;
    z.x = (r - e) + s;
    return z;
}


static double2 __internal_ddmul (double2 x, double2 y)
{

    volatile double e;



    double2 t, z;
    t.y = x.y * y.y;
    t.x = __fma_rn (x.y, y.y, -t.y);
    t.x = __fma_rn (x.x, y.x, t.x);
    t.x = __fma_rn (x.y, y.x, t.x);
    t.x = __fma_rn (x.x, y.y, t.x);
    z.y = e = t.y + t.x;
    z.x = (t.y - e) + t.x;
    return z;
}

static double2 __internal_log_ext_prec(double a)
{
  double2 res;
  double2 qq, cc, uu, tt;
  double f, g, u, v, q, ulo, tmp, m;
  int ilo, ihi, expo;

  ihi = __double2hiint(a);
  ilo = __double2loint(a);
  expo = (ihi >> 20) & 0x7ff;

  if (expo == 0) {
    a *= 18014398509481984.0;
    ihi = __double2hiint(a);
    ilo = __double2loint(a);
    expo = (ihi >> 20) & 0x7ff;
    expo -= 54;
  }
  expo -= 1023;




  m = __hiloint2double((ihi & 0x800fffff) | 0x3ff00000, ilo);
  if (m > 1.4142135623730951e+0) {
    m = __internal_half(m);
    expo = expo + 1;
  }





  f = m - 1.0;
  g = m + 1.0;
  g = 1.0 / g;
  u = f * g;
  u = u + u;

  v = u * u;
  q = 6.6253631649203309E-2/65536.0;
  q = __fma_rn (q, v, 6.6250935587260612E-2/16384.0);
  q = __fma_rn (q, v, 7.6935437806732829E-2/4096.0);
  q = __fma_rn (q, v, 9.0908878711093280E-2/1024.0);
  q = __fma_rn (q, v, 1.1111111322892790E-1/256.0);
  q = __fma_rn (q, v, 1.4285714284546502E-1/64.0);
  q = __fma_rn (q, v, 2.0000000000003113E-1/16.0);
  q = q * v;

  tmp = __internal_twice (f - u);
  tmp = __fma_rn (-u, f, tmp);
  ulo = g * tmp;

  qq.y = q;
  qq.x = 0.0;
  uu.y = u;
  uu.x = ulo;
  cc.y = 3.3333333333333331E-1/4.0;
  cc.x = -9.8201492846582465E-18/4.0;
  qq = __internal_ddadd_xgty (cc, qq);

  qq = __internal_ddmul(qq, uu);
  qq = __internal_ddmul(qq, uu);
  qq = __internal_ddmul(qq, uu);
  uu = __internal_ddadd_xgty (uu, qq);
  u = uu.y;
  ulo = uu.x;

  tt.y = expo * 6.9314718055966296e-001;
  tt.x = expo * 2.8235290563031577e-013;

  res = __internal_ddadd_xgty (tt, uu);
  return res;
}

static double __cuda_log2(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 1.4426950408889634e+0, t * 2.0355273740931033e-17);
}

static double __cuda_log10(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 4.3429448190325182e-1, t * 1.09831965021676510e-17);
}

static double __cuda_log1p(double a)
{
  double t;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  if ((a < -0.4) || (a > 6.6666666666666667e-1)) {
    return __cuda_log (a + 1.0);
  }

  t = a + 2.0;
  t = a / t;
  t = -a * t;
  t = __internal_atanh_kernel(a, t);
  return t;
}

static double __internal_exp_kernel(double a, int scale)
{
  double t, fac, z;
  int i;

  t = __cuda_rint (a * 1.4426950408889634e+0);
  i = (int)t;
  z = __fma_rn (t, -6.9314718055994529e-1, a);
  z = __fma_rn (t, -2.3190468138462996e-17, z);
  fac = 2.0;
  if (i <= -1021) {
    i += 55;
    fac = 5.5511151231257827e-17;
  }
  t = __internal_expm1_kernel(z);

  z = __hiloint2double((1022 + i + scale) << 20, 0);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static double __cuda_exp(double a)
{
  if (a > 7.0978271289338397e+2) {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (a <= -7.4513321910194122e+2) {
    return 0.0;
  }
  a = __internal_exp_kernel(a, 0);
  return a;
}

static double __cuda_exp2(double a)
{
  double z;
  double t;
  double fac;
  int i;

  if (a >= 1024.0) {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (a < -1075.0) {
    return 0.0;
  }
  t = __cuda_rint (a);
  z = a - t;
  i = (int)t;
  fac = 2.0;
  if (i <= -1021) {
    i += 55;
    fac = 5.5511151231257827e-17;
  }

  z = __fma_rn (z, 6.9314718055994529e-1, z * 2.3190468138462996e-17);
  t = __internal_expm1_kernel(z);
  z = __hiloint2double((1022 + i) << 20, 0);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static double __cuda_exp10(double a)
{
  double z;
  double t;
  double fac;
  int i;

  if (a >= 3.0825471555991675e+2) {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (a < -3.2360724533877976e+2) {
    return 0.0;
  }
  t = __cuda_rint (a * 3.3219280948873622e+0);
  i = (int)t;
  z = __fma_rn (t, -3.0102999566398120e-1, a);
  z = __fma_rn (t, -(-2.8037281277851704e-18), z);
  fac = 2.0;
  if (i <= -1021) {
    i += 55;
    fac = 5.5511151231257827e-17;
  }

  z = __fma_rn (z, 2.3025850929940459e+0, z * (-2.1707562233822494e-16));
  t = __internal_expm1_kernel(z);

  z = __hiloint2double((1022 + i) << 20, 0);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static double __cuda_expm1(double a)
{
  double t, z, u;
  int i, j;
  if (a > 7.0978271289338397e+2) {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (a < -53.0) {
    return -1.0;
  }
  t = __cuda_rint (a * 1.4426950408889634e+0);
  i = (int)t;
  z = __fma_rn (t, -6.9314718055994529e-1, a);
  z = __fma_rn (t, -2.3190468138462996e-17, z);
  if (__cuda_fabs(a) < 0.405465108) {
    z = a;
    i = 0;
  }
  j = (i == 1024) ? (i - 1) : i;
  t = __internal_expm1_kernel(z);
  u = __hiloint2double((1023 + j) << 20, 0);
  a = u - 1.0;
  t = __fma_rn (t, u, a);
  if (z == 0.0) t = z;
  if (i == 1024) t = t + t;
  return t;
}

static double __cuda_cosh(double a)
{
  double z;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  a = __cuda_fabs(a);
  z = __internal_exp_kernel(a, -2);
  z = __fma_rn(2.0, z, 0.125 / z);
  if (a >= 7.1047586007394398e+2) {
    z = __int_as_float(0x7f800000);
  }
  return z;
}

static double __cuda_sinh(double a)
{
  double s, z;
  s = a;
  a = __cuda_fabs(a);
  if (a < 1.0) {
    double a2 = a * a;

    z = 1.632386098183803E-010;
    z = __fma_rn (z, a2, 2.504854501385687E-008);
    z = __fma_rn (z, a2, 2.755734274788706E-006);
    z = __fma_rn (z, a2, 1.984126976294102E-004);
    z = __fma_rn (z, a2, 8.333333333452911E-003);
    z = __fma_rn (z, a2, 1.666666666666606E-001);
    z = z * a2;
    z = __fma_rn (z, a, a);
  } else if (a < 2.0) {
    z = __cuda_expm1(a);
    z = __internal_half (z + z / (z + 1.0));
  } else {
    z = __internal_exp_kernel(a, -1);
    z = z + (1.0 / (-4.0 * z));
    if (a >= 7.1047586007394398e+2) {
      z = __longlong_as_double(0x7ff0000000000000ULL);
    }
  }
  z = __cuda_copysign(z, s);
  return z;
}

static double __cuda_tanh(double a)
{
  double t;
  t = __cuda_fabs(a);
  if (t >= 0.55) {
    double s;
    s = 1.0 - 2.0 / (__internal_exp_kernel(2.0 * t, 0) + 1.0);
    if (t > 350.0) {
      s = 1.0;
    }
    a = __cuda_copysign(s, a);
  } else {
    double a2;
    a2 = a * a;
    t = 5.102147717274194E-005;
    t = __fma_rn (t, a2, -2.103023983278533E-004);
    t = __fma_rn (t, a2, 5.791370145050539E-004);
    t = __fma_rn (t, a2, -1.453216755611004E-003);
    t = __fma_rn (t, a2, 3.591719696944118E-003);
    t = __fma_rn (t, a2, -8.863194503940334E-003);
    t = __fma_rn (t, a2, 2.186948597477980E-002);
    t = __fma_rn (t, a2, -5.396825387607743E-002);
    t = __fma_rn (t, a2, 1.333333333316870E-001);
    t = __fma_rn (t, a2, -3.333333333333232E-001);
    t = t * a2;
    t = __fma_rn (t, a, a);
    a = __cuda_copysign(t, a);
  }
  return a;
}

static double __internal_atan_kernel(double a)
{
  double t, a2;
  a2 = a * a;
  t = -2.0258553044438358E-005 ;
  t = __fma_rn (t, a2, 2.2302240345758510E-004);
  t = __fma_rn (t, a2, -1.1640717779930576E-003);
  t = __fma_rn (t, a2, 3.8559749383629918E-003);
  t = __fma_rn (t, a2, -9.1845592187165485E-003);
  t = __fma_rn (t, a2, 1.6978035834597331E-002);
  t = __fma_rn (t, a2, -2.5826796814495994E-002);
  t = __fma_rn (t, a2, 3.4067811082715123E-002);
  t = __fma_rn (t, a2, -4.0926382420509971E-002);
  t = __fma_rn (t, a2, 4.6739496199157994E-002);
  t = __fma_rn (t, a2, -5.2392330054601317E-002);
  t = __fma_rn (t, a2, 5.8773077721790849E-002);
  t = __fma_rn (t, a2, -6.6658603633512573E-002);
  t = __fma_rn (t, a2, 7.6922129305867837E-002);
  t = __fma_rn (t, a2, -9.0909012354005225E-002);
  t = __fma_rn (t, a2, 1.1111110678749424E-001);
  t = __fma_rn (t, a2, -1.4285714271334815E-001);
  t = __fma_rn (t, a2, 1.9999999999755019E-001);
  t = __fma_rn (t, a2, -3.3333333333331860E-001);
  t = t * a2;
  t = __fma_rn (t, a, a);
  return t;
}

static double __cuda_atan2(double a, double b)
{
  double t0, t1, t3;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }


  t3 = __cuda_fabs(b);
  t1 = __cuda_fabs(a);
  if (t3 == 0.0 && t1 == 0.0) {
    t3 = __cuda___signbit(b) ? 3.1415926535897931e+0 : 0;
  } else if (__cuda___isinf(t3) && __cuda___isinf(t1)) {
    t3 = __cuda___signbit(b) ? 2.3561944901923448e+0 : 7.8539816339744828e-1;
  } else {
    t0 = __cuda_fmax (t1, t3);
    t1 = __cuda_fmin (t1, t3);
    t3 = t1 / t0;
    t3 = __internal_atan_kernel(t3);

    if (__cuda_fabs(a) > __cuda_fabs(b)) t3 = 1.5707963267948966e+0 - t3;
    if (b < 0.0) t3 = 3.1415926535897931e+0 - t3;
  }
  t3 = __cuda_copysign(t3, a);
  return t3;
}

static double __cuda_atan(double a)
{
  double t0, t1;

  t0 = __cuda_fabs(a);
  t1 = t0;
  if (t0 > 1.0) {
    t1 = 1.0 / t1;
  }

  t1 = __internal_atan_kernel(t1);

  if (t0 > 1.0) {
    t1 = 1.5707963267948966e+0 - t1;
  }
  return __cuda_copysign (t1, a);
}


static double __internal_asin_kernel(double a, double b)
{
  double r;
  r = 6.259798167646803E-002;
  r = __fma_rn (r, b, -7.620591484676952E-002);
  r = __fma_rn (r, b, 6.686894879337643E-002);
  r = __fma_rn (r, b, -1.787828218369301E-002);
  r = __fma_rn (r, b, 1.745227928732326E-002);
  r = __fma_rn (r, b, 1.000422754245580E-002);
  r = __fma_rn (r, b, 1.418108777515123E-002);
  r = __fma_rn (r, b, 1.733194598980628E-002);
  r = __fma_rn (r, b, 2.237350511593569E-002);
  r = __fma_rn (r, b, 3.038188875134962E-002);
  r = __fma_rn (r, b, 4.464285849810986E-002);
  r = __fma_rn (r, b, 7.499999998342270E-002);
  r = __fma_rn (r, b, 1.666666666667375E-001);
  r = r * b;
  return r;
}

static double __cuda_asin(double a)
{
  double t0, t1;
  t0 = __cuda_fabs(a);
  if (t0 > 1.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  if (t0 > 0.575) {
    t1 = __fma_rn (-0.5, t0, 0.5);
    t0 = __cuda_sqrt (t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = -2.0 * t0;
    t1 = __fma_rn (t0, t1, 6.1232339957367660e-17);
    t0 = t0 + 7.8539816339744828e-1;
    t1 = t0 + t1;
    t1 = t1 + 7.8539816339744828e-1;
  } else {
    t1 = t0 * t0;
    t1 = __internal_asin_kernel (t0, t1);
    t1 = __fma_rn (t1, t0, t0);
  }
  return __cuda_copysign(t1, a);
}

static double __cuda_acos(double a)
{
  double t0, t1;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  t0 = __cuda_fabs (a);
  if (t0 > 0.575) {
    t1 = __fma_rn (-0.5, t0, 0.5);
    t0 = __cuda_sqrt(t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    t0 = 2.0 * t0;
    if (__cuda___signbit(a)) {
      t0 = __fma_rn (1.0, t0, -1.2246467991473532e-16);
      t0 = 3.1415926535897931e+0 - t0;
    }
  } else {
    t1 = t0 * t0;
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    if (__cuda___signbit(a)) {
      t0 = __fma_rn (1.0, t0, +6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 + t0;
    } else {
      t0 = __fma_rn (1.0, t0, -6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 - t0;
    }
  }
  return t0;
}

static double __cuda_acosh(double a)
{
  double t;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  t = a - 1.0;
  if (__cuda_fabs(t) > 4503599627370496.0) {

    return 6.9314718055994529e-1 + __cuda_log(a);
  } else {
    t = t + __cuda_sqrt(__fma_rn(a, t, t));
    return __cuda_log1p(t);
  }
}

static double __cuda_asinh(double a)
{
# 1136 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx3.h" 3
  double fa, t;
  fa = __cuda_fabs(a);
  if (fa > 1.0e153) {
    t = 6.9314718055994529e-1 + __cuda_log(fa);
  } else {
    t = fa * fa;
    t = __cuda_log1p (fa + t / (1.0 + __cuda_sqrt(1.0 + t)));
  }

  return __cuda_copysign(t, a);
}

static double __cuda_atanh(double a)
{
  double fa, t;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  fa = __cuda_fabs(a);
  t = (2.0 * fa) / (1.0 - fa);
  t = 0.5 * __cuda_log1p(t);

  if (__cuda___isnan(t)) {
    return t;
  }

  if (__cuda___signbit(a)) {
    t = -t;
  }
  return t;
}

static double __cuda_hypot(double a, double b)
{
  double v, w, t;
  if (__cuda___isinf(a) || __cuda___isinf(b)) {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  v = __cuda_fmax(a, b);
  w = __cuda_fmin(a, b);
  t = w / v;
  t = __fma_rn (t, t, 1.0);
  t = v * __cuda_sqrt(t);
  if (v == 0.0) {
    t = v + w;
  }
  return t;
}

static double __cuda_cbrt(double a)
{
  float s;
  double t, r;
  int ilo, ihi, expo, nexpo, denorm;
  if ((a == 0.0) || !(__cuda___finite(a))) {
    return a + a;
  }
  t = __cuda_fabs(a);
  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  denorm = 0;
  if (expo == 0) {

    t = t * 18014398509481984.0;
    denorm = 18;
    ilo = __double2loint(t);
    ihi = __double2hiint(t);
    expo = ((int)((unsigned int)ihi >> 20) & 0x7ff);
  }

  nexpo = __float2int_rn(0.333333333f * (float)(expo - 1022));
  ihi -= (3 * nexpo) << 20;
  r = __hiloint2double(ihi, ilo);

  s = (float)r;
  t = __cuda_exp2f(0.333333333f * __log2f(s));

  t = t - (t - (r / (t * t))) * 3.3333333333333333e-1;
  t = t - (t - (r / (t * t))) * 3.3333333333333333e-1;

  ilo = __double2loint(t);
  ihi = __double2hiint(t);
  ihi += (nexpo - denorm) << 20;
  t = __hiloint2double(ihi, ilo);
  if (__cuda___signbit(a)) {
     t = -t;
  }
  return t;
}

static double __internal_accurate_pow(double a, double b)
{
  double2 loga;
  double2 prod;
  double t_hi, t_lo;
  double tmp;



  double e;



  loga = __internal_log_ext_prec(a);


  if (__cuda_fabs(b) > 1e304) b *= 1.220703125e-4;

  t_hi = loga.y * b;
  t_lo = __fma_rn (loga.y, b, -t_hi);
  t_lo = __fma_rn (loga.x, b, t_lo);
  prod.y = e = t_hi + t_lo;
  prod.x = (t_hi - e) + t_lo;


  tmp = __cuda_exp(prod.y);

  if (!__cuda___isinf(tmp)) {



    tmp = __fma_rn (tmp, prod.x, tmp);
  }
  return tmp;
}

static double __cuda_pow(double a, double b)
{
  int bIsOddInteger;
  double t;
  if (a == 1.0 || b == 0.0) {
    return 1.0;
  }
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }
  if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
    return __cuda___signbit(b) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  }
  if (__cuda___isinf(b)) {
    if (a == -1.0) {
      return 1.0;
    }
    t = __cuda_fabs(a) > 1.0 ? __longlong_as_double(0x7ff0000000000000ULL) : 0.0;
    if (b < 0.0) {
      t = 1.0 / t;
    }
    return t;
  }
  bIsOddInteger = (b - (2.0 * __cuda_floor(0.5 * b))) == 1.0;
  if (a == 0.0) {
    t = bIsOddInteger ? a : 0.0;
    if (b < 0.0) {
      t = 1.0 / t;
    }
    return t;
  }
  if (a == -__longlong_as_double(0x7ff0000000000000ULL)) {
    t = (b < 0.0) ? -1.0/a : -a;
    if (bIsOddInteger) {
      t = __longlong_as_double(__double_as_longlong(t)^0x8000000000000000ULL);
    }
    return t;
  }
  if ((a < 0.0) && (b != __cuda_trunc(b))) {
    return __longlong_as_double(0xfff8000000000000ULL);
  }
  t = __cuda_fabs(a);
  t = __internal_accurate_pow(t, b);
  if ((a < 0.0) && bIsOddInteger) {
    t = __longlong_as_double(__double_as_longlong(t) ^ 0x8000000000000000ULL);
  }
  return t;
}

static double __cuda_erf(double a)
{
  double t, r, q;

  if (__cuda___isnan(a)) {
    return a + a;
  }

  t = __cuda_fabs(a);
  if (t >= 1.0) {
    r = -1.28836351230756500E-019;
    r = __fma_rn (r, t, 1.30597472161093370E-017);
    r = __fma_rn (r, t, -6.33924401259620500E-016);
    r = __fma_rn (r, t, 1.96231865908940140E-014);
    r = __fma_rn (r, t, -4.35272243559990750E-013);
    r = __fma_rn (r, t, 7.37083927929352150E-012);
    r = __fma_rn (r, t, -9.91402142550461630E-011);
    r = __fma_rn (r, t, 1.08817017167760820E-009);
    r = __fma_rn (r, t, -9.93918713097634620E-009);
    r = __fma_rn (r, t, 7.66739923255145500E-008);
    r = __fma_rn (r, t, -5.05440278302806720E-007);
    r = __fma_rn (r, t, 2.87474157099000620E-006);
    r = __fma_rn (r, t, -1.42246725399722510E-005);
    r = __fma_rn (r, t, 6.16994555079419460E-005);
    r = __fma_rn (r, t, -2.36305221938908790E-004);
    r = __fma_rn (r, t, 8.05032844055371070E-004);
    r = __fma_rn (r, t, -2.45833366629108140E-003);
    r = __fma_rn (r, t, 6.78340988296706120E-003);
    r = __fma_rn (r, t, -1.70509103597554640E-002);
    r = __fma_rn (r, t, 3.93322852515666300E-002);
    r = __fma_rn (r, t, -8.37271292613764040E-002);
    r = __fma_rn (r, t, 1.64870423707623280E-001);
    r = __fma_rn (r, t, -2.99729521787681470E-001);
    r = __fma_rn (r, t, 4.99394435612628580E-001);
    r = __fma_rn (r, t, -7.52014596480123030E-001);
    r = __fma_rn (r, t, 9.99933138314926250E-001);
    r = __fma_rn (r, t, -1.12836725321102670E+000);
    r = __fma_rn (r, t, 9.99998988715182450E-001);
    q = __internal_exp_kernel(-t * t, 0);
    r = __fma_rn (r, -q, 1.0);
    if (t >= 6.5) {
      r = 1.0;
    }
    a = __cuda_copysign (r, a);
  } else {
    q = t * t;
    r = -7.77946848895991420E-010;
    r = __fma_rn (r, q, 1.37109803980285950E-008);
    r = __fma_rn (r, q, -1.62063137584932240E-007);
    r = __fma_rn (r, q, 1.64471315712790040E-006);
    r = __fma_rn (r, q, -1.49247123020098620E-005);
    r = __fma_rn (r, q, 1.20552935769006260E-004);
    r = __fma_rn (r, q, -8.54832592931448980E-004);
    r = __fma_rn (r, q, 5.22397760611847340E-003);
    r = __fma_rn (r, q, -2.68661706431114690E-002);
    r = __fma_rn (r, q, 1.12837916709441850E-001);
    r = __fma_rn (r, q, -3.76126389031835210E-001);
    r = __fma_rn (r, q, 1.12837916709551260E+000);
    a = r * a;
  }
  return a;
}

static double __cuda_erfc(double a)
{
  double p, q, h, l;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  if (a <= 0.55) {
    return 1.0 - __cuda_erf(a);
  }
  if (a > 27.3) {
    return 0.0;
  }
  if (a <= 5.0) {
    p = 5.64189549785304440E-001;
    p = __fma_rn (p, a, 8.17405083437083490E+000);
    p = __fma_rn (p, a, 5.68958722557864720E+001);
    p = __fma_rn (p, a, 2.42568747802647010E+002);
    p = __fma_rn (p, a, 6.80381374390412930E+002);
    p = __fma_rn (p, a, 1.25873132236024590E+003);
    p = __fma_rn (p, a, 1.43925353963809330E+003);
    p = __fma_rn (p, a, 8.15949420587659230E+002);
    q = a+ 1.44881247113239940E+001;
    q = __fma_rn (q, a, 1.01345387970210510E+002);
    q = __fma_rn (q, a, 4.37184684964009650E+002);
    q = __fma_rn (q, a, 1.25588209225251330E+003);
    q = __fma_rn (q, a, 2.43864015012647630E+003);
    q = __fma_rn (q, a, 3.10570469008816280E+003);
    q = __fma_rn (q, a, 2.35995386578953550E+003);
    q = __fma_rn (q, a, 8.15949420692539320E+002);
  } else {
    p = 5.64189583545675280E-001;
    p = __fma_rn (p, a, 2.04728556066513970E+000);
    p = __fma_rn (p, a, 6.75128409662943610E+000);
    p = __fma_rn (p, a, 1.10459345071747900E+001);
    p = __fma_rn (p, a, 1.22570382896313600E+001);
    p = __fma_rn (p, a, 6.01884641114116460E+000);
    q = a+ 3.62871917534986780E+000;
    q = __fma_rn (q, a, 1.24663395327043550E+001);
    q = __fma_rn (q, a, 2.13927672803974790E+001);
    q = __fma_rn (q, a, 2.72082423532866070E+001);
    q = __fma_rn (q, a, 1.86422906830006700E+001);
    q = __fma_rn (q, a, 6.13809834548870550E+000);
  }
  p = p / q;
  h = -a * a;
  l = __fma_rn (-a, a, -h);
  q = __internal_exp_kernel(h, 0);
  q = __fma_rn (q, l, q);
  p = p * q;
  return p;
}


static double __internal_tgamma_kernel(double a)
{
  double t;
  t = -4.42689340712524750E-010;
  t = __fma_rn (t, a, -2.02665918466589540E-007);
  t = __fma_rn (t, a, 1.13812117211195270E-006);
  t = __fma_rn (t, a, -1.25077348166307480E-006);
  t = __fma_rn (t, a, -2.01365017404087710E-005);
  t = __fma_rn (t, a, 1.28050126073544860E-004);
  t = __fma_rn (t, a, -2.15241408115274180E-004);
  t = __fma_rn (t, a, -1.16516754597046040E-003);
  t = __fma_rn (t, a, 7.21894322484663810E-003);
  t = __fma_rn (t, a, -9.62197153268626320E-003);
  t = __fma_rn (t, a, -4.21977345547223940E-002);
  t = __fma_rn (t, a, 1.66538611382503560E-001);
  t = __fma_rn (t, a, -4.20026350341054440E-002);
  t = __fma_rn (t, a, -6.55878071520257120E-001);
  t = __fma_rn (t, a, 5.77215664901532870E-001);
  t = __fma_rn (t, a, 1.00000000000000000E+000);
  return t;
}


static double __internal_stirling_poly(double a)
{
  double x = 1.0 / a;
  double z = 0.0;
  z = __fma_rn (z, x, 8.3949872067208726e-004);
  z = __fma_rn (z, x, -5.1717909082605919e-005);
  z = __fma_rn (z, x, -5.9216643735369393e-004);
  z = __fma_rn (z, x, 6.9728137583658571e-005);
  z = __fma_rn (z, x, 7.8403922172006662e-004);
  z = __fma_rn (z, x, -2.2947209362139917e-004);
  z = __fma_rn (z, x, -2.6813271604938273e-003);
  z = __fma_rn (z, x, 3.4722222222222220e-003);
  z = __fma_rn (z, x, 8.3333333333333329e-002);
  z = __fma_rn (z, x, 1.0000000000000000e+000);
  return z;
}

static double __internal_tgamma_stirling(double a)
{
  if (a < 1.7162437695630274e+002) {

    volatile double t_hi, t_lo, e;



    double2 loga, prod;
    double z = __internal_stirling_poly (a);
    double b = a - 0.5;


    loga = __internal_log_ext_prec(a);


    t_hi = loga.y * b;
    t_lo = __fma_rn (loga.y, b, -t_hi);
    t_lo = __fma_rn (loga.x, b, t_lo);
    prod.y = e = t_hi + t_lo;
    prod.x = (t_hi - e) + t_lo;


    loga.y = -a;
    loga.x = 0.0;
    prod = __internal_ddadd_xgty (prod, loga);


    a = __cuda_exp(prod.y);

    if (!__cuda___isinf(a)) {



      a = __fma_rn (a, prod.x, a);
    }
    a = __fma_rn (a, 2.5066282746310007e+0, a * (-1.8328579980459167e-16));
    return a * z;
  } else {
    return __longlong_as_double(0x7ff0000000000000ULL);
  }
}

static double __cuda_tgamma(double a)
{
  double s, xx, x = a;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  if (__cuda_fabs(x) < 15.0) {




    if (x >= 0.0) {
      s = 1.0;
      xx = x;
      while (xx > 1.5) {
        s = __fma_rn(s, xx, -s);
        xx = xx - 1.0;
      }
      if (x >= 0.5) {
        xx = xx - 1.0;
      }
      xx = __internal_tgamma_kernel (xx);
      if (x < 0.5) {
        xx = xx * x;
      }
      s = s / xx;
    } else {
      xx = x;
      s = xx;
      if (x == __cuda_floor(x)) {
        return __longlong_as_double(0xfff8000000000000ULL);
      }
      while (xx < -0.5) {
        s = __fma_rn (s, xx, s);
        xx = xx + 1.0;
      }
      xx = __internal_tgamma_kernel (xx);
      s = s * xx;
      s = 1.0 / s;
    }
    return s;
  } else {
    if (x >= 0.0) {
      return __internal_tgamma_stirling (x);
    } else {
      double t;
      int quot;
      if (x == __cuda_floor(x)) {
        return __longlong_as_double(0xfff8000000000000ULL);
      }
      if (x < -185.0) {
        int negative;
        x = __cuda_floor(x);
        negative = ((x - (2.0 * __cuda_floor(0.5 * x))) == 1.0);
        return negative ? __longlong_as_double(0x8000000000000000ULL) : 0.0;
      }

      xx = __cuda_rint (__internal_twice(x));
      quot = (int)xx;
      xx = __fma_rn (-0.5, xx, x);
      xx = xx * 3.1415926535897931e+0;
      if (quot & 1) {
        xx = __internal_cos_kerneld (xx);
      } else {
        xx = __internal_sin_kerneld (xx);
      }
      if (quot & 2) {
        xx = -xx;
      }
      x = __cuda_fabs (x);
      s = __cuda_exp (-x);
      t = x - 0.5;
      if (x > 140.0) t = __internal_half(t);
      t = __cuda_pow (x, t);
      if (x > 140.0) s = s * t;
      s = s * __internal_stirling_poly (x);
      s = s * x;
      s = s * xx;
      s = 1.0 / s;
      s = __fma_rn (s, 1.2533141373155003e+0, (-9.1642899902295834e-17) * s);
      s = s / t;
      return s;
    }
  }
}

static double __internal_lgamma_pos(double a)
{
  double sum;
  double s, t;

  if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
    return a;
  }
  if (a >= 3.0) {
    if (a >= 8.0) {



      s = 1.0 / a;
      t = s * s;
      sum = -0.1633436431e-2;
      sum = __fma_rn (sum, t, 0.83645878922e-3);
      sum = __fma_rn (sum, t, -0.5951896861197e-3);
      sum = __fma_rn (sum, t, 0.793650576493454e-3);
      sum = __fma_rn (sum, t, -0.277777777735865004e-2);
      sum = __fma_rn (sum, t, 0.833333333333331018375e-1);
      sum = __fma_rn (sum, s, 0.918938533204672);
      s = __internal_half(__cuda_log (a));
      t = a - 0.5;
      s = s * t;
      t = s - a;
      s = s + sum;
      t = t + s;
      return t;
    } else {
      a = a - 3.0;
      s = -4.02412642744125560E+003;
      s = __fma_rn (s, a, -2.97693796998962000E+005);
      s = __fma_rn (s, a, -6.38367087682528790E+006);
      s = __fma_rn (s, a, -5.57807214576539320E+007);
      s = __fma_rn (s, a, -2.24585140671479230E+008);
      s = __fma_rn (s, a, -4.70690608529125090E+008);
      s = __fma_rn (s, a, -7.62587065363263010E+008);
      s = __fma_rn (s, a, -9.71405112477113250E+008);
      t = a -1.02277248359873170E+003;
      t = __fma_rn (t, a, -1.34815350617954480E+005);
      t = __fma_rn (t, a, -4.64321188814343610E+006);
      t = __fma_rn (t, a, -6.48011106025542540E+007);
      t = __fma_rn (t, a, -4.19763847787431360E+008);
      t = __fma_rn (t, a, -1.25629926018000720E+009);
      t = __fma_rn (t, a, -1.40144133846491690E+009);
      t = s / t;
      t = t + a;
      return t;
    }
  } else if (a >= 1.5) {
    a = a - 2.0;
    t = 9.84839283076310610E-009;
    t = __fma_rn (t, a, -6.69743850483466500E-008);
    t = __fma_rn (t, a, 2.16565148880011450E-007);
    t = __fma_rn (t, a, -4.86170275781575260E-007);
    t = __fma_rn (t, a, 9.77962097401114400E-007);
    t = __fma_rn (t, a, -2.03041287574791810E-006);
    t = __fma_rn (t, a, 4.36119725805364580E-006);
    t = __fma_rn (t, a, -9.43829310866446590E-006);
    t = __fma_rn (t, a, 2.05106878496644220E-005);
    t = __fma_rn (t, a, -4.49271383742108440E-005);
    t = __fma_rn (t, a, 9.94570466342226000E-005);
    t = __fma_rn (t, a, -2.23154589559238440E-004);
    t = __fma_rn (t, a, 5.09669559149637430E-004);
    t = __fma_rn (t, a, -1.19275392649162300E-003);
    t = __fma_rn (t, a, 2.89051032936815490E-003);
    t = __fma_rn (t, a, -7.38555102806811700E-003);
    t = __fma_rn (t, a, 2.05808084278121250E-002);
    t = __fma_rn (t, a, -6.73523010532073720E-002);
    t = __fma_rn (t, a, 3.22467033424113040E-001);
    t = __fma_rn (t, a, 4.22784335098467190E-001);
    t = t * a;
    return t;
  } else if (a >= 0.7) {
    a = 1.0 - a;
    t = 1.17786911519331130E-002;
    t = __fma_rn (t, a, 3.89046747413522300E-002);
    t = __fma_rn (t, a, 5.90045711362049900E-002);
    t = __fma_rn (t, a, 6.02143305254344420E-002);
    t = __fma_rn (t, a, 5.61652708964839180E-002);
    t = __fma_rn (t, a, 5.75052755193461370E-002);
    t = __fma_rn (t, a, 6.21061973447320710E-002);
    t = __fma_rn (t, a, 6.67614724532521880E-002);
    t = __fma_rn (t, a, 7.14856037245421020E-002);
    t = __fma_rn (t, a, 7.69311251313347100E-002);
    t = __fma_rn (t, a, 8.33503129714946310E-002);
    t = __fma_rn (t, a, 9.09538288991182800E-002);
    t = __fma_rn (t, a, 1.00099591546322310E-001);
    t = __fma_rn (t, a, 1.11334278141734510E-001);
    t = __fma_rn (t, a, 1.25509666613462880E-001);
    t = __fma_rn (t, a, 1.44049896457704160E-001);
    t = __fma_rn (t, a, 1.69557177031481600E-001);
    t = __fma_rn (t, a, 2.07385551032182120E-001);
    t = __fma_rn (t, a, 2.70580808427600350E-001);
    t = __fma_rn (t, a, 4.00685634386517050E-001);
    t = __fma_rn (t, a, 8.22467033424113540E-001);
    t = __fma_rn (t, a, 5.77215664901532870E-001);
    t = t * a;
    return t;
  } else {
    t= -9.04051686831357990E-008;
    t = __fma_rn (t, a, 7.06814224969349250E-007);
    t = __fma_rn (t, a, -3.80702154637902830E-007);
    t = __fma_rn (t, a, -2.12880892189316100E-005);
    t = __fma_rn (t, a, 1.29108470307156190E-004);
    t = __fma_rn (t, a, -2.15932815215386580E-004);
    t = __fma_rn (t, a, -1.16484324388538480E-003);
    t = __fma_rn (t, a, 7.21883433044470670E-003);
    t = __fma_rn (t, a, -9.62194579514229560E-003);
    t = __fma_rn (t, a, -4.21977386992884450E-002);
    t = __fma_rn (t, a, 1.66538611813682460E-001);
    t = __fma_rn (t, a, -4.20026350606819980E-002);
    t = __fma_rn (t, a, -6.55878071519427450E-001);
    t = __fma_rn (t, a, 5.77215664901523870E-001);
    t = t * a;
    t = __fma_rn (t, a, a);
    return -__cuda_log (t);
  }
}

static double __cuda_lgamma(double a)
{
  double t;
  double i;
  long long int quot;
  if (__cuda___isnan(a)) {
    return a + a;
  }
  t = __internal_lgamma_pos(__cuda_fabs(a));
  if (a >= 0.0) return t;
  a = __cuda_fabs(a);
  i = __cuda_floor(a);
  if (a == i) return __longlong_as_double(0x7ff0000000000000ULL);
  if (a < 1e-19) return -__cuda_log(a);
  i = __cuda_rint (2.0 * a);
  quot = (long long int)i;
  i = __fma_rn (-0.5, i, a);
  i = i * 3.1415926535897931e+0;
  if (quot & 1) {
    i = __internal_cos_kerneld(i);
  } else {
    i = __internal_sin_kerneld(i);
  }
  i = __cuda_fabs(i);
  t = __cuda_log(3.1415926535897931e+0 / (i * a)) - t;
  return t;
}

static double __cuda_ldexp(double a, int b)
{
  double fa = __cuda_fabs (a);
  if ((fa == 0.0) || (fa == __longlong_as_double(0x7ff0000000000000ULL)) || (!(fa <= __longlong_as_double(0x7ff0000000000000ULL)))) {
    return a + a;
  }
  if (b == 0) {
    return a;
  }
  if (b > 2200) b = 2200;
  if (b < -2200) b = -2200;
  if (__cuda_abs (b) < 1022) {
    return a * __internal_exp2i_kernel(b);
  }
  if (__cuda_abs (b) < 2044) {
    int bhalf = b / 2;
    return a * __internal_exp2i_kernel (bhalf) *
           __internal_exp2i_kernel (b - bhalf);
  } else {
    int bquarter = b / 4;
    double t = __internal_exp2i_kernel(bquarter);
    return a * t * t * t *__internal_exp2i_kernel (b - 3 * bquarter);
  }
}

static double __cuda_scalbn(double a, int b)
{

  return __cuda_ldexp(a, b);
}

static double __cuda_scalbln(double a, long int b)
{


  if (b < -2147483648L) b = -2147483648L;
  if (b > 2147483647L) b = 2147483647L;

  return __cuda_scalbn(a, (int)b);
}

static double __cuda_frexp(double a, int *b)
{
  double fa = __cuda_fabs(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < 2.22507385850720140e-308) {
    a *= 18014398509481984.0;
    denorm = 54;
  } else {
    denorm = 0;
  }
  expo = (__double2hiint(a) >> 20) & 0x7ff;
  if ((fa == 0.0) || (expo == 0x7ff)) {
    expo = 0;
    a = a + a;
  } else {
    expo = expo - denorm - 1022;
    a = __longlong_as_double((__double_as_longlong(a) & 0x800fffffffffffffULL)|
                              0x3fe0000000000000ULL);
  }
  *b = expo;
  return a;
}

static double __cuda_modf(double a, double *b)
{
  double t;
  if (__cuda___finite(a)) {
    t = __cuda_trunc(a);
    *b = t;
    t = a - t;
    return __cuda_copysign(t, a);
  } else if (__cuda___isinf(a)) {
    t = 0.0;
    *b = a;
    return __cuda_copysign(t, a);
  } else {
    *b = a + a;
    return a + a;
  }
}

static double __cuda_fmod(double a, double b)
{
  double orig_a = a;
  double orig_b = b;
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (!((a <= __longlong_as_double(0x7ff0000000000000ULL)) && (b <= __longlong_as_double(0x7ff0000000000000ULL)))) {
      return orig_a + orig_b;
  }
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    int bhi = __double2hiint(b);
    int blo = __double2loint(b);
    int ahi = __double2hiint(a);
    double scaled_b = 0.0;
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5;
    }
    return __cuda_copysign (a, orig_a);
  } else {
    return orig_a;
  }
}

static double __cuda_remainder(double a, double b)
{
  double orig_a;
  double twoa = 0.0;
  unsigned int quot0 = 0;
  int bhi;
  int blo;
  int ahi;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    return a + b;
  }
  orig_a = a;
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    double scaled_b = 0.0;
    bhi = __double2hiint(b);
    blo = __double2loint(b);
    ahi = __double2hiint(a);
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        a -= scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5;
    }
  }

  twoa = a + a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
  }
  bhi = __double2hiint(a);
  blo = __double2loint(a);
  ahi = __double2hiint(orig_a);
  a = __hiloint2double((ahi & 0x80000000) ^ bhi, blo);
  return a;
}

static double __cuda_remquo(double a, double b, int *c)
{
  double orig_a;
  double twoa = 0.0;
  unsigned int quot = 0;
  unsigned int sign;
  int bhi;
  int blo;
  int ahi;
  if (__cuda___isnan(a) || __cuda___isnan(b)) {
    *c = quot;
    return a + b;
  }
  orig_a = a;
  sign = 0 - (__cuda___signbit(a) != __cuda___signbit(b));
  a = __cuda_fabs(a);
  b = __cuda_fabs(b);
  if (a == __longlong_as_double(0x7ff0000000000000ULL) || b == 0.0) {
    *c = quot;
    return __longlong_as_double(0xfff8000000000000ULL);
  } else if (a >= b) {
    double scaled_b = 0.0;
    bhi = __double2hiint(b);
    blo = __double2loint(b);
    ahi = __double2hiint(a);
    if (b < 2.22507385850720140e-308) {
      double t = b;
      while ((t < a) && (t < 2.22507385850720140e-308)) {
        t = t + t;
      }
      bhi = __double2hiint(t);
      blo = __double2loint(t);
      scaled_b = t;
    }
    if (a >= 2.22507385850720140e-308) {
      scaled_b = __hiloint2double ((bhi & 0x000fffff)|(ahi & 0x7ff00000), blo);
    }
    if (scaled_b > a) {
      scaled_b *= 0.5;
    }
    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5;
    }
  }

  twoa = a + a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
  }
  bhi = __double2hiint(a);
  blo = __double2loint(a);
  ahi = __double2hiint(orig_a);
  a = __hiloint2double((ahi & 0x80000000) ^ bhi, blo);
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *c = quot;
  return a;
}

static double __cuda_nextafter(double a, double b)
{
  unsigned long long int ia;
  unsigned long long int ib;
  ia = __double_as_longlong(a);
  ib = __double_as_longlong(b);
  if (__cuda___isnan(a) || __cuda___isnan(b)) return a + b;
  if (((ia | ib) << 1) == 0ULL) return b;
  if ((ia + ia) == 0ULL) {
    return __cuda_copysign (__longlong_as_double(0x0000000000000001ULL), b);
  }
  if ((a < b) && (a < 0.0)) ia--;
  if ((a < b) && (a > 0.0)) ia++;
  if ((a > b) && (a < 0.0)) ia++;
  if ((a > b) && (a > 0.0)) ia--;
  a = __longlong_as_double(ia);
  return a;
}

static double __cuda_nan(const char *s)
{
  unsigned long long i = 0;
  int c;
  int ovfl = 0;
  int invld = 0;
  if (*s == '0') {
    s++;
    if ((*s == 'x') || (*s == 'X')) {
      s++;
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x0fffffffffffffffULL) {
          ovfl = 1;
        }
        c = (((*s) >= 'A') && ((*s) <= 'F')) ? (*s + 'a' - 'A') : (*s);
        if ((c >= 'a') && (c <= 'f')) {
          c = c - 'a' + 10;
          i = i * 16 + c;
        } else if ((c >= '0') && (c <= '9')) {
          c = c - '0';
          i = i * 16 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    } else {
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x1fffffffffffffffULL) {
          ovfl = 1;
        }
        c = *s;
        if ((c >= '0') && (c <= '7')) {
          c = c - '0';
          i = i * 8 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    }
  } else {
    while (*s) {
      c = *s;
      if ((i > 1844674407370955161ULL) ||
          ((i == 1844674407370955161ULL) && (c > '5'))) {
        ovfl = 1;
      }
      if ((c >= '0') && (c <= '9')) {
        c = c - '0';
        i = i * 10 + c;
      } else {
        invld = 1;
      }
      s++;
    }
  }
  if (ovfl) {
    i = ~0ULL;
  }
  if (invld) {
    i = 0ULL;
  }
  i = (i & 0x000fffffffffffffULL) | 0x7ff8000000000000ULL;
  return __longlong_as_double(i);
}

static double __cuda_round(double a)
{
  double fa = __cuda_fabs(a);
  if (fa > 4503599627370496.0) {
    return a;
  } else {
    double u = __cuda_floor(fa + 0.5);
    if (fa < 0.5) u = 0;
    return __cuda_copysign(u, a);
  }
}

static long long int __cuda_llround(double a)
{

  if (a >= 9223372036854775807.0) return 0x7fffffffffffffffLL;
  if (a <= -9223372036854775808.0) return 0x8000000000000000LL;

  return (long long int)(__cuda_round(a));
}

static long int __cuda_lround(double a)
{

  return (long int)(__cuda_llround(a));
# 2124 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx3.h" 3
}

static double __cuda_fdim(double a, double b)
{
  double t;
  t = a - b;
  if (a <= b) {
    t = 0.0;
  }
  return t;
}

static int __cuda_ilogb(double a)
{
  unsigned long long int i;
  unsigned int ihi;
  unsigned int ilo;
  if (__cuda___isnan(a)) return -((int)((unsigned int)-1 >> 1))-1;
  if (__cuda___isinf(a)) return ((int)((unsigned int)-1 >> 1));
  if (a == 0.0) return -((int)((unsigned int)-1 >> 1))-1;
  a = __cuda_fabs(a);
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  i = ((unsigned long long int)ihi) << 32 | (unsigned long long int)ilo;
  if (a >= 2.22507385850720140e-308) {
    return ((int)((ihi >> 20) & 0x7ff)) - 1023;
  } else {
    int expo = -1022;
    while (i < 0x0010000000000000ULL) {
      expo--;
      i = i + i;
    }
    return expo;
  }
}

static double __cuda_logb(double a)
{
  unsigned long long int i;
  unsigned int ihi;
  unsigned int ilo;
  if (__cuda___isnan(a)) return a + a;
  a = __cuda_fabs(a);
  if (a == __longlong_as_double(0x7ff0000000000000ULL)) return a;
  if (a == 0.0) return -__longlong_as_double(0x7ff0000000000000ULL);
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  i = ((unsigned long long int)ihi) << 32 | (unsigned long long int)ilo;
  if (a >= 2.22507385850720140e-308) {
    return (double)((int)((ihi >> 20) & 0x7ff)) - 1023;
  } else {
    int expo = -1022;
    while (i < 0x0010000000000000ULL) {
      expo--;
      i = i + i;
    }
    return (double)expo;
  }
}

static double __cuda_fma(double a, double b, double c)
{
  return __fma_rn(a, b, c);
}
# 3862 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 2 3
# 94 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h" 2
# 216 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 2
struct __T20;
struct __T21;
struct __T22;
struct __T23;
struct __T20 {__TOptionValue *__par0;float *__par1;int __par2;int __dummy_field;};
struct __T21 {float *__par0;int __par1;int __dummy_field;};
struct __T22 {__TOptionValue *__par0;int __par1;int __dummy_field;};
struct __T23 {float *__par0;float *__par1;unsigned __par2;int __dummy_field;};
# 26 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_0000150a_00000000_14_MonteCarlo_SM13_cpp1_ii_c14de7b3(void) __attribute__((__constructor__));
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *__par0, float *__par1, int __par2){auto struct __T20 *__T24;
char __[256]; *(char**)&__T24 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2 - (size_t)__T24) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi); (void)cudaLaunch(((char *)__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi)); };}
static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi(float *__par0, int __par1){auto struct __T21 *__T25;
char __[256]; *(char**)&__T25 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1 - (size_t)__T25) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z27MonteCarloOneBlockPerOptionPfi); (void)cudaLaunch(((char *)__device_stub__Z27MonteCarloOneBlockPerOptionPfi)); };}
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei(__TOptionValue *__par0, int __par1){auto struct __T22 *__T26;
char __[256]; *(char**)&__T26 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T26->__par0 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T26->__par1 - (size_t)__T26) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z16MonteCarloReduceP14__TOptionValuei); (void)cudaLaunch(((char *)__device_stub__Z16MonteCarloReduceP14__TOptionValuei)); };}
static void __device_stub__Z16inverseCNDKernelPfS_j(float *__par0, float *__par1, unsigned __par2){auto struct __T23 *__T233;
char __[256]; *(char**)&__T233 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T233->__par0 - (size_t)__T233) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T233->__par1 - (size_t)__T233) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T233->__par2 - (size_t)__T233) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z16inverseCNDKernelPfS_j); (void)cudaLaunch(((char *)__device_stub__Z16inverseCNDKernelPfS_j)); };}
# 47 "/tmp/tmpxft_0000150a_00000000-4_MonteCarlo_SM13.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_0000150a_00000000_14_MonteCarlo_SM13_cpp1_ii_c14de7b3(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z16inverseCNDKernelPfS_j, (char*)"_Z16inverseCNDKernelPfS_j", "_Z16inverseCNDKernelPfS_j", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z16MonteCarloReduceP14__TOptionValuei, (char*)"_Z16MonteCarloReduceP14__TOptionValuei", "_Z16MonteCarloReduceP14__TOptionValuei", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z27MonteCarloOneBlockPerOptionPfi, (char*)"_Z27MonteCarloOneBlockPerOptionPfi", "_Z27MonteCarloOneBlockPerOptionPfi", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi, (char*)"_Z16MonteCarloKernelP14__TOptionValuePfi", "_Z16MonteCarloKernelP14__TOptionValuePfi", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_d_OptionData, (char*)"d_OptionData", "d_OptionData", 0, 65536, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_d_CallValue, (char*)"d_CallValue", "d_CallValue", 0, 32768, 0, 0);}

}
# 60 "MonteCarlo_SM13.cu" 2

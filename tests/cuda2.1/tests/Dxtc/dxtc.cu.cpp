# 1 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.cpp"
# 1 "dxtc.cu"
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
# 49 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 50 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 85 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float lerp(float a, float b, float t)
# 86 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 87 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return a + t * (b - a);
# 88 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 91 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float clamp(float f, float a, float b)
# 92 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 93 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 94 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 100 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator-(int2 &a)
# 101 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 102 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 103 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 106 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 107 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 108 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(a.x + b.x, a.y + b.y);
# 109 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 110 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 111 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 112 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y;
# 113 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 116 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 117 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 118 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(a.x - b.x, a.y - b.y);
# 119 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 120 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 121 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 122 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y;
# 123 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 126 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 127 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 128 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(a.x * b.x, a.y * b.y);
# 129 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 130 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator*(int2 a, int s)
# 131 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 132 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(a.x * s, a.y * s);
# 133 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 134 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int2 operator*(int s, int2 a)
# 135 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 136 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int2(a.x * s, a.y * s);
# 137 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 138 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(int2 &a, int s)
# 139 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 140 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 141 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 147 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 make_float2(float s)
# 148 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 149 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(s, s);
# 150 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 151 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 make_float2(int2 a)
# 152 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 153 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 154 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 157 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator-(float2 &a)
# 158 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 159 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 160 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 163 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 164 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 165 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x + b.x, a.y + b.y);
# 166 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 167 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 168 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 169 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y;
# 170 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 173 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 174 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 175 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x - b.x, a.y - b.y);
# 176 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 177 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 178 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 179 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y;
# 180 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 183 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 184 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 185 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x * b.x, a.y * b.y);
# 186 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 187 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator*(float2 a, float s)
# 188 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 189 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x * s, a.y * s);
# 190 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 191 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator*(float s, float2 a)
# 192 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 193 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x * s, a.y * s);
# 194 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 195 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(float2 &a, float s)
# 196 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 197 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 198 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 201 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 202 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 203 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(a.x / b.x, a.y / b.y);
# 204 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 205 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator/(float2 a, float s)
# 206 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 207 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 208 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 209 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 210 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 operator/(float s, float2 a)
# 211 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 212 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 213 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 214 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 215 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator/=(float2 &a, float s)
# 216 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 217 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 218 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a *= inv);
# 219 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 222 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 223 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 224 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a + (t * (b - a)));
# 225 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 228 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 229 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 230 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 231 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 233 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 234 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 235 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 236 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 239 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float dot(float2 a, float2 b)
# 240 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 241 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return a.x * b.x + a.y * b.y;
# 242 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 245 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float length(float2 v)
# 246 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 247 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return sqrtf(dot(v, v));
# 248 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 251 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 normalize(float2 v)
# 252 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 253 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 254 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (v * invLen);
# 255 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 258 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 floor(const float2 v)
# 259 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 260 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(floor(v.x), floor(v.y));
# 261 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 264 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 reflect(float2 i, float2 n)
# 265 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 266 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (i - (((2.0F) * n) * dot(n, i)));
# 267 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 270 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float2 fabs(float2 v)
# 271 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 272 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 273 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 279 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 make_float3(float s)
# 280 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 281 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(s, s, s);
# 282 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 283 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 make_float3(float2 a)
# 284 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 285 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 286 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 287 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 288 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 289 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x, a.y, s);
# 290 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 291 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 make_float3(float4 a)
# 292 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 293 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 294 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 295 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 make_float3(int3 a)
# 296 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 297 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 298 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 301 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator-(float3 &a)
# 302 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 303 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 304 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 307 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
static inline float3 fminf(float3 a, float3 b)
# 308 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 309 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 310 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 313 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
static inline float3 fmaxf(float3 a, float3 b)
# 314 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 315 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 316 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 319 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 320 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 321 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
# 322 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 323 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 324 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 325 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x + b, a.y + b, a.z + b);
# 326 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 327 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 328 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 329 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 330 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 333 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 334 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 335 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
# 336 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 337 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 338 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 339 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x - b, a.y - b, a.z - b);
# 340 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 341 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 342 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 343 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 344 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 347 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 348 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 349 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
# 350 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 351 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator*(float3 a, float s)
# 352 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 353 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x * s, a.y * s, a.z * s);
# 354 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 355 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator*(float s, float3 a)
# 356 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 357 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x * s, a.y * s, a.z * s);
# 358 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 359 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(float3 &a, float s)
# 360 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 361 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 362 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 365 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 366 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 367 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.x / b.x, a.y / b.y, a.z / b.z);
# 368 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 369 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator/(float3 a, float s)
# 370 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 371 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 372 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 373 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 374 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 operator/(float s, float3 a)
# 375 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 376 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 377 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 378 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 379 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator/=(float3 &a, float s)
# 380 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 381 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 382 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a *= inv);
# 383 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 386 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 387 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 388 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a + (t * (b - a)));
# 389 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 392 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 393 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 394 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 395 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 397 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 398 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 399 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 400 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 403 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float dot(float3 a, float3 b)
# 404 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 405 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a.x * b.x + a.y * b.y) + a.z * b.z;
# 406 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 409 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 410 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 411 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
# 412 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 415 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float length(float3 v)
# 416 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 417 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return sqrtf(dot(v, v));
# 418 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 421 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 normalize(float3 v)
# 422 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 423 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 424 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (v * invLen);
# 425 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 428 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 floor(const float3 v)
# 429 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 430 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(floor(v.x), floor(v.y), floor(v.z));
# 431 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 434 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 435 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 436 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (i - (((2.0F) * n) * dot(n, i)));
# 437 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 440 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float3 fabs(float3 v)
# 441 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 442 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 443 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 449 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 make_float4(float s)
# 450 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 451 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(s, s, s, s);
# 452 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 453 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 make_float4(float3 a)
# 454 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 455 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 456 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 457 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 458 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 459 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 460 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 461 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 make_float4(int4 a)
# 462 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 463 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 464 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 467 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator-(float4 &a)
# 468 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 469 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 470 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 473 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
static inline float4 fminf(float4 a, float4 b)
# 474 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 475 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 476 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 479 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
static inline float4 fmaxf(float4 a, float4 b)
# 480 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 481 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 482 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 485 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 486 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 487 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
# 488 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 489 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 490 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 491 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z; (a.w) += b.w;
# 492 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 495 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 496 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 497 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
# 498 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 499 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 500 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 501 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z; (a.w) -= b.w;
# 502 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 505 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator*(float4 a, float s)
# 506 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 507 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
# 508 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 509 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator*(float s, float4 a)
# 510 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 511 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
# 512 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 513 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(float4 &a, float s)
# 514 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 515 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
# 516 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 519 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 520 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 521 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
# 522 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 523 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator/(float4 a, float s)
# 524 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 525 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 526 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 527 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 528 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 operator/(float s, float4 a)
# 529 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 530 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 531 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a * inv);
# 532 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 533 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator/=(float4 &a, float s)
# 534 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 535 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float inv = ((1.0F) / s);
# 536 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a *= inv);
# 537 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 540 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 541 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 542 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (a + (t * (b - a)));
# 543 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 546 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 547 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 548 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 549 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 551 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 552 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 553 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 554 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 557 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float dot(float4 a, float4 b)
# 558 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 559 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return ((a.x * b.x + a.y * b.y) + a.z * b.z) + a.w * b.w;
# 560 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 563 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float length(float4 r)
# 564 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 565 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return sqrtf(dot(r, r));
# 566 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 569 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 normalize(float4 v)
# 570 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 571 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 572 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return (v * invLen);
# 573 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 576 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 floor(const float4 v)
# 577 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 578 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
# 579 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 582 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline float4 fabs(float4 v)
# 583 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 584 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 585 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 591 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 make_int3(int s)
# 592 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 593 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(s, s, s);
# 594 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 595 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 make_int3(float3 a)
# 596 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 597 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 598 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 601 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator-(int3 &a)
# 602 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 603 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 604 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 607 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 608 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 609 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 610 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 613 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 614 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 615 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 616 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 619 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 620 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 621 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x + b.x, a.y + b.y, a.z + b.z);
# 622 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 623 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 624 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 625 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 626 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 629 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 630 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 631 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x - b.x, a.y - b.y, a.z - b.z);
# 632 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 634 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 635 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 636 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 637 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 640 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 641 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 642 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x * b.x, a.y * b.y, a.z * b.z);
# 643 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 644 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator*(int3 a, int s)
# 645 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 646 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x * s, a.y * s, a.z * s);
# 647 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 648 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator*(int s, int3 a)
# 649 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 650 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x * s, a.y * s, a.z * s);
# 651 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 652 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(int3 &a, int s)
# 653 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 654 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 655 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 658 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator/(int3 a, int3 b)
# 659 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 660 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x / b.x, a.y / b.y, a.z / b.z);
# 661 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 662 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator/(int3 a, int s)
# 663 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 664 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x / s, a.y / s, a.z / s);
# 665 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 666 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 operator/(int s, int3 a)
# 667 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 668 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(a.x / s, a.y / s, a.z / s);
# 669 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 670 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator/=(int3 &a, int s)
# 671 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 672 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 673 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 676 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int clamp(int f, int a, int b)
# 677 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 678 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return max(a, min(f, b));
# 679 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 681 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 682 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 683 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 684 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 686 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 687 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 688 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 689 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 696 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 make_uint3(uint s)
# 697 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 698 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(s, s, s);
# 699 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 700 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 make_uint3(float3 a)
# 701 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 702 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3((unsigned)(a.x), (unsigned)(a.y), (unsigned)(a.z));
# 703 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 706 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 707 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 708 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 709 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 712 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 713 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 714 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 715 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 718 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 719 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 720 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x + b.x, a.y + b.y, a.z + b.z);
# 721 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 722 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 723 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 724 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 725 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 728 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 729 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 730 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x - b.x, a.y - b.y, a.z - b.z);
# 731 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 733 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 734 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 735 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 736 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 739 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 740 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 741 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x * b.x, a.y * b.y, a.z * b.z);
# 742 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 743 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator*(uint3 a, uint s)
# 744 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 745 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x * s, a.y * s, a.z * s);
# 746 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 747 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator*(uint s, uint3 a)
# 748 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 749 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x * s, a.y * s, a.z * s);
# 750 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 751 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator*=(uint3 &a, uint s)
# 752 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 753 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 754 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 757 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator/(uint3 a, uint3 b)
# 758 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 759 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x / b.x, a.y / b.y, a.z / b.z);
# 760 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 761 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator/(uint3 a, uint s)
# 762 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 763 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x / s, a.y / s, a.z / s);
# 764 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 765 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 operator/(uint s, uint3 a)
# 766 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 767 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(a.x / s, a.y / s, a.z / s);
# 768 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 769 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline void operator/=(uint3 &a, uint s)
# 770 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 771 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 772 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 775 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 776 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 777 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return max(a, min(f, b));
# 778 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 780 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 781 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 782 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 783 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 785 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 786 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
{
# 787 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 788 "/usr/local/NVIDIA_CUDA_SDK/common/inc/cutil_math.h"
}
# 143 "CudaMath.h"
inline float3 firstEigenVector(float matrix[6])
# 144 "CudaMath.h"
{
# 147 "CudaMath.h"
auto float3 v = make_float3((1.0F), (1.0F), (1.0F));
# 148 "CudaMath.h"
for (int i = 0; i < 8; i++) {
# 149 "CudaMath.h"
auto float x = ((v.x * matrix[0] + v.y * matrix[1]) + v.z * matrix[2]);
# 150 "CudaMath.h"
auto float y = ((v.x * matrix[1] + v.y * matrix[3]) + v.z * matrix[4]);
# 151 "CudaMath.h"
auto float z = ((v.x * matrix[2] + v.y * matrix[4]) + v.z * matrix[5]);
# 152 "CudaMath.h"
auto float m = max(max(x, y), z);
# 153 "CudaMath.h"
auto float iv = ((1.0F) / m);
# 157 "CudaMath.h"
v = make_float3(x * iv, y * iv, z * iv);
# 158 "CudaMath.h"
}
# 160 "CudaMath.h"
return v;
# 161 "CudaMath.h"
}
# 45 "dds.h"
extern "C" { typedef unsigned uint; }
# 46 "dds.h"
extern "C" { typedef unsigned short ushort; }
# 48 "dds.h"
struct DDSPixelFormat {
# 49 "dds.h"
uint size;
# 50 "dds.h"
uint flags;
# 51 "dds.h"
uint fourcc;
# 52 "dds.h"
uint bitcount;
# 53 "dds.h"
uint rmask;
# 54 "dds.h"
uint gmask;
# 55 "dds.h"
uint bmask;
# 56 "dds.h"
uint amask;
# 57 "dds.h"
};
# 59 "dds.h"
struct DDSCaps {
# 60 "dds.h"
uint caps1;
# 61 "dds.h"
uint caps2;
# 62 "dds.h"
uint caps3;
# 63 "dds.h"
uint caps4;
# 64 "dds.h"
};
# 67 "dds.h"
struct DDSHeader {
# 68 "dds.h"
uint fourcc;
# 69 "dds.h"
uint size;
# 70 "dds.h"
uint flags;
# 71 "dds.h"
uint height;
# 72 "dds.h"
uint width;
# 73 "dds.h"
uint pitch;
# 74 "dds.h"
uint depth;
# 75 "dds.h"
uint mipmapcount;
# 76 "dds.h"
uint reserved[11];
# 77 "dds.h"
DDSPixelFormat pf;
# 78 "dds.h"
DDSCaps caps;
# 79 "dds.h"
uint notused;
# 80 "dds.h"
};
# 82 "dds.h"
static const uint FOURCC_DDS = (((((unsigned)'D') | (((unsigned)'D') << 8)) | (((unsigned)'S') << 16)) | (((unsigned)' ') << 24));
# 83 "dds.h"
static const uint FOURCC_DXT1 = (((((unsigned)'D') | (((unsigned)'X') << 8)) | (((unsigned)'T') << 16)) | (((unsigned)'1') << 24));
# 84 "dds.h"
static const uint DDSD_WIDTH = (4U);
# 85 "dds.h"
static const uint DDSD_HEIGHT = (2U);
# 86 "dds.h"
static const uint DDSD_CAPS = (1U);
# 87 "dds.h"
static const uint DDSD_PIXELFORMAT = (4096U);
# 88 "dds.h"
static const uint DDSCAPS_TEXTURE = (4096U);
# 89 "dds.h"
static const uint DDPF_FOURCC = (4U);
# 90 "dds.h"
static const uint DDSD_LINEARSIZE = (524288U);
# 42 "permutations.h"
static void computePermutations(uint permutations[1024])
# 43 "permutations.h"
{
# 44 "permutations.h"
auto int indices[16];
# 45 "permutations.h"
auto int num = 0;
# 50 "permutations.h"
for (int m = 0; m < 16; ++m)
# 51 "permutations.h"
{
# 52 "permutations.h"
((indices)[m]) = 0;
# 53 "permutations.h"
}
# 54 "permutations.h"
auto const int imax = 15;
# 55 "permutations.h"
for (int i = imax; i >= 0; --i)
# 56 "permutations.h"
{
# 58 "permutations.h"
for (int m = i; m < 16; ++m)
# 59 "permutations.h"
{
# 60 "permutations.h"
((indices)[m]) = 2;
# 61 "permutations.h"
}
# 62 "permutations.h"
auto const int jmax = ((i == 0) ? 15 : 16);
# 63 "permutations.h"
for (int j = jmax; j >= i; --j)
# 64 "permutations.h"
{
# 66 "permutations.h"
if (j < 16)
# 67 "permutations.h"
{
# 68 "permutations.h"
((indices)[j]) = 1;
# 69 "permutations.h"
}
# 71 "permutations.h"
auto uint permutation = (0);
# 73 "permutations.h"
for (int p = 0; p < 16; p++) {
# 74 "permutations.h"
permutation |= ((indices)[p]) << (p * 2);
# 76 "permutations.h"
}
# 78 "permutations.h"
(permutations[num]) = permutation;
# 80 "permutations.h"
num++;
# 81 "permutations.h"
}
# 82 "permutations.h"
}
# 83 "permutations.h"
__cutilCondition(num == 151, (char *)("permutations.h"), 83);
# 85 "permutations.h"
for (int i = 0; i < 9; i++)
# 86 "permutations.h"
{
# 87 "permutations.h"
(permutations[num]) = (697685);
# 88 "permutations.h"
num++;
# 89 "permutations.h"
}
# 90 "permutations.h"
__cutilCondition(num == 160, (char *)("permutations.h"), 90);
# 95 "permutations.h"
for (int m = 0; m < 16; ++m)
# 96 "permutations.h"
{
# 97 "permutations.h"
((indices)[m]) = 0;
# 98 "permutations.h"
}
# 100 "permutations.h"
for (int i = imax; i >= 0; --i)
# 101 "permutations.h"
{
# 103 "permutations.h"
for (int m = i; m < 16; ++m)
# 104 "permutations.h"
{
# 105 "permutations.h"
((indices)[m]) = 2;
# 106 "permutations.h"
}
# 107 "permutations.h"
auto const int jmax = ((i == 0) ? 15 : 16);
# 108 "permutations.h"
for (int j = jmax; j >= i; --j)
# 109 "permutations.h"
{
# 111 "permutations.h"
for (int m = j; m < 16; ++m)
# 112 "permutations.h"
{
# 113 "permutations.h"
((indices)[m]) = 3;
# 114 "permutations.h"
}
# 116 "permutations.h"
auto int kmax = ((j == 0) ? 15 : 16);
# 117 "permutations.h"
for (int k = kmax; k >= j; --k)
# 118 "permutations.h"
{
# 120 "permutations.h"
if (k < 16)
# 121 "permutations.h"
{
# 122 "permutations.h"
((indices)[k]) = 1;
# 123 "permutations.h"
}
# 125 "permutations.h"
auto uint permutation = (0);
# 127 "permutations.h"
auto bool hasThree = false;
# 128 "permutations.h"
for (int p = 0; p < 16; p++) {
# 129 "permutations.h"
permutation |= ((indices)[p]) << (p * 2);
# 132 "permutations.h"
if (((indices)[p]) == 3) { hasThree = true; }
# 133 "permutations.h"
}
# 135 "permutations.h"
if (hasThree) {
# 136 "permutations.h"
(permutations[num]) = permutation;
# 137 "permutations.h"
num++;
# 138 "permutations.h"
}
# 139 "permutations.h"
}
# 140 "permutations.h"
}
# 141 "permutations.h"
}
# 142 "permutations.h"
__cutilCondition(num == 975, (char *)("permutations.h"), 142);
# 147 "permutations.h"
for (int i = 0; i < 49; i++)
# 148 "permutations.h"
{
# 149 "permutations.h"
(permutations[num]) = (11206485);
# 150 "permutations.h"
num++;
# 151 "permutations.h"
}
# 153 "permutations.h"
__cutilCondition(num == 1024, (char *)("permutations.h"), 153);
# 154 "permutations.h"
}
# 79 "dxtc.cu"
static float3 __shadow_kColorMetric;
# 200 "dxtc.cu"
static float __shadow_alphaTable4[4];
# 201 "dxtc.cu"
static float __shadow_alphaTable3[4];
# 202 "dxtc.cu"
static int __shadow_prods4[4];
# 203 "dxtc.cu"
static int __shadow_prods3[4];

# 1 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.stub.h" 1

extern "C" {


extern void __device_stub__Z8compressPKjS0_P5uint2(const uint *, const uint *, uint2 *);


}
# 206 "dxtc.cu" 2
# 544 "dxtc.cu"
union Color32 {
# 545 "dxtc.cu"
struct {
# 546 "dxtc.cu"
unsigned char b; unsigned char g; unsigned char r; unsigned char a;
# 547 "dxtc.cu"
};
# 548 "dxtc.cu"
unsigned u;
# 549 "dxtc.cu"
};
# 551 "dxtc.cu"
union Color16 {
# 552 "dxtc.cu"
struct {
# 553 "dxtc.cu"
unsigned short b:5;
# 554 "dxtc.cu"
unsigned short g:6;
# 555 "dxtc.cu"
unsigned short r:5;
# 556 "dxtc.cu"
};
# 557 "dxtc.cu"
unsigned short u;
# 558 "dxtc.cu"
};
# 560 "dxtc.cu"
struct BlockDXT1 {
# 562 "dxtc.cu"
Color16 col0;
# 563 "dxtc.cu"
Color16 col1;
# 564 "dxtc.cu"
union {
# 565 "dxtc.cu"
unsigned char row[4];
# 566 "dxtc.cu"
unsigned indices;
# 567 "dxtc.cu"
};
# 569 "dxtc.cu"
void decompress(Color32 [16]) const;
# 570 "dxtc.cu"
};
# 572 "dxtc.cu"
void BlockDXT1::decompress(Color32 *colors) const
# 573 "dxtc.cu"
{
# 574 "dxtc.cu"
auto Color32 palette[4];
# 577 "dxtc.cu"
(((palette)[0]).b) = (((this->col0).b) << 3) | (((this->col0).b) >> 2);
# 578 "dxtc.cu"
(((palette)[0]).g) = (((this->col0).g) << 2) | (((this->col0).g) >> 4);
# 579 "dxtc.cu"
(((palette)[0]).r) = (((this->col0).r) << 3) | (((this->col0).r) >> 2);
# 580 "dxtc.cu"
(((palette)[0]).a) = (255);
# 582 "dxtc.cu"
(((palette)[1]).r) = (((this->col1).r) << 3) | (((this->col1).r) >> 2);
# 583 "dxtc.cu"
(((palette)[1]).g) = (((this->col1).g) << 2) | (((this->col1).g) >> 4);
# 584 "dxtc.cu"
(((palette)[1]).b) = (((this->col1).b) << 3) | (((this->col1).b) >> 2);
# 585 "dxtc.cu"
(((palette)[1]).a) = (255);
# 587 "dxtc.cu"
if (((this->col0).u) > ((this->col1).u)) {
# 589 "dxtc.cu"
(((palette)[2]).r) = (2 * ((palette)[0]).r + ((palette)[1]).r) / 3;
# 590 "dxtc.cu"
(((palette)[2]).g) = (2 * ((palette)[0]).g + ((palette)[1]).g) / 3;
# 591 "dxtc.cu"
(((palette)[2]).b) = (2 * ((palette)[0]).b + ((palette)[1]).b) / 3;
# 592 "dxtc.cu"
(((palette)[2]).a) = (255);
# 594 "dxtc.cu"
(((palette)[3]).r) = (2 * ((palette)[1]).r + ((palette)[0]).r) / 3;
# 595 "dxtc.cu"
(((palette)[3]).g) = (2 * ((palette)[1]).g + ((palette)[0]).g) / 3;
# 596 "dxtc.cu"
(((palette)[3]).b) = (2 * ((palette)[1]).b + ((palette)[0]).b) / 3;
# 597 "dxtc.cu"
(((palette)[3]).a) = (255);
# 598 "dxtc.cu"
} else
# 599 "dxtc.cu"
{
# 601 "dxtc.cu"
(((palette)[2]).r) = (((palette)[0]).r + ((palette)[1]).r) / 2;
# 602 "dxtc.cu"
(((palette)[2]).g) = (((palette)[0]).g + ((palette)[1]).g) / 2;
# 603 "dxtc.cu"
(((palette)[2]).b) = (((palette)[0]).b + ((palette)[1]).b) / 2;
# 604 "dxtc.cu"
(((palette)[2]).a) = (255);
# 606 "dxtc.cu"
(((palette)[3]).r) = (0);
# 607 "dxtc.cu"
(((palette)[3]).g) = (0);
# 608 "dxtc.cu"
(((palette)[3]).b) = (0);
# 609 "dxtc.cu"
(((palette)[3]).a) = (0);
# 610 "dxtc.cu"
}
# 612 "dxtc.cu"
for (int i = 0; i < 16; i++)
# 613 "dxtc.cu"
{
# 614 "dxtc.cu"
(colors[i]) = (palette)[((this->indices) >> (2 * i)) & (3)];
# 615 "dxtc.cu"
}
# 616 "dxtc.cu"
}
# 618 "dxtc.cu"
static int compareColors(const Color32 *b0, const Color32 *b1)
# 619 "dxtc.cu"
{
# 620 "dxtc.cu"
auto int sum = 0;
# 621 "dxtc.cu"
for (int i = 0; i < 16; i++)
# 622 "dxtc.cu"
{
# 623 "dxtc.cu"
auto int r = ((b0[i]).r - (b1[i]).r);
# 624 "dxtc.cu"
auto int g = ((b0[i]).g - (b1[i]).g);
# 625 "dxtc.cu"
auto int b = ((b0[i]).b - (b1[i]).b);
# 626 "dxtc.cu"
sum += (r * r + g * g) + b * b;
# 627 "dxtc.cu"
}
# 628 "dxtc.cu"
return sum;
# 629 "dxtc.cu"
}
# 631 "dxtc.cu"
static int compareBlock(const BlockDXT1 *b0, const BlockDXT1 *b1)
# 632 "dxtc.cu"
{
# 633 "dxtc.cu"
auto Color32 colors0[16];
# 634 "dxtc.cu"
auto Color32 colors1[16];
# 636 "dxtc.cu"
if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
# 637 "dxtc.cu"
{
# 638 "dxtc.cu"
return 0;
# 639 "dxtc.cu"
} else
# 641 "dxtc.cu"
{
# 642 "dxtc.cu"
b0->decompress(colors0);
# 643 "dxtc.cu"
b1->decompress(colors1);
# 645 "dxtc.cu"
return compareColors(colors0, colors1);
# 646 "dxtc.cu"
}
# 647 "dxtc.cu"
}
# 653 "dxtc.cu"
int main(int argc, char **argv)
# 654 "dxtc.cu"
{
# 656 "dxtc.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 657 "dxtc.cu"
cutilDeviceInit(argc, argv); } else {
# 659 "dxtc.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 662 "dxtc.cu"
auto unsigned char *data = (__null);
# 663 "dxtc.cu"
auto uint W; auto uint H;
# 665 "dxtc.cu"
auto char *image_path = cutFindFilePath("lena_std.ppm", argv[0]);
# 666 "dxtc.cu"
if (image_path == (0)) {
# 667 "dxtc.cu"
printf("Error, unable to find source image\n");
# 668 "dxtc.cu"
cudaThreadExit();
# 669 "dxtc.cu"
exit(1);
# 670 "dxtc.cu"
}
# 672 "dxtc.cu"
if (!(cutLoadPPM4ub(image_path, &data, &W, &H))) {
# 673 "dxtc.cu"
printf("Error, unable to open source image\n");
# 674 "dxtc.cu"
cudaThreadExit();
# 675 "dxtc.cu"
exit(1);
# 676 "dxtc.cu"
}
# 678 "dxtc.cu"
auto uint w; auto uint h;
# 684 "dxtc.cu"
w = W >> 4;
# 685 "dxtc.cu"
h = H >> 4;
# 689 "dxtc.cu"
auto const uint memSize = ((w * h) * (4));
# 690 "dxtc.cu"
__cutilCondition((0) != memSize, (char *)("dxtc.cu"), 690);
# 692 "dxtc.cu"
auto uint *image = ((uint *)malloc(memSize));
# 695 "dxtc.cu"
for (uint by = (0); by < (h / (4)); by++) {
# 696 "dxtc.cu"
for (uint bx = (0); bx < (w / (4)); bx++) {
# 697 "dxtc.cu"
for (int i = 0; i < 16; i++) {
# 698 "dxtc.cu"
auto const int x = (i & 3);
# 699 "dxtc.cu"
auto const int y = (i / 4);
# 700 "dxtc.cu"
(image[((by * w) / (4) + bx) * (16) + i]) = ((uint *)data)[(((by * (4) + y) * (4)) * (W / (4)) + bx * (4)) + x];
# 702 "dxtc.cu"
}
# 703 "dxtc.cu"
}
# 704 "dxtc.cu"
}
# 707 "dxtc.cu"
auto uint *d_data = (__null);
# 708 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_data), memSize), "dxtc.cu", 708);
# 711 "dxtc.cu"
auto uint *d_result = (__null);
# 712 "dxtc.cu"
auto const uint compressedSize = (((w / (4)) * (h / (4))) * (8));
# 713 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_result), compressedSize), "dxtc.cu", 713);
# 714 "dxtc.cu"
auto uint *result = ((uint *)malloc(compressedSize));
# 717 "dxtc.cu"
auto uint permutations[1024];
# 718 "dxtc.cu"
computePermutations(permutations);
# 721 "dxtc.cu"
auto uint *d_permutations = (__null);
# 722 "dxtc.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_permutations), (1024) * sizeof(uint)), "dxtc.cu", 722);
# 723 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_permutations, permutations, (1024) * sizeof(uint), cudaMemcpyHostToDevice), "dxtc.cu", 724);
# 727 "dxtc.cu"
auto uint timer;
# 728 "dxtc.cu"
__cutilCheckError(cutCreateTimer(&timer), "dxtc.cu", 728);
# 730 "dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 730);
# 731 "dxtc.cu"
__cutilCheckError(cutStartTimer(timer), "dxtc.cu", 731);
# 734 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(d_data, image, memSize, cudaMemcpyHostToDevice), "dxtc.cu", 734);
# 736 "dxtc.cu"
auto uint blocks = (((w + (3)) / (4)) * ((h + (3)) / (4)));
# 737 "dxtc.cu"
cudaConfigureCall(blocks, 64) ? ((void)0) : __device_stub__Z8compressPKjS0_P5uint2(d_permutations, d_data, (uint2 *)d_result);
# 739 "dxtc.cu"
__cutilCheckMsg("compress", "dxtc.cu", 739);
# 741 "dxtc.cu"
__cudaSafeCall(cudaMemcpy(result, d_result, compressedSize, cudaMemcpyDeviceToHost), "dxtc.cu", 741);
# 743 "dxtc.cu"
__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 743);
# 744 "dxtc.cu"
__cutilCheckError(cutStopTimer(timer), "dxtc.cu", 744);
# 746 "dxtc.cu"
auto float time = cutGetTimerValue(timer);
# 747 "dxtc.cu"
printf("Time %f msec\n", time);
# 749 "dxtc.cu"
auto char output_filename[1024];
# 750 "dxtc.cu"
strcpy(output_filename, image_path);
# 751 "dxtc.cu"
strcpy((output_filename + strlen(image_path)) - 3, "dds");
# 754 "dxtc.cu"
auto FILE *fp = fopen(output_filename, "wb");
# 755 "dxtc.cu"
if (fp == (0)) {
# 756 "dxtc.cu"
printf("Error, unable to open output image\n");
# 757 "dxtc.cu"
cudaThreadExit();
# 758 "dxtc.cu"
exit(1);
# 759 "dxtc.cu"
}
# 761 "dxtc.cu"
auto DDSHeader header;
# 762 "dxtc.cu"
(header.fourcc) = FOURCC_DDS;
# 763 "dxtc.cu"
(header.size) = (124);
# 764 "dxtc.cu"
(header.flags) = (((((DDSD_WIDTH) | (DDSD_HEIGHT)) | (DDSD_CAPS)) | (DDSD_PIXELFORMAT)) | (DDSD_LINEARSIZE));
# 765 "dxtc.cu"
(header.height) = h;
# 766 "dxtc.cu"
(header.width) = w;
# 767 "dxtc.cu"
(header.pitch) = compressedSize;
# 768 "dxtc.cu"
(header.depth) = (0);
# 769 "dxtc.cu"
(header.mipmapcount) = (0);
# 770 "dxtc.cu"
memset(header.reserved, 0, sizeof(header.reserved));
# 771 "dxtc.cu"
((header.pf).size) = (32);
# 772 "dxtc.cu"
((header.pf).flags) = DDPF_FOURCC;
# 773 "dxtc.cu"
((header.pf).fourcc) = FOURCC_DXT1;
# 774 "dxtc.cu"
((header.pf).bitcount) = (0);
# 775 "dxtc.cu"
((header.pf).rmask) = (0);
# 776 "dxtc.cu"
((header.pf).gmask) = (0);
# 777 "dxtc.cu"
((header.pf).bmask) = (0);
# 778 "dxtc.cu"
((header.pf).amask) = (0);
# 779 "dxtc.cu"
((header.caps).caps1) = DDSCAPS_TEXTURE;
# 780 "dxtc.cu"
((header.caps).caps2) = (0);
# 781 "dxtc.cu"
((header.caps).caps3) = (0);
# 782 "dxtc.cu"
((header.caps).caps4) = (0);
# 783 "dxtc.cu"
(header.notused) = (0);
# 785 "dxtc.cu"
fwrite(&header, sizeof(DDSHeader), 1, fp);
# 786 "dxtc.cu"
fwrite(result, compressedSize, 1, fp);
# 788 "dxtc.cu"
fclose(fp);
# 791 "dxtc.cu"
auto const char *reference_image_path = (cutFindFilePath("lena_ref.dds", argv[0]));
# 792 "dxtc.cu"
if (reference_image_path == (0)) {
# 793 "dxtc.cu"
printf("Error, unable to find reference image\n");
# 794 "dxtc.cu"
cudaThreadExit();
# 795 "dxtc.cu"
exit(1);
# 796 "dxtc.cu"
}
# 798 "dxtc.cu"
fp = fopen(reference_image_path, "rb");
# 799 "dxtc.cu"
if (fp == (0)) {
# 800 "dxtc.cu"
printf("Error, unable to open reference image\n");
# 801 "dxtc.cu"
cudaThreadExit();
# 802 "dxtc.cu"
exit(1);
# 803 "dxtc.cu"
}
# 805 "dxtc.cu"
fseek(fp, sizeof(DDSHeader), 0);
# 807 "dxtc.cu"
auto uint referenceSize = (((W / (4)) * (H / (4))) * (8));
# 808 "dxtc.cu"
auto uint *reference = ((uint *)malloc(referenceSize));
# 809 "dxtc.cu"
fread(reference, referenceSize, 1, fp);
# 811 "dxtc.cu"
fclose(fp);
# 813 "dxtc.cu"
auto float rms = (0);
# 815 "dxtc.cu"
for (uint y = (0); y < h; y += (4))
# 816 "dxtc.cu"
{
# 817 "dxtc.cu"
for (uint x = (0); x < w; x += (4))
# 818 "dxtc.cu"
{
# 819 "dxtc.cu"
auto uint referenceBlockIdx = ((y / (4)) * (W / (4)) + x / (4));
# 820 "dxtc.cu"
auto uint resultBlockIdx = ((y / (4)) * (w / (4)) + x / (4));
# 822 "dxtc.cu"
auto int cmp = compareBlock((BlockDXT1 *)result + resultBlockIdx, (BlockDXT1 *)reference + referenceBlockIdx);
# 823 "dxtc.cu"
if (cmp != (0.0F)) {
# 824 "dxtc.cu"
printf("Error at (%d, %d):\t%f rms\n", x / (4), y / (4), ((float)cmp / (16)) / (3));
# 825 "dxtc.cu"
}
# 826 "dxtc.cu"
rms += cmp;
# 827 "dxtc.cu"
}
# 828 "dxtc.cu"
}
# 829 "dxtc.cu"
rms /= (w * h) * (3);
# 831 "dxtc.cu"
printf("RMS(reference, result) = %f\n", rms);
# 833 "dxtc.cu"
if (rms <= (0.0F))
# 834 "dxtc.cu"
{
# 835 "dxtc.cu"
printf("Test PASSED\n");
# 836 "dxtc.cu"
} else
# 838 "dxtc.cu"
{
# 839 "dxtc.cu"
printf("Test FAILED\n");
# 840 "dxtc.cu"
}
# 843 "dxtc.cu"
cutFree(image_path);
# 844 "dxtc.cu"
cutFree(data);
# 845 "dxtc.cu"
free(image);
# 846 "dxtc.cu"
__cudaSafeCall(cudaFree(d_permutations), "dxtc.cu", 846);
# 847 "dxtc.cu"
__cudaSafeCall(cudaFree(d_data), "dxtc.cu", 847);
# 848 "dxtc.cu"
__cudaSafeCall(cudaFree(d_result), "dxtc.cu", 848);
# 849 "dxtc.cu"
free(result);
# 851 "dxtc.cu"
__cutilCheckError(cutDeleteTimer(timer), "dxtc.cu", 851);
# 853 "dxtc.cu"
cudaThreadExit();
# 855 "dxtc.cu"
__cutilExit(argc, argv); return 0;
# 856 "dxtc.cu"
}

# 1 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_00000e36_00000000-3_dxtc.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00000e36_00000000-3_dxtc.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x74736e6f630a7d6eull,
0x616e09090a7b2073ull,0x203d20202020656dull,0x654d726f6c6f436bull,0x7309090a63697274ull,
0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x206d756e67657309ull,0x6f09090a30203d20ull,
0x3d20207465736666ull,0x74796209090a3020ull,0x31203d2020207365ull,0x7b206d656d090a32ull,
0x386633783009090aull,0x7830203030303030ull,0x3030303030386633ull,0x3030386633783020ull,
0x0a7d090a20303030ull,0x7374736e6f630a7dull,0x6d616e09090a7b20ull,0x70203d2020202065ull,
0x09090a3473646f72ull,0x20656d616e676573ull,0x0a74736e6f63203dull,0x6d756e6765730909ull,
0x09090a30203d2020ull,0x202074657366666full,0x6209090a3434203dull,0x3d20202073657479ull,
0x6d656d090a363120ull,0x30783009090a7b20ull,0x2030303030393030ull,0x3930303030307830ull,
0x3030307830203030ull,0x7830203230313034ull,0x3230343031303030ull,0x630a7d0a7d090a20ull,
0x0a7b207374736e6full,0x2020656d616e0909ull,0x646f7270203d2020ull,0x67657309090a3373ull,
0x63203d20656d616eull,0x7309090a74736e6full,0x3d20206d756e6765ull,0x66666f09090a3020ull,
0x36203d2020746573ull,0x6574796209090a30ull,0x3631203d20202073ull,0x0a7b206d656d090aull,
0x3430303078300909ull,0x3078302030303030ull,0x2030303430303030ull,0x3130343030307830ull,
0x3030307830203130ull,0x090a203130343031ull,0x736e6f630a7d0a7dull,0x6e09090a7b207374ull,
0x3d20202020656d61ull,0x61546168706c6120ull,0x7309090a34656c62ull,0x3d20656d616e6765ull,
0x090a74736e6f6320ull,0x206d756e67657309ull,0x6f09090a30203d20ull,0x3d20207465736666ull,
0x796209090a323120ull,0x203d202020736574ull,0x206d656d090a3631ull,0x3134783009090a7bull,
0x3020303030303031ull,0x3030303030303078ull,0x3063303478302030ull,0x3478302030303030ull,
0x2030303030303430ull,0x6f630a7d0a7d090aull,0x090a7b207374736eull,0x202020656d616e09ull,
0x6168706c61203d20ull,0x090a33656c626154ull,0x656d616e67657309ull,0x74736e6f63203d20ull,
0x756e67657309090aull,0x090a30203d20206dull,0x2074657366666f09ull,0x09090a3832203d20ull,
0x2020207365747962ull,0x656d090a3631203dull,0x783009090a7b206dull,0x3030303030383034ull,
0x3030303030783020ull,0x3034783020303030ull,0x3020303030303030ull,0x3030303030303478ull,
0x0a7d0a7d090a2030ull,0x090a7b2065646f63ull,0x5f203d20656d616eull,0x6572706d6f63385aull,
0x5f30536a4b507373ull,0x0a32746e69753550ull,0x203d206d656d6c09ull,0x206d656d73090a30ull,
0x090a38383032203dull,0x32203d2020676572ull,0x2020726162090a34ull,0x6e6f63090a31203dull,
0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,0x756e676573090909ull,
0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,0x2020736574796209ull,
0x09090a3237203d20ull,0x09090a7b206d656dull,0x3030303030783009ull,0x3030783020663030ull,
0x3020303130303030ull,0x6630303030303078ull,0x3030303078302066ull,0x09090a2038303030ull,
0x3030303030783009ull,0x3030783020343030ull,0x3020323030303030ull,0x3030303030303078ull,
0x3038643378302031ull,0x09090a2030303030ull,0x3030303030783009ull,0x3030783020666433ull,
0x3020663930303030ull,0x3030303030303078ull,0x3030303078302033ull,0x09090a2030323030ull,
0x3030313134783009ull,0x3030783020303030ull,0x3020303034303030ull,0x3535353535353578ull,
0x3030303078302035ull,0x09090a2030343030ull,0x3030383034783009ull,0x3030783020303030ull,
0x0a20663130303030ull,0x090a7d090a7d0909ull,0x2065646f636e6962ull,0x3061783009090a7bull,
0x3020313030303030ull,0x3837303030343078ull,0x3038303378302030ull,0x3678302064663130ull,
0x2038633730313463ull,0x303061783009090aull,0x7830203330303063ull,0x3030303030303030ull,
0x3032303030783020ull,0x3063783020353030ull,0x0a20303837303030ull,0x6330303178300909ull,
0x3078302033303030ull,0x2030383230303030ull,0x6330303030317830ull,0x3030347830203131ull,
0x090a203038373830ull,0x3032303033783009ull,0x3463783020313130ull,0x3020303837303031ull,
0x3130303130303378ull,0x3031346378302035ull,0x09090a2030383730ull,0x3830323830367830ull,
0x3430327830203930ull,0x7830203038373030ull,0x3931303063343034ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3138303030303278ull,0x3130343078302064ull,0x6478302030383734ull,
0x2035313030333830ull,0x3738303434307830ull,0x783009090a203038ull,0x3930343032303033ull,
0x3030313463783020ull,0x3030783020303837ull,0x3020643063303030ull,0x3837303030306378ull,
0x32783009090a2030ull,0x2031316538613330ull,0x3030303030307830ull,0x3430347830206230ull,
0x7830203531613063ull,0x3330303030303030ull,0x3032783009090a20ull,0x3020393063633030ull,
0x3837383032343078ull,0x6530306478302030ull,0x3878302039303430ull,0x2030383730306330ull,
0x303030783009090aull,0x7830203930383032ull,0x3038373030303063ull,0x3030303030783020ull,
0x3063783020313161ull,0x0a20303837303030ull,0x3238306478300909ull,0x3078302031313430ull,
0x2030383730303434ull,0x3430303130337830ull,0x3134637830203531ull,0x090a203038373030ull,
0x3038303033783009ull,0x3463783020393134ull,0x3020303837303031ull,0x3038303030306178ull,
0x3030343478302039ull,0x09090a2030383734ull,0x6130383130337830ull,0x3134657830203131ull,
0x7830203038373030ull,0x3531633038313033ull,0x3030313465783020ull,0x3009090a20303837ull,
0x3034303130306378ull,0x3862333078302039ull,0x6178302062303830ull,0x2031313830303030ull,
0x3734303034347830ull,0x783009090a203038ull,0x3531613030303061ull,0x3430303434783020ull,
0x6330783020303837ull,0x3020313034313030ull,0x3837383032346578ull,0x63783009090a2030ull,
0x2031313830313030ull,0x3830386233307830ull,0x3030637830206230ull,0x7830203531613031ull,
0x6230383038623330ull,0x6330783009090a20ull,0x3020313036313030ull,0x3837303132346578ull,
0x3030633078302030ull,0x6578302031303831ull,0x2030383734313234ull,0x306330783009090aull,
0x7830203130343730ull,0x3038373830323465ull,0x3730306330783020ull,0x3465783020313036ull,
0x0a20303837303132ull,0x3130306478300909ull,0x3278302031313064ull,0x2034383730303030ull,
0x3837303063307830ull,0x3234657830203130ull,0x090a203038373431ull,0x6330303062783009ull,
0x3030783020393130ull,0x3020343837383032ull,0x3232633030306278ull,0x3132303078302031ull,
0x09090a2034383730ull,0x3463303030627830ull,0x3230307830203532ull,0x7830203438373431ull,
0x3932303034383064ull,0x3830343430783020ull,0x3009090a20303837ull,0x3234316334303478ull,
0x3030303078302039ull,0x3078302033303030ull,0x2031303437303063ull,0x3738313234657830ull,
0x783009090a203038ull,0x3131343130303030ull,0x3030303063783020ull,0x6330783020303837ull,
0x3020313036373030ull,0x3837303232346578ull,0x64783009090a2030ull,0x2031313064313030ull,
0x3730303030327830ull,0x3063307830203438ull,0x7830203130383730ull,0x3038373432323465ull,
0x3062783009090a20ull,0x3020393130633030ull,0x3837383132303078ull,0x3030306278302034ull,
0x3078302031323263ull,0x2034383730323230ull,0x303062783009090aull,0x7830203532346330ull,
0x3438373432323030ull,0x3035383064783020ull,0x3430783020393230ull,0x0a20303837383034ull,
0x6334303478300909ull,0x3078302039323431ull,0x2033303030303030ull,0x3437303063307830ull,
0x3234657830203130ull,0x090a203038373831ull,0x3130303030783009ull,0x3063783020313134ull,
0x3020303837303030ull,0x3036373030633078ull,0x3232346578302031ull,0x09090a2030383730ull,
0x3064313030647830ull,0x3030327830203131ull,0x7830203438373030ull,0x3130383730306330ull,
0x3432323465783020ull,0x3009090a20303837ull,0x3130633030306278ull,0x3132303078302039ull,
0x6278302034383738ull,0x2031323263303030ull,0x3730323230307830ull,0x783009090a203438ull,
0x3532346330303062ull,0x3432323030783020ull,0x3064783020343837ull,0x3020393230303638ull,
0x3837383034343078ull,0x34783009090a2030ull,0x2039323431633430ull,0x3030303030307830ull,
0x3063307830203330ull,0x7830203130343730ull,0x3038373831323465ull,0x3030783009090a20ull,
0x3020313134313030ull,0x3837303030306378ull,0x3030633078302030ull,0x6578302031303637ull,
0x2030383730323234ull,0x303064783009090aull,0x7830203131306431ull,0x3438373030303032ull,
0x3730306330783020ull,0x3465783020313038ull,0x0a20303837343232ull,0x3030306278300909ull,
0x3078302039313063ull,0x2034383738313230ull,0x3263303030627830ull,0x3230307830203132ull,
0x090a203438373032ull,0x6330303062783009ull,0x3030783020353234ull,0x3020343837343232ull,
0x3034373030633078ull,0x3132346578302031ull,0x09090a2030383738ull,0x3637303063307830ull,
0x3234657830203130ull,0x7830203038373032ull,0x3130383730306330ull,0x3432323465783020ull,
0x3009090a20303837ull,0x3130643130306478ull,0x3030303278302031ull,0x6578302030383730ull,
0x2039313063373830ull,0x3738303634307830ull,0x783009090a203438ull,0x3132633036303063ull,
0x3030303030783020ull,0x3030783020303837ull,0x3020643065303230ull,0x3837303030306378ull,
0x30783009090a2030ull,0x2031303437313063ull,0x3730323234657830ull,0x3830657830203038ull,
0x7830206431326337ull,0x3438373031363430ull,0x3063783009090a20ull,0x3020313263303730ull,
0x3837303030303078ull,0x3130633078302030ull,0x6578302031303637ull,0x2030383730323234ull,
0x383065783009090aull,0x7830203132346337ull,0x3438373431363430ull,0x3038303063783020ull,
0x3030783020393163ull,0x0a20303837303030ull,0x3130633078300909ull,0x6578302031303837ull,
0x2030383738313234ull,0x6530373030637830ull,0x3030307830203931ull,0x090a203038373030ull,
0x3731306330783009ull,0x3465783020313061ull,0x3020303837383132ull,0x3165303830306378ull,
0x3030303078302039ull,0x09090a2030383730ull,0x6337313063307830ull,0x3234657830203130ull,
0x7830203038373831ull,0x3931303138303063ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3065373130633078ull,0x3132346578302031ull,0x3178302030383738ull,0x2064313038383030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6466663030303033ull,0x6330306336783020ull,
0x3061783020386337ull,0x3020333030663630ull,0x3030303030303078ull,0x31783009090a2030ull,
0x2033303066363030ull,0x3230303030307830ull,0x3030327830203038ull,0x7830203931653030ull,
0x3038373030303430ull,0x3034783009090a20ull,0x3020393163383634ull,0x3030303030303078ull,
0x3230303078302033ull,0x6378302064306330ull,0x2030383730303030ull,0x306364783009090aull,
0x7830206430306435ull,0x3038373030303032ull,0x6530306431783020ull,0x3962783020383130ull,
0x0a20383130363630ull,0x3030383078300909ull,0x6578302031303030ull,0x2030383738313234ull,
0x3265303064317830ull,0x3039627830203831ull,0x090a203831323636ull,0x3030303830783009ull,
0x3465783020313032ull,0x3020303837383132ull,0x3134653030643178ull,0x3630396278302038ull,
0x09090a2038313436ull,0x3430303038307830ull,0x3234657830203130ull,0x7830203038373831ull,
0x3831366530306431ull,0x3636303962783020ull,0x3009090a20383136ull,0x3036303030383078ull,
0x3132346578302031ull,0x3178302030383738ull,0x2038313865303064ull,0x3836363039627830ull,
0x783009090a203831ull,0x3130383030303830ull,0x3831323465783020ull,0x6431783020303837ull,
0x3020383161653030ull,0x3161363630396278ull,0x30783009090a2038ull,0x2031306130303038ull,
0x3738313234657830ull,0x3030337830203038ull,0x7830206431653031ull,0x3238373030316365ull,
0x3033783009090a20ull,0x3020646666306337ull,0x6337303130633678ull,0x3530303178302038ull,
0x3078302033303063ull,0x2030383230303030ull,0x303031783009090aull,0x7830203134303030ull,
0x3330303030303030ull,0x3830303031783020ull,0x3330783020393130ull,0x0a20333030303866ull,
0x3030303178300909ull,0x3078302064313038ull,0x2033303030386633ull,0x3038303030317830ull,
0x6633307830203532ull,0x090a203330303038ull,0x6435303064783009ull,0x3032783020393030ull,
0x3020303837303030ull,0x3236363730396378ull,0x3730396378302038ull,0x09090a2030333236ull,
0x3863373038637830ull,0x3230307830206432ull,0x7830203038373030ull,0x6431326339303865ull,
0x3832323030783020ull,0x3009090a20303837ull,0x3230633930386578ull,0x3332303078302039ull,
0x6578302030383730ull,0x2035323463393038ull,0x3763323230307830ull,0x783009090a203038ull,
0x6431386336303865ull,0x6331323030783020ull,0x3865783020303837ull,0x3020393234633630ull,
0x3837383232303078ull,0x65783009090a2030ull,0x2039316163363038ull,0x3734323230307830ull,
0x3030627830203038ull,0x7830203532653061ull,0x3038373030303038ull,0x3062783009090a20ull,
0x3020353263303930ull,0x3837303030303878ull,0x3030303978302030ull,0x3078302035323231ull,
0x2030383730303030ull,0x303032783009090aull,0x7830203134303231ull,0x3330303030303030ull,
0x3039303063783020ull,0x3063783020633165ull,0x0a20383132313630ull,0x3638303378300909ull,
0x3678302064663132ull,0x2038633734313438ull,0x3231613030637830ull,0x3030307830203532ull,
0x090a203038373030ull,0x3637303031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3165303430306378ull,0x3030303078302064ull,0x09090a2030383730ull,0x3430393030657830ull,
0x3030307830206431ull,0x7830203038376331ull,0x3931613036303065ull,0x6331303030783020ull,
0x3009090a20303837ull,0x3030646630306478ull,0x3030303278302039ull,0x3078302030383730ull,
0x2031303466333034ull,0x3738313234657830ull,0x783009090a203038ull,0x6431386336303862ull,
0x3430323036783020ull,0x3862783020303837ull,0x3020313261633630ull,0x3837343032303678ull,
0x62783009090a2030ull,0x2039323263363038ull,0x3734303230367830ull,0x3038627830203038ull,
0x7830203532306336ull,0x3038373430323036ull,0x3862783009090a20ull,0x3020313336633630ull,
0x3837343032303678ull,0x3030306178302030ull,0x3278302031323031ull,0x2030383734313063ull,
0x303061783009090aull,0x7830203932343130ull,0x3038373431306332ull,0x6336303862783020ull,
0x3036783020643234ull,0x0a20303837343032ull,0x3030306178300909ull,0x3278302035333831ull,
0x2030383734313063ull,0x6538383030337830ull,0x3030337830203033ull,0x090a203432323961ull,
0x6336303862783009ull,0x3036783020643165ull,0x3020303837343032ull,0x3336313030303378ull,
0x3330343078302035ull,0x09090a2030383734ull,0x3264363038627830ull,0x3230367830203132ull,
0x7830203038373430ull,0x3932636336303862ull,0x3430323036783020ull,0x3009090a20303837ull,
0x3265303030306178ull,0x3130633278302064ull,0x3278302030383734ull,0x2035333231303030ull,
0x3734333034307830ull,0x783009090a203038ull,0x6431306436303862ull,0x3430323036783020ull,
0x3061783020303837ull,0x3020353230313030ull,0x3837343130633278ull,0x33783009090a2030ull,
0x2039323431303030ull,0x3763323034307830ull,0x3038627830203038ull,0x7830203132366436ull,
0x3038373430323036ull,0x3032783009090a20ull,0x3020633238396430ull,0x3265383930303378ull,
0x3630386278302034ull,0x3678302064313464ull,0x2030383734303230ull,0x303061783009090aull,
0x7830203132303130ull,0x3038373431306332ull,0x3962303032783020ull,0x3033783020383234ull,
0x0a20633165383830ull,0x6130303278300909ull,0x3278302030323239ull,0x2063316538383030ull,
0x3864363038627830ull,0x3230367830203132ull,0x090a203038373430ull,0x3030343032783009ull,
0x3430783020643165ull,0x3020303837303230ull,0x3261643630386278ull,0x3032303678302031ull,
0x09090a2030383734ull,0x6530303430327830ull,0x3034307830206431ull,0x7830203038373032ull,
0x3132636436303862ull,0x3430323036783020ull,0x3009090a20303837ull,0x3165303034303278ull,
0x3230343078302064ull,0x6278302030383730ull,0x2039316564363038ull,0x3734303230367830ull,
0x783009090a203038ull,0x6431653030343032ull,0x3831303430783020ull,0x3031783020303837ull,
0x3020393138663030ull,0x3837633330363078ull,0x30783009090a2030ull,0x2031303464303034ull,
0x3763313234657830ull,0x3030337830203038ull,0x7830206466643030ull,0x3863373831306336ull,
0x3061783009090a20ull,0x3020333030376230ull,0x3030303030303078ull,0x6230303178302030ull,
0x3078302033303037ull,0x2030383230303030ull,0x303030783009090aull,0x7830203930633032ull,
0x3038373030303063ull,0x3533303864783020ull,0x3032783020393030ull,0x0a20303837303030ull,
0x3730383378300909ull,0x3678302064663163ull,0x2038633734313263ull,0x6530303031327830ull,
0x3434307830206431ull,0x090a203030353831ull,0x6430303430783009ull,0x3465783020313034ull,
0x3020303035633132ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x6338313030327830ull,0x3030307830203931ull,0x7830203330303030ull,0x6466643030383033ull,
0x3431346336783020ull,0x3009090a20386337ull,0x3030666130303178ull,0x3030303078302033ull,
0x3478302030383230ull,0x2039316530633430ull,0x3030303030307830ull,0x783009090a203330ull,
0x3930633030303030ull,0x3030303063783020ull,0x3830783020303837ull,0x3020313034313030ull,
0x3837383032346578ull,0x30783009090a2030ull,0x2031303631303038ull,0x3730313234657830ull,
0x3038307830203038ull,0x7830203130383130ull,0x3038373431323465ull,0x3066783009090a20ull,
0x3020313030303030ull,0x3030303030306578ull,0x6631363878302032ull,0x3078302033306566ull,
0x2030303030303030ull,0x313034783009090aull,0x7830203330303434ull,0x3030303030303030ull,
0x6630303031783020ull,0x3430783020313138ull,0x0a20303837633330ull,0x6633303178300909ull,
0x3078302039303038ull,0x2066666666376637ull,0x3830303030327830ull,0x3034307830203931ull,
0x090a203038373030ull,0x3038383033783009ull,0x6336783020646664ull,0x3020386337633034ull,
0x3030303030303578ull,0x3030303078302033ull,0x09090a2030303530ull,0x6330323030337830ull,
0x3134637830203531ull,0x7830203038373030ull,0x3531386330303032ull,0x3431323430783020ull,
0x3009090a20303837ull,0x3161306530306478ull,0x3063303878302035ull,0x3078302030383730ull,
0x2039306330323030ull,0x3730303030637830ull,0x783009090a203038ull,0x6466643039383033ull,
0x3031346336783020ull,0x3830783020386337ull,0x3020313034623230ull,0x3035343132346578ull,
0x31783009090a2030ull,0x2035323866303030ull,0x3763333036307830ull,0x3230317830203038ull,
0x7830203931303838ull,0x3330303030303030ull,0x3030783009090a20ull,0x3020393063303030ull,
0x3837303030306378ull,0x3030303178302030ull,0x3078302039323866ull,0x2030383763333034ull,
0x303031783009090aull,0x7830206431386630ull,0x3038376333303630ull,0x6630303031783020ull,
0x3430783020393138ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302031323866ull,
0x2030383763333036ull,0x6130393030337830ull,0x3034657830206432ull,0x090a203038373030ull,
0x3161383064783009ull,0x3430783020643236ull,0x3020303837303034ull,0x3036313230303078ull,
0x3030306378302064ull,0x09090a2030383730ull,0x3630303063317830ull,0x3034327830206432ull,
0x7830203038376330ull,0x3532323932303032ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3232636230616578ull,0x3232303078302031ull,0x6578302030383730ull,0x2039313263623061ull,
0x3738313230307830ull,0x783009090a203038ull,0x6431326362306165ull,0x6331323030783020ull,
0x3033783020303837ull,0x3020646633316238ull,0x6337343134633678ull,0x32783009090a2038ull,
0x2039323431303064ull,0x3763323034307830ull,0x3030317830203038ull,0x7830203330303564ull,
0x3038323030303030ull,0x3033783009090a20ull,0x3020353234313830ull,0x3837303031636578ull,
0x3238306478302030ull,0x3078302064323431ull,0x2030383730303434ull,0x303064783009090aull,
0x7830203930306431ull,0x3038373030303032ull,0x3130313033783020ull,0x6365783020393234ull,
0x0a20303837303031ull,0x3238306478300909ull,0x3078302035323231ull,0x2030383730303434ull,
0x3631303030617830ull,0x3034347830203534ull,0x090a203038373431ull,0x6363383865783009ull,
0x3830783020643230ull,0x3020303837303236ull,0x3434313030306178ull,0x3130343478302031ull,
0x09090a2030383734ull,0x3231303030617830ull,0x3034347830203933ull,0x7830203038373431ull,
0x3133323231313063ull,0x3030303030783020ull,0x3009090a20303837ull,0x3232636338386578ull,
0x3136383078302039ull,0x6378302030383738ull,0x2035323232623030ull,0x3730303030307830ull,
0x783009090a203038ull,0x3133633130313065ull,0x3033303830783020ull,0x3063783020303837ull,
0x3020353332326130ull,0x3837303030303078ull,0x65783009090a2030ull,0x2035326331383030ull,
0x3734323038307830ull,0x3030397830203038ull,0x7830203135383130ull,0x3038373030303030ull,
0x3065783009090a20ull,0x3020313363313630ull,0x3837343330383078ull,0x3431306378302030ull,
0x6378302034323231ull,0x2030333832633030ull,0x303061783009090aull,0x7830203532323130ull,
0x3038373438303463ull,0x3130303061783020ull,0x3463783020313338ull,0x0a20303837343830ull,
0x3030306378300909ull,0x3078302035323231ull,0x2033303038663134ull,0x3831303030637830ull,
0x3234307830203133ull,0x090a203330306337ull,0x3130303061783009ull,0x6363783020353332ull,
0x3020303837343030ull,0x3338313030306178ull,0x3030636378302064ull,0x09090a2030383734ull,
0x6131303030617830ull,0x3034387830203532ull,0x7830203038373436ull,0x3934653130303061ull,
0x3436303438783020ull,0x3009090a20303837ull,0x3332316230303378ull,0x3031346378302031ull,
0x3378302030383730ull,0x2039343432353030ull,0x3730303134637830ull,0x783009090a203038ull,
0x3532346363383865ull,0x6331363830783020ull,0x3064783020303837ull,0x3020313338313231ull,
0x3837343030343078ull,0x63783009090a2030ull,0x2063343031313130ull,0x3232363030637830ull,
0x3030637830203835ull,0x7830203834323239ull,0x3435323237303063ull,0x3065783009090a20ull,
0x3020643436313031ull,0x3837633430383078ull,0x6130306578302030ull,0x3078302039353032ull,
0x2030383738353038ull,0x303065783009090aull,0x7830203934633137ull,0x3038373834303830ull,
0x3239303065783020ull,0x3830783020353530ull,0x0a20303837343530ull,0x3331306378300909ull,
0x6378302063343832ull,0x2038353832363130ull,0x3832323130637830ull,0x3130637830203834ull,
0x090a203035383235ull,0x3230303061783009ull,0x3463783020643436ull,0x3020303837343830ull,
0x3563323030306178ull,0x3830346378302035ull,0x09090a2030383734ull,0x3632303030637830ull,
0x3134307830206434ull,0x7830203330303866ull,0x3535613230303063ull,0x6337323430783020ull,
0x3009090a20333030ull,0x3536323030306178ull,0x3030636378302039ull,0x6178302030383734ull,
0x2035356132303030ull,0x3734303063637830ull,0x783009090a203038ull,0x6434633230303061ull,
0x3436303438783020ull,0x3061783020303837ull,0x3020643561323030ull,0x3837343630343878ull,
0x33783009090a2030ull,0x2064343632623030ull,0x3730303134637830ull,0x3030337830203038ull,
0x7830206435653235ull,0x3038373030313463ull,0x3064783009090a20ull,0x3020643436323731ull,
0x3837343030343078ull,0x3133306378302030ull,0x3078302035336131ull,0x2037353334306433ull,
0x333063783009090aull,0x7830203935633231ull,0x3735333430643330ull,0x3164303063783020ull,
0x3063783020633530ull,0x0a20303263326430ull,0x3830306578300909ull,0x3078302031323232ull,
0x2030383763353038ull,0x3631363130657830ull,0x3034307830203132ull,0x090a203038373032ull,
0x3164303063783009ull,0x3063783020343361ull,0x3020633263323631ull,0x3330326430306378ull,
0x3030303078302035ull,0x09090a2030383730ull,0x6331623030657830ull,0x3030307830206432ull,
0x7830203038373433ull,0x3132303130303062ull,0x3032303030783020ull,0x3009090a20303837ull,
0x3361323931306378ull,0x3863333078302035ull,0x6278302033316231ull,0x2031323031303030ull,
0x3763323030307830ull,0x783009090a203038ull,0x6433653139313063ull,0x3138633330783020ull,
0x3063783020333162ull,0x3020343561316430ull,0x3265316630306378ull,0x63783009090a2063ull,
0x2035356331353130ull,0x3730303030307830ull,0x3030657830203038ull,0x7830206432303262ull,
0x3038373435303030ull,0x3061783009090a20ull,0x3020313538323030ull,0x3837343830346378ull,
0x3030306378302030ull,0x3078302031353832ull,0x2033303038663134ull,0x303061783009090aull,
0x7830203934343230ull,0x3038373438303463ull,0x3066303063783020ull,0x3063783020343563ull,
0x0a20383165316430ull,0x3030306178300909ull,0x6378302064333832ull,0x2030383734303063ull,
0x3432303030637830ull,0x3134307830203934ull,0x090a203330303866ull,0x3236303065783009ull,
0x3830783020313532ull,0x3020303837343530ull,0x3165313133306378ull,0x3064333078302039ull,
0x09090a2037353334ull,0x3432303030617830ull,0x3063637830203934ull,0x7830203038373430ull,
0x3135343164303065ull,0x3035303430783020ull,0x3009090a20303837ull,0x3263303630306378ull,
0x3030303078302039ull,0x6378302030383730ull,0x2035333432313330ull,0x3334306433307830ull,
0x783009090a203735ull,0x3832633161303063ull,0x3064303063783020ull,0x3063783020383365ull,
0x3020633161313630ull,0x3538323431306278ull,0x65783009090a2030ull,0x2039333232373030ull,
0x3738333038307830ull,0x3030637830203038ull,0x7830206331613164ull,0x6332363134313062ull,
0x3065783009090a20ull,0x3020353232313630ull,0x3837383330343078ull,0x3730306578302030ull,
0x3078302039313032ull,0x2030383738323030ull,0x383063783009090aull,0x7830203832363131ull,
0x6331323139303062ull,0x3130383065783020ull,0x3030783020313230ull,0x0a20303837383230ull,
0x3030306278300909ull,0x3078302039316330ull,0x2030383763313030ull,0x6330323830657830ull,
0x3030307830203931ull,0x090a203038373032ull,0x3039333063783009ull,0x3330783020393163ull,
0x3020336538336564ull,0x3265313030306178ull,0x3630343878302031ull,0x09090a2030383734ull,
0x3432303030617830ull,0x3034387830206431ull,0x7830203038373436ull,0x6466643032303062ull,
0x3430303036783020ull,0x3009090a20386337ull,0x3236323830306478ull,0x3030343078302031ull,
0x6478302030383734ull,0x2064313831373030ull,0x3734303034307830ull,0x783009090a203038ull,
0x6431303230303031ull,0x6333303030783020ull,0x3031783020303836ull,0x3020393163313030ull,
0x3836633330323078ull,0x31783009090a2030ull,0x2035306130303030ull,0x3663333034307830ull,
0x3030317830203038ull,0x7830203930633030ull,0x3038366333303630ull,0x3032783009090a20ull,
0x3020313138383030ull,0x3030303030303078ull,0x6438303378302037ull,0x3678302064663930ull,
0x2038633734313463ull,0x303031783009090aull,0x7830203330303563ull,0x3038323030303030ull,
0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,0x3030306178300909ull,
0x3078302031316530ull,0x2030383730303034ull,0x6330303030617830ull,0x3034307830206430ull,
0x090a203038373030ull,0x3033303033783009ull,0x3436783020646639ull,0x3020386337633030ull,
0x3032306538306478ull,0x3034343078302035ull,0x09090a2030303538ull,0x3630303030317830ull,
0x3034307830203531ull,0x7830203030356333ull,0x6430383030303031ull,0x6333303630783020ull,
0x3009090a20303035ull,0x3161303030303178ull,0x3330343078302031ull,0x3478302030303563ull,
0x2033303033643130ull,0x3030303030307830ull,0x783009090a203030ull,0x3935303030303031ull,
0x3030303030783020ull,0x3036783020333030ull,0x3020353163326539ull,0x3837303034303278ull,
0x33783009090a2030ull,0x2064666230393830ull,0x3763303463367830ull,0x3030357830203863ull,
0x7830203330303030ull,0x3030353030303030ull,0x3032783009090a20ull,0x3020393161386131ull,
0x3130303030303078ull,0x3832303178302037ull,0x3078302035313038ull,0x2033303030303030ull,
0x303030783009090aull,0x7830206430633032ull,0x3038373030303063ull,0x3030303030783020ull,
0x3063783020393061ull,0x0a20303837303030ull,0x3030303178300909ull,0x3078302064313866ull,
0x2030383763333036ull,0x3866303030317830ull,0x3034307830203132ull,0x090a203038376333ull,
0x6630303031783009ull,0x3630783020393138ull,0x3020303837633330ull,0x3138663030303178ull,
0x3330343078302035ull,0x09090a2030383763ull,0x3866303030317830ull,0x3036307830203532ull,
0x7830203038376333ull,0x3932306337306333ull,0x3030323465783020ull,0x3009090a20303837ull,
0x3234316138306478ull,0x3034343078302039ull,0x3078302030383730ull,0x2031313431323030ull,
0x3730303030637830ull,0x783009090a203038ull,0x3932653030303031ull,0x6330303432783020ull,
0x3032783020343837ull,0x3020643165383230ull,0x3030303030303078ull,0x65783009090a2033ull,
0x2035323263613061ull,0x3734323230307830ull,0x3061657830203038ull,0x7830203531326361ull,
0x3038373431323030ull,0x6165783009090a20ull,0x3020393132636130ull,0x3837383132303078ull,
0x6238303378302030ull,0x3678302064666630ull,0x2038633734313463ull,0x303132783009090aull,
0x7830203132303130ull,0x3438376333303430ull,0x3935313031783020ull,0x3030783020333030ull,
0x0a20303832303030ull,0x3830303378300909ull,0x6578302064313031ull,0x2030383730303163ull,
0x3031323830647830ull,0x3434307830203932ull,0x090a203038373030ull,0x6431303064783009ull,
0x3032783020393030ull,0x3020303837303030ull,0x3230313031303378ull,0x3031636578302031ull,
0x09090a2030383730ull,0x6530323830647830ull,0x3434307830206431ull,0x7830203038373030ull,
0x3933343130303061ull,0x3431303434783020ull,0x3009090a20303837ull,0x3230633039386578ull,
0x3236383078302039ull,0x6178302030383734ull,0x2035333031303030ull,0x3734313034347830ull,
0x783009090a203038ull,0x6433653030303061ull,0x3431303434783020ull,0x3063783020303837ull,
0x3020313363316530ull,0x3837303030303078ull,0x65783009090a2030ull,0x2031323263303938ull,
0x3734313638307830ull,0x3030637830203038ull,0x7830206431633161ull,0x3038373030303030ull,
0x3065783009090a20ull,0x3020313365316430ull,0x3837303330383078ull,0x3830306378302030ull,
0x3078302035346331ull,0x2030383730303030ull,0x303065783009090aull,0x7830206431653139ull,
0x3038376331303830ull,0x3130303039783020ull,0x3030783020313438ull,0x0a20303837303030ull,
0x3530306578300909ull,0x3078302031336531ull,0x2030383734343038ull,0x6530303130637830ull,
0x3030637830206331ull,0x090a203033303263ull,0x3030303061783009ull,0x3463783020643165ull,
0x3020303837343830ull,0x3338313030306178ull,0x3830346378302031ull,0x09090a2030383734ull,
0x6530303030637830ull,0x3134307830206431ull,0x7830203330303866ull,0x3133383130303063ull,
0x6337323430783020ull,0x3009090a20333030ull,0x3465303030306178ull,0x3030636378302064ull,
0x6178302030383734ull,0x2035343831303030ull,0x3734303063637830ull,0x783009090a203038ull,
0x6431363230303061ull,0x3436303438783020ull,0x3061783020303837ull,0x3020393432323030ull,
0x3837343630343878ull,0x33783009090a2030ull,0x2031336530623030ull,0x3730303134637830ull,
0x3030337830203038ull,0x7830203934343235ull,0x3038373030313463ull,0x3865783009090a20ull,
0x3020643134633039ull,0x3837383136383078ull,0x3231306478302030ull,0x3078302031333831ull,
0x2030383734303034ull,0x303063783009090aull,0x7830203035323165ull,0x3435633135303063ull,
0x3137303063783020ull,0x3063783020383463ull,0x0a20383563313630ull,0x6430306578300909ull,
0x3078302031353431ull,0x2030383730353038ull,0x6131383030657830ull,0x3038307830203535ull,
0x090a203038373435ull,0x3136303065783009ull,0x3830783020393465ull,0x3020303837383430ull,
0x3561313730306578ull,0x3530383078302064ull,0x09090a2030383738ull,0x3032343130637830ull,
0x3130637830203035ull,0x7830203835303235ull,0x3834303232313063ull,0x3237313063783020ull,
0x3009090a20343530ull,0x3438323030306178ull,0x3830346378302031ull,0x6178302030383734ull,
0x2031356332303030ull,0x3734383034637830ull,0x783009090a203038ull,0x3134303230303063ull,
0x3866313430783020ull,0x3063783020333030ull,0x3020313538323030ull,0x3030633732343078ull,
0x61783009090a2033ull,0x2039353032303030ull,0x3734303063637830ull,0x3030617830203038ull,
0x7830203135383230ull,0x3038373430306363ull,0x3061783009090a20ull,0x3020313463323030ull,
0x3837343630343878ull,0x3030306178302030ull,0x3878302064353832ull,0x2030383734363034ull,
0x303033783009090aull,0x7830203134303262ull,0x3038373030313463ull,0x3235303033783020ull,
0x3463783020643565ull,0x0a20303837303031ull,0x3731306478300909ull,0x3078302031343032ull,
0x2030383734303034ull,0x3632313330637830ull,0x6433307830206434ull,0x090a203735333430ull,
0x3231333063783009ull,0x3330783020393563ull,0x3020373533343064ull,0x3532313331306378ull,
0x3331306378302063ull,0x09090a2034326332ull,0x6331393030657830ull,0x3038307830203532ull,
0x7830203038376335ull,0x3532343136313065ull,0x3432303430783020ull,0x3009090a20303837ull,
0x3436323331306378ull,0x3631306378302063ull,0x6378302038326332ull,0x2064346131333130ull,
0x3730303030307830ull,0x783009090a203038ull,0x3932653161303065ull,0x6334303030783020ull,
0x3062783020303837ull,0x3020343232313930ull,0x3232316130306278ull,0x61783009090a2034ull,
0x2039343432303030ull,0x3734383034637830ull,0x3030617830203038ull,0x7830206434613230ull,
0x3038373438303463ull,0x3063783009090a20ull,0x3020393238323931ull,0x3162313863333078ull,
0x3931306378302033ull,0x3078302031353232ull,0x2033316231386333ull,0x303063783009090aull,
0x7830203534343230ull,0x3330303866313430ull,0x3230303063783020ull,0x3430783020643436ull,
0x0a20333030386631ull,0x6130306378300909ull,0x6378302034353431ull,0x2038343832343130ull,
0x6130343130637830ull,0x3030637830206335ull,0x090a203835383261ull,0x3135313063783009ull,
0x3030783020313565ull,0x3020303837303030ull,0x3132323030306178ull,0x3030636378302035ull,
0x09090a2030383734ull,0x3632303030617830ull,0x3063637830203534ull,0x7830203038373430ull,
0x3535633136313065ull,0x6335303830783020ull,0x3009090a20303837ull,0x3461313231306578ull,
0x3530303078302064ull,0x6378302030383730ull,0x2031356130313330ull,0x3334306433307830ull,
0x783009090a203735ull,0x3934323231333063ull,0x3430643330783020ull,0x3065783020373533ull,
0x3020353530316130ull,0x3837343530343078ull,0x63783009090a2030ull,0x2038326330343130ull,
0x3832323130637830ull,0x3130637830203032ull,0x7830203831343232ull,0x3435613235313062ull,
0x3065783009090a20ull,0x3020393263313830ull,0x3837383230383078ull,0x3630306378302030ull,
0x6378302030326531ull,0x2038313832343130ull,0x303062783009090aull,0x7830203933363230ull,
0x3038373435303030ull,0x3032313065783020ull,0x3430783020643165ull,0x0a20303837383230ull,
0x3630306578300909ull,0x3078302039316131ull,0x2030383730323030ull,0x6331313830637830ull,
0x3030627830203032ull,0x090a206331653037ull,0x3130383065783009ull,0x3030783020313232ull,
0x3020303837303230ull,0x3163303030306278ull,0x3130303078302064ull,0x09090a2030383763ull,
0x3232303030617830ull,0x3034387830203931ull,0x7830203038373436ull,0x6431653032383065ull,
0x3032303030783020ull,0x3009090a20303837ull,0x3161303030306178ull,0x3630343878302035ull,
0x6478302030383734ull,0x2039313032363030ull,0x3734303034307830ull,0x783009090a203038ull,
0x6431653030303063ull,0x3038653330783020ull,0x3064783020333030ull,0x3020353138313530ull,
0x3837343030343078ull,0x62783009090a2030ull,0x2064666630323030ull,0x3734303030367830ull,
0x3130617830203863ull,0x7830203330306563ull,0x3030303030303030ull,0x3061783009090a20ull,
0x3020353134313030ull,0x3837303030343078ull,0x3030306178302030ull,0x3078302039313831ull,
0x2030383730303034ull,0x313031783009090aull,0x7830203330306563ull,0x3030313030303030ull,
0x3036303033783020ull,0x3436783020646662ull,0x0a20386337633030ull,0x3030643178300909ull,
0x3178302034303065ull,0x2063306138303030ull,0x6338323030317830ull,0x3030317830203031ull,
0x090a203830653830ull,0x6563313031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3030303030633178ull,0x3030343478302035ull,0x09090a2030383763ull,0x3030313030647830ull,
0x3034307830203530ull,0x7830203038376332ull,0x3530323031303033ull,0x3030313465783020ull,
0x3009090a20303837ull,0x3032306538306478ull,0x3034343078302035ull,0x6478302030383730ull,
0x2035303063313063ull,0x3738303234307830ull,0x783009090a203038ull,0x3431363832303031ull,
0x3830303031783020ull,0x3031783020633038ull,0x3020313161303030ull,0x3837633330343078ull,
0x66783009090a2030ull,0x2031303030303030ull,0x3030303030657830ull,0x3030327830203230ull,
0x7830203935633231ull,0x3330303030303030ull,0x3033783009090a20ull,0x3020646664323439ull,
0x6337343134383678ull,0x3431303178302038ull,0x3078302033303064ull,0x2030383230303030ull,
0x303035783009090aull,0x7830203330303030ull,0x3038373030303030ull,0x6630303430783020ull,
0x3465783020313034ull,0x0a20303837383032ull,0x3830346478300909ull,0x3278302039303064ull,
0x2030383730303030ull,0x3064333034647830ull,0x3030327830206430ull,0x090a203038373030ull,
0x3332303430783009ull,0x3465783020313034ull,0x3020303837303032ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3130313930337830ull,0x3463367830206466ull,
0x7830203863373031ull,0x3330303430323061ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3030343032303178ull,0x3030303078302033ull,0x6478302030383230ull,0x2035303030313063ull,
0x3730303030327830ull,0x783009090a203038ull,0x3930303030303431ull,0x6330303434783020ull,
0x6362783020303837ull,0x3020646631633230ull,0x6337303132303678ull,0x61783009090a2038ull,
0x2033303037653130ull,0x3030303030307830ull,0x3063317830203030ull,0x7830203930303030ull,
0x3038376330303434ull,0x3031783009090a20ull,0x3020333030376531ull,0x3031303030303078ull,
0x3130636478302030ull,0x3278302035303030ull,0x2030383730303030ull,0x303531783009090aull,
0x7830203830306530ull,0x3431306530303531ull,0x3030306330783020ull,0x3465783020313030ull,
0x0a20303837343132ull,0x3130386478300909ull,0x3278302035303030ull,0x2030383730303030ull,
0x3030303034317830ull,0x3034347830203531ull,0x090a203038376330ull,0x3030303830783009ull,
0x3465783020313030ull,0x3020303837343132ull,0x6631653230636278ull,0x3032303678302064ull,
0x09090a2061633734ull,0x3032303063317830ull,0x3034347830203930ull,0x7830203038366330ull,
0x3531303230306331ull,0x6330303434783020ull,0x3009090a20303836ull,0x3030303030633078ull,
0x3132346578302031ull,0x3178302030383634ull,0x2035313032303038ull,0x3663303034347830ull,
0x783009090a203038ull,0x3130303030303830ull,0x3431323465783020ull,0x6362783020303836ull,
0x3020646631643230ull,0x6337343032303678ull,0x31783009090a2038ull,0x2039303031303063ull,
0x3663303034347830ull,0x3063317830203038ull,0x7830203531303130ull,0x3038366330303434ull,
0x6330783009090a20ull,0x3020313030303030ull,0x3836343132346578ull,0x3030383178302030ull,
0x3478302035313031ull,0x2030383663303034ull,0x303830783009090aull,0x7830203130303030ull,
0x3038363431323465ull,0x6332306362783020ull,0x3036783020646639ull,0x0a20386337343032ull,
0x3030633178300909ull,0x3478302039303830ull,0x2030383663303034ull,0x3830303063317830ull,
0x3034347830203531ull,0x090a203038366330ull,0x3030306330783009ull,0x3465783020313030ull,
0x3020303836343132ull,0x3138303030383178ull,0x3030343478302035ull,0x09090a2030383663ull,
0x3030303038307830ull,0x3234657830203130ull,0x7830203038363431ull,0x6466356332306362ull,
0x3430323036783020ull,0x3009090a20386337ull,0x3034303030633178ull,0x3030343478302039ull,
0x3178302030383663ull,0x2035313430303063ull,0x3663303034347830ull,0x783009090a203038ull,
0x3130303030306330ull,0x3431323465783020ull,0x3831783020303836ull,0x3020353134303030ull,
0x3836633030343478ull,0x30783009090a2030ull,0x2031303030303038ull,0x3634313234657830ull,
0x3063627830203038ull,0x7830206466336332ull,0x3863373430323036ull,0x6331783009090a20ull,
0x3020393032303030ull,0x3837633030343478ull,0x3030633078302030ull,0x6578302031303030ull,
0x2030383638303234ull,0x303831783009090aull,0x7830203930323030ull,0x3038366330303434ull,
0x3030303830783020ull,0x3465783020313030ull,0x0a20303836383032ull,0x3030306678300909ull,
0x6578302031303030ull,0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,
0x090a203030303030ull,0x6438303064783009ull,0x3032783020353030ull,0x3020303837303030ull,
0x3030303030343178ull,0x3030343478302039ull,0x09090a2030383763ull,0x6566663136387830ull,
0x3030307830203330ull,0x7830203030303030ull,0x6466353030303033ull,0x3431306336783020ull,
0x3009090a20386337ull,0x3030303030303378ull,0x3030303078302033ull,0x3378302030383230ull,
0x2031303830333030ull,0x3738303034367830ull,0x783009090a203038ull,0x3530303533303064ull,
0x3030303032783020ull,0x3064783020303837ull,0x3020313032303030ull,0x3837303230343078ull,
0x33783009090a2030ull,0x2039303263313034ull,0x3730303334637830ull,0x3034337830203038ull,
0x7830203530306331ull,0x3038373030333463ull,0x3433783009090a20ull,0x3020353134633130ull,
0x3837303033346378ull,0x3130343378302030ull,0x6378302039313663ull,0x2030383730303334ull,
0x303033783009090aull,0x7830203930303032ull,0x3038373030303465ull,0x6331303433783020ull,
0x3463783020643138ull,0x0a20303837303033ull,0x3130303378300909ull,0x6578302035303030ull,
0x2030383730303034ull,0x3030353030337830ull,0x3034657830203531ull,0x090a203038373030ull,
0x3061383064783009ull,0x3430783020393034ull,0x3020303837303034ull,0x3130303630303378ull,
0x3030346578302039ull,0x09090a2030383730ull,0x3030373030337830ull,0x3034657830206431ull,
0x7830203038373030ull,0x3530323061383064ull,0x3030343430783020ull,0x3009090a20303837ull,
0x3034303230303378ull,0x3031346378302039ull,0x6478302030383730ull,0x2035316130613830ull,
0x3730303434307830ull,0x783009090a203038ull,0x3931633061383064ull,0x3030343430783020ull,
0x3064783020303837ull,0x3020643165306138ull,0x3837303034343078ull,0x64783009090a2030ull,
0x2035303230323030ull,0x3734303034307830ull,0x3030337830203038ull,0x7830203930613034ull,
0x3038373030313463ull,0x3033783009090a20ull,0x3020353163303630ull,0x3837303031346378ull,
0x3830303378302030ull,0x6378302039316530ull,0x2030383730303134ull,0x303064783009090aull,
0x7830203530323032ull,0x3038373430303430ull,0x3036303064783020ull,0x3430783020393061ull,
0x0a20303837343030ull,0x3130343378300909ull,0x6378302035316163ull,0x2030383730303334ull,
0x6363313034337830ull,0x3334637830203931ull,0x090a203038373030ull,0x3032303064783009ull,
0x3430783020353032ull,0x3020303837343030ull,0x3030303530303378ull,0x3030346578302039ull,
0x09090a2030383730ull,0x3030363030337830ull,0x3034657830203531ull,0x7830203038373030ull,
0x3931656331303433ull,0x3030333463783020ull,0x3009090a20303837ull,0x3130643130343378ull,
0x3033346378302064ull,0x6478302030383730ull,0x2039303430613830ull,0x3730303434307830ull,
0x783009090a203038ull,0x3531613061383064ull,0x3030343430783020ull,0x3033783020303837ull,
0x3020393130303630ull,0x3837303030346578ull,0x33783009090a2030ull,0x2064313030373030ull,
0x3730303034657830ull,0x3030337830203038ull,0x7830203930343061ull,0x3038373030313463ull,
0x3033783009090a20ull,0x3020353161306330ull,0x3837303031346378ull,0x6138306478302030ull,
0x3078302039316330ull,0x2030383730303434ull,0x383064783009090aull,0x7830206431653061ull,
0x3038373030343430ull,0x6431303433783020ull,0x3463783020313232ull,0x0a20303837303033ull,
0x3530306478300909ull,0x3078302039303430ull,0x2030383734303034ull,0x6330653030337830ull,
0x3134637830203531ull,0x090a203038373030ull,0x3030313033783009ull,0x3463783020393165ull,
0x3020303837303031ull,0x3130303830303378ull,0x3030346578302064ull,0x09090a2030383730ull,
0x3464313034337830ull,0x3334637830203132ull,0x7830203038373030ull,0x3530323032303064ull,
0x3430303430783020ull,0x3009090a20303837ull,0x3061303630306478ull,0x3030343078302039ull,
0x6478302030383734ull,0x2035316530613830ull,0x3730303434307830ull,0x783009090a203038ull,
0x3931303038303033ull,0x3030303465783020ull,0x3433783020303837ull,0x3020643136643130ull,
0x3837303033346378ull,0x64783009090a2030ull,0x2035303230323030ull,0x3734303034307830ull,
0x3130337830203038ull,0x7830203930613032ull,0x3038373030313463ull,0x3064783009090a20ull,
0x3020353163306138ull,0x3837303034343078ull,0x3730303378302030ull,0x6578302039313030ull,
0x2030383730303034ull,0x303433783009090aull,0x7830206431386431ull,0x3038373030333463ull,
0x3032303064783020ull,0x3430783020353032ull,0x0a20303837343030ull,0x3431303378300909ull,
0x6378302039306130ull,0x2030383730303134ull,0x6330613830647830ull,0x3434307830203531ull,
0x090a203038373030ull,0x3037303033783009ull,0x3465783020393130ull,0x3020303837303030ull,
0x3161643130343378ull,0x3033346378302064ull,0x09090a2030383730ull,0x3230323030647830ull,
0x3034307830203530ull,0x7830203038373430ull,0x3930613036313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3163306138306478ull,0x3034343078302035ull,0x3378302030383730ull,
0x2039313030373030ull,0x3730303034657830ull,0x783009090a203038ull,0x6431636431303433ull,
0x3030333463783020ull,0x3064783020303837ull,0x3020353032303230ull,0x3837343030343078ull,
0x33783009090a2030ull,0x2039306130383130ull,0x3730303134637830ull,0x3830647830203038ull,
0x7830203531633061ull,0x3038373030343430ull,0x3033783009090a20ull,0x3020393130303730ull,
0x3837303030346578ull,0x3230306478302030ull,0x3078302035303230ull,0x2030383734303034ull,
0x313033783009090aull,0x7830203930613061ull,0x3038373030313463ull,0x3061383064783020ull,
0x3430783020353163ull,0x0a20303837303034ull,0x3130343378300909ull,0x6378302039316564ull,
0x2030383730303334ull,0x3230323030647830ull,0x3034307830203530ull,0x090a203038373430ull,
0x3063313033783009ull,0x3463783020393061ull,0x3020303837303031ull,0x3130303630303378ull,
0x3030346578302039ull,0x09090a2030383730ull,0x6334303030617830ull,0x3234307830203130ull,
0x7830203038373030ull,0x3531323032303064ull,0x3430303430783020ull,0x3009090a20303837ull,
0x3038303031303378ull,0x3031346378302035ull,0x3378302030383730ull,0x2031316330653130ull,
0x3730303134637830ull,0x783009090a203038ull,0x3930303033303033ull,0x3030313463783020ull,
0x3064783020303837ull,0x3020313036303130ull,0x3837343030343078ull,0x64783009090a2030ull,
0x2035306130343030ull,0x3734303034307830ull,0x3030327830203038ull,0x7830203930306430ull,
0x3038373830323430ull,0x3064783009090a20ull,0x3020313034306530ull,0x3837303038306178ull,
0x0a7d0a7d090a2031ull,0x0000000000000000ull
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
0x2f20676e696c6970ull,0x78706d742f706d74ull,0x30303030305f7466ull,0x303030305f363365ull,
0x5f30312d30303030ull,0x7070632e63747864ull,0x6d742f2820692e33ull,0x2e23494263632f70ull,
0x0a294e714a636966ull,0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x0a0a2d2d2d2d2d2dull,0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x090a2d2d2d2d2d2dull,0x6f6974704f202f2full,0x2d2f2f090a3a736eull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x20202f2f090a2d2dull,0x703a746567726154ull,
0x3a415349202c7874ull,0x45202c33315f6d73ull,0x696c3a6e6169646eull,0x6f50202c656c7474ull,
0x6953207265746e69ull,0x2f090a34363a657aull,0x2809334f2d20202full,0x617a696d6974704full,
0x76656c206e6f6974ull,0x202f2f090a296c65ull,0x6544280930672d20ull,0x6576656c20677562ull,
0x20202f2f090a296cull,0x7065522809326d2dull,0x697664612074726full,0x0a29736569726f73ull,
0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a0a2d2d2d2d2d2dull,
0x3109656c69662e09ull,0x616d6d6f633c2209ull,0x3e656e696c2d646eull,0x656c69662e090a22ull,
0x706d742f22093209ull,0x5f746678706d742full,0x3633653030303030ull,0x303030303030305full,
0x637478645f392d30ull,0x326566616475632eull,0x2e090a227570672eull,0x22093309656c6966ull,
0x62696c2f7273752full,0x3638782f6363672full,0x756e696c2d34365full,0x2e342f756e672d78ull,
0x6c636e692f332e33ull,0x646474732f656475ull,0x2e090a22682e6665ull,0x22093409656c6966ull,
0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,
0x2f6564756c636e69ull,0x697665642f747263ull,0x69746e75725f6563ull,0x2e090a22682e656dull,
0x22093509656c6966ull,0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,
0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x6665645f74736f68ull,0x0a22682e73656e69ull,
0x3609656c69662e09ull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,
0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x69746c6975622f65ull,0x2e73657079745f6eull,
0x6c69662e090a2268ull,0x6f682f2209370965ull,0x6d616964672f656dull,0x2f706d65742f736full,
0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x7665642f6564756cull,0x657079745f656369ull,
0x662e090a22682e73ull,0x2f22093809656c69ull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,
0x622f616475632f70ull,0x692f2e2e2f2f6e69ull,0x642f6564756c636eull,0x79745f7265766972ull,
0x090a22682e736570ull,0x093909656c69662eull,0x672f656d6f682f22ull,0x742f736f6d616964ull,
0x616475632f706d65ull,0x2e2e2f2f6e69622full,0x6564756c636e692full,0x657275747865742full,
0x682e73657079745full,0x656c69662e090a22ull,0x6f682f2209303109ull,0x6d616964672f656dull,
0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x6365762f6564756cull,
0x657079745f726f74ull,0x662e090a22682e73ull,0x2209313109656c69ull,0x64672f656d6f682full,
0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,
0x6c5f656369766564ull,0x61705f68636e7561ull,0x73726574656d6172ull,0x69662e090a22682eull,
0x2f2209323109656cull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,0x622f616475632f70ull,
0x692f2e2e2f2f6e69ull,0x632f6564756c636eull,0x61726f74732f7472ull,0x7373616c635f6567ull,
0x69662e090a22682eull,0x2f2209333109656cull,0x6c636e692f727375ull,0x737469622f656475ull,
0x682e73657079742full,0x656c69662e090a22ull,0x73752f2209343109ull,0x64756c636e692f72ull,
0x682e656d69742f65ull,0x656c69662e090a22ull,0x6475432209353109ull,0x22682e6874614d61ull,
0x09656c69662e090aull,0x6374786422093631ull,0x662e090a2275632eull,0x2209373109656c69ull,
0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,
0x2f6564756c636e69ull,0x665f6e6f6d6d6f63ull,0x736e6f6974636e75ull,0x69662e090a22682eull,
0x2f2209383109656cull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,0x622f616475632f70ull,
0x692f2e2e2f2f6e69ull,0x632f6564756c636eull,0x5f636e75662f7472ull,0x22682e6f7263616dull,
0x09656c69662e090aull,0x6d6f682f22093931ull,0x6f6d616964672f65ull,0x632f706d65742f73ull,
0x2f6e69622f616475ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09303209656c6966ull,0x672f656d6f682f22ull,0x742f736f6d616964ull,
0x616475632f706d65ull,0x2e2e2f2f6e69622full,0x6564756c636e692full,0x5f6563697665642full,
0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209313209656c69ull,0x64672f656d6f682full,
0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,
0x6e6f635f6874616dull,0x682e73746e617473ull,0x656c69662e090a22ull,0x6f682f2209323209ull,
0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,
0x5f6d732f6564756cull,0x696d6f74615f3131ull,0x6974636e75665f63ull,0x090a22682e736e6full,
0x333209656c69662eull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,
0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x5f32315f6d732f65ull,0x665f63696d6f7461ull,
0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209343209656cull,0x6964672f656d6f68ull,
0x6d65742f736f6d61ull,0x622f616475632f70ull,0x692f2e2e2f2f6e69ull,0x732f6564756c636eull,
0x756f645f33315f6dull,0x636e75665f656c62ull,0x22682e736e6f6974ull,0x09656c69662e090aull,
0x6d6f682f22093532ull,0x6f6d616964672f65ull,0x632f706d65742f73ull,0x2f6e69622f616475ull,
0x6c636e692f2e2e2full,0x747865742f656475ull,0x637465665f657275ull,0x6974636e75665f68ull,
0x090a22682e736e6full,0x363209656c69662eull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,
0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x665f6874616d2f65ull,
0x736e6f6974636e75ull,0x7874705f6c62645full,0x2e090a0a22682e33ull,0x2e20646572616873ull,
0x2034206e67696c61ull,0x61766f632038622eull,0x5f5f65636e616972ull,0x0a3b5d3438335b30ull,
0x6465726168732e09ull,0x206e67696c612e20ull,0x6e692038622e2034ull,0x315f5f7365636964ull,
0x090a3b5d3635325bull,0x206465726168732eull,0x34206e67696c612eull,0x705f732038622e20ull,
0x69746174756d7265ull,0x365b325f5f736e6full,0x732e090a3b5d3034ull,0x612e206465726168ull,
0x2e2034206e67696cull,0x5f5f737064203862ull,0x090a3b5d34365b33ull,0x2e2074736e6f632eull,
0x2034206e67696c61ull,0x6c6f436b2038622eull,0x63697274654d726full,0x7b203d205d32315bull,
0x2c3832312c302c30ull,0x312c302c302c3336ull,0x2c302c33362c3832ull,0x33362c3832312c30ull,
0x6e6f632e090a3b7dull,0x67696c612e207473ull,0x2038622e2034206eull,0x6261546168706c61ull,
0x205d36315b34656cull,0x312c302c307b203dull,0x302c302c35362c36ull,0x302c302c302c302cull,
0x2c34362c3239312cull,0x362c34362c302c30ull,0x6f632e090a3b7d34ull,0x696c612e2074736eull,
0x38622e2034206e67ull,0x61546168706c6120ull,0x5d36315b33656c62ull,0x2c302c307b203d20ull,
0x302c34362c383231ull,0x302c302c302c302cull,0x2c34362c302c302cull,0x34362c302c302c30ull,
0x6e6f632e090a3b7dull,0x67696c612e207473ull,0x2038622e2034206eull,0x315b3473646f7270ull,
0x2c307b203d205d36ull,0x2c302c302c392c30ull,0x2c322c302c302c39ull,0x2c322c302c342c31ull,
0x0a3b7d302c312c34ull,0x2074736e6f632e09ull,0x34206e67696c612eull,0x6f72702038622e20ull,
0x205d36315b337364ull,0x342c302c307b203dull,0x302c342c302c302cull,0x342c312c312c302cull,
0x312c342c312c302cull,0x2e090a0a3b7d302cull,0x5a5f207972746e65ull,0x736572706d6f6338ull,
0x505f30536a4b5073ull,0x090a32746e697535ull,0x206765722e090a7bull,0x687225203631752eull,
0x2e090a3b3e35313cull,0x3233752e20676572ull,0x3e3134323c722520ull,0x206765722e090a3bull,
0x647225203436752eull,0x2e090a3b3e33373cull,0x3233662e20676572ull,0x3e3539333c662520ull,
0x206765722e090a3bull,0x702520646572702eull,0x2e090a3b3e39323cull,0x752e206d61726170ull,
0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x736572706d6f6338ull,0x505f30536a4b5073ull,
0x705f32746e697535ull,0x69746174756d7265ull,0x702e090a3b736e6full,0x36752e206d617261ull,
0x616475635f5f2034ull,0x385a5f5f6d726170ull,0x73736572706d6f63ull,0x35505f30536a4b50ull,
0x6d695f32746e6975ull,0x702e090a3b656761ull,0x36752e206d617261ull,0x616475635f5f2034ull,
0x385a5f5f6d726170ull,0x73736572706d6f63ull,0x35505f30536a4b50ull,0x65725f32746e6975ull,
0x2e090a3b746c7573ull,0x2e20646572616873ull,0x2034206e67696c61ull,0x75635f5f2038622eull,
0x726f6c6f635f6164ull,0x39315b3836333173ull,0x68732e090a3b5d32ull,0x6c612e2064657261ull,
0x622e2034206e6769ull,0x616475635f5f2038ull,0x363531736d75735full,0x0a3b5d3239315b30ull,
0x6465726168732e09ull,0x206e67696c612e20ull,0x5f5f2038622e2034ull,0x6572785f61647563ull,
0x365b323537317366ull,0x68732e090a3b5d34ull,0x6c612e2064657261ull,0x622e2034206e6769ull,
0x616475635f5f2038ull,0x3173726f7272655full,0x5d3635325b363138ull,0x6562202f2f090a3bull,
0x2074726174537473ull,0x2f2f090a3032203dull,0x646e457473656220ull,0x2f090a3232203d20ull,
0x655074736562202full,0x6f69746174756d72ull,0x090a3631203d206eull,0x09363109636f6c2eull,
0x4c240a3009383035ull,0x63385a5f5f314242ull,0x5073736572706d6full,0x7535505f30536a4bull,
0x2e090a3a32746e69ull,0x3509363109636f6cull,0x7663090a30093631ull,0x31752e3233732e74ull,
0x202c317225092036ull,0x203b782e64697425ull,0x202f2f0920202020ull,0x36752e747663090aull,
0x2509203233732e34ull,0x317225202c316472ull,0x202020202020203bull,0x756d090a202f2f09ull,
0x3436752e6f6c2e6cull,0x202c326472250920ull,0x3b34202c31647225ull,0x202f2f0920202020ull,
0x33752e766f6d090aull,0x202c327225092032ull,0x20202020203b3531ull,0x2020202020202020ull,
0x6573090a202f2f09ull,0x33732e74672e7074ull,0x202c317025092032ull,0x327225202c317225ull,
0x202f2f092020203bull,0x622031702540090aull,0x5f744c2409206172ull,0x20203b3131315f30ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x343109363109636full,0x766f6d090a300938ull,
0x722509203436752eull,0x75635f5f202c3364ull,0x726f6c6f635f6164ull,0x2f093b3836333173ull,
0x2e766f6d090a202full,0x6472250920343675ull,0x7261766f63202c34ull,0x305f5f65636e6169ull,
0x090a202f2f09203bull,0x203436752e766f6dull,0x5f202c3564722509ull,0x75735f616475635full,
0x093b30363531736dull,0x2e646c090a202f2full,0x36752e6d61726170ull,0x2c36647225092034ull,
0x616475635f5f5b20ull,0x385a5f5f6d726170ull,0x73736572706d6f63ull,0x35505f30536a4b50ull,
0x6d695f32746e6975ull,0x2f2f093b5d656761ull,0x313832323a646920ull,0x70616475635f5f20ull,
0x63385a5f5f6d7261ull,0x5073736572706d6full,0x7535505f30536a4bull,0x616d695f32746e69ull,
0x090a3078302b6567ull,0x2e3233732e747663ull,0x3372250920363175ull,0x646961746325202cull,
0x2f092020203b782eull,0x2e747663090a202full,0x203233752e363175ull,0x25202c3168722509ull,
0x20202020203b3372ull,0x090a202f2f092020ull,0x656469772e6c756dull,0x722509203631732eull,
0x2c31687225202c34ull,0x2f0920203b363120ull,0x2e646461090a202full,0x3572250920323373ull,
0x25202c317225202cull,0x20202020203b3472ull,0x090a202f2f092020ull,0x2e3436732e747663ull,
0x6472250920323373ull,0x203b357225202c37ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c38647225ull,0x20203b34202c3764ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3964722509ull,0x647225202c366472ull,0x2f09202020203b38ull,
0x672e646c090a202full,0x33752e6c61626f6cull,0x202c367225092032ull,0x5d302b396472255bull,
0x6469202f2f09203bull,0x2e090a333832323aull,0x3109363109636f6cull,0x6e61090a30093035ull,
0x2509203233622e64ull,0x2c367225202c3772ull,0x2020203b35353220ull,0x202f2f0920202020ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c303164ull,0x20203b3231202c31ull,
0x7663090a202f2f09ull,0x3233662e6e722e74ull,0x662509203233752eull,0x203b377225202c31ull,
0x202f2f0920202020ull,0x36752e646461090aull,0x3131647225092034ull,0x2c3031647225202cull,
0x20203b3364722520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x62336630202c3266ull,
0x203b313830383038ull,0x202f2f0920202020ull,0x3132393330302e30ull,0x2e6c756d090a3735ull,
0x3366250920323366ull,0x25202c316625202cull,0x20202020203b3266ull,0x090a202f2f092020ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x5d302b3131647225ull,0x2f093b336625202cull,
0x3832323a6469202full,0x616475635f5f2034ull,0x3173726f6c6f635full,0x0a3078302b383633ull,
0x363109636f6c2e09ull,0x090a300931353109ull,0x203233622e6c6873ull,0x7225202c38722509ull,
0x20203b3631202c36ull,0x2f09202020202020ull,0x2e726873090a202full,0x3972250920323375ull,
0x32202c387225202cull,0x2020202020203b34ull,0x090a202f2f092020ull,0x662e6e722e747663ull,
0x09203233752e3233ull,0x397225202c346625ull,0x2f0920202020203bull,0x2e766f6d090a202full,
0x3566250920323366ull,0x303862336630202cull,0x2020203b31383038ull,0x2e30202f2f092020ull,
0x3735313239333030ull,0x33662e6c756d090aull,0x202c366625092032ull,0x356625202c346625ull,
0x202020202020203bull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920323366ull,
0x202c5d342b313164ull,0x202f2f093b366625ull,0x20353832323a6469ull,0x635f616475635f5full,
0x36333173726f6c6full,0x2e090a3078302b38ull,0x3109363109636f6cull,0x6873090a30093235ull,
0x2509203233622e6cull,0x367225202c303172ull,0x202020203b38202cull,0x202f2f0920202020ull,
0x33752e726873090aull,0x2c31317225092032ull,0x32202c3031722520ull,0x2020202020203b34ull,
0x7663090a202f2f09ull,0x3233662e6e722e74ull,0x662509203233752eull,0x3b31317225202c37ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x202c386625092032ull,0x3038303862336630ull,
0x20202020203b3138ull,0x30302e30202f2f09ull,0x090a373531323933ull,0x203233662e6c756dull,
0x6625202c39662509ull,0x203b386625202c37ull,0x2f09202020202020ull,0x732e7473090a202full,
0x33662e6465726168ull,0x316472255b092032ull,0x6625202c5d382b31ull,0x6469202f2f093b39ull,
0x5f5f20363832323aull,0x6c6f635f61647563ull,0x2b3836333173726full,0x6f6c2e090a307830ull,
0x3036310936310963ull,0x2e646461090a3009ull,0x6472250920343675ull,0x31647225202c3231ull,
0x3b35647225202c30ull,0x090a202f2f092020ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x5d302b3231647225ull,0x2f093b336625202cull,0x3832323a6469202full,0x616475635f5f2037ull,
0x363531736d75735full,0x73090a3078302b30ull,0x6465726168732e74ull,0x255b09203233662eull,
0x2c5d342b32316472ull,0x2f2f093b36662520ull,0x383832323a646920ull,0x5f616475635f5f20ull,
0x30363531736d7573ull,0x7473090a3078302bull,0x2e6465726168732eull,0x72255b0920323366ull,
0x202c5d382b323164ull,0x202f2f093b396625ull,0x20393832323a6469ull,0x735f616475635f5full,
0x2b30363531736d75ull,0x726f78090a307830ull,0x722509203233622eull,0x2c317225202c3231ull,
0x20202020203b3820ull,0x0a202f2f09202020ull,0x3436732e74766309ull,0x722509203233732eull,
0x317225202c333164ull,0x0920202020203b32ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c343164722509ull,0x31202c3331647225ull,0x0a202f2f09203b32ull,0x3436752e64646109ull,
0x2c35316472250920ull,0x25202c3564722520ull,0x0920203b34316472ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3031662509203233ull,0x35316472255b202cull,0x202f2f093b5d302bull,
0x20303932323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x2e646c090a307830ull,
0x662e646572616873ull,0x3131662509203233ull,0x35316472255b202cull,0x202f2f093b5d342bull,
0x20313932323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x2e646c090a307830ull,
0x662e646572616873ull,0x3231662509203233ull,0x35316472255b202cull,0x202f2f093b5d382bull,
0x20323932323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x646461090a307830ull,
0x662509203233662eull,0x2c336625202c3331ull,0x20203b3031662520ull,0x0a202f2f09202020ull,
0x726168732e747309ull,0x09203233662e6465ull,0x302b32316472255bull,0x3b33316625202c5dull,
0x323a6469202f2f09ull,0x75635f5f20333932ull,0x31736d75735f6164ull,0x0a3078302b303635ull,
0x3233662e64646109ull,0x202c343166250920ull,0x316625202c366625ull,0x0920202020203b31ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d342b3231ull,
0x202f2f093b343166ull,0x20343932323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,
0x646461090a307830ull,0x662509203233662eull,0x2c396625202c3531ull,0x20203b3231662520ull,
0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233662e6465ull,0x382b32316472255bull,
0x3b35316625202c5dull,0x323a6469202f2f09ull,0x75635f5f20353932ull,0x31736d75735f6164ull,
0x0a3078302b303635ull,0x3233622e726f7809ull,0x202c333172250920ull,0x203b34202c317225ull,
0x0920202020202020ull,0x747663090a202f2full,0x3233732e3436732eull,0x2c36316472250920ull,
0x20203b3331722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3731ull,0x09203b3231202c36ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c383164ull,0x3731647225202c35ull,0x0a202f2f0920203bull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c36316625ull,0x3b5d302b38316472ull,0x323a6469202f2f09ull,
0x75635f5f20363932ull,0x31736d75735f6164ull,0x0a3078302b303635ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c37316625ull,0x3b5d342b38316472ull,0x323a6469202f2f09ull,
0x75635f5f20373932ull,0x31736d75735f6164ull,0x0a3078302b303635ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c38316625ull,0x3b5d382b38316472ull,0x323a6469202f2f09ull,
0x75635f5f20383932ull,0x31736d75735f6164ull,0x0a3078302b303635ull,0x3233662e64646109ull,
0x202c393166250920ull,0x6625202c33316625ull,0x09202020203b3631ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3231ull,0x202f2f093b393166ull,
0x20393932323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x646461090a307830ull,
0x662509203233662eull,0x34316625202c3032ull,0x203b37316625202cull,0x0a202f2f09202020ull,
0x726168732e747309ull,0x09203233662e6465ull,0x342b32316472255bull,0x3b30326625202c5dull,
0x323a6469202f2f09ull,0x75635f5f20303033ull,0x31736d75735f6164ull,0x0a3078302b303635ull,
0x3233662e64646109ull,0x202c313266250920ull,0x6625202c35316625ull,0x09202020203b3831ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d382b3231ull,
0x202f2f093b313266ull,0x20313033323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,
0x726f78090a307830ull,0x722509203233622eull,0x2c317225202c3431ull,0x20202020203b3220ull,
0x0a202f2f09202020ull,0x3436732e74766309ull,0x722509203233732eull,0x317225202c393164ull,
0x0920202020203b34ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c303264722509ull,
0x31202c3931647225ull,0x0a202f2f09203b32ull,0x3436752e64646109ull,0x2c31326472250920ull,
0x25202c3564722520ull,0x0920203b30326472ull,0x2e646c090a202f2full,0x662e646572616873ull,
0x3232662509203233ull,0x31326472255b202cull,0x202f2f093b5d302bull,0x20323033323a6469ull,
0x735f616475635f5full,0x2b30363531736d75ull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3332662509203233ull,0x31326472255b202cull,0x202f2f093b5d342bull,0x20333033323a6469ull,
0x735f616475635f5full,0x2b30363531736d75ull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3432662509203233ull,0x31326472255b202cull,0x202f2f093b5d382bull,0x20343033323a6469ull,
0x735f616475635f5full,0x2b30363531736d75ull,0x646461090a307830ull,0x662509203233662eull,
0x39316625202c3532ull,0x203b32326625202cull,0x0a202f2f09202020ull,0x726168732e747309ull,
0x09203233662e6465ull,0x302b32316472255bull,0x3b35326625202c5dull,0x323a6469202f2f09ull,
0x75635f5f20353033ull,0x31736d75735f6164ull,0x0a3078302b303635ull,0x3233662e64646109ull,
0x202c363266250920ull,0x6625202c30326625ull,0x09202020203b3332ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d342b3231ull,0x202f2f093b363266ull,
0x20363033323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x646461090a307830ull,
0x662509203233662eull,0x31326625202c3732ull,0x203b34326625202cull,0x0a202f2f09202020ull,
0x726168732e747309ull,0x09203233662e6465ull,0x382b32316472255bull,0x3b37326625202c5dull,
0x323a6469202f2f09ull,0x75635f5f20373033ull,0x31736d75735f6164ull,0x0a3078302b303635ull,
0x3233622e726f7809ull,0x202c353172250920ull,0x203b31202c317225ull,0x0920202020202020ull,
0x747663090a202f2full,0x3233732e3436732eull,0x2c32326472250920ull,0x20203b3531722520ull,
0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x32647225202c3332ull,
0x09203b3231202c32ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c343264ull,
0x3332647225202c35ull,0x0a202f2f0920203bull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c38326625ull,0x3b5d342b34326472ull,0x323a6469202f2f09ull,0x75635f5f20383033ull,
0x31736d75735f6164ull,0x0a3078302b303635ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c39326625ull,0x3b5d382b34326472ull,0x323a6469202f2f09ull,0x75635f5f20393033ull,
0x31736d75735f6164ull,0x0a3078302b303635ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c30336625ull,0x3b5d302b34326472ull,0x323a6469202f2f09ull,0x75635f5f20303133ull,
0x31736d75735f6164ull,0x0a3078302b303635ull,0x3233662e64646109ull,0x202c313366250920ull,
0x6625202c30336625ull,0x09202020203b3532ull,0x2e7473090a202f2full,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3231ull,0x202f2f093b313366ull,0x20313133323a6469ull,
0x735f616475635f5full,0x2b30363531736d75ull,0x646461090a307830ull,0x662509203233662eull,
0x36326625202c3233ull,0x203b38326625202cull,0x0a202f2f09202020ull,0x726168732e747309ull,
0x09203233662e6465ull,0x342b32316472255bull,0x3b32336625202c5dull,0x323a6469202f2f09ull,
0x75635f5f20323133ull,0x31736d75735f6164ull,0x0a3078302b303635ull,0x3233662e64646109ull,
0x202c333366250920ull,0x6625202c37326625ull,0x09202020203b3932ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d382b3231ull,0x202f2f093b333366ull,
0x20333133323a6469ull,0x735f616475635f5full,0x2b30363531736d75ull,0x6f6c2e090a307830ull,
0x3531320935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x2c34336625092032ull,
0x616475635f5f5b20ull,0x363531736d75735full,0x2f2f093b5d302b30ull,0x343133323a646920ull,
0x5f616475635f5f20ull,0x30363531736d7573ull,0x6f6d090a3078302bull,0x2509203233662e76ull,
0x336630202c353366ull,0x3b30303030303864ull,0x202f2f0920202020ull,0x090a353236302e30ull,
0x203233662e6c756dull,0x25202c3633662509ull,0x336625202c343366ull,0x2f09202020203b35ull,
0x2e627573090a202full,0x3366250920323366ull,0x202c336625202c37ull,0x2020203b36336625ull,
0x090a202f2f092020ull,0x732e6f6c2e6c756dull,0x3631722509203233ull,0x36202c317225202cull,
0x2f0920202020203bull,0x2e747663090a202full,0x203233732e343673ull,0x202c353264722509ull,
0x2020203b36317225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,
0x3532647225202c36ull,0x2f0920203b34202cull,0x2e646461090a202full,0x6472250920343675ull,
0x34647225202c3732ull,0x3b3632647225202cull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3833662509ull,0x336625202c373366ull,0x2f09202020203b37ull,0x732e7473090a202full,
0x33662e6465726168ull,0x326472255b092032ull,0x6625202c5d302b37ull,0x69202f2f093b3833ull,
0x6320353133323a64ull,0x636e61697261766full,0x3078302b305f5f65ull,0x3109636f6c2e090aull,
0x0a30093631320935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c39336625ull,
0x75735f616475635full,0x342b30363531736dull,0x6469202f2f093b5dull,0x5f5f20363133323aull,
0x6d75735f61647563ull,0x78302b3036353173ull,0x662e766f6d090a34ull,0x3034662509203233ull,
0x303864336630202cull,0x2020203b30303030ull,0x302e30202f2f0920ull,0x6c756d090a353236ull,
0x662509203233662eull,0x39336625202c3134ull,0x203b30346625202cull,0x0a202f2f09202020ull,
0x3233662e62757309ull,0x202c323466250920ull,0x346625202c366625ull,0x0920202020203b31ull,
0x6c756d090a202f2full,0x662509203233662eull,0x37336625202c3334ull,0x203b32346625202cull,
0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233662e6465ull,0x342b37326472255bull,
0x3b33346625202c5dull,0x323a6469202f2f09ull,0x61766f6320373133ull,0x5f5f65636e616972ull,
0x2e090a3078302b30ull,0x3209353109636f6cull,0x646c090a30093731ull,0x2e6465726168732eull,
0x3466250920323366ull,0x75635f5f5b202c34ull,0x31736d75735f6164ull,0x093b5d382b303635ull,
0x33323a6469202f2full,0x6475635f5f203831ull,0x3531736d75735f61ull,0x090a3878302b3036ull,
0x203233662e766f6dull,0x30202c3534662509ull,0x3030303038643366ull,0x2f09202020203b30ull,
0x353236302e30202full,0x33662e6c756d090aull,0x2c36346625092032ull,0x25202c3434662520ull,
0x202020203b353466ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x396625202c373466ull,
0x203b36346625202cull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c38346625092032ull,
0x25202c3733662520ull,0x202020203b373466ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x202c5d382b373264ull,0x2f2f093b38346625ull,0x393133323a646920ull,
0x61697261766f6320ull,0x302b305f5f65636eull,0x636f6c2e090a3078ull,0x0938313209353109ull,
0x662e6c756d090a30ull,0x3934662509203233ull,0x202c32346625202cull,0x2020203b32346625ull,
0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203233662eull,0x5d32312b37326472ull,
0x093b39346625202cull,0x33323a6469202f2full,0x7261766f63203032ull,0x305f5f65636e6169ull,
0x6c2e090a3078302bull,0x313209353109636full,0x6c756d090a300939ull,0x662509203233662eull,
0x32346625202c3035ull,0x203b37346625202cull,0x0a202f2f09202020ull,0x726168732e747309ull,
0x09203233662e6465ull,0x312b37326472255bull,0x30356625202c5d36ull,0x3a6469202f2f093bull,
0x766f632031323332ull,0x5f65636e61697261ull,0x090a3078302b305full,0x09353109636f6c2eull,
0x6d090a3009303232ull,0x09203233662e6c75ull,0x6625202c31356625ull,0x37346625202c3734ull,
0x2f2f09202020203bull,0x68732e7473090a20ull,0x3233662e64657261ull,0x37326472255b0920ull,
0x6625202c5d30322bull,0x69202f2f093b3135ull,0x6320323233323a64ull,0x636e61697261766full,
0x3078302b305f5f65ull,0x33732e766f6d090aull,0x2c37317225092032ull,0x20202020203b3820ull,
0x2020202020202020ull,0x744c240a202f2f09ull,0x0a3a3531315f305full,0x706f6f6c3c2f2f20ull,
0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c30323220ull,0x656420676e697473ull,
0x202c31203a687470ull,0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,
0x73090a6e776f6e6bull,0x732e656c2e707465ull,0x2c32702509203233ull,0x25202c3731722520ull,
0x2f2f0920203b3172ull,0x2032702540090a20ull,0x744c240920617262ull,0x203b3631315f305full,
0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3032ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x636f6c2e090a3531ull,0x0936323209353109ull,0x732e646461090a30ull,
0x3831722509203233ull,0x202c37317225202cull,0x202020203b317225ull,0x6d090a202f2f0920ull,
0x33732e6f6c2e6c75ull,0x2c39317225092032ull,0x36202c3831722520ull,0x2f2f09202020203bull,
0x732e747663090a20ull,0x09203233732e3436ull,0x25202c3832647225ull,0x202020203b393172ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3932647225092034ull,0x2c3832647225202cull,
0x2f2f0920203b3420ull,0x752e646461090a20ull,0x3364722509203436ull,0x2c34647225202c30ull,
0x203b393264722520ull,0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3235ull,0x2f093b5d302b3732ull,0x3233323a6469202full,0x697261766f632033ull,
0x2b305f5f65636e61ull,0x2e646c090a307830ull,0x662e646572616873ull,0x3335662509203233ull,
0x30336472255b202cull,0x202f2f093b5d302bull,0x20343233323a6469ull,0x6e61697261766f63ull,
0x78302b305f5f6563ull,0x662e646461090a30ull,0x3435662509203233ull,0x202c32356625202cull,
0x2020203b33356625ull,0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203233662eull,
0x2c5d302b37326472ull,0x2f093b3435662520ull,0x3233323a6469202full,0x697261766f632035ull,
0x2b305f5f65636e61ull,0x6f6c2e090a307830ull,0x3732320935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c35356625092032ull,0x2b37326472255b20ull,0x69202f2f093b5d34ull,
0x6320363233323a64ull,0x636e61697261766full,0x3078302b305f5f65ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3635662509ull,0x5d342b3033647225ull,0x3a6469202f2f093bull,
0x766f632037323332ull,0x5f65636e61697261ull,0x090a3078302b305full,0x203233662e646461ull,
0x25202c3735662509ull,0x356625202c353566ull,0x2f09202020203b36ull,0x732e7473090a202full,
0x33662e6465726168ull,0x326472255b092032ull,0x6625202c5d342b37ull,0x69202f2f093b3735ull,
0x6320383233323a64ull,0x636e61697261766full,0x3078302b305f5f65ull,0x3109636f6c2e090aull,
0x0a30093832320935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c38356625ull,
0x3b5d382b37326472ull,0x323a6469202f2f09ull,0x61766f6320393233ull,0x5f5f65636e616972ull,
0x6c090a3078302b30ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3935ull,
0x2f093b5d382b3033ull,0x3333323a6469202full,0x697261766f632030ull,0x2b305f5f65636e61ull,
0x646461090a307830ull,0x662509203233662eull,0x38356625202c3036ull,0x203b39356625202cull,
0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233662e6465ull,0x382b37326472255bull,
0x3b30366625202c5dull,0x323a6469202f2f09ull,0x61766f6320313333ull,0x5f5f65636e616972ull,
0x2e090a3078302b30ull,0x3209353109636f6cull,0x646c090a30093932ull,0x2e6465726168732eull,
0x3666250920323366ull,0x326472255b202c31ull,0x2f093b5d32312b37ull,0x3333323a6469202full,
0x697261766f632032ull,0x2b305f5f65636e61ull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3236662509203233ull,0x30336472255b202cull,0x2f2f093b5d32312bull,0x333333323a646920ull,
0x61697261766f6320ull,0x302b305f5f65636eull,0x2e646461090a3078ull,0x3666250920323366ull,
0x2c31366625202c33ull,0x20203b3236662520ull,0x090a202f2f092020ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x32312b3732647225ull,0x3b33366625202c5dull,0x323a6469202f2f09ull,
0x61766f6320343333ull,0x5f5f65636e616972ull,0x2e090a3078302b30ull,0x3209353109636f6cull,
0x646c090a30093033ull,0x2e6465726168732eull,0x3666250920323366ull,0x326472255b202c34ull,
0x2f093b5d36312b37ull,0x3333323a6469202full,0x697261766f632035ull,0x2b305f5f65636e61ull,
0x2e646c090a307830ull,0x662e646572616873ull,0x3536662509203233ull,0x30336472255b202cull,
0x2f2f093b5d36312bull,0x363333323a646920ull,0x61697261766f6320ull,0x302b305f5f65636eull,
0x2e646461090a3078ull,0x3666250920323366ull,0x2c34366625202c36ull,0x20203b3536662520ull,
0x090a202f2f092020ull,0x65726168732e7473ull,0x5b09203233662e64ull,0x36312b3732647225ull,
0x3b36366625202c5dull,0x323a6469202f2f09ull,0x61766f6320373333ull,0x5f5f65636e616972ull,
0x2e090a3078302b30ull,0x3209353109636f6cull,0x646c090a30093133ull,0x2e6465726168732eull,
0x3666250920323366ull,0x326472255b202c37ull,0x2f093b5d30322b37ull,0x3333323a6469202full,
0x697261766f632038ull,0x2b305f5f65636e61ull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3836662509203233ull,0x30336472255b202cull,0x2f2f093b5d30322bull,0x393333323a646920ull,
0x61697261766f6320ull,0x302b305f5f65636eull,0x2e646461090a3078ull,0x3666250920323366ull,
0x2c37366625202c39ull,0x20203b3836662520ull,0x090a202f2f092020ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x30322b3732647225ull,0x3b39366625202c5dull,0x323a6469202f2f09ull,
0x61766f6320303433ull,0x5f5f65636e616972ull,0x4c240a3078302b30ull,0x3a3631315f305f74ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3032322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x2e090a3531315f30ull,
0x3209353109636f6cull,0x6873090a30093232ull,0x2509203233732e72ull,0x317225202c373172ull,
0x2020203b31202c37ull,0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c30327225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e74672e7074ull,
0x202c337025092032ull,0x7225202c37317225ull,0x202f2f09203b3032ull,0x622033702540090aull,
0x5f744c2409206172ull,0x20203b3531315f30ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x333209353109636full,0x2e646c090a300938ull,0x662e646572616873ull,0x3037662509203233ull,
0x7261766f635b202cull,0x305f5f65636e6169ull,0x202f2f093b5d302bull,0x20353532323a6469ull,
0x6e61697261766f63ull,0x78302b305f5f6563ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c313766250920ull,0x61697261766f635bull,0x322b305f5f65636eull,0x69202f2f093b5d30ull,
0x6320363532323a64ull,0x636e61697261766full,0x3178302b305f5f65ull,0x68732e646c090a34ull,
0x3233662e64657261ull,0x202c323766250920ull,0x61697261766f635bull,0x382b305f5f65636eull,
0x6469202f2f093b5dull,0x6f6320373532323aull,0x65636e6169726176ull,0x0a3878302b305f5full,
0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c33376625ull,0x636e61697261766full,
0x5d36312b305f5f65ull,0x3a6469202f2f093bull,0x766f632038353232ull,0x5f65636e61697261ull,
0x0a303178302b305full,0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c34376625ull,
0x636e61697261766full,0x5d32312b305f5f65ull,0x3a6469202f2f093bull,0x766f632039353232ull,
0x5f65636e61697261ull,0x090a6378302b305full,0x65726168732e646cull,0x2509203233662e64ull,
0x6f635b202c353766ull,0x65636e6169726176ull,0x093b5d342b305f5full,0x32323a6469202f2full,
0x7261766f63203036ull,0x305f5f65636e6169ull,0x6f6d090a3478302bull,0x2509203631732e76ull,
0x203b30202c326872ull,0x2020202020202020ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c36376625092032ull,0x3030386633663020ull,0x202020203b303030ull,0x6d090a31202f2f09ull,
0x09203233662e766full,0x6630202c37376625ull,0x3030303030386633ull,0x2f2f09202020203bull,
0x2e766f6d090a3120ull,0x3766250920323366ull,0x3866336630202c38ull,0x20203b3030303030ull,
0x0a31202f2f092020ull,0x32315f305f744c24ull,0x6c3c2f2f200a3a31ull,0x6f6f4c203e706f6full,
0x6c2079646f622070ull,0x2c38333220656e69ull,0x676e697473656e20ull,0x203a687470656420ull,
0x6172657469202c31ull,0x38203a736e6f6974ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3537662509ull,0x6e61697261766f63ull,0x5d342b305f5f6563ull,0x2e090a202f2f093bull,
0x3109353109636f6cull,0x756d090a30093735ull,0x2509203233662e6cull,0x376625202c393766ull,
0x3b38376625202c35ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093833320935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c34376625ull,0x636e61697261766full,
0x5d32312b305f5f65ull,0x2e090a202f2f093bull,0x3109353109636f6cull,0x756d090a30093735ull,
0x2509203233662e6cull,0x376625202c303866ull,0x3b37376625202c34ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093833320935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x635b202c33376625ull,0x636e61697261766full,0x5d36312b305f5f65ull,0x2e090a202f2f093bull,
0x3109353109636f6cull,0x756d090a30093735ull,0x2509203233662e6cull,0x376625202c313866ull,
0x3b36376625202c33ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093833320935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c32376625ull,0x636e61697261766full,
0x3b5d382b305f5f65ull,0x6c2e090a202f2f09ull,0x353109353109636full,0x6c756d090a300937ull,
0x662509203233662eull,0x32376625202c3238ull,0x203b38376625202cull,0x0a202f2f09202020ull,
0x3233662e6c756d09ull,0x202c333866250920ull,0x6625202c33376625ull,0x09202020203b3737ull,
0x6f6c2e090a202f2full,0x3833320935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x2c31376625092032ull,0x697261766f635b20ull,0x2b305f5f65636e61ull,0x202f2f093b5d3032ull,
0x3109636f6c2e090aull,0x0a30093735310935ull,0x3233662e6c756d09ull,0x202c343866250920ull,
0x6625202c31376625ull,0x09202020203b3637ull,0x6f6c2e090a202f2full,0x3833320935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c30376625092032ull,0x697261766f635b20ull,
0x2b305f5f65636e61ull,0x0a202f2f093b5d30ull,0x353109636f6c2e09ull,0x090a300937353109ull,
0x203233662e6c756dull,0x25202c3538662509ull,0x376625202c303766ull,0x2f09202020203b38ull,
0x2e6c756d090a202full,0x3866250920323366ull,0x2c35376625202c36ull,0x20203b3737662520ull,
0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3738662509ull,0x376625202c323766ull,
0x2f09202020203b36ull,0x2e646461090a202full,0x3866250920323366ull,0x2c39376625202c38ull,
0x20203b3038662520ull,0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3938662509ull,
0x386625202c323866ull,0x2f09202020203b33ull,0x2e646461090a202full,0x3966250920323366ull,
0x2c35386625202c30ull,0x20203b3638662520ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x25202c3139662509ull,0x386625202c313866ull,0x2f09202020203b38ull,0x2e646461090a202full,
0x3966250920323366ull,0x2c34386625202c32ull,0x20203b3938662520ull,0x090a202f2f092020ull,
0x203233662e646461ull,0x25202c3339662509ull,0x396625202c373866ull,0x2f09202020203b30ull,
0x2e78616d090a202full,0x3966250920323366ull,0x2c31396625202c34ull,0x20203b3339662520ull,
0x090a202f2f092020ull,0x203233662e78616dull,0x25202c3539662509ull,0x396625202c323966ull,
0x2f09202020203b34ull,0x2e706372090a202full,0x3966250920323366ull,0x3b35396625202c36ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3739662509ull,
0x396625202c313966ull,0x2f09202020203b36ull,0x2e6c756d090a202full,0x3966250920323366ull,
0x2c32396625202c38ull,0x20203b3639662520ull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3837662509ull,0x396625202c333966ull,0x2f09202020203b36ull,0x2e766f6d090a202full,
0x3766250920323366ull,0x3b37396625202c37ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x25202c3637662509ull,0x202020203b383966ull,0x2f09202020202020ull,
0x2e646461090a202full,0x6872250920363173ull,0x2c32687225202c32ull,0x20202020203b3120ull,
0x090a202f2f092020ull,0x203631752e766f6dull,0x38202c3368722509ull,0x202020202020203bull,
0x2f09202020202020ull,0x70746573090a202full,0x203631732e656e2eull,0x7225202c34702509ull,
0x33687225202c3268ull,0x090a202f2f09203bull,0x6172622034702540ull,0x5f305f744c240920ull,
0x202020203b313231ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0938333209353109ull,
0x752e766f6d090a30ull,0x3364722509203436ull,0x6475635f5f202c31ull,0x3173666572785f61ull,
0x202f2f093b323537ull,0x3109636f6c2e090aull,0x0a30093336310936ull,0x3233662e6c756d09ull,
0x202c393966250920ull,0x376625202c336625ull,0x0920202020203b38ull,0x6c756d090a202f2full,
0x662509203233662eull,0x396625202c303031ull,0x203b366625202c37ull,0x0a202f2f09202020ull,
0x3233662e6c756d09ull,0x2c31303166250920ull,0x6625202c39662520ull,0x09202020203b3839ull,
0x646461090a202f2full,0x662509203233662eull,0x396625202c323031ull,0x3030316625202c39ull,
0x0a202f2f0920203bull,0x3233662e64646109ull,0x2c33303166250920ull,0x202c313031662520ull,
0x09203b3230316625ull,0x766f6d090a202f2full,0x722509203436752eull,0x737064202c323364ull,
0x202020203b335f5full,0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c33336472250920ull,
0x25202c3264722520ull,0x0920203b32336472ull,0x2e7473090a202f2full,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3333ull,0x2f2f093b33303166ull,0x313433323a646920ull,
0x2b335f5f73706420ull,0x6f6c2e090a307830ull,0x3831310936310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x3430316625092032ull,0x5f5f7370645b202cull,0x2f093b5d30342b33ull,
0x3433323a6469202full,0x335f5f7370642033ull,0x746c2e746573090aull,0x3233662e3233752eull,
0x202c313272250920ull,0x25202c3430316625ull,0x2f2f093b33303166ull,0x732e67656e090a20ull,
0x3232722509203233ull,0x203b31327225202cull,0x2020202020202020ull,0x6c090a202f2f0920ull,
0x6465726168732e64ull,0x662509203233662eull,0x70645b202c353031ull,0x5d34342b335f5f73ull,
0x3a6469202f2f093bull,0x7370642032343332ull,0x746573090a335f5full,0x2e3233752e746c2eull,
0x3272250920323366ull,0x3530316625202c33ull,0x3b3330316625202cull,0x656e090a202f2f09ull,
0x2509203233732e67ull,0x327225202c343272ull,0x2020202020203b33ull,0x202f2f0920202020ull,
0x33732e646461090aull,0x2c35327225092032ull,0x25202c3232722520ull,0x202020203b343272ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3166250920323366ull,0x7370645b202c3630ull,
0x3b5d32332b335f5full,0x323a6469202f2f09ull,0x5f73706420353433ull,0x2e746573090a335full,
0x662e3233752e746cull,0x3632722509203233ull,0x2c3630316625202cull,0x093b333031662520ull,
0x67656e090a202f2full,0x722509203233732eull,0x36327225202c3732ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3730316625ull,
0x332b335f5f737064ull,0x69202f2f093b5d36ull,0x6420343433323a64ull,0x73090a335f5f7370ull,
0x33752e746c2e7465ull,0x2509203233662e32ull,0x316625202c383272ull,0x30316625202c3730ull,
0x090a202f2f093b33ull,0x203233732e67656eull,0x25202c3932722509ull,0x202020203b383272ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3372250920323373ull,0x2c37327225202c30ull,
0x20203b3932722520ull,0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233662e64ull,
0x645b202c38303166ull,0x34322b335f5f7370ull,0x6469202f2f093b5dull,0x706420373433323aull,
0x6573090a335f5f73ull,0x3233752e746c2e74ull,0x722509203233662eull,0x30316625202c3133ull,
0x3330316625202c38ull,0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c32337225ull,
0x20202020203b3133ull,0x2f2f092020202020ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x2c39303166250920ull,0x335f5f7370645b20ull,0x2f2f093b5d38322bull,0x363433323a646920ull,
0x0a335f5f73706420ull,0x2e746c2e74657309ull,0x203233662e323375ull,0x25202c3333722509ull,
0x6625202c39303166ull,0x202f2f093b333031ull,0x33732e67656e090aull,0x2c34337225092032ull,
0x20203b3333722520ull,0x2020202020202020ull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x337225202c353372ull,0x3b34337225202c32ull,0x202f2f0920202020ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c303131662509ull,0x2b335f5f7370645bull,0x202f2f093b5d3631ull,
0x20393433323a6469ull,0x090a335f5f737064ull,0x752e746c2e746573ull,0x09203233662e3233ull,
0x6625202c36337225ull,0x316625202c303131ull,0x0a202f2f093b3330ull,0x3233732e67656e09ull,
0x202c373372250920ull,0x2020203b36337225ull,0x0920202020202020ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3131662509203233ull,0x5f7370645b202c31ull,0x093b5d30322b335full,
0x33323a6469202f2full,0x5f5f737064203834ull,0x6c2e746573090a33ull,0x33662e3233752e74ull,
0x2c38337225092032ull,0x202c313131662520ull,0x2f093b3330316625ull,0x2e67656e090a202full,
0x3372250920323373ull,0x3b38337225202c39ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233732e646461ull,0x25202c3034722509ull,0x337225202c373372ull,0x2f09202020203b39ull,
0x732e646c090a202full,0x33662e6465726168ull,0x3231316625092032ull,0x5f5f7370645b202cull,
0x2f2f093b5d302b33ull,0x323533323a646920ull,0x0a335f5f73706420ull,0x2e746c2e74657309ull,
0x203233662e323375ull,0x25202c3134722509ull,0x6625202c32313166ull,0x202f2f093b333031ull,
0x33732e67656e090aull,0x2c32347225092032ull,0x20203b3134722520ull,0x2020202020202020ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3166250920323366ull,0x7370645b202c3331ull,
0x093b5d342b335f5full,0x33323a6469202f2full,0x5f5f737064203335ull,0x6c2e746573090a33ull,
0x33662e3233752e74ull,0x2c33347225092032ull,0x202c333131662520ull,0x2f093b3330316625ull,
0x2e67656e090a202full,0x3472250920323373ull,0x3b33347225202c34ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3534722509ull,0x347225202c323472ull,
0x2f09202020203b34ull,0x732e646c090a202full,0x33662e6465726168ull,0x3431316625092032ull,
0x5f5f7370645b202cull,0x2f2f093b5d382b33ull,0x313533323a646920ull,0x0a335f5f73706420ull,
0x2e746c2e74657309ull,0x203233662e323375ull,0x25202c3634722509ull,0x6625202c34313166ull,
0x202f2f093b333031ull,0x33732e67656e090aull,0x2c37347225092032ull,0x20203b3634722520ull,
0x2020202020202020ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3166250920323366ull,
0x7370645b202c3531ull,0x3b5d32312b335f5full,0x323a6469202f2f09ull,0x5f73706420303533ull,
0x2e746573090a335full,0x662e3233752e746cull,0x3834722509203233ull,0x2c3531316625202cull,
0x093b333031662520ull,0x67656e090a202f2full,0x722509203233732eull,0x38347225202c3934ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c303572250920ull,
0x7225202c37347225ull,0x09202020203b3934ull,0x646461090a202f2full,0x722509203233732eull,
0x35347225202c3135ull,0x203b30357225202cull,0x0a202f2f09202020ull,0x3233732e64646109ull,
0x202c323572250920ull,0x7225202c30347225ull,0x09202020203b3135ull,0x646461090a202f2full,
0x722509203233732eull,0x35337225202c3335ull,0x203b32357225202cull,0x0a202f2f09202020ull,
0x3233732e64646109ull,0x202c343572250920ull,0x7225202c30337225ull,0x09202020203b3335ull,
0x646461090a202f2full,0x722509203233732eull,0x35327225202c3535ull,0x203b34357225202cull,
0x0a202f2f09202020ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3631316625ull,
0x342b335f5f737064ull,0x69202f2f093b5d38ull,0x6420343533323a64ull,0x73090a335f5f7370ull,
0x33752e746c2e7465ull,0x2509203233662e32ull,0x316625202c363572ull,0x30316625202c3631ull,
0x090a202f2f093b33ull,0x203233732e67656eull,0x25202c3735722509ull,0x202020203b363572ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3572250920323373ull,0x2c35357225202c35ull,
0x20203b3735722520ull,0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233662e64ull,
0x645b202c37313166ull,0x32352b335f5f7370ull,0x6469202f2f093b5dull,0x706420353533323aull,
0x6573090a335f5f73ull,0x3233752e746c2e74ull,0x722509203233662eull,0x31316625202c3835ull,
0x3330316625202c37ull,0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c39357225ull,
0x20202020203b3835ull,0x2f2f092020202020ull,0x732e646461090a20ull,0x3535722509203233ull,
0x202c35357225202cull,0x2020203b39357225ull,0x6c090a202f2f0920ull,0x6465726168732e64ull,
0x662509203233662eull,0x70645b202c383131ull,0x5d36352b335f5f73ull,0x3a6469202f2f093bull,
0x7370642036353332ull,0x746573090a335f5full,0x2e3233752e746c2eull,0x3672250920323366ull,
0x3831316625202c30ull,0x3b3330316625202cull,0x656e090a202f2f09ull,0x2509203233732e67ull,
0x367225202c313672ull,0x2020202020203b30ull,0x202f2f0920202020ull,0x33732e646461090aull,
0x2c35357225092032ull,0x25202c3535722520ull,0x202020203b313672ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3166250920323366ull,0x7370645b202c3931ull,0x3b5d30362b335f5full,
0x323a6469202f2f09ull,0x5f73706420373533ull,0x2e746573090a335full,0x662e3233752e746cull,
0x3236722509203233ull,0x2c3931316625202cull,0x093b333031662520ull,0x67656e090a202f2full,
0x722509203233732eull,0x32367225202c3336ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233732e64646109ull,0x202c343672250920ull,0x7225202c35357225ull,0x09202020203b3336ull,
0x6f6c2e090a202f2full,0x3132310936310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x32647225202c3433ull,0x3b3133647225202cull,0x090a202f2f092020ull,0x203233732e766f6dull,
0x25202c3536722509ull,0x202020203b343672ull,0x2f09202020202020ull,0x732e7473090a202full,
0x33732e6465726168ull,0x336472255b092032ull,0x7225202c5d302b34ull,0x69202f2f093b3436ull,
0x5f20383533323a64ull,0x72785f616475635full,0x2b32353731736665ull,0x766f6d090a307830ull,
0x722509203233732eull,0x20203b30202c3636ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x32315f305f744c24ull,0x6c3c2f2f200a3a35ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,
0x2c31323120656e69ull,0x676e697473656e20ull,0x203a687470656420ull,0x6172657469202c31ull,
0x31203a736e6f6974ull,0x09636f6c2e090a35ull,0x3009373231093631ull,0x672e70746573090aull,
0x2509203233732e65ull,0x36367225202c3570ull,0x20203b317225202cull,0x2540090a202f2f09ull,
0x0920617262203570ull,0x38315f305f744c24ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3132312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x63090a3532315f30ull,
0x732e3436752e7476ull,0x3364722509203233ull,0x3b36367225202c35ull,0x2f2f092020202020ull,
0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c36336472ull,0x203b34202c353364ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3733647225ull,0x7225202c31336472ull,
0x2f2f09203b363364ull,0x68732e646c090a20ull,0x3233732e64657261ull,0x202c373672250920ull,
0x302b37336472255bull,0x6469202f2f093b5dull,0x5f5f20393533323aull,0x6572785f61647563ull,
0x302b323537317366ull,0x70746573090a3078ull,0x203233732e656e2eull,0x7225202c36702509ull,
0x35367225202c3736ull,0x090a202f2f09203bull,0x6172622036702540ull,0x5f305f744c240920ull,
0x202020203b313831ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c31323120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3532315f305f74ull,0x3233732e64646109ull,0x202c353672250920ull,
0x3b31202c35367225ull,0x0920202020202020ull,0x2e7473090a202f2full,0x732e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3433ull,0x202f2f093b353672ull,0x20303633323a6469ull,
0x785f616475635f5full,0x3235373173666572ull,0x744c240a3078302bull,0x0a3a3138315f305full,
0x3930315f305f4c24ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c31323120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x090a3532315f305full,0x203233732e646461ull,0x25202c3636722509ull,0x203b31202c363672ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3672250920323375ull,0x20203b3531202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x2e656e2e70746573ull,0x3770250920323373ull,
0x202c36367225202cull,0x2f09203b38367225ull,0x37702540090a202full,0x4c24092061726220ull,
0x3b3532315f305f74ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09363109636f6c2eull,
0x63090a3009373731ull,0x732e3436752e7476ull,0x3364722509203233ull,0x3b35367225202c38ull,
0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c39336472ull,
0x3b3231202c383364ull,0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3034647225ull,
0x647225202c336472ull,0x2f2f0920203b3933ull,0x68732e7473090a20ull,0x3233662e64657261ull,
0x30346472255b0920ull,0x336625202c5d302bull,0x3a6469202f2f093bull,0x635f5f2031363332ull,
0x6f6c6f635f616475ull,0x302b383633317372ull,0x732e7473090a3078ull,0x33662e6465726168ull,
0x346472255b092032ull,0x6625202c5d342b30ull,0x6469202f2f093b36ull,0x5f5f20323633323aull,
0x6c6f635f61647563ull,0x2b3836333173726full,0x2e7473090a307830ull,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d382b3034ull,0x69202f2f093b3966ull,0x5f20333633323a64ull,
0x6f635f616475635full,0x3836333173726f6cull,0x744c240a3078302bull,0x0a3a3131315f305full,
0x363109636f6c2e09ull,0x090a300936313509ull,0x203436752e766f6dull,0x5f202c3364722509ull,
0x6f635f616475635full,0x3836333173726f6cull,0x2e090a202f2f093bull,0x3509363109636f6cull,
0x6162090a30093831ull,0x0920636e79732e72ull,0x2020202020203b30ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093532350936ull,0x3233732e766f6d09ull,
0x202c393672250920ull,0x2020202020203b30ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x662509203233662eull,0x376630202c303231ull,0x3b66666666663766ull,0x33202f2f09202020ull,
0x2b6532383230342eull,0x2e766f6d090a3833ull,0x6472250920343675ull,0x646f7270202c3134ull,
0x20202020203b3473ull,0x090a202f2f092020ull,0x203436752e766f6dull,0x202c323464722509ull,
0x6261546168706c61ull,0x2f0920203b34656cull,0x2e766f6d090a202full,0x6472250920343675ull,
0x65705f73202c3334ull,0x6f69746174756d72ull,0x2f093b325f5f736eull,0x305f744c240a202full,
0x2f200a3a3932315full,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3520656e696c2079ull,
0x7473656e202c3532ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x090a3631203a736eull,0x203233732e646461ull,0x25202c3037722509ull,
0x317225202c393672ull,0x2f0920202020203bull,0x2e766f6d090a202full,0x3772250920323375ull,
0x203b313939202c31ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e656c2e70746573ull,
0x3870250920323373ull,0x202c30377225202cull,0x2f09203b31377225ull,0x38702540090a202full,
0x4c24092061726220ull,0x3b3033315f305f74ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x315f305f744c2409ull,0x202020202020203bull,0x2f09202020202020ull,
0x305f744c240a202full,0x2f200a3a3033315full,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3520656e696c2079ull,0x64616568202c3532ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x636f6c2e090a3932ull,0x0937343309363109ull,0x752e747663090a30ull,
0x09203233732e3436ull,0x25202c3434647225ull,0x202020203b303772ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3534647225092034ull,0x2c3434647225202cull,0x2f2f0920203b3420ull,
0x61702e646c090a20ull,0x203436752e6d6172ull,0x202c363464722509ull,0x70616475635f5f5bull,
0x63385a5f5f6d7261ull,0x5073736572706d6full,0x7535505f30536a4bull,0x7265705f32746e69ull,
0x6e6f69746174756dull,0x69202f2f093b5d73ull,0x5f20343633323a64ull,0x726170616475635full,
0x6d6f63385a5f5f6dull,0x6a4b507373657270ull,0x6e697535505f3053ull,0x756d7265705f3274ull,
0x2b736e6f69746174ull,0x646461090a307830ull,0x722509203436752eull,0x647225202c373464ull,
0x34647225202c3634ull,0x0a202f2f09203b35ull,0x626f6c672e646c09ull,0x09203233752e6c61ull,
0x255b202c32377225ull,0x3b5d302b37346472ull,0x323a6469202f2f09ull,0x766f6d090a353633ull,
0x722509203233752eull,0x3b393531202c3337ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x74672e7074657309ull,0x702509203233732eull,0x2c30377225202c39ull,0x09203b3337722520ull,
0x702540090a202f2full,0x2409206172622039ull,0x3233315f305f744cull,0x202020202020203bull,
0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c35323520ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x6c2e090a3932315full,0x343309363109636full,0x646461090a300938ull,0x722509203436752eull,
0x647225202c383464ull,0x34647225202c3534ull,0x0a202f2f09203b33ull,0x726168732e747309ull,
0x09203233752e6465ull,0x302b38346472255bull,0x3b32377225202c5dull,0x323a6469202f2f09ull,
0x65705f7320363633ull,0x6f69746174756d72ull,0x78302b325f5f736eull,0x5f305f744c240a30ull,
0x2f2f200a3a323331ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x323520656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,0x32315f305f744c24ull,
0x09636f6c2e090a39ull,0x3009303533093631ull,0x33732e766f6d090aull,0x2c34377225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203436732e76ull,
0x7225202c39346472ull,0x20202020203b3364ull,0x202f2f0920202020ull,0x33732e766f6d090aull,
0x2c35377225092032ull,0x20202020203b3020ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x6630202c31323166ull,0x3030303030303030ull,0x202f2f092020203bull,
0x662e766f6d090a30ull,0x3231662509203233ull,0x3030306630202c32ull,0x20203b3030303030ull,
0x090a30202f2f0920ull,0x203233662e766f6dull,0x202c333231662509ull,0x3030303030306630ull,
0x2f092020203b3030ull,0x5f744c240a30202full,0x200a3a3633315f30ull,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c303533ull,0x70656420676e6974ull,
0x69202c32203a6874ull,0x6e6f697461726574ull,0x2e090a3631203a73ull,0x3209363109636f6cull,
0x6873090a30093332ull,0x2509203233752e72ull,0x377225202c363772ull,0x3b34377225202c32ull,
0x202f2f0920202020ull,0x33622e646e61090aull,0x2c37377225092032ull,0x33202c3637722520ull,
0x202020202020203bull,0x7663090a202f2f09ull,0x33752e3436752e74ull,0x3035647225092032ull,
0x203b37377225202cull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c313564ull,0x20203b34202c3035ull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x7225202c32356472ull,0x647225202c313564ull,0x202f2f09203b3234ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x5b202c3432316625ull,0x5d302b3235647225ull,0x3a6469202f2f093bull,
0x706c612037363332ull,0x34656c6261546168ull,0x646c090a3078302bull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3532ull,0x2f093b5d302b3934ull,0x3633323a6469202full,
0x616475635f5f2038ull,0x3173726f6c6f635full,0x0a3078302b383633ull,0x3233662e64616d09ull,
0x2c33323166250920ull,0x202c343231662520ull,0x25202c3532316625ull,0x2f2f093b33323166ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c36323166250920ull,0x2b39346472255b20ull,
0x69202f2f093b5d34ull,0x5f20393633323a64ull,0x6f635f616475635full,0x3836333173726f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x6625202c32323166ull,0x316625202c343231ull,
0x32316625202c3632ull,0x090a202f2f093b32ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c37323166ull,0x3b5d382b39346472ull,0x323a6469202f2f09ull,0x75635f5f20303733ull,
0x726f6c6f635f6164ull,0x78302b3836333173ull,0x662e64616d090a30ull,0x3231662509203233ull,
0x3432316625202c31ull,0x2c3732316625202cull,0x093b313231662520ull,0x6f6c2e090a202f2full,
0x3432320936310963ull,0x2e646461090a3009ull,0x6472250920343675ull,0x35647225202c3335ull,
0x3134647225202c31ull,0x090a202f2f09203bull,0x74736e6f632e646cull,0x722509203233732eull,
0x6472255b202c3837ull,0x2f093b5d302b3335ull,0x3733323a6469202full,0x3473646f72702031ull,
0x6461090a3078302bull,0x2509203233732e64ull,0x377225202c353772ull,0x3b35377225202c38ull,
0x202f2f0920202020ull,0x36752e646461090aull,0x3934647225092034ull,0x2c3934647225202cull,
0x202020203b323120ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x377225202c343772ull,
0x2020203b32202c34ull,0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c39377225092032ull,
0x202020203b323320ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e656e2e7074ull,
0x2c30317025092032ull,0x25202c3437722520ull,0x202f2f093b393772ull,0x203031702540090aull,
0x744c240920617262ull,0x203b3633315f305full,0x2020202020202020ull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x323520656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x32315f305f744c24ull,0x09636f6c2e090a39ull,
0x3009323632093631ull,0x33732e726873090aull,0x2c30387225092032ull,0x31202c3537722520ull,
0x2020202020203b36ull,0x6873090a202f2f09ull,0x2509203233732e72ull,0x377225202c313872ull,
0x2020203b38202c35ull,0x202f2f0920202020ull,0x33622e646e61090aull,0x2c32387225092032ull,
0x32202c3537722520ull,0x20202020203b3535ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3832ull,0x736d75735f616475ull,0x3b5d302b30363531ull,
0x323a6469202f2f09ull,0x75635f5f20343133ull,0x31736d75735f6164ull,0x0a3078302b303635ull,
0x3233662e766f6d09ull,0x2c39323166250920ull,0x3030313134663020ull,0x092020203b303030ull,
0x756d090a39202f2full,0x2509203233662e6cull,0x6625202c30333166ull,0x316625202c383231ull,
0x202f2f09203b3932ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c313331662509ull,
0x5f616475635f5f5bull,0x30363531736d7573ull,0x202f2f093b5d342bull,0x20363133323a6469ull,
0x735f616475635f5full,0x2b30363531736d75ull,0x766f6d090a347830ull,0x662509203233662eull,
0x346630202c323331ull,0x3b30303030303131ull,0x39202f2f09202020ull,0x33662e6c756d090aull,
0x3333316625092032ull,0x2c3133316625202cull,0x203b323331662520ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3433ull,0x736d75735f616475ull,
0x3b5d382b30363531ull,0x323a6469202f2f09ull,0x75635f5f20383133ull,0x31736d75735f6164ull,
0x0a3878302b303635ull,0x3233662e766f6d09ull,0x2c35333166250920ull,0x3030313134663020ull,
0x092020203b303030ull,0x756d090a39202f2full,0x2509203233662e6cull,0x6625202c36333166ull,
0x316625202c343331ull,0x202f2f09203b3533ull,0x6e722e747663090aull,0x3233732e3233662eull,
0x2c37333166250920ull,0x20203b3038722520ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,
0x387225202c333872ull,0x203b353532202c31ull,0x202f2f0920202020ull,0x6e722e747663090aull,
0x3233732e3233662eull,0x2c38333166250920ull,0x20203b3238722520ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x6625202c39333166ull,0x316625202c303331ull,0x202f2f09203b3332ull,
0x33662e627573090aull,0x3034316625092032ull,0x2c3333316625202cull,0x203b323231662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c31343166ull,0x316625202c363331ull,
0x202f2f09203b3132ull,0x6e722e747663090aull,0x3233732e3233662eull,0x2c32343166250920ull,
0x20203b3338722520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c33343166ull,
0x316625202c383331ull,0x202f2f09203b3833ull,0x33662e6c756d090aull,0x3434316625092032ull,
0x2c3833316625202cull,0x203b393331662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c35343166ull,0x316625202c383331ull,0x202f2f09203b3034ull,0x33662e6c756d090aull,
0x3634316625092032ull,0x2c3833316625202cull,0x203b313431662520ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c37343166ull,0x316625202c373331ull,0x202f2f09203b3234ull,
0x33662e6c756d090aull,0x3834316625092032ull,0x2c3234316625202cull,0x203b333231662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c39343166ull,0x316625202c323431ull,
0x202f2f09203b3232ull,0x33662e6c756d090aull,0x3035316625092032ull,0x2c3234316625202cull,
0x203b313231662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c31353166ull,
0x316625202c373431ull,0x202f2f09203b3334ull,0x33662e627573090aull,0x3235316625092032ull,
0x2c3834316625202cull,0x203b343431662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,
0x6625202c33353166ull,0x316625202c393431ull,0x202f2f09203b3534ull,0x33662e627573090aull,
0x3435316625092032ull,0x2c3035316625202cull,0x203b363431662520ull,0x6372090a202f2f09ull,
0x2509203233662e70ull,0x6625202c35353166ull,0x202020203b313531ull,0x202f2f0920202020ull,
0x33662e6c756d090aull,0x3635316625092032ull,0x2c3235316625202cull,0x203b353531662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c37353166ull,0x316625202c333531ull,
0x202f2f09203b3535ull,0x33662e6c756d090aull,0x3835316625092032ull,0x2c3435316625202cull,
0x203b353531662520ull,0x7663090a202f2f09ull,0x33662e7461732e74ull,0x2509203233662e32ull,
0x6625202c39353166ull,0x202f2f093b363531ull,0x61732e747663090aull,0x33662e3233662e74ull,
0x3036316625092032ull,0x3b3735316625202cull,0x7663090a202f2f09ull,0x33662e7461732e74ull,
0x2509203233662e32ull,0x6625202c31363166ull,0x202f2f093b383531ull,0x33662e766f6d090aull,
0x3236316625092032ull,0x386631346630202cull,0x2020203b30303030ull,0x090a3133202f2f09ull,
0x203233662e6c756dull,0x202c333631662509ull,0x25202c3935316625ull,0x2f09203b32363166ull,
0x2e766f6d090a202full,0x3166250920323366ull,0x32346630202c3436ull,0x203b303030306337ull,
0x3336202f2f092020ull,0x33662e6c756d090aull,0x3536316625092032ull,0x2c3036316625202cull,
0x203b343631662520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c36363166ull,
0x3030303038663134ull,0x202f2f092020203bull,0x2e6c756d090a3133ull,0x3166250920323366ull,
0x36316625202c3736ull,0x3636316625202c31ull,0x090a202f2f09203bull,0x2e696e722e747663ull,
0x203233662e323366ull,0x202c383631662509ull,0x2f093b3336316625ull,0x2e747663090a202full,
0x2e3233662e696e72ull,0x3166250920323366ull,0x36316625202c3936ull,0x090a202f2f093b35ull,
0x2e696e722e747663ull,0x203233662e323366ull,0x202c303731662509ull,0x2f093b3736316625ull,
0x2e747663090a202full,0x2e3233752e697a72ull,0x3872250920323366ull,0x3836316625202c34ull,
0x090a202f2f09203bull,0x203233622e6c6873ull,0x25202c3538722509ull,0x3b3131202c343872ull,
0x2f09202020202020ull,0x2e747663090a202full,0x2e3233752e697a72ull,0x3872250920323366ull,
0x3936316625202c36ull,0x090a202f2f09203bull,0x203233622e6c6873ull,0x25202c3738722509ull,
0x203b35202c363872ull,0x2f09202020202020ull,0x622e726f090a202full,0x3838722509203233ull,
0x202c35387225202cull,0x2020203b37387225ull,0x090a202f2f092020ull,0x2e697a722e747663ull,
0x203233662e323375ull,0x25202c3938722509ull,0x2f09203b30373166ull,0x622e726f090a202full,
0x3039722509203233ull,0x202c38387225202cull,0x2020203b39387225ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x202c313731662509ull,0x3533343064336630ull,0x2f092020203b3137ull,
0x323233302e30202full,0x6c756d090a353737ull,0x662509203233662eull,0x316625202c323731ull,
0x37316625202c3836ull,0x0a202f2f09203b31ull,0x363109636f6c2e09ull,0x090a300933363209ull,
0x203233662e6c756dull,0x202c333731662509ull,0x25202c3833316625ull,0x2f09203b33323166ull,
0x2e6c756d090a202full,0x3166250920323366ull,0x33316625202c3437ull,0x3232316625202c38ull,
0x090a202f2f09203bull,0x203233662e6c756dull,0x202c353731662509ull,0x25202c3833316625ull,
0x2f09203b31323166ull,0x2e6c756d090a202full,0x3166250920323366ull,0x33316625202c3637ull,
0x3933316625202c37ull,0x090a202f2f09203bull,0x203233662e6c756dull,0x202c373731662509ull,
0x25202c3733316625ull,0x2f09203b30343166ull,0x2e6c756d090a202full,0x3166250920323366ull,
0x33316625202c3837ull,0x3134316625202c37ull,0x090a202f2f09203bull,0x203233662e627573ull,
0x202c393731662509ull,0x25202c3637316625ull,0x2f09203b33373166ull,0x2e627573090a202full,
0x3166250920323366ull,0x37316625202c3038ull,0x3437316625202c37ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c313831662509ull,0x25202c3837316625ull,0x2f09203b35373166ull,
0x2e6c756d090a202full,0x3166250920323366ull,0x37316625202c3238ull,0x3535316625202c39ull,
0x090a202f2f09203bull,0x203233662e6c756dull,0x202c333831662509ull,0x25202c3038316625ull,
0x2f09203b35353166ull,0x2e6c756d090a202full,0x3166250920323366ull,0x38316625202c3438ull,
0x3535316625202c31ull,0x090a202f2f09203bull,0x2e7461732e747663ull,0x203233662e323366ull,
0x202c353831662509ull,0x2f093b3238316625ull,0x2e747663090a202full,0x2e3233662e746173ull,
0x3166250920323366ull,0x38316625202c3638ull,0x090a202f2f093b33ull,0x2e7461732e747663ull,
0x203233662e323366ull,0x202c373831662509ull,0x2f093b3438316625ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x31346630202c3838ull,0x203b303030303866ull,0x3133202f2f092020ull,
0x33662e6c756d090aull,0x3938316625092032ull,0x2c3538316625202cull,0x203b383831662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c30393166ull,0x3030303063373234ull,
0x202f2f092020203bull,0x2e6c756d090a3336ull,0x3166250920323366ull,0x38316625202c3139ull,
0x3039316625202c36ull,0x090a202f2f09203bull,0x203233662e766f6dull,0x202c323931662509ull,
0x3030386631346630ull,0x2f092020203b3030ull,0x756d090a3133202full,0x2509203233662e6cull,
0x6625202c33393166ull,0x316625202c373831ull,0x202f2f09203b3239ull,0x6e722e747663090aull,
0x33662e3233662e69ull,0x3439316625092032ull,0x3b3938316625202cull,0x7663090a202f2f09ull,
0x33662e696e722e74ull,0x2509203233662e32ull,0x6625202c35393166ull,0x202f2f093b313931ull,
0x6e722e747663090aull,0x33662e3233662e69ull,0x3639316625092032ull,0x3b3339316625202cull,
0x7663090a202f2f09ull,0x33752e697a722e74ull,0x2509203233662e32ull,0x316625202c313972ull,
0x202f2f09203b3439ull,0x33622e6c6873090aull,0x2c32397225092032ull,0x31202c3139722520ull,
0x2020202020203b31ull,0x7663090a202f2f09ull,0x33752e697a722e74ull,0x2509203233662e32ull,
0x316625202c333972ull,0x202f2f09203b3539ull,0x33622e6c6873090aull,0x2c34397225092032ull,
0x35202c3339722520ull,0x202020202020203bull,0x726f090a202f2f09ull,0x722509203233622eull,
0x32397225202c3539ull,0x203b34397225202cull,0x202f2f0920202020ull,0x7a722e747663090aull,
0x33662e3233752e69ull,0x2c36397225092032ull,0x203b363931662520ull,0x726f090a202f2f09ull,
0x722509203233622eull,0x35397225202c3739ull,0x203b36397225202cull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x3739316625092032ull,0x343064336630202cull,0x2020203b31373533ull,
0x33302e30202f2f09ull,0x6d090a3537373232ull,0x09203233662e6c75ull,0x25202c3839316625ull,
0x6625202c34393166ull,0x2f2f09203b373931ull,0x09636f6c2e090a20ull,0x3009303533093631ull,
0x33662e6c756d090aull,0x3939316625092032ull,0x2c3237316625202cull,0x203b323731662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c30303266ull,0x316625202c323731ull,
0x202f2f09203b3332ull,0x33662e6c756d090aull,0x3130326625092032ull,0x2c3939316625202cull,
0x203b373331662520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c32303266ull,
0x3931316231386333ull,0x202f2f092020203bull,0x3133383531302e30ull,0x662e6c756d090a35ull,
0x3032662509203233ull,0x3936316625202c33ull,0x3b3230326625202cull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3430326625ull,0x3735333430643366ull,0x2f2f092020203b31ull,
0x37323233302e3020ull,0x2e6c756d090a3537ull,0x3266250920323366ull,0x37316625202c3530ull,
0x3430326625202c30ull,0x090a202f2f09203bull,0x203233662e766f6dull,0x202c363032662509ull,
0x3162313863336630ull,0x2f092020203b3931ull,0x383531302e30202full,0x6c756d090a353133ull,
0x662509203233662eull,0x316625202c373032ull,0x30326625202c3539ull,0x0a202f2f09203b36ull,
0x3233662e766f6d09ull,0x2c38303266250920ull,0x3334306433663020ull,0x092020203b313735ull,
0x3233302e30202f2full,0x756d090a35373732ull,0x2509203233662e6cull,0x6625202c39303266ull,
0x326625202c363931ull,0x202f2f09203b3830ull,0x33662e6c756d090aull,0x3031326625092032ull,
0x2c3330326625202cull,0x203b333032662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c31313266ull,0x316625202c333032ull,0x202f2f09203b3232ull,0x33662e6c756d090aull,
0x3231326625092032ull,0x2c3530326625202cull,0x203b353032662520ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c33313266ull,0x316625202c353032ull,0x202f2f09203b3132ull,
0x33662e6c756d090aull,0x3431326625092032ull,0x2c3839316625202cull,0x203b323731662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c35313266ull,0x316625202c393331ull,
0x202f2f09203b3839ull,0x33662e6c756d090aull,0x3631326625092032ull,0x2c3730326625202cull,
0x203b373032662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c37313266ull,
0x326625202c333032ull,0x202f2f09203b3730ull,0x33662e6c756d090aull,0x3831326625092032ull,
0x2c3034316625202cull,0x203b373032662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c39313266ull,0x326625202c393032ull,0x202f2f09203b3930ull,0x33662e6c756d090aull,
0x3032326625092032ull,0x2c3530326625202cull,0x203b393032662520ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c31323266ull,0x326625202c313431ull,0x202f2f09203b3930ull,
0x33662e6c756d090aull,0x3232326625092032ull,0x2c3733316625202cull,0x203b303132662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c33323266ull,0x326625202c373331ull,
0x202f2f09203b3231ull,0x33662e6c756d090aull,0x3432326625092032ull,0x2c3833316625202cull,
0x203b343132662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c35323266ull,
0x326625202c323431ull,0x202f2f09203b3631ull,0x33662e6c756d090aull,0x3632326625092032ull,
0x2c3833316625202cull,0x203b373132662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c37323266ull,0x326625202c323431ull,0x202f2f09203b3931ull,0x33662e6c756d090aull,
0x3832326625092032ull,0x2c3833316625202cull,0x203b303232662520ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x6625202c39323266ull,0x326625202c343232ull,0x202f2f09203b3030ull,
0x33662e646461090aull,0x3033326625092032ull,0x2c3232326625202cull,0x203b353232662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c31333266ull,0x326625202c363232ull,
0x202f2f09203b3131ull,0x33662e646461090aull,0x3233326625092032ull,0x2c3332326625202cull,
0x203b373232662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c33333266ull,
0x326625202c383232ull,0x202f2f09203b3331ull,0x33662e627573090aull,0x3433326625092032ull,
0x2c3932326625202cull,0x203b353132662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,
0x6625202c35333266ull,0x326625202c313332ull,0x202f2f09203b3831ull,0x33662e627573090aull,
0x3633326625092032ull,0x2c3333326625202cull,0x203b313232662520ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x6625202c37333266ull,0x326625202c353332ull,0x202f2f09203b3533ull,
0x33662e646461090aull,0x3833326625092032ull,0x2c3633326625202cull,0x203b363332662520ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c39333266ull,0x326625202c303332ull,
0x202f2f09203b3733ull,0x33662e646461090aull,0x3034326625092032ull,0x2c3233326625202cull,
0x203b383332662520ull,0x646c090a202f2f09ull,0x662e74736e6f632eull,0x3432662509203233ull,
0x6c6f436b5b202c31ull,0x63697274654d726full,0x202f2f093b5d342bull,0x20323733323a6469ull,
0x654d726f6c6f436bull,0x3478302b63697274ull,0x33662e6c756d090aull,0x3234326625092032ull,
0x2c3134326625202cull,0x203b393332662520ull,0x646c090a202f2f09ull,0x662e74736e6f632eull,
0x3432662509203233ull,0x6c6f436b5b202c33ull,0x63697274654d726full,0x202f2f093b5d382bull,
0x20333733323a6469ull,0x654d726f6c6f436bull,0x3878302b63697274ull,0x33662e6c756d090aull,
0x3434326625092032ull,0x2c3334326625202cull,0x203b303432662520ull,0x646c090a202f2f09ull,
0x662e74736e6f632eull,0x3432662509203233ull,0x6c6f436b5b202c35ull,0x63697274654d726full,
0x202f2f093b5d302bull,0x20343733323a6469ull,0x654d726f6c6f436bull,0x3078302b63697274ull,
0x33662e646461090aull,0x3634326625092032ull,0x2c3433326625202cull,0x203b343332662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c37343266ull,0x316625202c383931ull,
0x202f2f09203b3839ull,0x33662e64616d090aull,0x3834326625092032ull,0x2c3234316625202cull,
0x202c373432662520ull,0x2f093b3130326625ull,0x2e646461090a202full,0x3266250920323366ull,
0x34326625202c3934ull,0x3834326625202c36ull,0x090a202f2f09203bull,0x203233662e64616dull,
0x202c303532662509ull,0x25202c3534326625ull,0x6625202c39343266ull,0x202f2f093b323432ull,
0x33662e646461090aull,0x3135326625092032ull,0x2c3434326625202cull,0x203b303532662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c32353266ull,0x3933653833656433ull,
0x202f2f092020203bull,0x3131313131312e30ull,0x33662e6c756d090aull,0x3335326625092032ull,
0x2c3135326625202cull,0x203b323532662520ull,0x6573090a202f2f09ull,0x33662e746c2e7074ull,
0x2c31317025092032ull,0x202c333532662520ull,0x2f093b3032316625ull,0x70252140090a202full,
0x0920617262203131ull,0x33315f305f744c24ull,0x2020202020203b38ull,0x200a202f2f092020ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353235ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x6f6c2e090a393231ull,
0x3435330936310963ull,0x2e766f6d090a3009ull,0x3166250920323366ull,0x35326625202c3032ull,
0x2020202020203b33ull,0x090a202f2f092020ull,0x09363109636f6c2eull,0x6d090a3009353533ull,
0x09203233732e766full,0x7225202c38397225ull,0x20202020203b3237ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009363533093631ull,0x31752e747663090aull,0x2509203233752e36ull,
0x397225202c346872ull,0x2020202020203b30ull,0x6c2e090a202f2f09ull,0x353309363109636full,
0x747663090a300937ull,0x3233752e3631752eull,0x202c356872250920ull,0x2020203b37397225ull,
0x0a202f2f09202020ull,0x33315f305f744c24ull,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35323520656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x0a3932315f305f74ull,0x3233732e64646109ull,0x202c393672250920ull,
0x3436202c39367225ull,0x092020202020203bull,0x766f6d090a202f2full,0x722509203233752eull,
0x34323031202c3939ull,0x202020202020203bull,0x0a202f2f09202020ull,0x656e2e7074657309ull,
0x702509203233732eull,0x39367225202c3231ull,0x093b39397225202cull,0x702540090a202f2full,
0x0920617262203231ull,0x32315f305f744c24ull,0x2020202020203b39ull,0x0a202f2f09202020ull,
0x3a315f305f744c24ull,0x3109636f6c2e090aull,0x0a30093935330936ull,0x3233752e74766309ull,
0x722509203631752eull,0x687225202c303031ull,0x0920202020203b35ull,0x747663090a202f2full,
0x3631752e3233752eull,0x2c31303172250920ull,0x20203b3468722520ull,0x0a202f2f09202020ull,
0x656c2e7074657309ull,0x702509203233752eull,0x30317225202c3331ull,0x3130317225202c30ull,
0x40090a202f2f093bull,0x6172622033317025ull,0x5f305f744c240920ull,0x202020203b313431ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x0a30093237093631ull,0x3233732e766f6d09ull,
0x2c32303172250920ull,0x203b303031722520ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x0933370936310963ull,0x732e766f6d090a30ull,0x3031722509203233ull,0x3130317225202c30ull,
0x202020202020203bull,0x63090a202f2f0920ull,0x752e3631752e7476ull,0x3668722509203233ull,
0x3b3030317225202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x0a30093437093631ull,
0x3233732e766f6d09ull,0x2c31303172250920ull,0x203b323031722520ull,0x0920202020202020ull,
0x747663090a202f2full,0x3233752e3631752eull,0x202c376872250920ull,0x20203b3130317225ull,
0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x090a300934363309ull,0x203233732e766f6dull,
0x202c333031722509ull,0x2020203b38397225ull,0x2f09202020202020ull,0x2e726f78090a202full,
0x3172250920323362ull,0x30317225202c3430ull,0x3631333431202c33ull,0x2f093b3536373535ull,
0x2e766f6d090a202full,0x3972250920323373ull,0x3430317225202c38ull,0x202020202020203bull,
0x240a202f2f092020ull,0x3134315f305f744cull,0x732e766f6d090a3aull,0x3868722509203631ull,
0x202020203b30202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203436752e766full,
0x70202c3435647225ull,0x20203b3373646f72ull,0x2f2f092020202020ull,0x752e766f6d090a20ull,
0x3564722509203436ull,0x6168706c61202c35ull,0x203b33656c626154ull,0x4c240a202f2f0920ull,
0x3a3534315f305f74ull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x6e202c3436332065ull,0x6420676e69747365ull,0x2c31203a68747065ull,0x74616d6974736520ull,
0x6172657469206465ull,0x33203a736e6f6974ull,0x69772e6c756d090aull,0x09203631732e6564ull,
0x25202c3530317225ull,0x3b3436202c386872ull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x7225202c36303172ull,0x317225202c353031ull,0x202f2f092020203bull,0x33752e766f6d090aull,
0x3730317225092032ull,0x20203b393531202cull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33732e656c2e7074ull,0x2c34317025092032ull,0x202c363031722520ull,0x2f093b3730317225ull,
0x31702540090a202full,0x2409206172622034ull,0x3634315f305f744cull,0x202020202020203bull,
0x090a202f2f092020ull,0x20696e752e617262ull,0x325f305f744c2409ull,0x202020202020203bull,
0x2f09202020202020ull,0x305f744c240a202full,0x2f200a3a3634315full,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3436ull,
0x64656c6562616c20ull,0x315f305f744c2420ull,0x636f6c2e090a3534ull,0x0933373309363109ull,
0x752e747663090a30ull,0x09203233732e3436ull,0x25202c3635647225ull,0x2020203b36303172ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3735647225092034ull,0x2c3635647225202cull,
0x2f2f0920203b3420ull,0x752e646461090a20ull,0x3564722509203436ull,0x3334647225202c38ull,
0x3b3735647225202cull,0x6c090a202f2f0920ull,0x6465726168732e64ull,0x722509203233752eull,
0x72255b202c383031ull,0x093b5d302b383564ull,0x33323a6469202f2full,0x7265705f73203537ull,
0x6e6f69746174756dull,0x3078302b325f5f73ull,0x3109636f6c2e090aull,0x0a30093437330936ull,
0x3233732e766f6d09ull,0x2c39303172250920ull,0x20202020203b3020ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x722509203436732eull,0x647225202c393564ull,0x2020202020203b33ull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x2c30313172250920ull,0x20202020203b3020ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x306630202c343532ull,
0x3b30303030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,0x3535326625092032ull,
0x303030306630202cull,0x2020203b30303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,
0x30202c3635326625ull,0x3030303030303066ull,0x2f2f092020203b30ull,0x305f744c240a3020ull,
0x2f200a3a3035315full,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3320656e696c2079ull,
0x7473656e202c3437ull,0x7470656420676e69ull,0x7469202c32203a68ull,0x736e6f6974617265ull,
0x6c2e090a3631203aull,0x373309363109636full,0x2e646c090a300933ull,0x752e646572616873ull,
0x3031722509203233ull,0x356472255b202c38ull,0x2f2f093b5d302b38ull,0x09636f6c2e090a20ull,
0x3009343832093631ull,0x33752e726873090aull,0x3131317225092032ull,0x2c3830317225202cull,
0x203b393031722520ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,0x7225202c32313172ull,
0x203b33202c313131ull,0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233752e34ull,
0x7225202c30366472ull,0x202020203b323131ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,
0x2c31366472250920ull,0x202c303664722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,
0x3236647225092034ull,0x2c3136647225202cull,0x203b353564722520ull,0x646c090a202f2f09ull,
0x662e74736e6f632eull,0x3532662509203233ull,0x366472255b202c37ull,0x2f2f093b5d302b32ull,
0x363733323a646920ull,0x61546168706c6120ull,0x3078302b33656c62ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c383532662509ull,0x302b39356472255bull,0x6469202f2f093b5dull,
0x5f5f20373733323aull,0x6c6f635f61647563ull,0x2b3836333173726full,0x64616d090a307830ull,
0x662509203233662eull,0x326625202c363532ull,0x35326625202c3735ull,0x3635326625202c38ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c393532ull,
0x093b5d342b393564ull,0x33323a6469202f2full,0x6475635f5f203837ull,0x73726f6c6f635f61ull,
0x3078302b38363331ull,0x33662e64616d090aull,0x3535326625092032ull,0x2c3735326625202cull,
0x202c393532662520ull,0x2f093b3535326625ull,0x732e646c090a202full,0x33662e6465726168ull,
0x3036326625092032ull,0x39356472255b202cull,0x202f2f093b5d382bull,0x20393733323a6469ull,
0x635f616475635f5full,0x36333173726f6c6full,0x6d090a3078302b38ull,0x09203233662e6461ull,
0x25202c3435326625ull,0x6625202c37353266ull,0x326625202c303632ull,0x0a202f2f093b3435ull,
0x363109636f6c2e09ull,0x090a300935383209ull,0x203436752e646461ull,0x202c333664722509ull,
0x25202c3136647225ull,0x2f09203b34356472ull,0x632e646c090a202full,0x3233732e74736e6full,
0x2c33313172250920ull,0x2b33366472255b20ull,0x69202f2f093b5d30ull,0x7020303833323a64ull,
0x78302b3373646f72ull,0x732e646461090a30ull,0x3131722509203233ull,0x3331317225202c30ull,
0x3b3031317225202cull,0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3935647225ull,
0x3231202c39356472ull,0x2f2f09202020203bull,0x732e646461090a20ull,0x3031722509203233ull,
0x3930317225202c39ull,0x202020203b32202cull,0x6d090a202f2f0920ull,0x09203233752e766full,
0x33202c3431317225ull,0x2020202020203b32ull,0x2f2f092020202020ull,0x2e70746573090a20ull,
0x09203233732e656eull,0x7225202c35317025ull,0x317225202c393031ull,0x0a202f2f093b3431ull,
0x6220353170254009ull,0x5f744c2409206172ull,0x20203b3035315f30ull,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x34363320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3534315f305f744cull,
0x3109636f6c2e090aull,0x0a30093232330936ull,0x3233732e72687309ull,0x2c35313172250920ull,
0x202c303131722520ull,0x09202020203b3631ull,0x726873090a202f2full,0x722509203233732eull,
0x317225202c363131ull,0x20203b38202c3031ull,0x0a202f2f09202020ull,0x3233622e646e6109ull,
0x2c37313172250920ull,0x202c303131722520ull,0x092020203b353532ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3632662509203233ull,0x75635f5f5b202c31ull,0x31736d75735f6164ull,
0x093b5d302b303635ull,0x33323a6469202f2full,0x6475635f5f203431ull,0x3531736d75735f61ull,
0x090a3078302b3036ull,0x203233662e766f6dull,0x202c323632662509ull,0x3030303830346630ull,
0x2f092020203b3030ull,0x6c756d090a34202full,0x662509203233662eull,0x326625202c333632ull,
0x36326625202c3136ull,0x0a202f2f09203b32ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3436326625ull,0x735f616475635f5full,0x2b30363531736d75ull,0x69202f2f093b5d34ull,
0x5f20363133323a64ull,0x75735f616475635full,0x302b30363531736dull,0x2e766f6d090a3478ull,
0x3266250920323366ull,0x30346630202c3536ull,0x203b303030303038ull,0x0a34202f2f092020ull,
0x3233662e6c756d09ull,0x2c36363266250920ull,0x202c343632662520ull,0x09203b3536326625ull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3632662509203233ull,0x75635f5f5b202c37ull,
0x31736d75735f6164ull,0x093b5d382b303635ull,0x33323a6469202f2full,0x6475635f5f203831ull,
0x3531736d75735f61ull,0x090a3878302b3036ull,0x203233662e766f6dull,0x202c383632662509ull,
0x3030303830346630ull,0x2f092020203b3030ull,0x6c756d090a34202full,0x662509203233662eull,
0x326625202c393632ull,0x36326625202c3736ull,0x0a202f2f09203b38ull,0x2e6e722e74766309ull,
0x203233732e323366ull,0x202c303732662509ull,0x09203b3531317225ull,0x646e61090a202f2full,
0x722509203233622eull,0x317225202c383131ull,0x3b353532202c3631ull,0x0a202f2f09202020ull,
0x2e6e722e74766309ull,0x203233732e323366ull,0x202c313732662509ull,0x09203b3731317225ull,
0x627573090a202f2full,0x662509203233662eull,0x326625202c323732ull,0x35326625202c3336ull,
0x0a202f2f09203b36ull,0x3233662e62757309ull,0x2c33373266250920ull,0x202c363632662520ull,
0x09203b3535326625ull,0x627573090a202f2full,0x662509203233662eull,0x326625202c343732ull,
0x35326625202c3936ull,0x0a202f2f09203b34ull,0x2e6e722e74766309ull,0x203233732e323366ull,
0x202c353732662509ull,0x09203b3831317225ull,0x6c756d090a202f2full,0x662509203233662eull,
0x326625202c363732ull,0x37326625202c3137ull,0x0a202f2f09203b31ull,0x3233662e6c756d09ull,
0x2c37373266250920ull,0x202c313732662520ull,0x09203b3237326625ull,0x6c756d090a202f2full,
0x662509203233662eull,0x326625202c383732ull,0x37326625202c3137ull,0x0a202f2f09203b33ull,
0x3233662e6c756d09ull,0x2c39373266250920ull,0x202c313732662520ull,0x09203b3437326625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x326625202c303832ull,0x37326625202c3037ull,
0x0a202f2f09203b35ull,0x3233662e6c756d09ull,0x2c31383266250920ull,0x202c353732662520ull,
0x09203b3635326625ull,0x6c756d090a202f2full,0x662509203233662eull,0x326625202c323832ull,
0x35326625202c3537ull,0x0a202f2f09203b35ull,0x3233662e6c756d09ull,0x2c33383266250920ull,
0x202c353732662520ull,0x09203b3435326625ull,0x627573090a202f2full,0x662509203233662eull,
0x326625202c343832ull,0x37326625202c3038ull,0x0a202f2f09203b36ull,0x3233662e62757309ull,
0x2c35383266250920ull,0x202c313832662520ull,0x09203b3737326625ull,0x627573090a202f2full,
0x662509203233662eull,0x326625202c363832ull,0x37326625202c3238ull,0x0a202f2f09203b38ull,
0x3233662e62757309ull,0x2c37383266250920ull,0x202c333832662520ull,0x09203b3937326625ull,
0x706372090a202f2full,0x662509203233662eull,0x326625202c383832ull,0x20202020203b3438ull,
0x0a202f2f09202020ull,0x3233662e6c756d09ull,0x2c39383266250920ull,0x202c353832662520ull,
0x09203b3838326625ull,0x6c756d090a202f2full,0x662509203233662eull,0x326625202c303932ull,
0x38326625202c3638ull,0x0a202f2f09203b38ull,0x3233662e6c756d09ull,0x2c31393266250920ull,
0x202c373832662520ull,0x09203b3838326625ull,0x747663090a202f2full,0x3233662e7461732eull,
0x662509203233662eull,0x326625202c323932ull,0x0a202f2f093b3938ull,0x7461732e74766309ull,
0x3233662e3233662eull,0x2c33393266250920ull,0x093b303932662520ull,0x747663090a202f2full,
0x3233662e7461732eull,0x662509203233662eull,0x326625202c343932ull,0x0a202f2f093b3139ull,
0x3233662e766f6d09ull,0x2c35393266250920ull,0x3038663134663020ull,0x092020203b303030ull,
0x6d090a3133202f2full,0x09203233662e6c75ull,0x25202c3639326625ull,0x6625202c32393266ull,
0x2f2f09203b353932ull,0x662e766f6d090a20ull,0x3932662509203233ull,0x3732346630202c37ull,
0x20203b3030303063ull,0x0a3336202f2f0920ull,0x3233662e6c756d09ull,0x2c38393266250920ull,
0x202c333932662520ull,0x09203b3739326625ull,0x766f6d090a202f2full,0x662509203233662eull,
0x346630202c393932ull,0x3b30303030386631ull,0x33202f2f09202020ull,0x662e6c756d090a31ull,
0x3033662509203233ull,0x3439326625202c30ull,0x3b3939326625202cull,0x63090a202f2f0920ull,
0x662e696e722e7476ull,0x09203233662e3233ull,0x25202c3130336625ull,0x2f2f093b36393266ull,
0x722e747663090a20ull,0x662e3233662e696eull,0x3033662509203233ull,0x3839326625202c32ull,
0x63090a202f2f093bull,0x662e696e722e7476ull,0x09203233662e3233ull,0x25202c3330336625ull,
0x2f2f093b30303366ull,0x722e747663090a20ull,0x662e3233752e697aull,0x3131722509203233ull,
0x3130336625202c39ull,0x73090a202f2f093bull,0x09203233622e6c68ull,0x25202c3032317225ull,
0x3131202c39313172ull,0x2f2f09202020203bull,0x722e747663090a20ull,0x662e3233752e697aull,
0x3231722509203233ull,0x3230336625202c31ull,0x73090a202f2f093bull,0x09203233622e6c68ull,
0x25202c3232317225ull,0x3b35202c31323172ull,0x2f2f092020202020ull,0x33622e726f090a20ull,
0x3332317225092032ull,0x2c3032317225202cull,0x203b323231722520ull,0x63090a202f2f0920ull,
0x752e697a722e7476ull,0x09203233662e3233ull,0x25202c3432317225ull,0x2f2f093b33303366ull,
0x33622e726f090a20ull,0x3532317225092032ull,0x2c3332317225202cull,0x203b343231722520ull,
0x63090a202f2f0920ull,0x752e3631752e7476ull,0x3231722509203233ull,0x3532317225202c36ull,
0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3033662509203233ull,0x3064336630202c34ull,
0x20203b3137353334ull,0x302e30202f2f0920ull,0x090a353737323233ull,0x203233662e6c756dull,
0x202c353033662509ull,0x25202c3130336625ull,0x2f09203b34303366ull,0x636f6c2e090a202full,
0x0933323309363109ull,0x662e6c756d090a30ull,0x3033662509203233ull,0x3137326625202c36ull,
0x3b3635326625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x25202c3730336625ull,
0x6625202c31373266ull,0x2f2f09203b353532ull,0x662e6c756d090a20ull,0x3033662509203233ull,
0x3137326625202c38ull,0x3b3435326625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x25202c3930336625ull,0x6625202c30373266ull,0x2f2f09203b323732ull,0x662e6c756d090a20ull,
0x3133662509203233ull,0x3037326625202c30ull,0x3b3337326625202cull,0x6d090a202f2f0920ull,
0x09203233662e6c75ull,0x25202c3131336625ull,0x6625202c30373266ull,0x2f2f09203b343732ull,
0x662e627573090a20ull,0x3133662509203233ull,0x3930336625202c32ull,0x3b3630336625202cull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3331336625ull,0x6625202c30313366ull,
0x2f2f09203b373033ull,0x662e627573090a20ull,0x3133662509203233ull,0x3131336625202c34ull,
0x3b3830336625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x25202c3531336625ull,
0x6625202c32313366ull,0x2f2f09203b383832ull,0x662e6c756d090a20ull,0x3133662509203233ull,
0x3331336625202c36ull,0x3b3838326625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x25202c3731336625ull,0x6625202c34313366ull,0x2f2f09203b383832ull,0x732e747663090a20ull,
0x662e3233662e7461ull,0x3133662509203233ull,0x3531336625202c38ull,0x63090a202f2f093bull,
0x662e7461732e7476ull,0x09203233662e3233ull,0x25202c3931336625ull,0x2f2f093b36313366ull,
0x732e747663090a20ull,0x662e3233662e7461ull,0x3233662509203233ull,0x3731336625202c30ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x30202c3132336625ull,0x3030303866313466ull,
0x2f2f092020203b30ull,0x6c756d090a313320ull,0x662509203233662eull,0x336625202c323233ull,
0x32336625202c3831ull,0x0a202f2f09203b31ull,0x3233662e766f6d09ull,0x2c33323366250920ull,
0x3063373234663020ull,0x092020203b303030ull,0x6d090a3336202f2full,0x09203233662e6c75ull,
0x25202c3432336625ull,0x6625202c39313366ull,0x2f2f09203b333233ull,0x662e766f6d090a20ull,
0x3233662509203233ull,0x6631346630202c35ull,0x20203b3030303038ull,0x0a3133202f2f0920ull,
0x3233662e6c756d09ull,0x2c36323366250920ull,0x202c303233662520ull,0x09203b3532336625ull,
0x747663090a202f2full,0x3233662e696e722eull,0x662509203233662eull,0x336625202c373233ull,
0x0a202f2f093b3232ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c38323366250920ull,
0x093b343233662520ull,0x747663090a202f2full,0x3233662e696e722eull,0x662509203233662eull,
0x336625202c393233ull,0x0a202f2f093b3632ull,0x697a722e74766309ull,0x3233662e3233752eull,
0x2c37323172250920ull,0x093b373233662520ull,0x6c6873090a202f2full,0x722509203233622eull,
0x317225202c383231ull,0x203b3131202c3732ull,0x0a202f2f09202020ull,0x697a722e74766309ull,
0x3233662e3233752eull,0x2c39323172250920ull,0x093b383233662520ull,0x6c6873090a202f2full,
0x722509203233622eull,0x317225202c303331ull,0x20203b35202c3932ull,0x0a202f2f09202020ull,
0x203233622e726f09ull,0x202c313331722509ull,0x25202c3832317225ull,0x0920203b30333172ull,
0x747663090a202f2full,0x3233752e697a722eull,0x722509203233662eull,0x336625202c323331ull,
0x0a202f2f093b3932ull,0x203233622e726f09ull,0x202c333331722509ull,0x25202c3133317225ull,
0x0920203b32333172ull,0x747663090a202f2full,0x3233752e3631752eull,0x2c34333172250920ull,
0x203b333331722520ull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x2c30333366250920ull,
0x3334306433663020ull,0x092020203b313735ull,0x3233302e30202f2full,0x756d090a35373732ull,
0x2509203233662e6cull,0x6625202c31333366ull,0x336625202c373233ull,0x202f2f09203b3033ull,
0x3109636f6c2e090aull,0x0a30093437330936ull,0x3233662e6c756d09ull,0x2c32333366250920ull,
0x202c353033662520ull,0x09203b3530336625ull,0x6c756d090a202f2full,0x662509203233662eull,
0x336625202c333333ull,0x35326625202c3530ull,0x0a202f2f09203b36ull,0x3233662e6c756d09ull,
0x2c34333366250920ull,0x202c323333662520ull,0x09203b3037326625ull,0x766f6d090a202f2full,
0x662509203233662eull,0x336630202c353333ull,0x3b39313162313863ull,0x30202f2f09202020ull,
0x353133383531302eull,0x33662e6c756d090aull,0x3633336625092032ull,0x2c3230336625202cull,
0x203b353333662520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c37333366ull,
0x3137353334306433ull,0x202f2f092020203bull,0x3737323233302e30ull,0x662e6c756d090a35ull,
0x3333662509203233ull,0x3330336625202c38ull,0x3b3733336625202cull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3933336625ull,0x3131623138633366ull,0x2f2f092020203b39ull,
0x33383531302e3020ull,0x2e6c756d090a3531ull,0x3366250920323366ull,0x32336625202c3034ull,
0x3933336625202c38ull,0x090a202f2f09203bull,0x203233662e766f6dull,0x202c313433662509ull,
0x3533343064336630ull,0x2f092020203b3137ull,0x323233302e30202full,0x6c756d090a353737ull,
0x662509203233662eull,0x336625202c323433ull,0x34336625202c3932ull,0x0a202f2f09203b31ull,
0x3233662e6c756d09ull,0x2c33343366250920ull,0x202c363333662520ull,0x09203b3633336625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x336625202c343433ull,0x35326625202c3633ull,
0x0a202f2f09203b35ull,0x3233662e6c756d09ull,0x2c35343366250920ull,0x202c383333662520ull,
0x09203b3833336625ull,0x6c756d090a202f2full,0x662509203233662eull,0x336625202c363433ull,
0x35326625202c3833ull,0x0a202f2f09203b34ull,0x3233662e6c756d09ull,0x2c37343366250920ull,
0x202c313333662520ull,0x09203b3530336625ull,0x6c756d090a202f2full,0x662509203233662eull,
0x326625202c383433ull,0x33336625202c3237ull,0x0a202f2f09203b31ull,0x3233662e6c756d09ull,
0x2c39343366250920ull,0x202c303433662520ull,0x09203b3034336625ull,0x6c756d090a202f2full,
0x662509203233662eull,0x336625202c303533ull,0x34336625202c3633ull,0x0a202f2f09203b30ull,
0x3233662e6c756d09ull,0x2c31353366250920ull,0x202c333732662520ull,0x09203b3034336625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x336625202c323533ull,0x34336625202c3234ull,
0x0a202f2f09203b32ull,0x3233662e6c756d09ull,0x2c33353366250920ull,0x202c383333662520ull,
0x09203b3234336625ull,0x6c756d090a202f2full,0x662509203233662eull,0x326625202c343533ull,
0x34336625202c3437ull,0x0a202f2f09203b32ull,0x3233662e6c756d09ull,0x2c35353366250920ull,
0x202c303732662520ull,0x09203b3334336625ull,0x6c756d090a202f2full,0x662509203233662eull,
0x326625202c363533ull,0x34336625202c3037ull,0x0a202f2f09203b35ull,0x3233662e6c756d09ull,
0x2c37353366250920ull,0x202c313732662520ull,0x09203b3734336625ull,0x6c756d090a202f2full,
0x662509203233662eull,0x326625202c383533ull,0x34336625202c3537ull,0x0a202f2f09203b39ull,
0x3233662e6c756d09ull,0x2c39353366250920ull,0x202c313732662520ull,0x09203b3035336625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x326625202c303633ull,0x35336625202c3537ull,
0x0a202f2f09203b32ull,0x3233662e6c756d09ull,0x2c31363366250920ull,0x202c313732662520ull,
0x09203b3335336625ull,0x627573090a202f2full,0x662509203233662eull,0x336625202c323633ull,
0x33336625202c3735ull,0x0a202f2f09203b33ull,0x3233662e64646109ull,0x2c33363366250920ull,
0x202c353533662520ull,0x09203b3835336625ull,0x627573090a202f2full,0x662509203233662eull,
0x336625202c343633ull,0x34336625202c3935ull,0x0a202f2f09203b34ull,0x3233662e64646109ull,
0x2c35363366250920ull,0x202c363533662520ull,0x09203b3036336625ull,0x627573090a202f2full,
0x662509203233662eull,0x336625202c363633ull,0x34336625202c3136ull,0x0a202f2f09203b36ull,
0x3233662e62757309ull,0x2c37363366250920ull,0x202c323633662520ull,0x09203b3834336625ull,
0x627573090a202f2full,0x662509203233662eull,0x336625202c383633ull,0x35336625202c3436ull,
0x0a202f2f09203b31ull,0x3233662e62757309ull,0x2c39363366250920ull,0x202c363633662520ull,
0x09203b3435336625ull,0x646461090a202f2full,0x662509203233662eull,0x336625202c303733ull,
0x36336625202c3836ull,0x0a202f2f09203b38ull,0x3233662e64646109ull,0x2c31373366250920ull,
0x202c393633662520ull,0x09203b3936336625ull,0x646461090a202f2full,0x662509203233662eull,
0x336625202c323733ull,0x37336625202c3336ull,0x0a202f2f09203b30ull,0x3233662e64646109ull,
0x2c33373366250920ull,0x202c353633662520ull,0x09203b3137336625ull,0x2e646c090a202f2full,
0x33662e74736e6f63ull,0x3437336625092032ull,0x6f6c6f436b5b202cull,0x2b63697274654d72ull,
0x69202f2f093b5d34ull,0x6b20323733323a64ull,0x74654d726f6c6f43ull,0x0a3478302b636972ull,
0x3233662e6c756d09ull,0x2c35373366250920ull,0x202c343733662520ull,0x09203b3237336625ull,
0x2e646c090a202f2full,0x33662e74736e6f63ull,0x3637336625092032ull,0x6f6c6f436b5b202cull,
0x2b63697274654d72ull,0x69202f2f093b5d38ull,0x6b20333733323a64ull,0x74654d726f6c6f43ull,
0x0a3878302b636972ull,0x3233662e6c756d09ull,0x2c37373366250920ull,0x202c363733662520ull,
0x09203b3337336625ull,0x2e646c090a202f2full,0x33662e74736e6f63ull,0x3837336625092032ull,
0x6f6c6f436b5b202cull,0x2b63697274654d72ull,0x69202f2f093b5d30ull,0x6b20343733323a64ull,
0x74654d726f6c6f43ull,0x0a3078302b636972ull,0x3233662e64646109ull,0x2c39373366250920ull,
0x202c373633662520ull,0x09203b3736336625ull,0x6c756d090a202f2full,0x662509203233662eull,
0x336625202c303833ull,0x33336625202c3133ull,0x0a202f2f09203b31ull,0x3233662e64616d09ull,
0x2c31383366250920ull,0x202c353732662520ull,0x25202c3038336625ull,0x2f2f093b34333366ull,
0x662e646461090a20ull,0x3833662509203233ull,0x3937336625202c32ull,0x3b3138336625202cull,
0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3338336625ull,0x6625202c38373366ull,
0x336625202c323833ull,0x0a202f2f093b3537ull,0x3233662e64646109ull,0x2c34383366250920ull,
0x202c373733662520ull,0x09203b3338336625ull,0x766f6d090a202f2full,0x662509203233662eull,
0x336630202c353833ull,0x3b30303030303865ull,0x30202f2f09202020ull,0x6c756d090a35322eull,
0x662509203233662eull,0x336625202c363833ull,0x38336625202c3438ull,0x0a202f2f09203b35ull,
0x746c2e7074657309ull,0x702509203233662eull,0x38336625202c3631ull,0x3032316625202c36ull,
0x40090a202f2f093bull,0x7262203631702521ull,0x305f744c24092061ull,0x2020203b3435315full,
0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c34363320656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x090a3534315f305full,0x09363109636f6c2eull,0x6d090a3009383733ull,0x09203233662e766full,
0x25202c3032316625ull,0x2020203b36383366ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009333733093631ull,0x6168732e646c090aull,0x203233752e646572ull,0x202c383031722509ull,
0x302b38356472255bull,0x090a202f2f093b5dull,0x09363109636f6c2eull,0x6d090a3009393733ull,
0x09203233732e766full,0x7225202c38397225ull,0x202020203b383031ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009303833093631ull,0x33732e766f6d090aull,0x3130317225092032ull,
0x3b3632317225202cull,0x2020202020202020ull,0x7663090a202f2f09ull,0x33752e3631752e74ull,
0x2c39687225092032ull,0x203b313031722520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093138330936ull,0x3233732e766f6d09ull,0x2c30303172250920ull,0x203b343331722520ull,
0x0920202020202020ull,0x747663090a202f2full,0x3233752e3631752eull,0x2c30316872250920ull,
0x203b303031722520ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,0x702509203233752eull,
0x32317225202c3731ull,0x3433317225202c36ull,0x40090a202f2f093bull,0x6172622037317025ull,
0x5f305f744c240920ull,0x202020203b343531ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x090a3534315f305full,0x09363109636f6c2eull,
0x6f6d090a30093237ull,0x2509203233732e76ull,0x7225202c35333172ull,0x202020203b303031ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300933370936ull,0x203233732e766f6dull,
0x202c303031722509ull,0x20203b3130317225ull,0x2f09202020202020ull,0x2e747663090a202full,
0x203233752e363175ull,0x202c313168722509ull,0x20203b3030317225ull,0x090a202f2f092020ull,
0x09363109636f6c2eull,0x6f6d090a30093437ull,0x2509203233732e76ull,0x7225202c31303172ull,
0x202020203b353331ull,0x202f2f0920202020ull,0x31752e747663090aull,0x2509203233752e36ull,
0x7225202c32316872ull,0x202020203b313031ull,0x6c2e090a202f2f09ull,0x373309363109636full,
0x2e646c090a300933ull,0x752e646572616873ull,0x3031722509203233ull,0x356472255b202c38ull,
0x2f2f093b5d302b38ull,0x09636f6c2e090a20ull,0x3009363833093631ull,0x33622e746f6e090aull,
0x3633317225092032ull,0x3b3830317225202cull,0x2020202020202020ull,0x6873090a202f2f09ull,
0x2509203233752e72ull,0x7225202c37333172ull,0x203b31202c363331ull,0x202f2f0920202020ull,
0x33622e646e61090aull,0x3833317225092032ull,0x2c3733317225202cull,0x3535363133343120ull,
0x202f2f093b353637ull,0x33622e726f78090aull,0x3933317225092032ull,0x2c3830317225202cull,
0x203b383331722520ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x317225202c383972ull,
0x20202020203b3933ull,0x202f2f0920202020ull,0x315f305f744c240aull,0x5f744c240a3a3435ull,
0x200a3a3235315f30ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c343633ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x646461090a353431ull,0x722509203631732eull,0x38687225202c3868ull,0x202020203b31202cull,
0x0a202f2f09202020ull,0x3631752e766f6d09ull,0x2c33316872250920ull,0x20202020203b3320ull,
0x0920202020202020ull,0x746573090a202f2full,0x3631732e656e2e70ull,0x202c383170250920ull,
0x7225202c38687225ull,0x202f2f093b333168ull,0x203831702540090aull,0x744c240920617262ull,
0x203b3534315f305full,0x2020202020202020ull,0x744c240a202f2f09ull,0x2e090a3a325f305full,
0x3309363109636f6cull,0x6f6d090a30093139ull,0x2509203436752e76ull,0x5f5f202c34366472ull,
0x7272655f61647563ull,0x3b3631383173726full,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x7225202c35366472ull,0x36647225202c3264ull,0x202f2f0920203b34ull,0x6168732e7473090aull,
0x203233662e646572ull,0x2b35366472255b09ull,0x32316625202c5d30ull,0x6469202f2f093b30ull,
0x5f5f20313833323aull,0x7272655f61647563ull,0x2b3631383173726full,0x6f6c2e090a307830ull,
0x3330340936310963ull,0x2e766f6d090a3009ull,0x6472250920343675ull,0x69646e69202c3636ull,
0x203b315f5f736563ull,0x090a202f2f092020ull,0x203436752e646461ull,0x202c373664722509ull,
0x7225202c32647225ull,0x2f0920203b363664ull,0x732e7473090a202full,0x33732e6465726168ull,
0x366472255b092032ull,0x7225202c5d302b37ull,0x6469202f2f093b31ull,0x6e6920323833323aull,
0x315f5f7365636964ull,0x6c2e090a3078302bull,0x333409363109636full,0x726162090a300939ull,
0x300920636e79732eull,0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x3233752e766f6d09ull,0x2c30343172250920ull,0x202020203b313320ull,0x0920202020202020ull,
0x746573090a202f2full,0x3233732e74672e70ull,0x202c393170250920ull,0x317225202c317225ull,
0x0a202f2f093b3034ull,0x6220393170254009ull,0x5f744c2409206172ull,0x20203b3737315f30ull,
0x0920202020202020ull,0x2e646c090a202f2full,0x662e646572616873ull,0x3833662509203233ull,
0x366472255b202c37ull,0x2f2f093b5d302b35ull,0x333833323a646920ull,0x5f616475635f5f20ull,
0x383173726f727265ull,0x090a3078302b3631ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c38383366ull,0x3832312b35366472ull,0x6469202f2f093b5dull,0x5f5f20343833323aull,
0x7272655f61647563ull,0x2b3631383173726full,0x746573090a307830ull,0x3233662e74672e70ull,
0x202c303270250920ull,0x25202c3738336625ull,0x2f2f093b38383366ull,0x3270252140090a20ull,
0x2409206172622030ull,0x3736315f305f744cull,0x202020202020203bull,0x6c090a202f2f0920ull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c383833ull,0x5d3832312b353664ull,
0x2e090a202f2f093bull,0x3409363109636f6cull,0x6f6d090a30093534ull,0x2509203233662e76ull,
0x6625202c37383366ull,0x202020203b383833ull,0x202f2f0920202020ull,0x6168732e7473090aull,
0x203233662e646572ull,0x2b35366472255b09ull,0x38336625202c5d30ull,0x6469202f2f093b38ull,
0x5f5f20353833323aull,0x7272655f61647563ull,0x2b3631383173726full,0x6f6c2e090a307830ull,
0x3634340936310963ull,0x732e646c090a3009ull,0x33732e6465726168ull,0x3134317225092032ull,
0x37366472255b202cull,0x2f093b5d3832312bull,0x3833323a6469202full,0x656369646e692036ull,
0x3078302b315f5f73ull,0x6168732e7473090aull,0x203233732e646572ull,0x2b37366472255b09ull,
0x34317225202c5d30ull,0x6469202f2f093b31ull,0x6e6920373833323aull,0x315f5f7365636964ull,
0x744c240a3078302bull,0x0a3a3736315f305full,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3938336625ull,0x34362b3536647225ull,0x6469202f2f093b5dull,0x5f5f20383833323aull,
0x7272655f61647563ull,0x2b3631383173726full,0x746573090a307830ull,0x3233662e74672e70ull,
0x202c313270250920ull,0x25202c3738336625ull,0x2f2f093b39383366ull,0x3270252140090a20ull,
0x2409206172622031ull,0x3936315f305f744cull,0x202020202020203bull,0x6c090a202f2f0920ull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c393833ull,0x3b5d34362b353664ull,
0x6c2e090a202f2f09ull,0x343409363109636full,0x766f6d090a300939ull,0x662509203233662eull,
0x336625202c373833ull,0x20202020203b3938ull,0x0a202f2f09202020ull,0x726168732e747309ull,
0x09203233662e6465ull,0x302b35366472255bull,0x3938336625202c5dull,0x3a6469202f2f093bull,
0x635f5f2039383332ull,0x6f7272655f616475ull,0x302b363138317372ull,0x636f6c2e090a3078ull,
0x0930353409363109ull,0x68732e646c090a30ull,0x3233732e64657261ull,0x2c32343172250920ull,
0x2b37366472255b20ull,0x202f2f093b5d3436ull,0x20303933323a6469ull,0x5f73656369646e69ull,
0x090a3078302b315full,0x65726168732e7473ull,0x5b09203233732e64ull,0x5d302b3736647225ull,
0x3b3234317225202cull,0x323a6469202f2f09ull,0x69646e6920313933ull,0x302b315f5f736563ull,
0x305f744c240a3078ull,0x6c090a3a3936315full,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c303933ull,0x3b5d32332b353664ull,0x323a6469202f2f09ull,0x75635f5f20323933ull,
0x726f7272655f6164ull,0x78302b3631383173ull,0x2e70746573090a30ull,0x09203233662e7467ull,
0x6625202c32327025ull,0x336625202c373833ull,0x0a202f2f093b3039ull,0x2032327025214009ull,
0x744c240920617262ull,0x203b3137315f305full,0x0920202020202020ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3933662509203233ull,0x366472255b202c30ull,0x2f093b5d32332b35ull,
0x636f6c2e090a202full,0x0933353409363109ull,0x662e766f6d090a30ull,0x3833662509203233ull,
0x3039336625202c37ull,0x202020202020203bull,0x73090a202f2f0920ull,0x6465726168732e74ull,
0x255b09203233662eull,0x2c5d302b35366472ull,0x093b303933662520ull,0x33323a6469202f2full,
0x6475635f5f203339ull,0x73726f7272655f61ull,0x3078302b36313831ull,0x3109636f6c2e090aull,
0x0a30093435340936ull,0x726168732e646c09ull,0x09203233732e6465ull,0x5b202c3334317225ull,
0x32332b3736647225ull,0x6469202f2f093b5dull,0x6e6920343933323aull,0x315f5f7365636964ull,
0x7473090a3078302bull,0x2e6465726168732eull,0x72255b0920323373ull,0x202c5d302b373664ull,
0x2f093b3334317225ull,0x3933323a6469202full,0x656369646e692035ull,0x3078302b315f5f73ull,
0x315f305f744c240aull,0x2e646c090a3a3137ull,0x662e646572616873ull,0x3933662509203233ull,
0x366472255b202c31ull,0x2f093b5d36312b35ull,0x3933323a6469202full,0x616475635f5f2036ull,
0x3173726f7272655full,0x0a3078302b363138ull,0x74672e7074657309ull,0x702509203233662eull,
0x38336625202c3332ull,0x3139336625202c37ull,0x40090a202f2f093bull,0x7262203332702521ull,
0x305f744c24092061ull,0x2020203b3337315full,0x2f2f092020202020ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c31393366250920ull,0x2b35366472255b20ull,0x202f2f093b5d3631ull,
0x3109636f6c2e090aull,0x0a30093735340936ull,0x3233662e766f6d09ull,0x2c37383366250920ull,
0x203b313933662520ull,0x0920202020202020ull,0x2e7473090a202f2full,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3536ull,0x2f2f093b31393366ull,0x373933323a646920ull,
0x5f616475635f5f20ull,0x383173726f727265ull,0x090a3078302b3631ull,0x09363109636f6c2eull,
0x6c090a3009383534ull,0x6465726168732e64ull,0x722509203233732eull,0x72255b202c343431ull,
0x3b5d36312b373664ull,0x323a6469202f2f09ull,0x69646e6920383933ull,0x302b315f5f736563ull,
0x732e7473090a3078ull,0x33732e6465726168ull,0x366472255b092032ull,0x7225202c5d302b37ull,
0x202f2f093b343431ull,0x20393933323a6469ull,0x5f73656369646e69ull,0x240a3078302b315full,
0x3337315f305f744cull,0x68732e646c090a3aull,0x3233662e64657261ull,0x2c32393366250920ull,
0x2b35366472255b20ull,0x69202f2f093b5d38ull,0x5f20303034323a64ull,0x72655f616475635full,
0x3631383173726f72ull,0x6573090a3078302bull,0x33662e74672e7074ull,0x2c34327025092032ull,
0x202c373833662520ull,0x2f093b3239336625ull,0x70252140090a202full,0x0920617262203432ull,
0x37315f305f744c24ull,0x2020202020203b35ull,0x090a202f2f092020ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c32393366ull,0x3b5d382b35366472ull,0x6c2e090a202f2f09ull,
0x363409363109636full,0x766f6d090a300931ull,0x662509203233662eull,0x336625202c373833ull,
0x20202020203b3239ull,0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233662e6465ull,
0x302b35366472255bull,0x3239336625202c5dull,0x3a6469202f2f093bull,0x635f5f2031303432ull,
0x6f7272655f616475ull,0x302b363138317372ull,0x636f6c2e090a3078ull,0x0932363409363109ull,
0x68732e646c090a30ull,0x3233732e64657261ull,0x2c35343172250920ull,0x2b37366472255b20ull,
0x69202f2f093b5d38ull,0x6920323034323a64ull,0x5f5f73656369646eull,0x73090a3078302b31ull,
0x6465726168732e74ull,0x255b09203233732eull,0x2c5d302b37366472ull,0x093b353431722520ull,
0x34323a6469202f2full,0x6369646e69203330ull,0x78302b315f5f7365ull,0x5f305f744c240a30ull,
0x646c090a3a353731ull,0x2e6465726168732eull,0x3366250920323366ull,0x6472255b202c3339ull,
0x2f093b5d342b3536ull,0x3034323a6469202full,0x616475635f5f2034ull,0x3173726f7272655full,
0x0a3078302b363138ull,0x74672e7074657309ull,0x702509203233662eull,0x38336625202c3532ull,
0x3339336625202c37ull,0x40090a202f2f093bull,0x7262203532702521ull,0x305f744c24092061ull,
0x2020203b3737315full,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009353634093631ull,
0x6168732e7473090aull,0x203233662e646572ull,0x2b35366472255b09ull,0x39336625202c5d30ull,
0x6469202f2f093b33ull,0x5f5f20353034323aull,0x7272655f61647563ull,0x2b3631383173726full,
0x6f6c2e090a307830ull,0x3636340936310963ull,0x732e646c090a3009ull,0x33732e6465726168ull,
0x3634317225092032ull,0x37366472255b202cull,0x202f2f093b5d342bull,0x20363034323a6469ull,
0x5f73656369646e69ull,0x090a3078302b315full,0x65726168732e7473ull,0x5b09203233732e64ull,
0x5d302b3736647225ull,0x3b3634317225202cull,0x323a6469202f2f09ull,0x69646e6920373034ull,
0x302b315f5f736563ull,0x305f744c240a3078ull,0x4c240a3a3737315full,0x3a3536315f305f74ull,
0x3109636f6c2e090aull,0x0a30093137340936ull,0x6e79732e72616209ull,0x2020203b30092063ull,
0x2020202020202020ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3832350936310963ull,
0x732e646c090a3009ull,0x33732e6465726168ull,0x3734317225092032ull,0x6369646e695b202cull,
0x5d302b315f5f7365ull,0x3a6469202f2f093bull,0x646e692038303432ull,0x2b315f5f73656369ull,
0x6f6c2e090a307830ull,0x3033350936310963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x2020202020202020ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e656e2e70746573ull,
0x3270250920323373ull,0x3734317225202c36ull,0x2f093b317225202cull,0x32702540090a202full,
0x2409206172622036ull,0x3937315f305f744cull,0x202020202020203bull,0x090a202f2f092020ull,
0x09363109636f6c2eull,0x73090a3009343934ull,0x752e71652e707465ull,0x3732702509203233ull,
0x2c3030317225202cull,0x093b313031722520ull,0x766f6d090a202f2full,0x722509203233752eull,
0x203b30202c383431ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x3233732e766f6d09ull,
0x2c39343172250920ull,0x20203b3839722520ull,0x0920202020202020ull,0x6c6573090a202f2full,
0x2509203233752e70ull,0x7225202c30353172ull,0x317225202c383431ull,0x37327025202c3934ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x722509203233732eull,0x5f5f5b202c313531ull,
0x6572785f61647563ull,0x302b323537317366ull,0x6469202f2f093b5dull,0x5f5f20393034323aull,
0x6572785f61647563ull,0x090a323537317366ull,0x732e6f6c2e6c756dull,0x3531722509203233ull,
0x3135317225202c32ull,0x2f0920203b32202cull,0x2e726873090a202full,0x3172250920323375ull,
0x35317225202c3335ull,0x3235317225202c30ull,0x090a202f2f09203bull,0x203233622e646e61ull,
0x202c343531722509ull,0x33202c3335317225ull,0x2f0920202020203bull,0x732e646c090a202full,
0x33732e6465726168ull,0x3535317225092032ull,0x6475635f5f5b202cull,0x3173666572785f61ull,
0x093b5d342b323537ull,0x34323a6469202f2full,0x6475635f5f203031ull,0x3173666572785f61ull,
0x6c756d090a323537ull,0x203233732e6f6c2eull,0x202c363531722509ull,0x32202c3535317225ull,
0x0a202f2f0920203bull,0x3233752e72687309ull,0x2c37353172250920ull,0x202c303531722520ull,
0x09203b3635317225ull,0x646e61090a202f2full,0x722509203233622eull,0x317225202c383531ull,
0x20203b33202c3735ull,0x0a202f2f09202020ull,0x3233622e6c687309ull,0x2c39353172250920ull,
0x202c383531722520ull,0x0920202020203b32ull,0x2e726f090a202f2full,0x3172250920323362ull,
0x35317225202c3036ull,0x3935317225202c34ull,0x0a202f2f0920203bull,0x726168732e646c09ull,
0x09203233732e6465ull,0x5b202c3136317225ull,0x785f616475635f5full,0x3235373173666572ull,
0x202f2f093b5d382bull,0x20313134323a6469ull,0x785f616475635f5full,0x3235373173666572ull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x317225202c323631ull,0x20203b32202c3136ull,
0x6873090a202f2f09ull,0x2509203233752e72ull,0x7225202c33363172ull,0x317225202c303531ull,
0x202f2f09203b3236ull,0x33622e646e61090aull,0x3436317225092032ull,0x2c3336317225202cull,
0x20202020203b3320ull,0x6873090a202f2f09ull,0x2509203233622e6cull,0x7225202c35363172ull,
0x203b34202c343631ull,0x202f2f0920202020ull,0x3233622e726f090aull,0x2c36363172250920ull,
0x202c303631722520ull,0x20203b3536317225ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3172250920323373ull,0x635f5f5b202c3736ull,0x666572785f616475ull,0x32312b3235373173ull,
0x6469202f2f093b5dull,0x5f5f20323134323aull,0x6572785f61647563ull,0x090a323537317366ull,
0x732e6f6c2e6c756dull,0x3631722509203233ull,0x3736317225202c38ull,0x2f0920203b32202cull,
0x2e726873090a202full,0x3172250920323375ull,0x35317225202c3936ull,0x3836317225202c30ull,
0x090a202f2f09203bull,0x203233622e646e61ull,0x202c303731722509ull,0x33202c3936317225ull,
0x2f0920202020203bull,0x2e6c6873090a202full,0x3172250920323362ull,0x37317225202c3137ull,
0x2020203b36202c30ull,0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233732e64ull,
0x5f5b202c32373172ull,0x72785f616475635full,0x2b32353731736665ull,0x202f2f093b5d3631ull,
0x20333134323a6469ull,0x785f616475635f5full,0x3235373173666572ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c333731ull,0x20203b32202c3237ull,0x6873090a202f2f09ull,
0x2509203233752e72ull,0x7225202c34373172ull,0x317225202c303531ull,0x202f2f09203b3337ull,
0x33622e646e61090aull,0x3537317225092032ull,0x2c3437317225202cull,0x20202020203b3320ull,
0x6873090a202f2f09ull,0x2509203233622e6cull,0x7225202c36373172ull,0x203b38202c353731ull,
0x202f2f0920202020ull,0x3233622e726f090aull,0x2c37373172250920ull,0x202c313731722520ull,
0x20203b3637317225ull,0x726f090a202f2f09ull,0x722509203233622eull,0x317225202c383731ull,
0x37317225202c3636ull,0x202f2f0920203b37ull,0x6168732e646c090aull,0x203233732e646572ull,
0x202c393731722509ull,0x5f616475635f5f5bull,0x3537317366657278ull,0x2f093b5d30322b32ull,
0x3134323a6469202full,0x616475635f5f2034ull,0x373173666572785full,0x2e6c756d090a3235ull,
0x09203233732e6f6cull,0x25202c3038317225ull,0x3b32202c39373172ull,0x090a202f2f092020ull,
0x203233752e726873ull,0x202c313831722509ull,0x25202c3035317225ull,0x2f09203b30383172ull,
0x2e646e61090a202full,0x3172250920323362ull,0x38317225202c3238ull,0x2020203b33202c31ull,
0x090a202f2f092020ull,0x203233622e6c6873ull,0x202c333831722509ull,0x31202c3238317225ull,
0x2f09202020203b30ull,0x732e646c090a202full,0x33732e6465726168ull,0x3438317225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d34322b323537ull,0x323a6469202f2f09ull,
0x75635f5f20353134ull,0x73666572785f6164ull,0x756d090a32353731ull,0x3233732e6f6c2e6cull,
0x2c35383172250920ull,0x202c343831722520ull,0x202f2f0920203b32ull,0x33752e726873090aull,
0x3638317225092032ull,0x2c3035317225202cull,0x203b353831722520ull,0x6e61090a202f2f09ull,
0x2509203233622e64ull,0x7225202c37383172ull,0x203b33202c363831ull,0x202f2f0920202020ull,
0x33622e6c6873090aull,0x3838317225092032ull,0x2c3738317225202cull,0x202020203b323120ull,
0x726f090a202f2f09ull,0x722509203233622eull,0x317225202c393831ull,0x38317225202c3338ull,
0x202f2f0920203b38ull,0x3233622e726f090aull,0x2c30393172250920ull,0x202c383731722520ull,
0x20203b3938317225ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3172250920323373ull,
0x635f5f5b202c3139ull,0x666572785f616475ull,0x38322b3235373173ull,0x6469202f2f093b5dull,
0x5f5f20363134323aull,0x6572785f61647563ull,0x090a323537317366ull,0x732e6f6c2e6c756dull,
0x3931722509203233ull,0x3139317225202c32ull,0x2f0920203b32202cull,0x2e726873090a202full,
0x3172250920323375ull,0x35317225202c3339ull,0x3239317225202c30ull,0x090a202f2f09203bull,
0x203233622e646e61ull,0x202c343931722509ull,0x33202c3339317225ull,0x2f0920202020203bull,
0x2e6c6873090a202full,0x3172250920323362ull,0x39317225202c3539ull,0x20203b3431202c34ull,
0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c36393172ull,
0x72785f616475635full,0x2b32353731736665ull,0x202f2f093b5d3233ull,0x20373134323a6469ull,
0x785f616475635f5full,0x3235373173666572ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x317225202c373931ull,0x20203b32202c3639ull,0x6873090a202f2f09ull,0x2509203233752e72ull,
0x7225202c38393172ull,0x317225202c303531ull,0x202f2f09203b3739ull,0x33622e646e61090aull,
0x3939317225092032ull,0x2c3839317225202cull,0x20202020203b3320ull,0x6873090a202f2f09ull,
0x2509203233622e6cull,0x7225202c30303272ull,0x3b3631202c393931ull,0x202f2f0920202020ull,
0x3233622e726f090aull,0x2c31303272250920ull,0x202c353931722520ull,0x20203b3030327225ull,
0x726f090a202f2f09ull,0x722509203233622eull,0x317225202c323032ull,0x30327225202c3039ull,
0x202f2f0920203b31ull,0x6168732e646c090aull,0x203233732e646572ull,0x202c333032722509ull,
0x5f616475635f5f5bull,0x3537317366657278ull,0x2f093b5d36332b32ull,0x3134323a6469202full,
0x616475635f5f2038ull,0x373173666572785full,0x2e6c756d090a3235ull,0x09203233732e6f6cull,
0x25202c3430327225ull,0x3b32202c33303272ull,0x090a202f2f092020ull,0x203233752e726873ull,
0x202c353032722509ull,0x25202c3035317225ull,0x2f09203b34303272ull,0x2e646e61090a202full,
0x3272250920323362ull,0x30327225202c3630ull,0x2020203b33202c35ull,0x090a202f2f092020ull,
0x203233622e6c6873ull,0x202c373032722509ull,0x31202c3630327225ull,0x2f09202020203b38ull,
0x622e726f090a202full,0x3032722509203233ull,0x3230327225202c32ull,0x3b3730327225202cull,
0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38303272ull,
0x72785f616475635full,0x2b32353731736665ull,0x202f2f093b5d3034ull,0x20393134323a6469ull,
0x785f616475635f5full,0x3235373173666572ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x327225202c393032ull,0x20203b32202c3830ull,0x6873090a202f2f09ull,0x2509203233752e72ull,
0x7225202c30313272ull,0x327225202c303531ull,0x202f2f09203b3930ull,0x33622e646e61090aull,
0x3131327225092032ull,0x2c3031327225202cull,0x20202020203b3320ull,0x6873090a202f2f09ull,
0x2509203233622e6cull,0x7225202c32313272ull,0x3b3032202c313132ull,0x202f2f0920202020ull,
0x3233622e726f090aull,0x2c32303272250920ull,0x202c323032722520ull,0x20203b3231327225ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3272250920323373ull,0x635f5f5b202c3331ull,
0x666572785f616475ull,0x34342b3235373173ull,0x6469202f2f093b5dull,0x5f5f20303234323aull,
0x6572785f61647563ull,0x090a323537317366ull,0x732e6f6c2e6c756dull,0x3132722509203233ull,
0x3331327225202c34ull,0x2f0920203b32202cull,0x2e726873090a202full,0x3272250920323375ull,
0x35317225202c3531ull,0x3431327225202c30ull,0x090a202f2f09203bull,0x203233622e646e61ull,
0x202c363132722509ull,0x33202c3531327225ull,0x2f0920202020203bull,0x2e6c6873090a202full,
0x3272250920323362ull,0x31327225202c3731ull,0x20203b3232202c36ull,0x090a202f2f092020ull,
0x09203233622e726full,0x25202c3230327225ull,0x7225202c32303272ull,0x2f0920203b373132ull,
0x732e646c090a202full,0x33732e6465726168ull,0x3831327225092032ull,0x6475635f5f5b202cull,
0x3173666572785f61ull,0x3b5d38342b323537ull,0x323a6469202f2f09ull,0x75635f5f20313234ull,
0x73666572785f6164ull,0x756d090a32353731ull,0x3233732e6f6c2e6cull,0x2c39313272250920ull,
0x202c383132722520ull,0x202f2f0920203b32ull,0x33752e726873090aull,0x3032327225092032ull,
0x2c3035317225202cull,0x203b393132722520ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,
0x7225202c31323272ull,0x203b33202c303232ull,0x202f2f0920202020ull,0x33622e6c6873090aull,
0x3232327225092032ull,0x2c3132327225202cull,0x202020203b343220ull,0x726f090a202f2f09ull,
0x722509203233622eull,0x327225202c323032ull,0x32327225202c3230ull,0x202f2f0920203b32ull,
0x6168732e646c090aull,0x203233732e646572ull,0x202c333232722509ull,0x5f616475635f5f5bull,
0x3537317366657278ull,0x2f093b5d32352b32ull,0x3234323a6469202full,0x616475635f5f2032ull,
0x373173666572785full,0x2e6c756d090a3235ull,0x09203233732e6f6cull,0x25202c3432327225ull,
0x3b32202c33323272ull,0x090a202f2f092020ull,0x203233752e726873ull,0x202c353232722509ull,
0x25202c3035317225ull,0x2f09203b34323272ull,0x2e646e61090a202full,0x3272250920323362ull,
0x32327225202c3632ull,0x2020203b33202c35ull,0x090a202f2f092020ull,0x203233622e6c6873ull,
0x202c373232722509ull,0x32202c3632327225ull,0x2f09202020203b36ull,0x622e726f090a202full,
0x3032722509203233ull,0x3230327225202c32ull,0x3b3732327225202cull,0x090a202f2f092020ull,
0x65726168732e646cull,0x2509203233732e64ull,0x5f5b202c38323272ull,0x72785f616475635full,
0x2b32353731736665ull,0x202f2f093b5d3635ull,0x20333234323a6469ull,0x785f616475635f5full,
0x3235373173666572ull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x327225202c393232ull,
0x20203b32202c3832ull,0x6873090a202f2f09ull,0x2509203233752e72ull,0x7225202c30333272ull,
0x327225202c303531ull,0x202f2f09203b3932ull,0x33622e646e61090aull,0x3133327225092032ull,
0x2c3033327225202cull,0x20202020203b3320ull,0x6873090a202f2f09ull,0x2509203233622e6cull,
0x7225202c32333272ull,0x3b3832202c313332ull,0x202f2f0920202020ull,0x3233622e726f090aull,
0x2c32303272250920ull,0x202c323032722520ull,0x20203b3233327225ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3272250920323373ull,0x635f5f5b202c3333ull,0x666572785f616475ull,
0x30362b3235373173ull,0x6469202f2f093b5dull,0x5f5f20343234323aull,0x6572785f61647563ull,
0x090a323537317366ull,0x732e6f6c2e6c756dull,0x3332722509203233ull,0x3333327225202c34ull,
0x2f0920203b32202cull,0x2e726873090a202full,0x3272250920323375ull,0x35317225202c3533ull,
0x3433327225202c30ull,0x090a202f2f09203bull,0x203233622e6c6873ull,0x202c363332722509ull,
0x33202c3533327225ull,0x2f09202020203b30ull,0x622e726f090a202full,0x3032722509203233ull,
0x3230327225202c32ull,0x3b3633327225202cull,0x090a202f2f092020ull,0x09363109636f6c2eull,
0x6c090a3009383934ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x635f5f5b202c3836ull,
0x5f6d726170616475ull,0x72706d6f63385a5full,0x30536a4b50737365ull,0x32746e697535505full,
0x5d746c757365725full,0x3a6469202f2f093bull,0x635f5f2035323432ull,0x5f6d726170616475ull,
0x72706d6f63385a5full,0x30536a4b50737365ull,0x32746e697535505full,0x2b746c757365725full,
0x747663090a307830ull,0x3631752e3233732eull,0x2c37333272250920ull,0x2e64696174632520ull,
0x0a202f2f09203b78ull,0x3436752e74766309ull,0x722509203233732eull,0x327225202c393664ull,
0x09202020203b3733ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c303764722509ull,
0x38202c3936647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c31376472250920ull,
0x202c383664722520ull,0x09203b3037647225ull,0x6c6873090a202f2full,0x722509203233622eull,
0x317225202c383332ull,0x203b3631202c3030ull,0x0a202f2f09202020ull,0x203233622e726f09ull,
0x202c393332722509ull,0x25202c3130317225ull,0x0920203b38333272ull,0x2e7473090a202f2full,
0x762e6c61626f6c67ull,0x5b09203233752e32ull,0x5d302b3137647225ull,0x39333272257b202cull,
0x3b7d32303272252cull,0x744c240a202f2f09ull,0x0a3a3937315f305full,0x363109636f6c2e09ull,
0x090a300937333509ull,0x2020203b74697865ull,0x2020202020202020ull,0x2020202020202020ull,
0x2f09202020202020ull,0x6557444c240a202full,0x6f63385a5f5f646eull,0x4b5073736572706dull,
0x697535505f30536aull,0x207d090a3a32746eull,0x6f63385a5f202f2full,0x4b5073736572706dull,
0x697535505f30536aull,0x0000000a0a32746eull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"3cc9324d42e8eb92",(char*)"dxtc.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0};
# 5 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_00000e36_00000000-1_dxtc.cudafe1.stub.c" 2
struct __T20;
struct __T20 {const uint *__par0;const uint *__par1;uint2 *__par2;int __dummy_field;volatile char __dummy[4];};



static void __sti____cudaRegisterAll_39_tmpxft_00000e36_00000000_7_dxtc_cpp1_ii_c14de7b3(void) __attribute__((__constructor__));
void __device_stub__Z8compressPKjS0_P5uint2(const uint *__par0, const uint *__par1, uint2 *__par2){auto struct __T20 *__T2328;
char __[256]; *(char**)&__T2328 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2328->__par0 - (size_t)__T2328) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2328->__par1 - (size_t)__T2328) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2328->__par2 - (size_t)__T2328) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z8compressPKjS0_P5uint2); (void)cudaLaunch(((char *)__device_stub__Z8compressPKjS0_P5uint2)); };}



static void __sti____cudaRegisterAll_39_tmpxft_00000e36_00000000_7_dxtc_cpp1_ii_c14de7b3(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z8compressPKjS0_P5uint2, (char*)"_Z8compressPKjS0_P5uint2", "_Z8compressPKjS0_P5uint2", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_kColorMetric, (char*)"kColorMetric", "kColorMetric", 0, 12, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_alphaTable4, (char*)"alphaTable4", "alphaTable4", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_alphaTable3, (char*)"alphaTable3", "alphaTable3", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_prods4, (char*)"prods4", "prods4", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_prods3, (char*)"prods3", "prods3", 0, 16, 1, 0);}

}
# 858 "dxtc.cu" 2

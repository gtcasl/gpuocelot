# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "bicubicTexture.cu"
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
# 230 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned GLenum; }
# 231 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned GLbitfield; }
# 232 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned GLuint; }
# 233 "/usr/include/GL/glew.h" 3
extern "C" { typedef int GLint; }
# 234 "/usr/include/GL/glew.h" 3
extern "C" { typedef int GLsizei; }
# 236 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned char GLboolean; }
# 237 "/usr/include/GL/glew.h" 3
extern "C" { typedef signed char GLbyte; }
# 238 "/usr/include/GL/glew.h" 3
extern "C" { typedef short GLshort; }
# 239 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned char GLubyte; }
# 240 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned short GLushort; }
# 241 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned long GLulong; }
# 242 "/usr/include/GL/glew.h" 3
extern "C" { typedef float GLfloat; }
# 243 "/usr/include/GL/glew.h" 3
extern "C" { typedef float GLclampf; }
# 244 "/usr/include/GL/glew.h" 3
extern "C" { typedef double GLdouble; }
# 245 "/usr/include/GL/glew.h" 3
extern "C" { typedef double GLclampd; }
# 246 "/usr/include/GL/glew.h" 3
extern "C" { typedef void GLvoid; }
# 251 "/usr/include/GL/glew.h" 3
extern "C" { typedef signed long long GLint64EXT; }
# 252 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned long long GLuint64EXT; }
# 790 "/usr/include/GL/glew.h" 3
extern "C" void glAccum(GLenum, GLfloat);
# 791 "/usr/include/GL/glew.h" 3
extern "C" void glAlphaFunc(GLenum, GLclampf);
# 792 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glAreTexturesResident(GLsizei, const GLuint *, GLboolean *);
# 793 "/usr/include/GL/glew.h" 3
extern "C" void glArrayElement(GLint);
# 794 "/usr/include/GL/glew.h" 3
extern "C" void glBegin(GLenum);
# 795 "/usr/include/GL/glew.h" 3
extern "C" void glBindTexture(GLenum, GLuint);
# 796 "/usr/include/GL/glew.h" 3
extern "C" void glBitmap(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
# 797 "/usr/include/GL/glew.h" 3
extern "C" void glBlendFunc(GLenum, GLenum);
# 798 "/usr/include/GL/glew.h" 3
extern "C" void glCallList(GLuint);
# 799 "/usr/include/GL/glew.h" 3
extern "C" void glCallLists(GLsizei, GLenum, const GLvoid *);
# 800 "/usr/include/GL/glew.h" 3
extern "C" void glClear(GLbitfield);
# 801 "/usr/include/GL/glew.h" 3
extern "C" void glClearAccum(GLfloat, GLfloat, GLfloat, GLfloat);
# 802 "/usr/include/GL/glew.h" 3
extern "C" void glClearColor(GLclampf, GLclampf, GLclampf, GLclampf);
# 803 "/usr/include/GL/glew.h" 3
extern "C" void glClearDepth(GLclampd);
# 804 "/usr/include/GL/glew.h" 3
extern "C" void glClearIndex(GLfloat);
# 805 "/usr/include/GL/glew.h" 3
extern "C" void glClearStencil(GLint);
# 806 "/usr/include/GL/glew.h" 3
extern "C" void glClipPlane(GLenum, const GLdouble *);
# 807 "/usr/include/GL/glew.h" 3
extern "C" void glColor3b(GLbyte, GLbyte, GLbyte);
# 808 "/usr/include/GL/glew.h" 3
extern "C" void glColor3bv(const GLbyte *);
# 809 "/usr/include/GL/glew.h" 3
extern "C" void glColor3d(GLdouble, GLdouble, GLdouble);
# 810 "/usr/include/GL/glew.h" 3
extern "C" void glColor3dv(const GLdouble *);
# 811 "/usr/include/GL/glew.h" 3
extern "C" void glColor3f(GLfloat, GLfloat, GLfloat);
# 812 "/usr/include/GL/glew.h" 3
extern "C" void glColor3fv(const GLfloat *);
# 813 "/usr/include/GL/glew.h" 3
extern "C" void glColor3i(GLint, GLint, GLint);
# 814 "/usr/include/GL/glew.h" 3
extern "C" void glColor3iv(const GLint *);
# 815 "/usr/include/GL/glew.h" 3
extern "C" void glColor3s(GLshort, GLshort, GLshort);
# 816 "/usr/include/GL/glew.h" 3
extern "C" void glColor3sv(const GLshort *);
# 817 "/usr/include/GL/glew.h" 3
extern "C" void glColor3ub(GLubyte, GLubyte, GLubyte);
# 818 "/usr/include/GL/glew.h" 3
extern "C" void glColor3ubv(const GLubyte *);
# 819 "/usr/include/GL/glew.h" 3
extern "C" void glColor3ui(GLuint, GLuint, GLuint);
# 820 "/usr/include/GL/glew.h" 3
extern "C" void glColor3uiv(const GLuint *);
# 821 "/usr/include/GL/glew.h" 3
extern "C" void glColor3us(GLushort, GLushort, GLushort);
# 822 "/usr/include/GL/glew.h" 3
extern "C" void glColor3usv(const GLushort *);
# 823 "/usr/include/GL/glew.h" 3
extern "C" void glColor4b(GLbyte, GLbyte, GLbyte, GLbyte);
# 824 "/usr/include/GL/glew.h" 3
extern "C" void glColor4bv(const GLbyte *);
# 825 "/usr/include/GL/glew.h" 3
extern "C" void glColor4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 826 "/usr/include/GL/glew.h" 3
extern "C" void glColor4dv(const GLdouble *);
# 827 "/usr/include/GL/glew.h" 3
extern "C" void glColor4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 828 "/usr/include/GL/glew.h" 3
extern "C" void glColor4fv(const GLfloat *);
# 829 "/usr/include/GL/glew.h" 3
extern "C" void glColor4i(GLint, GLint, GLint, GLint);
# 830 "/usr/include/GL/glew.h" 3
extern "C" void glColor4iv(const GLint *);
# 831 "/usr/include/GL/glew.h" 3
extern "C" void glColor4s(GLshort, GLshort, GLshort, GLshort);
# 832 "/usr/include/GL/glew.h" 3
extern "C" void glColor4sv(const GLshort *);
# 833 "/usr/include/GL/glew.h" 3
extern "C" void glColor4ub(GLubyte, GLubyte, GLubyte, GLubyte);
# 834 "/usr/include/GL/glew.h" 3
extern "C" void glColor4ubv(const GLubyte *);
# 835 "/usr/include/GL/glew.h" 3
extern "C" void glColor4ui(GLuint, GLuint, GLuint, GLuint);
# 836 "/usr/include/GL/glew.h" 3
extern "C" void glColor4uiv(const GLuint *);
# 837 "/usr/include/GL/glew.h" 3
extern "C" void glColor4us(GLushort, GLushort, GLushort, GLushort);
# 838 "/usr/include/GL/glew.h" 3
extern "C" void glColor4usv(const GLushort *);
# 839 "/usr/include/GL/glew.h" 3
extern "C" void glColorMask(GLboolean, GLboolean, GLboolean, GLboolean);
# 840 "/usr/include/GL/glew.h" 3
extern "C" void glColorMaterial(GLenum, GLenum);
# 841 "/usr/include/GL/glew.h" 3
extern "C" void glColorPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 842 "/usr/include/GL/glew.h" 3
extern "C" void glCopyPixels(GLint, GLint, GLsizei, GLsizei, GLenum);
# 843 "/usr/include/GL/glew.h" 3
extern "C" void glCopyTexImage1D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
# 844 "/usr/include/GL/glew.h" 3
extern "C" void glCopyTexImage2D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
# 845 "/usr/include/GL/glew.h" 3
extern "C" void glCopyTexSubImage1D(GLenum, GLint, GLint, GLint, GLint, GLsizei);
# 846 "/usr/include/GL/glew.h" 3
extern "C" void glCopyTexSubImage2D(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
# 847 "/usr/include/GL/glew.h" 3
extern "C" void glCullFace(GLenum);
# 848 "/usr/include/GL/glew.h" 3
extern "C" void glDeleteLists(GLuint, GLsizei);
# 849 "/usr/include/GL/glew.h" 3
extern "C" void glDeleteTextures(GLsizei, const GLuint *);
# 850 "/usr/include/GL/glew.h" 3
extern "C" void glDepthFunc(GLenum);
# 851 "/usr/include/GL/glew.h" 3
extern "C" void glDepthMask(GLboolean);
# 852 "/usr/include/GL/glew.h" 3
extern "C" void glDepthRange(GLclampd, GLclampd);
# 853 "/usr/include/GL/glew.h" 3
extern "C" void glDisable(GLenum);
# 854 "/usr/include/GL/glew.h" 3
extern "C" void glDisableClientState(GLenum);
# 855 "/usr/include/GL/glew.h" 3
extern "C" void glDrawArrays(GLenum, GLint, GLsizei);
# 856 "/usr/include/GL/glew.h" 3
extern "C" void glDrawBuffer(GLenum);
# 857 "/usr/include/GL/glew.h" 3
extern "C" void glDrawElements(GLenum, GLsizei, GLenum, const GLvoid *);
# 858 "/usr/include/GL/glew.h" 3
extern "C" void glDrawPixels(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
# 859 "/usr/include/GL/glew.h" 3
extern "C" void glEdgeFlag(GLboolean);
# 860 "/usr/include/GL/glew.h" 3
extern "C" void glEdgeFlagPointer(GLsizei, const GLvoid *);
# 861 "/usr/include/GL/glew.h" 3
extern "C" void glEdgeFlagv(const GLboolean *);
# 862 "/usr/include/GL/glew.h" 3
extern "C" void glEnable(GLenum);
# 863 "/usr/include/GL/glew.h" 3
extern "C" void glEnableClientState(GLenum);
# 864 "/usr/include/GL/glew.h" 3
extern "C" void glEnd();
# 865 "/usr/include/GL/glew.h" 3
extern "C" void glEndList();
# 866 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord1d(GLdouble);
# 867 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord1dv(const GLdouble *);
# 868 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord1f(GLfloat);
# 869 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord1fv(const GLfloat *);
# 870 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord2d(GLdouble, GLdouble);
# 871 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord2dv(const GLdouble *);
# 872 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord2f(GLfloat, GLfloat);
# 873 "/usr/include/GL/glew.h" 3
extern "C" void glEvalCoord2fv(const GLfloat *);
# 874 "/usr/include/GL/glew.h" 3
extern "C" void glEvalMesh1(GLenum, GLint, GLint);
# 875 "/usr/include/GL/glew.h" 3
extern "C" void glEvalMesh2(GLenum, GLint, GLint, GLint, GLint);
# 876 "/usr/include/GL/glew.h" 3
extern "C" void glEvalPoint1(GLint);
# 877 "/usr/include/GL/glew.h" 3
extern "C" void glEvalPoint2(GLint, GLint);
# 878 "/usr/include/GL/glew.h" 3
extern "C" void glFeedbackBuffer(GLsizei, GLenum, GLfloat *);
# 879 "/usr/include/GL/glew.h" 3
extern "C" void glFinish();
# 880 "/usr/include/GL/glew.h" 3
extern "C" void glFlush();
# 881 "/usr/include/GL/glew.h" 3
extern "C" void glFogf(GLenum, GLfloat);
# 882 "/usr/include/GL/glew.h" 3
extern "C" void glFogfv(GLenum, const GLfloat *);
# 883 "/usr/include/GL/glew.h" 3
extern "C" void glFogi(GLenum, GLint);
# 884 "/usr/include/GL/glew.h" 3
extern "C" void glFogiv(GLenum, const GLint *);
# 885 "/usr/include/GL/glew.h" 3
extern "C" void glFrontFace(GLenum);
# 886 "/usr/include/GL/glew.h" 3
extern "C" void glFrustum(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 887 "/usr/include/GL/glew.h" 3
extern "C" GLuint glGenLists(GLsizei);
# 888 "/usr/include/GL/glew.h" 3
extern "C" void glGenTextures(GLsizei, GLuint *);
# 889 "/usr/include/GL/glew.h" 3
extern "C" void glGetBooleanv(GLenum, GLboolean *);
# 890 "/usr/include/GL/glew.h" 3
extern "C" void glGetClipPlane(GLenum, GLdouble *);
# 891 "/usr/include/GL/glew.h" 3
extern "C" void glGetDoublev(GLenum, GLdouble *);
# 892 "/usr/include/GL/glew.h" 3
extern "C" GLenum glGetError();
# 893 "/usr/include/GL/glew.h" 3
extern "C" void glGetFloatv(GLenum, GLfloat *);
# 894 "/usr/include/GL/glew.h" 3
extern "C" void glGetIntegerv(GLenum, GLint *);
# 895 "/usr/include/GL/glew.h" 3
extern "C" void glGetLightfv(GLenum, GLenum, GLfloat *);
# 896 "/usr/include/GL/glew.h" 3
extern "C" void glGetLightiv(GLenum, GLenum, GLint *);
# 897 "/usr/include/GL/glew.h" 3
extern "C" void glGetMapdv(GLenum, GLenum, GLdouble *);
# 898 "/usr/include/GL/glew.h" 3
extern "C" void glGetMapfv(GLenum, GLenum, GLfloat *);
# 899 "/usr/include/GL/glew.h" 3
extern "C" void glGetMapiv(GLenum, GLenum, GLint *);
# 900 "/usr/include/GL/glew.h" 3
extern "C" void glGetMaterialfv(GLenum, GLenum, GLfloat *);
# 901 "/usr/include/GL/glew.h" 3
extern "C" void glGetMaterialiv(GLenum, GLenum, GLint *);
# 902 "/usr/include/GL/glew.h" 3
extern "C" void glGetPixelMapfv(GLenum, GLfloat *);
# 903 "/usr/include/GL/glew.h" 3
extern "C" void glGetPixelMapuiv(GLenum, GLuint *);
# 904 "/usr/include/GL/glew.h" 3
extern "C" void glGetPixelMapusv(GLenum, GLushort *);
# 905 "/usr/include/GL/glew.h" 3
extern "C" void glGetPointerv(GLenum, GLvoid **);
# 906 "/usr/include/GL/glew.h" 3
extern "C" void glGetPolygonStipple(GLubyte *);
# 907 "/usr/include/GL/glew.h" 3
extern "C" const GLubyte *glGetString(GLenum);
# 908 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexEnvfv(GLenum, GLenum, GLfloat *);
# 909 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexEnviv(GLenum, GLenum, GLint *);
# 910 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexGendv(GLenum, GLenum, GLdouble *);
# 911 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexGenfv(GLenum, GLenum, GLfloat *);
# 912 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexGeniv(GLenum, GLenum, GLint *);
# 913 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexImage(GLenum, GLint, GLenum, GLenum, GLvoid *);
# 914 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexLevelParameterfv(GLenum, GLint, GLenum, GLfloat *);
# 915 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexLevelParameteriv(GLenum, GLint, GLenum, GLint *);
# 916 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexParameterfv(GLenum, GLenum, GLfloat *);
# 917 "/usr/include/GL/glew.h" 3
extern "C" void glGetTexParameteriv(GLenum, GLenum, GLint *);
# 918 "/usr/include/GL/glew.h" 3
extern "C" void glHint(GLenum, GLenum);
# 919 "/usr/include/GL/glew.h" 3
extern "C" void glIndexMask(GLuint);
# 920 "/usr/include/GL/glew.h" 3
extern "C" void glIndexPointer(GLenum, GLsizei, const GLvoid *);
# 921 "/usr/include/GL/glew.h" 3
extern "C" void glIndexd(GLdouble);
# 922 "/usr/include/GL/glew.h" 3
extern "C" void glIndexdv(const GLdouble *);
# 923 "/usr/include/GL/glew.h" 3
extern "C" void glIndexf(GLfloat);
# 924 "/usr/include/GL/glew.h" 3
extern "C" void glIndexfv(const GLfloat *);
# 925 "/usr/include/GL/glew.h" 3
extern "C" void glIndexi(GLint);
# 926 "/usr/include/GL/glew.h" 3
extern "C" void glIndexiv(const GLint *);
# 927 "/usr/include/GL/glew.h" 3
extern "C" void glIndexs(GLshort);
# 928 "/usr/include/GL/glew.h" 3
extern "C" void glIndexsv(const GLshort *);
# 929 "/usr/include/GL/glew.h" 3
extern "C" void glIndexub(GLubyte);
# 930 "/usr/include/GL/glew.h" 3
extern "C" void glIndexubv(const GLubyte *);
# 931 "/usr/include/GL/glew.h" 3
extern "C" void glInitNames();
# 932 "/usr/include/GL/glew.h" 3
extern "C" void glInterleavedArrays(GLenum, GLsizei, const GLvoid *);
# 933 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glIsEnabled(GLenum);
# 934 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glIsList(GLuint);
# 935 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glIsTexture(GLuint);
# 936 "/usr/include/GL/glew.h" 3
extern "C" void glLightModelf(GLenum, GLfloat);
# 937 "/usr/include/GL/glew.h" 3
extern "C" void glLightModelfv(GLenum, const GLfloat *);
# 938 "/usr/include/GL/glew.h" 3
extern "C" void glLightModeli(GLenum, GLint);
# 939 "/usr/include/GL/glew.h" 3
extern "C" void glLightModeliv(GLenum, const GLint *);
# 940 "/usr/include/GL/glew.h" 3
extern "C" void glLightf(GLenum, GLenum, GLfloat);
# 941 "/usr/include/GL/glew.h" 3
extern "C" void glLightfv(GLenum, GLenum, const GLfloat *);
# 942 "/usr/include/GL/glew.h" 3
extern "C" void glLighti(GLenum, GLenum, GLint);
# 943 "/usr/include/GL/glew.h" 3
extern "C" void glLightiv(GLenum, GLenum, const GLint *);
# 944 "/usr/include/GL/glew.h" 3
extern "C" void glLineStipple(GLint, GLushort);
# 945 "/usr/include/GL/glew.h" 3
extern "C" void glLineWidth(GLfloat);
# 946 "/usr/include/GL/glew.h" 3
extern "C" void glListBase(GLuint);
# 947 "/usr/include/GL/glew.h" 3
extern "C" void glLoadIdentity();
# 948 "/usr/include/GL/glew.h" 3
extern "C" void glLoadMatrixd(const GLdouble *);
# 949 "/usr/include/GL/glew.h" 3
extern "C" void glLoadMatrixf(const GLfloat *);
# 950 "/usr/include/GL/glew.h" 3
extern "C" void glLoadName(GLuint);
# 951 "/usr/include/GL/glew.h" 3
extern "C" void glLogicOp(GLenum);
# 952 "/usr/include/GL/glew.h" 3
extern "C" void glMap1d(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
# 953 "/usr/include/GL/glew.h" 3
extern "C" void glMap1f(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
# 954 "/usr/include/GL/glew.h" 3
extern "C" void glMap2d(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
# 955 "/usr/include/GL/glew.h" 3
extern "C" void glMap2f(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
# 956 "/usr/include/GL/glew.h" 3
extern "C" void glMapGrid1d(GLint, GLdouble, GLdouble);
# 957 "/usr/include/GL/glew.h" 3
extern "C" void glMapGrid1f(GLint, GLfloat, GLfloat);
# 958 "/usr/include/GL/glew.h" 3
extern "C" void glMapGrid2d(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
# 959 "/usr/include/GL/glew.h" 3
extern "C" void glMapGrid2f(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
# 960 "/usr/include/GL/glew.h" 3
extern "C" void glMaterialf(GLenum, GLenum, GLfloat);
# 961 "/usr/include/GL/glew.h" 3
extern "C" void glMaterialfv(GLenum, GLenum, const GLfloat *);
# 962 "/usr/include/GL/glew.h" 3
extern "C" void glMateriali(GLenum, GLenum, GLint);
# 963 "/usr/include/GL/glew.h" 3
extern "C" void glMaterialiv(GLenum, GLenum, const GLint *);
# 964 "/usr/include/GL/glew.h" 3
extern "C" void glMatrixMode(GLenum);
# 965 "/usr/include/GL/glew.h" 3
extern "C" void glMultMatrixd(const GLdouble *);
# 966 "/usr/include/GL/glew.h" 3
extern "C" void glMultMatrixf(const GLfloat *);
# 967 "/usr/include/GL/glew.h" 3
extern "C" void glNewList(GLuint, GLenum);
# 968 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3b(GLbyte, GLbyte, GLbyte);
# 969 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3bv(const GLbyte *);
# 970 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3d(GLdouble, GLdouble, GLdouble);
# 971 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3dv(const GLdouble *);
# 972 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3f(GLfloat, GLfloat, GLfloat);
# 973 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3fv(const GLfloat *);
# 974 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3i(GLint, GLint, GLint);
# 975 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3iv(const GLint *);
# 976 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3s(GLshort, GLshort, GLshort);
# 977 "/usr/include/GL/glew.h" 3
extern "C" void glNormal3sv(const GLshort *);
# 978 "/usr/include/GL/glew.h" 3
extern "C" void glNormalPointer(GLenum, GLsizei, const GLvoid *);
# 979 "/usr/include/GL/glew.h" 3
extern "C" void glOrtho(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 980 "/usr/include/GL/glew.h" 3
extern "C" void glPassThrough(GLfloat);
# 981 "/usr/include/GL/glew.h" 3
extern "C" void glPixelMapfv(GLenum, GLsizei, const GLfloat *);
# 982 "/usr/include/GL/glew.h" 3
extern "C" void glPixelMapuiv(GLenum, GLsizei, const GLuint *);
# 983 "/usr/include/GL/glew.h" 3
extern "C" void glPixelMapusv(GLenum, GLsizei, const GLushort *);
# 984 "/usr/include/GL/glew.h" 3
extern "C" void glPixelStoref(GLenum, GLfloat);
# 985 "/usr/include/GL/glew.h" 3
extern "C" void glPixelStorei(GLenum, GLint);
# 986 "/usr/include/GL/glew.h" 3
extern "C" void glPixelTransferf(GLenum, GLfloat);
# 987 "/usr/include/GL/glew.h" 3
extern "C" void glPixelTransferi(GLenum, GLint);
# 988 "/usr/include/GL/glew.h" 3
extern "C" void glPixelZoom(GLfloat, GLfloat);
# 989 "/usr/include/GL/glew.h" 3
extern "C" void glPointSize(GLfloat);
# 990 "/usr/include/GL/glew.h" 3
extern "C" void glPolygonMode(GLenum, GLenum);
# 991 "/usr/include/GL/glew.h" 3
extern "C" void glPolygonOffset(GLfloat, GLfloat);
# 992 "/usr/include/GL/glew.h" 3
extern "C" void glPolygonStipple(const GLubyte *);
# 993 "/usr/include/GL/glew.h" 3
extern "C" void glPopAttrib();
# 994 "/usr/include/GL/glew.h" 3
extern "C" void glPopClientAttrib();
# 995 "/usr/include/GL/glew.h" 3
extern "C" void glPopMatrix();
# 996 "/usr/include/GL/glew.h" 3
extern "C" void glPopName();
# 997 "/usr/include/GL/glew.h" 3
extern "C" void glPrioritizeTextures(GLsizei, const GLuint *, const GLclampf *);
# 998 "/usr/include/GL/glew.h" 3
extern "C" void glPushAttrib(GLbitfield);
# 999 "/usr/include/GL/glew.h" 3
extern "C" void glPushClientAttrib(GLbitfield);
# 1000 "/usr/include/GL/glew.h" 3
extern "C" void glPushMatrix();
# 1001 "/usr/include/GL/glew.h" 3
extern "C" void glPushName(GLuint);
# 1002 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2d(GLdouble, GLdouble);
# 1003 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2dv(const GLdouble *);
# 1004 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2f(GLfloat, GLfloat);
# 1005 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2fv(const GLfloat *);
# 1006 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2i(GLint, GLint);
# 1007 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2iv(const GLint *);
# 1008 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2s(GLshort, GLshort);
# 1009 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos2sv(const GLshort *);
# 1010 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3d(GLdouble, GLdouble, GLdouble);
# 1011 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3dv(const GLdouble *);
# 1012 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3f(GLfloat, GLfloat, GLfloat);
# 1013 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3fv(const GLfloat *);
# 1014 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3i(GLint, GLint, GLint);
# 1015 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3iv(const GLint *);
# 1016 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3s(GLshort, GLshort, GLshort);
# 1017 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos3sv(const GLshort *);
# 1018 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1019 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4dv(const GLdouble *);
# 1020 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1021 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4fv(const GLfloat *);
# 1022 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4i(GLint, GLint, GLint, GLint);
# 1023 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4iv(const GLint *);
# 1024 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4s(GLshort, GLshort, GLshort, GLshort);
# 1025 "/usr/include/GL/glew.h" 3
extern "C" void glRasterPos4sv(const GLshort *);
# 1026 "/usr/include/GL/glew.h" 3
extern "C" void glReadBuffer(GLenum);
# 1027 "/usr/include/GL/glew.h" 3
extern "C" void glReadPixels(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
# 1028 "/usr/include/GL/glew.h" 3
extern "C" void glRectd(GLdouble, GLdouble, GLdouble, GLdouble);
# 1029 "/usr/include/GL/glew.h" 3
extern "C" void glRectdv(const GLdouble *, const GLdouble *);
# 1030 "/usr/include/GL/glew.h" 3
extern "C" void glRectf(GLfloat, GLfloat, GLfloat, GLfloat);
# 1031 "/usr/include/GL/glew.h" 3
extern "C" void glRectfv(const GLfloat *, const GLfloat *);
# 1032 "/usr/include/GL/glew.h" 3
extern "C" void glRecti(GLint, GLint, GLint, GLint);
# 1033 "/usr/include/GL/glew.h" 3
extern "C" void glRectiv(const GLint *, const GLint *);
# 1034 "/usr/include/GL/glew.h" 3
extern "C" void glRects(GLshort, GLshort, GLshort, GLshort);
# 1035 "/usr/include/GL/glew.h" 3
extern "C" void glRectsv(const GLshort *, const GLshort *);
# 1036 "/usr/include/GL/glew.h" 3
extern "C" GLint glRenderMode(GLenum);
# 1037 "/usr/include/GL/glew.h" 3
extern "C" void glRotated(GLdouble, GLdouble, GLdouble, GLdouble);
# 1038 "/usr/include/GL/glew.h" 3
extern "C" void glRotatef(GLfloat, GLfloat, GLfloat, GLfloat);
# 1039 "/usr/include/GL/glew.h" 3
extern "C" void glScaled(GLdouble, GLdouble, GLdouble);
# 1040 "/usr/include/GL/glew.h" 3
extern "C" void glScalef(GLfloat, GLfloat, GLfloat);
# 1041 "/usr/include/GL/glew.h" 3
extern "C" void glScissor(GLint, GLint, GLsizei, GLsizei);
# 1042 "/usr/include/GL/glew.h" 3
extern "C" void glSelectBuffer(GLsizei, GLuint *);
# 1043 "/usr/include/GL/glew.h" 3
extern "C" void glShadeModel(GLenum);
# 1044 "/usr/include/GL/glew.h" 3
extern "C" void glStencilFunc(GLenum, GLint, GLuint);
# 1045 "/usr/include/GL/glew.h" 3
extern "C" void glStencilMask(GLuint);
# 1046 "/usr/include/GL/glew.h" 3
extern "C" void glStencilOp(GLenum, GLenum, GLenum);
# 1047 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1d(GLdouble);
# 1048 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1dv(const GLdouble *);
# 1049 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1f(GLfloat);
# 1050 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1fv(const GLfloat *);
# 1051 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1i(GLint);
# 1052 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1iv(const GLint *);
# 1053 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1s(GLshort);
# 1054 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord1sv(const GLshort *);
# 1055 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2d(GLdouble, GLdouble);
# 1056 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2dv(const GLdouble *);
# 1057 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2f(GLfloat, GLfloat);
# 1058 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2fv(const GLfloat *);
# 1059 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2i(GLint, GLint);
# 1060 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2iv(const GLint *);
# 1061 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2s(GLshort, GLshort);
# 1062 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord2sv(const GLshort *);
# 1063 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3d(GLdouble, GLdouble, GLdouble);
# 1064 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3dv(const GLdouble *);
# 1065 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3f(GLfloat, GLfloat, GLfloat);
# 1066 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3fv(const GLfloat *);
# 1067 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3i(GLint, GLint, GLint);
# 1068 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3iv(const GLint *);
# 1069 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3s(GLshort, GLshort, GLshort);
# 1070 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord3sv(const GLshort *);
# 1071 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1072 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4dv(const GLdouble *);
# 1073 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1074 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4fv(const GLfloat *);
# 1075 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4i(GLint, GLint, GLint, GLint);
# 1076 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4iv(const GLint *);
# 1077 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4s(GLshort, GLshort, GLshort, GLshort);
# 1078 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoord4sv(const GLshort *);
# 1079 "/usr/include/GL/glew.h" 3
extern "C" void glTexCoordPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 1080 "/usr/include/GL/glew.h" 3
extern "C" void glTexEnvf(GLenum, GLenum, GLfloat);
# 1081 "/usr/include/GL/glew.h" 3
extern "C" void glTexEnvfv(GLenum, GLenum, const GLfloat *);
# 1082 "/usr/include/GL/glew.h" 3
extern "C" void glTexEnvi(GLenum, GLenum, GLint);
# 1083 "/usr/include/GL/glew.h" 3
extern "C" void glTexEnviv(GLenum, GLenum, const GLint *);
# 1084 "/usr/include/GL/glew.h" 3
extern "C" void glTexGend(GLenum, GLenum, GLdouble);
# 1085 "/usr/include/GL/glew.h" 3
extern "C" void glTexGendv(GLenum, GLenum, const GLdouble *);
# 1086 "/usr/include/GL/glew.h" 3
extern "C" void glTexGenf(GLenum, GLenum, GLfloat);
# 1087 "/usr/include/GL/glew.h" 3
extern "C" void glTexGenfv(GLenum, GLenum, const GLfloat *);
# 1088 "/usr/include/GL/glew.h" 3
extern "C" void glTexGeni(GLenum, GLenum, GLint);
# 1089 "/usr/include/GL/glew.h" 3
extern "C" void glTexGeniv(GLenum, GLenum, const GLint *);
# 1090 "/usr/include/GL/glew.h" 3
extern "C" void glTexImage1D(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
# 1091 "/usr/include/GL/glew.h" 3
extern "C" void glTexImage2D(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
# 1092 "/usr/include/GL/glew.h" 3
extern "C" void glTexParameterf(GLenum, GLenum, GLfloat);
# 1093 "/usr/include/GL/glew.h" 3
extern "C" void glTexParameterfv(GLenum, GLenum, const GLfloat *);
# 1094 "/usr/include/GL/glew.h" 3
extern "C" void glTexParameteri(GLenum, GLenum, GLint);
# 1095 "/usr/include/GL/glew.h" 3
extern "C" void glTexParameteriv(GLenum, GLenum, const GLint *);
# 1096 "/usr/include/GL/glew.h" 3
extern "C" void glTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
# 1097 "/usr/include/GL/glew.h" 3
extern "C" void glTexSubImage2D(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
# 1098 "/usr/include/GL/glew.h" 3
extern "C" void glTranslated(GLdouble, GLdouble, GLdouble);
# 1099 "/usr/include/GL/glew.h" 3
extern "C" void glTranslatef(GLfloat, GLfloat, GLfloat);
# 1100 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2d(GLdouble, GLdouble);
# 1101 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2dv(const GLdouble *);
# 1102 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2f(GLfloat, GLfloat);
# 1103 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2fv(const GLfloat *);
# 1104 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2i(GLint, GLint);
# 1105 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2iv(const GLint *);
# 1106 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2s(GLshort, GLshort);
# 1107 "/usr/include/GL/glew.h" 3
extern "C" void glVertex2sv(const GLshort *);
# 1108 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3d(GLdouble, GLdouble, GLdouble);
# 1109 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3dv(const GLdouble *);
# 1110 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3f(GLfloat, GLfloat, GLfloat);
# 1111 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3fv(const GLfloat *);
# 1112 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3i(GLint, GLint, GLint);
# 1113 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3iv(const GLint *);
# 1114 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3s(GLshort, GLshort, GLshort);
# 1115 "/usr/include/GL/glew.h" 3
extern "C" void glVertex3sv(const GLshort *);
# 1116 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4d(GLdouble, GLdouble, GLdouble, GLdouble);
# 1117 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4dv(const GLdouble *);
# 1118 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat);
# 1119 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4fv(const GLfloat *);
# 1120 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4i(GLint, GLint, GLint, GLint);
# 1121 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4iv(const GLint *);
# 1122 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4s(GLshort, GLshort, GLshort, GLshort);
# 1123 "/usr/include/GL/glew.h" 3
extern "C" void glVertex4sv(const GLshort *);
# 1124 "/usr/include/GL/glew.h" 3
extern "C" void glVertexPointer(GLint, GLenum, GLsizei, const GLvoid *);
# 1125 "/usr/include/GL/glew.h" 3
extern "C" void glViewport(GLint, GLint, GLsizei, GLsizei);
# 270 "/usr/include/GL/glu.h" 3
class GLUnurbs;
# 271 "/usr/include/GL/glu.h" 3
class GLUquadric;
# 272 "/usr/include/GL/glu.h" 3
class GLUtesselator;
# 279 "/usr/include/GL/glu.h" 3
extern "C" { typedef GLUnurbs GLUnurbsObj; }
# 280 "/usr/include/GL/glu.h" 3
extern "C" { typedef GLUquadric GLUquadricObj; }
# 281 "/usr/include/GL/glu.h" 3
extern "C" { typedef GLUtesselator GLUtesselatorObj; }
# 282 "/usr/include/GL/glu.h" 3
extern "C" { typedef GLUtesselator GLUtriangulatorObj; }
# 287 "/usr/include/GL/glu.h" 3
extern "C" { typedef void (*_GLUfuncptr)(void); }
# 289 "/usr/include/GL/glu.h" 3
extern "C" void gluBeginCurve(GLUnurbs *);
# 290 "/usr/include/GL/glu.h" 3
extern "C" void gluBeginPolygon(GLUtesselator *);
# 291 "/usr/include/GL/glu.h" 3
extern "C" void gluBeginSurface(GLUnurbs *);
# 292 "/usr/include/GL/glu.h" 3
extern "C" void gluBeginTrim(GLUnurbs *);
# 293 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild1DMipmapLevels(GLenum, GLint, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 294 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild1DMipmaps(GLenum, GLint, GLsizei, GLenum, GLenum, const void *);
# 295 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild2DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 296 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild2DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
# 297 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild3DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
# 298 "/usr/include/GL/glu.h" 3
extern "C" GLint gluBuild3DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
# 299 "/usr/include/GL/glu.h" 3
extern "C" GLboolean gluCheckExtension(const GLubyte *, const GLubyte *);
# 300 "/usr/include/GL/glu.h" 3
extern "C" void gluCylinder(GLUquadric *, GLdouble, GLdouble, GLdouble, GLint, GLint);
# 301 "/usr/include/GL/glu.h" 3
extern "C" void gluDeleteNurbsRenderer(GLUnurbs *);
# 302 "/usr/include/GL/glu.h" 3
extern "C" void gluDeleteQuadric(GLUquadric *);
# 303 "/usr/include/GL/glu.h" 3
extern "C" void gluDeleteTess(GLUtesselator *);
# 304 "/usr/include/GL/glu.h" 3
extern "C" void gluDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint);
# 305 "/usr/include/GL/glu.h" 3
extern "C" void gluEndCurve(GLUnurbs *);
# 306 "/usr/include/GL/glu.h" 3
extern "C" void gluEndPolygon(GLUtesselator *);
# 307 "/usr/include/GL/glu.h" 3
extern "C" void gluEndSurface(GLUnurbs *);
# 308 "/usr/include/GL/glu.h" 3
extern "C" void gluEndTrim(GLUnurbs *);
# 309 "/usr/include/GL/glu.h" 3
extern "C" const GLubyte *gluErrorString(GLenum);
# 310 "/usr/include/GL/glu.h" 3
extern "C" void gluGetNurbsProperty(GLUnurbs *, GLenum, GLfloat *);
# 311 "/usr/include/GL/glu.h" 3
extern "C" const GLubyte *gluGetString(GLenum);
# 312 "/usr/include/GL/glu.h" 3
extern "C" void gluGetTessProperty(GLUtesselator *, GLenum, GLdouble *);
# 313 "/usr/include/GL/glu.h" 3
extern "C" void gluLoadSamplingMatrices(GLUnurbs *, const GLfloat *, const GLfloat *, const GLint *);
# 314 "/usr/include/GL/glu.h" 3
extern "C" void gluLookAt(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
# 315 "/usr/include/GL/glu.h" 3
extern "C" GLUnurbs *gluNewNurbsRenderer();
# 316 "/usr/include/GL/glu.h" 3
extern "C" GLUquadric *gluNewQuadric();
# 317 "/usr/include/GL/glu.h" 3
extern "C" GLUtesselator *gluNewTess();
# 318 "/usr/include/GL/glu.h" 3
extern "C" void gluNextContour(GLUtesselator *, GLenum);
# 319 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsCallback(GLUnurbs *, GLenum, _GLUfuncptr);
# 320 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsCallbackData(GLUnurbs *, GLvoid *);
# 321 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsCallbackDataEXT(GLUnurbs *, GLvoid *);
# 322 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLenum);
# 323 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsProperty(GLUnurbs *, GLenum, GLfloat);
# 324 "/usr/include/GL/glu.h" 3
extern "C" void gluNurbsSurface(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLint, GLfloat *, GLint, GLint, GLenum);
# 325 "/usr/include/GL/glu.h" 3
extern "C" void gluOrtho2D(GLdouble, GLdouble, GLdouble, GLdouble);
# 326 "/usr/include/GL/glu.h" 3
extern "C" void gluPartialDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble);
# 327 "/usr/include/GL/glu.h" 3
extern "C" void gluPerspective(GLdouble, GLdouble, GLdouble, GLdouble);
# 328 "/usr/include/GL/glu.h" 3
extern "C" void gluPickMatrix(GLdouble, GLdouble, GLdouble, GLdouble, GLint *);
# 329 "/usr/include/GL/glu.h" 3
extern "C" GLint gluProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
# 330 "/usr/include/GL/glu.h" 3
extern "C" void gluPwlCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLenum);
# 331 "/usr/include/GL/glu.h" 3
extern "C" void gluQuadricCallback(GLUquadric *, GLenum, _GLUfuncptr);
# 332 "/usr/include/GL/glu.h" 3
extern "C" void gluQuadricDrawStyle(GLUquadric *, GLenum);
# 333 "/usr/include/GL/glu.h" 3
extern "C" void gluQuadricNormals(GLUquadric *, GLenum);
# 334 "/usr/include/GL/glu.h" 3
extern "C" void gluQuadricOrientation(GLUquadric *, GLenum);
# 335 "/usr/include/GL/glu.h" 3
extern "C" void gluQuadricTexture(GLUquadric *, GLboolean);
# 336 "/usr/include/GL/glu.h" 3
extern "C" GLint gluScaleImage(GLenum, GLsizei, GLsizei, GLenum, const void *, GLsizei, GLsizei, GLenum, GLvoid *);
# 337 "/usr/include/GL/glu.h" 3
extern "C" void gluSphere(GLUquadric *, GLdouble, GLint, GLint);
# 338 "/usr/include/GL/glu.h" 3
extern "C" void gluTessBeginContour(GLUtesselator *);
# 339 "/usr/include/GL/glu.h" 3
extern "C" void gluTessBeginPolygon(GLUtesselator *, GLvoid *);
# 340 "/usr/include/GL/glu.h" 3
extern "C" void gluTessCallback(GLUtesselator *, GLenum, _GLUfuncptr);
# 341 "/usr/include/GL/glu.h" 3
extern "C" void gluTessEndContour(GLUtesselator *);
# 342 "/usr/include/GL/glu.h" 3
extern "C" void gluTessEndPolygon(GLUtesselator *);
# 343 "/usr/include/GL/glu.h" 3
extern "C" void gluTessNormal(GLUtesselator *, GLdouble, GLdouble, GLdouble);
# 344 "/usr/include/GL/glu.h" 3
extern "C" void gluTessProperty(GLUtesselator *, GLenum, GLdouble);
# 345 "/usr/include/GL/glu.h" 3
extern "C" void gluTessVertex(GLUtesselator *, GLdouble *, GLvoid *);
# 346 "/usr/include/GL/glu.h" 3
extern "C" GLint gluUnProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
# 347 "/usr/include/GL/glu.h" 3
extern "C" GLint gluUnProject4(GLdouble, GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble, GLdouble, GLdouble *, GLdouble *, GLdouble *, GLdouble *);
# 1187 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 1188 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
# 1189 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXIMAGE3DPROC)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
# 1190 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 1303 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLACTIVETEXTUREPROC)(GLenum); }
# 1304 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREPROC)(GLenum); }
# 1305 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
# 1306 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 1307 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
# 1308 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 1309 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 1310 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
# 1311 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum, GLint, GLvoid *); }
# 1312 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble [16]); }
# 1313 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat [16]); }
# 1314 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble [16]); }
# 1315 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat [16]); }
# 1316 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DPROC)(GLenum, GLdouble); }
# 1317 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVPROC)(GLenum, const GLdouble *); }
# 1318 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FPROC)(GLenum, GLfloat); }
# 1319 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVPROC)(GLenum, const GLfloat *); }
# 1320 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IPROC)(GLenum, GLint); }
# 1321 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVPROC)(GLenum, const GLint *); }
# 1322 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SPROC)(GLenum, GLshort); }
# 1323 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVPROC)(GLenum, const GLshort *); }
# 1324 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DPROC)(GLenum, GLdouble, GLdouble); }
# 1325 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVPROC)(GLenum, const GLdouble *); }
# 1326 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FPROC)(GLenum, GLfloat, GLfloat); }
# 1327 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVPROC)(GLenum, const GLfloat *); }
# 1328 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IPROC)(GLenum, GLint, GLint); }
# 1329 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVPROC)(GLenum, const GLint *); }
# 1330 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SPROC)(GLenum, GLshort, GLshort); }
# 1331 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVPROC)(GLenum, const GLshort *); }
# 1332 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 1333 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVPROC)(GLenum, const GLdouble *); }
# 1334 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 1335 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVPROC)(GLenum, const GLfloat *); }
# 1336 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IPROC)(GLenum, GLint, GLint, GLint); }
# 1337 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVPROC)(GLenum, const GLint *); }
# 1338 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SPROC)(GLenum, GLshort, GLshort, GLshort); }
# 1339 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVPROC)(GLenum, const GLshort *); }
# 1340 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 1341 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVPROC)(GLenum, const GLdouble *); }
# 1342 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 1343 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVPROC)(GLenum, const GLfloat *); }
# 1344 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 1345 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVPROC)(GLenum, const GLint *); }
# 1346 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 1347 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVPROC)(GLenum, const GLshort *); }
# 1348 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEPROC)(GLclampf, GLboolean); }
# 1446 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
# 1447 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONPROC)(GLenum); }
# 1448 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
# 1449 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERPROC)(GLenum, GLsizei, const GLvoid *); }
# 1450 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDDPROC)(GLdouble); }
# 1451 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDDVPROC)(const GLdouble *); }
# 1452 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDFPROC)(GLfloat); }
# 1453 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDFVPROC)(const GLfloat *); }
# 1454 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
# 1455 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSPROC)(GLenum, GLsizei *, GLenum, const GLvoid **, GLsizei); }
# 1456 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFPROC)(GLenum, GLfloat); }
# 1457 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVPROC)(GLenum, GLfloat *); }
# 1458 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERIPROC)(GLenum, GLint); }
# 1459 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVPROC)(GLenum, GLint *); }
# 1460 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BPROC)(GLbyte, GLbyte, GLbyte); }
# 1461 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *); }
# 1462 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DPROC)(GLdouble, GLdouble, GLdouble); }
# 1463 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *); }
# 1464 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FPROC)(GLfloat, GLfloat, GLfloat); }
# 1465 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *); }
# 1466 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IPROC)(GLint, GLint, GLint); }
# 1467 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVPROC)(const GLint *); }
# 1468 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SPROC)(GLshort, GLshort, GLshort); }
# 1469 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *); }
# 1470 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBPROC)(GLubyte, GLubyte, GLubyte); }
# 1471 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *); }
# 1472 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIPROC)(GLuint, GLuint, GLuint); }
# 1473 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *); }
# 1474 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USPROC)(GLushort, GLushort, GLushort); }
# 1475 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *); }
# 1476 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERPROC)(GLint, GLenum, GLsizei, GLvoid *); }
# 1477 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DPROC)(GLdouble, GLdouble); }
# 1478 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DVPROC)(const GLdouble *); }
# 1479 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FPROC)(GLfloat, GLfloat); }
# 1480 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FVPROC)(const GLfloat *); }
# 1481 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IPROC)(GLint, GLint); }
# 1482 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IVPROC)(const GLint *); }
# 1483 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SPROC)(GLshort, GLshort); }
# 1484 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SVPROC)(const GLshort *); }
# 1485 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DPROC)(GLdouble, GLdouble, GLdouble); }
# 1486 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DVPROC)(const GLdouble *); }
# 1487 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FPROC)(GLfloat, GLfloat, GLfloat); }
# 1488 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FVPROC)(const GLfloat *); }
# 1489 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IPROC)(GLint, GLint, GLint); }
# 1490 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IVPROC)(const GLint *); }
# 1491 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SPROC)(GLshort, GLshort, GLshort); }
# 1492 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SVPROC)(const GLshort *); }
# 1602 "/usr/include/GL/glew.h" 3
extern "C" { typedef ptrdiff_t GLsizeiptr; }
# 1603 "/usr/include/GL/glew.h" 3
extern "C" { typedef ptrdiff_t GLintptr; }
# 1605 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINQUERYPROC)(GLenum, GLuint); }
# 1606 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFERPROC)(GLenum, GLuint); }
# 1607 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, const GLvoid *, GLenum); }
# 1608 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const GLvoid *); }
# 1609 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei, const GLuint *); }
# 1610 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEQUERIESPROC)(GLsizei, const GLuint *); }
# 1611 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDQUERYPROC)(GLenum); }
# 1612 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENBUFFERSPROC)(GLsizei, GLuint *); }
# 1613 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENQUERIESPROC)(GLsizei, GLuint *); }
# 1614 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 1615 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVPROC)(GLenum, GLenum, GLvoid **); }
# 1616 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, GLvoid *); }
# 1617 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVPROC)(GLuint, GLenum, GLint *); }
# 1618 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVPROC)(GLuint, GLenum, GLuint *); }
# 1619 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYIVPROC)(GLenum, GLenum, GLint *); }
# 1620 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISBUFFERPROC)(GLuint); }
# 1621 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISQUERYPROC)(GLuint); }
# 1622 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERPROC)(GLenum, GLenum); }
# 1623 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERPROC)(GLenum); }
# 1739 "/usr/include/GL/glew.h" 3
extern "C" { typedef char GLchar; }
# 1741 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLATTACHSHADERPROC)(GLuint, GLuint); }
# 1742 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONPROC)(GLuint, GLuint, const GLchar *); }
# 1743 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum, GLenum); }
# 1744 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPILESHADERPROC)(GLuint); }
# 1745 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLCREATEPROGRAMPROC)(void); }
# 1746 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum); }
# 1747 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEPROGRAMPROC)(GLuint); }
# 1748 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETESHADERPROC)(GLuint); }
# 1749 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDETACHSHADERPROC)(GLuint, GLuint); }
# 1750 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint); }
# 1751 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERSPROC)(GLsizei, const GLenum *); }
# 1752 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint); }
# 1753 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
# 1754 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
# 1755 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETATTACHEDSHADERSPROC)(GLuint, GLsizei, GLsizei *, GLuint *); }
# 1756 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONPROC)(GLuint, const GLchar *); }
# 1757 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
# 1758 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint *); }
# 1759 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
# 1760 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSHADERSOURCEPROC)(GLint, GLsizei, GLsizei *, GLchar *); }
# 1761 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint *); }
# 1762 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONPROC)(GLint, const GLchar *); }
# 1763 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMFVPROC)(GLuint, GLint, GLfloat *); }
# 1764 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMIVPROC)(GLuint, GLint, GLint *); }
# 1765 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint, GLenum, GLvoid *); }
# 1766 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVPROC)(GLuint, GLenum, GLdouble *); }
# 1767 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVPROC)(GLuint, GLenum, GLfloat *); }
# 1768 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVPROC)(GLuint, GLenum, GLint *); }
# 1769 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISPROGRAMPROC)(GLuint); }
# 1770 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISSHADERPROC)(GLuint); }
# 1771 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLINKPROGRAMPROC)(GLuint); }
# 1772 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar **, const GLint *); }
# 1773 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEPROC)(GLenum, GLenum, GLint, GLuint); }
# 1774 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTENCILMASKSEPARATEPROC)(GLenum, GLuint); }
# 1775 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
# 1776 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1FPROC)(GLint, GLfloat); }
# 1777 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1FVPROC)(GLint, GLsizei, const GLfloat *); }
# 1778 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1IPROC)(GLint, GLint); }
# 1779 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1IVPROC)(GLint, GLsizei, const GLint *); }
# 1780 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2FPROC)(GLint, GLfloat, GLfloat); }
# 1781 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2FVPROC)(GLint, GLsizei, const GLfloat *); }
# 1782 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2IPROC)(GLint, GLint, GLint); }
# 1783 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2IVPROC)(GLint, GLsizei, const GLint *); }
# 1784 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3FPROC)(GLint, GLfloat, GLfloat, GLfloat); }
# 1785 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3FVPROC)(GLint, GLsizei, const GLfloat *); }
# 1786 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3IPROC)(GLint, GLint, GLint, GLint); }
# 1787 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3IVPROC)(GLint, GLsizei, const GLint *); }
# 1788 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4FPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 1789 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4FVPROC)(GLint, GLsizei, const GLfloat *); }
# 1790 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4IPROC)(GLint, GLint, GLint, GLint, GLint); }
# 1791 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4IVPROC)(GLint, GLsizei, const GLint *); }
# 1792 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1793 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1794 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1795 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUSEPROGRAMPROC)(GLuint); }
# 1796 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMPROC)(GLuint); }
# 1797 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DPROC)(GLuint, GLdouble); }
# 1798 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVPROC)(GLuint, const GLdouble *); }
# 1799 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FPROC)(GLuint, GLfloat); }
# 1800 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVPROC)(GLuint, const GLfloat *); }
# 1801 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SPROC)(GLuint, GLshort); }
# 1802 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVPROC)(GLuint, const GLshort *); }
# 1803 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DPROC)(GLuint, GLdouble, GLdouble); }
# 1804 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVPROC)(GLuint, const GLdouble *); }
# 1805 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FPROC)(GLuint, GLfloat, GLfloat); }
# 1806 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVPROC)(GLuint, const GLfloat *); }
# 1807 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SPROC)(GLuint, GLshort, GLshort); }
# 1808 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVPROC)(GLuint, const GLshort *); }
# 1809 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 1810 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVPROC)(GLuint, const GLdouble *); }
# 1811 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 1812 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVPROC)(GLuint, const GLfloat *); }
# 1813 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SPROC)(GLuint, GLshort, GLshort, GLshort); }
# 1814 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVPROC)(GLuint, const GLshort *); }
# 1815 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVPROC)(GLuint, const GLbyte *); }
# 1816 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVPROC)(GLuint, const GLint *); }
# 1817 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVPROC)(GLuint, const GLshort *); }
# 1818 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 1819 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVPROC)(GLuint, const GLubyte *); }
# 1820 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVPROC)(GLuint, const GLuint *); }
# 1821 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVPROC)(GLuint, const GLushort *); }
# 1822 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVPROC)(GLuint, const GLbyte *); }
# 1823 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 1824 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVPROC)(GLuint, const GLdouble *); }
# 1825 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 1826 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVPROC)(GLuint, const GLfloat *); }
# 1827 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVPROC)(GLuint, const GLint *); }
# 1828 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 1829 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVPROC)(GLuint, const GLshort *); }
# 1830 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVPROC)(GLuint, const GLubyte *); }
# 1831 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVPROC)(GLuint, const GLuint *); }
# 1832 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVPROC)(GLuint, const GLushort *); }
# 1833 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *); }
# 1962 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1963 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1964 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1965 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1966 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1967 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 1999 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTBUFFERMASK3DFXPROC)(GLuint); }
# 2039 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum, GLint, GLsizei); }
# 2040 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, GLint, GLsizei); }
# 2041 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLELEMENTPOINTERAPPLEPROC)(GLenum, const void *); }
# 2042 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum, const GLint *, const GLsizei *, GLsizei); }
# 2043 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei); }
# 2063 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEFENCESAPPLEPROC)(GLsizei, const GLuint *); }
# 2064 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFINISHFENCEAPPLEPROC)(GLuint); }
# 2065 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFINISHOBJECTAPPLEPROC)(GLenum, GLint); }
# 2066 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENFENCESAPPLEPROC)(GLsizei, GLuint *); }
# 2067 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISFENCEAPPLEPROC)(GLuint); }
# 2068 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSETFENCEAPPLEPROC)(GLuint); }
# 2069 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLTESTFENCEAPPLEPROC)(GLuint); }
# 2070 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLTESTOBJECTAPPLEPROC)(GLenum, GLuint); }
# 2117 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBUFFERPARAMETERIAPPLEPROC)(GLenum, GLenum, GLint); }
# 2118 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)(GLenum, GLintptr, GLsizeiptr); }
# 2161 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)(GLenum, GLenum, GLvoid **); }
# 2162 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXTURERANGEAPPLEPROC)(GLenum, GLsizei, GLvoid *); }
# 2189 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint); }
# 2190 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
# 2191 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
# 2192 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISVERTEXARRAYAPPLEPROC)(GLuint); }
# 2216 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei, void *); }
# 2217 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum, GLint); }
# 2218 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei, void *); }
# 2252 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLAMPCOLORARBPROC)(GLenum, GLenum); }
# 2298 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERSARBPROC)(GLsizei, const GLenum *); }
# 2447 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORSUBTABLEPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 2448 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 2449 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
# 2450 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
# 2451 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
# 2452 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 2453 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum, GLenum, GLfloat); }
# 2454 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
# 2455 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum, GLenum, GLint); }
# 2456 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
# 2457 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
# 2458 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCOLORTABLEPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 2459 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 2460 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
# 2461 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 2462 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 2463 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 2464 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *); }
# 2465 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 2466 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 2467 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 2468 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 2469 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 2470 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
# 2471 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
# 2472 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
# 2473 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *); }
# 2474 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLHISTOGRAMPROC)(GLenum, GLsizei, GLenum, GLboolean); }
# 2475 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMINMAXPROC)(GLenum, GLenum, GLboolean); }
# 2476 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRESETHISTOGRAMPROC)(GLenum); }
# 2477 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRESETMINMAXPROC)(GLenum); }
# 2478 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *); }
# 2533 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint); }
# 2534 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMATRIXINDEXPOINTERARBPROC)(GLint, GLenum, GLsizei, GLvoid *); }
# 2535 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMATRIXINDEXUBVARBPROC)(GLint, GLubyte *); }
# 2536 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMATRIXINDEXUIVARBPROC)(GLint, GLuint *); }
# 2537 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMATRIXINDEXUSVARBPROC)(GLint, GLushort *); }
# 2564 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEARBPROC)(GLclampf, GLboolean); }
# 2613 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLACTIVETEXTUREARBPROC)(GLenum); }
# 2614 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum); }
# 2615 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DARBPROC)(GLenum, GLdouble); }
# 2616 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVARBPROC)(GLenum, const GLdouble *); }
# 2617 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FARBPROC)(GLenum, GLfloat); }
# 2618 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVARBPROC)(GLenum, const GLfloat *); }
# 2619 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IARBPROC)(GLenum, GLint); }
# 2620 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVARBPROC)(GLenum, const GLint *); }
# 2621 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SARBPROC)(GLenum, GLshort); }
# 2622 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVARBPROC)(GLenum, const GLshort *); }
# 2623 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DARBPROC)(GLenum, GLdouble, GLdouble); }
# 2624 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVARBPROC)(GLenum, const GLdouble *); }
# 2625 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FARBPROC)(GLenum, GLfloat, GLfloat); }
# 2626 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVARBPROC)(GLenum, const GLfloat *); }
# 2627 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IARBPROC)(GLenum, GLint, GLint); }
# 2628 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVARBPROC)(GLenum, const GLint *); }
# 2629 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SARBPROC)(GLenum, GLshort, GLshort); }
# 2630 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVARBPROC)(GLenum, const GLshort *); }
# 2631 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 2632 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVARBPROC)(GLenum, const GLdouble *); }
# 2633 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 2634 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVARBPROC)(GLenum, const GLfloat *); }
# 2635 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IARBPROC)(GLenum, GLint, GLint, GLint); }
# 2636 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVARBPROC)(GLenum, const GLint *); }
# 2637 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SARBPROC)(GLenum, GLshort, GLshort, GLshort); }
# 2638 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVARBPROC)(GLenum, const GLshort *); }
# 2639 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 2640 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVARBPROC)(GLenum, const GLdouble *); }
# 2641 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 2642 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVARBPROC)(GLenum, const GLfloat *); }
# 2643 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IARBPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 2644 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVARBPROC)(GLenum, const GLint *); }
# 2645 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SARBPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 2646 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVARBPROC)(GLenum, const GLshort *); }
# 2698 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINQUERYARBPROC)(GLenum, GLuint); }
# 2699 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEQUERIESARBPROC)(GLsizei, const GLuint *); }
# 2700 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDQUERYARBPROC)(GLenum); }
# 2701 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENQUERIESARBPROC)(GLsizei, GLuint *); }
# 2702 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVARBPROC)(GLuint, GLenum, GLint *); }
# 2703 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint, GLenum, GLuint *); }
# 2704 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYIVARBPROC)(GLenum, GLenum, GLint *); }
# 2705 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISQUERYARBPROC)(GLuint); }
# 2744 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFARBPROC)(GLenum, GLfloat); }
# 2745 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVARBPROC)(GLenum, GLfloat *); }
# 2806 "/usr/include/GL/glew.h" 3
extern "C" { typedef char GLcharARB; }
# 2807 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned GLhandleARB; }
# 2809 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLATTACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
# 2810 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPILESHADERARBPROC)(GLhandleARB); }
# 2811 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLhandleARB (*PFNGLCREATEPROGRAMOBJECTARBPROC)(void); }
# 2812 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLhandleARB (*PFNGLCREATESHADEROBJECTARBPROC)(GLenum); }
# 2813 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEOBJECTARBPROC)(GLhandleARB); }
# 2814 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDETACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
# 2815 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
# 2816 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *); }
# 2817 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLhandleARB (*PFNGLGETHANDLEARBPROC)(GLenum); }
# 2818 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETINFOLOGARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
# 2819 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB, GLenum, GLfloat *); }
# 2820 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB, GLenum, GLint *); }
# 2821 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
# 2822 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
# 2823 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMFVARBPROC)(GLhandleARB, GLint, GLfloat *); }
# 2824 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMIVARBPROC)(GLhandleARB, GLint, GLint *); }
# 2825 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLINKPROGRAMARBPROC)(GLhandleARB); }
# 2826 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *); }
# 2827 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1FARBPROC)(GLint, GLfloat); }
# 2828 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 2829 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1IARBPROC)(GLint, GLint); }
# 2830 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1IVARBPROC)(GLint, GLsizei, const GLint *); }
# 2831 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2FARBPROC)(GLint, GLfloat, GLfloat); }
# 2832 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 2833 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2IARBPROC)(GLint, GLint, GLint); }
# 2834 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2IVARBPROC)(GLint, GLsizei, const GLint *); }
# 2835 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3FARBPROC)(GLint, GLfloat, GLfloat, GLfloat); }
# 2836 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 2837 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3IARBPROC)(GLint, GLint, GLint, GLint); }
# 2838 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3IVARBPROC)(GLint, GLsizei, const GLint *); }
# 2839 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4FARBPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 2840 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4FVARBPROC)(GLint, GLsizei, const GLfloat *); }
# 2841 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4IARBPROC)(GLint, GLint, GLint, GLint, GLint); }
# 2842 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4IVARBPROC)(GLint, GLsizei, const GLint *); }
# 2843 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 2844 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 2845 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 2846 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB); }
# 2847 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB); }
# 2956 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *); }
# 2957 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *); }
# 2958 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *); }
# 2959 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *); }
# 2960 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *); }
# 2961 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *); }
# 2962 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum, GLint, void *); }
# 3136 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDARBPROC)(GLdouble [16]); }
# 3137 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFARBPROC)(GLfloat [16]); }
# 3138 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDARBPROC)(GLdouble [16]); }
# 3139 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFARBPROC)(GLfloat [16]); }
# 3198 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXBLENDARBPROC)(GLint); }
# 3199 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTPOINTERARBPROC)(GLint, GLenum, GLsizei, GLvoid *); }
# 3200 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTBVARBPROC)(GLint, GLbyte *); }
# 3201 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTDVARBPROC)(GLint, GLdouble *); }
# 3202 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTFVARBPROC)(GLint, GLfloat *); }
# 3203 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTIVARBPROC)(GLint, GLint *); }
# 3204 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTSVARBPROC)(GLint, GLshort *); }
# 3205 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTUBVARBPROC)(GLint, GLubyte *); }
# 3206 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTUIVARBPROC)(GLint, GLuint *); }
# 3207 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWEIGHTUSVARBPROC)(GLint, GLushort *); }
# 3261 "/usr/include/GL/glew.h" 3
extern "C" { typedef ptrdiff_t GLsizeiptrARB; }
# 3262 "/usr/include/GL/glew.h" 3
extern "C" { typedef ptrdiff_t GLintptrARB; }
# 3264 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFERARBPROC)(GLenum, GLuint); }
# 3265 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBUFFERDATAARBPROC)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum); }
# 3266 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *); }
# 3267 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEBUFFERSARBPROC)(GLsizei, const GLuint *); }
# 3268 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENBUFFERSARBPROC)(GLsizei, GLuint *); }
# 3269 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum, GLenum, GLint *); }
# 3270 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVARBPROC)(GLenum, GLenum, GLvoid **); }
# 3271 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *); }
# 3272 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISBUFFERARBPROC)(GLuint); }
# 3273 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERARBPROC)(GLenum, GLenum); }
# 3274 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERARBPROC)(GLenum); }
# 3377 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDPROGRAMARBPROC)(GLenum, GLuint); }
# 3378 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEPROGRAMSARBPROC)(GLsizei, const GLuint *); }
# 3379 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
# 3380 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
# 3381 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENPROGRAMSARBPROC)(GLsizei, GLuint *); }
# 3382 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
# 3383 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
# 3384 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
# 3385 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
# 3386 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGARBPROC)(GLenum, GLenum, void *); }
# 3387 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMIVARBPROC)(GLenum, GLenum, GLint *); }
# 3388 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint, GLenum, GLvoid **); }
# 3389 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint, GLenum, GLdouble *); }
# 3390 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint, GLenum, GLfloat *); }
# 3391 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint, GLenum, GLint *); }
# 3392 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISPROGRAMARBPROC)(GLuint); }
# 3393 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3394 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
# 3395 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3396 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
# 3397 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3398 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
# 3399 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3400 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
# 3401 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMSTRINGARBPROC)(GLenum, GLenum, GLsizei, const void *); }
# 3402 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DARBPROC)(GLuint, GLdouble); }
# 3403 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVARBPROC)(GLuint, const GLdouble *); }
# 3404 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FARBPROC)(GLuint, GLfloat); }
# 3405 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVARBPROC)(GLuint, const GLfloat *); }
# 3406 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SARBPROC)(GLuint, GLshort); }
# 3407 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVARBPROC)(GLuint, const GLshort *); }
# 3408 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DARBPROC)(GLuint, GLdouble, GLdouble); }
# 3409 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVARBPROC)(GLuint, const GLdouble *); }
# 3410 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FARBPROC)(GLuint, GLfloat, GLfloat); }
# 3411 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVARBPROC)(GLuint, const GLfloat *); }
# 3412 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SARBPROC)(GLuint, GLshort, GLshort); }
# 3413 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVARBPROC)(GLuint, const GLshort *); }
# 3414 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 3415 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVARBPROC)(GLuint, const GLdouble *); }
# 3416 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 3417 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVARBPROC)(GLuint, const GLfloat *); }
# 3418 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SARBPROC)(GLuint, GLshort, GLshort, GLshort); }
# 3419 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVARBPROC)(GLuint, const GLshort *); }
# 3420 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint, const GLbyte *); }
# 3421 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint, const GLint *); }
# 3422 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint, const GLshort *); }
# 3423 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 3424 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint, const GLubyte *); }
# 3425 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint, const GLuint *); }
# 3426 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint, const GLushort *); }
# 3427 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVARBPROC)(GLuint, const GLbyte *); }
# 3428 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 3429 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVARBPROC)(GLuint, const GLdouble *); }
# 3430 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 3431 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVARBPROC)(GLuint, const GLfloat *); }
# 3432 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVARBPROC)(GLuint, const GLint *); }
# 3433 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SARBPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 3434 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVARBPROC)(GLuint, const GLshort *); }
# 3435 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint, const GLubyte *); }
# 3436 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint, const GLuint *); }
# 3437 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVARBPROC)(GLuint, const GLushort *); }
# 3438 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *); }
# 3520 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB, GLuint, const GLcharARB *); }
# 3521 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
# 3522 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
# 3537 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DARBPROC)(GLdouble, GLdouble); }
# 3538 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *); }
# 3539 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FARBPROC)(GLfloat, GLfloat); }
# 3540 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *); }
# 3541 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IARBPROC)(GLint, GLint); }
# 3542 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IVARBPROC)(const GLint *); }
# 3543 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SARBPROC)(GLshort, GLshort); }
# 3544 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SVARBPROC)(const GLshort *); }
# 3545 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DARBPROC)(GLdouble, GLdouble, GLdouble); }
# 3546 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *); }
# 3547 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FARBPROC)(GLfloat, GLfloat, GLfloat); }
# 3548 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *); }
# 3549 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IARBPROC)(GLint, GLint, GLint); }
# 3550 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IVARBPROC)(const GLint *); }
# 3551 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SARBPROC)(GLshort, GLshort, GLshort); }
# 3552 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SVARBPROC)(const GLshort *); }
# 3651 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERSATIPROC)(GLsizei, const GLenum *); }
# 3668 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYATIPROC)(GLenum, GLsizei); }
# 3669 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum, GLuint, GLuint, GLsizei); }
# 3670 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLELEMENTPOINTERATIPROC)(GLenum, const void *); }
# 3694 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum, GLfloat *); }
# 3695 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum, GLint *); }
# 3696 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum, GLfloat *); }
# 3697 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum, GLint *); }
# 3768 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3769 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3770 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3771 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINFRAGMENTSHADERATIPROC)(void); }
# 3772 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint); }
# 3773 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3774 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3775 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 3776 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint); }
# 3777 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDFRAGMENTSHADERATIPROC)(void); }
# 3778 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint); }
# 3779 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPASSTEXCOORDATIPROC)(GLuint, GLuint, GLenum); }
# 3780 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLEMAPATIPROC)(GLuint, GLuint, GLenum); }
# 3781 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint, const GLfloat *); }
# 3807 "/usr/include/GL/glew.h" 3
extern "C" { typedef void *(*PFNGLMAPOBJECTBUFFERATIPROC)(GLuint); }
# 3808 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint); }
# 3832 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPNTRIANGLESFATIPROC)(GLenum, GLfloat); }
# 3833 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPNTRIANGLESIATIPROC)(GLenum, GLint); }
# 3852 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum, GLenum, GLint, GLuint); }
# 3853 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEATIPROC)(GLenum, GLenum, GLenum, GLenum); }
# 3954 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLARRAYOBJECTATIPROC)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint); }
# 3955 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFREEOBJECTBUFFERATIPROC)(GLuint); }
# 3956 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETARRAYOBJECTFVATIPROC)(GLenum, GLenum, GLfloat *); }
# 3957 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETARRAYOBJECTIVATIPROC)(GLenum, GLenum, GLint *); }
# 3958 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 3959 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint, GLenum, GLint *); }
# 3960 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 3961 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 3962 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISOBJECTBUFFERATIPROC)(GLuint); }
# 3963 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei, const void *, GLenum); }
# 3964 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint, GLuint, GLsizei, const void *, GLenum); }
# 3965 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint, GLenum, GLsizei, GLuint, GLuint); }
# 3989 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
# 3990 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 3991 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint); }
# 4017 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum); }
# 4018 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3BATIPROC)(GLenum, GLbyte, GLbyte, GLbyte); }
# 4019 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3BVATIPROC)(GLenum, const GLbyte *); }
# 4020 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 4021 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
# 4022 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 4023 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
# 4024 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
# 4025 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3IVATIPROC)(GLenum, const GLint *); }
# 4026 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
# 4027 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALSTREAM3SVATIPROC)(GLenum, const GLshort *); }
# 4028 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXBLENDENVFATIPROC)(GLenum, GLfloat); }
# 4029 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXBLENDENVIATIPROC)(GLenum, GLint); }
# 4030 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DATIPROC)(GLenum, GLdouble, GLdouble); }
# 4031 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DVATIPROC)(GLenum, const GLdouble *); }
# 4032 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FATIPROC)(GLenum, GLfloat, GLfloat); }
# 4033 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FVATIPROC)(GLenum, const GLfloat *); }
# 4034 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IATIPROC)(GLenum, GLint, GLint); }
# 4035 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IVATIPROC)(GLenum, const GLint *); }
# 4036 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SATIPROC)(GLenum, GLshort, GLshort); }
# 4037 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SVATIPROC)(GLenum, const GLshort *); }
# 4038 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
# 4039 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
# 4040 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
# 4041 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
# 4042 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
# 4043 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IVATIPROC)(GLenum, const GLint *); }
# 4044 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
# 4045 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SVATIPROC)(GLenum, const GLshort *); }
# 4046 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
# 4047 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DVATIPROC)(GLenum, const GLdouble *); }
# 4048 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
# 4049 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FVATIPROC)(GLenum, const GLfloat *); }
# 4050 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IATIPROC)(GLenum, GLint, GLint, GLint, GLint); }
# 4051 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IVATIPROC)(GLenum, const GLint *); }
# 4052 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SATIPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
# 4053 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SVATIPROC)(GLenum, const GLshort *); }
# 4158 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint, GLint); }
# 4159 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLintptr (*PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint, GLint); }
# 4160 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORMBUFFEREXTPROC)(GLuint, GLint, GLuint); }
# 4181 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDCOLOREXTPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
# 4197 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum, GLenum); }
# 4215 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum, GLenum, GLenum, GLenum); }
# 4242 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONEXTPROC)(GLenum); }
# 4292 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *); }
# 4293 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
# 4307 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOCKARRAYSEXTPROC)(GLint, GLsizei); }
# 4308 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNLOCKARRAYSEXTPROC)(void); }
# 4343 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *); }
# 4344 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *); }
# 4345 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum, GLenum, GLfloat); }
# 4346 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 4347 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum, GLenum, GLint); }
# 4348 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 4349 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 4350 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
# 4351 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum, GLenum, GLenum, void *); }
# 4352 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4353 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4354 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum, GLenum, GLenum, void *, void *, void *); }
# 4355 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *, const void *); }
# 4395 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINORMALPOINTEREXTPROC)(GLenum, GLsizei, void *); }
# 4396 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTANGENTPOINTEREXTPROC)(GLenum, GLsizei, void *); }
# 4410 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint); }
# 4411 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint); }
# 4412 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei); }
# 4413 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 4414 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 4431 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCULLPARAMETERDVEXTPROC)(GLenum, GLdouble *); }
# 4432 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCULLPARAMETERFVEXTPROC)(GLenum, GLfloat *); }
# 4449 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDEPTHBOUNDSEXTPROC)(GLclampd, GLclampd); }
# 4462 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean); }
# 4463 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDISABLEINDEXEDEXTPROC)(GLenum, GLuint); }
# 4464 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENABLEINDEXEDEXTPROC)(GLenum, GLuint); }
# 4465 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum, GLuint, GLboolean *); }
# 4466 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum, GLuint, GLint *); }
# 4467 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISENABLEDINDEXEDEXTPROC)(GLenum, GLuint); }
# 4485 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum, GLint, GLsizei, GLsizei); }
# 4486 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei); }
# 4503 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
# 4525 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 4526 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDDEXTPROC)(GLdouble); }
# 4527 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDDVEXTPROC)(const GLdouble *); }
# 4528 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDFEXTPROC)(GLfloat); }
# 4529 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDFVEXTPROC)(const GLfloat *); }
# 4561 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTCOLORMATERIALEXTPROC)(GLenum, GLenum); }
# 4562 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFEXTPROC)(GLenum, GLfloat); }
# 4563 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFVEXTPROC)(GLenum, GLfloat *); }
# 4564 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELIEXTPROC)(GLenum, GLint); }
# 4565 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELIVEXTPROC)(GLenum, GLint *); }
# 4566 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFEXTPROC)(GLenum, GLenum, GLfloat); }
# 4567 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4568 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTIEXTPROC)(GLenum, GLenum, GLint); }
# 4569 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4570 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFEXTPROC)(GLenum, GLenum, const GLfloat); }
# 4571 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 4572 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALIEXTPROC)(GLenum, GLenum, const GLint); }
# 4573 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 4574 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4575 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4576 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 4577 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 4578 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLIGHTENVIEXTPROC)(GLenum, GLint); }
# 4613 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBLITFRAMEBUFFEREXTPROC)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum); }
# 4630 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei); }
# 4695 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum, GLuint); }
# 4696 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDRENDERBUFFEREXTPROC)(GLenum, GLuint); }
# 4697 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum); }
# 4698 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei, const GLuint *); }
# 4699 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei, const GLuint *); }
# 4700 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum, GLenum, GLenum, GLuint); }
# 4701 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
# 4702 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
# 4703 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint, GLint); }
# 4704 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei, GLuint *); }
# 4705 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei, GLuint *); }
# 4706 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENERATEMIPMAPEXTPROC)(GLenum); }
# 4707 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
# 4708 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4709 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISFRAMEBUFFEREXTPROC)(GLuint); }
# 4710 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISRENDERBUFFEREXTPROC)(GLuint); }
# 4711 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum, GLenum, GLsizei, GLsizei); }
# 4773 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum, GLenum, GLuint, GLint); }
# 4774 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum, GLenum, GLuint, GLint, GLenum); }
# 4775 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum, GLenum, GLuint, GLint, GLint); }
# 4776 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint, GLenum, GLint); }
# 4792 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum, GLuint, GLsizei, const GLfloat *); }
# 4793 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum, GLuint, GLsizei, const GLfloat *); }
# 4834 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint, GLuint, const GLchar *); }
# 4835 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint, const GLchar *); }
# 4836 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMUIVEXTPROC)(GLuint, GLint, GLuint *); }
# 4837 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint, GLenum, GLint *); }
# 4838 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint, GLenum, GLuint *); }
# 4839 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1UIEXTPROC)(GLint, GLuint); }
# 4840 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM1UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 4841 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2UIEXTPROC)(GLint, GLuint, GLuint); }
# 4842 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM2UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 4843 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3UIEXTPROC)(GLint, GLuint, GLuint, GLuint); }
# 4844 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM3UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 4845 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4UIEXTPROC)(GLint, GLuint, GLuint, GLuint, GLuint); }
# 4846 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLUNIFORM4UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
# 4847 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint, GLint); }
# 4848 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint, const GLint *); }
# 4849 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint, GLuint); }
# 4850 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint, const GLuint *); }
# 4851 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint, GLint, GLint); }
# 4852 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint, const GLint *); }
# 4853 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint, GLuint, GLuint); }
# 4854 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint, const GLuint *); }
# 4855 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint, GLint, GLint, GLint); }
# 4856 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint, const GLint *); }
# 4857 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
# 4858 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint, const GLuint *); }
# 4859 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint, const GLbyte *); }
# 4860 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint, GLint, GLint, GLint, GLint); }
# 4861 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint, const GLint *); }
# 4862 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint, const GLshort *); }
# 4863 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint, const GLubyte *); }
# 4864 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint, GLuint, GLuint, GLuint, GLuint); }
# 4865 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint, const GLuint *); }
# 4866 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint, const GLushort *); }
# 4867 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
# 4927 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMEXTPROC)(GLenum, GLboolean, GLenum, GLenum, void *); }
# 4928 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4929 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4930 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXEXTPROC)(GLenum, GLboolean, GLenum, GLenum, void *); }
# 4931 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 4932 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 4933 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLHISTOGRAMEXTPROC)(GLenum, GLsizei, GLenum, GLboolean); }
# 4934 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMINMAXEXTPROC)(GLenum, GLenum, GLboolean); }
# 4935 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRESETHISTOGRAMEXTPROC)(GLenum); }
# 4936 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRESETMINMAXEXTPROC)(GLenum); }
# 4967 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLINDEXFUNCEXTPROC)(GLenum, GLfloat); }
# 4980 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLINDEXMATERIALEXTPROC)(GLenum, GLenum); }
# 5013 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLAPPLYTEXTUREEXTPROC)(GLenum); }
# 5014 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXTURELIGHTEXTPROC)(GLenum); }
# 5015 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXTUREMATERIALEXTPROC)(GLenum, GLenum); }
# 5039 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
# 5040 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum, GLsizei *, GLenum, const GLvoid **, GLsizei); }
# 5072 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLEMASKEXTPROC)(GLclampf, GLboolean); }
# 5073 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLEPATTERNEXTPROC)(GLenum); }
# 5153 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *); }
# 5154 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEEXTPROC)(GLenum, GLenum, GLenum, void *); }
# 5155 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 5156 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
# 5196 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 5197 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 5198 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum, GLenum, const GLfloat); }
# 5199 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 5200 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum, GLenum, const GLint); }
# 5201 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 5233 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFEXTPROC)(GLenum, GLfloat); }
# 5234 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVEXTPROC)(GLenum, GLfloat *); }
# 5252 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOLYGONOFFSETEXTPROC)(GLfloat, GLfloat); }
# 5274 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINSCENEEXTPROC)(void); }
# 5275 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDSCENEEXTPROC)(void); }
# 5297 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
# 5298 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *); }
# 5299 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
# 5300 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *); }
# 5301 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
# 5302 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *); }
# 5303 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IEXTPROC)(GLint, GLint, GLint); }
# 5304 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *); }
# 5305 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort, GLshort, GLshort); }
# 5306 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *); }
# 5307 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte, GLubyte, GLubyte); }
# 5308 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *); }
# 5309 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint, GLuint, GLuint); }
# 5310 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *); }
# 5311 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort, GLushort, GLushort); }
# 5312 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *); }
# 5313 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLvoid *); }
# 5390 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLACTIVESTENCILFACEEXTPROC)(GLenum); }
# 5415 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *); }
# 5416 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *); }
# 5417 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *); }
# 5494 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXIMAGE3DEXTPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *); }
# 5531 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXBUFFEREXTPROC)(GLenum, GLenum, GLuint); }
# 5764 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLEARCOLORIIEXTPROC)(GLint, GLint, GLint, GLint); }
# 5765 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLEARCOLORIUIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
# 5766 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLint *); }
# 5767 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLuint *); }
# 5768 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, const GLint *); }
# 5769 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, const GLuint *); }
# 5819 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei, const GLuint *, GLboolean *); }
# 5820 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDTEXTUREEXTPROC)(GLenum, GLuint); }
# 5821 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETETEXTURESEXTPROC)(GLsizei, const GLuint *); }
# 5822 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENTEXTURESEXTPROC)(GLsizei, GLuint *); }
# 5823 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISTEXTUREEXTPROC)(GLuint); }
# 5824 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei, const GLuint *, const GLclampf *); }
# 5845 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXTURENORMALEXTPROC)(GLenum); }
# 5913 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint, GLenum, GLint64EXT *); }
# 5914 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint, GLenum, GLuint64EXT *); }
# 5962 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLARRAYELEMENTEXTPROC)(GLint); }
# 5963 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const void *); }
# 5964 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWARRAYSEXTPROC)(GLenum, GLint, GLsizei); }
# 5965 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei, GLsizei, const GLboolean *); }
# 5966 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPOINTERVEXTPROC)(GLenum, void **); }
# 5967 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLINDEXPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const void *); }
# 5968 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const void *); }
# 5969 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORDPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const void *); }
# 5970 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const void *); }
# 6102 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINVERTEXSHADEREXTPROC)(void); }
# 6103 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum, GLenum); }
# 6104 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum, GLenum); }
# 6105 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBINDPARAMETEREXTPROC)(GLenum); }
# 6106 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum, GLenum, GLenum); }
# 6107 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum, GLenum); }
# 6108 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDVERTEXSHADEREXTPROC)(GLuint); }
# 6109 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint); }
# 6110 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
# 6111 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
# 6112 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDVERTEXSHADEREXTPROC)(void); }
# 6113 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
# 6114 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLGENSYMBOLSEXTPROC)(GLenum, GLenum, GLenum, GLuint); }
# 6115 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLGENVERTEXSHADERSEXTPROC)(GLuint); }
# 6116 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6117 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6118 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6119 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6120 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6121 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6122 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
# 6123 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 6124 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
# 6125 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint, GLenum, GLvoid **); }
# 6126 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLINSERTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
# 6127 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISVARIANTENABLEDEXTPROC)(GLuint, GLenum); }
# 6128 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSETINVARIANTEXTPROC)(GLuint, GLenum, GLvoid *); }
# 6129 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSETLOCALCONSTANTEXTPROC)(GLuint, GLenum, GLvoid *); }
# 6130 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHADEROP1EXTPROC)(GLenum, GLuint, GLuint); }
# 6131 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHADEROP2EXTPROC)(GLenum, GLuint, GLuint, GLuint); }
# 6132 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHADEROP3EXTPROC)(GLenum, GLuint, GLuint, GLuint, GLuint); }
# 6133 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSWIZZLEEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
# 6134 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTPOINTEREXTPROC)(GLuint, GLenum, GLuint, GLvoid *); }
# 6135 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTBVEXTPROC)(GLuint, GLbyte *); }
# 6136 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTDVEXTPROC)(GLuint, GLdouble *); }
# 6137 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTFVEXTPROC)(GLuint, GLfloat *); }
# 6138 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTIVEXTPROC)(GLuint, GLint *); }
# 6139 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTSVEXTPROC)(GLuint, GLshort *); }
# 6140 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTUBVEXTPROC)(GLuint, GLubyte *); }
# 6141 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTUIVEXTPROC)(GLuint, GLuint *); }
# 6142 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVARIANTUSVEXTPROC)(GLuint, GLushort *); }
# 6143 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWRITEMASKEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
# 6211 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLint, GLenum, GLsizei, void *); }
# 6212 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat); }
# 6213 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFVEXTPROC)(GLfloat *); }
# 6228 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMETERMINATORGREMEDYPROC)(void); }
# 6241 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei, const void *); }
# 6263 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, const GLfloat *); }
# 6264 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, const GLint *); }
# 6265 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum, GLenum, const GLfloat); }
# 6266 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, const GLfloat *); }
# 6267 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum, GLenum, const GLint); }
# 6268 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, const GLint *); }
# 6318 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint); }
# 6319 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const *, GLsizei, GLint); }
# 6384 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 6385 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint, const GLboolean **, GLint); }
# 6386 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 6387 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLINDEXPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 6388 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
# 6389 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 6390 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 6391 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 6446 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORPOINTERVINTELPROC)(GLint, GLenum, const void **); }
# 6447 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMALPOINTERVINTELPROC)(GLenum, const void **); }
# 6448 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERVINTELPROC)(GLint, GLenum, const void **); }
# 6449 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXPOINTERVINTELPROC)(GLint, GLenum, const void **); }
# 6465 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSCISSORFUNCINTELPROC)(GLenum, GLenum, GLenum); }
# 6466 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSCISSORINTELPROC)(GLenum, GLclampf, GLclampf); }
# 6485 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLBUFFERREGIONENABLEDEXTPROC)(void); }
# 6486 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEBUFFERREGIONEXTPROC)(GLenum); }
# 6487 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERREGIONEXTPROC)(GLuint, GLint, GLint, GLsizei, GLsizei, GLint, GLint); }
# 6488 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLNEWBUFFERREGIONEXTPROC)(GLenum); }
# 6489 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREADBUFFERREGIONEXTPROC)(GLuint, GLint, GLint, GLsizei, GLsizei); }
# 6533 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRESIZEBUFFERSMESAPROC)(void); }
# 6546 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DMESAPROC)(GLdouble, GLdouble); }
# 6547 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *); }
# 6548 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FMESAPROC)(GLfloat, GLfloat); }
# 6549 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *); }
# 6550 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IMESAPROC)(GLint, GLint); }
# 6551 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2IVMESAPROC)(const GLint *); }
# 6552 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SMESAPROC)(GLshort, GLshort); }
# 6553 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *); }
# 6554 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DMESAPROC)(GLdouble, GLdouble, GLdouble); }
# 6555 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *); }
# 6556 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FMESAPROC)(GLfloat, GLfloat, GLfloat); }
# 6557 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *); }
# 6558 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IMESAPROC)(GLint, GLint, GLint); }
# 6559 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3IVMESAPROC)(const GLint *); }
# 6560 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SMESAPROC)(GLshort, GLshort, GLshort); }
# 6561 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *); }
# 6562 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4DMESAPROC)(GLdouble, GLdouble, GLdouble, GLdouble); }
# 6563 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *); }
# 6564 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4FMESAPROC)(GLfloat, GLfloat, GLfloat, GLfloat); }
# 6565 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *); }
# 6566 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4IMESAPROC)(GLint, GLint, GLint, GLint); }
# 6567 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4IVMESAPROC)(const GLint *); }
# 6568 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4SMESAPROC)(GLshort, GLshort, GLshort, GLshort); }
# 6569 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *); }
# 6644 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLEARDEPTHDNVPROC)(GLdouble); }
# 6645 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDEPTHBOUNDSDNVPROC)(GLdouble, GLdouble); }
# 6646 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDEPTHRANGEDNVPROC)(GLdouble, GLdouble); }
# 6712 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLEVALMAPSNVPROC)(GLenum, GLenum); }
# 6713 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
# 6714 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
# 6715 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, void *); }
# 6716 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMAPPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 6717 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETMAPPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
# 6718 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const void *); }
# 6719 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMAPPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
# 6720 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMAPPARAMETERIVNVPROC)(GLenum, GLenum, const GLint *); }
# 6745 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEFENCESNVPROC)(GLsizei, const GLuint *); }
# 6746 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFINISHFENCENVPROC)(GLuint); }
# 6747 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENFENCESNVPROC)(GLsizei, GLuint *); }
# 6748 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFENCEIVNVPROC)(GLuint, GLenum, GLint *); }
# 6749 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISFENCENVPROC)(GLuint); }
# 6750 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSETFENCENVPROC)(GLuint, GLenum); }
# 6751 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLTESTFENCENVPROC)(GLuint); }
# 6815 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble *); }
# 6816 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat *); }
# 6817 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble); }
# 6818 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLdouble []); }
# 6819 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat); }
# 6820 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLfloat []); }
# 6876 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei); }
# 6893 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum, GLint); }
# 6924 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
# 6925 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
# 6926 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6927 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
# 6928 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
# 6929 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
# 6930 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
# 6931 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
# 6932 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
# 6933 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
# 6934 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
# 6935 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
# 6961 "/usr/include/GL/glew.h" 3
extern "C" { typedef unsigned short GLhalf; }
# 6963 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR3HNVPROC)(GLhalf, GLhalf, GLhalf); }
# 6964 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR3HVNVPROC)(const GLhalf *); }
# 6965 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4HNVPROC)(GLhalf, GLhalf, GLhalf, GLhalf); }
# 6966 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4HVNVPROC)(const GLhalf *); }
# 6967 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDHNVPROC)(GLhalf); }
# 6968 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDHVNVPROC)(const GLhalf *); }
# 6969 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HNVPROC)(GLenum, GLhalf); }
# 6970 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HVNVPROC)(GLenum, const GLhalf *); }
# 6971 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HNVPROC)(GLenum, GLhalf, GLhalf); }
# 6972 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HVNVPROC)(GLenum, const GLhalf *); }
# 6973 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HNVPROC)(GLenum, GLhalf, GLhalf, GLhalf); }
# 6974 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HVNVPROC)(GLenum, const GLhalf *); }
# 6975 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HNVPROC)(GLenum, GLhalf, GLhalf, GLhalf, GLhalf); }
# 6976 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HVNVPROC)(GLenum, const GLhalf *); }
# 6977 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMAL3HNVPROC)(GLhalf, GLhalf, GLhalf); }
# 6978 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMAL3HVNVPROC)(const GLhalf *); }
# 6979 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HNVPROC)(GLhalf, GLhalf, GLhalf); }
# 6980 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalf *); }
# 6981 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD1HNVPROC)(GLhalf); }
# 6982 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD1HVNVPROC)(const GLhalf *); }
# 6983 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2HNVPROC)(GLhalf, GLhalf); }
# 6984 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2HVNVPROC)(const GLhalf *); }
# 6985 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD3HNVPROC)(GLhalf, GLhalf, GLhalf); }
# 6986 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD3HVNVPROC)(const GLhalf *); }
# 6987 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4HNVPROC)(GLhalf, GLhalf, GLhalf, GLhalf); }
# 6988 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4HVNVPROC)(const GLhalf *); }
# 6989 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX2HNVPROC)(GLhalf, GLhalf); }
# 6990 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX2HVNVPROC)(const GLhalf *); }
# 6991 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX3HNVPROC)(GLhalf, GLhalf, GLhalf); }
# 6992 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX3HVNVPROC)(const GLhalf *); }
# 6993 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX4HNVPROC)(GLhalf, GLhalf, GLhalf, GLhalf); }
# 6994 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEX4HVNVPROC)(const GLhalf *); }
# 6995 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HNVPROC)(GLuint, GLhalf); }
# 6996 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HVNVPROC)(GLuint, const GLhalf *); }
# 6997 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HNVPROC)(GLuint, GLhalf, GLhalf); }
# 6998 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HVNVPROC)(GLuint, const GLhalf *); }
# 6999 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HNVPROC)(GLuint, GLhalf, GLhalf, GLhalf); }
# 7000 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HVNVPROC)(GLuint, const GLhalf *); }
# 7001 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HNVPROC)(GLuint, GLhalf, GLhalf, GLhalf, GLhalf); }
# 7002 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HVNVPROC)(GLuint, const GLhalf *); }
# 7003 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint, GLsizei, const GLhalf *); }
# 7004 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint, GLsizei, const GLhalf *); }
# 7005 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint, GLsizei, const GLhalf *); }
# 7006 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint, GLsizei, const GLhalf *); }
# 7007 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHNVPROC)(GLhalf); }
# 7008 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalf *); }
# 7094 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint); }
# 7095 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei, const GLuint *); }
# 7096 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDOCCLUSIONQUERYNVPROC)(void); }
# 7097 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei, GLuint *); }
# 7098 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint, GLenum, GLint *); }
# 7099 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint, GLenum, GLuint *); }
# 7100 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISOCCLUSIONQUERYNVPROC)(GLuint); }
# 7137 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLint *); }
# 7138 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLuint *); }
# 7139 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *); }
# 7161 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum); }
# 7162 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELDATARANGENVPROC)(GLenum, GLsizei, void *); }
# 7180 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERINVPROC)(GLenum, GLint); }
# 7181 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVNVPROC)(GLenum, const GLint *); }
# 7198 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint); }
# 7199 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTNVPROC)(void); }
# 7265 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum); }
# 7266 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINEROUTPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean); }
# 7267 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFNVPROC)(GLenum, GLfloat); }
# 7268 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum, const GLfloat *); }
# 7269 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERINVPROC)(GLenum, GLint); }
# 7270 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum, const GLint *); }
# 7271 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFINALCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum); }
# 7272 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLfloat *); }
# 7273 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLint *); }
# 7274 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLfloat *); }
# 7275 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLint *); }
# 7276 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 7277 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
# 7304 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
# 7305 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 7564 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLACTIVEVARYINGNVPROC)(GLuint, const GLchar *); }
# 7565 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum); }
# 7566 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFERBASENVPROC)(GLenum, GLuint, GLuint); }
# 7567 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFEROFFSETNVPROC)(GLenum, GLuint, GLuint, GLintptr); }
# 7568 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFERRANGENVPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr); }
# 7569 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLENDTRANSFORMFEEDBACKNVPROC)(void); }
# 7570 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETACTIVEVARYINGNVPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *); }
# 7571 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint, GLuint, GLint *); }
# 7572 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLGETVARYINGLOCATIONNVPROC)(GLuint, const GLchar *); }
# 7573 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLuint, const GLint *, GLenum); }
# 7574 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint, GLsizei, const GLint *, GLenum); }
# 7603 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGENVPROC)(void); }
# 7604 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGENVPROC)(GLsizei, void *); }
# 7713 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei, const GLuint *, GLboolean *); }
# 7714 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLBINDPROGRAMNVPROC)(GLenum, GLuint); }
# 7715 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEPROGRAMSNVPROC)(GLsizei, const GLuint *); }
# 7716 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLEXECUTEPROGRAMNVPROC)(GLenum, GLuint, const GLfloat *); }
# 7717 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGENPROGRAMSNVPROC)(GLsizei, GLuint *); }
# 7718 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum, GLuint, GLenum, GLdouble *); }
# 7719 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
# 7720 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGNVPROC)(GLuint, GLenum, GLubyte *); }
# 7721 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETPROGRAMIVNVPROC)(GLuint, GLenum, GLint *); }
# 7722 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTRACKMATRIXIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
# 7723 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint, GLenum, GLvoid **); }
# 7724 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint, GLenum, GLdouble *); }
# 7725 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint, GLenum, GLfloat *); }
# 7726 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint, GLenum, GLint *); }
# 7727 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISPROGRAMNVPROC)(GLuint); }
# 7728 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLLOADPROGRAMNVPROC)(GLenum, GLuint, GLsizei, const GLubyte *); }
# 7729 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 7730 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum, GLuint, const GLdouble *); }
# 7731 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 7732 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum, GLuint, const GLfloat *); }
# 7733 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum, GLuint, GLuint, const GLdouble *); }
# 7734 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum, GLuint, GLuint, const GLfloat *); }
# 7735 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei, GLuint *); }
# 7736 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTRACKMATRIXNVPROC)(GLenum, GLuint, GLenum, GLenum); }
# 7737 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DNVPROC)(GLuint, GLdouble); }
# 7738 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVNVPROC)(GLuint, const GLdouble *); }
# 7739 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FNVPROC)(GLuint, GLfloat); }
# 7740 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVNVPROC)(GLuint, const GLfloat *); }
# 7741 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SNVPROC)(GLuint, GLshort); }
# 7742 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVNVPROC)(GLuint, const GLshort *); }
# 7743 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DNVPROC)(GLuint, GLdouble, GLdouble); }
# 7744 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVNVPROC)(GLuint, const GLdouble *); }
# 7745 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FNVPROC)(GLuint, GLfloat, GLfloat); }
# 7746 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVNVPROC)(GLuint, const GLfloat *); }
# 7747 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SNVPROC)(GLuint, GLshort, GLshort); }
# 7748 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVNVPROC)(GLuint, const GLshort *); }
# 7749 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
# 7750 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVNVPROC)(GLuint, const GLdouble *); }
# 7751 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 7752 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVNVPROC)(GLuint, const GLfloat *); }
# 7753 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SNVPROC)(GLuint, GLshort, GLshort, GLshort); }
# 7754 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVNVPROC)(GLuint, const GLshort *); }
# 7755 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
# 7756 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVNVPROC)(GLuint, const GLdouble *); }
# 7757 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
# 7758 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVNVPROC)(GLuint, const GLfloat *); }
# 7759 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SNVPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
# 7760 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVNVPROC)(GLuint, const GLshort *); }
# 7761 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBNVPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
# 7762 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint, const GLubyte *); }
# 7763 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint, GLint, GLenum, GLsizei, const void *); }
# 7764 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 7765 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 7766 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 7767 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 7768 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 7769 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 7770 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 7771 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 7772 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 7773 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
# 7774 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
# 7775 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint, GLsizei, const GLshort *); }
# 7776 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint, GLsizei, const GLubyte *); }
# 7945 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLEARDEPTHFOESPROC)(GLclampd); }
# 7946 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCLIPPLANEFOESPROC)(GLenum, const GLfloat *); }
# 7947 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDEPTHRANGEFOESPROC)(GLclampf, GLclampf); }
# 7948 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRUSTUMFOESPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 7949 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCLIPPLANEFOESPROC)(GLenum, GLfloat *); }
# 7950 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLORTHOFOESPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8117 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDETAILTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
# 8118 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 8132 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFOGFUNCSGISPROC)(GLsizei, const GLfloat *); }
# 8133 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFOGFUNCSGISPROC)(GLfloat *); }
# 8177 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLEMASKSGISPROC)(GLclampf, GLboolean); }
# 8178 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSAMPLEPATTERNSGISPROC)(GLenum); }
# 8201 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 8202 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSHARPENTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
# 8216 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXIMAGE4DSGISPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *); }
# 8217 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *); }
# 8253 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLfloat *); }
# 8254 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLsizei, const GLfloat *); }
# 8293 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLASYNCMARKERSGIXPROC)(GLuint); }
# 8294 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint, GLsizei); }
# 8295 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLFINISHASYNCSGIXPROC)(GLuint *); }
# 8296 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLuint (*PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei); }
# 8297 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLboolean (*PFNGLISASYNCMARKERSGIXPROC)(GLuint); }
# 8298 "/usr/include/GL/glew.h" 3
extern "C" { typedef GLint (*PFNGLPOLLASYNCSGIXPROC)(GLuint *); }
# 8378 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFLUSHRASTERSGIXPROC)(void); }
# 8407 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXTUREFOGSGIXPROC)(GLenum); }
# 8420 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum, GLenum); }
# 8421 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum, GLfloat); }
# 8422 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum, GLfloat *); }
# 8423 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum, GLint); }
# 8424 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum, GLint *); }
# 8425 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum, GLenum, GLfloat); }
# 8426 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
# 8427 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum, GLenum, GLint); }
# 8428 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, GLint *); }
# 8429 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum, GLenum, const GLfloat); }
# 8430 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
# 8431 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum, GLenum, const GLint); }
# 8432 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, const GLint *); }
# 8433 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
# 8434 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, GLint *); }
# 8435 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
# 8436 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, const GLint *); }
# 8465 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFRAMEZOOMSGIXPROC)(GLint); }
# 8507 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLPIXELTEXGENSGIXPROC)(GLenum); }
# 8529 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *); }
# 8582 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum, GLfloat); }
# 8583 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum, GLfloat *); }
# 8584 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSPRITEPARAMETERISGIXPROC)(GLenum, GLint); }
# 8585 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum, GLint *); }
# 8601 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTAGSAMPLEBUFFERSGIXPROC)(void); }
# 8779 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, const GLfloat *); }
# 8780 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, const GLint *); }
# 8781 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLESGIPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *); }
# 8782 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOPYCOLORTABLESGIPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
# 8783 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, GLfloat *); }
# 8784 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, GLint *); }
# 8785 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGETCOLORTABLESGIPROC)(GLenum, GLenum, GLenum, void *); }
# 8819 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLFINISHTEXTURESUNXPROC)(void); }
# 8846 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte); }
# 8847 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble); }
# 8848 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat); }
# 8849 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORISUNPROC)(GLint); }
# 8850 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort); }
# 8851 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte); }
# 8852 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint); }
# 8853 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort); }
# 8885 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREADVIDEOPIXELSSUNPROC)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *); }
# 8927 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum, GLsizei, const void *); }
# 8928 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte); }
# 8929 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *); }
# 8930 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUISUNPROC)(GLuint); }
# 8931 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *); }
# 8932 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort); }
# 8933 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *); }
# 8952 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8953 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 8954 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8955 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 8956 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat); }
# 8957 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *, const GLfloat *); }
# 8958 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 8959 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *, const GLfloat *); }
# 8960 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8961 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 8962 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8963 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 8964 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8965 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 8966 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 8967 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *, const GLubyte *, const GLfloat *); }
# 8968 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8969 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 8970 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8971 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 8972 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8973 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 8974 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8975 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
# 8976 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
# 8977 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *); }
# 8978 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8979 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 8980 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8981 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 8982 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
# 8983 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *, const GLubyte *, const GLfloat *); }
# 8984 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8985 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
# 8986 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8987 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 8988 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8989 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 8990 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
# 8991 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *); }
# 9066 "/usr/include/GL/glew.h" 3
extern "C" { typedef void (*PFNGLADDSWAPHINTRECTWINPROC)(GLint, GLint, GLsizei, GLsizei); }
# 9093 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXSUBIMAGE3DPROC __glewCopyTexSubImage3D; }
# 9094 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWRANGEELEMENTSPROC __glewDrawRangeElements; }
# 9095 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXIMAGE3DPROC __glewTexImage3D; }
# 9096 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSUBIMAGE3DPROC __glewTexSubImage3D; }
# 9098 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLACTIVETEXTUREPROC __glewActiveTexture; }
# 9099 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLIENTACTIVETEXTUREPROC __glewClientActiveTexture; }
# 9100 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE1DPROC __glewCompressedTexImage1D; }
# 9101 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE2DPROC __glewCompressedTexImage2D; }
# 9102 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE3DPROC __glewCompressedTexImage3D; }
# 9103 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC __glewCompressedTexSubImage1D; }
# 9104 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC __glewCompressedTexSubImage2D; }
# 9105 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC __glewCompressedTexSubImage3D; }
# 9106 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMPRESSEDTEXIMAGEPROC __glewGetCompressedTexImage; }
# 9107 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOADTRANSPOSEMATRIXDPROC __glewLoadTransposeMatrixd; }
# 9108 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOADTRANSPOSEMATRIXFPROC __glewLoadTransposeMatrixf; }
# 9109 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTTRANSPOSEMATRIXDPROC __glewMultTransposeMatrixd; }
# 9110 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTTRANSPOSEMATRIXFPROC __glewMultTransposeMatrixf; }
# 9111 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1DPROC __glewMultiTexCoord1d; }
# 9112 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1DVPROC __glewMultiTexCoord1dv; }
# 9113 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1FPROC __glewMultiTexCoord1f; }
# 9114 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1FVPROC __glewMultiTexCoord1fv; }
# 9115 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1IPROC __glewMultiTexCoord1i; }
# 9116 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1IVPROC __glewMultiTexCoord1iv; }
# 9117 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1SPROC __glewMultiTexCoord1s; }
# 9118 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1SVPROC __glewMultiTexCoord1sv; }
# 9119 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2DPROC __glewMultiTexCoord2d; }
# 9120 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2DVPROC __glewMultiTexCoord2dv; }
# 9121 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2FPROC __glewMultiTexCoord2f; }
# 9122 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2FVPROC __glewMultiTexCoord2fv; }
# 9123 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2IPROC __glewMultiTexCoord2i; }
# 9124 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2IVPROC __glewMultiTexCoord2iv; }
# 9125 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2SPROC __glewMultiTexCoord2s; }
# 9126 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2SVPROC __glewMultiTexCoord2sv; }
# 9127 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3DPROC __glewMultiTexCoord3d; }
# 9128 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3DVPROC __glewMultiTexCoord3dv; }
# 9129 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3FPROC __glewMultiTexCoord3f; }
# 9130 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3FVPROC __glewMultiTexCoord3fv; }
# 9131 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3IPROC __glewMultiTexCoord3i; }
# 9132 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3IVPROC __glewMultiTexCoord3iv; }
# 9133 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3SPROC __glewMultiTexCoord3s; }
# 9134 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3SVPROC __glewMultiTexCoord3sv; }
# 9135 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4DPROC __glewMultiTexCoord4d; }
# 9136 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4DVPROC __glewMultiTexCoord4dv; }
# 9137 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4FPROC __glewMultiTexCoord4f; }
# 9138 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4FVPROC __glewMultiTexCoord4fv; }
# 9139 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4IPROC __glewMultiTexCoord4i; }
# 9140 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4IVPROC __glewMultiTexCoord4iv; }
# 9141 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4SPROC __glewMultiTexCoord4s; }
# 9142 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4SVPROC __glewMultiTexCoord4sv; }
# 9143 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLECOVERAGEPROC __glewSampleCoverage; }
# 9145 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDCOLORPROC __glewBlendColor; }
# 9146 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDEQUATIONPROC __glewBlendEquation; }
# 9147 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDFUNCSEPARATEPROC __glewBlendFuncSeparate; }
# 9148 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDPOINTERPROC __glewFogCoordPointer; }
# 9149 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDDPROC __glewFogCoordd; }
# 9150 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDDVPROC __glewFogCoorddv; }
# 9151 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDFPROC __glewFogCoordf; }
# 9152 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDFVPROC __glewFogCoordfv; }
# 9153 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWARRAYSPROC __glewMultiDrawArrays; }
# 9154 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWELEMENTSPROC __glewMultiDrawElements; }
# 9155 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFPROC __glewPointParameterf; }
# 9156 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFVPROC __glewPointParameterfv; }
# 9157 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERIPROC __glewPointParameteri; }
# 9158 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERIVPROC __glewPointParameteriv; }
# 9159 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3BPROC __glewSecondaryColor3b; }
# 9160 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3BVPROC __glewSecondaryColor3bv; }
# 9161 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3DPROC __glewSecondaryColor3d; }
# 9162 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3DVPROC __glewSecondaryColor3dv; }
# 9163 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3FPROC __glewSecondaryColor3f; }
# 9164 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3FVPROC __glewSecondaryColor3fv; }
# 9165 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3IPROC __glewSecondaryColor3i; }
# 9166 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3IVPROC __glewSecondaryColor3iv; }
# 9167 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3SPROC __glewSecondaryColor3s; }
# 9168 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3SVPROC __glewSecondaryColor3sv; }
# 9169 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UBPROC __glewSecondaryColor3ub; }
# 9170 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UBVPROC __glewSecondaryColor3ubv; }
# 9171 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UIPROC __glewSecondaryColor3ui; }
# 9172 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UIVPROC __glewSecondaryColor3uiv; }
# 9173 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3USPROC __glewSecondaryColor3us; }
# 9174 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3USVPROC __glewSecondaryColor3usv; }
# 9175 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLORPOINTERPROC __glewSecondaryColorPointer; }
# 9176 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DPROC __glewWindowPos2d; }
# 9177 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DVPROC __glewWindowPos2dv; }
# 9178 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FPROC __glewWindowPos2f; }
# 9179 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FVPROC __glewWindowPos2fv; }
# 9180 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IPROC __glewWindowPos2i; }
# 9181 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IVPROC __glewWindowPos2iv; }
# 9182 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SPROC __glewWindowPos2s; }
# 9183 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SVPROC __glewWindowPos2sv; }
# 9184 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DPROC __glewWindowPos3d; }
# 9185 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DVPROC __glewWindowPos3dv; }
# 9186 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FPROC __glewWindowPos3f; }
# 9187 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FVPROC __glewWindowPos3fv; }
# 9188 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IPROC __glewWindowPos3i; }
# 9189 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IVPROC __glewWindowPos3iv; }
# 9190 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SPROC __glewWindowPos3s; }
# 9191 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SVPROC __glewWindowPos3sv; }
# 9193 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINQUERYPROC __glewBeginQuery; }
# 9194 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDBUFFERPROC __glewBindBuffer; }
# 9195 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERDATAPROC __glewBufferData; }
# 9196 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERSUBDATAPROC __glewBufferSubData; }
# 9197 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEBUFFERSPROC __glewDeleteBuffers; }
# 9198 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEQUERIESPROC __glewDeleteQueries; }
# 9199 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDQUERYPROC __glewEndQuery; }
# 9200 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENBUFFERSPROC __glewGenBuffers; }
# 9201 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENQUERIESPROC __glewGenQueries; }
# 9202 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERPARAMETERIVPROC __glewGetBufferParameteriv; }
# 9203 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERPOINTERVPROC __glewGetBufferPointerv; }
# 9204 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERSUBDATAPROC __glewGetBufferSubData; }
# 9205 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTIVPROC __glewGetQueryObjectiv; }
# 9206 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTUIVPROC __glewGetQueryObjectuiv; }
# 9207 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYIVPROC __glewGetQueryiv; }
# 9208 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISBUFFERPROC __glewIsBuffer; }
# 9209 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISQUERYPROC __glewIsQuery; }
# 9210 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPBUFFERPROC __glewMapBuffer; }
# 9211 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNMAPBUFFERPROC __glewUnmapBuffer; }
# 9213 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLATTACHSHADERPROC __glewAttachShader; }
# 9214 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDATTRIBLOCATIONPROC __glewBindAttribLocation; }
# 9215 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDEQUATIONSEPARATEPROC __glewBlendEquationSeparate; }
# 9216 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPILESHADERPROC __glewCompileShader; }
# 9217 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCREATEPROGRAMPROC __glewCreateProgram; }
# 9218 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCREATESHADERPROC __glewCreateShader; }
# 9219 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEPROGRAMPROC __glewDeleteProgram; }
# 9220 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETESHADERPROC __glewDeleteShader; }
# 9221 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDETACHSHADERPROC __glewDetachShader; }
# 9222 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDISABLEVERTEXATTRIBARRAYPROC __glewDisableVertexAttribArray; }
# 9223 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWBUFFERSPROC __glewDrawBuffers; }
# 9224 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENABLEVERTEXATTRIBARRAYPROC __glewEnableVertexAttribArray; }
# 9225 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETACTIVEATTRIBPROC __glewGetActiveAttrib; }
# 9226 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETACTIVEUNIFORMPROC __glewGetActiveUniform; }
# 9227 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETATTACHEDSHADERSPROC __glewGetAttachedShaders; }
# 9228 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETATTRIBLOCATIONPROC __glewGetAttribLocation; }
# 9229 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMINFOLOGPROC __glewGetProgramInfoLog; }
# 9230 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMIVPROC __glewGetProgramiv; }
# 9231 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSHADERINFOLOGPROC __glewGetShaderInfoLog; }
# 9232 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSHADERSOURCEPROC __glewGetShaderSource; }
# 9233 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSHADERIVPROC __glewGetShaderiv; }
# 9234 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMLOCATIONPROC __glewGetUniformLocation; }
# 9235 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMFVPROC __glewGetUniformfv; }
# 9236 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMIVPROC __glewGetUniformiv; }
# 9237 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBPOINTERVPROC __glewGetVertexAttribPointerv; }
# 9238 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBDVPROC __glewGetVertexAttribdv; }
# 9239 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBFVPROC __glewGetVertexAttribfv; }
# 9240 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBIVPROC __glewGetVertexAttribiv; }
# 9241 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISPROGRAMPROC __glewIsProgram; }
# 9242 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISSHADERPROC __glewIsShader; }
# 9243 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLINKPROGRAMPROC __glewLinkProgram; }
# 9244 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHADERSOURCEPROC __glewShaderSource; }
# 9245 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTENCILFUNCSEPARATEPROC __glewStencilFuncSeparate; }
# 9246 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTENCILMASKSEPARATEPROC __glewStencilMaskSeparate; }
# 9247 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTENCILOPSEPARATEPROC __glewStencilOpSeparate; }
# 9248 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1FPROC __glewUniform1f; }
# 9249 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1FVPROC __glewUniform1fv; }
# 9250 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1IPROC __glewUniform1i; }
# 9251 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1IVPROC __glewUniform1iv; }
# 9252 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2FPROC __glewUniform2f; }
# 9253 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2FVPROC __glewUniform2fv; }
# 9254 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2IPROC __glewUniform2i; }
# 9255 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2IVPROC __glewUniform2iv; }
# 9256 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3FPROC __glewUniform3f; }
# 9257 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3FVPROC __glewUniform3fv; }
# 9258 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3IPROC __glewUniform3i; }
# 9259 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3IVPROC __glewUniform3iv; }
# 9260 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4FPROC __glewUniform4f; }
# 9261 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4FVPROC __glewUniform4fv; }
# 9262 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4IPROC __glewUniform4i; }
# 9263 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4IVPROC __glewUniform4iv; }
# 9264 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX2FVPROC __glewUniformMatrix2fv; }
# 9265 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX3FVPROC __glewUniformMatrix3fv; }
# 9266 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX4FVPROC __glewUniformMatrix4fv; }
# 9267 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUSEPROGRAMPROC __glewUseProgram; }
# 9268 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVALIDATEPROGRAMPROC __glewValidateProgram; }
# 9269 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DPROC __glewVertexAttrib1d; }
# 9270 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DVPROC __glewVertexAttrib1dv; }
# 9271 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FPROC __glewVertexAttrib1f; }
# 9272 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FVPROC __glewVertexAttrib1fv; }
# 9273 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SPROC __glewVertexAttrib1s; }
# 9274 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SVPROC __glewVertexAttrib1sv; }
# 9275 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DPROC __glewVertexAttrib2d; }
# 9276 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DVPROC __glewVertexAttrib2dv; }
# 9277 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FPROC __glewVertexAttrib2f; }
# 9278 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FVPROC __glewVertexAttrib2fv; }
# 9279 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SPROC __glewVertexAttrib2s; }
# 9280 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SVPROC __glewVertexAttrib2sv; }
# 9281 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DPROC __glewVertexAttrib3d; }
# 9282 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DVPROC __glewVertexAttrib3dv; }
# 9283 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FPROC __glewVertexAttrib3f; }
# 9284 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FVPROC __glewVertexAttrib3fv; }
# 9285 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SPROC __glewVertexAttrib3s; }
# 9286 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SVPROC __glewVertexAttrib3sv; }
# 9287 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NBVPROC __glewVertexAttrib4Nbv; }
# 9288 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NIVPROC __glewVertexAttrib4Niv; }
# 9289 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NSVPROC __glewVertexAttrib4Nsv; }
# 9290 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUBPROC __glewVertexAttrib4Nub; }
# 9291 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUBVPROC __glewVertexAttrib4Nubv; }
# 9292 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUIVPROC __glewVertexAttrib4Nuiv; }
# 9293 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUSVPROC __glewVertexAttrib4Nusv; }
# 9294 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4BVPROC __glewVertexAttrib4bv; }
# 9295 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DPROC __glewVertexAttrib4d; }
# 9296 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DVPROC __glewVertexAttrib4dv; }
# 9297 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FPROC __glewVertexAttrib4f; }
# 9298 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FVPROC __glewVertexAttrib4fv; }
# 9299 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4IVPROC __glewVertexAttrib4iv; }
# 9300 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SPROC __glewVertexAttrib4s; }
# 9301 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SVPROC __glewVertexAttrib4sv; }
# 9302 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UBVPROC __glewVertexAttrib4ubv; }
# 9303 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UIVPROC __glewVertexAttrib4uiv; }
# 9304 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4USVPROC __glewVertexAttrib4usv; }
# 9305 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBPOINTERPROC __glewVertexAttribPointer; }
# 9307 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX2X3FVPROC __glewUniformMatrix2x3fv; }
# 9308 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX2X4FVPROC __glewUniformMatrix2x4fv; }
# 9309 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX3X2FVPROC __glewUniformMatrix3x2fv; }
# 9310 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX3X4FVPROC __glewUniformMatrix3x4fv; }
# 9311 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX4X2FVPROC __glewUniformMatrix4x2fv; }
# 9312 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX4X3FVPROC __glewUniformMatrix4x3fv; }
# 9314 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTBUFFERMASK3DFXPROC __glewTbufferMask3DFX; }
# 9316 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWELEMENTARRAYAPPLEPROC __glewDrawElementArrayAPPLE; }
# 9317 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC __glewDrawRangeElementArrayAPPLE; }
# 9318 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLELEMENTPOINTERAPPLEPROC __glewElementPointerAPPLE; }
# 9319 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC __glewMultiDrawElementArrayAPPLE; }
# 9320 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC __glewMultiDrawRangeElementArrayAPPLE; }
# 9322 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEFENCESAPPLEPROC __glewDeleteFencesAPPLE; }
# 9323 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINISHFENCEAPPLEPROC __glewFinishFenceAPPLE; }
# 9324 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINISHOBJECTAPPLEPROC __glewFinishObjectAPPLE; }
# 9325 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENFENCESAPPLEPROC __glewGenFencesAPPLE; }
# 9326 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISFENCEAPPLEPROC __glewIsFenceAPPLE; }
# 9327 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSETFENCEAPPLEPROC __glewSetFenceAPPLE; }
# 9328 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTESTFENCEAPPLEPROC __glewTestFenceAPPLE; }
# 9329 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTESTOBJECTAPPLEPROC __glewTestObjectAPPLE; }
# 9331 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERPARAMETERIAPPLEPROC __glewBufferParameteriAPPLE; }
# 9332 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC __glewFlushMappedBufferRangeAPPLE; }
# 9334 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC __glewGetTexParameterPointervAPPLE; }
# 9335 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXTURERANGEAPPLEPROC __glewTextureRangeAPPLE; }
# 9337 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDVERTEXARRAYAPPLEPROC __glewBindVertexArrayAPPLE; }
# 9338 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEVERTEXARRAYSAPPLEPROC __glewDeleteVertexArraysAPPLE; }
# 9339 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENVERTEXARRAYSAPPLEPROC __glewGenVertexArraysAPPLE; }
# 9340 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISVERTEXARRAYAPPLEPROC __glewIsVertexArrayAPPLE; }
# 9342 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC __glewFlushVertexArrayRangeAPPLE; }
# 9343 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXARRAYPARAMETERIAPPLEPROC __glewVertexArrayParameteriAPPLE; }
# 9344 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXARRAYRANGEAPPLEPROC __glewVertexArrayRangeAPPLE; }
# 9346 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLAMPCOLORARBPROC __glewClampColorARB; }
# 9348 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWBUFFERSARBPROC __glewDrawBuffersARB; }
# 9350 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORSUBTABLEPROC __glewColorSubTable; }
# 9351 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEPROC __glewColorTable; }
# 9352 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEPARAMETERFVPROC __glewColorTableParameterfv; }
# 9353 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEPARAMETERIVPROC __glewColorTableParameteriv; }
# 9354 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONFILTER1DPROC __glewConvolutionFilter1D; }
# 9355 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONFILTER2DPROC __glewConvolutionFilter2D; }
# 9356 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERFPROC __glewConvolutionParameterf; }
# 9357 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERFVPROC __glewConvolutionParameterfv; }
# 9358 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERIPROC __glewConvolutionParameteri; }
# 9359 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERIVPROC __glewConvolutionParameteriv; }
# 9360 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCOLORSUBTABLEPROC __glewCopyColorSubTable; }
# 9361 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCOLORTABLEPROC __glewCopyColorTable; }
# 9362 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCONVOLUTIONFILTER1DPROC __glewCopyConvolutionFilter1D; }
# 9363 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCONVOLUTIONFILTER2DPROC __glewCopyConvolutionFilter2D; }
# 9364 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPROC __glewGetColorTable; }
# 9365 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERFVPROC __glewGetColorTableParameterfv; }
# 9366 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERIVPROC __glewGetColorTableParameteriv; }
# 9367 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONFILTERPROC __glewGetConvolutionFilter; }
# 9368 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONPARAMETERFVPROC __glewGetConvolutionParameterfv; }
# 9369 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONPARAMETERIVPROC __glewGetConvolutionParameteriv; }
# 9370 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMPROC __glewGetHistogram; }
# 9371 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMPARAMETERFVPROC __glewGetHistogramParameterfv; }
# 9372 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMPARAMETERIVPROC __glewGetHistogramParameteriv; }
# 9373 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXPROC __glewGetMinmax; }
# 9374 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXPARAMETERFVPROC __glewGetMinmaxParameterfv; }
# 9375 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXPARAMETERIVPROC __glewGetMinmaxParameteriv; }
# 9376 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSEPARABLEFILTERPROC __glewGetSeparableFilter; }
# 9377 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLHISTOGRAMPROC __glewHistogram; }
# 9378 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMINMAXPROC __glewMinmax; }
# 9379 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRESETHISTOGRAMPROC __glewResetHistogram; }
# 9380 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRESETMINMAXPROC __glewResetMinmax; }
# 9381 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSEPARABLEFILTER2DPROC __glewSeparableFilter2D; }
# 9383 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCURRENTPALETTEMATRIXARBPROC __glewCurrentPaletteMatrixARB; }
# 9384 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMATRIXINDEXPOINTERARBPROC __glewMatrixIndexPointerARB; }
# 9385 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMATRIXINDEXUBVARBPROC __glewMatrixIndexubvARB; }
# 9386 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMATRIXINDEXUIVARBPROC __glewMatrixIndexuivARB; }
# 9387 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMATRIXINDEXUSVARBPROC __glewMatrixIndexusvARB; }
# 9389 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLECOVERAGEARBPROC __glewSampleCoverageARB; }
# 9391 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLACTIVETEXTUREARBPROC __glewActiveTextureARB; }
# 9392 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLIENTACTIVETEXTUREARBPROC __glewClientActiveTextureARB; }
# 9393 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1DARBPROC __glewMultiTexCoord1dARB; }
# 9394 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1DVARBPROC __glewMultiTexCoord1dvARB; }
# 9395 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1FARBPROC __glewMultiTexCoord1fARB; }
# 9396 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1FVARBPROC __glewMultiTexCoord1fvARB; }
# 9397 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1IARBPROC __glewMultiTexCoord1iARB; }
# 9398 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1IVARBPROC __glewMultiTexCoord1ivARB; }
# 9399 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1SARBPROC __glewMultiTexCoord1sARB; }
# 9400 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1SVARBPROC __glewMultiTexCoord1svARB; }
# 9401 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2DARBPROC __glewMultiTexCoord2dARB; }
# 9402 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2DVARBPROC __glewMultiTexCoord2dvARB; }
# 9403 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2FARBPROC __glewMultiTexCoord2fARB; }
# 9404 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2FVARBPROC __glewMultiTexCoord2fvARB; }
# 9405 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2IARBPROC __glewMultiTexCoord2iARB; }
# 9406 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2IVARBPROC __glewMultiTexCoord2ivARB; }
# 9407 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2SARBPROC __glewMultiTexCoord2sARB; }
# 9408 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2SVARBPROC __glewMultiTexCoord2svARB; }
# 9409 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3DARBPROC __glewMultiTexCoord3dARB; }
# 9410 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3DVARBPROC __glewMultiTexCoord3dvARB; }
# 9411 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3FARBPROC __glewMultiTexCoord3fARB; }
# 9412 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3FVARBPROC __glewMultiTexCoord3fvARB; }
# 9413 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3IARBPROC __glewMultiTexCoord3iARB; }
# 9414 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3IVARBPROC __glewMultiTexCoord3ivARB; }
# 9415 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3SARBPROC __glewMultiTexCoord3sARB; }
# 9416 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3SVARBPROC __glewMultiTexCoord3svARB; }
# 9417 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4DARBPROC __glewMultiTexCoord4dARB; }
# 9418 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4DVARBPROC __glewMultiTexCoord4dvARB; }
# 9419 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4FARBPROC __glewMultiTexCoord4fARB; }
# 9420 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4FVARBPROC __glewMultiTexCoord4fvARB; }
# 9421 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4IARBPROC __glewMultiTexCoord4iARB; }
# 9422 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4IVARBPROC __glewMultiTexCoord4ivARB; }
# 9423 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4SARBPROC __glewMultiTexCoord4sARB; }
# 9424 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4SVARBPROC __glewMultiTexCoord4svARB; }
# 9426 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINQUERYARBPROC __glewBeginQueryARB; }
# 9427 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEQUERIESARBPROC __glewDeleteQueriesARB; }
# 9428 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDQUERYARBPROC __glewEndQueryARB; }
# 9429 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENQUERIESARBPROC __glewGenQueriesARB; }
# 9430 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTIVARBPROC __glewGetQueryObjectivARB; }
# 9431 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTUIVARBPROC __glewGetQueryObjectuivARB; }
# 9432 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYIVARBPROC __glewGetQueryivARB; }
# 9433 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISQUERYARBPROC __glewIsQueryARB; }
# 9435 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFARBPROC __glewPointParameterfARB; }
# 9436 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFVARBPROC __glewPointParameterfvARB; }
# 9438 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLATTACHOBJECTARBPROC __glewAttachObjectARB; }
# 9439 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPILESHADERARBPROC __glewCompileShaderARB; }
# 9440 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCREATEPROGRAMOBJECTARBPROC __glewCreateProgramObjectARB; }
# 9441 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCREATESHADEROBJECTARBPROC __glewCreateShaderObjectARB; }
# 9442 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEOBJECTARBPROC __glewDeleteObjectARB; }
# 9443 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDETACHOBJECTARBPROC __glewDetachObjectARB; }
# 9444 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETACTIVEUNIFORMARBPROC __glewGetActiveUniformARB; }
# 9445 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETATTACHEDOBJECTSARBPROC __glewGetAttachedObjectsARB; }
# 9446 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHANDLEARBPROC __glewGetHandleARB; }
# 9447 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETINFOLOGARBPROC __glewGetInfoLogARB; }
# 9448 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOBJECTPARAMETERFVARBPROC __glewGetObjectParameterfvARB; }
# 9449 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOBJECTPARAMETERIVARBPROC __glewGetObjectParameterivARB; }
# 9450 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSHADERSOURCEARBPROC __glewGetShaderSourceARB; }
# 9451 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMLOCATIONARBPROC __glewGetUniformLocationARB; }
# 9452 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMFVARBPROC __glewGetUniformfvARB; }
# 9453 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMIVARBPROC __glewGetUniformivARB; }
# 9454 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLINKPROGRAMARBPROC __glewLinkProgramARB; }
# 9455 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHADERSOURCEARBPROC __glewShaderSourceARB; }
# 9456 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1FARBPROC __glewUniform1fARB; }
# 9457 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1FVARBPROC __glewUniform1fvARB; }
# 9458 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1IARBPROC __glewUniform1iARB; }
# 9459 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1IVARBPROC __glewUniform1ivARB; }
# 9460 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2FARBPROC __glewUniform2fARB; }
# 9461 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2FVARBPROC __glewUniform2fvARB; }
# 9462 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2IARBPROC __glewUniform2iARB; }
# 9463 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2IVARBPROC __glewUniform2ivARB; }
# 9464 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3FARBPROC __glewUniform3fARB; }
# 9465 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3FVARBPROC __glewUniform3fvARB; }
# 9466 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3IARBPROC __glewUniform3iARB; }
# 9467 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3IVARBPROC __glewUniform3ivARB; }
# 9468 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4FARBPROC __glewUniform4fARB; }
# 9469 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4FVARBPROC __glewUniform4fvARB; }
# 9470 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4IARBPROC __glewUniform4iARB; }
# 9471 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4IVARBPROC __glewUniform4ivARB; }
# 9472 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX2FVARBPROC __glewUniformMatrix2fvARB; }
# 9473 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX3FVARBPROC __glewUniformMatrix3fvARB; }
# 9474 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMMATRIX4FVARBPROC __glewUniformMatrix4fvARB; }
# 9475 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUSEPROGRAMOBJECTARBPROC __glewUseProgramObjectARB; }
# 9476 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVALIDATEPROGRAMARBPROC __glewValidateProgramARB; }
# 9478 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC __glewCompressedTexImage1DARB; }
# 9479 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC __glewCompressedTexImage2DARB; }
# 9480 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC __glewCompressedTexImage3DARB; }
# 9481 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC __glewCompressedTexSubImage1DARB; }
# 9482 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC __glewCompressedTexSubImage2DARB; }
# 9483 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC __glewCompressedTexSubImage3DARB; }
# 9484 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC __glewGetCompressedTexImageARB; }
# 9486 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOADTRANSPOSEMATRIXDARBPROC __glewLoadTransposeMatrixdARB; }
# 9487 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOADTRANSPOSEMATRIXFARBPROC __glewLoadTransposeMatrixfARB; }
# 9488 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTTRANSPOSEMATRIXDARBPROC __glewMultTransposeMatrixdARB; }
# 9489 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTTRANSPOSEMATRIXFARBPROC __glewMultTransposeMatrixfARB; }
# 9491 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXBLENDARBPROC __glewVertexBlendARB; }
# 9492 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTPOINTERARBPROC __glewWeightPointerARB; }
# 9493 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTBVARBPROC __glewWeightbvARB; }
# 9494 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTDVARBPROC __glewWeightdvARB; }
# 9495 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTFVARBPROC __glewWeightfvARB; }
# 9496 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTIVARBPROC __glewWeightivARB; }
# 9497 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTSVARBPROC __glewWeightsvARB; }
# 9498 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTUBVARBPROC __glewWeightubvARB; }
# 9499 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTUIVARBPROC __glewWeightuivARB; }
# 9500 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWEIGHTUSVARBPROC __glewWeightusvARB; }
# 9502 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDBUFFERARBPROC __glewBindBufferARB; }
# 9503 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERDATAARBPROC __glewBufferDataARB; }
# 9504 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERSUBDATAARBPROC __glewBufferSubDataARB; }
# 9505 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEBUFFERSARBPROC __glewDeleteBuffersARB; }
# 9506 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENBUFFERSARBPROC __glewGenBuffersARB; }
# 9507 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERPARAMETERIVARBPROC __glewGetBufferParameterivARB; }
# 9508 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERPOINTERVARBPROC __glewGetBufferPointervARB; }
# 9509 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBUFFERSUBDATAARBPROC __glewGetBufferSubDataARB; }
# 9510 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISBUFFERARBPROC __glewIsBufferARB; }
# 9511 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPBUFFERARBPROC __glewMapBufferARB; }
# 9512 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNMAPBUFFERARBPROC __glewUnmapBufferARB; }
# 9514 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDPROGRAMARBPROC __glewBindProgramARB; }
# 9515 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEPROGRAMSARBPROC __glewDeleteProgramsARB; }
# 9516 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDISABLEVERTEXATTRIBARRAYARBPROC __glewDisableVertexAttribArrayARB; }
# 9517 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENABLEVERTEXATTRIBARRAYARBPROC __glewEnableVertexAttribArrayARB; }
# 9518 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENPROGRAMSARBPROC __glewGenProgramsARB; }
# 9519 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMENVPARAMETERDVARBPROC __glewGetProgramEnvParameterdvARB; }
# 9520 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMENVPARAMETERFVARBPROC __glewGetProgramEnvParameterfvARB; }
# 9521 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC __glewGetProgramLocalParameterdvARB; }
# 9522 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC __glewGetProgramLocalParameterfvARB; }
# 9523 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMSTRINGARBPROC __glewGetProgramStringARB; }
# 9524 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMIVARBPROC __glewGetProgramivARB; }
# 9525 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBPOINTERVARBPROC __glewGetVertexAttribPointervARB; }
# 9526 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBDVARBPROC __glewGetVertexAttribdvARB; }
# 9527 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBFVARBPROC __glewGetVertexAttribfvARB; }
# 9528 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBIVARBPROC __glewGetVertexAttribivARB; }
# 9529 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISPROGRAMARBPROC __glewIsProgramARB; }
# 9530 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETER4DARBPROC __glewProgramEnvParameter4dARB; }
# 9531 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETER4DVARBPROC __glewProgramEnvParameter4dvARB; }
# 9532 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETER4FARBPROC __glewProgramEnvParameter4fARB; }
# 9533 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETER4FVARBPROC __glewProgramEnvParameter4fvARB; }
# 9534 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETER4DARBPROC __glewProgramLocalParameter4dARB; }
# 9535 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETER4DVARBPROC __glewProgramLocalParameter4dvARB; }
# 9536 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETER4FARBPROC __glewProgramLocalParameter4fARB; }
# 9537 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETER4FVARBPROC __glewProgramLocalParameter4fvARB; }
# 9538 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMSTRINGARBPROC __glewProgramStringARB; }
# 9539 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DARBPROC __glewVertexAttrib1dARB; }
# 9540 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DVARBPROC __glewVertexAttrib1dvARB; }
# 9541 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FARBPROC __glewVertexAttrib1fARB; }
# 9542 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FVARBPROC __glewVertexAttrib1fvARB; }
# 9543 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SARBPROC __glewVertexAttrib1sARB; }
# 9544 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SVARBPROC __glewVertexAttrib1svARB; }
# 9545 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DARBPROC __glewVertexAttrib2dARB; }
# 9546 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DVARBPROC __glewVertexAttrib2dvARB; }
# 9547 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FARBPROC __glewVertexAttrib2fARB; }
# 9548 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FVARBPROC __glewVertexAttrib2fvARB; }
# 9549 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SARBPROC __glewVertexAttrib2sARB; }
# 9550 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SVARBPROC __glewVertexAttrib2svARB; }
# 9551 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DARBPROC __glewVertexAttrib3dARB; }
# 9552 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DVARBPROC __glewVertexAttrib3dvARB; }
# 9553 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FARBPROC __glewVertexAttrib3fARB; }
# 9554 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FVARBPROC __glewVertexAttrib3fvARB; }
# 9555 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SARBPROC __glewVertexAttrib3sARB; }
# 9556 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SVARBPROC __glewVertexAttrib3svARB; }
# 9557 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NBVARBPROC __glewVertexAttrib4NbvARB; }
# 9558 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NIVARBPROC __glewVertexAttrib4NivARB; }
# 9559 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NSVARBPROC __glewVertexAttrib4NsvARB; }
# 9560 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUBARBPROC __glewVertexAttrib4NubARB; }
# 9561 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUBVARBPROC __glewVertexAttrib4NubvARB; }
# 9562 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUIVARBPROC __glewVertexAttrib4NuivARB; }
# 9563 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4NUSVARBPROC __glewVertexAttrib4NusvARB; }
# 9564 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4BVARBPROC __glewVertexAttrib4bvARB; }
# 9565 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DARBPROC __glewVertexAttrib4dARB; }
# 9566 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DVARBPROC __glewVertexAttrib4dvARB; }
# 9567 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FARBPROC __glewVertexAttrib4fARB; }
# 9568 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FVARBPROC __glewVertexAttrib4fvARB; }
# 9569 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4IVARBPROC __glewVertexAttrib4ivARB; }
# 9570 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SARBPROC __glewVertexAttrib4sARB; }
# 9571 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SVARBPROC __glewVertexAttrib4svARB; }
# 9572 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UBVARBPROC __glewVertexAttrib4ubvARB; }
# 9573 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UIVARBPROC __glewVertexAttrib4uivARB; }
# 9574 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4USVARBPROC __glewVertexAttrib4usvARB; }
# 9575 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBPOINTERARBPROC __glewVertexAttribPointerARB; }
# 9577 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDATTRIBLOCATIONARBPROC __glewBindAttribLocationARB; }
# 9578 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETACTIVEATTRIBARBPROC __glewGetActiveAttribARB; }
# 9579 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETATTRIBLOCATIONARBPROC __glewGetAttribLocationARB; }
# 9581 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DARBPROC __glewWindowPos2dARB; }
# 9582 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DVARBPROC __glewWindowPos2dvARB; }
# 9583 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FARBPROC __glewWindowPos2fARB; }
# 9584 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FVARBPROC __glewWindowPos2fvARB; }
# 9585 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IARBPROC __glewWindowPos2iARB; }
# 9586 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IVARBPROC __glewWindowPos2ivARB; }
# 9587 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SARBPROC __glewWindowPos2sARB; }
# 9588 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SVARBPROC __glewWindowPos2svARB; }
# 9589 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DARBPROC __glewWindowPos3dARB; }
# 9590 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DVARBPROC __glewWindowPos3dvARB; }
# 9591 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FARBPROC __glewWindowPos3fARB; }
# 9592 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FVARBPROC __glewWindowPos3fvARB; }
# 9593 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IARBPROC __glewWindowPos3iARB; }
# 9594 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IVARBPROC __glewWindowPos3ivARB; }
# 9595 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SARBPROC __glewWindowPos3sARB; }
# 9596 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SVARBPROC __glewWindowPos3svARB; }
# 9598 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWBUFFERSATIPROC __glewDrawBuffersATI; }
# 9600 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWELEMENTARRAYATIPROC __glewDrawElementArrayATI; }
# 9601 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWRANGEELEMENTARRAYATIPROC __glewDrawRangeElementArrayATI; }
# 9602 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLELEMENTPOINTERATIPROC __glewElementPointerATI; }
# 9604 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXBUMPPARAMETERFVATIPROC __glewGetTexBumpParameterfvATI; }
# 9605 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXBUMPPARAMETERIVATIPROC __glewGetTexBumpParameterivATI; }
# 9606 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXBUMPPARAMETERFVATIPROC __glewTexBumpParameterfvATI; }
# 9607 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXBUMPPARAMETERIVATIPROC __glewTexBumpParameterivATI; }
# 9609 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLALPHAFRAGMENTOP1ATIPROC __glewAlphaFragmentOp1ATI; }
# 9610 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLALPHAFRAGMENTOP2ATIPROC __glewAlphaFragmentOp2ATI; }
# 9611 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLALPHAFRAGMENTOP3ATIPROC __glewAlphaFragmentOp3ATI; }
# 9612 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINFRAGMENTSHADERATIPROC __glewBeginFragmentShaderATI; }
# 9613 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDFRAGMENTSHADERATIPROC __glewBindFragmentShaderATI; }
# 9614 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORFRAGMENTOP1ATIPROC __glewColorFragmentOp1ATI; }
# 9615 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORFRAGMENTOP2ATIPROC __glewColorFragmentOp2ATI; }
# 9616 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORFRAGMENTOP3ATIPROC __glewColorFragmentOp3ATI; }
# 9617 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEFRAGMENTSHADERATIPROC __glewDeleteFragmentShaderATI; }
# 9618 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDFRAGMENTSHADERATIPROC __glewEndFragmentShaderATI; }
# 9619 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENFRAGMENTSHADERSATIPROC __glewGenFragmentShadersATI; }
# 9620 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPASSTEXCOORDATIPROC __glewPassTexCoordATI; }
# 9621 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLEMAPATIPROC __glewSampleMapATI; }
# 9622 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSETFRAGMENTSHADERCONSTANTATIPROC __glewSetFragmentShaderConstantATI; }
# 9624 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPOBJECTBUFFERATIPROC __glewMapObjectBufferATI; }
# 9625 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNMAPOBJECTBUFFERATIPROC __glewUnmapObjectBufferATI; }
# 9627 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPNTRIANGLESFATIPROC __glPNTrianglewesfATI; }
# 9628 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPNTRIANGLESIATIPROC __glPNTrianglewesiATI; }
# 9630 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTENCILFUNCSEPARATEATIPROC __glewStencilFuncSeparateATI; }
# 9631 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTENCILOPSEPARATEATIPROC __glewStencilOpSeparateATI; }
# 9633 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLARRAYOBJECTATIPROC __glewArrayObjectATI; }
# 9634 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFREEOBJECTBUFFERATIPROC __glewFreeObjectBufferATI; }
# 9635 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETARRAYOBJECTFVATIPROC __glewGetArrayObjectfvATI; }
# 9636 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETARRAYOBJECTIVATIPROC __glewGetArrayObjectivATI; }
# 9637 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOBJECTBUFFERFVATIPROC __glewGetObjectBufferfvATI; }
# 9638 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOBJECTBUFFERIVATIPROC __glewGetObjectBufferivATI; }
# 9639 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTARRAYOBJECTFVATIPROC __glewGetVariantArrayObjectfvATI; }
# 9640 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTARRAYOBJECTIVATIPROC __glewGetVariantArrayObjectivATI; }
# 9641 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISOBJECTBUFFERATIPROC __glewIsObjectBufferATI; }
# 9642 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNEWOBJECTBUFFERATIPROC __glewNewObjectBufferATI; }
# 9643 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUPDATEOBJECTBUFFERATIPROC __glewUpdateObjectBufferATI; }
# 9644 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTARRAYOBJECTATIPROC __glewVariantArrayObjectATI; }
# 9646 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC __glewGetVertexAttribArrayObjectfvATI; }
# 9647 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC __glewGetVertexAttribArrayObjectivATI; }
# 9648 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBARRAYOBJECTATIPROC __glewVertexAttribArrayObjectATI; }
# 9650 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC __glewClientActiveVertexStreamATI; }
# 9651 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3BATIPROC __glewNormalStream3bATI; }
# 9652 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3BVATIPROC __glewNormalStream3bvATI; }
# 9653 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3DATIPROC __glewNormalStream3dATI; }
# 9654 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3DVATIPROC __glewNormalStream3dvATI; }
# 9655 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3FATIPROC __glewNormalStream3fATI; }
# 9656 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3FVATIPROC __glewNormalStream3fvATI; }
# 9657 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3IATIPROC __glewNormalStream3iATI; }
# 9658 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3IVATIPROC __glewNormalStream3ivATI; }
# 9659 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3SATIPROC __glewNormalStream3sATI; }
# 9660 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALSTREAM3SVATIPROC __glewNormalStream3svATI; }
# 9661 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXBLENDENVFATIPROC __glewVertexBlendEnvfATI; }
# 9662 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXBLENDENVIATIPROC __glewVertexBlendEnviATI; }
# 9663 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2DATIPROC __glewVertexStream2dATI; }
# 9664 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2DVATIPROC __glewVertexStream2dvATI; }
# 9665 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2FATIPROC __glewVertexStream2fATI; }
# 9666 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2FVATIPROC __glewVertexStream2fvATI; }
# 9667 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2IATIPROC __glewVertexStream2iATI; }
# 9668 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2IVATIPROC __glewVertexStream2ivATI; }
# 9669 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2SATIPROC __glewVertexStream2sATI; }
# 9670 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM2SVATIPROC __glewVertexStream2svATI; }
# 9671 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3DATIPROC __glewVertexStream3dATI; }
# 9672 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3DVATIPROC __glewVertexStream3dvATI; }
# 9673 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3FATIPROC __glewVertexStream3fATI; }
# 9674 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3FVATIPROC __glewVertexStream3fvATI; }
# 9675 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3IATIPROC __glewVertexStream3iATI; }
# 9676 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3IVATIPROC __glewVertexStream3ivATI; }
# 9677 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3SATIPROC __glewVertexStream3sATI; }
# 9678 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM3SVATIPROC __glewVertexStream3svATI; }
# 9679 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4DATIPROC __glewVertexStream4dATI; }
# 9680 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4DVATIPROC __glewVertexStream4dvATI; }
# 9681 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4FATIPROC __glewVertexStream4fATI; }
# 9682 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4FVATIPROC __glewVertexStream4fvATI; }
# 9683 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4IATIPROC __glewVertexStream4iATI; }
# 9684 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4IVATIPROC __glewVertexStream4ivATI; }
# 9685 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4SATIPROC __glewVertexStream4sATI; }
# 9686 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXSTREAM4SVATIPROC __glewVertexStream4svATI; }
# 9688 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMBUFFERSIZEEXTPROC __glewGetUniformBufferSizeEXT; }
# 9689 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMOFFSETEXTPROC __glewGetUniformOffsetEXT; }
# 9690 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORMBUFFEREXTPROC __glewUniformBufferEXT; }
# 9692 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDCOLOREXTPROC __glewBlendColorEXT; }
# 9694 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDEQUATIONSEPARATEEXTPROC __glewBlendEquationSeparateEXT; }
# 9696 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDFUNCSEPARATEEXTPROC __glewBlendFuncSeparateEXT; }
# 9698 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLENDEQUATIONEXTPROC __glewBlendEquationEXT; }
# 9700 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORSUBTABLEEXTPROC __glewColorSubTableEXT; }
# 9701 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCOLORSUBTABLEEXTPROC __glewCopyColorSubTableEXT; }
# 9703 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOCKARRAYSEXTPROC __glewLockArraysEXT; }
# 9704 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNLOCKARRAYSEXTPROC __glewUnlockArraysEXT; }
# 9706 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONFILTER1DEXTPROC __glewConvolutionFilter1DEXT; }
# 9707 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONFILTER2DEXTPROC __glewConvolutionFilter2DEXT; }
# 9708 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERFEXTPROC __glewConvolutionParameterfEXT; }
# 9709 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERFVEXTPROC __glewConvolutionParameterfvEXT; }
# 9710 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERIEXTPROC __glewConvolutionParameteriEXT; }
# 9711 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCONVOLUTIONPARAMETERIVEXTPROC __glewConvolutionParameterivEXT; }
# 9712 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC __glewCopyConvolutionFilter1DEXT; }
# 9713 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC __glewCopyConvolutionFilter2DEXT; }
# 9714 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONFILTEREXTPROC __glewGetConvolutionFilterEXT; }
# 9715 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC __glewGetConvolutionParameterfvEXT; }
# 9716 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC __glewGetConvolutionParameterivEXT; }
# 9717 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSEPARABLEFILTEREXTPROC __glewGetSeparableFilterEXT; }
# 9718 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSEPARABLEFILTER2DEXTPROC __glewSeparableFilter2DEXT; }
# 9720 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINORMALPOINTEREXTPROC __glewBinormalPointerEXT; }
# 9721 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTANGENTPOINTEREXTPROC __glewTangentPointerEXT; }
# 9723 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXIMAGE1DEXTPROC __glewCopyTexImage1DEXT; }
# 9724 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXIMAGE2DEXTPROC __glewCopyTexImage2DEXT; }
# 9725 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXSUBIMAGE1DEXTPROC __glewCopyTexSubImage1DEXT; }
# 9726 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXSUBIMAGE2DEXTPROC __glewCopyTexSubImage2DEXT; }
# 9727 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYTEXSUBIMAGE3DEXTPROC __glewCopyTexSubImage3DEXT; }
# 9729 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCULLPARAMETERDVEXTPROC __glewCullParameterdvEXT; }
# 9730 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCULLPARAMETERFVEXTPROC __glewCullParameterfvEXT; }
# 9732 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDEPTHBOUNDSEXTPROC __glewDepthBoundsEXT; }
# 9734 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORMASKINDEXEDEXTPROC __glewColorMaskIndexedEXT; }
# 9735 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDISABLEINDEXEDEXTPROC __glewDisableIndexedEXT; }
# 9736 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENABLEINDEXEDEXTPROC __glewEnableIndexedEXT; }
# 9737 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETBOOLEANINDEXEDVEXTPROC __glewGetBooleanIndexedvEXT; }
# 9738 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETINTEGERINDEXEDVEXTPROC __glewGetIntegerIndexedvEXT; }
# 9739 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISENABLEDINDEXEDEXTPROC __glewIsEnabledIndexedEXT; }
# 9741 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWARRAYSINSTANCEDEXTPROC __glewDrawArraysInstancedEXT; }
# 9742 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWELEMENTSINSTANCEDEXTPROC __glewDrawElementsInstancedEXT; }
# 9744 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWRANGEELEMENTSEXTPROC __glewDrawRangeElementsEXT; }
# 9746 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDPOINTEREXTPROC __glewFogCoordPointerEXT; }
# 9747 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDDEXTPROC __glewFogCoorddEXT; }
# 9748 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDDVEXTPROC __glewFogCoorddvEXT; }
# 9749 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDFEXTPROC __glewFogCoordfEXT; }
# 9750 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDFVEXTPROC __glewFogCoordfvEXT; }
# 9752 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTCOLORMATERIALEXTPROC __glewFragmentColorMaterialEXT; }
# 9753 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELFEXTPROC __glewFragmentLightModelfEXT; }
# 9754 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELFVEXTPROC __glewFragmentLightModelfvEXT; }
# 9755 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELIEXTPROC __glewFragmentLightModeliEXT; }
# 9756 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELIVEXTPROC __glewFragmentLightModelivEXT; }
# 9757 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTFEXTPROC __glewFragmentLightfEXT; }
# 9758 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTFVEXTPROC __glewFragmentLightfvEXT; }
# 9759 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTIEXTPROC __glewFragmentLightiEXT; }
# 9760 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTIVEXTPROC __glewFragmentLightivEXT; }
# 9761 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALFEXTPROC __glewFragmentMaterialfEXT; }
# 9762 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALFVEXTPROC __glewFragmentMaterialfvEXT; }
# 9763 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALIEXTPROC __glewFragmentMaterialiEXT; }
# 9764 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALIVEXTPROC __glewFragmentMaterialivEXT; }
# 9765 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTLIGHTFVEXTPROC __glewGetFragmentLightfvEXT; }
# 9766 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTLIGHTIVEXTPROC __glewGetFragmentLightivEXT; }
# 9767 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTMATERIALFVEXTPROC __glewGetFragmentMaterialfvEXT; }
# 9768 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTMATERIALIVEXTPROC __glewGetFragmentMaterialivEXT; }
# 9769 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLIGHTENVIEXTPROC __glewLightEnviEXT; }
# 9771 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBLITFRAMEBUFFEREXTPROC __glewBlitFramebufferEXT; }
# 9773 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC __glewRenderbufferStorageMultisampleEXT; }
# 9775 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDFRAMEBUFFEREXTPROC __glewBindFramebufferEXT; }
# 9776 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDRENDERBUFFEREXTPROC __glewBindRenderbufferEXT; }
# 9777 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC __glewCheckFramebufferStatusEXT; }
# 9778 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEFRAMEBUFFERSEXTPROC __glewDeleteFramebuffersEXT; }
# 9779 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETERENDERBUFFERSEXTPROC __glewDeleteRenderbuffersEXT; }
# 9780 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC __glewFramebufferRenderbufferEXT; }
# 9781 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC __glewFramebufferTexture1DEXT; }
# 9782 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC __glewFramebufferTexture2DEXT; }
# 9783 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC __glewFramebufferTexture3DEXT; }
# 9784 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENFRAMEBUFFERSEXTPROC __glewGenFramebuffersEXT; }
# 9785 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENRENDERBUFFERSEXTPROC __glewGenRenderbuffersEXT; }
# 9786 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENERATEMIPMAPEXTPROC __glewGenerateMipmapEXT; }
# 9787 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC __glewGetFramebufferAttachmentParameterivEXT; }
# 9788 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC __glewGetRenderbufferParameterivEXT; }
# 9789 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISFRAMEBUFFEREXTPROC __glewIsFramebufferEXT; }
# 9790 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISRENDERBUFFEREXTPROC __glewIsRenderbufferEXT; }
# 9791 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRENDERBUFFERSTORAGEEXTPROC __glewRenderbufferStorageEXT; }
# 9793 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTUREEXTPROC __glewFramebufferTextureEXT; }
# 9794 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC __glewFramebufferTextureFaceEXT; }
# 9795 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC __glewFramebufferTextureLayerEXT; }
# 9796 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETERIEXTPROC __glewProgramParameteriEXT; }
# 9798 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERS4FVEXTPROC __glewProgramEnvParameters4fvEXT; }
# 9799 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC __glewProgramLocalParameters4fvEXT; }
# 9801 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDFRAGDATALOCATIONEXTPROC __glewBindFragDataLocationEXT; }
# 9802 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGDATALOCATIONEXTPROC __glewGetFragDataLocationEXT; }
# 9803 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETUNIFORMUIVEXTPROC __glewGetUniformuivEXT; }
# 9804 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBIIVEXTPROC __glewGetVertexAttribIivEXT; }
# 9805 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBIUIVEXTPROC __glewGetVertexAttribIuivEXT; }
# 9806 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1UIEXTPROC __glewUniform1uiEXT; }
# 9807 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM1UIVEXTPROC __glewUniform1uivEXT; }
# 9808 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2UIEXTPROC __glewUniform2uiEXT; }
# 9809 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM2UIVEXTPROC __glewUniform2uivEXT; }
# 9810 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3UIEXTPROC __glewUniform3uiEXT; }
# 9811 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM3UIVEXTPROC __glewUniform3uivEXT; }
# 9812 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4UIEXTPROC __glewUniform4uiEXT; }
# 9813 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLUNIFORM4UIVEXTPROC __glewUniform4uivEXT; }
# 9814 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI1IEXTPROC __glewVertexAttribI1iEXT; }
# 9815 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI1IVEXTPROC __glewVertexAttribI1ivEXT; }
# 9816 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI1UIEXTPROC __glewVertexAttribI1uiEXT; }
# 9817 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI1UIVEXTPROC __glewVertexAttribI1uivEXT; }
# 9818 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI2IEXTPROC __glewVertexAttribI2iEXT; }
# 9819 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI2IVEXTPROC __glewVertexAttribI2ivEXT; }
# 9820 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI2UIEXTPROC __glewVertexAttribI2uiEXT; }
# 9821 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI2UIVEXTPROC __glewVertexAttribI2uivEXT; }
# 9822 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI3IEXTPROC __glewVertexAttribI3iEXT; }
# 9823 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI3IVEXTPROC __glewVertexAttribI3ivEXT; }
# 9824 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI3UIEXTPROC __glewVertexAttribI3uiEXT; }
# 9825 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI3UIVEXTPROC __glewVertexAttribI3uivEXT; }
# 9826 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4BVEXTPROC __glewVertexAttribI4bvEXT; }
# 9827 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4IEXTPROC __glewVertexAttribI4iEXT; }
# 9828 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4IVEXTPROC __glewVertexAttribI4ivEXT; }
# 9829 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4SVEXTPROC __glewVertexAttribI4svEXT; }
# 9830 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4UBVEXTPROC __glewVertexAttribI4ubvEXT; }
# 9831 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4UIEXTPROC __glewVertexAttribI4uiEXT; }
# 9832 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4UIVEXTPROC __glewVertexAttribI4uivEXT; }
# 9833 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBI4USVEXTPROC __glewVertexAttribI4usvEXT; }
# 9834 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBIPOINTEREXTPROC __glewVertexAttribIPointerEXT; }
# 9836 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMEXTPROC __glewGetHistogramEXT; }
# 9837 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMPARAMETERFVEXTPROC __glewGetHistogramParameterfvEXT; }
# 9838 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETHISTOGRAMPARAMETERIVEXTPROC __glewGetHistogramParameterivEXT; }
# 9839 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXEXTPROC __glewGetMinmaxEXT; }
# 9840 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXPARAMETERFVEXTPROC __glewGetMinmaxParameterfvEXT; }
# 9841 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMINMAXPARAMETERIVEXTPROC __glewGetMinmaxParameterivEXT; }
# 9842 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLHISTOGRAMEXTPROC __glewHistogramEXT; }
# 9843 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMINMAXEXTPROC __glewMinmaxEXT; }
# 9844 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRESETHISTOGRAMEXTPROC __glewResetHistogramEXT; }
# 9845 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRESETMINMAXEXTPROC __glewResetMinmaxEXT; }
# 9847 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLINDEXFUNCEXTPROC __glewIndexFuncEXT; }
# 9849 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLINDEXMATERIALEXTPROC __glewIndexMaterialEXT; }
# 9851 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLAPPLYTEXTUREEXTPROC __glewApplyTextureEXT; }
# 9852 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXTURELIGHTEXTPROC __glewTextureLightEXT; }
# 9853 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXTUREMATERIALEXTPROC __glewTextureMaterialEXT; }
# 9855 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWARRAYSEXTPROC __glewMultiDrawArraysEXT; }
# 9856 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIDRAWELEMENTSEXTPROC __glewMultiDrawElementsEXT; }
# 9858 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLEMASKEXTPROC __glewSampleMaskEXT; }
# 9859 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLEPATTERNEXTPROC __glewSamplePatternEXT; }
# 9861 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEEXTPROC __glewColorTableEXT; }
# 9862 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEEXTPROC __glewGetColorTableEXT; }
# 9863 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERFVEXTPROC __glewGetColorTableParameterfvEXT; }
# 9864 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERIVEXTPROC __glewGetColorTableParameterivEXT; }
# 9866 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC __glewGetPixelTransformParameterfvEXT; }
# 9867 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC __glewGetPixelTransformParameterivEXT; }
# 9868 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELTRANSFORMPARAMETERFEXTPROC __glewPixelTransformParameterfEXT; }
# 9869 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC __glewPixelTransformParameterfvEXT; }
# 9870 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELTRANSFORMPARAMETERIEXTPROC __glewPixelTransformParameteriEXT; }
# 9871 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC __glewPixelTransformParameterivEXT; }
# 9873 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFEXTPROC __glewPointParameterfEXT; }
# 9874 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERFVEXTPROC __glewPointParameterfvEXT; }
# 9876 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOLYGONOFFSETEXTPROC __glewPolygonOffsetEXT; }
# 9878 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINSCENEEXTPROC __glewBeginSceneEXT; }
# 9879 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDSCENEEXTPROC __glewEndSceneEXT; }
# 9881 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3BEXTPROC __glewSecondaryColor3bEXT; }
# 9882 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3BVEXTPROC __glewSecondaryColor3bvEXT; }
# 9883 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3DEXTPROC __glewSecondaryColor3dEXT; }
# 9884 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3DVEXTPROC __glewSecondaryColor3dvEXT; }
# 9885 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3FEXTPROC __glewSecondaryColor3fEXT; }
# 9886 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3FVEXTPROC __glewSecondaryColor3fvEXT; }
# 9887 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3IEXTPROC __glewSecondaryColor3iEXT; }
# 9888 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3IVEXTPROC __glewSecondaryColor3ivEXT; }
# 9889 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3SEXTPROC __glewSecondaryColor3sEXT; }
# 9890 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3SVEXTPROC __glewSecondaryColor3svEXT; }
# 9891 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UBEXTPROC __glewSecondaryColor3ubEXT; }
# 9892 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UBVEXTPROC __glewSecondaryColor3ubvEXT; }
# 9893 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UIEXTPROC __glewSecondaryColor3uiEXT; }
# 9894 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3UIVEXTPROC __glewSecondaryColor3uivEXT; }
# 9895 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3USEXTPROC __glewSecondaryColor3usEXT; }
# 9896 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3USVEXTPROC __glewSecondaryColor3usvEXT; }
# 9897 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLORPOINTEREXTPROC __glewSecondaryColorPointerEXT; }
# 9899 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLACTIVESTENCILFACEEXTPROC __glewActiveStencilFaceEXT; }
# 9901 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSUBIMAGE1DEXTPROC __glewTexSubImage1DEXT; }
# 9902 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSUBIMAGE2DEXTPROC __glewTexSubImage2DEXT; }
# 9903 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSUBIMAGE3DEXTPROC __glewTexSubImage3DEXT; }
# 9905 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXIMAGE3DEXTPROC __glewTexImage3DEXT; }
# 9907 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXBUFFEREXTPROC __glewTexBufferEXT; }
# 9909 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLEARCOLORIIEXTPROC __glewClearColorIiEXT; }
# 9910 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLEARCOLORIUIEXTPROC __glewClearColorIuiEXT; }
# 9911 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXPARAMETERIIVEXTPROC __glewGetTexParameterIivEXT; }
# 9912 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXPARAMETERIUIVEXTPROC __glewGetTexParameterIuivEXT; }
# 9913 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXPARAMETERIIVEXTPROC __glewTexParameterIivEXT; }
# 9914 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXPARAMETERIUIVEXTPROC __glewTexParameterIuivEXT; }
# 9916 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLARETEXTURESRESIDENTEXTPROC __glewAreTexturesResidentEXT; }
# 9917 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDTEXTUREEXTPROC __glewBindTextureEXT; }
# 9918 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETETEXTURESEXTPROC __glewDeleteTexturesEXT; }
# 9919 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENTEXTURESEXTPROC __glewGenTexturesEXT; }
# 9920 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISTEXTUREEXTPROC __glewIsTextureEXT; }
# 9921 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPRIORITIZETEXTURESEXTPROC __glewPrioritizeTexturesEXT; }
# 9923 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXTURENORMALEXTPROC __glewTextureNormalEXT; }
# 9925 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTI64VEXTPROC __glewGetQueryObjecti64vEXT; }
# 9926 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETQUERYOBJECTUI64VEXTPROC __glewGetQueryObjectui64vEXT; }
# 9928 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLARRAYELEMENTEXTPROC __glewArrayElementEXT; }
# 9929 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORPOINTEREXTPROC __glewColorPointerEXT; }
# 9930 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWARRAYSEXTPROC __glewDrawArraysEXT; }
# 9931 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLEDGEFLAGPOINTEREXTPROC __glewEdgeFlagPointerEXT; }
# 9932 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPOINTERVEXTPROC __glewGetPointervEXT; }
# 9933 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLINDEXPOINTEREXTPROC __glewIndexPointerEXT; }
# 9934 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALPOINTEREXTPROC __glewNormalPointerEXT; }
# 9935 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORDPOINTEREXTPROC __glewTexCoordPointerEXT; }
# 9936 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXPOINTEREXTPROC __glewVertexPointerEXT; }
# 9938 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINVERTEXSHADEREXTPROC __glewBeginVertexShaderEXT; }
# 9939 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDLIGHTPARAMETEREXTPROC __glewBindLightParameterEXT; }
# 9940 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDMATERIALPARAMETEREXTPROC __glewBindMaterialParameterEXT; }
# 9941 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDPARAMETEREXTPROC __glewBindParameterEXT; }
# 9942 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDTEXGENPARAMETEREXTPROC __glewBindTexGenParameterEXT; }
# 9943 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDTEXTUREUNITPARAMETEREXTPROC __glewBindTextureUnitParameterEXT; }
# 9944 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDVERTEXSHADEREXTPROC __glewBindVertexShaderEXT; }
# 9945 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEVERTEXSHADEREXTPROC __glewDeleteVertexShaderEXT; }
# 9946 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC __glewDisableVariantClientStateEXT; }
# 9947 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENABLEVARIANTCLIENTSTATEEXTPROC __glewEnableVariantClientStateEXT; }
# 9948 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDVERTEXSHADEREXTPROC __glewEndVertexShaderEXT; }
# 9949 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLEXTRACTCOMPONENTEXTPROC __glewExtractComponentEXT; }
# 9950 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENSYMBOLSEXTPROC __glewGenSymbolsEXT; }
# 9951 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENVERTEXSHADERSEXTPROC __glewGenVertexShadersEXT; }
# 9952 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETINVARIANTBOOLEANVEXTPROC __glewGetInvariantBooleanvEXT; }
# 9953 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETINVARIANTFLOATVEXTPROC __glewGetInvariantFloatvEXT; }
# 9954 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETINVARIANTINTEGERVEXTPROC __glewGetInvariantIntegervEXT; }
# 9955 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC __glewGetLocalConstantBooleanvEXT; }
# 9956 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETLOCALCONSTANTFLOATVEXTPROC __glewGetLocalConstantFloatvEXT; }
# 9957 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETLOCALCONSTANTINTEGERVEXTPROC __glewGetLocalConstantIntegervEXT; }
# 9958 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTBOOLEANVEXTPROC __glewGetVariantBooleanvEXT; }
# 9959 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTFLOATVEXTPROC __glewGetVariantFloatvEXT; }
# 9960 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTINTEGERVEXTPROC __glewGetVariantIntegervEXT; }
# 9961 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARIANTPOINTERVEXTPROC __glewGetVariantPointervEXT; }
# 9962 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLINSERTCOMPONENTEXTPROC __glewInsertComponentEXT; }
# 9963 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISVARIANTENABLEDEXTPROC __glewIsVariantEnabledEXT; }
# 9964 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSETINVARIANTEXTPROC __glewSetInvariantEXT; }
# 9965 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSETLOCALCONSTANTEXTPROC __glewSetLocalConstantEXT; }
# 9966 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHADEROP1EXTPROC __glewShaderOp1EXT; }
# 9967 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHADEROP2EXTPROC __glewShaderOp2EXT; }
# 9968 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHADEROP3EXTPROC __glewShaderOp3EXT; }
# 9969 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSWIZZLEEXTPROC __glewSwizzleEXT; }
# 9970 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTPOINTEREXTPROC __glewVariantPointerEXT; }
# 9971 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTBVEXTPROC __glewVariantbvEXT; }
# 9972 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTDVEXTPROC __glewVariantdvEXT; }
# 9973 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTFVEXTPROC __glewVariantfvEXT; }
# 9974 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTIVEXTPROC __glewVariantivEXT; }
# 9975 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTSVEXTPROC __glewVariantsvEXT; }
# 9976 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTUBVEXTPROC __glewVariantubvEXT; }
# 9977 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTUIVEXTPROC __glewVariantuivEXT; }
# 9978 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVARIANTUSVEXTPROC __glewVariantusvEXT; }
# 9979 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWRITEMASKEXTPROC __glewWriteMaskEXT; }
# 9981 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXWEIGHTPOINTEREXTPROC __glewVertexWeightPointerEXT; }
# 9982 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXWEIGHTFEXTPROC __glewVertexWeightfEXT; }
# 9983 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXWEIGHTFVEXTPROC __glewVertexWeightfvEXT; }
# 9985 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMETERMINATORGREMEDYPROC __glewFrameTerminatorGREMEDY; }
# 9987 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSTRINGMARKERGREMEDYPROC __glewStringMarkerGREMEDY; }
# 9989 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC __glewGetImageTransformParameterfvHP; }
# 9990 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC __glewGetImageTransformParameterivHP; }
# 9991 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLIMAGETRANSFORMPARAMETERFHPPROC __glewImageTransformParameterfHP; }
# 9992 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLIMAGETRANSFORMPARAMETERFVHPPROC __glewImageTransformParameterfvHP; }
# 9993 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLIMAGETRANSFORMPARAMETERIHPPROC __glewImageTransformParameteriHP; }
# 9994 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLIMAGETRANSFORMPARAMETERIVHPPROC __glewImageTransformParameterivHP; }
# 9996 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIMODEDRAWARRAYSIBMPROC __glewMultiModeDrawArraysIBM; }
# 9997 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTIMODEDRAWELEMENTSIBMPROC __glewMultiModeDrawElementsIBM; }
# 9999 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORPOINTERLISTIBMPROC __glewColorPointerListIBM; }
# 10000 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLEDGEFLAGPOINTERLISTIBMPROC __glewEdgeFlagPointerListIBM; }
# 10001 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDPOINTERLISTIBMPROC __glewFogCoordPointerListIBM; }
# 10002 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLINDEXPOINTERLISTIBMPROC __glewIndexPointerListIBM; }
# 10003 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALPOINTERLISTIBMPROC __glewNormalPointerListIBM; }
# 10004 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLORPOINTERLISTIBMPROC __glewSecondaryColorPointerListIBM; }
# 10005 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORDPOINTERLISTIBMPROC __glewTexCoordPointerListIBM; }
# 10006 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXPOINTERLISTIBMPROC __glewVertexPointerListIBM; }
# 10008 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORPOINTERVINTELPROC __glewColorPointervINTEL; }
# 10009 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMALPOINTERVINTELPROC __glewNormalPointervINTEL; }
# 10010 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORDPOINTERVINTELPROC __glewTexCoordPointervINTEL; }
# 10011 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXPOINTERVINTELPROC __glewVertexPointervINTEL; }
# 10013 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSCISSORFUNCINTELPROC __glewTexScissorFuncINTEL; }
# 10014 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSCISSORINTELPROC __glewTexScissorINTEL; }
# 10016 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBUFFERREGIONENABLEDEXTPROC __glewBufferRegionEnabledEXT; }
# 10017 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEBUFFERREGIONEXTPROC __glewDeleteBufferRegionEXT; }
# 10018 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDRAWBUFFERREGIONEXTPROC __glewDrawBufferRegionEXT; }
# 10019 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNEWBUFFERREGIONEXTPROC __glewNewBufferRegionEXT; }
# 10020 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREADBUFFERREGIONEXTPROC __glewReadBufferRegionEXT; }
# 10022 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRESIZEBUFFERSMESAPROC __glewResizeBuffersMESA; }
# 10024 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DMESAPROC __glewWindowPos2dMESA; }
# 10025 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2DVMESAPROC __glewWindowPos2dvMESA; }
# 10026 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FMESAPROC __glewWindowPos2fMESA; }
# 10027 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2FVMESAPROC __glewWindowPos2fvMESA; }
# 10028 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IMESAPROC __glewWindowPos2iMESA; }
# 10029 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2IVMESAPROC __glewWindowPos2ivMESA; }
# 10030 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SMESAPROC __glewWindowPos2sMESA; }
# 10031 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS2SVMESAPROC __glewWindowPos2svMESA; }
# 10032 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DMESAPROC __glewWindowPos3dMESA; }
# 10033 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3DVMESAPROC __glewWindowPos3dvMESA; }
# 10034 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FMESAPROC __glewWindowPos3fMESA; }
# 10035 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3FVMESAPROC __glewWindowPos3fvMESA; }
# 10036 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IMESAPROC __glewWindowPos3iMESA; }
# 10037 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3IVMESAPROC __glewWindowPos3ivMESA; }
# 10038 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SMESAPROC __glewWindowPos3sMESA; }
# 10039 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS3SVMESAPROC __glewWindowPos3svMESA; }
# 10040 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4DMESAPROC __glewWindowPos4dMESA; }
# 10041 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4DVMESAPROC __glewWindowPos4dvMESA; }
# 10042 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4FMESAPROC __glewWindowPos4fMESA; }
# 10043 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4FVMESAPROC __glewWindowPos4fvMESA; }
# 10044 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4IMESAPROC __glewWindowPos4iMESA; }
# 10045 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4IVMESAPROC __glewWindowPos4ivMESA; }
# 10046 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4SMESAPROC __glewWindowPos4sMESA; }
# 10047 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLWINDOWPOS4SVMESAPROC __glewWindowPos4svMESA; }
# 10049 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLEARDEPTHDNVPROC __glewClearDepthdNV; }
# 10050 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDEPTHBOUNDSDNVPROC __glewDepthBoundsdNV; }
# 10051 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDEPTHRANGEDNVPROC __glewDepthRangedNV; }
# 10053 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLEVALMAPSNVPROC __glewEvalMapsNV; }
# 10054 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMAPATTRIBPARAMETERFVNVPROC __glewGetMapAttribParameterfvNV; }
# 10055 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMAPATTRIBPARAMETERIVNVPROC __glewGetMapAttribParameterivNV; }
# 10056 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMAPCONTROLPOINTSNVPROC __glewGetMapControlPointsNV; }
# 10057 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMAPPARAMETERFVNVPROC __glewGetMapParameterfvNV; }
# 10058 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETMAPPARAMETERIVNVPROC __glewGetMapParameterivNV; }
# 10059 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPCONTROLPOINTSNVPROC __glewMapControlPointsNV; }
# 10060 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPPARAMETERFVNVPROC __glewMapParameterfvNV; }
# 10061 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMAPPARAMETERIVNVPROC __glewMapParameterivNV; }
# 10063 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEFENCESNVPROC __glewDeleteFencesNV; }
# 10064 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINISHFENCENVPROC __glewFinishFenceNV; }
# 10065 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENFENCESNVPROC __glewGenFencesNV; }
# 10066 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFENCEIVNVPROC __glewGetFenceivNV; }
# 10067 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISFENCENVPROC __glewIsFenceNV; }
# 10068 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSETFENCENVPROC __glewSetFenceNV; }
# 10069 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTESTFENCENVPROC __glewTestFenceNV; }
# 10071 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC __glewGetProgramNamedParameterdvNV; }
# 10072 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC __glewGetProgramNamedParameterfvNV; }
# 10073 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMNAMEDPARAMETER4DNVPROC __glewProgramNamedParameter4dNV; }
# 10074 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC __glewProgramNamedParameter4dvNV; }
# 10075 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMNAMEDPARAMETER4FNVPROC __glewProgramNamedParameter4fNV; }
# 10076 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC __glewProgramNamedParameter4fvNV; }
# 10078 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC __glewRenderbufferStorageMultisampleCoverageNV; }
# 10080 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMVERTEXLIMITNVPROC __glewProgramVertexLimitNV; }
# 10082 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERI4INVPROC __glewProgramEnvParameterI4iNV; }
# 10083 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERI4IVNVPROC __glewProgramEnvParameterI4ivNV; }
# 10084 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERI4UINVPROC __glewProgramEnvParameterI4uiNV; }
# 10085 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERI4UIVNVPROC __glewProgramEnvParameterI4uivNV; }
# 10086 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERSI4IVNVPROC __glewProgramEnvParametersI4ivNV; }
# 10087 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC __glewProgramEnvParametersI4uivNV; }
# 10088 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERI4INVPROC __glewProgramLocalParameterI4iNV; }
# 10089 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC __glewProgramLocalParameterI4ivNV; }
# 10090 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERI4UINVPROC __glewProgramLocalParameterI4uiNV; }
# 10091 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC __glewProgramLocalParameterI4uivNV; }
# 10092 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC __glewProgramLocalParametersI4ivNV; }
# 10093 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC __glewProgramLocalParametersI4uivNV; }
# 10095 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR3HNVPROC __glewColor3hNV; }
# 10096 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR3HVNVPROC __glewColor3hvNV; }
# 10097 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4HNVPROC __glewColor4hNV; }
# 10098 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4HVNVPROC __glewColor4hvNV; }
# 10099 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDHNVPROC __glewFogCoordhNV; }
# 10100 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGCOORDHVNVPROC __glewFogCoordhvNV; }
# 10101 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1HNVPROC __glewMultiTexCoord1hNV; }
# 10102 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD1HVNVPROC __glewMultiTexCoord1hvNV; }
# 10103 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2HNVPROC __glewMultiTexCoord2hNV; }
# 10104 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD2HVNVPROC __glewMultiTexCoord2hvNV; }
# 10105 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3HNVPROC __glewMultiTexCoord3hNV; }
# 10106 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD3HVNVPROC __glewMultiTexCoord3hvNV; }
# 10107 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4HNVPROC __glewMultiTexCoord4hNV; }
# 10108 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLMULTITEXCOORD4HVNVPROC __glewMultiTexCoord4hvNV; }
# 10109 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMAL3HNVPROC __glewNormal3hNV; }
# 10110 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMAL3HVNVPROC __glewNormal3hvNV; }
# 10111 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3HNVPROC __glewSecondaryColor3hNV; }
# 10112 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSECONDARYCOLOR3HVNVPROC __glewSecondaryColor3hvNV; }
# 10113 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD1HNVPROC __glewTexCoord1hNV; }
# 10114 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD1HVNVPROC __glewTexCoord1hvNV; }
# 10115 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2HNVPROC __glewTexCoord2hNV; }
# 10116 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2HVNVPROC __glewTexCoord2hvNV; }
# 10117 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD3HNVPROC __glewTexCoord3hNV; }
# 10118 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD3HVNVPROC __glewTexCoord3hvNV; }
# 10119 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4HNVPROC __glewTexCoord4hNV; }
# 10120 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4HVNVPROC __glewTexCoord4hvNV; }
# 10121 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX2HNVPROC __glewVertex2hNV; }
# 10122 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX2HVNVPROC __glewVertex2hvNV; }
# 10123 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX3HNVPROC __glewVertex3hNV; }
# 10124 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX3HVNVPROC __glewVertex3hvNV; }
# 10125 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX4HNVPROC __glewVertex4hNV; }
# 10126 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEX4HVNVPROC __glewVertex4hvNV; }
# 10127 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1HNVPROC __glewVertexAttrib1hNV; }
# 10128 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1HVNVPROC __glewVertexAttrib1hvNV; }
# 10129 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2HNVPROC __glewVertexAttrib2hNV; }
# 10130 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2HVNVPROC __glewVertexAttrib2hvNV; }
# 10131 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3HNVPROC __glewVertexAttrib3hNV; }
# 10132 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3HVNVPROC __glewVertexAttrib3hvNV; }
# 10133 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4HNVPROC __glewVertexAttrib4hNV; }
# 10134 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4HVNVPROC __glewVertexAttrib4hvNV; }
# 10135 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS1HVNVPROC __glewVertexAttribs1hvNV; }
# 10136 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS2HVNVPROC __glewVertexAttribs2hvNV; }
# 10137 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS3HVNVPROC __glewVertexAttribs3hvNV; }
# 10138 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS4HVNVPROC __glewVertexAttribs4hvNV; }
# 10139 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXWEIGHTHNVPROC __glewVertexWeighthNV; }
# 10140 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXWEIGHTHVNVPROC __glewVertexWeighthvNV; }
# 10142 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINOCCLUSIONQUERYNVPROC __glewBeginOcclusionQueryNV; }
# 10143 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEOCCLUSIONQUERIESNVPROC __glewDeleteOcclusionQueriesNV; }
# 10144 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDOCCLUSIONQUERYNVPROC __glewEndOcclusionQueryNV; }
# 10145 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENOCCLUSIONQUERIESNVPROC __glewGenOcclusionQueriesNV; }
# 10146 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOCCLUSIONQUERYIVNVPROC __glewGetOcclusionQueryivNV; }
# 10147 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETOCCLUSIONQUERYUIVNVPROC __glewGetOcclusionQueryuivNV; }
# 10148 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISOCCLUSIONQUERYNVPROC __glewIsOcclusionQueryNV; }
# 10150 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC __glewProgramBufferParametersIivNV; }
# 10151 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC __glewProgramBufferParametersIuivNV; }
# 10152 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC __glewProgramBufferParametersfvNV; }
# 10154 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFLUSHPIXELDATARANGENVPROC __glewFlushPixelDataRangeNV; }
# 10155 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELDATARANGENVPROC __glewPixelDataRangeNV; }
# 10157 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERINVPROC __glewPointParameteriNV; }
# 10158 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOINTPARAMETERIVNVPROC __glewPointParameterivNV; }
# 10160 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPRIMITIVERESTARTINDEXNVPROC __glewPrimitiveRestartIndexNV; }
# 10161 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPRIMITIVERESTARTNVPROC __glewPrimitiveRestartNV; }
# 10163 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERINPUTNVPROC __glewCombinerInputNV; }
# 10164 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINEROUTPUTNVPROC __glewCombinerOutputNV; }
# 10165 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERPARAMETERFNVPROC __glewCombinerParameterfNV; }
# 10166 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERPARAMETERFVNVPROC __glewCombinerParameterfvNV; }
# 10167 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERPARAMETERINVPROC __glewCombinerParameteriNV; }
# 10168 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERPARAMETERIVNVPROC __glewCombinerParameterivNV; }
# 10169 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINALCOMBINERINPUTNVPROC __glewFinalCombinerInputNV; }
# 10170 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC __glewGetCombinerInputParameterfvNV; }
# 10171 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC __glewGetCombinerInputParameterivNV; }
# 10172 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC __glewGetCombinerOutputParameterfvNV; }
# 10173 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC __glewGetCombinerOutputParameterivNV; }
# 10174 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC __glewGetFinalCombinerInputParameterfvNV; }
# 10175 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC __glewGetFinalCombinerInputParameterivNV; }
# 10177 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOMBINERSTAGEPARAMETERFVNVPROC __glewCombinerStageParameterfvNV; }
# 10178 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC __glewGetCombinerStageParameterfvNV; }
# 10180 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLACTIVEVARYINGNVPROC __glewActiveVaryingNV; }
# 10181 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBEGINTRANSFORMFEEDBACKNVPROC __glewBeginTransformFeedbackNV; }
# 10182 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDBUFFERBASENVPROC __glewBindBufferBaseNV; }
# 10183 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDBUFFEROFFSETNVPROC __glewBindBufferOffsetNV; }
# 10184 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDBUFFERRANGENVPROC __glewBindBufferRangeNV; }
# 10185 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLENDTRANSFORMFEEDBACKNVPROC __glewEndTransformFeedbackNV; }
# 10186 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETACTIVEVARYINGNVPROC __glewGetActiveVaryingNV; }
# 10187 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC __glewGetTransformFeedbackVaryingNV; }
# 10188 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVARYINGLOCATIONNVPROC __glewGetVaryingLocationNV; }
# 10189 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC __glewTransformFeedbackAttribsNV; }
# 10190 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC __glewTransformFeedbackVaryingsNV; }
# 10192 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFLUSHVERTEXARRAYRANGENVPROC __glewFlushVertexArrayRangeNV; }
# 10193 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXARRAYRANGENVPROC __glewVertexArrayRangeNV; }
# 10195 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLAREPROGRAMSRESIDENTNVPROC __glewAreProgramsResidentNV; }
# 10196 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLBINDPROGRAMNVPROC __glewBindProgramNV; }
# 10197 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEPROGRAMSNVPROC __glewDeleteProgramsNV; }
# 10198 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLEXECUTEPROGRAMNVPROC __glewExecuteProgramNV; }
# 10199 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENPROGRAMSNVPROC __glewGenProgramsNV; }
# 10200 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMPARAMETERDVNVPROC __glewGetProgramParameterdvNV; }
# 10201 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMPARAMETERFVNVPROC __glewGetProgramParameterfvNV; }
# 10202 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMSTRINGNVPROC __glewGetProgramStringNV; }
# 10203 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETPROGRAMIVNVPROC __glewGetProgramivNV; }
# 10204 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTRACKMATRIXIVNVPROC __glewGetTrackMatrixivNV; }
# 10205 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBPOINTERVNVPROC __glewGetVertexAttribPointervNV; }
# 10206 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBDVNVPROC __glewGetVertexAttribdvNV; }
# 10207 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBFVNVPROC __glewGetVertexAttribfvNV; }
# 10208 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETVERTEXATTRIBIVNVPROC __glewGetVertexAttribivNV; }
# 10209 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISPROGRAMNVPROC __glewIsProgramNV; }
# 10210 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLLOADPROGRAMNVPROC __glewLoadProgramNV; }
# 10211 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETER4DNVPROC __glewProgramParameter4dNV; }
# 10212 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETER4DVNVPROC __glewProgramParameter4dvNV; }
# 10213 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETER4FNVPROC __glewProgramParameter4fNV; }
# 10214 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETER4FVNVPROC __glewProgramParameter4fvNV; }
# 10215 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETERS4DVNVPROC __glewProgramParameters4dvNV; }
# 10216 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPROGRAMPARAMETERS4FVNVPROC __glewProgramParameters4fvNV; }
# 10217 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREQUESTRESIDENTPROGRAMSNVPROC __glewRequestResidentProgramsNV; }
# 10218 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTRACKMATRIXNVPROC __glewTrackMatrixNV; }
# 10219 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DNVPROC __glewVertexAttrib1dNV; }
# 10220 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1DVNVPROC __glewVertexAttrib1dvNV; }
# 10221 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FNVPROC __glewVertexAttrib1fNV; }
# 10222 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1FVNVPROC __glewVertexAttrib1fvNV; }
# 10223 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SNVPROC __glewVertexAttrib1sNV; }
# 10224 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB1SVNVPROC __glewVertexAttrib1svNV; }
# 10225 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DNVPROC __glewVertexAttrib2dNV; }
# 10226 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2DVNVPROC __glewVertexAttrib2dvNV; }
# 10227 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FNVPROC __glewVertexAttrib2fNV; }
# 10228 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2FVNVPROC __glewVertexAttrib2fvNV; }
# 10229 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SNVPROC __glewVertexAttrib2sNV; }
# 10230 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB2SVNVPROC __glewVertexAttrib2svNV; }
# 10231 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DNVPROC __glewVertexAttrib3dNV; }
# 10232 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3DVNVPROC __glewVertexAttrib3dvNV; }
# 10233 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FNVPROC __glewVertexAttrib3fNV; }
# 10234 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3FVNVPROC __glewVertexAttrib3fvNV; }
# 10235 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SNVPROC __glewVertexAttrib3sNV; }
# 10236 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB3SVNVPROC __glewVertexAttrib3svNV; }
# 10237 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DNVPROC __glewVertexAttrib4dNV; }
# 10238 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4DVNVPROC __glewVertexAttrib4dvNV; }
# 10239 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FNVPROC __glewVertexAttrib4fNV; }
# 10240 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4FVNVPROC __glewVertexAttrib4fvNV; }
# 10241 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SNVPROC __glewVertexAttrib4sNV; }
# 10242 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4SVNVPROC __glewVertexAttrib4svNV; }
# 10243 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UBNVPROC __glewVertexAttrib4ubNV; }
# 10244 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIB4UBVNVPROC __glewVertexAttrib4ubvNV; }
# 10245 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBPOINTERNVPROC __glewVertexAttribPointerNV; }
# 10246 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS1DVNVPROC __glewVertexAttribs1dvNV; }
# 10247 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS1FVNVPROC __glewVertexAttribs1fvNV; }
# 10248 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS1SVNVPROC __glewVertexAttribs1svNV; }
# 10249 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS2DVNVPROC __glewVertexAttribs2dvNV; }
# 10250 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS2FVNVPROC __glewVertexAttribs2fvNV; }
# 10251 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS2SVNVPROC __glewVertexAttribs2svNV; }
# 10252 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS3DVNVPROC __glewVertexAttribs3dvNV; }
# 10253 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS3FVNVPROC __glewVertexAttribs3fvNV; }
# 10254 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS3SVNVPROC __glewVertexAttribs3svNV; }
# 10255 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS4DVNVPROC __glewVertexAttribs4dvNV; }
# 10256 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS4FVNVPROC __glewVertexAttribs4fvNV; }
# 10257 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS4SVNVPROC __glewVertexAttribs4svNV; }
# 10258 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLVERTEXATTRIBS4UBVNVPROC __glewVertexAttribs4ubvNV; }
# 10260 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLEARDEPTHFOESPROC __glewClearDepthfOES; }
# 10261 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCLIPPLANEFOESPROC __glewClipPlanefOES; }
# 10262 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDEPTHRANGEFOESPROC __glewDepthRangefOES; }
# 10263 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRUSTUMFOESPROC __glewFrustumfOES; }
# 10264 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCLIPPLANEFOESPROC __glewGetClipPlanefOES; }
# 10265 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLORTHOFOESPROC __glewOrthofOES; }
# 10267 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDETAILTEXFUNCSGISPROC __glewDetailTexFuncSGIS; }
# 10268 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETDETAILTEXFUNCSGISPROC __glewGetDetailTexFuncSGIS; }
# 10270 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFOGFUNCSGISPROC __glewFogFuncSGIS; }
# 10271 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFOGFUNCSGISPROC __glewGetFogFuncSGIS; }
# 10273 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLEMASKSGISPROC __glewSampleMaskSGIS; }
# 10274 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSAMPLEPATTERNSGISPROC __glewSamplePatternSGIS; }
# 10276 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETSHARPENTEXFUNCSGISPROC __glewGetSharpenTexFuncSGIS; }
# 10277 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSHARPENTEXFUNCSGISPROC __glewSharpenTexFuncSGIS; }
# 10279 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXIMAGE4DSGISPROC __glewTexImage4DSGIS; }
# 10280 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXSUBIMAGE4DSGISPROC __glewTexSubImage4DSGIS; }
# 10282 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETTEXFILTERFUNCSGISPROC __glewGetTexFilterFuncSGIS; }
# 10283 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXFILTERFUNCSGISPROC __glewTexFilterFuncSGIS; }
# 10285 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLASYNCMARKERSGIXPROC __glewAsyncMarkerSGIX; }
# 10286 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLDELETEASYNCMARKERSSGIXPROC __glewDeleteAsyncMarkersSGIX; }
# 10287 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINISHASYNCSGIXPROC __glewFinishAsyncSGIX; }
# 10288 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGENASYNCMARKERSSGIXPROC __glewGenAsyncMarkersSGIX; }
# 10289 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLISASYNCMARKERSGIXPROC __glewIsAsyncMarkerSGIX; }
# 10290 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPOLLASYNCSGIXPROC __glewPollAsyncSGIX; }
# 10292 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFLUSHRASTERSGIXPROC __glewFlushRasterSGIX; }
# 10294 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXTUREFOGSGIXPROC __glewTextureFogSGIX; }
# 10296 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTCOLORMATERIALSGIXPROC __glewFragmentColorMaterialSGIX; }
# 10297 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELFSGIXPROC __glewFragmentLightModelfSGIX; }
# 10298 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELFVSGIXPROC __glewFragmentLightModelfvSGIX; }
# 10299 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELISGIXPROC __glewFragmentLightModeliSGIX; }
# 10300 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTMODELIVSGIXPROC __glewFragmentLightModelivSGIX; }
# 10301 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTFSGIXPROC __glewFragmentLightfSGIX; }
# 10302 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTFVSGIXPROC __glewFragmentLightfvSGIX; }
# 10303 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTISGIXPROC __glewFragmentLightiSGIX; }
# 10304 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTLIGHTIVSGIXPROC __glewFragmentLightivSGIX; }
# 10305 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALFSGIXPROC __glewFragmentMaterialfSGIX; }
# 10306 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALFVSGIXPROC __glewFragmentMaterialfvSGIX; }
# 10307 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALISGIXPROC __glewFragmentMaterialiSGIX; }
# 10308 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAGMENTMATERIALIVSGIXPROC __glewFragmentMaterialivSGIX; }
# 10309 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTLIGHTFVSGIXPROC __glewGetFragmentLightfvSGIX; }
# 10310 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTLIGHTIVSGIXPROC __glewGetFragmentLightivSGIX; }
# 10311 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTMATERIALFVSGIXPROC __glewGetFragmentMaterialfvSGIX; }
# 10312 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETFRAGMENTMATERIALIVSGIXPROC __glewGetFragmentMaterialivSGIX; }
# 10314 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFRAMEZOOMSGIXPROC __glewFrameZoomSGIX; }
# 10316 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLPIXELTEXGENSGIXPROC __glewPixelTexGenSGIX; }
# 10318 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREFERENCEPLANESGIXPROC __glewReferencePlaneSGIX; }
# 10320 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSPRITEPARAMETERFSGIXPROC __glewSpriteParameterfSGIX; }
# 10321 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSPRITEPARAMETERFVSGIXPROC __glewSpriteParameterfvSGIX; }
# 10322 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSPRITEPARAMETERISGIXPROC __glewSpriteParameteriSGIX; }
# 10323 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLSPRITEPARAMETERIVSGIXPROC __glewSpriteParameterivSGIX; }
# 10325 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTAGSAMPLEBUFFERSGIXPROC __glewTagSampleBufferSGIX; }
# 10327 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEPARAMETERFVSGIPROC __glewColorTableParameterfvSGI; }
# 10328 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLEPARAMETERIVSGIPROC __glewColorTableParameterivSGI; }
# 10329 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLORTABLESGIPROC __glewColorTableSGI; }
# 10330 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOPYCOLORTABLESGIPROC __glewCopyColorTableSGI; }
# 10331 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERFVSGIPROC __glewGetColorTableParameterfvSGI; }
# 10332 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLEPARAMETERIVSGIPROC __glewGetColorTableParameterivSGI; }
# 10333 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGETCOLORTABLESGIPROC __glewGetColorTableSGI; }
# 10335 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLFINISHTEXTURESUNXPROC __glewFinishTextureSUNX; }
# 10337 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORBSUNPROC __glewGlobalAlphaFactorbSUN; }
# 10338 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORDSUNPROC __glewGlobalAlphaFactordSUN; }
# 10339 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORFSUNPROC __glewGlobalAlphaFactorfSUN; }
# 10340 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORISUNPROC __glewGlobalAlphaFactoriSUN; }
# 10341 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORSSUNPROC __glewGlobalAlphaFactorsSUN; }
# 10342 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORUBSUNPROC __glewGlobalAlphaFactorubSUN; }
# 10343 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORUISUNPROC __glewGlobalAlphaFactoruiSUN; }
# 10344 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLGLOBALALPHAFACTORUSSUNPROC __glewGlobalAlphaFactorusSUN; }
# 10346 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREADVIDEOPIXELSSUNPROC __glewReadVideoPixelsSUN; }
# 10348 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEPOINTERSUNPROC __glewReplacementCodePointerSUN; }
# 10349 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUBSUNPROC __glewReplacementCodeubSUN; }
# 10350 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUBVSUNPROC __glewReplacementCodeubvSUN; }
# 10351 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUISUNPROC __glewReplacementCodeuiSUN; }
# 10352 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUIVSUNPROC __glewReplacementCodeuivSUN; }
# 10353 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUSSUNPROC __glewReplacementCodeusSUN; }
# 10354 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUSVSUNPROC __glewReplacementCodeusvSUN; }
# 10356 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR3FVERTEX3FSUNPROC __glewColor3fVertex3fSUN; }
# 10357 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR3FVERTEX3FVSUNPROC __glewColor3fVertex3fvSUN; }
# 10358 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC __glewColor4fNormal3fVertex3fSUN; }
# 10359 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC __glewColor4fNormal3fVertex3fvSUN; }
# 10360 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4UBVERTEX2FSUNPROC __glewColor4ubVertex2fSUN; }
# 10361 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4UBVERTEX2FVSUNPROC __glewColor4ubVertex2fvSUN; }
# 10362 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4UBVERTEX3FSUNPROC __glewColor4ubVertex3fSUN; }
# 10363 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLCOLOR4UBVERTEX3FVSUNPROC __glewColor4ubVertex3fvSUN; }
# 10364 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMAL3FVERTEX3FSUNPROC __glewNormal3fVertex3fSUN; }
# 10365 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLNORMAL3FVERTEX3FVSUNPROC __glewNormal3fVertex3fvSUN; }
# 10366 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC __glewReplacementCodeuiColor3fVertex3fSUN; }
# 10367 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC __glewReplacementCodeuiColor3fVertex3fvSUN; }
# 10368 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC __glewReplacementCodeuiColor4fNormal3fVertex3fSUN; }
# 10369 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC __glewReplacementCodeuiColor4fNormal3fVertex3fvSUN; }
# 10370 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC __glewReplacementCodeuiColor4ubVertex3fSUN; }
# 10371 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC __glewReplacementCodeuiColor4ubVertex3fvSUN; }
# 10372 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC __glewReplacementCodeuiNormal3fVertex3fSUN; }
# 10373 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC __glewReplacementCodeuiNormal3fVertex3fvSUN; }
# 10374 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC __glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN; }
# 10375 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC __glewReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN; }
# 10376 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC __glewReplacementCodeuiTexCoord2fNormal3fVertex3fSUN; }
# 10377 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC __glewReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN; }
# 10378 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC __glewReplacementCodeuiTexCoord2fVertex3fSUN; }
# 10379 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC __glewReplacementCodeuiTexCoord2fVertex3fvSUN; }
# 10380 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC __glewReplacementCodeuiVertex3fSUN; }
# 10381 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC __glewReplacementCodeuiVertex3fvSUN; }
# 10382 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC __glewTexCoord2fColor3fVertex3fSUN; }
# 10383 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC __glewTexCoord2fColor3fVertex3fvSUN; }
# 10384 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC __glewTexCoord2fColor4fNormal3fVertex3fSUN; }
# 10385 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC __glewTexCoord2fColor4fNormal3fVertex3fvSUN; }
# 10386 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC __glewTexCoord2fColor4ubVertex3fSUN; }
# 10387 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC __glewTexCoord2fColor4ubVertex3fvSUN; }
# 10388 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC __glewTexCoord2fNormal3fVertex3fSUN; }
# 10389 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC __glewTexCoord2fNormal3fVertex3fvSUN; }
# 10390 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FVERTEX3FSUNPROC __glewTexCoord2fVertex3fSUN; }
# 10391 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD2FVERTEX3FVSUNPROC __glewTexCoord2fVertex3fvSUN; }
# 10392 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC __glewTexCoord4fColor4fNormal3fVertex4fSUN; }
# 10393 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC __glewTexCoord4fColor4fNormal3fVertex4fvSUN; }
# 10394 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4FVERTEX4FSUNPROC __glewTexCoord4fVertex4fSUN; }
# 10395 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLTEXCOORD4FVERTEX4FVSUNPROC __glewTexCoord4fVertex4fvSUN; }
# 10397 "/usr/include/GL/glew.h" 3
extern "C" { extern PFNGLADDSWAPHINTRECTWINPROC __glewAddSwapHintRectWIN; }
# 10404 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_1_1; }
# 10405 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_1_2; }
# 10406 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_1_3; }
# 10407 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_1_4; }
# 10408 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_1_5; }
# 10409 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_2_0; }
# 10410 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_VERSION_2_1; }
# 10411 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_3DFX_multisample; }
# 10412 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_3DFX_tbuffer; }
# 10413 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_3DFX_texture_compression_FXT1; }
# 10414 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_client_storage; }
# 10415 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_element_array; }
# 10416 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_fence; }
# 10417 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_float_pixels; }
# 10418 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_flush_buffer_range; }
# 10419 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_pixel_buffer; }
# 10420 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_specular_vector; }
# 10421 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_texture_range; }
# 10422 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_transform_hint; }
# 10423 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_vertex_array_object; }
# 10424 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_vertex_array_range; }
# 10425 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_APPLE_ycbcr_422; }
# 10426 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_color_buffer_float; }
# 10427 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_depth_texture; }
# 10428 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_draw_buffers; }
# 10429 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_fragment_program; }
# 10430 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_fragment_program_shadow; }
# 10431 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_fragment_shader; }
# 10432 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_half_float_pixel; }
# 10433 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_imaging; }
# 10434 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_matrix_palette; }
# 10435 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_multisample; }
# 10436 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_multitexture; }
# 10437 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_occlusion_query; }
# 10438 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_pixel_buffer_object; }
# 10439 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_point_parameters; }
# 10440 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_point_sprite; }
# 10441 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_shader_objects; }
# 10442 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_shading_language_100; }
# 10443 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_shadow; }
# 10444 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_shadow_ambient; }
# 10445 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_border_clamp; }
# 10446 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_compression; }
# 10447 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_cube_map; }
# 10448 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_env_add; }
# 10449 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_env_combine; }
# 10450 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_env_crossbar; }
# 10451 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_env_dot3; }
# 10452 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_float; }
# 10453 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_mirrored_repeat; }
# 10454 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_non_power_of_two; }
# 10455 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_texture_rectangle; }
# 10456 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_transpose_matrix; }
# 10457 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_vertex_blend; }
# 10458 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_vertex_buffer_object; }
# 10459 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_vertex_program; }
# 10460 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_vertex_shader; }
# 10461 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ARB_window_pos; }
# 10462 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATIX_point_sprites; }
# 10463 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATIX_texture_env_combine3; }
# 10464 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATIX_texture_env_route; }
# 10465 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATIX_vertex_shader_output_point_size; }
# 10466 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_draw_buffers; }
# 10467 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_element_array; }
# 10468 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_envmap_bumpmap; }
# 10469 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_fragment_shader; }
# 10470 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_map_object_buffer; }
# 10471 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_pn_triangles; }
# 10472 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_separate_stencil; }
# 10473 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_shader_texture_lod; }
# 10474 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_text_fragment_shader; }
# 10475 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_texture_compression_3dc; }
# 10476 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_texture_env_combine3; }
# 10477 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_texture_float; }
# 10478 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_texture_mirror_once; }
# 10479 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_vertex_array_object; }
# 10480 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_vertex_attrib_array_object; }
# 10481 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_ATI_vertex_streams; }
# 10482 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_422_pixels; }
# 10483 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_Cg_shader; }
# 10484 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_abgr; }
# 10485 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_bgra; }
# 10486 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_bindable_uniform; }
# 10487 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_color; }
# 10488 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_equation_separate; }
# 10489 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_func_separate; }
# 10490 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_logic_op; }
# 10491 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_minmax; }
# 10492 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_blend_subtract; }
# 10493 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_clip_volume_hint; }
# 10494 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_cmyka; }
# 10495 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_color_subtable; }
# 10496 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_compiled_vertex_array; }
# 10497 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_convolution; }
# 10498 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_coordinate_frame; }
# 10499 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_copy_texture; }
# 10500 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_cull_vertex; }
# 10501 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_depth_bounds_test; }
# 10502 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_draw_buffers2; }
# 10503 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_draw_instanced; }
# 10504 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_draw_range_elements; }
# 10505 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_fog_coord; }
# 10506 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_fragment_lighting; }
# 10507 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_framebuffer_blit; }
# 10508 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_framebuffer_multisample; }
# 10509 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_framebuffer_object; }
# 10510 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_framebuffer_sRGB; }
# 10511 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_geometry_shader4; }
# 10512 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_gpu_program_parameters; }
# 10513 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_gpu_shader4; }
# 10514 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_histogram; }
# 10515 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_index_array_formats; }
# 10516 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_index_func; }
# 10517 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_index_material; }
# 10518 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_index_texture; }
# 10519 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_light_texture; }
# 10520 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_misc_attribute; }
# 10521 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_multi_draw_arrays; }
# 10522 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_multisample; }
# 10523 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_packed_depth_stencil; }
# 10524 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_packed_float; }
# 10525 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_packed_pixels; }
# 10526 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_paletted_texture; }
# 10527 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_pixel_buffer_object; }
# 10528 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_pixel_transform; }
# 10529 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_pixel_transform_color_table; }
# 10530 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_point_parameters; }
# 10531 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_polygon_offset; }
# 10532 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_rescale_normal; }
# 10533 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_scene_marker; }
# 10534 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_secondary_color; }
# 10535 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_separate_specular_color; }
# 10536 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_shadow_funcs; }
# 10537 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_shared_texture_palette; }
# 10538 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_stencil_clear_tag; }
# 10539 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_stencil_two_side; }
# 10540 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_stencil_wrap; }
# 10541 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_subtexture; }
# 10542 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture; }
# 10543 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture3D; }
# 10544 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_array; }
# 10545 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_buffer_object; }
# 10546 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_compression_dxt1; }
# 10547 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_compression_latc; }
# 10548 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_compression_rgtc; }
# 10549 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_compression_s3tc; }
# 10550 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_cube_map; }
# 10551 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_edge_clamp; }
# 10552 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_env; }
# 10553 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_env_add; }
# 10554 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_env_combine; }
# 10555 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_env_dot3; }
# 10556 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_filter_anisotropic; }
# 10557 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_integer; }
# 10558 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_lod_bias; }
# 10559 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_mirror_clamp; }
# 10560 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_object; }
# 10561 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_perturb_normal; }
# 10562 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_rectangle; }
# 10563 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_sRGB; }
# 10564 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_texture_shared_exponent; }
# 10565 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_timer_query; }
# 10566 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_vertex_array; }
# 10567 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_vertex_shader; }
# 10568 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_EXT_vertex_weighting; }
# 10569 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_GREMEDY_frame_terminator; }
# 10570 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_GREMEDY_string_marker; }
# 10571 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_HP_convolution_border_modes; }
# 10572 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_HP_image_transform; }
# 10573 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_HP_occlusion_test; }
# 10574 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_HP_texture_lighting; }
# 10575 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_cull_vertex; }
# 10576 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_multimode_draw_arrays; }
# 10577 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_rasterpos_clip; }
# 10578 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_static_data; }
# 10579 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_texture_mirrored_repeat; }
# 10580 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_IBM_vertex_array_lists; }
# 10581 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_INGR_color_clamp; }
# 10582 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_INGR_interlace_read; }
# 10583 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_INTEL_parallel_arrays; }
# 10584 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_INTEL_texture_scissor; }
# 10585 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_KTX_buffer_region; }
# 10586 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_MESAX_texture_stack; }
# 10587 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_MESA_pack_invert; }
# 10588 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_MESA_resize_buffers; }
# 10589 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_MESA_window_pos; }
# 10590 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_MESA_ycbcr_texture; }
# 10591 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_blend_square; }
# 10592 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_copy_depth_to_color; }
# 10593 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_depth_buffer_float; }
# 10594 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_depth_clamp; }
# 10595 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_depth_range_unclamped; }
# 10596 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_evaluators; }
# 10597 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fence; }
# 10598 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_float_buffer; }
# 10599 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fog_distance; }
# 10600 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fragment_program; }
# 10601 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fragment_program2; }
# 10602 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fragment_program4; }
# 10603 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_fragment_program_option; }
# 10604 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_framebuffer_multisample_coverage; }
# 10605 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_geometry_program4; }
# 10606 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_geometry_shader4; }
# 10607 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_gpu_program4; }
# 10608 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_half_float; }
# 10609 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_light_max_exponent; }
# 10610 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_multisample_filter_hint; }
# 10611 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_occlusion_query; }
# 10612 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_packed_depth_stencil; }
# 10613 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_parameter_buffer_object; }
# 10614 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_pixel_data_range; }
# 10615 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_point_sprite; }
# 10616 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_primitive_restart; }
# 10617 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_register_combiners; }
# 10618 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_register_combiners2; }
# 10619 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texgen_emboss; }
# 10620 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texgen_reflection; }
# 10621 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_compression_vtc; }
# 10622 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_env_combine4; }
# 10623 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_expand_normal; }
# 10624 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_rectangle; }
# 10625 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_shader; }
# 10626 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_shader2; }
# 10627 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_texture_shader3; }
# 10628 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_transform_feedback; }
# 10629 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_array_range; }
# 10630 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_array_range2; }
# 10631 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program; }
# 10632 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program1_1; }
# 10633 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program2; }
# 10634 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program2_option; }
# 10635 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program3; }
# 10636 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_NV_vertex_program4; }
# 10637 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OES_byte_coordinates; }
# 10638 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OES_compressed_paletted_texture; }
# 10639 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OES_read_format; }
# 10640 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OES_single_precision; }
# 10641 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OML_interlace; }
# 10642 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OML_resample; }
# 10643 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_OML_subsample; }
# 10644 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_PGI_misc_hints; }
# 10645 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_PGI_vertex_hints; }
# 10646 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_REND_screen_coordinates; }
# 10647 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_S3_s3tc; }
# 10648 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_color_range; }
# 10649 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_detail_texture; }
# 10650 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_fog_function; }
# 10651 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_generate_mipmap; }
# 10652 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_multisample; }
# 10653 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_pixel_texture; }
# 10654 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_sharpen_texture; }
# 10655 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture4D; }
# 10656 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture_border_clamp; }
# 10657 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture_edge_clamp; }
# 10658 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture_filter4; }
# 10659 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture_lod; }
# 10660 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIS_texture_select; }
# 10661 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_async; }
# 10662 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_async_histogram; }
# 10663 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_async_pixel; }
# 10664 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_blend_alpha_minmax; }
# 10665 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_clipmap; }
# 10666 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_depth_texture; }
# 10667 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_flush_raster; }
# 10668 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_fog_offset; }
# 10669 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_fog_texture; }
# 10670 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_fragment_specular_lighting; }
# 10671 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_framezoom; }
# 10672 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_interlace; }
# 10673 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_ir_instrument1; }
# 10674 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_list_priority; }
# 10675 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_pixel_texture; }
# 10676 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_pixel_texture_bits; }
# 10677 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_reference_plane; }
# 10678 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_resample; }
# 10679 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_shadow; }
# 10680 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_shadow_ambient; }
# 10681 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_sprite; }
# 10682 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_tag_sample_buffer; }
# 10683 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_add_env; }
# 10684 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_coordinate_clamp; }
# 10685 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_lod_bias; }
# 10686 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_multi_buffer; }
# 10687 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_range; }
# 10688 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_texture_scale_bias; }
# 10689 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_vertex_preclip; }
# 10690 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_vertex_preclip_hint; }
# 10691 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGIX_ycrcb; }
# 10692 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGI_color_matrix; }
# 10693 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGI_color_table; }
# 10694 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SGI_texture_color_table; }
# 10695 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUNX_constant_data; }
# 10696 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_convolution_border_modes; }
# 10697 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_global_alpha; }
# 10698 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_mesh_array; }
# 10699 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_read_video_pixels; }
# 10700 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_slice_accum; }
# 10701 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_triangle_list; }
# 10702 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_SUN_vertex; }
# 10703 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_WIN_phong_shading; }
# 10704 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_WIN_specular_fog; }
# 10705 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean __GLEW_WIN_swap_hint; }
# 10746 "/usr/include/GL/glew.h" 3
extern "C" GLenum glewInit();
# 10747 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glewIsSupported(const char *);
# 10755 "/usr/include/GL/glew.h" 3
extern "C" { extern GLboolean glewExperimental; }
# 10756 "/usr/include/GL/glew.h" 3
extern "C" GLboolean glewGetExtension(const char *);
# 10757 "/usr/include/GL/glew.h" 3
extern "C" const GLubyte *glewGetErrorString(GLenum);
# 10758 "/usr/include/GL/glew.h" 3
extern "C" const GLubyte *glewGetString(GLenum);
# 200 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutStrokeRoman; }
# 201 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutStrokeMonoRoman; }
# 202 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmap9By15; }
# 203 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmap8By13; }
# 204 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmapTimesRoman10; }
# 205 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmapTimesRoman24; }
# 206 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmapHelvetica10; }
# 207 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmapHelvetica12; }
# 208 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutBitmapHelvetica18; }
# 384 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInit(int *, char **);
# 385 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInitWindowPosition(int, int);
# 386 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInitWindowSize(int, int);
# 387 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInitDisplayMode(unsigned);
# 388 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInitDisplayString(const char *);
# 393 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutMainLoop();
# 398 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutCreateWindow(const char *);
# 399 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutCreateSubWindow(int, int, int, int, int);
# 400 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutDestroyWindow(int);
# 401 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetWindow(int);
# 402 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutGetWindow();
# 403 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetWindowTitle(const char *);
# 404 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetIconTitle(const char *);
# 405 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutReshapeWindow(int, int);
# 406 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPositionWindow(int, int);
# 407 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutShowWindow();
# 408 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutHideWindow();
# 409 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutIconifyWindow();
# 410 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPushWindow();
# 411 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPopWindow();
# 412 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutFullScreen();
# 417 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPostWindowRedisplay(int);
# 418 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPostRedisplay();
# 419 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSwapBuffers();
# 424 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWarpPointer(int, int);
# 425 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetCursor(int);
# 430 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutEstablishOverlay();
# 431 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutRemoveOverlay();
# 432 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutUseLayer(GLenum);
# 433 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPostOverlayRedisplay();
# 434 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPostWindowOverlayRedisplay(int);
# 435 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutShowOverlay();
# 436 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutHideOverlay();
# 441 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutCreateMenu(void (*)(int));
# 442 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutDestroyMenu(int);
# 443 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutGetMenu();
# 444 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetMenu(int);
# 445 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutAddMenuEntry(const char *, int);
# 446 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutAddSubMenu(const char *, int);
# 447 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutChangeToMenuEntry(int, const char *, int);
# 448 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutChangeToSubMenu(int, const char *, int);
# 449 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutRemoveMenuItem(int);
# 450 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutAttachMenu(int);
# 451 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutDetachMenu(int);
# 456 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutTimerFunc(unsigned, void (*)(int), int);
# 457 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutIdleFunc(void (*)(void));
# 462 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutKeyboardFunc(void (*)(unsigned char, int, int));
# 463 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSpecialFunc(void (*)(int, int, int));
# 464 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutReshapeFunc(void (*)(int, int));
# 465 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutVisibilityFunc(void (*)(int));
# 466 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutDisplayFunc(void (*)(void));
# 467 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutMouseFunc(void (*)(int, int, int, int));
# 468 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutMotionFunc(void (*)(int, int));
# 469 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutPassiveMotionFunc(void (*)(int, int));
# 470 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutEntryFunc(void (*)(int));
# 472 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutKeyboardUpFunc(void (*)(unsigned char, int, int));
# 473 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSpecialUpFunc(void (*)(int, int, int));
# 474 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutJoystickFunc(void (*)(unsigned, int, int, int), int);
# 475 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutMenuStateFunc(void (*)(int));
# 476 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutMenuStatusFunc(void (*)(int, int, int));
# 477 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutOverlayDisplayFunc(void (*)(void));
# 478 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWindowStatusFunc(void (*)(int));
# 480 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSpaceballMotionFunc(void (*)(int, int, int));
# 481 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSpaceballRotateFunc(void (*)(int, int, int));
# 482 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSpaceballButtonFunc(void (*)(int, int));
# 483 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutButtonBoxFunc(void (*)(int, int));
# 484 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutDialsFunc(void (*)(int, int));
# 485 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutTabletMotionFunc(void (*)(int, int));
# 486 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutTabletButtonFunc(void (*)(int, int, int, int));
# 491 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutGet(GLenum);
# 492 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutDeviceGet(GLenum);
# 493 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutGetModifiers();
# 494 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutLayerGet(GLenum);
# 499 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutBitmapCharacter(void *, int);
# 500 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutBitmapWidth(void *, int);
# 501 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutStrokeCharacter(void *, int);
# 502 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutStrokeWidth(void *, int);
# 503 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutBitmapLength(void *, const unsigned char *);
# 504 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutStrokeLength(void *, const unsigned char *);
# 509 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireCube(GLdouble);
# 510 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidCube(GLdouble);
# 511 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireSphere(GLdouble, GLint, GLint);
# 512 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidSphere(GLdouble, GLint, GLint);
# 513 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireCone(GLdouble, GLdouble, GLint, GLint);
# 514 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidCone(GLdouble, GLdouble, GLint, GLint);
# 516 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireTorus(GLdouble, GLdouble, GLint, GLint);
# 517 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidTorus(GLdouble, GLdouble, GLint, GLint);
# 518 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireDodecahedron();
# 519 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidDodecahedron();
# 520 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireOctahedron();
# 521 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidOctahedron();
# 522 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireTetrahedron();
# 523 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidTetrahedron();
# 524 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireIcosahedron();
# 525 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidIcosahedron();
# 530 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutWireTeapot(GLdouble);
# 531 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSolidTeapot(GLdouble);
# 536 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutGameModeString(const char *);
# 537 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutEnterGameMode();
# 538 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutLeaveGameMode();
# 539 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutGameModeGet(GLenum);
# 544 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutVideoResizeGet(GLenum);
# 545 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetupVideoResizing();
# 546 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutStopVideoResizing();
# 547 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutVideoResize(int, int, int, int);
# 548 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutVideoPan(int, int, int, int);
# 553 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetColor(int, GLfloat, GLfloat, GLfloat);
# 554 "/usr/include/GL/freeglut_std.h" 3
extern "C" GLfloat glutGetColor(int, int);
# 555 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutCopyColormap(int);
# 560 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutIgnoreKeyRepeat(int);
# 561 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutSetKeyRepeat(int);
# 562 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutForceJoystickFunc();
# 567 "/usr/include/GL/freeglut_std.h" 3
extern "C" int glutExtensionSupported(const char *);
# 568 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutReportErrors();
# 67 "/home/gdiamos/temp/cuda/bin//../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLSetGLDevice(int);
# 68 "/home/gdiamos/temp/cuda/bin//../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLRegisterBufferObject(GLuint);
# 69 "/home/gdiamos/temp/cuda/bin//../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLMapBufferObject(void **, GLuint);
# 70 "/home/gdiamos/temp/cuda/bin//../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLUnmapBufferObject(GLuint);
# 71 "/home/gdiamos/temp/cuda/bin//../include/cuda_gl_interop.h"
extern "C" cudaError_t cudaGLUnregisterBufferObject(GLuint);
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
# 65 "../../sdk/cutil.h"
enum CUTBoolean {
# 67 "../../sdk/cutil.h"
CUTFalse,
# 68 "../../sdk/cutil.h"
CUTTrue
# 69 "../../sdk/cutil.h"
};
# 77 "../../sdk/cutil.h"
extern "C" void cutFree(void *);
# 95 "../../sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 108 "../../sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 123 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 139 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 155 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 170 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 186 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 202 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 216 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 230 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 242 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 254 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 266 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 278 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 294 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 307 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 321 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 337 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 353 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 368 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 380 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 392 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 405 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 417 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 429 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 441 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 462 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 476 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 490 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 504 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 519 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 533 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 545 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 558 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 585 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 599 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 614 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 627 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 636 "../../sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 644 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 652 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 660 "../../sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 669 "../../sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 680 "../../sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
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
# 44 "../../sdk/cutil_inline.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 45 "../../sdk/cutil_inline.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 46 "../../sdk/cutil_inline.h"
aname, int index, char *file, int line)
# 47 "../../sdk/cutil_inline.h"
{
# 48 "../../sdk/cutil_inline.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 49 "../../sdk/cutil_inline.h"
}
# 51 "../../sdk/cutil_inline.h"
inline void __cutilCondition(int val, char *file, int line)
# 52 "../../sdk/cutil_inline.h"
{
# 53 "../../sdk/cutil_inline.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 54 "../../sdk/cutil_inline.h"
exit(1);
# 55 "../../sdk/cutil_inline.h"
}
# 56 "../../sdk/cutil_inline.h"
}
# 58 "../../sdk/cutil_inline.h"
inline void __cutilExit(int argc, char **argv)
# 59 "../../sdk/cutil_inline.h"
{
# 60 "../../sdk/cutil_inline.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 61 "../../sdk/cutil_inline.h"
printf("\nPress ENTER to exit...\n");
# 62 "../../sdk/cutil_inline.h"
fflush(stdout);
# 63 "../../sdk/cutil_inline.h"
fflush(stderr);
# 64 "../../sdk/cutil_inline.h"
getchar();
# 65 "../../sdk/cutil_inline.h"
}
# 66 "../../sdk/cutil_inline.h"
exit(0);
# 67 "../../sdk/cutil_inline.h"
}
# 72 "../../sdk/cutil_inline.h"
inline int cutGetMaxGflopsDeviceId()
# 73 "../../sdk/cutil_inline.h"
{
# 74 "../../sdk/cutil_inline.h"
auto int device_count = 0;
# 75 "../../sdk/cutil_inline.h"
cudaGetDeviceCount(&device_count);
# 77 "../../sdk/cutil_inline.h"
auto cudaDeviceProp device_properties;
# 78 "../../sdk/cutil_inline.h"
auto int max_gflops_device = 0;
# 79 "../../sdk/cutil_inline.h"
auto int max_gflops = 0;
# 81 "../../sdk/cutil_inline.h"
auto int current_device = 0;
# 82 "../../sdk/cutil_inline.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 83 "../../sdk/cutil_inline.h"
max_gflops = device_properties.multiProcessorCount * device_properties.clockRate;
# 84 "../../sdk/cutil_inline.h"
++current_device;
# 86 "../../sdk/cutil_inline.h"
while (current_device < device_count)
# 87 "../../sdk/cutil_inline.h"
{
# 88 "../../sdk/cutil_inline.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 89 "../../sdk/cutil_inline.h"
auto int gflops = (device_properties.multiProcessorCount * device_properties.clockRate);
# 90 "../../sdk/cutil_inline.h"
if (gflops > max_gflops)
# 91 "../../sdk/cutil_inline.h"
{
# 92 "../../sdk/cutil_inline.h"
max_gflops = gflops;
# 93 "../../sdk/cutil_inline.h"
max_gflops_device = current_device;
# 94 "../../sdk/cutil_inline.h"
}
# 95 "../../sdk/cutil_inline.h"
++current_device;
# 96 "../../sdk/cutil_inline.h"
}
# 98 "../../sdk/cutil_inline.h"
return max_gflops_device;
# 99 "../../sdk/cutil_inline.h"
}
# 102 "../../sdk/cutil_inline.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 103 "../../sdk/cutil_inline.h"
{
# 104 "../../sdk/cutil_inline.h"
do {
# 105 "../../sdk/cutil_inline.h"
if ((CUDA_SUCCESS) != err) {
# 106 "../../sdk/cutil_inline.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 108 "../../sdk/cutil_inline.h"
exit(-1);
# 109 "../../sdk/cutil_inline.h"
}
# 110 "../../sdk/cutil_inline.h"
} while (0);
# 111 "../../sdk/cutil_inline.h"
}
# 112 "../../sdk/cutil_inline.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 113 "../../sdk/cutil_inline.h"
{
# 114 "../../sdk/cutil_inline.h"
__cuSafeCallNoSync(err, file, line);
# 115 "../../sdk/cutil_inline.h"
}
# 117 "../../sdk/cutil_inline.h"
inline void __cuCtxSync(const char *file, const int line)
# 118 "../../sdk/cutil_inline.h"
{
# 119 "../../sdk/cutil_inline.h"
do {
# 120 "../../sdk/cutil_inline.h"
auto CUresult err = cuCtxSynchronize();
# 121 "../../sdk/cutil_inline.h"
if ((CUDA_SUCCESS) != err) {
# 122 "../../sdk/cutil_inline.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 124 "../../sdk/cutil_inline.h"
exit(-1);
# 125 "../../sdk/cutil_inline.h"
}
# 126 "../../sdk/cutil_inline.h"
} while (0);
# 127 "../../sdk/cutil_inline.h"
}
# 129 "../../sdk/cutil_inline.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 130 "../../sdk/cutil_inline.h"
{
# 131 "../../sdk/cutil_inline.h"
do {
# 132 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 133 "../../sdk/cutil_inline.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 135 "../../sdk/cutil_inline.h"
exit(-1);
# 136 "../../sdk/cutil_inline.h"
}
# 137 "../../sdk/cutil_inline.h"
} while (0);
# 138 "../../sdk/cutil_inline.h"
}
# 140 "../../sdk/cutil_inline.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 141 "../../sdk/cutil_inline.h"
{
# 142 "../../sdk/cutil_inline.h"
do {
# 143 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 144 "../../sdk/cutil_inline.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 146 "../../sdk/cutil_inline.h"
exit(-1);
# 147 "../../sdk/cutil_inline.h"
}
# 148 "../../sdk/cutil_inline.h"
} while (0);
# 149 "../../sdk/cutil_inline.h"
}
# 151 "../../sdk/cutil_inline.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 152 "../../sdk/cutil_inline.h"
{
# 153 "../../sdk/cutil_inline.h"
do {
# 154 "../../sdk/cutil_inline.h"
auto cudaError err = cudaThreadSynchronize();
# 155 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 156 "../../sdk/cutil_inline.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 158 "../../sdk/cutil_inline.h"
exit(-1);
# 159 "../../sdk/cutil_inline.h"
}
# 160 "../../sdk/cutil_inline.h"
} while (0);
# 161 "../../sdk/cutil_inline.h"
}
# 163 "../../sdk/cutil_inline.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 164 "../../sdk/cutil_inline.h"
{
# 165 "../../sdk/cutil_inline.h"
do {
# 166 "../../sdk/cutil_inline.h"
if ((CUFFT_SUCCESS) != err) {
# 167 "../../sdk/cutil_inline.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 169 "../../sdk/cutil_inline.h"
exit(-1);
# 170 "../../sdk/cutil_inline.h"
}
# 171 "../../sdk/cutil_inline.h"
} while (0);
# 172 "../../sdk/cutil_inline.h"
}
# 174 "../../sdk/cutil_inline.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 175 "../../sdk/cutil_inline.h"
{
# 176 "../../sdk/cutil_inline.h"
if ((CUTTrue) != err) {
# 177 "../../sdk/cutil_inline.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 179 "../../sdk/cutil_inline.h"
exit(-1);
# 180 "../../sdk/cutil_inline.h"
}
# 181 "../../sdk/cutil_inline.h"
}
# 182 "../../sdk/cutil_inline.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 183 "../../sdk/cutil_inline.h"
{
# 184 "../../sdk/cutil_inline.h"
do {
# 185 "../../sdk/cutil_inline.h"
auto cudaError_t err = cudaGetLastError();
# 186 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 187 "../../sdk/cutil_inline.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 189 "../../sdk/cutil_inline.h"
exit(-1);
# 190 "../../sdk/cutil_inline.h"
}
# 191 "../../sdk/cutil_inline.h"
err = cudaThreadSynchronize();
# 192 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 193 "../../sdk/cutil_inline.h"
fprintf(stderr, "cutilCheckMsg cudaThreadSynchronize error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 195 "../../sdk/cutil_inline.h"
exit(-1);
# 196 "../../sdk/cutil_inline.h"
}
# 197 "../../sdk/cutil_inline.h"
} while (0);
# 198 "../../sdk/cutil_inline.h"
}
# 199 "../../sdk/cutil_inline.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 200 "../../sdk/cutil_inline.h"
{
# 201 "../../sdk/cutil_inline.h"
do {
# 202 "../../sdk/cutil_inline.h"
if (!(pointer)) {
# 203 "../../sdk/cutil_inline.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 205 "../../sdk/cutil_inline.h"
exit(-1);
# 206 "../../sdk/cutil_inline.h"
}
# 207 "../../sdk/cutil_inline.h"
} while (0);
# 208 "../../sdk/cutil_inline.h"
}
# 214 "../../sdk/cutil_inline.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 215 "../../sdk/cutil_inline.h"
{
# 216 "../../sdk/cutil_inline.h"
auto int deviceCount;
# 217 "../../sdk/cutil_inline.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "../../sdk/cutil_inline.h", 217);
# 218 "../../sdk/cutil_inline.h"
if (deviceCount == 0) {
# 219 "../../sdk/cutil_inline.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 220 "../../sdk/cutil_inline.h"
exit(-1);
# 221 "../../sdk/cutil_inline.h"
}
# 222 "../../sdk/cutil_inline.h"
auto int dev = 0;
# 223 "../../sdk/cutil_inline.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 224 "../../sdk/cutil_inline.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
# 226 "../../sdk/cutil_inline.h"
auto cudaDeviceProp deviceProp;
# 227 "../../sdk/cutil_inline.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "../../sdk/cutil_inline.h", 227);
# 228 "../../sdk/cutil_inline.h"
if ((deviceProp.major) < 1) {
# 229 "../../sdk/cutil_inline.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 230 "../../sdk/cutil_inline.h"
exit(-1); }
# 232 "../../sdk/cutil_inline.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 233 "../../sdk/cutil_inline.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 234 "../../sdk/cutil_inline.h"
__cudaSafeCall(cudaSetDevice(dev), "../../sdk/cutil_inline.h", 234);
# 235 "../../sdk/cutil_inline.h"
}
# 237 "../../sdk/cutil_inline.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 238 "../../sdk/cutil_inline.h"
{
# 239 "../../sdk/cutil_inline.h"
cuDevice = 0;
# 240 "../../sdk/cutil_inline.h"
auto int deviceCount = 0;
# 241 "../../sdk/cutil_inline.h"
auto CUresult err = cuInit(0);
# 242 "../../sdk/cutil_inline.h"
if ((CUDA_SUCCESS) == err) {
# 243 "../../sdk/cutil_inline.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "../../sdk/cutil_inline.h", 243); }
# 244 "../../sdk/cutil_inline.h"
if (deviceCount == 0) {
# 245 "../../sdk/cutil_inline.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 246 "../../sdk/cutil_inline.h"
exit(-1);
# 247 "../../sdk/cutil_inline.h"
}
# 248 "../../sdk/cutil_inline.h"
auto int dev = 0;
# 249 "../../sdk/cutil_inline.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 250 "../../sdk/cutil_inline.h"
if (dev < 0) { dev = 0; }
# 251 "../../sdk/cutil_inline.h"
if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
# 252 "../../sdk/cutil_inline.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "../../sdk/cutil_inline.h", 252);
# 253 "../../sdk/cutil_inline.h"
auto char name[100];
# 254 "../../sdk/cutil_inline.h"
cuDeviceGetName(name, 100, cuDevice);
# 255 "../../sdk/cutil_inline.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 256 "../../sdk/cutil_inline.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 257 "../../sdk/cutil_inline.h"
}
# 262 "../../sdk/cutil_inline.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 263 "../../sdk/cutil_inline.h"
{
# 264 "../../sdk/cutil_inline.h"
do {
# 265 "../../sdk/cutil_inline.h"
auto cudaError_t err = cudaGetLastError();
# 266 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 267 "../../sdk/cutil_inline.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 269 "../../sdk/cutil_inline.h"
exit(-1);
# 270 "../../sdk/cutil_inline.h"
}
# 271 "../../sdk/cutil_inline.h"
err = cudaThreadSynchronize();
# 272 "../../sdk/cutil_inline.h"
if ((cudaSuccess) != err) {
# 273 "../../sdk/cutil_inline.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 275 "../../sdk/cutil_inline.h"
exit(-1);
# 276 "../../sdk/cutil_inline.h"
}
# 277 "../../sdk/cutil_inline.h"
} while (0);
# 278 "../../sdk/cutil_inline.h"
}
# 282 "../../sdk/cutil_inline.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 283 "../../sdk/cutil_inline.h"
{
# 284 "../../sdk/cutil_inline.h"
do {
# 285 "../../sdk/cutil_inline.h"
auto CUresult err = cuCtxSynchronize();
# 286 "../../sdk/cutil_inline.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 287 "../../sdk/cutil_inline.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 289 "../../sdk/cutil_inline.h"
exit(-1);
# 290 "../../sdk/cutil_inline.h"
}
# 291 "../../sdk/cutil_inline.h"
err = cuCtxSynchronize();
# 292 "../../sdk/cutil_inline.h"
if ((CUDA_SUCCESS) != err) {
# 293 "../../sdk/cutil_inline.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 295 "../../sdk/cutil_inline.h"
exit(-1);
# 296 "../../sdk/cutil_inline.h"
}
# 297 "../../sdk/cutil_inline.h"
} while (0);
# 298 "../../sdk/cutil_inline.h"
}
# 77 "bicubicTexture.cu"
extern "C" { typedef unsigned uint; }
# 78 "bicubicTexture.cu"
typedef unsigned char uchar;
# 49 "../../sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
# 50 "../../sdk/cutil_math.h"
extern "C" { typedef unsigned short ushort; }
# 85 "../../sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
# 86 "../../sdk/cutil_math.h"
{
# 87 "../../sdk/cutil_math.h"
return a + t * (b - a);
# 88 "../../sdk/cutil_math.h"
}
# 91 "../../sdk/cutil_math.h"
inline float clamp(float f, float a, float b)
# 92 "../../sdk/cutil_math.h"
{
# 93 "../../sdk/cutil_math.h"
return fmaxf(a, fminf(f, b));
# 94 "../../sdk/cutil_math.h"
}
# 100 "../../sdk/cutil_math.h"
inline int2 operator-(int2 &a)
# 101 "../../sdk/cutil_math.h"
{
# 102 "../../sdk/cutil_math.h"
return make_int2(-(a.x), -(a.y));
# 103 "../../sdk/cutil_math.h"
}
# 106 "../../sdk/cutil_math.h"
inline int2 operator+(int2 a, int2 b)
# 107 "../../sdk/cutil_math.h"
{
# 108 "../../sdk/cutil_math.h"
return make_int2(a.x + b.x, a.y + b.y);
# 109 "../../sdk/cutil_math.h"
}
# 110 "../../sdk/cutil_math.h"
inline void operator+=(int2 &a, int2 b)
# 111 "../../sdk/cutil_math.h"
{
# 112 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y;
# 113 "../../sdk/cutil_math.h"
}
# 116 "../../sdk/cutil_math.h"
inline int2 operator-(int2 a, int2 b)
# 117 "../../sdk/cutil_math.h"
{
# 118 "../../sdk/cutil_math.h"
return make_int2(a.x - b.x, a.y - b.y);
# 119 "../../sdk/cutil_math.h"
}
# 120 "../../sdk/cutil_math.h"
inline void operator-=(int2 &a, int2 b)
# 121 "../../sdk/cutil_math.h"
{
# 122 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y;
# 123 "../../sdk/cutil_math.h"
}
# 126 "../../sdk/cutil_math.h"
inline int2 operator*(int2 a, int2 b)
# 127 "../../sdk/cutil_math.h"
{
# 128 "../../sdk/cutil_math.h"
return make_int2(a.x * b.x, a.y * b.y);
# 129 "../../sdk/cutil_math.h"
}
# 130 "../../sdk/cutil_math.h"
inline int2 operator*(int2 a, int s)
# 131 "../../sdk/cutil_math.h"
{
# 132 "../../sdk/cutil_math.h"
return make_int2(a.x * s, a.y * s);
# 133 "../../sdk/cutil_math.h"
}
# 134 "../../sdk/cutil_math.h"
inline int2 operator*(int s, int2 a)
# 135 "../../sdk/cutil_math.h"
{
# 136 "../../sdk/cutil_math.h"
return make_int2(a.x * s, a.y * s);
# 137 "../../sdk/cutil_math.h"
}
# 138 "../../sdk/cutil_math.h"
inline void operator*=(int2 &a, int s)
# 139 "../../sdk/cutil_math.h"
{
# 140 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 141 "../../sdk/cutil_math.h"
}
# 147 "../../sdk/cutil_math.h"
inline float2 make_float2(float s)
# 148 "../../sdk/cutil_math.h"
{
# 149 "../../sdk/cutil_math.h"
return make_float2(s, s);
# 150 "../../sdk/cutil_math.h"
}
# 151 "../../sdk/cutil_math.h"
inline float2 make_float2(int2 a)
# 152 "../../sdk/cutil_math.h"
{
# 153 "../../sdk/cutil_math.h"
return make_float2((float)(a.x), (float)(a.y));
# 154 "../../sdk/cutil_math.h"
}
# 157 "../../sdk/cutil_math.h"
inline float2 operator-(float2 &a)
# 158 "../../sdk/cutil_math.h"
{
# 159 "../../sdk/cutil_math.h"
return make_float2(-(a.x), -(a.y));
# 160 "../../sdk/cutil_math.h"
}
# 163 "../../sdk/cutil_math.h"
inline float2 operator+(float2 a, float2 b)
# 164 "../../sdk/cutil_math.h"
{
# 165 "../../sdk/cutil_math.h"
return make_float2(a.x + b.x, a.y + b.y);
# 166 "../../sdk/cutil_math.h"
}
# 167 "../../sdk/cutil_math.h"
inline void operator+=(float2 &a, float2 b)
# 168 "../../sdk/cutil_math.h"
{
# 169 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y;
# 170 "../../sdk/cutil_math.h"
}
# 173 "../../sdk/cutil_math.h"
inline float2 operator-(float2 a, float2 b)
# 174 "../../sdk/cutil_math.h"
{
# 175 "../../sdk/cutil_math.h"
return make_float2(a.x - b.x, a.y - b.y);
# 176 "../../sdk/cutil_math.h"
}
# 177 "../../sdk/cutil_math.h"
inline void operator-=(float2 &a, float2 b)
# 178 "../../sdk/cutil_math.h"
{
# 179 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y;
# 180 "../../sdk/cutil_math.h"
}
# 183 "../../sdk/cutil_math.h"
inline float2 operator*(float2 a, float2 b)
# 184 "../../sdk/cutil_math.h"
{
# 185 "../../sdk/cutil_math.h"
return make_float2(a.x * b.x, a.y * b.y);
# 186 "../../sdk/cutil_math.h"
}
# 187 "../../sdk/cutil_math.h"
inline float2 operator*(float2 a, float s)
# 188 "../../sdk/cutil_math.h"
{
# 189 "../../sdk/cutil_math.h"
return make_float2(a.x * s, a.y * s);
# 190 "../../sdk/cutil_math.h"
}
# 191 "../../sdk/cutil_math.h"
inline float2 operator*(float s, float2 a)
# 192 "../../sdk/cutil_math.h"
{
# 193 "../../sdk/cutil_math.h"
return make_float2(a.x * s, a.y * s);
# 194 "../../sdk/cutil_math.h"
}
# 195 "../../sdk/cutil_math.h"
inline void operator*=(float2 &a, float s)
# 196 "../../sdk/cutil_math.h"
{
# 197 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s;
# 198 "../../sdk/cutil_math.h"
}
# 201 "../../sdk/cutil_math.h"
inline float2 operator/(float2 a, float2 b)
# 202 "../../sdk/cutil_math.h"
{
# 203 "../../sdk/cutil_math.h"
return make_float2(a.x / b.x, a.y / b.y);
# 204 "../../sdk/cutil_math.h"
}
# 205 "../../sdk/cutil_math.h"
inline float2 operator/(float2 a, float s)
# 206 "../../sdk/cutil_math.h"
{
# 207 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 208 "../../sdk/cutil_math.h"
return (a * inv);
# 209 "../../sdk/cutil_math.h"
}
# 210 "../../sdk/cutil_math.h"
inline float2 operator/(float s, float2 a)
# 211 "../../sdk/cutil_math.h"
{
# 212 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 213 "../../sdk/cutil_math.h"
return (a * inv);
# 214 "../../sdk/cutil_math.h"
}
# 215 "../../sdk/cutil_math.h"
inline void operator/=(float2 &a, float s)
# 216 "../../sdk/cutil_math.h"
{
# 217 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 218 "../../sdk/cutil_math.h"
(a *= inv);
# 219 "../../sdk/cutil_math.h"
}
# 222 "../../sdk/cutil_math.h"
inline float2 lerp(float2 a, float2 b, float t)
# 223 "../../sdk/cutil_math.h"
{
# 224 "../../sdk/cutil_math.h"
return (a + (t * (b - a)));
# 225 "../../sdk/cutil_math.h"
}
# 228 "../../sdk/cutil_math.h"
inline float2 clamp(float2 v, float a, float b)
# 229 "../../sdk/cutil_math.h"
{
# 230 "../../sdk/cutil_math.h"
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
# 231 "../../sdk/cutil_math.h"
}
# 233 "../../sdk/cutil_math.h"
inline float2 clamp(float2 v, float2 a, float2 b)
# 234 "../../sdk/cutil_math.h"
{
# 235 "../../sdk/cutil_math.h"
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
# 236 "../../sdk/cutil_math.h"
}
# 239 "../../sdk/cutil_math.h"
inline float dot(float2 a, float2 b)
# 240 "../../sdk/cutil_math.h"
{
# 241 "../../sdk/cutil_math.h"
return a.x * b.x + a.y * b.y;
# 242 "../../sdk/cutil_math.h"
}
# 245 "../../sdk/cutil_math.h"
inline float length(float2 v)
# 246 "../../sdk/cutil_math.h"
{
# 247 "../../sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 248 "../../sdk/cutil_math.h"
}
# 251 "../../sdk/cutil_math.h"
inline float2 normalize(float2 v)
# 252 "../../sdk/cutil_math.h"
{
# 253 "../../sdk/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 254 "../../sdk/cutil_math.h"
return (v * invLen);
# 255 "../../sdk/cutil_math.h"
}
# 258 "../../sdk/cutil_math.h"
inline float2 floor(const float2 v)
# 259 "../../sdk/cutil_math.h"
{
# 260 "../../sdk/cutil_math.h"
return make_float2(floor(v.x), floor(v.y));
# 261 "../../sdk/cutil_math.h"
}
# 264 "../../sdk/cutil_math.h"
inline float2 reflect(float2 i, float2 n)
# 265 "../../sdk/cutil_math.h"
{
# 266 "../../sdk/cutil_math.h"
return (i - (((2.0F) * n) * dot(n, i)));
# 267 "../../sdk/cutil_math.h"
}
# 270 "../../sdk/cutil_math.h"
inline float2 fabs(float2 v)
# 271 "../../sdk/cutil_math.h"
{
# 272 "../../sdk/cutil_math.h"
return make_float2(fabs(v.x), fabs(v.y));
# 273 "../../sdk/cutil_math.h"
}
# 279 "../../sdk/cutil_math.h"
inline float3 make_float3(float s)
# 280 "../../sdk/cutil_math.h"
{
# 281 "../../sdk/cutil_math.h"
return make_float3(s, s, s);
# 282 "../../sdk/cutil_math.h"
}
# 283 "../../sdk/cutil_math.h"
inline float3 make_float3(float2 a)
# 284 "../../sdk/cutil_math.h"
{
# 285 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, (0.0F));
# 286 "../../sdk/cutil_math.h"
}
# 287 "../../sdk/cutil_math.h"
inline float3 make_float3(float2 a, float s)
# 288 "../../sdk/cutil_math.h"
{
# 289 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, s);
# 290 "../../sdk/cutil_math.h"
}
# 291 "../../sdk/cutil_math.h"
inline float3 make_float3(float4 a)
# 292 "../../sdk/cutil_math.h"
{
# 293 "../../sdk/cutil_math.h"
return make_float3(a.x, a.y, a.z);
# 294 "../../sdk/cutil_math.h"
}
# 295 "../../sdk/cutil_math.h"
inline float3 make_float3(int3 a)
# 296 "../../sdk/cutil_math.h"
{
# 297 "../../sdk/cutil_math.h"
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
# 298 "../../sdk/cutil_math.h"
}
# 301 "../../sdk/cutil_math.h"
inline float3 operator-(float3 &a)
# 302 "../../sdk/cutil_math.h"
{
# 303 "../../sdk/cutil_math.h"
return make_float3(-(a.x), -(a.y), -(a.z));
# 304 "../../sdk/cutil_math.h"
}
# 307 "../../sdk/cutil_math.h"
static inline float3 fminf(float3 a, float3 b)
# 308 "../../sdk/cutil_math.h"
{
# 309 "../../sdk/cutil_math.h"
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
# 310 "../../sdk/cutil_math.h"
}
# 313 "../../sdk/cutil_math.h"
static inline float3 fmaxf(float3 a, float3 b)
# 314 "../../sdk/cutil_math.h"
{
# 315 "../../sdk/cutil_math.h"
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
# 316 "../../sdk/cutil_math.h"
}
# 319 "../../sdk/cutil_math.h"
inline float3 operator+(float3 a, float3 b)
# 320 "../../sdk/cutil_math.h"
{
# 321 "../../sdk/cutil_math.h"
return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
# 322 "../../sdk/cutil_math.h"
}
# 323 "../../sdk/cutil_math.h"
inline float3 operator+(float3 a, float b)
# 324 "../../sdk/cutil_math.h"
{
# 325 "../../sdk/cutil_math.h"
return make_float3(a.x + b, a.y + b, a.z + b);
# 326 "../../sdk/cutil_math.h"
}
# 327 "../../sdk/cutil_math.h"
inline void operator+=(float3 &a, float3 b)
# 328 "../../sdk/cutil_math.h"
{
# 329 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 330 "../../sdk/cutil_math.h"
}
# 333 "../../sdk/cutil_math.h"
inline float3 operator-(float3 a, float3 b)
# 334 "../../sdk/cutil_math.h"
{
# 335 "../../sdk/cutil_math.h"
return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
# 336 "../../sdk/cutil_math.h"
}
# 337 "../../sdk/cutil_math.h"
inline float3 operator-(float3 a, float b)
# 338 "../../sdk/cutil_math.h"
{
# 339 "../../sdk/cutil_math.h"
return make_float3(a.x - b, a.y - b, a.z - b);
# 340 "../../sdk/cutil_math.h"
}
# 341 "../../sdk/cutil_math.h"
inline void operator-=(float3 &a, float3 b)
# 342 "../../sdk/cutil_math.h"
{
# 343 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 344 "../../sdk/cutil_math.h"
}
# 347 "../../sdk/cutil_math.h"
inline float3 operator*(float3 a, float3 b)
# 348 "../../sdk/cutil_math.h"
{
# 349 "../../sdk/cutil_math.h"
return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
# 350 "../../sdk/cutil_math.h"
}
# 351 "../../sdk/cutil_math.h"
inline float3 operator*(float3 a, float s)
# 352 "../../sdk/cutil_math.h"
{
# 353 "../../sdk/cutil_math.h"
return make_float3(a.x * s, a.y * s, a.z * s);
# 354 "../../sdk/cutil_math.h"
}
# 355 "../../sdk/cutil_math.h"
inline float3 operator*(float s, float3 a)
# 356 "../../sdk/cutil_math.h"
{
# 357 "../../sdk/cutil_math.h"
return make_float3(a.x * s, a.y * s, a.z * s);
# 358 "../../sdk/cutil_math.h"
}
# 359 "../../sdk/cutil_math.h"
inline void operator*=(float3 &a, float s)
# 360 "../../sdk/cutil_math.h"
{
# 361 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 362 "../../sdk/cutil_math.h"
}
# 365 "../../sdk/cutil_math.h"
inline float3 operator/(float3 a, float3 b)
# 366 "../../sdk/cutil_math.h"
{
# 367 "../../sdk/cutil_math.h"
return make_float3(a.x / b.x, a.y / b.y, a.z / b.z);
# 368 "../../sdk/cutil_math.h"
}
# 369 "../../sdk/cutil_math.h"
inline float3 operator/(float3 a, float s)
# 370 "../../sdk/cutil_math.h"
{
# 371 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 372 "../../sdk/cutil_math.h"
return (a * inv);
# 373 "../../sdk/cutil_math.h"
}
# 374 "../../sdk/cutil_math.h"
inline float3 operator/(float s, float3 a)
# 375 "../../sdk/cutil_math.h"
{
# 376 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 377 "../../sdk/cutil_math.h"
return (a * inv);
# 378 "../../sdk/cutil_math.h"
}
# 379 "../../sdk/cutil_math.h"
inline void operator/=(float3 &a, float s)
# 380 "../../sdk/cutil_math.h"
{
# 381 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 382 "../../sdk/cutil_math.h"
(a *= inv);
# 383 "../../sdk/cutil_math.h"
}
# 386 "../../sdk/cutil_math.h"
inline float3 lerp(float3 a, float3 b, float t)
# 387 "../../sdk/cutil_math.h"
{
# 388 "../../sdk/cutil_math.h"
return (a + (t * (b - a)));
# 389 "../../sdk/cutil_math.h"
}
# 392 "../../sdk/cutil_math.h"
inline float3 clamp(float3 v, float a, float b)
# 393 "../../sdk/cutil_math.h"
{
# 394 "../../sdk/cutil_math.h"
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 395 "../../sdk/cutil_math.h"
}
# 397 "../../sdk/cutil_math.h"
inline float3 clamp(float3 v, float3 a, float3 b)
# 398 "../../sdk/cutil_math.h"
{
# 399 "../../sdk/cutil_math.h"
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 400 "../../sdk/cutil_math.h"
}
# 403 "../../sdk/cutil_math.h"
inline float dot(float3 a, float3 b)
# 404 "../../sdk/cutil_math.h"
{
# 405 "../../sdk/cutil_math.h"
return (a.x * b.x + a.y * b.y) + a.z * b.z;
# 406 "../../sdk/cutil_math.h"
}
# 409 "../../sdk/cutil_math.h"
inline float3 cross(float3 a, float3 b)
# 410 "../../sdk/cutil_math.h"
{
# 411 "../../sdk/cutil_math.h"
return make_float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
# 412 "../../sdk/cutil_math.h"
}
# 415 "../../sdk/cutil_math.h"
inline float length(float3 v)
# 416 "../../sdk/cutil_math.h"
{
# 417 "../../sdk/cutil_math.h"
return sqrtf(dot(v, v));
# 418 "../../sdk/cutil_math.h"
}
# 421 "../../sdk/cutil_math.h"
inline float3 normalize(float3 v)
# 422 "../../sdk/cutil_math.h"
{
# 423 "../../sdk/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 424 "../../sdk/cutil_math.h"
return (v * invLen);
# 425 "../../sdk/cutil_math.h"
}
# 428 "../../sdk/cutil_math.h"
inline float3 floor(const float3 v)
# 429 "../../sdk/cutil_math.h"
{
# 430 "../../sdk/cutil_math.h"
return make_float3(floor(v.x), floor(v.y), floor(v.z));
# 431 "../../sdk/cutil_math.h"
}
# 434 "../../sdk/cutil_math.h"
inline float3 reflect(float3 i, float3 n)
# 435 "../../sdk/cutil_math.h"
{
# 436 "../../sdk/cutil_math.h"
return (i - (((2.0F) * n) * dot(n, i)));
# 437 "../../sdk/cutil_math.h"
}
# 440 "../../sdk/cutil_math.h"
inline float3 fabs(float3 v)
# 441 "../../sdk/cutil_math.h"
{
# 442 "../../sdk/cutil_math.h"
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
# 443 "../../sdk/cutil_math.h"
}
# 449 "../../sdk/cutil_math.h"
inline float4 make_float4(float s)
# 450 "../../sdk/cutil_math.h"
{
# 451 "../../sdk/cutil_math.h"
return make_float4(s, s, s, s);
# 452 "../../sdk/cutil_math.h"
}
# 453 "../../sdk/cutil_math.h"
inline float4 make_float4(float3 a)
# 454 "../../sdk/cutil_math.h"
{
# 455 "../../sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, (0.0F));
# 456 "../../sdk/cutil_math.h"
}
# 457 "../../sdk/cutil_math.h"
inline float4 make_float4(float3 a, float w)
# 458 "../../sdk/cutil_math.h"
{
# 459 "../../sdk/cutil_math.h"
return make_float4(a.x, a.y, a.z, w);
# 460 "../../sdk/cutil_math.h"
}
# 461 "../../sdk/cutil_math.h"
inline float4 make_float4(int4 a)
# 462 "../../sdk/cutil_math.h"
{
# 463 "../../sdk/cutil_math.h"
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
# 464 "../../sdk/cutil_math.h"
}
# 467 "../../sdk/cutil_math.h"
inline float4 operator-(float4 &a)
# 468 "../../sdk/cutil_math.h"
{
# 469 "../../sdk/cutil_math.h"
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
# 470 "../../sdk/cutil_math.h"
}
# 473 "../../sdk/cutil_math.h"
static inline float4 fminf(float4 a, float4 b)
# 474 "../../sdk/cutil_math.h"
{
# 475 "../../sdk/cutil_math.h"
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
# 476 "../../sdk/cutil_math.h"
}
# 479 "../../sdk/cutil_math.h"
static inline float4 fmaxf(float4 a, float4 b)
# 480 "../../sdk/cutil_math.h"
{
# 481 "../../sdk/cutil_math.h"
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
# 482 "../../sdk/cutil_math.h"
}
# 485 "../../sdk/cutil_math.h"
inline float4 operator+(float4 a, float4 b)
# 486 "../../sdk/cutil_math.h"
{
# 487 "../../sdk/cutil_math.h"
return make_float4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
# 488 "../../sdk/cutil_math.h"
}
# 489 "../../sdk/cutil_math.h"
inline void operator+=(float4 &a, float4 b)
# 490 "../../sdk/cutil_math.h"
{
# 491 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z; (a.w) += b.w;
# 492 "../../sdk/cutil_math.h"
}
# 495 "../../sdk/cutil_math.h"
inline float4 operator-(float4 a, float4 b)
# 496 "../../sdk/cutil_math.h"
{
# 497 "../../sdk/cutil_math.h"
return make_float4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
# 498 "../../sdk/cutil_math.h"
}
# 499 "../../sdk/cutil_math.h"
inline void operator-=(float4 &a, float4 b)
# 500 "../../sdk/cutil_math.h"
{
# 501 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z; (a.w) -= b.w;
# 502 "../../sdk/cutil_math.h"
}
# 505 "../../sdk/cutil_math.h"
inline float4 operator*(float4 a, float s)
# 506 "../../sdk/cutil_math.h"
{
# 507 "../../sdk/cutil_math.h"
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
# 508 "../../sdk/cutil_math.h"
}
# 509 "../../sdk/cutil_math.h"
inline float4 operator*(float s, float4 a)
# 510 "../../sdk/cutil_math.h"
{
# 511 "../../sdk/cutil_math.h"
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
# 512 "../../sdk/cutil_math.h"
}
# 513 "../../sdk/cutil_math.h"
inline void operator*=(float4 &a, float s)
# 514 "../../sdk/cutil_math.h"
{
# 515 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
# 516 "../../sdk/cutil_math.h"
}
# 519 "../../sdk/cutil_math.h"
inline float4 operator/(float4 a, float4 b)
# 520 "../../sdk/cutil_math.h"
{
# 521 "../../sdk/cutil_math.h"
return make_float4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
# 522 "../../sdk/cutil_math.h"
}
# 523 "../../sdk/cutil_math.h"
inline float4 operator/(float4 a, float s)
# 524 "../../sdk/cutil_math.h"
{
# 525 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 526 "../../sdk/cutil_math.h"
return (a * inv);
# 527 "../../sdk/cutil_math.h"
}
# 528 "../../sdk/cutil_math.h"
inline float4 operator/(float s, float4 a)
# 529 "../../sdk/cutil_math.h"
{
# 530 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 531 "../../sdk/cutil_math.h"
return (a * inv);
# 532 "../../sdk/cutil_math.h"
}
# 533 "../../sdk/cutil_math.h"
inline void operator/=(float4 &a, float s)
# 534 "../../sdk/cutil_math.h"
{
# 535 "../../sdk/cutil_math.h"
auto float inv = ((1.0F) / s);
# 536 "../../sdk/cutil_math.h"
(a *= inv);
# 537 "../../sdk/cutil_math.h"
}
# 540 "../../sdk/cutil_math.h"
inline float4 lerp(float4 a, float4 b, float t)
# 541 "../../sdk/cutil_math.h"
{
# 542 "../../sdk/cutil_math.h"
return (a + (t * (b - a)));
# 543 "../../sdk/cutil_math.h"
}
# 546 "../../sdk/cutil_math.h"
inline float4 clamp(float4 v, float a, float b)
# 547 "../../sdk/cutil_math.h"
{
# 548 "../../sdk/cutil_math.h"
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
# 549 "../../sdk/cutil_math.h"
}
# 551 "../../sdk/cutil_math.h"
inline float4 clamp(float4 v, float4 a, float4 b)
# 552 "../../sdk/cutil_math.h"
{
# 553 "../../sdk/cutil_math.h"
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
# 554 "../../sdk/cutil_math.h"
}
# 557 "../../sdk/cutil_math.h"
inline float dot(float4 a, float4 b)
# 558 "../../sdk/cutil_math.h"
{
# 559 "../../sdk/cutil_math.h"
return ((a.x * b.x + a.y * b.y) + a.z * b.z) + a.w * b.w;
# 560 "../../sdk/cutil_math.h"
}
# 563 "../../sdk/cutil_math.h"
inline float length(float4 r)
# 564 "../../sdk/cutil_math.h"
{
# 565 "../../sdk/cutil_math.h"
return sqrtf(dot(r, r));
# 566 "../../sdk/cutil_math.h"
}
# 569 "../../sdk/cutil_math.h"
inline float4 normalize(float4 v)
# 570 "../../sdk/cutil_math.h"
{
# 571 "../../sdk/cutil_math.h"
auto float invLen = rsqrtf(dot(v, v));
# 572 "../../sdk/cutil_math.h"
return (v * invLen);
# 573 "../../sdk/cutil_math.h"
}
# 576 "../../sdk/cutil_math.h"
inline float4 floor(const float4 v)
# 577 "../../sdk/cutil_math.h"
{
# 578 "../../sdk/cutil_math.h"
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
# 579 "../../sdk/cutil_math.h"
}
# 582 "../../sdk/cutil_math.h"
inline float4 fabs(float4 v)
# 583 "../../sdk/cutil_math.h"
{
# 584 "../../sdk/cutil_math.h"
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
# 585 "../../sdk/cutil_math.h"
}
# 591 "../../sdk/cutil_math.h"
inline int3 make_int3(int s)
# 592 "../../sdk/cutil_math.h"
{
# 593 "../../sdk/cutil_math.h"
return make_int3(s, s, s);
# 594 "../../sdk/cutil_math.h"
}
# 595 "../../sdk/cutil_math.h"
inline int3 make_int3(float3 a)
# 596 "../../sdk/cutil_math.h"
{
# 597 "../../sdk/cutil_math.h"
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
# 598 "../../sdk/cutil_math.h"
}
# 601 "../../sdk/cutil_math.h"
inline int3 operator-(int3 &a)
# 602 "../../sdk/cutil_math.h"
{
# 603 "../../sdk/cutil_math.h"
return make_int3(-(a.x), -(a.y), -(a.z));
# 604 "../../sdk/cutil_math.h"
}
# 607 "../../sdk/cutil_math.h"
inline int3 min(int3 a, int3 b)
# 608 "../../sdk/cutil_math.h"
{
# 609 "../../sdk/cutil_math.h"
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 610 "../../sdk/cutil_math.h"
}
# 613 "../../sdk/cutil_math.h"
inline int3 max(int3 a, int3 b)
# 614 "../../sdk/cutil_math.h"
{
# 615 "../../sdk/cutil_math.h"
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 616 "../../sdk/cutil_math.h"
}
# 619 "../../sdk/cutil_math.h"
inline int3 operator+(int3 a, int3 b)
# 620 "../../sdk/cutil_math.h"
{
# 621 "../../sdk/cutil_math.h"
return make_int3(a.x + b.x, a.y + b.y, a.z + b.z);
# 622 "../../sdk/cutil_math.h"
}
# 623 "../../sdk/cutil_math.h"
inline void operator+=(int3 &a, int3 b)
# 624 "../../sdk/cutil_math.h"
{
# 625 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 626 "../../sdk/cutil_math.h"
}
# 629 "../../sdk/cutil_math.h"
inline int3 operator-(int3 a, int3 b)
# 630 "../../sdk/cutil_math.h"
{
# 631 "../../sdk/cutil_math.h"
return make_int3(a.x - b.x, a.y - b.y, a.z - b.z);
# 632 "../../sdk/cutil_math.h"
}
# 634 "../../sdk/cutil_math.h"
inline void operator-=(int3 &a, int3 b)
# 635 "../../sdk/cutil_math.h"
{
# 636 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 637 "../../sdk/cutil_math.h"
}
# 640 "../../sdk/cutil_math.h"
inline int3 operator*(int3 a, int3 b)
# 641 "../../sdk/cutil_math.h"
{
# 642 "../../sdk/cutil_math.h"
return make_int3(a.x * b.x, a.y * b.y, a.z * b.z);
# 643 "../../sdk/cutil_math.h"
}
# 644 "../../sdk/cutil_math.h"
inline int3 operator*(int3 a, int s)
# 645 "../../sdk/cutil_math.h"
{
# 646 "../../sdk/cutil_math.h"
return make_int3(a.x * s, a.y * s, a.z * s);
# 647 "../../sdk/cutil_math.h"
}
# 648 "../../sdk/cutil_math.h"
inline int3 operator*(int s, int3 a)
# 649 "../../sdk/cutil_math.h"
{
# 650 "../../sdk/cutil_math.h"
return make_int3(a.x * s, a.y * s, a.z * s);
# 651 "../../sdk/cutil_math.h"
}
# 652 "../../sdk/cutil_math.h"
inline void operator*=(int3 &a, int s)
# 653 "../../sdk/cutil_math.h"
{
# 654 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 655 "../../sdk/cutil_math.h"
}
# 658 "../../sdk/cutil_math.h"
inline int3 operator/(int3 a, int3 b)
# 659 "../../sdk/cutil_math.h"
{
# 660 "../../sdk/cutil_math.h"
return make_int3(a.x / b.x, a.y / b.y, a.z / b.z);
# 661 "../../sdk/cutil_math.h"
}
# 662 "../../sdk/cutil_math.h"
inline int3 operator/(int3 a, int s)
# 663 "../../sdk/cutil_math.h"
{
# 664 "../../sdk/cutil_math.h"
return make_int3(a.x / s, a.y / s, a.z / s);
# 665 "../../sdk/cutil_math.h"
}
# 666 "../../sdk/cutil_math.h"
inline int3 operator/(int s, int3 a)
# 667 "../../sdk/cutil_math.h"
{
# 668 "../../sdk/cutil_math.h"
return make_int3(a.x / s, a.y / s, a.z / s);
# 669 "../../sdk/cutil_math.h"
}
# 670 "../../sdk/cutil_math.h"
inline void operator/=(int3 &a, int s)
# 671 "../../sdk/cutil_math.h"
{
# 672 "../../sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 673 "../../sdk/cutil_math.h"
}
# 676 "../../sdk/cutil_math.h"
inline int clamp(int f, int a, int b)
# 677 "../../sdk/cutil_math.h"
{
# 678 "../../sdk/cutil_math.h"
return max(a, min(f, b));
# 679 "../../sdk/cutil_math.h"
}
# 681 "../../sdk/cutil_math.h"
inline int3 clamp(int3 v, int a, int b)
# 682 "../../sdk/cutil_math.h"
{
# 683 "../../sdk/cutil_math.h"
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 684 "../../sdk/cutil_math.h"
}
# 686 "../../sdk/cutil_math.h"
inline int3 clamp(int3 v, int3 a, int3 b)
# 687 "../../sdk/cutil_math.h"
{
# 688 "../../sdk/cutil_math.h"
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 689 "../../sdk/cutil_math.h"
}
# 696 "../../sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
# 697 "../../sdk/cutil_math.h"
{
# 698 "../../sdk/cutil_math.h"
return make_uint3(s, s, s);
# 699 "../../sdk/cutil_math.h"
}
# 700 "../../sdk/cutil_math.h"
inline uint3 make_uint3(float3 a)
# 701 "../../sdk/cutil_math.h"
{
# 702 "../../sdk/cutil_math.h"
return make_uint3((unsigned)(a.x), (unsigned)(a.y), (unsigned)(a.z));
# 703 "../../sdk/cutil_math.h"
}
# 706 "../../sdk/cutil_math.h"
inline uint3 min(uint3 a, uint3 b)
# 707 "../../sdk/cutil_math.h"
{
# 708 "../../sdk/cutil_math.h"
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
# 709 "../../sdk/cutil_math.h"
}
# 712 "../../sdk/cutil_math.h"
inline uint3 max(uint3 a, uint3 b)
# 713 "../../sdk/cutil_math.h"
{
# 714 "../../sdk/cutil_math.h"
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
# 715 "../../sdk/cutil_math.h"
}
# 718 "../../sdk/cutil_math.h"
inline uint3 operator+(uint3 a, uint3 b)
# 719 "../../sdk/cutil_math.h"
{
# 720 "../../sdk/cutil_math.h"
return make_uint3(a.x + b.x, a.y + b.y, a.z + b.z);
# 721 "../../sdk/cutil_math.h"
}
# 722 "../../sdk/cutil_math.h"
inline void operator+=(uint3 &a, uint3 b)
# 723 "../../sdk/cutil_math.h"
{
# 724 "../../sdk/cutil_math.h"
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
# 725 "../../sdk/cutil_math.h"
}
# 728 "../../sdk/cutil_math.h"
inline uint3 operator-(uint3 a, uint3 b)
# 729 "../../sdk/cutil_math.h"
{
# 730 "../../sdk/cutil_math.h"
return make_uint3(a.x - b.x, a.y - b.y, a.z - b.z);
# 731 "../../sdk/cutil_math.h"
}
# 733 "../../sdk/cutil_math.h"
inline void operator-=(uint3 &a, uint3 b)
# 734 "../../sdk/cutil_math.h"
{
# 735 "../../sdk/cutil_math.h"
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
# 736 "../../sdk/cutil_math.h"
}
# 739 "../../sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint3 b)
# 740 "../../sdk/cutil_math.h"
{
# 741 "../../sdk/cutil_math.h"
return make_uint3(a.x * b.x, a.y * b.y, a.z * b.z);
# 742 "../../sdk/cutil_math.h"
}
# 743 "../../sdk/cutil_math.h"
inline uint3 operator*(uint3 a, uint s)
# 744 "../../sdk/cutil_math.h"
{
# 745 "../../sdk/cutil_math.h"
return make_uint3(a.x * s, a.y * s, a.z * s);
# 746 "../../sdk/cutil_math.h"
}
# 747 "../../sdk/cutil_math.h"
inline uint3 operator*(uint s, uint3 a)
# 748 "../../sdk/cutil_math.h"
{
# 749 "../../sdk/cutil_math.h"
return make_uint3(a.x * s, a.y * s, a.z * s);
# 750 "../../sdk/cutil_math.h"
}
# 751 "../../sdk/cutil_math.h"
inline void operator*=(uint3 &a, uint s)
# 752 "../../sdk/cutil_math.h"
{
# 753 "../../sdk/cutil_math.h"
(a.x) *= s; (a.y) *= s; (a.z) *= s;
# 754 "../../sdk/cutil_math.h"
}
# 757 "../../sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint3 b)
# 758 "../../sdk/cutil_math.h"
{
# 759 "../../sdk/cutil_math.h"
return make_uint3(a.x / b.x, a.y / b.y, a.z / b.z);
# 760 "../../sdk/cutil_math.h"
}
# 761 "../../sdk/cutil_math.h"
inline uint3 operator/(uint3 a, uint s)
# 762 "../../sdk/cutil_math.h"
{
# 763 "../../sdk/cutil_math.h"
return make_uint3(a.x / s, a.y / s, a.z / s);
# 764 "../../sdk/cutil_math.h"
}
# 765 "../../sdk/cutil_math.h"
inline uint3 operator/(uint s, uint3 a)
# 766 "../../sdk/cutil_math.h"
{
# 767 "../../sdk/cutil_math.h"
return make_uint3(a.x / s, a.y / s, a.z / s);
# 768 "../../sdk/cutil_math.h"
}
# 769 "../../sdk/cutil_math.h"
inline void operator/=(uint3 &a, uint s)
# 770 "../../sdk/cutil_math.h"
{
# 771 "../../sdk/cutil_math.h"
(a.x) /= s; (a.y) /= s; (a.z) /= s;
# 772 "../../sdk/cutil_math.h"
}
# 775 "../../sdk/cutil_math.h"
inline uint clamp(uint f, uint a, uint b)
# 776 "../../sdk/cutil_math.h"
{
# 777 "../../sdk/cutil_math.h"
return max(a, min(f, b));
# 778 "../../sdk/cutil_math.h"
}
# 780 "../../sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint a, uint b)
# 781 "../../sdk/cutil_math.h"
{
# 782 "../../sdk/cutil_math.h"
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
# 783 "../../sdk/cutil_math.h"
}
# 785 "../../sdk/cutil_math.h"
inline uint3 clamp(uint3 v, uint3 a, uint3 b)
# 786 "../../sdk/cutil_math.h"
{
# 787 "../../sdk/cutil_math.h"
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
# 788 "../../sdk/cutil_math.h"
}
# 43 "bicubicTexture_kernel.cuh"
static texture< unsigned char, 2, cudaReadModeNormalizedFloat> tex;
# 47 "bicubicTexture_kernel.cuh"
float w0(float a)
# 48 "bicubicTexture_kernel.cuh"
{
# 50 "bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * (a * (a * (-a + (3.0F)) - (3.0F)) + (1.0F));
# 51 "bicubicTexture_kernel.cuh"
}
# 54 "bicubicTexture_kernel.cuh"
float w1(float a)
# 55 "bicubicTexture_kernel.cuh"
{
# 57 "bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * ((a * a) * ((3.0F) * a - (6.0F)) + (4.0F));
# 58 "bicubicTexture_kernel.cuh"
}
# 61 "bicubicTexture_kernel.cuh"
float w2(float a)
# 62 "bicubicTexture_kernel.cuh"
{
# 64 "bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * (a * (a * ((-(3.0F)) * a + (3.0F)) + (3.0F)) + (1.0F));
# 65 "bicubicTexture_kernel.cuh"
}
# 68 "bicubicTexture_kernel.cuh"
float w3(float a)
# 69 "bicubicTexture_kernel.cuh"
{
# 70 "bicubicTexture_kernel.cuh"
return ((1.0F) / (6.0F)) * ((a * a) * a);
# 71 "bicubicTexture_kernel.cuh"
}







# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.h" 1

extern "C" {


extern void __device_stub__Z8d_renderP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);
# 14 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.h"
}
# 80 "bicubicTexture_kernel.cuh" 2


# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.h" 1

extern "C" {





extern void __device_stub__Z15d_renderBicubicP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);





}
# 83 "bicubicTexture_kernel.cuh" 2


# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.h" 1

extern "C" {
# 11 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.h"
extern void __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff(uchar4 *, uint, uint, float, float, float, float, float);


}
# 86 "bicubicTexture_kernel.cuh" 2
# 84 "bicubicTexture.cu"
char *imageFilename = ((char *)("lena_bw.pgm"));
# 86 "bicubicTexture.cu"
uint width = (512); uint height = (512);
# 87 "bicubicTexture.cu"
uint imageWidth; uint imageHeight;
# 88 "bicubicTexture.cu"
dim3 blockSize(16, 16);
# 89 "bicubicTexture.cu"
dim3 gridSize(width / blockSize.x, height / blockSize.y);
# 91 "bicubicTexture.cu"
enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC};
# 92 "bicubicTexture.cu"
Mode mode = MODE_FAST_BICUBIC;
# 93 "bicubicTexture.cu"
bool drawCurves = false;
# 95 "bicubicTexture.cu"
cudaArray *d_imageArray = (0);
# 96 "bicubicTexture.cu"
GLuint pbo = (0);
# 97 "bicubicTexture.cu"
GLuint displayTex = (0);
# 98 "bicubicTexture.cu"
GLuint bufferTex = (0);
# 99 "bicubicTexture.cu"
GLuint fprog;
# 101 "bicubicTexture.cu"
float tx = (9.0F); float ty = (10.0F);
# 102 "bicubicTexture.cu"
float scale = ((1.0F) / (16.0F));
# 103 "bicubicTexture.cu"
float cx; float cy;
# 105 "bicubicTexture.cu"
bool bQATest = false;
# 107 "bicubicTexture.cu"
extern void initPixelBuffer();
# 108 "bicubicTexture.cu"
extern void runBenchmark(int);
# 111 "bicubicTexture.cu"
void render(uchar4 *output)
# 112 "bicubicTexture.cu"
{
# 114 "bicubicTexture.cu"
switch (mode) {
# 115 "bicubicTexture.cu"
case MODE_NEAREST:
# 116 "bicubicTexture.cu"
(tex.filterMode) = cudaFilterModePoint;
# 117 "bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : __device_stub__Z8d_renderP6uchar4jjfffff(output, width, height, tx, ty, scale, cx, cy);
# 118 "bicubicTexture.cu"
break;
# 119 "bicubicTexture.cu"
case MODE_BILINEAR:
# 120 "bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 121 "bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : __device_stub__Z8d_renderP6uchar4jjfffff(output, width, height, tx, ty, scale, cx, cy);
# 122 "bicubicTexture.cu"
break;
# 123 "bicubicTexture.cu"
case MODE_BICUBIC:
# 124 "bicubicTexture.cu"
(tex.filterMode) = cudaFilterModePoint;
# 125 "bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : __device_stub__Z15d_renderBicubicP6uchar4jjfffff(output, width, height, tx, ty, scale, cx, cy);
# 126 "bicubicTexture.cu"
break;
# 127 "bicubicTexture.cu"
case MODE_FAST_BICUBIC:
# 128 "bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 129 "bicubicTexture.cu"
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff(output, width, height, tx, ty, scale, cx, cy);
# 130 "bicubicTexture.cu"
break;
# 131 "bicubicTexture.cu"
}
# 132 "bicubicTexture.cu"
__cutilCheckMsg("kernel failed", "bicubicTexture.cu", 132);
# 133 "bicubicTexture.cu"
}
# 135 "bicubicTexture.cu"
void plotCurve(float (*func)(float))
# 136 "bicubicTexture.cu"
{
# 137 "bicubicTexture.cu"
auto const int steps = 100;
# 138 "bicubicTexture.cu"
glBegin(3);
# 139 "bicubicTexture.cu"
for (int i = 0; i < steps; i++) {
# 140 "bicubicTexture.cu"
auto float x = (i / ((float)(steps - 1)));
# 141 "bicubicTexture.cu"
glVertex2f(x, func(x));
# 142 "bicubicTexture.cu"
}
# 143 "bicubicTexture.cu"
glEnd();
# 144 "bicubicTexture.cu"
}
# 147 "bicubicTexture.cu"
void display()
# 148 "bicubicTexture.cu"
{
# 150 "bicubicTexture.cu"
auto uchar4 *d_output;
# 151 "bicubicTexture.cu"
__cudaSafeCall(cudaGLMapBufferObject((void **)(&d_output), pbo), "bicubicTexture.cu", 151);
# 152 "bicubicTexture.cu"
render(d_output);
# 153 "bicubicTexture.cu"
__cudaSafeCall(cudaGLUnmapBufferObject(pbo), "bicubicTexture.cu", 153);
# 156 "bicubicTexture.cu"
glClear(16384);
# 166 "bicubicTexture.cu"
__glewBindBufferARB(35052, pbo);
# 167 "bicubicTexture.cu"
glBindTexture(34037, displayTex);
# 168 "bicubicTexture.cu"
glPixelStorei(3317, 1);
# 169 "bicubicTexture.cu"
glTexSubImage2D(34037, 0, 0, 0, width, height, 32993, 5121, 0);
# 170 "bicubicTexture.cu"
glEnable(34037);
# 174 "bicubicTexture.cu"
glDisable(2929);
# 175 "bicubicTexture.cu"
glBegin(7);
# 176 "bicubicTexture.cu"
glTexCoord2f(0, height); glVertex2f(0, 0);
# 177 "bicubicTexture.cu"
glTexCoord2f(width, height); glVertex2f(1, 0);
# 178 "bicubicTexture.cu"
glTexCoord2f(width, 0); glVertex2f(1, 1);
# 179 "bicubicTexture.cu"
glTexCoord2f(0, 0); glVertex2f(0, 1);
# 180 "bicubicTexture.cu"
glEnd();
# 181 "bicubicTexture.cu"
glDisable(34037);
# 182 "bicubicTexture.cu"
glDisable(34820);
# 184 "bicubicTexture.cu"
__glewBindBufferARB(35052, 0);
# 186 "bicubicTexture.cu"
if (drawCurves) {
# 188 "bicubicTexture.cu"
glPushMatrix();
# 189 "bicubicTexture.cu"
glScalef((0.25), (0.25), (1.0));
# 191 "bicubicTexture.cu"
glTranslatef((0.0), (2.0), (0.0));
# 192 "bicubicTexture.cu"
glColor3f((1.0), (0.0), (0.0));
# 193 "bicubicTexture.cu"
plotCurve(w3);
# 195 "bicubicTexture.cu"
glTranslatef((1.0), (0.0), (0.0));
# 196 "bicubicTexture.cu"
glColor3f((0.0), (1.0), (0.0));
# 197 "bicubicTexture.cu"
plotCurve(w2);
# 199 "bicubicTexture.cu"
glTranslatef((1.0), (0.0), (0.0));
# 200 "bicubicTexture.cu"
glColor3f((0.0), (0.0), (1.0));
# 201 "bicubicTexture.cu"
plotCurve(w1);
# 203 "bicubicTexture.cu"
glTranslatef((1.0), (0.0), (0.0));
# 204 "bicubicTexture.cu"
glColor3f((1.0), (0.0), (1.0));
# 205 "bicubicTexture.cu"
plotCurve(w0);
# 207 "bicubicTexture.cu"
glPopMatrix();
# 208 "bicubicTexture.cu"
glColor3f((1.0), (1.0), (1.0));
# 209 "bicubicTexture.cu"
}
# 211 "bicubicTexture.cu"
glutSwapBuffers();
# 212 "bicubicTexture.cu"
glutReportErrors();
# 213 "bicubicTexture.cu"
}
# 216 "bicubicTexture.cu"
void idle()
# 217 "bicubicTexture.cu"
{
# 218 "bicubicTexture.cu"
glutPostRedisplay();
# 219 "bicubicTexture.cu"
}
# 221 "bicubicTexture.cu"
void keyboard(unsigned char key, int, int)
# 222 "bicubicTexture.cu"
{
# 223 "bicubicTexture.cu"
switch (key) {
# 224 "bicubicTexture.cu"
case 27:
# 225 "bicubicTexture.cu"
exit(0);
# 226 "bicubicTexture.cu"
break;
# 227 "bicubicTexture.cu"
case '1':
# 228 "bicubicTexture.cu"
mode = MODE_NEAREST;
# 229 "bicubicTexture.cu"
break;
# 230 "bicubicTexture.cu"
case '2':
# 231 "bicubicTexture.cu"
mode = MODE_BILINEAR;
# 232 "bicubicTexture.cu"
break;
# 233 "bicubicTexture.cu"
case '3':
# 234 "bicubicTexture.cu"
mode = MODE_BICUBIC;
# 235 "bicubicTexture.cu"
break;
# 236 "bicubicTexture.cu"
case '4':
# 237 "bicubicTexture.cu"
mode = MODE_FAST_BICUBIC;
# 238 "bicubicTexture.cu"
break;
# 240 "bicubicTexture.cu"
case '=':
# 241 "bicubicTexture.cu"
case '+':
# 242 "bicubicTexture.cu"
scale *= (0.5F);
# 243 "bicubicTexture.cu"
break;
# 244 "bicubicTexture.cu"
case '-':
# 245 "bicubicTexture.cu"
scale *= (2.0F);
# 246 "bicubicTexture.cu"
break;
# 247 "bicubicTexture.cu"
case 'r':
# 248 "bicubicTexture.cu"
scale = (1.0F);
# 249 "bicubicTexture.cu"
tx = (ty = (0.0F));
# 250 "bicubicTexture.cu"
break;
# 251 "bicubicTexture.cu"
case 'd':
# 252 "bicubicTexture.cu"
printf("%f, %f, %f\n", tx, ty, scale);
# 253 "bicubicTexture.cu"
case 'b':
# 254 "bicubicTexture.cu"
runBenchmark(1);
# 255 "bicubicTexture.cu"
break;
# 256 "bicubicTexture.cu"
case 'c':
# 257 "bicubicTexture.cu"
drawCurves ^= 1;
# 258 "bicubicTexture.cu"
break;
# 259 "bicubicTexture.cu"
default:
# 260 "bicubicTexture.cu"
break;
# 261 "bicubicTexture.cu"
}
# 263 "bicubicTexture.cu"
glutPostRedisplay();
# 264 "bicubicTexture.cu"
}
# 266 "bicubicTexture.cu"
int ox; int oy;
# 267 "bicubicTexture.cu"
int buttonState = 0;
# 269 "bicubicTexture.cu"
void mouse(int button, int state, int x, int y)
# 270 "bicubicTexture.cu"
{
# 271 "bicubicTexture.cu"
if (state == 0) {
# 272 "bicubicTexture.cu"
buttonState |= 1 << button; } else {
# 273 "bicubicTexture.cu"
if (state == 1) {
# 274 "bicubicTexture.cu"
buttonState = 0; } }
# 276 "bicubicTexture.cu"
ox = x; oy = y;
# 277 "bicubicTexture.cu"
glutPostRedisplay();
# 278 "bicubicTexture.cu"
}
# 280 "bicubicTexture.cu"
void motion(int x, int y)
# 281 "bicubicTexture.cu"
{
# 282 "bicubicTexture.cu"
auto float dx; auto float dy;
# 283 "bicubicTexture.cu"
dx = x - ox;
# 284 "bicubicTexture.cu"
dy = y - oy;
# 286 "bicubicTexture.cu"
if (buttonState & 1) {
# 288 "bicubicTexture.cu"
tx -= dx * scale;
# 289 "bicubicTexture.cu"
ty -= dy * scale;
# 290 "bicubicTexture.cu"
} else {
# 291 "bicubicTexture.cu"
if (buttonState & 2) {
# 293 "bicubicTexture.cu"
scale -= dy / (1000.0);
# 294 "bicubicTexture.cu"
} }
# 296 "bicubicTexture.cu"
ox = x; oy = y;
# 297 "bicubicTexture.cu"
glutPostRedisplay();
# 298 "bicubicTexture.cu"
}
# 300 "bicubicTexture.cu"
void reshape(int x, int y)
# 301 "bicubicTexture.cu"
{
# 302 "bicubicTexture.cu"
width = x; height = y;
# 304 "bicubicTexture.cu"
initPixelBuffer();
# 306 "bicubicTexture.cu"
glViewport(0, 0, x, y);
# 308 "bicubicTexture.cu"
glMatrixMode(5888);
# 309 "bicubicTexture.cu"
glLoadIdentity();
# 311 "bicubicTexture.cu"
glMatrixMode(5889);
# 312 "bicubicTexture.cu"
glLoadIdentity();
# 313 "bicubicTexture.cu"
glOrtho((0.0), (1.0), (0.0), (1.0), (0.0), (1.0));
# 314 "bicubicTexture.cu"
}
# 316 "bicubicTexture.cu"
void cleanup()
# 317 "bicubicTexture.cu"
{
# 318 "bicubicTexture.cu"
__cudaSafeCall(cudaFreeArray(d_imageArray), "bicubicTexture.cu", 318);
# 319 "bicubicTexture.cu"
__cudaSafeCall(cudaGLUnregisterBufferObject(pbo), "bicubicTexture.cu", 319);
# 320 "bicubicTexture.cu"
__glewDeleteBuffersARB(1, &pbo);
# 324 "bicubicTexture.cu"
glDeleteTextures(1, &displayTex);
# 326 "bicubicTexture.cu"
__glewDeleteProgramsARB(1, &fprog);
# 327 "bicubicTexture.cu"
printf("Test PASSED!\n");
# 328 "bicubicTexture.cu"
}
# 330 "bicubicTexture.cu"
int iDivUp(int a, int b) {
# 331 "bicubicTexture.cu"
return ((a % b) != 0) ? (a / b + 1) : (a / b);
# 332 "bicubicTexture.cu"
}
# 334 "bicubicTexture.cu"
void initPixelBuffer()
# 335 "bicubicTexture.cu"
{
# 336 "bicubicTexture.cu"
if (pbo) {
# 338 "bicubicTexture.cu"
__cudaSafeCall(cudaGLUnregisterBufferObject(pbo), "bicubicTexture.cu", 338);
# 339 "bicubicTexture.cu"
__glewDeleteBuffersARB(1, &pbo);
# 340 "bicubicTexture.cu"
}
# 343 "bicubicTexture.cu"
__glewGenBuffersARB(1, &pbo);
# 344 "bicubicTexture.cu"
__glewBindBufferARB(35052, pbo);
# 345 "bicubicTexture.cu"
__glewBufferDataARB(35052, (width * height) * sizeof(uchar4), 0, 35040);
# 346 "bicubicTexture.cu"
__glewBindBufferARB(35052, 0);
# 348 "bicubicTexture.cu"
__cudaSafeCall(cudaGLRegisterBufferObject(pbo), "bicubicTexture.cu", 348);
# 361 "bicubicTexture.cu"
if (displayTex) {
# 362 "bicubicTexture.cu"
glDeleteTextures(1, &displayTex);
# 363 "bicubicTexture.cu"
}
# 364 "bicubicTexture.cu"
glGenTextures(1, &displayTex);
# 365 "bicubicTexture.cu"
glBindTexture(34037, displayTex);
# 366 "bicubicTexture.cu"
glTexImage2D(34037, 0, 32856, width, height, 0, 6408, 5121, __null);
# 367 "bicubicTexture.cu"
glTexParameteri(34037, 10241, 9728);
# 368 "bicubicTexture.cu"
glTexParameteri(34037, 10240, 9728);
# 369 "bicubicTexture.cu"
glBindTexture(34037, 0);
# 373 "bicubicTexture.cu"
gridSize = dim3(iDivUp(width, blockSize.x), iDivUp(height, blockSize.y));
# 374 "bicubicTexture.cu"
}
# 376 "bicubicTexture.cu"
void mainMenu(int i)
# 377 "bicubicTexture.cu"
{
# 378 "bicubicTexture.cu"
keyboard(i, 0, 0);
# 379 "bicubicTexture.cu"
}
# 381 "bicubicTexture.cu"
void initMenus()
# 382 "bicubicTexture.cu"
{
# 383 "bicubicTexture.cu"
glutCreateMenu(mainMenu);
# 384 "bicubicTexture.cu"
glutAddMenuEntry("Nearest filtering [1]", '1');
# 385 "bicubicTexture.cu"
glutAddMenuEntry("Bilinear filtering [2]", '2');
# 386 "bicubicTexture.cu"
glutAddMenuEntry("Bicubic filtering [3]", '3');
# 387 "bicubicTexture.cu"
glutAddMenuEntry("Fast Bicubic filtering [4]", '4');
# 388 "bicubicTexture.cu"
glutAddMenuEntry("Zoom in [=]", '=');
# 389 "bicubicTexture.cu"
glutAddMenuEntry("Zoom out [-]", '-');
# 390 "bicubicTexture.cu"
glutAddMenuEntry("Benchmark [b]", 'b');
# 391 "bicubicTexture.cu"
glutAddMenuEntry("Quit [esc]", 27);
# 392 "bicubicTexture.cu"
glutAttachMenu(2);
# 393 "bicubicTexture.cu"
}
# 395 "bicubicTexture.cu"
void runBenchmark(int iterations)
# 396 "bicubicTexture.cu"
{
# 397 "bicubicTexture.cu"
auto unsigned timer;
# 398 "bicubicTexture.cu"
__cutilCheckError(cutCreateTimer(&timer), "bicubicTexture.cu", 398);
# 400 "bicubicTexture.cu"
auto uchar4 *d_output;
# 401 "bicubicTexture.cu"
__cudaSafeCall(cudaGLMapBufferObject((void **)(&d_output), pbo), "bicubicTexture.cu", 401);
# 403 "bicubicTexture.cu"
__cutilCheckError(cutStartTimer(timer), "bicubicTexture.cu", 403);
# 404 "bicubicTexture.cu"
for (int i = 0; i < iterations; ++i)
# 405 "bicubicTexture.cu"
{
# 406 "bicubicTexture.cu"
render(d_output);
# 407 "bicubicTexture.cu"
}
# 409 "bicubicTexture.cu"
cudaThreadSynchronize();
# 410 "bicubicTexture.cu"
__cutilCheckError(cutStopTimer(timer), "bicubicTexture.cu", 410);
# 411 "bicubicTexture.cu"
auto float time = (cutGetTimerValue(timer) / (float)iterations);
# 413 "bicubicTexture.cu"
__cudaSafeCall(cudaGLUnmapBufferObject(pbo), "bicubicTexture.cu", 413);
# 415 "bicubicTexture.cu"
printf("time: %0.3f ms, %f Mpixels/sec\n", time, ((width * height) / (time * (0.001000000047F))) / (1000000.0));
# 416 "bicubicTexture.cu"
}
# 419 "bicubicTexture.cu"
static const char *shaderCode = ("!!NVfp4.0\nINT PARAM width = program.local[0];\nINT TEMP index;\nFLR.S index, fragment.texcoord;\nMAD.S index.x, index.y, width," " index.x;\nTXF result.color, index.x, texture[0], BUFFER;\nEND");
# 428 "bicubicTexture.cu"
GLuint compileASMShader(GLenum program_type, const char *code)
# 429 "bicubicTexture.cu"
{
# 430 "bicubicTexture.cu"
auto GLuint program_id;
# 431 "bicubicTexture.cu"
__glewGenProgramsARB(1, &program_id);
# 432 "bicubicTexture.cu"
__glewBindProgramARB(program_type, program_id);
# 433 "bicubicTexture.cu"
__glewProgramStringARB(program_type, 34933, (GLsizei)strlen(code), (GLubyte *)code);
# 435 "bicubicTexture.cu"
auto GLint error_pos;
# 436 "bicubicTexture.cu"
glGetIntegerv(34379, &error_pos);
# 437 "bicubicTexture.cu"
if (error_pos != (-1)) {
# 438 "bicubicTexture.cu"
auto const GLubyte *error_string;
# 439 "bicubicTexture.cu"
error_string = glGetString(34932);
# 440 "bicubicTexture.cu"
fprintf(stderr, "Program error at position: %d\n%s\n", (int)error_pos, error_string);
# 441 "bicubicTexture.cu"
return 0;
# 442 "bicubicTexture.cu"
}
# 443 "bicubicTexture.cu"
return program_id;
# 444 "bicubicTexture.cu"
}
# 450 "bicubicTexture.cu"
int main(int argc, char **argv)
# 451 "bicubicTexture.cu"
{
# 452 "bicubicTexture.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 453 "bicubicTexture.cu"
cutilDeviceInit(argc, argv); } else {
# 455 "bicubicTexture.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 458 "bicubicTexture.cu"
auto char *filename;
# 459 "bicubicTexture.cu"
auto bool benchmark = false;
# 461 "bicubicTexture.cu"
if (argc > 1) {
# 462 "bicubicTexture.cu"
if (cutGetCmdLineArgumentstr(argc, (const char **)argv, "file", &filename)) {
# 463 "bicubicTexture.cu"
imageFilename = filename;
# 464 "bicubicTexture.cu"
}
# 465 "bicubicTexture.cu"
benchmark = (cutCheckCmdLineFlag(argc, (const char **)argv, "benchmark")) != 0;
# 466 "bicubicTexture.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt")) {
# 467 "bicubicTexture.cu"
benchmark = true;
# 468 "bicubicTexture.cu"
}
# 469 "bicubicTexture.cu"
}
# 471 "bicubicTexture.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "noqatest")) {
# 472 "bicubicTexture.cu"
benchmark = true;
# 473 "bicubicTexture.cu"
}
# 476 "bicubicTexture.cu"
auto uchar *h_data = (__null);
# 477 "bicubicTexture.cu"
auto char *imagePath = cutFindFilePath(imageFilename, argv[0]);
# 478 "bicubicTexture.cu"
if (imagePath == (0)) {
# 479 "bicubicTexture.cu"
exit(1); }
# 480 "bicubicTexture.cu"
__cutilCheckError(cutLoadPGMub(imagePath, &h_data, &imageWidth, &imageHeight), "bicubicTexture.cu", 480);
# 482 "bicubicTexture.cu"
printf("Loaded \'%s\', %d x %d pixels\n", imageFilename, imageWidth, imageHeight);
# 484 "bicubicTexture.cu"
cx = imageWidth * (0.5F);
# 485 "bicubicTexture.cu"
cy = imageHeight * (0.5F);
# 488 "bicubicTexture.cu"
auto cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 489 "bicubicTexture.cu"
__cudaSafeCall(cudaMallocArray(&d_imageArray, &channelDesc, imageWidth, imageHeight), "bicubicTexture.cu", 489);
# 490 "bicubicTexture.cu"
auto uint size = ((imageWidth * imageHeight) * sizeof(uchar));
# 491 "bicubicTexture.cu"
__cudaSafeCall(cudaMemcpyToArray(d_imageArray, 0, 0, h_data, size, cudaMemcpyHostToDevice), "bicubicTexture.cu", 491);
# 492 "bicubicTexture.cu"
cutFree(h_data);
# 495 "bicubicTexture.cu"
((tex.addressMode)[0]) = cudaAddressModeClamp;
# 496 "bicubicTexture.cu"
((tex.addressMode)[1]) = cudaAddressModeClamp;
# 497 "bicubicTexture.cu"
(tex.filterMode) = cudaFilterModeLinear;
# 498 "bicubicTexture.cu"
(tex.normalized) = (false);
# 501 "bicubicTexture.cu"
__cudaSafeCall(cudaBindTextureToArray(tex, d_imageArray, channelDesc), "bicubicTexture.cu", 501);
# 503 "bicubicTexture.cu"
printf("Press \'=\' and \'-\' to zoom\nPress number keys to change filtering mode:\n1 - nearest filtering\n2 - bilinear filtering\n3 - b" "icubic filtering\n4 - fast bicubic filtering\n");
# 514 "bicubicTexture.cu"
glutInit(&argc, argv);
# 515 "bicubicTexture.cu"
glutInitDisplayMode(0 | 2);
# 516 "bicubicTexture.cu"
glutInitWindowSize(width, height);
# 517 "bicubicTexture.cu"
glutCreateWindow("CUDA bicubic texture filtering");
# 518 "bicubicTexture.cu"
glutDisplayFunc(display);
# 519 "bicubicTexture.cu"
glutKeyboardFunc(keyboard);
# 520 "bicubicTexture.cu"
glutMouseFunc(mouse);
# 521 "bicubicTexture.cu"
glutMotionFunc(motion);
# 522 "bicubicTexture.cu"
glutReshapeFunc(reshape);
# 523 "bicubicTexture.cu"
glutIdleFunc(idle);
# 525 "bicubicTexture.cu"
initMenus();
# 527 "bicubicTexture.cu"
atexit(cleanup);
# 529 "bicubicTexture.cu"
glewInit();
# 530 "bicubicTexture.cu"
if (!(glewIsSupported("GL_VERSION_2_0 GL_ARB_pixel_buffer_object GL_EXT_texture_buffer_object GL_NV_gpu_program4 ")))
# 534 "bicubicTexture.cu"
{
# 535 "bicubicTexture.cu"
fprintf(stderr, "Required OpenGL extensions missing.");
# 536 "bicubicTexture.cu"
exit(-1);
# 537 "bicubicTexture.cu"
}
# 538 "bicubicTexture.cu"
initPixelBuffer();
# 539 "bicubicTexture.cu"
fprog = compileASMShader(34820, shaderCode);
# 540 "bicubicTexture.cu"
if (!(fprog)) { exit(0); }
# 542 "bicubicTexture.cu"
if (benchmark) {
# 543 "bicubicTexture.cu"
runBenchmark(1);
# 545 "bicubicTexture.cu"
exit(0);
# 546 "bicubicTexture.cu"
}
# 548 "bicubicTexture.cu"
glutMainLoop();
# 550 "bicubicTexture.cu"
cudaThreadExit();
# 551 "bicubicTexture.cu"
return 0;
# 552 "bicubicTexture.cu"
}

# 1 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_000018b5_00000000-3_bicubicTexture.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000018b5_00000000-3_bicubicTexture.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$compute_10$[] = {
0x6f69737265762e09ull,0x2e090a332e31206eull,0x7320746567726174ull,0x616d202c30315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x6964672f656d6f68ull,0x6d65742f736f6d61ull,0x6f2f616475632f70ull,0x696c2f34366e6570ull,
0x2f090a65622f2f62ull,0x6e65706f766e202full,0x746c697562206363ull,0x38303032206e6f20ull,
0x0a0a33302d32312dull,0x752e206765722e09ull,0x313c617225203233ull,0x65722e090a3b3e37ull,
0x25203436752e2067ull,0x3b3e37313c616472ull,0x2e206765722e090aull,0x3c61662520323366ull,
0x722e090a3b3e3731ull,0x203436662e206765ull,0x3e37313c61646625ull,0x206765722e090a3bull,
0x767225203233752eull,0x722e090a3b3e353cull,0x203436752e206765ull,0x3b3e353c76647225ull,
0x2e206765722e090aull,0x3c76662520323366ull,0x65722e090a3b3e35ull,0x25203436662e2067ull,
0x0a3b3e353c766466ull,0x2d2d2d2f2f090a0aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x6d6f43202f2f090aull,0x2f20676e696c6970ull,0x78706d742f706d74ull,
0x31303030305f7466ull,0x303030305f356238ull,0x625f372d30303030ull,0x6554636962756369ull,
0x70632e6572757478ull,0x742f2820692e3370ull,0x23494263632f706dull,0x296e6a3746586d2eull,
0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,
0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,
0x6974704f202f2f09ull,0x2f2f090a3a736e6full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x202f2f090a2d2d2dull,0x3a74656772615420ull,0x415349202c787470ull,
0x202c30315f6d733aull,0x6c3a6e6169646e45ull,0x50202c656c747469ull,0x53207265746e696full,
0x090a34363a657a69ull,0x09334f2d20202f2full,0x7a696d6974704f28ull,0x656c206e6f697461ull,
0x2f2f090a296c6576ull,0x44280930672d2020ull,0x76656c2067756265ull,0x202f2f090a296c65ull,
0x65522809326d2d20ull,0x7664612074726f70ull,0x29736569726f7369ull,0x2d2d2d2d2f2f090aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x09656c69662e090aull,
0x6d6d6f633c220931ull,0x656e696c2d646e61ull,0x6c69662e090a223eull,0x6d742f2209320965ull,
0x746678706d742f70ull,0x623831303030305full,0x3030303030305f35ull,0x6369625f362d3030ull,
0x7478655463696275ull,0x616475632e657275ull,0x227570672e326566ull,0x09656c69662e090aull,
0x2f7273752f220933ull,0x2f6363672f62696cull,0x6c2d34365f363878ull,0x756e672d78756e69ull,
0x692f332e332e342full,0x732f6564756c636eull,0x22682e6665646474ull,0x09656c69662e090aull,
0x656d6f682f220934ull,0x736f6d616964672full,0x75632f706d65742full,0x2f2f6e69622f6164ull,
0x756c636e692f2e2eull,0x642f7472632f6564ull,0x75725f6563697665ull,0x22682e656d69746eull,
0x09656c69662e090aull,0x656d6f682f220935ull,0x736f6d616964672full,0x75632f706d65742full,
0x2f2f6e69622f6164ull,0x756c636e692f2e2eull,0x5f74736f682f6564ull,0x2e73656e69666564ull,
0x6c69662e090a2268ull,0x6f682f2209360965ull,0x6d616964672f656dull,0x2f706d65742f736full,
0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x6975622f6564756cull,0x7079745f6e69746cull,
0x2e090a22682e7365ull,0x22093709656c6966ull,0x64672f656d6f682full,0x65742f736f6d6169ull,
0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x745f656369766564ull,
0x0a22682e73657079ull,0x3809656c69662e09ull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,
0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x7265766972642f65ull,
0x682e73657079745full,0x656c69662e090a22ull,0x6d6f682f22093909ull,0x6f6d616964672f65ull,
0x632f706d65742f73ull,0x2f6e69622f616475ull,0x6c636e692f2e2e2full,0x747865742f656475ull,
0x657079745f657275ull,0x662e090a22682e73ull,0x2209303109656c69ull,0x64672f656d6f682full,
0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,
0x745f726f74636576ull,0x0a22682e73657079ull,0x3109656c69662e09ull,0x656d6f682f220931ull,
0x736f6d616964672full,0x75632f706d65742full,0x2f2f6e69622f6164ull,0x756c636e692f2e2eull,
0x63697665642f6564ull,0x68636e75616c5f65ull,0x74656d617261705full,0x090a22682e737265ull,
0x323109656c69662eull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,
0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x74732f7472632f65ull,0x6c635f656761726full,
0x090a22682e737361ull,0x333109656c69662eull,0x692f7273752f2209ull,0x622f6564756c636eull,
0x657079742f737469ull,0x662e090a22682e73ull,0x2209343109656c69ull,0x636e692f7273752full,
0x6d69742f6564756cull,0x662e090a22682e65ull,0x2209353109656c69ull,0x5463696275636962ull,
0x6b5f657275747865ull,0x75632e6c656e7265ull,0x6c69662e090a2268ull,0x682f220936310965ull,
0x616964672f656d6full,0x706d65742f736f6dull,0x69622f616475632full,0x6e692f2e2e2f2f6eull,
0x6f632f6564756c63ull,0x6e75665f6e6f6d6dull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209373109ull,0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,
0x636e692f2e2e2f2full,0x7472632f6564756cull,0x616d5f636e75662full,0x090a22682e6f7263ull,
0x383109656c69662eull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,
0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x665f6874616d2f65ull,0x736e6f6974636e75ull,
0x69662e090a22682eull,0x2f2209393109656cull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,
0x622f616475632f70ull,0x692f2e2e2f2f6e69ull,0x642f6564756c636eull,0x75665f6563697665ull,
0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x682f220930320965ull,0x616964672f656d6full,
0x706d65742f736f6dull,0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x616d2f6564756c63ull,
0x74736e6f635f6874ull,0x0a22682e73746e61ull,0x3209656c69662e09ull,0x656d6f682f220931ull,
0x736f6d616964672full,0x75632f706d65742full,0x2f2f6e69622f6164ull,0x756c636e692f2e2eull,
0x31315f6d732f6564ull,0x5f63696d6f74615full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209323209656c69ull,0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,
0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x74615f32315f6d73ull,0x6e75665f63696d6full,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209333209ull,0x6d616964672f656dull,
0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x5f6d732f6564756cull,
0x6c62756f645f3331ull,0x6974636e75665f65ull,0x090a22682e736e6full,0x343209656c69662eull,
0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,
0x64756c636e692f2eull,0x7275747865742f65ull,0x5f68637465665f65ull,0x6e6f6974636e7566ull,
0x662e090a22682e73ull,0x2209353209656c69ull,0x64672f656d6f682full,0x65742f736f6d6169ull,
0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x6e75665f6874616dull,
0x645f736e6f697463ull,0x2e317874705f6c62ull,0x65742e090a0a2268ull,0x74203436752e2078ull,
0x652e090a0a3b7865ull,0x385a5f207972746eull,0x7265646e65725f64ull,0x3472616863753650ull,
0x0a66666666666a6aull,0x6765722e090a7b09ull,0x7225203233752e20ull,0x2e090a3b3e30333cull,
0x3436752e20676572ull,0x3b3e363c64722520ull,0x2e206765722e090aull,0x323c662520323366ull,
0x65722e090a3b3e30ull,0x20646572702e2067ull,0x090a3b3e333c7025ull,0x2e206d617261702eull,
0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,
0x666666666a6a3472ull,0x7074756f5f645f66ull,0x61702e090a3b7475ull,0x3233752e206d6172ull,
0x70616475635f5f20ull,0x64385a5f5f6d7261ull,0x507265646e65725full,0x6a34726168637536ull,
0x775f66666666666aull,0x2e090a3b68746469ull,0x752e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x65646e65725f6438ull,0x7261686375365072ull,0x66666666666a6a34ull,
0x3b7468676965685full,0x6d617261702e090aull,0x5f5f203233662e20ull,0x6d72617061647563ull,
0x65725f64385a5f5full,0x637536507265646eull,0x66666a6a34726168ull,0x0a3b78745f666666ull,
0x206d617261702e09ull,0x635f5f203233662eull,0x5f6d726170616475ull,0x6e65725f64385a5full,
0x6863753650726564ull,0x6666666a6a347261ull,0x090a3b79745f6666ull,0x2e206d617261702eull,
0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,
0x666666666a6a3472ull,0x3b656c6163735f66ull,0x6d617261702e090aull,0x5f5f203233662e20ull,
0x6d72617061647563ull,0x65725f64385a5f5full,0x637536507265646eull,0x66666a6a34726168ull,
0x0a3b78635f666666ull,0x206d617261702e09ull,0x635f5f203233662eull,0x5f6d726170616475ull,
0x6e65725f64385a5full,0x6863753650726564ull,0x6666666a6a347261ull,0x090a3b79635f6666ull,
0x09353109636f6c2eull,0x4c240a3009393531ull,0x64385a5f5f314242ull,0x507265646e65725full,
0x6a34726168637536ull,0x0a3a66666666666aull,0x3233752e74766309ull,0x722509203631752eull,
0x6961746325202c31ull,0x092020203b782e64ull,0x747663090a202f2full,0x3631752e3233752eull,
0x25202c3272250920ull,0x203b782e6469746eull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233752e6full,0x2c317225202c3372ull,0x0920203b32722520ull,0x747663090a202f2full,
0x3631752e3233752eull,0x25202c3472250920ull,0x3b792e6469617463ull,0x0a202f2f09202020ull,
0x3233752e74766309ull,0x722509203631752eull,0x6469746e25202c35ull,0x09202020203b792eull,
0x6c756d090a202f2full,0x33752e6f6c2e3432ull,0x202c367225092032ull,0x357225202c347225ull,
0x0a202f2f0920203bull,0x3233752e74766309ull,0x722509203631752eull,0x2e64697425202c37ull,
0x0920202020203b78ull,0x646461090a202f2full,0x722509203233752eull,0x202c377225202c38ull,
0x202020203b337225ull,0x0a202f2f09202020ull,0x3233752e74766309ull,0x722509203631752eull,
0x2e64697425202c39ull,0x0920202020203b79ull,0x646461090a202f2full,0x722509203233752eull,
0x2c397225202c3031ull,0x2020203b36722520ull,0x0a202f2f09202020ull,0x617261702e646c09ull,
0x2509203233752e6dull,0x5f5f5b202c313172ull,0x6d72617061647563ull,0x65725f64385a5f5full,
0x637536507265646eull,0x66666a6a34726168ull,0x746469775f666666ull,0x69202f2f093b5d68ull,
0x635f5f2035383a64ull,0x5f6d726170616475ull,0x6e65725f64385a5full,0x6863753650726564ull,
0x6666666a6a347261ull,0x68746469775f6666ull,0x646c090a3078302bull,0x752e6d617261702eull,
0x3231722509203233ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x65646e65725f6438ull,
0x7261686375365072ull,0x66666666666a6a34ull,0x5d7468676965685full,0x3a6469202f2f093bull,
0x6475635f5f203239ull,0x5a5f5f6d72617061ull,0x65646e65725f6438ull,0x7261686375365072ull,
0x66666666666a6a34ull,0x2b7468676965685full,0x746573090a307830ull,0x2e3233752e74672eull,
0x3172250920323375ull,0x2c32317225202c33ull,0x2f093b3031722520ull,0x2e67656e090a202full,
0x3172250920323373ull,0x3b33317225202c34ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x752e746c2e746573ull,0x09203233752e3233ull,0x7225202c35317225ull,0x3b31317225202c38ull,
0x656e090a202f2f09ull,0x2509203233732e67ull,0x317225202c363172ull,0x2020202020203b35ull,
0x202f2f0920202020ull,0x33622e646e61090aull,0x2c37317225092032ull,0x25202c3431722520ull,
0x202020203b363172ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x203b30202c383172ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x652e70746573090aull,0x2509203233732e71ull,
0x37317225202c3170ull,0x203b38317225202cull,0x2540090a202f2f09ull,0x0920617262203170ull,
0x3b355f305f744c24ull,0x2020202020202020ull,0x202f2f0920202020ull,0x7261702e646c090aull,
0x09203233662e6d61ull,0x5f5f5b202c316625ull,0x6d72617061647563ull,0x65725f64385a5f5full,
0x637536507265646eull,0x66666a6a34726168ull,0x3b5d79635f666666ull,0x383a6469202f2f09ull,
0x616475635f5f2032ull,0x385a5f5f6d726170ull,0x7265646e65725f64ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x090a3078302b7963ull,0x6d617261702e646cull,0x662509203233662eull,
0x75635f5f5b202c32ull,0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,
0x666666666a6a3472ull,0x5d656c6163735f66ull,0x3a6469202f2f093bull,0x6475635f5f203338ull,
0x5a5f5f6d72617061ull,0x65646e65725f6438ull,0x7261686375365072ull,0x66666666666a6a34ull,
0x302b656c6163735full,0x702e646c090a3078ull,0x3233662e6d617261ull,0x5b202c3366250920ull,
0x6170616475635f5full,0x5f64385a5f5f6d72ull,0x36507265646e6572ull,0x6a6a347261686375ull,
0x78635f6666666666ull,0x6469202f2f093b5dull,0x75635f5f2034383aull,0x5f5f6d7261706164ull,
0x646e65725f64385aull,0x6168637536507265ull,0x666666666a6a3472ull,0x3078302b78635f66ull,
0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c346625ull,0x6d72617061647563ull,
0x65725f64385a5f5full,0x637536507265646eull,0x66666a6a34726168ull,0x3b5d78745f666666ull,
0x393a6469202f2f09ull,0x616475635f5f2034ull,0x385a5f5f6d726170ull,0x7265646e65725f64ull,
0x3472616863753650ull,0x5f66666666666a6aull,0x090a3078302b7874ull,0x662e6e722e747663ull,
0x09203233752e3233ull,0x387225202c356625ull,0x2f0920202020203bull,0x2e627573090a202full,
0x3666250920323366ull,0x25202c356625202cull,0x20202020203b3366ull,0x090a202f2f092020ull,
0x203233662e64616dull,0x6625202c37662509ull,0x202c366625202c32ull,0x2f0920203b336625ull,
0x2e646461090a202full,0x3866250920323366ull,0x25202c346625202cull,0x20202020203b3766ull,
0x090a202f2f092020ull,0x6d617261702e646cull,0x662509203233662eull,0x75635f5f5b202c39ull,
0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,0x666666666a6a3472ull,
0x2f093b5d79745f66ull,0x2035393a6469202full,0x6170616475635f5full,0x5f64385a5f5f6d72ull,
0x36507265646e6572ull,0x6a6a347261686375ull,0x79745f6666666666ull,0x7663090a3078302bull,
0x3233662e6e722e74ull,0x662509203233752eull,0x30317225202c3031ull,0x202f2f092020203bull,
0x33662e627573090aull,0x2c31316625092032ull,0x25202c3031662520ull,0x20202020203b3166ull,
0x616d090a202f2f09ull,0x2509203233662e64ull,0x326625202c323166ull,0x202c31316625202cull,
0x202f2f093b316625ull,0x33662e646461090aull,0x2c33316625092032ull,0x6625202c39662520ull,
0x20202020203b3231ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x306630202c343166ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3531662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x762e64322e786574ull,
0x33662e3233752e34ull,0x2c393172257b2032ull,0x3272252c30327225ull,0x2c7d323272252c31ull,
0x66257b2c7865745bull,0x252c333166252c38ull,0x353166252c343166ull,0x6f6c2e090a3b5d7dull,
0x3037310935310963ull,0x2e766f6d090a3009ull,0x3272250920323373ull,0x3b39317225202c33ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009313731ull,
0x09203233622e766full,0x7225202c36316625ull,0x20202020203b3332ull,0x2f2f092020202020ull,
0x662e766f6d090a20ull,0x3731662509203233ull,0x663733346630202cull,0x2020203b30303030ull,
0x353532202f2f0920ull,0x33662e6c756d090aull,0x2c38316625092032ull,0x25202c3631662520ull,
0x202020203b373166ull,0x756d090a202f2f09ull,0x752e6f6c2e34326cull,0x3432722509203233ull,
0x202c30317225202cull,0x2f2f093b31317225ull,0x722e747663090a20ull,0x662e3233752e697aull,
0x3532722509203233ull,0x203b38316625202cull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x7225202c36327225ull,0x20202020203b3532ull,0x2f2f092020202020ull,0x61702e646c090a20ull,
0x203436752e6d6172ull,0x5b202c3164722509ull,0x6170616475635f5full,0x5f64385a5f5f6d72ull,
0x36507265646e6572ull,0x6a6a347261686375ull,0x5f645f6666666666ull,0x3b5d74757074756full,
0x393a6469202f2f09ull,0x616475635f5f2036ull,0x385a5f5f6d726170ull,0x7265646e65725f64ull,
0x3472616863753650ull,0x5f66666666666a6aull,0x74757074756f5f64ull,0x6461090a3078302bull,
0x2509203233752e64ull,0x387225202c373272ull,0x203b34327225202cull,0x202f2f0920202020ull,
0x36752e747663090aull,0x2509203233752e34ull,0x327225202c326472ull,0x2020202020203b37ull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x202c336472250920ull,0x3b34202c32647225ull,
0x202f2f0920202020ull,0x36752e646461090aull,0x2c34647225092034ull,0x25202c3164722520ull,
0x202020203b336472ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x203b30202c383272ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x6f6c672e7473090aull,0x752e34762e6c6162ull,
0x346472255b092038ull,0x72257b202c5d302bull,0x2c363272252c3632ull,0x3272252c36327225ull,
0x0a202f2f093b7d38ull,0x3a355f305f744c24ull,0x3109636f6c2e090aull,0x0a30093337310935ull,
0x20203b7469786509ull,0x2020202020202020ull,0x2020202020202020ull,0x0920202020202020ull,
0x57444c240a202f2full,0x64385a5f5f646e65ull,0x507265646e65725full,0x6a34726168637536ull,
0x0a3a66666666666aull,0x5a5f202f2f207d09ull,0x65646e65725f6438ull,0x7261686375365072ull,
0x66666666666a6a34ull,0x72746e652e090a0aull,0x5f6435315a5f2079ull,0x69427265646e6572ull,
0x7536506369627563ull,0x666a6a3472616863ull,0x0a7b090a66666666ull,0x752e206765722e09ull,
0x30313c7225203233ull,0x65722e090a3b3e34ull,0x25203436752e2067ull,0x090a3b3e363c6472ull,
0x33662e206765722eull,0x3031323c66252032ull,0x6765722e090a3b3eull,0x2520646572702e20ull,
0x2e090a3b3e333c70ull,0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,
0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,0x66666666666a6a34ull,
0x757074756f5f645full,0x7261702e090a3b74ull,0x203233752e206d61ull,0x6170616475635f5full,
0x6435315a5f5f6d72ull,0x427265646e65725full,0x3650636962756369ull,0x6a6a347261686375ull,
0x69775f6666666666ull,0x702e090a3b687464ull,0x33752e206d617261ull,0x616475635f5f2032ull,
0x315a5f5f6d726170ull,0x65646e65725f6435ull,0x6369627563694272ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x0a3b746867696568ull,0x206d617261702e09ull,0x635f5f203233662eull,
0x5f6d726170616475ull,0x65725f6435315a5full,0x756369427265646eull,0x6863753650636962ull,
0x6666666a6a347261ull,0x090a3b78745f6666ull,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x2e090a3b79745f66ull,0x662e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x0a3b656c6163735full,0x206d617261702e09ull,0x635f5f203233662eull,
0x5f6d726170616475ull,0x65725f6435315a5full,0x756369427265646eull,0x6863753650636962ull,
0x6666666a6a347261ull,0x090a3b78635f6666ull,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x2e090a3b79635f66ull,0x3109353109636f6cull,0x424c240a30093737ull,
0x6435315a5f5f3142ull,0x427265646e65725full,0x3650636962756369ull,0x6a6a347261686375ull,
0x090a3a6666666666ull,0x2e3233752e747663ull,0x3172250920363175ull,0x646961746325202cull,
0x2f092020203b782eull,0x2e747663090a202full,0x203631752e323375ull,0x6e25202c32722509ull,
0x20203b782e646974ull,0x090a202f2f092020ull,0x6f6c2e34326c756dull,0x722509203233752eull,
0x202c317225202c33ull,0x2f0920203b327225ull,0x2e747663090a202full,0x203631752e323375ull,
0x6325202c34722509ull,0x203b792e64696174ull,0x090a202f2f092020ull,0x2e3233752e747663ull,
0x3572250920363175ull,0x2e6469746e25202cull,0x2f09202020203b79ull,0x326c756d090a202full,
0x3233752e6f6c2e34ull,0x25202c3672250920ull,0x3b357225202c3472ull,0x090a202f2f092020ull,
0x2e3233752e747663ull,0x3772250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,
0x2e646461090a202full,0x3872250920323375ull,0x25202c377225202cull,0x20202020203b3372ull,
0x090a202f2f092020ull,0x2e3233752e747663ull,0x3972250920363175ull,0x792e64697425202cull,
0x2f0920202020203bull,0x2e646461090a202full,0x3172250920323375ull,0x202c397225202c30ull,
0x202020203b367225ull,0x090a202f2f092020ull,0x6d617261702e646cull,0x722509203233752eull,
0x635f5f5b202c3131ull,0x5f6d726170616475ull,0x65725f6435315a5full,0x756369427265646eull,
0x6863753650636962ull,0x6666666a6a347261ull,0x68746469775f6666ull,0x6469202f2f093b5dull,
0x635f5f203336363aull,0x5f6d726170616475ull,0x65725f6435315a5full,0x756369427265646eull,
0x6863753650636962ull,0x6666666a6a347261ull,0x68746469775f6666ull,0x646c090a3078302bull,
0x752e6d617261702eull,0x3231722509203233ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,0x66666666666a6a34ull,
0x5d7468676965685full,0x3a6469202f2f093bull,0x75635f5f20303736ull,0x5f5f6d7261706164ull,
0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,0x666666666a6a3472ull,
0x7468676965685f66ull,0x6573090a3078302bull,0x3233752e74672e74ull,0x722509203233752eull,
0x32317225202c3331ull,0x093b30317225202cull,0x67656e090a202f2full,0x722509203233732eull,
0x33317225202c3431ull,0x202020202020203bull,0x0a202f2f09202020ull,0x2e746c2e74657309ull,
0x203233752e323375ull,0x25202c3531722509ull,0x31317225202c3872ull,0x6e090a202f2f093bull,
0x09203233732e6765ull,0x7225202c36317225ull,0x20202020203b3531ull,0x2f2f092020202020ull,
0x622e646e61090a20ull,0x3731722509203233ull,0x202c34317225202cull,0x2020203b36317225ull,
0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c38317225ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e7165ull,0x317225202c317025ull,
0x3b38317225202c37ull,0x40090a202f2f0920ull,0x2061726220317025ull,0x355f315f744c2409ull,
0x202020202020203bull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009373131093531ull,
0x6e722e747663090aull,0x3233752e3233662eull,0x25202c3166250920ull,0x20202020203b3872ull,
0x7663090a202f2f09ull,0x3233662e6e722e74ull,0x662509203233752eull,0x3b30317225202c32ull,
0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c336625ull,
0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,0x6375365063696275ull,
0x66666a6a34726168ull,0x3b5d78635f666666ull,0x363a6469202f2f09ull,0x6475635f5f203236ull,
0x5a5f5f6d72617061ull,0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x0a3078302b78635full,0x3233662e62757309ull,0x25202c3466250920ull,
0x3b336625202c3166ull,0x0920202020202020ull,0x2e646c090a202f2full,0x33662e6d61726170ull,
0x202c356625092032ull,0x70616475635f5f5bull,0x35315a5f5f6d7261ull,0x7265646e65725f64ull,
0x5063696275636942ull,0x6a34726168637536ull,0x635f66666666666aull,0x69202f2f093b5d79ull,
0x5f5f203136363a64ull,0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x302b79635f666666ull,0x2e627573090a3078ull,
0x3666250920323366ull,0x25202c326625202cull,0x20202020203b3566ull,0x090a202f2f092020ull,
0x6d617261702e646cull,0x662509203233662eull,0x75635f5f5b202c37ull,0x5f5f6d7261706164ull,
0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,0x666666666a6a3472ull,
0x5d656c6163735f66ull,0x3a6469202f2f093bull,0x75635f5f20303636ull,0x5f5f6d7261706164ull,
0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,0x666666666a6a3472ull,
0x2b656c6163735f66ull,0x6c756d090a307830ull,0x662509203233662eull,0x202c346625202c38ull,
0x202020203b376625ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,0x25202c3966250920ull,
0x3b376625202c3666ull,0x0920202020202020ull,0x646461090a202f2full,0x662509203233662eull,
0x2c386625202c3031ull,0x2020203b33662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c313166250920ull,0x356625202c396625ull,0x092020202020203bull,0x2e646c090a202f2full,
0x33662e6d61726170ull,0x2c32316625092032ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x65646e65725f6435ull,0x6369627563694272ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x202f2f093b5d7874ull,0x5f203137363a6469ull,0x726170616475635full,0x5f6435315a5f5f6dull,
0x69427265646e6572ull,0x7536506369627563ull,0x666a6a3472616863ull,0x2b78745f66666666ull,
0x646461090a307830ull,0x662509203233662eull,0x32316625202c3331ull,0x203b30316625202cull,
0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203233662e6dull,0x5f5f5b202c343166ull,
0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,0x6375365063696275ull,
0x66666a6a34726168ull,0x3b5d79745f666666ull,0x363a6469202f2f09ull,0x6475635f5f203237ull,
0x5a5f5f6d72617061ull,0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x0a3078302b79745full,0x3233662e64646109ull,0x202c353166250920ull,
0x6625202c34316625ull,0x09202020203b3131ull,0x766f6d090a202f2full,0x662509203233662eull,
0x66626630202c3631ull,0x203b303030303030ull,0x2d202f2f09202020ull,0x646461090a352e30ull,
0x662509203233662eull,0x33316625202c3731ull,0x203b36316625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c383166250920ull,0x3030303066626630ull,0x09202020203b3030ull,
0x0a352e302d202f2full,0x3233662e64646109ull,0x202c393166250920ull,0x6625202c35316625ull,
0x09202020203b3831ull,0x747663090a202f2full,0x3233662e696d722eull,0x662509203233662eull,
0x37316625202c3032ull,0x0a202f2f0920203bull,0x696d722e74766309ull,0x3233662e3233662eull,
0x202c313266250920ull,0x0920203b39316625ull,0x766f6d090a202f2full,0x662509203233662eull,
0x66626630202c3232ull,0x203b303030303038ull,0x2d202f2f09202020ull,0x662e646461090a31ull,
0x3332662509203233ull,0x202c30326625202cull,0x2020203b32326625ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x6630202c34326625ull,0x3030303030386662ull,0x2f2f09202020203bull,
0x646461090a312d20ull,0x662509203233662eull,0x31326625202c3532ull,0x203b34326625202cull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c363266250920ull,0x2020203b33326625ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x35326625202c3732ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c383266250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,
0x306630202c393266ull,0x3b30303030303030ull,0x202f2f0920202020ull,0x322e786574090a30ull,
0x3233752e34762e64ull,0x72257b203233662eull,0x2c303272252c3931ull,0x3272252c31327225ull,
0x2c7865745b2c7d32ull,0x66252c363266257bull,0x2c383266252c3732ull,0x0a3b5d7d39326625ull,
0x353109636f6c2e09ull,0x090a300931323109ull,0x203233732e766f6dull,0x25202c3332722509ull,
0x202020203b393172ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3366250920323366ull,
0x3b30326625202c30ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x25202c3133662509ull,0x202020203b353266ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3366250920323366ull,0x3030306630202c32ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x3233662e766f6d09ull,0x202c333366250920ull,0x3030303030306630ull,0x09202020203b3030ull,
0x6574090a30202f2full,0x2e34762e64322e78ull,0x203233662e323375ull,0x72252c343272257bull,
0x2c363272252c3532ull,0x745b2c7d37327225ull,0x303366257b2c7865ull,0x66252c313366252cull,
0x7d333366252c3233ull,0x2e766f6d090a3b5dull,0x3272250920323373ull,0x3b34327225202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3433662509ull,
0x3030303038663366ull,0x2f09202020203b30ull,0x646461090a31202full,0x662509203233662eull,
0x30326625202c3533ull,0x203b34336625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c363366250920ull,0x2020203b35336625ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x662509203233662eull,0x35326625202c3733ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c383366250920ull,0x3030303030306630ull,0x09202020203b3030ull,
0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c393366ull,0x3b30303030303030ull,
0x202f2f0920202020ull,0x322e786574090a30ull,0x3233752e34762e64ull,0x72257b203233662eull,
0x2c303372252c3932ull,0x3372252c31337225ull,0x2c7865745b2c7d32ull,0x66252c363366257bull,
0x2c383366252c3733ull,0x0a3b5d7d39336625ull,0x3233732e766f6d09ull,0x202c333372250920ull,
0x2020203b39327225ull,0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,
0x30346630202c3034ull,0x203b303030303030ull,0x32202f2f09202020ull,0x33662e646461090aull,
0x2c31346625092032ull,0x25202c3032662520ull,0x202020203b303466ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x346625202c323466ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c33346625092032ull,0x20203b3532662520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x306630202c343466ull,0x3b30303030303030ull,
0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3534662509203233ull,0x303030306630202cull,
0x2020203b30303030ull,0x090a30202f2f0920ull,0x762e64322e786574ull,0x33662e3233752e34ull,
0x2c343372257b2032ull,0x3372252c35337225ull,0x2c7d373372252c36ull,0x66257b2c7865745bull,
0x2c333466252c3234ull,0x3466252c34346625ull,0x6f6d090a3b5d7d35ull,0x2509203233732e76ull,
0x337225202c383372ull,0x2020202020203b34ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c36346625092032ull,0x20203b3332662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x326625202c373466ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c38346625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c39346625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e786574090a3020ull,0x33752e34762e6432ull,0x257b203233662e32ull,
0x303472252c393372ull,0x72252c313472252cull,0x7865745b2c7d3234ull,0x252c363466257b2cull,
0x383466252c373466ull,0x3b5d7d393466252cull,0x33732e766f6d090aull,0x2c33347225092032ull,
0x20203b3933722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x326625202c303566ull,0x2020202020203b30ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c31356625092032ull,0x20203b3132662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x306630202c323566ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3335662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x762e64322e786574ull,0x33662e3233752e34ull,0x2c343472257b2032ull,
0x3472252c35347225ull,0x2c7d373472252c36ull,0x66257b2c7865745bull,0x2c313566252c3035ull,
0x3566252c32356625ull,0x6f6d090a3b5d7d33ull,0x2509203233732e76ull,0x347225202c383472ull,
0x2020202020203b34ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c34356625092032ull,
0x20203b3533662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x326625202c353566ull,0x2020202020203b31ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c36356625092032ull,0x3030303030663020ull,0x202020203b303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x6630202c37356625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x2e786574090a3020ull,0x33752e34762e6432ull,0x257b203233662e32ull,0x303572252c393472ull,
0x72252c313572252cull,0x7865745b2c7d3235ull,0x252c343566257b2cull,0x363566252c353566ull,
0x3b5d7d373566252cull,0x33732e766f6d090aull,0x2c33357225092032ull,0x20203b3934722520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x346625202c383566ull,
0x2020202020203b31ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c39356625092032ull,
0x20203b3132662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x306630202c303666ull,0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,
0x3136662509203233ull,0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,
0x762e64322e786574ull,0x33662e3233752e34ull,0x2c343572257b2032ull,0x3572252c35357225ull,
0x2c7d373572252c36ull,0x66257b2c7865745bull,0x2c393566252c3835ull,0x3666252c30366625ull,
0x6f6d090a3b5d7d31ull,0x2509203233732e76ull,0x357225202c383572ull,0x2020202020203b34ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c32366625092032ull,0x3030386633663020ull,
0x202020203b303030ull,0x61090a31202f2f09ull,0x09203233662e6464ull,0x6625202c33366625ull,
0x32366625202c3132ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3436662509203233ull,
0x203b33326625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6625202c35366625ull,0x20202020203b3336ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,
0x3636662509203233ull,0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,
0x203233662e766f6dull,0x30202c3736662509ull,0x3030303030303066ull,0x2f09202020203b30ull,
0x786574090a30202full,0x752e34762e64322eull,0x7b203233662e3233ull,0x3672252c39357225ull,
0x252c313672252c30ull,0x65745b2c7d323672ull,0x2c343666257b2c78ull,0x3666252c35366625ull,
0x5d7d373666252c36ull,0x732e766f6d090a3bull,0x3336722509203233ull,0x203b39357225202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c38366625ull,
0x20202020203b3032ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3936662509203233ull,
0x203b33366625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c30376625ull,0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,
0x3766250920323366ull,0x3030306630202c31ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x2e64322e78657409ull,0x662e3233752e3476ull,0x343672257b203233ull,0x72252c353672252cull,
0x7d373672252c3636ull,0x257b2c7865745b2cull,0x393666252c383666ull,0x66252c303766252cull,
0x6d090a3b5d7d3137ull,0x09203233732e766full,0x7225202c38367225ull,0x20202020203b3436ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3237662509203233ull,0x203b35336625202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c33376625ull,
0x20202020203b3336ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3437662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x30202c3537662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x786574090a30202full,
0x752e34762e64322eull,0x7b203233662e3233ull,0x3772252c39367225ull,0x252c313772252c30ull,
0x65745b2c7d323772ull,0x2c323766257b2c78ull,0x3766252c33376625ull,0x5d7d353766252c34ull,
0x732e766f6d090a3bull,0x3337722509203233ull,0x203b39367225202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c36376625ull,0x20202020203b3134ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3737662509203233ull,0x203b33366625202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c38376625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3766250920323366ull,
0x3030306630202c39ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x2e64322e78657409ull,
0x662e3233752e3476ull,0x343772257b203233ull,0x72252c353772252cull,0x7d373772252c3637ull,
0x257b2c7865745b2cull,0x373766252c363766ull,0x66252c383766252cull,0x6d090a3b5d7d3937ull,
0x09203233732e766full,0x7225202c38377225ull,0x20202020203b3437ull,0x2f2f092020202020ull,
0x662e766f6d090a20ull,0x3038662509203233ull,0x303030346630202cull,0x2020203b30303030ull,
0x090a32202f2f0920ull,0x203233662e646461ull,0x25202c3138662509ull,0x386625202c313266ull,
0x2f09202020203b30ull,0x2e766f6d090a202full,0x3866250920323366ull,0x3b33326625202c32ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3338662509ull,
0x202020203b313866ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3866250920323366ull,
0x3030306630202c34ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x202c353866250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x6574090a30202f2full,
0x2e34762e64322e78ull,0x203233662e323375ull,0x72252c393772257bull,0x2c313872252c3038ull,
0x745b2c7d32387225ull,0x323866257b2c7865ull,0x66252c333866252cull,0x7d353866252c3438ull,
0x2e766f6d090a3b5dull,0x3872250920323373ull,0x3b39377225202c33ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3638662509ull,0x202020203b303266ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3866250920323366ull,0x3b31386625202c37ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3838662509ull,
0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,0x662509203233662eull,
0x30306630202c3938ull,0x203b303030303030ull,0x30202f2f09202020ull,0x64322e786574090aull,
0x2e3233752e34762eull,0x3872257b20323366ull,0x252c353872252c34ull,0x373872252c363872ull,
0x7b2c7865745b2c7dull,0x3866252c36386625ull,0x252c383866252c37ull,0x090a3b5d7d393866ull,
0x203233732e766f6dull,0x25202c3838722509ull,0x202020203b343872ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3966250920323366ull,0x3b35336625202c30ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3139662509ull,0x202020203b313866ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3966250920323366ull,0x3030306630202c32ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c333966250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x6574090a30202f2full,0x2e34762e64322e78ull,
0x203233662e323375ull,0x72252c393872257bull,0x2c313972252c3039ull,0x745b2c7d32397225ull,
0x303966257b2c7865ull,0x66252c313966252cull,0x7d333966252c3239ull,0x2e766f6d090a3b5dull,
0x3972250920323373ull,0x3b39387225202c33ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x25202c3439662509ull,0x202020203b313466ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3966250920323366ull,0x3b31386625202c35ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3639662509ull,0x3030303030303066ull,
0x2f09202020203b30ull,0x766f6d090a30202full,0x662509203233662eull,0x30306630202c3739ull,
0x203b303030303030ull,0x30202f2f09202020ull,0x64322e786574090aull,0x2e3233752e34762eull,
0x3972257b20323366ull,0x252c353972252c34ull,0x373972252c363972ull,0x7b2c7865745b2c7dull,
0x3966252c34396625ull,0x252c363966252c35ull,0x090a3b5d7d373966ull,0x203233732e766f6dull,
0x25202c3839722509ull,0x202020203b343972ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0933303109353109ull,0x662e627573090a30ull,0x3839662509203233ull,0x202c37316625202cull,
0x2020203b30326625ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c39396625ull,
0x3030303030343034ull,0x2f2f09202020203bull,0x2e6c756d090a3320ull,0x3166250920323366ull,
0x38396625202c3030ull,0x203b39396625202cull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x202c313031662509ull,0x6625202c38396625ull,0x2f092020203b3839ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x30636630202c3230ull,0x203b303030303063ull,0x362d202f2f092020ull,
0x33662e646461090aull,0x3330316625092032ull,0x2c3030316625202cull,0x203b323031662520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c34303166ull,0x316625202c313031ull,
0x202f2f09203b3330ull,0x33662e766f6d090aull,0x3530316625092032ull,0x303830346630202cull,
0x2020203b30303030ull,0x61090a34202f2f09ull,0x09203233662e6464ull,0x25202c3630316625ull,
0x6625202c34303166ull,0x2f2f09203b353031ull,0x662e766f6d090a20ull,0x3031662509203233ull,
0x3265336630202c37ull,0x20203b6261616161ull,0x312e30202f2f0920ull,0x6d090a3736363636ull,
0x09203233662e6c75ull,0x25202c3830316625ull,0x6625202c36303166ull,0x2f2f09203b373031ull,
0x09636f6c2e090a20ull,0x3009313231093531ull,0x33662e766f6d090aull,0x3930316625092032ull,
0x303430346630202cull,0x2020203b30303030ull,0x73090a33202f2f09ull,0x09203233662e6275ull,
0x25202c3031316625ull,0x6625202c39303166ull,0x2f2f0920203b3839ull,0x662e766f6d090a20ull,
0x3131662509203233ull,0x3430636630202c31ull,0x20203b3030303030ull,0x0a332d202f2f0920ull,
0x3233662e6c756d09ull,0x2c32313166250920ull,0x25202c3839662520ull,0x0920203b31313166ull,
0x6c756d090a202f2full,0x662509203233662eull,0x396625202c333131ull,0x3130316625202c38ull,
0x0a202f2f0920203bull,0x3233662e6c756d09ull,0x2c34313166250920ull,0x25202c3839662520ull,
0x0920203b30313166ull,0x766f6d090a202f2full,0x662509203233662eull,0x346630202c353131ull,
0x3b30303030303430ull,0x33202f2f09202020ull,0x33662e646461090aull,0x3631316625092032ull,
0x2c3231316625202cull,0x203b353131662520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x6630202c37313166ull,0x6261616161326533ull,0x202f2f092020203bull,0x3736363636312e30ull,
0x33662e6c756d090aull,0x3831316625092032ull,0x2c3331316625202cull,0x203b373131662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c39313166ull,0x3030303030343063ull,
0x202f2f092020203bull,0x2e646461090a332dull,0x3166250920323366ull,0x31316625202c3032ull,
0x3931316625202c34ull,0x090a202f2f09203bull,0x203233662e6c756dull,0x202c313231662509ull,
0x6625202c38396625ull,0x2f0920203b363131ull,0x2e6c756d090a202full,0x3166250920323366ull,
0x38396625202c3232ull,0x3b3032316625202cull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x202c333231662509ull,0x3030303430346630ull,0x2f092020203b3030ull,0x646461090a33202full,
0x662509203233662eull,0x316625202c343231ull,0x32316625202c3132ull,0x0a202f2f09203b33ull,
0x3233662e766f6d09ull,0x2c35323166250920ull,0x3030386633663020ull,0x092020203b303030ull,
0x6461090a31202f2full,0x2509203233662e64ull,0x6625202c36323166ull,0x316625202c323231ull,
0x202f2f09203b3532ull,0x33662e6c756d090aull,0x3732316625092032ull,0x202c38396625202cull,
0x20203b3432316625ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c38323166ull,
0x6261616161326533ull,0x202f2f092020203bull,0x3736363636312e30ull,0x33662e6c756d090aull,
0x3932316625092032ull,0x2c3632316625202cull,0x203b383231662520ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x6630202c30333166ull,0x3030303030386633ull,0x202f2f092020203bull,
0x662e646461090a31ull,0x3331662509203233ull,0x3732316625202c31ull,0x3b3033316625202cull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x30202c3233316625ull,0x6161616132653366ull,
0x2f2f092020203b62ull,0x36363636312e3020ull,0x662e6c756d090a37ull,0x3331662509203233ull,
0x3133316625202c33ull,0x3b3233316625202cull,0x6d090a202f2f0920ull,0x09203233622e766full,
0x25202c3433316625ull,0x202020203b333272ull,0x2f2f092020202020ull,0x662e6c756d090a20ull,
0x3331662509203233ull,0x3932316625202c35ull,0x3b3433316625202cull,0x6d090a202f2f0920ull,
0x09203233622e766full,0x25202c3633316625ull,0x202020203b383272ull,0x2f2f092020202020ull,
0x662e64616d090a20ull,0x3331662509203233ull,0x3830316625202c37ull,0x2c3633316625202cull,
0x093b353331662520ull,0x766f6d090a202f2full,0x662509203233622eull,0x337225202c383331ull,
0x2020202020203b33ull,0x0a202f2f09202020ull,0x3233662e64616d09ull,0x2c39333166250920ull,
0x202c333331662520ull,0x25202c3833316625ull,0x2f2f093b37333166ull,0x622e766f6d090a20ull,
0x3431662509203233ull,0x3b38337225202c30ull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233662e6461ull,0x25202c3134316625ull,0x6625202c38313166ull,0x316625202c303431ull,
0x0a202f2f093b3933ull,0x3233622e766f6d09ull,0x2c32343166250920ull,0x20203b3334722520ull,
0x0920202020202020ull,0x6c756d090a202f2full,0x662509203233662eull,0x316625202c333431ull,
0x34316625202c3932ull,0x0a202f2f09203b32ull,0x3233622e766f6d09ull,0x2c34343166250920ull,
0x20203b3834722520ull,0x0920202020202020ull,0x64616d090a202f2full,0x662509203233662eull,
0x316625202c353431ull,0x34316625202c3830ull,0x3334316625202c34ull,0x6d090a202f2f093bull,
0x09203233622e766full,0x25202c3634316625ull,0x202020203b333572ull,0x2f2f092020202020ull,
0x662e64616d090a20ull,0x3431662509203233ull,0x3333316625202c37ull,0x2c3634316625202cull,
0x093b353431662520ull,0x766f6d090a202f2full,0x662509203233622eull,0x357225202c383431ull,
0x2020202020203b38ull,0x0a202f2f09202020ull,0x3233662e64616d09ull,0x2c39343166250920ull,
0x202c383131662520ull,0x25202c3834316625ull,0x2f2f093b37343166ull,0x622e766f6d090a20ull,
0x3531662509203233ull,0x3b33367225202c30ull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233662e6c75ull,0x25202c3135316625ull,0x6625202c39323166ull,0x2f2f09203b303531ull,
0x622e766f6d090a20ull,0x3531662509203233ull,0x3b38367225202c32ull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3335316625ull,0x6625202c38303166ull,
0x316625202c323531ull,0x0a202f2f093b3135ull,0x3233622e766f6d09ull,0x2c34353166250920ull,
0x20203b3337722520ull,0x0920202020202020ull,0x64616d090a202f2full,0x662509203233662eull,
0x316625202c353531ull,0x35316625202c3333ull,0x3335316625202c34ull,0x6d090a202f2f093bull,
0x09203233622e766full,0x25202c3635316625ull,0x202020203b383772ull,0x2f2f092020202020ull,
0x662e64616d090a20ull,0x3531662509203233ull,0x3831316625202c37ull,0x2c3635316625202cull,
0x093b353531662520ull,0x766f6d090a202f2full,0x662509203233622eull,0x387225202c383531ull,
0x2020202020203b33ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,0x2c39353166250920ull,
0x202c393231662520ull,0x09203b3835316625ull,0x766f6d090a202f2full,0x662509203233622eull,
0x387225202c303631ull,0x2020202020203b38ull,0x0a202f2f09202020ull,0x3233662e64616d09ull,
0x2c31363166250920ull,0x202c383031662520ull,0x25202c3036316625ull,0x2f2f093b39353166ull,
0x622e766f6d090a20ull,0x3631662509203233ull,0x3b33397225202c32ull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3336316625ull,0x6625202c33333166ull,
0x316625202c323631ull,0x0a202f2f093b3136ull,0x3233622e766f6d09ull,0x2c34363166250920ull,
0x20203b3839722520ull,0x0920202020202020ull,0x64616d090a202f2full,0x662509203233662eull,
0x316625202c353631ull,0x36316625202c3831ull,0x3336316625202c34ull,0x2e090a202f2f093bull,
0x3109353109636f6cull,0x7573090a30093230ull,0x2509203233662e62ull,0x6625202c36363166ull,
0x31326625202c3931ull,0x202f2f092020203bull,0x33662e766f6d090aull,0x3736316625092032ull,
0x303866336630202cull,0x2020203b30303030ull,0x6d090a31202f2f09ull,0x09203233662e766full,
0x30202c3836316625ull,0x3030303034306366ull,0x2f2f092020203b30ull,0x766f6d090a332d20ull,
0x662509203233662eull,0x346630202c393631ull,0x3b30303030303430ull,0x33202f2f09202020ull,
0x33662e627573090aull,0x3037316625092032ull,0x2c3936316625202cull,0x203b363631662520ull,
0x616d090a202f2f09ull,0x2509203233662e64ull,0x6625202c31373166ull,0x316625202c363631ull,
0x36316625202c3037ull,0x090a202f2f093b38ull,0x203233662e64616dull,0x202c323731662509ull,
0x25202c3137316625ull,0x6625202c36363166ull,0x202f2f093b373631ull,0x33662e766f6d090aull,
0x3337316625092032ull,0x613265336630202cull,0x2020203b62616161ull,0x36312e30202f2f09ull,
0x756d090a37363636ull,0x2509203233662e6cull,0x6625202c34373166ull,0x316625202c323731ull,
0x202f2f09203b3337ull,0x3109636f6c2e090aull,0x0a30093330310935ull,0x3233662e766f6d09ull,
0x2c35373166250920ull,0x3030343034663020ull,0x092020203b303030ull,0x756d090a33202f2full,
0x2509203233662e6cull,0x6625202c36373166ull,0x316625202c363631ull,0x202f2f09203b3537ull,
0x33662e6c756d090aull,0x3737316625092032ull,0x2c3636316625202cull,0x203b363631662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c38373166ull,0x3030303030633063ull,
0x202f2f092020203bull,0x2e646461090a362dull,0x3166250920323366ull,0x37316625202c3937ull,
0x3837316625202c36ull,0x090a202f2f09203bull,0x203233662e6c756dull,0x202c303831662509ull,
0x25202c3737316625ull,0x2f09203b39373166ull,0x2e766f6d090a202full,0x3166250920323366ull,
0x30346630202c3138ull,0x203b303030303038ull,0x0a34202f2f092020ull,0x3233662e64646109ull,
0x2c32383166250920ull,0x202c303831662520ull,0x09203b3138316625ull,0x766f6d090a202f2full,
0x662509203233662eull,0x336630202c333831ull,0x3b62616161613265ull,0x30202f2f09202020ull,
0x0a3736363636312eull,0x3233662e6c756d09ull,0x2c34383166250920ull,0x202c323831662520ull,
0x09203b3338316625ull,0x6f6c2e090a202f2full,0x3430310935310963ull,0x2e766f6d090a3009ull,
0x3166250920323366ull,0x30636630202c3538ull,0x203b303030303034ull,0x332d202f2f092020ull,
0x33662e6c756d090aull,0x3638316625092032ull,0x2c3636316625202cull,0x203b353831662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c37383166ull,0x3030303030343034ull,
0x202f2f092020203bull,0x662e646461090a33ull,0x3831662509203233ull,0x3638316625202c38ull,
0x3b3738316625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x25202c3938316625ull,
0x6625202c36363166ull,0x2f2f09203b383831ull,0x662e766f6d090a20ull,0x3931662509203233ull,
0x3430346630202c30ull,0x20203b3030303030ull,0x090a33202f2f0920ull,0x203233662e646461ull,
0x202c313931662509ull,0x25202c3938316625ull,0x2f09203b30393166ull,0x2e6c756d090a202full,
0x3166250920323366ull,0x36316625202c3239ull,0x3139316625202c36ull,0x090a202f2f09203bull,
0x203233662e766f6dull,0x202c333931662509ull,0x3030303866336630ull,0x2f092020203b3030ull,
0x646461090a31202full,0x662509203233662eull,0x316625202c343931ull,0x39316625202c3239ull,
0x0a202f2f09203b33ull,0x3233662e766f6d09ull,0x2c35393166250920ull,0x6161326533663020ull,
0x092020203b626161ull,0x3636312e30202f2full,0x6c756d090a373636ull,0x662509203233662eull,
0x316625202c363931ull,0x39316625202c3439ull,0x0a202f2f09203b35ull,0x353109636f6c2e09ull,
0x090a300939383109ull,0x203233662e6c756dull,0x202c373931662509ull,0x25202c3437316625ull,
0x2f09203b31343166ull,0x326c756d090a202full,0x3233752e6f6c2e34ull,0x202c393972250920ull,
0x7225202c30317225ull,0x0a202f2f093b3131ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5f5b202c316472ull,0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x756f5f645f666666ull,0x2f093b5d74757074ull,
0x3337363a6469202full,0x70616475635f5f20ull,0x35315a5f5f6d7261ull,0x7265646e65725f64ull,
0x5063696275636942ull,0x6a34726168637536ull,0x645f66666666666aull,0x2b74757074756f5full,
0x646461090a307830ull,0x722509203233752eull,0x387225202c303031ull,0x203b39397225202cull,
0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233752eull,0x30317225202c3264ull,
0x0920202020203b30ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x25202c3364722509ull,
0x203b34202c326472ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x202c346472250920ull,
0x7225202c31647225ull,0x09202020203b3364ull,0x6c756d090a202f2full,0x662509203233662eull,
0x316625202c383931ull,0x37316625202c3636ull,0x0a202f2f09203b37ull,0x3233662e766f6d09ull,
0x2c39393166250920ull,0x6161326533663020ull,0x092020203b626161ull,0x3636312e30202f2full,
0x6c756d090a373636ull,0x662509203233662eull,0x316625202c303032ull,0x39316625202c3839ull,
0x0a202f2f09203b39ull,0x3233662e6c756d09ull,0x2c31303266250920ull,0x202c303032662520ull,
0x09203b3536316625ull,0x6c756d090a202f2full,0x662509203233662eull,0x316625202c323032ull,
0x35316625202c3639ull,0x0a202f2f09203b37ull,0x3233662e6c756d09ull,0x2c33303266250920ull,
0x202c343831662520ull,0x09203b3934316625ull,0x646461090a202f2full,0x662509203233662eull,
0x316625202c343032ull,0x30326625202c3739ull,0x0a202f2f09203b33ull,0x3233662e64646109ull,
0x2c35303266250920ull,0x202c323032662520ull,0x09203b3430326625ull,0x646461090a202f2full,
0x662509203233662eull,0x326625202c363032ull,0x30326625202c3130ull,0x0a202f2f09203b35ull,
0x3233662e766f6d09ull,0x2c37303266250920ull,0x3066373334663020ull,0x092020203b303030ull,
0x090a353532202f2full,0x203233662e6c756dull,0x202c383032662509ull,0x25202c3630326625ull,
0x2f09203b37303266ull,0x2e747663090a202full,0x2e3233752e697a72ull,0x3172250920323366ull,
0x30326625202c3130ull,0x090a202f2f093b38ull,0x203233752e766f6dull,0x202c323031722509ull,
0x2020202020203b30ull,0x2f09202020202020ull,0x672e7473090a202full,0x34762e6c61626f6cull,
0x72255b092038752eull,0x7b202c5d302b3464ull,0x72252c3130317225ull,0x303172252c313031ull,
0x7d32303172252c31ull,0x4c240a202f2f093bull,0x090a3a355f315f74ull,0x09353109636f6c2eull,
0x65090a3009313931ull,0x202020203b746978ull,0x2020202020202020ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x6e6557444c240a20ull,0x5f6435315a5f5f64ull,0x69427265646e6572ull,
0x7536506369627563ull,0x666a6a3472616863ull,0x7d090a3a66666666ull,0x35315a5f202f2f20ull,
0x7265646e65725f64ull,0x5063696275636942ull,0x6a34726168637536ull,0x0a0a66666666666aull,
0x207972746e652e09ull,0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,
0x6a34726168637536ull,0x090a66666666666aull,0x206765722e090a7bull,0x3c7225203233752eull,
0x722e090a3b3e3534ull,0x203436752e206765ull,0x0a3b3e363c647225ull,0x662e206765722e09ull,
0x37313c6625203233ull,0x65722e090a3b3e31ull,0x20646572702e2067ull,0x090a3b3e373c7025ull,
0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x6e65725f6439315aull,
0x4274736146726564ull,0x3650636962756369ull,0x6a6a347261686375ull,0x5f645f6666666666ull,
0x0a3b74757074756full,0x206d617261702e09ull,0x635f5f203233752eull,0x5f6d726170616475ull,
0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,0x6a34726168637536ull,
0x775f66666666666aull,0x2e090a3b68746469ull,0x752e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x646e65725f643931ull,0x6942747361467265ull,0x7536506369627563ull,
0x666a6a3472616863ull,0x6965685f66666666ull,0x702e090a3b746867ull,0x33662e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x65646e65725f6439ull,0x6369427473614672ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x0a3b78745f666666ull,0x206d617261702e09ull,
0x635f5f203233662eull,0x5f6d726170616475ull,0x65725f6439315a5full,0x747361467265646eull,
0x5063696275636942ull,0x6a34726168637536ull,0x745f66666666666aull,0x7261702e090a3b79ull,
0x203233662e206d61ull,0x6170616475635f5full,0x6439315a5f5f6d72ull,0x467265646e65725full,
0x6275636942747361ull,0x6168637536506369ull,0x666666666a6a3472ull,0x3b656c6163735f66ull,
0x6d617261702e090aull,0x5f5f203233662e20ull,0x6d72617061647563ull,0x725f6439315a5f5full,
0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x61702e090a3b7863ull,0x3233662e206d6172ull,0x70616475635f5f20ull,0x39315a5f5f6d7261ull,
0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,0x6666666a6a347261ull,
0x090a3b79635f6666ull,0x09353109636f6c2eull,0x4c240a3009353931ull,0x39315a5f5f314242ull,
0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,0x6666666a6a347261ull,
0x747663090a3a6666ull,0x3631752e3233752eull,0x25202c3172250920ull,0x3b782e6469617463ull,
0x0a202f2f09202020ull,0x3233752e74766309ull,0x722509203631752eull,0x6469746e25202c32ull,
0x09202020203b782eull,0x6c756d090a202f2full,0x33752e6f6c2e3432ull,0x202c337225092032ull,
0x327225202c317225ull,0x0a202f2f0920203bull,0x3233752e74766309ull,0x722509203631752eull,
0x6961746325202c34ull,0x092020203b792e64ull,0x747663090a202f2full,0x3631752e3233752eull,
0x25202c3572250920ull,0x203b792e6469746eull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233752e6full,0x2c347225202c3672ull,0x0920203b35722520ull,0x747663090a202f2full,
0x3631752e3233752eull,0x25202c3772250920ull,0x20203b782e646974ull,0x0a202f2f09202020ull,
0x3233752e64646109ull,0x25202c3872250920ull,0x3b337225202c3772ull,0x0920202020202020ull,
0x747663090a202f2full,0x3631752e3233752eull,0x25202c3972250920ull,0x20203b792e646974ull,
0x0a202f2f09202020ull,0x3233752e64646109ull,0x202c303172250920ull,0x367225202c397225ull,
0x092020202020203bull,0x2e646c090a202f2full,0x33752e6d61726170ull,0x2c31317225092032ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x65646e65725f6439ull,0x6369427473614672ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x746469775f666666ull,0x69202f2f093b5d68ull,
0x5f5f203130343a64ull,0x6d72617061647563ull,0x725f6439315a5f5full,0x7361467265646e65ull,
0x6369627563694274ull,0x3472616863753650ull,0x5f66666666666a6aull,0x78302b6874646977ull,
0x61702e646c090a30ull,0x203233752e6d6172ull,0x5b202c3231722509ull,0x6170616475635f5full,
0x6439315a5f5f6d72ull,0x467265646e65725full,0x6275636942747361ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x7468676965685f66ull,0x6469202f2f093b5dull,0x635f5f203830343aull,
0x5f6d726170616475ull,0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,
0x6a34726168637536ull,0x685f66666666666aull,0x78302b7468676965ull,0x672e746573090a30ull,
0x33752e3233752e74ull,0x2c33317225092032ull,0x25202c3231722520ull,0x202f2f093b303172ull,
0x33732e67656e090aull,0x2c34317225092032ull,0x20203b3331722520ull,0x2020202020202020ull,
0x6573090a202f2f09ull,0x3233752e746c2e74ull,0x722509203233752eull,0x2c387225202c3531ull,
0x2f093b3131722520ull,0x2e67656e090a202full,0x3172250920323373ull,0x3b35317225202c36ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233622e646e61ull,0x25202c3731722509ull,
0x317225202c343172ull,0x2f09202020203b36ull,0x2e766f6d090a202full,0x3172250920323375ull,
0x2020203b30202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e71652e70746573ull,
0x3170250920323373ull,0x202c37317225202cull,0x2f09203b38317225ull,0x31702540090a202full,
0x4c24092061726220ull,0x203b37315f325f74ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x7663090a30093637ull,0x3233662e6e722e74ull,0x662509203233752eull,
0x203b387225202c31ull,0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233662e6d61ull,
0x5f5f5b202c326625ull,0x6d72617061647563ull,0x725f6439315a5f5full,0x7361467265646e65ull,
0x6369627563694274ull,0x3472616863753650ull,0x5f66666666666a6aull,0x202f2f093b5d7863ull,
0x5f203030343a6469ull,0x726170616475635full,0x5f6439315a5f5f6dull,0x61467265646e6572ull,
0x6962756369427473ull,0x7261686375365063ull,0x66666666666a6a34ull,0x0a3078302b78635full,
0x3233662e62757309ull,0x25202c3366250920ull,0x3b326625202c3166ull,0x0920202020202020ull,
0x2e646c090a202f2full,0x33662e6d61726170ull,0x202c346625092032ull,0x70616475635f5f5bull,
0x39315a5f5f6d7261ull,0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,
0x6666666a6a347261ull,0x656c6163735f6666ull,0x6469202f2f093b5dull,0x635f5f203939333aull,
0x5f6d726170616475ull,0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,
0x6a34726168637536ull,0x735f66666666666aull,0x3078302b656c6163ull,0x33662e6c756d090aull,
0x202c356625092032ull,0x346625202c336625ull,0x202020202020203bull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x2c356625202c3666ull,0x2020203b32662520ull,0x202f2f0920202020ull,
0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c376625ull,0x6d72617061647563ull,
0x725f6439315a5f5full,0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x202f2f093b5d7874ull,0x5f203930343a6469ull,0x726170616475635full,
0x5f6439315a5f5f6dull,0x61467265646e6572ull,0x6962756369427473ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x0a3078302b78745full,0x3233662e64646109ull,0x25202c3866250920ull,
0x3b366625202c3766ull,0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,
0x3066626630202c39ull,0x20203b3030303030ull,0x2d202f2f09202020ull,0x646461090a352e30ull,
0x662509203233662eull,0x2c386625202c3031ull,0x2020203b39662520ull,0x0a202f2f09202020ull,
0x696d722e74766309ull,0x3233662e3233662eull,0x202c313166250920ull,0x0920203b30316625ull,
0x627573090a202f2full,0x662509203233662eull,0x30316625202c3231ull,0x203b31316625202cull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c333166250920ull,0x3030303430346630ull,
0x09202020203b3030ull,0x756d090a33202f2full,0x2509203233662e6cull,0x316625202c343166ull,
0x3b33316625202c32ull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c35316625092032ull,
0x25202c3231662520ull,0x202020203b323166ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x636630202c363166ull,0x3b30303030306330ull,0x202f2f0920202020ull,0x2e646461090a362dull,
0x3166250920323366ull,0x2c34316625202c37ull,0x20203b3631662520ull,0x090a202f2f092020ull,
0x203233662e6c756dull,0x25202c3831662509ull,0x316625202c353166ull,0x2f09202020203b37ull,
0x2e766f6d090a202full,0x3166250920323366ull,0x3830346630202c39ull,0x20203b3030303030ull,
0x0a34202f2f092020ull,0x3233662e64646109ull,0x202c303266250920ull,0x6625202c38316625ull,
0x09202020203b3931ull,0x766f6d090a202f2full,0x662509203233662eull,0x65336630202c3132ull,
0x203b626161616132ull,0x30202f2f09202020ull,0x0a3736363636312eull,0x3233662e6c756d09ull,
0x202c323266250920ull,0x6625202c30326625ull,0x09202020203b3132ull,0x766f6d090a202f2full,
0x662509203233662eull,0x30346630202c3332ull,0x203b303030303034ull,0x33202f2f09202020ull,
0x33662e627573090aull,0x2c34326625092032ull,0x25202c3332662520ull,0x202020203b323166ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x316625202c353266ull,0x3b34326625202c32ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c36326625092032ull,0x3030343063663020ull,
0x202020203b303030ull,0x090a332d202f2f09ull,0x203233662e646461ull,0x25202c3732662509ull,
0x326625202c353266ull,0x2f09202020203b36ull,0x2e6c756d090a202full,0x3266250920323366ull,
0x2c32316625202c38ull,0x20203b3732662520ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x30202c3932662509ull,0x3030303038663366ull,0x2f09202020203b30ull,0x646461090a31202full,
0x662509203233662eull,0x38326625202c3033ull,0x203b39326625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c313366250920ull,0x6161613265336630ull,0x09202020203b6261ull,
0x3636312e30202f2full,0x6c756d090a373636ull,0x662509203233662eull,0x30336625202c3233ull,
0x203b31336625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c333366250920ull,
0x6625202c32336625ull,0x09202020203b3232ull,0x6f6c2e090a202f2full,0x0931380935310963ull,
0x662e6c756d090a30ull,0x3433662509203233ull,0x202c32316625202cull,0x2020203b35316625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c35336625ull,0x6261616161326533ull,
0x2f2f09202020203bull,0x36363636312e3020ull,0x662e6c756d090a37ull,0x3633662509203233ull,
0x202c34336625202cull,0x2020203b35336625ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c37336625ull,0x3030303030343063ull,0x2f2f09202020203bull,0x6c756d090a332d20ull,
0x662509203233662eull,0x32316625202c3833ull,0x203b37336625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c393366250920ull,0x3030303430346630ull,0x09202020203b3030ull,
0x6461090a33202f2full,0x2509203233662e64ull,0x336625202c303466ull,0x3b39336625202c38ull,
0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c31346625092032ull,0x25202c3231662520ull,
0x202020203b303466ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x346630202c323466ull,
0x3b30303030303430ull,0x202f2f0920202020ull,0x662e646461090a33ull,0x3334662509203233ull,
0x202c31346625202cull,0x2020203b32346625ull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x6625202c34346625ull,0x33346625202c3231ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,
0x3534662509203233ull,0x303866336630202cull,0x2020203b30303030ull,0x090a31202f2f0920ull,
0x203233662e646461ull,0x25202c3634662509ull,0x346625202c343466ull,0x2f09202020203b35ull,
0x2e766f6d090a202full,0x3466250920323366ull,0x3265336630202c37ull,0x20203b6261616161ull,
0x2e30202f2f092020ull,0x090a373636363631ull,0x203233662e6c756dull,0x25202c3834662509ull,
0x346625202c363466ull,0x2f09202020203b37ull,0x2e646461090a202full,0x3466250920323366ull,
0x2c38346625202c39ull,0x20203b3633662520ull,0x090a202f2f092020ull,0x09393109636f6c2eull,
0x090a300938323331ull,0x203233662e766f6dull,0x25202c3035662509ull,0x202020203b323266ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3566250920323366ull,0x3b33336625202c31ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09393109636f6c2eull,0x090a300930353231ull,
0x203233662e736261ull,0x25202c3235662509ull,0x202020203b333366ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3566250920323366ull,0x3865376630202c33ull,0x20203b3030303030ull,
0x2e38202f2f092020ull,0x332b653630373035ull,0x2e70746573090a37ull,0x09203233662e7467ull,
0x356625202c327025ull,0x3b33356625202c32ull,0x40090a202f2f0920ull,0x6172622032702521ull,
0x5f325f744c240920ull,0x20202020203b3931ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x0931353231093931ull,0x662e766f6d090a30ull,0x3435662509203233ull,0x303865336630202cull,
0x2020203b30303030ull,0x322e30202f2f0920ull,0x662e6c756d090a35ull,0x3035662509203233ull,
0x202c32326625202cull,0x2020203b34356625ull,0x2e090a202f2f0920ull,0x3109393109636f6cull,
0x6d090a3009323532ull,0x09203233662e766full,0x6630202c35356625ull,0x3030303030386533ull,
0x2f2f09202020203bull,0x6d090a35322e3020ull,0x09203233662e6c75ull,0x6625202c31356625ull,
0x35356625202c3333ull,0x2f2f09202020203bull,0x5f325f744c240a20ull,0x6f6c2e090a3a3931ull,
0x3434310935310963ull,0x2e766964090a3009ull,0x3566250920323366ull,0x2c30356625202c36ull,
0x20203b3135662520ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3735662509ull,
0x3030303038666266ull,0x2f09202020203b30ull,0x6461090a312d202full,0x2509203233662e64ull,
0x356625202c383566ull,0x3b37356625202c36ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c39356625092032ull,0x3030306633663020ull,0x202020203b303030ull,0x0a352e30202f2f09ull,
0x3233662e64646109ull,0x202c303666250920ull,0x6625202c38356625ull,0x09202020203b3935ull,
0x6f6c2e090a202f2full,0x3233310939310963ull,0x766f6d090a300938ull,0x662509203233662eull,
0x36336625202c3136ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c323666250920ull,0x2020203b39346625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3532310939310963ull,0x736261090a300930ull,0x662509203233662eull,0x39346625202c3336ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c343666250920ull,
0x3030303865376630ull,0x09202020203b3030ull,0x3730352e38202f2full,0x090a37332b653630ull,
0x2e74672e70746573ull,0x3370250920323366ull,0x202c33366625202cull,0x2f09203b34366625ull,
0x70252140090a202full,0x2409206172622033ull,0x3b31325f325f744cull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09393109636f6c2eull,0x090a300931353231ull,0x203233662e766f6dull,
0x30202c3536662509ull,0x3030303038653366ull,0x2f09202020203b30ull,0x090a35322e30202full,
0x203233662e6c756dull,0x25202c3136662509ull,0x366625202c363366ull,0x2f09202020203b35ull,
0x636f6c2e090a202full,0x3235323109393109ull,0x2e766f6d090a3009ull,0x3666250920323366ull,
0x3865336630202c36ull,0x20203b3030303030ull,0x2e30202f2f092020ull,0x2e6c756d090a3532ull,
0x3666250920323366ull,0x2c39346625202c32ull,0x20203b3636662520ull,0x240a202f2f092020ull,
0x3a31325f325f744cull,0x3109636f6c2e090aull,0x0a30093534310935ull,0x3233662e76696409ull,
0x202c373666250920ull,0x6625202c31366625ull,0x09202020203b3236ull,0x766f6d090a202f2full,
0x662509203233662eull,0x66336630202c3836ull,0x203b303030303038ull,0x31202f2f09202020ull,
0x33662e646461090aull,0x2c39366625092032ull,0x25202c3736662520ull,0x202020203b383666ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x336630202c303766ull,0x3b30303030303066ull,
0x202f2f0920202020ull,0x646461090a352e30ull,0x662509203233662eull,0x39366625202c3137ull,
0x203b30376625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x63090a3009383809ull,
0x33662e6e722e7476ull,0x2509203233752e32ull,0x317225202c323766ull,0x2f2f092020203b30ull,
0x61702e646c090a20ull,0x203233662e6d6172ull,0x5b202c3337662509ull,0x6170616475635f5full,
0x6439315a5f5f6d72ull,0x467265646e65725full,0x6275636942747361ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x2f093b5d79635f66ull,0x3839333a6469202full,0x70616475635f5f20ull,
0x39315a5f5f6d7261ull,0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,
0x6666666a6a347261ull,0x78302b79635f6666ull,0x662e627573090a30ull,0x3437662509203233ull,
0x202c32376625202cull,0x2020203b33376625ull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x6625202c35376625ull,0x3b346625202c3437ull,0x2f2f092020202020ull,0x662e646461090a20ull,
0x3637662509203233ull,0x202c35376625202cull,0x2020203b33376625ull,0x6c090a202f2f0920ull,
0x2e6d617261702e64ull,0x3766250920323366ull,0x75635f5f5b202c37ull,0x5f5f6d7261706164ull,
0x6e65725f6439315aull,0x4274736146726564ull,0x3650636962756369ull,0x6a6a347261686375ull,
0x79745f6666666666ull,0x6469202f2f093b5dull,0x635f5f203031343aull,0x5f6d726170616475ull,
0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,0x6a34726168637536ull,
0x745f66666666666aull,0x61090a3078302b79ull,0x09203233662e6464ull,0x6625202c38376625ull,
0x36376625202c3737ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3937662509203233ull,
0x303066626630202cull,0x2020203b30303030ull,0x2e302d202f2f0920ull,0x662e646461090a35ull,
0x3038662509203233ull,0x202c38376625202cull,0x2020203b39376625ull,0x63090a202f2f0920ull,
0x662e696d722e7476ull,0x09203233662e3233ull,0x6625202c31386625ull,0x2f2f0920203b3038ull,
0x662e627573090a20ull,0x3238662509203233ull,0x202c30386625202cull,0x2020203b31386625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c33386625ull,0x3030303030343034ull,
0x2f2f09202020203bull,0x2e6c756d090a3320ull,0x3866250920323366ull,0x2c32386625202c34ull,
0x20203b3338662520ull,0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3538662509ull,
0x386625202c323866ull,0x2f09202020203b32ull,0x2e766f6d090a202full,0x3866250920323366ull,
0x6330636630202c36ull,0x20203b3030303030ull,0x362d202f2f092020ull,0x33662e646461090aull,
0x2c37386625092032ull,0x25202c3438662520ull,0x202020203b363866ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x386625202c383866ull,0x3b37386625202c35ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c39386625092032ull,0x3030383034663020ull,0x202020203b303030ull,
0x61090a34202f2f09ull,0x09203233662e6464ull,0x6625202c30396625ull,0x39386625202c3838ull,
0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3139662509203233ull,0x613265336630202cull,
0x2020203b62616161ull,0x312e30202f2f0920ull,0x6d090a3736363636ull,0x09203233662e6c75ull,
0x6625202c32396625ull,0x31396625202c3039ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,
0x3339662509203233ull,0x303430346630202cull,0x2020203b30303030ull,0x090a33202f2f0920ull,
0x203233662e627573ull,0x25202c3439662509ull,0x386625202c333966ull,0x2f09202020203b32ull,
0x2e6c756d090a202full,0x3966250920323366ull,0x2c32386625202c35ull,0x20203b3439662520ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3639662509ull,0x3030303034306366ull,
0x2f09202020203b30ull,0x6461090a332d202full,0x2509203233662e64ull,0x396625202c373966ull,
0x3b36396625202c35ull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c38396625092032ull,
0x25202c3238662520ull,0x202020203b373966ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x336630202c393966ull,0x3b30303030303866ull,0x202f2f0920202020ull,0x662e646461090a31ull,
0x3031662509203233ull,0x2c38396625202c30ull,0x20203b3939662520ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3130316625ull,0x6161616132653366ull,0x2f2f092020203b62ull,
0x36363636312e3020ull,0x662e6c756d090a37ull,0x3031662509203233ull,0x3030316625202c32ull,
0x3b3130316625202cull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3330316625ull,
0x6625202c32303166ull,0x2f2f0920203b3239ull,0x09636f6c2e090a20ull,0x0938323331093931ull,
0x662e766f6d090a30ull,0x3035662509203233ull,0x203b32396625202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c31356625ull,0x202020203b333031ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x0930353231093931ull,0x662e736261090a30ull,
0x3031662509203233ull,0x3330316625202c34ull,0x202020202020203bull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3530316625ull,0x3030303038653766ull,0x2f2f092020203b30ull,
0x36303730352e3820ull,0x6573090a37332b65ull,0x33662e74672e7074ull,0x202c347025092032ull,
0x25202c3430316625ull,0x2f2f093b35303166ull,0x3470252140090a20ull,0x4c24092061726220ull,
0x203b33325f325f74ull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3109393109636f6cull,
0x6d090a3009313532ull,0x09203233662e766full,0x30202c3630316625ull,0x3030303038653366ull,
0x2f2f092020203b30ull,0x6d090a35322e3020ull,0x09203233662e6c75ull,0x6625202c30356625ull,
0x30316625202c3239ull,0x2f2f092020203b36ull,0x09636f6c2e090a20ull,0x0932353231093931ull,
0x662e766f6d090a30ull,0x3031662509203233ull,0x3865336630202c37ull,0x20203b3030303030ull,
0x322e30202f2f0920ull,0x662e6c756d090a35ull,0x3135662509203233ull,0x2c3330316625202cull,
0x203b373031662520ull,0x4c240a202f2f0920ull,0x0a3a33325f325f74ull,0x353109636f6c2e09ull,
0x6d090a3009333909ull,0x09203233662e6c75ull,0x25202c3830316625ull,0x386625202c323866ull,
0x2f2f092020203b35ull,0x662e766f6d090a20ull,0x3031662509203233ull,0x3265336630202c39ull,
0x20203b6261616161ull,0x312e30202f2f0920ull,0x6d090a3736363636ull,0x09203233662e6c75ull,
0x25202c3031316625ull,0x6625202c38303166ull,0x2f2f09203b393031ull,0x662e766f6d090a20ull,
0x3131662509203233ull,0x3430636630202c31ull,0x20203b3030303030ull,0x0a332d202f2f0920ull,
0x3233662e6c756d09ull,0x2c32313166250920ull,0x25202c3238662520ull,0x0920203b31313166ull,
0x766f6d090a202f2full,0x662509203233662eull,0x346630202c333131ull,0x3b30303030303430ull,
0x33202f2f09202020ull,0x33662e646461090aull,0x3431316625092032ull,0x2c3231316625202cull,
0x203b333131662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c35313166ull,
0x31316625202c3238ull,0x202f2f0920203b34ull,0x33662e766f6d090aull,0x3631316625092032ull,
0x303430346630202cull,0x2020203b30303030ull,0x61090a33202f2f09ull,0x09203233662e6464ull,
0x25202c3731316625ull,0x6625202c35313166ull,0x2f2f09203b363131ull,0x662e6c756d090a20ull,
0x3131662509203233ull,0x2c32386625202c38ull,0x203b373131662520ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3931316625ull,0x3030303038663366ull,0x2f2f092020203b30ull,
0x2e646461090a3120ull,0x3166250920323366ull,0x31316625202c3032ull,0x3931316625202c38ull,
0x090a202f2f09203bull,0x203233662e766f6dull,0x202c313231662509ull,0x6161613265336630ull,
0x2f092020203b6261ull,0x363636312e30202full,0x2e6c756d090a3736ull,0x3166250920323366ull,
0x32316625202c3232ull,0x3132316625202c30ull,0x090a202f2f09203bull,0x203233662e646461ull,
0x202c333231662509ull,0x25202c3232316625ull,0x2f09203b30313166ull,0x636f6c2e090a202full,
0x3832333109393109ull,0x2e766f6d090a3009ull,0x3666250920323366ull,0x3031316625202c31ull,
0x202020202020203bull,0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3236662509ull,
0x2020203b33323166ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x3035323109393109ull,
0x2e736261090a3009ull,0x3166250920323366ull,0x32316625202c3432ull,0x2020202020203b33ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x202c353231662509ull,0x3030303865376630ull,
0x2f092020203b3030ull,0x303730352e38202full,0x73090a37332b6536ull,0x662e74672e707465ull,
0x2c35702509203233ull,0x202c343231662520ull,0x2f093b3532316625ull,0x70252140090a202full,
0x2409206172622035ull,0x3b35325f325f744cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09393109636f6c2eull,0x090a300931353231ull,0x203233662e766f6dull,0x202c363231662509ull,
0x3030303865336630ull,0x2f092020203b3030ull,0x090a35322e30202full,0x203233662e6c756dull,
0x25202c3136662509ull,0x6625202c30313166ull,0x2f0920203b363231ull,0x636f6c2e090a202full,
0x3235323109393109ull,0x2e766f6d090a3009ull,0x3166250920323366ull,0x65336630202c3732ull,
0x203b303030303038ull,0x2e30202f2f092020ull,0x2e6c756d090a3532ull,0x3666250920323366ull,
0x3332316625202c32ull,0x3b3732316625202cull,0x240a202f2f092020ull,0x3a35325f325f744cull,
0x3109636f6c2e090aull,0x0a30093734310935ull,0x3233662e76696409ull,0x2c38323166250920ull,
0x25202c3035662520ull,0x092020203b313566ull,0x766f6d090a202f2full,0x662509203233662eull,
0x626630202c393231ull,0x3b30303030303866ull,0x2d202f2f09202020ull,0x662e646461090a31ull,
0x3331662509203233ull,0x3832316625202c30ull,0x3b3932316625202cull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x25202c3133316625ull,0x366625202c313166ull,0x2f2f092020203b30ull,
0x662e766f6d090a20ull,0x3331662509203233ull,0x3066336630202c32ull,0x20203b3030303030ull,
0x352e30202f2f0920ull,0x33662e646461090aull,0x3333316625092032ull,0x2c3033316625202cull,
0x203b323331662520ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c34333166ull,
0x33316625202c3138ull,0x202f2f0920203b33ull,0x33662e766f6d090aull,0x3533316625092032ull,
0x3b3133316625202cull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x6625202c36333166ull,0x202020203b343331ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x3733316625092032ull,0x303030306630202cull,0x2020203b30303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x30202c3833316625ull,0x3030303030303066ull,0x2f2f092020203b30ull,
0x2e786574090a3020ull,0x33752e34762e6432ull,0x257b203233662e32ull,0x303272252c393172ull,
0x72252c313272252cull,0x7865745b2c7d3232ull,0x2c35333166257b2cull,0x66252c3633316625ull,
0x333166252c373331ull,0x6c2e090a3b5d7d38ull,0x343109353109636full,0x766f6d090a300939ull,
0x722509203233732eull,0x39317225202c3332ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x2c39333166250920ull,0x25202c3131662520ull,0x092020203b313766ull,
0x766f6d090a202f2full,0x662509203233662eull,0x316625202c303431ull,0x20202020203b3933ull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x2c31343166250920ull,0x203b343331662520ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x306630202c323431ull,
0x3b30303030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,0x3334316625092032ull,
0x303030306630202cull,0x2020203b30303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,
0x3233662e3233752eull,0x252c343272257b20ull,0x363272252c353272ull,0x5b2c7d373272252cull,
0x3166257b2c786574ull,0x31343166252c3034ull,0x252c32343166252cull,0x0a3b5d7d33343166ull,
0x3233732e766f6d09ull,0x202c383272250920ull,0x2020203b34327225ull,0x0920202020202020ull,
0x766964090a202f2full,0x662509203233662eull,0x366625202c343431ull,0x3b32366625202c31ull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x2c35343166250920ull,0x3030386633663020ull,
0x092020203b303030ull,0x6461090a31202f2full,0x2509203233662e64ull,0x6625202c36343166ull,
0x316625202c343431ull,0x202f2f09203b3534ull,0x33662e766f6d090aull,0x3734316625092032ull,
0x303066336630202cull,0x2020203b30303030ull,0x0a352e30202f2f09ull,0x3233662e64646109ull,
0x2c38343166250920ull,0x202c363431662520ull,0x09203b3734316625ull,0x646461090a202f2full,
0x662509203233662eull,0x386625202c393431ull,0x3834316625202c31ull,0x0a202f2f0920203bull,
0x3233662e766f6d09ull,0x2c30353166250920ull,0x203b313331662520ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x316625202c313531ull,0x20202020203b3934ull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x2c32353166250920ull,0x3030303030663020ull,
0x092020203b303030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x6630202c33353166ull,
0x3030303030303030ull,0x202f2f092020203bull,0x322e786574090a30ull,0x3233752e34762e64ull,
0x72257b203233662eull,0x2c303372252c3932ull,0x3372252c31337225ull,0x2c7865745b2c7d32ull,
0x252c30353166257bull,0x3166252c31353166ull,0x33353166252c3235ull,0x766f6d090a3b5d7dull,
0x722509203233732eull,0x39327225202c3333ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x2c34353166250920ull,0x203b393331662520ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x316625202c353531ull,0x20202020203b3934ull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x2c36353166250920ull,0x3030303030663020ull,
0x092020203b303030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x6630202c37353166ull,
0x3030303030303030ull,0x202f2f092020203bull,0x322e786574090a30ull,0x3233752e34762e64ull,
0x72257b203233662eull,0x2c353372252c3433ull,0x3372252c36337225ull,0x2c7865745b2c7d37ull,
0x252c34353166257bull,0x3166252c35353166ull,0x37353166252c3635ull,0x766f6d090a3b5d7dull,
0x722509203233732eull,0x34337225202c3833ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233622e766f6d09ull,0x2c38353166250920ull,0x20203b3332722520ull,0x0920202020202020ull,
0x6c756d090a202f2full,0x662509203233662eull,0x336625202c393531ull,0x3835316625202c33ull,
0x0a202f2f0920203bull,0x3233622e766f6d09ull,0x2c30363166250920ull,0x20203b3832722520ull,
0x0920202020202020ull,0x64616d090a202f2full,0x662509203233662eull,0x346625202c313631ull,
0x3036316625202c39ull,0x3b3935316625202cull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c32363166ull,0x316625202c333031ull,0x202f2f09203b3136ull,0x33622e766f6d090aull,
0x3336316625092032ull,0x203b33337225202cull,0x2020202020202020ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c34363166ull,0x36316625202c3333ull,0x202f2f0920203b33ull,
0x33622e766f6d090aull,0x3536316625092032ull,0x203b38337225202cull,0x2020202020202020ull,
0x616d090a202f2f09ull,0x2509203233662e64ull,0x6625202c36363166ull,0x36316625202c3934ull,
0x3436316625202c35ull,0x6d090a202f2f093bull,0x09203233662e6461ull,0x25202c3736316625ull,
0x6625202c33323166ull,0x316625202c363631ull,0x0a202f2f093b3236ull,0x353109636f6c2e09ull,
0x090a300937303209ull,0x203233662e766f6dull,0x202c383631662509ull,0x3030663733346630ull,
0x2f092020203b3030ull,0x6d090a353532202full,0x09203233662e6c75ull,0x25202c3936316625ull,
0x6625202c37363166ull,0x2f2f09203b383631ull,0x722e747663090a20ull,0x662e3233752e697aull,
0x3933722509203233ull,0x3b3936316625202cull,0x6d090a202f2f0920ull,0x2e6f6c2e34326c75ull,
0x3472250920323375ull,0x2c30317225202c30ull,0x2f093b3131722520ull,0x2e766f6d090a202full,
0x3472250920323373ull,0x3b39337225202c31ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3164ull,0x5f6d726170616475ull,
0x65725f6439315a5full,0x747361467265646eull,0x5063696275636942ull,0x6a34726168637536ull,
0x645f66666666666aull,0x5d74757074756f5full,0x3a6469202f2f093bull,0x75635f5f20313134ull,
0x5f5f6d7261706164ull,0x6e65725f6439315aull,0x4274736146726564ull,0x3650636962756369ull,
0x6a6a347261686375ull,0x5f645f6666666666ull,0x302b74757074756full,0x2e646461090a3078ull,
0x3472250920323375ull,0x202c387225202c32ull,0x2020203b30347225ull,0x090a202f2f092020ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x3b32347225202c32ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c33647225ull,0x20203b34202c3264ull,
0x090a202f2f092020ull,0x203436752e646461ull,0x25202c3464722509ull,0x647225202c316472ull,
0x2f09202020203b33ull,0x2e766f6d090a202full,0x3472250920323375ull,0x2020203b30202c33ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x61626f6c672e7473ull,0x2038752e34762e6cull,
0x302b346472255b09ull,0x313472257b202c5dull,0x72252c313472252cull,0x7d333472252c3134ull,
0x4c240a202f2f093bull,0x0a3a37315f325f74ull,0x353109636f6c2e09ull,0x090a300939303209ull,
0x2020203b74697865ull,0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,
0x6557444c240a202full,0x6439315a5f5f646eull,0x467265646e65725full,0x6275636942747361ull,
0x6168637536506369ull,0x666666666a6a3472ull,0x2f2f207d090a3a66ull,0x725f6439315a5f20ull,
0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,0x0a66666666666a6aull,
0x000000000000000aull
};


}



extern "C" {


static const unsigned long long __deviceText_$sm_10$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d30315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x6c706d61730a7d6eull,
0x616e090a7b207265ull,0x203d20202020656dull,0x786574090a786574ull,0x30203d2074696e75ull,
0x2065646f630a7d0aull,0x20656d616e090a7bull,0x725f64385a5f203dull,0x7536507265646e65ull,
0x666a6a3472616863ull,0x6d6c090a66666666ull,0x090a30203d206d65ull,0x35203d206d656d73ull,
0x2020676572090a32ull,0x726162090a36203dull,0x63090a30203d2020ull,0x090a7b2074736e6full,
0x6d616e6765730909ull,0x736e6f63203d2065ull,0x6765730909090a74ull,0x31203d20206d756eull,
0x7366666f0909090aull,0x0a30203d20207465ull,0x7365747962090909ull,0x090a34203d202020ull,
0x090a7b206d656d09ull,0x3030303078300909ull,0x09090a2066663330ull,0x6962090a7d090a7dull,
0x0a7b2065646f636eull,0x3038306478300909ull,0x3078302035303230ull,0x2030383730303430ull,
0x6534303030617830ull,0x3234307830203930ull,0x090a203038373030ull,0x3430303061783009ull,
0x3430783020313134ull,0x3020303837303032ull,0x3132303030306178ull,0x3030343078302035ull,
0x09090a2030383730ull,0x6334303030617830ull,0x3234307830203530ull,0x7830203038373030ull,
0x6430323430303061ull,0x3030323430783020ull,0x3009090a20303837ull,0x3030303030306178ull,
0x3030343078302031ull,0x3678302030383730ull,0x2039303430343030ull,0x3734313030367830ull,
0x783009090a203038ull,0x6430323033303036ull,0x3030303036783020ull,0x3033783020303837ull,
0x3020646666633230ull,0x6337303132343678ull,0x33783009090a2038ull,0x2064666463333030ull,
0x3230313234367830ull,0x3030337830203863ull,0x7830203330303030ull,0x3030313030303030ull,
0x3061783009090a20ull,0x3020313136303030ull,0x3837343030343478ull,0x3030306178302030ull,
0x3478302035313430ull,0x2030383734303034ull,0x303131783009090aull,0x7830203030366630ull,
0x3430386630303131ull,0x6634303162783020ull,0x3162783020303136ull,0x0a20343138663530ull,
0x3430306578300909ull,0x3078302031303464ull,0x2030383730303230ull,0x3464353030657830ull,
0x3230307830203530ull,0x090a203038373430ull,0x3730303162783009ull,0x3162783020303030ull,
0x3020343032373130ull,0x3063633230303678ull,0x3032303678302039ull,0x09090a2030383763ull,
0x3030303432667830ull,0x3030307830203130ull,0x7830203438373030ull,0x3130303030303063ull,
0x6637333430783020ull,0x3009090a20333030ull,0x3030303030306178ull,0x3630343878302064ull,
0x3378302030383734ull,0x2035303430323030ull,0x3730303134637830ull,0x783009090a203038ull,
0x3130363030303061ull,0x6330303030783020ull,0x3033783020303837ull,0x3020353063303830ull,
0x3837303031306378ull,0x32783009090a2030ull,0x2039303863303030ull,0x3734303234307830ull,
0x3030647830203038ull,0x7830203930303031ull,0x3038373430303030ull,0x3031783009090a20ull,
0x3020643030303030ull,0x3837633330303078ull,0x6530306478302030ull,0x6178302035303430ull,
0x2031383730306330ull,0x6f630a7d0a7d090aull,0x616e090a7b206564ull,0x315a5f203d20656dull,
0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,0x66666a6a34726168ull,
0x656d6c090a666666ull,0x73090a30203d206dull,0x3235203d206d656dull,0x3d2020676572090aull,
0x726162090a353120ull,0x63090a30203d2020ull,0x090a7b2074736e6full,0x6d616e6765730909ull,
0x736e6f63203d2065ull,0x6765730909090a74ull,0x31203d20206d756eull,0x7366666f0909090aull,
0x0a30203d20207465ull,0x7365747962090909ull,0x0a3633203d202020ull,0x0a7b206d656d0909ull,
0x3030307830090909ull,0x7830206666333030ull,0x3030303030343034ull,0x3030383034783020ull,
0x3063783020303030ull,0x0a20303030303034ull,0x3866337830090909ull,0x7830203030303030ull,
0x6261616161326533ull,0x3030386537783020ull,0x6662783020303030ull,0x0a20303030303038ull,
0x3865337830090909ull,0x090a203030303030ull,0x62090a7d090a7d09ull,0x7b2065646f636e69ull,
0x383064783009090aull,0x7830203530323030ull,0x3038373030343030ull,0x3430303061783020ull,
0x3430783020643065ull,0x0a20303837303032ull,0x3030306178300909ull,0x3078302031313434ull,
0x2030383730303234ull,0x3230303030617830ull,0x3034307830203531ull,0x090a203038373030ull,
0x3430303061783009ull,0x3430783020353063ull,0x3020303837303032ull,0x3032343030306178ull,
0x3032343078302039ull,0x09090a2030383730ull,0x3030303030617830ull,0x3034307830203130ull,
0x7830203038373030ull,0x6431363034303036ull,0x3431303036783020ull,0x3009090a20303837ull,
0x3132303230303678ull,0x3030303678302039ull,0x3378302030383730ull,0x2064666663373030ull,
0x3730313234367830ull,0x783009090a203863ull,0x6466646336303033ull,0x3031323436783020ull,
0x3033783020386332ull,0x3020333030303030ull,0x3031303030303078ull,0x61783009090a2030ull,
0x2035306330303030ull,0x3734303034347830ull,0x3031317830203038ull,0x7830203030366630ull,
0x3430366631303162ull,0x3065783009090a20ull,0x3020313034643130ull,0x3837303032303078ull,
0x3030306278302030ull,0x3078302031303064ull,0x2030383730303230ull,0x303062783009090aull,
0x7830203130303030ull,0x3330303030666230ull,0x3030303061783020ull,0x6363783020313330ull,
0x0a20303837343230ull,0x3030306278300909ull,0x3078302039303831ull,0x2030383730303034ull,
0x3038303030317830ull,0x3063307830203130ull,0x090a203330303063ull,0x3830303031783009ull,
0x6330783020353030ull,0x3020333030303430ull,0x3034303230306378ull,0x3030303078302064ull,
0x09090a2030383730ull,0x3430303030657830ull,0x3034307830203130ull,0x7830203330303034ull,
0x3131343830303062ull,0x3034303430783020ull,0x3009090a20333030ull,0x3034303034306578ull,
0x3430633078302035ull,0x6578302033303030ull,0x2031303630303031ull,0x3738303430307830ull,
0x783009090a203038ull,0x3131343034303165ull,0x6330343030783020ull,0x3165783020303837ull,
0x3020353134303130ull,0x3837343034303078ull,0x63783009090a2030ull,0x2031303030623230ull,
0x6161326533307830ull,0x3031657830206261ull,0x7830203530343034ull,0x3038373031343030ull,
0x3063783009090a20ull,0x3020643036303230ull,0x3837303030303078ull,0x3530316578302030ull,
0x3078302031313430ull,0x2030383730313430ull,0x383065783009090aull,0x7830203930323035ull,
0x3038373030343030ull,0x3062323063783020ull,0x3330783020353036ull,0x0a20626161613265ull,
0x3638306278300909ull,0x3678302064663530ull,0x2038633730313530ull,0x3830353830657830ull,
0x3430307830203532ull,0x090a203038373430ull,0x3030303031783009ull,0x3430783020313234ull,
0x3020303837633330ull,0x3030303838306378ull,0x3034303078302031ull,0x09090a2030383630ull,
0x3031383830637830ull,0x3430307830203930ull,0x7830203038363030ull,0x3930343030303039ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030303230316578ull,0x3134303078302064ull,
0x6278302030383763ull,0x2064663331363830ull,0x3730313530367830ull,0x783009090a203863ull,
0x3030323830303031ull,0x3930303031783020ull,0x3062783020383032ull,0x3020393336303030ull,
0x3030303066333078ull,0x63783009090a2033ull,0x2031303230383830ull,0x3630303430307830ull,
0x3830637830203038ull,0x7830203930323138ull,0x3038363030343030ull,0x3061783009090a20ull,
0x3020643065303030ull,0x3837343030343478ull,0x3030313178302030ull,0x6278302034303866ull,
0x2063303866333031ull,0x303065783009090aull,0x7830203530346433ull,0x3038373430323030ull,
0x6430303062783020ull,0x3030783020353032ull,0x0a20303837343032ull,0x3030306278300909ull,
0x3078302035303230ull,0x2033303030306662ull,0x3230303030617830ull,0x3063637830203533ull,
0x090a203038373432ull,0x3130303062783009ull,0x3430783020313161ull,0x3020303837343030ull,
0x3030383030303178ull,0x6330633078302035ull,0x09090a2033303030ull,0x3830343030637830ull,
0x3030307830203531ull,0x7830203038373030ull,0x3530383030303065ull,0x3034303430783020ull,
0x3009090a20333030ull,0x3038383030306278ull,0x3430343078302064ull,0x6578302033303030ull,
0x2035306130313031ull,0x3738303430307830ull,0x783009090a203038ull,0x6430383033303165ull,
0x6330343030783020ull,0x3063783020303837ull,0x3020353032306232ull,0x6161613265333078ull,
0x65783009090a2062ull,0x2064303830333031ull,0x3730313430307830ull,0x3030397830203038ull,
0x7830203930343030ull,0x3038373030303030ull,0x3065783009090a20ull,0x3020643036303538ull,
0x3837343034303078ull,0x3230316578302030ull,0x3078302031303030ull,0x2030383730313430ull,
0x383062783009090aull,0x7830206466373036ull,0x3863373031353036ull,0x3030303062783020ull,
0x3330783020313030ull,0x0a20333030303066ull,0x3030303178300909ull,0x3078302039323630ull,
0x2030383763333034ull,0x3230383830637830ull,0x3430307830203530ull,0x090a203038363030ull,
0x3138383063783009ull,0x3030783020643034ull,0x3020303836303034ull,0x3138303530306378ull,
0x3030303078302035ull,0x09090a2030383730ull,0x3038303030317830ull,0x3063307830203930ull,
0x7830203330303034ull,0x3930383030343065ull,0x3034306330783020ull,0x3009090a20333030ull,
0x3038303230316578ull,0x3034303078302039ull,0x6578302030383734ull,0x2039303830323031ull,
0x3730313430307830ull,0x783009090a203038ull,0x3131613062323063ull,0x6132653330783020ull,
0x3065783020626161ull,0x3020353134303538ull,0x3837303134303078ull,0x62783009090a2030ull,
0x2064666230363830ull,0x3730313530367830ull,0x3030317830203863ull,0x7830206432613030ull,
0x3038376333303430ull,0x3063783009090a20ull,0x3020313138303838ull,0x3836303034303078ull,
0x3838306378302030ull,0x3078302035313631ull,0x2030383630303430ull,0x303062783009090aull,
0x7830203830383165ull,0x3030383130303062ull,0x3030303039783020ull,0x3039783020633036ull,
0x0a20343161303030ull,0x3330316578300909ull,0x3078302035303230ull,0x2030383763313430ull,
0x3830353031657830ull,0x3430307830206430ull,0x090a203038373031ull,0x3030303062783009ull,
0x3330783020353032ull,0x3020333030303066ull,0x3036303030306278ull,0x3066333078302064ull,
0x09090a2033303030ull,0x6363373030367830ull,0x3230367830203133ull,0x7830203038373831ull,
0x3430613131303062ull,0x3133303062783020ull,0x3009090a20343361ull,0x3134383030303178ull,
0x3030303178302038ull,0x3178302030313038ull,0x2063313238303030ull,0x3238303030317830ull,
0x783009090a203431ull,0x6330613930303031ull,0x3930303031783020ull,0x3266783020343061ull,
0x3020393130303034ull,0x3837303030303078ull,0x66783009090a2034ull,0x2039303030303432ull,
0x3730303030307830ull,0x3432667830203438ull,0x7830203131303030ull,0x3438373030303030ull,
0x3266783009090a20ull,0x3020313030303034ull,0x3837303030303078ull,0x3630306378302034ull,
0x3078302039313031ull,0x2030383730303030ull,0x303065783009090aull,0x7830203131323134ull,
0x3038373831303030ull,0x3132303063783020ull,0x3063783020383030ull,0x0a20343034313430ull,
0x3030306578300909ull,0x3078302031303231ull,0x2030383738303030ull,0x3631303030657830ull,
0x3030307830203130ull,0x090a203038373430ull,0x3030303063783009ull,0x3430783020313030ull,
0x3020333030663733ull,0x3030303030306178ull,0x3630343878302039ull,0x09090a2030383734ull,
0x3831323030337830ull,0x3134637830203530ull,0x7830203038373030ull,0x3130343030303061ull,
0x6330303030783020ull,0x3009090a20303837ull,0x3038303830303378ull,0x3031306378302035ull,
0x3278302030383730ull,0x2039303863303030ull,0x3734303234307830ull,0x783009090a203038ull,
0x3930303031303064ull,0x3430303030783020ull,0x3031783020303837ull,0x3020643030303030ull,
0x3837633330303078ull,0x64783009090a2030ull,0x2035303430653030ull,0x3730306330617830ull,
0x7d0a7d090a203138ull,0x0a7b2065646f630aull,0x203d20656d616e09ull,0x65725f6435315a5full,
0x756369427265646eull,0x6863753650636962ull,0x6666666a6a347261ull,0x6d656d6c090a6666ull,
0x6d73090a30203d20ull,0x0a3235203d206d65ull,0x203d202067657209ull,0x20726162090a3132ull,
0x6f63090a30203d20ull,0x09090a7b2074736eull,0x656d616e67657309ull,0x74736e6f63203d20ull,
0x6e6765730909090aull,0x0a31203d20206d75ull,0x657366666f090909ull,0x090a30203d202074ull,
0x2073657479620909ull,0x090a3032203d2020ull,0x090a7b206d656d09ull,0x3030303078300909ull,
0x3478302066663330ull,0x2030303030303430ull,0x3030303830347830ull,0x3430637830203030ull,
0x090a203030303030ull,0x3038663378300909ull,0x09090a2030303030ull,0x6962090a7d090a7dull,
0x0a7b2065646f636eull,0x3038306478300909ull,0x3078302035303230ull,0x2030383730303430ull,
0x6534303030617830ull,0x3234307830206430ull,0x090a203038373030ull,0x3430303061783009ull,
0x3430783020313134ull,0x3020303837303032ull,0x3132303030306178ull,0x3030343078302035ull,
0x09090a2030383730ull,0x6334303030617830ull,0x3234307830203530ull,0x7830203038373030ull,
0x3930323430303061ull,0x3030323430783020ull,0x3009090a20303837ull,0x3030303030306178ull,
0x3030343078302031ull,0x3678302030383730ull,0x2031313630343030ull,0x3734313030367830ull,
0x783009090a203038ull,0x3930323032303036ull,0x3030303036783020ull,0x3033783020303837ull,
0x3020646666633430ull,0x6337303132343678ull,0x33783009090a2038ull,0x2064666463323030ull,
0x3230313234367830ull,0x3030337830203863ull,0x7830203330303030ull,0x3030313030303030ull,
0x3061783009090a20ull,0x3020353034303030ull,0x3837343030343478ull,0x3030306178302030ull,
0x3478302064303830ull,0x2030383734303034ull,0x303131783009090aull,0x7830203030366630ull,
0x3431366631303162ull,0x6630303131783020ull,0x3162783020343038ull,0x0a20633038663330ull,
0x3530306578300909ull,0x3078302031303464ull,0x2030383730303230ull,0x3464333030657830ull,
0x3230307830203530ull,0x090a203038373430ull,0x3730303162783009ull,0x3162783020303030ull,
0x3020343032373130ull,0x3130303030306278ull,0x3066623078302035ull,0x09090a2033303030ull,
0x3230303030627830ull,0x6662307830203934ull,0x7830203330303030ull,0x6430613030303061ull,
0x3432306363783020ull,0x3009090a20303837ull,0x3534323030306178ull,0x3230636378302031ull,
0x3678302030383734ull,0x2031346363343030ull,0x3738303230367830ull,0x783009090a203038ull,
0x3130363030303062ull,0x3038666230783020ull,0x3062783020333030ull,0x3020353361303030ull,
0x3837633030383078ull,0x62783009090a2030ull,0x2039303832303030ull,0x3030386662307830ull,
0x3030317830203330ull,0x7830203031363830ull,0x6332386130303031ull,0x3031783009090a20ull,
0x3020383136383030ull,0x3330383030303178ull,0x3030303178302038ull,0x3178302063333438ull,
0x2063313861303030ull,0x303031783009090aull,0x7830203832303830ull,0x3431343830303031ull,
0x3030343266783020ull,0x3030783020393330ull,0x0a20343837303030ull,0x3034326678300909ull,
0x3078302039323030ull,0x2034383730303030ull,0x3030303432667830ull,0x3030307830203131ull,
0x090a203438373030ull,0x3030343266783009ull,0x3030783020393130ull,0x3020343837303030ull,
0x3061393030306278ull,0x3430343078302035ull,0x09090a2033303030ull,0x3038303030317830ull,
0x3063307830203132ull,0x7830203330303063ull,0x3532613131303165ull,0x6330343030783020ull,
0x3009090a20303837ull,0x3361316430306378ull,0x3030303078302064ull,0x6578302030383730ull,
0x2035306131313830ull,0x3730323430307830ull,0x783009090a203038ull,0x3532613139303165ull,
0x3031343030783020ull,0x3165783020303837ull,0x3020353065313130ull,0x3837383034303078ull,
0x63783009090a2030ull,0x2031333231623230ull,0x6161326533307830ull,0x3230637830206261ull,
0x7830203532323062ull,0x6261616132653330ull,0x3063783009090a20ull,0x3020343038316530ull,
0x3238316130306378ull,0x3430306578302038ull,0x3078302035313231ull,0x2030383734303030ull,
0x303065783009090aull,0x7830203534323136ull,0x3038373832303030ull,0x3230303062783020ull,
0x3330783020313138ull,0x0a20333030303866ull,0x3030303178300909ull,0x3078302039313630ull,
0x2030383763333034ull,0x3832303030627830ull,0x3034307830206434ull,0x090a203330303030ull,
0x3830303031783009ull,0x3031783020383230ull,0x3020633238383030ull,0x3138383030303178ull,
0x3030303178302063ull,0x09090a2034303661ull,0x3030303432667830ull,0x3030307830203932ull,
0x7830203438373030ull,0x3931303030343266ull,0x3030303030783020ull,0x3009090a20343837ull,
0x3030303034326678ull,0x3030303078302031ull,0x6378302034383730ull,0x2039323831613030ull,
0x3730303030307830ull,0x783009090a203038ull,0x6432323136303065ull,0x3832303030783020ull,
0x3063783020303837ull,0x3020393238313030ull,0x3837303030303078ull,0x62783009090a2030ull,
0x2039333630303030ull,0x3030386633307830ull,0x3030317830203330ull,0x7830203831363830ull,
0x6331366130303031ull,0x3031783009090a20ull,0x3020303063393030ull,0x3034383030303178ull,
0x3034326678302034ull,0x3078302039313030ull,0x2034383730303030ull,0x343266783009090aull,
0x7830203130303030ull,0x3438373030303030ull,0x3136303065783020ull,0x3030783020313332ull,
0x0a20303837383230ull,0x3030303178300909ull,0x3078302035323038ull,0x2033303030343063ull,
0x6131333830657830ull,0x3438307830203530ull,0x090a203038373432ull,0x3131303165783009ull,
0x3030783020353061ull,0x3020303837343034ull,0x3061313130316578ull,0x3134303078302035ull,
0x09090a2030383730ull,0x3230623230637830ull,0x6533307830203932ull,0x7830206261616132ull,
0x6433613166303063ull,0x3030303030783020ull,0x3009090a20303837ull,0x3134313030306578ull,
0x3130303078302035ull,0x6278302030383734ull,0x2035333630303030ull,0x3030303034307830ull,
0x783009090a203330ull,0x6331386130303031ull,0x6130303031783020ull,0x3031783020343038ull,
0x3020383163393030ull,0x3034383030303178ull,0x31783009090a2063ull,0x2038306139303030ull,
0x6139303030317830ull,0x3432667830203030ull,0x7830203931303030ull,0x3438373030303030ull,
0x3266783009090a20ull,0x3020393030303034ull,0x3837303030303078ull,0x3034326678302034ull,
0x3078302031303030ull,0x2034383730303030ull,0x323063783009090aull,0x7830206433653162ull,
0x6261616132653330ull,0x3136303065783020ull,0x3030783020393134ull,0x0a20303837343430ull,
0x3230306578300909ull,0x3078302035346531ull,0x2030383734313030ull,0x3432303030627830ull,
0x3038307830203934ull,0x090a203038373035ull,0x3130303065783009ull,0x3030783020313565ull,
0x3020303837383130ull,0x3163393030303178ull,0x3030303178302038ull,0x09090a2063313838ull,
0x3838303030317830ull,0x3030317830203431ull,0x7830203031613930ull,0x6330366130303031ull,
0x6130303031783020ull,0x3009090a20343036ull,0x3063393030303178ull,0x3030303178302038ull,
0x6678302030306139ull,0x2039313030303432ull,0x3730303030307830ull,0x783009090a203438ull,
0x3930303030343266ull,0x3030303030783020ull,0x3266783020343837ull,0x3020313130303034ull,
0x3837303030303078ull,0x66783009090a2034ull,0x2031303030303432ull,0x3730303030307830ull,
0x3130637830203438ull,0x7830203533343232ull,0x3038373030303030ull,0x3065783009090a20ull,
0x3020393334323138ull,0x3837303234303078ull,0x3030306278302030ull,0x3078302031323461ull,
0x2033303030343034ull,0x303165783009090aull,0x7830203933613165ull,0x3038373830343030ull,
0x3238303165783020ull,0x3030783020313234ull,0x0a20303837633034ull,0x3338306578300909ull,
0x3078302064343432ull,0x2030383734323438ull,0x6331623230637830ull,0x6533307830203532ull,
0x090a206261616132ull,0x3238303165783009ull,0x3030783020313234ull,0x3020303837303134ull,
0x3334323331316578ull,0x3034303078302039ull,0x09090a2030383734ull,0x3431363030657830ull,
0x3030307830203931ull,0x7830203038376332ull,0x3532323134313063ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3130316232306378ull,0x3265333078302064ull,0x6578302062616161ull,
0x2064303432653031ull,0x3730313430307830ull,0x783009090a203038ull,0x3530653134303065ull,
0x3831303030783020ull,0x3065783020303837ull,0x3020393034313230ull,0x3837303330303078ull,
0x65783009090a2030ull,0x2035316530313130ull,0x3734323030307830ull,0x3230637830203038ull,
0x7830206430363062ull,0x6261616132653330ull,0x3063783009090a20ull,0x3020313134326430ull,
0x3837303030303078ull,0x3030306578302030ull,0x3078302031306531ull,0x2030383738303030ull,
0x303065783009090aull,0x7830203930363031ull,0x3038373431303030ull,0x3062323063783020ull,
0x3330783020353038ull,0x0a20626161613265ull,0x3030306578300909ull,0x3078302031303230ull,
0x2030383738303030ull,0x3030303030637830ull,0x3334307830203130ull,0x090a203330306637ull,
0x3030303061783009ull,0x3438783020393030ull,0x3020303837343630ull,0x3030323230303378ull,
0x3031346378302035ull,0x09090a2030383730ull,0x3430303030617830ull,0x3030307830203130ull,
0x7830203038376330ull,0x3530383038303033ull,0x3030313063783020ull,0x3009090a20303837ull,
0x3038633030303278ull,0x3032343078302039ull,0x6478302030383734ull,0x2039303030313030ull,
0x3734303030307830ull,0x783009090a203038ull,0x6430303030303031ull,0x6333303030783020ull,
0x3064783020303837ull,0x3020353034306530ull,0x3837303063306178ull,0x0a7d0a7d090a2031ull,
0x0000000000000000ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_10",(char*)__deviceText_$sm_10$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"8c09133a2a6b9f58",(char*)"bicubicTexture.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0};
# 5 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.c" 2
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
# 1393 "/home/gdiamos/temp/cuda/bin//../include/device_functions.h" 3
static double fdivide(double a, double b)
{
  return (double)fdividef((float)a, (float)b);
}



static int __double2int_rz(double a)
{
  return __float2int_rz((float)a);
}

static unsigned int __double2uint_rz(double a)
{
  return __float2uint_rz((float)a);
}

static long long int __double2ll_rz(double a)
{
  return __float2ll_rz((float)a);
}

static unsigned long long int __double2ull_rz(double a)
{
  return __float2ull_rz((float)a);
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
  return __fma_rz(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __hiloint2double(0x80000000, 0x00000000));
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
  return __fma_rn(a, b, __hiloint2double(0x80000000, 0x00000000));
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
# 3855 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 3
# 1 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/home/gdiamos/temp/cuda/bin//../include/math_functions_dbl_ptx1.h" 3
static double __cuda_fabs(double a)
{
  return (float)__cuda_fabsf((float)a);
}

static double __cuda_fmax(double a, double b)
{
  return (float)__cuda_fmaxf((float)a, (float)b);
}

static double __cuda_fmin(double a, double b)
{
  return (float)__cuda_fminf((float)a, (float)b);
}

static int __cuda___finite(double a)
{
  return __cuda___finitef((float)a);
}

static int __cuda___isinf(double a)
{
  return __cuda___isinff((float)a);
}

static int __cuda___isnan(double a)
{
  return __cuda___isnanf((float)a);
}

static int __cuda___signbit(double a)
{
  return __cuda___signbitf((float)a);
}

static double __cuda_sqrt(double a)
{
  return (double)__cuda_sqrtf((float)a);
}

static double __cuda_rsqrt(double a)
{
  return (double)__cuda_rsqrtf((float)a);
}

static double __cuda_ceil(double a)
{
  return (double)__cuda_ceilf((float)a);
}

static double __cuda_trunc(double a)
{
  return (double)__cuda_truncf((float)a);
}

static double __cuda_floor(double a)
{
  return (double)__cuda_floorf((float)a);
}

static double __cuda_copysign(double a, double b)
{
  return (double)__cuda_copysignf((float)a, (float)b);
}

static double __cuda_sin(double a)
{
  return (double)__cuda_sinf((float)a);
}

static double __cuda_cos(double a)
{
  return (double)__cuda_cosf((float)a);
}

static void __cuda_sincos(double a, double *sptr, double *cptr)
{
  float fs, fc;

  __cuda_sincosf((float)a, &fs, &fc);

  *sptr = (double)fs;
  *cptr = (double)fc;
}

static double __cuda_tan(double a)
{
  return (double)__cuda_tanf((float)a);
}

static double __cuda_exp(double a)
{
  return (double)__cuda_expf((float)a);
}

static double __cuda_exp2(double a)
{
  return (double)__cuda_exp2f((float)a);
}

static double __cuda_exp10(double a)
{
  return (double)__cuda_exp10f((float)a);
}

static double __cuda_expm1(double a)
{
  return (double)__cuda_expm1f((float)a);
}

static double __cuda_cosh(double a)
{
  return (double)__cuda_coshf((float)a);
}

static double __cuda_sinh(double a)
{
  return (double)__cuda_sinhf((float)a);
}

static double __cuda_tanh(double a)
{
  return (double)__cuda_tanhf((float)a);
}

static double __cuda_asin(double a)
{
  return (double)__cuda_asinf((float)a);
}

static double __cuda_acos(double a)
{
  return (double)__cuda_acosf((float)a);
}

static double __cuda_atan(double a)
{
  return (double)__cuda_atanf((float)a);
}

static double __cuda_atan2(double a, double b)
{
  return (double)__cuda_atan2f((float)a, (float)b);
}

static double __cuda_log(double a)
{
  return (double)__cuda_logf((float)a);
}

static double __cuda_log2(double a)
{
  return (double)__cuda_log2f((float)a);
}

static double __cuda_log10(double a)
{
  return (double)__cuda_log10f((float)a);
}

static double __cuda_log1p(double a)
{
  return (double)__cuda_log1pf((float)a);
}

static double __cuda_acosh(double a)
{
  return (double)__cuda_acoshf((float)a);
}

static double __cuda_asinh(double a)
{
  return (double)__cuda_asinhf((float)a);
}

static double __cuda_atanh(double a)
{
  return (double)__cuda_atanhf((float)a);
}

static double __cuda_hypot(double a, double b)
{
  return (double)__cuda_hypotf((float)a, (float)b);
}

static double __cuda_cbrt(double a)
{
  return (double)__cuda_cbrtf((float)a);
}

static double __cuda_erf(double a)
{
  return (double)__cuda_erff((float)a);
}

static double __cuda_erfc(double a)
{
  return (double)__cuda_erfcf((float)a);
}

static double __cuda_lgamma(double a)
{
  return (double)__cuda_lgammaf((float)a);
}

static double __cuda_tgamma(double a)
{
  return (double)__cuda_tgammaf((float)a);
}

static double __cuda_ldexp(double a, int b)
{
  return (double)__cuda_ldexpf((float)a, b);
}

static double __cuda_scalbn(double a, int b)
{
  return (double)__cuda_scalbnf((float)a, b);
}

static double __cuda_scalbln(double a, long b)
{
  return (double)__cuda_scalblnf((float)a, b);
}

static double __cuda_frexp(double a, int *b)
{
  return (double)__cuda_frexpf((float)a, b);
}

static double __cuda_modf(double a, double *b)
{
  float fb;
  float fa = __cuda_modff((float)a, &fb);

  *b = (double)fb;

  return (double)fa;
}

static double __cuda_fmod(double a, double b)
{
  return (double)__cuda_fmodf((float)a, (float)b);
}

static double __cuda_remainder(double a, double b)
{
  return (double)__cuda_remainderf((float)a, (float)b);
}

static double __cuda_remquo(double a, double b, int *c)
{
  return (double)__cuda_remquof((float)a, (float)b, c);
}

static double __cuda_nextafter(double a, double b)
{
  return (double)__cuda_nextafterf((float)a, (float)b);
}

static double __cuda_nan(const char *tagp)
{
  return (double)__cuda_nanf(tagp);
}

static double __cuda_pow(double a, double b)
{
  return (double)__cuda_powf((float)a, (float)b);
}

static double __cuda_round(double a)
{
  return (double)__cuda_roundf((float)a);
}

static long __cuda_lround(double a)
{
  return __cuda_lroundf((float)a);
}

static long long __cuda_llround(double a)
{
  return __cuda_llroundf((float)a);
}

static double __cuda_rint(double a)
{
  return (double)__cuda_rintf((float)a);
}

static long __cuda_lrint(double a)
{
  return __cuda_lrintf((float)a);
}

static long long __cuda_llrint(double a)
{
  return __cuda_llrintf((float)a);
}

static double __cuda_nearbyint(double a)
{
  return (double)__cuda_nearbyintf((float)a);
}

static double __cuda_fdim(double a, double b)
{
  return (double)__cuda_fdimf((float)a, (float)b);
}

static int __cuda_ilogb(double a)
{
  return __cuda_ilogbf((float)a);
}

static double __cuda_logb(double a)
{
  return (double)__cuda_logbf((float)a);
}

static double __cuda_fma(double a, double b, double c)
{
  return (double)__cuda_fmaf((float)a, (float)b, (float)c);
}
# 3856 "/home/gdiamos/temp/cuda/bin//../include/math_functions.h" 2 3
# 94 "/home/gdiamos/temp/cuda/bin//../include/common_functions.h" 2
# 216 "/home/gdiamos/temp/cuda/bin//../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.c" 2
struct __T20;
struct __T21;
struct __T22;
struct __T20 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T21 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T22 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
# 21 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_000018b5_00000000_4_bicubicTexture_cpp1_ii_c14de7b3(void) __attribute__((__constructor__));
void __device_stub__Z8d_renderP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T20 *__T23;
char __[256]; *(char**)&__T23 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T23->__par0 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T23->__par1 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T23->__par2 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T23->__par3 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T23->__par4 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T23->__par5 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T23->__par6 - (size_t)__T23) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T23->__par7 - (size_t)__T23) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z8d_renderP6uchar4jjfffff); (void)cudaLaunch(((char *)__device_stub__Z8d_renderP6uchar4jjfffff)); };}
void __device_stub__Z15d_renderBicubicP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T21 *__T24;
char __[256]; *(char**)&__T24 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T24->__par5 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T24->__par6 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T24->__par7 - (size_t)__T24) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z15d_renderBicubicP6uchar4jjfffff); (void)cudaLaunch(((char *)__device_stub__Z15d_renderBicubicP6uchar4jjfffff)); };}
void __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T22 *__T2173;
char __[256]; *(char**)&__T2173 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2173->__par0 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2173->__par1 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2173->__par2 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2173->__par3 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2173->__par4 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2173->__par5 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2173->__par6 - (size_t)__T2173) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2173->__par7 - (size_t)__T2173) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z19d_renderFastBicubicP6uchar4jjfffff); (void)cudaLaunch(((char *)__device_stub__Z19d_renderFastBicubicP6uchar4jjfffff)); };}
# 37 "/tmp/tmpxft_000018b5_00000000-1_bicubicTexture.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_000018b5_00000000_4_bicubicTexture_cpp1_ii_c14de7b3(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z19d_renderFastBicubicP6uchar4jjfffff, (char*)"_Z19d_renderFastBicubicP6uchar4jjfffff", "_Z19d_renderFastBicubicP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z15d_renderBicubicP6uchar4jjfffff, (char*)"_Z15d_renderBicubicP6uchar4jjfffff", "_Z15d_renderBicubicP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z8d_renderP6uchar4jjfffff, (char*)"_Z8d_renderP6uchar4jjfffff", "_Z8d_renderP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&tex, 0, "tex", 2, 1, 0);}

}
# 554 "bicubicTexture.cu" 2

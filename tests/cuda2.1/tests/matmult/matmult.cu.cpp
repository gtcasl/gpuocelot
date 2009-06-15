# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.cpp"
# 1 "matmult.cu"
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

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h" 1

extern "C" {


extern void __device_stub__Z15k_matMult_naivePfS_S_iii(float *, float *, float *, int, int, int);
# 20 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
}
# 331 "/home/gdiamos/temp/cuda/bin//../include/cuda_runtime.h" 2
# 63 "matmult.cu"
void matrix_multiply_naive(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
# 64 "matmult.cu"
auto dim3 grid(A_rows / 16, B_cols / 16);
# 65 "matmult.cu"
auto dim3 block(16, 16);
# 66 "matmult.cu"
cudaConfigureCall(grid, block) ? ((void)0) : __device_stub__Z15k_matMult_naivePfS_S_iii(A, B, C, A_rows, A_cols, B_cols);
# 67 "matmult.cu"
}

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h" 1

extern "C" {





extern void __device_stub__Z16k_matMult_unrollPfS_S_iii(float *, float *, float *, int, int, int);
# 20 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
}
# 70 "matmult.cu" 2
# 168 "matmult.cu"
void matrix_multiply_unroll(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
# 169 "matmult.cu"
auto dim3 grid(B_cols / 32, A_rows / 16);
# 170 "matmult.cu"
auto dim3 block(16, 16);
# 171 "matmult.cu"
cudaConfigureCall(grid, block) ? ((void)0) : __device_stub__Z16k_matMult_unrollPfS_S_iii(A, B, C, A_rows, A_cols, B_cols);
# 172 "matmult.cu"
}

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h" 1

extern "C" {
# 11 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
extern void __device_stub__Z17k_matMult_unroll2PfS_S_iii(float *, float *, float *, int, int, int);
# 20 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
}
# 175 "matmult.cu" 2
# 371 "matmult.cu"
void matrix_multiply_unroll2(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
# 372 "matmult.cu"
auto dim3 grid(B_cols / 64, A_rows / 64);
# 373 "matmult.cu"
auto dim3 block(16, 16);
# 374 "matmult.cu"
cudaConfigureCall(grid, block) ? ((void)0) : __device_stub__Z17k_matMult_unroll2PfS_S_iii(A, B, C, A_rows, A_cols, B_cols);
# 375 "matmult.cu"
}

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h" 1

extern "C" {
# 14 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
extern void __device_stub__Z7sgemmNNPKfiS0_iPfiiff(const float *, int, const float *, int, float *, int, int, float, float);





}
# 378 "matmult.cu" 2
# 461 "matmult.cu"
void matrix_multiply_volvok(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
# 462 "matmult.cu"
auto dim3 grid((A_rows == ((A_rows / 64) * 64)) ? (A_rows / 64) : (A_rows / 64 + 1), (B_cols == ((B_cols / 16) * 16)) ? (B_cols / 16) : (B_cols / 16 + 1));
# 463 "matmult.cu"
auto dim3 block(16, 4);
# 465 "matmult.cu"
cudaConfigureCall(grid, block) ? ((void)0) : __device_stub__Z7sgemmNNPKfiS0_iPfiiff(A, A_rows, B, A_cols, C, A_rows, A_cols, 1, 0);
# 468 "matmult.cu"
}
# 472 "matmult.cu"
extern "C" void matrix_multiply_GPU(float *A, float *B, float *C, int A_rows, int A_cols, int B_cols) {
# 474 "matmult.cu"
matrix_multiply_volvok(A, B, C, A_rows, A_cols, B_cols);
# 476 "matmult.cu"
}

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h" 1

extern "C" {
# 17 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.h"
extern void __device_stub__Z13k_fill_matrixPfiif(float *, int, int, float);


}
# 479 "matmult.cu" 2
# 488 "matmult.cu"
extern "C" void fill_matrix(float *A, int M, int N, float s) {
# 489 "matmult.cu"
auto dim3 grid((N == ((N / 16) * 16)) ? (N / 16) : (N / 16 + 1), (M == ((M / 16) * 16)) ? (M / 16) : (M / 16 + 1));
# 490 "matmult.cu"
auto dim3 block(16, 16);
# 491 "matmult.cu"
cudaConfigureCall(grid, block) ? ((void)0) : __device_stub__Z13k_fill_matrixPfiif(A, M, N, s);
# 492 "matmult.cu"
}

# 1 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_00001388_00000000-3_matmult.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00001388_00000000-3_matmult.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x2065646f630a7d6eull,
0x20656d616e090a7bull,0x5f6b35315a5f203dull,0x5f746c754d74616dull,0x536650657669616eull,
0x090a6969695f535full,0x30203d206d656d6cull,0x3d206d656d73090aull,0x72090a3030313220ull,
0x0a39203d20206765ull,0x203d202072616209ull,0x74736e6f63090a31ull,0x65730909090a7b20ull,
0x203d20656d616e67ull,0x09090a74736e6f63ull,0x206d756e67657309ull,0x0909090a31203d20ull,
0x202074657366666full,0x620909090a30203dull,0x3d20202073657479ull,0x6d656d09090a3420ull,
0x78300909090a7b20ull,0x6666333030303030ull,0x7d090a7d09090a20ull,0x646f636e6962090aull,
0x783009090a7b2065ull,0x3930323030383064ull,0x3030343030783020ull,0x3031783020303837ull,
0x3020353034303030ull,0x3837343030303478ull,0x61783009090a2030ull,0x2031313430303030ull,
0x3730303034307830ull,0x3031317830203038ull,0x7830203830366630ull,0x3430386630303131ull,
0x3036783009090a20ull,0x3020643065343130ull,0x3837303132303078ull,0x3530303478302030ull,
0x3178302034316330ull,0x2034303232303031ull,0x303034783009090aull,0x7830203931363038ull,
0x3038373030303030ull,0x3034303036783020ull,0x3030783020643165ull,0x0a20303837343130ull,
0x3130303478300909ull,0x3078302035316334ull,0x2030383730303230ull,0x6330303130337830ull,
0x3134637830203931ull,0x090a203038373030ull,0x3030303061783009ull,0x3430783020313030ull,
0x3020303837303030ull,0x3165303031303378ull,0x3031346378302064ull,0x09090a2030383730ull,
0x3430383030367830ull,0x3030307830203530ull,0x7830203038373831ull,0x3931613030303032ull,
0x3030303430783020ull,0x3009090a20303837ull,0x3063303430303678ull,0x3130303078302039ull,
0x3278302030383763ull,0x2034303238363030ull,0x3038323030327830ull,0x783009090a203830ull,
0x6466376463373033ull,0x6330326336783020ull,0x3033783020386337ull,0x3020353032303230ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2064313430323030ull,0x3730303134637830ull,
0x3030317830203038ull,0x7830203930386630ull,0x3038376333303630ull,0x3132783009090a20ull,
0x3020383163653130ull,0x3138653730313278ull,0x3530303178302063ull,0x3078302033303032ull,
0x2030383230303030ull,0x303033783009090aull,0x7830203530383034ull,0x3038373030313463ull,
0x3036303033783020ull,0x3463783020313138ull,0x0a20303837303031ull,0x3030303278300909ull,
0x3078302035303030ull,0x2030383734303034ull,0x3838343330327830ull,0x3030307830203131ull,
0x090a203334303030ull,0x3032303030783009ull,0x3063783020393030ull,0x3020303837303030ull,
0x3032303230303078ull,0x3030306378302035ull,0x09090a2030383730ull,0x3830303030307830ull,
0x3030637830206430ull,0x7830203038373030ull,0x3131386436303033ull,0x3030333463783020ull,
0x3009090a20303837ull,0x3038663030303178ull,0x3330343078302035ull,0x6478302030383763ull,
0x2031326530653030ull,0x3730306330387830ull,0x783009090a203038ull,0x3130613132303430ull,
0x3032323465783020ull,0x3638783020303837ull,0x3020333065666631ull,0x3030303030303078ull,
0x64783009090a2030ull,0x2031326330653030ull,0x3730306330387830ull,0x3034307830203038ull,
0x7830203130613130ull,0x3038373032323465ull,0x3638783009090a20ull,0x3020333065666631ull,
0x3030303030303078ull,0x3030383178302030ull,0x3478302031326131ull,0x2030383763303034ull,
0x306365783009090aull,0x7830203132306338ull,0x3038373830323030ull,0x3330303831783020ull,
0x3434783020393061ull,0x0a20303837633030ull,0x3130386478300909ull,0x3278302031313836ull,
0x2030383730303030ull,0x3263323063657830ull,0x3230307830203132ull,0x090a203038373032ull,
0x3030303031783009ull,0x3434783020393030ull,0x3020343837633030ull,0x3234633230636578ull,
0x3232303078302031ull,0x09090a2030383730ull,0x3032303030317830ull,0x3034347830203930ull,
0x7830203438376330ull,0x3131383632303864ull,0x3030303032783020ull,0x3009090a20303837ull,
0x3236633230636578ull,0x3232303078302031ull,0x3178302030383730ull,0x2039303030303030ull,
0x3763303034347830ull,0x783009090a203438ull,0x3132386332306365ull,0x3032323030783020ull,
0x3031783020303837ull,0x3020393030323030ull,0x3837633030343478ull,0x64783009090a2034ull,
0x2031313836333038ull,0x3730303030327830ull,0x3063657830203038ull,0x7830203132616332ull,
0x3038373032323030ull,0x3031783009090a20ull,0x3020393030303030ull,0x3837633030343478ull,
0x3230636578302034ull,0x3078302031326363ull,0x2030383730323230ull,0x303031783009090aull,
0x7830203930303230ull,0x3438376330303434ull,0x3634303864783020ull,0x3032783020313138ull,
0x0a20303837303030ull,0x3230636578300909ull,0x3078302031326563ull,0x2030383730323230ull,
0x3030303030317830ull,0x3034347830203930ull,0x090a203438376330ull,0x6432306365783009ull,
0x3030783020313230ull,0x3020303837303232ull,0x3030323030303178ull,0x3030343478302039ull,
0x09090a2034383763ull,0x3836353038647830ull,0x3030327830203131ull,0x7830203038373030ull,
0x3132326432306365ull,0x3032323030783020ull,0x3009090a20303837ull,0x3030303030303178ull,
0x3030343478302039ull,0x6578302034383763ull,0x2031323464323063ull,0x3730323230307830ull,
0x783009090a203038ull,0x3930303230303031ull,0x6330303434783020ull,0x3864783020343837ull,
0x3020313138363630ull,0x3837303030303278ull,0x65783009090a2030ull,0x2031323664323063ull,
0x3730323230307830ull,0x3030317830203038ull,0x7830203930303030ull,0x3438376330303434ull,
0x6365783009090a20ull,0x3020313238643230ull,0x3837303232303078ull,0x3030303178302030ull,
0x3478302039303032ull,0x2034383763303034ull,0x303864783009090aull,0x7830203131383637ull,
0x3038373030303032ull,0x6432306365783020ull,0x3030783020313261ull,0x0a20303837303232ull,
0x3030303178300909ull,0x3478302039303030ull,0x2034383763303034ull,0x6364323063657830ull,
0x3230307830203132ull,0x090a203038373032ull,0x3230303031783009ull,0x3434783020393030ull,
0x3020343837633030ull,0x3065643230636578ull,0x3232303078302039ull,0x09090a2030383730ull,
0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,0x3530323830313032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x6637643130303378ull,0x3132633678302064ull,
0x3278302038633730ull,0x2064316538303030ull,0x3030303030307830ull,0x783009090a203730ull,
0x3931383030303032ull,0x3831303430783020ull,0x3031783020303837ull,0x3020333030663130ull,
0x3832303030303078ull,0x31783009090a2030ull,0x2035303831303030ull,0x3763303034347830ull,
0x3030347830203038ull,0x7830203131633033ull,0x3038373030303030ull,0x3036783009090a20ull,
0x3020313165303230ull,0x3837303130303078ull,0x3031303378302030ull,0x6378302031313830ull,
0x2030383730303134ull,0x303032783009090aull,0x7830203130613030ull,0x3038373030303430ull,
0x3032303036783020ull,0x3030783020353063ull,0x0a20303837303130ull,0x3030303278300909ull,
0x3078302031303230ull,0x2030383730303034ull,0x3030323030337830ull,0x3134637830203130ull,
0x090a203038373030ull,0x6430303032783009ull,0x3430783020313030ull,0x3020303837303032ull,
0x3030306530306478ull,0x3063306178302039ull,0x7d090a2031383730ull,0x2065646f630a7d0aull,
0x20656d616e090a7bull,0x5f6b33315a5f203dull,0x74616d5f6c6c6966ull,0x6669696650786972ull,
0x3d206d656d6c090aull,0x6d656d73090a3020ull,0x72090a3633203d20ull,0x0a34203d20206765ull,
0x203d202072616209ull,0x74736e6f63090a30ull,0x65730909090a7b20ull,0x203d20656d616e67ull,
0x09090a74736e6f63ull,0x206d756e67657309ull,0x0909090a31203d20ull,0x202074657366666full,
0x620909090a30203dull,0x3d20202073657479ull,0x6d656d09090a3420ull,0x78300909090a7b20ull,
0x6666333030303030ull,0x7d090a7d09090a20ull,0x646f636e6962090aull,0x783009090a7b2065ull,
0x3930323030383064ull,0x3030343030783020ull,0x3031783020303837ull,0x3020353034303030ull,
0x3837343030303478ull,0x61783009090a2030ull,0x2039303430303030ull,0x3730303034307830ull,
0x3030317830203038ull,0x7830203930323030ull,0x3038373430303034ull,0x3061783009090a20ull,
0x3020643030303030ull,0x3837303030343078ull,0x3130303678302030ull,0x3078302039306534ull,
0x2030383738303230ull,0x303036783009090aull,0x7830203530633432ull,0x3038376330323030ull,
0x6332303033783020ull,0x6336783020646664ull,0x0a20386337303132ull,0x3130303378300909ull,
0x3678302064666663ull,0x2038633230313263ull,0x3030303030337830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3030303031783009ull,0x3434783020313065ull,0x3020303837633030ull,
0x3030303530303478ull,0x3030303078302064ull,0x09090a2030383730ull,0x3230343030367830ull,
0x3030307830206430ull,0x7830203038376330ull,0x6430363030313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3030303430303678ull,0x3030303078302031ull,0x3278302030383763ull,
0x2031303030303030ull,0x3734303034307830ull,0x783009090a203038ull,0x3530303032303033ull,
0x3030313463783020ull,0x3131783020303837ull,0x3020303030663030ull,0x3038653130313278ull,
0x64783009090a2034ull,0x2031303230653030ull,0x3730306330617830ull,0x7d0a7d090a203138ull,
0x0a7b2065646f630aull,0x203d20656d616e09ull,0x616d5f6b37315a5full,0x6e755f746c754d74ull,
0x536650326c6c6f72ull,0x090a6969695f535full,0x30203d206d656d6cull,0x3d206d656d73090aull,
0x72090a3434323820ull,0x3633203d20206765ull,0x3d2020726162090aull,0x736e6f63090a3120ull,
0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x6d756e6765730909ull,
0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,0x2020207365747962ull,
0x656d09090a34203dull,0x300909090a7b206dull,0x6633303030303078ull,0x090a7d09090a2066ull,
0x6f636e6962090a7dull,0x3009090a7b206564ull,0x3034323030313178ull,0x3030303178302038ull,
0x3478302030323038ull,0x2035306534323030ull,0x3730303230307830ull,0x783009090a203038ull,
0x3130323230383064ull,0x3030343030783020ull,0x3033783020303837ull,0x3020353032303230ull,
0x3837303031346378ull,0x61783009090a2030ull,0x2031303030303030ull,0x3730303034307830ull,
0x3030317830203038ull,0x7830203930363130ull,0x3038376330303434ull,0x3032783009090a20ull,
0x3020393330303030ull,0x3837343030343078ull,0x3030303178302030ull,0x3478302035303831ull,
0x2030383763303034ull,0x313034783009090aull,0x7830206430383064ull,0x3038373030303030ull,
0x3063313036783020ull,0x3030783020313161ull,0x0a20303837633030ull,0x3030303478300909ull,
0x3078302064303630ull,0x2030383730303030ull,0x3830303130337830ull,0x3134637830203131ull,
0x090a203038373030ull,0x3030313033783009ull,0x3463783020643036ull,0x3020303837303031ull,
0x3438306331303678ull,0x3130303078302035ull,0x09090a2030383730ull,0x3430303030367830ull,
0x3030307830203134ull,0x7830203038376330ull,0x6466376463373033ull,0x6330326336783020ull,
0x3009090a20386337ull,0x3332343030306178ull,0x3032343078302064ull,0x3178302030383730ull,
0x2035303866303030ull,0x3763333036307830ull,0x783009090a203038ull,0x3930386630303031ull,
0x6333303430783020ull,0x3031783020303837ull,0x3020643038663030ull,0x3837633330363078ull,
0x31783009090a2030ull,0x2031313866303030ull,0x3763333034307830ull,0x3030317830203038ull,
0x7830203531386630ull,0x3038376333303630ull,0x3034783009090a20ull,0x3020353263346531ull,
0x3837303032303078ull,0x3030303178302030ull,0x3078302039313866ull,0x2030383763333034ull,
0x303031783009090aull,0x7830206431386630ull,0x3038376333303630ull,0x3230303061783020ull,
0x3430783020393530ull,0x0a20303837303030ull,0x3230303378300909ull,0x6378302064323231ull,
0x2030383730303134ull,0x3866303030317830ull,0x3034307830203132ull,0x090a203038376333ull,
0x6630303031783009ull,0x3630783020353238ull,0x3020303837633330ull,0x3238663030303178ull,
0x3330343078302039ull,0x09090a2030383763ull,0x6332303030327830ull,0x3034307830206434ull,
0x7830203038376332ull,0x6432386630303031ull,0x6333303630783020ull,0x3009090a20303837ull,
0x3338663030303178ull,0x3330343078302031ull,0x3178302030383763ull,0x2035333866303030ull,
0x3763333036307830ull,0x783009090a203038ull,0x3834306133313032ull,0x6131313032783020ull,
0x3031783020343563ull,0x3020313438663030ull,0x3837633330343078ull,0x31783009090a2030ull,
0x2035343866303030ull,0x3763333036307830ull,0x3030337830203038ull,0x7830203135343232ull,
0x3038373030313463ull,0x3033783009090a20ull,0x3020353561323230ull,0x3837303031346378ull,
0x3030303178302030ull,0x3078302039343866ull,0x2030383763333034ull,0x313132783009090aull,
0x7830203035636534ull,0x3435386535313132ull,0x3632323031783020ull,0x3030783020333030ull,
0x0a20303832303030ull,0x3334303478300909ull,0x3078302031376531ull,0x2033303030303030ull,
0x3664353030337830ull,0x3334637830206436ull,0x090a203038373030ull,0x3036303033783009ull,
0x3463783020353630ull,0x3020303837303031ull,0x3538333030303278ull,0x3530343078302064ull,
0x09090a2030383738ull,0x3664343030337830ull,0x3334637830203537ull,0x7830203038373030ull,
0x3136653131303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3632623631303278ull,
0x3931303278302038ull,0x3278302063356561ull,0x2030383662643130ull,0x6361383130327830ull,
0x783009090a203036ull,0x3837653936313032ull,0x6238313032783020ull,0x3033783020303632ull,
0x3020643630303430ull,0x3837303031346378ull,0x32783009090a2030ull,0x2035376361643030ull,
0x3030303030307830ull,0x3130327830203334ull,0x7830203436326265ull,0x6336636162313032ull,
0x3030783009090a20ull,0x3020393061333230ull,0x3837303030306378ull,0x3630303078302030ull,
0x6378302035303030ull,0x2030383730303030ull,0x303033783009090aull,0x7830203935653133ull,
0x3038373030313463ull,0x3132303033783020ull,0x3463783020353765ull,0x0a20303837303031ull,
0x3730303378300909ull,0x6378302039373664ull,0x2030383730303334ull,0x3664363030337830ull,
0x3334637830206437ull,0x090a203038373030ull,0x6436303033783009ull,0x3463783020643338ull,
0x3020303837303033ull,0x3838663030303178ull,0x3330343078302035ull,0x09090a2030383763ull,
0x3833323030337830ull,0x3134637830203137ull,0x7830203038373030ull,0x3138303432303033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3861326530306478ull,0x3063303878302039ull,
0x3278302030383730ull,0x2031306132303030ull,0x3763373034307830ull,0x783009090a203038ull,
0x3130303065303064ull,0x3030633038783020ull,0x3030783020303837ull,0x3020643036333230ull,
0x3837303030306378ull,0x30783009090a2030ull,0x2031306131303063ull,0x3738383234657830ull,
0x3063307830203038ull,0x7830203130613132ull,0x3038373030323465ull,0x3638783009090a20ull,
0x3020333065666631ull,0x3030303030303078ull,0x6530306478302030ull,0x3878302064383832ull,
0x2030383730306330ull,0x303032783009090aull,0x7830203130383230ull,0x3038373437303430ull,
0x3065303064783020ull,0x3038783020393830ull,0x0a20303837303063ull,0x3030303278300909ull,
0x3078302031303832ull,0x2030383738353034ull,0x3030653030647830ull,0x6330387830203130ull,
0x090a203038373030ull,0x3332303030783009ull,0x3063783020643034ull,0x3020303837303030ull,
0x3061313830633078ull,0x3832346578302031ull,0x09090a2030383763ull,0x3233323030307830ull,
0x3030637830206430ull,0x7830203038373030ull,0x3130613138306330ull,0x3838323465783020ull,
0x3009090a20303837ull,0x3838323030303278ull,0x3730343078302039ull,0x6478302030383730ull,
0x2064383434653030ull,0x3730306330387830ull,0x783009090a203038ull,0x6430303332303030ull,
0x3030303063783020ull,0x6330783020303837ull,0x3020313061313830ull,0x3837303032346578ull,
0x32783009090a2030ull,0x2031306333303030ull,0x3734353034307830ull,0x3030647830203038ull,
0x7830203938303065ull,0x3038373030633038ull,0x3032783009090a20ull,0x3020313061323030ull,
0x3837303830343078ull,0x6530306478302030ull,0x3878302031303030ull,0x2030383730306330ull,
0x303030783009090aull,0x7830206430653232ull,0x3038373030303063ull,0x3138306330783020ull,
0x3465783020313061ull,0x0a20303837633832ull,0x3230303078300909ull,0x6378302064303633ull,
0x2030383730303030ull,0x6131343063307830ull,0x3234657830203130ull,0x090a203038373838ull,
0x3136306330783009ull,0x3465783020313061ull,0x3020303837303032ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3030313038647830ull,0x3030327830206430ull,
0x7830203038373030ull,0x3130613130303431ull,0x6330303434783020ull,0x3009090a20303837ull,
0x3430633030636578ull,0x3432303078302031ull,0x6578302030383730ull,0x2039383065303063ull,
0x3734333230307830ull,0x783009090a203038ull,0x6430303032303864ull,0x3030303032783020ull,
0x3431783020303837ull,0x3020353363313030ull,0x3837633030343478ull,0x65783009090a2030ull,
0x2039343063303038ull,0x3738343230307830ull,0x3038657830203038ull,0x7830203130306530ull,
0x3038373434323030ull,0x6365783009090a20ull,0x3020353430636430ull,0x3837383432303078ull,
0x6430636578302030ull,0x3078302031303065ull,0x2030383730303230ull,0x303864783009090aull,
0x7830206430303033ull,0x3038373030303032ull,0x6364306365783020ull,0x3030783020313430ull,
0x0a20303837303432ull,0x6430636578300909ull,0x3078302039383065ull,0x2030383738383230ull,
0x3030343038647830ull,0x3030327830206430ull,0x090a203038373030ull,0x3130303431783009ull,
0x3434783020353365ull,0x3020303837633030ull,0x3430636430636578ull,0x3432303078302039ull,
0x09090a2030383734ull,0x3065643063657830ull,0x3230307830203534ull,0x7830203038373030ull,
0x6430303035303864ull,0x3030303032783020ull,0x3009090a20303837ull,0x3430636430636578ull,
0x3432303078302031ull,0x6578302030383730ull,0x2035333065643063ull,0x3738383230307830ull,
0x783009090a203038ull,0x6430303036303864ull,0x3030303032783020ull,0x3431783020303837ull,
0x3020313030323030ull,0x3837633030343478ull,0x65783009090a2030ull,0x2039343063303063ull,
0x3738343230307830ull,0x3063657830203038ull,0x7830203534306530ull,0x3038373434323030ull,
0x3864783009090a20ull,0x3020643030303730ull,0x3837303030303278ull,0x3030636578302030ull,
0x3078302031343063ull,0x2030383730343230ull,0x306365783009090aull,0x7830203533306530ull,
0x3038373433323030ull,0x3038303864783020ull,0x3032783020643030ull,0x0a20303837303030ull,
0x3030343178300909ull,0x3478302031303232ull,0x2030383763303034ull,0x3063303063657830ull,
0x3230307830203934ull,0x090a203038373834ull,0x6530306365783009ull,0x3030783020353430ull,
0x3020303837343432ull,0x3030303930386478ull,0x3030303278302064ull,0x09090a2030383730ull,
0x3063303063657830ull,0x3230307830203134ull,0x7830203038373034ull,0x3533306530306365ull,
0x3433323030783020ull,0x3009090a20303837ull,0x3030306130386478ull,0x3030303278302064ull,
0x3178302030383730ull,0x2031303432303034ull,0x3763303034347830ull,0x783009090a203038ull,
0x3934306330306365ull,0x3834323030783020ull,0x6365783020303837ull,0x3020353430653030ull,
0x3837343432303078ull,0x64783009090a2030ull,0x2064303030623038ull,0x3730303030327830ull,
0x3063657830203038ull,0x7830203134306330ull,0x3038373034323030ull,0x6365783009090a20ull,
0x3020353330653030ull,0x3837343332303078ull,0x6330386478302030ull,0x3278302064303030ull,
0x2030383730303030ull,0x303431783009090aull,0x7830203130363230ull,0x3038376330303434ull,
0x6330306365783020ull,0x3030783020393430ull,0x0a20303837383432ull,0x3030636578300909ull,
0x3078302035343065ull,0x2030383734343230ull,0x3030643038647830ull,0x3030327830206430ull,
0x090a203038373030ull,0x6330306365783009ull,0x3030783020313430ull,0x3020303837303432ull,
0x3330653030636578ull,0x3332303078302035ull,0x09090a2030383734ull,0x3030653038647830ull,
0x3030327830206430ull,0x7830203038373030ull,0x3130383230303431ull,0x6330303434783020ull,
0x3009090a20303837ull,0x3430633030636578ull,0x3432303078302039ull,0x6578302030383738ull,
0x2035343065303063ull,0x3734343230307830ull,0x783009090a203038ull,0x6430303066303864ull,
0x3030303032783020ull,0x6365783020303837ull,0x3020313430633030ull,0x3837303432303078ull,
0x65783009090a2030ull,0x2035333065303063ull,0x3734333230307830ull,0x3138647830203038ull,
0x7830206430303030ull,0x3038373030303032ull,0x3431783009090a20ull,0x3020313061323030ull,
0x3837633030343478ull,0x3030636578302030ull,0x3078302039343063ull,0x2030383738343230ull,
0x306365783009090aull,0x7830203534306530ull,0x3038373434323030ull,0x3031313864783020ull,
0x3032783020643030ull,0x0a20303837303030ull,0x3030636578300909ull,0x3078302031343063ull,
0x2030383730343230ull,0x3065303063657830ull,0x3230307830203533ull,0x090a203038373433ull,
0x3032313864783009ull,0x3032783020643030ull,0x3020303837303030ull,0x3063323030343178ull,
0x3030343478302031ull,0x09090a2030383763ull,0x3063303063657830ull,0x3230307830203934ull,
0x7830203038373834ull,0x3534306530306365ull,0x3434323030783020ull,0x3009090a20303837ull,
0x3030303331386478ull,0x3030303278302064ull,0x6578302030383730ull,0x2031343063303063ull,
0x3730343230307830ull,0x783009090a203038ull,0x3533306530306365ull,0x3433323030783020ull,
0x3864783020303837ull,0x3020643030303431ull,0x3837303030303278ull,0x31783009090a2030ull,
0x2031306532303034ull,0x3763303034347830ull,0x3063657830203038ull,0x7830203934306330ull,
0x3038373834323030ull,0x6365783009090a20ull,0x3020353430653030ull,0x3837343432303078ull,
0x3531386478302030ull,0x3278302064303030ull,0x2030383730303030ull,0x306365783009090aull,
0x7830203134306330ull,0x3038373034323030ull,0x6530306365783020ull,0x3030783020353330ull,
0x0a20303837343332ull,0x3631386478300909ull,0x3278302064303030ull,0x2030383730303030ull,
0x3033303034317830ull,0x3034347830203130ull,0x090a203038376330ull,0x6330306365783009ull,
0x3030783020393430ull,0x3020303837383432ull,0x3430653030636578ull,0x3432303078302035ull,
0x09090a2030383734ull,0x3030373138647830ull,0x3030327830206430ull,0x7830203038373030ull,
0x3134306330306365ull,0x3034323030783020ull,0x3009090a20303837ull,0x3330653030636578ull,
0x3332303078302035ull,0x6478302030383734ull,0x2064303030383138ull,0x3730303030327830ull,
0x783009090a203038ull,0x3130323330303431ull,0x6330303434783020ull,0x6365783020303837ull,
0x3020393430633030ull,0x3837383432303078ull,0x65783009090a2030ull,0x2035343065303063ull,
0x3734343230307830ull,0x3138647830203038ull,0x7830206430303039ull,0x3038373030303032ull,
0x6365783009090a20ull,0x3020313430633030ull,0x3837303432303078ull,0x3030636578302030ull,
0x3078302035333065ull,0x2030383734333230ull,0x313864783009090aull,0x7830206430303061ull,
0x3038373030303032ull,0x3330303431783020ull,0x3434783020313034ull,0x0a20303837633030ull,
0x3030636578300909ull,0x3078302039343063ull,0x2030383738343230ull,0x3065303063657830ull,
0x3230307830203534ull,0x090a203038373434ull,0x3062313864783009ull,0x3032783020643030ull,
0x3020303837303030ull,0x3430633030636578ull,0x3432303078302031ull,0x09090a2030383730ull,
0x3065303063657830ull,0x3230307830203533ull,0x7830203038373433ull,0x6430303063313864ull,
0x3030303032783020ull,0x3009090a20303837ull,0x3036333030343178ull,0x3030343478302031ull,
0x6578302030383763ull,0x2039343063303063ull,0x3738343230307830ull,0x783009090a203038ull,
0x3534306530306365ull,0x3434323030783020ull,0x3864783020303837ull,0x3020643030306431ull,
0x3837303030303278ull,0x65783009090a2030ull,0x2031343063303063ull,0x3730343230307830ull,
0x3063657830203038ull,0x7830203533306530ull,0x3038373433323030ull,0x3864783009090a20ull,
0x3020643030306531ull,0x3837303030303278ull,0x3030343178302030ull,0x3478302031303833ull,
0x2030383763303034ull,0x306365783009090aull,0x7830203934306330ull,0x3038373834323030ull,
0x6530306365783020ull,0x3030783020353430ull,0x0a20303837343432ull,0x6631386478300909ull,
0x3278302064303030ull,0x2030383730303030ull,0x3063303063657830ull,0x3230307830203134ull,
0x090a203038373034ull,0x6530306365783009ull,0x3030783020353330ull,0x3020303837343332ull,
0x3065666631363878ull,0x3030303078302033ull,0x09090a2030303030ull,0x3836383034647830ull,
0x3030327830206430ull,0x7830203038373030ull,0x3131303031303864ull,0x3030303032783020ull,
0x3009090a20303837ull,0x3030303030633178ull,0x3030343478302031ull,0x6578302030383763ull,
0x2039323063303030ull,0x3738323230307830ull,0x783009090a203438ull,0x3938306530303065ull,
0x3432323030783020ull,0x3864783020343837ull,0x3020313130303230ull,0x3837303030303278ull,
0x31783009090a2030ull,0x2035323230303063ull,0x3763303034347830ull,0x3038657830203038ull,
0x7830203133306330ull,0x3038373033323030ull,0x3865783009090a20ull,0x3020313030653030ull,
0x3837633232303078ull,0x3930306578302030ull,0x3078302064323063ull,0x2034383730333230ull,
0x303065783009090aull,0x7830203130306539ull,0x3438373030323030ull,0x3033303864783020ull,
0x3032783020313130ull,0x0a20303837303030ull,0x3930306578300909ull,0x3078302039323063ull,
0x2034383738323230ull,0x3065393030657830ull,0x3230307830203938ull,0x090a203438373838ull,
0x3034303864783009ull,0x3032783020313130ull,0x3020303837303030ull,0x3234303030633178ull,
0x3030343478302035ull,0x09090a2030383763ull,0x3063393030657830ull,0x3230307830203133ull,
0x7830203438376332ull,0x6432306539303065ull,0x3030323030783020ull,0x3009090a20343837ull,
0x3130303530386478ull,0x3030303278302031ull,0x6578302030383730ull,0x2039323063393030ull,
0x3738323230307830ull,0x783009090a203438ull,0x3532306539303065ull,0x3838323030783020ull,
0x3864783020343837ull,0x3020313130303630ull,0x3837303030303278ull,0x31783009090a2030ull,
0x2031303630303063ull,0x3763303034347830ull,0x3030657830203038ull,0x7830203133306330ull,
0x3438373033323030ull,0x3065783009090a20ull,0x3020643230653030ull,0x3837633232303078ull,
0x3730386478302034ull,0x3278302031313030ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203932306330ull,0x3438373832323030ull,0x6530303065783020ull,0x3030783020353230ull,
0x0a20343837343232ull,0x3830386478300909ull,0x3278302031313030ull,0x2030383730303030ull,
0x3830303063317830ull,0x3034347830203130ull,0x090a203038376330ull,0x6330303065783009ull,
0x3030783020313330ull,0x3020343837303332ull,0x3230653030306578ull,0x3232303078302064ull,
0x09090a2034383763ull,0x3030393038647830ull,0x3030327830203131ull,0x7830203038373030ull,
0x3932306330303065ull,0x3832323030783020ull,0x3009090a20343837ull,0x3230653030306578ull,
0x3232303078302035ull,0x6478302034383734ull,0x2031313030613038ull,0x3730303030327830ull,
0x783009090a203038ull,0x3130613030306331ull,0x6330303434783020ull,0x3065783020303837ull,
0x3020313330633030ull,0x3837303332303078ull,0x65783009090a2034ull,0x2064323065303030ull,
0x3763323230307830ull,0x3038647830203438ull,0x7830203131303062ull,0x3038373030303032ull,
0x3065783009090a20ull,0x3020393230633030ull,0x3837383232303078ull,0x3030306578302034ull,
0x3078302035323065ull,0x2034383734323230ull,0x303864783009090aull,0x7830203131303063ull,
0x3038373030303032ull,0x3030306331783020ull,0x3434783020313063ull,0x0a20303837633030ull,
0x3030306578300909ull,0x3078302031333063ull,0x2034383730333230ull,0x3065303030657830ull,
0x3230307830206432ull,0x090a203438376332ull,0x3064303864783009ull,0x3032783020313130ull,
0x3020303837303030ull,0x3230633030306578ull,0x3232303078302039ull,0x09090a2034383738ull,
0x3065303030657830ull,0x3230307830203532ull,0x7830203438373432ull,0x3131303065303864ull,
0x3030303032783020ull,0x3009090a20303837ull,0x3065303030633178ull,0x3030343478302031ull,
0x6578302030383763ull,0x2031333063303030ull,0x3730333230307830ull,0x783009090a203438ull,
0x6432306530303065ull,0x6332323030783020ull,0x3864783020343837ull,0x3020313130306630ull,
0x3837303030303278ull,0x65783009090a2030ull,0x2039323063303030ull,0x3738323230307830ull,
0x3030657830203438ull,0x7830203532306530ull,0x3438373432323030ull,0x3864783009090a20ull,
0x3020313130303031ull,0x3837303030303278ull,0x3030633178302030ull,0x3478302031303031ull,
0x2030383763303034ull,0x303065783009090aull,0x7830203133306330ull,0x3438373033323030ull,
0x6530303065783020ull,0x3030783020643230ull,0x0a20343837633232ull,0x3131386478300909ull,
0x3278302031313030ull,0x2030383730303030ull,0x3063303030657830ull,0x3230307830203932ull,
0x090a203438373832ull,0x6530303065783009ull,0x3030783020353230ull,0x3020343837343232ull,
0x3130303231386478ull,0x3030303278302031ull,0x09090a2030383730ull,0x3231303063317830ull,
0x3034347830203130ull,0x7830203038376330ull,0x3133306330303065ull,0x3033323030783020ull,
0x3009090a20343837ull,0x3230653030306578ull,0x3232303078302064ull,0x6478302034383763ull,
0x2031313030333138ull,0x3730303030327830ull,0x783009090a203038ull,0x3932306330303065ull,
0x3832323030783020ull,0x3065783020343837ull,0x3020353230653030ull,0x3837343232303078ull,
0x64783009090a2034ull,0x2031313030343138ull,0x3730303030327830ull,0x3063317830203038ull,
0x7830203130343130ull,0x3038376330303434ull,0x3065783009090a20ull,0x3020313330633030ull,
0x3837303332303078ull,0x3030306578302034ull,0x3078302064323065ull,0x2034383763323230ull,
0x313864783009090aull,0x7830203131303035ull,0x3038373030303032ull,0x6330303065783020ull,
0x3030783020393230ull,0x0a20343837383232ull,0x3030306578300909ull,0x3078302035323065ull,
0x2034383734323230ull,0x3030363138647830ull,0x3030327830203131ull,0x090a203038373030ull,
0x3130306331783009ull,0x3434783020313036ull,0x3020303837633030ull,0x3330633030306578ull,
0x3332303078302031ull,0x09090a2034383730ull,0x3065303030657830ull,0x3230307830206432ull,
0x7830203438376332ull,0x3131303037313864ull,0x3030303032783020ull,0x3009090a20303837ull,
0x3230633030306578ull,0x3232303078302039ull,0x6578302034383738ull,0x2035323065303030ull,
0x3734323230307830ull,0x783009090a203438ull,0x3131303038313864ull,0x3030303032783020ull,
0x6331783020303837ull,0x3020313038313030ull,0x3837633030343478ull,0x65783009090a2030ull,
0x2031333063303030ull,0x3730333230307830ull,0x3030657830203438ull,0x7830206432306530ull,
0x3438376332323030ull,0x3864783009090a20ull,0x3020313130303931ull,0x3837303030303278ull,
0x3030306578302030ull,0x3078302039323063ull,0x2034383738323230ull,0x303065783009090aull,
0x7830203532306530ull,0x3438373432323030ull,0x3061313864783020ull,0x3032783020313130ull,
0x0a20303837303030ull,0x3030633178300909ull,0x3478302031306131ull,0x2030383763303034ull,
0x3063303030657830ull,0x3230307830203133ull,0x090a203438373033ull,0x6530303065783009ull,
0x3030783020643230ull,0x3020343837633232ull,0x3130306231386478ull,0x3030303278302031ull,
0x09090a2030383730ull,0x3063303030657830ull,0x3230307830203932ull,0x7830203438373832ull,
0x3532306530303065ull,0x3432323030783020ull,0x3009090a20343837ull,0x3130306331386478ull,
0x3030303278302031ull,0x3178302030383730ull,0x2031306331303063ull,0x3763303034347830ull,
0x783009090a203038ull,0x3133306330303065ull,0x3033323030783020ull,0x3065783020343837ull,
0x3020643230653030ull,0x3837633232303078ull,0x64783009090a2034ull,0x2031313030643138ull,
0x3730303030327830ull,0x3030657830203038ull,0x7830203932306330ull,0x3438373832323030ull,
0x3065783009090a20ull,0x3020353230653030ull,0x3837343232303078ull,0x3030633178302034ull,
0x3478302031306531ull,0x2030383763303034ull,0x313864783009090aull,0x7830206430303065ull,
0x3038373030303032ull,0x6330306365783020ull,0x3030783020313330ull,0x0a20303837303332ull,
0x3030636578300909ull,0x3078302064323065ull,0x2030383763323230ull,0x3030663138647830ull,
0x3030327830206430ull,0x090a203038373030ull,0x6330306365783009ull,0x3030783020393230ull,
0x3020303837383232ull,0x3230653030636578ull,0x3232303078302035ull,0x09090a2030383734ull,
0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,0x6430383630313464ull,
0x3030303032783020ull,0x3009090a20303837ull,0x3130303130386478ull,0x3030303278302031ull,
0x3178302030383730ull,0x2031303030303063ull,0x3763303034347830ull,0x783009090a203038ull,
0x3931306330303065ull,0x3831323030783020ull,0x3065783020343837ull,0x3020393830653030ull,
0x3837343132303078ull,0x64783009090a2034ull,0x2031313030323038ull,0x3730303030327830ull,
0x3063317830203038ull,0x7830203531323030ull,0x3038376330303434ull,0x3865783009090a20ull,
0x3020313230633030ull,0x3837303232303078ull,0x3030386578302030ull,0x3078302031303065ull,
0x2030383763313230ull,0x303065783009090aull,0x7830206431306335ull,0x3438373032323030ull,
0x6535303065783020ull,0x3030783020313030ull,0x0a20343837303032ull,0x3330386478300909ull,
0x3278302031313030ull,0x2030383730303030ull,0x3063353030657830ull,0x3230307830203931ull,
0x090a203438373831ull,0x6535303065783009ull,0x3030783020393830ull,0x3020343837383832ull,
0x3130303430386478ull,0x3030303278302031ull,0x09090a2030383730ull,0x3430303063317830ull,
0x3034347830203531ull,0x7830203038376330ull,0x3132306335303065ull,0x6331323030783020ull,
0x3009090a20343837ull,0x3130653530306578ull,0x3032303078302064ull,0x6478302034383730ull,
0x2031313030353038ull,0x3730303030327830ull,0x783009090a203038ull,0x3931306335303065ull,
0x3831323030783020ull,0x3065783020343837ull,0x3020353130653530ull,0x3837383832303078ull,
0x64783009090a2034ull,0x2031313030363038ull,0x3730303030327830ull,0x3063317830203038ull,
0x7830203130363030ull,0x3038376330303434ull,0x3065783009090a20ull,0x3020313230633030ull,
0x3837303232303078ull,0x3030306578302034ull,0x3078302064313065ull,0x2034383763313230ull,
0x303864783009090aull,0x7830203131303037ull,0x3038373030303032ull,0x6330303065783020ull,
0x3030783020393130ull,0x0a20343837383132ull,0x3030306578300909ull,0x3078302035313065ull,
0x2034383734313230ull,0x3030383038647830ull,0x3030327830203131ull,0x090a203038373030ull,
0x3030306331783009ull,0x3434783020313038ull,0x3020303837633030ull,0x3230633030306578ull,
0x3232303078302031ull,0x09090a2034383730ull,0x3065303030657830ull,0x3230307830206431ull,
0x7830203438376331ull,0x3131303039303864ull,0x3030303032783020ull,0x3009090a20303837ull,
0x3130633030306578ull,0x3132303078302039ull,0x6578302034383738ull,0x2035313065303030ull,
0x3734313230307830ull,0x783009090a203438ull,0x3131303061303864ull,0x3030303032783020ull,
0x6331783020303837ull,0x3020313061303030ull,0x3837633030343478ull,0x65783009090a2030ull,
0x2031323063303030ull,0x3730323230307830ull,0x3030657830203438ull,0x7830206431306530ull,
0x3438376331323030ull,0x3864783009090a20ull,0x3020313130306230ull,0x3837303030303278ull,
0x3030306578302030ull,0x3078302039313063ull,0x2034383738313230ull,0x303065783009090aull,
0x7830203531306530ull,0x3438373431323030ull,0x3063303864783020ull,0x3032783020313130ull,
0x0a20303837303030ull,0x3030633178300909ull,0x3478302031306330ull,0x2030383763303034ull,
0x3063303030657830ull,0x3230307830203132ull,0x090a203438373032ull,0x6530303065783009ull,
0x3030783020643130ull,0x3020343837633132ull,0x3130306430386478ull,0x3030303278302031ull,
0x09090a2030383730ull,0x3063303030657830ull,0x3230307830203931ull,0x7830203438373831ull,
0x3531306530303065ull,0x3431323030783020ull,0x3009090a20343837ull,0x3130306530386478ull,
0x3030303278302031ull,0x3178302030383730ull,0x2031306530303063ull,0x3763303034347830ull,
0x783009090a203038ull,0x3132306330303065ull,0x3032323030783020ull,0x3065783020343837ull,
0x3020643130653030ull,0x3837633132303078ull,0x64783009090a2034ull,0x2031313030663038ull,
0x3730303030327830ull,0x3030657830203038ull,0x7830203931306330ull,0x3438373831323030ull,
0x3065783009090a20ull,0x3020353130653030ull,0x3837343132303078ull,0x3031386478302034ull,
0x3278302031313030ull,0x2030383730303030ull,0x306331783009090aull,0x7830203130303130ull,
0x3038376330303434ull,0x6330303065783020ull,0x3030783020313230ull,0x0a20343837303232ull,
0x3030306578300909ull,0x3078302064313065ull,0x2034383763313230ull,0x3030313138647830ull,
0x3030327830203131ull,0x090a203038373030ull,0x6330303065783009ull,0x3030783020393130ull,
0x3020343837383132ull,0x3130653030306578ull,0x3132303078302035ull,0x09090a2034383734ull,
0x3030323138647830ull,0x3030327830203131ull,0x7830203038373030ull,0x3130323130306331ull,
0x6330303434783020ull,0x3009090a20303837ull,0x3230633030306578ull,0x3232303078302031ull,
0x6578302034383730ull,0x2064313065303030ull,0x3763313230307830ull,0x783009090a203438ull,
0x3131303033313864ull,0x3030303032783020ull,0x3065783020303837ull,0x3020393130633030ull,
0x3837383132303078ull,0x65783009090a2034ull,0x2035313065303030ull,0x3734313230307830ull,
0x3138647830203438ull,0x7830203131303034ull,0x3038373030303032ull,0x6331783009090a20ull,
0x3020313034313030ull,0x3837633030343478ull,0x3030306578302030ull,0x3078302031323063ull,
0x2034383730323230ull,0x303065783009090aull,0x7830206431306530ull,0x3438376331323030ull,
0x3035313864783020ull,0x3032783020313130ull,0x0a20303837303030ull,0x3030306578300909ull,
0x3078302039313063ull,0x2034383738313230ull,0x3065303030657830ull,0x3230307830203531ull,
0x090a203438373431ull,0x3036313864783009ull,0x3032783020313130ull,0x3020303837303030ull,
0x3036313030633178ull,0x3030343478302031ull,0x09090a2030383763ull,0x3063303030657830ull,
0x3230307830203132ull,0x7830203438373032ull,0x6431306530303065ull,0x6331323030783020ull,
0x3009090a20343837ull,0x3130303731386478ull,0x3030303278302031ull,0x6578302030383730ull,
0x2039313063303030ull,0x3738313230307830ull,0x783009090a203438ull,0x3531306530303065ull,
0x3431323030783020ull,0x3864783020343837ull,0x3020313130303831ull,0x3837303030303278ull,
0x31783009090a2030ull,0x2031303831303063ull,0x3763303034347830ull,0x3030657830203038ull,
0x7830203132306330ull,0x3438373032323030ull,0x3065783009090a20ull,0x3020643130653030ull,
0x3837633132303078ull,0x3931386478302034ull,0x3278302031313030ull,0x2030383730303030ull,
0x303065783009090aull,0x7830203931306330ull,0x3438373831323030ull,0x6530303065783020ull,
0x3030783020353130ull,0x0a20343837343132ull,0x6131386478300909ull,0x3278302031313030ull,
0x2030383730303030ull,0x6131303063317830ull,0x3034347830203130ull,0x090a203038376330ull,
0x6330303065783009ull,0x3030783020313230ull,0x3020343837303232ull,0x3130653030306578ull,
0x3132303078302064ull,0x09090a2034383763ull,0x3030623138647830ull,0x3030327830203131ull,
0x7830203038373030ull,0x3931306330303065ull,0x3831323030783020ull,0x3009090a20343837ull,
0x3130653030306578ull,0x3132303078302035ull,0x6478302034383734ull,0x2031313030633138ull,
0x3730303030327830ull,0x783009090a203038ull,0x3130633130306331ull,0x6330303434783020ull,
0x3065783020303837ull,0x3020313230633030ull,0x3837303232303078ull,0x65783009090a2034ull,
0x2064313065303030ull,0x3763313230307830ull,0x3138647830203438ull,0x7830203131303064ull,
0x3038373030303032ull,0x3065783009090a20ull,0x3020393130633030ull,0x3837383132303078ull,
0x3030306578302034ull,0x3078302035313065ull,0x2034383734313230ull,0x306331783009090aull,
0x7830203130653130ull,0x3038376330303434ull,0x3065313864783020ull,0x3032783020643030ull,
0x0a20303837303030ull,0x3030636578300909ull,0x3078302031323063ull,0x2030383730323230ull,
0x3065303063657830ull,0x3230307830206431ull,0x090a203038376331ull,0x3066313864783009ull,
0x3032783020643030ull,0x3020303837303030ull,0x3130633030636578ull,0x3132303078302039ull,
0x09090a2030383738ull,0x3065303063657830ull,0x3230307830203531ull,0x7830203038373431ull,
0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,0x3038363831346478ull,
0x3030303278302064ull,0x6478302030383730ull,0x2031313030313038ull,0x3730303030327830ull,
0x783009090a203038ull,0x3130303030306331ull,0x6330303434783020ull,0x3065783020303837ull,
0x3020393030633030ull,0x3837383032303078ull,0x65783009090a2034ull,0x2039383065303030ull,
0x3734303230307830ull,0x3038647830203438ull,0x7830203131303032ull,0x3038373030303032ull,
0x6331783009090a20ull,0x3020353032303030ull,0x3837633030343478ull,0x3030386578302030ull,
0x3078302031313063ull,0x2030383730313230ull,0x303865783009090aull,0x7830203130306530ull,
0x3038376330323030ull,0x6331303065783020ull,0x3030783020643030ull,0x0a20343837303132ull,
0x3130306578300909ull,0x3078302031303065ull,0x2034383730303230ull,0x3030333038647830ull,
0x3030327830203131ull,0x090a203038373030ull,0x6331303065783009ull,0x3030783020393030ull,
0x3020343837383032ull,0x3830653130306578ull,0x3832303078302039ull,0x09090a2034383738ull,
0x3030343038647830ull,0x3030327830203131ull,0x7830203038373030ull,0x3530343030306331ull,
0x6330303434783020ull,0x3009090a20303837ull,0x3130633130306578ull,0x3032303078302031ull,
0x6578302034383763ull,0x2064303065313030ull,0x3730303230307830ull,0x783009090a203438ull,
0x3131303035303864ull,0x3030303032783020ull,0x3065783020303837ull,0x3020393030633130ull,
0x3837383032303078ull,0x65783009090a2034ull,0x2035303065313030ull,0x3738383230307830ull,
0x3038647830203438ull,0x7830203131303036ull,0x3038373030303032ull,0x6331783009090a20ull,
0x3020313036303030ull,0x3837633030343478ull,0x3030306578302030ull,0x3078302031313063ull,
0x2034383730313230ull,0x303065783009090aull,0x7830206430306530ull,0x3438376330323030ull,
0x3037303864783020ull,0x3032783020313130ull,0x0a20303837303030ull,0x3030306578300909ull,
0x3078302039303063ull,0x2034383738303230ull,0x3065303030657830ull,0x3230307830203530ull,
0x090a203438373430ull,0x3038303864783009ull,0x3032783020313130ull,0x3020303837303030ull,
0x3038303030633178ull,0x3030343478302031ull,0x09090a2030383763ull,0x3063303030657830ull,
0x3230307830203131ull,0x7830203438373031ull,0x6430306530303065ull,0x6330323030783020ull,
0x3009090a20343837ull,0x3130303930386478ull,0x3030303278302031ull,0x6578302030383730ull,
0x2039303063303030ull,0x3738303230307830ull,0x783009090a203438ull,0x3530306530303065ull,
0x3430323030783020ull,0x3864783020343837ull,0x3020313130306130ull,0x3837303030303278ull,
0x31783009090a2030ull,0x2031306130303063ull,0x3763303034347830ull,0x3030657830203038ull,
0x7830203131306330ull,0x3438373031323030ull,0x3065783009090a20ull,0x3020643030653030ull,
0x3837633032303078ull,0x6230386478302034ull,0x3278302031313030ull,0x2030383730303030ull,
0x303065783009090aull,0x7830203930306330ull,0x3438373830323030ull,0x6530303065783020ull,
0x3030783020353030ull,0x0a20343837343032ull,0x6330386478300909ull,0x3278302031313030ull,
0x2030383730303030ull,0x6330303063317830ull,0x3034347830203130ull,0x090a203038376330ull,
0x6330303065783009ull,0x3030783020313130ull,0x3020343837303132ull,0x3030653030306578ull,
0x3032303078302064ull,0x09090a2034383763ull,0x3030643038647830ull,0x3030327830203131ull,
0x7830203038373030ull,0x3930306330303065ull,0x3830323030783020ull,0x3009090a20343837ull,
0x3030653030306578ull,0x3032303078302035ull,0x6478302034383734ull,0x2031313030653038ull,
0x3730303030327830ull,0x783009090a203038ull,0x3130653030306331ull,0x6330303434783020ull,
0x3065783020303837ull,0x3020313130633030ull,0x3837303132303078ull,0x65783009090a2034ull,
0x2064303065303030ull,0x3763303230307830ull,0x3038647830203438ull,0x7830203131303066ull,
0x3038373030303032ull,0x3065783009090a20ull,0x3020393030633030ull,0x3837383032303078ull,
0x3030306578302034ull,0x3078302035303065ull,0x2034383734303230ull,0x313864783009090aull,
0x7830203131303030ull,0x3038373030303032ull,0x3130306331783020ull,0x3434783020313030ull,
0x0a20303837633030ull,0x3030306578300909ull,0x3078302031313063ull,0x2034383730313230ull,
0x3065303030657830ull,0x3230307830206430ull,0x090a203438376330ull,0x3031313864783009ull,
0x3032783020313130ull,0x3020303837303030ull,0x3030633030306578ull,0x3032303078302039ull,
0x09090a2034383738ull,0x3065303030657830ull,0x3230307830203530ull,0x7830203438373430ull,
0x3131303032313864ull,0x3030303032783020ull,0x3009090a20303837ull,0x3032313030633178ull,
0x3030343478302031ull,0x6578302030383763ull,0x2031313063303030ull,0x3730313230307830ull,
0x783009090a203438ull,0x6430306530303065ull,0x6330323030783020ull,0x3864783020343837ull,
0x3020313130303331ull,0x3837303030303278ull,0x65783009090a2030ull,0x2039303063303030ull,
0x3738303230307830ull,0x3030657830203438ull,0x7830203530306530ull,0x3438373430323030ull,
0x3864783009090a20ull,0x3020313130303431ull,0x3837303030303278ull,0x3030633178302030ull,
0x3478302031303431ull,0x2030383763303034ull,0x303065783009090aull,0x7830203131306330ull,
0x3438373031323030ull,0x6530303065783020ull,0x3030783020643030ull,0x0a20343837633032ull,
0x3531386478300909ull,0x3278302031313030ull,0x2030383730303030ull,0x3063303030657830ull,
0x3230307830203930ull,0x090a203438373830ull,0x6530303065783009ull,0x3030783020353030ull,
0x3020343837343032ull,0x3130303631386478ull,0x3030303278302031ull,0x09090a2030383730ull,
0x3631303063317830ull,0x3034347830203130ull,0x7830203038376330ull,0x3131306330303065ull,
0x3031323030783020ull,0x3009090a20343837ull,0x3030653030306578ull,0x3032303078302064ull,
0x6478302034383763ull,0x2031313030373138ull,0x3730303030327830ull,0x783009090a203038ull,
0x3930306330303065ull,0x3830323030783020ull,0x3065783020343837ull,0x3020353030653030ull,
0x3837343032303078ull,0x64783009090a2034ull,0x2031313030383138ull,0x3730303030327830ull,
0x3063317830203038ull,0x7830203130383130ull,0x3038376330303434ull,0x3065783009090a20ull,
0x3020313130633030ull,0x3837303132303078ull,0x3030306578302034ull,0x3078302064303065ull,
0x2034383763303230ull,0x313864783009090aull,0x7830203131303039ull,0x3038373030303032ull,
0x6330303065783020ull,0x3030783020393030ull,0x0a20343837383032ull,0x3030306578300909ull,
0x3078302035303065ull,0x2034383734303230ull,0x3030613138647830ull,0x3030327830203131ull,
0x090a203038373030ull,0x3130306331783009ull,0x3434783020313061ull,0x3020303837633030ull,
0x3130633030306578ull,0x3132303078302031ull,0x09090a2034383730ull,0x3065303030657830ull,
0x3230307830206430ull,0x7830203438376330ull,0x3131303062313864ull,0x3030303032783020ull,
0x3009090a20303837ull,0x3030633030306578ull,0x3032303078302039ull,0x6578302034383738ull,
0x2035303065303030ull,0x3734303230307830ull,0x783009090a203438ull,0x3131303063313864ull,
0x3030303032783020ull,0x6331783020303837ull,0x3020313063313030ull,0x3837633030343478ull,
0x65783009090a2030ull,0x2031313063303030ull,0x3730313230307830ull,0x3030657830203438ull,
0x7830206430306530ull,0x3438376330323030ull,0x3864783009090a20ull,0x3020313130306431ull,
0x3837303030303278ull,0x3030306578302030ull,0x3078302039303063ull,0x2034383738303230ull,
0x303065783009090aull,0x7830203530306530ull,0x3438373430323030ull,0x3130306331783020ull,
0x3434783020313065ull,0x0a20303837633030ull,0x6531386478300909ull,0x3278302064303030ull,
0x2030383730303030ull,0x3063303063657830ull,0x3230307830203131ull,0x090a203038373031ull,
0x6530306365783009ull,0x3030783020643030ull,0x3020303837633032ull,0x3030306631386478ull,
0x3030303278302064ull,0x09090a2030383730ull,0x3063303063657830ull,0x3230307830203930ull,
0x7830203038373830ull,0x3530306530306365ull,0x3430323030783020ull,0x3009090a20303837ull,
0x3832633031303278ull,0x3030303078302035ull,0x3378302033303030ull,0x2064663764313230ull,
0x3730313263367830ull,0x783009090a203863ull,0x3535616130303032ull,0x3030303030783020ull,
0x3032783020373030ull,0x3020313565313030ull,0x3837303530343078ull,0x31783009090a2030ull,
0x2033303030343030ull,0x3230303030307830ull,0x3230317830203038ull,0x7830203330306232ull,
0x3038373030303030ull,0x3034783009090a20ull,0x3020313065313334ull,0x3030303030303078ull,
0x3330303378302033ull,0x6378302039356531ull,0x2030383730303134ull,0x303033783009090aull,
0x7830203537653132ull,0x3038373030313463ull,0x6436303033783020ull,0x3463783020643338ull,
0x0a20303837303033ull,0x3230303378300909ull,0x6378302031373030ull,0x2030383730303134ull,
0x3831303030317830ull,0x3034347830203130ull,0x090a203038376330ull,0x3064313034783009ull,
0x3030783020313530ull,0x3020303837303030ull,0x3532306331303678ull,0x3530303078302031ull,
0x09090a2030383730ull,0x3832303130337830ull,0x3134637830203135ull,0x7830203038373030ull,
0x3130303063313036ull,0x3035303030783020ull,0x3009090a20303837ull,0x3030303030303278ull,
0x3430343078302031ull,0x3378302030383763ull,0x2031303030323030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3130306430303032ull,0x3030323430783020ull,0x3064783020303837ull,
0x3020393430306530ull,0x3837303063306178ull,0x32783009090a2030ull,0x2039333030303030ull,
0x3734373034307830ull,0x3030647830203038ull,0x7830203534633165ull,0x3038373030633061ull,
0x3032783009090a20ull,0x3020393330303030ull,0x3837383530343078ull,0x6530306478302030ull,
0x6178302031346331ull,0x2030383730306330ull,0x303032783009090aull,0x7830203933303030ull,
0x3038373037303430ull,0x3165303064783020ull,0x3061783020353363ull,0x0a20303837303063ull,
0x3030303278300909ull,0x3078302031303030ull,0x2030383763333034ull,0x3030653030647830ull,
0x6330617830203133ull,0x090a203038373030ull,0x3330303032783009ull,0x3430783020313361ull,
0x3020303837303030ull,0x3238316530306478ull,0x3063306178302064ull,0x09090a2030383730ull,
0x6332303030327830ull,0x3034307830206432ull,0x7830203038373030ull,0x3932363165303064ull,
0x3030633061783020ull,0x3009090a20303837ull,0x3238333030303278ull,0x3030343078302039ull,
0x6478302030383730ull,0x2035323431653030ull,0x3730306330617830ull,0x783009090a203038ull,
0x3130303030303032ull,0x6333303430783020ull,0x3064783020303837ull,0x3020313230306530ull,
0x3837303063306178ull,0x32783009090a2030ull,0x2031326133303030ull,0x3730303034307830ull,
0x3030647830203038ull,0x7830206431303165ull,0x3038373030633061ull,0x3032783009090a20ull,
0x3020643163323030ull,0x3837303030343078ull,0x6530306478302030ull,0x6178302039316530ull,
0x2030383730306330ull,0x303032783009090aull,0x7830203831386230ull,0x3030653930303032ull,
0x3065303064783020ull,0x3061783020353163ull,0x0a20303837303063ull,0x6530306478300909ull,
0x6178302031313030ull,0x2030383730306330ull,0x6133303030327830ull,0x3034307830203131ull,
0x090a203038373030ull,0x3065303064783009ull,0x3061783020643038ull,0x3020303837303063ull,
0x3063613030303278ull,0x3030303278302063ull,0x09090a2030303862ull,0x3630653030647830ull,
0x6330617830203930ull,0x7830203038373030ull,0x3530303065303064ull,0x3030633061783020ull,
0x0a7d090a20313837ull,0x7b2065646f630a7dull,0x3d20656d616e090aull,0x6d5f6b36315a5f20ull,
0x755f746c754d7461ull,0x5366506c6c6f726eull,0x090a6969695f535full,0x30203d206d656d6cull,
0x3d206d656d73090aull,0x72090a3432313320ull,0x3531203d20206765ull,0x3d2020726162090aull,
0x736e6f63090a3120ull,0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,
0x6d756e6765730909ull,0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,
0x2020207365747962ull,0x656d09090a34203dull,0x300909090a7b206dull,0x6633303030303078ull,
0x090a7d09090a2066ull,0x6f636e6962090a7dull,0x3009090a7b206564ull,0x3132303038306478ull,
0x3034303078302031ull,0x3178302030383730ull,0x2034303432303031ull,0x3666303031317830ull,
0x783009090a203430ull,0x3931383030303061ull,0x3030303430783020ull,0x3031783020303837ull,
0x3020393038313030ull,0x3837633030343478ull,0x61783009090a2030ull,0x2031313234303030ull,
0x3730303234307830ull,0x3030367830203038ull,0x7830203531653431ull,0x3038373831323030ull,
0x3034783009090a20ull,0x3020303234313330ull,0x3061306330303478ull,0x3830303478302063ull,
0x3078302064316334ull,0x2030383730303230ull,0x303036783009090aull,0x7830203132363132ull,
0x3038373032303030ull,0x3030303061783020ull,0x3430783020313030ull,0x0a20303837303030ull,
0x3031303378300909ull,0x6378302064303630ull,0x2030383730303134ull,0x6530313030337830ull,
0x3134637830206431ull,0x090a203038373030ull,0x3130313033783009ull,0x3463783020313230ull,
0x3020303837303031ull,0x3038306330303678ull,0x3030303078302039ull,0x09090a2030383763ull,
0x6530303030327830ull,0x3034307830206430ull,0x7830203038373030ull,0x3132343132303036ull,
0x3032303030783020ull,0x3009090a20303837ull,0x3034383330303278ull,0x3830303278302034ull,
0x3378302030323038ull,0x2064663764633730ull,0x3763303263367830ull,0x783009090a203863ull,
0x6430386630303031ull,0x6333303630783020ull,0x3033783020303837ull,0x3020393032303230ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2035323031323030ull,0x3730303134637830ull,
0x3030317830203038ull,0x7830203530386630ull,0x3038376333303430ull,0x3132783009090a20ull,
0x3020303263653230ull,0x3238653930313278ull,0x3730303178302034ull,0x3078302033303035ull,
0x2030383230303030ull,0x303033783009090aull,0x7830203932633035ull,0x3038373030313463ull,
0x3030303032783020ull,0x3430783020393038ull,0x0a20303837303030ull,0x3430303378300909ull,
0x6378302064326330ull,0x2030383730303134ull,0x6330363030337830ull,0x3134637830203931ull,
0x090a203038373030ull,0x3861303032783009ull,0x3032783020303334ull,0x3020343334393030ull,
0x3030303030303278ull,0x3230343078302039ull,0x09090a2030383763ull,0x6338343330327830ull,
0x3030307830203931ull,0x7830203338303030ull,0x3530343032303030ull,0x3030303063783020ull,
0x3009090a20303837ull,0x3063303030303078ull,0x3030306378302064ull,0x3078302030383730ull,
0x2039303030323030ull,0x3730303030637830ull,0x783009090a203038ull,0x3932386436303033ull,
0x3030333463783020ull,0x3033783020303837ull,0x3020643238303230ull,0x3837303031346378ull,
0x31783009090a2030ull,0x2039303866303030ull,0x3763333034307830ull,0x3030647830203038ull,
0x7830203931323165ull,0x3038373030633038ull,0x3430783009090a20ull,0x3020313061313430ull,
0x3837383132346578ull,0x6631363878302030ull,0x3078302033306566ull,0x2030303030303030ull,
0x303032783009090aull,0x7830203931303130ull,0x3038376332303430ull,0x3165303064783020ull,
0x3038783020393330ull,0x0a20303837303063ull,0x6530306478300909ull,0x3878302039316330ull,
0x2030383730306330ull,0x6131323030307830ull,0x3030637830203131ull,0x090a203038373030ull,
0x3130303030783009ull,0x3465783020313061ull,0x3020343837383332ull,0x3138313230303078ull,
0x3030306378302031ull,0x09090a2030383730ull,0x6131303030307830ull,0x3234657830203130ull,
0x7830203438373831ull,0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3330303030633178ull,0x3030343478302039ull,0x6478302030383763ull,0x2031313836313038ull,
0x3730303030327830ull,0x783009090a203038ull,0x3931323030306331ull,0x6330303434783020ull,
0x3865783020303837ull,0x3020353061646530ull,0x3837343032303078ull,0x65783009090a2030ull,
0x2039336166653038ull,0x3763303230307830ull,0x3030657830203038ull,0x7830206430306336ull,
0x3438373430323030ull,0x3065783009090a20ull,0x3020393130653630ull,0x3837383332303078ull,
0x3230386478302034ull,0x3278302031313836ull,0x2030383730303030ull,0x306331783009090aull,
0x7830203530343030ull,0x3038376330303434ull,0x6331303065783020ull,0x3030783020643030ull,
0x0a20343837633032ull,0x3130306578300909ull,0x3078302039313065ull,0x2034383738313230ull,
0x3836333038647830ull,0x3030327830203131ull,0x090a203038373030ull,0x3030306331783009ull,
0x3434783020353036ull,0x3020303837633030ull,0x3030633130306578ull,0x3032303078302064ull,
0x09090a2034383763ull,0x3065313030657830ull,0x3230307830203931ull,0x7830203438373831ull,
0x3131383634303864ull,0x3030303032783020ull,0x3009090a20303837ull,0x3038303030633178ull,
0x3030343478302035ull,0x6578302030383763ull,0x2064303063313030ull,0x3763303230307830ull,
0x783009090a203438ull,0x3931306531303065ull,0x3831323030783020ull,0x3864783020343837ull,
0x3020313138363530ull,0x3837303030303278ull,0x31783009090a2030ull,0x2035306130303063ull,
0x3763303034347830ull,0x3030657830203038ull,0x7830206430306331ull,0x3438376330323030ull,
0x3065783009090a20ull,0x3020393130653130ull,0x3837383132303078ull,0x3630386478302034ull,
0x3278302031313836ull,0x2030383730303030ull,0x306331783009090aull,0x7830203530633030ull,
0x3038376330303434ull,0x6331303065783020ull,0x3030783020643030ull,0x0a20343837633032ull,
0x3130306578300909ull,0x3078302039313065ull,0x2034383738313230ull,0x3836373038647830ull,
0x3030327830203131ull,0x090a203038373030ull,0x3030306331783009ull,0x3434783020353065ull,
0x3020303837633030ull,0x3030633130306578ull,0x3032303078302064ull,0x09090a2034383763ull,
0x3065313030657830ull,0x3230307830203931ull,0x7830203438373831ull,0x3131383638303864ull,
0x3030303032783020ull,0x3009090a20303837ull,0x3030313030633178ull,0x3030343478302035ull,
0x6578302030383763ull,0x2064303063313030ull,0x3763303230307830ull,0x783009090a203438ull,
0x3931306531303065ull,0x3831323030783020ull,0x3864783020343837ull,0x3020313138363930ull,
0x3837303030303278ull,0x31783009090a2030ull,0x2035303231303063ull,0x3763303034347830ull,
0x3030657830203038ull,0x7830206430306331ull,0x3438376330323030ull,0x3065783009090a20ull,
0x3020393130653130ull,0x3837383132303078ull,0x6130386478302034ull,0x3278302031313836ull,
0x2030383730303030ull,0x306331783009090aull,0x7830203530343130ull,0x3038376330303434ull,
0x6331303065783020ull,0x3030783020643030ull,0x0a20343837633032ull,0x3130306578300909ull,
0x3078302039313065ull,0x2034383738313230ull,0x3836623038647830ull,0x3030327830203131ull,
0x090a203038373030ull,0x3130306331783009ull,0x3434783020353036ull,0x3020303837633030ull,
0x3030633130306578ull,0x3032303078302064ull,0x09090a2034383763ull,0x3065313030657830ull,
0x3230307830203931ull,0x7830203438373831ull,0x3131383663303864ull,0x3030303032783020ull,
0x3009090a20303837ull,0x3038313030633178ull,0x3030343478302035ull,0x6578302030383763ull,
0x2064303063313030ull,0x3763303230307830ull,0x783009090a203438ull,0x3931306531303065ull,
0x3831323030783020ull,0x3864783020343837ull,0x3020313138366430ull,0x3837303030303278ull,
0x31783009090a2030ull,0x2035306131303063ull,0x3763303034347830ull,0x3030657830203038ull,
0x7830206430306331ull,0x3438376330323030ull,0x3065783009090a20ull,0x3020393330653130ull,
0x3837383132303078ull,0x6530386478302034ull,0x3278302031313836ull,0x2030383730303030ull,
0x306331783009090aull,0x7830203530633130ull,0x3038376330303434ull,0x6331303065783020ull,
0x3030783020393130ull,0x0a20343837633032ull,0x3130306578300909ull,0x3078302039333065ull,
0x2034383738333230ull,0x3836663038647830ull,0x3030327830203131ull,0x090a203038373030ull,
0x3130306331783009ull,0x3434783020643065ull,0x3020303837633030ull,0x3030633330306578ull,
0x3132303078302035ull,0x09090a2034383738ull,0x3065333030657830ull,0x3230307830206430ull,
0x7830203438373833ull,0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3034383031303278ull,0x3030303078302039ull,0x3378302033303030ull,0x2064663764323030ull,
0x3730313263367830ull,0x783009090a203863ull,0x3532323930303032ull,0x3030303030783020ull,
0x3032783020373030ull,0x3020313234313030ull,0x3837303230343078ull,0x31783009090a2030ull,
0x2033303035323030ull,0x3230303030307830ull,0x3030317830203038ull,0x7830203930383130ull,
0x3038376330303434ull,0x3034783009090a20ull,0x3020393134313530ull,0x3837303030303078ull,
0x3430303678302030ull,0x3078302039313631ull,0x2030383738313030ull,0x313033783009090aull,
0x7830203931633030ull,0x3038373030313463ull,0x3030303032783020ull,0x3430783020313065ull,
0x0a20303837303030ull,0x3430303678300909ull,0x3078302039303431ull,0x2030383738313030ull,
0x3430303030327830ull,0x3034307830203130ull,0x090a203038373030ull,0x3032303033783009ull,
0x3463783020393030ull,0x3020303837303031ull,0x3130383430303278ull,0x3230313278302030ull,
0x09090a2030303066ull,0x3830323030337830ull,0x3134637830203930ull,0x7830203038373030ull,
0x3530303065303064ull,0x3030633061783020ull,0x3009090a20303837ull,0x3030643030303278ull,
0x3032343078302031ull,0x6478302030383738ull,0x2064303030653030ull,0x3730306330617830ull,
0x7d0a7d090a203138ull,0x0a7b2065646f630aull,0x203d20656d616e09ull,0x6d6d656773375a5full,
0x305369664b504e4eull,0x666669696650695full,0x3d206d656d6c090aull,0x6d656d73090a3020ull,
0x0a30363131203d20ull,0x203d202067657209ull,0x20726162090a3533ull,0x6f63090a31203d20ull,
0x09090a7b2074736eull,0x656d616e67657309ull,0x74736e6f63203d20ull,0x6e6765730909090aull,
0x0a31203d20206d75ull,0x657366666f090909ull,0x090a30203d202074ull,0x2073657479620909ull,
0x090a3231203d2020ull,0x090a7b206d656d09ull,0x3030303078300909ull,0x3078302066663330ull,
0x2030303030313030ull,0x3030303030307830ull,0x0a7d09090a203034ull,0x636e6962090a7d09ull,
0x09090a7b2065646full,0x3230303830647830ull,0x3430307830203530ull,0x7830203038373030ull,
0x3137653230313134ull,0x3030303030783020ull,0x3009090a20333030ull,0x3132303030306178ull,
0x3030343078302035ull,0x6178302030383730ull,0x2039313030303030ull,0x3730303034307830ull,
0x783009090a203038ull,0x3130613030303032ull,0x3037303430783020ull,0x3031783020303837ull,
0x3020393030383430ull,0x3030303030303078ull,0x36783009090a2033ull,0x2031303464303030ull,
0x3738313230387830ull,0x3030317830203038ull,0x7830203530653130ull,0x3038376330303434ull,
0x3034783009090a20ull,0x3020633030303530ull,0x3161303230303478ull,0x3430303678302030ull,
0x3078302064303230ull,0x2030633763303030ull,0x303036783009090aull,0x7830203532363034ull,
0x3065373031303030ull,0x3030313033783020ull,0x3463783020643136ull,0x0a20303837303031ull,
0x3031303378300909ull,0x6378302039323231ull,0x2030383730303134ull,0x3630303130337830ull,
0x3134657830203131ull,0x090a203038373030ull,0x3034303036783009ull,0x3030783020646631ull,
0x3020386437633130ull,0x3230306631303378ull,0x3031636578302031ull,0x09090a2030383730ull,
0x3530343030367830ull,0x3030307830206466ull,0x7830203866373832ull,0x3131383030303132ull,
0x3430343430783020ull,0x3009090a20303838ull,0x3032313031303378ull,0x3031346578302064ull,
0x3378302030383730ull,0x2064316330343030ull,0x3730303134637830ull,0x783009090a203038ull,
0x3532303132303033ull,0x3030313463783020ull,0x3036783020303837ull,0x3020313232303530ull,
0x3837313130633078ull,0x32783009090a2030ull,0x2064303630303031ull,0x3836303434307830ull,
0x3030327830203038ull,0x7830203031653836ull,0x6334303939303032ull,0x3036783009090a20ull,
0x3020643136303530ull,0x3837663030633078ull,0x6631303378302030ull,0x6578302064306564ull,
0x2030383730303363ull,0x303032783009090aull,0x7830203530613030ull,0x3038373031303430ull,
0x3034303033783020ull,0x3463783020353161ull,0x0a20303837303031ull,0x3330303378300909ull,
0x6378302039303464ull,0x2030383730303334ull,0x3630323030337830ull,0x3134637830203131ull,
0x090a203038373030ull,0x6432303033783009ull,0x3463783020643034ull,0x3020303837303033ull,
0x3163303030303278ull,0x3130343078302035ull,0x09090a2030383734ull,0x6332303031347830ull,
0x3030307830203931ull,0x7830203730303030ull,0x3837653834303032ull,0x3833303032783020ull,
0x3009090a20343534ull,0x3032303230303078ull,0x3030306378302035ull,0x3278302030383730ull,
0x2064366130303030ull,0x3738313034307830ull,0x783009090a203038ull,0x3330303238313061ull,
0x3030303030783020ull,0x3033783020303030ull,0x3020393465643230ull,0x3837303033346378ull,
0x33783009090a2030ull,0x2035306363313030ull,0x3730303334637830ull,0x3030337830203038ull,
0x7830203135636334ull,0x3038373030333463ull,0x3033783009090a20ull,0x3020393534643530ull,
0x3837303033346378ull,0x3430303378302030ull,0x6378302064353464ull,0x2030383730303334ull,
0x303033783009090aull,0x7830203536636333ull,0x3038373030333463ull,0x6332303033783020ull,
0x3463783020393663ull,0x0a20303837303033ull,0x3030303178300909ull,0x3078302035343866ull,
0x2030383763333036ull,0x3866303030317830ull,0x3034307830203134ull,0x090a203038376333ull,
0x6630303031783009ull,0x3630783020643338ull,0x3020303837633330ull,0x3338663030303178ull,
0x3330343078302039ull,0x09090a2030383763ull,0x3866303030317830ull,0x3036307830203531ull,
0x7830203038376333ull,0x3131386630303031ull,0x6333303430783020ull,0x3009090a20303837ull,
0x3038663030303178ull,0x3330363078302039ull,0x3178302030383763ull,0x2039313866303030ull,
0x3763333034307830ull,0x783009090a203038ull,0x3132386630303031ull,0x6333303630783020ull,
0x3031783020303837ull,0x3020643138663030ull,0x3837633330343078ull,0x31783009090a2030ull,
0x2035333866303030ull,0x3763333036307830ull,0x3030317830203038ull,0x7830206430386630ull,
0x3038376333303430ull,0x3033783009090a20ull,0x3020313030303230ull,0x3837303031346378ull,
0x3030303178302030ull,0x3078302035323866ull,0x2030383763333036ull,0x303031783009090aull,
0x7830203932386630ull,0x3038376333303430ull,0x6630303031783020ull,0x3630783020643238ull,
0x0a20303837633330ull,0x3030303278300909ull,0x3078302031303064ull,0x2030633730303234ull,
0x3866303030317830ull,0x3034307830203133ull,0x090a203038376333ull,0x6330303032783009ull,
0x3430783020313663ull,0x3020303837343032ull,0x3736333230303378ull,0x3031346378302035ull,
0x09090a2030383730ull,0x3030303030327830ull,0x3034307830203934ull,0x7830203064373834ull,
0x3530326430343033ull,0x6334323430783020ull,0x3009090a20303837ull,0x3561323230303378ull,
0x3031346378302035ull,0x3378302030383730ull,0x2031363033323030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3537386330303032ull,0x3437323430783020ull,0x3033783020303837ull,
0x3020643432303034ull,0x3837393730343078ull,0x64783009090a2030ull,0x2039373030653030ull,
0x3730306330387830ull,0x3030327830203038ull,0x7830206437303030ull,0x3038376335303430ull,
0x3064783009090a20ull,0x3020313865336530ull,0x3837303063303878ull,0x3030303278302030ull,
0x3078302064373030ull,0x2030383738353034ull,0x303064783009090aull,0x7830203938653365ull,
0x3038373030633038ull,0x3030303032783020ull,0x3430783020643730ull,0x0a20303837343530ull,
0x6530306478300909ull,0x3878302035386533ull,0x2030383730306330ull,0x6133653030647830ull,
0x6330387830206437ull,0x090a203038373030ull,0x3230303430783009ull,0x3465783020313034ull,
0x3020303837383732ull,0x3063323030343078ull,0x3832346578302031ull,0x09090a2030383730ull,
0x3433303034307830ull,0x3234657830203130ull,0x7830203038373838ull,0x3130633330303430ull,
0x3438323465783020ull,0x3009090a20303837ull,0x3761333030303278ull,0x3630343078302039ull,
0x6478302030383738ull,0x2035386333653030ull,0x3730306330387830ull,0x783009090a203038ull,
0x3937613330303032ull,0x3436303430783020ull,0x3064783020303837ull,0x3020313863336530ull,
0x3837303063303878ull,0x32783009090a2030ull,0x2039376133303030ull,0x3730363034307830ull,
0x3030647830203038ull,0x7830203937633365ull,0x3038373030633038ull,0x3638783009090a20ull,
0x3020333065666631ull,0x3030303030303078ull,0x6631306578302030ull,0x3078302035343465ull,
0x2030383734343230ull,0x313065783009090aull,0x7830203134366566ull,0x3038373034323030ull,
0x6566313065783020ull,0x3030783020643338ull,0x0a20303837633332ull,0x6631306578300909ull,
0x3078302039336165ull,0x2030383738333230ull,0x6365663130657830ull,0x3230307830203531ull,
0x090a203038373431ull,0x6566313065783009ull,0x3030783020313165ull,0x3020303837303132ull,
0x3030666631306578ull,0x3032303078302039ull,0x09090a2030383738ull,0x3266663130657830ull,
0x3230307830203931ull,0x7830203038373831ull,0x3132346666313065ull,0x3032323030783020ull,
0x3009090a20303837ull,0x3136666631306578ull,0x3132303078302064ull,0x6578302030383763ull,
0x2035333866663130ull,0x3734333230307830ull,0x783009090a203038ull,0x3930303031303064ull,
0x3030303032783020ull,0x3065783020303837ull,0x3020643061666631ull,0x3837633032303078ull,
0x65783009090a2030ull,0x2035326366663130ull,0x3734323230307830ull,0x3130657830203038ull,
0x7830203932656666ull,0x3038373832323030ull,0x3865783009090a20ull,0x3020643230636631ull,
0x3837633232303078ull,0x6631386578302030ull,0x3078302031333263ull,0x2030383730333230ull,
0x323865783009090aull,0x7830203534366331ull,0x3038373434323030ull,0x6331323865783020ull,
0x3030783020313438ull,0x0a20303837303432ull,0x3132386578300909ull,0x3078302064336163ull,
0x2030383763333230ull,0x6363313238657830ull,0x3230307830203933ull,0x090a203038373833ull,
0x6331323865783009ull,0x3030783020353165ull,0x3020303837343132ull,0x3130643132386578ull,
0x3132303078302031ull,0x09090a2030383730ull,0x3264313238657830ull,0x3230307830203930ull,
0x7830203038373830ull,0x3931346431323865ull,0x3831323030783020ull,0x3009090a20303837ull,
0x3236643132386578ull,0x3232303078302031ull,0x6578302030383730ull,0x2064313864313238ull,
0x3763313230307830ull,0x783009090a203038ull,0x3533616431323865ull,0x3433323030783020ull,
0x3865783020303837ull,0x3020643063643132ull,0x3837633032303078ull,0x65783009090a2030ull,
0x2035326564313238ull,0x3734323230307830ull,0x3238657830203038ull,0x7830203932306531ull,
0x3038373832323030ull,0x3865783009090a20ull,0x3020643232653132ull,0x3837633232303078ull,
0x3132386578302030ull,0x3078302031333465ull,0x2030383730333230ull,0x303064783009090aull,
0x7830206430303032ull,0x3038373030303032ull,0x6530323865783020ull,0x3030783020353438ull,
0x0a20303837343432ull,0x3032386578300909ull,0x3078302031346165ull,0x2030383730343230ull,
0x6365303238657830ull,0x3230307830206433ull,0x090a203038376333ull,0x6530323865783009ull,
0x3030783020393365ull,0x3020303837383332ull,0x3130663032386578ull,0x3132303078302035ull,
0x09090a2030383734ull,0x3266303238657830ull,0x3230307830203131ull,0x7830203038373031ull,
0x3930346630323865ull,0x3830323030783020ull,0x3009090a20303837ull,0x3136663032386578ull,
0x3132303078302039ull,0x6578302030383738ull,0x2031323866303238ull,0x3730323230307830ull,
0x783009090a203038ull,0x6431616630323865ull,0x6331323030783020ull,0x3865783020303837ull,
0x3020353363663032ull,0x3837343332303078ull,0x65783009090a2030ull,0x2064306566303238ull,
0x3763303230307830ull,0x3263657830203038ull,0x7830203532306330ull,0x3038373432323030ull,
0x6365783009090a20ull,0x3020393232633032ull,0x3837383232303078ull,0x3032636578302030ull,
0x3078302064323463ull,0x2030383763323230ull,0x326365783009090aull,0x7830203133366330ull,
0x3038373033323030ull,0x3230303032783020ull,0x3430783020353738ull,0x0a20303837343730ull,
0x6530306478300909ull,0x3878302064376133ull,0x2030383730306330ull,0x3030303031327830ull,
0x3434307830203130ull,0x090a203063373830ull,0x6365316365783009ull,0x3030783020353461ull,
0x3020303837343432ull,0x3463636531636578ull,0x3432303078302031ull,0x09090a2030383730ull,
0x6563653163657830ull,0x3230307830206433ull,0x7830203038376333ull,0x3933306465316365ull,
0x3833323030783020ull,0x3009090a20303837ull,0x3132646531636578ull,0x3132303078302035ull,
0x6578302030383734ull,0x2031313464653163ull,0x3730313230307830ull,0x783009090a203038ull,
0x3930366465316365ull,0x3830323030783020ull,0x6365783020303837ull,0x3020393138646531ull,
0x3837383132303078ull,0x65783009090a2030ull,0x2031326164653163ull,0x3730323230307830ull,
0x3163657830203038ull,0x7830206431636465ull,0x3038376331323030ull,0x6365783009090a20ull,
0x3020353365646531ull,0x3837343332303078ull,0x6531636578302030ull,0x3078302064303065ull,
0x2030383763303230ull,0x316365783009090aull,0x7830203532326565ull,0x3038373432323030ull,
0x6565316365783020ull,0x3030783020393234ull,0x0a20303837383232ull,0x6531636578300909ull,
0x3078302064323665ull,0x2030383763323230ull,0x3865653163657830ull,0x3230307830203538ull,
0x090a203038373033ull,0x3030343033783009ull,0x3430783020353032ull,0x3020303837306631ull,
0x3361333030303278ull,0x3630343078302031ull,0x09090a2030383738ull,0x3831653030647830ull,
0x6330387830203138ull,0x7830203038373030ull,0x3133613330303032ull,0x3436303430783020ull,
0x3009090a20303837ull,0x3738316530306478ull,0x3063303878302039ull,0x3278302030383730ull,
0x2031336133303030ull,0x3730363034307830ull,0x783009090a203038ull,0x3133383165303064ull,
0x3030633038783020ull,0x3064783020303837ull,0x3020393030303330ull,0x3837303030303278ull,
0x65783009090a2030ull,0x2035346365663163ull,0x3734343230307830ull,0x3163657830203038ull,
0x7830203134656566ull,0x3038373034323030ull,0x6365783009090a20ull,0x3020643330666631ull,
0x3837633332303078ull,0x6631636578302030ull,0x3078302039333266ull,0x2030383738333230ull,
0x316365783009090aull,0x7830203531346666ull,0x3038373431323030ull,0x6666316365783020ull,
0x3030783020313136ull,0x0a20303837303132ull,0x6631636578300909ull,0x3078302039303866ull,
0x2030383738303230ull,0x6166663163657830ull,0x3230307830203931ull,0x090a203038373831ull,
0x6666316365783009ull,0x3030783020313263ull,0x3020303837303232ull,0x3165666631636578ull,
0x3132303078302064ull,0x09090a2030383763ull,0x3063663138657830ull,0x3230307830203533ull,
0x7830203038373433ull,0x6430326366313865ull,0x6330323030783020ull,0x3009090a20303837ull,
0x3234636631386578ull,0x3232303078302035ull,0x6578302030383734ull,0x2039323663663138ull,
0x3738323230307830ull,0x783009090a203038ull,0x6432386366313865ull,0x6332323030783020ull,
0x3865783020303837ull,0x3020643761636631ull,0x3837343832303078ull,0x65783009090a2030ull,
0x2035346563303238ull,0x3734343230307830ull,0x3238657830203038ull,0x7830203134306430ull,
0x3038373034323030ull,0x3865783009090a20ull,0x3020643332643032ull,0x3837633332303078ull,
0x3032386578302030ull,0x3078302039333464ull,0x2030383738333230ull,0x323865783009090aull,
0x7830203531366430ull,0x3038373431323030ull,0x6430323865783020ull,0x3030783020313138ull,
0x0a20303837303132ull,0x3032386578300909ull,0x3078302039306164ull,0x2030383738303230ull,
0x6364303238657830ull,0x3230307830203931ull,0x090a203038373831ull,0x6430323865783009ull,
0x3030783020313265ull,0x3020303837303232ull,0x3130653032386578ull,0x3132303078302064ull,
0x09090a2030383763ull,0x3265303238657830ull,0x3230307830203533ull,0x7830203038373433ull,
0x6430346530323865ull,0x6330323030783020ull,0x3009090a20303837ull,0x3236653032386578ull,
0x3232303078302035ull,0x6578302030383734ull,0x2039323865303238ull,0x3738323230307830ull,
0x783009090a203038ull,0x6432616530323865ull,0x6332323030783020ull,0x3865783020303837ull,
0x3020643763653032ull,0x3837633732303078ull,0x64783009090a2030ull,0x2064303030343030ull,
0x3730303030327830ull,0x3138657830203038ull,0x7830203534306665ull,0x3038373434323030ull,
0x3865783009090a20ull,0x3020313432666531ull,0x3837303432303078ull,0x6531386578302030ull,
0x3078302064333466ull,0x2030383763333230ull,0x313865783009090aull,0x7830203933366665ull,
0x3038373833323030ull,0x6665313865783020ull,0x3030783020353138ull,0x0a20303837343132ull,
0x6531386578300909ull,0x3078302031316166ull,0x2030383730313230ull,0x6366653138657830ull,
0x3230307830203930ull,0x090a203038373830ull,0x6665313865783009ull,0x3030783020393165ull,
0x3020303837383132ull,0x3230636531636578ull,0x3232303078302031ull,0x09090a2030383730ull,
0x3263653163657830ull,0x3230307830206431ull,0x7830203038376331ull,0x3533346365316365ull,
0x3433323030783020ull,0x3009090a20303837ull,0x3036636531636578ull,0x3032303078302064ull,
0x6578302030383763ull,0x2035323863653163ull,0x3734323230307830ull,0x783009090a203038ull,
0x3932616365316365ull,0x3832323030783020ull,0x6365783020303837ull,0x3020643263636531ull,
0x3837633232303078ull,0x65783009090a2030ull,0x2039376563653163ull,0x3763373230307830ull,
0x3030327830203038ull,0x7830206437383230ull,0x3038373437303430ull,0x3064783009090a20ull,
0x3020353765336530ull,0x3837303063303878ull,0x6330636578302030ull,0x3078302035343264ull,
0x2030383734343230ull,0x306365783009090aull,0x7830203134346463ull,0x3038373034323030ull,
0x6463306365783020ull,0x3030783020643336ull,0x0a20303837633332ull,0x6330636578300909ull,
0x3078302039333864ull,0x2030383738333230ull,0x6164633063657830ull,0x3230307830203531ull,
0x090a203038373431ull,0x6463306365783009ull,0x3030783020313163ull,0x3020303837303132ull,
0x3065646330636578ull,0x3032303078302039ull,0x09090a2030383738ull,0x3065633063657830ull,
0x3230307830203931ull,0x7830203038373831ull,0x3132326563306365ull,0x3032323030783020ull,
0x3009090a20303837ull,0x3134656330636578ull,0x3132303078302064ull,0x6578302030383763ull,
0x2035333665633063ull,0x3734333230307830ull,0x783009090a203038ull,0x6430386563306365ull,
0x6330323030783020ull,0x6365783020303837ull,0x3020353261656330ull,0x3837343232303078ull,
0x65783009090a2030ull,0x2039326365633063ull,0x3738323230307830ull,0x3063657830203038ull,
0x7830206432656563ull,0x3038376332323030ull,0x6365783009090a20ull,0x3020353830666330ull,
0x3837383732303078ull,0x3030303278302030ull,0x3078302031336533ull,0x2030383738363034ull,
0x303064783009090aull,0x7830203138383165ull,0x3038373030633038ull,0x3330303032783020ull,
0x3430783020313365ull,0x0a20303837343630ull,0x6530306478300909ull,0x3878302039373831ull,
0x2030383730306330ull,0x6533303030327830ull,0x3034307830203133ull,0x090a203038373036ull,
0x3165303064783009ull,0x3038783020313338ull,0x3020303837303063ull,0x3030303530306478ull,
0x3030303278302039ull,0x09090a2030383730ull,0x3466643163657830ull,0x3230307830203534ull,
0x7830203038373434ull,0x3134366664316365ull,0x3034323030783020ull,0x3009090a20303837ull,
0x3338666431636578ull,0x3332303078302064ull,0x6578302030383763ull,0x2039336166643163ull,
0x3738333230307830ull,0x783009090a203038ull,0x3531636664316365ull,0x3431323030783020ull,
0x6365783020303837ull,0x3020313165666431ull,0x3837303132303078ull,0x65783009090a2030ull,
0x2039303063643138ull,0x3738303230307830ull,0x3138657830203038ull,0x7830203931326364ull,
0x3038373831323030ull,0x3865783009090a20ull,0x3020313234636431ull,0x3837303232303078ull,
0x6431386578302030ull,0x3078302064313663ull,0x2030383763313230ull,0x313865783009090aull,
0x7830203533386364ull,0x3038373433323030ull,0x6364313865783020ull,0x3030783020643061ull,
0x0a20303837633032ull,0x6431386578300909ull,0x3078302035326363ull,0x2030383734323230ull,
0x6563643138657830ull,0x3230307830203932ull,0x090a203038373832ull,0x6464313865783009ull,
0x3030783020643230ull,0x3020303837633232ull,0x3732646431386578ull,0x3832303078302035ull,
0x09090a2030383734ull,0x3664303238657830ull,0x3230307830203534ull,0x7830203038373434ull,
0x3134386430323865ull,0x3034323030783020ull,0x3009090a20303837ull,0x3361643032386578ull,
0x3332303078302064ull,0x6578302030383763ull,0x2039336364303238ull,0x3738333230307830ull,
0x783009090a203038ull,0x3531656430323865ull,0x3431323030783020ull,0x3865783020303837ull,
0x3020313130653032ull,0x3837303132303078ull,0x65783009090a2030ull,0x2039303265303238ull,
0x3738303230307830ull,0x3238657830203038ull,0x7830203931346530ull,0x3038373831323030ull,
0x3865783009090a20ull,0x3020313236653032ull,0x3837303232303078ull,0x3032386578302030ull,
0x3078302064313865ull,0x2030383763313230ull,0x323865783009090aull,0x7830203533616530ull,
0x3038373433323030ull,0x6530323865783020ull,0x3030783020643063ull,0x0a20303837633032ull,
0x3032386578300909ull,0x3078302035326565ull,0x2030383734323230ull,0x3066303238657830ull,
0x3230307830203932ull,0x090a203038373832ull,0x6630323865783009ull,0x3030783020643232ull,
0x3020303837633232ull,0x3734663032386578ull,0x3732303078302035ull,0x09090a2030383734ull,
0x3030363030647830ull,0x3030327830206430ull,0x7830203038373030ull,0x3534386665313865ull,
0x3434323030783020ull,0x3009090a20303837ull,0x3461666531386578ull,0x3432303078302031ull,
0x6578302030383730ull,0x2064336366653138ull,0x3763333230307830ull,0x783009090a203038ull,
0x3933656665313865ull,0x3833323030783020ull,0x6365783020303837ull,0x3020353130636531ull,
0x3837343132303078ull,0x65783009090a2030ull,0x2031313263653163ull,0x3730313230307830ull,
0x3163657830203038ull,0x7830203930346365ull,0x3038373830323030ull,0x6365783009090a20ull,
0x3020393136636531ull,0x3837383132303078ull,0x6531636578302030ull,0x3078302031323863ull,
0x2030383730323230ull,0x316365783009090aull,0x7830206431616365ull,0x3038376331323030ull,
0x6365316365783020ull,0x3030783020353363ull,0x0a20303837343332ull,0x6531636578300909ull,
0x3078302064306563ull,0x2030383763303230ull,0x3064653163657830ull,0x3230307830203532ull,
0x090a203038373432ull,0x6465316365783009ull,0x3030783020393232ull,0x3020303837383232ull,
0x3234646531636578ull,0x3232303078302064ull,0x09090a2030383763ull,0x3664653163657830ull,
0x3230307830203138ull,0x7830203038373437ull,0x3537383230303032ull,0x6337303430783020ull,
0x3009090a20303837ull,0x3761336530306478ull,0x3063303878302039ull,0x6578302030383730ull,
0x2035346164633063ull,0x3734343230307830ull,0x783009090a203038ull,0x3134636463306365ull,
0x3034323030783020ull,0x6365783020303837ull,0x3020643365646330ull,0x3837633332303078ull,
0x65783009090a2030ull,0x2039333065633063ull,0x3738333230307830ull,0x3063657830203038ull,
0x7830203531326563ull,0x3038373431323030ull,0x6365783009090a20ull,0x3020313134656330ull,
0x3837303132303078ull,0x6330636578302030ull,0x3078302039303665ull,0x2030383738303230ull,
0x306365783009090aull,0x7830203931386563ull,0x3038373831323030ull,0x6563306365783020ull,
0x3030783020313261ull,0x0a20303837303232ull,0x6330636578300909ull,0x3078302064316365ull,
0x2030383763313230ull,0x6565633063657830ull,0x3230307830203533ull,0x090a203038373433ull,
0x6663306365783009ull,0x3030783020643030ull,0x3020303837633032ull,0x3232666330636578ull,
0x3232303078302035ull,0x09090a2030383734ull,0x3466633063657830ull,0x3230307830203932ull,
0x7830203038373832ull,0x6432366663306365ull,0x6332323030783020ull,0x3009090a20303837ull,
0x3838666330636578ull,0x3832303078302035ull,0x3278302030383730ull,0x2031336133303030ull,
0x3738363034307830ull,0x783009090a203038ull,0x3138383165303064ull,0x3030633038783020ull,
0x3032783020303837ull,0x3020313361333030ull,0x3837343630343078ull,0x64783009090a2030ull,
0x2064373831653030ull,0x3730306330387830ull,0x3030327830203038ull,0x7830203133613330ull,
0x3038373036303430ull,0x3064783009090a20ull,0x3020313338316530ull,0x3837303063303878ull,
0x3730306478302030ull,0x3278302039303030ull,0x2030383730303030ull,0x316365783009090aull,
0x7830203534636665ull,0x3038373434323030ull,0x6665316365783020ull,0x3030783020313465ull,
0x0a20303837303432ull,0x6531386578300909ull,0x3078302064333063ull,0x2030383763333230ull,
0x3263653138657830ull,0x3230307830203933ull,0x090a203038373833ull,0x6365313865783009ull,
0x3030783020353134ull,0x3020303837343132ull,0x3136636531386578ull,0x3132303078302031ull,
0x09090a2030383730ull,0x3863653138657830ull,0x3230307830203930ull,0x7830203038373830ull,
0x3931616365313865ull,0x3831323030783020ull,0x3009090a20303837ull,0x3263636531386578ull,
0x3232303078302031ull,0x6578302030383730ull,0x2064316563653138ull,0x3763313230307830ull,
0x783009090a203038ull,0x3533306465313865ull,0x3433323030783020ull,0x3865783020303837ull,
0x3020643032646531ull,0x3837633032303078ull,0x65783009090a2030ull,0x2035323464653138ull,
0x3734323230307830ull,0x3138657830203038ull,0x7830203932366465ull,0x3038373832323030ull,
0x3865783009090a20ull,0x3020643238646531ull,0x3837633232303078ull,0x6531386578302030ull,
0x3078302039376164ull,0x2030383734383230ull,0x323865783009090aull,0x7830203534656430ull,
0x3038373434323030ull,0x6530323865783020ull,0x3030783020313430ull,0x0a20303837303432ull,
0x3032386578300909ull,0x3078302064333265ull,0x2030383763333230ull,0x3465303238657830ull,
0x3230307830203933ull,0x090a203038373833ull,0x6530323865783009ull,0x3030783020353136ull,
0x3020303837343132ull,0x3138653032386578ull,0x3132303078302031ull,0x09090a2030383730ull,
0x6165303238657830ull,0x3230307830203930ull,0x7830203038373830ull,0x3931636530323865ull,
0x3831323030783020ull,0x3009090a20303837ull,0x3265653032386578ull,0x3232303078302031ull,
0x6578302030383730ull,0x2064313066303238ull,0x3763313230307830ull,0x783009090a203038ull,
0x3533326630323865ull,0x3433323030783020ull,0x3865783020303837ull,0x3020643034663032ull,
0x3837633032303078ull,0x65783009090a2030ull,0x2035323666303238ull,0x3734323230307830ull,
0x3238657830203038ull,0x7830203932386630ull,0x3038373832323030ull,0x3865783009090a20ull,
0x3020643261663032ull,0x3837633232303078ull,0x3032386578302030ull,0x3078302039376366ull,
0x2030383738373230ull,0x303064783009090aull,0x7830203930303038ull,0x3038373030303032ull,
0x6366313865783020ull,0x3030783020353430ull,0x0a20303837343432ull,0x6631386578300909ull,
0x3078302031343263ull,0x2030383730343230ull,0x3463663138657830ull,0x3230307830206433ull,
0x090a203038376333ull,0x6366313865783009ull,0x3030783020393336ull,0x3020303837383332ull,
0x3138636631386578ull,0x3132303078302035ull,0x09090a2030383734ull,0x6163663138657830ull,
0x3230307830203131ull,0x7830203038373031ull,0x3930636366313865ull,0x3830323030783020ull,
0x3009090a20303837ull,0x3165636631386578ull,0x3132303078302039ull,0x6578302030383738ull,
0x2031323064663138ull,0x3730323230307830ull,0x783009090a203038ull,0x6431326466313865ull,
0x6331323030783020ull,0x3865783020303837ull,0x3020353334646631ull,0x3837343332303078ull,
0x65783009090a2030ull,0x2064303664663138ull,0x3763303230307830ull,0x3138657830203038ull,
0x7830203532386466ull,0x3038373432323030ull,0x3865783009090a20ull,0x3020393261646631ull,
0x3837383232303078ull,0x6631386578302030ull,0x3078302064326364ull,0x2030383763323230ull,
0x313865783009090aull,0x7830203937656466ull,0x3038373837323030ull,0x3039303064783020ull,
0x3032783020643030ull,0x0a20303837303030ull,0x6330386578300909ull,0x3078302035343265ull,
0x2030383734343230ull,0x3465633038657830ull,0x3230307830203134ull,0x090a203038373034ull,
0x6563303865783009ull,0x3030783020643336ull,0x3020303837633332ull,0x3338656330386578ull,
0x3332303078302039ull,0x09090a2030383738ull,0x6165633038657830ull,0x3230307830203531ull,
0x7830203038373431ull,0x3131636563303865ull,0x3031323030783020ull,0x3009090a20303837ull,
0x3065656330386578ull,0x3032303078302039ull,0x6578302030383738ull,0x2039313066633038ull,
0x3738313230307830ull,0x783009090a203038ull,0x3132326663303865ull,0x3032323030783020ull,
0x3865783020303837ull,0x3020643134666330ull,0x3837633132303078ull,0x65783009090a2030ull,
0x2035333666633038ull,0x3734333230307830ull,0x3038657830203038ull,0x7830206430386663ull,
0x3038376330323030ull,0x3865783009090a20ull,0x3020353261666330ull,0x3837343232303078ull,
0x6330386578302030ull,0x3078302039326366ull,0x2030383738323230ull,0x303865783009090aull,
0x7830206432656663ull,0x3038376332323030ull,0x6363306365783020ull,0x3030783020313330ull,
0x0a20303837383732ull,0x3030303278300909ull,0x3078302035373832ull,0x2030383734373034ull,
0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,0x3231303033783009ull,
0x3436783020646637ull,0x3020386337383030ull,0x6635323030303378ull,0x3130343678302064ull,
0x09090a2038633230ull,0x3732313030337830ull,0x3034367830206466ull,0x7830203834313031ull,
0x3330303634303031ull,0x3030303030783020ull,0x3009090a20303832ull,0x3063646331303678ull,
0x3632303878302031ull,0x3378302032383763ull,0x2031303030323030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3530386430303032ull,0x3030323430783020ull,0x3064783020303837ull,
0x3020313032306530ull,0x3837303063303878ull,0x63783009090a2030ull,0x2035343065313130ull,
0x3730303230307830ull,0x3030657830203038ull,0x7830203534326530ull,0x3038373434323030ull,
0x3033783009090a20ull,0x3020313063643230ull,0x3837303033346378ull,0x6530306478302030ull,
0x6178302035343230ull,0x2030383730306330ull,0x303032783009090aull,0x7830203534323030ull,
0x3038373030303430ull,0x3265303064783020ull,0x3038783020353032ull,0x0a20303837303063ull,
0x3031306378300909ull,0x3078302031343065ull,0x2030383730303230ull,0x3265313030657830ull,
0x3230307830203530ull,0x090a203038373034ull,0x3265303064783009ull,0x3061783020353032ull,
0x3020303837303063ull,0x3432323030303278ull,0x3030343078302031ull,0x09090a2030383730ull,
0x3032653030647830ull,0x6330387830203530ull,0x7830203038373030ull,0x6433306566303063ull,
0x3030323030783020ull,0x3009090a20303837ull,0x3032653130306578ull,0x3332303078302035ull,
0x6478302030383763ull,0x2035303032653030ull,0x3730306330617830ull,0x783009090a203038ull,
0x6433303030303032ull,0x3034303430783020ull,0x3064783020303837ull,0x3020353065316530ull,
0x3837303063303878ull,0x63783009090a2030ull,0x2039333065653030ull,0x3730303230307830ull,
0x3030657830203038ull,0x7830203530326531ull,0x3038373833323030ull,0x3064783009090a20ull,
0x3020353065316530ull,0x3837303063306178ull,0x3030303278302030ull,0x3078302039333030ull,
0x2030383763333034ull,0x303064783009090aull,0x7830203530633165ull,0x3038373030633038ull,
0x6535303063783020ull,0x3030783020353130ull,0x0a20303837303032ull,0x3130306578300909ull,
0x3078302035303265ull,0x2030383734313230ull,0x6331653030647830ull,0x6330617830203530ull,
0x090a203038373030ull,0x3030303032783009ull,0x3430783020353130ull,0x3020303837383330ull,
0x3061306530306478ull,0x3063303878302035ull,0x09090a2030383730ull,0x3065343030637830ull,
0x3230307830203131ull,0x7830203038373030ull,0x3530326531303065ull,0x3031323030783020ull,
0x3009090a20303837ull,0x3061306530306478ull,0x3063306178302035ull,0x3278302030383730ull,
0x2031313030303030ull,0x3734313034307830ull,0x783009090a203038ull,0x3530383065303064ull,
0x3030633038783020ull,0x3063783020303837ull,0x3020393030653230ull,0x3837303032303078ull,
0x65783009090a2030ull,0x2035303265313030ull,0x3738303230307830ull,0x3030647830203038ull,
0x7830203530383065ull,0x3038373030633061ull,0x3032783009090a20ull,0x3020393030303030ull,
0x3837303130343078ull,0x6530306478302030ull,0x3878302035303430ull,0x2030383730306330ull,
0x303063783009090aull,0x7830203131306536ull,0x3038373030323030ull,0x6531303065783020ull,
0x3030783020353032ull,0x0a20303837303132ull,0x6530306478300909ull,0x6178302035303430ull,
0x2030383730306330ull,0x3030303030327830ull,0x3034307830203930ull,0x090a203038373830ull,
0x3065303064783009ull,0x3038783020353034ull,0x3020303837303063ull,0x3130653830306378ull,
0x3032303078302031ull,0x09090a2030383730ull,0x3265313030657830ull,0x3230307830203530ull,
0x7830203038373031ull,0x3530343065303064ull,0x3030633061783020ull,0x3009090a20303837ull,
0x3030303030303278ull,0x3030343078302039ull,0x6478302030383738ull,0x2035303430653030ull,
0x3730306330387830ull,0x783009090a203038ull,0x3131306537303063ull,0x3030323030783020ull,
0x3065783020303837ull,0x3020353032653130ull,0x3837303132303078ull,0x64783009090a2030ull,
0x2035303430653030ull,0x3730306330617830ull,0x3030327830203038ull,0x7830203930303030ull,
0x3038373830303430ull,0x3064783009090a20ull,0x3020353034306530ull,0x3837303063303878ull,
0x6430306378302030ull,0x3078302031313065ull,0x2030383730303230ull,0x303065783009090aull,
0x7830203530326531ull,0x3038373031323030ull,0x3065303064783020ull,0x3061783020353034ull,
0x0a20303837303063ull,0x3030303278300909ull,0x3078302039303030ull,0x2030383738303034ull,
0x3430653030647830ull,0x6330387830203530ull,0x090a203038373030ull,0x6533303063783009ull,
0x3030783020643030ull,0x3020303837303032ull,0x3032653130306578ull,0x3032303078302035ull,
0x09090a2030383763ull,0x3430653030647830ull,0x6330617830203530ull,0x7830203038373030ull,
0x3930303030303032ull,0x3830303430783020ull,0x3009090a20303837ull,0x3034306530306478ull,
0x3063303878302035ull,0x6378302030383730ull,0x2064303065393030ull,0x3730303230307830ull,
0x783009090a203038ull,0x3530326531303065ull,0x6330323030783020ull,0x3064783020303837ull,
0x3020353034306530ull,0x3837303063306178ull,0x32783009090a2030ull,0x2039303030303030ull,
0x3738303034307830ull,0x3030647830203038ull,0x7830203530343065ull,0x3038373030633038ull,
0x3063783009090a20ull,0x3020643030656130ull,0x3837303032303078ull,0x3130306578302030ull,
0x3078302035303265ull,0x2030383763303230ull,0x303064783009090aull,0x7830203530343065ull,
0x3038373030633061ull,0x3030303032783020ull,0x3430783020393030ull,0x0a20303837383030ull,
0x6530306478300909ull,0x3878302035303430ull,0x2030383730306330ull,0x3065623030637830ull,
0x3230307830206430ull,0x090a203038373030ull,0x6531303065783009ull,0x3030783020353032ull,
0x3020303837633032ull,0x3030303030303278ull,0x3030343078302064ull,0x09090a2030383738ull,
0x3430653030647830ull,0x6330617830203530ull,0x7830203038373030ull,0x3130363065303064ull,
0x3030633038783020ull,0x3009090a20303837ull,0x3030656330306378ull,0x3032303078302035ull,
0x6578302030383730ull,0x2031303265303030ull,0x3734303230307830ull,0x783009090a203038ull,
0x3130363065303064ull,0x3030633061783020ull,0x0a7d090a20313837ull,0x0000000000000a7dull
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
0x2f20676e696c6970ull,0x78706d742f706d74ull,0x31303030305f7466ull,0x303030305f383833ull,
0x6d5f372d30303030ull,0x632e746c756d7461ull,0x2f2820692e337070ull,0x494263632f706d74ull,
0x686e735677462e23ull,0x2d2d2d2f2f090a29ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2f2f090a0aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x74704f202f2f090aull,0x2f090a3a736e6f69ull,0x2d2d2d2d2d2d2d2full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f2f090a2d2d2d2dull,0x7465677261542020ull,
0x5349202c7874703aull,0x2c33315f6d733a41ull,0x3a6e6169646e4520ull,0x202c656c7474696cull,
0x207265746e696f50ull,0x0a34363a657a6953ull,0x334f2d20202f2f09ull,0x696d6974704f2809ull,
0x6c206e6f6974617aull,0x2f090a296c657665ull,0x280930672d20202full,0x656c206775626544ull,
0x2f2f090a296c6576ull,0x522809326d2d2020ull,0x64612074726f7065ull,0x736569726f736976ull,
0x2d2d2d2f2f090a29ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x656c69662e090a0aull,0x6d6f633c22093109ull,0x6e696c2d646e616dull,0x69662e090a223e65ull,
0x742f22093209656cull,0x6678706d742f706dull,0x3331303030305f74ull,0x30303030305f3838ull,
0x616d5f362d303030ull,0x75632e746c756d74ull,0x70672e3265666164ull,0x6c69662e090a2275ull,
0x73752f2209330965ull,0x63672f62696c2f72ull,0x34365f3638782f63ull,0x672d78756e696c2dull,
0x332e332e342f756eull,0x6564756c636e692full,0x2e6665646474732full,0x6c69662e090a2268ull,
0x6f682f2209340965ull,0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,
0x636e692f2e2e2f2full,0x7472632f6564756cull,0x5f6563697665642full,0x2e656d69746e7572ull,
0x6c69662e090a2268ull,0x6f682f2209350965ull,0x6d616964672f656dull,0x2f706d65742f736full,
0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x736f682f6564756cull,0x656e696665645f74ull,
0x662e090a22682e73ull,0x2f22093609656c69ull,0x6964672f656d6f68ull,0x6d65742f736f6d61ull,
0x622f616475632f70ull,0x692f2e2e2f2f6e69ull,0x622f6564756c636eull,0x745f6e69746c6975ull,
0x0a22682e73657079ull,0x3709656c69662e09ull,0x2f656d6f682f2209ull,0x2f736f6d61696467ull,
0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,0x6563697665642f65ull,
0x682e73657079745full,0x656c69662e090a22ull,0x6d6f682f22093809ull,0x6f6d616964672f65ull,
0x632f706d65742f73ull,0x2f6e69622f616475ull,0x6c636e692f2e2e2full,0x766972642f656475ull,
0x73657079745f7265ull,0x69662e090a22682eull,0x682f22093909656cull,0x616964672f656d6full,
0x706d65742f736f6dull,0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x65742f6564756c63ull,
0x79745f6572757478ull,0x090a22682e736570ull,0x303109656c69662eull,0x2f656d6f682f2209ull,
0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,0x64756c636e692f2eull,
0x726f746365762f65ull,0x682e73657079745full,0x656c69662e090a22ull,0x6f682f2209313109ull,
0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,
0x7665642f6564756cull,0x6e75616c5f656369ull,0x6d617261705f6863ull,0x22682e7372657465ull,
0x09656c69662e090aull,0x6d6f682f22093231ull,0x6f6d616964672f65ull,0x632f706d65742f73ull,
0x2f6e69622f616475ull,0x6c636e692f2e2e2full,0x2f7472632f656475ull,0x5f656761726f7473ull,
0x22682e7373616c63ull,0x09656c69662e090aull,0x7273752f22093331ull,0x6564756c636e692full,
0x79742f737469622full,0x090a22682e736570ull,0x343109656c69662eull,0x692f7273752f2209ull,
0x742f6564756c636eull,0x090a22682e656d69ull,0x353109656c69662eull,0x6c756d74616d2209ull,
0x2e090a2275632e74ull,0x09363109656c6966ull,0x672f656d6f682f22ull,0x742f736f6d616964ull,
0x616475632f706d65ull,0x2e2e2f2f6e69622full,0x6564756c636e692full,0x5f6e6f6d6d6f632full,
0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209373109656c69ull,0x64672f656d6f682full,
0x65742f736f6d6169ull,0x2f616475632f706dull,0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,
0x636e75662f747263ull,0x682e6f7263616d5full,0x656c69662e090a22ull,0x6f682f2209383109ull,
0x6d616964672f656dull,0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,
0x74616d2f6564756cull,0x6974636e75665f68ull,0x090a22682e736e6full,0x393109656c69662eull,
0x2f656d6f682f2209ull,0x2f736f6d61696467ull,0x6475632f706d6574ull,0x2e2f2f6e69622f61ull,
0x64756c636e692f2eull,0x6563697665642f65ull,0x6f6974636e75665full,0x2e090a22682e736eull,
0x09303209656c6966ull,0x672f656d6f682f22ull,0x742f736f6d616964ull,0x616475632f706d65ull,
0x2e2e2f2f6e69622full,0x6564756c636e692full,0x6f635f6874616d2full,0x2e73746e6174736eull,
0x6c69662e090a2268ull,0x682f220931320965ull,0x616964672f656d6full,0x706d65742f736f6dull,
0x69622f616475632full,0x6e692f2e2e2f2f6eull,0x6d732f6564756c63ull,0x6d6f74615f31315full,
0x74636e75665f6369ull,0x0a22682e736e6f69ull,0x3209656c69662e09ull,0x656d6f682f220932ull,
0x736f6d616964672full,0x75632f706d65742full,0x2f2f6e69622f6164ull,0x756c636e692f2e2eull,
0x32315f6d732f6564ull,0x5f63696d6f74615full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209333209656c69ull,0x64672f656d6f682full,0x65742f736f6d6169ull,0x2f616475632f706dull,
0x2f2e2e2f2f6e6962ull,0x2f6564756c636e69ull,0x6f645f33315f6d73ull,0x6e75665f656c6275ull,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209343209ull,0x6d616964672f656dull,
0x2f706d65742f736full,0x6e69622f61647563ull,0x636e692f2e2e2f2full,0x7865742f6564756cull,
0x7465665f65727574ull,0x74636e75665f6863ull,0x0a22682e736e6f69ull,0x3209656c69662e09ull,
0x656d6f682f220935ull,0x736f6d616964672full,0x75632f706d65742full,0x2f2f6e69622f6164ull,
0x756c636e692f2e2eull,0x5f6874616d2f6564ull,0x6e6f6974636e7566ull,0x74705f6c62645f73ull,
0x0a0a0a22682e3378ull,0x207972746e652e09ull,0x616d5f6b35315a5full,0x616e5f746c754d74ull,
0x535f536650657669ull,0x0a7b090a6969695full,0x752e206765722e09ull,0x363c687225203631ull,
0x6765722e090a3b3eull,0x7225203233752e20ull,0x2e090a3b3e34323cull,0x3436752e20676572ull,
0x3e33333c64722520ull,0x206765722e090a3bull,0x3c6625203233662eull,0x722e090a3b3e3733ull,
0x646572702e206765ull,0x0a3b3e343c702520ull,0x206d617261702e09ull,0x635f5f203436752eull,
0x5f6d726170616475ull,0x616d5f6b35315a5full,0x616e5f746c754d74ull,0x535f536650657669ull,
0x0a3b415f6969695full,0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,
0x616d5f6b35315a5full,0x616e5f746c754d74ull,0x535f536650657669ull,0x0a3b425f6969695full,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x616d5f6b35315a5full,
0x616e5f746c754d74ull,0x535f536650657669ull,0x0a3b435f6969695full,0x206d617261702e09ull,
0x635f5f203233732eull,0x5f6d726170616475ull,0x616d5f6b35315a5full,0x616e5f746c754d74ull,
0x535f536650657669ull,0x725f415f6969695full,0x702e090a3b73776full,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x754d74616d5f6b35ull,0x657669616e5f746cull,
0x69695f535f536650ull,0x736c6f635f415f69ull,0x617261702e090a3bull,0x5f203233732e206dull,
0x726170616475635full,0x5f6b35315a5f5f6dull,0x5f746c754d74616dull,0x536650657669616eull,
0x425f6969695f535full,0x090a3b736c6f635full,0x206465726168732eull,0x34206e67696c612eull,
0x635f5f2038622e20ull,0x6c625f425f616475ull,0x30315b36336b636full,0x732e090a3b5d3432ull,
0x612e206465726168ull,0x2e2034206e67696cull,0x6475635f5f203862ull,0x636f6c625f415f61ull,
0x30315b303630316bull,0x6c2e090a3b5d3432ull,0x363209353109636full,0x3142424c240a3009ull,
0x6d5f6b35315a5f5full,0x6e5f746c754d7461ull,0x5f53665065766961ull,0x090a3a6969695f53ull,
0x09353109636f6c2eull,0x7663090a30093633ull,0x31752e3233752e74ull,0x202c317225092036ull,
0x203b782e64697425ull,0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233752e34ull,
0x317225202c316472ull,0x202020202020203bull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,
0x746325202c316872ull,0x20203b792e646961ull,0x202f2f0920202020ull,0x31752e766f6d090aull,
0x2c32687225092036ull,0x792e6469746e2520ull,0x202020202020203bull,0x756d090a202f2f09ull,
0x752e656469772e6cull,0x2c32722509203631ull,0x25202c3168722520ull,0x202f2f093b326872ull,
0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3372ull,0x20202020203b792eull,
0x6461090a202f2f09ull,0x2509203233752e64ull,0x2c327225202c3472ull,0x2020203b33722520ull,
0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233752e6d61ull,0x5f5f5b202c357225ull,
0x6d72617061647563ull,0x6d5f6b35315a5f5full,0x6e5f746c754d7461ull,0x5f53665065766961ull,
0x5f415f6969695f53ull,0x2f093b5d736c6f63ull,0x2037363a6469202full,0x6170616475635f5full,
0x6b35315a5f5f6d72ull,0x746c754d74616d5full,0x6650657669616e5full,0x5f6969695f535f53ull,
0x302b736c6f635f41ull,0x702e646c090a3078ull,0x3436752e6d617261ull,0x202c326472250920ull,
0x70616475635f5f5bull,0x35315a5f5f6d7261ull,0x6c754d74616d5f6bull,0x50657669616e5f74ull,
0x6969695f535f5366ull,0x202f2f093b5d415full,0x5f5f2032373a6469ull,0x6d72617061647563ull,
0x6d5f6b35315a5f5full,0x6e5f746c754d7461ull,0x5f53665065766961ull,0x2b415f6969695f53ull,
0x6c756d090a307830ull,0x203233752e6f6c2eull,0x7225202c36722509ull,0x203b357225202c34ull,
0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233752eull,0x3b367225202c3364ull,
0x0920202020202020ull,0x646461090a202f2full,0x722509203436752eull,0x33647225202c3464ull,
0x203b31647225202cull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x2c34647225202c35ull,0x09202020203b3420ull,0x646461090a202f2full,0x722509203436752eull,
0x32647225202c3664ull,0x203b35647225202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x6d090a3009373309ull,0x09203631752e766full,0x6325202c33687225ull,0x203b782e64696174ull,
0x2f2f092020202020ull,0x752e766f6d090a20ull,0x3468722509203631ull,0x2e6469746e25202cull,
0x2020202020203b78ull,0x6d090a202f2f0920ull,0x2e656469772e6c75ull,0x3772250920363175ull,
0x202c33687225202cull,0x2f2f093b34687225ull,0x61702e646c090a20ull,0x203233752e6d6172ull,
0x5f5b202c38722509ull,0x726170616475635full,0x5f6b35315a5f5f6dull,0x5f746c754d74616dull,
0x536650657669616eull,0x425f6969695f535full,0x093b5d736c6f635full,0x36363a6469202f2full,
0x70616475635f5f20ull,0x35315a5f5f6d7261ull,0x6c754d74616d5f6bull,0x50657669616e5f74ull,
0x6969695f535f5366ull,0x2b736c6f635f425full,0x2e646c090a307830ull,0x36752e6d61726170ull,
0x2c37647225092034ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x754d74616d5f6b35ull,
0x657669616e5f746cull,0x69695f535f536650ull,0x2f2f093b5d425f69ull,0x5f2035373a646920ull,
0x726170616475635full,0x5f6b35315a5f5f6dull,0x5f746c754d74616dull,0x536650657669616eull,
0x425f6969695f535full,0x756d090a3078302bull,0x3233752e6f6c2e6cull,0x25202c3972250920ull,
0x3b337225202c3872ull,0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233752e34ull,
0x397225202c386472ull,0x202020202020203bull,0x7663090a202f2f09ull,0x33752e3436752e74ull,
0x2c39647225092032ull,0x2020203b37722520ull,0x202f2f0920202020ull,0x36752e646461090aull,
0x3031647225092034ull,0x202c39647225202cull,0x2020203b31647225ull,0x6461090a202f2f09ull,
0x2509203436752e64ull,0x7225202c31316472ull,0x31647225202c3864ull,0x202f2f0920203b30ull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c323164ull,0x20203b34202c3131ull,
0x6461090a202f2f09ull,0x2509203436752e64ull,0x7225202c33316472ull,0x31647225202c3764ull,
0x202f2f0920203b32ull,0x33752e766f6d090aull,0x2c30317225092032ull,0x20202020203b3020ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e656c2e7074ull,0x202c317025092032ull,
0x317225202c357225ull,0x202f2f0920203b30ull,0x33662e766f6d090aull,0x202c316625092032ull,
0x3030303030306630ull,0x20202020203b3030ull,0x40090a30202f2f09ull,0x2061726220317025ull,
0x315f305f744c2409ull,0x2020202020203b33ull,0x2f2f092020202020ull,0x752e766f6d090a20ull,
0x3164722509203436ull,0x6475635f5f202c34ull,0x636f6c625f425f61ull,0x202f2f093b36336bull,
0x36752e766f6d090aull,0x3531647225092034ull,0x616475635f5f202cull,0x6b636f6c625f415full,
0x2f2f093b30363031ull,0x732e646461090a20ull,0x3131722509203233ull,0x31202c357225202cull,
0x2020202020203b35ull,0x73090a202f2f0920ull,0x09203233732e7268ull,0x7225202c32317225ull,
0x203b3133202c3131ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3331722509203233ull,
0x2020203b3531202cull,0x2020202020202020ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x7225202c34317225ull,0x33317225202c3231ull,0x2f2f09202020203bull,0x732e646461090a20ull,
0x3531722509203233ull,0x202c34317225202cull,0x2020203b31317225ull,0x73090a202f2f0920ull,
0x09203233732e7268ull,0x7225202c36317225ull,0x20203b34202c3531ull,0x2f2f092020202020ull,
0x752e747663090a20ull,0x09203233752e3436ull,0x25202c3631647225ull,0x20202020203b3372ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3731647225092034ull,0x202c31647225202cull,
0x2f2f092020203b34ull,0x752e646461090a20ull,0x3164722509203436ull,0x3431647225202c38ull,
0x3b3731647225202cull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3931647225092034ull,
0x2c3631647225202cull,0x2f2f09203b343620ull,0x752e646461090a20ull,0x3264722509203436ull,
0x3531647225202c30ull,0x3b3931647225202cull,0x6d090a202f2f0920ull,0x33732e6f6c2e6c75ull,
0x2c37317225092032ull,0x3631202c38722520ull,0x2f2f09202020203bull,0x732e747663090a20ull,
0x09203233732e3436ull,0x25202c3132647225ull,0x202020203b373172ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3232647225092034ull,0x2c3132647225202cull,0x2f2f0920203b3420ull,
0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c33326472ull,0x3b3631202c363164ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3432647225ull,0x647225202c316472ull,
0x2f2f0920203b3332ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c35326472ull,
0x203b34202c343264ull,0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3632647225ull,
0x7225202c35326472ull,0x2f2f09203b353164ull,0x752e646461090a20ull,0x3264722509203436ull,
0x3532647225202c37ull,0x3b3431647225202cull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x3b30202c38317225ull,0x2020202020202020ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3931722509203233ull,0x203b36317225202cull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x0a3a31315f305f74ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x73656e202c373320ull,0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,
0x6974617265746920ull,0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x343409353109636full,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x202c326625092032ull,0x5d302b366472255bull,
0x6469202f2f09203bull,0x2e7473090a36373aull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d302b3632ull,0x69202f2f093b3266ull,0x635f5f2037373a64ull,0x6c625f415f616475ull,
0x2b303630316b636full,0x6f6c2e090a307830ull,0x0935340935310963ull,0x732e726162090a30ull,
0x203b300920636e79ull,0x2020202020202020ull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3409353109636f6cull,0x2e646c090a300936ull,0x662e6c61626f6c67ull,0x2c33662509203233ull,
0x2b33316472255b20ull,0x69202f2f093b5d30ull,0x7473090a38373a64ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x202c5d302b373264ull,0x202f2f093b336625ull,0x5f5f2039373a6469ull,
0x625f425f61647563ull,0x302b36336b636f6cull,0x636f6c2e090a3078ull,0x3009373409353109ull,
0x79732e726162090aull,0x20203b300920636eull,0x2020202020202020ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x303509353109636full,0x732e646c090a3009ull,0x33662e6465726168ull,
0x202c346625092032ull,0x302b30326472255bull,0x6469202f2f093b5dull,0x75635f5f2030383aull,
0x6f6c625f415f6164ull,0x302b303630316b63ull,0x732e646c090a3078ull,0x33662e6465726168ull,
0x202c356625092032ull,0x302b38316472255bull,0x6469202f2f093b5dull,0x75635f5f2031383aull,
0x6f6c625f425f6164ull,0x3078302b36336b63ull,0x33662e64616d090aull,0x202c316625092032ull,
0x356625202c346625ull,0x20203b316625202cull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3666250920323366ull,0x30326472255b202cull,0x202f2f093b5d342bull,0x5f5f2032383a6469ull,
0x625f415f61647563ull,0x303630316b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x3766250920323366ull,0x38316472255b202cull,0x2f2f093b5d34362bull,0x5f2033383a646920ull,
0x5f425f616475635full,0x2b36336b636f6c62ull,0x64616d090a307830ull,0x662509203233662eull,
0x202c366625202c31ull,0x316625202c376625ull,0x0a202f2f0920203bull,0x726168732e646c09ull,
0x09203233662e6465ull,0x72255b202c386625ull,0x093b5d382b303264ull,0x34383a6469202f2full,
0x5f616475635f5f20ull,0x316b636f6c625f41ull,0x0a3078302b303630ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x72255b202c396625ull,0x5d3832312b383164ull,0x3a6469202f2f093bull,
0x6475635f5f203538ull,0x636f6c625f425f61ull,0x0a3078302b36336bull,0x3233662e64616d09ull,
0x25202c3166250920ull,0x2c396625202c3866ull,0x0920203b31662520ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3031662509203233ull,0x30326472255b202cull,0x2f2f093b5d32312bull,
0x5f2036383a646920ull,0x5f415f616475635full,0x3630316b636f6c62ull,0x6c090a3078302b30ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3131ull,0x3b5d3239312b3831ull,
0x383a6469202f2f09ull,0x616475635f5f2037ull,0x6b636f6c625f425full,0x090a3078302b3633ull,
0x203233662e64616dull,0x6625202c31662509ull,0x31316625202c3031ull,0x2f093b316625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x2c32316625092032ull,0x2b30326472255b20ull,
0x202f2f093b5d3631ull,0x5f5f2038383a6469ull,0x625f415f61647563ull,0x303630316b636f6cull,
0x646c090a3078302bull,0x2e6465726168732eull,0x3166250920323366ull,0x316472255b202c33ull,
0x093b5d3635322b38ull,0x39383a6469202f2full,0x5f616475635f5f20ull,0x336b636f6c625f42ull,
0x6d090a3078302b36ull,0x09203233662e6461ull,0x316625202c316625ull,0x2c33316625202c32ull,
0x2f2f093b31662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x202c343166250920ull,
0x322b30326472255bull,0x69202f2f093b5d30ull,0x635f5f2030393a64ull,0x6c625f415f616475ull,
0x2b303630316b636full,0x2e646c090a307830ull,0x662e646572616873ull,0x3531662509203233ull,
0x38316472255b202cull,0x2f093b5d3032332bull,0x2031393a6469202full,0x425f616475635f5full,
0x36336b636f6c625full,0x616d090a3078302bull,0x2509203233662e64ull,0x34316625202c3166ull,
0x202c35316625202cull,0x202f2f093b316625ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3631662509ull,0x34322b3032647225ull,0x6469202f2f093b5dull,0x75635f5f2032393aull,
0x6f6c625f415f6164ull,0x302b303630316b63ull,0x732e646c090a3078ull,0x33662e6465726168ull,
0x2c37316625092032ull,0x2b38316472255b20ull,0x2f2f093b5d343833ull,0x5f2033393a646920ull,
0x5f425f616475635full,0x2b36336b636f6c62ull,0x64616d090a307830ull,0x662509203233662eull,
0x2c36316625202c31ull,0x25202c3731662520ull,0x0a202f2f093b3166ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c38316625ull,0x5d38322b30326472ull,0x3a6469202f2f093bull,
0x6475635f5f203439ull,0x636f6c625f415f61ull,0x78302b303630316bull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c393166250920ull,0x342b38316472255bull,0x202f2f093b5d3834ull,
0x5f5f2035393a6469ull,0x625f425f61647563ull,0x302b36336b636f6cull,0x2e64616d090a3078ull,
0x3166250920323366ull,0x202c38316625202cull,0x6625202c39316625ull,0x090a202f2f093b31ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c303266ull,0x3b5d32332b303264ull,
0x393a6469202f2f09ull,0x616475635f5f2036ull,0x6b636f6c625f415full,0x3078302b30363031ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3132662509ull,0x31352b3831647225ull,
0x69202f2f093b5d32ull,0x635f5f2037393a64ull,0x6c625f425f616475ull,0x78302b36336b636full,
0x662e64616d090a30ull,0x2c31662509203233ull,0x25202c3032662520ull,0x316625202c313266ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3232ull,
0x093b5d36332b3032ull,0x38393a6469202f2full,0x5f616475635f5f20ull,0x316b636f6c625f41ull,
0x0a3078302b303630ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c33326625ull,
0x3637352b38316472ull,0x6469202f2f093b5dull,0x75635f5f2039393aull,0x6f6c625f425f6164ull,
0x3078302b36336b63ull,0x33662e64616d090aull,0x202c316625092032ull,0x6625202c32326625ull,
0x3b316625202c3332ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,
0x326472255b202c34ull,0x2f093b5d30342b30ull,0x3030313a6469202full,0x5f616475635f5f20ull,
0x316b636f6c625f41ull,0x0a3078302b303630ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c35326625ull,0x3034362b38316472ull,0x6469202f2f093b5dull,0x635f5f203130313aull,
0x6c625f425f616475ull,0x78302b36336b636full,0x662e64616d090a30ull,0x2c31662509203233ull,
0x25202c3432662520ull,0x316625202c353266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3632ull,0x093b5d34342b3032ull,0x30313a6469202f2full,
0x616475635f5f2032ull,0x6b636f6c625f415full,0x3078302b30363031ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3732662509ull,0x30372b3831647225ull,0x69202f2f093b5d34ull,
0x5f5f203330313a64ull,0x625f425f61647563ull,0x302b36336b636f6cull,0x2e64616d090a3078ull,
0x3166250920323366ull,0x202c36326625202cull,0x6625202c37326625ull,0x090a202f2f093b31ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c383266ull,0x3b5d38342b303264ull,
0x313a6469202f2f09ull,0x6475635f5f203430ull,0x636f6c625f415f61ull,0x78302b303630316bull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c393266250920ull,0x372b38316472255bull,
0x202f2f093b5d3836ull,0x5f203530313a6469ull,0x5f425f616475635full,0x2b36336b636f6c62ull,
0x64616d090a307830ull,0x662509203233662eull,0x2c38326625202c31ull,0x25202c3932662520ull,
0x0a202f2f093b3166ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c30336625ull,
0x5d32352b30326472ull,0x3a6469202f2f093bull,0x75635f5f20363031ull,0x6f6c625f415f6164ull,
0x302b303630316b63ull,0x732e646c090a3078ull,0x33662e6465726168ull,0x2c31336625092032ull,
0x2b38316472255b20ull,0x2f2f093b5d323338ull,0x203730313a646920ull,0x425f616475635f5full,
0x36336b636f6c625full,0x616d090a3078302bull,0x2509203233662e64ull,0x30336625202c3166ull,
0x202c31336625202cull,0x202f2f093b316625ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3233662509ull,0x36352b3032647225ull,0x6469202f2f093b5dull,0x635f5f203830313aull,
0x6c625f415f616475ull,0x2b303630316b636full,0x2e646c090a307830ull,0x662e646572616873ull,
0x3333662509203233ull,0x38316472255b202cull,0x2f093b5d3639382bull,0x3930313a6469202full,
0x5f616475635f5f20ull,0x336b636f6c625f42ull,0x6d090a3078302b36ull,0x09203233662e6461ull,
0x336625202c316625ull,0x2c33336625202c32ull,0x2f2f093b31662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x202c343366250920ull,0x362b30326472255bull,0x69202f2f093b5d30ull,
0x5f5f203031313a64ull,0x625f415f61647563ull,0x303630316b636f6cull,0x646c090a3078302bull,
0x2e6465726168732eull,0x3366250920323366ull,0x316472255b202c35ull,0x093b5d3036392b38ull,
0x31313a6469202f2full,0x616475635f5f2031ull,0x6b636f6c625f425full,0x090a3078302b3633ull,
0x203233662e64616dull,0x6625202c31662509ull,0x35336625202c3433ull,0x2f093b316625202cull,
0x636f6c2e090a202full,0x3009323509353109ull,0x79732e726162090aull,0x20203b300920636eull,
0x2020202020202020ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x333509353109636full,
0x2e646461090a3009ull,0x6472250920343675ull,0x2c36647225202c36ull,0x202020203b343620ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6461090a30093435ull,0x2509203436752e64ull,
0x7225202c33316472ull,0x647225202c323264ull,0x202f2f09203b3331ull,0x33732e646461090aull,
0x2c38317225092032ull,0x31202c3831722520ull,0x2020202020203b36ull,0x6573090a202f2f09ull,
0x33732e746c2e7074ull,0x202c327025092032ull,0x7225202c38317225ull,0x202f2f0920203b35ull,
0x622032702540090aull,0x5f744c2409206172ull,0x2020203b31315f30ull,0x2020202020202020ull,
0x7262090a202f2f09ull,0x240920696e752e61ull,0x203b395f305f744cull,0x2020202020202020ull,
0x202f2f0920202020ull,0x315f305f744c240aull,0x305f744c240a3a33ull,0x6f6c2e090a3a395full,
0x0930360935310963ull,0x61702e646c090a30ull,0x203436752e6d6172ull,0x202c383264722509ull,
0x70616475635f5f5bull,0x35315a5f5f6d7261ull,0x6c754d74616d5f6bull,0x50657669616e5f74ull,
0x6969695f535f5366ull,0x202f2f093b5d435full,0x5f203231313a6469ull,0x726170616475635full,
0x5f6b35315a5f5f6dull,0x5f746c754d74616dull,0x536650657669616eull,0x435f6969695f535full,
0x756d090a3078302bull,0x3233732e6f6c2e6cull,0x202c303272250920ull,0x387225202c347225ull,
0x202f2f092020203bull,0x33752e646461090aull,0x2c31327225092032ull,0x7225202c37722520ull,
0x2020202020203b31ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x327225202c323272ull,
0x3b31327225202c30ull,0x202f2f0920202020ull,0x36732e747663090aull,0x2509203233732e34ull,
0x7225202c39326472ull,0x20202020203b3232ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,
0x2c30336472250920ull,0x202c393264722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,
0x3133647225092034ull,0x2c3832647225202cull,0x203b303364722520ull,0x7473090a202f2f09ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b313364ull,0x202f2f093b316625ull,
0x090a3331313a6469ull,0x09353109636f6c2eull,0x7865090a30093136ull,0x20202020203b7469ull,
0x2020202020202020ull,0x2020202020202020ull,0x202f2f0920202020ull,0x646e6557444c240aull,
0x6d5f6b35315a5f5full,0x6e5f746c754d7461ull,0x5f53665065766961ull,0x090a3a6969695f53ull,
0x315a5f202f2f207dull,0x754d74616d5f6b35ull,0x657669616e5f746cull,0x69695f535f536650ull,
0x746e652e090a0a69ull,0x6b36315a5f207972ull,0x746c754d74616d5full,0x506c6c6f726e755full,
0x6969695f535f5366ull,0x65722e090a7b090aull,0x25203631752e2067ull,0x090a3b3e343c6872ull,
0x33752e206765722eull,0x3e39323c72252032ull,0x206765722e090a3bull,0x647225203436752eull,
0x2e090a3b3e38343cull,0x3233662e20676572ull,0x3b3e35353c662520ull,0x2e206765722e090aull,
0x3c70252064657270ull,0x61702e090a3b3e34ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x6c754d74616d5f6bull,0x6c6c6f726e755f74ull,0x69695f535f536650ull,
0x702e090a3b415f69ull,0x36752e206d617261ull,0x616475635f5f2034ull,0x315a5f5f6d726170ull,
0x754d74616d5f6b36ull,0x6c6f726e755f746cull,0x695f535f5366506cull,0x2e090a3b425f6969ull,
0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x4d74616d5f6b3631ull,
0x6f726e755f746c75ull,0x5f535f5366506c6cull,0x090a3b435f696969ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x74616d5f6b36315aull,0x726e755f746c754dull,
0x535f5366506c6c6full,0x725f415f6969695full,0x702e090a3b73776full,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x754d74616d5f6b36ull,0x6c6f726e755f746cull,
0x695f535f5366506cull,0x6c6f635f415f6969ull,0x7261702e090a3b73ull,0x203233732e206d61ull,
0x6170616475635f5full,0x6b36315a5f5f6d72ull,0x746c754d74616d5full,0x506c6c6f726e755full,
0x6969695f535f5366ull,0x3b736c6f635f425full,0x65726168732e090aull,0x6e67696c612e2064ull,
0x5f2038622e203420ull,0x5f425f616475635full,0x3231326b636f6c62ull,0x3b5d383430325b34ull,
0x65726168732e090aull,0x6e67696c612e2064ull,0x5f2038622e203420ull,0x5f415f616475635full,
0x3731346b636f6c62ull,0x3b5d343230315b32ull,0x3109636f6c2e090aull,0x240a300937370935ull,
0x315a5f5f3142424cull,0x754d74616d5f6b36ull,0x6c6f726e755f746cull,0x695f535f5366506cull,
0x6f6c2e090a3a6969ull,0x0937380935310963ull,0x752e747663090a30ull,0x09203631752e3233ull,
0x697425202c317225ull,0x202020203b782e64ull,0x63090a202f2f0920ull,0x752e3436752e7476ull,
0x3164722509203233ull,0x20203b317225202cull,0x2f2f092020202020ull,0x752e766f6d090a20ull,
0x3168722509203631ull,0x646961746325202cull,0x20202020203b792eull,0x6d090a202f2f0920ull,
0x09203631752e766full,0x6e25202c32687225ull,0x20203b792e646974ull,0x2f2f092020202020ull,
0x772e6c756d090a20ull,0x203631752e656469ull,0x7225202c32722509ull,0x32687225202c3168ull,
0x63090a202f2f093bull,0x752e3233752e7476ull,0x2c33722509203631ull,0x3b792e6469742520ull,
0x2f2f092020202020ull,0x752e646461090a20ull,0x2c34722509203233ull,0x7225202c32722520ull,
0x2020202020203b33ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,0x3572250920323375ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4d74616d5f6b3631ull,0x6f726e755f746c75ull,
0x5f535f5366506c6cull,0x6f635f415f696969ull,0x202f2f093b5d736cull,0x5f203738323a6469ull,
0x726170616475635full,0x5f6b36315a5f5f6dull,0x5f746c754d74616dull,0x66506c6c6f726e75ull,
0x5f6969695f535f53ull,0x302b736c6f635f41ull,0x702e646c090a3078ull,0x3436752e6d617261ull,
0x202c326472250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x6c754d74616d5f6bull,
0x6c6c6f726e755f74ull,0x69695f535f536650ull,0x2f2f093b5d415f69ull,0x203239323a646920ull,
0x6170616475635f5full,0x6b36315a5f5f6d72ull,0x746c754d74616d5full,0x506c6c6f726e755full,
0x6969695f535f5366ull,0x090a3078302b415full,0x752e6f6c2e6c756dull,0x2c36722509203233ull,
0x7225202c34722520ull,0x2f09202020203b35ull,0x2e747663090a202full,0x203233752e343675ull,
0x25202c3364722509ull,0x20202020203b3672ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x25202c3464722509ull,0x647225202c336472ull,0x2f09202020203b31ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c35647225ull,0x20203b34202c3464ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3664722509ull,0x647225202c326472ull,0x2f09202020203b35ull,
0x636f6c2e090a202full,0x3009383809353109ull,0x33752e747663090aull,0x2509203631752e32ull,
0x69746e25202c3772ull,0x202020203b782e64ull,0x7663090a202f2f09ull,0x31752e3233752e74ull,
0x202c387225092036ull,0x782e646961746325ull,0x202f2f092020203bull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x202c387225202c39ull,0x202020203b377225ull,0x756d090a202f2f09ull,
0x3233752e6f6c2e6cull,0x202c303172250920ull,0x203b32202c397225ull,0x202f2f0920202020ull,
0x7261702e646c090aull,0x09203233752e6d61ull,0x5f5b202c31317225ull,0x726170616475635full,
0x5f6b36315a5f5f6dull,0x5f746c754d74616dull,0x66506c6c6f726e75ull,0x5f6969695f535f53ull,
0x3b5d736c6f635f42ull,0x323a6469202f2f09ull,0x6475635f5f203538ull,0x5a5f5f6d72617061ull,
0x4d74616d5f6b3631ull,0x6f726e755f746c75ull,0x5f535f5366506c6cull,0x6f635f425f696969ull,
0x090a3078302b736cull,0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3764ull,
0x5f6d726170616475ull,0x616d5f6b36315a5full,0x6e755f746c754d74ull,0x5f5366506c6c6f72ull,
0x5d425f6969695f53ull,0x3a6469202f2f093bull,0x75635f5f20343932ull,0x5f5f6d7261706164ull,
0x74616d5f6b36315aull,0x726e755f746c754dull,0x535f5366506c6c6full,0x302b425f6969695full,
0x2e6c756d090a3078ull,0x09203233752e6f6cull,0x7225202c32317225ull,0x3b337225202c3131ull,
0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323375ull,0x3b32317225202c38ull,
0x2f09202020202020ull,0x2e747663090a202full,0x203233752e343675ull,0x25202c3964722509ull,
0x202020203b303172ull,0x090a202f2f092020ull,0x203436752e646461ull,0x202c303164722509ull,
0x7225202c39647225ull,0x2f092020203b3164ull,0x2e646461090a202full,0x6472250920343675ull,
0x38647225202c3131ull,0x3b3031647225202cull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x3131647225202c32ull,0x2f0920203b34202cull,0x2e646461090a202full,
0x6472250920343675ull,0x37647225202c3331ull,0x3b3231647225202cull,0x090a202f2f092020ull,
0x203233752e766f6dull,0x30202c3331722509ull,0x202020202020203bull,0x2f09202020202020ull,
0x70746573090a202full,0x203233732e656c2eull,0x7225202c31702509ull,0x3b33317225202c35ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x6630202c31662509ull,0x3030303030303030ull,
0x2f0920202020203bull,0x766f6d090a30202full,0x662509203233662eull,0x3030306630202c32ull,
0x20203b3030303030ull,0x30202f2f09202020ull,0x622031702540090aull,0x5f744c2409206172ull,
0x202020203b395f31ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203436752e76ull,
0x5f5f202c34316472ull,0x625f425f61647563ull,0x343231326b636f6cull,0x6d090a202f2f093bull,
0x09203436752e766full,0x5f202c3531647225ull,0x5f415f616475635full,0x3731346b636f6c62ull,
0x090a202f2f093b32ull,0x203233732e646461ull,0x25202c3431722509ull,0x203b3531202c3572ull,
0x2f09202020202020ull,0x2e726873090a202full,0x3172250920323373ull,0x2c34317225202c35ull,
0x202020203b313320ull,0x090a202f2f092020ull,0x203233732e766f6dull,0x31202c3631722509ull,
0x2020202020203b35ull,0x2f09202020202020ull,0x2e646e61090a202full,0x3172250920323362ull,
0x2c35317225202c37ull,0x20203b3631722520ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x25202c3831722509ull,0x317225202c373172ull,0x2f09202020203b34ull,0x2e726873090a202full,
0x3172250920323373ull,0x2c38317225202c39ull,0x20202020203b3420ull,0x090a202f2f092020ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x3b337225202c3631ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3731647225ull,0x3233202c36316472ull,
0x090a202f2f09203bull,0x2e3436752e747663ull,0x6472250920323375ull,0x3b377225202c3831ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3931647225ull,
0x3b34202c38316472ull,0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323373ull,
0x3b337225202c3032ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x25202c3132647225ull,0x3436202c30326472ull,0x090a202f2f09203bull,0x203436752e646461ull,
0x202c323264722509ull,0x25202c3531647225ull,0x2f09203b31326472ull,0x2e747663090a202full,
0x203233732e343675ull,0x202c333264722509ull,0x202020203b317225ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3264722509203436ull,0x3332647225202c34ull,0x2f0920203b34202cull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3532ull,0x3432647225202c34ull,
0x090a202f2f09203bull,0x732e6f6c2e6c756dull,0x3032722509203233ull,0x202c31317225202cull,
0x2f092020203b3631ull,0x2e747663090a202full,0x203233732e343673ull,0x202c363264722509ull,
0x2020203b30327225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,
0x3632647225202c37ull,0x2f0920203b34202cull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x25202c3832647225ull,0x3631202c36316472ull,0x090a202f2f09203bull,0x203436752e646461ull,
0x202c393264722509ull,0x7225202c31647225ull,0x2f0920203b383264ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x25202c3033647225ull,0x3b34202c39326472ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x202c313364722509ull,0x25202c3531647225ull,0x2f09203b30336472ull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3233ull,0x3b3731647225202cull,
0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,0x3233647225202c33ull,
0x2f0920203b34202cull,0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3433ull,
0x3333647225202c34ull,0x090a202f2f09203bull,0x203233752e646461ull,0x25202c3132722509ull,
0x3b317225202c3772ull,0x2f09202020202020ull,0x2e747663090a202full,0x203233752e343675ull,
0x202c353364722509ull,0x2020203b31327225ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x202c363364722509ull,0x25202c3533647225ull,0x2f09203b37316472ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x25202c3733647225ull,0x3b34202c36336472ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x202c383364722509ull,0x25202c3431647225ull,0x2f09203b37336472ull,
0x2e766f6d090a202full,0x3272250920323373ull,0x2020203b30202c32ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x25202c3332722509ull,0x202020203b393172ull,
0x2f09202020202020ull,0x315f744c240a202full,0x3c2f2f200a3a375full,0x6f4c203e706f6f6cull,
0x2079646f6220706full,0x2c383820656e696cull,0x676e697473656e20ull,0x203a687470656420ull,
0x6d69747365202c31ull,0x6574692064657461ull,0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,
0x3109636f6c2e090aull,0x090a300935390935ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x6472255b202c3366ull,0x2f09203b5d302b36ull,0x3539323a6469202full,0x6168732e7473090aull,
0x203233662e646572ull,0x2b31336472255b09ull,0x3b336625202c5d30ull,0x323a6469202f2f09ull,
0x6475635f5f203639ull,0x636f6c625f415f61ull,0x78302b323731346bull,0x09636f6c2e090a30ull,
0x0a30093639093531ull,0x6e79732e72616209ull,0x2020203b30092063ull,0x2020202020202020ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x0937390935310963ull,0x6c672e646c090a30ull,
0x3233662e6c61626full,0x5b202c3466250920ull,0x5d302b3331647225ull,0x3a6469202f2f093bull,
0x2e7473090a373932ull,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3433ull,
0x69202f2f093b3466ull,0x5f5f203839323a64ull,0x625f425f61647563ull,0x343231326b636f6cull,
0x6c2e090a3078302bull,0x383909353109636full,0x2e646461090a3009ull,0x6472250920343675ull,
0x31647225202c3933ull,0x3331647225202c39ull,0x090a202f2f09203bull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x6472255b202c3566ull,0x2f093b5d302b3933ull,0x3939323a6469202full,
0x6168732e7473090aull,0x203233662e646572ull,0x2b38336472255b09ull,0x3b356625202c5d30ull,
0x333a6469202f2f09ull,0x6475635f5f203030ull,0x636f6c625f425f61ull,0x78302b343231326bull,
0x09636f6c2e090a30ull,0x0a30093939093531ull,0x6e79732e72616209ull,0x2020203b30092063ull,
0x2020202020202020ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3430310935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x202c366625092032ull,0x302b32326472255bull,
0x6469202f2f093b5dull,0x635f5f203130333aull,0x6c625f415f616475ull,0x2b323731346b636full,
0x6f6c2e090a307830ull,0x3530310935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x202c376625092032ull,0x342b32326472255bull,0x6469202f2f093b5dull,0x635f5f203230333aull,
0x6c625f415f616475ull,0x2b323731346b636full,0x6f6c2e090a307830ull,0x3630310935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x202c386625092032ull,0x382b32326472255bull,
0x6469202f2f093b5dull,0x635f5f203330333aull,0x6c625f415f616475ull,0x2b323731346b636full,
0x6f6c2e090a307830ull,0x3730310935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x202c396625092032ull,0x312b32326472255bull,0x69202f2f093b5d32ull,0x5f5f203430333a64ull,
0x625f415f61647563ull,0x323731346b636f6cull,0x6c2e090a3078302bull,0x303109353109636full,
0x2e646c090a300938ull,0x662e646572616873ull,0x3031662509203233ull,0x32326472255b202cull,
0x2f2f093b5d36312bull,0x203530333a646920ull,0x415f616475635f5full,0x31346b636f6c625full,
0x090a3078302b3237ull,0x09353109636f6c2eull,0x6c090a3009393031ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3131ull,0x093b5d30322b3232ull,0x30333a6469202f2full,
0x616475635f5f2036ull,0x6b636f6c625f415full,0x3078302b32373134ull,0x3109636f6c2e090aull,
0x0a30093031310935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c32316625ull,
0x5d34322b32326472ull,0x3a6469202f2f093bull,0x75635f5f20373033ull,0x6f6c625f415f6164ull,
0x302b323731346b63ull,0x636f6c2e090a3078ull,0x0931313109353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c333166250920ull,0x322b32326472255bull,0x69202f2f093b5d38ull,
0x5f5f203830333a64ull,0x625f415f61647563ull,0x323731346b636f6cull,0x6c2e090a3078302bull,
0x313109353109636full,0x2e646c090a300932ull,0x662e646572616873ull,0x3431662509203233ull,
0x32326472255b202cull,0x2f2f093b5d32332bull,0x203930333a646920ull,0x415f616475635f5full,
0x31346b636f6c625full,0x090a3078302b3237ull,0x09353109636f6c2eull,0x6c090a3009333131ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3531ull,0x093b5d36332b3232ull,
0x31333a6469202f2full,0x616475635f5f2030ull,0x6b636f6c625f415full,0x3078302b32373134ull,
0x3109636f6c2e090aull,0x0a30093431310935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c36316625ull,0x5d30342b32326472ull,0x3a6469202f2f093bull,0x75635f5f20313133ull,
0x6f6c625f415f6164ull,0x302b323731346b63ull,0x636f6c2e090a3078ull,0x0935313109353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c373166250920ull,0x342b32326472255bull,
0x69202f2f093b5d34ull,0x5f5f203231333a64ull,0x625f415f61647563ull,0x323731346b636f6cull,
0x6c2e090a3078302bull,0x313109353109636full,0x2e646c090a300936ull,0x662e646572616873ull,
0x3831662509203233ull,0x32326472255b202cull,0x2f2f093b5d38342bull,0x203331333a646920ull,
0x415f616475635f5full,0x31346b636f6c625full,0x090a3078302b3237ull,0x09353109636f6c2eull,
0x6c090a3009373131ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3931ull,
0x093b5d32352b3232ull,0x31333a6469202f2full,0x616475635f5f2034ull,0x6b636f6c625f415full,
0x3078302b32373134ull,0x3109636f6c2e090aull,0x0a30093831310935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c30326625ull,0x5d36352b32326472ull,0x3a6469202f2f093bull,
0x75635f5f20353133ull,0x6f6c625f415f6164ull,0x302b323731346b63ull,0x636f6c2e090a3078ull,
0x0939313109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c313266250920ull,
0x362b32326472255bull,0x69202f2f093b5d30ull,0x5f5f203631333a64ull,0x625f415f61647563ull,
0x323731346b636f6cull,0x6c2e090a3078302bull,0x323109353109636full,0x2e646c090a300931ull,
0x662e646572616873ull,0x3232662509203233ull,0x35326472255b202cull,0x202f2f093b5d302bull,
0x5f203731333a6469ull,0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,
0x09203233662e6461ull,0x326625202c326625ull,0x202c366625202c32ull,0x2f2f09203b326625ull,
0x09636f6c2e090a20ull,0x3009323231093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3332662509ull,0x32312b3532647225ull,0x69202f2f093b5d38ull,0x5f5f203831333a64ull,
0x625f425f61647563ull,0x343231326b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x33326625202c3266ull,0x25202c376625202cull,0x202f2f09203b3266ull,0x3109636f6c2e090aull,
0x0a30093332310935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c34326625ull,
0x3635322b35326472ull,0x6469202f2f093b5dull,0x635f5f203931333aull,0x6c625f425f616475ull,
0x2b343231326b636full,0x64616d090a307830ull,0x662509203233662eull,0x2c34326625202c32ull,
0x6625202c38662520ull,0x0a202f2f09203b32ull,0x353109636f6c2e09ull,0x090a300934323109ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c353266ull,0x5d3438332b353264ull,
0x3a6469202f2f093bull,0x75635f5f20303233ull,0x6f6c625f425f6164ull,0x302b343231326b63ull,
0x2e64616d090a3078ull,0x3266250920323366ull,0x202c35326625202cull,0x326625202c396625ull,
0x090a202f2f09203bull,0x09353109636f6c2eull,0x6c090a3009353231ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3632ull,0x3b5d3231352b3532ull,0x333a6469202f2f09ull,
0x6475635f5f203132ull,0x636f6c625f425f61ull,0x78302b343231326bull,0x662e64616d090a30ull,
0x2c32662509203233ull,0x25202c3632662520ull,0x326625202c303166ull,0x2e090a202f2f093bull,
0x3109353109636f6cull,0x646c090a30093632ull,0x2e6465726168732eull,0x3266250920323366ull,
0x326472255b202c37ull,0x093b5d3034362b35ull,0x32333a6469202f2full,0x616475635f5f2032ull,
0x6b636f6c625f425full,0x3078302b34323132ull,0x33662e64616d090aull,0x202c326625092032ull,
0x6625202c37326625ull,0x3b326625202c3131ull,0x6c2e090a202f2f09ull,0x323109353109636full,
0x2e646c090a300937ull,0x662e646572616873ull,0x3832662509203233ull,0x35326472255b202cull,
0x2f093b5d3836372bull,0x3332333a6469202full,0x5f616475635f5f20ull,0x326b636f6c625f42ull,
0x0a3078302b343231ull,0x3233662e64616d09ull,0x25202c3266250920ull,0x316625202c383266ull,
0x093b326625202c32ull,0x6f6c2e090a202f2full,0x3832310935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c39326625092032ull,0x2b35326472255b20ull,0x2f2f093b5d363938ull,
0x203432333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,
0x203233662e64616dull,0x6625202c32662509ull,0x33316625202c3932ull,0x2f093b326625202cull,
0x636f6c2e090a202full,0x0939323109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c303366250920ull,0x312b35326472255bull,0x2f2f093b5d343230ull,0x203532333a646920ull,
0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,0x203233662e64616dull,
0x6625202c32662509ull,0x34316625202c3033ull,0x2f093b326625202cull,0x636f6c2e090a202full,
0x0930333109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c313366250920ull,
0x312b35326472255bull,0x2f2f093b5d323531ull,0x203632333a646920ull,0x425f616475635f5full,
0x31326b636f6c625full,0x090a3078302b3432ull,0x203233662e64616dull,0x6625202c32662509ull,
0x35316625202c3133ull,0x2f093b326625202cull,0x636f6c2e090a202full,0x0931333109353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c323366250920ull,0x312b35326472255bull,
0x2f2f093b5d303832ull,0x203732333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,
0x090a3078302b3432ull,0x203233662e64616dull,0x6625202c32662509ull,0x36316625202c3233ull,
0x2f093b326625202cull,0x636f6c2e090a202full,0x0932333109353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c333366250920ull,0x312b35326472255bull,0x2f2f093b5d383034ull,
0x203832333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,
0x203233662e64616dull,0x6625202c32662509ull,0x37316625202c3333ull,0x2f093b326625202cull,
0x636f6c2e090a202full,0x0933333109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c343366250920ull,0x312b35326472255bull,0x2f2f093b5d363335ull,0x203932333a646920ull,
0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,0x203233662e64616dull,
0x6625202c32662509ull,0x38316625202c3433ull,0x2f093b326625202cull,0x636f6c2e090a202full,
0x0934333109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c353366250920ull,
0x312b35326472255bull,0x2f2f093b5d343636ull,0x203033333a646920ull,0x425f616475635f5full,
0x31326b636f6c625full,0x090a3078302b3432ull,0x203233662e64616dull,0x6625202c32662509ull,
0x39316625202c3533ull,0x2f093b326625202cull,0x636f6c2e090a202full,0x0935333109353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c363366250920ull,0x312b35326472255bull,
0x2f2f093b5d323937ull,0x203133333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,
0x090a3078302b3432ull,0x203233662e64616dull,0x6625202c32662509ull,0x30326625202c3633ull,
0x2f093b326625202cull,0x636f6c2e090a202full,0x0936333109353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c373366250920ull,0x312b35326472255bull,0x2f2f093b5d303239ull,
0x203233333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,
0x203233662e64616dull,0x6625202c32662509ull,0x31326625202c3733ull,0x2f093b326625202cull,
0x636f6c2e090a202full,0x0930343109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c383366250920ull,0x362b35326472255bull,0x69202f2f093b5d34ull,0x5f5f203333333a64ull,
0x625f425f61647563ull,0x343231326b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x38336625202c3166ull,0x25202c366625202cull,0x202f2f09203b3166ull,0x3109636f6c2e090aull,
0x0a30093134310935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c39336625ull,
0x3239312b35326472ull,0x6469202f2f093b5dull,0x635f5f203433333aull,0x6c625f425f616475ull,
0x2b343231326b636full,0x64616d090a307830ull,0x662509203233662eull,0x2c39336625202c31ull,
0x6625202c37662520ull,0x0a202f2f09203b31ull,0x353109636f6c2e09ull,0x090a300932343109ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c303466ull,0x5d3032332b353264ull,
0x3a6469202f2f093bull,0x75635f5f20353333ull,0x6f6c625f425f6164ull,0x302b343231326b63ull,
0x2e64616d090a3078ull,0x3166250920323366ull,0x202c30346625202cull,0x316625202c386625ull,
0x090a202f2f09203bull,0x09353109636f6c2eull,0x6c090a3009333431ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3134ull,0x3b5d3834342b3532ull,0x333a6469202f2f09ull,
0x6475635f5f203633ull,0x636f6c625f425f61ull,0x78302b343231326bull,0x662e64616d090a30ull,
0x2c31662509203233ull,0x25202c3134662520ull,0x3b316625202c3966ull,0x2e090a202f2f0920ull,
0x3109353109636f6cull,0x646c090a30093434ull,0x2e6465726168732eull,0x3466250920323366ull,
0x326472255b202c32ull,0x093b5d3637352b35ull,0x33333a6469202f2full,0x616475635f5f2037ull,
0x6b636f6c625f425full,0x3078302b34323132ull,0x33662e64616d090aull,0x202c316625092032ull,
0x6625202c32346625ull,0x3b316625202c3031ull,0x6c2e090a202f2f09ull,0x343109353109636full,
0x2e646c090a300935ull,0x662e646572616873ull,0x3334662509203233ull,0x35326472255b202cull,
0x2f093b5d3430372bull,0x3833333a6469202full,0x5f616475635f5f20ull,0x326b636f6c625f42ull,
0x0a3078302b343231ull,0x3233662e64616d09ull,0x25202c3166250920ull,0x316625202c333466ull,
0x093b316625202c31ull,0x6f6c2e090a202f2full,0x3634310935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c34346625092032ull,0x2b35326472255b20ull,0x2f2f093b5d323338ull,
0x203933333a646920ull,0x425f616475635f5full,0x31326b636f6c625full,0x090a3078302b3432ull,
0x203233662e64616dull,0x6625202c31662509ull,0x32316625202c3434ull,0x2f093b316625202cull,
0x636f6c2e090a202full,0x0937343109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c353466250920ull,0x392b35326472255bull,0x202f2f093b5d3036ull,0x5f203034333a6469ull,
0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,0x09203233662e6461ull,
0x346625202c316625ull,0x2c33316625202c35ull,0x2f2f093b31662520ull,0x09636f6c2e090a20ull,
0x3009383431093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3634662509ull,
0x30312b3532647225ull,0x202f2f093b5d3838ull,0x5f203134333a6469ull,0x5f425f616475635full,
0x3231326b636f6c62ull,0x6d090a3078302b34ull,0x09203233662e6461ull,0x346625202c316625ull,
0x2c34316625202c36ull,0x2f2f093b31662520ull,0x09636f6c2e090a20ull,0x3009393431093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3734662509ull,0x32312b3532647225ull,
0x202f2f093b5d3631ull,0x5f203234333a6469ull,0x5f425f616475635full,0x3231326b636f6c62ull,
0x6d090a3078302b34ull,0x09203233662e6461ull,0x346625202c316625ull,0x2c35316625202c37ull,
0x2f2f093b31662520ull,0x09636f6c2e090a20ull,0x3009303531093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3834662509ull,0x33312b3532647225ull,0x202f2f093b5d3434ull,
0x5f203334333a6469ull,0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,
0x09203233662e6461ull,0x346625202c316625ull,0x2c36316625202c38ull,0x2f2f093b31662520ull,
0x09636f6c2e090a20ull,0x3009313531093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3934662509ull,0x34312b3532647225ull,0x202f2f093b5d3237ull,0x5f203434333a6469ull,
0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,0x09203233662e6461ull,
0x346625202c316625ull,0x2c37316625202c39ull,0x2f2f093b31662520ull,0x09636f6c2e090a20ull,
0x3009323531093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3035662509ull,
0x36312b3532647225ull,0x202f2f093b5d3030ull,0x5f203534333a6469ull,0x5f425f616475635full,
0x3231326b636f6c62ull,0x6d090a3078302b34ull,0x09203233662e6461ull,0x356625202c316625ull,
0x2c38316625202c30ull,0x2f2f093b31662520ull,0x09636f6c2e090a20ull,0x3009333531093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3135662509ull,0x37312b3532647225ull,
0x202f2f093b5d3832ull,0x5f203634333a6469ull,0x5f425f616475635full,0x3231326b636f6c62ull,
0x6d090a3078302b34ull,0x09203233662e6461ull,0x356625202c316625ull,0x2c39316625202c31ull,
0x2f2f093b31662520ull,0x09636f6c2e090a20ull,0x3009343531093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3235662509ull,0x38312b3532647225ull,0x202f2f093b5d3635ull,
0x5f203734333a6469ull,0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,
0x09203233662e6461ull,0x356625202c316625ull,0x2c30326625202c32ull,0x2f2f093b31662520ull,
0x09636f6c2e090a20ull,0x3009353531093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3335662509ull,0x39312b3532647225ull,0x202f2f093b5d3438ull,0x5f203834333a6469ull,
0x5f425f616475635full,0x3231326b636f6c62ull,0x6d090a3078302b34ull,0x09203233662e6461ull,
0x356625202c316625ull,0x2c31326625202c33ull,0x2f2f093b31662520ull,0x09636f6c2e090a20ull,
0x3009373531093531ull,0x79732e726162090aull,0x20203b300920636eull,0x2020202020202020ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x353109353109636full,0x646461090a300938ull,
0x722509203436752eull,0x36647225202c3664ull,0x2020203b3436202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300939353109ull,0x203436752e646461ull,0x202c333164722509ull,
0x25202c3732647225ull,0x2f09203b33316472ull,0x2e646461090a202full,0x3272250920323373ull,
0x2c32327225202c32ull,0x202020203b363120ull,0x090a202f2f092020ull,0x2e746c2e70746573ull,
0x3270250920323373ull,0x202c32327225202cull,0x2f0920203b357225ull,0x32702540090a202full,
0x4c24092061726220ull,0x20203b375f315f74ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x355f315f744c2409ull,0x202020202020203bull,0x2f09202020202020ull,
0x315f744c240a202full,0x5f744c240a3a395full,0x6c2e090a3a355f31ull,0x363109353109636full,
0x6c756d090a300934ull,0x203233732e6f6c2eull,0x25202c3432722509ull,0x31317225202c3472ull,
0x0a202f2f0920203bull,0x3233752e64646109ull,0x202c353272250920ull,0x7225202c30317225ull,
0x0920202020203b31ull,0x646461090a202f2full,0x722509203233732eull,0x34327225202c3632ull,
0x203b35327225202cull,0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5b202c30346472ull,0x726170616475635full,0x5f6b36315a5f5f6dull,0x5f746c754d74616dull,
0x66506c6c6f726e75ull,0x5f6969695f535f53ull,0x69202f2f093b5d43ull,0x5f5f203138323a64ull,
0x6d72617061647563ull,0x6d5f6b36315a5f5full,0x755f746c754d7461ull,0x5366506c6c6f726eull,
0x435f6969695f535full,0x7663090a3078302bull,0x33732e3436732e74ull,0x3134647225092032ull,
0x203b36327225202cull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c323464ull,0x20203b34202c3134ull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x7225202c33346472ull,0x647225202c303464ull,0x202f2f09203b3234ull,0x6f6c672e7473090aull,
0x203233662e6c6162ull,0x2b33346472255b09ull,0x3b326625202c5d30ull,0x333a6469202f2f09ull,
0x636f6c2e090a3934ull,0x0935363109353109ull,0x752e646461090a30ull,0x3732722509203233ull,
0x202c36327225202cull,0x202020203b377225ull,0x63090a202f2f0920ull,0x752e3436752e7476ull,
0x3464722509203233ull,0x3b37327225202c34ull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,
0x2509203436752e6full,0x7225202c35346472ull,0x203b34202c343464ull,0x61090a202f2f0920ull,
0x09203436752e6464ull,0x25202c3634647225ull,0x7225202c30346472ull,0x2f2f09203b353464ull,
0x6c672e7473090a20ull,0x3233662e6c61626full,0x36346472255b0920ull,0x316625202c5d302bull,
0x3a6469202f2f093bull,0x6f6c2e090a303533ull,0x3636310935310963ull,0x74697865090a3009ull,
0x202020202020203bull,0x2020202020202020ull,0x2020202020202020ull,0x240a202f2f092020ull,
0x5f5f646e6557444cull,0x74616d5f6b36315aull,0x726e755f746c754dull,0x535f5366506c6c6full,
0x7d090a3a6969695full,0x36315a5f202f2f20ull,0x6c754d74616d5f6bull,0x6c6c6f726e755f74ull,
0x69695f535f536650ull,0x746e652e090a0a69ull,0x6b37315a5f207972ull,0x746c754d74616d5full,
0x326c6c6f726e755full,0x69695f535f536650ull,0x722e090a7b090a69ull,0x203631752e206765ull,
0x0a3b3e343c687225ull,0x752e206765722e09ull,0x39333c7225203233ull,0x6765722e090a3b3eull,
0x7225203436752e20ull,0x090a3b3e36383c64ull,0x33662e206765722eull,0x3839323c66252032ull,
0x6765722e090a3b3eull,0x2520646572702e20ull,0x2e090a3b3e343c70ull,0x752e206d61726170ull,
0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x4d74616d5f6b3731ull,0x6f726e755f746c75ull,
0x535f536650326c6cull,0x0a3b415f6969695full,0x206d617261702e09ull,0x635f5f203436752eull,
0x5f6d726170616475ull,0x616d5f6b37315a5full,0x6e755f746c754d74ull,0x536650326c6c6f72ull,
0x425f6969695f535full,0x617261702e090a3bull,0x5f203436752e206dull,0x726170616475635full,
0x5f6b37315a5f5f6dull,0x5f746c754d74616dull,0x50326c6c6f726e75ull,0x6969695f535f5366ull,
0x705f6c61765f5f5full,0x090a3b436d617261ull,0x2e206d617261702eull,0x75635f5f20323373ull,
0x5f5f6d7261706164ull,0x74616d5f6b37315aull,0x726e755f746c754dull,0x5f536650326c6c6full,
0x5f415f6969695f53ull,0x2e090a3b73776f72ull,0x732e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x4d74616d5f6b3731ull,0x6f726e755f746c75ull,0x535f536650326c6cull,
0x635f415f6969695full,0x702e090a3b736c6full,0x33732e206d617261ull,0x616475635f5f2032ull,
0x315a5f5f6d726170ull,0x754d74616d5f6b37ull,0x6c6f726e755f746cull,0x5f535f536650326cull,
0x6f635f425f696969ull,0x68732e090a3b736cull,0x6c612e2064657261ull,0x622e2034206e6769ull,
0x616475635f5f2038ull,0x6b636f6c625f415full,0x3930345b36333235ull,0x68732e090a3b5d36ull,
0x6c612e2064657261ull,0x622e2034206e6769ull,0x616475635f5f2038ull,0x6b636f6c625f425full,
0x3930345b32333339ull,0x6f6c2e090a3b5d36ull,0x3632320935310963ull,0x3142424c240a3009ull,
0x6d5f6b37315a5f5full,0x755f746c754d7461ull,0x6650326c6c6f726eull,0x3a6969695f535f53ull,
0x3109636f6c2e090aull,0x0a30093933320935ull,0x3631752e766f6d09ull,0x202c316872250920ull,
0x792e646961746325ull,0x092020202020203bull,0x766f6d090a202f2full,0x722509203631752eull,
0x69746e25202c3268ull,0x202020203b792e64ull,0x0a202f2f09202020ull,0x6469772e6c756d09ull,
0x2509203631752e65ull,0x31687225202c3172ull,0x093b32687225202cull,0x747663090a202f2full,
0x3631752e3233752eull,0x25202c3272250920ull,0x20203b782e646974ull,0x0a202f2f09202020ull,
0x3436752e74766309ull,0x722509203233752eull,0x3b327225202c3164ull,0x0920202020202020ull,
0x6c756d090a202f2full,0x203233752e6f6c2eull,0x7225202c33722509ull,0x2020203b34202c31ull,
0x0a202f2f09202020ull,0x3233752e74766309ull,0x722509203631752eull,0x2e64697425202c34ull,
0x0920202020203b79ull,0x646461090a202f2full,0x722509203233752eull,0x202c337225202c35ull,
0x202020203b347225ull,0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203233732e6dull,
0x635f5f5b202c3672ull,0x5f6d726170616475ull,0x616d5f6b37315a5full,0x6e755f746c754d74ull,
0x536650326c6c6f72ull,0x415f6969695f535full,0x093b5d736c6f635full,0x37313a6469202f2full,
0x6475635f5f203330ull,0x5a5f5f6d72617061ull,0x4d74616d5f6b3731ull,0x6f726e755f746c75ull,
0x535f536650326c6cull,0x635f415f6969695full,0x0a3078302b736c6full,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5f5b202c326472ull,0x6d72617061647563ull,0x6d5f6b37315a5f5full,
0x755f746c754d7461ull,0x6650326c6c6f726eull,0x5f6969695f535f53ull,0x69202f2f093b5d41ull,
0x5f20383037313a64ull,0x726170616475635full,0x5f6b37315a5f5f6dull,0x5f746c754d74616dull,
0x50326c6c6f726e75ull,0x6969695f535f5366ull,0x090a3078302b415full,0x732e6f6c2e6c756dull,
0x2c37722509203233ull,0x7225202c36722520ull,0x2f09202020203b35ull,0x2e747663090a202full,
0x203233732e343673ull,0x25202c3364722509ull,0x20202020203b3772ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3464722509ull,0x647225202c336472ull,0x2f09202020203b31ull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c35647225ull,0x20203b34202c3464ull,
0x090a202f2f092020ull,0x203436752e646461ull,0x25202c3664722509ull,0x647225202c326472ull,
0x2f09202020203b35ull,0x636f6c2e090a202full,0x0930343209353109ull,0x752e747663090a30ull,
0x09203631752e3233ull,0x746e25202c387225ull,0x2020203b782e6469ull,0x63090a202f2f0920ull,
0x752e3233752e7476ull,0x2c39722509203631ull,0x2e64696174632520ull,0x2f2f092020203b78ull,
0x6c2e6c756d090a20ull,0x2509203233752e6full,0x397225202c303172ull,0x20203b387225202cull,
0x6d090a202f2f0920ull,0x33752e6f6c2e6c75ull,0x2c31317225092032ull,0x34202c3031722520ull,
0x2f2f09202020203bull,0x752e646461090a20ull,0x3231722509203233ull,0x25202c327225202cull,
0x202020203b313172ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,0x3172250920323373ull,
0x75635f5f5b202c33ull,0x5f5f6d7261706164ull,0x74616d5f6b37315aull,0x726e755f746c754dull,
0x5f536650326c6c6full,0x5f425f6969695f53ull,0x2f093b5d736c6f63ull,0x3037313a6469202full,
0x616475635f5f2031ull,0x315a5f5f6d726170ull,0x754d74616d5f6b37ull,0x6c6f726e755f746cull,
0x5f535f536650326cull,0x6f635f425f696969ull,0x090a3078302b736cull,0x6d617261702e646cull,
0x722509203436752eull,0x635f5f5b202c3764ull,0x5f6d726170616475ull,0x616d5f6b37315a5full,
0x6e755f746c754d74ull,0x536650326c6c6f72ull,0x425f6969695f535full,0x6469202f2f093b5dull,
0x5f5f20303137313aull,0x6d72617061647563ull,0x6d5f6b37315a5f5full,0x755f746c754d7461ull,
0x6650326c6c6f726eull,0x5f6969695f535f53ull,0x63090a3078302b42ull,0x732e3436752e7476ull,
0x3864722509203233ull,0x203b32317225202cull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,
0x2509203233752e6full,0x317225202c343172ull,0x203b347225202c33ull,0x63090a202f2f0920ull,
0x752e3436752e7476ull,0x3964722509203233ull,0x203b34317225202cull,0x2f2f092020202020ull,
0x752e646461090a20ull,0x3164722509203436ull,0x2c38647225202c30ull,0x20203b3964722520ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3131647225092034ull,0x2c3031647225202cull,
0x2f2f0920203b3420ull,0x752e646461090a20ull,0x3164722509203436ull,0x2c37647225202c32ull,
0x203b313164722520ull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c35317225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e656cull,
0x367225202c317025ull,0x203b35317225202cull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x306630202c316625ull,0x3b30303030303030ull,0x2f2f092020202020ull,0x2e766f6d090a3020ull,
0x3266250920323366ull,0x303030306630202cull,0x2020203b30303030ull,0x0a30202f2f092020ull,
0x3233662e766f6d09ull,0x30202c3366250920ull,0x3030303030303066ull,0x0920202020203b30ull,
0x6f6d090a30202f2full,0x2509203233662e76ull,0x30306630202c3466ull,0x203b303030303030ull,
0x202f2f0920202020ull,0x662e766f6d090a30ull,0x2c35662509203233ull,0x3030303030663020ull,
0x202020203b303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,0x6630202c36662509ull,
0x3030303030303030ull,0x2f0920202020203bull,0x766f6d090a30202full,0x662509203233662eull,
0x3030306630202c37ull,0x20203b3030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,
0x202c386625092032ull,0x3030303030306630ull,0x20202020203b3030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x306630202c396625ull,0x3b30303030303030ull,0x2f2f092020202020ull,
0x2e766f6d090a3020ull,0x3166250920323366ull,0x3030306630202c30ull,0x20203b3030303030ull,
0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c313166250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c323166ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3331662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x30202c3431662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x30306630202c3531ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x33662e766f6d090aull,0x2c36316625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x40090a30202f2f09ull,0x2061726220317025ull,0x395f325f744c2409ull,0x202020202020203bull,
0x2f2f092020202020ull,0x752e766f6d090a20ull,0x3164722509203436ull,0x6475635f5f202c33ull,
0x636f6c625f415f61ull,0x2f093b363332356bull,0x2e766f6d090a202full,0x6472250920343675ull,
0x75635f5f202c3431ull,0x6f6c625f425f6164ull,0x093b323333396b63ull,0x646461090a202f2full,
0x722509203233732eull,0x2c367225202c3631ull,0x202020203b353120ull,0x0a202f2f09202020ull,
0x3233732e72687309ull,0x202c373172250920ull,0x3133202c36317225ull,0x092020202020203bull,
0x766f6d090a202f2full,0x722509203233732eull,0x203b3531202c3831ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x3233622e646e6109ull,0x202c393172250920ull,0x7225202c37317225ull,
0x09202020203b3831ull,0x646461090a202f2full,0x722509203233732eull,0x39317225202c3032ull,
0x203b36317225202cull,0x0a202f2f09202020ull,0x3233732e72687309ull,0x202c313272250920ull,
0x3b34202c30327225ull,0x0920202020202020ull,0x747663090a202f2full,0x3233752e3436752eull,
0x2c35316472250920ull,0x2020203b38722520ull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233752e6full,0x387225202c323272ull,0x092020203b32202cull,0x6c756d090a202f2full,
0x33752e6f6c2e3432ull,0x2c33327225092032ull,0x3b33202c38722520ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x3272250920323373ull,0x2c33317225202c34ull,0x092020203b363120ull,
0x747663090a202f2full,0x3233752e3436752eull,0x2c36316472250920ull,0x2020203b34722520ull,
0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3731ull,
0x0920203b34202c35ull,0x747663090a202f2full,0x3233752e3436752eull,0x2c38316472250920ull,
0x20203b3232722520ull,0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233752eull,
0x327225202c393164ull,0x0920202020203b33ull,0x747663090a202f2full,0x3233732e3436732eull,
0x2c30326472250920ull,0x20203b3432722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x31647225202c3132ull,0x09203b3436202c36ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x202c323264722509ull,0x34202c3831647225ull,0x0a202f2f0920203bull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3332ull,0x0920203b34202c39ull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c343264722509ull,0x34202c3032647225ull,
0x0a202f2f0920203bull,0x2e6f6c2e6c756d09ull,0x3272250920323373ull,0x202c367225202c35ull,
0x09202020203b3631ull,0x747663090a202f2full,0x3233732e3436732eull,0x2c35326472250920ull,
0x20203b3532722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x32647225202c3632ull,0x0920203b34202c35ull,0x6c756d090a202f2full,0x203233732e6f6c2eull,
0x25202c3632722509ull,0x203b3233202c3672ull,0x0a202f2f09202020ull,0x3436732e74766309ull,
0x722509203233732eull,0x327225202c373264ull,0x0920202020203b36ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x202c383264722509ull,0x34202c3732647225ull,0x0a202f2f0920203bull,
0x2e6f6c2e6c756d09ull,0x3272250920323373ull,0x202c367225202c37ull,0x09202020203b3834ull,
0x747663090a202f2full,0x3233732e3436732eull,0x2c39326472250920ull,0x20203b3732722520ull,
0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x32647225202c3033ull,
0x0920203b34202c39ull,0x747663090a202f2full,0x3233732e3436752eull,0x2c31336472250920ull,
0x2020203b34722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x33647225202c3233ull,0x09203b3436202c31ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c333364ull,0x33647225202c3331ull,0x0a202f2f09203b32ull,0x3436752e74766309ull,
0x722509203233732eull,0x327225202c343364ull,0x092020202020203bull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x202c353364722509ull,0x34202c3433647225ull,0x0a202f2f0920203bull,
0x3436752e64646109ull,0x2c36336472250920ull,0x202c343164722520ull,0x09203b3533647225ull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c373364722509ull,0x31202c3631647225ull,
0x0a202f2f09203b36ull,0x3436752e64646109ull,0x2c38336472250920ull,0x25202c3164722520ull,
0x0920203b37336472ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c393364722509ull,
0x34202c3833647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c30346472250920ull,
0x202c333164722520ull,0x09203b3933647225ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c313464ull,0x3132647225202c31ull,0x0a202f2f0920203bull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x34647225202c3234ull,0x0920203b34202c31ull,0x646461090a202f2full,
0x722509203436752eull,0x647225202c333464ull,0x34647225202c3431ull,0x0a202f2f09203b32ull,
0x3233752e64646109ull,0x202c383272250920ull,0x327225202c387225ull,0x092020202020203bull,
0x747663090a202f2full,0x3233752e3436752eull,0x2c34346472250920ull,0x20203b3832722520ull,
0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c35346472250920ull,0x202c343464722520ull,
0x09203b3132647225ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c363464722509ull,
0x34202c3534647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c37346472250920ull,
0x202c343164722520ull,0x09203b3634647225ull,0x646461090a202f2full,0x722509203233752eull,
0x32327225202c3932ull,0x20203b327225202cull,0x0a202f2f09202020ull,0x3436752e74766309ull,
0x722509203233752eull,0x327225202c383464ull,0x0920202020203b39ull,0x646461090a202f2full,
0x722509203436752eull,0x647225202c393464ull,0x32647225202c3834ull,0x0a202f2f09203b31ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x34647225202c3035ull,0x0920203b34202c39ull,
0x646461090a202f2full,0x722509203436752eull,0x647225202c313564ull,0x35647225202c3431ull,
0x0a202f2f09203b30ull,0x3233752e64646109ull,0x202c303372250920ull,0x7225202c33327225ull,
0x0920202020203b32ull,0x747663090a202f2full,0x3233752e3436752eull,0x2c32356472250920ull,
0x20203b3033722520ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c33356472250920ull,
0x202c323564722520ull,0x09203b3132647225ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c343564722509ull,0x34202c3335647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,
0x2c35356472250920ull,0x202c343164722520ull,0x09203b3435647225ull,0x766f6d090a202f2full,
0x722509203233732eull,0x20203b30202c3133ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x3233732e766f6d09ull,0x202c323372250920ull,0x2020203b31327225ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x2f2f200a3a375f32ull,0x4c203e706f6f6c3cull,0x79646f6220706f6full,
0x343220656e696c20ull,0x697473656e202c30ull,0x687470656420676eull,0x747365202c31203aull,
0x6920646574616d69ull,0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,
0x0933363209353109ull,0x6c672e646c090a30ull,0x3233662e6c61626full,0x202c373166250920ull,
0x5d302b366472255bull,0x3a6469202f2f093bull,0x7473090a31313731ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x202c5d302b303464ull,0x2f2f093b37316625ull,0x323137313a646920ull,
0x5f616475635f5f20ull,0x356b636f6c625f41ull,0x0a3078302b363332ull,0x353109636f6c2e09ull,
0x090a300934363209ull,0x203436752e646461ull,0x202c363564722509ull,0x25202c3632647225ull,
0x2f0920203b366472ull,0x672e646c090a202full,0x33662e6c61626f6cull,0x2c38316625092032ull,
0x2b36356472255b20ull,0x69202f2f093b5d30ull,0x090a333137313a64ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x30312b3034647225ull,0x316625202c5d3432ull,0x6469202f2f093b38ull,
0x5f5f20343137313aull,0x625f415f61647563ull,0x363332356b636f6cull,0x6c2e090a3078302bull,
0x363209353109636full,0x726162090a300935ull,0x300920636e79732eull,0x202020202020203bull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300936363209ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c393166ull,0x093b5d302b323164ull,
0x37313a6469202f2full,0x732e7473090a3531ull,0x33662e6465726168ull,0x346472255b092032ull,
0x6625202c5d302b33ull,0x69202f2f093b3931ull,0x5f20363137313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x2e090a3078302b32ull,0x3209353109636f6cull,0x6461090a30093736ull,
0x2509203436752e64ull,0x7225202c37356472ull,0x647225202c373164ull,0x202f2f09203b3231ull,
0x6f6c672e646c090aull,0x203233662e6c6162ull,0x5b202c3032662509ull,0x5d302b3735647225ull,
0x3a6469202f2f093bull,0x7473090a37313731ull,0x2e6465726168732eull,0x72255b0920323366ull,
0x202c5d302b373464ull,0x2f2f093b30326625ull,0x383137313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x353109636f6c2e09ull,0x090a300938363209ull,
0x203436752e646461ull,0x202c383564722509ull,0x25202c3232647225ull,0x2f09203b32316472ull,
0x672e646c090a202full,0x33662e6c61626f6cull,0x2c31326625092032ull,0x2b38356472255b20ull,
0x69202f2f093b5d30ull,0x090a393137313a64ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x5d302b3135647225ull,0x093b31326625202cull,0x37313a6469202f2full,0x6475635f5f203032ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x09636f6c2e090a30ull,0x3009393632093531ull,
0x36752e646461090aull,0x3935647225092034ull,0x2c3332647225202cull,0x203b323164722520ull,
0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3266250920323366ull,0x356472255b202c32ull,
0x2f2f093b5d302b39ull,0x313237313a646920ull,0x6168732e7473090aull,0x203233662e646572ull,
0x2b35356472255b09ull,0x32326625202c5d30ull,0x3a6469202f2f093bull,0x635f5f2032323731ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x6f6c2e090a307830ull,0x3037320935310963ull,
0x2e646461090a3009ull,0x6472250920343675ull,0x32647225202c3036ull,0x3b36647225202c38ull,
0x090a202f2f092020ull,0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c333266ull,
0x093b5d302b303664ull,0x37313a6469202f2full,0x732e7473090a3332ull,0x33662e6465726168ull,
0x346472255b092032ull,0x2c5d383430322b30ull,0x2f093b3332662520ull,0x3237313a6469202full,
0x616475635f5f2034ull,0x6b636f6c625f415full,0x3078302b36333235ull,0x3109636f6c2e090aull,
0x0a30093137320935ull,0x3436752e64646109ull,0x2c31366472250920ull,0x202c303364722520ull,
0x0920203b36647225ull,0x2e646c090a202f2full,0x662e6c61626f6c67ull,0x3432662509203233ull,
0x31366472255b202cull,0x202f2f093b5d302bull,0x0a353237313a6469ull,0x726168732e747309ull,
0x09203233662e6465ull,0x332b30346472255bull,0x6625202c5d323730ull,0x69202f2f093b3432ull,
0x5f20363237313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,0x2e090a3078302b36ull,
0x3209353109636f6cull,0x6162090a30093237ull,0x0920636e79732e72ull,0x2020202020203b30ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093937320935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c35326625ull,0x3b5d302b33336472ull,
0x313a6469202f2f09ull,0x75635f5f20373237ull,0x6f6c625f415f6164ull,0x302b363332356b63ull,
0x732e646c090a3078ull,0x33662e6465726168ull,0x2c36326625092032ull,0x2b33336472255b20ull,
0x69202f2f093b5d34ull,0x5f20383237313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,
0x6c090a3078302b36ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3732ull,
0x2f093b5d382b3333ull,0x3237313a6469202full,0x616475635f5f2039ull,0x6b636f6c625f415full,
0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3832662509ull,
0x32312b3333647225ull,0x6469202f2f093b5dull,0x5f5f20303337313aull,0x625f415f61647563ull,
0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x3266250920323366ull,
0x336472255b202c39ull,0x2f093b5d36312b33ull,0x3337313a6469202full,0x616475635f5f2031ull,
0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3033662509ull,0x30322b3333647225ull,0x6469202f2f093b5dull,0x5f5f20323337313aull,
0x625f415f61647563ull,0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x3366250920323366ull,0x336472255b202c31ull,0x2f093b5d34322b33ull,0x3337313a6469202full,
0x616475635f5f2033ull,0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3233662509ull,0x38322b3333647225ull,0x6469202f2f093b5dull,
0x5f5f20343337313aull,0x625f415f61647563ull,0x363332356b636f6cull,0x646c090a3078302bull,
0x2e6465726168732eull,0x3366250920323366ull,0x336472255b202c33ull,0x2f093b5d32332b33ull,
0x3337313a6469202full,0x616475635f5f2035ull,0x6b636f6c625f415full,0x3078302b36333235ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3433662509ull,0x36332b3333647225ull,
0x6469202f2f093b5dull,0x5f5f20363337313aull,0x625f415f61647563ull,0x363332356b636f6cull,
0x646c090a3078302bull,0x2e6465726168732eull,0x3366250920323366ull,0x336472255b202c35ull,
0x2f093b5d30342b33ull,0x3337313a6469202full,0x616475635f5f2037ull,0x6b636f6c625f415full,
0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3633662509ull,
0x34342b3333647225ull,0x6469202f2f093b5dull,0x5f5f20383337313aull,0x625f415f61647563ull,
0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x3366250920323366ull,
0x336472255b202c37ull,0x2f093b5d38342b33ull,0x3337313a6469202full,0x616475635f5f2039ull,
0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3833662509ull,0x32352b3333647225ull,0x6469202f2f093b5dull,0x5f5f20303437313aull,
0x625f415f61647563ull,0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x3366250920323366ull,0x336472255b202c39ull,0x2f093b5d36352b33ull,0x3437313a6469202full,
0x616475635f5f2031ull,0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3034662509ull,0x30362b3333647225ull,0x6469202f2f093b5dull,
0x5f5f20323437313aull,0x625f415f61647563ull,0x363332356b636f6cull,0x6c2e090a3078302bull,
0x383209353109636full,0x2e646c090a300931ull,0x662e646572616873ull,0x3134662509203233ull,
0x36336472255b202cull,0x202f2f093b5d302bull,0x20333437313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3631662509ull,
0x326625202c313466ull,0x3b36316625202c35ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3466250920323366ull,0x336472255b202c32ull,0x093b5d3635322b36ull,0x37313a6469202f2full,
0x6475635f5f203434ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3631662509203233ull,0x202c32346625202cull,0x6625202c36326625ull,0x0a202f2f093b3631ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c33346625ull,0x3231352b36336472ull,
0x6469202f2f093b5dull,0x5f5f20353437313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x346625202c363166ull,0x2c37326625202c33ull,
0x2f093b3631662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x2c34346625092032ull,
0x2b36336472255b20ull,0x2f2f093b5d383637ull,0x363437313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c363166250920ull,
0x6625202c34346625ull,0x36316625202c3832ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3534ull,0x5d343230312b3633ull,0x3a6469202f2f093bull,
0x635f5f2037343731ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x35346625202c3631ull,0x202c39326625202cull,0x2f2f093b36316625ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x202c363466250920ull,0x312b36336472255bull,
0x2f2f093b5d303832ull,0x383437313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c363166250920ull,0x6625202c36346625ull,
0x36316625202c3033ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3734ull,0x5d363335312b3633ull,0x3a6469202f2f093bull,0x635f5f2039343731ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x37346625202c3631ull,0x202c31336625202cull,0x2f2f093b36316625ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x202c383466250920ull,0x312b36336472255bull,0x2f2f093b5d323937ull,
0x303537313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x202c363166250920ull,0x6625202c38346625ull,0x36316625202c3233ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3934ull,
0x5d383430322b3633ull,0x3a6469202f2f093bull,0x635f5f2031353731ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x39346625202c3631ull,
0x202c33336625202cull,0x2f2f093b36316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x202c303566250920ull,0x322b36336472255bull,0x2f2f093b5d343033ull,0x323537313a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x202c363166250920ull,0x6625202c30356625ull,0x36316625202c3433ull,0x6c090a202f2f093bull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3135ull,0x5d303635322b3633ull,
0x3a6469202f2f093bull,0x635f5f2033353731ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x31356625202c3631ull,0x202c35336625202cull,
0x2f2f093b36316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x202c323566250920ull,
0x322b36336472255bull,0x2f2f093b5d363138ull,0x343537313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c363166250920ull,
0x6625202c32356625ull,0x36316625202c3633ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3335ull,0x5d323730332b3633ull,0x3a6469202f2f093bull,
0x635f5f2035353731ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x33356625202c3631ull,0x202c37336625202cull,0x2f2f093b36316625ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x202c343566250920ull,0x332b36336472255bull,
0x2f2f093b5d383233ull,0x363537313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c363166250920ull,0x6625202c34356625ull,
0x36316625202c3833ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3535ull,0x5d343835332b3633ull,0x3a6469202f2f093bull,0x635f5f2037353731ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x35356625202c3631ull,0x202c39336625202cull,0x2f2f093b36316625ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x202c363566250920ull,0x332b36336472255bull,0x2f2f093b5d303438ull,
0x383537313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x202c363166250920ull,0x6625202c36356625ull,0x36316625202c3034ull,
0x2e090a202f2f093bull,0x3209353109636f6cull,0x646c090a30093438ull,0x2e6465726168732eull,
0x3566250920323366ull,0x336472255b202c37ull,0x2f093b5d34362b36ull,0x3537313a6469202full,
0x616475635f5f2039ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x2c35316625092032ull,0x25202c3735662520ull,0x316625202c353266ull,0x090a202f2f093b35ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c383566ull,0x5d3032332b363364ull,
0x3a6469202f2f093bull,0x635f5f2030363731ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x38356625202c3531ull,0x202c36326625202cull,
0x2f2f093b35316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x202c393566250920ull,
0x352b36336472255bull,0x202f2f093b5d3637ull,0x20313637313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3531662509ull,
0x326625202c393566ull,0x3b35316625202c37ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3666250920323366ull,0x336472255b202c30ull,0x093b5d3233382b36ull,0x37313a6469202f2full,
0x6475635f5f203236ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3531662509203233ull,0x202c30366625202cull,0x6625202c38326625ull,0x0a202f2f093b3531ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c31366625ull,0x3830312b36336472ull,
0x69202f2f093b5d38ull,0x5f20333637313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c35316625ull,0x39326625202c3136ull,
0x093b35316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,0x3236662509203233ull,
0x36336472255b202cull,0x093b5d343433312bull,0x37313a6469202f2full,0x6475635f5f203436ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x3531662509203233ull,
0x202c32366625202cull,0x6625202c30336625ull,0x0a202f2f093b3531ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c33366625ull,0x3036312b36336472ull,0x69202f2f093b5d30ull,
0x5f20353637313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x6625202c35316625ull,0x31336625202c3336ull,0x093b35316625202cull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3436662509203233ull,0x36336472255b202cull,
0x093b5d363538312bull,0x37313a6469202f2full,0x6475635f5f203636ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x3531662509203233ull,0x202c34366625202cull,
0x6625202c32336625ull,0x0a202f2f093b3531ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c35366625ull,0x3131322b36336472ull,0x69202f2f093b5d32ull,0x5f20373637313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x6625202c35316625ull,0x33336625202c3536ull,0x093b35316625202cull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3636662509203233ull,0x36336472255b202cull,0x093b5d383633322bull,
0x37313a6469202f2full,0x6475635f5f203836ull,0x636f6c625f425f61ull,0x78302b323333396bull,
0x662e64616d090a30ull,0x3531662509203233ull,0x202c36366625202cull,0x6625202c34336625ull,
0x0a202f2f093b3531ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c37366625ull,
0x3236322b36336472ull,0x69202f2f093b5d34ull,0x5f20393637313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c35316625ull,
0x35336625202c3736ull,0x093b35316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,
0x3836662509203233ull,0x36336472255b202cull,0x093b5d303838322bull,0x37313a6469202f2full,
0x6475635f5f203037ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3531662509203233ull,0x202c38366625202cull,0x6625202c36336625ull,0x0a202f2f093b3531ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c39366625ull,0x3331332b36336472ull,
0x69202f2f093b5d36ull,0x5f20313737313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c35316625ull,0x37336625202c3936ull,
0x093b35316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,0x3037662509203233ull,
0x36336472255b202cull,0x093b5d323933332bull,0x37313a6469202f2full,0x6475635f5f203237ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x3531662509203233ull,
0x202c30376625202cull,0x6625202c38336625ull,0x0a202f2f093b3531ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c31376625ull,0x3436332b36336472ull,0x69202f2f093b5d38ull,
0x5f20333737313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x6625202c35316625ull,0x39336625202c3137ull,0x093b35316625202cull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3237662509203233ull,0x36336472255b202cull,
0x093b5d343039332bull,0x37313a6469202f2full,0x6475635f5f203437ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x3531662509203233ull,0x202c32376625202cull,
0x6625202c30346625ull,0x0a202f2f093b3531ull,0x353109636f6c2e09ull,0x090a300937383209ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c333766ull,0x5d3832312b363364ull,
0x3a6469202f2f093bull,0x635f5f2035373731ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x33376625202c3431ull,0x202c35326625202cull,
0x2f2f093b34316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x202c343766250920ull,
0x332b36336472255bull,0x202f2f093b5d3438ull,0x20363737313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3431662509ull,
0x326625202c343766ull,0x3b34316625202c36ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3766250920323366ull,0x336472255b202c35ull,0x093b5d3034362b36ull,0x37313a6469202f2full,
0x6475635f5f203737ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3431662509203233ull,0x202c35376625202cull,0x6625202c37326625ull,0x0a202f2f093b3431ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c36376625ull,0x3639382b36336472ull,
0x6469202f2f093b5dull,0x5f5f20383737313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x376625202c343166ull,0x2c38326625202c36ull,
0x2f093b3431662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x2c37376625092032ull,
0x2b36336472255b20ull,0x2f093b5d32353131ull,0x3737313a6469202full,0x616475635f5f2039ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x2c34316625092032ull,
0x25202c3737662520ull,0x316625202c393266ull,0x090a202f2f093b34ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c383766ull,0x383034312b363364ull,0x6469202f2f093b5dull,
0x5f5f20303837313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x376625202c343166ull,0x2c30336625202c38ull,0x2f093b3431662520ull,
0x732e646c090a202full,0x33662e6465726168ull,0x2c39376625092032ull,0x2b36336472255b20ull,
0x2f093b5d34363631ull,0x3837313a6469202full,0x616475635f5f2031ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x2c34316625092032ull,0x25202c3937662520ull,
0x316625202c313366ull,0x090a202f2f093b34ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c303866ull,0x303239312b363364ull,0x6469202f2f093b5dull,0x5f5f20323837313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x386625202c343166ull,0x2c32336625202c30ull,0x2f093b3431662520ull,0x732e646c090a202full,
0x33662e6465726168ull,0x2c31386625092032ull,0x2b36336472255b20ull,0x2f093b5d36373132ull,
0x3837313a6469202full,0x616475635f5f2033ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x2c34316625092032ull,0x25202c3138662520ull,0x316625202c333366ull,
0x090a202f2f093b34ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c323866ull,
0x323334322b363364ull,0x6469202f2f093b5dull,0x5f5f20343837313aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x386625202c343166ull,
0x2c34336625202c32ull,0x2f093b3431662520ull,0x732e646c090a202full,0x33662e6465726168ull,
0x2c33386625092032ull,0x2b36336472255b20ull,0x2f093b5d38383632ull,0x3837313a6469202full,
0x616475635f5f2035ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x2c34316625092032ull,0x25202c3338662520ull,0x316625202c353366ull,0x090a202f2f093b34ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c343866ull,0x343439322b363364ull,
0x6469202f2f093b5dull,0x5f5f20363837313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x386625202c343166ull,0x2c36336625202c34ull,
0x2f093b3431662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x2c35386625092032ull,
0x2b36336472255b20ull,0x2f093b5d30303233ull,0x3837313a6469202full,0x616475635f5f2037ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x2c34316625092032ull,
0x25202c3538662520ull,0x316625202c373366ull,0x090a202f2f093b34ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c363866ull,0x363534332b363364ull,0x6469202f2f093b5dull,
0x5f5f20383837313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x386625202c343166ull,0x2c38336625202c36ull,0x2f093b3431662520ull,
0x732e646c090a202full,0x33662e6465726168ull,0x2c37386625092032ull,0x2b36336472255b20ull,
0x2f093b5d32313733ull,0x3837313a6469202full,0x616475635f5f2039ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x2c34316625092032ull,0x25202c3738662520ull,
0x316625202c393366ull,0x090a202f2f093b34ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c383866ull,0x383639332b363364ull,0x6469202f2f093b5dull,0x5f5f20303937313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x386625202c343166ull,0x2c30346625202c38ull,0x2f093b3431662520ull,0x636f6c2e090a202full,
0x0930393209353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c393866250920ull,
0x312b36336472255bull,0x202f2f093b5d3239ull,0x20313937313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3331662509ull,
0x326625202c393866ull,0x3b33316625202c35ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3966250920323366ull,0x336472255b202c30ull,0x093b5d3834342b36ull,0x37313a6469202f2full,
0x6475635f5f203239ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3331662509203233ull,0x202c30396625202cull,0x6625202c36326625ull,0x0a202f2f093b3331ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c31396625ull,0x3430372b36336472ull,
0x6469202f2f093b5dull,0x5f5f20333937313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x396625202c333166ull,0x2c37326625202c31ull,
0x2f093b3331662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x2c32396625092032ull,
0x2b36336472255b20ull,0x2f2f093b5d303639ull,0x343937313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c333166250920ull,
0x6625202c32396625ull,0x33316625202c3832ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3339ull,0x5d363132312b3633ull,0x3a6469202f2f093bull,
0x635f5f2035393731ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x33396625202c3331ull,0x202c39326625202cull,0x2f2f093b33316625ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x202c343966250920ull,0x312b36336472255bull,
0x2f2f093b5d323734ull,0x363937313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c333166250920ull,0x6625202c34396625ull,
0x33316625202c3033ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3539ull,0x5d383237312b3633ull,0x3a6469202f2f093bull,0x635f5f2037393731ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x35396625202c3331ull,0x202c31336625202cull,0x2f2f093b33316625ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x202c363966250920ull,0x312b36336472255bull,0x2f2f093b5d343839ull,
0x383937313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x202c333166250920ull,0x6625202c36396625ull,0x33316625202c3233ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3739ull,
0x5d303432322b3633ull,0x3a6469202f2f093bull,0x635f5f2039393731ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x37396625202c3331ull,
0x202c33336625202cull,0x2f2f093b33316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x202c383966250920ull,0x322b36336472255bull,0x2f2f093b5d363934ull,0x303038313a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x202c333166250920ull,0x6625202c38396625ull,0x33316625202c3433ull,0x6c090a202f2f093bull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3939ull,0x5d323537322b3633ull,
0x3a6469202f2f093bull,0x635f5f2031303831ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x39396625202c3331ull,0x202c35336625202cull,
0x2f2f093b33316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c30303166250920ull,
0x2b36336472255b20ull,0x2f093b5d38303033ull,0x3038313a6469202full,0x616475635f5f2032ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x2c33316625092032ull,
0x202c303031662520ull,0x6625202c36336625ull,0x0a202f2f093b3331ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3130316625ull,0x32332b3633647225ull,0x202f2f093b5d3436ull,
0x20333038313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,
0x203233662e64616dull,0x25202c3331662509ull,0x6625202c31303166ull,0x33316625202c3733ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c323031ull,
0x303235332b363364ull,0x6469202f2f093b5dull,0x5f5f20343038313aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x316625202c333166ull,
0x38336625202c3230ull,0x093b33316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,
0x3031662509203233ull,0x336472255b202c33ull,0x3b5d363737332b36ull,0x313a6469202f2f09ull,
0x75635f5f20353038ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3166250920323366ull,0x3330316625202c33ull,0x202c39336625202cull,0x2f2f093b33316625ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c34303166250920ull,0x2b36336472255b20ull,
0x2f093b5d32333034ull,0x3038313a6469202full,0x616475635f5f2036ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x2c33316625092032ull,0x202c343031662520ull,
0x6625202c30346625ull,0x0a202f2f093b3331ull,0x353109636f6c2e09ull,0x090a300932393209ull,
0x636e79732e726162ull,0x202020203b300920ull,0x2020202020202020ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0935393209353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c353266250920ull,0x312b33336472255bull,0x2f2f093b5d343230ull,0x373038313a646920ull,
0x5f616475635f5f20ull,0x356b636f6c625f41ull,0x0a3078302b363332ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c36326625ull,0x3230312b33336472ull,0x69202f2f093b5d38ull,
0x5f20383038313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,0x6c090a3078302b36ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3732ull,0x5d323330312b3333ull,
0x3a6469202f2f093bull,0x635f5f2039303831ull,0x6c625f415f616475ull,0x2b363332356b636full,
0x2e646c090a307830ull,0x662e646572616873ull,0x3832662509203233ull,0x33336472255b202cull,
0x093b5d363330312bull,0x38313a6469202f2full,0x6475635f5f203031ull,0x636f6c625f415f61ull,
0x78302b363332356bull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c393266250920ull,
0x312b33336472255bull,0x2f2f093b5d303430ull,0x313138313a646920ull,0x5f616475635f5f20ull,
0x356b636f6c625f41ull,0x0a3078302b363332ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c30336625ull,0x3430312b33336472ull,0x69202f2f093b5d34ull,0x5f20323138313a64ull,
0x5f415f616475635full,0x3332356b636f6c62ull,0x6c090a3078302b36ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3133ull,0x5d383430312b3333ull,0x3a6469202f2f093bull,
0x635f5f2033313831ull,0x6c625f415f616475ull,0x2b363332356b636full,0x2e646c090a307830ull,
0x662e646572616873ull,0x3233662509203233ull,0x33336472255b202cull,0x093b5d323530312bull,
0x38313a6469202f2full,0x6475635f5f203431ull,0x636f6c625f415f61ull,0x78302b363332356bull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c333366250920ull,0x312b33336472255bull,
0x2f2f093b5d363530ull,0x353138313a646920ull,0x5f616475635f5f20ull,0x356b636f6c625f41ull,
0x0a3078302b363332ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c34336625ull,
0x3630312b33336472ull,0x69202f2f093b5d30ull,0x5f20363138313a64ull,0x5f415f616475635full,
0x3332356b636f6c62ull,0x6c090a3078302b36ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3533ull,0x5d343630312b3333ull,0x3a6469202f2f093bull,0x635f5f2037313831ull,
0x6c625f415f616475ull,0x2b363332356b636full,0x2e646c090a307830ull,0x662e646572616873ull,
0x3633662509203233ull,0x33336472255b202cull,0x093b5d383630312bull,0x38313a6469202f2full,
0x6475635f5f203831ull,0x636f6c625f415f61ull,0x78302b363332356bull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c373366250920ull,0x312b33336472255bull,0x2f2f093b5d323730ull,
0x393138313a646920ull,0x5f616475635f5f20ull,0x356b636f6c625f41ull,0x0a3078302b363332ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c38336625ull,0x3730312b33336472ull,
0x69202f2f093b5d36ull,0x5f20303238313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,
0x6c090a3078302b36ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3933ull,
0x5d303830312b3333ull,0x3a6469202f2f093bull,0x635f5f2031323831ull,0x6c625f415f616475ull,
0x2b363332356b636full,0x2e646c090a307830ull,0x662e646572616873ull,0x3034662509203233ull,
0x33336472255b202cull,0x093b5d343830312bull,0x38313a6469202f2full,0x6475635f5f203232ull,
0x636f6c625f415f61ull,0x78302b363332356bull,0x09636f6c2e090a30ull,0x3009383932093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c353031662509ull,0x302b36336472255bull,
0x6469202f2f093b5dull,0x5f5f20333238313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x316625202c323166ull,0x35326625202c3530ull,
0x093b32316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,0x3031662509203233ull,
0x336472255b202c36ull,0x093b5d3635322b36ull,0x38313a6469202f2full,0x6475635f5f203432ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x3231662509203233ull,
0x2c3630316625202cull,0x25202c3632662520ull,0x202f2f093b323166ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c373031662509ull,0x352b36336472255bull,0x202f2f093b5d3231ull,
0x20353238313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,
0x203233662e64616dull,0x25202c3231662509ull,0x6625202c37303166ull,0x32316625202c3732ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c383031ull,
0x5d3836372b363364ull,0x3a6469202f2f093bull,0x635f5f2036323831ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x30316625202c3231ull,
0x2c38326625202c38ull,0x2f093b3231662520ull,0x732e646c090a202full,0x33662e6465726168ull,
0x3930316625092032ull,0x36336472255b202cull,0x093b5d343230312bull,0x38313a6469202f2full,
0x6475635f5f203732ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3231662509203233ull,0x2c3930316625202cull,0x25202c3932662520ull,0x202f2f093b323166ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c303131662509ull,0x312b36336472255bull,
0x2f2f093b5d303832ull,0x383238313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c323166250920ull,0x25202c3031316625ull,
0x316625202c303366ull,0x090a202f2f093b32ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c31313166ull,0x3335312b36336472ull,0x69202f2f093b5d36ull,0x5f20393238313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x6625202c32316625ull,0x336625202c313131ull,0x3b32316625202c31ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3166250920323366ull,0x6472255b202c3231ull,0x5d323937312b3633ull,
0x3a6469202f2f093bull,0x635f5f2030333831ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x31316625202c3231ull,0x2c32336625202c32ull,
0x2f093b3231662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x3331316625092032ull,
0x36336472255b202cull,0x093b5d383430322bull,0x38313a6469202f2full,0x6475635f5f203133ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x3231662509203233ull,
0x2c3331316625202cull,0x25202c3333662520ull,0x202f2f093b323166ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c343131662509ull,0x322b36336472255bull,0x2f2f093b5d343033ull,
0x323338313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x202c323166250920ull,0x25202c3431316625ull,0x316625202c343366ull,
0x090a202f2f093b32ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c35313166ull,
0x3635322b36336472ull,0x69202f2f093b5d30ull,0x5f20333338313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c32316625ull,
0x336625202c353131ull,0x3b32316625202c35ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3631ull,0x5d363138322b3633ull,0x3a6469202f2f093bull,
0x635f5f2034333831ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x31316625202c3231ull,0x2c36336625202c36ull,0x2f093b3231662520ull,
0x732e646c090a202full,0x33662e6465726168ull,0x3731316625092032ull,0x36336472255b202cull,
0x093b5d323730332bull,0x38313a6469202f2full,0x6475635f5f203533ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x3231662509203233ull,0x2c3731316625202cull,
0x25202c3733662520ull,0x202f2f093b323166ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c383131662509ull,0x332b36336472255bull,0x2f2f093b5d383233ull,0x363338313a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x202c323166250920ull,0x25202c3831316625ull,0x316625202c383366ull,0x090a202f2f093b32ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c39313166ull,0x3835332b36336472ull,
0x69202f2f093b5d34ull,0x5f20373338313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c32316625ull,0x336625202c393131ull,
0x3b32316625202c39ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3166250920323366ull,
0x6472255b202c3032ull,0x5d303438332b3633ull,0x3a6469202f2f093bull,0x635f5f2038333831ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x32316625202c3231ull,0x2c30346625202c30ull,0x2f093b3231662520ull,0x636f6c2e090a202full,
0x0931303309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c31323166250920ull,
0x2b36336472255b20ull,0x202f2f093b5d3436ull,0x20393338313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3131662509ull,
0x6625202c31323166ull,0x31316625202c3532ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c323231ull,0x5d3032332b363364ull,0x3a6469202f2f093bull,
0x635f5f2030343831ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x32316625202c3131ull,0x2c36326625202c32ull,0x2f093b3131662520ull,
0x732e646c090a202full,0x33662e6465726168ull,0x3332316625092032ull,0x36336472255b202cull,
0x2f093b5d3637352bull,0x3438313a6469202full,0x616475635f5f2031ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x2c31316625092032ull,0x202c333231662520ull,
0x6625202c37326625ull,0x0a202f2f093b3131ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3432316625ull,0x33382b3633647225ull,0x69202f2f093b5d32ull,0x5f20323438313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x6625202c31316625ull,0x326625202c343231ull,0x3b31316625202c38ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3166250920323366ull,0x6472255b202c3532ull,0x5d383830312b3633ull,
0x3a6469202f2f093bull,0x635f5f2033343831ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x32316625202c3131ull,0x2c39326625202c35ull,
0x2f093b3131662520ull,0x732e646c090a202full,0x33662e6465726168ull,0x3632316625092032ull,
0x36336472255b202cull,0x093b5d343433312bull,0x38313a6469202f2full,0x6475635f5f203434ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x3131662509203233ull,
0x2c3632316625202cull,0x25202c3033662520ull,0x202f2f093b313166ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c373231662509ull,0x312b36336472255bull,0x2f2f093b5d303036ull,
0x353438313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x202c313166250920ull,0x25202c3732316625ull,0x316625202c313366ull,
0x090a202f2f093b31ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c38323166ull,
0x3538312b36336472ull,0x69202f2f093b5d36ull,0x5f20363438313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c31316625ull,
0x336625202c383231ull,0x3b31316625202c32ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3932ull,0x5d323131322b3633ull,0x3a6469202f2f093bull,
0x635f5f2037343831ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x32316625202c3131ull,0x2c33336625202c39ull,0x2f093b3131662520ull,
0x732e646c090a202full,0x33662e6465726168ull,0x3033316625092032ull,0x36336472255b202cull,
0x093b5d383633322bull,0x38313a6469202f2full,0x6475635f5f203834ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x3131662509203233ull,0x2c3033316625202cull,
0x25202c3433662520ull,0x202f2f093b313166ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c313331662509ull,0x322b36336472255bull,0x2f2f093b5d343236ull,0x393438313a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x202c313166250920ull,0x25202c3133316625ull,0x316625202c353366ull,0x090a202f2f093b31ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c32333166ull,0x3838322b36336472ull,
0x69202f2f093b5d30ull,0x5f20303538313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x6625202c31316625ull,0x336625202c323331ull,
0x3b31316625202c36ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3166250920323366ull,
0x6472255b202c3333ull,0x5d363331332b3633ull,0x3a6469202f2f093bull,0x635f5f2031353831ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x33316625202c3131ull,0x2c37336625202c33ull,0x2f093b3131662520ull,0x732e646c090a202full,
0x33662e6465726168ull,0x3433316625092032ull,0x36336472255b202cull,0x093b5d323933332bull,
0x38313a6469202f2full,0x6475635f5f203235ull,0x636f6c625f425f61ull,0x78302b323333396bull,
0x662e64616d090a30ull,0x3131662509203233ull,0x2c3433316625202cull,0x25202c3833662520ull,
0x202f2f093b313166ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c353331662509ull,
0x332b36336472255bull,0x2f2f093b5d383436ull,0x333538313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x202c313166250920ull,
0x25202c3533316625ull,0x316625202c393366ull,0x090a202f2f093b31ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c36333166ull,0x3039332b36336472ull,0x69202f2f093b5d34ull,
0x5f20343538313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x6625202c31316625ull,0x346625202c363331ull,0x3b31316625202c30ull,
0x6c2e090a202f2f09ull,0x303309353109636full,0x2e646c090a300934ull,0x662e646572616873ull,
0x3331662509203233ull,0x336472255b202c37ull,0x093b5d3832312b36ull,0x38313a6469202f2full,
0x6475635f5f203535ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x3031662509203233ull,0x2c3733316625202cull,0x25202c3532662520ull,0x202f2f093b303166ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c383331662509ull,0x332b36336472255bull,
0x202f2f093b5d3438ull,0x20363538313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,
0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3031662509ull,0x6625202c38333166ull,
0x30316625202c3632ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c393331ull,0x5d3034362b363364ull,0x3a6469202f2f093bull,0x635f5f2037353831ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x33316625202c3031ull,0x2c37326625202c39ull,0x2f093b3031662520ull,0x732e646c090a202full,
0x33662e6465726168ull,0x3034316625092032ull,0x36336472255b202cull,0x2f093b5d3639382bull,
0x3538313a6469202full,0x616475635f5f2038ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x2c30316625092032ull,0x202c303431662520ull,0x6625202c38326625ull,
0x0a202f2f093b3031ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3134316625ull,
0x31312b3633647225ull,0x202f2f093b5d3235ull,0x20393538313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3031662509ull,
0x6625202c31343166ull,0x30316625202c3932ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c323431ull,0x383034312b363364ull,0x6469202f2f093b5dull,
0x5f5f20303638313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x316625202c303166ull,0x30336625202c3234ull,0x093b30316625202cull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3431662509203233ull,0x336472255b202c33ull,
0x3b5d343636312b36ull,0x313a6469202f2f09ull,0x75635f5f20313638ull,0x6f6c625f425f6164ull,
0x302b323333396b63ull,0x2e64616d090a3078ull,0x3166250920323366ull,0x3334316625202c30ull,
0x202c31336625202cull,0x2f2f093b30316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x2c34343166250920ull,0x2b36336472255b20ull,0x2f093b5d30323931ull,0x3638313a6469202full,
0x616475635f5f2032ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x2c30316625092032ull,0x202c343431662520ull,0x6625202c32336625ull,0x0a202f2f093b3031ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3534316625ull,0x31322b3633647225ull,
0x202f2f093b5d3637ull,0x20333638313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,
0x090a3078302b3233ull,0x203233662e64616dull,0x25202c3031662509ull,0x6625202c35343166ull,
0x30316625202c3333ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c363431ull,0x323334322b363364ull,0x6469202f2f093b5dull,0x5f5f20343638313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x316625202c303166ull,0x34336625202c3634ull,0x093b30316625202cull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3431662509203233ull,0x336472255b202c37ull,0x3b5d383836322b36ull,
0x313a6469202f2f09ull,0x75635f5f20353638ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,
0x2e64616d090a3078ull,0x3166250920323366ull,0x3734316625202c30ull,0x202c35336625202cull,
0x2f2f093b30316625ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c38343166250920ull,
0x2b36336472255b20ull,0x2f093b5d34343932ull,0x3638313a6469202full,0x616475635f5f2036ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x2c30316625092032ull,
0x202c383431662520ull,0x6625202c36336625ull,0x0a202f2f093b3031ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3934316625ull,0x32332b3633647225ull,0x202f2f093b5d3030ull,
0x20373638313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,
0x203233662e64616dull,0x25202c3031662509ull,0x6625202c39343166ull,0x30316625202c3733ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c303531ull,
0x363534332b363364ull,0x6469202f2f093b5dull,0x5f5f20383638313aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x316625202c303166ull,
0x38336625202c3035ull,0x093b30316625202cull,0x2e646c090a202f2full,0x662e646572616873ull,
0x3531662509203233ull,0x336472255b202c31ull,0x3b5d323137332b36ull,0x313a6469202f2f09ull,
0x75635f5f20393638ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3166250920323366ull,0x3135316625202c30ull,0x202c39336625202cull,0x2f2f093b30316625ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c32353166250920ull,0x2b36336472255b20ull,
0x2f093b5d38363933ull,0x3738313a6469202full,0x616475635f5f2030ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x2c30316625092032ull,0x202c323531662520ull,
0x6625202c30346625ull,0x0a202f2f093b3031ull,0x353109636f6c2e09ull,0x090a300937303309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c33353166ull,0x3239312b36336472ull,
0x6469202f2f093b5dull,0x5f5f20313738313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x35316625202c3966ull,0x2c35326625202c33ull,
0x2f2f093b39662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c34353166250920ull,
0x2b36336472255b20ull,0x2f2f093b5d383434ull,0x323738313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3966250920ull,
0x6625202c34353166ull,0x3b396625202c3632ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3535ull,0x3b5d3430372b3633ull,0x313a6469202f2f09ull,
0x75635f5f20333738ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3966250920323366ull,0x2c3535316625202cull,0x25202c3732662520ull,0x0a202f2f093b3966ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3635316625ull,0x36392b3633647225ull,
0x69202f2f093b5d30ull,0x5f20343738313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x316625202c396625ull,0x38326625202c3635ull,
0x2f093b396625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3735316625092032ull,
0x36336472255b202cull,0x093b5d363132312bull,0x38313a6469202f2full,0x6475635f5f203537ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c39662509203233ull,
0x202c373531662520ull,0x6625202c39326625ull,0x090a202f2f093b39ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c38353166ull,0x3734312b36336472ull,0x69202f2f093b5d32ull,
0x5f20363738313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x316625202c396625ull,0x30336625202c3835ull,0x2f093b396625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3935316625092032ull,0x36336472255b202cull,
0x093b5d383237312bull,0x38313a6469202f2full,0x6475635f5f203737ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c39662509203233ull,0x202c393531662520ull,
0x6625202c31336625ull,0x090a202f2f093b39ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c30363166ull,0x3839312b36336472ull,0x69202f2f093b5d34ull,0x5f20383738313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x316625202c396625ull,0x32336625202c3036ull,0x2f093b396625202cull,0x732e646c090a202full,
0x33662e6465726168ull,0x3136316625092032ull,0x36336472255b202cull,0x093b5d303432322bull,
0x38313a6469202f2full,0x6475635f5f203937ull,0x636f6c625f425f61ull,0x78302b323333396bull,
0x662e64616d090a30ull,0x2c39662509203233ull,0x202c313631662520ull,0x6625202c33336625ull,
0x090a202f2f093b39ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c32363166ull,
0x3934322b36336472ull,0x69202f2f093b5d36ull,0x5f20303838313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x316625202c396625ull,
0x34336625202c3236ull,0x2f093b396625202cull,0x732e646c090a202full,0x33662e6465726168ull,
0x3336316625092032ull,0x36336472255b202cull,0x093b5d323537322bull,0x38313a6469202f2full,
0x6475635f5f203138ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x2c39662509203233ull,0x202c333631662520ull,0x6625202c35336625ull,0x090a202f2f093b39ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c34363166ull,0x3030332b36336472ull,
0x69202f2f093b5d38ull,0x5f20323838313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x316625202c396625ull,0x36336625202c3436ull,
0x2f093b396625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3536316625092032ull,
0x36336472255b202cull,0x093b5d343632332bull,0x38313a6469202f2full,0x6475635f5f203338ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c39662509203233ull,
0x202c353631662520ull,0x6625202c37336625ull,0x090a202f2f093b39ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c36363166ull,0x3235332b36336472ull,0x69202f2f093b5d30ull,
0x5f20343838313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x316625202c396625ull,0x38336625202c3636ull,0x2f093b396625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3736316625092032ull,0x36336472255b202cull,
0x093b5d363737332bull,0x38313a6469202f2full,0x6475635f5f203538ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c39662509203233ull,0x202c373631662520ull,
0x6625202c39336625ull,0x090a202f2f093b39ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c38363166ull,0x3330342b36336472ull,0x69202f2f093b5d32ull,0x5f20363838313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x316625202c396625ull,0x30346625202c3836ull,0x2f093b396625202cull,0x636f6c2e090a202full,
0x0939303309353109ull,0x732e726162090a30ull,0x203b300920636e79ull,0x2020202020202020ull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093231ull,
0x2e6465726168732eull,0x3266250920323366ull,0x336472255b202c35ull,0x3b5d383430322b33ull,
0x313a6469202f2f09ull,0x75635f5f20373838ull,0x6f6c625f415f6164ull,0x302b363332356b63ull,
0x732e646c090a3078ull,0x33662e6465726168ull,0x2c36326625092032ull,0x2b33336472255b20ull,
0x2f093b5d32353032ull,0x3838313a6469202full,0x616475635f5f2038ull,0x6b636f6c625f415full,
0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3732662509ull,
0x30322b3333647225ull,0x202f2f093b5d3635ull,0x20393838313a6469ull,0x415f616475635f5full,
0x32356b636f6c625full,0x090a3078302b3633ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c383266ull,0x303630322b333364ull,0x6469202f2f093b5dull,0x5f5f20303938313aull,
0x625f415f61647563ull,0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x3266250920323366ull,0x336472255b202c39ull,0x3b5d343630322b33ull,0x313a6469202f2f09ull,
0x75635f5f20313938ull,0x6f6c625f415f6164ull,0x302b363332356b63ull,0x732e646c090a3078ull,
0x33662e6465726168ull,0x2c30336625092032ull,0x2b33336472255b20ull,0x2f093b5d38363032ull,
0x3938313a6469202full,0x616475635f5f2032ull,0x6b636f6c625f415full,0x3078302b36333235ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3133662509ull,0x30322b3333647225ull,
0x202f2f093b5d3237ull,0x20333938313a6469ull,0x415f616475635f5full,0x32356b636f6c625full,
0x090a3078302b3633ull,0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c323366ull,
0x363730322b333364ull,0x6469202f2f093b5dull,0x5f5f20343938313aull,0x625f415f61647563ull,
0x363332356b636f6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x3366250920323366ull,
0x336472255b202c33ull,0x3b5d303830322b33ull,0x313a6469202f2f09ull,0x75635f5f20353938ull,
0x6f6c625f415f6164ull,0x302b363332356b63ull,0x732e646c090a3078ull,0x33662e6465726168ull,
0x2c34336625092032ull,0x2b33336472255b20ull,0x2f093b5d34383032ull,0x3938313a6469202full,
0x616475635f5f2036ull,0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3533662509ull,0x30322b3333647225ull,0x202f2f093b5d3838ull,
0x20373938313a6469ull,0x415f616475635f5full,0x32356b636f6c625full,0x090a3078302b3633ull,
0x65726168732e646cull,0x2509203233662e64ull,0x72255b202c363366ull,0x323930322b333364ull,
0x6469202f2f093b5dull,0x5f5f20383938313aull,0x625f415f61647563ull,0x363332356b636f6cull,
0x646c090a3078302bull,0x2e6465726168732eull,0x3366250920323366ull,0x336472255b202c37ull,
0x3b5d363930322b33ull,0x313a6469202f2f09ull,0x75635f5f20393938ull,0x6f6c625f415f6164ull,
0x302b363332356b63ull,0x732e646c090a3078ull,0x33662e6465726168ull,0x2c38336625092032ull,
0x2b33336472255b20ull,0x2f093b5d30303132ull,0x3039313a6469202full,0x616475635f5f2030ull,
0x6b636f6c625f415full,0x3078302b36333235ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3933662509ull,0x31322b3333647225ull,0x202f2f093b5d3430ull,0x20313039313a6469ull,
0x415f616475635f5full,0x32356b636f6c625full,0x090a3078302b3633ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c303466ull,0x383031322b333364ull,0x6469202f2f093b5dull,
0x5f5f20323039313aull,0x625f415f61647563ull,0x363332356b636f6cull,0x6c2e090a3078302bull,
0x313309353109636full,0x2e646c090a300935ull,0x662e646572616873ull,0x3631662509203233ull,
0x336472255b202c39ull,0x2f2f093b5d302b36ull,0x333039313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3866250920ull,
0x6625202c39363166ull,0x3b386625202c3532ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3037ull,0x3b5d3635322b3633ull,0x313a6469202f2f09ull,
0x75635f5f20343039ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3866250920323366ull,0x2c3037316625202cull,0x25202c3632662520ull,0x0a202f2f093b3866ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3137316625ull,0x31352b3633647225ull,
0x69202f2f093b5d32ull,0x5f20353039313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x316625202c386625ull,0x37326625202c3137ull,
0x2f093b386625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3237316625092032ull,
0x36336472255b202cull,0x2f093b5d3836372bull,0x3039313a6469202full,0x616475635f5f2036ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c386625092032ull,
0x25202c3237316625ull,0x386625202c383266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c333731ull,0x343230312b363364ull,0x6469202f2f093b5dull,
0x5f5f20373039313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x37316625202c3866ull,0x2c39326625202c33ull,0x2f2f093b38662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c34373166250920ull,0x2b36336472255b20ull,
0x2f093b5d30383231ull,0x3039313a6469202full,0x616475635f5f2038ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c386625092032ull,0x25202c3437316625ull,
0x386625202c303366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c353731ull,0x363335312b363364ull,0x6469202f2f093b5dull,0x5f5f20393039313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x37316625202c3866ull,0x2c31336625202c35ull,0x2f2f093b38662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c36373166250920ull,0x2b36336472255b20ull,0x2f093b5d32393731ull,
0x3139313a6469202full,0x616475635f5f2030ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c386625092032ull,0x25202c3637316625ull,0x386625202c323366ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c373731ull,
0x383430322b363364ull,0x6469202f2f093b5dull,0x5f5f20313139313aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x37316625202c3866ull,
0x2c33336625202c37ull,0x2f2f093b38662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x2c38373166250920ull,0x2b36336472255b20ull,0x2f093b5d34303332ull,0x3139313a6469202full,
0x616475635f5f2032ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x202c386625092032ull,0x25202c3837316625ull,0x386625202c343366ull,0x6c090a202f2f093bull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c393731ull,0x303635322b363364ull,
0x6469202f2f093b5dull,0x5f5f20333139313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x37316625202c3866ull,0x2c35336625202c39ull,
0x2f2f093b38662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c30383166250920ull,
0x2b36336472255b20ull,0x2f093b5d36313832ull,0x3139313a6469202full,0x616475635f5f2034ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c386625092032ull,
0x25202c3038316625ull,0x386625202c363366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c313831ull,0x323730332b363364ull,0x6469202f2f093b5dull,
0x5f5f20353139313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x38316625202c3866ull,0x2c37336625202c31ull,0x2f2f093b38662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c32383166250920ull,0x2b36336472255b20ull,
0x2f093b5d38323333ull,0x3139313a6469202full,0x616475635f5f2036ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c386625092032ull,0x25202c3238316625ull,
0x386625202c383366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c333831ull,0x343835332b363364ull,0x6469202f2f093b5dull,0x5f5f20373139313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x38316625202c3866ull,0x2c39336625202c33ull,0x2f2f093b38662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c34383166250920ull,0x2b36336472255b20ull,0x2f093b5d30343833ull,
0x3139313a6469202full,0x616475635f5f2038ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c386625092032ull,0x25202c3438316625ull,0x386625202c303466ull,
0x2e090a202f2f093bull,0x3309353109636f6cull,0x646c090a30093831ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3538ull,0x093b5d34362b3633ull,0x39313a6469202f2full,
0x6475635f5f203931ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x2c37662509203233ull,0x202c353831662520ull,0x6625202c35326625ull,0x090a202f2f093b37ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c36383166ull,0x3032332b36336472ull,
0x6469202f2f093b5dull,0x5f5f20303239313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x38316625202c3766ull,0x2c36326625202c36ull,
0x2f2f093b37662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c37383166250920ull,
0x2b36336472255b20ull,0x2f2f093b5d363735ull,0x313239313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3766250920ull,
0x6625202c37383166ull,0x3b376625202c3732ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3838ull,0x3b5d3233382b3633ull,0x313a6469202f2f09ull,
0x75635f5f20323239ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3766250920323366ull,0x2c3838316625202cull,0x25202c3832662520ull,0x0a202f2f093b3766ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3938316625ull,0x30312b3633647225ull,
0x202f2f093b5d3838ull,0x20333239313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,
0x090a3078302b3233ull,0x203233662e64616dull,0x6625202c37662509ull,0x326625202c393831ull,
0x093b376625202c39ull,0x2e646c090a202f2full,0x662e646572616873ull,0x3931662509203233ull,
0x336472255b202c30ull,0x3b5d343433312b36ull,0x313a6469202f2f09ull,0x75635f5f20343239ull,
0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,0x3766250920323366ull,
0x2c3039316625202cull,0x25202c3033662520ull,0x0a202f2f093b3766ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3139316625ull,0x36312b3633647225ull,0x202f2f093b5d3030ull,
0x20353239313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,
0x203233662e64616dull,0x6625202c37662509ull,0x336625202c313931ull,0x093b376625202c31ull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3931662509203233ull,0x336472255b202c32ull,
0x3b5d363538312b36ull,0x313a6469202f2f09ull,0x75635f5f20363239ull,0x6f6c625f425f6164ull,
0x302b323333396b63ull,0x2e64616d090a3078ull,0x3766250920323366ull,0x2c3239316625202cull,
0x25202c3233662520ull,0x0a202f2f093b3766ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3339316625ull,0x31322b3633647225ull,0x202f2f093b5d3231ull,0x20373239313a6469ull,
0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,
0x6625202c37662509ull,0x336625202c333931ull,0x093b376625202c33ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3931662509203233ull,0x336472255b202c34ull,0x3b5d383633322b36ull,
0x313a6469202f2f09ull,0x75635f5f20383239ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,
0x2e64616d090a3078ull,0x3766250920323366ull,0x2c3439316625202cull,0x25202c3433662520ull,
0x0a202f2f093b3766ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3539316625ull,
0x36322b3633647225ull,0x202f2f093b5d3432ull,0x20393239313a6469ull,0x425f616475635f5full,
0x33396b636f6c625full,0x090a3078302b3233ull,0x203233662e64616dull,0x6625202c37662509ull,
0x336625202c353931ull,0x093b376625202c35ull,0x2e646c090a202f2full,0x662e646572616873ull,
0x3931662509203233ull,0x336472255b202c36ull,0x3b5d303838322b36ull,0x313a6469202f2f09ull,
0x75635f5f20303339ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3766250920323366ull,0x2c3639316625202cull,0x25202c3633662520ull,0x0a202f2f093b3766ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3739316625ull,0x31332b3633647225ull,
0x202f2f093b5d3633ull,0x20313339313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,
0x090a3078302b3233ull,0x203233662e64616dull,0x6625202c37662509ull,0x336625202c373931ull,
0x093b376625202c37ull,0x2e646c090a202f2full,0x662e646572616873ull,0x3931662509203233ull,
0x336472255b202c38ull,0x3b5d323933332b36ull,0x313a6469202f2f09ull,0x75635f5f20323339ull,
0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,0x3766250920323366ull,
0x2c3839316625202cull,0x25202c3833662520ull,0x0a202f2f093b3766ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3939316625ull,0x36332b3633647225ull,0x202f2f093b5d3834ull,
0x20333339313a6469ull,0x425f616475635f5full,0x33396b636f6c625full,0x090a3078302b3233ull,
0x203233662e64616dull,0x6625202c37662509ull,0x336625202c393931ull,0x093b376625202c39ull,
0x2e646c090a202f2full,0x662e646572616873ull,0x3032662509203233ull,0x336472255b202c30ull,
0x3b5d343039332b36ull,0x313a6469202f2f09ull,0x75635f5f20343339ull,0x6f6c625f425f6164ull,
0x302b323333396b63ull,0x2e64616d090a3078ull,0x3766250920323366ull,0x2c3030326625202cull,
0x25202c3034662520ull,0x0a202f2f093b3766ull,0x353109636f6c2e09ull,0x090a300931323309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c31303266ull,0x3832312b36336472ull,
0x6469202f2f093b5dull,0x5f5f20353339313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x30326625202c3666ull,0x2c35326625202c31ull,
0x2f2f093b36662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c32303266250920ull,
0x2b36336472255b20ull,0x2f2f093b5d343833ull,0x363339313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3666250920ull,
0x6625202c32303266ull,0x3b366625202c3632ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3330ull,0x3b5d3034362b3633ull,0x313a6469202f2f09ull,
0x75635f5f20373339ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3666250920323366ull,0x2c3330326625202cull,0x25202c3732662520ull,0x0a202f2f093b3666ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3430326625ull,0x39382b3633647225ull,
0x69202f2f093b5d36ull,0x5f20383339313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c366625ull,0x38326625202c3430ull,
0x2f093b366625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3530326625092032ull,
0x36336472255b202cull,0x093b5d323531312bull,0x39313a6469202f2full,0x6475635f5f203933ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c36662509203233ull,
0x202c353032662520ull,0x6625202c39326625ull,0x090a202f2f093b36ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c36303266ull,0x3034312b36336472ull,0x69202f2f093b5d38ull,
0x5f20303439313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x326625202c366625ull,0x30336625202c3630ull,0x2f093b366625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3730326625092032ull,0x36336472255b202cull,
0x093b5d343636312bull,0x39313a6469202f2full,0x6475635f5f203134ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c36662509203233ull,0x202c373032662520ull,
0x6625202c31336625ull,0x090a202f2f093b36ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c38303266ull,0x3239312b36336472ull,0x69202f2f093b5d30ull,0x5f20323439313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x326625202c366625ull,0x32336625202c3830ull,0x2f093b366625202cull,0x732e646c090a202full,
0x33662e6465726168ull,0x3930326625092032ull,0x36336472255b202cull,0x093b5d363731322bull,
0x39313a6469202f2full,0x6475635f5f203334ull,0x636f6c625f425f61ull,0x78302b323333396bull,
0x662e64616d090a30ull,0x2c36662509203233ull,0x202c393032662520ull,0x6625202c33336625ull,
0x090a202f2f093b36ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c30313266ull,
0x3334322b36336472ull,0x69202f2f093b5d32ull,0x5f20343439313a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c366625ull,
0x34336625202c3031ull,0x2f093b366625202cull,0x732e646c090a202full,0x33662e6465726168ull,
0x3131326625092032ull,0x36336472255b202cull,0x093b5d383836322bull,0x39313a6469202f2full,
0x6475635f5f203534ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x2c36662509203233ull,0x202c313132662520ull,0x6625202c35336625ull,0x090a202f2f093b36ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c32313266ull,0x3439322b36336472ull,
0x69202f2f093b5d34ull,0x5f20363439313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c366625ull,0x36336625202c3231ull,
0x2f093b366625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3331326625092032ull,
0x36336472255b202cull,0x093b5d303032332bull,0x39313a6469202f2full,0x6475635f5f203734ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c36662509203233ull,
0x202c333132662520ull,0x6625202c37336625ull,0x090a202f2f093b36ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c34313266ull,0x3534332b36336472ull,0x69202f2f093b5d36ull,
0x5f20383439313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x326625202c366625ull,0x38336625202c3431ull,0x2f093b366625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3531326625092032ull,0x36336472255b202cull,
0x093b5d323137332bull,0x39313a6469202f2full,0x6475635f5f203934ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c36662509203233ull,0x202c353132662520ull,
0x6625202c39336625ull,0x090a202f2f093b36ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c36313266ull,0x3639332b36336472ull,0x69202f2f093b5d38ull,0x5f20303539313a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x326625202c366625ull,0x30346625202c3631ull,0x2f093b366625202cull,0x636f6c2e090a202full,
0x0934323309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c37313266250920ull,
0x2b36336472255b20ull,0x2f2f093b5d323931ull,0x313539313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3566250920ull,
0x6625202c37313266ull,0x3b356625202c3532ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3831ull,0x3b5d3834342b3633ull,0x313a6469202f2f09ull,
0x75635f5f20323539ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3566250920323366ull,0x2c3831326625202cull,0x25202c3632662520ull,0x0a202f2f093b3566ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3931326625ull,0x30372b3633647225ull,
0x69202f2f093b5d34ull,0x5f20333539313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c356625ull,0x37326625202c3931ull,
0x2f093b356625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3032326625092032ull,
0x36336472255b202cull,0x2f093b5d3036392bull,0x3539313a6469202full,0x616475635f5f2034ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c356625092032ull,
0x25202c3032326625ull,0x356625202c383266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c313232ull,0x363132312b363364ull,0x6469202f2f093b5dull,
0x5f5f20353539313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x32326625202c3566ull,0x2c39326625202c31ull,0x2f2f093b35662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c32323266250920ull,0x2b36336472255b20ull,
0x2f093b5d32373431ull,0x3539313a6469202full,0x616475635f5f2036ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c356625092032ull,0x25202c3232326625ull,
0x356625202c303366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c333232ull,0x383237312b363364ull,0x6469202f2f093b5dull,0x5f5f20373539313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x32326625202c3566ull,0x2c31336625202c33ull,0x2f2f093b35662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c34323266250920ull,0x2b36336472255b20ull,0x2f093b5d34383931ull,
0x3539313a6469202full,0x616475635f5f2038ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c356625092032ull,0x25202c3432326625ull,0x356625202c323366ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c353232ull,
0x303432322b363364ull,0x6469202f2f093b5dull,0x5f5f20393539313aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x32326625202c3566ull,
0x2c33336625202c35ull,0x2f2f093b35662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x2c36323266250920ull,0x2b36336472255b20ull,0x2f093b5d36393432ull,0x3639313a6469202full,
0x616475635f5f2030ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x202c356625092032ull,0x25202c3632326625ull,0x356625202c343366ull,0x6c090a202f2f093bull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c373232ull,0x323537322b363364ull,
0x6469202f2f093b5dull,0x5f5f20313639313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x32326625202c3566ull,0x2c35336625202c37ull,
0x2f2f093b35662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c38323266250920ull,
0x2b36336472255b20ull,0x2f093b5d38303033ull,0x3639313a6469202full,0x616475635f5f2032ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c356625092032ull,
0x25202c3832326625ull,0x356625202c363366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c393232ull,0x343632332b363364ull,0x6469202f2f093b5dull,
0x5f5f20333639313aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x32326625202c3566ull,0x2c37336625202c39ull,0x2f2f093b35662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c30333266250920ull,0x2b36336472255b20ull,
0x2f093b5d30323533ull,0x3639313a6469202full,0x616475635f5f2034ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c356625092032ull,0x25202c3033326625ull,
0x356625202c383366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c313332ull,0x363737332b363364ull,0x6469202f2f093b5dull,0x5f5f20353639313aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x33326625202c3566ull,0x2c39336625202c31ull,0x2f2f093b35662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c32333266250920ull,0x2b36336472255b20ull,0x2f093b5d32333034ull,
0x3639313a6469202full,0x616475635f5f2036ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c356625092032ull,0x25202c3233326625ull,0x356625202c303466ull,
0x2e090a202f2f093bull,0x3309353109636f6cull,0x6162090a30093632ull,0x0920636e79732e72ull,
0x2020202020203b30ull,0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093932330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c35326625ull,
0x3730332b33336472ull,0x69202f2f093b5d32ull,0x5f20373639313a64ull,0x5f415f616475635full,
0x3332356b636f6c62ull,0x6c090a3078302b36ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3632ull,0x5d363730332b3333ull,0x3a6469202f2f093bull,0x635f5f2038363931ull,
0x6c625f415f616475ull,0x2b363332356b636full,0x2e646c090a307830ull,0x662e646572616873ull,
0x3732662509203233ull,0x33336472255b202cull,0x093b5d303830332bull,0x39313a6469202f2full,
0x6475635f5f203936ull,0x636f6c625f415f61ull,0x78302b363332356bull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c383266250920ull,0x332b33336472255bull,0x2f2f093b5d343830ull,
0x303739313a646920ull,0x5f616475635f5f20ull,0x356b636f6c625f41ull,0x0a3078302b363332ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c39326625ull,0x3830332b33336472ull,
0x69202f2f093b5d38ull,0x5f20313739313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,
0x6c090a3078302b36ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3033ull,
0x5d323930332b3333ull,0x3a6469202f2f093bull,0x635f5f2032373931ull,0x6c625f415f616475ull,
0x2b363332356b636full,0x2e646c090a307830ull,0x662e646572616873ull,0x3133662509203233ull,
0x33336472255b202cull,0x093b5d363930332bull,0x39313a6469202f2full,0x6475635f5f203337ull,
0x636f6c625f415f61ull,0x78302b363332356bull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c323366250920ull,0x332b33336472255bull,0x2f2f093b5d303031ull,0x343739313a646920ull,
0x5f616475635f5f20ull,0x356b636f6c625f41ull,0x0a3078302b363332ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c33336625ull,0x3031332b33336472ull,0x69202f2f093b5d34ull,
0x5f20353739313a64ull,0x5f415f616475635full,0x3332356b636f6c62ull,0x6c090a3078302b36ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3433ull,0x5d383031332b3333ull,
0x3a6469202f2f093bull,0x635f5f2036373931ull,0x6c625f415f616475ull,0x2b363332356b636full,
0x2e646c090a307830ull,0x662e646572616873ull,0x3533662509203233ull,0x33336472255b202cull,
0x093b5d323131332bull,0x39313a6469202f2full,0x6475635f5f203737ull,0x636f6c625f415f61ull,
0x78302b363332356bull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c363366250920ull,
0x332b33336472255bull,0x2f2f093b5d363131ull,0x383739313a646920ull,0x5f616475635f5f20ull,
0x356b636f6c625f41ull,0x0a3078302b363332ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c37336625ull,0x3231332b33336472ull,0x69202f2f093b5d30ull,0x5f20393739313a64ull,
0x5f415f616475635full,0x3332356b636f6c62ull,0x6c090a3078302b36ull,0x6465726168732e64ull,
0x662509203233662eull,0x6472255b202c3833ull,0x5d343231332b3333ull,0x3a6469202f2f093bull,
0x635f5f2030383931ull,0x6c625f415f616475ull,0x2b363332356b636full,0x2e646c090a307830ull,
0x662e646572616873ull,0x3933662509203233ull,0x33336472255b202cull,0x093b5d383231332bull,
0x39313a6469202f2full,0x6475635f5f203138ull,0x636f6c625f415f61ull,0x78302b363332356bull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c303466250920ull,0x332b33336472255bull,
0x2f2f093b5d323331ull,0x323839313a646920ull,0x5f616475635f5f20ull,0x356b636f6c625f41ull,
0x0a3078302b363332ull,0x353109636f6c2e09ull,0x090a300932333309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c33333266ull,0x3b5d302b36336472ull,0x313a6469202f2f09ull,
0x75635f5f20333839ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3466250920323366ull,0x2c3333326625202cull,0x25202c3532662520ull,0x0a202f2f093b3466ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3433326625ull,0x35322b3633647225ull,
0x69202f2f093b5d36ull,0x5f20343839313a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c346625ull,0x36326625202c3433ull,
0x2f093b346625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3533326625092032ull,
0x36336472255b202cull,0x2f093b5d3231352bull,0x3839313a6469202full,0x616475635f5f2035ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c346625092032ull,
0x25202c3533326625ull,0x346625202c373266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c363332ull,0x5d3836372b363364ull,0x3a6469202f2f093bull,
0x635f5f2036383931ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x3633326625202c34ull,0x202c38326625202cull,0x202f2f093b346625ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c373332662509ull,0x312b36336472255bull,
0x2f2f093b5d343230ull,0x373839313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3466250920ull,0x6625202c37333266ull,
0x3b346625202c3932ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,
0x6472255b202c3833ull,0x5d303832312b3633ull,0x3a6469202f2f093bull,0x635f5f2038383931ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x3833326625202c34ull,0x202c30336625202cull,0x202f2f093b346625ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c393332662509ull,0x312b36336472255bull,0x2f2f093b5d363335ull,
0x393839313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x25202c3466250920ull,0x6625202c39333266ull,0x3b346625202c3133ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3034ull,
0x5d323937312b3633ull,0x3a6469202f2f093bull,0x635f5f2030393931ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x3034326625202c34ull,
0x202c32336625202cull,0x202f2f093b346625ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c313432662509ull,0x322b36336472255bull,0x2f2f093b5d383430ull,0x313939313a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x25202c3466250920ull,0x6625202c31343266ull,0x3b346625202c3333ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3234ull,0x5d343033322b3633ull,
0x3a6469202f2f093bull,0x635f5f2032393931ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x3234326625202c34ull,0x202c34336625202cull,
0x202f2f093b346625ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c333432662509ull,
0x322b36336472255bull,0x2f2f093b5d303635ull,0x333939313a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3466250920ull,
0x6625202c33343266ull,0x3b346625202c3533ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3434ull,0x5d363138322b3633ull,0x3a6469202f2f093bull,
0x635f5f2034393931ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x3434326625202c34ull,0x202c36336625202cull,0x202f2f093b346625ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c353432662509ull,0x332b36336472255bull,
0x2f2f093b5d323730ull,0x353939313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3466250920ull,0x6625202c35343266ull,
0x3b346625202c3733ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,
0x6472255b202c3634ull,0x5d383233332b3633ull,0x3a6469202f2f093bull,0x635f5f2036393931ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x3634326625202c34ull,0x202c38336625202cull,0x202f2f093b346625ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c373432662509ull,0x332b36336472255bull,0x2f2f093b5d343835ull,
0x373939313a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x25202c3466250920ull,0x6625202c37343266ull,0x3b346625202c3933ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3834ull,
0x5d303438332b3633ull,0x3a6469202f2f093bull,0x635f5f2038393931ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x3834326625202c34ull,
0x202c30346625202cull,0x202f2f093b346625ull,0x3109636f6c2e090aull,0x0a30093533330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3934326625ull,0x34362b3633647225ull,
0x6469202f2f093b5dull,0x5f5f20393939313aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x34326625202c3366ull,0x2c35326625202c39ull,
0x2f2f093b33662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c30353266250920ull,
0x2b36336472255b20ull,0x2f2f093b5d303233ull,0x303030323a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3366250920ull,
0x6625202c30353266ull,0x3b336625202c3632ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3135ull,0x3b5d3637352b3633ull,0x323a6469202f2f09ull,
0x75635f5f20313030ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3366250920323366ull,0x2c3135326625202cull,0x25202c3732662520ull,0x0a202f2f093b3366ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3235326625ull,0x33382b3633647225ull,
0x69202f2f093b5d32ull,0x5f20323030323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c336625ull,0x38326625202c3235ull,
0x2f093b336625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3335326625092032ull,
0x36336472255b202cull,0x093b5d383830312bull,0x30323a6469202f2full,0x6475635f5f203330ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c33662509203233ull,
0x202c333532662520ull,0x6625202c39326625ull,0x090a202f2f093b33ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c34353266ull,0x3433312b36336472ull,0x69202f2f093b5d34ull,
0x5f20343030323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x326625202c336625ull,0x30336625202c3435ull,0x2f093b336625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3535326625092032ull,0x36336472255b202cull,
0x093b5d303036312bull,0x30323a6469202f2full,0x6475635f5f203530ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c33662509203233ull,0x202c353532662520ull,
0x6625202c31336625ull,0x090a202f2f093b33ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c36353266ull,0x3538312b36336472ull,0x69202f2f093b5d36ull,0x5f20363030323a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x326625202c336625ull,0x32336625202c3635ull,0x2f093b336625202cull,0x732e646c090a202full,
0x33662e6465726168ull,0x3735326625092032ull,0x36336472255b202cull,0x093b5d323131322bull,
0x30323a6469202f2full,0x6475635f5f203730ull,0x636f6c625f425f61ull,0x78302b323333396bull,
0x662e64616d090a30ull,0x2c33662509203233ull,0x202c373532662520ull,0x6625202c33336625ull,
0x090a202f2f093b33ull,0x65726168732e646cull,0x2509203233662e64ull,0x255b202c38353266ull,
0x3633322b36336472ull,0x69202f2f093b5d38ull,0x5f20383030323a64ull,0x5f425f616475635full,
0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c336625ull,
0x34336625202c3835ull,0x2f093b336625202cull,0x732e646c090a202full,0x33662e6465726168ull,
0x3935326625092032ull,0x36336472255b202cull,0x093b5d343236322bull,0x30323a6469202f2full,
0x6475635f5f203930ull,0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,
0x2c33662509203233ull,0x202c393532662520ull,0x6625202c35336625ull,0x090a202f2f093b33ull,
0x65726168732e646cull,0x2509203233662e64ull,0x255b202c30363266ull,0x3838322b36336472ull,
0x69202f2f093b5d30ull,0x5f20303130323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c336625ull,0x36336625202c3036ull,
0x2f093b336625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3136326625092032ull,
0x36336472255b202cull,0x093b5d363331332bull,0x30323a6469202f2full,0x6475635f5f203131ull,
0x636f6c625f425f61ull,0x78302b323333396bull,0x662e64616d090a30ull,0x2c33662509203233ull,
0x202c313632662520ull,0x6625202c37336625ull,0x090a202f2f093b33ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c32363266ull,0x3933332b36336472ull,0x69202f2f093b5d32ull,
0x5f20323130323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,
0x09203233662e6461ull,0x326625202c336625ull,0x38336625202c3236ull,0x2f093b336625202cull,
0x732e646c090a202full,0x33662e6465726168ull,0x3336326625092032ull,0x36336472255b202cull,
0x093b5d383436332bull,0x30323a6469202f2full,0x6475635f5f203331ull,0x636f6c625f425f61ull,
0x78302b323333396bull,0x662e64616d090a30ull,0x2c33662509203233ull,0x202c333632662520ull,
0x6625202c39336625ull,0x090a202f2f093b33ull,0x65726168732e646cull,0x2509203233662e64ull,
0x255b202c34363266ull,0x3039332b36336472ull,0x69202f2f093b5d34ull,0x5f20343130323a64ull,
0x5f425f616475635full,0x3333396b636f6c62ull,0x6d090a3078302b32ull,0x09203233662e6461ull,
0x326625202c336625ull,0x30346625202c3436ull,0x2f093b336625202cull,0x636f6c2e090a202full,
0x0938333309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c35363266250920ull,
0x2b36336472255b20ull,0x2f2f093b5d383231ull,0x353130323a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3266250920ull,
0x6625202c35363266ull,0x3b326625202c3532ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3636ull,0x3b5d3438332b3633ull,0x323a6469202f2f09ull,
0x75635f5f20363130ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3266250920323366ull,0x2c3636326625202cull,0x25202c3632662520ull,0x0a202f2f093b3266ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3736326625ull,0x34362b3633647225ull,
0x69202f2f093b5d30ull,0x5f20373130323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c326625ull,0x37326625202c3736ull,
0x2f093b326625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3836326625092032ull,
0x36336472255b202cull,0x2f093b5d3639382bull,0x3130323a6469202full,0x616475635f5f2038ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c326625092032ull,
0x25202c3836326625ull,0x326625202c383266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c393632ull,0x323531312b363364ull,0x6469202f2f093b5dull,
0x5f5f20393130323aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x36326625202c3266ull,0x2c39326625202c39ull,0x2f2f093b32662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c30373266250920ull,0x2b36336472255b20ull,
0x2f093b5d38303431ull,0x3230323a6469202full,0x616475635f5f2030ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c326625092032ull,0x25202c3037326625ull,
0x326625202c303366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c313732ull,0x343636312b363364ull,0x6469202f2f093b5dull,0x5f5f20313230323aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x37326625202c3266ull,0x2c31336625202c31ull,0x2f2f093b32662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c32373266250920ull,0x2b36336472255b20ull,0x2f093b5d30323931ull,
0x3230323a6469202full,0x616475635f5f2032ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c326625092032ull,0x25202c3237326625ull,0x326625202c323366ull,
0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,0x72255b202c333732ull,
0x363731322b363364ull,0x6469202f2f093b5dull,0x5f5f20333230323aull,0x625f425f61647563ull,
0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,0x37326625202c3266ull,
0x2c33336625202c33ull,0x2f2f093b32662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x2c34373266250920ull,0x2b36336472255b20ull,0x2f093b5d32333432ull,0x3230323a6469202full,
0x616475635f5f2034ull,0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,
0x202c326625092032ull,0x25202c3437326625ull,0x326625202c343366ull,0x6c090a202f2f093bull,
0x6465726168732e64ull,0x662509203233662eull,0x72255b202c353732ull,0x383836322b363364ull,
0x6469202f2f093b5dull,0x5f5f20353230323aull,0x625f425f61647563ull,0x323333396b636f6cull,
0x616d090a3078302bull,0x2509203233662e64ull,0x37326625202c3266ull,0x2c35336625202c35ull,
0x2f2f093b32662520ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x2c36373266250920ull,
0x2b36336472255b20ull,0x2f093b5d34343932ull,0x3230323a6469202full,0x616475635f5f2036ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c326625092032ull,
0x25202c3637326625ull,0x326625202c363366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c373732ull,0x303032332b363364ull,0x6469202f2f093b5dull,
0x5f5f20373230323aull,0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,
0x2509203233662e64ull,0x37326625202c3266ull,0x2c37336625202c37ull,0x2f2f093b32662520ull,
0x68732e646c090a20ull,0x3233662e64657261ull,0x2c38373266250920ull,0x2b36336472255b20ull,
0x2f093b5d36353433ull,0x3230323a6469202full,0x616475635f5f2038ull,0x6b636f6c625f425full,
0x3078302b32333339ull,0x33662e64616d090aull,0x202c326625092032ull,0x25202c3837326625ull,
0x326625202c383366ull,0x6c090a202f2f093bull,0x6465726168732e64ull,0x662509203233662eull,
0x72255b202c393732ull,0x323137332b363364ull,0x6469202f2f093b5dull,0x5f5f20393230323aull,
0x625f425f61647563ull,0x323333396b636f6cull,0x616d090a3078302bull,0x2509203233662e64ull,
0x37326625202c3266ull,0x2c39336625202c39ull,0x2f2f093b32662520ull,0x68732e646c090a20ull,
0x3233662e64657261ull,0x2c30383266250920ull,0x2b36336472255b20ull,0x2f093b5d38363933ull,
0x3330323a6469202full,0x616475635f5f2030ull,0x6b636f6c625f425full,0x3078302b32333339ull,
0x33662e64616d090aull,0x202c326625092032ull,0x25202c3038326625ull,0x326625202c303466ull,
0x2e090a202f2f093bull,0x3309353109636f6cull,0x646c090a30093134ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3138ull,0x3b5d3239312b3633ull,0x323a6469202f2f09ull,
0x75635f5f20313330ull,0x6f6c625f425f6164ull,0x302b323333396b63ull,0x2e64616d090a3078ull,
0x3166250920323366ull,0x2c3138326625202cull,0x25202c3532662520ull,0x0a202f2f093b3166ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3238326625ull,0x34342b3633647225ull,
0x69202f2f093b5d38ull,0x5f20323330323a64ull,0x5f425f616475635full,0x3333396b636f6c62ull,
0x6d090a3078302b32ull,0x09203233662e6461ull,0x326625202c316625ull,0x36326625202c3238ull,
0x2f093b316625202cull,0x732e646c090a202full,0x33662e6465726168ull,0x3338326625092032ull,
0x36336472255b202cull,0x2f093b5d3430372bull,0x3330323a6469202full,0x616475635f5f2033ull,
0x6b636f6c625f425full,0x3078302b32333339ull,0x33662e64616d090aull,0x202c316625092032ull,
0x25202c3338326625ull,0x316625202c373266ull,0x6c090a202f2f093bull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c343832ull,0x5d3036392b363364ull,0x3a6469202f2f093bull,
0x635f5f2034333032ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x3438326625202c31ull,0x202c38326625202cull,0x202f2f093b316625ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c353832662509ull,0x312b36336472255bull,
0x2f2f093b5d363132ull,0x353330323a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3166250920ull,0x6625202c35383266ull,
0x3b316625202c3932ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,
0x6472255b202c3638ull,0x5d323734312b3633ull,0x3a6469202f2f093bull,0x635f5f2036333032ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x3638326625202c31ull,0x202c30336625202cull,0x202f2f093b316625ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c373832662509ull,0x312b36336472255bull,0x2f2f093b5d383237ull,
0x373330323a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x25202c3166250920ull,0x6625202c37383266ull,0x3b316625202c3133ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3838ull,
0x5d343839312b3633ull,0x3a6469202f2f093bull,0x635f5f2038333032ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x3838326625202c31ull,
0x202c32336625202cull,0x202f2f093b316625ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c393832662509ull,0x322b36336472255bull,0x2f2f093b5d303432ull,0x393330323a646920ull,
0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,
0x25202c3166250920ull,0x6625202c39383266ull,0x3b316625202c3333ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3039ull,0x5d363934322b3633ull,
0x3a6469202f2f093bull,0x635f5f2030343032ull,0x6c625f425f616475ull,0x2b323333396b636full,
0x64616d090a307830ull,0x662509203233662eull,0x3039326625202c31ull,0x202c34336625202cull,
0x202f2f093b316625ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c313932662509ull,
0x322b36336472255bull,0x2f2f093b5d323537ull,0x313430323a646920ull,0x5f616475635f5f20ull,
0x396b636f6c625f42ull,0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3166250920ull,
0x6625202c31393266ull,0x3b316625202c3533ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3266250920323366ull,0x6472255b202c3239ull,0x5d383030332b3633ull,0x3a6469202f2f093bull,
0x635f5f2032343032ull,0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,
0x662509203233662eull,0x3239326625202c31ull,0x202c36336625202cull,0x202f2f093b316625ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c333932662509ull,0x332b36336472255bull,
0x2f2f093b5d343632ull,0x333430323a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,
0x0a3078302b323333ull,0x3233662e64616d09ull,0x25202c3166250920ull,0x6625202c33393266ull,
0x3b316625202c3733ull,0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,
0x6472255b202c3439ull,0x5d303235332b3633ull,0x3a6469202f2f093bull,0x635f5f2034343032ull,
0x6c625f425f616475ull,0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,
0x3439326625202c31ull,0x202c38336625202cull,0x202f2f093b316625ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c353932662509ull,0x332b36336472255bull,0x2f2f093b5d363737ull,
0x353430323a646920ull,0x5f616475635f5f20ull,0x396b636f6c625f42ull,0x0a3078302b323333ull,
0x3233662e64616d09ull,0x25202c3166250920ull,0x6625202c35393266ull,0x3b316625202c3933ull,
0x646c090a202f2f09ull,0x2e6465726168732eull,0x3266250920323366ull,0x6472255b202c3639ull,
0x5d323330342b3633ull,0x3a6469202f2f093bull,0x635f5f2036343032ull,0x6c625f425f616475ull,
0x2b323333396b636full,0x64616d090a307830ull,0x662509203233662eull,0x3639326625202c31ull,
0x202c30346625202cull,0x202f2f093b316625ull,0x3109636f6c2e090aull,0x0a30093334330935ull,
0x3436752e64646109ull,0x202c366472250920ull,0x3436202c36647225ull,0x092020202020203bull,
0x6f6c2e090a202f2full,0x3434330935310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x32647225202c3231ull,0x3231647225202c34ull,0x090a202f2f09203bull,0x203233732e646461ull,
0x25202c3133722509ull,0x3b3631202c313372ull,0x2f09202020202020ull,0x70746573090a202full,
0x203233732e746c2eull,0x7225202c32702509ull,0x3b367225202c3133ull,0x090a202f2f092020ull,
0x6172622032702540ull,0x5f325f744c240920ull,0x2020202020203b37ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x2020203b355f325full,0x2020202020202020ull,
0x240a202f2f092020ull,0x0a3a395f325f744cull,0x3436752e74766309ull,0x722509203233752eull,
0x387225202c323664ull,0x092020202020203bull,0x6c756d090a202f2full,0x33752e6f6c2e3432ull,
0x2c33337225092032ull,0x3b32202c38722520ull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233752e6full,0x387225202c343372ull,0x092020203b33202cull,0x6c756d090a202f2full,
0x203233732e6f6c2eull,0x25202c3533722509ull,0x3b3631202c333172ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x36647225202c3731ull,0x0920203b34202c32ull,
0x747663090a202f2full,0x3233752e3436752eull,0x2c33366472250920ull,0x20203b3333722520ull,
0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233752eull,0x337225202c343664ull,
0x0920202020203b34ull,0x747663090a202f2full,0x3233732e3436732eull,0x2c35366472250920ull,
0x20203b3533722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x36647225202c3232ull,0x0920203b34202c33ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c333264722509ull,0x34202c3436647225ull,0x0a202f2f0920203bull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x36647225202c3432ull,0x0920203b34202c35ull,0x5f744c240a202f2full,
0x6c2e090a3a355f32ull,0x343309353109636full,0x2e646c090a300937ull,0x36752e6d61726170ull,
0x3636647225092034ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4d74616d5f6b3731ull,
0x6f726e755f746c75ull,0x535f536650326c6cull,0x765f5f5f6969695full,0x6d617261705f6c61ull,
0x69202f2f093b5d43ull,0x5f20373430323a64ull,0x726170616475635full,0x5f6b37315a5f5f6dull,
0x5f746c754d74616dull,0x50326c6c6f726e75ull,0x6969695f535f5366ull,0x705f6c61765f5f5full,
0x78302b436d617261ull,0x6c2e6c756d090a30ull,0x2509203233732e6full,0x317225202c363372ull,
0x203b357225202c33ull,0x61090a202f2f0920ull,0x09203233732e6464ull,0x7225202c37337225ull,
0x36337225202c3231ull,0x2f2f09202020203bull,0x732e747663090a20ull,0x09203233732e3436ull,
0x25202c3736647225ull,0x202020203b373372ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x3836647225092034ull,0x2c3736647225202cull,0x2f2f0920203b3420ull,0x752e646461090a20ull,
0x3664722509203436ull,0x3636647225202c39ull,0x3b3836647225202cull,0x73090a202f2f0920ull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b39366472ull,0x2f093b3631662520ull,
0x3430323a6469202full,0x09636f6c2e090a38ull,0x3009383433093531ull,0x36752e646461090aull,
0x3037647225092034ull,0x2c3936647225202cull,0x203b373164722520ull,0x7473090a202f2f09ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b303764ull,0x2f2f093b35316625ull,
0x393430323a646920ull,0x3109636f6c2e090aull,0x0a30093934330935ull,0x3436752e64646109ull,
0x2c31376472250920ull,0x202c393664722520ull,0x09203b3232647225ull,0x2e7473090a202f2full,
0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3137ull,0x202f2f093b343166ull,
0x0a303530323a6469ull,0x353109636f6c2e09ull,0x090a300930353309ull,0x203436752e646461ull,
0x202c323764722509ull,0x25202c3936647225ull,0x2f09203b33326472ull,0x672e7473090a202full,
0x33662e6c61626f6cull,0x376472255b092032ull,0x6625202c5d302b32ull,0x69202f2f093b3331ull,
0x090a313530323a64ull,0x09353109636f6c2eull,0x61090a3009333533ull,0x09203436752e6464ull,
0x25202c3337647225ull,0x7225202c39366472ull,0x2f2f09203b343264ull,0x6c672e7473090a20ull,
0x3233662e6c61626full,0x33376472255b0920ull,0x316625202c5d302bull,0x6469202f2f093b32ull,
0x2e090a323530323aull,0x3309353109636f6cull,0x6461090a30093435ull,0x2509203436752e64ull,
0x7225202c34376472ull,0x647225202c333764ull,0x202f2f09203b3731ull,0x6f6c672e7473090aull,
0x203233662e6c6162ull,0x2b34376472255b09ull,0x31316625202c5d30ull,0x3a6469202f2f093bull,
0x6c2e090a33353032ull,0x353309353109636full,0x646461090a300935ull,0x722509203436752eull,
0x647225202c353764ull,0x32647225202c3337ull,0x0a202f2f09203b32ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x302b35376472255bull,0x3b30316625202c5dull,0x323a6469202f2f09ull,
0x6f6c2e090a343530ull,0x3635330935310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x37647225202c3637ull,0x3332647225202c33ull,0x090a202f2f09203bull,0x61626f6c672e7473ull,
0x5b09203233662e6cull,0x5d302b3637647225ull,0x2f093b396625202cull,0x3530323a6469202full,
0x09636f6c2e090a35ull,0x3009393533093531ull,0x36752e646461090aull,0x3737647225092034ull,
0x2c3337647225202cull,0x203b343264722520ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,
0x72255b0920323366ull,0x202c5d302b373764ull,0x202f2f093b386625ull,0x0a363530323a6469ull,
0x353109636f6c2e09ull,0x090a300930363309ull,0x203436752e646461ull,0x202c383764722509ull,
0x25202c3737647225ull,0x2f09203b37316472ull,0x672e7473090a202full,0x33662e6c61626f6cull,
0x376472255b092032ull,0x6625202c5d302b38ull,0x6469202f2f093b37ull,0x2e090a373530323aull,
0x3309353109636f6cull,0x6461090a30093136ull,0x2509203436752e64ull,0x7225202c39376472ull,
0x647225202c373764ull,0x202f2f09203b3232ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,
0x2b39376472255b09ull,0x3b366625202c5d30ull,0x323a6469202f2f09ull,0x6f6c2e090a383530ull,
0x3236330935310963ull,0x2e646461090a3009ull,0x6472250920343675ull,0x37647225202c3038ull,
0x3332647225202c37ull,0x090a202f2f09203bull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x5d302b3038647225ull,0x2f093b356625202cull,0x3530323a6469202full,0x09636f6c2e090a39ull,
0x3009353633093531ull,0x36752e646461090aull,0x3138647225092034ull,0x2c3737647225202cull,
0x203b343264722520ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x202c5d302b313864ull,0x202f2f093b346625ull,0x0a303630323a6469ull,0x353109636f6c2e09ull,
0x090a300936363309ull,0x203436752e646461ull,0x202c323864722509ull,0x25202c3138647225ull,
0x2f09203b37316472ull,0x672e7473090a202full,0x33662e6c61626f6cull,0x386472255b092032ull,
0x6625202c5d302b32ull,0x6469202f2f093b33ull,0x2e090a313630323aull,0x3309353109636f6cull,
0x6461090a30093736ull,0x2509203436752e64ull,0x7225202c33386472ull,0x647225202c313864ull,
0x202f2f09203b3232ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b33386472255b09ull,
0x3b326625202c5d30ull,0x323a6469202f2f09ull,0x6f6c2e090a323630ull,0x3836330935310963ull,
0x2e646461090a3009ull,0x6472250920343675ull,0x38647225202c3438ull,0x3332647225202c31ull,
0x090a202f2f09203bull,0x61626f6c672e7473ull,0x5b09203233662e6cull,0x5d302b3438647225ull,
0x2f093b316625202cull,0x3630323a6469202full,0x09636f6c2e090a33ull,0x3009393633093531ull,
0x203b74697865090aull,0x2020202020202020ull,0x2020202020202020ull,0x2020202020202020ull,
0x444c240a202f2f09ull,0x315a5f5f646e6557ull,0x754d74616d5f6b37ull,0x6c6f726e755f746cull,
0x5f535f536650326cull,0x207d090a3a696969ull,0x6b37315a5f202f2full,0x746c754d74616d5full,
0x326c6c6f726e755full,0x69695f535f536650ull,0x746e652e090a0a69ull,0x6773375a5f207972ull,
0x664b504e4e6d6d65ull,0x696650695f305369ull,0x090a7b090a666669ull,0x31752e206765722eull,
0x3e343c6872252036ull,0x206765722e090a3bull,0x3c7225203233752eull,0x722e090a3b3e3432ull,
0x203436752e206765ull,0x3b3e36363c647225ull,0x2e206765722e090aull,0x333c662520323366ull,
0x722e090a3b3e3834ull,0x646572702e206765ull,0x0a3b3e333c702520ull,0x206d617261702e09ull,
0x635f5f203436752eull,0x5f6d726170616475ull,0x6d6d656773375a5full,0x305369664b504e4eull,
0x666669696650695full,0x705f6c61765f5f5full,0x090a3b416d617261ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x4e6d6d656773375aull,0x5f305369664b504eull,
0x5f66666969665069ull,0x702e090a3b61646cull,0x36752e206d617261ull,0x616475635f5f2034ull,
0x375a5f5f6d726170ull,0x504e4e6d6d656773ull,0x50695f305369664bull,0x5f5f5f6666696966ull,
0x617261705f6c6176ull,0x61702e090a3b426dull,0x3233732e206d6172ull,0x70616475635f5f20ull,
0x73375a5f5f6d7261ull,0x4b504e4e6d6d6567ull,0x6650695f30536966ull,0x62646c5f66666969ull,
0x617261702e090a3bull,0x5f203436752e206dull,0x726170616475635full,0x656773375a5f5f6dull,
0x69664b504e4e6d6dull,0x69696650695f3053ull,0x6c61765f5f5f6666ull,0x3b436d617261705full,
0x6d617261702e090aull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x6d656773375a5f5full,
0x5369664b504e4e6dull,0x6669696650695f30ull,0x090a3b63646c5f66ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x4e6d6d656773375aull,0x5f305369664b504eull,
0x5f66666969665069ull,0x7261702e090a3b6bull,0x203233662e206d61ull,0x6170616475635f5full,
0x6773375a5f5f6d72ull,0x664b504e4e6d6d65ull,0x696650695f305369ull,0x68706c615f666669ull,
0x7261702e090a3b61ull,0x203233662e206d61ull,0x6170616475635f5full,0x6773375a5f5f6d72ull,
0x664b504e4e6d6d65ull,0x696650695f305369ull,0x617465625f666669ull,0x726168732e090a3bull,
0x67696c612e206465ull,0x2038622e2034206eull,0x625f616475635f5full,0x315b383834333173ull,
0x2f090a3b5d383830ull,0x3631203d2063202full,0x3109636f6c2e090aull,0x0a30093230340935ull,
0x5a5f5f3142424c24ull,0x4e4e6d6d65677337ull,0x695f305369664b50ull,0x0a3a666669696650ull,
0x353109636f6c2e09ull,0x090a300930313409ull,0x2e3233732e747663ull,0x3172250920363175ull,
0x792e64697425202cull,0x2f0920202020203bull,0x326c756d090a202full,0x3233732e6f6c2e34ull,
0x25202c3272250920ull,0x203b3631202c3172ull,0x090a202f2f092020ull,0x2e3233732e747663ull,
0x3372250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,0x2e646461090a202full,
0x3472250920323373ull,0x25202c327225202cull,0x20202020203b3372ull,0x090a202f2f092020ull,
0x203631752e766f6dull,0x25202c3168722509ull,0x3b782e6469617463ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x3631752e65646977ull,0x25202c3572250920ull,0x3b3436202c316872ull,
0x090a202f2f092020ull,0x203233732e646461ull,0x7225202c36722509ull,0x203b357225202c34ull,
0x2f09202020202020ull,0x702e646c090a202full,0x3436752e6d617261ull,0x202c316472250920ull,
0x70616475635f5f5bull,0x73375a5f5f6d7261ull,0x4b504e4e6d6d6567ull,0x6650695f30536966ull,
0x765f5f5f66666969ull,0x6d617261705f6c61ull,0x69202f2f093b5d41ull,0x5f20393432313a64ull,
0x726170616475635full,0x656773375a5f5f6dull,0x69664b504e4e6d6dull,0x69696650695f3053ull,
0x6c61765f5f5f6666ull,0x2b416d617261705full,0x747663090a307830ull,0x3233732e3436732eull,
0x202c326472250920ull,0x202020203b367225ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x2c32647225202c33ull,0x09202020203b3420ull,0x646461090a202f2full,
0x722509203436752eull,0x31647225202c3464ull,0x203b33647225202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300931313409ull,0x203631752e766f6dull,0x25202c3268722509ull,
0x3b792e6469617463ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x3631752e65646977ull,
0x25202c3772250920ull,0x3b3631202c326872ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x7225202c38722509ull,0x203b377225202c31ull,0x2f09202020202020ull,0x702e646c090a202full,
0x3233732e6d617261ull,0x5b202c3972250920ull,0x6170616475635f5full,0x6773375a5f5f6d72ull,
0x664b504e4e6d6d65ull,0x696650695f305369ull,0x5d62646c5f666669ull,0x3a6469202f2f093bull,
0x635f5f2035343231ull,0x5f6d726170616475ull,0x6d6d656773375a5full,0x305369664b504e4eull,
0x666669696650695full,0x3078302b62646c5full,0x2e34326c756d090aull,0x09203233732e6f6cull,
0x7225202c30317225ull,0x203b397225202c38ull,0x646c090a202f2f09ull,0x752e6d617261702eull,
0x3564722509203436ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4e4e6d6d65677337ull,
0x695f305369664b50ull,0x5f5f666669696650ull,0x7261705f6c61765full,0x2f2f093b5d426d61ull,
0x313532313a646920ull,0x70616475635f5f20ull,0x73375a5f5f6d7261ull,0x4b504e4e6d6d6567ull,
0x6650695f30536966ull,0x765f5f5f66666969ull,0x6d617261705f6c61ull,0x61090a3078302b42ull,
0x09203233732e6464ull,0x7225202c31317225ull,0x3b337225202c3031ull,0x2f2f092020202020ull,
0x732e747663090a20ull,0x09203233732e3436ull,0x7225202c36647225ull,0x20202020203b3131ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x2c37647225092034ull,0x34202c3664722520ull,
0x2f2f09202020203bull,0x752e646461090a20ull,0x3864722509203436ull,0x202c35647225202cull,
0x2020203b37647225ull,0x6d090a202f2f0920ull,0x09203436732e766full,0x7225202c39647225ull,
0x20202020203b3864ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009363134093531ull,
0x33662e766f6d090aull,0x202c316625092032ull,0x3030303030306630ull,0x20202020203b3030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x316625202c326625ull,0x202020202020203bull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x2c33662509203233ull,0x3030303030663020ull,
0x202020203b303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,0x6625202c34662509ull,
0x2020202020203b33ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3566250920323366ull,
0x303030306630202cull,0x2020203b30303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x25202c3666250920ull,0x20202020203b3566ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x662509203233662eull,0x3030306630202c37ull,0x20203b3030303030ull,0x30202f2f09202020ull,
0x33662e766f6d090aull,0x202c386625092032ull,0x202020203b376625ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x30306630202c3966ull,0x203b303030303030ull,
0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3031662509203233ull,0x20203b396625202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c31316625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3166250920323366ull,
0x3b31316625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x30202c3331662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x33316625202c3431ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c353166250920ull,0x3030303030306630ull,0x09202020203b3030ull,
0x6f6d090a30202f2full,0x2509203233662e76ull,0x316625202c363166ull,0x2020202020203b35ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c37316625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,0x6625202c38316625ull,
0x20202020203b3731ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3931662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x25202c3032662509ull,0x202020203b393166ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3266250920323366ull,0x3030306630202c31ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x3233662e766f6d09ull,0x202c323266250920ull,0x2020203b31326625ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x30306630202c3332ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c34326625092032ull,0x20203b3332662520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x306630202c353266ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3632662509203233ull,
0x203b35326625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c37326625ull,0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,
0x3266250920323366ull,0x3b37326625202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x30202c3932662509ull,0x3030303030303066ull,0x2f09202020203b30ull,
0x766f6d090a30202full,0x662509203233662eull,0x39326625202c3033ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c313366250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x336625202c323366ull,
0x2020202020203b31ull,0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5f5b202c32317225ull,0x726170616475635full,0x656773375a5f5f6dull,0x69664b504e4e6d6dull,
0x69696650695f3053ull,0x2f093b5d6b5f6666ull,0x3532313a6469202full,0x616475635f5f2032ull,
0x375a5f5f6d726170ull,0x504e4e6d6d656773ull,0x50695f305369664bull,0x2b6b5f6666696966ull,
0x747663090a307830ull,0x3233732e3436752eull,0x2c30316472250920ull,0x20203b3231722520ull,
0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3131ull,
0x0920203b34202c30ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c323164ull,
0x3131647225202c38ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c33316472250920ull,
0x202c313164722520ull,0x09202020203b3336ull,0x766964090a202f2full,0x722509203436732eull,
0x647225202c343164ull,0x203b3436202c3331ull,0x0a202f2f09202020ull,0x3436732e766f6d09ull,
0x2c35316472250920ull,0x20202020203b3120ull,0x0920202020202020ull,0x78616d090a202f2full,
0x722509203436732eull,0x647225202c363164ull,0x31647225202c3431ull,0x0a202f2f09203b35ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x5f5f5b202c333172ull,0x6d72617061647563ull,
0x6d656773375a5f5full,0x5369664b504e4e6dull,0x6669696650695f30ull,0x093b5d61646c5f66ull,
0x32313a6469202f2full,0x6475635f5f203832ull,0x5a5f5f6d72617061ull,0x4e4e6d6d65677337ull,
0x695f305369664b50ull,0x6c5f666669696650ull,0x090a3078302b6164ull,0x2e3436752e747663ull,
0x6472250920323373ull,0x33317225202c3731ull,0x2f0920202020203bull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x25202c3831647225ull,0x3b34202c37316472ull,0x090a202f2f092020ull,
0x732e6f6c2e6c756dull,0x3431722509203233ull,0x202c33317225202cull,0x2f09202020203b32ull,
0x2e747663090a202full,0x203233732e343673ull,0x202c393164722509ull,0x2020203b34317225ull,
0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,0x3931647225202c30ull,
0x2f0920203b34202cull,0x2e6c756d090a202full,0x09203233732e6f6cull,0x7225202c35317225ull,
0x20203b33202c3331ull,0x090a202f2f092020ull,0x2e3436732e747663ull,0x6472250920323373ull,
0x35317225202c3132ull,0x2f0920202020203bull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x25202c3232647225ull,0x3b34202c31326472ull,0x090a202f2f092020ull,0x732e6f6c2e6c756dull,
0x3631722509203233ull,0x34202c397225202cull,0x2f0920202020203bull,0x2e747663090a202full,
0x203233732e343673ull,0x202c333264722509ull,0x2020203b36317225ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3264722509203436ull,0x3332647225202c34ull,0x2f0920203b34202cull,
0x2e6c756d090a202full,0x09203233732e6f6cull,0x7225202c37317225ull,0x2020203b38202c39ull,
0x090a202f2f092020ull,0x2e3436732e747663ull,0x6472250920323373ull,0x37317225202c3532ull,
0x2f0920202020203bull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3632647225ull,
0x3b34202c35326472ull,0x090a202f2f092020ull,0x732e6f6c2e6c756dull,0x3831722509203233ull,
0x31202c397225202cull,0x2f09202020203b32ull,0x2e747663090a202full,0x203233732e343673ull,
0x202c373264722509ull,0x2020203b38317225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,
0x3264722509203436ull,0x3732647225202c38ull,0x2f0920203b34202cull,0x2e6c756d090a202full,
0x09203233732e6f6cull,0x7225202c39317225ull,0x20203b34202c3331ull,0x090a202f2f092020ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x39317225202c3932ull,0x2f0920202020203bull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3033647225ull,0x3b34202c39326472ull,
0x090a202f2f092020ull,0x203436752e766f6dull,0x202c313364722509ull,0x625f616475635f5full,
0x093b383834333173ull,0x747663090a202f2full,0x3233732e3436752eull,0x2c32336472250920ull,
0x2020203b31722520ull,0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233732eull,
0x337225202c333364ull,0x092020202020203bull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c343364722509ull,0x31202c3333647225ull,0x0a202f2f09203b37ull,0x3436752e64646109ull,
0x2c35336472250920ull,0x202c323364722520ull,0x09203b3433647225ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x202c363364722509ull,0x34202c3533647225ull,0x0a202f2f0920203bull,
0x3436752e64646109ull,0x2c37336472250920ull,0x202c313364722520ull,0x09203b3633647225ull,
0x766f6d090a202f2full,0x722509203436732eull,0x647225202c383364ull,0x20202020203b3631ull,
0x0a202f2f09202020ull,0x3a395f335f744c24ull,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x6e202c3631342065ull,0x6420676e69747365ull,0x2c31203a68747065ull,
0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,
0x09353109636f6c2eull,0x6c090a3009303234ull,0x6c61626f6c672e64ull,0x662509203233662eull,
0x6472255b202c3333ull,0x2f2f093b5d302b34ull,0x333532313a646920ull,0x36752e646461090aull,
0x3933647225092034ull,0x2c3831647225202cull,0x20203b3464722520ull,0x646c090a202f2f09ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x336472255b202c34ull,0x2f2f093b5d302b39ull,
0x343532313a646920ull,0x36752e646461090aull,0x3034647225092034ull,0x2c3032647225202cull,
0x20203b3464722520ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3366250920323366ull,
0x346472255b202c35ull,0x2f2f093b5d302b30ull,0x353532313a646920ull,0x36752e646461090aull,
0x3134647225092034ull,0x2c3232647225202cull,0x20203b3464722520ull,0x646c090a202f2f09ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x346472255b202c36ull,0x2f2f093b5d302b31ull,
0x363532313a646920ull,0x3109636f6c2e090aull,0x0a30093332340935ull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x255b202c37336625ull,0x093b5d302b396472ull,0x32313a6469202f2full,
0x732e7473090a3735ull,0x33662e6465726168ull,0x336472255b092032ull,0x6625202c5d302b37ull,
0x69202f2f093b3733ull,0x5f20383532313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x09636f6c2e090a30ull,0x3009343234093531ull,0x36752e646461090aull,0x3234647225092034ull,
0x2c3432647225202cull,0x20203b3964722520ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,
0x3366250920323366ull,0x346472255b202c38ull,0x2f2f093b5d302b32ull,0x393532313a646920ull,
0x6168732e7473090aull,0x203233662e646572ull,0x2b37336472255b09ull,0x336625202c5d3631ull,
0x6469202f2f093b38ull,0x5f5f20303632313aull,0x3173625f61647563ull,0x3078302b38383433ull,
0x3109636f6c2e090aull,0x0a30093532340935ull,0x3436752e64646109ull,0x2c33346472250920ull,
0x202c363264722520ull,0x0920203b39647225ull,0x2e646c090a202f2full,0x662e6c61626f6c67ull,
0x3933662509203233ull,0x33346472255b202cull,0x202f2f093b5d302bull,0x0a313632313a6469ull,
0x726168732e747309ull,0x09203233662e6465ull,0x332b37336472255bull,0x39336625202c5d32ull,
0x3a6469202f2f093bull,0x635f5f2032363231ull,0x333173625f616475ull,0x0a3078302b383834ull,
0x353109636f6c2e09ull,0x090a300936323409ull,0x203436752e646461ull,0x202c343464722509ull,
0x25202c3832647225ull,0x2f0920203b396472ull,0x672e646c090a202full,0x33662e6c61626f6cull,
0x2c30346625092032ull,0x2b34346472255b20ull,0x69202f2f093b5d30ull,0x090a333632313a64ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x38342b3733647225ull,0x3b30346625202c5dull,
0x313a6469202f2f09ull,0x75635f5f20343632ull,0x34333173625f6164ull,0x090a3078302b3838ull,
0x09353109636f6c2eull,0x62090a3009373234ull,0x20636e79732e7261ull,0x20202020203b3009ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009393234093531ull,
0x36752e646461090aull,0x2c34647225092034ull,0x202c303364722520ull,0x2020203b34647225ull,
0x6c2e090a202f2f09ull,0x383309353109636full,0x2e646c090a300934ull,0x662e646572616873ull,
0x3134662509203233ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x2f2f093b5d302b38ull,
0x353632313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,0x64616d090a307830ull,
0x662509203233662eull,0x2c33336625202c31ull,0x25202c3134662520ull,0x0a202f2f093b3166ull,
0x3233662e766f6d09ull,0x25202c3266250920ull,0x20202020203b3166ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3538330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x2c32346625092032ull,0x616475635f5f5b20ull,0x383834333173625full,0x202f2f093b5d342bull,
0x20363632313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x2e64616d090a3478ull,
0x3366250920323366ull,0x202c33336625202cull,0x6625202c32346625ull,0x090a202f2f093b33ull,
0x203233662e766f6dull,0x6625202c34662509ull,0x2020202020203b33ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0936383309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c333466250920ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x69202f2f093b5d38ull,
0x5f20373632313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x662e64616d090a38ull,
0x2c35662509203233ull,0x25202c3333662520ull,0x356625202c333466ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x356625202c366625ull,0x202020202020203bull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009373833093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3434662509ull,0x625f616475635f5full,0x312b383834333173ull,0x69202f2f093b5d32ull,
0x5f20383632313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x662e64616d090a63ull,
0x2c37662509203233ull,0x25202c3333662520ull,0x376625202c343466ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x376625202c386625ull,0x202020202020203bull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009383833093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3534662509ull,0x625f616475635f5full,0x312b383834333173ull,0x69202f2f093b5d36ull,
0x5f20393632313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x2e64616d090a3031ull,
0x3966250920323366ull,0x202c33336625202cull,0x6625202c35346625ull,0x090a202f2f093b39ull,
0x203233662e766f6dull,0x25202c3031662509ull,0x20202020203b3966ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0939383309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c363466250920ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x202f2f093b5d3032ull,
0x20303732313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x64616d090a343178ull,
0x662509203233662eull,0x33336625202c3131ull,0x202c36346625202cull,0x2f2f093b31316625ull,
0x662e766f6d090a20ull,0x3231662509203233ull,0x203b31316625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093039ull,0x2e6465726168732eull,
0x3466250920323366ull,0x75635f5f5b202c37ull,0x34333173625f6164ull,0x093b5d34322b3838ull,
0x32313a6469202f2full,0x6475635f5f203137ull,0x3834333173625f61ull,0x090a383178302b38ull,
0x203233662e64616dull,0x25202c3331662509ull,0x346625202c333366ull,0x3b33316625202c37ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c343166ull,0x2020202020203b33ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093139330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5f5b202c38346625ull,0x73625f616475635full,0x38322b3838343331ull,
0x6469202f2f093b5dull,0x5f5f20323732313aull,0x3173625f61647563ull,0x3178302b38383433ull,
0x662e64616d090a63ull,0x3531662509203233ull,0x202c33336625202cull,0x6625202c38346625ull,
0x0a202f2f093b3531ull,0x3233662e766f6d09ull,0x202c363166250920ull,0x2020203b35316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3239330935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c39346625092032ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f2f093b5d32332bull,0x333732313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x616d090a30327830ull,0x2509203233662e64ull,0x336625202c373166ull,0x2c39346625202c33ull,
0x2f093b3731662520ull,0x2e766f6d090a202full,0x3166250920323366ull,0x3b37316625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009333933ull,
0x6465726168732e64ull,0x662509203233662eull,0x635f5f5b202c3035ull,0x333173625f616475ull,
0x3b5d36332b383834ull,0x313a6469202f2f09ull,0x75635f5f20343732ull,0x34333173625f6164ull,
0x0a343278302b3838ull,0x3233662e64616d09ull,0x202c393166250920ull,0x6625202c33336625ull,
0x39316625202c3035ull,0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c30326625ull,
0x20202020203b3931ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009343933093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3135662509ull,0x625f616475635f5full,
0x342b383834333173ull,0x69202f2f093b5d30ull,0x5f20353732313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x2e64616d090a3832ull,0x3266250920323366ull,0x2c33336625202c31ull,
0x25202c3135662520ull,0x202f2f093b313266ull,0x33662e766f6d090aull,0x2c32326625092032ull,
0x20203b3132662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300935ull,0x662e646572616873ull,0x3235662509203233ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x2f093b5d34342b38ull,0x3732313a6469202full,0x616475635f5f2036ull,
0x383834333173625full,0x6d090a633278302bull,0x09203233662e6461ull,0x6625202c33326625ull,
0x32356625202c3333ull,0x093b33326625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x33326625202c3432ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300936393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5f5b202c333566ull,
0x3173625f61647563ull,0x5d38342b38383433ull,0x3a6469202f2f093bull,0x635f5f2037373231ull,
0x333173625f616475ull,0x303378302b383834ull,0x33662e64616d090aull,0x2c35326625092032ull,
0x25202c3333662520ull,0x326625202c333566ull,0x090a202f2f093b35ull,0x203233662e766f6dull,
0x25202c3632662509ull,0x202020203b353266ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0937393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c343566250920ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x202f2f093b5d3235ull,0x20383732313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x64616d090a343378ull,0x662509203233662eull,
0x33336625202c3732ull,0x202c34356625202cull,0x2f2f093b37326625ull,0x662e766f6d090a20ull,
0x3832662509203233ull,0x203b37326625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093839ull,0x2e6465726168732eull,0x3566250920323366ull,
0x75635f5f5b202c35ull,0x34333173625f6164ull,0x093b5d36352b3838ull,0x32313a6469202f2full,
0x6475635f5f203937ull,0x3834333173625f61ull,0x090a383378302b38ull,0x203233662e64616dull,
0x25202c3932662509ull,0x356625202c333366ull,0x3b39326625202c35ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x326625202c303366ull,0x2020202020203b39ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093939330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5f5b202c36356625ull,0x73625f616475635full,0x30362b3838343331ull,0x6469202f2f093b5dull,
0x5f5f20303832313aull,0x3173625f61647563ull,0x3378302b38383433ull,0x662e64616d090a63ull,
0x3133662509203233ull,0x202c33336625202cull,0x6625202c36356625ull,0x0a202f2f093b3133ull,
0x3233662e766f6d09ull,0x202c323366250920ull,0x2020203b31336625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3033340935310963ull,0x672e646c090a3009ull,0x33662e6c61626f6cull,
0x2c33336625092032ull,0x302b346472255b20ull,0x6469202f2f093b5dull,0x2e090a313832313aull,
0x3309353109636f6cull,0x646c090a30093438ull,0x2e6465726168732eull,0x3566250920323366ull,
0x75635f5f5b202c37ull,0x34333173625f6164ull,0x093b5d38362b3838ull,0x32313a6469202f2full,
0x6475635f5f203238ull,0x3834333173625f61ull,0x090a343478302b38ull,0x203233662e64616dull,
0x6625202c31662509ull,0x37356625202c3433ull,0x2f093b316625202cull,0x2e766f6d090a202full,
0x3266250920323366ull,0x20203b316625202cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009353833ull,0x6465726168732e64ull,0x662509203233662eull,
0x635f5f5b202c3835ull,0x333173625f616475ull,0x3b5d32372b383834ull,0x313a6469202f2f09ull,
0x75635f5f20333832ull,0x34333173625f6164ull,0x0a383478302b3838ull,0x3233662e64616d09ull,
0x25202c3366250920ull,0x356625202c343366ull,0x093b336625202c38ull,0x766f6d090a202f2full,
0x662509203233662eull,0x203b336625202c34ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300936383309ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5f5b202c393566ull,0x3173625f61647563ull,0x5d36372b38383433ull,0x3a6469202f2f093bull,
0x635f5f2034383231ull,0x333173625f616475ull,0x633478302b383834ull,0x33662e64616d090aull,
0x202c356625092032ull,0x6625202c34336625ull,0x3b356625202c3935ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x3b356625202c3666ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093738330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5f5b202c30366625ull,0x73625f616475635full,0x30382b3838343331ull,0x6469202f2f093b5dull,
0x5f5f20353832313aull,0x3173625f61647563ull,0x3578302b38383433ull,0x662e64616d090a30ull,
0x2c37662509203233ull,0x25202c3433662520ull,0x376625202c303666ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x376625202c386625ull,0x202020202020203bull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009383833093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3136662509ull,0x625f616475635f5full,0x382b383834333173ull,0x69202f2f093b5d34ull,
0x5f20363832313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x2e64616d090a3435ull,
0x3966250920323366ull,0x202c34336625202cull,0x6625202c31366625ull,0x090a202f2f093b39ull,
0x203233662e766f6dull,0x25202c3031662509ull,0x20202020203b3966ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0939383309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c323666250920ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x202f2f093b5d3838ull,
0x20373832313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x64616d090a383578ull,
0x662509203233662eull,0x34336625202c3131ull,0x202c32366625202cull,0x2f2f093b31316625ull,
0x662e766f6d090a20ull,0x3231662509203233ull,0x203b31316625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093039ull,0x2e6465726168732eull,
0x3666250920323366ull,0x75635f5f5b202c33ull,0x34333173625f6164ull,0x093b5d32392b3838ull,
0x32313a6469202f2full,0x6475635f5f203838ull,0x3834333173625f61ull,0x090a633578302b38ull,
0x203233662e64616dull,0x25202c3331662509ull,0x366625202c343366ull,0x3b33316625202c33ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c343166ull,0x2020202020203b33ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093139330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5f5b202c34366625ull,0x73625f616475635full,0x36392b3838343331ull,
0x6469202f2f093b5dull,0x5f5f20393832313aull,0x3173625f61647563ull,0x3678302b38383433ull,
0x662e64616d090a30ull,0x3531662509203233ull,0x202c34336625202cull,0x6625202c34366625ull,
0x0a202f2f093b3531ull,0x3233662e766f6d09ull,0x202c363166250920ull,0x2020203b35316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3239330935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x2c35366625092032ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3030312bull,0x3932313a6469202full,0x616475635f5f2030ull,0x383834333173625full,
0x6d090a343678302bull,0x09203233662e6461ull,0x6625202c37316625ull,0x35366625202c3433ull,
0x093b37316625202cull,0x766f6d090a202f2full,0x662509203233662eull,0x37316625202c3831ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300933393309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5f5b202c363666ull,0x3173625f61647563ull,
0x3430312b38383433ull,0x6469202f2f093b5dull,0x5f5f20313932313aull,0x3173625f61647563ull,
0x3678302b38383433ull,0x662e64616d090a38ull,0x3931662509203233ull,0x202c34336625202cull,
0x6625202c36366625ull,0x0a202f2f093b3931ull,0x3233662e766f6d09ull,0x202c303266250920ull,
0x2020203b39316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3439330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c37366625092032ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3830312bull,0x3932313a6469202full,0x616475635f5f2032ull,
0x383834333173625full,0x6d090a633678302bull,0x09203233662e6461ull,0x6625202c31326625ull,
0x37366625202c3433ull,0x093b31326625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x31326625202c3232ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300935393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5f5b202c383666ull,
0x3173625f61647563ull,0x3231312b38383433ull,0x6469202f2f093b5dull,0x5f5f20333932313aull,
0x3173625f61647563ull,0x3778302b38383433ull,0x662e64616d090a30ull,0x3332662509203233ull,
0x202c34336625202cull,0x6625202c38366625ull,0x0a202f2f093b3332ull,0x3233662e766f6d09ull,
0x202c343266250920ull,0x2020203b33326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3639330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x2c39366625092032ull,
0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3631312bull,0x3932313a6469202full,
0x616475635f5f2034ull,0x383834333173625full,0x6d090a343778302bull,0x09203233662e6461ull,
0x6625202c35326625ull,0x39366625202c3433ull,0x093b35326625202cull,0x766f6d090a202f2full,
0x662509203233662eull,0x35326625202c3632ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300937393309ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5f5b202c303766ull,0x3173625f61647563ull,0x3032312b38383433ull,0x6469202f2f093b5dull,
0x5f5f20353932313aull,0x3173625f61647563ull,0x3778302b38383433ull,0x662e64616d090a38ull,
0x3732662509203233ull,0x202c34336625202cull,0x6625202c30376625ull,0x0a202f2f093b3732ull,
0x3233662e766f6d09ull,0x202c383266250920ull,0x2020203b37326625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3839330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x2c31376625092032ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3432312bull,
0x3932313a6469202full,0x616475635f5f2036ull,0x383834333173625full,0x6d090a633778302bull,
0x09203233662e6461ull,0x6625202c39326625ull,0x31376625202c3433ull,0x093b39326625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x39326625202c3033ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5f5b202c323766ull,0x3173625f61647563ull,0x3832312b38383433ull,
0x6469202f2f093b5dull,0x5f5f20373932313aull,0x3173625f61647563ull,0x3878302b38383433ull,
0x662e64616d090a30ull,0x3133662509203233ull,0x202c34336625202cull,0x6625202c32376625ull,
0x0a202f2f093b3133ull,0x3233662e766f6d09ull,0x202c323366250920ull,0x2020203b31336625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3133340935310963ull,0x2e646461090a3009ull,
0x6472250920343675ull,0x31647225202c3534ull,0x3b34647225202c38ull,0x090a202f2f092020ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c343366ull,0x093b5d302b353464ull,
0x32313a6469202f2full,0x636f6c2e090a3839ull,0x0934383309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x202c333766250920ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d363331ull,0x393932313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x616d090a38387830ull,0x2509203233662e64ull,0x35336625202c3166ull,0x202c33376625202cull,
0x202f2f093b316625ull,0x33662e766f6d090aull,0x202c326625092032ull,0x202020203b316625ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,0x2e646c090a300935ull,
0x662e646572616873ull,0x3437662509203233ull,0x6475635f5f5b202cull,0x3834333173625f61ull,
0x093b5d3034312b38ull,0x33313a6469202f2full,0x6475635f5f203030ull,0x3834333173625f61ull,
0x090a633878302b38ull,0x203233662e64616dull,0x6625202c33662509ull,0x34376625202c3533ull,
0x2f093b336625202cull,0x2e766f6d090a202full,0x3466250920323366ull,0x20203b336625202cull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009363833ull,
0x6465726168732e64ull,0x662509203233662eull,0x635f5f5b202c3537ull,0x333173625f616475ull,
0x5d3434312b383834ull,0x3a6469202f2f093bull,0x635f5f2031303331ull,0x333173625f616475ull,
0x303978302b383834ull,0x33662e64616d090aull,0x202c356625092032ull,0x6625202c35336625ull,
0x3b356625202c3537ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b356625202c3666ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093738330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c36376625ull,0x73625f616475635full,
0x34312b3838343331ull,0x69202f2f093b5d38ull,0x5f20323033313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x2e64616d090a3439ull,0x3766250920323366ull,0x202c35336625202cull,
0x6625202c36376625ull,0x090a202f2f093b37ull,0x203233662e766f6dull,0x6625202c38662509ull,
0x2020202020203b37ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0938383309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c373766250920ull,0x5f616475635f5f5bull,
0x2b38383433317362ull,0x2f2f093b5d323531ull,0x333033313a646920ull,0x5f616475635f5f20ull,
0x2b38383433317362ull,0x616d090a38397830ull,0x2509203233662e64ull,0x35336625202c3966ull,
0x202c37376625202cull,0x202f2f093b396625ull,0x33662e766f6d090aull,0x2c30316625092032ull,
0x2020203b39662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,
0x2e646c090a300939ull,0x662e646572616873ull,0x3837662509203233ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3635312b38ull,0x33313a6469202f2full,0x6475635f5f203430ull,
0x3834333173625f61ull,0x090a633978302b38ull,0x203233662e64616dull,0x25202c3131662509ull,
0x376625202c353366ull,0x3b31316625202c38ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x316625202c323166ull,0x2020202020203b31ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093039330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c39376625ull,
0x73625f616475635full,0x36312b3838343331ull,0x69202f2f093b5d30ull,0x5f20353033313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x2e64616d090a3061ull,0x3166250920323366ull,
0x2c35336625202c33ull,0x25202c3937662520ull,0x202f2f093b333166ull,0x33662e766f6d090aull,
0x2c34316625092032ull,0x20203b3331662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300931ull,0x662e646572616873ull,0x3038662509203233ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3436312b38ull,0x33313a6469202f2full,
0x6475635f5f203630ull,0x3834333173625f61ull,0x090a346178302b38ull,0x203233662e64616dull,
0x25202c3531662509ull,0x386625202c353366ull,0x3b35316625202c30ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c363166ull,0x2020202020203b35ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093239330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5f5b202c31386625ull,0x73625f616475635full,0x36312b3838343331ull,0x69202f2f093b5d38ull,
0x5f20373033313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x2e64616d090a3861ull,
0x3166250920323366ull,0x2c35336625202c37ull,0x25202c3138662520ull,0x202f2f093b373166ull,
0x33662e766f6d090aull,0x2c38316625092032ull,0x20203b3731662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300933ull,0x662e646572616873ull,
0x3238662509203233ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3237312b38ull,
0x33313a6469202f2full,0x6475635f5f203830ull,0x3834333173625f61ull,0x090a636178302b38ull,
0x203233662e64616dull,0x25202c3931662509ull,0x386625202c353366ull,0x3b39316625202c32ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c303266ull,0x2020202020203b39ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093439330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5f5b202c33386625ull,0x73625f616475635full,0x37312b3838343331ull,
0x69202f2f093b5d36ull,0x5f20393033313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x2e64616d090a3062ull,0x3266250920323366ull,0x2c35336625202c31ull,0x25202c3338662520ull,
0x202f2f093b313266ull,0x33662e766f6d090aull,0x2c32326625092032ull,0x20203b3132662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300935ull,
0x662e646572616873ull,0x3438662509203233ull,0x6475635f5f5b202cull,0x3834333173625f61ull,
0x093b5d3038312b38ull,0x33313a6469202f2full,0x6475635f5f203031ull,0x3834333173625f61ull,
0x090a346278302b38ull,0x203233662e64616dull,0x25202c3332662509ull,0x386625202c353366ull,
0x3b33326625202c34ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x326625202c343266ull,
0x2020202020203b33ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093639330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c35386625ull,0x73625f616475635full,
0x38312b3838343331ull,0x69202f2f093b5d34ull,0x5f20313133313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x2e64616d090a3862ull,0x3266250920323366ull,0x2c35336625202c35ull,
0x25202c3538662520ull,0x202f2f093b353266ull,0x33662e766f6d090aull,0x2c36326625092032ull,
0x20203b3532662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300937ull,0x662e646572616873ull,0x3638662509203233ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3838312b38ull,0x33313a6469202f2full,0x6475635f5f203231ull,
0x3834333173625f61ull,0x090a636278302b38ull,0x203233662e64616dull,0x25202c3732662509ull,
0x386625202c353366ull,0x3b37326625202c36ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x326625202c383266ull,0x2020202020203b37ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093839330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c37386625ull,
0x73625f616475635full,0x39312b3838343331ull,0x69202f2f093b5d32ull,0x5f20333133313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x2e64616d090a3063ull,0x3266250920323366ull,
0x2c35336625202c39ull,0x25202c3738662520ull,0x202f2f093b393266ull,0x33662e766f6d090aull,
0x2c30336625092032ull,0x20203b3932662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300939ull,0x662e646572616873ull,0x3838662509203233ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3639312b38ull,0x33313a6469202f2full,
0x6475635f5f203431ull,0x3834333173625f61ull,0x090a346378302b38ull,0x203233662e64616dull,
0x25202c3133662509ull,0x386625202c353366ull,0x3b31336625202c38ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x336625202c323366ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093233340935ull,0x3436752e64646109ull,0x2c36346472250920ull,
0x202c303264722520ull,0x0920203b34647225ull,0x2e646c090a202f2full,0x662e6c61626f6c67ull,
0x3533662509203233ull,0x36346472255b202cull,0x202f2f093b5d302bull,0x0a353133313a6469ull,
0x353109636f6c2e09ull,0x090a300934383309ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5f5b202c393866ull,0x3173625f61647563ull,0x3430322b38383433ull,0x6469202f2f093b5dull,
0x5f5f20363133313aull,0x3173625f61647563ull,0x6378302b38383433ull,0x662e64616d090a63ull,
0x2c31662509203233ull,0x25202c3633662520ull,0x316625202c393866ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x316625202c326625ull,0x202020202020203bull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009353833093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3039662509ull,0x625f616475635f5full,0x322b383834333173ull,0x202f2f093b5d3830ull,
0x20373133313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x64616d090a306478ull,
0x662509203233662eull,0x2c36336625202c33ull,0x25202c3039662520ull,0x0a202f2f093b3366ull,
0x3233662e766f6d09ull,0x25202c3466250920ull,0x20202020203b3366ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3638330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x2c31396625092032ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3231322bull,
0x3133313a6469202full,0x616475635f5f2038ull,0x383834333173625full,0x6d090a346478302bull,
0x09203233662e6461ull,0x336625202c356625ull,0x2c31396625202c36ull,0x2f2f093b35662520ull,
0x662e766f6d090a20ull,0x2c36662509203233ull,0x2020203b35662520ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093738ull,0x2e6465726168732eull,
0x3966250920323366ull,0x75635f5f5b202c32ull,0x34333173625f6164ull,0x3b5d3631322b3838ull,
0x313a6469202f2f09ull,0x75635f5f20393133ull,0x34333173625f6164ull,0x0a386478302b3838ull,
0x3233662e64616d09ull,0x25202c3766250920ull,0x396625202c363366ull,0x093b376625202c32ull,
0x766f6d090a202f2full,0x662509203233662eull,0x203b376625202c38ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938383309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5f5b202c333966ull,0x3173625f61647563ull,0x3032322b38383433ull,
0x6469202f2f093b5dull,0x5f5f20303233313aull,0x3173625f61647563ull,0x6478302b38383433ull,
0x662e64616d090a63ull,0x2c39662509203233ull,0x25202c3633662520ull,0x396625202c333966ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c30316625ull,0x2020202020203b39ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009393833093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3439662509ull,0x625f616475635f5full,0x322b383834333173ull,
0x202f2f093b5d3432ull,0x20313233313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x64616d090a306578ull,0x662509203233662eull,0x36336625202c3131ull,0x202c34396625202cull,
0x2f2f093b31316625ull,0x662e766f6d090a20ull,0x3231662509203233ull,0x203b31316625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093039ull,
0x2e6465726168732eull,0x3966250920323366ull,0x75635f5f5b202c35ull,0x34333173625f6164ull,
0x3b5d3832322b3838ull,0x313a6469202f2f09ull,0x75635f5f20323233ull,0x34333173625f6164ull,
0x0a346578302b3838ull,0x3233662e64616d09ull,0x202c333166250920ull,0x6625202c36336625ull,
0x33316625202c3539ull,0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c34316625ull,
0x20202020203b3331ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009313933093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3639662509ull,0x625f616475635f5full,
0x322b383834333173ull,0x202f2f093b5d3233ull,0x20333233313a6469ull,0x625f616475635f5full,
0x302b383834333173ull,0x64616d090a386578ull,0x662509203233662eull,0x36336625202c3531ull,
0x202c36396625202cull,0x2f2f093b35316625ull,0x662e766f6d090a20ull,0x3631662509203233ull,
0x203b35316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x646c090a30093239ull,0x2e6465726168732eull,0x3966250920323366ull,0x75635f5f5b202c37ull,
0x34333173625f6164ull,0x3b5d3633322b3838ull,0x313a6469202f2f09ull,0x75635f5f20343233ull,
0x34333173625f6164ull,0x0a636578302b3838ull,0x3233662e64616d09ull,0x202c373166250920ull,
0x6625202c36336625ull,0x37316625202c3739ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c38316625ull,0x20202020203b3731ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009333933093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3839662509ull,
0x625f616475635f5full,0x322b383834333173ull,0x202f2f093b5d3034ull,0x20353233313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x64616d090a306678ull,0x662509203233662eull,
0x36336625202c3931ull,0x202c38396625202cull,0x2f2f093b39316625ull,0x662e766f6d090a20ull,
0x3032662509203233ull,0x203b39316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093439ull,0x2e6465726168732eull,0x3966250920323366ull,
0x75635f5f5b202c39ull,0x34333173625f6164ull,0x3b5d3434322b3838ull,0x313a6469202f2f09ull,
0x75635f5f20363233ull,0x34333173625f6164ull,0x0a346678302b3838ull,0x3233662e64616d09ull,
0x202c313266250920ull,0x6625202c36336625ull,0x31326625202c3939ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x6625202c32326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009353933093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c303031662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383432ull,
0x373233313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,0x616d090a38667830ull,
0x2509203233662e64ull,0x336625202c333266ull,0x3030316625202c36ull,0x093b33326625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x33326625202c3432ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300936393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c31303166ull,0x73625f616475635full,0x35322b3838343331ull,
0x69202f2f093b5d32ull,0x5f20383233313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x2e64616d090a6366ull,0x3266250920323366ull,0x2c36336625202c35ull,0x202c313031662520ull,
0x2f2f093b35326625ull,0x662e766f6d090a20ull,0x3632662509203233ull,0x203b35326625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093739ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3230ull,0x333173625f616475ull,
0x5d3635322b383834ull,0x3a6469202f2f093bull,0x635f5f2039323331ull,0x333173625f616475ull,
0x303178302b383834ull,0x662e64616d090a30ull,0x3732662509203233ull,0x202c36336625202cull,
0x25202c3230316625ull,0x202f2f093b373266ull,0x33662e766f6d090aull,0x2c38326625092032ull,
0x20203b3732662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300938ull,0x662e646572616873ull,0x3031662509203233ull,0x75635f5f5b202c33ull,
0x34333173625f6164ull,0x3b5d3036322b3838ull,0x313a6469202f2f09ull,0x75635f5f20303333ull,
0x34333173625f6164ull,0x34303178302b3838ull,0x33662e64616d090aull,0x2c39326625092032ull,
0x25202c3633662520ull,0x6625202c33303166ull,0x0a202f2f093b3932ull,0x3233662e766f6d09ull,
0x202c303366250920ull,0x2020203b39326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3939330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3430316625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3436322b38ull,0x33313a6469202f2full,
0x6475635f5f203133ull,0x3834333173625f61ull,0x0a38303178302b38ull,0x3233662e64616d09ull,
0x202c313366250920ull,0x6625202c36336625ull,0x336625202c343031ull,0x090a202f2f093b31ull,
0x203233662e766f6dull,0x25202c3233662509ull,0x202020203b313366ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0933333409353109ull,0x752e646461090a30ull,0x3464722509203436ull,
0x3232647225202c37ull,0x203b34647225202cull,0x6c090a202f2f0920ull,0x6c61626f6c672e64ull,
0x662509203233662eull,0x6472255b202c3633ull,0x2f093b5d302b3734ull,0x3333313a6469202full,
0x09636f6c2e090a32ull,0x3009353334093531ull,0x36752e646461090aull,0x2c34647225092034ull,
0x202c303364722520ull,0x2020203b34647225ull,0x6c2e090a202f2f09ull,0x383309353109636full,
0x2e646c090a300934ull,0x662e646572616873ull,0x3031662509203233ull,0x75635f5f5b202c35ull,
0x34333173625f6164ull,0x3b5d3237322b3838ull,0x313a6469202f2f09ull,0x75635f5f20333333ull,
0x34333173625f6164ull,0x30313178302b3838ull,0x33662e64616d090aull,0x202c316625092032ull,
0x6625202c33336625ull,0x316625202c353031ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x316625202c326625ull,0x202020202020203bull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009353833093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c363031662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d363732ull,0x343333313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3431317830ull,0x09203233662e6461ull,
0x336625202c336625ull,0x3630316625202c33ull,0x2f093b336625202cull,0x2e766f6d090a202full,
0x3466250920323366ull,0x20203b336625202cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009363833ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c373031ull,0x3173625f61647563ull,0x3038322b38383433ull,0x6469202f2f093b5dull,
0x5f5f20353333313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a3831ull,
0x3566250920323366ull,0x202c33336625202cull,0x25202c3730316625ull,0x0a202f2f093b3566ull,
0x3233662e766f6d09ull,0x25202c3666250920ull,0x20202020203b3566ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3738330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3830316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3438322b38ull,
0x33313a6469202f2full,0x6475635f5f203633ull,0x3834333173625f61ull,0x0a63313178302b38ull,
0x3233662e64616d09ull,0x25202c3766250920ull,0x316625202c333366ull,0x3b376625202c3830ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b376625202c3866ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093838330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3930316625ull,0x625f616475635f5full,0x322b383834333173ull,
0x202f2f093b5d3838ull,0x20373333313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a30323178ull,0x2509203233662e64ull,0x33336625202c3966ull,0x2c3930316625202cull,
0x2f2f093b39662520ull,0x662e766f6d090a20ull,0x3031662509203233ull,0x20203b396625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093938ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3031ull,0x333173625f616475ull,
0x5d3239322b383834ull,0x3a6469202f2f093bull,0x635f5f2038333331ull,0x333173625f616475ull,
0x323178302b383834ull,0x662e64616d090a34ull,0x3131662509203233ull,0x202c33336625202cull,
0x25202c3031316625ull,0x202f2f093b313166ull,0x33662e766f6d090aull,0x2c32316625092032ull,
0x20203b3131662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300930ull,0x662e646572616873ull,0x3131662509203233ull,0x75635f5f5b202c31ull,
0x34333173625f6164ull,0x3b5d3639322b3838ull,0x313a6469202f2f09ull,0x75635f5f20393333ull,
0x34333173625f6164ull,0x38323178302b3838ull,0x33662e64616d090aull,0x2c33316625092032ull,
0x25202c3333662520ull,0x6625202c31313166ull,0x0a202f2f093b3331ull,0x3233662e766f6d09ull,
0x202c343166250920ull,0x2020203b33316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3139330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3231316625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3030332b38ull,0x33313a6469202f2full,
0x6475635f5f203034ull,0x3834333173625f61ull,0x0a63323178302b38ull,0x3233662e64616d09ull,
0x202c353166250920ull,0x6625202c33336625ull,0x316625202c323131ull,0x090a202f2f093b35ull,
0x203233662e766f6dull,0x25202c3631662509ull,0x202020203b353166ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0932393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x2c33313166250920ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3430332bull,
0x3433313a6469202full,0x616475635f5f2031ull,0x383834333173625full,0x090a30333178302bull,
0x203233662e64616dull,0x25202c3731662509ull,0x316625202c333366ull,0x37316625202c3331ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c38316625ull,0x20202020203b3731ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009333933093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c343131662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d383033ull,0x323433313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x6d090a3433317830ull,0x09203233662e6461ull,0x6625202c39316625ull,0x31316625202c3333ull,
0x3b39316625202c34ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c303266ull,
0x2020202020203b39ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093439330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3531316625ull,0x625f616475635f5full,
0x332b383834333173ull,0x202f2f093b5d3231ull,0x20333433313a6469ull,0x625f616475635f5full,
0x302b383834333173ull,0x616d090a38333178ull,0x2509203233662e64ull,0x336625202c313266ull,
0x3531316625202c33ull,0x093b31326625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x31326625202c3232ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300935393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c36313166ull,
0x73625f616475635full,0x31332b3838343331ull,0x69202f2f093b5d36ull,0x5f20343433313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a633331ull,0x662509203233662eull,
0x33336625202c3332ull,0x2c3631316625202cull,0x2f093b3332662520ull,0x2e766f6d090a202full,
0x3266250920323366ull,0x3b33326625202c34ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009363933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c373131ull,0x3173625f61647563ull,0x3032332b38383433ull,0x6469202f2f093b5dull,
0x5f5f20353433313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a3034ull,
0x3266250920323366ull,0x2c33336625202c35ull,0x202c373131662520ull,0x2f2f093b35326625ull,
0x662e766f6d090a20ull,0x3632662509203233ull,0x203b35326625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093739ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3831ull,0x333173625f616475ull,0x5d3432332b383834ull,
0x3a6469202f2f093bull,0x635f5f2036343331ull,0x333173625f616475ull,0x343178302b383834ull,
0x662e64616d090a34ull,0x3732662509203233ull,0x202c33336625202cull,0x25202c3831316625ull,
0x202f2f093b373266ull,0x33662e766f6d090aull,0x2c38326625092032ull,0x20203b3732662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300938ull,
0x662e646572616873ull,0x3131662509203233ull,0x75635f5f5b202c39ull,0x34333173625f6164ull,
0x3b5d3832332b3838ull,0x313a6469202f2f09ull,0x75635f5f20373433ull,0x34333173625f6164ull,
0x38343178302b3838ull,0x33662e64616d090aull,0x2c39326625092032ull,0x25202c3333662520ull,
0x6625202c39313166ull,0x0a202f2f093b3932ull,0x3233662e766f6d09ull,0x202c303366250920ull,
0x2020203b39326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3939330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3032316625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3233332b38ull,0x33313a6469202f2full,0x6475635f5f203834ull,
0x3834333173625f61ull,0x0a63343178302b38ull,0x3233662e64616d09ull,0x202c313366250920ull,
0x6625202c33336625ull,0x336625202c303231ull,0x090a202f2f093b31ull,0x203233662e766f6dull,
0x25202c3233662509ull,0x202020203b313366ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0936333409353109ull,0x6c672e646c090a30ull,0x3233662e6c61626full,0x202c333366250920ull,
0x5d302b346472255bull,0x3a6469202f2f093bull,0x6c2e090a39343331ull,0x383309353109636full,
0x2e646c090a300934ull,0x662e646572616873ull,0x3231662509203233ull,0x75635f5f5b202c31ull,
0x34333173625f6164ull,0x3b5d3034332b3838ull,0x313a6469202f2f09ull,0x75635f5f20303533ull,
0x34333173625f6164ull,0x34353178302b3838ull,0x33662e64616d090aull,0x202c316625092032ull,
0x6625202c34336625ull,0x316625202c313231ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x316625202c326625ull,0x202020202020203bull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009353833093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c323231662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d343433ull,0x313533313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3835317830ull,0x09203233662e6461ull,
0x336625202c336625ull,0x3232316625202c34ull,0x2f093b336625202cull,0x2e766f6d090a202full,
0x3466250920323366ull,0x20203b336625202cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009363833ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c333231ull,0x3173625f61647563ull,0x3834332b38383433ull,0x6469202f2f093b5dull,
0x5f5f20323533313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a6335ull,
0x3566250920323366ull,0x202c34336625202cull,0x25202c3332316625ull,0x0a202f2f093b3566ull,
0x3233662e766f6d09ull,0x25202c3666250920ull,0x20202020203b3566ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3738330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3432316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3235332b38ull,
0x33313a6469202f2full,0x6475635f5f203335ull,0x3834333173625f61ull,0x0a30363178302b38ull,
0x3233662e64616d09ull,0x25202c3766250920ull,0x316625202c343366ull,0x3b376625202c3432ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b376625202c3866ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093838330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3532316625ull,0x625f616475635f5full,0x332b383834333173ull,
0x202f2f093b5d3635ull,0x20343533313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a34363178ull,0x2509203233662e64ull,0x34336625202c3966ull,0x2c3532316625202cull,
0x2f2f093b39662520ull,0x662e766f6d090a20ull,0x3031662509203233ull,0x20203b396625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093938ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3632ull,0x333173625f616475ull,
0x5d3036332b383834ull,0x3a6469202f2f093bull,0x635f5f2035353331ull,0x333173625f616475ull,
0x363178302b383834ull,0x662e64616d090a38ull,0x3131662509203233ull,0x202c34336625202cull,
0x25202c3632316625ull,0x202f2f093b313166ull,0x33662e766f6d090aull,0x2c32316625092032ull,
0x20203b3131662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300930ull,0x662e646572616873ull,0x3231662509203233ull,0x75635f5f5b202c37ull,
0x34333173625f6164ull,0x3b5d3436332b3838ull,0x313a6469202f2f09ull,0x75635f5f20363533ull,
0x34333173625f6164ull,0x63363178302b3838ull,0x33662e64616d090aull,0x2c33316625092032ull,
0x25202c3433662520ull,0x6625202c37323166ull,0x0a202f2f093b3331ull,0x3233662e766f6d09ull,
0x202c343166250920ull,0x2020203b33316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3139330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3832316625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3836332b38ull,0x33313a6469202f2full,
0x6475635f5f203735ull,0x3834333173625f61ull,0x0a30373178302b38ull,0x3233662e64616d09ull,
0x202c353166250920ull,0x6625202c34336625ull,0x316625202c383231ull,0x090a202f2f093b35ull,
0x203233662e766f6dull,0x25202c3631662509ull,0x202020203b353166ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0932393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x2c39323166250920ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3237332bull,
0x3533313a6469202full,0x616475635f5f2038ull,0x383834333173625full,0x090a34373178302bull,
0x203233662e64616dull,0x25202c3731662509ull,0x316625202c343366ull,0x37316625202c3932ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c38316625ull,0x20202020203b3731ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009333933093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c303331662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d363733ull,0x393533313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x6d090a3837317830ull,0x09203233662e6461ull,0x6625202c39316625ull,0x33316625202c3433ull,
0x3b39316625202c30ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c303266ull,
0x2020202020203b39ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093439330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3133316625ull,0x625f616475635f5full,
0x332b383834333173ull,0x202f2f093b5d3038ull,0x20303633313a6469ull,0x625f616475635f5full,
0x302b383834333173ull,0x616d090a63373178ull,0x2509203233662e64ull,0x336625202c313266ull,
0x3133316625202c34ull,0x093b31326625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x31326625202c3232ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300935393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c32333166ull,
0x73625f616475635full,0x38332b3838343331ull,0x69202f2f093b5d34ull,0x5f20313633313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a303831ull,0x662509203233662eull,
0x34336625202c3332ull,0x2c3233316625202cull,0x2f093b3332662520ull,0x2e766f6d090a202full,
0x3266250920323366ull,0x3b33326625202c34ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009363933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c333331ull,0x3173625f61647563ull,0x3838332b38383433ull,0x6469202f2f093b5dull,
0x5f5f20323633313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a3438ull,
0x3266250920323366ull,0x2c34336625202c35ull,0x202c333331662520ull,0x2f2f093b35326625ull,
0x662e766f6d090a20ull,0x3632662509203233ull,0x203b35326625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093739ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3433ull,0x333173625f616475ull,0x5d3239332b383834ull,
0x3a6469202f2f093bull,0x635f5f2033363331ull,0x333173625f616475ull,0x383178302b383834ull,
0x662e64616d090a38ull,0x3732662509203233ull,0x202c34336625202cull,0x25202c3433316625ull,
0x202f2f093b373266ull,0x33662e766f6d090aull,0x2c38326625092032ull,0x20203b3732662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300938ull,
0x662e646572616873ull,0x3331662509203233ull,0x75635f5f5b202c35ull,0x34333173625f6164ull,
0x3b5d3639332b3838ull,0x313a6469202f2f09ull,0x75635f5f20343633ull,0x34333173625f6164ull,
0x63383178302b3838ull,0x33662e64616d090aull,0x2c39326625092032ull,0x25202c3433662520ull,
0x6625202c35333166ull,0x0a202f2f093b3932ull,0x3233662e766f6d09ull,0x202c303366250920ull,
0x2020203b39326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3939330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3633316625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3030342b38ull,0x33313a6469202f2full,0x6475635f5f203536ull,
0x3834333173625f61ull,0x0a30393178302b38ull,0x3233662e64616d09ull,0x202c313366250920ull,
0x6625202c34336625ull,0x336625202c363331ull,0x090a202f2f093b31ull,0x203233662e766f6dull,
0x25202c3233662509ull,0x202020203b313366ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0937333409353109ull,0x752e646461090a30ull,0x3464722509203436ull,0x3831647225202c38ull,
0x203b34647225202cull,0x6c090a202f2f0920ull,0x6c61626f6c672e64ull,0x662509203233662eull,
0x6472255b202c3433ull,0x2f093b5d302b3834ull,0x3633313a6469202full,0x09636f6c2e090a36ull,
0x3009343833093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c373331662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383034ull,0x373633313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3839317830ull,0x09203233662e6461ull,
0x336625202c316625ull,0x3733316625202c35ull,0x2f093b316625202cull,0x2e766f6d090a202full,
0x3266250920323366ull,0x20203b316625202cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009353833ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c383331ull,0x3173625f61647563ull,0x3231342b38383433ull,0x6469202f2f093b5dull,
0x5f5f20383633313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a6339ull,
0x3366250920323366ull,0x202c35336625202cull,0x25202c3833316625ull,0x0a202f2f093b3366ull,
0x3233662e766f6d09ull,0x25202c3466250920ull,0x20202020203b3366ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3638330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3933316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3631342b38ull,
0x33313a6469202f2full,0x6475635f5f203936ull,0x3834333173625f61ull,0x0a30613178302b38ull,
0x3233662e64616d09ull,0x25202c3566250920ull,0x316625202c353366ull,0x3b356625202c3933ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b356625202c3666ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093738330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3034316625ull,0x625f616475635f5full,0x342b383834333173ull,
0x202f2f093b5d3032ull,0x20303733313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a34613178ull,0x2509203233662e64ull,0x35336625202c3766ull,0x2c3034316625202cull,
0x2f2f093b37662520ull,0x662e766f6d090a20ull,0x2c38662509203233ull,0x2020203b37662520ull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093838ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3134ull,0x333173625f616475ull,
0x5d3432342b383834ull,0x3a6469202f2f093bull,0x635f5f2031373331ull,0x333173625f616475ull,
0x613178302b383834ull,0x662e64616d090a38ull,0x2c39662509203233ull,0x25202c3533662520ull,
0x6625202c31343166ull,0x090a202f2f093b39ull,0x203233662e766f6dull,0x25202c3031662509ull,
0x20202020203b3966ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0939383309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c32343166250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3832342bull,0x3733313a6469202full,0x616475635f5f2032ull,
0x383834333173625full,0x090a63613178302bull,0x203233662e64616dull,0x25202c3131662509ull,
0x316625202c353366ull,0x31316625202c3234ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c32316625ull,0x20202020203b3131ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009303933093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c333431662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d323334ull,0x333733313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3062317830ull,0x09203233662e6461ull,
0x6625202c33316625ull,0x34316625202c3533ull,0x3b33316625202c33ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c343166ull,0x2020202020203b33ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093139330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3434316625ull,0x625f616475635f5full,0x342b383834333173ull,0x202f2f093b5d3633ull,
0x20343733313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a34623178ull,
0x2509203233662e64ull,0x336625202c353166ull,0x3434316625202c35ull,0x093b35316625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x35316625202c3631ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300932393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c35343166ull,0x73625f616475635full,0x34342b3838343331ull,
0x69202f2f093b5d30ull,0x5f20353733313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a386231ull,0x662509203233662eull,0x35336625202c3731ull,0x2c3534316625202cull,
0x2f093b3731662520ull,0x2e766f6d090a202full,0x3166250920323366ull,0x3b37316625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009333933ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c363431ull,0x3173625f61647563ull,
0x3434342b38383433ull,0x6469202f2f093b5dull,0x5f5f20363733313aull,0x3173625f61647563ull,
0x3178302b38383433ull,0x2e64616d090a6362ull,0x3166250920323366ull,0x2c35336625202c39ull,
0x202c363431662520ull,0x2f2f093b39316625ull,0x662e766f6d090a20ull,0x3032662509203233ull,
0x203b39316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x646c090a30093439ull,0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3734ull,
0x333173625f616475ull,0x5d3834342b383834ull,0x3a6469202f2f093bull,0x635f5f2037373331ull,
0x333173625f616475ull,0x633178302b383834ull,0x662e64616d090a30ull,0x3132662509203233ull,
0x202c35336625202cull,0x25202c3734316625ull,0x202f2f093b313266ull,0x33662e766f6d090aull,
0x2c32326625092032ull,0x20203b3132662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300935ull,0x662e646572616873ull,0x3431662509203233ull,
0x75635f5f5b202c38ull,0x34333173625f6164ull,0x3b5d3235342b3838ull,0x313a6469202f2f09ull,
0x75635f5f20383733ull,0x34333173625f6164ull,0x34633178302b3838ull,0x33662e64616d090aull,
0x2c33326625092032ull,0x25202c3533662520ull,0x6625202c38343166ull,0x0a202f2f093b3332ull,
0x3233662e766f6d09ull,0x202c343266250920ull,0x2020203b33326625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3639330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3934316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3635342b38ull,
0x33313a6469202f2full,0x6475635f5f203937ull,0x3834333173625f61ull,0x0a38633178302b38ull,
0x3233662e64616d09ull,0x202c353266250920ull,0x6625202c35336625ull,0x326625202c393431ull,
0x090a202f2f093b35ull,0x203233662e766f6dull,0x25202c3632662509ull,0x202020203b353266ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0937393309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c30353166250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3036342bull,0x3833313a6469202full,0x616475635f5f2030ull,0x383834333173625full,
0x090a63633178302bull,0x203233662e64616dull,0x25202c3732662509ull,0x316625202c353366ull,
0x37326625202c3035ull,0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c38326625ull,
0x20202020203b3732ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009383933093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c313531662509ull,0x5f616475635f5f5bull,
0x2b38383433317362ull,0x2f2f093b5d343634ull,0x313833313a646920ull,0x5f616475635f5f20ull,
0x2b38383433317362ull,0x6d090a3064317830ull,0x09203233662e6461ull,0x6625202c39326625ull,
0x35316625202c3533ull,0x3b39326625202c31ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x326625202c303366ull,0x2020202020203b39ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093939330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3235316625ull,
0x625f616475635f5full,0x342b383834333173ull,0x202f2f093b5d3836ull,0x20323833313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x616d090a34643178ull,0x2509203233662e64ull,
0x336625202c313366ull,0x3235316625202c35ull,0x093b31336625202cull,0x766f6d090a202f2full,
0x662509203233662eull,0x31336625202c3233ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300938333409ull,0x203436752e646461ull,0x202c393464722509ull,
0x25202c3032647225ull,0x2f0920203b346472ull,0x672e646c090a202full,0x33662e6c61626f6cull,
0x2c35336625092032ull,0x2b39346472255b20ull,0x69202f2f093b5d30ull,0x090a333833313a64ull,
0x09353109636f6c2eull,0x6c090a3009343833ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c333531ull,0x3173625f61647563ull,0x3637342b38383433ull,0x6469202f2f093b5dull,
0x5f5f20343833313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a6364ull,
0x3166250920323366ull,0x202c36336625202cull,0x25202c3335316625ull,0x0a202f2f093b3166ull,
0x3233662e766f6d09ull,0x25202c3266250920ull,0x20202020203b3166ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3538330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3435316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3038342b38ull,
0x33313a6469202f2full,0x6475635f5f203538ull,0x3834333173625f61ull,0x0a30653178302b38ull,
0x3233662e64616d09ull,0x25202c3366250920ull,0x316625202c363366ull,0x3b336625202c3435ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b336625202c3466ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093638330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3535316625ull,0x625f616475635f5full,0x342b383834333173ull,
0x202f2f093b5d3438ull,0x20363833313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a34653178ull,0x2509203233662e64ull,0x36336625202c3566ull,0x2c3535316625202cull,
0x2f2f093b35662520ull,0x662e766f6d090a20ull,0x2c36662509203233ull,0x2020203b35662520ull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093738ull,
0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3635ull,0x333173625f616475ull,
0x5d3838342b383834ull,0x3a6469202f2f093bull,0x635f5f2037383331ull,0x333173625f616475ull,
0x653178302b383834ull,0x662e64616d090a38ull,0x2c37662509203233ull,0x25202c3633662520ull,
0x6625202c36353166ull,0x090a202f2f093b37ull,0x203233662e766f6dull,0x6625202c38662509ull,
0x2020202020203b37ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0938383309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c37353166250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3239342bull,0x3833313a6469202full,0x616475635f5f2038ull,
0x383834333173625full,0x090a63653178302bull,0x203233662e64616dull,0x6625202c39662509ull,
0x35316625202c3633ull,0x093b396625202c37ull,0x766f6d090a202f2full,0x662509203233662eull,
0x3b396625202c3031ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300939383309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c38353166ull,
0x73625f616475635full,0x39342b3838343331ull,0x69202f2f093b5d36ull,0x5f20393833313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a306631ull,0x662509203233662eull,
0x36336625202c3131ull,0x2c3835316625202cull,0x2f093b3131662520ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x3b31316625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009303933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c393531ull,0x3173625f61647563ull,0x3030352b38383433ull,0x6469202f2f093b5dull,
0x5f5f20303933313aull,0x3173625f61647563ull,0x3178302b38383433ull,0x2e64616d090a3466ull,
0x3166250920323366ull,0x2c36336625202c33ull,0x202c393531662520ull,0x2f2f093b33316625ull,
0x662e766f6d090a20ull,0x3431662509203233ull,0x203b33316625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093139ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3036ull,0x333173625f616475ull,0x5d3430352b383834ull,
0x3a6469202f2f093bull,0x635f5f2031393331ull,0x333173625f616475ull,0x663178302b383834ull,
0x662e64616d090a38ull,0x3531662509203233ull,0x202c36336625202cull,0x25202c3036316625ull,
0x202f2f093b353166ull,0x33662e766f6d090aull,0x2c36316625092032ull,0x20203b3531662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300932ull,
0x662e646572616873ull,0x3631662509203233ull,0x75635f5f5b202c31ull,0x34333173625f6164ull,
0x3b5d3830352b3838ull,0x313a6469202f2f09ull,0x75635f5f20323933ull,0x34333173625f6164ull,
0x63663178302b3838ull,0x33662e64616d090aull,0x2c37316625092032ull,0x25202c3633662520ull,
0x6625202c31363166ull,0x0a202f2f093b3731ull,0x3233662e766f6d09ull,0x202c383166250920ull,
0x2020203b37316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3339330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3236316625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3231352b38ull,0x33313a6469202f2full,0x6475635f5f203339ull,
0x3834333173625f61ull,0x0a30303278302b38ull,0x3233662e64616d09ull,0x202c393166250920ull,
0x6625202c36336625ull,0x316625202c323631ull,0x090a202f2f093b39ull,0x203233662e766f6dull,
0x25202c3032662509ull,0x202020203b393166ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0934393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c33363166250920ull,
0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3631352bull,0x3933313a6469202full,
0x616475635f5f2034ull,0x383834333173625full,0x090a34303278302bull,0x203233662e64616dull,
0x25202c3132662509ull,0x316625202c363366ull,0x31326625202c3336ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x6625202c32326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009353933093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c343631662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d303235ull,
0x353933313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3830327830ull,
0x09203233662e6461ull,0x6625202c33326625ull,0x36316625202c3633ull,0x3b33326625202c34ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x326625202c343266ull,0x2020202020203b33ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093639330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3536316625ull,0x625f616475635f5full,0x352b383834333173ull,
0x202f2f093b5d3432ull,0x20363933313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a63303278ull,0x2509203233662e64ull,0x336625202c353266ull,0x3536316625202c36ull,
0x093b35326625202cull,0x766f6d090a202f2full,0x662509203233662eull,0x35326625202c3632ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937393309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c36363166ull,0x73625f616475635full,
0x32352b3838343331ull,0x69202f2f093b5d38ull,0x5f20373933313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a303132ull,0x662509203233662eull,0x36336625202c3732ull,
0x2c3636316625202cull,0x2f093b3732662520ull,0x2e766f6d090a202full,0x3266250920323366ull,
0x3b37326625202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009383933ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c373631ull,
0x3173625f61647563ull,0x3233352b38383433ull,0x6469202f2f093b5dull,0x5f5f20383933313aull,
0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a3431ull,0x3266250920323366ull,
0x2c36336625202c39ull,0x202c373631662520ull,0x2f2f093b39326625ull,0x662e766f6d090a20ull,
0x3033662509203233ull,0x203b39326625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093939ull,0x2e6465726168732eull,0x3166250920323366ull,
0x635f5f5b202c3836ull,0x333173625f616475ull,0x5d3633352b383834ull,0x3a6469202f2f093bull,
0x635f5f2039393331ull,0x333173625f616475ull,0x313278302b383834ull,0x662e64616d090a38ull,
0x3133662509203233ull,0x202c36336625202cull,0x25202c3836316625ull,0x202f2f093b313366ull,
0x33662e766f6d090aull,0x2c32336625092032ull,0x20203b3133662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x333409353109636full,0x646461090a300939ull,0x722509203436752eull,
0x647225202c303564ull,0x34647225202c3232ull,0x0a202f2f0920203bull,0x626f6c672e646c09ull,
0x09203233662e6c61ull,0x255b202c36336625ull,0x3b5d302b30356472ull,0x313a6469202f2f09ull,
0x6f6c2e090a303034ull,0x3134340935310963ull,0x2e646461090a3009ull,0x6472250920343675ull,
0x3033647225202c34ull,0x203b34647225202cull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009343833ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c393631ull,
0x3173625f61647563ull,0x3434352b38383433ull,0x6469202f2f093b5dull,0x5f5f20313034313aull,
0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a3032ull,0x3166250920323366ull,
0x202c33336625202cull,0x25202c3936316625ull,0x0a202f2f093b3166ull,0x3233662e766f6d09ull,
0x25202c3266250920ull,0x20202020203b3166ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3538330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3037316625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3834352b38ull,0x34313a6469202f2full,
0x6475635f5f203230ull,0x3834333173625f61ull,0x0a34323278302b38ull,0x3233662e64616d09ull,
0x25202c3366250920ull,0x316625202c333366ull,0x3b336625202c3037ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x3b336625202c3466ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093638330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3137316625ull,0x625f616475635f5full,0x352b383834333173ull,0x202f2f093b5d3235ull,
0x20333034313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a38323278ull,
0x2509203233662e64ull,0x33336625202c3566ull,0x2c3137316625202cull,0x2f2f093b35662520ull,
0x662e766f6d090a20ull,0x2c36662509203233ull,0x2020203b35662520ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093738ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3237ull,0x333173625f616475ull,0x5d3635352b383834ull,
0x3a6469202f2f093bull,0x635f5f2034303431ull,0x333173625f616475ull,0x323278302b383834ull,
0x662e64616d090a63ull,0x2c37662509203233ull,0x25202c3333662520ull,0x6625202c32373166ull,
0x090a202f2f093b37ull,0x203233662e766f6dull,0x6625202c38662509ull,0x2020202020203b37ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0938383309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c33373166250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3036352bull,0x3034313a6469202full,0x616475635f5f2035ull,0x383834333173625full,
0x090a30333278302bull,0x203233662e64616dull,0x6625202c39662509ull,0x37316625202c3333ull,
0x093b396625202c33ull,0x766f6d090a202f2full,0x662509203233662eull,0x3b396625202c3031ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939383309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c34373166ull,0x73625f616475635full,
0x36352b3838343331ull,0x69202f2f093b5d34ull,0x5f20363034313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a343332ull,0x662509203233662eull,0x33336625202c3131ull,
0x2c3437316625202cull,0x2f093b3131662520ull,0x2e766f6d090a202full,0x3166250920323366ull,
0x3b31316625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009303933ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c353731ull,
0x3173625f61647563ull,0x3836352b38383433ull,0x6469202f2f093b5dull,0x5f5f20373034313aull,
0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a3833ull,0x3166250920323366ull,
0x2c33336625202c33ull,0x202c353731662520ull,0x2f2f093b33316625ull,0x662e766f6d090a20ull,
0x3431662509203233ull,0x203b33316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093139ull,0x2e6465726168732eull,0x3166250920323366ull,
0x635f5f5b202c3637ull,0x333173625f616475ull,0x5d3237352b383834ull,0x3a6469202f2f093bull,
0x635f5f2038303431ull,0x333173625f616475ull,0x333278302b383834ull,0x662e64616d090a63ull,
0x3531662509203233ull,0x202c33336625202cull,0x25202c3637316625ull,0x202f2f093b353166ull,
0x33662e766f6d090aull,0x2c36316625092032ull,0x20203b3531662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300932ull,0x662e646572616873ull,
0x3731662509203233ull,0x75635f5f5b202c37ull,0x34333173625f6164ull,0x3b5d3637352b3838ull,
0x313a6469202f2f09ull,0x75635f5f20393034ull,0x34333173625f6164ull,0x30343278302b3838ull,
0x33662e64616d090aull,0x2c37316625092032ull,0x25202c3333662520ull,0x6625202c37373166ull,
0x0a202f2f093b3731ull,0x3233662e766f6d09ull,0x202c383166250920ull,0x2020203b37316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3339330935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x3837316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,
0x093b5d3038352b38ull,0x34313a6469202f2full,0x6475635f5f203031ull,0x3834333173625f61ull,
0x0a34343278302b38ull,0x3233662e64616d09ull,0x202c393166250920ull,0x6625202c33336625ull,
0x316625202c383731ull,0x090a202f2f093b39ull,0x203233662e766f6dull,0x25202c3032662509ull,
0x202020203b393166ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0934393309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c39373166250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3438352bull,0x3134313a6469202full,0x616475635f5f2031ull,
0x383834333173625full,0x090a38343278302bull,0x203233662e64616dull,0x25202c3132662509ull,
0x316625202c333366ull,0x31326625202c3937ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c32326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009353933093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c303831662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383835ull,0x323134313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a6334327830ull,0x09203233662e6461ull,
0x6625202c33326625ull,0x38316625202c3333ull,0x3b33326625202c30ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x326625202c343266ull,0x2020202020203b33ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093639330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3138316625ull,0x625f616475635f5full,0x352b383834333173ull,0x202f2f093b5d3239ull,
0x20333134313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a30353278ull,
0x2509203233662e64ull,0x336625202c353266ull,0x3138316625202c33ull,0x093b35326625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x35326625202c3632ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c32383166ull,0x73625f616475635full,0x39352b3838343331ull,
0x69202f2f093b5d36ull,0x5f20343134313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a343532ull,0x662509203233662eull,0x33336625202c3732ull,0x2c3238316625202cull,
0x2f093b3732662520ull,0x2e766f6d090a202full,0x3266250920323366ull,0x3b37326625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009383933ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c333831ull,0x3173625f61647563ull,
0x3030362b38383433ull,0x6469202f2f093b5dull,0x5f5f20353134313aull,0x3173625f61647563ull,
0x3278302b38383433ull,0x2e64616d090a3835ull,0x3266250920323366ull,0x2c33336625202c39ull,
0x202c333831662520ull,0x2f2f093b39326625ull,0x662e766f6d090a20ull,0x3033662509203233ull,
0x203b39326625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x646c090a30093939ull,0x2e6465726168732eull,0x3166250920323366ull,0x635f5f5b202c3438ull,
0x333173625f616475ull,0x5d3430362b383834ull,0x3a6469202f2f093bull,0x635f5f2036313431ull,
0x333173625f616475ull,0x353278302b383834ull,0x662e64616d090a63ull,0x3133662509203233ull,
0x202c33336625202cull,0x25202c3438316625ull,0x202f2f093b313366ull,0x33662e766f6d090aull,
0x2c32336625092032ull,0x20203b3133662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x343409353109636full,0x2e646c090a300932ull,0x662e6c61626f6c67ull,0x3333662509203233ull,
0x2b346472255b202cull,0x69202f2f093b5d30ull,0x090a373134313a64ull,0x09353109636f6c2eull,
0x6c090a3009343833ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c353831ull,
0x3173625f61647563ull,0x3231362b38383433ull,0x6469202f2f093b5dull,0x5f5f20383134313aull,
0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a3436ull,0x3166250920323366ull,
0x202c34336625202cull,0x25202c3538316625ull,0x0a202f2f093b3166ull,0x3233662e766f6d09ull,
0x25202c3266250920ull,0x20202020203b3166ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3538330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3638316625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3631362b38ull,0x34313a6469202f2full,
0x6475635f5f203931ull,0x3834333173625f61ull,0x0a38363278302b38ull,0x3233662e64616d09ull,
0x25202c3366250920ull,0x316625202c343366ull,0x3b336625202c3638ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x3b336625202c3466ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093638330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3738316625ull,0x625f616475635f5full,0x362b383834333173ull,0x202f2f093b5d3032ull,
0x20303234313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a63363278ull,
0x2509203233662e64ull,0x34336625202c3566ull,0x2c3738316625202cull,0x2f2f093b35662520ull,
0x662e766f6d090a20ull,0x2c36662509203233ull,0x2020203b35662520ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093738ull,0x2e6465726168732eull,
0x3166250920323366ull,0x635f5f5b202c3838ull,0x333173625f616475ull,0x5d3432362b383834ull,
0x3a6469202f2f093bull,0x635f5f2031323431ull,0x333173625f616475ull,0x373278302b383834ull,
0x662e64616d090a30ull,0x2c37662509203233ull,0x25202c3433662520ull,0x6625202c38383166ull,
0x090a202f2f093b37ull,0x203233662e766f6dull,0x6625202c38662509ull,0x2020202020203b37ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0938383309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c39383166250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3832362bull,0x3234313a6469202full,0x616475635f5f2032ull,0x383834333173625full,
0x090a34373278302bull,0x203233662e64616dull,0x6625202c39662509ull,0x38316625202c3433ull,
0x093b396625202c39ull,0x766f6d090a202f2full,0x662509203233662eull,0x3b396625202c3031ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939383309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c30393166ull,0x73625f616475635full,
0x33362b3838343331ull,0x69202f2f093b5d32ull,0x5f20333234313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a383732ull,0x662509203233662eull,0x34336625202c3131ull,
0x2c3039316625202cull,0x2f093b3131662520ull,0x2e766f6d090a202full,0x3166250920323366ull,
0x3b31316625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009303933ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c313931ull,
0x3173625f61647563ull,0x3633362b38383433ull,0x6469202f2f093b5dull,0x5f5f20343234313aull,
0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a6337ull,0x3166250920323366ull,
0x2c34336625202c33ull,0x202c313931662520ull,0x2f2f093b33316625ull,0x662e766f6d090a20ull,
0x3431662509203233ull,0x203b33316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093139ull,0x2e6465726168732eull,0x3166250920323366ull,
0x635f5f5b202c3239ull,0x333173625f616475ull,0x5d3034362b383834ull,0x3a6469202f2f093bull,
0x635f5f2035323431ull,0x333173625f616475ull,0x383278302b383834ull,0x662e64616d090a30ull,
0x3531662509203233ull,0x202c34336625202cull,0x25202c3239316625ull,0x202f2f093b353166ull,
0x33662e766f6d090aull,0x2c36316625092032ull,0x20203b3531662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300932ull,0x662e646572616873ull,
0x3931662509203233ull,0x75635f5f5b202c33ull,0x34333173625f6164ull,0x3b5d3434362b3838ull,
0x313a6469202f2f09ull,0x75635f5f20363234ull,0x34333173625f6164ull,0x34383278302b3838ull,
0x33662e64616d090aull,0x2c37316625092032ull,0x25202c3433662520ull,0x6625202c33393166ull,
0x0a202f2f093b3731ull,0x3233662e766f6d09ull,0x202c383166250920ull,0x2020203b37316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3339330935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x3439316625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,
0x093b5d3834362b38ull,0x34313a6469202f2full,0x6475635f5f203732ull,0x3834333173625f61ull,
0x0a38383278302b38ull,0x3233662e64616d09ull,0x202c393166250920ull,0x6625202c34336625ull,
0x316625202c343931ull,0x090a202f2f093b39ull,0x203233662e766f6dull,0x25202c3032662509ull,
0x202020203b393166ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0934393309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c35393166250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3235362bull,0x3234313a6469202full,0x616475635f5f2038ull,
0x383834333173625full,0x090a63383278302bull,0x203233662e64616dull,0x25202c3132662509ull,
0x316625202c343366ull,0x31326625202c3539ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c32326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009353933093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c363931662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d363536ull,0x393234313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3039327830ull,0x09203233662e6461ull,
0x6625202c33326625ull,0x39316625202c3433ull,0x3b33326625202c36ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x326625202c343266ull,0x2020202020203b33ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093639330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3739316625ull,0x625f616475635f5full,0x362b383834333173ull,0x202f2f093b5d3036ull,
0x20303334313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a34393278ull,
0x2509203233662e64ull,0x336625202c353266ull,0x3739316625202c34ull,0x093b35326625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x35326625202c3632ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c38393166ull,0x73625f616475635full,0x36362b3838343331ull,
0x69202f2f093b5d34ull,0x5f20313334313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a383932ull,0x662509203233662eull,0x34336625202c3732ull,0x2c3839316625202cull,
0x2f093b3732662520ull,0x2e766f6d090a202full,0x3266250920323366ull,0x3b37326625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009383933ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c393931ull,0x3173625f61647563ull,
0x3836362b38383433ull,0x6469202f2f093b5dull,0x5f5f20323334313aull,0x3173625f61647563ull,
0x3278302b38383433ull,0x2e64616d090a6339ull,0x3266250920323366ull,0x2c34336625202c39ull,
0x202c393931662520ull,0x2f2f093b39326625ull,0x662e766f6d090a20ull,0x3033662509203233ull,
0x203b39326625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x646c090a30093939ull,0x2e6465726168732eull,0x3266250920323366ull,0x635f5f5b202c3030ull,
0x333173625f616475ull,0x5d3237362b383834ull,0x3a6469202f2f093bull,0x635f5f2033333431ull,
0x333173625f616475ull,0x613278302b383834ull,0x662e64616d090a30ull,0x3133662509203233ull,
0x202c34336625202cull,0x25202c3030326625ull,0x202f2f093b313366ull,0x33662e766f6d090aull,
0x2c32336625092032ull,0x20203b3133662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x343409353109636full,0x646461090a300933ull,0x722509203436752eull,0x647225202c313564ull,
0x34647225202c3831ull,0x0a202f2f0920203bull,0x626f6c672e646c09ull,0x09203233662e6c61ull,
0x255b202c34336625ull,0x3b5d302b31356472ull,0x313a6469202f2f09ull,0x6f6c2e090a343334ull,
0x3438330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3130326625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3038362b38ull,0x34313a6469202f2full,
0x6475635f5f203533ull,0x3834333173625f61ull,0x0a38613278302b38ull,0x3233662e64616d09ull,
0x25202c3166250920ull,0x326625202c353366ull,0x3b316625202c3130ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x3b316625202c3266ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093538330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3230326625ull,0x625f616475635f5full,0x362b383834333173ull,0x202f2f093b5d3438ull,
0x20363334313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a63613278ull,
0x2509203233662e64ull,0x35336625202c3366ull,0x2c3230326625202cull,0x2f2f093b33662520ull,
0x662e766f6d090a20ull,0x2c34662509203233ull,0x2020203b33662520ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093638ull,0x2e6465726168732eull,
0x3266250920323366ull,0x635f5f5b202c3330ull,0x333173625f616475ull,0x5d3838362b383834ull,
0x3a6469202f2f093bull,0x635f5f2037333431ull,0x333173625f616475ull,0x623278302b383834ull,
0x662e64616d090a30ull,0x2c35662509203233ull,0x25202c3533662520ull,0x6625202c33303266ull,
0x090a202f2f093b35ull,0x203233662e766f6dull,0x6625202c36662509ull,0x2020202020203b35ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0937383309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c34303266250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3239362bull,0x3334313a6469202full,0x616475635f5f2038ull,0x383834333173625full,
0x090a34623278302bull,0x203233662e64616dull,0x6625202c37662509ull,0x30326625202c3533ull,
0x093b376625202c34ull,0x766f6d090a202f2full,0x662509203233662eull,0x203b376625202c38ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938383309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c35303266ull,0x73625f616475635full,
0x39362b3838343331ull,0x69202f2f093b5d36ull,0x5f20393334313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a386232ull,0x662509203233662eull,0x2c35336625202c39ull,
0x202c353032662520ull,0x202f2f093b396625ull,0x33662e766f6d090aull,0x2c30316625092032ull,
0x2020203b39662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,
0x2e646c090a300939ull,0x662e646572616873ull,0x3032662509203233ull,0x75635f5f5b202c36ull,
0x34333173625f6164ull,0x3b5d3030372b3838ull,0x313a6469202f2f09ull,0x75635f5f20303434ull,
0x34333173625f6164ull,0x63623278302b3838ull,0x33662e64616d090aull,0x2c31316625092032ull,
0x25202c3533662520ull,0x6625202c36303266ull,0x0a202f2f093b3131ull,0x3233662e766f6d09ull,
0x202c323166250920ull,0x2020203b31316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3039330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3730326625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3430372b38ull,0x34313a6469202f2full,
0x6475635f5f203134ull,0x3834333173625f61ull,0x0a30633278302b38ull,0x3233662e64616d09ull,
0x202c333166250920ull,0x6625202c35336625ull,0x316625202c373032ull,0x090a202f2f093b33ull,
0x203233662e766f6dull,0x25202c3431662509ull,0x202020203b333166ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0931393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x2c38303266250920ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3830372bull,
0x3434313a6469202full,0x616475635f5f2032ull,0x383834333173625full,0x090a34633278302bull,
0x203233662e64616dull,0x25202c3531662509ull,0x326625202c353366ull,0x35316625202c3830ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c36316625ull,0x20202020203b3531ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009323933093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c393032662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d323137ull,0x333434313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x6d090a3863327830ull,0x09203233662e6461ull,0x6625202c37316625ull,0x30326625202c3533ull,
0x3b37316625202c39ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c383166ull,
0x2020202020203b37ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093339330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3031326625ull,0x625f616475635f5full,
0x372b383834333173ull,0x202f2f093b5d3631ull,0x20343434313a6469ull,0x625f616475635f5full,
0x302b383834333173ull,0x616d090a63633278ull,0x2509203233662e64ull,0x336625202c393166ull,
0x3031326625202c35ull,0x093b39316625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x39316625202c3032ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300934393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c31313266ull,
0x73625f616475635full,0x32372b3838343331ull,0x69202f2f093b5d30ull,0x5f20353434313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a306432ull,0x662509203233662eull,
0x35336625202c3132ull,0x2c3131326625202cull,0x2f093b3132662520ull,0x2e766f6d090a202full,
0x3266250920323366ull,0x3b31326625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009353933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c323132ull,0x3173625f61647563ull,0x3432372b38383433ull,0x6469202f2f093b5dull,
0x5f5f20363434313aull,0x3173625f61647563ull,0x3278302b38383433ull,0x2e64616d090a3464ull,
0x3266250920323366ull,0x2c35336625202c33ull,0x202c323132662520ull,0x2f2f093b33326625ull,
0x662e766f6d090a20ull,0x3432662509203233ull,0x203b33326625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093639ull,0x2e6465726168732eull,
0x3266250920323366ull,0x635f5f5b202c3331ull,0x333173625f616475ull,0x5d3832372b383834ull,
0x3a6469202f2f093bull,0x635f5f2037343431ull,0x333173625f616475ull,0x643278302b383834ull,
0x662e64616d090a38ull,0x3532662509203233ull,0x202c35336625202cull,0x25202c3331326625ull,
0x202f2f093b353266ull,0x33662e766f6d090aull,0x2c36326625092032ull,0x20203b3532662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300937ull,
0x662e646572616873ull,0x3132662509203233ull,0x75635f5f5b202c34ull,0x34333173625f6164ull,
0x3b5d3233372b3838ull,0x313a6469202f2f09ull,0x75635f5f20383434ull,0x34333173625f6164ull,
0x63643278302b3838ull,0x33662e64616d090aull,0x2c37326625092032ull,0x25202c3533662520ull,
0x6625202c34313266ull,0x0a202f2f093b3732ull,0x3233662e766f6d09ull,0x202c383266250920ull,
0x2020203b37326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3839330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3531326625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3633372b38ull,0x34313a6469202f2full,0x6475635f5f203934ull,
0x3834333173625f61ull,0x0a30653278302b38ull,0x3233662e64616d09ull,0x202c393266250920ull,
0x6625202c35336625ull,0x326625202c353132ull,0x090a202f2f093b39ull,0x203233662e766f6dull,
0x25202c3033662509ull,0x202020203b393266ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0939393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c36313266250920ull,
0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3034372bull,0x3534313a6469202full,
0x616475635f5f2030ull,0x383834333173625full,0x090a34653278302bull,0x203233662e64616dull,
0x25202c3133662509ull,0x326625202c353366ull,0x31336625202c3631ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x6625202c32336625ull,0x20202020203b3133ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009343434093531ull,0x36752e646461090aull,0x3235647225092034ull,
0x2c3032647225202cull,0x20203b3464722520ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,
0x3366250920323366ull,0x356472255b202c35ull,0x2f2f093b5d302b32ull,0x313534313a646920ull,
0x3109636f6c2e090aull,0x0a30093438330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3731326625ull,0x625f616475635f5full,0x372b383834333173ull,0x202f2f093b5d3834ull,
0x20323534313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a63653278ull,
0x2509203233662e64ull,0x36336625202c3166ull,0x2c3731326625202cull,0x2f2f093b31662520ull,
0x662e766f6d090a20ull,0x2c32662509203233ull,0x2020203b31662520ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093538ull,0x2e6465726168732eull,
0x3266250920323366ull,0x635f5f5b202c3831ull,0x333173625f616475ull,0x5d3235372b383834ull,
0x3a6469202f2f093bull,0x635f5f2033353431ull,0x333173625f616475ull,0x663278302b383834ull,
0x662e64616d090a30ull,0x2c33662509203233ull,0x25202c3633662520ull,0x6625202c38313266ull,
0x090a202f2f093b33ull,0x203233662e766f6dull,0x6625202c34662509ull,0x2020202020203b33ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0936383309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c39313266250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3635372bull,0x3534313a6469202full,0x616475635f5f2034ull,0x383834333173625full,
0x090a34663278302bull,0x203233662e64616dull,0x6625202c35662509ull,0x31326625202c3633ull,
0x093b356625202c39ull,0x766f6d090a202f2full,0x662509203233662eull,0x203b356625202c36ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937383309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c30323266ull,0x73625f616475635full,
0x36372b3838343331ull,0x69202f2f093b5d30ull,0x5f20353534313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a386632ull,0x662509203233662eull,0x2c36336625202c37ull,
0x202c303232662520ull,0x202f2f093b376625ull,0x33662e766f6d090aull,0x202c386625092032ull,
0x202020203b376625ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,
0x2e646c090a300938ull,0x662e646572616873ull,0x3232662509203233ull,0x75635f5f5b202c31ull,
0x34333173625f6164ull,0x3b5d3436372b3838ull,0x313a6469202f2f09ull,0x75635f5f20363534ull,
0x34333173625f6164ull,0x63663278302b3838ull,0x33662e64616d090aull,0x202c396625092032ull,
0x6625202c36336625ull,0x396625202c313232ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c30316625ull,0x2020202020203b39ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009393833093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c323232662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383637ull,0x373534313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3030337830ull,0x09203233662e6461ull,
0x6625202c31316625ull,0x32326625202c3633ull,0x3b31316625202c32ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c323166ull,0x2020202020203b31ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093039330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3332326625ull,0x625f616475635f5full,0x372b383834333173ull,0x202f2f093b5d3237ull,
0x20383534313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a34303378ull,
0x2509203233662e64ull,0x336625202c333166ull,0x3332326625202c36ull,0x093b33316625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x33316625202c3431ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300931393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c34323266ull,0x73625f616475635full,0x37372b3838343331ull,
0x69202f2f093b5d36ull,0x5f20393534313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a383033ull,0x662509203233662eull,0x36336625202c3531ull,0x2c3432326625202cull,
0x2f093b3531662520ull,0x2e766f6d090a202full,0x3166250920323366ull,0x3b35316625202c36ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009323933ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c353232ull,0x3173625f61647563ull,
0x3038372b38383433ull,0x6469202f2f093b5dull,0x5f5f20303634313aull,0x3173625f61647563ull,
0x3378302b38383433ull,0x2e64616d090a6330ull,0x3166250920323366ull,0x2c36336625202c37ull,
0x202c353232662520ull,0x2f2f093b37316625ull,0x662e766f6d090a20ull,0x3831662509203233ull,
0x203b37316625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x646c090a30093339ull,0x2e6465726168732eull,0x3266250920323366ull,0x635f5f5b202c3632ull,
0x333173625f616475ull,0x5d3438372b383834ull,0x3a6469202f2f093bull,0x635f5f2031363431ull,
0x333173625f616475ull,0x313378302b383834ull,0x662e64616d090a30ull,0x3931662509203233ull,
0x202c36336625202cull,0x25202c3632326625ull,0x202f2f093b393166ull,0x33662e766f6d090aull,
0x2c30326625092032ull,0x20203b3931662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300934ull,0x662e646572616873ull,0x3232662509203233ull,
0x75635f5f5b202c37ull,0x34333173625f6164ull,0x3b5d3838372b3838ull,0x313a6469202f2f09ull,
0x75635f5f20323634ull,0x34333173625f6164ull,0x34313378302b3838ull,0x33662e64616d090aull,
0x2c31326625092032ull,0x25202c3633662520ull,0x6625202c37323266ull,0x0a202f2f093b3132ull,
0x3233662e766f6d09ull,0x202c323266250920ull,0x2020203b31326625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3539330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3832326625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3239372b38ull,
0x34313a6469202f2full,0x6475635f5f203336ull,0x3834333173625f61ull,0x0a38313378302b38ull,
0x3233662e64616d09ull,0x202c333266250920ull,0x6625202c36336625ull,0x326625202c383232ull,
0x090a202f2f093b33ull,0x203233662e766f6dull,0x25202c3432662509ull,0x202020203b333266ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0936393309353109ull,0x68732e646c090a30ull,
0x3233662e64657261ull,0x2c39323266250920ull,0x616475635f5f5b20ull,0x383834333173625full,
0x2f093b5d3639372bull,0x3634313a6469202full,0x616475635f5f2034ull,0x383834333173625full,
0x090a63313378302bull,0x203233662e64616dull,0x25202c3532662509ull,0x326625202c363366ull,
0x35326625202c3932ull,0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c36326625ull,
0x20202020203b3532ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009373933093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c303332662509ull,0x5f616475635f5f5bull,
0x2b38383433317362ull,0x2f2f093b5d303038ull,0x353634313a646920ull,0x5f616475635f5f20ull,
0x2b38383433317362ull,0x6d090a3032337830ull,0x09203233662e6461ull,0x6625202c37326625ull,
0x33326625202c3633ull,0x3b37326625202c30ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x326625202c383266ull,0x2020202020203b37ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093839330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3133326625ull,
0x625f616475635f5full,0x382b383834333173ull,0x202f2f093b5d3430ull,0x20363634313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x616d090a34323378ull,0x2509203233662e64ull,
0x336625202c393266ull,0x3133326625202c36ull,0x093b39326625202cull,0x766f6d090a202f2full,
0x662509203233662eull,0x39326625202c3033ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300939393309ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5b202c32333266ull,0x73625f616475635full,0x30382b3838343331ull,0x69202f2f093b5d38ull,
0x5f20373634313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x64616d090a383233ull,
0x662509203233662eull,0x36336625202c3133ull,0x2c3233326625202cull,0x2f093b3133662520ull,
0x2e766f6d090a202full,0x3366250920323366ull,0x3b31336625202c32ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x61090a3009353434ull,0x09203436752e6464ull,
0x25202c3335647225ull,0x7225202c32326472ull,0x2f2f0920203b3464ull,0x6c672e646c090a20ull,
0x3233662e6c61626full,0x202c363366250920ull,0x302b33356472255bull,0x6469202f2f093b5dull,
0x2e090a383634313aull,0x3409353109636f6cull,0x6461090a30093734ull,0x2509203436752e64ull,
0x647225202c346472ull,0x34647225202c3033ull,0x202f2f092020203bull,0x3109636f6c2e090aull,
0x0a30093438330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3333326625ull,
0x625f616475635f5full,0x382b383834333173ull,0x202f2f093b5d3631ull,0x20393634313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x616d090a30333378ull,0x2509203233662e64ull,
0x33336625202c3166ull,0x2c3333326625202cull,0x2f2f093b31662520ull,0x662e766f6d090a20ull,
0x2c32662509203233ull,0x2020203b31662520ull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093538ull,0x2e6465726168732eull,0x3266250920323366ull,
0x635f5f5b202c3433ull,0x333173625f616475ull,0x5d3032382b383834ull,0x3a6469202f2f093bull,
0x635f5f2030373431ull,0x333173625f616475ull,0x333378302b383834ull,0x662e64616d090a34ull,
0x2c33662509203233ull,0x25202c3333662520ull,0x6625202c34333266ull,0x090a202f2f093b33ull,
0x203233662e766f6dull,0x6625202c34662509ull,0x2020202020203b33ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0936383309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x2c35333266250920ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3432382bull,
0x3734313a6469202full,0x616475635f5f2031ull,0x383834333173625full,0x090a38333378302bull,
0x203233662e64616dull,0x6625202c35662509ull,0x33326625202c3333ull,0x093b356625202c35ull,
0x766f6d090a202f2full,0x662509203233662eull,0x203b356625202c36ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937383309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c36333266ull,0x73625f616475635full,0x32382b3838343331ull,
0x69202f2f093b5d38ull,0x5f20323734313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a633333ull,0x662509203233662eull,0x2c33336625202c37ull,0x202c363332662520ull,
0x202f2f093b376625ull,0x33662e766f6d090aull,0x202c386625092032ull,0x202020203b376625ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,0x2e646c090a300938ull,
0x662e646572616873ull,0x3332662509203233ull,0x75635f5f5b202c37ull,0x34333173625f6164ull,
0x3b5d3233382b3838ull,0x313a6469202f2f09ull,0x75635f5f20333734ull,0x34333173625f6164ull,
0x30343378302b3838ull,0x33662e64616d090aull,0x202c396625092032ull,0x6625202c33336625ull,
0x396625202c373332ull,0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c30316625ull,
0x2020202020203b39ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009393833093531ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c383332662509ull,0x5f616475635f5f5bull,
0x2b38383433317362ull,0x2f2f093b5d363338ull,0x343734313a646920ull,0x5f616475635f5f20ull,
0x2b38383433317362ull,0x6d090a3434337830ull,0x09203233662e6461ull,0x6625202c31316625ull,
0x33326625202c3333ull,0x3b31316625202c38ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x316625202c323166ull,0x2020202020203b31ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093039330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3933326625ull,
0x625f616475635f5full,0x382b383834333173ull,0x202f2f093b5d3034ull,0x20353734313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x616d090a38343378ull,0x2509203233662e64ull,
0x336625202c333166ull,0x3933326625202c33ull,0x093b33316625202cull,0x766f6d090a202f2full,
0x662509203233662eull,0x33316625202c3431ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300931393309ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5b202c30343266ull,0x73625f616475635full,0x34382b3838343331ull,0x69202f2f093b5d34ull,
0x5f20363734313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x64616d090a633433ull,
0x662509203233662eull,0x33336625202c3531ull,0x2c3034326625202cull,0x2f093b3531662520ull,
0x2e766f6d090a202full,0x3166250920323366ull,0x3b35316625202c36ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009323933ull,0x6465726168732e64ull,
0x662509203233662eull,0x5f5f5b202c313432ull,0x3173625f61647563ull,0x3834382b38383433ull,
0x6469202f2f093b5dull,0x5f5f20373734313aull,0x3173625f61647563ull,0x3378302b38383433ull,
0x2e64616d090a3035ull,0x3166250920323366ull,0x2c33336625202c37ull,0x202c313432662520ull,
0x2f2f093b37316625ull,0x662e766f6d090a20ull,0x3831662509203233ull,0x203b37316625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093339ull,
0x2e6465726168732eull,0x3266250920323366ull,0x635f5f5b202c3234ull,0x333173625f616475ull,
0x5d3235382b383834ull,0x3a6469202f2f093bull,0x635f5f2038373431ull,0x333173625f616475ull,
0x353378302b383834ull,0x662e64616d090a34ull,0x3931662509203233ull,0x202c33336625202cull,
0x25202c3234326625ull,0x202f2f093b393166ull,0x33662e766f6d090aull,0x2c30326625092032ull,
0x20203b3931662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300934ull,0x662e646572616873ull,0x3432662509203233ull,0x75635f5f5b202c33ull,
0x34333173625f6164ull,0x3b5d3635382b3838ull,0x313a6469202f2f09ull,0x75635f5f20393734ull,
0x34333173625f6164ull,0x38353378302b3838ull,0x33662e64616d090aull,0x2c31326625092032ull,
0x25202c3333662520ull,0x6625202c33343266ull,0x0a202f2f093b3132ull,0x3233662e766f6d09ull,
0x202c323266250920ull,0x2020203b31326625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3539330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,0x3434326625092032ull,
0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3036382b38ull,0x34313a6469202f2full,
0x6475635f5f203038ull,0x3834333173625f61ull,0x0a63353378302b38ull,0x3233662e64616d09ull,
0x202c333266250920ull,0x6625202c33336625ull,0x326625202c343432ull,0x090a202f2f093b33ull,
0x203233662e766f6dull,0x25202c3432662509ull,0x202020203b333266ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0936393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x2c35343266250920ull,0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3436382bull,
0x3834313a6469202full,0x616475635f5f2031ull,0x383834333173625full,0x090a30363378302bull,
0x203233662e64616dull,0x25202c3532662509ull,0x326625202c333366ull,0x35326625202c3534ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x6625202c36326625ull,0x20202020203b3532ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009373933093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c363432662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d383638ull,0x323834313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x6d090a3436337830ull,0x09203233662e6461ull,0x6625202c37326625ull,0x34326625202c3333ull,
0x3b37326625202c36ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x326625202c383266ull,
0x2020202020203b37ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093839330935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3734326625ull,0x625f616475635f5full,
0x382b383834333173ull,0x202f2f093b5d3237ull,0x20333834313a6469ull,0x625f616475635f5full,
0x302b383834333173ull,0x616d090a38363378ull,0x2509203233662e64ull,0x336625202c393266ull,
0x3734326625202c33ull,0x093b39326625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x39326625202c3033ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300939393309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c38343266ull,
0x73625f616475635full,0x37382b3838343331ull,0x69202f2f093b5d36ull,0x5f20343834313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a633633ull,0x662509203233662eull,
0x33336625202c3133ull,0x2c3834326625202cull,0x2f093b3133662520ull,0x2e766f6d090a202full,
0x3366250920323366ull,0x3b31336625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009343833ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c393432ull,0x3173625f61647563ull,0x3438382b38383433ull,0x6469202f2f093b5dull,
0x5f5f20353834313aull,0x3173625f61647563ull,0x3378302b38383433ull,0x2e64616d090a3437ull,
0x3166250920323366ull,0x202c34336625202cull,0x25202c3934326625ull,0x0a202f2f093b3166ull,
0x3233662e766f6d09ull,0x25202c3266250920ull,0x20202020203b3166ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3538330935310963ull,0x732e646c090a3009ull,0x33662e6465726168ull,
0x3035326625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,0x093b5d3838382b38ull,
0x34313a6469202f2full,0x6475635f5f203638ull,0x3834333173625f61ull,0x0a38373378302b38ull,
0x3233662e64616d09ull,0x25202c3366250920ull,0x326625202c343366ull,0x3b336625202c3035ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x3b336625202c3466ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093638330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3135326625ull,0x625f616475635f5full,0x382b383834333173ull,
0x202f2f093b5d3239ull,0x20373834313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a63373378ull,0x2509203233662e64ull,0x34336625202c3566ull,0x2c3135326625202cull,
0x2f2f093b35662520ull,0x662e766f6d090a20ull,0x2c36662509203233ull,0x2020203b35662520ull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093738ull,
0x2e6465726168732eull,0x3266250920323366ull,0x635f5f5b202c3235ull,0x333173625f616475ull,
0x5d3639382b383834ull,0x3a6469202f2f093bull,0x635f5f2038383431ull,0x333173625f616475ull,
0x383378302b383834ull,0x662e64616d090a30ull,0x2c37662509203233ull,0x25202c3433662520ull,
0x6625202c32353266ull,0x090a202f2f093b37ull,0x203233662e766f6dull,0x6625202c38662509ull,
0x2020202020203b37ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0938383309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c33353266250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3030392bull,0x3834313a6469202full,0x616475635f5f2039ull,
0x383834333173625full,0x090a34383378302bull,0x203233662e64616dull,0x6625202c39662509ull,
0x35326625202c3433ull,0x093b396625202c33ull,0x766f6d090a202f2full,0x662509203233662eull,
0x3b396625202c3031ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300939383309ull,0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c34353266ull,
0x73625f616475635full,0x30392b3838343331ull,0x69202f2f093b5d34ull,0x5f20303934313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a383833ull,0x662509203233662eull,
0x34336625202c3131ull,0x2c3435326625202cull,0x2f093b3131662520ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x3b31316625202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009303933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c353532ull,0x3173625f61647563ull,0x3830392b38383433ull,0x6469202f2f093b5dull,
0x5f5f20313934313aull,0x3173625f61647563ull,0x3378302b38383433ull,0x2e64616d090a6338ull,
0x3166250920323366ull,0x2c34336625202c33ull,0x202c353532662520ull,0x2f2f093b33316625ull,
0x662e766f6d090a20ull,0x3431662509203233ull,0x203b33316625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x646c090a30093139ull,0x2e6465726168732eull,
0x3266250920323366ull,0x635f5f5b202c3635ull,0x333173625f616475ull,0x5d3231392b383834ull,
0x3a6469202f2f093bull,0x635f5f2032393431ull,0x333173625f616475ull,0x393378302b383834ull,
0x662e64616d090a30ull,0x3531662509203233ull,0x202c34336625202cull,0x25202c3635326625ull,
0x202f2f093b353166ull,0x33662e766f6d090aull,0x2c36316625092032ull,0x20203b3531662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300932ull,
0x662e646572616873ull,0x3532662509203233ull,0x75635f5f5b202c37ull,0x34333173625f6164ull,
0x3b5d3631392b3838ull,0x313a6469202f2f09ull,0x75635f5f20333934ull,0x34333173625f6164ull,
0x34393378302b3838ull,0x33662e64616d090aull,0x2c37316625092032ull,0x25202c3433662520ull,
0x6625202c37353266ull,0x0a202f2f093b3731ull,0x3233662e766f6d09ull,0x202c383166250920ull,
0x2020203b37316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3339330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3835326625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3032392b38ull,0x34313a6469202f2full,0x6475635f5f203439ull,
0x3834333173625f61ull,0x0a38393378302b38ull,0x3233662e64616d09ull,0x202c393166250920ull,
0x6625202c34336625ull,0x316625202c383532ull,0x090a202f2f093b39ull,0x203233662e766f6dull,
0x25202c3032662509ull,0x202020203b393166ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0934393309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c39353266250920ull,
0x616475635f5f5b20ull,0x383834333173625full,0x2f093b5d3432392bull,0x3934313a6469202full,
0x616475635f5f2035ull,0x383834333173625full,0x090a63393378302bull,0x203233662e64616dull,
0x25202c3132662509ull,0x326625202c343366ull,0x31326625202c3935ull,0x6d090a202f2f093bull,
0x09203233662e766full,0x6625202c32326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009353933093531ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c303632662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383239ull,
0x363934313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3061337830ull,
0x09203233662e6461ull,0x6625202c33326625ull,0x36326625202c3433ull,0x3b33326625202c30ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x326625202c343266ull,0x2020202020203b33ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093639330935ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3136326625ull,0x625f616475635f5full,0x392b383834333173ull,
0x202f2f093b5d3233ull,0x20373934313a6469ull,0x625f616475635f5full,0x302b383834333173ull,
0x616d090a34613378ull,0x2509203233662e64ull,0x336625202c353266ull,0x3136326625202c34ull,
0x093b35326625202cull,0x766f6d090a202f2full,0x662509203233662eull,0x35326625202c3632ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937393309ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c32363266ull,0x73625f616475635full,
0x33392b3838343331ull,0x69202f2f093b5d36ull,0x5f20383934313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a386133ull,0x662509203233662eull,0x34336625202c3732ull,
0x2c3236326625202cull,0x2f093b3732662520ull,0x2e766f6d090a202full,0x3266250920323366ull,
0x3b37326625202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009383933ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c333632ull,
0x3173625f61647563ull,0x3034392b38383433ull,0x6469202f2f093b5dull,0x5f5f20393934313aull,
0x3173625f61647563ull,0x3378302b38383433ull,0x2e64616d090a6361ull,0x3266250920323366ull,
0x2c34336625202c39ull,0x202c333632662520ull,0x2f2f093b39326625ull,0x662e766f6d090a20ull,
0x3033662509203233ull,0x203b39326625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093939ull,0x2e6465726168732eull,0x3266250920323366ull,
0x635f5f5b202c3436ull,0x333173625f616475ull,0x5d3434392b383834ull,0x3a6469202f2f093bull,
0x635f5f2030303531ull,0x333173625f616475ull,0x623378302b383834ull,0x662e64616d090a30ull,
0x3133662509203233ull,0x202c34336625202cull,0x25202c3436326625ull,0x202f2f093b313366ull,
0x33662e766f6d090aull,0x2c32336625092032ull,0x20203b3133662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x383309353109636full,0x2e646c090a300934ull,0x662e646572616873ull,
0x3632662509203233ull,0x75635f5f5b202c35ull,0x34333173625f6164ull,0x3b5d3235392b3838ull,
0x313a6469202f2f09ull,0x75635f5f20313035ull,0x34333173625f6164ull,0x38623378302b3838ull,
0x33662e64616d090aull,0x202c316625092032ull,0x6625202c35336625ull,0x316625202c353632ull,
0x6d090a202f2f093bull,0x09203233662e766full,0x316625202c326625ull,0x202020202020203bull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009353833093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c363632662509ull,0x5f616475635f5f5bull,0x2b38383433317362ull,
0x2f2f093b5d363539ull,0x323035313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,
0x6d090a6362337830ull,0x09203233662e6461ull,0x336625202c336625ull,0x3636326625202c35ull,
0x2f093b336625202cull,0x2e766f6d090a202full,0x3466250920323366ull,0x20203b336625202cull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009363833ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c373632ull,0x3173625f61647563ull,
0x3036392b38383433ull,0x6469202f2f093b5dull,0x5f5f20333035313aull,0x3173625f61647563ull,
0x3378302b38383433ull,0x2e64616d090a3063ull,0x3566250920323366ull,0x202c35336625202cull,
0x25202c3736326625ull,0x0a202f2f093b3566ull,0x3233662e766f6d09ull,0x25202c3666250920ull,
0x20202020203b3566ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3738330935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x3836326625092032ull,0x6475635f5f5b202cull,
0x3834333173625f61ull,0x093b5d3436392b38ull,0x35313a6469202f2full,0x6475635f5f203430ull,
0x3834333173625f61ull,0x0a34633378302b38ull,0x3233662e64616d09ull,0x25202c3766250920ull,
0x326625202c353366ull,0x3b376625202c3836ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x3b376625202c3866ull,0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093838330935ull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3936326625ull,
0x625f616475635f5full,0x392b383834333173ull,0x202f2f093b5d3836ull,0x20353035313a6469ull,
0x625f616475635f5full,0x302b383834333173ull,0x616d090a38633378ull,0x2509203233662e64ull,
0x35336625202c3966ull,0x2c3936326625202cull,0x2f2f093b39662520ull,0x662e766f6d090a20ull,
0x3031662509203233ull,0x20203b396625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3309353109636f6cull,0x646c090a30093938ull,0x2e6465726168732eull,0x3266250920323366ull,
0x635f5f5b202c3037ull,0x333173625f616475ull,0x5d3237392b383834ull,0x3a6469202f2f093bull,
0x635f5f2036303531ull,0x333173625f616475ull,0x633378302b383834ull,0x662e64616d090a63ull,
0x3131662509203233ull,0x202c35336625202cull,0x25202c3037326625ull,0x202f2f093b313166ull,
0x33662e766f6d090aull,0x2c32316625092032ull,0x20203b3131662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300930ull,0x662e646572616873ull,
0x3732662509203233ull,0x75635f5f5b202c31ull,0x34333173625f6164ull,0x3b5d3637392b3838ull,
0x313a6469202f2f09ull,0x75635f5f20373035ull,0x34333173625f6164ull,0x30643378302b3838ull,
0x33662e64616d090aull,0x2c33316625092032ull,0x25202c3533662520ull,0x6625202c31373266ull,
0x0a202f2f093b3331ull,0x3233662e766f6d09ull,0x202c343166250920ull,0x2020203b33316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3139330935310963ull,0x732e646c090a3009ull,
0x33662e6465726168ull,0x3237326625092032ull,0x6475635f5f5b202cull,0x3834333173625f61ull,
0x093b5d3038392b38ull,0x35313a6469202f2full,0x6475635f5f203830ull,0x3834333173625f61ull,
0x0a34643378302b38ull,0x3233662e64616d09ull,0x202c353166250920ull,0x6625202c35336625ull,
0x316625202c323732ull,0x090a202f2f093b35ull,0x203233662e766f6dull,0x25202c3631662509ull,
0x202020203b353166ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0932393309353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x2c33373266250920ull,0x616475635f5f5b20ull,
0x383834333173625full,0x2f093b5d3438392bull,0x3035313a6469202full,0x616475635f5f2039ull,
0x383834333173625full,0x090a38643378302bull,0x203233662e64616dull,0x25202c3731662509ull,
0x326625202c353366ull,0x37316625202c3337ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6625202c38316625ull,0x20202020203b3731ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009333933093531ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c343732662509ull,
0x5f616475635f5f5bull,0x2b38383433317362ull,0x2f2f093b5d383839ull,0x303135313a646920ull,
0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a6364337830ull,0x09203233662e6461ull,
0x6625202c39316625ull,0x37326625202c3533ull,0x3b39316625202c34ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c303266ull,0x2020202020203b39ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093439330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3537326625ull,0x625f616475635f5full,0x392b383834333173ull,0x202f2f093b5d3239ull,
0x20313135313a6469ull,0x625f616475635f5full,0x302b383834333173ull,0x616d090a30653378ull,
0x2509203233662e64ull,0x336625202c313266ull,0x3537326625202c35ull,0x093b31326625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x31326625202c3232ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300935393309ull,0x65726168732e646cull,
0x2509203233662e64ull,0x5f5b202c36373266ull,0x73625f616475635full,0x39392b3838343331ull,
0x69202f2f093b5d36ull,0x5f20323135313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a346533ull,0x662509203233662eull,0x35336625202c3332ull,0x2c3637326625202cull,
0x2f093b3332662520ull,0x2e766f6d090a202full,0x3266250920323366ull,0x3b33326625202c34ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009363933ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c373732ull,0x3173625f61647563ull,
0x3030312b38383433ull,0x69202f2f093b5d30ull,0x5f20333135313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a386533ull,0x662509203233662eull,0x35336625202c3532ull,
0x2c3737326625202cull,0x2f093b3532662520ull,0x2e766f6d090a202full,0x3266250920323366ull,
0x3b35326625202c36ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6c090a3009373933ull,0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c383732ull,
0x3173625f61647563ull,0x3030312b38383433ull,0x69202f2f093b5d34ull,0x5f20343135313a64ull,
0x73625f616475635full,0x78302b3838343331ull,0x64616d090a636533ull,0x662509203233662eull,
0x35336625202c3732ull,0x2c3837326625202cull,0x2f093b3732662520ull,0x2e766f6d090a202full,
0x3266250920323366ull,0x3b37326625202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6c090a3009383933ull,0x6465726168732e64ull,0x662509203233662eull,
0x5f5f5b202c393732ull,0x3173625f61647563ull,0x3030312b38383433ull,0x69202f2f093b5d38ull,
0x5f20353135313a64ull,0x73625f616475635full,0x78302b3838343331ull,0x64616d090a306633ull,
0x662509203233662eull,0x35336625202c3932ull,0x2c3937326625202cull,0x2f093b3932662520ull,
0x2e766f6d090a202full,0x3366250920323366ull,0x3b39326625202c30ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009393933ull,0x6465726168732e64ull,
0x662509203233662eull,0x5f5f5b202c303832ull,0x3173625f61647563ull,0x3130312b38383433ull,
0x69202f2f093b5d32ull,0x5f20363135313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a346633ull,0x662509203233662eull,0x35336625202c3133ull,0x2c3038326625202cull,
0x2f093b3133662520ull,0x2e766f6d090a202full,0x3366250920323366ull,0x3b31336625202c32ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009343833ull,
0x6465726168732e64ull,0x662509203233662eull,0x5f5f5b202c313832ull,0x3173625f61647563ull,
0x3230312b38383433ull,0x69202f2f093b5d30ull,0x5f20373135313a64ull,0x73625f616475635full,
0x78302b3838343331ull,0x64616d090a636633ull,0x662509203233662eull,0x2c36336625202c31ull,
0x202c313832662520ull,0x202f2f093b316625ull,0x33662e766f6d090aull,0x202c326625092032ull,
0x202020203b316625ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,
0x2e646c090a300935ull,0x662e646572616873ull,0x3832662509203233ull,0x75635f5f5b202c32ull,
0x34333173625f6164ull,0x5d343230312b3838ull,0x3a6469202f2f093bull,0x635f5f2038313531ull,
0x333173625f616475ull,0x303478302b383834ull,0x662e64616d090a30ull,0x2c33662509203233ull,
0x25202c3633662520ull,0x6625202c32383266ull,0x090a202f2f093b33ull,0x203233662e766f6dull,
0x6625202c34662509ull,0x2020202020203b33ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0936383309353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x2c33383266250920ull,
0x616475635f5f5b20ull,0x383834333173625full,0x093b5d383230312bull,0x35313a6469202f2full,
0x6475635f5f203931ull,0x3834333173625f61ull,0x0a34303478302b38ull,0x3233662e64616d09ull,
0x25202c3566250920ull,0x326625202c363366ull,0x3b356625202c3338ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x3b356625202c3666ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093738330935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3438326625ull,0x625f616475635f5full,0x312b383834333173ull,0x2f2f093b5d323330ull,
0x303235313a646920ull,0x5f616475635f5f20ull,0x2b38383433317362ull,0x6d090a3830347830ull,
0x09203233662e6461ull,0x336625202c376625ull,0x3438326625202c36ull,0x2f093b376625202cull,
0x2e766f6d090a202full,0x3866250920323366ull,0x20203b376625202cull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009383833ull,0x6465726168732e64ull,
0x662509203233662eull,0x5f5f5b202c353832ull,0x3173625f61647563ull,0x3330312b38383433ull,
0x69202f2f093b5d36ull,0x5f20313235313a64ull,0x73625f616475635full,0x78302b3838343331ull,
0x64616d090a633034ull,0x662509203233662eull,0x2c36336625202c39ull,0x202c353832662520ull,
0x202f2f093b396625ull,0x33662e766f6d090aull,0x2c30316625092032ull,0x2020203b39662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x383309353109636full,0x2e646c090a300939ull,
0x662e646572616873ull,0x3832662509203233ull,0x75635f5f5b202c36ull,0x34333173625f6164ull,
0x5d303430312b3838ull,0x3a6469202f2f093bull,0x635f5f2032323531ull,0x333173625f616475ull,
0x313478302b383834ull,0x662e64616d090a30ull,0x3131662509203233ull,0x202c36336625202cull,
0x25202c3638326625ull,0x202f2f093b313166ull,0x33662e766f6d090aull,0x2c32316625092032ull,
0x20203b3131662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300930ull,0x662e646572616873ull,0x3832662509203233ull,0x75635f5f5b202c37ull,
0x34333173625f6164ull,0x5d343430312b3838ull,0x3a6469202f2f093bull,0x635f5f2033323531ull,
0x333173625f616475ull,0x313478302b383834ull,0x662e64616d090a34ull,0x3331662509203233ull,
0x202c36336625202cull,0x25202c3738326625ull,0x202f2f093b333166ull,0x33662e766f6d090aull,
0x2c34316625092032ull,0x20203b3331662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300931ull,0x662e646572616873ull,0x3832662509203233ull,
0x75635f5f5b202c38ull,0x34333173625f6164ull,0x5d383430312b3838ull,0x3a6469202f2f093bull,
0x635f5f2034323531ull,0x333173625f616475ull,0x313478302b383834ull,0x662e64616d090a38ull,
0x3531662509203233ull,0x202c36336625202cull,0x25202c3838326625ull,0x202f2f093b353166ull,
0x33662e766f6d090aull,0x2c36316625092032ull,0x20203b3531662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300932ull,0x662e646572616873ull,
0x3832662509203233ull,0x75635f5f5b202c39ull,0x34333173625f6164ull,0x5d323530312b3838ull,
0x3a6469202f2f093bull,0x635f5f2035323531ull,0x333173625f616475ull,0x313478302b383834ull,
0x662e64616d090a63ull,0x3731662509203233ull,0x202c36336625202cull,0x25202c3938326625ull,
0x202f2f093b373166ull,0x33662e766f6d090aull,0x2c38316625092032ull,0x20203b3731662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300933ull,
0x662e646572616873ull,0x3932662509203233ull,0x75635f5f5b202c30ull,0x34333173625f6164ull,
0x5d363530312b3838ull,0x3a6469202f2f093bull,0x635f5f2036323531ull,0x333173625f616475ull,
0x323478302b383834ull,0x662e64616d090a30ull,0x3931662509203233ull,0x202c36336625202cull,
0x25202c3039326625ull,0x202f2f093b393166ull,0x33662e766f6d090aull,0x2c30326625092032ull,
0x20203b3931662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300934ull,0x662e646572616873ull,0x3932662509203233ull,0x75635f5f5b202c31ull,
0x34333173625f6164ull,0x5d303630312b3838ull,0x3a6469202f2f093bull,0x635f5f2037323531ull,
0x333173625f616475ull,0x323478302b383834ull,0x662e64616d090a34ull,0x3132662509203233ull,
0x202c36336625202cull,0x25202c3139326625ull,0x202f2f093b313266ull,0x33662e766f6d090aull,
0x2c32326625092032ull,0x20203b3132662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300935ull,0x662e646572616873ull,0x3932662509203233ull,
0x75635f5f5b202c32ull,0x34333173625f6164ull,0x5d343630312b3838ull,0x3a6469202f2f093bull,
0x635f5f2038323531ull,0x333173625f616475ull,0x323478302b383834ull,0x662e64616d090a38ull,
0x3332662509203233ull,0x202c36336625202cull,0x25202c3239326625ull,0x202f2f093b333266ull,
0x33662e766f6d090aull,0x2c34326625092032ull,0x20203b3332662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300936ull,0x662e646572616873ull,
0x3932662509203233ull,0x75635f5f5b202c33ull,0x34333173625f6164ull,0x5d383630312b3838ull,
0x3a6469202f2f093bull,0x635f5f2039323531ull,0x333173625f616475ull,0x323478302b383834ull,
0x662e64616d090a63ull,0x3532662509203233ull,0x202c36336625202cull,0x25202c3339326625ull,
0x202f2f093b353266ull,0x33662e766f6d090aull,0x2c36326625092032ull,0x20203b3532662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,0x2e646c090a300937ull,
0x662e646572616873ull,0x3932662509203233ull,0x75635f5f5b202c34ull,0x34333173625f6164ull,
0x5d323730312b3838ull,0x3a6469202f2f093bull,0x635f5f2030333531ull,0x333173625f616475ull,
0x333478302b383834ull,0x662e64616d090a30ull,0x3732662509203233ull,0x202c36336625202cull,
0x25202c3439326625ull,0x202f2f093b373266ull,0x33662e766f6d090aull,0x2c38326625092032ull,
0x20203b3732662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x393309353109636full,
0x2e646c090a300938ull,0x662e646572616873ull,0x3932662509203233ull,0x75635f5f5b202c35ull,
0x34333173625f6164ull,0x5d363730312b3838ull,0x3a6469202f2f093bull,0x635f5f2031333531ull,
0x333173625f616475ull,0x333478302b383834ull,0x662e64616d090a34ull,0x3932662509203233ull,
0x202c36336625202cull,0x25202c3539326625ull,0x202f2f093b393266ull,0x33662e766f6d090aull,
0x2c30336625092032ull,0x20203b3932662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393309353109636full,0x2e646c090a300939ull,0x662e646572616873ull,0x3932662509203233ull,
0x75635f5f5b202c36ull,0x34333173625f6164ull,0x5d303830312b3838ull,0x3a6469202f2f093bull,
0x635f5f2032333531ull,0x333173625f616475ull,0x333478302b383834ull,0x662e64616d090a38ull,
0x3133662509203233ull,0x202c36336625202cull,0x25202c3639326625ull,0x202f2f093b313366ull,
0x33662e766f6d090aull,0x2c32336625092032ull,0x20203b3133662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x353409353109636full,0x646461090a300933ull,0x722509203436752eull,
0x39647225202c3964ull,0x2020203b3436202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300934353409ull,0x636e79732e726162ull,0x202020203b300920ull,0x2020202020202020ull,
0x2f09202020202020ull,0x70746573090a202full,0x203436752e74672eull,0x7225202c31702509ull,
0x647225202c323164ull,0x090a202f2f093b39ull,0x6172622031702540ull,0x5f335f744c240920ull,
0x2020202020203b39ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0938353409353109ull,
0x61702e646c090a30ull,0x203233732e6d6172ull,0x5b202c3032722509ull,0x6170616475635f5full,
0x6773375a5f5f6d72ull,0x664b504e4e6d6d65ull,0x696650695f305369ull,0x5d63646c5f666669ull,
0x3a6469202f2f093bull,0x635f5f2037323231ull,0x5f6d726170616475ull,0x6d6d656773375a5full,
0x305369664b504e4eull,0x666669696650695full,0x3078302b63646c5full,0x2e34326c756d090aull,
0x09203233732e6f6cull,0x7225202c31327225ull,0x3b30327225202c37ull,0x646c090a202f2f09ull,
0x752e6d617261702eull,0x3564722509203436ull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,
0x4e6d6d656773375aull,0x5f305369664b504eull,0x5f66666969665069ull,0x61705f6c61765f5full,
0x2f093b5d436d6172ull,0x3335313a6469202full,0x616475635f5f2033ull,0x375a5f5f6d726170ull,
0x504e4e6d6d656773ull,0x50695f305369664bull,0x5f5f5f6666696966ull,0x617261705f6c6176ull,
0x090a3078302b436dull,0x203233732e646461ull,0x25202c3232722509ull,0x367225202c313272ull,
0x2f0920202020203bull,0x2e747663090a202full,0x203233732e343673ull,0x202c353564722509ull,
0x2020203b32327225ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3564722509203436ull,
0x3535647225202c36ull,0x2f0920203b34202cull,0x2e646461090a202full,0x6472250920343675ull,
0x35647225202c3735ull,0x3635647225202c34ull,0x090a202f2f09203bull,0x6d617261702e646cull,
0x662509203233662eull,0x5f5f5b202c373932ull,0x6d72617061647563ull,0x6d656773375a5f5full,
0x5369664b504e4e6dull,0x6669696650695f30ull,0x5d6168706c615f66ull,0x3a6469202f2f093bull,
0x635f5f2035323231ull,0x5f6d726170616475ull,0x6d6d656773375a5full,0x305369664b504e4eull,
0x666669696650695full,0x302b6168706c615full,0x702e646c090a3078ull,0x3233662e6d617261ull,
0x2c38393266250920ull,0x616475635f5f5b20ull,0x375a5f5f6d726170ull,0x504e4e6d6d656773ull,
0x50695f305369664bull,0x65625f6666696966ull,0x202f2f093b5d6174ull,0x20363232313a6469ull,
0x6170616475635f5full,0x6773375a5f5f6d72ull,0x664b504e4e6d6d65ull,0x696650695f305369ull,
0x617465625f666669ull,0x756d090a3078302bull,0x2509203233662e6cull,0x6625202c39393266ull,
0x316625202c373932ull,0x202f2f092020203bull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x202c303033662509ull,0x302b37356472255bull,0x6469202f2f093b5dull,0x6d090a343335313aull,
0x09203233662e6461ull,0x25202c3130336625ull,0x6625202c30303366ull,0x326625202c383932ull,
0x0a202f2f093b3939ull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b37356472255bull,
0x3130336625202c5dull,0x3a6469202f2f093bull,0x7663090a35333531ull,0x33732e3436752e74ull,
0x3835647225092032ull,0x203b30327225202cull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c393564ull,0x20203b34202c3835ull,0x6461090a202f2f09ull,
0x2509203436752e64ull,0x7225202c30366472ull,0x647225202c393564ull,0x202f2f09203b3735ull,
0x33662e6c756d090aull,0x3230336625092032ull,0x2c3739326625202cull,0x2020203b33662520ull,
0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3366250920323366ull,0x6472255b202c3330ull,
0x2f093b5d302b3036ull,0x3335313a6469202full,0x662e64616d090a36ull,0x3033662509203233ull,
0x3330336625202c34ull,0x2c3839326625202cull,0x093b323033662520ull,0x2e7473090a202f2full,
0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3036ull,0x2f2f093b34303366ull,
0x373335313a646920ull,0x36752e646461090aull,0x3136647225092034ull,0x2c3935647225202cull,
0x203b303664722520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c35303366ull,
0x356625202c373932ull,0x202f2f092020203bull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x202c363033662509ull,0x302b31366472255bull,0x6469202f2f093b5dull,0x6d090a383335313aull,
0x09203233662e6461ull,0x25202c3730336625ull,0x6625202c36303366ull,0x336625202c383932ull,
0x0a202f2f093b3530ull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b31366472255bull,
0x3730336625202c5dull,0x3a6469202f2f093bull,0x6461090a39333531ull,0x2509203436752e64ull,
0x7225202c32366472ull,0x647225202c393564ull,0x202f2f09203b3136ull,0x33662e6c756d090aull,
0x3830336625092032ull,0x2c3739326625202cull,0x2020203b37662520ull,0x646c090a202f2f09ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x6472255b202c3930ull,0x2f093b5d302b3236ull,
0x3435313a6469202full,0x662e64616d090a30ull,0x3133662509203233ull,0x3930336625202c30ull,
0x2c3839326625202cull,0x093b383033662520ull,0x2e7473090a202f2full,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3236ull,0x2f2f093b30313366ull,0x313435313a646920ull,
0x36752e646461090aull,0x3336647225092034ull,0x2c3935647225202cull,0x203b323664722520ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c31313366ull,0x396625202c373932ull,
0x202f2f092020203bull,0x6f6c672e646c090aull,0x203233662e6c6162ull,0x202c323133662509ull,
0x302b33366472255bull,0x6469202f2f093b5dull,0x6d090a323435313aull,0x09203233662e6461ull,
0x25202c3331336625ull,0x6625202c32313366ull,0x336625202c383932ull,0x0a202f2f093b3131ull,
0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b33366472255bull,0x3331336625202c5dull,
0x3a6469202f2f093bull,0x6c2e090a33343531ull,0x353409353109636full,0x646461090a300937ull,
0x722509203436752eull,0x647225202c343664ull,0x36647225202c3935ull,0x0a202f2f09203b33ull,
0x353109636f6c2e09ull,0x090a300938353409ull,0x203233662e6c756dull,0x202c343133662509ull,
0x25202c3739326625ull,0x2f0920203b313166ull,0x672e646c090a202full,0x33662e6c61626f6cull,
0x3531336625092032ull,0x34366472255b202cull,0x202f2f093b5d302bull,0x0a343435313a6469ull,
0x3233662e64616d09ull,0x2c36313366250920ull,0x202c353133662520ull,0x25202c3839326625ull,
0x2f2f093b34313366ull,0x6c672e7473090a20ull,0x3233662e6c61626full,0x34366472255b0920ull,
0x336625202c5d302bull,0x69202f2f093b3631ull,0x090a353435313a64ull,0x09353109636f6c2eull,
0x61090a3009373534ull,0x09203436752e6464ull,0x25202c3436647225ull,0x7225202c39356472ull,
0x2f2f09203b343664ull,0x09636f6c2e090a20ull,0x3009383534093531ull,0x33662e6c756d090aull,
0x3731336625092032ull,0x2c3739326625202cull,0x20203b3331662520ull,0x646c090a202f2f09ull,
0x2e6c61626f6c672eull,0x3366250920323366ull,0x6472255b202c3831ull,0x2f093b5d302b3436ull,
0x3435313a6469202full,0x662e64616d090a36ull,0x3133662509203233ull,0x3831336625202c39ull,
0x2c3839326625202cull,0x093b373133662520ull,0x2e7473090a202f2full,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3436ull,0x2f2f093b39313366ull,0x373435313a646920ull,
0x3109636f6c2e090aull,0x0a30093735340935ull,0x3436752e64646109ull,0x2c34366472250920ull,
0x202c393564722520ull,0x09203b3436647225ull,0x6f6c2e090a202f2full,0x3835340935310963ull,
0x2e6c756d090a3009ull,0x3366250920323366ull,0x39326625202c3032ull,0x3b35316625202c37ull,
0x090a202f2f092020ull,0x61626f6c672e646cull,0x2509203233662e6cull,0x255b202c31323366ull,
0x3b5d302b34366472ull,0x313a6469202f2f09ull,0x64616d090a383435ull,0x662509203233662eull,
0x336625202c323233ull,0x39326625202c3132ull,0x3032336625202c38ull,0x73090a202f2f093bull,
0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b34366472ull,0x093b323233662520ull,
0x35313a6469202f2full,0x636f6c2e090a3934ull,0x0937353409353109ull,0x752e646461090a30ull,
0x3664722509203436ull,0x3935647225202c34ull,0x3b3436647225202cull,0x2e090a202f2f0920ull,
0x3409353109636f6cull,0x756d090a30093835ull,0x2509203233662e6cull,0x6625202c33323366ull,
0x316625202c373932ull,0x202f2f0920203b37ull,0x6f6c672e646c090aull,0x203233662e6c6162ull,
0x202c343233662509ull,0x302b34366472255bull,0x6469202f2f093b5dull,0x6d090a303535313aull,
0x09203233662e6461ull,0x25202c3532336625ull,0x6625202c34323366ull,0x336625202c383932ull,
0x0a202f2f093b3332ull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x302b34366472255bull,
0x3532336625202c5dull,0x3a6469202f2f093bull,0x6c2e090a31353531ull,0x353409353109636full,
0x646461090a300937ull,0x722509203436752eull,0x647225202c343664ull,0x36647225202c3935ull,
0x0a202f2f09203b34ull,0x353109636f6c2e09ull,0x090a300938353409ull,0x203233662e6c756dull,
0x202c363233662509ull,0x25202c3739326625ull,0x2f0920203b393166ull,0x672e646c090a202full,
0x33662e6c61626f6cull,0x3732336625092032ull,0x34366472255b202cull,0x202f2f093b5d302bull,
0x0a323535313a6469ull,0x3233662e64616d09ull,0x2c38323366250920ull,0x202c373233662520ull,
0x25202c3839326625ull,0x2f2f093b36323366ull,0x6c672e7473090a20ull,0x3233662e6c61626full,
0x34366472255b0920ull,0x336625202c5d302bull,0x69202f2f093b3832ull,0x090a333535313a64ull,
0x09353109636f6c2eull,0x61090a3009373534ull,0x09203436752e6464ull,0x25202c3436647225ull,
0x7225202c39356472ull,0x2f2f09203b343664ull,0x09636f6c2e090a20ull,0x3009383534093531ull,
0x33662e6c756d090aull,0x3932336625092032ull,0x2c3739326625202cull,0x20203b3132662520ull,
0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3366250920323366ull,0x6472255b202c3033ull,
0x2f093b5d302b3436ull,0x3535313a6469202full,0x662e64616d090a34ull,0x3333662509203233ull,
0x3033336625202c31ull,0x2c3839326625202cull,0x093b393233662520ull,0x2e7473090a202f2full,
0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3436ull,0x2f2f093b31333366ull,
0x353535313a646920ull,0x3109636f6c2e090aull,0x0a30093735340935ull,0x3436752e64646109ull,
0x2c34366472250920ull,0x202c393564722520ull,0x09203b3436647225ull,0x6f6c2e090a202f2full,
0x3835340935310963ull,0x2e6c756d090a3009ull,0x3366250920323366ull,0x39326625202c3233ull,
0x3b33326625202c37ull,0x090a202f2f092020ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x255b202c33333366ull,0x3b5d302b34366472ull,0x313a6469202f2f09ull,0x64616d090a363535ull,
0x662509203233662eull,0x336625202c343333ull,0x39326625202c3333ull,0x3233336625202c38ull,
0x73090a202f2f093bull,0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d302b34366472ull,
0x093b343333662520ull,0x35313a6469202f2full,0x636f6c2e090a3735ull,0x0937353409353109ull,
0x752e646461090a30ull,0x3664722509203436ull,0x3935647225202c34ull,0x3b3436647225202cull,
0x2e090a202f2f0920ull,0x3409353109636f6cull,0x756d090a30093835ull,0x2509203233662e6cull,
0x6625202c35333366ull,0x326625202c373932ull,0x202f2f0920203b35ull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x202c363333662509ull,0x302b34366472255bull,0x6469202f2f093b5dull,
0x6d090a383535313aull,0x09203233662e6461ull,0x25202c3733336625ull,0x6625202c36333366ull,
0x336625202c383932ull,0x0a202f2f093b3533ull,0x626f6c672e747309ull,0x09203233662e6c61ull,
0x302b34366472255bull,0x3733336625202c5dull,0x3a6469202f2f093bull,0x6c2e090a39353531ull,
0x353409353109636full,0x646461090a300937ull,0x722509203436752eull,0x647225202c343664ull,
0x36647225202c3935ull,0x0a202f2f09203b34ull,0x353109636f6c2e09ull,0x090a300938353409ull,
0x203233662e6c756dull,0x202c383333662509ull,0x25202c3739326625ull,0x2f0920203b373266ull,
0x672e646c090a202full,0x33662e6c61626f6cull,0x3933336625092032ull,0x34366472255b202cull,
0x202f2f093b5d302bull,0x0a303635313a6469ull,0x3233662e64616d09ull,0x2c30343366250920ull,
0x202c393333662520ull,0x25202c3839326625ull,0x2f2f093b38333366ull,0x6c672e7473090a20ull,
0x3233662e6c61626full,0x34366472255b0920ull,0x336625202c5d302bull,0x69202f2f093b3034ull,
0x090a313635313a64ull,0x09353109636f6c2eull,0x61090a3009373534ull,0x09203436752e6464ull,
0x25202c3436647225ull,0x7225202c39356472ull,0x2f2f09203b343664ull,0x09636f6c2e090a20ull,
0x3009383534093531ull,0x33662e6c756d090aull,0x3134336625092032ull,0x2c3739326625202cull,
0x20203b3932662520ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3366250920323366ull,
0x6472255b202c3234ull,0x2f093b5d302b3436ull,0x3635313a6469202full,0x662e64616d090a32ull,
0x3433662509203233ull,0x3234336625202c33ull,0x2c3839326625202cull,0x093b313433662520ull,
0x2e7473090a202f2full,0x662e6c61626f6c67ull,0x6472255b09203233ull,0x25202c5d302b3436ull,
0x2f2f093b33343366ull,0x333635313a646920ull,0x3109636f6c2e090aull,0x0a30093735340935ull,
0x3436752e64646109ull,0x2c34366472250920ull,0x202c393564722520ull,0x09203b3436647225ull,
0x6f6c2e090a202f2full,0x3835340935310963ull,0x2e6c756d090a3009ull,0x3366250920323366ull,
0x39326625202c3434ull,0x3b31336625202c37ull,0x090a202f2f092020ull,0x61626f6c672e646cull,
0x2509203233662e6cull,0x255b202c35343366ull,0x3b5d302b34366472ull,0x313a6469202f2f09ull,
0x64616d090a343635ull,0x662509203233662eull,0x336625202c363433ull,0x39326625202c3534ull,
0x3434336625202c38ull,0x73090a202f2f093bull,0x6c61626f6c672e74ull,0x255b09203233662eull,
0x2c5d302b34366472ull,0x093b363433662520ull,0x35313a6469202f2full,0x636f6c2e090a3536ull,
0x0939353409353109ull,0x3b74697865090a30ull,0x2020202020202020ull,0x2020202020202020ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x5a5f5f646e655744ull,0x4e4e6d6d65677337ull,
0x695f305369664b50ull,0x0a3a666669696650ull,0x5a5f202f2f207d09ull,0x4e4e6d6d65677337ull,
0x695f305369664b50ull,0x0a0a666669696650ull,0x207972746e652e09ull,0x69665f6b33315a5full,
0x697274616d5f6c6cull,0x090a666969665078ull,0x206765722e090a7bull,0x687225203631752eull,
0x722e090a3b3e363cull,0x203233752e206765ull,0x0a3b3e38313c7225ull,0x752e206765722e09ull,
0x363c647225203436ull,0x6765722e090a3b3eull,0x6625203233662e20ull,0x722e090a3b3e333cull,
0x646572702e206765ull,0x0a3b3e333c702520ull,0x206d617261702e09ull,0x635f5f203436752eull,
0x5f6d726170616475ull,0x69665f6b33315a5full,0x697274616d5f6c6cull,0x415f666969665078ull,
0x617261702e090a3bull,0x5f203233732e206dull,0x726170616475635full,0x5f6b33315a5f5f6dull,
0x74616d5f6c6c6966ull,0x6669696650786972ull,0x61702e090a3b4d5full,0x3233732e206d6172ull,
0x70616475635f5f20ull,0x33315a5f5f6d7261ull,0x6d5f6c6c69665f6bull,0x6966507869727461ull,
0x2e090a3b4e5f6669ull,0x662e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,
0x6c6c69665f6b3331ull,0x5078697274616d5full,0x0a3b735f66696966ull,0x353109636f6c2e09ull,
0x240a300930383409ull,0x315a5f5f3142424cull,0x5f6c6c69665f6b33ull,0x665078697274616dull,
0x6f6d090a3a666969ull,0x2509203631752e76ull,0x746325202c316872ull,0x20203b792e646961ull,
0x202f2f0920202020ull,0x31752e766f6d090aull,0x2c32687225092036ull,0x792e6469746e2520ull,
0x202020202020203bull,0x756d090a202f2f09ull,0x752e656469772e6cull,0x2c31722509203631ull,
0x25202c3168722520ull,0x202f2f093b326872ull,0x31752e766f6d090aull,0x2c33687225092036ull,
0x2e64696174632520ull,0x2020202020203b78ull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,
0x746e25202c346872ull,0x2020203b782e6469ull,0x202f2f0920202020ull,0x69772e6c756d090aull,
0x09203631752e6564ull,0x687225202c327225ull,0x3b34687225202c33ull,0x7663090a202f2f09ull,
0x31752e3233752e74ull,0x202c337225092036ull,0x203b792e64697425ull,0x202f2f0920202020ull,
0x33752e646461090aull,0x202c347225092032ull,0x317225202c337225ull,0x202020202020203bull,
0x7663090a202f2f09ull,0x31752e3233752e74ull,0x202c357225092036ull,0x203b782e64697425ull,
0x202f2f0920202020ull,0x33752e646461090aull,0x202c367225092032ull,0x327225202c357225ull,
0x202020202020203bull,0x646c090a202f2f09ull,0x732e6d617261702eull,0x2c37722509203233ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x5f6c6c69665f6b33ull,0x665078697274616dull,
0x093b5d4e5f666969ull,0x31323a6469202f2full,0x70616475635f5f20ull,0x33315a5f5f6d7261ull,
0x6d5f6c6c69665f6bull,0x6966507869727461ull,0x3078302b4e5f6669ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5f5b202c387225ull,0x6d72617061647563ull,0x665f6b33315a5f5full,
0x7274616d5f6c6c69ull,0x5f66696966507869ull,0x69202f2f093b5d4dull,0x635f5f2038323a64ull,
0x5f6d726170616475ull,0x69665f6b33315a5full,0x697274616d5f6c6cull,0x4d5f666969665078ull,
0x6573090a3078302bull,0x3233752e74672e74ull,0x722509203233732eull,0x202c387225202c39ull,
0x202f2f093b347225ull,0x33732e67656e090aull,0x2c30317225092032ull,0x2020203b39722520ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x3233752e74672e74ull,0x722509203233732eull,
0x2c377225202c3131ull,0x2f2f093b36722520ull,0x732e67656e090a20ull,0x3231722509203233ull,
0x203b31317225202cull,0x2020202020202020ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x7225202c33317225ull,0x32317225202c3031ull,0x2f2f09202020203bull,0x752e766f6d090a20ull,
0x3431722509203233ull,0x202020203b30202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x732e71652e707465ull,0x2c31702509203233ull,0x25202c3331722520ull,0x2f2f09203b343172ull,
0x2031702540090a20ull,0x744c240920617262ull,0x2020203b355f345full,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3409353109636f6cull,0x646c090a30093438ull,0x662e6d617261702eull,
0x2c31662509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x5f6c6c69665f6b33ull,
0x665078697274616dull,0x093b5d735f666969ull,0x39323a6469202f2full,0x70616475635f5f20ull,
0x33315a5f5f6d7261ull,0x6d5f6c6c69665f6bull,0x6966507869727461ull,0x3078302b735f6669ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c31647225ull,0x726170616475635full,
0x5f6b33315a5f5f6dull,0x74616d5f6c6c6966ull,0x6669696650786972ull,0x202f2f093b5d415full,
0x5f5f2030333a6469ull,0x6d72617061647563ull,0x665f6b33315a5f5full,0x7274616d5f6c6c69ull,
0x5f66696966507869ull,0x6d090a3078302b41ull,0x33732e6f6c2e6c75ull,0x2c35317225092032ull,
0x7225202c37722520ull,0x2f2f092020203b34ull,0x732e646461090a20ull,0x3631722509203233ull,
0x25202c367225202cull,0x202020203b353172ull,0x63090a202f2f0920ull,0x732e3436732e7476ull,
0x3264722509203233ull,0x203b36317225202cull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,
0x2509203436752e6full,0x647225202c336472ull,0x2020203b34202c32ull,0x61090a202f2f0920ull,
0x09203436752e6464ull,0x7225202c34647225ull,0x33647225202c3164ull,0x2f2f09202020203bull,
0x6c672e7473090a20ull,0x3233662e6c61626full,0x2b346472255b0920ull,0x3b316625202c5d30ull,
0x3a6469202f2f0920ull,0x345f744c240a3133ull,0x6f6c2e090a3a355full,0x3638340935310963ull,
0x74697865090a3009ull,0x202020202020203bull,0x2020202020202020ull,0x2020202020202020ull,
0x240a202f2f092020ull,0x5f5f646e6557444cull,0x6c69665f6b33315aull,0x78697274616d5f6cull,
0x090a3a6669696650ull,0x315a5f202f2f207dull,0x5f6c6c69665f6b33ull,0x665078697274616dull,
0x0000000a0a666969ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"206f4901b6551822",(char*)"matmult.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0};
# 5 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.c" 2
struct __T20;
struct __T21;
struct __T22;
struct __T23;
struct __T24;
struct __T20 {float *__par0;float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T21 {float *__par0;float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T22 {float *__par0;float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T23 {const float *__par0;int __par1;const float *__par2;int __par3;float *__par4;int __par5;int __par6;float __par7;float __par8;int __dummy_field;volatile char __dummy[4];};
struct __T24 {float *__par0;int __par1;int __par2;float __par3;int __dummy_field;};
# 31 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.c"
static void __sti____cudaRegisterAll_42_tmpxft_00001388_00000000_4_matmult_cpp1_ii_457a4e85(void) __attribute__((__constructor__));
void __device_stub__Z15k_matMult_naivePfS_S_iii(float *__par0, float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T20 *__T25;
char __[256]; *(char**)&__T25 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T25->__par5 - (size_t)__T25) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z15k_matMult_naivePfS_S_iii); (void)cudaLaunch(((char *)__device_stub__Z15k_matMult_naivePfS_S_iii)); };}
void __device_stub__Z16k_matMult_unrollPfS_S_iii(float *__par0, float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T21 *__T28;
char __[256]; *(char**)&__T28 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T28->__par0 - (size_t)__T28) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T28->__par1 - (size_t)__T28) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T28->__par2 - (size_t)__T28) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T28->__par3 - (size_t)__T28) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T28->__par4 - (size_t)__T28) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T28->__par5 - (size_t)__T28) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z16k_matMult_unrollPfS_S_iii); (void)cudaLaunch(((char *)__device_stub__Z16k_matMult_unrollPfS_S_iii)); };}
void __device_stub__Z17k_matMult_unroll2PfS_S_iii(float *__par0, float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T22 *__T211;
char __[256]; *(char**)&__T211 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T211->__par0 - (size_t)__T211) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T211->__par1 - (size_t)__T211) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T211->__par2 - (size_t)__T211) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T211->__par3 - (size_t)__T211) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T211->__par4 - (size_t)__T211) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T211->__par5 - (size_t)__T211) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z17k_matMult_unroll2PfS_S_iii); (void)cudaLaunch(((char *)__device_stub__Z17k_matMult_unroll2PfS_S_iii)); };}
void __device_stub__Z7sgemmNNPKfiS0_iPfiiff(const float *__par0, int __par1, const float *__par2, int __par3, float *__par4, int __par5, int __par6, float __par7, float __par8){auto struct __T23 *__T214;
char __[256]; *(char**)&__T214 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T214->__par0 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T214->__par1 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T214->__par2 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T214->__par3 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T214->__par4 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T214->__par5 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T214->__par6 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T214->__par7 - (size_t)__T214) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T214->__par8 - (size_t)__T214) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z7sgemmNNPKfiS0_iPfiiff); (void)cudaLaunch(((char *)__device_stub__Z7sgemmNNPKfiS0_iPfiiff)); };}
void __device_stub__Z13k_fill_matrixPfiif(float *__par0, int __par1, int __par2, float __par3){auto struct __T24 *__T217;
char __[256]; *(char**)&__T217 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T217->__par0 - (size_t)__T217) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T217->__par1 - (size_t)__T217) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T217->__par2 - (size_t)__T217) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T217->__par3 - (size_t)__T217) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z13k_fill_matrixPfiif); (void)cudaLaunch(((char *)__device_stub__Z13k_fill_matrixPfiif)); };}
# 57 "/tmp/tmpxft_00001388_00000000-1_matmult.cudafe1.stub.c"
static void __sti____cudaRegisterAll_42_tmpxft_00001388_00000000_4_matmult_cpp1_ii_457a4e85(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z13k_fill_matrixPfiif, (char*)"_Z13k_fill_matrixPfiif", "_Z13k_fill_matrixPfiif", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z7sgemmNNPKfiS0_iPfiiff, (char*)"_Z7sgemmNNPKfiS0_iPfiiff", "_Z7sgemmNNPKfiS0_iPfiiff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z17k_matMult_unroll2PfS_S_iii, (char*)"_Z17k_matMult_unroll2PfS_S_iii", "_Z17k_matMult_unroll2PfS_S_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z16k_matMult_unrollPfS_S_iii, (char*)"_Z16k_matMult_unrollPfS_S_iii", "_Z16k_matMult_unrollPfS_S_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z15k_matMult_naivePfS_S_iii, (char*)"_Z15k_matMult_naivePfS_S_iii", "_Z15k_matMult_naivePfS_S_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);}

}
# 494 "matmult.cu" 2

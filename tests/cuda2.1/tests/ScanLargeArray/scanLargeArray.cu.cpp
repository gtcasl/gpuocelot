# 1 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.cpp"
# 1 "scanLargeArray.cu"
# 233 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) {
# 245 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
}
# 152 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 54 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/host_defines.h" 1 3
# 55 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/device_types.h" 1 3
# 46 "/home/normal/temp/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/driver_types.h" 1 3
# 59 "/home/normal/temp/cuda/bin/../include/driver_types.h" 3
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
# 224 "/home/normal/temp/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;


typedef int cudaStream_t;


typedef int cudaEvent_t;
# 44 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/texture_types.h" 1 3
# 54 "/home/normal/temp/cuda/bin/../include/texture_types.h" 3
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
# 45 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/vector_types.h" 1 3
# 54 "/home/normal/temp/cuda/bin/../include/vector_types.h" 3
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
# 262 "/home/normal/temp/cuda/bin/../include/vector_types.h" 3
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
# 328 "/home/normal/temp/cuda/bin/../include/vector_types.h" 3
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
# 419 "/home/normal/temp/cuda/bin/../include/vector_types.h" 3
typedef struct dim3 dim3;


struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};
# 45 "/home/normal/temp/cuda/bin/../include/builtin_types.h" 2 3
# 56 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 79 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 88 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);
# 101 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);
# 116 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h" 3
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
# 70 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 2 3
# 88 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 89 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
# 90 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 91 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 92 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 101 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
# 105 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 116 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 117 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 118 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 119 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 120 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 121 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 122 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 125 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 133 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 134 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
# 135 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 136 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 137 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 138 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 139 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 140 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 148 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 149 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 157 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 158 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 166 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 167 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 168 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 169 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 170 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 178 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 179 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 180 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 181 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 182 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 190 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 191 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 199 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 200 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 208 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
# 209 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 210 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 218 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 219 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 220 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 221 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 229 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 230 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
# 231 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 232 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 233 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 234 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 242 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 243 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 251 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 252 "/home/normal/temp/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 58 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 59 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 60 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 61 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 63 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 64 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 65 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(char)) * 8);
# 70 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 72 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 74 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 75 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 76 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 78 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 79 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 81 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 82 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 83 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 85 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 86 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 88 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 89 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 90 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 92 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 93 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 95 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 96 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 97 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 99 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 100 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 102 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 103 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 104 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 106 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 107 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 109 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 110 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 111 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 113 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 114 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 116 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 117 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 118 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(signed char)) * 8);
# 120 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 121 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 123 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 124 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 125 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned char)) * 8);
# 127 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 128 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 130 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 131 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 132 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 134 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 135 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 138 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 141 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 142 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 145 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 148 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 149 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 152 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 155 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 156 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 159 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 162 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 163 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 166 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 169 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 170 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 173 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(short)) * 8);
# 176 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 177 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 180 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned short)) * 8);
# 183 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 184 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 187 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 190 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 191 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 194 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 197 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 198 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 201 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 204 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 205 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 208 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 211 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 212 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 215 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 218 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 219 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 222 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 225 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 226 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 229 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(int)) * 8);
# 232 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 233 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 236 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(unsigned)) * 8);
# 239 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 240 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 302 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 303 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 304 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 306 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 307 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 309 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 310 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 311 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 313 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 314 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 316 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 317 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 318 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 320 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 321 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 323 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 324 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
{
# 325 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
auto int e = (((int)sizeof(float)) * 8);
# 327 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 328 "/home/normal/temp/cuda/bin/../include/channel_descriptor.h"
}
# 54 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 55 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
{
# 56 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
auto cudaPitchedPtr s;
# 58 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 59 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 60 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 61 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 63 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
return s;
# 64 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
}
# 66 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 67 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
{
# 68 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
auto cudaPos p;
# 70 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 71 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 72 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 74 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
return p;
# 75 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
}
# 77 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 78 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
{
# 79 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
auto cudaExtent e;
# 81 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 82 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 83 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 85 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
return e;
# 86 "/home/normal/temp/cuda/bin/../include/driver_functions.h"
}
# 54 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 55 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 56 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto char1 t; (t.x) = x; return t;
# 57 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 59 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 60 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 61 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uchar1 t; (t.x) = x; return t;
# 62 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 64 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 65 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 66 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto char2 t; (t.x) = x; (t.y) = y; return t;
# 67 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 69 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 70 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 71 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uchar2 t; (t.x) = x; (t.y) = y; return t;
# 72 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 74 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 75 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 76 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 77 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 79 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 80 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 81 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 82 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 84 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 85 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 86 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 87 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 89 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 90 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 91 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 92 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 94 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 95 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 96 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto short1 t; (t.x) = x; return t;
# 97 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 99 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 100 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 101 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ushort1 t; (t.x) = x; return t;
# 102 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 104 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 105 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 106 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto short2 t; (t.x) = x; (t.y) = y; return t;
# 107 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 109 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 110 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 111 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ushort2 t; (t.x) = x; (t.y) = y; return t;
# 112 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 114 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 115 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 116 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 117 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 119 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 120 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 121 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 122 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 124 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 125 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 126 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 127 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 129 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 130 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 131 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 132 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 134 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 135 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 136 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto int1 t; (t.x) = x; return t;
# 137 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 139 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 140 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 141 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uint1 t; (t.x) = x; return t;
# 142 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 144 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 145 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 146 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto int2 t; (t.x) = x; (t.y) = y; return t;
# 147 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 149 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 150 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 151 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uint2 t; (t.x) = x; (t.y) = y; return t;
# 152 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 154 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 155 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 156 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 157 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 159 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 160 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 161 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 162 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 164 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 165 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 166 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 167 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 169 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 170 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 171 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 172 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 174 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 175 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 176 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto long1 t; (t.x) = x; return t;
# 177 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 179 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 180 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 181 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ulong1 t; (t.x) = x; return t;
# 182 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 184 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 185 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 186 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto long2 t; (t.x) = x; (t.y) = y; return t;
# 187 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 189 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 190 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 191 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ulong2 t; (t.x) = x; (t.y) = y; return t;
# 192 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 218 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 219 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 220 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto float1 t; (t.x) = x; return t;
# 221 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 223 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 224 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 225 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto float2 t; (t.x) = x; (t.y) = y; return t;
# 226 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 228 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 229 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 230 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 231 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 233 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 234 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 235 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 236 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 238 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 239 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 240 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto longlong1 t; (t.x) = x; return t;
# 241 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 243 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 244 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 245 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ulonglong1 t; (t.x) = x; return t;
# 246 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 248 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 249 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 250 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto longlong2 t; (t.x) = x; (t.y) = y; return t;
# 251 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 253 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 254 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 255 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 256 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 258 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 259 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 260 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto double1 t; (t.x) = x; return t;
# 261 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
}
# 263 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 264 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
{
# 265 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
auto double2 t; (t.x) = x; (t.y) = y; return t;
# 266 "/home/normal/temp/cuda/bin/../include/vector_functions.h"
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
extern "C" { extern inline __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
# 43 "/usr/include/string.h" 3
extern "C" { extern inline void *memmove(void *, const void *, size_t) throw() __attribute__((__always_inline__)); }
# 51 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 59 "/usr/include/string.h" 3
extern "C" { extern inline __attribute__((__weak__)) void *memset(void *, int, size_t) throw() __attribute__((__always_inline__)); }
# 62 "/usr/include/string.h" 3
extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));
# 66 "/usr/include/string.h" 3
extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 73 "/usr/include/string.h" 3
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__));
# 77 "/usr/include/string.h" 3
extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 84 "/usr/include/string.h" 3
extern "C" { extern inline char *strcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)); }
# 87 "/usr/include/string.h" 3
extern "C" { extern inline char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
# 92 "/usr/include/string.h" 3
extern "C" { extern inline char *strcat(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)); }
# 95 "/usr/include/string.h" 3
extern "C" { extern inline char *strncat(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
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
extern "C" { extern inline void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
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
extern "C" { extern inline void bcopy(const void *, void *, size_t) throw() __attribute__((__always_inline__)); }
# 302 "/usr/include/string.h" 3
extern "C" { extern inline void bzero(void *, size_t) throw() __attribute__((__always_inline__)); }
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
extern "C" { extern inline char *stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)); }
# 375 "/usr/include/string.h" 3
extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();
# 378 "/usr/include/string.h" 3
extern "C" { extern inline char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
# 383 "/usr/include/string.h" 3
extern "C" char *strfry(char *) throw();
# 386 "/usr/include/string.h" 3
extern "C" void *memfrob(void *, size_t) throw();
# 393 "/usr/include/string.h" 3
extern "C" char *basename(const char *) throw();
# 23 "/usr/include/bits/string3.h" 3
extern "C" void __warn_memset_zero_len();
# 49 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__always_inline__)) void *memcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()
# 51 "/usr/include/bits/string3.h" 3
{
# 52 "/usr/include/bits/string3.h" 3
return __builtin___memcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
# 53 "/usr/include/bits/string3.h" 3
} }
# 56 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) void *memmove(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()
# 58 "/usr/include/bits/string3.h" 3
{
# 59 "/usr/include/bits/string3.h" 3
return __builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
# 60 "/usr/include/bits/string3.h" 3
} }
# 64 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) void *mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()
# 66 "/usr/include/bits/string3.h" 3
{
# 67 "/usr/include/bits/string3.h" 3
return __builtin___mempcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
# 68 "/usr/include/bits/string3.h" 3
} }
# 78 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__always_inline__)) void *memset(void *__dest, int __ch, size_t __len) throw()
# 79 "/usr/include/bits/string3.h" 3
{
# 80 "/usr/include/bits/string3.h" 3
if ((__builtin_constant_p(__len)) && (__len == (0)))
# 81 "/usr/include/bits/string3.h" 3
{
# 82 "/usr/include/bits/string3.h" 3
__warn_memset_zero_len();
# 83 "/usr/include/bits/string3.h" 3
return __dest;
# 84 "/usr/include/bits/string3.h" 3
}
# 85 "/usr/include/bits/string3.h" 3
return __builtin___memset_chk(__dest, __ch, __len, __builtin_object_size(__dest, 0));
# 86 "/usr/include/bits/string3.h" 3
} }
# 90 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) void bcopy(const void *__restrict__ __src, void *__restrict__ __dest, size_t __len) throw()
# 92 "/usr/include/bits/string3.h" 3
{
# 93 "/usr/include/bits/string3.h" 3
(void)__builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
# 94 "/usr/include/bits/string3.h" 3
} }
# 97 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) void bzero(void *__dest, size_t __len) throw()
# 98 "/usr/include/bits/string3.h" 3
{
# 99 "/usr/include/bits/string3.h" 3
(void)__builtin___memset_chk(__dest, '\000', __len, __builtin_object_size(__dest, 0));
# 100 "/usr/include/bits/string3.h" 3
} }
# 104 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *strcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 105 "/usr/include/bits/string3.h" 3
{
# 106 "/usr/include/bits/string3.h" 3
return __builtin___strcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
# 107 "/usr/include/bits/string3.h" 3
} }
# 111 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 112 "/usr/include/bits/string3.h" 3
{
# 113 "/usr/include/bits/string3.h" 3
return __builtin___stpcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
# 114 "/usr/include/bits/string3.h" 3
} }
# 119 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *strncpy(char *__restrict__ __dest, const char *__restrict__ __src, size_t __len) throw()
# 121 "/usr/include/bits/string3.h" 3
{
# 122 "/usr/include/bits/string3.h" 3
return __builtin___strncpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
# 123 "/usr/include/bits/string3.h" 3
} }
# 126 "/usr/include/bits/string3.h" 3
extern "C" char *__stpncpy_chk(char *, const char *, size_t, size_t) throw();
# 128 "/usr/include/bits/string3.h" 3
extern "C" char *__stpncpy_alias(char *, const char *, size_t) throw() __asm__("stpncpy");
# 133 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *stpncpy(char *__dest, const char *__src, size_t __n) throw()
# 134 "/usr/include/bits/string3.h" 3
{
# 135 "/usr/include/bits/string3.h" 3
if ((__builtin_object_size(__dest, 2 > 1) != ((size_t)(-1))) && ((!(__builtin_constant_p(__n))) || (__n <= __builtin_object_size(__dest, 2 > 1)))) {
# 137 "/usr/include/bits/string3.h" 3
return __stpncpy_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1)); }
# 138 "/usr/include/bits/string3.h" 3
return __stpncpy_alias(__dest, __src, __n);
# 139 "/usr/include/bits/string3.h" 3
} }
# 143 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *strcat(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 144 "/usr/include/bits/string3.h" 3
{
# 145 "/usr/include/bits/string3.h" 3
return __builtin___strcat_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
# 146 "/usr/include/bits/string3.h" 3
} }
# 150 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *strncat(char *__restrict__ __dest, const char *__restrict__ __src, size_t __len) throw()
# 152 "/usr/include/bits/string3.h" 3
{
# 153 "/usr/include/bits/string3.h" 3
return __builtin___strncat_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
# 154 "/usr/include/bits/string3.h" 3
} }
# 56 "/home/normal/temp/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();
# 59 "/home/normal/temp/cuda/bin/../include/common_functions.h"
extern "C" { extern inline __attribute__((__weak__)) void *memset(void *, int, size_t) throw() __attribute__((__always_inline__)); }
# 62 "/home/normal/temp/cuda/bin/../include/common_functions.h"
extern "C" { extern inline __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw() __attribute__((__always_inline__)); }
# 65 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
# 67 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));
# 69 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 71 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));
# 73 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));
# 76 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int min(int, int);
# 78 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);
# 80 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fminf(float, float) throw();
# 82 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmin(double, double) throw();
# 85 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int max(int, int);
# 87 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);
# 89 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();
# 91 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmax(double, double) throw();
# 94 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sin(double) throw();
# 96 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinf(float) throw();
# 99 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cos(double) throw();
# 101 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cosf(float) throw();
# 104 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();
# 106 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 109 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tan(double) throw();
# 111 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanf(float) throw();
# 114 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sqrt(double) throw();
# 116 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sqrtf(float) throw();
# 119 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rsqrt(double);
# 121 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rsqrtf(float);
# 124 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp2(double) throw();
# 126 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp2f(float) throw();
# 129 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp10(double) throw();
# 131 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float exp10f(float) throw();
# 134 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double expm1(double) throw();
# 136 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expm1f(float) throw();
# 139 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log2(double) throw();
# 141 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 144 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log10(double) throw();
# 146 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log10f(float) throw();
# 149 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log(double) throw();
# 151 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logf(float) throw();
# 154 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double log1p(double) throw();
# 156 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float log1pf(float) throw();
# 159 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));
# 161 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));
# 164 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double exp(double) throw();
# 166 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float expf(float) throw();
# 169 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cosh(double) throw();
# 171 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float coshf(float) throw();
# 174 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double sinh(double) throw();
# 176 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float sinhf(float) throw();
# 179 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tanh(double) throw();
# 181 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tanhf(float) throw();
# 184 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acosh(double) throw();
# 186 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acoshf(float) throw();
# 189 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asinh(double) throw();
# 191 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinhf(float) throw();
# 194 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atanh(double) throw();
# 196 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanhf(float) throw();
# 199 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();
# 201 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();
# 204 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double logb(double) throw();
# 206 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float logbf(float) throw();
# 209 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogb(double) throw();
# 211 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int ilogbf(float) throw();
# 214 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();
# 216 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();
# 219 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();
# 221 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();
# 224 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();
# 226 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();
# 229 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));
# 231 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));
# 234 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lround(double) throw();
# 236 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lroundf(float) throw();
# 239 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llround(double) throw();
# 241 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llroundf(float) throw();
# 244 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double rint(double) throw();
# 246 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float rintf(float) throw();
# 249 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrint(double) throw();
# 251 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long lrintf(float) throw();
# 254 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrint(double) throw();
# 256 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) long long llrintf(float) throw();
# 259 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nearbyint(double) throw();
# 261 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();
# 264 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));
# 266 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));
# 269 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));
# 271 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));
# 274 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fdim(double, double) throw();
# 276 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();
# 279 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan2(double, double) throw();
# 281 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();
# 284 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double atan(double) throw();
# 286 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float atanf(float) throw();
# 289 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double asin(double) throw();
# 291 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float asinf(float) throw();
# 294 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double acos(double) throw();
# 296 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float acosf(float) throw();
# 299 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double hypot(double, double) throw();
# 301 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();
# 304 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double cbrt(double) throw();
# 306 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float cbrtf(float) throw();
# 309 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double pow(double, double) throw();
# 311 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float powf(float, float) throw();
# 314 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double modf(double, double *) throw();
# 316 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float modff(float, float *) throw();
# 319 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fmod(double, double) throw();
# 321 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();
# 324 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remainder(double, double) throw();
# 326 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();
# 329 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();
# 331 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();
# 334 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erf(double) throw();
# 336 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erff(float) throw();
# 339 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double erfc(double) throw();
# 341 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float erfcf(float) throw();
# 344 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double lgamma(double) throw();
# 346 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float lgammaf(float) throw();
# 349 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double tgamma(double) throw();
# 351 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float tgammaf(float) throw();
# 354 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));
# 356 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));
# 359 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));
# 361 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));
# 364 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));
# 366 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));
# 369 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));
# 371 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));
# 374 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));
# 376 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 390 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 392 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 394 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__)); }
# 399 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__)); }
# 402 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();
# 404 "/home/normal/temp/cuda/bin/../include/math_functions.h"
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
extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__)); }
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
extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__)); }
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
extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__)); }
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
# 36 "/usr/include/bits/mathinline.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__const__)) int __signbitf(float __x) throw()
# 37 "/usr/include/bits/mathinline.h" 3
{
# 38 "/usr/include/bits/mathinline.h" 3
auto union { float __f; int __i; } __u = {__f: __x};
# 39 "/usr/include/bits/mathinline.h" 3
return (__u.__i) < 0;
# 40 "/usr/include/bits/mathinline.h" 3
} }
# 42 "/usr/include/bits/mathinline.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__const__)) int __signbit(double __x) throw()
# 43 "/usr/include/bits/mathinline.h" 3
{
# 44 "/usr/include/bits/mathinline.h" 3
auto union { double __d; int __i[2]; } __u = {__d: __x};
# 45 "/usr/include/bits/mathinline.h" 3
return ((__u.__i)[1]) < 0;
# 46 "/usr/include/bits/mathinline.h" 3
} }
# 48 "/usr/include/bits/mathinline.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__const__)) int __signbitl(long double __x) throw()
# 49 "/usr/include/bits/mathinline.h" 3
{
# 50 "/usr/include/bits/mathinline.h" 3
auto union { long double __l; int __i[3]; } __u = {__l: __x};
# 51 "/usr/include/bits/mathinline.h" 3
return (((__u.__i)[2]) & 32768) != 0;
# 52 "/usr/include/bits/mathinline.h" 3
} }
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
extern "C" { extern inline double atof(const char *) throw() __attribute__((__pure__)); }
# 148 "/usr/include/stdlib.h" 3
extern "C" { extern inline int atoi(const char *) throw() __attribute__((__pure__)); }
# 151 "/usr/include/stdlib.h" 3
extern "C" { extern inline long atol(const char *) throw() __attribute__((__pure__)); }
# 158 "/usr/include/stdlib.h" 3
extern "C" { extern inline long long atoll(const char *) throw() __attribute__((__pure__)); }
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
# 279 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) double atof(const char *__nptr) throw()
# 280 "/usr/include/stdlib.h" 3
{
# 281 "/usr/include/stdlib.h" 3
return strtod(__nptr, (char **)__null);
# 282 "/usr/include/stdlib.h" 3
} }
# 284 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) int atoi(const char *__nptr) throw()
# 285 "/usr/include/stdlib.h" 3
{
# 286 "/usr/include/stdlib.h" 3
return (int)strtol(__nptr, (char **)__null, 10);
# 287 "/usr/include/stdlib.h" 3
} }
# 289 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) long atol(const char *__nptr) throw()
# 290 "/usr/include/stdlib.h" 3
{
# 291 "/usr/include/stdlib.h" 3
return strtol(__nptr, (char **)__null, 10);
# 292 "/usr/include/stdlib.h" 3
} }
# 298 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) long long atoll(const char *__nptr) throw()
# 299 "/usr/include/stdlib.h" 3
{
# 300 "/usr/include/stdlib.h" 3
return strtoll(__nptr, (char **)__null, 10);
# 301 "/usr/include/stdlib.h" 3
} }
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
extern "C" { extern inline unsigned gnu_dev_major(unsigned long long) throw(); }
# 34 "/usr/include/sys/sysmacros.h" 3
extern "C" { extern inline unsigned gnu_dev_minor(unsigned long long) throw(); }
# 37 "/usr/include/sys/sysmacros.h" 3
extern "C" { extern inline unsigned long long gnu_dev_makedev(unsigned, unsigned) throw(); }
# 43 "/usr/include/sys/sysmacros.h" 3
extern "C" { inline unsigned gnu_dev_major(unsigned long long __dev) throw()
# 44 "/usr/include/sys/sysmacros.h" 3
{
# 45 "/usr/include/sys/sysmacros.h" 3
return ((__dev >> 8) & (4095)) | (((unsigned)(__dev >> 32)) & (~4095));
# 46 "/usr/include/sys/sysmacros.h" 3
} }
# 49 "/usr/include/sys/sysmacros.h" 3
extern "C" { inline unsigned gnu_dev_minor(unsigned long long __dev) throw()
# 50 "/usr/include/sys/sysmacros.h" 3
{
# 51 "/usr/include/sys/sysmacros.h" 3
return (__dev & (255)) | (((unsigned)(__dev >> 12)) & (~255));
# 52 "/usr/include/sys/sysmacros.h" 3
} }
# 55 "/usr/include/sys/sysmacros.h" 3
extern "C" { inline unsigned long long gnu_dev_makedev(unsigned __major, unsigned __minor) throw()
# 56 "/usr/include/sys/sysmacros.h" 3
{
# 57 "/usr/include/sys/sysmacros.h" 3
return (((__minor & (255)) | ((__major & (4095)) << 8)) | (((unsigned long long)(__minor & (~255))) << 12)) | (((unsigned long long)(__major & (~4095))) << 32);
# 60 "/usr/include/sys/sysmacros.h" 3
} }
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
extern "C" { extern inline char *realpath(const char *__restrict__, char *__restrict__) throw() __attribute__((__always_inline__)); }
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
extern "C" { extern inline int wctomb(char *, wchar_t) throw() __attribute__((__always_inline__)); }
# 798 "/usr/include/stdlib.h" 3
extern "C" { extern inline size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
# 801 "/usr/include/stdlib.h" 3
extern "C" { extern inline size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw() __attribute__((__always_inline__)); }
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
extern "C" { extern inline int ptsname_r(int, char *, size_t) throw() __attribute__((__always_inline__)); }
# 868 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 875 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 24 "/usr/include/bits/stdlib.h" 3
extern "C" char *__realpath_chk(const char *__restrict__, char *__restrict__, size_t) throw();
# 27 "/usr/include/bits/stdlib.h" 3
extern "C" char *__realpath_alias(const char *__restrict__, char *__restrict__) throw() __asm__("realpath");
# 30 "/usr/include/bits/stdlib.h" 3
extern "C" char *__realpath_chk_warn(const char *__restrict__, char *__restrict__, size_t) throw() __asm__("__realpath_chk");
# 38 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *realpath(const char *__restrict__ __name, char *__restrict__ __resolved) throw()
# 39 "/usr/include/bits/stdlib.h" 3
{
# 40 "/usr/include/bits/stdlib.h" 3
if (__builtin_object_size(__resolved, 2 > 1) != ((size_t)(-1)))
# 41 "/usr/include/bits/stdlib.h" 3
{
# 43 "/usr/include/bits/stdlib.h" 3
if (__builtin_object_size(__resolved, 2 > 1) < (4096)) {
# 44 "/usr/include/bits/stdlib.h" 3
return __realpath_chk_warn(__name, __resolved, __builtin_object_size(__resolved, 2 > 1)); }
# 46 "/usr/include/bits/stdlib.h" 3
return __realpath_chk(__name, __resolved, __builtin_object_size(__resolved, 2 > 1));
# 47 "/usr/include/bits/stdlib.h" 3
}
# 49 "/usr/include/bits/stdlib.h" 3
return __realpath_alias(__name, __resolved);
# 50 "/usr/include/bits/stdlib.h" 3
} }
# 53 "/usr/include/bits/stdlib.h" 3
extern "C" int __ptsname_r_chk(int, char *, size_t, size_t) throw();
# 55 "/usr/include/bits/stdlib.h" 3
extern "C" int __ptsname_r_alias(int, char *, size_t) throw() __asm__("ptsname_r");
# 58 "/usr/include/bits/stdlib.h" 3
extern "C" int __ptsname_r_chk_warn(int, char *, size_t, size_t) throw() __asm__("__ptsname_r_chk");
# 65 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) int ptsname_r(int __fd, char *__buf, size_t __buflen) throw()
# 66 "/usr/include/bits/stdlib.h" 3
{
# 67 "/usr/include/bits/stdlib.h" 3
if (__builtin_object_size(__buf, 2 > 1) != ((size_t)(-1)))
# 68 "/usr/include/bits/stdlib.h" 3
{
# 69 "/usr/include/bits/stdlib.h" 3
if (!(__builtin_constant_p(__buflen))) {
# 70 "/usr/include/bits/stdlib.h" 3
return __ptsname_r_chk(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1)); }
# 71 "/usr/include/bits/stdlib.h" 3
if (__buflen > __builtin_object_size(__buf, 2 > 1)) {
# 72 "/usr/include/bits/stdlib.h" 3
return __ptsname_r_chk_warn(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1)); }
# 73 "/usr/include/bits/stdlib.h" 3
}
# 74 "/usr/include/bits/stdlib.h" 3
return __ptsname_r_alias(__fd, __buf, __buflen);
# 75 "/usr/include/bits/stdlib.h" 3
} }
# 78 "/usr/include/bits/stdlib.h" 3
extern "C" int __wctomb_chk(char *, wchar_t, size_t) throw();
# 80 "/usr/include/bits/stdlib.h" 3
extern "C" int __wctomb_alias(char *, wchar_t) throw() __asm__("wctomb");
# 84 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) int wctomb(char *__s, wchar_t __wchar) throw()
# 85 "/usr/include/bits/stdlib.h" 3
{
# 93 "/usr/include/bits/stdlib.h" 3
if ((__builtin_object_size(__s, 2 > 1) != ((size_t)(-1))) && ((16) > __builtin_object_size(__s, 2 > 1))) {
# 94 "/usr/include/bits/stdlib.h" 3
return __wctomb_chk(__s, __wchar, __builtin_object_size(__s, 2 > 1)); }
# 95 "/usr/include/bits/stdlib.h" 3
return __wctomb_alias(__s, __wchar);
# 96 "/usr/include/bits/stdlib.h" 3
} }
# 99 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __mbstowcs_chk(wchar_t *__restrict__, const char *__restrict__, size_t, size_t) throw();
# 102 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __mbstowcs_alias(wchar_t *__restrict__, const char *__restrict__, size_t) throw() __asm__("mbstowcs");
# 106 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __mbstowcs_chk_warn(wchar_t *__restrict__, const char *__restrict__, size_t, size_t) throw() __asm__("__mbstowcs_chk");
# 114 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) size_t mbstowcs(wchar_t *__restrict__ __dst, const char *__restrict__ __src, size_t __len) throw()
# 116 "/usr/include/bits/stdlib.h" 3
{
# 117 "/usr/include/bits/stdlib.h" 3
if (__builtin_object_size(__dst, 2 > 1) != ((size_t)(-1)))
# 118 "/usr/include/bits/stdlib.h" 3
{
# 119 "/usr/include/bits/stdlib.h" 3
if (!(__builtin_constant_p(__len))) {
# 120 "/usr/include/bits/stdlib.h" 3
return __mbstowcs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t)); }
# 123 "/usr/include/bits/stdlib.h" 3
if (__len > (__builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t))) {
# 124 "/usr/include/bits/stdlib.h" 3
return __mbstowcs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t)); }
# 126 "/usr/include/bits/stdlib.h" 3
}
# 127 "/usr/include/bits/stdlib.h" 3
return __mbstowcs_alias(__dst, __src, __len);
# 128 "/usr/include/bits/stdlib.h" 3
} }
# 131 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __wcstombs_chk(char *__restrict__, const wchar_t *__restrict__, size_t, size_t) throw();
# 134 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __wcstombs_alias(char *__restrict__, const wchar_t *__restrict__, size_t) throw() __asm__("wcstombs");
# 138 "/usr/include/bits/stdlib.h" 3
extern "C" size_t __wcstombs_chk_warn(char *__restrict__, const wchar_t *__restrict__, size_t, size_t) throw() __asm__("__wcstombs_chk");
# 145 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) size_t wcstombs(char *__restrict__ __dst, const wchar_t *__restrict__ __src, size_t __len) throw()
# 147 "/usr/include/bits/stdlib.h" 3
{
# 148 "/usr/include/bits/stdlib.h" 3
if (__builtin_object_size(__dst, 2 > 1) != ((size_t)(-1)))
# 149 "/usr/include/bits/stdlib.h" 3
{
# 150 "/usr/include/bits/stdlib.h" 3
if (!(__builtin_constant_p(__len))) {
# 151 "/usr/include/bits/stdlib.h" 3
return __wcstombs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1)); }
# 152 "/usr/include/bits/stdlib.h" 3
if (__len > __builtin_object_size(__dst, 2 > 1)) {
# 153 "/usr/include/bits/stdlib.h" 3
return __wcstombs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1)); }
# 154 "/usr/include/bits/stdlib.h" 3
}
# 155 "/usr/include/bits/stdlib.h" 3
return __wcstombs_alias(__dst, __src, __len);
# 156 "/usr/include/bits/stdlib.h" 3
} }
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
# 424 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__)); }
# 426 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));
# 428 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 438 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 463 "/home/normal/temp/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 465 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 466 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 468 "/home/normal/temp/cuda/bin/../include/math_functions.h"
namespace std {
# 470 "/home/normal/temp/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 471 "/home/normal/temp/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 472 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 474 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::abs;
# 475 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::fabs;
# 476 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::ceil;
# 477 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::floor;
# 478 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 479 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::pow;
# 480 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::log;
# 481 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::log10;
# 482 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::fmod;
# 483 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::modf;
# 484 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::exp;
# 485 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::frexp;
# 486 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 487 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::asin;
# 488 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::sin;
# 489 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::sinh;
# 490 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::acos;
# 491 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::cos;
# 492 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::cosh;
# 493 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::atan;
# 494 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::atan2;
# 495 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::tan;
# 496 "/home/normal/temp/cuda/bin/../include/math_functions.h"
using std::tanh;
# 550 "/home/normal/temp/cuda/bin/../include/math_functions.h"
namespace std {
# 553 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 554 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 555 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 556 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 557 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 558 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 559 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 560 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 561 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 562 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 563 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 564 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 565 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 566 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 567 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 568 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 569 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 570 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 571 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 572 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 573 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 574 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 575 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 576 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 577 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 578 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 579 "/home/normal/temp/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 582 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 585 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 586 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 587 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return logbf(a);
# 588 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 590 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 591 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 592 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 593 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 595 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 596 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 597 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 598 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 600 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 601 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 602 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 603 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 605 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 606 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 607 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 608 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 610 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 611 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 612 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 613 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 615 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 616 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 617 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 618 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 620 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 621 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 622 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return log2f(a);
# 623 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 625 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 626 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 627 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 628 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 630 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 631 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 632 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 633 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 635 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 636 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 637 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 638 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 640 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 641 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 642 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 643 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 645 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 646 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 647 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 648 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 650 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 651 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 652 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 653 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 655 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 656 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 657 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 658 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 660 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 661 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 662 "/home/normal/temp/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 663 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 665 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 666 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 667 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return erff(a);
# 668 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 670 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 671 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 672 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 673 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 675 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 676 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 677 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 678 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 680 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 681 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 682 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 683 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 685 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 686 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 687 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 688 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 690 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 691 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 692 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 693 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 695 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 696 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 697 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 698 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 700 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 701 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 702 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 703 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 705 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 706 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 707 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 708 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 710 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 711 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 712 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 713 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 715 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 716 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 717 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return roundf(a);
# 718 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 720 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 721 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 722 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 723 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 725 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 726 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 727 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 728 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 730 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 731 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 732 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return truncf(a);
# 733 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 735 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 736 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 737 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return rintf(a);
# 738 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 740 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 741 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 742 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 743 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 745 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 746 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 747 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 748 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 750 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 751 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 752 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 753 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 755 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 756 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 757 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 758 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 760 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 761 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 762 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 763 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 765 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 766 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 767 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 768 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 770 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 771 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 772 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 773 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 775 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 776 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 777 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 778 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 780 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 781 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 782 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 783 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 785 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 786 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 787 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 788 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 790 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 791 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 792 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 793 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 795 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 796 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 797 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 798 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 800 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 801 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 802 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 803 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 805 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 806 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 807 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 808 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 810 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 811 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 812 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 813 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 815 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 816 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 817 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 818 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 820 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 821 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 822 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 823 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 825 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 826 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 827 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 828 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 830 "/home/normal/temp/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 831 "/home/normal/temp/cuda/bin/../include/math_functions.h"
{
# 832 "/home/normal/temp/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 833 "/home/normal/temp/cuda/bin/../include/math_functions.h"
}
# 59 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode = cudaReadModeElementType>
# 60 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 62 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 63 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 64 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 65 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
{
# 66 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->normalized) = norm;
# 67 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->filterMode) = fMode;
# 68 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[0]) = aMode;
# 69 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[1]) = aMode;
# 70 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[2]) = aMode;
# 71 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->channelDesc) = cudaCreateChannelDesc< T> ();
# 72 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
}
# 74 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 75 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 76 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 77 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
desc)
# 78 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
{
# 79 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->normalized) = norm;
# 80 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->filterMode) = fMode;
# 81 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[0]) = aMode;
# 82 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[1]) = aMode;
# 83 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
((this->addressMode)[2]) = aMode;
# 84 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
(this->channelDesc) = desc;
# 85 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
}
# 86 "/home/normal/temp/cuda/bin/../include/cuda_texture_types.h"
};
# 77 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 78 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 79 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 80 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset)
# 82 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 83 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 84 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 94 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 95 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 96 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 97 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 98 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 99 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 101 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 102 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 103 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 105 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 106 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 107 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 108 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 109 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 110 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 111 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 113 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 114 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 115 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 117 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 118 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 119 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 120 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 121 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 122 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 123 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
stream)
# 125 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 126 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 127 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 129 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 130 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 131 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 132 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 133 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 134 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 135 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 136 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
stream)
# 138 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 139 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 140 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 148 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 149 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 150 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 151 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 152 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 153 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 155 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 156 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 157 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 159 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 160 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 161 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 162 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 163 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 164 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 165 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 167 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 168 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 169 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 171 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 172 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 173 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 174 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 175 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 176 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 177 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
stream)
# 179 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 180 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 181 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 183 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 184 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 185 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 186 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 187 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 188 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, cudaMemcpyKind
# 189 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
kind, cudaStream_t
# 190 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
stream)
# 192 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 193 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 194 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 196 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 197 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 198 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol)
# 200 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 201 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 202 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 204 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 205 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 206 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 207 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol)
# 209 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 210 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 211 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 219 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 220 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
size, char *
# 221 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol)
# 223 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 224 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 225 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 228 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 229 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 230 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol)
# 232 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 233 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 234 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 242 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 243 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 244 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 245 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 246 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 247 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 248 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 250 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 251 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, (&desc), size);
# 252 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 254 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 255 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 256 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 257 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 258 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 259 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 261 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 262 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 263 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 265 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 266 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 267 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 268 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 269 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
desc)
# 271 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 272 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, (&desc));
# 273 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 276 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 277 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 278 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
array)
# 280 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 281 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
auto cudaChannelFormatDesc desc;
# 282 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
auto cudaError_t err = cudaGetChannelDesc(&desc, array);
# 284 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
# 285 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 293 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 294 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 295 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex)
# 297 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 298 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 299 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 307 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 308 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 309 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 310 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
tex)
# 312 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 313 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 314 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
}
# 322 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 323 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 324 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
symbol)
# 326 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
{
# 327 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)symbol);
# 328 "/home/normal/temp/cuda/bin/../include/cuda_runtime.h"
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
extern "C" { extern inline int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)); }
# 352 "/usr/include/stdio.h" 3
extern "C" { extern inline int vprintf(const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)); }
# 354 "/usr/include/stdio.h" 3
extern "C" { extern inline int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)); }
# 361 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();
# 365 "/usr/include/stdio.h" 3
extern "C" { extern inline int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)); }
# 374 "/usr/include/stdio.h" 3
extern "C" { extern inline int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)); }
# 377 "/usr/include/stdio.h" 3
extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 380 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 390 "/usr/include/stdio.h" 3
extern "C" { extern inline int vdprintf(int, const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)); }
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
extern "C" { extern inline int getchar(); }
# 528 "/usr/include/stdio.h" 3
extern "C" { extern inline int getc_unlocked(FILE *); }
# 529 "/usr/include/stdio.h" 3
extern "C" { extern inline int getchar_unlocked(); }
# 539 "/usr/include/stdio.h" 3
extern "C" { extern inline int fgetc_unlocked(FILE *); }
# 551 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
# 552 "/usr/include/stdio.h" 3
extern "C" int putc(int, FILE *);
# 558 "/usr/include/stdio.h" 3
extern "C" { extern inline int putchar(int); }
# 572 "/usr/include/stdio.h" 3
extern "C" { extern inline int fputc_unlocked(int, FILE *); }
# 580 "/usr/include/stdio.h" 3
extern "C" { extern inline int putc_unlocked(int, FILE *); }
# 581 "/usr/include/stdio.h" 3
extern "C" { extern inline int putchar_unlocked(int); }
# 588 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);
# 591 "/usr/include/stdio.h" 3
extern "C" int putw(int, FILE *);
# 600 "/usr/include/stdio.h" 3
extern "C" { extern inline char *fgets(char *__restrict__, int, FILE *__restrict__) __attribute__((__always_inline__)); }
# 608 "/usr/include/stdio.h" 3
extern "C" { extern inline char *gets(char *) __attribute__((__always_inline__)); }
# 618 "/usr/include/stdio.h" 3
extern "C" { extern inline char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__) __attribute__((__always_inline__)); }
# 634 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 637 "/usr/include/stdio.h" 3
extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 647 "/usr/include/stdio.h" 3
extern "C" { extern inline __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__); }
# 658 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 664 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 671 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 678 "/usr/include/stdio.h" 3
extern "C" { extern inline size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__) __attribute__((__always_inline__)); }
# 684 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 695 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 706 "/usr/include/stdio.h" 3
extern "C" { extern inline size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__) __attribute__((__always_inline__)); }
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
extern "C" { extern inline int feof_unlocked(FILE *) throw(); }
# 806 "/usr/include/stdio.h" 3
extern "C" { extern inline int ferror_unlocked(FILE *) throw(); }
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
extern "C" { extern inline int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)); }
# 882 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();
# 886 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE *) throw();
# 889 "/usr/include/stdio.h" 3
extern "C" void funlockfile(FILE *) throw();
# 45 "/usr/include/bits/stdio.h" 3
extern "C" { inline int getchar()
# 46 "/usr/include/bits/stdio.h" 3
{
# 47 "/usr/include/bits/stdio.h" 3
return _IO_getc(stdin);
# 48 "/usr/include/bits/stdio.h" 3
} }
# 54 "/usr/include/bits/stdio.h" 3
extern "C" { inline int fgetc_unlocked(FILE *__fp)
# 55 "/usr/include/bits/stdio.h" 3
{
# 56 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
# 57 "/usr/include/bits/stdio.h" 3
} }
# 64 "/usr/include/bits/stdio.h" 3
extern "C" { inline int getc_unlocked(FILE *__fp)
# 65 "/usr/include/bits/stdio.h" 3
{
# 66 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
# 67 "/usr/include/bits/stdio.h" 3
} }
# 71 "/usr/include/bits/stdio.h" 3
extern "C" { inline int getchar_unlocked()
# 72 "/usr/include/bits/stdio.h" 3
{
# 73 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((stdin->_IO_read_ptr) >= (stdin->_IO_read_end), 0)) ? __uflow(stdin) : (*((unsigned char *)((stdin->_IO_read_ptr)++)));
# 74 "/usr/include/bits/stdio.h" 3
} }
# 80 "/usr/include/bits/stdio.h" 3
extern "C" { inline int putchar(int __c)
# 81 "/usr/include/bits/stdio.h" 3
{
# 82 "/usr/include/bits/stdio.h" 3
return _IO_putc(__c, stdout);
# 83 "/usr/include/bits/stdio.h" 3
} }
# 89 "/usr/include/bits/stdio.h" 3
extern "C" { inline int fputc_unlocked(int __c, FILE *__stream)
# 90 "/usr/include/bits/stdio.h" 3
{
# 91 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
# 92 "/usr/include/bits/stdio.h" 3
} }
# 99 "/usr/include/bits/stdio.h" 3
extern "C" { inline int putc_unlocked(int __c, FILE *__stream)
# 100 "/usr/include/bits/stdio.h" 3
{
# 101 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
# 102 "/usr/include/bits/stdio.h" 3
} }
# 106 "/usr/include/bits/stdio.h" 3
extern "C" { inline int putchar_unlocked(int __c)
# 107 "/usr/include/bits/stdio.h" 3
{
# 108 "/usr/include/bits/stdio.h" 3
return (__builtin_expect((stdout->_IO_write_ptr) >= (stdout->_IO_write_end), 0)) ? __overflow(stdout, (unsigned char)__c) : ((unsigned char)((*((stdout->_IO_write_ptr)++)) = __c));
# 109 "/usr/include/bits/stdio.h" 3
} }
# 116 "/usr/include/bits/stdio.h" 3
extern "C" { inline __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream)
# 117 "/usr/include/bits/stdio.h" 3
{
# 118 "/usr/include/bits/stdio.h" 3
return __getdelim(__lineptr, __n, '\n', __stream);
# 119 "/usr/include/bits/stdio.h" 3
} }
# 126 "/usr/include/bits/stdio.h" 3
extern "C" { inline int feof_unlocked(FILE *__stream) throw()
# 127 "/usr/include/bits/stdio.h" 3
{
# 128 "/usr/include/bits/stdio.h" 3
return ((__stream->_flags) & 16) != 0;
# 129 "/usr/include/bits/stdio.h" 3
} }
# 133 "/usr/include/bits/stdio.h" 3
extern "C" { inline int ferror_unlocked(FILE *__stream) throw()
# 134 "/usr/include/bits/stdio.h" 3
{
# 135 "/usr/include/bits/stdio.h" 3
return ((__stream->_flags) & 32) != 0;
# 136 "/usr/include/bits/stdio.h" 3
} }
# 24 "/usr/include/bits/stdio2.h" 3
extern "C" int __sprintf_chk(char *__restrict__, int, size_t, const char *__restrict__, ...) throw();
# 26 "/usr/include/bits/stdio2.h" 3
extern "C" int __vsprintf_chk(char *__restrict__, int, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 44 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vsprintf(char *__restrict__ __s, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()
# 46 "/usr/include/bits/stdio2.h" 3
{
# 47 "/usr/include/bits/stdio2.h" 3
return __builtin___vsprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);
# 49 "/usr/include/bits/stdio2.h" 3
} }
# 53 "/usr/include/bits/stdio2.h" 3
extern "C" int __snprintf_chk(char *__restrict__, size_t, int, size_t, const char *__restrict__, ...) throw();
# 56 "/usr/include/bits/stdio2.h" 3
extern "C" int __vsnprintf_chk(char *__restrict__, size_t, int, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 75 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vsnprintf(char *__restrict__ __s, size_t __n, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()
# 77 "/usr/include/bits/stdio2.h" 3
{
# 78 "/usr/include/bits/stdio2.h" 3
return __builtin___vsnprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);
# 80 "/usr/include/bits/stdio2.h" 3
} }
# 86 "/usr/include/bits/stdio2.h" 3
extern "C" int __fprintf_chk(FILE *__restrict__, int, const char *__restrict__, ...);
# 88 "/usr/include/bits/stdio2.h" 3
extern "C" int __printf_chk(int, const char *__restrict__, ...);
# 89 "/usr/include/bits/stdio2.h" 3
extern "C" int __vfprintf_chk(FILE *__restrict__, int, const char *__restrict__, __gnuc_va_list);
# 91 "/usr/include/bits/stdio2.h" 3
extern "C" int __vprintf_chk(int, const char *__restrict__, __gnuc_va_list);
# 115 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vprintf(const char *__restrict__ __fmt, __gnuc_va_list __ap)
# 116 "/usr/include/bits/stdio2.h" 3
{
# 118 "/usr/include/bits/stdio2.h" 3
return __vfprintf_chk(stdout, 2 - 1, __fmt, __ap);
# 122 "/usr/include/bits/stdio2.h" 3
} }
# 125 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vfprintf(FILE *__restrict__ __stream, const char *__restrict__
# 126 "/usr/include/bits/stdio2.h" 3
__fmt, __gnuc_va_list __ap)
# 127 "/usr/include/bits/stdio2.h" 3
{
# 128 "/usr/include/bits/stdio2.h" 3
return __vfprintf_chk(__stream, 2 - 1, __fmt, __ap);
# 129 "/usr/include/bits/stdio2.h" 3
} }
# 133 "/usr/include/bits/stdio2.h" 3
extern "C" int __asprintf_chk(char **__restrict__, int, const char *__restrict__, ...) throw();
# 136 "/usr/include/bits/stdio2.h" 3
extern "C" int __vasprintf_chk(char **__restrict__, int, const char *__restrict__, __gnuc_va_list) throw();
# 139 "/usr/include/bits/stdio2.h" 3
extern "C" int __dprintf_chk(int, int, const char *__restrict__, ...);
# 141 "/usr/include/bits/stdio2.h" 3
extern "C" int __vdprintf_chk(int, int, const char *__restrict__, __gnuc_va_list);
# 144 "/usr/include/bits/stdio2.h" 3
extern "C" int __obstack_printf_chk(obstack *__restrict__, int, const char *__restrict__, ...) throw();
# 148 "/usr/include/bits/stdio2.h" 3
extern "C" int __obstack_vprintf_chk(obstack *__restrict__, int, const char *__restrict__, __gnuc_va_list) throw();
# 196 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vasprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()
# 198 "/usr/include/bits/stdio2.h" 3
{
# 199 "/usr/include/bits/stdio2.h" 3
return __vasprintf_chk(__ptr, 2 - 1, __fmt, __ap);
# 200 "/usr/include/bits/stdio2.h" 3
} }
# 203 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int vdprintf(int __fd, const char *__restrict__ __fmt, __gnuc_va_list __ap)
# 204 "/usr/include/bits/stdio2.h" 3
{
# 205 "/usr/include/bits/stdio2.h" 3
return __vdprintf_chk(__fd, 2 - 1, __fmt, __ap);
# 206 "/usr/include/bits/stdio2.h" 3
} }
# 209 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) int obstack_vprintf(obstack *__restrict__ __obstack, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()
# 211 "/usr/include/bits/stdio2.h" 3
{
# 212 "/usr/include/bits/stdio2.h" 3
return __obstack_vprintf_chk(__obstack, 2 - 1, __fmt, __ap);
# 214 "/usr/include/bits/stdio2.h" 3
} }
# 220 "/usr/include/bits/stdio2.h" 3
extern "C" char *__gets_chk(char *, size_t);
# 221 "/usr/include/bits/stdio2.h" 3
extern "C" char *__gets_warn(char *) __asm__("gets");
# 226 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *gets(char *__str)
# 227 "/usr/include/bits/stdio2.h" 3
{
# 228 "/usr/include/bits/stdio2.h" 3
if (__builtin_object_size(__str, 2 > 1) != ((size_t)(-1))) {
# 229 "/usr/include/bits/stdio2.h" 3
return __gets_chk(__str, __builtin_object_size(__str, 2 > 1)); }
# 230 "/usr/include/bits/stdio2.h" 3
return __gets_warn(__str);
# 231 "/usr/include/bits/stdio2.h" 3
} }
# 233 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_chk(char *__restrict__, size_t, int, FILE *__restrict__);
# 235 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_alias(char *__restrict__, int, FILE *__restrict__) __asm__("fgets");
# 238 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_chk_warn(char *__restrict__, size_t, int, FILE *__restrict__) __asm__("__fgets_chk");
# 245 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *fgets(char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
# 246 "/usr/include/bits/stdio2.h" 3
{
# 247 "/usr/include/bits/stdio2.h" 3
if (__builtin_object_size(__s, 2 > 1) != ((size_t)(-1)))
# 248 "/usr/include/bits/stdio2.h" 3
{
# 249 "/usr/include/bits/stdio2.h" 3
if ((!(__builtin_constant_p(__n))) || (__n <= 0)) {
# 250 "/usr/include/bits/stdio2.h" 3
return __fgets_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
# 252 "/usr/include/bits/stdio2.h" 3
if (((unsigned long)__n) > __builtin_object_size(__s, 2 > 1)) {
# 253 "/usr/include/bits/stdio2.h" 3
return __fgets_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
# 254 "/usr/include/bits/stdio2.h" 3
}
# 255 "/usr/include/bits/stdio2.h" 3
return __fgets_alias(__s, __n, __stream);
# 256 "/usr/include/bits/stdio2.h" 3
} }
# 258 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_chk(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__);
# 261 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_alias(void *__restrict__, size_t, size_t, FILE *__restrict__) __asm__("fread");
# 265 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_chk_warn(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__) __asm__("__fread_chk");
# 274 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) size_t fread(void *__restrict__ __ptr, size_t __size, size_t __n, FILE *__restrict__
# 275 "/usr/include/bits/stdio2.h" 3
__stream)
# 276 "/usr/include/bits/stdio2.h" 3
{
# 277 "/usr/include/bits/stdio2.h" 3
if (__builtin_object_size(__ptr, 0) != ((size_t)(-1)))
# 278 "/usr/include/bits/stdio2.h" 3
{
# 279 "/usr/include/bits/stdio2.h" 3
if (((!(__builtin_constant_p(__size))) || (!(__builtin_constant_p(__n)))) || ((__size | __n) >= (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) {
# 282 "/usr/include/bits/stdio2.h" 3
return __fread_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }
# 284 "/usr/include/bits/stdio2.h" 3
if ((__size * __n) > __builtin_object_size(__ptr, 0)) {
# 285 "/usr/include/bits/stdio2.h" 3
return __fread_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }
# 286 "/usr/include/bits/stdio2.h" 3
}
# 287 "/usr/include/bits/stdio2.h" 3
return __fread_alias(__ptr, __size, __n, __stream);
# 288 "/usr/include/bits/stdio2.h" 3
} }
# 291 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_unlocked_chk(char *__restrict__, size_t, int, FILE *__restrict__);
# 293 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_unlocked_alias(char *__restrict__, int, FILE *__restrict__) __asm__("fgets_unlocked");
# 296 "/usr/include/bits/stdio2.h" 3
extern "C" char *__fgets_unlocked_chk_warn(char *__restrict__, size_t, int, FILE *__restrict__) __asm__("__fgets_unlocked_chk");
# 303 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) char *fgets_unlocked(char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
# 304 "/usr/include/bits/stdio2.h" 3
{
# 305 "/usr/include/bits/stdio2.h" 3
if (__builtin_object_size(__s, 2 > 1) != ((size_t)(-1)))
# 306 "/usr/include/bits/stdio2.h" 3
{
# 307 "/usr/include/bits/stdio2.h" 3
if ((!(__builtin_constant_p(__n))) || (__n <= 0)) {
# 308 "/usr/include/bits/stdio2.h" 3
return __fgets_unlocked_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
# 310 "/usr/include/bits/stdio2.h" 3
if (((unsigned long)__n) > __builtin_object_size(__s, 2 > 1)) {
# 311 "/usr/include/bits/stdio2.h" 3
return __fgets_unlocked_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
# 312 "/usr/include/bits/stdio2.h" 3
}
# 313 "/usr/include/bits/stdio2.h" 3
return __fgets_unlocked_alias(__s, __n, __stream);
# 314 "/usr/include/bits/stdio2.h" 3
} }
# 319 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_unlocked_chk(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__);
# 322 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_unlocked_alias(void *__restrict__, size_t, size_t, FILE *__restrict__) __asm__("fread_unlocked");
# 326 "/usr/include/bits/stdio2.h" 3
extern "C" size_t __fread_unlocked_chk_warn(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__) __asm__("__fread_unlocked_chk");
# 335 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) size_t fread_unlocked(void *__restrict__ __ptr, size_t __size, size_t __n, FILE *__restrict__
# 336 "/usr/include/bits/stdio2.h" 3
__stream)
# 337 "/usr/include/bits/stdio2.h" 3
{
# 338 "/usr/include/bits/stdio2.h" 3
if (__builtin_object_size(__ptr, 0) != ((size_t)(-1)))
# 339 "/usr/include/bits/stdio2.h" 3
{
# 340 "/usr/include/bits/stdio2.h" 3
if (((!(__builtin_constant_p(__size))) || (!(__builtin_constant_p(__n)))) || ((__size | __n) >= (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) {
# 343 "/usr/include/bits/stdio2.h" 3
return __fread_unlocked_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }
# 346 "/usr/include/bits/stdio2.h" 3
if ((__size * __n) > __builtin_object_size(__ptr, 0)) {
# 347 "/usr/include/bits/stdio2.h" 3
return __fread_unlocked_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }
# 349 "/usr/include/bits/stdio2.h" 3
}
# 352 "/usr/include/bits/stdio2.h" 3
if ((((__builtin_constant_p(__size)) && (__builtin_constant_p(__n))) && ((__size | __n) < (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) && ((__size * __n) <= (8)))
# 356 "/usr/include/bits/stdio2.h" 3
{
# 357 "/usr/include/bits/stdio2.h" 3
auto size_t __cnt = (__size * __n);
# 358 "/usr/include/bits/stdio2.h" 3
auto char *__cptr = ((char *)__ptr);
# 359 "/usr/include/bits/stdio2.h" 3
if (__cnt == (0)) {
# 360 "/usr/include/bits/stdio2.h" 3
return 0; }
# 362 "/usr/include/bits/stdio2.h" 3
for (; __cnt > (0); --__cnt)
# 363 "/usr/include/bits/stdio2.h" 3
{
# 364 "/usr/include/bits/stdio2.h" 3
auto int __c = ((__builtin_expect((__stream->_IO_read_ptr) >= (__stream->_IO_read_end), 0)) ? __uflow(__stream) : (*((unsigned char *)((__stream->_IO_read_ptr)++))));
# 365 "/usr/include/bits/stdio2.h" 3
if (__c == (-1)) {
# 366 "/usr/include/bits/stdio2.h" 3
break; }
# 367 "/usr/include/bits/stdio2.h" 3
(*(__cptr++)) = __c;
# 368 "/usr/include/bits/stdio2.h" 3
}
# 369 "/usr/include/bits/stdio2.h" 3
return (__cptr - (char *)__ptr) / __size;
# 370 "/usr/include/bits/stdio2.h" 3
}
# 372 "/usr/include/bits/stdio2.h" 3
return __fread_unlocked_alias(__ptr, __size, __n, __stream);
# 373 "/usr/include/bits/stdio2.h" 3
} }
# 52 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 54 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 55 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 56 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 57 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 58 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 59 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 60 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUevent_st *CUevent; }
# 61 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUstream_st *CUstream; }
# 78 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 72 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 73 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 74 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 75 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 76 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 77 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 3
# 78 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 92 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 83 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 84 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 85 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 86 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 87 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 88 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 89 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 90 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 91 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 92 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 101 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 97 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 98 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 99 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 100 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR
# 101 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 109 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 106 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 107 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 108 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 109 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 135 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 114 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 115 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 116 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 117 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 118 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 119 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 120 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 121 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 122 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 123 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 124 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 125 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 126 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 127 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 128 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 129 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 130 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 132 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 133 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 134 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT
# 135 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 151 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 140 "/home/normal/temp/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 141 "/home/normal/temp/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 142 "/home/normal/temp/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 143 "/home/normal/temp/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 144 "/home/normal/temp/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 145 "/home/normal/temp/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 146 "/home/normal/temp/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 147 "/home/normal/temp/cuda/bin/../include/cuda.h"
int memPitch;
# 148 "/home/normal/temp/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 149 "/home/normal/temp/cuda/bin/../include/cuda.h"
int clockRate;
# 150 "/home/normal/temp/cuda/bin/../include/cuda.h"
int textureAlign;
# 151 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 160 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 156 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 157 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 158 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 159 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 160 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 220 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 166 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 169 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 178 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 182 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 186 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 192 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 196 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 202 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 206 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 210 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 213 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 218 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 220 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 231 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 225 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 227 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 228 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 229 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 230 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13
# 231 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 244 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 236 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 239 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 242 "/home/normal/temp/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 244 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 289 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 252 "/home/normal/temp/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 254 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 255 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 256 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 257 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 258 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 260 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 261 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 263 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 264 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 265 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 266 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 267 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 268 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 269 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 270 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 271 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 272 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 274 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 275 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 277 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 279 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 281 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 283 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 284 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 285 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 286 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 288 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 289 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUresult; }
# 300 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 308 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 309 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 310 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 311 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 312 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 313 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 314 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 322 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 323 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 324 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 325 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 326 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 327 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 328 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 329 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 338 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 339 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 340 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 341 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 342 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 343 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 344 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 345 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 353 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 355 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 356 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 364 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 365 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 367 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 368 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 381 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 382 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 385 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 388 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 389 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 392 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 393 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 396 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 418 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 400 "/home/normal/temp/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 402 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcXInBytes; unsigned srcY;
# 403 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 404 "/home/normal/temp/cuda/bin/../include/cuda.h"
const void *srcHost;
# 405 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 406 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 407 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 409 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstXInBytes; unsigned dstY;
# 410 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 411 "/home/normal/temp/cuda/bin/../include/cuda.h"
void *dstHost;
# 412 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 413 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 414 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 416 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 417 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Height;
# 418 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 419 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 420 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 449 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 424 "/home/normal/temp/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 426 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcXInBytes; unsigned srcY; unsigned srcZ;
# 427 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 428 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 429 "/home/normal/temp/cuda/bin/../include/cuda.h"
const void *srcHost;
# 430 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 431 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 432 "/home/normal/temp/cuda/bin/../include/cuda.h"
void *reserved0;
# 433 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 434 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned srcHeight;
# 436 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstXInBytes; unsigned dstY; unsigned dstZ;
# 437 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 438 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 439 "/home/normal/temp/cuda/bin/../include/cuda.h"
void *dstHost;
# 440 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 441 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 442 "/home/normal/temp/cuda/bin/../include/cuda.h"
void *reserved1;
# 443 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 444 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned dstHeight;
# 446 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 447 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Height;
# 448 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Depth;
# 449 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 450 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 465 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 467 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 471 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 473 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 477 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 480 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 487 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 488 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 489 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 491 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 492 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 493 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 502 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 503 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 526 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 512 "/home/normal/temp/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR {
# 516 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Width;
# 517 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Height;
# 522 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 525 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 526 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 528 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 529 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 530 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 552 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 533 "/home/normal/temp/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR {
# 537 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Width;
# 538 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Height;
# 539 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Depth;
# 543 "/home/normal/temp/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 546 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 550 "/home/normal/temp/cuda/bin/../include/cuda.h"
unsigned Flags;
# 552 "/home/normal/temp/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 553 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 554 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 561 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 562 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 564 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 567 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 568 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 570 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 571 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 572 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 580 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 581 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 582 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 583 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 584 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 585 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 593 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 594 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 595 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 596 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 597 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 608 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 609 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 610 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 617 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 618 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 619 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 620 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 621 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 622 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 629 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 630 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 631 "/home/normal/temp/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 632 "/home/normal/temp/cuda/bin/../include/cuda.h"
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
# 162 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 164 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 165 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 166 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return x.x;
# 167 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 169 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 170 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 171 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return x.y;
# 172 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 174 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 175 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
r, float i)
# 176 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 177 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuFloatComplex res;
# 178 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 179 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 180 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return res;
# 181 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 183 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 184 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 185 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 186 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 187 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 188 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 189 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 190 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 192 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 194 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 195 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 196 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 197 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 199 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 206 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 207 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 208 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 209 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuFloatComplex prod;
# 210 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
prod = make_cuFloatComplex(cuCrealf(x) * cuCrealf(y) - cuCimagf(x) * cuCimagf(y), cuCrealf(x) * cuCimagf(y) + cuCimagf(x) * cuCrealf(y));
# 214 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return prod;
# 215 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 222 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 223 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 224 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 225 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuFloatComplex quot;
# 226 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float s = ((float)fabs((double)cuCrealf(y)) + (float)fabs((double)cuCimagf(y)));
# 228 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float oos = ((1.0F) / s);
# 229 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float ars = (cuCrealf(x) * oos);
# 230 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float ais = (cuCimagf(x) * oos);
# 231 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float brs = (cuCrealf(y) * oos);
# 232 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float bis = (cuCimagf(y) * oos);
# 233 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
s = brs * brs + bis * bis;
# 234 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
oos = (1.0F) / s;
# 235 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
quot = make_cuFloatComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);
# 237 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return quot;
# 238 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 248 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 249 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 250 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float a = cuCrealf(x);
# 251 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float b = cuCimagf(x);
# 252 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto float v; auto float w; auto float t;
# 253 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
a = (float)fabs(a);
# 254 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
b = (float)fabs(b);
# 255 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 256 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
v = a;
# 257 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
w = b;
# 258 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} else {
# 259 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
v = b;
# 260 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
w = a;
# 261 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 262 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = w / v;
# 263 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = (1.0F) + t * t;
# 264 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = v * (float)sqrt(t);
# 265 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 266 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = v + w;
# 267 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 268 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return t;
# 269 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 272 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 274 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 275 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 276 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return x.x;
# 277 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 279 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 280 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 281 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return x.y;
# 282 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 284 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 285 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
r, double i)
# 286 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 287 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuDoubleComplex res;
# 288 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 289 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 290 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return res;
# 291 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 293 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 294 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 295 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 296 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 298 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 299 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 300 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 301 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 303 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 305 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 306 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 307 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 308 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 310 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 317 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 318 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 319 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 320 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuDoubleComplex prod;
# 321 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
prod = make_cuDoubleComplex(cuCreal(x) * cuCreal(y) - cuCimag(x) * cuCimag(y), cuCreal(x) * cuCimag(y) + cuCimag(x) * cuCreal(y));
# 325 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return prod;
# 326 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 333 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 334 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 335 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 336 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto cuDoubleComplex quot;
# 337 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 338 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double oos = ((1.0) / s);
# 339 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double ars = (cuCreal(x) * oos);
# 340 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double ais = (cuCimag(x) * oos);
# 341 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double brs = (cuCreal(y) * oos);
# 342 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double bis = (cuCimag(y) * oos);
# 343 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
s = brs * brs + bis * bis;
# 344 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
oos = (1.0) / s;
# 345 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
quot = make_cuDoubleComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);
# 347 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return quot;
# 348 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 356 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 357 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 358 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double a = cuCreal(x);
# 359 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double b = cuCimag(x);
# 360 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
auto double v; auto double w; auto double t;
# 361 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
a = fabs(a);
# 362 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
b = fabs(b);
# 363 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 364 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
v = a;
# 365 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
w = b;
# 366 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} else {
# 367 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
v = b;
# 368 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
w = a;
# 369 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 370 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = w / v;
# 371 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = (1.0) + t * t;
# 372 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = v * sqrt(t);
# 373 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 374 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 375 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
t = v + w;
# 376 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 377 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return t;
# 378 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
} }
# 387 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 388 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 389 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
y)
# 390 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 391 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 392 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 395 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 396 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
c)
# 397 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 398 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 399 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 401 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 402 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
c)
# 403 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
{
# 404 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 405 "/home/normal/temp/cuda/bin/../include/cuComplex.h"
}
# 74 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 64 "/home/normal/temp/cuda/bin/../include/cufft.h"
enum cufftResult_t {
# 65 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_SUCCESS,
# 66 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_INVALID_PLAN,
# 67 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_ALLOC_FAILED,
# 68 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_INVALID_TYPE,
# 69 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_INVALID_VALUE,
# 70 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_INTERNAL_ERROR,
# 71 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_EXEC_FAILED,
# 72 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_SETUP_FAILED,
# 73 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_INVALID_SIZE
# 74 "/home/normal/temp/cuda/bin/../include/cufft.h"
} cufftResult; }
# 79 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 82 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 87 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 98 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 94 "/home/normal/temp/cuda/bin/../include/cufft.h"
enum cufftType_t {
# 95 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_R2C = 42,
# 96 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_C2R = 44,
# 97 "/home/normal/temp/cuda/bin/../include/cufft.h"
CUFFT_C2C = 41
# 98 "/home/normal/temp/cuda/bin/../include/cufft.h"
} cufftType; }
# 100 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 105 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 109 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 113 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 115 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 120 "/home/normal/temp/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 124 "/home/normal/temp/cuda/bin/../include/cufft.h"
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
# 211 "../../sdk/cutil_inline.h"
inline void cutilDeviceInit(int ARGC, char **ARGV) { }
# 212 "../../sdk/cutil_inline.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV) { }
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
# 311 "../../sdk/cutil_inline.h"
# 1 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.h" 1

extern "C" {





extern __attribute__((__weak__)) void __device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii(float *, const float *, float *, int, int, int);

}
template <bool, bool>
void __globfunc_prescan( float *,const float *,float *,int,int,int);
extern "C" {



extern __attribute__((__weak__)) void __device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii(float *, const float *, float *, int, int, int);

}
template <bool, bool>
void __globfunc_prescan( float *,const float *,float *,int,int,int);
extern "C" {



extern __attribute__((__weak__)) void __device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii(float *, const float *, float *, int, int, int);

}
template <bool, bool>
void __globfunc_prescan( float *,const float *,float *,int,int,int);
extern "C" {



extern __attribute__((__weak__)) void __device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii(float *, const float *, float *, int, int, int);

}
template <bool, bool>
void __globfunc_prescan( float *,const float *,float *,int,int,int);
extern "C" {



}
# 312 "../../sdk/cutil_inline.h" 2





# 1 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.h" 1

extern "C" {


extern void __device_stub__Z10uniformAddPfS_iii(float *, float *, int, int, int);
# 44 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.h"
}
# 318 "../../sdk/cutil_inline.h" 2
# 71 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char *, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 76 "/usr/include/assert.h" 3
extern "C" void __assert_perror_fail(int, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 84 "/usr/include/assert.h" 3
extern "C" void __assert(const char *, const char *, int) throw() __attribute__((__noreturn__));
# 37 "scan.cu"
inline bool isPowerOfTwo(int n)
# 38 "scan.cu"
{
# 39 "scan.cu"
return (n & (n - 1)) == 0;
# 40 "scan.cu"
}
# 43 "scan.cu"
inline int floorPow2(int n)
# 44 "scan.cu"
{
# 52 "scan.cu"
auto int exp;
# 53 "scan.cu"
frexp((float)n, &exp);
# 54 "scan.cu"
return 1 << (exp - 1);
# 56 "scan.cu"
}
# 60 "scan.cu"
float **g_scanBlockSums;
# 61 "scan.cu"
unsigned g_numEltsAllocated = (0);
# 62 "scan.cu"
unsigned g_numLevelsAllocated = (0);
# 64 "scan.cu"
void preallocBlockSums(unsigned maxNumElements)
# 65 "scan.cu"
{
# 66 "scan.cu"
(g_numEltsAllocated == (0)) ? (static_cast< void>(0)) : __assert_fail("g_numEltsAllocated == 0", "scan.cu", 66, __PRETTY_FUNCTION__);
# 68 "scan.cu"
g_numEltsAllocated = maxNumElements;
# 70 "scan.cu"
auto unsigned blockSize = (256);
# 71 "scan.cu"
auto unsigned numElts = maxNumElements;
# 73 "scan.cu"
auto int level = 0;
# 75 "scan.cu"
do
# 76 "scan.cu"
{
# 77 "scan.cu"
auto unsigned numBlocks = (max(1, (int)ceil((float)numElts / ((2.0F) * blockSize))));
# 79 "scan.cu"
if (numBlocks > (1))
# 80 "scan.cu"
{
# 81 "scan.cu"
level++;
# 82 "scan.cu"
}
# 83 "scan.cu"
numElts = numBlocks;
# 84 "scan.cu"
} while (numElts > (1));
# 86 "scan.cu"
g_scanBlockSums = (float **)malloc(level * sizeof(float *));
# 87 "scan.cu"
g_numLevelsAllocated = level;
# 89 "scan.cu"
numElts = maxNumElements;
# 90 "scan.cu"
level = 0;
# 92 "scan.cu"
do
# 93 "scan.cu"
{
# 94 "scan.cu"
auto unsigned numBlocks = (max(1, (int)ceil((float)numElts / ((2.0F) * blockSize))));
# 96 "scan.cu"
if (numBlocks > (1))
# 97 "scan.cu"
{
# 98 "scan.cu"
__cudaSafeCall(cudaMalloc((void **)(g_scanBlockSums + level++), numBlocks * sizeof(float)), "scan.cu", 99);
# 100 "scan.cu"
}
# 101 "scan.cu"
numElts = numBlocks;
# 102 "scan.cu"
} while (numElts > (1));
# 104 "scan.cu"
__cutilCheckMsg("preallocBlockSums", "scan.cu", 104);
# 105 "scan.cu"
}
# 107 "scan.cu"
void deallocBlockSums()
# 108 "scan.cu"
{
# 109 "scan.cu"
for (unsigned i = (0); i < g_numLevelsAllocated; i++)
# 110 "scan.cu"
{
# 111 "scan.cu"
cudaFree(g_scanBlockSums[i]);
# 112 "scan.cu"
}
# 114 "scan.cu"
__cutilCheckMsg("deallocBlockSums", "scan.cu", 114);
# 116 "scan.cu"
free((void **)g_scanBlockSums);
# 118 "scan.cu"
g_scanBlockSums = (0);
# 119 "scan.cu"
g_numEltsAllocated = (0);
# 120 "scan.cu"
g_numLevelsAllocated = (0);
# 121 "scan.cu"
}
# 124 "scan.cu"
void prescanArrayRecursive(float *outArray, const float *
# 125 "scan.cu"
inArray, int
# 126 "scan.cu"
numElements, int
# 127 "scan.cu"
level)
# 128 "scan.cu"
{
# 129 "scan.cu"
auto unsigned blockSize = (256);
# 130 "scan.cu"
auto unsigned numBlocks = (max(1, (int)ceil((float)numElements / ((2.0F) * blockSize))));
# 132 "scan.cu"
auto unsigned numThreads;
# 134 "scan.cu"
if (numBlocks > (1)) {
# 135 "scan.cu"
numThreads = blockSize; } else {
# 136 "scan.cu"
if (isPowerOfTwo(numElements)) {
# 137 "scan.cu"
numThreads = numElements / 2; } else {
# 139 "scan.cu"
numThreads = floorPow2(numElements); } }
# 141 "scan.cu"
auto unsigned numEltsPerBlock = (numThreads * (2));
# 145 "scan.cu"
auto unsigned numEltsLastBlock = (numElements - (numBlocks - (1)) * numEltsPerBlock);
# 147 "scan.cu"
auto unsigned numThreadsLastBlock = max(1, numEltsLastBlock / (2));
# 148 "scan.cu"
auto unsigned np2LastBlock = (0);
# 149 "scan.cu"
auto unsigned sharedMemLastBlock = (0);
# 151 "scan.cu"
if (numEltsLastBlock != numEltsPerBlock)
# 152 "scan.cu"
{
# 153 "scan.cu"
np2LastBlock = (1);
# 155 "scan.cu"
if (!isPowerOfTwo(numEltsLastBlock)) {
# 156 "scan.cu"
numThreadsLastBlock = floorPow2(numEltsLastBlock); }
# 158 "scan.cu"
auto unsigned extraSpace = (((2) * numThreadsLastBlock) / (16));
# 159 "scan.cu"
sharedMemLastBlock = sizeof(float) * ((2) * numThreadsLastBlock + extraSpace);
# 161 "scan.cu"
}
# 164 "scan.cu"
auto unsigned extraSpace = (numEltsPerBlock / (16));
# 165 "scan.cu"
auto unsigned sharedMemSize = (sizeof(float) * (numEltsPerBlock + extraSpace));
# 177 "scan.cu"
auto dim3 grid(max(1, numBlocks - np2LastBlock), 1, 1);
# 178 "scan.cu"
auto dim3 threads(numThreads, 1, 1);
# 181 "scan.cu"
__cutilCheckMsg("prescanArrayRecursive before kernels", "scan.cu", 181);
# 184 "scan.cu"
if (numBlocks > (1))
# 185 "scan.cu"
{
# 186 "scan.cu"
cudaConfigureCall(grid, threads, sharedMemSize) ? ((void)0) : (__device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii)(outArray, inArray, g_scanBlockSums[level], numThreads * (2), 0, 0);
# 190 "scan.cu"
__cutilCheckMsg("prescanWithBlockSums", "scan.cu", 190);
# 191 "scan.cu"
if (np2LastBlock)
# 192 "scan.cu"
{
# 193 "scan.cu"
cudaConfigureCall(1, numThreadsLastBlock, sharedMemLastBlock) ? ((void)0) : (__device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii)(outArray, inArray, g_scanBlockSums[level], numEltsLastBlock, numBlocks - (1), numElements - numEltsLastBlock);
# 196 "scan.cu"
__cutilCheckMsg("prescanNP2WithBlockSums", "scan.cu", 196);
# 197 "scan.cu"
}
# 204 "scan.cu"
prescanArrayRecursive(g_scanBlockSums[level], g_scanBlockSums[level], numBlocks, level + 1);
# 209 "scan.cu"
cudaConfigureCall(grid, threads) ? ((void)0) : __device_stub__Z10uniformAddPfS_iii(outArray, g_scanBlockSums[level], numElements - numEltsLastBlock, 0, 0);
# 213 "scan.cu"
__cutilCheckMsg("uniformAdd", "scan.cu", 213);
# 214 "scan.cu"
if (np2LastBlock)
# 215 "scan.cu"
{
# 216 "scan.cu"
cudaConfigureCall(1, numThreadsLastBlock) ? ((void)0) : __device_stub__Z10uniformAddPfS_iii(outArray, g_scanBlockSums[level], numEltsLastBlock, numBlocks - (1), numElements - numEltsLastBlock);
# 221 "scan.cu"
__cutilCheckMsg("uniformAdd", "scan.cu", 221);
# 222 "scan.cu"
}
# 223 "scan.cu"
} else {
# 224 "scan.cu"
if (isPowerOfTwo(numElements))
# 225 "scan.cu"
{
# 226 "scan.cu"
cudaConfigureCall(grid, threads, sharedMemSize) ? ((void)0) : (__device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii)(outArray, inArray, 0, numThreads * (2), 0, 0);
# 228 "scan.cu"
__cutilCheckMsg("prescan", "scan.cu", 228);
# 229 "scan.cu"
} else
# 231 "scan.cu"
{
# 232 "scan.cu"
cudaConfigureCall(grid, threads, sharedMemSize) ? ((void)0) : (__device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii)(outArray, inArray, 0, numElements, 0, 0);
# 234 "scan.cu"
__cutilCheckMsg("prescanNP2", "scan.cu", 234);
# 235 "scan.cu"
} }
# 236 "scan.cu"
}
# 238 "scan.cu"
void prescanArray(float *outArray, float *inArray, int numElements)
# 239 "scan.cu"
{
# 240 "scan.cu"
prescanArrayRecursive(outArray, inArray, numElements, 0);
# 241 "scan.cu"
}
# 45 "scanLargeArray.cu"
extern void runTest(int, char **);
# 49 "scanLargeArray.cu"
extern "C" unsigned compare(const float *, const float *, const unsigned);
# 52 "scanLargeArray.cu"
extern "C" void computeGold(float *, float *, const unsigned);
# 58 "scanLargeArray.cu"
int main(int argc, char **argv)
# 59 "scanLargeArray.cu"
{
# 60 "scanLargeArray.cu"
runTest(argc, argv);
# 61 "scanLargeArray.cu"
__cutilExit(argc, argv); return 0;
# 62 "scanLargeArray.cu"
}
# 68 "scanLargeArray.cu"
void runTest(int argc, char **argv)
# 69 "scanLargeArray.cu"
{
# 71 "scanLargeArray.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
# 72 "scanLargeArray.cu"
cutilDeviceInit(argc, argv); } else {
# 74 "scanLargeArray.cu"
cudaSetDevice(cutGetMaxGflopsDeviceId()); }
# 80 "scanLargeArray.cu"
auto unsigned num_test_iterations = (1);
# 81 "scanLargeArray.cu"
auto unsigned num_elements = (10000);
# 84 "scanLargeArray.cu"
cutGetCmdLineArgumenti(argc, (const char **)argv, "n", (int *)(&num_elements));
# 85 "scanLargeArray.cu"
cutGetCmdLineArgumenti(argc, (const char **)argv, "i", (int *)(&num_test_iterations));
# 87 "scanLargeArray.cu"
auto unsigned mem_size = (sizeof(float) * num_elements);
# 89 "scanLargeArray.cu"
auto unsigned timerGPU; auto unsigned timerCPU;
# 90 "scanLargeArray.cu"
__cutilCheckError(cutCreateTimer(&timerCPU), "scanLargeArray.cu", 90);
# 91 "scanLargeArray.cu"
__cutilCheckError(cutCreateTimer(&timerGPU), "scanLargeArray.cu", 91);
# 94 "scanLargeArray.cu"
auto float *h_data = ((float *)malloc(mem_size));
# 97 "scanLargeArray.cu"
for (unsigned i = (0); i < num_elements; ++i)
# 98 "scanLargeArray.cu"
{
# 99 "scanLargeArray.cu"
(h_data[i]) = (1.0F);
# 100 "scanLargeArray.cu"
}
# 103 "scanLargeArray.cu"
auto float *reference = ((float *)malloc(mem_size));
# 104 "scanLargeArray.cu"
cutStartTimer(timerCPU);
# 105 "scanLargeArray.cu"
for (unsigned i = (0); i < num_test_iterations; i++)
# 106 "scanLargeArray.cu"
{
# 107 "scanLargeArray.cu"
computeGold(reference, h_data, num_elements);
# 108 "scanLargeArray.cu"
}
# 109 "scanLargeArray.cu"
cutStopTimer(timerCPU);
# 112 "scanLargeArray.cu"
auto float *d_idata = (__null);
# 113 "scanLargeArray.cu"
auto float *d_odata = (__null);
# 115 "scanLargeArray.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_idata), mem_size), "scanLargeArray.cu", 115);
# 116 "scanLargeArray.cu"
__cudaSafeCall(cudaMalloc((void **)(&d_odata), mem_size), "scanLargeArray.cu", 116);
# 119 "scanLargeArray.cu"
__cudaSafeCall(cudaMemcpy(d_idata, h_data, mem_size, cudaMemcpyHostToDevice), "scanLargeArray.cu", 119);
# 121 "scanLargeArray.cu"
__cudaSafeCall(cudaMemcpy(d_odata, h_data, mem_size, cudaMemcpyHostToDevice), "scanLargeArray.cu", 121);
# 123 "scanLargeArray.cu"
printf("Running parallel prefix sum (prescan) of %d elements\n", num_elements);
# 124 "scanLargeArray.cu"
printf("This version is work efficient (O(n) adds)\n");
# 125 "scanLargeArray.cu"
printf("and has very few shared memory bank conflicts\n\n");
# 127 "scanLargeArray.cu"
preallocBlockSums(num_elements);
# 130 "scanLargeArray.cu"
prescanArray(d_odata, d_idata, num_elements);
# 134 "scanLargeArray.cu"
cutStartTimer(timerGPU);
# 135 "scanLargeArray.cu"
for (unsigned i = (0); i < num_test_iterations; i++)
# 136 "scanLargeArray.cu"
{
# 138 "scanLargeArray.cu"
prescanArray(d_odata, d_idata, num_elements);
# 139 "scanLargeArray.cu"
}
# 140 "scanLargeArray.cu"
cutStopTimer(timerGPU);
# 142 "scanLargeArray.cu"
deallocBlockSums();
# 145 "scanLargeArray.cu"
__cudaSafeCall(cudaMemcpy(h_data, d_odata, sizeof(float) * num_elements, cudaMemcpyDeviceToHost), "scanLargeArray.cu", 146);
# 149 "scanLargeArray.cu"
if (cutCheckCmdLineFlag(argc, (const char **)argv, "regression"))
# 150 "scanLargeArray.cu"
{
# 152 "scanLargeArray.cu"
cutWriteFilef("./data/result.dat", h_data, num_elements, (0.0));
# 153 "scanLargeArray.cu"
} else
# 155 "scanLargeArray.cu"
{
# 158 "scanLargeArray.cu"
auto unsigned result_regtest = (cutComparef(reference, h_data, num_elements));
# 159 "scanLargeArray.cu"
printf("Test %s\n", ((1) == result_regtest) ? ((const char *)"PASSED") : ((const char *)"FAILED"));
# 160 "scanLargeArray.cu"
printf("Average GPU execution time: %f ms\n", cutGetTimerValue(timerGPU) / num_test_iterations);
# 161 "scanLargeArray.cu"
printf("CPU execution time:         %f ms\n", cutGetTimerValue(timerCPU) / num_test_iterations);
# 162 "scanLargeArray.cu"
}
# 164 "scanLargeArray.cu"
printf("\nCheck out the CUDA Data Parallel Primitives Library for more on scan.\n");
# 165 "scanLargeArray.cu"
printf("http://www.gpgpu.org/developer/cudpp\n");
# 168 "scanLargeArray.cu"
cutDeleteTimer(timerCPU);
# 169 "scanLargeArray.cu"
cutDeleteTimer(timerGPU);
# 170 "scanLargeArray.cu"
free(h_data);
# 171 "scanLargeArray.cu"
free(reference);
# 172 "scanLargeArray.cu"
cudaFree(d_odata);
# 173 "scanLargeArray.cu"
cudaFree(d_idata);
# 175 "scanLargeArray.cu"
cudaThreadExit();
# 176 "scanLargeArray.cu"
}

# 1 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_00003ee9_00000000-3_scanLargeArray.fatbin.c" 1
# 1 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* debug;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 144 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 157 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
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
# 191 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 214 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 225 "/home/normal/temp/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_00003ee9_00000000-3_scanLargeArray.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$compute_10$[] = {
0x6f69737265762e09ull,0x2e090a332e31206eull,0x7320746567726174ull,0x616d202c30315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x726f6e2f656d6f68ull,0x706d65742f6c616dull,0x706f2f616475632full,0x62696c2f34366e65ull,
0x2f2f090a65622f2full,0x636e65706f766e20ull,0x20746c6975622063ull,0x2d38303032206e6full,
0x090a0a33302d3231ull,0x33752e206765722eull,0x37313c6172252032ull,0x6765722e090a3b3eull,
0x7225203436752e20ull,0x0a3b3e37313c6164ull,0x662e206765722e09ull,0x313c616625203233ull,
0x65722e090a3b3e37ull,0x25203436662e2067ull,0x3b3e37313c616466ull,0x2e206765722e090aull,
0x3c76722520323375ull,0x65722e090a3b3e35ull,0x25203436752e2067ull,0x0a3b3e353c766472ull,
0x662e206765722e09ull,0x353c766625203233ull,0x6765722e090a3b3eull,0x6625203436662e20ull,
0x0a0a3b3e353c7664ull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x0a2d2d2d2d2d2d2dull,0x706d6f43202f2f09ull,0x742f20676e696c69ull,0x6678706d742f706dull,
0x6533303030305f74ull,0x30303030305f3965ull,0x63735f372d303030ull,0x41656772614c6e61ull,
0x7070632e79617272ull,0x6d742f2820692e33ull,0x2e23494263632f70ull,0x0a29475248633561ull,
0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a0a2d2d2d2d2d2dull,
0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x090a2d2d2d2d2d2dull,
0x6f6974704f202f2full,0x2d2f2f090a3a736eull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x20202f2f090a2d2dull,0x703a746567726154ull,0x3a415349202c7874ull,
0x45202c30315f6d73ull,0x696c3a6e6169646eull,0x6f50202c656c7474ull,0x6953207265746e69ull,
0x2f090a34363a657aull,0x2809334f2d20202full,0x617a696d6974704full,0x76656c206e6f6974ull,
0x202f2f090a296c65ull,0x6544280930672d20ull,0x6576656c20677562ull,0x20202f2f090a296cull,
0x7065522809326d2dull,0x697664612074726full,0x0a29736569726f73ull,0x2d2d2d2d2d2f2f09ull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a0a2d2d2d2d2d2dull,0x3109656c69662e09ull,
0x616d6d6f633c2209ull,0x3e656e696c2d646eull,0x656c69662e090a22ull,0x706d742f22093209ull,
0x5f746678706d742full,0x3965653330303030ull,0x303030303030305full,0x6e6163735f362d30ull,
0x727241656772614cull,0x66616475632e7961ull,0x0a227570672e3265ull,0x3309656c69662e09ull,
0x6c2f7273752f2209ull,0x782f6363672f6269ull,0x696c2d34365f3638ull,0x2f756e672d78756eull,
0x6e692f332e332e34ull,0x74732f6564756c63ull,0x0a22682e66656464ull,0x3409656c69662e09ull,
0x2f656d6f682f2209ull,0x742f6c616d726f6eull,0x616475632f706d65ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x697665642f747263ull,0x69746e75725f6563ull,0x2e090a22682e656dull,
0x22093509656c6966ull,0x6f6e2f656d6f682full,0x6d65742f6c616d72ull,0x622f616475632f70ull,
0x6e692f2e2e2f6e69ull,0x6f682f6564756c63ull,0x6e696665645f7473ull,0x2e090a22682e7365ull,
0x22093609656c6966ull,0x6f6e2f656d6f682full,0x6d65742f6c616d72ull,0x622f616475632f70ull,
0x6e692f2e2e2f6e69ull,0x75622f6564756c63ull,0x79745f6e69746c69ull,0x090a22682e736570ull,
0x093709656c69662eull,0x6e2f656d6f682f22ull,0x65742f6c616d726full,0x2f616475632f706dull,
0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x79745f6563697665ull,0x090a22682e736570ull,
0x093809656c69662eull,0x6e2f656d6f682f22ull,0x65742f6c616d726full,0x2f616475632f706dull,
0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x79745f7265766972ull,0x090a22682e736570ull,
0x093909656c69662eull,0x6e2f656d6f682f22ull,0x65742f6c616d726full,0x2f616475632f706dull,
0x692f2e2e2f6e6962ull,0x742f6564756c636eull,0x745f657275747865ull,0x0a22682e73657079ull,
0x3109656c69662e09ull,0x656d6f682f220930ull,0x2f6c616d726f6e2full,0x6475632f706d6574ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f726f746365762full,0x22682e7365707974ull,
0x09656c69662e090aull,0x6d6f682f22093131ull,0x6c616d726f6e2f65ull,0x75632f706d65742full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6563697665642f65ull,0x5f68636e75616c5full,
0x6574656d61726170ull,0x2e090a22682e7372ull,0x09323109656c6966ull,0x6e2f656d6f682f22ull,
0x65742f6c616d726full,0x2f616475632f706dull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,
0x61726f74732f7472ull,0x7373616c635f6567ull,0x69662e090a22682eull,0x2f2209333109656cull,
0x6c636e692f727375ull,0x737469622f656475ull,0x682e73657079742full,0x656c69662e090a22ull,
0x73752f2209343109ull,0x64756c636e692f72ull,0x682e656d69742f65ull,0x656c69662e090a22ull,
0x6163732209353109ull,0x7241656772614c6eull,0x6e72656b5f796172ull,0x090a2275632e6c65ull,
0x363109656c69662eull,0x692f7273752f2209ull,0x632f6564756c636eull,0x632f332e342f2b2bull,
0x2e090a226874616dull,0x09373109656c6966ull,0x6e2f656d6f682f22ull,0x65742f6c616d726full,
0x2f616475632f706dull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,0x75665f6e6f6d6d6full,
0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x682f220938310965ull,0x6d726f6e2f656d6full,
0x2f706d65742f6c61ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x2f7472632f656475ull,
0x63616d5f636e7566ull,0x2e090a22682e6f72ull,0x09393109656c6966ull,0x6e2f656d6f682f22ull,
0x65742f6c616d726full,0x2f616475632f706dull,0x692f2e2e2f6e6962ull,0x6d2f6564756c636eull,
0x636e75665f687461ull,0x22682e736e6f6974ull,0x09656c69662e090aull,0x6d6f682f22093032ull,
0x6c616d726f6e2f65ull,0x75632f706d65742full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x6563697665642f65ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09313209656c6966ull,
0x6e2f656d6f682f22ull,0x65742f6c616d726full,0x2f616475632f706dull,0x692f2e2e2f6e6962ull,
0x6d2f6564756c636eull,0x736e6f635f687461ull,0x22682e73746e6174ull,0x09656c69662e090aull,
0x6d6f682f22093232ull,0x6c616d726f6e2f65ull,0x75632f706d65742full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x5f31315f6d732f65ull,0x665f63696d6f7461ull,0x736e6f6974636e75ull,
0x69662e090a22682eull,0x2f2209333209656cull,0x726f6e2f656d6f68ull,0x706d65742f6c616dull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x5f6d732f6564756cull,0x696d6f74615f3231ull,
0x6974636e75665f63ull,0x090a22682e736e6full,0x343209656c69662eull,0x2f656d6f682f2209ull,
0x742f6c616d726f6eull,0x616475632f706d65ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6f645f33315f6d73ull,0x6e75665f656c6275ull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209353209ull,0x616d726f6e2f656dull,0x632f706d65742f6cull,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x75747865742f6564ull,0x68637465665f6572ull,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09363209656c6966ull,0x6e2f656d6f682f22ull,0x65742f6c616d726full,
0x2f616475632f706dull,0x692f2e2e2f6e6962ull,0x6d2f6564756c636eull,0x636e75665f687461ull,
0x62645f736e6f6974ull,0x682e317874705f6cull,0x7478652e090a0a22ull,0x6168732e096e7265ull,
0x696c612e20646572ull,0x38622e2034206e67ull,0x5b617461645f7320ull,0x6e652e090a0a3b5dull,
0x30315a5f20797274ull,0x416d726f66696e75ull,0x69695f5366506464ull,0x722e090a7b090a69ull,
0x203233752e206765ull,0x0a3b3e36313c7225ull,0x752e206765722e09ull,0x313c647225203436ull,
0x65722e090a3b3e33ull,0x25203233662e2067ull,0x2e090a3b3e383c66ull,0x6572702e20676572ull,
0x3b3e343c70252064ull,0x6d617261702e090aull,0x5f5f203436752e20ull,0x6d72617061647563ull,
0x696e7530315a5f5full,0x506464416d726f66ull,0x675f6969695f5366ull,0x090a3b617461645full,
0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x6f66696e7530315aull,
0x5366506464416d72ull,0x696e755f6969695full,0x090a3b736d726f66ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x6f66696e7530315aull,0x5366506464416d72ull,
0x0a3b6e5f6969695full,0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,
0x66696e7530315a5full,0x66506464416d726full,0x6c625f6969695f53ull,0x657366664f6b636full,
0x7261702e090a3b74ull,0x203233732e206d61ull,0x6170616475635f5full,0x7530315a5f5f6d72ull,
0x64416d726f66696eull,0x6969695f53665064ull,0x646e49657361625full,0x68732e090a3b7865ull,
0x33662e2064657261ull,0x090a3b696e752032ull,0x09353109636f6c2eull,0x4c240a3009383432ull,
0x30315a5f5f314242ull,0x416d726f66696e75ull,0x69695f5366506464ull,0x2e747663090a3a69ull,
0x203631752e323373ull,0x6325202c31722509ull,0x203b782e64696174ull,0x090a202f2f092020ull,
0x2e3233752e747663ull,0x3272250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,
0x2e766f6d090a202full,0x3372250920323375ull,0x202020203b30202cull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e656e2e70746573ull,0x3170250920323375ull,0x25202c327225202cull,
0x2f092020203b3372ull,0x31702540090a202full,0x4c24092061726220ull,0x20203b375f305f74ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6c090a3009323532ull,
0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,
0x6f66696e7530315aull,0x5366506464416d72ull,0x696e755f6969695full,0x093b5d736d726f66ull,
0x38333a6469202f2full,0x70616475635f5f20ull,0x30315a5f5f6d7261ull,0x416d726f66696e75ull,
0x69695f5366506464ull,0x726f66696e755f69ull,0x090a3078302b736dull,0x6d617261702e646cull,
0x722509203233752eull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x6f66696e7530315aull,
0x5366506464416d72ull,0x6f6c625f6969695full,0x74657366664f6b63ull,0x6469202f2f093b5dull,
0x75635f5f2039333aull,0x5f5f6d7261706164ull,0x6f66696e7530315aull,0x5366506464416d72ull,
0x6f6c625f6969695full,0x74657366664f6b63ull,0x6461090a3078302bull,0x2509203233752e64ull,
0x2c317225202c3572ull,0x2020203b34722520ull,0x202f2f0920202020ull,0x36752e747663090aull,
0x2509203233752e34ull,0x357225202c326472ull,0x202020202020203bull,0x756d090a202f2f09ull,
0x3436752e6f6c2e6cull,0x202c336472250920ull,0x3b34202c32647225ull,0x202f2f0920202020ull,
0x36752e646461090aull,0x2c34647225092034ull,0x25202c3164722520ull,0x202020203b336472ull,
0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3166250920323366ull,0x2b346472255b202cull,
0x202f2f09203b5d30ull,0x73090a30343a6469ull,0x6465726168732e74ull,0x755b09203233662eull,
0x316625202c5d696eull,0x2f2f09202020203bull,0x752033333a646920ull,0x240a3078302b696eull,
0x0a3a375f305f744cull,0x353109636f6c2e09ull,0x090a300936353209ull,0x636e79732e726162ull,
0x202020203b300920ull,0x2020202020202020ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0939353209353109ull,0x752e747663090a30ull,0x09203631752e3233ull,0x746e25202c367225ull,
0x2020203b782e6469ull,0x73090a202f2f0920ull,0x09203233622e6c68ull,0x367225202c377225ull,
0x202020203b31202cull,0x2f2f092020202020ull,0x34326c756d090a20ull,0x203233732e6f6c2eull,
0x7225202c38722509ull,0x203b377225202c31ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x3972250920323373ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x726f66696e753031ull,
0x5f5366506464416dull,0x657361625f696969ull,0x093b5d7865646e49ull,0x31343a6469202f2full,
0x70616475635f5f20ull,0x30315a5f5f6d7261ull,0x416d726f66696e75ull,0x69695f5366506464ull,
0x6e49657361625f69ull,0x0a3078302b786564ull,0x3233732e64646109ull,0x202c303172250920ull,
0x387225202c397225ull,0x092020202020203bull,0x646461090a202f2full,0x722509203233752eull,
0x30317225202c3131ull,0x20203b327225202cull,0x0a202f2f09202020ull,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5f5b202c356472ull,0x6d72617061647563ull,0x696e7530315a5f5full,
0x506464416d726f66ull,0x675f6969695f5366ull,0x093b5d617461645full,0x34333a6469202f2full,
0x70616475635f5f20ull,0x30315a5f5f6d7261ull,0x416d726f66696e75ull,0x69695f5366506464ull,
0x617461645f675f69ull,0x7663090a3078302bull,0x33752e3436752e74ull,0x2c36647225092032ull,
0x20203b3131722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x36647225202c3764ull,0x202020203b34202cull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x647225202c386472ull,0x3b37647225202c35ull,0x202f2f0920202020ull,0x6168732e646c090aull,
0x203233662e646572ull,0x755b202c32662509ull,0x202020203b5d696eull,0x333a6469202f2f09ull,
0x78302b696e752033ull,0x6c672e646c090a30ull,0x3233662e6c61626full,0x5b202c3366250920ull,
0x3b5d302b38647225ull,0x3a6469202f2f0920ull,0x2e646461090a3234ull,0x3466250920323366ull,
0x25202c336625202cull,0x20202020203b3266ull,0x090a202f2f092020ull,0x61626f6c672e7473ull,
0x5b09203233662e6cull,0x2c5d302b38647225ull,0x2f09203b34662520ull,0x0a33343a6469202full,
0x617261702e646c09ull,0x2509203233752e6dull,0x5f5f5b202c323172ull,0x6d72617061647563ull,
0x696e7530315a5f5full,0x506464416d726f66ull,0x6e5f6969695f5366ull,0x6469202f2f093b5dull,
0x75635f5f2034343aull,0x5f5f6d7261706164ull,0x6f66696e7530315aull,0x5366506464416d72ull,
0x302b6e5f6969695full,0x2e646461090a3078ull,0x3172250920323375ull,0x202c367225202c33ull,
0x202020203b327225ull,0x090a202f2f092020ull,0x2e656c2e70746573ull,0x3270250920323375ull,
0x202c32317225202cull,0x2f09203b33317225ull,0x32702540090a202full,0x4c24092061726220ull,
0x20203b395f305f74ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x61090a3009303632ull,0x09203233752e6464ull,0x7225202c34317225ull,0x3b367225202c3131ull,
0x2f2f092020202020ull,0x752e747663090a20ull,0x09203233752e3436ull,0x7225202c39647225ull,
0x20202020203b3431ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x3031647225092034ull,
0x202c39647225202cull,0x2f2f092020203b34ull,0x752e646461090a20ull,0x3164722509203436ull,
0x2c35647225202c31ull,0x203b303164722520ull,0x6c090a202f2f0920ull,0x6c61626f6c672e64ull,
0x662509203233662eull,0x316472255b202c35ull,0x2f2f093b5d302b31ull,0x090a35343a646920ull,
0x09353109636f6c2eull,0x6c090a3009393532ull,0x6465726168732e64ull,0x662509203233662eull,
0x5d696e755b202c32ull,0x2f2f09202020203bull,0x09636f6c2e090a20ull,0x3009303632093531ull,
0x33662e646461090aull,0x202c366625092032ull,0x326625202c356625ull,0x202020202020203bull,
0x7473090a202f2f09ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b313164ull,
0x202f2f093b366625ull,0x4c240a36343a6469ull,0x090a3a395f305f74ull,0x09353109636f6c2eull,
0x65090a3009313632ull,0x202020203b746978ull,0x2020202020202020ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x6e6557444c240a20ull,0x6e7530315a5f5f64ull,0x6464416d726f6669ull,
0x3a6969695f536650ull,0x5f202f2f207d090aull,0x6f66696e7530315aull,0x5366506464416d72ull,
0x2e090a0a6969695full,0x5a5f207972746e65ull,0x6e61637365727037ull,0x30624c4531624c49ull,
0x664b506650764545ull,0x090a6969695f3053ull,0x206765722e090a7bull,0x3c7225203233752eull,
0x722e090a3b3e3435ull,0x203436752e206765ull,0x3b3e38333c647225ull,0x2e206765722e090aull,
0x313c662520323366ull,0x65722e090a3b3e35ull,0x20646572702e2067ull,0x0a3b3e31313c7025ull,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x6373657270375a5full,
0x4c4531624c496e61ull,0x5066507645453062ull,0x6969695f3053664bull,0x617461646f5f675full,
0x617261702e090a3bull,0x5f203436752e206dull,0x726170616475635full,0x657270375a5f5f6dull,
0x31624c496e616373ull,0x5076454530624c45ull,0x695f3053664b5066ull,0x6164695f675f6969ull,
0x61702e090a3b6174ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x70375a5f5f6d7261ull,
0x4c496e6163736572ull,0x454530624c453162ull,0x3053664b50665076ull,0x625f675f6969695full,
0x736d75536b636f6cull,0x617261702e090a3bull,0x5f203233732e206dull,0x726170616475635full,
0x657270375a5f5f6dull,0x31624c496e616373ull,0x5076454530624c45ull,0x695f3053664b5066ull,
0x2e090a3b6e5f6969ull,0x732e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,
0x6e61637365727037ull,0x30624c4531624c49ull,0x664b506650764545ull,0x625f6969695f3053ull,
0x65646e496b636f6cull,0x7261702e090a3b78ull,0x203233732e206d61ull,0x6170616475635f5full,
0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454530624c4531ull,0x5f3053664b506650ull,
0x657361625f696969ull,0x090a3b7865646e49ull,0x09353109636f6c2eull,0x4c240a3009343232ull,
0x70375a5f5f314242ull,0x4c496e6163736572ull,0x454530624c453162ull,0x3053664b50665076ull,
0x2e090a3a6969695full,0x3209353109636f6cull,0x7663090a30093033ull,0x31752e3233752e74ull,
0x202c317225092036ull,0x3b782e6469746e25ull,0x202f2f0920202020ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5f5b202c327225ull,0x6d72617061647563ull,0x73657270375a5f5full,
0x4531624c496e6163ull,0x665076454530624cull,0x69695f3053664b50ull,0x6e49657361625f69ull,
0x2f2f093b5d786564ull,0x203038313a646920ull,0x6170616475635f5full,0x7270375a5f5f6d72ull,
0x624c496e61637365ull,0x76454530624c4531ull,0x5f3053664b506650ull,0x657361625f696969ull,
0x78302b7865646e49ull,0x752e766f6d090a30ull,0x2c33722509203233ull,0x20202020203b3020ull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x732e656e2e707465ull,0x2c31702509203233ull,
0x7225202c32722520ull,0x2f2f092020203b33ull,0x2031702540090a20ull,0x744c240920617262ull,
0x20203b30345f315full,0x2020202020202020ull,0x63090a202f2f0920ull,0x752e3233732e7476ull,
0x2c34722509203631ull,0x2e64696174632520ull,0x2f2f092020203b78ull,0x622e6c6873090a20ull,
0x2c35722509203233ull,0x3b31202c31722520ull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x2e6f6c2e34326c75ull,0x3672250920323373ull,0x25202c347225202cull,0x2f2f0920203b3572ull,
0x752e617262090a20ull,0x5f744c240920696eull,0x2020203b39335f31ull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x0a3a30345f315f74ull,0x3233732e766f6d09ull,0x25202c3672250920ull,
0x20202020203b3272ull,0x0920202020202020ull,0x5f744c240a202f2full,0x6d090a3a39335f31ull,
0x09203436752e766full,0x5f73202c31647225ull,0x2020203b61746164ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x0a30093639093531ull,0x3233732e74766309ull,0x722509203631752eull,
0x2e64697425202c37ull,0x0920202020203b78ull,0x646461090a202f2full,0x722509203233752eull,
0x202c367225202c38ull,0x202020203b377225ull,0x0a202f2f09202020ull,0x3436752e74766309ull,
0x722509203233732eull,0x3b387225202c3264ull,0x0920202020202020ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x25202c3364722509ull,0x203b34202c326472ull,0x0a202f2f09202020ull,
0x3233732e72687309ull,0x25202c3972250920ull,0x20203b34202c3772ull,0x0920202020202020ull,
0x646461090a202f2full,0x722509203233732eull,0x2c377225202c3031ull,0x2020203b39722520ull,
0x0a202f2f09202020ull,0x3436732e74766309ull,0x722509203233732eull,0x30317225202c3464ull,
0x092020202020203bull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x25202c3564722509ull,
0x203b34202c346472ull,0x0a202f2f09202020ull,0x3436752e64646109ull,0x202c366472250920ull,
0x7225202c31647225ull,0x09202020203b3564ull,0x2e646c090a202f2full,0x36752e6d61726170ull,
0x2c37647225092034ull,0x616475635f5f5b20ull,0x375a5f5f6d726170ull,0x496e616373657270ull,
0x4530624c4531624cull,0x53664b5066507645ull,0x5f675f6969695f30ull,0x093b5d6174616469ull,
0x37313a6469202f2full,0x616475635f5f2038ull,0x375a5f5f6d726170ull,0x496e616373657270ull,
0x4530624c4531624cull,0x53664b5066507645ull,0x5f675f6969695f30ull,0x78302b6174616469ull,
0x752e646461090a30ull,0x3864722509203436ull,0x202c33647225202cull,0x2020203b37647225ull,
0x6c090a202f2f0920ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x386472255b202c31ull,
0x2f2f09203b5d302bull,0x0a3238313a646920ull,0x726168732e747309ull,0x09203233662e6465ull,
0x5d302b366472255bull,0x09203b316625202cull,0x38313a6469202f2full,0x617461645f732033ull,
0x6c2e090a3078302bull,0x303109353109636full,0x646461090a300934ull,0x722509203233752eull,
0x2c377225202c3131ull,0x2020203b31722520ull,0x0a202f2f09202020ull,0x3233752e64646109ull,
0x202c323172250920ull,0x317225202c387225ull,0x092020202020203bull,0x747663090a202f2full,
0x3233732e3436752eull,0x202c396472250920ull,0x2020203b32317225ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x39647225202c3031ull,0x092020203b34202cull,
0x726873090a202f2full,0x722509203233732eull,0x31317225202c3331ull,0x202020203b34202cull,
0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c343172250920ull,0x7225202c31317225ull,
0x09202020203b3331ull,0x747663090a202f2full,0x3233732e3436732eull,0x2c31316472250920ull,
0x20203b3431722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3231ull,0x0920203b34202c31ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c333164ull,0x3231647225202c31ull,0x0a202f2f0920203bull,0x3436752e64646109ull,
0x2c34316472250920ull,0x202c303164722520ull,0x0920203b37647225ull,0x2e646c090a202f2full,
0x662e6c61626f6c67ull,0x2c32662509203233ull,0x2b34316472255b20ull,0x69202f2f093b5d30ull,
0x73090a3438313a64ull,0x6465726168732e74ull,0x255b09203233662eull,0x2c5d302b33316472ull,
0x2f2f093b32662520ull,0x203538313a646920ull,0x302b617461645f73ull,0x636f6c2e090a3078ull,
0x0930363109353109ull,0x732e766f6d090a30ull,0x3531722509203233ull,0x20203b317225202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c36317225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e656cull,
0x317225202c327025ull,0x203b36317225202cull,0x6d090a202f2f0920ull,0x09203233752e766full,
0x3b31202c37317225ull,0x2020202020202020ull,0x2f2f092020202020ull,0x2032702540090a20ull,
0x744c240920617262ull,0x20203b35355f315full,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x0a3a33345f315f74ull,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x6c2e090a32363120ull,0x363109353109636full,0x726162090a300932ull,0x300920636e79732eull,
0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,0x65672e7074657309ull,
0x702509203233752eull,0x202c377225202c33ull,0x0920203b35317225ull,0x702540090a202f2full,
0x2409206172622033ull,0x3b34345f315f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c32363120ull,0x6c6562616c206461ull,0x315f744c24206465ull,0x6f6c2e090a33345full,
0x3337310935310963ull,0x2e766f6d090a3009ull,0x3172250920323373ull,0x2020203b32202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x38317225202c3931ull,0x093b37317225202cull,0x6c756d090a202f2full,0x33732e6f6c2e3432ull,
0x2c30327225092032ull,0x25202c3931722520ull,0x0a202f2f093b3772ull,0x3233752e64646109ull,
0x202c313272250920ull,0x7225202c30327225ull,0x09202020203b3731ull,0x646461090a202f2full,
0x722509203233752eull,0x31327225202c3232ull,0x203b37317225202cull,0x0a202f2f09202020ull,
0x3233732e62757309ull,0x202c333272250920ull,0x3b31202c32327225ull,0x0920202020202020ull,
0x726873090a202f2full,0x722509203233732eull,0x33327225202c3432ull,0x202020203b34202cull,
0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c353272250920ull,0x7225202c32327225ull,
0x09202020203b3432ull,0x747663090a202f2full,0x3233732e3436752eull,0x2c35316472250920ull,
0x20203b3532722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3631ull,0x0920203b34202c35ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c373164ull,0x3631647225202c31ull,0x0a202f2f0920203bull,0x726168732e646c09ull,
0x09203233662e6465ull,0x72255b202c336625ull,0x3b5d342d2b373164ull,0x313a6469202f2f09ull,
0x7461645f73203738ull,0x73090a3078302b61ull,0x09203233732e6275ull,0x7225202c36327225ull,
0x20203b31202c3132ull,0x2f2f092020202020ull,0x732e726873090a20ull,0x3732722509203233ull,
0x202c36327225202cull,0x2020202020203b34ull,0x61090a202f2f0920ull,0x09203233732e6464ull,
0x7225202c38327225ull,0x37327225202c3132ull,0x2f2f09202020203bull,0x752e747663090a20ull,
0x09203233732e3436ull,0x25202c3831647225ull,0x202020203b383272ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3931647225092034ull,0x2c3831647225202cull,0x2f2f0920203b3420ull,
0x752e646461090a20ull,0x3264722509203436ull,0x2c31647225202c30ull,0x203b393164722520ull,
0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203233662eull,0x326472255b202c34ull,
0x2f093b5d342d2b30ull,0x3638313a6469202full,0x2b617461645f7320ull,0x646461090a307830ull,
0x662509203233662eull,0x202c336625202c35ull,0x202020203b346625ull,0x0a202f2f09202020ull,
0x726168732e747309ull,0x09203233662e6465ull,0x2d2b37316472255bull,0x3b356625202c5d34ull,
0x313a6469202f2f09ull,0x7461645f73203838ull,0x4c240a3078302b61ull,0x0a3a34345f315f74ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c32363120ull,0x6c6562616c206461ull,0x315f744c24206465ull,0x6f6c2e090a33345full,
0x3637310935310963ull,0x2e6c756d090a3009ull,0x09203233752e6f6cull,0x7225202c37317225ull,
0x20203b32202c3731ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009303631ull,
0x09203233732e7268ull,0x7225202c35317225ull,0x20203b31202c3531ull,0x2f2f092020202020ull,
0x752e766f6d090a20ull,0x3932722509203233ull,0x202020203b30202cull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e74672e707465ull,0x2c34702509203233ull,0x25202c3531722520ull,
0x2f2f09203b393272ull,0x2034702540090a20ull,0x744c240920617262ull,0x20203b33345f315full,
0x2020202020202020ull,0x62090a202f2f0920ull,0x0920696e752e6172ull,0x31345f315f744c24ull,
0x202020202020203bull,0x2f2f092020202020ull,0x5f315f744c240a20ull,0x5f744c240a3a3535ull,
0x2e090a3a31345f31ull,0x3209353109636f6cull,0x6f6d090a30093331ull,0x2509203233752e76ull,
0x203b30202c303372ull,0x2020202020202020ull,0x202f2f0920202020ull,0x6e2e70746573090aull,
0x2509203233752e65ull,0x2c377225202c3570ull,0x20203b3033722520ull,0x2540090a202f2f09ull,
0x0920617262203570ull,0x37345f315f744c24ull,0x202020202020203bull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093434310935ull,0x3233622e6c687309ull,0x202c313372250920ull,
0x203b31202c317225ull,0x0920202020202020ull,0x627573090a202f2full,0x722509203233732eull,
0x31337225202c3233ull,0x202020203b31202cull,0x0a202f2f09202020ull,0x3233732e72687309ull,
0x202c333372250920ull,0x3b34202c32337225ull,0x0920202020202020ull,0x646461090a202f2full,
0x722509203233732eull,0x31337225202c3433ull,0x203b33337225202cull,0x0a202f2f09202020ull,
0x3436752e74766309ull,0x722509203233732eull,0x337225202c313264ull,0x0920202020203b34ull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c323264722509ull,0x34202c3132647225ull,
0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c33326472250920ull,0x25202c3164722520ull,
0x0920203b32326472ull,0x2e646c090a202f2full,0x33732e6d61726170ull,0x2c35337225092032ull,
0x616475635f5f5b20ull,0x375a5f5f6d726170ull,0x496e616373657270ull,0x4530624c4531624cull,
0x53664b5066507645ull,0x6c625f6969695f30ull,0x7865646e496b636full,0x6469202f2f093b5dull,
0x635f5f203337313aull,0x5f6d726170616475ull,0x6373657270375a5full,0x4c4531624c496e61ull,
0x5066507645453062ull,0x6969695f3053664bull,0x6e496b636f6c625full,0x0a3078302b786564ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x72255b202c366625ull,0x3b5d342d2b333264ull,
0x313a6469202f2f09ull,0x7461645f73203938ull,0x6c090a3078302b61ull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x635f5f5b202c3432ull,0x5f6d726170616475ull,0x6373657270375a5full,
0x4c4531624c496e61ull,0x5066507645453062ull,0x6969695f3053664bull,0x6b636f6c625f675full,
0x2f093b5d736d7553ull,0x3039313a6469202full,0x70616475635f5f20ull,0x70375a5f5f6d7261ull,
0x4c496e6163736572ull,0x454530624c453162ull,0x3053664b50665076ull,0x625f675f6969695full,
0x736d75536b636f6cull,0x7663090a3078302bull,0x31752e3233732e74ull,0x2c36337225092036ull,
0x2e64696174632520ull,0x202f2f0920203b78ull,0x33732e766f6d090aull,0x2c37337225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e71652e7074ull,
0x202c367025092032ull,0x7225202c35337225ull,0x202f2f09203b3733ull,0x732e706c6573090aull,
0x3833722509203233ull,0x202c36337225202cull,0x7025202c35337225ull,0x090a202f2f093b36ull,
0x2e3436752e747663ull,0x6472250920323373ull,0x38337225202c3532ull,0x2f0920202020203bull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3632647225ull,0x3b34202c35326472ull,
0x090a202f2f092020ull,0x203436752e646461ull,0x202c373264722509ull,0x25202c3432647225ull,
0x2f09203b36326472ull,0x672e7473090a202full,0x33662e6c61626f6cull,0x326472255b092032ull,
0x6625202c5d302b37ull,0x6469202f2f093b36ull,0x6c2e090a3139313aull,0x343109353109636full,
0x766f6d090a300938ull,0x662509203233662eull,0x3030306630202c37ull,0x20203b3030303030ull,
0x30202f2f09202020ull,0x6168732e7473090aull,0x203233662e646572ull,0x2b33326472255b09ull,
0x376625202c5d342dull,0x3a6469202f2f093bull,0x61645f7320323931ull,0x240a3078302b6174ull,
0x3a37345f315f744cull,0x3109636f6c2e090aull,0x0a30093531320935ull,0x3233732e766f6d09ull,
0x202c393372250920ull,0x2020203b37317225ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x722509203233752eull,0x20203b31202c3034ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x746c2e7074657309ull,0x702509203233752eull,0x202c317225202c37ull,0x0920203b30347225ull,
0x702540090a202f2full,0x2409206172622037ull,0x3b39345f315f744cull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c313472250920ull,0x2020202020203b31ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x2f200a3a31355f31ull,0x203e706f6f6c3c2full,
0x646f6220706f6f4cull,0x3220656e696c2079ull,0x7473656e202c3531ull,0x7470656420676e69ull,
0x7365202c31203a68ull,0x20646574616d6974ull,0x6f69746172657469ull,0x6e6b6e75203a736eull,
0x6f6c2e090a6e776full,0x3938310935310963ull,0x2e726873090a3009ull,0x3372250920323375ull,
0x2c39337225202c39ull,0x20202020203b3120ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x62090a3009313931ull,0x20636e79732e7261ull,0x20202020203b3009ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233752e656cull,0x347225202c387025ull,
0x203b377225202c31ull,0x40090a202f2f0920ull,0x2061726220387025ull,0x355f315f744c2409ull,
0x2020202020203b32ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35313220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x2e090a31355f315full,0x3209353109636f6cull,0x6f6d090a30093230ull,
0x2509203233732e76ull,0x203b32202c323472ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x2e34326c756d090aull,0x09203233732e6f6cull,0x7225202c33347225ull,0x39337225202c3234ull,
0x6d090a202f2f093bull,0x2e6f6c2e34326c75ull,0x3472250920323373ull,0x2c33347225202c34ull,
0x2f2f093b37722520ull,0x752e646461090a20ull,0x3534722509203233ull,0x202c34347225202cull,
0x2020203b39337225ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c36347225ull,
0x20203b31202c3534ull,0x2f2f092020202020ull,0x732e726873090a20ull,0x3734722509203233ull,
0x202c36347225202cull,0x2020202020203b34ull,0x61090a202f2f0920ull,0x09203233732e6464ull,
0x7225202c38347225ull,0x37347225202c3534ull,0x2f2f09202020203bull,0x752e747663090a20ull,
0x09203233732e3436ull,0x25202c3832647225ull,0x202020203b383472ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3932647225092034ull,0x2c3832647225202cull,0x2f2f0920203b3420ull,
0x752e646461090a20ull,0x3364722509203436ull,0x2c31647225202c30ull,0x203b393264722520ull,
0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203233662eull,0x336472255b202c38ull,
0x2f093b5d342d2b30ull,0x3339313a6469202full,0x2b617461645f7320ull,0x6f6c2e090a307830ull,
0x3330320935310963ull,0x2e646461090a3009ull,0x3472250920323375ull,0x2c35347225202c39ull,
0x20203b3933722520ull,0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3035722509ull,
0x203b31202c393472ull,0x2f09202020202020ull,0x2e726873090a202full,0x3572250920323373ull,
0x2c30357225202c31ull,0x20202020203b3420ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x25202c3235722509ull,0x357225202c393472ull,0x2f09202020203b31ull,0x2e747663090a202full,
0x203233732e343675ull,0x202c313364722509ull,0x2020203b32357225ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3364722509203436ull,0x3133647225202c32ull,0x2f0920203b34202cull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3333ull,0x3b3233647225202cull,
0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233662e64ull,0x6472255b202c3966ull,
0x093b5d342d2b3333ull,0x39313a6469202f2full,0x617461645f732034ull,0x7473090a3078302bull,
0x2e6465726168732eull,0x72255b0920323366ull,0x2c5d342d2b303364ull,0x2f2f093b39662520ull,
0x203539313a646920ull,0x302b617461645f73ull,0x636f6c2e090a3078ull,0x0934303209353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c303166250920ull,0x2d2b33336472255bull,
0x69202f2f093b5d34ull,0x5f73203639313a64ull,0x3078302b61746164ull,0x33662e646461090aull,
0x2c31316625092032ull,0x25202c3031662520ull,0x20202020203b3866ull,0x7473090a202f2f09ull,
0x2e6465726168732eull,0x72255b0920323366ull,0x2c5d342d2b333364ull,0x2f093b3131662520ull,
0x3739313a6469202full,0x2b617461645f7320ull,0x5f744c240a307830ull,0x2f200a3a32355f31ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3531ull,0x64656c6562616c20ull,0x355f315f744c2420ull,0x09636f6c2e090a31ull,
0x3009373831093531ull,0x2e34326c756d090aull,0x09203233732e6f6cull,0x7225202c31347225ull,
0x20203b32202c3134ull,0x6573090a202f2f09ull,0x33752e656c2e7074ull,0x202c397025092032ull,
0x7225202c31347225ull,0x202f2f0920203b31ull,0x622039702540090aull,0x5f744c2409206172ull,
0x2020203b31355f31ull,0x2020202020202020ull,0x744c240a202f2f09ull,0x090a3a39345f315full,
0x09353109636f6c2eull,0x62090a3009363131ull,0x20636e79732e7261ull,0x20202020203b3009ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009393131093531ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5b202c3433647225ull,0x6170616475635f5full,
0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454530624c4531ull,0x5f3053664b506650ull,
0x646f5f675f696969ull,0x2f2f093b5d617461ull,0x203437313a646920ull,0x6170616475635f5full,
0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454530624c4531ull,0x5f3053664b506650ull,
0x646f5f675f696969ull,0x0a3078302b617461ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c32316625ull,0x093b5d302b366472ull,0x39313a6469202f2full,0x617461645f732038ull,
0x6461090a3078302bull,0x2509203436752e64ull,0x7225202c35336472ull,0x33647225202c3364ull,
0x202f2f0920203b34ull,0x6f6c672e7473090aull,0x203233662e6c6162ull,0x2b35336472255b09ull,
0x32316625202c5d30ull,0x3a6469202f2f093bull,0x6f6c2e090a393931ull,0x3732310935310963ull,
0x732e646c090a3009ull,0x33662e6465726168ull,0x2c33316625092032ull,0x2b33316472255b20ull,
0x69202f2f093b5d30ull,0x5f73203030323a64ull,0x3078302b61746164ull,0x36752e646461090aull,
0x3633647225092034ull,0x2c3031647225202cull,0x203b343364722520ull,0x7473090a202f2f09ull,
0x2e6c61626f6c672eull,0x72255b0920323366ull,0x202c5d302b363364ull,0x2f2f093b33316625ull,
0x0a3130323a646920ull,0x353109636f6c2e09ull,0x090a300931343209ull,0x2020203b74697865ull,
0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,0x6557444c240a202full,
0x7270375a5f5f646eull,0x624c496e61637365ull,0x76454530624c4531ull,0x5f3053664b506650ull,
0x207d090a3a696969ull,0x7270375a5f202f2full,0x624c496e61637365ull,0x76454530624c4531ull,
0x5f3053664b506650ull,0x652e090a0a696969ull,0x375a5f207972746eull,0x496e616373657270ull,
0x4531624c4531624cull,0x53664b5066507645ull,0x7b090a6969695f30ull,0x2e206765722e090aull,
0x353c722520323375ull,0x65722e090a3b3e36ull,0x25203436752e2067ull,0x0a3b3e30343c6472ull,
0x662e206765722e09ull,0x35313c6625203233ull,0x6765722e090a3b3eull,0x2520646572702e20ull,
0x090a3b3e32313c70ull,0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,
0x616373657270375aull,0x624c4531624c496eull,0x4b50665076454531ull,0x5f6969695f305366ull,
0x3b617461646f5f67ull,0x6d617261702e090aull,0x5f5f203436752e20ull,0x6d72617061647563ull,
0x73657270375a5f5full,0x4531624c496e6163ull,0x665076454531624cull,0x69695f3053664b50ull,
0x746164695f675f69ull,0x7261702e090a3b61ull,0x203436752e206d61ull,0x6170616475635f5full,
0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454531624c4531ull,0x5f3053664b506650ull,
0x6c625f675f696969ull,0x3b736d75536b636full,0x6d617261702e090aull,0x5f5f203233732e20ull,
0x6d72617061647563ull,0x73657270375a5f5full,0x4531624c496e6163ull,0x665076454531624cull,
0x69695f3053664b50ull,0x702e090a3b6e5f69ull,0x33732e206d617261ull,0x616475635f5f2032ull,
0x375a5f5f6d726170ull,0x496e616373657270ull,0x4531624c4531624cull,0x53664b5066507645ull,
0x6c625f6969695f30ull,0x7865646e496b636full,0x617261702e090a3bull,0x5f203233732e206dull,
0x726170616475635full,0x657270375a5f5f6dull,0x31624c496e616373ull,0x5076454531624c45ull,
0x695f3053664b5066ull,0x49657361625f6969ull,0x2e090a3b7865646eull,0x3209353109636f6cull,
0x424c240a30093432ull,0x7270375a5f5f3142ull,0x624c496e61637365ull,0x76454531624c4531ull,
0x5f3053664b506650ull,0x6c2e090a3a696969ull,0x333209353109636full,0x747663090a300930ull,
0x3631752e3233752eull,0x25202c3172250920ull,0x203b782e6469746eull,0x0a202f2f09202020ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3272ull,0x5f6d726170616475ull,
0x6373657270375a5full,0x4c4531624c496e61ull,0x5066507645453162ull,0x6969695f3053664bull,
0x646e49657361625full,0x202f2f093b5d7865ull,0x5f203838313a6469ull,0x726170616475635full,
0x657270375a5f5f6dull,0x31624c496e616373ull,0x5076454531624c45ull,0x695f3053664b5066ull,
0x49657361625f6969ull,0x3078302b7865646eull,0x33752e766f6d090aull,0x202c337225092032ull,
0x2020202020203b30ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e656e2e7074ull,
0x202c317025092032ull,0x337225202c327225ull,0x202f2f092020203bull,0x622031702540090aull,
0x5f744c2409206172ull,0x2020203b30345f32ull,0x2020202020202020ull,0x7663090a202f2f09ull,
0x31752e3233732e74ull,0x202c347225092036ull,0x782e646961746325ull,0x202f2f092020203bull,
0x33622e6c6873090aull,0x202c357225092032ull,0x203b31202c317225ull,0x2020202020202020ull,
0x756d090a202f2f09ull,0x732e6f6c2e34326cull,0x2c36722509203233ull,0x7225202c34722520ull,
0x202f2f0920203b35ull,0x6e752e617262090aull,0x325f744c24092069ull,0x202020203b39335full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x090a3a30345f325full,0x203233732e766f6dull,
0x7225202c36722509ull,0x2020202020203b32ull,0x2f09202020202020ull,0x325f744c240a202full,
0x6f6d090a3a39335full,0x2509203436752e76ull,0x645f73202c316472ull,0x202020203b617461ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300936390935ull,0x2e3233732e747663ull,
0x3772250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,0x2e646461090a202full,
0x3872250920323375ull,0x25202c367225202cull,0x20202020203b3772ull,0x090a202f2f092020ull,
0x2e3436752e747663ull,0x6472250920323373ull,0x203b387225202c32ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c33647225ull,0x20203b34202c3264ull,
0x090a202f2f092020ull,0x203233732e726873ull,0x7225202c39722509ull,0x2020203b34202c37ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3172250920323373ull,0x202c377225202c30ull,
0x202020203b397225ull,0x090a202f2f092020ull,0x2e3436732e747663ull,0x6472250920323373ull,
0x3b30317225202c34ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x7225202c35647225ull,0x20203b34202c3464ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x25202c3664722509ull,0x647225202c316472ull,0x2f09202020203b35ull,0x702e646c090a202full,
0x3436752e6d617261ull,0x202c376472250920ull,0x70616475635f5f5bull,0x70375a5f5f6d7261ull,
0x4c496e6163736572ull,0x454531624c453162ull,0x3053664b50665076ull,0x695f675f6969695full,
0x2f093b5d61746164ull,0x3638313a6469202full,0x70616475635f5f20ull,0x70375a5f5f6d7261ull,
0x4c496e6163736572ull,0x454531624c453162ull,0x3053664b50665076ull,0x695f675f6969695full,
0x3078302b61746164ull,0x36752e646461090aull,0x2c38647225092034ull,0x25202c3364722520ull,
0x202020203b376472ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3166250920323366ull,
0x2b386472255b202cull,0x202f2f09203b5d30ull,0x090a3039313a6469ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x2c5d302b36647225ull,0x2f09203b31662520ull,0x3139313a6469202full,
0x2b617461645f7320ull,0x646461090a307830ull,0x722509203233752eull,0x2c377225202c3131ull,
0x2020203b31722520ull,0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203233732e6dull,
0x5f5f5b202c323172ull,0x6d72617061647563ull,0x73657270375a5f5full,0x4531624c496e6163ull,
0x665076454531624cull,0x69695f3053664b50ull,0x2f2f093b5d6e5f69ull,0x203239313a646920ull,
0x6170616475635f5full,0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454531624c4531ull,
0x5f3053664b506650ull,0x78302b6e5f696969ull,0x2e70746573090a30ull,0x09203233732e7467ull,
0x317225202c327025ull,0x3b31317225202c32ull,0x40090a202f2f0920ull,0x6172622032702521ull,
0x5f325f744c240920ull,0x20202020203b3234ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009303031093531ull,0x33752e646461090aull,0x2c33317225092032ull,0x7225202c38722520ull,
0x2020202020203b31ull,0x7663090a202f2f09ull,0x33732e3436752e74ull,0x2c39647225092032ull,
0x20203b3331722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c303164ull,0x2020203b34202c39ull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x7225202c31316472ull,0x31647225202c3764ull,0x202f2f0920203b30ull,0x6f6c672e646c090aull,
0x203233662e6c6162ull,0x255b202c32662509ull,0x3b5d302b31316472ull,0x313a6469202f2f09ull,
0x2e617262090a3339ull,0x744c240920696e75ull,0x20203b31345f325full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3a32345f325f744cull,0x33662e766f6d090aull,0x202c326625092032ull,
0x3030303030306630ull,0x20202020203b3030ull,0x4c240a30202f2f09ull,0x0a3a31345f325f74ull,
0x3233732e72687309ull,0x202c343172250920ull,0x3b34202c31317225ull,0x0920202020202020ull,
0x646461090a202f2full,0x722509203233732eull,0x31317225202c3531ull,0x203b34317225202cull,
0x0a202f2f09202020ull,0x3436732e74766309ull,0x722509203233732eull,0x317225202c323164ull,
0x0920202020203b35ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c333164722509ull,
0x34202c3231647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c34316472250920ull,
0x25202c3164722520ull,0x0920203b33316472ull,0x2e7473090a202f2full,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3431ull,0x69202f2f093b3266ull,0x5f73203439313a64ull,
0x3078302b61746164ull,0x3109636f6c2e090aull,0x0a30093036310935ull,0x3233732e766f6d09ull,
0x202c363172250920ull,0x202020203b317225ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x722509203233752eull,0x20203b30202c3731ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x656c2e7074657309ull,0x702509203233732eull,0x202c317225202c33ull,0x0920203b37317225ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b31202c3831ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x7262203370254009ull,0x325f744c24092061ull,0x202020203b39355full,
0x0920202020202020ull,0x5f744c240a202f2full,0x2f200a3a35345f32ull,0x203e706f6f6c3c2full,
0x646f6220706f6f4cull,0x3120656e696c2079ull,0x636f6c2e090a3236ull,0x0932363109353109ull,
0x732e726162090a30ull,0x203b300920636e79ull,0x2020202020202020ull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x752e65672e707465ull,0x2c34702509203233ull,0x7225202c37722520ull,
0x2f2f0920203b3631ull,0x2034702540090a20ull,0x744c240920617262ull,0x20203b36345f325full,
0x2020202020202020ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3236ull,0x64656c6562616c20ull,
0x345f325f744c2420ull,0x09636f6c2e090a35ull,0x3009333731093531ull,0x33732e766f6d090aull,
0x2c39317225092032ull,0x20202020203b3220ull,0x2020202020202020ull,0x756d090a202f2f09ull,
0x732e6f6c2e34326cull,0x3032722509203233ull,0x202c39317225202cull,0x2f2f093b38317225ull,
0x34326c756d090a20ull,0x203233732e6f6c2eull,0x25202c3132722509ull,0x377225202c303272ull,
0x61090a202f2f093bull,0x09203233752e6464ull,0x7225202c32327225ull,0x38317225202c3132ull,
0x2f2f09202020203bull,0x752e646461090a20ull,0x3332722509203233ull,0x202c32327225202cull,
0x2020203b38317225ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c34327225ull,
0x20203b31202c3332ull,0x2f2f092020202020ull,0x732e726873090a20ull,0x3532722509203233ull,
0x202c34327225202cull,0x2020202020203b34ull,0x61090a202f2f0920ull,0x09203233732e6464ull,
0x7225202c36327225ull,0x35327225202c3332ull,0x2f2f09202020203bull,0x752e747663090a20ull,
0x09203233732e3436ull,0x25202c3531647225ull,0x202020203b363272ull,0x6d090a202f2f0920ull,
0x36752e6f6c2e6c75ull,0x3631647225092034ull,0x2c3531647225202cull,0x2f2f0920203b3420ull,
0x752e646461090a20ull,0x3164722509203436ull,0x2c31647225202c37ull,0x203b363164722520ull,
0x6c090a202f2f0920ull,0x6465726168732e64ull,0x662509203233662eull,0x316472255b202c33ull,
0x2f093b5d342d2b37ull,0x3639313a6469202full,0x2b617461645f7320ull,0x627573090a307830ull,
0x722509203233732eull,0x32327225202c3732ull,0x202020203b31202cull,0x0a202f2f09202020ull,
0x3233732e72687309ull,0x202c383272250920ull,0x3b34202c37327225ull,0x0920202020202020ull,
0x646461090a202f2full,0x722509203233732eull,0x32327225202c3932ull,0x203b38327225202cull,
0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233732eull,0x327225202c383164ull,
0x0920202020203b39ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c393164722509ull,
0x34202c3831647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c30326472250920ull,
0x25202c3164722520ull,0x0920203b39316472ull,0x2e646c090a202f2full,0x662e646572616873ull,
0x2c34662509203233ull,0x2b30326472255b20ull,0x202f2f093b5d342dull,0x73203539313a6469ull,
0x78302b617461645full,0x662e646461090a30ull,0x2c35662509203233ull,0x6625202c33662520ull,
0x2020202020203b34ull,0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203233662eull,
0x5d342d2b37316472ull,0x2f093b356625202cull,0x3739313a6469202full,0x2b617461645f7320ull,
0x5f744c240a307830ull,0x2f200a3a36345f32ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3236ull,0x64656c6562616c20ull,
0x345f325f744c2420ull,0x09636f6c2e090a35ull,0x3009363731093531ull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x38317225202c3831ull,0x202020203b32202cull,0x6c2e090a202f2f09ull,
0x363109353109636full,0x726873090a300930ull,0x722509203233732eull,0x36317225202c3631ull,
0x202020203b31202cull,0x0a202f2f09202020ull,0x3233752e766f6d09ull,0x202c303372250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x746573090a202f2full,0x3233732e74672e70ull,
0x25202c3570250920ull,0x337225202c363172ull,0x0a202f2f09203b30ull,0x7262203570254009ull,
0x325f744c24092061ull,0x202020203b35345full,0x0920202020202020ull,0x617262090a202f2full,
0x4c240920696e752eull,0x203b33345f325f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x39355f325f744c24ull,0x5f325f744c240a3aull,0x6f6c2e090a3a3334ull,0x3331320935310963ull,
0x2e766f6d090a3009ull,0x3372250920323375ull,0x2020203b30202c31ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e656e2e70746573ull,0x3670250920323375ull,0x25202c377225202cull,
0x2f0920203b313372ull,0x36702540090a202full,0x4c24092061726220ull,0x203b39345f325f74ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009343431ull,
0x09203233622e6c68ull,0x7225202c32337225ull,0x2020203b31202c31ull,0x2f2f092020202020ull,
0x732e627573090a20ull,0x3333722509203233ull,0x202c32337225202cull,0x2020202020203b31ull,
0x73090a202f2f0920ull,0x09203233732e7268ull,0x7225202c34337225ull,0x20203b34202c3333ull,
0x2f2f092020202020ull,0x732e646461090a20ull,0x3533722509203233ull,0x202c32337225202cull,
0x2020203b34337225ull,0x63090a202f2f0920ull,0x732e3436752e7476ull,0x3264722509203233ull,
0x3b35337225202c31ull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,
0x7225202c32326472ull,0x203b34202c313264ull,0x61090a202f2f0920ull,0x09203436752e6464ull,
0x25202c3332647225ull,0x647225202c316472ull,0x2f2f0920203b3232ull,0x61702e646c090a20ull,
0x203233732e6d6172ull,0x5b202c3633722509ull,0x6170616475635f5full,0x7270375a5f5f6d72ull,
0x624c496e61637365ull,0x76454531624c4531ull,0x5f3053664b506650ull,0x636f6c625f696969ull,
0x3b5d7865646e496bull,0x313a6469202f2f09ull,0x6475635f5f203138ull,0x5a5f5f6d72617061ull,
0x6e61637365727037ull,0x31624c4531624c49ull,0x664b506650764545ull,0x625f6969695f3053ull,
0x65646e496b636f6cull,0x6c090a3078302b78ull,0x6465726168732e64ull,0x662509203233662eull,
0x326472255b202c36ull,0x2f093b5d342d2b33ull,0x3839313a6469202full,0x2b617461645f7320ull,
0x2e646c090a307830ull,0x36752e6d61726170ull,0x3432647225092034ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6e61637365727037ull,0x31624c4531624c49ull,0x664b506650764545ull,
0x675f6969695f3053ull,0x75536b636f6c625full,0x202f2f093b5d736dull,0x5f203939313a6469ull,
0x726170616475635full,0x657270375a5f5f6dull,0x31624c496e616373ull,0x5076454531624c45ull,
0x695f3053664b5066ull,0x6f6c625f675f6969ull,0x302b736d75536b63ull,0x2e747663090a3078ull,
0x203631752e323373ull,0x25202c3733722509ull,0x3b782e6469617463ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x30202c3833722509ull,0x202020202020203bull,0x2f09202020202020ull,
0x70746573090a202full,0x203233732e71652eull,0x7225202c37702509ull,0x38337225202c3633ull,
0x090a202f2f09203bull,0x3233732e706c6573ull,0x202c393372250920ull,0x7225202c37337225ull,
0x3b377025202c3633ull,0x7663090a202f2f09ull,0x33732e3436752e74ull,0x3532647225092032ull,
0x203b39337225202cull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c363264ull,0x20203b34202c3532ull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x7225202c37326472ull,0x647225202c343264ull,0x202f2f09203b3632ull,0x6f6c672e7473090aull,
0x203233662e6c6162ull,0x2b37326472255b09ull,0x3b366625202c5d30ull,0x323a6469202f2f09ull,
0x636f6c2e090a3030ull,0x0938343109353109ull,0x662e766f6d090a30ull,0x2c37662509203233ull,
0x3030303030663020ull,0x202020203b303030ull,0x090a30202f2f0920ull,0x65726168732e7473ull,
0x5b09203233662e64ull,0x342d2b3332647225ull,0x093b376625202c5dull,0x30323a6469202f2full,
0x617461645f732031ull,0x744c240a3078302bull,0x090a3a39345f325full,0x09353109636f6c2eull,
0x6d090a3009353132ull,0x09203233732e766full,0x7225202c30347225ull,0x20202020203b3831ull,
0x2f2f092020202020ull,0x752e766f6d090a20ull,0x3134722509203233ull,0x202020203b31202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x752e746c2e707465ull,0x2c38702509203233ull,
0x7225202c31722520ull,0x2f2f0920203b3134ull,0x2038702540090a20ull,0x744c240920617262ull,
0x20203b31355f325full,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x3b31202c32347225ull,0x2020202020202020ull,0x2f2f092020202020ull,0x5f325f744c240a20ull,
0x3c2f2f200a3a3335ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,0x35313220656e696cull,
0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,0x746920646574616dull,
0x736e6f6974617265ull,0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,0x3009393831093531ull,
0x33752e726873090aull,0x2c30347225092032ull,0x31202c3034722520ull,0x202020202020203bull,
0x6c2e090a202f2f09ull,0x393109353109636full,0x726162090a300931ull,0x300920636e79732eull,
0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,
0x702509203233752eull,0x2c32347225202c39ull,0x0920203b37722520ull,0x702540090a202f2full,
0x2409206172622039ull,0x3b34355f325f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35313220ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x6f6c2e090a33355full,
0x3230320935310963ull,0x2e766f6d090a3009ull,0x3472250920323373ull,0x2020203b32202c33ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x33347225202c3434ull,0x093b30347225202cull,0x6c756d090a202f2full,0x33732e6f6c2e3432ull,
0x2c35347225092032ull,0x25202c3434722520ull,0x0a202f2f093b3772ull,0x3233752e64646109ull,
0x202c363472250920ull,0x7225202c35347225ull,0x09202020203b3034ull,0x627573090a202f2full,
0x722509203233732eull,0x36347225202c3734ull,0x202020203b31202cull,0x0a202f2f09202020ull,
0x3233732e72687309ull,0x202c383472250920ull,0x3b34202c37347225ull,0x0920202020202020ull,
0x646461090a202f2full,0x722509203233732eull,0x36347225202c3934ull,0x203b38347225202cull,
0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233732eull,0x347225202c383264ull,
0x0920202020203b39ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c393264722509ull,
0x34202c3832647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c30336472250920ull,
0x25202c3164722520ull,0x0920203b39326472ull,0x2e646c090a202f2full,0x662e646572616873ull,
0x2c38662509203233ull,0x2b30336472255b20ull,0x202f2f093b5d342dull,0x73203230323a6469ull,
0x78302b617461645full,0x09636f6c2e090a30ull,0x3009333032093531ull,0x33752e646461090aull,
0x2c30357225092032ull,0x25202c3634722520ull,0x202020203b303472ull,0x7573090a202f2f09ull,
0x2509203233732e62ull,0x357225202c313572ull,0x2020203b31202c30ull,0x202f2f0920202020ull,
0x33732e726873090aull,0x2c32357225092032ull,0x34202c3135722520ull,0x202020202020203bull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x357225202c333572ull,0x3b32357225202c30ull,
0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233732e34ull,0x7225202c31336472ull,
0x20202020203b3335ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c32336472250920ull,
0x202c313364722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,0x3333647225092034ull,
0x202c31647225202cull,0x20203b3233647225ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3966250920323366ull,0x33336472255b202cull,0x2f2f093b5d342d2bull,0x203330323a646920ull,
0x302b617461645f73ull,0x732e7473090a3078ull,0x33662e6465726168ull,0x336472255b092032ull,
0x25202c5d342d2b30ull,0x69202f2f093b3966ull,0x5f73203430323a64ull,0x3078302b61746164ull,
0x3109636f6c2e090aull,0x0a30093430320935ull,0x726168732e646c09ull,0x09203233662e6465ull,
0x255b202c30316625ull,0x5d342d2b33336472ull,0x3a6469202f2f093bull,0x61645f7320353032ull,
0x090a3078302b6174ull,0x203233662e646461ull,0x25202c3131662509ull,0x386625202c303166ull,
0x2f0920202020203bull,0x732e7473090a202full,0x33662e6465726168ull,0x336472255b092032ull,
0x25202c5d342d2b33ull,0x202f2f093b313166ull,0x73203630323a6469ull,0x78302b617461645full,
0x5f325f744c240a30ull,0x3c2f2f200a3a3435ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35313220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x0a33355f325f744cull,0x353109636f6c2e09ull,0x090a300937383109ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x32347225202c3234ull,0x2f0920203b32202cull,0x70746573090a202full,
0x203233752e656c2eull,0x25202c3031702509ull,0x317225202c323472ull,0x090a202f2f09203bull,
0x7262203031702540ull,0x325f744c24092061ull,0x202020203b33355full,0x2f09202020202020ull,
0x325f744c240a202full,0x6c2e090a3a31355full,0x313109353109636full,0x726162090a300936ull,
0x300920636e79732eull,0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300939313109ull,0x6d617261702e646cull,0x722509203436752eull,
0x5f5f5b202c343364ull,0x6d72617061647563ull,0x73657270375a5f5full,0x4531624c496e6163ull,
0x665076454531624cull,0x69695f3053664b50ull,0x7461646f5f675f69ull,0x69202f2f093b5d61ull,
0x5f5f203238313a64ull,0x6d72617061647563ull,0x73657270375a5f5full,0x4531624c496e6163ull,
0x665076454531624cull,0x69695f3053664b50ull,0x7461646f5f675f69ull,0x6c090a3078302b61ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3231ull,0x2f2f093b5d302b36ull,
0x203730323a646920ull,0x302b617461645f73ull,0x2e646461090a3078ull,0x6472250920343675ull,
0x33647225202c3533ull,0x3b3433647225202cull,0x090a202f2f092020ull,0x61626f6c672e7473ull,
0x5b09203233662e6cull,0x5d302b3533647225ull,0x093b32316625202cull,0x30323a6469202f2full,
0x3270252140090a38ull,0x4c24092061726220ull,0x203b37355f325f74ull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3109353109636f6cull,0x646c090a30093332ull,0x2e6465726168732eull,
0x3166250920323366ull,0x316472255b202c33ull,0x2f2f093b5d302b34ull,0x203930323a646920ull,
0x302b617461645f73ull,0x2e646461090a3078ull,0x3572250920323375ull,0x202c387225202c34ull,
0x202020203b317225ull,0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323373ull,
0x34357225202c3633ull,0x2f0920202020203bull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x25202c3733647225ull,0x3b34202c36336472ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x202c383364722509ull,0x25202c3433647225ull,0x2f09203b37336472ull,0x672e7473090a202full,
0x33662e6c61626f6cull,0x336472255b092032ull,0x6625202c5d302b38ull,0x69202f2f093b3331ull,
0x4c240a3031323a64ull,0x0a3a37355f325f74ull,0x353109636f6c2e09ull,0x090a300931343209ull,
0x2020203b74697865ull,0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,
0x6557444c240a202full,0x7270375a5f5f646eull,0x624c496e61637365ull,0x76454531624c4531ull,
0x5f3053664b506650ull,0x207d090a3a696969ull,0x7270375a5f202f2full,0x624c496e61637365ull,
0x76454531624c4531ull,0x5f3053664b506650ull,0x652e090a0a696969ull,0x375a5f207972746eull,
0x496e616373657270ull,0x4530624c4530624cull,0x53664b5066507645ull,0x7b090a6969695f30ull,
0x2e206765722e090aull,0x353c722520323375ull,0x65722e090a3b3e30ull,0x25203436752e2067ull,
0x0a3b3e34333c6472ull,0x662e206765722e09ull,0x34313c6625203233ull,0x6765722e090a3b3eull,
0x2520646572702e20ull,0x090a3b3e30313c70ull,0x2e206d617261702eull,0x75635f5f20343675ull,
0x5f5f6d7261706164ull,0x616373657270375aull,0x624c4530624c496eull,0x4b50665076454530ull,
0x5f6969695f305366ull,0x3b617461646f5f67ull,0x6d617261702e090aull,0x5f5f203436752e20ull,
0x6d72617061647563ull,0x73657270375a5f5full,0x4530624c496e6163ull,0x665076454530624cull,
0x69695f3053664b50ull,0x746164695f675f69ull,0x7261702e090a3b61ull,0x203436752e206d61ull,
0x6170616475635f5full,0x7270375a5f5f6d72ull,0x624c496e61637365ull,0x76454530624c4530ull,
0x5f3053664b506650ull,0x6c625f675f696969ull,0x3b736d75536b636full,0x6d617261702e090aull,
0x5f5f203233732e20ull,0x6d72617061647563ull,0x73657270375a5f5full,0x4530624c496e6163ull,
0x665076454530624cull,0x69695f3053664b50ull,0x702e090a3b6e5f69ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x375a5f5f6d726170ull,0x496e616373657270ull,0x4530624c4530624cull,
0x53664b5066507645ull,0x6c625f6969695f30ull,0x7865646e496b636full,0x617261702e090a3bull,
0x5f203233732e206dull,0x726170616475635full,0x657270375a5f5f6dull,0x30624c496e616373ull,
0x5076454530624c45ull,0x695f3053664b5066ull,0x49657361625f6969ull,0x2e090a3b7865646eull,
0x3209353109636f6cull,0x424c240a30093432ull,0x7270375a5f5f3142ull,0x624c496e61637365ull,
0x76454530624c4530ull,0x5f3053664b506650ull,0x6c2e090a3a696969ull,0x333209353109636full,
0x747663090a300930ull,0x3631752e3233752eull,0x25202c3172250920ull,0x203b782e6469746eull,
0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3272ull,
0x5f6d726170616475ull,0x6373657270375a5full,0x4c4530624c496e61ull,0x5066507645453062ull,
0x6969695f3053664bull,0x646e49657361625full,0x202f2f093b5d7865ull,0x5f203436313a6469ull,
0x726170616475635full,0x657270375a5f5f6dull,0x30624c496e616373ull,0x5076454530624c45ull,
0x695f3053664b5066ull,0x49657361625f6969ull,0x3078302b7865646eull,0x33752e766f6d090aull,
0x202c337225092032ull,0x2020202020203b30ull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33732e656e2e7074ull,0x202c317025092032ull,0x337225202c327225ull,0x202f2f092020203bull,
0x622031702540090aull,0x5f744c2409206172ull,0x2020203b32345f33ull,0x2020202020202020ull,
0x7663090a202f2f09ull,0x31752e3233732e74ull,0x202c347225092036ull,0x782e646961746325ull,
0x202f2f092020203bull,0x33622e6c6873090aull,0x202c357225092032ull,0x203b31202c317225ull,
0x2020202020202020ull,0x756d090a202f2f09ull,0x732e6f6c2e34326cull,0x2c36722509203233ull,
0x7225202c34722520ull,0x202f2f0920203b35ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x202020203b31345full,0x2020202020202020ull,0x744c240a202f2f09ull,0x090a3a32345f335full,
0x203233732e766f6dull,0x7225202c36722509ull,0x2020202020203b32ull,0x2f09202020202020ull,
0x335f744c240a202full,0x6f6d090a3a31345full,0x2509203436752e76ull,0x645f73202c316472ull,
0x202020203b617461ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300936390935ull,
0x2e3233732e747663ull,0x3772250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,
0x2e646461090a202full,0x3872250920323375ull,0x25202c367225202cull,0x20202020203b3772ull,
0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323373ull,0x203b387225202c32ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c33647225ull,
0x20203b34202c3264ull,0x090a202f2f092020ull,0x203233732e726873ull,0x7225202c39722509ull,
0x2020203b34202c37ull,0x2f09202020202020ull,0x2e646461090a202full,0x3172250920323373ull,
0x202c377225202c30ull,0x202020203b397225ull,0x090a202f2f092020ull,0x2e3436732e747663ull,
0x6472250920323373ull,0x3b30317225202c34ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c35647225ull,0x20203b34202c3464ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3664722509ull,0x647225202c316472ull,0x2f09202020203b35ull,
0x702e646c090a202full,0x3436752e6d617261ull,0x202c376472250920ull,0x70616475635f5f5bull,
0x70375a5f5f6d7261ull,0x4c496e6163736572ull,0x454530624c453062ull,0x3053664b50665076ull,
0x695f675f6969695full,0x2f093b5d61746164ull,0x3236313a6469202full,0x70616475635f5f20ull,
0x70375a5f5f6d7261ull,0x4c496e6163736572ull,0x454530624c453062ull,0x3053664b50665076ull,
0x695f675f6969695full,0x3078302b61746164ull,0x36752e646461090aull,0x2c38647225092034ull,
0x25202c3364722520ull,0x202020203b376472ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,
0x3166250920323366ull,0x2b386472255b202cull,0x202f2f09203b5d30ull,0x090a3636313a6469ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x2c5d302b36647225ull,0x2f09203b31662520ull,
0x3736313a6469202full,0x2b617461645f7320ull,0x6f6c2e090a307830ull,0x3430310935310963ull,
0x2e646461090a3009ull,0x3172250920323375ull,0x202c377225202c31ull,0x202020203b317225ull,
0x090a202f2f092020ull,0x203233752e646461ull,0x25202c3231722509ull,0x3b317225202c3872ull,
0x2f09202020202020ull,0x2e747663090a202full,0x203233732e343675ull,0x25202c3964722509ull,
0x202020203b323172ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,
0x2c39647225202c30ull,0x2f092020203b3420ull,0x2e726873090a202full,0x3172250920323373ull,
0x2c31317225202c33ull,0x20202020203b3420ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x25202c3431722509ull,0x317225202c313172ull,0x2f09202020203b33ull,0x2e747663090a202full,
0x203233732e343673ull,0x202c313164722509ull,0x2020203b34317225ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3164722509203436ull,0x3131647225202c32ull,0x2f0920203b34202cull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3331ull,0x3b3231647225202cull,
0x090a202f2f092020ull,0x203436752e646461ull,0x202c343164722509ull,0x25202c3031647225ull,
0x2f0920203b376472ull,0x672e646c090a202full,0x33662e6c61626f6cull,0x202c326625092032ull,
0x302b34316472255bull,0x6469202f2f093b5dull,0x7473090a3836313aull,0x2e6465726168732eull,
0x72255b0920323366ull,0x202c5d302b333164ull,0x202f2f093b326625ull,0x73203936313a6469ull,
0x78302b617461645full,0x09636f6c2e090a30ull,0x3009303631093531ull,0x33732e766f6d090aull,
0x2c35317225092032ull,0x2020203b31722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233752e76ull,0x203b30202c363172ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x6c2e70746573090aull,0x2509203233732e65ull,0x2c317225202c3270ull,0x20203b3631722520ull,
0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x203b31202c373172ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x622032702540090aull,0x5f744c2409206172ull,0x2020203b37355f33ull,
0x2020202020202020ull,0x744c240a202f2f09ull,0x200a3a35345f335full,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a323631ull,0x3236310935310963ull,
0x2e726162090a3009ull,0x3b300920636e7973ull,0x2020202020202020ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e65672e70746573ull,0x3370250920323375ull,0x25202c377225202cull,
0x2f0920203b353172ull,0x33702540090a202full,0x4c24092061726220ull,0x203b36345f335f74ull,
0x2020202020202020ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323631ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x636f6c2e090a3534ull,0x0933373109353109ull,0x732e766f6d090a30ull,
0x3831722509203233ull,0x202020203b32202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x2e6f6c2e34326c75ull,0x3172250920323373ull,0x2c38317225202c39ull,0x2f093b3731722520ull,
0x326c756d090a202full,0x3233732e6f6c2e34ull,0x202c303272250920ull,0x7225202c39317225ull,
0x090a202f2f093b37ull,0x203233752e646461ull,0x25202c3132722509ull,0x317225202c303272ull,
0x2f09202020203b37ull,0x2e646461090a202full,0x3272250920323375ull,0x2c31327225202c32ull,
0x20203b3731722520ull,0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3332722509ull,
0x203b31202c323272ull,0x2f09202020202020ull,0x2e726873090a202full,0x3272250920323373ull,
0x2c33327225202c34ull,0x20202020203b3420ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x25202c3532722509ull,0x327225202c323272ull,0x2f09202020203b34ull,0x2e747663090a202full,
0x203233732e343675ull,0x202c353164722509ull,0x2020203b35327225ull,0x090a202f2f092020ull,
0x752e6f6c2e6c756dull,0x3164722509203436ull,0x3531647225202c36ull,0x2f0920203b34202cull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3731ull,0x3b3631647225202cull,
0x090a202f2f092020ull,0x65726168732e646cull,0x2509203233662e64ull,0x6472255b202c3366ull,
0x093b5d342d2b3731ull,0x37313a6469202f2full,0x617461645f732031ull,0x7573090a3078302bull,
0x2509203233732e62ull,0x327225202c363272ull,0x2020203b31202c31ull,0x202f2f0920202020ull,
0x33732e726873090aull,0x2c37327225092032ull,0x34202c3632722520ull,0x202020202020203bull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x327225202c383272ull,0x3b37327225202c31ull,
0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233732e34ull,0x7225202c38316472ull,
0x20202020203b3832ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c39316472250920ull,
0x202c383164722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,0x3032647225092034ull,
0x202c31647225202cull,0x20203b3931647225ull,0x646c090a202f2f09ull,0x2e6465726168732eull,
0x3466250920323366ull,0x30326472255b202cull,0x2f2f093b5d342d2bull,0x203037313a646920ull,
0x302b617461645f73ull,0x2e646461090a3078ull,0x3566250920323366ull,0x25202c336625202cull,
0x20202020203b3466ull,0x090a202f2f092020ull,0x65726168732e7473ull,0x5b09203233662e64ull,
0x342d2b3731647225ull,0x093b356625202c5dull,0x37313a6469202f2full,0x617461645f732032ull,
0x744c240a3078302bull,0x200a3a36345f335full,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323631ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x636f6c2e090a3534ull,0x0936373109353109ull,0x6c2e6c756d090a30ull,
0x2509203233752e6full,0x317225202c373172ull,0x2020203b32202c37ull,0x2e090a202f2f0920ull,
0x3109353109636f6cull,0x6873090a30093036ull,0x2509203233732e72ull,0x317225202c353172ull,
0x2020203b31202c35ull,0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c39327225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e74672e7074ull,
0x202c347025092032ull,0x7225202c35317225ull,0x202f2f09203b3932ull,0x622034702540090aull,
0x5f744c2409206172ull,0x2020203b35345f33ull,0x2020202020202020ull,0x7262090a202f2f09ull,
0x240920696e752e61ull,0x3b33345f335f744cull,0x2020202020202020ull,0x202f2f0920202020ull,
0x355f335f744c240aull,0x335f744c240a3a37ull,0x6c2e090a3a33345full,0x313209353109636full,
0x766f6d090a300933ull,0x722509203233752eull,0x20203b30202c3033ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x656e2e7074657309ull,0x702509203233752eull,0x202c377225202c35ull,
0x0920203b30337225ull,0x702540090a202f2full,0x2409206172622035ull,0x3b39345f335f744cull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938343109ull,
0x203233622e6c6873ull,0x25202c3133722509ull,0x20203b31202c3172ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3666250920323366ull,0x303030306630202cull,0x2020203b30303030ull,
0x0a30202f2f092020ull,0x3233732e62757309ull,0x202c323372250920ull,0x3b31202c31337225ull,
0x0920202020202020ull,0x726873090a202f2full,0x722509203233732eull,0x32337225202c3333ull,
0x202020203b34202cull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c343372250920ull,
0x7225202c31337225ull,0x09202020203b3333ull,0x747663090a202f2full,0x3233732e3436752eull,
0x2c31326472250920ull,0x20203b3433722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x32647225202c3232ull,0x0920203b34202c31ull,0x646461090a202f2full,
0x722509203436752eull,0x647225202c333264ull,0x3232647225202c31ull,0x0a202f2f0920203bull,
0x726168732e747309ull,0x09203233662e6465ull,0x2d2b33326472255bull,0x3b366625202c5d34ull,
0x313a6469202f2f09ull,0x7461645f73203337ull,0x4c240a3078302b61ull,0x0a3a39345f335f74ull,
0x353109636f6c2e09ull,0x090a300935313209ull,0x203233732e766f6dull,0x25202c3533722509ull,
0x202020203b373172ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3372250920323375ull,
0x2020203b31202c36ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e746c2e70746573ull,
0x3670250920323375ull,0x25202c317225202cull,0x2f0920203b363372ull,0x36702540090a202full,
0x4c24092061726220ull,0x203b31355f335f74ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x31202c3733722509ull,0x202020202020203bull,0x2f09202020202020ull,
0x335f744c240a202full,0x2f2f200a3a33355full,0x4c203e706f6f6c3cull,0x79646f6220706f6full,
0x313220656e696c20ull,0x697473656e202c35ull,0x687470656420676eull,0x747365202c31203aull,
0x6920646574616d69ull,0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,
0x0939383109353109ull,0x752e726873090a30ull,0x3533722509203233ull,0x202c35337225202cull,
0x2020202020203b31ull,0x2e090a202f2f0920ull,0x3109353109636f6cull,0x6162090a30093139ull,
0x0920636e79732e72ull,0x2020202020203b30ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x6c2e70746573090aull,0x2509203233752e65ull,0x37337225202c3770ull,0x20203b377225202cull,
0x2540090a202f2f09ull,0x0920617262203770ull,0x34355f335f744c24ull,0x202020202020203bull,
0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3531322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x6c2e090a33355f33ull,0x303209353109636full,0x766f6d090a300932ull,0x722509203233732eull,
0x20203b32202c3833ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x337225202c393372ull,0x3b35337225202c38ull,0x756d090a202f2f09ull,
0x732e6f6c2e34326cull,0x3034722509203233ull,0x202c39337225202cull,0x202f2f093b377225ull,
0x33752e646461090aull,0x2c31347225092032ull,0x25202c3034722520ull,0x202020203b353372ull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x347225202c323472ull,0x2020203b31202c31ull,
0x202f2f0920202020ull,0x33732e726873090aull,0x2c33347225092032ull,0x34202c3234722520ull,
0x202020202020203bull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x347225202c343472ull,
0x3b33347225202c31ull,0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233732e34ull,
0x7225202c34326472ull,0x20202020203b3434ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,
0x2c35326472250920ull,0x202c343264722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,
0x3632647225092034ull,0x202c31647225202cull,0x20203b3532647225ull,0x646c090a202f2f09ull,
0x2e6465726168732eull,0x3766250920323366ull,0x36326472255b202cull,0x2f2f093b5d342d2bull,
0x203437313a646920ull,0x302b617461645f73ull,0x636f6c2e090a3078ull,0x0933303209353109ull,
0x752e646461090a30ull,0x3534722509203233ull,0x202c31347225202cull,0x2020203b35337225ull,
0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c36347225ull,0x20203b31202c3534ull,
0x2f2f092020202020ull,0x732e726873090a20ull,0x3734722509203233ull,0x202c36347225202cull,
0x2020202020203b34ull,0x61090a202f2f0920ull,0x09203233732e6464ull,0x7225202c38347225ull,
0x37347225202c3534ull,0x2f2f09202020203bull,0x752e747663090a20ull,0x09203233732e3436ull,
0x25202c3732647225ull,0x202020203b383472ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x3832647225092034ull,0x2c3732647225202cull,0x2f2f0920203b3420ull,0x752e646461090a20ull,
0x3264722509203436ull,0x2c31647225202c39ull,0x203b383264722520ull,0x6c090a202f2f0920ull,
0x6465726168732e64ull,0x662509203233662eull,0x326472255b202c38ull,0x2f093b5d342d2b39ull,
0x3537313a6469202full,0x2b617461645f7320ull,0x2e7473090a307830ull,0x662e646572616873ull,
0x6472255b09203233ull,0x202c5d342d2b3632ull,0x202f2f093b386625ull,0x73203637313a6469ull,
0x78302b617461645full,0x09636f6c2e090a30ull,0x3009343032093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x255b202c39662509ull,0x5d342d2b39326472ull,0x3a6469202f2f093bull,
0x61645f7320373731ull,0x090a3078302b6174ull,0x203233662e646461ull,0x25202c3031662509ull,
0x3b376625202c3966ull,0x2f09202020202020ull,0x732e7473090a202full,0x33662e6465726168ull,
0x326472255b092032ull,0x25202c5d342d2b39ull,0x202f2f093b303166ull,0x73203837313a6469ull,
0x78302b617461645full,0x5f335f744c240a30ull,0x3c2f2f200a3a3435ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35313220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x0a33355f335f744cull,0x353109636f6c2e09ull,0x090a300937383109ull,
0x6f6c2e34326c756dull,0x722509203233732eull,0x37337225202c3733ull,0x2f0920203b32202cull,
0x70746573090a202full,0x203233752e656c2eull,0x7225202c38702509ull,0x3b317225202c3733ull,
0x090a202f2f092020ull,0x6172622038702540ull,0x5f335f744c240920ull,0x20202020203b3335ull,
0x2f09202020202020ull,0x335f744c240a202full,0x6c2e090a3a31355full,0x313109353109636full,
0x726162090a300936ull,0x300920636e79732eull,0x202020202020203bull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939313109ull,0x6d617261702e646cull,
0x722509203436752eull,0x5f5f5b202c303364ull,0x6d72617061647563ull,0x73657270375a5f5full,
0x4530624c496e6163ull,0x665076454530624cull,0x69695f3053664b50ull,0x7461646f5f675f69ull,
0x69202f2f093b5d61ull,0x5f5f203835313a64ull,0x6d72617061647563ull,0x73657270375a5f5full,
0x4530624c496e6163ull,0x665076454530624cull,0x69695f3053664b50ull,0x7461646f5f675f69ull,
0x6c090a3078302b61ull,0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3131ull,
0x2f2f093b5d302b36ull,0x203937313a646920ull,0x302b617461645f73ull,0x2e646461090a3078ull,
0x6472250920343675ull,0x33647225202c3133ull,0x3b3033647225202cull,0x090a202f2f092020ull,
0x61626f6c672e7473ull,0x5b09203233662e6cull,0x5d302b3133647225ull,0x093b31316625202cull,
0x38313a6469202f2full,0x09636f6c2e090a30ull,0x3009373231093531ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3231662509ull,0x5d302b3331647225ull,0x3a6469202f2f093bull,
0x61645f7320313831ull,0x090a3078302b6174ull,0x203436752e646461ull,0x202c323364722509ull,
0x25202c3031647225ull,0x2f09203b30336472ull,0x672e7473090a202full,0x33662e6c61626f6cull,
0x336472255b092032ull,0x6625202c5d302b32ull,0x69202f2f093b3231ull,0x2e090a3238313a64ull,
0x3209353109636f6cull,0x7865090a30093134ull,0x20202020203b7469ull,0x2020202020202020ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x646e6557444c240aull,0x73657270375a5f5full,
0x4530624c496e6163ull,0x665076454530624cull,0x69695f3053664b50ull,0x2f2f207d090a3a69ull,
0x73657270375a5f20ull,0x4530624c496e6163ull,0x665076454530624cull,0x69695f3053664b50ull,
0x746e652e090a0a69ull,0x7270375a5f207972ull,0x624c496e61637365ull,0x76454531624c4530ull,
0x5f3053664b506650ull,0x090a7b090a696969ull,0x33752e206765722eull,0x3e32353c72252032ull,
0x206765722e090a3bull,0x647225203436752eull,0x2e090a3b3e36333cull,0x3233662e20676572ull,
0x3b3e34313c662520ull,0x2e206765722e090aull,0x3c70252064657270ull,0x702e090a3b3e3131ull,
0x36752e206d617261ull,0x616475635f5f2034ull,0x375a5f5f6d726170ull,0x496e616373657270ull,
0x4531624c4530624cull,0x53664b5066507645ull,0x5f675f6969695f30ull,0x090a3b617461646full,
0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x616373657270375aull,
0x624c4530624c496eull,0x4b50665076454531ull,0x5f6969695f305366ull,0x3b61746164695f67ull,
0x6d617261702e090aull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x73657270375a5f5full,
0x4530624c496e6163ull,0x665076454531624cull,0x69695f3053664b50ull,0x636f6c625f675f69ull,
0x090a3b736d75536bull,0x2e206d617261702eull,0x75635f5f20323373ull,0x5f5f6d7261706164ull,
0x616373657270375aull,0x624c4530624c496eull,0x4b50665076454531ull,0x5f6969695f305366ull,
0x7261702e090a3b6eull,0x203233732e206d61ull,0x6170616475635f5full,0x7270375a5f5f6d72ull,
0x624c496e61637365ull,0x76454531624c4530ull,0x5f3053664b506650ull,0x636f6c625f696969ull,
0x0a3b7865646e496bull,0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,
0x6373657270375a5full,0x4c4530624c496e61ull,0x5066507645453162ull,0x6969695f3053664bull,
0x646e49657361625full,0x6f6c2e090a3b7865ull,0x3432320935310963ull,0x3142424c240a3009ull,
0x73657270375a5f5full,0x4530624c496e6163ull,0x665076454531624cull,0x69695f3053664b50ull,
0x636f6c2e090a3a69ull,0x0930333209353109ull,0x752e747663090a30ull,0x09203631752e3233ull,
0x746e25202c317225ull,0x2020203b782e6469ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x3272250920323373ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6e61637365727037ull,
0x31624c4530624c49ull,0x664b506650764545ull,0x625f6969695f3053ull,0x7865646e49657361ull,
0x6469202f2f093b5dull,0x635f5f203237313aull,0x5f6d726170616475ull,0x6373657270375a5full,
0x4c4530624c496e61ull,0x5066507645453162ull,0x6969695f3053664bull,0x646e49657361625full,
0x090a3078302b7865ull,0x203233752e766f6dull,0x3b30202c33722509ull,0x2020202020202020ull,
0x2f09202020202020ull,0x70746573090a202full,0x203233732e656e2eull,0x7225202c31702509ull,
0x203b337225202c32ull,0x090a202f2f092020ull,0x6172622031702540ull,0x5f345f744c240920ull,
0x20202020203b3234ull,0x2f09202020202020ull,0x2e747663090a202full,0x203631752e323373ull,
0x6325202c34722509ull,0x203b782e64696174ull,0x090a202f2f092020ull,0x203233622e6c6873ull,
0x7225202c35722509ull,0x2020203b31202c31ull,0x2f09202020202020ull,0x326c756d090a202full,
0x3233732e6f6c2e34ull,0x25202c3672250920ull,0x3b357225202c3472ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x345f345f744c2409ull,0x2020202020203b31ull,0x2f09202020202020ull,
0x345f744c240a202full,0x6f6d090a3a32345full,0x2509203233732e76ull,0x3b327225202c3672ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x345f345f744c240aull,0x2e766f6d090a3a31ull,
0x6472250920343675ull,0x7461645f73202c31ull,0x2020202020203b61ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x7663090a30093639ull,0x31752e3233732e74ull,0x202c377225092036ull,
0x203b782e64697425ull,0x202f2f0920202020ull,0x33752e646461090aull,0x202c387225092032ull,
0x377225202c367225ull,0x202020202020203bull,0x7663090a202f2f09ull,0x33732e3436752e74ull,
0x2c32647225092032ull,0x2020203b38722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x32647225202c3364ull,0x202020203b34202cull,0x6873090a202f2f09ull,
0x2509203233732e72ull,0x2c377225202c3972ull,0x20202020203b3420ull,0x202f2f0920202020ull,
0x33732e646461090aull,0x2c30317225092032ull,0x7225202c37722520ull,0x2020202020203b39ull,
0x7663090a202f2f09ull,0x33732e3436732e74ull,0x2c34647225092032ull,0x20203b3031722520ull,
0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x34647225202c3564ull,
0x202020203b34202cull,0x6461090a202f2f09ull,0x2509203436752e64ull,0x647225202c366472ull,
0x3b35647225202c31ull,0x202f2f0920202020ull,0x7261702e646c090aull,0x09203436752e6d61ull,
0x5f5b202c37647225ull,0x726170616475635full,0x657270375a5f5f6dull,0x30624c496e616373ull,
0x5076454531624c45ull,0x695f3053664b5066ull,0x6164695f675f6969ull,0x202f2f093b5d6174ull,
0x5f203037313a6469ull,0x726170616475635full,0x657270375a5f5f6dull,0x30624c496e616373ull,
0x5076454531624c45ull,0x695f3053664b5066ull,0x6164695f675f6969ull,0x090a3078302b6174ull,
0x203436752e646461ull,0x25202c3864722509ull,0x647225202c336472ull,0x2f09202020203b37ull,
0x672e646c090a202full,0x33662e6c61626f6cull,0x202c316625092032ull,0x5d302b386472255bull,
0x6469202f2f09203bull,0x7473090a3437313aull,0x2e6465726168732eull,0x72255b0920323366ull,
0x25202c5d302b3664ull,0x202f2f09203b3166ull,0x73203537313a6469ull,0x78302b617461645full,
0x752e646461090a30ull,0x3131722509203233ull,0x25202c377225202cull,0x20202020203b3172ull,
0x6c090a202f2f0920ull,0x2e6d617261702e64ull,0x3172250920323373ull,0x75635f5f5b202c32ull,
0x5f5f6d7261706164ull,0x616373657270375aull,0x624c4530624c496eull,0x4b50665076454531ull,
0x5f6969695f305366ull,0x69202f2f093b5d6eull,0x5f5f203637313a64ull,0x6d72617061647563ull,
0x73657270375a5f5full,0x4530624c496e6163ull,0x665076454531624cull,0x69695f3053664b50ull,
0x0a3078302b6e5f69ull,0x74672e7074657309ull,0x702509203233732eull,0x2c32317225202c32ull,
0x09203b3131722520ull,0x252140090a202f2full,0x0920617262203270ull,0x34345f345f744c24ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300930303109ull,
0x203233752e646461ull,0x25202c3331722509ull,0x3b317225202c3872ull,0x2f09202020202020ull,
0x2e747663090a202full,0x203233732e343675ull,0x25202c3964722509ull,0x202020203b333172ull,
0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,0x2c39647225202c30ull,
0x2f092020203b3420ull,0x2e646461090a202full,0x6472250920343675ull,0x37647225202c3131ull,
0x3b3031647225202cull,0x090a202f2f092020ull,0x61626f6c672e646cull,0x2509203233662e6cull,
0x6472255b202c3266ull,0x2f093b5d302b3131ull,0x3737313a6469202full,0x6e752e617262090aull,
0x345f744c24092069ull,0x202020203b33345full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x090a3a34345f345full,0x203233662e766f6dull,0x6630202c32662509ull,0x3030303030303030ull,
0x2f0920202020203bull,0x5f744c240a30202full,0x73090a3a33345f34ull,0x09203233732e7268ull,
0x7225202c34317225ull,0x20203b34202c3131ull,0x2f2f092020202020ull,0x732e646461090a20ull,
0x3531722509203233ull,0x202c31317225202cull,0x2020203b34317225ull,0x63090a202f2f0920ull,
0x732e3436732e7476ull,0x3164722509203233ull,0x3b35317225202c32ull,0x2f2f092020202020ull,
0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c33316472ull,0x203b34202c323164ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3431647225ull,0x647225202c316472ull,
0x2f2f0920203b3331ull,0x68732e7473090a20ull,0x3233662e64657261ull,0x34316472255b0920ull,
0x326625202c5d302bull,0x3a6469202f2f093bull,0x61645f7320383731ull,0x090a3078302b6174ull,
0x09353109636f6c2eull,0x6d090a3009303631ull,0x09203233732e766full,0x7225202c36317225ull,
0x2020202020203b31ull,0x2f2f092020202020ull,0x752e766f6d090a20ull,0x3731722509203233ull,
0x202020203b30202cull,0x2020202020202020ull,0x73090a202f2f0920ull,0x732e656c2e707465ull,
0x2c33702509203233ull,0x7225202c31722520ull,0x2f2f0920203b3731ull,0x752e766f6d090a20ull,
0x3831722509203233ull,0x202020203b31202cull,0x2020202020202020ull,0x40090a202f2f0920ull,
0x2061726220337025ull,0x365f345f744c2409ull,0x2020202020203b31ull,0x2f2f092020202020ull,
0x5f345f744c240a20ull,0x3c2f2f200a3a3734ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x32363120656e696cull,0x3109636f6c2e090aull,0x0a30093236310935ull,0x6e79732e72616209ull,
0x2020203b30092063ull,0x2020202020202020ull,0x0920202020202020ull,0x746573090a202f2full,
0x3233752e65672e70ull,0x25202c3470250920ull,0x36317225202c3772ull,0x0a202f2f0920203bull,
0x7262203470254009ull,0x345f744c24092061ull,0x202020203b38345full,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x32363120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x0a37345f345f744cull,
0x353109636f6c2e09ull,0x090a300933373109ull,0x203233732e766f6dull,0x32202c3931722509ull,
0x202020202020203bull,0x2f09202020202020ull,0x326c756d090a202full,0x3233732e6f6c2e34ull,
0x202c303272250920ull,0x7225202c39317225ull,0x0a202f2f093b3831ull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x327225202c313272ull,0x093b377225202c30ull,0x646461090a202f2full,
0x722509203233752eull,0x31327225202c3232ull,0x203b38317225202cull,0x0a202f2f09202020ull,
0x3233752e64646109ull,0x202c333272250920ull,0x7225202c32327225ull,0x09202020203b3831ull,
0x627573090a202f2full,0x722509203233732eull,0x33327225202c3432ull,0x202020203b31202cull,
0x0a202f2f09202020ull,0x3233732e72687309ull,0x202c353272250920ull,0x3b34202c34327225ull,
0x0920202020202020ull,0x646461090a202f2full,0x722509203233732eull,0x33327225202c3632ull,
0x203b35327225202cull,0x0a202f2f09202020ull,0x3436752e74766309ull,0x722509203233732eull,
0x327225202c353164ull,0x0920202020203b36ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c363164722509ull,0x34202c3531647225ull,0x0a202f2f0920203bull,0x3436752e64646109ull,
0x2c37316472250920ull,0x25202c3164722520ull,0x0920203b36316472ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x2c33662509203233ull,0x2b37316472255b20ull,0x202f2f093b5d342dull,
0x73203038313a6469ull,0x78302b617461645full,0x732e627573090a30ull,0x3732722509203233ull,
0x202c32327225202cull,0x2020202020203b31ull,0x73090a202f2f0920ull,0x09203233732e7268ull,
0x7225202c38327225ull,0x20203b34202c3732ull,0x2f2f092020202020ull,0x732e646461090a20ull,
0x3932722509203233ull,0x202c32327225202cull,0x2020203b38327225ull,0x63090a202f2f0920ull,
0x732e3436752e7476ull,0x3164722509203233ull,0x3b39327225202c38ull,0x2f2f092020202020ull,
0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c39316472ull,0x203b34202c383164ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3032647225ull,0x647225202c316472ull,
0x2f2f0920203b3931ull,0x68732e646c090a20ull,0x3233662e64657261ull,0x5b202c3466250920ull,
0x342d2b3032647225ull,0x6469202f2f093b5dull,0x645f73203937313aull,0x0a3078302b617461ull,
0x3233662e64646109ull,0x25202c3566250920ull,0x3b346625202c3366ull,0x0920202020202020ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203233ull,0x202c5d342d2b3731ull,
0x202f2f093b356625ull,0x73203138313a6469ull,0x78302b617461645full,0x5f345f744c240a30ull,
0x3c2f2f200a3a3834ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x32363120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x0a37345f345f744cull,
0x353109636f6c2e09ull,0x090a300936373109ull,0x752e6f6c2e6c756dull,0x3831722509203233ull,
0x202c38317225202cull,0x2f09202020203b32ull,0x636f6c2e090a202full,0x0930363109353109ull,
0x732e726873090a30ull,0x3631722509203233ull,0x202c36317225202cull,0x2020202020203b31ull,
0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c30337225ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e7467ull,0x317225202c357025ull,
0x3b30337225202c36ull,0x40090a202f2f0920ull,0x2061726220357025ull,0x345f345f744c2409ull,
0x2020202020203b37ull,0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x2020203b35345f34ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x0a3a31365f345f74ull,
0x35345f345f744c24ull,0x09636f6c2e090a3aull,0x3009333132093531ull,0x33752e766f6d090aull,
0x2c31337225092032ull,0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33752e656e2e7074ull,0x202c367025092032ull,0x337225202c377225ull,0x202f2f0920203b31ull,
0x622036702540090aull,0x5f744c2409206172ull,0x2020203b31355f34ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x343109353109636full,0x6c6873090a300938ull,0x722509203233622eull,
0x2c317225202c3233ull,0x20202020203b3120ull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x30202c3666250920ull,0x3030303030303066ull,0x0920202020203b30ull,0x7573090a30202f2full,
0x2509203233732e62ull,0x337225202c333372ull,0x2020203b31202c32ull,0x202f2f0920202020ull,
0x33732e726873090aull,0x2c34337225092032ull,0x34202c3333722520ull,0x202020202020203bull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x337225202c353372ull,0x3b34337225202c32ull,
0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233732e34ull,0x7225202c31326472ull,
0x20202020203b3533ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c32326472250920ull,
0x202c313264722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,0x3332647225092034ull,
0x202c31647225202cull,0x20203b3232647225ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920323366ull,0x2c5d342d2b333264ull,0x2f2f093b36662520ull,0x203238313a646920ull,
0x302b617461645f73ull,0x345f744c240a3078ull,0x6c2e090a3a31355full,0x313209353109636full,
0x766f6d090a300935ull,0x722509203233732eull,0x38317225202c3633ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233752e766f6d09ull,0x202c373372250920ull,0x2020202020203b31ull,
0x0920202020202020ull,0x746573090a202f2full,0x3233752e746c2e70ull,0x25202c3770250920ull,
0x37337225202c3172ull,0x0a202f2f0920203bull,0x7262203770254009ull,0x345f744c24092061ull,
0x202020203b33355full,0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233732eull,
0x20203b31202c3833ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x35355f345f744c24ull,
0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c35313220656eull,
0x20676e697473656eull,0x31203a6874706564ull,0x616d69747365202cull,0x7265746920646574ull,
0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x353109636f6c2e09ull,0x090a300939383109ull,
0x203233752e726873ull,0x25202c3633722509ull,0x203b31202c363372ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0931393109353109ull,0x732e726162090a30ull,0x203b300920636e79ull,
0x2020202020202020ull,0x2020202020202020ull,0x73090a202f2f0920ull,0x752e656c2e707465ull,
0x2c38702509203233ull,0x25202c3833722520ull,0x2f2f0920203b3772ull,0x2038702540090a20ull,
0x744c240920617262ull,0x20203b36355f345full,0x2020202020202020ull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3531ull,0x64656c6562616c20ull,0x355f345f744c2420ull,0x09636f6c2e090a35ull,
0x3009323032093531ull,0x33732e766f6d090aull,0x2c39337225092032ull,0x20202020203b3220ull,
0x2020202020202020ull,0x756d090a202f2f09ull,0x732e6f6c2e34326cull,0x3034722509203233ull,
0x202c39337225202cull,0x2f2f093b36337225ull,0x34326c756d090a20ull,0x203233732e6f6c2eull,
0x25202c3134722509ull,0x377225202c303472ull,0x61090a202f2f093bull,0x09203233752e6464ull,
0x7225202c32347225ull,0x36337225202c3134ull,0x2f2f09202020203bull,0x732e627573090a20ull,
0x3334722509203233ull,0x202c32347225202cull,0x2020202020203b31ull,0x73090a202f2f0920ull,
0x09203233732e7268ull,0x7225202c34347225ull,0x20203b34202c3334ull,0x2f2f092020202020ull,
0x732e646461090a20ull,0x3534722509203233ull,0x202c32347225202cull,0x2020203b34347225ull,
0x63090a202f2f0920ull,0x732e3436752e7476ull,0x3264722509203233ull,0x3b35347225202c34ull,
0x2f2f092020202020ull,0x6c2e6c756d090a20ull,0x2509203436752e6full,0x7225202c35326472ull,
0x203b34202c343264ull,0x61090a202f2f0920ull,0x09203436752e6464ull,0x25202c3632647225ull,
0x647225202c316472ull,0x2f2f0920203b3532ull,0x68732e646c090a20ull,0x3233662e64657261ull,
0x5b202c3766250920ull,0x342d2b3632647225ull,0x6469202f2f093b5dull,0x645f73203338313aull,
0x0a3078302b617461ull,0x353109636f6c2e09ull,0x090a300933303209ull,0x203233752e646461ull,
0x25202c3634722509ull,0x337225202c323472ull,0x2f09202020203b36ull,0x2e627573090a202full,
0x3472250920323373ull,0x2c36347225202c37ull,0x20202020203b3120ull,0x090a202f2f092020ull,
0x203233732e726873ull,0x25202c3834722509ull,0x203b34202c373472ull,0x2f09202020202020ull,
0x2e646461090a202full,0x3472250920323373ull,0x2c36347225202c39ull,0x20203b3834722520ull,
0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323373ull,0x39347225202c3732ull,
0x2f0920202020203bull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3832647225ull,
0x3b34202c37326472ull,0x090a202f2f092020ull,0x203436752e646461ull,0x202c393264722509ull,
0x7225202c31647225ull,0x2f0920203b383264ull,0x732e646c090a202full,0x33662e6465726168ull,
0x202c386625092032ull,0x2d2b39326472255bull,0x69202f2f093b5d34ull,0x5f73203438313a64ull,
0x3078302b61746164ull,0x6168732e7473090aull,0x203233662e646572ull,0x2b36326472255b09ull,
0x386625202c5d342dull,0x3a6469202f2f093bull,0x61645f7320353831ull,0x090a3078302b6174ull,
0x09353109636f6c2eull,0x6c090a3009343032ull,0x6465726168732e64ull,0x662509203233662eull,
0x326472255b202c39ull,0x2f093b5d342d2b39ull,0x3638313a6469202full,0x2b617461645f7320ull,
0x646461090a307830ull,0x662509203233662eull,0x2c396625202c3031ull,0x2020203b37662520ull,
0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233662e6465ull,0x2d2b39326472255bull,
0x30316625202c5d34ull,0x3a6469202f2f093bull,0x61645f7320373831ull,0x240a3078302b6174ull,
0x3a36355f345f744cull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3531322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x6c2e090a35355f34ull,0x383109353109636full,0x6c756d090a300937ull,0x33732e6f6c2e3432ull,
0x2c38337225092032ull,0x32202c3833722520ull,0x0a202f2f0920203bull,0x656c2e7074657309ull,
0x702509203233752eull,0x2c38337225202c39ull,0x0920203b31722520ull,0x702540090a202f2full,
0x2409206172622039ull,0x3b35355f345f744cull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x33355f345f744c24ull,0x09636f6c2e090a3aull,0x3009363131093531ull,0x79732e726162090aull,
0x20203b300920636eull,0x2020202020202020ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x313109353109636full,0x2e646c090a300939ull,0x36752e6d61726170ull,0x3033647225092034ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6e61637365727037ull,0x31624c4530624c49ull,
0x664b506650764545ull,0x675f6969695f3053ull,0x3b5d617461646f5full,0x313a6469202f2f09ull,
0x6475635f5f203636ull,0x5a5f5f6d72617061ull,0x6e61637365727037ull,0x31624c4530624c49ull,
0x664b506650764545ull,0x675f6969695f3053ull,0x302b617461646f5full,0x732e646c090a3078ull,
0x33662e6465726168ull,0x2c31316625092032ull,0x302b366472255b20ull,0x6469202f2f093b5dull,
0x645f73203838313aull,0x0a3078302b617461ull,0x3436752e64646109ull,0x2c31336472250920ull,
0x25202c3364722520ull,0x0920203b30336472ull,0x2e7473090a202f2full,0x662e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3133ull,0x202f2f093b313166ull,0x090a3938313a6469ull,
0x7262203270252140ull,0x345f744c24092061ull,0x202020203b39355full,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0933323109353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,
0x202c323166250920ull,0x302b34316472255bull,0x6469202f2f093b5dull,0x645f73203039313aull,
0x0a3078302b617461ull,0x3233752e64646109ull,0x202c303572250920ull,0x317225202c387225ull,
0x092020202020203bull,0x747663090a202f2full,0x3233732e3436752eull,0x2c32336472250920ull,
0x20203b3035722520ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x33647225202c3333ull,0x0920203b34202c32ull,0x646461090a202f2full,0x722509203436752eull,
0x647225202c343364ull,0x33647225202c3033ull,0x0a202f2f09203b33ull,0x626f6c672e747309ull,
0x09203233662e6c61ull,0x302b34336472255bull,0x3b32316625202c5dull,0x313a6469202f2f09ull,
0x345f744c240a3139ull,0x6c2e090a3a39355full,0x343209353109636full,0x697865090a300931ull,
0x2020202020203b74ull,0x2020202020202020ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x5f646e6557444c24ull,0x6373657270375a5full,0x4c4530624c496e61ull,0x5066507645453162ull,
0x6969695f3053664bull,0x202f2f207d090a3aull,0x6373657270375a5full,0x4c4530624c496e61ull,
0x5066507645453162ull,0x6969695f3053664bull,0x0000000000000a0aull
};


}



extern "C" {


static const unsigned long long __deviceText_$sm_10$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d30315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x2065646f630a7d6eull,
0x20656d616e090a7bull,0x657270375a5f203dull,0x31624c496e616373ull,0x5076454531624c45ull,
0x695f3053664b5066ull,0x6d656d6c090a6969ull,0x6d73090a30203d20ull,0x0a3436203d206d65ull,
0x203d202067657209ull,0x20726162090a3031ull,0x6f63090a31203d20ull,0x09090a7b2074736eull,
0x656d616e67657309ull,0x74736e6f63203d20ull,0x6e6765730909090aull,0x0a31203d20206d75ull,
0x657366666f090909ull,0x090a30203d202074ull,0x2073657479620909ull,0x09090a34203d2020ull,
0x09090a7b206d656dull,0x3030303030783009ull,0x7d09090a20313030ull,0x6e6962090a7d090aull,
0x090a7b2065646f63ull,0x6463373033783009ull,0x6336783020646639ull,0x3020386337343132ull,
0x3032343030306178ull,0x3032343078302035ull,0x09090a2030383730ull,0x6334303030617830ull,
0x3234307830203930ull,0x7830203030353030ull,0x6430323031303033ull,0x3030313463783020ull,
0x3009090a20303035ull,0x3034303330303478ull,0x3130303078302039ull,0x3178302030303538ull,
0x2039303864303030ull,0x3263333234307830ull,0x783009090a203038ull,0x6430303030303061ull,
0x3030303430783020ull,0x3032783020303837ull,0x3020353136303030ull,0x3837383030343078ull,
0x33783009090a2030ull,0x2031303630343030ull,0x3730303163657830ull,0x3030337830203038ull,
0x7830203131613032ull,0x3038373030313463ull,0x3032783009090a20ull,0x3020383036383030ull,
0x3063653430313278ull,0x6530306478302030ull,0x3878302031303030ull,0x2030383730306330ull,
0x303030783009090aull,0x7830203530343032ull,0x3038373030303063ull,0x3030303032783020ull,
0x3430783020393036ull,0x0a20303837343030ull,0x3230303378300909ull,0x3678302039313464ull,
0x2030643730313263ull,0x3032303034307830ull,0x3234657830203130ull,0x090a203038373030ull,
0x3030303061783009ull,0x6330783020646664ull,0x3020386337343130ull,0x3061303030303278ull,
0x3030343078302031ull,0x09090a2030383635ull,0x3030323030337830ull,0x3134637830203130ull,
0x7830203038363130ull,0x3130636330303032ull,0x3130323430783020ull,0x3009090a20303836ull,
0x3030306530306478ull,0x3063303878302031ull,0x3178302030383631ull,0x2031303866303030ull,
0x3164333034307830ull,0x783009090a203030ull,0x3931343034303033ull,0x3030316365783020ull,
0x3032783020303837ull,0x3020393034303030ull,0x3837383130343078ull,0x30783009090a2030ull,
0x2039303430323030ull,0x3730303030637830ull,0x3730337830203038ull,0x7830206466333063ull,
0x3864376330306336ull,0x3830783009090a20ull,0x3020313030323030ull,0x3837303032346578ull,
0x3030303178302030ull,0x3078302031303230ull,0x2030383763333034ull,0x303031783009090aull,
0x7830203930303831ull,0x3330303030303030ull,0x3333303031783020ull,0x3030783020333030ull,
0x0a20303832313030ull,0x6631363878300909ull,0x3078302033306566ull,0x2030303030303030ull,
0x3730303030337830ull,0x3034367830206466ull,0x090a203864373831ull,0x6632303061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030663230303178ull,0x3030303078302033ull,
0x09090a2030383231ull,0x3430313030337830ull,0x3134637830203931ull,0x7830203038373030ull,
0x3831633833343034ull,0x3832303032783020ull,0x3009090a20633163ull,0x3165303030303278ull,
0x3030343078302039ull,0x3278302030383738ull,0x2031326538663330ull,0x6666666666307830ull,
0x783009090a206666ull,0x3532633866333032ull,0x6666666630783020ull,0x3033783020666666ull,
0x3020313230313430ull,0x3837303031636578ull,0x33783009090a2030ull,0x2035323231343030ull,
0x3730303163657830ull,0x3030327830203038ull,0x7830206331653838ull,0x3831633839303032ull,
0x3030783009090a20ull,0x3020643065303230ull,0x3837303030306378ull,0x3230303078302030ull,
0x6378302031316330ull,0x2030383730303030ull,0x306331783009090aull,0x7830203931656430ull,
0x3038376333323430ull,0x6430303062783020ull,0x3030783020393165ull,0x0a20343837383132ull,
0x3030303078300909ull,0x6578302031306531ull,0x2034383738313234ull,0x3030313030337830ull,
0x3163657830203130ull,0x090a203238373030ull,0x3063373033783009ull,0x6336783020646631ull,
0x3020386437303130ull,0x3034303130303378ull,0x3031346378302039ull,0x09090a2030383730ull,
0x3065313030317830ull,0x3030307830203330ull,0x7830203038323130ull,0x6466373063373033ull,
0x3431303436783020ull,0x3009090a20386437ull,0x3030323430306178ull,0x3030303078302033ull,
0x3178302030303030ull,0x2033303032343030ull,0x3231303030307830ull,0x783009090a203038ull,
0x3931323031303033ull,0x3030313463783020ull,0x3032783020303837ull,0x3020643163386633ull,
0x6666666666663078ull,0x33783009090a2066ull,0x2064663764633730ull,0x3738303263367830ull,
0x3030317830203864ull,0x7830203130366430ull,0x3038376333323430ull,0x3033783009090a20ull,
0x3020643165303430ull,0x3837303031636578ull,0x3030306178302030ull,0x3078302031306334ull,
0x2030383231303234ull,0x303032783009090aull,0x7830203931633030ull,0x3038376331303430ull,
0x3032303033783020ull,0x3463783020313030ull,0x0a20303837303031ull,0x3230303078300909ull,
0x6378302064306330ull,0x2030383730303030ull,0x3066303031327830ull,0x3064317830203831ull,
0x090a203030656630ull,0x3065303064783009ull,0x3061783020313063ull,0x3020303837303063ull,
0x3065313030633078ull,0x6633346578302031ull,0x09090a2030383730ull,0x3330303830337830ull,
0x3434367830206466ull,0x7830206164373430ull,0x3330306335303031ull,0x3130303030783020ull,
0x3009090a20303832ull,0x3130383130303178ull,0x3030303078302064ull,0x3378302033303030ull,
0x2039303430313030ull,0x3730303134657830ull,0x783009090a203038ull,0x3330656666313638ull,
0x3030303030783020ull,0x3033783020303030ull,0x3020646666303330ull,0x6437633030343678ull,
0x61783009090a2038ull,0x2033303039353030ull,0x3030303030307830ull,0x3030317830203030ull,
0x7830203330303935ull,0x3038323130303030ull,0x3033783009090a20ull,0x3020313034303130ull,
0x3837303031346378ull,0x3334303478302030ull,0x3278302030303038ull,0x2038313038323030ull,
0x303032783009090aull,0x7830203130633030ull,0x3038373830303430ull,0x3866333032783020ull,
0x6630783020313263ull,0x0a20666666666666ull,0x6633303278300909ull,0x3078302035323038ull,
0x2066666666666666ull,0x3031343030337830ull,0x3163657830203132ull,0x090a203038373030ull,
0x3134303033783009ull,0x6365783020353232ull,0x3020303837303031ull,0x3163383830303278ull,
0x3930303278302038ull,0x09090a2030303038ull,0x6330323030307830ull,0x3030637830203131ull,
0x7830203038373030ull,0x6430303032303030ull,0x3030303063783020ull,0x3009090a20303837ull,
0x3065643030303178ull,0x3332343078302031ull,0x3178302034383763ull,0x2039316564303063ull,
0x3763333234307830ull,0x783009090a203038ull,0x3130653130303030ull,0x3831323465783020ull,
0x6362783020343837ull,0x3020313065643030ull,0x3837303032303078ull,0x30783009090a2030ull,
0x2031306531303063ull,0x3730303234657830ull,0x3030337830203038ull,0x7830206431653031ull,
0x3238373030313463ull,0x3033783009090a20ull,0x3020646666303130ull,0x6437633030343678ull,
0x3430303178302038ull,0x3078302033303035ull,0x2030383231303030ull,0x313638783009090aull,
0x7830203330656666ull,0x3030303030303030ull,0x6330303032783020ull,0x3430783020393038ull,
0x0a20303837303132ull,0x3030343178300909ull,0x3078302031303065ull,0x2030383763333234ull,
0x3430653030647830ull,0x6330617830203130ull,0x090a203038373030ull,0x3030303033783009ull,
0x3030783020333030ull,0x3020303031303030ull,0x3061303030303278ull,0x3030343078302031ull,
0x09090a2030383734ull,0x3030323030337830ull,0x3134637830203530ull,0x7830203038373030ull,
0x3130306530303831ull,0x6333323430783020ull,0x3009090a20303837ull,0x3038633030303278ull,
0x3032343078302035ull,0x6478302030383734ull,0x2031303230653030ull,0x3730306330617830ull,
0x7d0a7d090a203138ull,0x0a7b2065646f630aull,0x203d20656d616e09ull,0x6373657270375a5full,
0x4c4530624c496e61ull,0x5066507645453162ull,0x6969695f3053664bull,0x3d206d656d6c090aull,
0x6d656d73090a3020ull,0x72090a3436203d20ull,0x3031203d20206765ull,0x3d2020726162090aull,
0x736e6f63090a3120ull,0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,
0x6d756e6765730909ull,0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,
0x2020207365747962ull,0x656d09090a38203dull,0x300909090a7b206dull,0x3030303030303078ull,
0x6666666678302031ull,0x09090a2066666666ull,0x6962090a7d090a7dull,0x0a7b2065646f636eull,
0x6337303378300909ull,0x3678302064663964ull,0x2038633734313263ull,0x3234303030617830ull,
0x3234307830203530ull,0x090a203038373030ull,0x3430303061783009ull,0x3430783020393063ull,
0x3020303035303032ull,0x3032303130303378ull,0x3031346378302064ull,0x09090a2030303530ull,
0x3430333030347830ull,0x3030307830203930ull,0x7830203030353831ull,0x3930386430303031ull,
0x6333323430783020ull,0x3009090a20303832ull,0x3130303030306178ull,0x3030343078302031ull,
0x3278302030383730ull,0x2039313830303030ull,0x3738303034307830ull,0x783009090a203038ull,
0x3130383034303033ull,0x3030316365783020ull,0x3033783020303837ull,0x3020353163303230ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2038303838303030ull,0x6365353031327830ull,
0x3030647830203030ull,0x7830203130303065ull,0x3038373030633038ull,0x3030783009090a20ull,
0x3020353034303230ull,0x3837303030306378ull,0x3030303278302030ull,0x3078302039303830ull,
0x2030383734303034ull,0x303033783009090aull,0x7830206430346432ull,0x3064373031326336ull,
0x3230303430783020ull,0x3465783020313030ull,0x0a20303837303032ull,0x3030306178300909ull,
0x3078302064663730ull,0x2038633734313063ull,0x6330303030327830ull,0x3034307830203130ull,
0x090a203038363530ull,0x3032303033783009ull,0x3463783020313030ull,0x3020303836313031ull,
0x3063633030303278ull,0x3032343078302031ull,0x09090a2030383631ull,0x3030653030647830ull,
0x6330387830203130ull,0x7830203038363130ull,0x3130386630303031ull,0x6433303430783020ull,
0x3009090a20303031ull,0x3034303430303378ull,0x3031636578302064ull,0x3278302030383730ull,
0x2039303430303030ull,0x3763303034307830ull,0x783009090a203038ull,0x3930343032303030ull,
0x3030303063783020ull,0x3033783020303837ull,0x3020646633306337ull,0x6437633030633678ull,
0x30783009090a2038ull,0x2031303032303038ull,0x3730303234657830ull,0x3030317830203038ull,
0x7830203130323030ull,0x3038376333303430ull,0x3031783009090a20ull,0x3020393030383130ull,
0x3030303030303078ull,0x3330303178302033ull,0x3078302033303033ull,0x2030383231303030ull,
0x313638783009090aull,0x7830203330656666ull,0x3030303030303030ull,0x3030303033783020ull,
0x3436783020646639ull,0x0a20386437383130ull,0x3230306178300909ull,0x3078302033303066ull,
0x2030303030303030ull,0x3066323030317830ull,0x3030307830203330ull,0x090a203038323130ull,
0x3031303033783009ull,0x3463783020643034ull,0x3020303837303031ull,0x3036383434303478ull,
0x3230303278302063ull,0x09090a2063313638ull,0x6530303030327830ull,0x3034307830206430ull,
0x7830203038373830ull,0x3132653866333032ull,0x6666666630783020ull,0x3009090a20666666ull,
0x3236386633303278ull,0x6666663078302035ull,0x3378302066666666ull,0x2031323031343030ull,
0x3730303163657830ull,0x783009090a203038ull,0x3532323134303033ull,0x3030316365783020ull,
0x3032783020303837ull,0x3020633165383830ull,0x3036383930303278ull,0x30783009090a2063ull,
0x2064306530323030ull,0x3730303030637830ull,0x3030307830203038ull,0x7830203131363032ull,
0x3038373030303063ull,0x6331783009090a20ull,0x3020643065643030ull,0x3837633332343078ull,
0x3030306278302030ull,0x3078302064306564ull,0x2034383763303230ull,0x303030783009090aull,
0x7830203130653130ull,0x3438376330323465ull,0x3031303033783020ull,0x6365783020313030ull,
0x0a20323837303031ull,0x6337303378300909ull,0x3678302064663130ull,0x2038643730313063ull,
0x3430313030337830ull,0x3134637830203930ull,0x090a203038373030ull,0x6531303031783009ull,
0x3030783020333030ull,0x3020303832313030ull,0x6639306337303378ull,0x3130343678302064ull,
0x09090a2038643734ull,0x3230313030337830ull,0x3134637830203130ull,0x7830203030353130ull,
0x6430303030303132ull,0x3530343430783020ull,0x3009090a20303035ull,0x3036303430303378ull,
0x3031636578302064ull,0x3278302030303531ull,0x2031303030303030ull,0x3564303034307830ull,
0x783009090a203030ull,0x6430303032303030ull,0x3130303063783020ull,0x6330783020303035ull,
0x3020313065313030ull,0x3035316633346578ull,0x33783009090a2030ull,0x2064663330303830ull,
0x3734303434367830ull,0x3030317830203864ull,0x7830203130343030ull,0x3038376333303430ull,
0x3031783009090a20ull,0x3020333030353530ull,0x3832313030303078ull,0x3130303178302030ull,
0x3078302064313038ull,0x2033303030303030ull,0x303033783009090aull,0x7830203130303031ull,
0x3038373030313465ull,0x6666313638783020ull,0x3030783020333065ull,0x0a20303030303030ull,
0x3430303378300909ull,0x3678302064666630ull,0x2038643763303034ull,0x3032353030617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3235303031783009ull,0x3030783020333030ull,
0x3020303832313030ull,0x3030303130303378ull,0x3031346378302039ull,0x09090a2030383730ull,
0x3438343430347830ull,0x3030327830203830ull,0x7830206330343830ull,0x3930363030303032ull,
0x3030303430783020ull,0x3009090a20303837ull,0x3236386633303278ull,0x6666663078302031ull,
0x3278302066666666ull,0x2035323438663330ull,0x6666666666307830ull,0x783009090a206666ull,
0x3132303134303033ull,0x3030316365783020ull,0x3033783020303837ull,0x3020353232313430ull,
0x3837303031636578ull,0x32783009090a2030ull,0x2063303638383030ull,0x3438393030327830ull,
0x3030307830203830ull,0x7830203131363032ull,0x3038373030303063ull,0x3030783009090a20ull,
0x3020643034303230ull,0x3837303030306378ull,0x3030303178302030ull,0x3078302039306564ull,
0x2034383763333234ull,0x306331783009090aull,0x7830206430656430ull,0x3038376333323430ull,
0x3130303030783020ull,0x3465783020313065ull,0x0a20343837633032ull,0x3030636278300909ull,
0x3078302039306564ull,0x2030383738303230ull,0x6531303063307830ull,0x3234657830203130ull,
0x090a203038373830ull,0x3031303033783009ull,0x3463783020643165ull,0x3020323837303031ull,
0x6666303130303378ull,0x3030343678302064ull,0x09090a2038643763ull,0x3065333030317830ull,
0x3030307830203330ull,0x7830203038323130ull,0x3330656666313638ull,0x3030303030783020ull,
0x3009090a20303030ull,0x3038633030303278ull,0x3132343078302039ull,0x3178302030383734ull,
0x2031303065303034ull,0x3763333234307830ull,0x783009090a203038ull,0x3130343065303064ull,
0x3030633061783020ull,0x3033783020303837ull,0x3020333030303030ull,0x3031303030303078ull,
0x32783009090a2030ull,0x2031306330303030ull,0x3734303034307830ull,0x3030337830203038ull,
0x7830203530303032ull,0x3038373030313463ull,0x3831783009090a20ull,0x3020313030653030ull,
0x3837633332343078ull,0x3030303278302030ull,0x3078302035303863ull,0x2030383734303234ull,
0x303064783009090aull,0x7830203130323065ull,0x3138373030633061ull,0x630a7d0a7d090a20ull,
0x6e090a7b2065646full,0x5a5f203d20656d61ull,0x6e61637365727037ull,0x30624c4531624c49ull,
0x664b506650764545ull,0x090a6969695f3053ull,0x30203d206d656d6cull,0x3d206d656d73090aull,
0x676572090a343620ull,0x090a3031203d2020ull,0x31203d2020726162ull,0x2074736e6f63090aull,
0x6765730909090a7bull,0x63203d20656d616eull,0x0909090a74736e6full,0x20206d756e676573ull,
0x6f0909090a31203dull,0x3d20207465736666ull,0x79620909090a3020ull,0x203d202020736574ull,
0x206d656d09090a34ull,0x3078300909090a7bull,0x2031303030303030ull,0x0a7d090a7d09090aull,
0x65646f636e696209ull,0x33783009090a7b20ull,0x2064663964633730ull,0x3734313263367830ull,
0x3030617830203863ull,0x7830203530323430ull,0x3038373030323430ull,0x3061783009090a20ull,
0x3020393063343030ull,0x3035303032343078ull,0x3130303378302030ull,0x6378302064303230ull,
0x2030303530303134ull,0x303034783009090aull,0x7830203930343033ull,0x3030353831303030ull,
0x6430303031783020ull,0x3430783020393038ull,0x0a20303832633332ull,0x3030306178300909ull,
0x3078302031313030ull,0x2030383730303034ull,0x3830303030327830ull,0x3034307830203130ull,
0x090a203038373830ull,0x3034303033783009ull,0x6365783020643038ull,0x3020303837303031ull,
0x3032303030303278ull,0x3030343078302039ull,0x09090a2030383730ull,0x3030323030337830ull,
0x3134637830203931ull,0x7830203038373030ull,0x6430383030303032ull,0x6330303430783020ull,
0x3009090a20303837ull,0x3134303230303378ull,0x3031346378302035ull,0x3278302030383730ull,
0x2031306363303030ull,0x3738313234307830ull,0x783009090a203038ull,0x3130303065303064ull,
0x3030633038783020ull,0x3030783020303837ull,0x3020393036303230ull,0x3837303030306378ull,
0x32783009090a2030ull,0x2039306363303030ull,0x3734313234307830ull,0x3030647830203038ull,
0x7830203930343065ull,0x3038373030633038ull,0x3032783009090a20ull,0x3020643038303030ull,
0x3837343030343078ull,0x3430303378302030ull,0x6578302064313630ull,0x2030383730303163ull,
0x303032783009090aull,0x7830206430363030ull,0x3038376331303430ull,0x3230303830783020ull,
0x3465783020313030ull,0x0a20303837303032ull,0x3230303078300909ull,0x6378302035303630ull,
0x2030383730303030ull,0x3330633730337830ull,0x3063367830206466ull,0x090a203863376330ull,
0x3230303430783009ull,0x3465783020313030ull,0x3020303837383032ull,0x3032303030303178ull,
0x3330343078302031ull,0x09090a2030383763ull,0x3038313030317830ull,0x3030307830203930ull,
0x7830203330303030ull,0x3330303133303031ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3065666631363878ull,0x3030303078302033ull,0x3378302030303030ull,0x2064663930303030ull,
0x3738313034367830ull,0x783009090a203863ull,0x3330306432303061ull,0x3030303030783020ull,
0x3031783020303030ull,0x3020333030643230ull,0x3832303030303078ull,0x33783009090a2030ull,
0x2064303430313030ull,0x3730303134637830ull,0x3430347830203038ull,0x7830206330363834ull,
0x6331363832303032ull,0x3032783009090a20ull,0x3020643065303030ull,0x3837383030343078ull,
0x6633303278302030ull,0x3078302031326538ull,0x2066666666666666ull,0x333032783009090aull,
0x7830203532363866ull,0x6666666666666630ull,0x3134303033783020ull,0x6365783020313230ull,
0x0a20303837303031ull,0x3430303378300909ull,0x6578302035323231ull,0x2030383730303163ull,
0x6538383030327830ull,0x3030327830206331ull,0x090a206330363839ull,0x3032303030783009ull,
0x3063783020643065ull,0x3020303837303030ull,0x3136303230303078ull,0x3030306378302031ull,
0x09090a2030383730ull,0x6564303063317830ull,0x3234307830206430ull,0x7830203038376333ull,
0x6430656430303062ull,0x6330323030783020ull,0x3009090a20343837ull,0x3065313030303078ull,
0x3032346578302031ull,0x3378302034383763ull,0x2031303030313030ull,0x3730303163657830ull,
0x783009090a203238ull,0x6466313063373033ull,0x3031306336783020ull,0x3033783020386337ull,
0x3020393034303130ull,0x3837303031346378ull,0x31783009090a2030ull,0x2033303063313030ull,
0x3230303030307830ull,0x3730337830203038ull,0x7830206466393063ull,0x3863373431303436ull,
0x3061783009090a20ull,0x3020333030303430ull,0x3030303030303078ull,0x3430303178302030ull,
0x3078302033303030ull,0x2030383230303030ull,0x303033783009090aull,0x7830206430323031ull,
0x3038373030313463ull,0x3866333032783020ull,0x6630783020643136ull,0x0a20666666666666ull,
0x6337303378300909ull,0x3678302064663764ull,0x2038633738303263ull,0x3664303030317830ull,
0x3234307830203130ull,0x090a203038376333ull,0x3034303033783009ull,0x6365783020643165ull,
0x3020303837303031ull,0x3063343030306178ull,0x3032343078302031ull,0x09090a2030383230ull,
0x3630303030327830ull,0x3034307830206430ull,0x7830203038376331ull,0x3130303032303033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3036303230303078ull,0x3030306378302064ull,
0x3278302030383730ull,0x2063303066303031ull,0x6566303064317830ull,0x783009090a203030ull,
0x3130363065303064ull,0x3030633061783020ull,0x6330783020303837ull,0x3020313065313030ull,
0x3837306633346578ull,0x33783009090a2030ull,0x2064663330303830ull,0x3734303434367830ull,
0x3030317830206163ull,0x7830203330306135ull,0x3038323030303030ull,0x3031783009090a20ull,
0x3020643130383130ull,0x3030303030303078ull,0x3130303378302033ull,0x6578302039303430ull,
0x2030383730303134ull,0x313638783009090aull,0x7830203330656666ull,0x3030303030303030ull,
0x3034303033783020ull,0x3436783020646666ull,0x0a20386337633030ull,0x3530306178300909ull,
0x3078302033303037ull,0x2030303030303030ull,0x3037353030317830ull,0x3030307830203330ull,
0x090a203038323030ull,0x3031303033783009ull,0x3463783020313034ull,0x3020303837303031ull,
0x3030383434303478ull,0x3230303278302030ull,0x09090a2063303038ull,0x3630303030327830ull,
0x3034307830203130ull,0x7830203038373830ull,0x3132363866333032ull,0x6666666630783020ull,
0x3009090a20666666ull,0x3230386633303278ull,0x6666663078302035ull,0x3378302066666666ull,
0x2031323031343030ull,0x3730303163657830ull,0x783009090a203038ull,0x3532323134303033ull,
0x3030316365783020ull,0x3032783020303837ull,0x3020633036383830ull,0x3030383930303278ull,
0x30783009090a2030ull,0x2031313630323030ull,0x3730303030637830ull,0x3030307830203038ull,
0x7830206430303032ull,0x3038373030303063ull,0x3031783009090a20ull,0x3020313065643030ull,
0x3837633332343078ull,0x3030633178302034ull,0x3078302064306564ull,0x2030383763333234ull,
0x303030783009090aull,0x7830203130653130ull,0x3438376330323465ull,0x6430306362783020ull,
0x3030783020313065ull,0x0a20303837303032ull,0x3030633078300909ull,0x6578302031306531ull,
0x2030383730303234ull,0x6530313030337830ull,0x3134637830206431ull,0x090a203238373030ull,
0x3031303033783009ull,0x3436783020646666ull,0x3020386337633030ull,0x3030333430303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6566663136387830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3530386330303032ull,0x3831323430783020ull,0x3009090a20303837ull,
0x3030653030383178ull,0x3332343078302031ull,0x6478302030383763ull,0x2031303230653030ull,
0x3730306330617830ull,0x783009090a203038ull,0x3530386330303032ull,0x3431323430783020ull,
0x3431783020303837ull,0x3020313030653030ull,0x3837633332343078ull,0x64783009090a2030ull,
0x2031303230653030ull,0x3730306330617830ull,0x7d0a7d090a203138ull,0x0a7b2065646f630aull,
0x203d20656d616e09ull,0x6373657270375a5full,0x4c4530624c496e61ull,0x5066507645453062ull,
0x6969695f3053664bull,0x3d206d656d6c090aull,0x6d656d73090a3020ull,0x72090a3436203d20ull,
0x3031203d20206765ull,0x3d2020726162090aull,0x736e6f63090a3120ull,0x730909090a7b2074ull,
0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x6d756e6765730909ull,0x09090a31203d2020ull,
0x2074657366666f09ull,0x0909090a30203d20ull,0x2020207365747962ull,0x656d09090a38203dull,
0x300909090a7b206dull,0x3030303030303078ull,0x6666666678302031ull,0x09090a2066666666ull,
0x6962090a7d090a7dull,0x0a7b2065646f636eull,0x6337303378300909ull,0x3678302064663964ull,
0x2038633734313263ull,0x3234303030617830ull,0x3234307830203530ull,0x090a203038373030ull,
0x3430303061783009ull,0x3430783020393063ull,0x3020303035303032ull,0x3032303130303378ull,
0x3031346378302064ull,0x09090a2030303530ull,0x3430333030347830ull,0x3030307830203930ull,
0x7830203030353831ull,0x3930386430303031ull,0x6333323430783020ull,0x3009090a20303832ull,
0x3130303030306178ull,0x3030343078302035ull,0x3278302030383730ull,0x2031306130303030ull,
0x3738303034307830ull,0x783009090a203038ull,0x6430613034303033ull,0x3030316365783020ull,
0x3032783020303837ull,0x3020393032303030ull,0x3837303030343078ull,0x33783009090a2030ull,
0x2039313030323030ull,0x3730303134637830ull,0x3030327830203038ull,0x7830203130613030ull,
0x3038376330303430ull,0x3033783009090a20ull,0x3020313134303230ull,0x3837303031346378ull,
0x3030303278302030ull,0x3078302039306363ull,0x2030383738313234ull,0x303030783009090aull,
0x7830203930303032ull,0x3038373030303063ull,0x6330303032783020ull,0x3430783020313063ull,
0x0a20303837303132ull,0x6530306478300909ull,0x3878302039303430ull,0x2030383730306330ull,
0x3030653030647830ull,0x6330387830203130ull,0x090a203038373030ull,0x3030303032783009ull,
0x3430783020643061ull,0x3020303837343030ull,0x3136303430303378ull,0x3031636578302064ull,
0x09090a2030383730ull,0x3630303030327830ull,0x3034307830206430ull,0x7830203038376331ull,
0x3130303230303830ull,0x3830323465783020ull,0x3009090a20303837ull,0x3036303230303078ull,
0x3030306378302035ull,0x3378302030383730ull,0x2064663330633730ull,0x3763303063367830ull,
0x783009090a203863ull,0x3130303230303430ull,0x3030323465783020ull,0x3031783020303837ull,
0x3020313032303030ull,0x3837633330343078ull,0x31783009090a2030ull,0x2039303038313030ull,
0x3030303030307830ull,0x3030317830203330ull,0x7830203330303133ull,0x3038323030303030ull,
0x3638783009090a20ull,0x3020333065666631ull,0x3030303030303078ull,0x3030303378302030ull,
0x3678302064666230ull,0x2038633738313034ull,0x303061783009090aull,0x7830203330306432ull,
0x3030303030303030ull,0x6432303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,
0x3130303378300909ull,0x6378302064303430ull,0x2030383730303134ull,0x3638353430347830ull,
0x3030327830206330ull,0x090a206331363832ull,0x3030303032783009ull,0x3430783020643065ull,
0x3020303837383030ull,0x3265386633303278ull,0x6666663078302031ull,0x09090a2066666666ull,
0x3638663330327830ull,0x6666307830203532ull,0x7830206666666666ull,0x3132303134303033ull,
0x3030316365783020ull,0x3009090a20303837ull,0x3232313430303378ull,0x3031636578302035ull,
0x3278302030383730ull,0x2063316538383030ull,0x3638393030327830ull,0x783009090a206330ull,
0x6430653032303030ull,0x3030303063783020ull,0x3030783020303837ull,0x3020313136303230ull,
0x3837303030306378ull,0x31783009090a2030ull,0x2064306564303063ull,0x3763333234307830ull,
0x3030627830203038ull,0x7830206430656430ull,0x3438376330323030ull,0x3030783009090a20ull,
0x3020313065313030ull,0x3837633032346578ull,0x3130303378302034ull,0x6578302031303030ull,
0x2032383730303163ull,0x373033783009090aull,0x7830206466313063ull,0x3863373031306336ull,
0x3031303033783020ull,0x3463783020393034ull,0x0a20303837303031ull,0x3130303178300909ull,
0x3078302033303063ull,0x2030383230303030ull,0x6230633730337830ull,0x3034367830206466ull,
0x090a203863373431ull,0x3031303033783009ull,0x3463783020313032ull,0x3020303035303031ull,
0x3030303030313278ull,0x3034343078302064ull,0x09090a2030303534ull,0x3630343030337830ull,
0x3163657830206430ull,0x7830203030353030ull,0x3130303030303032ull,0x6330303430783020ull,
0x3009090a20303035ull,0x3030303230303078ull,0x3030306378302064ull,0x3078302030303530ull,
0x2031306531303063ull,0x3530663334657830ull,0x783009090a203030ull,0x6466333030383033ull,
0x3430343436783020ull,0x3031783020386337ull,0x3020313034303030ull,0x3837633330343078ull,
0x31783009090a2030ull,0x2033303033353030ull,0x3230303030307830ull,0x3030317830203038ull,
0x7830206431303831ull,0x3330303030303030ull,0x3033783009090a20ull,0x3020313030303130ull,
0x3837303031346578ull,0x6631363878302030ull,0x3078302033306566ull,0x2030303030303030ull,
0x303033783009090aull,0x7830206466663035ull,0x3863376330303436ull,0x3035303061783020ull,
0x3030783020333030ull,0x0a20303030303030ull,0x3530303178300909ull,0x3078302033303030ull,
0x2030383230303030ull,0x3030313030337830ull,0x3134637830203930ull,0x090a203038373030ull,
0x3835343034783009ull,0x3032783020383034ull,0x3020633034383030ull,0x3036303030303278ull,
0x3030343078302039ull,0x09090a2030383730ull,0x3638663330327830ull,0x6666307830203132ull,
0x7830206666666666ull,0x3532343866333032ull,0x6666666630783020ull,0x3009090a20666666ull,
0x3230313430303378ull,0x3031636578302031ull,0x3378302030383730ull,0x2035323231343030ull,
0x3730303163657830ull,0x783009090a203038ull,0x6330363838303032ull,0x3839303032783020ull,
0x3030783020383034ull,0x3020313136303230ull,0x3837303030306378ull,0x30783009090a2030ull,
0x2064303430323030ull,0x3730303030637830ull,0x3030317830203038ull,0x7830203930656430ull,
0x3438376333323430ull,0x6331783009090a20ull,0x3020643065643030ull,0x3837633332343078ull,
0x3030303078302030ull,0x6578302031306531ull,0x2034383763303234ull,0x306362783009090aull,
0x7830203930656430ull,0x3038373830323030ull,0x3130306330783020ull,0x3465783020313065ull,
0x0a20303837383032ull,0x3130303378300909ull,0x6378302064316530ull,0x2032383730303134ull,
0x6630313030337830ull,0x3034367830206466ull,0x090a203863376330ull,0x6333303031783009ull,
0x3030783020333030ull,0x3020303832303030ull,0x3065666631363878ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3863303030327830ull,0x3234307830203530ull,0x7830203038373831ull,
0x3130306530303831ull,0x6333323430783020ull,0x3009090a20303837ull,0x3032306530306478ull,
0x3063306178302031ull,0x3278302030383730ull,0x2035303863303030ull,0x3730313234307830ull,
0x783009090a203038ull,0x3130306530303431ull,0x6333323430783020ull,0x3064783020303837ull,
0x3020313032306530ull,0x3837303063306178ull,0x0a7d0a7d090a2031ull,0x090a7b2065646f63ull,
0x5f203d20656d616eull,0x6f66696e7530315aull,0x5366506464416d72ull,0x6d6c090a6969695full,
0x090a30203d206d65ull,0x34203d206d656d73ull,0x2020676572090a38ull,0x726162090a35203dull,
0x62090a31203d2020ull,0x7b2065646f636e69ull,0x303061783009090aull,0x7830203530303030ull,
0x3063373030303430ull,0x3430303061783020ull,0x3430783020643063ull,0x0a20303837303032ull,
0x3030303278300909ull,0x3078302031303264ull,0x2030303563303234ull,0x3030323030337830ull,
0x3134637830203130ull,0x090a203030353030ull,0x6330303032783009ull,0x3430783020313063ull,
0x3020303035303032ull,0x3030306530306478ull,0x3063303878302031ull,0x09090a2030303530ull,
0x3631303030307830ull,0x3234657830203130ull,0x7830203030353030ull,0x3330656666313638ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3032343030306178ull,0x3032343078302039ull,
0x3178302030383730ull,0x2031303464303030ull,0x3763333234307830ull,0x783009090a203038ull,
0x3131343031303033ull,0x3030313463783020ull,0x3036783020303837ull,0x3020313036303430ull,
0x3837303030303878ull,0x32783009090a2030ull,0x2031303030303030ull,0x3734303034307830ull,
0x3030337830203038ull,0x7830206430303032ull,0x3038373030313463ull,0x3032783009090a20ull,
0x3020343034383130ull,0x3038653330313278ull,0x3130303378302063ull,0x3678302064663164ull,
0x2038633763303234ull,0x303064783009090aull,0x7830203530363065ull,0x3038373030633038ull,
0x6430303062783020ull,0x3030783020353036ull,0x0a20303837343032ull,0x6530306478300909ull,
0x6178302035303630ull,0x2030383730306330ull,0x3030303030337830ull,0x3030307830203330ull,
0x090a203038323030ull,0x3030303032783009ull,0x3430783020313030ull,0x3020303837383030ull,
0x3030303230303378ull,0x3031346378302031ull,0x09090a2030383730ull,0x3863303030327830ull,
0x3234307830203530ull,0x7830203038373030ull,0x3130323065303064ull,0x3030633038783020ull,
0x3009090a20303837ull,0x3036643030306278ull,0x3032303078302031ull,0x6478302030383730ull,
0x2031303230653030ull,0x3730306330617830ull,0x7d0a7d090a203138ull,0x000000000000000aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_10",(char*)__deviceText_$sm_10$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"fcd5228aa931be9f",(char*)"scanLargeArray.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0};
# 5 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.c" 2
# 1 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 1
# 74 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/temp/cuda/bin/../include/host_defines.h" 1
# 75 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 2
# 100 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h"
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
# 215 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/temp/cuda/bin/../include/common_functions.h" 1
# 68 "/home/normal/temp/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/temp/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/home/normal/temp/cuda/bin/../include/common_functions.h" 2

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
# 93 "/home/normal/temp/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/temp/cuda/bin/../include/math_functions.h" 1 3
# 844 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) int __cuda_error_not_implememted(void); int __cuda_error_not_implememted(void);
# 900 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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

# 1 "/home/normal/temp/cuda/bin/../include/device_functions.h" 1 3
# 347 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/math_constants.h" 1 3
# 348 "/home/normal/temp/cuda/bin/../include/device_functions.h" 2 3



static int __cuda___isnan(double a);
static int __cuda___isnanf(float a);
static int __double2int_rz(double);
static unsigned int __double2uint_rz(double);
static long long int __double2ll_rz(double);
static unsigned long long int __double2ull_rz(double);
# 370 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
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
# 1164 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 1185 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
static void __trap(void)
{
  __builtin_trap();
}
# 1207 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
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
# 1393 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
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
# 1470 "/home/normal/temp/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 257 "/home/normal/temp/cuda/bin/../include/sm_11_atomic_functions.h" 3
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
# 1471 "/home/normal/temp/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 118 "/home/normal/temp/cuda/bin/../include/sm_12_atomic_functions.h" 3
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
# 1472 "/home/normal/temp/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 266 "/home/normal/temp/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 690 "/home/normal/temp/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 1473 "/home/normal/temp/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/temp/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1910 "/home/normal/temp/cuda/bin/../include/texture_fetch_functions.h" 3
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
# 1474 "/home/normal/temp/cuda/bin/../include/device_functions.h" 2 3
# 925 "/home/normal/temp/cuda/bin/../include/math_functions.h" 2 3


static int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 949 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 1035 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 1123 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 1244 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
static int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1258 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 1597 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2509 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2541 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2594 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2629 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2655 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 2690 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 3192 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
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
# 3323 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}
# 3855 "/home/normal/temp/cuda/bin/../include/math_functions.h" 3
# 1 "/home/normal/temp/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/home/normal/temp/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
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
# 3856 "/home/normal/temp/cuda/bin/../include/math_functions.h" 2 3
# 94 "/home/normal/temp/cuda/bin/../include/common_functions.h" 2
# 216 "/home/normal/temp/cuda/bin/../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.c" 2
struct __T20;
struct __T21;
struct __T22;
struct __T23;
struct __T24;
struct __T20 {float *__par0;float *__par1;int __par2;int __par3;int __par4;int __dummy_field;};
struct __T21 {float *__par0;const float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T22 {float *__par0;const float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T23 {float *__par0;const float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
struct __T24 {float *__par0;const float *__par1;float *__par2;int __par3;int __par4;int __par5;int __dummy_field;};
# 31 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_00003ee9_00000000_4_scanLargeArray_cpp1_ii_c14de7b3(void) __attribute__((__constructor__));
void __device_stub__Z10uniformAddPfS_iii(float *__par0, float *__par1, int __par2, int __par3, int __par4){auto struct __T20 *__T27;
char __[256]; *(char**)&__T27 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T27->__par0 - (size_t)__T27) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T27->__par1 - (size_t)__T27) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T27->__par2 - (size_t)__T27) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T27->__par3 - (size_t)__T27) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T27->__par4 - (size_t)__T27) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z10uniformAddPfS_iii); (void)cudaLaunch(((char *)__device_stub__Z10uniformAddPfS_iii)); };}
 __attribute__((__weak__)) void __device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii(float *__par0, const float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T21 *__T225;
char __[256]; *(char**)&__T225 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T225->__par0 - (size_t)__T225) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T225->__par1 - (size_t)__T225) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T225->__par2 - (size_t)__T225) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T225->__par3 - (size_t)__T225) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T225->__par4 - (size_t)__T225) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T225->__par5 - (size_t)__T225) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii); (void)cudaLaunch(((char *)__device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii)); };}

}
template <>
void __globfunc_prescan<((bool)1), ((bool)0)> ( float *__cuda_0,const float *__cuda_1,float *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5)
{ __device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5); }
extern "C" {

 __attribute__((__weak__)) void __device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii(float *__par0, const float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T22 *__T226;
char __[256]; *(char**)&__T226 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T226->__par0 - (size_t)__T226) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T226->__par1 - (size_t)__T226) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T226->__par2 - (size_t)__T226) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T226->__par3 - (size_t)__T226) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T226->__par4 - (size_t)__T226) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T226->__par5 - (size_t)__T226) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii); (void)cudaLaunch(((char *)__device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii)); };}

}
template <>
void __globfunc_prescan<((bool)1), ((bool)1)> ( float *__cuda_0,const float *__cuda_1,float *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5)
{ __device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5); }
extern "C" {

 __attribute__((__weak__)) void __device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii(float *__par0, const float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T23 *__T227;
char __[256]; *(char**)&__T227 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T227->__par0 - (size_t)__T227) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T227->__par1 - (size_t)__T227) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T227->__par2 - (size_t)__T227) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T227->__par3 - (size_t)__T227) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T227->__par4 - (size_t)__T227) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T227->__par5 - (size_t)__T227) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii); (void)cudaLaunch(((char *)__device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii)); };}

}
template <>
void __globfunc_prescan<((bool)0), ((bool)0)> ( float *__cuda_0,const float *__cuda_1,float *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5)
{ __device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5); }
extern "C" {

 __attribute__((__weak__)) void __device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii(float *__par0, const float *__par1, float *__par2, int __par3, int __par4, int __par5){auto struct __T24 *__T228;
char __[256]; *(char**)&__T228 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T228->__par0 - (size_t)__T228) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T228->__par1 - (size_t)__T228) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T228->__par2 - (size_t)__T228) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T228->__par3 - (size_t)__T228) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T228->__par4 - (size_t)__T228) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T228->__par5 - (size_t)__T228) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)__device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii); (void)cudaLaunch(((char *)__device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii)); };}

}
template <>
void __globfunc_prescan<((bool)0), ((bool)1)> ( float *__cuda_0,const float *__cuda_1,float *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5)
{ __device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5); }
extern "C" {
# 85 "/tmp/tmpxft_00003ee9_00000000-1_scanLargeArray.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_00003ee9_00000000_4_scanLargeArray_cpp1_ii_c14de7b3(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z7prescanILb0ELb1EEvPfPKfS0_iii, (char*)"_Z7prescanILb0ELb1EEvPfPKfS0_iii", "_Z7prescanILb0ELb1EEvPfPKfS0_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z7prescanILb0ELb0EEvPfPKfS0_iii, (char*)"_Z7prescanILb0ELb0EEvPfPKfS0_iii", "_Z7prescanILb0ELb0EEvPfPKfS0_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z7prescanILb1ELb1EEvPfPKfS0_iii, (char*)"_Z7prescanILb1ELb1EEvPfPKfS0_iii", "_Z7prescanILb1ELb1EEvPfPKfS0_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z7prescanILb1ELb0EEvPfPKfS0_iii, (char*)"_Z7prescanILb1ELb0EEvPfPKfS0_iii", "_Z7prescanILb1ELb0EEvPfPKfS0_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)__device_stub__Z10uniformAddPfS_iii, (char*)"_Z10uniformAddPfS_iii", "_Z10uniformAddPfS_iii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterShared(__cudaFatCubinHandle, (void**)"s_data");}

}
# 178 "scanLargeArray.cu" 2

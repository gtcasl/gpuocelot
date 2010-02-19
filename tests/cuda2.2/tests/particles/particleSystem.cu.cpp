# 1 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.cpp"
# 1 "particleSystem.cu"
# 233 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) {
# 245 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
}
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 152 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 107 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 53 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 54 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/device_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/driver_types.h" 1 3
# 91 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{
  cudaSuccess = 0,
  cudaErrorMissingConfiguration = 1,
  cudaErrorMemoryAllocation = 2,
  cudaErrorInitializationError = 3,
  cudaErrorLaunchFailure = 4,
  cudaErrorPriorLaunchFailure = 5,
  cudaErrorLaunchTimeout = 6,
  cudaErrorLaunchOutOfResources = 7,
  cudaErrorInvalidDeviceFunction = 8,
  cudaErrorInvalidConfiguration = 9,
  cudaErrorInvalidDevice = 10,
  cudaErrorInvalidValue = 11,
  cudaErrorInvalidPitchValue = 12,
  cudaErrorInvalidSymbol = 13,
  cudaErrorMapBufferObjectFailed = 14,
  cudaErrorUnmapBufferObjectFailed = 15,
  cudaErrorInvalidHostPointer = 16,
  cudaErrorInvalidDevicePointer = 17,
  cudaErrorInvalidTexture = 18,
  cudaErrorInvalidTextureBinding = 19,
  cudaErrorInvalidChannelDescriptor = 20,
  cudaErrorInvalidMemcpyDirection = 21,
  cudaErrorAddressOfConstant = 22,
  cudaErrorTextureFetchFailed = 23,
  cudaErrorTextureNotBound = 24,
  cudaErrorSynchronizationError = 25,
  cudaErrorInvalidFilterSetting = 26,
  cudaErrorInvalidNormSetting = 27,
  cudaErrorMixedDeviceExecution = 28,
  cudaErrorCudartUnloading = 29,
  cudaErrorUnknown = 30,
  cudaErrorNotYetImplemented = 31,
  cudaErrorMemoryValueTooLarge = 32,
  cudaErrorInvalidResourceHandle = 33,
  cudaErrorNotReady = 34,
  cudaErrorInsufficientDriver = 35,
  cudaErrorSetOnActiveProcess = 36,
  cudaErrorNoDevice = 38,
  cudaErrorStartupFailure = 0x7f,
  cudaErrorApiFailureBase = 10000
};





enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned = 0,
  cudaChannelFormatKindUnsigned = 1,
  cudaChannelFormatKindFloat = 2,
  cudaChannelFormatKindNone = 3
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
  cudaMemcpyHostToDevice = 1,
  cudaMemcpyDeviceToHost = 2,
  cudaMemcpyDeviceToDevice = 3
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





struct cudaFuncAttributes
{
   size_t sharedSizeBytes;
   size_t constSizeBytes;
   size_t localSizeBytes;
   int maxThreadsPerBlock;
   int numRegs;
   int __cudaReserved[8];
};





enum cudaComputeMode
{
  cudaComputeModeDefault = 0,
  cudaComputeModeExclusive = 1,
  cudaComputeModeProhibited = 2
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
  int integrated;
  int canMapHostMemory;
  int computeMode;
  int __cudaReserved[36];
};
# 319 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef int cudaStream_t;





typedef int cudaEvent_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/texture_types.h" 3
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
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 82 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct char1
{
  signed char x;
 
};


struct uchar1
{
  unsigned char x;
 
};


struct __attribute__((__aligned__(2))) char2
{
  signed char x, y;
 
};


struct __attribute__((__aligned__(2))) uchar2
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


struct __attribute__((__aligned__(4))) char4
{
  signed char x, y, z, w;
 
};


struct __attribute__((__aligned__(4))) uchar4
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


struct __attribute__((__aligned__(4))) short2
{
  short x, y;
 
};


struct __attribute__((__aligned__(4))) ushort2
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


struct __attribute__((__aligned__(8))) short4 { short x, y, z, w; };


struct __attribute__((__aligned__(8))) ushort4 { unsigned short x, y, z, w; };


struct int1
{
  int x;
 
};


struct uint1
{
  unsigned int x;
 
};


struct __attribute__((__aligned__(8))) int2 { int x, y; };


struct __attribute__((__aligned__(8))) uint2 { unsigned int x, y; };


struct int3
{
  int x, y, z;
 
};


struct uint3
{
  unsigned int x, y, z;
 
};


struct __attribute__((__aligned__(16))) int4
{
  int x, y, z, w;
 
};


struct __attribute__((__aligned__(16))) uint4
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
# 258 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct __attribute__((__aligned__(2*sizeof(long int)))) long2
{
  long int x, y;
 
};


struct __attribute__((__aligned__(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
 
};
# 306 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct float1
{
  float x;
 
};


struct __attribute__((__aligned__(8))) float2 { float x, y; };


struct float3
{
  float x, y, z;
 
};


struct __attribute__((__aligned__(16))) float4
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


struct __attribute__((__aligned__(16))) longlong2
{
  long long int x, y;
 
};


struct __attribute__((__aligned__(16))) ulonglong2
{
  unsigned long long int x, y;
 
};


struct double1
{
  double x;
 
};


struct __attribute__((__aligned__(16))) double2
{
  double x, y;
 
};
# 378 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 469 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 55 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 80 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);

extern cudaError_t cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags);
extern cudaError_t cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);
extern cudaError_t cudaHostGetFlags(unsigned int *pFlags, void *pHost);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
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







extern cudaError_t cudaMemset(void *devPtr, int value, size_t count);
extern cudaError_t cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);







extern cudaError_t cudaGetSymbolAddress(void **devPtr, const char *symbol);
extern cudaError_t cudaGetSymbolSize(size_t *size, const char *symbol);







extern cudaError_t cudaGetDeviceCount(int *count);
extern cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
extern cudaError_t cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
extern cudaError_t cudaSetDevice(int device);
extern cudaError_t cudaGetDevice(int *device);
extern cudaError_t cudaSetValidDevices(int *device_arr, int len);
extern cudaError_t cudaSetDeviceFlags( int flags );







extern cudaError_t cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size );
extern cudaError_t cudaBindTexture2D(size_t *offset,const struct textureReference *texref,const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, size_t pitch);
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
extern cudaError_t cudaLaunch(const char *entry);
extern cudaError_t cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func);







extern cudaError_t cudaStreamCreate(cudaStream_t *pStream);
extern cudaError_t cudaStreamDestroy(cudaStream_t stream);
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream);
extern cudaError_t cudaStreamQuery(cudaStream_t stream);







extern cudaError_t cudaEventCreate(cudaEvent_t *event);
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t *event, int flags);
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
extern cudaError_t cudaEventQuery(cudaEvent_t event);
extern cudaError_t cudaEventSynchronize(cudaEvent_t event);
extern cudaError_t cudaEventDestroy(cudaEvent_t event);
extern cudaError_t cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);







extern cudaError_t cudaSetDoubleForDevice(double *d);
extern cudaError_t cudaSetDoubleForHost(double *d);







extern cudaError_t cudaThreadExit(void);
extern cudaError_t cudaThreadSynchronize(void);







extern cudaError_t cudaDriverGetVersion(int *driverVersion);
extern cudaError_t cudaRuntimeGetVersion(int *runtimeVersion);


}
# 108 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 109 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 2 3
# 91 "/usr/local/cuda/bin/../include/driver_types.h"
# 139 "/usr/local/cuda/bin/../include/driver_types.h"
# 151 "/usr/local/cuda/bin/../include/driver_types.h"
# 164 "/usr/local/cuda/bin/../include/driver_types.h"
# 170 "/usr/local/cuda/bin/../include/driver_types.h"
# 182 "/usr/local/cuda/bin/../include/driver_types.h"
# 194 "/usr/local/cuda/bin/../include/driver_types.h"
# 205 "/usr/local/cuda/bin/../include/driver_types.h"
# 216 "/usr/local/cuda/bin/../include/driver_types.h"
# 234 "/usr/local/cuda/bin/../include/driver_types.h"
# 248 "/usr/local/cuda/bin/../include/driver_types.h"
# 260 "/usr/local/cuda/bin/../include/driver_types.h"
# 319 "/usr/local/cuda/bin/../include/driver_types.h"
# 325 "/usr/local/cuda/bin/../include/driver_types.h"
# 331 "/usr/local/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
# 61 "/usr/local/cuda/bin/../include/texture_types.h"
# 68 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 82 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/vector_types.h"
# 96 "/usr/local/cuda/bin/../include/vector_types.h"
# 103 "/usr/local/cuda/bin/../include/vector_types.h"
# 110 "/usr/local/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
# 124 "/usr/local/cuda/bin/../include/vector_types.h"
# 131 "/usr/local/cuda/bin/../include/vector_types.h"
# 138 "/usr/local/cuda/bin/../include/vector_types.h"
# 145 "/usr/local/cuda/bin/../include/vector_types.h"
# 152 "/usr/local/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
# 166 "/usr/local/cuda/bin/../include/vector_types.h"
# 173 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
# 186 "/usr/local/cuda/bin/../include/vector_types.h"
# 193 "/usr/local/cuda/bin/../include/vector_types.h"
# 200 "/usr/local/cuda/bin/../include/vector_types.h"
# 203 "/usr/local/cuda/bin/../include/vector_types.h"
# 206 "/usr/local/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
# 220 "/usr/local/cuda/bin/../include/vector_types.h"
# 227 "/usr/local/cuda/bin/../include/vector_types.h"
# 234 "/usr/local/cuda/bin/../include/vector_types.h"
# 241 "/usr/local/cuda/bin/../include/vector_types.h"
# 258 "/usr/local/cuda/bin/../include/vector_types.h"
# 265 "/usr/local/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
# 313 "/usr/local/cuda/bin/../include/vector_types.h"
# 316 "/usr/local/cuda/bin/../include/vector_types.h"
# 323 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 337 "/usr/local/cuda/bin/../include/vector_types.h"
# 344 "/usr/local/cuda/bin/../include/vector_types.h"
# 351 "/usr/local/cuda/bin/../include/vector_types.h"
# 358 "/usr/local/cuda/bin/../include/vector_types.h"
# 365 "/usr/local/cuda/bin/../include/vector_types.h"
# 378 "/usr/local/cuda/bin/../include/vector_types.h"
# 380 "/usr/local/cuda/bin/../include/vector_types.h"
# 382 "/usr/local/cuda/bin/../include/vector_types.h"
# 384 "/usr/local/cuda/bin/../include/vector_types.h"
# 386 "/usr/local/cuda/bin/../include/vector_types.h"
# 388 "/usr/local/cuda/bin/../include/vector_types.h"
# 390 "/usr/local/cuda/bin/../include/vector_types.h"
# 392 "/usr/local/cuda/bin/../include/vector_types.h"
# 394 "/usr/local/cuda/bin/../include/vector_types.h"
# 396 "/usr/local/cuda/bin/../include/vector_types.h"
# 398 "/usr/local/cuda/bin/../include/vector_types.h"
# 400 "/usr/local/cuda/bin/../include/vector_types.h"
# 402 "/usr/local/cuda/bin/../include/vector_types.h"
# 404 "/usr/local/cuda/bin/../include/vector_types.h"
# 406 "/usr/local/cuda/bin/../include/vector_types.h"
# 408 "/usr/local/cuda/bin/../include/vector_types.h"
# 410 "/usr/local/cuda/bin/../include/vector_types.h"
# 412 "/usr/local/cuda/bin/../include/vector_types.h"
# 414 "/usr/local/cuda/bin/../include/vector_types.h"
# 416 "/usr/local/cuda/bin/../include/vector_types.h"
# 418 "/usr/local/cuda/bin/../include/vector_types.h"
# 420 "/usr/local/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
# 424 "/usr/local/cuda/bin/../include/vector_types.h"
# 426 "/usr/local/cuda/bin/../include/vector_types.h"
# 428 "/usr/local/cuda/bin/../include/vector_types.h"
# 430 "/usr/local/cuda/bin/../include/vector_types.h"
# 432 "/usr/local/cuda/bin/../include/vector_types.h"
# 434 "/usr/local/cuda/bin/../include/vector_types.h"
# 436 "/usr/local/cuda/bin/../include/vector_types.h"
# 438 "/usr/local/cuda/bin/../include/vector_types.h"
# 440 "/usr/local/cuda/bin/../include/vector_types.h"
# 442 "/usr/local/cuda/bin/../include/vector_types.h"
# 444 "/usr/local/cuda/bin/../include/vector_types.h"
# 446 "/usr/local/cuda/bin/../include/vector_types.h"
# 448 "/usr/local/cuda/bin/../include/vector_types.h"
# 450 "/usr/local/cuda/bin/../include/vector_types.h"
# 452 "/usr/local/cuda/bin/../include/vector_types.h"
# 454 "/usr/local/cuda/bin/../include/vector_types.h"
# 456 "/usr/local/cuda/bin/../include/vector_types.h"
# 458 "/usr/local/cuda/bin/../include/vector_types.h"
# 460 "/usr/local/cuda/bin/../include/vector_types.h"
# 469 "/usr/local/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
extern "C" cudaError_t cudaMallocHost(void **, size_t);
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
extern "C" cudaError_t cudaFree(void *);
extern "C" cudaError_t cudaFreeHost(void *);
extern "C" cudaError_t cudaFreeArray(cudaArray *);

extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 153 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 162 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 171 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
extern "C" cudaError_t cudaSetDevice(int);
extern "C" cudaError_t cudaGetDevice(int *);
extern "C" cudaError_t cudaSetValidDevices(int *, int);
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 185 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 198 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
extern "C" const char *cudaGetErrorString(cudaError_t);
# 216 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
extern "C" cudaError_t cudaLaunch(const char *);
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 227 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 238 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 252 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 261 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
extern "C" cudaError_t cudaThreadSynchronize();
# 270 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
{
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
{
auto int e = (((int)sizeof(char)) * 8);




return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);

}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}
# 337 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
}
# 54 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
{
auto cudaPitchedPtr s;

(s.ptr) = d;
(s.pitch) = p;
(s.xsize) = xsz;
(s.ysize) = ysz;

return s;
}

static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
{
auto cudaPos p;

(p.x) = x;
(p.y) = y;
(p.z) = z;

return p;
}

static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
{
auto cudaExtent e;

(e.width) = w;
(e.height) = h;
(e.depth) = d;

return e;
}
# 54 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
{
auto char1 t; (t.x) = x; return t;
}

static inline uchar1 make_uchar1(unsigned char x)
{
auto uchar1 t; (t.x) = x; return t;
}

static inline char2 make_char2(signed char x, signed char y)
{
auto char2 t; (t.x) = x; (t.y) = y; return t;
}

static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
{
auto uchar2 t; (t.x) = x; (t.y) = y; return t;
}

static inline char3 make_char3(signed char x, signed char y, signed char z)
{
auto char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
{
auto uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
{
auto char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
{
auto uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline short1 make_short1(short x)
{
auto short1 t; (t.x) = x; return t;
}

static inline ushort1 make_ushort1(unsigned short x)
{
auto ushort1 t; (t.x) = x; return t;
}

static inline short2 make_short2(short x, short y)
{
auto short2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
{
auto ushort2 t; (t.x) = x; (t.y) = y; return t;
}

static inline short3 make_short3(short x, short y, short z)
{
auto short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
{
auto ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline short4 make_short4(short x, short y, short z, short w)
{
auto short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
{
auto ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline int1 make_int1(int x)
{
auto int1 t; (t.x) = x; return t;
}

static inline uint1 make_uint1(unsigned x)
{
auto uint1 t; (t.x) = x; return t;
}

static inline int2 make_int2(int x, int y)
{
auto int2 t; (t.x) = x; (t.y) = y; return t;
}

static inline uint2 make_uint2(unsigned x, unsigned y)
{
auto uint2 t; (t.x) = x; (t.y) = y; return t;
}

static inline int3 make_int3(int x, int y, int z)
{
auto int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
{
auto uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline int4 make_int4(int x, int y, int z, int w)
{
auto int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
{
auto uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline long1 make_long1(long x)
{
auto long1 t; (t.x) = x; return t;
}

static inline ulong1 make_ulong1(unsigned long x)
{
auto ulong1 t; (t.x) = x; return t;
}

static inline long2 make_long2(long x, long y)
{
auto long2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
{
auto ulong2 t; (t.x) = x; (t.y) = y; return t;
}
# 218 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
{
auto float1 t; (t.x) = x; return t;
}

static inline float2 make_float2(float x, float y)
{
auto float2 t; (t.x) = x; (t.y) = y; return t;
}

static inline float3 make_float3(float x, float y, float z)
{
auto float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline float4 make_float4(float x, float y, float z, float w)
{
auto float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline longlong1 make_longlong1(long long x)
{
auto longlong1 t; (t.x) = x; return t;
}

static inline ulonglong1 make_ulonglong1(unsigned long long x)
{
auto ulonglong1 t; (t.x) = x; return t;
}

static inline longlong2 make_longlong2(long long x, long long y)
{
auto longlong2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
{
auto ulonglong2 t; (t.x) = x; (t.y) = y; return t;
}

static inline double1 make_double1(double x)
{
auto double1 t; (t.x) = x; return t;
}

static inline double2 make_double2(double x, double y)
{
auto double2 t; (t.x) = x; (t.y) = y; return t;
}
# 31 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __u_char; }
extern "C" { typedef unsigned short __u_short; }
extern "C" { typedef unsigned __u_int; }
extern "C" { typedef unsigned long __u_long; }


extern "C" { typedef signed char __int8_t; }
extern "C" { typedef unsigned char __uint8_t; }
extern "C" { typedef signed short __int16_t; }
extern "C" { typedef unsigned short __uint16_t; }
extern "C" { typedef signed int __int32_t; }
extern "C" { typedef unsigned __uint32_t; }

extern "C" { typedef signed long __int64_t; }
extern "C" { typedef unsigned long __uint64_t; }
# 53 "/usr/include/bits/types.h" 3
extern "C" { typedef long __quad_t; }
extern "C" { typedef unsigned long __u_quad_t; }
# 134 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __dev_t; }
extern "C" { typedef unsigned __uid_t; }
extern "C" { typedef unsigned __gid_t; }
extern "C" { typedef unsigned long __ino_t; }
extern "C" { typedef unsigned long __ino64_t; }
extern "C" { typedef unsigned __mode_t; }
extern "C" { typedef unsigned long __nlink_t; }
extern "C" { typedef long __off_t; }
extern "C" { typedef long __off64_t; }
extern "C" { typedef int __pid_t; }
extern "C" { typedef struct __fsid_t { int __val[2]; } __fsid_t; }
extern "C" { typedef long __clock_t; }
extern "C" { typedef unsigned long __rlim_t; }
extern "C" { typedef unsigned long __rlim64_t; }
extern "C" { typedef unsigned __id_t; }
extern "C" { typedef long __time_t; }
extern "C" { typedef unsigned __useconds_t; }
extern "C" { typedef long __suseconds_t; }

extern "C" { typedef int __daddr_t; }
extern "C" { typedef long __swblk_t; }
extern "C" { typedef int __key_t; }


extern "C" { typedef int __clockid_t; }


extern "C" { typedef void *__timer_t; }


extern "C" { typedef long __blksize_t; }




extern "C" { typedef long __blkcnt_t; }
extern "C" { typedef long __blkcnt64_t; }


extern "C" { typedef unsigned long __fsblkcnt_t; }
extern "C" { typedef unsigned long __fsblkcnt64_t; }


extern "C" { typedef unsigned long __fsfilcnt_t; }
extern "C" { typedef unsigned long __fsfilcnt64_t; }

extern "C" { typedef long __ssize_t; }



extern "C" { typedef __off64_t __loff_t; }
extern "C" { typedef __quad_t *__qaddr_t; }
extern "C" { typedef char *__caddr_t; }


extern "C" { typedef long __intptr_t; }


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

__time_t tv_sec;
long tv_nsec;
}; }
# 134 "/usr/include/time.h" 3
extern "C" { struct tm {

int tm_sec;
int tm_min;
int tm_hour;
int tm_mday;
int tm_mon;
int tm_year;
int tm_wday;
int tm_yday;
int tm_isdst;


long tm_gmtoff;
const char *tm_zone;




}; }
# 162 "/usr/include/time.h" 3
extern "C" { struct itimerspec {

timespec it_interval;
timespec it_value;
}; }


struct sigevent;
# 175 "/usr/include/time.h" 3
extern "C" { typedef __pid_t pid_t; }
# 184 "/usr/include/time.h" 3
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" time_t time(time_t *) throw();


extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__));



extern "C" time_t mktime(tm *) throw();
# 200 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw();
# 208 "/usr/include/time.h" 3
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw();
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef
# 28 "/usr/include/xlocale.h" 3
struct __locale_struct {


struct locale_data *__locales[13];


const unsigned short *__ctype_b;
const int *__ctype_tolower;
const int *__ctype_toupper;


const char *__names[13];
} *__locale_t; }
# 218 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw();




extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw();
# 232 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *) throw();



extern "C" tm *localtime(const time_t *) throw();
# 242 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw();




extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 254 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *) throw();


extern "C" char *ctime(const time_t *) throw();
# 265 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw();



extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw();
# 275 "/usr/include/time.h" 3
extern "C" { extern char *__tzname[2]; }
extern "C" { extern int __daylight; }
extern "C" { extern long __timezone; }




extern "C" { extern char *tzname[2]; }



extern "C" void tzset() throw();



extern "C" { extern int daylight; }
extern "C" { extern long timezone; }
# 297 "/usr/include/time.h" 3
extern "C" int stime(const time_t *) throw();
# 312 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *) throw();


extern "C" time_t timelocal(tm *) throw();


extern "C" int dysize(int) throw() __attribute__((__const__));
# 327 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *);




extern "C" int clock_getres(clockid_t, timespec *) throw();


extern "C" int clock_gettime(clockid_t, timespec *) throw();


extern "C" int clock_settime(clockid_t, const timespec *) throw();
# 346 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *);




extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw();




extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw();




extern "C" int timer_delete(timer_t) throw();


extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw();




extern "C" int timer_gettime(timer_t, itimerspec *) throw();



extern "C" int timer_getoverrun(timer_t) throw();
# 389 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 398 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 412 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__);
# 38 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw();




extern "C" void *memmove(void *, const void *, size_t) throw();
# 51 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 59 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));



extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 73 "/usr/include/string.h" 3
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__));



extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 84 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw();




extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__));


extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__));



extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__));


extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw();
# 121 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));


extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw();
# 130 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__));
# 138 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__));
# 167 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int) throw() __attribute__((__pure__));


extern "C" char *strrchr(const char *, int) throw() __attribute__((__pure__));
# 177 "/usr/include/string.h" 3
extern "C" char *strchrnul(const char *, int) throw() __attribute__((__pure__));
# 184 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__));



extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__));


extern "C" char *strpbrk(const char *, const char *) throw() __attribute__((__pure__));


extern "C" char *strstr(const char *, const char *) throw() __attribute__((__pure__));




extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw();
# 205 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();




extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();
# 217 "/usr/include/string.h" 3
extern "C" char *strcasestr(const char *, const char *) throw() __attribute__((__pure__));
# 225 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__));
# 231 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();


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



extern "C" void bcopy(const void *, void *, size_t) throw();



extern "C" void bzero(void *, size_t) throw();


extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));



extern "C" char *index(const char *, int) throw() __attribute__((__pure__));



extern "C" char *rindex(const char *, int) throw() __attribute__((__pure__));




extern "C" int ffs(int) throw() __attribute__((__const__));




extern "C" int ffsl(long) throw() __attribute__((__const__));

extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 331 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__));
# 342 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));



extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__));
# 354 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw();
# 361 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" char *strsignal(int) throw();


extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw();

extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw();




extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();


extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();




extern "C" char *strfry(char *) throw();


extern "C" void *memfrob(void *, size_t) throw();
# 393 "/usr/include/string.h" 3
extern "C" char *basename(const char *) throw();
# 56 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw();
# 65 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int min(int, int);

extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);

extern "C" __attribute__((__weak__)) long long llmin(long long, long long);

extern "C" __attribute__((__weak__)) unsigned long long ullmin(unsigned long long, unsigned long long);

extern "C" __attribute__((__weak__)) float fminf(float, float) throw();

extern "C" __attribute__((__weak__)) double fmin(double, double) throw();


extern "C" __attribute__((__weak__)) int max(int, int);

extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);

extern "C" __attribute__((__weak__)) long long llmax(long long, long long);

extern "C" __attribute__((__weak__)) unsigned long long ullmax(unsigned long long, unsigned long long);

extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();

extern "C" __attribute__((__weak__)) double fmax(double, double) throw();


extern "C" __attribute__((__weak__)) double sin(double) throw();

extern "C" __attribute__((__weak__)) float sinf(float) throw();


extern "C" __attribute__((__weak__)) double cos(double) throw();

extern "C" __attribute__((__weak__)) float cosf(float) throw();


extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();

extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();


extern "C" __attribute__((__weak__)) double tan(double) throw();

extern "C" __attribute__((__weak__)) float tanf(float) throw();


extern "C" __attribute__((__weak__)) double sqrt(double) throw();

extern "C" __attribute__((__weak__)) float sqrtf(float) throw();


extern "C" __attribute__((__weak__)) double rsqrt(double);

extern "C" __attribute__((__weak__)) float rsqrtf(float);


extern "C" __attribute__((__weak__)) double exp2(double) throw();

extern "C" __attribute__((__weak__)) float exp2f(float) throw();


extern "C" __attribute__((__weak__)) double exp10(double) throw();

extern "C" __attribute__((__weak__)) float exp10f(float) throw();


extern "C" __attribute__((__weak__)) double expm1(double) throw();

extern "C" __attribute__((__weak__)) float expm1f(float) throw();


extern "C" __attribute__((__weak__)) double log2(double) throw();

extern "C" __attribute__((__weak__)) float log2f(float) throw();


extern "C" __attribute__((__weak__)) double log10(double) throw();

extern "C" __attribute__((__weak__)) float log10f(float) throw();


extern "C" __attribute__((__weak__)) double log(double) throw();

extern "C" __attribute__((__weak__)) float logf(float) throw();


extern "C" __attribute__((__weak__)) double log1p(double) throw();

extern "C" __attribute__((__weak__)) float log1pf(float) throw();


extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double exp(double) throw();

extern "C" __attribute__((__weak__)) float expf(float) throw();


extern "C" __attribute__((__weak__)) double cosh(double) throw();

extern "C" __attribute__((__weak__)) float coshf(float) throw();


extern "C" __attribute__((__weak__)) double sinh(double) throw();

extern "C" __attribute__((__weak__)) float sinhf(float) throw();


extern "C" __attribute__((__weak__)) double tanh(double) throw();

extern "C" __attribute__((__weak__)) float tanhf(float) throw();


extern "C" __attribute__((__weak__)) double acosh(double) throw();

extern "C" __attribute__((__weak__)) float acoshf(float) throw();


extern "C" __attribute__((__weak__)) double asinh(double) throw();

extern "C" __attribute__((__weak__)) float asinhf(float) throw();


extern "C" __attribute__((__weak__)) double atanh(double) throw();

extern "C" __attribute__((__weak__)) float atanhf(float) throw();


extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();

extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();


extern "C" __attribute__((__weak__)) double logb(double) throw();

extern "C" __attribute__((__weak__)) float logbf(float) throw();


extern "C" __attribute__((__weak__)) int ilogb(double) throw();

extern "C" __attribute__((__weak__)) int ilogbf(float) throw();


extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();

extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();


extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();

extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();


extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();

extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();


extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) long lround(double) throw();

extern "C" __attribute__((__weak__)) long lroundf(float) throw();


extern "C" __attribute__((__weak__)) long long llround(double) throw();

extern "C" __attribute__((__weak__)) long long llroundf(float) throw();


extern "C" __attribute__((__weak__)) double rint(double) throw();

extern "C" __attribute__((__weak__)) float rintf(float) throw();


extern "C" __attribute__((__weak__)) long lrint(double) throw();

extern "C" __attribute__((__weak__)) long lrintf(float) throw();


extern "C" __attribute__((__weak__)) long long llrint(double) throw();

extern "C" __attribute__((__weak__)) long long llrintf(float) throw();


extern "C" __attribute__((__weak__)) double nearbyint(double) throw();

extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();


extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fdim(double, double) throw();

extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();


extern "C" __attribute__((__weak__)) double atan2(double, double) throw();

extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();


extern "C" __attribute__((__weak__)) double atan(double) throw();

extern "C" __attribute__((__weak__)) float atanf(float) throw();


extern "C" __attribute__((__weak__)) double asin(double) throw();

extern "C" __attribute__((__weak__)) float asinf(float) throw();


extern "C" __attribute__((__weak__)) double acos(double) throw();

extern "C" __attribute__((__weak__)) float acosf(float) throw();


extern "C" __attribute__((__weak__)) double hypot(double, double) throw();

extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();


extern "C" __attribute__((__weak__)) double cbrt(double) throw();

extern "C" __attribute__((__weak__)) float cbrtf(float) throw();


extern "C" __attribute__((__weak__)) double pow(double, double) throw();

extern "C" __attribute__((__weak__)) float powf(float, float) throw();


extern "C" __attribute__((__weak__)) double modf(double, double *) throw();

extern "C" __attribute__((__weak__)) float modff(float, float *) throw();


extern "C" __attribute__((__weak__)) double fmod(double, double) throw();

extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();


extern "C" __attribute__((__weak__)) double remainder(double, double) throw();

extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();


extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();

extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();


extern "C" __attribute__((__weak__)) double erf(double) throw();

extern "C" __attribute__((__weak__)) float erff(float) throw();


extern "C" __attribute__((__weak__)) double erfinv(double) throw();

extern "C" __attribute__((__weak__)) float erfinvf(float) throw();


extern "C" __attribute__((__weak__)) double erfc(double) throw();

extern "C" __attribute__((__weak__)) float erfcf(float) throw();


extern "C" __attribute__((__weak__)) double erfcinv(double) throw();

extern "C" __attribute__((__weak__)) float erfcinvf(float) throw();


extern "C" __attribute__((__weak__)) double lgamma(double) throw();

extern "C" __attribute__((__weak__)) float lgammaf(float) throw();


extern "C" __attribute__((__weak__)) double tgamma(double) throw();

extern "C" __attribute__((__weak__)) float tgammaf(float) throw();


extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 408 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();

extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw();
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acos(double) throw(); extern "C" double __acos(double) throw();

extern "C" __attribute__((__weak__)) double asin(double) throw(); extern "C" double __asin(double) throw();

extern "C" __attribute__((__weak__)) double atan(double) throw(); extern "C" double __atan(double) throw();

extern "C" __attribute__((__weak__)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw();


extern "C" __attribute__((__weak__)) double cos(double) throw(); extern "C" double __cos(double) throw();

extern "C" __attribute__((__weak__)) double sin(double) throw(); extern "C" double __sin(double) throw();

extern "C" __attribute__((__weak__)) double tan(double) throw(); extern "C" double __tan(double) throw();




extern "C" __attribute__((__weak__)) double cosh(double) throw(); extern "C" double __cosh(double) throw();

extern "C" __attribute__((__weak__)) double sinh(double) throw(); extern "C" double __sinh(double) throw();

extern "C" __attribute__((__weak__)) double tanh(double) throw(); extern "C" double __tanh(double) throw();




extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acosh(double) throw(); extern "C" double __acosh(double) throw();

extern "C" __attribute__((__weak__)) double asinh(double) throw(); extern "C" double __asinh(double) throw();

extern "C" __attribute__((__weak__)) double atanh(double) throw(); extern "C" double __atanh(double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp(double) throw(); extern "C" double __exp(double) throw();


extern "C" __attribute__((__weak__)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw();


extern "C" __attribute__((__weak__)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw();


extern "C" __attribute__((__weak__)) double log(double) throw(); extern "C" double __log(double) throw();


extern "C" __attribute__((__weak__)) double log10(double) throw(); extern "C" double __log10(double) throw();


extern "C" __attribute__((__weak__)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw();




extern "C" __attribute__((__weak__)) double exp10(double) throw(); extern "C" double __exp10(double) throw();

extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double expm1(double) throw(); extern "C" double __expm1(double) throw();


extern "C" __attribute__((__weak__)) double log1p(double) throw(); extern "C" double __log1p(double) throw();


extern "C" __attribute__((__weak__)) double logb(double) throw(); extern "C" double __logb(double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp2(double) throw(); extern "C" double __exp2(double) throw();


extern "C" __attribute__((__weak__)) double log2(double) throw(); extern "C" double __log2(double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw();


extern "C" __attribute__((__weak__)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw();




extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double) throw() __attribute__((__const__));


extern "C" int finite(double) throw() __attribute__((__const__));


extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw();



extern "C" double significand(double) throw(); extern "C" double __significand(double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));



extern "C" int isnan(double) throw() __attribute__((__const__));


extern "C" double j0(double) throw(); extern "C" double __j0(double) throw();
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw();
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw();
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw();
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw();
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double erf(double) throw(); extern "C" double __erf(double) throw();
extern "C" __attribute__((__weak__)) double erfc(double) throw(); extern "C" double __erfc(double) throw();
extern "C" __attribute__((__weak__)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double rint(double) throw(); extern "C" double __rint(double) throw();


extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__));

extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw();



extern "C" __attribute__((__weak__)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw();



extern "C" __attribute__((__weak__)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw();




extern "C" __attribute__((__weak__)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw();



extern "C" __attribute__((__weak__)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw();



extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrint(double) throw(); extern "C" long __lrint(double) throw();
extern "C" __attribute__((__weak__)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw();



extern "C" __attribute__((__weak__)) long lround(double) throw(); extern "C" long __lround(double) throw();
extern "C" __attribute__((__weak__)) long long llround(double) throw(); extern "C" long long __llround(double) throw();



extern "C" __attribute__((__weak__)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw();


extern "C" __attribute__((__weak__)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw();


extern "C" __attribute__((__weak__)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw();



extern "C" int __fpclassify(double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acosf(float) throw(); extern "C" float __acosf(float) throw();

extern "C" __attribute__((__weak__)) float asinf(float) throw(); extern "C" float __asinf(float) throw();

extern "C" __attribute__((__weak__)) float atanf(float) throw(); extern "C" float __atanf(float) throw();

extern "C" __attribute__((__weak__)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw();


extern "C" __attribute__((__weak__)) float cosf(float) throw();

extern "C" __attribute__((__weak__)) float sinf(float) throw();

extern "C" __attribute__((__weak__)) float tanf(float) throw();




extern "C" __attribute__((__weak__)) float coshf(float) throw(); extern "C" float __coshf(float) throw();

extern "C" __attribute__((__weak__)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw();

extern "C" __attribute__((__weak__)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw();




extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw();

extern "C" __attribute__((__weak__)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw();

extern "C" __attribute__((__weak__)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expf(float) throw();


extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw();


extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw();


extern "C" __attribute__((__weak__)) float logf(float) throw();


extern "C" __attribute__((__weak__)) float log10f(float) throw();


extern "C" __attribute__((__weak__)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw();




extern "C" __attribute__((__weak__)) float exp10f(float) throw();

extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw();


extern "C" __attribute__((__weak__)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw();


extern "C" __attribute__((__weak__)) float logbf(float) throw(); extern "C" float __logbf(float) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw();


extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float powf(float, float) throw();


extern "C" __attribute__((__weak__)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw();




extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float) throw() __attribute__((__const__));


extern "C" int finitef(float) throw() __attribute__((__const__));


extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw();



extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));



extern "C" int isnanf(float) throw() __attribute__((__const__));


extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw();
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw();
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw();
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw();
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw();
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float erff(float) throw(); extern "C" float __erff(float) throw();
extern "C" __attribute__((__weak__)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
extern "C" __attribute__((__weak__)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float rintf(float) throw(); extern "C" float __rintf(float) throw();


extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__));

extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw();



extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw();



extern "C" __attribute__((__weak__)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw();




extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw();



extern "C" __attribute__((__weak__)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw();



extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw();
extern "C" __attribute__((__weak__)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw();



extern "C" __attribute__((__weak__)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw();
extern "C" __attribute__((__weak__)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw();



extern "C" __attribute__((__weak__)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw();


extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw();


extern "C" __attribute__((__weak__)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw();



extern "C" int __fpclassifyf(float) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalbf(float, float) throw(); extern "C" float __scalbf(float, float) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double) throw(); extern "C" long double __acosl(long double) throw();

extern "C" long double asinl(long double) throw(); extern "C" long double __asinl(long double) throw();

extern "C" long double atanl(long double) throw(); extern "C" long double __atanl(long double) throw();

extern "C" long double atan2l(long double, long double) throw(); extern "C" long double __atan2l(long double, long double) throw();


extern "C" long double cosl(long double) throw(); extern "C" long double __cosl(long double) throw();

extern "C" long double sinl(long double) throw(); extern "C" long double __sinl(long double) throw();

extern "C" long double tanl(long double) throw(); extern "C" long double __tanl(long double) throw();




extern "C" long double coshl(long double) throw(); extern "C" long double __coshl(long double) throw();

extern "C" long double sinhl(long double) throw(); extern "C" long double __sinhl(long double) throw();

extern "C" long double tanhl(long double) throw(); extern "C" long double __tanhl(long double) throw();




extern "C" void sincosl(long double, long double *, long double *) throw(); extern "C" void __sincosl(long double, long double *, long double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acoshl(long double) throw(); extern "C" long double __acoshl(long double) throw();

extern "C" long double asinhl(long double) throw(); extern "C" long double __asinhl(long double) throw();

extern "C" long double atanhl(long double) throw(); extern "C" long double __atanhl(long double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expl(long double) throw(); extern "C" long double __expl(long double) throw();


extern "C" long double frexpl(long double, int *) throw(); extern "C" long double __frexpl(long double, int *) throw();


extern "C" long double ldexpl(long double, int) throw(); extern "C" long double __ldexpl(long double, int) throw();


extern "C" long double logl(long double) throw(); extern "C" long double __logl(long double) throw();


extern "C" long double log10l(long double) throw(); extern "C" long double __log10l(long double) throw();


extern "C" long double modfl(long double, long double *) throw(); extern "C" long double __modfl(long double, long double *) throw();




extern "C" long double exp10l(long double) throw(); extern "C" long double __exp10l(long double) throw();

extern "C" long double pow10l(long double) throw(); extern "C" long double __pow10l(long double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expm1l(long double) throw(); extern "C" long double __expm1l(long double) throw();


extern "C" long double log1pl(long double) throw(); extern "C" long double __log1pl(long double) throw();


extern "C" long double logbl(long double) throw(); extern "C" long double __logbl(long double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp2l(long double) throw(); extern "C" long double __exp2l(long double) throw();


extern "C" long double log2l(long double) throw(); extern "C" long double __log2l(long double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" long double powl(long double, long double) throw(); extern "C" long double __powl(long double, long double) throw();


extern "C" long double sqrtl(long double) throw(); extern "C" long double __sqrtl(long double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" long double hypotl(long double, long double) throw(); extern "C" long double __hypotl(long double, long double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cbrtl(long double) throw(); extern "C" long double __cbrtl(long double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ceill(long double) throw() __attribute__((__const__)); extern "C" long double __ceill(long double) throw() __attribute__((__const__));


extern "C" long double fabsl(long double) throw() __attribute__((__const__)); extern "C" long double __fabsl(long double) throw() __attribute__((__const__));


extern "C" long double floorl(long double) throw() __attribute__((__const__)); extern "C" long double __floorl(long double) throw() __attribute__((__const__));


extern "C" long double fmodl(long double, long double) throw(); extern "C" long double __fmodl(long double, long double) throw();




extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinfl(long double) throw() __attribute__((__const__));


extern "C" int finitel(long double) throw() __attribute__((__const__));


extern "C" long double dreml(long double, long double) throw(); extern "C" long double __dreml(long double, long double) throw();



extern "C" long double significandl(long double) throw(); extern "C" long double __significandl(long double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" long double copysignl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __copysignl(long double, long double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nanl(const char *) throw() __attribute__((__const__)); extern "C" long double __nanl(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));



extern "C" int isnanl(long double) throw() __attribute__((__const__));


extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw();
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw();
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw();
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw();
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw();
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw();
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw();
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" long double lgammal_r(long double, int *) throw(); extern "C" long double __lgammal_r(long double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" long double rintl(long double) throw(); extern "C" long double __rintl(long double) throw();


extern "C" long double nextafterl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nextafterl(long double, long double) throw() __attribute__((__const__));

extern "C" long double nexttowardl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nexttowardl(long double, long double) throw() __attribute__((__const__));



extern "C" long double remainderl(long double, long double) throw(); extern "C" long double __remainderl(long double, long double) throw();



extern "C" long double scalbnl(long double, int) throw(); extern "C" long double __scalbnl(long double, int) throw();



extern "C" int ilogbl(long double) throw(); extern "C" int __ilogbl(long double) throw();




extern "C" long double scalblnl(long double, long) throw(); extern "C" long double __scalblnl(long double, long) throw();



extern "C" long double nearbyintl(long double) throw(); extern "C" long double __nearbyintl(long double) throw();



extern "C" long double roundl(long double) throw() __attribute__((__const__)); extern "C" long double __roundl(long double) throw() __attribute__((__const__));



extern "C" long double truncl(long double) throw() __attribute__((__const__)); extern "C" long double __truncl(long double) throw() __attribute__((__const__));




extern "C" long double remquol(long double, long double, int *) throw(); extern "C" long double __remquol(long double, long double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrintl(long double) throw(); extern "C" long __lrintl(long double) throw();
extern "C" long long llrintl(long double) throw(); extern "C" long long __llrintl(long double) throw();



extern "C" long lroundl(long double) throw(); extern "C" long __lroundl(long double) throw();
extern "C" long long llroundl(long double) throw(); extern "C" long long __llroundl(long double) throw();



extern "C" long double fdiml(long double, long double) throw(); extern "C" long double __fdiml(long double, long double) throw();


extern "C" long double fmaxl(long double, long double) throw(); extern "C" long double __fmaxl(long double, long double) throw();


extern "C" long double fminl(long double, long double) throw(); extern "C" long double __fminl(long double, long double) throw();



extern "C" int __fpclassifyl(long double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__));




extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw();
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 199 "/usr/include/math.h" 3
enum __cuda_FP_NAN {
FP_NAN,

FP_INFINITE,

FP_ZERO,

FP_SUBNORMAL,

FP_NORMAL

};
# 291 "/usr/include/math.h" 3
extern "C" { typedef
# 285 "/usr/include/math.h" 3
enum {
_IEEE_ = (-1),
_SVID_,
_XOPEN_,
_POSIX_,
_ISOC_
} _LIB_VERSION_TYPE; }




extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; }
# 307 "/usr/include/math.h" 3
extern "C" { struct __exception {




int type;
char *name;
double arg1;
double arg2;
double retval;
}; }


extern "C" int matherr(__exception *) throw();
# 67 "/usr/include/bits/waitstatus.h" 3
extern "C" { union wait {

int w_status;

struct {

unsigned __w_termsig:7;
unsigned __w_coredump:1;
unsigned __w_retcode:8;
unsigned:16;
# 84 "/usr/include/bits/waitstatus.h" 3
} __wait_terminated;

struct {

unsigned __w_stopval:8;
unsigned __w_stopsig:8;
unsigned:16;
# 97 "/usr/include/bits/waitstatus.h" 3
} __wait_stopped;
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 99 "/usr/include/stdlib.h" 3
struct div_t {
int quot;
int rem;
} div_t; }
# 110 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 107 "/usr/include/stdlib.h" 3
struct ldiv_t {
long quot;
long rem;
} ldiv_t; }
# 122 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 119 "/usr/include/stdlib.h" 3
struct lldiv_t {
long long quot;
long long rem;
} lldiv_t; }
# 140 "/usr/include/stdlib.h" 3
extern "C" size_t __ctype_get_mb_cur_max() throw();




extern "C" double atof(const char *) throw() __attribute__((__pure__));


extern "C" int atoi(const char *) throw() __attribute__((__pure__));


extern "C" long atol(const char *) throw() __attribute__((__pure__));
# 158 "/usr/include/stdlib.h" 3
extern "C" long long atoll(const char *) throw() __attribute__((__pure__));
# 165 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw();
# 173 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw();


extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw();
# 184 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw();



extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw();
# 196 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw();




extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw();
# 210 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw();




extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw();
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();



extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 250 "/usr/include/stdlib.h" 3
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 256 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();




extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw();



extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw();



extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw();
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long) throw();


extern "C" long a64l(const char *) throw() __attribute__((__pure__));
# 35 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
extern "C" { typedef __u_short u_short; }
extern "C" { typedef __u_int u_int; }
extern "C" { typedef __u_long u_long; }
extern "C" { typedef __quad_t quad_t; }
extern "C" { typedef __u_quad_t u_quad_t; }
extern "C" { typedef __fsid_t fsid_t; }




extern "C" { typedef __loff_t loff_t; }



extern "C" { typedef __ino_t ino_t; }
# 57 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino64_t ino64_t; }




extern "C" { typedef __dev_t dev_t; }




extern "C" { typedef __gid_t gid_t; }




extern "C" { typedef __mode_t mode_t; }




extern "C" { typedef __nlink_t nlink_t; }




extern "C" { typedef __uid_t uid_t; }
# 88 "/usr/include/sys/types.h" 3
extern "C" { typedef __off_t off_t; }
# 95 "/usr/include/sys/types.h" 3
extern "C" { typedef __off64_t off64_t; }
# 105 "/usr/include/sys/types.h" 3
extern "C" { typedef __id_t id_t; }




extern "C" { typedef __ssize_t ssize_t; }
# 116 "/usr/include/sys/types.h" 3
extern "C" { typedef __daddr_t daddr_t; }
extern "C" { typedef __caddr_t caddr_t; }
# 123 "/usr/include/sys/types.h" 3
extern "C" { typedef __key_t key_t; }
# 137 "/usr/include/sys/types.h" 3
extern "C" { typedef __useconds_t useconds_t; }



extern "C" { typedef __suseconds_t suseconds_t; }
# 151 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long ulong; }
extern "C" { typedef unsigned short ushort; }
extern "C" { typedef unsigned uint; }
# 195 "/usr/include/sys/types.h" 3
extern "C" { typedef signed char int8_t; }
extern "C" { typedef short int16_t; }
extern "C" { typedef int int32_t; }
extern "C" { typedef long int64_t; }


extern "C" { typedef unsigned char u_int8_t; }
extern "C" { typedef unsigned short u_int16_t; }
extern "C" { typedef unsigned u_int32_t; }
extern "C" { typedef unsigned long u_int64_t; }

extern "C" { typedef int register_t; }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32 "/usr/include/bits/sigset.h" 3
extern "C" { typedef
# 30 "/usr/include/bits/sigset.h" 3
struct __sigset_t {
unsigned long __val[((1024) / ((8) * sizeof(unsigned long)))];
} __sigset_t; }
# 38 "/usr/include/sys/select.h" 3
extern "C" { typedef __sigset_t sigset_t; }
# 69 "/usr/include/bits/time.h" 3
extern "C" { struct timeval {

__time_t tv_sec;
__suseconds_t tv_usec;
}; }
# 55 "/usr/include/sys/select.h" 3
extern "C" { typedef long __fd_mask; }
# 78 "/usr/include/sys/select.h" 3
extern "C" { typedef
# 68 "/usr/include/sys/select.h" 3
struct fd_set {



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


extern "C" unsigned gnu_dev_minor(unsigned long long) throw();


extern "C" unsigned long long gnu_dev_makedev(unsigned, unsigned) throw();
# 228 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 235 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt_t blkcnt_t; }



extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }



extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 262 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 54 "/usr/include/bits/pthreadtypes.h" 3
union pthread_attr_t {
char __size[56];
long __align;
} pthread_attr_t; }
# 65 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 61 "/usr/include/bits/pthreadtypes.h" 3
struct __pthread_internal_list {

__pthread_internal_list *__prev;
__pthread_internal_list *__next;
} __pthread_list_t; }
# 104 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 77 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutex_t {
struct __pthread_mutex_s {

int __lock;
unsigned __count;
int __owner;

unsigned __nusers;



int __kind;

int __spins;
__pthread_list_t __list;
# 101 "/usr/include/bits/pthreadtypes.h" 3
} __data;
char __size[40];
long __align;
} pthread_mutex_t; }
# 110 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 107 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutexattr_t {
char __size[4];
int __align;
} pthread_mutexattr_t; }
# 130 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 116 "/usr/include/bits/pthreadtypes.h" 3
union pthread_cond_t {

struct {
int __lock;
unsigned __futex;
unsigned long long __total_seq;
unsigned long long __wakeup_seq;
unsigned long long __woken_seq;
void *__mutex;
unsigned __nwaiters;
unsigned __broadcast_seq;
} __data;
char __size[48];
long long __align;
} pthread_cond_t; }
# 136 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 133 "/usr/include/bits/pthreadtypes.h" 3
union pthread_condattr_t {
char __size[4];
int __align;
} pthread_condattr_t; }



extern "C" { typedef unsigned pthread_key_t; }



extern "C" { typedef int pthread_once_t; }
# 189 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 151 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlock_t {


struct {
int __lock;
unsigned __nr_readers;
unsigned __readers_wakeup;
unsigned __writer_wakeup;
unsigned __nr_readers_queued;
unsigned __nr_writers_queued;
int __writer;
int __shared;
unsigned long __pad1;
unsigned long __pad2;


unsigned __flags;
} __data;
# 187 "/usr/include/bits/pthreadtypes.h" 3
char __size[56];
long __align;
} pthread_rwlock_t; }
# 195 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 192 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlockattr_t {
char __size[8];
long __align;
} pthread_rwlockattr_t; }
# 201 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 207 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrier_t {
char __size[32];
long __align;
} pthread_barrier_t; }
# 216 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 213 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrierattr_t {
char __size[4];
int __align;
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw();


extern "C" void srandom(unsigned) throw();
# 336 "/usr/include/stdlib.h" 3
extern "C" char *initstate(unsigned, char *, size_t) throw();




extern "C" char *setstate(char *) throw();
# 349 "/usr/include/stdlib.h" 3
extern "C" { struct random_data {

int32_t *fptr;
int32_t *rptr;
int32_t *state;
int rand_type;
int rand_deg;
int rand_sep;
int32_t *end_ptr;
}; }

extern "C" int random_r(random_data *__restrict__, int32_t *__restrict__) throw();


extern "C" int srandom_r(unsigned, random_data *) throw();


extern "C" int initstate_r(unsigned, char *__restrict__, size_t, random_data *__restrict__) throw();




extern "C" int setstate_r(char *__restrict__, random_data *__restrict__) throw();
# 380 "/usr/include/stdlib.h" 3
extern "C" int rand() throw();

extern "C" void srand(unsigned) throw();




extern "C" int rand_r(unsigned *) throw();
# 395 "/usr/include/stdlib.h" 3
extern "C" double drand48() throw();
extern "C" double erand48(unsigned short [3]) throw();


extern "C" long lrand48() throw();
extern "C" long nrand48(unsigned short [3]) throw();



extern "C" long mrand48() throw();
extern "C" long jrand48(unsigned short [3]) throw();



extern "C" void srand48(long) throw();
extern "C" unsigned short *seed48(unsigned short [3]) throw();

extern "C" void lcong48(unsigned short [7]) throw();
# 418 "/usr/include/stdlib.h" 3
extern "C" { struct drand48_data {

unsigned short __x[3];
unsigned short __old_x[3];
unsigned short __c;
unsigned short __init;
unsigned long long __a;
}; }


extern "C" int drand48_r(drand48_data *__restrict__, double *__restrict__) throw();

extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__, double *__restrict__) throw();




extern "C" int lrand48_r(drand48_data *__restrict__, long *__restrict__) throw();


extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 444 "/usr/include/stdlib.h" 3
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw();


extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 453 "/usr/include/stdlib.h" 3
extern "C" int srand48_r(long, drand48_data *) throw();


extern "C" int seed48_r(unsigned short [3], drand48_data *) throw();


extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw();
# 471 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__));

extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__));
# 485 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void *, size_t) throw();


extern "C" void free(void *) throw();




extern "C" void cfree(void *) throw();
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw();
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__));




extern "C" int posix_memalign(void **, size_t, size_t) throw();
# 513 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute__((__noreturn__));



extern "C" int atexit(void (*)(void)) throw();
# 523 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw();
# 531 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 538 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 545 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw();




extern "C" char *__secure_getenv(const char *) throw();
# 557 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw();
# 563 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw();



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


extern "C" { typedef __compar_fn_t comparison_fn_t; }



extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 683 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);
# 689 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t);


extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *);
# 699 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 713 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));

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


extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw();


extern "C" char *qgcvt(long double, int, char *) throw();
# 765 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();


extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 787 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();


extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int wctomb(char *, wchar_t) throw();



extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();


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



extern "C" int unlockpt(int) throw();




extern "C" char *ptsname(int) throw();
# 864 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw();



extern "C" int getpt();
# 875 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 74 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {

template<class _Iterator, class _Container> class __normal_iterator;


}

namespace std __attribute__((visibility("default"))) {

struct __true_type { };
struct __false_type { };

template<bool __T0>
struct __truth_type {
typedef __false_type __type; };


template<> struct __truth_type< true> {
typedef __true_type __type; };



template<class _Sp, class _Tp>
struct __traitor {

enum __cuda___value { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
typedef typename __truth_type< (((bool)_Sp::__value) || ((bool)_Tp::__value))> ::__type __type;
};



template<class _Sp, class _Tp>
struct __traitand {

enum __cuda___value { __value = (((bool)_Sp::__value) && ((bool)_Tp::__value))};
typedef typename __truth_type< (((bool)_Sp::__value) && ((bool)_Tp::__value))> ::__type __type;
};


template<class , class >
struct __are_same {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Tp>
struct __are_same< _Tp, _Tp> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<class _Tp>
struct __is_void {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_void< void> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_integer {

enum __cuda___value { __value};
typedef __false_type __type;
};
# 156 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< signed char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_integer< wchar_t> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_integer< short> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned short> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< int> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< long long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned long long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_floating {

enum __cuda___value { __value};
typedef __false_type __type;
};



template<> struct __is_floating< float> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_floating< double> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_floating< long double> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_pointer {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Tp>
struct __is_pointer< _Tp *> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_normal_iterator {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Iterator, class _Container>
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {


enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {

};




template<class _Tp>
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {

};




template<class _Tp>
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {

};




template<class _Tp>
struct __is_char {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_char< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_char< wchar_t> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<class _Tp>
struct __is_byte {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_byte< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_byte< signed char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_byte< unsigned char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_move_iterator {

enum __cuda___value { __value};
typedef __false_type __type;
};
# 415 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
}
# 43 "/usr/include/c++/4.3/ext/type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {


template<bool __T1, class >
struct __enable_if {
};

template<class _Tp>
struct __enable_if< true, _Tp> {
typedef _Tp __type; };



template<bool _Cond, class _Iftrue, class _Iffalse>
struct __conditional_type {
typedef _Iftrue __type; };

template<class _Iftrue, class _Iffalse>
struct __conditional_type< false, _Iftrue, _Iffalse> {
typedef _Iffalse __type; };



template<class _Tp>
struct __add_unsigned {


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
};


template<> struct __add_unsigned< char> {
typedef unsigned char __type; };


template<> struct __add_unsigned< signed char> {
typedef unsigned char __type; };


template<> struct __add_unsigned< short> {
typedef unsigned short __type; };


template<> struct __add_unsigned< int> {
typedef unsigned __type; };


template<> struct __add_unsigned< long> {
typedef unsigned long __type; };


template<> struct __add_unsigned< long long> {
typedef unsigned long long __type; };



template<> struct __add_unsigned< bool> ;


template<> struct __add_unsigned< wchar_t> ;



template<class _Tp>
struct __remove_unsigned {


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
};


template<> struct __remove_unsigned< char> {
typedef signed char __type; };


template<> struct __remove_unsigned< unsigned char> {
typedef signed char __type; };


template<> struct __remove_unsigned< unsigned short> {
typedef short __type; };


template<> struct __remove_unsigned< unsigned> {
typedef int __type; };


template<> struct __remove_unsigned< unsigned long> {
typedef long __type; };


template<> struct __remove_unsigned< unsigned long long> {
typedef long long __type; };



template<> struct __remove_unsigned< bool> ;


template<> struct __remove_unsigned< wchar_t> ;



template < typename _Type >
    inline bool
    __is_null_pointer ( _Type * __ptr )
    { return __ptr == 0; }

template < typename _Type >
    inline bool
    __is_null_pointer ( _Type )
    { return false; }



template<class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
struct __promote {
typedef double __type; };

template<class _Tp>
struct __promote< _Tp, false> {
typedef _Tp __type; };

template<class _Tp, class _Up>
struct __promote_2 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;


public: typedef __typeof__((__type1() + __type2())) __type;
};

template<class _Tp, class _Up, class _Vp>
struct __promote_3 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;


public: typedef __typeof__(((__type1() + __type2()) + __type3())) __type;
};

template<class _Tp, class _Up, class _Vp, class _Wp>
struct __promote_4 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
typedef typename __promote< _Wp, std::__is_integer< _Wp> ::__value> ::__type __type4;


public: typedef __typeof__((((__type1() + __type2()) + __type3()) + __type4())) __type;
};

}
# 82 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {



template < typename _Tp >
    _Tp __cmath_power ( _Tp, unsigned int );

template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }


inline double abs(double __x)
{ return __builtin_fabs(__x); }


inline float abs(float __x)
{ return __builtin_fabsf(__x); }


inline long double abs(long double __x)
{ return __builtin_fabsl(__x); }

using ::acos;


inline float acos(float __x)
{ return __builtin_acosf(__x); }


inline long double acos(long double __x)
{ return __builtin_acosl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }

using ::asin;


inline float asin(float __x)
{ return __builtin_asinf(__x); }


inline long double asin(long double __x)
{ return __builtin_asinl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }

using ::atan;


inline float atan(float __x)
{ return __builtin_atanf(__x); }


inline long double atan(long double __x)
{ return __builtin_atanl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }

using ::atan2;


inline float atan2(float __y, float __x)
{ return __builtin_atan2f(__y, __x); }


inline long double atan2(long double __y, long double __x)
{ return __builtin_atan2l(__y, __x); }

template < typename _Tp, typename _Up >
    inline
    typename __gnu_cxx :: __promote_2 <
    typename __gnu_cxx :: __enable_if < __traitand < __is_arithmetic < _Tp >,
            __is_arithmetic < _Up > > :: __value,
        _Tp > :: __type, _Up > :: __type
    atan2 ( _Tp __y, _Up __x )
    {
      typedef typename __gnu_cxx :: __promote_2 < _Tp, _Up > :: __type __type;
      return atan2 ( __type ( __y ), __type ( __x ) );
    }

using ::ceil;


inline float ceil(float __x)
{ return __builtin_ceilf(__x); }


inline long double ceil(long double __x)
{ return __builtin_ceill(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }

using ::cos;


inline float cos(float __x)
{ return __builtin_cosf(__x); }


inline long double cos(long double __x)
{ return __builtin_cosl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }

using ::cosh;


inline float cosh(float __x)
{ return __builtin_coshf(__x); }


inline long double cosh(long double __x)
{ return __builtin_coshl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }

using ::exp;


inline float exp(float __x)
{ return __builtin_expf(__x); }


inline long double exp(long double __x)
{ return __builtin_expl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }

using ::fabs;


inline float fabs(float __x)
{ return __builtin_fabsf(__x); }


inline long double fabs(long double __x)
{ return __builtin_fabsl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }

using ::floor;


inline float floor(float __x)
{ return __builtin_floorf(__x); }


inline long double floor(long double __x)
{ return __builtin_floorl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }

using ::fmod;


inline float fmod(float __x, float __y)
{ return __builtin_fmodf(__x, __y); }


inline long double fmod(long double __x, long double __y)
{ return __builtin_fmodl(__x, __y); }

using ::frexp;


inline float frexp(float __x, int *__exp)
{ return __builtin_frexpf(__x, __exp); }


inline long double frexp(long double __x, int *__exp)
{ return __builtin_frexpl(__x, __exp); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }

using ::ldexp;


inline float ldexp(float __x, int __exp)
{ return __builtin_ldexpf(__x, __exp); }


inline long double ldexp(long double __x, int __exp)
{ return __builtin_ldexpl(__x, __exp); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }

using ::log;


inline float log(float __x)
{ return __builtin_logf(__x); }


inline long double log(long double __x)
{ return __builtin_logl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }

using ::log10;


inline float log10(float __x)
{ return __builtin_log10f(__x); }


inline long double log10(long double __x)
{ return __builtin_log10l(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }

using ::modf;


inline float modf(float __x, float *__iptr)
{ return __builtin_modff(__x, __iptr); }


inline long double modf(long double __x, long double *__iptr)
{ return __builtin_modfl(__x, __iptr); }

using ::pow;


inline float pow(float __x, float __y)
{ return __builtin_powf(__x, __y); }


inline long double pow(long double __x, long double __y)
{ return __builtin_powl(__x, __y); }



inline double pow(double __x, int __i)
{ return __builtin_powi(__x, __i); }


inline float pow(float __x, int __n)
{ return __builtin_powif(__x, __n); }


inline long double pow(long double __x, int __n)
{ return __builtin_powil(__x, __n); }

template < typename _Tp, typename _Up >
    inline
    typename __gnu_cxx :: __promote_2 <
    typename __gnu_cxx :: __enable_if < __traitand < __is_arithmetic < _Tp >,
            __is_arithmetic < _Up > > :: __value,
        _Tp > :: __type, _Up > :: __type
    pow ( _Tp __x, _Up __y )
    {
      typedef typename __gnu_cxx :: __promote_2 < _Tp, _Up > :: __type __type;
      return pow ( __type ( __x ), __type ( __y ) );
    }

using ::sin;


inline float sin(float __x)
{ return __builtin_sinf(__x); }


inline long double sin(long double __x)
{ return __builtin_sinl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }

using ::sinh;


inline float sinh(float __x)
{ return __builtin_sinhf(__x); }


inline long double sinh(long double __x)
{ return __builtin_sinhl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }

using ::sqrt;


inline float sqrt(float __x)
{ return __builtin_sqrtf(__x); }


inline long double sqrt(long double __x)
{ return __builtin_sqrtl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }

using ::tan;


inline float tan(float __x)
{ return __builtin_tanf(__x); }


inline long double tan(long double __x)
{ return __builtin_tanl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }

using ::tanh;


inline float tanh(float __x)
{ return __builtin_tanhf(__x); }


inline long double tanh(long double __x)
{ return __builtin_tanhl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }

}
# 483 "/usr/include/c++/4.3/cmath" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {

template < typename _Tp >
    inline int
    __capture_fpclassify ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __fpclassifyf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __fpclassify ( __f ) : __fpclassifyl ( __f ) ); }

}
# 505 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    fpclassify ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return :: __gnu_cxx :: __capture_fpclassify ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isfinite ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isfinite ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isinf ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isinf ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnan ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnan ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnormal ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnormal ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    signbit ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_signbit ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreater ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreaterequal ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isless ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isless ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessequal ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessgreater ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isunordered ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isunordered ( __type ( __f1 ), __type ( __f2 ) );
    }

}
# 40 "/usr/include/c++/4.3/bits/cmath.tcc" 3
namespace std __attribute__((visibility("default"))) {

template < typename _Tp >
    inline _Tp
    __cmath_power ( _Tp __x, unsigned int __n )
    {
      _Tp __y = __n % 2 ? __x : _Tp ( 1 );

      while ( __n >>= 1 )
        {
          __x = __x * __x;
          if ( __n % 2 )
            __y = __y * __x;
        }

      return __y;
    }

}
# 54 "/usr/include/c++/4.3/cstddef" 3
namespace std __attribute__((visibility("default"))) {

using ::ptrdiff_t;
using ::size_t;

}
# 105 "/usr/include/c++/4.3/cstdlib" 3
namespace std __attribute__((visibility("default"))) {

using ::div_t;
using ::ldiv_t;

using ::abort;
using ::abs;
using ::atexit;
using ::atof;
using ::atoi;
using ::atol;
using ::bsearch;
using ::calloc;
using ::div;
using ::exit;
using ::free;
using ::getenv;
using ::labs;
using ::ldiv;
using ::malloc;

using ::mblen;
using ::mbstowcs;
using ::mbtowc;

using ::qsort;
using ::rand;
using ::realloc;
using ::srand;
using ::strtod;
using ::strtol;
using ::strtoul;
using ::system;

using ::wcstombs;
using ::wctomb;



inline long abs(long __i) { return labs(__i); }


inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }

}
# 162 "/usr/include/c++/4.3/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {


using ::lldiv_t;
# 171 "/usr/include/c++/4.3/cstdlib" 3
using ::_Exit;



inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }


using ::llabs;


inline lldiv_t div(long long __n, long long __d)
{ auto lldiv_t __q; (__q.quot) = __n / __d; (__q.rem) = __n % __d; return __q; }

using ::lldiv;
# 195 "/usr/include/c++/4.3/cstdlib" 3
using ::atoll;
using ::strtoll;
using ::strtoull;

using ::strtof;
using ::strtold;

}

namespace std __attribute__((visibility("default"))) {


using __gnu_cxx::lldiv_t;

using __gnu_cxx::_Exit;
using __gnu_cxx::abs;

using __gnu_cxx::llabs;
using __gnu_cxx::div;
using __gnu_cxx::lldiv;

using __gnu_cxx::atoll;
using __gnu_cxx::strtof;
using __gnu_cxx::strtoll;
using __gnu_cxx::strtoull;
using __gnu_cxx::strtold;

}
# 442 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 456 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 481 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {

extern inline long long abs(long long) __attribute__((visibility("default")));
}

namespace std {

template<class T> extern inline T __pow_helper(T, int);
template<class T> extern inline T __cmath_power(T, unsigned);
}

using std::abs;
using std::fabs;
using std::ceil;
using std::floor;
using std::sqrt;
using std::pow;
using std::log;
using std::log10;
using std::fmod;
using std::modf;
using std::exp;
using std::frexp;
using std::ldexp;
using std::asin;
using std::sin;
using std::sinh;
using std::acos;
using std::cos;
using std::cosh;
using std::atan;
using std::atan2;
using std::tan;
using std::tanh;
# 568 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {


extern inline long abs(long) __attribute__((visibility("default")));
extern inline float abs(float) __attribute__((visibility("default")));
extern inline double abs(double) __attribute__((visibility("default")));
extern inline float fabs(float) __attribute__((visibility("default")));
extern inline float ceil(float) __attribute__((visibility("default")));
extern inline float floor(float) __attribute__((visibility("default")));
extern inline float sqrt(float) __attribute__((visibility("default")));
extern inline float pow(float, float) __attribute__((visibility("default")));
extern inline float pow(float, int) __attribute__((visibility("default")));
extern inline double pow(double, int) __attribute__((visibility("default")));
extern inline float log(float) __attribute__((visibility("default")));
extern inline float log10(float) __attribute__((visibility("default")));
extern inline float fmod(float, float) __attribute__((visibility("default")));
extern inline float modf(float, float *) __attribute__((visibility("default")));
extern inline float exp(float) __attribute__((visibility("default")));
extern inline float frexp(float, int *) __attribute__((visibility("default")));
extern inline float ldexp(float, int) __attribute__((visibility("default")));
extern inline float asin(float) __attribute__((visibility("default")));
extern inline float sin(float) __attribute__((visibility("default")));
extern inline float sinh(float) __attribute__((visibility("default")));
extern inline float acos(float) __attribute__((visibility("default")));
extern inline float cos(float) __attribute__((visibility("default")));
extern inline float cosh(float) __attribute__((visibility("default")));
extern inline float atan(float) __attribute__((visibility("default")));
extern inline float atan2(float, float) __attribute__((visibility("default")));
extern inline float tan(float) __attribute__((visibility("default")));
extern inline float tanh(float) __attribute__((visibility("default")));


}


static inline float logb(float a)
{
return logbf(a);
}

static inline int ilogb(float a)
{
return ilogbf(a);
}

static inline float scalbn(float a, int b)
{
return scalbnf(a, b);
}

static inline float scalbln(float a, long b)
{
return scalblnf(a, b);
}

static inline float exp2(float a)
{
return exp2f(a);
}

static inline float exp10(float a)
{
return exp10f(a);
}

static inline float expm1(float a)
{
return expm1f(a);
}

static inline float log2(float a)
{
return log2f(a);
}

static inline float log1p(float a)
{
return log1pf(a);
}

static inline float rsqrt(float a)
{
return rsqrtf(a);
}

static inline float acosh(float a)
{
return acoshf(a);
}

static inline float asinh(float a)
{
return asinhf(a);
}

static inline float atanh(float a)
{
return atanhf(a);
}

static inline float hypot(float a, float b)
{
return hypotf(a, b);
}

static inline float cbrt(float a)
{
return cbrtf(a);
}

static inline void sincos(float a, float *sptr, float *cptr)
{
sincosf(a, sptr, cptr);
}

static inline float erf(float a)
{
return erff(a);
}

static inline float erfinv(float a)
{
return erfinvf(a);
}

static inline float erfc(float a)
{
return erfcf(a);
}

static inline float erfcinv(float a)
{
return erfcinvf(a);
}

static inline float lgamma(float a)
{
return lgammaf(a);
}

static inline float tgamma(float a)
{
return tgammaf(a);
}

static inline float copysign(float a, float b)
{
return copysignf(a, b);
}

static inline double copysign(double a, float b)
{
return copysign(a, (double)b);
}

static inline float copysign(float a, double b)
{
return copysignf(a, (float)b);
}

static inline float nextafter(float a, float b)
{
return nextafterf(a, b);
}

static inline float remainder(float a, float b)
{
return remainderf(a, b);
}

static inline float remquo(float a, float b, int *quo)
{
return remquof(a, b, quo);
}

static inline float round(float a)
{
return roundf(a);
}

static inline long lround(float a)
{
return lroundf(a);
}

static inline long long llround(float a)
{
return llroundf(a);
}

static inline float trunc(float a)
{
return truncf(a);
}

static inline float rint(float a)
{
return rintf(a);
}

static inline long lrint(float a)
{
return lrintf(a);
}

static inline long long llrint(float a)
{
return llrintf(a);
}

static inline float nearbyint(float a)
{
return nearbyintf(a);
}

static inline float fdim(float a, float b)
{
return fdimf(a, b);
}

static inline float fma(float a, float b, float c)
{
return fmaf(a, b, c);
}

static inline unsigned min(unsigned a, unsigned b)
{
return umin(a, b);
}

static inline unsigned min(int a, unsigned b)
{
return umin((unsigned)a, b);
}

static inline unsigned min(unsigned a, int b)
{
return umin(a, (unsigned)b);
}

static inline long long min(long long a, long long b)
{
return llmin(a, b);
}

static inline unsigned long long min(unsigned long long a, unsigned long long b)
{
return ullmin(a, b);
}

static inline unsigned long long min(long long a, unsigned long long b)
{
return ullmin((unsigned long long)a, b);
}

static inline unsigned long long min(unsigned long long a, long long b)
{
return ullmin(a, (unsigned long long)b);
}

static inline float min(float a, float b)
{
return fminf(a, b);
}

static inline double min(double a, double b)
{
return fmin(a, b);
}

static inline double min(float a, double b)
{
return fmin((double)a, b);
}

static inline double min(double a, float b)
{
return fmin(a, (double)b);
}

static inline unsigned max(unsigned a, unsigned b)
{
return umax(a, b);
}

static inline unsigned max(int a, unsigned b)
{
return umax((unsigned)a, b);
}

static inline unsigned max(unsigned a, int b)
{
return umax(a, (unsigned)b);
}

static inline long long max(long long a, long long b)
{
return llmax(a, b);
}

static inline unsigned long long max(unsigned long long a, unsigned long long b)
{
return ullmax(a, b);
}

static inline unsigned long long max(long long a, unsigned long long b)
{
return ullmax((unsigned long long)a, b);
}

static inline unsigned long long max(unsigned long long a, long long b)
{
return ullmax(a, (unsigned long long)b);
}

static inline float max(float a, float b)
{
return fmaxf(a, b);
}

static inline double max(double a, double b)
{
return fmax(a, b);
}

static inline double max(float a, double b)
{
return fmax((double)a, b);
}

static inline double max(double a, float b)
{
return fmax(a, (double)b);
}
# 59 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
struct texture : public textureReference {

texture(int norm = 0, cudaTextureFilterMode
fMode = cudaFilterModePoint, cudaTextureAddressMode
aMode = cudaAddressModeClamp)
{
(this->normalized) = norm;
(this->filterMode) = fMode;
((this->addressMode)[0]) = aMode;
((this->addressMode)[1]) = aMode;
((this->addressMode)[2]) = aMode;
(this->channelDesc) = cudaCreateChannelDesc< T> ();
}

texture(int norm, cudaTextureFilterMode
fMode, cudaTextureAddressMode
aMode, cudaChannelFormatDesc
desc)
{
(this->normalized) = norm;
(this->filterMode) = fMode;
((this->addressMode)[0]) = aMode;
((this->addressMode)[1]) = aMode;
((this->addressMode)[2]) = aMode;
(this->channelDesc) = desc;
}
};
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 101 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaSetupArgument(T
arg, size_t
offset)

{
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
}

template<class T> inline cudaError_t
cudaHostAlloc(T **
ptr, size_t
size, unsigned
flags)

{
return cudaHostAlloc((void **)((void *)ptr), size, flags);
}

template<class T> inline cudaError_t
cudaHostGetDevicePointer(T **
pDevice, void *
pHost, unsigned
flags)

{
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
}

template<class T> inline cudaError_t
cudaMalloc(T **
devPtr, size_t
size)

{
return cudaMalloc((void **)((void *)devPtr), size);
}

template<class T> inline cudaError_t
cudaMallocHost(T **
ptr, size_t
size)

{
return cudaMallocHost((void **)((void *)ptr), size);
}

template<class T> inline cudaError_t
cudaMallocPitch(T **
devPtr, size_t *
pitch, size_t
width, size_t
height)

{
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
}
# 172 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
symbol, const void *
src, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyHostToDevice)

{
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
}

template<class T> inline cudaError_t
cudaMemcpyToSymbol(const T &
symbol, const void *
src, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyHostToDevice)

{
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
}

static inline cudaError_t cudaMemcpyToSymbolAsync(char *
symbol, const void *
src, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
}

template<class T> inline cudaError_t
cudaMemcpyToSymbolAsync(const T &
symbol, const void *
src, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
}
# 226 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
dst, char *
symbol, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyDeviceToHost)

{
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
}

template<class T> inline cudaError_t
cudaMemcpyFromSymbol(void *
dst, const T &
symbol, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyDeviceToHost)

{
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
}

static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
dst, char *
symbol, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
}

template<class T> inline cudaError_t
cudaMemcpyFromSymbolAsync(void *
dst, const T &
symbol, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
}

static inline cudaError_t cudaGetSymbolAddress(void **
devPtr, char *
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
}
# 304 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolAddress(void **
devPtr, const T &
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
}
# 319 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol)

{
return cudaGetSymbolSize(size, (const char *)symbol);
}
# 348 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolSize(size_t *
size, const T &
symbol)

{
return cudaGetSymbolSize(size, (const char *)(&symbol));
}
# 404 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, &tex, devPtr, (&desc), size);
}
# 448 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
}
# 503 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture2D(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t
width, size_t
height, size_t
pitch)

{
return cudaBindTexture2D(offset, &tex, devPtr, (&desc), width, height, pitch);
}
# 545 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc)

{
return cudaBindTextureToArray(&tex, array, (&desc));
}
# 582 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array)

{
auto cudaChannelFormatDesc desc;
auto cudaError_t err = cudaGetChannelDesc(&desc, array);

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
}
# 620 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaUnbindTexture(const texture< T, dim, readMode> &
tex)

{
return cudaUnbindTexture(&tex);
}
# 659 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode> &
tex)

{
return cudaGetTextureAlignmentOffset(offset, &tex);
}
# 708 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaLaunch(T *
entry)

{
return cudaLaunch((const char *)entry);
}
# 744 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaFuncGetAttributes(cudaFuncAttributes *
attr, T *
entry)

{
return cudaFuncGetAttributes(attr, (const char *)entry);
}
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 90 "/usr/include/wchar.h" 3
extern "C" { typedef
# 79 "/usr/include/wchar.h" 3
struct __mbstate_t {
int __count;

union {

unsigned __wch;



char __wchb[4];
} __value;
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 23 "/usr/include/_G_config.h" 3
struct _G_fpos_t {
__off_t __pos;
__mbstate_t __state;
} _G_fpos_t; }




extern "C" { typedef
# 28 "/usr/include/_G_config.h" 3
struct _G_fpos64_t {
__off64_t __pos;
__mbstate_t __state;
} _G_fpos64_t; }
# 53 "/usr/include/_G_config.h" 3
extern "C" { typedef short _G_int16_t; }
extern "C" { typedef int _G_int32_t; }
extern "C" { typedef unsigned short _G_uint16_t; }
extern "C" { typedef unsigned _G_uint32_t; }
# 43 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stdarg.h" 3
extern "C" { typedef __builtin_va_list __gnuc_va_list; }
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3
extern "C" { typedef void _IO_lock_t; }
# 186 "/usr/include/libio.h" 3
extern "C" { struct _IO_marker {
_IO_marker *_next;
_IO_FILE *_sbuf;



int _pos;
# 203 "/usr/include/libio.h" 3
}; }


enum __codecvt_result {

__codecvt_ok,
__codecvt_partial,
__codecvt_error,
__codecvt_noconv
};
# 271 "/usr/include/libio.h" 3
extern "C" { struct _IO_FILE {
int _flags;




char *_IO_read_ptr;
char *_IO_read_end;
char *_IO_read_base;
char *_IO_write_base;
char *_IO_write_ptr;
char *_IO_write_end;
char *_IO_buf_base;
char *_IO_buf_end;

char *_IO_save_base;
char *_IO_backup_base;
char *_IO_save_end;

_IO_marker *_markers;

_IO_FILE *_chain;

int _fileno;



int _flags2;

__off_t _old_offset;



unsigned short _cur_column;
signed char _vtable_offset;
char _shortbuf[1];



_IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3
__off64_t _offset;
# 328 "/usr/include/libio.h" 3
void *__pad1;
void *__pad2;
void *__pad3;
void *__pad4;
size_t __pad5;

int _mode;

char _unused2[((((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(size_t))];

}; }
# 344 "/usr/include/libio.h" 3
struct _IO_FILE_plus;

extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; }
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; }
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; }
# 364 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_read_fn(void *, char *, size_t); }
# 372 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_write_fn(void *, const char *, size_t); }
# 381 "/usr/include/libio.h" 3
extern "C" { typedef int __io_seek_fn(void *, __off64_t *, int); }


extern "C" { typedef int __io_close_fn(void *); }




extern "C" { typedef __io_read_fn cookie_read_function_t; }
extern "C" { typedef __io_write_fn cookie_write_function_t; }
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401 "/usr/include/libio.h" 3
extern "C" { typedef
# 396 "/usr/include/libio.h" 3
struct _IO_cookie_io_functions_t {
__io_read_fn *read;
__io_write_fn *write;
__io_seek_fn *seek;
__io_close_fn *close;
} _IO_cookie_io_functions_t; }
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }

struct _IO_cookie_file;


extern "C" void _IO_cookie_init(_IO_cookie_file *, int, void *, _IO_cookie_io_functions_t);
# 416 "/usr/include/libio.h" 3
extern "C" int __underflow(_IO_FILE *);
extern "C" int __uflow(_IO_FILE *);
extern "C" int __overflow(_IO_FILE *, int);
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *);
extern "C" int _IO_putc(int, _IO_FILE *);
extern "C" int _IO_feof(_IO_FILE *) throw();
extern "C" int _IO_ferror(_IO_FILE *) throw();

extern "C" int _IO_peekc_locked(_IO_FILE *);
# 469 "/usr/include/libio.h" 3
extern "C" void _IO_flockfile(_IO_FILE *) throw();
extern "C" void _IO_funlockfile(_IO_FILE *) throw();
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw();
# 488 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__);

extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list);

extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t);

extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);

extern "C" void _IO_free_backup_area(_IO_FILE *) throw();
# 80 "/usr/include/stdio.h" 3
extern "C" { typedef __gnuc_va_list va_list; }
# 91 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos_t fpos_t; }
# 97 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 145 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; }
extern "C" { extern _IO_FILE *stdout; }
extern "C" { extern _IO_FILE *stderr; }
# 155 "/usr/include/stdio.h" 3
extern "C" int remove(const char *) throw();

extern "C" int rename(const char *, const char *) throw();




extern "C" int renameat(int, const char *, int, const char *) throw();
# 172 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 182 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64();



extern "C" char *tmpnam(char *) throw();
# 192 "/usr/include/stdio.h" 3
extern "C" char *tmpnam_r(char *) throw();
# 204 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__));
# 214 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE *);




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

extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 283 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int, const char *) throw();
# 289 "/usr/include/stdio.h" 3
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw();




extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 300 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 307 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();



extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 318 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();



extern "C" void setlinebuf(FILE *) throw();
# 331 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 337 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);

extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 346 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 352 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list);

extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 361 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();



extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 374 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();


extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();


extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 390 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);


extern "C" int dprintf(int, const char *__restrict__, ...);
# 403 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 409 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);

extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 449 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 457 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);



extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 509 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
extern "C" int getc(FILE *);
# 516 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 528 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
extern "C" int getchar_unlocked();
# 539 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE *);
# 551 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
extern "C" int putc(int, FILE *);
# 558 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 572 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int, FILE *);
# 580 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
extern "C" int putchar_unlocked(int);
# 588 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);


extern "C" int putw(int, FILE *);
# 600 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 608 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 618 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 634 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);


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

extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 718 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);




extern "C" long ftell(FILE *);




extern "C" void rewind(FILE *);
# 742 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);




extern "C" __off_t ftello(FILE *);
# 767 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);




extern "C" int fsetpos(FILE *, const fpos_t *);
# 787 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int);
extern "C" __off64_t ftello64(FILE *);
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__);
extern "C" int fsetpos64(FILE *, const fpos64_t *);




extern "C" void clearerr(FILE *) throw();

extern "C" int feof(FILE *) throw();

extern "C" int ferror(FILE *) throw();




extern "C" void clearerr_unlocked(FILE *) throw();
extern "C" int feof_unlocked(FILE *) throw();
extern "C" int ferror_unlocked(FILE *) throw();
# 815 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
extern "C" { extern const char *const sys_errlist[]; }


extern "C" { extern int _sys_nerr; }
extern "C" { extern const char *const _sys_errlist[]; }
# 827 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();




extern "C" int fileno_unlocked(FILE *) throw();
# 842 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 848 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 854 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 860 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);




struct obstack;


extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();


extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 882 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();



extern "C" int ftrylockfile(FILE *) throw();


extern "C" void funlockfile(FILE *) throw();
# 62 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }

extern "C" { typedef int CUdevice; }
extern "C" { typedef struct CUctx_st *CUcontext; }
extern "C" { typedef struct CUmod_st *CUmodule; }
extern "C" { typedef struct CUfunc_st *CUfunction; }
extern "C" { typedef struct CUarray_st *CUarray; }
extern "C" { typedef struct CUtexref_st *CUtexref; }
extern "C" { typedef struct CUevent_st *CUevent; }
extern "C" { typedef struct CUstream_st *CUstream; }
# 91 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 82 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
CU_CTX_SCHED_AUTO,
CU_CTX_SCHED_SPIN,
CU_CTX_SCHED_YIELD,
CU_CTX_SCHED_MASK,
CU_CTX_BLOCKING_SYNC,
CU_CTX_MAP_HOST = 8,
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
CU_CTX_FLAGS_MASK = 31
} CUctx_flags; }
# 99 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 96 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
CU_EVENT_DEFAULT,
CU_EVENT_BLOCKING_SYNC
} CUevent_flags; }
# 113 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 104 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
CU_AD_FORMAT_UNSIGNED_INT16,
CU_AD_FORMAT_UNSIGNED_INT32,
CU_AD_FORMAT_SIGNED_INT8 = 8,
CU_AD_FORMAT_SIGNED_INT16,
CU_AD_FORMAT_SIGNED_INT32,
CU_AD_FORMAT_HALF = 16,
CU_AD_FORMAT_FLOAT = 32
} CUarray_format; }
# 122 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 118 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
CU_TR_ADDRESS_MODE_WRAP,
CU_TR_ADDRESS_MODE_CLAMP,
CU_TR_ADDRESS_MODE_MIRROR
} CUaddress_mode; }
# 130 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 127 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
CU_TR_FILTER_MODE_POINT,
CU_TR_FILTER_MODE_LINEAR
} CUfilter_mode; }
# 159 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 135 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,

CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
CU_DEVICE_ATTRIBUTE_INTEGRATED,
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE
} CUdevice_attribute; }
# 175 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 164 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
int maxThreadsPerBlock;
int maxThreadsDim[3];
int maxGridSize[3];
int sharedMemPerBlock;
int totalConstantMemory;
int SIMDWidth;
int memPitch;
int regsPerBlock;
int clockRate;
int textureAlign;
} CUdevprop; }
# 212 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 180 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 186 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 193 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 199 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_NUM_REGS,

CU_FUNC_ATTRIBUTE_MAX
} CUfunction_attribute; }
# 221 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 217 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
CU_MEMORYTYPE_HOST = 1,
CU_MEMORYTYPE_DEVICE,
CU_MEMORYTYPE_ARRAY
} CUmemorytype; }
# 230 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 226 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
CU_COMPUTEMODE_DEFAULT,
CU_COMPUTEMODE_EXCLUSIVE,
CU_COMPUTEMODE_PROHIBITED
} CUcomputemode; }
# 309 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 235 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {




CU_JIT_MAX_REGISTERS,
# 252 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 258 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 264 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 271 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 277 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 284 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 290 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 296 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,




CU_JIT_TARGET,
# 307 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY

} CUjit_option; }
# 320 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 314 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {

CU_TARGET_COMPUTE_10,
CU_TARGET_COMPUTE_11,
CU_TARGET_COMPUTE_12,
CU_TARGET_COMPUTE_13
} CUjit_target; }
# 333 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 325 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {


CU_PREFER_PTX,


CU_PREFER_BINARY

} CUjit_fallback; }
# 381 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 344 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {

CUDA_SUCCESS,
CUDA_ERROR_INVALID_VALUE,
CUDA_ERROR_OUT_OF_MEMORY,
CUDA_ERROR_NOT_INITIALIZED,
CUDA_ERROR_DEINITIALIZED,

CUDA_ERROR_NO_DEVICE = 100,
CUDA_ERROR_INVALID_DEVICE,

CUDA_ERROR_INVALID_IMAGE = 200,
CUDA_ERROR_INVALID_CONTEXT,
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
CUDA_ERROR_MAP_FAILED = 205,
CUDA_ERROR_UNMAP_FAILED,
CUDA_ERROR_ARRAY_IS_MAPPED,
CUDA_ERROR_ALREADY_MAPPED,
CUDA_ERROR_NO_BINARY_FOR_GPU,
CUDA_ERROR_ALREADY_ACQUIRED,
CUDA_ERROR_NOT_MAPPED,

CUDA_ERROR_INVALID_SOURCE = 300,
CUDA_ERROR_FILE_NOT_FOUND,

CUDA_ERROR_INVALID_HANDLE = 400,

CUDA_ERROR_NOT_FOUND = 500,

CUDA_ERROR_NOT_READY = 600,

CUDA_ERROR_LAUNCH_FAILED = 700,
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
CUDA_ERROR_LAUNCH_TIMEOUT,
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,

CUDA_ERROR_UNKNOWN = 999
} CUresult; }
# 427 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 407 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {

unsigned srcXInBytes;
unsigned srcY;
CUmemorytype srcMemoryType;
const void *srcHost;
CUdeviceptr srcDevice;
CUarray srcArray;
unsigned srcPitch;

unsigned dstXInBytes;
unsigned dstY;
CUmemorytype dstMemoryType;
void *dstHost;
CUdeviceptr dstDevice;
CUarray dstArray;
unsigned dstPitch;

unsigned WidthInBytes;
unsigned Height;
} CUDA_MEMCPY2D; }
# 461 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 432 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {

unsigned srcXInBytes;
unsigned srcY;
unsigned srcZ;
unsigned srcLOD;
CUmemorytype srcMemoryType;
const void *srcHost;
CUdeviceptr srcDevice;
CUarray srcArray;
void *reserved0;
unsigned srcPitch;
unsigned srcHeight;

unsigned dstXInBytes;
unsigned dstY;
unsigned dstZ;
unsigned dstLOD;
CUmemorytype dstMemoryType;
void *dstHost;
CUdeviceptr dstDevice;
CUarray dstArray;
void *reserved1;
unsigned dstPitch;
unsigned dstHeight;

unsigned WidthInBytes;
unsigned Height;
unsigned Depth;
} CUDA_MEMCPY3D; }
# 474 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 467 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR {
unsigned Width;
unsigned Height;

CUarray_format Format;

unsigned NumChannels;
} CUDA_ARRAY_DESCRIPTOR; }
# 490 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 480 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR {
unsigned Width;
unsigned Height;
unsigned Depth;

CUarray_format Format;

unsigned NumChannels;

unsigned Flags;
} CUDA_ARRAY3D_DESCRIPTOR; }
# 529 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);




extern "C" CUresult cuDriverGetVersion(int *);
# 542 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
extern "C" CUresult cuDeviceGetCount(int *);
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 556 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
extern "C" CUresult cuCtxDestroy(CUcontext);
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
extern "C" CUresult cuCtxDetach(CUcontext);
extern "C" CUresult cuCtxPushCurrent(CUcontext);
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
extern "C" CUresult cuCtxGetDevice(CUdevice *);
extern "C" CUresult cuCtxSynchronize();
# 572 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
extern "C" CUresult cuModuleUnload(CUmodule);
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 587 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);

extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 598 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);

extern "C" CUresult cuMemAllocHost(void **, unsigned);
extern "C" CUresult cuMemFreeHost(void *);

extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);

extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 620 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);


extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);


extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);


extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);


extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);



extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);



extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 659 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);



extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);



extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);


extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 681 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);

extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 696 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 706 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
extern "C" CUresult cuArrayDestroy(CUarray);

extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 719 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
extern "C" CUresult cuTexRefDestroy(CUtexref);

extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
extern "C" CUresult cuTexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, unsigned);
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);

extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 743 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
extern "C" CUresult cuParamSetf(CUfunction, int, float);
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 755 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 764 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
extern "C" CUresult cuEventRecord(CUevent, CUstream);
extern "C" CUresult cuEventQuery(CUevent);
extern "C" CUresult cuEventSynchronize(CUevent);
extern "C" CUresult cuEventDestroy(CUevent);
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 776 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
extern "C" CUresult cuStreamQuery(CUstream);
extern "C" CUresult cuStreamSynchronize(CUstream);
extern "C" CUresult cuStreamDestroy(CUstream);
# 65 "../../sdk/cutil.h"
enum CUTBoolean {

CUTFalse,
CUTTrue
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
# 162 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }

extern "C" { static inline float cuCrealf(cuFloatComplex x)
{
return x.x;
} }

extern "C" { static inline float cuCimagf(cuFloatComplex x)
{
return x.y;
} }

extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
r, float i)
{
auto cuFloatComplex res;
(res.x) = r;
(res.y) = i;
return res;
} }

extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
{
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
} }
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
y)
{
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));

} }

extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
y)
{
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));

} }
# 206 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
y)
{
auto cuFloatComplex prod;
prod = make_cuFloatComplex(cuCrealf(x) * cuCrealf(y) - cuCimagf(x) * cuCimagf(y), cuCrealf(x) * cuCimagf(y) + cuCimagf(x) * cuCrealf(y));



return prod;
} }
# 222 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
y)
{
auto cuFloatComplex quot;
auto float s = ((float)fabs((double)cuCrealf(y)) + (float)fabs((double)cuCimagf(y)));

auto float oos = ((1.0F) / s);
auto float ars = (cuCrealf(x) * oos);
auto float ais = (cuCimagf(x) * oos);
auto float brs = (cuCrealf(y) * oos);
auto float bis = (cuCimagf(y) * oos);
s = brs * brs + bis * bis;
oos = (1.0F) / s;
quot = make_cuFloatComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);

return quot;
} }
# 248 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
{
auto float a = cuCrealf(x);
auto float b = cuCimagf(x);
auto float v; auto float w; auto float t;
a = (float)fabs(a);
b = (float)fabs(b);
if (a > b) {
v = a;
w = b;
} else {
v = b;
w = a;
}
t = w / v;
t = (1.0F) + t * t;
t = v * (float)sqrt(t);
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
t = v + w;
}
return t;
} }


extern "C" { typedef double2 cuDoubleComplex; }

extern "C" { static inline double cuCreal(cuDoubleComplex x)
{
return x.x;
} }

extern "C" { static inline double cuCimag(cuDoubleComplex x)
{
return x.y;
} }

extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
r, double i)
{
auto cuDoubleComplex res;
(res.x) = r;
(res.y) = i;
return res;
} }

extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
{
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
} }

extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
y)
{
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));

} }

extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
y)
{
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));

} }
# 317 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
y)
{
auto cuDoubleComplex prod;
prod = make_cuDoubleComplex(cuCreal(x) * cuCreal(y) - cuCimag(x) * cuCimag(y), cuCreal(x) * cuCimag(y) + cuCimag(x) * cuCreal(y));



return prod;
} }
# 333 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
y)
{
auto cuDoubleComplex quot;
auto double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
auto double oos = ((1.0) / s);
auto double ars = (cuCreal(x) * oos);
auto double ais = (cuCimag(x) * oos);
auto double brs = (cuCreal(y) * oos);
auto double bis = (cuCimag(y) * oos);
s = brs * brs + bis * bis;
oos = (1.0) / s;
quot = make_cuDoubleComplex((ars * brs + ais * bis) * oos, (ais * brs - ars * bis) * oos);

return quot;
} }
# 356 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
{
auto double a = cuCreal(x);
auto double b = cuCimag(x);
auto double v; auto double w; auto double t;
a = fabs(a);
b = fabs(b);
if (a > b) {
v = a;
w = b;
} else {
v = b;
w = a;
}
t = w / v;
t = (1.0) + t * t;
t = v * sqrt(t);
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
{
t = v + w;
}
return t;
} }
# 387 "/usr/local/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
static inline cuComplex make_cuComplex(float x, float
y)
{
return make_cuFloatComplex(x, y);
}


static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
c)
{
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
}

static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
c)
{
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
}
# 71 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 61 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftResult_t {
CUFFT_SUCCESS,
CUFFT_INVALID_PLAN,
CUFFT_ALLOC_FAILED,
CUFFT_INVALID_TYPE,
CUFFT_INVALID_VALUE,
CUFFT_INTERNAL_ERROR,
CUFFT_EXEC_FAILED,
CUFFT_SETUP_FAILED,
CUFFT_INVALID_SIZE
} cufftResult; }




extern "C" { typedef unsigned cufftHandle; }



extern "C" { typedef float cufftReal; }
extern "C" { typedef double cufftDoubleReal; }




extern "C" { typedef cuComplex cufftComplex; }
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 101 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 94 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftType_t {
CUFFT_R2C = 42,
CUFFT_C2R = 44,
CUFFT_C2C = 41,
CUFFT_D2Z = 106,
CUFFT_Z2D = 108,
CUFFT_Z2Z = 105
} cufftType; }

extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);




extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);



extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);



extern "C" cufftResult cufftDestroy(cufftHandle);

extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);




extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);



extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);



extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);




extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);



extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);



extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 44 "../../sdk/cutil_inline.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
bdimx, unsigned bdimy, unsigned bdimz, char *
aname, int index, char *file, int line)
{
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
}

inline void __cutilCondition(int val, char *file, int line)
{
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
exit(1);
}
}

inline void __cutilExit(int argc, char **argv)
{
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
printf("\nPress ENTER to exit...\n");
fflush(stdout);
fflush(stderr);
getchar();
}
exit(0);
}




inline int cutGetMaxGflopsDeviceId()
{
auto int device_count = 0;
cudaGetDeviceCount(&device_count);

auto cudaDeviceProp device_properties;
auto int max_gflops_device = 0;
auto int max_gflops = 0;

auto int current_device = 0;
cudaGetDeviceProperties(&device_properties, current_device);
max_gflops = device_properties.multiProcessorCount * device_properties.clockRate;
++current_device;

while (current_device < device_count)
{
cudaGetDeviceProperties(&device_properties, current_device);
auto int gflops = (device_properties.multiProcessorCount * device_properties.clockRate);
if (gflops > max_gflops)
{
max_gflops = gflops;
max_gflops_device = current_device;
}
++current_device;
}

return max_gflops_device;
}


inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
{
do {
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);

exit(-1);
}
} while (0);
}
inline void __cuSafeCall(CUresult err, const char *file, const int line)
{
__cuSafeCallNoSync(err, file, line);
}

inline void __cuCtxSync(const char *file, const int line)
{
do {
auto CUresult err = cuCtxSynchronize();
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);

exit(-1);
}
} while (0);
}

inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
{
do {
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
} while (0);
}

inline void __cudaSafeCall(cudaError err, const char *file, const int line)
{
do {
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
} while (0);
}

inline void __cudaSafeThreadSync(const char *file, const int line)
{
do {
auto cudaError err = cudaThreadSynchronize();
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
} while (0);
}

inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
{
do {
if ((CUFFT_SUCCESS) != err) {
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);

exit(-1);
}
} while (0);
}

inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
{
if ((CUTTrue) != err) {
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);

exit(-1);
}
}
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
{
do {
auto cudaError_t err = cudaGetLastError();
if ((cudaSuccess) != err) {
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));

exit(-1);
}
err = cudaThreadSynchronize();
if ((cudaSuccess) != err) {
fprintf(stderr, "cutilCheckMsg cudaThreadSynchronize error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));

exit(-1);
}
} while (0);
}
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
{
do {
if (!(pointer)) {
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);

exit(-1);
}
} while (0);
}
# 214 "../../sdk/cutil_inline.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
{
auto int deviceCount;
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "../../sdk/cutil_inline.h", 217);
if (deviceCount == 0) {
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
exit(-1);
}
auto int dev = 0;
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }

auto cudaDeviceProp deviceProp;
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "../../sdk/cutil_inline.h", 227);
if ((deviceProp.major) < 1) {
fprintf(stderr, "cutil error: device does not support CUDA.\n");
exit(-1); }

if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
__cudaSafeCall(cudaSetDevice(dev), "../../sdk/cutil_inline.h", 234);
}

inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
{
cuDevice = 0;
auto int deviceCount = 0;
auto CUresult err = cuInit(0);
if ((CUDA_SUCCESS) == err) {
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "../../sdk/cutil_inline.h", 243); }
if (deviceCount == 0) {
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
exit(-1);
}
auto int dev = 0;
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
if (dev < 0) { dev = 0; }
if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "../../sdk/cutil_inline.h", 252);
auto char name[100];
cuDeviceGetName(name, 100, cuDevice);
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
fprintf(stderr, "Using device %d: %s\n", dev, name); }
}




inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
{
do {
auto cudaError_t err = cudaGetLastError();
if ((cudaSuccess) != err) {
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));

exit(-1);
}
err = cudaThreadSynchronize();
if ((cudaSuccess) != err) {
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));

exit(-1);
}
} while (0);
}



inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
{
do {
auto CUresult err = cuCtxSynchronize();
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);

exit(-1);
}
err = cuCtxSynchronize();
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);

exit(-1);
}
} while (0);
}
# 98 "/usr/include/c++/4.3/cstdio" 3
namespace std __attribute__((visibility("default"))) {

using ::FILE;
using ::fpos_t;

using ::clearerr;
using ::fclose;
using ::feof;
using ::ferror;
using ::fflush;
using ::fgetc;
using ::fgetpos;
using ::fgets;
using ::fopen;
using ::fprintf;
using ::fputc;
using ::fputs;
using ::fread;
using ::freopen;
using ::fscanf;
using ::fseek;
using ::fsetpos;
using ::ftell;
using ::fwrite;
using ::getc;
using ::getchar;
using ::gets;
using ::perror;
using ::printf;
using ::putc;
using ::putchar;
using ::puts;
using ::remove;
using ::rename;
using ::rewind;
using ::scanf;
using ::setbuf;
using ::setvbuf;
using ::sprintf;
using ::sscanf;
using ::tmpfile;
using ::tmpnam;
using ::ungetc;
using ::vfprintf;
using ::vprintf;
using ::vsprintf;

}
# 155 "/usr/include/c++/4.3/cstdio" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 170 "/usr/include/c++/4.3/cstdio" 3
using ::snprintf;
using ::vfscanf;
using ::vscanf;
using ::vsnprintf;
using ::vsscanf;


}

namespace std __attribute__((visibility("default"))) {

using __gnu_cxx::snprintf;
using __gnu_cxx::vfscanf;
using __gnu_cxx::vscanf;
using __gnu_cxx::vsnprintf;
using __gnu_cxx::vsscanf;

}
# 53 "/usr/include/GL/gl.h" 3
extern "C" { typedef unsigned GLenum; }
extern "C" { typedef unsigned char GLboolean; }
extern "C" { typedef unsigned GLbitfield; }
extern "C" { typedef signed char GLbyte; }
extern "C" { typedef short GLshort; }
extern "C" { typedef int GLint; }
extern "C" { typedef int GLsizei; }
extern "C" { typedef unsigned char GLubyte; }
extern "C" { typedef unsigned short GLushort; }
extern "C" { typedef unsigned GLuint; }
extern "C" { typedef float GLfloat; }
extern "C" { typedef float GLclampf; }
extern "C" { typedef double GLdouble; }
extern "C" { typedef double GLclampd; }
extern "C" { typedef void GLvoid; }
# 1287 "/usr/include/GL/gl.h" 3
extern "C" void glAccum(GLenum, GLfloat);
extern "C" void glAlphaFunc(GLenum, GLclampf);
extern "C" GLboolean glAreTexturesResident(GLsizei, const GLuint *, GLboolean *);
extern "C" void glArrayElement(GLint);
extern "C" void glBegin(GLenum);
extern "C" void glBindTexture(GLenum, GLuint);
extern "C" void glBitmap(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
extern "C" void glBlendFunc(GLenum, GLenum);
extern "C" void glCallList(GLuint);
extern "C" void glCallLists(GLsizei, GLenum, const GLvoid *);
extern "C" void glClear(GLbitfield);
extern "C" void glClearAccum(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glClearColor(GLclampf, GLclampf, GLclampf, GLclampf);
extern "C" void glClearDepth(GLclampd);
extern "C" void glClearIndex(GLfloat);
extern "C" void glClearStencil(GLint);
extern "C" void glClipPlane(GLenum, const GLdouble *);
extern "C" void glColor3b(GLbyte, GLbyte, GLbyte);
extern "C" void glColor3bv(const GLbyte *);
extern "C" void glColor3d(GLdouble, GLdouble, GLdouble);
extern "C" void glColor3dv(const GLdouble *);
extern "C" void glColor3f(GLfloat, GLfloat, GLfloat);
extern "C" void glColor3fv(const GLfloat *);
extern "C" void glColor3i(GLint, GLint, GLint);
extern "C" void glColor3iv(const GLint *);
extern "C" void glColor3s(GLshort, GLshort, GLshort);
extern "C" void glColor3sv(const GLshort *);
extern "C" void glColor3ub(GLubyte, GLubyte, GLubyte);
extern "C" void glColor3ubv(const GLubyte *);
extern "C" void glColor3ui(GLuint, GLuint, GLuint);
extern "C" void glColor3uiv(const GLuint *);
extern "C" void glColor3us(GLushort, GLushort, GLushort);
extern "C" void glColor3usv(const GLushort *);
extern "C" void glColor4b(GLbyte, GLbyte, GLbyte, GLbyte);
extern "C" void glColor4bv(const GLbyte *);
extern "C" void glColor4d(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glColor4dv(const GLdouble *);
extern "C" void glColor4f(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glColor4fv(const GLfloat *);
extern "C" void glColor4i(GLint, GLint, GLint, GLint);
extern "C" void glColor4iv(const GLint *);
extern "C" void glColor4s(GLshort, GLshort, GLshort, GLshort);
extern "C" void glColor4sv(const GLshort *);
extern "C" void glColor4ub(GLubyte, GLubyte, GLubyte, GLubyte);
extern "C" void glColor4ubv(const GLubyte *);
extern "C" void glColor4ui(GLuint, GLuint, GLuint, GLuint);
extern "C" void glColor4uiv(const GLuint *);
extern "C" void glColor4us(GLushort, GLushort, GLushort, GLushort);
extern "C" void glColor4usv(const GLushort *);
extern "C" void glColorMask(GLboolean, GLboolean, GLboolean, GLboolean);
extern "C" void glColorMaterial(GLenum, GLenum);
extern "C" void glColorPointer(GLint, GLenum, GLsizei, const GLvoid *);
extern "C" void glCopyPixels(GLint, GLint, GLsizei, GLsizei, GLenum);
extern "C" void glCopyTexImage1D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
extern "C" void glCopyTexImage2D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
extern "C" void glCopyTexSubImage1D(GLenum, GLint, GLint, GLint, GLint, GLsizei);
extern "C" void glCopyTexSubImage2D(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
extern "C" void glCullFace(GLenum);
extern "C" void glDeleteLists(GLuint, GLsizei);
extern "C" void glDeleteTextures(GLsizei, const GLuint *);
extern "C" void glDepthFunc(GLenum);
extern "C" void glDepthMask(GLboolean);
extern "C" void glDepthRange(GLclampd, GLclampd);
extern "C" void glDisable(GLenum);
extern "C" void glDisableClientState(GLenum);
extern "C" void glDrawArrays(GLenum, GLint, GLsizei);
extern "C" void glDrawBuffer(GLenum);
extern "C" void glDrawElements(GLenum, GLsizei, GLenum, const GLvoid *);
extern "C" void glDrawPixels(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
extern "C" void glEdgeFlag(GLboolean);
extern "C" void glEdgeFlagPointer(GLsizei, const GLvoid *);
extern "C" void glEdgeFlagv(const GLboolean *);
extern "C" void glEnable(GLenum);
extern "C" void glEnableClientState(GLenum);
extern "C" void glEnd();
extern "C" void glEndList();
extern "C" void glEvalCoord1d(GLdouble);
extern "C" void glEvalCoord1dv(const GLdouble *);
extern "C" void glEvalCoord1f(GLfloat);
extern "C" void glEvalCoord1fv(const GLfloat *);
extern "C" void glEvalCoord2d(GLdouble, GLdouble);
extern "C" void glEvalCoord2dv(const GLdouble *);
extern "C" void glEvalCoord2f(GLfloat, GLfloat);
extern "C" void glEvalCoord2fv(const GLfloat *);
extern "C" void glEvalMesh1(GLenum, GLint, GLint);
extern "C" void glEvalMesh2(GLenum, GLint, GLint, GLint, GLint);
extern "C" void glEvalPoint1(GLint);
extern "C" void glEvalPoint2(GLint, GLint);
extern "C" void glFeedbackBuffer(GLsizei, GLenum, GLfloat *);
extern "C" void glFinish();
extern "C" void glFlush();
extern "C" void glFogf(GLenum, GLfloat);
extern "C" void glFogfv(GLenum, const GLfloat *);
extern "C" void glFogi(GLenum, GLint);
extern "C" void glFogiv(GLenum, const GLint *);
extern "C" void glFrontFace(GLenum);
extern "C" void glFrustum(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" GLuint glGenLists(GLsizei);
extern "C" void glGenTextures(GLsizei, GLuint *);
extern "C" void glGetBooleanv(GLenum, GLboolean *);
extern "C" void glGetClipPlane(GLenum, GLdouble *);
extern "C" void glGetDoublev(GLenum, GLdouble *);
extern "C" GLenum glGetError();
extern "C" void glGetFloatv(GLenum, GLfloat *);
extern "C" void glGetIntegerv(GLenum, GLint *);
extern "C" void glGetLightfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetLightiv(GLenum, GLenum, GLint *);
extern "C" void glGetMapdv(GLenum, GLenum, GLdouble *);
extern "C" void glGetMapfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetMapiv(GLenum, GLenum, GLint *);
extern "C" void glGetMaterialfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetMaterialiv(GLenum, GLenum, GLint *);
extern "C" void glGetPixelMapfv(GLenum, GLfloat *);
extern "C" void glGetPixelMapuiv(GLenum, GLuint *);
extern "C" void glGetPixelMapusv(GLenum, GLushort *);
extern "C" void glGetPointerv(GLenum, GLvoid **);
extern "C" void glGetPolygonStipple(GLubyte *);
extern "C" const GLubyte *glGetString(GLenum);
extern "C" void glGetTexEnvfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetTexEnviv(GLenum, GLenum, GLint *);
extern "C" void glGetTexGendv(GLenum, GLenum, GLdouble *);
extern "C" void glGetTexGenfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetTexGeniv(GLenum, GLenum, GLint *);
extern "C" void glGetTexImage(GLenum, GLint, GLenum, GLenum, GLvoid *);
extern "C" void glGetTexLevelParameterfv(GLenum, GLint, GLenum, GLfloat *);
extern "C" void glGetTexLevelParameteriv(GLenum, GLint, GLenum, GLint *);
extern "C" void glGetTexParameterfv(GLenum, GLenum, GLfloat *);
extern "C" void glGetTexParameteriv(GLenum, GLenum, GLint *);
extern "C" void glHint(GLenum, GLenum);
extern "C" void glIndexMask(GLuint);
extern "C" void glIndexPointer(GLenum, GLsizei, const GLvoid *);
extern "C" void glIndexd(GLdouble);
extern "C" void glIndexdv(const GLdouble *);
extern "C" void glIndexf(GLfloat);
extern "C" void glIndexfv(const GLfloat *);
extern "C" void glIndexi(GLint);
extern "C" void glIndexiv(const GLint *);
extern "C" void glIndexs(GLshort);
extern "C" void glIndexsv(const GLshort *);
extern "C" void glIndexub(GLubyte);
extern "C" void glIndexubv(const GLubyte *);
extern "C" void glInitNames();
extern "C" void glInterleavedArrays(GLenum, GLsizei, const GLvoid *);
extern "C" GLboolean glIsEnabled(GLenum);
extern "C" GLboolean glIsList(GLuint);
extern "C" GLboolean glIsTexture(GLuint);
extern "C" void glLightModelf(GLenum, GLfloat);
extern "C" void glLightModelfv(GLenum, const GLfloat *);
extern "C" void glLightModeli(GLenum, GLint);
extern "C" void glLightModeliv(GLenum, const GLint *);
extern "C" void glLightf(GLenum, GLenum, GLfloat);
extern "C" void glLightfv(GLenum, GLenum, const GLfloat *);
extern "C" void glLighti(GLenum, GLenum, GLint);
extern "C" void glLightiv(GLenum, GLenum, const GLint *);
extern "C" void glLineStipple(GLint, GLushort);
extern "C" void glLineWidth(GLfloat);
extern "C" void glListBase(GLuint);
extern "C" void glLoadIdentity();
extern "C" void glLoadMatrixd(const GLdouble *);
extern "C" void glLoadMatrixf(const GLfloat *);
extern "C" void glLoadName(GLuint);
extern "C" void glLogicOp(GLenum);
extern "C" void glMap1d(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
extern "C" void glMap1f(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
extern "C" void glMap2d(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
extern "C" void glMap2f(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
extern "C" void glMapGrid1d(GLint, GLdouble, GLdouble);
extern "C" void glMapGrid1f(GLint, GLfloat, GLfloat);
extern "C" void glMapGrid2d(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
extern "C" void glMapGrid2f(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
extern "C" void glMaterialf(GLenum, GLenum, GLfloat);
extern "C" void glMaterialfv(GLenum, GLenum, const GLfloat *);
extern "C" void glMateriali(GLenum, GLenum, GLint);
extern "C" void glMaterialiv(GLenum, GLenum, const GLint *);
extern "C" void glMatrixMode(GLenum);
extern "C" void glMultMatrixd(const GLdouble *);
extern "C" void glMultMatrixf(const GLfloat *);
extern "C" void glNewList(GLuint, GLenum);
extern "C" void glNormal3b(GLbyte, GLbyte, GLbyte);
extern "C" void glNormal3bv(const GLbyte *);
extern "C" void glNormal3d(GLdouble, GLdouble, GLdouble);
extern "C" void glNormal3dv(const GLdouble *);
extern "C" void glNormal3f(GLfloat, GLfloat, GLfloat);
extern "C" void glNormal3fv(const GLfloat *);
extern "C" void glNormal3i(GLint, GLint, GLint);
extern "C" void glNormal3iv(const GLint *);
extern "C" void glNormal3s(GLshort, GLshort, GLshort);
extern "C" void glNormal3sv(const GLshort *);
extern "C" void glNormalPointer(GLenum, GLsizei, const GLvoid *);
extern "C" void glOrtho(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glPassThrough(GLfloat);
extern "C" void glPixelMapfv(GLenum, GLsizei, const GLfloat *);
extern "C" void glPixelMapuiv(GLenum, GLsizei, const GLuint *);
extern "C" void glPixelMapusv(GLenum, GLsizei, const GLushort *);
extern "C" void glPixelStoref(GLenum, GLfloat);
extern "C" void glPixelStorei(GLenum, GLint);
extern "C" void glPixelTransferf(GLenum, GLfloat);
extern "C" void glPixelTransferi(GLenum, GLint);
extern "C" void glPixelZoom(GLfloat, GLfloat);
extern "C" void glPointSize(GLfloat);
extern "C" void glPolygonMode(GLenum, GLenum);
extern "C" void glPolygonOffset(GLfloat, GLfloat);
extern "C" void glPolygonStipple(const GLubyte *);
extern "C" void glPopAttrib();
extern "C" void glPopClientAttrib();
extern "C" void glPopMatrix();
extern "C" void glPopName();
extern "C" void glPrioritizeTextures(GLsizei, const GLuint *, const GLclampf *);
extern "C" void glPushAttrib(GLbitfield);
extern "C" void glPushClientAttrib(GLbitfield);
extern "C" void glPushMatrix();
extern "C" void glPushName(GLuint);
extern "C" void glRasterPos2d(GLdouble, GLdouble);
extern "C" void glRasterPos2dv(const GLdouble *);
extern "C" void glRasterPos2f(GLfloat, GLfloat);
extern "C" void glRasterPos2fv(const GLfloat *);
extern "C" void glRasterPos2i(GLint, GLint);
extern "C" void glRasterPos2iv(const GLint *);
extern "C" void glRasterPos2s(GLshort, GLshort);
extern "C" void glRasterPos2sv(const GLshort *);
extern "C" void glRasterPos3d(GLdouble, GLdouble, GLdouble);
extern "C" void glRasterPos3dv(const GLdouble *);
extern "C" void glRasterPos3f(GLfloat, GLfloat, GLfloat);
extern "C" void glRasterPos3fv(const GLfloat *);
extern "C" void glRasterPos3i(GLint, GLint, GLint);
extern "C" void glRasterPos3iv(const GLint *);
extern "C" void glRasterPos3s(GLshort, GLshort, GLshort);
extern "C" void glRasterPos3sv(const GLshort *);
extern "C" void glRasterPos4d(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glRasterPos4dv(const GLdouble *);
extern "C" void glRasterPos4f(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glRasterPos4fv(const GLfloat *);
extern "C" void glRasterPos4i(GLint, GLint, GLint, GLint);
extern "C" void glRasterPos4iv(const GLint *);
extern "C" void glRasterPos4s(GLshort, GLshort, GLshort, GLshort);
extern "C" void glRasterPos4sv(const GLshort *);
extern "C" void glReadBuffer(GLenum);
extern "C" void glReadPixels(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
extern "C" void glRectd(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glRectdv(const GLdouble *, const GLdouble *);
extern "C" void glRectf(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glRectfv(const GLfloat *, const GLfloat *);
extern "C" void glRecti(GLint, GLint, GLint, GLint);
extern "C" void glRectiv(const GLint *, const GLint *);
extern "C" void glRects(GLshort, GLshort, GLshort, GLshort);
extern "C" void glRectsv(const GLshort *, const GLshort *);
extern "C" GLint glRenderMode(GLenum);
extern "C" void glRotated(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glRotatef(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glScaled(GLdouble, GLdouble, GLdouble);
extern "C" void glScalef(GLfloat, GLfloat, GLfloat);
extern "C" void glScissor(GLint, GLint, GLsizei, GLsizei);
extern "C" void glSelectBuffer(GLsizei, GLuint *);
extern "C" void glShadeModel(GLenum);
extern "C" void glStencilFunc(GLenum, GLint, GLuint);
extern "C" void glStencilMask(GLuint);
extern "C" void glStencilOp(GLenum, GLenum, GLenum);
extern "C" void glTexCoord1d(GLdouble);
extern "C" void glTexCoord1dv(const GLdouble *);
extern "C" void glTexCoord1f(GLfloat);
extern "C" void glTexCoord1fv(const GLfloat *);
extern "C" void glTexCoord1i(GLint);
extern "C" void glTexCoord1iv(const GLint *);
extern "C" void glTexCoord1s(GLshort);
extern "C" void glTexCoord1sv(const GLshort *);
extern "C" void glTexCoord2d(GLdouble, GLdouble);
extern "C" void glTexCoord2dv(const GLdouble *);
extern "C" void glTexCoord2f(GLfloat, GLfloat);
extern "C" void glTexCoord2fv(const GLfloat *);
extern "C" void glTexCoord2i(GLint, GLint);
extern "C" void glTexCoord2iv(const GLint *);
extern "C" void glTexCoord2s(GLshort, GLshort);
extern "C" void glTexCoord2sv(const GLshort *);
extern "C" void glTexCoord3d(GLdouble, GLdouble, GLdouble);
extern "C" void glTexCoord3dv(const GLdouble *);
extern "C" void glTexCoord3f(GLfloat, GLfloat, GLfloat);
extern "C" void glTexCoord3fv(const GLfloat *);
extern "C" void glTexCoord3i(GLint, GLint, GLint);
extern "C" void glTexCoord3iv(const GLint *);
extern "C" void glTexCoord3s(GLshort, GLshort, GLshort);
extern "C" void glTexCoord3sv(const GLshort *);
extern "C" void glTexCoord4d(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glTexCoord4dv(const GLdouble *);
extern "C" void glTexCoord4f(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glTexCoord4fv(const GLfloat *);
extern "C" void glTexCoord4i(GLint, GLint, GLint, GLint);
extern "C" void glTexCoord4iv(const GLint *);
extern "C" void glTexCoord4s(GLshort, GLshort, GLshort, GLshort);
extern "C" void glTexCoord4sv(const GLshort *);
extern "C" void glTexCoordPointer(GLint, GLenum, GLsizei, const GLvoid *);
extern "C" void glTexEnvf(GLenum, GLenum, GLfloat);
extern "C" void glTexEnvfv(GLenum, GLenum, const GLfloat *);
extern "C" void glTexEnvi(GLenum, GLenum, GLint);
extern "C" void glTexEnviv(GLenum, GLenum, const GLint *);
extern "C" void glTexGend(GLenum, GLenum, GLdouble);
extern "C" void glTexGendv(GLenum, GLenum, const GLdouble *);
extern "C" void glTexGenf(GLenum, GLenum, GLfloat);
extern "C" void glTexGenfv(GLenum, GLenum, const GLfloat *);
extern "C" void glTexGeni(GLenum, GLenum, GLint);
extern "C" void glTexGeniv(GLenum, GLenum, const GLint *);
extern "C" void glTexImage1D(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
extern "C" void glTexImage2D(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
extern "C" void glTexParameterf(GLenum, GLenum, GLfloat);
extern "C" void glTexParameterfv(GLenum, GLenum, const GLfloat *);
extern "C" void glTexParameteri(GLenum, GLenum, GLint);
extern "C" void glTexParameteriv(GLenum, GLenum, const GLint *);
extern "C" void glTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
extern "C" void glTexSubImage2D(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
extern "C" void glTranslated(GLdouble, GLdouble, GLdouble);
extern "C" void glTranslatef(GLfloat, GLfloat, GLfloat);
extern "C" void glVertex2d(GLdouble, GLdouble);
extern "C" void glVertex2dv(const GLdouble *);
extern "C" void glVertex2f(GLfloat, GLfloat);
extern "C" void glVertex2fv(const GLfloat *);
extern "C" void glVertex2i(GLint, GLint);
extern "C" void glVertex2iv(const GLint *);
extern "C" void glVertex2s(GLshort, GLshort);
extern "C" void glVertex2sv(const GLshort *);
extern "C" void glVertex3d(GLdouble, GLdouble, GLdouble);
extern "C" void glVertex3dv(const GLdouble *);
extern "C" void glVertex3f(GLfloat, GLfloat, GLfloat);
extern "C" void glVertex3fv(const GLfloat *);
extern "C" void glVertex3i(GLint, GLint, GLint);
extern "C" void glVertex3iv(const GLint *);
extern "C" void glVertex3s(GLshort, GLshort, GLshort);
extern "C" void glVertex3sv(const GLshort *);
extern "C" void glVertex4d(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void glVertex4dv(const GLdouble *);
extern "C" void glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat);
extern "C" void glVertex4fv(const GLfloat *);
extern "C" void glVertex4i(GLint, GLint, GLint, GLint);
extern "C" void glVertex4iv(const GLint *);
extern "C" void glVertex4s(GLshort, GLshort, GLshort, GLshort);
extern "C" void glVertex4sv(const GLshort *);
extern "C" void glVertexPointer(GLint, GLenum, GLsizei, const GLvoid *);
extern "C" void glViewport(GLint, GLint, GLsizei, GLsizei);
# 3861 "/usr/include/GL/glext.h" 3
extern "C" { typedef char GLchar; }




extern "C" { typedef ptrdiff_t GLintptr; }
extern "C" { typedef ptrdiff_t GLsizeiptr; }




extern "C" { typedef ptrdiff_t GLintptrARB; }
extern "C" { typedef ptrdiff_t GLsizeiptrARB; }




extern "C" { typedef char GLcharARB; }
extern "C" { typedef unsigned GLhandleARB; }




extern "C" { typedef unsigned short GLhalfARB; }



extern "C" { typedef unsigned short GLhalfNV; }



extern "C" { typedef signed long long GLint64EXT; }
extern "C" { typedef unsigned long long GLuint64EXT; }
# 3938 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDCOLORPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
extern "C" { typedef void (*PFNGLBLENDEQUATIONPROC)(GLenum); }
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOLORTABLEPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLCOPYCOLORTABLEPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPROC)(GLenum, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLCOLORSUBTABLEPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTERPROC)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *); }
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETHISTOGRAMPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMINMAXPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLHISTOGRAMPROC)(GLenum, GLsizei, GLenum, GLboolean); }
extern "C" { typedef void (*PFNGLMINMAXPROC)(GLenum, GLenum, GLboolean); }
extern "C" { typedef void (*PFNGLRESETHISTOGRAMPROC)(GLenum); }
extern "C" { typedef void (*PFNGLRESETMINMAXPROC)(GLenum); }
extern "C" { typedef void (*PFNGLTEXIMAGE3DPROC)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 4028 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLACTIVETEXTUREPROC)(GLenum); }
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DPROC)(GLenum, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SPROC)(GLenum, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DPROC)(GLenum, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FPROC)(GLenum, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IPROC)(GLenum, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SPROC)(GLenum, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IPROC)(GLenum, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SPROC)(GLenum, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IPROC)(GLenum, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEPROC)(GLclampf, GLboolean); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum, GLint, GLvoid *); }
# 4125 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLFOGCOORDFPROC)(GLfloat); }
extern "C" { typedef void (*PFNGLFOGCOORDFVPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLFOGCOORDDPROC)(GLdouble); }
extern "C" { typedef void (*PFNGLFOGCOORDDVPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERPROC)(GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSPROC)(GLenum, const GLsizei *, GLenum, const GLvoid **, GLsizei); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERFPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERIPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BPROC)(GLbyte, GLbyte, GLbyte); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBPROC)(GLubyte, GLubyte, GLubyte); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USPROC)(GLushort, GLushort, GLushort); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2DPROC)(GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS2DVPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FPROC)(GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FVPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IPROC)(GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IVPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SPROC)(GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SVPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DVPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FVPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IVPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SVPROC)(const GLshort *); }
# 4195 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGENQUERIESPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLDELETEQUERIESPROC)(GLsizei, const GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISQUERYPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBEGINQUERYPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLENDQUERYPROC)(GLenum); }
extern "C" { typedef void (*PFNGLGETQUERYIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVPROC)(GLuint, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLBINDBUFFERPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENBUFFERSPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISBUFFERPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, const GLvoid *, GLenum); }
extern "C" { typedef void (*PFNGLBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, GLvoid *); }
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERPROC)(GLenum, GLenum); }
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERPROC)(GLenum); }
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVPROC)(GLenum, GLenum, GLvoid **); }
# 4313 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum, GLenum); }
extern "C" { typedef void (*PFNGLDRAWBUFFERSPROC)(GLsizei, const GLenum *); }
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEPROC)(GLenum, GLenum, GLint, GLuint); }
extern "C" { typedef void (*PFNGLSTENCILMASKSEPARATEPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLATTACHSHADERPROC)(GLuint, GLuint); }
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONPROC)(GLuint, GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLCOMPILESHADERPROC)(GLuint); }
extern "C" { typedef GLuint (*PFNGLCREATEPROGRAMPROC)(void); }
extern "C" { typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum); }
extern "C" { typedef void (*PFNGLDELETEPROGRAMPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDELETESHADERPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDETACHSHADERPROC)(GLuint, GLuint); }
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint); }
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint); }
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *); }
extern "C" { typedef void (*PFNGLGETATTACHEDSHADERSPROC)(GLuint, GLsizei, GLsizei *, GLuint *); }
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONPROC)(GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
extern "C" { typedef void (*PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
extern "C" { typedef void (*PFNGLGETSHADERSOURCEPROC)(GLuint, GLsizei, GLsizei *, GLchar *); }
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONPROC)(GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLGETUNIFORMFVPROC)(GLuint, GLint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETUNIFORMIVPROC)(GLuint, GLint, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVPROC)(GLuint, GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint, GLenum, GLvoid **); }
extern "C" { typedef GLboolean (*PFNGLISPROGRAMPROC)(GLuint); }
extern "C" { typedef GLboolean (*PFNGLISSHADERPROC)(GLuint); }
extern "C" { typedef void (*PFNGLLINKPROGRAMPROC)(GLuint); }
extern "C" { typedef void (*PFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar **, const GLint *); }
extern "C" { typedef void (*PFNGLUSEPROGRAMPROC)(GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM1FPROC)(GLint, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM2FPROC)(GLint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM3FPROC)(GLint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM4FPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM1IPROC)(GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM2IPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM3IPROC)(GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM4IPROC)(GLint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM1FVPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM2FVPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM3FVPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM4FVPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM1IVPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM2IVPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM3IVPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM4IVPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMPROC)(GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DPROC)(GLuint, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FPROC)(GLuint, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SPROC)(GLuint, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DPROC)(GLuint, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FPROC)(GLuint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SPROC)(GLuint, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SPROC)(GLuint, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *); }
# 4418 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
# 4492 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORMASKIPROC)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean); }
extern "C" { typedef void (*PFNGLGETBOOLEANI_VPROC)(GLenum, GLuint, GLboolean *); }
extern "C" { typedef void (*PFNGLGETINTEGERI_VPROC)(GLenum, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLENABLEIPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDISABLEIPROC)(GLenum, GLuint); }
extern "C" { typedef GLboolean (*PFNGLISENABLEDIPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum); }
extern "C" { typedef void (*PFNGLENDTRANSFORMFEEDBACKPROC)(void); }
extern "C" { typedef void (*PFNGLBINDBUFFERRANGEPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr); }
extern "C" { typedef void (*PFNGLBINDBUFFERBASEPROC)(GLenum, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint, GLsizei, const GLint *, GLenum); }
extern "C" { typedef void (*PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLCLAMPCOLORPROC)(GLenum, GLenum); }
extern "C" { typedef void (*PFNGLBEGINCONDITIONALRENDERPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLENDCONDITIONALRENDERPROC)(void); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IPROC)(GLuint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IPROC)(GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IPROC)(GLuint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IPROC)(GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIPROC)(GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIPROC)(GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIPROC)(GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IVPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIVPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4BVPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4SVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UBVPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4USVPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIIVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLGETUNIFORMUIVPROC)(GLuint, GLint, GLuint *); }
extern "C" { typedef void (*PFNGLBINDFRAGDATALOCATIONPROC)(GLuint, GLuint, const GLchar *); }
extern "C" { typedef GLint (*PFNGLGETFRAGDATALOCATIONPROC)(GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLUNIFORM1UIPROC)(GLint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM2UIPROC)(GLint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM3UIPROC)(GLint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM4UIPROC)(GLint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM1UIVPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM2UIVPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM3UIVPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM4UIVPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLTEXPARAMETERIIVPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLTEXPARAMETERIUIVPROC)(GLenum, GLenum, const GLuint *); }
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIUIVPROC)(GLenum, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLCLEARBUFFERIVPROC)(GLenum, GLint, const GLint *); }
extern "C" { typedef void (*PFNGLCLEARBUFFERUIVPROC)(GLenum, GLint, const GLuint *); }
extern "C" { typedef void (*PFNGLCLEARBUFFERFVPROC)(GLenum, GLint, const GLfloat *); }
extern "C" { typedef void (*PFNGLCLEARBUFFERFIPROC)(GLenum, GLint, GLfloat, GLint); }
extern "C" { typedef const GLubyte *(*PFNGLGETSTRINGIPROC)(GLenum, GLuint); }
# 4590 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLACTIVETEXTUREARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DARBPROC)(GLenum, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1DVARBPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FARBPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1FVARBPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IARBPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1IVARBPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SARBPROC)(GLenum, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1SVARBPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DARBPROC)(GLenum, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2DVARBPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FARBPROC)(GLenum, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2FVARBPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IARBPROC)(GLenum, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2IVARBPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SARBPROC)(GLenum, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2SVARBPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3DVARBPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3FVARBPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IARBPROC)(GLenum, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3IVARBPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SARBPROC)(GLenum, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3SVARBPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DARBPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4DVARBPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FARBPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4FVARBPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IARBPROC)(GLenum, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4IVARBPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SARBPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4SVARBPROC)(GLenum, const GLshort *); }
# 4634 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *); }
# 4645 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSAMPLECOVERAGEARBPROC)(GLclampf, GLboolean); }
# 4667 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum, GLint, GLvoid *); }
# 4686 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFARBPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVARBPROC)(GLenum, const GLfloat *); }
# 4704 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLWEIGHTBVARBPROC)(GLint, const GLbyte *); }
extern "C" { typedef void (*PFNGLWEIGHTSVARBPROC)(GLint, const GLshort *); }
extern "C" { typedef void (*PFNGLWEIGHTIVARBPROC)(GLint, const GLint *); }
extern "C" { typedef void (*PFNGLWEIGHTFVARBPROC)(GLint, const GLfloat *); }
extern "C" { typedef void (*PFNGLWEIGHTDVARBPROC)(GLint, const GLdouble *); }
extern "C" { typedef void (*PFNGLWEIGHTUBVARBPROC)(GLint, const GLubyte *); }
extern "C" { typedef void (*PFNGLWEIGHTUSVARBPROC)(GLint, const GLushort *); }
extern "C" { typedef void (*PFNGLWEIGHTUIVARBPROC)(GLint, const GLuint *); }
extern "C" { typedef void (*PFNGLWEIGHTPOINTERARBPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLVERTEXBLENDARBPROC)(GLint); }
# 4725 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint); }
extern "C" { typedef void (*PFNGLMATRIXINDEXUBVARBPROC)(GLint, const GLubyte *); }
extern "C" { typedef void (*PFNGLMATRIXINDEXUSVARBPROC)(GLint, const GLushort *); }
extern "C" { typedef void (*PFNGLMATRIXINDEXUIVARBPROC)(GLint, const GLuint *); }
extern "C" { typedef void (*PFNGLMATRIXINDEXPOINTERARBPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 4780 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DARBPROC)(GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FARBPROC)(GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IARBPROC)(GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IVARBPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SARBPROC)(GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SVARBPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DARBPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FARBPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IARBPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IVARBPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SARBPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SVARBPROC)(const GLshort *); }
# 4864 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DARBPROC)(GLuint, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVARBPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FARBPROC)(GLuint, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVARBPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SARBPROC)(GLuint, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVARBPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DARBPROC)(GLuint, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVARBPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FARBPROC)(GLuint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVARBPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SARBPROC)(GLuint, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVARBPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVARBPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVARBPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SARBPROC)(GLuint, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVARBPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4BVARBPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DARBPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVARBPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FARBPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVARBPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4IVARBPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SARBPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVARBPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4USVARBPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMSTRINGARBPROC)(GLenum, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLBINDPROGRAMARBPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEPROGRAMSARBPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENPROGRAMSARBPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum, GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum, GLuint, GLdouble *); }
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum, GLuint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETPROGRAMIVARBPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGARBPROC)(GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint, GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint, GLenum, GLvoid **); }
extern "C" { typedef GLboolean (*PFNGLISPROGRAMARBPROC)(GLuint); }
# 4948 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBINDBUFFERARBPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEBUFFERSARBPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENBUFFERSARBPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISBUFFERARBPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBUFFERDATAARBPROC)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum); }
extern "C" { typedef void (*PFNGLBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETBUFFERSUBDATAARBPROC)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *); }
extern "C" { typedef GLvoid *(*PFNGLMAPBUFFERARBPROC)(GLenum, GLenum); }
extern "C" { typedef GLboolean (*PFNGLUNMAPBUFFERARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETBUFFERPOINTERVARBPROC)(GLenum, GLenum, GLvoid **); }
# 4973 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGENQUERIESARBPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLDELETEQUERIESARBPROC)(GLsizei, const GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISQUERYARBPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBEGINQUERYARBPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLENDQUERYARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLGETQUERYIVARBPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETQUERYOBJECTIVARBPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint, GLenum, GLuint *); }
# 5026 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDELETEOBJECTARBPROC)(GLhandleARB); }
extern "C" { typedef GLhandleARB (*PFNGLGETHANDLEARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLDETACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
extern "C" { typedef GLhandleARB (*PFNGLCREATESHADEROBJECTARBPROC)(GLenum); }
extern "C" { typedef void (*PFNGLSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *); }
extern "C" { typedef void (*PFNGLCOMPILESHADERARBPROC)(GLhandleARB); }
extern "C" { typedef GLhandleARB (*PFNGLCREATEPROGRAMOBJECTARBPROC)(void); }
extern "C" { typedef void (*PFNGLATTACHOBJECTARBPROC)(GLhandleARB, GLhandleARB); }
extern "C" { typedef void (*PFNGLLINKPROGRAMARBPROC)(GLhandleARB); }
extern "C" { typedef void (*PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB); }
extern "C" { typedef void (*PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB); }
extern "C" { typedef void (*PFNGLUNIFORM1FARBPROC)(GLint, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM2FARBPROC)(GLint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM3FARBPROC)(GLint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM4FARBPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLUNIFORM1IARBPROC)(GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM2IARBPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM3IARBPROC)(GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM4IARBPROC)(GLint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLUNIFORM1FVARBPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM2FVARBPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM3FVARBPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM4FVARBPROC)(GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORM1IVARBPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM2IVARBPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM3IVARBPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORM4IVARBPROC)(GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX2FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX3FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLUNIFORMMATRIX4FVARBPROC)(GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETINFOLOGARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
extern "C" { typedef void (*PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *); }
extern "C" { typedef GLint (*PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
extern "C" { typedef void (*PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
extern "C" { typedef void (*PFNGLGETUNIFORMFVARBPROC)(GLhandleARB, GLint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETUNIFORMIVARBPROC)(GLhandleARB, GLint, GLint *); }
extern "C" { typedef void (*PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *); }
# 5074 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB, GLuint, const GLcharARB *); }
extern "C" { typedef void (*PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *); }
extern "C" { typedef GLint (*PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB, const GLcharARB *); }
# 5104 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERSARBPROC)(GLsizei, const GLenum *); }
# 5116 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCLAMPCOLORARBPROC)(GLenum, GLenum); }
# 5141 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei); }
# 5169 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLboolean (*PFNGLISRENDERBUFFERPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBINDRENDERBUFFERPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETERENDERBUFFERSPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENRENDERBUFFERSPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEPROC)(GLenum, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef GLboolean (*PFNGLISFRAMEBUFFERPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBINDFRAMEBUFFERPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENFRAMEBUFFERSPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum, GLenum, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGENERATEMIPMAPPROC)(GLenum); }
extern "C" { typedef void (*PFNGLBLITFRAMEBUFFERPROC)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum); }
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum, GLenum, GLuint, GLint, GLint); }
# 5203 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERIARBPROC)(GLuint, GLenum, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum, GLenum, GLuint, GLint, GLenum); }
# 5218 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint, GLuint); }
# 5227 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLMAPBUFFERRANGEPROC)(GLenum, GLintptr, GLsizeiptr, GLbitfield); }
extern "C" { typedef void (*PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum, GLintptr, GLsizeiptr); }
# 5236 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXBUFFERARBPROC)(GLenum, GLenum, GLuint); }
# 5255 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBINDVERTEXARRAYPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDELETEVERTEXARRAYSPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENVERTEXARRAYSPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISVERTEXARRAYPROC)(GLuint); }
# 5270 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDCOLOREXTPROC)(GLclampf, GLclampf, GLclampf, GLclampf); }
# 5278 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPOLYGONOFFSETEXTPROC)(GLfloat, GLfloat); }
# 5291 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXIMAGE3DEXTPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 5301 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLTEXFILTERFUNCSGISPROC)(GLenum, GLenum, GLsizei, const GLfloat *); }
# 5311 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 5324 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
# 5345 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETHISTOGRAMEXTPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMINMAXEXTPROC)(GLenum, GLboolean, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLHISTOGRAMEXTPROC)(GLenum, GLsizei, GLenum, GLboolean); }
extern "C" { typedef void (*PFNGLMINMAXEXTPROC)(GLenum, GLenum, GLboolean); }
extern "C" { typedef void (*PFNGLRESETHISTOGRAMEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLRESETMINMAXEXTPROC)(GLenum); }
# 5374 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *); }
extern "C" { typedef void (*PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *); }
# 5404 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLESGIPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLCOPYCOLORTABLESGIPROC)(GLenum, GLenum, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLGETCOLORTABLESGIPROC)(GLenum, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum, GLenum, GLint *); }
# 5418 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPIXELTEXGENSGIXPROC)(GLenum); }
# 5431 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum, GLfloat *); }
# 5445 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXIMAGE4DSGISPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
# 5467 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLboolean (*PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei, const GLuint *, GLboolean *); }
extern "C" { typedef void (*PFNGLBINDTEXTUREEXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETETEXTURESEXTPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENTEXTURESEXTPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISTEXTUREEXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei, const GLuint *, const GLclampf *); }
# 5481 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDETAILTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 5491 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSHARPENTEXFUNCSGISPROC)(GLenum, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum, GLfloat *); }
# 5509 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSAMPLEMASKSGISPROC)(GLclampf, GLboolean); }
extern "C" { typedef void (*PFNGLSAMPLEPATTERNSGISPROC)(GLenum); }
# 5530 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLARRAYELEMENTEXTPROC)(GLint); }
extern "C" { typedef void (*PFNGLCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLDRAWARRAYSEXTPROC)(GLenum, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei, GLsizei, const GLboolean *); }
extern "C" { typedef void (*PFNGLGETPOINTERVEXTPROC)(GLenum, GLvoid **); }
extern "C" { typedef void (*PFNGLINDEXPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLNORMALPOINTEREXTPROC)(GLenum, GLsizei, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXCOORDPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLVERTEXPOINTEREXTPROC)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *); }
# 5570 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONEXTPROC)(GLenum); }
# 5601 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLSPRITEPARAMETERISGIXPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum, const GLint *); }
# 5617 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFEXTPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVEXTPROC)(GLenum, const GLfloat *); }
# 5627 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERFSGISPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERFVSGISPROC)(GLenum, const GLfloat *); }
# 5641 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLint (*PFNGLGETINSTRUMENTSSGIXPROC)(void); }
extern "C" { typedef void (*PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei, GLint *); }
extern "C" { typedef GLint (*PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *); }
extern "C" { typedef void (*PFNGLREADINSTRUMENTSSGIXPROC)(GLint); }
extern "C" { typedef void (*PFNGLSTARTINSTRUMENTSSGIXPROC)(void); }
extern "C" { typedef void (*PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint); }
# 5658 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFRAMEZOOMSGIXPROC)(GLint); }
# 5666 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTAGSAMPLEBUFFERSGIXPROC)(void); }
# 5677 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *); }
extern "C" { typedef void (*PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *); }
extern "C" { typedef void (*PFNGLDEFORMSGIXPROC)(GLbitfield); }
extern "C" { typedef void (*PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield); }
# 5688 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *); }
# 5696 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFLUSHRASTERSGIXPROC)(void); }
# 5709 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFOGFUNCSGISPROC)(GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETFOGFUNCSGISPROC)(GLfloat *); }
# 5727 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum, GLenum, GLfloat *); }
# 5749 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum, GLsizei, GLint, GLint, GLsizei); }
# 5762 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLHINTPGIPROC)(GLenum, GLint); }
# 5773 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORTABLEEXTPROC)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEEXTPROC)(GLenum, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum, GLenum, GLfloat *); }
# 5793 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLLISTPARAMETERFSGIXPROC)(GLuint, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLLISTPARAMETERFVSGIXPROC)(GLuint, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLLISTPARAMETERISGIXPROC)(GLuint, GLenum, GLint); }
extern "C" { typedef void (*PFNGLLISTPARAMETERIVSGIXPROC)(GLuint, GLenum, const GLint *); }
# 5826 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLINDEXMATERIALEXTPROC)(GLenum, GLenum); }
# 5834 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLINDEXFUNCEXTPROC)(GLenum, GLclampf); }
# 5847 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLLOCKARRAYSEXTPROC)(GLint, GLsizei); }
extern "C" { typedef void (*PFNGLUNLOCKARRAYSEXTPROC)(void); }
# 5857 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCULLPARAMETERDVEXTPROC)(GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLCULLPARAMETERFVEXTPROC)(GLenum, GLfloat *); }
# 5887 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum, GLenum); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLLIGHTENVISGIXPROC)(GLenum, GLint); }
# 5920 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *); }
# 5938 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLAPPLYTEXTUREEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLTEXTURELIGHTEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLTEXTUREMATERIALEXTPROC)(GLenum, GLenum); }
# 5961 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLASYNCMARKERSGIXPROC)(GLuint); }
extern "C" { typedef GLint (*PFNGLFINISHASYNCSGIXPROC)(GLuint *); }
extern "C" { typedef GLint (*PFNGLPOLLASYNCSGIXPROC)(GLuint *); }
extern "C" { typedef GLuint (*PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei); }
extern "C" { typedef void (*PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint, GLsizei); }
extern "C" { typedef GLboolean (*PFNGLISASYNCMARKERSGIXPROC)(GLuint); }
# 5985 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
extern "C" { typedef void (*PFNGLNORMALPOINTERVINTELPROC)(GLenum, const GLvoid **); }
extern "C" { typedef void (*PFNGLCOLORPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERVINTELPROC)(GLint, GLenum, const GLvoid **); }
# 6003 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum, GLenum, const GLfloat *); }
# 6042 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IEXTPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte, GLubyte, GLubyte); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort, GLushort, GLushort); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint, GLenum, GLsizei, const GLvoid *); }
# 6066 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXTURENORMALEXTPROC)(GLenum); }
# 6075 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum, GLint *, GLsizei *, GLsizei); }
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum, const GLsizei *, GLenum, const GLvoid **, GLsizei); }
# 6088 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFOGCOORDFEXTPROC)(GLfloat); }
extern "C" { typedef void (*PFNGLFOGCOORDFVEXTPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLFOGCOORDDEXTPROC)(GLdouble); }
extern "C" { typedef void (*PFNGLFOGCOORDDVEXTPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLFOGCOORDPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 6125 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTANGENT3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
extern "C" { typedef void (*PFNGLTANGENT3BVEXTPROC)(const GLbyte *); }
extern "C" { typedef void (*PFNGLTANGENT3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLTANGENT3DVEXTPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLTANGENT3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTANGENT3FVEXTPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLTANGENT3IEXTPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLTANGENT3IVEXTPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLTANGENT3SEXTPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLTANGENT3SVEXTPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLBINORMAL3BEXTPROC)(GLbyte, GLbyte, GLbyte); }
extern "C" { typedef void (*PFNGLBINORMAL3BVEXTPROC)(const GLbyte *); }
extern "C" { typedef void (*PFNGLBINORMAL3DEXTPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLBINORMAL3DVEXTPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLBINORMAL3FEXTPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLBINORMAL3FVEXTPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLBINORMAL3IEXTPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLBINORMAL3IVEXTPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLBINORMAL3SEXTPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLBINORMAL3SVEXTPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLTANGENTPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLBINORMALPOINTEREXTPROC)(GLenum, GLsizei, const GLvoid *); }
# 6170 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFINISHTEXTURESUNXPROC)(void); }
# 6185 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORISUNPROC)(GLint); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort); }
extern "C" { typedef void (*PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint); }
# 6206 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUISUNPROC)(GLuint); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum, GLsizei, const GLvoid **); }
# 6259 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *, const GLubyte *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *, const GLubyte *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *); }
# 6306 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum, GLenum, GLenum, GLenum); }
# 6314 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDFUNCSEPARATEINGRPROC)(GLenum, GLenum, GLenum, GLenum); }
# 6360 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLsizei, GLenum, GLsizei, const GLvoid *); }
# 6375 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGENVPROC)(void); }
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGENVPROC)(GLsizei, const GLvoid *); }
# 6396 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERFNVPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLCOMBINERPARAMETERINVPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLCOMBINEROUTPUTNVPROC)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean); }
extern "C" { typedef void (*PFNGLFINALCOMBINERINPUTNVPROC)(GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
# 6432 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLRESIZEBUFFERSMESAPROC)(void); }
# 6463 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLWINDOWPOS2DMESAPROC)(GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FMESAPROC)(GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IMESAPROC)(GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS2IVMESAPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SMESAPROC)(GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DMESAPROC)(GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FMESAPROC)(GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IMESAPROC)(GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS3IVMESAPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SMESAPROC)(GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *); }
extern "C" { typedef void (*PFNGLWINDOWPOS4DMESAPROC)(GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *); }
extern "C" { typedef void (*PFNGLWINDOWPOS4FMESAPROC)(GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *); }
extern "C" { typedef void (*PFNGLWINDOWPOS4IMESAPROC)(GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLWINDOWPOS4IVMESAPROC)(const GLint *); }
extern "C" { typedef void (*PFNGLWINDOWPOS4SMESAPROC)(GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *); }
# 6503 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const *, GLsizei, GLint); }
# 6519 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint, const GLboolean **, GLint); }
extern "C" { typedef void (*PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLINDEXPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLNORMALPOINTERLISTIBMPROC)(GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
extern "C" { typedef void (*PFNGLVERTEXPOINTERLISTIBMPROC)(GLint, GLenum, GLint, const GLvoid **, GLint); }
# 6558 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTBUFFERMASK3DFXPROC)(GLuint); }
# 6567 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSAMPLEMASKEXTPROC)(GLclampf, GLboolean); }
extern "C" { typedef void (*PFNGLSAMPLEPATTERNEXTPROC)(GLenum); }
# 6592 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean, GLboolean, GLboolean, GLboolean); }
# 6600 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLIGLOOINTERFACESGIXPROC)(GLenum, const GLvoid *); }
# 6622 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDELETEFENCESNVPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENFENCESNVPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISFENCENVPROC)(GLuint); }
extern "C" { typedef GLboolean (*PFNGLTESTFENCENVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLGETFENCEIVNVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLFINISHFENCENVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLSETFENCENVPROC)(GLuint, GLenum); }
# 6644 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *); }
extern "C" { typedef void (*PFNGLMAPPARAMETERIVNVPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMAPPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *); }
extern "C" { typedef void (*PFNGLGETMAPPARAMETERIVNVPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMAPPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLEVALMAPSNVPROC)(GLenum, GLenum); }
# 6669 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum, GLenum, GLfloat *); }
# 6761 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLboolean (*PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei, const GLuint *, GLboolean *); }
extern "C" { typedef void (*PFNGLBINDPROGRAMNVPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEPROGRAMSNVPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLEXECUTEPROGRAMNVPROC)(GLenum, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLGENPROGRAMSNVPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum, GLuint, GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum, GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETPROGRAMIVNVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMSTRINGNVPROC)(GLuint, GLenum, GLubyte *); }
extern "C" { typedef void (*PFNGLGETTRACKMATRIXIVNVPROC)(GLenum, GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint, GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint, GLenum, GLvoid **); }
extern "C" { typedef GLboolean (*PFNGLISPROGRAMNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLLOADPROGRAMNVPROC)(GLenum, GLuint, GLsizei, const GLubyte *); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum, GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum, GLuint, GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum, GLuint, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLTRACKMATRIXNVPROC)(GLenum, GLuint, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DNVPROC)(GLuint, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1DVNVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FNVPROC)(GLuint, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1FVNVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SNVPROC)(GLuint, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1SVNVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DNVPROC)(GLuint, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2DVNVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FNVPROC)(GLuint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2FVNVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SNVPROC)(GLuint, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2SVNVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3DVNVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3FVNVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SNVPROC)(GLuint, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3SVNVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DNVPROC)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4DVNVPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FNVPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4FVNVPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SNVPROC)(GLuint, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4SVNVPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBNVPROC)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint, GLsizei, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint, GLsizei, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint, GLsizei, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint, GLsizei, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint, GLsizei, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint, GLsizei, const GLubyte *); }
# 6859 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum, GLfloat *); }
# 6883 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLuint (*PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBEGINFRAGMENTSHADERATIPROC)(void); }
extern "C" { typedef void (*PFNGLENDFRAGMENTSHADERATIPROC)(void); }
extern "C" { typedef void (*PFNGLPASSTEXCOORDATIPROC)(GLuint, GLuint, GLenum); }
extern "C" { typedef void (*PFNGLSAMPLEMAPATIPROC)(GLuint, GLuint, GLenum); }
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint, const GLfloat *); }
# 6905 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPNTRIANGLESIATIPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLPNTRIANGLESFATIPROC)(GLenum, GLfloat); }
# 6925 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLuint (*PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei, const GLvoid *, GLenum); }
extern "C" { typedef GLboolean (*PFNGLISOBJECTBUFFERATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint, GLuint, GLsizei, const GLvoid *, GLenum); }
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLFREEOBJECTBUFFERATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLARRAYOBJECTATIPROC)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLGETARRAYOBJECTFVATIPROC)(GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETARRAYOBJECTIVATIPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint, GLenum, GLsizei, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 6985 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBEGINVERTEXSHADEREXTPROC)(void); }
extern "C" { typedef void (*PFNGLENDVERTEXSHADEREXTPROC)(void); }
extern "C" { typedef void (*PFNGLBINDVERTEXSHADEREXTPROC)(GLuint); }
extern "C" { typedef GLuint (*PFNGLGENVERTEXSHADERSEXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLSHADEROP1EXTPROC)(GLenum, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSHADEROP2EXTPROC)(GLenum, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSHADEROP3EXTPROC)(GLenum, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLSWIZZLEEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLWRITEMASKEXTPROC)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLINSERTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef GLuint (*PFNGLGENSYMBOLSEXTPROC)(GLenum, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLSETINVARIANTEXTPROC)(GLuint, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLSETLOCALCONSTANTEXTPROC)(GLuint, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLVARIANTBVEXTPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVARIANTSVEXTPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVARIANTIVEXTPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVARIANTFVEXTPROC)(GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLVARIANTDVEXTPROC)(GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLVARIANTUBVEXTPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVARIANTUSVEXTPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVARIANTUIVEXTPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVARIANTPOINTEREXTPROC)(GLuint, GLenum, GLuint, const GLvoid *); }
extern "C" { typedef void (*PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint); }
extern "C" { typedef GLuint (*PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum, GLenum); }
extern "C" { typedef GLuint (*PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum, GLenum); }
extern "C" { typedef GLuint (*PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum, GLenum, GLenum); }
extern "C" { typedef GLuint (*PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum, GLenum); }
extern "C" { typedef GLuint (*PFNGLBINDPARAMETEREXTPROC)(GLenum); }
extern "C" { typedef GLboolean (*PFNGLISVARIANTENABLEDEXTPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
extern "C" { typedef void (*PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint, GLenum, GLvoid **); }
extern "C" { typedef void (*PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
extern "C" { typedef void (*PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint, GLenum, GLboolean *); }
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint, GLenum, GLfloat *); }
# 7078 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXSTREAM1SATIPROC)(GLenum, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1SVATIPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1IATIPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1IVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1FATIPROC)(GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1FVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1DATIPROC)(GLenum, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM1DVATIPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SATIPROC)(GLenum, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2SVATIPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IATIPROC)(GLenum, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2IVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FATIPROC)(GLenum, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2FVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DATIPROC)(GLenum, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM2DVATIPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3SVATIPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3IVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SATIPROC)(GLenum, GLshort, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4SVATIPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IATIPROC)(GLenum, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4IVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4FVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLVERTEXSTREAM4DVATIPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3BATIPROC)(GLenum, GLbyte, GLbyte, GLbyte); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3BVATIPROC)(GLenum, const GLbyte *); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3SATIPROC)(GLenum, GLshort, GLshort, GLshort); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3SVATIPROC)(GLenum, const GLshort *); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3IATIPROC)(GLenum, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3IVATIPROC)(GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3FATIPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3FVATIPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3DATIPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLNORMALSTREAM3DVATIPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum); }
extern "C" { typedef void (*PFNGLVERTEXBLENDENVIATIPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLVERTEXBLENDENVFATIPROC)(GLenum, GLfloat); }
# 7132 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLELEMENTPOINTERATIPROC)(GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYATIPROC)(GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum, GLuint, GLuint, GLsizei); }
# 7142 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWMESHARRAYSSUNPROC)(GLenum, GLint, GLsizei, GLsizei); }
# 7168 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei, const GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISOCCLUSIONQUERYNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLENDOCCLUSIONQUERYNVPROC)(void); }
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint, GLenum, GLuint *); }
# 7183 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPOINTPARAMETERINVPROC)(GLenum, GLint); }
extern "C" { typedef void (*PFNGLPOINTPARAMETERIVNVPROC)(GLenum, const GLint *); }
# 7204 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLACTIVESTENCILFACEEXTPROC)(GLenum); }
# 7224 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLELEMENTPOINTERAPPLEPROC)(GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum, const GLint *, const GLsizei *, GLsizei); }
extern "C" { typedef void (*PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei); }
# 7243 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGENFENCESAPPLEPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLDELETEFENCESAPPLEPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLSETFENCEAPPLEPROC)(GLuint); }
extern "C" { typedef GLboolean (*PFNGLISFENCEAPPLEPROC)(GLuint); }
extern "C" { typedef GLboolean (*PFNGLTESTFENCEAPPLEPROC)(GLuint); }
extern "C" { typedef void (*PFNGLFINISHFENCEAPPLEPROC)(GLuint); }
extern "C" { typedef GLboolean (*PFNGLTESTOBJECTAPPLEPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLFINISHOBJECTAPPLEPROC)(GLenum, GLint); }
# 7261 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint); }
extern "C" { typedef void (*PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei, const GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISVERTEXARRAYAPPLEPROC)(GLuint); }
# 7274 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei, GLvoid *); }
extern "C" { typedef void (*PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei, GLvoid *); }
extern "C" { typedef void (*PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum, GLint); }
# 7292 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWBUFFERSATIPROC)(GLsizei, const GLenum *); }
# 7325 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint, GLsizei, const GLubyte *, const GLdouble *); }
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint, GLsizei, const GLubyte *, GLfloat *); }
extern "C" { typedef void (*PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint, GLsizei, const GLubyte *, GLdouble *); }
# 7383 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEX2HNVPROC)(GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEX2HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEX3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEX3HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEX4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEX4HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLNORMAL3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLNORMAL3HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLCOLOR3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLCOLOR3HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLCOLOR4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLCOLOR4HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLTEXCOORD1HNVPROC)(GLhalfNV); }
extern "C" { typedef void (*PFNGLTEXCOORD1HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLTEXCOORD2HNVPROC)(GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLTEXCOORD2HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLTEXCOORD3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLTEXCOORD3HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLTEXCOORD4HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLTEXCOORD4HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HNVPROC)(GLenum, GLhalfNV); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD1HVNVPROC)(GLenum, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HNVPROC)(GLenum, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD2HVNVPROC)(GLenum, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HNVPROC)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD3HVNVPROC)(GLenum, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HNVPROC)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLMULTITEXCOORD4HVNVPROC)(GLenum, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLFOGCOORDHNVPROC)(GLhalfNV); }
extern "C" { typedef void (*PFNGLFOGCOORDHVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HNVPROC)(GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHNVPROC)(GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HNVPROC)(GLuint, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB1HVNVPROC)(GLuint, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HNVPROC)(GLuint, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB2HVNVPROC)(GLuint, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HNVPROC)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB3HVNVPROC)(GLuint, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HNVPROC)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV); }
extern "C" { typedef void (*PFNGLVERTEXATTRIB4HVNVPROC)(GLuint, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint, GLsizei, const GLhalfNV *); }
# 7437 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPIXELDATARANGENVPROC)(GLenum, GLsizei, GLvoid *); }
extern "C" { typedef void (*PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum); }
# 7447 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTNVPROC)(void); }
extern "C" { typedef void (*PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint); }
# 7465 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLvoid *(*PFNGLMAPOBJECTBUFFERATIPROC)(GLuint); }
extern "C" { typedef void (*PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint); }
# 7475 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSTENCILOPSEPARATEATIPROC)(GLenum, GLenum, GLenum, GLenum); }
extern "C" { typedef void (*PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum, GLenum, GLint, GLuint); }
# 7486 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint, GLenum, GLint *); }
# 7500 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDEPTHBOUNDSEXTPROC)(GLclampd, GLclampd); }
# 7512 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum, GLenum); }
# 7564 "/usr/include/GL/glext.h" 3
extern "C" { typedef GLboolean (*PFNGLISRENDERBUFFEREXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBINDRENDERBUFFEREXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei, GLuint *); }
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef GLboolean (*PFNGLISFRAMEBUFFEREXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum, GLenum, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGENERATEMIPMAPEXTPROC)(GLenum); }
# 7588 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei, const GLvoid *); }
# 7601 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint, GLenum, GLint64EXT *); }
extern "C" { typedef void (*PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint, GLenum, GLuint64EXT *); }
# 7610 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXBUFFEREXTPROC)(GLenum, GLenum, GLuint); }
# 7628 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum); }
extern "C" { typedef void (*PFNGLENDTRANSFORMFEEDBACKNVPROC)(void); }
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLuint, const GLint *, GLenum); }
extern "C" { typedef void (*PFNGLBINDBUFFERRANGENVPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr); }
extern "C" { typedef void (*PFNGLBINDBUFFEROFFSETNVPROC)(GLenum, GLuint, GLuint, GLintptr); }
extern "C" { typedef void (*PFNGLBINDBUFFERBASENVPROC)(GLenum, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint, GLsizei, const GLint *, GLenum); }
extern "C" { typedef void (*PFNGLACTIVEVARYINGNVPROC)(GLuint, const GLchar *); }
extern "C" { typedef GLint (*PFNGLGETVARYINGLOCATIONNVPROC)(GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLGETACTIVEVARYINGNVPROC)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *); }
extern "C" { typedef void (*PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint, GLuint, GLint *); }
# 7649 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDEPTHRANGEDNVPROC)(GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLCLEARDEPTHDNVPROC)(GLdouble); }
extern "C" { typedef void (*PFNGLDEPTHBOUNDSDNVPROC)(GLdouble, GLdouble); }
# 7684 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean); }
extern "C" { typedef void (*PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum, GLuint, GLboolean *); }
extern "C" { typedef void (*PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLENABLEINDEXEDEXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDISABLEINDEXEDEXTPROC)(GLenum, GLuint); }
extern "C" { typedef GLboolean (*PFNGLISENABLEDINDEXEDEXTPROC)(GLenum, GLuint); }
# 7702 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, const GLuint *); }
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLCLEARCOLORIIEXTPROC)(GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLCLEARCOLORIUIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
# 7717 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLUNIFORMBUFFEREXTPROC)(GLuint, GLint, GLuint); }
extern "C" { typedef GLint (*PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint, GLint); }
extern "C" { typedef GLintptr (*PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint, GLint); }
# 7760 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETUNIFORMUIVEXTPROC)(GLuint, GLint, GLuint *); }
extern "C" { typedef void (*PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint, GLuint, const GLchar *); }
extern "C" { typedef GLint (*PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint, const GLchar *); }
extern "C" { typedef void (*PFNGLUNIFORM1UIEXTPROC)(GLint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM2UIEXTPROC)(GLint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM3UIEXTPROC)(GLint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM4UIEXTPROC)(GLint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLUNIFORM1UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM2UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM3UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLUNIFORM4UIVEXTPROC)(GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint, const GLbyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint, const GLshort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint, const GLubyte *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint, const GLushort *); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint, GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint, GLenum, GLuint *); }
# 7805 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint, GLenum, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum, GLenum, GLuint, GLint, GLenum); }
# 7816 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum, GLint); }
# 7839 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum, GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum, GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum, GLuint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum, GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum, GLuint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum, GLuint, GLuint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum, GLuint, GLuint *); }
# 7864 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum, GLuint, GLuint, GLsizei, const GLuint *); }
# 7874 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei); }
# 7882 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei); }
# 7890 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBLITFRAMEBUFFEREXTPROC)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum); }
# 7899 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei); }
# 7931 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint); }
# 7938 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint); }
# 7947 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETVIDEOIVNVPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETVIDEOUIVNVPROC)(GLuint, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLGETVIDEOI64VNVPROC)(GLuint, GLenum, GLint64EXT *); }
extern "C" { typedef void (*PFNGLGETVIDEOUI64VNVPROC)(GLuint, GLenum, GLuint64EXT *); }
# 7959 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLENDCONDITIONALRENDERNVPROC)(void); }
# 7974 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLENDTRANSFORMFEEDBACKEXTPROC)(void); }
extern "C" { typedef void (*PFNGLBINDBUFFERRANGEEXTPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr); }
extern "C" { typedef void (*PFNGLBINDBUFFEROFFSETEXTPROC)(GLenum, GLuint, GLuint, GLintptr); }
extern "C" { typedef void (*PFNGLBINDBUFFERBASEEXTPROC)(GLenum, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(GLuint, GLsizei, const GLint *, GLenum); }
extern "C" { typedef void (*PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(GLuint, GLuint, GLint *); }
# 8173 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield); }
extern "C" { typedef void (*PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield); }
extern "C" { typedef void (*PFNGLMATRIXLOADFEXTPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMATRIXLOADDEXTPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMATRIXMULTFEXTPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMATRIXMULTDEXTPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMATRIXROTATEFEXTPROC)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMATRIXROTATEDEXTPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMATRIXSCALEFEXTPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMATRIXSCALEDEXTPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMATRIXFRUSTUMEXTPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMATRIXORTHOEXTPROC)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLMATRIXPOPEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMATRIXPUSHEXTPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint, GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint, GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint, GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint, GLenum, GLint, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint, GLenum, GLint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint, GLenum, GLint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum, GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum, GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum, GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint); }
extern "C" { typedef void (*PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei); }
extern "C" { typedef void (*PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum, GLenum, GLint, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum, GLenum, GLint, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum, GLenum, GLint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLBINDMULTITEXTUREEXTPROC)(GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum, GLint, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLMULTITEXENVFEXTPROC)(GLenum, GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXENVFVEXTPROC)(GLenum, GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXENVIEXTPROC)(GLenum, GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXENVIVEXTPROC)(GLenum, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXGENDEXTPROC)(GLenum, GLenum, GLenum, GLdouble); }
extern "C" { typedef void (*PFNGLMULTITEXGENDVEXTPROC)(GLenum, GLenum, GLenum, const GLdouble *); }
extern "C" { typedef void (*PFNGLMULTITEXGENFEXTPROC)(GLenum, GLenum, GLenum, GLfloat); }
extern "C" { typedef void (*PFNGLMULTITEXGENFVEXTPROC)(GLenum, GLenum, GLenum, const GLfloat *); }
extern "C" { typedef void (*PFNGLMULTITEXGENIEXTPROC)(GLenum, GLenum, GLenum, GLint); }
extern "C" { typedef void (*PFNGLMULTITEXGENIVEXTPROC)(GLenum, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLGETMULTITEXENVFVEXTPROC)(GLenum, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMULTITEXENVIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMULTITEXGENDVEXTPROC)(GLenum, GLenum, GLenum, GLdouble *); }
extern "C" { typedef void (*PFNGLGETMULTITEXGENFVEXTPROC)(GLenum, GLenum, GLenum, GLfloat *); }
extern "C" { typedef void (*PFNGLGETMULTITEXGENIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum, GLuint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum, GLuint, GLdouble *); }
extern "C" { typedef void (*PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum, GLuint, GLvoid **); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint, GLenum, GLint, GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum, GLenum, GLint, GLvoid *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint, GLenum, GLenum, GLsizei, const GLvoid *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint, GLenum, GLuint, const GLdouble *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint, GLenum, GLuint, const GLfloat *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint, GLenum, GLuint, GLdouble *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint, GLenum, GLuint, GLfloat *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint, GLenum, GLenum, GLvoid *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint, GLenum, GLuint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint, GLenum, GLuint, const GLint *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint, GLenum, GLuint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint, GLenum, GLuint, const GLuint *); }
extern "C" { typedef void (*PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint, GLenum, GLuint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint, GLenum, GLuint, GLint *); }
extern "C" { typedef void (*PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint, GLenum, GLuint, GLuint *); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint, GLenum, GLenum, const GLuint *); }
extern "C" { typedef void (*PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint, GLenum, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLenum, const GLint *); }
extern "C" { typedef void (*PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLenum, const GLuint *); }
extern "C" { typedef void (*PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLenum, GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint, GLint, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint, GLint, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint, GLint, GLint, GLint, GLint, GLint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint, GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint, GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint, GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint, GLint, GLsizei, const GLint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint, GLint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint, GLint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint, GLint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint, GLsizeiptr, const GLvoid *, GLenum); }
extern "C" { typedef void (*PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint, GLintptr, GLsizeiptr, const GLvoid *); }
extern "C" { typedef GLvoid *(*PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint, GLenum); }
extern "C" { typedef GLboolean (*PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint); }
extern "C" { typedef void (*PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint, GLenum, GLvoid **); }
extern "C" { typedef void (*PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint, GLintptr, GLsizeiptr, GLvoid *); }
extern "C" { typedef void (*PFNGLTEXTUREBUFFEREXTPROC)(GLuint, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLMULTITEXBUFFEREXTPROC)(GLenum, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef GLenum (*PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint, GLenum, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint, GLenum, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint, GLenum, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint, GLenum, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum, GLenum); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint, GLsizei, const GLenum *); }
extern "C" { typedef void (*PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint, GLenum, GLint *); }
extern "C" { typedef void (*PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint, GLsizei, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint, GLenum, GLuint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint, GLenum, GLuint, GLint, GLint); }
extern "C" { typedef void (*PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint, GLenum, GLuint, GLint, GLenum); }
extern "C" { typedef void (*PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint, GLenum, GLuint); }
extern "C" { typedef void (*PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum, GLenum, GLuint); }
# 8376 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETMULTISAMPLEFVNVPROC)(GLenum, GLuint, GLfloat *); }
extern "C" { typedef void (*PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint, GLbitfield); }
extern "C" { typedef void (*PFNGLTEXRENDERBUFFERNVPROC)(GLenum, GLuint); }
# 8392 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum, GLuint); }
extern "C" { typedef void (*PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei, const GLuint *); }
extern "C" { typedef void (*PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei, GLuint *); }
extern "C" { typedef GLboolean (*PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLPAUSETRANSFORMFEEDBACKNVPROC)(void); }
extern "C" { typedef void (*PFNGLRESUMETRANSFORMFEEDBACKNVPROC)(void); }
extern "C" { typedef void (*PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum, GLuint); }
# 8417 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLBUFFERADDRESSRANGENVPROC)(GLenum, GLuint, GLuint64EXT, GLsizeiptr); }
extern "C" { typedef void (*PFNGLVERTEXFORMATNVPROC)(GLint, GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLNORMALFORMATNVPROC)(GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLCOLORFORMATNVPROC)(GLint, GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLINDEXFORMATNVPROC)(GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLTEXCOORDFORMATNVPROC)(GLint, GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLEDGEFLAGFORMATNVPROC)(GLsizei); }
extern "C" { typedef void (*PFNGLSECONDARYCOLORFORMATNVPROC)(GLint, GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLFOGCOORDFORMATNVPROC)(GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei); }
extern "C" { typedef void (*PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint, GLint, GLenum, GLsizei); }
extern "C" { typedef void (*PFNGLGETINTEGERUI64I_VNVPROC)(GLenum, GLuint, GLuint64EXT *); }
# 8450 "/usr/include/GL/glext.h" 3
extern "C" { typedef void (*PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum, GLenum, GLuint64EXT *); }
extern "C" { typedef void (*PFNGLGETINTEGERUI64VNVPROC)(GLenum, GLuint64EXT *); }
extern "C" { typedef void (*PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint, GLenum, GLuint64EXT *); }
extern "C" { typedef GLboolean (*PFNGLISBUFFERRESIDENTNVPROC)(GLenum); }
extern "C" { typedef GLboolean (*PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum); }
extern "C" { typedef void (*PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum, GLenum); }
extern "C" { typedef void (*PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint); }
extern "C" { typedef void (*PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint, GLenum); }
extern "C" { typedef void (*PFNGLUNIFORMUI64NVPROC)(GLint, GLuint64EXT); }
extern "C" { typedef void (*PFNGLUNIFORMUI64VNVPROC)(GLint, GLsizei, const GLuint64EXT *); }
extern "C" { typedef void (*PFNGLGETUNIFORMUI64VNVPROC)(GLuint, GLint, GLuint64EXT *); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint, GLint, GLuint64EXT); }
extern "C" { typedef void (*PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint, GLint, GLsizei, const GLuint64EXT *); }
# 270 "/usr/include/GL/glu.h" 3
class GLUnurbs;
class GLUquadric;
class GLUtesselator;
# 279 "/usr/include/GL/glu.h" 3
extern "C" { typedef GLUnurbs GLUnurbsObj; }
extern "C" { typedef GLUquadric GLUquadricObj; }
extern "C" { typedef GLUtesselator GLUtesselatorObj; }
extern "C" { typedef GLUtesselator GLUtriangulatorObj; }




extern "C" { typedef void (*_GLUfuncptr)(void); }

extern "C" void gluBeginCurve(GLUnurbs *);
extern "C" void gluBeginPolygon(GLUtesselator *);
extern "C" void gluBeginSurface(GLUnurbs *);
extern "C" void gluBeginTrim(GLUnurbs *);
extern "C" GLint gluBuild1DMipmapLevels(GLenum, GLint, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
extern "C" GLint gluBuild1DMipmaps(GLenum, GLint, GLsizei, GLenum, GLenum, const void *);
extern "C" GLint gluBuild2DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
extern "C" GLint gluBuild2DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
extern "C" GLint gluBuild3DMipmapLevels(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLint, GLint, GLint, const void *);
extern "C" GLint gluBuild3DMipmaps(GLenum, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
extern "C" GLboolean gluCheckExtension(const GLubyte *, const GLubyte *);
extern "C" void gluCylinder(GLUquadric *, GLdouble, GLdouble, GLdouble, GLint, GLint);
extern "C" void gluDeleteNurbsRenderer(GLUnurbs *);
extern "C" void gluDeleteQuadric(GLUquadric *);
extern "C" void gluDeleteTess(GLUtesselator *);
extern "C" void gluDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint);
extern "C" void gluEndCurve(GLUnurbs *);
extern "C" void gluEndPolygon(GLUtesselator *);
extern "C" void gluEndSurface(GLUnurbs *);
extern "C" void gluEndTrim(GLUnurbs *);
extern "C" const GLubyte *gluErrorString(GLenum);
extern "C" void gluGetNurbsProperty(GLUnurbs *, GLenum, GLfloat *);
extern "C" const GLubyte *gluGetString(GLenum);
extern "C" void gluGetTessProperty(GLUtesselator *, GLenum, GLdouble *);
extern "C" void gluLoadSamplingMatrices(GLUnurbs *, const GLfloat *, const GLfloat *, const GLint *);
extern "C" void gluLookAt(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" GLUnurbs *gluNewNurbsRenderer();
extern "C" GLUquadric *gluNewQuadric();
extern "C" GLUtesselator *gluNewTess();
extern "C" void gluNextContour(GLUtesselator *, GLenum);
extern "C" void gluNurbsCallback(GLUnurbs *, GLenum, _GLUfuncptr);
extern "C" void gluNurbsCallbackData(GLUnurbs *, GLvoid *);
extern "C" void gluNurbsCallbackDataEXT(GLUnurbs *, GLvoid *);
extern "C" void gluNurbsCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLenum);
extern "C" void gluNurbsProperty(GLUnurbs *, GLenum, GLfloat);
extern "C" void gluNurbsSurface(GLUnurbs *, GLint, GLfloat *, GLint, GLfloat *, GLint, GLint, GLfloat *, GLint, GLint, GLenum);
extern "C" void gluOrtho2D(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void gluPartialDisk(GLUquadric *, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble);
extern "C" void gluPerspective(GLdouble, GLdouble, GLdouble, GLdouble);
extern "C" void gluPickMatrix(GLdouble, GLdouble, GLdouble, GLdouble, GLint *);
extern "C" GLint gluProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
extern "C" void gluPwlCurve(GLUnurbs *, GLint, GLfloat *, GLint, GLenum);
extern "C" void gluQuadricCallback(GLUquadric *, GLenum, _GLUfuncptr);
extern "C" void gluQuadricDrawStyle(GLUquadric *, GLenum);
extern "C" void gluQuadricNormals(GLUquadric *, GLenum);
extern "C" void gluQuadricOrientation(GLUquadric *, GLenum);
extern "C" void gluQuadricTexture(GLUquadric *, GLboolean);
extern "C" GLint gluScaleImage(GLenum, GLsizei, GLsizei, GLenum, const void *, GLsizei, GLsizei, GLenum, GLvoid *);
extern "C" void gluSphere(GLUquadric *, GLdouble, GLint, GLint);
extern "C" void gluTessBeginContour(GLUtesselator *);
extern "C" void gluTessBeginPolygon(GLUtesselator *, GLvoid *);
extern "C" void gluTessCallback(GLUtesselator *, GLenum, _GLUfuncptr);
extern "C" void gluTessEndContour(GLUtesselator *);
extern "C" void gluTessEndPolygon(GLUtesselator *);
extern "C" void gluTessNormal(GLUtesselator *, GLdouble, GLdouble, GLdouble);
extern "C" void gluTessProperty(GLUtesselator *, GLenum, GLdouble);
extern "C" void gluTessVertex(GLUtesselator *, GLdouble *, GLvoid *);
extern "C" GLint gluUnProject(GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble *, GLdouble *, GLdouble *);
extern "C" GLint gluUnProject4(GLdouble, GLdouble, GLdouble, GLdouble, const GLdouble *, const GLdouble *, const GLint *, GLdouble, GLdouble, GLdouble *, GLdouble *, GLdouble *, GLdouble *);
# 200 "/usr/include/GL/freeglut_std.h" 3
extern "C" { extern void *glutStrokeRoman; }
extern "C" { extern void *glutStrokeMonoRoman; }
extern "C" { extern void *glutBitmap9By15; }
extern "C" { extern void *glutBitmap8By13; }
extern "C" { extern void *glutBitmapTimesRoman10; }
extern "C" { extern void *glutBitmapTimesRoman24; }
extern "C" { extern void *glutBitmapHelvetica10; }
extern "C" { extern void *glutBitmapHelvetica12; }
extern "C" { extern void *glutBitmapHelvetica18; }
# 384 "/usr/include/GL/freeglut_std.h" 3
extern "C" void glutInit(int *, char **);
extern "C" void glutInitWindowPosition(int, int);
extern "C" void glutInitWindowSize(int, int);
extern "C" void glutInitDisplayMode(unsigned);
extern "C" void glutInitDisplayString(const char *);




extern "C" void glutMainLoop();




extern "C" int glutCreateWindow(const char *);
extern "C" int glutCreateSubWindow(int, int, int, int, int);
extern "C" void glutDestroyWindow(int);
extern "C" void glutSetWindow(int);
extern "C" int glutGetWindow();
extern "C" void glutSetWindowTitle(const char *);
extern "C" void glutSetIconTitle(const char *);
extern "C" void glutReshapeWindow(int, int);
extern "C" void glutPositionWindow(int, int);
extern "C" void glutShowWindow();
extern "C" void glutHideWindow();
extern "C" void glutIconifyWindow();
extern "C" void glutPushWindow();
extern "C" void glutPopWindow();
extern "C" void glutFullScreen();




extern "C" void glutPostWindowRedisplay(int);
extern "C" void glutPostRedisplay();
extern "C" void glutSwapBuffers();




extern "C" void glutWarpPointer(int, int);
extern "C" void glutSetCursor(int);




extern "C" void glutEstablishOverlay();
extern "C" void glutRemoveOverlay();
extern "C" void glutUseLayer(GLenum);
extern "C" void glutPostOverlayRedisplay();
extern "C" void glutPostWindowOverlayRedisplay(int);
extern "C" void glutShowOverlay();
extern "C" void glutHideOverlay();




extern "C" int glutCreateMenu(void (*)(int));
extern "C" void glutDestroyMenu(int);
extern "C" int glutGetMenu();
extern "C" void glutSetMenu(int);
extern "C" void glutAddMenuEntry(const char *, int);
extern "C" void glutAddSubMenu(const char *, int);
extern "C" void glutChangeToMenuEntry(int, const char *, int);
extern "C" void glutChangeToSubMenu(int, const char *, int);
extern "C" void glutRemoveMenuItem(int);
extern "C" void glutAttachMenu(int);
extern "C" void glutDetachMenu(int);




extern "C" void glutTimerFunc(unsigned, void (*)(int), int);
extern "C" void glutIdleFunc(void (*)(void));




extern "C" void glutKeyboardFunc(void (*)(unsigned char, int, int));
extern "C" void glutSpecialFunc(void (*)(int, int, int));
extern "C" void glutReshapeFunc(void (*)(int, int));
extern "C" void glutVisibilityFunc(void (*)(int));
extern "C" void glutDisplayFunc(void (*)(void));
extern "C" void glutMouseFunc(void (*)(int, int, int, int));
extern "C" void glutMotionFunc(void (*)(int, int));
extern "C" void glutPassiveMotionFunc(void (*)(int, int));
extern "C" void glutEntryFunc(void (*)(int));

extern "C" void glutKeyboardUpFunc(void (*)(unsigned char, int, int));
extern "C" void glutSpecialUpFunc(void (*)(int, int, int));
extern "C" void glutJoystickFunc(void (*)(unsigned, int, int, int), int);
extern "C" void glutMenuStateFunc(void (*)(int));
extern "C" void glutMenuStatusFunc(void (*)(int, int, int));
extern "C" void glutOverlayDisplayFunc(void (*)(void));
extern "C" void glutWindowStatusFunc(void (*)(int));

extern "C" void glutSpaceballMotionFunc(void (*)(int, int, int));
extern "C" void glutSpaceballRotateFunc(void (*)(int, int, int));
extern "C" void glutSpaceballButtonFunc(void (*)(int, int));
extern "C" void glutButtonBoxFunc(void (*)(int, int));
extern "C" void glutDialsFunc(void (*)(int, int));
extern "C" void glutTabletMotionFunc(void (*)(int, int));
extern "C" void glutTabletButtonFunc(void (*)(int, int, int, int));




extern "C" int glutGet(GLenum);
extern "C" int glutDeviceGet(GLenum);
extern "C" int glutGetModifiers();
extern "C" int glutLayerGet(GLenum);




extern "C" void glutBitmapCharacter(void *, int);
extern "C" int glutBitmapWidth(void *, int);
extern "C" void glutStrokeCharacter(void *, int);
extern "C" int glutStrokeWidth(void *, int);
extern "C" int glutBitmapLength(void *, const unsigned char *);
extern "C" int glutStrokeLength(void *, const unsigned char *);




extern "C" void glutWireCube(GLdouble);
extern "C" void glutSolidCube(GLdouble);
extern "C" void glutWireSphere(GLdouble, GLint, GLint);
extern "C" void glutSolidSphere(GLdouble, GLint, GLint);
extern "C" void glutWireCone(GLdouble, GLdouble, GLint, GLint);
extern "C" void glutSolidCone(GLdouble, GLdouble, GLint, GLint);

extern "C" void glutWireTorus(GLdouble, GLdouble, GLint, GLint);
extern "C" void glutSolidTorus(GLdouble, GLdouble, GLint, GLint);
extern "C" void glutWireDodecahedron();
extern "C" void glutSolidDodecahedron();
extern "C" void glutWireOctahedron();
extern "C" void glutSolidOctahedron();
extern "C" void glutWireTetrahedron();
extern "C" void glutSolidTetrahedron();
extern "C" void glutWireIcosahedron();
extern "C" void glutSolidIcosahedron();




extern "C" void glutWireTeapot(GLdouble);
extern "C" void glutSolidTeapot(GLdouble);




extern "C" void glutGameModeString(const char *);
extern "C" int glutEnterGameMode();
extern "C" void glutLeaveGameMode();
extern "C" int glutGameModeGet(GLenum);




extern "C" int glutVideoResizeGet(GLenum);
extern "C" void glutSetupVideoResizing();
extern "C" void glutStopVideoResizing();
extern "C" void glutVideoResize(int, int, int, int);
extern "C" void glutVideoPan(int, int, int, int);




extern "C" void glutSetColor(int, GLfloat, GLfloat, GLfloat);
extern "C" GLfloat glutGetColor(int, int);
extern "C" void glutCopyColormap(int);




extern "C" void glutIgnoreKeyRepeat(int);
extern "C" void glutSetKeyRepeat(int);
extern "C" void glutForceJoystickFunc();




extern "C" int glutExtensionSupported(const char *);
extern "C" void glutReportErrors();
# 70 "/usr/local/cuda/bin/../include/cuda_gl_interop.h"
enum cudaGLMapFlags {

cudaGLMapFlagsNone,
cudaGLMapFlagsReadOnly,
cudaGLMapFlagsWriteDiscard
};

extern "C" cudaError_t cudaGLSetGLDevice(int);
extern "C" cudaError_t cudaGLRegisterBufferObject(GLuint);
extern "C" cudaError_t cudaGLMapBufferObject(void **, GLuint);
extern "C" cudaError_t cudaGLUnmapBufferObject(GLuint);
extern "C" cudaError_t cudaGLUnregisterBufferObject(GLuint);

extern "C" cudaError_t cudaGLSetBufferObjectMapFlags(GLuint, unsigned);
extern "C" cudaError_t cudaGLMapBufferObjectAsync(void **, GLuint, cudaStream_t);
extern "C" cudaError_t cudaGLUnmapBufferObjectAsync(GLuint, cudaStream_t);
# 49 "../../sdk/cutil_math.h"
extern "C" { typedef unsigned uint; }
extern "C" { typedef unsigned short ushort; }
# 85 "../../sdk/cutil_math.h"
inline float lerp(float a, float b, float t)
{
return a + t * (b - a);
}


inline float clamp(float f, float a, float b)
{
return fmaxf(a, fminf(f, b));
}
# 100 "../../sdk/cutil_math.h"
inline int2 operator-(int2 &a)
{
return make_int2(-(a.x), -(a.y));
}


inline int2 operator+(int2 a, int2 b)
{
return make_int2(a.x + b.x, a.y + b.y);
}
inline void operator+=(int2 &a, int2 b)
{
(a.x) += b.x; (a.y) += b.y;
}


inline int2 operator-(int2 a, int2 b)
{
return make_int2(a.x - b.x, a.y - b.y);
}
inline void operator-=(int2 &a, int2 b)
{
(a.x) -= b.x; (a.y) -= b.y;
}


inline int2 operator*(int2 a, int2 b)
{
return make_int2(a.x * b.x, a.y * b.y);
}
inline int2 operator*(int2 a, int s)
{
return make_int2(a.x * s, a.y * s);
}
inline int2 operator*(int s, int2 a)
{
return make_int2(a.x * s, a.y * s);
}
inline void operator*=(int2 &a, int s)
{
(a.x) *= s; (a.y) *= s;
}
# 147 "../../sdk/cutil_math.h"
inline float2 make_float2(float s)
{
return make_float2(s, s);
}
inline float2 make_float2(int2 a)
{
return make_float2((float)(a.x), (float)(a.y));
}


inline float2 operator-(float2 &a)
{
return make_float2(-(a.x), -(a.y));
}


inline float2 operator+(float2 a, float2 b)
{
return make_float2(a.x + b.x, a.y + b.y);
}
inline void operator+=(float2 &a, float2 b)
{
(a.x) += b.x; (a.y) += b.y;
}


inline float2 operator-(float2 a, float2 b)
{
return make_float2(a.x - b.x, a.y - b.y);
}
inline void operator-=(float2 &a, float2 b)
{
(a.x) -= b.x; (a.y) -= b.y;
}


inline float2 operator*(float2 a, float2 b)
{
return make_float2(a.x * b.x, a.y * b.y);
}
inline float2 operator*(float2 a, float s)
{
return make_float2(a.x * s, a.y * s);
}
inline float2 operator*(float s, float2 a)
{
return make_float2(a.x * s, a.y * s);
}
inline void operator*=(float2 &a, float s)
{
(a.x) *= s; (a.y) *= s;
}


inline float2 operator/(float2 a, float2 b)
{
return make_float2(a.x / b.x, a.y / b.y);
}
inline float2 operator/(float2 a, float s)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline float2 operator/(float s, float2 a)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline void operator/=(float2 &a, float s)
{
auto float inv = ((1.0F) / s);
(a *= inv);
}


inline float2 lerp(float2 a, float2 b, float t)
{
return (a + (t * (b - a)));
}


inline float2 clamp(float2 v, float a, float b)
{
return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
}

inline float2 clamp(float2 v, float2 a, float2 b)
{
return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}


inline float dot(float2 a, float2 b)
{
return a.x * b.x + a.y * b.y;
}


inline float length(float2 v)
{
return sqrtf(dot(v, v));
}


inline float2 normalize(float2 v)
{
auto float invLen = rsqrtf(dot(v, v));
return (v * invLen);
}


inline float2 floor(const float2 v)
{
return make_float2(floor(v.x), floor(v.y));
}


inline float2 reflect(float2 i, float2 n)
{
return (i - (((2.0F) * n) * dot(n, i)));
}


inline float2 fabs(float2 v)
{
return make_float2(fabs(v.x), fabs(v.y));
}
# 279 "../../sdk/cutil_math.h"
inline float3 make_float3(float s)
{
return make_float3(s, s, s);
}
inline float3 make_float3(float2 a)
{
return make_float3(a.x, a.y, (0.0F));
}
inline float3 make_float3(float2 a, float s)
{
return make_float3(a.x, a.y, s);
}
inline float3 make_float3(float4 a)
{
return make_float3(a.x, a.y, a.z);
}
inline float3 make_float3(int3 a)
{
return make_float3((float)(a.x), (float)(a.y), (float)(a.z));
}


inline float3 operator-(float3 &a)
{
return make_float3(-(a.x), -(a.y), -(a.z));
}


static inline float3 fminf(float3 a, float3 b)
{
return make_float3(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z));
}


static inline float3 fmaxf(float3 a, float3 b)
{
return make_float3(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z));
}


inline float3 operator+(float3 a, float3 b)
{
return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline float3 operator+(float3 a, float b)
{
return make_float3(a.x + b, a.y + b, a.z + b);
}
inline void operator+=(float3 &a, float3 b)
{
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
}


inline float3 operator-(float3 a, float3 b)
{
return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline float3 operator-(float3 a, float b)
{
return make_float3(a.x - b, a.y - b, a.z - b);
}
inline void operator-=(float3 &a, float3 b)
{
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
}


inline float3 operator*(float3 a, float3 b)
{
return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline float3 operator*(float3 a, float s)
{
return make_float3(a.x * s, a.y * s, a.z * s);
}
inline float3 operator*(float s, float3 a)
{
return make_float3(a.x * s, a.y * s, a.z * s);
}
inline void operator*=(float3 &a, float s)
{
(a.x) *= s; (a.y) *= s; (a.z) *= s;
}


inline float3 operator/(float3 a, float3 b)
{
return make_float3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline float3 operator/(float3 a, float s)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline float3 operator/(float s, float3 a)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline void operator/=(float3 &a, float s)
{
auto float inv = ((1.0F) / s);
(a *= inv);
}


inline float3 lerp(float3 a, float3 b, float t)
{
return (a + (t * (b - a)));
}


inline float3 clamp(float3 v, float a, float b)
{
return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}

inline float3 clamp(float3 v, float3 a, float3 b)
{
return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}


inline float dot(float3 a, float3 b)
{
return (a.x * b.x + a.y * b.y) + a.z * b.z;
}


inline float3 cross(float3 a, float3 b)
{
return make_float3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}


inline float length(float3 v)
{
return sqrtf(dot(v, v));
}


inline float3 normalize(float3 v)
{
auto float invLen = rsqrtf(dot(v, v));
return (v * invLen);
}


inline float3 floor(const float3 v)
{
return make_float3(floor(v.x), floor(v.y), floor(v.z));
}


inline float3 reflect(float3 i, float3 n)
{
return (i - (((2.0F) * n) * dot(n, i)));
}


inline float3 fabs(float3 v)
{
return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
}
# 449 "../../sdk/cutil_math.h"
inline float4 make_float4(float s)
{
return make_float4(s, s, s, s);
}
inline float4 make_float4(float3 a)
{
return make_float4(a.x, a.y, a.z, (0.0F));
}
inline float4 make_float4(float3 a, float w)
{
return make_float4(a.x, a.y, a.z, w);
}
inline float4 make_float4(int4 a)
{
return make_float4((float)(a.x), (float)(a.y), (float)(a.z), (float)(a.w));
}


inline float4 operator-(float4 &a)
{
return make_float4(-(a.x), -(a.y), -(a.z), -(a.w));
}


static inline float4 fminf(float4 a, float4 b)
{
return make_float4(fminf(a.x, b.x), fminf(a.y, b.y), fminf(a.z, b.z), fminf(a.w, b.w));
}


static inline float4 fmaxf(float4 a, float4 b)
{
return make_float4(fmaxf(a.x, b.x), fmaxf(a.y, b.y), fmaxf(a.z, b.z), fmaxf(a.w, b.w));
}


inline float4 operator+(float4 a, float4 b)
{
return make_float4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
inline void operator+=(float4 &a, float4 b)
{
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z; (a.w) += b.w;
}


inline float4 operator-(float4 a, float4 b)
{
return make_float4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
inline void operator-=(float4 &a, float4 b)
{
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z; (a.w) -= b.w;
}


inline float4 operator*(float4 a, float s)
{
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
}
inline float4 operator*(float s, float4 a)
{
return make_float4(a.x * s, a.y * s, a.z * s, a.w * s);
}
inline void operator*=(float4 &a, float s)
{
(a.x) *= s; (a.y) *= s; (a.z) *= s; (a.w) *= s;
}


inline float4 operator/(float4 a, float4 b)
{
return make_float4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}
inline float4 operator/(float4 a, float s)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline float4 operator/(float s, float4 a)
{
auto float inv = ((1.0F) / s);
return (a * inv);
}
inline void operator/=(float4 &a, float s)
{
auto float inv = ((1.0F) / s);
(a *= inv);
}


inline float4 lerp(float4 a, float4 b, float t)
{
return (a + (t * (b - a)));
}


inline float4 clamp(float4 v, float a, float b)
{
return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}

inline float4 clamp(float4 v, float4 a, float4 b)
{
return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}


inline float dot(float4 a, float4 b)
{
return ((a.x * b.x + a.y * b.y) + a.z * b.z) + a.w * b.w;
}


inline float length(float4 r)
{
return sqrtf(dot(r, r));
}


inline float4 normalize(float4 v)
{
auto float invLen = rsqrtf(dot(v, v));
return (v * invLen);
}


inline float4 floor(const float4 v)
{
return make_float4(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
}


inline float4 fabs(float4 v)
{
return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
}
# 591 "../../sdk/cutil_math.h"
inline int3 make_int3(int s)
{
return make_int3(s, s, s);
}
inline int3 make_int3(float3 a)
{
return make_int3((int)(a.x), (int)(a.y), (int)(a.z));
}


inline int3 operator-(int3 &a)
{
return make_int3(-(a.x), -(a.y), -(a.z));
}


inline int3 min(int3 a, int3 b)
{
return make_int3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}


inline int3 max(int3 a, int3 b)
{
return make_int3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}


inline int3 operator+(int3 a, int3 b)
{
return make_int3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline void operator+=(int3 &a, int3 b)
{
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
}


inline int3 operator-(int3 a, int3 b)
{
return make_int3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline void operator-=(int3 &a, int3 b)
{
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
}


inline int3 operator*(int3 a, int3 b)
{
return make_int3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline int3 operator*(int3 a, int s)
{
return make_int3(a.x * s, a.y * s, a.z * s);
}
inline int3 operator*(int s, int3 a)
{
return make_int3(a.x * s, a.y * s, a.z * s);
}
inline void operator*=(int3 &a, int s)
{
(a.x) *= s; (a.y) *= s; (a.z) *= s;
}


inline int3 operator/(int3 a, int3 b)
{
return make_int3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline int3 operator/(int3 a, int s)
{
return make_int3(a.x / s, a.y / s, a.z / s);
}
inline int3 operator/(int s, int3 a)
{
return make_int3(a.x / s, a.y / s, a.z / s);
}
inline void operator/=(int3 &a, int s)
{
(a.x) /= s; (a.y) /= s; (a.z) /= s;
}


inline int clamp(int f, int a, int b)
{
return max(a, min(f, b));
}

inline int3 clamp(int3 v, int a, int b)
{
return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}

inline int3 clamp(int3 v, int3 a, int3 b)
{
return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
# 696 "../../sdk/cutil_math.h"
inline uint3 make_uint3(uint s)
{
return make_uint3(s, s, s);
}
inline uint3 make_uint3(float3 a)
{
return make_uint3((unsigned)(a.x), (unsigned)(a.y), (unsigned)(a.z));
}


inline uint3 min(uint3 a, uint3 b)
{
return make_uint3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}


inline uint3 max(uint3 a, uint3 b)
{
return make_uint3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}


inline uint3 operator+(uint3 a, uint3 b)
{
return make_uint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline void operator+=(uint3 &a, uint3 b)
{
(a.x) += b.x; (a.y) += b.y; (a.z) += b.z;
}


inline uint3 operator-(uint3 a, uint3 b)
{
return make_uint3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline void operator-=(uint3 &a, uint3 b)
{
(a.x) -= b.x; (a.y) -= b.y; (a.z) -= b.z;
}


inline uint3 operator*(uint3 a, uint3 b)
{
return make_uint3(a.x * b.x, a.y * b.y, a.z * b.z);
}
inline uint3 operator*(uint3 a, uint s)
{
return make_uint3(a.x * s, a.y * s, a.z * s);
}
inline uint3 operator*(uint s, uint3 a)
{
return make_uint3(a.x * s, a.y * s, a.z * s);
}
inline void operator*=(uint3 &a, uint s)
{
(a.x) *= s; (a.y) *= s; (a.z) *= s;
}


inline uint3 operator/(uint3 a, uint3 b)
{
return make_uint3(a.x / b.x, a.y / b.y, a.z / b.z);
}
inline uint3 operator/(uint3 a, uint s)
{
return make_uint3(a.x / s, a.y / s, a.z / s);
}
inline uint3 operator/(uint s, uint3 a)
{
return make_uint3(a.x / s, a.y / s, a.z / s);
}
inline void operator/=(uint3 &a, uint s)
{
(a.x) /= s; (a.y) /= s; (a.z) /= s;
}


inline uint clamp(uint f, uint a, uint b)
{
return max(a, min(f, b));
}

inline uint3 clamp(uint3 v, uint a, uint b)
{
return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}

inline uint3 clamp(uint3 v, uint3 a, uint3 b)
{
return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
# 18 "particles_kernel.cuh"
extern "C" { typedef unsigned uint; }

struct SimParams {
float4 colliderPos;
float colliderRadius;

float3 gravity;
float globalDamping;
float particleRadius;

uint3 gridSize;
uint numCells;
float3 worldOrigin;
float3 cellSize;

uint numBodies;
uint maxParticlesPerCell;

float spring;
float damping;
float shear;
float attraction;
float boundaryDamping;
};
# 45 "particles_kernel.cu"
static texture< float4, 1, cudaReadModeElementType> oldPosTex;
static texture< float4, 1, cudaReadModeElementType> oldVelTex;

static texture< uint2, 1, cudaReadModeElementType> particleHashTex;
static texture< unsigned, 1, cudaReadModeElementType> cellStartTex;

static texture< unsigned, 1, cudaReadModeElementType> gridCountersTex;
static texture< unsigned, 1, cudaReadModeElementType> gridCellsTex;


static SimParams params__cuda_shadow_variable__;



void integrate__entry(float4 *newPos, float4 *newVel, float4 *
oldPos, float4 *oldVel, float
deltaTime);
# 132 "particles_kernel.cu"
void updateGridD__entry(float4 *pos, uint *
gridCounters, uint *
gridCells);
# 147 "particles_kernel.cu"
void calcHashD__entry(float4 *pos, uint2 *
particleHash);
# 164 "particles_kernel.cu"
void reorderDataAndFindCellStartD__entry(uint2 *particleHash, float4 *
oldPos, float4 *
oldVel, float4 *
sortedPos, float4 *
sortedVel, uint *
cellStart);
# 336 "particles_kernel.cu"
void collideD__entry(float4 *newPos, float4 *newVel, float4 *
oldPos, float4 *oldVel, uint2 *

particleHash, uint *
cellStart);
# 45 "radixsort.cuh"
extern "C" { typedef unsigned uint; }
extern "C" { typedef unsigned short ushort; }
# 57 "radixsort.cuh"
typedef
# 53 "radixsort.cuh"
struct __attribute__((__aligned__(8))) KeyValuePair {
uint key;
uint value;

} KeyValuePair;


extern "C" void RadixSort(KeyValuePair *, KeyValuePair *, uint, uint);
# 44 "radixsort_kernel.cu"
static const int NUM_SMS = 16;
static const int NUM_THREADS_PER_SM = 192;
static const int NUM_THREADS_PER_BLOCK = 64;

static const int NUM_BLOCKS = ((NUM_THREADS_PER_SM / NUM_THREADS_PER_BLOCK) * NUM_SMS);
static const int RADIX = 8;
static const int RADICES = (1 << RADIX);
static const int RADIXMASK = (RADICES - 1);



static const int RADIXBITS = 32;

static const int RADIXTHREADS = 16;
static const int RADIXGROUPS = (NUM_THREADS_PER_BLOCK / RADIXTHREADS);
static const int TOTALRADIXGROUPS = (NUM_BLOCKS * RADIXGROUPS);
static const int SORTRADIXGROUPS = (TOTALRADIXGROUPS * RADICES);
static const int GRFELEMENTS = ((NUM_THREADS_PER_BLOCK / RADIXTHREADS) * RADICES);
static const int GRFSIZE = ((GRFELEMENTS) * sizeof(uint));


static const int PREFIX_NUM_THREADS_PER_SM = NUM_THREADS_PER_SM;
static const int PREFIX_NUM_THREADS_PER_BLOCK = PREFIX_NUM_THREADS_PER_SM;
static const int PREFIX_NUM_BLOCKS = ((PREFIX_NUM_THREADS_PER_SM / PREFIX_NUM_THREADS_PER_BLOCK) * NUM_SMS);
static const int PREFIX_BLOCKSIZE = (SORTRADIXGROUPS / PREFIX_NUM_BLOCKS);
static const int PREFIX_GRFELEMENTS = (PREFIX_BLOCKSIZE + (2 * PREFIX_NUM_THREADS_PER_BLOCK));
static const int PREFIX_GRFSIZE = ((PREFIX_GRFELEMENTS) * sizeof(uint));


static const int SHUFFLE_GRFOFFSET = (RADIXGROUPS * RADICES);
static const int SHUFFLE_GRFELEMENTS = (SHUFFLE_GRFOFFSET + PREFIX_NUM_BLOCKS);
static const int SHUFFLE_GRFSIZE = ((SHUFFLE_GRFELEMENTS) * sizeof(uint));
# 81 "radixsort_kernel.cu"
uint gRadixSum[(TOTALRADIXGROUPS * RADICES)];
static uint dRadixSum__cuda_shadow_variable__[(TOTALRADIXGROUPS * RADICES)];
uint gRadixBlockSum[PREFIX_NUM_BLOCKS];
static uint dRadixBlockSum__cuda_shadow_variable__[PREFIX_NUM_BLOCKS];
# 101 "radixsort_kernel.cu"
void RadixSum__entry(KeyValuePair *pData, uint elements, uint elements_rounded_to_3072, uint shift);
# 251 "radixsort_kernel.cu"
void RadixPrefixSum__entry();
# 374 "radixsort_kernel.cu"
void RadixAddOffsetsAndShuffle__entry(KeyValuePair *pSrc, KeyValuePair *pDst, uint elements, uint elements_rounded_to_3072, int shift);
# 50 "radixsort.cu"
extern "C" { void RadixSort(KeyValuePair *pData0, KeyValuePair *pData1, uint elements, uint bits)
{

auto uint elements_rounded_to_3072;
auto int modval = (elements % (3072));
if (modval == 0) {
elements_rounded_to_3072 = elements; } else {

elements_rounded_to_3072 = elements + (3072 - modval); }


for (uint shift = (0); shift < bits; shift += (RADIX))
{



cudaConfigureCall(NUM_BLOCKS, NUM_THREADS_PER_BLOCK, GRFSIZE) ? ((void)0) : RadixSum__entry(pData0, elements, elements_rounded_to_3072, shift);

cudaConfigureCall(PREFIX_NUM_BLOCKS, PREFIX_NUM_THREADS_PER_BLOCK, PREFIX_GRFSIZE) ? ((void)0) : RadixPrefixSum__entry();

cudaConfigureCall(NUM_BLOCKS, NUM_THREADS_PER_BLOCK, SHUFFLE_GRFSIZE) ? ((void)0) : RadixAddOffsetsAndShuffle__entry(pData0, pData1, elements, elements_rounded_to_3072, shift);


auto KeyValuePair *pTemp = pData0;
pData0 = pData1;
pData1 = pTemp;
}
} }
# 52 "particleSystem.cu"
extern "C" { void cudaInit(int argc, char **argv)
{

if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
cutilDeviceInit(argc, argv); } else {

cudaSetDevice(cutGetMaxGflopsDeviceId()); }
} }

extern "C" { void allocateArray(void **devPtr, size_t size)
{
__cudaSafeCall(cudaMalloc(devPtr, size), "particleSystem.cu", 63);
} }

extern "C" { void freeArray(void *devPtr)
{
__cudaSafeCall(cudaFree(devPtr), "particleSystem.cu", 68);
} }

extern "C" { void threadSync()
{
__cudaSafeCall(cudaThreadSynchronize(), "particleSystem.cu", 73);
} }

extern "C" { void copyArrayFromDevice(void *host, const void *device, unsigned vbo, int size)
{
if (vbo) {
__cudaSafeCall(cudaGLMapBufferObject((void **)(&device), vbo), "particleSystem.cu", 79); }

__cudaSafeCall(cudaMemcpy(host, device, size, cudaMemcpyDeviceToHost), "particleSystem.cu", 81);

if (vbo) {
__cudaSafeCall(cudaGLUnmapBufferObject(vbo), "particleSystem.cu", 84); }
} }

extern "C" { void copyArrayToDevice(void *device, const void *host, int offset, int size)
{
__cudaSafeCall(cudaMemcpy((char *)device + offset, host, size, cudaMemcpyHostToDevice), "particleSystem.cu", 89);
} }

extern "C" { void registerGLBufferObject(uint vbo)
{
__cudaSafeCall(cudaGLRegisterBufferObject(vbo), "particleSystem.cu", 94);
} }

extern "C" { void unregisterGLBufferObject(uint vbo)
{
__cudaSafeCall(cudaGLUnregisterBufferObject(vbo), "particleSystem.cu", 99);
} }

extern "C" { void setParameters(SimParams *hostParams)
{

__cudaSafeCall(cudaMemcpyToSymbol(params__cuda_shadow_variable__, hostParams, sizeof(SimParams)), "particleSystem.cu", 105);
} }


extern "C" { int iDivUp(int a, int b) {
return ((a % b) != 0) ? (a / b + 1) : (a / b);
} }


extern "C" { void computeGridSize(int n, int blockSize, int &numBlocks, int &numThreads)
{
numThreads = min(blockSize, n);
numBlocks = iDivUp(n, numThreads);
} }


extern "C" { void integrateSystem(uint vboOldPos, uint vboNewPos, float *
oldVel, float *newVel, float
deltaTime, int
numParticles)
{
auto int numThreads; auto int numBlocks;
computeGridSize(numParticles, 256, numBlocks, numThreads);

auto float *oldPos; auto float *newPos;
__cudaSafeCall(cudaGLMapBufferObject((void **)(&oldPos), vboOldPos), "particleSystem.cu", 130);
__cudaSafeCall(cudaGLMapBufferObject((void **)(&newPos), vboNewPos), "particleSystem.cu", 131);


cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : integrate__entry((float4 *)newPos, (float4 *)newVel, (float4 *)oldPos, (float4 *)oldVel, deltaTime);




__cutilCheckMsg("integrate kernel execution failed", "particleSystem.cu", 139);

__cudaSafeCall(cudaGLUnmapBufferObject(vboOldPos), "particleSystem.cu", 141);
__cudaSafeCall(cudaGLUnmapBufferObject(vboNewPos), "particleSystem.cu", 142);
} }


extern "C" { void updateGrid(uint vboPos, uint *
gridCounters, uint *
gridCells, uint
numParticles, uint
numCells)
{
auto int numThreads; auto int numBlocks;
computeGridSize(numParticles, 256, numBlocks, numThreads);

auto float *pos;
__cudaSafeCall(cudaGLMapBufferObject((void **)(&pos), vboPos), "particleSystem.cu", 156);

__cudaSafeCall(cudaMemset(gridCounters, 0, numCells * sizeof(uint)), "particleSystem.cu", 158);


cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : updateGridD__entry((float4 *)pos, gridCounters, gridCells);




__cutilCheckMsg("Kernel execution failed", "particleSystem.cu", 166);

__cudaSafeCall(cudaGLUnmapBufferObject(vboPos), "particleSystem.cu", 168);
} }



extern "C" { void calcHash(uint vboPos, uint *
particleHash, int
numParticles)
{
auto int numThreads; auto int numBlocks;
computeGridSize(numParticles, 256, numBlocks, numThreads);

auto float *pos;
__cudaSafeCall(cudaGLMapBufferObject((void **)(&pos), vboPos), "particleSystem.cu", 181);


cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : calcHashD__entry((float4 *)pos, (uint2 *)particleHash);



__cutilCheckMsg("Kernel execution failed", "particleSystem.cu", 188);

__cudaSafeCall(cudaGLUnmapBufferObject(vboPos), "particleSystem.cu", 190);
} }


extern "C" { void reorderDataAndFindCellStart(uint *particleHash, uint
vboOldPos, float *
oldVel, float *
sortedPos, float *
sortedVel, uint *
cellStart, uint
numParticles, uint
numCells)
{
auto int numThreads; auto int numBlocks;
computeGridSize(numParticles, 256, numBlocks, numThreads);

__cudaSafeCall(cudaMemset(cellStart, 4294967295U, numCells * sizeof(uint)), "particleSystem.cu", 206);

auto float *oldPos;
__cudaSafeCall(cudaGLMapBufferObject((void **)(&oldPos), vboOldPos), "particleSystem.cu", 209);


__cudaSafeCall(cudaBindTexture(0, oldPosTex, oldPos, numParticles * sizeof(float4)), "particleSystem.cu", 212);
__cudaSafeCall(cudaBindTexture(0, oldVelTex, oldVel, numParticles * sizeof(float4)), "particleSystem.cu", 213);


cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : reorderDataAndFindCellStartD__entry((uint2 *)particleHash, (float4 *)oldPos, (float4 *)oldVel, (float4 *)sortedPos, (float4 *)sortedVel, (uint *)cellStart);
# 223 "particleSystem.cu"
__cutilCheckMsg("Kernel execution failed: reorderDataAndFindCellStartD", "particleSystem.cu", 223);


__cudaSafeCall(cudaUnbindTexture(oldPosTex), "particleSystem.cu", 226);
__cudaSafeCall(cudaUnbindTexture(oldVelTex), "particleSystem.cu", 227);


__cudaSafeCall(cudaGLUnmapBufferObject(vboOldPos), "particleSystem.cu", 230);
} }


extern "C" { void collide(uint vboOldPos, uint vboNewPos, float *
sortedPos, float *sortedVel, float *
oldVel, float *newVel, uint *
gridCounters, uint *
gridCells, uint *
particleHash, uint *
cellStart, uint
numParticles, uint
numCells, uint
maxParticlesPerCell)
{
auto float4 *oldPos; auto float4 *newPos;
__cudaSafeCall(cudaGLMapBufferObject((void **)(&oldPos), vboOldPos), "particleSystem.cu", 246);
__cudaSafeCall(cudaGLMapBufferObject((void **)(&newPos), vboNewPos), "particleSystem.cu", 247);
# 253 "particleSystem.cu"
__cudaSafeCall(cudaBindTexture(0, oldPosTex, sortedPos, numParticles * sizeof(float4)), "particleSystem.cu", 253);
__cudaSafeCall(cudaBindTexture(0, oldVelTex, sortedVel, numParticles * sizeof(float4)), "particleSystem.cu", 254);

__cudaSafeCall(cudaBindTexture(0, particleHashTex, particleHash, numParticles * sizeof(uint2)), "particleSystem.cu", 256);
__cudaSafeCall(cudaBindTexture(0, cellStartTex, cellStart, numCells * sizeof(uint)), "particleSystem.cu", 257);
# 270 "particleSystem.cu"
auto int numThreads; auto int numBlocks;
computeGridSize(numParticles, 64, numBlocks, numThreads);


cudaConfigureCall(numBlocks, numThreads) ? ((void)0) : collideD__entry((float4 *)newPos, (float4 *)newVel, (float4 *)sortedPos, (float4 *)sortedVel, (uint2 *)particleHash, cellStart);
# 287 "particleSystem.cu"
__cutilCheckMsg("Kernel execution failed", "particleSystem.cu", 287);

__cudaSafeCall(cudaGLUnmapBufferObject(vboNewPos), "particleSystem.cu", 289);
__cudaSafeCall(cudaGLUnmapBufferObject(vboOldPos), "particleSystem.cu", 290);


__cudaSafeCall(cudaUnbindTexture(oldPosTex), "particleSystem.cu", 293);
__cudaSafeCall(cudaUnbindTexture(oldVelTex), "particleSystem.cu", 294);


__cudaSafeCall(cudaUnbindTexture(particleHashTex), "particleSystem.cu", 297);
__cudaSafeCall(cudaUnbindTexture(cellStartTex), "particleSystem.cu", 298);
# 304 "particleSystem.cu"
} }

# 1 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_0000153d_00000000-6_particleSystem.fatbin.c" 1
# 1 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct __cudaFatDebugEntryRec {
    char* gpuProfileName;
    char* debug;
    struct __cudaFatDebugEntryRec *next;
    unsigned int size;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 146 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 160 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
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
    unsigned int characteristic;
} __cudaFatCudaBinary;
# 196 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 219 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 230 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_0000153d_00000000-6_particleSystem.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x6c706d61730a7d6eull,
0x616e090a7b207265ull,0x203d20202020656dull,0x6c6c654364697267ull,0x6574090a78655473ull,
0x203d2074696e7578ull,0x706d61730a7d0a35ull,0x6e090a7b2072656cull,0x3d20202020656d61ull,
0x756f436469726720ull,0x786554737265746eull,0x696e75786574090aull,0x0a7d0a34203d2074ull,
0x2072656c706d6173ull,0x20656d616e090a7bull,0x6c6563203d202020ull,0x655474726174536cull,
0x6e75786574090a78ull,0x7d0a33203d207469ull,0x72656c706d61730aull,0x656d616e090a7b20ull,
0x6170203d20202020ull,0x6148656c63697472ull,0x74090a7865546873ull,0x3d2074696e757865ull,
0x6d61730a7d0a3220ull,0x090a7b2072656c70ull,0x20202020656d616eull,0x6c6556646c6f203dull,
0x786574090a786554ull,0x31203d2074696e75ull,0x6c706d61730a7d0aull,0x616e090a7b207265ull,
0x203d20202020656dull,0x6554736f50646c6full,0x6e75786574090a78ull,0x7d0a30203d207469ull,
0x7b20636f6c65720aull,0x20656d616e09090aull,0x615264203d202020ull,0x6b636f6c42786964ull,
0x657309090a6d7553ull,0x203d20656d616e67ull,0x09090a636f6c6572ull,0x20206d756e676573ull,
0x6f09090a3431203dull,0x3d20207465736666ull,0x74796209090a3420ull,0x36203d2020207365ull,
0x6f6c65720a7d0a34ull,0x616e09090a7b2063ull,0x203d20202020656dull,0x7553786964615264ull,
0x6e67657309090a6dull,0x6572203d20656d61ull,0x657309090a636f6cull,0x203d20206d756e67ull,
0x66666f09090a3431ull,0x30203d2020746573ull,0x736574796209090aull,0x363931203d202020ull,
0x6f630a7d0a383036ull,0x090a7b207374736eull,0x202020656d616e09ull,0x6d61726170203d20ull,
0x6e67657309090a73ull,0x6f63203d20656d61ull,0x657309090a74736eull,0x203d20206d756e67ull,
0x7366666f09090a30ull,0x0a30203d20207465ull,0x2073657479620909ull,0x0a323131203d2020ull,
0x7b2065646f630a7dull,0x3d20656d616e090aull,0x64707531315a5f20ull,0x4464697247657461ull,
0x3474616f6c663650ull,0x6c090a5f31536a50ull,0x0a30203d206d656dull,0x203d206d656d7309ull,
0x20676572090a3834ull,0x6162090a37203d20ull,0x090a30203d202072ull,0x0a7b2074736e6f63ull,
0x616e676573090909ull,0x6e6f63203d20656dull,0x65730909090a7473ull,0x203d20206d756e67ull,
0x66666f0909090a31ull,0x30203d2020746573ull,0x657479620909090aull,0x0a34203d20202073ull,
0x0a7b206d656d0909ull,0x3865337830090909ull,0x090a203030303030ull,0x62090a7d090a7d09ull,
0x7b2065646f636e69ull,0x303061783009090aull,0x7830203530633430ull,0x3038373030323430ull,
0x3430303061783020ull,0x3430783020393032ull,0x0a20303837303032ull,0x3230303478300909ull,
0x3078302035303230ull,0x2030383738313030ull,0x3030303030617830ull,0x3034307830203130ull,
0x090a203038373030ull,0x3030303032783009ull,0x3430783020353132ull,0x3020303837303030ull,
0x3061303430303378ull,0x3031346378302035ull,0x09090a2030383730ull,0x3038303030317830ull,
0x6537307830203130ull,0x7830203330303038ull,0x3131386330303032ull,0x3430323430783020ull,
0x3009090a20303837ull,0x6631303339306278ull,0x3830303678302064ull,0x6478302038633734ull,
0x2031303830653030ull,0x3730306130387830ull,0x783009090a203038ull,0x3131363230303031ull,
0x6330303432783020ull,0x3162783020303837ull,0x3020393034303030ull,0x3837303430383078ull,
0x31783009090a2030ull,0x2064303030303030ull,0x3663303434327830ull,0x3830637830203038ull,
0x7830203930343030ull,0x3038363030343030ull,0x3063783009090a20ull,0x3020313136303339ull,
0x3836303030303078ull,0x3030303978302030ull,0x6378302063303830ull,0x2063303430333030ull,
0x333031783009090aull,0x7830203930303866ull,0x6666666666666630ull,0x3030303061783020ull,
0x6363783020643036ull,0x0a20303837343230ull,0x3030313278300909ull,0x3078302031313430ull,
0x2030383730333034ull,0x3630303030617830ull,0x3063387830203930ull,0x090a203038373436ull,
0x3034303033783009ull,0x3461783020643034ull,0x3020303837303030ull,0x3030383030303178ull,
0x3865373078302039ull,0x09090a2033303030ull,0x3630623830347830ull,0x3030307830203131ull,
0x7830203038373831ull,0x6466353032393062ull,0x3438303036783020ull,0x3009090a20386337ull,
0x3032303030316278ull,0x3330383078302039ull,0x3178302030383763ull,0x2064303432303030ull,
0x3763303034327830ull,0x783009090a203038ull,0x3530383061383034ull,0x3831303030783020ull,
0x3031783020303837ull,0x3020643030303030ull,0x3836633034343278ull,0x63783009090a2030ull,
0x2039303430303830ull,0x3630303430307830ull,0x3930637830203038ull,0x7830206430363032ull,
0x3038363030303030ull,0x3039783009090a20ull,0x3020633036303030ull,0x3034303330306378ull,
0x6633303178302063ull,0x3078302039303038ull,0x2066666666666666ull,0x303061783009090aull,
0x7830206430363030ull,0x3038373432306363ull,0x3030303132783020ull,0x3430783020313134ull,
0x0a20303837633230ull,0x3030306178300909ull,0x3878302064303630ull,0x2030383734363063ull,
0x3038303030317830ull,0x6537307830203930ull,0x090a203330303038ull,0x3034303033783009ull,
0x3461783020643036ull,0x3020303837303030ull,0x6635303139306278ull,0x3830303678302064ull,
0x09090a2038633734ull,0x3630613830367830ull,0x3030387830203530ull,0x7830203038373430ull,
0x3130303030303162ull,0x3833303830783020ull,0x3009090a20303837ull,0x3032323030303178ull,
0x3030343278302039ull,0x3178302030383763ull,0x2039303030303030ull,0x3663303434327830ull,
0x783009090a203038ull,0x3130303030383063ull,0x3030343030783020ull,0x3063783020303836ull,
0x3020393034303139ull,0x3836303030303078ull,0x39783009090a2030ull,0x2038303430303030ull,
0x3030323030637830ull,0x3330317830203030ull,0x7830203930303866ull,0x6666666666666630ull,
0x3061783009090a20ull,0x3020313030303030ull,0x3837343230636378ull,0x3030313278302030ull,
0x3078302064303430ull,0x2030383738323034ull,0x303061783009090aull,0x7830203130303030ull,
0x3038373436306338ull,0x3033303033783020ull,0x3461783020313030ull,0x0a20303837303030ull,
0x3030303278300909ull,0x3078302031303230ull,0x2030383730303034ull,0x6132303030317830ull,
0x3034327830203530ull,0x090a203038376330ull,0x3032303033783009ull,0x3463783020643030ull,
0x3020303837303031ull,0x3130303330303478ull,0x3030303078302039ull,0x09090a2030383730ull,
0x3038313030317830ull,0x3030307830203131ull,0x7830203330303030ull,0x6430636330303032ull,
0x6330323430783020ull,0x3009090a20303837ull,0x3132303230303678ull,0x3130303078302039ull,
0x6478302030383738ull,0x2064303630343037ull,0x3730306330657830ull,0x783009090a203038ull,
0x3930343030303132ull,0x3435303430783020ull,0x3033783020303837ull,0x3020313163303031ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2039303630323030ull,0x3730303034617830ull,
0x3030367830203038ull,0x7830203130303032ull,0x3038373031303030ull,0x3032783009090a20ull,
0x3020313030303030ull,0x3837383030343078ull,0x3230303378302030ull,0x6378302031303030ull,
0x2030383730303134ull,0x303032783009090aull,0x7830203130306430ull,0x3038373030323430ull,
0x3065303064783020ull,0x3061783020353130ull,0x0a20313837303063ull,0x646f630a7d0a7d09ull,
0x6d616e090a7b2065ull,0x35325a5f203d2065ull,0x6464417869646152ull,0x417374657366664full,
0x6c6666756853646eull,0x5679654b32315065ull,0x7269615065756c61ull,0x090a696a6a5f3053ull,
0x30203d206d656d6cull,0x3d206d656d73090aull,0x676572090a383420ull,0x090a3532203d2020ull,
0x31203d2020726162ull,0x2074736e6f63090aull,0x6765730909090a7bull,0x63203d20656d616eull,
0x0909090a74736e6full,0x20206d756e676573ull,0x6f0909090a31203dull,0x3d20207465736666ull,
0x79620909090a3020ull,0x203d202020736574ull,0x6d656d09090a3038ull,0x78300909090a7b20ull,
0x6530303030303030ull,0x3030303030783020ull,0x3030783020663030ull,0x3020313030303030ull,
0x3030303030303078ull,0x78300909090a2033ull,0x3033303030303030ull,0x6666666666783020ull,
0x3030783020636666ull,0x3020666633303030ull,0x3030303130303078ull,0x78300909090a2030ull,
0x3230303030303030ull,0x3030303030783020ull,0x3030783020343030ull,0x3020353030303030ull,
0x3030303030303078ull,0x78300909090a2036ull,0x3730303030303030ull,0x3030303030783020ull,
0x3030783020383030ull,0x3020393030303030ull,0x3030303030303078ull,0x78300909090a2061ull,
0x6230303030303030ull,0x3030303030783020ull,0x3030783020633030ull,0x3020643030303030ull,
0x6630303030303078ull,0x090a7d09090a2066ull,0x6f636e6962090a7dull,0x3009090a7b206564ull,
0x3130303030306178ull,0x3030343078302031ull,0x3078302030633730ull,0x2031303831383030ull,
0x3530663334657830ull,0x783009090a203030ull,0x6466393030383033ull,0x3031343436783020ull,
0x3033783020386337ull,0x3020313038303230ull,0x3035303031346378ull,0x32783009090a2030ull,
0x2031303030303031ull,0x3534303837307830ull,0x3030647830203030ull,0x7830203130303065ull,
0x3030353030633038ull,0x3030783009090a20ull,0x3020353038303230ull,0x3035303030306378ull,
0x3830343078302030ull,0x6578302031306131ull,0x2030303530303234ull,0x313638783009090aull,
0x7830203330656666ull,0x3030303030303030ull,0x3031383033783020ull,0x6336783020313038ull,
0x0a20306337633034ull,0x3130303178300909ull,0x3078302064303038ull,0x2033303030303030ull,
0x3030323830647830ull,0x3434307830203930ull,0x090a203038373030ull,0x3030343032783009ull,
0x3430783020313038ull,0x3020303837633030ull,0x3130306337303378ull,0x3130633678302035ull,
0x09090a2030383738ull,0x6130303030617830ull,0x3063327830203531ull,0x7830203038373431ull,
0x6466623032303064ull,0x3030303430783020ull,0x3009090a20386437ull,0x3030303230303078ull,
0x3030306378302035ull,0x6478302030383730ull,0x2035303036303234ull,0x3631303030327830ull,
0x783009090a203038ull,0x3130303030303431ull,0x6430303434783020ull,0x3031783020303836ull,
0x3020313038663030ull,0x3031643330363078ull,0x38783009090a2030ull,0x2033306566663136ull,
0x3030303030307830ull,0x3030307830203030ull,0x7830203530383032ull,0x3038363030303063ull,
0x3464783009090a20ull,0x3020393030363032ull,0x3836303030303278ull,0x3030383278302030ull,
0x3078302031303063ull,0x2030383630303234ull,0x303430783009090aull,0x7830203130383138ull,
0x3038363030323465ull,0x6666313638783020ull,0x3030783020333065ull,0x0a20303030303030ull,
0x3130303378300909ull,0x6378302064303630ull,0x2030383730303134ull,0x3730313830337830ull,
0x3463367830206466ull,0x090a203864376330ull,0x6330303031783009ull,0x3030783020333030ull,
0x3020303832313030ull,0x3038303230303378ull,0x3031346578302039ull,0x09090a2030383730ull,
0x6334303030617830ull,0x3234307830203130ull,0x7830203038373030ull,0x3531383033383064ull,
0x3030343430783020ull,0x3009090a20303837ull,0x3138303538306478ull,0x3034343078302039ull,
0x3678302030383730ull,0x2064303430343830ull,0x3730303430367830ull,0x783009090a203038ull,
0x3930613030303032ull,0x3831303430783020ull,0x3033783020303837ull,0x3020643036303230ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2064663530363830ull,0x3730313463367830ull,
0x3030327830203863ull,0x7830203931613030ull,0x3038376330303430ull,0x3061783009090a20ull,
0x3020333030333430ull,0x3030303030303078ull,0x3430303178302030ull,0x3078302033303033ull,
0x2030383230303030ull,0x303032783009090aull,0x7830206430343863ull,0x3330303030303030ull,
0x3032303033783020ull,0x3463783020353163ull,0x0a20303837303031ull,0x3230303078300909ull,
0x6378302035303630ull,0x2030383730303030ull,0x6130303031327830ull,0x3837307830206431ull,
0x090a203038373030ull,0x3065303064783009ull,0x3038783020353265ull,0x3020303837303063ull,
0x3063303030306178ull,0x3131343078302064ull,0x09090a2030383734ull,0x3038623230317830ull,
0x6161307830203531ull,0x7830206261616161ull,0x3132633062303034ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3265306130303678ull,0x3230303078302031ull,0x3378302030633730ull,
0x2039323031303130ull,0x3730303134637830ull,0x783009090a203038ull,0x3132303130313033ull,
0x3030313465783020ull,0x3036783020303837ull,0x3020646664306130ull,0x6437383230303078ull,
0x32783009090a2038ull,0x2031323031303031ull,0x3863313434307830ull,0x3030367830203038ull,
0x7830206430653062ull,0x3038373132306330ull,0x3033783009090a20ull,0x3020643036306230ull,
0x3837303031636578ull,0x6337303378302030ull,0x3678302064666430ull,0x2038633734303063ull,
0x303033783009090aull,0x7830203531363830ull,0x3330303030303030ull,0x3030303031783020ull,
0x3430783020643061ull,0x0a20303832633330ull,0x3230303078300909ull,0x6378302039303630ull,
0x2030383730303030ull,0x3036303238647830ull,0x3030327830203930ull,0x090a203038373030ull,
0x6330303832783009ull,0x3430783020643030ull,0x3020303837343232ull,0x3034383030303278ull,
0x3030303078302039ull,0x09090a2037303030ull,0x3038303036307830ull,0x3234657830203130ull,
0x7830203038376330ull,0x6466353036383033ull,0x6330346336783020ull,0x3009090a20386337ull,
0x3163383030303278ull,0x3030303078302039ull,0x3278302033633030ull,0x2064316538303030ull,
0x3330303030307830ull,0x783009090a203330ull,0x3330306332303031ull,0x3030303030783020ull,
0x3066783020303832ull,0x3020313030303030ull,0x3030303030306578ull,0x38783009090a2032ull,
0x2033306566663136ull,0x3030303030307830ull,0x3136387830203030ull,0x7830203330656666ull,
0x3030303030303030ull,0x3031783009090a20ull,0x3020393032313030ull,0x3837633030343478ull,
0x6232303178302030ull,0x3078302039313038ull,0x2062616161616161ull,0x303034783009090aull,
0x7830206430383064ull,0x3038373030303030ull,0x3063303036783020ull,0x3030783020643061ull,
0x0a20306337633030ull,0x3031303378300909ull,0x6378302035313630ull,0x2030383730303134ull,
0x3630303130337830ull,0x3134657830206430ull,0x090a203038373030ull,0x3063303036783009ull,
0x3030783020646639ull,0x3020386437343130ull,0x3036303030313278ull,0x3134343078302064ull,
0x09090a2030383863ull,0x3030323030337830ull,0x3134637830206431ull,0x7830203038373030ull,
0x3531383034303033ull,0x3030313465783020ull,0x3009090a20303837ull,0x3061306430303678ull,
0x3030633078302031ull,0x3278302030383764ull,0x2064306130303030ull,0x3763313034307830ull,
0x783009090a203038ull,0x3930303037303033ull,0x3030313465783020ull,0x3034783020303837ull,
0x3020313038303730ull,0x3837303030303078ull,0x36783009090a2030ull,0x2031306130363030ull,
0x3730303030307830ull,0x3130337830203038ull,0x7830203130303030ull,0x3038373030313463ull,
0x3036783009090a20ull,0x3020643038303630ull,0x3837303030303078ull,0x3138306478302030ull,
0x3078302031303830ull,0x2030383730303434ull,0x303032783009090aull,0x7830203831363832ull,
0x3031303833303032ull,0x3036303033783020ull,0x3436783020646639ull,0x0a20386337383130ull,
0x3030303378300909ull,0x3078302033303030ull,0x2030383230303030ull,0x3030633730337830ull,
0x3063367830206431ull,0x090a203038373830ull,0x3032383033783009ull,0x6336783020313230ull,
0x3020303837383034ull,0x3230303838303378ull,0x3034633678302035ull,0x09090a2030383738ull,
0x3030333830337830ull,0x3463367830203932ull,0x7830203038373830ull,0x6432303039383033ull,
0x3830346336783020ull,0x3009090a20303837ull,0x3330306138303378ull,0x3034633678302031ull,
0x3378302030383738ull,0x2035333030623830ull,0x3738303463367830ull,0x783009090a203038ull,
0x3933303063383033ull,0x3830346336783020ull,0x3033783020303837ull,0x3020643330306438ull,
0x3837383034633678ull,0x33783009090a2030ull,0x2031343030653830ull,0x3738303463367830ull,
0x3830337830203038ull,0x7830203534303066ull,0x3038373830346336ull,0x3033783009090a20ull,
0x3020393430303039ull,0x3837383034633678ull,0x3139303378302030ull,0x3678302064343030ull,
0x2030383738303463ull,0x393033783009090aull,0x7830206430303032ull,0x3038373830346336ull,
0x3030383033783020ull,0x6336783020393030ull,0x0a20303837383034ull,0x3138303378300909ull,
0x3678302031303030ull,0x2030383738303463ull,0x6530323830647830ull,0x3434307830206431ull,
0x090a203038373030ull,0x3132383064783009ull,0x3430783020313230ull,0x3020303837303034ull,
0x3232313238306478ull,0x3034343078302035ull,0x09090a2030383730ull,0x3431323830647830ull,
0x3434307830203932ull,0x7830203038373030ull,0x6432363132383064ull,0x3030343430783020ull,
0x3009090a20303837ull,0x3338313238306478ull,0x3034343078302031ull,0x6478302030383730ull,
0x2035336131323830ull,0x3730303434307830ull,0x783009090a203038ull,0x3933633132383064ull,
0x3030343430783020ull,0x3064783020303837ull,0x3020643365313238ull,0x3837303034343078ull,
0x64783009090a2030ull,0x2031343032323830ull,0x3730303434307830ull,0x3830647830203038ull,
0x7830203534323232ull,0x3038373030343430ull,0x3064783009090a20ull,0x3020393434323238ull,
0x3837303034343078ull,0x3238306478302030ull,0x3078302064343632ull,0x2030383730303434ull,
0x383064783009090aull,0x7830203135363032ull,0x3038373030343430ull,0x3032383064783020ull,
0x3430783020353534ull,0x0a20303837303034ull,0x3238306478300909ull,0x3078302039353030ull,
0x2030383730303434ull,0x3064343030337830ull,0x3234367830203130ull,0x090a203064373031ull,
0x3030303061783009ull,0x6330783020646631ull,0x3020386337343130ull,0x3038303330303378ull,
0x3031346378302039ull,0x09090a2030383631ull,0x3863303030327830ull,0x3234307830203930ull,
0x7830203038363930ull,0x3130343065303064ull,0x3130383038783020ull,0x3009090a20303836ull,
0x3038663030303178ull,0x3330343078302031ull,0x3178302030303164ull,0x2064353866303030ull,
0x3763333036307830ull,0x783009090a203038ull,0x6435343030303031ull,0x6330343432783020ull,
0x3064783020303832ull,0x3020646666323730ull,0x6337303030343078ull,0x61783009090a2038ull,
0x2033303032393030ull,0x3030303030307830ull,0x3030317830203030ull,0x7830203330303239ull,
0x3030313030303030ull,0x3031783009090a20ull,0x3020393034313030ull,0x3837633030343478ull,
0x3230303378302030ull,0x6578302039303030ull,0x2030383730303034ull,0x393064783009090aull,
0x7830203930343033ull,0x3038373030343430ull,0x3032303033783020ull,0x3463783020393034ull,
0x0a20303837303031ull,0x3030303278300909ull,0x3078302039306130ull,0x2030383738303034ull,
0x3430323030307830ull,0x3030637830203530ull,0x090a203038373030ull,0x6631303532783009ull,
0x3030783020393038ull,0x3020333030303030ull,0x3638643330343378ull,0x3033346378302031ull,
0x09090a2030383730ull,0x3831303034307830ull,0x3234657830203130ull,0x7830203038373830ull,
0x3830303830303031ull,0x3832303031783020ull,0x3009090a20633032ull,0x3663633030303278ull,
0x3632343078302031ull,0x6478302030383730ull,0x2039303033653030ull,0x3730303830617830ull,
0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,0x3638783020323030ull,
0x3020333065666631ull,0x3030303030303078ull,0x64783009090a2030ull,0x2064666632383030ull,
0x3730303034307830ull,0x3030617830203863ull,0x7830203330303361ull,0x3030303030303030ull,
0x3031783009090a20ull,0x3020333030336130ull,0x3031303030303078ull,0x3030303178302030ull,
0x3478302039303431ull,0x2030383763303034ull,0x303033783009090aull,0x7830203930303032ull,
0x3038373030303465ull,0x3033393064783020ull,0x3430783020393034ull,0x0a20303837303034ull,
0x3230303378300909ull,0x6378302039303430ull,0x2030383730303134ull,0x6130303030327830ull,
0x3034307830203930ull,0x090a203038373830ull,0x3032303030783009ull,0x3063783020353034ull,
0x3020303837303030ull,0x3038663130353278ull,0x3030303078302039ull,0x09090a2033303030ull,
0x3864333034337830ull,0x3334637830203136ull,0x7830203038373030ull,0x3130383130303430ull,
0x3830323465783020ull,0x3009090a20303837ull,0x3030383030303178ull,0x3230303178302038ull,
0x3278302063303238ull,0x2031366363303030ull,0x3730363234307830ull,0x783009090a203038ull,
0x3930303365303064ull,0x3030383061783020ull,0x3066783020303837ull,0x3020313030303030ull,
0x3030303030306578ull,0x38783009090a2032ull,0x2033306566663136ull,0x3030303030307830ull,
0x3030647830203030ull,0x7830206466663239ull,0x3863373030303430ull,0x3061783009090a20ull,
0x3020333030346230ull,0x3030303030303078ull,0x6230303178302030ull,0x3078302033303034ull,
0x2030303130303030ull,0x303031783009090aull,0x7830203930343130ull,0x3038376330303434ull,
0x3032303033783020ull,0x3465783020393030ull,0x0a20303837303030ull,0x3339306478300909ull,
0x3078302039303430ull,0x2030383730303434ull,0x3430323030337830ull,0x3134637830203930ull,
0x090a203038373030ull,0x3030303032783009ull,0x3430783020393061ull,0x3020303837383030ull,
0x3034303230303078ull,0x3030306378302035ull,0x09090a2030383730ull,0x3866313035327830ull,
0x3030307830203930ull,0x7830203330303030ull,0x3136386433303433ull,0x3030333463783020ull,
0x3009090a20303837ull,0x3038313030343078ull,0x3032346578302031ull,0x3178302030383738ull,
0x2038303038303030ull,0x3238323030317830ull,0x783009090a206330ull,0x3136636330303032ull,
0x3036323430783020ull,0x3064783020303837ull,0x3020393030336530ull,0x3837303038306178ull,
0x66783009090a2030ull,0x2031303030303030ull,0x3030303030657830ull,0x3136387830203230ull,
0x7830203330656666ull,0x3030303030303030ull,0x3064783009090a20ull,0x3020646666326130ull,
0x6337303030343078ull,0x6330306178302038ull,0x3078302033303035ull,0x2030303030303030ull,
0x303031783009090aull,0x7830203330303563ull,0x3030313030303030ull,0x3130303031783020ull,
0x3434783020393034ull,0x0a20303837633030ull,0x3230303378300909ull,0x6578302039303030ull,
0x2030383730303034ull,0x3430333930647830ull,0x3434307830203930ull,0x090a203038373030ull,
0x3032303033783009ull,0x3463783020393034ull,0x3020303837303031ull,0x3061303030303278ull,
0x3030343078302039ull,0x09090a2030383738ull,0x3430323030307830ull,0x3030637830203530ull,
0x7830203038373030ull,0x3930386631303532ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3638643330343378ull,0x3033346378302031ull,0x3078302030383730ull,0x2031303831303034ull,
0x3738303234657830ull,0x783009090a203038ull,0x3830303830303031ull,0x3832303031783020ull,
0x3032783020633032ull,0x3020313663633030ull,0x3837303632343078ull,0x64783009090a2030ull,
0x2039303033653030ull,0x3730303830617830ull,0x3030667830203038ull,0x7830203130303030ull,
0x3230303030303065ull,0x3638783009090a20ull,0x3020333065666631ull,0x3030303030303078ull,
0x6230306478302030ull,0x3078302064666632ull,0x2038633730303034ull,0x303061783009090aull,
0x7830203330303664ull,0x3030303030303030ull,0x3664303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303178300909ull,0x3478302039303431ull,0x2030383763303034ull,
0x3030323030337830ull,0x3034657830203930ull,0x090a203038373030ull,0x3033393064783009ull,
0x3430783020393034ull,0x3020303837303034ull,0x3034303230303378ull,0x3031346378302039ull,
0x09090a2030383730ull,0x6130303030327830ull,0x3034307830203930ull,0x7830203038373830ull,
0x3530343032303030ull,0x3030303063783020ull,0x3009090a20303837ull,0x3038663130353278ull,
0x3030303078302039ull,0x3378302033303030ull,0x2031363864333034ull,0x3730303334637830ull,
0x783009090a203038ull,0x3130383130303430ull,0x3830323465783020ull,0x3031783020303837ull,
0x3020383030383030ull,0x3032383230303178ull,0x32783009090a2063ull,0x2031366363303030ull,
0x3730363234307830ull,0x3030647830203038ull,0x7830203930303365ull,0x3038373030383061ull,
0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,0x6631363878302032ull,
0x3078302033306566ull,0x2030303030303030ull,0x303064783009090aull,0x7830206466663263ull,
0x3863373030303430ull,0x3765303061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x6530303178300909ull,0x3078302033303037ull,0x2030303130303030ull,0x3431303030317830ull,
0x3034347830203930ull,0x090a203038376330ull,0x3032303033783009ull,0x3465783020393030ull,
0x3020303837303030ull,0x3034303339306478ull,0x3034343078302039ull,0x09090a2030383730ull,
0x3430323030337830ull,0x3134637830203930ull,0x7830203038373030ull,0x3930613030303032ull,
0x3830303430783020ull,0x3009090a20303837ull,0x3034303230303078ull,0x3030306378302035ull,
0x3278302030383730ull,0x2039303866313035ull,0x3030303030307830ull,0x783009090a203330ull,
0x3136386433303433ull,0x3030333463783020ull,0x3430783020303837ull,0x3020313038313030ull,
0x3837383032346578ull,0x31783009090a2030ull,0x2038303038303030ull,0x3238323030317830ull,
0x3030327830206330ull,0x7830203136636330ull,0x3038373036323430ull,0x3064783009090a20ull,
0x3020393030336530ull,0x3837303038306178ull,0x3030306678302030ull,0x6578302031303030ull,
0x2032303030303030ull,0x313638783009090aull,0x7830203330656666ull,0x3030303030303030ull,
0x3264303064783020ull,0x3430783020646666ull,0x0a20386337303030ull,0x6630306178300909ull,
0x3078302033303038ull,0x2030303030303030ull,0x3038663030317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3130303031783009ull,0x3434783020393034ull,0x3020303837633030ull,
0x3030303230303378ull,0x3030346578302039ull,0x09090a2030383730ull,0x3430333930647830ull,
0x3434307830203930ull,0x7830203038373030ull,0x3930343032303033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3061303030303278ull,0x3030343078302039ull,0x3078302030383738ull,
0x2035303430323030ull,0x3730303030637830ull,0x783009090a203038ull,0x3930386631303532ull,
0x3030303030783020ull,0x3433783020333030ull,0x3020313638643330ull,0x3837303033346378ull,
0x30783009090a2030ull,0x2031303831303034ull,0x3738303234657830ull,0x3030317830203038ull,
0x7830203830303830ull,0x6330323832303031ull,0x3032783009090a20ull,0x3020313663633030ull,
0x3837303632343078ull,0x6530306478302030ull,0x6178302039303033ull,0x2030383730303830ull,
0x303066783009090aull,0x7830203130303030ull,0x3230303030303065ull,0x6666313638783020ull,
0x3030783020333065ull,0x0a20303030303030ull,0x6530306478300909ull,0x3078302064666632ull,
0x2038633730303034ull,0x3039303130617830ull,0x3030307830203330ull,0x090a203030303030ull,
0x3930313031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3034313030303178ull,
0x3030343478302039ull,0x09090a2030383763ull,0x3030323030337830ull,0x3034657830203930ull,
0x7830203038373030ull,0x3930343033393064ull,0x3030343430783020ull,0x3009090a20303837ull,
0x3034303230303378ull,0x3031346378302039ull,0x3278302030383730ull,0x2039306130303030ull,
0x3738303034307830ull,0x783009090a203038ull,0x3530343032303030ull,0x3030303063783020ull,
0x3532783020303837ull,0x3020393038663130ull,0x3030303030303078ull,0x33783009090a2033ull,
0x2031363864333034ull,0x3730303334637830ull,0x3034307830203038ull,0x7830203130383130ull,
0x3038373830323465ull,0x3031783009090a20ull,0x3020383030383030ull,0x3032383230303178ull,
0x3030303278302063ull,0x3078302031366363ull,0x2030383730363234ull,0x303064783009090aull,
0x7830203930303365ull,0x3038373030383061ull,0x3030303066783020ull,0x3065783020313030ull,
0x0a20323030303030ull,0x6631363878300909ull,0x3078302033306566ull,0x2030303030303030ull,
0x6632663030647830ull,0x3034307830206466ull,0x090a203863373030ull,0x6131313061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030613131303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3431303030317830ull,0x3034347830203930ull,0x7830203038376330ull,
0x3930303032303033ull,0x3030303465783020ull,0x3009090a20303837ull,0x3034303339306478ull,
0x3034343078302039ull,0x3378302030383730ull,0x2039303430323030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3930613030303032ull,0x3830303430783020ull,0x3030783020303837ull,
0x3020353034303230ull,0x3837303030306378ull,0x32783009090a2030ull,0x2039303866313035ull,
0x3030303030307830ull,0x3034337830203330ull,0x7830203136386433ull,0x3038373030333463ull,
0x3430783009090a20ull,0x3020313038313030ull,0x3837383032346578ull,0x3030303178302030ull,
0x3178302038303038ull,0x2063303238323030ull,0x303032783009090aull,0x7830203136636330ull,
0x3038373036323430ull,0x3365303064783020ull,0x3061783020393030ull,0x0a20303837303038ull,
0x3030306678300909ull,0x6578302031303030ull,0x2032303030303030ull,0x6566663136387830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3230313064783009ull,0x3430783020646666ull,
0x3020386337303030ull,0x3030623231306178ull,0x3030303078302033ull,0x09090a2030303030ull,
0x3062323130317830ull,0x3030307830203330ull,0x7830203030313030ull,0x3930343130303031ull,
0x6330303434783020ull,0x3009090a20303837ull,0x3030303230303378ull,0x3030346578302039ull,
0x6478302030383730ull,0x2039303430333930ull,0x3730303434307830ull,0x783009090a203038ull,
0x3930343032303033ull,0x3030313463783020ull,0x3032783020303837ull,0x3020393061303030ull,
0x3837383030343078ull,0x30783009090a2030ull,0x2035303430323030ull,0x3730303030637830ull,
0x3035327830203038ull,0x7830203930386631ull,0x3330303030303030ull,0x3433783009090a20ull,
0x3020313638643330ull,0x3837303033346378ull,0x3030343078302030ull,0x6578302031303831ull,
0x2030383738303234ull,0x303031783009090aull,0x7830203830303830ull,0x6330323832303031ull,
0x6330303032783020ull,0x3430783020313663ull,0x0a20303837303632ull,0x6530306478300909ull,
0x6178302039303033ull,0x2030383730303830ull,0x3030303030667830ull,0x3030657830203130ull,
0x090a203230303030ull,0x6666313638783009ull,0x3030783020333065ull,0x3020303030303030ull,
0x6666323131306478ull,0x3030343078302064ull,0x09090a2038633730ull,0x3063333130617830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3330306333313031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3034313030303178ull,0x3030343478302039ull,0x3378302030383763ull,
0x2039303030323030ull,0x3730303034657830ull,0x783009090a203038ull,0x3930343033393064ull,
0x3030343430783020ull,0x3033783020303837ull,0x3020393034303230ull,0x3837303031346378ull,
0x32783009090a2030ull,0x2039306130303030ull,0x3738303034307830ull,0x3030307830203038ull,
0x7830203530343032ull,0x3038373030303063ull,0x3532783009090a20ull,0x3020393038663130ull,
0x3030303030303078ull,0x3330343378302033ull,0x6378302031363864ull,0x2030383730303334ull,
0x303430783009090aull,0x7830203130383130ull,0x3038373830323465ull,0x3830303031783020ull,
0x3031783020383030ull,0x0a20633032383230ull,0x3030303278300909ull,0x3078302031366363ull,
0x2030383730363234ull,0x3033653030647830ull,0x3830617830203930ull,0x090a203038373030ull,
0x3030303066783009ull,0x3065783020313030ull,0x3020323030303030ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x6632323130647830ull,0x3034307830206466ull,
0x7830203863373030ull,0x3330306434313061ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3030643431303178ull,0x3030303078302033ull,0x3178302030303130ull,0x2039303431303030ull,
0x3763303034347830ull,0x783009090a203038ull,0x3930303032303033ull,0x3030303465783020ull,
0x3064783020303837ull,0x3020393034303339ull,0x3837303034343078ull,0x33783009090a2030ull,
0x2039303430323030ull,0x3730303134637830ull,0x3030327830203038ull,0x7830203930613030ull,
0x3038373830303430ull,0x3030783009090a20ull,0x3020353034303230ull,0x3837303030306378ull,
0x3130353278302030ull,0x3078302039303866ull,0x2033303030303030ull,0x303433783009090aull,
0x7830203136386433ull,0x3038373030333463ull,0x3130303430783020ull,0x3465783020313038ull,
0x0a20303837383032ull,0x3030303178300909ull,0x3178302038303038ull,0x2063303238323030ull,
0x6363303030327830ull,0x3234307830203136ull,0x090a203038373036ull,0x3365303064783009ull,
0x3061783020393030ull,0x3020303837303038ull,0x3030303030306678ull,0x3030306578302031ull,
0x09090a2032303030ull,0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,
0x6466663233313064ull,0x3030303430783020ull,0x3009090a20386337ull,0x3030653531306178ull,
0x3030303078302033ull,0x3178302030303030ull,0x2033303065353130ull,0x3130303030307830ull,
0x783009090a203030ull,0x3930343130303031ull,0x6330303434783020ull,0x3033783020303837ull,
0x3020393030303230ull,0x3837303030346578ull,0x64783009090a2030ull,0x2039303430333930ull,
0x3730303434307830ull,0x3030337830203038ull,0x7830203930343032ull,0x3038373030313463ull,
0x3032783009090a20ull,0x3020393061303030ull,0x3837383030343078ull,0x3230303078302030ull,
0x6378302035303430ull,0x2030383730303030ull,0x303532783009090aull,0x7830203930386631ull,
0x3330303030303030ull,0x6433303433783020ull,0x3463783020313638ull,0x0a20303837303033ull,
0x3030343078300909ull,0x6578302031303831ull,0x2030383738303234ull,0x3038303030317830ull,
0x3030317830203830ull,0x090a206330323832ull,0x6330303032783009ull,0x3430783020313663ull,
0x3020303837303632ull,0x3030336530306478ull,0x3038306178302039ull,0x09090a2030383730ull,
0x3030303030667830ull,0x3030657830203130ull,0x7830203230303030ull,0x3330656666313638ull,
0x3030303030783020ull,0x3009090a20303030ull,0x6666323431306478ull,0x3030343078302064ull,
0x6178302038633730ull,0x2033303066363130ull,0x3030303030307830ull,0x783009090a203030ull,
0x3330306636313031ull,0x3030303030783020ull,0x3031783020303031ull,0x3020393034313030ull,
0x3837633030343478ull,0x33783009090a2030ull,0x2039303030323030ull,0x3730303034657830ull,
0x3930647830203038ull,0x7830203930343033ull,0x3038373030343430ull,0x3033783009090a20ull,
0x3020393034303230ull,0x3837303031346378ull,0x3030303278302030ull,0x3078302039306130ull,
0x2030383738303034ull,0x303030783009090aull,0x7830203530343032ull,0x3038373030303063ull,
0x6631303532783020ull,0x3030783020393038ull,0x0a20333030303030ull,0x3330343378300909ull,
0x6378302031363864ull,0x2030383730303334ull,0x3831303034307830ull,0x3234657830203130ull,
0x090a203038373830ull,0x3830303031783009ull,0x3031783020383030ull,0x3020633032383230ull,
0x3663633030303278ull,0x3632343078302031ull,0x09090a2030383730ull,0x3033653030647830ull,
0x3830617830203930ull,0x7830203038373030ull,0x3130303030303066ull,0x3030303065783020ull,
0x3009090a20323030ull,0x3065666631363878ull,0x3030303078302033ull,0x6478302030303030ull,
0x2064666632353130ull,0x3730303034307830ull,0x783009090a203863ull,0x3330303038313061ull,
0x3030303030783020ull,0x3031783020303030ull,0x3020333030303831ull,0x3031303030303078ull,
0x31783009090a2030ull,0x2039303431303030ull,0x3763303034347830ull,0x3030337830203038ull,
0x7830203930303032ull,0x3038373030303465ull,0x3064783009090a20ull,0x3020393034303339ull,
0x3837303034343078ull,0x3230303378302030ull,0x6378302039303430ull,0x2030383730303134ull,
0x303032783009090aull,0x7830203930613030ull,0x3038373830303430ull,0x3032303030783020ull,
0x3063783020353034ull,0x0a20303837303030ull,0x3130353278300909ull,0x3078302039303866ull,
0x2033303030303030ull,0x3864333034337830ull,0x3334637830203136ull,0x090a203038373030ull,
0x3130303430783009ull,0x3465783020313038ull,0x3020303837383032ull,0x3030383030303178ull,
0x3230303178302038ull,0x09090a2063303238ull,0x6363303030327830ull,0x3234307830203136ull,
0x7830203038373036ull,0x3930303365303064ull,0x3030383061783020ull,0x3009090a20303837ull,
0x3030303030306678ull,0x3030306578302031ull,0x3878302032303030ull,0x2033306566663136ull,
0x3030303030307830ull,0x783009090a203030ull,0x6466663236313064ull,0x3030303430783020ull,
0x3061783020386337ull,0x3020333030313931ull,0x3030303030303078ull,0x31783009090a2030ull,
0x2033303031393130ull,0x3130303030307830ull,0x3030317830203030ull,0x7830203930343130ull,
0x3038376330303434ull,0x3033783009090a20ull,0x3020393030303230ull,0x3837303030346578ull,
0x3339306478302030ull,0x3078302039303430ull,0x2030383730303434ull,0x303033783009090aull,
0x7830203930343032ull,0x3038373030313463ull,0x3030303032783020ull,0x3430783020393061ull,
0x0a20303837383030ull,0x3230303078300909ull,0x6378302035303430ull,0x2030383730303030ull,
0x3866313035327830ull,0x3030307830206430ull,0x090a203330303030ull,0x6433303433783009ull,
0x3463783020393038ull,0x3020303837303033ull,0x3038313030343078ull,0x3032346578302031ull,
0x09090a2030383763ull,0x3238303030317830ull,0x3031327830206330ull,0x7830206335636532ull,
0x3930303030303031ull,0x6333303430783020ull,0x3009090a20303837ull,0x3065326530306478ull,
0x3038306178302039ull,0x6678302030383730ull,0x2031303030303030ull,0x3030303030657830ull,
0x783009090a203230ull,0x3330656666313638ull,0x3030303030783020ull,0x3032783020303030ull,
0x3020313138383031ull,0x3030303030303078ull,0x33783009090a2033ull,0x2064663930363030ull,
0x3734303034367830ull,0x3030317830203863ull,0x7830203330306237ull,0x3038323030303030ull,
0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,0x0a7d0a7d090a2031ull,
0x090a7b2065646f63ull,0x5f203d20656d616eull,0x64696c6c6f63385aull,0x616f6c6636504465ull,
0x5f30535f30533474ull,0x6e697535505f3053ull,0x6d6c090a6a503274ull,0x090a30203d206d65ull,
0x36203d206d656d73ull,0x2020676572090a34ull,0x6162090a3633203dull,0x090a30203d202072ull,
0x0a7b2074736e6f63ull,0x616e676573090909ull,0x6e6f63203d20656dull,0x65730909090a7473ull,
0x203d20206d756e67ull,0x66666f0909090a31ull,0x30203d2020746573ull,0x657479620909090aull,
0x3231203d20202073ull,0x7b206d656d09090aull,0x666678300909090aull,0x3020666666666666ull,
0x3030303030303078ull,0x3038653378302032ull,0x09090a2030303030ull,0x6962090a7d090a7dull,
0x0a7b2065646f636eull,0x3030306178300909ull,0x3078302035306334ull,0x2030383730303234ull,
0x3234303030617830ull,0x3234307830203930ull,0x090a203038373030ull,0x3032303034783009ull,
0x3030783020353032ull,0x3020303837383130ull,0x3030303030306178ull,0x3030343078302031ull,
0x09090a2030383730ull,0x3230303030327830ull,0x3034307830203930ull,0x7830203038373030ull,
0x3130303830303031ull,0x3038653730783020ull,0x3009090a20333030ull,0x3234303030303178ull,
0x3330363078302031ull,0x6278302030383763ull,0x2064663130313930ull,0x3734383030367830ull,
0x783009090a203863ull,0x3131343030303031ull,0x6333303430783020ull,0x3766783020303837ull,
0x3020313230303030ull,0x3837343030303078ull,0x66783009090a2030ull,0x2031313230323037ull,
0x3763303030307830ull,0x3030317830203438ull,0x7830203130323230ull,0x3038376330303432ull,
0x3031783009090a20ull,0x3020633032393230ull,0x3534393030303178ull,0x3230303178302034ull,
0x3178302063346138ull,0x2038356338303030ull,0x303031783009090aull,0x7830203035653832ull,
0x3430303165633062ull,0x3030303031783020ull,0x3432783020313034ull,0x0a20303836633034ull,
0x3238306378300909ull,0x3078302035303230ull,0x2030383630303430ull,0x3030313930637830ull,
0x3030307830203130ull,0x090a203038363030ull,0x3030303039783009ull,0x3063783020303030ull,
0x3020343032303030ull,0x3030383030303178ull,0x3865373078302031ull,0x09090a2033303030ull,
0x3230303030617830ull,0x3063637830203931ull,0x7830203038373432ull,0x6466313032393062ull,
0x3438303036783020ull,0x3009090a20386337ull,0x3036303030316278ull,0x3330383078302035ull,
0x3178302030383763ull,0x2035313432303030ull,0x3763303034327830ull,0x783009090a203038ull,
0x3130633030303061ull,0x3436306338783020ull,0x3031783020303837ull,0x3020353134303030ull,
0x3836633034343278ull,0x63783009090a2030ull,0x2035303230323830ull,0x3630303430307830ull,
0x3930637830203038ull,0x7830203531613032ull,0x3038363030303030ull,0x3039783009090a20ull,
0x3020343161303030ull,0x3132303530306378ull,0x3030303178302034ull,0x3078302035303038ull,
0x2033303030386537ull,0x303061783009090aull,0x7830203931613030ull,0x3038373432306363ull,
0x3033393062783020ull,0x3036783020646633ull,0x0a20386337343830ull,0x3030316278300909ull,
0x3078302035306132ull,0x2030383730343038ull,0x3632303030317830ull,0x3034327830203531ull,
0x090a203038376330ull,0x3030303061783009ull,0x6338783020643563ull,0x3020303837343630ull,
0x3134303030303178ull,0x3034343278302035ull,0x09090a2030383663ull,0x3230323830637830ull,
0x3430307830203530ull,0x7830203038363030ull,0x3531613033393063ull,0x3030303030783020ull,
0x3009090a20303836ull,0x3161303030303978ull,0x3530306378302034ull,0x3278302034303230ull,
0x2035313038663330ull,0x6666666666307830ull,0x783009090a206666ull,0x3536303832303032ull,
0x3030303030783020ull,0x3031783020333030ull,0x3020393630386633ull,0x6666666666663078ull,
0x61783009090a2066ull,0x2031303230303030ull,0x3734323063637830ull,0x3030317830203038ull,
0x7830206436386630ull,0x3038376333303430ull,0x3031783009090a20ull,0x3020313738663030ull,
0x3837633330363078ull,0x3030303178302030ull,0x3078302035373866ull,0x2030383763333034ull,
0x303061783009090aull,0x7830203136303030ull,0x3038373436306338ull,0x3866333031783020ull,
0x6630783020393730ull,0x0a20666666666666ull,0x3030303178300909ull,0x3078302039316130ull,
0x2030383763333036ull,0x3063393030617830ull,0x3030307830203330ull,0x090a203030303030ull,
0x3063373033783009ull,0x6336783020646664ull,0x3020386337343030ull,0x3030373930306178ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3035343030317830ull,0x3030307830203330ull,
0x7830203038323030ull,0x3130303866333031ull,0x6666666630783020ull,0x3009090a20666666ull,
0x3030303030313278ull,0x3230343078302031ull,0x3378302030383738ull,0x2064666430303030ull,
0x3730313034367830ull,0x783009090a203863ull,0x3330303534303031ull,0x3030303030783020ull,
0x3032783020303832ull,0x3020353065323030ull,0x6337383730343078ull,0x31783009090a2030ull,
0x2033303035343030ull,0x3930303030307830ull,0x3330317830203038ull,0x7830206431303866ull,
0x6666666666666630ull,0x3132783009090a20ull,0x3020643165303030ull,0x3837633230343078ull,
0x3730303378302030ull,0x3678302064663330ull,0x2038633730313034ull,0x303031783009090aull,
0x7830203330303534ull,0x3038323030303030ull,0x3330303032783020ull,0x3430783020353230ull,
0x0a20306337383630ull,0x3430303178300909ull,0x3078302033303035ull,0x2030383930303030ull,
0x3038663330317830ull,0x6666307830203932ull,0x090a206666666666ull,0x3130303132783009ull,
0x3430783020393234ull,0x3020303837303330ull,0x6633316130303378ull,0x3030343678302064ull,
0x09090a2038633763ull,0x3039343030317830ull,0x3030307830203330ull,0x7830203038323030ull,
0x6432386630303031ull,0x6333303430783020ull,0x3009090a20303837ull,0x3138663030303178ull,
0x3330363078302064ull,0x3178302030383763ull,0x2035323866303030ull,0x3763333034307830ull,
0x783009090a203038ull,0x3330303739303031ull,0x3030303030783020ull,0x3033783020303837ull,
0x3020643132303730ull,0x3837303030346178ull,0x33783009090a2030ull,0x2035303231613030ull,
0x3730303034617830ull,0x6330347830203038ull,0x7830206331653861ull,0x3430323862633034ull,
0x3036783009090a20ull,0x3020353032306138ull,0x3837633130303878ull,0x3030303378302030ull,
0x6178302031306330ull,0x2030383730303034ull,0x303032783009090aull,0x7830203832323830ull,
0x3030343932303031ull,0x3639303061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x3630336678300909ull,0x3078302031303630ull,0x2030383730303030ull,0x3130303830337830ull,
0x3434367830206466ull,0x090a203863373431ull,0x3735303031783009ull,0x3030783020333030ull,
0x3020303832303030ull,0x3238663030303178ull,0x3330343078302064ull,0x09090a2030383763ull,
0x3866303030317830ull,0x3036307830206431ull,0x7830203038376333ull,0x3532386630303031ull,
0x6333303430783020ull,0x3009090a20303837ull,0x3030363930303178ull,0x3030303078302033ull,
0x3378302030383730ull,0x2064663966353930ull,0x3738303034367830ull,0x783009090a203863ull,
0x6432386630303031ull,0x6333303630783020ull,0x3031783020303837ull,0x3020643138663030ull,
0x3837633330343078ull,0x31783009090a2030ull,0x2035323866303030ull,0x3763333036307830ull,
0x3030317830203038ull,0x7830203330303639ull,0x3038323030303030ull,0x3034783009090a20ull,
0x3020333030363930ull,0x3030303030303078ull,0x3030303178302030ull,0x3078302064333030ull,
0x2030383763333034ull,0x303031783009090aull,0x7830203530653130ull,0x3038376333303630ull,
0x3034303366783020ull,0x3030783020353034ull,0x0a20343837303030ull,0x3130303378300909ull,
0x3678302064663531ull,0x2038633734313034ull,0x3030303030357830ull,0x3030307830203330ull,
0x090a203038323030ull,0x3132303033783009ull,0x3436783020646666ull,0x3020386337383030ull,
0x3030313930306178ull,0x3030303078302033ull,0x09090a2030303030ull,0x3031393030317830ull,
0x3030307830203330ull,0x7830203038323030ull,0x3134653130303031ull,0x6333303430783020ull,
0x3009090a20303837ull,0x3030663830306178ull,0x3030303078302033ull,0x3178302030303030ull,
0x2031336531303030ull,0x3763333036307830ull,0x783009090a203038ull,0x3134303030303766ull,
0x3430303030783020ull,0x3766783020343837ull,0x3020313332303230ull,0x3837343030303078ull,
0x62783009090a2034ull,0x2034303232333430ull,0x3032383430627830ull,0x3030637830203034ull,
0x7830206337323031ull,0x3434343235353062ull,0x3065783009090a20ull,0x3020393430323031ull,
0x3837633730303078ull,0x3131306578302030ull,0x3078302064373232ull,0x2030383738343030ull,
0x303031783009090aull,0x7830203934323130ull,0x3038376330303432ull,0x3330303039783020ull,
0x3034783020643765ull,0x0a20303837303030ull,0x3938306278300909ull,0x3978302038343432ull,
0x2063376533303030ull,0x3532663130627830ull,0x3030367830206466ull,0x090a203863373031ull,
0x3130303031783009ull,0x3430783020643863ull,0x3020303837633330ull,0x3030633830303178ull,
0x3030303078302033ull,0x09090a2030303130ull,0x6533303030397830ull,0x3130627830203438ull,
0x7830203834656232ull,0x3833613133353062ull,0x3431303063783020ull,0x3009090a20343332ull,
0x3838313434306278ull,0x3132306378302030ull,0x6378302063373032ull,0x2038386331643030ull,
0x3634363530627830ull,0x783009090a203033ull,0x3538323431313063ull,0x3030303030783020ull,
0x3065783020303837ull,0x3020643865333032ull,0x3837383830303078ull,0x63783009090a2030ull,
0x2039383432363930ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203934323463ull,
0x3038376338303030ull,0x3063783009090a20ull,0x3020643865333232ull,0x3837303030303078ull,
0x3231306578302030ull,0x3078302064376533ull,0x2030383730383034ull,0x393065783009090aull,
0x7830203138303437ull,0x3038376338303830ull,0x3338393065783020ull,0x3030783020643765ull,
0x0a20303837303830ull,0x3939306578300909ull,0x3078302031343032ull,0x2030383763373030ull,
0x3234323230637830ull,0x3030307830206437ull,0x090a203038373030ull,0x3137393065783009ull,
0x3830783020643738ull,0x3020303837633730ull,0x3334323132306578ull,0x3330343078302031ull,
0x09090a2030383730ull,0x6131323230637830ull,0x3030307830203138ull,0x7830203038373030ull,
0x3533343264303065ull,0x3833303430783020ull,0x3009090a20303837ull,0x3363313739306578ull,
0x3830383078302039ull,0x6578302030383730ull,0x2035336131383930ull,0x3738333030307830ull,
0x783009090a203038ull,0x3133383138393065ull,0x6337303030783020ull,0x3065783020303837ull,
0x3020353032303939ull,0x3837343330303078ull,0x65783009090a2030ull,0x2031333232393930ull,
0x3730333030307830ull,0x3030317830203038ull,0x7830203330306638ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020313338663030ull,0x3837633330363078ull,0x3030303178302030ull,
0x3078302035303866ull,0x2030383763333034ull,0x303031783009090aull,0x7830203134386630ull,
0x3038376333303630ull,0x3130303062783020ull,0x3030783020643238ull,0x0a20323837633230ull,
0x3930306278300909ull,0x6278302034323032ull,0x2063313230373030ull,0x3030303031327830ull,
0x3034307830203530ull,0x090a203238373435ull,0x3931303032783009ull,0x3030783020643365ull,
0x3020333030303030ull,0x6666313130303378ull,0x3130343678302064ull,0x09090a2038633734ull,
0x3065353030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x3330303030303035ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030303030306678ull,0x3030306578302031ull,
0x6278302032303030ull,0x2064363631303030ull,0x3763363030307830ull,0x783009090a203238ull,
0x3931633831303032ull,0x3030303030783020ull,0x3033783020333030ull,0x3020646664303931ull,
0x6337343130633678ull,0x62783009090a2038ull,0x2034373231643130ull,0x6530633130627830ull,
0x3030317830203037ull,0x7830203330303233ull,0x3038323030303030ull,0x3066783009090a20ull,
0x3020313030303030ull,0x3030303030306578ull,0x3130303278302032ull,0x3078302039376362ull,
0x2033303030303030ull,0x383033783009090aull,0x7830206466643331ull,0x3863373431346336ull,
0x3033303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3130303278300909ull,
0x3078302039363462ull,0x2033303030303030ull,0x3533313830337830ull,0x3463367830206466ull,
0x090a203863373431ull,0x6632303031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3036383138306278ull,0x3038306278302034ull,0x09090a2063303039ull,0x3230313030637830ull,
0x3830627830203030ull,0x7830203431616132ull,0x3130363033303065ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3161303530306578ull,0x3030303078302039ull,0x3178302030383730ull,
0x2031303830303030ull,0x3763303034327830ull,0x783009090a203038ull,0x3931633030303039ull,
0x3030303034783020ull,0x3062783020303837ull,0x3020303030303938ull,0x3163303030303978ull,
0x62783009090a2038ull,0x2064663130363030ull,0x3730313030367830ull,0x3030617830203863ull,
0x7830203330303563ull,0x3030303030303030ull,0x3031783009090a20ull,0x3020333030326330ull,
0x3031303030303078ull,0x3030303978302030ull,0x6378302063316330ull,0x2034306530313030ull,
0x303063783009090aull,0x7830206330363037ull,0x3032323033313063ull,0x3830303062783020ull,
0x3063783020383163ull,0x0a20303065303530ull,0x3430306578300909ull,0x3078302035313630ull,
0x2030383730323063ull,0x6330363930637830ull,0x3030307830203931ull,0x090a203038373030ull,
0x3036313065783009ull,0x3430783020353130ull,0x3020303837343130ull,0x3136303630306378ull,
0x3630306378302063ull,0x09090a2030323230ull,0x3030363030637830ull,0x3030307830203931ull,
0x7830203038373030ull,0x3532613030303065ull,0x3835303030783020ull,0x3009090a20303837ull,
0x3036303530306578ull,0x3130303078302064ull,0x6578302030383730ull,0x2035316130313030ull,
0x3763343030307830ull,0x783009090a203038ull,0x3130383037393065ull,0x6331303030783020ull,
0x3065783020303837ull,0x3020353036323739ull,0x3837303230303078ull,0x65783009090a2030ull,
0x2039316332373930ull,0x3738313030307830ull,0x3930657830203038ull,0x7830203130363038ull,
0x3038373030303030ull,0x3065783009090a20ull,0x3020353061303839ull,0x3837343030303078ull,
0x3839306578302030ull,0x3078302064303231ull,0x2030383738313030ull,0x303061783009090aull,
0x7830203130303030ull,0x3038373430303465ull,0x3030303061783020ull,0x3465783020353032ull,
0x0a20303837343030ull,0x3030306178300909ull,0x6578302064303630ull,0x2030383734303034ull,
0x3035633030317830ull,0x3030307830203330ull,0x090a203038373030ull,0x6630303031783009ull,
0x3430783020643038ull,0x3020303837633330ull,0x3038663030303178ull,0x3330363078302035ull,
0x09090a2030383763ull,0x3866303030317830ull,0x3034307830203130ull,0x7830203038376333ull,
0x3930343033303033ull,0x3030313463783020ull,0x3009090a20323837ull,0x3136306231306278ull,
0x6431306278302038ull,0x6278302063303030ull,0x2034313230633130ull,0x3866323031327830ull,
0x783009090a203030ull,0x3130303065303064ull,0x3030383038783020ull,0x3062783020303837ull,
0x3020383163323630ull,0x3038303330306278ull,0x62783009090a2038ull,0x2064303632303030ull,
0x3734313030307830ull,0x3030337830203038ull,0x7830203130323034ull,0x3038373030313463ull,
0x3032783009090a20ull,0x3020313063633030ull,0x3837303032343078ull,0x6530306478302030ull,
0x6178302039303030ull,0x2030383730306330ull,0x303032783009090aull,0x7830203530303834ull,
0x3330303030303030ull,0x3065303064783020ull,0x3061783020643032ull,0x0a20303837303063ull,
0x3830303278300909ull,0x3078302035303038ull,0x2033303030303030ull,0x3230653030647830ull,
0x6330617830203931ull,0x090a203038373030ull,0x3863303032783009ull,0x3030783020313030ull,
0x3020333030303030ull,0x3530306530306478ull,0x3063306178302031ull,0x7d090a2031383730ull,
0x2065646f630a7d0aull,0x20656d616e090a7bull,0x657238325a5f203dull,0x746144726564726full,
0x646e6946646e4161ull,0x726174536c6c6543ull,0x746e697535504474ull,0x74616f6c66365032ull,
0x535f32535f325334ull,0x6d6c090a6a505f32ull,0x090a30203d206d65ull,0x31203d206d656d73ull,
0x676572090a343031ull,0x090a3031203d2020ull,0x31203d2020726162ull,0x2074736e6f63090aull,
0x6765730909090a7bull,0x63203d20656d616eull,0x0909090a74736e6full,0x20206d756e676573ull,
0x6f0909090a31203dull,0x3d20207465736666ull,0x79620909090a3020ull,0x203d202020736574ull,
0x206d656d09090a38ull,0x6678300909090a7bull,0x2038666666666666ull,0x6666666666667830ull,
0x0a7d09090a206666ull,0x636e6962090a7d09ull,0x09090a7b2065646full,0x6334303030617830ull,
0x3234307830203530ull,0x7830203038373030ull,0x3930323430303061ull,0x3030323430783020ull,
0x3009090a20303837ull,0x3032303230303478ull,0x3130303078302035ull,0x6178302030383738ull,
0x2031303030303030ull,0x3730303034307830ull,0x783009090a203038ull,0x3132303030303032ull,
0x3430303430783020ull,0x3033783020303837ull,0x3020353030313330ull,0x3837303031346378ull,
0x33783009090a2030ull,0x2064663131633730ull,0x3730313063367830ull,0x3030307830203863ull,
0x7830203530303032ull,0x3038373030303063ull,0x3032783009090a20ull,0x3020393038633030ull,
0x3837343032343078ull,0x6337303378302030ull,0x3678302064663130ull,0x2038633238303034ull,
0x303064783009090aull,0x7830203130343065ull,0x3038373030383038ull,0x3030303031783020ull,
0x3630783020313132ull,0x0a20303837633330ull,0x3030343078300909ull,0x6578302031303232ull,
0x2030383730303234ull,0x3430303031327830ull,0x3434307830203530ull,0x090a203038363030ull,
0x3065303064783009ull,0x3038783020393032ull,0x3020303836303038ull,0x3030323030303078ull,
0x3032346578302031ull,0x09090a2030383638ull,0x6566663136387830ull,0x3030307830203330ull,
0x7830203030303030ull,0x6466313163373033ull,0x3830306336783020ull,0x3009090a20386337ull,
0x3030393130306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303036313030ull,
0x3230303030307830ull,0x783009090a203038ull,0x6466316530303433ull,0x3830323436783020ull,
0x3031783020386337ull,0x3020333030393130ull,0x3832303030303078ull,0x33783009090a2030ull,
0x2031303030323030ull,0x3730303134637830ull,0x3030327830203038ull,0x7830203130636430ull,
0x3038373030323430ull,0x3064783009090a20ull,0x3020313230306530ull,0x3837303063306178ull,
0x3030303178302030ull,0x3078302031303830ull,0x2032383763333034ull,0x303166783009090aull,
0x7830203030313030ull,0x3031333032303166ull,0x6666313638783020ull,0x3030783020333065ull,
0x0a20303030303030ull,0x3430303378300909ull,0x6378302031323031ull,0x2030383730303134ull,
0x3464303030327830ull,0x3234307830203532ull,0x090a203038373032ull,0x3165303064783009ull,
0x3061783020313032ull,0x3020303837303061ull,0x3038643030303278ull,0x3232343078302031ull,
0x09090a2030383730ull,0x3030653030647830ull,0x6130617830203131ull,0x090a203138373030ull,
0x65646f630a7d0a7dull,0x656d616e090a7b20ull,0x6e69395a5f203d20ull,0x5065746172676574ull,
0x533474616f6c6636ull,0x5f30535f30535f30ull,0x206d656d6c090a66ull,0x656d73090a30203dull,
0x090a3436203d206dull,0x31203d2020676572ull,0x2020726162090a34ull,0x6e6962090a30203dull,
0x090a7b2065646f63ull,0x3430303061783009ull,0x3430783020353063ull,0x3020303837303032ull,
0x3032343030306178ull,0x3032343078302039ull,0x09090a2030383730ull,0x3230323030347830ull,
0x3030307830203530ull,0x7830203038373831ull,0x3130303030303061ull,0x3030303430783020ull,
0x3009090a20303837ull,0x3032303030303278ull,0x3030343078302031ull,0x3378302030383730ull,
0x2031323030343030ull,0x3730303134637830ull,0x783009090a203038ull,0x3130346430303032ull,
0x3032323430783020ull,0x3032783020303837ull,0x3020353230643030ull,0x3837303232343078ull,
0x64783009090a2030ull,0x2031303030653030ull,0x3730306130387830ull,0x3030647830203038ull,
0x7830203131323165ull,0x3038373030613038ull,0x3031783009090a20ull,0x3020353230383030ull,
0x3030303866333078ull,0x3030316278302033ull,0x3078302064323231ull,0x2030383734323038ull,
0x383065783009090aull,0x7830203130386435ull,0x3038373030323030ull,0x6436383065783020ull,
0x3030783020353038ull,0x0a20303837343032ull,0x3738306578300909ull,0x3078302039303864ull,
0x2030383738303230ull,0x6538323030317830ull,0x3830637830203433ull,0x090a206331303038ull,
0x3038383063783009ull,0x3063783020383232ull,0x3020343234303838ull,0x3336303030303178ull,
0x3330343078302031ull,0x09090a2030383763ull,0x3864373030657830ull,0x3230307830203130ull,
0x7830203038373031ull,0x3930386461303065ull,0x3431323030783020ull,0x3009090a20303837ull,
0x3138643930306578ull,0x3132303078302031ull,0x6278302030383738ull,0x2064663731303030ull,
0x3734303030367830ull,0x783009090a203863ull,0x3430343832303031ull,0x3830303031783020ull,
0x3063783020633038ull,0x3020643165306139ull,0x3836303030303078ull,0x31783009090a2030ull,
0x2031303631303030ull,0x3663333036307830ull,0x3030317830203038ull,0x7830203531303830ull,
0x3330303038666230ull,0x3162783009090a20ull,0x3020353161303030ull,0x3837343230303078ull,
0x3030306278302030ull,0x3678302064666230ull,0x2038633730313030ull,0x393063783009090aull,
0x7830206431653061ull,0x3038363030303030ull,0x3030303031783020ull,0x3430783020313061ull,
0x0a20303836633330ull,0x3130306278300909ull,0x3678302064663731ull,0x2038633734303030ull,
0x3431613930637830ull,0x3030307830203932ull,0x090a203038363030ull,0x3130303031783009ull,
0x3630783020393036ull,0x3020303836633330ull,0x6662303230306278ull,0x3130303678302064ull,
0x09090a2038633730ull,0x3431613930637830ull,0x3030307830203932ull,0x7830203038363030ull,
0x3930613030303031ull,0x6333303430783020ull,0x3009090a20303836ull,0x6637313330306278ull,
0x3030303678302064ull,0x6378302038633734ull,0x2035323231613930ull,0x3630303030307830ull,
0x783009090a203038ull,0x3131363130303031ull,0x6333303630783020ull,0x3062783020303836ull,
0x3020646662303430ull,0x6337303130303678ull,0x63783009090a2038ull,0x2035323231613930ull,
0x3630303030307830ull,0x3030317830203038ull,0x7830203131613030ull,0x3038366333303430ull,
0x3031783009090a20ull,0x3020343034383230ull,0x3038383030303178ull,0x3230303178302038ull,
0x3278302063306139ull,0x2030313865383031ull,0x303064783009090aull,0x7830203130383065ull,
0x3038373030613061ull,0x3930303031783020ull,0x3031783020343034ull,0x0a20383032393230ull,
0x3030303178300909ull,0x3278302063303839ull,0x2030316365383031ull,0x6530303030317830ull,
0x3034307830203130ull,0x090a203038376333ull,0x3065303064783009ull,0x3061783020313038ull,
0x0a20313837303061ull,0x646f630a7d0a7d09ull,0x6d616e090a7b2065ull,0x34315a5f203d2065ull,
0x6572507869646152ull,0x0a766d7553786966ull,0x203d206d656d6c09ull,0x206d656d73090a30ull,
0x6572090a3631203dull,0x0a3031203d202067ull,0x203d202072616209ull,0x74736e6f63090a31ull,
0x65730909090a7b20ull,0x203d20656d616e67ull,0x09090a74736e6f63ull,0x206d756e67657309ull,
0x0909090a31203d20ull,0x202074657366666full,0x620909090a30203dull,0x3d20202073657479ull,
0x656d09090a303220ull,0x300909090a7b206dull,0x3130303030303078ull,0x3030303078302031ull,
0x6678302066303030ull,0x2030386666666666ull,0x6330303030307830ull,0x300909090a206662ull,
0x6666666666666678ull,0x090a7d09090a2063ull,0x6f636e6962090a7dull,0x3009090a7b206564ull,
0x3030386232303178ull,0x6161613078302035ull,0x6178302062616161ull,0x2031313030303030ull,
0x3730303034307830ull,0x783009090a203038ull,0x3130363038303034ull,0x3030303030783020ull,
0x3033783020303837ull,0x3020393030303031ull,0x3837303031346378ull,0x33783009090a2030ull,
0x2031303030303130ull,0x3730303134657830ull,0x3030367830203038ull,0x7830206466353038ull,
0x3864373830303030ull,0x3036783009090a20ull,0x3020646635303830ull,0x6337383030303078ull,
0x3030306178302038ull,0x3078302039316334ull,0x2030383730303234ull,0x343033783009090aull,
0x7830203530303030ull,0x3038373166313430ull,0x3030343033783020ull,0x3430783020313030ull,
0x0a20303837306631ull,0x3430303378300909ull,0x6378302064306330ull,0x2030383730303134ull,
0x3230373030337830ull,0x3134657830203930ull,0x090a203038373030ull,0x3037303033783009ull,
0x3465783020353030ull,0x3020303837303031ull,0x3034303030303278ull,0x3030343078302039ull,
0x09090a2030383763ull,0x3030323830647830ull,0x3434307830203130ull,0x7830203038373030ull,
0x3530323036303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3034303730303378ull,
0x3031346378302064ull,0x3378302030383730ull,0x2039303430363030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3130303030303032ull,0x3430303430783020ull,0x3033783020303837ull,
0x3020353163306230ull,0x3837303031346378ull,0x33783009090a2030ull,0x2064316330613030ull,
0x3730303134637830ull,0x3030327830203038ull,0x7830203430363832ull,0x3030383830343032ull,
0x3032783009090a20ull,0x3020343161383730ull,0x3030383130303278ull,0x3138306478302038ull,
0x3078302031303830ull,0x2030383730303434ull,0x303032783009090aull,0x7830206430613830ull,
0x3363303030303030ull,0x3034303033783020ull,0x3465783020353038ull,0x0a20303837303031ull,
0x3230303378300909ull,0x3678302064663730ull,0x2038633763303034ull,0x3230303830367830ull,
0x3430367830203130ull,0x090a203038373030ull,0x3932303061783009ull,0x3030783020333030ull,
0x3020303030303030ull,0x3034303030303178ull,0x3330363078302035ull,0x09090a2030383763ull,
0x3039323030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x3132303834303032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3132303230303378ull,0x3031346378302064ull,
0x3078302030383730ull,0x2035303031323030ull,0x3730303030637830ull,0x783009090a203038ull,
0x6431653030303132ull,0x3030383730783020ull,0x3064783020303837ull,0x3020313265306530ull,
0x3837303063303878ull,0x32783009090a2030ull,0x2039303438303030ull,0x3030303030307830ull,
0x3036307830206630ull,0x7830203130383931ull,0x3038373032323465ull,0x3033783009090a20ull,
0x3020646637303230ull,0x6337303130343678ull,0x3030303278302038ull,0x3078302064316538ull,
0x2033333030303030ull,0x303031783009090aull,0x7830203330303332ull,0x3038323030303030ull,
0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,0x6631363878300909ull,
0x3078302033306566ull,0x2030303030303030ull,0x3830313530347830ull,0x3030307830206430ull,
0x090a203330303030ull,0x3830313032783009ull,0x3030783020643136ull,0x3020333030303030ull,
0x3065303330303378ull,0x3130343678302039ull,0x09090a2030643730ull,0x3530303030617830ull,
0x3063307830206466ull,0x7830203863373431ull,0x3330306133303061ull,0x3030303030783020ull,
0x3009090a20303030ull,0x3036303030303178ull,0x3330343078302039ull,0x3178302030383763ull,
0x2033303061333030ull,0x3131303030307830ull,0x783009090a203030ull,0x3132343834303032ull,
0x3030303030783020ull,0x3030783020333030ull,0x3020353030313230ull,0x3837303030306378ull,
0x31783009090a2030ull,0x2031323866303030ull,0x3763333036307830ull,0x3034327830203038ull,
0x7830203132306330ull,0x3038373032323430ull,0x3032783009090a20ull,0x3020643036383130ull,
0x3030303030303078ull,0x3030363078302033ull,0x6578302031303230ull,0x2030383730323234ull,
0x303033783009090aull,0x7830206466373037ull,0x3864373431303436ull,0x3533303031783020ull,
0x3030783020333030ull,0x0a20303832313030ull,0x3030306678300909ull,0x6578302031303030ull,
0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,
0x3032303030783009ull,0x3063783020393034ull,0x3020303837303030ull,0x3234383430303278ull,
0x3030303078302031ull,0x09090a2033303030ull,0x3632303038317830ull,0x3034347830206430ull,
0x7830203038376330ull,0x3530303132303030ull,0x3030303063783020ull,0x3009090a20303837ull,
0x3038323030383078ull,0x3032346578302031ull,0x3878302030383763ull,0x2033306566663136ull,
0x3030303030307830ull,0x783009090a203030ull,0x3132303831313031ull,0x3030303030783020ull,
0x3032783020333030ull,0x3020643034303034ull,0x3837303230343078ull,0x32783009090a2030ull,
0x2035323638303130ull,0x3030303030307830ull,0x3730337830203330ull,0x7830206466333163ull,
0x3864376330306336ull,0x3030783009090a20ull,0x3020393036303230ull,0x3837303030306378ull,
0x3030383178302030ull,0x3478302064303832ull,0x2030303564303034ull,0x303031783009090aull,
0x7830206430386630ull,0x3038326433303430ull,0x6666313638783020ull,0x3030783020333065ull,
0x0a20303030303030ull,0x3030343278300909ull,0x3078302064303065ull,0x2030383763303234ull,
0x3032303034307830ull,0x3234657830203130ull,0x090a203038376330ull,0x6666313638783009ull,
0x3030783020333065ull,0x3020303030303030ull,0x3230313130303378ull,0x3031346378302031ull,
0x09090a2030383730ull,0x3131333830337830ull,0x3463367830206466ull,0x7830203864376330ull,
0x3330303334303031ull,0x3130303030783020ull,0x3009090a20303832ull,0x3034386633303278ull,
0x6666663078302064ull,0x3378302066666666ull,0x2064663730633730ull,0x3763303063367830ull,
0x783009090a203864ull,0x6430303030303430ull,0x3130303034783020ull,0x3132783020303035ull,
0x3020643036303030ull,0x3035313134343078ull,0x30783009090a2030ull,0x2039303630303030ull,
0x3531303030637830ull,0x3038317830203030ull,0x7830206430303030ull,0x3030356430303434ull,
0x3031783009090a20ull,0x3020643038663030ull,0x3832643330343078ull,0x3530306178302030ull,
0x3078302033303065ull,0x2030303030303030ull,0x303031783009090aull,0x7830203330306535ull,
0x3030313030303030ull,0x6330303432783020ull,0x3430783020313230ull,0x0a20303837633032ull,
0x3130303278300909ull,0x3078302039303438ull,0x2033303030303030ull,0x3230303036307830ull,
0x3234657830203130ull,0x090a203038373032ull,0x3037303033783009ull,0x3436783020646635ull,
0x3020386337343130ull,0x3030393530303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x3030303030667830ull,0x3030657830203130ull,0x7830203230303030ull,0x3330656666313638ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3063303830303378ull,0x3031346378302039ull,
0x3278302030383730ull,0x2039303438303030ull,0x3030303030307830ull,0x783009090a203331ull,
0x3930343034303033ull,0x3030313465783020ull,0x3033783020303837ull,0x3020643034303730ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2039303430363030ull,0x3730303134637830ull,
0x3030327830203038ull,0x7830203930363030ull,0x3038373830303430ull,0x3032783009090a20ull,
0x3020353032383130ull,0x3030303030303078ull,0x3130303378302033ull,0x3678302064663530ull,
0x2038633763303034ull,0x303061783009090aull,0x7830203330303437ull,0x3030303030303030ull,
0x3437303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3430303278300909ull,
0x3078302064303038ull,0x2033303030303030ull,0x3230323030337830ull,0x3134637830203130ull,
0x090a203038373030ull,0x3032303030783009ull,0x3063783020353036ull,0x3020303837303030ull,
0x3030303030313278ull,0x3038373078302064ull,0x09090a2030383730ull,0x3839313036317830ull,
0x3034347830203130ull,0x7830203038376330ull,0x3530323830303032ull,0x3030303030783020ull,
0x3009090a20663030ull,0x3036306530306478ull,0x3063306178302031ull,0x3378302030383730ull,
0x2064663530313030ull,0x3730313034367830ull,0x783009090a203863ull,0x6430363830303032ull,
0x3030303030783020ull,0x3031783020333330ull,0x3020333030653630ull,0x3832303030303078ull,
0x33783009090a2030ull,0x2064663930633730ull,0x3734313034367830ull,0x3030337830206163ull,
0x7830203330303030ull,0x3038323030303030ull,0x3033783009090a20ull,0x3020313063303230ull,
0x3837303031346378ull,0x3636306478302030ull,0x3278302035303831ull,0x2030383730303030ull,
0x303132783009090aull,0x7830203930303030ull,0x3038373430383730ull,0x3030303431783020ull,
0x3434783020313030ull,0x0a20303837633030ull,0x3230303378300909ull,0x6378302035306130ull,
0x2030383730303134ull,0x3430653030647830ull,0x6330617830203130ull,0x090a203038373030ull,
0x3830303031783009ull,0x3030783020393030ull,0x3020333030303030ull,0x3032303030313278ull,
0x3038373078302031ull,0x09090a2030383730ull,0x3030653030647830ull,0x6330617830203930ull,
0x090a203138373030ull,0x65646f630a7d0a7dull,0x656d616e090a7b20ull,0x6163395a5f203d20ull,
0x504468736148636cull,0x503474616f6c6636ull,0x090a32746e697535ull,0x30203d206d656d6cull,
0x3d206d656d73090aull,0x676572090a323320ull,0x62090a36203d2020ull,0x0a30203d20207261ull,
0x7b2074736e6f6309ull,0x6e6765730909090aull,0x6f63203d20656d61ull,0x730909090a74736eull,
0x3d20206d756e6765ull,0x666f0909090a3120ull,0x203d202074657366ull,0x7479620909090a30ull,
0x34203d2020207365ull,0x7b206d656d09090aull,0x653378300909090aull,0x0a20303030303038ull,
0x090a7d090a7d0909ull,0x2065646f636e6962ull,0x3061783009090a7bull,0x3020353063343030ull,
0x3837303032343078ull,0x3030306178302030ull,0x3078302039303234ull,0x2030383730303234ull,
0x303034783009090aull,0x7830203530323032ull,0x3038373831303030ull,0x3030303061783020ull,
0x3430783020313030ull,0x0a20303837303030ull,0x3030303278300909ull,0x3078302031313230ull,
0x2030383730303034ull,0x3830343030337830ull,0x3134637830203530ull,0x090a203038373030ull,
0x3830303031783009ull,0x3730783020313030ull,0x3020333030303865ull,0x3138633030303278ull,
0x3032343078302035ull,0x09090a2030383734ull,0x3130333930627830ull,0x3030367830206466ull,
0x7830203863373438ull,0x3130613065303064ull,0x3030613038783020ull,0x3009090a20303837ull,
0x3136323030303178ull,0x3030343278302035ull,0x6278302030383763ull,0x2039303430303031ull,
0x3730343038307830ull,0x783009090a203038ull,0x6430303030303031ull,0x6330343432783020ull,
0x3063783020303836ull,0x3020393034303038ull,0x3836303034303078ull,0x63783009090a2030ull,
0x2035313630333930ull,0x3630303030307830ull,0x3030397830203038ull,0x7830206330613030ull,
0x6330343033303063ull,0x3031783009090a20ull,0x3020393030386633ull,0x6666666666663078ull,
0x3030306178302066ull,0x6378302064303630ull,0x2030383734323063ull,0x303132783009090aull,
0x7830203531343030ull,0x3038373033303430ull,0x3030303061783020ull,0x6338783020393036ull,
0x0a20303837343630ull,0x3530303378300909ull,0x6178302064303430ull,0x2030383730303034ull,
0x3038303030317830ull,0x6537307830203930ull,0x090a203330303038ull,0x3062383034783009ull,
0x3030783020353136ull,0x3020303837383130ull,0x6635303239306278ull,0x3830303678302064ull,
0x09090a2038633734ull,0x3230303031627830ull,0x3038307830203930ull,0x7830203038376333ull,
0x6430343230303031ull,0x6330303432783020ull,0x3009090a20303837ull,0x3061306138303478ull,
0x3130303078302035ull,0x3178302030383738ull,0x2064303030303030ull,0x3663303434327830ull,
0x783009090a203038ull,0x3930343030383063ull,0x3030343030783020ull,0x3063783020303836ull,
0x3020643036303239ull,0x3836303030303078ull,0x39783009090a2030ull,0x2063303630303030ull,
0x3430333030637830ull,0x3330317830206330ull,0x7830203930303866ull,0x6666666666666630ull,
0x3061783009090a20ull,0x3020643036303030ull,0x3837343230636378ull,0x3030313278302030ull,
0x3078302035313430ull,0x2030383763323034ull,0x303061783009090aull,0x7830206430363030ull,
0x3038373436306338ull,0x3830303031783020ull,0x3730783020393030ull,0x0a20333030303865ull,
0x3530303378300909ull,0x6178302064303630ull,0x2030383730303034ull,0x3530313930627830ull,
0x3030367830206466ull,0x090a203863373438ull,0x3061383036783009ull,0x3038783020353036ull,
0x3020303837343030ull,0x3030303030316278ull,0x3330383078302031ull,0x09090a2030383738ull,
0x3232303030317830ull,0x3034327830203930ull,0x7830203038376330ull,0x3930303030303031ull,
0x6330343432783020ull,0x3009090a20303836ull,0x3030303038306378ull,0x3034303078302031ull,
0x6378302030383630ull,0x2039303430313930ull,0x3630303030307830ull,0x783009090a203038ull,
0x3830343030303039ull,0x3032303063783020ull,0x3031783020383030ull,0x3020313030386633ull,
0x6666666666663078ull,0x61783009090a2066ull,0x2039303430303030ull,0x3734323063637830ull,
0x3031327830203038ull,0x7830206430303030ull,0x3038373832303430ull,0x3061783009090a20ull,
0x3020313034303030ull,0x3837343630633878ull,0x3330303378302030ull,0x6178302031303030ull,
0x2030383730303034ull,0x303033783009090aull,0x7830203930383033ull,0x3038373030313463ull,
0x3830303032783020ull,0x3031783020303032ull,0x0a20343038383030ull,0x3030303278300909ull,
0x3078302039306363ull,0x2030383738303234ull,0x3430653030647830ull,0x3830617830203130ull,
0x090a203138373030ull,0x65646f630a7d0a7dull,0x656d616e090a7b20ull,0x6152385a5f203d20ull,
0x31506d7553786964ull,0x756c615679654b32ull,0x6a6a6a7269615065ull,0x3d206d656d6c090aull,
0x6d656d73090a3020ull,0x72090a3834203d20ull,0x3432203d20206765ull,0x3d2020726162090aull,
0x736e6f63090a3120ull,0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,
0x6d756e6765730909ull,0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,
0x2020207365747962ull,0x6d09090a3038203dull,0x0909090a7b206d65ull,0x3330303030307830ull,
0x3030307830206666ull,0x7830206630303030ull,0x3030303031303030ull,0x3030303030783020ull,
0x0909090a20313030ull,0x3030303030307830ull,0x3030307830203230ull,0x7830203330303030ull,
0x3430303030303030ull,0x3030303030783020ull,0x0909090a20353030ull,0x3030303030307830ull,
0x3030307830203630ull,0x7830203730303030ull,0x3830303030303030ull,0x3030303030783020ull,
0x0909090a20393030ull,0x3030303030307830ull,0x3030307830206130ull,0x7830206230303030ull,
0x6330303030303030ull,0x3030303030783020ull,0x0909090a20643030ull,0x3030303030307830ull,
0x3030307830206530ull,0x7830206666303030ull,0x3063303030303030ull,0x3030303030783020ull,
0x7d09090a20636633ull,0x6e6962090a7d090aull,0x090a7b2065646f63ull,0x3030303061783009ull,
0x3430783020353030ull,0x3020303837303030ull,0x6633303038303378ull,0x3134343678302064ull,
0x09090a2038633730ull,0x3062303030617830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3130323030303031ull,0x6333303630783020ull,0x3009090a20303837ull,0x3030623030303178ull,
0x3030303078302033ull,0x3278302030383230ull,0x2039303038633030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3530343032303030ull,0x3030303063783020ull,0x3032783020303837ull,
0x3020353032383030ull,0x3030303030303078ull,0x30783009090a2037ull,0x2031303038303036ull,
0x3730663334657830ull,0x3830337830203038ull,0x7830206466333030ull,0x3863376330343436ull,
0x3031783009090a20ull,0x3020333030373030ull,0x3832303030303078ull,0x3030306678302030ull,
0x6578302031303030ull,0x2032303030303030ull,0x313638783009090aull,0x7830203330656666ull,
0x3030303030303030ull,0x3030303031783020ull,0x3434783020393065ull,0x0a20303837633030ull,
0x6232303178300909ull,0x3078302035313038ull,0x2062616161616161ull,0x3830623030347830ull,
0x3030307830203530ull,0x090a203038373030ull,0x3061303036783009ull,0x3030783020353061ull,
0x3020306337343030ull,0x3132303031303378ull,0x3031346378302031ull,0x09090a2030383730ull,
0x3230303130337830ull,0x3134657830206430ull,0x7830203038373030ull,0x6466393061303036ull,
0x3031303030783020ull,0x3009090a20386437ull,0x3036303030313278ull,0x3034343078302064ull,
0x3378302030383838ull,0x2031313030343030ull,0x3730303134657830ull,0x783009090a203038ull,
0x3530633234303134ull,0x3030303030783020ull,0x3036783020333030ull,0x3020393061306230ull,
0x3837643030633078ull,0x32783009090a2030ull,0x2035313830303030ull,0x3734303034307830ull,
0x3030337830203038ull,0x7830206430343037ull,0x3038373030313465ull,0x3034783009090a20ull,
0x3020393063306230ull,0x3837303030303078ull,0x6130303678302030ull,0x3078302039306530ull,
0x2030383738303030ull,0x313033783009090aull,0x7830203930343030ull,0x3038373030313463ull,
0x3061303036783020ull,0x3030783020353163ull,0x0a20303837383030ull,0x3138306478300909ull,
0x3078302039303030ull,0x2030383730303434ull,0x6138333030327830ull,0x3030327830203831ull,
0x090a203431343835ull,0x3036303033783009ull,0x3436783020646662ull,0x3020386337383130ull,
0x3030653131306178ull,0x3030303078302033ull,0x09090a2030303030ull,0x3065313130317830ull,
0x3030307830203330ull,0x7830203038323030ull,0x6431343063373033ull,0x3830303436783020ull,
0x3009090a20303837ull,0x3234303338303378ull,0x3034343678302031ull,0x3378302030383738ull,
0x2035323430343830ull,0x3738303434367830ull,0x783009090a203038ull,0x3932343035383033ull,
0x3830343436783020ull,0x3033783020303837ull,0x3020643234303638ull,0x3837383034343678ull,
0x33783009090a2030ull,0x2031333430373830ull,0x3738303434367830ull,0x3830337830203038ull,
0x7830203533343038ull,0x3038373830343436ull,0x3033783009090a20ull,0x3020393334303938ull,
0x3837383034343678ull,0x6138303378302030ull,0x3678302064333430ull,0x2030383738303434ull,
0x383033783009090aull,0x7830203134343062ull,0x3038373830343436ull,0x3063383033783020ull,
0x3436783020353434ull,0x0a20303837383034ull,0x6438303378300909ull,0x3678302039343430ull,
0x2030383738303434ull,0x3430653830337830ull,0x3434367830206434ull,0x090a203038373830ull,
0x3066383033783009ull,0x3436783020313534ull,0x3020303837383034ull,0x3034303039303378ull,
0x3034343678302064ull,0x09090a2030383738ull,0x3430313830337830ull,0x3434367830203930ull,
0x7830203038373830ull,0x6431653033383064ull,0x3030343430783020ull,0x3009090a20303837ull,
0x3230313338306478ull,0x3034343078302031ull,0x6478302030383730ull,0x2035323231333830ull,
0x3730303434307830ull,0x783009090a203038ull,0x3932343133383064ull,0x3030343430783020ull,
0x3064783020303837ull,0x3020643236313338ull,0x3837303034343078ull,0x64783009090a2030ull,
0x2031333831333830ull,0x3730303434307830ull,0x3830647830203038ull,0x7830203533613133ull,
0x3038373030343430ull,0x3064783009090a20ull,0x3020393363313338ull,0x3837303034343078ull,
0x3338306478302030ull,0x3078302064336531ull,0x2030383730303434ull,0x383064783009090aull,
0x7830203134303233ull,0x3038373030343430ull,0x3233383064783020ull,0x3430783020353432ull,
0x0a20303837303034ull,0x3338306478300909ull,0x3078302039343432ull,0x2030383730303434ull,
0x3632333830647830ull,0x3434307830206434ull,0x090a203038373030ull,0x3233383064783009ull,
0x3430783020313538ull,0x3020303837303034ull,0x3536303338306478ull,0x3034343078302035ull,
0x09090a2030383730ull,0x3430333830647830ull,0x3434307830203935ull,0x7830203038373030ull,
0x3930636335303033ull,0x3031323436783020ull,0x3009090a20306437ull,0x6635303030306178ull,
0x3130633078302064ull,0x3378302038633734ull,0x2039306130333030ull,0x3631303134637830ull,
0x783009090a203038ull,0x3930386330303032ull,0x3930323430783020ull,0x3064783020303836ull,
0x3020643534306530ull,0x3836313063303878ull,0x31783009090a2030ull,0x2064353866303030ull,
0x3164333034307830ull,0x3030317830203030ull,0x7830203930386630ull,0x3038376333303430ull,
0x3031783009090a20ull,0x3020393036303030ull,0x3832633034343278ull,0x3730306478302030ull,
0x3078302064663530ull,0x2038633730303034ull,0x303061783009090aull,0x7830203330303635ull,
0x3030303030303030ull,0x3635303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303178300909ull,0x3478302064303031ull,0x2030383763303034ull,0x6532333030337830ull,
0x3034657830206430ull,0x090a203038373030ull,0x3031393064783009ull,0x3430783020643036ull,
0x3020303837303034ull,0x3036303230303378ull,0x3031346378302064ull,0x09090a2030383730ull,
0x3830303030327830ull,0x3034307830206430ull,0x7830203038376330ull,0x3530363032303030ull,
0x3030303063783020ull,0x3009090a20303837ull,0x3038663130353278ull,0x3030303078302064ull,
0x3078302033303030ull,0x2031303831303034ull,0x3763303234657830ull,0x783009090a203038ull,
0x3130303030303066ull,0x3030303065783020ull,0x3638783020323030ull,0x3020333065666631ull,
0x3030303030303078ull,0x64783009090a2030ull,0x2064663530383030ull,0x3730303034307830ull,
0x3030617830203863ull,0x7830203330303336ull,0x3030303030303030ull,0x3031783009090a20ull,
0x3020333030333630ull,0x3031303030303078ull,0x3030303178302030ull,0x3478302064303031ull,
0x2030383763303034ull,0x303033783009090aull,0x7830206430653233ull,0x3038373030303465ull,
0x3031393064783020ull,0x3430783020643036ull,0x0a20303837303034ull,0x3230303378300909ull,
0x6378302064303630ull,0x2030383730303134ull,0x3830303030327830ull,0x3034307830206430ull,
0x090a203038376330ull,0x3032303030783009ull,0x3063783020353036ull,0x3020303837303030ull,
0x3038663130353278ull,0x3030303078302064ull,0x09090a2033303030ull,0x3831303034307830ull,
0x3234657830203130ull,0x7830203038376330ull,0x3130303030303066ull,0x3030303065783020ull,
0x3009090a20323030ull,0x3065666631363878ull,0x3030303078302033ull,0x6478302030303030ull,
0x2064663530393030ull,0x3730303034307830ull,0x783009090a203863ull,0x3330303037303061ull,
0x3030303030783020ull,0x3031783020303030ull,0x3020333030303730ull,0x3031303030303078ull,
0x31783009090a2030ull,0x2064303031303030ull,0x3763303034347830ull,0x3030337830203038ull,
0x7830206430653233ull,0x3038373030303465ull,0x3064783009090a20ull,0x3020643036303139ull,
0x3837303034343078ull,0x3230303378302030ull,0x6378302064303630ull,0x2030383730303134ull,
0x303032783009090aull,0x7830206430383030ull,0x3038376330303430ull,0x3032303030783020ull,
0x3063783020353036ull,0x0a20303837303030ull,0x3130353278300909ull,0x3078302064303866ull,
0x2033303030303030ull,0x3831303034307830ull,0x3234657830203130ull,0x090a203038376330ull,
0x3030303066783009ull,0x3065783020313030ull,0x3020323030303030ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3530613030647830ull,0x3034307830206466ull,
0x7830203863373030ull,0x3330306437303061ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3030643730303178ull,0x3030303078302033ull,0x3178302030303130ull,0x2064303031303030ull,
0x3763303034347830ull,0x783009090a203038ull,0x6430653233303033ull,0x3030303465783020ull,
0x3064783020303837ull,0x3020643036303139ull,0x3837303034343078ull,0x33783009090a2030ull,
0x2064303630323030ull,0x3730303134637830ull,0x3030327830203038ull,0x7830206430383030ull,
0x3038376330303430ull,0x3030783009090a20ull,0x3020353036303230ull,0x3837303030306378ull,
0x3130353278302030ull,0x3078302064303866ull,0x2033303030303030ull,0x303430783009090aull,
0x7830203130383130ull,0x3038376330323465ull,0x3030303066783020ull,0x3065783020313030ull,
0x0a20323030303030ull,0x6631363878300909ull,0x3078302033306566ull,0x2030303030303030ull,
0x3530623030647830ull,0x3034307830206466ull,0x090a203863373030ull,0x6138303061783009ull,
0x3030783020333030ull,0x3020303030303030ull,0x3030613830303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3031303030317830ull,0x3034347830206430ull,0x7830203038376330ull,
0x6430653233303033ull,0x3030303465783020ull,0x3009090a20303837ull,0x3036303139306478ull,
0x3034343078302064ull,0x3378302030383730ull,0x2064303630323030ull,0x3730303134637830ull,
0x783009090a203038ull,0x6430383030303032ull,0x6330303430783020ull,0x3030783020303837ull,
0x3020353036303230ull,0x3837303030306378ull,0x32783009090a2030ull,0x2064303866313035ull,
0x3030303030307830ull,0x3034307830203330ull,0x7830203130383130ull,0x3038376330323465ull,
0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,0x6631363878302032ull,
0x3078302033306566ull,0x2030303030303030ull,0x303064783009090aull,0x7830206466353063ull,
0x3863373030303430ull,0x3739303061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x3930303178300909ull,0x3078302033303037ull,0x2030303130303030ull,0x3031303030317830ull,
0x3034347830206430ull,0x090a203038376330ull,0x3233303033783009ull,0x3465783020643065ull,
0x3020303837303030ull,0x3036303139306478ull,0x3034343078302064ull,0x09090a2030383730ull,
0x3630323030337830ull,0x3134637830206430ull,0x7830203038373030ull,0x6430383030303032ull,
0x6330303430783020ull,0x3009090a20303837ull,0x3036303230303078ull,0x3030306378302035ull,
0x3278302030383730ull,0x2064303866313035ull,0x3030303030307830ull,0x783009090a203330ull,
0x3130383130303430ull,0x6330323465783020ull,0x3066783020303837ull,0x3020313030303030ull,
0x3030303030306578ull,0x38783009090a2032ull,0x2033306566663136ull,0x3030303030307830ull,
0x3030647830203030ull,0x7830206466353064ull,0x3863373030303430ull,0x3061783009090a20ull,
0x3020333030346130ull,0x3030303030303078ull,0x6130303178302030ull,0x3078302033303034ull,
0x2030303130303030ull,0x303031783009090aull,0x7830206430303130ull,0x3038376330303434ull,
0x3233303033783020ull,0x3465783020643065ull,0x0a20303837303030ull,0x3139306478300909ull,
0x3078302064303630ull,0x2030383730303434ull,0x3630323030337830ull,0x3134637830206430ull,
0x090a203038373030ull,0x3030303032783009ull,0x3430783020643038ull,0x3020303837633030ull,
0x3036303230303078ull,0x3030306378302035ull,0x09090a2030383730ull,0x3866313035327830ull,
0x3030307830206430ull,0x7830203330303030ull,0x3130383130303430ull,0x6330323465783020ull,
0x3009090a20303837ull,0x3030303030306678ull,0x3030306578302031ull,0x3878302032303030ull,
0x2033306566663136ull,0x3030303030307830ull,0x783009090a203030ull,0x6466353065303064ull,
0x3030303430783020ull,0x3061783020386337ull,0x3020333030316230ull,0x3030303030303078ull,
0x31783009090a2030ull,0x2033303031623030ull,0x3130303030307830ull,0x3030317830203030ull,
0x7830206430303130ull,0x3038376330303434ull,0x3033783009090a20ull,0x3020643065323330ull,
0x3837303030346578ull,0x3139306478302030ull,0x3078302064303630ull,0x2030383730303434ull,
0x303033783009090aull,0x7830206430363032ull,0x3038373030313463ull,0x3030303032783020ull,
0x3430783020643038ull,0x0a20303837633030ull,0x3230303078300909ull,0x6378302035303630ull,
0x2030383730303030ull,0x3866313035327830ull,0x3030307830206430ull,0x090a203330303030ull,
0x3130303430783009ull,0x3465783020313038ull,0x3020303837633032ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x6566663136387830ull,0x3030307830203330ull,
0x7830203030303030ull,0x6466353066303064ull,0x3030303430783020ull,0x3009090a20386337ull,
0x3030656230306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303065623030ull,
0x3130303030307830ull,0x783009090a203030ull,0x6430303130303031ull,0x6330303434783020ull,
0x3033783020303837ull,0x3020643065323330ull,0x3837303030346578ull,0x64783009090a2030ull,
0x2064303630313930ull,0x3730303434307830ull,0x3030337830203038ull,0x7830206430363032ull,
0x3038373030313463ull,0x3032783009090a20ull,0x3020643038303030ull,0x3837633030343078ull,
0x3230303078302030ull,0x6378302035303630ull,0x2030383730303030ull,0x303532783009090aull,
0x7830206430386631ull,0x3330303030303030ull,0x3130303430783020ull,0x3465783020313038ull,
0x0a20303837633032ull,0x3030306678300909ull,0x6578302031303030ull,0x2032303030303030ull,
0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,0x3030313064783009ull,
0x3430783020646635ull,0x3020386337303030ull,0x3030626330306178ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3062633030317830ull,0x3030307830203330ull,0x7830203030313030ull,
0x6430303130303031ull,0x6330303434783020ull,0x3009090a20303837ull,0x3065323330303378ull,
0x3030346578302064ull,0x6478302030383730ull,0x2064303630313930ull,0x3730303434307830ull,
0x783009090a203038ull,0x6430363032303033ull,0x3030313463783020ull,0x3032783020303837ull,
0x3020643038303030ull,0x3837633030343078ull,0x30783009090a2030ull,0x2035303630323030ull,
0x3730303030637830ull,0x3035327830203038ull,0x7830206430386631ull,0x3330303030303030ull,
0x3430783009090a20ull,0x3020313038313030ull,0x3837633032346578ull,0x3030306678302030ull,
0x6578302031303030ull,0x2032303030303030ull,0x313638783009090aull,0x7830203330656666ull,
0x3030303030303030ull,0x3031313064783020ull,0x3430783020646635ull,0x0a20386337303030ull,
0x6430306178300909ull,0x3078302033303038ull,0x2030303030303030ull,0x3038643030317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3130303031783009ull,0x3434783020643030ull,
0x3020303837633030ull,0x3065323330303378ull,0x3030346578302064ull,0x09090a2030383730ull,
0x3630313930647830ull,0x3434307830206430ull,0x7830203038373030ull,0x6430363032303033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3038303030303278ull,0x3030343078302064ull,
0x3078302030383763ull,0x2035303630323030ull,0x3730303030637830ull,0x783009090a203038ull,
0x6430386631303532ull,0x3030303030783020ull,0x3430783020333030ull,0x3020313038313030ull,
0x3837633032346578ull,0x66783009090a2030ull,0x2031303030303030ull,0x3030303030657830ull,
0x3136387830203230ull,0x7830203330656666ull,0x3030303030303030ull,0x3064783009090a20ull,
0x3020646635303231ull,0x6337303030343078ull,0x6530306178302038ull,0x3078302033303035ull,
0x2030303030303030ull,0x303031783009090aull,0x7830203330303565ull,0x3030313030303030ull,
0x3130303031783020ull,0x3434783020643030ull,0x0a20303837633030ull,0x3330303378300909ull,
0x6578302064306532ull,0x2030383730303034ull,0x3630313930647830ull,0x3434307830206430ull,
0x090a203038373030ull,0x3032303033783009ull,0x3463783020643036ull,0x3020303837303031ull,
0x3038303030303278ull,0x3030343078302064ull,0x09090a2030383763ull,0x3630323030307830ull,
0x3030637830203530ull,0x7830203038373030ull,0x6430386631303532ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3038313030343078ull,0x3032346578302031ull,0x6678302030383763ull,
0x2031303030303030ull,0x3030303030657830ull,0x783009090a203230ull,0x3330656666313638ull,
0x3030303030783020ull,0x3064783020303030ull,0x3020646635303331ull,0x6337303030343078ull,
0x61783009090a2038ull,0x2033303032663030ull,0x3030303030307830ull,0x3030317830203030ull,
0x7830203330303266ull,0x3030313030303030ull,0x3031783009090a20ull,0x3020643030313030ull,
0x3837633030343478ull,0x3330303378302030ull,0x6578302064306532ull,0x2030383730303034ull,
0x393064783009090aull,0x7830206430363031ull,0x3038373030343430ull,0x3032303033783020ull,
0x3463783020643036ull,0x0a20303837303031ull,0x3030303278300909ull,0x3078302064303830ull,
0x2030383763303034ull,0x3630323030307830ull,0x3030637830203530ull,0x090a203038373030ull,
0x6631303532783009ull,0x3030783020643038ull,0x3020333030303030ull,0x3038313030343078ull,
0x3032346578302031ull,0x09090a2030383763ull,0x3030303030667830ull,0x3030657830203130ull,
0x7830203230303030ull,0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,
0x6635303431306478ull,0x3030343078302064ull,0x6178302038633730ull,0x2033303066663030ull,
0x3030303030307830ull,0x783009090a203030ull,0x3330306666303031ull,0x3030303030783020ull,
0x3031783020303031ull,0x3020643030313030ull,0x3837633030343478ull,0x33783009090a2030ull,
0x2064306532333030ull,0x3730303034657830ull,0x3930647830203038ull,0x7830206430363031ull,
0x3038373030343430ull,0x3033783009090a20ull,0x3020643036303230ull,0x3837303031346378ull,
0x3030303278302030ull,0x3078302064303830ull,0x2030383763303034ull,0x303030783009090aull,
0x7830203530363032ull,0x3038373030303063ull,0x6631303532783020ull,0x3030783020643038ull,
0x0a20333030303030ull,0x3030343078300909ull,0x6578302031303831ull,0x2030383763303234ull,
0x3030303030667830ull,0x3030657830203130ull,0x090a203230303030ull,0x6666313638783009ull,
0x3030783020333065ull,0x3020303030303030ull,0x6635303531306478ull,0x3030343078302064ull,
0x09090a2038633730ull,0x3063303130617830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3330306330313031ull,0x3030303030783020ull,0x3009090a20303031ull,0x3030313030303178ull,
0x3030343478302064ull,0x3378302030383763ull,0x2064306532333030ull,0x3730303034657830ull,
0x783009090a203038ull,0x6430363031393064ull,0x3030343430783020ull,0x3033783020303837ull,
0x3020643036303230ull,0x3837303031346378ull,0x32783009090a2030ull,0x2064303830303030ull,
0x3763303034307830ull,0x3030307830203038ull,0x7830203530363032ull,0x3038373030303063ull,
0x3532783009090a20ull,0x3020643038663130ull,0x3030303030303078ull,0x3030343078302033ull,
0x6578302031303831ull,0x2030383763303234ull,0x303066783009090aull,0x7830203130303030ull,
0x3230303030303065ull,0x6666313638783020ull,0x3030783020333065ull,0x0a20303030303030ull,
0x3631306478300909ull,0x3078302064663530ull,0x2038633730303034ull,0x3039313130617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3931313031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030313030303178ull,0x3030343478302039ull,0x09090a2030383763ull,
0x6532323030337830ull,0x3034657830203930ull,0x7830203038373030ull,0x3930343031393064ull,
0x3030343430783020ull,0x3009090a20303837ull,0x3034303230303378ull,0x3031346378302039ull,
0x3278302030383730ull,0x2039303830303030ull,0x3738303034307830ull,0x783009090a203038ull,
0x3530343032303030ull,0x3030303063783020ull,0x3532783020303837ull,0x3020393038663130ull,
0x3030303030303078ull,0x30783009090a2033ull,0x2031303831303034ull,0x3738303234657830ull,
0x3030667830203038ull,0x7830203130303030ull,0x3230303030303065ull,0x3638783009090a20ull,
0x3020333065666631ull,0x3030303030303078ull,0x3031303278302030ull,0x3078302035316138ull,
0x2033303030303030ull,0x303033783009090aull,0x7830206466643035ull,0x3863373031303436ull,
0x3334303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3230303378300909ull,
0x6578302039303030ull,0x2032383730303134ull,0x3530313930337830ull,0x3434367830206466ull,
0x090a203863373031ull,0x3030303033783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3034303230303378ull,0x3031346378302064ull,0x09090a2030383730ull,0x3030353830647830ull,
0x3434307830203130ull,0x7830203038373030ull,0x3530343032393036ull,0x3430343036783020ull,
0x3009090a20303837ull,0x3030383330303278ull,0x3130303278302038ull,0x3278302030303038ull,
0x2035303438633030ull,0x3030303030307830ull,0x783009090a203330ull,0x3130303032303033ull,
0x3030313463783020ull,0x3030783020303837ull,0x3020353032303230ull,0x3837303030306378ull,
0x32783009090a2030ull,0x2035303030303031ull,0x3730303837307830ull,0x3036317830203038ull,
0x7830203130303830ull,0x3038376330303434ull,0x3032783009090a20ull,0x3020643036383030ull,
0x3030303030303078ull,0x6530306478302037ull,0x6178302031303230ull,0x2030383730306330ull,
0x393033783009090aull,0x7830206466373033ull,0x3863376330343436ull,0x3830303032783020ull,
0x3030783020353032ull,0x0a20333033303030ull,0x3231303178300909ull,0x3078302033303039ull,
0x2030383230303030ull,0x3030303030667830ull,0x3030657830203130ull,0x090a203130303030ull,
0x000000000a7d0a7dull
};


}



extern "C" {


static const unsigned long long __deviceText_$compute_13$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x2f2f090a33315f6dull,
0x656c69706d6f6320ull,0x2f20687469772064ull,0x61636f6c2f727375ull,0x6f2f616475632f6cull,
0x696c2f34366e6570ull,0x2f090a65622f2f62ull,0x6e65706f766e202full,0x6220332e32206363ull,
0x206e6f20746c6975ull,0x2d37302d39303032ull,0x2d2f2f090a0a3033ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x43202f2f090a2d2dull,0x676e696c69706d6full,
0x6d742f706d742f20ull,0x3030305f74667870ull,0x30305f6433353130ull,0x322d303030303030ull,
0x6369747261705f32ull,0x6d6574737953656cull,0x20692e337070632eull,0x63632f706d742f28ull,
0x4f4e64412e234942ull,0x2d2f2f090a295654ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2f2f090a0a2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x4f202f2f090a2d2dull,0x0a3a736e6f697470ull,0x2d2d2d2d2d2f2f09ull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x090a2d2d2d2d2d2dull,0x6772615420202f2full,
0x202c7874703a7465ull,0x315f6d733a415349ull,0x6169646e45202c33ull,0x656c7474696c3a6eull,
0x65746e696f50202cull,0x363a657a69532072ull,0x2d20202f2f090a34ull,0x6974704f2809334full,
0x6e6f6974617a696dull,0x0a296c6576656c20ull,0x30672d20202f2f09ull,0x2067756265442809ull,
0x090a296c6576656cull,0x09326d2d20202f2full,0x2074726f70655228ull,0x69726f7369766461ull,
0x2d2f2f090a297365ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x69662e090a0a2d2dull,0x633c22093109656cull,0x6c2d646e616d6d6full,0x2e090a223e656e69ull,
0x22093209656c6966ull,0x706d742f706d742full,0x303030305f746678ull,0x3030305f64333531ull,
0x31322d3030303030ull,0x6c6369747261705full,0x2e6d657473795365ull,0x2e32656661647563ull,
0x662e090a22757067ull,0x7022093309656c69ull,0x73656c6369747261ull,0x2e6c656e72656b5full,
0x662e090a22687563ull,0x7222093409656c69ull,0x74726f7378696461ull,0x2e090a226875632eull,
0x22093509656c6966ull,0x62696c2f7273752full,0x3638782f6363672full,0x756e696c2d34365full,
0x2e342f756e672d78ull,0x6c636e692f332e33ull,0x646474732f656475ull,0x2e090a22682e6665ull,
0x22093609656c6966ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x632f6564756c636eull,0x63697665642f7472ull,0x6d69746e75725f65ull,0x662e090a22682e65ull,
0x2f22093709656c69ull,0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6f682f6564756c63ull,0x6e696665645f7473ull,0x2e090a22682e7365ull,0x22093809656c6966ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x622f6564756c636eull,
0x745f6e69746c6975ull,0x0a22682e73657079ull,0x3909656c69662e09ull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f6563697665642full,
0x22682e7365707974ull,0x09656c69662e090aull,0x7273752f22093031ull,0x632f6c61636f6c2full,
0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x65766972642f6564ull,0x2e73657079745f72ull,
0x6c69662e090a2268ull,0x752f220931310965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x7865742f6564756cull,0x7079745f65727574ull,0x2e090a22682e7365ull,
0x09323109656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x745f726f74636576ull,0x0a22682e73657079ull,0x3109656c69662e09ull,
0x2f7273752f220933ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x6563697665642f65ull,0x5f68636e75616c5full,0x6574656d61726170ull,0x2e090a22682e7372ull,
0x09343109656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x726f74732f747263ull,0x73616c635f656761ull,0x662e090a22682e73ull,
0x2209353109656c69ull,0x636e692f7273752full,0x7469622f6564756cull,0x2e73657079742f73ull,
0x6c69662e090a2268ull,0x752f220936310965ull,0x756c636e692f7273ull,0x2e656d69742f6564ull,
0x6c69662e090a2268ull,0x6170220937310965ull,0x5f73656c63697472ull,0x632e6c656e72656bull,
0x6c69662e090a2275ull,0x6172220938310965ull,0x5f74726f73786964ull,0x632e6c656e72656bull,
0x6c69662e090a2275ull,0x752f220939310965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x6d6f632f6564756cull,0x636e75665f6e6f6dull,0x22682e736e6f6974ull,
0x09656c69662e090aull,0x7273752f22093032ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x662f7472632f6564ull,0x7263616d5f636e75ull,0x662e090a22682e6full,
0x2209313209656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x6d2f6564756c636eull,0x636e75665f687461ull,0x22682e736e6f6974ull,0x09656c69662e090aull,
0x7273752f22093232ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x63697665642f6564ull,0x6974636e75665f65ull,0x090a22682e736e6full,0x333209656c69662eull,
0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x6f635f6874616d2full,0x2e73746e6174736eull,0x6c69662e090a2268ull,0x752f220934320965ull,
0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x5f6d732f6564756cull,
0x696d6f74615f3131ull,0x6974636e75665f63ull,0x090a22682e736e6full,0x353209656c69662eull,
0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x615f32315f6d732full,0x75665f63696d6f74ull,0x2e736e6f6974636eull,0x6c69662e090a2268ull,
0x752f220936320965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x5f6d732f6564756cull,0x6c62756f645f3331ull,0x6974636e75665f65ull,0x090a22682e736e6full,
0x373209656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x657275747865742full,0x665f68637465665full,0x736e6f6974636e75ull,
0x69662e090a22682eull,0x2f2209383209656cull,0x61636f6c2f727375ull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,0x74636e75665f6874ull,0x6c62645f736e6f69ull,
0x22682e337874705full,0x657478652e090a0aull,0x726168732e096e72ull,0x67696c612e206465ull,
0x2038622e2034206eull,0x7553786964615273ull,0x742e090a3b5d5b6dull,0x203436752e207865ull,
0x6554736f50646c6full,0x7865742e090a3b78ull,0x6c6f203436752e20ull,0x3b7865546c655664ull,
0x2e207865742e090aull,0x7472617020343675ull,0x68736148656c6369ull,0x742e090a3b786554ull,
0x203436752e207865ull,0x726174536c6c6563ull,0x2e090a3b78655474ull,0x3436752e20786574ull,
0x756f436469726720ull,0x786554737265746eull,0x207865742e090a3bull,0x697267203436752eull,
0x6554736c6c654364ull,0x6e6f632e090a3b78ull,0x67696c612e207473ull,0x38622e203631206eull,
0x5b736d6172617020ull,0x2e090a3b5d323131ull,0x2e206c61626f6c67ull,0x2034206e67696c61ull,
0x646152642038622eull,0x39315b6d75537869ull,0x090a3b5d38303636ull,0x206c61626f6c672eull,
0x34206e67696c612eull,0x6152642038622e20ull,0x6b636f6c42786964ull,0x3b5d34365b6d7553ull,
0x72746e652e090a0aull,0x746e69395a5f2079ull,0x3650657461726765ull,0x30533474616f6c66ull,
0x665f30535f30535full,0x61702e09090a2820ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x6f5077656e5f665full,0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x655677656e5f665full,0x61702e09090a2c6cull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x6f50646c6f5f665full,0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x6556646c6f5f665full,0x61702e09090a2c6cull,0x3233662e206d6172ull,0x70616475635f5f20ull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x61746c65645f665full,0x7b090a29656d6954ull,0x2e206765722e090aull,0x373c722520323375ull,
0x6765722e090a3b3eull,0x7225203436752e20ull,0x090a3b3e32313c64ull,0x33662e206765722eull,
0x3e37343c66252032ull,0x206765722e090a3bull,0x702520646572702eull,0x6c2e090a3b3e383cull,
0x313609373109636full,0x3142424c240a3009ull,0x65746e69395a5f5full,0x6636506574617267ull,
0x5f30533474616f6cull,0x3a665f30535f3053ull,0x3109636f6c2e090aull,0x090a300935360937ull,
0x2e3233732e747663ull,0x3172250920363175ull,0x646961746325202cull,0x747663090a3b782eull,
0x3631752e3233732eull,0x25202c3272250920ull,0x0a3b782e6469746eull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x2c317225202c3372ull,0x63090a3b32722520ull,0x752e3233752e7476ull,
0x2c34722509203631ull,0x3b782e6469742520ull,0x33752e646461090aull,0x202c357225092032ull,
0x347225202c337225ull,0x752e747663090a3bull,0x09203233732e3436ull,0x7225202c31647225ull,
0x2e6c756d090a3b35ull,0x09203436752e6f6cull,0x7225202c32647225ull,0x0a3b3631202c3164ull,
0x617261702e646c09ull,0x2509203436752e6dull,0x5f5f5b202c336472ull,0x6d72617061647563ull,
0x65746e69395a5f5full,0x6636506574617267ull,0x5f30533474616f6cull,0x5f665f30535f3053ull,
0x3b5d736f50646c6full,0x36752e646461090aull,0x2c34647225092034ull,0x25202c3364722520ull,
0x646c090a3b326472ull,0x2e6c61626f6c672eull,0x09203233662e3476ull,0x3266252c3166257bull,
0x3466252c3366252cull,0x346472255b202c7dull,0x6c2e090a3b5d302bull,0x363609373109636full,
0x702e646c090a3009ull,0x3436752e6d617261ull,0x202c356472250920ull,0x70616475635f5f5bull,
0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x6556646c6f5f665full,0x646461090a3b5d6cull,0x722509203436752eull,0x35647225202c3664ull,
0x0a3b32647225202cull,0x626f6c672e646c09ull,0x33662e34762e6c61ull,0x2c3566257b092032ull,
0x2c3766252c366625ull,0x255b202c7d386625ull,0x0a3b5d302b366472ull,0x373109636f6c2e09ull,
0x6c090a3009313709ull,0x2e6d617261702e64ull,0x3966250920323366ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x61726765746e6939ull,0x616f6c6636506574ull,0x5f30535f30533474ull,
0x6c65645f665f3053ull,0x3b5d656d69546174ull,0x6e6f632e646c090aull,0x09203233662e7473ull,
0x705b202c30316625ull,0x30322b736d617261ull,0x2e6c756d090a3b5dull,0x3166250920323366ull,
0x2c30316625202c31ull,0x61090a3b39662520ull,0x09203233662e6464ull,0x6625202c32316625ull,
0x3b356625202c3131ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c33316625ull,
0x32332b736d617261ull,0x2e6c756d090a3b5dull,0x3166250920323366ull,0x2c32316625202c34ull,
0x090a3b3331662520ull,0x203233662e766f6dull,0x25202c3531662509ull,0x646c090a3b343166ull,
0x662e74736e6f632eull,0x3631662509203233ull,0x6d617261705b202cull,0x090a3b5d34322b73ull,
0x203233662e6c756dull,0x25202c3731662509ull,0x396625202c363166ull,0x662e646461090a3bull,
0x3831662509203233ull,0x202c37316625202cull,0x756d090a3b366625ull,0x2509203233662e6cull,
0x316625202c393166ull,0x3b33316625202c38ull,0x33662e766f6d090aull,0x2c30326625092032ull,
0x090a3b3931662520ull,0x74736e6f632e646cull,0x662509203233662eull,0x7261705b202c3132ull,
0x3b5d38322b736d61ull,0x33662e6c756d090aull,0x2c32326625092032ull,0x25202c3132662520ull,
0x646461090a3b3966ull,0x662509203233662eull,0x32326625202c3332ull,0x090a3b376625202cull,
0x203233662e6c756dull,0x25202c3432662509ull,0x316625202c333266ull,0x2e766f6d090a3b33ull,
0x3266250920323366ull,0x3b34326625202c35ull,0x3109636f6c2e090aull,0x090a300934370937ull,
0x203233662e6c756dull,0x25202c3632662509ull,0x396625202c343166ull,0x662e646461090a3bull,
0x3732662509203233ull,0x202c36326625202cull,0x6f6d090a3b316625ull,0x2509203233662e76ull,
0x326625202c383266ull,0x2e6c756d090a3b37ull,0x3266250920323366ull,0x2c39316625202c39ull,
0x61090a3b39662520ull,0x09203233662e6464ull,0x6625202c30336625ull,0x3b326625202c3932ull,
0x33662e766f6d090aull,0x2c31336625092032ull,0x090a3b3033662520ull,0x203233662e6c756dull,
0x25202c3233662509ull,0x396625202c343266ull,0x662e646461090a3bull,0x3333662509203233ull,
0x202c32336625202cull,0x6f6d090a3b336625ull,0x2509203233662e76ull,0x336625202c343366ull,
0x632e646c090a3b33ull,0x3233662e74736e6full,0x202c353366250920ull,0x2b736d617261705bull,
0x6f6d090a3b5d3633ull,0x2509203233662e76ull,0x336630202c363366ull,0x3b30303030303866ull,
0x202f2f0920202020ull,0x662e627573090a31ull,0x3733662509203233ull,0x202c36336625202cull,
0x73090a3b35336625ull,0x662e746c2e707465ull,0x2c31702509203233ull,0x25202c3733662520ull,
0x2140090a3b373266ull,0x2061726220317025ull,0x345f305f744c2409ull,0x6c2e090a3b363638ull,
0x373709373109636full,0x2e766f6d090a3009ull,0x3266250920323366ull,0x3b37336625202c38ull,
0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c38336625ull,0x30312b736d617261ull,
0x6c756d090a3b5d34ull,0x662509203233662eull,0x38336625202c3531ull,0x0a3b34316625202cull,
0x38345f305f744c24ull,0x766f6d090a3a3636ull,0x662509203233662eull,0x66626630202c3933ull,
0x203b303030303038ull,0x2d202f2f09202020ull,0x662e646461090a31ull,0x3034662509203233ull,
0x202c35336625202cull,0x73090a3b39336625ull,0x662e74672e707465ull,0x2c32702509203233ull,
0x25202c3034662520ull,0x2140090a3b383266ull,0x2061726220327025ull,0x355f305f744c2409ull,
0x6c2e090a3b383733ull,0x383709373109636full,0x2e766f6d090a3009ull,0x3266250920323366ull,
0x3b30346625202c38ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c31346625ull,
0x30312b736d617261ull,0x6c756d090a3b5d34ull,0x662509203233662eull,0x31346625202c3531ull,
0x0a3b35316625202cull,0x33355f305f744c24ull,0x746573090a3a3837ull,0x3233662e746c2e70ull,
0x25202c3370250920ull,0x336625202c373366ull,0x70252140090a3b30ull,0x2409206172622033ull,
0x3938355f305f744cull,0x636f6c2e090a3b30ull,0x3009393709373109ull,0x33662e766f6d090aull,
0x2c31336625092032ull,0x090a3b3733662520ull,0x74736e6f632e646cull,0x662509203233662eull,
0x7261705b202c3234ull,0x5d3430312b736d61ull,0x662e6c756d090a3bull,0x3032662509203233ull,
0x202c32346625202cull,0x4c240a3b39316625ull,0x303938355f305f74ull,0x2e70746573090a3aull,
0x09203233662e7467ull,0x346625202c347025ull,0x3b31336625202c30ull,0x203470252140090aull,
0x744c240920617262ull,0x3b323034365f305full,0x3109636f6c2e090aull,0x090a300930380937ull,
0x203233662e766f6dull,0x25202c3133662509ull,0x646c090a3b303466ull,0x662e74736e6f632eull,
0x3334662509203233ull,0x6d617261705b202cull,0x0a3b5d3430312b73ull,0x3233662e6c756d09ull,
0x202c303266250920ull,0x6625202c33346625ull,0x5f744c240a3b3032ull,0x0a3a323034365f30ull,
0x746c2e7074657309ull,0x702509203233662eull,0x2c37336625202c35ull,0x090a3b3333662520ull,
0x7262203570252140ull,0x305f744c24092061ull,0x090a3b343139365full,0x09373109636f6c2eull,
0x6f6d090a30093138ull,0x2509203233662e76ull,0x336625202c343366ull,0x632e646c090a3b37ull,
0x3233662e74736e6full,0x202c343466250920ull,0x2b736d617261705bull,0x6d090a3b5d343031ull,
0x09203233662e6c75ull,0x6625202c35326625ull,0x34326625202c3434ull,0x5f305f744c240a3bull,
0x73090a3a34313936ull,0x662e74672e707465ull,0x2c36702509203233ull,0x25202c3034662520ull,
0x2140090a3b343366ull,0x2061726220367025ull,0x375f305f744c2409ull,0x6c2e090a3b363234ull,
0x323809373109636full,0x2e766f6d090a3009ull,0x3366250920323366ull,0x3b30346625202c34ull,
0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c35346625ull,0x30312b736d617261ull,
0x6c756d090a3b5d34ull,0x662509203233662eull,0x35346625202c3532ull,0x0a3b35326625202cull,
0x34375f305f744c24ull,0x6f6c2e090a3a3632ull,0x0935380937310963ull,0x61702e646c090a30ull,
0x203436752e6d6172ull,0x5b202c3764722509ull,0x6170616475635f5full,0x6e69395a5f5f6d72ull,
0x5065746172676574ull,0x533474616f6c6636ull,0x5f30535f30535f30ull,0x736f5077656e5f66ull,
0x2e646461090a3b5dull,0x6472250920343675ull,0x2c37647225202c38ull,0x090a3b3264722520ull,
0x61626f6c672e7473ull,0x3233662e34762e6cull,0x2b386472255b0920ull,0x3266257b202c5d30ull,
0x252c313366252c38ull,0x7d3466252c343366ull,0x09636f6c2e090a3bull,0x0a30093638093731ull,
0x617261702e646c09ull,0x2509203436752e6dull,0x5f5f5b202c396472ull,0x6d72617061647563ull,
0x65746e69395a5f5full,0x6636506574617267ull,0x5f30533474616f6cull,0x5f665f30535f3053ull,
0x3b5d6c655677656eull,0x36752e646461090aull,0x3031647225092034ull,0x202c39647225202cull,
0x73090a3b32647225ull,0x6c61626f6c672e74ull,0x203233662e34762eull,0x2b30316472255b09ull,
0x3166257b202c5d30ull,0x252c303266252c35ull,0x7d3866252c353266ull,0x09636f6c2e090a3bull,
0x0a30093738093731ull,0x240a3b7469786509ull,0x5f5f646e6557444cull,0x726765746e69395aull,
0x6f6c663650657461ull,0x30535f3053347461ull,0x090a3a665f30535full,0x395a5f202f2f207dull,
0x7461726765746e69ull,0x74616f6c66365065ull,0x535f30535f305334ull,0x652e090a0a665f30ull,
0x315a5f207972746eull,0x4765746164707531ull,0x6c66365044646972ull,0x31536a503474616full,
0x702e09090a28205full,0x36752e206d617261ull,0x616475635f5f2034ull,0x315a5f5f6d726170ull,
0x4765746164707531ull,0x6c66365044646972ull,0x31536a503474616full,0x090a2c736f705f5full,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x6164707531315a5full,
0x5044646972476574ull,0x503474616f6c6636ull,0x6972675f5f31536aull,0x7265746e756f4364ull,
0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x31315a5f5f6d7261ull,
0x7247657461647075ull,0x6f6c663650446469ull,0x5f31536a50347461ull,0x6c6543646972675full,
0x090a7b090a29736cull,0x33752e206765722eull,0x0a3b317672252032ull,0x752e206765722e09ull,
0x31333c7225203233ull,0x6765722e090a3b3eull,0x7225203436752e20ull,0x090a3b3e34313c64ull,
0x33662e206765722eull,0x3e30323c66252032ull,0x09636f6c2e090a3bull,0x3009343331093731ull,
0x5f5f3142424c240aull,0x746164707531315aull,0x3650446469724765ull,0x6a503474616f6c66ull,
0x6c2e090a3a5f3153ull,0x333109373109636full,0x747663090a300937ull,0x3631752e3233732eull,
0x25202c3172250920ull,0x3b782e6469617463ull,0x33732e747663090aull,0x2509203631752e32ull,
0x69746e25202c3272ull,0x756d090a3b782e64ull,0x732e6f6c2e34326cull,0x2c33722509203233ull,
0x7225202c31722520ull,0x2e747663090a3b32ull,0x203631752e323375ull,0x7425202c34722509ull,
0x61090a3b782e6469ull,0x09203233752e6464ull,0x337225202c357225ull,0x090a3b347225202cull,
0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3164ull,0x5f6d726170616475ull,
0x6164707531315a5full,0x5044646972476574ull,0x503474616f6c6636ull,0x736f705f5f31536aull,
0x2e747663090a3b5dull,0x203233732e343675ull,0x25202c3264722509ull,0x6c756d090a3b3572ull,
0x203436752e6f6c2eull,0x25202c3364722509ull,0x3b3631202c326472ull,0x36752e646461090aull,
0x2c34647225092034ull,0x25202c3164722520ull,0x646c090a3b336472ull,0x2e6c61626f6c672eull,
0x09203233662e3476ull,0x3266252c3166257bull,0x2c7d5f2c3366252cull,0x302b346472255b20ull,
0x636f6c2e090a3b5dull,0x0934303109373109ull,0x6f632e646c090a30ull,0x203233752e74736eull,
0x705b202c36722509ull,0x34342b736d617261ull,0x632e646c090a3b5dull,0x3233752e74736e6full,
0x5b202c3772250920ull,0x342b736d61726170ull,0x2e646c090a3b5d30ull,0x33662e74736e6f63ull,
0x202c346625092032ull,0x2b736d617261705bull,0x7573090a3b5d3436ull,0x2509203233662e62ull,
0x2c336625202c3566ull,0x6c090a3b34662520ull,0x2e74736e6f632e64ull,0x3666250920323366ull,
0x6d617261705b202cull,0x090a3b5d36372b73ull,0x6c6c75662e766964ull,0x662509203233662eull,
0x202c356625202c37ull,0x7663090a3b366625ull,0x33662e696d722e74ull,0x2509203233662e32ull,
0x3b376625202c3866ull,0x7a722e747663090aull,0x33662e3233732e69ull,0x202c387225092032ull,
0x646c090a3b386625ull,0x752e74736e6f632eull,0x2c39722509203233ull,0x736d617261705b20ull,
0x73090a3b5d38342bull,0x09203233752e6275ull,0x7225202c30317225ull,0x6d090a3b31202c39ull,
0x09203233752e6e69ull,0x7225202c31317225ull,0x3b30317225202c38ull,0x2e34326c756d090aull,
0x09203233732e6f6cull,0x7225202c32317225ull,0x3b367225202c3131ull,0x2e34326c756d090aull,
0x09203233732e6f6cull,0x7225202c33317225ull,0x3b377225202c3231ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x61705b202c396625ull,0x5d30362b736d6172ull,0x662e627573090a3bull,
0x3031662509203233ull,0x25202c326625202cull,0x2e646c090a3b3966ull,0x33662e74736e6f63ull,
0x2c31316625092032ull,0x736d617261705b20ull,0x64090a3b5d32372bull,0x2e6c6c75662e7669ull,
0x3166250920323366ull,0x2c30316625202c32ull,0x090a3b3131662520ull,0x2e696d722e747663ull,
0x203233662e323366ull,0x25202c3331662509ull,0x7663090a3b323166ull,0x33732e697a722e74ull,
0x2509203233662e32ull,0x316625202c343172ull,0x2e627573090a3b33ull,0x3172250920323375ull,
0x202c367225202c35ull,0x2e6e696d090a3b31ull,0x3172250920323375ull,0x2c34317225202c36ull,
0x090a3b3531722520ull,0x6f6c2e34326c756dull,0x722509203233732eull,0x36317225202c3731ull,
0x090a3b377225202cull,0x203233732e646461ull,0x25202c3831722509ull,0x317225202c333172ull,
0x632e646c090a3b37ull,0x3233662e74736e6full,0x202c343166250920ull,0x2b736d617261705bull,
0x7573090a3b5d3635ull,0x2509203233662e62ull,0x316625202c353166ull,0x0a3b34316625202cull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x61705b202c363166ull,0x5d38362b736d6172ull,
0x662e766964090a3bull,0x203233662e6c6c75ull,0x25202c3731662509ull,0x316625202c353166ull,
0x2e747663090a3b36ull,0x2e3233662e696d72ull,0x3166250920323366ull,0x3b37316625202c38ull,
0x7a722e747663090aull,0x33662e3233732e69ull,0x2c39317225092032ull,0x090a3b3831662520ull,
0x203233752e627573ull,0x25202c3032722509ull,0x090a3b31202c3772ull,0x203233752e6e696dull,
0x25202c3132722509ull,0x327225202c393172ull,0x2e646461090a3b30ull,0x3272250920323373ull,
0x2c38317225202c32ull,0x090a3b3132722520ull,0x09373109636f6c2eull,0x6c090a3009313231ull,
0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c35ull,0x5f5f6d7261706164ull,
0x746164707531315aull,0x3650446469724765ull,0x6a503474616f6c66ull,0x646972675f5f3153ull,
0x737265746e756f43ull,0x2e747663090a3b5dull,0x203233752e343675ull,0x25202c3664722509ull,
0x756d090a3b323272ull,0x3436752e6f6c2e6cull,0x202c376472250920ull,0x3b34202c36647225ull,
0x36752e646461090aull,0x2c38647225092034ull,0x25202c3564722520ull,0x6f6d090a3b376472ull,
0x2509203233752e76ull,0x0a3b31202c333272ull,0x6c672e6d6f746109ull,0x6464612e6c61626full,
0x722509203233752eull,0x6472255b202c3176ull,0x33327225202c5d38ull,0x732e766f6d090a3bull,
0x3432722509203233ull,0x0a3b31767225202cull,0x373109636f6c2e09ull,0x090a300936323109ull,
0x74736e6f632e646cull,0x722509203233752eull,0x7261705b202c3532ull,0x3b5d34382b736d61ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c39647225ull,0x726170616475635full,
0x707531315a5f5f6dull,0x6469724765746164ull,0x74616f6c66365044ull,0x675f5f31536a5034ull,
0x736c6c6543646972ull,0x2e627573090a3b5dull,0x3272250920323375ull,0x2c35327225202c36ull,
0x6e696d090a3b3120ull,0x722509203233752eull,0x34327225202c3732ull,0x0a3b36327225202cull,
0x2e6f6c2e6c756d09ull,0x3272250920323375ull,0x2c32327225202c38ull,0x090a3b3532722520ull,
0x203233752e646461ull,0x25202c3932722509ull,0x327225202c373272ull,0x2e747663090a3b38ull,
0x203233752e343675ull,0x202c303164722509ull,0x6d090a3b39327225ull,0x36752e6f6c2e6c75ull,
0x3131647225092034ull,0x2c3031647225202cull,0x646461090a3b3420ull,0x722509203436752eull,
0x647225202c323164ull,0x3131647225202c39ull,0x6c672e7473090a3bull,0x3233752e6c61626full,
0x32316472255b0920ull,0x357225202c5d302bull,0x09636f6c2e090a3bull,0x3009333431093731ull,
0x0a3b74697865090aull,0x5f646e6557444c24ull,0x6164707531315a5full,0x5044646972476574ull,
0x503474616f6c6636ull,0x7d090a3a5f31536aull,0x31315a5f202f2f20ull,0x7247657461647075ull,
0x6f6c663650446469ull,0x5f31536a50347461ull,0x72746e652e090a0aull,0x6c6163395a5f2079ull,
0x3650446873614863ull,0x35503474616f6c66ull,0x0a282032746e6975ull,0x6d617261702e0909ull,
0x5f5f203436752e20ull,0x6d72617061647563ull,0x636c6163395a5f5full,0x6636504468736148ull,
0x7535503474616f6cull,0x736f705f32746e69ull,0x7261702e09090a2cull,0x203436752e206d61ull,
0x6170616475635f5full,0x6163395a5f5f6d72ull,0x504468736148636cull,0x503474616f6c6636ull,
0x705f32746e697535ull,0x48656c6369747261ull,0x0a7b090a29687361ull,0x752e206765722e09ull,
0x34323c7225203233ull,0x6765722e090a3b3eull,0x7225203436752e20ull,0x2e090a3b3e393c64ull,
0x3233662e20676572ull,0x3b3e30323c662520ull,0x3109636f6c2e090aull,0x0a30093834310937ull,
0x5a5f5f3142424c24ull,0x736148636c616339ull,0x616f6c6636504468ull,0x746e697535503474ull,
0x636f6c2e090a3a32ull,0x0931353109373109ull,0x732e747663090a30ull,0x09203631752e3233ull,
0x746325202c317225ull,0x090a3b782e646961ull,0x2e3233732e747663ull,0x3272250920363175ull,
0x2e6469746e25202cull,0x326c756d090a3b78ull,0x3233732e6f6c2e34ull,0x25202c3372250920ull,
0x3b327225202c3172ull,0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3472ull,
0x646461090a3b782eull,0x722509203233752eull,0x202c337225202c35ull,0x7663090a3b347225ull,
0x33732e3436752e74ull,0x2c31647225092032ull,0x6c090a3b35722520ull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x75635f5f5b202c32ull,0x5f5f6d7261706164ull,0x6148636c6163395aull,
0x6f6c663650446873ull,0x6e69753550347461ull,0x3b5d736f705f3274ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x31647225202c3364ull,0x61090a3b3631202cull,0x09203436752e6464ull,
0x7225202c34647225ull,0x33647225202c3264ull,0x6c672e646c090a3bull,0x2e34762e6c61626full,
0x66257b0920323366ull,0x66252c3266252c31ull,0x255b202c7d5f2c33ull,0x0a3b5d302b346472ull,
0x373109636f6c2e09ull,0x090a300934303109ull,0x74736e6f632e646cull,0x722509203233752eull,
0x617261705b202c36ull,0x0a3b5d34342b736dull,0x736e6f632e646c09ull,0x2509203233752e74ull,
0x7261705b202c3772ull,0x3b5d30342b736d61ull,0x6e6f632e646c090aull,0x09203233662e7473ull,
0x61705b202c346625ull,0x5d34362b736d6172ull,0x662e627573090a3bull,0x2c35662509203233ull,
0x6625202c33662520ull,0x632e646c090a3b34ull,0x3233662e74736e6full,0x5b202c3666250920ull,
0x372b736d61726170ull,0x766964090a3b5d36ull,0x33662e6c6c75662eull,0x202c376625092032ull,
0x366625202c356625ull,0x722e747663090a3bull,0x662e3233662e696dull,0x2c38662509203233ull,
0x63090a3b37662520ull,0x732e697a722e7476ull,0x09203233662e3233ull,0x386625202c387225ull,
0x6f632e646c090a3bull,0x203233752e74736eull,0x705b202c39722509ull,0x38342b736d617261ull,
0x2e627573090a3b5dull,0x3172250920323375ull,0x202c397225202c30ull,0x2e6e696d090a3b31ull,
0x3172250920323375ull,0x202c387225202c31ull,0x6d090a3b30317225ull,0x2e6f6c2e34326c75ull,
0x3172250920323373ull,0x2c31317225202c32ull,0x6d090a3b36722520ull,0x2e6f6c2e34326c75ull,
0x3172250920323373ull,0x2c32317225202c33ull,0x6c090a3b37722520ull,0x2e74736e6f632e64ull,
0x3966250920323366ull,0x6d617261705b202cull,0x090a3b5d30362b73ull,0x203233662e627573ull,
0x25202c3031662509ull,0x3b396625202c3266ull,0x6e6f632e646c090aull,0x09203233662e7473ull,
0x705b202c31316625ull,0x32372b736d617261ull,0x2e766964090a3b5dull,0x3233662e6c6c7566ull,
0x202c323166250920ull,0x6625202c30316625ull,0x747663090a3b3131ull,0x3233662e696d722eull,
0x662509203233662eull,0x32316625202c3331ull,0x722e747663090a3bull,0x662e3233732e697aull,
0x3431722509203233ull,0x0a3b33316625202cull,0x3233752e62757309ull,0x202c353172250920ull,
0x0a3b31202c367225ull,0x3233752e6e696d09ull,0x202c363172250920ull,0x7225202c34317225ull,
0x6c756d090a3b3531ull,0x33732e6f6c2e3432ull,0x2c37317225092032ull,0x25202c3631722520ull,
0x646461090a3b3772ull,0x722509203233732eull,0x33317225202c3831ull,0x0a3b37317225202cull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x61705b202c343166ull,0x5d36352b736d6172ull,
0x662e627573090a3bull,0x3531662509203233ull,0x25202c316625202cull,0x646c090a3b343166ull,
0x662e74736e6f632eull,0x3631662509203233ull,0x6d617261705b202cull,0x090a3b5d38362b73ull,
0x6c6c75662e766964ull,0x662509203233662eull,0x35316625202c3731ull,0x0a3b36316625202cull,
0x696d722e74766309ull,0x3233662e3233662eull,0x202c383166250920ull,0x63090a3b37316625ull,
0x732e697a722e7476ull,0x09203233662e3233ull,0x6625202c39317225ull,0x627573090a3b3831ull,
0x722509203233752eull,0x2c377225202c3032ull,0x6e696d090a3b3120ull,0x722509203233752eull,
0x39317225202c3132ull,0x0a3b30327225202cull,0x3233732e64646109ull,0x202c323272250920ull,
0x7225202c38317225ull,0x6f6c2e090a3b3132ull,0x3835310937310963ull,0x702e646c090a3009ull,
0x3436752e6d617261ull,0x202c356472250920ull,0x70616475635f5f5bull,0x63395a5f5f6d7261ull,
0x4468736148636c61ull,0x3474616f6c663650ull,0x5f32746e69753550ull,0x656c636974726170ull,
0x090a3b5d68736148ull,0x752e6f6c2e6c756dull,0x3664722509203436ull,0x202c31647225202cull,
0x2e646461090a3b38ull,0x6472250920343675ull,0x2c35647225202c37ull,0x090a3b3664722520ull,
0x61626f6c672e7473ull,0x3233752e32762e6cull,0x2b376472255b0920ull,0x3272257b202c5d30ull,
0x0a3b7d3572252c32ull,0x373109636f6c2e09ull,0x090a300939353109ull,0x4c240a3b74697865ull,
0x5a5f5f646e655744ull,0x736148636c616339ull,0x616f6c6636504468ull,0x746e697535503474ull,
0x2f2f207d090a3a32ull,0x636c6163395a5f20ull,0x6636504468736148ull,0x7535503474616f6cull,
0x2e090a0a32746e69ull,0x5a5f207972746e65ull,0x6564726f65723832ull,0x646e416174614472ull,
0x6c6c6543646e6946ull,0x3550447472617453ull,0x66365032746e6975ull,0x5f32533474616f6cull,
0x6a505f32535f3253ull,0x61702e09090a2820ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x38325a5f5f6d7261ull,0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,
0x6975355044747261ull,0x6f6c66365032746eull,0x32535f3253347461ull,0x705f6a505f32535full,
0x48656c6369747261ull,0x2e09090a2c687361ull,0x752e206d61726170ull,0x6475635f5f203436ull,
0x5a5f5f6d72617061ull,0x6564726f65723832ull,0x646e416174614472ull,0x6c6c6543646e6946ull,
0x3550447472617453ull,0x66365032746e6975ull,0x5f32533474616f6cull,0x6a505f32535f3253ull,
0x2c736f50646c6f5full,0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,
0x657238325a5f5f6dull,0x746144726564726full,0x646e6946646e4161ull,0x726174536c6c6543ull,
0x746e697535504474ull,0x74616f6c66365032ull,0x535f32535f325334ull,0x646c6f5f6a505f32ull,
0x2e09090a2c6c6556ull,0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,
0x6564726f65723832ull,0x646e416174614472ull,0x6c6c6543646e6946ull,0x3550447472617453ull,
0x66365032746e6975ull,0x5f32533474616f6cull,0x6a505f32535f3253ull,0x50646574726f735full,
0x702e09090a2c736full,0x36752e206d617261ull,0x616475635f5f2034ull,0x325a5f5f6d726170ull,
0x726564726f657238ull,0x46646e4161746144ull,0x536c6c6543646e69ull,0x7535504474726174ull,
0x6c66365032746e69ull,0x535f32533474616full,0x5f6a505f32535f32ull,0x6556646574726f73ull,
0x61702e09090a2c6cull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x38325a5f5f6d7261ull,
0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,0x6975355044747261ull,
0x6f6c66365032746eull,0x32535f3253347461ull,0x635f6a505f32535full,0x74726174536c6c65ull,
0x722e090a7b090a29ull,0x203233752e206765ull,0x0a3b3e32333c7225ull,0x752e206765722e09ull,
0x313c647225203436ull,0x65722e090a3b3e39ull,0x25203233662e2067ull,0x090a3b3e38313c66ull,
0x72702e206765722eull,0x3e353c7025206465ull,0x726168732e090a3bull,0x67696c612e206465ull,
0x2038622e2034206eull,0x735f616475635f5full,0x7361486465726168ull,0x5b32313936393168ull,
0x090a3b5d38323031ull,0x09373109636f6c2eull,0x4c240a3009393631ull,0x38325a5f5f314242ull,
0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,0x6975355044747261ull,
0x6f6c66365032746eull,0x32535f3253347461ull,0x0a3a6a505f32535full,0x373109636f6c2e09ull,
0x090a300933373109ull,0x2e3233732e747663ull,0x3172250920363175ull,0x646961746325202cull,
0x747663090a3b782eull,0x3631752e3233732eull,0x25202c3272250920ull,0x0a3b782e6469746eull,
0x6c2e34326c756d09ull,0x2509203233732e6full,0x2c317225202c3372ull,0x63090a3b32722520ull,
0x752e3233752e7476ull,0x2c34722509203631ull,0x3b782e6469742520ull,0x33752e646461090aull,
0x202c357225092032ull,0x347225202c337225ull,0x752e747663090a3bull,0x09203233732e3436ull,
0x7225202c31647225ull,0x702e646c090a3b35ull,0x3436752e6d617261ull,0x202c326472250920ull,
0x70616475635f5f5bull,0x38325a5f5f6d7261ull,0x44726564726f6572ull,0x6946646e41617461ull,
0x74536c6c6543646eull,0x6975355044747261ull,0x6f6c66365032746eull,0x32535f3253347461ull,
0x705f6a505f32535full,0x48656c6369747261ull,0x6d090a3b5d687361ull,0x36752e6f6c2e6c75ull,
0x2c33647225092034ull,0x38202c3164722520ull,0x752e646461090a3bull,0x3464722509203436ull,
0x202c32647225202cull,0x6c090a3b33647225ull,0x6c61626f6c672e64ull,0x203233752e32762eull,
0x72252c3672257b09ull,0x6472255b202c7d37ull,0x2e090a3b5d302b34ull,0x3109373109636f6cull,
0x6f6d090a30093937ull,0x2509203436752e76ull,0x635f5f202c356472ull,0x726168735f616475ull,
0x3931687361486465ull,0x63090a3b32313936ull,0x752e3436752e7476ull,0x3664722509203233ull,
0x090a3b347225202cull,0x752e6f6c2e6c756dull,0x3764722509203436ull,0x202c36647225202cull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x2c35647225202c38ull,0x090a3b3764722520ull,
0x65726168732e7473ull,0x5b09203233752e64ull,0x2c5d342b38647225ull,0x6d090a3b36722520ull,
0x09203233732e766full,0x0a3b30202c387225ull,0x2e74672e74657309ull,0x203233732e323375ull,
0x7225202c39722509ull,0x0a3b387225202c35ull,0x3233732e67656e09ull,0x202c303172250920ull,
0x6f6d090a3b397225ull,0x2509203233752e76ull,0x0a3b30202c313172ull,0x2e71652e74657309ull,
0x203233752e323375ull,0x25202c3231722509ull,0x31317225202c3472ull,0x732e67656e090a3bull,
0x3331722509203233ull,0x0a3b32317225202cull,0x3233622e646e6109ull,0x202c343172250920ull,
0x7225202c30317225ull,0x766f6d090a3b3331ull,0x722509203233752eull,0x090a3b30202c3531ull,
0x2e71652e70746573ull,0x3170250920323373ull,0x202c34317225202cull,0x40090a3b35317225ull,
0x2061726220317025ull,0x325f335f744c2409ull,0x646c090a3b383138ull,0x6c6974616c6f762eull,
0x6c61626f6c672e65ull,0x203233752e32762eull,0x252c363172257b09ull,0x255b202c7d373172ull,
0x3b5d382d2b346472ull,0x3109636f6c2e090aull,0x0a30093338310937ull,0x3233732e766f6d09ull,
0x202c383172250920ull,0x6d090a3b36317225ull,0x09203233732e766full,0x7225202c39317225ull,
0x6f6c2e090a3b3731ull,0x3438310937310963ull,0x2e766f6d090a3009ull,0x3272250920323373ull,
0x3b38317225202c30ull,0x6168732e7473090aull,0x203233752e646572ull,0x616475635f5f5b09ull,
0x486465726168735full,0x3139363931687361ull,0x7225202c5d302b32ull,0x5f744c240a3b3032ull,
0x0a3a383138325f33ull,0x373109636f6c2e09ull,0x090a300937383109ull,0x636e79732e726162ull,
0x6f6d090a3b300920ull,0x2509203233752e76ull,0x0a3b30202c313272ull,0x71652e7074657309ull,
0x702509203233732eull,0x202c357225202c32ull,0x40090a3b31327225ull,0x2061726220327025ull,
0x35325f335f4c2409ull,0x2e646c090a3b3236ull,0x752e646572616873ull,0x3232722509203233ull,
0x2b386472255b202cull,0x746573090a3b5d30ull,0x3233752e71652e70ull,0x25202c3370250920ull,
0x367225202c323272ull,0x2033702540090a3bull,0x5f4c240920617262ull,0x0a3b363033325f33ull,
0x3635325f335f4c24ull,0x636f6c2e090a3a32ull,0x0930393109373109ull,0x61702e646c090a30ull,
0x203436752e6d6172ull,0x5b202c3964722509ull,0x6170616475635f5full,0x7238325a5f5f6d72ull,
0x6144726564726f65ull,0x6e6946646e416174ull,0x6174536c6c654364ull,0x6e69753550447472ull,
0x616f6c6636503274ull,0x5f32535f32533474ull,0x65635f6a505f3253ull,0x5d74726174536c6cull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3031647225ull,0x6c756d090a3b3672ull,
0x203436752e6f6c2eull,0x202c313164722509ull,0x34202c3031647225ull,0x752e646461090a3bull,
0x3164722509203436ull,0x2c39647225202c32ull,0x0a3b313164722520ull,0x626f6c672e747309ull,
0x09203233752e6c61ull,0x302b32316472255bull,0x0a3b357225202c5dull,0x3033325f335f4c24ull,
0x2e766f6d090a3a36ull,0x3272250920323373ull,0x0a3b377225202c33ull,0x3233732e766f6d09ull,
0x202c343272250920ull,0x2e766f6d090a3b30ull,0x3272250920323373ull,0x6d090a3b30202c35ull,
0x09203233732e766full,0x3b30202c36327225ull,0x64312e786574090aull,0x2e3233662e34762eull,
0x3166257b20323373ull,0x3366252c3266252cull,0x6f5b2c7d3466252cull,0x786554736f50646cull,
0x252c333272257b2cull,0x353272252c343272ull,0x3b5d7d363272252cull,0x3109636f6c2e090aull,
0x0a30093439310937ull,0x3233662e766f6d09ull,0x25202c3566250920ull,0x766f6d090a3b3166ull,
0x662509203233662eull,0x0a3b326625202c36ull,0x3233662e766f6d09ull,0x25202c3766250920ull,
0x766f6d090a3b3366ull,0x662509203233662eull,0x0a3b346625202c38ull,0x3233732e766f6d09ull,
0x202c373272250920ull,0x6f6d090a3b377225ull,0x2509203233732e76ull,0x0a3b30202c383272ull,
0x3233732e766f6d09ull,0x202c393272250920ull,0x2e766f6d090a3b30ull,0x3372250920323373ull,
0x74090a3b30202c30ull,0x34762e64312e7865ull,0x3233732e3233662eull,0x66252c3966257b20ull,
0x2c313166252c3031ull,0x6f5b2c7d32316625ull,0x7865546c6556646cull,0x252c373272257b2cull,
0x393272252c383272ull,0x3b5d7d303372252cull,0x3109636f6c2e090aull,0x0a30093539310937ull,
0x3233662e766f6d09ull,0x202c333166250920ull,0x6f6d090a3b396625ull,0x2509203233662e76ull,
0x316625202c343166ull,0x2e766f6d090a3b30ull,0x3166250920323366ull,0x3b31316625202c35ull,
0x33662e766f6d090aull,0x2c36316625092032ull,0x090a3b3231662520ull,0x09373109636f6c2eull,
0x62090a3009373931ull,0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3939310937310963ull,
0x2e6c756d090a3009ull,0x09203436752e6f6cull,0x25202c3331647225ull,0x3b3631202c316472ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5b202c3431647225ull,0x6170616475635f5full,
0x7238325a5f5f6d72ull,0x6144726564726f65ull,0x6e6946646e416174ull,0x6174536c6c654364ull,
0x6e69753550447472ull,0x616f6c6636503274ull,0x5f32535f32533474ull,0x6f735f6a505f3253ull,
0x5d736f5064657472ull,0x752e646461090a3bull,0x3164722509203436ull,0x3431647225202c35ull,
0x3b3331647225202cull,0x6f6c672e7473090aull,0x662e34762e6c6162ull,0x6472255b09203233ull,
0x7b202c5d302b3531ull,0x2c3666252c356625ull,0x7d3866252c376625ull,0x09636f6c2e090a3bull,
0x3009303032093731ull,0x7261702e646c090aull,0x09203436752e6d61ull,0x5b202c3631647225ull,
0x6170616475635f5full,0x7238325a5f5f6d72ull,0x6144726564726f65ull,0x6e6946646e416174ull,
0x6174536c6c654364ull,0x6e69753550447472ull,0x616f6c6636503274ull,0x5f32535f32533474ull,
0x6f735f6a505f3253ull,0x5d6c655664657472ull,0x752e646461090a3bull,0x3164722509203436ull,
0x3631647225202c37ull,0x3b3331647225202cull,0x6f6c672e7473090aull,0x662e34762e6c6162ull,
0x6472255b09203233ull,0x7b202c5d302b3731ull,0x3166252c33316625ull,0x252c353166252c34ull,
0x2e090a3b7d363166ull,0x3209373109636f6cull,0x7865090a30093230ull,0x57444c240a3b7469ull,
0x38325a5f5f646e65ull,0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,
0x6975355044747261ull,0x6f6c66365032746eull,0x32535f3253347461ull,0x0a3a6a505f32535full,
0x5a5f202f2f207d09ull,0x6564726f65723832ull,0x646e416174614472ull,0x6c6c6543646e6946ull,
0x3550447472617453ull,0x66365032746e6975ull,0x5f32533474616f6cull,0x6a505f32535f3253ull,
0x72746e652e090a0aull,0x6c6f63385a5f2079ull,0x663650446564696cull,0x5f30533474616f6cull,
0x35505f30535f3053ull,0x206a5032746e6975ull,0x7261702e09090a28ull,0x203436752e206d61ull,
0x6170616475635f5full,0x6f63385a5f5f6d72ull,0x3650446564696c6cull,0x30533474616f6c66ull,
0x505f30535f30535full,0x6a5032746e697535ull,0x2c736f5077656e5full,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x6c6f63385a5f5f6dull,0x663650446564696cull,
0x5f30533474616f6cull,0x35505f30535f3053ull,0x5f6a5032746e6975ull,0x0a2c6c655677656eull,
0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x6c6c6f63385a5f5full,
0x6c66365044656469ull,0x535f30533474616full,0x7535505f30535f30ull,0x6f5f6a5032746e69ull,
0x090a2c736f50646cull,0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,
0x696c6c6f63385a5full,0x6f6c663650446564ull,0x30535f3053347461ull,0x697535505f30535full,
0x6c6f5f6a5032746eull,0x09090a2c6c655664ull,0x2e206d617261702eull,0x75635f5f20343675ull,
0x5f5f6d7261706164ull,0x64696c6c6f63385aull,0x616f6c6636504465ull,0x5f30535f30533474ull,
0x6e697535505f3053ull,0x7261705f6a503274ull,0x736148656c636974ull,0x61702e09090a2c68ull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x63385a5f5f6d7261ull,0x50446564696c6c6full,
0x533474616f6c6636ull,0x5f30535f30535f30ull,0x5032746e69753550ull,0x74536c6c65635f6aull,
0x0a7b090a29747261ull,0x752e206765722e09ull,0x35383c7225203233ull,0x6765722e090a3b3eull,
0x7225203436752e20ull,0x090a3b3e39313c64ull,0x33662e206765722eull,0x3934313c66252032ull,
0x6765722e090a3b3eull,0x2520646572702e20ull,0x090a3b3e38313c70ull,0x09373109636f6c2eull,
0x4c240a3009303433ull,0x63385a5f5f314242ull,0x50446564696c6c6full,0x533474616f6c6636ull,
0x5f30535f30535f30ull,0x5032746e69753550ull,0x2e747663090a3a6aull,0x203631752e323373ull,
0x6325202c31722509ull,0x0a3b782e64696174ull,0x3233732e74766309ull,0x722509203631752eull,
0x6469746e25202c32ull,0x6c756d090a3b782eull,0x33732e6f6c2e3432ull,0x202c337225092032ull,
0x327225202c317225ull,0x752e747663090a3bull,0x09203631752e3233ull,0x697425202c347225ull,
0x6461090a3b782e64ull,0x2509203233752e64ull,0x2c337225202c3572ull,0x6d090a3b34722520ull,
0x09203233732e766full,0x357225202c367225ull,0x732e766f6d090a3bull,0x2c37722509203233ull,
0x766f6d090a3b3020ull,0x722509203233732eull,0x6d090a3b30202c38ull,0x09203233732e766full,
0x0a3b30202c397225ull,0x2e64312e78657409ull,0x732e3233662e3476ull,0x2c3166257b203233ull,
0x2c3366252c326625ull,0x6c6f5b2c7d346625ull,0x2c786554736f5064ull,0x3772252c3672257bull,
0x3972252c3872252cull,0x6f6c2e090a3b5d7dull,0x3035330937310963ull,0x2e766f6d090a3009ull,
0x3566250920323366ull,0x090a3b316625202cull,0x203233662e766f6dull,0x6625202c36662509ull,
0x2e766f6d090a3b32ull,0x3766250920323366ull,0x090a3b336625202cull,0x203233732e766f6dull,
0x25202c3031722509ull,0x766f6d090a3b3572ull,0x722509203233732eull,0x090a3b30202c3131ull,
0x203233732e766f6dull,0x30202c3231722509ull,0x732e766f6d090a3bull,0x3331722509203233ull,
0x6574090a3b30202cull,0x2e34762e64312e78ull,0x203233732e323366ull,0x3966252c3866257bull,
0x66252c303166252cull,0x646c6f5b2c7d3131ull,0x7b2c7865546c6556ull,0x3172252c30317225ull,
0x252c323172252c31ull,0x090a3b5d7d333172ull,0x09373109636f6c2eull,0x6d090a3009313533ull,
0x09203233662e766full,0x6625202c32316625ull,0x2e766f6d090a3b38ull,0x3166250920323366ull,
0x0a3b396625202c33ull,0x3233662e766f6d09ull,0x202c343166250920ull,0x6d090a3b30316625ull,
0x09203233662e766full,0x6625202c35316625ull,0x6f6c2e090a3b3131ull,0x3435330937310963ull,
0x632e646c090a3009ull,0x3233662e74736e6full,0x202c363166250920ull,0x2b736d617261705bull,
0x7573090a3b5d3635ull,0x2509203233662e62ull,0x356625202c373166ull,0x0a3b36316625202cull,
0x736e6f632e646c09ull,0x2509203233662e74ull,0x61705b202c383166ull,0x5d38362b736d6172ull,
0x662e766964090a3bull,0x203233662e6c6c75ull,0x25202c3931662509ull,0x316625202c373166ull,
0x2e747663090a3b38ull,0x2e3233662e696d72ull,0x3266250920323366ull,0x3b39316625202c30ull,
0x7a722e747663090aull,0x33662e3233732e69ull,0x2c34317225092032ull,0x090a3b3032662520ull,
0x74736e6f632e646cull,0x662509203233662eull,0x7261705b202c3132ull,0x3b5d30362b736d61ull,
0x33662e627573090aull,0x2c32326625092032ull,0x6625202c36662520ull,0x2e646c090a3b3132ull,
0x33662e74736e6f63ull,0x2c33326625092032ull,0x736d617261705b20ull,0x64090a3b5d32372bull,
0x2e6c6c75662e7669ull,0x3266250920323366ull,0x2c32326625202c34ull,0x090a3b3332662520ull,
0x2e696d722e747663ull,0x203233662e323366ull,0x25202c3532662509ull,0x7663090a3b343266ull,
0x33732e697a722e74ull,0x2509203233662e32ull,0x326625202c353172ull,0x632e646c090a3b35ull,
0x3233662e74736e6full,0x202c363266250920ull,0x2b736d617261705bull,0x7573090a3b5d3436ull,
0x2509203233662e62ull,0x376625202c373266ull,0x0a3b36326625202cull,0x736e6f632e646c09ull,
0x2509203233662e74ull,0x61705b202c383266ull,0x5d36372b736d6172ull,0x662e766964090a3bull,
0x203233662e6c6c75ull,0x25202c3932662509ull,0x326625202c373266ull,0x2e747663090a3b38ull,
0x2e3233662e696d72ull,0x3366250920323366ull,0x3b39326625202c30ull,0x7a722e747663090aull,
0x33662e3233732e69ull,0x2c36317225092032ull,0x090a3b3033662520ull,0x203233732e627573ull,
0x25202c3731722509ull,0x0a3b31202c343172ull,0x3233732e64646109ull,0x202c383172250920ull,
0x3b32202c34317225ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c31336625ull,
0x36332b736d617261ull,0x2e766f6d090a3b5dull,0x3172250920323373ull,0x090a3b312d202c39ull,
0x203233662e766f6dull,0x30202c3233662509ull,0x3030303030303066ull,0x2f09202020203b30ull,
0x766f6d090a30202full,0x662509203233662eull,0x30306630202c3333ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c34336625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x4c240a30202f2f09ull,0x343532315f345f74ull,0x6c3c2f2f200a3a36ull,
0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c34353320656e69ull,0x676e697473656e20ull,
0x203a687470656420ull,0x6172657469202c31ull,0x33203a736e6f6974ull,0x33732e766f6d090aull,
0x2c30327225092032ull,0x744c240a3b312d20ull,0x34313333315f345full,0x6f6c3c2f2f200a3aull,
0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c34353320656eull,0x20676e697473656eull,
0x32203a6874706564ull,0x746172657469202cull,0x0a33203a736e6f69ull,0x3233732e766f6d09ull,
0x202c313272250920ull,0x4c240a3b37317225ull,0x383034315f345f74ull,0x6c3c2f2f200a3a32ull,
0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c34353320656e69ull,0x676e697473656e20ull,
0x203a687470656420ull,0x6172657469202c33ull,0x33203a736e6f6974ull,0x3109636f6c2e090aull,
0x0a30093030330937ull,0x3233752e766f6d09ull,0x202c323272250920ull,0x70746573090a3b30ull,
0x203233732e746c2eull,0x7225202c31702509ull,0x32327225202c3132ull,0x2031702540090a3bull,
0x744c240920617262ull,0x36343938315f345full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34353320656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x32383034315f345full,0x6e6f632e646c090aull,0x09203233752e7473ull,
0x705b202c33327225ull,0x30342b736d617261ull,0x2e627573090a3b5dull,0x3272250920323375ull,
0x2c33327225202c34ull,0x746573090a3b3120ull,0x3233752e74672e70ull,0x25202c3270250920ull,
0x327225202c313272ull,0x32702540090a3b34ull,0x4c24092061726220ull,0x343938315f345f74ull,
0x6c3c2f2f200a3b36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c34353320656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x383034315f345f74ull,
0x732e646461090a32ull,0x3532722509203233ull,0x202c35317225202cull,0x6d090a3b30327225ull,
0x09203233752e766full,0x3b30202c36327225ull,0x6c2e70746573090aull,0x2509203233732e74ull,
0x35327225202c3370ull,0x0a3b36327225202cull,0x7262203370254009ull,0x345f744c24092061ull,
0x0a3b36343938315full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c34353320ull,0x6c6562616c206461ull,0x345f744c24206465ull,
0x090a32383034315full,0x74736e6f632e646cull,0x722509203233752eull,0x7261705b202c3732ull,
0x3b5d34342b736d61ull,0x33752e627573090aull,0x2c38327225092032ull,0x31202c3732722520ull,
0x2e70746573090a3bull,0x09203233752e7467ull,0x327225202c347025ull,0x3b38327225202c35ull,
0x622034702540090aull,0x5f744c2409206172ull,0x3b36343938315f34ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3435332065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32383034315f34ull,0x3233732e64646109ull,
0x202c393272250920ull,0x7225202c36317225ull,0x766f6d090a3b3931ull,0x722509203233752eull,
0x090a3b30202c3033ull,0x2e746c2e70746573ull,0x3570250920323373ull,0x202c39327225202cull,
0x40090a3b30337225ull,0x2061726220357025ull,0x315f345f744c2409ull,0x2f200a3b36343938ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,
0x64616568202c3435ull,0x64656c6562616c20ull,0x315f345f744c2420ull,0x646c090a32383034ull,
0x752e74736e6f632eull,0x3133722509203233ull,0x6d617261705b202cull,0x090a3b5d38342b73ull,
0x203233752e627573ull,0x25202c3233722509ull,0x0a3b31202c313372ull,0x656c2e7074657309ull,
0x702509203233752eull,0x2c39327225202c36ull,0x090a3b3233722520ull,0x6172622036702540ull,
0x315f345f4c240920ull,0x4c240a3b38393430ull,0x343938315f345f74ull,0x5f345f4c240a3a36ull,
0x200a3a3435373031ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c343533ull,0x656c6562616c2064ull,0x5f345f744c242064ull,
0x6d090a3238303431ull,0x09203233662e766full,0x6630202c35336625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3366250920323366ull,0x3030306630202c36ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c373366250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x7262090a30202f2full,0x240920696e752e61ull,
0x3835325f345f744cull,0x315f345f4c240a3bull,0x2f200a3a38393430ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3435ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x6c2e090a32383034ull,0x303109373109636full,
0x6e696d090a300934ull,0x722509203233752eull,0x39327225202c3333ull,0x0a3b32337225202cull,
0x6c2e34326c756d09ull,0x2509203233732e6full,0x337225202c343372ull,0x3b37327225202c33ull,
0x2e34326c756d090aull,0x09203233732e6f6cull,0x7225202c35337225ull,0x33327225202c3433ull,
0x752e6e696d090a3bull,0x3633722509203233ull,0x202c35327225202cull,0x6d090a3b38327225ull,
0x2e6f6c2e34326c75ull,0x3372250920323373ull,0x2c36337225202c37ull,0x090a3b3332722520ull,
0x203233732e646461ull,0x25202c3833722509ull,0x337225202c353372ull,0x2e6e696d090a3b37ull,
0x3372250920323375ull,0x2c31327225202c39ull,0x090a3b3432722520ull,0x203233732e646461ull,
0x25202c3034722509ull,0x337225202c383372ull,0x636f6c2e090a3b39ull,0x0938303309373109ull,
0x732e766f6d090a30ull,0x3134722509203233ull,0x0a3b30347225202cull,0x3233732e766f6d09ull,
0x202c323472250920ull,0x2e766f6d090a3b30ull,0x3472250920323373ull,0x6d090a3b30202c33ull,
0x09203233732e766full,0x3b30202c34347225ull,0x64312e786574090aull,0x2e3233752e34762eull,
0x3472257b20323373ull,0x252c363472252c35ull,0x383472252c373472ull,0x536c6c65635b2c7dull,
0x2c78655474726174ull,0x72252c313472257bull,0x2c333472252c3234ull,0x0a3b5d7d34347225ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34353320ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a32383034315full,
0x09373109636f6c2eull,0x6d090a3009313133ull,0x09203233732e766full,0x7225202c39347225ull,
0x766f6d090a3b3534ull,0x722509203233752eull,0x0a3b312d202c3035ull,0x656e2e7074657309ull,
0x702509203233752eull,0x2c39347225202c37ull,0x090a3b3035722520ull,0x6172622037702540ull,
0x5f345f744c240920ull,0x200a3b3833333431ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c343533ull,0x656c6562616c2064ull,
0x5f345f744c242064ull,0x6d090a3238303431ull,0x09203233662e766full,0x6630202c35336625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3366250920323366ull,
0x3030306630202c36ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x202c373366250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x7262090a30202f2full,
0x240920696e752e61ull,0x3835325f345f744cull,0x5f345f744c240a3bull,0x200a3a3833333431ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c343533ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x6c090a3238303431ull,
0x2e74736e6f632e64ull,0x3572250920323375ull,0x617261705b202c31ull,0x0a3b5d34382b736dull,
0x3233752e766f6d09ull,0x202c323572250920ull,0x70746573090a3b30ull,0x203233752e71652eull,
0x7225202c38702509ull,0x32357225202c3135ull,0x662e766f6d090a3bull,0x3833662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x30202c3933662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x30306630202c3034ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x622038702540090aull,0x5f744c2409206172ull,0x3b38353439315f34ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3435332065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32383034315f34ull,0x3233732e766f6d09ull,
0x202c333572250920ull,0x6d090a3b31357225ull,0x09203233732e766full,0x7225202c34357225ull,
0x3c2f2f200a3b3934ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x34353320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3034315f345f744cull,
0x2e766f6d090a3238ull,0x3572250920323373ull,0x3b33357225202c35ull,0x315f345f744c240aull,
0x2f200a3a32363335ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3320656e696c2079ull,
0x7473656e202c3131ull,0x7470656420676e69ull,0x7365202c34203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x766f6d090a6e776full,0x722509203233732eull,
0x34357225202c3635ull,0x732e766f6d090a3bull,0x3735722509203233ull,0x6f6d090a3b30202cull,
0x2509203233732e76ull,0x0a3b30202c383572ull,0x3233732e766f6d09ull,0x202c393572250920ull,
0x2e786574090a3b30ull,0x33752e34762e6431ull,0x257b203233732e32ull,0x313672252c303672ull,
0x72252c323672252cull,0x7261705b2c7d3336ull,0x736148656c636974ull,0x72257b2c78655468ull,
0x2c373572252c3635ull,0x3572252c38357225ull,0x2f2f200a3b5d7d39ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x313320656e696c20ull,0x2064616568202c31ull,
0x2064656c6562616cull,0x35315f345f744c24ull,0x6f6c2e090a323633ull,0x3831330937310963ull,
0x2e766f6d090a3009ull,0x3672250920323373ull,0x3b30367225202c34ull,0x3109636f6c2e090aull,
0x0a30093931330937ull,0x656e2e7074657309ull,0x702509203233752eull,0x2c30347225202c39ull,
0x090a3b3436722520ull,0x6172622039702540ull,0x5f345f744c240920ull,0x200a3b3035383431ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c313133ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x73090a3236333531ull,
0x752e71652e707465ull,0x3031702509203233ull,0x202c34357225202cull,0x2540090a3b357225ull,
0x2061726220303170ull,0x315f345f744c2409ull,0x2f200a3b38313635ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3131ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x6f6d090a32363335ull,0x2509203233732e76ull,
0x357225202c353672ull,0x2e766f6d090a3b34ull,0x3672250920323373ull,0x6d090a3b30202c36ull,
0x09203233732e766full,0x3b30202c37367225ull,0x33732e766f6d090aull,0x2c38367225092032ull,
0x786574090a3b3020ull,0x662e34762e64312eull,0x7b203233732e3233ull,0x3466252c31346625ull,
0x252c333466252c32ull,0x6c6f5b2c7d343466ull,0x2c786554736f5064ull,0x72252c353672257bull,
0x2c373672252c3636ull,0x0a3b5d7d38367225ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31313320ull,0x6c6562616c206461ull,
0x345f744c24206465ull,0x090a32363335315full,0x09373109636f6c2eull,0x6d090a3009323233ull,
0x09203233662e766full,0x6625202c35346625ull,0x766f6d090a3b3134ull,0x662509203233662eull,
0x32346625202c3634ull,0x662e766f6d090a3bull,0x3734662509203233ull,0x0a3b33346625202cull,
0x3233732e766f6d09ull,0x202c393672250920ull,0x6d090a3b34357225ull,0x09203233732e766full,
0x3b30202c30377225ull,0x33732e766f6d090aull,0x2c31377225092032ull,0x766f6d090a3b3020ull,
0x722509203233732eull,0x090a3b30202c3237ull,0x762e64312e786574ull,0x33732e3233662e34ull,
0x2c383466257b2032ull,0x3566252c39346625ull,0x2c7d313566252c30ull,0x546c6556646c6f5bull,
0x393672257b2c7865ull,0x72252c303772252cull,0x7d323772252c3137ull,0x6c3c2f2f200a3b5dull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c31313320656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363335315f345f74ull,0x09636f6c2e090a32ull,
0x3009333233093731ull,0x33662e766f6d090aull,0x2c32356625092032ull,0x090a3b3834662520ull,
0x203233662e766f6dull,0x25202c3335662509ull,0x6f6d090a3b393466ull,0x2509203233662e76ull,
0x356625202c343566ull,0x636f6c2e090a3b30ull,0x0936313209373109ull,0x662e627573090a30ull,
0x3535662509203233ull,0x202c36346625202cull,0x7573090a3b366625ull,0x2509203233662e62ull,
0x346625202c363566ull,0x0a3b356625202c35ull,0x3233662e62757309ull,0x202c373566250920ull,
0x6625202c37346625ull,0x2e646461090a3b37ull,0x3566250920323366ull,0x2c31336625202c38ull,
0x090a3b3133662520ull,0x203233662e6c756dull,0x25202c3935662509ull,0x356625202c353566ull,
0x2e64616d090a3b35ull,0x3666250920323366ull,0x2c36356625202c30ull,0x25202c3635662520ull,
0x616d090a3b393566ull,0x2509203233662e64ull,0x356625202c313666ull,0x2c37356625202c37ull,
0x090a3b3036662520ull,0x7070612e74727173ull,0x203233662e786f72ull,0x25202c3236662509ull,
0x6573090a3b313666ull,0x33662e74672e7074ull,0x2c31317025092032ull,0x25202c3835662520ull,
0x2140090a3b323666ull,0x6172622031317025ull,0x5f345f744c240920ull,0x200a3b3638333631ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c313133ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x2e090a3236333531ull,
0x3209373109636f6cull,0x7573090a30093033ull,0x2509203233662e62ull,0x356625202c333666ull,
0x3b32316625202c32ull,0x33662e627573090aull,0x2c34366625092032ull,0x25202c3335662520ull,
0x7573090a3b333166ull,0x2509203233662e62ull,0x356625202c353666ull,0x3b34316625202c34ull,
0x70612e706372090aull,0x3233662e786f7270ull,0x202c363666250920ull,0x6d090a3b32366625ull,
0x09203233662e6c75ull,0x6625202c37366625ull,0x36366625202c3535ull,0x662e6c756d090a3bull,
0x3836662509203233ull,0x202c36356625202cull,0x6d090a3b36366625ull,0x09203233662e6c75ull,
0x6625202c39366625ull,0x36366625202c3735ull,0x662e6c756d090a3bull,0x3037662509203233ull,
0x202c34366625202cull,0x6d090a3b37366625ull,0x09203233662e6461ull,0x6625202c31376625ull,
0x33366625202c3836ull,0x0a3b30376625202cull,0x3233662e64616d09ull,0x202c323766250920ull,
0x6625202c39366625ull,0x31376625202c3536ull,0x662e6c756d090a3bull,0x3337662509203233ull,
0x202c38366625202cull,0x73090a3b32376625ull,0x09203233662e6275ull,0x6625202c34376625ull,
0x33376625202c3336ull,0x662e6c756d090a3bull,0x3537662509203233ull,0x202c37366625202cull,
0x73090a3b32376625ull,0x09203233662e6275ull,0x6625202c36376625ull,0x35376625202c3436ull,
0x662e6c756d090a3bull,0x3737662509203233ull,0x202c39366625202cull,0x73090a3b32376625ull,
0x09203233662e6275ull,0x6625202c38376625ull,0x37376625202c3536ull,0x09636f6c2e090a3bull,
0x3009393332093731ull,0x33662e627573090aull,0x2c39376625092032ull,0x25202c3835662520ull,
0x646c090a3b323666ull,0x662e74736e6f632eull,0x3038662509203233ull,0x6d617261705b202cull,
0x090a3b5d38382b73ull,0x203233662e6c756dull,0x25202c3138662509ull,0x376625202c303866ull,
0x632e646c090a3b39ull,0x3233662e74736e6full,0x202c323866250920ull,0x2b736d617261705bull,
0x6c090a3b5d303031ull,0x2e74736e6f632e64ull,0x3866250920323366ull,0x617261705b202c33ull,
0x0a3b5d36392b736dull,0x736e6f632e646c09ull,0x2509203233662e74ull,0x61705b202c343866ull,
0x5d32392b736d6172ull,0x662e6c756d090a3bull,0x3538662509203233ull,0x202c38366625202cull,
0x6d090a3b31386625ull,0x09203233662e6c75ull,0x6625202c36386625ull,0x34386625202c3336ull,
0x662e627573090a3bull,0x3738662509203233ull,0x202c36386625202cull,0x6d090a3b35386625ull,
0x09203233662e6461ull,0x6625202c38386625ull,0x33386625202c3437ull,0x0a3b37386625202cull,
0x3233662e64616d09ull,0x202c393866250920ull,0x6625202c36356625ull,0x38386625202c3238ull,
0x662e6c756d090a3bull,0x3039662509203233ull,0x202c37366625202cull,0x6d090a3b31386625ull,
0x09203233662e6c75ull,0x6625202c31396625ull,0x34386625202c3436ull,0x662e627573090a3bull,
0x3239662509203233ull,0x202c31396625202cull,0x6d090a3b30396625ull,0x09203233662e6461ull,
0x6625202c33396625ull,0x33386625202c3637ull,0x0a3b32396625202cull,0x3233662e64616d09ull,
0x202c343966250920ull,0x6625202c35356625ull,0x33396625202c3238ull,0x662e6c756d090a3bull,
0x3539662509203233ull,0x202c39366625202cull,0x6d090a3b31386625ull,0x09203233662e6c75ull,
0x6625202c36396625ull,0x34386625202c3536ull,0x662e627573090a3bull,0x3739662509203233ull,
0x202c36396625202cull,0x6d090a3b35396625ull,0x09203233662e6461ull,0x6625202c38396625ull,
0x33386625202c3837ull,0x0a3b37396625202cull,0x3233662e64616d09ull,0x202c393966250920ull,
0x6625202c37356625ull,0x38396625202c3238ull,0x752e617262090a3bull,0x5f744c240920696eull,
0x3b30333136315f34ull,0x315f345f744c240aull,0x2f200a3a36383336ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3131ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x6f6d090a32363335ull,0x2509203233662e76ull,
0x306630202c393966ull,0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,
0x3439662509203233ull,0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,
0x203233662e766f6dull,0x30202c3938662509ull,0x3030303030303066ull,0x2f09202020203b30ull,
0x5f744c240a30202full,0x3a30333136315f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3131332065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32363335315f34ull,0x373109636f6c2e09ull,0x090a300937323309ull,
0x203233662e646461ull,0x25202c3034662509ull,0x346625202c393866ull,0x2e646461090a3b30ull,
0x3366250920323366ull,0x2c34396625202c39ull,0x090a3b3933662520ull,0x203233662e646461ull,
0x25202c3833662509ull,0x336625202c393966ull,0x345f744c240a3b38ull,0x0a3a38313635315full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c31313320ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a32363335315full,
0x09373109636f6c2eull,0x61090a3009363133ull,0x09203233752e6464ull,0x7225202c34357225ull,
0x090a3b31202c3435ull,0x203233752e646461ull,0x25202c3337722509ull,0x357225202c393472ull,
0x70746573090a3b31ull,0x203233752e656e2eull,0x25202c3231702509ull,0x377225202c343572ull,
0x31702540090a3b33ull,0x2409206172622032ull,0x3335315f345f744cull,0x3c2f2f200a3b3236ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x34353320656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3034315f345f744cull,0x2e617262090a3238ull,
0x744c240920696e75ull,0x30353834315f345full,0x5f345f744c240a3bull,0x200a3a3835343931ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c343533ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x4c240a3238303431ull,
0x353834315f345f74ull,0x345f744c240a3a30ull,0x2f200a3a3431355full,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3435ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x6c2e090a32383034ull,0x323309373109636full,
0x766f6d090a300939ull,0x662509203233662eull,0x30346625202c3733ull,0x662e766f6d090a3bull,
0x3633662509203233ull,0x0a3b39336625202cull,0x3233662e766f6d09ull,0x202c353366250920ull,
0x4c240a3b38336625ull,0x3a3835325f345f74ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3435332065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32383034315f34ull,0x373109636f6c2e09ull,0x090a300933363309ull,
0x203233662e646461ull,0x25202c3433662509ull,0x336625202c373366ull,0x2e646461090a3b34ull,
0x3366250920323366ull,0x2c36336625202c33ull,0x090a3b3333662520ull,0x203233662e646461ull,
0x25202c3233662509ull,0x336625202c353366ull,0x2e646461090a3b32ull,0x3272250920323373ull,
0x2c31327225202c31ull,0x746573090a3b3120ull,0x3233732e656e2e70ull,0x202c333170250920ull,
0x7225202c31327225ull,0x702540090a3b3831ull,0x0920617262203331ull,0x34315f345f744c24ull,
0x2f2f200a3b323830ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x353320656e696c20ull,0x2064616568202c34ull,0x2064656c6562616cull,0x33315f345f744c24ull,
0x646461090a343133ull,0x722509203233732eull,0x30327225202c3032ull,0x6f6d090a3b31202cull,
0x2509203233752e76ull,0x0a3b32202c343772ull,0x656e2e7074657309ull,0x702509203233732eull,
0x30327225202c3431ull,0x0a3b34377225202cull,0x6220343170254009ull,0x5f744c2409206172ull,
0x3b34313333315f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3435332065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a36343532315f34ull,0x3233732e64646109ull,0x202c393172250920ull,0x3b31202c39317225ull,
0x33752e766f6d090aull,0x2c35377225092032ull,0x746573090a3b3220ull,0x3233732e656e2e70ull,
0x202c353170250920ull,0x7225202c39317225ull,0x702540090a3b3537ull,0x0920617262203531ull,
0x32315f345f744c24ull,0x6c2e090a3b363435ull,0x313209373109636full,0x2e646c090a300936ull,
0x33662e74736e6f63ull,0x3030316625092032ull,0x6d617261705b202cull,0x090a3b5d36312b73ull,
0x203233662e646461ull,0x202c313031662509ull,0x25202c3030316625ull,0x646c090a3b313366ull,
0x662e74736e6f632eull,0x3031662509203233ull,0x617261705b202c32ull,0x090a3b5d342b736dull,
0x203233662e627573ull,0x202c333031662509ull,0x25202c3230316625ull,0x2e646c090a3b3666ull,
0x33662e74736e6f63ull,0x3430316625092032ull,0x6d617261705b202cull,0x73090a3b5d302b73ull,
0x09203233662e6275ull,0x25202c3530316625ull,0x6625202c34303166ull,0x632e646c090a3b35ull,
0x3233662e74736e6full,0x2c36303166250920ull,0x736d617261705b20ull,0x7573090a3b5d382bull,
0x2509203233662e62ull,0x6625202c37303166ull,0x376625202c363031ull,0x662e6c756d090a3bull,
0x3031662509203233ull,0x3330316625202c38ull,0x3b3330316625202cull,0x33662e64616d090aull,
0x3930316625092032ull,0x2c3530316625202cull,0x202c353031662520ull,0x090a3b3830316625ull,
0x203233662e64616dull,0x202c303131662509ull,0x25202c3730316625ull,0x6625202c37303166ull,
0x7173090a3b393031ull,0x6f727070612e7472ull,0x2509203233662e78ull,0x6625202c31313166ull,
0x6573090a3b303131ull,0x33662e74672e7074ull,0x2c36317025092032ull,0x202c313031662520ull,
0x090a3b3131316625ull,0x6220363170252140ull,0x5f744c2409206172ull,0x3b32323937315f34ull,
0x3109636f6c2e090aull,0x0a30093033320937ull,0x3233662e67656e09ull,0x2c32313166250920ull,
0x090a3b3231662520ull,0x203233662e67656eull,0x202c333131662509ull,0x72090a3b34316625ull,
0x6f727070612e7063ull,0x2509203233662e78ull,0x6625202c34313166ull,0x756d090a3b313131ull,
0x2509203233662e6cull,0x6625202c35313166ull,0x316625202c333031ull,0x6c756d090a3b3431ull,
0x662509203233662eull,0x316625202c363131ull,0x31316625202c3530ull,0x2e6c756d090a3b34ull,
0x3166250920323366ull,0x30316625202c3731ull,0x3431316625202c37ull,0x662e6c756d090a3bull,
0x3131662509203233ull,0x3531316625202c38ull,0x0a3b33316625202cull,0x3233662e67656e09ull,
0x2c39313166250920ull,0x0a3b383131662520ull,0x3233662e64616d09ull,0x2c30323166250920ull,
0x202c363131662520ull,0x25202c3231316625ull,0x6d090a3b39313166ull,0x09203233662e6461ull,
0x25202c3132316625ull,0x6625202c37313166ull,0x316625202c333131ull,0x6c756d090a3b3032ull,
0x662509203233662eull,0x316625202c323231ull,0x32316625202c3631ull,0x2e6c756d090a3b31ull,
0x3166250920323366ull,0x31316625202c3332ull,0x3132316625202c35ull,0x662e6c756d090a3bull,
0x3231662509203233ull,0x3731316625202c34ull,0x3b3132316625202cull,0x3109636f6c2e090aull,
0x0a30093733320937ull,0x3233662e62757309ull,0x2c35323166250920ull,0x202c313031662520ull,
0x090a3b3131316625ull,0x74736e6f632e646cull,0x662509203233662eull,0x61705b202c363231ull,
0x5d38382b736d6172ull,0x662e6c756d090a3bull,0x3231662509203233ull,0x3632316625202c37ull,
0x3b3532316625202cull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x5b202c3832316625ull,
0x392b736d61726170ull,0x2e646c090a3b5d36ull,0x33662e74736e6f63ull,0x3932316625092032ull,
0x6d617261705b202cull,0x090a3b5d32392b73ull,0x203233662e6c756dull,0x202c303331662509ull,
0x25202c3631316625ull,0x6d090a3b37323166ull,0x09203233662e6461ull,0x25202c3133316625ull,
0x316625202c323166ull,0x33316625202c3932ull,0x2e646461090a3b30ull,0x3166250920323366ull,
0x32316625202c3233ull,0x3b3232316625202cull,0x33662e64616d090aull,0x3333316625092032ull,
0x2c3832316625202cull,0x202c323331662520ull,0x090a3b3133316625ull,0x203233662e67656eull,
0x202c343331662509ull,0x090a3b3333316625ull,0x203233662e6c756dull,0x202c353331662509ull,
0x25202c3531316625ull,0x6d090a3b37323166ull,0x09203233662e6461ull,0x25202c3633316625ull,
0x316625202c333166ull,0x33316625202c3932ull,0x2e646461090a3b35ull,0x3166250920323366ull,
0x32316625202c3733ull,0x3b33316625202c33ull,0x33662e64616d090aull,0x3833316625092032ull,
0x2c3832316625202cull,0x202c373331662520ull,0x090a3b3633316625ull,0x203233662e67656eull,
0x202c393331662509ull,0x090a3b3833316625ull,0x203233662e6c756dull,0x202c303431662509ull,
0x25202c3731316625ull,0x6d090a3b37323166ull,0x09203233662e6461ull,0x25202c3134316625ull,
0x316625202c343166ull,0x34316625202c3932ull,0x2e646461090a3b30ull,0x3166250920323366ull,
0x32316625202c3234ull,0x3b34316625202c34ull,0x33662e64616d090aull,0x3334316625092032ull,
0x2c3832316625202cull,0x202c323431662520ull,0x090a3b3134316625ull,0x203233662e67656eull,
0x202c343431662509ull,0x090a3b3334316625ull,0x20696e752e617262ull,0x315f345f744c2409ull,
0x4c240a3b36363637ull,0x323937315f345f74ull,0x2e766f6d090a3a32ull,0x3166250920323366ull,
0x30306630202c3434ull,0x203b303030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x2c39333166250920ull,0x3030303030663020ull,0x092020203b303030ull,0x6f6d090a30202f2full,
0x2509203233662e76ull,0x6630202c34333166ull,0x3030303030303030ull,0x202f2f092020203bull,
0x5f345f744c240a30ull,0x090a3a3636363731ull,0x09373109636f6c2eull,0x61090a3009323733ull,
0x09203233662e6464ull,0x6625202c34336625ull,0x336625202c343331ull,0x2e646461090a3b34ull,
0x3366250920323366ull,0x3933316625202c33ull,0x0a3b33336625202cull,0x3233662e64646109ull,
0x202c323366250920ull,0x25202c3434316625ull,0x6c2e090a3b323366ull,0x373309373109636full,
0x2e646c090a300936ull,0x36752e6d61726170ull,0x2c31647225092034ull,0x616475635f5f5b20ull,
0x385a5f5f6d726170ull,0x446564696c6c6f63ull,0x3474616f6c663650ull,0x30535f30535f3053ull,
0x32746e697535505full,0x69747261705f6a50ull,0x5d68736148656c63ull,0x752e747663090a3bull,
0x09203233732e3436ull,0x7225202c32647225ull,0x2e6c756d090a3b35ull,0x09203436752e6f6cull,
0x7225202c33647225ull,0x090a3b38202c3264ull,0x203436752e646461ull,0x25202c3464722509ull,
0x647225202c316472ull,0x762e646c090a3b33ull,0x2e656c6974616c6full,0x762e6c61626f6c67ull,
0x7b09203233752e32ull,0x3772252c36377225ull,0x6472255b202c7d37ull,0x6d090a3b5d302b34ull,
0x09203233732e766full,0x7225202c38377225ull,0x766f6d090a3b3637ull,0x722509203233732eull,
0x37377225202c3937ull,0x09636f6c2e090a3bull,0x3009373733093731ull,0x7261702e646c090aull,
0x09203436752e6d61ull,0x5f5b202c35647225ull,0x726170616475635full,0x6c6f63385a5f5f6dull,
0x663650446564696cull,0x5f30533474616f6cull,0x35505f30535f3053ull,0x5f6a5032746e6975ull,
0x3b5d6c655677656eull,0x33662e646461090aull,0x3534316625092032ull,0x202c32316625202cull,
0x6d090a3b34336625ull,0x09203233732e766full,0x7225202c30387225ull,0x747663090a3b3937ull,
0x3233752e3436752eull,0x202c366472250920ull,0x6d090a3b30387225ull,0x36752e6f6c2e6c75ull,
0x2c37647225092034ull,0x31202c3664722520ull,0x2e646461090a3b36ull,0x6472250920343675ull,
0x2c35647225202c38ull,0x090a3b3764722520ull,0x61626f6c672e7473ull,0x5b09203233662e6cull,
0x2c5d302b38647225ull,0x0a3b353431662520ull,0x3233662e64646109ull,0x2c36343166250920ull,
0x25202c3331662520ull,0x6f6d090a3b333366ull,0x2509203233732e76ull,0x377225202c313872ull,
0x2e747663090a3b39ull,0x203233752e343675ull,0x25202c3964722509ull,0x756d090a3b313872ull,
0x3436752e6f6c2e6cull,0x2c30316472250920ull,0x31202c3964722520ull,0x2e646461090a3b36ull,
0x6472250920343675ull,0x35647225202c3131ull,0x3b3031647225202cull,0x6f6c672e7473090aull,
0x203233662e6c6162ull,0x2b31316472255b09ull,0x34316625202c5d34ull,0x2e646461090a3b36ull,
0x3166250920323366ull,0x34316625202c3734ull,0x0a3b32336625202cull,0x3233732e766f6d09ull,
0x202c323872250920ull,0x63090a3b39377225ull,0x752e3436752e7476ull,0x3164722509203233ull,
0x3b32387225202c32ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c333164ull,
0x0a3b3631202c3231ull,0x3436752e64646109ull,0x2c34316472250920ull,0x25202c3564722520ull,
0x73090a3b33316472ull,0x6c61626f6c672e74ull,0x255b09203233662eull,0x2c5d382b34316472ull,
0x0a3b373431662520ull,0x3233732e766f6d09ull,0x202c333872250920ull,0x63090a3b39377225ull,
0x752e3436752e7476ull,0x3164722509203233ull,0x3b33387225202c35ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c363164ull,0x0a3b3631202c3531ull,0x3436752e64646109ull,
0x2c37316472250920ull,0x25202c3564722520ull,0x73090a3b36316472ull,0x6c61626f6c672e74ull,
0x255b09203233662eull,0x5d32312b37316472ull,0x0a3b35316625202cull,0x373109636f6c2e09ull,
0x090a300931383309ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,0x6564696c6c6f6338ull,
0x74616f6c66365044ull,0x535f30535f305334ull,0x746e697535505f30ull,0x207d090a3a6a5032ull,
0x6f63385a5f202f2full,0x3650446564696c6cull,0x30533474616f6c66ull,0x505f30535f30535full,
0x6a5032746e697535ull,0x72746e652e090a0aull,0x646152385a5f2079ull,0x3231506d75537869ull,
0x65756c615679654bull,0x206a6a6a72696150ull,0x7261702e09090a28ull,0x203436752e206d61ull,
0x6170616475635f5full,0x6152385a5f5f6d72ull,0x31506d7553786964ull,0x756c615679654b32ull,
0x6a6a6a7269615065ull,0x0a2c61746144705full,0x6d617261702e0909ull,0x5f5f203233752e20ull,
0x6d72617061647563ull,0x69646152385a5f5full,0x4b3231506d755378ull,0x5065756c61567965ull,
0x655f6a6a6a726961ull,0x2c73746e656d656cull,0x617261702e09090aull,0x5f203233752e206dull,
0x726170616475635full,0x646152385a5f5f6dull,0x3231506d75537869ull,0x65756c615679654bull,
0x5f6a6a6a72696150ull,0x73746e656d656c65ull,0x6465646e756f725full,0x323730335f6f745full,
0x7261702e09090a2cull,0x203233752e206d61ull,0x6170616475635f5full,0x6152385a5f5f6d72ull,
0x31506d7553786964ull,0x756c615679654b32ull,0x6a6a6a7269615065ull,0x0a2974666968735full,
0x6765722e090a7b09ull,0x7225203631752e20ull,0x2e090a3b3e333c68ull,0x3233752e20676572ull,
0x3e3638313c722520ull,0x206765722e090a3bull,0x647225203436752eull,0x2e090a3b3e30353cull,
0x6572702e20676572ull,0x3e31343c70252064ull,0x09636f6c2e090a3bull,0x3009313031093831ull,
0x5f5f3142424c240aull,0x537869646152385aull,0x79654b3231506d75ull,0x69615065756c6156ull,
0x2e090a3a6a6a6a72ull,0x3109383109636f6cull,0x7663090a30093330ull,0x31752e3233752e74ull,
0x202c317225092036ull,0x0a3b782e64697425ull,0x3233732e766f6d09ull,0x25202c3272250920ull,
0x766f6d090a3b3172ull,0x722509203233752eull,0x3b33323031202c33ull,0x672e70746573090aull,
0x2509203233752e74ull,0x2c317225202c3170ull,0x40090a3b33722520ull,0x2061726220317025ull,
0x325f355f744c2409ull,0x6d090a3b32383430ull,0x09203436752e766full,0x5273202c31647225ull,
0x3b6d755378696461ull,0x33752e766f6d090aull,0x202c347225092032ull,0x73090a3b37383031ull,
0x09203233752e6275ull,0x347225202c357225ull,0x090a3b317225202cull,0x203233732e726873ull,
0x7225202c36722509ull,0x090a3b3133202c35ull,0x203233732e766f6dull,0x3336202c37722509ull,
0x622e646e61090a3bull,0x2c38722509203233ull,0x7225202c36722520ull,0x2e646461090a3b37ull,
0x3972250920323373ull,0x25202c387225202cull,0x726873090a3b3572ull,0x722509203233732eull,
0x2c397225202c3031ull,0x747663090a3b3620ull,0x3233752e3436752eull,0x202c326472250920ull,
0x756d090a3b317225ull,0x3436752e6f6c2e6cull,0x202c336472250920ull,0x3b34202c32647225ull,
0x36752e646461090aull,0x2c34647225092034ull,0x25202c3164722520ull,0x6f6d090a3b336472ull,
0x2509203233732e76ull,0x317225202c313172ull,0x355f744c240a3b30ull,0x0a3a34393930325full,
0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c33303120ull,
0x656420676e697473ull,0x202c31203a687470ull,0x6574616d69747365ull,0x7461726574692064ull,
0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,0x3109383109636f6cull,0x6f6d090a30093830ull,
0x2509203233752e76ull,0x0a3b30202c323172ull,0x726168732e747309ull,0x09203233752e6465ull,
0x5d302b346472255bull,0x0a3b32317225202cull,0x3233752e64646109ull,0x25202c3272250920ull,
0x0a3b3436202c3272ull,0x3436752e64646109ull,0x202c346472250920ull,0x3532202c34647225ull,
0x2e766f6d090a3b36ull,0x3172250920323375ull,0x3b33323031202c33ull,0x6c2e70746573090aull,
0x2509203233752e65ull,0x2c327225202c3270ull,0x090a3b3331722520ull,0x6172622032702540ull,
0x5f355f744c240920ull,0x240a3b3439393032ull,0x3430325f355f744cull,0x766f6d090a3a3238ull,
0x722509203436752eull,0x64615273202c3164ull,0x090a3b6d75537869ull,0x09383109636f6c2eull,
0x62090a3009363331ull,0x20636e79732e7261ull,0x646e61090a3b3009ull,0x722509203233622eull,
0x2c317225202c3431ull,0x6873090a3b353120ull,0x2509203233752e72ull,0x317225202c353172ull,
0x6f6d090a3b34202cull,0x2509203631752e76ull,0x746325202c316872ull,0x090a3b782e646961ull,
0x656469772e6c756dull,0x722509203631752eull,0x31687225202c3631ull,0x646c090a3b34202cull,
0x752e6d617261702eull,0x3731722509203233ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x7553786964615238ull,0x5679654b3231506dull,0x7269615065756c61ull,0x6d656c655f6a6a6aull,
0x756f725f73746e65ull,0x5f6f745f6465646eull,0x090a3b5d32373033ull,0x203233752e766f6dull,
0x2d202c3831722509ull,0x3735353631333431ull,0x6c756d090a3b3536ull,0x203233752e69682eull,
0x25202c3931722509ull,0x317225202c373172ull,0x2e726873090a3b38ull,0x3272250920323375ull,
0x2c39317225202c30ull,0x646461090a3b3720ull,0x722509203233752eull,0x35317225202c3132ull,
0x0a3b36317225202cull,0x2e6f6c2e6c756d09ull,0x3272250920323375ull,0x2c30327225202c32ull,
0x090a3b3132722520ull,0x203233752e646461ull,0x25202c3332722509ull,0x327225202c343172ull,
0x2e766f6d090a3b32ull,0x3272250920323373ull,0x0a3b33327225202cull,0x3233752e64646109ull,
0x202c343272250920ull,0x7225202c30327225ull,0x746573090a3b3232ull,0x3233752e65672e70ull,
0x25202c3370250920ull,0x327225202c333272ull,0x33702540090a3b34ull,0x4c24092061726220ull,
0x303531325f355f74ull,0x2e627573090a3b36ull,0x3272250920323375ull,0x2c30327225202c35ull,
0x090a3b3431722520ull,0x203233752e646461ull,0x25202c3632722509ull,0x3b3531202c353272ull,
0x33732e726873090aull,0x2c37327225092032ull,0x33202c3632722520ull,0x2e766f6d090a3b31ull,
0x3272250920323373ull,0x090a3b3531202c38ull,0x203233622e646e61ull,0x25202c3932722509ull,
0x327225202c373272ull,0x2e646461090a3b38ull,0x3372250920323373ull,0x2c39327225202c30ull,
0x090a3b3632722520ull,0x203233732e726873ull,0x25202c3133722509ull,0x0a3b34202c303372ull,
0x3233752e766f6d09ull,0x202c323372250920ull,0x70746573090a3b30ull,0x203233752e71652eull,
0x7225202c34702509ull,0x32337225202c3431ull,0x752e766f6d090a3bull,0x3333722509203233ull,
0x6573090a3b31202cull,0x33752e71652e7074ull,0x202c357025092032ull,0x7225202c34317225ull,
0x766f6d090a3b3333ull,0x722509203233752eull,0x090a3b32202c3433ull,0x2e71652e70746573ull,
0x3670250920323375ull,0x202c34317225202cull,0x6d090a3b34337225ull,0x09203233752e766full,
0x3b33202c35337225ull,0x652e70746573090aull,0x2509203233752e71ull,0x34317225202c3770ull,
0x0a3b35337225202cull,0x3233752e766f6d09ull,0x202c363372250920ull,0x70746573090a3b34ull,
0x203233752e71652eull,0x7225202c38702509ull,0x36337225202c3431ull,0x752e766f6d090a3bull,
0x3733722509203233ull,0x6573090a3b35202cull,0x33752e71652e7074ull,0x202c397025092032ull,
0x7225202c34317225ull,0x766f6d090a3b3733ull,0x722509203233752eull,0x090a3b36202c3833ull,
0x2e71652e70746573ull,0x3170250920323375ull,0x2c34317225202c30ull,0x090a3b3833722520ull,
0x203233752e766f6dull,0x37202c3933722509ull,0x2e70746573090a3bull,0x09203233752e7165ull,
0x7225202c31317025ull,0x39337225202c3431ull,0x752e766f6d090a3bull,0x3034722509203233ull,
0x6573090a3b38202cull,0x33752e71652e7074ull,0x2c32317025092032ull,0x25202c3431722520ull,
0x6f6d090a3b303472ull,0x2509203233752e76ull,0x0a3b39202c313472ull,0x71652e7074657309ull,
0x702509203233752eull,0x34317225202c3331ull,0x0a3b31347225202cull,0x3233752e766f6d09ull,
0x202c323472250920ull,0x746573090a3b3031ull,0x3233752e71652e70ull,0x202c343170250920ull,
0x7225202c34317225ull,0x766f6d090a3b3234ull,0x722509203233752eull,0x0a3b3131202c3334ull,
0x71652e7074657309ull,0x702509203233752eull,0x34317225202c3531ull,0x0a3b33347225202cull,
0x3233752e766f6d09ull,0x202c343472250920ull,0x746573090a3b3231ull,0x3233752e71652e70ull,
0x202c363170250920ull,0x7225202c34317225ull,0x766f6d090a3b3434ull,0x722509203233752eull,
0x0a3b3331202c3534ull,0x71652e7074657309ull,0x702509203233752eull,0x34317225202c3731ull,
0x0a3b35347225202cull,0x3233752e766f6d09ull,0x202c363472250920ull,0x746573090a3b3431ull,
0x3233752e71652e70ull,0x202c383170250920ull,0x7225202c34317225ull,0x766f6d090a3b3634ull,
0x722509203233752eull,0x0a3b3531202c3734ull,0x71652e7074657309ull,0x702509203233752eull,
0x34317225202c3931ull,0x0a3b37347225202cull,0x33732e706c657309ull,0x2c38347225092032ull,
0x25202c30202c3120ull,0x6c6573090a3b3470ull,0x2509203233732e70ull,0x202c31202c393472ull,
0x0a3b357025202c30ull,0x33732e706c657309ull,0x2c30357225092032ull,0x25202c30202c3120ull,
0x6c6573090a3b3670ull,0x2509203233732e70ull,0x202c31202c313572ull,0x0a3b377025202c30ull,
0x33732e706c657309ull,0x2c32357225092032ull,0x25202c30202c3120ull,0x6c6573090a3b3870ull,
0x2509203233732e70ull,0x202c31202c333572ull,0x0a3b397025202c30ull,0x33732e706c657309ull,
0x2c34357225092032ull,0x25202c30202c3120ull,0x6573090a3b303170ull,0x09203233732e706cull,
0x2c31202c35357225ull,0x31317025202c3020ull,0x2e706c6573090a3bull,0x3572250920323373ull,
0x2c30202c31202c36ull,0x090a3b3231702520ull,0x3233732e706c6573ull,0x202c373572250920ull,
0x7025202c30202c31ull,0x6c6573090a3b3331ull,0x2509203233732e70ull,0x202c31202c383572ull,
0x3b34317025202c30ull,0x732e706c6573090aull,0x3935722509203233ull,0x202c30202c31202cull,
0x73090a3b35317025ull,0x203233732e706c65ull,0x31202c3036722509ull,0x317025202c30202cull,
0x706c6573090a3b36ull,0x722509203233732eull,0x30202c31202c3136ull,0x0a3b37317025202cull,
0x33732e706c657309ull,0x2c32367225092032ull,0x25202c30202c3120ull,0x6573090a3b383170ull,
0x09203233732e706cull,0x2c31202c33367225ull,0x39317025202c3020ull,0x61702e646c090a3bull,
0x203233752e6d6172ull,0x5b202c3436722509ull,0x6170616475635f5full,0x6152385a5f5f6d72ull,
0x31506d7553786964ull,0x756c615679654b32ull,0x6a6a6a7269615065ull,0x746e656d656c655full,
0x766f6d090a3b5d73ull,0x722509203233732eull,0x31337225202c3536ull,0x5f355f744c240a3bull,
0x200a3a3831303232ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,
0x73656e202c363331ull,0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,
0x6974617265746920ull,0x6b6e75203a736e6full,0x6573090a6e776f6eull,0x33752e746c2e7074ull,
0x2c30327025092032ull,0x7225202c32722520ull,0x252140090a3b3436ull,0x2061726220303270ull,
0x325f355f744c2409ull,0x2f200a3b30333532ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3633ull,0x64656c6562616c20ull,
0x325f355f744c2420ull,0x6c2e090a38313032ull,0x343109383109636full,0x2e646c090a300938ull,
0x36752e6d61726170ull,0x2c35647225092034ull,0x616475635f5f5b20ull,0x385a5f5f6d726170ull,
0x6d75537869646152ull,0x615679654b323150ull,0x6a7269615065756cull,0x61746144705f6a6aull,
0x2e747663090a3b5dull,0x203233752e343675ull,0x25202c3664722509ull,0x6c756d090a3b3272ull,
0x203436752e6f6c2eull,0x25202c3764722509ull,0x0a3b38202c366472ull,0x3436752e64646109ull,
0x202c386472250920ull,0x7225202c35647225ull,0x2e646c090a3b3764ull,0x752e6c61626f6c67ull,
0x3636722509203233ull,0x2b386472255b202cull,0x617262090a3b5d30ull,0x4c240920696e752eull,
0x373232325f355f74ull,0x355f744c240a3b34ull,0x0a3a30333532325full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36333120ull,
0x6c6562616c206461ull,0x355f744c24206465ull,0x090a38313032325full,0x09383109636f6c2eull,
0x6d090a3009303531ull,0x09203233752e766full,0x3b30202c36367225ull,0x325f355f744c240aull,
0x2f200a3a34373232ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3633ull,0x64656c6562616c20ull,0x325f355f744c2420ull,
0x6573090a38313032ull,0x09203233732e706cull,0x2c31202c37367225ull,0x30327025202c3020ull,
0x622e646e61090a3bull,0x3836722509203233ull,0x202c37367225202cull,0x6d090a3b38347225ull,
0x09203233752e766full,0x3b30202c39367225ull,0x652e70746573090aull,0x2509203233732e71ull,
0x367225202c313270ull,0x3b39367225202c38ull,0x203132702540090aull,0x744c240920617262ull,
0x36383732325f355full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36333120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38313032325f355full,0x3109636f6c2e090aull,0x0a30093337310938ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x5f5f5b202c303772ull,0x6d72617061647563ull,0x69646152385a5f5full,
0x4b3231506d755378ull,0x5065756c61567965ull,0x735f6a6a6a726961ull,0x090a3b5d74666968ull,
0x203233752e726873ull,0x25202c3137722509ull,0x377225202c363672ull,0x2e646e61090a3b30ull,
0x3772250920323362ull,0x2c31377225202c32ull,0x6d090a3b35353220ull,0x33752e6f6c2e6c75ull,
0x2c33377225092032ull,0x34202c3237722520ull,0x752e646461090a3bull,0x3437722509203233ull,
0x202c35317225202cull,0x63090a3b33377225ull,0x752e3436752e7476ull,0x3964722509203233ull,
0x0a3b34377225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x39647225202c3031ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c31316472ull,0x31647225202c3164ull,
0x732e646c090a3b30ull,0x33752e6465726168ull,0x2c35377225092032ull,0x2b31316472255b20ull,
0x646461090a3b5d30ull,0x722509203233752eull,0x35377225202c3637ull,0x7473090a3b31202cull,
0x2e6465726168732eull,0x72255b0920323375ull,0x202c5d302b313164ull,0x4c240a3b36377225ull,
0x383732325f355f74ull,0x6c3c2f2f200a3a36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c36333120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x313032325f355f74ull,0x09636f6c2e090a38ull,0x3009343731093831ull,0x79732e726162090aull,
0x090a3b300920636eull,0x203233622e646e61ull,0x25202c3737722509ull,0x347225202c373672ull,
0x2e766f6d090a3b39ull,0x3772250920323375ull,0x73090a3b30202c38ull,0x732e71652e707465ull,
0x3232702509203233ull,0x202c37377225202cull,0x40090a3b38377225ull,0x6172622032327025ull,
0x5f355f744c240920ull,0x200a3b3839323332ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363331ull,0x656c6562616c2064ull,
0x5f355f744c242064ull,0x2e090a3831303232ull,0x3109383109636f6cull,0x646c090a30093637ull,
0x732e6d617261702eull,0x3937722509203233ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x7553786964615238ull,0x5679654b3231506dull,0x7269615065756c61ull,0x666968735f6a6a6aull,
0x726873090a3b5d74ull,0x722509203233752eull,0x36367225202c3137ull,0x0a3b39377225202cull,
0x3233622e646e6109ull,0x202c323772250920ull,0x3532202c31377225ull,0x2e6c756d090a3b35ull,
0x09203233752e6f6cull,0x7225202c33377225ull,0x090a3b34202c3237ull,0x203233752e646461ull,
0x25202c3038722509ull,0x377225202c353172ull,0x2e747663090a3b33ull,0x203233752e343675ull,
0x202c323164722509ull,0x6d090a3b30387225ull,0x36752e6f6c2e6c75ull,0x3331647225092034ull,
0x2c3231647225202cull,0x646461090a3b3420ull,0x722509203436752eull,0x647225202c313164ull,
0x3331647225202c31ull,0x68732e646c090a3bull,0x3233752e64657261ull,0x202c313872250920ull,
0x302b31316472255bull,0x2e646461090a3b5dull,0x3872250920323375ull,0x2c31387225202c32ull,
0x2e7473090a3b3120ull,0x752e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3131ull,
0x744c240a3b323872ull,0x38393233325f355full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36333120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x38313032325f355full,0x3109636f6c2e090aull,0x0a30093737310938ull,
0x6e79732e72616209ull,0x61090a3b30092063ull,0x09203233622e646eull,0x7225202c33387225ull,
0x30357225202c3736ull,0x752e766f6d090a3bull,0x3438722509203233ull,0x6573090a3b30202cull,
0x33732e71652e7074ull,0x2c33327025092032ull,0x25202c3338722520ull,0x2540090a3b343872ull,
0x2061726220333270ull,0x325f355f744c2409ull,0x2f200a3b30313833ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3633ull,
0x64656c6562616c20ull,0x325f355f744c2420ull,0x6c2e090a38313032ull,0x373109383109636full,
0x2e646c090a300939ull,0x33732e6d61726170ull,0x2c35387225092032ull,0x616475635f5f5b20ull,
0x385a5f5f6d726170ull,0x6d75537869646152ull,0x615679654b323150ull,0x6a7269615065756cull,
0x74666968735f6a6aull,0x2e726873090a3b5dull,0x3772250920323375ull,0x2c36367225202c31ull,
0x090a3b3538722520ull,0x203233622e646e61ull,0x25202c3237722509ull,0x353532202c313772ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x377225202c333772ull,0x61090a3b34202c32ull,
0x09203233752e6464ull,0x7225202c36387225ull,0x33377225202c3531ull,0x752e747663090a3bull,
0x09203233752e3436ull,0x25202c3431647225ull,0x756d090a3b363872ull,0x3436752e6f6c2e6cull,
0x2c35316472250920ull,0x202c343164722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x31647225202c3131ull,0x3b3531647225202cull,0x6168732e646c090aull,0x203233752e646572ull,
0x5b202c3738722509ull,0x5d302b3131647225ull,0x752e646461090a3bull,0x3838722509203233ull,
0x202c37387225202cull,0x732e7473090a3b31ull,0x33752e6465726168ull,0x316472255b092032ull,
0x7225202c5d302b31ull,0x5f744c240a3b3838ull,0x3a30313833325f35ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3633312065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a38313032325f35ull,0x383109636f6c2e09ull,
0x090a300930383109ull,0x636e79732e726162ull,0x6e61090a3b300920ull,0x2509203233622e64ull,
0x367225202c393872ull,0x3b31357225202c37ull,0x33752e766f6d090aull,0x2c30397225092032ull,
0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c343270250920ull,0x7225202c39387225ull,
0x702540090a3b3039ull,0x0920617262203432ull,0x34325f355f744c24ull,0x2f2f200a3b323233ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333120656e696c20ull,
0x2064616568202c36ull,0x2064656c6562616cull,0x32325f355f744c24ull,0x6f6c2e090a383130ull,
0x3238310938310963ull,0x702e646c090a3009ull,0x3233732e6d617261ull,0x202c313972250920ull,
0x70616475635f5f5bull,0x52385a5f5f6d7261ull,0x506d755378696461ull,0x6c615679654b3231ull,
0x6a6a726961506575ull,0x5d74666968735f6aull,0x752e726873090a3bull,0x3137722509203233ull,
0x202c36367225202cull,0x61090a3b31397225ull,0x09203233622e646eull,0x7225202c32377225ull,
0x3b353532202c3137ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x32377225202c3337ull,
0x6461090a3b34202cull,0x2509203233752e64ull,0x317225202c323972ull,0x3b33377225202c35ull,
0x36752e747663090aull,0x2509203233752e34ull,0x7225202c36316472ull,0x6c756d090a3b3239ull,
0x203436752e6f6c2eull,0x202c373164722509ull,0x34202c3631647225ull,0x752e646461090a3bull,
0x3164722509203436ull,0x2c31647225202c31ull,0x0a3b373164722520ull,0x726168732e646c09ull,
0x09203233752e6465ull,0x255b202c33397225ull,0x3b5d302b31316472ull,0x33752e646461090aull,
0x2c34397225092032ull,0x31202c3339722520ull,0x68732e7473090a3bull,0x3233752e64657261ull,
0x31316472255b0920ull,0x397225202c5d302bull,0x355f744c240a3b34ull,0x0a3a32323334325full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36333120ull,0x6c6562616c206461ull,0x355f744c24206465ull,0x090a38313032325full,
0x09383109636f6c2eull,0x62090a3009333831ull,0x20636e79732e7261ull,0x646e61090a3b3009ull,
0x722509203233622eull,0x37367225202c3539ull,0x0a3b32357225202cull,0x3233752e766f6d09ull,
0x202c363972250920ull,0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3532702509ull,
0x397225202c353972ull,0x32702540090a3b36ull,0x2409206172622035ull,0x3834325f355f744cull,
0x3c2f2f200a3b3433ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x36333120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3032325f355f744cull,
0x636f6c2e090a3831ull,0x0935383109383109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x5b202c3739722509ull,0x6170616475635f5full,0x6152385a5f5f6d72ull,0x31506d7553786964ull,
0x756c615679654b32ull,0x6a6a6a7269615065ull,0x3b5d74666968735full,0x33752e726873090aull,
0x2c31377225092032ull,0x25202c3636722520ull,0x6e61090a3b373972ull,0x2509203233622e64ull,
0x377225202c323772ull,0x0a3b353532202c31ull,0x2e6f6c2e6c756d09ull,0x3772250920323375ull,
0x2c32377225202c33ull,0x646461090a3b3420ull,0x722509203233752eull,0x35317225202c3839ull,
0x0a3b33377225202cull,0x3436752e74766309ull,0x722509203233752eull,0x397225202c383164ull,
0x2e6c756d090a3b38ull,0x09203436752e6f6cull,0x25202c3931647225ull,0x3b34202c38316472ull,
0x36752e646461090aull,0x3131647225092034ull,0x202c31647225202cull,0x090a3b3931647225ull,
0x65726168732e646cull,0x2509203233752e64ull,0x72255b202c393972ull,0x0a3b5d302b313164ull,
0x3233752e64646109ull,0x2c30303172250920ull,0x31202c3939722520ull,0x68732e7473090a3bull,
0x3233752e64657261ull,0x31316472255b0920ull,0x317225202c5d302bull,0x5f744c240a3b3030ull,
0x3a34333834325f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3633312065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a38313032325f35ull,0x383109636f6c2e09ull,0x090a300936383109ull,0x636e79732e726162ull,
0x6e61090a3b300920ull,0x2509203233622e64ull,0x7225202c31303172ull,0x33357225202c3736ull,
0x752e766f6d090a3bull,0x3031722509203233ull,0x73090a3b30202c32ull,0x732e71652e707465ull,
0x3632702509203233ull,0x2c3130317225202cull,0x0a3b323031722520ull,0x6220363270254009ull,
0x5f744c2409206172ull,0x3b36343335325f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3633312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a38313032325f35ull,0x383109636f6c2e09ull,0x090a300938383109ull,
0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c333031ull,0x6d72617061647563ull,
0x69646152385a5f5full,0x4b3231506d755378ull,0x5065756c61567965ull,0x735f6a6a6a726961ull,
0x090a3b5d74666968ull,0x203233752e726873ull,0x25202c3137722509ull,0x317225202c363672ull,
0x646e61090a3b3330ull,0x722509203233622eull,0x31377225202c3237ull,0x090a3b353532202cull,
0x752e6f6c2e6c756dull,0x3337722509203233ull,0x202c32377225202cull,0x2e646461090a3b34ull,
0x3172250920323375ull,0x35317225202c3430ull,0x0a3b33377225202cull,0x3436752e74766309ull,
0x722509203233752eull,0x317225202c303264ull,0x6c756d090a3b3430ull,0x203436752e6f6c2eull,
0x202c313264722509ull,0x34202c3032647225ull,0x752e646461090a3bull,0x3164722509203436ull,
0x2c31647225202c31ull,0x0a3b313264722520ull,0x726168732e646c09ull,0x09203233752e6465ull,
0x5b202c3530317225ull,0x5d302b3131647225ull,0x752e646461090a3bull,0x3031722509203233ull,
0x3530317225202c36ull,0x7473090a3b31202cull,0x2e6465726168732eull,0x72255b0920323375ull,
0x202c5d302b313164ull,0x240a3b3630317225ull,0x3335325f355f744cull,0x3c2f2f200a3a3634ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x36333120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3032325f355f744cull,0x636f6c2e090a3831ull,
0x0939383109383109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,0x3233622e646e6109ull,
0x2c37303172250920ull,0x25202c3736722520ull,0x6f6d090a3b343572ull,0x2509203233752e76ull,
0x3b30202c38303172ull,0x652e70746573090aull,0x2509203233732e71ull,0x317225202c373270ull,
0x30317225202c3730ull,0x32702540090a3b38ull,0x2409206172622037ull,0x3835325f355f744cull,
0x3c2f2f200a3b3835ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x36333120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3032325f355f744cull,
0x636f6c2e090a3831ull,0x0931393109383109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x202c393031722509ull,0x70616475635f5f5bull,0x52385a5f5f6d7261ull,0x506d755378696461ull,
0x6c615679654b3231ull,0x6a6a726961506575ull,0x5d74666968735f6aull,0x752e726873090a3bull,
0x3137722509203233ull,0x202c36367225202cull,0x090a3b3930317225ull,0x203233622e646e61ull,
0x25202c3237722509ull,0x353532202c313772ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x377225202c333772ull,0x61090a3b34202c32ull,0x09203233752e6464ull,0x25202c3031317225ull,
0x377225202c353172ull,0x2e747663090a3b33ull,0x203233752e343675ull,0x202c323264722509ull,
0x090a3b3031317225ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,0x3232647225202c33ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c31316472ull,0x32647225202c3164ull,
0x732e646c090a3b33ull,0x33752e6465726168ull,0x3131317225092032ull,0x31316472255b202cull,
0x6461090a3b5d302bull,0x2509203233752e64ull,0x7225202c32313172ull,0x0a3b31202c313131ull,
0x726168732e747309ull,0x09203233752e6465ull,0x302b31316472255bull,0x3231317225202c5dull,
0x5f355f744c240a3bull,0x200a3a3835383532ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363331ull,0x656c6562616c2064ull,
0x5f355f744c242064ull,0x2e090a3831303232ull,0x3109383109636f6cull,0x6162090a30093239ull,
0x0920636e79732e72ull,0x2e646e61090a3b30ull,0x3172250920323362ull,0x37367225202c3331ull,
0x0a3b35357225202cull,0x3233752e766f6d09ull,0x2c34313172250920ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x202c383270250920ull,0x25202c3331317225ull,0x40090a3b34313172ull,
0x6172622038327025ull,0x5f355f744c240920ull,0x200a3b3037333632ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363331ull,
0x656c6562616c2064ull,0x5f355f744c242064ull,0x2e090a3831303232ull,0x3109383109636f6cull,
0x646c090a30093439ull,0x732e6d617261702eull,0x3131722509203233ull,0x75635f5f5b202c35ull,
0x5f5f6d7261706164ull,0x537869646152385aull,0x79654b3231506d75ull,0x69615065756c6156ull,
0x6968735f6a6a6a72ull,0x6873090a3b5d7466ull,0x2509203233752e72ull,0x367225202c313772ull,
0x3531317225202c36ull,0x622e646e61090a3bull,0x3237722509203233ull,0x202c31377225202cull,
0x756d090a3b353532ull,0x3233752e6f6c2e6cull,0x202c333772250920ull,0x3b34202c32377225ull,
0x33752e646461090aull,0x3631317225092032ull,0x202c35317225202cull,0x63090a3b33377225ull,
0x752e3436752e7476ull,0x3264722509203233ull,0x3631317225202c34ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c35326472ull,0x0a3b34202c343264ull,0x3436752e64646109ull,
0x2c31316472250920ull,0x25202c3164722520ull,0x6c090a3b35326472ull,0x6465726168732e64ull,
0x722509203233752eull,0x72255b202c373131ull,0x0a3b5d302b313164ull,0x3233752e64646109ull,
0x2c38313172250920ull,0x202c373131722520ull,0x732e7473090a3b31ull,0x33752e6465726168ull,
0x316472255b092032ull,0x7225202c5d302b31ull,0x744c240a3b383131ull,0x30373336325f355full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36333120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38313032325f355full,
0x3109636f6c2e090aull,0x0a30093539310938ull,0x6e79732e72616209ull,0x61090a3b30092063ull,
0x09203233622e646eull,0x25202c3931317225ull,0x357225202c373672ull,0x2e766f6d090a3b36ull,
0x3172250920323375ull,0x090a3b30202c3032ull,0x2e71652e70746573ull,0x3270250920323373ull,
0x3931317225202c39ull,0x3b3032317225202cull,0x203932702540090aull,0x744c240920617262ull,
0x32383836325f355full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36333120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38313032325f355full,0x3109636f6c2e090aull,0x0a30093739310938ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x5f5b202c31323172ull,0x726170616475635full,0x646152385a5f5f6dull,
0x3231506d75537869ull,0x65756c615679654bull,0x5f6a6a6a72696150ull,0x0a3b5d7466696873ull,
0x3233752e72687309ull,0x202c313772250920ull,0x7225202c36367225ull,0x6e61090a3b313231ull,
0x2509203233622e64ull,0x377225202c323772ull,0x0a3b353532202c31ull,0x2e6f6c2e6c756d09ull,
0x3772250920323375ull,0x2c32377225202c33ull,0x646461090a3b3420ull,0x722509203233752eull,
0x317225202c323231ull,0x3b33377225202c35ull,0x36752e747663090aull,0x2509203233752e34ull,
0x7225202c36326472ull,0x756d090a3b323231ull,0x3436752e6f6c2e6cull,0x2c37326472250920ull,
0x202c363264722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3131ull,
0x3b3732647225202cull,0x6168732e646c090aull,0x203233752e646572ull,0x202c333231722509ull,
0x302b31316472255bull,0x2e646461090a3b5dull,0x3172250920323375ull,0x32317225202c3432ull,
0x73090a3b31202c33ull,0x6465726168732e74ull,0x255b09203233752eull,0x2c5d302b31316472ull,
0x0a3b343231722520ull,0x36325f355f744c24ull,0x2f2f200a3a323838ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x333120656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x32325f355f744c24ull,0x6f6c2e090a383130ull,0x3839310938310963ull,
0x2e726162090a3009ull,0x3b300920636e7973ull,0x33622e646e61090aull,0x3532317225092032ull,
0x202c37367225202cull,0x6d090a3b37357225ull,0x09203233752e766full,0x30202c3632317225ull,
0x2e70746573090a3bull,0x09203233732e7165ull,0x7225202c30337025ull,0x317225202c353231ull,
0x702540090a3b3632ull,0x0920617262203033ull,0x37325f355f744c24ull,0x2f2f200a3b343933ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333120656e696c20ull,
0x2064616568202c36ull,0x2064656c6562616cull,0x32325f355f744c24ull,0x6f6c2e090a383130ull,
0x3030320938310963ull,0x702e646c090a3009ull,0x3233732e6d617261ull,0x2c37323172250920ull,
0x616475635f5f5b20ull,0x385a5f5f6d726170ull,0x6d75537869646152ull,0x615679654b323150ull,
0x6a7269615065756cull,0x74666968735f6a6aull,0x2e726873090a3b5dull,0x3772250920323375ull,
0x2c36367225202c31ull,0x0a3b373231722520ull,0x3233622e646e6109ull,0x202c323772250920ull,
0x3532202c31377225ull,0x2e6c756d090a3b35ull,0x09203233752e6f6cull,0x7225202c33377225ull,
0x090a3b34202c3237ull,0x203233752e646461ull,0x202c383231722509ull,0x7225202c35317225ull,
0x747663090a3b3337ull,0x3233752e3436752eull,0x2c38326472250920ull,0x0a3b383231722520ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x32647225202c3932ull,0x61090a3b34202c38ull,
0x09203436752e6464ull,0x25202c3131647225ull,0x647225202c316472ull,0x2e646c090a3b3932ull,
0x752e646572616873ull,0x3231722509203233ull,0x316472255b202c39ull,0x61090a3b5d302b31ull,
0x09203233752e6464ull,0x25202c3033317225ull,0x3b31202c39323172ull,0x6168732e7473090aull,
0x203233752e646572ull,0x2b31316472255b09ull,0x33317225202c5d30ull,0x355f744c240a3b30ull,
0x0a3a34393337325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c36333120ull,0x6c6562616c206461ull,0x355f744c24206465ull,
0x090a38313032325full,0x09383109636f6c2eull,0x62090a3009313032ull,0x20636e79732e7261ull,
0x646e61090a3b3009ull,0x722509203233622eull,0x367225202c313331ull,0x3b38357225202c37ull,
0x33752e766f6d090aull,0x3233317225092032ull,0x6573090a3b30202cull,0x33732e71652e7074ull,
0x2c31337025092032ull,0x202c313331722520ull,0x090a3b3233317225ull,0x7262203133702540ull,
0x355f744c24092061ull,0x0a3b36303937325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36333120ull,0x6c6562616c206461ull,
0x355f744c24206465ull,0x090a38313032325full,0x09383109636f6c2eull,0x6c090a3009333032ull,
0x2e6d617261702e64ull,0x3172250920323373ull,0x635f5f5b202c3333ull,0x5f6d726170616475ull,
0x7869646152385a5full,0x654b3231506d7553ull,0x615065756c615679ull,0x68735f6a6a6a7269ull,
0x73090a3b5d746669ull,0x09203233752e7268ull,0x7225202c31377225ull,0x33317225202c3636ull,
0x2e646e61090a3b33ull,0x3772250920323362ull,0x2c31377225202c32ull,0x6d090a3b35353220ull,
0x33752e6f6c2e6c75ull,0x2c33377225092032ull,0x34202c3237722520ull,0x752e646461090a3bull,
0x3331722509203233ull,0x2c35317225202c34ull,0x090a3b3337722520ull,0x2e3436752e747663ull,
0x6472250920323375ull,0x33317225202c3033ull,0x2e6c756d090a3b34ull,0x09203436752e6f6cull,
0x25202c3133647225ull,0x3b34202c30336472ull,0x36752e646461090aull,0x3131647225092034ull,
0x202c31647225202cull,0x090a3b3133647225ull,0x65726168732e646cull,0x2509203233752e64ull,
0x255b202c35333172ull,0x3b5d302b31316472ull,0x33752e646461090aull,0x3633317225092032ull,
0x2c3533317225202cull,0x2e7473090a3b3120ull,0x752e646572616873ull,0x6472255b09203233ull,
0x25202c5d302b3131ull,0x4c240a3b36333172ull,0x303937325f355f74ull,0x6c3c2f2f200a3a36ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36333120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x313032325f355f74ull,0x09636f6c2e090a38ull,
0x3009343032093831ull,0x79732e726162090aull,0x090a3b300920636eull,0x203233622e646e61ull,
0x202c373331722509ull,0x7225202c37367225ull,0x766f6d090a3b3935ull,0x722509203233752eull,
0x0a3b30202c383331ull,0x71652e7074657309ull,0x702509203233732eull,0x33317225202c3233ull,
0x3833317225202c37ull,0x3233702540090a3bull,0x4c24092061726220ull,0x313438325f355f74ull,
0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36333120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x313032325f355f74ull,
0x09636f6c2e090a38ull,0x3009363032093831ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5b202c3933317225ull,0x6170616475635f5full,0x6152385a5f5f6d72ull,0x31506d7553786964ull,
0x756c615679654b32ull,0x6a6a6a7269615065ull,0x3b5d74666968735full,0x33752e726873090aull,
0x2c31377225092032ull,0x25202c3636722520ull,0x61090a3b39333172ull,0x09203233622e646eull,
0x7225202c32377225ull,0x3b353532202c3137ull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x32377225202c3337ull,0x6461090a3b34202cull,0x2509203233752e64ull,0x7225202c30343172ull,
0x33377225202c3531ull,0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3233647225ull,
0x6d090a3b30343172ull,0x36752e6f6c2e6c75ull,0x3333647225092034ull,0x2c3233647225202cull,
0x646461090a3b3420ull,0x722509203436752eull,0x647225202c313164ull,0x3333647225202c31ull,
0x68732e646c090a3bull,0x3233752e64657261ull,0x2c31343172250920ull,0x2b31316472255b20ull,
0x646461090a3b5d30ull,0x722509203233752eull,0x317225202c323431ull,0x090a3b31202c3134ull,
0x65726168732e7473ull,0x5b09203233752e64ull,0x5d302b3131647225ull,0x3b3234317225202cull,
0x325f355f744c240aull,0x2f200a3a38313438ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3633ull,0x64656c6562616c20ull,
0x325f355f744c2420ull,0x6c2e090a38313032ull,0x303209383109636full,0x726162090a300937ull,
0x300920636e79732eull,0x622e646e61090a3bull,0x3431722509203233ull,0x2c37367225202c33ull,
0x090a3b3036722520ull,0x203233752e766f6dull,0x202c343431722509ull,0x70746573090a3b30ull,
0x203233732e71652eull,0x25202c3333702509ull,0x7225202c33343172ull,0x2540090a3b343431ull,
0x2061726220333370ull,0x325f355f744c2409ull,0x2f200a3b30333938ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3633ull,
0x64656c6562616c20ull,0x325f355f744c2420ull,0x6c2e090a38313032ull,0x303209383109636full,
0x2e646c090a300939ull,0x33732e6d61726170ull,0x3534317225092032ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x7553786964615238ull,0x5679654b3231506dull,0x7269615065756c61ull,
0x666968735f6a6a6aull,0x726873090a3b5d74ull,0x722509203233752eull,0x36367225202c3137ull,
0x3b3534317225202cull,0x33622e646e61090aull,0x2c32377225092032ull,0x32202c3137722520ull,
0x6c756d090a3b3535ull,0x203233752e6f6c2eull,0x25202c3337722509ull,0x0a3b34202c323772ull,
0x3233752e64646109ull,0x2c36343172250920ull,0x25202c3531722520ull,0x7663090a3b333772ull,
0x33752e3436752e74ull,0x3433647225092032ull,0x3b3634317225202cull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c353364ull,0x090a3b34202c3433ull,0x203436752e646461ull,
0x202c313164722509ull,0x7225202c31647225ull,0x646c090a3b353364ull,0x2e6465726168732eull,
0x3172250920323375ull,0x6472255b202c3734ull,0x090a3b5d302b3131ull,0x203233752e646461ull,
0x202c383431722509ull,0x31202c3734317225ull,0x68732e7473090a3bull,0x3233752e64657261ull,
0x31316472255b0920ull,0x317225202c5d302bull,0x5f744c240a3b3834ull,0x3a30333938325f35ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3633312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a38313032325f35ull,
0x383109636f6c2e09ull,0x090a300930313209ull,0x636e79732e726162ull,0x6e61090a3b300920ull,
0x2509203233622e64ull,0x7225202c39343172ull,0x31367225202c3736ull,0x752e766f6d090a3bull,
0x3531722509203233ull,0x73090a3b30202c30ull,0x732e71652e707465ull,0x3433702509203233ull,
0x2c3934317225202cull,0x0a3b303531722520ull,0x6220343370254009ull,0x5f744c2409206172ull,
0x3b32343439325f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3633312065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a38313032325f35ull,0x383109636f6c2e09ull,0x090a300932313209ull,0x6d617261702e646cull,
0x722509203233732eull,0x5f5f5b202c313531ull,0x6d72617061647563ull,0x69646152385a5f5full,
0x4b3231506d755378ull,0x5065756c61567965ull,0x735f6a6a6a726961ull,0x090a3b5d74666968ull,
0x203233752e726873ull,0x25202c3137722509ull,0x317225202c363672ull,0x646e61090a3b3135ull,
0x722509203233622eull,0x31377225202c3237ull,0x090a3b353532202cull,0x752e6f6c2e6c756dull,
0x3337722509203233ull,0x202c32377225202cull,0x2e646461090a3b34ull,0x3172250920323375ull,
0x35317225202c3235ull,0x0a3b33377225202cull,0x3436752e74766309ull,0x722509203233752eull,
0x317225202c363364ull,0x6c756d090a3b3235ull,0x203436752e6f6c2eull,0x202c373364722509ull,
0x34202c3633647225ull,0x752e646461090a3bull,0x3164722509203436ull,0x2c31647225202c31ull,
0x0a3b373364722520ull,0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3335317225ull,
0x5d302b3131647225ull,0x752e646461090a3bull,0x3531722509203233ull,0x3335317225202c34ull,
0x7473090a3b31202cull,0x2e6465726168732eull,0x72255b0920323375ull,0x202c5d302b313164ull,
0x240a3b3435317225ull,0x3439325f355f744cull,0x3c2f2f200a3a3234ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x36333120656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3032325f355f744cull,0x636f6c2e090a3831ull,0x0933313209383109ull,
0x732e726162090a30ull,0x0a3b300920636e79ull,0x3233622e646e6109ull,0x2c35353172250920ull,
0x25202c3736722520ull,0x6f6d090a3b323672ull,0x2509203233752e76ull,0x3b30202c36353172ull,
0x652e70746573090aull,0x2509203233732e71ull,0x317225202c353370ull,0x35317225202c3535ull,
0x33702540090a3b36ull,0x2409206172622035ull,0x3939325f355f744cull,0x3c2f2f200a3b3435ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x36333120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3032325f355f744cull,0x636f6c2e090a3831ull,
0x0935313209383109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,0x202c373531722509ull,
0x70616475635f5f5bull,0x52385a5f5f6d7261ull,0x506d755378696461ull,0x6c615679654b3231ull,
0x6a6a726961506575ull,0x5d74666968735f6aull,0x752e726873090a3bull,0x3137722509203233ull,
0x202c36367225202cull,0x090a3b3735317225ull,0x203233622e646e61ull,0x25202c3237722509ull,
0x353532202c313772ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x377225202c333772ull,
0x61090a3b34202c32ull,0x09203233752e6464ull,0x25202c3835317225ull,0x377225202c353172ull,
0x2e747663090a3b33ull,0x203233752e343675ull,0x202c383364722509ull,0x090a3b3835317225ull,
0x752e6f6c2e6c756dull,0x3364722509203436ull,0x3833647225202c39ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c31316472ull,0x33647225202c3164ull,0x732e646c090a3b39ull,
0x33752e6465726168ull,0x3935317225092032ull,0x31316472255b202cull,0x6461090a3b5d302bull,
0x2509203233752e64ull,0x7225202c30363172ull,0x0a3b31202c393531ull,0x726168732e747309ull,
0x09203233752e6465ull,0x302b31316472255bull,0x3036317225202c5dull,0x5f355f744c240a3bull,
0x200a3a3435393932ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c363331ull,0x656c6562616c2064ull,0x5f355f744c242064ull,
0x2e090a3831303232ull,0x3209383109636f6cull,0x6162090a30093631ull,0x0920636e79732e72ull,
0x2e646e61090a3b30ull,0x3172250920323362ull,0x37367225202c3136ull,0x0a3b33367225202cull,
0x3233752e766f6d09ull,0x2c32363172250920ull,0x746573090a3b3020ull,0x3233732e71652e70ull,
0x202c363370250920ull,0x25202c3136317225ull,0x40090a3b32363172ull,0x6172622036337025ull,
0x5f355f744c240920ull,0x200a3b3636343033ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363331ull,0x656c6562616c2064ull,
0x5f355f744c242064ull,0x2e090a3831303232ull,0x3209383109636f6cull,0x646c090a30093831ull,
0x732e6d617261702eull,0x3631722509203233ull,0x75635f5f5b202c33ull,0x5f5f6d7261706164ull,
0x537869646152385aull,0x79654b3231506d75ull,0x69615065756c6156ull,0x6968735f6a6a6a72ull,
0x6873090a3b5d7466ull,0x2509203233752e72ull,0x367225202c313772ull,0x3336317225202c36ull,
0x622e646e61090a3bull,0x3237722509203233ull,0x202c31377225202cull,0x756d090a3b353532ull,
0x3233752e6f6c2e6cull,0x202c333772250920ull,0x3b34202c32377225ull,0x33752e646461090aull,
0x3436317225092032ull,0x202c35317225202cull,0x63090a3b33377225ull,0x752e3436752e7476ull,
0x3464722509203233ull,0x3436317225202c30ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c31346472ull,0x0a3b34202c303464ull,0x3436752e64646109ull,0x2c31316472250920ull,
0x25202c3164722520ull,0x6c090a3b31346472ull,0x6465726168732e64ull,0x722509203233752eull,
0x72255b202c353631ull,0x0a3b5d302b313164ull,0x3233752e64646109ull,0x2c36363172250920ull,
0x202c353631722520ull,0x732e7473090a3b31ull,0x33752e6465726168ull,0x316472255b092032ull,
0x7225202c5d302b31ull,0x744c240a3b363631ull,0x36363430335f355full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36333120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38313032325f355full,0x3109636f6c2e090aull,
0x0a30093931320938ull,0x6e79732e72616209ull,0x61090a3b30092063ull,0x09203233752e6464ull,
0x327225202c327225ull,0x73090a3b3631202cull,0x752e74672e707465ull,0x3733702509203233ull,
0x202c34327225202cull,0x2540090a3b327225ull,0x2061726220373370ull,0x325f355f744c2409ull,
0x4c240a3b38313032ull,0x303531325f355f74ull,0x636f6c2e090a3a36ull,0x0938333209383109ull,
0x752e726873090a30ull,0x3631722509203233ull,0x202c317225202c37ull,0x2e766f6d090a3b32ull,
0x3172250920323375ull,0x3b353532202c3836ull,0x672e70746573090aull,0x2509203233752e74ull,
0x317225202c383370ull,0x36317225202c3736ull,0x33702540090a3b38ull,0x2409206172622038ull,
0x3231335f355f744cull,0x766f6d090a3b3433ull,0x722509203233752eull,0x313732202c393631ull,
0x752e627573090a3bull,0x3731722509203233ull,0x3936317225202c30ull,0x3b3736317225202cull,
0x33732e726873090aull,0x3137317225092032ull,0x2c3037317225202cull,0x6f6d090a3b313320ull,
0x2509203233732e76ull,0x3531202c32373172ull,0x622e646e61090a3bull,0x3731722509203233ull,
0x3137317225202c33ull,0x3b3237317225202cull,0x33732e646461090aull,0x3437317225092032ull,
0x2c3337317225202cull,0x0a3b303731722520ull,0x3233732e72687309ull,0x2c35373172250920ull,
0x202c343731722520ull,0x2e646e61090a3b34ull,0x3172250920323362ull,0x2c317225202c3637ull,
0x6c756d090a3b3320ull,0x33752e6f6c2e3432ull,0x3737317225092032ull,0x2c3736317225202cull,
0x6c756d090a3b3420ull,0x33752e6f6c2e3432ull,0x3837317225092032ull,0x2c3736317225202cull,
0x61090a3b32393120ull,0x09203233752e6464ull,0x25202c3937317225ull,0x317225202c363172ull,
0x646461090a3b3837ull,0x722509203233752eull,0x317225202c303831ull,0x37317225202c3637ull,
0x2e747663090a3b37ull,0x203233752e343675ull,0x202c323464722509ull,0x090a3b3038317225ull,
0x752e6f6c2e6c756dull,0x3464722509203436ull,0x3234647225202c33ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c34346472ull,0x34647225202c3164ull,0x2e766f6d090a3b33ull,
0x6472250920343675ull,0x64615264202c3534ull,0x090a3b6d75537869ull,0x203233752e646461ull,
0x202c313831722509ull,0x25202c3637317225ull,0x63090a3b39373172ull,0x752e3436752e7476ull,
0x3464722509203233ull,0x3138317225202c36ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c37346472ull,0x0a3b34202c363464ull,0x3436752e64646109ull,0x2c38346472250920ull,
0x202c353464722520ull,0x090a3b3734647225ull,0x203233732e766f6dull,0x202c323831722509ull,
0x240a3b3537317225ull,0x3731335f355f744cull,0x3c2f2f200a3a3634ull,0x6f4c203e706f6f6cull,
0x2079646f6220706full,0x38333220656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,
0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,0x776f6e6b6e75203aull,
0x09636f6c2e090a6eull,0x3009313432093831ull,0x6168732e646c090aull,0x203233752e646572ull,
0x202c333831722509ull,0x302b34346472255bull,0x672e7473090a3b5dull,0x33752e6c61626f6cull,
0x346472255b092032ull,0x7225202c5d302b38ull,0x6461090a3b333831ull,0x2509203436752e64ull,
0x7225202c38346472ull,0x323231202c383464ull,0x646461090a3b3838ull,0x722509203233752eull,
0x317225202c373731ull,0x0a3b3436202c3737ull,0x3436752e64646109ull,0x2c34346472250920ull,
0x202c343464722520ull,0x6f6d090a3b363532ull,0x2509203233752e76ull,0x3031202c34383172ull,
0x746573090a3b3032ull,0x3233752e656c2e70ull,0x202c393370250920ull,0x25202c3737317225ull,
0x40090a3b34383172ull,0x6172622039337025ull,0x5f355f744c240920ull,0x240a3b3634373133ull,
0x3231335f355f744cull,0x6f6c2e090a3a3433ull,0x3434320938310963ull,0x74697865090a3009ull,
0x6e6557444c240a3bull,0x646152385a5f5f64ull,0x3231506d75537869ull,0x65756c615679654bull,
0x3a6a6a6a72696150ull,0x5f202f2f207d090aull,0x537869646152385aull,0x79654b3231506d75ull,
0x69615065756c6156ull,0x2e090a0a6a6a6a72ull,0x5a5f207972746e65ull,0x5078696461523431ull,
0x6d75537869666572ull,0x722e090a7b090a76ull,0x203233752e206765ull,0x0a3b3e30373c7225ull,
0x752e206765722e09ull,0x333c647225203436ull,0x65722e090a3b3e30ull,0x20646572702e2067ull,
0x0a3b3e35313c7025ull,0x383109636f6c2e09ull,0x240a300931353209ull,0x315a5f5f3142424cull,
0x7250786964615234ull,0x766d755378696665ull,0x09636f6c2e090a3aull,0x3009393632093831ull,
0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3172ull,0x646e61090a3b782eull,
0x722509203233622eull,0x202c317225202c32ull,0x726873090a3b3531ull,0x722509203233752eull,
0x202c317225202c33ull,0x326c756d090a3b34ull,0x3233752e6f6c2e34ull,0x25202c3472250920ull,
0x0a3b3731202c3372ull,0x3233752e64646109ull,0x25202c3572250920ull,0x3b347225202c3272ull,
0x33752e766f6d090aull,0x202c367225092032ull,0x353536313334312dull,0x756d090a3b353637ull,
0x3233752e69682e6cull,0x25202c3772250920ull,0x3b367225202c3172ull,0x33752e726873090aull,
0x202c387225092032ull,0x0a3b37202c377225ull,0x3233752e74766309ull,0x722509203631752eull,
0x6961746325202c39ull,0x756d090a3b782e64ull,0x752e6f6c2e34326cull,0x3031722509203233ull,
0x31202c397225202cull,0x2e766f6d090a3b36ull,0x3172250920323375ull,0x313334312d202c31ull,
0x0a3b353637353536ull,0x2e69682e6c756d09ull,0x3172250920323375ull,0x202c317225202c32ull,
0x73090a3b31317225ull,0x09203233752e7268ull,0x7225202c33317225ull,0x090a3b37202c3231ull,
0x752e6f6c2e6c756dull,0x3431722509203233ull,0x202c33317225202cull,0x7573090a3b323931ull,
0x2509203233752e62ull,0x317225202c353172ull,0x0a3b34317225202cull,0x3233752e64646109ull,
0x202c363172250920ull,0x317225202c387225ull,0x2e6c756d090a3b30ull,0x09203233752e6f6cull,
0x7225202c37317225ull,0x3b323931202c3631ull,0x33752e646461090aull,0x2c38317225092032ull,
0x25202c3531722520ull,0x6f6d090a3b373172ull,0x2509203233732e76ull,0x317225202c393172ull,
0x2e6c756d090a3b38ull,0x09203233752e6f6cull,0x7225202c30327225ull,0x3b32373033202c39ull,
0x33752e646461090aull,0x2c31327225092032ull,0x33202c3032722520ull,0x6573090a3b323730ull,
0x33752e656c2e7074ull,0x202c317025092032ull,0x7225202c31327225ull,0x702540090a3b3831ull,
0x2409206172622031ull,0x3836375f365f744cull,0x2e766f6d090a3b32ull,0x6472250920343675ull,
0x6964615264202c31ull,0x6d090a3b6d755378ull,0x09203436752e766full,0x5273202c32647225ull,
0x3b6d755378696461ull,0x33752e627573090aull,0x2c32327225092032ull,0x25202c3132722520ull,
0x6461090a3b383172ull,0x2509203233752e64ull,0x327225202c333272ull,0x0a3b313931202c32ull,
0x3233732e766f6d09ull,0x202c343272250920ull,0x353536313334312dull,0x6f6d090a3b353637ull,
0x2509203233732e76ull,0x0a3b30202c353272ull,0x746c2e7074657309ull,0x702509203233732eull,
0x2c33327225202c32ull,0x090a3b3532722520ull,0x203233732e736261ull,0x25202c3632722509ull,
0x756d090a3b333272ull,0x3233752e69682e6cull,0x202c373272250920ull,0x7225202c36327225ull,
0x726873090a3b3432ull,0x722509203233732eull,0x37327225202c3832ull,0x2540090a3b37202cull,
0x732e627573203270ull,0x3832722509203233ull,0x202c35327225202cull,0x6d090a3b38327225ull,
0x09203233732e766full,0x7225202c39327225ull,0x747663090a3b3832ull,0x3233752e3436752eull,
0x202c336472250920ull,0x756d090a3b357225ull,0x3436752e6f6c2e6cull,0x202c346472250920ull,
0x3b34202c33647225ull,0x36752e646461090aull,0x2c35647225092034ull,0x25202c3464722520ull,
0x7663090a3b326472ull,0x33752e3436752e74ull,0x2c36647225092032ull,0x090a3b3831722520ull,
0x752e6f6c2e6c756dull,0x3764722509203436ull,0x202c36647225202cull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x2c31647225202c38ull,0x090a3b3764722520ull,0x203233732e766f6dull,
0x25202c3033722509ull,0x744c240a3b393272ull,0x3a343931385f365full,0x6f6f6c3c2f2f200aull,
0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x6e202c3936322065ull,0x6420676e69747365ull,
0x2c31203a68747065ull,0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,
0x090a6e776f6e6b6eull,0x09383109636f6c2eull,0x6c090a3009343732ull,0x6c61626f6c672e64ull,
0x722509203233752eull,0x6472255b202c3133ull,0x73090a3b5d302b38ull,0x6465726168732e74ull,
0x255b09203233752eull,0x202c5d302b356472ull,0x2e090a3b31337225ull,0x3209383109636f6cull,
0x6461090a30093537ull,0x2509203436752e64ull,0x647225202c356472ull,0x0a3b363138202c35ull,
0x3233752e64646109ull,0x202c393172250920ull,0x3931202c39317225ull,0x2e646461090a3b32ull,
0x6472250920343675ull,0x2c38647225202c38ull,0x73090a3b38363720ull,0x752e74672e707465ull,
0x2c33702509203233ull,0x25202c3132722520ull,0x2540090a3b393172ull,0x0920617262203370ull,
0x31385f365f744c24ull,0x5f744c240a3b3439ull,0x0a3a323836375f36ull,0x3436752e766f6d09ull,
0x202c316472250920ull,0x7553786964615264ull,0x2e766f6d090a3b6dull,0x6472250920343675ull,
0x6964615273202c32ull,0x2e090a3b6d755378ull,0x3209383109636f6cull,0x6162090a30093937ull,
0x0920636e79732e72ull,0x636f6c2e090a3b30ull,0x0933383209383109ull,0x34326c756d090a30ull,
0x203233752e6f6c2eull,0x25202c3233722509ull,0x0a3b3731202c3172ull,0x3233732e766f6d09ull,
0x202c333372250920ull,0x61090a3b32337225ull,0x09203233752e6464ull,0x7225202c34337225ull,
0x0a3b3631202c3233ull,0x74672e7074657309ull,0x702509203233752eull,0x2c34337225202c34ull,
0x090a3b3233722520ull,0x7262203470252140ull,0x365f744c24092061ull,0x090a3b363037385full,
0x2e3436732e747663ull,0x6472250920323373ull,0x3b32337225202c39ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c303164ull,0x61090a3b34202c39ull,0x09203436752e6464ull,
0x25202c3131647225ull,0x647225202c326472ull,0x766f6d090a3b3031ull,0x722509203233752eull,
0x240a3b30202c3533ull,0x3132395f365f744cull,0x6c3c2f2f200a3a38ull,0x6f6f4c203e706f6full,
0x6c2079646f622070ull,0x2c33383220656e69ull,0x676e697473656e20ull,0x203a687470656420ull,
0x6172657469202c31ull,0x31203a736e6f6974ull,0x09636f6c2e090a36ull,0x3009383832093831ull,
0x6168732e646c090aull,0x203233752e646572ull,0x5b202c3633722509ull,0x5d302b3131647225ull,
0x752e646461090a3bull,0x3533722509203233ull,0x202c36337225202cull,0x2e090a3b35337225ull,
0x3209383109636f6cull,0x7473090a30093938ull,0x2e6465726168732eull,0x72255b0920323375ull,
0x202c5d302b313164ull,0x2e090a3b35337225ull,0x3209383109636f6cull,0x6461090a30093039ull,
0x2509203233732e64ull,0x337225202c333372ull,0x61090a3b31202c33ull,0x09203436752e6464ull,
0x25202c3131647225ull,0x3b34202c31316472ull,0x6e2e70746573090aull,0x2509203233752e65ull,
0x33337225202c3570ull,0x0a3b34337225202cull,0x7262203570254009ull,0x365f744c24092061ull,
0x240a3b383132395full,0x3037385f365f744cull,0x636f6c2e090a3a36ull,0x0932393209383109ull,
0x732e726162090a30ull,0x0a3b300920636e79ull,0x383109636f6c2e09ull,0x090a300935303309ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x32337225202c3231ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c33316472ull,0x0a3b34202c323164ull,0x3436752e64646109ull,
0x2c34316472250920ull,0x25202c3264722520ull,0x6c090a3b33316472ull,0x6465726168732e64ull,
0x722509203233752eull,0x6472255b202c3733ull,0x0a3b5d30362b3431ull,0x726168732e747309ull,
0x09203233752e6465ull,0x362b34316472255bull,0x37337225202c5d34ull,0x09636f6c2e090a3bull,
0x3009363033093831ull,0x79732e726162090aull,0x090a3b300920636eull,0x203233732e766f6dull,
0x31202c3833722509ull,0x365f744c240a3b37ull,0x0a3a32343230315full,0x706f6f6c3c2f2f20ull,
0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c36303320ull,0x656420676e697473ull,
0x202c31203a687470ull,0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,
0x73090a6e776f6e6bull,0x09203233732e6275ull,0x7225202c39337225ull,0x38337225202c3233ull,
0x732e646461090a3bull,0x3034722509203233ull,0x202c39337225202cull,0x766f6d090a3b3631ull,
0x722509203233752eull,0x090a3b30202c3134ull,0x2e656c2e70746573ull,0x3670250920323373ull,
0x202c30347225202cull,0x40090a3b31347225ull,0x2061726220367025ull,0x315f365f744c2409ull,
0x2f200a3b34353730ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3320656e696c2079ull,0x64616568202c3630ull,0x64656c6562616c20ull,0x315f365f744c2420ull,
0x6c2e090a32343230ull,0x313309383109636full,0x747663090a300932ull,0x3233732e3436732eull,
0x2c35316472250920ull,0x090a3b3933722520ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,
0x3531647225202c36ull,0x6461090a3b34202cull,0x2509203436752e64ull,0x7225202c37316472ull,
0x31647225202c3264ull,0x732e646c090a3b36ull,0x33752e6465726168ull,0x2c32347225092032ull,
0x2b37316472255b20ull,0x7262090a3b5d3436ull,0x240920696e752e61ull,0x3430315f365f744cull,
0x5f744c240a3b3839ull,0x3a34353730315f36ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3630332065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32343230315f36ull,0x3233752e766f6d09ull,0x202c323472250920ull,
0x365f744c240a3b30ull,0x0a3a38393430315full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36303320ull,0x6c6562616c206461ull,
0x365f744c24206465ull,0x090a32343230315full,0x09383109636f6c2eull,0x62090a3009333133ull,
0x20636e79732e7261ull,0x6f6c2e090a3b3009ull,0x3431330938310963ull,0x732e646c090a3009ull,
0x33752e6465726168ull,0x2c33347225092032ull,0x2b34316472255b20ull,0x6461090a3b5d3436ull,
0x2509203233752e64ull,0x347225202c343472ull,0x3b32347225202c33ull,0x6168732e7473090aull,
0x203233752e646572ull,0x2b34316472255b09ull,0x347225202c5d3436ull,0x636f6c2e090a3b34ull,
0x0935313309383109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,0x383109636f6c2e09ull,
0x090a300936313309ull,0x732e6f6c2e6c756dull,0x3833722509203233ull,0x202c38337225202cull,
0x2e766f6d090a3b32ull,0x3472250920323375ull,0x3b33363233202c35ull,0x6c2e70746573090aull,
0x2509203233732e65ull,0x38337225202c3770ull,0x0a3b35347225202cull,0x7262203770254009ull,
0x365f744c24092061ull,0x0a3b32343230315full,0x383109636f6c2e09ull,0x090a300935323309ull,
0x203233732e766f6dull,0x25202c3333722509ull,0x7573090a3b323372ull,0x2509203233732e62ull,
0x337225202c363472ull,0x6d090a3b31202c32ull,0x09203233752e766full,0x3b30202c37347225ull,
0x6c2e70746573090aull,0x2509203233732e65ull,0x36347225202c3870ull,0x0a3b37347225202cull,
0x7262203870254009ull,0x365f744c24092061ull,0x0a3b32323531315full,0x383109636f6c2e09ull,
0x090a300938323309ull,0x65726168732e646cull,0x2509203233752e64ull,0x72255b202c383472ull,
0x3b5d342d2b343164ull,0x6e752e617262090aull,0x365f744c24092069ull,0x0a3b36363231315full,
0x31315f365f744c24ull,0x6f6d090a3a323235ull,0x2509203233752e76ull,0x0a3b30202c383472ull,
0x31315f365f744c24ull,0x2140090a3a363632ull,0x2061726220347025ull,0x315f365f744c2409ull,
0x6d090a3b38373731ull,0x09203436732e766full,0x25202c3131647225ull,0x4c240a3b34316472ull,
0x393232315f365f74ull,0x6c3c2f2f200a3a30ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,
0x2c38323320656e69ull,0x676e697473656e20ull,0x203a687470656420ull,0x6172657469202c31ull,
0x31203a736e6f6974ull,0x09636f6c2e090a36ull,0x3009313333093831ull,0x6168732e646c090aull,
0x203233752e646572ull,0x5b202c3934722509ull,0x5d302b3131647225ull,0x752e646461090a3bull,
0x3035722509203233ull,0x202c39347225202cull,0x73090a3b38347225ull,0x6465726168732e74ull,
0x255b09203233752eull,0x2c5d302b31316472ull,0x090a3b3035722520ull,0x09383109636f6c2eull,
0x61090a3009323333ull,0x09203233732e6464ull,0x7225202c33337225ull,0x090a3b31202c3333ull,
0x203436752e646461ull,0x202c313164722509ull,0x34202c3131647225ull,0x2e70746573090a3bull,
0x09203233752e656eull,0x337225202c397025ull,0x3b34337225202c33ull,0x622039702540090aull,
0x5f744c2409206172ull,0x3b30393232315f36ull,0x315f365f744c240aull,0x2e090a3a38373731ull,
0x3309383109636f6cull,0x6162090a30093433ull,0x0920636e79732e72ull,0x636f6c2e090a3b30ull,
0x0935343309383109ull,0x752e646461090a30ull,0x3135722509203233ull,0x202c38317225202cull,
0x2e766f6d090a3b31ull,0x3172250920323373ull,0x3b31357225202c39ull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x2c397225202c3235ull,0x61090a3b36353220ull,0x09203233752e6464ull,
0x7225202c33357225ull,0x3b363532202c3235ull,0x33752e726873090aull,0x2c34357225092032ull,
0x34202c3335722520ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x357225202c353572ull,
0x0a3b323931202c34ull,0x656c2e7074657309ull,0x702509203233752eull,0x35357225202c3031ull,
0x0a3b31357225202cull,0x6220303170254009ull,0x5f744c2409206172ull,0x3b32303832315f36ull,
0x33752e627573090aull,0x2c36357225092032ull,0x25202c3535722520ull,0x6461090a3b313572ull,
0x2509203233752e64ull,0x357225202c373572ull,0x0a3b313931202c36ull,0x3233732e766f6d09ull,
0x202c383572250920ull,0x353536313334312dull,0x6f6d090a3b353637ull,0x2509203233732e76ull,
0x0a3b30202c393572ull,0x746c2e7074657309ull,0x702509203233732eull,0x37357225202c3131ull,
0x0a3b39357225202cull,0x3233732e73626109ull,0x202c303672250920ull,0x6d090a3b37357225ull,
0x33752e69682e6c75ull,0x2c31367225092032ull,0x25202c3036722520ull,0x6873090a3b383572ull,
0x2509203233732e72ull,0x367225202c323672ull,0x40090a3b37202c31ull,0x6275732031317025ull,
0x722509203233732eull,0x39357225202c3236ull,0x0a3b32367225202cull,0x3233732e766f6d09ull,
0x202c333672250920ull,0x63090a3b32367225ull,0x752e3436752e7476ull,0x3164722509203233ull,
0x0a3b357225202c38ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3931ull,
0x61090a3b34202c38ull,0x09203436752e6464ull,0x7225202c35647225ull,0x647225202c393164ull,
0x2e747663090a3b32ull,0x203233752e343675ull,0x202c303264722509ull,0x6d090a3b31357225ull,
0x36752e6f6c2e6c75ull,0x3132647225092034ull,0x2c3032647225202cull,0x646461090a3b3420ull,
0x722509203436752eull,0x31647225202c3864ull,0x3b3132647225202cull,0x33732e766f6d090aull,
0x2c34367225092032ull,0x240a3b3336722520ull,0x3333315f365f744cull,0x3c2f2f200a3a3431ull,
0x6f4c203e706f6f6cull,0x2079646f6220706full,0x35343320656e696cull,0x6e697473656e202cull,
0x3a68747065642067ull,0x69747365202c3120ull,0x746920646574616dull,0x736e6f6974617265ull,
0x776f6e6b6e75203aull,0x09636f6c2e090a6eull,0x3009383433093831ull,0x6168732e646c090aull,
0x203233752e646572ull,0x5b202c3536722509ull,0x3b5d302b35647225ull,0x6f6c672e7473090aull,
0x203233752e6c6162ull,0x302b386472255b09ull,0x3b35367225202c5dull,0x3109636f6c2e090aull,
0x0a30093035330938ull,0x3436752e64646109ull,0x202c356472250920ull,0x3138202c35647225ull,
0x2e646461090a3b36ull,0x3172250920323375ull,0x2c39317225202c39ull,0x61090a3b32393120ull,
0x09203436752e6464ull,0x7225202c38647225ull,0x3b383637202c3864ull,0x672e70746573090aull,
0x2509203233752e74ull,0x357225202c323170ull,0x3b39317225202c35ull,0x203231702540090aull,
0x744c240920617262ull,0x34313333315f365full,0x5f365f744c240a3bull,0x090a3a3230383231ull,
0x203233752e766f6dull,0x30202c3636722509ull,0x2e70746573090a3bull,0x09203233752e656eull,
0x7225202c33317025ull,0x3b36367225202c31ull,0x203331702540090aull,0x744c240920617262ull,
0x36323833315f365full,0x09636f6c2e090a3bull,0x3009373533093831ull,0x6168732e646c090aull,
0x203233752e646572ull,0x5b202c3736722509ull,0x7553786964615273ull,0x5d32353033312b6dull,
0x752e766f6d090a3bull,0x3264722509203436ull,0x6964615264202c32ull,0x75536b636f6c4278ull,
0x2e747663090a3b6dull,0x203233752e343675ull,0x202c333264722509ull,0x756d090a3b397225ull,
0x3436752e6f6c2e6cull,0x2c34326472250920ull,0x202c333264722520ull,0x2e646461090a3b34ull,
0x6472250920343675ull,0x32647225202c3532ull,0x3432647225202c32ull,0x6c672e7473090a3bull,
0x3233752e6c61626full,0x35326472255b0920ull,0x367225202c5d302bull,0x636f6c2e090a3b37ull,
0x0938353309383109ull,0x752e766f6d090a30ull,0x3836722509203233ull,0x7663090a3b30202cull,
0x33752e3436752e74ull,0x3632647225092032ull,0x0a3b30327225202cull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x32647225202c3732ull,0x61090a3b34202c36ull,0x09203436752e6464ull,
0x25202c3832647225ull,0x647225202c316472ull,0x2e7473090a3b3732ull,0x752e6c61626f6c67ull,
0x6472255b09203233ull,0x25202c5d302b3832ull,0x744c240a3b383672ull,0x36323833315f365full,
0x09636f6c2e090a3aull,0x3009303633093831ull,0x0a3b74697865090aull,0x5f646e6557444c24ull,
0x6964615234315a5full,0x5378696665725078ull,0x207d090a3a766d75ull,0x5234315a5f202f2full,
0x6665725078696461ull,0x0a0a766d75537869ull,0x207972746e652e09ull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x2e09090a2820696aull,0x752e206d61726170ull,0x6475635f5f203436ull,
0x5a5f5f6d72617061ull,0x4178696461523532ull,0x74657366664f6464ull,0x66756853646e4173ull,
0x654b323150656c66ull,0x615065756c615679ull,0x696a6a5f30537269ull,0x090a2c637253705full,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x2c747344705f696aull,0x617261702e09090aull,0x5f203233752e206dull,
0x726170616475635full,0x615235325a5f5f6dull,0x664f646441786964ull,0x646e417374657366ull,
0x50656c6666756853ull,0x6c615679654b3231ull,0x3053726961506575ull,0x656c655f696a6a5full,
0x090a2c73746e656dull,0x206d617261702e09ull,0x635f5f203233752eull,0x5f6d726170616475ull,
0x6964615235325a5full,0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,
0x65756c615679654bull,0x6a5f305372696150ull,0x656d656c655f696aull,0x6e756f725f73746eull,
0x335f6f745f646564ull,0x2e09090a2c323730ull,0x732e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x4178696461523532ull,0x74657366664f6464ull,0x66756853646e4173ull,
0x654b323150656c66ull,0x615065756c615679ull,0x696a6a5f30537269ull,0x0a2974666968735full,
0x6765722e090a7b09ull,0x7225203233752e20ull,0x090a3b3e3132323cull,0x36752e206765722eull,
0x32313c6472252034ull,0x65722e090a3b3e35ull,0x20646572702e2067ull,0x0a3b3e35343c7025ull,
0x383109636f6c2e09ull,0x240a300934373309ull,0x325a5f5f3142424cull,0x6441786964615235ull,
0x7374657366664f64ull,0x6666756853646e41ull,0x79654b323150656cull,0x69615065756c6156ull,
0x3a696a6a5f305372ull,0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3172ull,
0x766f6d090a3b782eull,0x722509203233752eull,0x73090a3b30202c32ull,0x752e656e2e707465ull,
0x2c31702509203233ull,0x7225202c31722520ull,0x31702540090a3b32ull,0x4c24092061726220ull,
0x313833325f375f74ull,0x636f6c2e090a3b30ull,0x0938373309383109ull,0x752e766f6d090a30ull,
0x2c33722509203233ull,0x2e7473090a3b3020ull,0x752e646572616873ull,0x6152735b09203233ull,
0x342b6d7553786964ull,0x7225202c5d363930ull,0x375f744c240a3b33ull,0x0a3a30313833325full,
0x3233752e766f6d09ull,0x31202c3472250920ull,0x70746573090a3b34ull,0x203233752e74672eull,
0x7225202c32702509ull,0x0a3b347225202c31ull,0x7262203270254009ull,0x375f744c24092061ull,
0x0a3b32323334325full,0x383109636f6c2e09ull,0x090a300931383309ull,0x203436752e766f6dull,
0x73202c3164722509ull,0x6d75537869646152ull,0x752e747663090a3bull,0x09203233752e3436ull,
0x7225202c32647225ull,0x2e6c756d090a3b31ull,0x09203436752e6f6cull,0x7225202c33647225ull,
0x090a3b34202c3264ull,0x203436752e766f6dull,0x64202c3464722509ull,0x6f6c427869646152ull,
0x090a3b6d75536b63ull,0x203436752e646461ull,0x25202c3564722509ull,0x647225202c336472ull,
0x672e646c090a3b34ull,0x33752e6c61626f6cull,0x202c357225092032ull,0x5d302b356472255bull,
0x752e646461090a3bull,0x3664722509203436ull,0x202c33647225202cull,0x73090a3b31647225ull,
0x6465726168732e74ull,0x255b09203233752eull,0x303031342b366472ull,0x0a3b357225202c5dull,
0x34325f375f744c24ull,0x6f6d090a3a323233ull,0x2509203436752e76ull,0x615273202c316472ull,
0x0a3b6d7553786964ull,0x383109636f6c2e09ull,0x090a300932383309ull,0x636e79732e726162ull,
0x6f6d090a3b300920ull,0x2509203233732e76ull,0x0a3b3531202c3672ull,0x656c2e7074657309ull,
0x702509203233732eull,0x202c317225202c33ull,0x6573090a3b367225ull,0x09203233732e706cull,
0x202c31202c377225ull,0x0a3b337025202c30ull,0x3233732e766f6d09ull,0x31202c3872250920ull,
0x5f375f744c240a3bull,0x200a3a3634333532ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,
0x20656e696c207964ull,0x73656e202c323833ull,0x70656420676e6974ull,0x65202c31203a6874ull,
0x646574616d697473ull,0x6974617265746920ull,0x6b6e75203a736e6full,0x7573090a6e776f6eull,
0x2509203233732e62ull,0x2c317225202c3972ull,0x6d090a3b38722520ull,0x09203233732e766full,
0x3b30202c30317225ull,0x65672e746573090aull,0x3233732e3233752eull,0x202c313172250920ull,
0x317225202c397225ull,0x2e67656e090a3b30ull,0x3172250920323373ull,0x3b31317225202c32ull,
0x33622e646e61090aull,0x2c33317225092032ull,0x25202c3231722520ull,0x766f6d090a3b3772ull,
0x722509203233752eull,0x090a3b30202c3431ull,0x2e71652e70746573ull,0x3470250920323373ull,
0x202c33317225202cull,0x40090a3b34317225ull,0x2061726220347025ull,0x325f375f744c2409ull,
0x2f200a3b38353835ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3320656e696c2079ull,0x64616568202c3238ull,0x64656c6562616c20ull,0x325f375f744c2420ull,
0x6c2e090a36343335ull,0x393309383109636full,0x747663090a300930ull,0x3233732e3436732eull,
0x202c376472250920ull,0x756d090a3b397225ull,0x3436752e6f6c2e6cull,0x202c386472250920ull,
0x3b34202c37647225ull,0x36752e646461090aull,0x2c39647225092034ull,0x25202c3164722520ull,
0x646c090a3b386472ull,0x2e6465726168732eull,0x3172250920323375ull,0x396472255b202c35ull,
0x0a3b5d363930342bull,0x696e752e61726209ull,0x5f375f744c240920ull,0x240a3b3230363532ull,
0x3835325f375f744cull,0x3c2f2f200a3a3835ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x32383320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3335325f375f744cull,0x2e766f6d090a3634ull,0x3172250920323375ull,0x4c240a3b30202c35ull,
0x303635325f375f74ull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c32383320656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x343335325f375f74ull,0x09636f6c2e090a36ull,0x3009313933093831ull,0x79732e726162090aull,
0x090a3b300920636eull,0x7262203370252140ull,0x375f744c24092061ull,0x0a3b34313136325full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c32383320ull,0x6c6562616c206461ull,0x375f744c24206465ull,0x090a36343335325full,
0x09383109636f6c2eull,0x63090a3009333933ull,0x732e3436732e7476ull,0x3164722509203233ull,
0x0a3b317225202c30ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3131ull,
0x61090a3b34202c30ull,0x09203436752e6464ull,0x25202c3231647225ull,0x647225202c316472ull,
0x2e646c090a3b3131ull,0x752e646572616873ull,0x3631722509203233ull,0x32316472255b202cull,
0x0a3b5d363930342bull,0x3233752e64646109ull,0x202c373172250920ull,0x7225202c36317225ull,
0x2e7473090a3b3531ull,0x752e646572616873ull,0x6472255b09203233ull,0x5d363930342b3231ull,
0x0a3b37317225202cull,0x36325f375f744c24ull,0x2f2f200a3a343131ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x383320656e696c20ull,0x2064616568202c32ull,
0x2064656c6562616cull,0x35325f375f744c24ull,0x6f6c2e090a363433ull,0x3439330938310963ull,
0x2e726162090a3009ull,0x3b300920636e7973ull,0x3109636f6c2e090aull,0x0a30093539330938ull,
0x2e6f6c2e6c756d09ull,0x3872250920323373ull,0x32202c387225202cull,0x752e766f6d090a3bull,
0x3831722509203233ull,0x73090a3b3531202cull,0x732e656c2e707465ull,0x2c35702509203233ull,
0x7225202c38722520ull,0x702540090a3b3831ull,0x2409206172622035ull,0x3335325f375f744cull,
0x6f6c2e090a3b3634ull,0x3930340938310963ull,0x2e646e61090a3009ull,0x3172250920323362ull,
0x202c317225202c39ull,0x2e726873090a3b33ull,0x3272250920323375ull,0x202c317225202c30ull,
0x2e747663090a3b32ull,0x203631752e323375ull,0x25202c3132722509ull,0x3b782e6469617463ull,
0x2e34326c756d090aull,0x09203233752e6f6cull,0x7225202c32327225ull,0x0a3b3834202c3032ull,
0x3233752e64646109ull,0x202c333272250920ull,0x7225202c31327225ull,0x6c756d090a3b3232ull,
0x203233752e6f6c2eull,0x25202c3432722509ull,0x0a3b34202c333272ull,0x3233752e64646109ull,
0x202c353272250920ull,0x7225202c39317225ull,0x6c756d090a3b3432ull,0x33732e6f6c2e3432ull,
0x2c36327225092032ull,0x34202c3032722520ull,0x732e646461090a3bull,0x3732722509203233ull,
0x202c36327225202cull,0x6d090a3b39317225ull,0x09203233732e766full,0x7225202c38327225ull,
0x766f6d090a3b3732ull,0x722509203233752eull,0x33323031202c3932ull,0x2e70746573090a3bull,
0x09203233732e7467ull,0x327225202c367025ull,0x3b39327225202c37ull,0x622036702540090aull,
0x5f744c2409206172ull,0x3b32383836325f37ull,0x33732e766f6d090aull,0x2c30337225092032ull,
0x090a3b3738303120ull,0x203233732e627573ull,0x25202c3133722509ull,0x327225202c303372ull,
0x2e726873090a3b37ull,0x3372250920323373ull,0x2c31337225202c32ull,0x6f6d090a3b313320ull,
0x2509203233732e76ull,0x3b3336202c333372ull,0x33622e646e61090aull,0x2c34337225092032ull,
0x25202c3233722520ull,0x6461090a3b333372ull,0x2509203233732e64ull,0x337225202c353372ull,
0x3b31337225202c34ull,0x33732e726873090aull,0x2c36337225092032ull,0x36202c3533722520ull,
0x752e766f6d090a3bull,0x3164722509203436ull,0x6964615264202c33ull,0x63090a3b6d755378ull,
0x732e3436732e7476ull,0x3164722509203233ull,0x3b35327225202c34ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c353164ull,0x090a3b34202c3431ull,0x203436752e646461ull,
0x202c363164722509ull,0x25202c3331647225ull,0x63090a3b35316472ull,0x732e3436732e7476ull,
0x3164722509203233ull,0x3b37327225202c37ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c383164ull,0x090a3b34202c3731ull,0x203436752e646461ull,0x202c393164722509ull,
0x7225202c31647225ull,0x6f6d090a3b383164ull,0x2509203233732e76ull,0x337225202c373372ull,
0x375f744c240a3b36ull,0x0a3a34393337325full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,
0x656e696c2079646full,0x656e202c39303420ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6574616d69747365ull,0x7461726574692064ull,0x6e75203a736e6f69ull,0x2e090a6e776f6e6bull,
0x3409383109636f6cull,0x646c090a30093231ull,0x2e6c61626f6c672eull,0x3372250920323375ull,
0x316472255b202c38ull,0x6d090a3b5d302b36ull,0x09203233732e766full,0x312d202c39337225ull,
0x3637353536313334ull,0x2e766f6d090a3b35ull,0x3472250920323373ull,0x73090a3b30202c30ull,
0x732e746c2e707465ull,0x2c37702509203233ull,0x25202c3532722520ull,0x6261090a3b303472ull,
0x2509203233732e73ull,0x327225202c313472ull,0x2e6c756d090a3b35ull,0x09203233752e6968ull,
0x7225202c32347225ull,0x39337225202c3134ull,0x732e726873090a3bull,0x3334722509203233ull,
0x202c32347225202cull,0x702540090a3b3131ull,0x33732e6275732037ull,0x2c33347225092032ull,
0x25202c3034722520ull,0x6f6d090a3b333472ull,0x2509203233732e76ull,0x347225202c343472ull,
0x2e747663090a3b33ull,0x203233732e343673ull,0x202c303264722509ull,0x6d090a3b34347225ull,
0x36752e6f6c2e6c75ull,0x3132647225092034ull,0x2c3032647225202cull,0x646461090a3b3420ull,
0x722509203436752eull,0x647225202c323264ull,0x3132647225202c31ull,0x68732e646c090a3bull,
0x3233752e64657261ull,0x202c353472250920ull,0x342b32326472255bull,0x61090a3b5d363930ull,
0x09203233752e6464ull,0x7225202c36347225ull,0x35347225202c3833ull,0x68732e7473090a3bull,
0x3233752e64657261ull,0x39316472255b0920ull,0x347225202c5d302bull,0x636f6c2e090a3b36ull,
0x0934313409383109ull,0x732e646461090a30ull,0x3532722509203233ull,0x202c35327225202cull,
0x61090a3b32373033ull,0x09203436752e6464ull,0x25202c3631647225ull,0x3231202c36316472ull,
0x6461090a3b383832ull,0x2509203233732e64ull,0x327225202c383272ull,0x090a3b3436202c38ull,
0x203436752e646461ull,0x202c393164722509ull,0x32202c3931647225ull,0x766f6d090a3b3635ull,
0x722509203233752eull,0x33323031202c3734ull,0x2e70746573090a3bull,0x09203233732e656cull,
0x327225202c387025ull,0x3b37347225202c38ull,0x622038702540090aull,0x5f744c2409206172ull,
0x3b34393337325f37ull,0x325f375f744c240aull,0x2e090a3a32383836ull,0x3409383109636f6cull,
0x6162090a30093631ull,0x0920636e79732e72ull,0x636f6c2e090a3b30ull,0x0931333409383109ull,
0x732e726162090a30ull,0x0a3b300920636e79ull,0x3233622e646e6109ull,0x202c383472250920ull,
0x3b3531202c317225ull,0x33752e726873090aull,0x2c39347225092032ull,0x3b34202c31722520ull,
0x2e34326c756d090aull,0x09203233752e6f6cull,0x7225202c30357225ull,0x090a3b34202c3132ull,
0x6d617261702e646cull,0x722509203233752eull,0x635f5f5b202c3135ull,0x5f6d726170616475ull,
0x6964615235325a5full,0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,
0x65756c615679654bull,0x6a5f305372696150ull,0x656d656c655f696aull,0x6e756f725f73746eull,
0x335f6f745f646564ull,0x6d090a3b5d323730ull,0x09203233752e766full,0x312d202c32357225ull,
0x3637353536313334ull,0x2e6c756d090a3b35ull,0x09203233752e6968ull,0x7225202c33357225ull,
0x32357225202c3135ull,0x752e726873090a3bull,0x3435722509203233ull,0x202c33357225202cull,
0x2e646461090a3b37ull,0x3572250920323375ull,0x2c39347225202c35ull,0x090a3b3035722520ull,
0x752e6f6c2e6c756dull,0x3635722509203233ull,0x202c34357225202cull,0x61090a3b35357225ull,
0x09203233732e6464ull,0x7225202c37357225ull,0x36357225202c3834ull,0x732e766f6d090a3bull,
0x3835722509203233ull,0x0a3b37357225202cull,0x3233752e64646109ull,0x202c393572250920ull,
0x7225202c34357225ull,0x746573090a3b3635ull,0x3233752e65672e70ull,0x25202c3970250920ull,
0x357225202c373572ull,0x39702540090a3b39ull,0x4c24092061726220ull,0x303937325f375f74ull,
0x2e627573090a3b36ull,0x3672250920323375ull,0x2c34357225202c30ull,0x090a3b3834722520ull,
0x203233752e646461ull,0x25202c3136722509ull,0x3b3531202c303672ull,0x33732e726873090aull,
0x2c32367225092032ull,0x33202c3136722520ull,0x2e766f6d090a3b31ull,0x3672250920323373ull,
0x090a3b3531202c33ull,0x203233622e646e61ull,0x25202c3436722509ull,0x367225202c323672ull,
0x2e646461090a3b33ull,0x3672250920323373ull,0x2c34367225202c35ull,0x090a3b3136722520ull,
0x203233732e726873ull,0x25202c3636722509ull,0x0a3b34202c353672ull,0x3233732e766f6d09ull,
0x202c373672250920ull,0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3031702509ull,
0x367225202c383472ull,0x2e766f6d090a3b37ull,0x3672250920323373ull,0x73090a3b31202c38ull,
0x732e71652e707465ull,0x3131702509203233ull,0x202c38347225202cull,0x6d090a3b38367225ull,
0x09203233732e766full,0x3b32202c39367225ull,0x652e70746573090aull,0x2509203233732e71ull,
0x347225202c323170ull,0x3b39367225202c38ull,0x33732e766f6d090aull,0x2c30377225092032ull,
0x746573090a3b3320ull,0x3233732e71652e70ull,0x202c333170250920ull,0x7225202c38347225ull,
0x766f6d090a3b3037ull,0x722509203233732eull,0x090a3b34202c3137ull,0x2e71652e70746573ull,
0x3170250920323373ull,0x2c38347225202c34ull,0x090a3b3137722520ull,0x203233732e766f6dull,
0x35202c3237722509ull,0x2e70746573090a3bull,0x09203233732e7165ull,0x7225202c35317025ull,
0x32377225202c3834ull,0x732e766f6d090a3bull,0x3337722509203233ull,0x6573090a3b36202cull,
0x33732e71652e7074ull,0x2c36317025092032ull,0x25202c3834722520ull,0x6f6d090a3b333772ull,
0x2509203233732e76ull,0x0a3b37202c343772ull,0x71652e7074657309ull,0x702509203233732eull,
0x38347225202c3731ull,0x0a3b34377225202cull,0x3233732e766f6d09ull,0x202c353772250920ull,
0x70746573090a3b38ull,0x203233732e71652eull,0x25202c3831702509ull,0x377225202c383472ull,
0x2e766f6d090a3b35ull,0x3772250920323373ull,0x73090a3b39202c36ull,0x732e71652e707465ull,
0x3931702509203233ull,0x202c38347225202cull,0x6d090a3b36377225ull,0x09203233732e766full,
0x3031202c37377225ull,0x2e70746573090a3bull,0x09203233732e7165ull,0x7225202c30327025ull,
0x37377225202c3834ull,0x732e766f6d090a3bull,0x3837722509203233ull,0x73090a3b3131202cull,
0x732e71652e707465ull,0x3132702509203233ull,0x202c38347225202cull,0x6d090a3b38377225ull,
0x09203233732e766full,0x3231202c39377225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x7225202c32327025ull,0x39377225202c3834ull,0x732e766f6d090a3bull,0x3038722509203233ull,
0x73090a3b3331202cull,0x732e71652e707465ull,0x3332702509203233ull,0x202c38347225202cull,
0x6d090a3b30387225ull,0x09203233732e766full,0x3431202c31387225ull,0x2e70746573090a3bull,
0x09203233732e7165ull,0x7225202c34327025ull,0x31387225202c3834ull,0x732e766f6d090a3bull,
0x3238722509203233ull,0x73090a3b3531202cull,0x732e71652e707465ull,0x3532702509203233ull,
0x202c38347225202cull,0x73090a3b32387225ull,0x203233732e706c65ull,0x31202c3338722509ull,
0x317025202c30202cull,0x706c6573090a3b30ull,0x722509203233732eull,0x30202c31202c3438ull,
0x0a3b31317025202cull,0x33732e706c657309ull,0x2c35387225092032ull,0x25202c30202c3120ull,
0x6573090a3b323170ull,0x09203233732e706cull,0x2c31202c36387225ull,0x33317025202c3020ull,
0x2e706c6573090a3bull,0x3872250920323373ull,0x2c30202c31202c37ull,0x090a3b3431702520ull,
0x3233732e706c6573ull,0x202c383872250920ull,0x7025202c30202c31ull,0x6c6573090a3b3531ull,
0x2509203233732e70ull,0x202c31202c393872ull,0x3b36317025202c30ull,0x732e706c6573090aull,
0x3039722509203233ull,0x202c30202c31202cull,0x73090a3b37317025ull,0x203233732e706c65ull,
0x31202c3139722509ull,0x317025202c30202cull,0x706c6573090a3b38ull,0x722509203233732eull,
0x30202c31202c3239ull,0x0a3b39317025202cull,0x33732e706c657309ull,0x2c33397225092032ull,
0x25202c30202c3120ull,0x6573090a3b303270ull,0x09203233732e706cull,0x2c31202c34397225ull,
0x31327025202c3020ull,0x2e706c6573090a3bull,0x3972250920323373ull,0x2c30202c31202c35ull,
0x090a3b3232702520ull,0x3233732e706c6573ull,0x202c363972250920ull,0x7025202c30202c31ull,
0x6c6573090a3b3332ull,0x2509203233732e70ull,0x202c31202c373972ull,0x3b34327025202c30ull,
0x732e706c6573090aull,0x3839722509203233ull,0x202c30202c31202cull,0x6c090a3b35327025ull,
0x2e6d617261702e64ull,0x3972250920323375ull,0x75635f5f5b202c39ull,0x5f5f6d7261706164ull,
0x786964615235325aull,0x657366664f646441ull,0x756853646e417374ull,0x4b323150656c6666ull,
0x5065756c61567965ull,0x6a6a5f3053726961ull,0x6e656d656c655f69ull,0x6f6d090a3b5d7374ull,
0x2509203233732e76ull,0x7225202c30303172ull,0x5f744c240a3b3636ull,0x3a38313438325f37ull,
0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x6e202c3133342065ull,
0x6420676e69747365ull,0x2c31203a68747065ull,0x74616d6974736520ull,0x6172657469206465ull,
0x75203a736e6f6974ull,0x090a6e776f6e6b6eull,0x2e746c2e70746573ull,0x3270250920323375ull,
0x2c38357225202c36ull,0x090a3b3939722520ull,0x6220363270252140ull,0x5f744c2409206172ull,
0x3b30333938325f37ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3133342065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a38313438325f37ull,0x383109636f6c2e09ull,0x090a300930343409ull,0x6d617261702e646cull,
0x722509203436752eull,0x5f5f5b202c333264ull,0x6d72617061647563ull,0x64615235325a5f5full,
0x66664f6464417869ull,0x53646e4173746573ull,0x3150656c66667568ull,0x756c615679654b32ull,
0x5f30537269615065ull,0x637253705f696a6aull,0x2e747663090a3b5dull,0x203233732e343675ull,
0x202c343264722509ull,0x6d090a3b38357225ull,0x36752e6f6c2e6c75ull,0x3532647225092034ull,
0x2c3432647225202cull,0x646461090a3b3820ull,0x722509203436752eull,0x647225202c363264ull,
0x32647225202c3332ull,0x672e646c090a3b35ull,0x32762e6c61626f6cull,0x257b09203233752eull,
0x3172252c31303172ull,0x72255b202c7d3230ull,0x0a3b5d302b363264ull,0x3233732e766f6d09ull,
0x2c33303172250920ull,0x0a3b323031722520ull,0x696e752e61726209ull,0x5f375f744c240920ull,
0x240a3b3437363832ull,0x3938325f375f744cull,0x3c2f2f200a3a3033ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x31333420656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3438325f375f744cull,0x636f6c2e090a3831ull,0x0933343409383109ull,
0x752e766f6d090a30ull,0x3031722509203233ull,0x4c240a3b30202c31ull,0x373638325f375f74ull,
0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c31333420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x313438325f375f74ull,
0x2e706c6573090a38ull,0x3172250920323373ull,0x30202c31202c3430ull,0x0a3b36327025202cull,
0x3233622e646e6109ull,0x2c35303172250920ull,0x202c343031722520ull,0x6d090a3b33387225ull,
0x09203233752e766full,0x30202c3630317225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x7225202c37327025ull,0x317225202c353031ull,0x702540090a3b3630ull,0x0920617262203732ull,
0x39325f375f744c24ull,0x2f2f200a3b363831ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x333420656e696c20ull,0x2064616568202c31ull,0x2064656c6562616cull,
0x38325f375f744c24ull,0x6f6c2e090a383134ull,0x3437340938310963ull,0x702e646c090a3009ull,
0x3233732e6d617261ull,0x2c37303172250920ull,0x616475635f5f5b20ull,0x325a5f5f6d726170ull,
0x6441786964615235ull,0x7374657366664f64ull,0x6666756853646e41ull,0x79654b323150656cull,
0x69615065756c6156ull,0x5f696a6a5f305372ull,0x0a3b5d7466696873ull,0x3233752e72687309ull,
0x2c38303172250920ull,0x202c313031722520ull,0x090a3b3730317225ull,0x203233622e646e61ull,
0x202c393031722509ull,0x32202c3830317225ull,0x6c756d090a3b3535ull,0x203233752e6f6c2eull,
0x202c303131722509ull,0x34202c3930317225ull,0x752e646461090a3bull,0x3131722509203233ull,
0x2c39347225202c31ull,0x0a3b303131722520ull,0x3436752e74766309ull,0x722509203233752eull,
0x317225202c373264ull,0x6c756d090a3b3131ull,0x203436752e6f6c2eull,0x202c383264722509ull,
0x34202c3732647225ull,0x752e646461090a3bull,0x3264722509203436ull,0x2c31647225202c39ull,
0x0a3b383264722520ull,0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3231317225ull,
0x5d302b3932647225ull,0x752e646461090a3bull,0x3131722509203233ull,0x3231317225202c33ull,
0x7473090a3b31202cull,0x2e6465726168732eull,0x72255b0920323375ull,0x202c5d302b393264ull,
0x090a3b3331317225ull,0x09383109636f6c2eull,0x6c090a3009353734ull,0x2e6d617261702e64ull,
0x6472250920343675ull,0x635f5f5b202c3033ull,0x5f6d726170616475ull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x5d747344705f696aull,0x752e747663090a3bull,0x09203233752e3436ull,
0x25202c3133647225ull,0x6d090a3b32313172ull,0x36752e6f6c2e6c75ull,0x3233647225092034ull,
0x2c3133647225202cull,0x646461090a3b3820ull,0x722509203436752eull,0x647225202c333364ull,
0x33647225202c3033ull,0x2e766f6d090a3b32ull,0x3172250920323373ull,0x30317225202c3431ull,
0x672e7473090a3b33ull,0x32762e6c61626f6cull,0x255b09203233752eull,0x2c5d302b33336472ull,
0x2c31303172257b20ull,0x0a3b7d3431317225ull,0x39325f375f744c24ull,0x2f2f200a3a363831ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333420656e696c20ull,
0x2064616568202c31ull,0x2064656c6562616cull,0x38325f375f744c24ull,0x6f6c2e090a383134ull,
0x3737340938310963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,0x33622e646e61090aull,
0x3531317225092032ull,0x2c3430317225202cull,0x090a3b3438722520ull,0x203233752e766f6dull,
0x202c363131722509ull,0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3832702509ull,
0x7225202c35313172ull,0x2540090a3b363131ull,0x2061726220383270ull,0x325f375f744c2409ull,
0x2f200a3b38393639ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3420656e696c2079ull,0x64616568202c3133ull,0x64656c6562616c20ull,0x325f375f744c2420ull,
0x6c2e090a38313438ull,0x383409383109636full,0x2e646c090a300930ull,0x33732e6d61726170ull,
0x3731317225092032ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4178696461523532ull,
0x74657366664f6464ull,0x66756853646e4173ull,0x654b323150656c66ull,0x615065756c615679ull,
0x696a6a5f30537269ull,0x3b5d74666968735full,0x33752e726873090aull,0x3830317225092032ull,
0x2c3130317225202cull,0x0a3b373131722520ull,0x3233622e646e6109ull,0x2c39303172250920ull,
0x202c383031722520ull,0x756d090a3b353532ull,0x3233752e6f6c2e6cull,0x2c30313172250920ull,
0x202c393031722520ull,0x2e646461090a3b34ull,0x3172250920323375ull,0x39347225202c3831ull,
0x3b3031317225202cull,0x36752e747663090aull,0x2509203233752e34ull,0x7225202c34336472ull,
0x756d090a3b383131ull,0x3436752e6f6c2e6cull,0x2c35336472250920ull,0x202c343364722520ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3932ull,0x3b3533647225202cull,
0x6168732e646c090aull,0x203233752e646572ull,0x202c393131722509ull,0x302b39326472255bull,
0x2e646461090a3b5dull,0x3172250920323375ull,0x31317225202c3032ull,0x73090a3b31202c39ull,
0x6465726168732e74ull,0x255b09203233752eull,0x2c5d302b39326472ull,0x0a3b303231722520ull,
0x383109636f6c2e09ull,0x090a300931383409ull,0x6d617261702e646cull,0x722509203436752eull,
0x5f5f5b202c363364ull,0x6d72617061647563ull,0x64615235325a5f5full,0x66664f6464417869ull,
0x53646e4173746573ull,0x3150656c66667568ull,0x756c615679654b32ull,0x5f30537269615065ull,
0x747344705f696a6aull,0x2e747663090a3b5dull,0x203233752e343675ull,0x202c373364722509ull,
0x090a3b3931317225ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,0x3733647225202c38ull,
0x6461090a3b38202cull,0x2509203436752e64ull,0x7225202c39336472ull,0x647225202c363364ull,
0x766f6d090a3b3833ull,0x722509203233732eull,0x317225202c313231ull,0x2e7473090a3b3330ull,
0x762e6c61626f6c67ull,0x5b09203233752e32ull,0x5d302b3933647225ull,0x31303172257b202cull,
0x3b7d31323172252cull,0x325f375f744c240aull,0x2f200a3a38393639ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3420656e696c2079ull,0x64616568202c3133ull,
0x64656c6562616c20ull,0x325f375f744c2420ull,0x6c2e090a38313438ull,0x383409383109636full,
0x726162090a300933ull,0x300920636e79732eull,0x622e646e61090a3bull,0x3231722509203233ull,
0x3430317225202c32ull,0x0a3b35387225202cull,0x3233752e766f6d09ull,0x2c33323172250920ull,
0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c393270250920ull,0x25202c3232317225ull,
0x40090a3b33323172ull,0x6172622039327025ull,0x5f375f744c240920ull,0x200a3b3031323033ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c313334ull,0x656c6562616c2064ull,0x5f375f744c242064ull,0x2e090a3831343832ull,
0x3409383109636f6cull,0x646c090a30093638ull,0x732e6d617261702eull,0x3231722509203233ull,
0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x786964615235325aull,0x657366664f646441ull,
0x756853646e417374ull,0x4b323150656c6666ull,0x5065756c61567965ull,0x6a6a5f3053726961ull,
0x5d74666968735f69ull,0x752e726873090a3bull,0x3031722509203233ull,0x3130317225202c38ull,
0x3b3432317225202cull,0x33622e646e61090aull,0x3930317225092032ull,0x2c3830317225202cull,
0x6d090a3b35353220ull,0x33752e6f6c2e6c75ull,0x3031317225092032ull,0x2c3930317225202cull,
0x646461090a3b3420ull,0x722509203233752eull,0x347225202c353231ull,0x3031317225202c39ull,
0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3034647225ull,0x6d090a3b35323172ull,
0x36752e6f6c2e6c75ull,0x3134647225092034ull,0x2c3034647225202cull,0x646461090a3b3420ull,
0x722509203436752eull,0x647225202c393264ull,0x3134647225202c31ull,0x68732e646c090a3bull,
0x3233752e64657261ull,0x2c36323172250920ull,0x2b39326472255b20ull,0x646461090a3b5d30ull,
0x722509203233752eull,0x317225202c373231ull,0x090a3b31202c3632ull,0x65726168732e7473ull,
0x5b09203233752e64ull,0x5d302b3932647225ull,0x3b3732317225202cull,0x3109636f6c2e090aull,
0x0a30093738340938ull,0x617261702e646c09ull,0x2509203436752e6dull,0x5f5b202c32346472ull,
0x726170616475635full,0x615235325a5f5f6dull,0x664f646441786964ull,0x646e417374657366ull,
0x50656c6666756853ull,0x6c615679654b3231ull,0x3053726961506575ull,0x7344705f696a6a5full,
0x747663090a3b5d74ull,0x3233752e3436752eull,0x2c33346472250920ull,0x0a3b363231722520ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x34647225202c3434ull,0x61090a3b38202c33ull,
0x09203436752e6464ull,0x25202c3534647225ull,0x7225202c32346472ull,0x6f6d090a3b343464ull,
0x2509203233732e76ull,0x7225202c38323172ull,0x7473090a3b333031ull,0x2e6c61626f6c672eull,
0x09203233752e3276ull,0x302b35346472255bull,0x303172257b202c5dull,0x7d38323172252c31ull,
0x5f375f744c240a3bull,0x200a3a3031323033ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c313334ull,0x656c6562616c2064ull,
0x5f375f744c242064ull,0x2e090a3831343832ull,0x3409383109636f6cull,0x6162090a30093938ull,
0x0920636e79732e72ull,0x2e646e61090a3b30ull,0x3172250920323362ull,0x30317225202c3932ull,
0x3b36387225202c34ull,0x33752e766f6d090aull,0x3033317225092032ull,0x6573090a3b30202cull,
0x33732e71652e7074ull,0x2c30337025092032ull,0x202c393231722520ull,0x090a3b3033317225ull,
0x7262203033702540ull,0x375f744c24092061ull,0x0a3b32323730335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31333420ull,
0x6c6562616c206461ull,0x375f744c24206465ull,0x090a38313438325full,0x09383109636f6c2eull,
0x6c090a3009323934ull,0x2e6d617261702e64ull,0x3172250920323373ull,0x635f5f5b202c3133ull,
0x5f6d726170616475ull,0x6964615235325a5full,0x7366664f64644178ull,0x6853646e41737465ull,
0x323150656c666675ull,0x65756c615679654bull,0x6a5f305372696150ull,0x74666968735f696aull,
0x2e726873090a3b5dull,0x3172250920323375ull,0x30317225202c3830ull,0x3133317225202c31ull,
0x622e646e61090a3bull,0x3031722509203233ull,0x3830317225202c39ull,0x090a3b353532202cull,
0x752e6f6c2e6c756dull,0x3131722509203233ull,0x3930317225202c30ull,0x6461090a3b34202cull,
0x2509203233752e64ull,0x7225202c32333172ull,0x31317225202c3934ull,0x2e747663090a3b30ull,
0x203233752e343675ull,0x202c363464722509ull,0x090a3b3233317225ull,0x752e6f6c2e6c756dull,
0x3464722509203436ull,0x3634647225202c37ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c39326472ull,0x34647225202c3164ull,0x732e646c090a3b37ull,0x33752e6465726168ull,
0x3333317225092032ull,0x39326472255b202cull,0x6461090a3b5d302bull,0x2509203233752e64ull,
0x7225202c34333172ull,0x0a3b31202c333331ull,0x726168732e747309ull,0x09203233752e6465ull,
0x302b39326472255bull,0x3433317225202c5dull,0x09636f6c2e090a3bull,0x3009333934093831ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5b202c3834647225ull,0x6170616475635f5full,
0x5235325a5f5f6d72ull,0x4f64644178696461ull,0x6e41737465736666ull,0x656c666675685364ull,
0x615679654b323150ull,0x537269615065756cull,0x44705f696a6a5f30ull,0x7663090a3b5d7473ull,
0x33752e3436752e74ull,0x3934647225092032ull,0x3b3333317225202cull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x647225202c303564ull,0x090a3b38202c3934ull,0x203436752e646461ull,
0x202c313564722509ull,0x25202c3834647225ull,0x6d090a3b30356472ull,0x09203233732e766full,
0x25202c3533317225ull,0x73090a3b33303172ull,0x6c61626f6c672e74ull,0x203233752e32762eull,
0x2b31356472255b09ull,0x3172257b202c5d30ull,0x35333172252c3130ull,0x375f744c240a3b7dull,
0x0a3a32323730335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c31333420ull,0x6c6562616c206461ull,0x375f744c24206465ull,
0x090a38313438325full,0x09383109636f6c2eull,0x62090a3009353934ull,0x20636e79732e7261ull,
0x646e61090a3b3009ull,0x722509203233622eull,0x317225202c363331ull,0x37387225202c3430ull,
0x752e766f6d090a3bull,0x3331722509203233ull,0x73090a3b30202c37ull,0x732e71652e707465ull,
0x3133702509203233ull,0x2c3633317225202cull,0x0a3b373331722520ull,0x6220313370254009ull,
0x5f744c2409206172ull,0x3b34333231335f37ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3133342065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a38313438325f37ull,0x383109636f6c2e09ull,0x090a300938393409ull,
0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c383331ull,0x6d72617061647563ull,
0x64615235325a5f5full,0x66664f6464417869ull,0x53646e4173746573ull,0x3150656c66667568ull,
0x756c615679654b32ull,0x5f30537269615065ull,0x666968735f696a6aull,0x726873090a3b5d74ull,
0x722509203233752eull,0x317225202c383031ull,0x33317225202c3130ull,0x2e646e61090a3b38ull,
0x3172250920323362ull,0x30317225202c3930ull,0x0a3b353532202c38ull,0x2e6f6c2e6c756d09ull,
0x3172250920323375ull,0x30317225202c3031ull,0x61090a3b34202c39ull,0x09203233752e6464ull,
0x25202c3933317225ull,0x317225202c393472ull,0x747663090a3b3031ull,0x3233752e3436752eull,
0x2c32356472250920ull,0x0a3b393331722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x35647225202c3335ull,0x61090a3b34202c32ull,0x09203436752e6464ull,0x25202c3932647225ull,
0x647225202c316472ull,0x2e646c090a3b3335ull,0x752e646572616873ull,0x3431722509203233ull,
0x326472255b202c30ull,0x61090a3b5d302b39ull,0x09203233752e6464ull,0x25202c3134317225ull,
0x3b31202c30343172ull,0x6168732e7473090aull,0x203233752e646572ull,0x2b39326472255b09ull,
0x34317225202c5d30ull,0x636f6c2e090a3b31ull,0x0939393409383109ull,0x61702e646c090a30ull,
0x203436752e6d6172ull,0x202c343564722509ull,0x70616475635f5f5bull,0x35325a5f5f6d7261ull,
0x6464417869646152ull,0x417374657366664full,0x6c6666756853646eull,0x5679654b32315065ull,
0x7269615065756c61ull,0x705f696a6a5f3053ull,0x63090a3b5d747344ull,0x752e3436752e7476ull,
0x3564722509203233ull,0x3034317225202c35ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,
0x7225202c36356472ull,0x0a3b38202c353564ull,0x3436752e64646109ull,0x2c37356472250920ull,
0x202c343564722520ull,0x090a3b3635647225ull,0x203233732e766f6dull,0x202c323431722509ull,
0x090a3b3330317225ull,0x61626f6c672e7473ull,0x3233752e32762e6cull,0x37356472255b0920ull,
0x72257b202c5d302bull,0x343172252c313031ull,0x5f744c240a3b7d32ull,0x3a34333231335f37ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3133342065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a38313438325f37ull,
0x383109636f6c2e09ull,0x090a300931303509ull,0x636e79732e726162ull,0x6e61090a3b300920ull,
0x2509203233622e64ull,0x7225202c33343172ull,0x387225202c343031ull,0x2e766f6d090a3b38ull,
0x3172250920323375ull,0x090a3b30202c3434ull,0x2e71652e70746573ull,0x3370250920323373ull,
0x3334317225202c32ull,0x3b3434317225202cull,0x203233702540090aull,0x744c240920617262ull,
0x36343731335f375full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c31333420656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38313438325f375full,0x3109636f6c2e090aull,0x0a30093430350938ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x5f5b202c35343172ull,0x726170616475635full,0x615235325a5f5f6dull,
0x664f646441786964ull,0x646e417374657366ull,0x50656c6666756853ull,0x6c615679654b3231ull,
0x3053726961506575ull,0x6968735f696a6a5full,0x6873090a3b5d7466ull,0x2509203233752e72ull,
0x7225202c38303172ull,0x317225202c313031ull,0x646e61090a3b3534ull,0x722509203233622eull,
0x317225202c393031ull,0x3b353532202c3830ull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x317225202c303131ull,0x090a3b34202c3930ull,0x203233752e646461ull,0x202c363431722509ull,
0x7225202c39347225ull,0x7663090a3b303131ull,0x33752e3436752e74ull,0x3835647225092032ull,
0x3b3634317225202cull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c393564ull,
0x090a3b34202c3835ull,0x203436752e646461ull,0x202c393264722509ull,0x7225202c31647225ull,
0x646c090a3b393564ull,0x2e6465726168732eull,0x3172250920323375ull,0x6472255b202c3734ull,
0x090a3b5d302b3932ull,0x203233752e646461ull,0x202c383431722509ull,0x31202c3734317225ull,
0x68732e7473090a3bull,0x3233752e64657261ull,0x39326472255b0920ull,0x317225202c5d302bull,
0x6f6c2e090a3b3834ull,0x3530350938310963ull,0x702e646c090a3009ull,0x3436752e6d617261ull,
0x2c30366472250920ull,0x616475635f5f5b20ull,0x325a5f5f6d726170ull,0x6441786964615235ull,
0x7374657366664f64ull,0x6666756853646e41ull,0x79654b323150656cull,0x69615065756c6156ull,
0x5f696a6a5f305372ull,0x090a3b5d74734470ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x34317225202c3136ull,0x2e6c756d090a3b37ull,0x09203436752e6f6cull,0x25202c3236647225ull,
0x3b38202c31366472ull,0x36752e646461090aull,0x3336647225092034ull,0x2c3036647225202cull,
0x0a3b323664722520ull,0x3233732e766f6d09ull,0x2c39343172250920ull,0x0a3b333031722520ull,
0x626f6c672e747309ull,0x33752e32762e6c61ull,0x366472255b092032ull,0x257b202c5d302b33ull,
0x3172252c31303172ull,0x744c240a3b7d3934ull,0x36343731335f375full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c31333420656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38313438325f375full,0x3109636f6c2e090aull,
0x0a30093730350938ull,0x6e79732e72616209ull,0x61090a3b30092063ull,0x09203233622e646eull,
0x25202c3035317225ull,0x7225202c34303172ull,0x766f6d090a3b3938ull,0x722509203233752eull,
0x0a3b30202c313531ull,0x71652e7074657309ull,0x702509203233732eull,0x35317225202c3333ull,
0x3135317225202c30ull,0x3333702540090a3bull,0x4c24092061726220ull,0x353232335f375f74ull,
0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c31333420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x313438325f375f74ull,
0x09636f6c2e090a38ull,0x3009303135093831ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5b202c3235317225ull,0x6170616475635f5full,0x5235325a5f5f6d72ull,0x4f64644178696461ull,
0x6e41737465736666ull,0x656c666675685364ull,0x615679654b323150ull,0x537269615065756cull,
0x68735f696a6a5f30ull,0x73090a3b5d746669ull,0x09203233752e7268ull,0x25202c3830317225ull,
0x7225202c31303172ull,0x6e61090a3b323531ull,0x2509203233622e64ull,0x7225202c39303172ull,
0x353532202c383031ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c30313172ull,
0x0a3b34202c393031ull,0x3233752e64646109ull,0x2c33353172250920ull,0x25202c3934722520ull,
0x63090a3b30313172ull,0x752e3436752e7476ull,0x3664722509203233ull,0x3335317225202c34ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c35366472ull,0x0a3b34202c343664ull,
0x3436752e64646109ull,0x2c39326472250920ull,0x25202c3164722520ull,0x6c090a3b35366472ull,
0x6465726168732e64ull,0x722509203233752eull,0x72255b202c343531ull,0x0a3b5d302b393264ull,
0x3233752e64646109ull,0x2c35353172250920ull,0x202c343531722520ull,0x732e7473090a3b31ull,
0x33752e6465726168ull,0x326472255b092032ull,0x7225202c5d302b39ull,0x6c2e090a3b353531ull,
0x313509383109636full,0x2e646c090a300931ull,0x36752e6d61726170ull,0x3636647225092034ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4178696461523532ull,0x74657366664f6464ull,
0x66756853646e4173ull,0x654b323150656c66ull,0x615065756c615679ull,0x696a6a5f30537269ull,
0x0a3b5d747344705full,0x3436752e74766309ull,0x722509203233752eull,0x317225202c373664ull,
0x6c756d090a3b3435ull,0x203436752e6f6c2eull,0x202c383664722509ull,0x38202c3736647225ull,
0x752e646461090a3bull,0x3664722509203436ull,0x3636647225202c39ull,0x3b3836647225202cull,
0x33732e766f6d090aull,0x3635317225092032ull,0x3b3330317225202cull,0x6f6c672e7473090aull,
0x752e32762e6c6162ull,0x6472255b09203233ull,0x7b202c5d302b3936ull,0x72252c3130317225ull,
0x4c240a3b7d363531ull,0x353232335f375f74ull,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c31333420656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x313438325f375f74ull,0x09636f6c2e090a38ull,0x3009333135093831ull,
0x79732e726162090aull,0x090a3b300920636eull,0x203233622e646e61ull,0x202c373531722509ull,
0x25202c3430317225ull,0x6f6d090a3b303972ull,0x2509203233752e76ull,0x3b30202c38353172ull,
0x652e70746573090aull,0x2509203233732e71ull,0x317225202c343370ull,0x35317225202c3735ull,
0x33702540090a3b38ull,0x2409206172622034ull,0x3732335f375f744cull,0x3c2f2f200a3b3037ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x31333420656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3438325f375f744cull,0x636f6c2e090a3831ull,
0x0936313509383109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,0x202c393531722509ull,
0x70616475635f5f5bull,0x35325a5f5f6d7261ull,0x6464417869646152ull,0x417374657366664full,
0x6c6666756853646eull,0x5679654b32315065ull,0x7269615065756c61ull,0x735f696a6a5f3053ull,
0x090a3b5d74666968ull,0x203233752e726873ull,0x202c383031722509ull,0x25202c3130317225ull,
0x61090a3b39353172ull,0x09203233622e646eull,0x25202c3930317225ull,0x3532202c38303172ull,
0x2e6c756d090a3b35ull,0x09203233752e6f6cull,0x25202c3031317225ull,0x3b34202c39303172ull,
0x33752e646461090aull,0x3036317225092032ull,0x202c39347225202cull,0x090a3b3031317225ull,
0x2e3436752e747663ull,0x6472250920323375ull,0x36317225202c3037ull,0x2e6c756d090a3b30ull,
0x09203436752e6f6cull,0x25202c3137647225ull,0x3b34202c30376472ull,0x36752e646461090aull,
0x3932647225092034ull,0x202c31647225202cull,0x090a3b3137647225ull,0x65726168732e646cull,
0x2509203233752e64ull,0x255b202c31363172ull,0x3b5d302b39326472ull,0x33752e646461090aull,
0x3236317225092032ull,0x2c3136317225202cull,0x2e7473090a3b3120ull,0x752e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3932ull,0x2e090a3b32363172ull,0x3509383109636f6cull,
0x646c090a30093731ull,0x752e6d617261702eull,0x3764722509203436ull,0x75635f5f5b202c32ull,
0x5f5f6d7261706164ull,0x786964615235325aull,0x657366664f646441ull,0x756853646e417374ull,
0x4b323150656c6666ull,0x5065756c61567965ull,0x6a6a5f3053726961ull,0x3b5d747344705f69ull,
0x36752e747663090aull,0x2509203233752e34ull,0x7225202c33376472ull,0x756d090a3b313631ull,
0x3436752e6f6c2e6cull,0x2c34376472250920ull,0x202c333764722520ull,0x2e646461090a3b38ull,
0x6472250920343675ull,0x37647225202c3537ull,0x3437647225202c32ull,0x732e766f6d090a3bull,
0x3631722509203233ull,0x3330317225202c33ull,0x6c672e7473090a3bull,0x2e32762e6c61626full,
0x72255b0920323375ull,0x202c5d302b353764ull,0x252c31303172257bull,0x240a3b7d33363172ull,
0x3732335f375f744cull,0x3c2f2f200a3a3037ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x31333420656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3438325f375f744cull,0x636f6c2e090a3831ull,0x0939313509383109ull,0x732e726162090a30ull,
0x0a3b300920636e79ull,0x3233622e646e6109ull,0x2c34363172250920ull,0x202c343031722520ull,
0x6d090a3b31397225ull,0x09203233752e766full,0x30202c3536317225ull,0x2e70746573090a3bull,
0x09203233732e7165ull,0x7225202c35337025ull,0x317225202c343631ull,0x702540090a3b3536ull,
0x0920617262203533ull,0x33335f375f744c24ull,0x2f2f200a3b323832ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x333420656e696c20ull,0x2064616568202c31ull,
0x2064656c6562616cull,0x38325f375f744c24ull,0x6f6c2e090a383134ull,0x3232350938310963ull,
0x702e646c090a3009ull,0x3233732e6d617261ull,0x2c36363172250920ull,0x616475635f5f5b20ull,
0x325a5f5f6d726170ull,0x6441786964615235ull,0x7374657366664f64ull,0x6666756853646e41ull,
0x79654b323150656cull,0x69615065756c6156ull,0x5f696a6a5f305372ull,0x0a3b5d7466696873ull,
0x3233752e72687309ull,0x2c38303172250920ull,0x202c313031722520ull,0x090a3b3636317225ull,
0x203233622e646e61ull,0x202c393031722509ull,0x32202c3830317225ull,0x6c756d090a3b3535ull,
0x203233752e6f6c2eull,0x202c303131722509ull,0x34202c3930317225ull,0x752e646461090a3bull,
0x3631722509203233ull,0x2c39347225202c37ull,0x0a3b303131722520ull,0x3436752e74766309ull,
0x722509203233752eull,0x317225202c363764ull,0x6c756d090a3b3736ull,0x203436752e6f6c2eull,
0x202c373764722509ull,0x34202c3637647225ull,0x752e646461090a3bull,0x3264722509203436ull,
0x2c31647225202c39ull,0x0a3b373764722520ull,0x726168732e646c09ull,0x09203233752e6465ull,
0x5b202c3836317225ull,0x5d302b3932647225ull,0x752e646461090a3bull,0x3631722509203233ull,
0x3836317225202c39ull,0x7473090a3b31202cull,0x2e6465726168732eull,0x72255b0920323375ull,
0x202c5d302b393264ull,0x090a3b3936317225ull,0x09383109636f6c2eull,0x6c090a3009333235ull,
0x2e6d617261702e64ull,0x6472250920343675ull,0x635f5f5b202c3837ull,0x5f6d726170616475ull,
0x6964615235325a5full,0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,
0x65756c615679654bull,0x6a5f305372696150ull,0x5d747344705f696aull,0x752e747663090a3bull,
0x09203233752e3436ull,0x25202c3937647225ull,0x6d090a3b38363172ull,0x36752e6f6c2e6c75ull,
0x3038647225092034ull,0x2c3937647225202cull,0x646461090a3b3820ull,0x722509203436752eull,
0x647225202c313864ull,0x38647225202c3837ull,0x2e766f6d090a3b30ull,0x3172250920323373ull,
0x30317225202c3037ull,0x672e7473090a3b33ull,0x32762e6c61626f6cull,0x255b09203233752eull,
0x2c5d302b31386472ull,0x2c31303172257b20ull,0x0a3b7d3037317225ull,0x33335f375f744c24ull,
0x2f2f200a3a323832ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333420656e696c20ull,0x2064616568202c31ull,0x2064656c6562616cull,0x38325f375f744c24ull,
0x6f6c2e090a383134ull,0x3532350938310963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x33622e646e61090aull,0x3137317225092032ull,0x2c3430317225202cull,0x090a3b3239722520ull,
0x203233752e766f6dull,0x202c323731722509ull,0x70746573090a3b30ull,0x203233732e71652eull,
0x25202c3633702509ull,0x7225202c31373172ull,0x2540090a3b323731ull,0x2061726220363370ull,
0x335f375f744c2409ull,0x2f200a3b34393733ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3420656e696c2079ull,0x64616568202c3133ull,0x64656c6562616c20ull,
0x325f375f744c2420ull,0x6c2e090a38313438ull,0x323509383109636full,0x2e646c090a300938ull,
0x33732e6d61726170ull,0x3337317225092032ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x4178696461523532ull,0x74657366664f6464ull,0x66756853646e4173ull,0x654b323150656c66ull,
0x615065756c615679ull,0x696a6a5f30537269ull,0x3b5d74666968735full,0x33752e726873090aull,
0x3830317225092032ull,0x2c3130317225202cull,0x0a3b333731722520ull,0x3233622e646e6109ull,
0x2c39303172250920ull,0x202c383031722520ull,0x756d090a3b353532ull,0x3233752e6f6c2e6cull,
0x2c30313172250920ull,0x202c393031722520ull,0x2e646461090a3b34ull,0x3172250920323375ull,
0x39347225202c3437ull,0x3b3031317225202cull,0x36752e747663090aull,0x2509203233752e34ull,
0x7225202c32386472ull,0x756d090a3b343731ull,0x3436752e6f6c2e6cull,0x2c33386472250920ull,
0x202c323864722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3932ull,
0x3b3338647225202cull,0x6168732e646c090aull,0x203233752e646572ull,0x202c353731722509ull,
0x302b39326472255bull,0x2e646461090a3b5dull,0x3172250920323375ull,0x37317225202c3637ull,
0x73090a3b31202c35ull,0x6465726168732e74ull,0x255b09203233752eull,0x2c5d302b39326472ull,
0x0a3b363731722520ull,0x383109636f6c2e09ull,0x090a300939323509ull,0x6d617261702e646cull,
0x722509203436752eull,0x5f5f5b202c343864ull,0x6d72617061647563ull,0x64615235325a5f5full,
0x66664f6464417869ull,0x53646e4173746573ull,0x3150656c66667568ull,0x756c615679654b32ull,
0x5f30537269615065ull,0x747344705f696a6aull,0x2e747663090a3b5dull,0x203233752e343675ull,
0x202c353864722509ull,0x090a3b3537317225ull,0x752e6f6c2e6c756dull,0x3864722509203436ull,
0x3538647225202c36ull,0x6461090a3b38202cull,0x2509203436752e64ull,0x7225202c37386472ull,
0x647225202c343864ull,0x766f6d090a3b3638ull,0x722509203233732eull,0x317225202c373731ull,
0x2e7473090a3b3330ull,0x762e6c61626f6c67ull,0x5b09203233752e32ull,0x5d302b3738647225ull,
0x31303172257b202cull,0x3b7d37373172252cull,0x335f375f744c240aull,0x2f200a3a34393733ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3420656e696c2079ull,
0x64616568202c3133ull,0x64656c6562616c20ull,0x325f375f744c2420ull,0x6c2e090a38313438ull,
0x333509383109636full,0x726162090a300931ull,0x300920636e79732eull,0x622e646e61090a3bull,
0x3731722509203233ull,0x3430317225202c38ull,0x0a3b33397225202cull,0x3233752e766f6d09ull,
0x2c39373172250920ull,0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c373370250920ull,
0x25202c3837317225ull,0x40090a3b39373172ull,0x6172622037337025ull,0x5f375f744c240920ull,
0x200a3b3630333433ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c313334ull,0x656c6562616c2064ull,0x5f375f744c242064ull,
0x2e090a3831343832ull,0x3509383109636f6cull,0x646c090a30093433ull,0x732e6d617261702eull,
0x3831722509203233ull,0x75635f5f5b202c30ull,0x5f5f6d7261706164ull,0x786964615235325aull,
0x657366664f646441ull,0x756853646e417374ull,0x4b323150656c6666ull,0x5065756c61567965ull,
0x6a6a5f3053726961ull,0x5d74666968735f69ull,0x752e726873090a3bull,0x3031722509203233ull,
0x3130317225202c38ull,0x3b3038317225202cull,0x33622e646e61090aull,0x3930317225092032ull,
0x2c3830317225202cull,0x6d090a3b35353220ull,0x33752e6f6c2e6c75ull,0x3031317225092032ull,
0x2c3930317225202cull,0x646461090a3b3420ull,0x722509203233752eull,0x347225202c313831ull,
0x3031317225202c39ull,0x752e747663090a3bull,0x09203233752e3436ull,0x25202c3838647225ull,
0x6d090a3b31383172ull,0x36752e6f6c2e6c75ull,0x3938647225092034ull,0x2c3838647225202cull,
0x646461090a3b3420ull,0x722509203436752eull,0x647225202c393264ull,0x3938647225202c31ull,
0x68732e646c090a3bull,0x3233752e64657261ull,0x2c32383172250920ull,0x2b39326472255b20ull,
0x646461090a3b5d30ull,0x722509203233752eull,0x317225202c333831ull,0x090a3b31202c3238ull,
0x65726168732e7473ull,0x5b09203233752e64ull,0x5d302b3932647225ull,0x3b3338317225202cull,
0x3109636f6c2e090aull,0x0a30093533350938ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5b202c30396472ull,0x726170616475635full,0x615235325a5f5f6dull,0x664f646441786964ull,
0x646e417374657366ull,0x50656c6666756853ull,0x6c615679654b3231ull,0x3053726961506575ull,
0x7344705f696a6a5full,0x747663090a3b5d74ull,0x3233752e3436752eull,0x2c31396472250920ull,
0x0a3b323831722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x39647225202c3239ull,
0x61090a3b38202c31ull,0x09203436752e6464ull,0x25202c3339647225ull,0x7225202c30396472ull,
0x6f6d090a3b323964ull,0x2509203233732e76ull,0x7225202c34383172ull,0x7473090a3b333031ull,
0x2e6c61626f6c672eull,0x09203233752e3276ull,0x302b33396472255bull,0x303172257b202c5dull,
0x7d34383172252c31ull,0x5f375f744c240a3bull,0x200a3a3630333433ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c313334ull,
0x656c6562616c2064ull,0x5f375f744c242064ull,0x2e090a3831343832ull,0x3509383109636f6cull,
0x6162090a30093733ull,0x0920636e79732e72ull,0x2e646e61090a3b30ull,0x3172250920323362ull,
0x30317225202c3538ull,0x3b34397225202c34ull,0x33752e766f6d090aull,0x3638317225092032ull,
0x6573090a3b30202cull,0x33732e71652e7074ull,0x2c38337025092032ull,0x202c353831722520ull,
0x090a3b3638317225ull,0x7262203833702540ull,0x375f744c24092061ull,0x0a3b38313834335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c31333420ull,0x6c6562616c206461ull,0x375f744c24206465ull,0x090a38313438325full,
0x09383109636f6c2eull,0x6c090a3009303435ull,0x2e6d617261702e64ull,0x3172250920323373ull,
0x635f5f5b202c3738ull,0x5f6d726170616475ull,0x6964615235325a5full,0x7366664f64644178ull,
0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,0x6a5f305372696150ull,
0x74666968735f696aull,0x2e726873090a3b5dull,0x3172250920323375ull,0x30317225202c3830ull,
0x3738317225202c31ull,0x622e646e61090a3bull,0x3031722509203233ull,0x3830317225202c39ull,
0x090a3b353532202cull,0x752e6f6c2e6c756dull,0x3131722509203233ull,0x3930317225202c30ull,
0x6461090a3b34202cull,0x2509203233752e64ull,0x7225202c38383172ull,0x31317225202c3934ull,
0x2e747663090a3b30ull,0x203233752e343675ull,0x202c343964722509ull,0x090a3b3838317225ull,
0x752e6f6c2e6c756dull,0x3964722509203436ull,0x3439647225202c35ull,0x6461090a3b34202cull,
0x2509203436752e64ull,0x7225202c39326472ull,0x39647225202c3164ull,0x732e646c090a3b35ull,
0x33752e6465726168ull,0x3938317225092032ull,0x39326472255b202cull,0x6461090a3b5d302bull,
0x2509203233752e64ull,0x7225202c30393172ull,0x0a3b31202c393831ull,0x726168732e747309ull,
0x09203233752e6465ull,0x302b39326472255bull,0x3039317225202c5dull,0x09636f6c2e090a3bull,
0x3009313435093831ull,0x7261702e646c090aull,0x09203436752e6d61ull,0x5b202c3639647225ull,
0x6170616475635f5full,0x5235325a5f5f6d72ull,0x4f64644178696461ull,0x6e41737465736666ull,
0x656c666675685364ull,0x615679654b323150ull,0x537269615065756cull,0x44705f696a6a5f30ull,
0x7663090a3b5d7473ull,0x33752e3436752e74ull,0x3739647225092032ull,0x3b3938317225202cull,
0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c383964ull,0x090a3b38202c3739ull,
0x203436752e646461ull,0x202c393964722509ull,0x25202c3639647225ull,0x6d090a3b38396472ull,
0x09203233732e766full,0x25202c3139317225ull,0x73090a3b33303172ull,0x6c61626f6c672e74ull,
0x203233752e32762eull,0x2b39396472255b09ull,0x3172257b202c5d30ull,0x31393172252c3130ull,
0x375f744c240a3b7dull,0x0a3a38313834335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c31333420ull,0x6c6562616c206461ull,
0x375f744c24206465ull,0x090a38313438325full,0x09383109636f6c2eull,0x62090a3009333435ull,
0x20636e79732e7261ull,0x646e61090a3b3009ull,0x722509203233622eull,0x317225202c323931ull,
0x35397225202c3430ull,0x752e766f6d090a3bull,0x3931722509203233ull,0x73090a3b30202c33ull,
0x732e71652e707465ull,0x3933702509203233ull,0x2c3239317225202cull,0x0a3b333931722520ull,
0x6220393370254009ull,0x5f744c2409206172ull,0x3b30333335335f37ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3133342065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a38313438325f37ull,0x383109636f6c2e09ull,
0x090a300936343509ull,0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c343931ull,
0x6d72617061647563ull,0x64615235325a5f5full,0x66664f6464417869ull,0x53646e4173746573ull,
0x3150656c66667568ull,0x756c615679654b32ull,0x5f30537269615065ull,0x666968735f696a6aull,
0x726873090a3b5d74ull,0x722509203233752eull,0x317225202c383031ull,0x39317225202c3130ull,
0x2e646e61090a3b34ull,0x3172250920323362ull,0x30317225202c3930ull,0x0a3b353532202c38ull,
0x2e6f6c2e6c756d09ull,0x3172250920323375ull,0x30317225202c3031ull,0x61090a3b34202c39ull,
0x09203233752e6464ull,0x25202c3539317225ull,0x317225202c393472ull,0x747663090a3b3031ull,
0x3233752e3436752eull,0x3030316472250920ull,0x3b3539317225202cull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x7225202c31303164ull,0x3b34202c30303164ull,0x36752e646461090aull,
0x3932647225092034ull,0x202c31647225202cull,0x0a3b313031647225ull,0x726168732e646c09ull,
0x09203233752e6465ull,0x5b202c3639317225ull,0x5d302b3932647225ull,0x752e646461090a3bull,
0x3931722509203233ull,0x3639317225202c37ull,0x7473090a3b31202cull,0x2e6465726168732eull,
0x72255b0920323375ull,0x202c5d302b393264ull,0x090a3b3739317225ull,0x09383109636f6c2eull,
0x6c090a3009373435ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x5f5f5b202c323031ull,
0x6d72617061647563ull,0x64615235325a5f5full,0x66664f6464417869ull,0x53646e4173746573ull,
0x3150656c66667568ull,0x756c615679654b32ull,0x5f30537269615065ull,0x747344705f696a6aull,
0x2e747663090a3b5dull,0x203233752e343675ull,0x2c33303164722509ull,0x0a3b363931722520ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x647225202c343031ull,0x0a3b38202c333031ull,
0x3436752e64646109ull,0x3530316472250920ull,0x323031647225202cull,0x343031647225202cull,
0x732e766f6d090a3bull,0x3931722509203233ull,0x3330317225202c38ull,0x6c672e7473090a3bull,
0x2e32762e6c61626full,0x72255b0920323375ull,0x2c5d302b35303164ull,0x2c31303172257b20ull,
0x0a3b7d3839317225ull,0x35335f375f744c24ull,0x2f2f200a3a303333ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x333420656e696c20ull,0x2064616568202c31ull,
0x2064656c6562616cull,0x38325f375f744c24ull,0x6f6c2e090a383134ull,0x3934350938310963ull,
0x2e726162090a3009ull,0x3b300920636e7973ull,0x33622e646e61090aull,0x3939317225092032ull,
0x2c3430317225202cull,0x090a3b3639722520ull,0x203233752e766f6dull,0x202c303032722509ull,
0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3034702509ull,0x7225202c39393172ull,
0x2540090a3b303032ull,0x2061726220303470ull,0x335f375f744c2409ull,0x2f200a3b32343835ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3420656e696c2079ull,
0x64616568202c3133ull,0x64656c6562616c20ull,0x325f375f744c2420ull,0x6c2e090a38313438ull,
0x353509383109636full,0x2e646c090a300932ull,0x33732e6d61726170ull,0x3130327225092032ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4178696461523532ull,0x74657366664f6464ull,
0x66756853646e4173ull,0x654b323150656c66ull,0x615065756c615679ull,0x696a6a5f30537269ull,
0x3b5d74666968735full,0x33752e726873090aull,0x3830317225092032ull,0x2c3130317225202cull,
0x0a3b313032722520ull,0x3233622e646e6109ull,0x2c39303172250920ull,0x202c383031722520ull,
0x756d090a3b353532ull,0x3233752e6f6c2e6cull,0x2c30313172250920ull,0x202c393031722520ull,
0x2e646461090a3b34ull,0x3272250920323375ull,0x39347225202c3230ull,0x3b3031317225202cull,
0x36752e747663090aull,0x2509203233752e34ull,0x25202c3630316472ull,0x6d090a3b32303272ull,
0x36752e6f6c2e6c75ull,0x3031647225092034ull,0x3031647225202c37ull,0x61090a3b34202c36ull,
0x09203436752e6464ull,0x25202c3932647225ull,0x647225202c316472ull,0x646c090a3b373031ull,
0x2e6465726168732eull,0x3272250920323375ull,0x6472255b202c3330ull,0x090a3b5d302b3932ull,
0x203233752e646461ull,0x202c343032722509ull,0x31202c3330327225ull,0x68732e7473090a3bull,
0x3233752e64657261ull,0x39326472255b0920ull,0x327225202c5d302bull,0x6f6c2e090a3b3430ull,
0x3335350938310963ull,0x702e646c090a3009ull,0x3436752e6d617261ull,0x3830316472250920ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4178696461523532ull,0x74657366664f6464ull,
0x66756853646e4173ull,0x654b323150656c66ull,0x615065756c615679ull,0x696a6a5f30537269ull,
0x0a3b5d747344705full,0x3436752e74766309ull,0x722509203233752eull,0x7225202c39303164ull,
0x756d090a3b333032ull,0x3436752e6f6c2e6cull,0x3031316472250920ull,0x393031647225202cull,
0x6461090a3b38202cull,0x2509203436752e64ull,0x25202c3131316472ull,0x25202c3830316472ull,
0x090a3b3031316472ull,0x203233732e766f6dull,0x202c353032722509ull,0x090a3b3330317225ull,
0x61626f6c672e7473ull,0x3233752e32762e6cull,0x31316472255b0920ull,0x257b202c5d302b31ull,
0x3272252c31303172ull,0x744c240a3b7d3530ull,0x32343835335f375full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c31333420656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38313438325f375full,0x3109636f6c2e090aull,
0x0a30093535350938ull,0x6e79732e72616209ull,0x61090a3b30092063ull,0x09203233622e646eull,
0x25202c3630327225ull,0x7225202c34303172ull,0x766f6d090a3b3739ull,0x722509203233752eull,
0x0a3b30202c373032ull,0x71652e7074657309ull,0x702509203233732eull,0x30327225202c3134ull,
0x3730327225202c36ull,0x3134702540090a3bull,0x4c24092061726220ull,0x353336335f375f74ull,
0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c31333420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x313438325f375f74ull,
0x09636f6c2e090a38ull,0x3009383535093831ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5b202c3830327225ull,0x6170616475635f5full,0x5235325a5f5f6d72ull,0x4f64644178696461ull,
0x6e41737465736666ull,0x656c666675685364ull,0x615679654b323150ull,0x537269615065756cull,
0x68735f696a6a5f30ull,0x73090a3b5d746669ull,0x09203233752e7268ull,0x25202c3830317225ull,
0x7225202c31303172ull,0x6e61090a3b383032ull,0x2509203233622e64ull,0x7225202c39303172ull,
0x353532202c383031ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c30313172ull,
0x0a3b34202c393031ull,0x3233752e64646109ull,0x2c39303272250920ull,0x25202c3934722520ull,
0x63090a3b30313172ull,0x752e3436752e7476ull,0x3164722509203233ull,0x30327225202c3231ull,
0x2e6c756d090a3b39ull,0x09203436752e6f6cull,0x202c333131647225ull,0x202c323131647225ull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x31647225202c3932ull,0x333131647225202cull,
0x68732e646c090a3bull,0x3233752e64657261ull,0x2c30313272250920ull,0x2b39326472255b20ull,
0x646461090a3b5d30ull,0x722509203233752eull,0x327225202c313132ull,0x090a3b31202c3031ull,
0x65726168732e7473ull,0x5b09203233752e64ull,0x5d302b3932647225ull,0x3b3131327225202cull,
0x3109636f6c2e090aull,0x0a30093935350938ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5b202c3431316472ull,0x6170616475635f5full,0x5235325a5f5f6d72ull,0x4f64644178696461ull,
0x6e41737465736666ull,0x656c666675685364ull,0x615679654b323150ull,0x537269615065756cull,
0x44705f696a6a5f30ull,0x7663090a3b5d7473ull,0x33752e3436752e74ull,0x3131647225092032ull,
0x3031327225202c35ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x25202c3631316472ull,
0x38202c3531316472ull,0x752e646461090a3bull,0x3164722509203436ull,0x31647225202c3731ull,
0x31647225202c3431ull,0x766f6d090a3b3631ull,0x722509203233732eull,0x317225202c323132ull,
0x2e7473090a3b3330ull,0x762e6c61626f6c67ull,0x5b09203233752e32ull,0x302b373131647225ull,
0x303172257b202c5dull,0x7d32313272252c31ull,0x5f375f744c240a3bull,0x200a3a3435333633ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c313334ull,0x656c6562616c2064ull,0x5f375f744c242064ull,0x2e090a3831343832ull,
0x3509383109636f6cull,0x6162090a30093136ull,0x0920636e79732e72ull,0x2e646e61090a3b30ull,
0x3272250920323362ull,0x30317225202c3331ull,0x3b38397225202c34ull,0x33752e766f6d090aull,
0x3431327225092032ull,0x6573090a3b30202cull,0x33732e71652e7074ull,0x2c32347025092032ull,
0x202c333132722520ull,0x090a3b3431327225ull,0x7262203234702540ull,0x375f744c24092061ull,
0x0a3b36363836335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c31333420ull,0x6c6562616c206461ull,0x375f744c24206465ull,
0x090a38313438325full,0x09383109636f6c2eull,0x6c090a3009343635ull,0x2e6d617261702e64ull,
0x3272250920323373ull,0x635f5f5b202c3531ull,0x5f6d726170616475ull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x74666968735f696aull,0x2e726873090a3b5dull,0x3172250920323375ull,
0x30317225202c3830ull,0x3531327225202c31ull,0x622e646e61090a3bull,0x3031722509203233ull,
0x3830317225202c39ull,0x090a3b353532202cull,0x752e6f6c2e6c756dull,0x3131722509203233ull,
0x3930317225202c30ull,0x6461090a3b34202cull,0x2509203233752e64ull,0x7225202c36313272ull,
0x31317225202c3934ull,0x2e747663090a3b30ull,0x203233752e343675ull,0x2c38313164722509ull,
0x0a3b363132722520ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x647225202c393131ull,
0x0a3b34202c383131ull,0x3436752e64646109ull,0x2c39326472250920ull,0x25202c3164722520ull,
0x090a3b3931316472ull,0x65726168732e646cull,0x2509203233752e64ull,0x255b202c37313272ull,
0x3b5d302b39326472ull,0x33752e646461090aull,0x3831327225092032ull,0x2c3731327225202cull,
0x2e7473090a3b3120ull,0x752e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3932ull,
0x2e090a3b38313272ull,0x3509383109636f6cull,0x646c090a30093536ull,0x752e6d617261702eull,
0x3164722509203436ull,0x635f5f5b202c3032ull,0x5f6d726170616475ull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x5d747344705f696aull,0x752e747663090a3bull,0x09203233752e3436ull,
0x202c313231647225ull,0x090a3b3731327225ull,0x752e6f6c2e6c756dull,0x3164722509203436ull,
0x31647225202c3232ull,0x090a3b38202c3132ull,0x203436752e646461ull,0x2c33323164722509ull,
0x2c30323164722520ull,0x3b32323164722520ull,0x33732e766f6d090aull,0x3931327225092032ull,
0x3b3330317225202cull,0x6f6c672e7473090aull,0x752e32762e6c6162ull,0x6472255b09203233ull,
0x202c5d302b333231ull,0x252c31303172257bull,0x240a3b7d39313272ull,0x3836335f375f744cull,
0x3c2f2f200a3a3636ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x31333420656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3438325f375f744cull,
0x636f6c2e090a3831ull,0x0937363509383109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x3233732e64646109ull,0x202c383572250920ull,0x3631202c38357225ull,0x2e70746573090a3bull,
0x09203233752e746cull,0x7225202c33347025ull,0x39357225202c3835ull,0x3334702540090a3bull,
0x4c24092061726220ull,0x313438325f375f74ull,0x375f744c240a3b38ull,0x0a3a36303937325full,
0x383109636f6c2e09ull,0x090a300933373509ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,
0x4178696461523532ull,0x74657366664f6464ull,0x66756853646e4173ull,0x654b323150656c66ull,
0x615065756c615679ull,0x696a6a5f30537269ull,0x202f2f207d090a3aull,0x6964615235325a5full,
0x7366664f64644178ull,0x6853646e41737465ull,0x323150656c666675ull,0x65756c615679654bull,
0x6a5f305372696150ull,0x000000000a0a696aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"5c5350df0a2f4458",(char*)"particleSystem.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xaebfefb4};
# 5 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.stub.c" 2
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 112 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1
# 113 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 139 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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

extern void __cudaRegisterSurface(
        void **fatCubinHandle,
  const struct surfaceReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
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
# 274 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 68 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/usr/local/cuda/bin/../include/common_functions.h" 2

static __attribute__((__unused__)) clock_t __cuda_clock(void)
{
  return clock();
}

static __attribute__((__unused__)) void *__cuda_memset(void *s, int c, size_t n)
{
  return memset(s, c, n);
}

static __attribute__((__unused__)) void *__cuda_memcpy(void *d, const void *s, size_t n)
{
  return memcpy(d, s, n);
}
# 93 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 912 "/usr/local/cuda/bin/../include/math_functions.h" 3
int __cuda_error_not_implememted(void);
# 972 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda_abs(int a)
{
  return abs(a);
}

static __attribute__((__unused__)) float __cuda_fabsf(float a)
{
  return fabsf(a);
}

static __attribute__((__unused__)) long long int __cuda_llabs(long long int a)
{

  return ::llabs(a);



}

static __attribute__((__unused__)) float __cuda_exp2f(float a)
{
  return exp2f(a);
}

# 1 "/usr/local/cuda/bin/../include/device_functions.h" 1 3
# 442 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 443 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 2384 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/common_types.h" 1 3
# 37 "/usr/local/cuda/bin/../include/common_types.h" 3
union __cudart_FloatUintCvt {
    float f;
    unsigned int i;
};

union __cudart_FloatIntCvt {
    float f;
    int i;
};

union __cudart_DoubleUlonglongCvt {
    double d;
    unsigned long long int i;
};

union __cudart_DoubleLonglongCvt {
    double d;
    long long int i;
};

union __cudart_DoubleInthiloCvt {
    double d;
    signed int i[2];
};

struct __cudart_UintUint {
    unsigned int lo;
    unsigned int hi;
};
# 2385 "/usr/local/cuda/bin/../include/device_functions.h" 2 3

static const unsigned char __internal_rcpTab[128] =
{
  0xff, 0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf4, 0xf2,
  0xf0, 0xee, 0xed, 0xeb, 0xe9, 0xe8, 0xe6, 0xe4,
  0xe3, 0xe1, 0xe0, 0xde, 0xdd, 0xdb, 0xda, 0xd8,
  0xd7, 0xd5, 0xd4, 0xd3, 0xd1, 0xd0, 0xcf, 0xcd,
  0xcc, 0xcb, 0xca, 0xc8, 0xc7, 0xc6, 0xc5, 0xc4,
  0xc2, 0xc1, 0xc0, 0xbf, 0xbe, 0xbd, 0xbc, 0xbb,
  0xba, 0xb9, 0xb8, 0xb7, 0xb6, 0xb5, 0xb4, 0xb3,
  0xb2, 0xb1, 0xb0, 0xaf, 0xae, 0xad, 0xac, 0xab,
  0xaa, 0xa9, 0xa8, 0xa8, 0xa7, 0xa6, 0xa5, 0xa4,
  0xa3, 0xa3, 0xa2, 0xa1, 0xa0, 0x9f, 0x9f, 0x9e,
  0x9d, 0x9c, 0x9c, 0x9b, 0x9a, 0x99, 0x99, 0x98,
  0x97, 0x97, 0x96, 0x95, 0x95, 0x94, 0x93, 0x93,
  0x92, 0x91, 0x91, 0x90, 0x8f, 0x8f, 0x8e, 0x8e,
  0x8d, 0x8c, 0x8c, 0x8b, 0x8b, 0x8a, 0x89, 0x89,
  0x88, 0x88, 0x87, 0x87, 0x86, 0x85, 0x85, 0x84,
  0x84, 0x83, 0x83, 0x82, 0x82, 0x81, 0x81, 0x80
};

static const unsigned int __internal_invSqrtCubeTab[96] =
{
  0xfa0bf8fe, 0xee6b28fa, 0xe5f024f7, 0xdaf268f3,
  0xd2f000f0, 0xc890c0ec, 0xc10378e9, 0xb9a758e6,
  0xb4da40e4, 0xadcea0e1, 0xa6f278de, 0xa279c0dc,
  0x9beb48d9, 0x97a5c4d7, 0x916340d4, 0x8d4fc8d2,
  0x895000d0, 0x8563b8ce, 0x818ac0cc, 0x7dc4e8ca,
  0x7a1200c8, 0x7671d8c6, 0x72e440c4, 0x6f6908c2,
  0x6db240c1, 0x6a523cbf, 0x670424bd, 0x6563c0bc,
  0x623028ba, 0x609ce8b9, 0x5d8364b7, 0x5bfd18b6,
  0x58fd40b4, 0x5783a8b3, 0x560e48b2, 0x533000b0,
  0x51c70caf, 0x506238ae, 0x4da4c0ac, 0x4c4c10ab,
  0x4af768aa, 0x49a6b8a9, 0x485a00a8, 0x471134a7,
  0x45cc58a6, 0x434e40a4, 0x4214f8a3, 0x40df88a2,
  0x3fade0a1, 0x3e8000a0, 0x3d55dc9f, 0x3c2f789e,
  0x3c2f789e, 0x3b0cc49d, 0x39edc09c, 0x38d2609b,
  0x37baa89a, 0x36a68899, 0x35960098, 0x34890497,
  0x34890497, 0x337f9896, 0x3279ac95, 0x31774094,
  0x30784893, 0x30784893, 0x2f7cc892, 0x2e84b091,
  0x2d900090, 0x2d900090, 0x2c9eac8f, 0x2bb0b88e,
  0x2bb0b88e, 0x2ac6148d, 0x29dec08c, 0x29dec08c,
  0x28fab08b, 0x2819e88a, 0x2819e88a, 0x273c5889,
  0x273c5889, 0x26620088, 0x258ad487, 0x258ad487,
  0x24b6d886, 0x24b6d886, 0x23e5fc85, 0x23184084,
  0x23184084, 0x224d9883, 0x224d9883, 0x21860882,
  0x21860882, 0x20c18081, 0x20c18081, 0x20000080
};

static __attribute__((__unused__)) float __internal_frcp_kernel (float x,enum cudaRoundMode mode)
{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int sign;
  unsigned f, y;

  arg.f = x;
  sign = arg.i & 0x80000000;
  expo = (arg.i >> 23);
  expo = expo & 0xff;
  f = expo - 1;

  if (f <= 0xFD) {
    y = (arg.i << 8);
    y = y | 0x80000000;

    arg.i = __internal_rcpTab[(y >> 24) - 128];

    f = arg.i * arg.i;
    f = f << 16;
    prod = ((unsigned long long)y) * f;
    arg.i = (arg.i << 24) - (unsigned)(prod >> 32);

    f = arg.i + arg.i;
    prod = ((unsigned long long)y) * f;
    f = (unsigned)(-(int)(prod >> 32));
    prod = ((unsigned long long)arg.i) * f;
    y = y >> 8;

    expo = (2 * 127) - expo - 2;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 6;
    } else {
      arg.i = (arg.i + 32) >> 6;
    }
    if ((int)expo >= 0) {
      f = y * arg.i;
      arg.i = ((expo << 23) + arg.i) | sign;
    } else {

      expo = -(int)expo;
      arg.i = arg.i >> expo;
      f = y * arg.i;
      arg.i = arg.i | sign;
    }
    if (mode == cudaRoundNearest) {
      expo = f + y;
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)expo < 0) expo = (unsigned)(-(int)expo);
      if (expo < f) arg.i++;
    } else if (mode == cudaRoundZero) {
      if ((int)f > 0) arg.i = arg.i - 1;
    } else if (mode == cudaRoundPosInf) {
      if (((int)f > 0) && sign) arg.i = arg.i - 1;
      if (((int)f < 0) && !sign) arg.i = arg.i + 1;
    } else {
      if (((int)f > 0) && !sign) arg.i = arg.i - 1;
      if (((int)f < 0) && sign) arg.i = arg.i + 1;
    }
    return arg.f;
  } else {

    if (!(arg.i << 1)) {
      arg.i = 0x7F800000 | arg.i;
      return arg.f;
    }

    if ((arg.i << 1) == 0xff000000) {
      arg.i &= 0x80000000;
      return arg.f;
    }

    if ((arg.i << 1) > 0xff000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    f = 0;
    arg.i <<= 8;
    do {
      f++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i |= sign;
    arg.f = __internal_frcp_kernel (arg.f, mode);
    expo = ((arg.i << 1) >> 24);
    if ((expo + f) < 255) {
      arg.i = (arg.i + (f << 23));
      return arg.f;
    }
    if (mode == cudaRoundNearest) {
      arg.i = (arg.i & 0x80000000) | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      arg.i = (arg.i & 0x80000000) | 0x7f7fffff;
    } else if (mode == cudaRoundPosInf) {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f7fffff : 0x7f800000);
    } else {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f800000 : 0x7f7fffff);
    }
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fsqrt_kernel (float radicand, enum cudaRoundMode mode)

{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int s, f, x;

  arg.f = radicand;
  expo = arg.i >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((arg.i <= 0x80000000) && (f <= 0xFD)) {

    x = (arg.i << 8) | 0x80000000;
    x = x >> (expo & 1);

    arg.i = f = __internal_invSqrtCubeTab[((unsigned)x >> 25) - 32];

    prod = ((unsigned long long)x) * f;
    arg.i = ((arg.i * 3) << 22) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)arg.i) * arg.i;
    s = (unsigned)(prod >> 32);
    prod = ((unsigned long long)x) * s;
    f = 0x30000000 - (unsigned)(prod >> 32);
    prod = ((unsigned long long)f) * arg.i;
    arg.i = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * arg.i;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 3;
    } else {
      arg.i = (arg.i + 4) >> 3;
    }
    x = (x << 16) - (arg.i * arg.i);

    if (mode == cudaRoundNearest) {
      f = x - (2 * arg.i + 1);
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)x < 0) x = (unsigned)(-(int)x);
      if (f < x) arg.i ++;
    } else if ((mode == cudaRoundZero) || (mode == cudaRoundMinInf)) {
      if ((int)x < 0) arg.i--;
    } else if (mode == cudaRoundPosInf) {
      if ((int)x > 0) arg.i++;
    }
    arg.i = arg.i + (((expo + 125) & ~0x1) << 22);
    return arg.f;
  } else {

    if (!(arg.i << 1) || (arg.i == 0x7F800000)) {
      return arg.f;
    }

    if ((arg.i << 1) > 0xFF000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    if (arg.i & 0x80000000) {
      arg.i = 0xFFC00000;
      return arg.f;
    }

    x = 0;
    arg.i <<= 8;
    do {
      x++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i += (x & 1) << 23;
    x += (x & 1);
    arg.f = __internal_fsqrt_kernel (arg.f, mode);
    arg.i -= ((x >> 1) << 23);
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fdiv_kernel (float dividend, float divisor, enum cudaRoundMode mode)

{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  volatile union __cudart_FloatUintCvt cvtx, cvty, res;

  cvtx.f = dividend;
  cvty.f = divisor;
  expox = ((cvtx.i >> 23) & 0xff) - 1;
  expoy = ((cvty.i >> 23) & 0xff) - 1;
  sign = ((cvtx.i ^ cvty.i) & 0x80000000);

  if ((expox <= 0xFD) && (expoy <= 0xFD)) {
divide:
    expox = expox - expoy + 127 - 1;
    expoy = expox;

    y = (cvty.i << 8) | 0x80000000;
    x = (cvtx.i & 0x00ffffff) | 0x00800000;

    r = __internal_rcpTab[(y >> 24) - 128];

    f = r * r;
    prod = ((unsigned long long)y) * (f << 16);
    r = (r << 24) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)y) * (r << 1);
    f = (unsigned)-(int)(prod >> 32);
    prod = ((unsigned long long)f) * (r << 1);
    r = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expox--;
      prod = prod + prod;
    }
    if (mode == cudaRoundNearest) {

      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem0, rem1, inc;

        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        rem0 = rem1 - y;
        inc = abs(rem0) < abs(rem1);

        res.i = sign | ((expox << 23) + r + inc);
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f800000;
        return res.f;
      } else {

        int shift = -(int)expox;
        if (shift > 23) {

          r = (shift < 25) && ((x != y) || (r > 0x00ff0000));
          res.i = sign | r;
          return res.f;
        }
        if (x == y) {

          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          remhi = remlo - y;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if ((remhi < remlo) || ((remhi == remlo) && (r & 1))) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundZero) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if (rem1 < 0) r--;
        r = (expox << 23) + r;
        if (r == 0x7f800000) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f7fffff;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift < 31)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = 0;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) & (r != 0)) r--;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundPosInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (sign)) r--;
        if ((rem1 > 0) && (!sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f7fffff : 0x7f800000;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (sign)) r--;
          if ((remlo > 0) && (!sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundMinInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (!sign)) r--;
        if ((rem1 > 0) && (sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (!sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f800000 : 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (!sign)) r--;
          if ((remlo > 0) && (sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    }
  }
  {
    int xzero, yzero, xinf, yinf, xnan, ynan;

    xnan = (cvtx.i << 1) > 0xff000000;
    ynan = (cvty.i << 1) > 0xff000000;

    if (xnan) {
      res.i = cvtx.i | 0x00400000;
      return res.f;
    }
    if (ynan) {
      res.i = cvty.i | 0x00400000;
      return res.f;
    }
    xzero = (cvtx.i << 1) == 0x00000000;
    yzero = (cvty.i << 1) == 0x00000000;
    xinf = (cvtx.i << 1) == 0xff000000;
    yinf = (cvty.i << 1) == 0xff000000;

    if ((xzero & yzero) | (xinf & yinf)) {
      res.i = 0xffc00000;
      return res.f;
    }

    if (xzero | yinf) {
      res.i = sign;
      return res.f;
    }

    if (yzero | xinf) {
      res.i = sign | 0x7f800000;
      return res.f;
    }

    if ((int)expox < 0) {
      cvtx.i = cvtx.i << 9;
      while ((int)cvtx.i >= 0) {
        expox--;
        cvtx.i = cvtx.i + cvtx.i;
      }
      cvtx.i = cvtx.i >> 8;
    }
    if ((int)expoy < 0) {
      cvty.i = cvty.i << 9;
      while ((int)cvty.i >= 0) {
        expoy--;
        cvty.i = cvty.i + cvty.i;
      }
      cvty.i = cvty.i >> 8;
    }
    goto divide;
  }
}

static __attribute__((__unused__)) float __internal_fmul_kernel (float a, float b, enum cudaRoundMode mode)

{
  unsigned long long product;
  volatile union __cudart_FloatUintCvt xx, yy;
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

      if (mode == cudaRoundNearest) {
        if (yy.i < 0x80000000) return xx.f;
        xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (yy.i && !expo_y);
      } else if (mode == cudaRoundMinInf) {
        xx.i += (yy.i && expo_y);
      }
      return xx.f;
    } else if ((int)expo_x >= 254) {

      if (mode == cudaRoundNearest) {
         xx.i = expo_y | 0x7F800000;
      } else if (mode == cudaRoundZero) {
         xx.i = expo_y | 0x7F7FFFFF;
      } else if (mode == cudaRoundPosInf) {
         xx.i = (expo_y ? 0xff7fffff : 0x7F800000);
      } else {
         xx.i = (expo_y ? 0xFF800000 : 0x7f7fffff);
      }
      return xx.f;
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      if (mode == cudaRoundNearest) {
        if (expo_x > 25) {

          xx.i = expo_y;
          return xx.f;
        } else {
          yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
          xx.i = expo_y + (xx.i >> expo_x);
          xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
          return xx.f;
        }
      } else if (mode == cudaRoundZero) {
        if (expo_x > 25) expo_x = 25;
        xx.i = expo_y + (xx.i >> expo_x);
        return xx.f;
      } else if (mode == cudaRoundPosInf) {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && !expo_y);
        return xx.f;
      } else {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && expo_y);
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

static __attribute__((__unused__)) float __internal_fmaf_kernel (float a, float b, float c, enum cudaRoundMode mode)

{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;
  volatile union __cudart_FloatUintCvt cvt;

  cvt.f = a;
  xx = cvt.i;
  cvt.f = b;
  yy = cvt.i;
  cvt.f = c;
  zz = cvt.i;

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
      return b + b;
    }
    if ((zz << 1) > 0xff000000) {
      return c + c;
    }
    if ((xx << 1) > 0xff000000) {
      return a + a;
    }
# 3164 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      cvt.i = 0xffc00000;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          cvt.i = 0xffc00000;
          return cvt.f;
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      cvt.i = xx;
      return cvt.f;
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      cvt.i = yy;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      cvt.i = zz;
      return cvt.f;
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          cvt.i = zz;
          return cvt.f;
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      if (mode == cudaRoundMinInf) {
        zz = 0x80000000 & (xx ^ yy ^ zz);
      } else {
        zz &= 0x7fffffff;
      }
      cvt.i = zz;
      return cvt.f;
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      cvt.i = zz;
      return cvt.f;
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
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

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

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

        if (mode == cudaRoundMinInf) {
          xx = 0x80000000;
        }
        cvt.i = xx;
        return cvt.f;
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
    if (mode == cudaRoundNearest) {
      s = xx & 1;
      xx += (temp == 0x80000000) ? s : (temp >> 31);
    } else if (mode == cudaRoundPosInf) {
      xx += temp && !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += temp && expo_y;
    }
    xx = xx + (expo_x << 23);
    cvt.i = xx;
    return cvt.f;
  } else if ((int)expo_x >= 126) {

    if (mode == cudaRoundNearest) {
      xx = expo_y | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      xx = expo_y | 0x7F7FFFFF;
    } else if (mode == cudaRoundPosInf) {
      xx = expo_y ? 0xFF7FFFFF : 0x7f800000;
    } else if (mode == cudaRoundMinInf) {
      xx = expo_y ? 0xff800000 : 0x7f7fffff;
    }
    cvt.i = xx;
    return cvt.f;
  }

  expo_x = (unsigned int)(-(int)expo_x);
  if (expo_x > 25) {

    xx = 0;
    if (mode == cudaRoundPosInf) {
      xx += !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += !!expo_y;
    }
    cvt.i = expo_y | xx;
    return cvt.f;
  }
  temp = (xx << (32 - expo_x)) | ((temp) ? 1 : 0);
  xx = xx >> expo_x;
  if (mode == cudaRoundNearest) {
    xx = xx + ((temp == 0x80000000) ? (xx & 1) : (temp >> 31));
  } else if (mode == cudaRoundPosInf) {
    xx = xx + (!expo_y && temp);
  } else if (mode == cudaRoundMinInf) {
    xx = xx + (expo_y && temp);
  }
  xx = expo_y + xx;
  cvt.i = xx;
  return cvt.f;
}

static __attribute__((__unused__)) float __internal_fadd_kernel (float a, float b, enum cudaRoundMode mode)

{
  volatile union __cudart_FloatUintCvt xx, yy;
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
      temp = (unsigned)(-((int)temp));
      xx.i = xx.i - (yy.i >> expo_y) - (temp ? 1 : 0);
      if (xx.i & 0x00800000) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {
        if ((temp | (xx.i << 1)) == 0) {

          if (mode == cudaRoundMinInf) {
            xx.i = 0x80000000;
          } else {
            xx.i = 0;
          }
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
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {

        temp = (xx.i << 31) | (temp >> 1);
        xx.i = ((xx.i & 0x80000000) | (xx.i >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i + (expo_x << 23);
      if (mode == cudaRoundNearest) {
        if (temp < 0x80000000) return xx.f;
        xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (temp && !(xx.i & 0x80000000));
      } else if (mode == cudaRoundMinInf) {
        xx.i += (temp && (xx.i & 0x80000000));
      }
      return xx.f;
    }
    if ((int)expo_x >= 254) {

      temp = xx.i & 0x80000000;
      if (mode == cudaRoundNearest) {
        xx.i = (temp) | 0x7f800000;
      } else if (mode == cudaRoundZero) {
        xx.i = (temp) | 0x7f7fffff;
      } else if (mode == cudaRoundMinInf) {
        xx.i = (temp ? 0xFF800000 : 0x7f7fffff);
      } else if (mode == cudaRoundPosInf) {
        xx.i = (temp ? 0xff7fffff : 0x7F800000);
      }
      return xx.f;
    }

    expo_y = expo_x + 32;
    yy.i = xx.i & 0x80000000;
    xx.i = xx.i & ~0xff000000;
    expo_x = (unsigned)(-((int)expo_x));
    temp = xx.i << expo_y | ((temp) ? 1 : 0);
    xx.i = yy.i | (xx.i >> expo_x);
    if (mode == cudaRoundNearest) {
      xx.i += (temp == 0x80000000) ? (xx.i & 1) : (temp >> 31);
    } else if (mode == cudaRoundZero) {
    } else if (mode == cudaRoundPosInf) {
      xx.i += (temp && !yy.i);
    } else if (mode == cudaRoundMinInf) {
      xx.i += (temp && yy.i);
    }
    return xx.f;
  } else {

    if (!(yy.i << 1)) {
      if (mode == cudaRoundMinInf) {
        if (!(xx.i << 1)) {
          xx.i = xx.i | yy.i;
        }
      } else {
        if (xx.i == 0x80000000) {
          xx.i = yy.i;
        }
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

static __attribute__((__unused__)) float __frcp_rn (float a)
{
  return __internal_frcp_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __frcp_rz (float a)
{
  return __internal_frcp_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __frcp_rd (float a)
{
  return __internal_frcp_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __frcp_ru (float a)
{
  return __internal_frcp_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fsqrt_rn (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fsqrt_rz (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __fsqrt_rd (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fsqrt_ru (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fdiv_rn (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fdiv_rz (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fdiv_rd (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fdiv_ru (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fadd_rd (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fadd_ru (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmul_rd (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fmul_ru (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rn (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmaf_rz (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmaf_ru (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rd (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __cuda___isnan(double a);
static __attribute__((__unused__)) int __cuda___isnanf(float a);
static __attribute__((__unused__)) int __double2int_rz(double);
static __attribute__((__unused__)) unsigned int __double2uint_rz(double);
static __attribute__((__unused__)) long long int __double2ll_rz(double);
static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double);
# 3771 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) int __mulhi(int a, int b)
{
  long long int c = (long long int)a * (long long int)b;

  return (int)(c >> 32);
}

static __attribute__((__unused__)) unsigned int __umulhi(unsigned int a, unsigned int b)
{
  unsigned long long int c = (unsigned long long int)a * (unsigned long long int)b;

  return (unsigned int)(c >> 32);
}

static __attribute__((__unused__)) unsigned long long int __umul64hi(unsigned long long int a, unsigned long long int b)
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

static __attribute__((__unused__)) long long int __mul64hi(long long int a, long long int b)
{
  long long int res;
  res = __umul64hi(a, b);
  if (a < 0LL) res = res - b;
  if (b < 0LL) res = res - a;
  return res;
}

static __attribute__((__unused__)) float __saturatef(float a)
{
  if (__cuda___isnanf(a)) return 0.0f;
  return a >= 1.0f ? 1.0f : a <= 0.0f ? 0.0f : a;
}

static __attribute__((__unused__)) unsigned int __sad(int a, int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) unsigned int __usad(unsigned int a, unsigned int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) int __mul24(int a, int b)
{

  a &= 0xffffff;
  a = (a & 0x800000) != 0 ? a | ~0xffffff : a;
  b &= 0xffffff;
  b = (b & 0x800000) != 0 ? b | ~0xffffff : b;


  return a * b;
}

static __attribute__((__unused__)) unsigned int __umul24(unsigned int a, unsigned int b)
{

  a &= 0xffffff;
  b &= 0xffffff;


  return a * b;
}

static __attribute__((__unused__)) float __int_as_float(int a)
{
  volatile union __cudart_FloatIntCvt u;

  u.i = a;
  return u.f;
}

static __attribute__((__unused__)) int __float_as_int(float a)
{
  volatile union __cudart_FloatIntCvt u;

  u.f = a;
  return u.i;
}

static __attribute__((__unused__)) long long int __internal_float2ll_kernel(float a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
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

static __attribute__((__unused__)) int __internal_float2int(float a, enum cudaRoundMode rndMode)
{
  return (int)__internal_float2ll_kernel(a, 2147483647LL, -2147483648LL, 0LL, rndMode);
}

static __attribute__((__unused__)) int __float2int_rz(float a)
{



  return __internal_float2int(a, cudaRoundZero);

}

static __attribute__((__unused__)) int __float2int_ru(float a)
{
  return __internal_float2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __float2int_rd(float a)
{
  return __internal_float2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __float2int_rn(float a)
{
  return __internal_float2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __internal_float2ll(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __float2ll_rz(float a)
{



  return __internal_float2ll(a, cudaRoundZero);

}

static __attribute__((__unused__)) long long int __float2ll_ru(float a)
{
  return __internal_float2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __float2ll_rd(float a)
{
  return __internal_float2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __float2ll_rn(float a)
{
  return __internal_float2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull_kernel(float a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
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

static __attribute__((__unused__)) unsigned int __internal_float2uint(float a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_float2ull_kernel(a, 4294967295U, 0U, rndMode);
}

static __attribute__((__unused__)) unsigned int __float2uint_rz(float a)
{



  return __internal_float2uint(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned int __float2uint_ru(float a)
{
  return __internal_float2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rd(float a)
{
  return __internal_float2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rn(float a)
{
  return __internal_float2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rz(float a)
{



  return __internal_float2ull(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned long long int __float2ull_ru(float a)
{
  return __internal_float2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rd(float a)
{
  return __internal_float2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rn(float a)
{
  return __internal_float2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __internal_normalize64(unsigned long long int *a)
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

static __attribute__((__unused__)) int __internal_normalize(unsigned int *a)
{
  unsigned long long int t = (unsigned long long int)*a;
  int lz = __internal_normalize64(&t);

  *a = (unsigned int)(t >> 32);

  return lz - 32;
}

static __attribute__((__unused__)) float __internal_int2float_kernel(int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
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

static __attribute__((__unused__)) float __int2float_rz(int a)
{
  return __internal_int2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __int2float_ru(int a)
{
  return __internal_int2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __int2float_rd(int a)
{
  return __internal_int2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __int2float_rn(int a)
{



  return __internal_int2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __internal_uint2float_kernel(unsigned int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (rndMode == cudaRoundNearest) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.f;
}

static __attribute__((__unused__)) float __uint2float_rz(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __uint2float_ru(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __uint2float_rd(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __uint2float_rn(unsigned int a)
{



  return __internal_uint2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __ll2float_rn(long long int a)
{
  return (float)a;
}

static __attribute__((__unused__)) float __internal_ull2float_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
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
  if (rndMode == cudaRoundNearest) {
    res += (t == 0x80000000) ? (res & 1) : (t >> 31);
  } else if (rndMode == cudaRoundPosInf) {
    res += (t != 0);
  }
  return __int_as_float(res);
}

static __attribute__((__unused__)) float __ull2float_rn(unsigned long long int a)
{



  return __internal_ull2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) unsigned short __float2half_rn(float f)
{
  unsigned int x = __float_as_int (f);
  unsigned int u = (x & 0x7fffffff), remainder, shift, lsb, lsb_s1, lsb_m1;
  unsigned int sign, exponent, mantissa;


  if (u > 0x7f800000) {
    return 0x7fff;
  }

  sign = ((x >> 16) & 0x8000);


  if (u > 0x477fefff) {
    return sign | 0x7c00;
  }
  if (u < 0x33000001) {
    return sign | 0x0000;
  }

  exponent = ((u >> 23) & 0xff);
  mantissa = (u & 0x7fffff);

  if (exponent > 0x70) {
    shift = 13;
    exponent -= 0x70;
  } else {
    shift = 0x7e - exponent;
    exponent = 0;
    mantissa |= 0x800000;
  }
  lsb = (1 << shift);
  lsb_s1 = (lsb >> 1);
  lsb_m1 = (lsb - 1);


  remainder = (mantissa & lsb_m1);
  mantissa >>= shift;
  if (remainder > lsb_s1 || (remainder == lsb_s1 && (mantissa & 0x1))) {
    ++mantissa;
    if (!(mantissa & 0x3ff)) {
      ++exponent;
      mantissa = 0;
    }
  }

  return sign | (exponent << 10) | mantissa;
}

static __attribute__((__unused__)) float __half2float(unsigned short h)
{
  unsigned int sign = ((h >> 15) & 1);
  unsigned int exponent = ((h >> 10) & 0x1f);
  unsigned int mantissa = ((h & 0x3ff) << 13);

  if (exponent == 0x1f) {
    mantissa = (mantissa
                ? (sign = 0, 0x7fffff)
                : 0);
    exponent = 0xff;
  } else if (!exponent) {
    if (mantissa) {
      unsigned int msb;
      exponent = 0x71;
      do {
        msb = (mantissa & 0x400000);
        mantissa <<= 1;
        --exponent;
      } while (!msb);
      mantissa &= 0x7fffff;
    }
  } else {
    exponent += 0x70;
  }

  return __int_as_float ((sign << 31) | (exponent << 23) | mantissa);
}

static __attribute__((__unused__)) float __fadd_rz(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmul_rz(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fadd_rn(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmul_rn(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) void __brkpt(int c)
{

}
# 4318 "/usr/local/cuda/bin/../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static __attribute__((__unused__)) inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4337 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) void __prof_trigger(int a)
{
}

static __attribute__((__unused__)) void __threadfence(void)
{
  __syncthreads();
}

static __attribute__((__unused__)) void __threadfence_block(void)
{
  __syncthreads();
}



static __attribute__((__unused__)) void __trap(void)
{
  __builtin_trap();
}
# 4375 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) float __fdividef(float a, float b)
{



  volatile float aa = a;
  volatile float bb = b;

  if (__cuda_fabsf(bb) > 8.507059173e37f) {
    if (__cuda_fabsf(aa) <= 3.402823466e38f) {
      return ((aa / bb) / 3.402823466e38f) / 3.402823466e38f;
    } else {
      bb = 1.0f / bb;
      bb = bb / 3.402823466e38f;
      return aa * bb;
    }
  } else {
    return aa / bb;
  }

}


static __attribute__((__unused__)) float __sinf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return sinf(a);
}

static __attribute__((__unused__)) float __cosf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return cosf(a);
}

static __attribute__((__unused__)) float __log2f(float a)
{
  return log2f(a);
}







static __attribute__((__unused__)) float __internal_accurate_fdividef(float a, float b)
{
  return a / b;
}

static __attribute__((__unused__)) float __tanf(float a)
{



  return __fdividef (__sinf(a), __cosf(a));

}

static __attribute__((__unused__)) void __sincosf(float a, float *sptr, float *cptr)
{



  *sptr = __sinf(a);
  *cptr = __cosf(a);

}

static __attribute__((__unused__)) float __expf(float a)
{



  return __cuda_exp2f(a * 1.442695041f);

}

static __attribute__((__unused__)) float __exp10f(float a)
{



  return __cuda_exp2f(a * 3.321928094f);

}

static __attribute__((__unused__)) float __log10f(float a)
{



  return 0.301029996f * __log2f(a);

}

static __attribute__((__unused__)) float __logf(float a)
{



  return 0.693147181f * __log2f(a);

}

static __attribute__((__unused__)) float __powf(float a, float b)
{



  return __cuda_exp2f(b * __log2f(a));

}

static __attribute__((__unused__)) float fdividef(float a, float b)
{





  return __internal_accurate_fdividef(a, b);

}

static __attribute__((__unused__)) int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static __attribute__((__unused__)) int __clzll(long long int a)
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

static __attribute__((__unused__)) int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static __attribute__((__unused__)) int __popcll(unsigned long long int a)
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

static __attribute__((__unused__)) unsigned int __brev(unsigned int a)
{
  a = ((a >> 1) & 0x55555555) + ((a & 0x55555555) << 1);
  a = ((a >> 2) & 0x33333333) + ((a & 0x33333333) << 2);
  a = ((a >> 4) & 0x0F0F0F0F) + ((a & 0x0F0F0F0F) << 4);
  a = ((a >> 8) & 0x00FF00FF) + ((a & 0x00FF00FF) << 8);
  a = ( a >> 16 ) + ( a << 16);
  return a;
}

static __attribute__((__unused__)) unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}

static __attribute__((__unused__)) int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static __attribute__((__unused__)) int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}
# 4623 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) double fdivide(double a, double b)
{
  return a / b;
}



static __attribute__((__unused__)) int __internal_double2int(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) long long int __internal_double2ll(double a, enum cudaRoundMode rndMode);
static __attribute__((__unused__)) unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode);

static __attribute__((__unused__)) int __double2int_rz(double a)
{
  return __internal_double2int(a, cudaRoundZero);
}

static __attribute__((__unused__)) unsigned int __double2uint_rz(double a)
{
  return __internal_double2uint(a, cudaRoundZero);
}

static __attribute__((__unused__)) long long int __double2ll_rz(double a)
{
  return __internal_double2ll(a, cudaRoundZero);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double a)
{
  return __internal_double2ull(a, cudaRoundZero);
}
# 4667 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 257 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static __attribute__((__unused__)) int __iAtomicAdd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAdd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicExch(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicExch(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) float __fAtomicExch(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMin(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMin(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMax(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMax(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicInc(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = (old >= val) ? 0 : old + 1; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicDec(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = ((old == 0) | (old > val)) ? val : (old - 1); __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicAnd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAnd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicOr(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicOr(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicXor(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicXor(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicCAS(int *address, int compare, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}
# 4668 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 118 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static __attribute__((__unused__)) unsigned long long int __ullAtomicAdd(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicExch(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicCAS(unsigned long long int *address, unsigned long long int compare, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);



  return old;
}





static __attribute__((__unused__)) int __any(int cond)
{
  return cond;
}

static __attribute__((__unused__)) int __all(int cond)
{
  return cond;
}
# 4669 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 267 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
static __attribute__((__unused__)) double __longlong_as_double(long long int a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.i = a;
  return u.d;
}

static __attribute__((__unused__)) long long int __double_as_longlong(double a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.d = a;
  return u.i;
}

static __attribute__((__unused__)) float __internal_double2float_kernel(double a)
{
  volatile union __cudart_DoubleUlonglongCvt xx;
  volatile union __cudart_FloatUintCvt res;

  int shift;
  xx.d = a;
  if (xx.i == 0) return 0.0f;
  res.i = (((unsigned int) (xx.i >> 32)) & 0x80000000);
  if ((xx.i & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
    if ((xx.i & 0x7fffffffffffffffULL) > 0x7ff0000000000000ULL) {

      res.i = ((unsigned int)((xx.i >> 32) & 0x80000000) |
               (255U << 23) | 0x00400000 |
               (unsigned int)((xx.i >> (53 - 24)) & 0x007fffff));
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
      xx.i >>= -126 - shift;
    }
  } else {
    res.i |= (unsigned int) (127 + shift) << 23;
  }
  res.i |= ((unsigned int) (xx.i >> 29)) & 0x007fffff;
  xx.i &= 0x1fffffff;
  return res.f;
}

static __attribute__((__unused__)) double __internal_ll2double_kernel(long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
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

static __attribute__((__unused__)) double __internal_ull2double_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
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

static __attribute__((__unused__)) long long int __internal_double2ll_kernel(double a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
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

static __attribute__((__unused__)) unsigned long long int __internal_double2ull_kernel(double a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
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

static __attribute__((__unused__)) int __double2hiint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[1];
}

static __attribute__((__unused__)) int __double2loint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[0];
}

static __attribute__((__unused__)) double __hiloint2double(int a, int b)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.i[0] = b;
  cvt.i[1] = a;
  return cvt.d;
}

static __attribute__((__unused__)) float __double2float_rn(double a)
{
  return (float)a;
}

static __attribute__((__unused__)) float __double2float_rz(double a)
{
  return __internal_double2float_kernel(a);
}

static __attribute__((__unused__)) int __internal_double2int(double a, enum cudaRoundMode rndMode)
{
  return (int)__internal_double2ll_kernel(a, 2147483647LL, -2147483648LL, -2147483648LL, rndMode);
}

static __attribute__((__unused__)) int __double2int_rn(double a)
{
  return __internal_double2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __double2int_ru(double a)
{
  return __internal_double2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __double2int_rd(double a)
{
  return __internal_double2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_double2ull_kernel(a, 4294967295ULL, 2147483648ULL, rndMode);
}

static __attribute__((__unused__)) unsigned int __double2uint_rn(double a)
{
  return __internal_double2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned int __double2uint_ru(double a)
{
  return __internal_double2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __double2uint_rd(double a)
{
  return __internal_double2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __internal_double2ll(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __double2ll_rn(double a)
{
  return __internal_double2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __double2ll_ru(double a)
{
  return __internal_double2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __double2ll_rd(double a)
{
  return __internal_double2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rn(double a)
{
  return __internal_double2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_ru(double a)
{
  return __internal_double2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rd(double a)
{
  return __internal_double2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __int2double_rn(int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __uint2double_rn(unsigned int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rn(long long int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rz(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ll2double_rd(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ll2double_ru(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __ull2double_rn(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundNearest);
}

static __attribute__((__unused__)) double __ull2double_rz(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ull2double_rd(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ull2double_ru(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundPosInf);
}







static __attribute__((__unused__)) double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
{



  struct __cudart_UintUint xx, yy, zz, ww;
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
# 660 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
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

static __attribute__((__unused__)) double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static __attribute__((__unused__)) double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static __attribute__((__unused__)) double __dadd_rz(double a, double b)
{
  return __fma_rz(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_ru(double a, double b)
{
  return __fma_ru(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_rd(double a, double b)
{
  return __fma_rd(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static __attribute__((__unused__)) double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __longlong_as_double(0x8000000000000000ULL));
}

static __attribute__((__unused__)) double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, 0.0);
}

static __attribute__((__unused__)) double __dadd_rn(double a, double b)
{
  return __fma_rn(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, __longlong_as_double(0x8000000000000000ULL));
}
# 4670 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1910 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 3
extern void __cudaTextureFetch(const void *tex, void *index, int integer, void *val);

static __attribute__((__unused__)) int4 __itexfetchi(const void *tex, int4 index)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetchi(const void *tex, int4 index)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetchi(const void *tex, int4 index)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) int4 __itexfetch(const void *tex, float4 index, int dim)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetch(const void *tex, float4 index, int dim)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetch(const void *tex, float4 index, int dim)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}
# 4671 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 997 "/usr/local/cuda/bin/../include/math_functions.h" 2 3


static __attribute__((__unused__)) int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static __attribute__((__unused__)) float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 1021 "/usr/local/cuda/bin/../include/math_functions.h" 3


extern __attribute__((__weak__)) int min(int a, int b); int min(int a, int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) unsigned int umin(unsigned int a, unsigned int b); unsigned int umin(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) long long int llmin(long long int a, long long int b); long long int llmin(long long int a, long long int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) unsigned long long int ullmin(unsigned long long int a, unsigned long long int b); unsigned long long int ullmin(unsigned long long int a, unsigned long long int b)
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

extern __attribute__((__weak__)) long long int llmax(long long int a, long long int b); long long int llmax(long long int a, long long int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak__)) unsigned long long int ullmax(unsigned long long int a, unsigned long long int b); unsigned long long int ullmax(unsigned long long int a, unsigned long long int b)
{
  return a > b ? a : b;
}


# 1135 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_nearbyintf(float a)
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

static __attribute__((__unused__)) float __internal_fminf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.i | cvtb.i) == 0x80000000) {
    return __int_as_float(0x80000000);
  }
  return a < b ? a : b;
}

static __attribute__((__unused__)) float __internal_fmaxf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.f == 0.0f) && (cvtb.f == 0.0f)) {
    cvta.i &= cvtb.i;
    return cvta.f;
  }
  return a > b ? a : b;
}
# 1235 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) long int __cuda_labs(long int a)
{
  return labs(a);
}

static __attribute__((__unused__)) float __cuda_ceilf(float a)
{
  return ceilf(a);
}

static __attribute__((__unused__)) float __cuda_floorf(float a)
{
  return floorf(a);
}

static __attribute__((__unused__)) float __cuda_sqrtf(float a)
{
  return sqrtf(a);
}

static __attribute__((__unused__)) float __cuda_rsqrtf(float a)
{
  return rsqrtf(a);
}

static __attribute__((__unused__)) float __cuda_truncf(float a)
{
  return truncf(a);
}

static __attribute__((__unused__)) int __cuda_max(int a, int b)
{
  return max(a, b);
}

static __attribute__((__unused__)) int __cuda_min(int a, int b)
{
  return min(a, b);
}

static __attribute__((__unused__)) unsigned int __cuda_umax(unsigned int a, unsigned int b)
{
  return umax(a, b);
}

static __attribute__((__unused__)) unsigned int __cuda_umin(unsigned int a, unsigned int b)
{
  return umin(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llmax(long long int a, long long int b)
{
  return llmax(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llmin(long long int a, long long int b)
{
  return llmin(a, b);
}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmax(unsigned long long int a, unsigned long long int b)
{
  return ullmax(a, b);
}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmin(unsigned long long int a, unsigned long long int b)
{
  return ullmin(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llrintf(float a)
{



  return __float2ll_rn(a);

}

static __attribute__((__unused__)) long int __cuda_lrintf(float a)
{




  return (long int)__cuda_llrintf(a);




}

static __attribute__((__unused__)) float __cuda_nearbyintf(float a)
{





  return __internal_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_fmaxf(float a, float b)
{





  return __internal_fmaxf(a, b);

}

static __attribute__((__unused__)) float __cuda_fminf(float a, float b)
{





  return __internal_fminf(a, b);

}






static __attribute__((__unused__)) int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1379 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda___isinff(float a)
{
  return __cuda_fabsf(a) == __int_as_float(0x7f800000);
}

static __attribute__((__unused__)) int __cuda___isnanf(float a)
{
  return !(__cuda_fabsf(a) <= __int_as_float(0x7f800000));
}

static __attribute__((__unused__)) float __cuda_nextafterf(float a, float b)
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

static __attribute__((__unused__)) float __cuda_nanf(const char *tagp)
{

  return __int_as_float(0x7fffffff);
}

static __attribute__((__unused__)) float __internal_fmad(float a, float b, float c)
{

  return __fmaf_rn (a, b, c);



}


static __attribute__((__unused__)) float __internal_atanhf_kernel(float a_1, float a_2)
{
  float a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 1.566305595598990E-001f/64.0f;
  t = __internal_fmad (t, a2, 1.995081856004762E-001f/16.0f);
  t = __internal_fmad (t, a2, 3.333382699617026E-001f/4.0f);
  t = t * a2;
  t = __internal_fmad (t, a, a_2);
  t = t + a_1;
  return t;
}




static __attribute__((__unused__)) float __internal_atanf_kernel(float a)
{
  float t4, t0, t1;

  t4 = a * a;
  t0 = -5.674867153f;
  t0 = __internal_fmad (t4, -0.823362947f, t0);
  t0 = __internal_fmad (t0, t4, -6.565555096f);
  t0 = t0 * t4;
  t0 = t0 * a;
  t1 = t4 + 11.33538818f;
  t1 = __internal_fmad (t1, t4, 28.84246826f);
  t1 = __internal_fmad (t1, t4, 19.69667053f);
  t1 = 1.0f / t1;
  a = __internal_fmad (t0, t1, a);
  return a;
}


static __attribute__((__unused__)) float __internal_tan_kernel(float a)
{
  float a2, s, t;

  a2 = a * a;
  t = __internal_fmad (4.114678393115178E-003f, a2, -8.231194034909670E-001f);
  s = a2 - 2.469348886157666E+000f;
  s = 1.0f / s;
  t = t * s;
  t = t * a2;
  t = __internal_fmad (t, a, a);
  return t;
}

static __attribute__((__unused__)) float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia;
  ia = __float_as_int(a);

  if ((a > 0.0f) && (a < __int_as_float(0x7f800000))) {
    int e = -127;


    if ((unsigned)ia < (unsigned)0x00800000) {
      a = a * 16777216.0f;
      e -= 24;
      ia = __float_as_int(a);
    }


    m = __int_as_float((ia & 0x807fffff) | 0x3f800000);
    e += ((unsigned)ia >> 23);
    if (m > 1.414213562f) {
      m = m * 0.5f;
      e = e + 1;
    }
    t = m - 1.0f;
    z = m + 1.0f;
    z = __fdividef (t, z);
    z = -t * z;
    z = __internal_atanhf_kernel(t, z);
    z = __internal_fmad ((float)e, 0.693147181f, z);
    return z;
  } else {

    return __logf(a);
  }
}

static __attribute__((__unused__)) float2 __internal_log_ep(float a)
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
  q = __internal_fmad (q, v, 1.99887797540072460E-001f/16.0f);
  q = __internal_fmad (q, v, 3.33333880955515580E-001f/4.0f);
  q = q * v;
  q = q * u;
  log_hi = __int_as_float(__float_as_int(u) & 0xfffff000);
  v = __int_as_float(__float_as_int(f) & 0xfffff000);
  u = 2.0f * (f - log_hi);
  f = f - v;
  u = __internal_fmad (-log_hi, v, u);
  u = __internal_fmad (-log_hi, f, u);
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

static __attribute__((__unused__)) float __internal_accurate_log2f(float a)
{
  return 1.442695041f * __internal_accurate_logf(a);
}




static __attribute__((__unused__)) float2 __internal_dsmul (float2 x, float2 y)
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


static __attribute__((__unused__)) float __internal_trig_reduction_kernel(float a, int *quadrant)
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
      hi = (hi << e) + (lo >> q);
      lo = (lo << e) + (result[idx] >> q);
    }
    q = hi >> 30;

    hi = (hi << 2) + (lo >> 30);
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
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xc90fdaa2;
    hi = __umulhi(hi, 0xc90fdaa2);
    if ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | (((e + 126) << 23) + (hi >> 8) + ((hi << 24) >= 0x80000000));
    return __int_as_float(ia);
  }
  q = __float2int_rn (a * 0.636619772f);
  j = (float)q;
  a = __internal_fmad (-j, 1.5703125000000000e+000f, a);


  a = __fmaf_rn (-j, 4.8382673412561417e-004f, a);




  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}
# 1743 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = __internal_fmad (j, -0.6931457519f, a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
  z = z * 1.442695041f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j + scale);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_expf(float a)
{
  float z;

  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a > 105.0f) z = __int_as_float(0x7f800000);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_exp10f(float a)
{
  float j, z;

  j = __cuda_truncf(a * 3.321928094f);
  z = __internal_fmad (j, -3.0102920532226563e-001f, a);
  z = __internal_fmad (j, -7.9034171557301747e-007f, z);
  z = z * 3.321928094f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j);
  if (a < -46.0f) z = 0.0f;
  if (a > 46.0f) z = __int_as_float(0x7f800000);
  return z;
}

static __attribute__((__unused__)) float __internal_lgammaf_pos(float a)
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
      sum = __internal_fmad (sum, t, -0.2777655457e-2f);
      sum = __internal_fmad (sum, t, 0.83333273853e-1f);
      sum = __internal_fmad (sum, s, 0.918938533204672f);
      s = 0.5f * __internal_accurate_logf(a);
      t = a - 0.5f;
      s = s * t;
      t = s - a;
      s = __fadd_rn(s, sum);
      t = t + s;
      return t;
    } else {
      a = a - 3.0f;
      s = -7.488903254816711E+002f;
      s = __internal_fmad (s, a, -1.234974215949363E+004f);
      s = __internal_fmad (s, a, -4.106137688064877E+004f);
      s = __internal_fmad (s, a, -4.831066242492429E+004f);
      s = __internal_fmad (s, a, -1.430333998207429E+005f);
      t = a - 2.592509840117874E+002f;
      t = __internal_fmad (t, a, -1.077717972228532E+004f);
      t = __internal_fmad (t, a, -9.268505031444956E+004f);
      t = __internal_fmad (t, a, -2.063535768623558E+005f);
      t = __fdividef (s, t);
      t = t + a;
      return t;
    }
  } else if (a >= 1.5f) {
    a = a - 2.0f;
    t = 4.959849168282574E-005f;
    t = __internal_fmad (t, a, -2.208948403848352E-004f);
    t = __internal_fmad (t, a, 5.413142447864599E-004f);
    t = __internal_fmad (t, a, -1.204516976842832E-003f);
    t = __internal_fmad (t, a, 2.884251838546602E-003f);
    t = __internal_fmad (t, a, -7.382757963931180E-003f);
    t = __internal_fmad (t, a, 2.058131963026755E-002f);
    t = __internal_fmad (t, a, -6.735248600734503E-002f);
    t = __internal_fmad (t, a, 3.224670187176319E-001f);
    t = __internal_fmad (t, a, 4.227843368636472E-001f);
    t = t * a;
    return t;
  } else if (a >= 0.7f) {
    a = 1.0f - a;
    t = 4.588266515364258E-002f;
    t = __internal_fmad (t, a, 1.037396712740616E-001f);
    t = __internal_fmad (t, a, 1.228036339653591E-001f);
    t = __internal_fmad (t, a, 1.275242157462838E-001f);
    t = __internal_fmad (t, a, 1.432166835245778E-001f);
    t = __internal_fmad (t, a, 1.693435824224152E-001f);
    t = __internal_fmad (t, a, 2.074079329483975E-001f);
    t = __internal_fmad (t, a, 2.705875136435339E-001f);
    t = __internal_fmad (t, a, 4.006854436743395E-001f);
    t = __internal_fmad (t, a, 8.224669796332661E-001f);
    t = __internal_fmad (t, a, 5.772156651487230E-001f);
    t = t * a;
    return t;
  } else {
    t = 3.587515669447039E-003f;
    t = __internal_fmad (t, a, -5.471285428060787E-003f);
    t = __internal_fmad (t, a, -4.462712795343244E-002f);
    t = __internal_fmad (t, a, 1.673177015593242E-001f);
    t = __internal_fmad (t, a, -4.213597883575600E-002f);
    t = __internal_fmad (t, a, -6.558672843439567E-001f);
    t = __internal_fmad (t, a, 5.772153712885004E-001f);
    t = t * a;
    t = __internal_fmad (t, a, a);
    return -__internal_accurate_logf(t);
  }
}


static __attribute__((__unused__)) float __internal_sin_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = -1.95152959e-4f;
  z = __internal_fmad (z, x2, 8.33216087e-3f);
  z = __internal_fmad (z, x2, -1.66666546e-1f);
  z = z * x2;
  z = __internal_fmad (z, x, x);
  return z;
}


static __attribute__((__unused__)) float __internal_cos_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = 2.44331571e-5f;
  z = __internal_fmad (z, x2, -1.38873163e-3f);
  z = __internal_fmad (z, x2, 4.16666457e-2f);
  z = __internal_fmad (z, x2, -5.00000000e-1f);
  z = __internal_fmad (z, x2, 1.00000000e+0f);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_sinf(float a)
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







static __attribute__((__unused__)) float __cuda_rintf(float a)
{



  return __cuda_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_sinf(float a)
{





  return __internal_accurate_sinf(a);

}

static __attribute__((__unused__)) float __cuda_cosf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
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

static __attribute__((__unused__)) float __cuda_tanf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  z = __internal_tan_kernel(z);
  if (i & 1) {
    z = - (1.0f / z);
  }
  return z;

}

static __attribute__((__unused__)) float __cuda_log2f(float a)
{





  return __internal_accurate_log2f(a);

}

static __attribute__((__unused__)) float __cuda_expf(float a)
{





  return __internal_accurate_expf(a);

}

static __attribute__((__unused__)) float __cuda_exp10f(float a)
{





  return __internal_accurate_exp10f(a);

}

static __attribute__((__unused__)) float __cuda_coshf(float a)
{
  float z;

  a = __cuda_fabsf(a);
  z = __internal_expf_kernel(a, -2.0f);
  z = __internal_fmad (2.0f, z, __fdividef (0.125f, z));
  if (a >= 90.0f) {
    z = __int_as_float(0x7f800000);
  }
  return z;
}

static __attribute__((__unused__)) float __cuda_sinhf(float a)
{
  float s, z;

  s = a;
  a = __cuda_fabsf(a);
  if (a < 1.0f) {
    float a2 = a * a;

    z = 2.816951222e-6f;
    z = __internal_fmad (z, a2, 1.983615978e-4f);
    z = __internal_fmad (z, a2, 8.333350058e-3f);
    z = __internal_fmad (z, a2, 1.666666650e-1f);
    z = z * a2;
    z = __internal_fmad (z, a, a);
  } else {
    z = __internal_expf_kernel(a, -2.0f);
    z = __internal_fmad (2.0f, z, -__fdividef (0.125f, z));
    if (a >= 90.0f) {
      z = __int_as_float(0x7f800000);
    }
  }
  return __cuda_copysignf(z, s);
}

static __attribute__((__unused__)) float __cuda_tanhf(float a)
{
  float s, t;

  t = __cuda_fabsf(a);
  if (t < 0.55f) {
    float z, z2;
    z = t;
    z2 = z * z;
    t = 1.643758066599993e-2f;
    t = __internal_fmad (t, z2, -5.267181327760551e-2f);
    t = __internal_fmad (t, z2, 1.332072505223051e-1f);
    t = __internal_fmad (t, z2, -3.333294663641083e-1f);
    t = t * z2;
    s = __internal_fmad (t, z, z);
  } else {
    s = 1.0f - __fdividef(2.0f,(__internal_expf_kernel(2.0f * t, 0.0f)+1.0f));
    if (t >= 88.0f) {
      s = 1.0f;
    }
  }
  return __cuda_copysignf(s, a);
}

static __attribute__((__unused__)) float __cuda_atan2f(float a, float b)
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

static __attribute__((__unused__)) float __cuda_atanf(float a)
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


static __attribute__((__unused__)) float __internal_asinf_kernel(float a)
{
  float t2, t3, t4;

  t2 = a * a;
  t3 = -0.501162291f;
  t3 = __internal_fmad (t3, t2, 0.915201485f);
  t3 = t3 * t2;
  t3 = t3 * a;
  t4 = t2 - 5.478654385f;
  t4 = __internal_fmad (t4, t2, 5.491230488f);
  t4 = 1.0f / t4;
  a = __internal_fmad (t3, t4, a);
  return a;
}

static __attribute__((__unused__)) float __cuda_asinf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.575f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t2 = __internal_fmad (-2.0f, t1, 1.570796327f);
  if (t0 > 0.575f) {
    t1 = t2;
  }
  return __cuda_copysignf(t1, a);
}

static __attribute__((__unused__)) float __cuda_acosf(float a)
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

static __attribute__((__unused__)) float __cuda_logf(float a)
{





  return __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log10f(float a)
{





  return 0.434294482f * __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log1pf(float a)
{



  float t;




  if (a >= -0.394f && a <= 0.65f) {

    t = a + 2.0f;
    t = __fdividef (a, t);
    t = -a * t;
    t = __internal_atanhf_kernel (a, t);
  } else {
    t = __internal_accurate_logf (1.0f + a);
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_acoshf(float a)
{



  float t;

  t = a - 1.0f;
  if (__cuda_fabsf(t) > 8388608.0f) {

    return 0.693147181f + __internal_accurate_logf(a);
  } else {
    t = t + __cuda_sqrtf(__internal_fmad (a, t, t));
    return __cuda_log1pf(t);
  }

}

static __attribute__((__unused__)) float __cuda_asinhf(float a)
{



  float fa, oofa, t;

  fa = __cuda_fabsf(a);
  if (fa > 8.507059173e37f) {
    t = 0.693147181f + __logf(fa);
  } else {
    oofa = 1.0f / fa;
    t =fa+__fdividef (fa,(oofa+__cuda_sqrtf(__internal_fmad(oofa,oofa,1.0f))));
    t = __cuda_log1pf(t);
  }
  return __cuda_copysignf(t, a);

}

static __attribute__((__unused__)) float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * __cuda_log1pf(t);
  return __cuda_copysignf(t, a);

}

static __attribute__((__unused__)) float __cuda_expm1f(float a)
{
  float t, z, j, u;

  t = __cuda_rintf (a * 1.442695041f);
  z = __internal_fmad (-t, 0.6931457519f, a);
  z = __internal_fmad (-t, 1.4286067653e-6f, z);

  if (__cuda_fabsf(a) < 0.41f) {
    z = a;
    t = 0.0f;
  }

  j = t;
  if (t == 128.0f) j = j - 1.0f;

  u = 1.38795078474044430E-003f;
  u = __internal_fmad (u, z, 8.38241261853264930E-003f);
  u = __internal_fmad (u, z, 4.16678317762833940E-002f);
  u = __internal_fmad (u, z, 1.66663978874356580E-001f);
  u = __internal_fmad (u, z, 4.99999940395997040E-001f);
  u = u * z;
  u = __internal_fmad (u, z, z);
  if (a == 0.0f) u = a;

  z = __cuda_exp2f (j);
  a = z - 1.0f;
  if (a != 0.0f) u = __internal_fmad (u, z, a);
  if (t == 128.0f) u = u + u;

  if (j > 128.0f) u = __int_as_float(0x7f800000);
  if (j < -25.0f) u = -1.0f;
  return u;
}

static __attribute__((__unused__)) float __cuda_hypotf(float a, float b)
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
  t = __internal_fmad (t, t, 1.0f);
  t = v * __cuda_sqrtf(t);
  if (v == 0.0f) {
    t = v + w;
  }
  if ((v == __int_as_float(0x7f800000)) || (w == __int_as_float(0x7f800000))) {
    t = __int_as_float(0x7f800000);
  }
  return t;

}

static __attribute__((__unused__)) float __cuda_cbrtf(float a)
{



  float s, t;

  s = __cuda_fabsf(a);
  if ((a == 0.0f) || (s == __int_as_float(0x7f800000))) {
    return a + a;
  }
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t-(t-(__fdividef(s,(t*t))))*0.333333333f;





  t = __cuda_copysignf(t, a);

  return t;

}

static __attribute__((__unused__)) float __cuda_erff(float a)
{
  float t, r, q;

  t = __cuda_fabsf(a);
  if (t < 1.0f) {
    t = t * t;
    r = -5.58510127926029810E-004f;
    r = __internal_fmad (r, t, 4.90688891415893070E-003f);
    r = __internal_fmad (r, t, -2.67027980930150640E-002f);
    r = __internal_fmad (r, t, 1.12799056505903940E-001f);
    r = __internal_fmad (r, t, -3.76122956138427440E-001f);
    r = __internal_fmad (r, t, 1.12837911712623450E+000f);
    a = a * r;
  } else if (t <= __int_as_float(0x7f800000)) {



    q = __internal_fmad (t, 0.3275911f, 1.0f);
    q = 1.0f / q;
    r = 1.061405429f;
    r = __internal_fmad (r, q, -1.453152027f);
    r = __internal_fmad (r, q, 1.421413741f);
    r = __internal_fmad (r, q, -0.284496736f);
    r = __internal_fmad (r, q, 0.254829592f);
    r = r * q;
    q = __internal_expf_kernel(-a * a, 0.0f);
    r = __internal_fmad (-q, r, 1.0f);
    if (t >= 5.5f) {
      r = 1.0f;
    }
    a = __int_as_float (__float_as_int(r) | (__float_as_int(a) & 0x80000000));
  }
  return a;
}

static __attribute__((__unused__)) float __cuda_erfinvf (float a)
{
  float fa, t;

  fa = fabsf(a);
  if (fa >= 1.0f) {
    t = __cuda_rsqrtf (__int_as_float (0xffc00000));
    if (fa == 1.0f) {
      t = a * __int_as_float(0x7f800000);
    }
  } else if (fa > 0.9375f) {




    float p, q;

    t = __cuda_log1pf(-fa);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
    if (a < 0.0f) t = -t;
  } else if (fa > 0.75f) {




    float p, q;

    t = __internal_fmad (a, a, -0.87890625f);
    p = -7.1986748896e+0f;
    p = __internal_fmad (p, t, +1.3411974175e+1f);
    p = __internal_fmad (p, t, -5.1381573203e+0f);
    p = __internal_fmad (p, t, 4.9633374831e-1f);
    q = t -1.1436535838e+1f;
    q = __internal_fmad (q, t, 1.3568885572e+1f);
    q = __internal_fmad (q, t, -4.1747509256e+0f);
    q = __internal_fmad (q, t, 3.5327242323e-1f);
    p = __fdividef (p, q);
    t = a * p;
  } else {
    float a2;

    a2 = a * a;
    t = 6.1046168794766742E-001f;
    t = __internal_fmad (t, a2, -8.9504882462753121E-001f);
    t = __internal_fmad (t, a2, 7.0224162369928511E-001f);
    t = __internal_fmad (t, a2, -1.9993784895823222E-001f);
    t = __internal_fmad (t, a2, 1.1920613463949599E-001f);
    t = __internal_fmad (t, a2, 8.0131492246997685E-002f);
    t = __internal_fmad (t, a2, 1.2793154958377403E-001f);
    t = __internal_fmad (t, a2, 2.3200529172828793E-001f);
    t = __internal_fmad (t, a2, 8.8622695604694379E-001f);
    t = t * a;
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_erfcf(float a)
{

    if (__cuda___isnanf(a)) return a + a;

  if (a <= 0.813f) {
    return 1.0f - __cuda_erff(a);
  } else if (a > 10.055f) {
    return 0.0f;
  } else {
    float p;
    float q;
    float h;
    float l;




    p = 1.9997798317768276E-006f;
    p = __internal_fmad (p, a, 5.6410849770777538E-001f);
    p = __internal_fmad (p, a, 2.4579440583231387E+000f);
    p = __internal_fmad (p, a, 4.9763988947448308E+000f);
    p = __internal_fmad (p, a, 4.5767235962336885E+000f);
    q = a + 4.3540863476555538E+000f;
    q = __internal_fmad (q, a, 9.3453217404616584E+000f);
    q = __internal_fmad (q, a, 1.0132282183545772E+001f);
    q = __internal_fmad (q, a, 4.5781789912165518E+000f);

    h = 1.0f / q;
    q = __internal_fmad (-q * h, h, 2.0f * h);
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

static __attribute__((__unused__)) float __cuda_erfcinvf (float a)
{
  float t;
  if (a <= 0.0f) {
    t = __int_as_float(0x7fffffff);
    if (a == 0.0f) {
      t = (1.0f - a) * __int_as_float(0x7f800000);
    }
  }
  else if (a >= 0.0625f) {
    t = __cuda_erfinvf (1.0f - a);
  }
  else {
    float p, q;
    t = __cuda_logf(a);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_lgammaf(float a)
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
  i = __internal_fmad (-i, 0.5f, a);
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

static __attribute__((__unused__)) float __cuda_ldexpf(float a, int b)
{



  float fa = __cuda_fabsf(a);

  if ((fa == 0.0f) || (fa == __int_as_float(0x7f800000)) || (b == 0)) {
    if (!(fa > 0.0f)) a = a + a;
    return a;
  } else if (__cuda_abs(b) < 126) {
    return a * __cuda_exp2f((float)b);
  } else if (__cuda_abs(b) < 252) {
    int bhalf = b / 2;
    return a * __cuda_exp2f((float)bhalf) * __cuda_exp2f((float)(b - bhalf));
  } else {
    int bquarter = b / 4;
    float t = __cuda_exp2f((float)bquarter);
    return a * t * t * t * __cuda_exp2f((float)(b - 3 * bquarter));
  }

}

static __attribute__((__unused__)) float __cuda_scalbnf(float a, int b)
{




  return __cuda_ldexpf(a, b);

}

static __attribute__((__unused__)) float __cuda_scalblnf(float a, long int b)
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

static __attribute__((__unused__)) float __cuda_frexpf(float a, int *b)
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

static __attribute__((__unused__)) float __cuda_modff(float a, float *b)
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

static __attribute__((__unused__)) float __cuda_fmodf(float a, float b)
{



  float orig_a = a;
  float orig_b = b;
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
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
    if (!(a > 0.0f)) orig_a = orig_a + orig_a;
    return orig_a;
  }

}

static __attribute__((__unused__)) float __cuda_remainderf(float a, float b)
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
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
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
# 2758 "/usr/local/cuda/bin/../include/math_functions.h" 3
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        twoa = __internal_fmad (a, 2.0f, -scaled_b) - scaled_b;
        a = a - scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5f;
    }
  }


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
# 2790 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static __attribute__((__unused__)) float __cuda_remquof(float a, float b, int* quo)
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
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
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
# 2846 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 2881 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static __attribute__((__unused__)) float __cuda_fmaf(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static __attribute__((__unused__)) float __internal_accurate_powf(float a, float b)
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



    t = __internal_fmad (t, prod.x, t);
  }
  return t;
}

static __attribute__((__unused__)) float __cuda_powif(float a, int b)
{
  unsigned int e = __cuda_abs(b);
  float r = 1.0f;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0f / r : r;
    }
    a = a * a;
  }
}

static __attribute__((__unused__)) double __cuda_powi(double a, int b)
{
  unsigned int e = __cuda_abs(b);
  double r = 1.0;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0 / r : r;
    }
    a = a * a;
  }
}

static __attribute__((__unused__)) float __cuda_powf(float a, float b)
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
    t = - ((b < 0.0f) ? (1.0f / a) : a);
    if (bIsOddInteger) {
      t = __int_as_float(__float_as_int(t) ^ 0x80000000);
    }
    return t;
  }
  if ((a < 0.0f) && (b != __cuda_truncf(b))) {
    return __cuda_rsqrtf(__int_as_float(0xffc00000));
  }
  t = __cuda_fabsf(a);
  t = __internal_accurate_powf(t, b);
  if ((a < 0.0f) && bIsOddInteger) {
    t = __int_as_float(__float_as_int(t) ^ 0x80000000);
  }
  return t;

}


static __attribute__((__unused__)) float __internal_tgammaf_kernel(float a)
{
  float t;
  t = -1.05767296987211380E-003f;
  t = __internal_fmad (t, a, 7.09279059435508670E-003f);
  t = __internal_fmad (t, a, -9.65347121958557050E-003f);
  t = __internal_fmad (t, a, -4.21736613253687960E-002f);
  t = __internal_fmad (t, a, 1.66542401247154280E-001f);
  t = __internal_fmad (t, a, -4.20043267827838460E-002f);
  t = __internal_fmad (t, a, -6.55878234051332940E-001f);
  t = __internal_fmad (t, a, 5.77215696929794240E-001f);
  t = __internal_fmad (t, a, 1.00000000000000000E+000f);
  return t;
}





static __attribute__((__unused__)) float __cuda_tgammaf(float a)
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
    s = __fdividef(s, xx);
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

static __attribute__((__unused__)) float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  float u = __cuda_copysignf (0.5f, a);
  u = __cuda_truncf (a + u);
  if (fa > 8388608.0f) u = a;
  if (fa < 0.5f) u = __cuda_truncf (a);
  return u;

}

static __attribute__((__unused__)) long long int __internal_llroundf_kernel(float a)
{
  unsigned long long int res, t = 0LL;
  int shift;
  unsigned int ia = __float_as_int(a);

  if ((ia << 1) > 0xff000000) return 0x8000000000000000LL;
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

static __attribute__((__unused__)) long long int __cuda_llroundf(float a)
{



  return __internal_llroundf_kernel(a);

}

static __attribute__((__unused__)) long int __cuda_lroundf(float a)
{




  return (long int)__cuda_llroundf(a);
# 3169 "/usr/local/cuda/bin/../include/math_functions.h" 3
}

static __attribute__((__unused__)) float __cuda_fdimf(float a, float b)
{
  float t;
  t = a - b;
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static __attribute__((__unused__)) int __cuda_ilogbf(float a)
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

static __attribute__((__unused__)) float __cuda_logbf(float a)
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

static __attribute__((__unused__)) void __cuda_sincosf(float a, float *sptr, float *cptr)
{





  float t, u, s, c;
  int quadrant;
  t = __cuda_fabsf(a);
  if ((t == __int_as_float(0x7f800000)) || (t == 0.0f)) {
    s = __fmul_rn (a, 0.0f);
    c = 1.0f + s;
    *sptr = s;
    *cptr = c;
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
# 3298 "/usr/local/cuda/bin/../include/math_functions.h" 3


extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}


# 3869 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 61 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
static __attribute__((__unused__)) double __cuda_fabs(double a)
{
  return fabs(a);
}

static __attribute__((__unused__)) double __cuda_fmax(double a, double b)
{

  volatile union __cudart_DoubleUlonglongCvt cvta, cvtb;
  int nana, nanb;

  cvta.d = a;
  cvtb.d = b;
  nana = ((cvta.i << 1) > 0xffe0000000000000ULL);
  nanb = ((cvtb.i << 1) > 0xffe0000000000000ULL);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.d == 0.0) && (cvtb.d == 0.0)) {
    cvta.i &= cvtb.i;
    return cvta.d;
  }
  return a > b ? a : b;



}

static __attribute__((__unused__)) double __cuda_fmin(double a, double b)
{

  volatile union __cudart_DoubleUlonglongCvt cvta, cvtb;
  int nana, nanb;

  cvta.d = a;
  cvtb.d = b;
  nana = ((cvta.i << 1) > 0xffe0000000000000ULL);
  nanb = ((cvtb.i << 1) > 0xffe0000000000000ULL);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.i | cvtb.i) == 0x8000000000000000ULL) {
    return __longlong_as_double(0x8000000000000000ULL) ;
  }
  return a < b ? a : b;



}

static __attribute__((__unused__)) double __cuda_ceil(double a)
{
  return ceil(a);
}

static __attribute__((__unused__)) double __cuda_floor(double a)
{
  return floor(a);
}

static __attribute__((__unused__)) double __cuda_trunc(double a)
{
  return trunc(a);
}

static __attribute__((__unused__)) double __cuda_nearbyint(double a)
{



  double res = nearbyint(a);





  return res;

}







static __attribute__((__unused__)) double __cuda_rint(double a)
{
  return __cuda_nearbyint(a);
}

static __attribute__((__unused__)) long int __cuda_lrint(double a)
{

  return (long int)__double2ll_rn(a);



}

static __attribute__((__unused__)) long long int __cuda_llrint(double a)
{
  return __double2ll_rn(a);
}

static __attribute__((__unused__)) int __cuda___signbit(double a)
{
  return (int)((unsigned int)__double2hiint(a) >> 31);
}

static __attribute__((__unused__)) int __cuda___finite(double a)
{
  return __cuda_fabs(a) < __longlong_as_double(0x7ff0000000000000ULL);
}

static __attribute__((__unused__)) int __cuda___isinf(double a)
{
  return __cuda_fabs(a) == __longlong_as_double(0x7ff0000000000000ULL);
}

static __attribute__((__unused__)) int __cuda___isnan(double a)
{
  return !(__cuda_fabs(a) <= __longlong_as_double(0x7ff0000000000000ULL));
}

static __attribute__((__unused__)) double __cuda_copysign(double a, double b)
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

static __attribute__((__unused__)) double __internal_trig_reduction_kerneld(double a, int *quadrant)
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


static __attribute__((__unused__)) double __internal_sin_kerneld(double x)
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


static __attribute__((__unused__)) double __internal_cos_kerneld(double x)
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


static __attribute__((__unused__)) double __internal_tan_kerneld(double x, int i)
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

static __attribute__((__unused__)) double __cuda_sqrt(double a)
{
  return sqrt(a);
}

static __attribute__((__unused__)) double __cuda_rsqrt(double a)
{

    return 1.0 / sqrt(a);



}


static __attribute__((__unused__)) double __internal_expm1_kernel (double a)
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


static __attribute__((__unused__)) double __internal_atanh_kernel (double a_1, double a_2)
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

static __attribute__((__unused__)) double __internal_exp2i_kernel(int b)
{
  return __hiloint2double((b + 1023) << 20, 0);
}

static __attribute__((__unused__)) double __internal_half(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi - 0x00100000, ilo);
}

static __attribute__((__unused__)) double __internal_twice(double a)
{
  unsigned int ihi, ilo;
  ilo = __double2loint(a);
  ihi = __double2hiint(a);
  return __hiloint2double(ihi + 0x00100000, ilo);
}

static __attribute__((__unused__)) double __cuda_sin(double a)
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

static __attribute__((__unused__)) double __cuda_cos(double a)
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

static __attribute__((__unused__)) void __cuda_sincos(double a, double *sptr, double *cptr)
{
  double t, u, s, c;
  int i;
  t = __cuda_fabs(a);
  if ((t == __longlong_as_double(0x7ff0000000000000ULL)) || (t == 0.0)) {
    s = __dmul_rn (a, 0.0);
    c = 1.0 + s;
    *sptr = s;
    *cptr = c;
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

static __attribute__((__unused__)) double __cuda_tan(double a)
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

static __attribute__((__unused__)) double __cuda_log(double a)
{
  double m, f, g, u, v, tmp, q, ulo, log_lo, log_hi;
  int ihi, ilo;

  ihi = __double2hiint(a);
  ilo = __double2loint(a);

  if ((a > 0.0) && (a < __longlong_as_double(0x7ff0000000000000ULL))) {
    int e = -1023;

    if ((unsigned)ihi < (unsigned)0x00100000) {
      a = a * 18014398509481984.0;
      e -= 54;
      ihi = __double2hiint(a);
      ilo = __double2loint(a);
    }



    e += (ihi >> 20);
    ihi = (ihi & 0x800fffff) | 0x3ff00000;
    m = __hiloint2double (ihi, ilo);
    if ((unsigned)ihi > (unsigned)0x3ff6a09e) {
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
  } else {
    if (__cuda___isnan(a)) {
      return a + a;
    }

    if (a == 0) {
      return -__longlong_as_double(0x7ff0000000000000ULL);
    }

    if (a == __longlong_as_double(0x7ff0000000000000ULL)) {
      return a;
    }

    return __longlong_as_double(0xfff8000000000000ULL);
  }
}


static __attribute__((__unused__)) double2 __internal_ddadd_xgty (double2 x, double2 y)
{
  double2 z;

  volatile

  double r, s, e;
  r = x.y + y.y;
  e = x.y - r;
  s = ((e + y.y) + y.x) + x.x;
  z.y = e = r + s;
  z.x = (r - e) + s;
  return z;
}


static __attribute__((__unused__)) double2 __internal_ddmul (double2 x, double2 y)
{

  volatile

  double e;
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

static __attribute__((__unused__)) double2 __internal_log_ext_prec(double a)
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




  ihi = (ihi & 0x800fffff) | 0x3ff00000;
  m = __hiloint2double (ihi, ilo);
  if ((unsigned)ihi > (unsigned)0x3ff6a09e) {
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

static __attribute__((__unused__)) double __cuda_log2(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 1.4426950408889634e+0, t * 2.0355273740931033e-17);
}

static __attribute__((__unused__)) double __cuda_log10(double a)
{
  double t;
  t = __cuda_log(a);
  return __fma_rn (t, 4.3429448190325182e-1, t * 1.09831965021676510e-17);
}

static __attribute__((__unused__)) double __cuda_log1p(double a)
{
  double t;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x3fe55555) || ((int)i < (int)0xbfd99999)) {

    t = a + 2.0;
    t = a / t;
    t = -a * t;
    t = __internal_atanh_kernel(a, t);
    return t;
  }
  return __cuda_log (a + 1.0);
}

static __attribute__((__unused__)) double __internal_exp_kernel(double a, int scale)
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
  z = __internal_exp2i_kernel(i + scale - 1);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static __attribute__((__unused__)) double __cuda_exp(double a)
{
  double t;
  int i;
  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40862e43) || ((int)i < (int)0xC0874911)) {
    t = __internal_exp_kernel(a, 0);
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_exp2(double a)
{
  double z;
  double t;
  double fac;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40900000) || ((int)i < (int)0xc090cc00)) {
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
    z = __internal_exp2i_kernel(i - 1);
    t = __fma_rn (t, z, z);
    t = t * fac;
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_exp10(double a)
{
  double z;
  double t;
  double fac;
  int i;

  i = __double2hiint(a);
  if (((unsigned)i < (unsigned)0x40734414) || ((int)i < (int)0xc07439b8)) {
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
    z = __internal_exp2i_kernel(i - 1);
    t = __fma_rn (t, z, z);
    t = t * fac;
    return t;
  }
  t = ((unsigned int)i >> 31) ? 0.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_expm1(double a)
{
  double t, z, u;
  int i, j, k;

  k = __double2hiint(a);
  if (((unsigned)k < (unsigned)0x40862e43) || ((int)k < (int)0xc04a8000)) {
    t = __cuda_rint (a * 1.4426950408889634e+0);
    i = (int)t;
    z = __fma_rn (t, -6.9314718055994529e-1, a);
    z = __fma_rn (t, -2.3190468138462996e-17, z);
    k = k + k;
    if ((unsigned)k < (unsigned)0x7fb3e647) {
      z = a;
      i = 0;
    }
    t = __internal_expm1_kernel(z);
    j = i;
    if (i == 1024) j--;
    u = __internal_exp2i_kernel(j);
    a = u - 1.0;
    t = __fma_rn (t, u, a);
    if (i == 1024) t = t + t;
    if (k == 0) t = z;
    return t;
  }
  t = ((unsigned int)k >> 31) ? -1.0 : __longlong_as_double(0x7ff0000000000000ULL);
  if (__cuda___isnan(a)) {
    t = a + a;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_cosh(double a)
{
  double z;
  int i;

  z = __cuda_fabs(a);
  i = __double2hiint(z);
  if ((unsigned)i < (unsigned)0x408633cf) {
    z = __internal_exp_kernel(z, -2);
    z = __fma_rn(2.0, z, 0.125 / z);
    return z;
  } else {
    if (z > 0.0) a = __int_as_float(0x7f800000);
    return a + a;
  }
}

static __attribute__((__unused__)) double __cuda_sinh(double a)
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

static __attribute__((__unused__)) double __cuda_tanh(double a)
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

static __attribute__((__unused__)) double __internal_atan_kernel(double a)
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

static __attribute__((__unused__)) double __cuda_atan2(double a, double b)
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

static __attribute__((__unused__)) double __cuda_atan(double a)
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


static __attribute__((__unused__)) double __internal_asin_kernel(double a, double b)
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

static __attribute__((__unused__)) double __cuda_asin(double a)
{
  double fa, t0, t1;
  int ihi, ahi;
  ahi = __double2hiint(a);
  fa = __cuda_fabs(a);
  ihi = __double2hiint(fa);
  if (ihi < 0x3fe26666) {
    t1 = fa * fa;
    t1 = __internal_asin_kernel (fa, t1);
    t1 = __fma_rn (t1, fa, fa);
    t1 = __cuda_copysign(t1, a);
  } else {
    t1 = __fma_rn (-0.5, fa, 0.5);
    t0 = __cuda_sqrt (t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = -2.0 * t0;
    t1 = __fma_rn (t0, t1, 6.1232339957367660e-17);
    t0 = t0 + 7.8539816339744828e-1;
    t1 = t0 + t1;
    t1 = t1 + 7.8539816339744828e-1;
    if (ahi < 0x3ff00000) {
      t1 = __cuda_copysign(t1, a);
    }
  }
  return t1;
}

static __attribute__((__unused__)) double __cuda_acos(double a)
{
  double t0, t1;
  int ihi, ahi;


  if (__cuda___isnan(a)) {
    return a + a;
  }

  ahi = __double2hiint(a);
  t0 = __cuda_fabs (a);
  ihi = __double2hiint(t0);
  if (ihi < 0x3fe26666) {
    t1 = t0 * t0;
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    if ((unsigned)ahi >= (unsigned)0x80000000) {
      t0 = __fma_rn (1.0, t0, +6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 + t0;
    } else {
      t0 = __fma_rn (1.0, t0, -6.1232339957367660e-17);
      t0 = 1.5707963267948966e+0 - t0;
    }
  } else {
    t1 = __fma_rn (-0.5, t0, 0.5);
    t0 = __cuda_sqrt(t1);
    t1 = __internal_asin_kernel (t0, t1);
    t0 = __fma_rn (t1, t0, t0);
    t0 = 2.0 * t0;
    if ((unsigned)ahi >= (unsigned)0x80000000) {
      t0 = __fma_rn (1.0, t0, -1.2246467991473532e-16);
      t0 = 3.1415926535897931e+0 - t0;
    }
  }
  return t0;
}

static __attribute__((__unused__)) double __cuda_acosh(double a)
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

static __attribute__((__unused__)) double __cuda_asinh(double a)
{
# 1162 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
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

static __attribute__((__unused__)) double __cuda_atanh(double a)
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

static __attribute__((__unused__)) double __cuda_hypot(double a, double b)
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

static __attribute__((__unused__)) double __cuda_cbrt(double a)
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

static __attribute__((__unused__)) double __internal_accurate_pow(double a, double b)
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

static __attribute__((__unused__)) double __cuda_pow(double a, double b)
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

static __attribute__((__unused__)) double __cuda_erf(double a)
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

static __attribute__((__unused__)) double __cuda_erfinv(double a)
{
  double fa, t;

  fa = fabs(a);
  if (fa >= 1.0) {
    t = __longlong_as_double(0xfff8000000000000ULL);
    if (fa == 1.0) {
      t = a * __longlong_as_double(0x7ff0000000000000ULL);
    }
  } else if (fa >= 0.9375) {




    double p, q;

    t = __cuda_log1p(-fa);
    t = __cuda_rsqrt(-t);
    p = 2.7834010353747001060e-3;
    p = __fma_rn (p, t, 8.6030097526280260580e-1);
    p = __fma_rn (p, t, 2.1371214997265515515e+0);
    p = __fma_rn (p, t, 3.1598519601132090206e+0);
    p = __fma_rn (p, t, 3.5780402569085996758e+0);
    p = __fma_rn (p, t, 1.5335297523989890804e+0);
    p = __fma_rn (p, t, 3.4839207139657522572e-1);
    p = __fma_rn (p, t, 5.3644861147153648366e-2);
    p = __fma_rn (p, t, 4.3836709877126095665e-3);
    p = __fma_rn (p, t, 1.3858518113496718808e-4);
    p = __fma_rn (p, t, 1.1738352509991666680e-6);
    q = t+ 2.2859981272422905412e+0;
    q = __fma_rn (q, t, 4.3859045256449554654e+0);
    q = __fma_rn (q, t, 4.6632960348736635331e+0);
    q = __fma_rn (q, t, 3.9846608184671757296e+0);
    q = __fma_rn (q, t, 1.6068377709719017609e+0);
    q = __fma_rn (q, t, 3.5609087305900265560e-1);
    q = __fma_rn (q, t, 5.3963550303200816744e-2);
    q = __fma_rn (q, t, 4.3873424022706935023e-3);
    q = __fma_rn (q, t, 1.3858762165532246059e-4);
    q = __fma_rn (q, t, 1.1738313872397777529e-6);
    t = p / (q * t);
    if (a < 0.0) t = -t;
  } else if (fa >= 0.75) {




    double p, q;

    t = __fma_rn (a, a, -.87890625);
    p = .21489185007307062000e+0;
    p = __fma_rn (p, t, -.64200071507209448655e+1);
    p = __fma_rn (p, t, .29631331505876308123e+2);
    p = __fma_rn (p, t, -.47644367129787181803e+2);
    p = __fma_rn (p, t, .34810057749357500873e+2);
    p = __fma_rn (p, t, -.12954198980646771502e+2);
    p = __fma_rn (p, t, .25349389220714893917e+1);
    p = __fma_rn (p, t, -.24758242362823355486e+0);
    p = __fma_rn (p, t, .94897362808681080020e-2);
    q = t -.12831383833953226499e+2;
    q = __fma_rn (q, t, .41409991778428888716e+2);
    q = __fma_rn (q, t, -.53715373448862143349e+2);
    q = __fma_rn (q, t, .33880176779595142685e+2);
    q = __fma_rn (q, t, -.11315360624238054876e+2);
    q = __fma_rn (q, t, .20369295047216351160e+1);
    q = __fma_rn (q, t, -.18611650627372178511e+0);
    q = __fma_rn (q, t, .67544512778850945940e-2);
    p = p / q;
    t = a * p;
  } else {




    double p, q;

    t = __fma_rn (a, a, -.5625);
    p = -.23886240104308755900e+2;
    p = __fma_rn (p, t, .45560204272689128170e+3);
    p = __fma_rn (p, t, -.22977467176607144887e+4);
    p = __fma_rn (p, t, .46631433533434331287e+4);
    p = __fma_rn (p, t, -.43799652308386926161e+4);
    p = __fma_rn (p, t, .19007153590528134753e+4);
    p = __fma_rn (p, t, -.30786872642313695280e+3);
    q = t -.83288327901936570000e+2;
    q = __fma_rn (q, t, .92741319160935318800e+3);
    q = __fma_rn (q, t, -.35088976383877264098e+4);
    q = __fma_rn (q, t, .59039348134843665626e+4);
    q = __fma_rn (q, t, -.48481635430048872102e+4);
    q = __fma_rn (q, t, .18997769186453057810e+4);
    q = __fma_rn (q, t, -.28386514725366621129e+3);
    p = p / q;
    t = a * p;
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_erfcinv(double a)
{
  double t;

  if (__cuda___isnan(a)) return a + a;

  if (a <= 0.0) {
    t = __longlong_as_double(0xfff8000000000000ULL);
    if (a == 0.0) {
      t = (1.0 - a) * __longlong_as_double(0x7ff0000000000000ULL);
    }
  }
  else if (a >= 0.0625) {
    t = __cuda_erfinv (1.0 - a);
  }
  else if (a >= 1e-100) {




    double p, q;
    t = __cuda_log(a);
    t = __cuda_rsqrt(-t);
    p = 2.7834010353747001060e-3;
    p = __fma_rn (p, t, 8.6030097526280260580e-1);
    p = __fma_rn (p, t, 2.1371214997265515515e+0);
    p = __fma_rn (p, t, 3.1598519601132090206e+0);
    p = __fma_rn (p, t, 3.5780402569085996758e+0);
    p = __fma_rn (p, t, 1.5335297523989890804e+0);
    p = __fma_rn (p, t, 3.4839207139657522572e-1);
    p = __fma_rn (p, t, 5.3644861147153648366e-2);
    p = __fma_rn (p, t, 4.3836709877126095665e-3);
    p = __fma_rn (p, t, 1.3858518113496718808e-4);
    p = __fma_rn (p, t, 1.1738352509991666680e-6);
    q = t+ 2.2859981272422905412e+0;
    q = __fma_rn (q, t, 4.3859045256449554654e+0);
    q = __fma_rn (q, t, 4.6632960348736635331e+0);
    q = __fma_rn (q, t, 3.9846608184671757296e+0);
    q = __fma_rn (q, t, 1.6068377709719017609e+0);
    q = __fma_rn (q, t, 3.5609087305900265560e-1);
    q = __fma_rn (q, t, 5.3963550303200816744e-2);
    q = __fma_rn (q, t, 4.3873424022706935023e-3);
    q = __fma_rn (q, t, 1.3858762165532246059e-4);
    q = __fma_rn (q, t, 1.1738313872397777529e-6);
    t = p / (q * t);
  }
  else {




    double p, q;
    t = __cuda_log(a);
    t = __cuda_rsqrt(-t);
    p = 6.9952990607058154858e-1;
    p = __fma_rn (p, t, 1.9507620287580568829e+0);
    p = __fma_rn (p, t, 8.2810030904462690216e-1);
    p = __fma_rn (p, t, 1.1279046353630280005e-1);
    p = __fma_rn (p, t, 6.0537914739162189689e-3);
    p = __fma_rn (p, t, 1.3714329569665128933e-4);
    p = __fma_rn (p, t, 1.2964481560643197452e-6);
    p = __fma_rn (p, t, 4.6156006321345332510e-9);
    p = __fma_rn (p, t, 4.5344689563209398450e-12);
    q = t+ 1.5771922386662040546e+0;
    q = __fma_rn (q, t, 2.1238242087454993542e+0);
    q = __fma_rn (q, t, 8.4001814918178042919e-1);
    q = __fma_rn (q, t, 1.1311889334355782065e-1);
    q = __fma_rn (q, t, 6.0574830550097140404e-3);
    q = __fma_rn (q, t, 1.3715891988350205065e-4);
    q = __fma_rn (q, t, 1.2964671850944981713e-6);
    q = __fma_rn (q, t, 4.6156017600933592558e-9);
    q = __fma_rn (q, t, 4.5344687377088206783e-12);
    t = p / (q * t);
  }
  return t;
}

static __attribute__((__unused__)) double __cuda_erfc(double a)
{
  double p, q, h, l;
  int ahi;

  ahi = __double2hiint(a);
  if (ahi < (int)0x3fe80000) {
    return 1.0 - __cuda_erf(a);
  }
  if (a > 27.3) {
    return 0.0;
  }
  if (ahi < (int)0x40140000) {

    p = 5.6418956292134603E-001;
    p = __fma_rn (p, a, 7.9573512229784757E+000);
    p = __fma_rn (p, a, 5.4297984550299049E+001);
    p = __fma_rn (p, a, 2.2775657465890461E+002);
    p = __fma_rn (p, a, 6.2995529536738172E+002);
    p = __fma_rn (p, a, 1.1508293767713837E+003);
    p = __fma_rn (p, a, 1.3002167301542784E+003);
    p = __fma_rn (p, a, 7.2716547570180592E+002);
    q = a+ 1.4104035812651274E+001;
    q = __fma_rn (q, a, 9.6740724349422138E+001);
    q = __fma_rn (q, a, 4.1073916054746462E+002);
    q = __fma_rn (q, a, 1.1641974580374074E+003);
    q = __fma_rn (q, a, 2.2344896486798129E+003);
    q = __fma_rn (q, a, 2.8166572432808462E+003);
    q = __fma_rn (q, a, 2.1207350981593036E+003);
    q = __fma_rn (q, a, 7.2716547619708967E+002);
    p = p / q;
    h = a * a;
    l = __fma_rn (a, a, -h);
    q = __internal_exp_kernel(-h, 0);
    q = __fma_rn (l, -q, q);
    p = p * q;
  } else {

    double ooa, ooasq;

    ooa = 1.0 / a;
    ooasq = ooa * ooa;
    p = -4.0025406686930527E+005;
    p = __fma_rn (p, ooasq, 1.4420582543942123E+005);
    p = __fma_rn (p, ooasq, -2.7664185780951841E+004);
    p = __fma_rn (p, ooasq, 4.1144611644767283E+003);
    p = __fma_rn (p, ooasq, -5.8706000519209351E+002);
    p = __fma_rn (p, ooasq, 9.1490086446323375E+001);
    p = __fma_rn (p, ooasq, -1.6659491387740221E+001);
    p = __fma_rn (p, ooasq, 3.7024804085481784E+000);
    p = __fma_rn (p, ooasq, -1.0578553994424316E+000);
    p = __fma_rn (p, ooasq, 4.2314218745087778E-001);
    p = __fma_rn (p, ooasq, -2.8209479177354962E-001);
    p = __fma_rn (p, ooasq, 5.6418958354775606E-001);
    h = a * a;
    l = __fma_rn (a, a, -h);
    q = __internal_exp_kernel(-h, 0);
    q = __fma_rn (l, -q, q);
    p = p * ooa;
    p = p * q;
  }
  return p;
}


static __attribute__((__unused__)) double __internal_tgamma_kernel(double a)
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


static __attribute__((__unused__)) double __internal_stirling_poly(double a)
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

static __attribute__((__unused__)) double __internal_tgamma_stirling(double a)
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

static __attribute__((__unused__)) double __cuda_tgamma(double a)
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

static __attribute__((__unused__)) double __internal_lgamma_pos(double a)
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

static __attribute__((__unused__)) double __cuda_lgamma(double a)
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

static __attribute__((__unused__)) double __cuda_ldexp(double a, int b)
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

static __attribute__((__unused__)) double __cuda_scalbn(double a, int b)
{

  return __cuda_ldexp(a, b);
}

static __attribute__((__unused__)) double __cuda_scalbln(double a, long int b)
{


  if (b < -2147483648L) b = -2147483648L;
  if (b > 2147483647L) b = 2147483647L;

  return __cuda_scalbn(a, (int)b);
}

static __attribute__((__unused__)) double __cuda_frexp(double a, int *b)
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

static __attribute__((__unused__)) double __cuda_modf(double a, double *b)
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

static __attribute__((__unused__)) double __cuda_fmod(double a, double b)
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

static __attribute__((__unused__)) double __cuda_remainder(double a, double b)
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

static __attribute__((__unused__)) double __cuda_remquo(double a, double b, int *c)
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

static __attribute__((__unused__)) double __cuda_nextafter(double a, double b)
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

static __attribute__((__unused__)) double __cuda_nan(const char *s)
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

static __attribute__((__unused__)) double __cuda_round(double a)
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

static __attribute__((__unused__)) long long int __cuda_llround(double a)
{

  if (a >= 9223372036854775807.0) return 0x7fffffffffffffffLL;
  if (a <= -9223372036854775808.0) return 0x8000000000000000LL;

  return (long long int)(__cuda_round(a));
}

static __attribute__((__unused__)) long int __cuda_lround(double a)
{

  return (long int)(__cuda_llround(a));
# 2336 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
}

static __attribute__((__unused__)) double __cuda_fdim(double a, double b)
{
  double t;
  t = a - b;
  if (a <= b) {
    t = 0.0;
  }
  return t;
}

static __attribute__((__unused__)) int __cuda_ilogb(double a)
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

static __attribute__((__unused__)) double __cuda_logb(double a)
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

static __attribute__((__unused__)) double __cuda_fma(double a, double b, double c)
{
  return __fma_rn(a, b, c);
}
# 3870 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 94 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 275 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.stub.c" 2




struct __T20 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float __par4;int __dummy_field;};




struct __T21 {float4 *__par0;uint *__par1;uint *__par2;int __dummy_field;};




struct __T22 {float4 *__par0;uint2 *__par1;int __dummy_field;};




struct __T23 {uint2 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float4 *__par4;uint *__par5;int __dummy_field;};




struct __T24 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;uint2 *__par4;uint *__par5;int __dummy_field;};




struct __T25 {KeyValuePair *__par0;uint __par1;uint __par2;uint __par3;int __dummy_field;};
# 44 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.stub.c"
struct __T26 {KeyValuePair *__par0;KeyValuePair *__par1;uint __par2;uint __par3;int __par4;int __dummy_field;};
static void __sti____cudaRegisterAll_50_tmpxft_0000153d_00000000_19_particleSystem_cpp1_ii_dee98040(void) __attribute__((__constructor__));
void __device_stub__Z9integrateP6float4S0_S0_S0_f(float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float __par4){auto struct __T20 *__T27;
*(void**)(void*)&__T27 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T27->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T27->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T27->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T27->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T27->__par4) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry))); };}

}
void integrate__entry( float4 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,float __cuda_4)
{__device_stub__Z9integrateP6float4S0_S0_S0_f( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);}
extern "C"{

void __device_stub__Z11updateGridDP6float4PjS1_(float4 *__par0, uint *__par1, uint *__par2){auto struct __T21 *__T222;
*(void**)(void*)&__T222 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T222->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T222->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T222->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint *, uint *))updateGridD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint *, uint *))updateGridD__entry))); };}

}
void updateGridD__entry( float4 *__cuda_0,uint *__cuda_1,uint *__cuda_2)
{__device_stub__Z11updateGridDP6float4PjS1_( __cuda_0,__cuda_1,__cuda_2);}
extern "C"{

void __device_stub__Z9calcHashDP6float4P5uint2(float4 *__par0, uint2 *__par1){auto struct __T22 *__T223;
*(void**)(void*)&__T223 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T223->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T223->__par1) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint2 *))calcHashD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint2 *))calcHashD__entry))); };}

}
void calcHashD__entry( float4 *__cuda_0,uint2 *__cuda_1)
{__device_stub__Z9calcHashDP6float4P5uint2( __cuda_0,__cuda_1);}
extern "C"{

void __device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj(uint2 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float4 *__par4, uint *__par5){auto struct __T23 *__T224;
*(void**)(void*)&__T224 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T224->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T224->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T224->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T224->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T224->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T224->__par5) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry)); (void)cudaLaunch(((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry))); };}

}
void reorderDataAndFindCellStartD__entry( uint2 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,float4 *__cuda_4,uint *__cuda_5)
{__device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);}
extern "C"{

void __device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj(float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, uint2 *__par4, uint *__par5){auto struct __T24 *__T2137;
*(void**)(void*)&__T2137 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2137->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2137->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2137->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2137->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2137->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2137->__par5) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry))); };}

}
void collideD__entry( float4 *__cuda_0,float4 *__cuda_1,float4 *__cuda_2,float4 *__cuda_3,uint2 *__cuda_4,uint *__cuda_5)
{__device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);}
extern "C"{

void __device_stub__Z8RadixSumP12KeyValuePairjjj(KeyValuePair *__par0, uint __par1, uint __par2, uint __par3){auto struct __T25 *__T2138;
*(void**)(void*)&__T2138 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2138->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2138->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2138->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2138->__par3) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(KeyValuePair *, uint, uint, uint))RadixSum__entry)); (void)cudaLaunch(((char *)((void ( *)(KeyValuePair *, uint, uint, uint))RadixSum__entry))); };}

}
void RadixSum__entry( KeyValuePair *__cuda_0,uint __cuda_1,uint __cuda_2,uint __cuda_3)
{__device_stub__Z8RadixSumP12KeyValuePairjjj( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{

void __device_stub__Z14RadixPrefixSumv(void){auto struct __T2139 *__T2140;
*(void**)(void*)&__T2140 = (void*)0;{ volatile static char *__f; __f = ((char *)((void ( *)(void))RadixPrefixSum__entry)); (void)cudaLaunch(((char *)((void ( *)(void))RadixPrefixSum__entry))); };}

}
void RadixPrefixSum__entry(void)
{__device_stub__Z14RadixPrefixSumv();}
extern "C"{

void __device_stub__Z25RadixAddOffsetsAndShuffleP12KeyValuePairS0_jji(KeyValuePair *__par0, KeyValuePair *__par1, uint __par2, uint __par3, int __par4){auto struct __T26 *__T2141;
*(void**)(void*)&__T2141 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2141->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2141->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2141->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2141->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2141->__par4) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(KeyValuePair *, KeyValuePair *, uint, uint, int))RadixAddOffsetsAndShuffle__entry)); (void)cudaLaunch(((char *)((void ( *)(KeyValuePair *, KeyValuePair *, uint, uint, int))RadixAddOffsetsAndShuffle__entry))); };}

}
void RadixAddOffsetsAndShuffle__entry( KeyValuePair *__cuda_0,KeyValuePair *__cuda_1,uint __cuda_2,uint __cuda_3,int __cuda_4)
{__device_stub__Z25RadixAddOffsetsAndShuffleP12KeyValuePairS0_jji( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);}
extern "C"{
# 182 "/tmp/tmpxft_0000153d_00000000-4_particleSystem.cudafe1.stub.c"
static void __sti____cudaRegisterAll_50_tmpxft_0000153d_00000000_19_particleSystem_cpp1_ii_dee98040(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(KeyValuePair *, KeyValuePair *, uint, uint, int))RadixAddOffsetsAndShuffle__entry), (char*)"_Z25RadixAddOffsetsAndShuffleP12KeyValuePairS0_jji", "_Z25RadixAddOffsetsAndShuffleP12KeyValuePairS0_jji", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(void))RadixPrefixSum__entry), (char*)"_Z14RadixPrefixSumv", "_Z14RadixPrefixSumv", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(KeyValuePair *, uint, uint, uint))RadixSum__entry), (char*)"_Z8RadixSumP12KeyValuePairjjj", "_Z8RadixSumP12KeyValuePairjjj", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry), (char*)"_Z8collideDP6float4S0_S0_S0_P5uint2Pj", "_Z8collideDP6float4S0_S0_S0_P5uint2Pj", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry), (char*)"_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", "_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint2 *))calcHashD__entry), (char*)"_Z9calcHashDP6float4P5uint2", "_Z9calcHashDP6float4P5uint2", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint *, uint *))updateGridD__entry), (char*)"_Z11updateGridDP6float4PjS1_", "_Z11updateGridDP6float4PjS1_", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry), (char*)"_Z9integrateP6float4S0_S0_S0_f", "_Z9integrateP6float4S0_S0_S0_f", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldPosTex, 0, "oldPosTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldVelTex, 0, "oldVelTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&particleHashTex, 0, "particleHashTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&cellStartTex, 0, "cellStartTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCountersTex, 0, "gridCountersTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCellsTex, 0, "gridCellsTex", 1, 0, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&params__cuda_shadow_variable__, (char*)"params", "params", 0, 112, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&dRadixSum__cuda_shadow_variable__, (char*)"dRadixSum", "dRadixSum", 0, 196608, 0, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&dRadixBlockSum__cuda_shadow_variable__, (char*)"dRadixBlockSum", "dRadixBlockSum", 0, 64, 0, 0);__cudaRegisterShared(__cudaFatCubinHandle, (void**)"sRadixSum");}

}
# 306 "particleSystem.cu" 2

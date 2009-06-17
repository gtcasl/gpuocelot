# 1 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.cpp"
# 1 "bicubicTexture.cu"
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
# 80 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
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
# 90 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 318 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 54 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 262 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 328 "/usr/local/cuda/bin/../include/vector_types.h" 3
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
# 419 "/usr/local/cuda/bin/../include/vector_types.h" 3
typedef struct dim3 dim3;


struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};
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
# 120 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
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
# 81 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 82 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 2 3
# 90 "/usr/local/cuda/bin/../include/driver_types.h"
# 138 "/usr/local/cuda/bin/../include/driver_types.h"
# 150 "/usr/local/cuda/bin/../include/driver_types.h"
# 163 "/usr/local/cuda/bin/../include/driver_types.h"
# 169 "/usr/local/cuda/bin/../include/driver_types.h"
# 181 "/usr/local/cuda/bin/../include/driver_types.h"
# 193 "/usr/local/cuda/bin/../include/driver_types.h"
# 204 "/usr/local/cuda/bin/../include/driver_types.h"
# 215 "/usr/local/cuda/bin/../include/driver_types.h"
# 233 "/usr/local/cuda/bin/../include/driver_types.h"
# 247 "/usr/local/cuda/bin/../include/driver_types.h"
# 259 "/usr/local/cuda/bin/../include/driver_types.h"
# 318 "/usr/local/cuda/bin/../include/driver_types.h"
# 324 "/usr/local/cuda/bin/../include/driver_types.h"
# 330 "/usr/local/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
# 61 "/usr/local/cuda/bin/../include/texture_types.h"
# 68 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 54 "/usr/local/cuda/bin/../include/vector_types.h"
# 60 "/usr/local/cuda/bin/../include/vector_types.h"
# 66 "/usr/local/cuda/bin/../include/vector_types.h"
# 72 "/usr/local/cuda/bin/../include/vector_types.h"
# 78 "/usr/local/cuda/bin/../include/vector_types.h"
# 84 "/usr/local/cuda/bin/../include/vector_types.h"
# 90 "/usr/local/cuda/bin/../include/vector_types.h"
# 96 "/usr/local/cuda/bin/../include/vector_types.h"
# 102 "/usr/local/cuda/bin/../include/vector_types.h"
# 108 "/usr/local/cuda/bin/../include/vector_types.h"
# 114 "/usr/local/cuda/bin/../include/vector_types.h"
# 120 "/usr/local/cuda/bin/../include/vector_types.h"
# 126 "/usr/local/cuda/bin/../include/vector_types.h"
# 132 "/usr/local/cuda/bin/../include/vector_types.h"
# 138 "/usr/local/cuda/bin/../include/vector_types.h"
# 144 "/usr/local/cuda/bin/../include/vector_types.h"
# 150 "/usr/local/cuda/bin/../include/vector_types.h"
# 156 "/usr/local/cuda/bin/../include/vector_types.h"
# 162 "/usr/local/cuda/bin/../include/vector_types.h"
# 168 "/usr/local/cuda/bin/../include/vector_types.h"
# 174 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 186 "/usr/local/cuda/bin/../include/vector_types.h"
# 192 "/usr/local/cuda/bin/../include/vector_types.h"
# 198 "/usr/local/cuda/bin/../include/vector_types.h"
# 204 "/usr/local/cuda/bin/../include/vector_types.h"
# 216 "/usr/local/cuda/bin/../include/vector_types.h"
# 228 "/usr/local/cuda/bin/../include/vector_types.h"
# 262 "/usr/local/cuda/bin/../include/vector_types.h"
# 268 "/usr/local/cuda/bin/../include/vector_types.h"
# 274 "/usr/local/cuda/bin/../include/vector_types.h"
# 280 "/usr/local/cuda/bin/../include/vector_types.h"
# 286 "/usr/local/cuda/bin/../include/vector_types.h"
# 292 "/usr/local/cuda/bin/../include/vector_types.h"
# 298 "/usr/local/cuda/bin/../include/vector_types.h"
# 304 "/usr/local/cuda/bin/../include/vector_types.h"
# 310 "/usr/local/cuda/bin/../include/vector_types.h"
# 316 "/usr/local/cuda/bin/../include/vector_types.h"
# 328 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 332 "/usr/local/cuda/bin/../include/vector_types.h"
# 334 "/usr/local/cuda/bin/../include/vector_types.h"
# 336 "/usr/local/cuda/bin/../include/vector_types.h"
# 338 "/usr/local/cuda/bin/../include/vector_types.h"
# 340 "/usr/local/cuda/bin/../include/vector_types.h"
# 342 "/usr/local/cuda/bin/../include/vector_types.h"
# 344 "/usr/local/cuda/bin/../include/vector_types.h"
# 346 "/usr/local/cuda/bin/../include/vector_types.h"
# 348 "/usr/local/cuda/bin/../include/vector_types.h"
# 350 "/usr/local/cuda/bin/../include/vector_types.h"
# 352 "/usr/local/cuda/bin/../include/vector_types.h"
# 354 "/usr/local/cuda/bin/../include/vector_types.h"
# 356 "/usr/local/cuda/bin/../include/vector_types.h"
# 358 "/usr/local/cuda/bin/../include/vector_types.h"
# 360 "/usr/local/cuda/bin/../include/vector_types.h"
# 362 "/usr/local/cuda/bin/../include/vector_types.h"
# 364 "/usr/local/cuda/bin/../include/vector_types.h"
# 366 "/usr/local/cuda/bin/../include/vector_types.h"
# 368 "/usr/local/cuda/bin/../include/vector_types.h"
# 370 "/usr/local/cuda/bin/../include/vector_types.h"
# 372 "/usr/local/cuda/bin/../include/vector_types.h"
# 374 "/usr/local/cuda/bin/../include/vector_types.h"
# 376 "/usr/local/cuda/bin/../include/vector_types.h"
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
# 419 "/usr/local/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
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
# 120 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
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
# 137 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 152 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
extern "C" cudaError_t cudaSetDevice(int);
extern "C" cudaError_t cudaGetDevice(int *);
extern "C" cudaError_t cudaSetValidDevices(int *, int);
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 206 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
extern "C" const char *cudaGetErrorString(cudaError_t);
# 215 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
extern "C" cudaError_t cudaLaunch(const char *);
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 226 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 237 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 251 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 260 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
extern "C" cudaError_t cudaThreadSynchronize();
# 269 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
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
extern "C" { extern inline __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }




extern "C" { extern inline void *memmove(void *, const void *, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 51 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 59 "/usr/include/string.h" 3
extern "C" { extern inline __attribute__((__weak__)) void *memset(void *, int, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));



extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 73 "/usr/include/string.h" 3
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__));



extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 84 "/usr/include/string.h" 3
extern "C" { extern inline char *strcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }




extern "C" { extern inline char *strcat(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline char *strncat(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }



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


extern "C" { extern inline void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
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



extern "C" { extern inline void bcopy(const void *, void *, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }



extern "C" { extern inline void bzero(void *, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


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

extern "C" { extern inline char *stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }




extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();


extern "C" { extern inline char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }




extern "C" char *strfry(char *) throw();


extern "C" void *memfrob(void *, size_t) throw();
# 393 "/usr/include/string.h" 3
extern "C" char *basename(const char *) throw();
# 23 "/usr/include/bits/string3.h" 3
extern "C" void __warn_memset_zero_len();
# 49 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void *memcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()

{
return __builtin___memcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void *memmove(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()

{
return __builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void *mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, size_t __len) throw()

{
return __builtin___mempcpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
} }
# 78 "/usr/include/bits/string3.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void *memset(void *__dest, int __ch, size_t __len) throw()
{
if ((__builtin_constant_p(__len)) && (__len == (0)))
{
__warn_memset_zero_len();
return __dest;
}
return __builtin___memset_chk(__dest, __ch, __len, __builtin_object_size(__dest, 0));
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void bcopy(const void *__restrict__ __src, void *__restrict__ __dest, size_t __len) throw()

{
(void)__builtin___memmove_chk(__dest, __src, __len, __builtin_object_size(__dest, 0));
} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) void bzero(void *__dest, size_t __len) throw()
{
(void)__builtin___memset_chk(__dest, '\000', __len, __builtin_object_size(__dest, 0));
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
{
return __builtin___strcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
{
return __builtin___stpcpy_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
} }




extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strncpy(char *__restrict__ __dest, const char *__restrict__ __src, size_t __len) throw()

{
return __builtin___strncpy_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
} }


extern "C" char *__stpncpy_chk(char *, const char *, size_t, size_t) throw();

extern "C" char *__stpncpy_alias(char *, const char *, size_t) throw() __asm__("stpncpy");




extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *stpncpy(char *__dest, const char *__src, size_t __n) throw()
{
if ((__builtin_object_size(__dest, 2 > 1) != ((size_t)(-1))) && ((!(__builtin_constant_p(__n))) || (__n <= __builtin_object_size(__dest, 2 > 1)))) {

return __stpncpy_chk(__dest, __src, __n, __builtin_object_size(__dest, 2 > 1)); }
return __stpncpy_alias(__dest, __src, __n);
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strcat(char *__restrict__ __dest, const char *__restrict__ __src) throw()
{
return __builtin___strcat_chk(__dest, __src, __builtin_object_size(__dest, 2 > 1));
} }



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *strncat(char *__restrict__ __dest, const char *__restrict__ __src, size_t __len) throw()

{
return __builtin___strncat_chk(__dest, __src, __len, __builtin_object_size(__dest, 2 > 1));
} }
# 56 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" { extern inline __attribute__((__weak__)) void *memset(void *, int, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 65 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int min(int, int);

extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);

extern "C" __attribute__((__weak__)) float fminf(float, float) throw();

extern "C" __attribute__((__weak__)) double fmin(double, double) throw();


extern "C" __attribute__((__weak__)) int max(int, int);

extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);

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
# 400 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));

extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }


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



extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




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



extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




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



extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




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
# 36 "/usr/include/bits/mathinline.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitf(float __x) throw()
{
auto union { float __f; int __i; } __u = {__f: __x};
return (__u.__i) < 0;
} }

extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbit(double __x) throw()
{
auto union { double __d; int __i[2]; } __u = {__d: __x};
return ((__u.__i)[1]) < 0;
} }

extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitl(long double __x) throw()
{
auto union { long double __l; int __i[3]; } __u = {__l: __x};
return (((__u.__i)[2]) & 32768) != 0;
} }
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




extern "C" { extern inline double atof(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int atoi(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline long atol(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }
# 158 "/usr/include/stdlib.h" 3
extern "C" { extern inline long long atoll(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }
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
# 279 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) double atof(const char *__nptr) throw()
{
return strtod(__nptr, (char **)__null);
} }

extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) int atoi(const char *__nptr) throw()
{
return (int)strtol(__nptr, (char **)__null, 10);
} }

extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) long atol(const char *__nptr) throw()
{
return strtol(__nptr, (char **)__null, 10);
} }
# 298 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) long long atoll(const char *__nptr) throw()
{
return strtoll(__nptr, (char **)__null, 10);
} }
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
extern "C" { extern inline unsigned gnu_dev_major(unsigned long long) throw() __attribute__((__gnu_inline__)); }


extern "C" { extern inline unsigned gnu_dev_minor(unsigned long long) throw() __attribute__((__gnu_inline__)); }


extern "C" { extern inline unsigned long long gnu_dev_makedev(unsigned, unsigned) throw() __attribute__((__gnu_inline__)); }
# 43 "/usr/include/sys/sysmacros.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) unsigned gnu_dev_major(unsigned long long __dev) throw()
{
return ((__dev >> 8) & (4095)) | (((unsigned)(__dev >> 32)) & (~4095));
} }


extern "C" { inline __attribute__((__gnu_inline__)) unsigned gnu_dev_minor(unsigned long long __dev) throw()
{
return (__dev & (255)) | (((unsigned)(__dev >> 12)) & (~255));
} }


extern "C" { inline __attribute__((__gnu_inline__)) unsigned long long gnu_dev_makedev(unsigned __major, unsigned __minor) throw()
{
return (((__minor & (255)) | ((__major & (4095)) << 8)) | (((unsigned long long)(__minor & (~255))) << 12)) | (((unsigned long long)(__major & (~4095))) << 32);


} }
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
extern "C" { extern inline char *realpath(const char *__restrict__, char *__restrict__) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
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



extern "C" { extern inline int wctomb(char *, wchar_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }



extern "C" { extern inline size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
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
extern "C" { extern inline int ptsname_r(int, char *, size_t) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }



extern "C" int getpt();
# 875 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 24 "/usr/include/bits/stdlib.h" 3
extern "C" char *__realpath_chk(const char *__restrict__, char *__restrict__, size_t) throw();


extern "C" char *__realpath_alias(const char *__restrict__, char *__restrict__) throw() __asm__("realpath");


extern "C" char *__realpath_chk_warn(const char *__restrict__, char *__restrict__, size_t) throw() __asm__("__realpath_chk");
# 38 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *realpath(const char *__restrict__ __name, char *__restrict__ __resolved) throw()
{
if (__builtin_object_size(__resolved, 2 > 1) != ((size_t)(-1)))
{

if (__builtin_object_size(__resolved, 2 > 1) < (4096)) {
return __realpath_chk_warn(__name, __resolved, __builtin_object_size(__resolved, 2 > 1)); }

return __realpath_chk(__name, __resolved, __builtin_object_size(__resolved, 2 > 1));
}

return __realpath_alias(__name, __resolved);
} }


extern "C" int __ptsname_r_chk(int, char *, size_t, size_t) throw();

extern "C" int __ptsname_r_alias(int, char *, size_t) throw() __asm__("ptsname_r");


extern "C" int __ptsname_r_chk_warn(int, char *, size_t, size_t) throw() __asm__("__ptsname_r_chk");
# 65 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int ptsname_r(int __fd, char *__buf, size_t __buflen) throw()
{
if (__builtin_object_size(__buf, 2 > 1) != ((size_t)(-1)))
{
if (!(__builtin_constant_p(__buflen))) {
return __ptsname_r_chk(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1)); }
if (__buflen > __builtin_object_size(__buf, 2 > 1)) {
return __ptsname_r_chk_warn(__fd, __buf, __buflen, __builtin_object_size(__buf, 2 > 1)); }
}
return __ptsname_r_alias(__fd, __buf, __buflen);
} }


extern "C" int __wctomb_chk(char *, wchar_t, size_t) throw();

extern "C" int __wctomb_alias(char *, wchar_t) throw() __asm__("wctomb");



extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int wctomb(char *__s, wchar_t __wchar) throw()
{
# 93 "/usr/include/bits/stdlib.h" 3
if ((__builtin_object_size(__s, 2 > 1) != ((size_t)(-1))) && ((16) > __builtin_object_size(__s, 2 > 1))) {
return __wctomb_chk(__s, __wchar, __builtin_object_size(__s, 2 > 1)); }
return __wctomb_alias(__s, __wchar);
} }


extern "C" size_t __mbstowcs_chk(wchar_t *__restrict__, const char *__restrict__, size_t, size_t) throw();


extern "C" size_t __mbstowcs_alias(wchar_t *__restrict__, const char *__restrict__, size_t) throw() __asm__("mbstowcs");



extern "C" size_t __mbstowcs_chk_warn(wchar_t *__restrict__, const char *__restrict__, size_t, size_t) throw() __asm__("__mbstowcs_chk");
# 114 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) size_t mbstowcs(wchar_t *__restrict__ __dst, const char *__restrict__ __src, size_t __len) throw()

{
if (__builtin_object_size(__dst, 2 > 1) != ((size_t)(-1)))
{
if (!(__builtin_constant_p(__len))) {
return __mbstowcs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t)); }


if (__len > (__builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t))) {
return __mbstowcs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1) / sizeof(wchar_t)); }

}
return __mbstowcs_alias(__dst, __src, __len);
} }


extern "C" size_t __wcstombs_chk(char *__restrict__, const wchar_t *__restrict__, size_t, size_t) throw();


extern "C" size_t __wcstombs_alias(char *__restrict__, const wchar_t *__restrict__, size_t) throw() __asm__("wcstombs");



extern "C" size_t __wcstombs_chk_warn(char *__restrict__, const wchar_t *__restrict__, size_t, size_t) throw() __asm__("__wcstombs_chk");
# 145 "/usr/include/bits/stdlib.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) size_t wcstombs(char *__restrict__ __dst, const wchar_t *__restrict__ __src, size_t __len) throw()

{
if (__builtin_object_size(__dst, 2 > 1) != ((size_t)(-1)))
{
if (!(__builtin_constant_p(__len))) {
return __wcstombs_chk(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1)); }
if (__len > __builtin_object_size(__dst, 2 > 1)) {
return __wcstombs_chk_warn(__dst, __src, __len, __builtin_object_size(__dst, 2 > 1)); }
}
return __wcstombs_alias(__dst, __src, __len);
} }
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
# 434 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }

extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 448 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 473 "/usr/local/cuda/bin/../include/math_functions.h"
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
# 560 "/usr/local/cuda/bin/../include/math_functions.h"
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
# 98 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaSetupArgument(T
arg, size_t
offset)

{
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
}
# 120 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 174 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolAddress(void **
devPtr, const T &
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
}
# 267 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol)

{
return cudaGetSymbolSize(size, (const char *)symbol);
}
# 296 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolSize(size_t *
size, const T &
symbol)

{
return cudaGetSymbolSize(size, (const char *)(&symbol));
}
# 352 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 396 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
}
# 451 "/usr/local/cuda/bin/../include/cuda_runtime.h"
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
# 493 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc)

{
return cudaBindTextureToArray(&tex, array, (&desc));
}
# 530 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array)

{
auto cudaChannelFormatDesc desc;
auto cudaError_t err = cudaGetChannelDesc(&desc, array);

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
}
# 568 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaUnbindTexture(const texture< T, dim, readMode> &
tex)

{
return cudaUnbindTexture(&tex);
}
# 607 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode> &
tex)

{
return cudaGetTextureAlignmentOffset(offset, &tex);
}
# 649 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaLaunch(T *
entry)

{
return cudaLaunch((const char *)entry);
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
extern "C" { extern inline int fprintf(FILE *__restrict__, const char *__restrict__, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 337 "/usr/include/stdio.h" 3
extern "C" { extern inline int printf(const char *__restrict__, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }

extern "C" { extern inline int sprintf(char *__restrict__, const char *__restrict__, ...) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 346 "/usr/include/stdio.h" 3
extern "C" { extern inline int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 352 "/usr/include/stdio.h" 3
extern "C" { extern inline int vprintf(const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }

extern "C" { extern inline int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 361 "/usr/include/stdio.h" 3
extern "C" { extern inline int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }



extern "C" { extern inline int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 374 "/usr/include/stdio.h" 3
extern "C" { extern inline int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int __asprintf(char **__restrict__, const char *__restrict__, ...) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int asprintf(char **__restrict__, const char *__restrict__, ...) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 390 "/usr/include/stdio.h" 3
extern "C" { extern inline int vdprintf(int, const char *__restrict__, __gnuc_va_list) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int dprintf(int, const char *__restrict__, ...) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
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
extern "C" { extern inline int getchar() __attribute__((__gnu_inline__)); }
# 528 "/usr/include/stdio.h" 3
extern "C" { extern inline int getc_unlocked(FILE *) __attribute__((__gnu_inline__)); }
extern "C" { extern inline int getchar_unlocked() __attribute__((__gnu_inline__)); }
# 539 "/usr/include/stdio.h" 3
extern "C" { extern inline int fgetc_unlocked(FILE *) __attribute__((__gnu_inline__)); }
# 551 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
extern "C" int putc(int, FILE *);
# 558 "/usr/include/stdio.h" 3
extern "C" { extern inline int putchar(int) __attribute__((__gnu_inline__)); }
# 572 "/usr/include/stdio.h" 3
extern "C" { extern inline int fputc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); }
# 580 "/usr/include/stdio.h" 3
extern "C" { extern inline int putc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); }
extern "C" { extern inline int putchar_unlocked(int) __attribute__((__gnu_inline__)); }
# 588 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);


extern "C" int putw(int, FILE *);
# 600 "/usr/include/stdio.h" 3
extern "C" { extern inline char *fgets(char *__restrict__, int, FILE *__restrict__) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 608 "/usr/include/stdio.h" 3
extern "C" { extern inline char *gets(char *) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 618 "/usr/include/stdio.h" 3
extern "C" { extern inline char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 634 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);


extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 647 "/usr/include/stdio.h" 3
extern "C" { extern inline __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__) __attribute__((__gnu_inline__)); }
# 658 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 664 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 671 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 678 "/usr/include/stdio.h" 3
extern "C" { extern inline size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 684 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 695 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 706 "/usr/include/stdio.h" 3
extern "C" { extern inline size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__) __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }

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
extern "C" { extern inline int feof_unlocked(FILE *) throw() __attribute__((__gnu_inline__)); }
extern "C" { extern inline int ferror_unlocked(FILE *) throw() __attribute__((__gnu_inline__)); }
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


extern "C" { extern inline int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw() __attribute__((__always_inline__)) __attribute__((__gnu_inline__)); }
# 882 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();



extern "C" int ftrylockfile(FILE *) throw();


extern "C" void funlockfile(FILE *) throw();
# 45 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int getchar()
{
return _IO_getc(stdin);
} }
# 54 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int fgetc_unlocked(FILE *__fp)
{
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
} }
# 64 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int getc_unlocked(FILE *__fp)
{
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
} }



extern "C" { inline __attribute__((__gnu_inline__)) int getchar_unlocked()
{
return (__builtin_expect((stdin->_IO_read_ptr) >= (stdin->_IO_read_end), 0)) ? __uflow(stdin) : (*((unsigned char *)((stdin->_IO_read_ptr)++)));
} }
# 80 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int putchar(int __c)
{
return _IO_putc(__c, stdout);
} }
# 89 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int fputc_unlocked(int __c, FILE *__stream)
{
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
} }
# 99 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int putc_unlocked(int __c, FILE *__stream)
{
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
} }



extern "C" { inline __attribute__((__gnu_inline__)) int putchar_unlocked(int __c)
{
return (__builtin_expect((stdout->_IO_write_ptr) >= (stdout->_IO_write_end), 0)) ? __overflow(stdout, (unsigned char)__c) : ((unsigned char)((*((stdout->_IO_write_ptr)++)) = __c));
} }
# 116 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream)
{
return __getdelim(__lineptr, __n, '\n', __stream);
} }
# 126 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int feof_unlocked(FILE *__stream) throw()
{
return ((__stream->_flags) & 16) != 0;
} }



extern "C" { inline __attribute__((__gnu_inline__)) int ferror_unlocked(FILE *__stream) throw()
{
return ((__stream->_flags) & 32) != 0;
} }
# 24 "/usr/include/bits/stdio2.h" 3
extern "C" int __sprintf_chk(char *__restrict__, int, size_t, const char *__restrict__, ...) throw();

extern "C" int __vsprintf_chk(char *__restrict__, int, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 32 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int sprintf(char *__restrict__ __s, const char *__restrict__ __fmt, ...) throw()
{
return __builtin___sprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __builtin_va_arg_pack());

} }
# 44 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vsprintf(char *__restrict__ __s, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()

{
return __builtin___vsprintf_chk(__s, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);

} }



extern "C" int __snprintf_chk(char *__restrict__, size_t, int, size_t, const char *__restrict__, ...) throw();


extern "C" int __vsnprintf_chk(char *__restrict__, size_t, int, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 62 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int snprintf(char *__restrict__ __s, size_t __n, const char *__restrict__ __fmt, ...) throw()

{
return __builtin___snprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __builtin_va_arg_pack());

} }
# 75 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vsnprintf(char *__restrict__ __s, size_t __n, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()

{
return __builtin___vsnprintf_chk(__s, __n, 2 - 1, __builtin_object_size(__s, 2 > 1), __fmt, __ap);

} }
# 86 "/usr/include/bits/stdio2.h" 3
extern "C" int __fprintf_chk(FILE *__restrict__, int, const char *__restrict__, ...);

extern "C" int __printf_chk(int, const char *__restrict__, ...);
extern "C" int __vfprintf_chk(FILE *__restrict__, int, const char *__restrict__, __gnuc_va_list);

extern "C" int __vprintf_chk(int, const char *__restrict__, __gnuc_va_list);




extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int fprintf(FILE *__restrict__ __stream, const char *__restrict__ __fmt, ...)
{
return __fprintf_chk(__stream, 2 - 1, __fmt, __builtin_va_arg_pack());

} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int printf(const char *__restrict__ __fmt, ...)
{
return __printf_chk(2 - 1, __fmt, __builtin_va_arg_pack());
} }
# 115 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vprintf(const char *__restrict__ __fmt, __gnuc_va_list __ap)
{

return __vfprintf_chk(stdout, 2 - 1, __fmt, __ap);



} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vfprintf(FILE *__restrict__ __stream, const char *__restrict__
__fmt, __gnuc_va_list __ap)
{
return __vfprintf_chk(__stream, 2 - 1, __fmt, __ap);
} }



extern "C" int __asprintf_chk(char **__restrict__, int, const char *__restrict__, ...) throw();


extern "C" int __vasprintf_chk(char **__restrict__, int, const char *__restrict__, __gnuc_va_list) throw();


extern "C" int __dprintf_chk(int, int, const char *__restrict__, ...);

extern "C" int __vdprintf_chk(int, int, const char *__restrict__, __gnuc_va_list);


extern "C" int __obstack_printf_chk(obstack *__restrict__, int, const char *__restrict__, ...) throw();



extern "C" int __obstack_vprintf_chk(obstack *__restrict__, int, const char *__restrict__, __gnuc_va_list) throw();
# 156 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int asprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, ...) throw()
{
return __asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());

} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int __asprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, ...) throw()

{
return __asprintf_chk(__ptr, 2 - 1, __fmt, __builtin_va_arg_pack());

} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int dprintf(int __fd, const char *__restrict__ __fmt, ...)
{
return __dprintf_chk(__fd, 2 - 1, __fmt, __builtin_va_arg_pack());

} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int obstack_printf(obstack *__restrict__ __obstack, const char *__restrict__ __fmt, ...) throw()

{
return __obstack_printf_chk(__obstack, 2 - 1, __fmt, __builtin_va_arg_pack());

} }
# 196 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vasprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()

{
return __vasprintf_chk(__ptr, 2 - 1, __fmt, __ap);
} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int vdprintf(int __fd, const char *__restrict__ __fmt, __gnuc_va_list __ap)
{
return __vdprintf_chk(__fd, 2 - 1, __fmt, __ap);
} }


extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) int obstack_vprintf(obstack *__restrict__ __obstack, const char *__restrict__ __fmt, __gnuc_va_list __ap) throw()

{
return __obstack_vprintf_chk(__obstack, 2 - 1, __fmt, __ap);

} }
# 220 "/usr/include/bits/stdio2.h" 3
extern "C" char *__gets_chk(char *, size_t);
extern "C" char *__gets_warn(char *) __asm__("gets");




extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *gets(char *__str)
{
if (__builtin_object_size(__str, 2 > 1) != ((size_t)(-1))) {
return __gets_chk(__str, __builtin_object_size(__str, 2 > 1)); }
return __gets_warn(__str);
} }

extern "C" char *__fgets_chk(char *__restrict__, size_t, int, FILE *__restrict__);

extern "C" char *__fgets_alias(char *__restrict__, int, FILE *__restrict__) __asm__("fgets");


extern "C" char *__fgets_chk_warn(char *__restrict__, size_t, int, FILE *__restrict__) __asm__("__fgets_chk");
# 245 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *fgets(char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
{
if (__builtin_object_size(__s, 2 > 1) != ((size_t)(-1)))
{
if ((!(__builtin_constant_p(__n))) || (__n <= 0)) {
return __fgets_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }

if (((unsigned long)__n) > __builtin_object_size(__s, 2 > 1)) {
return __fgets_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
}
return __fgets_alias(__s, __n, __stream);
} }

extern "C" size_t __fread_chk(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__);


extern "C" size_t __fread_alias(void *__restrict__, size_t, size_t, FILE *__restrict__) __asm__("fread");



extern "C" size_t __fread_chk_warn(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__) __asm__("__fread_chk");
# 274 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) size_t fread(void *__restrict__ __ptr, size_t __size, size_t __n, FILE *__restrict__
__stream)
{
if (__builtin_object_size(__ptr, 0) != ((size_t)(-1)))
{
if (((!(__builtin_constant_p(__size))) || (!(__builtin_constant_p(__n)))) || ((__size | __n) >= (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) {


return __fread_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }

if ((__size * __n) > __builtin_object_size(__ptr, 0)) {
return __fread_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }
}
return __fread_alias(__ptr, __size, __n, __stream);
} }


extern "C" char *__fgets_unlocked_chk(char *__restrict__, size_t, int, FILE *__restrict__);

extern "C" char *__fgets_unlocked_alias(char *__restrict__, int, FILE *__restrict__) __asm__("fgets_unlocked");


extern "C" char *__fgets_unlocked_chk_warn(char *__restrict__, size_t, int, FILE *__restrict__) __asm__("__fgets_unlocked_chk");
# 303 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) char *fgets_unlocked(char *__restrict__ __s, int __n, FILE *__restrict__ __stream)
{
if (__builtin_object_size(__s, 2 > 1) != ((size_t)(-1)))
{
if ((!(__builtin_constant_p(__n))) || (__n <= 0)) {
return __fgets_unlocked_chk(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }

if (((unsigned long)__n) > __builtin_object_size(__s, 2 > 1)) {
return __fgets_unlocked_chk_warn(__s, __builtin_object_size(__s, 2 > 1), __n, __stream); }
}
return __fgets_unlocked_alias(__s, __n, __stream);
} }




extern "C" size_t __fread_unlocked_chk(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__);


extern "C" size_t __fread_unlocked_alias(void *__restrict__, size_t, size_t, FILE *__restrict__) __asm__("fread_unlocked");



extern "C" size_t __fread_unlocked_chk_warn(void *__restrict__, size_t, size_t, size_t, FILE *__restrict__) __asm__("__fread_unlocked_chk");
# 335 "/usr/include/bits/stdio2.h" 3
extern "C" { inline __attribute__((__always_inline__)) __attribute__((__gnu_inline__)) size_t fread_unlocked(void *__restrict__ __ptr, size_t __size, size_t __n, FILE *__restrict__
__stream)
{
if (__builtin_object_size(__ptr, 0) != ((size_t)(-1)))
{
if (((!(__builtin_constant_p(__size))) || (!(__builtin_constant_p(__n)))) || ((__size | __n) >= (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) {


return __fread_unlocked_chk(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }


if ((__size * __n) > __builtin_object_size(__ptr, 0)) {
return __fread_unlocked_chk_warn(__ptr, __builtin_object_size(__ptr, 0), __size, __n, __stream); }

}


if ((((__builtin_constant_p(__size)) && (__builtin_constant_p(__n))) && ((__size | __n) < (((size_t)1) << (((8) * sizeof(size_t)) / (2))))) && ((__size * __n) <= (8)))



{
auto size_t __cnt = (__size * __n);
auto char *__cptr = ((char *)__ptr);
if (__cnt == (0)) {
return 0; }

for (; __cnt > (0); --__cnt)
{
auto int __c = ((__builtin_expect((__stream->_IO_read_ptr) >= (__stream->_IO_read_end), 0)) ? __uflow(__stream) : (*((unsigned char *)((__stream->_IO_read_ptr)++))));
if (__c == (-1)) {
break; }
(*(__cptr++)) = __c;
}
return (__cptr - (char *)__ptr) / __size;
}

return __fread_unlocked_alias(__ptr, __size, __n, __stream);
} }
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
# 90 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 82 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
CU_CTX_SCHED_AUTO,
CU_CTX_SCHED_SPIN,
CU_CTX_SCHED_YIELD,
CU_CTX_SCHED_MASK,
CU_CTX_BLOCKING_SYNC,
CU_CTX_MAP_HOST = 8,
CU_CTX_FLAGS_MASK = 15
} CUctx_flags; }
# 98 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 95 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
CU_EVENT_DEFAULT,
CU_EVENT_BLOCKING_SYNC
} CUevent_flags; }
# 112 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 103 "/usr/local/cuda/bin/../include/cuda.h"
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
# 121 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 117 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
CU_TR_ADDRESS_MODE_WRAP,
CU_TR_ADDRESS_MODE_CLAMP,
CU_TR_ADDRESS_MODE_MIRROR
} CUaddress_mode; }
# 129 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 126 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
CU_TR_FILTER_MODE_POINT,
CU_TR_FILTER_MODE_LINEAR
} CUfilter_mode; }
# 158 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 134 "/usr/local/cuda/bin/../include/cuda.h"
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
# 174 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 163 "/usr/local/cuda/bin/../include/cuda.h"
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
# 211 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 179 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 185 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 192 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 198 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_NUM_REGS,

CU_FUNC_ATTRIBUTE_MAX
} CUfunction_attribute; }
# 220 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 216 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
CU_MEMORYTYPE_HOST = 1,
CU_MEMORYTYPE_DEVICE,
CU_MEMORYTYPE_ARRAY
} CUmemorytype; }
# 229 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 225 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
CU_COMPUTEMODE_DEFAULT,
CU_COMPUTEMODE_EXCLUSIVE,
CU_COMPUTEMODE_PROHIBITED
} CUcomputemode; }
# 308 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 234 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {




CU_JIT_MAX_REGISTERS,
# 251 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 257 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 263 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 270 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 276 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 283 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 289 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 295 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,




CU_JIT_TARGET,
# 306 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY

} CUjit_option; }
# 319 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 313 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {

CU_TARGET_COMPUTE_10,
CU_TARGET_COMPUTE_11,
CU_TARGET_COMPUTE_12,
CU_TARGET_COMPUTE_13
} CUjit_target; }
# 332 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 324 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {


CU_PREFER_PTX,


CU_PREFER_BINARY

} CUjit_fallback; }
# 380 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 343 "/usr/local/cuda/bin/../include/cuda.h"
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
# 426 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 406 "/usr/local/cuda/bin/../include/cuda.h"
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
# 460 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 431 "/usr/local/cuda/bin/../include/cuda.h"
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
# 473 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 466 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR {
unsigned Width;
unsigned Height;

CUarray_format Format;

unsigned NumChannels;
} CUDA_ARRAY_DESCRIPTOR; }
# 489 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 479 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR {
unsigned Width;
unsigned Height;
unsigned Depth;

CUarray_format Format;

unsigned NumChannels;

unsigned Flags;
} CUDA_ARRAY3D_DESCRIPTOR; }
# 528 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);




extern "C" CUresult cuDriverGetVersion(int *);
# 541 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
extern "C" CUresult cuDeviceGetCount(int *);
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 555 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
extern "C" CUresult cuCtxDestroy(CUcontext);
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
extern "C" CUresult cuCtxDetach(CUcontext);
extern "C" CUresult cuCtxPushCurrent(CUcontext);
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
extern "C" CUresult cuCtxGetDevice(CUdevice *);
extern "C" CUresult cuCtxSynchronize();
# 571 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
extern "C" CUresult cuModuleUnload(CUmodule);
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 586 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);

extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 597 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);

extern "C" CUresult cuMemAllocHost(void **, unsigned);
extern "C" CUresult cuMemFreeHost(void *);

extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);

extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 618 "/usr/local/cuda/bin/../include/cuda.h"
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
# 657 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);



extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);



extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);


extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 679 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);

extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 694 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 704 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
extern "C" CUresult cuArrayDestroy(CUarray);

extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 717 "/usr/local/cuda/bin/../include/cuda.h"
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
# 741 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
extern "C" CUresult cuParamSetf(CUfunction, int, float);
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 753 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 762 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
extern "C" CUresult cuEventRecord(CUevent, CUstream);
extern "C" CUresult cuEventQuery(CUevent);
extern "C" CUresult cuEventSynchronize(CUevent);
extern "C" CUresult cuEventDestroy(CUevent);
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 774 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
extern "C" CUresult cuStreamQuery(CUstream);
extern "C" CUresult cuStreamSynchronize(CUstream);
extern "C" CUresult cuStreamDestroy(CUstream);
# 64 "../../sdk/cutil.h"
enum CUTBoolean {

CUTFalse,
CUTTrue
};
# 76 "../../sdk/cutil.h"
extern "C" void cutFree(void *);
# 94 "../../sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 107 "../../sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 122 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 138 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 154 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 169 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 185 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 201 "../../sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 215 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 229 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 241 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 253 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 265 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 277 "../../sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 293 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 306 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 320 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 336 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 352 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 367 "../../sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 379 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 391 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 404 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 416 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 428 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 440 "../../sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 461 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 475 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 489 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 503 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 518 "../../sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 532 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 544 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 557 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 584 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 599 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 613 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 627 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 642 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 657 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 672 "../../sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 685 "../../sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 694 "../../sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 702 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 710 "../../sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 718 "../../sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 727 "../../sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 738 "../../sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 19 "../../sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
bdimx, unsigned bdimy, unsigned bdimz, char *
aname, int index, char *file, int line)
{
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
}
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
# 69 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 59 "/usr/local/cuda/bin/../include/cufft.h"
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




extern "C" { typedef cuComplex cufftComplex; }
# 93 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 89 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftType_t {
CUFFT_R2C = 42,
CUFFT_C2R = 44,
CUFFT_C2C = 41
} cufftType; }

extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);




extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);



extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);



extern "C" cufftResult cufftDestroy(cufftHandle);

extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);




extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);



extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 22 "../../sdk/cutil_inline_runtime.h"
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

inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
{
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
}

inline void __cudaSafeCall(cudaError err, const char *file, const int line)
{
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
}

inline void __cudaSafeThreadSync(const char *file, const int line)
{
auto cudaError err = cudaThreadSynchronize();
if ((cudaSuccess) != err) {
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));

exit(-1);
}
}

inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
{
if ((CUFFT_SUCCESS) != err) {
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);

exit(-1);
}
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
auto cudaError_t err = cudaGetLastError();
if ((cudaSuccess) != err) {
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));

exit(-1);
}
# 132 "../../sdk/cutil_inline_runtime.h"
}
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
{
if (!(pointer)) {
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);

exit(-1);
}
}


inline void cutilDeviceInit(int ARGC, char **ARGV) { }
# 171 "../../sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
{
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
}
# 16 "../../sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
{
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);

exit(-1);
}
}
inline void __cuSafeCall(CUresult err, const char *file, const int line)
{
__cuSafeCallNoSync(err, file, line);
}

inline void __cuCtxSync(const char *file, const int line)
{
auto CUresult err = cuCtxSynchronize();
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);

exit(-1);
}
}

inline void __cuCheckMsg(const char *msg, const char *file, const int line)
{
auto CUresult err = cuCtxSynchronize();
if ((CUDA_SUCCESS) != err) {
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);

exit(-1);
}
}



inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV) { }
# 78 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
{
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
}
# 12 "../../sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
{
printf("CUDA %d.%02d Toolkit built this project.\n", 2020 / 1000, 2020 % 100);
printf("  [ %s ] requirements:\n", sSDKsample);
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
}
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
# 39 "bicubicTexture.cu"
extern "C" { typedef unsigned uint; }
typedef unsigned char uchar;
# 43 "./bicubicTexture_kernel.cuh"
enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC};

static texture< unsigned char, 2, cudaReadModeNormalizedFloat> tex;



float w0(float a)
{

return ((1.0F) / (6.0F)) * (a * (a * (-a + (3.0F)) - (3.0F)) + (1.0F));
}


float w1(float a)
{

return ((1.0F) / (6.0F)) * ((a * a) * ((3.0F) * a - (6.0F)) + (4.0F));
}


float w2(float a)
{

return ((1.0F) / (6.0F)) * (a * (a * ((-(3.0F)) * a + (3.0F)) + (3.0F)) + (1.0F));
}


float w3(float a)
{
return ((1.0F) / (6.0F)) * ((a * a) * a);
}
# 161 "./bicubicTexture_kernel.cuh"
void d_render__entry(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy);
# 179 "./bicubicTexture_kernel.cuh"
void d_renderBicubic__entry(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy);
# 197 "./bicubicTexture_kernel.cuh"
void d_renderFastBicubic__entry(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy);
# 44 "bicubicTexture.cu"
cudaArray *d_imageArray = (0);


extern "C" void initTexture(int imageWidth, int imageHeight, uchar *h_data)
{

auto cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
__cudaSafeCall(cudaMallocArray(&d_imageArray, &channelDesc, imageWidth, imageHeight), "bicubicTexture.cu", 51);
auto uint size = ((imageWidth * imageHeight) * sizeof(uchar));
__cudaSafeCall(cudaMemcpyToArray(d_imageArray, 0, 0, h_data, size, cudaMemcpyHostToDevice), "bicubicTexture.cu", 53);
cutFree(h_data);


((tex.addressMode)[0]) = cudaAddressModeClamp;
((tex.addressMode)[1]) = cudaAddressModeClamp;
(tex.filterMode) = cudaFilterModeLinear;
(tex.normalized) = (false);


__cudaSafeCall(cudaBindTextureToArray(tex, d_imageArray, channelDesc), "bicubicTexture.cu", 63);
}


extern "C" void freeTexture()
{
__cudaSafeCall(cudaFreeArray(d_imageArray), "bicubicTexture.cu", 69);
}




extern "C" void render(int width, int height, float tx, float ty, float scale, float cx, float cy, dim3
blockSize, dim3 gridSize, int mode, uchar4 *output)
{

switch (mode) {
case MODE_NEAREST:
(tex.filterMode) = cudaFilterModePoint;
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_render__entry(output, width, height, tx, ty, scale, cx, cy);
break;
case MODE_BILINEAR:
(tex.filterMode) = cudaFilterModeLinear;
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_render__entry(output, width, height, tx, ty, scale, cx, cy);
break;
case MODE_BICUBIC:
(tex.filterMode) = cudaFilterModePoint;
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_renderBicubic__entry(output, width, height, tx, ty, scale, cx, cy);
break;
case MODE_FAST_BICUBIC:
(tex.filterMode) = cudaFilterModeLinear;
cudaConfigureCall(gridSize, blockSize) ? ((void)0) : d_renderFastBicubic__entry(output, width, height, tx, ty, scale, cx, cy);
break;
}
__cutilCheckMsg("kernel failed", "bicubicTexture.cu", 97);
}

# 1 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_00004c55_00000000-3_bicubicTexture.fatbin.c" 1
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
typedef struct {
    char* gpuProfileName;
    char* debug;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 144 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 158 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
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
# 194 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 217 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 228 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_00004c55_00000000-3_bicubicTexture.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$compute_10$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x616d202c30315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x61636f6c2f727375ull,0x6f2f616475632f6cull,0x696c2f34366e6570ull,0x2f090a65622f2f62ull,
0x6e65706f766e202full,0x746c697562206363ull,0x39303032206e6f20ull,0x0a0a39302d34302dull,
0x752e206765722e09ull,0x313c617225203233ull,0x65722e090a3b3e37ull,0x25203436752e2067ull,
0x3b3e37313c616472ull,0x2e206765722e090aull,0x3c61662520323366ull,0x722e090a3b3e3731ull,
0x203436662e206765ull,0x3e37313c61646625ull,0x206765722e090a3bull,0x767225203233752eull,
0x722e090a3b3e353cull,0x203436752e206765ull,0x3b3e353c76647225ull,0x2e206765722e090aull,
0x3c76662520323366ull,0x65722e090a3b3e35ull,0x25203436662e2067ull,0x0a3b3e353c766466ull,
0x2d2d2d2f2f090a0aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x6d6f43202f2f090aull,0x2f20676e696c6970ull,0x78706d742f706d74ull,0x34303030305f7466ull,
0x303030305f353563ull,0x625f372d30303030ull,0x6554636962756369ull,0x70632e6572757478ull,
0x742f2820692e3370ull,0x23494263632f706dull,0x29436164516b462eull,0x2d2d2d2d2f2f090aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x2d2d2d2d2f2f090aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x6974704f202f2f09ull,
0x2f2f090a3a736e6full,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x202f2f090a2d2d2dull,0x3a74656772615420ull,0x415349202c787470ull,0x202c30315f6d733aull,
0x6c3a6e6169646e45ull,0x50202c656c747469ull,0x53207265746e696full,0x090a34363a657a69ull,
0x09334f2d20202f2full,0x7a696d6974704f28ull,0x656c206e6f697461ull,0x2f2f090a296c6576ull,
0x44280930672d2020ull,0x76656c2067756265ull,0x202f2f090a296c65ull,0x65522809326d2d20ull,
0x7664612074726f70ull,0x29736569726f7369ull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x09656c69662e090aull,0x6d6d6f633c220931ull,
0x656e696c2d646e61ull,0x6c69662e090a223eull,0x6d742f2209320965ull,0x746678706d742f70ull,
0x356334303030305full,0x3030303030305f35ull,0x6369625f362d3030ull,0x7478655463696275ull,
0x616475632e657275ull,0x227570672e326566ull,0x09656c69662e090aull,0x2f7273752f220933ull,
0x2f6363672f62696cull,0x6c2d34365f363878ull,0x756e672d78756e69ull,0x692f332e332e342full,
0x732f6564756c636eull,0x22682e6665646474ull,0x09656c69662e090aull,0x2f7273752f220934ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x65642f7472632f65ull,
0x6e75725f65636976ull,0x0a22682e656d6974ull,0x3509656c69662e09ull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x65645f74736f682full,
0x22682e73656e6966ull,0x09656c69662e090aull,0x2f7273752f220936ull,0x75632f6c61636f6cull,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x69746c6975622f65ull,0x2e73657079745f6eull,
0x6c69662e090a2268ull,0x73752f2209370965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x697665642f656475ull,0x73657079745f6563ull,0x69662e090a22682eull,
0x752f22093809656cull,0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x6972642f6564756cull,0x657079745f726576ull,0x662e090a22682e73ull,0x2f22093909656c69ull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65742f6564756c63ull,
0x79745f6572757478ull,0x090a22682e736570ull,0x303109656c69662eull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f726f746365762full,
0x22682e7365707974ull,0x09656c69662e090aull,0x7273752f22093131ull,0x632f6c61636f6c2full,
0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x63697665642f6564ull,0x68636e75616c5f65ull,
0x74656d617261705full,0x090a22682e737265ull,0x323109656c69662eull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x6f74732f7472632full,
0x616c635f65676172ull,0x2e090a22682e7373ull,0x09333109656c6966ull,0x6e692f7273752f22ull,
0x69622f6564756c63ull,0x73657079742f7374ull,0x69662e090a22682eull,0x2f2209343109656cull,
0x6c636e692f727375ull,0x656d69742f656475ull,0x69662e090a22682eull,0x622209353109656cull,
0x6554636962756369ull,0x656b5f6572757478ull,0x6875632e6c656e72ull,0x656c69662e090a22ull,
0x73752f2209363109ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6d6d6f632f656475ull,0x74636e75665f6e6full,0x0a22682e736e6f69ull,0x3109656c69662e09ull,
0x2f7273752f220937ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x75662f7472632f65ull,0x6f7263616d5f636eull,0x69662e090a22682eull,0x2f2209383109656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,
0x74636e75665f6874ull,0x0a22682e736e6f69ull,0x3109656c69662e09ull,0x2f7273752f220939ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6563697665642f65ull,
0x6f6974636e75665full,0x2e090a22682e736eull,0x09303209656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x6e6f635f6874616dull,
0x682e73746e617473ull,0x656c69662e090a22ull,0x73752f2209313209ull,0x2f6c61636f6c2f72ull,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x63696d6f74615f31ull,
0x6f6974636e75665full,0x2e090a22682e736eull,0x09323209656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x74615f32315f6d73ull,
0x6e75665f63696d6full,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209333209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,
0x656c62756f645f33ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09343209656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x745f6e6f6d6d6f63ull,0x0a22682e73657079ull,0x3209656c69662e09ull,0x2f7273752f220935ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x7275747865742f65ull,
0x5f68637465665f65ull,0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209363209656c69ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x6d2f6564756c636eull,
0x636e75665f687461ull,0x62645f736e6f6974ull,0x682e317874705f6cull,0x7865742e090a0a22ull,
0x6574203436752e20ull,0x6e652e090a0a3b78ull,0x64385a5f20797274ull,0x507265646e65725full,
0x6a34726168637536ull,0x282066666666666aull,0x617261702e09090aull,0x5f203436752e206dull,
0x726170616475635full,0x725f64385a5f5f6dull,0x7536507265646e65ull,0x666a6a3472616863ull,
0x6f5f645f66666666ull,0x090a2c7475707475ull,0x206d617261702e09ull,0x635f5f203233752eull,
0x5f6d726170616475ull,0x6e65725f64385a5full,0x6863753650726564ull,0x6666666a6a347261ull,
0x68746469775f6666ull,0x7261702e09090a2cull,0x203233752e206d61ull,0x6170616475635f5full,
0x5f64385a5f5f6d72ull,0x36507265646e6572ull,0x6a6a347261686375ull,0x65685f6666666666ull,
0x09090a2c74686769ull,0x2e206d617261702eull,0x75635f5f20323366ull,0x5f5f6d7261706164ull,
0x646e65725f64385aull,0x6168637536507265ull,0x666666666a6a3472ull,0x09090a2c78745f66ull,
0x2e206d617261702eull,0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x646e65725f64385aull,
0x6168637536507265ull,0x666666666a6a3472ull,0x09090a2c79745f66ull,0x2e206d617261702eull,
0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,
0x666666666a6a3472ull,0x2c656c6163735f66ull,0x617261702e09090aull,0x5f203233662e206dull,
0x726170616475635full,0x725f64385a5f5f6dull,0x7536507265646e65ull,0x666a6a3472616863ull,
0x2c78635f66666666ull,0x617261702e09090aull,0x5f203233662e206dull,0x726170616475635full,
0x725f64385a5f5f6dull,0x7536507265646e65ull,0x666a6a3472616863ull,0x2979635f66666666ull,
0x65722e090a7b090aull,0x25203233752e2067ull,0x090a3b3e30333c72ull,0x36752e206765722eull,
0x3e363c6472252034ull,0x206765722e090a3bull,0x3c6625203233662eull,0x722e090a3b3e3032ull,
0x646572702e206765ull,0x0a3b3e333c702520ull,0x353109636f6c2e09ull,0x240a300931363109ull,
0x385a5f5f3142424cull,0x7265646e65725f64ull,0x3472616863753650ull,0x3a66666666666a6aull,
0x33752e747663090aull,0x2509203631752e32ull,0x61746325202c3172ull,0x2020203b782e6469ull,
0x7663090a202f2f09ull,0x31752e3233752e74ull,0x202c327225092036ull,0x3b782e6469746e25ull,
0x202f2f0920202020ull,0x2e34326c756d090aull,0x09203233752e6f6cull,0x317225202c337225ull,
0x20203b327225202cull,0x7663090a202f2f09ull,0x31752e3233752e74ull,0x202c347225092036ull,
0x792e646961746325ull,0x202f2f092020203bull,0x33752e747663090aull,0x2509203631752e32ull,
0x69746e25202c3572ull,0x202020203b792e64ull,0x756d090a202f2f09ull,0x752e6f6c2e34326cull,
0x2c36722509203233ull,0x7225202c34722520ull,0x202f2f0920203b35ull,0x33752e747663090aull,
0x2509203631752e32ull,0x64697425202c3772ull,0x20202020203b782eull,0x6461090a202f2f09ull,
0x2509203233752e64ull,0x2c377225202c3872ull,0x2020203b33722520ull,0x202f2f0920202020ull,
0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3972ull,0x20202020203b792eull,
0x6461090a202f2f09ull,0x2509203233752e64ull,0x397225202c303172ull,0x20203b367225202cull,
0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233752e6d61ull,0x5f5b202c31317225ull,
0x726170616475635full,0x725f64385a5f5f6dull,0x7536507265646e65ull,0x666a6a3472616863ull,
0x6469775f66666666ull,0x202f2f093b5d6874ull,0x5f5f2031363a6469ull,0x6d72617061647563ull,
0x65725f64385a5f5full,0x637536507265646eull,0x66666a6a34726168ull,0x746469775f666666ull,
0x6c090a3078302b68ull,0x2e6d617261702e64ull,0x3172250920323375ull,0x75635f5f5b202c32ull,
0x5f5f6d7261706164ull,0x646e65725f64385aull,0x6168637536507265ull,0x666666666a6a3472ull,
0x7468676965685f66ull,0x6469202f2f093b5dull,0x75635f5f2038363aull,0x5f5f6d7261706164ull,
0x646e65725f64385aull,0x6168637536507265ull,0x666666666a6a3472ull,0x7468676965685f66ull,
0x6573090a3078302bull,0x3233752e74672e74ull,0x722509203233752eull,0x32317225202c3331ull,
0x093b30317225202cull,0x67656e090a202f2full,0x722509203233732eull,0x33317225202c3431ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x2e746c2e74657309ull,0x203233752e323375ull,
0x25202c3531722509ull,0x31317225202c3872ull,0x6e090a202f2f093bull,0x09203233732e6765ull,
0x7225202c36317225ull,0x20202020203b3531ull,0x2f2f092020202020ull,0x622e646e61090a20ull,
0x3731722509203233ull,0x202c34317225202cull,0x2020203b36317225ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x3b30202c38317225ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e7165ull,0x317225202c317025ull,0x3b38317225202c37ull,
0x40090a202f2f0920ull,0x2061726220317025ull,0x315f305f744c2409ull,0x202020203b323832ull,
0x2f2f092020202020ull,0x61702e646c090a20ull,0x203233662e6d6172ull,0x5f5b202c31662509ull,
0x726170616475635full,0x725f64385a5f5f6dull,0x7536507265646e65ull,0x666a6a3472616863ull,
0x5d79635f66666666ull,0x3a6469202f2f093bull,0x6475635f5f203835ull,0x5a5f5f6d72617061ull,
0x65646e65725f6438ull,0x7261686375365072ull,0x66666666666a6a34ull,0x0a3078302b79635full,
0x617261702e646c09ull,0x2509203233662e6dull,0x635f5f5b202c3266ull,0x5f6d726170616475ull,
0x6e65725f64385a5full,0x6863753650726564ull,0x6666666a6a347261ull,0x656c6163735f6666ull,
0x6469202f2f093b5dull,0x75635f5f2039353aull,0x5f5f6d7261706164ull,0x646e65725f64385aull,
0x6168637536507265ull,0x666666666a6a3472ull,0x2b656c6163735f66ull,0x2e646c090a307830ull,
0x33662e6d61726170ull,0x202c336625092032ull,0x70616475635f5f5bull,0x64385a5f5f6d7261ull,
0x507265646e65725full,0x6a34726168637536ull,0x635f66666666666aull,0x69202f2f093b5d78ull,
0x635f5f2030363a64ull,0x5f6d726170616475ull,0x6e65725f64385a5full,0x6863753650726564ull,
0x6666666a6a347261ull,0x78302b78635f6666ull,0x61702e646c090a30ull,0x203233662e6d6172ull,
0x5f5b202c34662509ull,0x726170616475635full,0x725f64385a5f5f6dull,0x7536507265646e65ull,
0x666a6a3472616863ull,0x5d78745f66666666ull,0x3a6469202f2f093bull,0x6475635f5f203037ull,
0x5a5f5f6d72617061ull,0x65646e65725f6438ull,0x7261686375365072ull,0x66666666666a6a34ull,
0x0a3078302b78745full,0x2e6e722e74766309ull,0x203233752e323366ull,0x7225202c35662509ull,
0x0920202020203b38ull,0x627573090a202f2full,0x662509203233662eull,0x202c356625202c36ull,
0x202020203b336625ull,0x0a202f2f09202020ull,0x3233662e64616d09ull,0x25202c3766250920ull,
0x2c366625202c3266ull,0x0920203b33662520ull,0x646461090a202f2full,0x662509203233662eull,
0x202c346625202c38ull,0x202020203b376625ull,0x0a202f2f09202020ull,0x617261702e646c09ull,
0x2509203233662e6dull,0x635f5f5b202c3966ull,0x5f6d726170616475ull,0x6e65725f64385a5full,
0x6863753650726564ull,0x6666666a6a347261ull,0x093b5d79745f6666ull,0x31373a6469202f2full,
0x70616475635f5f20ull,0x64385a5f5f6d7261ull,0x507265646e65725full,0x6a34726168637536ull,
0x745f66666666666aull,0x63090a3078302b79ull,0x33662e6e722e7476ull,0x2509203233752e32ull,
0x317225202c303166ull,0x2f2f092020203b30ull,0x662e627573090a20ull,0x3131662509203233ull,
0x202c30316625202cull,0x202020203b316625ull,0x6d090a202f2f0920ull,0x09203233662e6461ull,
0x6625202c32316625ull,0x2c31316625202c32ull,0x2f2f093b31662520ull,0x662e646461090a20ull,
0x3331662509203233ull,0x25202c396625202cull,0x202020203b323166ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x6630202c34316625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x2e766f6d090a3020ull,0x3166250920323366ull,0x3030306630202c35ull,0x20203b3030303030ull,
0x0a30202f2f092020ull,0x2e64322e78657409ull,0x662e3233752e3476ull,0x393172257b203233ull,
0x72252c303272252cull,0x7d323272252c3132ull,0x257b2c7865745b2cull,0x2c333166252c3866ull,
0x3166252c34316625ull,0x6c2e090a3b5d7d35ull,0x373109353109636full,0x766f6d090a300932ull,
0x722509203233732eull,0x39317225202c3332ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300933373109ull,0x203233622e766f6dull,0x25202c3631662509ull,
0x202020203b333272ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3166250920323366ull,
0x3733346630202c37ull,0x20203b3030303066ull,0x3532202f2f092020ull,0x662e6c756d090a35ull,
0x3831662509203233ull,0x202c36316625202cull,0x2020203b37316625ull,0x6d090a202f2f0920ull,
0x2e6f6c2e34326c75ull,0x3272250920323375ull,0x2c30317225202c34ull,0x2f093b3131722520ull,
0x2e747663090a202full,0x2e3233752e697a72ull,0x3272250920323366ull,0x3b38316625202c35ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x25202c3632722509ull,0x202020203b353272ull,
0x2f09202020202020ull,0x702e646c090a202full,0x3436752e6d617261ull,0x202c316472250920ull,
0x70616475635f5f5bull,0x64385a5f5f6d7261ull,0x507265646e65725full,0x6a34726168637536ull,
0x645f66666666666aull,0x5d74757074756f5full,0x3a6469202f2f093bull,0x6475635f5f203237ull,
0x5a5f5f6d72617061ull,0x65646e65725f6438ull,0x7261686375365072ull,0x66666666666a6a34ull,
0x757074756f5f645full,0x61090a3078302b74ull,0x09203233752e6464ull,0x7225202c37327225ull,
0x3b34327225202c38ull,0x2f2f092020202020ull,0x752e747663090a20ull,0x09203233752e3436ull,
0x7225202c32647225ull,0x20202020203b3732ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x2c33647225092034ull,0x34202c3264722520ull,0x2f2f09202020203bull,0x752e646461090a20ull,
0x3464722509203436ull,0x202c31647225202cull,0x2020203b33647225ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x3b30202c38327225ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x6c672e7473090a20ull,0x2e34762e6c61626full,0x6472255b09203875ull,0x257b202c5d302b34ull,
0x363272252c363272ull,0x72252c363272252cull,0x202f2f093b7d3832ull,0x315f305f744c240aull,
0x6c2e090a3a323832ull,0x373109353109636full,0x697865090a300935ull,0x2020202020203b74ull,
0x2020202020202020ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x5f646e6557444c24ull,
0x6e65725f64385a5full,0x6863753650726564ull,0x6666666a6a347261ull,0x2f207d090a3a6666ull,
0x725f64385a5f202full,0x7536507265646e65ull,0x666a6a3472616863ull,0x2e090a0a66666666ull,
0x5a5f207972746e65ull,0x646e65725f643531ull,0x6962756369427265ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x61702e09090a2820ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x35315a5f5f6d7261ull,0x7265646e65725f64ull,0x5063696275636942ull,0x6a34726168637536ull,
0x645f66666666666aull,0x2c74757074756f5full,0x617261702e09090aull,0x5f203233752e206dull,
0x726170616475635full,0x5f6435315a5f5f6dull,0x69427265646e6572ull,0x7536506369627563ull,
0x666a6a3472616863ull,0x6469775f66666666ull,0x702e09090a2c6874ull,0x33752e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x65646e65725f6435ull,0x6369627563694272ull,
0x3472616863753650ull,0x5f66666666666a6aull,0x0a2c746867696568ull,0x6d617261702e0909ull,
0x5f5f203233662e20ull,0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x0a2c78745f666666ull,0x6d617261702e0909ull,
0x5f5f203233662e20ull,0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x0a2c79745f666666ull,0x6d617261702e0909ull,
0x5f5f203233662e20ull,0x6d72617061647563ull,0x725f6435315a5f5full,0x6369427265646e65ull,
0x6375365063696275ull,0x66666a6a34726168ull,0x6c6163735f666666ull,0x61702e09090a2c65ull,
0x3233662e206d6172ull,0x70616475635f5f20ull,0x35315a5f5f6d7261ull,0x7265646e65725f64ull,
0x5063696275636942ull,0x6a34726168637536ull,0x635f66666666666aull,0x61702e09090a2c78ull,
0x3233662e206d6172ull,0x70616475635f5f20ull,0x35315a5f5f6d7261ull,0x7265646e65725f64ull,
0x5063696275636942ull,0x6a34726168637536ull,0x635f66666666666aull,0x2e090a7b090a2979ull,
0x3233752e20676572ull,0x3e3530313c722520ull,0x206765722e090a3bull,0x647225203436752eull,
0x722e090a3b3e363cull,0x203233662e206765ull,0x3b3e3339313c6625ull,0x2e206765722e090aull,
0x3c70252064657270ull,0x6f6c2e090a3b3e33ull,0x3937310935310963ull,0x3142424c240a3009ull,
0x725f6435315a5f5full,0x6369427265646e65ull,0x6375365063696275ull,0x66666a6a34726168ull,
0x7663090a3a666666ull,0x31752e3233752e74ull,0x202c317225092036ull,0x782e646961746325ull,
0x202f2f092020203bull,0x33752e747663090aull,0x2509203631752e32ull,0x69746e25202c3272ull,
0x202020203b782e64ull,0x756d090a202f2f09ull,0x752e6f6c2e34326cull,0x2c33722509203233ull,
0x7225202c31722520ull,0x202f2f0920203b32ull,0x33752e747663090aull,0x2509203631752e32ull,
0x61746325202c3472ull,0x2020203b792e6469ull,0x7663090a202f2f09ull,0x31752e3233752e74ull,
0x202c357225092036ull,0x3b792e6469746e25ull,0x202f2f0920202020ull,0x2e34326c756d090aull,
0x09203233752e6f6cull,0x347225202c367225ull,0x20203b357225202cull,0x7663090a202f2f09ull,
0x31752e3233752e74ull,0x202c377225092036ull,0x203b782e64697425ull,0x202f2f0920202020ull,
0x33752e646461090aull,0x202c387225092032ull,0x337225202c377225ull,0x202020202020203bull,
0x7663090a202f2f09ull,0x31752e3233752e74ull,0x202c397225092036ull,0x203b792e64697425ull,
0x202f2f0920202020ull,0x33752e646461090aull,0x2c30317225092032ull,0x7225202c39722520ull,
0x2020202020203b36ull,0x646c090a202f2f09ull,0x752e6d617261702eull,0x3131722509203233ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x646e65725f643531ull,0x6962756369427265ull,
0x7261686375365063ull,0x66666666666a6a34ull,0x3b5d68746469775full,0x333a6469202f2f09ull,
0x6475635f5f203130ull,0x5a5f5f6d72617061ull,0x646e65725f643531ull,0x6962756369427265ull,
0x7261686375365063ull,0x66666666666a6a34ull,0x302b68746469775full,0x702e646c090a3078ull,
0x3233752e6d617261ull,0x202c323172250920ull,0x70616475635f5f5bull,0x35315a5f5f6d7261ull,
0x7265646e65725f64ull,0x5063696275636942ull,0x6a34726168637536ull,0x685f66666666666aull,
0x093b5d7468676965ull,0x30333a6469202f2full,0x616475635f5f2038ull,0x315a5f5f6d726170ull,
0x65646e65725f6435ull,0x6369627563694272ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x302b746867696568ull,0x2e746573090a3078ull,0x752e3233752e7467ull,0x3331722509203233ull,
0x202c32317225202cull,0x2f2f093b30317225ull,0x732e67656e090a20ull,0x3431722509203233ull,
0x203b33317225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,0x33752e746c2e7465ull,
0x2509203233752e32ull,0x387225202c353172ull,0x093b31317225202cull,0x67656e090a202f2full,
0x722509203233732eull,0x35317225202c3631ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233622e646e6109ull,0x202c373172250920ull,0x7225202c34317225ull,0x09202020203b3631ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3831ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x2c37317225202c31ull,
0x09203b3831722520ull,0x702540090a202f2full,0x2409206172622031ull,0x3832315f315f744cull,
0x2020202020203b32ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939313109ull,
0x662e6e722e747663ull,0x09203233752e3233ull,0x387225202c316625ull,0x2f0920202020203bull,
0x2e747663090a202full,0x752e3233662e6e72ull,0x2c32662509203233ull,0x20203b3031722520ull,
0x090a202f2f092020ull,0x6d617261702e646cull,0x662509203233662eull,0x75635f5f5b202c33ull,
0x5f5f6d7261706164ull,0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x2f093b5d78635f66ull,0x3030333a6469202full,0x70616475635f5f20ull,
0x35315a5f5f6d7261ull,0x7265646e65725f64ull,0x5063696275636942ull,0x6a34726168637536ull,
0x635f66666666666aull,0x73090a3078302b78ull,0x09203233662e6275ull,0x316625202c346625ull,
0x20203b336625202cull,0x2f2f092020202020ull,0x61702e646c090a20ull,0x203233662e6d6172ull,
0x5f5b202c35662509ull,0x726170616475635full,0x5f6435315a5f5f6dull,0x69427265646e6572ull,
0x7536506369627563ull,0x666a6a3472616863ull,0x5d79635f66666666ull,0x3a6469202f2f093bull,
0x75635f5f20393932ull,0x5f5f6d7261706164ull,0x6e65725f6435315aull,0x6275636942726564ull,
0x6168637536506369ull,0x666666666a6a3472ull,0x3078302b79635f66ull,0x33662e627573090aull,
0x202c366625092032ull,0x356625202c326625ull,0x202020202020203bull,0x646c090a202f2f09ull,
0x662e6d617261702eull,0x2c37662509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x65646e65725f6435ull,0x6369627563694272ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x093b5d656c616373ull,0x39323a6469202f2full,0x616475635f5f2038ull,0x315a5f5f6d726170ull,
0x65646e65725f6435ull,0x6369627563694272ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x78302b656c616373ull,0x662e64616d090a30ull,0x2c38662509203233ull,0x6625202c37662520ull,
0x203b336625202c34ull,0x6d090a202f2f0920ull,0x09203233662e6461ull,0x376625202c396625ull,
0x25202c366625202cull,0x2f2f0920203b3566ull,0x61702e646c090a20ull,0x203233662e6d6172ull,
0x5b202c3031662509ull,0x6170616475635f5full,0x6435315a5f5f6d72ull,0x427265646e65725full,
0x3650636962756369ull,0x6a6a347261686375ull,0x78745f6666666666ull,0x6469202f2f093b5dull,
0x635f5f203930333aull,0x5f6d726170616475ull,0x65725f6435315a5full,0x756369427265646eull,
0x6863753650636962ull,0x6666666a6a347261ull,0x78302b78745f6666ull,0x662e646461090a30ull,
0x3131662509203233ull,0x202c30316625202cull,0x202020203b386625ull,0x6c090a202f2f0920ull,
0x2e6d617261702e64ull,0x3166250920323366ull,0x75635f5f5b202c32ull,0x5f5f6d7261706164ull,
0x6e65725f6435315aull,0x6275636942726564ull,0x6168637536506369ull,0x666666666a6a3472ull,
0x2f093b5d79745f66ull,0x3031333a6469202full,0x70616475635f5f20ull,0x35315a5f5f6d7261ull,
0x7265646e65725f64ull,0x5063696275636942ull,0x6a34726168637536ull,0x745f66666666666aull,
0x61090a3078302b79ull,0x09203233662e6464ull,0x6625202c33316625ull,0x3b396625202c3231ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3431662509203233ull,0x303066626630202cull,
0x2020203b30303030ull,0x2e302d202f2f0920ull,0x662e646461090a35ull,0x3531662509203233ull,
0x202c31316625202cull,0x2020203b34316625ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c36316625ull,0x3030303030306662ull,0x2f2f09202020203bull,0x61090a352e302d20ull,
0x09203233662e6464ull,0x6625202c37316625ull,0x36316625202c3331ull,0x2f2f09202020203bull,
0x722e747663090a20ull,0x662e3233662e696dull,0x3831662509203233ull,0x203b35316625202cull,
0x63090a202f2f0920ull,0x662e696d722e7476ull,0x09203233662e3233ull,0x6625202c39316625ull,
0x2f2f0920203b3731ull,0x662e766f6d090a20ull,0x3032662509203233ull,0x303866626630202cull,
0x2020203b30303030ull,0x0a312d202f2f0920ull,0x3233662e64646109ull,0x202c313266250920ull,
0x6625202c38316625ull,0x09202020203b3032ull,0x766f6d090a202f2full,0x662509203233662eull,
0x66626630202c3232ull,0x203b303030303038ull,0x2d202f2f09202020ull,0x662e646461090a31ull,
0x3332662509203233ull,0x202c39316625202cull,0x2020203b32326625ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x6625202c34326625ull,0x20202020203b3132ull,0x2f2f092020202020ull,
0x662e766f6d090a20ull,0x3532662509203233ull,0x203b33326625202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c36326625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3266250920323366ull,0x3030306630202c37ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x2e64322e78657409ull,0x662e3233752e3476ull,
0x393172257b203233ull,0x72252c303272252cull,0x7d323272252c3132ull,0x257b2c7865745b2cull,
0x353266252c343266ull,0x66252c363266252cull,0x2e090a3b5d7d3732ull,0x3109353109636f6cull,
0x6f6d090a30093332ull,0x2509203233732e76ull,0x317225202c333272ull,0x2020202020203b39ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c38326625092032ull,0x20203b3831662520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x326625202c393266ull,
0x2020202020203b33ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c30336625092032ull,
0x3030303030663020ull,0x202020203b303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,
0x6630202c31336625ull,0x3030303030303030ull,0x2f2f09202020203bull,0x2e786574090a3020ull,
0x33752e34762e6432ull,0x257b203233662e32ull,0x353272252c343272ull,0x72252c363272252cull,
0x7865745b2c7d3732ull,0x252c383266257b2cull,0x303366252c393266ull,0x3b5d7d313366252cull,
0x33732e766f6d090aull,0x2c38327225092032ull,0x20203b3432722520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x336630202c323366ull,0x3b30303030303866ull,
0x202f2f0920202020ull,0x662e646461090a31ull,0x3333662509203233ull,0x202c38316625202cull,
0x2020203b32336625ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c34336625ull,
0x20202020203b3333ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3533662509203233ull,
0x203b33326625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c36336625ull,0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,
0x3366250920323366ull,0x3030306630202c37ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x2e64322e78657409ull,0x662e3233752e3476ull,0x393272257b203233ull,0x72252c303372252cull,
0x7d323372252c3133ull,0x257b2c7865745b2cull,0x353366252c343366ull,0x66252c363366252cull,
0x6d090a3b5d7d3733ull,0x09203233732e766full,0x7225202c33337225ull,0x20202020203b3932ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3833662509203233ull,0x303030346630202cull,
0x2020203b30303030ull,0x090a32202f2f0920ull,0x203233662e646461ull,0x25202c3933662509ull,
0x336625202c383166ull,0x2f09202020203b38ull,0x2e766f6d090a202full,0x3466250920323366ull,
0x3b39336625202c30ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x25202c3134662509ull,0x202020203b333266ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3466250920323366ull,0x3030306630202c32ull,0x20203b3030303030ull,0x0a30202f2f092020ull,
0x3233662e766f6d09ull,0x202c333466250920ull,0x3030303030306630ull,0x09202020203b3030ull,
0x6574090a30202f2full,0x2e34762e64322e78ull,0x203233662e323375ull,0x72252c343372257bull,
0x2c363372252c3533ull,0x745b2c7d37337225ull,0x303466257b2c7865ull,0x66252c313466252cull,
0x7d333466252c3234ull,0x2e766f6d090a3b5dull,0x3372250920323373ull,0x3b34337225202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3434662509ull,
0x202020203b313266ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3466250920323366ull,
0x3b39316625202c35ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x30202c3634662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x30306630202c3734ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x64322e786574090aull,0x2e3233752e34762eull,0x3372257b20323366ull,0x252c303472252c39ull,
0x323472252c313472ull,0x7b2c7865745b2c7dull,0x3466252c34346625ull,0x252c363466252c35ull,
0x090a3b5d7d373466ull,0x203233732e766f6dull,0x25202c3334722509ull,0x202020203b393372ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3466250920323366ull,0x3b38316625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3934662509ull,
0x202020203b393166ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3566250920323366ull,
0x3030306630202c30ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x202c313566250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x6574090a30202f2full,
0x2e34762e64322e78ull,0x203233662e323375ull,0x72252c343472257bull,0x2c363472252c3534ull,
0x745b2c7d37347225ull,0x383466257b2c7865ull,0x66252c393466252cull,0x7d313566252c3035ull,
0x2e766f6d090a3b5dull,0x3472250920323373ull,0x3b34347225202c38ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3235662509ull,0x202020203b333366ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3566250920323366ull,0x3b39316625202c33ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3435662509ull,
0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,0x662509203233662eull,
0x30306630202c3535ull,0x203b303030303030ull,0x30202f2f09202020ull,0x64322e786574090aull,
0x2e3233752e34762eull,0x3472257b20323366ull,0x252c303572252c39ull,0x323572252c313572ull,
0x7b2c7865745b2c7dull,0x3566252c32356625ull,0x252c343566252c33ull,0x090a3b5d7d353566ull,
0x203233732e766f6dull,0x25202c3335722509ull,0x202020203b393472ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3566250920323366ull,0x3b39336625202c36ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3735662509ull,0x202020203b393166ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3566250920323366ull,0x3030306630202c38ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c393566250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x6574090a30202f2full,0x2e34762e64322e78ull,
0x203233662e323375ull,0x72252c343572257bull,0x2c363572252c3535ull,0x745b2c7d37357225ull,
0x363566257b2c7865ull,0x66252c373566252cull,0x7d393566252c3835ull,0x2e766f6d090a3b5dull,
0x3572250920323373ull,0x3b34357225202c38ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x30202c3036662509ull,0x3030303038663366ull,0x2f09202020203b30ull,
0x646461090a31202full,0x662509203233662eull,0x39316625202c3136ull,0x203b30366625202cull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c323666250920ull,0x2020203b31326625ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x31366625202c3336ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c343666250920ull,
0x3030303030306630ull,0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,
0x306630202c353666ull,0x3b30303030303030ull,0x202f2f0920202020ull,0x322e786574090a30ull,
0x3233752e34762e64ull,0x72257b203233662eull,0x2c303672252c3935ull,0x3672252c31367225ull,
0x2c7865745b2c7d32ull,0x66252c323666257bull,0x2c343666252c3336ull,0x0a3b5d7d35366625ull,
0x3233732e766f6d09ull,0x202c333672250920ull,0x2020203b39357225ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x38316625202c3636ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c373666250920ull,0x2020203b31366625ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x30306630202c3836ull,
0x203b303030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c39366625092032ull,
0x3030303030663020ull,0x202020203b303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,
0x3233662e3233752eull,0x252c343672257b20ull,0x363672252c353672ull,0x5b2c7d373672252cull,
0x3666257b2c786574ull,0x252c373666252c36ull,0x393666252c383666ull,0x766f6d090a3b5d7dull,
0x722509203233732eull,0x34367225202c3836ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c303766250920ull,0x2020203b33336625ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x31366625202c3137ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c323766250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c333766ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x322e786574090a30ull,0x3233752e34762e64ull,
0x72257b203233662eull,0x2c303772252c3936ull,0x3772252c31377225ull,0x2c7865745b2c7d32ull,
0x66252c303766257bull,0x2c323766252c3137ull,0x0a3b5d7d33376625ull,0x3233732e766f6d09ull,
0x202c333772250920ull,0x2020203b39367225ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x662509203233662eull,0x39336625202c3437ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c353766250920ull,0x2020203b31366625ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x30306630202c3637ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c37376625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x74090a30202f2f09ull,0x34762e64322e7865ull,0x3233662e3233752eull,
0x252c343772257b20ull,0x363772252c353772ull,0x5b2c7d373772252cull,0x3766257b2c786574ull,
0x252c353766252c34ull,0x373766252c363766ull,0x766f6d090a3b5d7dull,0x722509203233732eull,
0x34377225202c3837ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c383766250920ull,0x3030303030346630ull,0x09202020203b3030ull,0x6461090a32202f2full,
0x2509203233662e64ull,0x316625202c393766ull,0x3b38376625202c39ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c30386625092032ull,0x20203b3132662520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x376625202c313866ull,0x2020202020203b39ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c32386625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c33386625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e786574090a3020ull,0x33752e34762e6432ull,
0x257b203233662e32ull,0x303872252c393772ull,0x72252c313872252cull,0x7865745b2c7d3238ull,
0x252c303866257b2cull,0x323866252c313866ull,0x3b5d7d333866252cull,0x33732e766f6d090aull,
0x2c33387225092032ull,0x20203b3937722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c343866ull,0x2020202020203b38ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c35386625092032ull,0x20203b3937662520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x306630202c363866ull,0x3b30303030303030ull,
0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3738662509203233ull,0x303030306630202cull,
0x2020203b30303030ull,0x090a30202f2f0920ull,0x762e64322e786574ull,0x33662e3233752e34ull,
0x2c343872257b2032ull,0x3872252c35387225ull,0x2c7d373872252c36ull,0x66257b2c7865745bull,
0x2c353866252c3438ull,0x3866252c36386625ull,0x6f6d090a3b5d7d37ull,0x2509203233732e76ull,
0x387225202c383872ull,0x2020202020203b34ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c38386625092032ull,0x20203b3333662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x376625202c393866ull,0x2020202020203b39ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c30396625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c31396625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e786574090a3020ull,0x33752e34762e6432ull,0x257b203233662e32ull,
0x303972252c393872ull,0x72252c313972252cull,0x7865745b2c7d3239ull,0x252c383866257b2cull,
0x303966252c393866ull,0x3b5d7d313966252cull,0x33732e766f6d090aull,0x2c33397225092032ull,
0x20203b3938722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x336625202c323966ull,0x2020202020203b39ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c33396625092032ull,0x20203b3937662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x306630202c343966ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3539662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x762e64322e786574ull,0x33662e3233752e34ull,0x2c343972257b2032ull,
0x3972252c35397225ull,0x2c7d373972252c36ull,0x66257b2c7865745bull,0x2c333966252c3239ull,
0x3966252c34396625ull,0x6f6d090a3b5d7d35ull,0x2509203233732e76ull,0x397225202c383972ull,
0x2020202020203b34ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093430310935ull,
0x3233662e62757309ull,0x202c363966250920ull,0x6625202c35316625ull,0x09202020203b3831ull,
0x766f6d090a202f2full,0x662509203233662eull,0x30346630202c3739ull,0x203b303030303034ull,
0x33202f2f09202020ull,0x33662e627573090aull,0x2c38396625092032ull,0x25202c3739662520ull,
0x202020203b363966ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x636630202c393966ull,
0x3b30303030303430ull,0x202f2f0920202020ull,0x2e64616d090a332dull,0x3166250920323366ull,
0x36396625202c3030ull,0x202c38396625202cull,0x2f2f093b39396625ull,0x662e766f6d090a20ull,
0x3031662509203233ull,0x3866336630202c31ull,0x20203b3030303030ull,0x090a31202f2f0920ull,
0x203233662e64616dull,0x202c323031662509ull,0x6625202c36396625ull,0x316625202c303031ull,
0x0a202f2f093b3130ull,0x3233662e766f6d09ull,0x2c33303166250920ull,0x6161326533663020ull,
0x092020203b626161ull,0x3636312e30202f2full,0x6c756d090a373636ull,0x662509203233662eull,
0x316625202c343031ull,0x30316625202c3230ull,0x0a202f2f09203b33ull,0x353109636f6c2e09ull,
0x090a300935303109ull,0x203233662e766f6dull,0x202c353031662509ull,0x3030306330636630ull,
0x2f092020203b3030ull,0x6f6d090a362d202full,0x2509203233662e76ull,0x6630202c36303166ull,
0x3030303030343034ull,0x202f2f092020203bull,0x662e64616d090a33ull,0x3031662509203233ull,
0x3630316625202c37ull,0x202c36396625202cull,0x2f093b3530316625ull,0x2e6c756d090a202full,
0x3166250920323366ull,0x36396625202c3830ull,0x203b36396625202cull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x202c393031662509ull,0x3030303830346630ull,0x2f092020203b3030ull,
0x64616d090a34202full,0x662509203233662eull,0x316625202c303131ull,0x30316625202c3730ull,
0x3930316625202c38ull,0x6d090a202f2f093bull,0x09203233662e766full,0x30202c3131316625ull,
0x6161616132653366ull,0x2f2f092020203b62ull,0x36363636312e3020ull,0x662e6c756d090a37ull,
0x3131662509203233ull,0x3031316625202c32ull,0x3b3131316625202cull,0x2e090a202f2f0920ull,
0x3109353109636f6cull,0x6f6d090a30093630ull,0x2509203233662e76ull,0x6630202c33313166ull,
0x3030303030343034ull,0x202f2f092020203bull,0x662e766f6d090a33ull,0x3131662509203233ull,
0x3430636630202c34ull,0x20203b3030303030ull,0x0a332d202f2f0920ull,0x3233662e64616d09ull,
0x2c35313166250920ull,0x202c343131662520ull,0x6625202c36396625ull,0x202f2f093b333131ull,
0x33662e766f6d090aull,0x3631316625092032ull,0x303430346630202cull,0x2020203b30303030ull,
0x6d090a33202f2f09ull,0x09203233662e6461ull,0x25202c3731316625ull,0x316625202c363966ull,
0x31316625202c3531ull,0x090a202f2f093b36ull,0x203233662e766f6dull,0x202c383131662509ull,
0x3030303866336630ull,0x2f092020203b3030ull,0x64616d090a31202full,0x662509203233662eull,
0x396625202c393131ull,0x3731316625202c36ull,0x3b3831316625202cull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x6630202c30323166ull,0x6261616161326533ull,0x202f2f092020203bull,
0x3736363636312e30ull,0x33662e6c756d090aull,0x3132316625092032ull,0x2c3931316625202cull,
0x203b303231662520ull,0x6c2e090a202f2f09ull,0x303109353109636full,0x6c756d090a300937ull,
0x662509203233662eull,0x396625202c323231ull,0x3830316625202c36ull,0x0a202f2f0920203bull,
0x3233662e766f6d09ull,0x2c33323166250920ull,0x6161326533663020ull,0x092020203b626161ull,
0x3636312e30202f2full,0x6c756d090a373636ull,0x662509203233662eull,0x316625202c343231ull,
0x32316625202c3232ull,0x0a202f2f09203b33ull,0x353109636f6c2e09ull,0x090a300933323109ull,
0x203233622e766f6dull,0x202c353231662509ull,0x2020203b33327225ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x3166250920323366ull,0x30316625202c3632ull,0x3532316625202c34ull,
0x090a202f2f09203bull,0x203233622e766f6dull,0x202c373231662509ull,0x2020203b38327225ull,
0x2f09202020202020ull,0x2e64616d090a202full,0x3166250920323366ull,0x32316625202c3832ull,
0x3231316625202c37ull,0x3b3632316625202cull,0x6f6d090a202f2f09ull,0x2509203233622e76ull,
0x7225202c39323166ull,0x20202020203b3333ull,0x202f2f0920202020ull,0x33662e64616d090aull,
0x3033316625092032ull,0x2c3932316625202cull,0x202c313231662520ull,0x2f093b3832316625ull,
0x2e766f6d090a202full,0x3166250920323362ull,0x38337225202c3133ull,0x202020202020203bull,
0x090a202f2f092020ull,0x203233662e64616dull,0x202c323331662509ull,0x25202c3133316625ull,
0x6625202c34323166ull,0x202f2f093b303331ull,0x33622e766f6d090aull,0x3333316625092032ull,
0x203b33347225202cull,0x2020202020202020ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c34333166ull,0x316625202c343031ull,0x202f2f09203b3333ull,0x33622e766f6d090aull,
0x3533316625092032ull,0x203b38347225202cull,0x2020202020202020ull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c36333166ull,0x316625202c353331ull,0x33316625202c3231ull,
0x090a202f2f093b34ull,0x203233622e766f6dull,0x202c373331662509ull,0x2020203b33357225ull,
0x2f09202020202020ull,0x2e64616d090a202full,0x3166250920323366ull,0x33316625202c3833ull,
0x3132316625202c37ull,0x3b3633316625202cull,0x6f6d090a202f2f09ull,0x2509203233622e76ull,
0x7225202c39333166ull,0x20202020203b3835ull,0x202f2f0920202020ull,0x33662e64616d090aull,
0x3034316625092032ull,0x2c3933316625202cull,0x202c343231662520ull,0x2f093b3833316625ull,
0x2e766f6d090a202full,0x3166250920323362ull,0x33367225202c3134ull,0x202020202020203bull,
0x090a202f2f092020ull,0x203233662e6c756dull,0x202c323431662509ull,0x25202c3430316625ull,
0x2f09203b31343166ull,0x2e766f6d090a202full,0x3166250920323362ull,0x38367225202c3334ull,
0x202020202020203bull,0x090a202f2f092020ull,0x203233662e64616dull,0x202c343431662509ull,
0x25202c3334316625ull,0x6625202c32313166ull,0x202f2f093b323431ull,0x33622e766f6d090aull,
0x3534316625092032ull,0x203b33377225202cull,0x2020202020202020ull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c36343166ull,0x316625202c353431ull,0x34316625202c3132ull,
0x090a202f2f093b34ull,0x203233622e766f6dull,0x202c373431662509ull,0x2020203b38377225ull,
0x2f09202020202020ull,0x2e64616d090a202full,0x3166250920323366ull,0x34316625202c3834ull,
0x3432316625202c37ull,0x3b3634316625202cull,0x6f6d090a202f2f09ull,0x2509203233622e76ull,
0x7225202c39343166ull,0x20202020203b3338ull,0x202f2f0920202020ull,0x33662e6c756d090aull,
0x3035316625092032ull,0x2c3430316625202cull,0x203b393431662520ull,0x6f6d090a202f2f09ull,
0x2509203233622e76ull,0x7225202c31353166ull,0x20202020203b3838ull,0x202f2f0920202020ull,
0x33662e64616d090aull,0x3235316625092032ull,0x2c3135316625202cull,0x202c323131662520ull,
0x2f093b3035316625ull,0x2e766f6d090a202full,0x3166250920323362ull,0x33397225202c3335ull,
0x202020202020203bull,0x090a202f2f092020ull,0x203233662e64616dull,0x202c343531662509ull,
0x25202c3335316625ull,0x6625202c31323166ull,0x202f2f093b323531ull,0x33622e766f6d090aull,
0x3535316625092032ull,0x203b38397225202cull,0x2020202020202020ull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c36353166ull,0x316625202c353531ull,0x35316625202c3432ull,
0x090a202f2f093b34ull,0x09353109636f6c2eull,0x73090a3009343031ull,0x09203233662e6275ull,
0x25202c3735316625ull,0x316625202c373166ull,0x2f2f092020203b39ull,0x662e766f6d090a20ull,
0x3531662509203233ull,0x3866336630202c38ull,0x20203b3030303030ull,0x090a31202f2f0920ull,
0x203233662e766f6dull,0x202c393531662509ull,0x3030303430636630ull,0x2f092020203b3030ull,
0x6f6d090a332d202full,0x2509203233662e76ull,0x6630202c30363166ull,0x3030303030343034ull,
0x202f2f092020203bull,0x662e627573090a33ull,0x3631662509203233ull,0x3036316625202c31ull,
0x3b3735316625202cull,0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3236316625ull,
0x6625202c37353166ull,0x316625202c313631ull,0x0a202f2f093b3935ull,0x3233662e64616d09ull,
0x2c33363166250920ull,0x202c373531662520ull,0x25202c3236316625ull,0x2f2f093b38353166ull,
0x662e766f6d090a20ull,0x3631662509203233ull,0x3265336630202c34ull,0x20203b6261616161ull,
0x312e30202f2f0920ull,0x6d090a3736363636ull,0x09203233662e6c75ull,0x25202c3536316625ull,
0x6625202c33363166ull,0x2f2f09203b343631ull,0x09636f6c2e090a20ull,0x3009353031093531ull,
0x33662e6c756d090aull,0x3636316625092032ull,0x2c3735316625202cull,0x203b373531662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c37363166ull,0x3030303030383034ull,
0x202f2f092020203bull,0x662e766f6d090a34ull,0x3631662509203233ull,0x6330636630202c38ull,
0x20203b3030303030ull,0x0a362d202f2f0920ull,0x3233662e766f6d09ull,0x2c39363166250920ull,
0x3030343034663020ull,0x092020203b303030ull,0x616d090a33202f2full,0x2509203233662e64ull,
0x6625202c30373166ull,0x316625202c393631ull,0x36316625202c3735ull,0x090a202f2f093b38ull,
0x203233662e64616dull,0x202c313731662509ull,0x25202c3037316625ull,0x6625202c36363166ull,
0x202f2f093b373631ull,0x33662e766f6d090aull,0x3237316625092032ull,0x613265336630202cull,
0x2020203b62616161ull,0x36312e30202f2f09ull,0x756d090a37363636ull,0x2509203233662e6cull,
0x6625202c33373166ull,0x316625202c313731ull,0x202f2f09203b3237ull,0x3109636f6c2e090aull,
0x0a30093630310935ull,0x3233662e766f6d09ull,0x2c34373166250920ull,0x3030386633663020ull,
0x092020203b303030ull,0x6f6d090a31202f2full,0x2509203233662e76ull,0x6630202c35373166ull,
0x3030303030343034ull,0x202f2f092020203bull,0x662e766f6d090a33ull,0x3731662509203233ull,
0x3430346630202c36ull,0x20203b3030303030ull,0x090a33202f2f0920ull,0x203233662e766f6dull,
0x202c373731662509ull,0x3030303430636630ull,0x2f092020203b3030ull,0x616d090a332d202full,
0x2509203233662e64ull,0x6625202c38373166ull,0x316625202c373731ull,0x37316625202c3735ull,
0x090a202f2f093b36ull,0x203233662e64616dull,0x202c393731662509ull,0x25202c3735316625ull,
0x6625202c38373166ull,0x202f2f093b353731ull,0x33662e64616d090aull,0x3038316625092032ull,
0x2c3735316625202cull,0x202c393731662520ull,0x2f093b3437316625ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x65336630202c3138ull,0x203b626161616132ull,0x2e30202f2f092020ull,
0x090a373636363631ull,0x203233662e6c756dull,0x202c323831662509ull,0x25202c3038316625ull,
0x2f09203b31383166ull,0x636f6c2e090a202full,0x0937303109353109ull,0x662e6c756d090a30ull,
0x3831662509203233ull,0x3735316625202c33ull,0x3b3636316625202cull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x30202c3438316625ull,0x6161616132653366ull,0x2f2f092020203b62ull,
0x36363636312e3020ull,0x662e6c756d090a37ull,0x3831662509203233ull,0x3338316625202c35ull,
0x3b3438316625202cull,0x2e090a202f2f0920ull,0x3109353109636f6cull,0x756d090a30093139ull,
0x2509203233662e6cull,0x6625202c36383166ull,0x316625202c353631ull,0x202f2f09203b3233ull,
0x33662e64616d090aull,0x3738316625092032ull,0x2c3034316625202cull,0x202c333731662520ull,
0x2f093b3638316625ull,0x326c756d090a202full,0x3233752e6f6c2e34ull,0x202c393972250920ull,
0x7225202c30317225ull,0x0a202f2f093b3131ull,0x3233662e64616d09ull,0x2c38383166250920ull,
0x202c383431662520ull,0x25202c3238316625ull,0x2f2f093b37383166ull,0x662e64616d090a20ull,
0x3831662509203233ull,0x3635316625202c39ull,0x2c3538316625202cull,0x093b383831662520ull,
0x766f6d090a202f2full,0x662509203233662eull,0x346630202c303931ull,0x3b30303030663733ull,
0x32202f2f09202020ull,0x2e6c756d090a3535ull,0x3166250920323366ull,0x38316625202c3139ull,
0x3039316625202c39ull,0x090a202f2f09203bull,0x2e697a722e747663ull,0x203233662e323375ull,
0x202c303031722509ull,0x2f093b3139316625ull,0x702e646c090a202full,0x3436752e6d617261ull,
0x202c316472250920ull,0x70616475635f5f5bull,0x35315a5f5f6d7261ull,0x7265646e65725f64ull,
0x5063696275636942ull,0x6a34726168637536ull,0x645f66666666666aull,0x5d74757074756f5full,
0x3a6469202f2f093bull,0x75635f5f20313133ull,0x5f5f6d7261706164ull,0x6e65725f6435315aull,
0x6275636942726564ull,0x6168637536506369ull,0x666666666a6a3472ull,0x7074756f5f645f66ull,
0x090a3078302b7475ull,0x203233752e646461ull,0x202c313031722509ull,0x397225202c387225ull,
0x2f09202020203b39ull,0x2e747663090a202full,0x203233752e343675ull,0x25202c3264722509ull,
0x2020203b31303172ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,
0x202c32647225202cull,0x2f09202020203b34ull,0x2e646461090a202full,0x6472250920343675ull,
0x2c31647225202c34ull,0x20203b3364722520ull,0x090a202f2f092020ull,0x203233732e766f6dull,
0x202c323031722509ull,0x20203b3030317225ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3172250920323375ull,0x20203b30202c3330ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x61626f6c672e7473ull,0x2038752e34762e6cull,0x302b346472255b09ull,0x303172257b202c5dull,
0x2c32303172252c32ull,0x72252c3230317225ull,0x2f2f093b7d333031ull,0x5f315f744c240a20ull,
0x2e090a3a32383231ull,0x3109353109636f6cull,0x7865090a30093339ull,0x20202020203b7469ull,
0x2020202020202020ull,0x2020202020202020ull,0x202f2f0920202020ull,0x646e6557444c240aull,
0x725f6435315a5f5full,0x6369427265646e65ull,0x6375365063696275ull,0x66666a6a34726168ull,
0x207d090a3a666666ull,0x6435315a5f202f2full,0x427265646e65725full,0x3650636962756369ull,
0x6a6a347261686375ull,0x090a0a6666666666ull,0x5f207972746e652eull,0x6e65725f6439315aull,
0x4274736146726564ull,0x3650636962756369ull,0x6a6a347261686375ull,0x0a28206666666666ull,
0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x725f6439315a5f5full,
0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,0x5f66666666666a6aull,
0x74757074756f5f64ull,0x7261702e09090a2cull,0x203233752e206d61ull,0x6170616475635f5full,
0x6439315a5f5f6d72ull,0x467265646e65725full,0x6275636942747361ull,0x6168637536506369ull,
0x666666666a6a3472ull,0x2c68746469775f66ull,0x617261702e09090aull,0x5f203233752e206dull,
0x726170616475635full,0x5f6439315a5f5f6dull,0x61467265646e6572ull,0x6962756369427473ull,
0x7261686375365063ull,0x66666666666a6a34ull,0x2c7468676965685full,0x617261702e09090aull,
0x5f203233662e206dull,0x726170616475635full,0x5f6439315a5f5f6dull,0x61467265646e6572ull,
0x6962756369427473ull,0x7261686375365063ull,0x66666666666a6a34ull,0x2e09090a2c78745full,
0x662e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x646e65725f643931ull,
0x6942747361467265ull,0x7536506369627563ull,0x666a6a3472616863ull,0x2c79745f66666666ull,
0x617261702e09090aull,0x5f203233662e206dull,0x726170616475635full,0x5f6439315a5f5f6dull,
0x61467265646e6572ull,0x6962756369427473ull,0x7261686375365063ull,0x66666666666a6a34ull,
0x0a2c656c6163735full,0x6d617261702e0909ull,0x5f5f203233662e20ull,0x6d72617061647563ull,
0x725f6439315a5f5full,0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x702e09090a2c7863ull,0x33662e206d617261ull,0x616475635f5f2032ull,
0x315a5f5f6d726170ull,0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,
0x66666a6a34726168ull,0x0a2979635f666666ull,0x6765722e090a7b09ull,0x7225203233752e20ull,
0x2e090a3b3e35343cull,0x3436752e20676572ull,0x3b3e363c64722520ull,0x2e206765722e090aull,
0x313c662520323366ull,0x722e090a3b3e3533ull,0x646572702e206765ull,0x0a3b3e333c702520ull,
0x353109636f6c2e09ull,0x240a300937393109ull,0x315a5f5f3142424cull,0x65646e65725f6439ull,
0x6369427473614672ull,0x6375365063696275ull,0x66666a6a34726168ull,0x7663090a3a666666ull,
0x31752e3233752e74ull,0x202c317225092036ull,0x782e646961746325ull,0x202f2f092020203bull,
0x33752e747663090aull,0x2509203631752e32ull,0x69746e25202c3272ull,0x202020203b782e64ull,
0x756d090a202f2f09ull,0x752e6f6c2e34326cull,0x2c33722509203233ull,0x7225202c31722520ull,
0x202f2f0920203b32ull,0x33752e747663090aull,0x2509203631752e32ull,0x61746325202c3472ull,
0x2020203b792e6469ull,0x7663090a202f2f09ull,0x31752e3233752e74ull,0x202c357225092036ull,
0x3b792e6469746e25ull,0x202f2f0920202020ull,0x2e34326c756d090aull,0x09203233752e6f6cull,
0x347225202c367225ull,0x20203b357225202cull,0x7663090a202f2f09ull,0x31752e3233752e74ull,
0x202c377225092036ull,0x203b782e64697425ull,0x202f2f0920202020ull,0x33752e646461090aull,
0x202c387225092032ull,0x337225202c377225ull,0x202020202020203bull,0x7663090a202f2f09ull,
0x31752e3233752e74ull,0x202c397225092036ull,0x203b792e64697425ull,0x202f2f0920202020ull,
0x33752e646461090aull,0x2c30317225092032ull,0x7225202c39722520ull,0x2020202020203b36ull,
0x646c090a202f2f09ull,0x752e6d617261702eull,0x3131722509203233ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x646e65725f643931ull,0x6942747361467265ull,0x7536506369627563ull,
0x666a6a3472616863ull,0x6469775f66666666ull,0x202f2f093b5d6874ull,0x5f203137313a6469ull,
0x726170616475635full,0x5f6439315a5f5f6dull,0x61467265646e6572ull,0x6962756369427473ull,
0x7261686375365063ull,0x66666666666a6a34ull,0x302b68746469775full,0x702e646c090a3078ull,
0x3233752e6d617261ull,0x202c323172250920ull,0x70616475635f5f5bull,0x39315a5f5f6d7261ull,
0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,0x6666666a6a347261ull,
0x68676965685f6666ull,0x69202f2f093b5d74ull,0x5f5f203837313a64ull,0x6d72617061647563ull,
0x725f6439315a5f5full,0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x302b746867696568ull,0x2e746573090a3078ull,0x752e3233752e7467ull,
0x3331722509203233ull,0x202c32317225202cull,0x2f2f093b30317225ull,0x732e67656e090a20ull,
0x3431722509203233ull,0x203b33317225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x33752e746c2e7465ull,0x2509203233752e32ull,0x387225202c353172ull,0x093b31317225202cull,
0x67656e090a202f2full,0x722509203233732eull,0x35317225202c3631ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233622e646e6109ull,0x202c373172250920ull,0x7225202c34317225ull,
0x09202020203b3631ull,0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3831ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,
0x2c37317225202c31ull,0x09203b3831722520ull,0x702540090a202f2full,0x2409206172622031ull,
0x3832315f325f744cull,0x2020202020203b32ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x63090a3009383709ull,0x33662e6e722e7476ull,0x2509203233752e32ull,0x3b387225202c3166ull,
0x2f2f092020202020ull,0x61702e646c090a20ull,0x203233662e6d6172ull,0x5f5b202c32662509ull,
0x726170616475635full,0x5f6439315a5f5f6dull,0x61467265646e6572ull,0x6962756369427473ull,
0x7261686375365063ull,0x66666666666a6a34ull,0x2f2f093b5d78635full,0x203037313a646920ull,
0x6170616475635f5full,0x6439315a5f5f6d72ull,0x467265646e65725full,0x6275636942747361ull,
0x6168637536506369ull,0x666666666a6a3472ull,0x3078302b78635f66ull,0x33662e627573090aull,
0x202c336625092032ull,0x326625202c316625ull,0x202020202020203bull,0x646c090a202f2f09ull,
0x662e6d617261702eull,0x2c34662509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,0x66666a6a34726168ull,
0x6c6163735f666666ull,0x69202f2f093b5d65ull,0x5f5f203936313a64ull,0x6d72617061647563ull,
0x725f6439315a5f5full,0x7361467265646e65ull,0x6369627563694274ull,0x3472616863753650ull,
0x5f66666666666a6aull,0x78302b656c616373ull,0x662e64616d090a30ull,0x2c35662509203233ull,
0x6625202c34662520ull,0x203b326625202c33ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x3666250920323366ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x646e65725f643931ull,
0x6942747361467265ull,0x7536506369627563ull,0x666a6a3472616863ull,0x5d78745f66666666ull,
0x3a6469202f2f093bull,0x75635f5f20393731ull,0x5f5f6d7261706164ull,0x6e65725f6439315aull,
0x4274736146726564ull,0x3650636962756369ull,0x6a6a347261686375ull,0x78745f6666666666ull,
0x6461090a3078302bull,0x2509203233662e64ull,0x2c366625202c3766ull,0x2020203b35662520ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x202c386625092032ull,0x3030303066626630ull,
0x20202020203b3030ull,0x352e302d202f2f09ull,0x33662e646461090aull,0x202c396625092032ull,
0x386625202c376625ull,0x202020202020203bull,0x7663090a202f2f09ull,0x33662e696d722e74ull,
0x2509203233662e32ull,0x396625202c303166ull,0x202f2f092020203bull,0x33662e627573090aull,
0x2c31316625092032ull,0x6625202c39662520ull,0x20202020203b3031ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x346630202c323166ull,0x3b30303030303430ull,0x202f2f0920202020ull,
0x662e627573090a33ull,0x3331662509203233ull,0x202c32316625202cull,0x2020203b31316625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c34316625ull,0x3030303030343063ull,
0x2f2f09202020203bull,0x64616d090a332d20ull,0x662509203233662eull,0x31316625202c3531ull,
0x202c33316625202cull,0x2f2f093b34316625ull,0x662e766f6d090a20ull,0x3631662509203233ull,
0x303866336630202cull,0x2020203b30303030ull,0x090a31202f2f0920ull,0x203233662e64616dull,
0x25202c3731662509ull,0x316625202c313166ull,0x3b36316625202c35ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x336630202c383166ull,0x3b62616161613265ull,0x202f2f0920202020ull,
0x3736363636312e30ull,0x33662e6c756d090aull,0x2c39316625092032ull,0x25202c3731662520ull,
0x202020203b383166ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x636630202c303266ull,
0x3b30303030306330ull,0x202f2f0920202020ull,0x2e766f6d090a362dull,0x3266250920323366ull,
0x3430346630202c31ull,0x20203b3030303030ull,0x0a33202f2f092020ull,0x3233662e64616d09ull,
0x202c323266250920ull,0x6625202c31326625ull,0x30326625202c3131ull,0x6d090a202f2f093bull,
0x09203233662e6c75ull,0x6625202c33326625ull,0x31316625202c3131ull,0x2f2f09202020203bull,
0x662e766f6d090a20ull,0x3432662509203233ull,0x303830346630202cull,0x2020203b30303030ull,
0x090a34202f2f0920ull,0x203233662e64616dull,0x25202c3532662509ull,0x326625202c323266ull,
0x3b34326625202c33ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x336630202c363266ull,
0x3b62616161613265ull,0x202f2f0920202020ull,0x3736363636312e30ull,0x33662e6c756d090aull,
0x2c37326625092032ull,0x25202c3532662520ull,0x202020203b363266ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x326625202c383266ull,0x3b39316625202c37ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x090a300933380935ull,0x203233662e766f6dull,0x30202c3932662509ull,
0x3030303034303466ull,0x2f09202020203b30ull,0x766f6d090a33202full,0x662509203233662eull,
0x30636630202c3033ull,0x203b303030303034ull,0x2d202f2f09202020ull,0x662e64616d090a33ull,
0x3133662509203233ull,0x202c30336625202cull,0x6625202c31316625ull,0x0a202f2f093b3932ull,
0x3233662e766f6d09ull,0x202c323366250920ull,0x3030303430346630ull,0x09202020203b3030ull,
0x616d090a33202f2full,0x2509203233662e64ull,0x316625202c333366ull,0x2c31336625202c31ull,
0x2f093b3233662520ull,0x2e766f6d090a202full,0x3366250920323366ull,0x3866336630202c34ull,
0x20203b3030303030ull,0x0a31202f2f092020ull,0x3233662e64616d09ull,0x202c353366250920ull,
0x6625202c31316625ull,0x34336625202c3333ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x6630202c36336625ull,0x6261616161326533ull,0x2f2f09202020203bull,0x36363636312e3020ull,
0x662e6c756d090a37ull,0x3733662509203233ull,0x202c35336625202cull,0x2020203b36336625ull,
0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x6625202c38336625ull,0x33326625202c3131ull,
0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3933662509203233ull,0x613265336630202cull,
0x2020203b62616161ull,0x312e30202f2f0920ull,0x6d090a3736363636ull,0x09203233662e6c75ull,
0x6625202c30346625ull,0x39336625202c3833ull,0x2f2f09202020203bull,0x662e646461090a20ull,
0x3134662509203233ull,0x202c30346625202cull,0x2020203b37336625ull,0x2e090a202f2f0920ull,
0x3909353109636f6cull,0x766964090a300930ull,0x2e786f727070612eull,0x3466250920323366ull,
0x2c37326625202c32ull,0x2f093b3832662520ull,0x2e766f6d090a202full,0x3466250920323366ull,
0x3866626630202c33ull,0x20203b3030303030ull,0x312d202f2f092020ull,0x33662e646461090aull,
0x2c34346625092032ull,0x25202c3234662520ull,0x202020203b333466ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x336630202c353466ull,0x3b30303030303066ull,0x202f2f0920202020ull,
0x646461090a352e30ull,0x662509203233662eull,0x34346625202c3634ull,0x203b35346625202cull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x64090a3009353909ull,0x6f727070612e7669ull,
0x2509203233662e78ull,0x346625202c373466ull,0x3b31346625202c30ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x336630202c383466ull,0x3b30303030303866ull,0x202f2f0920202020ull,
0x662e646461090a31ull,0x3934662509203233ull,0x202c37346625202cull,0x2020203b38346625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c30356625ull,0x3030303030306633ull,
0x2f2f09202020203bull,0x6461090a352e3020ull,0x2509203233662e64ull,0x346625202c313566ull,
0x3b30356625202c39ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300930390935ull,
0x662e6e722e747663ull,0x09203233752e3233ull,0x7225202c32356625ull,0x2f092020203b3031ull,
0x702e646c090a202full,0x3233662e6d617261ull,0x202c333566250920ull,0x70616475635f5f5bull,
0x39315a5f5f6d7261ull,0x7265646e65725f64ull,0x7563694274736146ull,0x6863753650636962ull,
0x6666666a6a347261ull,0x093b5d79635f6666ull,0x36313a6469202f2full,0x616475635f5f2038ull,
0x315a5f5f6d726170ull,0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,
0x66666a6a34726168ull,0x302b79635f666666ull,0x2e627573090a3078ull,0x3566250920323366ull,
0x2c32356625202c34ull,0x20203b3335662520ull,0x090a202f2f092020ull,0x203233662e64616dull,
0x25202c3535662509ull,0x34356625202c3466ull,0x093b33356625202cull,0x2e646c090a202f2full,
0x33662e6d61726170ull,0x2c36356625092032ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,0x66666a6a34726168ull,
0x3b5d79745f666666ull,0x313a6469202f2f09ull,0x6475635f5f203038ull,0x5a5f5f6d72617061ull,
0x646e65725f643931ull,0x6942747361467265ull,0x7536506369627563ull,0x666a6a3472616863ull,
0x2b79745f66666666ull,0x646461090a307830ull,0x662509203233662eull,0x36356625202c3735ull,
0x203b35356625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c383566250920ull,
0x3030303066626630ull,0x09202020203b3030ull,0x0a352e302d202f2full,0x3233662e64646109ull,
0x202c393566250920ull,0x6625202c37356625ull,0x09202020203b3835ull,0x747663090a202f2full,
0x3233662e696d722eull,0x662509203233662eull,0x39356625202c3036ull,0x0a202f2f0920203bull,
0x3233662e62757309ull,0x202c313666250920ull,0x6625202c39356625ull,0x09202020203b3036ull,
0x766f6d090a202f2full,0x662509203233662eull,0x30636630202c3236ull,0x203b303030303063ull,
0x2d202f2f09202020ull,0x662e766f6d090a36ull,0x3336662509203233ull,0x303430346630202cull,
0x2020203b30303030ull,0x090a33202f2f0920ull,0x203233662e64616dull,0x25202c3436662509ull,
0x366625202c333666ull,0x3b32366625202c31ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x366625202c353666ull,0x3b31366625202c31ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c36366625092032ull,0x3030383034663020ull,0x202020203b303030ull,0x6d090a34202f2f09ull,
0x09203233662e6461ull,0x6625202c37366625ull,0x35366625202c3436ull,0x093b36366625202cull,
0x766f6d090a202f2full,0x662509203233662eull,0x65336630202c3836ull,0x203b626161616132ull,
0x30202f2f09202020ull,0x0a3736363636312eull,0x3233662e6c756d09ull,0x202c393666250920ull,
0x6625202c37366625ull,0x09202020203b3836ull,0x766f6d090a202f2full,0x662509203233662eull,
0x30346630202c3037ull,0x203b303030303034ull,0x33202f2f09202020ull,0x33662e627573090aull,
0x2c31376625092032ull,0x25202c3037662520ull,0x202020203b313666ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x636630202c323766ull,0x3b30303030303430ull,0x202f2f0920202020ull,
0x2e64616d090a332dull,0x3766250920323366ull,0x2c31366625202c33ull,0x25202c3137662520ull,
0x202f2f093b323766ull,0x33662e766f6d090aull,0x2c34376625092032ull,0x3030386633663020ull,
0x202020203b303030ull,0x6d090a31202f2f09ull,0x09203233662e6461ull,0x6625202c35376625ull,
0x33376625202c3136ull,0x093b34376625202cull,0x766f6d090a202f2full,0x662509203233662eull,
0x65336630202c3637ull,0x203b626161616132ull,0x30202f2f09202020ull,0x0a3736363636312eull,
0x3233662e6c756d09ull,0x202c373766250920ull,0x6625202c35376625ull,0x09202020203b3637ull,
0x6f6c2e090a202f2full,0x0935390935310963ull,0x662e6c756d090a30ull,0x3837662509203233ull,
0x202c31366625202cull,0x2020203b35366625ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c39376625ull,0x6261616161326533ull,0x2f2f09202020203bull,0x36363636312e3020ull,
0x662e6c756d090a37ull,0x3038662509203233ull,0x202c38376625202cull,0x2020203b39376625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c31386625ull,0x3030303030343034ull,
0x2f2f09202020203bull,0x2e766f6d090a3320ull,0x3866250920323366ull,0x3430636630202c32ull,
0x20203b3030303030ull,0x332d202f2f092020ull,0x33662e64616d090aull,0x2c33386625092032ull,
0x25202c3238662520ull,0x386625202c313666ull,0x090a202f2f093b31ull,0x203233662e766f6dull,
0x30202c3438662509ull,0x3030303034303466ull,0x2f09202020203b30ull,0x64616d090a33202full,
0x662509203233662eull,0x31366625202c3538ull,0x202c33386625202cull,0x2f2f093b34386625ull,
0x662e766f6d090a20ull,0x3638662509203233ull,0x303866336630202cull,0x2020203b30303030ull,
0x090a31202f2f0920ull,0x203233662e64616dull,0x25202c3738662509ull,0x386625202c313666ull,
0x3b36386625202c35ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x336630202c383866ull,
0x3b62616161613265ull,0x202f2f0920202020ull,0x3736363636312e30ull,0x33662e6c756d090aull,
0x2c39386625092032ull,0x25202c3738662520ull,0x202020203b383866ull,0x6c2e090a202f2f09ull,
0x343109353109636full,0x646461090a300939ull,0x662509203233662eull,0x37376625202c3039ull,
0x203b39366625202cull,0x0a202f2f09202020ull,0x7070612e76696409ull,0x203233662e786f72ull,
0x25202c3139662509ull,0x396625202c393666ull,0x090a202f2f093b30ull,0x203233662e766f6dull,
0x30202c3239662509ull,0x3030303038666266ull,0x2f09202020203b30ull,0x6461090a312d202full,
0x2509203233662e64ull,0x396625202c333966ull,0x3b32396625202c31ull,0x202f2f0920202020ull,
0x33662e646461090aull,0x2c34396625092032ull,0x25202c3634662520ull,0x202020203b303166ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x336630202c353966ull,0x3b30303030303066ull,
0x202f2f0920202020ull,0x646461090a352e30ull,0x662509203233662eull,0x33396625202c3639ull,
0x203b35396625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c373966250920ull,
0x6625202c30366625ull,0x09202020203b3639ull,0x766f6d090a202f2full,0x662509203233662eull,
0x34396625202c3839ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c393966250920ull,0x2020203b37396625ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x662509203233662eull,0x306630202c303031ull,0x3b30303030303030ull,0x30202f2f09202020ull,
0x33662e766f6d090aull,0x3130316625092032ull,0x303030306630202cull,0x2020203b30303030ull,
0x74090a30202f2f09ull,0x34762e64322e7865ull,0x3233662e3233752eull,0x252c393172257b20ull,
0x313272252c303272ull,0x5b2c7d323272252cull,0x3966257b2c786574ull,0x252c393966252c38ull,
0x3166252c30303166ull,0x2e090a3b5d7d3130ull,0x3109353109636f6cull,0x6f6d090a30093135ull,
0x2509203233732e76ull,0x317225202c333272ull,0x2020202020203b39ull,0x202f2f0920202020ull,
0x33662e646461090aull,0x3230316625092032ull,0x202c31356625202cull,0x2020203b30316625ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6625202c33303166ull,0x202020203b323031ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x3430316625092032ull,0x203b37396625202cull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c35303166ull,
0x3030303030303030ull,0x202f2f092020203bull,0x662e766f6d090a30ull,0x3031662509203233ull,
0x3030306630202c36ull,0x20203b3030303030ull,0x090a30202f2f0920ull,0x762e64322e786574ull,
0x33662e3233752e34ull,0x2c343272257b2032ull,0x3272252c35327225ull,0x2c7d373272252c36ull,
0x66257b2c7865745bull,0x303166252c333031ull,0x2c35303166252c34ull,0x3b5d7d3630316625ull,
0x33732e766f6d090aull,0x2c38327225092032ull,0x20203b3432722520ull,0x2020202020202020ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c37303166ull,0x30386625202c3938ull,
0x202f2f092020203bull,0x70612e766964090aull,0x3233662e786f7270ull,0x2c38303166250920ull,
0x25202c3038662520ull,0x2f2f093b37303166ull,0x662e766f6d090a20ull,0x3031662509203233ull,
0x3866336630202c39ull,0x20203b3030303030ull,0x090a31202f2f0920ull,0x203233662e646461ull,
0x202c303131662509ull,0x25202c3830316625ull,0x2f09203b39303166ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x66336630202c3131ull,0x203b303030303030ull,0x2e30202f2f092020ull,
0x662e646461090a35ull,0x3131662509203233ull,0x3031316625202c32ull,0x3b3131316625202cull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3331316625ull,0x316625202c303666ull,
0x2f2f0920203b3231ull,0x662e766f6d090a20ull,0x3131662509203233ull,0x3b34396625202c34ull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x25202c3531316625ull,
0x2020203b33313166ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3131662509203233ull,
0x3030306630202c36ull,0x20203b3030303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x202c373131662509ull,0x3030303030306630ull,0x2f092020203b3030ull,0x786574090a30202full,
0x752e34762e64322eull,0x7b203233662e3233ull,0x3372252c39327225ull,0x252c313372252c30ull,
0x65745b2c7d323372ull,0x34313166257b2c78ull,0x252c35313166252cull,0x3166252c36313166ull,
0x6d090a3b5d7d3731ull,0x09203233732e766full,0x7225202c33337225ull,0x20202020203b3932ull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3131662509203233ull,0x3230316625202c38ull,
0x202020202020203bull,0x6d090a202f2f0920ull,0x09203233662e766full,0x25202c3931316625ull,
0x2020203b33313166ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3231662509203233ull,
0x3030306630202c30ull,0x20203b3030303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x202c313231662509ull,0x3030303030306630ull,0x2f092020203b3030ull,0x786574090a30202full,
0x752e34762e64322eull,0x7b203233662e3233ull,0x3372252c34337225ull,0x252c363372252c35ull,
0x65745b2c7d373372ull,0x38313166257b2c78ull,0x252c39313166252cull,0x3166252c30323166ull,
0x6d090a3b5d7d3132ull,0x09203233732e766full,0x7225202c38337225ull,0x20202020203b3433ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009393032093531ull,0x33622e766f6d090aull,
0x3232316625092032ull,0x203b38327225202cull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233622e76ull,0x7225202c33323166ull,0x20202020203b3332ull,0x202f2f0920202020ull,
0x33622e766f6d090aull,0x3432316625092032ull,0x203b38337225202cull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233622e76ull,0x7225202c35323166ull,0x20202020203b3333ull,
0x202f2f0920202020ull,0x33662e6c756d090aull,0x3632316625092032ull,0x2c3232316625202cull,
0x20203b3134662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c37323166ull,
0x346625202c343231ull,0x202f2f0920203b31ull,0x2e34326c756d090aull,0x09203233752e6f6cull,
0x7225202c39337225ull,0x31317225202c3031ull,0x6d090a202f2f093bull,0x09203233662e6461ull,
0x25202c3832316625ull,0x6625202c33323166ull,0x32316625202c3832ull,0x090a202f2f093b36ull,
0x203233662e64616dull,0x202c393231662509ull,0x25202c3532316625ull,0x316625202c383266ull,
0x0a202f2f093b3732ull,0x3233662e6c756d09ull,0x2c30333166250920ull,0x202c383231662520ull,
0x0920203b30396625ull,0x64616d090a202f2full,0x662509203233662eull,0x316625202c313331ull,
0x32316625202c3730ull,0x3033316625202c39ull,0x6d090a202f2f093bull,0x09203233662e766full,
0x30202c3233316625ull,0x3030306637333466ull,0x2f2f092020203b30ull,0x756d090a35353220ull,
0x2509203233662e6cull,0x6625202c33333166ull,0x316625202c313331ull,0x202f2f09203b3233ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c31647225ull,0x726170616475635full,
0x5f6439315a5f5f6dull,0x61467265646e6572ull,0x6962756369427473ull,0x7261686375365063ull,
0x66666666666a6a34ull,0x757074756f5f645full,0x69202f2f093b5d74ull,0x5f5f203138313a64ull,
0x6d72617061647563ull,0x725f6439315a5f5full,0x7361467265646e65ull,0x6369627563694274ull,
0x3472616863753650ull,0x5f66666666666a6aull,0x74757074756f5f64ull,0x6461090a3078302bull,
0x2509203233752e64ull,0x387225202c303472ull,0x203b39337225202cull,0x202f2f0920202020ull,
0x36752e747663090aull,0x2509203233752e34ull,0x347225202c326472ull,0x2020202020203b30ull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x202c336472250920ull,0x3b34202c32647225ull,
0x202f2f0920202020ull,0x36752e646461090aull,0x2c34647225092034ull,0x25202c3164722520ull,
0x202020203b336472ull,0x7663090a202f2f09ull,0x33752e697a722e74ull,0x2509203233662e32ull,
0x316625202c313472ull,0x202f2f09203b3333ull,0x33732e766f6d090aull,0x2c32347225092032ull,
0x20203b3134722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x203b30202c333472ull,0x2020202020202020ull,0x202f2f0920202020ull,0x6f6c672e7473090aull,
0x752e34762e6c6162ull,0x346472255b092038ull,0x72257b202c5d302bull,0x2c323472252c3234ull,
0x3472252c32347225ull,0x0a202f2f093b7d33ull,0x32315f325f744c24ull,0x6f6c2e090a3a3238ull,
0x3131320935310963ull,0x74697865090a3009ull,0x202020202020203bull,0x2020202020202020ull,
0x2020202020202020ull,0x240a202f2f092020ull,0x5f5f646e6557444cull,0x6e65725f6439315aull,
0x4274736146726564ull,0x3650636962756369ull,0x6a6a347261686375ull,0x090a3a6666666666ull,
0x315a5f202f2f207dull,0x65646e65725f6439ull,0x6369427473614672ull,0x6375365063696275ull,
0x66666a6a34726168ull,0x0000000a0a666666ull
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
0x726162090a343120ull,0x63090a30203d2020ull,0x090a7b2074736e6full,0x6d616e6765730909ull,
0x736e6f63203d2065ull,0x6765730909090a74ull,0x31203d20206d756eull,0x7366666f0909090aull,
0x0a30203d20207465ull,0x7365747962090909ull,0x0a3832203d202020ull,0x0a7b206d656d0909ull,
0x3030307830090909ull,0x7830206666333030ull,0x3030303030343063ull,0x3030343034783020ull,
0x6633783020303030ull,0x0a20303030303038ull,0x3265337830090909ull,0x7830206261616161ull,
0x3030303030383034ull,0x3030386662783020ull,0x7d09090a20303030ull,0x6e6962090a7d090aull,
0x090a7b2065646f63ull,0x3030383064783009ull,0x3030783020353032ull,0x3020303837303034ull,
0x3065343030306178ull,0x3032343078302039ull,0x09090a2030383730ull,0x3434303030617830ull,
0x3234307830203131ull,0x7830203038373030ull,0x3531323030303061ull,0x3030303430783020ull,
0x3009090a20303837ull,0x3063343030306178ull,0x3032343078302035ull,0x6178302030383730ull,
0x2064303234303030ull,0x3730303234307830ull,0x783009090a203038ull,0x3130303030303061ull,
0x3030303430783020ull,0x3036783020303837ull,0x3020393034303430ull,0x3837343130303678ull,
0x36783009090a2030ull,0x2064303230333030ull,0x3730303030367830ull,0x3030337830203038ull,
0x7830206466666332ull,0x3863373031323436ull,0x3033783009090a20ull,0x3020646664633330ull,
0x6332303132343678ull,0x3030303378302038ull,0x3078302033303030ull,0x2030303130303030ull,
0x303061783009090aull,0x7830203130363030ull,0x3038373430303434ull,0x3030303061783020ull,
0x3434783020313134ull,0x0a20303837343030ull,0x3030313178300909ull,0x6278302034303666ull,
0x2034313666303031ull,0x3866303031317830ull,0x3031627830203030ull,0x090a203031386634ull,
0x6435303065783009ull,0x3030783020353034ull,0x3020303837343032ull,0x3034643430306578ull,
0x3032303078302031ull,0x09090a2030383730ull,0x3037313031627830ull,0x3031627830203430ull,
0x7830203030323730ull,0x3931323030303062ull,0x3030666230783020ull,0x3009090a20333030ull,
0x3363633230303678ull,0x3032303678302031ull,0x6278302030383763ull,0x2039303030303030ull,
0x3030306662307830ull,0x783009090a203330ull,0x3131633030303061ull,0x3432306363783020ull,
0x3031783020303837ull,0x3020353030383030ull,0x3030306330633078ull,0x31783009090a2033ull,
0x2031303038303030ull,0x3030343063307830ull,0x3030617830203330ull,0x7830203531343030ull,
0x3038373432306363ull,0x3062783009090a20ull,0x3020633063303434ull,0x3234303534306278ull,
0x3030306278302030ull,0x3078302039313638ull,0x2033303030343034ull,0x383065783009090aull,
0x7830203930363032ull,0x3038373430343030ull,0x3033303063783020ull,0x3030783020643236ull,
0x0a20303837303030ull,0x3138306578300909ull,0x3078302064313630ull,0x2030383730303438ull,
0x3031303030657830ull,0x3034307830203530ull,0x090a203330303034ull,0x3138303063783009ull,
0x3030783020353230ull,0x3020303837303030ull,0x3230393030306278ull,0x3430343078302039ull,
0x09090a2033303030ull,0x3031303430657830ull,0x3063307830203130ull,0x7830203330303034ull,
0x3931363036303165ull,0x3430343030783020ull,0x3009090a20303837ull,0x3136303730316578ull,
0x3034303078302064ull,0x6578302030383738ull,0x2035333430623031ull,0x3734313430307830ull,
0x783009090a203038ull,0x3930363062303063ull,0x3030303030783020ull,0x3165783020303837ull,
0x3020393136303630ull,0x3837633034303078ull,0x65783009090a2030ull,0x2064313630373031ull,
0x3763303430307830ull,0x3031657830203038ull,0x7830206430323131ull,0x3038373431343030ull,
0x3165783009090a20ull,0x3020393230316130ull,0x3837343034303078ull,0x3030316578302030ull,
0x3078302064323031ull,0x2030383738303430ull,0x323063783009090aull,0x7830203530613162ull,
0x6261616132653330ull,0x3062323063783020ull,0x3330783020643036ull,0x0a20626161613265ull,
0x6130316578300909ull,0x3078302039323031ull,0x2030383763303430ull,0x3031393030637830ull,
0x3030307830203130ull,0x090a203038373030ull,0x3162303165783009ull,0x3030783020313230ull,
0x3020303837633034ull,0x3263303438306578ull,0x3034303078302035ull,0x09090a2030383734ull,
0x3431343830657830ull,0x3430307830206432ull,0x7830203038376330ull,0x3930343062323063ull,
0x6132653330783020ull,0x3009090a20626161ull,0x3030306232306378ull,0x3265333078302031ull,
0x3978302062616161ull,0x2038313231303030ull,0x3631303030397830ull,0x783009090a203433ull,
0x3932653034383065ull,0x3830343030783020ull,0x3065783020303837ull,0x3020313230313438ull,
0x3837303034303078ull,0x65783009090a2030ull,0x2035303230363031ull,0x3738313430307830ull,
0x3031657830203038ull,0x7830206430363064ull,0x3038373831343030ull,0x3039783009090a20ull,
0x3020633134313030ull,0x3130313030303978ull,0x3730316578302038ull,0x3078302039303430ull,
0x2030383763303430ull,0x303165783009090aull,0x7830203931303036ull,0x3038376330343030ull,
0x3030303062783020ull,0x3330783020313032ull,0x0a20333030303066ull,0x3030306278300909ull,
0x3078302064303630ull,0x2033303030306633ull,0x3430303030627830ull,0x6633307830203930ull,
0x090a203330303030ull,0x3030303062783009ull,0x3330783020353063ull,0x3020333030303066ull,
0x3130303430306278ull,0x3330306278302038ull,0x09090a2030306130ull,0x3830323030627830ull,
0x3030627830203031ull,0x7830206331613031ull,0x3830633830303031ull,0x3830303031783020ull,
0x3009090a20633030ull,0x3030383030303178ull,0x3030303178302034ull,0x3178302030303838ull,
0x2035316530303030ull,0x3763333034307830ull,0x783009090a203038ull,0x3130303030343266ull,
0x3030303030783020ull,0x3266783020343837ull,0x3020393030303034ull,0x3837303030303078ull,
0x66783009090a2034ull,0x2031313030303432ull,0x3730303030307830ull,0x3432667830203438ull,
0x7830203931303030ull,0x3438373030303030ull,0x3063783009090a20ull,0x3020313034313030ull,
0x3837303030303078ull,0x3230306578302030ull,0x3078302035303231ull,0x2030383730303030ull,
0x303063783009090aull,0x7830203030383061ull,0x3430323062303063ull,0x3039303065783020ull,
0x3030783020313063ull,0x0a20303837303030ull,0x3030306578300909ull,0x3078302031303031ull,
0x2030383734303030ull,0x3030303030637830ull,0x3334307830203130ull,0x090a203330306637ull,
0x3030303061783009ull,0x3438783020393030ull,0x3020303837343630ull,0x3038313230303378ull,
0x3031346378302035ull,0x09090a2030383730ull,0x3430303030617830ull,0x3030307830203130ull,
0x7830203038376330ull,0x3530383038303033ull,0x3030313063783020ull,0x3009090a20303837ull,
0x3038633030303278ull,0x3032343078302039ull,0x6478302030383734ull,0x2039303030313030ull,
0x3734303030307830ull,0x783009090a203038ull,0x6430303030303031ull,0x6333303030783020ull,
0x3064783020303837ull,0x3020353034306530ull,0x3837303063306178ull,0x0a7d0a7d090a2031ull,
0x090a7b2065646f63ull,0x5f203d20656d616eull,0x6e65725f6435315aull,0x6275636942726564ull,
0x6168637536506369ull,0x666666666a6a3472ull,0x206d656d6c090a66ull,0x656d73090a30203dull,
0x090a3235203d206dull,0x32203d2020676572ull,0x2020726162090a32ull,0x6e6f63090a30203dull,
0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,0x756e676573090909ull,
0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,0x2020736574796209ull,
0x09090a3032203d20ull,0x09090a7b206d656dull,0x3030303030783009ull,0x3063783020666633ull,
0x3020303030303034ull,0x3030303038663378ull,0x3034303478302030ull,0x09090a2030303030ull,
0x3030383034783009ull,0x7d09090a20303030ull,0x6e6962090a7d090aull,0x090a7b2065646f63ull,
0x3030383064783009ull,0x3030783020353032ull,0x3020303837303034ull,0x3065343030306178ull,
0x3032343078302064ull,0x09090a2030383730ull,0x3434303030617830ull,0x3234307830203930ull,
0x7830203038373030ull,0x3530323030303061ull,0x3030303430783020ull,0x3009090a20303837ull,
0x3163343030306178ull,0x3032343078302035ull,0x6178302030383730ull,0x2031313234303030ull,
0x3730303234307830ull,0x783009090a203038ull,0x3130303030303061ull,0x3030303430783020ull,
0x3036783020303837ull,0x3020313236303230ull,0x3837343030303678ull,0x36783009090a2030ull,
0x2031316130343030ull,0x3730303030367830ull,0x3030337830203038ull,0x7830206466666338ull,
0x3863373031323436ull,0x3033783009090a20ull,0x3020646664633430ull,0x6332303132343678ull,
0x3030303378302038ull,0x3078302033303030ull,0x2030303130303030ull,0x303061783009090aull,
0x7830203130383030ull,0x3038373430303434ull,0x3130303061783020ull,0x3434783020643030ull,
0x0a20303837343030ull,0x3030313178300909ull,0x6278302034303666ull,0x2038303666303031ull,
0x3866303031317830ull,0x3031627830203030ull,0x090a206330386633ull,0x6432303065783009ull,
0x3030783020393034ull,0x3020303837343032ull,0x3034643330306578ull,0x3032303078302035ull,
0x09090a2030383730ull,0x3037323031627830ull,0x3031627830203030ull,0x7830203430323731ull,
0x3130303030303062ull,0x3030666230783020ull,0x3009090a20333030ull,0x3432303030306278ull,
0x3066623078302035ull,0x6178302033303030ull,0x2039313030303030ull,0x3734323063637830ull,
0x783009090a203038ull,0x6431323230303061ull,0x3432306363783020ull,0x3036783020303837ull,
0x3020313363633830ull,0x3837303132303678ull,0x62783009090a2030ull,0x2039326330303030ull,
0x3030386662307830ull,0x3030627830203330ull,0x7830206433633030ull,0x3038373030303430ull,
0x3062783009090a20ull,0x3020393465303030ull,0x3030303866623078ull,0x3030303178302033ull,
0x3078302064306530ull,0x2030383763333034ull,0x303062783009090aull,0x7830203134653030ull,
0x3330303038663330ull,0x3930303031783020ull,0x3031783020303134ull,0x0a20343134613030ull,
0x3030303178300909ull,0x3178302038303439ull,0x2030303439303030ull,0x3032303030317830ull,
0x3034307830203530ull,0x090a203038376333ull,0x3030343266783009ull,0x3030783020313130ull,
0x3020343837303030ull,0x3030303034326678ull,0x3030303078302039ull,0x09090a2034383730ull,
0x3030303432667830ull,0x3030307830203130ull,0x7830203438373030ull,0x3132653930303062ull,
0x3034303430783020ull,0x3009090a20333030ull,0x3265313830316578ull,0x3034303078302031ull,
0x6578302030383734ull,0x2031326531383031ull,0x3738303430307830ull,0x783009090a203038ull,
0x3132303162323063ull,0x6132653330783020ull,0x3062783020626161ull,0x3020353265303030ull,
0x3030303030343078ull,0x63783009090a2033ull,0x2030353031343030ull,0x3031323030637830ull,
0x3030637830203833ull,0x7830203433303130ull,0x3030633830303031ull,0x3031783009090a20ull,
0x3020303163383030ull,0x3165383030303178ull,0x3030303178302034ull,0x3178302038306338ull,
0x2063323239303030ull,0x303031783009090aull,0x7830203430346130ull,0x6330306130303031ull,
0x3030343266783020ull,0x3030783020393230ull,0x0a20343837303030ull,0x3034326678300909ull,
0x3078302031303030ull,0x2034383730303030ull,0x3030303432667830ull,0x3030307830203131ull,
0x090a203438373030ull,0x3030343266783009ull,0x3030783020393030ull,0x3020343837303030ull,
0x3230316130306378ull,0x3030303078302064ull,0x09090a2030383730ull,0x3038303030317830ull,
0x3063307830203132ull,0x7830203330303063ull,0x3932653133383065ull,0x3032343030783020ull,
0x3009090a20303837ull,0x3465316630306378ull,0x3030303078302064ull,0x6578302030383730ull,
0x2035303632613031ull,0x3730313430307830ull,0x783009090a203038ull,0x3535323062323063ull,
0x6132653330783020ull,0x3065783020626161ull,0x3020313561323030ull,0x3837303530303078ull,
0x65783009090a2030ull,0x2064306132343030ull,0x3738333030307830ull,0x3030657830203038ull,
0x7830203932613232ull,0x3038373433303030ull,0x3062783009090a20ull,0x3020393063303030ull,
0x3030303866333078ull,0x3030303178302033ull,0x3178302030316338ull,0x2034313239303030ull,
0x303031783009090aull,0x7830203030343830ull,0x3430346130303031ull,0x3030343266783020ull,
0x3030783020313130ull,0x0a20343837303030ull,0x3034326678300909ull,0x3078302031303030ull,
0x2034383730303030ull,0x3830353130657830ull,0x3030307830203933ull,0x090a203038376332ull,
0x3830303031783009ull,0x6330783020643230ull,0x3020333030303430ull,0x3065313138306578ull,
0x3234383078302035ull,0x09090a2030383763ull,0x6531313031657830ull,0x3430307830203530ull,
0x7830203038376330ull,0x3530653131303165ull,0x3830343030783020ull,0x3009090a20303837ull,
0x3332306232306378ull,0x3265333078302035ull,0x6378302062616161ull,0x2064336531333130ull,
0x3730303030307830ull,0x783009090a203038ull,0x3535613130303065ull,0x3035303030783020ull,
0x3062783020303837ull,0x3020313563303030ull,0x3030303030343078ull,0x31783009090a2033ull,
0x2034316538303030ull,0x6538303030317830ull,0x3030317830203430ull,0x7830203031343830ull,
0x6334346130303031ull,0x3031783009090a20ull,0x3020383438613030ull,0x3038613030303178ull,
0x3034326678302030ull,0x3078302031313030ull,0x2034383730303030ull,0x343266783009090aull,
0x7830203934303030ull,0x3438373030303030ull,0x3030343266783020ull,0x3030783020313030ull,
0x0a20343837303030ull,0x6232306378300909ull,0x3078302064336531ull,0x2062616161326533ull,
0x6131343030657830ull,0x3030307830206430ull,0x090a203038376330ull,0x3132313065783009ull,
0x3030783020393465ull,0x3020303837343530ull,0x3465303030306278ull,0x3430343078302035ull,
0x09090a2030383734ull,0x6531303030657830ull,0x3030307830206434ull,0x7830203038376330ull,
0x3831343830303031ull,0x6130303031783020ull,0x3009090a20633130ull,0x3130613030303178ull,
0x3030303178302034ull,0x3178302030313861ull,0x2063303239303030ull,0x3239303030317830ull,
0x783009090a203430ull,0x3130383230303031ull,0x6333303430783020ull,0x3266783020303837ull,
0x3020393130303034ull,0x3837303030303078ull,0x66783009090a2034ull,0x2039303030303432ull,
0x3730303030307830ull,0x3432667830203438ull,0x7830203131303030ull,0x3438373030303030ull,
0x3266783009090a20ull,0x3020313030303034ull,0x3837303030303078ull,0x3030306278302034ull,
0x3078302035323261ull,0x2033303030343034ull,0x303165783009090aull,0x7830203134323239ull,
0x3038373430343030ull,0x3231313063783020ull,0x3030783020353232ull,0x0a20303837303030ull,
0x3031316578300909ull,0x3078302031343232ull,0x2030383738303430ull,0x3232303030657830ull,
0x3034307830203132ull,0x090a203330303034ull,0x3230343065783009ull,0x6330783020643232ull,
0x3020333030303430ull,0x3530326232306378ull,0x3265333078302031ull,0x09090a2062616161ull,
0x3231383031657830ull,0x3430307830203134ull,0x7830203038373031ull,0x3132323262303165ull,
0x6330343030783020ull,0x3009090a20303837ull,0x3261313630306578ull,0x3230303078302039ull,
0x6378302030383738ull,0x2039313832323130ull,0x3730303030307830ull,0x783009090a203038ull,
0x6431303262323063ull,0x6132653330783020ull,0x3165783020626161ull,0x3020643032323830ull,
0x3837383034303078ull,0x65783009090a2030ull,0x2035316531343030ull,0x3738323030307830ull,
0x3030657830203038ull,0x7830203131343064ull,0x3038373833303030ull,0x3065783009090a20ull,
0x3020353036323730ull,0x3837383130303078ull,0x6232306378302030ull,0x3078302064303630ull,
0x2062616161326533ull,0x303063783009090aull,0x7830203930323239ull,0x3038373030303030ull,
0x3066303065783020ull,0x3030783020313130ull,0x0a20303837303130ull,0x3330306578300909ull,
0x3078302031306130ull,0x2030383734303030ull,0x3430623230637830ull,0x6533307830203530ull,
0x090a206261616132ull,0x3031303065783009ull,0x3030783020313038ull,0x3020303837303030ull,
0x3030303030306378ull,0x3733343078302031ull,0x09090a2033303066ull,0x3030303030617830ull,
0x3034387830203530ull,0x7830203038373436ull,0x3930383132303033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3032303030306178ull,0x3030303078302031ull,0x3378302030383763ull,
0x2035303430383030ull,0x3730303130637830ull,0x783009090a203038ull,0x3530386330303032ull,
0x3830323430783020ull,0x3064783020303837ull,0x3020313130303130ull,0x3837343030303078ull,
0x31783009090a2030ull,0x2035313030303030ull,0x3763333030307830ull,0x3030647830203038ull,
0x7830203930323065ull,0x3138373030633061ull,0x000a7d0a7d090a20ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_10",(char*)__deviceText_$sm_10$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"45179864bc4c59a3",(char*)"bicubicTexture.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0,0x64f98d6d};
# 5 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.stub.c" 2
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 85 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1
# 86 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 111 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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
# 226 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 68 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/usr/local/cuda/bin/../include/common_functions.h" 2

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
# 93 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 864 "/usr/local/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) int __cuda_error_not_implememted(void); int __cuda_error_not_implememted(void);
# 920 "/usr/local/cuda/bin/../include/math_functions.h" 3
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

# 1 "/usr/local/cuda/bin/../include/device_functions.h" 1 3
# 426 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 427 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 2367 "/usr/local/cuda/bin/../include/device_functions.h" 3
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
# 2368 "/usr/local/cuda/bin/../include/device_functions.h" 2 3

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

static float __internal_frcp_kernel (float x,enum cudaRoundMode mode)
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

static float __internal_fsqrt_kernel (float radicand, enum cudaRoundMode mode)

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

static float __internal_fdiv_kernel (float dividend, float divisor, enum cudaRoundMode mode)

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

static float __internal_fmul_kernel2 (float a, float b, enum cudaRoundMode mode)

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

static float __internal_fmaf_kernel (float a, float b, float c, enum cudaRoundMode mode)

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
# 3148 "/usr/local/cuda/bin/../include/device_functions.h" 3
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


static float __internal_fadd_kernel2 (float a, float b, enum cudaRoundMode mode)

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
          if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {
        if ((temp | (xx.i << 1)) == 0) {

          if (mode == cudaRoundMinInf) {
            xx.i = 0x80000000;
          } else if (mode == cudaRoundPosInf) {
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
          if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
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
      if (mode == cudaRoundMinInf) {
        xx.i += (temp && (xx.i & 0x80000000));
      } else if (mode == cudaRoundPosInf) {
        xx.i += (temp && !(xx.i & 0x80000000));
      }
      xx.i = xx.i + (expo_x << 23);
      return xx.f;
    }
    if ((int)expo_x >= 254) {

      temp = xx.i & 0x80000000;
      if (mode == cudaRoundMinInf) {
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
    if (mode == cudaRoundMinInf) {
      xx.i += (temp && yy.i);
    } else if (mode == cudaRoundPosInf) {
      xx.i += (temp && !yy.i);
    }
    return xx.f;
  } else {

    if (!(yy.i << 1)) {
      if (mode == cudaRoundMinInf) {
        if (!(xx.i << 1)) {
          xx.i = xx.i | yy.i;
        }
      } else if (mode == cudaRoundPosInf) {
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

static float __frcp_rn (float a)
{
  return __internal_frcp_kernel (a, cudaRoundNearest);
}

static float __frcp_rz (float a)
{
  return __internal_frcp_kernel (a, cudaRoundZero);
}

static float __frcp_rd (float a)
{
  return __internal_frcp_kernel (a, cudaRoundMinInf);
}

static float __frcp_ru (float a)
{
  return __internal_frcp_kernel (a, cudaRoundPosInf);
}

static float __fsqrt_rn (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundNearest);
}

static float __fsqrt_rz (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundZero);
}

static float __fsqrt_rd (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundMinInf);
}

static float __fsqrt_ru (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundPosInf);
}

static float __fdiv_rn (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundNearest);
}

static float __fdiv_rz (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundZero);
}

static float __fdiv_rd (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundMinInf);
}

static float __fdiv_ru (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundPosInf);
}

static float __fadd_rd (float a, float b)
{
  return __internal_fadd_kernel2 (a, b, cudaRoundMinInf);
}

static float __fadd_ru (float a, float b)
{
  return __internal_fadd_kernel2 (a, b, cudaRoundPosInf);
}

static float __fmul_rd (float a, float b)
{
  return __internal_fmul_kernel2 (a, b, cudaRoundMinInf);
}

static float __fmul_ru (float a, float b)
{
  return __internal_fmul_kernel2 (a, b, cudaRoundPosInf);
}

static float __fmaf_rn (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundNearest);
}

static float __fmaf_rz (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundZero);
}

static float __fmaf_ru (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundPosInf);
}

static float __fmaf_rd (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundMinInf);
}

static int __cuda___isnan(double a);
static int __cuda___isnanf(float a);
static int __double2int_rz(double);
static unsigned int __double2uint_rz(double);
static long long int __double2ll_rz(double);
static unsigned long long int __double2ull_rz(double);
# 3737 "/usr/local/cuda/bin/../include/device_functions.h" 3
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
  if (__cuda___isnanf(a)) return 0.0f;
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
  volatile union __cudart_FloatIntCvt u;

  u.i = a;
  return u.f;
}

static int __float_as_int(float a)
{
  volatile union __cudart_FloatIntCvt u;

  u.f = a;
  return u.i;
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
  volatile union __cudart_FloatUintCvt res;
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
# 4518 "/usr/local/cuda/bin/../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4537 "/usr/local/cuda/bin/../include/device_functions.h" 3
static void __prof_trigger(int a)
{
}

static void __threadfence(void)
{
}

static void __threadfence_block(void)
{
}



static void __trap(void)
{
  __builtin_trap();
}
# 4573 "/usr/local/cuda/bin/../include/device_functions.h" 3
static float __fdividef(float a, float b)
{






  if (__cuda_fabsf(b) > 8.507059173e37f) {
    if (__cuda_fabsf(a) <= 3.402823466e38f) {
      return ((a / b) / 3.402823466e38f) / 3.402823466e38f;
    } else {
      return __int_as_float(0xffc00000);
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



  return __fdividef (__sinf(a), __cosf(a));

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

static int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
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

static unsigned int __brev(unsigned int a)
{
  a = ((a >> 1) & 0x55555555) + ((a & 0x55555555) << 1);
  a = ((a >> 2) & 0x33333333) + ((a & 0x33333333) << 2);
  a = ((a >> 4) & 0x0F0F0F0F) + ((a & 0x0F0F0F0F) << 4);
  a = ((a >> 8) & 0x00FF00FF) + ((a & 0x00FF00FF) << 8);
  a = ( a >> 16 ) + ( a << 16);
  return a;
}

static unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}

static int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}
# 4779 "/usr/local/cuda/bin/../include/device_functions.h" 3
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
# 4856 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 257 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static int __iAtomicAdd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static unsigned int __uAtomicAdd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicExch(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicExch(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static float __fAtomicExch(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicMin(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicMin(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicMax(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicMax(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicInc(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = (old >= val) ? 0 : old + 1; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicDec(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = ((old == 0) | (old > val)) ? val : (old - 1); __cudaMutexOperation(0);




  return old;
}

static int __iAtomicAnd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicAnd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicOr(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicOr(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicXor(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicXor(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static int __iAtomicCAS(int *address, int compare, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}

static unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}
# 4857 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 118 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static unsigned long long int __ullAtomicAdd(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static unsigned long long int __ullAtomicExch(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);



  return old;
}

static unsigned long long int __ullAtomicCAS(unsigned long long int *address, unsigned long long int compare, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);



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
# 4858 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 267 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
static double __longlong_as_double(long long int a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.i = a;
  return u.d;
}

static long long int __double_as_longlong(double a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.d = a;
  return u.i;
}

static float __internal_double2float_kernel(double a)
{
  volatile union __cudart_DoubleUlonglongCvt xx;
  volatile union __cudart_FloatUintCvt res;

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

static double __internal_ull2double_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
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

static long long int __internal_double2ll_kernel(double a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
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

static unsigned long long int __internal_double2ull_kernel(double a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
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

static int __double2hiint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[1];
}

static int __double2loint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[0];
}

static double __hiloint2double(int a, int b)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

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
# 656 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 4859 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1910 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 3
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
# 4860 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 945 "/usr/local/cuda/bin/../include/math_functions.h" 2 3


static int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 969 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 1055 "/usr/local/cuda/bin/../include/math_functions.h" 3
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

static float __internal_fmaxf(float a, float b)
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
# 1151 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 1272 "/usr/local/cuda/bin/../include/math_functions.h" 3
static int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1286 "/usr/local/cuda/bin/../include/math_functions.h" 3
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

static float __internal_fmad(float a, float b, float c)
{
  return a * b + c;
}


static float __internal_atanhf_kernel(float a_1, float a_2)
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




static float __internal_atanf_kernel(float a)
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


static float __internal_tan_kernel(float a)
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
  z = __fdividef (t, z);
  z = -t * z;
  z = __internal_atanhf_kernel(t, z);
  z = __internal_fmad ((float)e, 0.693147181f, z);
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
  a = __internal_fmad (-j, 4.8351287841796875e-004f, a);
  a = __internal_fmad (-j, 3.1385570764541626e-007f, a);
  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}
# 1630 "/usr/local/cuda/bin/../include/math_functions.h" 3
static float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = __internal_fmad (j, -0.6931457519f, a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
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
  z = __internal_fmad (j, -3.0102920532226563e-001f, a);
  z = __internal_fmad (j, -7.9034171557301747e-007f, z);
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


static float __internal_sin_kernel(float x)
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


static float __internal_cos_kernel(float x)
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
    z = - (1.0f / z);
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
  z = __internal_fmad (2.0f, z, __fdividef (0.125f, z));
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

static float __cuda_tanhf(float a)
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

static float __cuda_asinf(float a)
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
    t = __fdividef (a, t);
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
    t = t + __cuda_sqrtf(__internal_fmad (a, t, t));
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
    t =fa+__fdividef (fa,(oofa+__cuda_sqrtf(__internal_fmad(oofa,oofa,1.0f))));
    t = __cuda_log1pf(t);
  }
  return __cuda_copysignf(t, a);

}

static float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * __cuda_log1pf(t);
  return __cuda_copysignf(t, a);

}

static float __cuda_expm1f(float a)
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

static float __cuda_cbrtf(float a)
{



  float s, t;

  s = __cuda_fabsf(a);
  if ((a == 0.0f) || (s == __int_as_float(0x7f800000))) {
    return a;
  }
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t-(t-(__fdividef(s,(t*t))))*0.333333333f;
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

static float __cuda_erfinvf (float a)
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




    p = 4.014893410762552E-006f;
    p = __internal_fmad (p, a, 5.640401259462436E-001f);
    p = __internal_fmad (p, a, 2.626649872281140E+000f);
    p = __internal_fmad (p, a, 5.486372652389673E+000f);
    p = __internal_fmad (p, a, 5.250714831459401E+000f);
    q = a + 4.651376250488319E+000f;
    q = __internal_fmad (q, a, 1.026302828878470E+001f);
    q = __internal_fmad (q, a, 1.140762166021288E+001f);
    q = __internal_fmad (q, a, 5.251211619089947E+000f);

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

static float __cuda_erfcinvf (float a)
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

static float __cuda_ldexpf(float a, int b)
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
# 2638 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 2670 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 2723 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 2758 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
  return __fmaf_rn(a, b, c);
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



    t = __internal_fmad (t, prod.x, t);
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
      return b < 0 ? 1.0f / r : r;
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
      return b < 0 ? 1.0 / r : r;
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


static float __internal_tgammaf_kernel(float a)
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

static float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  float u = __cuda_copysignf (0.5f, a);
  u = __cuda_truncf (a + u);
  if (fa > 8388608.0f) u = a;
  if (fa < 0.5f) u = __cuda_truncf (a);
  return u;

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
# 3045 "/usr/local/cuda/bin/../include/math_functions.h" 3
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
# 3176 "/usr/local/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}
# 3728 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
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

static double __cuda_erfinv(double a)
{
  return (double)__cuda_erfinvf((float)a);
}

static double __cuda_erfc(double a)
{
  return (double)__cuda_erfcf((float)a);
}

static double __cuda_erfcinv(double a)
{
  return (double)__cuda_erfcinvf((float)a);
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
# 3729 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 94 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 227 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T21 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
struct __T22 {uchar4 *__par0;uint __par1;uint __par2;float __par3;float __par4;float __par5;float __par6;float __par7;int __dummy_field;};
static void __sti____cudaRegisterAll_49_tmpxft_00004c55_00000000_4_bicubicTexture_cpp1_ii_tex(void) __attribute__((__constructor__));
void __device_stub__Z8d_renderP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T20 *__T25;
char __[256]; *(char**)&__T25 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T25->__par5 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T25->__par6 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T25->__par7 - (size_t)__T25) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render__entry))); };}

}
void d_render__entry( uchar4 * __cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
{__device_stub__Z8d_renderP6uchar4jjfffff( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7);}
extern "C"{

void __device_stub__Z15d_renderBicubicP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T21 *__T26;
char __[256]; *(char**)&__T26 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T26->__par0 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T26->__par1 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T26->__par2 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T26->__par3 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T26->__par4 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T26->__par5 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T26->__par6 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T26->__par7 - (size_t)__T26) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic__entry))); };}

}
void d_renderBicubic__entry( uchar4 * __cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
{__device_stub__Z15d_renderBicubicP6uchar4jjfffff( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7);}
extern "C"{

void __device_stub__Z19d_renderFastBicubicP6uchar4jjfffff(uchar4 *__par0, uint __par1, uint __par2, float __par3, float __par4, float __par5, float __par6, float __par7){auto struct __T22 *__T2175;
char __[256]; *(char**)&__T2175 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2175->__par0 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2175->__par1 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2175->__par2 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2175->__par3 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2175->__par4 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2175->__par5 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2175->__par6 - (size_t)__T2175) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2175->__par7 - (size_t)__T2175) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic__entry))); };}

}
void d_renderFastBicubic__entry( uchar4 * __cuda_0,uint __cuda_1,uint __cuda_2,float __cuda_3,float __cuda_4,float __cuda_5,float __cuda_6,float __cuda_7)
{__device_stub__Z19d_renderFastBicubicP6uchar4jjfffff( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7);}
extern "C"{
# 43 "/tmp/tmpxft_00004c55_00000000-1_bicubicTexture.cudafe1.stub.c"
static void __sti____cudaRegisterAll_49_tmpxft_00004c55_00000000_4_bicubicTexture_cpp1_ii_tex(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderFastBicubic__entry), (char*)"_Z19d_renderFastBicubicP6uchar4jjfffff", "_Z19d_renderFastBicubicP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_renderBicubic__entry), (char*)"_Z15d_renderBicubicP6uchar4jjfffff", "_Z15d_renderBicubicP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, uint, uint, float, float, float, float, float))d_render__entry), (char*)"_Z8d_renderP6uchar4jjfffff", "_Z8d_renderP6uchar4jjfffff", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&tex, 0, "tex", 2, 1, 0);}

}
# 100 "bicubicTexture.cu" 2

# 1 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.cpp"
# 1 "MonteCarlo_SM13.cu"
# 233 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) {
# 245 "/usr/include/c++/4.3/x86_64-linux-gnu/bits/c++config.h" 3
}
# 46 "/home/normal/cuda/bin/../include/device_types.h"
# 152 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 1 3
# 80 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 53 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/home/normal/cuda/bin/../include/host_defines.h" 1 3
# 54 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 1 "/home/normal/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/home/normal/cuda/bin/../include/builtin_types.h" 3
# 1 "/home/normal/cuda/bin/../include/device_types.h" 1 3
# 46 "/home/normal/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/driver_types.h" 1 3
# 90 "/home/normal/cuda/bin/../include/driver_types.h" 3
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
# 318 "/home/normal/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef int cudaStream_t;





typedef int cudaEvent_t;
# 44 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/texture_types.h" 1 3
# 54 "/home/normal/cuda/bin/../include/texture_types.h" 3
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
# 45 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/home/normal/cuda/bin/../include/vector_types.h" 1 3
# 54 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 262 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 328 "/home/normal/cuda/bin/../include/vector_types.h" 3
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
# 419 "/home/normal/cuda/bin/../include/vector_types.h" 3
typedef struct dim3 dim3;


struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};
# 45 "/home/normal/cuda/bin/../include/builtin_types.h" 2 3
# 55 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 80 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 89 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);
# 102 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);

extern cudaError_t cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags);
extern cudaError_t cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);
# 120 "/home/normal/cuda/bin/../include/cuda_runtime_api.h" 3
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
# 81 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/home/normal/cuda/bin/../include/crt/storage_class.h" 1 3
# 82 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/x86_64-linux-gnu/4.3.3/include/stddef.h" 2 3
# 90 "/home/normal/cuda/bin/../include/driver_types.h"
# 138 "/home/normal/cuda/bin/../include/driver_types.h"
# 150 "/home/normal/cuda/bin/../include/driver_types.h"
# 163 "/home/normal/cuda/bin/../include/driver_types.h"
# 169 "/home/normal/cuda/bin/../include/driver_types.h"
# 181 "/home/normal/cuda/bin/../include/driver_types.h"
# 193 "/home/normal/cuda/bin/../include/driver_types.h"
# 204 "/home/normal/cuda/bin/../include/driver_types.h"
# 215 "/home/normal/cuda/bin/../include/driver_types.h"
# 233 "/home/normal/cuda/bin/../include/driver_types.h"
# 247 "/home/normal/cuda/bin/../include/driver_types.h"
# 259 "/home/normal/cuda/bin/../include/driver_types.h"
# 318 "/home/normal/cuda/bin/../include/driver_types.h"
# 324 "/home/normal/cuda/bin/../include/driver_types.h"
# 330 "/home/normal/cuda/bin/../include/driver_types.h"
# 54 "/home/normal/cuda/bin/../include/texture_types.h"
# 61 "/home/normal/cuda/bin/../include/texture_types.h"
# 68 "/home/normal/cuda/bin/../include/texture_types.h"
# 75 "/home/normal/cuda/bin/../include/texture_types.h"
# 54 "/home/normal/cuda/bin/../include/vector_types.h"
# 60 "/home/normal/cuda/bin/../include/vector_types.h"
# 66 "/home/normal/cuda/bin/../include/vector_types.h"
# 72 "/home/normal/cuda/bin/../include/vector_types.h"
# 78 "/home/normal/cuda/bin/../include/vector_types.h"
# 84 "/home/normal/cuda/bin/../include/vector_types.h"
# 90 "/home/normal/cuda/bin/../include/vector_types.h"
# 96 "/home/normal/cuda/bin/../include/vector_types.h"
# 102 "/home/normal/cuda/bin/../include/vector_types.h"
# 108 "/home/normal/cuda/bin/../include/vector_types.h"
# 114 "/home/normal/cuda/bin/../include/vector_types.h"
# 120 "/home/normal/cuda/bin/../include/vector_types.h"
# 126 "/home/normal/cuda/bin/../include/vector_types.h"
# 132 "/home/normal/cuda/bin/../include/vector_types.h"
# 138 "/home/normal/cuda/bin/../include/vector_types.h"
# 144 "/home/normal/cuda/bin/../include/vector_types.h"
# 150 "/home/normal/cuda/bin/../include/vector_types.h"
# 156 "/home/normal/cuda/bin/../include/vector_types.h"
# 162 "/home/normal/cuda/bin/../include/vector_types.h"
# 168 "/home/normal/cuda/bin/../include/vector_types.h"
# 174 "/home/normal/cuda/bin/../include/vector_types.h"
# 180 "/home/normal/cuda/bin/../include/vector_types.h"
# 186 "/home/normal/cuda/bin/../include/vector_types.h"
# 192 "/home/normal/cuda/bin/../include/vector_types.h"
# 198 "/home/normal/cuda/bin/../include/vector_types.h"
# 204 "/home/normal/cuda/bin/../include/vector_types.h"
# 216 "/home/normal/cuda/bin/../include/vector_types.h"
# 228 "/home/normal/cuda/bin/../include/vector_types.h"
# 262 "/home/normal/cuda/bin/../include/vector_types.h"
# 268 "/home/normal/cuda/bin/../include/vector_types.h"
# 274 "/home/normal/cuda/bin/../include/vector_types.h"
# 280 "/home/normal/cuda/bin/../include/vector_types.h"
# 286 "/home/normal/cuda/bin/../include/vector_types.h"
# 292 "/home/normal/cuda/bin/../include/vector_types.h"
# 298 "/home/normal/cuda/bin/../include/vector_types.h"
# 304 "/home/normal/cuda/bin/../include/vector_types.h"
# 310 "/home/normal/cuda/bin/../include/vector_types.h"
# 316 "/home/normal/cuda/bin/../include/vector_types.h"
# 328 "/home/normal/cuda/bin/../include/vector_types.h"
# 330 "/home/normal/cuda/bin/../include/vector_types.h"
# 332 "/home/normal/cuda/bin/../include/vector_types.h"
# 334 "/home/normal/cuda/bin/../include/vector_types.h"
# 336 "/home/normal/cuda/bin/../include/vector_types.h"
# 338 "/home/normal/cuda/bin/../include/vector_types.h"
# 340 "/home/normal/cuda/bin/../include/vector_types.h"
# 342 "/home/normal/cuda/bin/../include/vector_types.h"
# 344 "/home/normal/cuda/bin/../include/vector_types.h"
# 346 "/home/normal/cuda/bin/../include/vector_types.h"
# 348 "/home/normal/cuda/bin/../include/vector_types.h"
# 350 "/home/normal/cuda/bin/../include/vector_types.h"
# 352 "/home/normal/cuda/bin/../include/vector_types.h"
# 354 "/home/normal/cuda/bin/../include/vector_types.h"
# 356 "/home/normal/cuda/bin/../include/vector_types.h"
# 358 "/home/normal/cuda/bin/../include/vector_types.h"
# 360 "/home/normal/cuda/bin/../include/vector_types.h"
# 362 "/home/normal/cuda/bin/../include/vector_types.h"
# 364 "/home/normal/cuda/bin/../include/vector_types.h"
# 366 "/home/normal/cuda/bin/../include/vector_types.h"
# 368 "/home/normal/cuda/bin/../include/vector_types.h"
# 370 "/home/normal/cuda/bin/../include/vector_types.h"
# 372 "/home/normal/cuda/bin/../include/vector_types.h"
# 374 "/home/normal/cuda/bin/../include/vector_types.h"
# 376 "/home/normal/cuda/bin/../include/vector_types.h"
# 378 "/home/normal/cuda/bin/../include/vector_types.h"
# 380 "/home/normal/cuda/bin/../include/vector_types.h"
# 382 "/home/normal/cuda/bin/../include/vector_types.h"
# 384 "/home/normal/cuda/bin/../include/vector_types.h"
# 386 "/home/normal/cuda/bin/../include/vector_types.h"
# 388 "/home/normal/cuda/bin/../include/vector_types.h"
# 390 "/home/normal/cuda/bin/../include/vector_types.h"
# 392 "/home/normal/cuda/bin/../include/vector_types.h"
# 394 "/home/normal/cuda/bin/../include/vector_types.h"
# 396 "/home/normal/cuda/bin/../include/vector_types.h"
# 398 "/home/normal/cuda/bin/../include/vector_types.h"
# 400 "/home/normal/cuda/bin/../include/vector_types.h"
# 402 "/home/normal/cuda/bin/../include/vector_types.h"
# 404 "/home/normal/cuda/bin/../include/vector_types.h"
# 406 "/home/normal/cuda/bin/../include/vector_types.h"
# 408 "/home/normal/cuda/bin/../include/vector_types.h"
# 410 "/home/normal/cuda/bin/../include/vector_types.h"
# 419 "/home/normal/cuda/bin/../include/vector_types.h"
# 422 "/home/normal/cuda/bin/../include/vector_types.h"
# 89 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 102 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
extern "C" cudaError_t cudaMallocHost(void **, size_t);
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
extern "C" cudaError_t cudaFree(void *);
extern "C" cudaError_t cudaFreeHost(void *);
extern "C" cudaError_t cudaFreeArray(cudaArray *);

extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 120 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
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
# 137 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 152 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
extern "C" cudaError_t cudaSetDevice(int);
extern "C" cudaError_t cudaGetDevice(int *);
extern "C" cudaError_t cudaSetValidDevices(int *, int);
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 206 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
extern "C" const char *cudaGetErrorString(cudaError_t);
# 215 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
extern "C" cudaError_t cudaLaunch(const char *);
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 226 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 237 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 251 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 260 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
extern "C" cudaError_t cudaThreadSynchronize();
# 269 "/home/normal/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 93 "/home/normal/cuda/bin/../include/channel_descriptor.h"
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
# 337 "/home/normal/cuda/bin/../include/channel_descriptor.h"
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
# 54 "/home/normal/cuda/bin/../include/driver_functions.h"
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
# 54 "/home/normal/cuda/bin/../include/vector_functions.h"
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
# 218 "/home/normal/cuda/bin/../include/vector_functions.h"
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
# 56 "/home/normal/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw();
# 65 "/home/normal/cuda/bin/../include/math_functions.h"
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
# 400 "/home/normal/cuda/bin/../include/math_functions.h"
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
# 434 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 448 "/home/normal/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 473 "/home/normal/cuda/bin/../include/math_functions.h"
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
# 560 "/home/normal/cuda/bin/../include/math_functions.h"
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
# 59 "/home/normal/cuda/bin/../include/cuda_texture_types.h"
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
# 53 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 55 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 57 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 59 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 61 "/home/normal/cuda/bin/../include/device_launch_parameters.h"
# 98 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaSetupArgument(T
arg, size_t
offset)

{
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
}
# 120 "/home/normal/cuda/bin/../include/cuda_runtime.h"
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
# 174 "/home/normal/cuda/bin/../include/cuda_runtime.h"
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
# 252 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolAddress(void **
devPtr, const T &
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
}
# 267 "/home/normal/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol)

{
return cudaGetSymbolSize(size, (const char *)symbol);
}
# 296 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolSize(size_t *
size, const T &
symbol)

{
return cudaGetSymbolSize(size, (const char *)(&symbol));
}
# 352 "/home/normal/cuda/bin/../include/cuda_runtime.h"
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
# 396 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
}
# 451 "/home/normal/cuda/bin/../include/cuda_runtime.h"
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
# 493 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc)

{
return cudaBindTextureToArray(&tex, array, (&desc));
}
# 530 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array)

{
auto cudaChannelFormatDesc desc;
auto cudaError_t err = cudaGetChannelDesc(&desc, array);

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
}
# 568 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaUnbindTexture(const texture< T, dim, readMode> &
tex)

{
return cudaUnbindTexture(&tex);
}
# 607 "/home/normal/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode> &
tex)

{
return cudaGetTextureAlignmentOffset(offset, &tex);
}
# 649 "/home/normal/cuda/bin/../include/cuda_runtime.h"
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
# 62 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }

extern "C" { typedef int CUdevice; }
extern "C" { typedef struct CUctx_st *CUcontext; }
extern "C" { typedef struct CUmod_st *CUmodule; }
extern "C" { typedef struct CUfunc_st *CUfunction; }
extern "C" { typedef struct CUarray_st *CUarray; }
extern "C" { typedef struct CUtexref_st *CUtexref; }
extern "C" { typedef struct CUevent_st *CUevent; }
extern "C" { typedef struct CUstream_st *CUstream; }
# 90 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 82 "/home/normal/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
CU_CTX_SCHED_AUTO,
CU_CTX_SCHED_SPIN,
CU_CTX_SCHED_YIELD,
CU_CTX_SCHED_MASK,
CU_CTX_BLOCKING_SYNC,
CU_CTX_MAP_HOST = 8,
CU_CTX_FLAGS_MASK = 15
} CUctx_flags; }
# 98 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 95 "/home/normal/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
CU_EVENT_DEFAULT,
CU_EVENT_BLOCKING_SYNC
} CUevent_flags; }
# 112 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 103 "/home/normal/cuda/bin/../include/cuda.h"
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
# 121 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 117 "/home/normal/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
CU_TR_ADDRESS_MODE_WRAP,
CU_TR_ADDRESS_MODE_CLAMP,
CU_TR_ADDRESS_MODE_MIRROR
} CUaddress_mode; }
# 129 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 126 "/home/normal/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
CU_TR_FILTER_MODE_POINT,
CU_TR_FILTER_MODE_LINEAR
} CUfilter_mode; }
# 158 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 134 "/home/normal/cuda/bin/../include/cuda.h"
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
# 174 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 163 "/home/normal/cuda/bin/../include/cuda.h"
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
# 211 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 179 "/home/normal/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 185 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 192 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 198 "/home/normal/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,




CU_FUNC_ATTRIBUTE_NUM_REGS,

CU_FUNC_ATTRIBUTE_MAX
} CUfunction_attribute; }
# 220 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 216 "/home/normal/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
CU_MEMORYTYPE_HOST = 1,
CU_MEMORYTYPE_DEVICE,
CU_MEMORYTYPE_ARRAY
} CUmemorytype; }
# 229 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 225 "/home/normal/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
CU_COMPUTEMODE_DEFAULT,
CU_COMPUTEMODE_EXCLUSIVE,
CU_COMPUTEMODE_PROHIBITED
} CUcomputemode; }
# 308 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 234 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {




CU_JIT_MAX_REGISTERS,
# 251 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 257 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 263 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 270 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 276 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 283 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 289 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 295 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,




CU_JIT_TARGET,
# 306 "/home/normal/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY

} CUjit_option; }
# 319 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 313 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {

CU_TARGET_COMPUTE_10,
CU_TARGET_COMPUTE_11,
CU_TARGET_COMPUTE_12,
CU_TARGET_COMPUTE_13
} CUjit_target; }
# 332 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 324 "/home/normal/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {


CU_PREFER_PTX,


CU_PREFER_BINARY

} CUjit_fallback; }
# 380 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 343 "/home/normal/cuda/bin/../include/cuda.h"
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
# 426 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 406 "/home/normal/cuda/bin/../include/cuda.h"
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
# 460 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 431 "/home/normal/cuda/bin/../include/cuda.h"
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
# 473 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 466 "/home/normal/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR {
unsigned Width;
unsigned Height;

CUarray_format Format;

unsigned NumChannels;
} CUDA_ARRAY_DESCRIPTOR; }
# 489 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 479 "/home/normal/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR {
unsigned Width;
unsigned Height;
unsigned Depth;

CUarray_format Format;

unsigned NumChannels;

unsigned Flags;
} CUDA_ARRAY3D_DESCRIPTOR; }
# 528 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);




extern "C" CUresult cuDriverGetVersion(int *);
# 541 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
extern "C" CUresult cuDeviceGetCount(int *);
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 555 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
extern "C" CUresult cuCtxDestroy(CUcontext);
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
extern "C" CUresult cuCtxDetach(CUcontext);
extern "C" CUresult cuCtxPushCurrent(CUcontext);
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
extern "C" CUresult cuCtxGetDevice(CUdevice *);
extern "C" CUresult cuCtxSynchronize();
# 571 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
extern "C" CUresult cuModuleUnload(CUmodule);
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 586 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);

extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 597 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);

extern "C" CUresult cuMemAllocHost(void **, unsigned);
extern "C" CUresult cuMemFreeHost(void *);

extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);

extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 618 "/home/normal/cuda/bin/../include/cuda.h"
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
# 657 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);



extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);

extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);



extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);


extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 679 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);

extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 694 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 704 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
extern "C" CUresult cuArrayDestroy(CUarray);

extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 717 "/home/normal/cuda/bin/../include/cuda.h"
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
# 741 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
extern "C" CUresult cuParamSetf(CUfunction, int, float);
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 753 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 762 "/home/normal/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
extern "C" CUresult cuEventRecord(CUevent, CUstream);
extern "C" CUresult cuEventQuery(CUevent);
extern "C" CUresult cuEventSynchronize(CUevent);
extern "C" CUresult cuEventDestroy(CUevent);
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 774 "/home/normal/cuda/bin/../include/cuda.h"
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
# 162 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 206 "/home/normal/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
y)
{
auto cuFloatComplex prod;
prod = make_cuFloatComplex(cuCrealf(x) * cuCrealf(y) - cuCimagf(x) * cuCimagf(y), cuCrealf(x) * cuCimagf(y) + cuCimagf(x) * cuCrealf(y));



return prod;
} }
# 222 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 248 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 317 "/home/normal/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
y)
{
auto cuDoubleComplex prod;
prod = make_cuDoubleComplex(cuCreal(x) * cuCreal(y) - cuCimag(x) * cuCimag(y), cuCreal(x) * cuCimag(y) + cuCimag(x) * cuCreal(y));



return prod;
} }
# 333 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 356 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 387 "/home/normal/cuda/bin/../include/cuComplex.h"
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
# 69 "/home/normal/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 59 "/home/normal/cuda/bin/../include/cufft.h"
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
# 93 "/home/normal/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 89 "/home/normal/cuda/bin/../include/cufft.h"
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
# 52 "realtype.h"
typedef double real;
# 52 "MonteCarlo_common.h"
typedef
# 46 "MonteCarlo_common.h"
struct TOptionData {
float S;
float X;
float T;
float R;
float V;
} TOptionData;
# 61 "MonteCarlo_common.h"
typedef
# 58 "MonteCarlo_common.h"
struct __attribute__((__aligned__(8))) TOptionValue {
float Expected;
float Confidence;
} TOptionValue;
# 85 "MonteCarlo_common.h"
typedef
# 64 "MonteCarlo_common.h"
struct TOptionPlan {

int device;

int optionCount;


TOptionData *optionData;
TOptionValue *callValue;

void *d_Buffer;


unsigned seed;

int pathN;

float *d_Samples;


float time;
} TOptionPlan;
# 73 "MonteCarlo_kernel.cuh"
typedef
# 68 "MonteCarlo_kernel.cuh"
struct __TOptionData {
real S;
real X;
real MuByT;
real VBySqrtT;
} __TOptionData;
static __TOptionData __shadow_d_OptionData[2048];
# 80 "MonteCarlo_kernel.cuh"
typedef
# 77 "MonteCarlo_kernel.cuh"
struct __TOptionValue {
real Expected;
real Confidence;
} __TOptionValue;
static __TOptionValue __shadow_d_CallValue[2048];
# 109 "MonteCarlo_kernel.cuh"
static void MonteCarloKernel__entry(__TOptionValue *
d_Buffer, float *
d_Samples, int
pathN);
# 147 "MonteCarlo_kernel.cuh"
static void MonteCarloOneBlockPerOption__entry(float *
d_Samples, int
pathN);
# 191 "MonteCarlo_kernel.cuh"
static void MonteCarloReduce__entry(__TOptionValue *
d_Buffer, int
accumN);
# 228 "MonteCarlo_kernel.cuh"
static void initMonteCarloGPU(TOptionPlan *plan) {
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
if (doMultiBlock) {
auto const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
auto const int accumN = (256 * blocksPerOption);
__cudaSafeCall(cudaMalloc((void **)(&(plan->d_Buffer)), (accumN * plan->optionCount) * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 236);



}
}


static void closeMonteCarloGPU(TOptionPlan *plan) {
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
if (doMultiBlock) { __cudaSafeCall(cudaFree(plan->d_Buffer), "MonteCarlo_kernel.cuh", 243); }
}


static void MonteCarloGPU(TOptionPlan *plan) {
auto __TOptionData h_OptionData[2048];
auto __TOptionValue h_CallValue[2048];

if (((plan->optionCount) <= 0) || ((plan->optionCount) > 2048)) {
printf("MonteCarloGPU(): bad option count.\n");
return;
}

for (int i = 0; i < (plan->optionCount); i++) {
auto const double T = (((plan->optionData)[i]).T);
auto const double R = (((plan->optionData)[i]).R);
auto const double V = (((plan->optionData)[i]).V);
auto const double MuByT = ((R - ((0.5) * V) * V) * T);
auto const double VBySqrtT = (V * sqrt(T));
(((h_OptionData)[i]).S) = (real)(((plan->optionData)[i]).S);
(((h_OptionData)[i]).X) = (real)(((plan->optionData)[i]).X);
(((h_OptionData)[i]).MuByT) = (real)MuByT;
(((h_OptionData)[i]).VBySqrtT) = (real)VBySqrtT;
}

__cudaSafeCall(cudaMemcpyToSymbol(__shadow_d_OptionData, h_OptionData, plan->optionCount * sizeof(__TOptionData)), "MonteCarlo_kernel.cuh", 272);
# 274 "MonteCarlo_kernel.cuh"
auto const int doMultiBlock = ((plan->pathN / plan->optionCount) >= 8192);
if (doMultiBlock) {
auto const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
auto const int accumN = (256 * blocksPerOption);
auto const dim3 gridMain(blocksPerOption, plan->optionCount);
cudaConfigureCall(gridMain, 256) ? ((void)0) : MonteCarloKernel__entry((__TOptionValue *)(plan->d_Buffer), plan->d_Samples, plan->pathN);




__cutilCheckMsg("MonteCarloKernel() execution failed\n", "MonteCarlo_kernel.cuh", 284);
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloReduce__entry((__TOptionValue *)(plan->d_Buffer), accumN);



__cutilCheckMsg("MonteCarloReduce() execution failed\n", "MonteCarlo_kernel.cuh", 289);
} else {
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloOneBlockPerOption__entry(plan->d_Samples, plan->pathN);



__cutilCheckMsg("MonteCarloOneBlockPerOption() execution failed\n", "MonteCarlo_kernel.cuh", 295);
}
__cudaSafeCall(cudaMemcpyFromSymbol(h_CallValue, __shadow_d_CallValue, plan->optionCount * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 301);
# 303 "MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
auto const double RT = (((plan->optionData)[i]).R * ((plan->optionData)[i]).T);
auto const double sum = (((h_CallValue)[i]).Expected);
auto const double sum2 = (((h_CallValue)[i]).Confidence);
auto const double pathN = (plan->pathN);

(((plan->callValue)[i]).Expected) = (float)((exp(-RT) * sum) / pathN);

auto double stdDev = sqrt((pathN * sum2 - sum * sum) / (pathN * (pathN - (1))));

(((plan->callValue)[i]).Confidence) = (float)(((exp(-RT) * (1.959999999999999964)) * stdDev) / sqrt(pathN));
}
}
# 248 "quasirandomGenerator_kernel.cuh"
static void inverseCNDKernel__entry(float *
d_Output, float *
d_Input, unsigned
pathN);
# 274 "quasirandomGenerator_kernel.cuh"
static void inverseCNDgpu(float *d_Output, float *d_Input, unsigned N) {
cudaConfigureCall(128, 128) ? ((void)0) : inverseCNDKernel__entry(d_Output, d_Input, N);
__cutilCheckMsg("inverseCNDKernel() execution failed.\n", "quasirandomGenerator_kernel.cuh", 276);
}
# 44 "MonteCarlo_SM13.cu"
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan) {
initMonteCarloGPU(plan);
}

extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan) {
closeMonteCarloGPU(plan);
}

extern "C" void MonteCarlo_SM13(TOptionPlan *plan) {
MonteCarloGPU(plan);
}

extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned N) {
inverseCNDgpu(d_Output, d_Input, N);
}

# 1 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_0000707d_00000000-6_MonteCarlo_SM13.fatbin.c" 1
# 1 "/home/normal/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* debug;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 144 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 158 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
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
# 194 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 217 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 228 "/home/normal/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "/tmp/tmpxft_0000707d_00000000-6_MonteCarlo_SM13.fatbin.c" 2




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
0x656d73090a30203dull,0x090a3633203d206dull,0x32203d2020676572ull,0x2020726162090a37ull,
0x6e6f63090a30203dull,0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,
0x756e676573090909ull,0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,
0x2020736574796209ull,0x09090a3233203d20ull,0x09090a7b206d656dull,0x3437383063783009ull,
0x3034783020313139ull,0x3020323465323638ull,0x3063666666666678ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3030303034783009ull,0x3030783020303030ull,0x3020373330303030ull,
0x3030303030303078ull,0x3039633378302030ull,0x09090a2030303030ull,0x6962090a7d090a7dull,
0x0a7b2065646f636eull,0x3030303178300909ull,0x3478302035303230ull,0x2030383734303030ull,
0x3030303030617830ull,0x3034307830203530ull,0x090a203038373030ull,0x3431303036783009ull,
0x3030783020313663ull,0x3020303837343032ull,0x3330383030303178ull,0x3030303078302039ull,
0x09090a2033303030ull,0x3038303030317830ull,0x3030307830206433ull,0x7830203330303030ull,
0x3330303037303061ull,0x3030303030783020ull,0x3009090a20303030ull,0x6631643831303378ull,
0x3032633678302064ull,0x6178302038633763ull,0x2031316534303030ull,0x3730303234307830ull,
0x783009090a203038ull,0x3030633932303031ull,0x3930303031783020ull,0x3031783020343065ull,
0x3020393530333030ull,0x3837633330363078ull,0x31783009090a2030ull,0x2033303066363030ull,
0x3230303030307830ull,0x3030307830203038ull,0x7830203530383035ull,0x3038373030303063ull,
0x3031783009090a20ull,0x3020313132303030ull,0x3837343030303478ull,0x3230303378302030ull,
0x6378302064306332ull,0x2030383730303134ull,0x303431783009090aull,0x7830203932383030ull,
0x3038376330303432ull,0x3030303431783020ull,0x3432783020643261ull,0x0a20303837633030ull,
0x3030343178300909ull,0x3278302031336330ull,0x2030383763303034ull,0x6530303034317830ull,
0x3034327830203533ull,0x090a203038376330ull,0x3434303034783009ull,0x3030783020353138ull,
0x3020303837303032ull,0x3234303030343178ull,0x3030343278302031ull,0x09090a2030383763ull,
0x3630303034317830ull,0x3034327830203532ull,0x7830203038376330ull,0x3931303030303431ull,
0x6330303432783020ull,0x3009090a20303837ull,0x3132303030343178ull,0x3030343278302064ull,
0x3278302030383763ull,0x2035366363303030ull,0x3763303234307830ull,0x783009090a203038ull,
0x6435613032303033ull,0x3030313463783020ull,0x3064783020303837ull,0x3020393032336530ull,
0x3837303063303878ull,0x61783009090a2030ull,0x2039303430303030ull,0x3730303434637830ull,
0x3030657830203038ull,0x7830203134383132ull,0x3038373832303034ull,0x3031783009090a20ull,
0x3020383030613030ull,0x3032613230303178ull,0x3038303378302063ull,0x3678302064663730ull,
0x2038633734303463ull,0x383033783009090aull,0x7830206466373031ull,0x3834316330343436ull,
0x3436303061783020ull,0x3030783020333030ull,0x0a20303030303030ull,0x3030303178300909ull,
0x3078302039303630ull,0x2030383763333034ull,0x3062353030317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3865333031783009ull,0x3630783020393030ull,0x3020663238623235ull,
0x3030383730303178ull,0x6666333078302064ull,0x09090a2037353137ull,0x3032323030657830ull,
0x3030387830203930ull,0x7830203038373030ull,0x3930343030303061ull,0x3430346363783020ull,
0x3009090a20303837ull,0x3634303030306178ull,0x3634383878302039ull,0x3378302030383734ull,
0x2064663533323830ull,0x3730313463367830ull,0x783009090a203863ull,0x3936343330303132ull,
0x3431343430783020ull,0x3031783020303035ull,0x3020393463303030ull,0x3035633034343278ull,
0x31783009090a2030ull,0x2064346530303030ull,0x3563303434327830ull,0x3030317830203030ull,
0x7830203934363030ull,0x3038326330343432ull,0x3031783009090a20ull,0x3020643438303030ull,
0x3832633034343278ull,0x6632303178302030ull,0x3078302031353038ull,0x2066393361666566ull,
0x303031783009090aull,0x7830203535303832ull,0x3765323665666230ull,0x3034313065783020ull,
0x3034783020313434ull,0x0a20303837303430ull,0x6633303178300909ull,0x3078302031353038ull,
0x2033303839336233ull,0x3038653130317830ull,0x6362307830203535ull,0x090a206263626137ull,
0x3034313065783009ull,0x3034783020393034ull,0x3020303837303430ull,0x3430386432303178ull,
0x6663633078302031ull,0x09090a2062623835ull,0x3038663330317830ull,0x6533307830203534ull,
0x7830203730663132ull,0x3135303866323031ull,0x6336616430783020ull,0x3009090a20626233ull,
0x3530383130303178ull,0x3565333078302035ull,0x6578302062646661ull,0x2031343430303130ull,
0x3730353030347830ull,0x783009090a203038ull,0x3135303836323031ull,0x6630366630783020ull,
0x3031783020663038ull,0x3020353530383531ull,0x6537323965333078ull,0x65783009090a2037ull,
0x2031343430303130ull,0x3730353030347830ull,0x3230317830203038ull,0x7830203135303836ull,
0x3736643230663830ull,0x3031783009090a20ull,0x3020353530386131ull,0x6431376365333078ull,
0x3031306578302066ull,0x3478302031343430ull,0x2030383730353030ull,0x323031783009090aull,
0x7830203135303830ull,0x6634393862333130ull,0x3830323031783020ull,0x3330783020353530ull,
0x0a20623130616665ull,0x3031306578300909ull,0x3478302031343430ull,0x2030383730353030ull,
0x3038383030317830ull,0x6431307830203135ull,0x090a206237666133ull,0x3830323031783009ull,
0x3330783020353530ull,0x3020623130613266ull,0x3434303031306578ull,0x3530303478302031ull,
0x09090a2030383730ull,0x3038633230317830ull,0x3631307830203135ull,0x7830206631613363ull,
0x3535303863323031ull,0x3635663330783020ull,0x3009090a20373163ull,0x3434303031306578ull,
0x3530303478302031ull,0x3178302030383730ull,0x2031353038313230ull,0x3930313131307830ull,
0x783009090a203731ull,0x3535303831313031ull,0x3138663330783020ull,0x3065783020333131ull,
0x3020313434303031ull,0x3837303530303478ull,0x31783009090a2030ull,0x2031353038313030ull,
0x3535353535307830ull,0x3130317830206634ull,0x7830203535303835ull,0x3735353561663330ull,
0x3065783009090a20ull,0x3020313434303031ull,0x3837303530303478ull,0x6632303178302030ull,
0x3078302031353038ull,0x2037353535353535ull,0x313031783009090aull,0x7830203535303835ull,
0x3735353563663330ull,0x3030313065783020ull,0x3034783020313434ull,0x0a20303837303530ull,
0x3030303178300909ull,0x3078302031353038ull,0x2033303030303030ull,0x3038303030317830ull,
0x6633307830203535ull,0x090a203330303065ull,0x3030313065783009ull,0x3034783020313434ull,
0x3020303837303530ull,0x3434303031306578ull,0x3030303878302031ull,0x09090a2030383730ull,
0x3032323030657830ull,0x3030347830203930ull,0x7830203038373830ull,0x3534346265333032ull,
0x3030303030783020ull,0x3009090a20663330ull,0x3438663030303178ull,0x3330343078302031ull,
0x3378302030383763ull,0x2035343232343130ull,0x3730303134637830ull,0x783009090a203038ull,
0x3930343030313065ull,0x3034303034783020ull,0x3065783020303837ull,0x3020393034323230ull,
0x3837303030303878ull,0x31783009090a2030ull,0x2033303034363030ull,0x3730303030307830ull,
0x3130337830203038ull,0x7830206466353066ull,0x3863373030313465ull,0x3031783009090a20ull,
0x3020393430383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302064343038ull,
0x2033303030666637ull,0x303031783009090aull,0x7830203930303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3030783020643030ull,0x0a20333030303030ull,0x3231306578300909ull,
0x6578302064663132ull,0x2038643763303130ull,0x3632303030317830ull,0x3034307830206430ull,
0x090a203030316333ull,0x3230303031783009ull,0x3430783020393034ull,0x3020303031633330ull,
0x3030323030306578ull,0x3430303678302039ull,0x09090a2030303531ull,0x6330323030657830ull,
0x3038347830203134ull,0x7830203238373032ull,0x3930303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3030383030303178ull,0x3030303078302064ull,0x3278302033303030ull,
0x2031363033303030ull,0x3734313034307830ull,0x783009090a203038ull,0x3930303232303065ull,
0x3030303063783020ull,0x3033783020303837ull,0x3020646631643831ull,0x6337303132633678ull,
0x65783009090a2038ull,0x2039333430303030ull,0x3738333030367830ull,0x3030657830203038ull,
0x7830203130343032ull,0x3038373030303034ull,0x3032783009090a20ull,0x3020353665323030ull,
0x3837343630343078ull,0x3130303178302030ull,0x3078302033303039ull,0x2030383230303030ull,
0x303031783009090aull,0x7830203330303037ull,0x3038373030303030ull,0x3230303131783020ull,
0x3134783020303132ull,0x0a20343138323430ull,0x6230303478300909ull,0x3078302039303031ull,
0x2032383730303030ull,0x3231613030367830ull,0x3030307830203930ull,0x090a203038373830ull,
0x3030313033783009ull,0x3463783020393034ull,0x3020303837303031ull,0x3030316130303678ull,
0x3030303078302039ull,0x09090a2030383738ull,0x3430303030327830ull,0x3034307830203930ull,
0x7830203038373835ull,0x3930343034303033ull,0x3030313463783020ull,0x3009090a20303837ull,
0x3038633030303278ull,0x3032343078302039ull,0x6478302030383738ull,0x2039333430653030ull,
0x3730303830617830ull,0x783009090a203038ull,0x3930343838303032ull,0x3030303030783020ull,
0x3064783020333030ull,0x3020313034306530ull,0x3837303038306178ull,0x0a7d0a7d090a2031ull,
0x090a7b2065646f63ull,0x5f203d20656d616eull,0x65746e6f4d36315aull,0x6465526f6c726143ull,
0x5f5f343150656375ull,0x566e6f6974704f54ull,0x6c090a6965756c61ull,0x0a30203d206d656dull,
0x203d206d656d7309ull,0x6572090a38323134ull,0x0a3631203d202067ull,0x203d202072616209ull,
0x74736e6f63090a31ull,0x65730909090a7b20ull,0x203d20656d616e67ull,0x09090a74736e6f63ull,
0x206d756e67657309ull,0x0909090a31203d20ull,0x202074657366666full,0x620909090a30203dull,
0x3d20202073657479ull,0x656d09090a323120ull,0x300909090a7b206dull,0x6630303030303078ull,
0x3030303078302066ull,0x3078302066373030ull,0x2066333030303030ull,0x0a7d090a7d09090aull,
0x65646f636e696209ull,0x61783009090a7b20ull,0x2035313030303030ull,0x3730303034307830ull,
0x3830337830203038ull,0x7830203130613030ull,0x3064376330346336ull,0x3061783009090a20ull,
0x3020646631303030ull,0x6337343130633078ull,0x3230306178302038ull,0x3078302033303066ull,
0x2030303030303030ull,0x303031783009090aull,0x7830203131613030ull,0x3038376333303630ull,
0x6632303031783020ull,0x3030783020333030ull,0x0a20303031313030ull,0x3030303178300909ull,
0x3478302031306330ull,0x2030383763303034ull,0x6334313030347830ull,0x3230307830203530ull,
0x090a203038373030ull,0x3030313033783009ull,0x3463783020353032ull,0x3020303837303031ull,
0x3132343030306178ull,0x3032343078302064ull,0x09090a2030383730ull,0x6334303030367830ull,
0x3230307830203530ull,0x7830203038373430ull,0x3931383030303031ull,0x6333303430783020ull,
0x3009090a20303837ull,0x3038303330303378ull,0x3031346378302031ull,0x3378302030383730ull,
0x2035336530333030ull,0x3730303134637830ull,0x783009090a203038ull,0x3530323034303033ull,
0x3030313463783020ull,0x3032783020303837ull,0x3020313330383032ull,0x3830303030303078ull,
0x32783009090a2033ull,0x2064323038303230ull,0x3030303030307830ull,0x3030327830203330ull,
0x7830203933386330ull,0x3038373430323430ull,0x3031783009090a20ull,0x3020313030383030ull,
0x3030303030303078ull,0x3030303178302033ull,0x3078302035303038ull,0x2033303030303030ull,
0x303033783009090aull,0x7830206466646335ull,0x3864376330326336ull,0x3432303061783020ull,
0x3030783020333030ull,0x0a20303030303030ull,0x3230303178300909ull,0x3178302038326138ull,
0x2038303038303030ull,0x3230303030317830ull,0x3036307830206430ull,0x090a203038376333ull,
0x3432303031783009ull,0x3030783020333030ull,0x3020303832313030ull,0x3263303430303378ull,
0x3031346378302031ull,0x09090a2030383730ull,0x6331303030327830ull,0x3034307830206433ull,
0x7830203038373032ull,0x3132653165303064ull,0x3030383038783020ull,0x3009090a20303837ull,
0x3030313030306578ull,0x3030303678302031ull,0x3278302030383730ull,0x2031326539383030ull,
0x3030303030307830ull,0x783009090a203330ull,0x3132303165303064ull,0x3030383038783020ull,
0x3065783020303837ull,0x3020393030313030ull,0x3837383030303678ull,0x32783009090a2030ull,
0x2039323439303030ull,0x3030303030307830ull,0x3030337830203331ull,0x7830206466646361ull,
0x3864373031326336ull,0x3032783009090a20ull,0x3020643365393030ull,0x3031303030303078ull,
0x3130303178302033ull,0x3078302033303062ull,0x2030383231303030ull,0x303030783009090aull,
0x7830203530383130ull,0x3238373030303063ull,0x3030303430783020ull,0x3465783020313030ull,
0x0a20303837303032ull,0x3030343078300909ull,0x6578302031303230ull,0x2030383734303234ull,
0x3631303030307830ull,0x3030637830203530ull,0x090a203038373030ull,0x3030303032783009ull,
0x3430783020353161ull,0x3020303837633130ull,0x3030303030343078ull,0x3032346578302031ull,
0x09090a2030383738ull,0x3230303034307830ull,0x3234657830203130ull,0x7830203038376330ull,
0x6466623030383033ull,0x6330346336783020ull,0x3009090a20386437ull,0x3165383630303278ull,
0x6230303278302038ull,0x3278302063326139ull,0x2031336131303030ull,0x3730333034307830ull,
0x783009090a203038ull,0x3330303231303031ull,0x3130303030783020ull,0x3066783020303832ull,
0x3020313030303030ull,0x3030303030306578ull,0x61783009090a2032ull,0x2033303035613030ull,
0x3030303030307830ull,0x3030317830203030ull,0x7830203130383030ull,0x3038376333303430ull,
0x3031783009090a20ull,0x3020333030356130ull,0x3031303030303078ull,0x3330303078302030ull,
0x6378302035303830ull,0x2030383730303030ull,0x313638783009090aull,0x7830203330656666ull,
0x3030303030303030ull,0x3031383033783020ull,0x6336783020646631ull,0x0a20386337303134ull,
0x3430306178300909ull,0x3078302033303035ull,0x2030303030303030ull,0x3034303134647830ull,
0x3030327830203930ull,0x090a203038373030ull,0x3534303031783009ull,0x3030783020333030ull,
0x3020303832303030ull,0x3030653030393178ull,0x3030393178302038ull,0x09090a2063303265ull,
0x3030323038317830ull,0x3034347830203931ull,0x7830203038376330ull,0x6431323032303831ull,
0x6330303434783020ull,0x3009090a20303837ull,0x3034303030306578ull,0x3130303678302039ull,
0x3078302030383738ull,0x2031303030303038ull,0x3738303234657830ull,0x783009090a203038ull,
0x3130323030303830ull,0x6330323465783020ull,0x3531783020303837ull,0x3020383030663030ull,
0x3032663030353178ull,0x31783009090a2063ull,0x2039313031323034ull,0x3763303034347830ull,
0x3034317830203038ull,0x7830206431323132ull,0x3038376330303434ull,0x3065783009090a20ull,
0x3020393034303030ull,0x3837383130303678ull,0x3030343078302030ull,0x6578302031303031ull,
0x2030383738303234ull,0x303430783009090aull,0x7830203130323130ull,0x3038376330323465ull,
0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,0x6631363878300909ull,
0x3078302033306566ull,0x2030303030303030ull,0x3130323830337830ull,0x3463367830206466ull,
0x090a203863373031ull,0x3635303061783009ull,0x3030783020333030ull,0x3020303030303030ull,
0x3030363530303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x3065303039317830ull,
0x3039317830203830ull,0x7830206330326530ull,0x3931303031303831ull,0x6330303434783020ull,
0x3009090a20303837ull,0x3132303130383178ull,0x3030343478302064ull,0x6578302030383763ull,
0x2039303430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3130303030303830ull,
0x3830323465783020ull,0x3830783020303837ull,0x3020313032303030ull,0x3837633032346578ull,
0x31783009090a2030ull,0x2038303066303035ull,0x3266303035317830ull,0x3034317830206330ull,
0x7830203931303131ull,0x3038376330303434ull,0x3431783009090a20ull,0x3020643132313130ull,
0x3837633030343478ull,0x3030306578302030ull,0x3678302039303430ull,0x2030383738313030ull,
0x303430783009090aull,0x7830203130303130ull,0x3038373830323465ull,0x3130303430783020ull,
0x3465783020313032ull,0x0a20303837633032ull,0x3030306678300909ull,0x6578302031303030ull,
0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,
0x6530303931783009ull,0x3931783020383030ull,0x3020633032653030ull,0x3130383030383178ull,
0x3030343478302039ull,0x09090a2030383763ull,0x3238303038317830ull,0x3034347830206431ull,
0x7830203038376330ull,0x3930343030303065ull,0x3831303036783020ull,0x3009090a20303837ull,
0x3030303030383078ull,0x3032346578302031ull,0x3078302030383738ull,0x2031303230303038ull,
0x3763303234657830ull,0x783009090a203038ull,0x3830306630303531ull,0x6630303531783020ull,
0x3431783020633032ull,0x3020393130393030ull,0x3837633030343478ull,0x31783009090a2030ull,
0x2064313239303034ull,0x3763303034347830ull,0x3030657830203038ull,0x7830203930343030ull,
0x3038373831303036ull,0x3430783009090a20ull,0x3020313030313030ull,0x3837383032346578ull,
0x3030343078302030ull,0x6578302031303231ull,0x2030383763303234ull,0x313638783009090aull,
0x7830203330656666ull,0x3030303030303030ull,0x6530303931783020ull,0x3931783020383030ull,
0x0a20633032653030ull,0x3030383178300909ull,0x3478302039313034ull,0x2030383763303034ull,
0x3234303038317830ull,0x3034347830206431ull,0x090a203038376330ull,0x3030303065783009ull,
0x3036783020393034ull,0x3020303837383130ull,0x3030303030383078ull,0x3032346578302031ull,
0x09090a2030383738ull,0x3230303038307830ull,0x3234657830203130ull,0x7830203038376330ull,
0x3830306630303531ull,0x6630303531783020ull,0x3009090a20633032ull,0x3130353030343178ull,
0x3030343478302039ull,0x3178302030383763ull,0x2064313235303034ull,0x3763303034347830ull,
0x783009090a203038ull,0x3930343030303065ull,0x3831303036783020ull,0x3430783020303837ull,
0x3020313030313030ull,0x3837383032346578ull,0x30783009090a2030ull,0x2031303231303034ull,
0x3763303234657830ull,0x3136387830203038ull,0x7830203330656666ull,0x3030303030303030ull,
0x3931783009090a20ull,0x3020383030653030ull,0x3032653030393178ull,0x3030383178302063ull,
0x3478302039313032ull,0x2030383763303034ull,0x303831783009090aull,0x7830206431323230ull,
0x3038376330303434ull,0x3030303065783020ull,0x3036783020393034ull,0x0a20303837383130ull,
0x3030383078300909ull,0x6578302031303030ull,0x2030383738303234ull,0x3230303038307830ull,
0x3234657830203130ull,0x090a203038376330ull,0x6630303531783009ull,0x3531783020383030ull,
0x3020633032663030ull,0x3130333030343178ull,0x3030343478302039ull,0x09090a2030383763ull,
0x3233303034317830ull,0x3034347830206431ull,0x7830203038376330ull,0x3930343030303065ull,
0x3831303036783020ull,0x3009090a20303837ull,0x3030313030343078ull,0x3032346578302031ull,
0x3078302030383738ull,0x2031303231303034ull,0x3763303234657830ull,0x783009090a203038ull,
0x3330656666313638ull,0x3030303030783020ull,0x3931783020303030ull,0x3020383030653030ull,
0x3032653030393178ull,0x31783009090a2063ull,0x2038313066303039ull,0x3266303039317830ull,
0x3030657830206331ull,0x7830203930343030ull,0x3038373831303036ull,0x3830783009090a20ull,
0x3020313030303030ull,0x3837383032346578ull,0x3030383078302030ull,0x6578302031303230ull,
0x2030383763303234ull,0x303531783009090aull,0x7830203830306630ull,0x6330326630303531ull,
0x3230303431783020ull,0x3434783020393130ull,0x0a20303837633030ull,0x3030343178300909ull,
0x3478302064313232ull,0x2030383763303034ull,0x3430303030657830ull,0x3030367830203930ull,
0x090a203038373831ull,0x3130303430783009ull,0x3465783020313030ull,0x3020303837383032ull,
0x3032313030343078ull,0x3032346578302031ull,0x09090a2030383763ull,0x6566663136387830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3830306530303931ull,0x6530303931783020ull,
0x3009090a20633032ull,0x3138653030393178ull,0x3030393178302038ull,0x6578302063316165ull,
0x2039303430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3130303030303830ull,
0x3830323465783020ull,0x3830783020303837ull,0x3020313032303030ull,0x3837633032346578ull,
0x31783009090a2030ull,0x2038303066303035ull,0x3266303035317830ull,0x3035317830206330ull,
0x7830203831386630ull,0x6331616630303531ull,0x3065783009090a20ull,0x3020393034303030ull,
0x3837383130303678ull,0x3030343078302030ull,0x6578302031303031ull,0x2030383738303234ull,
0x303430783009090aull,0x7830203130323130ull,0x3038376330323465ull,0x6666313638783020ull,
0x3030783020333065ull,0x0a20303030303030ull,0x3030393178300909ull,0x3178302038303065ull,
0x2063303265303039ull,0x3465303039317830ull,0x3039317830203831ull,0x090a206331366530ull,
0x3030303065783009ull,0x3036783020393034ull,0x3020303837383130ull,0x3030303030383078ull,
0x3032346578302031ull,0x09090a2030383738ull,0x3230303038307830ull,0x3234657830203130ull,
0x7830203038376330ull,0x3830306630303531ull,0x6630303531783020ull,0x3009090a20633032ull,
0x3134663030353178ull,0x3030353178302038ull,0x6578302063313666ull,0x2039303430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3130303130303430ull,0x3830323465783020ull,
0x3430783020303837ull,0x3020313032313030ull,0x3837633032346578ull,0x38783009090a2030ull,
0x2033306566663136ull,0x3030303030307830ull,0x3030327830203030ull,0x7830203130303830ull,
0x3331303030303030ull,0x3033783009090a20ull,0x3020646631303038ull,0x6337633034633678ull,
0x3031346478302038ull,0x3278302035303030ull,0x2030383730303030ull,0x303031783009090aull,
0x7830203330303433ull,0x3038323030303030ull,0x3063373033783020ull,0x3436783020646639ull,
0x0a20616337343130ull,0x3030303378300909ull,0x3078302033303030ull,0x2030383230303030ull,
0x6334303030617830ull,0x3234307830203130ull,0x090a203038373030ull,0x3034303033783009ull,
0x3463783020393030ull,0x3020303837303031ull,0x3030313430303178ull,0x3030343478302031ull,
0x09090a2030383763ull,0x3231343030317830ull,0x3034347830203530ull,0x7830203038376330ull,
0x3930343030303132ull,0x3030383730783020ull,0x3009090a20303837ull,0x3034306530306478ull,
0x3038306178302031ull,0x3178302030383730ull,0x2030303066303031ull,0x3266303031317830ull,
0x783009090a203430ull,0x3930343838303032ull,0x3030303030783020ull,0x3064783020333030ull,
0x3020313034306530ull,0x3837303038306178ull,0x0a7d0a7d090a2031ull,0x090a7b2065646f63ull,
0x5f203d20656d616eull,0x7265766e6936315aull,0x72654b444e436573ull,0x6a5f5366506c656eull,
0x3d206d656d6c090aull,0x6d656d73090a3020ull,0x72090a3633203d20ull,0x3532203d20206765ull,
0x3d2020726162090aull,0x736e6f63090a3020ull,0x730909090a7b2074ull,0x3d20656d616e6765ull,
0x090a74736e6f6320ull,0x6d756e6765730909ull,0x09090a31203d2020ull,0x2074657366666f09ull,
0x0909090a30203d20ull,0x2020207365747962ull,0x6d09090a3235203dull,0x0909090a7b206d65ull,
0x6666663030307830ull,0x3030307830206666ull,0x7830206666373030ull,0x6666666666303038ull,
0x3030666633783020ull,0x0909090a20303030ull,0x3061366666337830ull,0x6666667830206539ull,
0x7830203130636666ull,0x3030303030303030ull,0x3030353334783020ull,0x0909090a20303030ull,
0x6266666666667830ull,0x6666667830206263ull,0x7830203030303030ull,0x3130303030303030ull,
0x3030303030783020ull,0x0909090a20303030ull,0x3030386666667830ull,0x0a7d09090a203030ull,
0x636e6962090a7d09ull,0x09090a7b2065646full,0x6463633730337830ull,0x3234367830206466ull,
0x7830203863373830ull,0x6466666363373033ull,0x3830323436783020ull,0x3009090a20386332ull,
0x3063343030306178ull,0x3032343078302035ull,0x6178302030383730ull,0x2031333234303030ull,
0x3730303234307830ull,0x783009090a203038ull,0x3130303030303061ull,0x3030303430783020ull,
0x3031783020303837ull,0x3020333030353032ull,0x3832303030303078ull,0x36783009090a2030ull,
0x2031343831313030ull,0x3730303030367830ull,0x3130337830203038ull,0x7830206466316430ull,
0x3863376330323436ull,0x3033783009090a20ull,0x3020333030303030ull,0x3832303030303078ull,
0x3030306178302030ull,0x3078302035303834ull,0x2030383730303234ull,0x303033783009090aull,
0x7830203130303232ull,0x3038373030313463ull,0x3131343034783020ull,0x3132783020303538ull,
0x0a20383463653030ull,0x3030303278300909ull,0x3078302035343863ull,0x2030383730303234ull,
0x3832323030337830ull,0x3134637830206434ull,0x090a203038373030ull,0x3265303064783009ull,
0x3038783020313034ull,0x3020303837303063ull,0x3130383030303178ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3038303030317830ull,0x6633307830203531ull,0x7830203330303066ull,
0x3930303030303061ull,0x3030343463783020ull,0x3009090a20303837ull,0x6635303430306578ull,
0x3130306578302064ull,0x3178302038633738ull,0x2031303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3530303830303031ull,0x3030303030783020ull,0x3065783020333030ull,
0x3020646635303030ull,0x3431633030306578ull,0x61783009090a2038ull,0x2033303065663130ull,
0x3030303030307830ull,0x3030317830203030ull,0x7830203330306231ull,0x3030313030303030ull,
0x3031783009090a20ull,0x3020313030383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302035303038ull,0x2033303038666666ull,0x313031783009090aull,0x7830203330306566ull,
0x3038373030303030ull,0x3830303031783020ull,0x3030783020313030ull,0x0a20333030303030ull,
0x3030303178300909ull,0x3078302035303038ull,0x2033303030656662ull,0x3038313230317830ull,
0x6561307830203131ull,0x090a206661373431ull,0x3837303031783009ull,0x3330783020353130ull,
0x3020373165616466ull,0x3334303030306578ull,0x3030303678302031ull,0x09090a2030383730ull,
0x3931343030657830ull,0x3130657830206466ull,0x7830203863373430ull,0x3330306466313061ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3030323430303178ull,0x3030303078302033ull,
0x6578302030303130ull,0x2031303831633030ull,0x3730303030387830ull,0x783009090a203038ull,
0x3930303838333031ull,0x3733373530783020ull,0x3031783020373737ull,0x3020643030383932ull,
0x3037393330633078ull,0x31783009090a2066ull,0x2031313038633330ull,0x6333373463307830ull,
0x3130317830206636ull,0x7830203531303832ull,0x3332623434303430ull,0x3031783009090a20ull,
0x3020313230383730ull,0x6138353530323078ull,0x3033303178302037ull,0x3078302035323038ull,
0x2066623039303034ull,0x333031783009090aull,0x7830203931303864ull,0x3735653130373030ull,
0x3866323031783020ull,0x6330783020643130ull,0x0a20666630353330ull,0x3230306578300909ull,
0x3478302039303030ull,0x2030383730313030ull,0x3030383030657830ull,0x3030347830203132ull,
0x090a203038373831ull,0x3865313031783009ull,0x6130783020313130ull,0x3020663361343565ull,
0x3130383033303178ull,0x3330633078302035ull,0x09090a2037643932ull,0x3038633230317830ull,
0x3139307830203931ull,0x7830203330353138ull,0x6431303837313031ull,0x3733303430783020ull,
0x3009090a20373531ull,0x3030303230306578ull,0x3130303478302039ull,0x6578302030383730ull,
0x2031323030383030ull,0x3738313030347830ull,0x783009090a203038ull,0x3131303864303031ull,
0x3832623130783020ull,0x3031783020333236ull,0x3020353130383331ull,0x6430343030343078ull,
0x31783009090a2062ull,0x2039313038643230ull,0x3035353630307830ull,0x3330317830203337ull,
0x7830206431303830ull,0x3732663032306330ull,0x3065783009090a20ull,0x3020393030303230ull,
0x3837303130303478ull,0x3830306578302030ull,0x3478302039313030ull,0x2030383738313030ull,
0x303031783009090aull,0x7830203131303830ull,0x3330303030303030ull,0x3830303031783020ull,
0x3330783020353130ull,0x0a20333030306666ull,0x3230306578300909ull,0x3878302039303831ull,
0x2030383730303030ull,0x3030363030657830ull,0x3030347830203131ull,0x090a203038373031ull,
0x3832303031783009ull,0x3031783020303034ull,0x3020343036383030ull,0x3038383230303178ull,
0x3030303178302038ull,0x09090a2063306138ull,0x3061303430327830ull,0x3030307830203330ull,
0x7830203038373030ull,0x3330306466313031ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6466393130303065ull,0x3031303065783020ull,
0x3061783020386337ull,0x3020333030646431ull,0x3030303030303078ull,0x31783009090a2030ull,
0x2033303034313130ull,0x3130303030307830ull,0x3030317830203030ull,0x7830203130303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020353030383030ull,0x3030306666333078ull,
0x3030306578302033ull,0x3678302039303430ull,0x2030383730303034ull,0x303031783009090aull,
0x7830203130303830ull,0x3330303030303030ull,0x3830303031783020ull,0x3030783020353030ull,
0x0a20333030303030ull,0x3030306578300909ull,0x6578302064663530ull,0x2038633730313030ull,
0x3038303030317830ull,0x3030307830203131ull,0x090a203330303030ull,0x3830303031783009ull,
0x3730783020353130ull,0x3020333030306666ull,0x3034383230303178ull,0x3030303178302030ull,
0x09090a2034303638ull,0x3530343030657830ull,0x3030657830206466ull,0x7830203863323430ull,
0x3330306361303061ull,0x3030303030783020ull,0x3009090a20303030ull,0x3132303030303178ull,
0x3330363078302031ull,0x3178302030383763ull,0x2033303061393030ull,0x3130303030307830ull,
0x783009090a203030ull,0x6466393030383033ull,0x3031343436783020ull,0x3031783020386337ull,
0x3020313063303030ull,0x3035633034343278ull,0x31783009090a2030ull,0x2035306530303030ull,
0x3563303434327830ull,0x3030657830203030ull,0x7830203130343030ull,0x3030353030303038ull,
0x3031783009090a20ull,0x3020393030313030ull,0x3035633034343278ull,0x3030303178302030ull,
0x3278302039306130ull,0x2030383263303434ull,0x313033783009090aull,0x7830206430323034ull,
0x3038373030316365ull,0x3032383064783020ull,0x3430783020353032ull,0x0a20303837303034ull,
0x3138306478300909ull,0x3078302064303630ull,0x2030383730303434ull,0x3230333830647830ull,
0x3434307830203530ull,0x090a203038373430ull,0x3030303032783009ull,0x3430783020353534ull,
0x3020303837633030ull,0x6633303438303378ull,0x3034343678302064ull,0x09090a2038633763ull,
0x3038303030317830ull,0x3030317830203833ull,0x7830206333323832ull,0x6433653130303132ull,
0x3432343430783020ull,0x3009090a20303035ull,0x3561323030313278ull,0x3234343078302035ull,
0x3178302030303538ull,0x2031303038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3530303830303031ull,0x3066663330783020ull,0x3065783020333030ull,0x3020313063313030ull,
0x3837303030303678ull,0x31783009090a2030ull,0x2030303038303030ull,0x3238323030317830ull,
0x3430327830203430ull,0x7830203330306365ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020393030383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302064303038ull,
0x2033303030666662ull,0x303065783009090aull,0x7830203131633130ull,0x3038373830303036ull,
0x3830303031783020ull,0x3031783020383030ull,0x0a20633032383230ull,0x3230306578300909ull,
0x3878302031303830ull,0x2030383730303030ull,0x3030303030657830ull,0x3030367830203931ull,
0x090a203038373030ull,0x3865313031783009ull,0x3330783020313030ull,0x3020336630386561ull,
0x3030386230303178ull,0x6265333078302035ull,0x09090a2033383331ull,0x3038343030317830ull,
0x6238307830203932ull,0x7830203362386137ull,0x6432303835323031ull,0x3064653330783020ull,
0x3009090a20336565ull,0x3263303630306578ull,0x3030303878302031ull,0x6578302030383730ull,
0x2031303031303030ull,0x3738323030347830ull,0x783009090a203038ull,0x3932303866323031ull,
0x3230663930783020ull,0x3031783020373736ull,0x3020643230383632ull,0x3262336665333078ull,
0x65783009090a2037ull,0x2031303031303030ull,0x3738323030347830ull,0x3130317830203038ull,
0x7830203932303836ull,0x3739306261396130ull,0x3031783009090a20ull,0x3020643230386230ull,
0x3534373166333078ull,0x3030306578302066ull,0x3478302031303031ull,0x2030383738323030ull,
0x313031783009090aull,0x7830203932303834ull,0x3731356231643230ull,0x3837303031783020ull,
0x3330783020643230ull,0x0a20663137633366ull,0x3030306578300909ull,0x3478302039323031ull,
0x2030383738323030ull,0x3038643230317830ull,0x3239307830203933ull,0x090a203337656233ull,
0x3834323031783009ull,0x3330783020643330ull,0x3020333934323666ull,0x3063303030306578ull,
0x3130343678302031ull,0x09090a2030383730ull,0x3031613030657830ull,0x3030347830203932ull,
0x7830203038373833ull,0x3933303834303031ull,0x3939393930783020ull,0x3009090a20663361ull,
0x3330383931303178ull,0x3866333078302064ull,0x6578302062393939ull,0x2039323031613030ull,
0x3738333030347830ull,0x783009090a203038ull,0x3933303834313031ull,0x3535353530783020ull,
0x3031783020373535ull,0x3020643330383531ull,0x3535356266333078ull,0x32783009090a2037ull,
0x2035303238303030ull,0x3030313030307830ull,0x3030657830203330ull,0x7830203932303161ull,
0x3038373833303034ull,0x3065783009090a20ull,0x3020313230316130ull,0x3837303030303878ull,
0x3430306578302030ull,0x3478302031306330ull,0x2030383730303034ull,0x303061783009090aull,
0x7830203131613230ull,0x3038373031343434ull,0x3038303065783020ull,0x3038783020313263ull,
0x0a20303837303030ull,0x3030303378300909ull,0x3078302039336161ull,0x2033303030303030ull,
0x3038663230317830ull,0x6566307830203932ull,0x090a206639336166ull,0x3832303031783009ull,
0x3330783020643230ull,0x3020376532366566ull,0x3034303030306578ull,0x3230303478302039ull,
0x09090a2030383730ull,0x6331303030617830ull,0x3434347830203132ull,0x7830203038373031ull,
0x3130383061303065ull,0x3831303034783020ull,0x3009090a20303837ull,0x3230316130306578ull,
0x3030303478302031ull,0x6578302030383730ull,0x2039316330303030ull,0x3730323034367830ull,
0x783009090a203038ull,0x3931343030303065ull,0x3831303836783020ull,0x3031783020303837ull,
0x3020393030386633ull,0x3038393362333078ull,0x31783009090a2033ull,0x2064303038653130ull,
0x6261376333307830ull,0x3030657830206263ull,0x7830203930383032ull,0x3038373831303034ull,
0x3065783009090a20ull,0x3020393030303030ull,0x3837383030303678ull,0x6130303178302030ull,
0x3078302033303063ull,0x2030383730303030ull,0x303031783009090aull,0x7830203130303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3730783020353030ull,0x0a20333030306666ull,
0x3030306578300909ull,0x6578302064663530ull,0x2038633763303130ull,0x3030613030317830ull,
0x3030307830203330ull,0x090a203038323030ull,0x3030303065783009ull,0x3036783020393034ull,
0x3020303837383030ull,0x3030636130303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x3530303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x6635303030306578ull,0x3030306578302064ull,
0x3178302038633738ull,0x2033303037613030ull,0x3130303030307830ull,0x783009090a203030ull,
0x3930303830303031ull,0x3030303030783020ull,0x3031783020333030ull,0x3020643030383030ull,
0x3030306666663078ull,0x31783009090a2033ull,0x2033303063613030ull,0x3730303030307830ull,
0x3030317830203038ull,0x7830203130303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020353030383030ull,0x3030306666373078ull,0x3030306578302033ull,0x6578302064663530ull,
0x2038633738303030ull,0x303031783009090aull,0x7830203930363130ull,0x3030316330343432ull,
0x3130303031783020ull,0x3432783020643038ull,0x0a20303031633034ull,0x3030306178300909ull,
0x6578302031313430ull,0x2032383734303434ull,0x3038303030317830ull,0x3030307830203130ull,
0x090a203330303030ull,0x3830303031783009ull,0x3030783020353030ull,0x3020333030303030ull,
0x6639303030306578ull,0x3130306578302064ull,0x09090a2038633730ull,0x3038303030317830ull,
0x3030307830203931ull,0x7830203330303030ull,0x6431303830303031ull,0x3066663730783020ull,
0x3009090a20333030ull,0x3038383030303178ull,0x3230303178302030ull,0x6578302034306138ull,
0x2064663930363030ull,0x3234303030657830ull,0x783009090a203863ull,0x3330303231313061ull,
0x3030303030783020ull,0x3031783020303030ull,0x3020393132303030ull,0x3837633330343078ull,
0x31783009090a2030ull,0x2033303064663030ull,0x3130303030307830ull,0x3830337830203030ull,
0x7830206466643030ull,0x3863373031343436ull,0x3031783009090a20ull,0x3020313063303030ull,
0x3035633034343278ull,0x3030303178302030ull,0x3278302035306530ull,0x2030303563303434ull,
0x303065783009090aull,0x7830203130383030ull,0x3030353030303038ull,0x3130303031783020ull,
0x3432783020393030ull,0x0a20303035633034ull,0x3030303178300909ull,0x3278302039306130ull,
0x2030383263303434ull,0x3230343130337830ull,0x3163657830206430ull,0x090a203038373030ull,
0x3032383064783009ull,0x3430783020353032ull,0x3020303837303034ull,0x3036303138306478ull,
0x3034343078302064ull,0x09090a2030383730ull,0x3230333830647830ull,0x3434307830203530ull,
0x7830203038373430ull,0x3535343030303032ull,0x6330303430783020ull,0x3009090a20303837ull,
0x6633303438303378ull,0x3034343678302064ull,0x3178302038633763ull,0x2038333038323030ull,
0x3238303030317830ull,0x783009090a206333ull,0x6433653130303132ull,0x3432343430783020ull,
0x3132783020303035ull,0x3020353561323030ull,0x3035383234343078ull,0x31783009090a2030ull,
0x2031303038303030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830203530303830ull,
0x3330303066663330ull,0x3065783009090a20ull,0x3020313063313030ull,0x3837303030303678ull,
0x3230303178302030ull,0x3178302030303038ull,0x2034303238303030ull,0x343032783009090aull,
0x7830203330306365ull,0x3038373030303030ull,0x3830303031783020ull,0x3030783020393030ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302064303038ull,0x2033303030666662ull,
0x6331303030657830ull,0x3030367830203131ull,0x090a203038373830ull,0x3832303031783009ull,
0x3031783020383030ull,0x3020633032383030ull,0x3038303230306578ull,0x3030303878302031ull,
0x09090a2030383730ull,0x3030303030657830ull,0x3030367830203931ull,0x7830203038373030ull,
0x3130303865313031ull,0x3865613330783020ull,0x3009090a20336630ull,0x3030386230303178ull,
0x6265333078302035ull,0x3178302033383331ull,0x2039323038343030ull,0x3861376238307830ull,
0x783009090a203362ull,0x6432303835323031ull,0x3064653330783020ull,0x3065783020336565ull,
0x3020313263303630ull,0x3837303030303878ull,0x65783009090a2030ull,0x2031303031303030ull,
0x3738323030347830ull,0x3230317830203038ull,0x7830203932303866ull,0x3737363230663930ull,
0x3031783009090a20ull,0x3020643230383632ull,0x3262336665333078ull,0x3030306578302037ull,
0x3478302031303031ull,0x2030383738323030ull,0x313031783009090aull,0x7830203932303836ull,
0x3739306261396130ull,0x3862303031783020ull,0x3330783020643230ull,0x0a20663534373166ull,
0x3030306578300909ull,0x3478302031303031ull,0x2030383738323030ull,0x3038343130317830ull,
0x6432307830203932ull,0x090a203731356231ull,0x3837303031783009ull,0x3330783020643230ull,
0x3020663137633366ull,0x3230313030306578ull,0x3230303478302039ull,0x09090a2030383738ull,
0x3038643230317830ull,0x3239307830203933ull,0x7830203337656233ull,0x6433303834323031ull,
0x3236663330783020ull,0x3009090a20333934ull,0x3063303030306578ull,0x3130343678302031ull,
0x6578302030383730ull,0x2039323031613030ull,0x3738333030347830ull,0x783009090a203038ull,
0x3933303834303031ull,0x3939393930783020ull,0x3031783020663361ull,0x3020643330383931ull,
0x3939393866333078ull,0x65783009090a2062ull,0x2039323031613030ull,0x3738333030347830ull,
0x3130317830203038ull,0x7830203933303834ull,0x3735353535353530ull,0x3031783009090a20ull,
0x3020643330383531ull,0x3535356266333078ull,0x3030303278302037ull,0x3078302035303238ull,
0x2033303030313030ull,0x303065783009090aull,0x7830203932303161ull,0x3038373833303034ull,
0x3161303065783020ull,0x3038783020313230ull,0x0a20303837303030ull,0x3430306578300909ull,
0x3478302031306330ull,0x2030383730303034ull,0x6132303030617830ull,0x3434347830203131ull,
0x090a203038373031ull,0x3038303065783009ull,0x3038783020313263ull,0x3020303837303030ull,
0x3361613030303378ull,0x3030303078302039ull,0x09090a2033303030ull,0x3038663230317830ull,
0x6566307830203932ull,0x7830206639336166ull,0x6432303832303031ull,0x3665663330783020ull,
0x3009090a20376532ull,0x3034303030306578ull,0x3230303478302039ull,0x6178302030383730ull,
0x2031326331303030ull,0x3730313434347830ull,0x783009090a203038ull,0x3130383061303065ull,
0x3831303034783020ull,0x3065783020303837ull,0x3020313230316130ull,0x3837303030303478ull,
0x65783009090a2030ull,0x2039316330303030ull,0x3730323034367830ull,0x3030657830203038ull,
0x7830203931343030ull,0x3038373831303836ull,0x3031783009090a20ull,0x3020393030386633ull,
0x3038393362333078ull,0x6531303178302033ull,0x3078302064303038ull,0x2062636261376333ull,
0x303065783009090aull,0x7830203930383032ull,0x3038373831303034ull,0x3030303065783020ull,
0x3036783020313030ull,0x0a20303837383030ull,0x3131303178300909ull,0x3078302033303032ull,
0x2030383730303030ull,0x3038303030317830ull,0x3030307830203130ull,0x090a203330303030ull,
0x3830303031783009ull,0x3730783020353030ull,0x3020333030306666ull,0x6635303030306578ull,
0x3031306578302064ull,0x09090a2038633763ull,0x3034303130317830ull,0x3030307830203330ull,
0x7830203038323030ull,0x3130343030303065ull,0x3830303036783020ull,0x3009090a20303837ull,
0x3030303030306178ull,0x3034346578302031ull,0x3178302030383734ull,0x2033303032313130ull,
0x3730303030307830ull,0x783009090a203038ull,0x3130303830303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020353030383030ull,0x3030303030303078ull,0x65783009090a2033ull,
0x2064663930303030ull,0x3738303030657830ull,0x3130317830203863ull,0x7830203330306230ull,
0x3030313030303030ull,0x3031783009090a20ull,0x3020313030383030ull,0x3030303030303078ull,
0x3030303178302033ull,0x3078302035303038ull,0x2033303030666666ull,0x313031783009090aull,
0x7830203330303231ull,0x3038373030303030ull,0x3830303031783020ull,0x3030783020313030ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302035303038ull,0x2033303030666637ull,
0x3930303030657830ull,0x3030657830206466ull,0x090a203863373830ull,0x3030303031783009ull,
0x3630783020313038ull,0x3020303836633330ull,0x3061303030303178ull,0x3330343078302035ull,
0x09090a2030383663ull,0x3631303030317830ull,0x3434327830203130ull,0x7830203030316330ull,
0x3530383130303031ull,0x6330343432783020ull,0x3009090a20303031ull,0x3030303030306678ull,
0x3030306578302031ull,0x3178302032303030ull,0x2033303064643130ull,0x3730303030307830ull,
0x783009090a203038ull,0x3130303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020353030383030ull,0x3030303030303078ull,0x65783009090a2033ull,0x2064663530303030ull,
0x3730313030657830ull,0x3030317830203863ull,0x7830203131303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020353130383030ull,0x3030306666373078ull,0x3230303178302033ull,
0x3178302030303438ull,0x2034303638303030ull,0x303065783009090aull,0x7830206466353034ull,
0x3863323430303065ull,0x3637313061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x3030303178300909ull,0x3078302031313230ull,0x2030383763333036ull,0x3034363130317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3030383033783009ull,0x3436783020646639ull,
0x3020386337303134ull,0x3063303030303178ull,0x3034343278302031ull,0x09090a2030303563ull,
0x6530303030317830ull,0x3434327830203530ull,0x7830203030356330ull,0x3130343030303065ull,
0x3030303038783020ull,0x3009090a20303035ull,0x3030313030303178ull,0x3034343278302039ull,
0x3178302030303563ull,0x2039306130303030ull,0x3263303434327830ull,0x783009090a203038ull,
0x6430323034313033ull,0x3030316365783020ull,0x3064783020303837ull,0x3020353032303238ull,
0x3837303034343078ull,0x64783009090a2030ull,0x2064303630313830ull,0x3730303434307830ull,
0x3830647830203038ull,0x7830203530323033ull,0x3038373430343430ull,0x3032783009090a20ull,
0x3020353534303030ull,0x3837633030343078ull,0x3438303378302030ull,0x3678302064663330ull,
0x2038633763303434ull,0x303031783009090aull,0x7830203833303830ull,0x6333323832303031ull,
0x3130303132783020ull,0x3430783020643365ull,0x0a20303035343234ull,0x3030313278300909ull,
0x3078302035356132ull,0x2030303538323434ull,0x3038303030317830ull,0x3030307830203130ull,
0x090a203330303030ull,0x3830303031783009ull,0x3330783020353030ull,0x3020333030306666ull,
0x3063313030306578ull,0x3030303678302031ull,0x09090a2030383730ull,0x3038303030317830ull,
0x3030317830203030ull,0x7830203430323832ull,0x3330306365343032ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3030383030303178ull,0x3030303078302039ull,0x3178302033303030ull,
0x2064303038303030ull,0x3030666662307830ull,0x783009090a203330ull,0x3131633130303065ull,
0x3830303036783020ull,0x3031783020303837ull,0x3020383030383030ull,0x3032383230303178ull,
0x65783009090a2063ull,0x2031303830323030ull,0x3730303030387830ull,0x3030657830203038ull,
0x7830203931303030ull,0x3038373030303036ull,0x3031783009090a20ull,0x3020313030386531ull,
0x6630386561333078ull,0x6230303178302033ull,0x3078302035303038ull,0x2033383331626533ull,
0x303031783009090aull,0x7830203932303834ull,0x3362386137623830ull,0x3835323031783020ull,
0x3330783020643230ull,0x0a20336565306465ull,0x3630306578300909ull,0x3878302031326330ull,
0x2030383730303030ull,0x3031303030657830ull,0x3030347830203130ull,0x090a203038373832ull,
0x3866323031783009ull,0x3930783020393230ull,0x3020373736323066ull,0x3230383632303178ull,
0x6665333078302064ull,0x09090a2037326233ull,0x3031303030657830ull,0x3030347830203130ull,
0x7830203038373832ull,0x3932303836313031ull,0x6261396130783020ull,0x3009090a20373930ull,
0x3230386230303178ull,0x3166333078302064ull,0x6578302066353437ull,0x2031303031303030ull,
0x3738323030347830ull,0x783009090a203038ull,0x3932303834313031ull,0x6231643230783020ull,
0x3031783020373135ull,0x3020643230383730ull,0x3137633366333078ull,0x65783009090a2066ull,
0x2039323031303030ull,0x3738323030347830ull,0x3230317830203038ull,0x7830203933303864ull,
0x3337656233323930ull,0x3031783009090a20ull,0x3020643330383432ull,0x3934323666333078ull,
0x3030306578302033ull,0x3678302031306330ull,0x2030383730313034ull,0x303065783009090aull,
0x7830203932303161ull,0x3038373833303034ull,0x3834303031783020ull,0x3930783020393330ull,
0x0a20663361393939ull,0x3931303178300909ull,0x3078302064333038ull,0x2062393939386633ull,
0x3031613030657830ull,0x3030347830203932ull,0x090a203038373833ull,0x3834313031783009ull,
0x3530783020393330ull,0x3020373535353535ull,0x3330383531303178ull,0x6266333078302064ull,
0x09090a2037353535ull,0x3238303030327830ull,0x3030307830203530ull,0x7830203330303031ull,
0x3932303161303065ull,0x3833303034783020ull,0x3009090a20303837ull,0x3230316130306578ull,
0x3030303878302031ull,0x6578302030383730ull,0x2031306330343030ull,0x3730303034347830ull,
0x783009090a203038ull,0x3131613230303061ull,0x3031343434783020ull,0x3065783020303837ull,
0x3020313263303830ull,0x3837303030303878ull,0x33783009090a2030ull,0x2039336161303030ull,
0x3030303030307830ull,0x3230317830203330ull,0x7830203932303866ull,0x6639336166656630ull,
0x3031783009090a20ull,0x3020643230383230ull,0x6532366566333078ull,0x3030306578302037ull,
0x3478302039303430ull,0x2030383730323030ull,0x303061783009090aull,0x7830203132633130ull,
0x3038373031343434ull,0x3061303065783020ull,0x3034783020313038ull,0x0a20303837383130ull,
0x6130306578300909ull,0x3478302031323031ull,0x2030383730303030ull,0x6330303030657830ull,
0x3034367830203931ull,0x090a203038373032ull,0x3030303065783009ull,0x3836783020393134ull,
0x3020303837383130ull,0x3030386633303178ull,0x3362333078302039ull,0x09090a2033303839ull,
0x3038653130317830ull,0x6333307830206430ull,0x7830206263626137ull,0x3930383032303065ull,
0x3831303034783020ull,0x3009090a20303837ull,0x3030303030306578ull,0x3030303678302039ull,
0x3178302030383738ull,0x2033303036373130ull,0x3730303030307830ull,0x783009090a203038ull,
0x3130303830303031ull,0x3030303030783020ull,0x3031783020333030ull,0x3020353030383030ull,
0x3030306666373078ull,0x65783009090a2033ull,0x2064663530303030ull,0x3763303130657830ull,
0x3130317830203863ull,0x7830203330306136ull,0x3038323030303030ull,0x3065783009090a20ull,
0x3020393034303030ull,0x3837383030303678ull,0x3731303178302030ull,0x3078302033303036ull,
0x2030383730303030ull,0x303031783009090aull,0x7830203130303830ull,0x3330303030303030ull,
0x3830303031783020ull,0x3030783020353030ull,0x0a20333030303030ull,0x3030306578300909ull,
0x6578302064663530ull,0x2038633738303030ull,0x3031373130317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3830303031783009ull,0x3030783020393030ull,0x3020333030303030ull,
0x3030383030303178ull,0x6666663078302064ull,0x09090a2033303030ull,0x3036373130317830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3130303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3030383030303178ull,0x6666373078302035ull,0x6578302033303030ull,
0x2064663530303030ull,0x3738303030657830ull,0x783009090a203863ull,0x3930363130303031ull,
0x6330343432783020ull,0x3031783020303031ull,0x3020643038313030ull,0x3031633034343278ull,
0x61783009090a2030ull,0x2031313430303030ull,0x3734303434657830ull,0x3030317830203238ull,
0x7830203130303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020353030383030ull,
0x3030303030303078ull,0x3030306578302033ull,0x6578302064663930ull,0x2038633730313030ull,
0x303031783009090aull,0x7830203931303830ull,0x3330303030303030ull,0x3830303031783020ull,
0x3730783020643130ull,0x0a20333030306666ull,0x3030303178300909ull,0x3178302030303838ull,
0x2034306138323030ull,0x3930363030657830ull,0x3030657830206466ull,0x090a203863323430ull,
0x6364313061783009ull,0x3030783020333030ull,0x3020303030303030ull,0x3132303030303178ull,
0x3330343078302039ull,0x09090a2030383763ull,0x3037633130317830ull,0x3030307830203330ull,
0x7830203030313030ull,0x6466643030383033ull,0x3031343436783020ull,0x3009090a20386337ull,
0x3063303030303178ull,0x3034343278302031ull,0x3178302030303563ull,0x2035306530303030ull,
0x3563303434327830ull,0x783009090a203030ull,0x3130383030303065ull,0x3030303038783020ull,
0x3031783020303035ull,0x3020393030313030ull,0x3035633034343278ull,0x31783009090a2030ull,
0x2039306130303030ull,0x3263303434327830ull,0x3130337830203038ull,0x7830206430323034ull,
0x3038373030316365ull,0x3064783009090a20ull,0x3020353032303238ull,0x3837303034343078ull,
0x3138306478302030ull,0x3078302064303630ull,0x2030383730303434ull,0x383064783009090aull,
0x7830203530323033ull,0x3038373430343430ull,0x3030303032783020ull,0x3430783020353534ull,
0x0a20303837633030ull,0x3438303378300909ull,0x3678302064663330ull,0x2038633763303434ull,
0x3038323030317830ull,0x3030317830203833ull,0x090a206333323830ull,0x3130303132783009ull,
0x3430783020643365ull,0x3020303035343234ull,0x3561323030313278ull,0x3234343078302035ull,
0x09090a2030303538ull,0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,
0x3530303830303031ull,0x3066663330783020ull,0x3009090a20333030ull,0x3063313030306578ull,
0x3030303678302031ull,0x3178302030383730ull,0x2030303038323030ull,0x3238303030317830ull,
0x783009090a203430ull,0x3330306365343032ull,0x3030303030783020ull,0x3031783020303837ull,
0x3020393030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2064303038303030ull,
0x3030666662307830ull,0x3030657830203330ull,0x7830203131633130ull,0x3038373830303036ull,
0x3031783009090a20ull,0x3020383030383230ull,0x3032383030303178ull,0x3230306578302063ull,
0x3878302031303830ull,0x2030383730303030ull,0x303065783009090aull,0x7830203931303030ull,
0x3038373030303036ull,0x3865313031783020ull,0x3330783020313030ull,0x0a20336630386561ull,
0x6230303178300909ull,0x3078302035303038ull,0x2033383331626533ull,0x3038343030317830ull,
0x6238307830203932ull,0x090a203362386137ull,0x3835323031783009ull,0x3330783020643230ull,
0x3020336565306465ull,0x3263303630306578ull,0x3030303878302031ull,0x09090a2030383730ull,
0x3031303030657830ull,0x3030347830203130ull,0x7830203038373832ull,0x3932303866323031ull,
0x3230663930783020ull,0x3009090a20373736ull,0x3230383632303178ull,0x6665333078302064ull,
0x6578302037326233ull,0x2031303031303030ull,0x3738323030347830ull,0x783009090a203038ull,
0x3932303836313031ull,0x6261396130783020ull,0x3031783020373930ull,0x3020643230386230ull,
0x3534373166333078ull,0x65783009090a2066ull,0x2031303031303030ull,0x3738323030347830ull,
0x3130317830203038ull,0x7830203932303834ull,0x3731356231643230ull,0x3031783009090a20ull,
0x3020643230383730ull,0x3137633366333078ull,0x3030306578302066ull,0x3478302039323031ull,
0x2030383738323030ull,0x323031783009090aull,0x7830203933303864ull,0x3337656233323930ull,
0x3834323031783020ull,0x3330783020643330ull,0x0a20333934323666ull,0x3030306578300909ull,
0x3678302031306330ull,0x2030383730313034ull,0x3031613030657830ull,0x3030347830203932ull,
0x090a203038373833ull,0x3834303031783009ull,0x3930783020393330ull,0x3020663361393939ull,
0x3330383931303178ull,0x3866333078302064ull,0x09090a2062393939ull,0x3031613030657830ull,
0x3030347830203932ull,0x7830203038373833ull,0x3933303834313031ull,0x3535353530783020ull,
0x3009090a20373535ull,0x3330383531303178ull,0x6266333078302064ull,0x3278302037353535ull,
0x2035303238303030ull,0x3030313030307830ull,0x783009090a203330ull,0x3932303161303065ull,
0x3833303034783020ull,0x3065783020303837ull,0x3020313230316130ull,0x3837303030303878ull,
0x65783009090a2030ull,0x2031306330343030ull,0x3730303034347830ull,0x3030617830203038ull,
0x7830203131613230ull,0x3038373031343434ull,0x3065783009090a20ull,0x3020313263303830ull,
0x3837303030303878ull,0x3030303378302030ull,0x3078302039336161ull,0x2033303030303030ull,
0x323031783009090aull,0x7830203932303866ull,0x6639336166656630ull,0x3832303031783020ull,
0x3330783020643230ull,0x0a20376532366566ull,0x3030306578300909ull,0x3478302039303430ull,
0x2030383730323030ull,0x6331303030617830ull,0x3434347830203132ull,0x090a203038373031ull,
0x3061303065783009ull,0x3034783020313038ull,0x3020303837383130ull,0x3230316130306578ull,
0x3030303478302031ull,0x09090a2030383730ull,0x6330303030657830ull,0x3034367830203931ull,
0x7830203038373032ull,0x3931343030303065ull,0x3831303836783020ull,0x3009090a20303837ull,
0x3030386633303178ull,0x3362333078302039ull,0x3178302033303839ull,0x2064303038653130ull,
0x6261376333307830ull,0x783009090a206263ull,0x3930383032303065ull,0x3831303034783020ull,
0x3065783020303837ull,0x3020313030303030ull,0x3837383030303678ull,0x31783009090a2030ull,
0x2033303063643130ull,0x3730303030307830ull,0x3030317830203038ull,0x7830203130303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020353030383030ull,0x3030306666373078ull,
0x3030306578302033ull,0x6578302064663530ull,0x2038633763303130ull,0x313031783009090aull,
0x7830203330306563ull,0x3038323030303030ull,0x3030303065783020ull,0x3036783020313034ull,
0x0a20303837383030ull,0x3030306178300909ull,0x6578302031303030ull,0x2030383734303434ull,
0x3063643130317830ull,0x3030307830203330ull,0x090a203038373030ull,0x3830303031783009ull,
0x3030783020313030ull,0x3020333030303030ull,0x3030383030303178ull,0x3030303078302035ull,
0x09090a2033303030ull,0x3930303030657830ull,0x3030657830206466ull,0x7830203863373830ull,
0x3330303564313031ull,0x3030303030783020ull,0x3009090a20303031ull,0x3030383030303178ull,
0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,0x3030666666307830ull,
0x783009090a203330ull,0x3330306364313031ull,0x3030303030783020ull,0x3031783020303837ull,
0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2035303038303030ull,
0x3030666637307830ull,0x3030657830203330ull,0x7830206466393030ull,0x3863373830303065ull,
0x3031783009090a20ull,0x3020313038303030ull,0x3836633330363078ull,0x3030303178302030ull,
0x3078302035306130ull,0x2030383663333034ull,0x303031783009090aull,0x7830203130363130ull,
0x3030316330343432ull,0x3130303031783020ull,0x3432783020353038ull,0x0a20303031633034ull,
0x3030306678300909ull,0x6578302031303030ull,0x2032303030303030ull,0x3030303030667830ull,
0x3030657830203130ull,0x090a203230303030ull,0x3864323031783009ull,0x3030783020313130ull,
0x3020623564323061ull,0x3130383530303178ull,0x3965333078302035ull,0x09090a2066333961ull,
0x3038363130317830ull,0x3037307830203930ull,0x7830203762376239ull,0x6430303835313031ull,
0x3339653330783020ull,0x3009090a20663136ull,0x3130303430306578ull,0x3030303478302031ull,
0x3178302030383738ull,0x2039303038383030ull,0x3835663530307830ull,0x783009090a203332ull,
0x6430303832333031ull,0x3030663330783020ull,0x3065783020626564ull,0x3020313130303430ull,
0x3837383030303478ull,0x31783009090a2030ull,0x2039303038363030ull,0x3839613061307830ull,
0x3230317830203738ull,0x7830206430303865ull,0x3336653933663330ull,0x3065783009090a20ull,
0x3020313130303430ull,0x3837383030303478ull,0x3530303178302030ull,0x3078302039303038ull,
0x2062373665333565ull,0x303031783009090aull,0x7830206430303833ull,0x3736376636663330ull,
0x3034303065783020ull,0x3034783020313130ull,0x0a20303837383030ull,0x3733303178300909ull,
0x3078302039303038ull,0x2033323434653337ull,0x3038643230317830ull,0x6633307830206430ull,
0x090a206265346339ull,0x3034303065783009ull,0x3034783020313130ull,0x3020303837383030ull,
0x3030383630303178ull,0x3636323078302039ull,0x09090a2062363039ull,0x3038373030317830ull,
0x6633307830206430ull,0x7830203335393463ull,0x3131303034303065ull,0x3830303034783020ull,
0x3009090a20303837ull,0x3030383133303178ull,0x3866633078302039ull,0x3178302033316362ull,
0x2064303038363030ull,0x3366656633307830ull,0x783009090a206663ull,0x3930303034303065ull,
0x3830303034783020ull,0x3031783020303837ull,0x3020313130386432ull,0x3330346533633078ull,
0x31783009090a2037ull,0x2035313038323330ull,0x3935646633307830ull,0x3030317830203339ull,
0x7830203931303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643130383030ull,
0x3030303030303078ull,0x3230306578302033ull,0x3478302039303030ull,0x2030383730313030ull,
0x303065783009090aull,0x7830206466393136ull,0x3863373430303065ull,0x3832303031783020ull,
0x3031783020303034ull,0x0a20343036383030ull,0x3030306178300909ull,0x6578302031303430ull,
0x2030383234303434ull,0x3030303030667830ull,0x3030657830203130ull,0x090a203230303030ull,
0x3030303061783009ull,0x3063783020313030ull,0x3020323837343034ull,0x3438323030303278ull,
0x3430343078302031ull,0x09090a2030383730ull,0x3232653030647830ull,0x6330617830203130ull,
0x7830203038373030ull,0x6466316430313033ull,0x3031323436783020ull,0x3009090a20386337ull,
0x3434613331303278ull,0x3131303278302038ull,0x3178302034343661ull,0x2033303065303030ull,
0x3230303030307830ull,0x783009090a203038ull,0x3330303030303033ull,0x3030303030783020ull,
0x3036783020303837ull,0x3020393438313130ull,0x3837303030303678ull,0x33783009090a2030ull,
0x2064663164323130ull,0x3763303234367830ull,0x3030337830203863ull,0x7830203330303030ull,
0x3038323030303030ull,0x3132783009090a20ull,0x3020313030663130ull,0x3030303030303078ull,
0x3030306178302033ull,0x3478302031303030ull,0x2030383730303434ull,0x303031783009090aull,
0x7830203030303832ull,0x3430323830303031ull,0x3430303061783020ull,0x3430783020353338ull,
0x0a20303837303032ull,0x6534303278300909ull,0x3078302033303063ull,0x2030383730303030ull,
0x3831643030347830ull,0x3030307830203535ull,0x090a203038373031ull,0x3232303033783009ull,
0x3463783020393034ull,0x3020303837303031ull,0x3538633030303278ull,0x3032343078302031ull,
0x09090a2030383738ull,0x6132323030337830ull,0x3134637830206434ull,0x7830203038373030ull,
0x3034303832303031ull,0x3830303031783020ull,0x3009090a20343432ull,0x3034613130303278ull,
0x3030303078302031ull,0x6178302033303030ull,0x2031303030303030ull,0x3730303434347830ull,
0x783009090a203038ull,0x3131303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020353130383030ull,0x3030306666333078ull,0x65783009090a2033ull,0x2039303030303130ull,
0x3730303030387830ull,0x3030657830203038ull,0x7830206466353034ull,0x3863373831303065ull,
0x3031783009090a20ull,0x3020313030383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302035303038ull,0x2033303030303030ull,0x303065783009090aull,0x7830206466353030ull,
0x3834316330303065ull,0x3330343061783020ull,0x3030783020333030ull,0x0a20303030303030ull,
0x3232303178300909ull,0x3078302033303030ull,0x2030303130303030ull,0x3038303030317830ull,
0x3030307830203130ull,0x090a203330303030ull,0x3830303031783009ull,0x6630783020353030ull,
0x3020333030386666ull,0x3030333034303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x3530303830303031ull,
0x3065666230783020ull,0x3009090a20333030ull,0x3130383132303178ull,0x3165613078302031ull,
0x3178302066613734ull,0x2035313038373030ull,0x6561646633307830ull,0x783009090a203731ull,
0x3133343030303065ull,0x3030303036783020ull,0x3065783020303837ull,0x3020646639313430ull,
0x6337343031306578ull,0x61783009090a2038ull,0x2033303032303430ull,0x3030303030307830ull,
0x3230317830203030ull,0x7830203330303734ull,0x3030313030303030ull,0x3065783009090a20ull,
0x3020313038316330ull,0x3837303030303878ull,0x3833303178302030ull,0x3078302039303038ull,
0x2037373737333735ull,0x323031783009090aull,0x7830206430303839ull,0x6630373933306330ull,
0x3863333031783020ull,0x6330783020313130ull,0x0a20663663333734ull,0x3231303178300909ull,
0x3078302035313038ull,0x2033326234343034ull,0x3038373030317830ull,0x3032307830203132ull,
0x090a203761383535ull,0x3830333031783009ull,0x3430783020353230ull,0x3020666230393030ull,
0x3130386433303178ull,0x3037303078302039ull,0x09090a2037356531ull,0x3038663230317830ull,
0x3063307830206431ull,0x7830206666303533ull,0x3930303032303065ull,0x3031303034783020ull,
0x3009090a20303837ull,0x3230303830306578ull,0x3130303478302031ull,0x3178302030383738ull,
0x2031313038653130ull,0x6134356561307830ull,0x783009090a206633ull,0x3531303830333031ull,
0x3233306330783020ull,0x3031783020376439ull,0x3020393130386332ull,0x3035313831393078ull,
0x31783009090a2033ull,0x2064313038373130ull,0x3137333034307830ull,0x3030657830203735ull,
0x7830203930303032ull,0x3038373031303034ull,0x3065783009090a20ull,0x3020313230303830ull,
0x3837383130303478ull,0x6430303178302030ull,0x3078302031313038ull,0x2033323638326231ull,
0x313031783009090aull,0x7830203531303833ull,0x6264303430303430ull,0x3864323031783020ull,
0x3030783020393130ull,0x0a20333730353536ull,0x3033303178300909ull,0x3078302064313038ull,
0x2037326630323063ull,0x3030323030657830ull,0x3030347830203930ull,0x090a203038373031ull,
0x3038303065783009ull,0x3034783020393130ull,0x3020303837383130ull,0x3130383030303178ull,
0x3030303078302031ull,0x09090a2033303030ull,0x3038303030317830ull,0x6633307830203531ull,
0x7830203330303066ull,0x3930383132303065ull,0x3030303038783020ull,0x3009090a20303837ull,
0x3130303630306578ull,0x3130303478302031ull,0x3178302030383730ull,0x2030303438323030ull,
0x3638303030317830ull,0x783009090a203430ull,0x3830383832303031ull,0x3830303031783020ull,
0x3032783020633061ull,0x3020333030613034ull,0x3837303030303078ull,0x31783009090a2030ull,
0x2033303032303430ull,0x3730303030307830ull,0x3030317830203038ull,0x7830203130303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020353030383030ull,0x3030303030303078ull,
0x3030306578302033ull,0x6578302064663931ull,0x2038633730313030ull,0x333061783009090aull,
0x7830203330303265ull,0x3030303030303030ull,0x3931333031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303178300909ull,0x3078302031303038ull,0x2033303030303030ull,
0x3038303030317830ull,0x6633307830203530ull,0x090a203330303066ull,0x3030303065783009ull,
0x3436783020393034ull,0x3020303837303030ull,0x3030383030303178ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3038303030317830ull,0x3030307830203530ull,0x7830203330303030ull,
0x6466353030303065ull,0x3031303065783020ull,0x3009090a20386337ull,0x3130383030303178ull,
0x3030303078302031ull,0x3178302033303030ull,0x2035313038303030ull,0x3030666637307830ull,
0x783009090a203330ull,0x3030343832303031ull,0x3830303031783020ull,0x3065783020343036ull,
0x3020646635303430ull,0x6332343030306578ull,0x61783009090a2038ull,0x2033303031623230ull,
0x3030303030307830ull,0x3030317830203030ull,0x7830203131323030ull,0x3038376333303630ull,
0x3031783009090a20ull,0x3020333030663932ull,0x3031303030303078ull,0x3038303378302030ull,
0x3678302064663930ull,0x2038633730313434ull,0x303031783009090aull,0x7830203130633030ull,
0x3030356330343432ull,0x3030303031783020ull,0x3432783020353065ull,0x0a20303035633034ull,
0x3030306578300909ull,0x3878302031303430ull,0x2030303530303030ull,0x3031303030317830ull,
0x3434327830203930ull,0x090a203030356330ull,0x3030303031783009ull,0x3432783020393061ull,
0x3020303832633034ull,0x3032303431303378ull,0x3031636578302064ull,0x09090a2030383730ull,
0x3230323830647830ull,0x3434307830203530ull,0x7830203038373030ull,0x6430363031383064ull,
0x3030343430783020ull,0x3009090a20303837ull,0x3032303338306478ull,0x3034343078302035ull,
0x3278302030383734ull,0x2031363430303030ull,0x3763303034307830ull,0x783009090a203038ull,
0x6466333034383033ull,0x6330343436783020ull,0x3031783020386337ull,0x3020383330383030ull,
0x3332383230303178ull,0x32783009090a2063ull,0x2064336531303031ull,0x3534323434307830ull,
0x3031327830203030ull,0x7830203136303330ull,0x3030353832343430ull,0x3031783009090a20ull,
0x3020313030383030ull,0x3030303030303078ull,0x3030303178302033ull,0x3078302035303038ull,
0x2033303030666633ull,0x303065783009090aull,0x7830203130633130ull,0x3038373030303036ull,
0x3830303031783020ull,0x3031783020303030ull,0x0a20343032383230ull,0x6534303278300909ull,
0x3078302033303063ull,0x2030383730303030ull,0x3038303030317830ull,0x3030307830203930ull,
0x090a203330303030ull,0x3830303031783009ull,0x6230783020643030ull,0x3020333030306666ull,
0x3163313030306578ull,0x3030303678302031ull,0x09090a2030383738ull,0x3038303030317830ull,
0x3030317830203830ull,0x7830206330323832ull,0x3130383032303065ull,0x3030303038783020ull,
0x3009090a20303837ull,0x3130303030306578ull,0x3030303678302039ull,0x3178302030383730ull,
0x2031303038653130ull,0x3038656133307830ull,0x783009090a203366ull,0x3530303862303031ull,
0x3162653330783020ull,0x3031783020333833ull,0x3020393230383430ull,0x6238613762383078ull,
0x31783009090a2033ull,0x2064323038353230ull,0x6530646533307830ull,0x3030657830203365ull,
0x7830203132633036ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030313030ull,
0x3837383230303478ull,0x6632303178302030ull,0x3078302039323038ull,0x2037373632306639ull,
0x323031783009090aull,0x7830206432303836ull,0x3732623366653330ull,0x3130303065783020ull,
0x3034783020313030ull,0x0a20303837383230ull,0x3631303178300909ull,0x3078302039323038ull,
0x2037393062613961ull,0x3038623030317830ull,0x6633307830206432ull,0x090a206635343731ull,
0x3130303065783009ull,0x3034783020313030ull,0x3020303837383230ull,0x3230383431303178ull,
0x3164323078302039ull,0x09090a2037313562ull,0x3038373030317830ull,0x6633307830206432ull,
0x7830206631376333ull,0x3130303130303065ull,0x3832303034783020ull,0x3009090a20303837ull,
0x3230386432303178ull,0x3332393078302039ull,0x3178302033376562ull,0x2064323038343230ull,
0x3432366633307830ull,0x783009090a203339ull,0x3130303130303065ull,0x3832303034783020ull,
0x3031783020303837ull,0x3020393230383430ull,0x3361393939393078ull,0x31783009090a2066ull,
0x2064323038393130ull,0x3939386633307830ull,0x3030657830206239ull,0x7830203130303130ull,
0x3038373832303034ull,0x3031783009090a20ull,0x3020393230383431ull,0x3535353535353078ull,
0x3531303178302037ull,0x3078302064323038ull,0x2037353535626633ull,0x303065783009090aull,
0x7830203932303130ull,0x3038373832303034ull,0x3030303065783020ull,0x3436783020313063ull,
0x0a20303837303130ull,0x3030303278300909ull,0x3078302035303238ull,0x2033303030313030ull,
0x3031613030657830ull,0x3030387830203132ull,0x090a203038373030ull,0x3034303065783009ull,
0x3434783020313063ull,0x3020303837303030ull,0x3130333030306178ull,0x3134343478302031ull,
0x09090a2030383730ull,0x6330383030657830ull,0x3030387830203132ull,0x7830203038373030ull,
0x3933306230303033ull,0x3030303030783020ull,0x3009090a20333030ull,0x3230386632303178ull,
0x6665663078302039ull,0x3178302066393361ull,0x2064323038323030ull,0x3236656633307830ull,
0x783009090a203765ull,0x3930343030303065ull,0x3032303034783020ull,0x3061783020303837ull,
0x3020313263313030ull,0x3837303134343478ull,0x65783009090a2030ull,0x2031303830613030ull,
0x3738313030347830ull,0x3030657830203038ull,0x7830203132303161ull,0x3038373030303034ull,
0x3065783009090a20ull,0x3020393163303030ull,0x3837303230343678ull,0x3030306578302030ull,
0x3678302039313430ull,0x2030383738313038ull,0x333031783009090aull,0x7830203930303866ull,
0x3330383933623330ull,0x3865313031783020ull,0x3330783020643030ull,0x0a20626362613763ull,
0x3230306578300909ull,0x3478302039303830ull,0x2030383738313030ull,0x3030303030657830ull,
0x3030367830203930ull,0x090a203038373830ull,0x3162323031783009ull,0x3030783020333030ull,
0x3020303837303030ull,0x3030383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x6637307830203530ull,0x7830203330303066ull,0x6466353030303065ull,
0x6330313065783020ull,0x3009090a20386337ull,0x3030356132303178ull,0x3030303078302033ull,
0x6578302030383230ull,0x2039303430303030ull,0x3738303030367830ull,0x783009090a203038ull,
0x3330303162323031ull,0x3030303030783020ull,0x3031783020303837ull,0x3020313030383030ull,
0x3030303030303078ull,0x31783009090a2033ull,0x2035303038303030ull,0x3030303030307830ull,
0x3030657830203330ull,0x7830206466353030ull,0x3863373830303065ull,0x3031783009090a20ull,
0x3020333030636132ull,0x3031303030303078ull,0x3030303178302030ull,0x3078302039303038ull,
0x2033303030303030ull,0x303031783009090aull,0x7830206430303830ull,0x3330303066666630ull,
0x3162323031783020ull,0x3030783020333030ull,0x0a20303837303030ull,0x3030303178300909ull,
0x3078302031303038ull,0x2033303030303030ull,0x3038303030317830ull,0x6637307830203530ull,
0x090a203330303066ull,0x3030303065783009ull,0x3065783020646635ull,0x3020386337383030ull,
0x3036313030303178ull,0x3034343278302039ull,0x09090a2030303163ull,0x3831303030317830ull,
0x3434327830206430ull,0x7830203030316330ull,0x3131343030303061ull,0x3430343465783020ull,
0x3009090a20323837ull,0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,
0x2035303038303030ull,0x3030303030307830ull,0x783009090a203330ull,0x6466393030303065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020393130383030ull,0x3030303030303078ull,
0x31783009090a2033ull,0x2064313038303030ull,0x3030666637307830ull,0x3030317830203330ull,
0x7830203030383830ull,0x3430613832303031ull,0x3065783009090a20ull,0x3020646639303630ull,
0x6332343030306578ull,0x3133306178302038ull,0x3078302033303037ull,0x2030303030303030ull,
0x303031783009090aull,0x7830203931323030ull,0x3038376333303430ull,0x3230333031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3038303378300909ull,0x3678302064666430ull,
0x2038633730313434ull,0x6330303030317830ull,0x3434327830203130ull,0x090a203030356330ull,
0x3030303031783009ull,0x3432783020353065ull,0x3020303035633034ull,0x3038303030306578ull,
0x3030303878302031ull,0x09090a2030303530ull,0x3031303030317830ull,0x3434327830203930ull,
0x7830203030356330ull,0x3930613030303031ull,0x6330343432783020ull,0x3009090a20303832ull,
0x3032303431303378ull,0x3031636578302064ull,0x6478302030383730ull,0x2035303230323830ull,
0x3730303434307830ull,0x783009090a203038ull,0x6430363031383064ull,0x3030343430783020ull,
0x3064783020303837ull,0x3020353032303338ull,0x3837343034343078ull,0x32783009090a2030ull,
0x2031363430303030ull,0x3763303034307830ull,0x3830337830203038ull,0x7830206466333034ull,
0x3863376330343436ull,0x3031783009090a20ull,0x3020383330383230ull,0x3332383030303178ull,
0x3030313278302063ull,0x3078302064336531ull,0x2030303534323434ull,0x303132783009090aull,
0x7830203136303330ull,0x3030353832343430ull,0x3830303031783020ull,0x3030783020313030ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302035303038ull,0x2033303030666633ull,
0x6331303030657830ull,0x3030367830203130ull,0x090a203038373030ull,0x3832303031783009ull,
0x3031783020303030ull,0x3020343032383030ull,0x3030636534303278ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3038303030317830ull,0x3030307830203930ull,0x7830203330303030ull,
0x6430303830303031ull,0x3066666230783020ull,0x3009090a20333030ull,0x3163313030306578ull,
0x3030303678302031ull,0x3178302030383738ull,0x2038303038323030ull,0x3238303030317830ull,
0x783009090a206330ull,0x3130383032303065ull,0x3030303038783020ull,0x3065783020303837ull,
0x3020393130303030ull,0x3837303030303678ull,0x31783009090a2030ull,0x2031303038653130ull,
0x3038656133307830ull,0x3030317830203366ull,0x7830203530303862ull,0x3338333162653330ull,
0x3031783009090a20ull,0x3020393230383430ull,0x6238613762383078ull,0x3532303178302033ull,
0x3078302064323038ull,0x2033656530646533ull,0x303065783009090aull,0x7830203132633036ull,
0x3038373030303038ull,0x3130303065783020ull,0x3034783020313030ull,0x0a20303837383230ull,
0x6632303178300909ull,0x3078302039323038ull,0x2037373632306639ull,0x3038363230317830ull,
0x6533307830206432ull,0x090a203732623366ull,0x3130303065783009ull,0x3034783020313030ull,
0x3020303837383230ull,0x3230383631303178ull,0x6139613078302039ull,0x09090a2037393062ull,
0x3038623030317830ull,0x6633307830206432ull,0x7830206635343731ull,0x3130303130303065ull,
0x3832303034783020ull,0x3009090a20303837ull,0x3230383431303178ull,0x3164323078302039ull,
0x3178302037313562ull,0x2064323038373030ull,0x3763336633307830ull,0x783009090a206631ull,
0x3130303130303065ull,0x3832303034783020ull,0x3031783020303837ull,0x3020393230386432ull,
0x3765623332393078ull,0x31783009090a2033ull,0x2064323038343230ull,0x3432366633307830ull,
0x3030657830203339ull,0x7830203130303130ull,0x3038373832303034ull,0x3031783009090a20ull,
0x3020393230383430ull,0x3361393939393078ull,0x3931303178302066ull,0x3078302064323038ull,
0x2062393939386633ull,0x303065783009090aull,0x7830203130303130ull,0x3038373832303034ull,
0x3834313031783020ull,0x3530783020393230ull,0x0a20373535353535ull,0x3531303178300909ull,
0x3078302064323038ull,0x2037353535626633ull,0x3031303030657830ull,0x3030347830203932ull,
0x090a203038373832ull,0x3030303065783009ull,0x3436783020313063ull,0x3020303837303130ull,
0x3032383030303278ull,0x3130303078302035ull,0x09090a2033303030ull,0x3031613030657830ull,
0x3030387830203132ull,0x7830203038373030ull,0x3130633034303065ull,0x3030303434783020ull,
0x3009090a20303837ull,0x3130333030306178ull,0x3134343478302031ull,0x6578302030383730ull,
0x2031326330383030ull,0x3730303030387830ull,0x783009090a203038ull,0x3933306230303033ull,
0x3030303030783020ull,0x3031783020333030ull,0x3020393230386632ull,0x3933616665663078ull,
0x31783009090a2066ull,0x2064323038323030ull,0x3236656633307830ull,0x3030657830203765ull,
0x7830203930343030ull,0x3038373032303034ull,0x3061783009090a20ull,0x3020313263313030ull,
0x3837303134343478ull,0x6130306578302030ull,0x3478302031303830ull,0x2030383738313030ull,
0x303065783009090aull,0x7830203132303161ull,0x3038373030303034ull,0x3030303065783020ull,
0x3436783020393163ull,0x0a20303837303230ull,0x3030306578300909ull,0x3678302039313430ull,
0x2030383738313038ull,0x3038663330317830ull,0x6233307830203930ull,0x090a203330383933ull,
0x3865313031783009ull,0x3330783020643030ull,0x3020626362613763ull,0x3038303230306578ull,
0x3130303478302039ull,0x09090a2030383738ull,0x3030303030657830ull,0x3030367830203130ull,
0x7830203038373830ull,0x3330303731333031ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,
0x3030666637307830ull,0x783009090a203330ull,0x6466353030303065ull,0x6330313065783020ull,
0x3031783020386337ull,0x3020333030393033ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2031303430303030ull,0x3738303030367830ull,0x3030617830203038ull,0x7830203130303030ull,
0x3038373430343465ull,0x3031783009090a20ull,0x3020333030373133ull,0x3837303030303078ull,
0x3030303178302030ull,0x3078302031303038ull,0x2033303030303030ull,0x303031783009090aull,
0x7830203530303830ull,0x3330303030303030ull,0x3030303065783020ull,0x3065783020646639ull,
0x0a20386337383030ull,0x3133303178300909ull,0x3078302033303030ull,0x2030303130303030ull,
0x3038303030317830ull,0x3030307830203130ull,0x090a203330303030ull,0x3830303031783009ull,
0x6630783020353030ull,0x3020333030306666ull,0x3030373133303178ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,
0x3530303830303031ull,0x3066663730783020ull,0x3009090a20333030ull,0x6639303030306578ull,
0x3030306578302064ull,0x3178302038633738ull,0x2031303830303030ull,0x3663333036307830ull,
0x783009090a203038ull,0x3530613030303031ull,0x6333303430783020ull,0x3031783020303836ull,
0x3020313036313030ull,0x3031633034343278ull,0x31783009090a2030ull,0x2035303831303030ull,
0x3163303434327830ull,0x3030667830203030ull,0x7830203130303030ull,0x3230303030303065ull,
0x3031783009090a20ull,0x3020333030326533ull,0x3837303030303078ull,0x3030303178302030ull,
0x3078302031303038ull,0x2033303030303030ull,0x303031783009090aull,0x7830203530303830ull,
0x3330303030303030ull,0x3030303065783020ull,0x3065783020646635ull,0x0a20386337303130ull,
0x3030303178300909ull,0x3078302031313038ull,0x2033303030303030ull,0x3038303030317830ull,
0x6637307830203531ull,0x090a203330303066ull,0x3832303031783009ull,0x3031783020303034ull,
0x3020343036383030ull,0x6635303430306578ull,0x3030306578302064ull,0x09090a2038633234ull,
0x3062373330617830ull,0x3030307830203330ull,0x7830203030303030ull,0x3131323030303031ull,
0x6333303630783020ull,0x3009090a20303837ull,0x3030393633303178ull,0x3030303078302033ull,
0x3378302030303130ull,0x2064663930303830ull,0x3730313434367830ull,0x783009090a203863ull,
0x3130633030303031ull,0x6330343432783020ull,0x3031783020303035ull,0x3020353065303030ull,
0x3035633034343278ull,0x65783009090a2030ull,0x2031303430303030ull,0x3530303030387830ull,
0x3030317830203030ull,0x7830203930303130ull,0x3030356330343432ull,0x3031783009090a20ull,
0x3020393061303030ull,0x3832633034343278ull,0x3431303378302030ull,0x6578302064303230ull,
0x2030383730303163ull,0x383064783009090aull,0x7830203530323032ull,0x3038373030343430ull,
0x3031383064783020ull,0x3430783020643036ull,0x0a20303837303034ull,0x3338306478300909ull,
0x3078302035303230ull,0x2030383734303434ull,0x3430303030327830ull,0x3034307830203136ull,
0x090a203038376330ull,0x3034383033783009ull,0x3436783020646633ull,0x3020386337633034ull,
0x3330383030303178ull,0x3230303178302038ull,0x09090a2063333238ull,0x6531303031327830ull,
0x3434307830206433ull,0x7830203030353432ull,0x3136303330303132ull,0x3832343430783020ull,
0x3009090a20303035ull,0x3030383030303178ull,0x3030303078302031ull,0x3178302033303030ull,
0x2035303038303030ull,0x3030666633307830ull,0x783009090a203330ull,0x3130633130303065ull,
0x3030303036783020ull,0x3031783020303837ull,0x3020303030383030ull,0x3032383230303178ull,
0x32783009090a2034ull,0x2033303063653430ull,0x3730303030307830ull,0x3030317830203038ull,
0x7830203930303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643030383030ull,
0x3030306666623078ull,0x3030306578302033ull,0x3678302031316331ull,0x2030383738303030ull,
0x303031783009090aull,0x7830203830303830ull,0x6330323832303031ull,0x3032303065783020ull,
0x3038783020313038ull,0x0a20303837303030ull,0x3030306578300909ull,0x3678302039313030ull,
0x2030383730303030ull,0x3038653130317830ull,0x6133307830203130ull,0x090a203366303865ull,
0x3862303031783009ull,0x3330783020353030ull,0x3020333833316265ull,0x3230383430303178ull,
0x3762383078302039ull,0x09090a2033623861ull,0x3038353230317830ull,0x6533307830206432ull,
0x7830203365653064ull,0x3132633036303065ull,0x3030303038783020ull,0x3009090a20303837ull,
0x3030313030306578ull,0x3230303478302031ull,0x3178302030383738ull,0x2039323038663230ull,
0x3632306639307830ull,0x783009090a203737ull,0x6432303836323031ull,0x3366653330783020ull,
0x3065783020373262ull,0x3020313030313030ull,0x3837383230303478ull,0x31783009090a2030ull,
0x2039323038363130ull,0x3062613961307830ull,0x3030317830203739ull,0x7830206432303862ull,
0x6635343731663330ull,0x3065783009090a20ull,0x3020313030313030ull,0x3837383230303478ull,
0x3431303178302030ull,0x3078302039323038ull,0x2037313562316432ull,0x303031783009090aull,
0x7830206432303837ull,0x6631376333663330ull,0x3130303065783020ull,0x3034783020313030ull,
0x0a20303837383230ull,0x6432303178300909ull,0x3078302039323038ull,0x2033376562333239ull,
0x3038343230317830ull,0x6633307830206432ull,0x090a203339343236ull,0x3130303065783009ull,
0x3034783020313030ull,0x3020303837383230ull,0x3230383430303178ull,0x3939393078302039ull,
0x09090a2066336139ull,0x3038393130317830ull,0x6633307830206432ull,0x7830206239393938ull,
0x3130303130303065ull,0x3832303034783020ull,0x3009090a20303837ull,0x3230383431303178ull,
0x3535353078302039ull,0x3178302037353535ull,0x2064323038353130ull,0x3535626633307830ull,
0x783009090a203735ull,0x3932303130303065ull,0x3832303034783020ull,0x3065783020303837ull,
0x3020313063303030ull,0x3837303130343678ull,0x32783009090a2030ull,0x2035303238303030ull,
0x3030313030307830ull,0x3030657830203330ull,0x7830203132303161ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313063303430ull,0x3837303030343478ull,0x3030306178302030ull,
0x3478302031313033ull,0x2030383730313434ull,0x303065783009090aull,0x7830203132633038ull,
0x3038373030303038ull,0x6230303033783020ull,0x3030783020393330ull,0x0a20333030303030ull,
0x6632303178300909ull,0x3078302039323038ull,0x2066393361666566ull,0x3038323030317830ull,
0x6633307830206432ull,0x090a203765323665ull,0x3030303065783009ull,0x3034783020393034ull,
0x3020303837303230ull,0x3263313030306178ull,0x3134343478302031ull,0x09090a2030383730ull,
0x3830613030657830ull,0x3030347830203130ull,0x7830203038373831ull,0x3132303161303065ull,
0x3030303034783020ull,0x3009090a20303837ull,0x3163303030306578ull,0x3230343678302039ull,
0x6578302030383730ull,0x2039313430303030ull,0x3738313038367830ull,0x783009090a203038ull,
0x3930303866333031ull,0x3933623330783020ull,0x3031783020333038ull,0x3020643030386531ull,
0x6362613763333078ull,0x65783009090a2062ull,0x2039303830323030ull,0x3738313030347830ull,
0x3030657830203038ull,0x7830203930303030ull,0x3038373830303036ull,0x3031783009090a20ull,
0x3020333030623733ull,0x3837303030303078ull,0x3030303178302030ull,0x3078302031303038ull,
0x2033303030303030ull,0x303031783009090aull,0x7830203530303830ull,0x3330303066663730ull,
0x3030303065783020ull,0x3065783020646635ull,0x0a20386337633031ull,0x3633303178300909ull,
0x3078302033303066ull,0x2030383230303030ull,0x3430303030657830ull,0x3030367830203930ull,
0x090a203038373830ull,0x6237333031783009ull,0x3030783020333030ull,0x3020303837303030ull,
0x3030383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,0x3038303030317830ull,
0x3030307830203530ull,0x7830203330303030ull,0x6466353030303065ull,0x3830303065783020ull,
0x3009090a20386337ull,0x3030363733303178ull,0x3030303078302033ull,0x3178302030303130ull,
0x2039303038303030ull,0x3030303030307830ull,0x783009090a203330ull,0x6430303830303031ull,
0x3066666630783020ull,0x3031783020333030ull,0x3020333030623733ull,0x3837303030303078ull,
0x31783009090a2030ull,0x2031303038303030ull,0x3030303030307830ull,0x3030317830203330ull,
0x7830203530303830ull,0x3330303066663730ull,0x3065783009090a20ull,0x3020646635303030ull,
0x6337383030306578ull,0x3030303178302038ull,0x3278302039303631ull,0x2030303163303434ull,
0x303031783009090aull,0x7830206430383130ull,0x3030316330343432ull,0x3030303061783020ull,
0x3465783020313134ull,0x0a20323837343034ull,0x3030303178300909ull,0x3078302031303038ull,
0x2033303030303030ull,0x3038303030317830ull,0x3030307830203530ull,0x090a203330303030ull,
0x3030303065783009ull,0x3065783020646639ull,0x3020386337303130ull,0x3130383030303178ull,
0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,0x6637307830206431ull,
0x7830203330303066ull,0x3030383830303031ull,0x3832303031783020ull,0x3009090a20343061ull,
0x6639303630306578ull,0x3030306578302064ull,0x6178302038633234ull,0x2033303031653330ull,
0x3030303030307830ull,0x783009090a203030ull,0x3931323030303031ull,0x6333303430783020ull,
0x3031783020303837ull,0x3020333030636333ull,0x3031303030303078ull,0x33783009090a2030ull,
0x2064666430303830ull,0x3730313434367830ull,0x3030317830203863ull,0x7830203130633030ull,
0x3030356330343432ull,0x3031783009090a20ull,0x3020353065303030ull,0x3035633034343278ull,
0x3030306578302030ull,0x3878302031303830ull,0x2030303530303030ull,0x303031783009090aull,
0x7830203930303130ull,0x3030356330343432ull,0x3030303031783020ull,0x3432783020393061ull,
0x0a20303832633034ull,0x3431303378300909ull,0x6578302064303230ull,0x2030383730303163ull,
0x3230323830647830ull,0x3434307830203530ull,0x090a203038373030ull,0x3031383064783009ull,
0x3430783020643036ull,0x3020303837303034ull,0x3032303338306478ull,0x3034343078302035ull,
0x09090a2030383734ull,0x3430303030327830ull,0x3034307830203136ull,0x7830203038376330ull,
0x6466333034383033ull,0x6330343436783020ull,0x3009090a20386337ull,0x3330383230303178ull,
0x3030303178302038ull,0x3278302063333238ull,0x2064336531303031ull,0x3534323434307830ull,
0x783009090a203030ull,0x3136303330303132ull,0x3832343430783020ull,0x3031783020303035ull,
0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2035303038303030ull,
0x3030666633307830ull,0x3030657830203330ull,0x7830203130633130ull,0x3038373030303036ull,
0x3031783009090a20ull,0x3020303030383230ull,0x3032383030303178ull,0x6534303278302034ull,
0x3078302033303063ull,0x2030383730303030ull,0x303031783009090aull,0x7830203930303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x6230783020643030ull,0x0a20333030306666ull,
0x3030306578300909ull,0x3678302031316331ull,0x2030383738303030ull,0x3038323030317830ull,
0x3030317830203830ull,0x090a206330323830ull,0x3032303065783009ull,0x3038783020313038ull,
0x3020303837303030ull,0x3130303030306578ull,0x3030303678302039ull,0x09090a2030383730ull,
0x3038653130317830ull,0x6133307830203130ull,0x7830203366303865ull,0x3530303862303031ull,
0x3162653330783020ull,0x3009090a20333833ull,0x3230383430303178ull,0x3762383078302039ull,
0x3178302033623861ull,0x2064323038353230ull,0x6530646533307830ull,0x783009090a203365ull,
0x3132633036303065ull,0x3030303038783020ull,0x3065783020303837ull,0x3020313030313030ull,
0x3837383230303478ull,0x31783009090a2030ull,0x2039323038663230ull,0x3632306639307830ull,
0x3230317830203737ull,0x7830206432303836ull,0x3732623366653330ull,0x3065783009090a20ull,
0x3020313030313030ull,0x3837383230303478ull,0x3631303178302030ull,0x3078302039323038ull,
0x2037393062613961ull,0x303031783009090aull,0x7830206432303862ull,0x6635343731663330ull,
0x3130303065783020ull,0x3034783020313030ull,0x0a20303837383230ull,0x3431303178300909ull,
0x3078302039323038ull,0x2037313562316432ull,0x3038373030317830ull,0x6633307830206432ull,
0x090a206631376333ull,0x3130303065783009ull,0x3034783020313030ull,0x3020303837383230ull,
0x3230386432303178ull,0x3332393078302039ull,0x09090a2033376562ull,0x3038343230317830ull,
0x6633307830206432ull,0x7830203339343236ull,0x3130303130303065ull,0x3832303034783020ull,
0x3009090a20303837ull,0x3230383430303178ull,0x3939393078302039ull,0x3178302066336139ull,
0x2064323038393130ull,0x3939386633307830ull,0x783009090a206239ull,0x3130303130303065ull,
0x3832303034783020ull,0x3031783020303837ull,0x3020393230383431ull,0x3535353535353078ull,
0x31783009090a2037ull,0x2064323038353130ull,0x3535626633307830ull,0x3030657830203735ull,
0x7830203932303130ull,0x3038373832303034ull,0x3065783009090a20ull,0x3020313063303030ull,
0x3837303130343678ull,0x3030303278302030ull,0x3078302035303238ull,0x2033303030313030ull,
0x303065783009090aull,0x7830203132303161ull,0x3038373030303038ull,0x3034303065783020ull,
0x3434783020313063ull,0x0a20303837303030ull,0x3030306178300909ull,0x3478302031313033ull,
0x2030383730313434ull,0x6330383030657830ull,0x3030387830203132ull,0x090a203038373030ull,
0x6230303033783009ull,0x3030783020393330ull,0x3020333030303030ull,0x3230386632303178ull,
0x6665663078302039ull,0x09090a2066393361ull,0x3038323030317830ull,0x6633307830206432ull,
0x7830203765323665ull,0x3930343030303065ull,0x3032303034783020ull,0x3009090a20303837ull,
0x3263313030306178ull,0x3134343478302031ull,0x6578302030383730ull,0x2031303830613030ull,
0x3738313030347830ull,0x783009090a203038ull,0x3132303161303065ull,0x3030303034783020ull,
0x3065783020303837ull,0x3020393163303030ull,0x3837303230343678ull,0x65783009090a2030ull,
0x2039313430303030ull,0x3738313038367830ull,0x3330317830203038ull,0x7830203930303866ull,
0x3330383933623330ull,0x3031783009090a20ull,0x3020643030386531ull,0x6362613763333078ull,
0x3230306578302062ull,0x3478302039303830ull,0x2030383738313030ull,0x303065783009090aull,
0x7830203130303030ull,0x3038373830303036ull,0x3165333031783020ull,0x3030783020333030ull,
0x0a20303837303030ull,0x3030303178300909ull,0x3078302031303038ull,0x2033303030303030ull,
0x3038303030317830ull,0x6637307830203530ull,0x090a203330303066ull,0x3030303065783009ull,
0x3065783020646635ull,0x3020386337633031ull,0x3030336433303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x3430303030657830ull,0x3030367830203130ull,0x7830203038373830ull,
0x3130303030303061ull,0x3430343465783020ull,0x3009090a20303837ull,0x3030316533303178ull,
0x3030303078302033ull,0x3178302030383730ull,0x2031303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3530303830303031ull,0x3030303030783020ull,0x3065783020333030ull,
0x3020646639303030ull,0x6337383030306578ull,0x31783009090a2038ull,0x2033303061643330ull,
0x3130303030307830ull,0x3030317830203030ull,0x7830203130303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020353030383030ull,0x3030306666663078ull,0x6533303178302033ull,
0x3078302033303031ull,0x2030383730303030ull,0x303031783009090aull,0x7830203130303830ull,
0x3330303030303030ull,0x3830303031783020ull,0x3730783020353030ull,0x0a20333030306666ull,
0x3030306578300909ull,0x6578302064663930ull,0x2038633738303030ull,0x3830303030317830ull,
0x3036307830203130ull,0x090a203038366333ull,0x3030303031783009ull,0x3430783020353061ull,
0x3020303836633330ull,0x3036313030303178ull,0x3034343278302031ull,0x09090a2030303163ull,
0x3831303030317830ull,0x3434327830203530ull,0x7830203030316330ull,0x3130303030303066ull,
0x3030303065783020ull,0x3009090a20323030ull,0x3030303030306678ull,0x3030306578302031ull,
0x3178302032303030ull,0x2031313038643230ull,0x6432306130307830ull,0x783009090a206235ull,
0x3531303835303031ull,0x6139653330783020ull,0x3031783020663339ull,0x3020393030383631ull,
0x6237623930373078ull,0x31783009090a2037ull,0x2064303038353130ull,0x3633396533307830ull,
0x3030657830206631ull,0x7830203131303034ull,0x3038373830303034ull,0x3031783009090a20ull,
0x3020393030383830ull,0x3238356635303078ull,0x3233303178302033ull,0x3078302064303038ull,
0x2062656430306633ull,0x303065783009090aull,0x7830203131303034ull,0x3038373830303034ull,
0x3836303031783020ull,0x6130783020393030ull,0x0a20373838396130ull,0x6532303178300909ull,
0x3078302064303038ull,0x2033366539336633ull,0x3030343030657830ull,0x3030347830203131ull,
0x090a203038373830ull,0x3835303031783009ull,0x6530783020393030ull,0x3020623736653335ull,
0x3030383330303178ull,0x3666333078302064ull,0x09090a2037363766ull,0x3030343030657830ull,
0x3030347830203131ull,0x7830203038373830ull,0x3930303837333031ull,0x3465333730783020ull,
0x3009090a20333234ull,0x3030386432303178ull,0x3966333078302064ull,0x6578302062653463ull,
0x2031313030343030ull,0x3738303030347830ull,0x783009090a203038ull,0x3930303836303031ull,
0x3936363230783020ull,0x3031783020623630ull,0x3020643030383730ull,0x3539346366333078ull,
0x65783009090a2033ull,0x2031313030343030ull,0x3738303030347830ull,0x3330317830203038ull,
0x7830203930303831ull,0x3331636238666330ull,0x3031783009090a20ull,0x3020643030383630ull,
0x6333666566333078ull,0x3430306578302066ull,0x3478302039303030ull,0x2030383738303030ull,
0x323031783009090aull,0x7830203131303864ull,0x3733303465336330ull,0x3832333031783020ull,
0x3330783020353130ull,0x0a20333939356466ull,0x3030303178300909ull,0x3078302039313038ull,
0x2033303030303030ull,0x3038303030317830ull,0x3030307830206431ull,0x090a203330303030ull,
0x3032303065783009ull,0x3034783020393030ull,0x3020303837303130ull,0x6639313630306578ull,
0x3030306578302064ull,0x09090a2038633734ull,0x3438323030317830ull,0x3030317830203030ull,
0x7830203430363830ull,0x3130343030303061ull,0x3430343465783020ull,0x3009090a20303832ull,
0x3030303030306678ull,0x3030306578302031ull,0x6178302032303030ull,0x2031303030303030ull,
0x3734303430637830ull,0x783009090a203238ull,0x3934613230303032ull,0x3834303430783020ull,
0x3064783020303837ull,0x3020313038326530ull,0x3837303063306178ull,0x33783009090a2030ull,
0x2064663164323130ull,0x3730313234367830ull,0x3030327830203863ull,0x7830203135383230ull,
0x3038376334303430ull,0x3031783009090a20ull,0x3020333030323132ull,0x3832303030303078ull,
0x3030303378302030ull,0x3078302033303030ull,0x2030383730303030ull,0x303031783009090aull,
0x7830203131343030ull,0x3038376333303630ull,0x3030303031783020ull,0x3430783020353136ull,
0x0a20303837633330ull,0x3030303178300909ull,0x3078302039313030ull,0x2030383763333036ull,
0x3230303030317830ull,0x3034307830206431ull,0x090a203038376333ull,0x3030303031783009ull,
0x3630783020393230ull,0x3020303837633330ull,0x3232303030303178ull,0x3330343078302064ull,
0x09090a2030383763ull,0x3430303030317830ull,0x3036307830203133ull,0x7830203038376333ull,
0x3533363030303031ull,0x6333303430783020ull,0x3009090a20303837ull,0x3036303431303378ull,
0x3031346578302039ull,0x3178302030383730ull,0x2031303038663330ull,0x3030303030307830ull,
0x783009090a206637ull,0x3930343030303064ull,0x3030303430783020ull,0x3032783020303837ull,
0x3020393334386633ull,0x6666666666663078ull,0x33783009090a2066ull,0x2035303230343130ull,
0x3730303134657830ull,0x3030647830203038ull,0x7830203130323030ull,0x3038373030303430ull,
0x3032783009090a20ull,0x3020643330386633ull,0x6666666666663078ull,0x3030303178302066ull,
0x3078302039353038ull,0x2033303030303030ull,0x333031783009090aull,0x7830203130303865ull,
0x6637303030303030ull,0x3130303033783020ull,0x3436783020646666ull,0x0a20386337383130ull,
0x3030303378300909ull,0x3678302064666431ull,0x2038343138313034ull,0x3032373430617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3237343031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3063303030306178ull,0x3035346378302039ull,0x09090a2030383734ull,
0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x3530303830303031ull,
0x3066663730783020ull,0x3009090a20333030ull,0x6635303030306578ull,0x3030306578302064ull,
0x3178302038633763ull,0x2033303038323430ull,0x3230303030307830ull,0x783009090a203038ull,
0x3130343130303031ull,0x6333303630783020ull,0x3031783020303837ull,0x3020353030383030ull,
0x3030383030303078ull,0x64783009090a2033ull,0x2035303631313030ull,0x3734303034307830ull,
0x3030337830203038ull,0x7830203330303030ull,0x3038373030303030ull,0x3061783009090a20ull,
0x3020393038303030ull,0x3837343035346378ull,0x3030303178302030ull,0x3078302031303038ull,
0x2033303030303030ull,0x303031783009090aull,0x7830203530303830ull,0x3330303066663730ull,
0x3030303065783020ull,0x3065783020646635ull,0x0a20386337633030ull,0x3334303178300909ull,
0x3078302033303031ull,0x2030383230303030ull,0x3831303030317830ull,0x3034307830203130ull,
0x090a203038376333ull,0x3830303031783009ull,0x3030783020353030ull,0x3020333030383030ull,
0x3061313130306478ull,0x3030343078302035ull,0x09090a2030383734ull,0x3030303030337830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3130303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3030383030303178ull,0x3030303078302035ull,0x6578302033303030ull,
0x2031326330303030ull,0x3738303030657830ull,0x783009090a203038ull,0x3130303830303031ull,
0x3030303030783020ull,0x3061783020333030ull,0x3020393063303030ull,0x3837343035346378ull,
0x31783009090a2030ull,0x2035303038303030ull,0x3030303030307830ull,0x3030657830203330ull,
0x7830203130383030ull,0x3038373830303065ull,0x3064783009090a20ull,0x3020313230313030ull,
0x3837303030343078ull,0x3030303178302030ull,0x3078302031303038ull,0x2033303030303030ull,
0x303031783009090aull,0x7830203530303830ull,0x3330303066663730ull,0x3030303065783020ull,
0x3065783020353234ull,0x0a20303837383030ull,0x3030306178300909ull,0x6378302039303830ull,
0x2030383734303534ull,0x3430303030657830ull,0x3030657830203130ull,0x090a203038373830ull,
0x3130303064783009ull,0x3430783020313032ull,0x3020303837303030ull,0x6631313030306478ull,
0x3030343078302064ull,0x09090a2038633734ull,0x3034343430317830ull,0x3030307830203330ull,
0x7830203030313030ull,0x3130303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3030383030303178ull,0x6666663078302035ull,0x3378302033303038ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3132383030303061ull,0x3430353463783020ull,
0x3031783020303837ull,0x3020313030383030ull,0x3030303030303078ull,0x31783009090a2033ull,
0x2035303038303030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830203930303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643030383030ull,0x3030306666373078ull,
0x3230306578302033ull,0x6578302064663131ull,0x2038633738303030ull,0x303065783009090aull,
0x7830206466643030ull,0x3834313830303065ull,0x3135343031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x6430306478300909ull,0x3078302031303631ull,0x2030383738303034ull,
0x3038303030317830ull,0x3038307830203530ull,0x090a203330303030ull,0x3031303064783009ull,
0x3430783020353030ull,0x3020303837303030ull,0x3030383030303178ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3030303030337830ull,0x3030307830203330ull,0x7830203038373030ull,
0x3132633030303061ull,0x3430353463783020ull,0x3009090a20303837ull,0x3030383030303178ull,
0x3030303078302031ull,0x3178302033303030ull,0x2035303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3930303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020643030383030ull,0x3030306666373078ull,0x65783009090a2033ull,0x2064663131323030ull,
0x3738303030657830ull,0x3030657830203863ull,0x7830206466393030ull,0x3834313830303065ull,
0x3031783009090a20ull,0x3020333030303634ull,0x3031303030303078ull,0x6430306478302030ull,
0x3078302031303631ull,0x2030383738303034ull,0x303031783009090aull,0x7830203530303830ull,
0x3330303030303830ull,0x3031303064783020ull,0x3430783020313030ull,0x0a20303837303030ull,
0x3030303178300909ull,0x3078302035303038ull,0x2033303030666637ull,0x3030313030647830ull,
0x3034307830203530ull,0x090a203038373430ull,0x3830303031783009ull,0x3030783020313030ull,
0x3020333030303030ull,0x3030303030303378ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3038303030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x6466663130303033ull,
0x3430306336783020ull,0x3009090a20386337ull,0x3030383634306178ull,0x3030303078302033ull,
0x3178302030303030ull,0x2033303038363430ull,0x3130303030307830ull,0x783009090a203030ull,
0x3130303830303031ull,0x3030303030783020ull,0x3031783020333030ull,0x3020353030383030ull,
0x3030303533343078ull,0x65783009090a2033ull,0x2039326330303030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203935303861ull,0x6666666666666630ull,0x3066783009090a20ull,
0x3020313030303030ull,0x3030303030306578ull,0x3030303178302032ull,0x3078302031303038ull,
0x2033303030303030ull,0x303033783009090aull,0x7830206466643130ull,0x3863373430306336ull,
0x3137343061783020ull,0x3030783020333030ull,0x0a20303030303030ull,0x3734303178300909ull,
0x3078302033303031ull,0x2030303130303030ull,0x3038303030317830ull,0x3030307830203130ull,
0x090a203330303030ull,0x3830303031783009ull,0x3430783020353030ull,0x3020333030303533ull,
0x3338303030306578ull,0x3030303878302031ull,0x09090a2030383730ull,0x6361363330327830ull,
0x3030307830203935ull,0x7830203330303030ull,0x3130303030303066ull,0x3030303065783020ull,
0x3009090a20323030ull,0x3038313030303178ull,0x3330363078302031ull,0x3278302032383763ull,
0x2031336339323030ull,0x6666666666307830ull,0x783009090a203363ull,0x3530383134313033ull,
0x3030313463783020ull,0x3032783020303837ull,0x3020353061313034ull,0x3837343030343078ull,
0x61783009090a2030ull,0x2039303030303030ull,0x3734363430637830ull,0x3030397830203038ull,
0x7830203930343030ull,0x3038373030303030ull,0x3031783009090a20ull,0x3020393134313030ull,
0x3837633330343078ull,0x3230303278302030ull,0x3078302035336539ull,0x2033636666666666ull,
0x303061783009090aull,0x7830203131343030ull,0x3038373030343463ull,0x3830303031783020ull,
0x3030783020393030ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302064303038ull,
0x2033303030666633ull,0x3830303030657830ull,0x3034347830203132ull,0x090a203038373830ull,
0x3138303065783009ull,0x3038783020393330ull,0x3020303837303030ull,0x3238303830306578ull,
0x3130303478302031ull,0x09090a2030383730ull,0x6331383030657830ull,0x3030347830203132ull,
0x7830203038373032ull,0x3930303038303065ull,0x3830303434783020ull,0x3009090a20303837ull,
0x3030313230306578ull,0x3230303478302039ull,0x3378302030383730ull,0x2064316131343130ull,
0x3730303134637830ull,0x783009090a203038ull,0x6431363130343032ull,0x6331303430783020ull,
0x3065783020303837ull,0x3020313163303430ull,0x3837303030303878ull,0x65783009090a2030ull,
0x2039323830303030ull,0x3738313034347830ull,0x3030657830203038ull,0x7830203131343138ull,
0x3038373031303034ull,0x3065783009090a20ull,0x3020313038303030ull,0x3837383130343478ull,
0x3230306578302030ull,0x3478302039313030ull,0x2030383730313030ull,0x303031783009090aull,
0x7830203132653030ull,0x3038376333303630ull,0x3034313033783020ull,0x3465783020643165ull,
0x0a20303837303031ull,0x6633303178300909ull,0x3078302035323038ull,0x2066373030303030ull,
0x6530393030647830ull,0x3034307830206431ull,0x090a203038373030ull,0x3831303032783009ull,
0x6630783020643165ull,0x3020336366666666ull,0x3238313030303378ull,0x3330343078302035ull,
0x09090a2030383734ull,0x6530303030327830ull,0x3034307830203532ull,0x7830203038373432ull,
0x3932323130303032ull,0x3835303430783020ull,0x3009090a20303837ull,0x3234396533303278ull,
0x3030303078302035ull,0x3178302066333030ull,0x2064323038643330ull,0x3030303030307830ull,
0x783009090a206637ull,0x6466333162303033ull,0x6330303436783020ull,0x3061783020386337ull,
0x3020333030396534ull,0x3030303030303078ull,0x31783009090a2030ull,0x2033303063393430ull,
0x3130303030307830ull,0x3030317830203030ull,0x7830203130633030ull,0x3038376333303430ull,
0x3032783009090a20ull,0x3020353034313034ull,0x3837633130343078ull,0x3431303378302030ull,
0x6378302035303230ull,0x2030383730303134ull,0x303032783009090aull,0x7830203530303130ull,
0x3038373430303430ull,0x3965343031783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x6633303178300909ull,0x3078302039313038ull,0x2066333030303030ull,0x3531363030337830ull,
0x3063367830206466ull,0x090a203863373031ull,0x3865343061783009ull,0x3030783020333030ull,
0x3020303030303030ull,0x3030366134303178ull,0x3030303078302033ull,0x09090a2030303130ull,
0x3038303030317830ull,0x3038307830203130ull,0x7830203330303030ull,0x3130303130303064ull,
0x3030303430783020ull,0x3009090a20303837ull,0x3030383030303178ull,0x6666373078302035ull,
0x6478302033303030ull,0x2035303030313030ull,0x3734303034307830ull,0x783009090a203038ull,
0x3130303830303031ull,0x3030303030783020ull,0x3031783020333030ull,0x3020333030386534ull,
0x3837303030303078ull,0x31783009090a2030ull,0x2039313038303030ull,0x3030303038307830ull,
0x3030647830203330ull,0x7830206432303136ull,0x3038373030303430ull,0x3031783009090a20ull,
0x3020393130386330ull,0x6266666666663078ull,0x3630303378302066ull,0x3678302064663531ull,
0x2038633734303063ull,0x343061783009090aull,0x7830203330303765ull,0x3030303030303030ull,
0x6661343031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3030303178300909ull,
0x3078302031303038ull,0x2033303030303030ull,0x3631303030317830ull,0x3036307830203530ull,
0x090a203038376333ull,0x3765343031783009ull,0x3030783020333030ull,0x3020303837303030ull,
0x3230303230306578ull,0x3138303478302031ull,0x09090a2030383730ull,0x3030323030657830ull,
0x3430347830203931ull,0x7830203038373031ull,0x3931303136303065ull,0x3433303065783020ull,
0x3009090a20303837ull,0x3163303030306178ull,0x3130633278302039ull,0x6578302030383734ull,
0x2031303030323030ull,0x3730316330347830ull,0x783009090a203038ull,0x3930303866333031ull,
0x6630303030783020ull,0x3064783020666666ull,0x3020353032303230ull,0x3837303030343078ull,
0x31783009090a2030ull,0x2039303038303030ull,0x3030313030307830ull,0x3030647830203330ull,
0x7830203530323032ull,0x3038373430303430ull,0x3032783009090a20ull,0x3020393034396633ull,
0x3330303030303078ull,0x3030303378302066ull,0x3078302039303438ull,0x2033303030303030ull,
0x323031783009090aull,0x7830206430303830ull,0x3330303030303030ull,0x3033303033783020ull,
0x6336783020646635ull,0x0a20386337383130ull,0x6334306178300909ull,0x3078302033303035ull,
0x2030303030303030ull,0x3035633430317830ull,0x3030307830203330ull,0x090a203030313030ull,
0x3830303031783009ull,0x3030783020643030ull,0x3020333030303030ull,0x3030303330303378ull,
0x3130633678302031ull,0x09090a2030383734ull,0x3030303030617830ull,0x3063327830203130ull,
0x7830203038373431ull,0x3931633030303064ull,0x3430303430783020ull,0x3009090a20303837ull,
0x3032303030303178ull,0x3330343078302031ull,0x3178302030383763ull,0x2035303038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x3930343830323032ull,0x6666666630783020ull,
0x3066783020666666ull,0x3020313030303030ull,0x3030303030306578ull,0x31783009090a2032ull,
0x2064303038303030ull,0x3030303030307830ull,0x3030337830203330ull,0x7830206466353033ull,
0x3863373431306336ull,0x3033783009090a20ull,0x3020643034383032ull,0x3030303030303078ull,
0x3330303378302033ull,0x6378302035313230ull,0x2030383630303034ull,0x303033783009090aull,
0x7830203131303032ull,0x3038363030303465ull,0x3033303033783020ull,0x3463783020643030ull,
0x0a20303836303030ull,0x3530306478300909ull,0x3078302031303830ull,0x2030383634303034ull,
0x3038303030317830ull,0x3030307830203131ull,0x090a203330303030ull,0x3034303033783009ull,
0x6336783020643036ull,0x3020303836343130ull,0x3036303030306178ull,0x3130633278302064ull,
0x09090a2030383634ull,0x6330333030647830ull,0x3034307830203931ull,0x7830203038363430ull,
0x3530323032303033ull,0x3030303465783020ull,0x3009090a20303836ull,0x3030383130303178ull,
0x3030303078302039ull,0x6478302033303030ull,0x2064303030323030ull,0x3730303034307830ull,
0x783009090a203038ull,0x3130303031303033ull,0x3030313465783020ull,0x3033783020303837ull,
0x3020313132306631ull,0x3837303031346378ull,0x64783009090a2030ull,0x2031303030343030ull,
0x3734303034307830ull,0x3030647830203038ull,0x7830203930303032ull,0x3038373030303430ull,
0x3064783009090a20ull,0x3020393063303230ull,0x3837343030343078ull,0x3230306478302030ull,
0x3078302039303630ull,0x2030383730303034ull,0x303033783009090aull,0x7830203530323031ull,
0x3038373030313465ull,0x3830303031783020ull,0x3030783020643030ull,0x0a20333030303030ull,
0x3330303378300909ull,0x3678302064663530ull,0x2038633734313063ull,0x3036653430617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3665343031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030383130303278ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x3030307830203930ull,0x7830203330303030ull,0x6466313032303033ull,
0x3830306336783020ull,0x3009090a20386337ull,0x3030356534306178ull,0x3030303078302033ull,
0x3178302030303030ull,0x2033303035653430ull,0x3130303030307830ull,0x783009090a203030ull,
0x3530323831303032ull,0x3030303030783020ull,0x3066783020333030ull,0x3020313030303030ull,
0x3030303030306578ull,0x64783009090a2032ull,0x2035303230623030ull,0x3734303034307830ull,
0x3030667830203238ull,0x7830203130303030ull,0x3230303030303065ull,0x3066783009090a20ull,
0x3020313030303030ull,0x3030303030306578ull,0x3030306678302032ull,0x6578302031303030ull,
0x2032303030303030ull,0x303033783009090aull,0x7830203330303030ull,0x3038373030303030ull,
0x3030303066783020ull,0x3065783020313030ull,0x0a20303030303030ull,0x3030303178300909ull,
0x3078302039303038ull,0x2033303030666637ull,0x3230323030647830ull,0x3034307830203930ull,
0x090a203038373030ull,0x3034313033783009ull,0x3465783020393534ull,0x3020303837303031ull,
0x3030386433303178ull,0x3030303078302039ull,0x09090a2066373030ull,0x6361663330327830ull,
0x6666307830203532ull,0x7830206666666666ull,0x6466333132303033ull,0x6330303436783020ull,
0x3009090a20386337ull,0x3030313835306178ull,0x3030303078302033ull,0x3178302030303030ull,
0x2039303030303030ull,0x3763333036307830ull,0x783009090a203038ull,0x6430323030303031ull,
0x6333303430783020ull,0x3031783020303837ull,0x3020313232303030ull,0x3837633330363078ull,
0x31783009090a2030ull,0x2033303061313530ull,0x3230303030307830ull,0x3030317830203038ull,
0x7830203131386630ull,0x3038376333303430ull,0x3031783009090a20ull,0x3020353130383030ull,
0x3030306666373078ull,0x3030306178302033ull,0x6378302039313430ull,0x2030383734303534ull,
0x303065783009090aull,0x7830206466393036ull,0x3863373831303065ull,0x6630303031783020ull,
0x3630783020313138ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302035313038ull,
0x2033303030666637ull,0x3031303530317830ull,0x3030307830203330ull,0x090a203038323030ull,
0x3830303031783009ull,0x3030783020353030ull,0x3020333030383030ull,0x3030313130306478ull,
0x3030343078302035ull,0x09090a2030383734ull,0x3031383530317830ull,0x3030307830203330ull,
0x7830203038373030ull,0x6466393036303065ull,0x3830303065783020ull,0x3009090a20386337ull,
0x3030373035303178ull,0x3030303078302033ull,0x3178302030303130ull,0x2031303038303030ull,
0x3030303038307830ull,0x783009090a203330ull,0x3530303130303064ull,0x3030303430783020ull,
0x3031783020303837ull,0x3020313038663030ull,0x3837633330343078ull,0x31783009090a2030ull,
0x2033303031383530ull,0x3730303030307830ull,0x3030317830203038ull,0x7830203131386630ull,
0x3038376333303630ull,0x3031783009090a20ull,0x3020353138663030ull,0x3837633330343078ull,
0x3430306578302030ull,0x6578302064663530ull,0x2038633738303030ull,0x353031783009090aull,
0x7830203330303131ull,0x3030313030303030ull,0x3830303031783020ull,0x3830783020313030ull,
0x0a20333030303030ull,0x3030306478300909ull,0x3078302031303031ull,0x2030383730303034ull,
0x3038303030317830ull,0x6637307830203530ull,0x090a203330303066ull,0x3031303064783009ull,
0x3430783020353030ull,0x3020303837343030ull,0x3038663030303178ull,0x3330363078302031ull,
0x09090a2030383763ull,0x3031383530317830ull,0x3030307830203330ull,0x7830203038373030ull,
0x6466333163373033ull,0x3831306336783020ull,0x3009090a20386337ull,0x3030383135303178ull,
0x3030303078302033ull,0x3178302030383230ull,0x2031303038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x3530303830303031ull,0x3035333430783020ull,0x3065783020333030ull,
0x3020313034303030ull,0x3837303030303878ull,0x31783009090a2030ull,0x2064353038363330ull,
0x3030303030307830ull,0x3530317830203330ull,0x7830203330306231ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020643538663030ull,0x3837633330343078ull,0x3135303178302030ull,
0x3078302033303062ull,0x2030383730303030ull,0x303031783009090aull,0x7830206435386630ull,
0x3038376333303630ull,0x6131303032783020ull,0x6630783020393063ull,0x0a20336366666666ull,
0x3431303378300909ull,0x6378302039303430ull,0x2030383730303134ull,0x3230303430327830ull,
0x3034307830203530ull,0x090a203038373830ull,0x3030303061783009ull,0x3063783020393030ull,
0x3020303837343634ull,0x3134303030303978ull,0x3030303078302039ull,0x09090a2030383730ull,
0x3038303030317830ull,0x3030307830203930ull,0x7830203330303030ull,0x6430303830303031ull,
0x3066663330783020ull,0x3009090a20333030ull,0x3130303030306178ull,0x3034346578302031ull,
0x6178302030383734ull,0x2031306330303030ull,0x3730303434637830ull,0x783009090a203038ull,
0x3931383030303065ull,0x3830303034783020ull,0x3065783020303837ull,0x3020393263303030ull,
0x3837303030303478ull,0x65783009090a2030ull,0x2031326330363030ull,0x3730303030387830ull,
0x3030657830203038ull,0x7830203932303161ull,0x3038373832303034ull,0x3065783009090a20ull,
0x3020313238306130ull,0x3837383030303478ull,0x3830306578302030ull,0x3478302031323431ull,
0x2030383738323030ull,0x303065783009090aull,0x7830203130633061ull,0x3038373030303034ull,
0x3030303065783020ull,0x3034783020313138ull,0x0a20303837383030ull,0x3030303178300909ull,
0x3078302039313038ull,0x2033303030666637ull,0x3830383030657830ull,0x3030347830203930ull,
0x090a203038373030ull,0x3036303064783009ull,0x3430783020393136ull,0x3020303837303030ull,
0x3163303431303378ull,0x3031346578302039ull,0x09090a2030383730ull,0x6332303030337830ull,
0x3034307830206431ull,0x7830203038373831ull,0x6432653030303032ull,0x6335303430783020ull,
0x3009090a20303837ull,0x3230386433303178ull,0x3030303078302039ull,0x3278302066373030ull,
0x2064313639653330ull,0x3030303030307830ull,0x783009090a206633ull,0x6466663061303033ull,
0x3031303436783020ull,0x3061783020386337ull,0x3020333030303835ull,0x3030303030303078ull,
0x31783009090a2030ull,0x2033303064333530ull,0x3230303030307830ull,0x3430327830203038ull,
0x7830203130363130ull,0x3038373831303430ull,0x3032783009090a20ull,0x3020313030386633ull,
0x3330303030303078ull,0x3431303378302066ull,0x6378302031303030ull,0x2030383730303134ull,
0x303032783009090aull,0x7830203530363030ull,0x3038373030303430ull,0x3030303031783020ull,
0x3430783020313034ull,0x0a20303837633330ull,0x3835303178300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x3038663330317830ull,0x3030307830203930ull,0x090a206633303030ull,
0x3132303033783009ull,0x6336783020646637ull,0x3020386337633030ull,0x3030363435303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x3038303030317830ull,0x3038307830203130ull,
0x7830203330303030ull,0x3130363030303064ull,0x3030303430783020ull,0x3009090a20303837ull,
0x3030383030303178ull,0x6666373078302035ull,0x6478302033303030ull,0x2035303030313030ull,
0x3734303034307830ull,0x783009090a203038ull,0x3130386630303031ull,0x6333303630783020ull,
0x3031783020303837ull,0x3020333030303835ull,0x3837303030303078ull,0x31783009090a2030ull,
0x2039303038633030ull,0x6666666666307830ull,0x3030317830206662ull,0x7830203931303830ull,
0x3330303030303830ull,0x3033783009090a20ull,0x3020646637313230ull,0x6337383130633678ull,
0x3630306478302038ull,0x3078302039323630ull,0x2030383730303034ull,0x353031783009090aull,
0x7830203330306534ull,0x3038323030303030ull,0x6630303031783020ull,0x3430783020313038ull,
0x0a20303837633330ull,0x3030303178300909ull,0x3078302035303431ull,0x2030383763333036ull,
0x3030383530317830ull,0x3030307830203330ull,0x090a203038373030ull,0x3038303065783009ull,
0x3034783020393038ull,0x3020303837303034ull,0x3138303830306578ull,0x3038303478302039ull,
0x09090a2030383730ull,0x3830383030657830ull,0x6330347830203130ull,0x7830203038373030ull,
0x3131303866333031ull,0x6630303030783020ull,0x3009090a20666666ull,0x3132303430306478ull,
0x3030343078302035ull,0x3378302030383730ull,0x2035303639313030ull,0x6666666666307830ull,
0x783009090a203363ull,0x3132303830303031ull,0x3031303030783020ull,0x3031783020333030ull,
0x3020313130386631ull,0x3030303030303078ull,0x65783009090a2033ull,0x2064303430363030ull,
0x3734313030657830ull,0x3030647830203038ull,0x7830203930613038ull,0x3038373430303430ull,
0x3033783009090a20ull,0x3020646633303430ull,0x6337633030633678ull,0x3635306178302038ull,
0x3078302033303032ull,0x2030303030303030ull,0x303061783009090aull,0x7830203131363030ull,
0x3038373431306332ull,0x3236353031783020ull,0x3030783020333030ull,0x0a20303832303030ull,
0x6337303378300909ull,0x3678302031303030ull,0x2030383734313063ull,0x3030303030617830ull,
0x3063327830203130ull,0x090a203038373431ull,0x3030303064783009ull,0x3430783020313138ull,
0x3020303837343030ull,0x3032383032303278ull,0x6666663078302035ull,0x09090a2066666666ull,
0x3430303030317830ull,0x3034307830203130ull,0x7830203038376333ull,0x3930386630303031ull,
0x6333303630783020ull,0x3009090a20303837ull,0x6633306337303378ull,0x3030633678302064ull,
0x6178302061633738ull,0x2033303065363530ull,0x3030303030307830ull,0x783009090a203030ull,
0x3330306536353031ull,0x3030303030783020ull,0x3033783020303832ull,0x3020643032383032ull,
0x3030303030303078ull,0x33783009090a2033ull,0x2035313030333030ull,0x3730303034637830ull,
0x3730337830203038ull,0x7830203531613063ull,0x3038373431306336ull,0x3033783009090a20ull,
0x3020393134303330ull,0x3837303030346378ull,0x3130303378302030ull,0x6578302031303030ull,
0x2030383730303034ull,0x303061783009090aull,0x7830206430613030ull,0x3038373431306332ull,
0x3031303033783020ull,0x3465783020393034ull,0x0a20303837303030ull,0x3630306478300909ull,
0x3078302031303030ull,0x2030383734303034ull,0x3830333030647830ull,0x3034307830203131ull,
0x090a203038373430ull,0x3031303033783009ull,0x3465783020353030ull,0x3020323837303031ull,
0x3034306631303378ull,0x3031346378302064ull,0x09090a2030383730ull,0x3230333030647830ull,
0x3034307830206430ull,0x7830203038373430ull,0x3530303831303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3136303130306478ull,0x3030343078302035ull,0x6478302030383730ull,
0x2031303030313030ull,0x3730303034307830ull,0x783009090a203038ull,0x3530383035303064ull,
0x3430303430783020ull,0x3064783020303837ull,0x3020646631303130ull,0x6337303030343078ull,
0x61783009090a2038ull,0x2033303065373530ull,0x3030303030307830ull,0x3030337830203030ull,
0x7830203130343031ull,0x3038373030313465ull,0x3031783009090a20ull,0x3020333030653735ull,
0x3031303030303078ull,0x3130303178302030ull,0x3078302035303038ull,0x2033303030303030ull,
0x303032783009090aull,0x7830206430363030ull,0x3063373430303430ull,0x3831303032783020ull,
0x3030783020353030ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302035303030ull,
0x2030383663333034ull,0x3230303030317830ull,0x3036307830203130ull,0x090a203038376333ull,
0x3130303064783009ull,0x3430783020353034ull,0x3020323837343030ull,0x3036303030303178ull,
0x3330343078302031ull,0x09090a2030383763ull,0x3030303030667830ull,0x3030657830203130ull,
0x7830203230303030ull,0x3130303030303066ull,0x3030303065783020ull,0x3009090a20323030ull,
0x3030303030303378ull,0x3030303078302033ull,0x6678302030383730ull,0x2031303030303030ull,
0x3030303030657830ull,0x7d0a7d090a203130ull,0x0a7b2065646f630aull,0x203d20656d616e09ull,
0x746e6f4d37325a5full,0x6e4f6f6c72614365ull,0x65506b636f6c4265ull,0x506e6f6974704f72ull,
0x6d656d6c090a6966ull,0x6d73090a30203d20ull,0x323134203d206d65ull,0x2020676572090a38ull,
0x6162090a3033203dull,0x090a31203d202072ull,0x0a7b2074736e6f63ull,0x616e676573090909ull,
0x6e6f63203d20656dull,0x65730909090a7473ull,0x203d20206d756e67ull,0x66666f0909090a31ull,
0x30203d2020746573ull,0x657479620909090aull,0x3434203d20202073ull,0x7b206d656d09090aull,
0x303078300909090aull,0x3020666630303030ull,0x3139343738306378ull,0x3638303478302031ull,
0x6678302032346532ull,0x2033306366666666ull,0x303078300909090aull,0x3020663730303030ull,
0x3330303030303078ull,0x3030303078302066ull,0x3478302030303030ull,0x2030303030303030ull,
0x303078300909090aull,0x3020373330303030ull,0x3030303030303078ull,0x3039633378302030ull,
0x09090a2030303030ull,0x6962090a7d090a7dull,0x0a7b2065646f636eull,0x3030306178300909ull,
0x3078302064353030ull,0x2030383730303034ull,0x6532303830337830ull,0x3463367830203130ull,
0x090a203064376330ull,0x3030303061783009ull,0x6330783020646631ull,0x3020386337343130ull,
0x3030663730306178ull,0x3030303078302033ull,0x09090a2030303030ull,0x6532303030317830ull,
0x3036307830203135ull,0x7830203038376333ull,0x3330306637303031ull,0x3130303030783020ull,
0x3009090a20303031ull,0x3063343030306178ull,0x3032343078302031ull,0x6178302030383730ull,
0x2039353234303030ull,0x3730303234307830ull,0x783009090a203038ull,0x3530303035303030ull,
0x3030303063783020ull,0x3033783020303837ull,0x3020313038323330ull,0x3837303031346378ull,
0x31783009090a2030ull,0x2039363832303030ull,0x3763333034307830ull,0x3030337830203038ull,
0x7830203535633233ull,0x3038373030313463ull,0x3032783009090a20ull,0x3020353630383032ull,
0x3830303030303078ull,0x3032303278302033ull,0x3078302031363038ull,0x2033303030303030ull,
0x303431783009090aull,0x7830203931383030ull,0x3038376330303432ull,0x3030303431783020ull,
0x3432783020643161ull,0x0a20303837633030ull,0x3030343178300909ull,0x3278302031326330ull,
0x2030383763303034ull,0x6530303034317830ull,0x3034327830203532ull,0x090a203038376330ull,
0x3030303431783009ull,0x3432783020393234ull,0x3020303837633030ull,0x3236303030343178ull,
0x3030343278302064ull,0x09090a2030383763ull,0x3030303034317830ull,0x3034327830203133ull,
0x7830203038376330ull,0x3533323030303431ull,0x6330303432783020ull,0x3009090a20303837ull,
0x3030383030303178ull,0x3030303078302039ull,0x3178302033303030ull,0x2064303038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6466646337313033ull,0x6330326336783020ull,
0x3061783020386437ull,0x3020333030343730ull,0x3030303030303078ull,0x31783009090a2030ull,
0x2063366561323030ull,0x3438303030317830ull,0x3030317830203030ull,0x7830203530363030ull,
0x3038376333303630ull,0x3031783009090a20ull,0x3020333030343730ull,0x3832313030303078ull,
0x3230303378302030ull,0x6378302031313433ull,0x2030383730303134ull,0x303032783009090aull,
0x7830203137386330ull,0x3038373031323430ull,0x3365303064783020ull,0x3038783020313138ull,
0x0a20303837303063ull,0x3030306178300909ull,0x6378302031313830ull,0x2030383730303434ull,
0x3031343030657830ull,0x3030347830203933ull,0x090a203038373831ull,0x3930303031783009ull,
0x3031783020303163ull,0x3020343165393230ull,0x6662303138303378ull,0x3034633678302064ull,
0x09090a2038643734ull,0x6230323830337830ull,0x3434367830206466ull,0x7830203835316430ull,
0x3330306136303061ull,0x3030303030783020ull,0x3009090a20303030ull,0x3161303030303178ull,
0x3330343078302031ull,0x3178302030383763ull,0x2033303031363030ull,0x3131303030307830ull,
0x783009090a203030ull,0x3131303865333031ull,0x6232353630783020ull,0x3031783020663238ull,
0x3020353130383730ull,0x3531376666333078ull,0x65783009090a2037ull,0x2031316331343030ull,
0x3730303030387830ull,0x3030617830203038ull,0x7830203131383030ull,0x3038373430346363ull,
0x3061783009090a20ull,0x3020353738303030ull,0x3837343634383878ull,0x3338303378302030ull,
0x3678302064666233ull,0x2038643730313463ull,0x303132783009090aull,0x7830203537613330ull,
0x3030353132343430ull,0x3130303031783020ull,0x3432783020313432ull,0x0a20303035643034ull,
0x3030303178300909ull,0x3278302035343431ull,0x2030303564303434ull,0x6330303030317830ull,
0x3434327830203134ull,0x090a203038326430ull,0x3030303031783009ull,0x3432783020353465ull,
0x3020303832643034ull,0x3430386632303178ull,0x6665663078302039ull,0x09090a2066393361ull,
0x3038323030317830ull,0x6662307830206434ull,0x7830203765323665ull,0x3933383032313065ull,
0x3833303034783020ull,0x3009090a20303837ull,0x3430386633303178ull,0x3362333078302039ull,
0x3178302033303839ull,0x2064343038653130ull,0x6261376362307830ull,0x783009090a206263ull,
0x3131383032313065ull,0x3833303034783020ull,0x3031783020303837ull,0x3020393330386432ull,
0x6238356663633078ull,0x31783009090a2062ull,0x2064333038663330ull,0x6631326533307830ull,
0x3230317830203730ull,0x7830203934303866ull,0x6262336336616430ull,0x3031783009090a20ull,
0x3020643430383130ull,0x6466613565333078ull,0x6530306578302062ull,0x3478302039333830ull,
0x2030383738343030ull,0x323031783009090aull,0x7830203934303836ull,0x6630386630366630ull,
0x3835313031783020ull,0x3330783020643430ull,0x0a20376537323965ull,0x6530306578300909ull,
0x3478302039333830ull,0x2030383738343030ull,0x3038363230317830ull,0x6638307830203934ull,
0x090a203736643230ull,0x3861313031783009ull,0x3330783020643430ull,0x3020666431376365ull,
0x3338306530306578ull,0x3430303478302039ull,0x09090a2030383738ull,0x3038303230317830ull,
0x3331307830203934ull,0x7830206634393862ull,0x6434303830323031ull,0x6166653330783020ull,
0x3009090a20623130ull,0x3338306530306578ull,0x3430303478302039ull,0x3178302030383738ull,
0x2039343038383030ull,0x6661336431307830ull,0x783009090a206237ull,0x6434303830323031ull,
0x6132663330783020ull,0x3065783020623130ull,0x3020393338306530ull,0x3837383430303478ull,
0x31783009090a2030ull,0x2039343038633230ull,0x6133633631307830ull,0x3230317830206631ull,
0x7830206434303863ull,0x3731633635663330ull,0x3065783009090a20ull,0x3020393338306530ull,
0x3837383430303478ull,0x3132303178302030ull,0x3078302039343038ull,0x2037313930313131ull,
0x313031783009090aull,0x7830206434303831ull,0x3331313138663330ull,0x3065303065783020ull,
0x3034783020393338ull,0x0a20303837383430ull,0x3130303178300909ull,0x3078302039343038ull,
0x2066343535353535ull,0x3038353130317830ull,0x6633307830206434ull,0x090a203735353561ull,
0x3065303065783009ull,0x3034783020393338ull,0x3020303837383430ull,0x3430386632303178ull,
0x3535353078302039ull,0x09090a2037353535ull,0x3038353130317830ull,0x6633307830206434ull,
0x7830203735353563ull,0x3933383065303065ull,0x3834303034783020ull,0x3009090a20303837ull,
0x3430383030303178ull,0x3030303078302039ull,0x3178302033303030ull,0x2064343038303030ull,
0x3030656633307830ull,0x783009090a203330ull,0x3933383065303065ull,0x3834303034783020ull,
0x3065783020303837ull,0x3020393338306530ull,0x3837303030303878ull,0x65783009090a2030ull,
0x2031316331343030ull,0x3730313030347830ull,0x3330327830203038ull,0x7830206433616265ull,
0x6633303030303030ull,0x3031783009090a20ull,0x3020393338663030ull,0x3837633330363078ull,
0x3431303378302030ull,0x6378302064336531ull,0x2030383730303134ull,0x303065783009090aull,
0x7830203131383065ull,0x3038373833303034ull,0x3234303065783020ull,0x3038783020313130ull,
0x0a20303837303030ull,0x3630303178300909ull,0x3078302033303061ull,0x2030383730303030ull,
0x3930663130337830ull,0x3134657830206466ull,0x090a203864373030ull,0x3830303031783009ull,
0x3030783020313430ull,0x3020333030303030ull,0x3430383030303178ull,0x6666373078302035ull,
0x09090a2033303030ull,0x3038303030317830ull,0x3030307830203131ull,0x7830203330303030ull,
0x3531303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x6664313031306578ull,
0x3031306578302064ull,0x3178302038653763ull,0x2035313232303030ull,0x3164333034307830ull,
0x783009090a203030ull,0x3131303230303031ull,0x6433303430783020ull,0x3065783020303031ull,
0x3020313163313030ull,0x3035613330303678ull,0x65783009090a2030ull,0x2039333831343030ull,
0x3738323038347830ull,0x3030317830203238ull,0x7830203131303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020353130383030ull,0x3030303030303078ull,0x3030303278302033ull,
0x3078302064363662ull,0x2033313030303030ull,0x303065783009090aull,0x7830203131633134ull,
0x3038373030303063ull,0x6362313033783020ull,0x6336783020646664ull,0x0a20386437303132ull,
0x3030306578300909ull,0x3678302039303830ull,0x2030383738303030ull,0x3830343030657830ull,
0x3030347830203130ull,0x090a203038373030ull,0x6230303032783009ull,0x3030783020313738ull,
0x3020333430303030ull,0x3030663130303178ull,0x3030303078302033ull,0x09090a2030383231ull,
0x3233303030307830ull,0x3030637830203530ull,0x7830203238373030ull,0x3130303030303430ull,
0x3830323465783020ull,0x3009090a20303837ull,0x3032303030343078ull,0x3032346578302031ull,
0x3078302030383763ull,0x2035303033303030ull,0x3730303030637830ull,0x783009090a203038ull,
0x6435653230303032ull,0x3835303430783020ull,0x3430783020303837ull,0x3020313030303030ull,
0x3837303032346578ull,0x30783009090a2030ull,0x2031303230303034ull,0x3734303234657830ull,
0x3830337830203038ull,0x7830206466663230ull,0x3864376330346336ull,0x3032783009090a20ull,
0x3020383663616131ull,0x3661613831303278ull,0x3030303278302030ull,0x3078302035366132ull,
0x2030383734363034ull,0x303031783009090aull,0x7830203330303631ull,0x3038323130303030ull,
0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,0x6630306178300909ull,
0x3078302033303035ull,0x2030303030303030ull,0x3832303030317830ull,0x3034307830203130ull,
0x090a203038376333ull,0x3566303031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3038323330303078ull,0x3030306378302035ull,0x09090a2030383730ull,0x6566663136387830ull,
0x3030307830203330ull,0x7830203030303030ull,0x6466313034383033ull,0x3031346336783020ull,
0x3009090a20386337ull,0x3030353930306178ull,0x3030303078302033ull,0x6478302030303030ull,
0x2039303034303134ull,0x3730303030327830ull,0x783009090a203038ull,0x3330303539303031ull,
0x3030303030783020ull,0x3931783020303832ull,0x3020383030653030ull,0x3032653030393178ull,
0x31783009090a2063ull,0x2031313030323038ull,0x3763303034347830ull,0x3038317830203038ull,
0x7830203531323032ull,0x3038376330303434ull,0x3065783009090a20ull,0x3020393034303030ull,
0x3837303130303678ull,0x3030383078302030ull,0x6578302031303030ull,0x2030383738303234ull,
0x303830783009090aull,0x7830203130323030ull,0x3038376330323465ull,0x6630303531783020ull,
0x3531783020383030ull,0x0a20633032663030ull,0x3230343178300909ull,0x3478302031313031ull,
0x2030383763303034ull,0x3231323034317830ull,0x3034347830203531ull,0x090a203038376330ull,
0x3030303065783009ull,0x3036783020393034ull,0x3020303837303130ull,0x3030313030343078ull,
0x3032346578302031ull,0x09090a2030383738ull,0x3231303034307830ull,0x3234657830203130ull,
0x7830203038376330ull,0x3130303030303066ull,0x3030303065783020ull,0x3009090a20323030ull,
0x3065666631363878ull,0x3030303078302033ull,0x3378302030303030ull,0x2064663130353830ull,
0x3730313463367830ull,0x783009090a203863ull,0x3330303661303061ull,0x3030303030783020ull,
0x3031783020303030ull,0x3020333030366130ull,0x3832303030303078ull,0x31783009090a2030ull,
0x2038303065303039ull,0x3265303039317830ull,0x3038317830206330ull,0x7830203131303031ull,
0x3038376330303434ull,0x3831783009090a20ull,0x3020353132303130ull,0x3837633030343478ull,
0x3030306578302030ull,0x3678302039303430ull,0x2030383730313030ull,0x303830783009090aull,
0x7830203130303030ull,0x3038373830323465ull,0x3030303830783020ull,0x3465783020313032ull,
0x0a20303837633032ull,0x3030353178300909ull,0x3178302038303066ull,0x2063303266303035ull,
0x3031313034317830ull,0x3034347830203131ull,0x090a203038376330ull,0x3131303431783009ull,
0x3434783020353132ull,0x3020303837633030ull,0x3034303030306578ull,0x3130303678302039ull,
0x09090a2030383730ull,0x3031303034307830ull,0x3234657830203130ull,0x7830203038373830ull,
0x3130323130303430ull,0x6330323465783020ull,0x3009090a20303837ull,0x3030303030306678ull,
0x3030306578302031ull,0x3878302032303030ull,0x2033306566663136ull,0x3030303030307830ull,
0x783009090a203030ull,0x3830306530303931ull,0x6530303931783020ull,0x3831783020633032ull,
0x3020313130383030ull,0x3837633030343478ull,0x31783009090a2030ull,0x2035313238303038ull,
0x3763303034347830ull,0x3030657830203038ull,0x7830203930343030ull,0x3038373031303036ull,
0x3830783009090a20ull,0x3020313030303030ull,0x3837383032346578ull,0x3030383078302030ull,
0x6578302031303230ull,0x2030383763303234ull,0x303531783009090aull,0x7830203830306630ull,
0x6330326630303531ull,0x3930303431783020ull,0x3434783020313130ull,0x0a20303837633030ull,
0x3030343178300909ull,0x3478302035313239ull,0x2030383763303034ull,0x3430303030657830ull,
0x3030367830203930ull,0x090a203038373031ull,0x3130303430783009ull,0x3465783020313030ull,
0x3020303837383032ull,0x3032313030343078ull,0x3032346578302031ull,0x09090a2030383763ull,
0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,0x3830306530303931ull,
0x6530303931783020ull,0x3009090a20633032ull,0x3130343030383178ull,0x3030343478302031ull,
0x3178302030383763ull,0x2035313234303038ull,0x3763303034347830ull,0x783009090a203038ull,
0x3930343030303065ull,0x3031303036783020ull,0x3830783020303837ull,0x3020313030303030ull,
0x3837383032346578ull,0x30783009090a2030ull,0x2031303230303038ull,0x3763303234657830ull,
0x3035317830203038ull,0x7830203830306630ull,0x6330326630303531ull,0x3431783009090a20ull,
0x3020313130353030ull,0x3837633030343478ull,0x3030343178302030ull,0x3478302035313235ull,
0x2030383763303034ull,0x303065783009090aull,0x7830203930343030ull,0x3038373031303036ull,
0x3130303430783020ull,0x3465783020313030ull,0x0a20303837383032ull,0x3030343078300909ull,
0x6578302031303231ull,0x2030383763303234ull,0x6566663136387830ull,0x3030307830203330ull,
0x090a203030303030ull,0x6530303931783009ull,0x3931783020383030ull,0x3020633032653030ull,
0x3130323030383178ull,0x3030343478302031ull,0x09090a2030383763ull,0x3232303038317830ull,
0x3034347830203531ull,0x7830203038376330ull,0x3930343030303065ull,0x3031303036783020ull,
0x3009090a20303837ull,0x3030303030383078ull,0x3032346578302031ull,0x3078302030383738ull,
0x2031303230303038ull,0x3763303234657830ull,0x783009090a203038ull,0x3830306630303531ull,
0x6630303531783020ull,0x3431783020633032ull,0x3020313130333030ull,0x3837633030343478ull,
0x31783009090a2030ull,0x2035313233303034ull,0x3763303034347830ull,0x3030657830203038ull,
0x7830203930343030ull,0x3038373031303036ull,0x3430783009090a20ull,0x3020313030313030ull,
0x3837383032346578ull,0x3030343078302030ull,0x6578302031303231ull,0x2030383763303234ull,
0x313638783009090aull,0x7830203330656666ull,0x3030303030303030ull,0x6530303931783020ull,
0x3931783020383030ull,0x0a20633032653030ull,0x3030393178300909ull,0x3178302030313066ull,
0x2034313266303039ull,0x3430303030657830ull,0x3030367830203930ull,0x090a203038373031ull,
0x3030303830783009ull,0x3465783020313030ull,0x3020303837383032ull,0x3032303030383078ull,
0x3032346578302031ull,0x09090a2030383763ull,0x3066303035317830ull,0x3035317830203830ull,
0x7830206330326630ull,0x3131303230303431ull,0x6330303434783020ull,0x3009090a20303837ull,
0x3132323030343178ull,0x3030343478302035ull,0x6578302030383763ull,0x2039303430303030ull,
0x3730313030367830ull,0x783009090a203038ull,0x3130303130303430ull,0x3830323465783020ull,
0x3430783020303837ull,0x3020313032313030ull,0x3837633032346578ull,0x38783009090a2030ull,
0x2033306566663136ull,0x3030303030307830ull,0x3039317830203030ull,0x7830203830306530ull,
0x6330326530303931ull,0x3931783009090a20ull,0x3020303138653030ull,0x3161653030393178ull,
0x3030306578302034ull,0x3678302039303430ull,0x2030383730313030ull,0x303830783009090aull,
0x7830203130303030ull,0x3038373830323465ull,0x3030303830783020ull,0x3465783020313032ull,
0x0a20303837633032ull,0x3030353178300909ull,0x3178302038303066ull,0x2063303266303035ull,
0x3866303035317830ull,0x3035317830203031ull,0x090a203431616630ull,0x3030303065783009ull,
0x3036783020393034ull,0x3020303837303130ull,0x3030313030343078ull,0x3032346578302031ull,
0x09090a2030383738ull,0x3231303034307830ull,0x3234657830203130ull,0x7830203038376330ull,
0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,0x3030653030393178ull,
0x3030393178302038ull,0x3178302063303265ull,0x2030313465303039ull,0x3665303039317830ull,
0x783009090a203431ull,0x3930343030303065ull,0x3031303036783020ull,0x3830783020303837ull,
0x3020313030303030ull,0x3837383032346578ull,0x30783009090a2030ull,0x2031303230303038ull,
0x3763303234657830ull,0x3035317830203038ull,0x7830203830306630ull,0x6330326630303531ull,
0x3531783009090a20ull,0x3020303134663030ull,0x3136663030353178ull,0x3030306578302034ull,
0x3678302039303430ull,0x2030383730313030ull,0x303430783009090aull,0x7830203130303130ull,
0x3038373830323465ull,0x3130303430783020ull,0x3465783020313032ull,0x0a20303837633032ull,
0x6631363878300909ull,0x3078302033306566ull,0x2030303030303030ull,0x3038303030327830ull,
0x3030307830203130ull,0x090a203331303030ull,0x3030383033783009ull,0x6336783020646631ull,
0x3020386337633034ull,0x3030303031346478ull,0x3030303278302035ull,0x09090a2030383730ull,
0x3034383030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x6466393263373033ull,
0x3431303436783020ull,0x3009090a20616337ull,0x3030303030303378ull,0x3030303078302033ull,
0x6178302030383230ull,0x2031306334303030ull,0x3730303234307830ull,0x783009090a203038ull,
0x3930303034303033ull,0x3030313463783020ull,0x3031783020303837ull,0x3020313030313430ull,
0x3837633030343478ull,0x31783009090a2030ull,0x2035303231343030ull,0x3763303034347830ull,
0x3031327830203038ull,0x7830203930343030ull,0x3038373030383730ull,0x3064783009090a20ull,
0x3020313034306530ull,0x3837303038306178ull,0x3030313178302030ull,0x3178302030303066ull,
0x2034303266303031ull,0x303032783009090aull,0x7830203930343838ull,0x3330303030303030ull,
0x3065303064783020ull,0x3061783020313034ull,0x0a20313837303038ull,0x0000000a7d0a7d09ull
};


}



extern "C" {


static const unsigned long long __deviceText_$compute_13$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x2f2f090a33315f6dull,
0x656c69706d6f6320ull,0x2f20687469772064ull,0x61636f6c2f727375ull,0x6f2f616475632f6cull,
0x696c2f34366e6570ull,0x2f090a65622f2f62ull,0x6e65706f766e202full,0x746c697562206363ull,
0x39303032206e6f20ull,0x0a0a39302d34302dull,0x752e206765722e09ull,0x313c617225203233ull,
0x65722e090a3b3e37ull,0x25203436752e2067ull,0x3b3e37313c616472ull,0x2e206765722e090aull,
0x3c61662520323366ull,0x722e090a3b3e3731ull,0x203436662e206765ull,0x3e37313c61646625ull,
0x206765722e090a3bull,0x767225203233752eull,0x722e090a3b3e353cull,0x203436752e206765ull,
0x3b3e353c76647225ull,0x2e206765722e090aull,0x3c76662520323366ull,0x65722e090a3b3e35ull,
0x25203436662e2067ull,0x0a3b3e353c766466ull,0x2d2d2d2f2f090a0aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x6d6f43202f2f090aull,0x2f20676e696c6970ull,
0x78706d742f706d74ull,0x37303030305f7466ull,0x303030305f643730ull,0x5f37312d30303030ull,
0x72614365746e6f4dull,0x2e33314d535f6f6cull,0x2820692e33707063ull,0x4263632f706d742full,
0x64304674792e2349ull,0x2d2d2f2f090a2936ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2f2f090a0a2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x704f202f2f090a2dull,0x090a3a736e6f6974ull,0x2d2d2d2d2d2d2f2full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2f090a2d2d2d2d2dull,0x656772615420202full,
0x49202c7874703a74ull,0x33315f6d733a4153ull,0x6e6169646e45202cull,0x2c656c7474696c3aull,
0x7265746e696f5020ull,0x34363a657a695320ull,0x4f2d20202f2f090aull,0x6d6974704f280933ull,
0x206e6f6974617a69ull,0x090a296c6576656cull,0x0930672d20202f2full,0x6c20677562654428ull,
0x2f090a296c657665ull,0x2809326d2d20202full,0x612074726f706552ull,0x6569726f73697664ull,
0x2d2d2f2f090a2973ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x6c69662e090a0a2dull,0x6f633c2209310965ull,0x696c2d646e616d6dull,0x662e090a223e656eull,
0x2f22093209656c69ull,0x78706d742f706d74ull,0x37303030305f7466ull,0x303030305f643730ull,
0x5f36312d30303030ull,0x72614365746e6f4dull,0x2e33314d535f6f6cull,0x2e32656661647563ull,
0x662e090a22757067ull,0x4d22093309656c69ull,0x6c72614365746e6full,0x6c656e72656b5f6full,
0x2e090a226875632eull,0x22093409656c6966ull,0x62696c2f7273752full,0x3638782f6363672full,
0x756e696c2d34365full,0x2e342f756e672d78ull,0x6c636e692f332e33ull,0x646474732f656475ull,
0x2e090a22682e6665ull,0x22093509656c6966ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x7665642f7472632full,0x746e75725f656369ull,
0x090a22682e656d69ull,0x093609656c69662eull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x645f74736f682f65ull,0x682e73656e696665ull,
0x656c69662e090a22ull,0x6d6f682f22093709ull,0x6c616d726f6e2f65ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x6975622f6564756cull,0x7079745f6e69746cull,0x2e090a22682e7365ull,
0x22093809656c6966ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x5f6563697665642full,0x22682e7365707974ull,0x09656c69662e090aull,
0x656d6f682f220939ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x766972642f656475ull,0x73657079745f7265ull,0x69662e090a22682eull,0x2f2209303109656cull,
0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x5f65727574786574ull,0x22682e7365707974ull,0x09656c69662e090aull,0x6d6f682f22093131ull,
0x6c616d726f6e2f65ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x6365762f6564756cull,
0x657079745f726f74ull,0x662e090a22682e73ull,0x2209323109656c69ull,0x6f6e2f656d6f682full,
0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f6563697665642full,
0x705f68636e75616cull,0x726574656d617261ull,0x662e090a22682e73ull,0x2209333109656c69ull,
0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x6f74732f7472632full,0x616c635f65676172ull,0x2e090a22682e7373ull,0x09343109656c6966ull,
0x6e692f7273752f22ull,0x69622f6564756c63ull,0x73657079742f7374ull,0x69662e090a22682eull,
0x2f2209353109656cull,0x6c636e692f727375ull,0x656d69742f656475ull,0x69662e090a22682eull,
0x722209363109656cull,0x2e657079746c6165ull,0x6c69662e090a2268ull,0x6f4d220937310965ull,
0x6f6c72614365746eull,0x697463756465725full,0x0a226875632e6e6full,0x3109656c69662e09ull,
0x6973617571220938ull,0x65476d6f646e6172ull,0x5f726f746172656eull,0x632e6c656e72656bull,
0x69662e090a226875ull,0x2f2209393109656cull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x665f6e6f6d6d6f63ull,0x736e6f6974636e75ull,
0x69662e090a22682eull,0x2f2209303209656cull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x636e75662f747263ull,0x682e6f7263616d5full,
0x656c69662e090a22ull,0x6f682f2209313209ull,0x616d726f6e2f656dull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,0x74636e75665f6874ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x656d6f682f220932ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x697665642f656475ull,0x74636e75665f6563ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x656d6f682f220933ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x6874616d2f656475ull,0x6e6174736e6f635full,0x2e090a22682e7374ull,
0x09343209656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x5f31315f6d732f65ull,0x665f63696d6f7461ull,0x736e6f6974636e75ull,
0x69662e090a22682eull,0x2f2209353209656cull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x74615f32315f6d73ull,0x6e75665f63696d6full,
0x682e736e6f697463ull,0x656c69662e090a22ull,0x6f682f2209363209ull,0x616d726f6e2f656dull,
0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x6d732f6564756c63ull,0x62756f645f33315full,
0x74636e75665f656cull,0x0a22682e736e6f69ull,0x3209656c69662e09ull,0x656d6f682f220937ull,
0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x747865742f656475ull,
0x637465665f657275ull,0x6974636e75665f68ull,0x090a22682e736e6full,0x383209656c69662eull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x5f6874616d2f6564ull,0x6e6f6974636e7566ull,0x74705f6c62645f73ull,0x090a0a22682e3378ull,
0x2e2074736e6f632eull,0x2038206e67696c61ull,0x704f5f642038622eull,0x617461446e6f6974ull,
0x3b5d36333535365bull,0x61626f6c672e090aull,0x6e67696c612e206cull,0x642038622e203820ull,
0x6c61566c6c61435full,0x38363732335b6575ull,0x6e652e090a0a3b5dull,0x36315a5f20797274ull,
0x72614365746e6f4dull,0x6c656e72654b6f6cull,0x704f545f5f343150ull,0x756c61566e6f6974ull,
0x090a282069665065ull,0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,
0x746e6f4d36315a5full,0x654b6f6c72614365ull,0x5f3431506c656e72ull,0x6e6f6974704f545full,
0x69665065756c6156ull,0x65666675425f645full,0x61702e09090a2c72ull,0x3436752e206d6172ull,
0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72614365746e6f4dull,0x6c656e72654b6f6cull,
0x704f545f5f343150ull,0x756c61566e6f6974ull,0x535f645f69665065ull,0x0a2c73656c706d61ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x6e6f4d36315a5f5full,
0x4b6f6c7261436574ull,0x3431506c656e7265ull,0x6f6974704f545f5full,0x665065756c61566eull,
0x294e687461705f69ull,0x65722e090a7b090aull,0x25203631752e2067ull,0x090a3b3e353c6872ull,
0x33752e206765722eull,0x3e39323c72252032ull,0x206765722e090a3bull,0x647225203436752eull,
0x2e090a3b3e36313cull,0x3233662e20676572ull,0x0a3b3e333c662520ull,0x662e206765722e09ull,
0x343c646625203436ull,0x65722e090a3b3e34ull,0x20646572702e2067ull,0x090a3b3e383c7025ull,
0x31093309636f6c2eull,0x424c240a30093231ull,0x4d36315a5f5f3142ull,0x6c72614365746e6full,
0x506c656e72654b6full,0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x6c2e090a3a696650ull,
0x393231093309636full,0x2e766f6d090a3009ull,0x6872250920363175ull,0x6469746e25202c31ull,
0x20202020203b782eull,0x090a202f2f092020ull,0x203631752e766f6dull,0x25202c3268722509ull,
0x3b782e6469617463ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x3631752e65646977ull,
0x25202c3172250920ull,0x687225202c326872ull,0x090a202f2f093b31ull,0x2e3233752e747663ull,
0x3272250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,0x2e646461090a202full,
0x3372250920323375ull,0x25202c327225202cull,0x20202020203b3172ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x7225202c34722509ull,0x2020202020203b33ull,0x2f09202020202020ull,
0x2e747663090a202full,0x203631752e323373ull,0x6325202c35722509ull,0x203b792e64696174ull,
0x090a202f2f092020ull,0x203631752e766f6dull,0x25202c3368722509ull,0x782e64696174636eull,
0x2f0920202020203bull,0x702e646c090a202full,0x3233732e6d617261ull,0x5b202c3672250920ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6c72614365746e6full,0x506c656e72654b6full,
0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x687461705f696650ull,0x69202f2f093b5d4eull,
0x5f5f203533313a64ull,0x6d72617061647563ull,0x6e6f4d36315a5f5full,0x4b6f6c7261436574ull,
0x3431506c656e7265ull,0x6f6974704f545f5full,0x665065756c61566eull,0x2b4e687461705f69ull,
0x746573090a307830ull,0x3233732e656c2e70ull,0x25202c3170250920ull,0x3b337225202c3672ull,
0x0a202f2f09202020ull,0x3436662e766f6d09ull,0x202c316466250920ull,0x3030303030306430ull,
0x3030303030303030ull,0x30202f2f093b3030ull,0x36662e766f6d090aull,0x2c32646625092034ull,
0x3030303030643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x2031702540090a30ull,
0x744c240920617262ull,0x3b323836375f305full,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x2e656469772e6c75ull,0x3772250920363175ull,0x202c33687225202cull,0x2f2f093b31687225ull,
0x732e747663090a20ull,0x09203233752e3436ull,0x7225202c31647225ull,0x2020202020203b37ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x2c32647225092034ull,0x34202c3164722520ull,
0x2f2f09202020203bull,0x61702e646c090a20ull,0x203436752e6d6172ull,0x5b202c3364722509ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6c72614365746e6full,0x506c656e72654b6full,
0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x61535f645f696650ull,0x093b5d73656c706dull,
0x34313a6469202f2full,0x616475635f5f2031ull,0x315a5f5f6d726170ull,0x614365746e6f4d36ull,
0x656e72654b6f6c72ull,0x4f545f5f3431506cull,0x6c61566e6f697470ull,0x5f645f6966506575ull,
0x2b73656c706d6153ull,0x747663090a307830ull,0x3233732e3436752eull,0x202c346472250920ull,
0x202020203b337225ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x2c34647225202c35ull,0x09202020203b3420ull,0x646461090a202f2full,0x722509203436752eull,
0x33647225202c3664ull,0x203b35647225202cull,0x0a202f2f09202020ull,0x3436752e766f6d09ull,
0x202c376472250920ull,0x6e6f6974704f5f64ull,0x0920203b61746144ull,0x747663090a202f2full,
0x3233732e3436732eull,0x202c386472250920ull,0x202020203b357225ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x2c38647225202c39ull,0x092020203b323320ull,
0x646461090a202f2full,0x722509203436752eull,0x647225202c303164ull,0x3b39647225202c37ull,
0x0a202f2f09202020ull,0x736e6f632e646c09ull,0x2509203436662e74ull,0x72255b202c336466ull,
0x3b5d36312b303164ull,0x313a6469202f2f09ull,0x74704f5f64203234ull,0x2b617461446e6f69ull,
0x2e646c090a307830ull,0x36662e74736e6f63ull,0x2c34646625092034ull,0x2b30316472255b20ull,
0x202f2f093b5d3432ull,0x64203334313a6469ull,0x446e6f6974704f5full,0x0a3078302b617461ull,
0x736e6f632e646c09ull,0x2509203436662e74ull,0x72255b202c356466ull,0x093b5d382b303164ull,
0x34313a6469202f2full,0x6974704f5f642034ull,0x302b617461446e6full,0x632e646c090a3078ull,
0x3436662e74736e6full,0x202c366466250920ull,0x302b30316472255bull,0x6469202f2f093b5dull,
0x4f5f64203534313aull,0x7461446e6f697470ull,0x4c240a3078302b61ull,0x363431365f305f74ull,
0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c39323120656eull,
0x20676e697473656eull,0x31203a6874706564ull,0x616d69747365202cull,0x7265746920646574ull,
0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x093309636f6c2e09ull,0x6c090a3009303331ull,
0x6c61626f6c672e64ull,0x662509203233662eull,0x366472255b202c31ull,0x2f2f09203b5d302bull,
0x0a3634313a646920ull,0x3436662e74766309ull,0x662509203233662eull,0x3b316625202c3764ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x0931333109330963ull,0x722e64616d090a30ull,
0x2509203436662e6eull,0x646625202c386466ull,0x2c37646625202c34ull,0x2f093b3364662520ull,
0x2e766f6d090a202full,0x72257b0920343662ull,0x202c7d3972252c38ull,0x2020203b38646625ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x2d202c3031722509ull,0x3735373834363031ull,
0x2f092020203b3935ull,0x2e746573090a202full,0x732e3233752e746cull,0x3131722509203233ull,
0x25202c397225202cull,0x202f2f093b303172ull,0x33732e67656e090aull,0x2c32317225092032ull,
0x20203b3131722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x383031202c333172ull,0x3b30393435333532ull,0x202f2f0920202020ull,0x656c2e746573090aull,
0x3233752e3233752eull,0x202c343172250920ull,0x317225202c397225ull,0x090a202f2f093b33ull,
0x203233732e67656eull,0x25202c3531722509ull,0x202020203b343172ull,0x2f09202020202020ull,
0x622e726f090a202full,0x3631722509203233ull,0x202c32317225202cull,0x2020203b35317225ull,
0x090a202f2f092020ull,0x203233752e766f6dull,0x30202c3731722509ull,0x202020202020203bull,
0x2f09202020202020ull,0x70746573090a202full,0x203233732e71652eull,0x7225202c32702509ull,
0x37317225202c3631ull,0x090a202f2f09203bull,0x6172622032702540ull,0x5f305f744c240920ull,
0x2020203b32303436ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39323120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363431365f305f74ull,0x3209636f6c2e090aull,0x0a30093436370938ull,
0x3436662e766f6d09ull,0x202c396466250920ull,0x3531376666336430ull,0x3238623235363734ull,
0x31202f2f093b6566ull,0x6d090a373234342eull,0x09203436662e6c75ull,0x25202c3031646625ull,
0x646625202c386466ull,0x2f2f092020203b39ull,0x722e747663090a20ull,0x662e3436662e696eull,
0x3164662509203436ull,0x3031646625202c31ull,0x63090a202f2f093bull,0x732e697a722e7476ull,
0x09203436662e3233ull,0x6625202c38317225ull,0x2f2f09203b313164ull,0x732e766f6d090a20ull,
0x3931722509203233ull,0x203b38317225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x312d202c30327225ull,0x202020203b313230ull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e7467ull,0x317225202c337025ull,0x3b30327225202c38ull,
0x40090a202f2f0920ull,0x2061726220337025ull,0x375f305f744c2409ull,0x202020203b303731ull,
0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c39323120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x0a363431365f305full,0x383209636f6c2e09ull,0x090a300939363709ull,0x203233732e646461ull,
0x25202c3931722509ull,0x3b3535202c383172ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x63336430202c3231ull,0x3030303030303039ull,0x093b303030303030ull,
0x3135352e35202f2full,0x090a37312d653231ull,0x20696e752e617262ull,0x365f305f744c2409ull,
0x202020203b343139ull,0x2f09202020202020ull,0x305f744c240a202full,0x200a3a303731375full,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c393231ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x6f6d090a36343136ull,
0x2509203436662e76ull,0x6430202c32316466ull,0x3030303030303034ull,0x3030303030303030ull,
0x240a32202f2f093bull,0x3139365f305f744cull,0x6c3c2f2f200a3a34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39323120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363431365f305f74ull,0x3209636f6c2e090aull,0x0a30093439330938ull,
0x3436662e766f6d09ull,0x2c33316466250920ull,0x3236656662643020ull,0x3361666566323465ull,
0x202f2f093b666539ull,0x34313339362e302dull,0x722e64616d090a37ull,0x2509203436662e6eull,
0x6625202c34316466ull,0x646625202c313164ull,0x38646625202c3331ull,0x6d090a202f2f093bull,
0x09203436662e766full,0x30202c3531646625ull,0x3963626137636264ull,0x3330383933623365ull,
0x322d202f2f093b66ull,0x2d6535303931332eull,0x2e64616d090a3731ull,0x09203436662e6e72ull,
0x25202c3631646625ull,0x6625202c31316466ull,0x646625202c353164ull,0x0a202f2f093b3431ull,
0x3436662e766f6d09ull,0x2c37316466250920ull,0x6631326533643020ull,0x3835666363663730ull,
0x202f2f093b646162ull,0x6533343838302e32ull,0x766f6d090a39302dull,0x662509203436662eull,
0x336430202c383164ull,0x6431386466613565ull,0x3b66616233633661ull,0x31352e32202f2f09ull,
0x0a38302d65363633ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3931ull,
0x3631646625202c37ull,0x3b3831646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x766f6d090a300935ull,0x662509203436662eull,0x336430202c303264ull,0x6635356537323965ull,
0x3b36653038663036ull,0x35372e32202f2f09ull,0x0a37302d65353735ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x31646625202c3931ull,0x3631646625202c39ull,0x3b3032646625202cull,
0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300936ull,0x662509203436662eull,
0x336430202c313264ull,0x3861646431376365ull,0x3b36363664323066ull,0x35372e32202f2f09ull,
0x0a36302d65323735ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3931ull,
0x3631646625202c39ull,0x3b3132646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x766f6d090a300937ull,0x662509203436662eull,0x336430202c323264ull,0x3130613130616665ull,
0x3b30653439386233ull,0x38342e32202f2f09ull,0x0a35302d65363130ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x31646625202c3931ull,0x3631646625202c39ull,0x3b3232646625202cull,
0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300938ull,0x662509203436662eull,
0x336430202c333264ull,0x3130613130613266ull,0x3b38383766613364ull,0x30302e30202f2f09ull,
0x0a33313438393130ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3931ull,
0x3631646625202c39ull,0x3b3332646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x766f6d090a300939ull,0x662509203436662eull,0x336430202c343264ull,0x3163363163363566ull,
0x3b63653161336336ull,0x30302e30202f2f09ull,0x090a393838383331ull,0x662e6e722e64616dull,
0x3164662509203436ull,0x3931646625202c39ull,0x2c3631646625202cull,0x093b343264662520ull,
0x6f6c2e090a202f2full,0x3030340938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,
0x66336430202c3532ull,0x3131313131313138ull,0x093b313631393031ull,0x3830302e30202f2full,
0x6d090a3333333333ull,0x36662e6e722e6461ull,0x3931646625092034ull,0x2c3931646625202cull,
0x202c363164662520ull,0x2f093b3532646625ull,0x636f6c2e090a202full,0x0931303409383209ull,
0x662e766f6d090a30ull,0x3264662509203436ull,0x6166336430202c36ull,0x3535353535353535ull,
0x2f093b3163343535ull,0x363134302e30202full,0x64616d090a373636ull,0x203436662e6e722eull,
0x202c393164662509ull,0x25202c3931646625ull,0x6625202c36316466ull,0x202f2f093b363264ull,
0x3209636f6c2e090aull,0x0a30093230340938ull,0x3436662e766f6d09ull,0x2c37326466250920ull,
0x3535636633643020ull,0x3535353535353535ull,0x202f2f093b663635ull,0x3736363636312e30ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c393164ull,0x31646625202c3931ull,
0x3732646625202c36ull,0x2e090a202f2f093bull,0x3409383209636f6cull,0x6f6d090a30093330ull,
0x2509203436662e76ull,0x6430202c38326466ull,0x3030303030656633ull,0x3030303030303030ull,
0x352e30202f2f093bull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c393164ull,
0x31646625202c3931ull,0x3832646625202c36ull,0x2e090a202f2f093bull,0x3409383209636f6cull,
0x756d090a30093530ull,0x2509203436662e6cull,0x6625202c39326466ull,0x646625202c363164ull,
0x202f2f09203b3931ull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c393164ull,
0x31646625202c3932ull,0x3631646625202c36ull,0x2e090a202f2f093bull,0x3709383209636f6cull,
0x6461090a30093638ull,0x2509203233732e64ull,0x317225202c313272ull,0x3b32323031202c39ull,
0x202f2f0920202020ull,0x33622e6c6873090aull,0x2c32327225092032ull,0x32202c3132722520ull,
0x2020202020203b30ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x203b30202c333272ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x36622e766f6d090aull,0x3033646625092034ull,
0x2c333272257b202cull,0x20203b7d32327225ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c31336466250920ull,0x202c393164662520ull,0x25202c3033646625ull,0x2f2f093b30336466ull,
0x662e6c756d090a20ull,0x3364662509203436ull,0x3231646625202c32ull,0x3b3133646625202cull,
0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f305f744c24ull,0x2020202020203b38ull,
0x2f2f092020202020ull,0x5f305f744c240a20ull,0x2f200a3a32303436ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3932ull,
0x64656c6562616c20ull,0x365f305f744c2420ull,0x6f6c2e090a363431ull,0x3039370938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x66376430202c3333ull,0x3030303030303066ull,
0x093b303030303030ull,0x090a666e69202f2full,0x203436662e766f6dull,0x202c343364662509ull,
0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,0x33752e726873090aull,
0x2c34327225092032ull,0x3133202c39722520ull,0x202020202020203bull,0x6f6d090a202f2f09ull,
0x2509203233752e76ull,0x203b30202c353272ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x652e70746573090aull,0x2509203233752e71ull,0x34327225202c3470ull,0x203b35327225202cull,
0x6573090a202f2f09ull,0x09203436662e706cull,0x25202c3533646625ull,0x6625202c33336466ull,
0x347025202c343364ull,0x61090a202f2f093bull,0x09203436662e6464ull,0x25202c3633646625ull,
0x646625202c386466ull,0x2f2f092020203b38ull,0x662e736261090a20ull,0x3364662509203436ull,
0x3b38646625202c37ull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3833646625ull,0x3030303066663764ull,0x3030303030303030ull,0x6e69202f2f093b30ull,
0x2e70746573090a66ull,0x09203436662e656cull,0x646625202c357025ull,0x33646625202c3733ull,
0x090a202f2f093b38ull,0x3436662e706c6573ull,0x2c32336466250920ull,0x202c353364662520ull,
0x25202c3633646625ull,0x0a202f2f093b3570ull,0x35325f305f744c24ull,0x6c3c2f2f200a3a38ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39323120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363431365f305f74ull,0x3309636f6c2e090aull,
0x090a300932333109ull,0x203436662e6c756dull,0x202c393364662509ull,0x6625202c36646625ull,
0x2f0920203b323364ull,0x2e627573090a202full,0x6466250920343666ull,0x33646625202c3034ull,
0x3b35646625202c39ull,0x090a202f2f092020ull,0x203436662e766f6dull,0x202c313464662509ull,
0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,0x36662e78616d090aull,
0x3234646625092034ull,0x2c3034646625202cull,0x203b313464662520ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x646625202c326466ull,0x32646625202c3234ull,0x202f2f092020203bull,
0x3309636f6c2e090aull,0x090a300933333109ull,0x662e6e722e64616dull,0x3164662509203436ull,
0x2c3234646625202cull,0x202c323464662520ull,0x2f2f093b31646625ull,0x732e646461090a20ull,
0x2c34722509203233ull,0x7225202c34722520ull,0x2020202020203b37ull,0x61090a202f2f0920ull,
0x09203436752e6464ull,0x7225202c36647225ull,0x36647225202c3264ull,0x2f2f09202020203bull,
0x2e70746573090a20ull,0x09203233732e746cull,0x347225202c367025ull,0x20203b367225202cull,
0x40090a202f2f0920ull,0x2061726220367025ull,0x365f305f744c2409ull,0x202020203b363431ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x203b343336355f30ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x323836375f305f74ull,0x772e6c756d090a3aull,
0x203631752e656469ull,0x7225202c37722509ull,0x31687225202c3368ull,0x4c240a202f2f093bull,
0x343336355f305f74ull,0x09636f6c2e090a3aull,0x0a30093533310933ull,0x617261702e646c09ull,
0x2509203436752e6dull,0x5f5b202c31316472ull,0x726170616475635full,0x6f4d36315a5f5f6dull,
0x6f6c72614365746eull,0x31506c656e72654bull,0x6974704f545f5f34ull,0x5065756c61566e6full,
0x6675425f645f6966ull,0x2f2f093b5d726566ull,0x203734313a646920ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6c72614365746e6full,0x506c656e72654b6full,0x74704f545f5f3431ull,
0x65756c61566e6f69ull,0x75425f645f696650ull,0x3078302b72656666ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x2c357225202c3632ull,0x2020203b37722520ull,0x6461090a202f2f09ull,
0x2509203233732e64ull,0x337225202c373272ull,0x203b36327225202cull,0x202f2f0920202020ull,
0x36732e747663090aull,0x2509203233732e34ull,0x7225202c32316472ull,0x20202020203b3732ull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c33316472250920ull,0x202c323164722520ull,
0x202f2f09203b3631ull,0x36752e646461090aull,0x3431647225092034ull,0x2c3131647225202cull,
0x203b333164722520ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,0x72255b0920343666ull,
0x202c5d302b343164ull,0x2f2f093b32646625ull,0x0a3834313a646920ull,0x626f6c672e747309ull,
0x09203436662e6c61ull,0x382b34316472255bull,0x3b31646625202c5dull,0x313a6469202f2f09ull,
0x636f6c2e090a3934ull,0x3009363331093309ull,0x203b74697865090aull,0x2020202020202020ull,
0x2020202020202020ull,0x2020202020202020ull,0x444c240a202f2f09ull,0x315a5f5f646e6557ull,
0x614365746e6f4d36ull,0x656e72654b6f6c72ull,0x4f545f5f3431506cull,0x6c61566e6f697470ull,
0x090a3a6966506575ull,0x315a5f202f2f207dull,0x614365746e6f4d36ull,0x656e72654b6f6c72ull,
0x4f545f5f3431506cull,0x6c61566e6f697470ull,0x090a0a6966506575ull,0x5f207972746e652eull,
0x65746e6f4d37325aull,0x656e4f6f6c726143ull,0x7265506b636f6c42ull,0x66506e6f6974704full,
0x702e09090a282069ull,0x36752e206d617261ull,0x616475635f5f2034ull,0x325a5f5f6d726170ull,
0x614365746e6f4d37ull,0x6c42656e4f6f6c72ull,0x704f7265506b636full,0x5f6966506e6f6974ull,
0x656c706d61535f64ull,0x61702e09090a2c73ull,0x3233732e206d6172ull,0x70616475635f5f20ull,
0x37325a5f5f6d7261ull,0x72614365746e6f4dull,0x6f6c42656e4f6f6cull,0x74704f7265506b63ull,
0x705f6966506e6f69ull,0x7b090a294e687461ull,0x2e206765722e090aull,0x353c722520323375ull,
0x65722e090a3b3e30ull,0x25203436752e2067ull,0x0a3b3e36323c6472ull,0x662e206765722e09ull,
0x3e333c6625203233ull,0x206765722e090a3bull,0x646625203436662eull,0x2e090a3b3e34393cull,
0x6572702e20676572ull,0x3e34313c70252064ull,0x726168732e090a3bull,0x67696c612e206465ull,
0x2038622e2038206eull,0x735f616475635f5full,0x6c6143326d75535full,0x325b34343338396cull,
0x2e090a3b5d383430ull,0x2e20646572616873ull,0x2038206e67696c61ull,0x75635f5f2038622eull,
0x6d75535f735f6164ull,0x333030316c6c6143ull,0x5d383430325b3239ull,0x09636f6c2e090a3bull,
0x0a30093934310933ull,0x5a5f5f3142424c24ull,0x4365746e6f4d3732ull,0x42656e4f6f6c7261ull,
0x4f7265506b636f6cull,0x6966506e6f697470ull,0x09636f6c2e090a3aull,0x0a30093436310933ull,
0x3233732e74766309ull,0x722509203631752eull,0x2e64697425202c31ull,0x0920202020203b78ull,
0x766f6d090a202f2full,0x722509203233732eull,0x203b317225202c32ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x32202c3372250920ull,0x20202020203b3535ull,
0x0920202020202020ull,0x746573090a202f2full,0x3233732e656c2e70ull,0x25202c3170250920ull,
0x3b337225202c3172ull,0x0a202f2f09202020ull,0x6220317025214009ull,0x5f744c2409206172ull,
0x3b32323937315f31ull,0x0920202020202020ull,0x766f6d090a202f2full,0x722509203436752eull,
0x75635f5f202c3164ull,0x6d75535f735f6164ull,0x3338396c6c614332ull,0x0a202f2f093b3434ull,
0x3436752e766f6d09ull,0x202c326472250920ull,0x735f616475635f5full,0x6c6c61436d75535full,
0x093b323933303031ull,0x766f6d090a202f2full,0x722509203436752eull,0x704f5f64202c3364ull,
0x617461446e6f6974ull,0x0a202f2f0920203bull,0x3233732e74766309ull,0x722509203631752eull,
0x6961746325202c34ull,0x092020203b782e64ull,0x747663090a202f2full,0x3233732e3436732eull,
0x202c346472250920ull,0x202020203b347225ull,0x0a202f2f09202020ull,0x2e6f6c2e6c756d09ull,
0x6472250920343675ull,0x2c34647225202c35ull,0x092020203b323320ull,0x646461090a202f2full,
0x722509203436752eull,0x33647225202c3664ull,0x203b35647225202cull,0x0a202f2f09202020ull,
0x736e6f632e646c09ull,0x2509203436662e74ull,0x72255b202c316466ull,0x093b5d36312b3664ull,
0x34323a6469202f2full,0x6974704f5f642035ull,0x302b617461446e6full,0x632e646c090a3078ull,
0x3436662e74736e6full,0x202c326466250920ull,0x34322b366472255bull,0x6469202f2f093b5dull,
0x4f5f64203634323aull,0x7461446e6f697470ull,0x6c090a3078302b61ull,0x2e74736e6f632e64ull,
0x6466250920343666ull,0x366472255b202c33ull,0x2f2f09203b5d382bull,0x203734323a646920ull,
0x6e6f6974704f5f64ull,0x3078302b61746144ull,0x6e6f632e646c090aull,0x09203436662e7473ull,
0x255b202c34646625ull,0x203b5d302b366472ull,0x323a6469202f2f09ull,0x74704f5f64203834ull,
0x2b617461446e6f69ull,0x747663090a307830ull,0x3233732e3436752eull,0x202c376472250920ull,
0x202020203b317225ull,0x0a202f2f09202020ull,0x3436732e766f6d09ull,0x202c386472250920ull,
0x2020203b37647225ull,0x0920202020202020ull,0x747663090a202f2full,0x3631752e3233752eull,
0x25202c3572250920ull,0x203b782e6469746eull,0x0a202f2f09202020ull,0x3436732e74766309ull,
0x722509203233752eull,0x3b357225202c3964ull,0x0920202020202020ull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x202c303164722509ull,0x3b38202c37647225ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x39647225202c3131ull,0x092020203b38202cull,
0x646461090a202f2full,0x722509203436752eull,0x647225202c323164ull,0x32647225202c3031ull,
0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c33316472250920ull,0x202c303164722520ull,
0x0920203b31647225ull,0x2e646c090a202f2full,0x33732e6d61726170ull,0x202c367225092032ull,
0x70616475635f5f5bull,0x37325a5f5f6d7261ull,0x72614365746e6f4dull,0x6f6c42656e4f6f6cull,
0x74704f7265506b63ull,0x705f6966506e6f69ull,0x2f093b5d4e687461ull,0x3933323a6469202full,
0x70616475635f5f20ull,0x37325a5f5f6d7261ull,0x72614365746e6f4dull,0x6f6c42656e4f6f6cull,
0x74704f7265506b63ull,0x705f6966506e6f69ull,0x3078302b4e687461ull,0x315f315f744c240aull,
0x2f200a3a34333438ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3120656e696c2079ull,
0x7473656e202c3436ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x0936363109330963ull,
0x732e766f6d090a30ull,0x2c37722509203233ull,0x2020203b32722520ull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e65672e707465ull,0x2c32702509203233ull,0x7225202c32722520ull,
0x2f2f092020203b36ull,0x662e766f6d090a20ull,0x3564662509203436ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x2e766f6d090a3020ull,0x6466250920343666ull,
0x3030306430202c36ull,0x3030303030303030ull,0x2f093b3030303030ull,0x702540090a30202full,
0x2409206172622032ull,0x3833325f315f744cull,0x20202020203b3031ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34363120ull,0x6c6562616c206461ull,0x315f744c24206465ull,0x090a34333438315full,
0x203233732e627573ull,0x7225202c38722509ull,0x203b327225202c36ull,0x2f09202020202020ull,
0x2e646461090a202full,0x3972250920323373ull,0x32202c387225202cull,0x20202020203b3535ull,
0x090a202f2f092020ull,0x203233732e726873ull,0x25202c3031722509ull,0x203b3133202c3972ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3172250920323373ull,0x203b353532202c31ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233622e646e61ull,0x25202c3231722509ull,
0x317225202c303172ull,0x2f09202020203b31ull,0x2e646461090a202full,0x3172250920323373ull,
0x2c32317225202c33ull,0x2020203b39722520ull,0x090a202f2f092020ull,0x203233732e726873ull,
0x25202c3431722509ull,0x203b38202c333172ull,0x2f09202020202020ull,0x702e646c090a202full,
0x3436752e6d617261ull,0x2c34316472250920ull,0x616475635f5f5b20ull,0x325a5f5f6d726170ull,
0x614365746e6f4d37ull,0x6c42656e4f6f6c72ull,0x704f7265506b636full,0x5f6966506e6f6974ull,
0x656c706d61535f64ull,0x69202f2f093b5d73ull,0x5f5f203934323a64ull,0x6d72617061647563ull,
0x6e6f4d37325a5f5full,0x4f6f6c7261436574ull,0x506b636f6c42656eull,0x6e6f6974704f7265ull,
0x61535f645f696650ull,0x78302b73656c706dull,0x6c2e6c756d090a30ull,0x2509203436752e6full,
0x7225202c35316472ull,0x20203b34202c3864ull,0x61090a202f2f0920ull,0x09203436752e6464ull,
0x25202c3631647225ull,0x7225202c34316472ull,0x2f2f09203b353164ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c34363120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333438315f315full,0x33732e766f6d090aull,
0x2c35317225092032ull,0x20203b3431722520ull,0x2020202020202020ull,0x744c240a202f2f09ull,
0x32303239315f315full,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,
0x202c36363120656eull,0x20676e697473656eull,0x32203a6874706564ull,0x616d69747365202cull,
0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x093309636f6c2e09ull,
0x6c090a3009373631ull,0x6c61626f6c672e64ull,0x662509203233662eull,0x316472255b202c31ull,
0x2f2f093b5d302b36ull,0x0a3035323a646920ull,0x3436662e74766309ull,0x662509203233662eull,
0x3b316625202c3764ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x0938363109330963ull,
0x722e64616d090a30ull,0x2509203436662e6eull,0x646625202c386466ull,0x2c37646625202c32ull,
0x2f093b3164662520ull,0x2e766f6d090a202full,0x72257b0920343662ull,0x7d373172252c3631ull,
0x203b38646625202cull,0x090a202f2f092020ull,0x203233732e766f6dull,0x2d202c3831722509ull,
0x3735373834363031ull,0x2f092020203b3935ull,0x2e746573090a202full,0x732e3233752e746cull,
0x3931722509203233ull,0x202c37317225202cull,0x2f2f093b38317225ull,0x732e67656e090a20ull,
0x3032722509203233ull,0x203b39317225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x3031202c31327225ull,0x3039343533353238ull,0x2f2f09202020203bull,
0x6c2e746573090a20ull,0x33752e3233752e65ull,0x2c32327225092032ull,0x25202c3731722520ull,
0x202f2f093b313272ull,0x33732e67656e090aull,0x2c33327225092032ull,0x20203b3232722520ull,
0x2020202020202020ull,0x726f090a202f2f09ull,0x722509203233622eull,0x30327225202c3432ull,
0x203b33327225202cull,0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c35327225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e71652e7074ull,
0x202c337025092032ull,0x7225202c34327225ull,0x202f2f09203b3532ull,0x622033702540090aull,
0x5f744c2409206172ull,0x3b38353439315f31ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363120656e696c20ull,
0x2064616568202c36ull,0x2064656c6562616cull,0x39315f315f744c24ull,0x6f6c2e090a323032ull,
0x3436370938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x6666336430202c39ull,
0x3235363734353137ull,0x2f093b6566323862ull,0x373234342e31202full,0x36662e6c756d090aull,
0x3031646625092034ull,0x202c38646625202cull,0x2020203b39646625ull,0x7663090a202f2f09ull,
0x36662e696e722e74ull,0x2509203436662e34ull,0x6625202c31316466ull,0x202f2f093b303164ull,
0x7a722e747663090aull,0x36662e3233732e69ull,0x2c36327225092034ull,0x203b313164662520ull,
0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x327225202c373272ull,0x2020202020203b36ull,
0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c38327225092032ull,0x203b313230312d20ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e74672e7074ull,0x202c347025092032ull,
0x7225202c36327225ull,0x202f2f09203b3832ull,0x622034702540090aull,0x5f744c2409206172ull,
0x3b36323230325f31ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363120656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x39315f315f744c24ull,0x6f6c2e090a323032ull,0x3936370938320963ull,
0x2e646461090a3009ull,0x3272250920323373ull,0x2c36327225202c37ull,0x202020203b353520ull,
0x090a202f2f092020ull,0x203436662e766f6dull,0x202c323164662509ull,0x3030303963336430ull,
0x3030303030303030ull,0x35202f2f093b3030ull,0x2d6532313135352eull,0x2e617262090a3731ull,
0x744c240920696e75ull,0x30373939315f315full,0x202020202020203bull,0x240a202f2f092020ull,
0x3230325f315f744cull,0x3c2f2f200a3a3632ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36363120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3239315f315f744cull,0x2e766f6d090a3230ull,0x6466250920343666ull,0x30346430202c3231ull,
0x3030303030303030ull,0x093b303030303030ull,0x744c240a32202f2full,0x30373939315f315full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36363120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32303239315f315full,
0x3209636f6c2e090aull,0x0a30093439330938ull,0x3436662e766f6d09ull,0x2c33316466250920ull,
0x3236656662643020ull,0x3361666566323465ull,0x202f2f093b666539ull,0x34313339362e302dull,
0x722e64616d090a37ull,0x2509203436662e6eull,0x6625202c34316466ull,0x646625202c313164ull,
0x38646625202c3331ull,0x6d090a202f2f093bull,0x09203436662e766full,0x30202c3531646625ull,
0x3963626137636264ull,0x3330383933623365ull,0x322d202f2f093b66ull,0x2d6535303931332eull,
0x2e64616d090a3731ull,0x09203436662e6e72ull,0x25202c3631646625ull,0x6625202c31316466ull,
0x646625202c353164ull,0x0a202f2f093b3431ull,0x3436662e766f6d09ull,0x2c37316466250920ull,
0x6631326533643020ull,0x3835666363663730ull,0x202f2f093b646162ull,0x6533343838302e32ull,
0x766f6d090a39302dull,0x662509203436662eull,0x336430202c383164ull,0x6431386466613565ull,
0x3b66616233633661ull,0x31352e32202f2f09ull,0x0a38302d65363633ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x31646625202c3931ull,0x3631646625202c37ull,0x3b3831646625202cull,
0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300935ull,0x662509203436662eull,
0x336430202c303264ull,0x6635356537323965ull,0x3b36653038663036ull,0x35372e32202f2f09ull,
0x0a37302d65353735ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3931ull,
0x3631646625202c39ull,0x3b3032646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x766f6d090a300936ull,0x662509203436662eull,0x336430202c313264ull,0x3861646431376365ull,
0x3b36363664323066ull,0x35372e32202f2f09ull,0x0a36302d65323735ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x31646625202c3931ull,0x3631646625202c39ull,0x3b3132646625202cull,
0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300937ull,0x662509203436662eull,
0x336430202c323264ull,0x3130613130616665ull,0x3b30653439386233ull,0x38342e32202f2f09ull,
0x0a35302d65363130ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x31646625202c3931ull,
0x3631646625202c39ull,0x3b3232646625202cull,0x6c2e090a202f2f09ull,0x393309383209636full,
0x766f6d090a300938ull,0x662509203436662eull,0x336430202c333264ull,0x3130613130613266ull,
0x3b38383766613364ull,0x30302e30202f2f09ull,0x0a33313438393130ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x31646625202c3931ull,0x3631646625202c39ull,0x3b3332646625202cull,
0x6c2e090a202f2f09ull,0x393309383209636full,0x766f6d090a300939ull,0x662509203436662eull,
0x336430202c343264ull,0x3163363163363566ull,0x3b63653161336336ull,0x30302e30202f2f09ull,
0x090a393838383331ull,0x662e6e722e64616dull,0x3164662509203436ull,0x3931646625202c39ull,
0x2c3631646625202cull,0x093b343264662520ull,0x6f6c2e090a202f2full,0x3030340938320963ull,
0x2e766f6d090a3009ull,0x6466250920343666ull,0x66336430202c3532ull,0x3131313131313138ull,
0x093b313631393031ull,0x3830302e30202f2full,0x6d090a3333333333ull,0x36662e6e722e6461ull,
0x3931646625092034ull,0x2c3931646625202cull,0x202c363164662520ull,0x2f093b3532646625ull,
0x636f6c2e090a202full,0x0931303409383209ull,0x662e766f6d090a30ull,0x3264662509203436ull,
0x6166336430202c36ull,0x3535353535353535ull,0x2f093b3163343535ull,0x363134302e30202full,
0x64616d090a373636ull,0x203436662e6e722eull,0x202c393164662509ull,0x25202c3931646625ull,
0x6625202c36316466ull,0x202f2f093b363264ull,0x3209636f6c2e090aull,0x0a30093230340938ull,
0x3436662e766f6d09ull,0x2c37326466250920ull,0x3535636633643020ull,0x3535353535353535ull,
0x202f2f093b663635ull,0x3736363636312e30ull,0x6e722e64616d090aull,0x662509203436662eull,
0x646625202c393164ull,0x31646625202c3931ull,0x3732646625202c36ull,0x2e090a202f2f093bull,
0x3409383209636f6cull,0x6f6d090a30093330ull,0x2509203436662e76ull,0x6430202c38326466ull,
0x3030303030656633ull,0x3030303030303030ull,0x352e30202f2f093bull,0x6e722e64616d090aull,
0x662509203436662eull,0x646625202c393164ull,0x31646625202c3931ull,0x3832646625202c36ull,
0x2e090a202f2f093bull,0x3409383209636f6cull,0x756d090a30093530ull,0x2509203436662e6cull,
0x6625202c39326466ull,0x646625202c363164ull,0x202f2f09203b3931ull,0x6e722e64616d090aull,
0x662509203436662eull,0x646625202c393164ull,0x31646625202c3932ull,0x3631646625202c36ull,
0x2e090a202f2f093bull,0x3709383209636f6cull,0x6461090a30093638ull,0x2509203233732e64ull,
0x327225202c393272ull,0x3b32323031202c37ull,0x202f2f0920202020ull,0x33622e6c6873090aull,
0x2c30337225092032ull,0x32202c3932722520ull,0x2020202020203b30ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x203b30202c313372ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x36622e766f6d090aull,0x3033646625092034ull,0x2c313372257b202cull,0x20203b7d30337225ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x2c31336466250920ull,0x202c393164662520ull,
0x25202c3033646625ull,0x2f2f093b30336466ull,0x662e6c756d090a20ull,0x3364662509203436ull,
0x3231646625202c32ull,0x3b3133646625202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x35325f315f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,0x5f315f744c240a20ull,
0x200a3a3835343931ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c363631ull,0x656c6562616c2064ull,0x5f315f744c242064ull,
0x2e090a3230323931ull,0x3709383209636f6cull,0x6f6d090a30093039ull,0x2509203436662e76ull,
0x6430202c33336466ull,0x3030303030666637ull,0x3030303030303030ull,0x666e69202f2f093bull,
0x36662e766f6d090aull,0x3433646625092034ull,0x303030306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x2e726873090a3020ull,0x3372250920323375ull,0x2c37317225202c32ull,
0x202020203b313320ull,0x090a202f2f092020ull,0x203233752e766f6dull,0x30202c3333722509ull,
0x202020202020203bull,0x2f09202020202020ull,0x70746573090a202full,0x203233752e71652eull,
0x7225202c35702509ull,0x33337225202c3233ull,0x090a202f2f09203bull,0x3436662e706c6573ull,
0x2c35336466250920ull,0x202c333364662520ull,0x25202c3433646625ull,0x0a202f2f093b3570ull,
0x3436662e64646109ull,0x2c36336466250920ull,0x25202c3864662520ull,0x092020203b386466ull,
0x736261090a202f2full,0x662509203436662eull,0x646625202c373364ull,0x2020202020203b38ull,
0x0a202f2f09202020ull,0x3436662e766f6d09ull,0x2c38336466250920ull,0x3030666637643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x746573090a666e69ull,0x3436662e656c2e70ull,
0x25202c3670250920ull,0x6625202c37336466ull,0x202f2f093b383364ull,0x662e706c6573090aull,
0x3364662509203436ull,0x3533646625202c32ull,0x2c3633646625202cull,0x2f2f093b36702520ull,
0x5f315f744c240a20ull,0x2f2f200a3a383532ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363120656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,
0x39315f315f744c24ull,0x6f6c2e090a323032ull,0x0939363109330963ull,0x662e6c756d090a30ull,
0x3364662509203436ull,0x2c34646625202c39ull,0x203b323364662520ull,0x73090a202f2f0920ull,
0x09203436662e6275ull,0x25202c3034646625ull,0x6625202c39336466ull,0x2f2f0920203b3364ull,
0x662e766f6d090a20ull,0x3464662509203436ull,0x3030306430202c31ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x78616d090a30202full,0x662509203436662eull,0x646625202c323464ull,
0x34646625202c3034ull,0x0a202f2f09203b31ull,0x3436662e64646109ull,0x202c366466250920ull,
0x25202c3234646625ull,0x092020203b366466ull,0x6f6c2e090a202f2full,0x0930373109330963ull,
0x722e64616d090a30ull,0x2509203436662e6eull,0x646625202c356466ull,0x34646625202c3234ull,
0x3b35646625202c32ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x2c377225202c3772ull,
0x2020203b36353220ull,0x202f2f0920202020ull,0x36752e646461090aull,0x3631647225092034ull,
0x2c3631647225202cull,0x20203b3432303120ull,0x6573090a202f2f09ull,0x33732e746c2e7074ull,
0x202c377025092032ull,0x367225202c377225ull,0x202f2f092020203bull,0x622037702540090aull,
0x5f744c2409206172ull,0x3b32303239315f31ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363120656e696c20ull,
0x2064616568202c34ull,0x2064656c6562616cull,0x38315f315f744c24ull,0x617262090a343334ull,
0x4c240920696e752eull,0x393638315f315f74ull,0x2020202020203b30ull,0x0a202f2f09202020ull,
0x33325f315f744c24ull,0x2f2f200a3a303138ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363120656e696c20ull,0x2064616568202c34ull,0x2064656c6562616cull,
0x38315f315f744c24ull,0x5f744c240a343334ull,0x3a30393638315f31ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3436312065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333438315f31ull,0x093309636f6c2e09ull,
0x73090a3009323731ull,0x6465726168732e74ull,0x255b09203436662eull,0x2c5d302b32316472ull,
0x2f093b3664662520ull,0x3135323a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3239333030316cull,0x6f6c2e090a307830ull,0x0933373109330963ull,0x68732e7473090a30ull,
0x3436662e64657261ull,0x33316472255b0920ull,0x646625202c5d302bull,0x6469202f2f093b35ull,
0x635f5f203235323aull,0x75535f735f616475ull,0x38396c6c6143326dull,0x0a3078302b343433ull,
0x3233752e64646109ull,0x25202c3272250920ull,0x3b357225202c3272ull,0x0920202020202020ull,
0x646461090a202f2full,0x722509203436752eull,0x39647225202c3864ull,0x203b38647225202cull,
0x0a202f2f09202020ull,0x3436752e64646109ull,0x2c33316472250920ull,0x202c313164722520ull,
0x09203b3331647225ull,0x646461090a202f2full,0x722509203436752eull,0x647225202c323164ull,
0x31647225202c3131ull,0x0a202f2f09203b32ull,0x3233752e766f6d09ull,0x202c343372250920ull,
0x202020203b353532ull,0x0920202020202020ull,0x746573090a202f2full,0x3233732e656c2e70ull,
0x25202c3870250920ull,0x34337225202c3272ull,0x0a202f2f0920203bull,0x7262203870254009ull,
0x315f744c24092061ull,0x203b34333438315full,0x0920202020202020ull,0x5f744c240a202f2full,
0x3a32323937315f31ull,0x3309636f6c2e090aull,0x090a300938373109ull,0x203436752e766f6dull,
0x5f202c3164722509ull,0x5f735f616475635full,0x6c6c6143326d7553ull,0x2f093b3434333839ull,
0x2e766f6d090a202full,0x6472250920343675ull,0x6475635f5f202c32ull,0x436d75535f735f61ull,
0x39333030316c6c61ull,0x090a202f2f093b32ull,0x09373109636f6c2eull,0x6f6d090a30093837ull,
0x2509203233732e76ull,0x317225202c353372ull,0x202020202020203bull,0x202f2f0920202020ull,
0x203170252140090aull,0x744c240920617262ull,0x34393930325f315full,0x202020202020203bull,
0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x313135202c363372ull,0x202020202020203bull,
0x202f2f0920202020ull,0x33732e627573090aull,0x2c37337225092032ull,0x25202c3633722520ull,
0x20202020203b3172ull,0x6873090a202f2f09ull,0x2509203233732e72ull,0x337225202c383372ull,
0x20203b3133202c37ull,0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c39337225092032ull,
0x2020203b35353220ull,0x2020202020202020ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,
0x337225202c303472ull,0x3b39337225202c38ull,0x202f2f0920202020ull,0x33732e646461090aull,
0x2c31347225092032ull,0x25202c3034722520ull,0x202020203b373372ull,0x6873090a202f2f09ull,
0x2509203233732e72ull,0x347225202c323472ull,0x2020203b38202c31ull,0x202f2f0920202020ull,
0x36752e747663090aull,0x2509203233732e34ull,0x7225202c37316472ull,0x2020202020203b31ull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c38316472250920ull,0x202c373164722520ull,
0x202f2f0920203b38ull,0x33732e766f6d090aull,0x2c33347225092032ull,0x20203b3234722520ull,
0x2020202020202020ull,0x744c240a202f2f09ull,0x36303531325f315full,0x6f6c3c2f2f200a3aull,
0x706f6f4c203e706full,0x696c2079646f6220ull,0x6e202c383720656eull,0x6420676e69747365ull,
0x2c31203a68747065ull,0x74616d6974736520ull,0x6172657469206465ull,0x75203a736e6f6974ull,
0x090a6e776f6e6b6eull,0x09373109636f6c2eull,0x6162090a30093937ull,0x0920636e79732e72ull,
0x2020202020203b30ull,0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x090a300930380937ull,0x203436752e646461ull,0x202c393164722509ull,0x25202c3831647225ull,
0x2f0920203b326472ull,0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3032ull,
0x3b31647225202c38ull,0x090a202f2f092020ull,0x203233752e766f6dull,0x31202c3434722509ull,
0x20202020203b3732ull,0x2f09202020202020ull,0x70746573090a202full,0x203233732e74672eull,
0x7225202c39702509ull,0x34347225202c3533ull,0x090a202f2f09203bull,0x6172622039702540ull,
0x5f315f744c240920ull,0x20203b3236373132ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x202c383720656e69ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x36303531325f315full,0x3109636f6c2e090aull,
0x090a300932350937ull,0x65726168732e646cull,0x2509203436662e64ull,0x255b202c33346466ull,
0x3b5d302b39316472ull,0x323a6469202f2f09ull,0x6475635f5f203335ull,0x436d75535f735f61ull,
0x39333030316c6c61ull,0x6c090a3078302b32ull,0x6465726168732e64ull,0x662509203436662eull,
0x72255b202c343464ull,0x343230312b393164ull,0x6469202f2f093b5dull,0x635f5f203435323aull,
0x75535f735f616475ull,0x3030316c6c61436dull,0x0a3078302b323933ull,0x3436662e64646109ull,
0x2c35346466250920ull,0x202c333464662520ull,0x09203b3434646625ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3931ull,0x2f2f093b35346466ull,
0x203535323a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,0x302b323933303031ull,
0x732e646c090a3078ull,0x36662e6465726168ull,0x3634646625092034ull,0x30326472255b202cull,
0x202f2f093b5d302bull,0x5f203635323a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,
0x78302b3434333839ull,0x68732e646c090a30ull,0x3436662e64657261ull,0x2c37346466250920ull,
0x2b30326472255b20ull,0x2f093b5d34323031ull,0x3735323a6469202full,0x5f616475635f5f20ull,
0x6143326d75535f73ull,0x2b34343338396c6cull,0x646461090a307830ull,0x662509203436662eull,
0x646625202c383464ull,0x34646625202c3634ull,0x0a202f2f09203b37ull,0x726168732e747309ull,
0x09203436662e6465ull,0x302b30326472255bull,0x3834646625202c5dull,0x3a6469202f2f093bull,
0x75635f5f20383532ull,0x6d75535f735f6164ull,0x3338396c6c614332ull,0x240a3078302b3434ull,
0x3731325f315f744cull,0x3c2f2f200a3a3236ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x2c383720656e696cull,0x616c206461656820ull,0x4c242064656c6562ull,
0x303531325f315f74ull,0x732e726162090a36ull,0x203b300920636e79ull,0x2020202020202020ull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3336202c35347225ull,
0x202020202020203bull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e7467ull,
0x7225202c30317025ull,0x35347225202c3533ull,0x40090a202f2f093bull,0x6172622030317025ull,
0x5f315f744c240920ull,0x20203b3437323232ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x68202c383720656eull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a36303531325f31ull,0x373109636f6c2e09ull,
0x6c090a3009333509ull,0x6465726168732e64ull,0x662509203436662eull,0x72255b202c393464ull,
0x093b5d302b393164ull,0x35323a6469202f2full,0x616475635f5f2039ull,0x61436d75535f735full,
0x3239333030316c6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x6466250920343666ull,
0x6472255b202c3035ull,0x3b5d3231352b3931ull,0x323a6469202f2f09ull,0x6475635f5f203036ull,
0x436d75535f735f61ull,0x39333030316c6c61ull,0x61090a3078302b32ull,0x09203436662e6464ull,
0x25202c3135646625ull,0x6625202c39346466ull,0x2f2f09203b303564ull,0x68732e7473090a20ull,
0x3436662e64657261ull,0x39316472255b0920ull,0x646625202c5d302bull,0x69202f2f093b3135ull,
0x5f5f203136323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b32393330ull,
0x6168732e646c090aull,0x203436662e646572ull,0x202c323564662509ull,0x302b30326472255bull,
0x6469202f2f093b5dull,0x635f5f203236323aull,0x75535f735f616475ull,0x38396c6c6143326dull,
0x0a3078302b343433ull,0x726168732e646c09ull,0x09203436662e6465ull,0x5b202c3335646625ull,
0x31352b3032647225ull,0x69202f2f093b5d32ull,0x5f5f203336323a64ull,0x535f735f61647563ull,
0x396c6c6143326d75ull,0x3078302b34343338ull,0x36662e646461090aull,0x3435646625092034ull,
0x2c3235646625202cull,0x203b333564662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920343666ull,0x202c5d302b303264ull,0x2f093b3435646625ull,0x3436323a6469202full,
0x5f616475635f5f20ull,0x6143326d75535f73ull,0x2b34343338396c6cull,0x5f744c240a307830ull,
0x3a34373232325f31ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x6568202c38372065ull,0x6c6562616c206461ull,0x315f744c24206465ull,
0x090a36303531325full,0x636e79732e726162ull,0x202020203b300920ull,0x2020202020202020ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x3009373509373109ull,0x6168732e646c090aull,
0x203436662e646572ull,0x202c353564662509ull,0x302b39316472255bull,0x6469202f2f093b5dull,
0x635f5f203536323aull,0x75535f735f616475ull,0x3030316c6c61436dull,0x0a3078302b323933ull,
0x726168732e646c09ull,0x09203436662e6465ull,0x5b202c3635646625ull,0x35322b3931647225ull,
0x69202f2f093b5d36ull,0x5f5f203636323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,
0x3078302b32393330ull,0x36662e646461090aull,0x3735646625092034ull,0x2c3535646625202cull,
0x203b363564662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,
0x202c5d302b393164ull,0x2f093b3735646625ull,0x3736323a6469202full,0x5f616475635f5f20ull,
0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3564662509203436ull,0x326472255b202c38ull,0x2f2f093b5d302b30ull,0x203836323a646920ull,
0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,0x732e646c090a3078ull,
0x36662e6465726168ull,0x3935646625092034ull,0x30326472255b202cull,0x2f093b5d3635322bull,
0x3936323a6469202full,0x5f616475635f5f20ull,0x6143326d75535f73ull,0x2b34343338396c6cull,
0x646461090a307830ull,0x662509203436662eull,0x646625202c303664ull,0x35646625202c3835ull,
0x0a202f2f09203b39ull,0x726168732e747309ull,0x09203436662e6465ull,0x302b30326472255bull,
0x3036646625202c5dull,0x3a6469202f2f093bull,0x75635f5f20303732ull,0x6d75535f735f6164ull,
0x3338396c6c614332ull,0x090a3078302b3434ull,0x636e79732e726162ull,0x202020203b300920ull,
0x2020202020202020ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x3009383509373109ull,
0x6168732e646c090aull,0x203436662e646572ull,0x202c313664662509ull,0x302b39316472255bull,
0x6469202f2f093b5dull,0x635f5f203137323aull,0x75535f735f616475ull,0x3030316c6c61436dull,
0x0a3078302b323933ull,0x726168732e646c09ull,0x09203436662e6465ull,0x5b202c3236646625ull,
0x32312b3931647225ull,0x69202f2f093b5d38ull,0x5f5f203237323a64ull,0x535f735f61647563ull,
0x30316c6c61436d75ull,0x3078302b32393330ull,0x36662e646461090aull,0x3336646625092034ull,
0x2c3136646625202cull,0x203b323664662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,
0x72255b0920343666ull,0x202c5d302b393164ull,0x2f093b3336646625ull,0x3337323a6469202full,
0x5f616475635f5f20ull,0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e646c090a307830ull,
0x662e646572616873ull,0x3664662509203436ull,0x326472255b202c34ull,0x2f2f093b5d302b30ull,
0x203437323a646920ull,0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,
0x732e646c090a3078ull,0x36662e6465726168ull,0x3536646625092034ull,0x30326472255b202cull,
0x2f093b5d3832312bull,0x3537323a6469202full,0x5f616475635f5f20ull,0x6143326d75535f73ull,
0x2b34343338396c6cull,0x646461090a307830ull,0x662509203436662eull,0x646625202c363664ull,
0x36646625202c3436ull,0x0a202f2f09203b35ull,0x726168732e747309ull,0x09203436662e6465ull,
0x302b30326472255bull,0x3636646625202c5dull,0x3a6469202f2f093bull,0x75635f5f20363732ull,
0x6d75535f735f6164ull,0x3338396c6c614332ull,0x090a3078302b3434ull,0x636e79732e726162ull,
0x202020203b300920ull,0x2020202020202020ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x3009393509373109ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c373664662509ull,
0x302b39316472255bull,0x6469202f2f093b5dull,0x635f5f203737323aull,0x75535f735f616475ull,
0x3030316c6c61436dull,0x0a3078302b323933ull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3836646625ull,0x34362b3931647225ull,0x6469202f2f093b5dull,0x635f5f203837323aull,
0x75535f735f616475ull,0x3030316c6c61436dull,0x0a3078302b323933ull,0x3436662e64646109ull,
0x2c39366466250920ull,0x202c373664662520ull,0x09203b3836646625ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3931ull,0x2f2f093b39366466ull,
0x203937323a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,0x302b323933303031ull,
0x732e646c090a3078ull,0x36662e6465726168ull,0x3037646625092034ull,0x30326472255b202cull,
0x202f2f093b5d302bull,0x5f203038323a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,
0x78302b3434333839ull,0x68732e646c090a30ull,0x3436662e64657261ull,0x2c31376466250920ull,
0x2b30326472255b20ull,0x202f2f093b5d3436ull,0x5f203138323a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x78302b3434333839ull,0x662e646461090a30ull,0x3764662509203436ull,
0x3037646625202c32ull,0x3b3137646625202cull,0x73090a202f2f0920ull,0x6465726168732e74ull,
0x255b09203436662eull,0x2c5d302b30326472ull,0x093b323764662520ull,0x38323a6469202f2full,
0x616475635f5f2032ull,0x43326d75535f735full,0x34343338396c6c61ull,0x6162090a3078302bull,
0x0920636e79732e72ull,0x2020202020203b30ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x090a300930360937ull,0x65726168732e646cull,0x2509203436662e64ull,
0x255b202c33376466ull,0x3b5d302b39316472ull,0x323a6469202f2f09ull,0x6475635f5f203338ull,
0x436d75535f735f61ull,0x39333030316c6c61ull,0x6c090a3078302b32ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c343764ull,0x3b5d32332b393164ull,0x323a6469202f2f09ull,
0x6475635f5f203438ull,0x436d75535f735f61ull,0x39333030316c6c61ull,0x61090a3078302b32ull,
0x09203436662e6464ull,0x25202c3537646625ull,0x6625202c33376466ull,0x2f2f09203b343764ull,
0x68732e7473090a20ull,0x3436662e64657261ull,0x39316472255b0920ull,0x646625202c5d302bull,
0x69202f2f093b3537ull,0x5f5f203538323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,
0x3078302b32393330ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c363764662509ull,
0x302b30326472255bull,0x6469202f2f093b5dull,0x635f5f203638323aull,0x75535f735f616475ull,
0x38396c6c6143326dull,0x0a3078302b343433ull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3737646625ull,0x32332b3032647225ull,0x6469202f2f093b5dull,0x635f5f203738323aull,
0x75535f735f616475ull,0x38396c6c6143326dull,0x0a3078302b343433ull,0x3436662e64646109ull,
0x2c38376466250920ull,0x202c363764662520ull,0x09203b3737646625ull,0x2e7473090a202f2full,
0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3032ull,0x2f2f093b38376466ull,
0x203838323a646920ull,0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,
0x2e726162090a3078ull,0x3b300920636e7973ull,0x2020202020202020ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09373109636f6c2eull,0x646c090a30093136ull,0x2e6465726168732eull,
0x6466250920343666ull,0x6472255b202c3937ull,0x2f093b5d302b3931ull,0x3938323a6469202full,
0x5f616475635f5f20ull,0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e646c090a307830ull,
0x662e646572616873ull,0x3864662509203436ull,0x316472255b202c30ull,0x2f093b5d36312b39ull,
0x3039323a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,0x2b3239333030316cull,
0x646461090a307830ull,0x662509203436662eull,0x646625202c313864ull,0x38646625202c3937ull,
0x0a202f2f09203b30ull,0x726168732e747309ull,0x09203436662e6465ull,0x302b39316472255bull,
0x3138646625202c5dull,0x3a6469202f2f093bull,0x75635f5f20313932ull,0x6d75535f735f6164ull,
0x333030316c6c6143ull,0x090a3078302b3239ull,0x65726168732e646cull,0x2509203436662e64ull,
0x255b202c32386466ull,0x3b5d302b30326472ull,0x323a6469202f2f09ull,0x6475635f5f203239ull,
0x326d75535f735f61ull,0x343338396c6c6143ull,0x6c090a3078302b34ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c333864ull,0x3b5d36312b303264ull,0x323a6469202f2f09ull,
0x6475635f5f203339ull,0x326d75535f735f61ull,0x343338396c6c6143ull,0x61090a3078302b34ull,
0x09203436662e6464ull,0x25202c3438646625ull,0x6625202c32386466ull,0x2f2f09203b333864ull,
0x68732e7473090a20ull,0x3436662e64657261ull,0x30326472255b0920ull,0x646625202c5d302bull,
0x69202f2f093b3438ull,0x5f5f203439323a64ull,0x535f735f61647563ull,0x396c6c6143326d75ull,
0x3078302b34343338ull,0x79732e726162090aull,0x20203b300920636eull,0x2020202020202020ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x323609373109636full,0x732e646c090a3009ull,
0x36662e6465726168ull,0x3538646625092034ull,0x39316472255b202cull,0x202f2f093b5d302bull,
0x5f203539323a6469ull,0x5f735f616475635full,0x316c6c61436d7553ull,0x78302b3239333030ull,
0x68732e646c090a30ull,0x3436662e64657261ull,0x2c36386466250920ull,0x2b39316472255b20ull,
0x69202f2f093b5d38ull,0x5f5f203639323a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,
0x3078302b32393330ull,0x36662e646461090aull,0x3738646625092034ull,0x2c3538646625202cull,
0x203b363864662520ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,
0x202c5d302b393164ull,0x2f093b3738646625ull,0x3739323a6469202full,0x5f616475635f5f20ull,
0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3864662509203436ull,0x326472255b202c38ull,0x2f2f093b5d302b30ull,0x203839323a646920ull,
0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,0x732e646c090a3078ull,
0x36662e6465726168ull,0x3938646625092034ull,0x30326472255b202cull,0x202f2f093b5d382bull,
0x5f203939323a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,0x78302b3434333839ull,
0x662e646461090a30ull,0x3964662509203436ull,0x3838646625202c30ull,0x3b3938646625202cull,
0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203436662eull,0x2c5d302b30326472ull,
0x093b303964662520ull,0x30333a6469202f2full,0x616475635f5f2030ull,0x43326d75535f735full,
0x34343338396c6c61ull,0x6162090a3078302bull,0x0920636e79732e72ull,0x2020202020203b30ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300930380937ull,
0x203233732e646461ull,0x25202c3533722509ull,0x363532202c353372ull,0x2f0920202020203bull,
0x2e646461090a202full,0x6472250920343675ull,0x31647225202c3831ull,0x3b38343032202c38ull,
0x090a202f2f092020ull,0x203233752e766f6dull,0x32202c3634722509ull,0x20202020203b3535ull,
0x2f09202020202020ull,0x70746573090a202full,0x203233732e656c2eull,0x25202c3131702509ull,
0x347225202c353372ull,0x090a202f2f093b36ull,0x7262203131702540ull,0x315f744c24092061ull,
0x203b36303531325full,0x2f09202020202020ull,0x315f744c240a202full,0x0a3a34393930325full,
0x093309636f6c2e09ull,0x6d090a3009383731ull,0x09203233752e766full,0x3b30202c37347225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233752e656eull,
0x7225202c32317025ull,0x3b37347225202c31ull,0x40090a202f2f0920ull,0x6172622032317025ull,
0x5f315f744c240920ull,0x20203b3234303332ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x0a30093138310933ull,0x3436752e766f6d09ull,0x2c31326472250920ull,0x566c6c61435f6420ull,
0x0920203b65756c61ull,0x747663090a202f2full,0x3631752e3233732eull,0x202c383472250920ull,
0x782e646961746325ull,0x0a202f2f0920203bull,0x3436732e74766309ull,0x722509203233732eull,
0x347225202c323264ull,0x0920202020203b38ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c333264722509ull,0x31202c3232647225ull,0x0a202f2f09203b36ull,0x3436752e64646109ull,
0x2c34326472250920ull,0x202c313264722520ull,0x09203b3332647225ull,0x2e646c090a202f2full,
0x662e646572616873ull,0x3964662509203436ull,0x75635f5f5b202c31ull,0x6d75535f735f6164ull,
0x333030316c6c6143ull,0x2f093b5d302b3239ull,0x3130333a6469202full,0x5f616475635f5f20ull,
0x6c61436d75535f73ull,0x2b3239333030316cull,0x2e7473090a307830ull,0x662e6c61626f6c67ull,
0x6472255b09203436ull,0x25202c5d302b3432ull,0x2f2f093b31396466ull,0x203230333a646920ull,
0x61566c6c61435f64ull,0x0a3078302b65756cull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3239646625ull,0x735f616475635f5full,0x6c6143326d75535full,0x302b34343338396cull,
0x6469202f2f093b5dull,0x635f5f203330333aull,0x75535f735f616475ull,0x38396c6c6143326dull,
0x0a3078302b343433ull,0x626f6c672e747309ull,0x09203436662e6c61ull,0x382b34326472255bull,
0x3239646625202c5dull,0x3a6469202f2f093bull,0x61435f6420343033ull,0x2b65756c61566c6cull,
0x5f744c240a307830ull,0x3a32343033325f31ull,0x3309636f6c2e090aull,0x090a300933383109ull,
0x2020203b74697865ull,0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,
0x6557444c240a202full,0x4d37325a5f5f646eull,0x6c72614365746e6full,0x636f6c42656e4f6full,
0x6974704f7265506bull,0x090a3a6966506e6full,0x325a5f202f2f207dull,0x614365746e6f4d37ull,
0x6c42656e4f6f6c72ull,0x704f7265506b636full,0x0a6966506e6f6974ull,0x7972746e652e090aull,
0x6e6f4d36315a5f20ull,0x526f6c7261436574ull,0x3431506563756465ull,0x6f6974704f545f5full,
0x206965756c61566eull,0x7261702e09090a28ull,0x203436752e206d61ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6c72614365746e6full,0x506563756465526full,0x74704f545f5f3431ull,
0x65756c61566e6f69ull,0x666675425f645f69ull,0x702e09090a2c7265ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x614365746e6f4d36ull,0x63756465526f6c72ull,
0x4f545f5f34315065ull,0x6c61566e6f697470ull,0x756363615f696575ull,0x090a7b090a294e6dull,
0x33752e206765722eull,0x3e33333c72252032ull,0x206765722e090a3bull,0x647225203436752eull,
0x2e090a3b3e35323cull,0x3436662e20676572ull,0x3e36353c64662520ull,0x206765722e090a3bull,
0x702520646572702eull,0x2e090a3b3e30313cull,0x2e20646572616873ull,0x2038206e67696c61ull,
0x75635f5f2038622eull,0x6d75535f735f6164ull,0x3230316c6c614332ull,0x383430325b363534ull,
0x6168732e090a3b5dull,0x696c612e20646572ull,0x38622e2038206e67ull,0x5f616475635f5f20ull,
0x6c61436d75535f73ull,0x5b3430353430316cull,0x090a3b5d38343032ull,0x31093309636f6c2eull,
0x424c240a30093339ull,0x4d36315a5f5f3142ull,0x6c72614365746e6full,0x506563756465526full,
0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x636f6c2e090a3a69ull,0x3009323032093309ull,
0x33732e747663090aull,0x2509203631752e32ull,0x64697425202c3172ull,0x20202020203b782eull,
0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x3b317225202c3272ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x33732e766f6d090aull,0x202c337225092032ull,0x202020203b353532ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e656c2e7074ull,0x202c317025092032ull,
0x337225202c317225ull,0x202f2f092020203bull,0x203170252140090aull,0x744c240920617262ull,
0x30373533315f325full,0x202020202020203bull,0x6f6d090a202f2f09ull,0x2509203436752e76ull,
0x635f5f202c316472ull,0x75535f735f616475ull,0x30316c6c6143326dull,0x2f2f093b36353432ull,
0x752e766f6d090a20ull,0x3264722509203436ull,0x616475635f5f202cull,0x61436d75535f735full,
0x3430353430316c6cull,0x6c090a202f2f093bull,0x2e6d617261702e64ull,0x3472250920323375ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x4365746e6f4d3631ull,0x756465526f6c7261ull,
0x545f5f3431506563ull,0x61566e6f6974704full,0x6363615f6965756cull,0x2f2f093b5d4e6d75ull,
0x203835313a646920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6c72614365746e6full,
0x506563756465526full,0x74704f545f5f3431ull,0x65756c61566e6f69ull,0x4e6d756363615f69ull,
0x646c090a3078302bull,0x752e6d617261702eull,0x3364722509203436ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x4365746e6f4d3631ull,0x756465526f6c7261ull,0x545f5f3431506563ull,
0x61566e6f6974704full,0x425f645f6965756cull,0x093b5d7265666675ull,0x36313a6469202f2full,
0x616475635f5f2030ull,0x315a5f5f6d726170ull,0x614365746e6f4d36ull,0x63756465526f6c72ull,
0x4f545f5f34315065ull,0x6c61566e6f697470ull,0x75425f645f696575ull,0x3078302b72656666ull,
0x33752e747663090aull,0x2509203631752e32ull,0x61746325202c3572ull,0x2020203b782e6469ull,
0x756d090a202f2f09ull,0x3233752e6f6c2e6cull,0x25202c3672250920ull,0x3b347225202c3572ull,
0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233752e34ull,0x367225202c346472ull,
0x202020202020203bull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x202c356472250920ull,
0x3631202c34647225ull,0x202f2f092020203bull,0x36752e646461090aull,0x2c36647225092034ull,
0x25202c3364722520ull,0x202020203b356472ull,0x7663090a202f2f09ull,0x33732e3436752e74ull,
0x2c37647225092032ull,0x2020203b31722520ull,0x202f2f0920202020ull,0x36732e766f6d090aull,
0x2c38647225092034ull,0x20203b3764722520ull,0x2020202020202020ull,0x7663090a202f2f09ull,
0x31752e3233752e74ull,0x202c377225092036ull,0x3b782e6469746e25ull,0x202f2f0920202020ull,
0x36732e747663090aull,0x2509203233752e34ull,0x377225202c396472ull,0x202020202020203bull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x2c30316472250920ull,0x38202c3764722520ull,
0x202f2f092020203bull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x647225202c313164ull,
0x2020203b38202c39ull,0x6461090a202f2f09ull,0x2509203436752e64ull,0x7225202c32316472ull,
0x647225202c303164ull,0x202f2f0920203b32ull,0x36752e646461090aull,0x3331647225092034ull,
0x2c3031647225202cull,0x20203b3164722520ull,0x744c240a202f2f09ull,0x32383034315f325full,
0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,0x202c32303220656eull,
0x20676e697473656eull,0x31203a6874706564ull,0x616d69747365202cull,0x7265746920646574ull,
0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,0x093309636f6c2e09ull,0x6d090a3009343032ull,
0x09203233732e766full,0x327225202c387225ull,0x202020202020203bull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e6567ull,0x327225202c327025ull,0x20203b347225202cull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x6430202c31646625ull,0x3030303030303030ull,
0x3030303030303030ull,0x090a30202f2f093bull,0x203436662e766f6dull,0x30202c3264662509ull,
0x3030303030303064ull,0x3030303030303030ull,0x0a30202f2f093b30ull,0x7262203270254009ull,
0x325f744c24092061ull,0x203b34333438315full,0x0920202020202020ull,0x3c2f2f200a202f2full,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x32303220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3034315f325f744cull,0x2e627573090a3238ull,
0x3972250920323373ull,0x25202c347225202cull,0x20202020203b3272ull,0x090a202f2f092020ull,
0x203233732e646461ull,0x25202c3031722509ull,0x3b353532202c3972ull,0x2f09202020202020ull,
0x2e726873090a202full,0x3172250920323373ull,0x2c30317225202c31ull,0x202020203b313320ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x32202c3231722509ull,0x20202020203b3535ull,
0x2f09202020202020ull,0x2e646e61090a202full,0x3172250920323362ull,0x2c31317225202c33ull,
0x20203b3231722520ull,0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3431722509ull,
0x317225202c333172ull,0x2f09202020203b30ull,0x2e726873090a202full,0x3172250920323373ull,
0x2c34317225202c35ull,0x20202020203b3820ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,
0x3164722509203436ull,0x2c38647225202c34ull,0x2f0920203b363120ull,0x2e646461090a202full,
0x6472250920343673ull,0x36647225202c3531ull,0x3b3431647225202cull,0x200a202f2f092020ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c323032ull,0x656c6562616c2064ull,0x5f325f744c242064ull,0x6d090a3238303431ull,
0x09203233732e766full,0x7225202c36317225ull,0x20202020203b3531ull,0x2f2f092020202020ull,
0x5f325f744c240a20ull,0x200a3a3035383431ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,
0x20656e696c207964ull,0x73656e202c343032ull,0x70656420676e6974ull,0x65202c32203a6874ull,
0x646574616d697473ull,0x6974617265746920ull,0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,
0x363032093309636full,0x672e646c090a3009ull,0x36662e6c61626f6cull,0x2c33646625092034ull,
0x2b35316472255b20ull,0x69202f2f093b5d30ull,0x61090a3236313a64ull,0x09203436662e6464ull,
0x6625202c32646625ull,0x32646625202c3364ull,0x2f2f09202020203bull,0x09636f6c2e090a20ull,
0x0a30093730320933ull,0x626f6c672e646c09ull,0x09203436662e6c61ull,0x255b202c34646625ull,
0x3b5d382b35316472ull,0x313a6469202f2f09ull,0x2e646461090a3336ull,0x6466250920343666ull,
0x2c34646625202c31ull,0x20203b3164662520ull,0x090a202f2f092020ull,0x203233732e646461ull,
0x7225202c38722509ull,0x203b363532202c38ull,0x2f09202020202020ull,0x2e646461090a202full,
0x6472250920343673ull,0x31647225202c3531ull,0x3b36393034202c35ull,0x090a202f2f092020ull,
0x2e746c2e70746573ull,0x3370250920323373ull,0x25202c387225202cull,0x2f092020203b3472ull,
0x33702540090a202full,0x4c24092061726220ull,0x353834315f325f74ull,0x2020202020203b30ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c323032ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x62090a3238303431ull,0x0920696e752e6172ull,0x34315f325f744c24ull,0x202020203b383333ull,
0x2f2f092020202020ull,0x5f325f744c240a20ull,0x200a3a3433343831ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323032ull,
0x656c6562616c2064ull,0x5f325f744c242064ull,0x4c240a3238303431ull,0x333334315f325f74ull,
0x6c3c2f2f200a3a38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c32303220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x383034315f325f74ull,
0x09636f6c2e090a32ull,0x0a30093930320933ull,0x726168732e747309ull,0x09203436662e6465ull,
0x302b32316472255bull,0x3b32646625202c5dull,0x313a6469202f2f09ull,0x6475635f5f203436ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x2e090a3078302b34ull,0x3132093309636f6cull,
0x2e7473090a300930ull,0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3331ull,
0x202f2f093b316466ull,0x5f203536313a6469ull,0x5f735f616475635full,0x6c6c6143326d7553ull,
0x302b363534323031ull,0x2e646461090a3078ull,0x3272250920323375ull,0x25202c327225202cull,
0x20202020203b3772ull,0x090a202f2f092020ull,0x203436752e646461ull,0x25202c3864722509ull,
0x647225202c396472ull,0x2f09202020203b38ull,0x2e646461090a202full,0x6472250920343675ull,
0x31647225202c3331ull,0x3331647225202c31ull,0x090a202f2f09203bull,0x203436752e646461ull,
0x202c323164722509ull,0x25202c3131647225ull,0x2f09203b32316472ull,0x2e766f6d090a202full,
0x3172250920323375ull,0x203b353532202c37ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x2e656c2e70746573ull,0x3470250920323373ull,0x25202c327225202cull,0x2f0920203b373172ull,
0x34702540090a202full,0x4c24092061726220ull,0x383034315f325f74ull,0x2020202020203b32ull,
0x240a202f2f092020ull,0x3533315f325f744cull,0x6f6c2e090a3a3037ull,0x0935313209330963ull,
0x752e766f6d090a30ull,0x3164722509203436ull,0x616475635f5f202cull,0x43326d75535f735full,
0x35343230316c6c61ull,0x090a202f2f093b36ull,0x203436752e766f6dull,0x5f202c3264722509ull,
0x5f735f616475635full,0x316c6c61436d7553ull,0x2f093b3430353430ull,0x636f6c2e090a202full,
0x3009383709373109ull,0x33732e766f6d090aull,0x2c38317225092032ull,0x2020203b31722520ull,
0x2020202020202020ull,0x2140090a202f2f09ull,0x2061726220317025ull,0x315f325f744c2409ull,
0x2020203b38313635ull,0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c39317225092032ull,
0x2020203b31313520ull,0x2020202020202020ull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x317225202c303272ull,0x203b317225202c39ull,0x202f2f0920202020ull,0x33732e726873090aull,
0x2c31327225092032ull,0x33202c3032722520ull,0x2020202020203b31ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x353532202c323272ull,0x202020202020203bull,0x202f2f0920202020ull,
0x33622e646e61090aull,0x2c33327225092032ull,0x25202c3132722520ull,0x202020203b323272ull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x327225202c343272ull,0x3b30327225202c33ull,
0x202f2f0920202020ull,0x33732e726873090aull,0x2c35327225092032ull,0x38202c3432722520ull,
0x202020202020203bull,0x7663090a202f2f09ull,0x33732e3436752e74ull,0x3631647225092032ull,
0x20203b317225202cull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x647225202c373164ull,0x20203b38202c3631ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,
0x327225202c363272ull,0x2020202020203b35ull,0x202f2f0920202020ull,0x315f325f744c240aull,
0x2f200a3a30333136ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3720656e696c2079ull,
0x697473656e202c38ull,0x687470656420676eull,0x747365202c31203aull,0x6920646574616d69ull,
0x6e6f697461726574ull,0x6f6e6b6e75203a73ull,0x636f6c2e090a6e77ull,0x3009393709373109ull,
0x79732e726162090aull,0x20203b300920636eull,0x2020202020202020ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x303809373109636full,0x2e646461090a3009ull,0x6472250920343675ull,
0x31647225202c3831ull,0x3b32647225202c37ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x202c393164722509ull,0x25202c3731647225ull,0x2f0920203b316472ull,0x2e766f6d090a202full,
0x3272250920323375ull,0x203b373231202c37ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x2e74672e70746573ull,0x3570250920323373ull,0x202c38317225202cull,0x2f09203b37327225ull,
0x35702540090a202full,0x4c24092061726220ull,0x383336315f325f74ull,0x2020202020203b36ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x64616568202c3837ull,0x64656c6562616c20ull,0x315f325f744c2420ull,
0x6c2e090a30333136ull,0x323509373109636full,0x732e646c090a3009ull,0x36662e6465726168ull,
0x2c35646625092034ull,0x2b38316472255b20ull,0x69202f2f093b5d30ull,0x5f5f203636313a64ull,
0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b34303534ull,0x6168732e646c090aull,
0x203436662e646572ull,0x5b202c3664662509ull,0x30312b3831647225ull,0x202f2f093b5d3432ull,
0x5f203736313a6469ull,0x5f735f616475635full,0x316c6c61436d7553ull,0x78302b3430353430ull,
0x662e646461090a30ull,0x3764662509203436ull,0x202c35646625202cull,0x2020203b36646625ull,
0x73090a202f2f0920ull,0x6465726168732e74ull,0x255b09203436662eull,0x2c5d302b38316472ull,
0x2f093b3764662520ull,0x3836313a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3430353430316cull,0x2e646c090a307830ull,0x662e646572616873ull,0x3864662509203436ull,
0x39316472255b202cull,0x202f2f093b5d302bull,0x5f203936313a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x302b363534323031ull,0x732e646c090a3078ull,0x36662e6465726168ull,
0x2c39646625092034ull,0x2b39316472255b20ull,0x2f093b5d34323031ull,0x3037313a6469202full,
0x5f616475635f5f20ull,0x6143326d75535f73ull,0x3635343230316c6cull,0x6461090a3078302bull,
0x2509203436662e64ull,0x6625202c30316466ull,0x39646625202c3864ull,0x202f2f092020203bull,
0x6168732e7473090aull,0x203436662e646572ull,0x2b39316472255b09ull,0x31646625202c5d30ull,
0x6469202f2f093b30ull,0x635f5f203137313aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x315f325f744c240aull,0x2f200a3a36383336ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3720656e696c2079ull,0x2064616568202c38ull,
0x2064656c6562616cull,0x36315f325f744c24ull,0x726162090a303331ull,0x300920636e79732eull,
0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,0x3233752e766f6d09ull,
0x202c383272250920ull,0x20202020203b3336ull,0x0920202020202020ull,0x746573090a202f2full,
0x3233732e74672e70ull,0x25202c3670250920ull,0x327225202c383172ull,0x0a202f2f09203b38ull,
0x7262203670254009ull,0x325f744c24092061ull,0x203b38393836315full,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x2c383720656e696cull,0x616c206461656820ull,0x4c242064656c6562ull,0x333136315f325f74ull,
0x09636f6c2e090a30ull,0x0a30093335093731ull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3131646625ull,0x5d302b3831647225ull,0x3a6469202f2f093bull,0x75635f5f20323731ull,
0x6d75535f735f6164ull,0x353430316c6c6143ull,0x090a3078302b3430ull,0x65726168732e646cull,
0x2509203436662e64ull,0x255b202c32316466ull,0x3231352b38316472ull,0x6469202f2f093b5dull,
0x635f5f203337313aull,0x75535f735f616475ull,0x3430316c6c61436dull,0x0a3078302b343035ull,
0x3436662e64646109ull,0x2c33316466250920ull,0x202c313164662520ull,0x09203b3231646625ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3831ull,
0x2f2f093b33316466ull,0x203437313a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,
0x302b343035343031ull,0x732e646c090a3078ull,0x36662e6465726168ull,0x3431646625092034ull,
0x39316472255b202cull,0x202f2f093b5d302bull,0x5f203537313a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x302b363534323031ull,0x732e646c090a3078ull,0x36662e6465726168ull,
0x3531646625092034ull,0x39316472255b202cull,0x2f093b5d3231352bull,0x3637313a6469202full,
0x5f616475635f5f20ull,0x6143326d75535f73ull,0x3635343230316c6cull,0x6461090a3078302bull,
0x2509203436662e64ull,0x6625202c36316466ull,0x646625202c343164ull,0x202f2f09203b3531ull,
0x6168732e7473090aull,0x203436662e646572ull,0x2b39316472255b09ull,0x31646625202c5d30ull,
0x6469202f2f093b36ull,0x635f5f203737313aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x315f325f744c240aull,0x2f200a3a38393836ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3720656e696c2079ull,0x2064616568202c38ull,
0x2064656c6562616cull,0x36315f325f744c24ull,0x726162090a303331ull,0x300920636e79732eull,
0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,0x373109636f6c2e09ull,
0x6c090a3009373509ull,0x6465726168732e64ull,0x662509203436662eull,0x72255b202c373164ull,
0x093b5d302b383164ull,0x37313a6469202f2full,0x616475635f5f2038ull,0x61436d75535f735full,
0x3430353430316c6cull,0x646c090a3078302bull,0x2e6465726168732eull,0x6466250920343666ull,
0x6472255b202c3831ull,0x3b5d3635322b3831ull,0x313a6469202f2f09ull,0x6475635f5f203937ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x61090a3078302b34ull,0x09203436662e6464ull,
0x25202c3931646625ull,0x6625202c37316466ull,0x2f2f09203b383164ull,0x68732e7473090a20ull,
0x3436662e64657261ull,0x38316472255b0920ull,0x646625202c5d302bull,0x69202f2f093b3931ull,
0x5f5f203038313a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b34303534ull,
0x6168732e646c090aull,0x203436662e646572ull,0x202c303264662509ull,0x302b39316472255bull,
0x6469202f2f093b5dull,0x635f5f203138313aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x6168732e646c090aull,0x203436662e646572ull,0x202c313264662509ull,
0x322b39316472255bull,0x202f2f093b5d3635ull,0x5f203238313a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x302b363534323031ull,0x2e646461090a3078ull,0x6466250920343666ull,
0x32646625202c3232ull,0x3132646625202c30ull,0x090a202f2f09203bull,0x65726168732e7473ull,
0x5b09203436662e64ull,0x5d302b3931647225ull,0x3b3232646625202cull,0x313a6469202f2f09ull,
0x6475635f5f203338ull,0x326d75535f735f61ull,0x343230316c6c6143ull,0x090a3078302b3635ull,
0x636e79732e726162ull,0x202020203b300920ull,0x2020202020202020ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x3009383509373109ull,0x6168732e646c090aull,0x203436662e646572ull,
0x202c333264662509ull,0x302b38316472255bull,0x6469202f2f093b5dull,0x635f5f203438313aull,
0x75535f735f616475ull,0x3430316c6c61436dull,0x0a3078302b343035ull,0x726168732e646c09ull,
0x09203436662e6465ull,0x5b202c3432646625ull,0x32312b3831647225ull,0x69202f2f093b5d38ull,
0x5f5f203538313a64ull,0x535f735f61647563ull,0x30316c6c61436d75ull,0x3078302b34303534ull,
0x36662e646461090aull,0x3532646625092034ull,0x2c3332646625202cull,0x203b343264662520ull,
0x7473090a202f2f09ull,0x2e6465726168732eull,0x72255b0920343666ull,0x202c5d302b383164ull,
0x2f093b3532646625ull,0x3638313a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3430353430316cull,0x2e646c090a307830ull,0x662e646572616873ull,0x3264662509203436ull,
0x316472255b202c36ull,0x2f2f093b5d302b39ull,0x203738313a646920ull,0x735f616475635f5full,
0x6c6143326d75535full,0x2b3635343230316cull,0x2e646c090a307830ull,0x662e646572616873ull,
0x3264662509203436ull,0x316472255b202c37ull,0x093b5d3832312b39ull,0x38313a6469202f2full,
0x616475635f5f2038ull,0x43326d75535f735full,0x35343230316c6c61ull,0x61090a3078302b36ull,
0x09203436662e6464ull,0x25202c3832646625ull,0x6625202c36326466ull,0x2f2f09203b373264ull,
0x68732e7473090a20ull,0x3436662e64657261ull,0x39316472255b0920ull,0x646625202c5d302bull,
0x69202f2f093b3832ull,0x5f5f203938313a64ull,0x535f735f61647563ull,0x316c6c6143326d75ull,
0x78302b3635343230ull,0x732e726162090a30ull,0x203b300920636e79ull,0x2020202020202020ull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3509373109636f6cull,0x2e646c090a300939ull,
0x662e646572616873ull,0x3264662509203436ull,0x316472255b202c39ull,0x2f2f093b5d302b38ull,
0x203039313a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,0x302b343035343031ull,
0x732e646c090a3078ull,0x36662e6465726168ull,0x3033646625092034ull,0x38316472255b202cull,
0x2f2f093b5d34362bull,0x203139313a646920ull,0x735f616475635f5full,0x6c6c61436d75535full,
0x302b343035343031ull,0x2e646461090a3078ull,0x6466250920343666ull,0x32646625202c3133ull,
0x3033646625202c39ull,0x090a202f2f09203bull,0x65726168732e7473ull,0x5b09203436662e64ull,
0x5d302b3831647225ull,0x3b3133646625202cull,0x313a6469202f2f09ull,0x6475635f5f203239ull,
0x436d75535f735f61ull,0x30353430316c6c61ull,0x6c090a3078302b34ull,0x6465726168732e64ull,
0x662509203436662eull,0x72255b202c323364ull,0x093b5d302b393164ull,0x39313a6469202f2full,
0x616475635f5f2033ull,0x43326d75535f735full,0x35343230316c6c61ull,0x6c090a3078302b36ull,
0x6465726168732e64ull,0x662509203436662eull,0x72255b202c333364ull,0x3b5d34362b393164ull,
0x313a6469202f2f09ull,0x6475635f5f203439ull,0x326d75535f735f61ull,0x343230316c6c6143ull,
0x090a3078302b3635ull,0x203436662e646461ull,0x202c343364662509ull,0x25202c3233646625ull,
0x2f09203b33336466ull,0x732e7473090a202full,0x36662e6465726168ull,0x316472255b092034ull,
0x6625202c5d302b39ull,0x202f2f093b343364ull,0x5f203539313a6469ull,0x5f735f616475635full,
0x6c6c6143326d7553ull,0x302b363534323031ull,0x2e726162090a3078ull,0x3b300920636e7973ull,
0x2020202020202020ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09373109636f6c2eull,
0x646c090a30093036ull,0x2e6465726168732eull,0x6466250920343666ull,0x6472255b202c3533ull,
0x2f093b5d302b3831ull,0x3639313a6469202full,0x5f616475635f5f20ull,0x6c61436d75535f73ull,
0x2b3430353430316cull,0x2e646c090a307830ull,0x662e646572616873ull,0x3364662509203436ull,
0x316472255b202c36ull,0x2f093b5d32332b38ull,0x3739313a6469202full,0x5f616475635f5f20ull,
0x6c61436d75535f73ull,0x2b3430353430316cull,0x646461090a307830ull,0x662509203436662eull,
0x646625202c373364ull,0x33646625202c3533ull,0x0a202f2f09203b36ull,0x726168732e747309ull,
0x09203436662e6465ull,0x302b38316472255bull,0x3733646625202c5dull,0x3a6469202f2f093bull,
0x75635f5f20383931ull,0x6d75535f735f6164ull,0x353430316c6c6143ull,0x090a3078302b3430ull,
0x65726168732e646cull,0x2509203436662e64ull,0x255b202c38336466ull,0x3b5d302b39316472ull,
0x313a6469202f2f09ull,0x6475635f5f203939ull,0x326d75535f735f61ull,0x343230316c6c6143ull,
0x090a3078302b3635ull,0x65726168732e646cull,0x2509203436662e64ull,0x255b202c39336466ull,
0x5d32332b39316472ull,0x3a6469202f2f093bull,0x75635f5f20303032ull,0x6d75535f735f6164ull,
0x3230316c6c614332ull,0x0a3078302b363534ull,0x3436662e64646109ull,0x2c30346466250920ull,
0x202c383364662520ull,0x09203b3933646625ull,0x2e7473090a202f2full,0x662e646572616873ull,
0x6472255b09203436ull,0x25202c5d302b3931ull,0x2f2f093b30346466ull,0x203130323a646920ull,
0x735f616475635f5full,0x6c6143326d75535full,0x2b3635343230316cull,0x726162090a307830ull,
0x300920636e79732eull,0x202020202020203bull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x373109636f6c2e09ull,0x6c090a3009313609ull,0x6465726168732e64ull,0x662509203436662eull,
0x72255b202c313464ull,0x093b5d302b383164ull,0x30323a6469202f2full,0x616475635f5f2032ull,
0x61436d75535f735full,0x3430353430316c6cull,0x646c090a3078302bull,0x2e6465726168732eull,
0x6466250920343666ull,0x6472255b202c3234ull,0x093b5d36312b3831ull,0x30323a6469202f2full,
0x616475635f5f2033ull,0x61436d75535f735full,0x3430353430316c6cull,0x6461090a3078302bull,
0x2509203436662e64ull,0x6625202c33346466ull,0x646625202c313464ull,0x202f2f09203b3234ull,
0x6168732e7473090aull,0x203436662e646572ull,0x2b38316472255b09ull,0x34646625202c5d30ull,
0x6469202f2f093b33ull,0x635f5f203430323aull,0x75535f735f616475ull,0x3430316c6c61436dull,
0x0a3078302b343035ull,0x726168732e646c09ull,0x09203436662e6465ull,0x5b202c3434646625ull,
0x5d302b3931647225ull,0x3a6469202f2f093bull,0x75635f5f20353032ull,0x6d75535f735f6164ull,
0x3230316c6c614332ull,0x0a3078302b363534ull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3534646625ull,0x36312b3931647225ull,0x6469202f2f093b5dull,0x635f5f203630323aull,
0x75535f735f616475ull,0x30316c6c6143326dull,0x3078302b36353432ull,0x36662e646461090aull,
0x3634646625092034ull,0x2c3434646625202cull,0x203b353464662520ull,0x7473090a202f2f09ull,
0x2e6465726168732eull,0x72255b0920343666ull,0x202c5d302b393164ull,0x2f093b3634646625ull,
0x3730323a6469202full,0x5f616475635f5f20ull,0x6143326d75535f73ull,0x3635343230316c6cull,
0x6162090a3078302bull,0x0920636e79732e72ull,0x2020202020203b30ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300932360937ull,0x65726168732e646cull,
0x2509203436662e64ull,0x255b202c37346466ull,0x3b5d302b38316472ull,0x323a6469202f2f09ull,
0x6475635f5f203830ull,0x436d75535f735f61ull,0x30353430316c6c61ull,0x6c090a3078302b34ull,
0x6465726168732e64ull,0x662509203436662eull,0x72255b202c383464ull,0x093b5d382b383164ull,
0x30323a6469202f2full,0x616475635f5f2039ull,0x61436d75535f735full,0x3430353430316c6cull,
0x6461090a3078302bull,0x2509203436662e64ull,0x6625202c39346466ull,0x646625202c373464ull,
0x202f2f09203b3834ull,0x6168732e7473090aull,0x203436662e646572ull,0x2b38316472255b09ull,
0x34646625202c5d30ull,0x6469202f2f093b39ull,0x635f5f203031323aull,0x75535f735f616475ull,
0x3430316c6c61436dull,0x0a3078302b343035ull,0x726168732e646c09ull,0x09203436662e6465ull,
0x5b202c3035646625ull,0x5d302b3931647225ull,0x3a6469202f2f093bull,0x75635f5f20313132ull,
0x6d75535f735f6164ull,0x3230316c6c614332ull,0x0a3078302b363534ull,0x726168732e646c09ull,
0x09203436662e6465ull,0x5b202c3135646625ull,0x5d382b3931647225ull,0x3a6469202f2f093bull,
0x75635f5f20323132ull,0x6d75535f735f6164ull,0x3230316c6c614332ull,0x0a3078302b363534ull,
0x3436662e64646109ull,0x2c32356466250920ull,0x202c303564662520ull,0x09203b3135646625ull,
0x2e7473090a202f2full,0x662e646572616873ull,0x6472255b09203436ull,0x25202c5d302b3931ull,
0x2f2f093b32356466ull,0x203331323a646920ull,0x735f616475635f5full,0x6c6143326d75535full,
0x2b3635343230316cull,0x726162090a307830ull,0x300920636e79732eull,0x202020202020203bull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x373109636f6c2e09ull,0x61090a3009303809ull,
0x09203233732e6464ull,0x7225202c38317225ull,0x3b363532202c3831ull,0x2f2f092020202020ull,
0x752e646461090a20ull,0x3164722509203436ull,0x3731647225202c37ull,0x203b38343032202cull,
0x6d090a202f2f0920ull,0x09203233752e766full,0x3532202c39327225ull,0x2020202020203b35ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e656cull,0x317225202c377025ull,
0x3b39327225202c38ull,0x40090a202f2f0920ull,0x2061726220377025ull,0x315f325f744c2409ull,
0x2020203b30333136ull,0x2f2f092020202020ull,0x5f325f744c240a20ull,0x090a3a3831363531ull,
0x32093309636f6c2eull,0x6f6d090a30093531ull,0x2509203233752e76ull,0x203b30202c303372ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x6e2e70746573090aull,0x2509203233752e65ull,
0x2c317225202c3870ull,0x20203b3033722520ull,0x2540090a202f2f09ull,0x0920617262203870ull,
0x37315f325f744c24ull,0x202020203b363636ull,0x202f2f0920202020ull,0x3309636f6c2e090aull,
0x090a300938313209ull,0x203436752e766f6dull,0x202c303264722509ull,0x61566c6c61435f64ull,
0x2f0920203b65756cull,0x2e747663090a202full,0x203631752e323375ull,0x25202c3133722509ull,
0x3b782e6469617463ull,0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x31337225202c3132ull,0x2f0920202020203bull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x25202c3232647225ull,0x3631202c31326472ull,0x090a202f2f09203bull,0x203436752e646461ull,
0x202c333264722509ull,0x25202c3032647225ull,0x2f09203b32326472ull,0x732e646c090a202full,
0x36662e6465726168ull,0x3335646625092034ull,0x6475635f5f5b202cull,0x436d75535f735f61ull,
0x30353430316c6c61ull,0x2f2f093b5d302b34ull,0x203431323a646920ull,0x735f616475635f5full,
0x6c6c61436d75535full,0x302b343035343031ull,0x672e7473090a3078ull,0x36662e6c61626f6cull,
0x326472255b092034ull,0x6625202c5d302b33ull,0x202f2f093b333564ull,0x64203531323a6469ull,
0x6c61566c6c61435full,0x090a3078302b6575ull,0x65726168732e646cull,0x2509203436662e64ull,
0x5f5b202c34356466ull,0x5f735f616475635full,0x6c6c6143326d7553ull,0x302b363534323031ull,
0x6469202f2f093b5dull,0x635f5f203631323aull,0x75535f735f616475ull,0x30316c6c6143326dull,
0x3078302b36353432ull,0x6f6c672e7473090aull,0x203436662e6c6162ull,0x2b33326472255b09ull,
0x35646625202c5d38ull,0x6469202f2f093b34ull,0x435f64203731323aull,0x65756c61566c6c61ull,
0x744c240a3078302bull,0x36363637315f325full,0x09636f6c2e090a3aull,0x0a30093032320933ull,
0x20203b7469786509ull,0x2020202020202020ull,0x2020202020202020ull,0x0920202020202020ull,
0x57444c240a202f2full,0x36315a5f5f646e65ull,0x72614365746e6f4dull,0x6563756465526f6cull,
0x704f545f5f343150ull,0x756c61566e6f6974ull,0x2f207d090a3a6965ull,0x6f4d36315a5f202full,
0x6f6c72614365746eull,0x3150656375646552ull,0x6974704f545f5f34ull,0x6965756c61566e6full,
0x72746e652e090a0aull,0x6e6936315a5f2079ull,0x444e436573726576ull,0x66506c656e72654bull,
0x09090a28206a5f53ull,0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,
0x7265766e6936315aull,0x72654b444e436573ull,0x6a5f5366506c656eull,0x757074754f5f645full,
0x61702e09090a2c74ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x36315a5f5f6d7261ull,
0x4365737265766e69ull,0x6c656e72654b444eull,0x5f645f6a5f536650ull,0x090a2c7475706e49ull,
0x206d617261702e09ull,0x635f5f203233752eull,0x5f6d726170616475ull,0x65766e6936315a5full,
0x654b444e43657372ull,0x5f5366506c656e72ull,0x294e687461705f6aull,0x65722e090a7b090aull,
0x25203233752e2067ull,0x0a3b3e3334323c72ull,0x752e206765722e09ull,0x313c647225203436ull,
0x65722e090a3b3e37ull,0x25203233662e2067ull,0x2e090a3b3e353c66ull,0x3436662e20676572ull,
0x3039333c64662520ull,0x6765722e090a3b3eull,0x2520646572702e20ull,0x090a3b3e33363c70ull,
0x09383109636f6c2eull,0x4c240a3009313532ull,0x36315a5f5f314242ull,0x4365737265766e69ull,
0x6c656e72654b444eull,0x090a3a6a5f536650ull,0x6d617261702e646cull,0x722509203233752eull,
0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x7265766e6936315aull,0x72654b444e436573ull,
0x6a5f5366506c656eull,0x3b5d4e687461705full,0x313a6469202f2f09ull,0x75635f5f20333430ull,
0x5f5f6d7261706164ull,0x7265766e6936315aull,0x72654b444e436573ull,0x6a5f5366506c656eull,
0x302b4e687461705full,0x2e747663090a3078ull,0x203631752e323375ull,0x7425202c32722509ull,
0x2020203b782e6469ull,0x090a202f2f092020ull,0x2e3233752e747663ull,0x3372250920363175ull,
0x646961746325202cull,0x2f092020203b782eull,0x2e747663090a202full,0x203631752e323375ull,
0x6e25202c34722509ull,0x20203b782e646974ull,0x090a202f2f092020ull,0x6d617261702e646cull,
0x722509203436752eull,0x635f5f5b202c3164ull,0x5f6d726170616475ull,0x65766e6936315a5full,
0x654b444e43657372ull,0x5f5366506c656e72ull,0x75706e495f645f6aull,0x69202f2f093b5d74ull,
0x5f20373430313a64ull,0x726170616475635full,0x6e6936315a5f5f6dull,0x444e436573726576ull,
0x66506c656e72654bull,0x6e495f645f6a5f53ull,0x0a3078302b747570ull,0x3436752e766f6d09ull,
0x202c326472250920ull,0x2020202020203b30ull,0x0920202020202020ull,0x746573090a202f2full,
0x3436752e71652e70ull,0x25202c3170250920ull,0x647225202c316472ull,0x0a202f2f09203b32ull,
0x7262203170254009ull,0x335f744c24092061ull,0x203b36363036355full,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3935320938310963ull,0x326c756d090a3009ull,0x3233752e6f6c2e34ull,
0x25202c3572250920ull,0x3b337225202c3472ull,0x090a202f2f092020ull,0x203233752e646461ull,
0x7225202c36722509ull,0x203b327225202c35ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3772250920323373ull,0x20203b367225202cull,0x2020202020202020ull,0x090a202f2f092020ull,
0x2e65672e70746573ull,0x3270250920323375ull,0x25202c367225202cull,0x2f092020203b3172ull,
0x32702540090a202full,0x4c24092061726220ull,0x323139365f335f74ull,0x2020202020203b32ull,
0x090a202f2f092020ull,0x2e3233752e747663ull,0x3872250920363175ull,0x696174636e25202cull,
0x2f0920203b782e64ull,0x326c756d090a202full,0x3233752e6f6c2e34ull,0x25202c3972250920ull,
0x3b387225202c3472ull,0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x203b367225202c33ull,0x2f09202020202020ull,0x2e747663090a202full,0x203233752e343673ull,
0x25202c3464722509ull,0x20202020203b3972ull,0x090a202f2f092020ull,0x752e6f6c2e6c756dull,
0x3564722509203436ull,0x202c33647225202cull,0x2f09202020203b34ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c36647225ull,0x20203b34202c3464ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3764722509ull,0x647225202c356472ull,0x2f09202020203b31ull,
0x702e646c090a202full,0x3436752e6d617261ull,0x202c386472250920ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x4365737265766e69ull,0x6c656e72654b444eull,0x5f645f6a5f536650ull,
0x3b5d74757074754full,0x313a6469202f2f09ull,0x75635f5f20393430ull,0x5f5f6d7261706164ull,
0x7265766e6936315aull,0x72654b444e436573ull,0x6a5f5366506c656eull,0x757074754f5f645full,
0x61090a3078302b74ull,0x09203436752e6464ull,0x7225202c39647225ull,0x35647225202c3864ull,
0x2f2f09202020203bull,0x5f335f744c240a20ull,0x200a3a3433383635ull,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a303632ull,0x3036320938310963ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x202c316625092032ull,0x5d302b376472255bull,
0x6469202f2f09203bull,0x63090a303530313aull,0x662e3436662e7476ull,0x3164662509203233ull,
0x20203b316625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009313632093831ull,
0x36662e766f6d090aull,0x2c32646625092034ull,0x3030666633643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x672e746573090a31ull,0x36662e3233752e65ull,0x2c30317225092034ull,
0x25202c3164662520ull,0x202f2f093b326466ull,0x33732e67656e090aull,0x2c31317225092032ull,
0x20203b3031722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x306430202c336466ull,0x3030303030303030ull,0x3b30303030303030ull,0x73090a30202f2f09ull,
0x33752e656c2e7465ull,0x2509203436662e32ull,0x646625202c323172ull,0x3b33646625202c31ull,
0x656e090a202f2f09ull,0x2509203233732e67ull,0x317225202c333172ull,0x2020202020203b32ull,
0x202f2f0920202020ull,0x3233622e726f090aull,0x202c343172250920ull,0x7225202c31317225ull,
0x20202020203b3331ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x203b30202c353172ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x652e70746573090aull,0x2509203233732e71ull,
0x34317225202c3370ull,0x203b35317225202cull,0x2540090a202f2f09ull,0x0920617262203370ull,
0x37355f335f744c24ull,0x202020203b303930ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,0x3436662e766f6d09ull,
0x202c346466250920ull,0x3030386666666430ull,0x3030303030303030ull,0x6e202f2f093b3030ull,
0x2e617262090a6e61ull,0x744c240920696e75ull,0x3b383138325f335full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3037355f335f744cull,0x3c2f2f200a3a3039ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3836355f335f744cull,0x636f6c2e090a3433ull,0x0933323109383109ull,
0x662e766f6d090a30ull,0x3564662509203436ull,0x306566626430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x61090a352e302d20ull,0x09203436662e6464ull,0x6625202c36646625ull,
0x35646625202c3164ull,0x2f2f09202020203bull,0x662e736261090a20ull,0x3764662509203436ull,
0x203b36646625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x6430202c38646625ull,0x3734316561646633ull,0x3165613734316561ull,0x342e30202f2f093bull,
0x2e70746573090a32ull,0x09203436662e746cull,0x646625202c347025ull,0x3b38646625202c37ull,
0x40090a202f2f0920ull,0x6172622034702521ull,0x5f335f744c240920ull,0x20203b3835383735ull,
0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34333836355f335full,0x3109636f6c2e090aull,0x0a30093532310938ull,0x3436662e6c756d09ull,
0x202c396466250920ull,0x6625202c36646625ull,0x09202020203b3664ull,0x766f6d090a202f2full,
0x662509203436662eull,0x346430202c303164ull,0x3133396430343030ull,0x3b64303236383262ull,
0x30352e32202f2f09ull,0x766f6d090a333636ull,0x662509203436662eull,0x636430202c313164ull,
0x6130376439323330ull,0x3b65643361343565ull,0x2e38312d202f2f09ull,0x766f6d090a353136ull,
0x662509203436662eull,0x346430202c323164ull,0x6332313262343430ull,0x3b63663663333734ull,
0x332e3134202f2f09ull,0x766f6d090a323139ull,0x662509203436662eull,0x636430202c333164ull,
0x3539653037393330ull,0x3b38373737373337ull,0x2e35322d202f2f09ull,0x616d090a31313434ull,
0x3436662e6e722e64ull,0x2c34316466250920ull,0x202c333164662520ull,0x6625202c39646625ull,
0x202f2f093b323164ull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c353164ull,
0x3431646625202c39ull,0x3b3131646625202cull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c36316466250920ull,0x25202c3964662520ull,0x6625202c35316466ull,0x202f2f093b303164ull,
0x36662e6c756d090aull,0x3731646625092034ull,0x202c36646625202cull,0x20203b3631646625ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x6430202c38316466ull,0x3030303030666633ull,
0x3030303030303030ull,0x090a31202f2f093bull,0x203436662e766f6dull,0x202c393164662509ull,
0x3266303230636430ull,0x3730353536303037ull,0x2d202f2f093b6432ull,0x0a31353337342e38ull,
0x3436662e766f6d09ull,0x2c30326466250920ull,0x3137333034643020ull,0x3531383139373535ull,
0x202f2f093b633230ull,0x0a343338302e3332ull,0x3436662e766f6d09ull,0x2c31326466250920ull,
0x3035333063643020ull,0x6531303730666566ull,0x202f2f093b643735ull,0x323236302e31322dull,
0x36662e766f6d090aull,0x3232646625092034ull,0x393030346430202cull,0x3535303230666230ull,
0x2f2f093b37346138ull,0x33383033312e3320ull,0x6e722e64616d090aull,0x662509203436662eull,
0x646625202c333264ull,0x39646625202c3232ull,0x3b3132646625202cull,0x616d090a202f2f09ull,
0x3436662e6e722e64ull,0x2c34326466250920ull,0x25202c3964662520ull,0x6625202c33326466ull,
0x202f2f093b303264ull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c353264ull,
0x3432646625202c39ull,0x3b3931646625202cull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c36326466250920ull,0x25202c3964662520ull,0x6625202c35326466ull,0x202f2f093b383164ull,
0x6e722e766964090aull,0x662509203436662eull,0x646625202c373264ull,0x32646625202c3731ull,
0x090a202f2f093b36ull,0x20696e752e617262ull,0x355f335f744c2409ull,0x2020203b32303637ull,
0x2f09202020202020ull,0x335f744c240a202full,0x0a3a38353837355full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333836355full,0x203436662e766f6dull,
0x202c383264662509ull,0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,
0x672e70746573090aull,0x2509203436662e74ull,0x36646625202c3570ull,0x3b3832646625202cull,
0x2140090a202f2f09ull,0x2061726220357025ull,0x355f335f744c2409ull,0x2020203b30373338ull,
0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34333836355f33ull,0x383209636f6c2e09ull,0x090a300935343509ull,0x203436662e766f6dull,
0x202c393264662509ull,0x3030306666336430ull,0x3030303030303030ull,0x31202f2f093b3030ull,
0x36662e627573090aull,0x3033646625092034ull,0x2c3932646625202cull,0x20203b3164662520ull,
0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x3172252c36317225ull,0x33646625202c7d37ull,
0x202f2f0920203b30ull,0x33732e766f6d090aull,0x2c38317225092032ull,0x20203b3731722520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x343509383209636full,0x766f6d090a300936ull,
0x257b09203436622eull,0x303272252c393172ull,0x3033646625202c7dull,0x0a202f2f0920203bull,
0x383209636f6c2e09ull,0x090a300938343509ull,0x203436662e766f6dull,0x202c313364662509ull,
0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,0x74672e746573090aull,
0x3436662e3233752eull,0x202c313272250920ull,0x25202c3033646625ull,0x2f2f093b31336466ull,
0x732e67656e090a20ull,0x3232722509203233ull,0x203b31327225202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x30202c3233646625ull,0x3030303066663764ull,
0x3030303030303030ull,0x6e69202f2f093b30ull,0x6c2e746573090a66ull,0x36662e3233752e74ull,
0x2c33327225092034ull,0x202c303364662520ull,0x2f093b3233646625ull,0x2e67656e090a202full,
0x3272250920323373ull,0x3b33327225202c34ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233622e646e61ull,0x25202c3532722509ull,0x327225202c323272ull,0x2f09202020203b34ull,
0x2e766f6d090a202full,0x3272250920323375ull,0x2020203b30202c36ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e71652e70746573ull,0x3670250920323373ull,0x202c35327225202cull,
0x2f09203b36327225ull,0x36702540090a202full,0x4c24092061726220ull,0x383639335f335f74ull,
0x2020202020203b32ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3433383635ull,0x09203233752e766full,0x3031202c37327225ull,
0x20203b3537353834ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233752e7467ull,
0x317225202c377025ull,0x3b37327225202c37ull,0x40090a202f2f0920ull,0x2061726220377025ull,
0x355f335f744c2409ull,0x2020203b32383838ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333836355f335full,0x3209636f6c2e090aull,
0x0a30093435350938ull,0x3436662e766f6d09ull,0x2c33336466250920ull,0x3030353334643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x6534343130382e31ull,0x6c756d090a36312bull,
0x662509203436662eull,0x646625202c343364ull,0x33646625202c3033ull,0x0a202f2f09203b33ull,
0x3436622e766f6d09ull,0x2c383272257b0920ull,0x25202c7d38317225ull,0x0920203b34336466ull,
0x6f6c2e090a202f2full,0x3535350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,
0x7d393272252c3931ull,0x3b3433646625202cull,0x090a202f2f092020ull,0x203233732e766f6dull,
0x2d202c3033722509ull,0x2020203b37373031ull,0x2f09202020202020ull,0x2e617262090a202full,
0x744c240920696e75ull,0x36323638355f335full,0x202020202020203bull,0x240a202f2f092020ull,
0x3838355f335f744cull,0x3c2f2f200a3a3238ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3836355f335f744cull,0x2e766f6d090a3433ull,0x3372250920323373ull,0x333230312d202c30ull,
0x202020202020203bull,0x240a202f2f092020ull,0x3638355f335f744cull,0x3c2f2f200a3a3632ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3836355f335f744cull,0x636f6c2e090a3433ull,
0x0930363509383209ull,0x732e726873090a30ull,0x3133722509203233ull,0x202c38317225202cull,
0x20202020203b3032ull,0x61090a202f2f0920ull,0x09203233622e646eull,0x7225202c32337225ull,
0x37343032202c3133ull,0x2f2f09202020203bull,0x732e646461090a20ull,0x3033722509203233ull,
0x202c30337225202cull,0x2020203b32337225ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,
0x6e61090a30093236ull,0x2509203233622e64ull,0x317225202c333372ull,0x363431322d202c38ull,
0x093b333730353334ull,0x2e726f090a202f2full,0x3372250920323362ull,0x2c33337225202c34ull,
0x3339363237303120ull,0x202f2f093b383432ull,0x36622e766f6d090aull,0x3533646625092034ull,
0x2c393172257b202cull,0x20203b7d34337225ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x373031202c353372ull,0x3b32383537323133ull,0x202f2f0920202020ull,0x6c2e70746573090aull,
0x2509203233752e65ull,0x34337225202c3870ull,0x203b35337225202cull,0x2540090a202f2f09ull,
0x0920617262203870ull,0x39355f335f744c24ull,0x202020203b383331ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,
0x383209636f6c2e09ull,0x090a300934363509ull,0x203436622e766f6dull,0x252c363372257b09ull,
0x6625202c7d373372ull,0x2f0920203b353364ull,0x2e627573090a202full,0x3372250920323373ull,
0x2c37337225202c38ull,0x3637353834303120ull,0x090a202f2f09203bull,0x203436622e766f6dull,
0x252c393372257b09ull,0x6625202c7d303472ull,0x2f0920203b353364ull,0x2e766f6d090a202full,
0x6466250920343662ull,0x3372257b202c3533ull,0x3b7d383372252c39ull,0x090a202f2f092020ull,
0x09383209636f6c2eull,0x61090a3009353635ull,0x09203233732e6464ull,0x7225202c30337225ull,
0x20203b31202c3033ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,0x200a3a3833313935ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3433383635ull,
0x3509383209636f6cull,0x6f6d090a30093937ull,0x2509203436662e76ull,0x6430202c36336466ull,
0x3030303030666662ull,0x3030303030303030ull,0x0a312d202f2f093bull,0x3436662e64646109ull,
0x2c37336466250920ull,0x202c353364662520ull,0x09203b3633646625ull,0x766f6d090a202f2full,
0x662509203436662eull,0x336430202c383364ull,0x3030303030306666ull,0x3b30303030303030ull,
0x61090a31202f2f09ull,0x09203436662e6464ull,0x25202c3933646625ull,0x6625202c35336466ull,
0x2f2f09203b383364ull,0x722e706372090a20ull,0x2509203436662e6eull,0x6625202c30346466ull,
0x202020203b393364ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3134646625ull,
0x6625202c37336466ull,0x2f2f09203b303464ull,0x662e646461090a20ull,0x3464662509203436ull,
0x3134646625202c32ull,0x3b3134646625202cull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,
0x25202c3334646625ull,0x6625202c32346466ull,0x2f2f09203b323464ull,0x662e766f6d090a20ull,
0x3464662509203436ull,0x6265336430202c34ull,0x6561336230383331ull,0x2f093b6531663038ull,
0x333632302e31202full,0x6d090a36302d6533ull,0x09203436662e766full,0x30202c3534646625ull,
0x3265653064653364ull,0x3062386137623835ull,0x2e34202f2f093b34ull,0x302d653934363330ull,
0x722e64616d090a36ull,0x2509203436662e6eull,0x6625202c36346466ull,0x646625202c343464ull,
0x34646625202c3334ull,0x090a202f2f093b35ull,0x203436662e766f6dull,0x202c373464662509ull,
0x3262336665336430ull,0x3736323066393636ull,0x31202f2f093b6636ull,0x2d6534343837382eull,
0x2e64616d090a3530ull,0x09203436662e6e72ull,0x25202c3834646625ull,0x6625202c36346466ull,
0x646625202c333464ull,0x0a202f2f093b3734ull,0x3436662e766f6d09ull,0x2c39346466250920ull,
0x3437316633643020ull,0x3062613961626335ull,0x202f2f093b363539ull,0x6531383737382e38ull,
0x64616d090a35302dull,0x203436662e6e722eull,0x202c303564662509ull,0x25202c3834646625ull,
0x6625202c33346466ull,0x202f2f093b393464ull,0x36662e766f6d090aull,0x3135646625092034ull,
0x633366336430202cull,0x6231643237633137ull,0x2f2f093b34353135ull,0x33343030302e3020ull,
0x616d090a38323034ull,0x3436662e6e722e64ull,0x2c32356466250920ull,0x202c303564662520ull,
0x25202c3334646625ull,0x2f2f093b31356466ull,0x09636f6c2e090a20ull,0x3009303835093832ull,
0x36662e766f6d090aull,0x3335646625092034ull,0x323666336430202cull,0x6233323934323934ull,
0x2f2f093b64323765ull,0x33323230302e3020ull,0x64616d090a343132ull,0x203436662e6e722eull,
0x202c323564662509ull,0x25202c3235646625ull,0x6625202c33346466ull,0x202f2f093b333564ull,
0x3209636f6c2e090aull,0x0a30093138350938ull,0x3436662e766f6d09ull,0x2c34356466250920ull,
0x3939386633643020ull,0x6139393939393939ull,0x202f2f093b346333ull,0x090a353231302e30ull,
0x662e6e722e64616dull,0x3564662509203436ull,0x3235646625202c32ull,0x2c3334646625202cull,
0x093b343564662520ull,0x6f6c2e090a202f2full,0x3238350938320963ull,0x2e766f6d090a3009ull,
0x6466250920343666ull,0x66336430202c3535ull,0x3535353535353562ull,0x093b343535353535ull,
0x3338302e30202f2full,0x616d090a33333333ull,0x3436662e6e722e64ull,0x2c32356466250920ull,
0x202c323564662520ull,0x25202c3334646625ull,0x2f2f093b35356466ull,0x09636f6c2e090a20ull,
0x3009343835093832ull,0x36662e627573090aull,0x3635646625092034ull,0x2c3733646625202cull,
0x203b323464662520ull,0x656e090a202f2f09ull,0x2509203436662e67ull,0x6625202c37356466ull,
0x202020203b323464ull,0x202f2f0920202020ull,0x36622e766f6d090aull,0x313472257b092034ull,
0x202c7d323472252cull,0x20203b3635646625ull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x347225202c333472ull,0x3538343031202c32ull,0x202f2f09203b3637ull,0x36622e766f6d090aull,
0x343472257b092034ull,0x202c7d353472252cull,0x20203b3635646625ull,0x6f6d090a202f2f09ull,
0x2509203436622e76ull,0x257b202c38356466ull,0x333472252c343472ull,0x202f2f0920203b7dull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c393564ull,0x33646625202c3735ull,
0x3835646625202c37ull,0x2e090a202f2f093bull,0x3509383209636f6cull,0x756d090a30093838ull,
0x2509203436662e6cull,0x6625202c30366466ull,0x646625202c333464ull,0x202f2f09203b3235ull,
0x36662e6c756d090aull,0x3235646625092034ull,0x2c3234646625202cull,0x203b303664662520ull,
0x6c2e090a202f2f09ull,0x393509383209636full,0x747663090a300938ull,0x2e3436662e6e722eull,
0x6466250920323373ull,0x30337225202c3136ull,0x0a202f2f0920203bull,0x3436662e766f6d09ull,
0x2c32366466250920ull,0x3236656633643020ull,0x3361666566323465ull,0x202f2f093b666539ull,
0x3734313339362e30ull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c333664ull,
0x36646625202c3136ull,0x3234646625202c32ull,0x6d090a202f2f093bull,0x09203436662e766full,
0x30202c3436646625ull,0x3963626137633364ull,0x3330383933623365ull,0x2e32202f2f093b66ull,
0x312d653530393133ull,0x722e64616d090a37ull,0x2509203436662e6eull,0x6625202c35366466ull,
0x646625202c393564ull,0x35646625202c3034ull,0x090a202f2f093b32ull,0x203233732e67656eull,
0x25202c3634722509ull,0x202020203b303372ull,0x2f09202020202020ull,0x2e747663090a202full,
0x732e3436662e6e72ull,0x3664662509203233ull,0x3b36347225202c36ull,0x090a202f2f092020ull,
0x203436662e766f6dull,0x202c373664662509ull,0x6532366566336430ull,0x3933616665663234ull,
0x30202f2f093b6665ull,0x0a3734313339362eull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x36646625202c3836ull,0x3736646625202c36ull,0x3b3336646625202cull,0x7573090a202f2f09ull,
0x2509203436662e62ull,0x6625202c39366466ull,0x646625202c383664ull,0x202f2f09203b3234ull,
0x36662e627573090aull,0x3037646625092034ull,0x2c3536646625202cull,0x203b393664662520ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x2c31376466250920ull,0x202c313664662520ull,
0x25202c3436646625ull,0x2f2f093b30376466ull,0x662e646461090a20ull,0x3764662509203436ull,
0x3336646625202c32ull,0x3b3137646625202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x30345f335f744c24ull,0x20202020203b3839ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x200a3a3238363933ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x2e090a3433383635ull,0x3609383209636f6cull,0x6261090a30093130ull,0x2509203436662e73ull,
0x6625202c33376466ull,0x202020203b303364ull,0x202f2f0920202020ull,0x36662e766f6d090aull,
0x3437646625092034ull,0x306666376430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,
0x6573090a666e6920ull,0x36662e656c2e7074ull,0x202c397025092034ull,0x25202c3337646625ull,
0x2f2f093b34376466ull,0x2039702540090a20ull,0x744c240920617262ull,0x30353639355f335full,
0x202020202020203bull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x355f335f744c2420ull,0x6461090a34333836ull,0x2509203436662e64ull,0x6625202c32376466ull,
0x646625202c303364ull,0x202f2f09203b3033ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x20203b383930345full,0x2020202020202020ull,0x744c240a202f2f09ull,0x30353639355f335full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34333836355f335full,
0x36662e766f6d090aull,0x3537646625092034ull,0x303030306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e71652eull,0x25202c3031702509ull,
0x6625202c30336466ull,0x202f2f093b353764ull,0x303170252140090aull,0x4c24092061726220ull,
0x363130365f335f74ull,0x2020202020203b32ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x36355f335f744c24ull,0x766f6d090a343338ull,0x662509203436662eull,
0x666430202c323764ull,0x3030303030306666ull,0x3b30303030303030ull,0x666e692d202f2f09ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x20203b383930345full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x32363130365f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333836355f335full,0x36662e766f6d090aull,0x3637646625092034ull,
0x306666376430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x6573090a666e6920ull,
0x36662e71652e7074ull,0x2c31317025092034ull,0x202c303364662520ull,0x2f093b3637646625ull,
0x70252140090a202full,0x0920617262203131ull,0x30365f335f744c24ull,0x202020203b343736ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6d090a3433383635ull,0x09203436662e766full,0x25202c3237646625ull,0x2020203b30336466ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x203b383930345f33ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x373630365f335f74ull,0x6c3c2f2f200a3a34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,0x662e766f6d090a34ull,
0x3764662509203436ull,0x6666666430202c32ull,0x3030303030303038ull,0x2f093b3030303030ull,
0x4c240a6e616e202full,0x383930345f335f74ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333836355f335full,0x3209636f6c2e090aull,0x0a30093534350938ull,
0x3436662e67656e09ull,0x2c37376466250920ull,0x203b323764662520ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x257b09203436622eull,0x383472252c373472ull,0x3737646625202c7dull,
0x0a202f2f0920203bull,0x3233732e766f6d09ull,0x202c383172250920ull,0x2020203b38347225ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3634350938320963ull,0x2e766f6d090a3009ull,
0x72257b0920343662ull,0x7d393472252c3931ull,0x3b3737646625202cull,0x090a202f2f092020ull,
0x09383209636f6c2eull,0x6d090a3009383435ull,0x09203436662e766full,0x30202c3837646625ull,
0x3030303030303064ull,0x3030303030303030ull,0x0a30202f2f093b30ull,0x2e74672e74657309ull,
0x203436662e323375ull,0x25202c3035722509ull,0x6625202c37376466ull,0x202f2f093b383764ull,
0x33732e67656e090aull,0x2c31357225092032ull,0x20203b3035722520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x6430202c39376466ull,0x3030303030666637ull,
0x3030303030303030ull,0x666e69202f2f093bull,0x746c2e746573090aull,0x3436662e3233752eull,
0x202c323572250920ull,0x25202c3737646625ull,0x2f2f093b39376466ull,0x732e67656e090a20ull,
0x3335722509203233ull,0x203b32357225202cull,0x2020202020202020ull,0x61090a202f2f0920ull,
0x09203233622e646eull,0x7225202c34357225ull,0x33357225202c3135ull,0x2f2f09202020203bull,
0x752e766f6d090a20ull,0x3535722509203233ull,0x202020203b30202cull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e71652e707465ull,0x3231702509203233ull,0x202c34357225202cull,
0x2f2f093b35357225ull,0x3231702540090a20ull,0x4c24092061726220ull,0x313231345f335f74ull,
0x2020202020203b38ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x355f335f744c2420ull,0x6f6d090a34333836ull,0x2509203233752e76ull,0x343031202c363572ull,
0x2020203b35373538ull,0x202f2f0920202020ull,0x672e70746573090aull,0x2509203233752e74ull,
0x347225202c333170ull,0x3b36357225202c38ull,0x2540090a202f2f09ull,0x2061726220333170ull,
0x365f335f744c2409ull,0x2020203b32343431ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,0x383209636f6c2e09ull,
0x090a300934353509ull,0x203436662e766f6dull,0x202c303864662509ull,0x3030303533346430ull,
0x3030303030303030ull,0x31202f2f093b3030ull,0x2b6534343130382eull,0x2e6c756d090a3631ull,
0x6466250920343666ull,0x37646625202c3138ull,0x3038646625202c37ull,0x090a202f2f09203bull,
0x203436622e766f6dull,0x252c373572257b09ull,0x6625202c7d383172ull,0x2f0920203b313864ull,
0x636f6c2e090a202full,0x0935353509383209ull,0x622e766f6d090a30ull,0x3172257b09203436ull,
0x2c7d383572252c39ull,0x203b313864662520ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x312d202c30337225ull,0x202020203b373730ull,0x2f2f092020202020ull,0x752e617262090a20ull,
0x5f744c240920696eull,0x3b36383131365f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x343431365f335f74ull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333836355f335f74ull,0x732e766f6d090a34ull,0x3033722509203233ull,0x3b333230312d202cull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x383131365f335f74ull,0x6c3c2f2f200a3a36ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,0x09636f6c2e090a34ull,
0x3009303635093832ull,0x33732e726873090aull,0x2c39357225092032ull,0x32202c3831722520ull,
0x2020202020203b30ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,0x357225202c303672ull,
0x3b37343032202c39ull,0x202f2f0920202020ull,0x33732e646461090aull,0x2c30337225092032ull,
0x25202c3033722520ull,0x202020203b303672ull,0x6c2e090a202f2f09ull,0x363509383209636full,
0x646e61090a300932ull,0x722509203233622eull,0x38317225202c3333ull,0x34363431322d202cull,
0x2f093b3337303533ull,0x622e726f090a202full,0x3433722509203233ull,0x202c33337225202cull,
0x3233393632373031ull,0x0a202f2f093b3834ull,0x3436622e766f6d09ull,0x2c35336466250920ull,
0x252c393172257b20ull,0x0920203b7d343372ull,0x766f6d090a202f2full,0x722509203233752eull,
0x33373031202c3136ull,0x203b323835373231ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,
0x702509203233752eull,0x34337225202c3431ull,0x093b31367225202cull,0x702540090a202f2full,
0x0920617262203431ull,0x31365f335f744c24ull,0x202020203b383936ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c30363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333836355full,
0x09383209636f6c2eull,0x6d090a3009343635ull,0x09203436622e766full,0x72252c323672257bull,
0x646625202c7d3336ull,0x2f2f0920203b3533ull,0x732e627573090a20ull,0x3436722509203233ull,
0x202c33367225202cull,0x3b36373538343031ull,0x6d090a202f2f0920ull,0x09203436622e766full,
0x72252c353672257bull,0x646625202c7d3636ull,0x2f2f0920203b3533ull,0x622e766f6d090a20ull,
0x3364662509203436ull,0x353672257b202c35ull,0x203b7d343672252cull,0x2e090a202f2f0920ull,
0x3509383209636f6cull,0x6461090a30093536ull,0x2509203233732e64ull,0x337225202c303372ull,
0x2020203b31202c30ull,0x202f2f0920202020ull,0x365f335f744c240aull,0x2f200a3a38393631ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3036ull,0x64656c6562616c20ull,0x355f335f744c2420ull,0x6c2e090a34333836ull,
0x373509383209636full,0x766f6d090a300939ull,0x662509203436662eull,0x626430202c323864ull,
0x3030303030306666ull,0x3b30303030303030ull,0x090a312d202f2f09ull,0x203436662e646461ull,
0x202c373364662509ull,0x25202c3533646625ull,0x2f09203b32386466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x66336430202c3338ull,0x3030303030303066ull,0x093b303030303030ull,
0x6461090a31202f2full,0x2509203436662e64ull,0x6625202c34386466ull,0x646625202c353364ull,
0x202f2f09203b3338ull,0x6e722e706372090aull,0x662509203436662eull,0x646625202c303464ull,
0x20202020203b3438ull,0x756d090a202f2f09ull,0x2509203436662e6cull,0x6625202c31346466ull,
0x646625202c373364ull,0x202f2f09203b3034ull,0x36662e646461090aull,0x3234646625092034ull,
0x2c3134646625202cull,0x203b313464662520ull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x6625202c33346466ull,0x646625202c323464ull,0x202f2f09203b3234ull,0x36662e766f6d090aull,
0x3538646625092034ull,0x316265336430202cull,0x3865613362303833ull,0x2f2f093b65316630ull,
0x33333632302e3120ull,0x6f6d090a36302d65ull,0x2509203436662e76ull,0x6430202c36386466ull,
0x3532656530646533ull,0x3430623861376238ull,0x302e34202f2f093bull,0x36302d6539343633ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c373864ull,0x34646625202c3538ull,
0x3638646625202c33ull,0x6d090a202f2f093bull,0x09203436662e766full,0x30202c3838646625ull,
0x3632623366653364ull,0x3637363230663936ull,0x2e31202f2f093b66ull,0x302d653434383738ull,
0x722e64616d090a35ull,0x2509203436662e6eull,0x6625202c39386466ull,0x646625202c373864ull,
0x38646625202c3334ull,0x090a202f2f093b38ull,0x203436662e766f6dull,0x202c303964662509ull,
0x3534373166336430ull,0x3930626139616263ull,0x38202f2f093b3635ull,0x2d6531383737382eull,
0x2e64616d090a3530ull,0x09203436662e6e72ull,0x25202c3139646625ull,0x6625202c39386466ull,
0x646625202c333464ull,0x0a202f2f093b3039ull,0x3436662e766f6d09ull,0x2c32396466250920ull,
0x3763336633643020ull,0x3562316432376331ull,0x202f2f093b343531ull,0x3433343030302e30ull,
0x64616d090a383230ull,0x203436662e6e722eull,0x202c323564662509ull,0x25202c3139646625ull,
0x6625202c33346466ull,0x202f2f093b323964ull,0x3209636f6c2e090aull,0x0a30093038350938ull,
0x3436662e766f6d09ull,0x2c33396466250920ull,0x3432366633643020ull,0x6562333239343239ull,
0x202f2f093b643237ull,0x3233323230302e30ull,0x2e64616d090a3431ull,0x09203436662e6e72ull,
0x25202c3235646625ull,0x6625202c32356466ull,0x646625202c333464ull,0x0a202f2f093b3339ull,
0x383209636f6c2e09ull,0x090a300931383509ull,0x203436662e766f6dull,0x202c343964662509ull,
0x3939393866336430ull,0x3361393939393939ull,0x30202f2f093b3463ull,0x6d090a353231302eull,
0x36662e6e722e6461ull,0x3235646625092034ull,0x2c3235646625202cull,0x202c333464662520ull,
0x2f093b3439646625ull,0x636f6c2e090a202full,0x0932383509383209ull,0x662e766f6d090a30ull,
0x3964662509203436ull,0x6266336430202c35ull,0x3535353535353535ull,0x2f093b3435353535ull,
0x333338302e30202full,0x64616d090a333333ull,0x203436662e6e722eull,0x202c323564662509ull,
0x25202c3235646625ull,0x6625202c33346466ull,0x202f2f093b353964ull,0x3209636f6c2e090aull,
0x0a30093438350938ull,0x3436662e62757309ull,0x2c36356466250920ull,0x202c373364662520ull,
0x09203b3234646625ull,0x67656e090a202f2full,0x662509203436662eull,0x646625202c363964ull,
0x20202020203b3234ull,0x0a202f2f09202020ull,0x3436622e766f6d09ull,0x2c373672257b0920ull,
0x25202c7d38367225ull,0x0920203b36356466ull,0x646461090a202f2full,0x722509203233732eull,
0x38367225202c3936ull,0x373538343031202cull,0x0a202f2f09203b36ull,0x3436622e766f6d09ull,
0x2c303772257b0920ull,0x25202c7d31377225ull,0x0920203b36356466ull,0x766f6d090a202f2full,
0x662509203436622eull,0x72257b202c373964ull,0x7d393672252c3037ull,0x0a202f2f0920203bull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x39646625202c3935ull,0x3733646625202c36ull,
0x3b3739646625202cull,0x6c2e090a202f2f09ull,0x383509383209636full,0x6c756d090a300938ull,
0x662509203436662eull,0x646625202c383964ull,0x35646625202c3334ull,0x0a202f2f09203b32ull,
0x3436662e6c756d09ull,0x2c32356466250920ull,0x202c323464662520ull,0x09203b3839646625ull,
0x6f6c2e090a202f2full,0x3839350938320963ull,0x2e747663090a3009ull,0x732e3436662e6e72ull,
0x3664662509203233ull,0x3b30337225202c31ull,0x090a202f2f092020ull,0x203436662e766f6dull,
0x202c393964662509ull,0x6532366566336430ull,0x3933616665663234ull,0x30202f2f093b6665ull,
0x0a3734313339362eull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x36646625202c3336ull,
0x3939646625202c31ull,0x3b3234646625202cull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3030316466ull,0x3963626137633364ull,0x3330383933623365ull,0x2e32202f2f093b66ull,
0x312d653530393133ull,0x722e64616d090a37ull,0x2509203436662e6eull,0x25202c3130316466ull,
0x6625202c39356466ull,0x646625202c303464ull,0x0a202f2f093b3235ull,0x3233732e67656e09ull,
0x202c323772250920ull,0x2020203b30337225ull,0x0920202020202020ull,0x747663090a202f2full,
0x2e3436662e6e722eull,0x6466250920323373ull,0x377225202c323031ull,0x0a202f2f09203b32ull,
0x3436662e766f6d09ull,0x3330316466250920ull,0x366566336430202cull,0x6166656632346532ull,
0x2f2f093b66653933ull,0x34313339362e3020ull,0x722e64616d090a37ull,0x2509203436662e6eull,
0x25202c3430316466ull,0x25202c3230316466ull,0x25202c3330316466ull,0x2f2f093b33366466ull,
0x662e627573090a20ull,0x3164662509203436ull,0x31646625202c3530ull,0x34646625202c3430ull,
0x090a202f2f093b32ull,0x203436662e627573ull,0x2c36303164662509ull,0x2c31303164662520ull,
0x3b35303164662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x2c31376466250920ull,
0x202c313664662520ull,0x202c303031646625ull,0x093b363031646625ull,0x646461090a202f2full,
0x662509203436662eull,0x6625202c37303164ull,0x646625202c333664ull,0x0a202f2f093b3137ull,
0x696e752e61726209ull,0x5f335f744c240920ull,0x2020203b30313634ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x3a38313231345f33ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a34333836355f33ull,0x383209636f6c2e09ull,0x090a300931303609ull,
0x203436662e736261ull,0x2c38303164662509ull,0x203b323764662520ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x6466250920343666ull,0x376430202c393031ull,0x3030303030306666ull,
0x3b30303030303030ull,0x0a666e69202f2f09ull,0x656c2e7074657309ull,0x702509203436662eull,
0x31646625202c3531ull,0x31646625202c3830ull,0x0a202f2f093b3930ull,0x6220353170254009ull,
0x5f744c2409206172ull,0x3b30313232365f33ull,0x0920202020202020ull,0x3c2f2f200a202f2full,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3836355f335f744cull,0x2e646461090a3433ull,
0x6466250920343666ull,0x646625202c303131ull,0x37646625202c3237ull,0x090a202f2f093b32ull,
0x203436662e67656eull,0x2c37303164662509ull,0x3b30313164662520ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x3b303136345f335full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3232365f335f744cull,0x3c2f2f200a3a3031ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x30363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3836355f335f744cull,0x2e766f6d090a3433ull,0x6466250920343666ull,
0x306430202c313131ull,0x3030303030303030ull,0x3b30303030303030ull,0x73090a30202f2f09ull,
0x662e71652e707465ull,0x3631702509203436ull,0x2c3737646625202cull,0x3b31313164662520ull,
0x2140090a202f2f09ull,0x6172622036317025ull,0x5f335f744c240920ull,0x20203b3232373236ull,
0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34333836355f33ull,0x3436662e766f6d09ull,0x3730316466250920ull,0x306666666430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x62090a666e692d20ull,0x0920696e752e6172ull,
0x36345f335f744c24ull,0x20202020203b3031ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x200a3a3232373236ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6d090a3433383635ull,0x09203436662e766full,0x202c323131646625ull,0x3030306666376430ull,
0x3030303030303030ull,0x69202f2f093b3030ull,0x70746573090a666eull,0x203436662e71652eull,
0x25202c3731702509ull,0x6625202c37376466ull,0x2f2f093b32313164ull,0x3170252140090a20ull,
0x2409206172622037ull,0x3233365f335f744cull,0x20202020203b3433ull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3036ull,0x64656c6562616c20ull,0x355f335f744c2420ull,0x6f6d090a34333836ull,
0x2509203436662e76ull,0x25202c3730316466ull,0x2020203b37376466ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x20203b303136345full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x34333233365f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333836355f335full,0x36662e766f6d090aull,0x3031646625092034ull,
0x6666666430202c37ull,0x3030303030303038ull,0x2f093b3030303030ull,0x4c240a6e616e202full,
0x303136345f335f74ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34333836355f335full,0x3109636f6c2e090aull,0x0a30093832310938ull,0x3436662e766f6d09ull,
0x2c37326466250920ull,0x3b37303164662520ull,0x0920202020202020ull,0x617262090a202f2full,
0x4c240920696e752eull,0x313138355f335f74ull,0x2020202020203b34ull,0x0a202f2f09202020ull,
0x38355f335f744c24ull,0x2f2f200a3a303733ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,
0x36355f335f744c24ull,0x6f6c2e090a343338ull,0x3534350938320963ull,0x2e766f6d090a3009ull,
0x72257b0920343662ull,0x7d343772252c3337ull,0x203b31646625202cull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x25202c3831722509ull,0x202020203b343772ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0936343509383209ull,0x622e766f6d090a30ull,0x3172257b09203436ull,
0x2c7d353772252c39ull,0x20203b3164662520ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,
0x6f6d090a30093834ull,0x2509203436662e76ull,0x30202c3331316466ull,0x3030303030303064ull,
0x3030303030303030ull,0x0a30202f2f093b30ull,0x2e74672e74657309ull,0x203436662e323375ull,
0x25202c3637722509ull,0x646625202c316466ull,0x202f2f093b333131ull,0x33732e67656e090aull,
0x2c37377225092032ull,0x20203b3637722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3431316466ull,0x3030303066663764ull,0x3030303030303030ull,
0x6e69202f2f093b30ull,0x6c2e746573090a66ull,0x36662e3233752e74ull,0x2c38377225092034ull,
0x25202c3164662520ull,0x2f093b3431316466ull,0x2e67656e090a202full,0x3772250920323373ull,
0x3b38377225202c39ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233622e646e61ull,
0x25202c3038722509ull,0x377225202c373772ull,0x2f09202020203b39ull,0x2e766f6d090a202full,
0x3872250920323375ull,0x2020203b30202c31ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x2e71652e70746573ull,0x3170250920323373ull,0x2c30387225202c38ull,0x2f093b3138722520ull,
0x31702540090a202full,0x2409206172622038ull,0x3732345f335f744cull,0x20202020203b3435ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6d090a3433383635ull,0x09203233752e766full,0x3031202c32387225ull,0x20203b3537353834ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233752e7467ull,0x7225202c39317025ull,
0x32387225202c3437ull,0x40090a202f2f093bull,0x6172622039317025ull,0x5f335f744c240920ull,
0x20203b3230303436ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333836355f335full,0x3209636f6c2e090aull,0x0a30093435350938ull,
0x3436662e766f6d09ull,0x3531316466250920ull,0x303533346430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x34343130382e3120ull,0x756d090a36312b65ull,0x2509203436662e6cull,
0x25202c3631316466ull,0x646625202c316466ull,0x202f2f093b353131ull,0x36622e766f6d090aull,
0x333872257b092034ull,0x202c7d383172252cull,0x203b363131646625ull,0x6c2e090a202f2f09ull,
0x353509383209636full,0x766f6d090a300935ull,0x257b09203436622eull,0x343872252c393172ull,
0x3131646625202c7dull,0x0a202f2f09203b36ull,0x3233732e766f6d09ull,0x202c303372250920ull,
0x20203b373730312dull,0x0920202020202020ull,0x617262090a202f2full,0x4c240920696e752eull,
0x343733365f335f74ull,0x2020202020203b36ull,0x0a202f2f09202020ull,0x34365f335f744c24ull,
0x2f2f200a3a323030ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,0x36355f335f744c24ull,
0x766f6d090a343338ull,0x722509203233732eull,0x3230312d202c3033ull,0x2020202020203b33ull,
0x0a202f2f09202020ull,0x33365f335f744c24ull,0x2f2f200a3a363437ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x36355f335f744c24ull,0x6f6c2e090a343338ull,0x3036350938320963ull,
0x2e726873090a3009ull,0x3872250920323373ull,0x2c38317225202c35ull,0x202020203b303220ull,
0x090a202f2f092020ull,0x203233622e646e61ull,0x25202c3638722509ull,0x343032202c353872ull,
0x2f09202020203b37ull,0x2e646461090a202full,0x3372250920323373ull,0x2c30337225202c30ull,
0x20203b3638722520ull,0x090a202f2f092020ull,0x09383209636f6c2eull,0x61090a3009323635ull,
0x09203233622e646eull,0x7225202c33337225ull,0x3431322d202c3831ull,0x3b33373035333436ull,
0x726f090a202f2f09ull,0x722509203233622eull,0x33337225202c3433ull,0x393632373031202cull,
0x2f2f093b38343233ull,0x622e766f6d090a20ull,0x3364662509203436ull,0x393172257b202c35ull,
0x203b7d343372252cull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3031202c37387225ull,
0x3238353732313337ull,0x2f2f09202020203bull,0x2e70746573090a20ull,0x09203233752e656cull,
0x7225202c30327025ull,0x37387225202c3433ull,0x40090a202f2f093bull,0x6172622030327025ull,
0x5f335f744c240920ull,0x20203b3835323436ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333836355f335full,0x3209636f6c2e090aull,
0x0a30093436350938ull,0x3436622e766f6d09ull,0x2c383872257b0920ull,0x25202c7d39387225ull,
0x0920203b35336466ull,0x627573090a202f2full,0x722509203233732eull,0x39387225202c3039ull,
0x373538343031202cull,0x0a202f2f09203b36ull,0x3436622e766f6d09ull,0x2c313972257b0920ull,
0x25202c7d32397225ull,0x0920203b35336466ull,0x766f6d090a202f2full,0x662509203436622eull,
0x72257b202c353364ull,0x7d303972252c3139ull,0x0a202f2f0920203bull,0x383209636f6c2e09ull,
0x090a300935363509ull,0x203233732e646461ull,0x25202c3033722509ull,0x203b31202c303372ull,
0x2f09202020202020ull,0x335f744c240a202full,0x0a3a38353234365full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333836355full,0x09383209636f6c2eull,
0x6d090a3009393735ull,0x09203436662e766full,0x202c373131646625ull,0x3030306666626430ull,
0x3030303030303030ull,0x2d202f2f093b3030ull,0x662e646461090a31ull,0x3364662509203436ull,
0x3533646625202c37ull,0x373131646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,
0x202c383131646625ull,0x3030306666336430ull,0x3030303030303030ull,0x31202f2f093b3030ull,
0x36662e646461090aull,0x3131646625092034ull,0x3533646625202c39ull,0x383131646625202cull,
0x72090a202f2f093bull,0x36662e6e722e7063ull,0x3034646625092034ull,0x393131646625202cull,
0x2f2f09202020203bull,0x662e6c756d090a20ull,0x3464662509203436ull,0x3733646625202c31ull,
0x3b3034646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3234646625ull,
0x6625202c31346466ull,0x2f2f09203b313464ull,0x662e6c756d090a20ull,0x3464662509203436ull,
0x3234646625202c33ull,0x3b3234646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x202c303231646625ull,0x3833316265336430ull,0x6630386561336230ull,0x31202f2f093b6531ull,
0x2d6533333632302eull,0x2e766f6d090a3630ull,0x6466250920343666ull,0x336430202c313231ull,
0x3835326565306465ull,0x3b34306238613762ull,0x33302e34202f2f09ull,0x0a36302d65393436ull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x646625202c323231ull,0x646625202c303231ull,
0x31646625202c3334ull,0x0a202f2f093b3132ull,0x3436662e766f6d09ull,0x3332316466250920ull,
0x336665336430202cull,0x3230663936363262ull,0x2f2f093b66363736ull,0x34343837382e3120ull,
0x616d090a35302d65ull,0x3436662e6e722e64ull,0x3432316466250920ull,0x323231646625202cull,
0x2c3334646625202cull,0x3b33323164662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3532316466ull,0x6335343731663364ull,0x3539306261396162ull,0x2e38202f2f093b36ull,
0x302d653138373738ull,0x722e64616d090a35ull,0x2509203436662e6eull,0x25202c3632316466ull,
0x25202c3432316466ull,0x6625202c33346466ull,0x2f2f093b35323164ull,0x662e766f6d090a20ull,
0x3164662509203436ull,0x66336430202c3732ull,0x6432376331376333ull,0x093b343531356231ull,
0x3030302e30202f2full,0x090a383230343334ull,0x662e6e722e64616dull,0x3564662509203436ull,
0x3231646625202c32ull,0x3334646625202c36ull,0x373231646625202cull,0x2e090a202f2f093bull,
0x3509383209636f6cull,0x6f6d090a30093038ull,0x2509203436662e76ull,0x30202c3832316466ull,
0x3239343236663364ull,0x3237656233323934ull,0x2e30202f2f093b64ull,0x3431323332323030ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c323564ull,0x34646625202c3235ull,
0x3231646625202c33ull,0x090a202f2f093b38ull,0x09383209636f6c2eull,0x6d090a3009313835ull,
0x09203436662e766full,0x202c393231646625ull,0x3939393866336430ull,0x3361393939393939ull,
0x30202f2f093b3463ull,0x6d090a353231302eull,0x36662e6e722e6461ull,0x3235646625092034ull,
0x2c3235646625202cull,0x202c333464662520ull,0x093b393231646625ull,0x6f6c2e090a202f2full,
0x3238350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x336430202c303331ull,
0x3535353535356266ull,0x3b34353535353535ull,0x38302e30202f2f09ull,0x6d090a3333333333ull,
0x36662e6e722e6461ull,0x3235646625092034ull,0x2c3235646625202cull,0x202c333464662520ull,
0x093b303331646625ull,0x6f6c2e090a202f2full,0x3438350938320963ull,0x2e627573090a3009ull,
0x6466250920343666ull,0x33646625202c3635ull,0x3234646625202c37ull,0x090a202f2f09203bull,
0x203436662e67656eull,0x2c31333164662509ull,0x203b323464662520ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x72257b0920343662ull,0x7d343972252c3339ull,0x3b3635646625202cull,
0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3539722509ull,0x343031202c343972ull,
0x2f09203b36373538ull,0x2e766f6d090a202full,0x72257b0920343662ull,0x7d373972252c3639ull,
0x3b3635646625202cull,0x090a202f2f092020ull,0x203436622e766f6dull,0x2c32333164662509ull,
0x252c363972257b20ull,0x2f09203b7d353972ull,0x2e64616d090a202full,0x09203436662e6e72ull,
0x25202c3935646625ull,0x25202c3133316466ull,0x6625202c37336466ull,0x2f2f093b32333164ull,
0x09636f6c2e090a20ull,0x3009383835093832ull,0x36662e6c756d090aull,0x3331646625092034ull,
0x3334646625202c33ull,0x3b3235646625202cull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x6625202c32356466ull,0x646625202c323464ull,0x202f2f093b333331ull,0x3209636f6c2e090aull,
0x0a30093839350938ull,0x2e6e722e74766309ull,0x203233732e343666ull,0x202c313664662509ull,
0x0920203b30337225ull,0x766f6d090a202f2full,0x662509203436662eull,0x6430202c34333164ull,
0x3234653236656633ull,0x6665393361666566ull,0x362e30202f2f093bull,0x6d090a3734313339ull,
0x36662e6e722e6461ull,0x3336646625092034ull,0x2c3136646625202cull,0x2c34333164662520ull,
0x093b323464662520ull,0x766f6d090a202f2full,0x662509203436662eull,0x6430202c35333164ull,
0x6539636261376333ull,0x6633303839336233ull,0x332e32202f2f093bull,0x37312d6535303931ull,
0x6e722e64616d090aull,0x662509203436662eull,0x6625202c36333164ull,0x646625202c393564ull,
0x35646625202c3034ull,0x090a202f2f093b32ull,0x203233732e67656eull,0x25202c3839722509ull,
0x202020203b303372ull,0x2f09202020202020ull,0x2e747663090a202full,0x732e3436662e6e72ull,
0x3164662509203233ull,0x38397225202c3733ull,0x090a202f2f09203bull,0x203436662e766f6dull,
0x2c38333164662509ull,0x3236656633643020ull,0x3361666566323465ull,0x202f2f093b666539ull,
0x3734313339362e30ull,0x6e722e64616d090aull,0x662509203436662eull,0x6625202c39333164ull,
0x6625202c37333164ull,0x6625202c38333164ull,0x202f2f093b333664ull,0x36662e627573090aull,
0x3431646625092034ull,0x3331646625202c30ull,0x3234646625202c39ull,0x73090a202f2f093bull,
0x09203436662e6275ull,0x202c313431646625ull,0x202c363331646625ull,0x093b303431646625ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x202c313764662509ull,0x25202c3136646625ull,
0x25202c3533316466ull,0x2f093b3134316466ull,0x2e646461090a202full,0x6466250920343666ull,
0x646625202c323431ull,0x37646625202c3336ull,0x090a202f2f093b31ull,0x20696e752e617262ull,
0x335f335f744c2409ull,0x202020203b343730ull,0x2f09202020202020ull,0x335f744c240a202full,
0x0a3a34353732345full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c30363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x090a34333836355full,0x09383209636f6c2eull,0x61090a3009313036ull,0x09203436662e7362ull,
0x202c333431646625ull,0x2020203b31646625ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,
0x3164662509203436ull,0x66376430202c3434ull,0x3030303030303066ull,0x093b303030303030ull,
0x090a666e69202f2full,0x2e656c2e70746573ull,0x3270250920343666ull,0x3431646625202c31ull,
0x3431646625202c33ull,0x090a202f2f093b34ull,0x7262203132702540ull,0x335f744c24092061ull,
0x203b30373734365full,0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333836355f335f74ull,0x662e646461090a34ull,0x3164662509203436ull,
0x31646625202c3234ull,0x203b31646625202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x30335f335f744c24ull,0x20202020203b3437ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x200a3a3037373436ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6d090a3433383635ull,0x09203436662e766full,0x202c353431646625ull,0x3030303030306430ull,
0x3030303030303030ull,0x30202f2f093b3030ull,0x652e70746573090aull,0x2509203436662e71ull,
0x646625202c323270ull,0x3431646625202c31ull,0x090a202f2f093b35ull,0x6220323270252140ull,
0x5f744c2409206172ull,0x3b32383235365f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,0x662e766f6d090a34ull,
0x3164662509203436ull,0x66666430202c3234ull,0x3030303030303066ull,0x093b303030303030ull,
0x0a666e692d202f2full,0x696e752e61726209ull,0x5f335f744c240920ull,0x2020203b34373033ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x3a32383235365f33ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,0x3436662e766f6d09ull,
0x3634316466250920ull,0x306666376430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,
0x6573090a666e6920ull,0x36662e71652e7074ull,0x2c33327025092034ull,0x25202c3164662520ull,
0x2f093b3634316466ull,0x70252140090a202full,0x0920617262203332ull,0x35365f335f744c24ull,
0x202020203b343937ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3433383635ull,0x09203436662e766full,0x202c323431646625ull,
0x2020203b31646625ull,0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x203b343730335f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x393735365f335f74ull,
0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c30363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,
0x662e766f6d090a34ull,0x3164662509203436ull,0x66666430202c3234ull,0x3030303030303866ull,
0x093b303030303030ull,0x240a6e616e202f2full,0x3730335f335f744cull,0x6c3c2f2f200a3a34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,0x09636f6c2e090a34ull,
0x3009353435093832ull,0x36662e67656e090aull,0x3431646625092034ull,0x3431646625202c37ull,
0x2020202020203b32ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x3172252c39397225ull,
0x646625202c7d3030ull,0x202f2f093b373431ull,0x33732e766f6d090aull,0x2c38317225092032ull,
0x203b303031722520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x343509383209636full,
0x766f6d090a300936ull,0x257b09203436622eull,0x303172252c393172ull,0x31646625202c7d31ull,
0x0a202f2f093b3734ull,0x383209636f6c2e09ull,0x090a300938343509ull,0x203436662e766f6dull,
0x2c38343164662509ull,0x3030303030643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x672e746573090a30ull,0x36662e3233752e74ull,0x3230317225092034ull,0x373431646625202cull,
0x383431646625202cull,0x6e090a202f2f093bull,0x09203233732e6765ull,0x25202c3330317225ull,
0x2020203b32303172ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3164662509203436ull,
0x66376430202c3934ull,0x3030303030303066ull,0x093b303030303030ull,0x090a666e69202f2full,
0x752e746c2e746573ull,0x09203436662e3233ull,0x25202c3430317225ull,0x25202c3734316466ull,
0x2f093b3934316466ull,0x2e67656e090a202full,0x3172250920323373ull,0x30317225202c3530ull,
0x2020202020203b34ull,0x090a202f2f092020ull,0x203233622e646e61ull,0x202c363031722509ull,
0x25202c3330317225ull,0x2f09203b35303172ull,0x2e766f6d090a202full,0x3172250920323375ull,
0x20203b30202c3730ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e71652e70746573ull,
0x3270250920323373ull,0x3630317225202c34ull,0x3b3730317225202cull,0x2540090a202f2f09ull,
0x2061726220343270ull,0x345f335f744c2409ull,0x2020203b30393234ull,0x202f2f0920202020ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,
0x3233752e766f6d09ull,0x2c38303172250920ull,0x3537353834303120ull,0x092020202020203bull,
0x746573090a202f2full,0x3233752e74672e70ull,0x202c353270250920ull,0x25202c3030317225ull,
0x2f2f093b38303172ull,0x3532702540090a20ull,0x4c24092061726220ull,0x363536365f335f74ull,
0x2020202020203b32ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,
0x355f335f744c2420ull,0x6c2e090a34333836ull,0x353509383209636full,0x766f6d090a300934ull,
0x662509203436662eull,0x6430202c30353164ull,0x3030303030353334ull,0x3030303030303030ull,
0x382e31202f2f093bull,0x36312b6534343130ull,0x36662e6c756d090aull,0x3531646625092034ull,
0x3431646625202c31ull,0x3531646625202c37ull,0x090a202f2f093b30ull,0x203436622e766f6dull,
0x2c39303172257b09ull,0x25202c7d38317225ull,0x2f093b3135316466ull,0x636f6c2e090a202full,
0x0935353509383209ull,0x622e766f6d090a30ull,0x3172257b09203436ull,0x7d30313172252c39ull,
0x313531646625202cull,0x6d090a202f2f093bull,0x09203233732e766full,0x312d202c30337225ull,
0x202020203b373730ull,0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x3b36303336365f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x363536365f335f74ull,
0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c30363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,
0x732e766f6d090a34ull,0x3033722509203233ull,0x3b333230312d202cull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x303336365f335f74ull,0x6c3c2f2f200a3a36ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333836355f335f74ull,0x09636f6c2e090a34ull,0x3009303635093832ull,
0x33732e726873090aull,0x3131317225092032ull,0x202c38317225202cull,0x20202020203b3032ull,
0x6e61090a202f2f09ull,0x2509203233622e64ull,0x7225202c32313172ull,0x343032202c313131ull,
0x202f2f0920203b37ull,0x33732e646461090aull,0x2c30337225092032ull,0x25202c3033722520ull,
0x2020203b32313172ull,0x6c2e090a202f2f09ull,0x363509383209636full,0x646e61090a300932ull,
0x722509203233622eull,0x38317225202c3333ull,0x34363431322d202cull,0x2f093b3337303533ull,
0x622e726f090a202full,0x3433722509203233ull,0x202c33337225202cull,0x3233393632373031ull,
0x0a202f2f093b3834ull,0x3436622e766f6d09ull,0x2c35336466250920ull,0x252c393172257b20ull,
0x0920203b7d343372ull,0x766f6d090a202f2full,0x722509203233752eull,0x373031202c333131ull,
0x3b32383537323133ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,0x702509203233752eull,
0x34337225202c3632ull,0x3b3331317225202cull,0x2540090a202f2f09ull,0x2061726220363270ull,
0x365f335f744c2409ull,0x2020203b38313836ull,0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3036322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,0x383209636f6c2e09ull,
0x090a300934363509ull,0x203436622e766f6dull,0x2c34313172257b09ull,0x202c7d3531317225ull,
0x2f093b3533646625ull,0x2e627573090a202full,0x3172250920323373ull,0x31317225202c3631ull,
0x3538343031202c35ull,0x0a202f2f093b3637ull,0x3436622e766f6d09ull,0x37313172257b0920ull,
0x2c7d38313172252cull,0x093b353364662520ull,0x766f6d090a202f2full,0x662509203436622eull,
0x72257b202c353364ull,0x313172252c373131ull,0x0a202f2f093b7d36ull,0x383209636f6c2e09ull,
0x090a300935363509ull,0x203233732e646461ull,0x25202c3033722509ull,0x203b31202c303372ull,
0x2f09202020202020ull,0x335f744c240a202full,0x0a3a38313836365full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c30363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333836355full,0x09383209636f6c2eull,
0x6d090a3009393735ull,0x09203436662e766full,0x202c323531646625ull,0x3030306666626430ull,
0x3030303030303030ull,0x2d202f2f093b3030ull,0x662e646461090a31ull,0x3364662509203436ull,
0x3533646625202c37ull,0x323531646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,
0x202c333531646625ull,0x3030306666336430ull,0x3030303030303030ull,0x31202f2f093b3030ull,
0x36662e646461090aull,0x3531646625092034ull,0x3533646625202c34ull,0x333531646625202cull,
0x72090a202f2f093bull,0x36662e6e722e7063ull,0x3034646625092034ull,0x343531646625202cull,
0x2f2f09202020203bull,0x662e6c756d090a20ull,0x3464662509203436ull,0x3733646625202c31ull,
0x3b3034646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3234646625ull,
0x6625202c31346466ull,0x2f2f09203b313464ull,0x662e6c756d090a20ull,0x3464662509203436ull,
0x3234646625202c33ull,0x3b3234646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x202c353531646625ull,0x3833316265336430ull,0x6630386561336230ull,0x31202f2f093b6531ull,
0x2d6533333632302eull,0x2e766f6d090a3630ull,0x6466250920343666ull,0x336430202c363531ull,
0x3835326565306465ull,0x3b34306238613762ull,0x33302e34202f2f09ull,0x0a36302d65393436ull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x646625202c373531ull,0x646625202c353531ull,
0x31646625202c3334ull,0x0a202f2f093b3635ull,0x3436662e766f6d09ull,0x3835316466250920ull,
0x336665336430202cull,0x3230663936363262ull,0x2f2f093b66363736ull,0x34343837382e3120ull,
0x616d090a35302d65ull,0x3436662e6e722e64ull,0x3935316466250920ull,0x373531646625202cull,
0x2c3334646625202cull,0x3b38353164662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3036316466ull,0x6335343731663364ull,0x3539306261396162ull,0x2e38202f2f093b36ull,
0x302d653138373738ull,0x722e64616d090a35ull,0x2509203436662e6eull,0x25202c3136316466ull,
0x25202c3935316466ull,0x6625202c33346466ull,0x2f2f093b30363164ull,0x662e766f6d090a20ull,
0x3164662509203436ull,0x66336430202c3236ull,0x6432376331376333ull,0x093b343531356231ull,
0x3030302e30202f2full,0x090a383230343334ull,0x662e6e722e64616dull,0x3564662509203436ull,
0x3631646625202c32ull,0x3334646625202c31ull,0x323631646625202cull,0x2e090a202f2f093bull,
0x3509383209636f6cull,0x6f6d090a30093038ull,0x2509203436662e76ull,0x30202c3336316466ull,
0x3239343236663364ull,0x3237656233323934ull,0x2e30202f2f093b64ull,0x3431323332323030ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c323564ull,0x34646625202c3235ull,
0x3631646625202c33ull,0x090a202f2f093b33ull,0x09383209636f6c2eull,0x6d090a3009313835ull,
0x09203436662e766full,0x202c343631646625ull,0x3939393866336430ull,0x3361393939393939ull,
0x30202f2f093b3463ull,0x6d090a353231302eull,0x36662e6e722e6461ull,0x3235646625092034ull,
0x2c3235646625202cull,0x202c333464662520ull,0x093b343631646625ull,0x6f6c2e090a202f2full,
0x3238350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x336430202c353631ull,
0x3535353535356266ull,0x3b34353535353535ull,0x38302e30202f2f09ull,0x6d090a3333333333ull,
0x36662e6e722e6461ull,0x3235646625092034ull,0x2c3235646625202cull,0x202c333464662520ull,
0x093b353631646625ull,0x6f6c2e090a202f2full,0x3438350938320963ull,0x2e627573090a3009ull,
0x6466250920343666ull,0x33646625202c3635ull,0x3234646625202c37ull,0x090a202f2f09203bull,
0x203436662e67656eull,0x2c36363164662509ull,0x203b323464662520ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x72257b0920343662ull,0x323172252c393131ull,0x35646625202c7d30ull,
0x090a202f2f093b36ull,0x203233732e646461ull,0x202c313231722509ull,0x31202c3032317225ull,
0x093b363735383430ull,0x766f6d090a202f2full,0x257b09203436622eull,0x3172252c32323172ull,
0x646625202c7d3332ull,0x0a202f2f093b3635ull,0x3436622e766f6d09ull,0x3736316466250920ull,
0x32323172257b202cull,0x3b7d31323172252cull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c39356466250920ull,0x2c36363164662520ull,0x202c373364662520ull,0x093b373631646625ull,
0x6f6c2e090a202f2full,0x3838350938320963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x646625202c383631ull,0x35646625202c3334ull,0x090a202f2f093b32ull,0x203436662e6c756dull,
0x202c323564662509ull,0x25202c3234646625ull,0x2f093b3836316466ull,0x636f6c2e090a202full,
0x0938393509383209ull,0x722e747663090a30ull,0x33732e3436662e6eull,0x3136646625092032ull,
0x203b30337225202cull,0x6d090a202f2f0920ull,0x09203436662e766full,0x202c393631646625ull,
0x6532366566336430ull,0x3933616665663234ull,0x30202f2f093b6665ull,0x0a3734313339362eull,
0x2e6e722e64616d09ull,0x6466250920343666ull,0x36646625202c3336ull,0x3631646625202c31ull,
0x3234646625202c39ull,0x6d090a202f2f093bull,0x09203436662e766full,0x202c303731646625ull,
0x6362613763336430ull,0x3038393362336539ull,0x32202f2f093b6633ull,0x2d6535303931332eull,
0x2e64616d090a3731ull,0x09203436662e6e72ull,0x202c313731646625ull,0x25202c3935646625ull,
0x6625202c30346466ull,0x202f2f093b323564ull,0x33732e67656e090aull,0x3432317225092032ull,
0x203b30337225202cull,0x2020202020202020ull,0x7663090a202f2f09ull,0x3436662e6e722e74ull,
0x662509203233732eull,0x7225202c32373164ull,0x202f2f093b343231ull,0x36662e766f6d090aull,
0x3731646625092034ull,0x6566336430202c33ull,0x6665663234653236ull,0x2f093b6665393361ull,
0x313339362e30202full,0x2e64616d090a3734ull,0x09203436662e6e72ull,0x202c343731646625ull,
0x202c323731646625ull,0x202c333731646625ull,0x2f093b3336646625ull,0x2e627573090a202full,
0x6466250920343666ull,0x646625202c353731ull,0x646625202c343731ull,0x0a202f2f093b3234ull,
0x3436662e62757309ull,0x3637316466250920ull,0x313731646625202cull,0x353731646625202cull,
0x6d090a202f2f093bull,0x36662e6e722e6461ull,0x3137646625092034ull,0x2c3136646625202cull,
0x2c30373164662520ull,0x3b36373164662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,
0x25202c3737316466ull,0x6625202c33366466ull,0x202f2f093b313764ull,0x6e752e617262090aull,
0x335f744c24092069ull,0x20203b363835335full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x30393234345f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34333836355f335full,0x3209636f6c2e090aull,0x0a30093130360938ull,0x3436662e73626109ull,
0x3837316466250920ull,0x323431646625202cull,0x092020202020203bull,0x766f6d090a202f2full,
0x662509203436662eull,0x6430202c39373164ull,0x3030303030666637ull,0x3030303030303030ull,
0x666e69202f2f093bull,0x6c2e70746573090aull,0x2509203436662e65ull,0x646625202c373270ull,
0x646625202c383731ull,0x202f2f093b393731ull,0x203732702540090aull,0x744c240920617262ull,
0x30333337365f335full,0x202020202020203bull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c30ull,
0x2064656c6562616cull,0x36355f335f744c24ull,0x646461090a343338ull,0x662509203436662eull,
0x6625202c30383164ull,0x6625202c32343164ull,0x2f2f093b32343164ull,0x662e67656e090a20ull,
0x3164662509203436ull,0x31646625202c3737ull,0x20202020203b3038ull,0x62090a202f2f0920ull,
0x0920696e752e6172ull,0x35335f335f744c24ull,0x20202020203b3638ull,0x2f2f092020202020ull,
0x5f335f744c240a20ull,0x200a3a3033333736ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3433383635ull,0x09203436662e766full,0x202c313831646625ull,
0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,0x652e70746573090aull,
0x2509203436662e71ull,0x646625202c383270ull,0x646625202c373431ull,0x202f2f093b313831ull,
0x383270252140090aull,0x4c24092061726220ull,0x343837365f335f74ull,0x2020202020203b32ull,
0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x363220656e696c20ull,0x2064616568202c30ull,0x2064656c6562616cull,0x36355f335f744c24ull,
0x766f6d090a343338ull,0x662509203436662eull,0x6430202c37373164ull,0x3030303030666666ull,
0x3030303030303030ull,0x6e692d202f2f093bull,0x752e617262090a66ull,0x5f744c240920696eull,
0x203b363835335f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x343837365f335f74ull,
0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c30363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,
0x662e766f6d090a34ull,0x3164662509203436ull,0x66376430202c3238ull,0x3030303030303066ull,
0x093b303030303030ull,0x090a666e69202f2full,0x2e71652e70746573ull,0x3270250920343666ull,
0x3431646625202c39ull,0x3831646625202c37ull,0x090a202f2f093b32ull,0x6220393270252140ull,
0x5f744c2409206172ull,0x3b34353338365f33ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c30363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333836355f335f74ull,0x662e766f6d090a34ull,
0x3164662509203436ull,0x31646625202c3737ull,0x20202020203b3734ull,0x62090a202f2f0920ull,
0x0920696e752e6172ull,0x35335f335f744c24ull,0x20202020203b3638ull,0x2f2f092020202020ull,
0x5f335f744c240a20ull,0x200a3a3435333836ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3433383635ull,0x09203436662e766full,0x202c373731646625ull,
0x3030386666666430ull,0x3030303030303030ull,0x6e202f2f093b3030ull,0x335f744c240a6e61ull,
0x200a3a363835335full,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c303632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x2e090a3433383635ull,0x3109383109636f6cull,0x6f6d090a30093033ull,0x2509203436662e76ull,
0x6625202c37326466ull,0x2020203b37373164ull,0x202f2f0920202020ull,0x355f335f744c240aull,
0x2f200a3a34313138ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3036ull,0x64656c6562616c20ull,0x355f335f744c2420ull,
0x6c2e090a34333836ull,0x333109383109636full,0x766f6d090a300932ull,0x662509203436662eull,
0x6430202c33383164ull,0x3233393935646633ull,0x6436333034653363ull,0x332e30202f2f093bull,
0x6d090a3537343733ull,0x09203436662e766full,0x202c343831646625ull,0x6333666566336430ull,
0x3163623866633663ull,0x30202f2f093b3133ull,0x0a3936313637392eull,0x3436662e766f6d09ull,
0x3538316466250920ull,0x346366336430202cull,0x3936363237303539ull,0x2f2f093b36383630ull,
0x39373036312e3020ull,0x662e766f6d090a38ull,0x3164662509203436ull,0x66336430202c3638ull,
0x3337646165346339ull,0x093b373332343465ull,0x3732302e30202f2full,0x6f6d090a39333436ull,
0x2509203436662e76ull,0x30202c3738316466ull,0x3436376636663364ull,0x3837366533356533ull,
0x2e30202f2f093b35ull,0x3735303438333030ull,0x36662e766f6d090aull,0x3831646625092034ull,
0x3366336430202c38ull,0x6130616532366539ull,0x2f093b3634383839ull,0x333030302e30202full,
0x6f6d090a39313539ull,0x2509203436662e76ull,0x30202c3938316466ull,0x6265643030663364ull,
0x3032383566353032ull,0x2e33202f2f093b38ull,0x302d653836373132ull,0x662e766f6d090a35ull,
0x3164662509203436ull,0x65336430202c3039ull,0x3037356431363339ull,0x093b363562376239ull,
0x3838382e32202f2full,0x090a37302d653731ull,0x203436662e766f6dull,0x2c31393164662509ull,
0x3961396533643020ull,0x6432306130356333ull,0x202f2f093b646135ull,0x6532333036392e33ull,
0x64616d090a37302dull,0x203436662e6e722eull,0x2c32393164662509ull,0x2c31393164662520ull,
0x202c373264662520ull,0x093b303931646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x2c33393164662509ull,0x202c373264662520ull,0x202c323931646625ull,0x093b393831646625ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x2c34393164662509ull,0x202c373264662520ull,
0x202c333931646625ull,0x093b383831646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x2c35393164662509ull,0x202c373264662520ull,0x202c343931646625ull,0x093b373831646625ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x2c36393164662509ull,0x202c373264662520ull,
0x202c353931646625ull,0x093b363831646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x2c37393164662509ull,0x202c373264662520ull,0x202c363931646625ull,0x093b353831646625ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x2c38393164662509ull,0x202c373264662520ull,
0x202c373931646625ull,0x093b343831646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x2c39393164662509ull,0x202c373264662520ull,0x202c383931646625ull,0x093b333831646625ull,
0x67656e090a202f2full,0x662509203436662eull,0x6625202c30303264ull,0x2020203b39393164ull,
0x0a202f2f09202020ull,0x3436662e766f6d09ull,0x3130326466250920ull,0x303030306430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3020ull,0x203436662e746c2eull,
0x25202c3033702509ull,0x646625202c366466ull,0x202f2f093b313032ull,0x662e706c6573090aull,
0x3264662509203436ull,0x3032646625202c37ull,0x3931646625202c30ull,0x3b30337025202c39ull,
0x744c240a202f2f09ull,0x32303637355f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c30363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333836355f335full,0x36662e766f6d090aull,0x2c34646625092034ull,
0x203b373264662520ull,0x2020202020202020ull,0x744c240a202f2f09ull,0x3a383138325f335full,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3036322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333836355f33ull,
0x383109636f6c2e09ull,0x090a300931363209ull,0x662e6e722e747663ull,0x09203436662e3233ull,
0x646625202c326625ull,0x2f09202020203b34ull,0x672e7473090a202full,0x33662e6c61626f6cull,
0x396472255b092032ull,0x326625202c5d302bull,0x6469202f2f09203bull,0x61090a313530313aull,
0x09203233752e6464ull,0x397225202c377225ull,0x20203b377225202cull,0x2f2f092020202020ull,
0x752e646461090a20ull,0x3964722509203436ull,0x202c39647225202cull,0x2020203b36647225ull,
0x61090a202f2f0920ull,0x09203436752e6464ull,0x7225202c37647225ull,0x36647225202c3764ull,
0x2f2f09202020203bull,0x2e70746573090a20ull,0x09203233752e746cull,0x7225202c31337025ull,
0x203b317225202c37ull,0x40090a202f2f0920ull,0x6172622031337025ull,0x5f335f744c240920ull,
0x20203b3433383635ull,0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x3b32323139365f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x363036355f335f74ull,
0x636f6c2e090a3a36ull,0x0937363209383109ull,0x34326c756d090a30ull,0x203233752e6f6c2eull,
0x202c353231722509ull,0x337225202c347225ull,0x61090a202f2f093bull,0x09203233752e6464ull,
0x25202c3632317225ull,0x7225202c35323172ull,0x2f2f092020203b32ull,0x732e766f6d090a20ull,
0x3231722509203233ull,0x3632317225202c37ull,0x202020202020203bull,0x73090a202f2f0920ull,
0x752e65672e707465ull,0x3233702509203233ull,0x2c3632317225202cull,0x2f2f093b31722520ull,
0x3233702540090a20ull,0x4c24092061726220ull,0x323139365f335f74ull,0x2020202020203b32ull,
0x63090a202f2f0920ull,0x752e3436752e7476ull,0x3164722509203233ull,0x3632317225202c30ull,
0x2f2f09202020203bull,0x752e747663090a20ull,0x09203631752e3233ull,0x25202c3832317225ull,
0x782e64696174636eull,0x6d090a202f2f093bull,0x2e6f6c2e34326c75ull,0x3172250920323375ull,
0x2c347225202c3932ull,0x093b383231722520ull,0x6c756d090a202f2full,0x203436752e6f6c2eull,
0x202c313164722509ull,0x34202c3031647225ull,0x0a202f2f0920203bull,0x3436732e74766309ull,
0x722509203233752eull,0x317225202c323164ull,0x09202020203b3932ull,0x646461090a202f2full,
0x722509203233752eull,0x317225202c303331ull,0x202020203b31202cull,0x0a202f2f09202020ull,
0x2e6e722e74766309ull,0x203233752e343666ull,0x2c32303264662509ull,0x093b303331722520ull,
0x706372090a202f2full,0x203436662e6e722eull,0x2c33303264662509ull,0x3b32303264662520ull,
0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203436752e6dull,0x5f5b202c33316472ull,
0x726170616475635full,0x6e6936315a5f5f6dull,0x444e436573726576ull,0x66506c656e72654bull,
0x754f5f645f6a5f53ull,0x2f093b5d74757074ull,0x3430313a6469202full,0x616475635f5f2039ull,
0x315a5f5f6d726170ull,0x65737265766e6936ull,0x656e72654b444e43ull,0x645f6a5f5366506cull,
0x2b74757074754f5full,0x646461090a307830ull,0x722509203436752eull,0x647225202c343164ull,
0x31647225202c3331ull,0x0a202f2f09203b31ull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3531ull,0x0920203b34202c32ull,0x5f744c240a202f2full,0x3a34333639365f33ull,
0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x2e090a3936322065ull,
0x3209383109636f6cull,0x6461090a30093936ull,0x2509203233752e64ull,0x7225202c31333172ull,
0x203b31202c373231ull,0x202f2f0920202020ull,0x6e722e747663090aull,0x3233752e3436662eull,
0x3430326466250920ull,0x3b3133317225202cull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x25202c3530326466ull,0x25202c3430326466ull,0x2f093b3330326466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c363032ull,0x3030303030306666ull,0x3b30303030303030ull,
0x73090a31202f2f09ull,0x33752e65672e7465ull,0x2509203436662e32ull,0x6625202c32333172ull,
0x6625202c35303264ull,0x2f2f093b36303264ull,0x732e67656e090a20ull,0x3331722509203233ull,
0x3233317225202c33ull,0x202020202020203bull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x202c373032646625ull,0x3030303030306430ull,0x3030303030303030ull,0x30202f2f093b3030ull,
0x656c2e746573090aull,0x3436662e3233752eull,0x2c34333172250920ull,0x2c35303264662520ull,
0x3b37303264662520ull,0x656e090a202f2f09ull,0x2509203233732e67ull,0x7225202c35333172ull,
0x202020203b343331ull,0x202f2f0920202020ull,0x3233622e726f090aull,0x2c36333172250920ull,
0x202c333331722520ull,0x20203b3533317225ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x3b30202c37333172ull,0x2020202020202020ull,0x202f2f0920202020ull,0x652e70746573090aull,
0x2509203233732e71ull,0x317225202c333370ull,0x33317225202c3633ull,0x090a202f2f093b37ull,
0x7262203333702540ull,0x335f744c24092061ull,0x203b30393839365full,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333639365f335f74ull,
0x662e766f6d090a34ull,0x3264662509203436ull,0x66666430202c3830ull,0x3030303030303866ull,
0x093b303030303030ull,0x090a6e616e202f2full,0x20696e752e617262ull,0x325f335f744c2409ull,
0x20202020203b3835ull,0x2f09202020202020ull,0x335f744c240a202full,0x0a3a30393839365full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333639365full,
0x09383109636f6c2eull,0x6d090a3009333231ull,0x09203436662e766full,0x202c393032646625ull,
0x3030306566626430ull,0x3030303030303030ull,0x2d202f2f093b3030ull,0x646461090a352e30ull,
0x662509203436662eull,0x6625202c30313264ull,0x6625202c35303264ull,0x2f2f093b39303264ull,
0x662e736261090a20ull,0x3264662509203436ull,0x32646625202c3131ull,0x20202020203b3031ull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x202c323132646625ull,0x3165616466336430ull,
0x6137343165613734ull,0x30202f2f093b3165ull,0x746573090a32342eull,0x3436662e746c2e70ull,
0x202c343370250920ull,0x202c313132646625ull,0x093b323132646625ull,0x252140090a202f2full,
0x2061726220343370ull,0x375f335f744c2409ull,0x2020203b38353630ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333639365full,
0x09383109636f6c2eull,0x6d090a3009353231ull,0x09203436662e6c75ull,0x202c333132646625ull,
0x202c303132646625ull,0x093b303132646625ull,0x766f6d090a202f2full,0x662509203436662eull,
0x6430202c34313264ull,0x3339643034303034ull,0x6430323638326231ull,0x352e32202f2f093bull,
0x6f6d090a33363630ull,0x2509203436662e76ull,0x30202c3531326466ull,0x3764393233306364ull,
0x6433613435656130ull,0x312d202f2f093b65ull,0x6d090a3531362e38ull,0x09203436662e766full,
0x202c363132646625ull,0x3262343430346430ull,0x3663333734633231ull,0x34202f2f093b6366ull,
0x090a323139332e31ull,0x203436662e766f6dull,0x2c37313264662509ull,0x3739333063643020ull,
0x3737333735396530ull,0x202f2f093b383737ull,0x313134342e35322dull,0x6e722e64616d090aull,
0x662509203436662eull,0x6625202c38313264ull,0x6625202c37313264ull,0x6625202c33313264ull,
0x2f2f093b36313264ull,0x722e64616d090a20ull,0x2509203436662e6eull,0x25202c3931326466ull,
0x25202c3331326466ull,0x25202c3831326466ull,0x2f093b3531326466ull,0x2e64616d090a202full,
0x09203436662e6e72ull,0x202c303232646625ull,0x202c333132646625ull,0x202c393132646625ull,
0x093b343132646625ull,0x6c756d090a202f2full,0x662509203436662eull,0x6625202c31323264ull,
0x6625202c30313264ull,0x2f2f093b30323264ull,0x662e766f6d090a20ull,0x3264662509203436ull,
0x66336430202c3232ull,0x3030303030303066ull,0x093b303030303030ull,0x6f6d090a31202f2full,
0x2509203436662e76ull,0x30202c3332326466ull,0x3732663032306364ull,0x3237303535363030ull,
0x382d202f2f093b64ull,0x090a31353337342eull,0x203436662e766f6dull,0x2c34323264662509ull,
0x3137333034643020ull,0x3531383139373535ull,0x202f2f093b633230ull,0x0a343338302e3332ull,
0x3436662e766f6d09ull,0x3532326466250920ull,0x353330636430202cull,0x3130373066656630ull,
0x2f2f093b64373565ull,0x3236302e31322d20ull,0x662e766f6d090a32ull,0x3264662509203436ull,
0x30346430202c3632ull,0x3032306662303930ull,0x093b373461383535ull,0x3033312e33202f2full,
0x2e64616d090a3338ull,0x09203436662e6e72ull,0x202c373232646625ull,0x202c363232646625ull,
0x202c333132646625ull,0x093b353232646625ull,0x64616d090a202f2full,0x203436662e6e722eull,
0x2c38323264662509ull,0x2c33313264662520ull,0x2c37323264662520ull,0x3b34323264662520ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x3932326466250920ull,0x333132646625202cull,
0x383232646625202cull,0x333232646625202cull,0x6d090a202f2f093bull,0x36662e6e722e6461ull,
0x3332646625092034ull,0x3132646625202c30ull,0x3232646625202c33ull,0x3232646625202c39ull,
0x090a202f2f093b32ull,0x662e6e722e766964ull,0x3264662509203436ull,0x3232646625202c37ull,
0x3332646625202c31ull,0x090a202f2f093b30ull,0x20696e752e617262ull,0x375f335f744c2409ull,
0x2020203b32303430ull,0x2f09202020202020ull,0x335f744c240a202full,0x0a3a38353630375full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333639365full,
0x203436662e766f6dull,0x2c31333264662509ull,0x3030303030643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x2e70746573090a30ull,0x09203436662e7467ull,0x6625202c35337025ull,
0x6625202c30313264ull,0x2f2f093b31333264ull,0x3370252140090a20ull,0x2409206172622035ull,
0x3131375f335f744cull,0x20202020203b3037ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3936ull,
0x64656c6562616c20ull,0x365f335f744c2420ull,0x6c2e090a34333639ull,0x343509383209636full,
0x766f6d090a300935ull,0x662509203436662eull,0x6430202c32333264ull,0x3030303030666633ull,
0x3030303030303030ull,0x090a31202f2f093bull,0x203436662e627573ull,0x2c33333264662509ull,
0x2c32333264662520ull,0x3b35303264662520ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,
0x72252c3833317225ull,0x6625202c7d393331ull,0x2f2f093b33333264ull,0x732e766f6d090a20ull,
0x3831722509203233ull,0x3b3933317225202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,
0x3509383209636f6cull,0x6f6d090a30093634ull,0x7b09203436622e76ull,0x3172252c39317225ull,
0x646625202c7d3034ull,0x202f2f093b333332ull,0x3209636f6c2e090aull,0x0a30093834350938ull,
0x3436662e766f6d09ull,0x3433326466250920ull,0x303030306430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x2e746573090a3020ull,0x662e3233752e7467ull,0x3431722509203436ull,
0x3332646625202c31ull,0x3332646625202c33ull,0x090a202f2f093b34ull,0x203233732e67656eull,
0x202c323431722509ull,0x20203b3134317225ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x376430202c353332ull,0x3030303030306666ull,0x3b30303030303030ull,
0x0a666e69202f2f09ull,0x2e746c2e74657309ull,0x203436662e323375ull,0x202c333431722509ull,
0x202c333332646625ull,0x093b353332646625ull,0x67656e090a202f2full,0x722509203233732eull,
0x317225202c343431ull,0x20202020203b3334ull,0x0a202f2f09202020ull,0x3233622e646e6109ull,
0x2c35343172250920ull,0x202c323431722520ull,0x09203b3434317225ull,0x766f6d090a202f2full,
0x722509203233752eull,0x203b30202c363431ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x71652e7074657309ull,0x702509203233732eull,0x34317225202c3633ull,0x3634317225202c35ull,
0x40090a202f2f093bull,0x6172622036337025ull,0x5f335f744c240920ull,0x20203b3236333734ull,
0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34333639365f335full,0x33752e766f6d090aull,0x3734317225092032ull,0x373538343031202cull,
0x2020202020203b35ull,0x6573090a202f2f09ull,0x33752e74672e7074ull,0x2c37337025092032ull,
0x202c393331722520ull,0x2f093b3734317225ull,0x33702540090a202full,0x2409206172622037ull,
0x3631375f335f744cull,0x20202020203b3238ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3433363936ull,0x3509383209636f6cull,
0x6f6d090a30093435ull,0x2509203436662e76ull,0x30202c3633326466ull,0x3030303035333464ull,
0x3030303030303030ull,0x2e31202f2f093b30ull,0x312b653434313038ull,0x662e6c756d090a36ull,
0x3264662509203436ull,0x32646625202c3733ull,0x32646625202c3333ull,0x0a202f2f093b3633ull,
0x3436622e766f6d09ull,0x38343172257b0920ull,0x202c7d383172252cull,0x093b373332646625ull,
0x6f6c2e090a202f2full,0x3535350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,
0x39343172252c3931ull,0x3332646625202c7dull,0x090a202f2f093b37ull,0x203233732e766f6dull,
0x2d202c3033722509ull,0x2020203b37373031ull,0x2f09202020202020ull,0x2e617262090a202full,
0x744c240920696e75ull,0x36323431375f335full,0x202020202020203bull,0x240a202f2f092020ull,
0x3631375f335f744cull,0x3c2f2f200a3a3238ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639365f335f744cull,0x2e766f6d090a3433ull,0x3372250920323373ull,0x333230312d202c30ull,
0x202020202020203bull,0x240a202f2f092020ull,0x3431375f335f744cull,0x3c2f2f200a3a3632ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,0x636f6c2e090a3433ull,
0x0930363509383209ull,0x732e726873090a30ull,0x3531722509203233ull,0x2c38317225202c30ull,
0x202020203b303220ull,0x61090a202f2f0920ull,0x09203233622e646eull,0x25202c3135317225ull,
0x3032202c30353172ull,0x2f2f0920203b3734ull,0x732e646461090a20ull,0x3033722509203233ull,
0x202c30337225202cull,0x20203b3135317225ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,
0x6e61090a30093236ull,0x2509203233622e64ull,0x317225202c333372ull,0x363431322d202c38ull,
0x093b333730353334ull,0x2e726f090a202f2full,0x3372250920323362ull,0x2c33337225202c34ull,
0x3339363237303120ull,0x202f2f093b383432ull,0x36622e766f6d090aull,0x3533646625092034ull,
0x2c393172257b202cull,0x20203b7d34337225ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x3031202c32353172ull,0x3238353732313337ull,0x202f2f092020203bull,0x6c2e70746573090aull,
0x2509203233752e65ull,0x337225202c383370ull,0x3235317225202c34ull,0x40090a202f2f093bull,
0x6172622038337025ull,0x5f335f744c240920ull,0x20203b3833393137ull,0x2f2f092020202020ull,
0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,
0x3209636f6c2e090aull,0x0a30093436350938ull,0x3436622e766f6d09ull,0x33353172257b0920ull,
0x2c7d34353172252cull,0x093b353364662520ull,0x627573090a202f2full,0x722509203233732eull,
0x317225202c353531ull,0x38343031202c3435ull,0x202f2f093b363735ull,0x36622e766f6d090aull,
0x353172257b092034ull,0x7d37353172252c36ull,0x3b3533646625202cull,0x6f6d090a202f2f09ull,
0x2509203436622e76ull,0x257b202c35336466ull,0x3172252c36353172ull,0x202f2f093b7d3535ull,
0x3209636f6c2e090aull,0x0a30093536350938ull,0x3233732e64646109ull,0x202c303372250920ull,
0x3b31202c30337225ull,0x0920202020202020ull,0x5f744c240a202f2full,0x3a38333931375f33ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333639365f33ull,
0x383209636f6c2e09ull,0x090a300939373509ull,0x203436662e766f6dull,0x2c38333264662509ull,
0x3030666662643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x2e646461090a312dull,
0x6466250920343666ull,0x33646625202c3733ull,0x3332646625202c35ull,0x090a202f2f093b38ull,
0x203436662e766f6dull,0x2c39333264662509ull,0x3030666633643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x662e646461090a31ull,0x3264662509203436ull,0x33646625202c3034ull,
0x3332646625202c35ull,0x090a202f2f093b39ull,0x662e6e722e706372ull,0x3464662509203436ull,
0x3432646625202c30ull,0x2f09202020203b30ull,0x2e6c756d090a202full,0x6466250920343666ull,
0x33646625202c3134ull,0x3034646625202c37ull,0x090a202f2f09203bull,0x203436662e646461ull,
0x202c323464662509ull,0x25202c3134646625ull,0x2f09203b31346466ull,0x2e6c756d090a202full,
0x6466250920343666ull,0x34646625202c3334ull,0x3234646625202c32ull,0x090a202f2f09203bull,
0x203436662e766f6dull,0x2c31343264662509ull,0x3331626533643020ull,0x3038656133623038ull,
0x202f2f093b653166ull,0x6533333632302e31ull,0x766f6d090a36302dull,0x662509203436662eull,
0x6430202c32343264ull,0x3532656530646533ull,0x3430623861376238ull,0x302e34202f2f093bull,
0x36302d6539343633ull,0x6e722e64616d090aull,0x662509203436662eull,0x6625202c33343264ull,
0x6625202c31343264ull,0x646625202c333464ull,0x202f2f093b323432ull,0x36662e766f6d090aull,
0x3432646625092034ull,0x6665336430202c34ull,0x3066393636326233ull,0x2f093b6636373632ull,
0x343837382e31202full,0x6d090a35302d6534ull,0x36662e6e722e6461ull,0x3432646625092034ull,
0x3432646625202c35ull,0x3334646625202c33ull,0x343432646625202cull,0x6d090a202f2f093bull,
0x09203436662e766full,0x202c363432646625ull,0x3534373166336430ull,0x3930626139616263ull,
0x38202f2f093b3635ull,0x2d6531383737382eull,0x2e64616d090a3530ull,0x09203436662e6e72ull,
0x202c373432646625ull,0x202c353432646625ull,0x25202c3334646625ull,0x2f093b3634326466ull,
0x2e766f6d090a202full,0x6466250920343666ull,0x336430202c383432ull,0x3237633137633366ull,
0x3b34353135623164ull,0x30302e30202f2f09ull,0x0a38323034333430ull,0x2e6e722e64616d09ull,
0x6466250920343666ull,0x32646625202c3235ull,0x34646625202c3734ull,0x3432646625202c33ull,
0x090a202f2f093b38ull,0x09383209636f6c2eull,0x6d090a3009303835ull,0x09203436662e766full,
0x202c393432646625ull,0x3934323666336430ull,0x3765623332393432ull,0x30202f2f093b6432ull,
0x313233323230302eull,0x722e64616d090a34ull,0x2509203436662e6eull,0x6625202c32356466ull,
0x646625202c323564ull,0x32646625202c3334ull,0x0a202f2f093b3934ull,0x383209636f6c2e09ull,
0x090a300931383509ull,0x203436662e766f6dull,0x2c30353264662509ull,0x3939386633643020ull,
0x6139393939393939ull,0x202f2f093b346333ull,0x090a353231302e30ull,0x662e6e722e64616dull,
0x3564662509203436ull,0x3235646625202c32ull,0x2c3334646625202cull,0x3b30353264662520ull,
0x6c2e090a202f2f09ull,0x383509383209636full,0x766f6d090a300932ull,0x662509203436662eull,
0x6430202c31353264ull,0x3535353535626633ull,0x3435353535353535ull,0x302e30202f2f093bull,
0x090a333333333338ull,0x662e6e722e64616dull,0x3564662509203436ull,0x3235646625202c32ull,
0x2c3334646625202cull,0x3b31353264662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,
0x627573090a300934ull,0x662509203436662eull,0x646625202c363564ull,0x34646625202c3733ull,
0x0a202f2f09203b32ull,0x3436662e67656e09ull,0x3235326466250920ull,0x3b3234646625202cull,
0x0920202020202020ull,0x766f6d090a202f2full,0x257b09203436622eull,0x3172252c38353172ull,
0x646625202c7d3935ull,0x0a202f2f093b3635ull,0x3233732e64646109ull,0x2c30363172250920ull,
0x202c393531722520ull,0x3b36373538343031ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,
0x72252c3136317225ull,0x6625202c7d323631ull,0x202f2f093b363564ull,0x36622e766f6d090aull,
0x3532646625092034ull,0x363172257b202c33ull,0x7d30363172252c31ull,0x6d090a202f2f093bull,
0x36662e6e722e6461ull,0x3935646625092034ull,0x323532646625202cull,0x2c3733646625202cull,
0x3b33353264662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,0x6c756d090a300938ull,
0x662509203436662eull,0x6625202c34353264ull,0x646625202c333464ull,0x0a202f2f093b3235ull,
0x3436662e6c756d09ull,0x2c32356466250920ull,0x202c323464662520ull,0x093b343532646625ull,
0x6f6c2e090a202f2full,0x3839350938320963ull,0x2e747663090a3009ull,0x732e3436662e6e72ull,
0x3664662509203233ull,0x3b30337225202c31ull,0x090a202f2f092020ull,0x203436662e766f6dull,
0x2c35353264662509ull,0x3236656633643020ull,0x3361666566323465ull,0x202f2f093b666539ull,
0x3734313339362e30ull,0x6e722e64616d090aull,0x662509203436662eull,0x646625202c333664ull,
0x32646625202c3136ull,0x34646625202c3535ull,0x090a202f2f093b32ull,0x203436662e766f6dull,
0x2c36353264662509ull,0x6261376333643020ull,0x3839336233653963ull,0x202f2f093b663330ull,
0x6535303931332e32ull,0x64616d090a37312dull,0x203436662e6e722eull,0x2c37353264662509ull,
0x202c393564662520ull,0x25202c3034646625ull,0x2f2f093b32356466ull,0x732e67656e090a20ull,
0x3631722509203233ull,0x3b30337225202c33ull,0x2020202020202020ull,0x63090a202f2f0920ull,
0x36662e6e722e7476ull,0x2509203233732e34ull,0x25202c3835326466ull,0x2f2f093b33363172ull,
0x662e766f6d090a20ull,0x3264662509203436ull,0x66336430202c3935ull,0x6566323465323665ull,
0x093b666539336166ull,0x3339362e30202f2full,0x64616d090a373431ull,0x203436662e6e722eull,
0x2c30363264662509ull,0x2c38353264662520ull,0x2c39353264662520ull,0x093b333664662520ull,
0x627573090a202f2full,0x662509203436662eull,0x6625202c31363264ull,0x6625202c30363264ull,
0x202f2f093b323464ull,0x36662e627573090aull,0x3632646625092034ull,0x3532646625202c32ull,
0x3632646625202c37ull,0x090a202f2f093b31ull,0x662e6e722e64616dull,0x3764662509203436ull,
0x3136646625202c31ull,0x363532646625202cull,0x323632646625202cull,0x61090a202f2f093bull,
0x09203436662e6464ull,0x25202c3237646625ull,0x6625202c33366466ull,0x2f2f09203b313764ull,
0x752e617262090a20ull,0x5f744c240920696eull,0x203b383335315f33ull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x363337345f335f74ull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333639365f335f74ull,0x09636f6c2e090a34ull,0x3009313036093832ull,
0x36662e736261090aull,0x3632646625092034ull,0x3332646625202c33ull,0x2020202020203b33ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x30202c3436326466ull,0x3030303066663764ull,
0x3030303030303030ull,0x6e69202f2f093b30ull,0x2e70746573090a66ull,0x09203436662e656cull,
0x6625202c39337025ull,0x6625202c33363264ull,0x2f2f093b34363264ull,0x3933702540090a20ull,
0x4c24092061726220ull,0x353432375f335f74ull,0x2020202020203b30ull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3936ull,0x64656c6562616c20ull,0x365f335f744c2420ull,0x6461090a34333639ull,
0x2509203436662e64ull,0x6625202c32376466ull,0x6625202c33333264ull,0x2f2f093b33333264ull,
0x752e617262090a20ull,0x5f744c240920696eull,0x203b383335315f33ull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x353432375f335f74ull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333639365f335f74ull,0x662e766f6d090a34ull,0x3264662509203436ull,
0x30306430202c3536ull,0x3030303030303030ull,0x093b303030303030ull,0x6573090a30202f2full,
0x36662e71652e7074ull,0x2c30347025092034ull,0x2c33333264662520ull,0x3b35363264662520ull,
0x2140090a202f2f09ull,0x6172622030347025ull,0x5f335f744c240920ull,0x20203b3236393237ull,
0x202f2f0920202020ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34333639365f33ull,0x3436662e766f6d09ull,0x2c32376466250920ull,0x3030666666643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x7262090a666e692dull,0x240920696e752e61ull,
0x3335315f335f744cull,0x2020202020203b38ull,0x202f2f0920202020ull,0x375f335f744c240aull,
0x2f200a3a32363932ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,0x365f335f744c2420ull,
0x6f6d090a34333639ull,0x2509203436662e76ull,0x30202c3636326466ull,0x3030303066663764ull,
0x3030303030303030ull,0x6e69202f2f093b30ull,0x2e70746573090a66ull,0x09203436662e7165ull,
0x6625202c31347025ull,0x6625202c33333264ull,0x2f2f093b36363264ull,0x3470252140090a20ull,
0x2409206172622031ull,0x3433375f335f744cull,0x20202020203b3437ull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3936ull,0x64656c6562616c20ull,0x365f335f744c2420ull,0x6f6d090a34333639ull,
0x2509203436662e76ull,0x6625202c32376466ull,0x2020203b33333264ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x20203b383335315full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x34373433375f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333639365f335full,0x36662e766f6d090aull,0x3237646625092034ull,
0x386666666430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x744c240a6e616e20ull,
0x3a383335315f335full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3936322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34333639365f33ull,0x383209636f6c2e09ull,0x090a300935343509ull,0x203436662e67656eull,
0x2c37363264662509ull,0x203b323764662520ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x72257b0920343662ull,0x363172252c343631ull,0x32646625202c7d35ull,0x0a202f2f093b3736ull,
0x3233732e766f6d09ull,0x202c383172250920ull,0x20203b3536317225ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3634350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,
0x36363172252c3931ull,0x3632646625202c7dull,0x090a202f2f093b37ull,0x09383209636f6c2eull,
0x6d090a3009383435ull,0x09203436662e766full,0x202c383632646625ull,0x3030303030306430ull,
0x3030303030303030ull,0x30202f2f093b3030ull,0x74672e746573090aull,0x3436662e3233752eull,
0x2c37363172250920ull,0x2c37363264662520ull,0x3b38363264662520ull,0x656e090a202f2f09ull,
0x2509203233732e67ull,0x7225202c38363172ull,0x202020203b373631ull,0x202f2f0920202020ull,
0x36662e766f6d090aull,0x3632646625092034ull,0x6666376430202c39ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x73090a666e69202full,0x33752e746c2e7465ull,0x2509203436662e32ull,
0x6625202c39363172ull,0x6625202c37363264ull,0x2f2f093b39363264ull,0x732e67656e090a20ull,
0x3731722509203233ull,0x3936317225202c30ull,0x202020202020203bull,0x61090a202f2f0920ull,
0x09203233622e646eull,0x25202c3137317225ull,0x7225202c38363172ull,0x2f2f09203b303731ull,
0x752e766f6d090a20ull,0x3731722509203233ull,0x2020203b30202c32ull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e71652e707465ull,0x3234702509203233ull,0x2c3137317225202cull,
0x093b323731722520ull,0x702540090a202f2full,0x0920617262203234ull,0x38345f335f744c24ull,
0x202020203b383938ull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a34333639365full,0x203233752e766f6dull,0x202c333731722509ull,
0x3b35373538343031ull,0x2f09202020202020ull,0x70746573090a202full,0x203233752e74672eull,
0x25202c3334702509ull,0x7225202c35363172ull,0x202f2f093b333731ull,0x203334702540090aull,
0x744c240920617262ull,0x32343234375f335full,0x202020202020203bull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,
0x2064616568202c39ull,0x2064656c6562616cull,0x39365f335f744c24ull,0x6f6c2e090a343336ull,
0x3435350938320963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,0x346430202c303732ull,
0x3030303030303533ull,0x3b30303030303030ull,0x30382e31202f2f09ull,0x0a36312b65343431ull,
0x3436662e6c756d09ull,0x3137326466250920ull,0x373632646625202cull,0x303732646625202cull,
0x6d090a202f2f093bull,0x09203436622e766full,0x252c34373172257bull,0x6625202c7d383172ull,
0x2f2f093b31373264ull,0x09636f6c2e090a20ull,0x3009353535093832ull,0x36622e766f6d090aull,
0x393172257b092034ull,0x2c7d35373172252cull,0x3b31373264662520ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x30312d202c303372ull,0x20202020203b3737ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x203b36383933375full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x32343234375f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333639365f335full,0x33732e766f6d090aull,0x2c30337225092032ull,
0x203b333230312d20ull,0x2020202020202020ull,0x744c240a202f2f09ull,0x36383933375f335full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,
0x3209636f6c2e090aull,0x0a30093036350938ull,0x3233732e72687309ull,0x2c36373172250920ull,
0x32202c3831722520ull,0x0920202020203b30ull,0x646e61090a202f2full,0x722509203233622eull,
0x317225202c373731ull,0x37343032202c3637ull,0x0a202f2f0920203bull,0x3233732e64646109ull,
0x202c303372250920ull,0x7225202c30337225ull,0x092020203b373731ull,0x6f6c2e090a202f2full,
0x3236350938320963ull,0x2e646e61090a3009ull,0x3372250920323362ull,0x2c38317225202c33ull,
0x3334363431322d20ull,0x2f2f093b33373035ull,0x33622e726f090a20ull,0x2c34337225092032ull,
0x31202c3333722520ull,0x3432333936323730ull,0x090a202f2f093b38ull,0x203436622e766f6dull,
0x202c353364662509ull,0x72252c393172257bull,0x2f0920203b7d3433ull,0x2e766f6d090a202full,
0x3172250920323375ull,0x33373031202c3837ull,0x203b323835373231ull,0x090a202f2f092020ull,
0x2e656c2e70746573ull,0x3470250920323375ull,0x2c34337225202c34ull,0x093b383731722520ull,
0x702540090a202f2full,0x0920617262203434ull,0x34375f335f744c24ull,0x202020203b383934ull,
0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x090a34333639365full,0x09383209636f6c2eull,0x6d090a3009343635ull,0x09203436622e766full,
0x252c39373172257bull,0x25202c7d30383172ull,0x2f2f093b35336466ull,0x732e627573090a20ull,
0x3831722509203233ull,0x3038317225202c31ull,0x373538343031202cull,0x090a202f2f093b36ull,
0x203436622e766f6dull,0x2c32383172257b09ull,0x202c7d3338317225ull,0x2f093b3533646625ull,
0x2e766f6d090a202full,0x6466250920343662ull,0x3172257b202c3533ull,0x31383172252c3238ull,
0x090a202f2f093b7dull,0x09383209636f6c2eull,0x61090a3009353635ull,0x09203233732e6464ull,
0x7225202c30337225ull,0x20203b31202c3033ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x200a3a3839343437ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x2e090a3433363936ull,0x3509383209636f6cull,0x6f6d090a30093937ull,0x2509203436662e76ull,
0x30202c3237326466ull,0x3030303066666264ull,0x3030303030303030ull,0x312d202f2f093b30ull,
0x36662e646461090aull,0x3733646625092034ull,0x2c3533646625202cull,0x3b32373264662520ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x30202c3337326466ull,0x3030303066663364ull,
0x3030303030303030ull,0x0a31202f2f093b30ull,0x3436662e64646109ull,0x3437326466250920ull,
0x2c3533646625202cull,0x3b33373264662520ull,0x6372090a202f2f09ull,0x3436662e6e722e70ull,
0x2c30346466250920ull,0x3b34373264662520ull,0x202f2f0920202020ull,0x36662e6c756d090aull,
0x3134646625092034ull,0x2c3733646625202cull,0x203b303464662520ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x6625202c32346466ull,0x646625202c313464ull,0x202f2f09203b3134ull,
0x36662e6c756d090aull,0x3334646625092034ull,0x2c3234646625202cull,0x203b323464662520ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x30202c3537326466ull,0x3038333162653364ull,
0x3166303865613362ull,0x2e31202f2f093b65ull,0x302d653333363230ull,0x662e766f6d090a36ull,
0x3264662509203436ull,0x65336430202c3637ull,0x6238353265653064ull,0x093b343062386137ull,
0x3633302e34202f2full,0x090a36302d653934ull,0x662e6e722e64616dull,0x3264662509203436ull,
0x32646625202c3737ull,0x34646625202c3537ull,0x3732646625202c33ull,0x090a202f2f093b36ull,
0x203436662e766f6dull,0x2c38373264662509ull,0x6233666533643020ull,0x3632306639363632ull,
0x202f2f093b663637ull,0x6534343837382e31ull,0x64616d090a35302dull,0x203436662e6e722eull,
0x2c39373264662509ull,0x2c37373264662520ull,0x202c333464662520ull,0x093b383732646625ull,
0x766f6d090a202f2full,0x662509203436662eull,0x6430202c30383264ull,0x6263353437316633ull,
0x3635393062613961ull,0x382e38202f2f093bull,0x35302d6531383737ull,0x6e722e64616d090aull,
0x662509203436662eull,0x6625202c31383264ull,0x6625202c39373264ull,0x646625202c333464ull,
0x202f2f093b303832ull,0x36662e766f6d090aull,0x3832646625092034ull,0x3366336430202c32ull,
0x3164323763313763ull,0x2f093b3435313562ull,0x343030302e30202full,0x6d090a3832303433ull,
0x36662e6e722e6461ull,0x3235646625092034ull,0x313832646625202cull,0x2c3334646625202cull,
0x3b32383264662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,0x766f6d090a300930ull,
0x662509203436662eull,0x6430202c33383264ull,0x3432393432366633ull,0x6432376562333239ull,
0x302e30202f2f093bull,0x0a34313233323230ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x35646625202c3235ull,0x3334646625202c32ull,0x333832646625202cull,0x2e090a202f2f093bull,
0x3509383209636f6cull,0x6f6d090a30093138ull,0x2509203436662e76ull,0x30202c3438326466ull,
0x3939393938663364ull,0x6333613939393939ull,0x2e30202f2f093b34ull,0x616d090a35323130ull,
0x3436662e6e722e64ull,0x2c32356466250920ull,0x202c323564662520ull,0x25202c3334646625ull,
0x2f093b3438326466ull,0x636f6c2e090a202full,0x0932383509383209ull,0x662e766f6d090a30ull,
0x3264662509203436ull,0x66336430202c3538ull,0x3535353535353562ull,0x093b343535353535ull,
0x3338302e30202f2full,0x616d090a33333333ull,0x3436662e6e722e64ull,0x2c32356466250920ull,
0x202c323564662520ull,0x25202c3334646625ull,0x2f093b3538326466ull,0x636f6c2e090a202full,
0x0934383509383209ull,0x662e627573090a30ull,0x3564662509203436ull,0x3733646625202c36ull,
0x3b3234646625202cull,0x6e090a202f2f0920ull,0x09203436662e6765ull,0x202c363832646625ull,
0x20203b3234646625ull,0x2f2f092020202020ull,0x622e766f6d090a20ull,0x3172257b09203436ull,
0x35383172252c3438ull,0x3635646625202c7dull,0x61090a202f2f093bull,0x09203233732e6464ull,
0x25202c3638317225ull,0x3031202c35383172ull,0x2f093b3637353834ull,0x2e766f6d090a202full,
0x72257b0920343662ull,0x383172252c373831ull,0x35646625202c7d38ull,0x090a202f2f093b36ull,
0x203436622e766f6dull,0x2c37383264662509ull,0x2c37383172257b20ull,0x093b7d3638317225ull,
0x64616d090a202f2full,0x203436662e6e722eull,0x202c393564662509ull,0x202c363832646625ull,
0x25202c3733646625ull,0x2f093b3738326466ull,0x636f6c2e090a202full,0x0938383509383209ull,
0x662e6c756d090a30ull,0x3264662509203436ull,0x34646625202c3838ull,0x3235646625202c33ull,
0x6d090a202f2f093bull,0x09203436662e6c75ull,0x25202c3235646625ull,0x6625202c32346466ull,
0x2f2f093b38383264ull,0x09636f6c2e090a20ull,0x3009383935093832ull,0x6e722e747663090aull,
0x3233732e3436662eull,0x2c31366466250920ull,0x20203b3033722520ull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3938326466ull,0x3465323665663364ull,0x6539336166656632ull,
0x2e30202f2f093b66ull,0x090a373431333936ull,0x662e6e722e64616dull,0x3664662509203436ull,
0x3136646625202c33ull,0x393832646625202cull,0x3b3234646625202cull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3039326466ull,0x3963626137633364ull,0x3330383933623365ull,
0x2e32202f2f093b66ull,0x312d653530393133ull,0x722e64616d090a37ull,0x2509203436662e6eull,
0x25202c3139326466ull,0x6625202c39356466ull,0x646625202c303464ull,0x0a202f2f093b3235ull,
0x3233732e67656e09ull,0x2c39383172250920ull,0x20203b3033722520ull,0x0920202020202020ull,
0x747663090a202f2full,0x2e3436662e6e722eull,0x6466250920323373ull,0x317225202c323932ull,
0x0a202f2f093b3938ull,0x3436662e766f6d09ull,0x3339326466250920ull,0x366566336430202cull,
0x6166656632346532ull,0x2f2f093b66653933ull,0x34313339362e3020ull,0x722e64616d090a37ull,
0x2509203436662e6eull,0x25202c3439326466ull,0x25202c3239326466ull,0x25202c3339326466ull,
0x2f2f093b33366466ull,0x662e627573090a20ull,0x3264662509203436ull,0x32646625202c3539ull,
0x34646625202c3439ull,0x090a202f2f093b32ull,0x203436662e627573ull,0x2c36393264662509ull,
0x2c31393264662520ull,0x3b35393264662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x2c31376466250920ull,0x202c313664662520ull,0x202c303932646625ull,0x093b363932646625ull,
0x646461090a202f2full,0x662509203436662eull,0x6625202c37303164ull,0x646625202c333664ull,
0x0a202f2f093b3137ull,0x696e752e61726209ull,0x5f335f744c240920ull,0x2020203b30353032ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x3a38393838345f33ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3936322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333639365f33ull,0x383209636f6c2e09ull,
0x090a300931303609ull,0x203436662e736261ull,0x2c37393264662509ull,0x203b323764662520ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x6466250920343666ull,0x376430202c383932ull,
0x3030303030306666ull,0x3b30303030303030ull,0x0a666e69202f2f09ull,0x656c2e7074657309ull,
0x702509203436662eull,0x32646625202c3534ull,0x32646625202c3739ull,0x0a202f2f093b3839ull,
0x6220353470254009ull,0x5f744c2409206172ull,0x3b30313035375f33ull,0x0920202020202020ull,
0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,
0x2e646461090a3433ull,0x6466250920343666ull,0x646625202c393932ull,0x37646625202c3237ull,
0x090a202f2f093b32ull,0x203436662e67656eull,0x2c37303164662509ull,0x3b39393264662520ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x3b303530325f335full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3035375f335f744cull,0x3c2f2f200a3a3031ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,0x2e766f6d090a3433ull,
0x6466250920343666ull,0x306430202c303033ull,0x3030303030303030ull,0x3b30303030303030ull,
0x73090a30202f2f09ull,0x662e71652e707465ull,0x3634702509203436ull,0x373632646625202cull,
0x303033646625202cull,0x40090a202f2f093bull,0x7262203634702521ull,0x335f744c24092061ull,
0x203b32323535375full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333639365f335full,0x36662e766f6d090aull,0x3031646625092034ull,
0x6666666430202c37ull,0x3030303030303030ull,0x2f093b3030303030ull,0x090a666e692d202full,
0x20696e752e617262ull,0x325f335f744c2409ull,0x202020203b303530ull,0x2f09202020202020ull,
0x335f744c240a202full,0x0a3a32323535375full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a34333639365full,0x203436662e766f6dull,0x2c31303364662509ull,
0x3030666637643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x746573090a666e69ull,
0x3436662e71652e70ull,0x202c373470250920ull,0x202c373632646625ull,0x093b313033646625ull,
0x252140090a202f2full,0x2061726220373470ull,0x375f335f744c2409ull,0x2020203b34333036ull,
0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x090a34333639365full,0x203436662e766f6dull,0x2c37303164662509ull,0x3b37363264662520ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x3b303530325f335full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3036375f335f744cull,0x3c2f2f200a3a3433ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,0x2e766f6d090a3433ull,
0x6466250920343666ull,0x666430202c373031ull,0x3030303030386666ull,0x3b30303030303030ull,
0x0a6e616e202f2f09ull,0x30325f335f744c24ull,0x3c2f2f200a3a3035ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3639365f335f744cull,0x636f6c2e090a3433ull,0x0938323109383109ull,
0x662e766f6d090a30ull,0x3264662509203436ull,0x3031646625202c37ull,0x2020202020203b37ull,
0x62090a202f2f0920ull,0x0920696e752e6172ull,0x30375f335f744c24ull,0x202020203b343139ull,
0x2f2f092020202020ull,0x5f335f744c240a20ull,0x200a3a3037313137ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3433363936ull,0x3509383209636f6cull,
0x6f6d090a30093534ull,0x7b09203436622e76ull,0x72252c3039317225ull,0x6625202c7d313931ull,
0x2f2f093b35303264ull,0x732e766f6d090a20ull,0x3831722509203233ull,0x3b3139317225202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,0x6f6d090a30093634ull,
0x7b09203436622e76ull,0x3172252c39317225ull,0x646625202c7d3239ull,0x202f2f093b353032ull,
0x3209636f6c2e090aull,0x0a30093834350938ull,0x3436662e766f6d09ull,0x3230336466250920ull,
0x303030306430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x2e746573090a3020ull,
0x662e3233752e7467ull,0x3931722509203436ull,0x3032646625202c33ull,0x3033646625202c35ull,
0x090a202f2f093b32ull,0x203233732e67656eull,0x202c343931722509ull,0x20203b3339317225ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x6466250920343666ull,0x376430202c333033ull,
0x3030303030306666ull,0x3b30303030303030ull,0x0a666e69202f2f09ull,0x2e746c2e74657309ull,
0x203436662e323375ull,0x202c353931722509ull,0x202c353032646625ull,0x093b333033646625ull,
0x67656e090a202f2full,0x722509203233732eull,0x317225202c363931ull,0x20202020203b3539ull,
0x0a202f2f09202020ull,0x3233622e646e6109ull,0x2c37393172250920ull,0x202c343931722520ull,
0x09203b3639317225ull,0x766f6d090a202f2full,0x722509203233752eull,0x203b30202c383931ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,
0x39317225202c3834ull,0x3839317225202c37ull,0x40090a202f2f093bull,0x6172622038347025ull,
0x5f335f744c240920ull,0x20203b3433343035ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,0x33752e766f6d090aull,
0x3939317225092032ull,0x373538343031202cull,0x2020202020203b35ull,0x6573090a202f2f09ull,
0x33752e74672e7074ull,0x2c39347025092032ull,0x202c313931722520ull,0x2f093b3939317225ull,
0x34702540090a202full,0x2409206172622039ull,0x3836375f335f744cull,0x20202020203b3230ull,
0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x2e090a3433363936ull,0x3509383209636f6cull,0x6f6d090a30093435ull,0x2509203436662e76ull,
0x30202c3430336466ull,0x3030303035333464ull,0x3030303030303030ull,0x2e31202f2f093b30ull,
0x312b653434313038ull,0x662e6c756d090a36ull,0x3364662509203436ull,0x32646625202c3530ull,
0x33646625202c3530ull,0x0a202f2f093b3430ull,0x3436622e766f6d09ull,0x30303272257b0920ull,
0x202c7d383172252cull,0x093b353033646625ull,0x6f6c2e090a202f2full,0x3535350938320963ull,
0x2e766f6d090a3009ull,0x72257b0920343662ull,0x31303272252c3931ull,0x3033646625202c7dull,
0x090a202f2f093b35ull,0x203233732e766f6dull,0x2d202c3033722509ull,0x2020203b37373031ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x36343536375f335full,
0x202020202020203bull,0x240a202f2f092020ull,0x3836375f335f744cull,0x3c2f2f200a3a3230ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,0x2e766f6d090a3433ull,
0x3372250920323373ull,0x333230312d202c30ull,0x202020202020203bull,0x240a202f2f092020ull,
0x3536375f335f744cull,0x3c2f2f200a3a3634ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3639365f335f744cull,0x636f6c2e090a3433ull,0x0930363509383209ull,0x732e726873090a30ull,
0x3032722509203233ull,0x2c38317225202c32ull,0x202020203b303220ull,0x61090a202f2f0920ull,
0x09203233622e646eull,0x25202c3330327225ull,0x3032202c32303272ull,0x2f2f0920203b3734ull,
0x732e646461090a20ull,0x3033722509203233ull,0x202c30337225202cull,0x20203b3330327225ull,
0x2e090a202f2f0920ull,0x3509383209636f6cull,0x6e61090a30093236ull,0x2509203233622e64ull,
0x317225202c333372ull,0x363431322d202c38ull,0x093b333730353334ull,0x2e726f090a202f2full,
0x3372250920323362ull,0x2c33337225202c34ull,0x3339363237303120ull,0x202f2f093b383432ull,
0x36622e766f6d090aull,0x3533646625092034ull,0x2c393172257b202cull,0x20203b7d34337225ull,
0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x3031202c34303272ull,0x3238353732313337ull,
0x202f2f092020203bull,0x6c2e70746573090aull,0x2509203233752e65ull,0x337225202c303570ull,
0x3430327225202c34ull,0x40090a202f2f093bull,0x6172622030357025ull,0x5f335f744c240920ull,
0x20203b3835303737ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34333639365f335full,0x3209636f6c2e090aull,0x0a30093436350938ull,
0x3436622e766f6d09ull,0x35303272257b0920ull,0x2c7d36303272252cull,0x093b353364662520ull,
0x627573090a202f2full,0x722509203233732eull,0x327225202c373032ull,0x38343031202c3630ull,
0x202f2f093b363735ull,0x36622e766f6d090aull,0x303272257b092034ull,0x7d39303272252c38ull,
0x3b3533646625202cull,0x6f6d090a202f2f09ull,0x2509203436622e76ull,0x257b202c35336466ull,
0x3272252c38303272ull,0x202f2f093b7d3730ull,0x3209636f6c2e090aull,0x0a30093536350938ull,
0x3233732e64646109ull,0x202c303372250920ull,0x3b31202c30337225ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x3a38353037375f33ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3936322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a34333639365f33ull,0x383209636f6c2e09ull,0x090a300939373509ull,
0x203436662e766f6dull,0x2c36303364662509ull,0x3030666662643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x2e646461090a312dull,0x6466250920343666ull,0x33646625202c3733ull,
0x3033646625202c35ull,0x090a202f2f093b36ull,0x203436662e766f6dull,0x2c37303364662509ull,
0x3030666633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x662e646461090a31ull,
0x3364662509203436ull,0x33646625202c3830ull,0x3033646625202c35ull,0x090a202f2f093b37ull,
0x662e6e722e706372ull,0x3464662509203436ull,0x3033646625202c30ull,0x2f09202020203b38ull,
0x2e6c756d090a202full,0x6466250920343666ull,0x33646625202c3134ull,0x3034646625202c37ull,
0x090a202f2f09203bull,0x203436662e646461ull,0x202c323464662509ull,0x25202c3134646625ull,
0x2f09203b31346466ull,0x2e6c756d090a202full,0x6466250920343666ull,0x34646625202c3334ull,
0x3234646625202c32ull,0x090a202f2f09203bull,0x203436662e766f6dull,0x2c39303364662509ull,
0x3331626533643020ull,0x3038656133623038ull,0x202f2f093b653166ull,0x6533333632302e31ull,
0x766f6d090a36302dull,0x662509203436662eull,0x6430202c30313364ull,0x3532656530646533ull,
0x3430623861376238ull,0x302e34202f2f093bull,0x36302d6539343633ull,0x6e722e64616d090aull,
0x662509203436662eull,0x6625202c31313364ull,0x6625202c39303364ull,0x646625202c333464ull,
0x202f2f093b303133ull,0x36662e766f6d090aull,0x3133646625092034ull,0x6665336430202c32ull,
0x3066393636326233ull,0x2f093b6636373632ull,0x343837382e31202full,0x6d090a35302d6534ull,
0x36662e6e722e6461ull,0x3133646625092034ull,0x3133646625202c33ull,0x3334646625202c31ull,
0x323133646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,0x202c343133646625ull,
0x3534373166336430ull,0x3930626139616263ull,0x38202f2f093b3635ull,0x2d6531383737382eull,
0x2e64616d090a3530ull,0x09203436662e6e72ull,0x202c353133646625ull,0x202c333133646625ull,
0x25202c3334646625ull,0x2f093b3431336466ull,0x2e766f6d090a202full,0x6466250920343666ull,
0x336430202c363133ull,0x3237633137633366ull,0x3b34353135623164ull,0x30302e30202f2f09ull,
0x0a38323034333430ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x33646625202c3235ull,
0x34646625202c3531ull,0x3133646625202c33ull,0x090a202f2f093b36ull,0x09383209636f6c2eull,
0x6d090a3009303835ull,0x09203436662e766full,0x202c373133646625ull,0x3934323666336430ull,
0x3765623332393432ull,0x30202f2f093b6432ull,0x313233323230302eull,0x722e64616d090a34ull,
0x2509203436662e6eull,0x6625202c32356466ull,0x646625202c323564ull,0x33646625202c3334ull,
0x0a202f2f093b3731ull,0x383209636f6c2e09ull,0x090a300931383509ull,0x203436662e766f6dull,
0x2c38313364662509ull,0x3939386633643020ull,0x6139393939393939ull,0x202f2f093b346333ull,
0x090a353231302e30ull,0x662e6e722e64616dull,0x3564662509203436ull,0x3235646625202c32ull,
0x2c3334646625202cull,0x3b38313364662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,
0x766f6d090a300932ull,0x662509203436662eull,0x6430202c39313364ull,0x3535353535626633ull,
0x3435353535353535ull,0x302e30202f2f093bull,0x090a333333333338ull,0x662e6e722e64616dull,
0x3564662509203436ull,0x3235646625202c32ull,0x2c3334646625202cull,0x3b39313364662520ull,
0x6c2e090a202f2f09ull,0x383509383209636full,0x627573090a300934ull,0x662509203436662eull,
0x646625202c363564ull,0x34646625202c3733ull,0x0a202f2f09203b32ull,0x3436662e67656e09ull,
0x3032336466250920ull,0x3b3234646625202cull,0x0920202020202020ull,0x766f6d090a202f2full,
0x257b09203436622eull,0x3272252c30313272ull,0x646625202c7d3131ull,0x0a202f2f093b3635ull,
0x3233732e64646109ull,0x2c32313272250920ull,0x202c313132722520ull,0x3b36373538343031ull,
0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x72252c3331327225ull,0x6625202c7d343132ull,
0x202f2f093b363564ull,0x36622e766f6d090aull,0x3233646625092034ull,0x313272257b202c31ull,
0x7d32313272252c33ull,0x6d090a202f2f093bull,0x36662e6e722e6461ull,0x3935646625092034ull,
0x303233646625202cull,0x2c3733646625202cull,0x3b31323364662520ull,0x6c2e090a202f2f09ull,
0x383509383209636full,0x6c756d090a300938ull,0x662509203436662eull,0x6625202c32323364ull,
0x646625202c333464ull,0x0a202f2f093b3235ull,0x3436662e6c756d09ull,0x2c32356466250920ull,
0x202c323464662520ull,0x093b323233646625ull,0x6f6c2e090a202f2full,0x3839350938320963ull,
0x2e747663090a3009ull,0x732e3436662e6e72ull,0x3664662509203233ull,0x3b30337225202c31ull,
0x090a202f2f092020ull,0x203436662e766f6dull,0x2c33323364662509ull,0x3236656633643020ull,
0x3361666566323465ull,0x202f2f093b666539ull,0x3734313339362e30ull,0x6e722e64616d090aull,
0x662509203436662eull,0x646625202c333664ull,0x33646625202c3136ull,0x34646625202c3332ull,
0x090a202f2f093b32ull,0x203436662e766f6dull,0x2c34323364662509ull,0x6261376333643020ull,
0x3839336233653963ull,0x202f2f093b663330ull,0x6535303931332e32ull,0x64616d090a37312dull,
0x203436662e6e722eull,0x2c35323364662509ull,0x202c393564662520ull,0x25202c3034646625ull,
0x2f2f093b32356466ull,0x732e67656e090a20ull,0x3132722509203233ull,0x3b30337225202c35ull,
0x2020202020202020ull,0x63090a202f2f0920ull,0x36662e6e722e7476ull,0x2509203233732e34ull,
0x25202c3632336466ull,0x2f2f093b35313272ull,0x662e766f6d090a20ull,0x3364662509203436ull,
0x66336430202c3732ull,0x6566323465323665ull,0x093b666539336166ull,0x3339362e30202f2full,
0x64616d090a373431ull,0x203436662e6e722eull,0x2c38323364662509ull,0x2c36323364662520ull,
0x2c37323364662520ull,0x093b333664662520ull,0x627573090a202f2full,0x662509203436662eull,
0x6625202c39323364ull,0x6625202c38323364ull,0x202f2f093b323464ull,0x36662e627573090aull,
0x3333646625092034ull,0x3233646625202c30ull,0x3233646625202c35ull,0x090a202f2f093b39ull,
0x662e6e722e64616dull,0x3764662509203436ull,0x3136646625202c31ull,0x343233646625202cull,
0x303333646625202cull,0x61090a202f2f093bull,0x09203436662e6464ull,0x202c323431646625ull,
0x25202c3336646625ull,0x2f2f093b31376466ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x20203b3431355f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x333430355f335f74ull,
0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333639365f335f74ull,
0x09636f6c2e090a34ull,0x3009313036093832ull,0x36662e736261090aull,0x3333646625092034ull,
0x3032646625202c31ull,0x2020202020203b35ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,
0x30202c3233336466ull,0x3030303066663764ull,0x3030303030303030ull,0x6e69202f2f093b30ull,
0x2e70746573090a66ull,0x09203436662e656cull,0x6625202c31357025ull,0x6625202c31333364ull,
0x2f2f093b32333364ull,0x3135702540090a20ull,0x4c24092061726220ull,0x373537375f335f74ull,
0x2020202020203b30ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,
0x365f335f744c2420ull,0x6461090a34333639ull,0x2509203436662e64ull,0x25202c3234316466ull,
0x25202c3530326466ull,0x2f093b3530326466ull,0x2e617262090a202full,0x744c240920696e75ull,
0x203b3431355f335full,0x2020202020202020ull,0x240a202f2f092020ull,0x3537375f335f744cull,
0x3c2f2f200a3a3037ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,
0x2e766f6d090a3433ull,0x6466250920343666ull,0x306430202c333333ull,0x3030303030303030ull,
0x3b30303030303030ull,0x73090a30202f2f09ull,0x662e71652e707465ull,0x3235702509203436ull,
0x353032646625202cull,0x333333646625202cull,0x40090a202f2f093bull,0x7262203235702521ull,
0x335f744c24092061ull,0x203b32383038375full,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,0x36662e766f6d090aull,
0x3431646625092034ull,0x6666666430202c32ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x090a666e692d202full,0x20696e752e617262ull,0x355f335f744c2409ull,0x20202020203b3431ull,
0x2f09202020202020ull,0x335f744c240a202full,0x0a3a32383038375full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a34333639365full,0x203436662e766f6dull,
0x2c34333364662509ull,0x3030666637643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x746573090a666e69ull,0x3436662e71652e70ull,0x202c333570250920ull,0x202c353032646625ull,
0x093b343333646625ull,0x252140090a202f2full,0x2061726220333570ull,0x375f335f744c2409ull,
0x2020203b34393538ull,0x0a202f2f09202020ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a34333639365full,0x203436662e766f6dull,0x2c32343164662509ull,
0x3b35303264662520ull,0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,
0x203b3431355f335full,0x2020202020202020ull,0x240a202f2f092020ull,0x3538375f335f744cull,
0x3c2f2f200a3a3439ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,
0x2e766f6d090a3433ull,0x6466250920343666ull,0x666430202c323431ull,0x3030303030386666ull,
0x3b30303030303030ull,0x0a6e616e202f2f09ull,0x31355f335f744c24ull,0x6c3c2f2f200a3a34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c39363220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333639365f335f74ull,0x09636f6c2e090a34ull,
0x3009353435093832ull,0x36662e67656e090aull,0x3333646625092034ull,0x3431646625202c35ull,
0x2020202020203b32ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x72252c3631327225ull,
0x6625202c7d373132ull,0x2f2f093b35333364ull,0x732e766f6d090a20ull,0x3831722509203233ull,
0x3b3731327225202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,
0x6f6d090a30093634ull,0x7b09203436622e76ull,0x3272252c39317225ull,0x646625202c7d3831ull,
0x202f2f093b353333ull,0x3209636f6c2e090aull,0x0a30093834350938ull,0x3436662e766f6d09ull,
0x3633336466250920ull,0x303030306430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,
0x2e746573090a3020ull,0x662e3233752e7467ull,0x3132722509203436ull,0x3333646625202c39ull,
0x3333646625202c35ull,0x090a202f2f093b36ull,0x203233732e67656eull,0x202c303232722509ull,
0x20203b3931327225ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x6466250920343666ull,
0x376430202c373333ull,0x3030303030306666ull,0x3b30303030303030ull,0x0a666e69202f2f09ull,
0x2e746c2e74657309ull,0x203436662e323375ull,0x202c313232722509ull,0x202c353333646625ull,
0x093b373333646625ull,0x67656e090a202f2full,0x722509203233732eull,0x327225202c323232ull,
0x20202020203b3132ull,0x0a202f2f09202020ull,0x3233622e646e6109ull,0x2c33323272250920ull,
0x202c303232722520ull,0x09203b3232327225ull,0x766f6d090a202f2full,0x722509203233752eull,
0x203b30202c343232ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x71652e7074657309ull,
0x702509203233732eull,0x32327225202c3435ull,0x3432327225202c33ull,0x40090a202f2f093bull,
0x6172622034357025ull,0x5f335f744c240920ull,0x20203b3037393135ull,0x2f2f092020202020ull,
0x6f6c3c2f2f200a20ull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c39363220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,
0x33752e766f6d090aull,0x3532327225092032ull,0x373538343031202cull,0x2020202020203b35ull,
0x6573090a202f2f09ull,0x33752e74672e7074ull,0x2c35357025092032ull,0x202c373132722520ull,
0x2f093b3532327225ull,0x35702540090a202full,0x2409206172622035ull,0x3339375f335f744cull,
0x20202020203b3236ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x2e090a3433363936ull,0x3509383209636f6cull,0x6f6d090a30093435ull,
0x2509203436662e76ull,0x30202c3833336466ull,0x3030303035333464ull,0x3030303030303030ull,
0x2e31202f2f093b30ull,0x312b653434313038ull,0x662e6c756d090a36ull,0x3364662509203436ull,
0x33646625202c3933ull,0x33646625202c3533ull,0x0a202f2f093b3833ull,0x3436622e766f6d09ull,
0x36323272257b0920ull,0x202c7d383172252cull,0x093b393333646625ull,0x6f6c2e090a202f2full,
0x3535350938320963ull,0x2e766f6d090a3009ull,0x72257b0920343662ull,0x37323272252c3931ull,
0x3333646625202c7dull,0x090a202f2f093b39ull,0x203233732e766f6dull,0x2d202c3033722509ull,
0x2020203b37373031ull,0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,
0x36303139375f335full,0x202020202020203bull,0x240a202f2f092020ull,0x3339375f335f744cull,
0x3c2f2f200a3a3236ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,
0x2e766f6d090a3433ull,0x3372250920323373ull,0x333230312d202c30ull,0x202020202020203bull,
0x240a202f2f092020ull,0x3139375f335f744cull,0x3c2f2f200a3a3630ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3639365f335f744cull,0x636f6c2e090a3433ull,0x0930363509383209ull,
0x732e726873090a30ull,0x3232722509203233ull,0x2c38317225202c38ull,0x202020203b303220ull,
0x61090a202f2f0920ull,0x09203233622e646eull,0x25202c3932327225ull,0x3032202c38323272ull,
0x2f2f0920203b3734ull,0x732e646461090a20ull,0x3033722509203233ull,0x202c30337225202cull,
0x20203b3932327225ull,0x2e090a202f2f0920ull,0x3509383209636f6cull,0x6e61090a30093236ull,
0x2509203233622e64ull,0x317225202c333372ull,0x363431322d202c38ull,0x093b333730353334ull,
0x2e726f090a202f2full,0x3372250920323362ull,0x2c33337225202c34ull,0x3339363237303120ull,
0x202f2f093b383432ull,0x36622e766f6d090aull,0x3533646625092034ull,0x2c393172257b202cull,
0x20203b7d34337225ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x3031202c30333272ull,
0x3238353732313337ull,0x202f2f092020203bull,0x6c2e70746573090aull,0x2509203233752e65ull,
0x337225202c363570ull,0x3033327225202c34ull,0x40090a202f2f093bull,0x6172622036357025ull,
0x5f335f744c240920ull,0x20203b3831363937ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39363220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34333639365f335full,0x3209636f6c2e090aull,
0x0a30093436350938ull,0x3436622e766f6d09ull,0x31333272257b0920ull,0x2c7d32333272252cull,
0x093b353364662520ull,0x627573090a202f2full,0x722509203233732eull,0x327225202c333332ull,
0x38343031202c3233ull,0x202f2f093b363735ull,0x36622e766f6d090aull,0x333272257b092034ull,
0x7d35333272252c34ull,0x3b3533646625202cull,0x6f6d090a202f2f09ull,0x2509203436622e76ull,
0x257b202c35336466ull,0x3272252c34333272ull,0x202f2f093b7d3333ull,0x3209636f6c2e090aull,
0x0a30093536350938ull,0x3233732e64646109ull,0x202c303372250920ull,0x3b31202c30337225ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x3a38313639375f33ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3936322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34333639365f33ull,0x383209636f6c2e09ull,
0x090a300939373509ull,0x203436662e766f6dull,0x2c30343364662509ull,0x3030666662643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x2e646461090a312dull,0x6466250920343666ull,
0x33646625202c3733ull,0x3433646625202c35ull,0x090a202f2f093b30ull,0x203436662e766f6dull,
0x2c31343364662509ull,0x3030666633643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x662e646461090a31ull,0x3364662509203436ull,0x33646625202c3234ull,0x3433646625202c35ull,
0x090a202f2f093b31ull,0x662e6e722e706372ull,0x3464662509203436ull,0x3433646625202c30ull,
0x2f09202020203b32ull,0x2e6c756d090a202full,0x6466250920343666ull,0x33646625202c3134ull,
0x3034646625202c37ull,0x090a202f2f09203bull,0x203436662e646461ull,0x202c323464662509ull,
0x25202c3134646625ull,0x2f09203b31346466ull,0x2e6c756d090a202full,0x6466250920343666ull,
0x34646625202c3334ull,0x3234646625202c32ull,0x090a202f2f09203bull,0x203436662e766f6dull,
0x2c33343364662509ull,0x3331626533643020ull,0x3038656133623038ull,0x202f2f093b653166ull,
0x6533333632302e31ull,0x766f6d090a36302dull,0x662509203436662eull,0x6430202c34343364ull,
0x3532656530646533ull,0x3430623861376238ull,0x302e34202f2f093bull,0x36302d6539343633ull,
0x6e722e64616d090aull,0x662509203436662eull,0x6625202c35343364ull,0x6625202c33343364ull,
0x646625202c333464ull,0x202f2f093b343433ull,0x36662e766f6d090aull,0x3433646625092034ull,
0x6665336430202c36ull,0x3066393636326233ull,0x2f093b6636373632ull,0x343837382e31202full,
0x6d090a35302d6534ull,0x36662e6e722e6461ull,0x3433646625092034ull,0x3433646625202c37ull,
0x3334646625202c35ull,0x363433646625202cull,0x6d090a202f2f093bull,0x09203436662e766full,
0x202c383433646625ull,0x3534373166336430ull,0x3930626139616263ull,0x38202f2f093b3635ull,
0x2d6531383737382eull,0x2e64616d090a3530ull,0x09203436662e6e72ull,0x202c393433646625ull,
0x202c373433646625ull,0x25202c3334646625ull,0x2f093b3834336466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x336430202c303533ull,0x3237633137633366ull,0x3b34353135623164ull,
0x30302e30202f2f09ull,0x0a38323034333430ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x33646625202c3235ull,0x34646625202c3934ull,0x3533646625202c33ull,0x090a202f2f093b30ull,
0x09383209636f6c2eull,0x6d090a3009303835ull,0x09203436662e766full,0x202c313533646625ull,
0x3934323666336430ull,0x3765623332393432ull,0x30202f2f093b6432ull,0x313233323230302eull,
0x722e64616d090a34ull,0x2509203436662e6eull,0x6625202c32356466ull,0x646625202c323564ull,
0x33646625202c3334ull,0x0a202f2f093b3135ull,0x383209636f6c2e09ull,0x090a300931383509ull,
0x203436662e766f6dull,0x2c32353364662509ull,0x3939386633643020ull,0x6139393939393939ull,
0x202f2f093b346333ull,0x090a353231302e30ull,0x662e6e722e64616dull,0x3564662509203436ull,
0x3235646625202c32ull,0x2c3334646625202cull,0x3b32353364662520ull,0x6c2e090a202f2f09ull,
0x383509383209636full,0x766f6d090a300932ull,0x662509203436662eull,0x6430202c33353364ull,
0x3535353535626633ull,0x3435353535353535ull,0x302e30202f2f093bull,0x090a333333333338ull,
0x662e6e722e64616dull,0x3564662509203436ull,0x3235646625202c32ull,0x2c3334646625202cull,
0x3b33353364662520ull,0x6c2e090a202f2f09ull,0x383509383209636full,0x627573090a300934ull,
0x662509203436662eull,0x646625202c363564ull,0x34646625202c3733ull,0x0a202f2f09203b32ull,
0x3436662e67656e09ull,0x3435336466250920ull,0x3b3234646625202cull,0x0920202020202020ull,
0x766f6d090a202f2full,0x257b09203436622eull,0x3272252c36333272ull,0x646625202c7d3733ull,
0x0a202f2f093b3635ull,0x3233732e64646109ull,0x2c38333272250920ull,0x202c373332722520ull,
0x3b36373538343031ull,0x6f6d090a202f2f09ull,0x7b09203436622e76ull,0x72252c3933327225ull,
0x6625202c7d303432ull,0x202f2f093b363564ull,0x36622e766f6d090aull,0x3533646625092034ull,
0x333272257b202c35ull,0x7d38333272252c39ull,0x6d090a202f2f093bull,0x36662e6e722e6461ull,
0x3935646625092034ull,0x343533646625202cull,0x2c3733646625202cull,0x3b35353364662520ull,
0x6c2e090a202f2f09ull,0x383509383209636full,0x6c756d090a300938ull,0x662509203436662eull,
0x6625202c36353364ull,0x646625202c333464ull,0x0a202f2f093b3235ull,0x3436662e6c756d09ull,
0x2c32356466250920ull,0x202c323464662520ull,0x093b363533646625ull,0x6f6c2e090a202f2full,
0x3839350938320963ull,0x2e747663090a3009ull,0x732e3436662e6e72ull,0x3664662509203233ull,
0x3b30337225202c31ull,0x090a202f2f092020ull,0x203436662e766f6dull,0x2c37353364662509ull,
0x3236656633643020ull,0x3361666566323465ull,0x202f2f093b666539ull,0x3734313339362e30ull,
0x6e722e64616d090aull,0x662509203436662eull,0x646625202c333664ull,0x33646625202c3136ull,
0x34646625202c3735ull,0x090a202f2f093b32ull,0x203436662e766f6dull,0x2c38353364662509ull,
0x6261376333643020ull,0x3839336233653963ull,0x202f2f093b663330ull,0x6535303931332e32ull,
0x64616d090a37312dull,0x203436662e6e722eull,0x2c39353364662509ull,0x202c393564662520ull,
0x25202c3034646625ull,0x2f2f093b32356466ull,0x732e67656e090a20ull,0x3432722509203233ull,
0x3b30337225202c31ull,0x2020202020202020ull,0x63090a202f2f0920ull,0x36662e6e722e7476ull,
0x2509203233732e34ull,0x25202c3036336466ull,0x2f2f093b31343272ull,0x662e766f6d090a20ull,
0x3364662509203436ull,0x66336430202c3136ull,0x6566323465323665ull,0x093b666539336166ull,
0x3339362e30202f2full,0x64616d090a373431ull,0x203436662e6e722eull,0x2c32363364662509ull,
0x2c30363364662520ull,0x2c31363364662520ull,0x093b333664662520ull,0x627573090a202f2full,
0x662509203436662eull,0x6625202c33363364ull,0x6625202c32363364ull,0x202f2f093b323464ull,
0x36662e627573090aull,0x3633646625092034ull,0x3533646625202c34ull,0x3633646625202c39ull,
0x090a202f2f093b33ull,0x662e6e722e64616dull,0x3764662509203436ull,0x3136646625202c31ull,
0x383533646625202cull,0x343633646625202cull,0x61090a202f2f093bull,0x09203436662e6464ull,
0x202c373731646625ull,0x25202c3336646625ull,0x2f2f093b31376466ull,0x752e617262090a20ull,
0x5f744c240920696eull,0x203b363230315f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x373931355f335f74ull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333639365f335f74ull,0x09636f6c2e090a34ull,0x3009313036093832ull,0x36662e736261090aull,
0x3633646625092034ull,0x3431646625202c35ull,0x2020202020203b32ull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x30202c3636336466ull,0x3030303066663764ull,0x3030303030303030ull,
0x6e69202f2f093b30ull,0x2e70746573090a66ull,0x09203436662e656cull,0x6625202c37357025ull,
0x6625202c35363364ull,0x2f2f093b36363364ull,0x3735702540090a20ull,0x4c24092061726220ull,
0x333130385f335f74ull,0x2020202020203b30ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3936ull,
0x64656c6562616c20ull,0x365f335f744c2420ull,0x6461090a34333639ull,0x2509203436662e64ull,
0x25202c3736336466ull,0x25202c3234316466ull,0x2f093b3234316466ull,0x2e67656e090a202full,
0x6466250920343666ull,0x646625202c373731ull,0x202020203b373633ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x315f335f744c2409ull,0x202020203b363230ull,0x2f09202020202020ull,
0x335f744c240a202full,0x0a3a30333130385full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a34333639365full,0x203436662e766f6dull,0x2c38363364662509ull,
0x3030303030643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a30ull,
0x09203436662e7165ull,0x6625202c38357025ull,0x6625202c35333364ull,0x2f2f093b38363364ull,
0x3570252140090a20ull,0x2409206172622038ull,0x3630385f335f744cull,0x20202020203b3234ull,
0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3936ull,0x64656c6562616c20ull,0x365f335f744c2420ull,
0x6f6d090a34333639ull,0x2509203436662e76ull,0x30202c3737316466ull,0x3030303066666664ull,
0x3030303030303030ull,0x692d202f2f093b30ull,0x2e617262090a666eull,0x744c240920696e75ull,
0x3b363230315f335full,0x2020202020202020ull,0x240a202f2f092020ull,0x3630385f335f744cull,
0x3c2f2f200a3a3234ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x39363220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,
0x2e766f6d090a3433ull,0x6466250920343666ull,0x376430202c393633ull,0x3030303030306666ull,
0x3b30303030303030ull,0x0a666e69202f2f09ull,0x71652e7074657309ull,0x702509203436662eull,
0x33646625202c3935ull,0x33646625202c3533ull,0x0a202f2f093b3936ull,0x2039357025214009ull,
0x744c240920617262ull,0x34353131385f335full,0x092020202020203bull,0x3c2f2f200a202f2full,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39363220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3639365f335f744cull,0x2e766f6d090a3433ull,
0x6466250920343666ull,0x646625202c373731ull,0x202020203b353333ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x315f335f744c2409ull,0x202020203b363230ull,0x2f09202020202020ull,
0x335f744c240a202full,0x0a3a34353131385full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a34333639365full,0x203436662e766f6dull,0x2c37373164662509ull,
0x3038666666643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x5f744c240a6e616eull,
0x0a3a363230315f33ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c39363220ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x090a34333639365full,0x09383109636f6c2eull,0x6d090a3009303331ull,0x09203436662e766full,
0x25202c3732646625ull,0x20203b3737316466ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,
0x200a3a3431393037ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c393632ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x2e090a3433363936ull,0x3109383109636f6cull,0x6f6d090a30093233ull,0x2509203436662e76ull,
0x30202c3037336466ull,0x3339393564663364ull,0x3633303465336332ull,0x2e30202f2f093b64ull,
0x090a353734373333ull,0x203436662e766f6dull,0x2c31373364662509ull,0x3366656633643020ull,
0x6362386663366363ull,0x202f2f093b313331ull,0x3936313637392e30ull,0x36662e766f6d090aull,
0x3733646625092034ull,0x6366336430202c32ull,0x3636323730353934ull,0x2f093b3638363039ull,
0x373036312e30202full,0x2e766f6d090a3839ull,0x6466250920343666ull,0x336430202c333733ull,
0x3764616534633966ull,0x3b37333234346533ull,0x32302e30202f2f09ull,0x6d090a3933343637ull,
0x09203436662e766full,0x202c343733646625ull,0x3637663666336430ull,0x3736653335653334ull,
0x30202f2f093b3538ull,0x353034383330302eull,0x662e766f6d090a37ull,0x3364662509203436ull,
0x66336430202c3537ull,0x3061653236653933ull,0x093b363438383961ull,0x3030302e30202f2full,
0x6d090a3931353933ull,0x09203436662e766full,0x202c363733646625ull,0x6564303066336430ull,
0x3238356635303262ull,0x33202f2f093b3830ull,0x2d6538363731322eull,0x2e766f6d090a3530ull,
0x6466250920343666ull,0x336430202c373733ull,0x3735643136333965ull,0x3b36356237623930ull,
0x38382e32202f2f09ull,0x0a37302d65373138ull,0x3436662e766f6d09ull,0x3837336466250920ull,
0x613965336430202cull,0x3230613035633339ull,0x2f2f093b64613564ull,0x32333036392e3320ull,
0x616d090a37302d65ull,0x3436662e6e722e64ull,0x3937336466250920ull,0x383733646625202cull,
0x2c3732646625202cull,0x3b37373364662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x3038336466250920ull,0x2c3732646625202cull,0x2c39373364662520ull,0x3b36373364662520ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x3138336466250920ull,0x2c3732646625202cull,
0x2c30383364662520ull,0x3b35373364662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x3238336466250920ull,0x2c3732646625202cull,0x2c31383364662520ull,0x3b34373364662520ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x3338336466250920ull,0x2c3732646625202cull,
0x2c32383364662520ull,0x3b33373364662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x3438336466250920ull,0x2c3732646625202cull,0x2c33383364662520ull,0x3b32373364662520ull,
0x616d090a202f2f09ull,0x3436662e6e722e64ull,0x3538336466250920ull,0x2c3732646625202cull,
0x2c34383364662520ull,0x3b31373364662520ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x3638336466250920ull,0x2c3732646625202cull,0x2c35383364662520ull,0x3b30373364662520ull,
0x656e090a202f2f09ull,0x2509203436662e67ull,0x25202c3738336466ull,0x20203b3638336466ull,
0x202f2f0920202020ull,0x36662e766f6d090aull,0x3833646625092034ull,0x3030306430202c38ull,
0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a30202full,0x3436662e746c2e70ull,
0x202c303670250920ull,0x202c303132646625ull,0x093b383833646625ull,0x6c6573090a202f2full,
0x2509203436662e70ull,0x6625202c37326466ull,0x6625202c37383364ull,0x7025202c36383364ull,
0x0a202f2f093b3036ull,0x30375f335f744c24ull,0x2f2f200a3a323034ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x363220656e696c20ull,0x2064616568202c39ull,
0x2064656c6562616cull,0x39365f335f744c24ull,0x766f6d090a343336ull,0x662509203436662eull,
0x6625202c38303264ull,0x202020203b373264ull,0x0a202f2f09202020ull,0x35325f335f744c24ull,
0x6c3c2f2f200a3a38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c39363220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x333639365f335f74ull,
0x09636f6c2e090a34ull,0x3009393632093831ull,0x6e722e747663090aull,0x3436662e3233662eull,
0x25202c3366250920ull,0x20203b3830326466ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,
0x72255b0920323366ull,0x202c5d302b343164ull,0x202f2f093b336625ull,0x0a323530313a6469ull,
0x3233752e64646109ull,0x2c37323172250920ull,0x202c393231722520ull,0x09203b3732317225ull,
0x646461090a202f2full,0x722509203436752eull,0x647225202c343164ull,0x31647225202c3431ull,
0x0a202f2f09203b35ull,0x746c2e7074657309ull,0x702509203233752eull,0x32317225202c3136ull,
0x093b317225202c37ull,0x702540090a202f2full,0x0920617262203136ull,0x39365f335f744c24ull,
0x202020203b343336ull,0x0a202f2f09202020ull,0x39365f335f744c24ull,0x744c240a3a323231ull,
0x30313835355f335full,0x09636f6c2e090a3aull,0x3009323732093831ull,0x203b74697865090aull,
0x2020202020202020ull,0x2020202020202020ull,0x2020202020202020ull,0x444c240a202f2f09ull,
0x315a5f5f646e6557ull,0x65737265766e6936ull,0x656e72654b444e43ull,0x0a3a6a5f5366506cull,
0x5a5f202f2f207d09ull,0x737265766e693631ull,0x6e72654b444e4365ull,0x0a6a5f5366506c65ull,
0x000000000000000aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"40fad8063431ac3c",(char*)"MonteCarlo_SM13.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0,0x31b79e74};
# 5 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 2
# 1 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 1
# 85 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/cuda/bin/../include/host_defines.h" 1
# 86 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2
# 111 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
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
# 226 "/home/normal/cuda/bin/../include/crt/host_runtime.h"
# 1 "/home/normal/cuda/bin/../include/common_functions.h" 1
# 68 "/home/normal/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/home/normal/cuda/bin/../include/common_functions.h" 2

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
# 93 "/home/normal/cuda/bin/../include/common_functions.h"
# 1 "/home/normal/cuda/bin/../include/math_functions.h" 1 3
# 864 "/home/normal/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) int __cuda_error_not_implememted(void); int __cuda_error_not_implememted(void);
# 920 "/home/normal/cuda/bin/../include/math_functions.h" 3
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

# 1 "/home/normal/cuda/bin/../include/device_functions.h" 1 3
# 426 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/math_constants.h" 1 3
# 427 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 2367 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/common_types.h" 1 3
# 37 "/home/normal/cuda/bin/../include/common_types.h" 3
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
# 2368 "/home/normal/cuda/bin/../include/device_functions.h" 2 3

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
# 3148 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 3737 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4518 "/home/normal/cuda/bin/../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4537 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4573 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4812 "/home/normal/cuda/bin/../include/device_functions.h" 3
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
# 4856 "/home/normal/cuda/bin/../include/device_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 257 "/home/normal/cuda/bin/../include/sm_11_atomic_functions.h" 3
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
# 4857 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 118 "/home/normal/cuda/bin/../include/sm_12_atomic_functions.h" 3
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
# 4858 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 267 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 656 "/home/normal/cuda/bin/../include/sm_13_double_functions.h" 3
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
# 4859 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 1 "/home/normal/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1910 "/home/normal/cuda/bin/../include/texture_fetch_functions.h" 3
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
# 4860 "/home/normal/cuda/bin/../include/device_functions.h" 2 3
# 945 "/home/normal/cuda/bin/../include/math_functions.h" 2 3


static int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 969 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1055 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1151 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1272 "/home/normal/cuda/bin/../include/math_functions.h" 3
static int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1286 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 1630 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2638 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2670 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2723 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 2758 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 3045 "/home/normal/cuda/bin/../include/math_functions.h" 3
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
# 3176 "/home/normal/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}
# 3734 "/home/normal/cuda/bin/../include/math_functions.h" 3
# 1 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 61 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
static double __cuda_fabs(double a)
{
  return fabs(a);
}

static double __cuda_fmax(double a, double b)
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

static double __cuda_fmin(double a, double b)
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



    e += ((ihi >> 20) & 0x7ff);
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


static double2 __internal_ddadd_xgty (double2 x, double2 y)
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


static double2 __internal_ddmul (double2 x, double2 y)
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
  z = __internal_exp2i_kernel(i + scale - 1);
  t = __fma_rn (t, z, z);
  t = t * fac;
  return t;
}

static double __cuda_exp(double a)
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

static double __cuda_exp2(double a)
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

static double __cuda_exp10(double a)
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

static double __cuda_expm1(double a)
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

static double __cuda_cosh(double a)
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

static double __cuda_acos(double a)
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
# 1164 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
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

static double __cuda_erfinv(double a)
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

static double __cuda_erfcinv(double a)
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

static double __cuda_erfc(double a)
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
  h = a * a;
  l = __fma_rn (a, a, -h);
  q = __internal_exp_kernel(-h, 0);
  q = __fma_rn (l, -q, q);
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
# 2326 "/home/normal/cuda/bin/../include/math_functions_dbl_ptx3.h" 3
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
# 3735 "/home/normal/cuda/bin/../include/math_functions.h" 2 3
# 94 "/home/normal/cuda/bin/../include/common_functions.h" 2
# 227 "/home/normal/cuda/bin/../include/crt/host_runtime.h" 2
# 6 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.stub.c" 2
struct __T20 {__TOptionValue *__par0;float *__par1;int __par2;int __dummy_field;};
struct __T21 {float *__par0;int __par1;int __dummy_field;};
struct __T22 {__TOptionValue *__par0;int __par1;int __dummy_field;};
struct __T23 {float *__par0;float *__par1;unsigned __par2;int __dummy_field;};
static void __sti____cudaRegisterAll_51_tmpxft_0000707d_00000000_14_MonteCarlo_SM13_cpp1_ii_9123f87d(void) __attribute__((__constructor__));
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *__par0, float *__par1, int __par2){auto struct __T20 *__T24;
char __[256]; *(char**)&__T24 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1 - (size_t)__T24) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2 - (size_t)__T24) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel__entry))); };}

}
static void MonteCarloKernel__entry( __TOptionValue * __cuda_0,float * __cuda_1,int __cuda_2)
{__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi( __cuda_0, __cuda_1, __cuda_2);}
extern "C"{

static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi(float *__par0, int __par1){auto struct __T21 *__T25;
char __[256]; *(char**)&__T25 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1 - (size_t)__T25) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption__entry))); };}

}
static void MonteCarloOneBlockPerOption__entry( float * __cuda_0,int __cuda_1)
{__device_stub__Z27MonteCarloOneBlockPerOptionPfi( __cuda_0, __cuda_1);}
extern "C"{

static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei(__TOptionValue *__par0, int __par1){auto struct __T22 *__T26;
char __[256]; *(char**)&__T26 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T26->__par0 - (size_t)__T26) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T26->__par1 - (size_t)__T26) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce__entry)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce__entry))); };}

}
static void MonteCarloReduce__entry( __TOptionValue * __cuda_0,int __cuda_1)
{__device_stub__Z16MonteCarloReduceP14__TOptionValuei( __cuda_0, __cuda_1);}
extern "C"{

static void __device_stub__Z16inverseCNDKernelPfS_j(float *__par0, float *__par1, unsigned __par2){auto struct __T23 *__T224;
char __[256]; *(char**)&__T224 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T224->__par0 - (size_t)__T224) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T224->__par1 - (size_t)__T224) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T224->__par2 - (size_t)__T224) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel__entry))); };}

}
static void inverseCNDKernel__entry( float * __cuda_0,float * __cuda_1,unsigned __cuda_2)
{__device_stub__Z16inverseCNDKernelPfS_j( __cuda_0, __cuda_1, __cuda_2);}
extern "C"{
# 55 "/tmp/tmpxft_0000707d_00000000-4_MonteCarlo_SM13.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_0000707d_00000000_14_MonteCarlo_SM13_cpp1_ii_9123f87d(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, unsigned))inverseCNDKernel__entry), (char*)"_Z16inverseCNDKernelPfS_j", "_Z16inverseCNDKernelPfS_j", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, int))MonteCarloReduce__entry), (char*)"_Z16MonteCarloReduceP14__TOptionValuei", "_Z16MonteCarloReduceP14__TOptionValuei", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))MonteCarloOneBlockPerOption__entry), (char*)"_Z27MonteCarloOneBlockPerOptionPfi", "_Z27MonteCarloOneBlockPerOptionPfi", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel__entry), (char*)"_Z16MonteCarloKernelP14__TOptionValuePfi", "_Z16MonteCarloKernelP14__TOptionValuePfi", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_d_OptionData, (char*)"d_OptionData", "d_OptionData", 0, 65536, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_d_CallValue, (char*)"d_CallValue", "d_CallValue", 0, 32768, 0, 0);}

}
# 60 "MonteCarlo_SM13.cu" 2

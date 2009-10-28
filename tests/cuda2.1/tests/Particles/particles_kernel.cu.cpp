# 1 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.cpp"
# 1 "particles_kernel.cu"
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


static SimParams __shadow_params;



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
# 334 "particles_kernel.cu"
void collideD__entry(float4 *newPos, float4 *newVel, float4 *
oldPos, float4 *oldVel, uint2 *

particleHash, uint *
cellStart);
# 382 "particles_kernel.cu"
# 1 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_000062f6_00000000-6_particles_kernel.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000062f6_00000000-6_particles_kernel.fatbin.c" 2




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
0x207374736e6f630aull,0x656d616e09090a7bull,0x6170203d20202020ull,0x7309090a736d6172ull,
0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x206d756e67657309ull,0x6f09090a30203d20ull,
0x3d20207465736666ull,0x74796209090a3020ull,0x31203d2020207365ull,0x646f630a7d0a3231ull,
0x6d616e090a7b2065ull,0x31315a5f203d2065ull,0x7247657461647075ull,0x6f6c663650446469ull,
0x5f31536a50347461ull,0x3d206d656d6c090aull,0x6d656d73090a3020ull,0x72090a3034203d20ull,
0x0a37203d20206765ull,0x203d202072616209ull,0x74736e6f63090a30ull,0x65730909090a7b20ull,
0x203d20656d616e67ull,0x09090a74736e6f63ull,0x206d756e67657309ull,0x0909090a31203d20ull,
0x202074657366666full,0x620909090a30203dull,0x3d20202073657479ull,0x6d656d09090a3420ull,
0x78300909090a7b20ull,0x3030303030386533ull,0x7d090a7d09090a20ull,0x646f636e6962090aull,
0x783009090a7b2065ull,0x3530633430303061ull,0x3030323430783020ull,0x3061783020303837ull,
0x3020393032343030ull,0x3837303032343078ull,0x34783009090a2030ull,0x2035303230323030ull,
0x3738313030307830ull,0x3030617830203038ull,0x7830203130303030ull,0x3038373030303430ull,
0x3032783009090a20ull,0x3020313032303030ull,0x3837303030343078ull,0x3430303378302030ull,
0x6378302035303030ull,0x2030383730303134ull,0x303031783009090aull,0x7830203930303830ull,
0x3330303038653730ull,0x6330303032783020ull,0x3430783020353038ull,0x0a20303837343032ull,
0x3139306278300909ull,0x3678302064663530ull,0x2038633734383030ull,0x3230653030647830ull,
0x6330387830203930ull,0x090a203038373030ull,0x3230303031783009ull,0x3432783020643032ull,
0x3020303837633030ull,0x3034303030316278ull,0x3330383078302039ull,0x09090a2030383738ull,
0x3030303030317830ull,0x3434327830206430ull,0x7830203038366330ull,0x3930343030383063ull,
0x3030343030783020ull,0x3009090a20303836ull,0x3036303139306378ull,0x3030303078302064ull,
0x3978302030383630ull,0x2063303630303030ull,0x3430333030637830ull,0x783009090a206330ull,
0x3930303830303031ull,0x3038653730783020ull,0x3061783020333030ull,0x3020643036303030ull,
0x3837343230636378ull,0x32783009090a2030ull,0x2031313238343030ull,0x3030303030307830ull,
0x3930627830203330ull,0x7830206466353032ull,0x3863373438303036ull,0x3061783009090a20ull,
0x3020393036303030ull,0x3837343630633878ull,0x6530306478302030ull,0x3878302064303830ull,
0x2030383730306330ull,0x303031783009090aull,0x7830203131343230ull,0x3038376330303432ull,
0x3030303162783020ull,0x3830783020643036ull,0x0a20303837633330ull,0x3030303178300909ull,
0x3278302031313030ull,0x2030383663303434ull,0x3630303830637830ull,0x3430307830206430ull,
0x090a203038363030ull,0x3032393063783009ull,0x3030783020313138ull,0x3020303836303030ull,
0x3138303030303978ull,0x3030303078302035ull,0x09090a2030383730ull,0x3038303030317830ull,
0x6537307830203131ull,0x7830203330303038ull,0x3530323838303032ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3036303530306378ull,0x3030303078302064ull,0x6278302030383730ull,
0x2064663930333930ull,0x3734383030367830ull,0x783009090a203863ull,0x3530323065303064ull,
0x3030633038783020ull,0x3061783020303837ull,0x3020643036303030ull,0x3837343230636378ull,
0x31783009090a2030ull,0x2031313632303030ull,0x3763303034327830ull,0x3031627830203038ull,
0x7830203530323030ull,0x3038373034303830ull,0x3061783009090a20ull,0x3020643036303030ull,
0x3837343630633878ull,0x3030303178302030ull,0x3278302031313030ull,0x2030383663303434ull,
0x383063783009090aull,0x7830203530323030ull,0x3038363030343030ull,0x3033393063783020ull,
0x3030783020313138ull,0x0a20303836303030ull,0x3030303978300909ull,0x6378302030313830ull,
0x2030313230343030ull,0x3038663330317830ull,0x6666307830203530ull,0x090a206666666666ull,
0x3030303061783009ull,0x6363783020313138ull,0x3020303837343230ull,0x3132303030313278ull,
0x3330343078302035ull,0x09090a2030383730ull,0x3830303030617830ull,0x3063387830203131ull,
0x7830203038373436ull,0x3531383035303033ull,0x3030303461783020ull,0x3009090a20303837ull,
0x3132386238303278ull,0x6263303478302030ull,0x3378302034316138ull,0x2064303630343030ull,
0x3730303034617830ull,0x783009090a203038ull,0x3031613861633034ull,0x3861383032783020ull,
0x3036783020343132ull,0x3020643036306138ull,0x3837303130303878ull,0x33783009090a2030ull,
0x2039303430353030ull,0x3730303034617830ull,0x3030327830203038ull,0x7830203930363030ull,
0x3038373830303430ull,0x3031783009090a20ull,0x3020643061323030ull,0x3837633030343278ull,
0x3230303378302030ull,0x6378302031313430ull,0x2030383730303134ull,0x303034783009090aull,
0x7830203931383037ull,0x3038373030303030ull,0x3831303031783020ull,0x3030783020353130ull,
0x0a20333030303030ull,0x3030303278300909ull,0x3078302031316363ull,0x2030383730313234ull,
0x6130363030367830ull,0x3030307830203931ull,0x090a203038373831ull,0x3035303764783009ull,
0x3065783020313138ull,0x3020303837303063ull,0x3032303030313278ull,0x3530343078302035ull,
0x09090a2030383734ull,0x6330303130337830ull,0x3134637830203531ull,0x7830203038373030ull,
0x3530383031303033ull,0x3030303461783020ull,0x3009090a20303837ull,0x3038303630303678ull,
0x3130303078302039ull,0x3278302030383734ull,0x2035303430303030ull,0x3734303034307830ull,
0x783009090a203038ull,0x3530323032303033ull,0x3030313463783020ull,0x3032783020303837ull,
0x3020353030643030ull,0x3837343032343078ull,0x64783009090a2030ull,0x2031303230653030ull,
0x3730306330617830ull,0x7d0a7d090a203138ull,0x0a7b2065646f630aull,0x203d20656d616e09ull,
0x696c6c6f63385a5full,0x6f6c663650446564ull,0x30535f3053347461ull,0x697535505f30535full,
0x6c090a6a5032746eull,0x0a30203d206d656dull,0x203d206d656d7309ull,0x20676572090a3436ull,
0x62090a3533203d20ull,0x0a30203d20207261ull,0x7b2074736e6f6309ull,0x6e6765730909090aull,
0x6f63203d20656d61ull,0x730909090a74736eull,0x3d20206d756e6765ull,0x666f0909090a3120ull,
0x203d202074657366ull,0x7479620909090a30ull,0x31203d2020207365ull,0x206d656d09090a32ull,
0x6678300909090a7bull,0x2066666666666666ull,0x3030303030307830ull,0x3865337830203230ull,
0x090a203030303030ull,0x62090a7d090a7d09ull,0x7b2065646f636e69ull,0x303061783009090aull,
0x7830203530633430ull,0x3038373030323430ull,0x3430303061783020ull,0x3430783020393032ull,
0x0a20303837303032ull,0x3230303478300909ull,0x3078302035303230ull,0x2030383738313030ull,
0x3030303030617830ull,0x3034307830203130ull,0x090a203038373030ull,0x3030303032783009ull,
0x3430783020393032ull,0x3020303837303030ull,0x3030383030303178ull,0x3865373078302031ull,
0x09090a2033303030ull,0x3430303030317830ull,0x3036307830203132ull,0x7830203038376333ull,
0x6466313031393062ull,0x3438303036783020ull,0x3009090a20386337ull,0x3134303030303178ull,
0x3330343078302031ull,0x6678302030383763ull,0x2031323030303037ull,0x3734303030307830ull,
0x783009090a203038ull,0x3131323032303766ull,0x6330303030783020ull,0x3031783020343837ull,
0x3020313032323030ull,0x3837633030343278ull,0x31783009090a2030ull,0x2063303239323030ull,
0x3439303030317830ull,0x3030317830206333ull,0x7830203832613832ull,0x6334633830303031ull,
0x3031783009090a20ull,0x3020633265383230ull,0x3030316563306278ull,0x3030303178302034ull,
0x3278302031303430ull,0x2030383663303434ull,0x383063783009090aull,0x7830203530323032ull,
0x3038363030343030ull,0x3031393063783020ull,0x3030783020313030ull,0x0a20303836303030ull,
0x3030303978300909ull,0x6378302030303030ull,0x2034303230303030ull,0x3038303030317830ull,
0x6537307830203130ull,0x090a203330303038ull,0x3030303061783009ull,0x6363783020353132ull,
0x3020303837343230ull,0x6631303239306278ull,0x3830303678302064ull,0x09090a2038633734ull,
0x3630303031627830ull,0x3038307830203130ull,0x7830203038376333ull,0x3530343230303031ull,
0x6330303432783020ull,0x3009090a20303837ull,0x3561303030306178ull,0x3630633878302031ull,
0x3178302030383734ull,0x2035303430303030ull,0x3663303434327830ull,0x783009090a203038ull,
0x3130303032383063ull,0x3030343030783020ull,0x3063783020303836ull,0x3020353032303239ull,
0x3836303030303078ull,0x39783009090a2030ull,0x2034303230303030ull,0x3030313030637830ull,
0x3030317830203430ull,0x7830203130303830ull,0x3330303038653730ull,0x3061783009090a20ull,
0x3020353132303030ull,0x3837343230636378ull,0x3339306278302030ull,0x3678302064663130ull,
0x2038633734383030ull,0x303162783009090aull,0x7830203130653130ull,0x3038373034303830ull,
0x3230303031783020ull,0x3432783020353036ull,0x0a20303837633030ull,0x3030306178300909ull,
0x3878302035356130ull,0x2030383734363063ull,0x3430303030317830ull,0x3434327830203530ull,
0x090a203038366330ull,0x3032383063783009ull,0x3030783020313030ull,0x3020303836303034ull,
0x3032303339306378ull,0x3030303078302035ull,0x09090a2030383630ull,0x3230303030397830ull,
0x3030637830203430ull,0x7830203030303031ull,0x6435303866333031ull,0x6666666630783020ull,
0x3009090a20666666ull,0x3030303030306178ull,0x3230636378302031ull,0x3178302030383734ull,
0x2031363866303030ull,0x3763333034307830ull,0x783009090a203038ull,0x3536386630303031ull,
0x6333303630783020ull,0x3031783020303837ull,0x3020393638663030ull,0x3837633330343078ull,
0x61783009090a2030ull,0x2039353030303030ull,0x3734363063387830ull,0x3330317830203038ull,
0x7830206436303866ull,0x6666666666666630ull,0x3031783009090a20ull,0x3020313730386633ull,
0x6666666666663078ull,0x3030303278302066ull,0x3078302031303832ull,0x2030633730373034ull,
0x303061783009090aull,0x7830203330303239ull,0x3030303030303030ull,0x3234303031783020ull,
0x3030783020333030ull,0x0a20303839303030ull,0x6633303178300909ull,0x3078302035303038ull,
0x2066666666666666ull,0x3230303031327830ull,0x3034307830203530ull,0x090a203038373832ull,
0x3031303033783009ull,0x3436783020646631ull,0x3020386337303130ull,0x3030323430303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6132303030327830ull,0x3034307830203531ull,
0x7830203063376336ull,0x3330303234303031ull,0x3030303030783020ull,0x3009090a20303839ull,
0x3130386633303178ull,0x6666663078302039ull,0x3278302066666666ull,0x2039316330303031ull,
0x3763323034307830ull,0x783009090a203038ull,0x6466623036303033ull,0x3031303436783020ull,
0x3031783020386337ull,0x3020333030323430ull,0x3832303030303078ull,0x32783009090a2030ull,
0x2064316332303030ull,0x3763353034307830ull,0x3030317830203063ull,0x7830203330303234ull,
0x3038393030303030ull,0x3031783009090a20ull,0x3020353230386633ull,0x6666666666663078ull,
0x3030313278302066ull,0x3078302035323231ull,0x2030383730333034ull,0x303033783009090aull,
0x7830206466663039ull,0x3863376330303436ull,0x3634303031783020ull,0x3030783020333030ull,
0x0a20303832303030ull,0x3030303178300909ull,0x3078302035323866ull,0x2030383763333036ull,
0x3866303030317830ull,0x3034307830203531ull,0x090a203038376333ull,0x6630303031783009ull,
0x3630783020393138ull,0x3020303837633330ull,0x3030323930303178ull,0x3030303078302033ull,
0x09090a2030383730ull,0x6530393030337830ull,0x3034617830206431ull,0x7830203038373030ull,
0x3931613036303033ull,0x3030303461783020ull,0x3009090a20303837ull,0x3165386263303478ull,
0x6163303478302034ull,0x3378302038316338ull,0x2031303030313030ull,0x3730303034617830ull,
0x783009090a203038ull,0x3530613061383036ull,0x3831303038783020ull,0x3032783020303837ull,
0x3020633132383030ull,0x3065383030303178ull,0x66783009090a2030ull,0x2031303630363033ull,
0x3730303030307830ull,0x3830337830203038ull,0x7830206466313030ull,0x3863373431343436ull,
0x3031783009090a20ull,0x3020333030333530ull,0x3832303030303078ull,0x3030303178302030ull,
0x3078302035323866ull,0x2030383763333036ull,0x303031783009090aull,0x7830203531386630ull,
0x3038376333303430ull,0x6630303031783020ull,0x3630783020393138ull,0x0a20303837633330ull,
0x3930303178300909ull,0x3078302033303032ull,0x2030383730303030ull,0x3966353930337830ull,
0x3034367830206466ull,0x090a203863373830ull,0x6630303031783009ull,0x3430783020353238ull,
0x3020303837633330ull,0x3138663030303178ull,0x3330363078302035ull,0x09090a2030383763ull,
0x3866303030317830ull,0x3034307830203931ull,0x7830203038376333ull,0x3330303239303031ull,
0x3030303030783020ull,0x3009090a20303832ull,0x3030323930303478ull,0x3030303078302033ull,
0x3178302030303030ull,0x2035373866303030ull,0x3763333036307830ull,0x783009090a203038ull,
0x3033303864313032ull,0x3930303031783020ull,0x3366783020343038ull,0x3020353034303430ull,
0x3837303030303078ull,0x33783009090a2034ull,0x2064666630313030ull,0x3734313034367830ull,
0x3030357830203863ull,0x7830203330303030ull,0x3038323030303030ull,0x3032783009090a20ull,
0x3020353034303034ull,0x3837303030343078ull,0x3130303378302030ull,0x3678302064666233ull,
0x2038633738303034ull,0x303061783009090aull,0x7830203330306438ull,0x3030303030303030ull,
0x6438303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3030303178300909ull,
0x3078302031343831ull,0x2030383763333036ull,0x3062383030617830ull,0x3030307830203330ull,
0x090a203030303030ull,0x3030303766783009ull,0x3030783020313430ull,0x3020343837343030ull,
0x3332303230376678ull,0x3030303078302031ull,0x09090a2034383734ull,0x3232333430627830ull,
0x3430627830203430ull,0x7830203034303238ull,0x3837323031303063ull,0x3266343062783020ull,
0x3009090a20343434ull,0x3430323031306578ull,0x3730303078302039ull,0x6578302030383738ull,
0x2064373232313130ull,0x3738343030307830ull,0x783009090a203038ull,0x3934323130303031ull,
0x6330303432783020ull,0x3039783020303837ull,0x3020393765333030ull,0x3837303030303478ull,
0x62783009090a2030ull,0x2038343432393830ull,0x6333303030397830ull,0x3230627830203038ull,
0x7830206466353230ull,0x3863373031303036ull,0x3031783009090a20ull,0x3020393763313030ull,
0x3837633330343078ull,0x3830303178302030ull,0x3078302033303038ull,0x2030303130303030ull,
0x303039783009090aull,0x7830206437653330ull,0x3038373030303034ull,0x3230363062783020ull,
0x3062783020303834ull,0x0a20383361316134ull,0x3130306378300909ull,0x6278302034336533ull,
0x2038343831343430ull,0x6533303130637830ull,0x3030637830203033ull,0x090a203438633164ull,
0x3333353062783009ull,0x3063783020383763ull,0x3020633765333131ull,0x3838313231306578ull,
0x3830303078302035ull,0x09090a2030383734ull,0x3034363930637830ull,0x3030307830203138ull,
0x7830203038373030ull,0x3538653365313065ull,0x3438303030783020ull,0x3009090a20303837ull,
0x3838313032306378ull,0x3030303078302039ull,0x6578302030383730ull,0x2031333831313230ull,
0x3738343034307830ull,0x783009090a203038ull,0x3934343237393065ull,0x3838303830783020ull,
0x3065783020303837ull,0x3020313338313839ull,0x3837383430303078ull,0x65783009090a2030ull,
0x2031333032393930ull,0x3730333030307830ull,0x3230637830203038ull,0x7830203134653330ull,
0x3038373030303030ull,0x3065783009090a20ull,0x3020313463333739ull,0x3837303430383078ull,
0x6631306578302030ull,0x3078302039373234ull,0x2030383738373034ull,0x323063783009090aull,
0x7830203934613130ull,0x3038373030303030ull,0x3464303065783020ull,0x3430783020353332ull,
0x0a20303837383330ull,0x3739306578300909ull,0x3078302039336331ull,0x2030383738343038ull,
0x6131383930657830ull,0x3030307830203533ull,0x090a203038373833ull,0x3338393065783009ull,
0x3030783020393363ull,0x3020303837303430ull,0x3032303939306578ull,0x3330303078302035ull,
0x09090a2030383734ull,0x3232393930657830ull,0x3030307830203533ull,0x7830203038373833ull,
0x3330306238303031ull,0x3030303030783020ull,0x3009090a20303837ull,0x3338663030303178ull,
0x3330363078302035ull,0x3178302030383763ull,0x2035303866303030ull,0x3763333034307830ull,
0x783009090a203038ull,0x3133386630303031ull,0x6333303630783020ull,0x3062783020303837ull,
0x3020353261313030ull,0x3837343230303078ull,0x62783009090a2032ull,0x2038313831363030ull,
0x3230353030627830ull,0x3030667830203431ull,0x7830203130303030ull,0x3230303030303065ull,
0x3032783009090a20ull,0x3020353761623130ull,0x3030303030303078ull,0x3539303378302033ull,
0x3678302064666233ull,0x2038633734313034ull,0x303031783009090aull,0x7830203330306135ull,
0x3038323030303030ull,0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3030306278300909ull,0x3078302031363231ull,0x2032383730363030ull,0x3862313030327830ull,
0x3030307830203137ull,0x090a203330303030ull,0x3331383033783009ull,0x6336783020646639ull,
0x3020386337343134ull,0x3663306131306278ull,0x3931306278302038ull,0x09090a2034366130ull,
0x3066323030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x6436366231303032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x6637333138303378ull,0x3134633678302064ull,
0x3178302038633734ull,0x2033303065323030ull,0x3230303030307830ull,0x783009090a203038ull,
0x6435656131303032ull,0x3030303030783020ull,0x3033783020333030ull,0x3020646666323138ull,
0x6337343134633678ull,0x31783009090a2038ull,0x2033303064323030ull,0x3230303030307830ull,
0x3830627830203038ull,0x7830203430363831ull,0x6330303930383062ull,0x3063783009090a20ull,
0x3020303032303130ull,0x3165393238306278ull,0x3330306578302034ull,0x3078302031303630ull,
0x2030383730303030ull,0x303065783009090aull,0x7830203931613035ull,0x3038373030303030ull,
0x3030303031783020ull,0x3432783020313038ull,0x0a20303837633030ull,0x3030303978300909ull,
0x3478302064316330ull,0x2030383730303030ull,0x3030393830627830ull,0x3030397830203030ull,
0x090a206331653030ull,0x3037303062783009ull,0x3036783020646631ull,0x3020386337303130ull,
0x3030646230306178ull,0x3030303078302033ull,0x09090a2030303030ull,0x3061623030317830ull,
0x3030307830203330ull,0x7830203030313030ull,0x3931633030303039ull,0x3030303034783020ull,
0x3009090a20303837ull,0x3063303130306378ull,0x3330306378302034ull,0x6378302063306330ull,
0x2030323230613030ull,0x3030373430627830ull,0x783009090a206331ull,0x3130633035303063ull,
0x3030303030783020ull,0x3065783020303837ull,0x3020353136303430ull,0x3837303230633078ull,
0x63783009090a2030ull,0x2039316530363930ull,0x3730303030307830ull,0x3130657830203038ull,
0x7830203531303033ull,0x3038373431303430ull,0x3063783009090a20ull,0x3020633136303630ull,
0x3230303630306378ull,0x3630306378302030ull,0x3078302039313230ull,0x2030383730303030ull,
0x303065783009090aull,0x7830206430363035ull,0x3038373031303030ull,0x3031303065783020ull,
0x3030783020353061ull,0x0a20303837383230ull,0x3030306578300909ull,0x3078302035316130ull,
0x2030383763343030ull,0x3830373930657830ull,0x3030307830203130ull,0x090a203038376331ull,
0x3137393065783009ull,0x3030783020393134ull,0x3020303837383130ull,0x3136323739306578ull,
0x3230303078302064ull,0x09090a2030383730ull,0x3630383930657830ull,0x3063307830203130ull,
0x7830203038373030ull,0x3530323038393065ull,0x3831306330783020ull,0x3009090a20303837ull,
0x3061303839306578ull,0x3130633078302064ull,0x3178302030383763ull,0x2033303064623030ull,
0x3730303030307830ull,0x783009090a203038ull,0x6430386630303031ull,0x6333303430783020ull,
0x3031783020303837ull,0x3020353038663030ull,0x3837633330363078ull,0x31783009090a2030ull,
0x2031303866303030ull,0x3763333034307830ull,0x3030337830203038ull,0x7830203930343033ull,
0x3238373030313463ull,0x3062783009090a20ull,0x3020383136303831ull,0x3030306131306278ull,
0x3931306278302063ull,0x3278302034313230ull,0x2030303866323031ull,0x303064783009090aull,
0x7830203130303065ull,0x3038373030383038ull,0x3236303062783020ull,0x3062783020383136ull,
0x0a20383038303330ull,0x3030306278300909ull,0x3078302064303431ull,0x2030383734313030ull,
0x3230343030337830ull,0x3134637830203130ull,0x090a203038373030ull,0x6330303032783009ull,
0x3430783020313063ull,0x3020303837303032ull,0x3030306530306478ull,0x3063306178302039ull,
0x09090a2030383730ull,0x3038343030327830ull,0x3030307830203530ull,0x7830203330303030ull,
0x6430323065303064ull,0x3030633061783020ull,0x3009090a20303837ull,0x3030383830303278ull,
0x3030303078302035ull,0x6478302033303030ull,0x2039313230653030ull,0x3730306330617830ull,
0x783009090a203038ull,0x3130303863303032ull,0x3030303030783020ull,0x3064783020333030ull,
0x3020643230306530ull,0x3837303063306178ull,0x0a7d0a7d090a2031ull,0x090a7b2065646f63ull,
0x5f203d20656d616eull,0x64726f657238325aull,0x6e41617461447265ull,0x6c6543646e694664ull,
0x504474726174536cull,0x365032746e697535ull,0x32533474616f6c66ull,0x505f32535f32535full,
0x206d656d6c090a6aull,0x656d73090a30203dull,0x32393031203d206dull,0x3d2020676572090aull,
0x726162090a303120ull,0x63090a31203d2020ull,0x090a7b2074736e6full,0x6d616e6765730909ull,
0x736e6f63203d2065ull,0x6765730909090a74ull,0x31203d20206d756eull,0x7366666f0909090aull,
0x0a30203d20207465ull,0x7365747962090909ull,0x090a38203d202020ull,0x090a7b206d656d09ull,
0x6666666678300909ull,0x6678302038666666ull,0x2066666666666666ull,0x0a7d090a7d09090aull,
0x65646f636e696209ull,0x61783009090a7b20ull,0x2035306334303030ull,0x3730303234307830ull,
0x3030617830203038ull,0x7830203930323430ull,0x3038373030323430ull,0x3034783009090a20ull,
0x3020353032303230ull,0x3837383130303078ull,0x3030306178302030ull,0x3078302031303030ull,
0x2030383730303034ull,0x303032783009090aull,0x7830203132303030ull,0x3038373430303430ull,
0x3133303033783020ull,0x3463783020353030ull,0x0a20303837303031ull,0x6337303378300909ull,
0x3678302064663131ull,0x2038633730313063ull,0x3030323030307830ull,0x3030637830203530ull,
0x090a203038373030ull,0x6330303032783009ull,0x3430783020393038ull,0x3020303837343032ull,
0x6631306337303378ull,0x3030343678302064ull,0x09090a2038633238ull,0x3430653030647830ull,
0x3830387830203130ull,0x7830203038373030ull,0x3130323230303430ull,0x3030323465783020ull,
0x3009090a20303837ull,0x3134303030313278ull,0x3034343078302031ull,0x6478302030383630ull,
0x2039303830653030ull,0x3630303830387830ull,0x783009090a203038ull,0x3130303230303030ull,
0x3830323465783020ull,0x3638783020303836ull,0x3020333065666631ull,0x3030303030303078ull,
0x33783009090a2030ull,0x2064663131633730ull,0x3738303063367830ull,0x3030617830203863ull,
0x7830203330303831ull,0x3030303030303030ull,0x3031783009090a20ull,0x3020333030353130ull,
0x3832303030303078ull,0x3030343378302030ull,0x3678302064663165ull,0x2038633738303234ull,
0x303031783009090aull,0x7830203330303831ull,0x3038323030303030ull,0x3032303033783020ull,
0x3463783020313030ull,0x0a20303837303031ull,0x3030303278300909ull,0x3078302031306364ull,
0x2030383730303234ull,0x3030653030647830ull,0x6330617830203132ull,0x090a203038373030ull,
0x3034303033783009ull,0x3463783020313032ull,0x3020323837303031ull,0x3263653030313278ull,
0x3030303178302034ull,0x09090a2030303238ull,0x3231653030647830ull,0x6130387830203131ull,
0x7830203038373030ull,0x3130323032303766ull,0x6330303030783020ull,0x3009090a20343837ull,
0x3132316530306478ull,0x3063303878302031ull,0x3378302030383730ull,0x2031323031343030ull,
0x3730303134637830ull,0x783009090a203038ull,0x3532346430303032ull,0x3032323430783020ull,
0x3064783020303837ull,0x3020313132316530ull,0x3837303061306178ull,0x32783009090a2030ull,
0x2031313864303030ull,0x3730323234307830ull,0x3030647830203038ull,0x7830203130383065ull,
0x3138373030613061ull,0x630a7d0a7d090a20ull,0x6e090a7b2065646full,0x5a5f203d20656d61ull,
0x61726765746e6939ull,0x616f6c6636506574ull,0x5f30535f30533474ull,0x6d6c090a665f3053ull,
0x090a30203d206d65ull,0x35203d206d656d73ull,0x2020676572090a32ull,0x6162090a3431203dull,
0x090a30203d202072ull,0x2065646f636e6962ull,0x3061783009090a7bull,0x3020353063343030ull,
0x3837303032343078ull,0x3030306178302030ull,0x3078302039303234ull,0x2030383730303234ull,
0x303034783009090aull,0x7830203530323032ull,0x3038373831303030ull,0x3030303061783020ull,
0x3430783020313030ull,0x0a20303837303030ull,0x3030303278300909ull,0x3078302031303230ull,
0x2030383730303034ull,0x3030343030337830ull,0x3134637830203132ull,0x090a203038373030ull,
0x6430303032783009ull,0x3430783020313034ull,0x3020303837303232ull,0x3230643030303278ull,
0x3232343078302035ull,0x09090a2030383730ull,0x3030653030647830ull,0x6130387830203130ull,
0x7830203038373030ull,0x3131323165303064ull,0x3030613038783020ull,0x3009090a20303837ull,
0x3230383030303178ull,0x3866333078302035ull,0x6278302033303030ull,0x2064323231303031ull,
0x3734323038307830ull,0x783009090a203038ull,0x3130386435383065ull,0x3030323030783020ull,
0x3065783020303837ull,0x3020353038643638ull,0x3837343032303078ull,0x65783009090a2030ull,
0x2039303864373830ull,0x3738303230307830ull,0x3030317830203038ull,0x7830203433653832ull,
0x6331303038383063ull,0x3063783009090a20ull,0x3020383232303838ull,0x3234303838306378ull,
0x3030303178302034ull,0x3078302031333630ull,0x2030383763333034ull,0x303065783009090aull,
0x7830203130386437ull,0x3038373031323030ull,0x6461303065783020ull,0x3030783020393038ull,
0x0a20303837343132ull,0x3930306578300909ull,0x3078302031313864ull,0x2030383738313230ull,
0x3731303030627830ull,0x3030367830206466ull,0x090a203863373430ull,0x3832303031783009ull,
0x3031783020343034ull,0x3020633038383030ull,0x3165306139306378ull,0x3030303078302064ull,
0x09090a2030383630ull,0x3631303030317830ull,0x3036307830203130ull,0x7830203038366333ull,
0x3531303830303031ull,0x3038666230783020ull,0x3009090a20333030ull,0x3161303030316278ull,
0x3230303078302035ull,0x6278302030383734ull,0x2064666230303030ull,0x3730313030367830ull,
0x783009090a203863ull,0x6431653061393063ull,0x3030303030783020ull,0x3031783020303836ull,
0x3020313061303030ull,0x3836633330343078ull,0x62783009090a2030ull,0x2064663731313030ull,
0x3734303030367830ull,0x3930637830203863ull,0x7830203932343161ull,0x3038363030303030ull,
0x3031783009090a20ull,0x3020393036313030ull,0x3836633330363078ull,0x3230306278302030ull,
0x3678302064666230ull,0x2038633730313030ull,0x393063783009090aull,0x7830203932343161ull,
0x3038363030303030ull,0x3030303031783020ull,0x3430783020393061ull,0x0a20303836633330ull,
0x3330306278300909ull,0x3678302064663731ull,0x2038633734303030ull,0x3231613930637830ull,
0x3030307830203532ull,0x090a203038363030ull,0x3130303031783009ull,0x3630783020313136ull,
0x3020303836633330ull,0x6662303430306278ull,0x3130303678302064ull,0x09090a2038633730ull,
0x3231613930637830ull,0x3030307830203532ull,0x7830203038363030ull,0x3131613030303031ull,
0x6333303430783020ull,0x3009090a20303836ull,0x3034383230303178ull,0x3030303178302034ull,
0x3178302038303838ull,0x2063306139323030ull,0x3865383031327830ull,0x783009090a203031ull,
0x3130383065303064ull,0x3030613061783020ull,0x3031783020303837ull,0x3020343034393030ull,
0x3032393230303178ull,0x31783009090a2038ull,0x2063303839303030ull,0x6365383031327830ull,
0x3030317830203031ull,0x7830203130653030ull,0x3038376333303430ull,0x3064783009090a20ull,
0x3020313038306530ull,0x3837303061306178ull,0x0a7d0a7d090a2031ull,0x090a7b2065646f63ull,
0x5f203d20656d616eull,0x6148636c6163395aull,0x6f6c663650446873ull,0x6e69753550347461ull,
0x6d656d6c090a3274ull,0x6d73090a30203d20ull,0x0a3233203d206d65ull,0x203d202067657209ull,
0x2020726162090a37ull,0x6e6f63090a30203dull,0x0909090a7b207473ull,0x20656d616e676573ull,
0x0a74736e6f63203dull,0x756e676573090909ull,0x090a31203d20206dull,0x74657366666f0909ull,
0x09090a30203d2020ull,0x2020736574796209ull,0x6d09090a34203d20ull,0x0909090a7b206d65ull,
0x3030303865337830ull,0x0a7d09090a203030ull,0x636e6962090a7d09ull,0x09090a7b2065646full,
0x6334303030617830ull,0x3234307830203530ull,0x7830203038373030ull,0x3930323430303061ull,
0x3030323430783020ull,0x3009090a20303837ull,0x3032303230303478ull,0x3130303078302035ull,
0x6178302030383738ull,0x2031303030303030ull,0x3730303034307830ull,0x783009090a203038ull,
0x3130323030303032ull,0x3030303430783020ull,0x3033783020303837ull,0x3020353030303430ull,
0x3837303031346378ull,0x31783009090a2030ull,0x2039303038303030ull,0x3030386537307830ull,
0x3030327830203330ull,0x7830203530386330ull,0x3038373430323430ull,0x3062783009090a20ull,
0x3020646635303139ull,0x6337343830303678ull,0x6530306478302038ull,0x3878302039303230ull,
0x2030383730306330ull,0x303031783009090aull,0x7830206430323230ull,0x3038376330303432ull,
0x3030303162783020ull,0x3830783020393034ull,0x0a20303837383330ull,0x3030303178300909ull,
0x3278302064303030ull,0x2030383663303434ull,0x3430303830637830ull,0x3430307830203930ull,
0x090a203038363030ull,0x3031393063783009ull,0x3030783020643036ull,0x3020303836303030ull,
0x3036303030303978ull,0x3330306378302063ull,0x09090a2063303430ull,0x3038303030317830ull,
0x6537307830203930ull,0x7830203330303038ull,0x6430363030303061ull,0x3432306363783020ull,
0x3009090a20303837ull,0x3132383430303278ull,0x3030303078302031ull,0x6278302033303030ull,
0x2064663530323930ull,0x3734383030367830ull,0x783009090a203863ull,0x3930363030303061ull,
0x3436306338783020ull,0x3064783020303837ull,0x3020643038306530ull,0x3837303063303878ull,
0x31783009090a2030ull,0x2031313432303030ull,0x3763303034327830ull,0x3031627830203038ull,
0x7830206430363030ull,0x3038376333303830ull,0x3031783009090a20ull,0x3020313130303030ull,
0x3836633034343278ull,0x3038306378302030ull,0x3078302064303630ull,0x2030383630303430ull,
0x393063783009090aull,0x7830203131383032ull,0x3038363030303030ull,0x3030303039783020ull,
0x3030783020353138ull,0x0a20303837303030ull,0x3030303178300909ull,0x3078302031313038ull,
0x2033303030386537ull,0x3238383030327830ull,0x3030307830203530ull,0x090a203330303030ull,
0x3035303063783009ull,0x3030783020643036ull,0x3020303837303030ull,0x6639303339306278ull,
0x3830303678302064ull,0x09090a2038633734ull,0x3230653030647830ull,0x6330387830203530ull,
0x7830203038373030ull,0x3531363030303061ull,0x3432306363783020ull,0x3009090a20303837ull,
0x3136323030303178ull,0x3030343278302031ull,0x6278302030383763ull,0x2064303230303031ull,
0x3730343038307830ull,0x783009090a203038ull,0x3530613030303061ull,0x3436306338783020ull,
0x3031783020303837ull,0x3020313130303030ull,0x3836633034343278ull,0x63783009090a2030ull,
0x2064303630303830ull,0x3630303430307830ull,0x3930637830203038ull,0x7830203131383033ull,
0x3038363030303030ull,0x3039783009090a20ull,0x3020303138303030ull,0x3136303430306378ull,
0x6633303178302030ull,0x3078302064303038ull,0x2066666666666666ull,0x303061783009090aull,
0x7830203131383030ull,0x3038373432306363ull,0x3863383032783020ull,0x3032783020343136ull,
0x0a20383136386238ull,0x3030306178300909ull,0x3878302031313830ull,0x2030383734363063ull,
0x3230363030337830ull,0x3034617830203931ull,0x090a203038373030ull,0x3035303033783009ull,
0x3461783020353038ull,0x3020303837303030ull,0x3163386163303478ull,0x6263303478302030ull,
0x09090a2034303238ull,0x3630303031327830ull,0x3034307830206430ull,0x7830203038373832ull,
0x3131323061383036ull,0x3031303038783020ull,0x3009090a20303837ull,0x3034303330303378ull,
0x3030346178302039ull,0x3378302030383730ull,0x2035303030333030ull,0x3730303134637830ull,
0x783009090a203038ull,0x3830383832303032ull,0x3830303031783020ull,0x3032783020633030ull,
0x3020313063633030ull,0x3837343032343078ull,0x64783009090a2030ull,0x2039303030653030ull,
0x3730303830617830ull,0x7d0a7d090a203138ull,0x000000000000000aull
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
0x78706d742f706d74ull,0x36303030305f7466ull,0x303030305f366632ull,0x5f33322d30303030ull,
0x656c636974726170ull,0x6c656e72656b5f73ull,0x20692e337070632eull,0x63632f706d742f28ull,
0x667038312e234942ull,0x2d2f2f090a294848ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
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
0x22093209656c6966ull,0x706d742f706d742full,0x303030305f746678ull,0x3030305f36663236ull,
0x32322d3030303030ull,0x6c6369747261705full,0x656e72656b5f7365ull,0x6566616475632e6cull,
0x090a227570672e32ull,0x093309656c69662eull,0x6c63697472617022ull,0x656e72656b5f7365ull,
0x090a226875632e6cull,0x093409656c69662eull,0x696c2f7273752f22ull,0x38782f6363672f62ull,
0x6e696c2d34365f36ull,0x342f756e672d7875ull,0x636e692f332e332eull,0x6474732f6564756cull,
0x090a22682e666564ull,0x093509656c69662eull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x65642f7472632f65ull,0x6e75725f65636976ull,
0x0a22682e656d6974ull,0x3609656c69662e09ull,0x2f656d6f682f2209ull,0x632f6c616d726f6eull,
0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x5f74736f682f6564ull,0x2e73656e69666564ull,
0x6c69662e090a2268ull,0x6f682f2209370965ull,0x616d726f6e2f656dull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x75622f6564756c63ull,0x79745f6e69746c69ull,0x090a22682e736570ull,
0x093809656c69662eull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x6563697665642f65ull,0x682e73657079745full,0x656c69662e090a22ull,
0x6d6f682f22093909ull,0x6c616d726f6e2f65ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x6972642f6564756cull,0x657079745f726576ull,0x662e090a22682e73ull,0x2209303109656c69ull,
0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x657275747865742full,0x682e73657079745full,0x656c69662e090a22ull,0x6f682f2209313109ull,
0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65762f6564756c63ull,
0x7079745f726f7463ull,0x2e090a22682e7365ull,0x09323109656c6966ull,0x6e2f656d6f682f22ull,
0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6563697665642f65ull,
0x5f68636e75616c5full,0x6574656d61726170ull,0x2e090a22682e7372ull,0x09333109656c6966ull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x74732f7472632f65ull,0x6c635f656761726full,0x090a22682e737361ull,0x343109656c69662eull,
0x692f7273752f2209ull,0x622f6564756c636eull,0x657079742f737469ull,0x662e090a22682e73ull,
0x2209353109656c69ull,0x636e692f7273752full,0x6d69742f6564756cull,0x662e090a22682e65ull,
0x2209363109656c69ull,0x656c636974726170ull,0x6c656e72656b5f73ull,0x662e090a2275632eull,
0x2209373109656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x5f6e6f6d6d6f632full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209383109656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x6e75662f7472632full,0x2e6f7263616d5f63ull,0x6c69662e090a2268ull,
0x682f220939310965ull,0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x6d2f6564756c636eull,0x636e75665f687461ull,0x22682e736e6f6974ull,0x09656c69662e090aull,
0x6d6f682f22093032ull,0x6c616d726f6e2f65ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x7665642f6564756cull,0x636e75665f656369ull,0x22682e736e6f6974ull,0x09656c69662e090aull,
0x6d6f682f22093132ull,0x6c616d726f6e2f65ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x74616d2f6564756cull,0x6174736e6f635f68ull,0x090a22682e73746eull,0x323209656c69662eull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x31315f6d732f6564ull,0x5f63696d6f74615full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209333209656c69ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x615f32315f6d732full,0x75665f63696d6f74ull,0x2e736e6f6974636eull,
0x6c69662e090a2268ull,0x682f220934320965ull,0x6d726f6e2f656d6full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x732f6564756c636eull,0x756f645f33315f6dull,0x636e75665f656c62ull,
0x22682e736e6f6974ull,0x09656c69662e090aull,0x6d6f682f22093532ull,0x6c616d726f6e2f65ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x7865742f6564756cull,0x7465665f65727574ull,
0x74636e75665f6863ull,0x0a22682e736e6f69ull,0x3209656c69662e09ull,0x656d6f682f220936ull,
0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,
0x6f6974636e75665full,0x705f6c62645f736eull,0x0a0a22682e337874ull,0x752e207865742e09ull,
0x6f50646c6f203436ull,0x2e090a3b78655473ull,0x3436752e20786574ull,0x546c6556646c6f20ull,
0x65742e090a3b7865ull,0x70203436752e2078ull,0x48656c6369747261ull,0x0a3b786554687361ull,
0x752e207865742e09ull,0x536c6c6563203436ull,0x3b78655474726174ull,0x2e207865742e090aull,
0x6469726720343675ull,0x737265746e756f43ull,0x742e090a3b786554ull,0x203436752e207865ull,
0x6c6c654364697267ull,0x2e090a3b78655473ull,0x612e2074736e6f63ull,0x203631206e67696cull,
0x617261702038622eull,0x3b5d3231315b736dull,0x72746e652e090a0aull,0x746e69395a5f2079ull,
0x3650657461726765ull,0x30533474616f6c66ull,0x665f30535f30535full,0x61702e09090a2820ull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x69395a5f5f6d7261ull,0x657461726765746eull,
0x3474616f6c663650ull,0x30535f30535f3053ull,0x6f5077656e5f665full,0x61702e09090a2c73ull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x69395a5f5f6d7261ull,0x657461726765746eull,
0x3474616f6c663650ull,0x30535f30535f3053ull,0x655677656e5f665full,0x61702e09090a2c6cull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x69395a5f5f6d7261ull,0x657461726765746eull,
0x3474616f6c663650ull,0x30535f30535f3053ull,0x6f50646c6f5f665full,0x61702e09090a2c73ull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x69395a5f5f6d7261ull,0x657461726765746eull,
0x3474616f6c663650ull,0x30535f30535f3053ull,0x6556646c6f5f665full,0x61702e09090a2c6cull,
0x3233662e206d6172ull,0x70616475635f5f20ull,0x69395a5f5f6d7261ull,0x657461726765746eull,
0x3474616f6c663650ull,0x30535f30535f3053ull,0x61746c65645f665full,0x7b090a29656d6954ull,
0x2e206765722e090aull,0x373c722520323375ull,0x6765722e090a3b3eull,0x7225203436752e20ull,
0x090a3b3e32313c64ull,0x33662e206765722eull,0x3e37343c66252032ull,0x206765722e090a3bull,
0x702520646572702eull,0x6c2e090a3b3e383cull,0x313609363109636full,0x3142424c240a3009ull,
0x65746e69395a5f5full,0x6636506574617267ull,0x5f30533474616f6cull,0x3a665f30535f3053ull,
0x3109636f6c2e090aull,0x090a300935360936ull,0x2e3233732e747663ull,0x3172250920363175ull,
0x646961746325202cull,0x2f092020203b782eull,0x2e747663090a202full,0x203631752e323373ull,
0x6e25202c32722509ull,0x20203b782e646974ull,0x090a202f2f092020ull,0x6f6c2e34326c756dull,
0x722509203233732eull,0x202c317225202c33ull,0x2f0920203b327225ull,0x2e747663090a202full,
0x203631752e323375ull,0x7425202c34722509ull,0x2020203b782e6469ull,0x090a202f2f092020ull,
0x203233752e646461ull,0x7225202c35722509ull,0x203b347225202c33ull,0x2f09202020202020ull,
0x2e747663090a202full,0x203233732e343675ull,0x25202c3164722509ull,0x20202020203b3572ull,
0x090a202f2f092020ull,0x752e6f6c2e6c756dull,0x3264722509203436ull,0x202c31647225202cull,
0x2f092020203b3631ull,0x702e646c090a202full,0x3436752e6d617261ull,0x202c336472250920ull,
0x70616475635f5f5bull,0x69395a5f5f6d7261ull,0x657461726765746eull,0x3474616f6c663650ull,
0x30535f30535f3053ull,0x6f50646c6f5f665full,0x69202f2f093b5d73ull,0x5f5f203436313a64ull,
0x6d72617061647563ull,0x65746e69395a5f5full,0x6636506574617267ull,0x5f30533474616f6cull,
0x5f665f30535f3053ull,0x302b736f50646c6full,0x2e646461090a3078ull,0x6472250920343675ull,
0x2c33647225202c34ull,0x20203b3264722520ull,0x090a202f2f092020ull,0x61626f6c672e646cull,
0x3233662e34762e6cull,0x252c3166257b0920ull,0x252c3366252c3266ull,0x72255b202c7d3466ull,
0x2f093b5d302b3464ull,0x636f6c2e090a202full,0x3009363609363109ull,0x7261702e646c090aull,
0x09203436752e6d61ull,0x5f5b202c35647225ull,0x726170616475635full,0x746e69395a5f5f6dull,
0x3650657461726765ull,0x30533474616f6c66ull,0x665f30535f30535full,0x5d6c6556646c6f5full,
0x3a6469202f2f093bull,0x75635f5f20393631ull,0x5f5f6d7261706164ull,0x726765746e69395aull,
0x6f6c663650657461ull,0x30535f3053347461ull,0x6c6f5f665f30535full,0x3078302b6c655664ull,
0x36752e646461090aull,0x2c36647225092034ull,0x25202c3564722520ull,0x202020203b326472ull,
0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x09203233662e3476ull,0x3666252c3566257bull,
0x3866252c3766252cull,0x366472255b202c7dull,0x202f2f093b5d302bull,0x3109636f6c2e090aull,
0x090a300931370936ull,0x6d617261702e646cull,0x662509203233662eull,0x75635f5f5b202c39ull,
0x5f5f6d7261706164ull,0x726765746e69395aull,0x6f6c663650657461ull,0x30535f3053347461ull,
0x65645f665f30535full,0x5d656d695461746cull,0x3a6469202f2f093bull,0x75635f5f20303631ull,
0x5f5f6d7261706164ull,0x726765746e69395aull,0x6f6c663650657461ull,0x30535f3053347461ull,
0x65645f665f30535full,0x2b656d695461746cull,0x2e646c090a307830ull,0x33662e74736e6f63ull,
0x2c30316625092032ull,0x736d617261705b20ull,0x2f2f093b5d30322bull,0x203437313a646920ull,
0x302b736d61726170ull,0x6c756d090a343178ull,0x662509203233662eull,0x30316625202c3131ull,
0x20203b396625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c323166250920ull,
0x6625202c31316625ull,0x0920202020203b35ull,0x2e646c090a202f2full,0x33662e74736e6f63ull,
0x2c33316625092032ull,0x736d617261705b20ull,0x2f2f093b5d32332bull,0x203935313a646920ull,
0x302b736d61726170ull,0x6c756d090a303278ull,0x662509203233662eull,0x32316625202c3431ull,
0x203b33316625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c353166250920ull,
0x2020203b34316625ull,0x0920202020202020ull,0x2e646c090a202f2full,0x33662e74736e6f63ull,
0x2c36316625092032ull,0x736d617261705b20ull,0x2f2f093b5d34322bull,0x203537313a646920ull,
0x302b736d61726170ull,0x6c756d090a383178ull,0x662509203233662eull,0x36316625202c3731ull,
0x20203b396625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c383166250920ull,
0x6625202c37316625ull,0x0920202020203b36ull,0x6c756d090a202f2full,0x662509203233662eull,
0x38316625202c3931ull,0x203b33316625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c303266250920ull,0x2020203b39316625ull,0x0920202020202020ull,0x2e646c090a202f2full,
0x33662e74736e6f63ull,0x2c31326625092032ull,0x736d617261705b20ull,0x2f2f093b5d38322bull,
0x203637313a646920ull,0x302b736d61726170ull,0x6c756d090a633178ull,0x662509203233662eull,
0x31326625202c3232ull,0x20203b396625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c333266250920ull,0x6625202c32326625ull,0x0920202020203b37ull,0x6c756d090a202f2full,
0x662509203233662eull,0x33326625202c3432ull,0x203b33316625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c353266250920ull,0x2020203b34326625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x0934370936310963ull,0x662e6c756d090a30ull,0x3632662509203233ull,
0x202c34316625202cull,0x202020203b396625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x6625202c37326625ull,0x3b316625202c3632ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,
0x3832662509203233ull,0x203b37326625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233662e6c75ull,0x6625202c39326625ull,0x3b396625202c3931ull,0x2f2f092020202020ull,
0x662e646461090a20ull,0x3033662509203233ull,0x202c39326625202cull,0x202020203b326625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c31336625ull,0x20202020203b3033ull,
0x2f2f092020202020ull,0x662e6c756d090a20ull,0x3233662509203233ull,0x202c34326625202cull,
0x202020203b396625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c33336625ull,
0x3b336625202c3233ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3433662509203233ull,
0x203b33336625202cull,0x2020202020202020ull,0x6c090a202f2f0920ull,0x2e74736e6f632e64ull,
0x3366250920323366ull,0x617261705b202c35ull,0x093b5d36332b736dull,0x35313a6469202f2full,
0x736d617261702038ull,0x6d090a343278302bull,0x09203233662e766full,0x6630202c36336625ull,
0x3030303030386633ull,0x2f2f09202020203bull,0x2e627573090a3120ull,0x3366250920323366ull,
0x2c36336625202c37ull,0x20203b3533662520ull,0x090a202f2f092020ull,0x2e746c2e70746573ull,
0x3170250920323366ull,0x202c37336625202cull,0x2f09203b37326625ull,0x70252140090a202full,
0x2409206172622031ull,0x3638345f305f744cull,0x2020202020203b36ull,0x090a202f2f092020ull,
0x09363109636f6c2eull,0x6f6d090a30093737ull,0x2509203233662e76ull,0x336625202c383266ull,
0x2020202020203b37ull,0x202f2f0920202020ull,0x6e6f632e646c090aull,0x09203233662e7473ull,
0x705b202c38336625ull,0x30312b736d617261ull,0x69202f2f093b5d34ull,0x6170203737313a64ull,
0x3678302b736d6172ull,0x662e6c756d090a38ull,0x3531662509203233ull,0x202c38336625202cull,
0x2020203b34316625ull,0x4c240a202f2f0920ull,0x363638345f305f74ull,0x662e766f6d090a3aull,
0x3933662509203233ull,0x303866626630202cull,0x2020203b30303030ull,0x0a312d202f2f0920ull,
0x3233662e64646109ull,0x202c303466250920ull,0x6625202c35336625ull,0x09202020203b3933ull,
0x746573090a202f2full,0x3233662e74672e70ull,0x25202c3270250920ull,0x326625202c303466ull,
0x0a202f2f09203b38ull,0x6220327025214009ull,0x5f744c2409206172ull,0x203b383733355f30ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x0938370936310963ull,0x662e766f6d090a30ull,
0x3832662509203233ull,0x203b30346625202cull,0x2020202020202020ull,0x6c090a202f2f0920ull,
0x2e74736e6f632e64ull,0x3466250920323366ull,0x617261705b202c31ull,0x3b5d3430312b736dull,
0x313a6469202f2f09ull,0x6d61726170203737ull,0x090a383678302b73ull,0x203233662e6c756dull,
0x25202c3531662509ull,0x316625202c313466ull,0x2f09202020203b35ull,0x305f744c240a202full,
0x090a3a383733355full,0x2e746c2e70746573ull,0x3370250920323366ull,0x202c37336625202cull,
0x2f09203b30336625ull,0x70252140090a202full,0x2409206172622033ull,0x3938355f305f744cull,
0x2020202020203b30ull,0x090a202f2f092020ull,0x09363109636f6c2eull,0x6f6d090a30093937ull,
0x2509203233662e76ull,0x336625202c313366ull,0x2020202020203b37ull,0x202f2f0920202020ull,
0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c32346625ull,0x30312b736d617261ull,
0x69202f2f093b5d34ull,0x6170203737313a64ull,0x3678302b736d6172ull,0x662e6c756d090a38ull,
0x3032662509203233ull,0x202c32346625202cull,0x2020203b39316625ull,0x4c240a202f2f0920ull,
0x303938355f305f74ull,0x2e70746573090a3aull,0x09203233662e7467ull,0x346625202c347025ull,
0x3b31336625202c30ull,0x40090a202f2f0920ull,0x6172622034702521ull,0x5f305f744c240920ull,
0x2020203b32303436ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x0a30093038093631ull,
0x3233662e766f6d09ull,0x202c313366250920ull,0x2020203b30346625ull,0x0920202020202020ull,
0x2e646c090a202f2full,0x33662e74736e6f63ull,0x2c33346625092032ull,0x736d617261705b20ull,
0x2f093b5d3430312bull,0x3737313a6469202full,0x2b736d6172617020ull,0x756d090a38367830ull,
0x2509203233662e6cull,0x346625202c303266ull,0x3b30326625202c33ull,0x202f2f0920202020ull,
0x365f305f744c240aull,0x6573090a3a323034ull,0x33662e746c2e7074ull,0x202c357025092032ull,
0x6625202c37336625ull,0x202f2f09203b3333ull,0x203570252140090aull,0x744c240920617262ull,
0x3b343139365f305full,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x313809363109636full,
0x2e766f6d090a3009ull,0x3366250920323366ull,0x3b37336625202c34ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x74736e6f632e646cull,0x662509203233662eull,0x7261705b202c3434ull,
0x5d3430312b736d61ull,0x3a6469202f2f093bull,0x6172617020373731ull,0x0a383678302b736dull,
0x3233662e6c756d09ull,0x202c353266250920ull,0x6625202c34346625ull,0x09202020203b3432ull,
0x5f744c240a202f2full,0x0a3a343139365f30ull,0x74672e7074657309ull,0x702509203233662eull,
0x2c30346625202c36ull,0x09203b3433662520ull,0x252140090a202f2full,0x0920617262203670ull,
0x34375f305f744c24ull,0x20202020203b3632ull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,
0x6d090a3009323809ull,0x09203233662e766full,0x6625202c34336625ull,0x20202020203b3034ull,
0x2f2f092020202020ull,0x6f632e646c090a20ull,0x203233662e74736eull,0x5b202c3534662509ull,
0x312b736d61726170ull,0x202f2f093b5d3430ull,0x70203737313a6469ull,0x78302b736d617261ull,
0x2e6c756d090a3836ull,0x3266250920323366ull,0x2c35346625202c35ull,0x20203b3532662520ull,
0x240a202f2f092020ull,0x3234375f305f744cull,0x636f6c2e090a3a36ull,0x3009353809363109ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c37647225ull,0x726170616475635full,
0x746e69395a5f5f6dull,0x3650657461726765ull,0x30533474616f6c66ull,0x665f30535f30535full,
0x5d736f5077656e5full,0x3a6469202f2f093bull,0x75635f5f20383731ull,0x5f5f6d7261706164ull,
0x726765746e69395aull,0x6f6c663650657461ull,0x30535f3053347461ull,0x656e5f665f30535full,
0x3078302b736f5077ull,0x36752e646461090aull,0x2c38647225092034ull,0x25202c3764722520ull,
0x202020203b326472ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,0x09203233662e3476ull,
0x5d302b386472255bull,0x2c383266257b202cull,0x3366252c31336625ull,0x093b7d3466252c34ull,
0x6f6c2e090a202f2full,0x0936380936310963ull,0x61702e646c090a30ull,0x203436752e6d6172ull,
0x5b202c3964722509ull,0x6170616475635f5full,0x6e69395a5f5f6d72ull,0x5065746172676574ull,
0x533474616f6c6636ull,0x5f30535f30535f30ull,0x6c655677656e5f66ull,0x6469202f2f093b5dull,
0x635f5f203338313aull,0x5f6d726170616475ull,0x6765746e69395a5full,0x6c66365065746172ull,
0x535f30533474616full,0x6e5f665f30535f30ull,0x78302b6c65567765ull,0x752e646461090a30ull,
0x3164722509203436ull,0x2c39647225202c30ull,0x20203b3264722520ull,0x73090a202f2f0920ull,
0x6c61626f6c672e74ull,0x203233662e34762eull,0x2b30316472255b09ull,0x3166257b202c5d30ull,
0x252c303266252c35ull,0x7d3866252c353266ull,0x2e090a202f2f093bull,0x3809363109636f6cull,
0x697865090a300937ull,0x2020202020203b74ull,0x2020202020202020ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x5f646e6557444c24ull,0x6765746e69395a5full,0x6c66365065746172ull,
0x535f30533474616full,0x0a3a665f30535f30ull,0x5a5f202f2f207d09ull,0x61726765746e6939ull,
0x616f6c6636506574ull,0x5f30535f30533474ull,0x2e090a0a665f3053ull,0x5a5f207972746e65ull,
0x6574616470753131ull,0x6636504464697247ull,0x536a503474616f6cull,0x2e09090a28205f31ull,
0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x6574616470753131ull,
0x6636504464697247ull,0x536a503474616f6cull,0x0a2c736f705f5f31ull,0x6d617261702e0909ull,
0x5f5f203436752e20ull,0x6d72617061647563ull,0x64707531315a5f5full,0x4464697247657461ull,
0x3474616f6c663650ull,0x72675f5f31536a50ull,0x65746e756f436469ull,0x702e09090a2c7372ull,
0x36752e206d617261ull,0x616475635f5f2034ull,0x315a5f5f6d726170ull,0x4765746164707531ull,
0x6c66365044646972ull,0x31536a503474616full,0x6543646972675f5full,0x0a7b090a29736c6cull,
0x752e206765722e09ull,0x31333c7225203233ull,0x6765722e090a3b3eull,0x7225203436752e20ull,
0x090a3b3e34313c64ull,0x33662e206765722eull,0x3e31333c66252032ull,0x206765722e090a3bull,
0x702520646572702eull,0x6c2e090a3b3e353cull,0x333109363109636full,0x42424c240a300934ull,
0x707531315a5f5f31ull,0x6469724765746164ull,0x74616f6c66365044ull,0x0a3a5f31536a5034ull,
0x303209636f6c2e09ull,0x0a30093439363409ull,0x3233732e74766309ull,0x722509203631752eull,
0x6961746325202c31ull,0x092020203b782e64ull,0x747663090a202f2full,0x3631752e3233732eull,
0x25202c3272250920ull,0x203b782e6469746eull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x2c317225202c3372ull,0x0920203b32722520ull,0x747663090a202f2full,
0x3631752e3233752eull,0x25202c3472250920ull,0x20203b782e646974ull,0x0a202f2f09202020ull,
0x3233752e64646109ull,0x25202c3572250920ull,0x3b347225202c3372ull,0x0920202020202020ull,
0x2e646c090a202f2full,0x36752e6d61726170ull,0x2c31647225092034ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x4765746164707531ull,0x6c66365044646972ull,0x31536a503474616full,
0x093b5d736f705f5full,0x35393a6469202f2full,0x70616475635f5f20ull,0x31315a5f5f6d7261ull,
0x7247657461647075ull,0x6f6c663650446469ull,0x5f31536a50347461ull,0x3078302b736f705full,
0x36752e747663090aull,0x2509203233732e34ull,0x357225202c326472ull,0x202020202020203bull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x202c336472250920ull,0x3631202c32647225ull,
0x202f2f092020203bull,0x36752e646461090aull,0x2c34647225092034ull,0x25202c3164722520ull,
0x202020203b336472ull,0x646c090a202f2f09ull,0x2e6c61626f6c672eull,0x3166250920323366ull,
0x2b346472255b202cull,0x202f2f09203b5d30ull,0x6c090a36393a6469ull,0x2e74736e6f632e64ull,
0x3266250920323366ull,0x6d617261705b202cull,0x2f093b5d36352b73ull,0x2037393a6469202full,
0x302b736d61726170ull,0x627573090a383378ull,0x662509203233662eull,0x202c316625202c33ull,
0x202020203b326625ull,0x0a202f2f09202020ull,0x736e6f632e646c09ull,0x2509203233662e74ull,
0x7261705b202c3466ull,0x3b5d38362b736d61ull,0x393a6469202f2f09ull,0x736d617261702038ull,
0x6d090a343478302bull,0x09203233662e766full,0x346625202c356625ull,0x202020202020203bull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x0936313634093032ull,0x662e736261090a30ull,
0x2c36662509203233ull,0x2020203b34662520ull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x376630202c376625ull,0x3b30303030303865ull,0x2f2f092020202020ull,
0x36303730352e3820ull,0x6573090a37332b65ull,0x33662e74672e7074ull,0x202c317025092032ull,
0x376625202c366625ull,0x202f2f092020203bull,0x203170252140090aull,0x744c240920617262ull,
0x3b323635325f315full,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x363409303209636full,
0x6f6d090a30093731ull,0x2509203233662e76ull,0x65336630202c3866ull,0x203b303030303038ull,
0x202f2f0920202020ull,0x756d090a35322e30ull,0x2509203233662e6cull,0x2c336625202c3366ull,
0x2020203b38662520ull,0x202f2f0920202020ull,0x3209636f6c2e090aull,0x3009383136340930ull,
0x33662e766f6d090aull,0x202c396625092032ull,0x3030303865336630ull,0x20202020203b3030ull,
0x35322e30202f2f09ull,0x33662e6c756d090aull,0x202c356625092032ull,0x396625202c346625ull,
0x202020202020203bull,0x744c240a202f2f09ull,0x3a323635325f315full,0x3109636f6c2e090aull,
0x090a300933390936ull,0x727070612e766964ull,0x09203233662e786full,0x6625202c30316625ull,
0x093b356625202c33ull,0x747663090a202f2full,0x3233662e696d722eull,0x662509203233662eull,
0x30316625202c3131ull,0x0a202f2f0920203bull,0x697a722e74766309ull,0x3233662e3233732eull,
0x25202c3672250920ull,0x092020203b313166ull,0x6f6c2e090a202f2full,0x3936340930320963ull,
0x2e646c090a300934ull,0x662e6c61626f6c67ull,0x3231662509203233ull,0x2b346472255b202cull,
0x69202f2f093b5d34ull,0x646c090a39393a64ull,0x662e74736e6f632eull,0x3331662509203233ull,
0x6d617261705b202cull,0x2f093b5d30362b73ull,0x3030313a6469202full,0x2b736d6172617020ull,
0x7573090a63337830ull,0x2509203233662e62ull,0x32316625202c3366ull,0x203b33316625202cull,
0x202f2f0920202020ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c34316625ull,
0x32372b736d617261ull,0x6469202f2f093b5dull,0x726170203130313aull,0x383478302b736d61ull,
0x33662e766f6d090aull,0x202c356625092032ull,0x2020203b34316625ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x363409303209636full,0x6261090a30093631ull,0x2509203233662e73ull,
0x316625202c353166ull,0x2020202020203b34ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c36316625092032ull,0x3030386537663020ull,0x202020203b303030ull,0x30352e38202f2f09ull,
0x0a37332b65363037ull,0x74672e7074657309ull,0x702509203233662eull,0x2c35316625202c32ull,
0x09203b3631662520ull,0x252140090a202f2full,0x0920617262203270ull,0x30335f315f744c24ull,
0x20202020203b3437ull,0x0a202f2f09202020ull,0x303209636f6c2e09ull,0x0a30093731363409ull,
0x3233662e766f6d09ull,0x202c373166250920ull,0x3030303865336630ull,0x09202020203b3030ull,
0x0a35322e30202f2full,0x3233662e6c756d09ull,0x25202c3366250920ull,0x37316625202c3366ull,
0x092020202020203bull,0x6f6c2e090a202f2full,0x3136340930320963ull,0x766f6d090a300938ull,
0x662509203233662eull,0x65336630202c3831ull,0x203b303030303038ull,0x30202f2f09202020ull,
0x6c756d090a35322eull,0x662509203233662eull,0x2c34316625202c35ull,0x20203b3831662520ull,
0x0a202f2f09202020ull,0x30335f315f744c24ull,0x6f6c2e090a3a3437ull,0x0934390936310963ull,
0x612e766964090a30ull,0x33662e786f727070ull,0x2c39316625092032ull,0x6625202c33662520ull,
0x090a202f2f093b35ull,0x2e696d722e747663ull,0x203233662e323366ull,0x25202c3032662509ull,
0x2f0920203b393166ull,0x2e747663090a202full,0x2e3233732e697a72ull,0x3772250920323366ull,
0x203b30326625202cull,0x090a202f2f092020ull,0x09303209636f6c2eull,0x090a300934393634ull,
0x61626f6c672e646cull,0x2509203233662e6cull,0x72255b202c313266ull,0x2f093b5d382b3464ull,
0x3230313a6469202full,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c32326625ull,
0x34362b736d617261ull,0x6469202f2f093b5dull,0x726170203330313aull,0x303478302b736d61ull,
0x33662e627573090aull,0x202c336625092032ull,0x6625202c31326625ull,0x20202020203b3232ull,
0x646c090a202f2f09ull,0x662e74736e6f632eull,0x3332662509203233ull,0x6d617261705b202cull,
0x2f093b5d36372b73ull,0x3430313a6469202full,0x2b736d6172617020ull,0x6f6d090a63347830ull,
0x2509203233662e76ull,0x33326625202c3566ull,0x202020202020203bull,0x202f2f0920202020ull,
0x3209636f6c2e090aull,0x3009363136340930ull,0x33662e736261090aull,0x2c34326625092032ull,
0x20203b3332662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x376630202c353266ull,0x3b30303030303865ull,0x202f2f0920202020ull,0x6536303730352e38ull,
0x746573090a37332bull,0x3233662e74672e70ull,0x25202c3370250920ull,0x326625202c343266ull,
0x0a202f2f09203b35ull,0x6220337025214009ull,0x5f744c2409206172ull,0x203b363835335f31ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3136340930320963ull,0x766f6d090a300937ull,
0x662509203233662eull,0x65336630202c3632ull,0x203b303030303038ull,0x30202f2f09202020ull,
0x6c756d090a35322eull,0x662509203233662eull,0x202c336625202c33ull,0x2020203b36326625ull,
0x0a202f2f09202020ull,0x303209636f6c2e09ull,0x0a30093831363409ull,0x3233662e766f6d09ull,
0x202c373266250920ull,0x3030303865336630ull,0x09202020203b3030ull,0x0a35322e30202f2full,
0x3233662e6c756d09ull,0x25202c3566250920ull,0x326625202c333266ull,0x0920202020203b37ull,
0x5f744c240a202f2full,0x0a3a363835335f31ull,0x363109636f6c2e09ull,0x090a300931323109ull,
0x727070612e766964ull,0x09203233662e786full,0x6625202c38326625ull,0x093b356625202c33ull,
0x2e646c090a202f2full,0x33752e74736e6f63ull,0x202c387225092032ull,0x2b736d617261705bull,
0x202f2f093b5d3434ull,0x61702031393a6469ull,0x3278302b736d6172ull,0x752e627573090a63ull,
0x2c39722509203233ull,0x3b31202c38722520ull,0x2020202020202020ull,0x6c090a202f2f0920ull,
0x2e74736e6f632e64ull,0x3172250920323375ull,0x617261705b202c30ull,0x093b5d38342b736dull,
0x30313a6469202f2full,0x736d617261702035ull,0x73090a303378302bull,0x09203233752e6275ull,
0x7225202c31317225ull,0x20203b31202c3031ull,0x2f2f092020202020ull,0x6f632e646c090a20ull,
0x203233752e74736eull,0x5b202c3231722509ull,0x342b736d61726170ull,0x69202f2f093b5d30ull,
0x7261702030393a64ull,0x383278302b736d61ull,0x33752e627573090aull,0x2c33317225092032ull,
0x31202c3231722520ull,0x202020202020203bull,0x7663090a202f2f09ull,0x33662e696d722e74ull,
0x2509203233662e32ull,0x326625202c393266ull,0x202f2f0920203b38ull,0x33752e6e696d090aull,
0x2c34317225092032ull,0x7225202c37722520ull,0x2020202020203b39ull,0x696d090a202f2f09ull,
0x2509203233752e6eull,0x367225202c353172ull,0x203b33317225202cull,0x202f2f0920202020ull,
0x7a722e747663090aull,0x33662e3233732e69ull,0x2c36317225092032ull,0x20203b3932662520ull,
0x756d090a202f2f09ull,0x732e6f6c2e34326cull,0x3731722509203233ull,0x202c34317225202cull,
0x2f2f093b32317225ull,0x752e6e696d090a20ull,0x3831722509203233ull,0x202c36317225202cull,
0x2020203b31317225ull,0x6d090a202f2f0920ull,0x2e6f6c2e34326c75ull,0x3172250920323373ull,
0x2c38317225202c39ull,0x2f2f093b38722520ull,0x34326c756d090a20ull,0x203233732e6f6c2eull,
0x25202c3032722509ull,0x317225202c393172ull,0x090a202f2f093b32ull,0x203233732e646461ull,
0x25202c3132722509ull,0x327225202c373172ull,0x2f09202020203b30ull,0x2e646461090a202full,
0x3272250920323373ull,0x2c31327225202c32ull,0x20203b3531722520ull,0x090a202f2f092020ull,
0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3564ull,0x5f6d726170616475ull,
0x6164707531315a5full,0x5044646972476574ull,0x503474616f6c6636ull,0x6972675f5f31536aull,
0x7265746e756f4364ull,0x69202f2f093b5d73ull,0x5f5f203630313a64ull,0x6d72617061647563ull,
0x64707531315a5f5full,0x4464697247657461ull,0x3474616f6c663650ull,0x72675f5f31536a50ull,
0x65746e756f436469ull,0x090a3078302b7372ull,0x2e3436752e747663ull,0x6472250920323375ull,
0x3b32327225202c36ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x7225202c37647225ull,0x20203b34202c3664ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x25202c3864722509ull,0x647225202c356472ull,0x2f09202020203b37ull,0x2e766f6d090a202full,
0x3272250920323375ull,0x2020203b31202c33ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x6f6c672e6d6f7461ull,0x2e6464612e6c6162ull,0x7672250920323375ull,0x386472255b202c31ull,
0x3b33327225202c5dull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x767225202c343272ull,
0x2020202020203b31ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093632310936ull,
0x736e6f632e646c09ull,0x2509203233752e74ull,0x61705b202c353272ull,0x5d34382b736d6172ull,
0x3a6469202f2f093bull,0x6d61726170203938ull,0x090a343578302b73ull,0x6d617261702e646cull,
0x722509203436752eull,0x635f5f5b202c3964ull,0x5f6d726170616475ull,0x6164707531315a5full,
0x5044646972476574ull,0x503474616f6c6636ull,0x6972675f5f31536aull,0x3b5d736c6c654364ull,
0x313a6469202f2f09ull,0x6475635f5f203730ull,0x5a5f5f6d72617061ull,0x6574616470753131ull,
0x6636504464697247ull,0x536a503474616f6cull,0x43646972675f5f31ull,0x3078302b736c6c65ull,
0x33752e627573090aull,0x2c36327225092032ull,0x31202c3532722520ull,0x202020202020203bull,
0x696d090a202f2f09ull,0x2509203233752e6eull,0x327225202c373272ull,0x3b36327225202c34ull,
0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x32327225202c3832ull,
0x203b35327225202cull,0x6461090a202f2f09ull,0x2509203233752e64ull,0x327225202c393272ull,
0x3b38327225202c37ull,0x202f2f0920202020ull,0x36752e747663090aull,0x2509203233752e34ull,
0x7225202c30316472ull,0x20202020203b3932ull,0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,
0x2c31316472250920ull,0x202c303164722520ull,0x202f2f0920203b34ull,0x36752e646461090aull,
0x3231647225092034ull,0x202c39647225202cull,0x20203b3131647225ull,0x7473090a202f2f09ull,
0x2e6c61626f6c672eull,0x72255b0920323375ull,0x202c5d302b323164ull,0x202f2f093b357225ull,
0x090a3830313a6469ull,0x09363109636f6c2eull,0x65090a3009333431ull,0x202020203b746978ull,
0x2020202020202020ull,0x2020202020202020ull,0x2f2f092020202020ull,0x6e6557444c240a20ull,
0x707531315a5f5f64ull,0x6469724765746164ull,0x74616f6c66365044ull,0x0a3a5f31536a5034ull,
0x5a5f202f2f207d09ull,0x6574616470753131ull,0x6636504464697247ull,0x536a503474616f6cull,
0x6e652e090a0a5f31ull,0x63395a5f20797274ull,0x4468736148636c61ull,0x3474616f6c663650ull,
0x2032746e69753550ull,0x7261702e09090a28ull,0x203436752e206d61ull,0x6170616475635f5full,
0x6163395a5f5f6d72ull,0x504468736148636cull,0x503474616f6c6636ull,0x705f32746e697535ull,
0x702e09090a2c736full,0x36752e206d617261ull,0x616475635f5f2034ull,0x395a5f5f6d726170ull,
0x68736148636c6163ull,0x74616f6c66365044ull,0x32746e6975355034ull,0x6c6369747261705full,
0x090a296873614865ull,0x206765722e090a7bull,0x3c7225203233752eull,0x722e090a3b3e3432ull,
0x203436752e206765ull,0x0a3b3e393c647225ull,0x662e206765722e09ull,0x31333c6625203233ull,
0x6765722e090a3b3eull,0x2520646572702e20ull,0x2e090a3b3e353c70ull,0x3109363109636f6cull,
0x424c240a30093834ull,0x6163395a5f5f3142ull,0x504468736148636cull,0x503474616f6c6636ull,
0x0a3a32746e697535ull,0x303209636f6c2e09ull,0x0a30093439363409ull,0x3233732e74766309ull,
0x722509203631752eull,0x6961746325202c31ull,0x092020203b782e64ull,0x747663090a202f2full,
0x3631752e3233732eull,0x25202c3272250920ull,0x203b782e6469746eull,0x0a202f2f09202020ull,
0x6c2e34326c756d09ull,0x2509203233732e6full,0x2c317225202c3372ull,0x0920203b32722520ull,
0x747663090a202f2full,0x3631752e3233752eull,0x25202c3472250920ull,0x20203b782e646974ull,
0x0a202f2f09202020ull,0x3233752e64646109ull,0x25202c3572250920ull,0x3b347225202c3372ull,
0x0920202020202020ull,0x747663090a202f2full,0x3233732e3436752eull,0x202c316472250920ull,
0x202020203b357225ull,0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5f5b202c326472ull,0x6d72617061647563ull,0x636c6163395a5f5full,0x6636504468736148ull,
0x7535503474616f6cull,0x736f705f32746e69ull,0x6469202f2f093b5dull,0x75635f5f2039383aull,
0x5f5f6d7261706164ull,0x6148636c6163395aull,0x6f6c663650446873ull,0x6e69753550347461ull,
0x302b736f705f3274ull,0x2e6c756d090a3078ull,0x09203436752e6f6cull,0x7225202c33647225ull,
0x203b3631202c3164ull,0x090a202f2f092020ull,0x203436752e646461ull,0x25202c3464722509ull,
0x647225202c326472ull,0x2f09202020203b33ull,0x672e646c090a202full,0x33662e6c61626f6cull,
0x202c316625092032ull,0x5d302b346472255bull,0x6469202f2f09203bull,0x2e646c090a30393aull,
0x33662e74736e6f63ull,0x202c326625092032ull,0x2b736d617261705bull,0x202f2f093b5d3635ull,
0x61702031393a6469ull,0x3378302b736d6172ull,0x662e627573090a38ull,0x2c33662509203233ull,
0x6625202c31662520ull,0x2020202020203b32ull,0x6c090a202f2f0920ull,0x2e74736e6f632e64ull,
0x3466250920323366ull,0x6d617261705b202cull,0x2f093b5d38362b73ull,0x2032393a6469202full,
0x302b736d61726170ull,0x766f6d090a343478ull,0x662509203233662eull,0x203b346625202c35ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x303209636f6c2e09ull,0x0a30093631363409ull,
0x3233662e73626109ull,0x25202c3666250920ull,0x20202020203b3466ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x662509203233662eull,0x3865376630202c37ull,0x20203b3030303030ull,
0x38202f2f09202020ull,0x2b6536303730352eull,0x70746573090a3733ull,0x203233662e74672eull,
0x6625202c31702509ull,0x203b376625202c36ull,0x090a202f2f092020ull,0x7262203170252140ull,
0x325f744c24092061ull,0x20203b323635325full,0x2f09202020202020ull,0x636f6c2e090a202full,
0x3731363409303209ull,0x2e766f6d090a3009ull,0x3866250920323366ull,0x303865336630202cull,
0x2020203b30303030ull,0x2e30202f2f092020ull,0x2e6c756d090a3532ull,0x3366250920323366ull,
0x25202c336625202cull,0x20202020203b3866ull,0x090a202f2f092020ull,0x09303209636f6c2eull,
0x090a300938313634ull,0x203233662e766f6dull,0x6630202c39662509ull,0x3030303030386533ull,
0x2f0920202020203bull,0x090a35322e30202full,0x203233662e6c756dull,0x6625202c35662509ull,
0x203b396625202c34ull,0x2f09202020202020ull,0x325f744c240a202full,0x090a3a323635325full,
0x09363109636f6c2eull,0x6964090a30093339ull,0x786f727070612e76ull,0x662509203233662eull,
0x2c336625202c3031ull,0x2f2f093b35662520ull,0x722e747663090a20ull,0x662e3233662e696dull,
0x3131662509203233ull,0x203b30316625202cull,0x63090a202f2f0920ull,0x732e697a722e7476ull,
0x09203233662e3233ull,0x316625202c367225ull,0x2f2f092020203b31ull,0x09636f6c2e090a20ull,
0x0934393634093032ull,0x6c672e646c090a30ull,0x3233662e6c61626full,0x202c323166250920ull,
0x5d342b346472255bull,0x3a6469202f2f093bull,0x632e646c090a3339ull,0x3233662e74736e6full,
0x202c333166250920ull,0x2b736d617261705bull,0x202f2f093b5d3036ull,0x61702034393a6469ull,
0x3378302b736d6172ull,0x662e627573090a63ull,0x2c33662509203233ull,0x25202c3231662520ull,
0x202020203b333166ull,0x6c090a202f2f0920ull,0x2e74736e6f632e64ull,0x3166250920323366ull,
0x617261705b202c34ull,0x093b5d32372b736dull,0x35393a6469202f2full,0x2b736d6172617020ull,
0x6f6d090a38347830ull,0x2509203233662e76ull,0x34316625202c3566ull,0x202020202020203bull,
0x202f2f0920202020ull,0x3209636f6c2e090aull,0x3009363136340930ull,0x33662e736261090aull,
0x2c35316625092032ull,0x20203b3431662520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x376630202c363166ull,0x3b30303030303865ull,0x202f2f0920202020ull,
0x6536303730352e38ull,0x746573090a37332bull,0x3233662e74672e70ull,0x25202c3270250920ull,
0x316625202c353166ull,0x0a202f2f09203b36ull,0x6220327025214009ull,0x5f744c2409206172ull,
0x203b343730335f32ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3136340930320963ull,
0x766f6d090a300937ull,0x662509203233662eull,0x65336630202c3731ull,0x203b303030303038ull,
0x30202f2f09202020ull,0x6c756d090a35322eull,0x662509203233662eull,0x202c336625202c33ull,
0x2020203b37316625ull,0x0a202f2f09202020ull,0x303209636f6c2e09ull,0x0a30093831363409ull,
0x3233662e766f6d09ull,0x202c383166250920ull,0x3030303865336630ull,0x09202020203b3030ull,
0x0a35322e30202f2full,0x3233662e6c756d09ull,0x25202c3566250920ull,0x316625202c343166ull,
0x0920202020203b38ull,0x5f744c240a202f2full,0x0a3a343730335f32ull,0x363109636f6c2e09ull,
0x64090a3009343909ull,0x6f727070612e7669ull,0x2509203233662e78ull,0x336625202c393166ull,
0x2f093b356625202cull,0x2e747663090a202full,0x2e3233662e696d72ull,0x3266250920323366ull,
0x3b39316625202c30ull,0x090a202f2f092020ull,0x2e697a722e747663ull,0x203233662e323373ull,
0x6625202c37722509ull,0x2f092020203b3032ull,0x636f6c2e090a202full,0x3439363409303209ull,
0x672e646c090a3009ull,0x33662e6c61626f6cull,0x2c31326625092032ull,0x382b346472255b20ull,
0x6469202f2f093b5dull,0x2e646c090a36393aull,0x33662e74736e6f63ull,0x2c32326625092032ull,
0x736d617261705b20ull,0x2f2f093b5d34362bull,0x702037393a646920ull,0x78302b736d617261ull,
0x2e627573090a3034ull,0x3366250920323366ull,0x202c31326625202cull,0x2020203b32326625ull,
0x090a202f2f092020ull,0x74736e6f632e646cull,0x662509203233662eull,0x7261705b202c3332ull,
0x3b5d36372b736d61ull,0x393a6469202f2f09ull,0x736d617261702038ull,0x6d090a633478302bull,
0x09203233662e766full,0x326625202c356625ull,0x2020202020203b33ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x0936313634093032ull,0x662e736261090a30ull,0x3432662509203233ull,
0x203b33326625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c35326625ull,0x3030303030386537ull,0x2f2f09202020203bull,0x36303730352e3820ull,
0x6573090a37332b65ull,0x33662e74672e7074ull,0x202c337025092032ull,0x6625202c34326625ull,
0x202f2f09203b3532ull,0x203370252140090aull,0x744c240920617262ull,0x3b363835335f325full,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x363409303209636full,0x6f6d090a30093731ull,
0x2509203233662e76ull,0x336630202c363266ull,0x3b30303030303865ull,0x202f2f0920202020ull,
0x756d090a35322e30ull,0x2509203233662e6cull,0x2c336625202c3366ull,0x20203b3632662520ull,
0x202f2f0920202020ull,0x3209636f6c2e090aull,0x3009383136340930ull,0x33662e766f6d090aull,
0x2c37326625092032ull,0x3030386533663020ull,0x202020203b303030ull,0x35322e30202f2f09ull,
0x33662e6c756d090aull,0x202c356625092032ull,0x6625202c33326625ull,0x20202020203b3732ull,
0x744c240a202f2f09ull,0x3a363835335f325full,0x3109636f6c2e090aull,0x0a30093835310936ull,
0x617261702e646c09ull,0x2509203436752e6dull,0x5f5f5b202c356472ull,0x6d72617061647563ull,
0x636c6163395a5f5full,0x6636504468736148ull,0x7535503474616f6cull,0x7261705f32746e69ull,
0x736148656c636974ull,0x69202f2f093b5d68ull,0x635f5f2039393a64ull,0x5f6d726170616475ull,
0x48636c6163395a5full,0x6c66365044687361ull,0x697535503474616full,0x747261705f32746eull,
0x68736148656c6369ull,0x756d090a3078302bull,0x3436752e6f6c2e6cull,0x202c366472250920ull,
0x3b38202c31647225ull,0x202f2f0920202020ull,0x36752e646461090aull,0x2c37647225092034ull,
0x25202c3564722520ull,0x202020203b366472ull,0x646c090a202f2f09ull,0x752e74736e6f632eull,
0x2c38722509203233ull,0x736d617261705b20ull,0x2f2f093b5d34342bull,0x203030313a646920ull,
0x302b736d61726170ull,0x2e646c090a633278ull,0x33752e74736e6f63ull,0x202c397225092032ull,
0x2b736d617261705bull,0x202f2f093b5d3034ull,0x70203130313a6469ull,0x78302b736d617261ull,
0x2e766964090a3832ull,0x662e786f72707061ull,0x3832662509203233ull,0x25202c336625202cull,
0x0a202f2f093b3566ull,0x696d722e74766309ull,0x3233662e3233662eull,0x202c393266250920ull,
0x0920203b38326625ull,0x747663090a202f2full,0x3233732e697a722eull,0x722509203233662eull,
0x39326625202c3031ull,0x0a202f2f0920203bull,0x736e6f632e646c09ull,0x2509203233752e74ull,
0x61705b202c313172ull,0x5d38342b736d6172ull,0x3a6469202f2f093bull,0x6172617020323031ull,
0x0a303378302b736dull,0x3233752e62757309ull,0x202c323172250920ull,0x3b31202c31317225ull,
0x0920202020202020ull,0x6e696d090a202f2full,0x722509203233752eull,0x30317225202c3331ull,
0x203b32317225202cull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,0x2509203233732e6full,
0x317225202c343172ull,0x093b387225202c33ull,0x6c756d090a202f2full,0x33732e6f6c2e3432ull,
0x2c35317225092032ull,0x25202c3431722520ull,0x0a202f2f093b3972ull,0x3233752e62757309ull,
0x202c363172250920ull,0x203b31202c387225ull,0x0920202020202020ull,0x6e696d090a202f2full,
0x722509203233752eull,0x2c377225202c3731ull,0x20203b3631722520ull,0x0a202f2f09202020ull,
0x6c2e34326c756d09ull,0x2509203233732e6full,0x317225202c383172ull,0x093b397225202c37ull,
0x646461090a202f2full,0x722509203233732eull,0x35317225202c3931ull,0x203b38317225202cull,
0x0a202f2f09202020ull,0x3233752e62757309ull,0x202c303272250920ull,0x203b31202c397225ull,
0x0920202020202020ull,0x6e696d090a202f2full,0x722509203233752eull,0x2c367225202c3132ull,
0x20203b3032722520ull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c323272250920ull,
0x7225202c39317225ull,0x09202020203b3132ull,0x2e7473090a202f2full,0x762e6c61626f6c67ull,
0x5b09203233752e32ull,0x2c5d302b37647225ull,0x252c323272257b20ull,0x202f2f093b7d3572ull,
0x3109636f6c2e090aull,0x0a30093935310936ull,0x20203b7469786509ull,0x2020202020202020ull,
0x2020202020202020ull,0x0920202020202020ull,0x57444c240a202f2full,0x63395a5f5f646e65ull,
0x4468736148636c61ull,0x3474616f6c663650ull,0x3a32746e69753550ull,0x5f202f2f207d090aull,
0x6148636c6163395aull,0x6f6c663650446873ull,0x6e69753550347461ull,0x6e652e090a0a3274ull,
0x38325a5f20797274ull,0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,
0x6975355044747261ull,0x6f6c66365032746eull,0x32535f3253347461ull,0x28206a505f32535full,
0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,0x657238325a5f5f6dull,
0x746144726564726full,0x646e6946646e4161ull,0x726174536c6c6543ull,0x746e697535504474ull,
0x74616f6c66365032ull,0x535f32535f325334ull,0x7261705f6a505f32ull,0x736148656c636974ull,
0x61702e09090a2c68ull,0x3436752e206d6172ull,0x70616475635f5f20ull,0x38325a5f5f6d7261ull,
0x44726564726f6572ull,0x6946646e41617461ull,0x74536c6c6543646eull,0x6975355044747261ull,
0x6f6c66365032746eull,0x32535f3253347461ull,0x6f5f6a505f32535full,0x090a2c736f50646cull,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x726f657238325a5full,
0x4161746144726564ull,0x6543646e6946646eull,0x4474726174536c6cull,0x5032746e69753550ull,
0x533474616f6c6636ull,0x5f32535f32535f32ull,0x6556646c6f5f6a50ull,0x61702e09090a2c6cull,
0x3436752e206d6172ull,0x70616475635f5f20ull,0x38325a5f5f6d7261ull,0x44726564726f6572ull,
0x6946646e41617461ull,0x74536c6c6543646eull,0x6975355044747261ull,0x6f6c66365032746eull,
0x32535f3253347461ull,0x735f6a505f32535full,0x736f50646574726full,0x7261702e09090a2cull,
0x203436752e206d61ull,0x6170616475635f5full,0x7238325a5f5f6d72ull,0x6144726564726f65ull,
0x6e6946646e416174ull,0x6174536c6c654364ull,0x6e69753550447472ull,0x616f6c6636503274ull,
0x5f32535f32533474ull,0x6f735f6a505f3253ull,0x2c6c655664657472ull,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x657238325a5f5f6dull,0x746144726564726full,
0x646e6946646e4161ull,0x726174536c6c6543ull,0x746e697535504474ull,0x74616f6c66365032ull,
0x535f32535f325334ull,0x6c65635f6a505f32ull,0x0a2974726174536cull,0x6765722e090a7b09ull,
0x7225203233752e20ull,0x2e090a3b3e38323cull,0x3436752e20676572ull,0x3e33323c64722520ull,
0x206765722e090a3bull,0x3c6625203233662eull,0x722e090a3b3e3431ull,0x646572702e206765ull,
0x0a3b3e353c702520ull,0x6465726168732e09ull,0x206e67696c612e20ull,0x5f5f2038622e2034ull,
0x6168735f61647563ull,0x3268736148646572ull,0x5d383230315b3034ull,0x7270202f2f090a3bull,
0x3d20617461447665ull,0x6f6c2e090a363120ull,0x3936310936310963ull,0x3142424c240a3009ull,
0x6f657238325a5f5full,0x6174614472656472ull,0x43646e6946646e41ull,0x74726174536c6c65ull,
0x32746e6975355044ull,0x3474616f6c663650ull,0x32535f32535f3253ull,0x6c2e090a3a6a505full,
0x373109363109636full,0x747663090a300933ull,0x3631752e3233732eull,0x25202c3172250920ull,
0x3b782e6469617463ull,0x0a202f2f09202020ull,0x3233732e74766309ull,0x722509203631752eull,
0x6469746e25202c32ull,0x09202020203b782eull,0x6c756d090a202f2full,0x33732e6f6c2e3432ull,
0x202c337225092032ull,0x327225202c317225ull,0x0a202f2f0920203bull,0x3233752e74766309ull,
0x722509203631752eull,0x2e64697425202c34ull,0x0920202020203b78ull,0x646461090a202f2full,
0x722509203233752eull,0x202c337225202c35ull,0x202020203b347225ull,0x0a202f2f09202020ull,
0x3436752e74766309ull,0x722509203233732eull,0x3b357225202c3164ull,0x0920202020202020ull,
0x2e646c090a202f2full,0x36752e6d61726170ull,0x2c32647225092034ull,0x616475635f5f5b20ull,
0x325a5f5f6d726170ull,0x726564726f657238ull,0x46646e4161746144ull,0x536c6c6543646e69ull,
0x7535504474726174ull,0x6c66365032746e69ull,0x535f32533474616full,0x5f6a505f32535f32ull,
0x656c636974726170ull,0x2f093b5d68736148ull,0x2035393a6469202full,0x6170616475635f5full,
0x7238325a5f5f6d72ull,0x6144726564726f65ull,0x6e6946646e416174ull,0x6174536c6c654364ull,
0x6e69753550447472ull,0x616f6c6636503274ull,0x5f32535f32533474ull,0x61705f6a505f3253ull,
0x6148656c63697472ull,0x090a3078302b6873ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,
0x202c31647225202cull,0x2f09202020203b38ull,0x2e646461090a202full,0x6472250920343675ull,
0x2c32647225202c34ull,0x20203b3364722520ull,0x090a202f2f092020ull,0x61626f6c672e646cull,
0x3233752e32762e6cull,0x252c3672257b0920ull,0x72255b202c7d3772ull,0x2f093b5d302b3464ull,
0x636f6c2e090a202full,0x0939373109363109ull,0x752e766f6d090a30ull,0x3564722509203436ull,
0x616475635f5f202cull,0x486465726168735full,0x093b303432687361ull,0x747663090a202f2full,
0x3233752e3436752eull,0x202c366472250920ull,0x202020203b347225ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x2c36647225202c37ull,0x09202020203b3420ull,
0x646461090a202f2full,0x722509203436752eull,0x35647225202c3864ull,0x203b37647225202cull,
0x0a202f2f09202020ull,0x726168732e747309ull,0x09203233752e6465ull,0x5d342b386472255bull,
0x09203b367225202cull,0x38393a6469202f2full,0x5f616475635f5f20ull,0x6148646572616873ull,
0x78302b3034326873ull,0x732e766f6d090a30ull,0x2c38722509203233ull,0x20202020203b3020ull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x33752e74672e7465ull,0x2509203233732e32ull,
0x2c357225202c3972ull,0x2f2f093b38722520ull,0x732e67656e090a20ull,0x3031722509203233ull,
0x20203b397225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233752e766full,
0x3b30202c31317225ull,0x2020202020202020ull,0x2f2f092020202020ull,0x652e746573090a20ull,
0x33752e3233752e71ull,0x2c32317225092032ull,0x7225202c34722520ull,0x0a202f2f093b3131ull,
0x3233732e67656e09ull,0x202c333172250920ull,0x2020203b32317225ull,0x0920202020202020ull,
0x646e61090a202f2full,0x722509203233622eull,0x30317225202c3431ull,0x203b33317225202cull,
0x0a202f2f09202020ull,0x3233752e766f6d09ull,0x202c353172250920ull,0x2020202020203b30ull,
0x0920202020202020ull,0x746573090a202f2full,0x3233732e71652e70ull,0x25202c3170250920ull,
0x317225202c343172ull,0x0a202f2f09203b35ull,0x7262203170254009ull,0x335f744c24092061ull,
0x20203b383138325full,0x0920202020202020ull,0x2e646c090a202f2full,0x762e6c61626f6c67ull,
0x7b09203233752e32ull,0x3172252c36317225ull,0x6472255b202c7d37ull,0x2f093b5d382d2b34ull,
0x636f6c2e090a202full,0x0936383109363109ull,0x732e766f6d090a30ull,0x3831722509203233ull,
0x203b36317225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x7225202c39317225ull,0x20202020203b3731ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009343831093631ull,0x33732e766f6d090aull,0x2c30327225092032ull,0x20203b3831722520ull,
0x2020202020202020ull,0x7473090a202f2f09ull,0x2e6465726168732eull,0x5f5f5b0920323375ull,
0x6168735f61647563ull,0x3268736148646572ull,0x25202c5d302b3034ull,0x202f2f093b303272ull,
0x5f203330313a6469ull,0x68735f616475635full,0x6873614864657261ull,0x0a3078302b303432ull,
0x38325f335f744c24ull,0x6f6c2e090a3a3831ull,0x3738310936310963ull,0x2e726162090a3009ull,
0x3b300920636e7973ull,0x2020202020202020ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233752e766f6dull,0x30202c3132722509ull,0x202020202020203bull,0x2f09202020202020ull,
0x70746573090a202full,0x203233732e71652eull,0x7225202c32702509ull,0x3b31327225202c35ull,
0x090a202f2f092020ull,0x6172622032702540ull,0x325f335f4c240920ull,0x202020203b323635ull,
0x2f09202020202020ull,0x732e646c090a202full,0x33752e6465726168ull,0x2c32327225092032ull,
0x302b386472255b20ull,0x6469202f2f093b5dull,0x635f5f203430313aull,0x726168735f616475ull,
0x3432687361486465ull,0x73090a3078302b30ull,0x752e71652e707465ull,0x2c33702509203233ull,
0x25202c3232722520ull,0x2f2f0920203b3672ull,0x2033702540090a20ull,0x5f4c240920617262ull,
0x203b363033325f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x3a323635325f335full,
0x3109636f6c2e090aull,0x0a30093039310936ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5f5b202c396472ull,0x6d72617061647563ull,0x6f657238325a5f5full,0x6174614472656472ull,
0x43646e6946646e41ull,0x74726174536c6c65ull,0x32746e6975355044ull,0x3474616f6c663650ull,
0x32535f32535f3253ull,0x6c6c65635f6a505full,0x093b5d7472617453ull,0x30313a6469202f2full,
0x616475635f5f2035ull,0x325a5f5f6d726170ull,0x726564726f657238ull,0x46646e4161746144ull,
0x536c6c6543646e69ull,0x7535504474726174ull,0x6c66365032746e69ull,0x535f32533474616full,
0x5f6a505f32535f32ull,0x726174536c6c6563ull,0x63090a3078302b74ull,0x752e3436752e7476ull,
0x3164722509203233ull,0x203b367225202c30ull,0x2f2f092020202020ull,0x6c2e6c756d090a20ull,
0x2509203436752e6full,0x7225202c31316472ull,0x203b34202c303164ull,0x61090a202f2f0920ull,
0x09203436752e6464ull,0x25202c3231647225ull,0x647225202c396472ull,0x2f2f0920203b3131ull,
0x6c672e7473090a20ull,0x3233752e6c61626full,0x32316472255b0920ull,0x357225202c5d302bull,
0x3a6469202f2f093bull,0x335f4c240a363031ull,0x090a3a363033325full,0x09363109636f6c2eull,
0x6c090a3009343931ull,0x2e6d617261702e64ull,0x6472250920343675ull,0x635f5f5b202c3331ull,
0x5f6d726170616475ull,0x726f657238325a5full,0x4161746144726564ull,0x6543646e6946646eull,
0x4474726174536c6cull,0x5032746e69753550ull,0x533474616f6c6636ull,0x5f32535f32535f32ull,
0x6f50646c6f5f6a50ull,0x69202f2f093b5d73ull,0x5f5f203730313a64ull,0x6d72617061647563ull,
0x6f657238325a5f5full,0x6174614472656472ull,0x43646e6946646e41ull,0x74726174536c6c65ull,
0x32746e6975355044ull,0x3474616f6c663650ull,0x32535f32535f3253ull,0x50646c6f5f6a505full,
0x090a3078302b736full,0x2e3436752e747663ull,0x6472250920323375ull,0x3b377225202c3431ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x25202c3531647225ull,
0x3631202c34316472ull,0x090a202f2f09203bull,0x203436752e646461ull,0x202c363164722509ull,
0x25202c3331647225ull,0x2f09203b35316472ull,0x672e646c090a202full,0x34762e6c61626f6cull,
0x5f7b09203233662eull,0x3266252c3166252cull,0x5b202c7d3366252cull,0x5d302b3631647225ull,
0x6d090a202f2f093bull,0x09203233732e766full,0x7225202c33327225ull,0x2020202020203b37ull,
0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3432722509203233ull,0x202020203b30202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,0x3b30202c35327225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3632722509203233ull,
0x202020203b30202cull,0x2020202020202020ull,0x74090a202f2f0920ull,0x34762e64312e7865ull,
0x3233732e3233662eull,0x66252c3466257b20ull,0x66252c3666252c35ull,0x56646c6f5b2c7d37ull,
0x257b2c7865546c65ull,0x343272252c333272ull,0x72252c353272252cull,0x2e090a3b5d7d3632ull,
0x3109363109636f6cull,0x6f6d090a30093539ull,0x2509203233662e76ull,0x3b346625202c3866ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x202c396625092032ull,
0x202020203b356625ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x366625202c303166ull,0x202020202020203bull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c31316625092032ull,0x2020203b37662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x393109363109636full,0x6c756d090a300937ull,0x203436752e6f6c2eull,0x202c373164722509ull,
0x3631202c31647225ull,0x0a202f2f0920203bull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5b202c38316472ull,0x726170616475635full,0x657238325a5f5f6dull,0x746144726564726full,
0x646e6946646e4161ull,0x726174536c6c6543ull,0x746e697535504474ull,0x74616f6c66365032ull,
0x535f32535f325334ull,0x726f735f6a505f32ull,0x3b5d736f50646574ull,0x313a6469202f2f09ull,
0x6475635f5f203231ull,0x5a5f5f6d72617061ull,0x6564726f65723832ull,0x646e416174614472ull,
0x6c6c6543646e6946ull,0x3550447472617453ull,0x66365032746e6975ull,0x5f32533474616f6cull,
0x6a505f32535f3253ull,0x50646574726f735full,0x090a3078302b736full,0x203436752e646461ull,
0x202c393164722509ull,0x25202c3831647225ull,0x2f09203b37316472ull,0x672e646c090a202full,
0x33662e6c61626f6cull,0x2c32316625092032ull,0x2b36316472255b20ull,0x69202f2f093b5d30ull,
0x73090a3331313a64ull,0x6c61626f6c672e74ull,0x203233662e34762eull,0x2b39316472255b09ull,
0x3166257b202c5d30ull,0x66252c3166252c32ull,0x093b7d3366252c32ull,0x6f6c2e090a202f2full,
0x3839310936310963ull,0x702e646c090a3009ull,0x3436752e6d617261ull,0x2c30326472250920ull,
0x616475635f5f5b20ull,0x325a5f5f6d726170ull,0x726564726f657238ull,0x46646e4161746144ull,
0x536c6c6543646e69ull,0x7535504474726174ull,0x6c66365032746e69ull,0x535f32533474616full,
0x5f6a505f32535f32ull,0x6556646574726f73ull,0x69202f2f093b5d6cull,0x5f5f203831313a64ull,
0x6d72617061647563ull,0x6f657238325a5f5full,0x6174614472656472ull,0x43646e6946646e41ull,
0x74726174536c6c65ull,0x32746e6975355044ull,0x3474616f6c663650ull,0x32535f32535f3253ull,
0x74726f735f6a505full,0x78302b6c65566465ull,0x752e646461090a30ull,0x3264722509203436ull,
0x3032647225202c31ull,0x3b3731647225202cull,0x73090a202f2f0920ull,0x6c61626f6c672e74ull,
0x203233662e34762eull,0x2b31326472255b09ull,0x3866257b202c5d30ull,0x3166252c3966252cull,
0x3b7d313166252c30ull,0x6c2e090a202f2f09ull,0x303209363109636full,0x697865090a300930ull,
0x2020202020203b74ull,0x2020202020202020ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x5f646e6557444c24ull,0x726f657238325a5full,0x4161746144726564ull,0x6543646e6946646eull,
0x4474726174536c6cull,0x5032746e69753550ull,0x533474616f6c6636ull,0x5f32535f32535f32ull,
0x2f207d090a3a6a50ull,0x657238325a5f202full,0x746144726564726full,0x646e6946646e4161ull,
0x726174536c6c6543ull,0x746e697535504474ull,0x74616f6c66365032ull,0x535f32535f325334ull,
0x2e090a0a6a505f32ull,0x5a5f207972746e65ull,0x6564696c6c6f6338ull,0x74616f6c66365044ull,
0x535f30535f305334ull,0x746e697535505f30ull,0x09090a28206a5032ull,0x2e206d617261702eull,
0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x64696c6c6f63385aull,0x616f6c6636504465ull,
0x5f30535f30533474ull,0x6e697535505f3053ull,0x77656e5f6a503274ull,0x2e09090a2c736f50ull,
0x752e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x6564696c6c6f6338ull,
0x74616f6c66365044ull,0x535f30535f305334ull,0x746e697535505f30ull,0x5677656e5f6a5032ull,
0x702e09090a2c6c65ull,0x36752e206d617261ull,0x616475635f5f2034ull,0x385a5f5f6d726170ull,
0x446564696c6c6f63ull,0x3474616f6c663650ull,0x30535f30535f3053ull,0x32746e697535505full,
0x6f50646c6f5f6a50ull,0x61702e09090a2c73ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x63385a5f5f6d7261ull,0x50446564696c6c6full,0x533474616f6c6636ull,0x5f30535f30535f30ull,
0x5032746e69753550ull,0x6c6556646c6f5f6aull,0x7261702e09090a2cull,0x203436752e206d61ull,
0x6170616475635f5full,0x6f63385a5f5f6d72ull,0x3650446564696c6cull,0x30533474616f6c66ull,
0x505f30535f30535full,0x6a5032746e697535ull,0x6c6369747261705full,0x090a2c6873614865ull,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x696c6c6f63385a5full,
0x6f6c663650446564ull,0x30535f3053347461ull,0x697535505f30535full,0x65635f6a5032746eull,
0x2974726174536c6cull,0x65722e090a7b090aull,0x25203233752e2067ull,0x090a3b3e36383c72ull,
0x36752e206765722eull,0x39313c6472252034ull,0x6765722e090a3b3eull,0x6625203233662e20ull,
0x090a3b3e3336313cull,0x72702e206765722eull,0x31323c7025206465ull,0x73202f2f090a3b3eull,
0x746144646574726full,0x090a3631203d2061ull,0x09363109636f6c2eull,0x4c240a3009383333ull,
0x63385a5f5f314242ull,0x50446564696c6c6full,0x533474616f6c6636ull,0x5f30535f30535f30ull,
0x5032746e69753550ull,0x2e747663090a3a6aull,0x203631752e323373ull,0x6325202c31722509ull,
0x203b782e64696174ull,0x090a202f2f092020ull,0x2e3233732e747663ull,0x3272250920363175ull,
0x2e6469746e25202cull,0x2f09202020203b78ull,0x326c756d090a202full,0x3233732e6f6c2e34ull,
0x25202c3372250920ull,0x3b327225202c3172ull,0x090a202f2f092020ull,0x2e3233752e747663ull,
0x3472250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,0x2e646461090a202full,
0x3572250920323375ull,0x25202c337225202cull,0x20202020203b3472ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x7225202c36722509ull,0x2020202020203b35ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3772250920323373ull,0x202020203b30202cull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233732e766f6dull,0x3b30202c38722509ull,0x2020202020202020ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3972250920323373ull,0x202020203b30202cull,
0x2020202020202020ull,0x090a202f2f092020ull,0x762e64312e786574ull,0x33732e3233662e34ull,
0x252c3166257b2032ull,0x252c3366252c3266ull,0x646c6f5b2c7d3466ull,0x7b2c786554736f50ull,
0x2c3772252c367225ull,0x7d3972252c387225ull,0x636f6c2e090a3b5dull,0x0938343309363109ull,
0x662e766f6d090a30ull,0x2c35662509203233ull,0x2020203b31662520ull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x326625202c366625ull,0x202020202020203bull,
0x2f2f092020202020ull,0x662e766f6d090a20ull,0x2c37662509203233ull,0x2020203b33662520ull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,0x7225202c30317225ull,
0x2020202020203b35ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3131722509203233ull,
0x202020203b30202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x3b30202c32317225ull,0x2020202020202020ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3331722509203233ull,0x202020203b30202cull,0x2020202020202020ull,0x74090a202f2f0920ull,
0x34762e64312e7865ull,0x3233732e3233662eull,0x66252c3866257b20ull,0x252c303166252c39ull,
0x6c6f5b2c7d313166ull,0x2c7865546c655664ull,0x72252c303172257bull,0x2c323172252c3131ull,
0x0a3b5d7d33317225ull,0x363109636f6c2e09ull,0x090a300939343309ull,0x203233662e766f6dull,
0x25202c3231662509ull,0x20202020203b3866ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3166250920323366ull,0x203b396625202c33ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x25202c3431662509ull,0x202020203b303166ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3166250920323366ull,0x3b31316625202c35ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09303209636f6c2eull,0x090a300934393634ull,0x74736e6f632e646cull,
0x662509203233662eull,0x7261705b202c3631ull,0x3b5d36352b736d61ull,0x343a6469202f2f09ull,
0x6d61726170203239ull,0x090a383378302b73ull,0x203233662e627573ull,0x25202c3731662509ull,
0x36316625202c3566ull,0x2f0920202020203bull,0x632e646c090a202full,0x3233662e74736e6full,
0x202c383166250920ull,0x2b736d617261705bull,0x202f2f093b5d3836ull,0x70203339343a6469ull,
0x78302b736d617261ull,0x2e766f6d090a3434ull,0x3166250920323366ull,0x3b38316625202c39ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x09303209636f6c2eull,0x090a300936313634ull,
0x203233662e736261ull,0x25202c3032662509ull,0x202020203b383166ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3266250920323366ull,0x3865376630202c31ull,0x20203b3030303030ull,
0x2e38202f2f092020ull,0x332b653630373035ull,0x2e70746573090a37ull,0x09203233662e7467ull,
0x326625202c317025ull,0x3b31326625202c30ull,0x40090a202f2f0920ull,0x6172622031702521ull,
0x5f345f744c240920ull,0x20203b3833333431ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x0937313634093032ull,0x662e766f6d090a30ull,0x3232662509203233ull,0x303865336630202cull,
0x2020203b30303030ull,0x322e30202f2f0920ull,0x662e6c756d090a35ull,0x3731662509203233ull,
0x202c37316625202cull,0x2020203b32326625ull,0x2e090a202f2f0920ull,0x3409303209636f6cull,
0x6d090a3009383136ull,0x09203233662e766full,0x6630202c33326625ull,0x3030303030386533ull,
0x2f2f09202020203bull,0x6d090a35322e3020ull,0x09203233662e6c75ull,0x6625202c39316625ull,
0x33326625202c3831ull,0x2f2f09202020203bull,0x5f345f744c240a20ull,0x090a3a3833333431ull,
0x09363109636f6c2eull,0x6964090a30093339ull,0x786f727070612e76ull,0x662509203233662eull,
0x37316625202c3432ull,0x093b39316625202cull,0x747663090a202f2full,0x3233662e696d722eull,
0x662509203233662eull,0x34326625202c3532ull,0x0a202f2f0920203bull,0x697a722e74766309ull,
0x3233662e3233732eull,0x202c343172250920ull,0x0920203b35326625ull,0x6f6c2e090a202f2full,
0x3936340930320963ull,0x2e646c090a300934ull,0x33662e74736e6f63ull,0x2c36326625092032ull,
0x736d617261705b20ull,0x2f2f093b5d30362bull,0x203439343a646920ull,0x302b736d61726170ull,
0x627573090a633378ull,0x662509203233662eull,0x2c366625202c3731ull,0x20203b3632662520ull,
0x0a202f2f09202020ull,0x736e6f632e646c09ull,0x2509203233662e74ull,0x61705b202c373266ull,
0x5d32372b736d6172ull,0x3a6469202f2f093bull,0x6172617020353934ull,0x0a383478302b736dull,
0x3233662e766f6d09ull,0x202c393166250920ull,0x2020203b37326625ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3136340930320963ull,0x736261090a300936ull,0x662509203233662eull,
0x37326625202c3832ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c393266250920ull,0x3030303865376630ull,0x09202020203b3030ull,0x3730352e38202f2full,
0x090a37332b653630ull,0x2e74672e70746573ull,0x3270250920323366ull,0x202c38326625202cull,
0x2f09203b39326625ull,0x70252140090a202full,0x2409206172622032ull,0x3834315f345f744cull,
0x20202020203b3035ull,0x090a202f2f092020ull,0x09303209636f6c2eull,0x090a300937313634ull,
0x203233662e766f6dull,0x30202c3033662509ull,0x3030303038653366ull,0x2f09202020203b30ull,
0x090a35322e30202full,0x203233662e6c756dull,0x25202c3731662509ull,0x336625202c373166ull,
0x2f09202020203b30ull,0x636f6c2e090a202full,0x3831363409303209ull,0x2e766f6d090a3009ull,
0x3366250920323366ull,0x3865336630202c31ull,0x20203b3030303030ull,0x2e30202f2f092020ull,
0x2e6c756d090a3532ull,0x3166250920323366ull,0x2c37326625202c39ull,0x20203b3133662520ull,
0x240a202f2f092020ull,0x3834315f345f744cull,0x6f6c2e090a3a3035ull,0x0934390936310963ull,
0x612e766964090a30ull,0x33662e786f727070ull,0x2c32336625092032ull,0x25202c3731662520ull,
0x202f2f093b393166ull,0x6d722e747663090aull,0x33662e3233662e69ull,0x2c33336625092032ull,
0x20203b3233662520ull,0x7663090a202f2f09ull,0x33732e697a722e74ull,0x2509203233662e32ull,
0x336625202c353172ull,0x202f2f0920203b33ull,0x3209636f6c2e090aull,0x3009343936340930ull,
0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c34336625ull,0x34362b736d617261ull,
0x6469202f2f093b5dull,0x726170203639343aull,0x303478302b736d61ull,0x33662e627573090aull,
0x2c37316625092032ull,0x6625202c37662520ull,0x20202020203b3433ull,0x646c090a202f2f09ull,
0x662e74736e6f632eull,0x3533662509203233ull,0x6d617261705b202cull,0x2f093b5d36372b73ull,
0x3739343a6469202full,0x2b736d6172617020ull,0x6f6d090a63347830ull,0x2509203233662e76ull,
0x336625202c393166ull,0x2020202020203b35ull,0x202f2f0920202020ull,0x3209636f6c2e090aull,
0x3009363136340930ull,0x33662e736261090aull,0x2c36336625092032ull,0x20203b3533662520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x376630202c373366ull,
0x3b30303030303865ull,0x202f2f0920202020ull,0x6536303730352e38ull,0x746573090a37332bull,
0x3233662e74672e70ull,0x25202c3370250920ull,0x336625202c363366ull,0x0a202f2f09203b37ull,
0x6220337025214009ull,0x5f744c2409206172ull,0x3b32363335315f34ull,0x0920202020202020ull,
0x6f6c2e090a202f2full,0x3136340930320963ull,0x766f6d090a300937ull,0x662509203233662eull,
0x65336630202c3833ull,0x203b303030303038ull,0x30202f2f09202020ull,0x6c756d090a35322eull,
0x662509203233662eull,0x37316625202c3731ull,0x203b38336625202cull,0x0a202f2f09202020ull,
0x303209636f6c2e09ull,0x0a30093831363409ull,0x3233662e766f6d09ull,0x202c393366250920ull,
0x3030303865336630ull,0x09202020203b3030ull,0x0a35322e30202f2full,0x3233662e6c756d09ull,
0x202c393166250920ull,0x6625202c35336625ull,0x09202020203b3933ull,0x5f744c240a202f2full,
0x3a32363335315f34ull,0x3109636f6c2e090aull,0x0a30093235330936ull,0x7070612e76696409ull,
0x203233662e786f72ull,0x25202c3034662509ull,0x316625202c373166ull,0x090a202f2f093b39ull,
0x2e696d722e747663ull,0x203233662e323366ull,0x25202c3134662509ull,0x2f0920203b303466ull,
0x2e747663090a202full,0x2e3233732e697a72ull,0x3172250920323366ull,0x3b31346625202c36ull,
0x090a202f2f092020ull,0x74736e6f632e646cull,0x662509203233662eull,0x7261705b202c3234ull,
0x3b5d36332b736d61ull,0x343a6469202f2f09ull,0x6d61726170203137ull,0x090a343278302b73ull,
0x203233732e766f6dull,0x2d202c3731722509ull,0x2020202020203b31ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3466250920323366ull,0x3030306630202c33ull,0x20203b3030303030ull,
0x0a30202f2f092020ull,0x3233662e766f6d09ull,0x202c343466250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c353466ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x5f345f744c240a30ull,0x200a3a3638333631ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c323533ull,
0x70656420676e6974ull,0x69202c31203a6874ull,0x6e6f697461726574ull,0x6f6d090a33203a73ull,
0x2509203233732e76ull,0x3b312d202c383172ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x315f345f744c240aull,0x2f200a3a34353137ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,
0x3320656e696c2079ull,0x7473656e202c3235ull,0x7470656420676e69ull,0x7469202c32203a68ull,
0x736e6f6974617265ull,0x766f6d090a33203aull,0x722509203233732eull,0x203b312d202c3931ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x37315f345f744c24ull,0x2f2f200a3a323239ull,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x353320656e696c20ull,0x697473656e202c32ull,
0x687470656420676eull,0x657469202c33203aull,0x3a736e6f69746172ull,0x636f6c2e090a3320ull,
0x0938393209363109ull,0x732e646461090a30ull,0x3032722509203233ull,0x202c34317225202cull,
0x2020203b39317225ull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c31327225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e746cull,
0x327225202c347025ull,0x3b31327225202c30ull,0x40090a202f2f0920ull,0x2061726220347025ull,
0x325f345f744c2409ull,0x2020203b36383732ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c32353320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32323937315f345full,0x6e6f632e646c090aull,
0x09203233752e7473ull,0x705b202c32327225ull,0x30342b736d617261ull,0x6469202f2f093b5dull,
0x726170203839343aull,0x383278302b736d61ull,0x33752e627573090aull,0x2c33327225092032ull,
0x31202c3232722520ull,0x202020202020203bull,0x6573090a202f2f09ull,0x33752e74672e7074ull,
0x202c357025092032ull,0x7225202c30327225ull,0x202f2f09203b3332ull,0x622035702540090aull,
0x5f744c2409206172ull,0x3b36383732325f34ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353320656e696c20ull,
0x2064616568202c32ull,0x2064656c6562616cull,0x37315f345f744c24ull,0x646461090a323239ull,
0x722509203233732eull,0x35317225202c3432ull,0x203b38317225202cull,0x0a202f2f09202020ull,
0x3233752e766f6d09ull,0x202c353272250920ull,0x2020202020203b30ull,0x0920202020202020ull,
0x746573090a202f2full,0x3233732e746c2e70ull,0x25202c3670250920ull,0x327225202c343272ull,
0x0a202f2f09203b35ull,0x7262203670254009ull,0x345f744c24092061ull,0x203b36383732325full,
0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x32353320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3937315f345f744cull,0x632e646c090a3232ull,0x3233752e74736e6full,0x202c363272250920ull,
0x2b736d617261705bull,0x202f2f093b5d3434ull,0x70203736343a6469ull,0x78302b736d617261ull,
0x2e627573090a6332ull,0x3272250920323375ull,0x2c36327225202c37ull,0x20202020203b3120ull,
0x090a202f2f092020ull,0x2e74672e70746573ull,0x3770250920323375ull,0x202c34327225202cull,
0x2f09203b37327225ull,0x37702540090a202full,0x4c24092061726220ull,0x383732325f345f74ull,
0x2020202020203b36ull,0x200a202f2f092020ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323533ull,0x656c6562616c2064ull,
0x5f345f744c242064ull,0x61090a3232393731ull,0x09203233732e6464ull,0x7225202c38327225ull,
0x37317225202c3631ull,0x2f2f09202020203bull,0x752e766f6d090a20ull,0x3932722509203233ull,
0x202020203b30202cull,0x2020202020202020ull,0x73090a202f2f0920ull,0x732e746c2e707465ull,
0x2c38702509203233ull,0x25202c3832722520ull,0x2f2f09203b393272ull,0x2038702540090a20ull,
0x744c240920617262ull,0x36383732325f345full,0x202020202020203bull,0x2f200a202f2f0920ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,
0x64616568202c3235ull,0x64656c6562616c20ull,0x315f345f744c2420ull,0x646c090a32323937ull,
0x752e74736e6f632eull,0x3033722509203233ull,0x6d617261705b202cull,0x2f093b5d38342b73ull,
0x3939343a6469202full,0x2b736d6172617020ull,0x7573090a30337830ull,0x2509203233752e62ull,
0x337225202c313372ull,0x2020203b31202c30ull,0x202f2f0920202020ull,0x6c2e70746573090aull,
0x2509203233752e65ull,0x38327225202c3970ull,0x203b31337225202cull,0x2540090a202f2f09ull,
0x0920617262203970ull,0x3832315f345f4c24ull,0x20202020203b3230ull,0x202f2f0920202020ull,
0x325f345f744c240aull,0x4c240a3a36383732ull,0x38353033315f345full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c32353320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32323937315f345full,0x33662e766f6d090aull,
0x2c36346625092032ull,0x3030303030663020ull,0x202020203b303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x6630202c37346625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x2e766f6d090a3020ull,0x3466250920323366ull,0x3030306630202c38ull,0x20203b3030303030ull,
0x0a30202f2f092020ull,0x696e752e61726209ull,0x5f345f744c240920ull,0x202020203b383532ull,
0x0920202020202020ull,0x345f4c240a202f2full,0x0a3a32303832315full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c32353320ull,
0x6c6562616c206461ull,0x345f744c24206465ull,0x090a32323937315full,0x09363109636f6c2eull,
0x6d090a3009343031ull,0x09203233752e6e69ull,0x7225202c32337225ull,0x31337225202c3832ull,
0x2f2f09202020203bull,0x34326c756d090a20ull,0x203233732e6f6c2eull,0x25202c3333722509ull,
0x327225202c323372ull,0x090a202f2f093b36ull,0x6f6c2e34326c756dull,0x722509203233732eull,
0x33337225202c3433ull,0x093b32327225202cull,0x6e696d090a202f2full,0x722509203233752eull,
0x34327225202c3533ull,0x203b37327225202cull,0x0a202f2f09202020ull,0x6c2e34326c756d09ull,
0x2509203233732e6full,0x337225202c363372ull,0x3b32327225202c35ull,0x6461090a202f2f09ull,
0x2509203233732e64ull,0x337225202c373372ull,0x3b36337225202c34ull,0x202f2f0920202020ull,
0x33752e6e696d090aull,0x2c38337225092032ull,0x25202c3032722520ull,0x202020203b333272ull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x337225202c393372ull,0x3b38337225202c37ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093630330936ull,0x3233732e766f6d09ull,
0x202c303472250920ull,0x2020203b39337225ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x722509203233732eull,0x20203b30202c3134ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x3233732e766f6d09ull,0x202c323472250920ull,0x2020202020203b30ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x722509203233732eull,0x20203b30202c3334ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x2e64312e78657409ull,0x732e3233752e3476ull,0x343472257b203233ull,
0x72252c353472252cull,0x7d373472252c3634ull,0x74536c6c65635b2cull,0x7b2c786554747261ull,
0x3472252c30347225ull,0x252c323472252c31ull,0x200a3b5d7d333472ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c323533ull,
0x656c6562616c2064ull,0x5f345f744c242064ull,0x2e090a3232393731ull,0x3309363109636f6cull,
0x6f6d090a30093930ull,0x2509203233732e76ull,0x347225202c383472ull,0x2020202020203b34ull,
0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c39347225092032ull,0x202020203b312d20ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x33752e656e2e7074ull,0x2c30317025092032ull,
0x25202c3834722520ull,0x202f2f093b393472ull,0x203031702540090aull,0x744c240920617262ull,
0x38373138315f345full,0x202020202020203bull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x353320656e696c20ull,0x2064616568202c32ull,
0x2064656c6562616cull,0x37315f345f744c24ull,0x766f6d090a323239ull,0x662509203233662eull,
0x30306630202c3634ull,0x203b303030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,
0x2c37346625092032ull,0x3030303030663020ull,0x202020203b303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x6630202c38346625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x2e617262090a3020ull,0x744c240920696e75ull,0x203b3835325f345full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3138315f345f744cull,0x3c2f2f200a3a3837ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x32353320656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3937315f345f744cull,0x632e646c090a3232ull,0x3233752e74736e6full,
0x202c303572250920ull,0x2b736d617261705bull,0x202f2f093b5d3438ull,0x70203536343a6469ull,
0x78302b736d617261ull,0x2e766f6d090a3435ull,0x3572250920323375ull,0x2020203b30202c31ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x2e71652e70746573ull,0x3170250920323375ull,
0x2c30357225202c31ull,0x2f093b3135722520ull,0x2e766f6d090a202full,0x3466250920323366ull,
0x3030306630202c39ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x202c303566250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x6f6d090a30202f2full,
0x2509203233662e76ull,0x306630202c313566ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x3131702540090a30ull,0x4c24092061726220ull,0x393233325f345f74ull,0x2020202020203b38ull,
0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3320656e696c2079ull,0x64616568202c3235ull,0x64656c6562616c20ull,0x315f345f744c2420ull,
0x6f6d090a32323937ull,0x2509203233732e76ull,0x357225202c323572ull,0x2020202020203b30ull,
0x202f2f0920202020ull,0x33752e766f6d090aull,0x2c33357225092032ull,0x20202020203b3020ull,
0x2020202020202020ull,0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x353320656e696c20ull,0x2064616568202c32ull,0x2064656c6562616cull,
0x37315f345f744c24ull,0x766f6d090a323239ull,0x722509203233732eull,0x32357225202c3435ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x39315f345f744c24ull,0x2f2f200a3a323032ull,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x303320656e696c20ull,0x697473656e202c39ull,
0x687470656420676eull,0x747365202c34203aull,0x6920646574616d69ull,0x6e6f697461726574ull,
0x6f6e6b6e75203a73ull,0x2e646461090a6e77ull,0x3572250920323375ull,0x2c38347225202c35ull,
0x20203b3335722520ull,0x090a202f2f092020ull,0x203233732e766f6dull,0x25202c3635722509ull,
0x202020203b353572ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3572250920323373ull,
0x2020203b30202c37ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e766f6dull,
0x30202c3835722509ull,0x202020202020203bull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3572250920323373ull,0x2020203b30202c39ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x762e64312e786574ull,0x33732e3233752e34ull,0x2c303672257b2032ull,0x3672252c31367225ull,
0x2c7d333672252c32ull,0x6c6369747261705bull,0x7865546873614865ull,0x252c363572257b2cull,
0x383572252c373572ull,0x3b5d7d393572252cull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3930332065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32303239315f34ull,0x363109636f6c2e09ull,0x090a300936313309ull,
0x203233732e766f6dull,0x25202c3436722509ull,0x202020203b303672ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0937313309363109ull,0x2e70746573090a30ull,0x09203233752e656eull,
0x7225202c32317025ull,0x34367225202c3933ull,0x40090a202f2f093bull,0x6172622032317025ull,
0x5f345f744c240920ull,0x20203b3039363831ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39303320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32303239315f345full,0x33752e627573090aull,
0x2c35367225092032ull,0x7225202c35722520ull,0x20202020203b3834ull,0x6573090a202f2f09ull,
0x33752e71652e7074ull,0x2c33317025092032ull,0x25202c3335722520ull,0x202f2f093b353672ull,
0x203331702540090aull,0x744c240920617262ull,0x38353439315f345full,0x202020202020203bull,
0x2f2f200a202f2f09ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x303320656e696c20ull,0x2064616568202c39ull,0x2064656c6562616cull,0x39315f345f744c24ull,
0x766f6d090a323032ull,0x722509203233732eull,0x35357225202c3636ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c373672250920ull,0x2020202020203b30ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233732eull,0x20203b30202c3836ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c393672250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x786574090a202f2full,0x662e34762e64312eull,
0x7b203233732e3233ull,0x3566252c32356625ull,0x252c343566252c33ull,0x6c6f5b2c7d353566ull,
0x2c786554736f5064ull,0x72252c363672257bull,0x2c383672252c3736ull,0x0a3b5d7d39367225ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c39303320ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a32303239315full,
0x09363109636f6c2eull,0x6d090a3009303233ull,0x09203233662e766full,0x6625202c36356625ull,
0x20202020203b3235ull,0x2f2f092020202020ull,0x662e766f6d090a20ull,0x3735662509203233ull,
0x203b33356625202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6625202c38356625ull,0x20202020203b3435ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3037722509203233ull,0x203b35357225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233732e766full,0x3b30202c31377225ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x732e766f6d090a20ull,0x3237722509203233ull,0x202020203b30202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233732e766full,0x3b30202c33377225ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x312e786574090a20ull,0x3233662e34762e64ull,0x66257b203233732eull,
0x2c303666252c3935ull,0x3666252c31366625ull,0x56646c6f5b2c7d32ull,0x257b2c7865546c65ull,
0x313772252c303772ull,0x72252c323772252cull,0x2f200a3b5d7d3337ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3930ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x6c2e090a32303239ull,0x323309363109636full,
0x766f6d090a300931ull,0x662509203233662eull,0x39356625202c3336ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c343666250920ull,0x2020203b30366625ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x662509203233662eull,0x31366625202c3536ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x090a300934313209ull,
0x203233662e627573ull,0x25202c3636662509ull,0x366625202c373566ull,0x2f0920202020203bull,
0x2e627573090a202full,0x3666250920323366ull,0x2c36356625202c37ull,0x2020203b35662520ull,
0x090a202f2f092020ull,0x203233662e627573ull,0x25202c3836662509ull,0x376625202c383566ull,
0x2f0920202020203bull,0x2e646461090a202full,0x3666250920323366ull,0x2c32346625202c39ull,
0x20203b3234662520ull,0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3037662509ull,
0x366625202c363666ull,0x2f09202020203b36ull,0x2e64616d090a202full,0x3766250920323366ull,
0x2c37366625202c31ull,0x25202c3736662520ull,0x202f2f093b303766ull,0x33662e64616d090aull,
0x2c32376625092032ull,0x25202c3836662520ull,0x376625202c383666ull,0x090a202f2f093b31ull,
0x7070612e74727173ull,0x203233662e786f72ull,0x25202c3337662509ull,0x2f0920203b323766ull,
0x70746573090a202full,0x203233662e74672eull,0x25202c3431702509ull,0x376625202c393666ull,
0x090a202f2f093b33ull,0x6220343170252140ull,0x5f744c2409206172ull,0x3b36323230325f34ull,
0x2f09202020202020ull,0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c39303320656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x303239315f345f74ull,0x09636f6c2e090a32ull,0x3009353332093631ull,0x33662e627573090aull,
0x2c34376625092032ull,0x25202c3336662520ull,0x202020203b323166ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x366625202c353766ull,0x3b33316625202c34ull,0x202f2f0920202020ull,
0x33662e627573090aull,0x2c36376625092032ull,0x25202c3536662520ull,0x202020203b343166ull,
0x7372090a202f2f09ull,0x727070612e747271ull,0x09203233662e786full,0x6625202c37376625ull,
0x202f2f09203b3237ull,0x33662e6c756d090aull,0x2c38376625092032ull,0x25202c3636662520ull,
0x202020203b373766ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x366625202c393766ull,
0x3b37376625202c37ull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c30386625092032ull,
0x25202c3836662520ull,0x202020203b373766ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x376625202c313866ull,0x3b38376625202c35ull,0x202f2f0920202020ull,0x33662e64616d090aull,
0x2c32386625092032ull,0x25202c3937662520ull,0x386625202c343766ull,0x090a202f2f093b31ull,
0x203233662e64616dull,0x25202c3338662509ull,0x376625202c303866ull,0x3b32386625202c36ull,
0x646c090a202f2f09ull,0x662e74736e6f632eull,0x3438662509203233ull,0x6d617261705b202cull,
0x2f093b5d36392b73ull,0x3936343a6469202full,0x2b736d6172617020ull,0x756d090a30367830ull,
0x2509203233662e6cull,0x376625202c353866ull,0x3b33386625202c39ull,0x202f2f0920202020ull,
0x33662e627573090aull,0x2c36386625092032ull,0x25202c3437662520ull,0x202020203b353866ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x386625202c373866ull,0x3b36386625202c34ull,
0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c38386625092032ull,0x25202c3837662520ull,
0x202020203b333866ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x376625202c393866ull,
0x3b38386625202c35ull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c30396625092032ull,
0x25202c3438662520ull,0x202020203b393866ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x386625202c313966ull,0x3b33386625202c30ull,0x202f2f0920202020ull,0x33662e627573090aull,
0x2c32396625092032ull,0x25202c3637662520ull,0x202020203b313966ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x386625202c333966ull,0x3b32396625202c34ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093733320936ull,0x3233662e62757309ull,0x202c343966250920ull,
0x6625202c39366625ull,0x09202020203b3337ull,0x2e646c090a202f2full,0x33662e74736e6f63ull,
0x2c35396625092032ull,0x736d617261705b20ull,0x2f2f093b5d38382bull,0x203130353a646920ull,
0x302b736d61726170ull,0x6c756d090a383578ull,0x662509203233662eull,0x35396625202c3639ull,
0x203b34396625202cull,0x0a202f2f09202020ull,0x736e6f632e646c09ull,0x2509203233662e74ull,
0x61705b202c373966ull,0x3030312b736d6172ull,0x6469202f2f093b5dull,0x726170203036343aull,
0x343678302b736d61ull,0x6e6f632e646c090aull,0x09203233662e7473ull,0x705b202c38396625ull,
0x32392b736d617261ull,0x6469202f2f093b5dull,0x726170203836343aull,0x633578302b736d61ull,
0x33662e6c756d090aull,0x2c39396625092032ull,0x25202c3937662520ull,0x202020203b363966ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c30303166ull,0x38396625202c3437ull,
0x202f2f092020203bull,0x33662e627573090aull,0x3130316625092032ull,0x2c3030316625202cull,
0x20203b3939662520ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c32303166ull,
0x30316625202c3738ull,0x202f2f0920203b31ull,0x33662e64616d090aull,0x3330316625092032ull,
0x202c37366625202cull,0x6625202c37396625ull,0x202f2f093b323031ull,0x33662e6c756d090aull,
0x3430316625092032ull,0x202c38376625202cull,0x2020203b36396625ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c35303166ull,0x38396625202c3537ull,0x202f2f092020203bull,
0x33662e627573090aull,0x3630316625092032ull,0x2c3530316625202cull,0x203b343031662520ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c37303166ull,0x30316625202c3039ull,
0x202f2f0920203b36ull,0x33662e64616d090aull,0x3830316625092032ull,0x202c36366625202cull,
0x6625202c37396625ull,0x202f2f093b373031ull,0x33662e6c756d090aull,0x3930316625092032ull,
0x202c30386625202cull,0x2020203b36396625ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c30313166ull,0x38396625202c3637ull,0x202f2f092020203bull,0x33662e627573090aull,
0x3131316625092032ull,0x2c3031316625202cull,0x203b393031662520ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x6625202c32313166ull,0x31316625202c3339ull,0x202f2f0920203b31ull,
0x33662e64616d090aull,0x3331316625092032ull,0x202c38366625202cull,0x6625202c37396625ull,
0x202f2f093b323131ull,0x6e752e617262090aull,0x345f744c24092069ull,0x203b30373939315full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x36323230325f345full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c39303320656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32303239315f345full,0x33662e766f6d090aull,
0x3331316625092032ull,0x303030306630202cull,0x2020203b30303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x30202c3830316625ull,0x3030303030303066ull,0x2f2f092020203b30ull,
0x2e766f6d090a3020ull,0x3166250920323366ull,0x30306630202c3330ull,0x203b303030303030ull,
0x0a30202f2f092020ull,0x39315f345f744c24ull,0x2f2f200a3a303739ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x303320656e696c20ull,0x2064616568202c39ull,
0x2064656c6562616cull,0x39315f345f744c24ull,0x6f6c2e090a323032ull,0x3532330936310963ull,
0x2e646461090a3009ull,0x3566250920323366ull,0x3330316625202c31ull,0x203b31356625202cull,
0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3035662509ull,0x6625202c38303166ull,
0x2f092020203b3035ull,0x2e646461090a202full,0x3466250920323366ull,0x3331316625202c39ull,
0x203b39346625202cull,0x240a202f2f092020ull,0x3439315f345f744cull,0x3c2f2f200a3a3835ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x39303320656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3239315f345f744cull,0x636f6c2e090a3230ull,
0x0934313309363109ull,0x752e646461090a30ull,0x3335722509203233ull,0x202c33357225202cull,
0x2020202020203b31ull,0x73090a202f2f0920ull,0x752e656e2e707465ull,0x3531702509203233ull,
0x202c30357225202cull,0x2f2f093b33357225ull,0x3531702540090a20ull,0x4c24092061726220ull,
0x303239315f345f74ull,0x2020202020203b32ull,0x2f200a202f2f0920ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3320656e696c2079ull,0x64616568202c3235ull,
0x64656c6562616c20ull,0x315f345f744c2420ull,0x7262090a32323937ull,0x240920696e752e61ull,
0x3638315f345f744cull,0x20202020203b3039ull,0x202f2f0920202020ull,0x325f345f744c240aull,
0x2f200a3a38393233ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3320656e696c2079ull,0x64616568202c3235ull,0x64656c6562616c20ull,0x315f345f744c2420ull,
0x744c240a32323937ull,0x30393638315f345full,0x5f345f744c240a3aull,0x2f2f200a3a343135ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353320656e696c20ull,
0x2064616568202c32ull,0x2064656c6562616cull,0x37315f345f744c24ull,0x6f6c2e090a323239ull,
0x3732330936310963ull,0x2e766f6d090a3009ull,0x3466250920323366ull,0x3b31356625202c38ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x25202c3734662509ull,
0x202020203b303566ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3466250920323366ull,
0x3b39346625202c36ull,0x2020202020202020ull,0x240a202f2f092020ull,0x3835325f345f744cull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c32353320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32323937315f345full,
0x3109636f6c2e090aull,0x0a30093136330936ull,0x3233662e64646109ull,0x202c353466250920ull,
0x6625202c38346625ull,0x09202020203b3534ull,0x646461090a202f2full,0x662509203233662eull,
0x37346625202c3434ull,0x203b34346625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c333466250920ull,0x6625202c36346625ull,0x09202020203b3334ull,0x646461090a202f2full,
0x722509203233732eull,0x39317225202c3931ull,0x202020203b31202cull,0x0a202f2f09202020ull,
0x3233752e766f6d09ull,0x202c343772250920ull,0x2020202020203b32ull,0x0920202020202020ull,
0x746573090a202f2full,0x3233732e656e2e70ull,0x202c363170250920ull,0x7225202c39317225ull,
0x0a202f2f093b3437ull,0x6220363170254009ull,0x5f744c2409206172ull,0x3b32323937315f34ull,
0x0920202020202020ull,0x3c2f2f200a202f2full,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x32353320656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3137315f345f744cull,0x2e646461090a3435ull,0x3172250920323373ull,0x2c38317225202c38ull,
0x20202020203b3120ull,0x090a202f2f092020ull,0x203233752e766f6dull,0x32202c3537722509ull,
0x202020202020203bull,0x2f09202020202020ull,0x70746573090a202full,0x203233732e656e2eull,
0x25202c3731702509ull,0x377225202c383172ull,0x090a202f2f093b35ull,0x7262203731702540ull,
0x345f744c24092061ull,0x203b34353137315full,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c32353320656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x383336315f345f74ull,0x732e646461090a36ull,
0x3731722509203233ull,0x202c37317225202cull,0x2020202020203b31ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x3b32202c36377225ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e656eull,0x7225202c38317025ull,0x36377225202c3731ull,
0x40090a202f2f093bull,0x6172622038317025ull,0x5f345f744c240920ull,0x20203b3638333631ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009343132093631ull,0x6e6f632e646c090aull,
0x09203233662e7473ull,0x5b202c3431316625ull,0x312b736d61726170ull,0x69202f2f093b5d36ull,
0x6170203230353a64ull,0x3178302b736d6172ull,0x662e646461090a30ull,0x3131662509203233ull,
0x3431316625202c35ull,0x203b32346625202cull,0x6c090a202f2f0920ull,0x2e74736e6f632e64ull,
0x3166250920323366ull,0x7261705b202c3631ull,0x093b5d342b736d61ull,0x30353a6469202f2full,
0x736d617261702033ull,0x7573090a3478302bull,0x2509203233662e62ull,0x6625202c37313166ull,
0x366625202c363131ull,0x202f2f092020203bull,0x6e6f632e646c090aull,0x09203233662e7473ull,
0x5b202c3831316625ull,0x302b736d61726170ull,0x6469202f2f093b5dull,0x726170203430353aull,
0x0a3078302b736d61ull,0x3233662e62757309ull,0x2c39313166250920ull,0x202c383131662520ull,
0x092020203b356625ull,0x2e646c090a202f2full,0x33662e74736e6f63ull,0x3032316625092032ull,
0x6d617261705b202cull,0x2f2f093b5d382b73ull,0x203530353a646920ull,0x302b736d61726170ull,
0x2e627573090a3878ull,0x3166250920323366ull,0x32316625202c3132ull,0x203b376625202c30ull,
0x090a202f2f092020ull,0x203233662e6c756dull,0x202c323231662509ull,0x25202c3731316625ull,
0x2f09203b37313166ull,0x2e64616d090a202full,0x3166250920323366ull,0x31316625202c3332ull,
0x3931316625202c39ull,0x3b3232316625202cull,0x616d090a202f2f09ull,0x2509203233662e64ull,
0x6625202c34323166ull,0x316625202c313231ull,0x32316625202c3132ull,0x090a202f2f093b33ull,
0x7070612e74727173ull,0x203233662e786f72ull,0x202c353231662509ull,0x2f093b3432316625ull,
0x70746573090a202full,0x203233662e74672eull,0x25202c3931702509ull,0x6625202c35313166ull,
0x202f2f093b353231ull,0x393170252140090aull,0x4c24092061726220ull,0x363731325f345f74ull,
0x2020202020203b32ull,0x6c2e090a202f2f09ull,0x323209363109636full,0x67656e090a300938ull,
0x662509203233662eull,0x316625202c363231ull,0x2020202020203b32ull,0x0a202f2f09202020ull,
0x3233662e67656e09ull,0x2c37323166250920ull,0x20203b3431662520ull,0x0920202020202020ull,
0x717372090a202f2full,0x6f727070612e7472ull,0x2509203233662e78ull,0x6625202c38323166ull,
0x202f2f093b343231ull,0x33662e6c756d090aull,0x3932316625092032ull,0x2c3731316625202cull,
0x203b383231662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c30333166ull,
0x316625202c393131ull,0x202f2f09203b3832ull,0x33662e6c756d090aull,0x3133316625092032ull,
0x2c3132316625202cull,0x203b383231662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x6625202c32333166ull,0x316625202c393231ull,0x202f2f0920203b33ull,0x33662e67656e090aull,
0x3333316625092032ull,0x3b3233316625202cull,0x2020202020202020ull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c34333166ull,0x316625202c303331ull,0x33316625202c3632ull,
0x090a202f2f093b33ull,0x203233662e64616dull,0x202c353331662509ull,0x25202c3133316625ull,
0x6625202c37323166ull,0x202f2f093b343331ull,0x33662e64616d090aull,0x3633316625092032ull,
0x2c3033316625202cull,0x202c353331662520ull,0x2f2f093b32316625ull,0x662e67656e090a20ull,
0x3331662509203233ull,0x3633316625202c37ull,0x202020202020203bull,0x6d090a202f2f0920ull,
0x09203233662e6461ull,0x25202c3833316625ull,0x6625202c39323166ull,0x316625202c353331ull,
0x090a202f2f093b33ull,0x203233662e67656eull,0x202c393331662509ull,0x20203b3833316625ull,
0x2f09202020202020ull,0x2e64616d090a202full,0x3166250920323366ull,0x33316625202c3034ull,
0x3533316625202c31ull,0x093b34316625202cull,0x67656e090a202f2full,0x662509203233662eull,
0x316625202c313431ull,0x20202020203b3034ull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,
0x090a300935333209ull,0x203233662e627573ull,0x202c323431662509ull,0x25202c3531316625ull,
0x2f09203b35323166ull,0x632e646c090a202full,0x3233662e74736e6full,0x2c33343166250920ull,
0x736d617261705b20ull,0x2f2f093b5d38382bull,0x203130353a646920ull,0x302b736d61726170ull,
0x6c756d090a383578ull,0x662509203233662eull,0x316625202c343431ull,0x34316625202c3334ull,
0x0a202f2f09203b32ull,0x736e6f632e646c09ull,0x2509203233662e74ull,0x705b202c35343166ull,
0x32392b736d617261ull,0x6469202f2f093b5dull,0x726170203836343aull,0x633578302b736d61ull,
0x6e6f632e646c090aull,0x09203233662e7473ull,0x5b202c3634316625ull,0x392b736d61726170ull,
0x69202f2f093b5d36ull,0x6170203936343a64ull,0x3678302b736d6172ull,0x662e6c756d090a30ull,
0x3431662509203233ull,0x3033316625202c37ull,0x3b3434316625202cull,0x6d090a202f2f0920ull,
0x09203233662e6461ull,0x25202c3834316625ull,0x316625202c323166ull,0x34316625202c3534ull,
0x090a202f2f093b37ull,0x203233662e6c756dull,0x202c393431662509ull,0x25202c3733316625ull,
0x2f09203b36343166ull,0x2e627573090a202full,0x3166250920323366ull,0x34316625202c3035ull,
0x3834316625202c39ull,0x090a202f2f09203bull,0x203233662e6c756dull,0x202c313531662509ull,
0x25202c3932316625ull,0x2f09203b34343166ull,0x2e64616d090a202full,0x3166250920323366ull,
0x33316625202c3235ull,0x2c3534316625202cull,0x093b313531662520ull,0x6c756d090a202f2full,
0x662509203233662eull,0x316625202c333531ull,0x34316625202c3933ull,0x0a202f2f09203b36ull,
0x3233662e62757309ull,0x2c34353166250920ull,0x202c333531662520ull,0x09203b3235316625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x316625202c353531ull,0x34316625202c3133ull,
0x0a202f2f09203b34ull,0x3233662e64616d09ull,0x2c36353166250920ull,0x25202c3431662520ull,
0x6625202c35343166ull,0x202f2f093b353531ull,0x33662e6c756d090aull,0x3735316625092032ull,
0x2c3134316625202cull,0x203b363431662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,
0x6625202c38353166ull,0x316625202c373531ull,0x202f2f09203b3635ull,0x6e752e617262090aull,
0x345f744c24092069ull,0x203b36303531325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x32363731325f345full,0x662e766f6d090a3aull,0x3531662509203233ull,0x3030306630202c38ull,
0x20203b3030303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,0x202c343531662509ull,
0x3030303030306630ull,0x2f092020203b3030ull,0x766f6d090a30202full,0x662509203233662eull,
0x306630202c303531ull,0x3b30303030303030ull,0x30202f2f09202020ull,0x325f345f744c240aull,
0x2e090a3a36303531ull,0x3309363109636f6cull,0x6461090a30093037ull,0x2509203233662e64ull,
0x316625202c353466ull,0x35346625202c3035ull,0x202f2f092020203bull,0x33662e646461090aull,
0x2c34346625092032ull,0x202c343531662520ull,0x2020203b34346625ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x316625202c333466ull,0x33346625202c3835ull,0x202f2f092020203bull,
0x3109636f6c2e090aull,0x0a30093737330936ull,0x617261702e646c09ull,0x2509203436752e6dull,
0x5f5f5b202c316472ull,0x6d72617061647563ull,0x6c6c6f63385a5f5full,0x6c66365044656469ull,
0x535f30533474616full,0x7535505f30535f30ull,0x705f6a5032746e69ull,0x48656c6369747261ull,
0x2f2f093b5d687361ull,0x203630353a646920ull,0x6170616475635f5full,0x6f63385a5f5f6d72ull,
0x3650446564696c6cull,0x30533474616f6c66ull,0x505f30535f30535full,0x6a5032746e697535ull,
0x6c6369747261705full,0x78302b6873614865ull,0x752e747663090a30ull,0x09203233732e3436ull,
0x7225202c32647225ull,0x2020202020203b35ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x2c33647225092034ull,0x38202c3264722520ull,0x2f2f09202020203bull,0x752e646461090a20ull,
0x3464722509203436ull,0x202c31647225202cull,0x2020203b33647225ull,0x6c090a202f2f0920ull,
0x6c61626f6c672e64ull,0x203233752e32762eull,0x252c373772257b09ull,0x255b202c7d383772ull,
0x093b5d302b346472ull,0x766f6d090a202f2full,0x722509203233732eull,0x37377225202c3937ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c303872250920ull,
0x2020203b38377225ull,0x0920202020202020ull,0x6f6c2e090a202f2full,0x3537330936310963ull,
0x702e646c090a3009ull,0x3436752e6d617261ull,0x202c356472250920ull,0x70616475635f5f5bull,
0x63385a5f5f6d7261ull,0x50446564696c6c6full,0x533474616f6c6636ull,0x5f30535f30535f30ull,
0x5032746e69753550ull,0x6c655677656e5f6aull,0x6469202f2f093b5dull,0x635f5f203037343aull,
0x5f6d726170616475ull,0x696c6c6f63385a5full,0x6f6c663650446564ull,0x30535f3053347461ull,
0x697535505f30535full,0x656e5f6a5032746eull,0x3078302b6c655677ull,0x33662e646461090aull,
0x3935316625092032ull,0x202c32316625202cull,0x2020203b35346625ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x387225202c313872ull,0x2020202020203b30ull,0x202f2f0920202020ull,
0x36752e747663090aull,0x2509203233752e34ull,0x387225202c366472ull,0x2020202020203b31ull,
0x756d090a202f2f09ull,0x3436752e6f6c2e6cull,0x202c376472250920ull,0x3631202c36647225ull,
0x202f2f092020203bull,0x36752e646461090aull,0x2c38647225092034ull,0x25202c3564722520ull,
0x202020203b376472ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,0x72255b0920323366ull,
0x25202c5d302b3864ull,0x2f2f093b39353166ull,0x0a3131353a646920ull,0x3233662e64646109ull,
0x2c30363166250920ull,0x25202c3331662520ull,0x092020203b343466ull,0x766f6d090a202f2full,
0x722509203233732eull,0x30387225202c3238ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3436752e74766309ull,0x722509203233752eull,0x32387225202c3964ull,0x092020202020203bull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c303164722509ull,0x3631202c39647225ull,
0x0a202f2f0920203bull,0x3436752e64646109ull,0x2c31316472250920ull,0x25202c3564722520ull,
0x0920203b30316472ull,0x2e7473090a202f2full,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x25202c5d342b3131ull,0x2f2f093b30363166ull,0x0a3231353a646920ull,0x3233662e64646109ull,
0x2c31363166250920ull,0x25202c3431662520ull,0x092020203b333466ull,0x766f6d090a202f2full,
0x722509203233732eull,0x30387225202c3338ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3436752e74766309ull,0x722509203233752eull,0x387225202c323164ull,0x0920202020203b33ull,
0x6c756d090a202f2full,0x203436752e6f6c2eull,0x202c333164722509ull,0x31202c3231647225ull,
0x0a202f2f09203b36ull,0x3436752e64646109ull,0x2c34316472250920ull,0x25202c3564722520ull,
0x0920203b33316472ull,0x2e7473090a202f2full,0x662e6c61626f6c67ull,0x6472255b09203233ull,
0x25202c5d382b3431ull,0x2f2f093b31363166ull,0x0a3331353a646920ull,0x3233732e766f6d09ull,
0x202c343872250920ull,0x2020203b30387225ull,0x0920202020202020ull,0x747663090a202f2full,
0x3233752e3436752eull,0x2c35316472250920ull,0x20203b3438722520ull,0x0a202f2f09202020ull,
0x2e6f6c2e6c756d09ull,0x6472250920343675ull,0x31647225202c3631ull,0x09203b3631202c35ull,
0x646461090a202f2full,0x722509203436752eull,0x647225202c373164ull,0x3631647225202c35ull,
0x0a202f2f0920203bull,0x626f6c672e747309ull,0x09203233662e6c61ull,0x312b37316472255bull,
0x35316625202c5d32ull,0x3a6469202f2f093bull,0x6f6c2e090a343135ull,0x3937330936310963ull,
0x74697865090a3009ull,0x202020202020203bull,0x2020202020202020ull,0x2020202020202020ull,
0x240a202f2f092020ull,0x5f5f646e6557444cull,0x64696c6c6f63385aull,0x616f6c6636504465ull,
0x5f30535f30533474ull,0x6e697535505f3053ull,0x7d090a3a6a503274ull,0x63385a5f202f2f20ull,
0x50446564696c6c6full,0x533474616f6c6636ull,0x5f30535f30535f30ull,0x5032746e69753550ull,
0x00000000000a0a6aull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"916bcf5d6548fba2",(char*)"particles_kernel.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0,0xce663b14};
# 5 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.stub.c" 2
struct __T20 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float __par4;int __dummy_field;};
struct __T21 {float4 *__par0;uint *__par1;uint *__par2;int __dummy_field;volatile char __dummy[4];};
struct __T22 {float4 *__par0;uint2 *__par1;int __dummy_field;volatile char __dummy[4];};
struct __T23 {uint2 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;float4 *__par4;uint *__par5;int __dummy_field;volatile char __dummy[4];};
struct __T24 {float4 *__par0;float4 *__par1;float4 *__par2;float4 *__par3;uint2 *__par4;uint *__par5;int __dummy_field;volatile char __dummy[4];};
static void __sti____cudaRegisterAll_52_tmpxft_000062f6_00000000_20_particles_kernel_cpp1_ii_dee98040(void) __attribute__((__constructor__));
void __device_stub__Z9integrateP6float4S0_S0_S0_f(float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float __par4){auto struct __T20 *__T25;
char __[256]; *(char**)&__T25 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T25->__par2 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T25->__par3 - (size_t)__T25) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T25->__par4 - (size_t)__T25) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry))); };}

}
void integrate__entry( float4 * __cuda_0,float4 * __cuda_1,float4 * __cuda_2,float4 * __cuda_3,float __cuda_4)
{__device_stub__Z9integrateP6float4S0_S0_S0_f( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4);}
extern "C"{

void __device_stub__Z11updateGridDP6float4PjS1_(float4 *__par0, uint *__par1, uint *__par2){auto struct __T21 *__T220;
char __[256]; *(char**)&__T220 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T220->__par0 - (size_t)__T220) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T220->__par1 - (size_t)__T220) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T220->__par2 - (size_t)__T220) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint *, uint *))updateGridD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint *, uint *))updateGridD__entry))); };}

}
void updateGridD__entry( float4 * __cuda_0,uint * __cuda_1,uint * __cuda_2)
{__device_stub__Z11updateGridDP6float4PjS1_( __cuda_0, __cuda_1, __cuda_2);}
extern "C"{

void __device_stub__Z9calcHashDP6float4P5uint2(float4 *__par0, uint2 *__par1){auto struct __T22 *__T221;
char __[256]; *(char**)&__T221 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T221->__par0 - (size_t)__T221) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T221->__par1 - (size_t)__T221) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, uint2 *))calcHashD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, uint2 *))calcHashD__entry))); };}

}
void calcHashD__entry( float4 * __cuda_0,uint2 * __cuda_1)
{__device_stub__Z9calcHashDP6float4P5uint2( __cuda_0, __cuda_1);}
extern "C"{

void __device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj(uint2 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, float4 *__par4, uint *__par5){auto struct __T23 *__T222;
char __[256]; *(char**)&__T222 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T222->__par0 - (size_t)__T222) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T222->__par1 - (size_t)__T222) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T222->__par2 - (size_t)__T222) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T222->__par3 - (size_t)__T222) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T222->__par4 - (size_t)__T222) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T222->__par5 - (size_t)__T222) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry)); (void)cudaLaunch(((char *)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry))); };}

}
void reorderDataAndFindCellStartD__entry( uint2 * __cuda_0,float4 * __cuda_1,float4 * __cuda_2,float4 * __cuda_3,float4 * __cuda_4,uint * __cuda_5)
{__device_stub__Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5);}
extern "C"{

void __device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj(float4 *__par0, float4 *__par1, float4 *__par2, float4 *__par3, uint2 *__par4, uint *__par5){auto struct __T24 *__T2135;
char __[256]; *(char**)&__T2135 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2135->__par0 - (size_t)__T2135) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2135->__par1 - (size_t)__T2135) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2135->__par2 - (size_t)__T2135) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2135->__par3 - (size_t)__T2135) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2135->__par4 - (size_t)__T2135) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2135->__par5 - (size_t)__T2135) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry)); (void)cudaLaunch(((char *)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry))); };}

}
void collideD__entry( float4 * __cuda_0,float4 * __cuda_1,float4 * __cuda_2,float4 * __cuda_3,uint2 * __cuda_4,uint * __cuda_5)
{__device_stub__Z8collideDP6float4S0_S0_S0_P5uint2Pj( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5);}
extern "C"{
# 67 "/tmp/tmpxft_000062f6_00000000-4_particles_kernel.cudafe1.stub.c"
static void __sti____cudaRegisterAll_52_tmpxft_000062f6_00000000_20_particles_kernel_cpp1_ii_dee98040(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, uint2 *, uint *))collideD__entry), (char*)"_Z8collideDP6float4S0_S0_S0_P5uint2Pj", "_Z8collideDP6float4S0_S0_S0_P5uint2Pj", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uint2 *, float4 *, float4 *, float4 *, float4 *, uint *))reorderDataAndFindCellStartD__entry), (char*)"_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", "_Z28reorderDataAndFindCellStartDP5uint2P6float4S2_S2_S2_Pj", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint2 *))calcHashD__entry), (char*)"_Z9calcHashDP6float4P5uint2", "_Z9calcHashDP6float4P5uint2", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, uint *, uint *))updateGridD__entry), (char*)"_Z11updateGridDP6float4PjS1_", "_Z11updateGridDP6float4PjS1_", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float4 *, float4 *, float4 *, float4 *, float))integrate__entry), (char*)"_Z9integrateP6float4S0_S0_S0_f", "_Z9integrateP6float4S0_S0_S0_f", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldPosTex, 0, "oldPosTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&oldVelTex, 0, "oldVelTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&particleHashTex, 0, "particleHashTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&cellStartTex, 0, "cellStartTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCountersTex, 0, "gridCountersTex", 1, 0, 0);__cudaRegisterTexture(__cudaFatCubinHandle, (const struct textureReference*)&gridCellsTex, 0, "gridCellsTex", 1, 0, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&__shadow_params, (char*)"params", "params", 0, 112, 1, 0);}

}
# 382 "particles_kernel.cu" 2

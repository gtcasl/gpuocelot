# 1 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.cpp"
# 1 "Mandelbrot_sm10.cu"
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
# 6 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm10(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int, const int);
extern "C" void RunMandelbrot1_sm10(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int, const int);

extern "C" void RunMandelbrot0_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int, const int, const int);
extern "C" void RunMandelbrot1_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int, const int, const int);
# 15 "Mandelbrot_kernel.cu"
inline void dsdeq(float &a0, float &a1, double b)
{
a0 = (float)b;
a1 = (float)(b - a0);
}
# 364 "Mandelbrot_kernel.cu"
inline int iDivUp(int a, int b)
{
return ((a % b) != 0) ? (a / b + 1) : (a / b);
}
# 7 "Mandelbrot_sm10.cu"
template<class T> static void
__wrapper__device_stub_Mandelbrot0_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &scale, const uchar4 &colors, const int &frame, const int &animationFrame);
# 7 "Mandelbrot_sm10.cu"
template<class T> void
Mandelbrot0_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T scale, const uchar4 colors, const int frame, const int animationFrame){__wrapper__device_stub_Mandelbrot0_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,scale,colors,frame,animationFrame);}
# 51 "Mandelbrot_sm10.cu"
void MandelbrotDS0_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float yOff0, const float yOff1, const float scale, const uchar4 colors, const int frame, const int animationFrame);
# 98 "Mandelbrot_sm10.cu"
template<class T> static void
__wrapper__device_stub_Mandelbrot1_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &scale, const uchar4 &colors, const int &frame, const int &animationFrame);
# 98 "Mandelbrot_sm10.cu"
template<class T> void
Mandelbrot1_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T scale, const uchar4 colors, const int frame, const int animationFrame){__wrapper__device_stub_Mandelbrot1_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,scale,colors,frame,animationFrame);}
# 152 "Mandelbrot_sm10.cu"
void MandelbrotDS1_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float yOff0, const float yOff1, const float scale, const uchar4 colors, const int frame, const int animationFrame);
# 209 "Mandelbrot_sm10.cu"
void RunMandelbrot0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode)
{
auto dim3 threads(16, 16);
auto dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));

switch (mode) {
default:
case 0:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10__entry< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)scale, colors, frame, animationFrame);
break;
case 1:
auto float x0; auto float x1; auto float y0; auto float y1;
dsdeq(x0, x1, xOff);
dsdeq(y0, y1, yOff);
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS0_sm10__entry(dst, imageW, imageH, crunch, x0, x1, y0, y1, (float)scale, colors, frame, animationFrame);
break;
case 2:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10__entry< double> )(dst, imageW, imageH, crunch, xOff, yOff, scale, colors, frame, animationFrame);
break;
}
__cutilCheckMsg("Mandelbrot0_sm10 kernel execution failed.\n", "Mandelbrot_sm10.cu", 229);
}


void RunMandelbrot1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int mode)
{
auto dim3 threads(16, 16);
auto dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));

switch (mode) {
default:
case 0:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10__entry< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)scale, colors, frame, animationFrame);
break;
case 1:
auto float x0; auto float x1; auto float y0; auto float y1;
dsdeq(x0, x1, xOff);
dsdeq(y0, y1, yOff);
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS1_sm10__entry(dst, imageW, imageH, crunch, x0, x1, y0, y1, (float)scale, colors, frame, animationFrame);
break;
case 2:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10__entry< double> )(dst, imageW, imageH, crunch, xOff, yOff, scale, colors, frame, animationFrame);
break;
}

__cutilCheckMsg("Mandelbrot1_sm10 kernel execution failed.\n", "Mandelbrot_sm10.cu", 254);
}

# 1 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_000062e6_00000000-6_Mandelbrot_sm10.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000062e6_00000000-6_Mandelbrot_sm10.fatbin.c" 2




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
0x78706d742f706d74ull,0x36303030305f7466ull,0x303030305f366532ull,0x5f30322d30303030ull,
0x72626c65646e614dull,0x2e30316d735f746full,0x2820692e33707063ull,0x4263632f706d742full,
0x386b3742442e2349ull,0x2d2d2f2f090a2950ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
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
0x2f22093209656c69ull,0x78706d742f706d74ull,0x36303030305f7466ull,0x303030305f366532ull,
0x5f39312d30303030ull,0x72626c65646e614dull,0x2e30316d735f746full,0x2e32656661647563ull,
0x662e090a22757067ull,0x2f22093309656c69ull,0x2f62696c2f727375ull,0x5f3638782f636367ull,
0x78756e696c2d3436ull,0x332e342f756e672dull,0x756c636e692f332eull,0x65646474732f6564ull,
0x662e090a22682e66ull,0x2f22093409656c69ull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x697665642f747263ull,0x69746e75725f6563ull,
0x2e090a22682e656dull,0x22093509656c6966ull,0x6f6e2f656d6f682full,0x6475632f6c616d72ull,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x65645f74736f682full,0x22682e73656e6966ull,
0x09656c69662e090aull,0x656d6f682f220936ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x6c6975622f656475ull,0x657079745f6e6974ull,0x662e090a22682e73ull,
0x2f22093709656c69ull,0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x745f656369766564ull,0x0a22682e73657079ull,0x3809656c69662e09ull,
0x2f656d6f682f2209ull,0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x65766972642f6564ull,0x2e73657079745f72ull,0x6c69662e090a2268ull,0x6f682f2209390965ull,
0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65742f6564756c63ull,
0x79745f6572757478ull,0x090a22682e736570ull,0x303109656c69662eull,0x2f656d6f682f2209ull,
0x632f6c616d726f6eull,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x6f746365762f6564ull,
0x2e73657079745f72ull,0x6c69662e090a2268ull,0x682f220931310965ull,0x6d726f6e2f656d6full,
0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x616c5f6563697665ull,
0x7261705f68636e75ull,0x2e73726574656d61ull,0x6c69662e090a2268ull,0x682f220932310965ull,
0x6d726f6e2f656d6full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,
0x61726f74732f7472ull,0x7373616c635f6567ull,0x69662e090a22682eull,0x2f2209333109656cull,
0x6c636e692f727375ull,0x737469622f656475ull,0x682e73657079742full,0x656c69662e090a22ull,
0x73752f2209343109ull,0x64756c636e692f72ull,0x682e656d69742f65ull,0x656c69662e090a22ull,
0x6e614d2209353109ull,0x5f746f72626c6564ull,0x632e6c656e72656bull,0x6c69662e090a2275ull,
0x614d220936310965ull,0x746f72626c65646eull,0x75632e30316d735full,0x656c69662e090a22ull,
0x6f682f2209373109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6f632f6564756c63ull,0x6e75665f6e6f6d6dull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209383109ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x72632f6564756c63ull,0x6d5f636e75662f74ull,0x0a22682e6f726361ull,0x3109656c69662e09ull,
0x656d6f682f220939ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6874616d2f656475ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09303209656c6966ull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x6563697665642f65ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09313209656c6966ull,
0x6e2f656d6f682f22ull,0x75632f6c616d726full,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x635f6874616d2f65ull,0x73746e6174736e6full,0x69662e090a22682eull,0x2f2209323209656cull,
0x726f6e2f656d6f68ull,0x616475632f6c616dull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x74615f31315f6d73ull,0x6e75665f63696d6full,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x6f682f2209333209ull,0x616d726f6e2f656dull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x6d732f6564756c63ull,0x6d6f74615f32315full,0x74636e75665f6369ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x656d6f682f220934ull,0x2f6c616d726f6e2full,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x656c62756f645f33ull,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09353209656c6966ull,0x6e2f656d6f682f22ull,0x75632f6c616d726full,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x7275747865742f65ull,0x5f68637465665f65ull,
0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209363209656c69ull,0x6f6e2f656d6f682full,
0x6475632f6c616d72ull,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x75665f6874616d2full,
0x5f736e6f6974636eull,0x337874705f6c6264ull,0x2e090a0a0a22682eull,0x5a5f207972746e65ull,
0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x69695f5366666666ull,0x61702e09090a2820ull,0x3436752e206d6172ull,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f305344746full,0x6168637536503031ull,
0x6666666969693472ull,0x645f69695f536666ull,0x702e09090a2c7473ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f305344746f72ull,
0x686375365030316dull,0x6666696969347261ull,0x5f69695f53666666ull,0x0a2c576567616d69ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x6e614d38315a5f5full,
0x44746f72626c6564ull,0x5030316d735f3053ull,0x6934726168637536ull,0x5366666666666969ull,
0x67616d695f69695full,0x702e09090a2c4865ull,0x33732e206d617261ull,0x616475635f5f2032ull,
0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,
0x6666696969347261ull,0x5f69695f53666666ull,0x0a2c68636e757263ull,0x6d617261702e0909ull,
0x5f5f203233662e20ull,0x6d72617061647563ull,0x6e614d38315a5f5full,0x44746f72626c6564ull,
0x5030316d735f3053ull,0x6934726168637536ull,0x5366666666666969ull,0x66664f785f69695full,
0x61702e09090a2c30ull,0x3233662e206d6172ull,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,
0x785f69695f536666ull,0x09090a2c3166664full,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x65646e614d38315aull,0x305344746f72626cull,0x75365030316d735full,
0x6969693472616863ull,0x695f536666666666ull,0x2c3066664f795f69ull,0x617261702e09090aull,
0x5f203233662e206dull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f305344ull,0x3472616863753650ull,0x6666666666696969ull,0x664f795f69695f53ull,
0x702e09090a2c3166ull,0x33662e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x5f69695f53666666ull,0x090a2c656c616373ull,0x206d617261702e09ull,0x34206e67696c612eull,
0x635f5f2038622e20ull,0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f30ull,0x6969347261686375ull,0x5f53666666666669ull,0x726f6c6f635f6969ull,
0x09090a2c5d345b73ull,0x2e206d617261702eull,0x75635f5f20323373ull,0x5f5f6d7261706164ull,
0x65646e614d38315aull,0x305344746f72626cull,0x75365030316d735full,0x6969693472616863ull,
0x695f536666666666ull,0x2c656d6172665f69ull,0x617261702e09090aull,0x5f203233732e206dull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,
0x3472616863753650ull,0x6666666666696969ull,0x696e615f69695f53ull,0x72466e6f6974616dull,
0x0a7b090a29656d61ull,0x752e206765722e09ull,0x363c687225203631ull,0x6765722e090a3b3eull,
0x7225203233752e20ull,0x2e090a3b3e32363cull,0x3436752e20676572ull,0x3b3e363c64722520ull,
0x2e206765722e090aull,0x323c662520323366ull,0x722e090a3b3e3233ull,0x646572702e206765ull,
0x3b3e30313c702520ull,0x3109636f6c2e090aull,0x240a300931350936ull,0x315a5f5f3142424cull,
0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x3a69695f53666666ull,0x31752e766f6d090aull,0x2c31687225092036ull,0x2e64696174632520ull,
0x2020202020203b78ull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,0x746e25202c326872ull,
0x2020203b782e6469ull,0x202f2f0920202020ull,0x69772e6c756d090aull,0x09203631752e6564ull,
0x687225202c317225ull,0x3b32687225202c31ull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,
0x746325202c336872ull,0x20203b792e646961ull,0x202f2f0920202020ull,0x31752e766f6d090aull,
0x2c34687225092036ull,0x792e6469746e2520ull,0x202020202020203bull,0x756d090a202f2f09ull,
0x752e656469772e6cull,0x2c32722509203631ull,0x25202c3368722520ull,0x202f2f093b346872ull,
0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3372ull,0x20202020203b782eull,
0x6461090a202f2f09ull,0x2509203233752e64ull,0x2c337225202c3472ull,0x2020203b31722520ull,
0x202f2f0920202020ull,0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3572ull,
0x20202020203b792eull,0x6461090a202f2f09ull,0x2509203233752e64ull,0x2c357225202c3672ull,
0x2020203b32722520ull,0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5f5f5b202c377225ull,0x6d72617061647563ull,0x6e614d38315a5f5full,0x44746f72626c6564ull,
0x5030316d735f3053ull,0x6934726168637536ull,0x5366666666666969ull,0x67616d695f69695full,
0x202f2f093b5d5765ull,0x5f203938353a6469ull,0x726170616475635full,0x614d38315a5f5f6dull,
0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,0x6666666666696969ull,
0x616d695f69695f53ull,0x0a3078302b576567ull,0x617261702e646c09ull,0x2509203233732e6dull,
0x635f5f5b202c3872ull,0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f30ull,0x6969347261686375ull,0x5f53666666666669ull,0x6567616d695f6969ull,
0x69202f2f093b5d48ull,0x5f5f203639353a64ull,0x6d72617061647563ull,0x6e614d38315a5f5full,
0x44746f72626c6564ull,0x5030316d735f3053ull,0x6934726168637536ull,0x5366666666666969ull,
0x67616d695f69695full,0x090a3078302b4865ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x387225202c397225ull,0x2f093b367225202cull,0x2e67656e090a202full,0x3172250920323373ull,
0x203b397225202c30ull,0x2020202020202020ull,0x090a202f2f092020ull,0x752e74672e746573ull,
0x09203233732e3233ull,0x7225202c31317225ull,0x093b347225202c37ull,0x67656e090a202f2full,
0x722509203233732eull,0x31317225202c3231ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233622e646e6109ull,0x202c333172250920ull,0x7225202c30317225ull,0x09202020203b3231ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3431ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x2c33317225202c31ull,
0x09203b3431722520ull,0x702540090a202f2full,0x2409206172622031ull,0x3731375f305f744cull,
0x2020202020203b30ull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x63090a3009323609ull,
0x33662e6e722e7476ull,0x2509203233732e32ull,0x3b347225202c3166ull,0x2f2f092020202020ull,
0x61702e646c090a20ull,0x203233662e6d6172ull,0x5f5b202c32662509ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x6163735f69695f53ull,0x202f2f093b5d656cull,0x5f203838353a6469ull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,
0x3472616863753650ull,0x6666666666696969ull,0x6163735f69695f53ull,0x090a3078302b656cull,
0x203233662e6c756dull,0x6625202c33662509ull,0x203b326625202c31ull,0x2f09202020202020ull,
0x702e646c090a202full,0x3233662e6d617261ull,0x5b202c3466250920ull,0x6170616475635f5full,
0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x4f785f69695f5366ull,0x2f2f093b5d306666ull,0x203738353a646920ull,
0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,
0x7261686375365030ull,0x6666666669696934ull,0x4f785f69695f5366ull,0x0a3078302b306666ull,
0x3233662e64646109ull,0x25202c3566250920ull,0x3b346625202c3366ull,0x0920202020202020ull,
0x627573090a202f2full,0x662509203233662eull,0x202c356625202c36ull,0x202020203b336625ull,
0x0a202f2f09202020ull,0x3233662e62757309ull,0x25202c3766250920ull,0x3b366625202c3466ull,
0x0920202020202020ull,0x627573090a202f2full,0x662509203233662eull,0x202c356625202c38ull,
0x202020203b366625ull,0x0a202f2f09202020ull,0x3233662e62757309ull,0x25202c3966250920ull,
0x3b386625202c3366ull,0x0920202020202020ull,0x646461090a202f2full,0x662509203233662eull,
0x2c376625202c3031ull,0x2020203b39662520ull,0x0a202f2f09202020ull,0x617261702e646c09ull,
0x2509203233662e6dull,0x5f5f5b202c313166ull,0x6d72617061647563ull,0x6e614d38315a5f5full,
0x44746f72626c6564ull,0x5030316d735f3053ull,0x6934726168637536ull,0x5366666666666969ull,
0x66664f785f69695full,0x69202f2f093b5d31ull,0x5f5f203739353a64ull,0x6d72617061647563ull,
0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3053ull,0x6934726168637536ull,
0x5366666666666969ull,0x66664f785f69695full,0x61090a3078302b31ull,0x09203233662e6464ull,
0x6625202c32316625ull,0x30316625202c3131ull,0x2f2f09202020203bull,0x662e646461090a20ull,
0x3331662509203233ull,0x25202c356625202cull,0x202020203b323166ull,0x73090a202f2f0920ull,
0x09203233662e6275ull,0x6625202c34316625ull,0x3b356625202c3331ull,0x2f2f092020202020ull,
0x662e627573090a20ull,0x3531662509203233ull,0x202c32316625202cull,0x2020203b34316625ull,
0x2e090a202f2f0920ull,0x3609363109636f6cull,0x747663090a300933ull,0x2e3233662e6e722eull,
0x3166250920323373ull,0x203b367225202c36ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,
0x202c373166250920ull,0x6625202c36316625ull,0x0920202020203b32ull,0x2e646c090a202f2full,
0x33662e6d61726170ull,0x2c38316625092032ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x5f69695f53666666ull,0x093b5d3066664f79ull,0x38353a6469202f2full,0x616475635f5f2036ull,
0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,
0x6666696969347261ull,0x5f69695f53666666ull,0x78302b3066664f79ull,0x662e646461090a30ull,
0x3931662509203233ull,0x202c37316625202cull,0x2020203b38316625ull,0x73090a202f2f0920ull,
0x09203233662e6275ull,0x6625202c30326625ull,0x37316625202c3931ull,0x2f2f09202020203bull,
0x662e627573090a20ull,0x3132662509203233ull,0x202c38316625202cull,0x2020203b30326625ull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c32326625ull,0x30326625202c3931ull,
0x2f2f09202020203bull,0x662e627573090a20ull,0x3332662509203233ull,0x202c37316625202cull,
0x2020203b32326625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c34326625ull,
0x33326625202c3132ull,0x2f2f09202020203bull,0x61702e646c090a20ull,0x203233662e6d6172ull,
0x5b202c3532662509ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,
0x316d735f30534474ull,0x7261686375365030ull,0x6666666669696934ull,0x4f795f69695f5366ull,
0x2f2f093b5d316666ull,0x203839353a646920ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,
0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,0x6666666669696934ull,
0x4f795f69695f5366ull,0x0a3078302b316666ull,0x3233662e64646109ull,0x202c363266250920ull,
0x6625202c35326625ull,0x09202020203b3432ull,0x646461090a202f2full,0x662509203233662eull,
0x39316625202c3732ull,0x203b36326625202cull,0x0a202f2f09202020ull,0x3233662e62757309ull,
0x202c383266250920ull,0x6625202c37326625ull,0x09202020203b3931ull,0x627573090a202f2full,
0x662509203233662eull,0x36326625202c3932ull,0x203b38326625202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300939323309ull,0x203233662e766f6dull,0x25202c3033662509ull,
0x202020203b373266ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0930333309353109ull,
0x662e766f6d090a30ull,0x3133662509203233ull,0x203b39326625202cull,0x2020202020202020ull,
0x2e090a202f2f0920ull,0x3309353109636f6cull,0x6f6d090a30093133ull,0x2509203233662e76ull,
0x316625202c323366ull,0x2020202020203b33ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093233330935ull,0x3233662e766f6d09ull,0x202c333366250920ull,0x2020203b35316625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3333330935310963ull,0x2e766f6d090a3009ull,
0x3366250920323366ull,0x3036346630202c34ull,0x20203b3030343030ull,0x3138202f2f092020ull,
0x2e6c756d090a3339ull,0x3366250920323366ull,0x2c37326625202c35ull,0x20203b3433662520ull,
0x090a202f2f092020ull,0x203233662e627573ull,0x25202c3633662509ull,0x326625202c353366ull,
0x2f09202020203b37ull,0x2e627573090a202full,0x3366250920323366ull,0x2c35336625202c37ull,
0x20203b3633662520ull,0x090a202f2f092020ull,0x203233662e627573ull,0x25202c3833662509ull,
0x336625202c373266ull,0x2f09202020203b37ull,0x2e6c756d090a202full,0x3366250920323366ull,
0x2c37326625202c39ull,0x20203b3732662520ull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3034662509ull,0x326625202c373266ull,0x2f09202020203b39ull,0x2e64616d090a202full,
0x3466250920323366ull,0x2c37326625202c31ull,0x25202c3932662520ull,0x202f2f093b303466ull,
0x33662e646461090aull,0x2c32346625092032ull,0x25202c3933662520ull,0x202020203b313466ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x336625202c333466ull,0x3b37336625202c37ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c34346625092032ull,0x25202c3334662520ull,
0x202020203b393366ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x346625202c353466ull,
0x3b39336625202c32ull,0x202f2f0920202020ull,0x33662e64616d090aull,0x2c36346625092032ull,
0x25202c3733662520ull,0x346625202c383366ull,0x090a202f2f093b34ull,0x203233662e627573ull,
0x25202c3734662509ull,0x346625202c323466ull,0x2f09202020203b35ull,0x2e627573090a202full,
0x3466250920323366ull,0x2c31346625202c38ull,0x20203b3534662520ull,0x090a202f2f092020ull,
0x203233662e64616dull,0x25202c3934662509ull,0x336625202c373366ull,0x3b36346625202c38ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x336625202c303566ull,0x3b37346625202c39ull,
0x202f2f0920202020ull,0x33662e64616d090aull,0x2c31356625092032ull,0x25202c3833662520ull,
0x346625202c383366ull,0x090a202f2f093b39ull,0x203233662e646461ull,0x25202c3235662509ull,
0x356625202c383466ull,0x2f09202020203b30ull,0x2e646461090a202full,0x3566250920323366ull,
0x2c31356625202c33ull,0x20203b3235662520ull,0x090a202f2f092020ull,0x203233662e64616dull,
0x25202c3435662509ull,0x326625202c393266ull,0x3b33356625202c39ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x346625202c353566ull,0x3b34356625202c32ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c36356625092032ull,0x20203b3535662520ull,0x2020202020202020ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x356625202c373566ull,0x3b32346625202c35ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c38356625092032ull,0x25202c3435662520ull,
0x202020203b373566ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x356625202c393566ull,
0x2020202020203b38ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093433330935ull,
0x3233662e766f6d09ull,0x202c303666250920ull,0x3430303036346630ull,0x09202020203b3030ull,
0x0a33393138202f2full,0x3233662e6c756d09ull,0x202c313666250920ull,0x6625202c33316625ull,
0x09202020203b3036ull,0x627573090a202f2full,0x662509203233662eull,0x31366625202c3236ull,
0x203b33316625202cull,0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c333666250920ull,
0x6625202c31366625ull,0x09202020203b3236ull,0x627573090a202f2full,0x662509203233662eull,
0x33316625202c3436ull,0x203b33366625202cull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,
0x202c353666250920ull,0x6625202c33316625ull,0x09202020203b3331ull,0x6c756d090a202f2full,
0x662509203233662eull,0x33316625202c3636ull,0x203b35316625202cull,0x0a202f2f09202020ull,
0x3233662e64616d09ull,0x202c373666250920ull,0x6625202c33316625ull,0x36366625202c3531ull,
0x61090a202f2f093bull,0x09203233662e6464ull,0x6625202c38366625ull,0x37366625202c3536ull,
0x2f2f09202020203bull,0x662e6c756d090a20ull,0x3936662509203233ull,0x202c33366625202cull,
0x2020203b33366625ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c30376625ull,
0x35366625202c3936ull,0x2f2f09202020203bull,0x662e627573090a20ull,0x3137662509203233ull,
0x202c38366625202cull,0x2020203b35366625ull,0x6d090a202f2f0920ull,0x09203233662e6461ull,
0x6625202c32376625ull,0x34366625202c3336ull,0x093b30376625202cull,0x627573090a202f2full,
0x662509203233662eull,0x38366625202c3337ull,0x203b31376625202cull,0x0a202f2f09202020ull,
0x3233662e62757309ull,0x202c343766250920ull,0x6625202c37366625ull,0x09202020203b3137ull,
0x64616d090a202f2full,0x662509203233662eull,0x33366625202c3537ull,0x202c34366625202cull,
0x2f2f093b32376625ull,0x662e627573090a20ull,0x3637662509203233ull,0x202c35366625202cull,
0x2020203b33376625ull,0x6d090a202f2f0920ull,0x09203233662e6461ull,0x6625202c37376625ull,
0x34366625202c3436ull,0x093b35376625202cull,0x646461090a202f2full,0x662509203233662eull,
0x34376625202c3837ull,0x203b36376625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c393766250920ull,0x6625202c37376625ull,0x09202020203b3837ull,0x64616d090a202f2full,
0x662509203233662eull,0x35316625202c3038ull,0x202c35316625202cull,0x2f2f093b39376625ull,
0x662e646461090a20ull,0x3138662509203233ull,0x202c38366625202cull,0x2020203b30386625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6625202c32386625ull,0x20202020203b3138ull,
0x2f2f092020202020ull,0x662e627573090a20ull,0x3338662509203233ull,0x202c31386625202cull,
0x2020203b38366625ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c34386625ull,
0x33386625202c3038ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3538662509203233ull,
0x203b34386625202cull,0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,
0x6461090a30093533ull,0x2509203233662e64ull,0x356625202c363866ull,0x3b31386625202c35ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c37386625092032ull,0x25202c3638662520ull,
0x202020203b313866ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x356625202c383866ull,
0x3b37386625202c35ull,0x202f2f0920202020ull,0x33662e627573090aull,0x2c39386625092032ull,
0x25202c3638662520ull,0x202020203b373866ull,0x7573090a202f2f09ull,0x2509203233662e62ull,
0x386625202c303966ull,0x3b39386625202c31ull,0x202f2f0920202020ull,0x33662e646461090aull,
0x2c31396625092032ull,0x25202c3838662520ull,0x202020203b303966ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x386625202c323966ull,0x3b31396625202c34ull,0x202f2f0920202020ull,
0x33662e646461090aull,0x2c33396625092032ull,0x25202c3835662520ull,0x202020203b323966ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x386625202c343966ull,0x3b33396625202c36ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c35396625092032ull,0x25202c3439662520ull,
0x202020203b363866ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x396625202c363966ull,
0x3b35396625202c33ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093633330935ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x5f5f5b202c353172ull,0x6d72617061647563ull,
0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3053ull,0x6934726168637536ull,
0x5366666666666969ull,0x6e7572635f69695full,0x202f2f093b5d6863ull,0x5f203538353a6469ull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,
0x3472616863753650ull,0x6666666666696969ull,0x7572635f69695f53ull,0x0a3078302b68636eull,
0x3233732e62757309ull,0x202c363172250920ull,0x3b31202c35317225ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b31202c3731ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x2c35317225202c32ull,
0x09203b3731722520ull,0x702540090a202f2full,0x2409206172622032ull,0x3836375f305f744cull,
0x2020202020203b32ull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c373966250920ull,
0x6625202c34396625ull,0x09202020203b3639ull,0x766f6d090a202f2full,0x662509203233662eull,
0x30346630202c3839ull,0x203b303030303038ull,0x34202f2f09202020ull,0x6c2e70746573090aull,
0x2509203233662e74ull,0x37396625202c3370ull,0x203b38396625202cull,0x2140090a202f2f09ull,
0x2061726220337025ull,0x375f305f744c2409ull,0x202020203b323836ull,0x202f2f0920202020ull,
0x31355f305f4c240aull,0x3c2f2f200a3a3232ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x37333320656e696cull,0x3109636f6c2e090aull,0x0a30093733330935ull,0x3233662e6c756d09ull,
0x202c393966250920ull,0x6625202c31336625ull,0x09202020203b3233ull,0x6c756d090a202f2full,
0x662509203233662eull,0x336625202c303031ull,0x3b32336625202c30ull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x2c31303166250920ull,0x3030303634663020ull,0x092020203b303034ull,
0x0a33393138202f2full,0x3233662e6c756d09ull,0x2c32303166250920ull,0x25202c3233662520ull,
0x0920203b31303166ull,0x766f6d090a202f2full,0x662509203233662eull,0x346630202c333031ull,
0x3b30303430303036ull,0x38202f2f09202020ull,0x6c756d090a333931ull,0x662509203233662eull,
0x336625202c343031ull,0x3330316625202c30ull,0x0a202f2f0920203bull,0x3233662e64616d09ull,
0x2c35303166250920ull,0x25202c3033662520ull,0x396625202c333366ull,0x090a202f2f093b39ull,
0x203233662e627573ull,0x202c363031662509ull,0x25202c3230316625ull,0x2f0920203b323366ull,
0x2e627573090a202full,0x3166250920323366ull,0x30316625202c3730ull,0x3b30336625202c34ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x202c383031662509ull,0x25202c3030316625ull,
0x2f09203b35303166ull,0x2e627573090a202full,0x3166250920323366ull,0x30316625202c3930ull,
0x3630316625202c32ull,0x090a202f2f09203bull,0x203233662e627573ull,0x202c303131662509ull,
0x25202c3430316625ull,0x2f09203b37303166ull,0x2e627573090a202full,0x3166250920323366ull,
0x30316625202c3131ull,0x3030316625202c38ull,0x090a202f2f09203bull,0x203233662e627573ull,
0x202c323131662509ull,0x6625202c32336625ull,0x2f0920203b393031ull,0x2e6c756d090a202full,
0x3166250920323366ull,0x30316625202c3331ull,0x3031316625202c39ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c343131662509ull,0x25202c3331316625ull,0x2f09203b30303166ull,
0x2e627573090a202full,0x3166250920323366ull,0x30336625202c3531ull,0x3b3031316625202cull,
0x090a202f2f092020ull,0x203233662e627573ull,0x202c363131662509ull,0x25202c3530316625ull,
0x2f09203b31313166ull,0x2e627573090a202full,0x3166250920323366ull,0x30316625202c3731ull,
0x3131316625202c38ull,0x090a202f2f09203bull,0x203233662e64616dull,0x202c383131662509ull,
0x25202c3930316625ull,0x6625202c35313166ull,0x202f2f093b343131ull,0x33662e627573090aull,
0x3931316625092032ull,0x2c3030316625202cull,0x203b373131662520ull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c30323166ull,0x316625202c303131ull,0x31316625202c3231ull,
0x090a202f2f093b38ull,0x203233662e646461ull,0x202c313231662509ull,0x25202c3631316625ull,
0x2f09203b39313166ull,0x2e64616d090a202full,0x3166250920323366ull,0x31316625202c3232ull,
0x3531316625202c32ull,0x3b3032316625202cull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x6625202c33323166ull,0x316625202c313231ull,0x202f2f09203b3232ull,0x33662e64616d090aull,
0x3432316625092032ull,0x202c31336625202cull,0x6625202c33336625ull,0x202f2f093b333231ull,
0x33662e646461090aull,0x3532316625092032ull,0x2c3830316625202cull,0x203b343231662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c36323166ull,0x316625202c353231ull,
0x202f2f09203b3830ull,0x33662e627573090aull,0x2c31336625092032ull,0x202c343231662520ull,
0x20203b3632316625ull,0x6c2e090a202f2f09ull,0x333309353109636full,0x646461090a300938ull,
0x662509203233662eull,0x316625202c373231ull,0x32316625202c3532ull,0x0a202f2f09203b35ull,
0x3233662e62757309ull,0x2c38323166250920ull,0x202c373231662520ull,0x09203b3532316625ull,
0x627573090a202f2full,0x662509203233662eull,0x316625202c393231ull,0x32316625202c3532ull,
0x0a202f2f09203b38ull,0x3233662e62757309ull,0x2c30333166250920ull,0x202c373231662520ull,
0x09203b3832316625ull,0x627573090a202f2full,0x662509203233662eull,0x316625202c313331ull,
0x33316625202c3532ull,0x0a202f2f09203b30ull,0x3233662e64646109ull,0x2c32333166250920ull,
0x202c393231662520ull,0x09203b3133316625ull,0x646461090a202f2full,0x662509203233662eull,
0x316625202c333331ull,0x31336625202c3233ull,0x0a202f2f0920203bull,0x3233662e64646109ull,
0x2c34333166250920ull,0x202c333331662520ull,0x0920203b31336625ull,0x646461090a202f2full,
0x662509203233662eull,0x316625202c353331ull,0x33316625202c3732ull,0x0a202f2f09203b34ull,
0x3233662e62757309ull,0x2c36333166250920ull,0x202c353331662520ull,0x09203b3732316625ull,
0x627573090a202f2full,0x662509203233662eull,0x33316625202c3133ull,0x3633316625202c34ull,
0x0a202f2f0920203bull,0x353109636f6c2e09ull,0x090a300939333309ull,0x203233662e646461ull,
0x202c373331662509ull,0x6625202c37326625ull,0x2f0920203b353331ull,0x2e627573090a202full,
0x3166250920323366ull,0x33316625202c3833ull,0x3533316625202c37ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c393331662509ull,0x6625202c37326625ull,0x2f0920203b383331ull,
0x2e627573090a202full,0x3166250920323366ull,0x33316625202c3034ull,0x3833316625202c37ull,
0x090a202f2f09203bull,0x203233662e627573ull,0x202c313431662509ull,0x25202c3533316625ull,
0x2f09203b30343166ull,0x2e646461090a202full,0x3166250920323366ull,0x33316625202c3234ull,
0x3134316625202c39ull,0x090a202f2f09203bull,0x203233662e646461ull,0x202c333431662509ull,
0x6625202c31336625ull,0x2f0920203b323431ull,0x2e646461090a202full,0x3166250920323366ull,
0x39326625202c3434ull,0x3b3334316625202cull,0x090a202f2f092020ull,0x203233662e646461ull,
0x202c353431662509ull,0x25202c3733316625ull,0x2f09203b34343166ull,0x2e766f6d090a202full,
0x3366250920323366ull,0x3534316625202c30ull,0x202020202020203bull,0x090a202f2f092020ull,
0x203233662e627573ull,0x202c363431662509ull,0x25202c3534316625ull,0x2f09203b37333166ull,
0x2e627573090a202full,0x3166250920323366ull,0x34316625202c3734ull,0x3634316625202c34ull,
0x090a202f2f09203bull,0x203233662e766f6dull,0x25202c3133662509ull,0x2020203b37343166ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0932343309353109ull,0x662e627573090a30ull,
0x3431662509203233ull,0x2c32386625202c38ull,0x20203b3635662520ull,0x73090a202f2f0920ull,
0x09203233662e6275ull,0x25202c3934316625ull,0x6625202c38343166ull,0x2f2f0920203b3238ull,
0x662e627573090a20ull,0x3531662509203233ull,0x3834316625202c30ull,0x3b3934316625202cull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3135316625ull,0x6625202c39343166ull,
0x2f2f0920203b3635ull,0x662e627573090a20ull,0x3531662509203233ull,0x2c32386625202c32ull,
0x203b303531662520ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3335316625ull,
0x6625202c32353166ull,0x2f2f09203b313531ull,0x662e646461090a20ull,0x3531662509203233ull,
0x3335316625202c34ull,0x203b35386625202cull,0x73090a202f2f0920ull,0x09203233662e6275ull,
0x25202c3535316625ull,0x6625202c34353166ull,0x2f2f0920203b3935ull,0x662e646461090a20ull,
0x3531662509203233ull,0x3834316625202c36ull,0x3b3535316625202cull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x25202c3735316625ull,0x6625202c36353166ull,0x2f2f0920203b3331ull,
0x662e627573090a20ull,0x3531662509203233ull,0x3735316625202c38ull,0x3b3635316625202cull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3935316625ull,0x6625202c37353166ull,
0x2f2f09203b383531ull,0x662e627573090a20ull,0x3631662509203233ull,0x3635316625202c30ull,
0x3b3935316625202cull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3136316625ull,
0x316625202c333166ull,0x2f2f0920203b3835ull,0x662e646461090a20ull,0x3631662509203233ull,
0x3036316625202c32ull,0x3b3136316625202cull,0x73090a202f2f0920ull,0x09203233662e6275ull,
0x25202c3336316625ull,0x6625202c36353166ull,0x2f2f09203b383431ull,0x662e627573090a20ull,
0x3631662509203233ull,0x3535316625202c34ull,0x3b3336316625202cull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x25202c3536316625ull,0x6625202c32363166ull,0x2f2f09203b343631ull,
0x662e646461090a20ull,0x3631662509203233ull,0x2c35316625202c36ull,0x203b353631662520ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3736316625ull,0x6625202c37353166ull,
0x2f2f09203b363631ull,0x662e766f6d090a20ull,0x3233662509203233ull,0x3b3736316625202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3836316625ull,
0x6625202c37363166ull,0x2f2f09203b373531ull,0x662e627573090a20ull,0x3631662509203233ull,
0x3636316625202c39ull,0x3b3836316625202cull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6625202c33336625ull,0x202020203b393631ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009343433093531ull,0x33662e6c756d090aull,0x3037316625092032ull,0x2c3534316625202cull,
0x203b353431662520ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x6630202c31373166ull,
0x3030343030303634ull,0x202f2f092020203bull,0x756d090a33393138ull,0x2509203233662e6cull,
0x6625202c32373166ull,0x316625202c353431ull,0x202f2f09203b3137ull,0x33662e627573090aull,
0x3337316625092032ull,0x2c3237316625202cull,0x203b353431662520ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c34373166ull,0x316625202c353431ull,0x202f2f09203b3734ull,
0x33662e627573090aull,0x3537316625092032ull,0x2c3237316625202cull,0x203b333731662520ull,
0x616d090a202f2f09ull,0x2509203233662e64ull,0x6625202c36373166ull,0x316625202c353431ull,
0x37316625202c3734ull,0x090a202f2f093b34ull,0x203233662e627573ull,0x202c373731662509ull,
0x25202c3534316625ull,0x2f09203b35373166ull,0x2e646461090a202full,0x3166250920323366ull,
0x37316625202c3837ull,0x3637316625202c30ull,0x090a202f2f09203bull,0x203233662e627573ull,
0x202c393731662509ull,0x25202c3837316625ull,0x2f09203b30373166ull,0x2e627573090a202full,
0x3166250920323366ull,0x37316625202c3038ull,0x3937316625202c38ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c313831662509ull,0x25202c3037316625ull,0x2f09203b30383166ull,
0x2e627573090a202full,0x3166250920323366ull,0x37316625202c3238ull,0x3937316625202c36ull,
0x090a202f2f09203bull,0x203233662e646461ull,0x202c333831662509ull,0x25202c3138316625ull,
0x2f09203b32383166ull,0x2e6c756d090a202full,0x3166250920323366ull,0x37316625202c3438ull,
0x3537316625202c35ull,0x090a202f2f09203bull,0x203233662e627573ull,0x202c353831662509ull,
0x25202c3438316625ull,0x2f09203b30373166ull,0x2e64616d090a202full,0x3166250920323366ull,
0x37316625202c3638ull,0x3737316625202c35ull,0x3b3538316625202cull,0x616d090a202f2f09ull,
0x2509203233662e64ull,0x6625202c37383166ull,0x316625202c353731ull,0x38316625202c3737ull,
0x090a202f2f093b36ull,0x203233662e64616dull,0x202c383831662509ull,0x25202c3737316625ull,
0x6625202c37373166ull,0x202f2f093b373831ull,0x33662e646461090aull,0x3938316625092032ull,
0x2c3338316625202cull,0x203b383831662520ull,0x616d090a202f2f09ull,0x2509203233662e64ull,
0x6625202c30393166ull,0x316625202c373431ull,0x38316625202c3734ull,0x090a202f2f093b39ull,
0x203233662e646461ull,0x202c313931662509ull,0x25202c3837316625ull,0x2f09203b30393166ull,
0x2e766f6d090a202full,0x3566250920323366ull,0x3139316625202c36ull,0x202020202020203bull,
0x090a202f2f092020ull,0x203233662e627573ull,0x202c323931662509ull,0x25202c3139316625ull,
0x2f09203b38373166ull,0x2e627573090a202full,0x3166250920323366ull,0x39316625202c3339ull,
0x3239316625202c30ull,0x090a202f2f09203bull,0x203233662e766f6dull,0x25202c3935662509ull,
0x2020203b33393166ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0935343309353109ull,
0x662e6c756d090a30ull,0x3931662509203233ull,0x3736316625202c34ull,0x3b3736316625202cull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x30202c3539316625ull,0x3034303030363466ull,
0x2f2f092020203b30ull,0x6d090a3339313820ull,0x09203233662e6c75ull,0x25202c3639316625ull,
0x6625202c37363166ull,0x2f2f09203b353931ull,0x662e627573090a20ull,0x3931662509203233ull,
0x3639316625202c37ull,0x3b3736316625202cull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x25202c3839316625ull,0x6625202c37363166ull,0x2f2f09203b393631ull,0x662e627573090a20ull,
0x3931662509203233ull,0x3639316625202c39ull,0x3b3739316625202cull,0x6d090a202f2f0920ull,
0x09203233662e6461ull,0x25202c3030326625ull,0x6625202c37363166ull,0x316625202c393631ull,
0x0a202f2f093b3839ull,0x3233662e62757309ull,0x2c31303266250920ull,0x202c373631662520ull,
0x09203b3939316625ull,0x646461090a202f2full,0x662509203233662eull,0x316625202c323032ull,
0x30326625202c3439ull,0x0a202f2f09203b30ull,0x3233662e62757309ull,0x2c33303266250920ull,
0x202c323032662520ull,0x09203b3439316625ull,0x627573090a202f2full,0x662509203233662eull,
0x326625202c343032ull,0x30326625202c3230ull,0x0a202f2f09203b33ull,0x3233662e62757309ull,
0x2c35303266250920ull,0x202c343931662520ull,0x09203b3430326625ull,0x627573090a202f2full,
0x662509203233662eull,0x326625202c363032ull,0x30326625202c3030ull,0x0a202f2f09203b33ull,
0x3233662e64646109ull,0x2c37303266250920ull,0x202c353032662520ull,0x09203b3630326625ull,
0x6c756d090a202f2full,0x662509203233662eull,0x316625202c383032ull,0x39316625202c3939ull,
0x0a202f2f09203b39ull,0x3233662e62757309ull,0x2c39303266250920ull,0x202c383032662520ull,
0x09203b3439316625ull,0x64616d090a202f2full,0x662509203233662eull,0x316625202c303132ull,
0x30326625202c3939ull,0x3930326625202c31ull,0x6d090a202f2f093bull,0x09203233662e6461ull,
0x25202c3131326625ull,0x6625202c39393166ull,0x326625202c313032ull,0x0a202f2f093b3031ull,
0x3233662e64616d09ull,0x2c32313266250920ull,0x202c313032662520ull,0x25202c3130326625ull,
0x2f2f093b31313266ull,0x662e646461090a20ull,0x3132662509203233ull,0x3730326625202c33ull,
0x3b3231326625202cull,0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3431326625ull,
0x6625202c39363166ull,0x326625202c393631ull,0x0a202f2f093b3331ull,0x3233662e64646109ull,
0x2c35313266250920ull,0x202c323032662520ull,0x09203b3431326625ull,0x766f6d090a202f2full,
0x662509203233662eull,0x31326625202c3238ull,0x2020202020203b35ull,0x0a202f2f09202020ull,
0x3233662e62757309ull,0x2c36313266250920ull,0x202c353132662520ull,0x09203b3230326625ull,
0x627573090a202f2full,0x662509203233662eull,0x326625202c373132ull,0x31326625202c3431ull,
0x0a202f2f09203b36ull,0x3233662e766f6d09ull,0x202c353866250920ull,0x20203b3731326625ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3634330935310963ull,0x2e646461090a3009ull,
0x3266250920323366ull,0x39316625202c3831ull,0x3531326625202c31ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c393132662509ull,0x25202c3831326625ull,0x2f09203b35313266ull,
0x2e627573090a202full,0x3266250920323366ull,0x39316625202c3032ull,0x3931326625202c31ull,
0x090a202f2f09203bull,0x203233662e627573ull,0x202c313232662509ull,0x25202c3831326625ull,
0x2f09203b39313266ull,0x2e627573090a202full,0x3266250920323366ull,0x31326625202c3232ull,
0x3132326625202c35ull,0x090a202f2f09203bull,0x203233662e646461ull,0x202c333232662509ull,
0x25202c3032326625ull,0x2f09203b32323266ull,0x2e646461090a202full,0x3266250920323366ull,
0x31326625202c3432ull,0x3332326625202c37ull,0x090a202f2f09203bull,0x203233662e646461ull,
0x202c353232662509ull,0x25202c3339316625ull,0x2f09203b34323266ull,0x636f6c2e090a202full,
0x0936333309353109ull,0x732e627573090a30ull,0x3631722509203233ull,0x202c36317225202cull,
0x2020202020203b31ull,0x6d090a202f2f0920ull,0x09203233752e766full,0x3b30202c38317225ull,
0x2020202020202020ull,0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e7165ull,
0x317225202c347025ull,0x3b38317225202c36ull,0x40090a202f2f0920ull,0x2061726220347025ull,
0x375f305f744c2409ull,0x202020203b323836ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c37333320656eull,
0x62616c2064616568ull,0x5f4c242064656c65ull,0x090a323231355f30ull,0x203233662e646461ull,
0x202c363232662509ull,0x25202c3831326625ull,0x2f09203b35323266ull,0x2e627573090a202full,
0x3266250920323366ull,0x32326625202c3732ull,0x3831326625202c36ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c383232662509ull,0x25202c3532326625ull,0x2f09203b37323266ull,
0x2e646461090a202full,0x3266250920323366ull,0x32326625202c3932ull,0x3832326625202c36ull,
0x090a202f2f09203bull,0x203233662e766f6dull,0x202c303332662509ull,0x3030303830346630ull,
0x2f092020203b3030ull,0x746573090a34202full,0x3233662e746c2e70ull,0x25202c3570250920ull,
0x6625202c39323266ull,0x202f2f093b303332ull,0x622035702540090aull,0x305f4c2409206172ull,
0x20203b323231355full,0x2020202020202020ull,0x744c240a202f2f09ull,0x3a323836375f305full,
0x33355f305f4c240aull,0x6f6c2e090a3a3837ull,0x0936360936310963ull,0x732e766f6d090a30ull,
0x3931722509203233ull,0x202020203b30202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x732e74672e707465ull,0x2c36702509203233ull,0x25202c3631722520ull,0x2f2f09203b393172ull,
0x732e627573090a20ull,0x3032722509203233ull,0x202c35317225202cull,0x2020203b36317225ull,
0x6d090a202f2f0920ull,0x09203233732e766full,0x3b30202c31327225ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x2e706c6573090a20ull,0x3272250920323373ull,0x2c30327225202c32ull,
0x25202c3132722520ull,0x0a202f2f093b3670ull,0x3233752e766f6d09ull,0x202c333272250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x746573090a202f2full,0x3233732e71652e70ull,
0x25202c3770250920ull,0x327225202c323272ull,0x0a202f2f09203b33ull,0x7262203770254009ull,
0x305f744c24092061ull,0x20203b343139365full,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x0933370936310963ull,0x61702e646c090a30ull,0x203233732e6d6172ull,0x5b202c3432722509ull,
0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,
0x7261686375365030ull,0x6666666669696934ull,0x6e615f69695f5366ull,0x466e6f6974616d69ull,
0x2f093b5d656d6172ull,0x3939353a6469202full,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,
0x615f69695f536666ull,0x6e6f6974616d696eull,0x78302b656d617246ull,0x732e646461090a30ull,
0x3532722509203233ull,0x202c34327225202cull,0x2020203b32327225ull,0x6c090a202f2f0920ull,
0x2e6d617261702e64ull,0x3632722509203875ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x69695f5366666666ull,0x2b73726f6c6f635full,0x69202f2f093b5d30ull,0x5f5f203030363a64ull,
0x6d72617061647563ull,0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3053ull,
0x6934726168637536ull,0x5366666666666969ull,0x6f6c6f635f69695full,0x090a3078302b7372ull,
0x732e6f6c2e6c756dull,0x3732722509203233ull,0x202c35327225202cull,0x2f09203b36327225ull,
0x2e747663090a202full,0x09203233752e3875ull,0x7225202c38327225ull,0x20202020203b3732ull,
0x090a202f2f092020ull,0x09363109636f6c2eull,0x646c090a30093437ull,0x752e6d617261702eull,
0x2c39327225092038ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d38ull,
0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,0x5f69695f53666666ull,
0x312b73726f6c6f63ull,0x6469202f2f093b5dull,0x635f5f203130363aull,0x5f6d726170616475ull,
0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f30ull,0x6969347261686375ull,
0x5f53666666666669ull,0x726f6c6f635f6969ull,0x6d090a3178302b73ull,0x33732e6f6c2e6c75ull,
0x2c30337225092032ull,0x25202c3532722520ull,0x2f2f09203b393272ull,0x752e747663090a20ull,
0x2509203233752e38ull,0x337225202c313372ull,0x2020202020203b30ull,0x2e090a202f2f0920ull,
0x3709363109636f6cull,0x2e646c090a300935ull,0x38752e6d61726170ull,0x202c323372250920ull,
0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f305344746full,
0x6168637536503031ull,0x6666666969693472ull,0x635f69695f536666ull,0x5d322b73726f6c6full,
0x3a6469202f2f093bull,0x75635f5f20323036ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x305344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,
0x73726f6c6f635f69ull,0x756d090a3278302bull,0x3233732e6f6c2e6cull,0x202c333372250920ull,
0x7225202c35327225ull,0x202f2f09203b3233ull,0x38752e747663090aull,0x722509203233752eull,
0x33337225202c3433ull,0x202020202020203bull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3536365f305f744cull,0x2020202020203b38ull,0x202f2f0920202020ull,0x365f305f744c240aull,
0x6c2e090a3a343139ull,0x393709363109636full,0x2e766f6d090a3009ull,0x3372250920323375ull,
0x2020203b30202c34ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233752e766f6dull,
0x30202c3133722509ull,0x202020202020203bull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3272250920323375ull,0x2020203b30202c38ull,0x2020202020202020ull,0x240a202f2f092020ull,
0x3536365f305f744cull,0x702e646c090a3a38ull,0x3436752e6d617261ull,0x202c316472250920ull,
0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f305344746full,
0x6168637536503031ull,0x6666666969693472ull,0x645f69695f536666ull,0x202f2f093b5d7473ull,
0x5f203330363a6469ull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f305344ull,0x3472616863753650ull,0x6666666666696969ull,0x7473645f69695f53ull,
0x756d090a3078302bull,0x3233732e6f6c2e6cull,0x202c353372250920ull,0x367225202c377225ull,
0x202f2f092020203bull,0x33732e646461090aull,0x2c36337225092032ull,0x7225202c34722520ull,
0x20202020203b3533ull,0x7663090a202f2f09ull,0x33732e3436752e74ull,0x2c32647225092032ull,
0x20203b3633722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x32647225202c3364ull,0x202020203b34202cull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x647225202c346472ull,0x3b33647225202c31ull,0x202f2f0920202020ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5b202c37337225ull,0x726170616475635full,0x614d38315a5f5f6dull,
0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,0x6666666666696969ull,
0x6172665f69695f53ull,0x202f2f093b5d656dull,0x5f203138353a6469ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x6172665f69695f53ull,0x090a3078302b656dull,0x203233752e766f6dull,
0x30202c3833722509ull,0x202020202020203bull,0x2f09202020202020ull,0x70746573090a202full,
0x203233732e656e2eull,0x7225202c38702509ull,0x38337225202c3733ull,0x090a202f2f09203bull,
0x6172622038702540ull,0x5f305f744c240920ull,0x2020203b36323437ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x3009363809363109ull,0x33752e766f6d090aull,0x2c39337225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,
0x5b092038752e3476ull,0x2c5d302b34647225ull,0x252c383272257b20ull,0x343372252c313372ull,
0x093b7d393372252cull,0x617262090a202f2full,0x4c240920696e752eull,0x303731375f305f74ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x34375f305f744c24ull,0x6f6c2e090a3a3632ull,
0x0930390936310963ull,0x732e646461090a30ull,0x3034722509203233ull,0x202c37337225202cull,
0x2020202020203b31ull,0x73090a202f2f0920ull,0x09203233732e7268ull,0x7225202c31347225ull,
0x203b3133202c3034ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3234722509203233ull,
0x202020203b31202cull,0x2020202020202020ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x7225202c33347225ull,0x32347225202c3134ull,0x2f2f09202020203bull,0x732e646461090a20ull,
0x3434722509203233ull,0x202c33347225202cull,0x2020203b30347225ull,0x73090a202f2f0920ull,
0x09203233732e7268ull,0x7225202c35347225ull,0x20203b31202c3434ull,0x2f2f092020202020ull,
0x6c672e646c090a20ull,0x2e34762e6c61626full,0x3472257b09203875ull,0x252c373472252c36ull,
0x202c7d5f2c383472ull,0x5d302b346472255bull,0x6d090a202f2f093bull,0x33732e6f6c2e6c75ull,
0x2c39347225092032ull,0x25202c3733722520ull,0x2f2f09203b363472ull,0x732e646461090a20ull,
0x3035722509203233ull,0x202c38327225202cull,0x2020203b39347225ull,0x61090a202f2f0920ull,
0x09203233732e6464ull,0x7225202c31357225ull,0x30357225202c3534ull,0x2f2f09202020203bull,
0x732e766964090a20ull,0x3235722509203233ull,0x202c31357225202cull,0x2020203b30347225ull,
0x2e090a202f2f0920ull,0x3909363109636f6cull,0x6c756d090a300931ull,0x203233732e6f6c2eull,
0x25202c3335722509ull,0x347225202c373372ull,0x0a202f2f09203b37ull,0x3233732e64646109ull,
0x202c343572250920ull,0x7225202c31337225ull,0x09202020203b3335ull,0x646461090a202f2full,
0x722509203233732eull,0x35347225202c3535ull,0x203b34357225202cull,0x0a202f2f09202020ull,
0x3233732e76696409ull,0x202c363572250920ull,0x7225202c35357225ull,0x09202020203b3034ull,
0x2e7473090a202f2full,0x762e6c61626f6c67ull,0x255b092038752e32ull,0x202c5d302b346472ull,
0x72252c323572257bull,0x202f2f093b7d3635ull,0x3109636f6c2e090aull,0x090a300932390936ull,
0x732e6f6c2e6c756dull,0x3735722509203233ull,0x202c37337225202cull,0x2f09203b38347225ull,
0x2e646461090a202full,0x3572250920323373ull,0x2c34337225202c38ull,0x20203b3735722520ull,
0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3935722509ull,0x357225202c353472ull,
0x2f09202020203b38ull,0x2e766964090a202full,0x3672250920323373ull,0x2c39357225202c30ull,
0x20203b3034722520ull,0x090a202f2f092020ull,0x61626f6c672e7473ull,0x255b092038752e6cull,
0x202c5d322b346472ull,0x2f09203b30367225ull,0x3331363a6469202full,0x375f305f744c240aull,
0x744c240a3a303731ull,0x3a363431365f305full,0x3109636f6c2e090aull,0x090a300935390936ull,
0x2020203b74697865ull,0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,
0x6557444c240a202full,0x4d38315a5f5f646eull,0x6f72626c65646e61ull,0x316d735f30534474ull,
0x7261686375365030ull,0x6666666669696934ull,0x090a3a69695f5366ull,0x315a5f202f2f207dull,
0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x0a69695f53666666ull,0x7972746e652e090aull,0x6e614d38315a5f20ull,0x44746f72626c6564ull,
0x5030316d735f3153ull,0x6934726168637536ull,0x5366666666666969ull,0x09090a282069695full,
0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,
0x090a2c7473645f69ull,0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,
0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f31ull,0x6969347261686375ull,
0x5f53666666666669ull,0x6567616d695f6969ull,0x61702e09090a2c57ull,0x3233732e206d6172ull,
0x70616475635f5f20ull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,
0x6168637536503031ull,0x6666666969693472ull,0x695f69695f536666ull,0x090a2c486567616dull,
0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,0x646e614d38315a5full,
0x5344746f72626c65ull,0x365030316d735f31ull,0x6969347261686375ull,0x5f53666666666669ull,
0x636e7572635f6969ull,0x61702e09090a2c68ull,0x3233662e206d6172ull,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x785f69695f536666ull,0x09090a2c3066664full,0x2e206d617261702eull,
0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,0x315344746f72626cull,
0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,0x2c3166664f785f69ull,
0x617261702e09090aull,0x5f203233662e206dull,0x726170616475635full,0x614d38315a5f5f6dull,
0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,
0x664f795f69695f53ull,0x702e09090a2c3066ull,0x33662e206d617261ull,0x616475635f5f2032ull,
0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f315344746f72ull,0x686375365030316dull,
0x6666696969347261ull,0x5f69695f53666666ull,0x090a2c3166664f79ull,0x206d617261702e09ull,
0x635f5f203233662eull,0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f31ull,0x6969347261686375ull,0x5f53666666666669ull,0x656c6163735f6969ull,
0x7261702e09090a2cull,0x67696c612e206d61ull,0x2038622e2034206eull,0x6170616475635f5full,
0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f31534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x6f635f69695f5366ull,0x2c5d345b73726f6cull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,0x6172665f69695f53ull,
0x702e09090a2c656dull,0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f315344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x5f69695f53666666ull,0x6f6974616d696e61ull,0x0a29656d6172466eull,0x6765722e090a7b09ull,
0x7225203631752e20ull,0x2e090a3b3e363c68ull,0x3233752e20676572ull,0x3e3734313c722520ull,
0x206765722e090a3bull,0x647225203436752eull,0x2e090a3b3e32313cull,0x3233662e20676572ull,
0x3e3233323c662520ull,0x206765722e090a3bull,0x702520646572702eull,0x2e090a3b3e34313cull,
0x3109363109636f6cull,0x424c240a30093235ull,0x4d38315a5f5f3142ull,0x6f72626c65646e61ull,
0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,0x090a3a69695f5366ull,
0x203631752e766f6dull,0x25202c3168722509ull,0x3b782e6469617463ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x6872250920363175ull,0x6469746e25202c32ull,0x20202020203b782eull,
0x090a202f2f092020ull,0x656469772e6c756dull,0x722509203631752eull,0x2c31687225202c31ull,
0x2f093b3268722520ull,0x2e766f6d090a202full,0x6872250920363175ull,0x6961746325202c33ull,
0x202020203b792e64ull,0x090a202f2f092020ull,0x203631752e766f6dull,0x25202c3468722509ull,
0x203b792e6469746eull,0x2f09202020202020ull,0x2e6c756d090a202full,0x3631752e65646977ull,
0x25202c3272250920ull,0x687225202c336872ull,0x090a202f2f093b34ull,0x2e3233752e747663ull,
0x3372250920363175ull,0x782e64697425202cull,0x2f0920202020203bull,0x2e646461090a202full,
0x3472250920323375ull,0x25202c337225202cull,0x20202020203b3172ull,0x090a202f2f092020ull,
0x2e3233752e747663ull,0x3572250920363175ull,0x792e64697425202cull,0x2f0920202020203bull,
0x2e646461090a202full,0x3672250920323375ull,0x25202c357225202cull,0x20202020203b3272ull,
0x090a202f2f092020ull,0x6d617261702e646cull,0x722509203233732eull,0x75635f5f5b202c37ull,
0x5f5f6d7261706164ull,0x65646e614d38315aull,0x315344746f72626cull,0x75365030316d735full,
0x6969693472616863ull,0x695f536666666666ull,0x486567616d695f69ull,0x6469202f2f093b5dull,
0x635f5f203037363aull,0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f31ull,0x6969347261686375ull,0x5f53666666666669ull,0x6567616d695f6969ull,
0x6c090a3078302b48ull,0x2e6d617261702e64ull,0x3872250920323373ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,0x5f315344746f7262ull,0x6375365030316d73ull,
0x6669696934726168ull,0x69695f5366666666ull,0x5d576567616d695full,0x3a6469202f2f093bull,
0x75635f5f20313736ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,0x315344746f72626cull,
0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,0x576567616d695f69ull,
0x6573090a3078302bull,0x3233752e74672e74ull,0x722509203233732eull,0x202c377225202c39ull,
0x202f2f093b367225ull,0x33732e67656e090aull,0x2c30317225092032ull,0x2020203b39722520ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x3233752e74672e74ull,0x722509203233732eull,
0x2c387225202c3131ull,0x2f2f093b34722520ull,0x732e67656e090a20ull,0x3231722509203233ull,
0x203b31317225202cull,0x2020202020202020ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x7225202c33317225ull,0x32317225202c3031ull,0x2f2f09202020203bull,0x752e766f6d090a20ull,
0x3431722509203233ull,0x202020203b30202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x732e71652e707465ull,0x2c31702509203233ull,0x25202c3331722520ull,0x2f2f09203b343172ull,
0x2031702540090a20ull,0x744c240920617262ull,0x34373835315f315full,0x202020202020203bull,
0x2e090a202f2f0920ull,0x3109363109636f6cull,0x756d090a30093036ull,0x3233732e6f6c2e6cull,
0x202c353172250920ull,0x367225202c387225ull,0x202f2f092020203bull,0x33732e646461090aull,
0x2c36317225092032ull,0x7225202c34722520ull,0x20202020203b3531ull,0x646c090a202f2f09ull,
0x752e6d617261702eull,0x3164722509203436ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3831ull,0x5f315344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x69695f5366666666ull,0x2f093b5d7473645full,0x3936363a6469202full,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x645f69695f536666ull,0x090a3078302b7473ull,0x2e3436752e747663ull,
0x6472250920323373ull,0x3b36317225202c32ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c33647225ull,0x20203b34202c3264ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3464722509ull,0x647225202c316472ull,0x2f09202020203b33ull,
0x672e646c090a202full,0x34762e6c61626f6cull,0x72257b092038752eull,0x2c383172252c3731ull,
0x2c7d5f2c39317225ull,0x302b346472255b20ull,0x090a202f2f093b5dull,0x203233752e766f6dull,
0x30202c3032722509ull,0x202020202020203bull,0x2f09202020202020ull,0x70746573090a202full,
0x203233732e656c2eull,0x7225202c32702509ull,0x3b30327225202c34ull,0x090a202f2f092020ull,
0x6172622032702540ull,0x5f315f744c240920ull,0x20203b3238303431ull,0x2f09202020202020ull,
0x672e646c090a202full,0x34762e6c61626f6cull,0x72257b092038752eull,0x2c323272252c3132ull,
0x2c7d5f2c33327225ull,0x2d2b346472255b20ull,0x0a202f2f093b5d34ull,0x363109636f6c2e09ull,
0x090a300935363109ull,0x203233732e627573ull,0x25202c3432722509ull,0x317225202c333272ull,
0x2f09202020203b39ull,0x2e736261090a202full,0x3272250920323373ull,0x3b34327225202c35ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e766f6dull,0x31202c3632722509ull,
0x2020202020203b30ull,0x2f09202020202020ull,0x2e746573090a202full,0x732e3233752e7467ull,
0x3732722509203233ull,0x202c35327225202cull,0x2f2f093b36327225ull,0x732e67656e090a20ull,
0x3832722509203233ull,0x203b37327225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x09203233732e6275ull,0x7225202c39327225ull,0x37317225202c3132ull,0x2f2f09202020203bull,
0x732e736261090a20ull,0x3033722509203233ull,0x203b39327225202cull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233732e766full,0x3031202c31337225ull,0x202020202020203bull,
0x2f2f092020202020ull,0x672e746573090a20ull,0x33732e3233752e74ull,0x2c32337225092032ull,
0x25202c3033722520ull,0x202f2f093b313372ull,0x33732e67656e090aull,0x2c33337225092032ull,
0x20203b3233722520ull,0x2020202020202020ull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x327225202c343372ull,0x3b38317225202c32ull,0x202f2f0920202020ull,0x33732e736261090aull,
0x2c35337225092032ull,0x20203b3433722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x3b3031202c363372ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x74672e746573090aull,0x3233732e3233752eull,0x202c373372250920ull,0x7225202c35337225ull,
0x0a202f2f093b3633ull,0x3233732e67656e09ull,0x202c383372250920ull,0x2020203b37337225ull,
0x0920202020202020ull,0x2e726f090a202f2full,0x3372250920323362ull,0x2c33337225202c39ull,
0x20203b3833722520ull,0x0a202f2f09202020ull,0x203233622e726f09ull,0x25202c3034722509ull,
0x337225202c383272ull,0x0920202020203b39ull,0x617262090a202f2full,0x4c240920696e752eull,
0x323833315f315f74ull,0x2020202020203b36ull,0x0a202f2f09202020ull,0x34315f315f744c24ull,
0x6f6d090a3a323830ull,0x2509203233732e76ull,0x203b30202c303472ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x315f315f744c240aull,0x61090a3a36323833ull,0x09203233732e6464ull,
0x7225202c31347225ull,0x2020203b31202c34ull,0x2f2f092020202020ull,0x2e70746573090a20ull,
0x09203233732e656cull,0x387225202c337025ull,0x203b31347225202cull,0x40090a202f2f0920ull,
0x2061726220337025ull,0x315f315f744c2409ull,0x2020203b38333334ull,0x2f2f092020202020ull,
0x6c672e646c090a20ull,0x2e34762e6c61626full,0x3472257b09203875ull,0x252c333472252c32ull,
0x202c7d5f2c343472ull,0x5d342b346472255bull,0x2e090a202f2f093bull,0x3109363109636f6cull,
0x7573090a30093736ull,0x2509203233732e62ull,0x347225202c353472ull,0x3b39317225202c34ull,
0x202f2f0920202020ull,0x33732e736261090aull,0x2c36347225092032ull,0x20203b3534722520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x3b3031202c373472ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x74672e746573090aull,0x3233732e3233752eull,
0x202c383472250920ull,0x7225202c36347225ull,0x0a202f2f093b3734ull,0x3233732e67656e09ull,
0x202c393472250920ull,0x2020203b38347225ull,0x0920202020202020ull,0x627573090a202f2full,
0x722509203233732eull,0x32347225202c3035ull,0x203b37317225202cull,0x0a202f2f09202020ull,
0x3233732e73626109ull,0x202c313572250920ull,0x2020203b30357225ull,0x0920202020202020ull,
0x766f6d090a202f2full,0x722509203233732eull,0x203b3031202c3235ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x2e74672e74657309ull,0x203233732e323375ull,0x25202c3335722509ull,
0x357225202c313572ull,0x090a202f2f093b32ull,0x203233732e67656eull,0x25202c3435722509ull,
0x202020203b333572ull,0x2f09202020202020ull,0x2e627573090a202full,0x3572250920323373ull,
0x2c33347225202c35ull,0x20203b3831722520ull,0x090a202f2f092020ull,0x203233732e736261ull,
0x25202c3635722509ull,0x202020203b353572ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3572250920323373ull,0x20203b3031202c37ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x752e74672e746573ull,0x09203233732e3233ull,0x7225202c38357225ull,0x37357225202c3635ull,
0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c39357225ull,0x20202020203b3835ull,
0x2f2f092020202020ull,0x33622e726f090a20ull,0x2c30367225092032ull,0x25202c3435722520ull,
0x202020203b393572ull,0x6f090a202f2f0920ull,0x2509203233622e72ull,0x347225202c313672ull,
0x3b30367225202c39ull,0x2f2f092020202020ull,0x732e646461090a20ull,0x3034722509203233ull,
0x202c30347225202cull,0x2020203b31367225ull,0x4c240a202f2f0920ull,0x333334315f315f74ull,
0x2e766f6d090a3a38ull,0x3672250920323375ull,0x2020203b30202c32ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e656c2e70746573ull,0x3470250920323373ull,0x25202c367225202cull,
0x2f0920203b323672ull,0x34702540090a202full,0x4c24092061726220ull,0x353834315f315f74ull,
0x2020202020203b30ull,0x090a202f2f092020ull,0x09363109636f6c2eull,0x73090a3009393631ull,
0x09203233732e6275ull,0x7225202c33367225ull,0x3b387225202c3631ull,0x2f2f092020202020ull,
0x732e747663090a20ull,0x09203233732e3436ull,0x7225202c35647225ull,0x20202020203b3336ull,
0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,0x2c36647225092034ull,0x34202c3564722520ull,
0x2f2f09202020203bull,0x752e646461090a20ull,0x3764722509203436ull,0x202c31647225202cull,
0x2020203b36647225ull,0x6c090a202f2f0920ull,0x6c61626f6c672e64ull,0x092038752e34762eull,
0x72252c343672257bull,0x2c363672252c3536ull,0x6472255b202c7d5full,0x2f2f093b5d302b37ull,
0x732e627573090a20ull,0x3736722509203233ull,0x202c36367225202cull,0x2020203b39317225ull,
0x61090a202f2f0920ull,0x09203233732e7362ull,0x7225202c38367225ull,0x20202020203b3736ull,
0x2f2f092020202020ull,0x732e766f6d090a20ull,0x3936722509203233ull,0x2020203b3031202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x33752e74672e7465ull,0x2509203233732e32ull,
0x367225202c303772ull,0x3b39367225202c38ull,0x656e090a202f2f09ull,0x2509203233732e67ull,
0x377225202c313772ull,0x2020202020203b30ull,0x202f2f0920202020ull,0x33732e627573090aull,
0x2c32377225092032ull,0x25202c3436722520ull,0x202020203b373172ull,0x6261090a202f2f09ull,
0x2509203233732e73ull,0x377225202c333772ull,0x2020202020203b32ull,0x202f2f0920202020ull,
0x33732e766f6d090aull,0x2c34377225092032ull,0x202020203b303120ull,0x2020202020202020ull,
0x6573090a202f2f09ull,0x3233752e74672e74ull,0x722509203233732eull,0x33377225202c3537ull,
0x093b34377225202cull,0x67656e090a202f2full,0x722509203233732eull,0x35377225202c3637ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x3233732e62757309ull,0x202c373772250920ull,
0x7225202c35367225ull,0x09202020203b3831ull,0x736261090a202f2full,0x722509203233732eull,
0x37377225202c3837ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233732e766f6d09ull,
0x202c393772250920ull,0x20202020203b3031ull,0x0920202020202020ull,0x746573090a202f2full,
0x2e3233752e74672eull,0x3872250920323373ull,0x2c38377225202c30ull,0x2f093b3937722520ull,
0x2e67656e090a202full,0x3872250920323373ull,0x3b30387225202c31ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x09203233622e726full,0x7225202c32387225ull,0x31387225202c3637ull,
0x2f0920202020203bull,0x622e726f090a202full,0x3338722509203233ull,0x202c31377225202cull,
0x2020203b32387225ull,0x090a202f2f092020ull,0x203233732e646461ull,0x25202c3034722509ull,
0x387225202c303472ull,0x2f09202020203b33ull,0x315f744c240a202full,0x0a3a30353834315full,
0x3233732e64646109ull,0x202c343872250920ull,0x203b31202c367225ull,0x0920202020202020ull,
0x746573090a202f2full,0x3233732e656c2e70ull,0x25202c3570250920ull,0x34387225202c3772ull,
0x0a202f2f0920203bull,0x7262203570254009ull,0x315f744c24092061ull,0x203b32363335315full,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3137310936310963ull,0x2e646461090a3009ull,
0x3872250920323373ull,0x2c36317225202c35ull,0x2020203b38722520ull,0x090a202f2f092020ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x3b35387225202c38ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c39647225ull,0x20203b34202c3864ull,
0x090a202f2f092020ull,0x203436752e646461ull,0x202c303164722509ull,0x7225202c31647225ull,
0x2f092020203b3964ull,0x672e646c090a202full,0x34762e6c61626f6cull,0x72257b092038752eull,
0x2c373872252c3638ull,0x2c7d5f2c38387225ull,0x2b30316472255b20ull,0x0a202f2f093b5d30ull,
0x3233732e62757309ull,0x202c393872250920ull,0x7225202c38387225ull,0x09202020203b3931ull,
0x736261090a202f2full,0x722509203233732eull,0x39387225202c3039ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c313972250920ull,0x20202020203b3031ull,
0x0920202020202020ull,0x746573090a202f2full,0x2e3233752e74672eull,0x3972250920323373ull,
0x2c30397225202c32ull,0x2f093b3139722520ull,0x2e67656e090a202full,0x3972250920323373ull,
0x3b32397225202c33ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e627573ull,
0x25202c3439722509ull,0x317225202c363872ull,0x2f09202020203b37ull,0x2e736261090a202full,
0x3972250920323373ull,0x3b34397225202c35ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x31202c3639722509ull,0x2020202020203b30ull,0x2f09202020202020ull,
0x2e746573090a202full,0x732e3233752e7467ull,0x3739722509203233ull,0x202c35397225202cull,
0x2f2f093b36397225ull,0x732e67656e090a20ull,0x3839722509203233ull,0x203b37397225202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c39397225ull,
0x38317225202c3738ull,0x2f2f09202020203bull,0x732e736261090a20ull,0x3031722509203233ull,
0x3b39397225202c30ull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x31202c3130317225ull,0x2020202020203b30ull,0x2f2f092020202020ull,0x672e746573090a20ull,
0x33732e3233752e74ull,0x3230317225092032ull,0x2c3030317225202cull,0x093b313031722520ull,
0x67656e090a202f2full,0x722509203233732eull,0x317225202c333031ull,0x20202020203b3230ull,
0x0a202f2f09202020ull,0x203233622e726f09ull,0x202c343031722509ull,0x7225202c38397225ull,
0x092020203b333031ull,0x2e726f090a202f2full,0x3172250920323362ull,0x33397225202c3530ull,
0x3b3430317225202cull,0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c303472250920ull,
0x7225202c30347225ull,0x092020203b353031ull,0x5f744c240a202f2full,0x3a32363335315f31ull,
0x33752e766f6d090aull,0x3630317225092032ull,0x202020203b30202cull,0x2020202020202020ull,
0x6573090a202f2f09ull,0x33732e71652e7074ull,0x202c367025092032ull,0x7225202c30347225ull,
0x202f2f093b363031ull,0x622036702540090aull,0x5f744c2409206172ull,0x3b34373835315f31ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x373109363109636full,0x747663090a300938ull,
0x2e3233662e6e722eull,0x3166250920323373ull,0x20203b347225202cull,0x0a202f2f09202020ull,
0x617261702e646c09ull,0x2509203233662e6dull,0x635f5f5b202c3266ull,0x5f6d726170616475ull,
0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f31ull,0x6969347261686375ull,
0x5f53666666666669ull,0x656c6163735f6969ull,0x6469202f2f093b5dull,0x635f5f203736363aull,
0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f31ull,
0x6969347261686375ull,0x5f53666666666669ull,0x656c6163735f6969ull,0x756d090a3078302bull,
0x2509203233662e6cull,0x2c316625202c3366ull,0x2020203b32662520ull,0x202f2f0920202020ull,
0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c346625ull,0x6d72617061647563ull,
0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3153ull,0x6934726168637536ull,
0x5366666666666969ull,0x66664f785f69695full,0x69202f2f093b5d30ull,0x5f5f203636363a64ull,
0x6d72617061647563ull,0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3153ull,
0x6934726168637536ull,0x5366666666666969ull,0x66664f785f69695full,0x61090a3078302b30ull,
0x09203233662e6464ull,0x336625202c356625ull,0x20203b346625202cull,0x2f2f092020202020ull,
0x662e627573090a20ull,0x2c36662509203233ull,0x6625202c35662520ull,0x2020202020203b33ull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x346625202c376625ull,0x20203b366625202cull,
0x2f2f092020202020ull,0x662e627573090a20ull,0x2c38662509203233ull,0x6625202c35662520ull,
0x2020202020203b36ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x336625202c396625ull,
0x20203b386625202cull,0x2f2f092020202020ull,0x662e646461090a20ull,0x3031662509203233ull,
0x25202c376625202cull,0x20202020203b3966ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x3166250920323366ull,0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,
0x5d3166664f785f69ull,0x3a6469202f2f093bull,0x75635f5f20333936ull,0x5f5f6d7261706164ull,
0x65646e614d38315aull,0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,
0x695f536666666666ull,0x2b3166664f785f69ull,0x646461090a307830ull,0x662509203233662eull,
0x31316625202c3231ull,0x203b30316625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c333166250920ull,0x316625202c356625ull,0x0920202020203b32ull,0x627573090a202f2full,
0x662509203233662eull,0x33316625202c3431ull,0x20203b356625202cull,0x0a202f2f09202020ull,
0x3233662e62757309ull,0x202c353166250920ull,0x6625202c32316625ull,0x09202020203b3431ull,
0x6f6c2e090a202f2full,0x3937310936310963ull,0x2e747663090a3009ull,0x732e3233662e6e72ull,
0x3631662509203233ull,0x20203b367225202cull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3731662509ull,0x326625202c363166ull,0x2f0920202020203bull,0x702e646c090a202full,
0x3233662e6d617261ull,0x202c383166250920ull,0x70616475635f5f5bull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,
0x795f69695f536666ull,0x2f093b5d3066664full,0x3536363a6469202full,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x795f69695f536666ull,0x3078302b3066664full,0x33662e646461090aull,
0x2c39316625092032ull,0x25202c3731662520ull,0x202020203b383166ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x316625202c303266ull,0x3b37316625202c39ull,0x202f2f0920202020ull,
0x33662e627573090aull,0x2c31326625092032ull,0x25202c3831662520ull,0x202020203b303266ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x316625202c323266ull,0x3b30326625202c39ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c33326625092032ull,0x25202c3731662520ull,
0x202020203b323266ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x326625202c343266ull,
0x3b33326625202c31ull,0x202f2f0920202020ull,0x7261702e646c090aull,0x09203233662e6d61ull,
0x5f5b202c35326625ull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,0x664f795f69695f53ull,
0x202f2f093b5d3166ull,0x5f203439363a6469ull,0x726170616475635full,0x614d38315a5f5f6dull,
0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,
0x664f795f69695f53ull,0x090a3078302b3166ull,0x203233662e646461ull,0x25202c3632662509ull,
0x326625202c353266ull,0x2f09202020203b34ull,0x2e646461090a202full,0x3266250920323366ull,
0x2c39316625202c37ull,0x20203b3632662520ull,0x090a202f2f092020ull,0x203233662e627573ull,
0x25202c3832662509ull,0x316625202c373266ull,0x2f09202020203b39ull,0x2e627573090a202full,
0x3266250920323366ull,0x2c36326625202c39ull,0x20203b3832662520ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6d090a3009393233ull,0x09203233662e766full,0x6625202c30336625ull,
0x20202020203b3732ull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009303333093531ull,
0x33662e766f6d090aull,0x2c31336625092032ull,0x20203b3932662520ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x333309353109636full,0x766f6d090a300931ull,0x662509203233662eull,
0x33316625202c3233ull,0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300932333309ull,0x203233662e766f6dull,0x25202c3333662509ull,0x202020203b353166ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0933333309353109ull,0x662e766f6d090a30ull,
0x3433662509203233ull,0x303036346630202cull,0x2020203b30303430ull,0x393138202f2f0920ull,
0x662e6c756d090a33ull,0x3533662509203233ull,0x202c37326625202cull,0x2020203b34336625ull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c36336625ull,0x37326625202c3533ull,
0x2f2f09202020203bull,0x662e627573090a20ull,0x3733662509203233ull,0x202c35336625202cull,
0x2020203b36336625ull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c38336625ull,
0x37336625202c3732ull,0x2f2f09202020203bull,0x662e6c756d090a20ull,0x3933662509203233ull,
0x202c37326625202cull,0x2020203b37326625ull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x6625202c30346625ull,0x39326625202c3732ull,0x2f2f09202020203bull,0x662e64616d090a20ull,
0x3134662509203233ull,0x202c37326625202cull,0x6625202c39326625ull,0x0a202f2f093b3034ull,
0x3233662e64646109ull,0x202c323466250920ull,0x6625202c39336625ull,0x09202020203b3134ull,
0x6c756d090a202f2full,0x662509203233662eull,0x37336625202c3334ull,0x203b37336625202cull,
0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c343466250920ull,0x6625202c33346625ull,
0x09202020203b3933ull,0x627573090a202f2full,0x662509203233662eull,0x32346625202c3534ull,
0x203b39336625202cull,0x0a202f2f09202020ull,0x3233662e64616d09ull,0x202c363466250920ull,
0x6625202c37336625ull,0x34346625202c3833ull,0x73090a202f2f093bull,0x09203233662e6275ull,
0x6625202c37346625ull,0x35346625202c3234ull,0x2f2f09202020203bull,0x662e627573090a20ull,
0x3834662509203233ull,0x202c31346625202cull,0x2020203b35346625ull,0x6d090a202f2f0920ull,
0x09203233662e6461ull,0x6625202c39346625ull,0x38336625202c3733ull,0x093b36346625202cull,
0x627573090a202f2full,0x662509203233662eull,0x39336625202c3035ull,0x203b37346625202cull,
0x0a202f2f09202020ull,0x3233662e64616d09ull,0x202c313566250920ull,0x6625202c38336625ull,
0x39346625202c3833ull,0x61090a202f2f093bull,0x09203233662e6464ull,0x6625202c32356625ull,
0x30356625202c3834ull,0x2f2f09202020203bull,0x662e646461090a20ull,0x3335662509203233ull,
0x202c31356625202cull,0x2020203b32356625ull,0x6d090a202f2f0920ull,0x09203233662e6461ull,
0x6625202c34356625ull,0x39326625202c3932ull,0x093b33356625202cull,0x646461090a202f2full,
0x662509203233662eull,0x32346625202c3535ull,0x203b34356625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c363566250920ull,0x2020203b35356625ull,0x0920202020202020ull,
0x627573090a202f2full,0x662509203233662eull,0x35356625202c3735ull,0x203b32346625202cull,
0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c383566250920ull,0x6625202c34356625ull,
0x09202020203b3735ull,0x766f6d090a202f2full,0x662509203233662eull,0x38356625202c3935ull,
0x202020202020203bull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300934333309ull,
0x203233662e766f6dull,0x30202c3036662509ull,0x3034303030363466ull,0x2f09202020203b30ull,
0x090a33393138202full,0x203233662e6c756dull,0x25202c3136662509ull,0x366625202c333166ull,
0x2f09202020203b30ull,0x2e627573090a202full,0x3666250920323366ull,0x2c31366625202c32ull,
0x20203b3331662520ull,0x090a202f2f092020ull,0x203233662e627573ull,0x25202c3336662509ull,
0x366625202c313666ull,0x2f09202020203b32ull,0x2e627573090a202full,0x3666250920323366ull,
0x2c33316625202c34ull,0x20203b3336662520ull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3536662509ull,0x316625202c333166ull,0x2f09202020203b33ull,0x2e6c756d090a202full,
0x3666250920323366ull,0x2c33316625202c36ull,0x20203b3531662520ull,0x090a202f2f092020ull,
0x203233662e64616dull,0x25202c3736662509ull,0x316625202c333166ull,0x3b36366625202c35ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x366625202c383666ull,0x3b37366625202c35ull,
0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c39366625092032ull,0x25202c3336662520ull,
0x202020203b333666ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x366625202c303766ull,
0x3b35366625202c39ull,0x202f2f0920202020ull,0x33662e627573090aull,0x2c31376625092032ull,
0x25202c3836662520ull,0x202020203b353666ull,0x616d090a202f2f09ull,0x2509203233662e64ull,
0x366625202c323766ull,0x2c34366625202c33ull,0x2f093b3037662520ull,0x2e627573090a202full,
0x3766250920323366ull,0x2c38366625202c33ull,0x20203b3137662520ull,0x090a202f2f092020ull,
0x203233662e627573ull,0x25202c3437662509ull,0x376625202c373666ull,0x2f09202020203b31ull,
0x2e64616d090a202full,0x3766250920323366ull,0x2c33366625202c35ull,0x25202c3436662520ull,
0x202f2f093b323766ull,0x33662e627573090aull,0x2c36376625092032ull,0x25202c3536662520ull,
0x202020203b333766ull,0x616d090a202f2f09ull,0x2509203233662e64ull,0x366625202c373766ull,
0x2c34366625202c34ull,0x2f093b3537662520ull,0x2e646461090a202full,0x3766250920323366ull,
0x2c34376625202c38ull,0x20203b3637662520ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x25202c3937662509ull,0x376625202c373766ull,0x2f09202020203b38ull,0x2e64616d090a202full,
0x3866250920323366ull,0x2c35316625202c30ull,0x25202c3531662520ull,0x202f2f093b393766ull,
0x33662e646461090aull,0x2c31386625092032ull,0x25202c3836662520ull,0x202020203b303866ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x386625202c323866ull,0x2020202020203b31ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x2c33386625092032ull,0x25202c3138662520ull,
0x202020203b383666ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x386625202c343866ull,
0x3b33386625202c30ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c35386625092032ull,
0x20203b3438662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x333309353109636full,
0x646461090a300935ull,0x662509203233662eull,0x35356625202c3638ull,0x203b31386625202cull,
0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c373866250920ull,0x6625202c36386625ull,
0x09202020203b3138ull,0x627573090a202f2full,0x662509203233662eull,0x35356625202c3838ull,
0x203b37386625202cull,0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c393866250920ull,
0x6625202c36386625ull,0x09202020203b3738ull,0x627573090a202f2full,0x662509203233662eull,
0x31386625202c3039ull,0x203b39386625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c313966250920ull,0x6625202c38386625ull,0x09202020203b3039ull,0x646461090a202f2full,
0x662509203233662eull,0x34386625202c3239ull,0x203b31396625202cull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x202c333966250920ull,0x6625202c38356625ull,0x09202020203b3239ull,
0x646461090a202f2full,0x662509203233662eull,0x36386625202c3439ull,0x203b33396625202cull,
0x0a202f2f09202020ull,0x3233662e62757309ull,0x202c353966250920ull,0x6625202c34396625ull,
0x09202020203b3638ull,0x627573090a202f2full,0x662509203233662eull,0x33396625202c3639ull,
0x203b35396625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300936333309ull,
0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c373031ull,0x6d72617061647563ull,
0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3153ull,0x6934726168637536ull,
0x5366666666666969ull,0x6e7572635f69695full,0x202f2f093b5d6863ull,0x5f203436363a6469ull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f315344ull,
0x3472616863753650ull,0x6666666666696969ull,0x7572635f69695f53ull,0x0a3078302b68636eull,
0x3233732e62757309ull,0x2c38303172250920ull,0x202c373031722520ull,0x0920202020203b31ull,
0x766f6d090a202f2full,0x722509203233752eull,0x203b31202c393031ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x3730317225202c37ull,
0x3b3930317225202cull,0x2540090a202f2f09ull,0x0920617262203770ull,0x36315f315f744c24ull,
0x202020203b383938ull,0x202f2f0920202020ull,0x33662e646461090aull,0x2c37396625092032ull,
0x25202c3439662520ull,0x202020203b363966ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x346630202c383966ull,0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,
0x09203233662e746cull,0x396625202c387025ull,0x3b38396625202c37ull,0x40090a202f2f0920ull,
0x6172622038702521ull,0x5f315f744c240920ull,0x20203b3839383631ull,0x2f2f092020202020ull,
0x315f315f4c240a20ull,0x2f200a3a30393232ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,
0x3320656e696c2079ull,0x636f6c2e090a3733ull,0x0937333309353109ull,0x662e6c756d090a30ull,
0x3939662509203233ull,0x202c31336625202cull,0x2020203b32336625ull,0x6d090a202f2f0920ull,
0x09203233662e6c75ull,0x25202c3030316625ull,0x336625202c303366ull,0x2f2f092020203b32ull,
0x662e766f6d090a20ull,0x3031662509203233ull,0x3036346630202c31ull,0x20203b3030343030ull,
0x393138202f2f0920ull,0x662e6c756d090a33ull,0x3031662509203233ull,0x2c32336625202c32ull,
0x203b313031662520ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x30202c3330316625ull,
0x3034303030363466ull,0x2f2f092020203b30ull,0x6d090a3339313820ull,0x09203233662e6c75ull,
0x25202c3430316625ull,0x316625202c303366ull,0x2f2f0920203b3330ull,0x662e64616d090a20ull,
0x3031662509203233ull,0x2c30336625202c35ull,0x25202c3333662520ull,0x202f2f093b393966ull,
0x33662e627573090aull,0x3630316625092032ull,0x2c3230316625202cull,0x20203b3233662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c37303166ull,0x336625202c343031ull,
0x202f2f0920203b30ull,0x33662e646461090aull,0x3830316625092032ull,0x2c3030316625202cull,
0x203b353031662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c39303166ull,
0x316625202c323031ull,0x202f2f09203b3630ull,0x33662e627573090aull,0x3031316625092032ull,
0x2c3430316625202cull,0x203b373031662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,
0x6625202c31313166ull,0x316625202c383031ull,0x202f2f09203b3030ull,0x33662e627573090aull,
0x3231316625092032ull,0x202c32336625202cull,0x20203b3930316625ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x6625202c33313166ull,0x316625202c393031ull,0x202f2f09203b3031ull,
0x33662e627573090aull,0x3431316625092032ull,0x2c3331316625202cull,0x203b303031662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c35313166ull,0x31316625202c3033ull,
0x202f2f0920203b30ull,0x33662e627573090aull,0x3631316625092032ull,0x2c3530316625202cull,
0x203b313131662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c37313166ull,
0x316625202c383031ull,0x202f2f09203b3131ull,0x33662e64616d090aull,0x3831316625092032ull,
0x2c3930316625202cull,0x202c353131662520ull,0x2f093b3431316625ull,0x2e627573090a202full,
0x3166250920323366ull,0x30316625202c3931ull,0x3731316625202c30ull,0x090a202f2f09203bull,
0x203233662e64616dull,0x202c303231662509ull,0x25202c3031316625ull,0x6625202c32313166ull,
0x202f2f093b383131ull,0x33662e646461090aull,0x3132316625092032ull,0x2c3631316625202cull,
0x203b393131662520ull,0x616d090a202f2f09ull,0x2509203233662e64ull,0x6625202c32323166ull,
0x316625202c323131ull,0x32316625202c3531ull,0x090a202f2f093b30ull,0x203233662e646461ull,
0x202c333231662509ull,0x25202c3132316625ull,0x2f09203b32323166ull,0x2e64616d090a202full,
0x3166250920323366ull,0x31336625202c3432ull,0x202c33336625202cull,0x2f093b3332316625ull,
0x2e646461090a202full,0x3166250920323366ull,0x30316625202c3532ull,0x3432316625202c38ull,
0x090a202f2f09203bull,0x203233662e627573ull,0x202c363231662509ull,0x25202c3532316625ull,
0x2f09203b38303166ull,0x2e627573090a202full,0x3366250920323366ull,0x3432316625202c31ull,
0x3b3632316625202cull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x61090a3009383333ull,
0x09203233662e6464ull,0x25202c3732316625ull,0x6625202c35323166ull,0x2f2f09203b353231ull,
0x662e627573090a20ull,0x3231662509203233ull,0x3732316625202c38ull,0x3b3532316625202cull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3932316625ull,0x6625202c35323166ull,
0x2f2f09203b383231ull,0x662e627573090a20ull,0x3331662509203233ull,0x3732316625202c30ull,
0x3b3832316625202cull,0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3133316625ull,
0x6625202c35323166ull,0x2f2f09203b303331ull,0x662e646461090a20ull,0x3331662509203233ull,
0x3932316625202c32ull,0x3b3133316625202cull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x25202c3333316625ull,0x6625202c32333166ull,0x2f2f0920203b3133ull,0x662e646461090a20ull,
0x3331662509203233ull,0x3333316625202c34ull,0x203b31336625202cull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x25202c3533316625ull,0x6625202c37323166ull,0x2f2f09203b343331ull,
0x662e627573090a20ull,0x3331662509203233ull,0x3533316625202c36ull,0x3b3732316625202cull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x6625202c31336625ull,0x316625202c343331ull,
0x2f2f0920203b3633ull,0x09636f6c2e090a20ull,0x3009393333093531ull,0x33662e646461090aull,
0x3733316625092032ull,0x202c37326625202cull,0x20203b3533316625ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x6625202c38333166ull,0x316625202c373331ull,0x202f2f09203b3533ull,
0x33662e627573090aull,0x3933316625092032ull,0x202c37326625202cull,0x20203b3833316625ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c30343166ull,0x316625202c373331ull,
0x202f2f09203b3833ull,0x33662e627573090aull,0x3134316625092032ull,0x2c3533316625202cull,
0x203b303431662520ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x6625202c32343166ull,
0x316625202c393331ull,0x202f2f09203b3134ull,0x33662e646461090aull,0x3334316625092032ull,
0x202c31336625202cull,0x20203b3234316625ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x6625202c34343166ull,0x34316625202c3932ull,0x202f2f0920203b33ull,0x33662e646461090aull,
0x3534316625092032ull,0x2c3733316625202cull,0x203b343431662520ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x316625202c303366ull,0x20202020203b3534ull,0x202f2f0920202020ull,
0x33662e627573090aull,0x3634316625092032ull,0x2c3534316625202cull,0x203b373331662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c37343166ull,0x316625202c343431ull,
0x202f2f09203b3634ull,0x33662e766f6d090aull,0x2c31336625092032ull,0x203b373431662520ull,
0x2020202020202020ull,0x6c2e090a202f2f09ull,0x343309353109636full,0x627573090a300932ull,
0x662509203233662eull,0x386625202c383431ull,0x3b36356625202c32ull,0x0a202f2f09202020ull,
0x3233662e62757309ull,0x2c39343166250920ull,0x202c383431662520ull,0x0920203b32386625ull,
0x627573090a202f2full,0x662509203233662eull,0x316625202c303531ull,0x34316625202c3834ull,
0x0a202f2f09203b39ull,0x3233662e64646109ull,0x2c31353166250920ull,0x202c393431662520ull,
0x0920203b36356625ull,0x627573090a202f2full,0x662509203233662eull,0x386625202c323531ull,
0x3035316625202c32ull,0x0a202f2f0920203bull,0x3233662e62757309ull,0x2c33353166250920ull,
0x202c323531662520ull,0x09203b3135316625ull,0x646461090a202f2full,0x662509203233662eull,
0x316625202c343531ull,0x35386625202c3335ull,0x0a202f2f0920203bull,0x3233662e62757309ull,
0x2c35353166250920ull,0x202c343531662520ull,0x0920203b39356625ull,0x646461090a202f2full,
0x662509203233662eull,0x316625202c363531ull,0x35316625202c3834ull,0x0a202f2f09203b35ull,
0x3233662e64646109ull,0x2c37353166250920ull,0x202c363531662520ull,0x0920203b33316625ull,
0x627573090a202f2full,0x662509203233662eull,0x316625202c383531ull,0x35316625202c3735ull,
0x0a202f2f09203b36ull,0x3233662e62757309ull,0x2c39353166250920ull,0x202c373531662520ull,
0x09203b3835316625ull,0x627573090a202f2full,0x662509203233662eull,0x316625202c303631ull,
0x35316625202c3635ull,0x0a202f2f09203b39ull,0x3233662e62757309ull,0x2c31363166250920ull,
0x25202c3331662520ull,0x0920203b38353166ull,0x646461090a202f2full,0x662509203233662eull,
0x316625202c323631ull,0x36316625202c3036ull,0x0a202f2f09203b31ull,0x3233662e62757309ull,
0x2c33363166250920ull,0x202c363531662520ull,0x09203b3834316625ull,0x627573090a202f2full,
0x662509203233662eull,0x316625202c343631ull,0x36316625202c3535ull,0x0a202f2f09203b33ull,
0x3233662e64646109ull,0x2c35363166250920ull,0x202c323631662520ull,0x09203b3436316625ull,
0x646461090a202f2full,0x662509203233662eull,0x316625202c363631ull,0x3536316625202c35ull,
0x0a202f2f0920203bull,0x3233662e64646109ull,0x2c37363166250920ull,0x202c373531662520ull,
0x09203b3636316625ull,0x766f6d090a202f2full,0x662509203233662eull,0x36316625202c3233ull,
0x2020202020203b37ull,0x0a202f2f09202020ull,0x3233662e62757309ull,0x2c38363166250920ull,
0x202c373631662520ull,0x09203b3735316625ull,0x627573090a202f2full,0x662509203233662eull,
0x316625202c393631ull,0x36316625202c3636ull,0x0a202f2f09203b38ull,0x3233662e766f6d09ull,
0x202c333366250920ull,0x20203b3936316625ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3434330935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,0x34316625202c3037ull,
0x3534316625202c35ull,0x090a202f2f09203bull,0x203233662e766f6dull,0x202c313731662509ull,
0x3430303036346630ull,0x2f092020203b3030ull,0x090a33393138202full,0x203233662e6c756dull,
0x202c323731662509ull,0x25202c3534316625ull,0x2f09203b31373166ull,0x2e627573090a202full,
0x3166250920323366ull,0x37316625202c3337ull,0x3534316625202c32ull,0x090a202f2f09203bull,
0x203233662e6c756dull,0x202c343731662509ull,0x25202c3534316625ull,0x2f09203b37343166ull,
0x2e627573090a202full,0x3166250920323366ull,0x37316625202c3537ull,0x3337316625202c32ull,
0x090a202f2f09203bull,0x203233662e64616dull,0x202c363731662509ull,0x25202c3534316625ull,
0x6625202c37343166ull,0x202f2f093b343731ull,0x33662e627573090aull,0x3737316625092032ull,
0x2c3534316625202cull,0x203b353731662520ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x6625202c38373166ull,0x316625202c303731ull,0x202f2f09203b3637ull,0x33662e627573090aull,
0x3937316625092032ull,0x2c3837316625202cull,0x203b303731662520ull,0x7573090a202f2f09ull,
0x2509203233662e62ull,0x6625202c30383166ull,0x316625202c383731ull,0x202f2f09203b3937ull,
0x33662e627573090aull,0x3138316625092032ull,0x2c3037316625202cull,0x203b303831662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c32383166ull,0x316625202c363731ull,
0x202f2f09203b3937ull,0x33662e646461090aull,0x3338316625092032ull,0x2c3138316625202cull,
0x203b323831662520ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x6625202c34383166ull,
0x316625202c353731ull,0x202f2f09203b3537ull,0x33662e627573090aull,0x3538316625092032ull,
0x2c3438316625202cull,0x203b303731662520ull,0x616d090a202f2f09ull,0x2509203233662e64ull,
0x6625202c36383166ull,0x316625202c353731ull,0x38316625202c3737ull,0x090a202f2f093b35ull,
0x203233662e64616dull,0x202c373831662509ull,0x25202c3537316625ull,0x6625202c37373166ull,
0x202f2f093b363831ull,0x33662e64616d090aull,0x3838316625092032ull,0x2c3737316625202cull,
0x202c373731662520ull,0x2f093b3738316625ull,0x2e646461090a202full,0x3166250920323366ull,
0x38316625202c3938ull,0x3838316625202c33ull,0x090a202f2f09203bull,0x203233662e64616dull,
0x202c303931662509ull,0x25202c3734316625ull,0x6625202c37343166ull,0x202f2f093b393831ull,
0x33662e646461090aull,0x3139316625092032ull,0x2c3837316625202cull,0x203b303931662520ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x316625202c363566ull,0x20202020203b3139ull,
0x202f2f0920202020ull,0x33662e627573090aull,0x3239316625092032ull,0x2c3139316625202cull,
0x203b383731662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c33393166ull,
0x316625202c303931ull,0x202f2f09203b3239ull,0x33662e766f6d090aull,0x2c39356625092032ull,
0x203b333931662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x343309353109636full,
0x6c756d090a300935ull,0x662509203233662eull,0x316625202c343931ull,0x36316625202c3736ull,
0x0a202f2f09203b37ull,0x3233662e766f6d09ull,0x2c35393166250920ull,0x3030303634663020ull,
0x092020203b303034ull,0x0a33393138202f2full,0x3233662e6c756d09ull,0x2c36393166250920ull,
0x202c373631662520ull,0x09203b3539316625ull,0x627573090a202f2full,0x662509203233662eull,
0x316625202c373931ull,0x36316625202c3639ull,0x0a202f2f09203b37ull,0x3233662e6c756d09ull,
0x2c38393166250920ull,0x202c373631662520ull,0x09203b3936316625ull,0x627573090a202f2full,
0x662509203233662eull,0x316625202c393931ull,0x39316625202c3639ull,0x0a202f2f09203b37ull,
0x3233662e64616d09ull,0x2c30303266250920ull,0x202c373631662520ull,0x25202c3936316625ull,
0x2f2f093b38393166ull,0x662e627573090a20ull,0x3032662509203233ull,0x3736316625202c31ull,
0x3b3939316625202cull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3230326625ull,
0x6625202c34393166ull,0x2f2f09203b303032ull,0x662e627573090a20ull,0x3032662509203233ull,
0x3230326625202c33ull,0x3b3439316625202cull,0x73090a202f2f0920ull,0x09203233662e6275ull,
0x25202c3430326625ull,0x6625202c32303266ull,0x2f2f09203b333032ull,0x662e627573090a20ull,
0x3032662509203233ull,0x3439316625202c35ull,0x3b3430326625202cull,0x73090a202f2f0920ull,
0x09203233662e6275ull,0x25202c3630326625ull,0x6625202c30303266ull,0x2f2f09203b333032ull,
0x662e646461090a20ull,0x3032662509203233ull,0x3530326625202c37ull,0x3b3630326625202cull,
0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x25202c3830326625ull,0x6625202c39393166ull,
0x2f2f09203b393931ull,0x662e627573090a20ull,0x3032662509203233ull,0x3830326625202c39ull,
0x3b3439316625202cull,0x6d090a202f2f0920ull,0x09203233662e6461ull,0x25202c3031326625ull,
0x6625202c39393166ull,0x326625202c313032ull,0x0a202f2f093b3930ull,0x3233662e64616d09ull,
0x2c31313266250920ull,0x202c393931662520ull,0x25202c3130326625ull,0x2f2f093b30313266ull,
0x662e64616d090a20ull,0x3132662509203233ull,0x3130326625202c32ull,0x2c3130326625202cull,
0x093b313132662520ull,0x646461090a202f2full,0x662509203233662eull,0x326625202c333132ull,
0x31326625202c3730ull,0x0a202f2f09203b32ull,0x3233662e64616d09ull,0x2c34313266250920ull,
0x202c393631662520ull,0x25202c3936316625ull,0x2f2f093b33313266ull,0x662e646461090a20ull,
0x3132662509203233ull,0x3230326625202c35ull,0x3b3431326625202cull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x6625202c32386625ull,0x202020203b353132ull,0x2f2f092020202020ull,
0x662e627573090a20ull,0x3132662509203233ull,0x3531326625202c36ull,0x3b3230326625202cull,
0x73090a202f2f0920ull,0x09203233662e6275ull,0x25202c3731326625ull,0x6625202c34313266ull,
0x2f2f09203b363132ull,0x662e766f6d090a20ull,0x3538662509203233ull,0x3b3731326625202cull,
0x2020202020202020ull,0x2e090a202f2f0920ull,0x3309353109636f6cull,0x6461090a30093634ull,
0x2509203233662e64ull,0x6625202c38313266ull,0x326625202c313931ull,0x202f2f09203b3531ull,
0x33662e627573090aull,0x3931326625092032ull,0x2c3831326625202cull,0x203b353132662520ull,
0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c30323266ull,0x326625202c313931ull,
0x202f2f09203b3931ull,0x33662e627573090aull,0x3132326625092032ull,0x2c3831326625202cull,
0x203b393132662520ull,0x7573090a202f2f09ull,0x2509203233662e62ull,0x6625202c32323266ull,
0x326625202c353132ull,0x202f2f09203b3132ull,0x33662e646461090aull,0x3332326625092032ull,
0x2c3032326625202cull,0x203b323232662520ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x6625202c34323266ull,0x326625202c373132ull,0x202f2f09203b3332ull,0x33662e646461090aull,
0x3532326625092032ull,0x2c3339316625202cull,0x203b343232662520ull,0x6c2e090a202f2f09ull,
0x333309353109636full,0x627573090a300936ull,0x722509203233732eull,0x317225202c383031ull,
0x20203b31202c3830ull,0x0a202f2f09202020ull,0x3233752e766f6d09ull,0x2c30313172250920ull,
0x20202020203b3020ull,0x0920202020202020ull,0x746573090a202f2full,0x3233732e71652e70ull,
0x25202c3970250920ull,0x7225202c38303172ull,0x202f2f093b303131ull,0x622039702540090aull,
0x5f744c2409206172ull,0x3b38393836315f31ull,0x2020202020202020ull,0x2f2f200a202f2f09ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333320656e696c20ull,
0x2064616568202c37ull,0x2064656c6562616cull,0x3232315f315f4c24ull,0x2e646461090a3039ull,
0x3266250920323366ull,0x31326625202c3632ull,0x3532326625202c38ull,0x090a202f2f09203bull,
0x203233662e627573ull,0x202c373232662509ull,0x25202c3632326625ull,0x2f09203b38313266ull,
0x2e627573090a202full,0x3266250920323366ull,0x32326625202c3832ull,0x3732326625202c35ull,
0x090a202f2f09203bull,0x203233662e646461ull,0x202c393232662509ull,0x25202c3632326625ull,
0x2f09203b38323266ull,0x2e766f6d090a202full,0x3266250920323366ull,0x30346630202c3033ull,
0x203b303030303038ull,0x0a34202f2f092020ull,0x746c2e7074657309ull,0x702509203233662eull,
0x32326625202c3031ull,0x3033326625202c39ull,0x40090a202f2f093bull,0x6172622030317025ull,
0x315f315f4c240920ull,0x2020203b30393232ull,0x2f2f092020202020ull,0x5f315f744c240a20ull,
0x240a3a3839383631ull,0x343532315f315f4cull,0x636f6c2e090a3a36ull,0x0932383109363109ull,
0x732e766f6d090a30ull,0x3131722509203233ull,0x2020203b30202c31ull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x732e74672e707465ull,0x3131702509203233ull,0x2c3830317225202cull,
0x093b313131722520ull,0x627573090a202f2full,0x722509203233732eull,0x317225202c323131ull,
0x30317225202c3730ull,0x0a202f2f09203b38ull,0x3233732e766f6d09ull,0x2c33313172250920ull,
0x20202020203b3020ull,0x0920202020202020ull,0x6c6573090a202f2full,0x2509203233732e70ull,
0x7225202c34313172ull,0x317225202c323131ull,0x31317025202c3331ull,0x6d090a202f2f093bull,
0x09203233752e766full,0x30202c3531317225ull,0x202020202020203bull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e7165ull,0x7225202c32317025ull,0x317225202c343131ull,
0x0a202f2f093b3531ull,0x6220323170254009ull,0x5f744c2409206172ull,0x3b32343636315f31ull,
0x0920202020202020ull,0x6f6c2e090a202f2full,0x3938310936310963ull,0x702e646c090a3009ull,
0x3233732e6d617261ull,0x2c36313172250920ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f315344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x5f69695f53666666ull,0x6f6974616d696e61ull,0x3b5d656d6172466eull,0x363a6469202f2f09ull,
0x6475635f5f203539ull,0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,0x5f315344746f7262ull,
0x6375365030316d73ull,0x6669696934726168ull,0x69695f5366666666ull,0x6974616d696e615full,
0x2b656d6172466e6full,0x646461090a307830ull,0x722509203233732eull,0x317225202c373131ull,
0x31317225202c3631ull,0x0a202f2f09203b34ull,0x617261702e646c09ull,0x7225092038752e6dull,
0x5f5f5b202c383131ull,0x6d72617061647563ull,0x6e614d38315a5f5full,0x44746f72626c6564ull,
0x5030316d735f3153ull,0x6934726168637536ull,0x5366666666666969ull,0x6f6c6f635f69695full,
0x2f093b5d302b7372ull,0x3639363a6469202full,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,
0x635f69695f536666ull,0x78302b73726f6c6full,0x6c2e6c756d090a30ull,0x2509203233732e6full,
0x7225202c39313172ull,0x317225202c373131ull,0x0a202f2f093b3831ull,0x2e38752e74766309ull,
0x3172250920323375ull,0x31317225202c3032ull,0x0920202020203b39ull,0x6f6c2e090a202f2full,
0x3039310936310963ull,0x702e646c090a3009ull,0x2038752e6d617261ull,0x202c313231722509ull,
0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,
0x6168637536503031ull,0x6666666969693472ull,0x635f69695f536666ull,0x5d312b73726f6c6full,
0x3a6469202f2f093bull,0x75635f5f20373936ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x695f536666666666ull,
0x73726f6c6f635f69ull,0x756d090a3178302bull,0x3233732e6f6c2e6cull,0x2c32323172250920ull,
0x202c373131722520ull,0x2f093b3132317225ull,0x2e747663090a202full,0x09203233752e3875ull,
0x25202c3332317225ull,0x2020203b32323172ull,0x090a202f2f092020ull,0x09363109636f6c2eull,
0x6c090a3009313931ull,0x2e6d617261702e64ull,0x3231722509203875ull,0x75635f5f5b202c34ull,
0x5f5f6d7261706164ull,0x65646e614d38315aull,0x315344746f72626cull,0x75365030316d735full,
0x6969693472616863ull,0x695f536666666666ull,0x73726f6c6f635f69ull,0x202f2f093b5d322bull,
0x5f203839363a6469ull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,0x6c6f635f69695f53ull,
0x0a3278302b73726full,0x2e6f6c2e6c756d09ull,0x3172250920323373ull,0x31317225202c3532ull,
0x3432317225202c37ull,0x63090a202f2f093bull,0x33752e38752e7476ull,0x3632317225092032ull,
0x3b3532317225202cull,0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,
0x3b36383336315f31ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x343636315f315f74ull,
0x636f6c2e090a3a32ull,0x0935393109363109ull,0x752e766f6d090a30ull,0x3231722509203233ull,
0x2020203b30202c36ull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233752e766full,
0x30202c3332317225ull,0x202020202020203bull,0x2f2f092020202020ull,0x752e766f6d090a20ull,
0x3231722509203233ull,0x2020203b30202c30ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x383336315f315f74ull,0x636f6c2e090a3a36ull,0x0931303209363109ull,0x61702e646c090a30ull,
0x203233732e6d6172ull,0x202c373231722509ull,0x70616475635f5f5bull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,
0x665f69695f536666ull,0x2f093b5d656d6172ull,0x3036363a6469202full,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x665f69695f536666ull,0x3078302b656d6172ull,0x33732e646461090aull,
0x3832317225092032ull,0x2c3732317225202cull,0x20202020203b3120ull,0x6873090a202f2f09ull,
0x2509203233732e72ull,0x7225202c39323172ull,0x3b3133202c383231ull,0x202f2f0920202020ull,
0x33732e766f6d090aull,0x3033317225092032ull,0x202020203b31202cull,0x2020202020202020ull,
0x6e61090a202f2f09ull,0x2509203233622e64ull,0x7225202c31333172ull,0x317225202c393231ull,
0x202f2f09203b3033ull,0x33732e646461090aull,0x3233317225092032ull,0x2c3133317225202cull,
0x203b383231722520ull,0x6873090a202f2f09ull,0x2509203233732e72ull,0x7225202c33333172ull,
0x203b31202c323331ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x317225202c343331ull,0x37317225202c3732ull,0x61090a202f2f093bull,0x09203233732e6464ull,
0x25202c3533317225ull,0x7225202c30323172ull,0x2f2f09203b343331ull,0x732e646461090a20ull,
0x3331722509203233ull,0x3333317225202c36ull,0x3b3533317225202cull,0x64090a202f2f0920ull,
0x09203233732e7669ull,0x25202c3733317225ull,0x7225202c36333172ull,0x2f2f09203b383231ull,
0x09636f6c2e090a20ull,0x3009323032093631ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x317225202c383331ull,0x38317225202c3732ull,0x61090a202f2f093bull,0x09203233732e6464ull,
0x25202c3933317225ull,0x7225202c33323172ull,0x2f2f09203b383331ull,0x732e646461090a20ull,
0x3431722509203233ull,0x3333317225202c30ull,0x3b3933317225202cull,0x64090a202f2f0920ull,
0x09203233732e7669ull,0x25202c3134317225ull,0x7225202c30343172ull,0x2f2f09203b383231ull,
0x6c672e7473090a20ull,0x2e32762e6c61626full,0x6472255b09203875ull,0x257b202c5d302b34ull,
0x3172252c37333172ull,0x202f2f093b7d3134ull,0x3109636f6c2e090aull,0x0a30093330320936ull,
0x2e6f6c2e6c756d09ull,0x3172250920323373ull,0x32317225202c3234ull,0x3b39317225202c37ull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x7225202c33343172ull,0x317225202c363231ull,
0x202f2f09203b3234ull,0x33732e646461090aull,0x3434317225092032ull,0x2c3333317225202cull,
0x203b333431722520ull,0x6964090a202f2f09ull,0x2509203233732e76ull,0x7225202c35343172ull,
0x317225202c343431ull,0x202f2f09203b3832ull,0x6f6c672e7473090aull,0x092038752e6c6162ull,
0x5d322b346472255bull,0x3b3534317225202cull,0x373a6469202f2f09ull,0x315f744c240a3130ull,
0x0a3a34373835315full,0x33315f315f744c24ull,0x6c2e090a3a343133ull,0x303209363109636full,
0x697865090a300936ull,0x2020202020203b74ull,0x2020202020202020ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x5f646e6557444c24ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f31ull,0x6969347261686375ull,0x5f53666666666669ull,0x2f207d090a3a6969ull,
0x614d38315a5f202full,0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,
0x6666666666696969ull,0x2e090a0a69695f53ull,0x5a5f207972746e65ull,0x6c65646e614d3631ull,
0x6d735f30746f7262ull,0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x282069695f30535full,0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x0a2c7473645f6969ull,0x6d617261702e0909ull,
0x5f5f203233732e20ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,
0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,
0x576567616d695f69ull,0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764566ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x67616d695f69695full,0x702e09090a2c4865ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x72635f69695f3053ull,0x09090a2c68636e75ull,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x09090a2c66664f78ull,
0x2e206d617261702eull,0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,
0x735f30746f72626cull,0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,
0x5f69695f30535f32ull,0x09090a2c66664f79ull,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x090a2c656c616373ull,
0x206d617261702e09ull,0x34206e67696c612eull,0x635f5f2038622e20ull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x69695f30535f3253ull,0x5b73726f6c6f635full,0x702e09090a2c5d34ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x72665f69695f3053ull,0x2e09090a2c656d61ull,0x732e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764566493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x615f69695f30535full,0x6e6f6974616d696eull,
0x090a29656d617246ull,0x206765722e090a7bull,0x687225203631752eull,0x722e090a3b3e363cull,
0x203233752e206765ull,0x0a3b3e32363c7225ull,0x752e206765722e09ull,0x363c647225203436ull,
0x6765722e090a3b3eull,0x6625203233662e20ull,0x090a3b3e3331313cull,0x72702e206765722eull,
0x37323c7025206465ull,0x636f6c2e090a3b3eull,0x0a30093809363109ull,0x5a5f5f3142424c24ull,
0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764566493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x0a3a69695f30535full,0x3631752e766f6d09ull,0x202c316872250920ull,
0x782e646961746325ull,0x092020202020203bull,0x766f6d090a202f2full,0x722509203631752eull,
0x69746e25202c3268ull,0x202020203b782e64ull,0x0a202f2f09202020ull,0x6469772e6c756d09ull,
0x2509203631752e65ull,0x31687225202c3172ull,0x093b32687225202cull,0x766f6d090a202f2full,
0x722509203631752eull,0x61746325202c3368ull,0x2020203b792e6469ull,0x0a202f2f09202020ull,
0x3631752e766f6d09ull,0x202c346872250920ull,0x3b792e6469746e25ull,0x0920202020202020ull,
0x6c756d090a202f2full,0x31752e656469772eull,0x202c327225092036ull,0x7225202c33687225ull,
0x0a202f2f093b3468ull,0x3233752e74766309ull,0x722509203631752eull,0x2e64697425202c33ull,
0x0920202020203b78ull,0x646461090a202f2full,0x722509203233752eull,0x202c337225202c34ull,
0x202020203b317225ull,0x0a202f2f09202020ull,0x3233752e74766309ull,0x722509203631752eull,
0x2e64697425202c35ull,0x0920202020203b79ull,0x646461090a202f2full,0x722509203233752eull,
0x202c357225202c36ull,0x202020203b327225ull,0x0a202f2f09202020ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x635f5f5b202c3772ull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f30746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x69695f30535f3253ull,0x5d576567616d695full,0x3a6469202f2f093bull,0x75635f5f20373035ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x302b576567616d69ull,
0x702e646c090a3078ull,0x3233732e6d617261ull,0x5b202c3872250920ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764566ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x67616d695f69695full,0x202f2f093b5d4865ull,
0x5f203431353a6469ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x6567616d695f6969ull,0x73090a3078302b48ull,0x33752e74672e7465ull,0x2509203233732e32ull,
0x2c387225202c3972ull,0x2f2f093b36722520ull,0x732e67656e090a20ull,0x3031722509203233ull,
0x20203b397225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,0x33752e74672e7465ull,
0x2509203233732e32ull,0x377225202c313172ull,0x2f093b347225202cull,0x2e67656e090a202full,
0x3172250920323373ull,0x3b31317225202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233622e646e61ull,0x25202c3331722509ull,0x317225202c303172ull,0x2f09202020203b32ull,
0x2e766f6d090a202full,0x3172250920323375ull,0x2020203b30202c34ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x2e71652e70746573ull,0x3170250920323373ull,0x202c33317225202cull,
0x2f09203b34317225ull,0x31702540090a202full,0x4c24092061726220ull,0x393930325f325f74ull,
0x2020202020203b34ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x63090a3009393231ull,
0x33662e6e722e7476ull,0x2509203233732e32ull,0x3b367225202c3166ull,0x2f2f092020202020ull,
0x61702e646c090a20ull,0x203233662e6d6172ull,0x5f5b202c32662509ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x656c6163735f6969ull,0x6469202f2f093b5dull,
0x635f5f203630353aull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,
0x302b656c6163735full,0x702e646c090a3078ull,0x3233662e6d617261ull,0x5b202c3366250920ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,
0x6863753650764566ull,0x5f54696969347261ull,0x30535f32535f3253ull,0x66664f795f69695full,
0x6469202f2f093b5dull,0x635f5f203531353aull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f30746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x69695f30535f3253ull,0x78302b66664f795full,0x662e64616d090a30ull,0x2c34662509203233ull,
0x6625202c31662520ull,0x203b336625202c32ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x346625202c356625ull,0x202020202020203bull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009303331093531ull,0x6e722e747663090aull,0x3233732e3233662eull,0x25202c3666250920ull,
0x20202020203b3472ull,0x646c090a202f2f09ull,0x662e6d617261702eull,0x2c37662509203233ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f30746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x4f785f69695f3053ull,
0x202f2f093b5d6666ull,0x5f203631353a6469ull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f30535f32535f32ull,0x2b66664f785f6969ull,0x64616d090a307830ull,0x662509203233662eull,
0x202c366625202c38ull,0x376625202c326625ull,0x0a202f2f0920203bull,0x3233662e766f6d09ull,
0x25202c3966250920ull,0x20202020203b3866ull,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3333310935310963ull,0x702e646c090a3009ull,0x3233732e6d617261ull,0x202c353172250920ull,
0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,
0x6375365076456649ull,0x5469696934726168ull,0x535f32535f32535full,0x7572635f69695f30ull,
0x2f2f093b5d68636eull,0x203530353a646920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764566ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x6e7572635f69695full,0x090a3078302b6863ull,0x203233732e766f6dull,
0x25202c3631722509ull,0x202020203b353172ull,0x2f09202020202020ull,0x325f744c240a202full,
0x0a3a38333334315full,0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,
0x6c2e090a36393220ull,0x393209353109636full,0x6c756d090a300936ull,0x662509203233662eull,
0x2c356625202c3031ull,0x2020203b35662520ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,
0x202c313166250920ull,0x396625202c396625ull,0x092020202020203bull,0x646461090a202f2full,
0x662509203233662eull,0x31316625202c3231ull,0x203b30316625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c333166250920ull,0x3030303830346630ull,0x09202020203b3030ull,
0x6573090a34202f2full,0x33662e74672e7074ull,0x202c327025092032ull,0x6625202c32316625ull,
0x202f2f09203b3331ull,0x203270252140090aull,0x744c240920617262ull,0x36303531325f325full,
0x202020202020203bull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c373172ull,
0x2020203b31202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x325f744c24092069ull,
0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,0x36303531325f325full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38333334315f325full,
0x3109636f6c2e090aull,0x0a30093933310935ull,0x3233662e6c756d09ull,0x202c343166250920ull,
0x396625202c356625ull,0x092020202020203bull,0x646461090a202f2full,0x662509203233662eull,
0x34316625202c3531ull,0x203b34316625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x25202c3566250920ull,0x35316625202c3466ull,0x092020202020203bull,0x6f6c2e090a202f2full,
0x3034310935310963ull,0x2e627573090a3009ull,0x3166250920323366ull,0x2c31316625202c36ull,
0x20203b3031662520ull,0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c39662509ull,
0x3b36316625202c38ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0931343109353109ull,
0x662e6c756d090a30ull,0x3731662509203233ull,0x25202c356625202cull,0x20202020203b3566ull,
0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x6625202c31316625ull,0x203b396625202c39ull,
0x2f2f092020202020ull,0x662e646461090a20ull,0x3831662509203233ull,0x202c31316625202cull,
0x2020203b37316625ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c39316625ull,
0x3030303030383034ull,0x2f2f09202020203bull,0x70746573090a3420ull,0x203233662e74672eull,
0x6625202c33702509ull,0x39316625202c3831ull,0x090a202f2f09203bull,0x7262203370252140ull,
0x325f744c24092061ull,0x203b38313032325full,0x2f09202020202020ull,0x2e627573090a202full,
0x3172250920323373ull,0x2c36317225202c37ull,0x20202020203b3220ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x325f325f744c2409ull,0x20202020203b3835ull,0x2f09202020202020ull,
0x325f744c240a202full,0x0a3a38313032325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36393220ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a38333334315full,0x09353109636f6c2eull,0x6d090a3009373431ull,
0x09203233662e6c75ull,0x6625202c34316625ull,0x203b396625202c35ull,0x2f2f092020202020ull,
0x662e646461090a20ull,0x3032662509203233ull,0x202c34316625202cull,0x2020203b34316625ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x346625202c356625ull,0x203b30326625202cull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009383431093531ull,0x33662e627573090aull,
0x2c31326625092032ull,0x25202c3131662520ull,0x202020203b373166ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x2c386625202c3966ull,0x20203b3132662520ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093934310935ull,0x3233662e6c756d09ull,0x202c323266250920ull,
0x356625202c356625ull,0x092020202020203bull,0x6c756d090a202f2full,0x662509203233662eull,
0x2c396625202c3131ull,0x2020203b39662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c333266250920ull,0x6625202c31316625ull,0x09202020203b3232ull,0x766f6d090a202f2full,
0x662509203233662eull,0x30346630202c3432ull,0x203b303030303038ull,0x34202f2f09202020ull,
0x672e70746573090aull,0x2509203233662e74ull,0x33326625202c3470ull,0x203b34326625202cull,
0x2140090a202f2f09ull,0x2061726220347025ull,0x325f325f744c2409ull,0x2020203b30333532ull,
0x202f2f0920202020ull,0x33732e627573090aull,0x2c37317225092032ull,0x33202c3631722520ull,
0x202020202020203bull,0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f325f744cull,
0x202020202020203bull,0x202f2f0920202020ull,0x325f325f744c240aull,0x2f200a3a30333532ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3639ull,0x64656c6562616c20ull,0x315f325f744c2420ull,0x6c2e090a38333334ull,
0x353109353109636full,0x6c756d090a300935ull,0x662509203233662eull,0x2c356625202c3431ull,
0x2020203b39662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c353266250920ull,
0x6625202c34316625ull,0x09202020203b3431ull,0x646461090a202f2full,0x662509203233662eull,
0x202c346625202c35ull,0x2020203b35326625ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300936353109ull,0x203233662e627573ull,0x25202c3632662509ull,0x326625202c313166ull,
0x2f09202020203b32ull,0x2e646461090a202full,0x3966250920323366ull,0x25202c386625202cull,
0x202020203b363266ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009373531ull,
0x09203233662e6c75ull,0x6625202c37326625ull,0x203b356625202c35ull,0x2f2f092020202020ull,
0x662e6c756d090a20ull,0x3131662509203233ull,0x25202c396625202cull,0x20202020203b3966ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c38326625ull,0x37326625202c3131ull,
0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3932662509203233ull,0x303830346630202cull,
0x2020203b30303030ull,0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3570250920323366ull,
0x202c38326625202cull,0x2f09203b39326625ull,0x70252140090a202full,0x2409206172622035ull,
0x3033325f325f744cull,0x20202020203b3234ull,0x090a202f2f092020ull,0x203233732e627573ull,
0x25202c3731722509ull,0x203b34202c363172ull,0x2f09202020202020ull,0x2e617262090a202full,
0x744c240920696e75ull,0x203b3835325f325full,0x2020202020202020ull,0x240a202f2f092020ull,
0x3033325f325f744cull,0x3c2f2f200a3a3234ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36393220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3334315f325f744cull,0x636f6c2e090a3833ull,0x0933363109353109ull,0x662e6c756d090a30ull,
0x3431662509203233ull,0x25202c356625202cull,0x20202020203b3966ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x6625202c30336625ull,0x34316625202c3431ull,0x2f2f09202020203bull,
0x662e646461090a20ull,0x2c35662509203233ull,0x6625202c34662520ull,0x20202020203b3033ull,
0x2e090a202f2f0920ull,0x3109353109636f6cull,0x7573090a30093436ull,0x2509203233662e62ull,
0x316625202c313366ull,0x3b37326625202c31ull,0x202f2f0920202020ull,0x33662e646461090aull,
0x202c396625092032ull,0x336625202c386625ull,0x2020202020203b31ull,0x6c2e090a202f2f09ull,
0x363109353109636full,0x6c756d090a300935ull,0x662509203233662eull,0x2c356625202c3233ull,
0x2020203b35662520ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,0x202c313166250920ull,
0x396625202c396625ull,0x092020202020203bull,0x646461090a202f2full,0x662509203233662eull,
0x31316625202c3333ull,0x203b32336625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,
0x202c343366250920ull,0x3030303830346630ull,0x09202020203b3030ull,0x6573090a34202f2full,
0x33662e74672e7074ull,0x202c367025092032ull,0x6625202c33336625ull,0x202f2f09203b3433ull,
0x203670252140090aull,0x744c240920617262ull,0x34353533325f325full,0x202020202020203bull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c373172ull,0x2020203b35202c36ull,
0x202f2f0920202020ull,0x6e752e617262090aull,0x325f744c24092069ull,0x2020203b3835325full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x34353533325f325full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38333334315f325full,0x3109636f6c2e090aull,
0x0a30093137310935ull,0x3233662e6c756d09ull,0x202c343166250920ull,0x396625202c356625ull,
0x092020202020203bull,0x646461090a202f2full,0x662509203233662eull,0x34316625202c3533ull,
0x203b34316625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x25202c3566250920ull,
0x35336625202c3466ull,0x092020202020203bull,0x6f6c2e090a202f2full,0x3237310935310963ull,
0x2e627573090a3009ull,0x3366250920323366ull,0x2c31316625202c36ull,0x20203b3233662520ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c39662509ull,0x3b36336625202c38ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0933373109353109ull,0x662e6c756d090a30ull,
0x3733662509203233ull,0x25202c356625202cull,0x20202020203b3566ull,0x6d090a202f2f0920ull,
0x09203233662e6c75ull,0x6625202c31316625ull,0x203b396625202c39ull,0x2f2f092020202020ull,
0x662e646461090a20ull,0x3833662509203233ull,0x202c31316625202cull,0x2020203b37336625ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c39336625ull,0x3030303030383034ull,
0x2f2f09202020203bull,0x70746573090a3420ull,0x203233662e74672eull,0x6625202c37702509ull,
0x39336625202c3833ull,0x090a202f2f09203bull,0x7262203770252140ull,0x325f744c24092061ull,
0x203b36363034325full,0x2f09202020202020ull,0x2e627573090a202full,0x3172250920323373ull,
0x2c36317225202c37ull,0x20202020203b3620ull,0x090a202f2f092020ull,0x20696e752e617262ull,
0x325f325f744c2409ull,0x20202020203b3835ull,0x2f09202020202020ull,0x325f744c240a202full,
0x0a3a36363034325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c36393220ull,0x6c6562616c206461ull,0x325f744c24206465ull,
0x090a38333334315full,0x09353109636f6c2eull,0x6d090a3009393731ull,0x09203233662e6c75ull,
0x6625202c34316625ull,0x203b396625202c35ull,0x2f2f092020202020ull,0x662e646461090a20ull,
0x3034662509203233ull,0x202c34316625202cull,0x2020203b34316625ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x346625202c356625ull,0x203b30346625202cull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009303831093531ull,0x33662e627573090aull,0x2c31346625092032ull,
0x25202c3131662520ull,0x202020203b373366ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x2c386625202c3966ull,0x20203b3134662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093138310935ull,0x3233662e6c756d09ull,0x202c323466250920ull,0x356625202c356625ull,
0x092020202020203bull,0x6c756d090a202f2full,0x662509203233662eull,0x2c396625202c3131ull,
0x2020203b39662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c333466250920ull,
0x6625202c31316625ull,0x09202020203b3234ull,0x766f6d090a202f2full,0x662509203233662eull,
0x30346630202c3434ull,0x203b303030303038ull,0x34202f2f09202020ull,0x672e70746573090aull,
0x2509203233662e74ull,0x33346625202c3870ull,0x203b34346625202cull,0x2140090a202f2f09ull,
0x2061726220387025ull,0x325f325f744c2409ull,0x2020203b38373534ull,0x202f2f0920202020ull,
0x33732e627573090aull,0x2c37317225092032ull,0x37202c3631722520ull,0x202020202020203bull,
0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f325f744cull,0x202020202020203bull,
0x202f2f0920202020ull,0x325f325f744c240aull,0x2f200a3a38373534ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,
0x64656c6562616c20ull,0x315f325f744c2420ull,0x6c2e090a38333334ull,0x383109353109636full,
0x6c756d090a300937ull,0x662509203233662eull,0x2c356625202c3431ull,0x2020203b39662520ull,
0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c353466250920ull,0x6625202c34316625ull,
0x09202020203b3431ull,0x646461090a202f2full,0x662509203233662eull,0x202c346625202c35ull,
0x2020203b35346625ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938383109ull,
0x203233662e627573ull,0x25202c3634662509ull,0x346625202c313166ull,0x2f09202020203b32ull,
0x2e646461090a202full,0x3966250920323366ull,0x25202c386625202cull,0x202020203b363466ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009393831ull,0x09203233662e6c75ull,
0x6625202c37346625ull,0x203b356625202c35ull,0x2f2f092020202020ull,0x662e6c756d090a20ull,
0x3131662509203233ull,0x25202c396625202cull,0x20202020203b3966ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x6625202c38346625ull,0x37346625202c3131ull,0x2f2f09202020203bull,
0x662e766f6d090a20ull,0x3934662509203233ull,0x303830346630202cull,0x2020203b30303030ull,
0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3970250920323366ull,0x202c38346625202cull,
0x2f09203b39346625ull,0x70252140090a202full,0x2409206172622039ull,0x3035325f325f744cull,
0x20202020203b3039ull,0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3731722509ull,
0x203b38202c363172ull,0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,
0x203b3835325f325full,0x2020202020202020ull,0x240a202f2f092020ull,0x3035325f325f744cull,
0x3c2f2f200a3a3039ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x36393220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3334315f325f744cull,
0x636f6c2e090a3833ull,0x0935393109353109ull,0x662e6c756d090a30ull,0x3431662509203233ull,
0x25202c356625202cull,0x20202020203b3966ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x6625202c30356625ull,0x34316625202c3431ull,0x2f2f09202020203bull,0x662e646461090a20ull,
0x2c35662509203233ull,0x6625202c34662520ull,0x20202020203b3035ull,0x2e090a202f2f0920ull,
0x3109353109636f6cull,0x7573090a30093639ull,0x2509203233662e62ull,0x316625202c313566ull,
0x3b37346625202c31ull,0x202f2f0920202020ull,0x33662e646461090aull,0x202c396625092032ull,
0x356625202c386625ull,0x2020202020203b31ull,0x6c2e090a202f2f09ull,0x393109353109636full,
0x6c756d090a300937ull,0x662509203233662eull,0x2c356625202c3235ull,0x2020203b35662520ull,
0x0a202f2f09202020ull,0x3233662e6c756d09ull,0x202c313166250920ull,0x396625202c396625ull,
0x092020202020203bull,0x646461090a202f2full,0x662509203233662eull,0x31316625202c3335ull,
0x203b32356625202cull,0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c343566250920ull,
0x3030303830346630ull,0x09202020203b3030ull,0x6573090a34202f2full,0x33662e74672e7074ull,
0x2c30317025092032ull,0x25202c3335662520ull,0x202f2f093b343566ull,0x303170252140090aull,
0x4c24092061726220ull,0x303635325f325f74ull,0x2020202020203b32ull,0x7573090a202f2f09ull,
0x2509203233732e62ull,0x317225202c373172ull,0x2020203b39202c36ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x325f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x32303635325f325full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x38333334315f325full,0x3109636f6c2e090aull,0x0a30093330320935ull,
0x3233662e6c756d09ull,0x202c343166250920ull,0x396625202c356625ull,0x092020202020203bull,
0x646461090a202f2full,0x662509203233662eull,0x34316625202c3535ull,0x203b34316625202cull,
0x0a202f2f09202020ull,0x3233662e64646109ull,0x25202c3566250920ull,0x35356625202c3466ull,
0x092020202020203bull,0x6f6c2e090a202f2full,0x3430320935310963ull,0x2e627573090a3009ull,
0x3566250920323366ull,0x2c31316625202c36ull,0x20203b3235662520ull,0x090a202f2f092020ull,
0x203233662e646461ull,0x6625202c39662509ull,0x3b36356625202c38ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0935303209353109ull,0x662e6c756d090a30ull,0x3735662509203233ull,
0x25202c356625202cull,0x20202020203b3566ull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,
0x6625202c31316625ull,0x203b396625202c39ull,0x2f2f092020202020ull,0x662e646461090a20ull,
0x3835662509203233ull,0x202c31316625202cull,0x2020203b37356625ull,0x6d090a202f2f0920ull,
0x09203233662e766full,0x6630202c39356625ull,0x3030303030383034ull,0x2f2f09202020203bull,
0x70746573090a3420ull,0x203233662e74672eull,0x25202c3131702509ull,0x356625202c383566ull,
0x090a202f2f093b39ull,0x6220313170252140ull,0x5f744c2409206172ull,0x3b34313136325f32ull,
0x2f09202020202020ull,0x2e627573090a202full,0x3172250920323373ull,0x2c36317225202c37ull,
0x202020203b303120ull,0x090a202f2f092020ull,0x20696e752e617262ull,0x325f325f744c2409ull,
0x20202020203b3835ull,0x2f09202020202020ull,0x325f744c240a202full,0x0a3a34313136325full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36393220ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a38333334315full,
0x09353109636f6c2eull,0x6d090a3009313132ull,0x09203233662e6c75ull,0x6625202c34316625ull,
0x203b396625202c35ull,0x2f2f092020202020ull,0x662e646461090a20ull,0x3036662509203233ull,
0x202c34316625202cull,0x2020203b34316625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x346625202c356625ull,0x203b30366625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009323132093531ull,0x33662e627573090aull,0x2c31366625092032ull,0x25202c3131662520ull,
0x202020203b373566ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c386625202c3966ull,
0x20203b3136662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093331320935ull,
0x3233662e6c756d09ull,0x202c323666250920ull,0x356625202c356625ull,0x092020202020203bull,
0x6c756d090a202f2full,0x662509203233662eull,0x2c396625202c3131ull,0x2020203b39662520ull,
0x0a202f2f09202020ull,0x3233662e64646109ull,0x202c333666250920ull,0x6625202c31316625ull,
0x09202020203b3236ull,0x766f6d090a202f2full,0x662509203233662eull,0x30346630202c3436ull,
0x203b303030303038ull,0x34202f2f09202020ull,0x672e70746573090aull,0x2509203233662e74ull,
0x366625202c323170ull,0x3b34366625202c33ull,0x2140090a202f2f09ull,0x6172622032317025ull,
0x5f325f744c240920ull,0x20203b3632363632ull,0x202f2f0920202020ull,0x33732e627573090aull,
0x2c37317225092032ull,0x31202c3631722520ull,0x2020202020203b31ull,0x7262090a202f2f09ull,
0x240920696e752e61ull,0x3835325f325f744cull,0x202020202020203bull,0x202f2f0920202020ull,
0x325f325f744c240aull,0x2f200a3a36323636ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,
0x315f325f744c2420ull,0x6c2e090a38333334ull,0x313209353109636full,0x6c756d090a300939ull,
0x662509203233662eull,0x2c356625202c3431ull,0x2020203b39662520ull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x202c353666250920ull,0x6625202c34316625ull,0x09202020203b3431ull,
0x646461090a202f2full,0x662509203233662eull,0x202c346625202c35ull,0x2020203b35366625ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300930323209ull,0x203233662e627573ull,
0x25202c3636662509ull,0x366625202c313166ull,0x2f09202020203b32ull,0x2e646461090a202full,
0x3966250920323366ull,0x25202c386625202cull,0x202020203b363666ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6d090a3009313232ull,0x09203233662e6c75ull,0x6625202c37366625ull,
0x203b356625202c35ull,0x2f2f092020202020ull,0x662e6c756d090a20ull,0x3131662509203233ull,
0x25202c396625202cull,0x20202020203b3966ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x6625202c38366625ull,0x37366625202c3131ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,
0x3936662509203233ull,0x303830346630202cull,0x2020203b30303030ull,0x090a34202f2f0920ull,
0x2e74672e70746573ull,0x3170250920323366ull,0x2c38366625202c33ull,0x2f093b3936662520ull,
0x70252140090a202full,0x0920617262203331ull,0x37325f325f744c24ull,0x202020203b383331ull,
0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3731722509ull,0x3b3231202c363172ull,
0x2f09202020202020ull,0x2e617262090a202full,0x744c240920696e75ull,0x203b3835325f325full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3137325f325f744cull,0x3c2f2f200a3a3833ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x36393220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3334315f325f744cull,0x636f6c2e090a3833ull,
0x0937323209353109ull,0x662e6c756d090a30ull,0x3431662509203233ull,0x25202c356625202cull,
0x20202020203b3966ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c30376625ull,
0x34316625202c3431ull,0x2f2f09202020203bull,0x662e646461090a20ull,0x2c35662509203233ull,
0x6625202c34662520ull,0x20202020203b3037ull,0x2e090a202f2f0920ull,0x3209353109636f6cull,
0x7573090a30093832ull,0x2509203233662e62ull,0x316625202c313766ull,0x3b37366625202c31ull,
0x202f2f0920202020ull,0x33662e646461090aull,0x202c396625092032ull,0x376625202c386625ull,
0x2020202020203b31ull,0x6c2e090a202f2f09ull,0x323209353109636full,0x6c756d090a300939ull,
0x662509203233662eull,0x2c356625202c3237ull,0x2020203b35662520ull,0x0a202f2f09202020ull,
0x3233662e6c756d09ull,0x202c313166250920ull,0x396625202c396625ull,0x092020202020203bull,
0x646461090a202f2full,0x662509203233662eull,0x31316625202c3337ull,0x203b32376625202cull,
0x0a202f2f09202020ull,0x3233662e766f6d09ull,0x202c343766250920ull,0x3030303830346630ull,
0x09202020203b3030ull,0x6573090a34202f2full,0x33662e74672e7074ull,0x2c34317025092032ull,
0x25202c3337662520ull,0x202f2f093b343766ull,0x343170252140090aull,0x4c24092061726220ull,
0x353637325f325f74ull,0x2020202020203b30ull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x317225202c373172ull,0x20203b3331202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,
0x325f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x30353637325f325full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38333334315f325full,0x3109636f6c2e090aull,0x0a30093533320935ull,0x3233662e6c756d09ull,
0x202c343166250920ull,0x396625202c356625ull,0x092020202020203bull,0x646461090a202f2full,
0x662509203233662eull,0x34316625202c3537ull,0x203b34316625202cull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x25202c3566250920ull,0x35376625202c3466ull,0x092020202020203bull,
0x6f6c2e090a202f2full,0x3633320935310963ull,0x2e627573090a3009ull,0x3766250920323366ull,
0x2c31316625202c36ull,0x20203b3237662520ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x6625202c39662509ull,0x3b36376625202c38ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0937333209353109ull,0x662e6c756d090a30ull,0x3737662509203233ull,0x25202c356625202cull,
0x20202020203b3566ull,0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x6625202c31316625ull,
0x203b396625202c39ull,0x2f2f092020202020ull,0x662e646461090a20ull,0x3837662509203233ull,
0x202c31316625202cull,0x2020203b37376625ull,0x6d090a202f2f0920ull,0x09203233662e766full,
0x6630202c39376625ull,0x3030303030383034ull,0x2f2f09202020203bull,0x70746573090a3420ull,
0x203233662e74672eull,0x25202c3531702509ull,0x376625202c383766ull,0x090a202f2f093b39ull,
0x6220353170252140ull,0x5f744c2409206172ull,0x3b32363138325f32ull,0x2f09202020202020ull,
0x2e627573090a202full,0x3172250920323373ull,0x2c36317225202c37ull,0x202020203b343120ull,
0x090a202f2f092020ull,0x20696e752e617262ull,0x325f325f744c2409ull,0x20202020203b3835ull,
0x2f09202020202020ull,0x325f744c240a202full,0x0a3a32363138325full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36393220ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a38333334315full,0x09353109636f6c2eull,
0x6d090a3009333432ull,0x09203233662e6c75ull,0x6625202c34316625ull,0x203b396625202c35ull,
0x2f2f092020202020ull,0x662e646461090a20ull,0x3038662509203233ull,0x202c34316625202cull,
0x2020203b34316625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x346625202c356625ull,
0x203b30386625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009343432093531ull,
0x33662e627573090aull,0x2c31386625092032ull,0x25202c3131662520ull,0x202020203b373766ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c386625202c3966ull,0x20203b3138662520ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093534320935ull,0x3233662e6c756d09ull,
0x202c323866250920ull,0x356625202c356625ull,0x092020202020203bull,0x6c756d090a202f2full,
0x662509203233662eull,0x2c396625202c3131ull,0x2020203b39662520ull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x202c333866250920ull,0x6625202c31316625ull,0x09202020203b3238ull,
0x766f6d090a202f2full,0x662509203233662eull,0x30346630202c3438ull,0x203b303030303038ull,
0x34202f2f09202020ull,0x672e70746573090aull,0x2509203233662e74ull,0x386625202c363170ull,
0x3b34386625202c33ull,0x2140090a202f2f09ull,0x6172622036317025ull,0x5f325f744c240920ull,
0x20203b3437363832ull,0x202f2f0920202020ull,0x33732e627573090aull,0x2c37317225092032ull,
0x31202c3631722520ull,0x2020202020203b35ull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3835325f325f744cull,0x202020202020203bull,0x202f2f0920202020ull,0x325f325f744c240aull,
0x2f200a3a34373638ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,0x315f325f744c2420ull,
0x6c2e090a38333334ull,0x353209353109636full,0x6c756d090a300931ull,0x662509203233662eull,
0x2c356625202c3431ull,0x2020203b39662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x202c353866250920ull,0x6625202c34316625ull,0x09202020203b3431ull,0x646461090a202f2full,
0x662509203233662eull,0x202c346625202c35ull,0x2020203b35386625ull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300932353209ull,0x203233662e627573ull,0x25202c3638662509ull,
0x386625202c313166ull,0x2f09202020203b32ull,0x2e646461090a202full,0x3966250920323366ull,
0x25202c386625202cull,0x202020203b363866ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6d090a3009333532ull,0x09203233662e6c75ull,0x6625202c37386625ull,0x203b356625202c35ull,
0x2f2f092020202020ull,0x662e6c756d090a20ull,0x3131662509203233ull,0x25202c396625202cull,
0x20202020203b3966ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c38386625ull,
0x37386625202c3131ull,0x2f2f09202020203bull,0x662e766f6d090a20ull,0x3938662509203233ull,
0x303830346630202cull,0x2020203b30303030ull,0x090a34202f2f0920ull,0x2e74672e70746573ull,
0x3170250920323366ull,0x2c38386625202c37ull,0x2f093b3938662520ull,0x70252140090a202full,
0x0920617262203731ull,0x39325f325f744c24ull,0x202020203b363831ull,0x090a202f2f092020ull,
0x203233732e627573ull,0x25202c3731722509ull,0x3b3631202c363172ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x203b3835325f325full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3139325f325f744cull,0x3c2f2f200a3a3638ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x36393220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3334315f325f744cull,0x636f6c2e090a3833ull,0x0939353209353109ull,
0x662e6c756d090a30ull,0x3431662509203233ull,0x25202c356625202cull,0x20202020203b3966ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x6625202c30396625ull,0x34316625202c3431ull,
0x2f2f09202020203bull,0x662e646461090a20ull,0x2c35662509203233ull,0x6625202c34662520ull,
0x20202020203b3039ull,0x2e090a202f2f0920ull,0x3209353109636f6cull,0x7573090a30093036ull,
0x2509203233662e62ull,0x316625202c313966ull,0x3b37386625202c31ull,0x202f2f0920202020ull,
0x33662e646461090aull,0x202c396625092032ull,0x396625202c386625ull,0x2020202020203b31ull,
0x6c2e090a202f2f09ull,0x363209353109636full,0x6c756d090a300931ull,0x662509203233662eull,
0x2c356625202c3239ull,0x2020203b35662520ull,0x0a202f2f09202020ull,0x3233662e6c756d09ull,
0x202c313166250920ull,0x396625202c396625ull,0x092020202020203bull,0x646461090a202f2full,
0x662509203233662eull,0x31316625202c3339ull,0x203b32396625202cull,0x0a202f2f09202020ull,
0x3233662e766f6d09ull,0x202c343966250920ull,0x3030303830346630ull,0x09202020203b3030ull,
0x6573090a34202f2full,0x33662e74672e7074ull,0x2c38317025092032ull,0x25202c3339662520ull,
0x202f2f093b343966ull,0x383170252140090aull,0x4c24092061726220ull,0x393639325f325f74ull,
0x2020202020203b38ull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c373172ull,
0x20203b3731202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x325f744c24092069ull,
0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,0x38393639325f325full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38333334315f325full,
0x3109636f6c2e090aull,0x0a30093736320935ull,0x3233662e6c756d09ull,0x202c343166250920ull,
0x396625202c356625ull,0x092020202020203bull,0x646461090a202f2full,0x662509203233662eull,
0x34316625202c3539ull,0x203b34316625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x25202c3566250920ull,0x35396625202c3466ull,0x092020202020203bull,0x6f6c2e090a202f2full,
0x3836320935310963ull,0x2e627573090a3009ull,0x3966250920323366ull,0x2c31316625202c36ull,
0x20203b3239662520ull,0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c39662509ull,
0x3b36396625202c38ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0939363209353109ull,
0x662e6c756d090a30ull,0x3739662509203233ull,0x25202c356625202cull,0x20202020203b3566ull,
0x6d090a202f2f0920ull,0x09203233662e6c75ull,0x6625202c31316625ull,0x203b396625202c39ull,
0x2f2f092020202020ull,0x662e646461090a20ull,0x3839662509203233ull,0x202c31316625202cull,
0x2020203b37396625ull,0x6d090a202f2f0920ull,0x09203233662e766full,0x6630202c39396625ull,
0x3030303030383034ull,0x2f2f09202020203bull,0x70746573090a3420ull,0x203233662e74672eull,
0x25202c3931702509ull,0x396625202c383966ull,0x090a202f2f093b39ull,0x6220393170252140ull,
0x5f744c2409206172ull,0x3b30313230335f32ull,0x2f09202020202020ull,0x2e627573090a202full,
0x3172250920323373ull,0x2c36317225202c37ull,0x202020203b383120ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x325f325f744c2409ull,0x20202020203b3835ull,0x2f09202020202020ull,
0x325f744c240a202full,0x0a3a30313230335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36393220ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a38333334315full,0x09353109636f6c2eull,0x6d090a3009353732ull,
0x09203233662e6c75ull,0x6625202c34316625ull,0x203b396625202c35ull,0x2f2f092020202020ull,
0x662e646461090a20ull,0x3031662509203233ull,0x2c34316625202c30ull,0x20203b3431662520ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x346625202c356625ull,0x3b3030316625202cull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009363732093531ull,0x33662e627573090aull,
0x3130316625092032ull,0x202c31316625202cull,0x2020203b37396625ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x2c386625202c3966ull,0x203b313031662520ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093737320935ull,0x3233662e6c756d09ull,0x2c32303166250920ull,
0x6625202c35662520ull,0x0920202020203b35ull,0x6c756d090a202f2full,0x662509203233662eull,
0x2c396625202c3131ull,0x2020203b39662520ull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x2c33303166250920ull,0x25202c3131662520ull,0x0920203b32303166ull,0x766f6d090a202f2full,
0x662509203233662eull,0x346630202c343031ull,0x3b30303030303830ull,0x34202f2f09202020ull,
0x672e70746573090aull,0x2509203233662e74ull,0x316625202c303270ull,0x30316625202c3330ull,
0x090a202f2f093b34ull,0x6220303270252140ull,0x5f744c2409206172ull,0x3b32323730335f32ull,
0x2f09202020202020ull,0x2e627573090a202full,0x3172250920323373ull,0x2c36317225202c37ull,
0x202020203b393120ull,0x090a202f2f092020ull,0x20696e752e617262ull,0x325f325f744c2409ull,
0x20202020203b3835ull,0x2f09202020202020ull,0x325f744c240a202full,0x0a3a32323730335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36393220ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a38333334315full,
0x09353109636f6c2eull,0x6d090a3009333832ull,0x09203233662e6c75ull,0x6625202c34316625ull,
0x203b396625202c35ull,0x2f2f092020202020ull,0x662e646461090a20ull,0x3031662509203233ull,
0x2c34316625202c35ull,0x20203b3431662520ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x346625202c356625ull,0x3b3530316625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009343832093531ull,0x33662e627573090aull,0x3630316625092032ull,0x202c31316625202cull,
0x20203b3230316625ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c386625202c3966ull,
0x203b363031662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093538320935ull,
0x3233662e6c756d09ull,0x2c37303166250920ull,0x6625202c35662520ull,0x0920202020203b35ull,
0x6f6c2e090a202f2full,0x3938320935310963ull,0x2e627573090a3009ull,0x3172250920323373ull,
0x2c36317225202c36ull,0x202020203b303220ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6d090a3009333832ull,0x09203233752e766full,0x3b30202c38317225ull,0x2020202020202020ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e656cull,0x7225202c31327025ull,
0x38317225202c3631ull,0x40090a202f2f093bull,0x6172622031327025ull,0x325f325f4c240920ull,
0x2020203b38333730ull,0x2f2f092020202020ull,0x6f6c3c2f2f200a20ull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x38333334315f325full,0x33662e6c756d090aull,0x2c31316625092032ull,
0x6625202c39662520ull,0x2020202020203b39ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x6625202c38303166ull,0x30316625202c3131ull,0x202f2f0920203b37ull,0x33662e766f6d090aull,
0x3930316625092032ull,0x303830346630202cull,0x2020203b30303030ull,0x73090a34202f2f09ull,
0x662e74672e707465ull,0x3232702509203233ull,0x2c3830316625202cull,0x093b393031662520ull,
0x252140090a202f2full,0x2061726220323270ull,0x30325f325f4c2409ull,0x202020203b323834ull,
0x0a202f2f09202020ull,0x3730325f325f4c24ull,0x766f6d090a3a3833ull,0x722509203233732eull,
0x36317225202c3731ull,0x202020202020203bull,0x0a202f2f09202020ull,0x696e752e61726209ull,
0x5f325f744c240920ull,0x202020203b383532ull,0x0920202020202020ull,0x325f4c240a202f2full,
0x0a3a32383430325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c36393220ull,0x6c6562616c206461ull,0x325f744c24206465ull,
0x090a38333334315full,0x09353109636f6c2eull,0x6d090a3009323932ull,0x09203233662e6c75ull,
0x6625202c34316625ull,0x203b396625202c35ull,0x2f2f092020202020ull,0x662e646461090a20ull,
0x3131662509203233ull,0x2c34316625202c30ull,0x20203b3431662520ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x346625202c356625ull,0x3b3031316625202cull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009333932093531ull,0x33662e627573090aull,0x3131316625092032ull,
0x202c31316625202cull,0x20203b3730316625ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x2c386625202c3966ull,0x203b313131662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093239320935ull,0x696e752e61726209ull,0x5f325f744c240920ull,0x20203b3833333431ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x090a3a3835325f32ull,0x09363109636f6c2eull,
0x6f6d090a30093931ull,0x2509203233732e76ull,0x203b30202c393172ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x672e70746573090aull,0x2509203233732e74ull,0x317225202c333270ull,
0x3b39317225202c37ull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c303272ull,
0x3b37317225202c35ull,0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c31327225092032ull,
0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x09203233732e706cull,
0x7225202c32327225ull,0x31327225202c3032ull,0x093b33327025202cull,0x766f6d090a202f2full,
0x722509203233752eull,0x20203b30202c3332ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x71652e7074657309ull,0x702509203233732eull,0x32327225202c3432ull,0x093b33327225202cull,
0x702540090a202f2full,0x0920617262203432ull,0x31335f325f744c24ull,0x202020203b303934ull,
0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x6c090a3009363209ull,0x2e6d617261702e64ull,
0x3272250920323373ull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,
0x735f30746f72626cull,0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,
0x5f69695f30535f32ull,0x6f6974616d696e61ull,0x3b5d656d6172466eull,0x353a6469202f2f09ull,
0x6475635f5f203731ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x615f69695f30535full,
0x6e6f6974616d696eull,0x78302b656d617246ull,0x732e646461090a30ull,0x3532722509203233ull,
0x202c34327225202cull,0x2020203b32327225ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,
0x3632722509203875ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,
0x6d735f30746f7262ull,0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x635f69695f30535full,0x5d302b73726f6c6full,0x3a6469202f2f093bull,0x75635f5f20383135ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x302b73726f6c6f63ull,
0x2e6c756d090a3078ull,0x09203233732e6f6cull,0x7225202c37327225ull,0x36327225202c3532ull,
0x090a202f2f09203bull,0x752e38752e747663ull,0x3832722509203233ull,0x203b37327225202cull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x3009373209363109ull,0x7261702e646c090aull,
0x25092038752e6d61ull,0x5f5f5b202c393272ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x30746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x73726f6c6f635f69ull,0x202f2f093b5d312bull,0x5f203931353a6469ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x726f6c6f635f6969ull,
0x6d090a3178302b73ull,0x33732e6f6c2e6c75ull,0x2c30337225092032ull,0x25202c3532722520ull,
0x2f2f09203b393272ull,0x752e747663090a20ull,0x2509203233752e38ull,0x337225202c313372ull,
0x2020202020203b30ull,0x2e090a202f2f0920ull,0x3209363109636f6cull,0x2e646c090a300938ull,
0x38752e6d61726170ull,0x202c323372250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,
0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456649ull,0x5469696934726168ull,
0x535f32535f32535full,0x6c6f635f69695f30ull,0x093b5d322b73726full,0x32353a6469202f2full,
0x616475635f5f2030ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f30746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x6f635f69695f3053ull,
0x3278302b73726f6cull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x35327225202c3333ull,
0x203b32337225202cull,0x7663090a202f2f09ull,0x3233752e38752e74ull,0x202c343372250920ull,
0x2020203b33337225ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x325f744c24092069ull,
0x203b34333231335full,0x2020202020202020ull,0x744c240a202f2f09ull,0x30393431335f325full,
0x09636f6c2e090a3aull,0x0a30093233093631ull,0x3233752e766f6d09ull,0x202c343372250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233752eull,
0x20203b30202c3133ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x3233752e766f6d09ull,
0x202c383272250920ull,0x2020202020203b30ull,0x0920202020202020ull,0x5f744c240a202f2full,
0x3a34333231335f32ull,0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c31647225ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x3b5d7473645f6969ull,
0x353a6469202f2f09ull,0x6475635f5f203132ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,
0x6d735f30746f7262ull,0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x645f69695f30535full,0x090a3078302b7473ull,0x732e6f6c2e6c756dull,0x3533722509203233ull,
0x25202c377225202cull,0x2f092020203b3672ull,0x2e646461090a202full,0x3372250920323373ull,
0x202c347225202c36ull,0x2020203b35337225ull,0x090a202f2f092020ull,0x2e3436752e747663ull,
0x6472250920323373ull,0x3b36337225202c32ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x09203436752e6f6cull,0x7225202c33647225ull,0x20203b34202c3264ull,0x090a202f2f092020ull,
0x203436752e646461ull,0x25202c3464722509ull,0x647225202c316472ull,0x2f09202020203b33ull,
0x702e646c090a202full,0x3233732e6d617261ull,0x202c373372250920ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x6172665f69695f30ull,0x202f2f093b5d656dull,
0x5f203130353a6469ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x656d6172665f6969ull,0x6f6d090a3078302bull,0x2509203233752e76ull,0x203b30202c383372ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x337225202c353270ull,0x3b38337225202c37ull,0x2540090a202f2f09ull,0x2061726220353270ull,
0x335f325f744c2409ull,0x2020203b32303032ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x090a300939330936ull,0x203233752e766f6dull,0x30202c3933722509ull,0x202020202020203bull,
0x2f09202020202020ull,0x672e7473090a202full,0x34762e6c61626f6cull,0x72255b092038752eull,
0x7b202c5d302b3464ull,0x3372252c38327225ull,0x252c343372252c31ull,0x2f2f093b7d393372ull,
0x752e617262090a20ull,0x5f744c240920696eull,0x3b36343731335f32ull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x303032335f325f74ull,0x636f6c2e090a3a32ull,0x3009333409363109ull,
0x33732e646461090aull,0x2c30347225092032ull,0x31202c3733722520ull,0x202020202020203bull,
0x6873090a202f2f09ull,0x2509203233732e72ull,0x347225202c313472ull,0x20203b3133202c30ull,
0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c32347225092032ull,0x20202020203b3120ull,
0x2020202020202020ull,0x6e61090a202f2f09ull,0x2509203233622e64ull,0x347225202c333472ull,
0x3b32347225202c31ull,0x202f2f0920202020ull,0x33732e646461090aull,0x2c34347225092032ull,
0x25202c3334722520ull,0x202020203b303472ull,0x6873090a202f2f09ull,0x2509203233732e72ull,
0x347225202c353472ull,0x2020203b31202c34ull,0x202f2f0920202020ull,0x6f6c672e646c090aull,
0x752e34762e6c6162ull,0x363472257b092038ull,0x72252c373472252cull,0x5b202c7d5f2c3834ull,
0x3b5d302b34647225ull,0x756d090a202f2f09ull,0x3233732e6f6c2e6cull,0x202c393472250920ull,
0x7225202c37337225ull,0x202f2f09203b3634ull,0x33732e646461090aull,0x2c30357225092032ull,
0x25202c3832722520ull,0x202020203b393472ull,0x6461090a202f2f09ull,0x2509203233732e64ull,
0x347225202c313572ull,0x3b30357225202c35ull,0x202f2f0920202020ull,0x33732e766964090aull,
0x2c32357225092032ull,0x25202c3135722520ull,0x202020203b303472ull,0x6c2e090a202f2f09ull,
0x343409363109636full,0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x7225202c33357225ull,
0x37347225202c3733ull,0x090a202f2f09203bull,0x203233732e646461ull,0x25202c3435722509ull,
0x357225202c313372ull,0x2f09202020203b33ull,0x2e646461090a202full,0x3572250920323373ull,
0x2c35347225202c35ull,0x20203b3435722520ull,0x090a202f2f092020ull,0x203233732e766964ull,
0x25202c3635722509ull,0x347225202c353572ull,0x2f09202020203b30ull,0x672e7473090a202full,
0x32762e6c61626f6cull,0x72255b092038752eull,0x7b202c5d302b3464ull,0x3572252c32357225ull,
0x0a202f2f093b7d36ull,0x363109636f6c2e09ull,0x6d090a3009353409ull,0x33732e6f6c2e6c75ull,
0x2c37357225092032ull,0x25202c3733722520ull,0x2f2f09203b383472ull,0x732e646461090a20ull,
0x3835722509203233ull,0x202c34337225202cull,0x2020203b37357225ull,0x61090a202f2f0920ull,
0x09203233732e6464ull,0x7225202c39357225ull,0x38357225202c3534ull,0x2f2f09202020203bull,
0x732e766964090a20ull,0x3036722509203233ull,0x202c39357225202cull,0x2020203b30347225ull,
0x73090a202f2f0920ull,0x6c61626f6c672e74ull,0x72255b092038752eull,0x25202c5d322b3464ull,
0x2f2f09203b303672ull,0x0a3133353a646920ull,0x31335f325f744c24ull,0x744c240a3a363437ull,
0x34393930325f325full,0x09636f6c2e090a3aull,0x0a30093834093631ull,0x20203b7469786509ull,
0x2020202020202020ull,0x2020202020202020ull,0x0920202020202020ull,0x57444c240a202f2full,
0x36315a5f5f646e65ull,0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x7d090a3a69695f30ull,0x36315a5f202f2f20ull,
0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456649ull,0x5469696934726168ull,
0x535f32535f32535full,0x2e090a0a69695f30ull,0x5a5f207972746e65ull,0x6c65646e614d3631ull,
0x6d735f30746f7262ull,0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x282069695f30535full,0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x0a2c7473645f6969ull,0x6d617261702e0909ull,
0x5f5f203233732e20ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,
0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,
0x576567616d695f69ull,0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764564ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x67616d695f69695full,0x702e09090a2c4865ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645644930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x72635f69695f3053ull,0x09090a2c68636e75ull,0x2e206d617261702eull,0x75635f5f20343666ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x09090a2c66664f78ull,
0x2e206d617261702eull,0x75635f5f20343666ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,
0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,0x535f32535f546969ull,
0x5f69695f30535f32ull,0x09090a2c66664f79ull,0x2e206d617261702eull,0x75635f5f20343666ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,0x090a2c656c616373ull,
0x206d617261702e09ull,0x34206e67696c612eull,0x635f5f2038622e20ull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x69695f30535f3253ull,0x5b73726f6c6f635full,0x702e09090a2c5d34ull,
0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645644930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x72665f69695f3053ull,0x2e09090a2c656d61ull,0x732e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x615f69695f30535full,0x6e6f6974616d696eull,
0x090a29656d617246ull,0x206765722e090a7bull,0x687225203631752eull,0x722e090a3b3e363cull,
0x203233752e206765ull,0x0a3b3e32363c7225ull,0x752e206765722e09ull,0x363c647225203436ull,
0x6765722e090a3b3eull,0x6625203436662e20ull,0x0a3b3e3331313c64ull,0x702e206765722e09ull,
0x323c702520646572ull,0x6f6c2e090a3b3e37ull,0x3009380936310963ull,0x5f5f3142424c240aull,
0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x3a69695f30535f32ull,0x31752e766f6d090aull,0x2c31687225092036ull,
0x2e64696174632520ull,0x2020202020203b78ull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,
0x746e25202c326872ull,0x2020203b782e6469ull,0x202f2f0920202020ull,0x69772e6c756d090aull,
0x09203631752e6564ull,0x687225202c317225ull,0x3b32687225202c31ull,0x6f6d090a202f2f09ull,
0x2509203631752e76ull,0x746325202c336872ull,0x20203b792e646961ull,0x202f2f0920202020ull,
0x31752e766f6d090aull,0x2c34687225092036ull,0x792e6469746e2520ull,0x202020202020203bull,
0x756d090a202f2f09ull,0x752e656469772e6cull,0x2c32722509203631ull,0x25202c3368722520ull,
0x202f2f093b346872ull,0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3372ull,
0x20202020203b782eull,0x6461090a202f2f09ull,0x2509203233752e64ull,0x2c337225202c3472ull,
0x2020203b31722520ull,0x202f2f0920202020ull,0x33752e747663090aull,0x2509203631752e32ull,
0x64697425202c3572ull,0x20202020203b792eull,0x6461090a202f2f09ull,0x2509203233752e64ull,
0x2c357225202c3672ull,0x2020203b32722520ull,0x202f2f0920202020ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5f5b202c377225ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x30746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x576567616d695f69ull,0x6469202f2f093b5dull,0x635f5f203730353aull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645644930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,0x2b576567616d695full,
0x2e646c090a307830ull,0x33732e6d61726170ull,0x202c387225092032ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x616d695f69695f30ull,0x2f2f093b5d486567ull,
0x203431353a646920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3074ull,0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x67616d695f69695full,0x090a3078302b4865ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x387225202c397225ull,0x2f093b367225202cull,0x2e67656e090a202full,0x3172250920323373ull,
0x203b397225202c30ull,0x2020202020202020ull,0x090a202f2f092020ull,0x752e74672e746573ull,
0x09203233732e3233ull,0x7225202c31317225ull,0x093b347225202c37ull,0x67656e090a202f2full,
0x722509203233732eull,0x31317225202c3231ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233622e646e6109ull,0x202c333172250920ull,0x7225202c30317225ull,0x09202020203b3231ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3431ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x2c33317225202c31ull,
0x09203b3431722520ull,0x702540090a202f2full,0x2409206172622031ull,0x3930325f335f744cull,
0x20202020203b3439ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939323109ull,
0x6d617261702e646cull,0x662509203436662eull,0x635f5f5b202c3164ull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x69695f30535f3253ull,0x3b5d656c6163735full,0x353a6469202f2f09ull,
0x6475635f5f203630ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x735f69695f30535full,
0x3078302b656c6163ull,0x7261702e646c090aull,0x09203436662e6d61ull,0x5f5b202c32646625ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x5d66664f795f6969ull,
0x3a6469202f2f093bull,0x75635f5f20353135ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,
0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,0x535f32535f546969ull,
0x5f69695f30535f32ull,0x3078302b66664f79ull,0x6e722e747663090aull,0x3233732e3436662eull,
0x202c336466250920ull,0x202020203b367225ull,0x616d090a202f2f09ull,0x3436662e6e722e64ull,
0x202c346466250920ull,0x6625202c33646625ull,0x32646625202c3164ull,0x6d090a202f2f093bull,
0x09203436662e766full,0x6625202c35646625ull,0x20202020203b3464ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009303331093531ull,0x7261702e646c090aull,0x09203436662e6d61ull,
0x5f5b202c36646625ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x5d66664f785f6969ull,0x3a6469202f2f093bull,0x75635f5f20363135ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f69695f30535f32ull,0x3078302b66664f78ull,0x6e722e747663090aull,
0x3233732e3436662eull,0x202c376466250920ull,0x202020203b347225ull,0x616d090a202f2f09ull,
0x3436662e6e722e64ull,0x202c386466250920ull,0x6625202c37646625ull,0x36646625202c3164ull,
0x6d090a202f2f093bull,0x09203436662e766full,0x6625202c39646625ull,0x20202020203b3864ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009333331093531ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5b202c35317225ull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f30535f32535f32ull,0x636e7572635f6969ull,0x69202f2f093b5d68ull,0x5f5f203530353a64ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,0x45644930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,0x68636e7572635f69ull,
0x6f6d090a3078302bull,0x2509203233732e76ull,0x317225202c363172ull,0x2020202020203b35ull,
0x202f2f0920202020ull,0x315f335f744c240aull,0x2f200a3a38333334ull,0x203e706f6f6c3c2full,
0x646f6220706f6f4cull,0x3220656e696c2079ull,0x636f6c2e090a3639ull,0x0936393209353109ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x2c35646625202c30ull,0x20203b3564662520ull,
0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3131646625ull,0x646625202c396466ull,
0x2f2f092020203b39ull,0x662e646461090a20ull,0x3164662509203436ull,0x3131646625202c32ull,
0x3b3031646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,0x30202c3331646625ull,
0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,
0x702509203436662eull,0x3231646625202c32ull,0x3b3331646625202cull,0x2140090a202f2f09ull,
0x2061726220327025ull,0x325f335f744c2409ull,0x2020203b36303531ull,0x202f2f0920202020ull,
0x33732e627573090aull,0x2c37317225092032ull,0x31202c3631722520ull,0x202020202020203bull,
0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f335f744cull,0x202020202020203bull,
0x202f2f0920202020ull,0x325f335f744c240aull,0x2f200a3a36303531ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,
0x64656c6562616c20ull,0x315f335f744c2420ull,0x6c2e090a38333334ull,0x333109353109636full,
0x6c756d090a300939ull,0x662509203436662eull,0x646625202c343164ull,0x3b39646625202c35ull,
0x0a202f2f09202020ull,0x3436662e64646109ull,0x2c35316466250920ull,0x202c343164662520ull,
0x09203b3431646625ull,0x646461090a202f2full,0x662509203436662eull,0x34646625202c3564ull,
0x3b3531646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300930343109ull,
0x203436662e627573ull,0x202c363164662509ull,0x25202c3131646625ull,0x2f09203b30316466ull,
0x2e646461090a202full,0x6466250920343666ull,0x2c38646625202c39ull,0x203b363164662520ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009313431ull,0x09203436662e6c75ull,
0x25202c3731646625ull,0x646625202c356466ull,0x2f2f092020203b35ull,0x662e6c756d090a20ull,
0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x25202c3831646625ull,0x6625202c31316466ull,0x2f2f09203b373164ull,
0x662e766f6d090a20ull,0x3164662509203436ull,0x3130346430202c39ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,0x25202c3370250920ull,
0x6625202c38316466ull,0x202f2f093b393164ull,0x203370252140090aull,0x744c240920617262ull,
0x38313032325f335full,0x202020202020203bull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x317225202c373172ull,0x2020203b32202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,
0x335f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x38313032325f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38333334315f335full,0x3109636f6c2e090aull,0x0a30093734310935ull,0x3436662e6c756d09ull,
0x2c34316466250920ull,0x25202c3564662520ull,0x092020203b396466ull,0x646461090a202f2full,
0x662509203436662eull,0x646625202c303264ull,0x31646625202c3431ull,0x0a202f2f09203b34ull,
0x3436662e64646109ull,0x202c356466250920ull,0x6625202c34646625ull,0x092020203b303264ull,
0x6f6c2e090a202f2full,0x3834310935310963ull,0x2e627573090a3009ull,0x6466250920343666ull,
0x31646625202c3132ull,0x3731646625202c31ull,0x090a202f2f09203bull,0x203436662e646461ull,
0x25202c3964662509ull,0x646625202c386466ull,0x2f092020203b3132ull,0x636f6c2e090a202full,
0x0939343109353109ull,0x662e6c756d090a30ull,0x3264662509203436ull,0x2c35646625202c32ull,
0x20203b3564662520ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3131646625ull,
0x646625202c396466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,0x3264662509203436ull,
0x3131646625202c33ull,0x3b3232646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3432646625ull,0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,
0x74672e7074657309ull,0x702509203436662eull,0x3332646625202c34ull,0x3b3432646625202cull,
0x2140090a202f2f09ull,0x2061726220347025ull,0x325f335f744c2409ull,0x2020203b30333532ull,
0x202f2f0920202020ull,0x33732e627573090aull,0x2c37317225092032ull,0x33202c3631722520ull,
0x202020202020203bull,0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f335f744cull,
0x202020202020203bull,0x202f2f0920202020ull,0x325f335f744c240aull,0x2f200a3a30333532ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3639ull,0x64656c6562616c20ull,0x315f335f744c2420ull,0x6c2e090a38333334ull,
0x353109353109636full,0x6c756d090a300935ull,0x662509203436662eull,0x646625202c343164ull,
0x3b39646625202c35ull,0x0a202f2f09202020ull,0x3436662e64646109ull,0x2c35326466250920ull,
0x202c343164662520ull,0x09203b3431646625ull,0x646461090a202f2full,0x662509203436662eull,
0x34646625202c3564ull,0x3b3532646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300936353109ull,0x203436662e627573ull,0x202c363264662509ull,0x25202c3131646625ull,
0x2f09203b32326466ull,0x2e646461090a202full,0x6466250920343666ull,0x2c38646625202c39ull,
0x203b363264662520ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009373531ull,
0x09203436662e6c75ull,0x25202c3732646625ull,0x646625202c356466ull,0x2f2f092020203b35ull,
0x662e6c756d090a20ull,0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3832646625ull,0x6625202c31316466ull,
0x2f2f09203b373264ull,0x662e766f6d090a20ull,0x3264662509203436ull,0x3130346430202c39ull,
0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,
0x25202c3570250920ull,0x6625202c38326466ull,0x202f2f093b393264ull,0x203570252140090aull,
0x744c240920617262ull,0x32343033325f335full,0x202020202020203bull,0x7573090a202f2f09ull,
0x2509203233732e62ull,0x317225202c373172ull,0x2020203b34202c36ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x335f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x32343033325f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x38333334315f335full,0x3109636f6c2e090aull,0x0a30093336310935ull,
0x3436662e6c756d09ull,0x2c34316466250920ull,0x25202c3564662520ull,0x092020203b396466ull,
0x646461090a202f2full,0x662509203436662eull,0x646625202c303364ull,0x31646625202c3431ull,
0x0a202f2f09203b34ull,0x3436662e64646109ull,0x202c356466250920ull,0x6625202c34646625ull,
0x092020203b303364ull,0x6f6c2e090a202f2full,0x3436310935310963ull,0x2e627573090a3009ull,
0x6466250920343666ull,0x31646625202c3133ull,0x3732646625202c31ull,0x090a202f2f09203bull,
0x203436662e646461ull,0x25202c3964662509ull,0x646625202c386466ull,0x2f092020203b3133ull,
0x636f6c2e090a202full,0x0935363109353109ull,0x662e6c756d090a30ull,0x3364662509203436ull,
0x2c35646625202c32ull,0x20203b3564662520ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,
0x25202c3131646625ull,0x646625202c396466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,
0x3364662509203436ull,0x3131646625202c33ull,0x3b3233646625202cull,0x6d090a202f2f0920ull,
0x09203436662e766full,0x30202c3433646625ull,0x3030303031303464ull,0x3030303030303030ull,
0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,0x3333646625202c36ull,
0x3b3433646625202cull,0x2140090a202f2f09ull,0x2061726220367025ull,0x325f335f744c2409ull,
0x2020203b34353533ull,0x202f2f0920202020ull,0x33732e627573090aull,0x2c37317225092032ull,
0x35202c3631722520ull,0x202020202020203bull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3835325f335f744cull,0x202020202020203bull,0x202f2f0920202020ull,0x325f335f744c240aull,
0x2f200a3a34353533ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,0x315f335f744c2420ull,
0x6c2e090a38333334ull,0x373109353109636full,0x6c756d090a300931ull,0x662509203436662eull,
0x646625202c343164ull,0x3b39646625202c35ull,0x0a202f2f09202020ull,0x3436662e64646109ull,
0x2c35336466250920ull,0x202c343164662520ull,0x09203b3431646625ull,0x646461090a202f2full,
0x662509203436662eull,0x34646625202c3564ull,0x3b3533646625202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300932373109ull,0x203436662e627573ull,0x202c363364662509ull,
0x25202c3131646625ull,0x2f09203b32336466ull,0x2e646461090a202full,0x6466250920343666ull,
0x2c38646625202c39ull,0x203b363364662520ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6d090a3009333731ull,0x09203436662e6c75ull,0x25202c3733646625ull,0x646625202c356466ull,
0x2f2f092020203b35ull,0x662e6c756d090a20ull,0x3164662509203436ull,0x2c39646625202c31ull,
0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3833646625ull,
0x6625202c31316466ull,0x2f2f09203b373364ull,0x662e766f6d090a20ull,0x3364662509203436ull,
0x3130346430202c39ull,0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a34202full,
0x3436662e74672e70ull,0x25202c3770250920ull,0x6625202c38336466ull,0x202f2f093b393364ull,
0x203770252140090aull,0x744c240920617262ull,0x36363034325f335full,0x202020202020203bull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c373172ull,0x2020203b36202c36ull,
0x202f2f0920202020ull,0x6e752e617262090aull,0x335f744c24092069ull,0x2020203b3835325full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x36363034325f335full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x38333334315f335full,0x3109636f6c2e090aull,
0x0a30093937310935ull,0x3436662e6c756d09ull,0x2c34316466250920ull,0x25202c3564662520ull,
0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,0x646625202c303464ull,
0x31646625202c3431ull,0x0a202f2f09203b34ull,0x3436662e64646109ull,0x202c356466250920ull,
0x6625202c34646625ull,0x092020203b303464ull,0x6f6c2e090a202f2full,0x3038310935310963ull,
0x2e627573090a3009ull,0x6466250920343666ull,0x31646625202c3134ull,0x3733646625202c31ull,
0x090a202f2f09203bull,0x203436662e646461ull,0x25202c3964662509ull,0x646625202c386466ull,
0x2f092020203b3134ull,0x636f6c2e090a202full,0x0931383109353109ull,0x662e6c756d090a30ull,
0x3464662509203436ull,0x2c35646625202c32ull,0x20203b3564662520ull,0x6d090a202f2f0920ull,
0x09203436662e6c75ull,0x25202c3131646625ull,0x646625202c396466ull,0x2f2f092020203b39ull,
0x662e646461090a20ull,0x3464662509203436ull,0x3131646625202c33ull,0x3b3234646625202cull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x30202c3434646625ull,0x3030303031303464ull,
0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,
0x3334646625202c38ull,0x3b3434646625202cull,0x2140090a202f2f09ull,0x2061726220387025ull,
0x325f335f744c2409ull,0x2020203b38373534ull,0x202f2f0920202020ull,0x33732e627573090aull,
0x2c37317225092032ull,0x37202c3631722520ull,0x202020202020203bull,0x7262090a202f2f09ull,
0x240920696e752e61ull,0x3835325f335f744cull,0x202020202020203bull,0x202f2f0920202020ull,
0x325f335f744c240aull,0x2f200a3a38373534ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,
0x315f335f744c2420ull,0x6c2e090a38333334ull,0x383109353109636full,0x6c756d090a300937ull,
0x662509203436662eull,0x646625202c343164ull,0x3b39646625202c35ull,0x0a202f2f09202020ull,
0x3436662e64646109ull,0x2c35346466250920ull,0x202c343164662520ull,0x09203b3431646625ull,
0x646461090a202f2full,0x662509203436662eull,0x34646625202c3564ull,0x3b3534646625202cull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938383109ull,0x203436662e627573ull,
0x202c363464662509ull,0x25202c3131646625ull,0x2f09203b32346466ull,0x2e646461090a202full,
0x6466250920343666ull,0x2c38646625202c39ull,0x203b363464662520ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6d090a3009393831ull,0x09203436662e6c75ull,0x25202c3734646625ull,
0x646625202c356466ull,0x2f2f092020203b35ull,0x662e6c756d090a20ull,0x3164662509203436ull,
0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,
0x25202c3834646625ull,0x6625202c31316466ull,0x2f2f09203b373464ull,0x662e766f6d090a20ull,
0x3464662509203436ull,0x3130346430202c39ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x746573090a34202full,0x3436662e74672e70ull,0x25202c3970250920ull,0x6625202c38346466ull,
0x202f2f093b393464ull,0x203970252140090aull,0x744c240920617262ull,0x30393035325f335full,
0x202020202020203bull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c373172ull,
0x2020203b38202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,0x30393035325f335full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x38333334315f335full,
0x3109636f6c2e090aull,0x0a30093539310935ull,0x3436662e6c756d09ull,0x2c34316466250920ull,
0x25202c3564662520ull,0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,
0x646625202c303564ull,0x31646625202c3431ull,0x0a202f2f09203b34ull,0x3436662e64646109ull,
0x202c356466250920ull,0x6625202c34646625ull,0x092020203b303564ull,0x6f6c2e090a202f2full,
0x3639310935310963ull,0x2e627573090a3009ull,0x6466250920343666ull,0x31646625202c3135ull,
0x3734646625202c31ull,0x090a202f2f09203bull,0x203436662e646461ull,0x25202c3964662509ull,
0x646625202c386466ull,0x2f092020203b3135ull,0x636f6c2e090a202full,0x0937393109353109ull,
0x662e6c756d090a30ull,0x3564662509203436ull,0x2c35646625202c32ull,0x20203b3564662520ull,
0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3131646625ull,0x646625202c396466ull,
0x2f2f092020203b39ull,0x662e646461090a20ull,0x3564662509203436ull,0x3131646625202c33ull,
0x3b3235646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,0x30202c3435646625ull,
0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,
0x702509203436662eull,0x35646625202c3031ull,0x3435646625202c33ull,0x40090a202f2f093bull,
0x7262203031702521ull,0x335f744c24092061ull,0x203b32303635325full,0x2f2f092020202020ull,
0x732e627573090a20ull,0x3731722509203233ull,0x202c36317225202cull,0x2020202020203b39ull,
0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f335f744c24ull,0x2020202020203b38ull,
0x2f2f092020202020ull,0x5f335f744c240a20ull,0x200a3a3230363532ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363932ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3833333431ull,0x3209353109636f6cull,
0x756d090a30093330ull,0x2509203436662e6cull,0x6625202c34316466ull,0x39646625202c3564ull,
0x202f2f092020203bull,0x36662e646461090aull,0x3535646625092034ull,0x2c3431646625202cull,
0x203b343164662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x646625202c356466ull,
0x3535646625202c34ull,0x202f2f092020203bull,0x3109636f6c2e090aull,0x0a30093430320935ull,
0x3436662e62757309ull,0x2c36356466250920ull,0x202c313164662520ull,0x09203b3235646625ull,
0x646461090a202f2full,0x662509203436662eull,0x38646625202c3964ull,0x3b3635646625202cull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300935303209ull,0x203436662e6c756dull,
0x202c373564662509ull,0x6625202c35646625ull,0x2f092020203b3564ull,0x2e6c756d090a202full,
0x6466250920343666ull,0x39646625202c3131ull,0x203b39646625202cull,0x090a202f2f092020ull,
0x203436662e646461ull,0x202c383564662509ull,0x25202c3131646625ull,0x2f09203b37356466ull,
0x2e766f6d090a202full,0x6466250920343666ull,0x30346430202c3935ull,0x3030303030303031ull,
0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,0x2c31317025092034ull,
0x202c383564662520ull,0x2f093b3935646625ull,0x70252140090a202full,0x0920617262203131ull,
0x36325f335f744c24ull,0x202020203b343131ull,0x090a202f2f092020ull,0x203233732e627573ull,
0x25202c3731722509ull,0x3b3031202c363172ull,0x2f09202020202020ull,0x2e617262090a202full,
0x744c240920696e75ull,0x203b3835325f335full,0x2020202020202020ull,0x240a202f2f092020ull,
0x3136325f335f744cull,0x3c2f2f200a3a3431ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x36393220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3334315f335f744cull,0x636f6c2e090a3833ull,0x0931313209353109ull,0x662e6c756d090a30ull,
0x3164662509203436ull,0x2c35646625202c34ull,0x20203b3964662520ull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x25202c3036646625ull,0x6625202c34316466ull,0x2f2f09203b343164ull,
0x662e646461090a20ull,0x3564662509203436ull,0x202c34646625202cull,0x20203b3036646625ull,
0x2e090a202f2f0920ull,0x3209353109636f6cull,0x7573090a30093231ull,0x2509203436662e62ull,
0x6625202c31366466ull,0x646625202c313164ull,0x202f2f09203b3735ull,0x36662e646461090aull,
0x2c39646625092034ull,0x25202c3864662520ull,0x2020203b31366466ull,0x6c2e090a202f2f09ull,
0x313209353109636full,0x6c756d090a300933ull,0x662509203436662eull,0x646625202c323664ull,
0x3b35646625202c35ull,0x0a202f2f09202020ull,0x3436662e6c756d09ull,0x2c31316466250920ull,
0x25202c3964662520ull,0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,
0x646625202c333664ull,0x36646625202c3131ull,0x0a202f2f09203b32ull,0x3436662e766f6d09ull,
0x2c34366466250920ull,0x3030313034643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x2e70746573090a34ull,0x09203436662e7467ull,0x6625202c32317025ull,0x646625202c333664ull,
0x0a202f2f093b3436ull,0x2032317025214009ull,0x744c240920617262ull,0x36323636325f335full,
0x092020202020203bull,0x627573090a202f2full,0x722509203233732eull,0x36317225202c3731ull,
0x2020203b3131202cull,0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f335f744c240920ull,
0x202020203b383532ull,0x0920202020202020ull,0x5f744c240a202f2full,0x3a36323636325f33ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3639322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a38333334315f33ull,
0x353109636f6c2e09ull,0x090a300939313209ull,0x203436662e6c756dull,0x202c343164662509ull,
0x6625202c35646625ull,0x2f092020203b3964ull,0x2e646461090a202full,0x6466250920343666ull,
0x31646625202c3536ull,0x3431646625202c34ull,0x090a202f2f09203bull,0x203436662e646461ull,
0x25202c3564662509ull,0x646625202c346466ull,0x2f092020203b3536ull,0x636f6c2e090a202full,
0x0930323209353109ull,0x662e627573090a30ull,0x3664662509203436ull,0x3131646625202c36ull,
0x3b3236646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x6625202c39646625ull,
0x36646625202c3864ull,0x2f2f092020203b36ull,0x09636f6c2e090a20ull,0x3009313232093531ull,
0x36662e6c756d090aull,0x3736646625092034ull,0x202c35646625202cull,0x2020203b35646625ull,
0x756d090a202f2f09ull,0x2509203436662e6cull,0x6625202c31316466ull,0x39646625202c3964ull,
0x202f2f092020203bull,0x36662e646461090aull,0x3836646625092034ull,0x2c3131646625202cull,
0x203b373664662520ull,0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x6430202c39366466ull,
0x3030303030313034ull,0x3030303030303030ull,0x090a34202f2f093bull,0x2e74672e70746573ull,
0x3170250920343666ull,0x3836646625202c33ull,0x3b3936646625202cull,0x2140090a202f2f09ull,
0x6172622033317025ull,0x5f335f744c240920ull,0x20203b3833313732ull,0x202f2f0920202020ull,
0x33732e627573090aull,0x2c37317225092032ull,0x31202c3631722520ull,0x2020202020203b32ull,
0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f335f744cull,0x202020202020203bull,
0x202f2f0920202020ull,0x325f335f744c240aull,0x2f200a3a38333137ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,
0x64656c6562616c20ull,0x315f335f744c2420ull,0x6c2e090a38333334ull,0x323209353109636full,
0x6c756d090a300937ull,0x662509203436662eull,0x646625202c343164ull,0x3b39646625202c35ull,
0x0a202f2f09202020ull,0x3436662e64646109ull,0x2c30376466250920ull,0x202c343164662520ull,
0x09203b3431646625ull,0x646461090a202f2full,0x662509203436662eull,0x34646625202c3564ull,
0x3b3037646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300938323209ull,
0x203436662e627573ull,0x202c313764662509ull,0x25202c3131646625ull,0x2f09203b37366466ull,
0x2e646461090a202full,0x6466250920343666ull,0x2c38646625202c39ull,0x203b313764662520ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009393232ull,0x09203436662e6c75ull,
0x25202c3237646625ull,0x646625202c356466ull,0x2f2f092020203b35ull,0x662e6c756d090a20ull,
0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x25202c3337646625ull,0x6625202c31316466ull,0x2f2f09203b323764ull,
0x662e766f6d090a20ull,0x3764662509203436ull,0x3130346430202c34ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,0x202c343170250920ull,
0x25202c3337646625ull,0x2f2f093b34376466ull,0x3170252140090a20ull,0x2409206172622034ull,
0x3637325f335f744cull,0x20202020203b3035ull,0x73090a202f2f0920ull,0x09203233732e6275ull,
0x7225202c37317225ull,0x203b3331202c3631ull,0x2f2f092020202020ull,0x752e617262090a20ull,
0x5f744c240920696eull,0x20203b3835325f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x353637325f335f74ull,0x6c3c2f2f200a3a30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c36393220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333334315f335f74ull,0x09636f6c2e090a38ull,0x3009353332093531ull,0x36662e6c756d090aull,
0x3431646625092034ull,0x202c35646625202cull,0x2020203b39646625ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x6625202c35376466ull,0x646625202c343164ull,0x202f2f09203b3431ull,
0x36662e646461090aull,0x2c35646625092034ull,0x25202c3464662520ull,0x2020203b35376466ull,
0x6c2e090a202f2f09ull,0x333209353109636full,0x627573090a300936ull,0x662509203436662eull,
0x646625202c363764ull,0x37646625202c3131ull,0x0a202f2f09203b32ull,0x3436662e64646109ull,
0x202c396466250920ull,0x6625202c38646625ull,0x092020203b363764ull,0x6f6c2e090a202f2full,
0x3733320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,0x35646625202c3737ull,
0x203b35646625202cull,0x090a202f2f092020ull,0x203436662e6c756dull,0x202c313164662509ull,
0x6625202c39646625ull,0x2f092020203b3964ull,0x2e646461090a202full,0x6466250920343666ull,
0x31646625202c3837ull,0x3737646625202c31ull,0x090a202f2f09203bull,0x203436662e766f6dull,
0x202c393764662509ull,0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,
0x672e70746573090aull,0x2509203436662e74ull,0x646625202c353170ull,0x37646625202c3837ull,
0x090a202f2f093b39ull,0x6220353170252140ull,0x5f744c2409206172ull,0x3b32363138325f33ull,
0x2f09202020202020ull,0x2e627573090a202full,0x3172250920323373ull,0x2c36317225202c37ull,
0x202020203b343120ull,0x090a202f2f092020ull,0x20696e752e617262ull,0x325f335f744c2409ull,
0x20202020203b3835ull,0x2f09202020202020ull,0x335f744c240a202full,0x0a3a32363138325full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36393220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a38333334315full,
0x09353109636f6c2eull,0x6d090a3009333432ull,0x09203436662e6c75ull,0x25202c3431646625ull,
0x646625202c356466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,0x3864662509203436ull,
0x3431646625202c30ull,0x3b3431646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,
0x6625202c35646625ull,0x38646625202c3464ull,0x2f2f092020203b30ull,0x09636f6c2e090a20ull,
0x3009343432093531ull,0x36662e627573090aull,0x3138646625092034ull,0x2c3131646625202cull,
0x203b373764662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x646625202c396466ull,
0x3138646625202c38ull,0x202f2f092020203bull,0x3109636f6c2e090aull,0x0a30093534320935ull,
0x3436662e6c756d09ull,0x2c32386466250920ull,0x25202c3564662520ull,0x092020203b356466ull,
0x6c756d090a202f2full,0x662509203436662eull,0x646625202c313164ull,0x3b39646625202c39ull,
0x0a202f2f09202020ull,0x3436662e64646109ull,0x2c33386466250920ull,0x202c313164662520ull,
0x09203b3238646625ull,0x766f6d090a202f2full,0x662509203436662eull,0x346430202c343864ull,
0x3030303030303130ull,0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3631702509203436ull,0x2c3338646625202cull,0x093b343864662520ull,0x252140090a202f2full,
0x2061726220363170ull,0x325f335f744c2409ull,0x2020203b34373638ull,0x0a202f2f09202020ull,
0x3233732e62757309ull,0x202c373172250920ull,0x3531202c36317225ull,0x092020202020203bull,
0x617262090a202f2full,0x4c240920696e752eull,0x3b3835325f335f74ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x38325f335f744c24ull,0x2f2f200a3a343736ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x393220656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x34315f335f744c24ull,0x6f6c2e090a383333ull,0x3135320935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x35646625202c3431ull,0x203b39646625202cull,
0x090a202f2f092020ull,0x203436662e646461ull,0x202c353864662509ull,0x25202c3431646625ull,
0x2f09203b34316466ull,0x2e646461090a202full,0x6466250920343666ull,0x2c34646625202c35ull,
0x203b353864662520ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009323532ull,
0x09203436662e6275ull,0x25202c3638646625ull,0x6625202c31316466ull,0x2f2f09203b323864ull,
0x662e646461090a20ull,0x3964662509203436ull,0x202c38646625202cull,0x20203b3638646625ull,
0x2e090a202f2f0920ull,0x3209353109636f6cull,0x756d090a30093335ull,0x2509203436662e6cull,
0x6625202c37386466ull,0x35646625202c3564ull,0x202f2f092020203bull,0x36662e6c756d090aull,
0x3131646625092034ull,0x202c39646625202cull,0x2020203b39646625ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x6625202c38386466ull,0x646625202c313164ull,0x202f2f09203b3738ull,
0x36662e766f6d090aull,0x3938646625092034ull,0x303130346430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x70746573090a3420ull,0x203436662e74672eull,0x25202c3731702509ull,
0x6625202c38386466ull,0x202f2f093b393864ull,0x373170252140090aull,0x4c24092061726220ull,
0x383139325f335f74ull,0x2020202020203b36ull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x317225202c373172ull,0x20203b3631202c36ull,0x202f2f0920202020ull,0x6e752e617262090aull,
0x335f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x36383139325f335full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x38333334315f335full,0x3109636f6c2e090aull,0x0a30093935320935ull,0x3436662e6c756d09ull,
0x2c34316466250920ull,0x25202c3564662520ull,0x092020203b396466ull,0x646461090a202f2full,
0x662509203436662eull,0x646625202c303964ull,0x31646625202c3431ull,0x0a202f2f09203b34ull,
0x3436662e64646109ull,0x202c356466250920ull,0x6625202c34646625ull,0x092020203b303964ull,
0x6f6c2e090a202f2full,0x3036320935310963ull,0x2e627573090a3009ull,0x6466250920343666ull,
0x31646625202c3139ull,0x3738646625202c31ull,0x090a202f2f09203bull,0x203436662e646461ull,
0x25202c3964662509ull,0x646625202c386466ull,0x2f092020203b3139ull,0x636f6c2e090a202full,
0x0931363209353109ull,0x662e6c756d090a30ull,0x3964662509203436ull,0x2c35646625202c32ull,
0x20203b3564662520ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3131646625ull,
0x646625202c396466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,0x3964662509203436ull,
0x3131646625202c33ull,0x3b3239646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3439646625ull,0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,
0x74672e7074657309ull,0x702509203436662eull,0x39646625202c3831ull,0x3439646625202c33ull,
0x40090a202f2f093bull,0x7262203831702521ull,0x335f744c24092061ull,0x203b38393639325full,
0x2f2f092020202020ull,0x732e627573090a20ull,0x3731722509203233ull,0x202c36317225202cull,
0x20202020203b3731ull,0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f335f744c24ull,
0x2020202020203b38ull,0x2f2f092020202020ull,0x5f335f744c240a20ull,0x200a3a3839363932ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c363932ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3833333431ull,
0x3209353109636f6cull,0x756d090a30093736ull,0x2509203436662e6cull,0x6625202c34316466ull,
0x39646625202c3564ull,0x202f2f092020203bull,0x36662e646461090aull,0x3539646625092034ull,
0x2c3431646625202cull,0x203b343164662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,
0x646625202c356466ull,0x3539646625202c34ull,0x202f2f092020203bull,0x3109636f6c2e090aull,
0x0a30093836320935ull,0x3436662e62757309ull,0x2c36396466250920ull,0x202c313164662520ull,
0x09203b3239646625ull,0x646461090a202f2full,0x662509203436662eull,0x38646625202c3964ull,
0x3b3639646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939363209ull,
0x203436662e6c756dull,0x202c373964662509ull,0x6625202c35646625ull,0x2f092020203b3564ull,
0x2e6c756d090a202full,0x6466250920343666ull,0x39646625202c3131ull,0x203b39646625202cull,
0x090a202f2f092020ull,0x203436662e646461ull,0x202c383964662509ull,0x25202c3131646625ull,
0x2f09203b37396466ull,0x2e766f6d090a202full,0x6466250920343666ull,0x30346430202c3939ull,
0x3030303030303031ull,0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,
0x2c39317025092034ull,0x202c383964662520ull,0x2f093b3939646625ull,0x70252140090a202full,
0x0920617262203931ull,0x30335f335f744c24ull,0x202020203b303132ull,0x090a202f2f092020ull,
0x203233732e627573ull,0x25202c3731722509ull,0x3b3831202c363172ull,0x2f09202020202020ull,
0x2e617262090a202full,0x744c240920696e75ull,0x203b3835325f335full,0x2020202020202020ull,
0x240a202f2f092020ull,0x3230335f335f744cull,0x3c2f2f200a3a3031ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x36393220656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3334315f335f744cull,0x636f6c2e090a3833ull,0x0935373209353109ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x2c35646625202c34ull,0x20203b3964662520ull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x202c303031646625ull,0x25202c3431646625ull,
0x2f2f093b34316466ull,0x662e646461090a20ull,0x3564662509203436ull,0x202c34646625202cull,
0x203b303031646625ull,0x2e090a202f2f0920ull,0x3209353109636f6cull,0x7573090a30093637ull,
0x2509203436662e62ull,0x25202c3130316466ull,0x6625202c31316466ull,0x202f2f093b373964ull,
0x36662e646461090aull,0x2c39646625092034ull,0x25202c3864662520ull,0x20203b3130316466ull,
0x6c2e090a202f2f09ull,0x373209353109636full,0x6c756d090a300937ull,0x662509203436662eull,
0x6625202c32303164ull,0x35646625202c3564ull,0x0a202f2f0920203bull,0x3436662e6c756d09ull,
0x2c31316466250920ull,0x25202c3964662520ull,0x092020203b396466ull,0x646461090a202f2full,
0x662509203436662eull,0x6625202c33303164ull,0x646625202c313164ull,0x202f2f093b323031ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x3130346430202c34ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,0x202c303270250920ull,
0x202c333031646625ull,0x093b343031646625ull,0x252140090a202f2full,0x2061726220303270ull,
0x335f335f744c2409ull,0x2020203b32323730ull,0x0a202f2f09202020ull,0x3233732e62757309ull,
0x202c373172250920ull,0x3931202c36317225ull,0x092020202020203bull,0x617262090a202f2full,
0x4c240920696e752eull,0x3b3835325f335f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x30335f335f744c24ull,0x2f2f200a3a323237ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x393220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,
0x34315f335f744c24ull,0x6f6c2e090a383333ull,0x3338320935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x35646625202c3431ull,0x203b39646625202cull,0x090a202f2f092020ull,
0x203436662e646461ull,0x2c35303164662509ull,0x202c343164662520ull,0x2f093b3431646625ull,
0x2e646461090a202full,0x6466250920343666ull,0x2c34646625202c35ull,0x3b35303164662520ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009343832ull,0x09203436662e6275ull,
0x202c363031646625ull,0x25202c3131646625ull,0x2f093b3230316466ull,0x2e646461090a202full,
0x6466250920343666ull,0x2c38646625202c39ull,0x3b36303164662520ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6d090a3009353832ull,0x09203436662e6c75ull,0x202c373031646625ull,
0x6625202c35646625ull,0x2f2f0920203b3564ull,0x09636f6c2e090a20ull,0x3009393832093531ull,
0x33732e627573090aull,0x2c36317225092032ull,0x32202c3631722520ull,0x2020202020203b30ull,
0x6c2e090a202f2f09ull,0x383209353109636full,0x766f6d090a300933ull,0x722509203233752eull,
0x20203b30202c3831ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,
0x702509203233732eull,0x36317225202c3132ull,0x093b38317225202cull,0x702540090a202f2full,
0x0920617262203132ull,0x3730325f335f4c24ull,0x20202020203b3833ull,0x0a202f2f09202020ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c36393220ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a38333334315full,
0x203436662e6c756dull,0x202c313164662509ull,0x6625202c39646625ull,0x2f092020203b3964ull,
0x2e646461090a202full,0x6466250920343666ull,0x646625202c383031ull,0x31646625202c3131ull,
0x0a202f2f093b3730ull,0x3436662e766f6d09ull,0x3930316466250920ull,0x303130346430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3420ull,0x203436662e74672eull,
0x25202c3232702509ull,0x25202c3830316466ull,0x2f093b3930316466ull,0x70252140090a202full,
0x0920617262203232ull,0x3430325f335f4c24ull,0x20202020203b3238ull,0x240a202f2f092020ull,
0x333730325f335f4cull,0x2e766f6d090a3a38ull,0x3172250920323373ull,0x3b36317225202c37ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x20696e752e617262ull,0x325f335f744c2409ull,
0x20202020203b3835ull,0x2f09202020202020ull,0x5f335f4c240a202full,0x200a3a3238343032ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c363932ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3833333431ull,
0x3209353109636f6cull,0x756d090a30093239ull,0x2509203436662e6cull,0x6625202c34316466ull,
0x39646625202c3564ull,0x202f2f092020203bull,0x36662e646461090aull,0x3131646625092034ull,
0x3431646625202c30ull,0x3b3431646625202cull,0x6461090a202f2f09ull,0x2509203436662e64ull,
0x646625202c356466ull,0x3131646625202c34ull,0x202f2f0920203b30ull,0x3109636f6c2e090aull,
0x0a30093339320935ull,0x3436662e62757309ull,0x3131316466250920ull,0x2c3131646625202cull,
0x3b37303164662520ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x646625202c396466ull,
0x3131646625202c38ull,0x202f2f0920203b31ull,0x3109636f6c2e090aull,0x0a30093239320935ull,
0x696e752e61726209ull,0x5f335f744c240920ull,0x20203b3833333431ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x090a3a3835325f33ull,0x09363109636f6c2eull,0x6f6d090a30093931ull,
0x2509203233732e76ull,0x203b30202c393172ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x672e70746573090aull,0x2509203233732e74ull,0x317225202c333270ull,0x3b39317225202c37ull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x317225202c303272ull,0x3b37317225202c35ull,
0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c31327225092032ull,0x20202020203b3020ull,
0x2020202020202020ull,0x6573090a202f2f09ull,0x09203233732e706cull,0x7225202c32327225ull,
0x31327225202c3032ull,0x093b33327025202cull,0x766f6d090a202f2full,0x722509203233752eull,
0x20203b30202c3332ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x71652e7074657309ull,
0x702509203233732eull,0x32327225202c3432ull,0x093b33327225202cull,0x702540090a202f2full,
0x0920617262203432ull,0x31335f335f744c24ull,0x202020203b303934ull,0x0a202f2f09202020ull,
0x363109636f6c2e09ull,0x6c090a3009363209ull,0x2e6d617261702e64ull,0x3272250920323373ull,
0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645644930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,
0x6f6974616d696e61ull,0x3b5d656d6172466eull,0x353a6469202f2f09ull,0x6475635f5f203731ull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x615f69695f30535full,0x6e6f6974616d696eull,
0x78302b656d617246ull,0x732e646461090a30ull,0x3532722509203233ull,0x202c34327225202cull,
0x2020203b32327225ull,0x6c090a202f2f0920ull,0x2e6d617261702e64ull,0x3632722509203875ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x635f69695f30535full,
0x5d302b73726f6c6full,0x3a6469202f2f093bull,0x75635f5f20383135ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f69695f30535f32ull,0x302b73726f6c6f63ull,0x2e6c756d090a3078ull,
0x09203233732e6f6cull,0x7225202c37327225ull,0x36327225202c3532ull,0x090a202f2f09203bull,
0x752e38752e747663ull,0x3832722509203233ull,0x203b37327225202cull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x3009373209363109ull,0x7261702e646c090aull,0x25092038752e6d61ull,
0x5f5f5b202c393272ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,
0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,
0x73726f6c6f635f69ull,0x202f2f093b5d312bull,0x5f203931353a6469ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x726f6c6f635f6969ull,0x6d090a3178302b73ull,
0x33732e6f6c2e6c75ull,0x2c30337225092032ull,0x25202c3532722520ull,0x2f2f09203b393272ull,
0x752e747663090a20ull,0x2509203233752e38ull,0x337225202c313372ull,0x2020202020203b30ull,
0x2e090a202f2f0920ull,0x3209363109636f6cull,0x2e646c090a300938ull,0x38752e6d61726170ull,
0x202c323372250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x6c6f635f69695f30ull,0x093b5d322b73726full,0x32353a6469202f2full,0x616475635f5f2030ull,
0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645644930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x6f635f69695f3053ull,0x3278302b73726f6cull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x35327225202c3333ull,0x203b32337225202cull,
0x7663090a202f2f09ull,0x3233752e38752e74ull,0x202c343372250920ull,0x2020203b33337225ull,
0x202f2f0920202020ull,0x6e752e617262090aull,0x335f744c24092069ull,0x203b34333231335full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x30393431335f335full,0x09636f6c2e090a3aull,
0x0a30093233093631ull,0x3233752e766f6d09ull,0x202c343372250920ull,0x2020202020203b30ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3133ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x3233752e766f6d09ull,0x202c383272250920ull,
0x2020202020203b30ull,0x0920202020202020ull,0x5f744c240a202f2full,0x3a34333231335f33ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c31647225ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x3b5d7473645f6969ull,0x353a6469202f2f09ull,
0x6475635f5f203132ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x645f69695f30535full,
0x090a3078302b7473ull,0x732e6f6c2e6c756dull,0x3533722509203233ull,0x25202c377225202cull,
0x2f092020203b3672ull,0x2e646461090a202full,0x3372250920323373ull,0x202c347225202c36ull,
0x2020203b35337225ull,0x090a202f2f092020ull,0x2e3436752e747663ull,0x6472250920323373ull,
0x3b36337225202c32ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x7225202c33647225ull,0x20203b34202c3264ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x25202c3464722509ull,0x647225202c316472ull,0x2f09202020203b33ull,0x702e646c090a202full,
0x3233732e6d617261ull,0x202c373372250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,
0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,
0x535f32535f32535full,0x6172665f69695f30ull,0x202f2f093b5d656dull,0x5f203130353a6469ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x656d6172665f6969ull,
0x6f6d090a3078302bull,0x2509203233752e76ull,0x203b30202c383372ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x6e2e70746573090aull,0x2509203233732e65ull,0x337225202c353270ull,
0x3b38337225202c37ull,0x2540090a202f2f09ull,0x2061726220353270ull,0x335f335f744c2409ull,
0x2020203b32303032ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x090a300939330936ull,
0x203233752e766f6dull,0x30202c3933722509ull,0x202020202020203bull,0x2f09202020202020ull,
0x672e7473090a202full,0x34762e6c61626f6cull,0x72255b092038752eull,0x7b202c5d302b3464ull,
0x3372252c38327225ull,0x252c343372252c31ull,0x2f2f093b7d393372ull,0x752e617262090a20ull,
0x5f744c240920696eull,0x3b36343731335f33ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x303032335f335f74ull,0x636f6c2e090a3a32ull,0x3009333409363109ull,0x33732e646461090aull,
0x2c30347225092032ull,0x31202c3733722520ull,0x202020202020203bull,0x6873090a202f2f09ull,
0x2509203233732e72ull,0x347225202c313472ull,0x20203b3133202c30ull,0x202f2f0920202020ull,
0x33732e766f6d090aull,0x2c32347225092032ull,0x20202020203b3120ull,0x2020202020202020ull,
0x6e61090a202f2f09ull,0x2509203233622e64ull,0x347225202c333472ull,0x3b32347225202c31ull,
0x202f2f0920202020ull,0x33732e646461090aull,0x2c34347225092032ull,0x25202c3334722520ull,
0x202020203b303472ull,0x6873090a202f2f09ull,0x2509203233732e72ull,0x347225202c353472ull,
0x2020203b31202c34ull,0x202f2f0920202020ull,0x6f6c672e646c090aull,0x752e34762e6c6162ull,
0x363472257b092038ull,0x72252c373472252cull,0x5b202c7d5f2c3834ull,0x3b5d302b34647225ull,
0x756d090a202f2f09ull,0x3233732e6f6c2e6cull,0x202c393472250920ull,0x7225202c37337225ull,
0x202f2f09203b3634ull,0x33732e646461090aull,0x2c30357225092032ull,0x25202c3832722520ull,
0x202020203b393472ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x347225202c313572ull,
0x3b30357225202c35ull,0x202f2f0920202020ull,0x33732e766964090aull,0x2c32357225092032ull,
0x25202c3135722520ull,0x202020203b303472ull,0x6c2e090a202f2f09ull,0x343409363109636full,
0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x7225202c33357225ull,0x37347225202c3733ull,
0x090a202f2f09203bull,0x203233732e646461ull,0x25202c3435722509ull,0x357225202c313372ull,
0x2f09202020203b33ull,0x2e646461090a202full,0x3572250920323373ull,0x2c35347225202c35ull,
0x20203b3435722520ull,0x090a202f2f092020ull,0x203233732e766964ull,0x25202c3635722509ull,
0x347225202c353572ull,0x2f09202020203b30ull,0x672e7473090a202full,0x32762e6c61626f6cull,
0x72255b092038752eull,0x7b202c5d302b3464ull,0x3572252c32357225ull,0x0a202f2f093b7d36ull,
0x363109636f6c2e09ull,0x6d090a3009353409ull,0x33732e6f6c2e6c75ull,0x2c37357225092032ull,
0x25202c3733722520ull,0x2f2f09203b383472ull,0x732e646461090a20ull,0x3835722509203233ull,
0x202c34337225202cull,0x2020203b37357225ull,0x61090a202f2f0920ull,0x09203233732e6464ull,
0x7225202c39357225ull,0x38357225202c3534ull,0x2f2f09202020203bull,0x732e766964090a20ull,
0x3036722509203233ull,0x202c39357225202cull,0x2020203b30347225ull,0x73090a202f2f0920ull,
0x6c61626f6c672e74ull,0x72255b092038752eull,0x25202c5d322b3464ull,0x2f2f09203b303672ull,
0x0a3133353a646920ull,0x31335f335f744c24ull,0x744c240a3a363437ull,0x34393930325f335full,
0x09636f6c2e090a3aull,0x0a30093834093631ull,0x20203b7469786509ull,0x2020202020202020ull,
0x2020202020202020ull,0x0920202020202020ull,0x57444c240a202f2full,0x36315a5f5f646e65ull,
0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,
0x535f32535f32535full,0x7d090a3a69695f30ull,0x36315a5f202f2f20ull,0x72626c65646e614dull,
0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x2e090a0a69695f30ull,0x5a5f207972746e65ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x282069695f30535full,
0x617261702e09090aull,0x5f203436752e206dull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f30535f32535f32ull,0x0a2c7473645f6969ull,0x6d617261702e0909ull,0x5f5f203233732e20ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,0x576567616d695f69ull,
0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764566ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x67616d695f69695full,0x702e09090a2c4865ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x72635f69695f3053ull,
0x09090a2c68636e75ull,0x2e206d617261702eull,0x75635f5f20323366ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645664930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f69695f30535f32ull,0x09090a2c66664f78ull,0x2e206d617261702eull,
0x75635f5f20323366ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f31746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,
0x09090a2c66664f79ull,0x2e206d617261702eull,0x75635f5f20323366ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645664930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f69695f30535f32ull,0x090a2c656c616373ull,0x206d617261702e09ull,
0x34206e67696c612eull,0x635f5f2038622e20ull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f31746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x69695f30535f3253ull,0x5b73726f6c6f635full,0x702e09090a2c5d34ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x72665f69695f3053ull,
0x2e09090a2c656d61ull,0x732e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x615f69695f30535full,0x6e6f6974616d696eull,0x090a29656d617246ull,
0x206765722e090a7bull,0x687225203631752eull,0x722e090a3b3e363cull,0x203233752e206765ull,
0x3b3e3734313c7225ull,0x2e206765722e090aull,0x3c64722520343675ull,0x722e090a3b3e3231ull,
0x203233662e206765ull,0x3b3e3331313c6625ull,0x2e206765722e090aull,0x3c70252064657270ull,
0x6c2e090a3b3e3133ull,0x393909363109636full,0x3142424c240a3009ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x2e766f6d090a3a69ull,0x6872250920363175ull,0x6961746325202c31ull,
0x202020203b782e64ull,0x090a202f2f092020ull,0x203631752e766f6dull,0x25202c3268722509ull,
0x203b782e6469746eull,0x2f09202020202020ull,0x2e6c756d090a202full,0x3631752e65646977ull,
0x25202c3172250920ull,0x687225202c316872ull,0x090a202f2f093b32ull,0x203631752e766f6dull,
0x25202c3368722509ull,0x3b792e6469617463ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x6872250920363175ull,0x6469746e25202c34ull,0x20202020203b792eull,0x090a202f2f092020ull,
0x656469772e6c756dull,0x722509203631752eull,0x2c33687225202c32ull,0x2f093b3468722520ull,
0x2e747663090a202full,0x203631752e323375ull,0x7425202c33722509ull,0x2020203b782e6469ull,
0x090a202f2f092020ull,0x203233752e646461ull,0x7225202c34722509ull,0x203b317225202c33ull,
0x2f09202020202020ull,0x2e747663090a202full,0x203631752e323375ull,0x7425202c35722509ull,
0x2020203b792e6469ull,0x090a202f2f092020ull,0x203233752e646461ull,0x7225202c36722509ull,
0x203b327225202c35ull,0x2f09202020202020ull,0x702e646c090a202full,0x3233732e6d617261ull,
0x5b202c3772250920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764566ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x67616d695f69695full,0x202f2f093b5d4865ull,0x5f203838353a6469ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x6567616d695f6969ull,0x6c090a3078302b48ull,
0x2e6d617261702e64ull,0x3872250920323373ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x695f69695f30535full,0x093b5d576567616dull,0x38353a6469202f2full,
0x616475635f5f2039ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x6d695f69695f3053ull,
0x3078302b57656761ull,0x74672e746573090aull,0x3233732e3233752eull,0x25202c3972250920ull,
0x3b367225202c3772ull,0x656e090a202f2f09ull,0x2509203233732e67ull,0x397225202c303172ull,
0x202020202020203bull,0x202f2f0920202020ull,0x74672e746573090aull,0x3233732e3233752eull,
0x202c313172250920ull,0x347225202c387225ull,0x6e090a202f2f093bull,0x09203233732e6765ull,
0x7225202c32317225ull,0x20202020203b3131ull,0x2f2f092020202020ull,0x622e646e61090a20ull,
0x3331722509203233ull,0x202c30317225202cull,0x2020203b32317225ull,0x6d090a202f2f0920ull,
0x09203233752e766full,0x3b30202c34317225ull,0x2020202020202020ull,0x2f2f092020202020ull,
0x2e70746573090a20ull,0x09203233732e7165ull,0x317225202c317025ull,0x3b34317225202c33ull,
0x40090a202f2f0920ull,0x2061726220317025ull,0x325f345f744c2409ull,0x2020203b32363138ull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009373031093631ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x2c387225202c3531ull,0x2020203b36722520ull,0x6461090a202f2f09ull,
0x2509203233732e64ull,0x347225202c363172ull,0x203b35317225202cull,0x202f2f0920202020ull,
0x7261702e646c090aull,0x09203436752e6d61ull,0x5f5b202c31647225ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x3b5d7473645f6969ull,0x353a6469202f2f09ull,
0x6475635f5f203738ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x645f69695f30535full,
0x090a3078302b7473ull,0x2e3436752e747663ull,0x6472250920323373ull,0x3b36317225202c32ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,0x7225202c33647225ull,
0x20203b34202c3264ull,0x090a202f2f092020ull,0x203436752e646461ull,0x25202c3464722509ull,
0x647225202c316472ull,0x2f09202020203b33ull,0x672e646c090a202full,0x34762e6c61626f6cull,
0x72257b092038752eull,0x2c383172252c3731ull,0x2c7d5f2c39317225ull,0x302b346472255b20ull,
0x090a202f2f093b5dull,0x203233752e766f6dull,0x30202c3032722509ull,0x202020202020203bull,
0x2f09202020202020ull,0x70746573090a202full,0x203233732e656c2eull,0x7225202c32702509ull,
0x3b30327225202c34ull,0x090a202f2f092020ull,0x6172622032702540ull,0x5f345f744c240920ull,
0x20203b3033393832ull,0x2f09202020202020ull,0x672e646c090a202full,0x34762e6c61626f6cull,
0x72257b092038752eull,0x2c323272252c3132ull,0x2c7d5f2c33327225ull,0x2d2b346472255b20ull,
0x0a202f2f093b5d34ull,0x363109636f6c2e09ull,0x090a300932313109ull,0x203233732e627573ull,
0x25202c3432722509ull,0x317225202c333272ull,0x2f09202020203b39ull,0x2e736261090a202full,
0x3272250920323373ull,0x3b34327225202c35ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233732e766f6dull,0x31202c3632722509ull,0x2020202020203b30ull,0x2f09202020202020ull,
0x2e746573090a202full,0x732e3233752e7467ull,0x3732722509203233ull,0x202c35327225202cull,
0x2f2f093b36327225ull,0x732e67656e090a20ull,0x3832722509203233ull,0x203b37327225202cull,
0x2020202020202020ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c39327225ull,
0x37317225202c3132ull,0x2f2f09202020203bull,0x732e736261090a20ull,0x3033722509203233ull,
0x203b39327225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,
0x3031202c31337225ull,0x202020202020203bull,0x2f2f092020202020ull,0x672e746573090a20ull,
0x33732e3233752e74ull,0x2c32337225092032ull,0x25202c3033722520ull,0x202f2f093b313372ull,
0x33732e67656e090aull,0x2c33337225092032ull,0x20203b3233722520ull,0x2020202020202020ull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x327225202c343372ull,0x3b38317225202c32ull,
0x202f2f0920202020ull,0x33732e736261090aull,0x2c35337225092032ull,0x20203b3433722520ull,
0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x3b3031202c363372ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x74672e746573090aull,0x3233732e3233752eull,
0x202c373372250920ull,0x7225202c35337225ull,0x0a202f2f093b3633ull,0x3233732e67656e09ull,
0x202c383372250920ull,0x2020203b37337225ull,0x0920202020202020ull,0x2e726f090a202f2full,
0x3372250920323362ull,0x2c33337225202c39ull,0x20203b3833722520ull,0x0a202f2f09202020ull,
0x203233622e726f09ull,0x25202c3034722509ull,0x337225202c383272ull,0x0920202020203b39ull,
0x617262090a202f2full,0x4c240920696e752eull,0x373638325f345f74ull,0x2020202020203b34ull,
0x0a202f2f09202020ull,0x38325f345f744c24ull,0x6f6d090a3a303339ull,0x2509203233732e76ull,
0x203b30202c303472ull,0x2020202020202020ull,0x202f2f0920202020ull,0x325f345f744c240aull,
0x61090a3a34373638ull,0x09203233732e6464ull,0x7225202c31347225ull,0x2020203b31202c34ull,
0x2f2f092020202020ull,0x2e70746573090a20ull,0x09203233732e656cull,0x387225202c337025ull,
0x203b31347225202cull,0x40090a202f2f0920ull,0x2061726220337025ull,0x325f345f744c2409ull,
0x2020203b36383139ull,0x2f2f092020202020ull,0x6c672e646c090a20ull,0x2e34762e6c61626full,
0x3472257b09203875ull,0x252c333472252c32ull,0x202c7d5f2c343472ull,0x5d342b346472255bull,
0x2e090a202f2f093bull,0x3109363109636f6cull,0x7573090a30093431ull,0x2509203233732e62ull,
0x347225202c353472ull,0x3b39317225202c34ull,0x202f2f0920202020ull,0x33732e736261090aull,
0x2c36347225092032ull,0x20203b3534722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233732e76ull,0x3b3031202c373472ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x74672e746573090aull,0x3233732e3233752eull,0x202c383472250920ull,0x7225202c36347225ull,
0x0a202f2f093b3734ull,0x3233732e67656e09ull,0x202c393472250920ull,0x2020203b38347225ull,
0x0920202020202020ull,0x627573090a202f2full,0x722509203233732eull,0x32347225202c3035ull,
0x203b37317225202cull,0x0a202f2f09202020ull,0x3233732e73626109ull,0x202c313572250920ull,
0x2020203b30357225ull,0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233732eull,
0x203b3031202c3235ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x2e74672e74657309ull,
0x203233732e323375ull,0x25202c3335722509ull,0x357225202c313572ull,0x090a202f2f093b32ull,
0x203233732e67656eull,0x25202c3435722509ull,0x202020203b333572ull,0x2f09202020202020ull,
0x2e627573090a202full,0x3572250920323373ull,0x2c33347225202c35ull,0x20203b3831722520ull,
0x090a202f2f092020ull,0x203233732e736261ull,0x25202c3635722509ull,0x202020203b353572ull,
0x2f09202020202020ull,0x2e766f6d090a202full,0x3572250920323373ull,0x20203b3031202c37ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x7225202c38357225ull,0x37357225202c3635ull,0x6e090a202f2f093bull,0x09203233732e6765ull,
0x7225202c39357225ull,0x20202020203b3835ull,0x2f2f092020202020ull,0x33622e726f090a20ull,
0x2c30367225092032ull,0x25202c3435722520ull,0x202020203b393572ull,0x6f090a202f2f0920ull,
0x2509203233622e72ull,0x347225202c313672ull,0x3b30367225202c39ull,0x2f2f092020202020ull,
0x732e646461090a20ull,0x3034722509203233ull,0x202c30347225202cull,0x2020203b31367225ull,
0x4c240a202f2f0920ull,0x383139325f345f74ull,0x2e766f6d090a3a36ull,0x3672250920323375ull,
0x2020203b30202c32ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e656c2e70746573ull,
0x3470250920323373ull,0x25202c367225202cull,0x2f0920203b323672ull,0x34702540090a202full,
0x4c24092061726220ull,0x393639325f345f74ull,0x2020202020203b38ull,0x090a202f2f092020ull,
0x09363109636f6c2eull,0x73090a3009363131ull,0x09203233732e6275ull,0x7225202c33367225ull,
0x3b387225202c3631ull,0x2f2f092020202020ull,0x732e747663090a20ull,0x09203233732e3436ull,
0x7225202c35647225ull,0x20202020203b3336ull,0x6d090a202f2f0920ull,0x36752e6f6c2e6c75ull,
0x2c36647225092034ull,0x34202c3564722520ull,0x2f2f09202020203bull,0x752e646461090a20ull,
0x3764722509203436ull,0x202c31647225202cull,0x2020203b36647225ull,0x6c090a202f2f0920ull,
0x6c61626f6c672e64ull,0x092038752e34762eull,0x72252c343672257bull,0x2c363672252c3536ull,
0x6472255b202c7d5full,0x2f2f093b5d302b37ull,0x732e627573090a20ull,0x3736722509203233ull,
0x202c36367225202cull,0x2020203b39317225ull,0x61090a202f2f0920ull,0x09203233732e7362ull,
0x7225202c38367225ull,0x20202020203b3736ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3936722509203233ull,0x2020203b3031202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x33752e74672e7465ull,0x2509203233732e32ull,0x367225202c303772ull,0x3b39367225202c38ull,
0x656e090a202f2f09ull,0x2509203233732e67ull,0x377225202c313772ull,0x2020202020203b30ull,
0x202f2f0920202020ull,0x33732e627573090aull,0x2c32377225092032ull,0x25202c3436722520ull,
0x202020203b373172ull,0x6261090a202f2f09ull,0x2509203233732e73ull,0x377225202c333772ull,
0x2020202020203b32ull,0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c34377225092032ull,
0x202020203b303120ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x3233752e74672e74ull,
0x722509203233732eull,0x33377225202c3537ull,0x093b34377225202cull,0x67656e090a202f2full,
0x722509203233732eull,0x35377225202c3637ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233732e62757309ull,0x202c373772250920ull,0x7225202c35367225ull,0x09202020203b3831ull,
0x736261090a202f2full,0x722509203233732eull,0x37377225202c3837ull,0x202020202020203bull,
0x0a202f2f09202020ull,0x3233732e766f6d09ull,0x202c393772250920ull,0x20202020203b3031ull,
0x0920202020202020ull,0x746573090a202f2full,0x2e3233752e74672eull,0x3872250920323373ull,
0x2c38377225202c30ull,0x2f093b3937722520ull,0x2e67656e090a202full,0x3872250920323373ull,
0x3b30387225202c31ull,0x2020202020202020ull,0x090a202f2f092020ull,0x09203233622e726full,
0x7225202c32387225ull,0x31387225202c3637ull,0x2f0920202020203bull,0x622e726f090a202full,
0x3338722509203233ull,0x202c31377225202cull,0x2020203b32387225ull,0x090a202f2f092020ull,
0x203233732e646461ull,0x25202c3034722509ull,0x387225202c303472ull,0x2f09202020203b33ull,
0x345f744c240a202full,0x0a3a38393639325full,0x3233732e64646109ull,0x202c343872250920ull,
0x203b31202c367225ull,0x0920202020202020ull,0x746573090a202f2full,0x3233732e656c2e70ull,
0x25202c3570250920ull,0x34387225202c3772ull,0x0a202f2f0920203bull,0x7262203570254009ull,
0x345f744c24092061ull,0x203b30313230335full,0x0920202020202020ull,0x6f6c2e090a202f2full,
0x3831310936310963ull,0x2e646461090a3009ull,0x3872250920323373ull,0x2c36317225202c35ull,
0x2020203b38722520ull,0x090a202f2f092020ull,0x2e3436732e747663ull,0x6472250920323373ull,
0x3b35387225202c38ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x09203436752e6f6cull,
0x7225202c39647225ull,0x20203b34202c3864ull,0x090a202f2f092020ull,0x203436752e646461ull,
0x202c303164722509ull,0x7225202c31647225ull,0x2f092020203b3964ull,0x672e646c090a202full,
0x34762e6c61626f6cull,0x72257b092038752eull,0x2c373872252c3638ull,0x2c7d5f2c38387225ull,
0x2b30316472255b20ull,0x0a202f2f093b5d30ull,0x3233732e62757309ull,0x202c393872250920ull,
0x7225202c38387225ull,0x09202020203b3931ull,0x736261090a202f2full,0x722509203233732eull,
0x39387225202c3039ull,0x202020202020203bull,0x0a202f2f09202020ull,0x3233732e766f6d09ull,
0x202c313972250920ull,0x20202020203b3031ull,0x0920202020202020ull,0x746573090a202f2full,
0x2e3233752e74672eull,0x3972250920323373ull,0x2c30397225202c32ull,0x2f093b3139722520ull,
0x2e67656e090a202full,0x3972250920323373ull,0x3b32397225202c33ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3439722509ull,0x317225202c363872ull,
0x2f09202020203b37ull,0x2e736261090a202full,0x3972250920323373ull,0x3b34397225202c35ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e766f6dull,0x31202c3639722509ull,
0x2020202020203b30ull,0x2f09202020202020ull,0x2e746573090a202full,0x732e3233752e7467ull,
0x3739722509203233ull,0x202c35397225202cull,0x2f2f093b36397225ull,0x732e67656e090a20ull,
0x3839722509203233ull,0x203b37397225202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x09203233732e6275ull,0x7225202c39397225ull,0x38317225202c3738ull,0x2f2f09202020203bull,
0x732e736261090a20ull,0x3031722509203233ull,0x3b39397225202c30ull,0x2020202020202020ull,
0x6d090a202f2f0920ull,0x09203233732e766full,0x31202c3130317225ull,0x2020202020203b30ull,
0x2f2f092020202020ull,0x672e746573090a20ull,0x33732e3233752e74ull,0x3230317225092032ull,
0x2c3030317225202cull,0x093b313031722520ull,0x67656e090a202f2full,0x722509203233732eull,
0x317225202c333031ull,0x20202020203b3230ull,0x0a202f2f09202020ull,0x203233622e726f09ull,
0x202c343031722509ull,0x7225202c38397225ull,0x092020203b333031ull,0x2e726f090a202f2full,
0x3172250920323362ull,0x33397225202c3530ull,0x3b3430317225202cull,0x0a202f2f09202020ull,
0x3233732e64646109ull,0x202c303472250920ull,0x7225202c30347225ull,0x092020203b353031ull,
0x5f744c240a202f2full,0x3a30313230335f34ull,0x33752e766f6d090aull,0x3630317225092032ull,
0x202020203b30202cull,0x2020202020202020ull,0x6573090a202f2f09ull,0x33732e71652e7074ull,
0x202c367025092032ull,0x7225202c30347225ull,0x202f2f093b363031ull,0x622036702540090aull,
0x5f744c2409206172ull,0x3b32323730335f34ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x323109353109636full,0x747663090a300939ull,0x2e3233662e6e722eull,0x3166250920323373ull,
0x20203b367225202cull,0x0a202f2f09202020ull,0x617261702e646c09ull,0x2509203233662e6dull,
0x635f5f5b202c3266ull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,
0x3b5d656c6163735full,0x353a6469202f2f09ull,0x6475635f5f203538ull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x735f69695f30535full,0x3078302b656c6163ull,0x7261702e646c090aull,
0x09203233662e6d61ull,0x5f5f5b202c336625ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x3b5d66664f795f69ull,0x363a6469202f2f09ull,0x6475635f5f203131ull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x795f69695f30535full,0x0a3078302b66664full,
0x3233662e64616d09ull,0x25202c3466250920ull,0x2c326625202c3166ull,0x0920203b33662520ull,
0x766f6d090a202f2full,0x662509203233662eull,0x203b346625202c35ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300930333109ull,0x662e6e722e747663ull,
0x09203233732e3233ull,0x347225202c366625ull,0x2f0920202020203bull,0x702e646c090a202full,
0x3233662e6d617261ull,0x5b202c3766250920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764566ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x66664f785f69695full,0x6469202f2f093b5dull,0x635f5f203231363aull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645664930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,0x78302b66664f785full,
0x662e64616d090a30ull,0x2c38662509203233ull,0x6625202c36662520ull,0x203b376625202c32ull,
0x6d090a202f2f0920ull,0x09203233662e766full,0x386625202c396625ull,0x202020202020203bull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009333331093531ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5b202c3730317225ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764566ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x6e7572635f69695full,0x202f2f093b5d6863ull,0x5f203438353a6469ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f31ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x636e7572635f6969ull,
0x6d090a3078302b68ull,0x09203233732e766full,0x25202c3830317225ull,0x2020203b37303172ull,
0x2f2f092020202020ull,0x5f345f744c240a20ull,0x200a3a3236373132ull,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a363932ull,0x3639320935310963ull,
0x2e6c756d090a3009ull,0x3166250920323366ull,0x202c356625202c30ull,0x202020203b356625ull,
0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3131662509ull,0x3b396625202c3966ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3166250920323366ull,0x2c31316625202c32ull,
0x20203b3031662520ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3331662509ull,
0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,
0x25202c3770250920ull,0x316625202c323166ull,0x0a202f2f09203b33ull,0x6220377025214009ull,
0x5f744c2409206172ull,0x3b34333231335f34ull,0x0920202020202020ull,0x627573090a202f2full,
0x722509203233732eull,0x317225202c393031ull,0x20203b31202c3830ull,0x0a202f2f09202020ull,
0x696e752e61726209ull,0x5f345f744c240920ull,0x202020203b383532ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x3a34333231335f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32363731325f34ull,0x353109636f6c2e09ull,0x090a300939333109ull,
0x203233662e6c756dull,0x25202c3431662509ull,0x3b396625202c3566ull,0x2f09202020202020ull,
0x2e646461090a202full,0x3166250920323366ull,0x2c34316625202c35ull,0x20203b3431662520ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c35662509ull,0x3b35316625202c34ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0930343109353109ull,0x662e627573090a30ull,
0x3631662509203233ull,0x202c31316625202cull,0x2020203b30316625ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x386625202c396625ull,0x203b36316625202cull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009313431093531ull,0x33662e6c756d090aull,0x2c37316625092032ull,
0x6625202c35662520ull,0x2020202020203b35ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x396625202c313166ull,0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,
0x2c38316625092032ull,0x25202c3131662520ull,0x202020203b373166ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x346630202c393166ull,0x3b30303030303830ull,0x202f2f0920202020ull,
0x2e70746573090a34ull,0x09203233662e7467ull,0x316625202c387025ull,0x3b39316625202c38ull,
0x40090a202f2f0920ull,0x6172622038702521ull,0x5f345f744c240920ull,0x20203b3634373133ull,
0x2f2f092020202020ull,0x732e627573090a20ull,0x3031722509203233ull,0x3830317225202c39ull,
0x202020203b32202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f345f744c24ull,
0x2020202020203b38ull,0x2f2f092020202020ull,0x5f345f744c240a20ull,0x200a3a3634373133ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c363932ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x2e090a3236373132ull,
0x3109353109636f6cull,0x756d090a30093734ull,0x2509203233662e6cull,0x356625202c343166ull,
0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,0x2c30326625092032ull,
0x25202c3431662520ull,0x202020203b343166ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x2c346625202c3566ull,0x20203b3032662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093834310935ull,0x3233662e62757309ull,0x202c313266250920ull,0x6625202c31316625ull,
0x09202020203b3731ull,0x646461090a202f2full,0x662509203233662eull,0x202c386625202c39ull,
0x2020203b31326625ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300939343109ull,
0x203233662e6c756dull,0x25202c3232662509ull,0x3b356625202c3566ull,0x2f09202020202020ull,
0x2e6c756d090a202full,0x3166250920323366ull,0x202c396625202c31ull,0x202020203b396625ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3332662509ull,0x326625202c313166ull,
0x2f09202020203b32ull,0x2e766f6d090a202full,0x3266250920323366ull,0x3830346630202c34ull,
0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,
0x2c33326625202c39ull,0x09203b3432662520ull,0x252140090a202f2full,0x0920617262203970ull,
0x32335f345f744c24ull,0x202020203b383532ull,0x0a202f2f09202020ull,0x3233732e62757309ull,
0x2c39303172250920ull,0x202c383031722520ull,0x0920202020203b33ull,0x617262090a202f2full,
0x4c240920696e752eull,0x3b3835325f345f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x32335f345f744c24ull,0x2f2f200a3a383532ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x393220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,
0x31325f345f744c24ull,0x6f6c2e090a323637ull,0x3535310935310963ull,0x2e6c756d090a3009ull,
0x3166250920323366ull,0x202c356625202c34ull,0x202020203b396625ull,0x090a202f2f092020ull,
0x203233662e646461ull,0x25202c3532662509ull,0x316625202c343166ull,0x2f09202020203b34ull,
0x2e646461090a202full,0x3566250920323366ull,0x25202c346625202cull,0x202020203b353266ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009363531ull,0x09203233662e6275ull,
0x6625202c36326625ull,0x32326625202c3131ull,0x2f2f09202020203bull,0x662e646461090a20ull,
0x2c39662509203233ull,0x6625202c38662520ull,0x20202020203b3632ull,0x2e090a202f2f0920ull,
0x3109353109636f6cull,0x756d090a30093735ull,0x2509203233662e6cull,0x356625202c373266ull,
0x20203b356625202cull,0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c31316625092032ull,
0x6625202c39662520ull,0x2020202020203b39ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x316625202c383266ull,0x3b37326625202c31ull,0x202f2f0920202020ull,0x33662e766f6d090aull,
0x2c39326625092032ull,0x3030383034663020ull,0x202020203b303030ull,0x73090a34202f2f09ull,
0x662e74672e707465ull,0x3031702509203233ull,0x202c38326625202cull,0x2f2f093b39326625ull,
0x3170252140090a20ull,0x2409206172622030ull,0x3732335f345f744cull,0x20202020203b3037ull,
0x73090a202f2f0920ull,0x09203233732e6275ull,0x25202c3930317225ull,0x3b34202c38303172ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x20203b3835325f34ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x373732335f345f74ull,0x6c3c2f2f200a3a30ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36393220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f345f74ull,0x09636f6c2e090a32ull,
0x3009333631093531ull,0x33662e6c756d090aull,0x2c34316625092032ull,0x6625202c35662520ull,
0x2020202020203b39ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x316625202c303366ull,
0x3b34316625202c34ull,0x202f2f0920202020ull,0x33662e646461090aull,0x202c356625092032ull,
0x336625202c346625ull,0x2020202020203b30ull,0x6c2e090a202f2f09ull,0x363109353109636full,
0x627573090a300934ull,0x662509203233662eull,0x31316625202c3133ull,0x203b37326625202cull,
0x0a202f2f09202020ull,0x3233662e64646109ull,0x25202c3966250920ull,0x31336625202c3866ull,
0x092020202020203bull,0x6f6c2e090a202f2full,0x3536310935310963ull,0x2e6c756d090a3009ull,
0x3366250920323366ull,0x202c356625202c32ull,0x202020203b356625ull,0x090a202f2f092020ull,
0x203233662e6c756dull,0x25202c3131662509ull,0x3b396625202c3966ull,0x2f09202020202020ull,
0x2e646461090a202full,0x3366250920323366ull,0x2c31316625202c33ull,0x20203b3233662520ull,
0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3433662509ull,0x3030303038303466ull,
0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,0x202c313170250920ull,
0x6625202c33336625ull,0x0a202f2f093b3433ull,0x2031317025214009ull,0x744c240920617262ull,
0x32383233335f345full,0x092020202020203bull,0x627573090a202f2full,0x722509203233732eull,
0x317225202c393031ull,0x20203b35202c3830ull,0x0a202f2f09202020ull,0x696e752e61726209ull,
0x5f345f744c240920ull,0x202020203b383532ull,0x0920202020202020ull,0x5f744c240a202f2full,
0x3a32383233335f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3639322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a32363731325f34ull,0x353109636f6c2e09ull,0x090a300931373109ull,0x203233662e6c756dull,
0x25202c3431662509ull,0x3b396625202c3566ull,0x2f09202020202020ull,0x2e646461090a202full,
0x3366250920323366ull,0x2c34316625202c35ull,0x20203b3431662520ull,0x090a202f2f092020ull,
0x203233662e646461ull,0x6625202c35662509ull,0x3b35336625202c34ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0932373109353109ull,0x662e627573090a30ull,0x3633662509203233ull,
0x202c31316625202cull,0x2020203b32336625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,
0x386625202c396625ull,0x203b36336625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,
0x3009333731093531ull,0x33662e6c756d090aull,0x2c37336625092032ull,0x6625202c35662520ull,
0x2020202020203b35ull,0x756d090a202f2f09ull,0x2509203233662e6cull,0x396625202c313166ull,
0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,0x2c38336625092032ull,
0x25202c3131662520ull,0x202020203b373366ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,
0x346630202c393366ull,0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,
0x09203233662e7467ull,0x6625202c32317025ull,0x39336625202c3833ull,0x40090a202f2f093bull,
0x7262203231702521ull,0x345f744c24092061ull,0x203b34393733335full,0x2f2f092020202020ull,
0x732e627573090a20ull,0x3031722509203233ull,0x3830317225202c39ull,0x202020203b36202cull,
0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f345f744c24ull,0x2020202020203b38ull,
0x2f2f092020202020ull,0x5f345f744c240a20ull,0x200a3a3439373333ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363932ull,
0x656c6562616c2064ull,0x5f345f744c242064ull,0x2e090a3236373132ull,0x3109353109636f6cull,
0x756d090a30093937ull,0x2509203233662e6cull,0x356625202c343166ull,0x20203b396625202cull,
0x202f2f0920202020ull,0x33662e646461090aull,0x2c30346625092032ull,0x25202c3431662520ull,
0x202020203b343166ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c346625202c3566ull,
0x20203b3034662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093038310935ull,
0x3233662e62757309ull,0x202c313466250920ull,0x6625202c31316625ull,0x09202020203b3733ull,
0x646461090a202f2full,0x662509203233662eull,0x202c386625202c39ull,0x2020203b31346625ull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300931383109ull,0x203233662e6c756dull,
0x25202c3234662509ull,0x3b356625202c3566ull,0x2f09202020202020ull,0x2e6c756d090a202full,
0x3166250920323366ull,0x202c396625202c31ull,0x202020203b396625ull,0x090a202f2f092020ull,
0x203233662e646461ull,0x25202c3334662509ull,0x346625202c313166ull,0x2f09202020203b32ull,
0x2e766f6d090a202full,0x3466250920323366ull,0x3830346630202c34ull,0x20203b3030303030ull,
0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,0x33346625202c3331ull,
0x093b34346625202cull,0x252140090a202f2full,0x2061726220333170ull,0x335f345f744c2409ull,
0x2020203b36303334ull,0x0a202f2f09202020ull,0x3233732e62757309ull,0x2c39303172250920ull,
0x202c383031722520ull,0x0920202020203b37ull,0x617262090a202f2full,0x4c240920696e752eull,
0x3b3835325f345f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x34335f345f744c24ull,
0x2f2f200a3a363033ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x393220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,0x31325f345f744c24ull,
0x6f6c2e090a323637ull,0x3738310935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,
0x202c356625202c34ull,0x202020203b396625ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x25202c3534662509ull,0x316625202c343166ull,0x2f09202020203b34ull,0x2e646461090a202full,
0x3566250920323366ull,0x25202c346625202cull,0x202020203b353466ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x73090a3009383831ull,0x09203233662e6275ull,0x6625202c36346625ull,
0x32346625202c3131ull,0x2f2f09202020203bull,0x662e646461090a20ull,0x2c39662509203233ull,
0x6625202c38662520ull,0x20202020203b3634ull,0x2e090a202f2f0920ull,0x3109353109636f6cull,
0x756d090a30093938ull,0x2509203233662e6cull,0x356625202c373466ull,0x20203b356625202cull,
0x202f2f0920202020ull,0x33662e6c756d090aull,0x2c31316625092032ull,0x6625202c39662520ull,
0x2020202020203b39ull,0x6461090a202f2f09ull,0x2509203233662e64ull,0x316625202c383466ull,
0x3b37346625202c31ull,0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c39346625092032ull,
0x3030383034663020ull,0x202020203b303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3431702509203233ull,0x202c38346625202cull,0x2f2f093b39346625ull,0x3170252140090a20ull,
0x2409206172622034ull,0x3834335f345f744cull,0x20202020203b3831ull,0x73090a202f2f0920ull,
0x09203233732e6275ull,0x25202c3930317225ull,0x3b38202c38303172ull,0x2f2f092020202020ull,
0x752e617262090a20ull,0x5f744c240920696eull,0x20203b3835325f34ull,0x2020202020202020ull,
0x4c240a202f2f0920ull,0x313834335f345f74ull,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36393220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x363731325f345f74ull,0x09636f6c2e090a32ull,0x3009353931093531ull,
0x33662e6c756d090aull,0x2c34316625092032ull,0x6625202c35662520ull,0x2020202020203b39ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x316625202c303566ull,0x3b34316625202c34ull,
0x202f2f0920202020ull,0x33662e646461090aull,0x202c356625092032ull,0x356625202c346625ull,
0x2020202020203b30ull,0x6c2e090a202f2f09ull,0x393109353109636full,0x627573090a300936ull,
0x662509203233662eull,0x31316625202c3135ull,0x203b37346625202cull,0x0a202f2f09202020ull,
0x3233662e64646109ull,0x25202c3966250920ull,0x31356625202c3866ull,0x092020202020203bull,
0x6f6c2e090a202f2full,0x3739310935310963ull,0x2e6c756d090a3009ull,0x3566250920323366ull,
0x202c356625202c32ull,0x202020203b356625ull,0x090a202f2f092020ull,0x203233662e6c756dull,
0x25202c3131662509ull,0x3b396625202c3966ull,0x2f09202020202020ull,0x2e646461090a202full,
0x3566250920323366ull,0x2c31316625202c33ull,0x20203b3235662520ull,0x090a202f2f092020ull,
0x203233662e766f6dull,0x30202c3435662509ull,0x3030303038303466ull,0x2f09202020203b30ull,
0x746573090a34202full,0x3233662e74672e70ull,0x202c353170250920ull,0x6625202c33356625ull,
0x0a202f2f093b3435ull,0x2035317025214009ull,0x744c240920617262ull,0x30333335335f345full,
0x092020202020203bull,0x627573090a202f2full,0x722509203233732eull,0x317225202c393031ull,
0x20203b39202c3830ull,0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f345f744c240920ull,
0x202020203b383532ull,0x0920202020202020ull,0x5f744c240a202f2full,0x3a30333335335f34ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3639322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a32363731325f34ull,
0x353109636f6c2e09ull,0x090a300933303209ull,0x203233662e6c756dull,0x25202c3431662509ull,
0x3b396625202c3566ull,0x2f09202020202020ull,0x2e646461090a202full,0x3566250920323366ull,
0x2c34316625202c35ull,0x20203b3431662520ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x6625202c35662509ull,0x3b35356625202c34ull,0x2f09202020202020ull,0x636f6c2e090a202full,
0x0934303209353109ull,0x662e627573090a30ull,0x3635662509203233ull,0x202c31316625202cull,
0x2020203b32356625ull,0x61090a202f2f0920ull,0x09203233662e6464ull,0x386625202c396625ull,
0x203b36356625202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009353032093531ull,
0x33662e6c756d090aull,0x2c37356625092032ull,0x6625202c35662520ull,0x2020202020203b35ull,
0x756d090a202f2f09ull,0x2509203233662e6cull,0x396625202c313166ull,0x20203b396625202cull,
0x202f2f0920202020ull,0x33662e646461090aull,0x2c38356625092032ull,0x25202c3131662520ull,
0x202020203b373566ull,0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x346630202c393566ull,
0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,0x09203233662e7467ull,
0x6625202c36317025ull,0x39356625202c3835ull,0x40090a202f2f093bull,0x7262203631702521ull,
0x345f744c24092061ull,0x203b32343835335full,0x2f2f092020202020ull,0x732e627573090a20ull,
0x3031722509203233ull,0x3830317225202c39ull,0x2020203b3031202cull,0x62090a202f2f0920ull,
0x0920696e752e6172ull,0x35325f345f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,
0x5f345f744c240a20ull,0x200a3a3234383533ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363932ull,0x656c6562616c2064ull,
0x5f345f744c242064ull,0x2e090a3236373132ull,0x3209353109636f6cull,0x756d090a30093131ull,
0x2509203233662e6cull,0x356625202c343166ull,0x20203b396625202cull,0x202f2f0920202020ull,
0x33662e646461090aull,0x2c30366625092032ull,0x25202c3431662520ull,0x202020203b343166ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c346625202c3566ull,0x20203b3036662520ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093231320935ull,0x3233662e62757309ull,
0x202c313666250920ull,0x6625202c31316625ull,0x09202020203b3735ull,0x646461090a202f2full,
0x662509203233662eull,0x202c386625202c39ull,0x2020203b31366625ull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300933313209ull,0x203233662e6c756dull,0x25202c3236662509ull,
0x3b356625202c3566ull,0x2f09202020202020ull,0x2e6c756d090a202full,0x3166250920323366ull,
0x202c396625202c31ull,0x202020203b396625ull,0x090a202f2f092020ull,0x203233662e646461ull,
0x25202c3336662509ull,0x366625202c313166ull,0x2f09202020203b32ull,0x2e766f6d090a202full,
0x3666250920323366ull,0x3830346630202c34ull,0x20203b3030303030ull,0x0a34202f2f092020ull,
0x74672e7074657309ull,0x702509203233662eull,0x33366625202c3731ull,0x093b34366625202cull,
0x252140090a202f2full,0x2061726220373170ull,0x335f345f744c2409ull,0x2020203b34353336ull,
0x0a202f2f09202020ull,0x3233732e62757309ull,0x2c39303172250920ull,0x202c383031722520ull,
0x09202020203b3131ull,0x617262090a202f2full,0x4c240920696e752eull,0x3b3835325f345f74ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x36335f345f744c24ull,0x2f2f200a3a343533ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x393220656e696c20ull,
0x2064616568202c36ull,0x2064656c6562616cull,0x31325f345f744c24ull,0x6f6c2e090a323637ull,
0x3931320935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,0x202c356625202c34ull,
0x202020203b396625ull,0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3536662509ull,
0x316625202c343166ull,0x2f09202020203b34ull,0x2e646461090a202full,0x3566250920323366ull,
0x25202c346625202cull,0x202020203b353666ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x73090a3009303232ull,0x09203233662e6275ull,0x6625202c36366625ull,0x32366625202c3131ull,
0x2f2f09202020203bull,0x662e646461090a20ull,0x2c39662509203233ull,0x6625202c38662520ull,
0x20202020203b3636ull,0x2e090a202f2f0920ull,0x3209353109636f6cull,0x756d090a30093132ull,
0x2509203233662e6cull,0x356625202c373666ull,0x20203b356625202cull,0x202f2f0920202020ull,
0x33662e6c756d090aull,0x2c31316625092032ull,0x6625202c39662520ull,0x2020202020203b39ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x316625202c383666ull,0x3b37366625202c31ull,
0x202f2f0920202020ull,0x33662e766f6d090aull,0x2c39366625092032ull,0x3030383034663020ull,
0x202020203b303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3831702509203233ull,
0x202c38366625202cull,0x2f2f093b39366625ull,0x3170252140090a20ull,0x2409206172622038ull,
0x3836335f345f744cull,0x20202020203b3636ull,0x73090a202f2f0920ull,0x09203233732e6275ull,
0x25202c3930317225ull,0x3231202c38303172ull,0x2f2f09202020203bull,0x752e617262090a20ull,
0x5f744c240920696eull,0x20203b3835325f34ull,0x2020202020202020ull,0x4c240a202f2f0920ull,
0x363836335f345f74ull,0x6c3c2f2f200a3a36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c36393220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x363731325f345f74ull,0x09636f6c2e090a32ull,0x3009373232093531ull,0x33662e6c756d090aull,
0x2c34316625092032ull,0x6625202c35662520ull,0x2020202020203b39ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x316625202c303766ull,0x3b34316625202c34ull,0x202f2f0920202020ull,
0x33662e646461090aull,0x202c356625092032ull,0x376625202c346625ull,0x2020202020203b30ull,
0x6c2e090a202f2f09ull,0x323209353109636full,0x627573090a300938ull,0x662509203233662eull,
0x31316625202c3137ull,0x203b37366625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,
0x25202c3966250920ull,0x31376625202c3866ull,0x092020202020203bull,0x6f6c2e090a202f2full,
0x3932320935310963ull,0x2e6c756d090a3009ull,0x3766250920323366ull,0x202c356625202c32ull,
0x202020203b356625ull,0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3131662509ull,
0x3b396625202c3966ull,0x2f09202020202020ull,0x2e646461090a202full,0x3766250920323366ull,
0x2c31316625202c33ull,0x20203b3237662520ull,0x090a202f2f092020ull,0x203233662e766f6dull,
0x30202c3437662509ull,0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,
0x3233662e74672e70ull,0x202c393170250920ull,0x6625202c33376625ull,0x0a202f2f093b3437ull,
0x2039317025214009ull,0x744c240920617262ull,0x38373337335f345full,0x092020202020203bull,
0x627573090a202f2full,0x722509203233732eull,0x317225202c393031ull,0x203b3331202c3830ull,
0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f345f744c240920ull,0x202020203b383532ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x3a38373337335f34ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32363731325f34ull,0x353109636f6c2e09ull,
0x090a300935333209ull,0x203233662e6c756dull,0x25202c3431662509ull,0x3b396625202c3566ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3766250920323366ull,0x2c34316625202c35ull,
0x20203b3431662520ull,0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c35662509ull,
0x3b35376625202c34ull,0x2f09202020202020ull,0x636f6c2e090a202full,0x0936333209353109ull,
0x662e627573090a30ull,0x3637662509203233ull,0x202c31316625202cull,0x2020203b32376625ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x386625202c396625ull,0x203b36376625202cull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009373332093531ull,0x33662e6c756d090aull,
0x2c37376625092032ull,0x6625202c35662520ull,0x2020202020203b35ull,0x756d090a202f2f09ull,
0x2509203233662e6cull,0x396625202c313166ull,0x20203b396625202cull,0x202f2f0920202020ull,
0x33662e646461090aull,0x2c38376625092032ull,0x25202c3131662520ull,0x202020203b373766ull,
0x6f6d090a202f2f09ull,0x2509203233662e76ull,0x346630202c393766ull,0x3b30303030303830ull,
0x202f2f0920202020ull,0x2e70746573090a34ull,0x09203233662e7467ull,0x6625202c30327025ull,
0x39376625202c3837ull,0x40090a202f2f093bull,0x7262203032702521ull,0x345f744c24092061ull,
0x203b30393837335full,0x2f2f092020202020ull,0x732e627573090a20ull,0x3031722509203233ull,
0x3830317225202c39ull,0x2020203b3431202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x35325f345f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,0x5f345f744c240a20ull,
0x200a3a3039383733ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c363932ull,0x656c6562616c2064ull,0x5f345f744c242064ull,
0x2e090a3236373132ull,0x3209353109636f6cull,0x756d090a30093334ull,0x2509203233662e6cull,
0x356625202c343166ull,0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,
0x2c30386625092032ull,0x25202c3431662520ull,0x202020203b343166ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x2c346625202c3566ull,0x20203b3038662520ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093434320935ull,0x3233662e62757309ull,0x202c313866250920ull,
0x6625202c31316625ull,0x09202020203b3737ull,0x646461090a202f2full,0x662509203233662eull,
0x202c386625202c39ull,0x2020203b31386625ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300935343209ull,0x203233662e6c756dull,0x25202c3238662509ull,0x3b356625202c3566ull,
0x2f09202020202020ull,0x2e6c756d090a202full,0x3166250920323366ull,0x202c396625202c31ull,
0x202020203b396625ull,0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3338662509ull,
0x386625202c313166ull,0x2f09202020203b32ull,0x2e766f6d090a202full,0x3866250920323366ull,
0x3830346630202c34ull,0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,
0x702509203233662eull,0x33386625202c3132ull,0x093b34386625202cull,0x252140090a202f2full,
0x2061726220313270ull,0x335f345f744c2409ull,0x2020203b32303438ull,0x0a202f2f09202020ull,
0x3233732e62757309ull,0x2c39303172250920ull,0x202c383031722520ull,0x09202020203b3531ull,
0x617262090a202f2full,0x4c240920696e752eull,0x3b3835325f345f74ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x38335f345f744c24ull,0x2f2f200a3a323034ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x393220656e696c20ull,0x2064616568202c36ull,
0x2064656c6562616cull,0x31325f345f744c24ull,0x6f6c2e090a323637ull,0x3135320935310963ull,
0x2e6c756d090a3009ull,0x3166250920323366ull,0x202c356625202c34ull,0x202020203b396625ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x25202c3538662509ull,0x316625202c343166ull,
0x2f09202020203b34ull,0x2e646461090a202full,0x3566250920323366ull,0x25202c346625202cull,
0x202020203b353866ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009323532ull,
0x09203233662e6275ull,0x6625202c36386625ull,0x32386625202c3131ull,0x2f2f09202020203bull,
0x662e646461090a20ull,0x2c39662509203233ull,0x6625202c38662520ull,0x20202020203b3638ull,
0x2e090a202f2f0920ull,0x3209353109636f6cull,0x756d090a30093335ull,0x2509203233662e6cull,
0x356625202c373866ull,0x20203b356625202cull,0x202f2f0920202020ull,0x33662e6c756d090aull,
0x2c31316625092032ull,0x6625202c39662520ull,0x2020202020203b39ull,0x6461090a202f2f09ull,
0x2509203233662e64ull,0x316625202c383866ull,0x3b37386625202c31ull,0x202f2f0920202020ull,
0x33662e766f6d090aull,0x2c39386625092032ull,0x3030383034663020ull,0x202020203b303030ull,
0x73090a34202f2f09ull,0x662e74672e707465ull,0x3232702509203233ull,0x202c38386625202cull,
0x2f2f093b39386625ull,0x3270252140090a20ull,0x2409206172622032ull,0x3938335f345f744cull,
0x20202020203b3431ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x25202c3930317225ull,
0x3631202c38303172ull,0x2f2f09202020203bull,0x752e617262090a20ull,0x5f744c240920696eull,
0x20203b3835325f34ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x313938335f345f74ull,
0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36393220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f345f74ull,
0x09636f6c2e090a32ull,0x3009393532093531ull,0x33662e6c756d090aull,0x2c34316625092032ull,
0x6625202c35662520ull,0x2020202020203b39ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x316625202c303966ull,0x3b34316625202c34ull,0x202f2f0920202020ull,0x33662e646461090aull,
0x202c356625092032ull,0x396625202c346625ull,0x2020202020203b30ull,0x6c2e090a202f2f09ull,
0x363209353109636full,0x627573090a300930ull,0x662509203233662eull,0x31316625202c3139ull,
0x203b37386625202cull,0x0a202f2f09202020ull,0x3233662e64646109ull,0x25202c3966250920ull,
0x31396625202c3866ull,0x092020202020203bull,0x6f6c2e090a202f2full,0x3136320935310963ull,
0x2e6c756d090a3009ull,0x3966250920323366ull,0x202c356625202c32ull,0x202020203b356625ull,
0x090a202f2f092020ull,0x203233662e6c756dull,0x25202c3131662509ull,0x3b396625202c3966ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3966250920323366ull,0x2c31316625202c33ull,
0x20203b3239662520ull,0x090a202f2f092020ull,0x203233662e766f6dull,0x30202c3439662509ull,
0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,
0x202c333270250920ull,0x6625202c33396625ull,0x0a202f2f093b3439ull,0x2033327025214009ull,
0x744c240920617262ull,0x36323439335f345full,0x092020202020203bull,0x627573090a202f2full,
0x722509203233732eull,0x317225202c393031ull,0x203b3731202c3830ull,0x0a202f2f09202020ull,
0x696e752e61726209ull,0x5f345f744c240920ull,0x202020203b383532ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x3a36323439335f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32363731325f34ull,0x353109636f6c2e09ull,0x090a300937363209ull,
0x203233662e6c756dull,0x25202c3431662509ull,0x3b396625202c3566ull,0x2f09202020202020ull,
0x2e646461090a202full,0x3966250920323366ull,0x2c34316625202c35ull,0x20203b3431662520ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c35662509ull,0x3b35396625202c34ull,
0x2f09202020202020ull,0x636f6c2e090a202full,0x0938363209353109ull,0x662e627573090a30ull,
0x3639662509203233ull,0x202c31316625202cull,0x2020203b32396625ull,0x61090a202f2f0920ull,
0x09203233662e6464ull,0x386625202c396625ull,0x203b36396625202cull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009393632093531ull,0x33662e6c756d090aull,0x2c37396625092032ull,
0x6625202c35662520ull,0x2020202020203b35ull,0x756d090a202f2f09ull,0x2509203233662e6cull,
0x396625202c313166ull,0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,
0x2c38396625092032ull,0x25202c3131662520ull,0x202020203b373966ull,0x6f6d090a202f2f09ull,
0x2509203233662e76ull,0x346630202c393966ull,0x3b30303030303830ull,0x202f2f0920202020ull,
0x2e70746573090a34ull,0x09203233662e7467ull,0x6625202c34327025ull,0x39396625202c3839ull,
0x40090a202f2f093bull,0x7262203432702521ull,0x345f744c24092061ull,0x203b38333939335full,
0x2f2f092020202020ull,0x732e627573090a20ull,0x3031722509203233ull,0x3830317225202c39ull,
0x2020203b3831202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,0x35325f345f744c24ull,
0x2020202020203b38ull,0x2f2f092020202020ull,0x5f345f744c240a20ull,0x200a3a3833393933ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c363932ull,0x656c6562616c2064ull,0x5f345f744c242064ull,0x2e090a3236373132ull,
0x3209353109636f6cull,0x756d090a30093537ull,0x2509203233662e6cull,0x356625202c343166ull,
0x20203b396625202cull,0x202f2f0920202020ull,0x33662e646461090aull,0x3030316625092032ull,
0x202c34316625202cull,0x2020203b34316625ull,0x6461090a202f2f09ull,0x2509203233662e64ull,
0x2c346625202c3566ull,0x203b303031662520ull,0x202f2f0920202020ull,0x3109636f6c2e090aull,
0x0a30093637320935ull,0x3233662e62757309ull,0x2c31303166250920ull,0x25202c3131662520ull,
0x092020203b373966ull,0x646461090a202f2full,0x662509203233662eull,0x202c386625202c39ull,
0x20203b3130316625ull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300937373209ull,
0x203233662e6c756dull,0x202c323031662509ull,0x356625202c356625ull,0x2f0920202020203bull,
0x2e6c756d090a202full,0x3166250920323366ull,0x202c396625202c31ull,0x202020203b396625ull,
0x090a202f2f092020ull,0x203233662e646461ull,0x202c333031662509ull,0x6625202c31316625ull,
0x2f0920203b323031ull,0x2e766f6d090a202full,0x3166250920323366ull,0x30346630202c3430ull,
0x203b303030303038ull,0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,
0x30316625202c3532ull,0x3430316625202c33ull,0x40090a202f2f093bull,0x7262203532702521ull,
0x345f744c24092061ull,0x203b30353430345full,0x2f2f092020202020ull,0x732e627573090a20ull,
0x3031722509203233ull,0x3830317225202c39ull,0x2020203b3931202cull,0x62090a202f2f0920ull,
0x0920696e752e6172ull,0x35325f345f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,
0x5f345f744c240a20ull,0x200a3a3035343034ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363932ull,0x656c6562616c2064ull,
0x5f345f744c242064ull,0x2e090a3236373132ull,0x3209353109636f6cull,0x756d090a30093338ull,
0x2509203233662e6cull,0x356625202c343166ull,0x20203b396625202cull,0x202f2f0920202020ull,
0x33662e646461090aull,0x3530316625092032ull,0x202c34316625202cull,0x2020203b34316625ull,
0x6461090a202f2f09ull,0x2509203233662e64ull,0x2c346625202c3566ull,0x203b353031662520ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093438320935ull,0x3233662e62757309ull,
0x2c36303166250920ull,0x25202c3131662520ull,0x0920203b32303166ull,0x646461090a202f2full,
0x662509203233662eull,0x202c386625202c39ull,0x20203b3630316625ull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300935383209ull,0x203233662e6c756dull,0x202c373031662509ull,
0x356625202c356625ull,0x2f0920202020203bull,0x636f6c2e090a202full,0x0939383209353109ull,
0x732e627573090a30ull,0x3031722509203233ull,0x3830317225202c38ull,0x2020203b3032202cull,
0x2e090a202f2f0920ull,0x3209353109636f6cull,0x6f6d090a30093338ull,0x2509203233752e76ull,
0x3b30202c30313172ull,0x2020202020202020ull,0x202f2f0920202020ull,0x6c2e70746573090aull,
0x2509203233732e65ull,0x317225202c363270ull,0x31317225202c3830ull,0x090a202f2f093b30ull,
0x7262203632702540ull,0x5f345f4c24092061ull,0x20203b3630393732ull,0x2f09202020202020ull,
0x6c3c2f2f200a202full,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36393220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f345f74ull,
0x662e6c756d090a32ull,0x3131662509203233ull,0x25202c396625202cull,0x20202020203b3966ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x25202c3830316625ull,0x316625202c313166ull,
0x2f2f0920203b3730ull,0x662e766f6d090a20ull,0x3031662509203233ull,0x3830346630202c39ull,
0x20203b3030303030ull,0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3270250920323366ull,
0x3830316625202c37ull,0x3b3930316625202cull,0x2140090a202f2f09ull,0x6172622037327025ull,
0x325f345f4c240920ull,0x2020203b30353637ull,0x202f2f0920202020ull,0x37325f345f4c240aull,
0x6f6d090a3a363039ull,0x2509203233732e76ull,0x7225202c39303172ull,0x202020203b383031ull,
0x202f2f0920202020ull,0x6e752e617262090aull,0x345f744c24092069ull,0x2020203b3835325full,
0x2020202020202020ull,0x5f4c240a202f2f09ull,0x3a30353637325f34ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32363731325f34ull,0x353109636f6c2e09ull,
0x090a300932393209ull,0x203233662e6c756dull,0x25202c3431662509ull,0x3b396625202c3566ull,
0x2f09202020202020ull,0x2e646461090a202full,0x3166250920323366ull,0x34316625202c3031ull,
0x203b34316625202cull,0x090a202f2f092020ull,0x203233662e646461ull,0x6625202c35662509ull,
0x3031316625202c34ull,0x2f0920202020203bull,0x636f6c2e090a202full,0x0933393209353109ull,
0x662e627573090a30ull,0x3131662509203233ull,0x2c31316625202c31ull,0x203b373031662520ull,
0x61090a202f2f0920ull,0x09203233662e6464ull,0x386625202c396625ull,0x3b3131316625202cull,
0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009323932093531ull,0x6e752e617262090aull,
0x345f744c24092069ull,0x203b32363731325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x0a3a3835325f345full,0x363109636f6c2e09ull,0x090a300935323109ull,0x203233732e766f6dull,
0x202c313131722509ull,0x2020202020203b30ull,0x2f09202020202020ull,0x70746573090a202full,
0x203233732e74672eull,0x25202c3832702509ull,0x7225202c39303172ull,0x202f2f093b313131ull,
0x33732e627573090aull,0x3231317225092032ull,0x2c3730317225202cull,0x203b393031722520ull,
0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x3b30202c33313172ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x732e706c6573090aull,0x3131722509203233ull,0x3231317225202c34ull,
0x2c3331317225202cull,0x2f093b3832702520ull,0x2e766f6d090a202full,0x3172250920323375ull,
0x20203b30202c3531ull,0x2020202020202020ull,0x090a202f2f092020ull,0x2e71652e70746573ull,
0x3270250920323373ull,0x3431317225202c39ull,0x3b3531317225202cull,0x2540090a202f2f09ull,
0x2061726220393270ull,0x345f345f744c2409ull,0x2020203b38313231ull,0x202f2f0920202020ull,
0x3109636f6c2e090aull,0x0a30093233310936ull,0x617261702e646c09ull,0x2509203233732e6dull,
0x5f5b202c36313172ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x664930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x616d696e615f6969ull,0x6d6172466e6f6974ull,0x69202f2f093b5d65ull,0x5f5f203331363a64ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,0x74616d696e615f69ull,
0x656d6172466e6f69ull,0x6461090a3078302bull,0x2509203233732e64ull,0x7225202c37313172ull,
0x317225202c363131ull,0x202f2f09203b3431ull,0x7261702e646c090aull,0x25092038752e6d61ull,
0x5f5b202c38313172ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x664930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x726f6c6f635f6969ull,0x2f2f093b5d302b73ull,0x203431363a646920ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764566ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x6f6c6f635f69695full,0x090a3078302b7372ull,
0x732e6f6c2e6c756dull,0x3131722509203233ull,0x3731317225202c39ull,0x3b3831317225202cull,
0x7663090a202f2f09ull,0x3233752e38752e74ull,0x2c30323172250920ull,0x203b393131722520ull,
0x202f2f0920202020ull,0x3109636f6c2e090aull,0x0a30093333310936ull,0x617261702e646c09ull,
0x7225092038752e6dull,0x5f5f5b202c313231ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x73726f6c6f635f69ull,0x202f2f093b5d312bull,0x5f203531363a6469ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x664930316d735f31ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x726f6c6f635f6969ull,
0x6d090a3178302b73ull,0x33732e6f6c2e6c75ull,0x3232317225092032ull,0x2c3731317225202cull,
0x093b313231722520ull,0x747663090a202f2full,0x203233752e38752eull,0x202c333231722509ull,
0x20203b3232317225ull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x090a300934333109ull,
0x6d617261702e646cull,0x317225092038752eull,0x635f5f5b202c3432ull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x69695f30535f3253ull,0x2b73726f6c6f635full,0x69202f2f093b5d32ull,
0x5f5f203631363a64ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,
0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,
0x73726f6c6f635f69ull,0x756d090a3278302bull,0x3233732e6f6c2e6cull,0x2c35323172250920ull,
0x202c373131722520ull,0x2f093b3432317225ull,0x2e747663090a202full,0x09203233752e3875ull,
0x25202c3632317225ull,0x2020203b35323172ull,0x090a202f2f092020ull,0x20696e752e617262ull,
0x345f345f744c2409ull,0x2020203b32363930ull,0x2f09202020202020ull,0x345f744c240a202full,
0x0a3a38313231345full,0x363109636f6c2e09ull,0x090a300938333109ull,0x203233752e766f6dull,
0x202c363231722509ull,0x2020202020203b30ull,0x2f09202020202020ull,0x2e766f6d090a202full,
0x3172250920323375ull,0x20203b30202c3332ull,0x2020202020202020ull,0x090a202f2f092020ull,
0x203233752e766f6dull,0x202c303231722509ull,0x2020202020203b30ull,0x2f09202020202020ull,
0x345f744c240a202full,0x0a3a32363930345full,0x363109636f6c2e09ull,0x090a300934343109ull,
0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c373231ull,0x6d72617061647563ull,
0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x695f30535f32535full,0x5d656d6172665f69ull,0x3a6469202f2f093bull,
0x75635f5f20303835ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f31746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f69695f30535f32ull,
0x78302b656d617266ull,0x732e646461090a30ull,0x3231722509203233ull,0x3732317225202c38ull,
0x202020203b31202cull,0x73090a202f2f0920ull,0x09203233732e7268ull,0x25202c3932317225ull,
0x3133202c38323172ull,0x2f2f09202020203bull,0x732e766f6d090a20ull,0x3331722509203233ull,
0x2020203b31202c30ull,0x2020202020202020ull,0x61090a202f2f0920ull,0x09203233622e646eull,
0x25202c3133317225ull,0x7225202c39323172ull,0x2f2f09203b303331ull,0x732e646461090a20ull,
0x3331722509203233ull,0x3133317225202c32ull,0x3b3832317225202cull,0x73090a202f2f0920ull,
0x09203233732e7268ull,0x25202c3333317225ull,0x3b31202c32333172ull,0x2f2f092020202020ull,
0x6c2e6c756d090a20ull,0x2509203233732e6full,0x7225202c34333172ull,0x317225202c373231ull,
0x090a202f2f093b37ull,0x203233732e646461ull,0x202c353331722509ull,0x25202c3032317225ull,
0x2f09203b34333172ull,0x2e646461090a202full,0x3172250920323373ull,0x33317225202c3633ull,
0x3533317225202c33ull,0x090a202f2f09203bull,0x203233732e766964ull,0x202c373331722509ull,
0x25202c3633317225ull,0x2f09203b38323172ull,0x636f6c2e090a202full,0x0935343109363109ull,
0x6c2e6c756d090a30ull,0x2509203233732e6full,0x7225202c38333172ull,0x317225202c373231ull,
0x090a202f2f093b38ull,0x203233732e646461ull,0x202c393331722509ull,0x25202c3332317225ull,
0x2f09203b38333172ull,0x2e646461090a202full,0x3172250920323373ull,0x33317225202c3034ull,
0x3933317225202c33ull,0x090a202f2f09203bull,0x203233732e766964ull,0x202c313431722509ull,
0x25202c3034317225ull,0x2f09203b38323172ull,0x672e7473090a202full,0x32762e6c61626f6cull,
0x72255b092038752eull,0x7b202c5d302b3464ull,0x72252c3733317225ull,0x2f2f093b7d313431ull,
0x09636f6c2e090a20ull,0x3009363431093631ull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x317225202c323431ull,0x39317225202c3732ull,0x61090a202f2f093bull,0x09203233732e6464ull,
0x25202c3334317225ull,0x7225202c36323172ull,0x2f2f09203b323431ull,0x732e646461090a20ull,
0x3431722509203233ull,0x3333317225202c34ull,0x3b3334317225202cull,0x64090a202f2f0920ull,
0x09203233732e7669ull,0x25202c3534317225ull,0x7225202c34343172ull,0x2f2f09203b383231ull,
0x6c672e7473090a20ull,0x2038752e6c61626full,0x322b346472255b09ull,0x3534317225202c5dull,
0x3a6469202f2f093bull,0x5f744c240a393136ull,0x3a32323730335f34ull,0x325f345f744c240aull,
0x2e090a3a32363138ull,0x3109363109636f6cull,0x7865090a30093934ull,0x20202020203b7469ull,
0x2020202020202020ull,0x2020202020202020ull,0x202f2f0920202020ull,0x646e6557444c240aull,
0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x695f30535f32535full,0x2f2f207d090a3a69ull,0x6e614d36315a5f20ull,
0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x746e652e090a0a69ull,0x4d36315a5f207972ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x09090a282069695full,0x2e206d617261702eull,0x75635f5f20343675ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f69695f30535f32ull,0x2e09090a2c747364ull,0x732e206d61726170ull,
0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x695f69695f30535full,
0x090a2c576567616dull,0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x69695f30535f3253ull,0x2c486567616d695full,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x636e7572635f6969ull,0x61702e09090a2c68ull,0x3436662e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x664f785f69695f30ull,0x61702e09090a2c66ull,
0x3436662e206d6172ull,0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x664f795f69695f30ull,0x61702e09090a2c66ull,0x3436662e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x6163735f69695f30ull,0x702e09090a2c656cull,
0x6c612e206d617261ull,0x622e2034206e6769ull,0x616475635f5f2038ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x6f635f69695f3053ull,0x2c5d345b73726f6cull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x656d6172665f6969ull,0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x6d696e615f69695full,0x6172466e6f697461ull,
0x090a7b090a29656dull,0x31752e206765722eull,0x3e363c6872252036ull,0x206765722e090a3bull,
0x3c7225203233752eull,0x2e090a3b3e373431ull,0x3436752e20676572ull,0x3e32313c64722520ull,
0x206765722e090a3bull,0x646625203436662eull,0x090a3b3e3331313cull,0x72702e206765722eull,
0x31333c7025206465ull,0x636f6c2e090a3b3eull,0x3009393909363109ull,0x5f5f3142424c240aull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x3a69695f30535f32ull,0x31752e766f6d090aull,0x2c31687225092036ull,
0x2e64696174632520ull,0x2020202020203b78ull,0x6f6d090a202f2f09ull,0x2509203631752e76ull,
0x746e25202c326872ull,0x2020203b782e6469ull,0x202f2f0920202020ull,0x69772e6c756d090aull,
0x09203631752e6564ull,0x687225202c317225ull,0x3b32687225202c31ull,0x6f6d090a202f2f09ull,
0x2509203631752e76ull,0x746325202c336872ull,0x20203b792e646961ull,0x202f2f0920202020ull,
0x31752e766f6d090aull,0x2c34687225092036ull,0x792e6469746e2520ull,0x202020202020203bull,
0x756d090a202f2f09ull,0x752e656469772e6cull,0x2c32722509203631ull,0x25202c3368722520ull,
0x202f2f093b346872ull,0x33752e747663090aull,0x2509203631752e32ull,0x64697425202c3372ull,
0x20202020203b782eull,0x6461090a202f2f09ull,0x2509203233752e64ull,0x2c337225202c3472ull,
0x2020203b31722520ull,0x202f2f0920202020ull,0x33752e747663090aull,0x2509203631752e32ull,
0x64697425202c3572ull,0x20202020203b792eull,0x6461090a202f2f09ull,0x2509203233752e64ull,
0x2c357225202c3672ull,0x2020203b32722520ull,0x202f2f0920202020ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5f5f5b202c377225ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x695f30535f32535full,0x486567616d695f69ull,0x6469202f2f093b5dull,0x635f5f203838353aull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645644930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,0x2b486567616d695full,
0x2e646c090a307830ull,0x33732e6d61726170ull,0x202c387225092032ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x616d695f69695f30ull,0x2f2f093b5d576567ull,
0x203938353a646920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x67616d695f69695full,0x090a3078302b5765ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x377225202c397225ull,0x2f093b367225202cull,0x2e67656e090a202full,0x3172250920323373ull,
0x203b397225202c30ull,0x2020202020202020ull,0x090a202f2f092020ull,0x752e74672e746573ull,
0x09203233732e3233ull,0x7225202c31317225ull,0x093b347225202c38ull,0x67656e090a202f2full,
0x722509203233732eull,0x31317225202c3231ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233622e646e6109ull,0x202c333172250920ull,0x7225202c30317225ull,0x09202020203b3231ull,
0x766f6d090a202f2full,0x722509203233752eull,0x20203b30202c3431ull,0x2020202020202020ull,
0x0a202f2f09202020ull,0x71652e7074657309ull,0x702509203233732eull,0x2c33317225202c31ull,
0x09203b3431722520ull,0x702540090a202f2full,0x2409206172622031ull,0x3138325f355f744cull,
0x20202020203b3236ull,0x0a202f2f09202020ull,0x363109636f6c2e09ull,0x090a300937303109ull,
0x732e6f6c2e6c756dull,0x3531722509203233ull,0x25202c387225202cull,0x2f092020203b3672ull,
0x2e646461090a202full,0x3172250920323373ull,0x202c347225202c36ull,0x2020203b35317225ull,
0x090a202f2f092020ull,0x6d617261702e646cull,0x722509203436752eull,0x635f5f5b202c3164ull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645644930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,0x2f093b5d7473645full,
0x3738353a6469202full,0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x7473645f69695f30ull,0x7663090a3078302bull,0x33732e3436752e74ull,0x2c32647225092032ull,
0x20203b3631722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,0x722509203436752eull,
0x32647225202c3364ull,0x202020203b34202cull,0x6461090a202f2f09ull,0x2509203436752e64ull,
0x647225202c346472ull,0x3b33647225202c31ull,0x202f2f0920202020ull,0x6f6c672e646c090aull,
0x752e34762e6c6162ull,0x373172257b092038ull,0x72252c383172252cull,0x5b202c7d5f2c3931ull,
0x3b5d302b34647225ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,0x203b30202c303272ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x2c347225202c3270ull,0x20203b3032722520ull,0x2540090a202f2f09ull,0x0920617262203270ull,
0x38325f355f744c24ull,0x202020203b303339ull,0x202f2f0920202020ull,0x6f6c672e646c090aull,
0x752e34762e6c6162ull,0x313272257b092038ull,0x72252c323272252cull,0x5b202c7d5f2c3332ull,
0x5d342d2b34647225ull,0x2e090a202f2f093bull,0x3109363109636f6cull,0x7573090a30093231ull,
0x2509203233732e62ull,0x327225202c343272ull,0x3b39317225202c33ull,0x202f2f0920202020ull,
0x33732e736261090aull,0x2c35327225092032ull,0x20203b3432722520ull,0x2020202020202020ull,
0x6f6d090a202f2f09ull,0x2509203233732e76ull,0x3b3031202c363272ull,0x2020202020202020ull,
0x202f2f0920202020ull,0x74672e746573090aull,0x3233732e3233752eull,0x202c373272250920ull,
0x7225202c35327225ull,0x0a202f2f093b3632ull,0x3233732e67656e09ull,0x202c383272250920ull,
0x2020203b37327225ull,0x0920202020202020ull,0x627573090a202f2full,0x722509203233732eull,
0x31327225202c3932ull,0x203b37317225202cull,0x0a202f2f09202020ull,0x3233732e73626109ull,
0x202c303372250920ull,0x2020203b39327225ull,0x0920202020202020ull,0x766f6d090a202f2full,
0x722509203233732eull,0x203b3031202c3133ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x2e74672e74657309ull,0x203233732e323375ull,0x25202c3233722509ull,0x337225202c303372ull,
0x090a202f2f093b31ull,0x203233732e67656eull,0x25202c3333722509ull,0x202020203b323372ull,
0x2f09202020202020ull,0x2e627573090a202full,0x3372250920323373ull,0x2c32327225202c34ull,
0x20203b3831722520ull,0x090a202f2f092020ull,0x203233732e736261ull,0x25202c3533722509ull,
0x202020203b343372ull,0x2f09202020202020ull,0x2e766f6d090a202full,0x3372250920323373ull,
0x20203b3031202c36ull,0x2020202020202020ull,0x090a202f2f092020ull,0x752e74672e746573ull,
0x09203233732e3233ull,0x7225202c37337225ull,0x36337225202c3533ull,0x6e090a202f2f093bull,
0x09203233732e6765ull,0x7225202c38337225ull,0x20202020203b3733ull,0x2f2f092020202020ull,
0x33622e726f090a20ull,0x2c39337225092032ull,0x25202c3333722520ull,0x202020203b383372ull,
0x6f090a202f2f0920ull,0x2509203233622e72ull,0x327225202c303472ull,0x3b39337225202c38ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x3b34373638325f35ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x333938325f355f74ull,0x2e766f6d090a3a30ull,
0x3472250920323373ull,0x2020203b30202c30ull,0x2020202020202020ull,0x240a202f2f092020ull,
0x3638325f355f744cull,0x646461090a3a3437ull,0x722509203233732eull,0x2c347225202c3134ull,
0x20202020203b3120ull,0x0a202f2f09202020ull,0x656c2e7074657309ull,0x702509203233732eull,
0x202c387225202c33ull,0x0920203b31347225ull,0x702540090a202f2full,0x2409206172622033ull,
0x3139325f355f744cull,0x20202020203b3638ull,0x0a202f2f09202020ull,0x626f6c672e646c09ull,
0x38752e34762e6c61ull,0x2c323472257b0920ull,0x3472252c33347225ull,0x255b202c7d5f2c34ull,
0x093b5d342b346472ull,0x6f6c2e090a202f2full,0x3431310936310963ull,0x2e627573090a3009ull,
0x3472250920323373ull,0x2c34347225202c35ull,0x20203b3931722520ull,0x090a202f2f092020ull,
0x203233732e736261ull,0x25202c3634722509ull,0x202020203b353472ull,0x2f09202020202020ull,
0x2e766f6d090a202full,0x3472250920323373ull,0x20203b3031202c37ull,0x2020202020202020ull,
0x090a202f2f092020ull,0x752e74672e746573ull,0x09203233732e3233ull,0x7225202c38347225ull,
0x37347225202c3634ull,0x6e090a202f2f093bull,0x09203233732e6765ull,0x7225202c39347225ull,
0x20202020203b3834ull,0x2f2f092020202020ull,0x732e627573090a20ull,0x3035722509203233ull,
0x202c32347225202cull,0x2020203b37317225ull,0x61090a202f2f0920ull,0x09203233732e7362ull,
0x7225202c31357225ull,0x20202020203b3035ull,0x2f2f092020202020ull,0x732e766f6d090a20ull,
0x3235722509203233ull,0x2020203b3031202cull,0x2020202020202020ull,0x73090a202f2f0920ull,
0x33752e74672e7465ull,0x2509203233732e32ull,0x357225202c333572ull,0x3b32357225202c31ull,
0x656e090a202f2f09ull,0x2509203233732e67ull,0x357225202c343572ull,0x2020202020203b33ull,
0x202f2f0920202020ull,0x33732e627573090aull,0x2c35357225092032ull,0x25202c3334722520ull,
0x202020203b383172ull,0x6261090a202f2f09ull,0x2509203233732e73ull,0x357225202c363572ull,
0x2020202020203b35ull,0x202f2f0920202020ull,0x33732e766f6d090aull,0x2c37357225092032ull,
0x202020203b303120ull,0x2020202020202020ull,0x6573090a202f2f09ull,0x3233752e74672e74ull,
0x722509203233732eull,0x36357225202c3835ull,0x093b37357225202cull,0x67656e090a202f2full,
0x722509203233732eull,0x38357225202c3935ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x203233622e726f09ull,0x25202c3036722509ull,0x357225202c343572ull,0x0920202020203b39ull,
0x2e726f090a202f2full,0x3672250920323362ull,0x2c39347225202c31ull,0x20203b3036722520ull,
0x0a202f2f09202020ull,0x3233732e64646109ull,0x202c303472250920ull,0x7225202c30347225ull,
0x09202020203b3136ull,0x5f744c240a202f2full,0x3a36383139325f35ull,0x33752e766f6d090aull,
0x2c32367225092032ull,0x20202020203b3020ull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33732e656c2e7074ull,0x202c347025092032ull,0x367225202c367225ull,0x202f2f0920203b32ull,
0x622034702540090aull,0x5f744c2409206172ull,0x3b38393639325f35ull,0x2020202020202020ull,
0x6c2e090a202f2f09ull,0x313109363109636full,0x627573090a300936ull,0x722509203233732eull,
0x36317225202c3336ull,0x20203b387225202cull,0x0a202f2f09202020ull,0x3436732e74766309ull,
0x722509203233732eull,0x33367225202c3564ull,0x092020202020203bull,0x6c756d090a202f2full,
0x203436752e6f6c2eull,0x25202c3664722509ull,0x203b34202c356472ull,0x0a202f2f09202020ull,
0x3436752e64646109ull,0x202c376472250920ull,0x7225202c31647225ull,0x09202020203b3664ull,
0x2e646c090a202f2full,0x762e6c61626f6c67ull,0x257b092038752e34ull,0x353672252c343672ull,
0x7d5f2c363672252cull,0x2b376472255b202cull,0x0a202f2f093b5d30ull,0x3233732e62757309ull,
0x202c373672250920ull,0x7225202c36367225ull,0x09202020203b3931ull,0x736261090a202f2full,
0x722509203233732eull,0x37367225202c3836ull,0x202020202020203bull,0x0a202f2f09202020ull,
0x3233732e766f6d09ull,0x202c393672250920ull,0x20202020203b3031ull,0x0920202020202020ull,
0x746573090a202f2full,0x2e3233752e74672eull,0x3772250920323373ull,0x2c38367225202c30ull,
0x2f093b3936722520ull,0x2e67656e090a202full,0x3772250920323373ull,0x3b30377225202c31ull,
0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e627573ull,0x25202c3237722509ull,
0x317225202c343672ull,0x2f09202020203b37ull,0x2e736261090a202full,0x3772250920323373ull,
0x3b32377225202c33ull,0x2020202020202020ull,0x090a202f2f092020ull,0x203233732e766f6dull,
0x31202c3437722509ull,0x2020202020203b30ull,0x2f09202020202020ull,0x2e746573090a202full,
0x732e3233752e7467ull,0x3537722509203233ull,0x202c33377225202cull,0x2f2f093b34377225ull,
0x732e67656e090a20ull,0x3637722509203233ull,0x203b35377225202cull,0x2020202020202020ull,
0x73090a202f2f0920ull,0x09203233732e6275ull,0x7225202c37377225ull,0x38317225202c3536ull,
0x2f2f09202020203bull,0x732e736261090a20ull,0x3837722509203233ull,0x203b37377225202cull,
0x2020202020202020ull,0x6d090a202f2f0920ull,0x09203233732e766full,0x3031202c39377225ull,
0x202020202020203bull,0x2f2f092020202020ull,0x672e746573090a20ull,0x33732e3233752e74ull,
0x2c30387225092032ull,0x25202c3837722520ull,0x202f2f093b393772ull,0x33732e67656e090aull,
0x2c31387225092032ull,0x20203b3038722520ull,0x2020202020202020ull,0x726f090a202f2f09ull,
0x722509203233622eull,0x36377225202c3238ull,0x203b31387225202cull,0x202f2f0920202020ull,
0x3233622e726f090aull,0x202c333872250920ull,0x7225202c31377225ull,0x20202020203b3238ull,
0x6461090a202f2f09ull,0x2509203233732e64ull,0x347225202c303472ull,0x3b33387225202c30ull,
0x202f2f0920202020ull,0x325f355f744c240aull,0x61090a3a38393639ull,0x09203233732e6464ull,
0x7225202c34387225ull,0x2020203b31202c36ull,0x2f2f092020202020ull,0x2e70746573090a20ull,
0x09203233732e656cull,0x377225202c357025ull,0x203b34387225202cull,0x40090a202f2f0920ull,
0x2061726220357025ull,0x335f355f744c2409ull,0x2020203b30313230ull,0x2f2f092020202020ull,
0x09636f6c2e090a20ull,0x3009383131093631ull,0x33732e646461090aull,0x2c35387225092032ull,
0x25202c3631722520ull,0x20202020203b3872ull,0x7663090a202f2f09ull,0x33732e3436732e74ull,
0x2c38647225092032ull,0x20203b3538722520ull,0x202f2f0920202020ull,0x6f6c2e6c756d090aull,
0x722509203436752eull,0x38647225202c3964ull,0x202020203b34202cull,0x6461090a202f2f09ull,
0x2509203436752e64ull,0x7225202c30316472ull,0x39647225202c3164ull,0x202f2f092020203bull,
0x6f6c672e646c090aull,0x752e34762e6c6162ull,0x363872257b092038ull,0x72252c373872252cull,
0x5b202c7d5f2c3838ull,0x5d302b3031647225ull,0x73090a202f2f093bull,0x09203233732e6275ull,
0x7225202c39387225ull,0x39317225202c3838ull,0x2f2f09202020203bull,0x732e736261090a20ull,
0x3039722509203233ull,0x203b39387225202cull,0x2020202020202020ull,0x6d090a202f2f0920ull,
0x09203233732e766full,0x3031202c31397225ull,0x202020202020203bull,0x2f2f092020202020ull,
0x672e746573090a20ull,0x33732e3233752e74ull,0x2c32397225092032ull,0x25202c3039722520ull,
0x202f2f093b313972ull,0x33732e67656e090aull,0x2c33397225092032ull,0x20203b3239722520ull,
0x2020202020202020ull,0x7573090a202f2f09ull,0x2509203233732e62ull,0x387225202c343972ull,
0x3b37317225202c36ull,0x202f2f0920202020ull,0x33732e736261090aull,0x2c35397225092032ull,
0x20203b3439722520ull,0x2020202020202020ull,0x6f6d090a202f2f09ull,0x2509203233732e76ull,
0x3b3031202c363972ull,0x2020202020202020ull,0x202f2f0920202020ull,0x74672e746573090aull,
0x3233732e3233752eull,0x202c373972250920ull,0x7225202c35397225ull,0x0a202f2f093b3639ull,
0x3233732e67656e09ull,0x202c383972250920ull,0x2020203b37397225ull,0x0920202020202020ull,
0x627573090a202f2full,0x722509203233732eull,0x37387225202c3939ull,0x203b38317225202cull,
0x0a202f2f09202020ull,0x3233732e73626109ull,0x2c30303172250920ull,0x20203b3939722520ull,
0x0920202020202020ull,0x766f6d090a202f2full,0x722509203233732eull,0x3b3031202c313031ull,
0x2020202020202020ull,0x0a202f2f09202020ull,0x2e74672e74657309ull,0x203233732e323375ull,
0x202c323031722509ull,0x25202c3030317225ull,0x2f2f093b31303172ull,0x732e67656e090a20ull,
0x3031722509203233ull,0x3230317225202c33ull,0x202020202020203bull,0x6f090a202f2f0920ull,
0x2509203233622e72ull,0x7225202c34303172ull,0x30317225202c3839ull,0x2f2f092020203b33ull,
0x33622e726f090a20ull,0x3530317225092032ull,0x202c33397225202cull,0x20203b3430317225ull,
0x61090a202f2f0920ull,0x09203233732e6464ull,0x7225202c30347225ull,0x30317225202c3034ull,
0x2f2f092020203b35ull,0x5f355f744c240a20ull,0x090a3a3031323033ull,0x203233752e766f6dull,
0x202c363031722509ull,0x2020202020203b30ull,0x2f09202020202020ull,0x70746573090a202full,
0x203233732e71652eull,0x7225202c36702509ull,0x30317225202c3034ull,0x090a202f2f093b36ull,
0x6172622036702540ull,0x5f355f744c240920ull,0x20203b3232373033ull,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0939323109353109ull,0x61702e646c090a30ull,0x203436662e6d6172ull,
0x5b202c3164662509ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x6c6163735f69695full,0x69202f2f093b5d65ull,0x5f5f203538353a64ull,0x6d72617061647563ull,
0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x695f30535f32535full,0x2b656c6163735f69ull,0x2e646c090a307830ull,
0x36662e6d61726170ull,0x2c32646625092034ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x4f795f69695f3053ull,0x202f2f093b5d6666ull,0x5f203131363a6469ull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x2b66664f795f6969ull,
0x747663090a307830ull,0x2e3436662e6e722eull,0x6466250920323373ull,0x203b367225202c33ull,
0x0a202f2f09202020ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x2c33646625202c34ull,
0x25202c3164662520ull,0x202f2f093b326466ull,0x36662e766f6d090aull,0x2c35646625092034ull,
0x20203b3464662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,0x333109353109636full,
0x2e646c090a300930ull,0x36662e6d61726170ull,0x2c36646625092034ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x4f785f69695f3053ull,0x202f2f093b5d6666ull,
0x5f203231363a6469ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,
0x2b66664f785f6969ull,0x747663090a307830ull,0x2e3436662e6e722eull,0x6466250920323373ull,
0x203b347225202c37ull,0x0a202f2f09202020ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x2c37646625202c38ull,0x25202c3164662520ull,0x202f2f093b366466ull,0x36662e766f6d090aull,
0x2c39646625092034ull,0x20203b3864662520ull,0x2020202020202020ull,0x6c2e090a202f2f09ull,
0x333109353109636full,0x2e646c090a300933ull,0x33732e6d61726170ull,0x3730317225092032ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x635f69695f30535full,
0x093b5d68636e7572ull,0x38353a6469202f2full,0x616475635f5f2034ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x72635f69695f3053ull,0x3078302b68636e75ull,0x33732e766f6d090aull,
0x3830317225092032ull,0x3b3730317225202cull,0x2020202020202020ull,0x744c240a202f2f09ull,
0x32363731325f355full,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,
0x090a36393220656eull,0x09353109636f6c2eull,0x6d090a3009363932ull,0x09203436662e6c75ull,
0x25202c3031646625ull,0x646625202c356466ull,0x2f2f092020203b35ull,0x662e6c756d090a20ull,
0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x25202c3231646625ull,0x6625202c31316466ull,0x2f2f09203b303164ull,
0x662e766f6d090a20ull,0x3164662509203436ull,0x3130346430202c33ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,0x25202c3770250920ull,
0x6625202c32316466ull,0x202f2f093b333164ull,0x203770252140090aull,0x744c240920617262ull,
0x34333231335f355full,0x202020202020203bull,0x7573090a202f2f09ull,0x2509203233732e62ull,
0x7225202c39303172ull,0x203b31202c383031ull,0x202f2f0920202020ull,0x6e752e617262090aull,
0x355f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x34333231335f355full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x32363731325f355full,0x3109636f6c2e090aull,0x0a30093933310935ull,0x3436662e6c756d09ull,
0x2c34316466250920ull,0x25202c3564662520ull,0x092020203b396466ull,0x646461090a202f2full,
0x662509203436662eull,0x646625202c353164ull,0x31646625202c3431ull,0x0a202f2f09203b34ull,
0x3436662e64646109ull,0x202c356466250920ull,0x6625202c34646625ull,0x092020203b353164ull,
0x6f6c2e090a202f2full,0x3034310935310963ull,0x2e627573090a3009ull,0x6466250920343666ull,
0x31646625202c3631ull,0x3031646625202c31ull,0x090a202f2f09203bull,0x203436662e646461ull,
0x25202c3964662509ull,0x646625202c386466ull,0x2f092020203b3631ull,0x636f6c2e090a202full,
0x0931343109353109ull,0x662e6c756d090a30ull,0x3164662509203436ull,0x2c35646625202c37ull,
0x20203b3564662520ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,0x25202c3131646625ull,
0x646625202c396466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,0x3164662509203436ull,
0x3131646625202c38ull,0x3b3731646625202cull,0x6d090a202f2f0920ull,0x09203436662e766full,
0x30202c3931646625ull,0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,
0x74672e7074657309ull,0x702509203436662eull,0x3831646625202c38ull,0x3b3931646625202cull,
0x2140090a202f2f09ull,0x2061726220387025ull,0x335f355f744c2409ull,0x2020203b36343731ull,
0x202f2f0920202020ull,0x33732e627573090aull,0x3930317225092032ull,0x2c3830317225202cull,
0x20202020203b3220ull,0x7262090a202f2f09ull,0x240920696e752e61ull,0x3835325f355f744cull,
0x202020202020203bull,0x202f2f0920202020ull,0x335f355f744c240aull,0x2f200a3a36343731ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3639ull,0x64656c6562616c20ull,0x325f355f744c2420ull,0x6c2e090a32363731ull,
0x343109353109636full,0x6c756d090a300937ull,0x662509203436662eull,0x646625202c343164ull,
0x3b39646625202c35ull,0x0a202f2f09202020ull,0x3436662e64646109ull,0x2c30326466250920ull,
0x202c343164662520ull,0x09203b3431646625ull,0x646461090a202f2full,0x662509203436662eull,
0x34646625202c3564ull,0x3b3032646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300938343109ull,0x203436662e627573ull,0x202c313264662509ull,0x25202c3131646625ull,
0x2f09203b37316466ull,0x2e646461090a202full,0x6466250920343666ull,0x2c38646625202c39ull,
0x203b313264662520ull,0x090a202f2f092020ull,0x09353109636f6c2eull,0x6d090a3009393431ull,
0x09203436662e6c75ull,0x25202c3232646625ull,0x646625202c356466ull,0x2f2f092020203b35ull,
0x662e6c756d090a20ull,0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3332646625ull,0x6625202c31316466ull,
0x2f2f09203b323264ull,0x662e766f6d090a20ull,0x3264662509203436ull,0x3130346430202c34ull,
0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,
0x25202c3970250920ull,0x6625202c33326466ull,0x202f2f093b343264ull,0x203970252140090aull,
0x744c240920617262ull,0x38353232335f355full,0x202020202020203bull,0x7573090a202f2f09ull,
0x2509203233732e62ull,0x7225202c39303172ull,0x203b33202c383031ull,0x202f2f0920202020ull,
0x6e752e617262090aull,0x355f744c24092069ull,0x2020203b3835325full,0x2020202020202020ull,
0x744c240a202f2f09ull,0x38353232335f355full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x32363731325f355full,0x3109636f6c2e090aull,0x0a30093535310935ull,
0x3436662e6c756d09ull,0x2c34316466250920ull,0x25202c3564662520ull,0x092020203b396466ull,
0x646461090a202f2full,0x662509203436662eull,0x646625202c353264ull,0x31646625202c3431ull,
0x0a202f2f09203b34ull,0x3436662e64646109ull,0x202c356466250920ull,0x6625202c34646625ull,
0x092020203b353264ull,0x6f6c2e090a202f2full,0x3635310935310963ull,0x2e627573090a3009ull,
0x6466250920343666ull,0x31646625202c3632ull,0x3232646625202c31ull,0x090a202f2f09203bull,
0x203436662e646461ull,0x25202c3964662509ull,0x646625202c386466ull,0x2f092020203b3632ull,
0x636f6c2e090a202full,0x0937353109353109ull,0x662e6c756d090a30ull,0x3264662509203436ull,
0x2c35646625202c37ull,0x20203b3564662520ull,0x6d090a202f2f0920ull,0x09203436662e6c75ull,
0x25202c3131646625ull,0x646625202c396466ull,0x2f2f092020203b39ull,0x662e646461090a20ull,
0x3264662509203436ull,0x3131646625202c38ull,0x3b3732646625202cull,0x6d090a202f2f0920ull,
0x09203436662e766full,0x30202c3932646625ull,0x3030303031303464ull,0x3030303030303030ull,
0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,0x32646625202c3031ull,
0x3932646625202c38ull,0x40090a202f2f093bull,0x7262203031702521ull,0x355f744c24092061ull,
0x203b30373732335full,0x2f2f092020202020ull,0x732e627573090a20ull,0x3031722509203233ull,
0x3830317225202c39ull,0x202020203b34202cull,0x62090a202f2f0920ull,0x0920696e752e6172ull,
0x35325f355f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,0x5f355f744c240a20ull,
0x200a3a3037373233ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c363932ull,0x656c6562616c2064ull,0x5f355f744c242064ull,
0x2e090a3236373132ull,0x3109353109636f6cull,0x756d090a30093336ull,0x2509203436662e6cull,
0x6625202c34316466ull,0x39646625202c3564ull,0x202f2f092020203bull,0x36662e646461090aull,
0x3033646625092034ull,0x2c3431646625202cull,0x203b343164662520ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x646625202c356466ull,0x3033646625202c34ull,0x202f2f092020203bull,
0x3109636f6c2e090aull,0x0a30093436310935ull,0x3436662e62757309ull,0x2c31336466250920ull,
0x202c313164662520ull,0x09203b3732646625ull,0x646461090a202f2full,0x662509203436662eull,
0x38646625202c3964ull,0x3b3133646625202cull,0x0a202f2f09202020ull,0x353109636f6c2e09ull,
0x090a300935363109ull,0x203436662e6c756dull,0x202c323364662509ull,0x6625202c35646625ull,
0x2f092020203b3564ull,0x2e6c756d090a202full,0x6466250920343666ull,0x39646625202c3131ull,
0x203b39646625202cull,0x090a202f2f092020ull,0x203436662e646461ull,0x202c333364662509ull,
0x25202c3131646625ull,0x2f09203b32336466ull,0x2e766f6d090a202full,0x6466250920343666ull,
0x30346430202c3433ull,0x3030303030303031ull,0x093b303030303030ull,0x6573090a34202f2full,
0x36662e74672e7074ull,0x2c31317025092034ull,0x202c333364662520ull,0x2f093b3433646625ull,
0x70252140090a202full,0x0920617262203131ull,0x33335f355f744c24ull,0x202020203b323832ull,
0x090a202f2f092020ull,0x203233732e627573ull,0x202c393031722509ull,0x35202c3830317225ull,
0x2f0920202020203bull,0x2e617262090a202full,0x744c240920696e75ull,0x203b3835325f355full,
0x2020202020202020ull,0x240a202f2f092020ull,0x3233335f355f744cull,0x3c2f2f200a3a3238ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x36393220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3731325f355f744cull,0x636f6c2e090a3236ull,
0x0931373109353109ull,0x662e6c756d090a30ull,0x3164662509203436ull,0x2c35646625202c34ull,
0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3533646625ull,
0x6625202c34316466ull,0x2f2f09203b343164ull,0x662e646461090a20ull,0x3564662509203436ull,
0x202c34646625202cull,0x20203b3533646625ull,0x2e090a202f2f0920ull,0x3109353109636f6cull,
0x7573090a30093237ull,0x2509203436662e62ull,0x6625202c36336466ull,0x646625202c313164ull,
0x202f2f09203b3233ull,0x36662e646461090aull,0x2c39646625092034ull,0x25202c3864662520ull,
0x2020203b36336466ull,0x6c2e090a202f2f09ull,0x373109353109636full,0x6c756d090a300933ull,
0x662509203436662eull,0x646625202c373364ull,0x3b35646625202c35ull,0x0a202f2f09202020ull,
0x3436662e6c756d09ull,0x2c31316466250920ull,0x25202c3964662520ull,0x092020203b396466ull,
0x646461090a202f2full,0x662509203436662eull,0x646625202c383364ull,0x33646625202c3131ull,
0x0a202f2f09203b37ull,0x3436662e766f6d09ull,0x2c39336466250920ull,0x3030313034643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,
0x6625202c32317025ull,0x646625202c383364ull,0x0a202f2f093b3933ull,0x2032317025214009ull,
0x744c240920617262ull,0x34393733335f355full,0x092020202020203bull,0x627573090a202f2full,
0x722509203233732eull,0x317225202c393031ull,0x20203b36202c3830ull,0x0a202f2f09202020ull,
0x696e752e61726209ull,0x5f355f744c240920ull,0x202020203b383532ull,0x0920202020202020ull,
0x5f744c240a202f2full,0x3a34393733335f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a32363731325f35ull,0x353109636f6c2e09ull,0x090a300939373109ull,
0x203436662e6c756dull,0x202c343164662509ull,0x6625202c35646625ull,0x2f092020203b3964ull,
0x2e646461090a202full,0x6466250920343666ull,0x31646625202c3034ull,0x3431646625202c34ull,
0x090a202f2f09203bull,0x203436662e646461ull,0x25202c3564662509ull,0x646625202c346466ull,
0x2f092020203b3034ull,0x636f6c2e090a202full,0x0930383109353109ull,0x662e627573090a30ull,
0x3464662509203436ull,0x3131646625202c31ull,0x3b3733646625202cull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x6625202c39646625ull,0x34646625202c3864ull,0x2f2f092020203b31ull,
0x09636f6c2e090a20ull,0x3009313831093531ull,0x36662e6c756d090aull,0x3234646625092034ull,
0x202c35646625202cull,0x2020203b35646625ull,0x756d090a202f2f09ull,0x2509203436662e6cull,
0x6625202c31316466ull,0x39646625202c3964ull,0x202f2f092020203bull,0x36662e646461090aull,
0x3334646625092034ull,0x2c3131646625202cull,0x203b323464662520ull,0x6f6d090a202f2f09ull,
0x2509203436662e76ull,0x6430202c34346466ull,0x3030303030313034ull,0x3030303030303030ull,
0x090a34202f2f093bull,0x2e74672e70746573ull,0x3170250920343666ull,0x3334646625202c33ull,
0x3b3434646625202cull,0x2140090a202f2f09ull,0x6172622033317025ull,0x5f355f744c240920ull,
0x20203b3630333433ull,0x202f2f0920202020ull,0x33732e627573090aull,0x3930317225092032ull,
0x2c3830317225202cull,0x20202020203b3720ull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3835325f355f744cull,0x202020202020203bull,0x202f2f0920202020ull,0x335f355f744c240aull,
0x2f200a3a36303334ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,0x325f355f744c2420ull,
0x6c2e090a32363731ull,0x383109353109636full,0x6c756d090a300937ull,0x662509203436662eull,
0x646625202c343164ull,0x3b39646625202c35ull,0x0a202f2f09202020ull,0x3436662e64646109ull,
0x2c35346466250920ull,0x202c343164662520ull,0x09203b3431646625ull,0x646461090a202f2full,
0x662509203436662eull,0x34646625202c3564ull,0x3b3534646625202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300938383109ull,0x203436662e627573ull,0x202c363464662509ull,
0x25202c3131646625ull,0x2f09203b32346466ull,0x2e646461090a202full,0x6466250920343666ull,
0x2c38646625202c39ull,0x203b363464662520ull,0x090a202f2f092020ull,0x09353109636f6c2eull,
0x6d090a3009393831ull,0x09203436662e6c75ull,0x25202c3734646625ull,0x646625202c356466ull,
0x2f2f092020203b35ull,0x662e6c756d090a20ull,0x3164662509203436ull,0x2c39646625202c31ull,
0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x25202c3834646625ull,
0x6625202c31316466ull,0x2f2f09203b373464ull,0x662e766f6d090a20ull,0x3464662509203436ull,
0x3130346430202c39ull,0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a34202full,
0x3436662e74672e70ull,0x202c343170250920ull,0x25202c3834646625ull,0x2f2f093b39346466ull,
0x3170252140090a20ull,0x2409206172622034ull,0x3834335f355f744cull,0x20202020203b3831ull,
0x73090a202f2f0920ull,0x09203233732e6275ull,0x25202c3930317225ull,0x3b38202c38303172ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x20203b3835325f35ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x313834335f355f74ull,0x6c3c2f2f200a3a38ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36393220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f355f74ull,0x09636f6c2e090a32ull,
0x3009353931093531ull,0x36662e6c756d090aull,0x3431646625092034ull,0x202c35646625202cull,
0x2020203b39646625ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x6625202c30356466ull,
0x646625202c343164ull,0x202f2f09203b3431ull,0x36662e646461090aull,0x2c35646625092034ull,
0x25202c3464662520ull,0x2020203b30356466ull,0x6c2e090a202f2f09ull,0x393109353109636full,
0x627573090a300936ull,0x662509203436662eull,0x646625202c313564ull,0x34646625202c3131ull,
0x0a202f2f09203b37ull,0x3436662e64646109ull,0x202c396466250920ull,0x6625202c38646625ull,
0x092020203b313564ull,0x6f6c2e090a202f2full,0x3739310935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x35646625202c3235ull,0x203b35646625202cull,0x090a202f2f092020ull,
0x203436662e6c756dull,0x202c313164662509ull,0x6625202c39646625ull,0x2f092020203b3964ull,
0x2e646461090a202full,0x6466250920343666ull,0x31646625202c3335ull,0x3235646625202c31ull,
0x090a202f2f09203bull,0x203436662e766f6dull,0x202c343564662509ull,0x3030303130346430ull,
0x3030303030303030ull,0x34202f2f093b3030ull,0x672e70746573090aull,0x2509203436662e74ull,
0x646625202c353170ull,0x35646625202c3335ull,0x090a202f2f093b34ull,0x6220353170252140ull,
0x5f744c2409206172ull,0x3b30333335335f35ull,0x2f09202020202020ull,0x2e627573090a202full,
0x3172250920323373ull,0x30317225202c3930ull,0x2020203b39202c38ull,0x090a202f2f092020ull,
0x20696e752e617262ull,0x325f355f744c2409ull,0x20202020203b3835ull,0x2f09202020202020ull,
0x355f744c240a202full,0x0a3a30333335335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36393220ull,0x6c6562616c206461ull,
0x355f744c24206465ull,0x090a32363731325full,0x09353109636f6c2eull,0x6d090a3009333032ull,
0x09203436662e6c75ull,0x25202c3431646625ull,0x646625202c356466ull,0x2f2f092020203b39ull,
0x662e646461090a20ull,0x3564662509203436ull,0x3431646625202c35ull,0x3b3431646625202cull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x6625202c35646625ull,0x35646625202c3464ull,
0x2f2f092020203b35ull,0x09636f6c2e090a20ull,0x3009343032093531ull,0x36662e627573090aull,
0x3635646625092034ull,0x2c3131646625202cull,0x203b323564662520ull,0x6461090a202f2f09ull,
0x2509203436662e64ull,0x646625202c396466ull,0x3635646625202c38ull,0x202f2f092020203bull,
0x3109636f6c2e090aull,0x0a30093530320935ull,0x3436662e6c756d09ull,0x2c37356466250920ull,
0x25202c3564662520ull,0x092020203b356466ull,0x6c756d090a202f2full,0x662509203436662eull,
0x646625202c313164ull,0x3b39646625202c39ull,0x0a202f2f09202020ull,0x3436662e64646109ull,
0x2c38356466250920ull,0x202c313164662520ull,0x09203b3735646625ull,0x766f6d090a202f2full,
0x662509203436662eull,0x346430202c393564ull,0x3030303030303130ull,0x3b30303030303030ull,
0x73090a34202f2f09ull,0x662e74672e707465ull,0x3631702509203436ull,0x2c3835646625202cull,
0x093b393564662520ull,0x252140090a202f2full,0x2061726220363170ull,0x335f355f744c2409ull,
0x2020203b32343835ull,0x0a202f2f09202020ull,0x3233732e62757309ull,0x2c39303172250920ull,
0x202c383031722520ull,0x09202020203b3031ull,0x617262090a202f2full,0x4c240920696e752eull,
0x3b3835325f355f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x35335f355f744c24ull,
0x2f2f200a3a323438ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x393220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,0x31325f355f744c24ull,
0x6f6c2e090a323637ull,0x3131320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x35646625202c3431ull,0x203b39646625202cull,0x090a202f2f092020ull,0x203436662e646461ull,
0x202c303664662509ull,0x25202c3431646625ull,0x2f09203b34316466ull,0x2e646461090a202full,
0x6466250920343666ull,0x2c34646625202c35ull,0x203b303664662520ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x73090a3009323132ull,0x09203436662e6275ull,0x25202c3136646625ull,
0x6625202c31316466ull,0x2f2f09203b373564ull,0x662e646461090a20ull,0x3964662509203436ull,
0x202c38646625202cull,0x20203b3136646625ull,0x2e090a202f2f0920ull,0x3209353109636f6cull,
0x756d090a30093331ull,0x2509203436662e6cull,0x6625202c32366466ull,0x35646625202c3564ull,
0x202f2f092020203bull,0x36662e6c756d090aull,0x3131646625092034ull,0x202c39646625202cull,
0x2020203b39646625ull,0x6461090a202f2f09ull,0x2509203436662e64ull,0x6625202c33366466ull,
0x646625202c313164ull,0x202f2f09203b3236ull,0x36662e766f6d090aull,0x3436646625092034ull,
0x303130346430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3420ull,
0x203436662e74672eull,0x25202c3731702509ull,0x6625202c33366466ull,0x202f2f093b343664ull,
0x373170252140090aull,0x4c24092061726220ull,0x353336335f355f74ull,0x2020202020203b34ull,
0x7573090a202f2f09ull,0x2509203233732e62ull,0x7225202c39303172ull,0x3b3131202c383031ull,
0x202f2f0920202020ull,0x6e752e617262090aull,0x355f744c24092069ull,0x2020203b3835325full,
0x2020202020202020ull,0x744c240a202f2f09ull,0x34353336335f355full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32363731325f355full,0x3109636f6c2e090aull,
0x0a30093931320935ull,0x3436662e6c756d09ull,0x2c34316466250920ull,0x25202c3564662520ull,
0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,0x646625202c353664ull,
0x31646625202c3431ull,0x0a202f2f09203b34ull,0x3436662e64646109ull,0x202c356466250920ull,
0x6625202c34646625ull,0x092020203b353664ull,0x6f6c2e090a202f2full,0x3032320935310963ull,
0x2e627573090a3009ull,0x6466250920343666ull,0x31646625202c3636ull,0x3236646625202c31ull,
0x090a202f2f09203bull,0x203436662e646461ull,0x25202c3964662509ull,0x646625202c386466ull,
0x2f092020203b3636ull,0x636f6c2e090a202full,0x0931323209353109ull,0x662e6c756d090a30ull,
0x3664662509203436ull,0x2c35646625202c37ull,0x20203b3564662520ull,0x6d090a202f2f0920ull,
0x09203436662e6c75ull,0x25202c3131646625ull,0x646625202c396466ull,0x2f2f092020203b39ull,
0x662e646461090a20ull,0x3664662509203436ull,0x3131646625202c38ull,0x3b3736646625202cull,
0x6d090a202f2f0920ull,0x09203436662e766full,0x30202c3936646625ull,0x3030303031303464ull,
0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,
0x36646625202c3831ull,0x3936646625202c38ull,0x40090a202f2f093bull,0x7262203831702521ull,
0x355f744c24092061ull,0x203b36363836335full,0x2f2f092020202020ull,0x732e627573090a20ull,
0x3031722509203233ull,0x3830317225202c39ull,0x2020203b3231202cull,0x62090a202f2f0920ull,
0x0920696e752e6172ull,0x35325f355f744c24ull,0x2020202020203b38ull,0x2f2f092020202020ull,
0x5f355f744c240a20ull,0x200a3a3636383633ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c363932ull,0x656c6562616c2064ull,
0x5f355f744c242064ull,0x2e090a3236373132ull,0x3209353109636f6cull,0x756d090a30093732ull,
0x2509203436662e6cull,0x6625202c34316466ull,0x39646625202c3564ull,0x202f2f092020203bull,
0x36662e646461090aull,0x3037646625092034ull,0x2c3431646625202cull,0x203b343164662520ull,
0x6461090a202f2f09ull,0x2509203436662e64ull,0x646625202c356466ull,0x3037646625202c34ull,
0x202f2f092020203bull,0x3109636f6c2e090aull,0x0a30093832320935ull,0x3436662e62757309ull,
0x2c31376466250920ull,0x202c313164662520ull,0x09203b3736646625ull,0x646461090a202f2full,
0x662509203436662eull,0x38646625202c3964ull,0x3b3137646625202cull,0x0a202f2f09202020ull,
0x353109636f6c2e09ull,0x090a300939323209ull,0x203436662e6c756dull,0x202c323764662509ull,
0x6625202c35646625ull,0x2f092020203b3564ull,0x2e6c756d090a202full,0x6466250920343666ull,
0x39646625202c3131ull,0x203b39646625202cull,0x090a202f2f092020ull,0x203436662e646461ull,
0x202c333764662509ull,0x25202c3131646625ull,0x2f09203b32376466ull,0x2e766f6d090a202full,
0x6466250920343666ull,0x30346430202c3437ull,0x3030303030303031ull,0x093b303030303030ull,
0x6573090a34202f2full,0x36662e74672e7074ull,0x2c39317025092034ull,0x202c333764662520ull,
0x2f093b3437646625ull,0x70252140090a202full,0x0920617262203931ull,0x37335f355f744c24ull,
0x202020203b383733ull,0x090a202f2f092020ull,0x203233732e627573ull,0x202c393031722509ull,
0x31202c3830317225ull,0x2f09202020203b33ull,0x2e617262090a202full,0x744c240920696e75ull,
0x203b3835325f355full,0x2020202020202020ull,0x240a202f2f092020ull,0x3337335f355f744cull,
0x3c2f2f200a3a3837ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x36393220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3731325f355f744cull,
0x636f6c2e090a3236ull,0x0935333209353109ull,0x662e6c756d090a30ull,0x3164662509203436ull,
0x2c35646625202c34ull,0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,
0x25202c3537646625ull,0x6625202c34316466ull,0x2f2f09203b343164ull,0x662e646461090a20ull,
0x3564662509203436ull,0x202c34646625202cull,0x20203b3537646625ull,0x2e090a202f2f0920ull,
0x3209353109636f6cull,0x7573090a30093633ull,0x2509203436662e62ull,0x6625202c36376466ull,
0x646625202c313164ull,0x202f2f09203b3237ull,0x36662e646461090aull,0x2c39646625092034ull,
0x25202c3864662520ull,0x2020203b36376466ull,0x6c2e090a202f2f09ull,0x333209353109636full,
0x6c756d090a300937ull,0x662509203436662eull,0x646625202c373764ull,0x3b35646625202c35ull,
0x0a202f2f09202020ull,0x3436662e6c756d09ull,0x2c31316466250920ull,0x25202c3964662520ull,
0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,0x646625202c383764ull,
0x37646625202c3131ull,0x0a202f2f09203b37ull,0x3436662e766f6d09ull,0x2c39376466250920ull,
0x3030313034643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a34ull,
0x09203436662e7467ull,0x6625202c30327025ull,0x646625202c383764ull,0x0a202f2f093b3937ull,
0x2030327025214009ull,0x744c240920617262ull,0x30393837335f355full,0x092020202020203bull,
0x627573090a202f2full,0x722509203233732eull,0x317225202c393031ull,0x203b3431202c3830ull,
0x0a202f2f09202020ull,0x696e752e61726209ull,0x5f355f744c240920ull,0x202020203b383532ull,
0x0920202020202020ull,0x5f744c240a202f2full,0x3a30393837335f35ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3639322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a32363731325f35ull,0x353109636f6c2e09ull,
0x090a300933343209ull,0x203436662e6c756dull,0x202c343164662509ull,0x6625202c35646625ull,
0x2f092020203b3964ull,0x2e646461090a202full,0x6466250920343666ull,0x31646625202c3038ull,
0x3431646625202c34ull,0x090a202f2f09203bull,0x203436662e646461ull,0x25202c3564662509ull,
0x646625202c346466ull,0x2f092020203b3038ull,0x636f6c2e090a202full,0x0934343209353109ull,
0x662e627573090a30ull,0x3864662509203436ull,0x3131646625202c31ull,0x3b3737646625202cull,
0x61090a202f2f0920ull,0x09203436662e6464ull,0x6625202c39646625ull,0x38646625202c3864ull,
0x2f2f092020203b31ull,0x09636f6c2e090a20ull,0x3009353432093531ull,0x36662e6c756d090aull,
0x3238646625092034ull,0x202c35646625202cull,0x2020203b35646625ull,0x756d090a202f2f09ull,
0x2509203436662e6cull,0x6625202c31316466ull,0x39646625202c3964ull,0x202f2f092020203bull,
0x36662e646461090aull,0x3338646625092034ull,0x2c3131646625202cull,0x203b323864662520ull,
0x6f6d090a202f2f09ull,0x2509203436662e76ull,0x6430202c34386466ull,0x3030303030313034ull,
0x3030303030303030ull,0x090a34202f2f093bull,0x2e74672e70746573ull,0x3270250920343666ull,
0x3338646625202c31ull,0x3b3438646625202cull,0x2140090a202f2f09ull,0x6172622031327025ull,
0x5f355f744c240920ull,0x20203b3230343833ull,0x202f2f0920202020ull,0x33732e627573090aull,
0x3930317225092032ull,0x2c3830317225202cull,0x202020203b353120ull,0x7262090a202f2f09ull,
0x240920696e752e61ull,0x3835325f355f744cull,0x202020202020203bull,0x202f2f0920202020ull,
0x335f355f744c240aull,0x2f200a3a32303438ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,
0x325f355f744c2420ull,0x6c2e090a32363731ull,0x353209353109636full,0x6c756d090a300931ull,
0x662509203436662eull,0x646625202c343164ull,0x3b39646625202c35ull,0x0a202f2f09202020ull,
0x3436662e64646109ull,0x2c35386466250920ull,0x202c343164662520ull,0x09203b3431646625ull,
0x646461090a202f2full,0x662509203436662eull,0x34646625202c3564ull,0x3b3538646625202cull,
0x0a202f2f09202020ull,0x353109636f6c2e09ull,0x090a300932353209ull,0x203436662e627573ull,
0x202c363864662509ull,0x25202c3131646625ull,0x2f09203b32386466ull,0x2e646461090a202full,
0x6466250920343666ull,0x2c38646625202c39ull,0x203b363864662520ull,0x090a202f2f092020ull,
0x09353109636f6c2eull,0x6d090a3009333532ull,0x09203436662e6c75ull,0x25202c3738646625ull,
0x646625202c356466ull,0x2f2f092020203b35ull,0x662e6c756d090a20ull,0x3164662509203436ull,
0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,0x09203436662e6464ull,
0x25202c3838646625ull,0x6625202c31316466ull,0x2f2f09203b373864ull,0x662e766f6d090a20ull,
0x3864662509203436ull,0x3130346430202c39ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x746573090a34202full,0x3436662e74672e70ull,0x202c323270250920ull,0x25202c3838646625ull,
0x2f2f093b39386466ull,0x3270252140090a20ull,0x2409206172622032ull,0x3938335f355f744cull,
0x20202020203b3431ull,0x73090a202f2f0920ull,0x09203233732e6275ull,0x25202c3930317225ull,
0x3631202c38303172ull,0x2f2f09202020203bull,0x752e617262090a20ull,0x5f744c240920696eull,
0x20203b3835325f35ull,0x2020202020202020ull,0x4c240a202f2f0920ull,0x313938335f355f74ull,
0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c36393220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f355f74ull,
0x09636f6c2e090a32ull,0x3009393532093531ull,0x36662e6c756d090aull,0x3431646625092034ull,
0x202c35646625202cull,0x2020203b39646625ull,0x6461090a202f2f09ull,0x2509203436662e64ull,
0x6625202c30396466ull,0x646625202c343164ull,0x202f2f09203b3431ull,0x36662e646461090aull,
0x2c35646625092034ull,0x25202c3464662520ull,0x2020203b30396466ull,0x6c2e090a202f2f09ull,
0x363209353109636full,0x627573090a300930ull,0x662509203436662eull,0x646625202c313964ull,
0x38646625202c3131ull,0x0a202f2f09203b37ull,0x3436662e64646109ull,0x202c396466250920ull,
0x6625202c38646625ull,0x092020203b313964ull,0x6f6c2e090a202f2full,0x3136320935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x35646625202c3239ull,0x203b35646625202cull,
0x090a202f2f092020ull,0x203436662e6c756dull,0x202c313164662509ull,0x6625202c39646625ull,
0x2f092020203b3964ull,0x2e646461090a202full,0x6466250920343666ull,0x31646625202c3339ull,
0x3239646625202c31ull,0x090a202f2f09203bull,0x203436662e766f6dull,0x202c343964662509ull,
0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,0x672e70746573090aull,
0x2509203436662e74ull,0x646625202c333270ull,0x39646625202c3339ull,0x090a202f2f093b34ull,
0x6220333270252140ull,0x5f744c2409206172ull,0x3b36323439335f35ull,0x2f09202020202020ull,
0x2e627573090a202full,0x3172250920323373ull,0x30317225202c3930ull,0x20203b3731202c38ull,
0x090a202f2f092020ull,0x20696e752e617262ull,0x325f355f744c2409ull,0x20202020203b3835ull,
0x2f09202020202020ull,0x355f744c240a202full,0x0a3a36323439335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c36393220ull,
0x6c6562616c206461ull,0x355f744c24206465ull,0x090a32363731325full,0x09353109636f6c2eull,
0x6d090a3009373632ull,0x09203436662e6c75ull,0x25202c3431646625ull,0x646625202c356466ull,
0x2f2f092020203b39ull,0x662e646461090a20ull,0x3964662509203436ull,0x3431646625202c35ull,
0x3b3431646625202cull,0x61090a202f2f0920ull,0x09203436662e6464ull,0x6625202c35646625ull,
0x39646625202c3464ull,0x2f2f092020203b35ull,0x09636f6c2e090a20ull,0x3009383632093531ull,
0x36662e627573090aull,0x3639646625092034ull,0x2c3131646625202cull,0x203b323964662520ull,
0x6461090a202f2f09ull,0x2509203436662e64ull,0x646625202c396466ull,0x3639646625202c38ull,
0x202f2f092020203bull,0x3109636f6c2e090aull,0x0a30093936320935ull,0x3436662e6c756d09ull,
0x2c37396466250920ull,0x25202c3564662520ull,0x092020203b356466ull,0x6c756d090a202f2full,
0x662509203436662eull,0x646625202c313164ull,0x3b39646625202c39ull,0x0a202f2f09202020ull,
0x3436662e64646109ull,0x2c38396466250920ull,0x202c313164662520ull,0x09203b3739646625ull,
0x766f6d090a202f2full,0x662509203436662eull,0x346430202c393964ull,0x3030303030303130ull,
0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3432702509203436ull,
0x2c3839646625202cull,0x093b393964662520ull,0x252140090a202f2full,0x2061726220343270ull,
0x335f355f744c2409ull,0x2020203b38333939ull,0x0a202f2f09202020ull,0x3233732e62757309ull,
0x2c39303172250920ull,0x202c383031722520ull,0x09202020203b3831ull,0x617262090a202f2full,
0x4c240920696e752eull,0x3b3835325f355f74ull,0x2020202020202020ull,0x0a202f2f09202020ull,
0x39335f355f744c24ull,0x2f2f200a3a383339ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x393220656e696c20ull,0x2064616568202c36ull,0x2064656c6562616cull,
0x31325f355f744c24ull,0x6f6c2e090a323637ull,0x3537320935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x35646625202c3431ull,0x203b39646625202cull,0x090a202f2f092020ull,
0x203436662e646461ull,0x2c30303164662509ull,0x202c343164662520ull,0x2f093b3431646625ull,
0x2e646461090a202full,0x6466250920343666ull,0x2c34646625202c35ull,0x3b30303164662520ull,
0x090a202f2f092020ull,0x09353109636f6c2eull,0x73090a3009363732ull,0x09203436662e6275ull,
0x202c313031646625ull,0x25202c3131646625ull,0x2f2f093b37396466ull,0x662e646461090a20ull,
0x3964662509203436ull,0x202c38646625202cull,0x203b313031646625ull,0x2e090a202f2f0920ull,
0x3209353109636f6cull,0x756d090a30093737ull,0x2509203436662e6cull,0x25202c3230316466ull,
0x646625202c356466ull,0x202f2f0920203b35ull,0x36662e6c756d090aull,0x3131646625092034ull,
0x202c39646625202cull,0x2020203b39646625ull,0x6461090a202f2f09ull,0x2509203436662e64ull,
0x25202c3330316466ull,0x6625202c31316466ull,0x2f2f093b32303164ull,0x662e766f6d090a20ull,
0x3164662509203436ull,0x30346430202c3430ull,0x3030303030303031ull,0x093b303030303030ull,
0x6573090a34202f2full,0x36662e74672e7074ull,0x2c35327025092034ull,0x2c33303164662520ull,
0x3b34303164662520ull,0x2140090a202f2f09ull,0x6172622035327025ull,0x5f355f744c240920ull,
0x20203b3035343034ull,0x202f2f0920202020ull,0x33732e627573090aull,0x3930317225092032ull,
0x2c3830317225202cull,0x202020203b393120ull,0x7262090a202f2f09ull,0x240920696e752e61ull,
0x3835325f355f744cull,0x202020202020203bull,0x202f2f0920202020ull,0x345f355f744c240aull,
0x2f200a3a30353430ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3639ull,0x64656c6562616c20ull,0x325f355f744c2420ull,
0x6c2e090a32363731ull,0x383209353109636full,0x6c756d090a300933ull,0x662509203436662eull,
0x646625202c343164ull,0x3b39646625202c35ull,0x0a202f2f09202020ull,0x3436662e64646109ull,
0x3530316466250920ull,0x2c3431646625202cull,0x093b343164662520ull,0x646461090a202f2full,
0x662509203436662eull,0x34646625202c3564ull,0x353031646625202cull,0x0a202f2f0920203bull,
0x353109636f6c2e09ull,0x090a300934383209ull,0x203436662e627573ull,0x2c36303164662509ull,
0x202c313164662520ull,0x093b323031646625ull,0x646461090a202f2full,0x662509203436662eull,
0x38646625202c3964ull,0x363031646625202cull,0x0a202f2f0920203bull,0x353109636f6c2e09ull,
0x090a300935383209ull,0x203436662e6c756dull,0x2c37303164662509ull,0x25202c3564662520ull,
0x2f0920203b356466ull,0x636f6c2e090a202full,0x0939383209353109ull,0x732e627573090a30ull,
0x3031722509203233ull,0x3830317225202c38ull,0x2020203b3032202cull,0x2e090a202f2f0920ull,
0x3209353109636f6cull,0x6f6d090a30093338ull,0x2509203233752e76ull,0x3b30202c30313172ull,
0x2020202020202020ull,0x202f2f0920202020ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x317225202c363270ull,0x31317225202c3830ull,0x090a202f2f093b30ull,0x7262203632702540ull,
0x5f355f4c24092061ull,0x20203b3630393732ull,0x2f09202020202020ull,0x6c3c2f2f200a202full,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c36393220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x363731325f355f74ull,0x662e6c756d090a32ull,
0x3164662509203436ull,0x2c39646625202c31ull,0x20203b3964662520ull,0x61090a202f2f0920ull,
0x09203436662e6464ull,0x202c383031646625ull,0x25202c3131646625ull,0x2f093b3730316466ull,
0x2e766f6d090a202full,0x6466250920343666ull,0x346430202c393031ull,0x3030303030303130ull,
0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3732702509203436ull,
0x383031646625202cull,0x393031646625202cull,0x40090a202f2f093bull,0x7262203732702521ull,
0x5f355f4c24092061ull,0x20203b3035363732ull,0x2f2f092020202020ull,0x325f355f4c240a20ull,
0x6d090a3a36303937ull,0x09203233732e766full,0x25202c3930317225ull,0x2020203b38303172ull,
0x2f2f092020202020ull,0x752e617262090a20ull,0x5f744c240920696eull,0x20203b3835325f35ull,
0x2020202020202020ull,0x4c240a202f2f0920ull,0x30353637325f355full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c36393220656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x32363731325f355full,0x3109636f6c2e090aull,
0x0a30093239320935ull,0x3436662e6c756d09ull,0x2c34316466250920ull,0x25202c3564662520ull,
0x092020203b396466ull,0x646461090a202f2full,0x662509203436662eull,0x6625202c30313164ull,
0x646625202c343164ull,0x0a202f2f093b3431ull,0x3436662e64646109ull,0x202c356466250920ull,
0x6625202c34646625ull,0x0920203b30313164ull,0x6f6c2e090a202f2full,0x3339320935310963ull,
0x2e627573090a3009ull,0x6466250920343666ull,0x646625202c313131ull,0x31646625202c3131ull,
0x0a202f2f093b3730ull,0x3436662e64646109ull,0x202c396466250920ull,0x6625202c38646625ull,
0x0920203b31313164ull,0x6f6c2e090a202f2full,0x3239320935310963ull,0x2e617262090a3009ull,
0x744c240920696e75ull,0x32363731325f355full,0x202020202020203bull,0x240a202f2f092020ull,
0x3835325f355f744cull,0x09636f6c2e090a3aull,0x3009353231093631ull,0x33732e766f6d090aull,
0x3131317225092032ull,0x202020203b30202cull,0x2020202020202020ull,0x6573090a202f2f09ull,
0x33732e74672e7074ull,0x2c38327025092032ull,0x202c393031722520ull,0x2f093b3131317225ull,
0x2e627573090a202full,0x3172250920323373ull,0x30317225202c3231ull,0x3930317225202c37ull,
0x090a202f2f09203bull,0x203233732e766f6dull,0x202c333131722509ull,0x2020202020203b30ull,
0x2f09202020202020ull,0x706c6573090a202full,0x722509203233732eull,0x317225202c343131ull,
0x31317225202c3231ull,0x3b38327025202c33ull,0x6f6d090a202f2f09ull,0x2509203233752e76ull,
0x3b30202c35313172ull,0x2020202020202020ull,0x202f2f0920202020ull,0x652e70746573090aull,
0x2509203233732e71ull,0x317225202c393270ull,0x31317225202c3431ull,0x090a202f2f093b35ull,
0x7262203932702540ull,0x355f744c24092061ull,0x203b38313231345full,0x2f09202020202020ull,
0x636f6c2e090a202full,0x0932333109363109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x202c363131722509ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x696e615f69695f30ull,0x72466e6f6974616dull,0x2f2f093b5d656d61ull,0x203331363a646920ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,
0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,0x6d696e615f69695full,
0x6172466e6f697461ull,0x090a3078302b656dull,0x203233732e646461ull,0x202c373131722509ull,
0x25202c3631317225ull,0x2f09203b34313172ull,0x702e646c090a202full,0x2038752e6d617261ull,
0x202c383131722509ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x6c6f635f69695f30ull,0x093b5d302b73726full,0x31363a6469202f2full,0x616475635f5f2034ull,
0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x6f635f69695f3053ull,0x3078302b73726f6cull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x317225202c393131ull,0x31317225202c3731ull,
0x090a202f2f093b38ull,0x752e38752e747663ull,0x3231722509203233ull,0x3931317225202c30ull,
0x2f0920202020203bull,0x636f6c2e090a202full,0x0933333109363109ull,0x61702e646c090a30ull,
0x092038752e6d6172ull,0x5b202c3132317225ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x6f6c6f635f69695full,0x2f093b5d312b7372ull,0x3531363a6469202full,
0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,
0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,0x6c6f635f69695f30ull,
0x0a3178302b73726full,0x2e6f6c2e6c756d09ull,0x3172250920323373ull,0x31317225202c3232ull,
0x3132317225202c37ull,0x63090a202f2f093bull,0x33752e38752e7476ull,0x3332317225092032ull,
0x3b3232317225202cull,0x2f2f092020202020ull,0x09636f6c2e090a20ull,0x3009343331093631ull,
0x7261702e646c090aull,0x25092038752e6d61ull,0x5f5b202c34323172ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f30535f32535f32ull,0x726f6c6f635f6969ull,0x2f2f093b5d322b73ull,
0x203631363a646920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x30535f32535f3253ull,
0x6f6c6f635f69695full,0x090a3278302b7372ull,0x732e6f6c2e6c756dull,0x3231722509203233ull,
0x3731317225202c35ull,0x3b3432317225202cull,0x7663090a202f2f09ull,0x3233752e38752e74ull,
0x2c36323172250920ull,0x203b353231722520ull,0x202f2f0920202020ull,0x6e752e617262090aull,
0x355f744c24092069ull,0x203b32363930345full,0x2020202020202020ull,0x744c240a202f2f09ull,
0x38313231345f355full,0x09636f6c2e090a3aull,0x3009383331093631ull,0x33752e766f6d090aull,
0x3632317225092032ull,0x202020203b30202cull,0x2020202020202020ull,0x6f6d090a202f2f09ull,
0x2509203233752e76ull,0x3b30202c33323172ull,0x2020202020202020ull,0x202f2f0920202020ull,
0x33752e766f6d090aull,0x3032317225092032ull,0x202020203b30202cull,0x2020202020202020ull,
0x744c240a202f2f09ull,0x32363930345f355full,0x09636f6c2e090a3aull,0x3009343431093631ull,
0x7261702e646c090aull,0x09203233732e6d61ull,0x5b202c3732317225ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x6d6172665f69695full,0x69202f2f093b5d65ull,
0x5f5f203038353a64ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,
0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x695f30535f32535full,
0x2b656d6172665f69ull,0x646461090a307830ull,0x722509203233732eull,0x317225202c383231ull,
0x20203b31202c3732ull,0x0a202f2f09202020ull,0x3233732e72687309ull,0x2c39323172250920ull,
0x202c383231722520ull,0x09202020203b3133ull,0x766f6d090a202f2full,0x722509203233732eull,
0x203b31202c303331ull,0x2020202020202020ull,0x0a202f2f09202020ull,0x3233622e646e6109ull,
0x2c31333172250920ull,0x202c393231722520ull,0x09203b3033317225ull,0x646461090a202f2full,
0x722509203233732eull,0x317225202c323331ull,0x32317225202c3133ull,0x0a202f2f09203b38ull,
0x3233732e72687309ull,0x2c33333172250920ull,0x202c323331722520ull,0x0920202020203b31ull,
0x6c756d090a202f2full,0x203233732e6f6c2eull,0x202c343331722509ull,0x25202c3732317225ull,
0x202f2f093b373172ull,0x33732e646461090aull,0x3533317225092032ull,0x2c3032317225202cull,
0x203b343331722520ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x7225202c36333172ull,
0x317225202c333331ull,0x202f2f09203b3533ull,0x33732e766964090aull,0x3733317225092032ull,
0x2c3633317225202cull,0x203b383231722520ull,0x6c2e090a202f2f09ull,0x343109363109636full,
0x6c756d090a300935ull,0x203233732e6f6c2eull,0x202c383331722509ull,0x25202c3732317225ull,
0x202f2f093b383172ull,0x33732e646461090aull,0x3933317225092032ull,0x2c3332317225202cull,
0x203b383331722520ull,0x6461090a202f2f09ull,0x2509203233732e64ull,0x7225202c30343172ull,
0x317225202c333331ull,0x202f2f09203b3933ull,0x33732e766964090aull,0x3134317225092032ull,
0x2c3034317225202cull,0x203b383231722520ull,0x7473090a202f2f09ull,0x2e6c61626f6c672eull,
0x5b092038752e3276ull,0x2c5d302b34647225ull,0x2c37333172257b20ull,0x093b7d3134317225ull,
0x6f6c2e090a202f2full,0x3634310936310963ull,0x2e6c756d090a3009ull,0x09203233732e6f6cull,
0x25202c3234317225ull,0x7225202c37323172ull,0x0a202f2f093b3931ull,0x3233732e64646109ull,
0x2c33343172250920ull,0x202c363231722520ull,0x09203b3234317225ull,0x646461090a202f2full,
0x722509203233732eull,0x317225202c343431ull,0x34317225202c3333ull,0x0a202f2f09203b33ull,
0x3233732e76696409ull,0x2c35343172250920ull,0x202c343431722520ull,0x09203b3832317225ull,
0x2e7473090a202f2full,0x752e6c61626f6c67ull,0x346472255b092038ull,0x317225202c5d322bull,
0x69202f2f093b3534ull,0x4c240a3931363a64ull,0x323730335f355f74ull,0x355f744c240a3a32ull,
0x0a3a32363138325full,0x363109636f6c2e09ull,0x090a300939343109ull,0x2020203b74697865ull,
0x2020202020202020ull,0x2020202020202020ull,0x2f09202020202020ull,0x6557444c240a202full,
0x4d36315a5f5f646eull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,
0x5f54696969347261ull,0x30535f32535f3253ull,0x207d090a3a69695full,0x4d36315a5f202f2full,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,
0x30535f32535f3253ull,0x0000000a0a69695full
};


}



extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x2065646f630a7d6eull,
0x20656d616e090a7bull,0x614d36315a5f203dull,0x746f72626c65646eull,0x664930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x6d656d6c090a6969ull,
0x6d73090a30203d20ull,0x0a3036203d206d65ull,0x203d202067657209ull,0x20726162090a3531ull,
0x6f63090a30203d20ull,0x09090a7b2074736eull,0x656d616e67657309ull,0x74736e6f63203d20ull,
0x6e6765730909090aull,0x0a31203d20206d75ull,0x657366666f090909ull,0x090a30203d202074ull,
0x2073657479620909ull,0x090a3231203d2020ull,0x090a7b206d656d09ull,0x3030303078300909ull,
0x3478302066663330ull,0x2030303030303830ull,0x3030303030307830ull,0x0a7d09090a203130ull,
0x636e6962090a7d09ull,0x09090a7b2065646full,0x3230303830647830ull,0x3430307830203530ull,
0x7830203038373030ull,0x3930343030303031ull,0x3430303034783020ull,0x3009090a20303837ull,
0x3032303030306178ull,0x3030343078302064ull,0x3178302030383730ull,0x2035303230303030ull,
0x3734303030347830ull,0x783009090a203038ull,0x3930303030303061ull,0x3030303430783020ull,
0x3036783020303837ull,0x3020353165343230ull,0x3837633032303078ull,0x36783009090a2030ull,
0x2064316334313030ull,0x3738303230307830ull,0x3030337830203038ull,0x7830206466666335ull,
0x3863373031326336ull,0x3033783009090a20ull,0x3020646664633730ull,0x6332303132633678ull,
0x3030303378302038ull,0x3078302033303030ull,0x2030303130303030ull,0x303061783009090aull,
0x7830203930613030ull,0x3038373431303434ull,0x3130303031783020ull,0x3434783020313034ull,
0x0a20303837633030ull,0x3030306178300909ull,0x3478302031316530ull,0x2030383734313034ull,
0x3231303030317830ull,0x3034347830203530ull,0x090a203038376330ull,0x6432303065783009ull,
0x3030783020643036ull,0x3020303837303032ull,0x3136643430306578ull,0x3032303078302031ull,
0x09090a2030383734ull,0x3037623030347830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3830306630303131ull,0x3832303031783020ull,0x3009090a20303036ull,0x3038303030303178ull,
0x3330343078302035ull,0x6378302030383763ull,0x2038313630333030ull,0x3830343030637830ull,
0x783009090a203032ull,0x3532633030303062ull,0x3032303030783020ull,0x3062783020303837ull,
0x3020646633313138ull,0x6337303134303678ull,0x31783009090a2038ull,0x2033303039313030ull,
0x3130303030307830ull,0x3330327830203030ull,0x7830203930343866ull,0x6666666666666630ull,
0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,
0x6278302063303630ull,0x2030313031363430ull,0x303062783009090aull,0x7830206330363033ull,
0x3031323034303062ull,0x3033303062783020ull,0x3063783020633030ull,0x0a20303238303430ull,
0x3330306378300909ull,0x6278302038313630ull,0x2034326330383030ull,0x3331313830627830ull,
0x3430367830206466ull,0x090a203863373031ull,0x3132303031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3034386533303278ull,0x6666663078302039ull,0x09090a2066666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,0x6330363034303063ull,
0x3136343062783020ull,0x3009090a20303130ull,0x3036303330306278ull,0x3430306278302063ull,
0x6278302030313230ull,0x2063303030333030ull,0x3830343030637830ull,0x783009090a203032ull,
0x3831363033303063ull,0x3038303062783020ull,0x3062783020343263ull,0x3020646633313138ull,
0x6337303134303678ull,0x31783009090a2038ull,0x2033303039323030ull,0x3130303030307830ull,
0x3330327830203030ull,0x7830203930343864ull,0x6666666666666630ull,0x3035783009090a20ull,
0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,0x6278302063303630ull,
0x2030313031363430ull,0x303062783009090aull,0x7830206330363033ull,0x3031323034303062ull,
0x3033303062783020ull,0x3063783020633030ull,0x0a20303238303430ull,0x3330306378300909ull,
0x6278302038313630ull,0x2034326330383030ull,0x3331313830627830ull,0x3430367830206466ull,
0x090a203863373031ull,0x3133303031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3034386333303278ull,0x6666663078302039ull,0x09090a2066666666ull,0x3030303030357830ull,
0x3030307830203330ull,0x7830203038373030ull,0x6330363034303063ull,0x3136343062783020ull,
0x3009090a20303130ull,0x3036303330306278ull,0x3430306278302063ull,0x6278302030313230ull,
0x2063303030333030ull,0x3830343030637830ull,0x783009090a203032ull,0x3831363033303063ull,
0x3038303062783020ull,0x3062783020343263ull,0x3020646633313138ull,0x6337303134303678ull,
0x31783009090a2038ull,0x2033303039333030ull,0x3130303030307830ull,0x3330327830203030ull,
0x7830203930343862ull,0x6666666666666630ull,0x3035783009090a20ull,0x3020333030303030ull,
0x3837303030303078ull,0x3430306378302030ull,0x6278302063303630ull,0x2030313031363430ull,
0x303062783009090aull,0x7830206330363033ull,0x3031323034303062ull,0x3033303062783020ull,
0x3063783020633030ull,0x0a20303238303430ull,0x3330306378300909ull,0x6278302038313630ull,
0x2034326330383030ull,0x3331313830627830ull,0x3430367830206466ull,0x090a203863373031ull,
0x3134303031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3034386133303278ull,
0x6666663078302039ull,0x09090a2066666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x7830203038373030ull,0x6330363034303063ull,0x3136343062783020ull,0x3009090a20303130ull,
0x3036303330306278ull,0x3430306278302063ull,0x6278302030313230ull,0x2063303030333030ull,
0x3830343030637830ull,0x783009090a203032ull,0x3831363033303063ull,0x3038303062783020ull,
0x3062783020343263ull,0x3020646633313138ull,0x6337303134303678ull,0x31783009090a2038ull,
0x2033303039343030ull,0x3130303030307830ull,0x3330327830203030ull,0x7830203930343839ull,
0x6666666666666630ull,0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,
0x3430306378302030ull,0x6278302063303630ull,0x2030313031363430ull,0x303062783009090aull,
0x7830206330363033ull,0x3031323034303062ull,0x3033303062783020ull,0x3063783020633030ull,
0x0a20303238303430ull,0x3330306378300909ull,0x6278302038313630ull,0x2034326330383030ull,
0x3331313830627830ull,0x3430367830206466ull,0x090a203863373031ull,0x3135303031783009ull,
0x3030783020333030ull,0x3020303031303030ull,0x3034383833303278ull,0x6666663078302039ull,
0x09090a2066666666ull,0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,
0x6330363034303063ull,0x3136343062783020ull,0x3009090a20303130ull,0x3036303330306278ull,
0x3430306278302063ull,0x6278302030313230ull,0x2063303030333030ull,0x3830343030637830ull,
0x783009090a203032ull,0x3831363033303063ull,0x3038303062783020ull,0x3062783020343263ull,
0x3020646633313138ull,0x6337303134303678ull,0x31783009090a2038ull,0x2033303039353030ull,
0x3130303030307830ull,0x3330327830203030ull,0x7830203930343837ull,0x6666666666666630ull,
0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,
0x6278302063303630ull,0x2030313031363430ull,0x303062783009090aull,0x7830206330363033ull,
0x3031323034303062ull,0x3033303062783020ull,0x3063783020633030ull,0x0a20303238303430ull,
0x3330306378300909ull,0x6278302038313630ull,0x2034326330383030ull,0x3331313830627830ull,
0x3430367830206466ull,0x090a203863373031ull,0x3136303031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3034383633303278ull,0x6666663078302039ull,0x09090a2066666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,0x6330363034303063ull,
0x3136343062783020ull,0x3009090a20303130ull,0x3036303330306278ull,0x3430306278302063ull,
0x6278302030313230ull,0x2063303030333030ull,0x3830343030637830ull,0x783009090a203032ull,
0x3831363033303063ull,0x3038303062783020ull,0x3062783020343263ull,0x3020646633313138ull,
0x6337303134303678ull,0x31783009090a2038ull,0x2033303039363030ull,0x3130303030307830ull,
0x3330327830203030ull,0x7830203930343835ull,0x6666666666666630ull,0x3035783009090a20ull,
0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,0x6278302063303630ull,
0x2030313031363430ull,0x303062783009090aull,0x7830206330363033ull,0x3031323034303062ull,
0x3033303062783020ull,0x3063783020633030ull,0x0a20303238303430ull,0x3330306378300909ull,
0x6278302038313630ull,0x2034326330383030ull,0x3331313830627830ull,0x3430367830206466ull,
0x090a203863373031ull,0x3137303031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3034383433303278ull,0x6666663078302039ull,0x09090a2066666666ull,0x3030303030357830ull,
0x3030307830203330ull,0x7830203038373030ull,0x6330363034303063ull,0x3136343062783020ull,
0x3009090a20303130ull,0x3036303330306278ull,0x3430306278302063ull,0x6278302030313230ull,
0x2063303030333030ull,0x3830343030637830ull,0x783009090a203032ull,0x3831363033303063ull,
0x3038303062783020ull,0x3062783020343263ull,0x3020646633313138ull,0x6337303134303678ull,
0x31783009090a2038ull,0x2033303039373030ull,0x3130303030307830ull,0x3330327830203030ull,
0x7830203930343833ull,0x6666666666666630ull,0x3035783009090a20ull,0x3020333030303030ull,
0x3837303030303078ull,0x3430306378302030ull,0x6278302063303630ull,0x2030313031363430ull,
0x303062783009090aull,0x7830206330363033ull,0x3031323034303062ull,0x3033303062783020ull,
0x3063783020633030ull,0x0a20303238303430ull,0x3330306378300909ull,0x6278302038313630ull,
0x2034326330383030ull,0x3331313830627830ull,0x3430367830206466ull,0x090a203863373031ull,
0x3138303031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3034383233303278ull,
0x6666663078302039ull,0x09090a2066666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x7830203038373030ull,0x6330363034303063ull,0x3136343062783020ull,0x3009090a20303130ull,
0x3036303330306278ull,0x3430306278302063ull,0x6278302030313230ull,0x2063303030333030ull,
0x3830343030637830ull,0x783009090a203032ull,0x3831363033303063ull,0x3038303062783020ull,
0x3062783020343263ull,0x3020646633313138ull,0x6337303134303678ull,0x31783009090a2038ull,
0x2033303039383030ull,0x3130303030307830ull,0x3330327830203030ull,0x7830203930343831ull,
0x6666666666666630ull,0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,
0x3430306378302030ull,0x6278302063303630ull,0x2030313031363430ull,0x303062783009090aull,
0x7830206330363033ull,0x3031323034303062ull,0x3033303062783020ull,0x3063783020633030ull,
0x0a20303238303430ull,0x3330306378300909ull,0x6278302038313630ull,0x2034326330383030ull,
0x3331313830627830ull,0x3430367830206466ull,0x090a203863373031ull,0x3139303031783009ull,
0x3030783020333030ull,0x3020303031303030ull,0x3034383033303278ull,0x6666663078302039ull,
0x09090a2066666666ull,0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,
0x6330363034303063ull,0x3136343062783020ull,0x3009090a20303130ull,0x3036303330306278ull,
0x3430306278302063ull,0x6278302030313230ull,0x2063303030333030ull,0x3830343030637830ull,
0x783009090a203032ull,0x3831363033303063ull,0x3038303062783020ull,0x3062783020343263ull,
0x3020646633313138ull,0x6337303134303678ull,0x31783009090a2038ull,0x2033303039393030ull,
0x3130303030307830ull,0x3230327830203030ull,0x7830203930343866ull,0x6666666666666630ull,
0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,
0x6278302063303630ull,0x2030313031363430ull,0x303062783009090aull,0x7830206330363033ull,
0x3031323034303062ull,0x3033303062783020ull,0x3063783020633030ull,0x0a20303238303430ull,
0x3330306378300909ull,0x6278302038313630ull,0x2034326330383030ull,0x3331313830627830ull,
0x3430367830206466ull,0x090a203863373031ull,0x3161303031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3034386532303278ull,0x6666663078302039ull,0x09090a2066666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,0x6330363034303063ull,
0x3136343062783020ull,0x3009090a20303130ull,0x3036303330306278ull,0x3430306278302063ull,
0x6278302030313230ull,0x2063303030333030ull,0x3830343030637830ull,0x783009090a203032ull,
0x3831363033303063ull,0x3038303062783020ull,0x3062783020343263ull,0x3020646633313138ull,
0x6337303134303678ull,0x31783009090a2038ull,0x2033303039613030ull,0x3130303030307830ull,
0x3230327830203030ull,0x7830203930343864ull,0x6666666666666630ull,0x3035783009090a20ull,
0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,0x6278302063303630ull,
0x2063303630333030ull,0x323032783009090aull,0x7830203930343863ull,0x6666666666666630ull,
0x3136343062783020ull,0x3062783020303130ull,0x0a20633030303330ull,0x6337303378300909ull,
0x3678302064663530ull,0x2038633763303063ull,0x3230343030627830ull,0x3030637830203031ull,
0x090a203831363033ull,0x3262303031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3238303430306378ull,0x3630306278302030ull,0x09090a2034323031ull,0x3331313830627830ull,
0x3430367830206466ull,0x7830203863373031ull,0x3330303362303031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3030303030303578ull,0x3030303078302033ull,0x6378302030383730ull,
0x2063303630343030ull,0x3031363430627830ull,0x783009090a203031ull,0x6330363033303062ull,
0x3034303062783020ull,0x3062783020303132ull,0x3020643030303030ull,0x3837633030303078ull,
0x31783009090a2030ull,0x2033303033313030ull,0x3730303030307830ull,0x3730337830203038ull,
0x7830203530343063ull,0x3038373031306336ull,0x3032783009090a20ull,0x3020313030643034ull,
0x3837383032343078ull,0x3130306478302030ull,0x3078302031303030ull,0x2030383730303034ull,
0x373033783009090aull,0x7830206466313063ull,0x3863373830306336ull,0x3164303061783020ull,
0x3030783020333030ull,0x0a20303030303030ull,0x6330303178300909ull,0x3078302033303065ull,
0x2030383230303030ull,0x3036303030647830ull,0x3030327830203530ull,0x090a203038373030ull,
0x6430303032783009ull,0x3430783020313063ull,0x3020303837303032ull,0x3030303030346178ull,
0x3032303078302039ull,0x09090a2030383738ull,0x3230303034617830ull,0x3230307830203931ull,
0x7830203038373830ull,0x6431343030303461ull,0x3830323030783020ull,0x3009090a20303837ull,
0x3032303230303478ull,0x3630303478302038ull,0x3478302030313230ull,0x2039313230373030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3930343030313033ull,0x3030313463783020ull,
0x3033783020303837ull,0x3020313138303031ull,0x3837303031346378ull,0x33783009090a2030ull,
0x2039316330303130ull,0x3730303134637830ull,0x3030367830203038ull,0x7830203530303032ull,
0x3038373830303030ull,0x3036783009090a20ull,0x3020393030303630ull,0x3837303130303078ull,
0x3730303678302030ull,0x3078302031303030ull,0x2030383738313030ull,0x303061783009090aull,
0x7830206430323030ull,0x3038376330303430ull,0x3030303061783020ull,0x3430783020313134ull,
0x0a20303837633030ull,0x3030306178300909ull,0x3078302039313030ull,0x2030383763303034ull,
0x3031643030317830ull,0x3030307830203330ull,0x090a203038373030ull,0x6630303031783009ull,
0x3630783020393138ull,0x3020303837633330ull,0x3038663030303178ull,0x3330343078302064ull,
0x09090a2030383763ull,0x3866303030317830ull,0x3036307830203131ull,0x7830203038376333ull,
0x3130633030303031ull,0x6330303434783020ull,0x3009090a20323837ull,0x3030306230303478ull,
0x3030303078302035ull,0x3678302030383730ull,0x2035303230613030ull,0x3734303030307830ull,
0x783009090a203038ull,0x3530323030313033ull,0x3030313463783020ull,0x3036783020303837ull,
0x3020313030306130ull,0x3837343030303078ull,0x32783009090a2030ull,0x2031303030303030ull,
0x3763313034307830ull,0x3030337830203038ull,0x7830203130303032ull,0x3038373030313463ull,
0x3033783009090a20ull,0x3020646662646337ull,0x6337343132633678ull,0x3030303278302038ull,
0x3078302064313863ull,0x2030383730303234ull,0x303031783009090aull,0x7830203330303165ull,
0x3038323030303030ull,0x3030303061783020ull,0x3030783020313036ull,0x0a20303837633030ull,
0x3830303378300909ull,0x6378302039303031ull,0x2030383730303130ull,0x6330303030617830ull,
0x3030307830203530ull,0x090a203038376330ull,0x3032303064783009ull,0x3030783020313030ull,
0x3020303837343030ull,0x3065306530306478ull,0x3063306178302031ull,0x09090a2030383730ull,
0x3030303030337830ull,0x3030307830203330ull,0x7830203038373030ull,0x3531653065303064ull,
0x3030633038783020ull,0x3009090a20303837ull,0x3061313030303178ull,0x3030343478302035ull,
0x6178302030383763ull,0x2039343431303030ull,0x3738303030307830ull,0x783009090a203038ull,
0x3930616631303132ull,0x3030303030783020ull,0x3033783020333030ull,0x3020313061303830ull,
0x3837303031346578ull,0x34783009090a2030ull,0x2039323630323130ull,0x3730303030307830ull,
0x3130337830203038ull,0x7830203132343066ull,0x3038373030316365ull,0x3061783009090a20ull,
0x3020313030303030ull,0x3837383030303078ull,0x3031303378302030ull,0x6378302039323431ull,
0x2030383730303134ull,0x383064783009090aull,0x7830203132303132ull,0x3038373030343430ull,
0x3030303034783020ull,0x3030783020643236ull,0x0a20303837303030ull,0x3231303678300909ull,
0x3078302035323430ull,0x2030383738323030ull,0x3031303030327830ull,0x3034307830203132ull,
0x090a203038373830ull,0x3130313033783009ull,0x3463783020393236ull,0x3020303837303031ull,
0x3232313030303278ull,0x3030343078302035ull,0x09090a2030383763ull,0x3031313030337830ull,
0x3163657830203132ull,0x7830203038373030ull,0x3932343030303036ull,0x3832303030783020ull,
0x3009090a20303837ull,0x3034383030303178ull,0x3930303278302063ull,0x3278302030303039ull,
0x2039333431303030ull,0x3730313034307830ull,0x783009090a203038ull,0x3330303730313032ull,
0x3030303030783020ull,0x3031783020303837ull,0x3020303130383230ull,0x3034383030303178ull,
0x32783009090a2063ull,0x2031303031303030ull,0x3738333034307830ull,0x3030617830203038ull,
0x7830203132383030ull,0x3038376330303030ull,0x3032783009090a20ull,0x3020333030373031ull,
0x3837303030303078ull,0x3030306178302030ull,0x3078302039313631ull,0x2030383738303030ull,
0x303034783009090aull,0x7830203531363036ull,0x3038373030303030ull,0x3030313033783020ull,
0x3463783020353161ull,0x0a20303837303031ull,0x3630303678300909ull,0x3078302035303430ull,
0x2030383734313030ull,0x3238363030327830ull,0x3030317830206330ull,0x090a203430303832ull,
0x3130303032783009ull,0x3430783020313030ull,0x3020303837633030ull,0x3034303830303378ull,
0x3031306378302039ull,0x09090a2030383730ull,0x3430303030317830ull,0x3034307830206430ull,
0x7830203038376333ull,0x3330303730313032ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3030313230306478ull,0x3030303078302039ull,0x6478302030383734ull,0x2035306530653030ull,
0x3730303430617830ull,0x783009090a203038ull,0x3530653832303032ull,0x3030303030783020ull,
0x3064783020333030ull,0x3020313032306530ull,0x3837303030306178ull,0x33783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030617830203038ull,0x7830203532363030ull,
0x3038373431313430ull,0x3061783009090a20ull,0x3020393232313030ull,0x3837343030343478ull,
0x3030306178302030ull,0x3078302064323030ull,0x2030383734313134ull,0x303039783009090aull,
0x7830203133343130ull,0x3038373030303030ull,0x3130303061783020ull,0x3434783020393236ull,
0x0a20303837343630ull,0x6533303278300909ull,0x3078302031333839ull,0x2066666666666666ull,
0x3431633030637830ull,0x3030307830203932ull,0x090a203063376330ull,0x3130303061783009ull,
0x3438783020393234ull,0x3020303837343630ull,0x3334323531303478ull,0x3030303078302035ull,
0x09090a2030383730ull,0x3632343130367830ull,0x3030307830203533ull,0x7830203038373433ull,
0x3533613130313033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3334323431303678ull,
0x3330303078302035ull,0x3278302030383734ull,0x2035333631303430ull,0x3734333034307830ull,
0x783009090a203038ull,0x3533613130303061ull,0x3436303434783020ull,0x3063783020303837ull,
0x3020313361316330ull,0x6337633030303078ull,0x61783009090a2030ull,0x2031333831303030ull,
0x3734363034387830ull,0x3030327830203038ull,0x7830203932343130ull,0x3038373033303430ull,
0x3034783009090a20ull,0x3020313361323231ull,0x3837303030303078ull,0x3331303678302030ull,
0x3078302031333832ull,0x2030383730333030ull,0x313033783009090aull,0x7830203133383130ull,
0x3038373030313463ull,0x3232313036783020ull,0x3030783020313338ull,0x0a20303837303330ull,
0x3030303378300909ull,0x3078302064323831ull,0x2030383763323034ull,0x3231623030337830ull,
0x3034367830203532ull,0x090a203038376330ull,0x3030303064783009ull,0x3430783020313036ull,
0x3020303837383030ull,0x3030306631303378ull,0x3031346578302031ull,0x09090a2030383730ull,
0x3231303030337830ull,0x3034307830203932ull,0x7830203038373832ull,0x3532303030303061ull,
0x3431306332783020ull,0x3009090a20303837ull,0x3232316130306478ull,0x3030343078302035ull,
0x3378302030383738ull,0x2064663730633730ull,0x3734313063367830ull,0x783009090a203863ull,
0x3130303030303032ull,0x3432303430783020ull,0x3064783020303837ull,0x3020313030303330ull,
0x3035633230343078ull,0x33783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,
0x3030667830203038ull,0x7830203130303030ull,0x3130303030303065ull,0x630a7d0a7d090a20ull,
0x6e090a7b2065646full,0x5a5f203d20656d61ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x090a69695f30535full,
0x30203d206d656d6cull,0x3d206d656d73090aull,0x676572090a303620ull,0x090a3531203d2020ull,
0x30203d2020726162ull,0x2074736e6f63090aull,0x6765730909090a7bull,0x63203d20656d616eull,
0x0909090a74736e6full,0x20206d756e676573ull,0x6f0909090a31203dull,0x3d20207465736666ull,
0x79620909090a3020ull,0x203d202020736574ull,0x6d656d09090a3631ull,0x78300909090a7b20ull,
0x6666333030303030ull,0x3030303030783020ull,0x3034783020613030ull,0x3020303030303038ull,
0x3030303030303078ull,0x090a7d09090a2031ull,0x6f636e6962090a7dull,0x3009090a7b206564ull,
0x3032303038306478ull,0x3034303078302035ull,0x3178302030383730ull,0x2039303430303030ull,
0x3734303030347830ull,0x783009090a203038ull,0x6430323030303061ull,0x3030303430783020ull,
0x3031783020303837ull,0x3020353032303030ull,0x3837343030303478ull,0x61783009090a2030ull,
0x2039303030303030ull,0x3730303034307830ull,0x3030367830203038ull,0x7830203530653432ull,
0x3038376330323030ull,0x3036783009090a20ull,0x3020643063343130ull,0x3837383032303078ull,
0x3130303378302030ull,0x3678302064666663ull,0x2038633730313263ull,0x303033783009090aull,
0x7830206466646333ull,0x3863323031326336ull,0x3030303033783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303178300909ull,0x3478302031306330ull,0x2030383763303034ull,
0x3030333030347830ull,0x3030307830203930ull,0x090a203038373030ull,0x3032303036783009ull,
0x3030783020393032ull,0x3020303837383030ull,0x3034303031303378ull,0x3031346378302039ull,
0x09090a2030383730ull,0x3030323030367830ull,0x3030307830203130ull,0x7830203038373830ull,
0x6431303030303032ull,0x6330303430783020ull,0x3009090a20303837ull,0x3065303230303378ull,
0x3031346378302031ull,0x3278302030383730ull,0x2031323863303030ull,0x3730303234307830ull,
0x783009090a203038ull,0x3130303165303064ull,0x3030633038783020ull,0x3033783020303837ull,
0x3020393030303830ull,0x3837303031346578ull,0x33783009090a2030ull,0x2064663730633730ull,
0x3763303063367830ull,0x3030617830203863ull,0x7830203330306432ull,0x3030303030303030ull,
0x3061783009090a20ull,0x3020393130303030ull,0x3837383030343078ull,0x3030306178302030ull,
0x3078302031313230ull,0x2030383738303034ull,0x303061783009090aull,0x7830203531383030ull,
0x3038373830303430ull,0x6332303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,
0x6333303278300909ull,0x3078302031303039ull,0x2066666666666666ull,0x3030653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x3038303033783009ull,0x3465783020393030ull,
0x3020303837303031ull,0x3230303030306178ull,0x3030343078302035ull,0x09090a2030383738ull,
0x3830303030617830ull,0x3034307830203930ull,0x7830203038373830ull,0x3432323936343032ull,
0x3835343032783020ull,0x3009090a20383234ull,0x3032303030306178ull,0x3030343078302031ull,
0x6178302030383738ull,0x2039303231303030ull,0x3734313134307830ull,0x783009090a203038ull,
0x3532343130303061ull,0x3431313430783020ull,0x3032783020303837ull,0x3020313030303034ull,
0x3837303130343078ull,0x33783009090a2030ull,0x2039303430313830ull,0x3730313463367830ull,
0x3830337830203038ull,0x7830203532323131ull,0x3038373031346336ull,0x3061783009090a20ull,
0x3020313030303030ull,0x3837343131343078ull,0x3930306478302030ull,0x3078302039303430ull,
0x2030383734303034ull,0x383033783009090aull,0x7830203130303031ull,0x3038373031346336ull,
0x3032303064783020ull,0x3430783020313030ull,0x0a20303837343030ull,0x3030306178300909ull,
0x3278302035323030ull,0x2030383734313063ull,0x3064323030317830ull,0x3030307830203330ull,
0x090a203038373030ull,0x6630303031783009ull,0x3630783020353238ull,0x3020303837633330ull,
0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,0x3034343030617830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3130363831303032ull,0x3030303030783020ull,
0x3009090a20333030ull,0x6664633030303378ull,0x3032633678302064ull,0x3178302038633763ull,
0x2033303034343030ull,0x3230303030307830ull,0x783009090a203038ull,0x3130303934303032ull,
0x3030303030783020ull,0x3064783020333030ull,0x3020313030306530ull,0x3837303063303878ull,
0x33783009090a2030ull,0x2039303030383030ull,0x3730303134657830ull,0x3030617830203038ull,
0x7830203932303030ull,0x3038373830303430ull,0x3061783009090a20ull,0x3020393038303030ull,
0x3837383030343078ull,0x3634303278302030ull,0x3278302038323439ull,0x2063323438353430ull,
0x303061783009090aull,0x7830203130323030ull,0x3038373830303430ull,0x3130303061783020ull,
0x3430783020393034ull,0x0a20303837343131ull,0x3030306178300909ull,0x3078302039323631ull,
0x2030383734313134ull,0x3030303430327830ull,0x3034307830203130ull,0x090a203038373031ull,
0x3031383033783009ull,0x6336783020393034ull,0x3020303837303134ull,0x3234313138303378ull,
0x3134633678302039ull,0x09090a2030383730ull,0x3030303030617830ull,0x3134307830203130ull,
0x7830203038373431ull,0x3930343061303064ull,0x3430303430783020ull,0x3009090a20303837ull,
0x3030303138303378ull,0x3134633678302031ull,0x6478302030383730ull,0x2031303030323030ull,
0x3734303034307830ull,0x783009090a203038ull,0x3130303030303061ull,0x3431306332783020ull,
0x3032783020303837ull,0x3020353232313030ull,0x3837303030343078ull,0x33783009090a2030ull,
0x2064663330633730ull,0x3763303063367830ull,0x3030617830206163ull,0x7830203330306235ull,
0x3030303030303030ull,0x3031783009090a20ull,0x3020333030623530ull,0x3832303030303078ull,
0x3030303378302030ull,0x3078302031306363ull,0x2030383763313234ull,0x303033783009090aull,
0x7830203130303032ull,0x3038373030313463ull,0x6330303032783020ull,0x3430783020313038ull,
0x0a20303837303032ull,0x6530306478300909ull,0x3878302031303030ull,0x2030383730306330ull,
0x3030383030337830ull,0x3134657830203930ull,0x090a203038373030ull,0x3030303061783009ull,
0x3430783020393230ull,0x3020303837383030ull,0x3038303030306178ull,0x3030343078302039ull,
0x09090a2030383738ull,0x3439363430327830ull,0x3430327830203832ull,0x7830206332343835ull,
0x3130323030303061ull,0x3830303430783020ull,0x3009090a20303837ull,0x3034313030306178ull,
0x3131343078302039ull,0x6178302030383734ull,0x2039323631303030ull,0x3734313134307830ull,
0x783009090a203038ull,0x3130303030343032ull,0x3031303430783020ull,0x3033783020303837ull,
0x3020393034303138ull,0x3837303134633678ull,0x33783009090a2030ull,0x2039323431313830ull,
0x3730313463367830ull,0x3030617830203038ull,0x7830203130303030ull,0x3038373431313430ull,
0x3064783009090a20ull,0x3020393034306130ull,0x3837343030343078ull,0x3138303378302030ull,
0x3678302031303030ull,0x2030383730313463ull,0x303064783009090aull,0x7830203130303032ull,
0x3038373430303430ull,0x3030303061783020ull,0x6332783020313030ull,0x0a20303837343130ull,
0x3030303278300909ull,0x3078302035323231ull,0x2030383730303034ull,0x3030303030667830ull,
0x3030657830203130ull,0x090a203230303030ull,0x3437303061783009ull,0x3030783020333030ull,
0x3020303030303030ull,0x3032383130303278ull,0x3030303078302031ull,0x09090a2033303030ull,
0x6663303030337830ull,0x3263367830206466ull,0x7830203863376330ull,0x3330303437303031ull,
0x3030303030783020ull,0x3009090a20303832ull,0x3063633030303278ull,0x3132343078302031ull,
0x3378302030383763ull,0x2031303030323030ull,0x3730303134637830ull,0x783009090a203038ull,
0x3130386330303032ull,0x3030323430783020ull,0x3064783020303837ull,0x3020313030306530ull,
0x3837303063303878ull,0x33783009090a2030ull,0x2039303030383030ull,0x3730303134657830ull,
0x3030617830203038ull,0x7830206431303030ull,0x3038373830303430ull,0x3061783009090a20ull,
0x3020393038303030ull,0x3837383030343078ull,0x3634303278302030ull,0x3278302063316538ull,
0x2038323438353430ull,0x303061783009090aull,0x7830203130323030ull,0x3038373830303430ull,
0x3030303061783020ull,0x3430783020393065ull,0x0a20303837343131ull,0x3030306178300909ull,
0x3078302064313431ull,0x2030383734313134ull,0x3030303430327830ull,0x3034307830203130ull,
0x090a203038373031ull,0x3031383033783009ull,0x6336783020393034ull,0x3020303837303134ull,
0x3165303138303378ull,0x3134633678302064ull,0x09090a2030383730ull,0x3030303030617830ull,
0x3134307830203130ull,0x7830203038373431ull,0x3930343037303064ull,0x3430303430783020ull,
0x3009090a20303837ull,0x3030303138303378ull,0x3134633678302031ull,0x6478302030383730ull,
0x2031303030323030ull,0x3734303034307830ull,0x783009090a203038ull,0x3130303030303061ull,
0x3431306332783020ull,0x3032783020303837ull,0x3020353232313030ull,0x3837303030343078ull,
0x33783009090a2030ull,0x2064663331633730ull,0x3738303063367830ull,0x3030337830206163ull,
0x7830203330303030ull,0x3038323030303030ull,0x3061783009090a20ull,0x3020643136303030ull,
0x3837343130343478ull,0x3030306178302030ull,0x3478302039303230ull,0x2030383734313034ull,
0x303131783009090aull,0x7830203030346630ull,0x3430326630303131ull,0x6432303065783020ull,
0x3030783020643036ull,0x0a20303837303032ull,0x3730306578300909ull,0x3078302064313664ull,
0x2030383734303230ull,0x3032323130347830ull,0x3030307830203330ull,0x090a203030303030ull,
0x6630303131783009ull,0x3031783020383030ull,0x3020303036383030ull,0x3065303030303178ull,
0x3330363078302035ull,0x09090a2030383763ull,0x3630333030637830ull,0x3030637830203432ull,
0x7830203832653037ull,0x6432323130303062ull,0x3832303030783020ull,0x3009090a20303837ull,
0x6637313238306278ull,0x3134303678302064ull,0x3178302038633730ull,0x2033303034383030ull,
0x3130303030307830ull,0x783009090a203030ull,0x3930343866333032ull,0x6666666630783020ull,
0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,
0x2063303630373030ull,0x3431393430627830ull,0x3030627830206331ull,0x7830206330363033ull,
0x6331323037303062ull,0x3062783009090a20ull,0x3020633030303330ull,0x3265303730306378ull,
0x3330306378302038ull,0x6278302034323630ull,0x2063323231613030ull,0x383062783009090aull,
0x7830206466373132ull,0x3863373031343036ull,0x6338303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x6533303278300909ull,0x3078302039303438ull,0x2066666666666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3037303063783009ull,
0x3062783020633036ull,0x3020633134313934ull,0x3036303330306278ull,0x3730306278302063ull,
0x09090a2063313230ull,0x3030333030627830ull,0x3030637830206330ull,0x7830203832653037ull,
0x3432363033303063ull,0x3161303062783020ull,0x3009090a20633232ull,0x6637313238306278ull,
0x3134303678302064ull,0x3178302038633730ull,0x2033303034393030ull,0x3130303030307830ull,
0x783009090a203030ull,0x3930343864333032ull,0x6666666630783020ull,0x3035783020666666ull,
0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,0x2063303630373030ull,
0x3431393430627830ull,0x3030627830206331ull,0x7830206330363033ull,0x6331323037303062ull,
0x3062783009090a20ull,0x3020633030303330ull,0x3265303730306378ull,0x3330306378302038ull,
0x6278302034323630ull,0x2063323231613030ull,0x383062783009090aull,0x7830206466373132ull,
0x3863373031343036ull,0x6339303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x6333303278300909ull,0x3078302039303438ull,0x2066666666666666ull,0x3030303030357830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3037303063783009ull,0x3062783020633036ull,
0x3020633134313934ull,0x3036303330306278ull,0x3730306278302063ull,0x09090a2063313230ull,
0x3030333030627830ull,0x3030637830206330ull,0x7830203832653037ull,0x3432363033303063ull,
0x3161303062783020ull,0x3009090a20633232ull,0x6637313238306278ull,0x3134303678302064ull,
0x3178302038633730ull,0x2033303034613030ull,0x3130303030307830ull,0x783009090a203030ull,
0x3930343862333032ull,0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,
0x3837303030303078ull,0x63783009090a2030ull,0x2063303630373030ull,0x3431393430627830ull,
0x3030627830206331ull,0x7830206330363033ull,0x6331323037303062ull,0x3062783009090a20ull,
0x3020633030303330ull,0x3265303730306378ull,0x3330306378302038ull,0x6278302034323630ull,
0x2063323231613030ull,0x383062783009090aull,0x7830206466373132ull,0x3863373031343036ull,
0x6361303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x6133303278300909ull,
0x3078302039303438ull,0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3037303063783009ull,0x3062783020633036ull,0x3020633134313934ull,
0x3036303330306278ull,0x3730306278302063ull,0x09090a2063313230ull,0x3030333030627830ull,
0x3030637830206330ull,0x7830203832653037ull,0x3432363033303063ull,0x3161303062783020ull,
0x3009090a20633232ull,0x6637313238306278ull,0x3134303678302064ull,0x3178302038633730ull,
0x2033303034623030ull,0x3130303030307830ull,0x783009090a203030ull,0x3930343839333032ull,
0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,
0x63783009090a2030ull,0x2063303630373030ull,0x3431393430627830ull,0x3030627830206331ull,
0x7830206330363033ull,0x6331323037303062ull,0x3062783009090a20ull,0x3020633030303330ull,
0x3265303730306378ull,0x3330306378302038ull,0x6278302034323630ull,0x2063323231613030ull,
0x383062783009090aull,0x7830206466373132ull,0x3863373031343036ull,0x6362303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3833303278300909ull,0x3078302039303438ull,
0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3037303063783009ull,0x3062783020633036ull,0x3020633134313934ull,0x3036303330306278ull,
0x3730306278302063ull,0x09090a2063313230ull,0x3030333030627830ull,0x3030637830206330ull,
0x7830203832653037ull,0x3432363033303063ull,0x3161303062783020ull,0x3009090a20633232ull,
0x6637313238306278ull,0x3134303678302064ull,0x3178302038633730ull,0x2033303034633030ull,
0x3130303030307830ull,0x783009090a203030ull,0x3930343837333032ull,0x6666666630783020ull,
0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,
0x2063303630373030ull,0x3431393430627830ull,0x3030627830206331ull,0x7830206330363033ull,
0x6331323037303062ull,0x3062783009090a20ull,0x3020633030303330ull,0x3265303730306378ull,
0x3330306378302038ull,0x6278302034323630ull,0x2063323231613030ull,0x383062783009090aull,
0x7830206466373132ull,0x3863373031343036ull,0x6363303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3633303278300909ull,0x3078302039303438ull,0x2066666666666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3037303063783009ull,
0x3062783020633036ull,0x3020633134313934ull,0x3036303330306278ull,0x3730306278302063ull,
0x09090a2063313230ull,0x3030333030627830ull,0x3030637830206330ull,0x7830203832653037ull,
0x3432363033303063ull,0x3161303062783020ull,0x3009090a20633232ull,0x6637313238306278ull,
0x3134303678302064ull,0x3178302038633730ull,0x2033303034643030ull,0x3130303030307830ull,
0x783009090a203030ull,0x3930343835333032ull,0x6666666630783020ull,0x3035783020666666ull,
0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,0x2063303630373030ull,
0x3431393430627830ull,0x3030627830206331ull,0x7830206330363033ull,0x6331323037303062ull,
0x3062783009090a20ull,0x3020633030303330ull,0x3265303730306378ull,0x3330306378302038ull,
0x6278302034323630ull,0x2063323231613030ull,0x383062783009090aull,0x7830206466373132ull,
0x3863373031343036ull,0x6364303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3433303278300909ull,0x3078302039303438ull,0x2066666666666666ull,0x3030303030357830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3037303063783009ull,0x3062783020633036ull,
0x3020633134313934ull,0x3036303330306278ull,0x3730306278302063ull,0x09090a2063313230ull,
0x3030333030627830ull,0x3030637830206330ull,0x7830203832653037ull,0x3432363033303063ull,
0x3161303062783020ull,0x3009090a20633232ull,0x6637313238306278ull,0x3134303678302064ull,
0x3178302038633730ull,0x2033303034653030ull,0x3130303030307830ull,0x783009090a203030ull,
0x3930343833333032ull,0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,
0x3837303030303078ull,0x63783009090a2030ull,0x2063303630373030ull,0x3431393430627830ull,
0x3030627830206331ull,0x7830206330363033ull,0x6331323037303062ull,0x3062783009090a20ull,
0x3020633030303330ull,0x3265303730306378ull,0x3330306378302038ull,0x6278302034323630ull,
0x2063323231613030ull,0x383062783009090aull,0x7830206466373132ull,0x3863373031343036ull,
0x6365303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3233303278300909ull,
0x3078302039303438ull,0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3037303063783009ull,0x3062783020633036ull,0x3020633134313934ull,
0x3036303330306278ull,0x3730306278302063ull,0x09090a2063313230ull,0x3030333030627830ull,
0x3030637830206330ull,0x7830203832653037ull,0x3432363033303063ull,0x3161303062783020ull,
0x3009090a20633232ull,0x6637313238306278ull,0x3134303678302064ull,0x3178302038633730ull,
0x2033303034663030ull,0x3130303030307830ull,0x783009090a203030ull,0x3930343831333032ull,
0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,
0x63783009090a2030ull,0x2063303630373030ull,0x3431393430627830ull,0x3030627830206331ull,
0x7830206330363033ull,0x6331323037303062ull,0x3062783009090a20ull,0x3020633030303330ull,
0x3265303730306378ull,0x3330306378302038ull,0x6278302034323630ull,0x2063323231613030ull,
0x383062783009090aull,0x7830206466373132ull,0x3863373031343036ull,0x6366303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3033303278300909ull,0x3078302039303438ull,
0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3037303063783009ull,0x3062783020633036ull,0x3020633134313934ull,0x3036303330306278ull,
0x3730306278302063ull,0x09090a2063313230ull,0x3030333030627830ull,0x3030637830206330ull,
0x7830203832653037ull,0x3432363033303063ull,0x3161303062783020ull,0x3009090a20633232ull,
0x6637313238306278ull,0x3134303678302064ull,0x3178302038633730ull,0x2033303034303130ull,
0x3130303030307830ull,0x783009090a203030ull,0x3930343866323032ull,0x6666666630783020ull,
0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,
0x2063303630373030ull,0x3431393430627830ull,0x3030627830206331ull,0x7830206330363033ull,
0x6331323037303062ull,0x3062783009090a20ull,0x3020633030303330ull,0x3265303730306378ull,
0x3330306378302038ull,0x6278302034323630ull,0x2063323231613030ull,0x383062783009090aull,
0x7830206466373132ull,0x3863373031343036ull,0x6330313031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x6532303278300909ull,0x3078302039303438ull,0x2066666666666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3037303063783009ull,
0x3062783020633036ull,0x3020633134313934ull,0x3036303330306278ull,0x3730306278302063ull,
0x09090a2063313230ull,0x3030333030627830ull,0x3030637830206330ull,0x7830203832653037ull,
0x3432363033303063ull,0x3161303062783020ull,0x3009090a20633232ull,0x6637313238306278ull,
0x3134303678302064ull,0x3178302038633730ull,0x2033303034313130ull,0x3130303030307830ull,
0x783009090a203030ull,0x3930343864323032ull,0x6666666630783020ull,0x3035783020666666ull,
0x3020333030303030ull,0x3837303030303078ull,0x63783009090a2030ull,0x2063303630373030ull,
0x3630333030627830ull,0x3230327830206330ull,0x7830203930343863ull,0x6666666666666630ull,
0x3062783009090a20ull,0x3020633134313934ull,0x3030303330306278ull,0x6337303378302063ull,
0x3678302064663530ull,0x2038633763303063ull,0x303062783009090aull,0x7830206331323037ull,
0x3432363033303063ull,0x6431313031783020ull,0x3030783020333030ull,0x0a20303832303030ull,
0x3730306378300909ull,0x6278302038326530ull,0x2063323431393030ull,0x3731323830627830ull,
0x3430367830206466ull,0x090a203863373031ull,0x6531313031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3630373030637830ull,0x3430627830206330ull,0x7830206331343139ull,0x6330363033303062ull,
0x3037303062783020ull,0x3009090a20633132ull,0x3030303030306278ull,0x3030303078302064ull,
0x3178302030383763ull,0x2033303065373030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3530343063373033ull,0x3031306336783020ull,0x3032783020303837ull,0x3020313030643034ull,
0x3837383032343078ull,0x64783009090a2030ull,0x2031303030313030ull,0x3730303034307830ull,
0x3730337830203038ull,0x7830206466313063ull,0x3863373830306336ull,0x3061783009090a20ull,
0x3020333030633331ull,0x3030303030303078ull,0x3331303178302030ull,0x3078302033303039ull,
0x2030383230303030ull,0x303064783009090aull,0x7830203530303630ull,0x3038373030303032ull,
0x6430303032783020ull,0x3430783020313063ull,0x0a20303837303032ull,0x3030346178300909ull,
0x3078302039303030ull,0x2030383738303230ull,0x3230303034617830ull,0x3230307830203931ull,
0x090a203038373830ull,0x3030303461783009ull,0x3030783020643134ull,0x3020303837383032ull,
0x3032303230303478ull,0x3630303478302038ull,0x09090a2063313230ull,0x3230373030347830ull,
0x3030307830203532ull,0x7830203038373030ull,0x3930343030313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3165303031303378ull,0x3031346378302064ull,0x3378302030383730ull,
0x2035323231303130ull,0x3730303134637830ull,0x783009090a203038ull,0x3530303032303036ull,
0x3830303030783020ull,0x3036783020303837ull,0x3020393030303630ull,0x3837633130303078ull,
0x36783009090a2030ull,0x2064303030373030ull,0x3734323030307830ull,0x3030617830203038ull,
0x7830203130323030ull,0x3038376330303430ull,0x3061783009090a20ull,0x3020353234303030ull,
0x3837633030343078ull,0x3030306178302030ull,0x3078302064313630ull,0x2030383763303034ull,
0x313031783009090aull,0x7830203330306333ull,0x3038373030303030ull,0x6630303031783020ull,
0x3430783020643138ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302035323866ull,
0x2030383763333036ull,0x3866303030317830ull,0x3034307830203130ull,0x090a203038376333ull,
0x3130303031783009ull,0x3434783020353061ull,0x3020323837633030ull,0x3034306430303478ull,
0x3030303078302064ull,0x09090a2030383730ull,0x6166313031327830ull,0x3030307830203930ull,
0x7830203330303030ull,0x3932363063303036ull,0x6330303030783020ull,0x3009090a20303837ull,
0x3034306631303378ull,0x3031636578302064ull,0x3478302030383730ull,0x2064323430623030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3932343130313033ull,0x3030313463783020ull,
0x3064783020303837ull,0x3020643036303338ull,0x3837303034343078ull,0x36783009090a2030ull,
0x2064323630613030ull,0x3763323030307830ull,0x3030367830203038ull,0x7830203931343063ull,
0x3038373832303030ull,0x3032783009090a20ull,0x3020643036303030ull,0x3837383030343078ull,
0x3031303378302030ull,0x6378302039323631ull,0x2030383730303134ull,0x303032783009090aull,
0x7830203130633030ull,0x3038373030303430ull,0x3031303033783020ull,0x6365783020393136ull,
0x0a20303837303031ull,0x6130303678300909ull,0x3078302035313430ull,0x2030383738323030ull,
0x3438323030317830ull,0x3030327830206330ull,0x090a203030633830ull,0x3030303032783009ull,
0x3430783020393361ull,0x3020303837343230ull,0x3030303631303278ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3038303030317830ull,0x3030317830203431ull,0x7830206330343832ull,
0x3130633030303032ull,0x3833303430783020ull,0x3009090a20303837ull,0x3261303030306178ull,
0x3030303078302039ull,0x3278302030383763ull,0x2033303030363130ull,0x3730303030307830ull,
0x783009090a203038ull,0x6430343039303034ull,0x3030303030783020ull,0x3036783020303837ull,
0x3020643036303830ull,0x3837633030303078ull,0x33783009090a2030ull,0x2064303630303130ull,
0x3730303134637830ull,0x3030367830203038ull,0x7830203530343038ull,0x3038376330303030ull,
0x3032783009090a20ull,0x3020633032383730ull,0x3030383030303178ull,0x3030303278302034ull,
0x3078302031306330ull,0x2030383763303034ull,0x303033783009090aull,0x7830203930343038ull,
0x3038373030313063ull,0x3030303031783020ull,0x3430783020643034ull,0x0a20303837633330ull,
0x3631303278300909ull,0x3078302033303030ull,0x2030383730303030ull,0x3431323030647830ull,
0x3030307830203930ull,0x090a203038373430ull,0x3165303064783009ull,0x3061783020353030ull,
0x3020303837303034ull,0x3030393230303278ull,0x3030303078302035ull,0x09090a2033303030ull,
0x3230653030647830ull,0x3030617830203130ull,0x7830203038373030ull,0x3330303030303033ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3236303030306178ull,0x3131343078302035ull,
0x6178302030383734ull,0x2039323231303030ull,0x3734303034347830ull,0x783009090a203038ull,
0x6432303030303061ull,0x3431313430783020ull,0x3039783020303837ull,0x3020313334313030ull,
0x3837303030303078ull,0x61783009090a2030ull,0x2039323631303030ull,0x3734363034347830ull,
0x3330327830203038ull,0x7830203133383965ull,0x6666666666666630ull,0x3063783009090a20ull,
0x3020393234316330ull,0x6337633030303078ull,0x3030306178302030ull,0x3878302039323431ull,
0x2030383734363034ull,0x313034783009090aull,0x7830203533343235ull,0x3038373030303030ull,
0x3234313036783020ull,0x3030783020353336ull,0x0a20303837343330ull,0x3031303378300909ull,
0x6378302035336131ull,0x2030383730303134ull,0x3432343130367830ull,0x3030307830203533ull,
0x090a203038373433ull,0x3130343032783009ull,0x3430783020353336ull,0x3020303837343330ull,
0x3361313030306178ull,0x3630343478302035ull,0x09090a2030383734ull,0x6131633030637830ull,
0x3030307830203133ull,0x7830203063376330ull,0x3133383130303061ull,0x3436303438783020ull,
0x3009090a20303837ull,0x3234313030303278ull,0x3330343078302039ull,0x3478302030383730ull,
0x2031336132323130ull,0x3730303030307830ull,0x783009090a203038ull,0x3133383233313036ull,
0x3033303030783020ull,0x3033783020303837ull,0x3020313338313031ull,0x3837303031346378ull,
0x36783009090a2030ull,0x2031333832323130ull,0x3730333030307830ull,0x3030337830203038ull,
0x7830206432383130ull,0x3038376332303430ull,0x3033783009090a20ull,0x3020353232316230ull,
0x3837633030343678ull,0x3030306478302030ull,0x3078302031303630ull,0x2030383738303034ull,
0x313033783009090aull,0x7830203130303066ull,0x3038373030313465ull,0x3130303033783020ull,
0x3430783020393232ull,0x0a20303837383230ull,0x3030306178300909ull,0x3278302035323030ull,
0x2030383734313063ull,0x3231613030647830ull,0x3034307830203532ull,0x090a203038373830ull,
0x3063373033783009ull,0x6336783020646637ull,0x3020386337343130ull,0x3030303030303278ull,
0x3230343078302031ull,0x09090a2030383734ull,0x3030333030647830ull,0x3034307830203130ull,
0x7830203030356332ull,0x3330303030303033ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3030303030306678ull,0x3030306578302031ull,0x7d090a2031303030ull,0x2065646f630a7d0aull,
0x20656d616e090a7bull,0x614d36315a5f203dull,0x746f72626c65646eull,0x644930316d735f30ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f30535f32535f32ull,0x6d656d6c090a6969ull,
0x6d73090a30203d20ull,0x0a3637203d206d65ull,0x203d202067657209ull,0x20726162090a3931ull,
0x6f63090a30203d20ull,0x09090a7b2074736eull,0x656d616e67657309ull,0x74736e6f63203d20ull,
0x6e6765730909090aull,0x0a31203d20206d75ull,0x657366666f090909ull,0x090a30203d202074ull,
0x2073657479620909ull,0x09090a38203d2020ull,0x09090a7b206d656dull,0x3030303030783009ull,
0x3030783020666633ull,0x0a20313030303030ull,0x090a7d090a7d0909ull,0x2065646f636e6962ull,
0x3064783009090a7bull,0x3020353032303038ull,0x3837303034303078ull,0x3030303178302030ull,
0x3478302039303430ull,0x2030383734303030ull,0x303061783009090aull,0x7830206430323030ull,
0x3038373030303430ull,0x3030303031783020ull,0x3034783020353032ull,0x0a20303837343030ull,
0x3030306178300909ull,0x3078302039303030ull,0x2030383730303034ull,0x6534323030367830ull,
0x3230307830203132ull,0x090a203038376330ull,0x3431303036783009ull,0x3030783020353263ull,
0x3020303837383032ull,0x6666633830303378ull,0x3132633678302064ull,0x09090a2038633730ull,
0x6463393030337830ull,0x3263367830206466ull,0x7830203863323031ull,0x3330303030303033ull,
0x3030303030783020ull,0x3009090a20303031ull,0x3230313030306178ull,0x3134343478302039ull,
0x3178302030383730ull,0x2030316366303031ull,0x6566303031317830ull,0x783009090a203431ull,
0x3830386630303131ull,0x6630303131783020ull,0x3061783020633061ull,0x3020393132313030ull,
0x3837303134343478ull,0x31783009090a2030ull,0x2030303466303031ull,0x3666303031317830ull,
0x3030657830203430ull,0x7830203930343134ull,0x3038373830303034ull,0x3065783009090a20ull,
0x3020393138303630ull,0x3837303030303478ull,0x3331303478302030ull,0x3078302033303030ull,
0x2030303030303030ull,0x303131783009090aull,0x7830203834306630ull,0x3030343832303031ull,
0x3030303031783020ull,0x3430783020353036ull,0x0a20303837633330ull,0x3230303178300909ull,
0x3178302030316338ull,0x2034316538303030ull,0x3430323030657830ull,0x3030387830203932ull,
0x090a203038373030ull,0x3036303065783009ull,0x3038783020313363ull,0x3020303837303030ull,
0x3430383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,0x3038303030317830ull,
0x3034307830203534ull,0x7830203330303031ull,0x3933343130303065ull,0x3033303036783020ull,
0x3009090a20303837ull,0x6664313031306578ull,0x3130306578302064ull,0x3178302038633730ull,
0x2033303065313030ull,0x3130303030307830ull,0x783009090a203030ull,0x3934346166333032ull,
0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,
0x65783009090a2030ull,0x2039303430363030ull,0x3730303030387830ull,0x3030657830203038ull,
0x7830203931383130ull,0x3038373832303836ull,0x3065783009090a20ull,0x3020393034303030ull,
0x3837383030303678ull,0x3030306578302030ull,0x3678302039323830ull,0x2030383738313030ull,
0x303065783009090aull,0x7830203931303030ull,0x3038373830303036ull,0x3161303065783020ull,
0x3038783020313334ull,0x0a20303837303030ull,0x3630306578300909ull,0x3878302039306330ull,
0x2030383730303030ull,0x3038303030317830ull,0x3030307830203134ull,0x090a203330303030ull,
0x3830303031783009ull,0x3430783020353430ull,0x3020333030303130ull,0x3334303030306578ull,
0x3330303678302039ull,0x09090a2030383730ull,0x6431303130657830ull,0x3030657830206466ull,
0x7830203863373031ull,0x3330306332303031ull,0x3030303030783020ull,0x3009090a20303031ull,
0x3434616533303278ull,0x6666663078302039ull,0x3578302066666666ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3931633061303065ull,0x3030303038783020ull,
0x3065783020303837ull,0x3020393238313030ull,0x3837383030383678ull,0x65783009090a2030ull,
0x2039306330303030ull,0x3738313030367830ull,0x3030657830203038ull,0x7830203931383030ull,
0x3038373832303036ull,0x3065783009090a20ull,0x3020393030303030ull,0x3837383030303678ull,
0x3630306578302030ull,0x3878302031336330ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203932343032ull,0x3038373030303038ull,0x3830303031783020ull,0x3030783020313430ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302035343038ull,0x2033303030313034ull,
0x3431303030657830ull,0x3030367830203933ull,0x090a203038373033ull,0x3130313065783009ull,
0x3065783020646664ull,0x3020386337303130ull,0x3030613330303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3461643330327830ull,0x6666307830203934ull,0x7830206666666666ull,
0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303837ull,0x3034303630306578ull,
0x3030303878302039ull,0x6578302030383730ull,0x2039313831303030ull,0x3738323038367830ull,
0x783009090a203038ull,0x3930343030303065ull,0x3830303036783020ull,0x3065783020303837ull,
0x3020393138303030ull,0x3837383130303678ull,0x65783009090a2030ull,0x2039303030303030ull,
0x3738303030367830ull,0x3030657830203038ull,0x7830203133633036ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020393234303230ull,0x3837303030303878ull,0x3030303178302030ull,
0x3078302031343038ull,0x2033303030303030ull,0x303031783009090aull,0x7830203534303830ull,
0x3330303031303430ull,0x3130303065783020ull,0x3036783020393334ull,0x0a20303837303330ull,
0x3031306578300909ull,0x6578302064666431ull,0x2038633730313030ull,0x3038343030317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x6163333032783009ull,0x6630783020393434ull,
0x3020666666666666ull,0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3430363030657830ull,0x3030387830203930ull,0x7830203038373030ull,0x3931383130303065ull,
0x3832303836783020ull,0x3009090a20303837ull,0x3034303030306578ull,0x3030303678302039ull,
0x6578302030383738ull,0x2039313830303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3930303030303065ull,0x3830303036783020ull,0x3065783020303837ull,0x3020313363303630ull,
0x3837303030303878ull,0x65783009090a2030ull,0x2039323430323030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203134303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020353430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302039333431ull,
0x2030383730333030ull,0x313065783009090aull,0x7830206466643130ull,0x3863373031303065ull,
0x3635303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x6233303278300909ull,
0x3078302039343461ull,0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3036303065783009ull,0x3038783020393034ull,0x3020303837303030ull,
0x3138313030306578ull,0x3230383678302039ull,0x09090a2030383738ull,0x3430303030657830ull,
0x3030367830203930ull,0x7830203038373830ull,0x3931383030303065ull,0x3831303036783020ull,
0x3009090a20303837ull,0x3030303030306578ull,0x3030303678302039ull,0x6578302030383738ull,
0x2031336330363030ull,0x3730303030387830ull,0x783009090a203038ull,0x3932343032303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020313430383030ull,0x3030303030303078ull,
0x31783009090a2033ull,0x2035343038303030ull,0x3030313034307830ull,0x3030657830203330ull,
0x7830203933343130ull,0x3038373033303036ull,0x3065783009090a20ull,0x3020646664313031ull,
0x6337303130306578ull,0x3630303178302038ull,0x3078302033303034ull,0x2030303130303030ull,
0x333032783009090aull,0x7830203934346161ull,0x6666666666666630ull,0x3030303035783020ull,
0x3030783020333030ull,0x0a20303837303030ull,0x3630306578300909ull,0x3878302039303430ull,
0x2030383730303030ull,0x3831303030657830ull,0x3038367830203931ull,0x090a203038373832ull,
0x3030303065783009ull,0x3036783020393034ull,0x3020303837383030ull,0x3138303030306578ull,
0x3130303678302039ull,0x09090a2030383738ull,0x3030303030657830ull,0x3030367830203930ull,
0x7830203038373830ull,0x3133633036303065ull,0x3030303038783020ull,0x3009090a20303837ull,
0x3234303230306578ull,0x3030303878302039ull,0x3178302030383730ull,0x2031343038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x3534303830303031ull,0x3031303430783020ull,
0x3065783020333030ull,0x3020393334313030ull,0x3837303330303678ull,0x65783009090a2030ull,
0x2064666431303130ull,0x3730313030657830ull,0x3030317830203863ull,0x7830203330303237ull,
0x3030313030303030ull,0x3032783009090a20ull,0x3020393434613933ull,0x6666666666663078ull,
0x3030303578302066ull,0x3078302033303030ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203930343036ull,0x3038373030303038ull,0x3130303065783020ull,0x3836783020393138ull,
0x0a20303837383230ull,0x3030306578300909ull,0x3678302039303430ull,0x2030383738303030ull,
0x3830303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3036783020393030ull,0x3020303837383030ull,0x3363303630306578ull,0x3030303878302031ull,
0x09090a2030383730ull,0x3430323030657830ull,0x3030387830203932ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333431303030ull,0x3730333030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030303830ull,0x3031303030303078ull,0x32783009090a2030ull,0x2039343461383330ull,
0x6666666666307830ull,0x3030357830206666ull,0x7830203330303030ull,0x3038373030303030ull,
0x3065783009090a20ull,0x3020393034303630ull,0x3837303030303878ull,0x3030306578302030ull,
0x3678302039313831ull,0x2030383738323038ull,0x303065783009090aull,0x7830203930343030ull,
0x3038373830303036ull,0x3030303065783020ull,0x3036783020393138ull,0x0a20303837383130ull,
0x3030306578300909ull,0x3678302039303030ull,0x2030383738303030ull,0x6330363030657830ull,
0x3030387830203133ull,0x090a203038373030ull,0x3032303065783009ull,0x3038783020393234ull,
0x3020303837303030ull,0x3430383030303178ull,0x3030303078302031ull,0x09090a2033303030ull,
0x3038303030317830ull,0x3034307830203534ull,0x7830203330303031ull,0x3933343130303065ull,
0x3033303036783020ull,0x3009090a20303837ull,0x6664313031306578ull,0x3130306578302064ull,
0x3178302038633730ull,0x2033303065383030ull,0x3130303030307830ull,0x783009090a203030ull,
0x3934346137333032ull,0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,
0x3837303030303078ull,0x65783009090a2030ull,0x2039303430363030ull,0x3730303030387830ull,
0x3030657830203038ull,0x7830203931383130ull,0x3038373832303836ull,0x3065783009090a20ull,
0x3020393034303030ull,0x3837383030303678ull,0x3030306578302030ull,0x3678302039313830ull,
0x2030383738313030ull,0x303065783009090aull,0x7830203930303030ull,0x3038373830303036ull,
0x3036303065783020ull,0x3038783020313363ull,0x0a20303837303030ull,0x3230306578300909ull,
0x3878302039323430ull,0x2030383730303030ull,0x3038303030317830ull,0x3030307830203134ull,
0x090a203330303030ull,0x3830303031783009ull,0x3430783020353430ull,0x3020333030303130ull,
0x3334313030306578ull,0x3330303678302039ull,0x09090a2030383730ull,0x6431303130657830ull,
0x3030657830206466ull,0x7830203863373031ull,0x3330306339303031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3434613633303278ull,0x6666663078302039ull,0x3578302066666666ull,
0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,0x3930343036303065ull,
0x3030303038783020ull,0x3065783020303837ull,0x3020393138313030ull,0x3837383230383678ull,
0x65783009090a2030ull,0x2039303430303030ull,0x3738303030367830ull,0x3030657830203038ull,
0x7830203931383030ull,0x3038373831303036ull,0x3065783009090a20ull,0x3020393030303030ull,
0x3837383030303678ull,0x3630306578302030ull,0x3878302031336330ull,0x2030383730303030ull,
0x303065783009090aull,0x7830203932343032ull,0x3038373030303038ull,0x3830303031783020ull,
0x3030783020313430ull,0x0a20333030303030ull,0x3030303178300909ull,0x3078302035343038ull,
0x2033303030313034ull,0x3431303030657830ull,0x3030367830203933ull,0x090a203038373033ull,
0x3130313065783009ull,0x3065783020646664ull,0x3020386337303130ull,0x3030616130303178ull,
0x3030303078302033ull,0x09090a2030303130ull,0x3461353330327830ull,0x6666307830203934ull,
0x7830206666666666ull,0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3034303630306578ull,0x3030303878302039ull,0x6578302030383730ull,0x2039313831303030ull,
0x3738323038367830ull,0x783009090a203038ull,0x3930343030303065ull,0x3830303036783020ull,
0x3065783020303837ull,0x3020393138303030ull,0x3837383130303678ull,0x65783009090a2030ull,
0x2039303030303030ull,0x3738303030367830ull,0x3030657830203038ull,0x7830203133633036ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020393234303230ull,0x3837303030303878ull,
0x3030303178302030ull,0x3078302031343038ull,0x2033303030303030ull,0x303031783009090aull,
0x7830203534303830ull,0x3330303031303430ull,0x3130303065783020ull,0x3036783020393334ull,
0x0a20303837303330ull,0x3031306578300909ull,0x6578302064666431ull,0x2038633730313030ull,
0x3038623030317830ull,0x3030307830203330ull,0x090a203030313030ull,0x6134333032783009ull,
0x6630783020393434ull,0x3020666666666666ull,0x3030303030303578ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3430363030657830ull,0x3030387830203930ull,0x7830203038373030ull,
0x3931383130303065ull,0x3832303836783020ull,0x3009090a20303837ull,0x3034303030306578ull,
0x3030303678302039ull,0x6578302030383738ull,0x2039313830303030ull,0x3738313030367830ull,
0x783009090a203038ull,0x3930303030303065ull,0x3830303036783020ull,0x3065783020303837ull,
0x3020313363303630ull,0x3837303030303878ull,0x65783009090a2030ull,0x2039323430323030ull,
0x3730303030387830ull,0x3030317830203038ull,0x7830203134303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020353430383030ull,0x3030303130343078ull,0x3030306578302033ull,
0x3678302039333431ull,0x2030383730333030ull,0x313065783009090aull,0x7830206466643130ull,
0x3863373031303065ull,0x3663303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3333303278300909ull,0x3078302039343461ull,0x2066666666666666ull,0x3030303030357830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3036303065783009ull,0x3038783020393034ull,
0x3020303837303030ull,0x3138313030306578ull,0x3230383678302039ull,0x09090a2030383738ull,
0x3430303030657830ull,0x3030367830203930ull,0x7830203038373830ull,0x3931383030303065ull,
0x3831303036783020ull,0x3009090a20303837ull,0x3030303030306578ull,0x3030303678302039ull,
0x6578302030383738ull,0x2031336330363030ull,0x3730303030387830ull,0x783009090a203038ull,
0x3932343032303065ull,0x3030303038783020ull,0x3031783020303837ull,0x3020313430383030ull,
0x3030303030303078ull,0x31783009090a2033ull,0x2035343038303030ull,0x3030313034307830ull,
0x3030657830203330ull,0x7830203933343130ull,0x3038373033303036ull,0x3065783009090a20ull,
0x3020646664313031ull,0x6337303130306578ull,0x6430303178302038ull,0x3078302033303034ull,
0x2030303130303030ull,0x333032783009090aull,0x7830203934346132ull,0x6666666666666630ull,
0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,0x3630306578300909ull,
0x3878302039303430ull,0x2030383730303030ull,0x3831303030657830ull,0x3038367830203931ull,
0x090a203038373832ull,0x3030303065783009ull,0x3036783020393034ull,0x3020303837383030ull,
0x3138303030306578ull,0x3130303678302039ull,0x09090a2030383738ull,0x3030303030657830ull,
0x3030367830203930ull,0x7830203038373830ull,0x3133633036303065ull,0x3030303038783020ull,
0x3009090a20303837ull,0x3234303230306578ull,0x3030303878302039ull,0x3178302030383730ull,
0x2031343038303030ull,0x3030303030307830ull,0x783009090a203330ull,0x3534303830303031ull,
0x3031303430783020ull,0x3065783020333030ull,0x3020393334313030ull,0x3837303330303678ull,
0x65783009090a2030ull,0x2064666431303130ull,0x3730313030657830ull,0x3030317830203863ull,
0x7830203330303265ull,0x3030313030303030ull,0x3032783009090a20ull,0x3020393434613133ull,
0x6666666666663078ull,0x3030303578302066ull,0x3078302033303030ull,0x2030383730303030ull,
0x303065783009090aull,0x7830203930343036ull,0x3038373030303038ull,0x3130303065783020ull,
0x3836783020393138ull,0x0a20303837383230ull,0x3030306578300909ull,0x3678302039303430ull,
0x2030383738303030ull,0x3830303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3036783020393030ull,0x3020303837383030ull,0x3363303630306578ull,
0x3030303878302031ull,0x09090a2030383730ull,0x3430323030657830ull,0x3030387830203932ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333431303030ull,
0x3730333030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030306630ull,0x3031303030303078ull,0x32783009090a2030ull,
0x2039343461303330ull,0x6666666666307830ull,0x3030357830206666ull,0x7830203330303030ull,
0x3038373030303030ull,0x3065783009090a20ull,0x3020393034303630ull,0x3837303030303878ull,
0x3030306578302030ull,0x3678302039313831ull,0x2030383738323038ull,0x303065783009090aull,
0x7830203930343030ull,0x3038373830303036ull,0x3030303065783020ull,0x3036783020393138ull,
0x0a20303837383130ull,0x3030306578300909ull,0x3678302039303030ull,0x2030383738303030ull,
0x6330363030657830ull,0x3030387830203133ull,0x090a203038373030ull,0x3032303065783009ull,
0x3038783020393234ull,0x3020303837303030ull,0x3430383030303178ull,0x3030303078302031ull,
0x09090a2033303030ull,0x3038303030317830ull,0x3034307830203534ull,0x7830203330303031ull,
0x3933343130303065ull,0x3033303036783020ull,0x3009090a20303837ull,0x6664313031306578ull,
0x3130306578302064ull,0x3178302038633730ull,0x2033303065663030ull,0x3130303030307830ull,
0x783009090a203030ull,0x3934346166323032ull,0x6666666630783020ull,0x3035783020666666ull,
0x3020333030303030ull,0x3837303030303078ull,0x65783009090a2030ull,0x2039303430363030ull,
0x3730303030387830ull,0x3030657830203038ull,0x7830203931383130ull,0x3038373832303836ull,
0x3065783009090a20ull,0x3020393034303030ull,0x3837383030303678ull,0x3030306578302030ull,
0x3678302039313830ull,0x2030383738313030ull,0x303065783009090aull,0x7830203930303030ull,
0x3038373830303036ull,0x3036303065783020ull,0x3038783020313363ull,0x0a20303837303030ull,
0x3230306578300909ull,0x3878302039323430ull,0x2030383730303030ull,0x3038303030317830ull,
0x3030307830203134ull,0x090a203330303030ull,0x3830303031783009ull,0x3430783020353430ull,
0x3020333030303130ull,0x3334313030306578ull,0x3330303678302039ull,0x09090a2030383730ull,
0x6431303130657830ull,0x3030657830206466ull,0x7830203863373031ull,0x3330306330313031ull,
0x3030303030783020ull,0x3009090a20303031ull,0x3434616532303278ull,0x6666663078302039ull,
0x3578302066666666ull,0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3930343036303065ull,0x3030303038783020ull,0x3065783020303837ull,0x3020393138313030ull,
0x3837383230383678ull,0x65783009090a2030ull,0x2039303430303030ull,0x3738303030367830ull,
0x3030657830203038ull,0x7830203931383030ull,0x3038373831303036ull,0x3065783009090a20ull,
0x3020393030303030ull,0x3837383030303678ull,0x3630306578302030ull,0x3878302031336330ull,
0x2030383730303030ull,0x303065783009090aull,0x7830203932343032ull,0x3038373030303038ull,
0x3830303031783020ull,0x3030783020313430ull,0x0a20333030303030ull,0x3030303178300909ull,
0x3078302035343038ull,0x2033303030313034ull,0x3431303030657830ull,0x3030367830203933ull,
0x090a203038373033ull,0x3130313065783009ull,0x3065783020646664ull,0x3020386337303130ull,
0x3030613131303178ull,0x3030303078302033ull,0x09090a2030303130ull,0x3461643230327830ull,
0x6666307830203934ull,0x7830206666666666ull,0x3330303030303035ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3034303630306578ull,0x3030303878302039ull,0x6578302030383730ull,
0x2039303430303030ull,0x3738303030367830ull,0x783009090a203038ull,0x3934346163323032ull,
0x6666666630783020ull,0x3065783020666666ull,0x3020393138313030ull,0x3837383230383678ull,
0x65783009090a2030ull,0x2039303030303030ull,0x3738303030367830ull,0x3730337830203038ull,
0x7830206466353263ull,0x3863376330306336ull,0x3065783009090a20ull,0x3020393138303030ull,
0x3837383130303678ull,0x3230306578302030ull,0x3878302039323430ull,0x2030383730303030ull,
0x313031783009090aull,0x7830203330303932ull,0x3038323030303030ull,0x3036303065783020ull,
0x3038783020313363ull,0x0a20303837303030ull,0x3030303178300909ull,0x3078302031343038ull,
0x2033303030303030ull,0x3038303030317830ull,0x3034307830203534ull,0x090a203330303031ull,
0x3130303065783009ull,0x3036783020393338ull,0x3020303837383230ull,0x6664313031306578ull,
0x3130306578302064ull,0x09090a2038633730ull,0x3061323130317830ull,0x3030307830203330ull,
0x7830203030313030ull,0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3034303630306578ull,0x3030303878302039ull,0x6578302030383730ull,0x2039313831303030ull,
0x3738323038367830ull,0x783009090a203038ull,0x3930343030303065ull,0x3830303036783020ull,
0x3065783020303837ull,0x3020393138303030ull,0x3837383130303678ull,0x65783009090a2030ull,
0x2039303030303030ull,0x3738303030367830ull,0x3030317830203038ull,0x7830203330303531ull,
0x3038373030303030ull,0x3033783009090a20ull,0x3020353034326337ull,0x3837303130633678ull,
0x3034303278302030ull,0x3078302031303064ull,0x2030383738343234ull,0x303064783009090aull,
0x7830203130303031ull,0x3038373030303430ull,0x3063373033783020ull,0x6336783020646631ull,
0x0a20386337383030ull,0x3431306178300909ull,0x3078302033303061ull,0x2030303030303030ull,
0x3037343130317830ull,0x3030307830203330ull,0x090a203038323030ull,0x3830303064783009ull,
0x3032783020353030ull,0x3020303837303030ull,0x3034653030303278ull,0x3032343078302031ull,
0x09090a2030383730ull,0x3030303034617830ull,0x3230307830203930ull,0x7830203038373830ull,
0x3931323030303461ull,0x3830323030783020ull,0x3009090a20303837ull,0x3134303030346178ull,
0x3032303078302064ull,0x3478302030383738ull,0x2038303230323030ull,0x3230363030347830ull,
0x783009090a203031ull,0x3531323037303034ull,0x3030303030783020ull,0x3033783020303837ull,
0x3020393034303031ull,0x3837303031346378ull,0x33783009090a2030ull,0x2031313830303130ull,
0x3730303134637830ull,0x3130337830203038ull,0x7830203531613030ull,0x3038373030313463ull,
0x3036783009090a20ull,0x3020353030303230ull,0x3837383030303078ull,0x3630303678302030ull,
0x3078302039303030ull,0x2030383730313030ull,0x303036783009090aull,0x7830203130303037ull,
0x3038373431303030ull,0x3030303061783020ull,0x3430783020643032ull,0x0a20303837633030ull,
0x3030306178300909ull,0x3078302035313430ull,0x2030383763303034ull,0x3030303030617830ull,
0x3034307830203931ull,0x090a203038376330ull,0x6134313031783009ull,0x3030783020333030ull,
0x3020303837303030ull,0x3138663030303178ull,0x3330363078302039ull,0x09090a2030383763ull,
0x3866303030317830ull,0x3034307830206430ull,0x7830203038376333ull,0x3531386630303031ull,
0x6333303630783020ull,0x3009090a20303837ull,0x3063303030303178ull,0x3030343478302031ull,
0x3478302032383763ull,0x2035303030313130ull,0x3730303030307830ull,0x783009090a203038ull,
0x3530323030313036ull,0x3430303030783020ull,0x3033783020303837ull,0x3020353032303031ull,
0x3837303031346378ull,0x36783009090a2030ull,0x2031303030303130ull,0x3734303030307830ull,
0x3030327830203038ull,0x7830203130303030ull,0x3038373432303430ull,0x3033783009090a20ull,
0x3020313030303230ull,0x3837303031346378ull,0x6337303378302030ull,0x3678302064663365ull,
0x2038633734313263ull,0x303032783009090aull,0x7830206431386330ull,0x3038373030323430ull,
0x6135313031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3030306178300909ull,
0x3078302031303630ull,0x2030383763303030ull,0x3431383030337830ull,0x3130637830203930ull,
0x090a203038373030ull,0x3030303061783009ull,0x3030783020353063ull,0x3020303837633030ull,
0x3030303230306478ull,0x3030303078302031ull,0x09090a2030383734ull,0x6530653030647830ull,
0x6330617830203130ull,0x7830203038373030ull,0x3330303030303033ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3165306530306478ull,0x3063303878302031ull,0x3178302030383730ull,
0x2035303232303030ull,0x3763303034347830ull,0x783009090a203038ull,0x3934303130303061ull,
0x3830303030783020ull,0x3132783020303837ull,0x3020393032653030ull,0x3837343036343078ull,
0x34783009090a2030ull,0x2031323630323130ull,0x3730303030307830ull,0x3130337830203038ull,
0x7830203130343066ull,0x3038373030316365ull,0x3033783009090a20ull,0x3020393230313031ull,
0x3837303031346378ull,0x3138306478302030ull,0x3078302031323030ull,0x2030383730303434ull,
0x303033783009090aull,0x7830203130383038ull,0x3038373030313465ull,0x3032313036783020ull,
0x3030783020353234ull,0x0a20303837383230ull,0x3030303278300909ull,0x3078302031323031ull,
0x2030383738303034ull,0x3030303030617830ull,0x3030307830203132ull,0x090a203038373830ull,
0x3130303032783009ull,0x3430783020313032ull,0x3020303837633030ull,0x3230313130303378ull,
0x3031636578302031ull,0x09090a2030383730ull,0x3630383030347830ull,0x3030317830203432ull,
0x7830206330343830ull,0x3130303130303032ull,0x3030303430783020ull,0x3009090a20303837ull,
0x3332313031303378ull,0x3031346378302039ull,0x3278302030383730ull,0x2033303066373130ull,
0x3730303030307830ull,0x783009090a203038ull,0x3934323130303061ull,0x3830303030783020ull,
0x3036783020303837ull,0x3020643034303830ull,0x3837383330303078ull,0x31783009090a2030ull,
0x2030313038323030ull,0x3630323130347830ull,0x3030327830203832ull,0x7830203030363835ull,
0x6330343830303031ull,0x3033783009090a20ull,0x3020353134313031ull,0x3837303031346378ull,
0x3030303278302030ull,0x3078302031303031ull,0x2030383730303034ull,0x313036783009090aull,
0x7830203530343032ull,0x3038373431303030ull,0x6637313032783020ull,0x3030783020333030ull,
0x0a20303837303030ull,0x3630303278300909ull,0x3178302063303238ull,0x2034303038323030ull,
0x3830303030617830ull,0x3030307830206430ull,0x090a203038376330ull,0x3130303032783009ull,
0x3430783020313030ull,0x3020303837633030ull,0x3034303830303378ull,0x3031306378302039ull,
0x09090a2030383730ull,0x3430303030317830ull,0x3034307830206430ull,0x7830203038376333ull,
0x3330306637313032ull,0x3030303030783020ull,0x3009090a20303837ull,0x3036303230306478ull,
0x3030303078302039ull,0x6478302030383734ull,0x2035306530653030ull,0x3730303430617830ull,
0x783009090a203038ull,0x3530653832303032ull,0x3030303030783020ull,0x3064783020333030ull,
0x3020313032306530ull,0x3837303030306178ull,0x33783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030617830203038ull,0x7830203532363030ull,0x3038373431313430ull,
0x3061783009090a20ull,0x3020393232313030ull,0x3837343030343478ull,0x3030306178302030ull,
0x3078302064323030ull,0x2030383734313134ull,0x303039783009090aull,0x7830203133343130ull,
0x3038373030303030ull,0x3130303061783020ull,0x3434783020393236ull,0x0a20303837343630ull,
0x6533303278300909ull,0x3078302031333839ull,0x2066666666666666ull,0x3431633030637830ull,
0x3030307830203932ull,0x090a203063376330ull,0x3130303061783009ull,0x3438783020393234ull,
0x3020303837343630ull,0x3334323531303478ull,0x3030303078302035ull,0x09090a2030383730ull,
0x3632343130367830ull,0x3030307830203533ull,0x7830203038373433ull,0x3533613130313033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3334323431303678ull,0x3330303078302035ull,
0x3278302030383734ull,0x2035333631303430ull,0x3734333034307830ull,0x783009090a203038ull,
0x3533613130303061ull,0x3436303434783020ull,0x3063783020303837ull,0x3020313361316330ull,
0x6337633030303078ull,0x61783009090a2030ull,0x2031333831303030ull,0x3734363034387830ull,
0x3030327830203038ull,0x7830203932343130ull,0x3038373033303430ull,0x3034783009090a20ull,
0x3020313361323231ull,0x3837303030303078ull,0x3331303678302030ull,0x3078302031333832ull,
0x2030383730333030ull,0x313033783009090aull,0x7830203133383130ull,0x3038373030313463ull,
0x3232313036783020ull,0x3030783020313338ull,0x0a20303837303330ull,0x3030303378300909ull,
0x3078302064323831ull,0x2030383763323034ull,0x3231623030337830ull,0x3034367830203532ull,
0x090a203038376330ull,0x3030303064783009ull,0x3430783020313036ull,0x3020303837383030ull,
0x3030306631303378ull,0x3031346578302031ull,0x09090a2030383730ull,0x3231303030337830ull,
0x3034307830203932ull,0x7830203038373832ull,0x3532303030303061ull,0x3431306332783020ull,
0x3009090a20303837ull,0x3232316130306478ull,0x3030343078302035ull,0x3378302030383738ull,
0x2064663730633730ull,0x3734313063367830ull,0x783009090a203863ull,0x3130303030303032ull,
0x3432303430783020ull,0x3064783020303837ull,0x3020313030303330ull,0x3035633230343078ull,
0x33783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030667830203038ull,
0x7830203130303030ull,0x3130303030303065ull,0x630a7d0a7d090a20ull,0x6e090a7b2065646full,
0x5a5f203d20656d61ull,0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,
0x6669696934726168ull,0x69695f5366666666ull,0x3d206d656d6c090aull,0x6d656d73090a3020ull,
0x72090a3836203d20ull,0x3232203d20206765ull,0x3d2020726162090aull,0x736e6f63090a3020ull,
0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x6d756e6765730909ull,
0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,0x2020207365747962ull,
0x6d09090a3032203dull,0x0909090a7b206d65ull,0x3330303030307830ull,0x3036347830206666ull,
0x7830203030343030ull,0x3130303030303030ull,0x3030383034783020ull,0x0909090a20303030ull,
0x6666666666667830ull,0x0a7d09090a206666ull,0x636e6962090a7d09ull,0x09090a7b2065646full,
0x3230303830647830ull,0x3430307830203530ull,0x7830203038373030ull,0x3930343030303031ull,
0x3430303034783020ull,0x3009090a20303837ull,0x3032303030306178ull,0x3030343078302064ull,
0x3178302030383730ull,0x2035303230303030ull,0x3734303030347830ull,0x783009090a203038ull,
0x3930303030303061ull,0x3030303430783020ull,0x3036783020303837ull,0x3020393265343230ull,
0x3837633032303078ull,0x36783009090a2030ull,0x2064326334313030ull,0x3738303230307830ull,
0x3030337830203038ull,0x7830206466666361ull,0x3863373031326336ull,0x3033783009090a20ull,
0x3020646664636230ull,0x6332303132633678ull,0x3030303378302038ull,0x3078302033303030ull,
0x2030303130303030ull,0x303061783009090aull,0x7830203930343130ull,0x3038373431303434ull,
0x3130303031783020ull,0x3434783020313036ull,0x0a20303837633030ull,0x3230306578300909ull,
0x3078302031316164ull,0x2030383730303230ull,0x3631303030617830ull,0x3034347830203530ull,
0x090a203038373431ull,0x3130303031783009ull,0x3434783020313032ull,0x3020303837633030ull,
0x3161643230306578ull,0x3132343078302035ull,0x09090a2030383730ull,0x6164313030657830ull,
0x3230307830206430ull,0x7830203038373030ull,0x3931383030303062ull,0x3431303830783020ull,
0x3009090a20303837ull,0x3061643130306578ull,0x3032343078302031ull,0x6578302030383763ull,
0x2039316164323030ull,0x3738313238307830ull,0x783009090a203038ull,0x3431363735343162ull,
0x3030343062783020ull,0x3062783020383036ull,0x3020353161303030ull,0x3837383130303078ull,
0x65783009090a2030ull,0x2035306164313030ull,0x3738303238307830ull,0x3431627830203038ull,
0x7830203030323730ull,0x6331383735303162ull,0x3062783009090a20ull,0x3020343030303130ull,
0x3038303730306278ull,0x3030306278302030ull,0x3078302035313464ull,0x2030383734303230ull,
0x383065783009090aull,0x7830203930303031ull,0x3038373030343830ull,0x3034343062783020ull,
0x3062783020303230ull,0x0a20343036303530ull,0x3138306578300909ull,0x3078302031313030ull,
0x2030383738303438ull,0x3030303030637830ull,0x3430627830203831ull,0x090a203830653038ull,
0x3033343062783009ull,0x3062783020633032ull,0x3020633130303434ull,0x3238303430306578ull,
0x3130383078302035ull,0x09090a2030383738ull,0x3030323030637830ull,0x3430627830203032ull,
0x7830206330613033ull,0x3532653034303065ull,0x3432303030783020ull,0x3009090a20303837ull,
0x3330303230306578ull,0x3230303078302035ull,0x6578302030383730ull,0x2035313230313830ull,
0x3734303438307830ull,0x783009090a203038ull,0x3133323033303063ull,0x3030303030783020ull,
0x3065783020303837ull,0x3020353265303430ull,0x3837343230303078ull,0x65783009090a2030ull,
0x2031323030303030ull,0x3734333030307830ull,0x3830657830203038ull,0x7830203131323031ull,
0x3038373431343830ull,0x3065783009090a20ull,0x3020643332303330ull,0x3837303330303078ull,
0x3130306378302030ull,0x6278302038333230ull,0x2030343031363430ull,0x303062783009090aull,
0x7830203133323030ull,0x3038373031303830ull,0x3031303065783020ull,0x3030783020353132ull,
0x0a20303837633330ull,0x3430306578300909ull,0x3078302035343830ull,0x2030383738333038ull,
0x6131303530627830ull,0x3530627830203433ull,0x090a203034303130ull,0x3030303062783009ull,
0x3830783020393461ull,0x3020303837383330ull,0x3438313430306578ull,0x3430303078302035ull,
0x09090a2030383734ull,0x6330303530627830ull,0x3530627830203831ull,0x7830206334613032ull,
0x3134383134303065ull,0x3434303030783020ull,0x3009090a20303837ull,0x3365313235306278ull,
0x3335306278302063ull,0x6578302038336331ull,0x2031316530373030ull,0x3734323030307830ull,
0x783009090a203038ull,0x3931613130303062ull,0x3831303030783020ull,0x3065783020303837ull,
0x3020643138316330ull,0x3837303430303078ull,0x62783009090a2030ull,0x2034326531653030ull,
0x3830363030627830ull,0x3030627830203031ull,0x7830206431653030ull,0x3038373432303030ull,
0x3065783009090a20ull,0x3020393134303230ull,0x3837303130303078ull,0x3330306578302030ull,
0x3078302064313630ull,0x2030383763313030ull,0x303062783009090aull,0x7830206333303136ull,
0x3833613037303062ull,0x3165303062783020ull,0x3062783020303165ull,0x0a20343263393430ull,
0x3934306278300909ull,0x6278302030333830ull,0x2034316331353430ull,0x6531393430627830ull,
0x3430627830203432ull,0x090a203033633163ull,0x3035343062783009ull,0x3062783020303465ull,
0x3020343165313834ull,0x3132316330306278ull,0x3534306278302063ull,0x09090a2034336330ull,
0x3032373030627830ull,0x3030627830203431ull,0x7830203431613135ull,0x3032383035303062ull,
0x3134343062783020ull,0x3009090a20303130ull,0x3261303030306278ull,0x3130383078302035ull,
0x3378302030383730ull,0x2064663164323830ull,0x3738303663367830ull,0x783009090a203863ull,
0x3133306666333132ull,0x6666666630783020ull,0x3031783020666666ull,0x3020303132383230ull,
0x3130383030303178ull,0x31783009090a2038ull,0x2034313638323030ull,0x3438303030317830ull,
0x3030317830206331ull,0x7830203330303461ull,0x3038323030303030ull,0x3062783009090a20ull,
0x3020313230313030ull,0x3837343230303078ull,0x3338306278302030ull,0x3678302064663131ull,
0x2038633734303430ull,0x303034783009090aull,0x7830203330303461ull,0x3030303030303030ull,
0x3030303035783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3230306378300909ull,
0x3078302035343230ull,0x2030383730303030ull,0x3230313830657830ull,0x3438307830203132ull,
0x090a203038373430ull,0x3031383065783009ull,0x3830783020353230ull,0x3020303837303034ull,
0x3430303130306378ull,0x3030303078302039ull,0x09090a2030383730ull,0x3030333030657830ull,
0x3030307830203534ull,0x7830203038373434ull,0x3132323030343065ull,0x3030363430783020ull,
0x3009090a20333430ull,0x3230303034306578ull,0x3036343078302035ull,0x6578302033343030ull,
0x2064343030313030ull,0x3734343030307830ull,0x783009090a203038ull,0x3535303139303065ull,
0x3834303830783020ull,0x3062783020303837ull,0x3020313530303030ull,0x3837343230383078ull,
0x65783009090a2030ull,0x2031303030313030ull,0x3763343034307830ull,0x3030627830203038ull,
0x7830203530323030ull,0x3038373032303830ull,0x3065783009090a20ull,0x3020313230313431ull,
0x3837343530303078ull,0x3034306278302030ull,0x6278302034343232ull,0x2030303632303430ull,
0x303062783009090aull,0x7830203130343230ull,0x3038373030303830ull,0x3039303065783020ull,
0x3030783020313232ull,0x0a20303837303230ull,0x3431306578300909ull,0x3078302035303230ull,
0x2030383730323030ull,0x3232303030627830ull,0x3030627830203030ull,0x090a203030303031ull,
0x3032303065783009ull,0x3030783020393036ull,0x3020303837303030ull,0x3236323230306278ull,
0x3930306278302034ull,0x09090a2034303231ull,0x3239313030627830ull,0x3430627830203032ull,
0x7830203030633166ull,0x3434303931303062ull,0x3065343062783020ull,0x3009090a20383430ull,
0x3032313335306278ull,0x3834306278302063ull,0x6278302030323231ull,0x2034323231313530ull,
0x3030323530627830ull,0x783009090a203434ull,0x6333653132313062ull,0x3131353062783020ull,
0x3062783020383363ull,0x3020633034303334ull,0x3030313930306278ull,0x62783009090a2038ull,
0x2030326331663430ull,0x3430333030627830ull,0x3130627830203830ull,0x7830203032303130ull,
0x3432343033303062ull,0x3062783009090a20ull,0x3020303230316434ull,0x3332313130306278ull,
0x3830306278302038ull,0x6278302034343030ull,0x2038306331363030ull,0x303062783009090aull,
0x7830206330323234ull,0x6333633932303062ull,0x3031353062783020ull,0x3062783020343336ull,
0x0a20303465393230ull,0x6434306278300909ull,0x6278302038343630ull,0x2034303238653030ull,
0x6331303530627830ull,0x3430627830203034ull,0x090a206334323230ull,0x3066343062783009ull,
0x3062783020383363ull,0x3020633332323235ull,0x3338306434306278ull,0x3134306278302034ull,
0x09090a2030303231ull,0x6331303130627830ull,0x3530627830203430ull,0x7830203432303133ull,
0x3032653164303062ull,0x3031303062783020ull,0x3009090a20303030ull,0x3030313930306278ull,
0x3030306278302034ull,0x6278302034336530ull,0x2038336130313030ull,0x6131323030627830ull,
0x783009090a203030ull,0x3430363065303062ull,0x3830303062783020ull,0x3062783020383034ull,
0x3020643032303030ull,0x3837633030383078ull,0x65783009090a2030ull,0x2031323230313830ull,
0x3734303438307830ull,0x3830657830203038ull,0x7830203532303031ull,0x3038373030343830ull,
0x3062783009090a20ull,0x3020383061313234ull,0x3063313334306278ull,0x3034306578302063ull,
0x3078302031323230ull,0x2033343030303634ull,0x343065783009090aull,0x7830203532303030ull,
0x3334303030363430ull,0x3030303063783020ull,0x3063783020383330ull,0x0a20343432303130ull,
0x3834306278300909ull,0x6278302030343230ull,0x2034333030393430ull,0x3231393030657830ull,
0x3038307830206433ull,0x090a203038373833ull,0x3033303063783009ull,0x3030783020393432ull,
0x3020303837303030ull,0x3430313830306578ull,0x3430383078302064ull,0x09090a2030383734ull,
0x3430303030637830ull,0x3030307830203933ull,0x7830203038373030ull,0x3534613139303065ull,
0x6333303030783020ull,0x3009090a20303837ull,0x3332303330306578ull,0x3430303078302064ull,
0x6578302030383738ull,0x2039343032383030ull,0x3763343030307830ull,0x783009090a203038ull,
0x3933343030303065ull,0x3833303030783020ull,0x3065783020303837ull,0x3020353461313930ull,
0x3837343430303078ull,0x65783009090a2030ull,0x2035323230313030ull,0x3763333030307830ull,
0x3030657830203038ull,0x7830206434303238ull,0x3038373834303030ull,0x3065783009090a20ull,
0x3020313230303030ull,0x3837383330303078ull,0x6430306578302030ull,0x3078302035336131ull,
0x2030383734343030ull,0x303065783009090aull,0x7830203934323031ull,0x3038373432303430ull,
0x3230313065783020ull,0x3030783020313430ull,0x0a20303837633430ull,0x3030306578300909ull,
0x3078302035343030ull,0x2030383730323034ull,0x6531323530627830ull,0x3530627830206333ull,
0x090a206334323132ull,0x3131353062783009ull,0x3062783020383463ull,0x3020383330313135ull,
0x3432303130306578ull,0x3430383078302035ull,0x09090a2030383763ull,0x3030303030657830ull,
0x3038307830203933ull,0x7830203038373833ull,0x6333323266303062ull,0x3132313062783020ull,
0x3009090a20383363ull,0x3365313031306278ull,0x6430306278302063ull,0x6578302034336331ull,
0x2031343630333030ull,0x3763333030307830ull,0x783009090a203038ull,0x3533343032303065ull,
0x3433303030783020ull,0x3062783020303837ull,0x3020383332313031ull,0x3330316430306278ull,
0x62783009090a2063ull,0x2034346531653030ull,0x6331393430627830ull,0x3130627830203432ull,
0x7830203834633931ull,0x3034303239343062ull,0x3062783009090a20ull,0x3020633432323235ull,
0x3265313235306278ull,0x3335306278302034ull,0x6278302038346331ull,0x2030326531383430ull,
0x313062783009090aull,0x7830203432323132ull,0x3433613138343062ull,0x3230303062783020ull,
0x3030783020313230ull,0x0a20303837343230ull,0x3030313278300909ull,0x3078302031333831ull,
0x2030633730313434ull,0x6131303030627830ull,0x3030307830203132ull,0x090a203038373032ull,
0x3030303035783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3232323830306278ull,
0x3135306278302034ull,0x09090a2034343231ull,0x3031313530627830ull,0x3030627830203032ull,
0x7830203032323138ull,0x6466313133383062ull,0x3430343036783020ull,0x3009090a20386337ull,
0x3030633430303178ull,0x3030303078302033ull,0x3578302030383230ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3530383163373033ull,0x3031306336783020ull,
0x3032783020303837ull,0x3020313030643034ull,0x3837303332343078ull,0x64783009090a2030ull,
0x2031303030313030ull,0x3730303034307830ull,0x3730337830203038ull,0x7830206466313063ull,
0x3863373830306336ull,0x3061783009090a20ull,0x3020333030656230ull,0x3030303030303078ull,
0x6230303178302030ull,0x3078302033303062ull,0x2030383230303030ull,0x303064783009090aull,
0x7830203530303730ull,0x3038373030303032ull,0x6530303032783020ull,0x3430783020313030ull,
0x0a20303837303032ull,0x3030346178300909ull,0x3078302039303030ull,0x2030383738303230ull,
0x3230303034617830ull,0x3230307830203931ull,0x090a203038373830ull,0x3030303461783009ull,
0x3030783020643134ull,0x3020303837383032ull,0x3032303230303478ull,0x3630303478302038ull,
0x09090a2030313230ull,0x3230373030347830ull,0x3030307830203531ull,0x7830203038373030ull,
0x3930343030313033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3138303031303378ull,
0x3031346378302031ull,0x3378302030383730ull,0x2035316130303130ull,0x3730303134637830ull,
0x783009090a203038ull,0x3530303032303036ull,0x3830303030783020ull,0x3036783020303837ull,
0x3020393030303630ull,0x3837303130303078ull,0x36783009090a2030ull,0x2031303030373030ull,
0x3734313030307830ull,0x3030617830203038ull,0x7830206430323030ull,0x3038376330303430ull,
0x3061783009090a20ull,0x3020353134303030ull,0x3837633030343078ull,0x3030306178302030ull,
0x3078302039313030ull,0x2030383763303034ull,0x303031783009090aull,0x7830203330306562ull,
0x3038373030303030ull,0x6630303031783020ull,0x3630783020393138ull,0x0a20303837633330ull,
0x3030303178300909ull,0x3078302064303866ull,0x2030383763333034ull,0x3866303030317830ull,
0x3036307830203531ull,0x090a203038376333ull,0x3030303031783009ull,0x3434783020313063ull,
0x3020323837633030ull,0x3030303531303478ull,0x3030303078302035ull,0x09090a2030383730ull,
0x3230343130367830ull,0x3030307830203530ull,0x7830203038373430ull,0x3530323030313033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3030303431303678ull,0x3030303078302031ull,
0x3278302030383734ull,0x2031303030303030ull,0x3763323034307830ull,0x783009090a203038ull,
0x3130303032303033ull,0x3030313463783020ull,0x3033783020303837ull,0x3020646666646337ull,
0x6337343132633678ull,0x32783009090a2038ull,0x2064313863303030ull,0x3730303234307830ull,
0x3030317830203038ull,0x7830203330306563ull,0x3038323030303030ull,0x3061783009090a20ull,
0x3020313036303030ull,0x3837633030303078ull,0x3830303378302030ull,0x6378302039303431ull,
0x2030383730303130ull,0x303061783009090aull,0x7830203530633030ull,0x3038376330303030ull,
0x3032303064783020ull,0x3030783020313030ull,0x0a20303837343030ull,0x6530306478300909ull,
0x6178302031306530ull,0x2030383730306330ull,0x3030303030337830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3065303064783009ull,0x3038783020313165ull,0x3020303837303063ull,
0x3065313030303178ull,0x3030343478302035ull,0x09090a2030383763ull,0x3031303030617830ull,
0x3030307830203134ull,0x7830203038373830ull,0x3930656631303132ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3236303031303478ull,0x3030303078302035ull,0x3378302030383730ull,
0x2031303430663130ull,0x3730303163657830ull,0x783009090a203038ull,0x3932323130313033ull,
0x3030313463783020ull,0x3064783020303837ull,0x3020313030303238ull,0x3837303034343078ull,
0x33783009090a2030ull,0x2035323830383030ull,0x3730303134657830ull,0x3130367830203038ull,
0x7830203132343030ull,0x3038373832303030ull,0x3032783009090a20ull,0x3020313030303030ull,
0x3837383030343078ull,0x3030306178302030ull,0x3078302031323432ull,0x2030383738303030ull,
0x303032783009090aull,0x7830203532303130ull,0x3038376330303430ull,0x3031303033783020ull,
0x6365783020313230ull,0x0a20303837303031ull,0x3830303478300909ull,0x3178302038323630ull,
0x2063303438303030ull,0x3031303030327830ull,0x3034307830203130ull,0x090a203038373432ull,
0x3130313033783009ull,0x3463783020393334ull,0x3020303837303031ull,0x3030336630303278ull,
0x3030303078302033ull,0x09090a2030383730ull,0x3231303030617830ull,0x3030307830203934ull,
0x7830203038373830ull,0x6430343038303036ull,0x3833303030783020ull,0x3009090a20303837ull,
0x3130383230303178ull,0x3231303478302030ull,0x3278302038323630ull,0x2030303638353030ull,
0x3438303030317830ull,0x783009090a206330ull,0x3531343130313033ull,0x3030313463783020ull,
0x3032783020303837ull,0x3020313030313030ull,0x3837303030343078ull,0x36783009090a2030ull,
0x2035303430323130ull,0x3734313030307830ull,0x3030327830203038ull,0x7830203330303366ull,
0x3038373030303030ull,0x3032783009090a20ull,0x3020633032383630ull,0x3030383230303178ull,
0x3030306178302034ull,0x3078302064303830ull,0x2030383763303030ull,0x303032783009090aull,
0x7830203130303130ull,0x3038376330303430ull,0x3038303033783020ull,0x3063783020393034ull,
0x0a20303837303031ull,0x3030303178300909ull,0x3078302064303430ull,0x2030383763333034ull,
0x3033663030327830ull,0x3030307830203330ull,0x090a203038373030ull,0x3032303064783009ull,
0x3030783020393036ull,0x3020303837343030ull,0x3065306530306478ull,0x3034306178302035ull,
0x09090a2030383730ull,0x6538323030327830ull,0x3030307830203530ull,0x7830203330303030ull,
0x3130323065303064ull,0x3030303061783020ull,0x3009090a20303837ull,0x3030303030303378ull,
0x3030303078302033ull,0x6178302030383730ull,0x2035323630303030ull,0x3734313134307830ull,
0x783009090a203038ull,0x3932323130303061ull,0x3430303434783020ull,0x3061783020303837ull,
0x3020643230303030ull,0x3837343131343078ull,0x39783009090a2030ull,0x2031333431303030ull,
0x3730303030307830ull,0x3030617830203038ull,0x7830203932363130ull,0x3038373436303434ull,
0x3032783009090a20ull,0x3020313338396533ull,0x6666666666663078ull,0x6330306378302066ull,
0x3078302039323431ull,0x2030633763303030ull,0x303061783009090aull,0x7830203932343130ull,
0x3038373436303438ull,0x3235313034783020ull,0x3030783020353334ull,0x0a20303837303030ull,
0x3431303678300909ull,0x3078302035333632ull,0x2030383734333030ull,0x6131303130337830ull,
0x3134637830203533ull,0x090a203038373030ull,0x3234313036783009ull,0x3030783020353334ull,
0x3020303837343330ull,0x3336313034303278ull,0x3330343078302035ull,0x09090a2030383734ull,
0x6131303030617830ull,0x3034347830203533ull,0x7830203038373436ull,0x3133613163303063ull,
0x6330303030783020ull,0x3009090a20306337ull,0x3338313030306178ull,0x3630343878302031ull,
0x3278302030383734ull,0x2039323431303030ull,0x3730333034307830ull,0x783009090a203038ull,
0x3133613232313034ull,0x3030303030783020ull,0x3036783020303837ull,0x3020313338323331ull,
0x3837303330303078ull,0x33783009090a2030ull,0x2031333831303130ull,0x3730303134637830ull,
0x3130367830203038ull,0x7830203133383232ull,0x3038373033303030ull,0x3033783009090a20ull,
0x3020643238313030ull,0x3837633230343078ull,0x6230303378302030ull,0x3678302035323231ull,
0x2030383763303034ull,0x303064783009090aull,0x7830203130363030ull,0x3038373830303430ull,
0x3066313033783020ull,0x3465783020313030ull,0x0a20303837303031ull,0x3030303378300909ull,
0x3078302039323231ull,0x2030383738323034ull,0x3030303030617830ull,0x3063327830203532ull,
0x090a203038373431ull,0x3161303064783009ull,0x3430783020353232ull,0x3020303837383030ull,
0x6637306337303378ull,0x3130633678302064ull,0x09090a2038633734ull,0x3030303030327830ull,
0x3034307830203130ull,0x7830203038373432ull,0x3130303033303064ull,0x6332303430783020ull,
0x3009090a20303035ull,0x3030303030303378ull,0x3030303078302033ull,0x6678302030383730ull,
0x2031303030303030ull,0x3030303030657830ull,0x7d0a7d090a203130ull,0x0a7b2065646f630aull,
0x203d20656d616e09ull,0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645644930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x69695f30535f3253ull,0x3d206d656d6c090aull,
0x6d656d73090a3020ull,0x72090a3637203d20ull,0x3132203d20206765ull,0x3d2020726162090aull,
0x736e6f63090a3020ull,0x730909090a7b2074ull,0x3d20656d616e6765ull,0x090a74736e6f6320ull,
0x6d756e6765730909ull,0x09090a31203d2020ull,0x2074657366666f09ull,0x0909090a30203d20ull,
0x2020207365747962ull,0x6d09090a3231203dull,0x0909090a7b206d65ull,0x3330303030307830ull,
0x3030307830206666ull,0x7830206130303030ull,0x3130303030303030ull,0x7d090a7d09090a20ull,
0x646f636e6962090aull,0x783009090a7b2065ull,0x3530323030383064ull,0x3030343030783020ull,
0x3031783020303837ull,0x3020393034303030ull,0x3837343030303478ull,0x61783009090a2030ull,
0x2064303230303030ull,0x3730303034307830ull,0x3030317830203038ull,0x7830203530323030ull,
0x3038373430303034ull,0x3061783009090a20ull,0x3020393030303030ull,0x3837303030343078ull,
0x3230303678302030ull,0x3078302035306534ull,0x2030383763303230ull,0x303036783009090aull,
0x7830203931633431ull,0x3038373830323030ull,0x6331303033783020ull,0x6336783020646666ull,
0x0a20386337303132ull,0x3630303378300909ull,0x3678302064666463ull,0x2038633230313263ull,
0x3030303030337830ull,0x3030307830203330ull,0x090a203030313030ull,0x3030303031783009ull,
0x3434783020313063ull,0x3020303837633030ull,0x3030303330303478ull,0x3030303078302039ull,
0x09090a2030383730ull,0x3230323030367830ull,0x3030307830203930ull,0x7830203038373830ull,
0x3930343030313033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3030303230303678ull,
0x3030303078302031ull,0x3278302030383738ull,0x2031303030303030ull,0x3738313034307830ull,
0x783009090a203038ull,0x3930303032303033ull,0x3030313463783020ull,0x3032783020303837ull,
0x3020643238633030ull,0x3837383032343078ull,0x64783009090a2030ull,0x2039303631653030ull,
0x3730306330387830ull,0x3030337830203038ull,0x7830206430343038ull,0x3038373030313465ull,
0x3033783009090a20ull,0x3020646664306337ull,0x6337633030633678ull,0x3230306178302038ull,
0x3078302033303064ull,0x2030303030303030ull,0x303061783009090aull,0x7830203932383030ull,
0x3038373830303430ull,0x3030303061783020ull,0x3430783020353261ull,0x0a20303837383030ull,
0x3030306178300909ull,0x3078302031326330ull,0x2030383738303034ull,0x3063323030317830ull,
0x3030307830203330ull,0x090a203038323030ull,0x3963333032783009ull,0x6630783020393036ull,
0x3020666666666666ull,0x3034306530306478ull,0x3063303878302039ull,0x09090a2030383730ull,
0x3430383030337830ull,0x3134657830206430ull,0x7830203038373030ull,0x3131383030303061ull,
0x3830303430783020ull,0x3009090a20303837ull,0x3063303030306178ull,0x3030343078302064ull,
0x3278302030383738ull,0x2030313838613430ull,0x3638383430327830ull,0x783009090a203431ull,
0x3930613030303061ull,0x3830303430783020ull,0x3061783020303837ull,0x3020643038303030ull,
0x3837343131343078ull,0x61783009090a2030ull,0x2031316130303030ull,0x3734313134307830ull,
0x3430327830203038ull,0x7830203930343030ull,0x3038373432303430ull,0x3033783009090a20ull,
0x3020643036303138ull,0x3837303134633678ull,0x3138303378302030ull,0x3678302031313830ull,
0x2030383730313463ull,0x303061783009090aull,0x7830203930343030ull,0x3038373431313430ull,
0x3034303064783020ull,0x3430783020643036ull,0x0a20303837343030ull,0x3138303378300909ull,
0x3678302039303430ull,0x2030383730313463ull,0x3430333030647830ull,0x3034307830203930ull,
0x090a203038373430ull,0x3030303061783009ull,0x6332783020643034ull,0x3020303837343130ull,
0x3030643230303178ull,0x3030303078302033ull,0x09090a2030383730ull,0x3866303030317830ull,
0x3036307830206430ull,0x7830203038376333ull,0x3130303030303066ull,0x3030303065783020ull,
0x3009090a20323030ull,0x3030343430306178ull,0x3030303078302033ull,0x3278302030303030ull,
0x2039306338313030ull,0x3030303030307830ull,0x783009090a203330ull,0x6466646332303033ull,
0x6330326336783020ull,0x3031783020386337ull,0x3020333030343430ull,0x3832303030303078ull,
0x32783009090a2030ull,0x2039303639343030ull,0x3030303030307830ull,0x3030647830203330ull,
0x7830203930343065ull,0x3038373030633038ull,0x3033783009090a20ull,0x3020313134303830ull,
0x3837303031346578ull,0x3030306178302030ull,0x3078302035313830ull,0x2030383738303034ull,
0x303061783009090aull,0x7830203131303130ull,0x3038373830303430ull,0x3861343032783020ull,
0x3032783020343161ull,0x0a20633138383834ull,0x3030306178300909ull,0x3078302039306130ull,
0x2030383738303034ull,0x6130303030617830ull,0x3134307830203131ull,0x090a203038373431ull,
0x3030303061783009ull,0x3430783020353165ull,0x3020303837343131ull,0x3034303034303278ull,
0x3230343078302039ull,0x09090a2030383734ull,0x3830313830337830ull,0x3463367830203131ull,
0x7830203038373031ull,0x3531613031383033ull,0x3031346336783020ull,0x3009090a20303837ull,
0x3034303030306178ull,0x3131343078302039ull,0x6478302030383734ull,0x2031313830353030ull,
0x3734303034307830ull,0x783009090a203038ull,0x3930343031383033ull,0x3031346336783020ull,
0x3064783020303837ull,0x3020393034303430ull,0x3837343030343078ull,0x61783009090a2030ull,
0x2039303430303030ull,0x3734313063327830ull,0x3030327830203038ull,0x7830206430363030ull,
0x3038373830303430ull,0x3033783009090a20ull,0x3020646633306337ull,0x6337633030633678ull,
0x3530306178302061ull,0x3078302033303062ull,0x2030303030303030ull,0x303031783009090aull,
0x7830203330306235ull,0x3038323030303030ull,0x6330303033783020ull,0x3430783020393063ull,
0x0a20303837303032ull,0x3230303378300909ull,0x6378302039303430ull,0x2030383730303134ull,
0x3863303030327830ull,0x3234307830203930ull,0x090a203038373830ull,0x3065303064783009ull,
0x3038783020393034ull,0x3020303837303063ull,0x3134303830303378ull,0x3031346578302035ull,
0x09090a2030383730ull,0x3830303030617830ull,0x3034307830203131ull,0x7830203038373830ull,
0x3531343130303061ull,0x3830303430783020ull,0x3009090a20303837ull,0x3138386134303278ull,
0x3834303278302030ull,0x6178302034316138ull,0x2039306130303030ull,0x3738303034307830ull,
0x783009090a203038ull,0x3131383030303061ull,0x3431313430783020ull,0x3061783020303837ull,
0x3020353161303030ull,0x3837343131343078ull,0x32783009090a2030ull,0x2039303430303430ull,
0x3734323034307830ull,0x3830337830203038ull,0x7830203131383031ull,0x3038373031346336ull,
0x3033783009090a20ull,0x3020353161303138ull,0x3837303134633678ull,0x3030306178302030ull,
0x3078302039303430ull,0x2030383734313134ull,0x303064783009090aull,0x7830203131383035ull,
0x3038373430303430ull,0x3031383033783020ull,0x6336783020393034ull,0x0a20303837303134ull,
0x3430306478300909ull,0x3078302039303430ull,0x2030383734303034ull,0x3430303030617830ull,
0x3063327830203930ull,0x090a203038373431ull,0x3030303032783009ull,0x3430783020643036ull,
0x3020303837383030ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x3034373030617830ull,0x3030307830203330ull,0x7830203030303030ull,0x3930323831303032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x6666633230303378ull,0x3032633678302064ull,
0x3178302038633763ull,0x2033303034373030ull,0x3230303030307830ull,0x783009090a203038ull,
0x3130636330303032ull,0x3030323430783020ull,0x3033783020303837ull,0x3020313030303230ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2031303863303030ull,0x3730303234307830ull,
0x3030647830203038ull,0x7830203130303065ull,0x3038373030633038ull,0x3033783009090a20ull,
0x3020313130303830ull,0x3837303031346578ull,0x3030306178302030ull,0x3078302039303030ull,
0x2030383738303034ull,0x303061783009090aull,0x7830203131303130ull,0x3038373830303430ull,
0x3861343032783020ull,0x3032783020383034ull,0x0a20303138383834ull,0x3030306178300909ull,
0x3078302031303230ull,0x2030383738303034ull,0x3430303030617830ull,0x3134307830203930ull,
0x090a203038373431ull,0x3030303061783009ull,0x3430783020313138ull,0x3020303837343131ull,
0x3030303034303278ull,0x3230343078302031ull,0x09090a2030383734ull,0x3430313830337830ull,
0x3463367830203930ull,0x7830203038373031ull,0x3131383031383033ull,0x3031346336783020ull,
0x3009090a20303837ull,0x3030303030306178ull,0x3131343078302031ull,0x6478302030383734ull,
0x2039303430343030ull,0x3734303034307830ull,0x783009090a203038ull,0x3130303031383033ull,
0x3031346336783020ull,0x3064783020303837ull,0x3020313030303230ull,0x3837343030343078ull,
0x61783009090a2030ull,0x2031303030303030ull,0x3734313063327830ull,0x3030327830203038ull,
0x7830206430363030ull,0x3038373030303430ull,0x3033783009090a20ull,0x3020646637306337ull,
0x6337383030633678ull,0x3030303378302061ull,0x3078302033303030ull,0x2030383230303030ull,
0x303061783009090aull,0x7830203133323030ull,0x3038373031343434ull,0x6630303131783020ull,
0x3131783020303163ull,0x0a20343165663030ull,0x3030313178300909ull,0x3178302038303866ull,
0x2063306166303031ull,0x6330303030617830ull,0x3434347830203931ull,0x090a203038373031ull,
0x6630303131783009ull,0x3131783020303034ull,0x3020343036663030ull,0x3038313430306578ull,
0x3030303478302039ull,0x09090a2030383738ull,0x3830363030657830ull,0x3030347830203931ull,
0x7830203038373030ull,0x3330306339313034ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3530663030313178ull,0x3030303178302030ull,0x3178302030303438ull,0x2035303630303030ull,
0x3763333036307830ull,0x783009090a203038ull,0x3031633830303031ull,0x3832303031783020ull,
0x3065783020343165ull,0x3020313334303230ull,0x3837303030303878ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031343831ull,0x2030383738333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6138303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x6633303278300909ull,0x3078302031353861ull,0x2066666666666666ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3036303065783009ull,
0x3038783020393034ull,0x3020303837303030ull,0x3163313030306578ull,0x3330383678302039ull,
0x09090a2030383730ull,0x3430303030657830ull,0x3030367830203930ull,0x7830203038373830ull,
0x3931383030303065ull,0x3831303036783020ull,0x3009090a20303837ull,0x3030303030306578ull,
0x3030303678302039ull,0x6578302030383738ull,0x2039336330363030ull,0x3730303030387830ull,
0x783009090a203038ull,0x3133343032303065ull,0x3030303038783020ull,0x3031783020303837ull,
0x3020393430383030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2064343038303030ull,
0x3030313034307830ull,0x3030657830203330ull,0x7830203134383130ull,0x3038373833303036ull,
0x3065783009090a20ull,0x3020646631323231ull,0x6337303130306578ull,0x3930303178302038ull,
0x3078302033303038ull,0x2030303130303030ull,0x333032783009090aull,0x7830203135386165ull,
0x6666666666666630ull,0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3630306578300909ull,0x3878302039303430ull,0x2030383730303030ull,0x6331303030657830ull,
0x3038367830203931ull,0x090a203038373033ull,0x3030303065783009ull,0x3036783020393034ull,
0x3020303837383030ull,0x3138303030306578ull,0x3130303678302039ull,0x09090a2030383738ull,
0x3030303030657830ull,0x3030367830203930ull,0x7830203038373830ull,0x3933633036303065ull,
0x3030303038783020ull,0x3009090a20303837ull,0x3334303230306578ull,0x3030303878302031ull,
0x3178302030383730ull,0x2039343038303030ull,0x3030303030307830ull,0x783009090a203330ull,
0x6434303830303031ull,0x3031303430783020ull,0x3065783020333030ull,0x3020313438313030ull,
0x3837383330303678ull,0x65783009090a2030ull,0x2064663132323130ull,0x3730313030657830ull,
0x3030317830203863ull,0x7830203330303661ull,0x3030313030303030ull,0x3032783009090a20ull,
0x3020313538616433ull,0x6666666666663078ull,0x3030303578302066ull,0x3078302033303030ull,
0x2030383730303030ull,0x303065783009090aull,0x7830203930343036ull,0x3038373030303038ull,
0x3130303065783020ull,0x3836783020393163ull,0x0a20303837303330ull,0x3030306578300909ull,
0x3678302039303430ull,0x2030383738303030ull,0x3830303030657830ull,0x3030367830203931ull,
0x090a203038373831ull,0x3030303065783009ull,0x3036783020393030ull,0x3020303837383030ull,
0x3363303630306578ull,0x3030303878302039ull,0x09090a2030383730ull,0x3430323030657830ull,
0x3030387830203133ull,0x7830203038373030ull,0x3934303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302064ull,0x6578302033303030ull,
0x2031343831303030ull,0x3738333030367830ull,0x783009090a203038ull,0x6466313232313065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020333030346230ull,0x3031303030303078ull,
0x32783009090a2030ull,0x2031353861633330ull,0x6666666666307830ull,0x3030357830206666ull,
0x7830203330303030ull,0x3038373030303030ull,0x3065783009090a20ull,0x3020393034303630ull,
0x3837303030303878ull,0x3030306578302030ull,0x3678302039316331ull,0x2030383730333038ull,
0x303065783009090aull,0x7830203930343030ull,0x3038373830303036ull,0x3030303065783020ull,
0x3036783020393138ull,0x0a20303837383130ull,0x3030306578300909ull,0x3678302039303030ull,
0x2030383738303030ull,0x6330363030657830ull,0x3030387830203933ull,0x090a203038373030ull,
0x3032303065783009ull,0x3038783020313334ull,0x3020303837303030ull,0x3430383030303178ull,
0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,0x3034307830206434ull,
0x7830203330303031ull,0x3134383130303065ull,0x3833303036783020ull,0x3009090a20303837ull,
0x6631323231306578ull,0x3130306578302064ull,0x3178302038633730ull,0x2033303032633030ull,
0x3130303030307830ull,0x783009090a203030ull,0x3135386162333032ull,0x6666666630783020ull,
0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,0x65783009090a2030ull,
0x2039303430363030ull,0x3730303030387830ull,0x3030657830203038ull,0x7830203931633130ull,
0x3038373033303836ull,0x3065783009090a20ull,0x3020393034303030ull,0x3837383030303678ull,
0x3030306578302030ull,0x3678302039313830ull,0x2030383738313030ull,0x303065783009090aull,
0x7830203930303030ull,0x3038373830303036ull,0x3036303065783020ull,0x3038783020393363ull,
0x0a20303837303030ull,0x3230306578300909ull,0x3878302031333430ull,0x2030383730303030ull,
0x3038303030317830ull,0x3030307830203934ull,0x090a203330303030ull,0x3830303031783009ull,
0x3430783020643430ull,0x3020333030303130ull,0x3438313030306578ull,0x3330303678302031ull,
0x09090a2030383738ull,0x3132323130657830ull,0x3030657830206466ull,0x7830203863373031ull,
0x3330303064303031ull,0x3030303030783020ull,0x3009090a20303031ull,0x3538616133303278ull,
0x6666663078302031ull,0x3578302066666666ull,0x2033303030303030ull,0x3730303030307830ull,
0x783009090a203038ull,0x3930343036303065ull,0x3030303038783020ull,0x3065783020303837ull,
0x3020393163313030ull,0x3837303330383678ull,0x65783009090a2030ull,0x2039303430303030ull,
0x3738303030367830ull,0x3030657830203038ull,0x7830203931383030ull,0x3038373831303036ull,
0x3065783009090a20ull,0x3020393030303030ull,0x3837383030303678ull,0x3630306578302030ull,
0x3878302039336330ull,0x2030383730303030ull,0x303065783009090aull,0x7830203133343032ull,
0x3038373030303038ull,0x3830303031783020ull,0x3030783020393430ull,0x0a20333030303030ull,
0x3030303178300909ull,0x3078302064343038ull,0x2033303030313034ull,0x3831303030657830ull,
0x3030367830203134ull,0x090a203038373833ull,0x3232313065783009ull,0x3065783020646631ull,
0x3020386337303130ull,0x3030656430303178ull,0x3030303078302033ull,0x09090a2030303130ull,
0x3861393330327830ull,0x6666307830203135ull,0x7830206666666666ull,0x3330303030303035ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3034303630306578ull,0x3030303878302039ull,
0x6578302030383730ull,0x2039316331303030ull,0x3730333038367830ull,0x783009090a203038ull,
0x3930343030303065ull,0x3830303036783020ull,0x3065783020303837ull,0x3020393138303030ull,
0x3837383130303678ull,0x65783009090a2030ull,0x2039303030303030ull,0x3738303030367830ull,
0x3030657830203038ull,0x7830203933633036ull,0x3038373030303038ull,0x3065783009090a20ull,
0x3020313334303230ull,0x3837303030303878ull,0x3030303178302030ull,0x3078302039343038ull,
0x2033303030303030ull,0x303031783009090aull,0x7830206434303830ull,0x3330303031303430ull,
0x3130303065783020ull,0x3036783020313438ull,0x0a20303837383330ull,0x3231306578300909ull,
0x6578302064663132ull,0x2038633730313030ull,0x3063653030317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x6138333032783009ull,0x6630783020313538ull,0x3020666666666666ull,
0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,0x3430363030657830ull,
0x3030387830203930ull,0x7830203038373030ull,0x3931633130303065ull,0x3033303836783020ull,
0x3009090a20303837ull,0x3034303030306578ull,0x3030303678302039ull,0x6578302030383738ull,
0x2039313830303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3930303030303065ull,
0x3830303036783020ull,0x3065783020303837ull,0x3020393363303630ull,0x3837303030303878ull,
0x65783009090a2030ull,0x2031333430323030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031343831ull,0x2030383738333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6166303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3733303278300909ull,0x3078302031353861ull,
0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3036303065783009ull,0x3038783020393034ull,0x3020303837303030ull,0x3163313030306578ull,
0x3330383678302039ull,0x09090a2030383730ull,0x3430303030657830ull,0x3030367830203930ull,
0x7830203038373830ull,0x3931383030303065ull,0x3831303036783020ull,0x3009090a20303837ull,
0x3030303030306578ull,0x3030303678302039ull,0x6578302030383738ull,0x2039336330363030ull,
0x3730303030387830ull,0x783009090a203038ull,0x3133343032303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020393430383030ull,0x3030303030303078ull,0x31783009090a2033ull,
0x2064343038303030ull,0x3030313034307830ull,0x3030657830203330ull,0x7830203134383130ull,
0x3038373833303036ull,0x3065783009090a20ull,0x3020646631323231ull,0x6337303130306578ull,
0x3031303178302038ull,0x3078302033303038ull,0x2030303130303030ull,0x333032783009090aull,
0x7830203135386136ull,0x6666666666666630ull,0x3030303035783020ull,0x3030783020333030ull,
0x0a20303837303030ull,0x3630306578300909ull,0x3878302039303430ull,0x2030383730303030ull,
0x6331303030657830ull,0x3038367830203931ull,0x090a203038373033ull,0x3030303065783009ull,
0x3036783020393034ull,0x3020303837383030ull,0x3138303030306578ull,0x3130303678302039ull,
0x09090a2030383738ull,0x3030303030657830ull,0x3030367830203930ull,0x7830203038373830ull,
0x3933633036303065ull,0x3030303038783020ull,0x3009090a20303837ull,0x3334303230306578ull,
0x3030303878302031ull,0x3178302030383730ull,0x2039343038303030ull,0x3030303030307830ull,
0x783009090a203330ull,0x6434303830303031ull,0x3031303430783020ull,0x3065783020333030ull,
0x3020313438313030ull,0x3837383330303678ull,0x65783009090a2030ull,0x2064663132323130ull,
0x3730313030657830ull,0x3130317830203863ull,0x7830203330303631ull,0x3030313030303030ull,
0x3032783009090a20ull,0x3020313538613533ull,0x6666666666663078ull,0x3030303578302066ull,
0x3078302033303030ull,0x2030383730303030ull,0x303065783009090aull,0x7830203930343036ull,
0x3038373030303038ull,0x3130303065783020ull,0x3836783020393163ull,0x0a20303837303330ull,
0x3030306578300909ull,0x3678302039303430ull,0x2030383738303030ull,0x3830303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3036783020393030ull,
0x3020303837383030ull,0x3363303630306578ull,0x3030303878302039ull,0x09090a2030383730ull,
0x3430323030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3934303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302064ull,
0x6578302033303030ull,0x2031343831303030ull,0x3738333030367830ull,0x783009090a203038ull,
0x6466313232313065ull,0x3031303065783020ull,0x3031783020386337ull,0x3020333030343231ull,
0x3031303030303078ull,0x32783009090a2030ull,0x2031353861343330ull,0x6666666666307830ull,
0x3030357830206666ull,0x7830203330303030ull,0x3038373030303030ull,0x3065783009090a20ull,
0x3020393034303630ull,0x3837303030303878ull,0x3030306578302030ull,0x3678302039316331ull,
0x2030383730333038ull,0x303065783009090aull,0x7830203930343030ull,0x3038373830303036ull,
0x3030303065783020ull,0x3036783020393138ull,0x0a20303837383130ull,0x3030306578300909ull,
0x3678302039303030ull,0x2030383738303030ull,0x6330363030657830ull,0x3030387830203933ull,
0x090a203038373030ull,0x3032303065783009ull,0x3038783020313334ull,0x3020303837303030ull,
0x3430383030303178ull,0x3030303078302039ull,0x09090a2033303030ull,0x3038303030317830ull,
0x3034307830206434ull,0x7830203330303031ull,0x3134383130303065ull,0x3833303036783020ull,
0x3009090a20303837ull,0x6631323231306578ull,0x3130306578302064ull,0x3178302038633730ull,
0x2033303032333130ull,0x3130303030307830ull,0x783009090a203030ull,0x3135386133333032ull,
0x6666666630783020ull,0x3035783020666666ull,0x3020333030303030ull,0x3837303030303078ull,
0x65783009090a2030ull,0x2039303430363030ull,0x3730303030387830ull,0x3030657830203038ull,
0x7830203931633130ull,0x3038373033303836ull,0x3065783009090a20ull,0x3020393034303030ull,
0x3837383030303678ull,0x3030306578302030ull,0x3678302039313830ull,0x2030383738313030ull,
0x303065783009090aull,0x7830203930303030ull,0x3038373830303036ull,0x3036303065783020ull,
0x3038783020393363ull,0x0a20303837303030ull,0x3230306578300909ull,0x3878302031333430ull,
0x2030383730303030ull,0x3038303030317830ull,0x3030307830203934ull,0x090a203330303030ull,
0x3830303031783009ull,0x3430783020643430ull,0x3020333030303130ull,0x3438313030306578ull,
0x3330303678302031ull,0x09090a2030383738ull,0x3132323130657830ull,0x3030657830206466ull,
0x7830203863373031ull,0x3330303034313031ull,0x3030303030783020ull,0x3009090a20303031ull,
0x3538613233303278ull,0x6666663078302031ull,0x3578302066666666ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3930343036303065ull,0x3030303038783020ull,
0x3065783020303837ull,0x3020393163313030ull,0x3837303330383678ull,0x65783009090a2030ull,
0x2039303430303030ull,0x3738303030367830ull,0x3030657830203038ull,0x7830203931383030ull,
0x3038373831303036ull,0x3065783009090a20ull,0x3020393030303030ull,0x3837383030303678ull,
0x3630306578302030ull,0x3878302039336330ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203133343032ull,0x3038373030303038ull,0x3830303031783020ull,0x3030783020393430ull,
0x0a20333030303030ull,0x3030303178300909ull,0x3078302064343038ull,0x2033303030313034ull,
0x3831303030657830ull,0x3030367830203134ull,0x090a203038373833ull,0x3232313065783009ull,
0x3065783020646631ull,0x3020386337303130ull,0x3030653431303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3861313330327830ull,0x6666307830203135ull,0x7830206666666666ull,
0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303837ull,0x3034303630306578ull,
0x3030303878302039ull,0x6578302030383730ull,0x2039316331303030ull,0x3730333038367830ull,
0x783009090a203038ull,0x3930343030303065ull,0x3830303036783020ull,0x3065783020303837ull,
0x3020393138303030ull,0x3837383130303678ull,0x65783009090a2030ull,0x2039303030303030ull,
0x3738303030367830ull,0x3030657830203038ull,0x7830203933633036ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313334303230ull,0x3837303030303878ull,0x3030303178302030ull,
0x3078302039343038ull,0x2033303030303030ull,0x303031783009090aull,0x7830206434303830ull,
0x3330303031303430ull,0x3130303065783020ull,0x3036783020313438ull,0x0a20303837383330ull,
0x3231306578300909ull,0x6578302064663132ull,0x2038633730313030ull,0x3063353130317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x6130333032783009ull,0x6630783020313538ull,
0x3020666666666666ull,0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3430363030657830ull,0x3030387830203930ull,0x7830203038373030ull,0x3931633130303065ull,
0x3033303836783020ull,0x3009090a20303837ull,0x3034303030306578ull,0x3030303678302039ull,
0x6578302030383738ull,0x2039313830303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3930303030303065ull,0x3830303036783020ull,0x3065783020303837ull,0x3020393363303630ull,
0x3837303030303878ull,0x65783009090a2030ull,0x2031333430323030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302031343831ull,
0x2030383738333030ull,0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,
0x6136313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x6632303278300909ull,
0x3078302031353861ull,0x2066666666666666ull,0x3030303030357830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3036303065783009ull,0x3038783020393034ull,0x3020303837303030ull,
0x3163313030306578ull,0x3330383678302039ull,0x09090a2030383730ull,0x3430303030657830ull,
0x3030367830203930ull,0x7830203038373830ull,0x3931383030303065ull,0x3831303036783020ull,
0x3009090a20303837ull,0x3030303030306578ull,0x3030303678302039ull,0x6578302030383738ull,
0x2039336330363030ull,0x3730303030387830ull,0x783009090a203038ull,0x3133343032303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020393430383030ull,0x3030303030303078ull,
0x31783009090a2033ull,0x2064343038303030ull,0x3030313034307830ull,0x3030657830203330ull,
0x7830203134383130ull,0x3038373833303036ull,0x3065783009090a20ull,0x3020646631323231ull,
0x6337303130306578ull,0x3731303178302038ull,0x3078302033303038ull,0x2030303130303030ull,
0x323032783009090aull,0x7830203135386165ull,0x6666666666666630ull,0x3030303035783020ull,
0x3030783020333030ull,0x0a20303837303030ull,0x3630306578300909ull,0x3878302039303430ull,
0x2030383730303030ull,0x6331303030657830ull,0x3038367830203931ull,0x090a203038373033ull,
0x3030303065783009ull,0x3036783020393034ull,0x3020303837383030ull,0x3138303030306578ull,
0x3130303678302039ull,0x09090a2030383738ull,0x3030303030657830ull,0x3030367830203930ull,
0x7830203038373830ull,0x3933633036303065ull,0x3030303038783020ull,0x3009090a20303837ull,
0x3334303230306578ull,0x3030303878302031ull,0x3178302030383730ull,0x2039343038303030ull,
0x3030303030307830ull,0x783009090a203330ull,0x6434303830303031ull,0x3031303430783020ull,
0x3065783020333030ull,0x3020313438313030ull,0x3837383330303678ull,0x65783009090a2030ull,
0x2064663132323130ull,0x3730313030657830ull,0x3130317830203863ull,0x7830203330303638ull,
0x3030313030303030ull,0x3032783009090a20ull,0x3020313538616432ull,0x6666666666663078ull,
0x3030303578302066ull,0x3078302033303030ull,0x2030383730303030ull,0x303065783009090aull,
0x7830203930343036ull,0x3038373030303038ull,0x3030303065783020ull,0x3036783020393034ull,
0x0a20303837383030ull,0x6332303278300909ull,0x3078302031353861ull,0x2066666666666666ull,
0x6331303030657830ull,0x3038367830203931ull,0x090a203038373033ull,0x3030303065783009ull,
0x3036783020393030ull,0x3020303837383030ull,0x6639326337303378ull,0x3030633678302064ull,
0x09090a2038633763ull,0x3830303030657830ull,0x3030367830203931ull,0x7830203038373831ull,
0x3133343032303065ull,0x3030303038783020ull,0x3009090a20303837ull,0x3030353931303178ull,
0x3030303078302033ull,0x6578302030383230ull,0x2039336330363030ull,0x3730303030387830ull,
0x783009090a203038ull,0x3934303830303031ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020643430383030ull,0x3030303130343078ull,0x65783009090a2033ull,0x2031346331303030ull,
0x3730333030367830ull,0x3130657830203038ull,0x7830206466313232ull,0x3863373031303065ull,
0x3031783009090a20ull,0x3020333030363931ull,0x3031303030303078ull,0x3030303578302030ull,
0x3078302033303030ull,0x2030383730303030ull,0x303065783009090aull,0x7830203930343036ull,
0x3038373030303038ull,0x3130303065783020ull,0x3836783020393163ull,0x0a20303837303330ull,
0x3030306578300909ull,0x3678302039303430ull,0x2030383738303030ull,0x3830303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3036783020393030ull,
0x3020303837383030ull,0x3030313830303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3832633730337830ull,0x3063367830203530ull,0x7830203038373031ull,0x3130306430343032ull,
0x3035323430783020ull,0x3009090a20303837ull,0x3030303130306478ull,0x3030343078302031ull,
0x3378302030383730ull,0x2064663130633730ull,0x3738303063367830ull,0x783009090a203863ull,
0x3330303662313061ull,0x3030303030783020ull,0x3031783020303030ull,0x3020333030336231ull,
0x3832303030303078ull,0x64783009090a2030ull,0x2035303038303030ull,0x3730303030327830ull,
0x3030327830203038ull,0x7830203130346530ull,0x3038373030323430ull,0x3461783009090a20ull,
0x3020393030303030ull,0x3837383032303078ull,0x3030346178302030ull,0x3078302039313230ull,
0x2030383738303230ull,0x303461783009090aull,0x7830206431343030ull,0x3038373830323030ull,
0x3032303034783020ull,0x3034783020383032ull,0x0a20303132303630ull,0x3730303478300909ull,
0x3078302035313230ull,0x2030383730303030ull,0x3430303130337830ull,0x3134637830203930ull,
0x090a203038373030ull,0x3030313033783009ull,0x3463783020313138ull,0x3020303837303031ull,
0x3161303031303378ull,0x3031346378302035ull,0x09090a2030383730ull,0x3030323030367830ull,
0x3030307830203530ull,0x7830203038373830ull,0x3930303036303036ull,0x3031303030783020ull,
0x3009090a20303837ull,0x3030303730303678ull,0x3130303078302064ull,0x6178302030383734ull,
0x2031303230303030ull,0x3763303034307830ull,0x783009090a203038ull,0x3531343030303061ull,
0x6330303430783020ull,0x3061783020303837ull,0x3020393136303030ull,0x3837633030343078ull,
0x31783009090a2030ull,0x2033303036623130ull,0x3730303030307830ull,0x3030317830203038ull,
0x7830203931386630ull,0x3038376333303430ull,0x3031783009090a20ull,0x3020353138663030ull,
0x3837633330363078ull,0x3030303178302030ull,0x3078302031303866ull,0x2030383763333034ull,
0x303031783009090aull,0x7830203530323230ull,0x3238376330303434ull,0x3035313034783020ull,
0x3030783020643034ull,0x0a20303837303030ull,0x3030313278300909ull,0x3078302039303265ull,
0x2030383738303634ull,0x3630343130367830ull,0x3030307830203131ull,0x090a203038376330ull,
0x3066313033783009ull,0x6365783020643034ull,0x3020303837303031ull,0x3138303031303378ull,
0x3031346378302031ull,0x09090a2030383730ull,0x3630323830647830ull,0x3434307830206430ull,
0x7830203038373030ull,0x3131343034313036ull,0x3031303030783020ull,0x3009090a20303837ull,
0x3036383230303278ull,0x3131303478302063ull,0x3278302038323430ull,0x2031303830303030ull,
0x3730303034307830ull,0x783009090a203038ull,0x6431363031303033ull,0x3030316365783020ull,
0x3036783020303837ull,0x3020313136303031ull,0x3837383230303078ull,0x31783009090a2030ull,
0x2063303438323030ull,0x6538303030327830ull,0x3130337830203030ull,0x7830203131383030ull,
0x3038373030313463ull,0x3032783009090a20ull,0x3020333030396431ull,0x3837303030303078ull,
0x3331303478302030ull,0x3078302039323430ull,0x2030383730303030ull,0x313036783009090aull,
0x7830206430343030ull,0x3038373031303030ull,0x3030303031783020ull,0x3430783020313130ull,
0x0a20303837633330ull,0x3231303678300909ull,0x3078302031323630ull,0x2030383738323030ull,
0x3638353030327830ull,0x3030317830203030ull,0x090a206330343832ull,0x3130313033783009ull,
0x3463783020353130ull,0x3020303837303031ull,0x3065303030303278ull,0x3030343078302031ull,
0x09090a2030383730ull,0x3430323130367830ull,0x3030307830203530ull,0x7830203038373431ull,
0x3330303964313032ull,0x3030303030783020ull,0x3009090a20303837ull,0x3032383630303278ull,
0x3030303178302063ull,0x6178302034303038ull,0x2064303830303030ull,0x3763303030307830ull,
0x783009090a203038ull,0x3130653030303032ull,0x6330303430783020ull,0x3033783020303837ull,
0x3020393034303830ull,0x3837303031306378ull,0x31783009090a2030ull,0x2064303430303030ull,
0x3763333034307830ull,0x3130327830203038ull,0x7830203330303964ull,0x3038373030303030ull,
0x3064783009090a20ull,0x3020393036303230ull,0x3837343030303078ull,0x6530306478302030ull,
0x6178302035303631ull,0x2030383730303430ull,0x303032783009090aull,0x7830203530363932ull,
0x3330303030303030ull,0x3065303064783020ull,0x3061783020313032ull,0x0a20303837303030ull,
0x3030303378300909ull,0x3078302033303030ull,0x2030383730303030ull,0x3630303030617830ull,
0x3134307830203932ull,0x090a203038373431ull,0x3130303061783009ull,0x3434783020313334ull,
0x3020303837343030ull,0x3330303030306178ull,0x3131343078302035ull,0x09090a2030383734ull,
0x3831303030397830ull,0x3030307830203933ull,0x7830203038373030ull,0x3133613130303061ull,
0x3436303434783020ull,0x3009090a20303837ull,0x3363396533303278ull,0x6666663078302039ull,
0x6378302066666666ull,0x2031333831653030ull,0x3763303030307830ull,0x783009090a203063ull,
0x3133383130303061ull,0x3436303438783020ull,0x3034783020303837ull,0x3020643338323931ull,
0x3837303030303078ull,0x36783009090a2030ull,0x2064336132383130ull,0x3763333030307830ull,
0x3130337830203038ull,0x7830206433653130ull,0x3038373030313463ull,0x3036783009090a20ull,
0x3020643338323831ull,0x3837633330303078ull,0x3034303278302030ull,0x3078302064336131ull,
0x2030383763333034ull,0x303061783009090aull,0x7830206433653130ull,0x3038373436303434ull,
0x3165303063783020ull,0x3030783020393365ull,0x0a20306337633030ull,0x3030306178300909ull,
0x3878302039336331ull,0x2030383734363034ull,0x3831303030327830ull,0x3034307830203133ull,
0x090a203038373833ull,0x3334313034783009ull,0x3030783020393332ull,0x3020303837303030ull,
0x3330333531303678ull,0x3330303078302039ull,0x09090a2030383738ull,0x6331303130337830ull,
0x3134637830203933ull,0x7830203038373030ull,0x3933303334313036ull,0x3833303030783020ull,
0x3009090a20303837ull,0x3363313030303378ull,0x3330343078302035ull,0x3378302030383734ull,
0x2039323431643030ull,0x3763303034367830ull,0x783009090a203038ull,0x3130363030303064ull,
0x3830303430783020ull,0x3033783020303837ull,0x3020313030306631ull,0x3837303031346578ull,
0x33783009090a2030ull,0x2031333431303030ull,0x3730333034307830ull,0x3030617830203038ull,
0x7830203932303030ull,0x3038373431306332ull,0x3064783009090a20ull,0x3020393234316330ull,
0x3837383030343078ull,0x6337303378302030ull,0x3678302064663730ull,0x2038633734313063ull,
0x303032783009090aull,0x7830203130303030ull,0x3038373832303430ull,0x3033303064783020ull,
0x3430783020313030ull,0x0a20303035633230ull,0x3030303378300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x3030303030667830ull,0x3030657830203130ull,0x090a203130303030ull,
0x65646f630a7d0a7dull,0x656d616e090a7b20ull,0x4d38315a5f203d20ull,0x6f72626c65646e61ull,
0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6c090a69695f5366ull,
0x0a30203d206d656dull,0x203d206d656d7309ull,0x20676572090a3836ull,0x62090a3432203d20ull,
0x0a30203d20207261ull,0x7b2074736e6f6309ull,0x6e6765730909090aull,0x6f63203d20656d61ull,
0x730909090a74736eull,0x3d20206d756e6765ull,0x666f0909090a3120ull,0x203d202074657366ull,
0x7479620909090a30ull,0x32203d2020207365ull,0x206d656d09090a34ull,0x3078300909090a7bull,
0x2066663330303030ull,0x3030303030307830ull,0x3036347830206130ull,0x7830203030343030ull,
0x3130303030303030ull,0x3478300909090a20ull,0x2030303030303830ull,0x6666666666667830ull,
0x0a7d09090a206666ull,0x636e6962090a7d09ull,0x09090a7b2065646full,0x3230303830647830ull,
0x3430307830203530ull,0x7830203038373030ull,0x3930343030303031ull,0x3430303034783020ull,
0x3009090a20303837ull,0x3032303030306178ull,0x3030343078302064ull,0x3178302030383730ull,
0x2035303230303030ull,0x3734303030347830ull,0x783009090a203038ull,0x3930303030303061ull,
0x3030303430783020ull,0x3036783020303837ull,0x3020353065343230ull,0x3837633032303078ull,
0x36783009090a2030ull,0x2039306334313030ull,0x3738303230307830ull,0x3030337830203038ull,
0x7830206466666331ull,0x3863373031326336ull,0x3033783009090a20ull,0x3020646664633230ull,
0x6332303132633678ull,0x3030303378302038ull,0x3078302033303030ull,0x2030303130303030ull,
0x303031783009090aull,0x7830203130633030ull,0x3038376330303434ull,0x3033303034783020ull,
0x3030783020643030ull,0x0a20303837303030ull,0x3230303678300909ull,0x3078302064303230ull,
0x2030383763303030ull,0x3630303130337830ull,0x3134637830206430ull,0x090a203038373030ull,
0x3032303036783009ull,0x3030783020313030ull,0x3020303837633030ull,0x3030303030303278ull,
0x3030343078302031ull,0x09090a2030383738ull,0x3030323030337830ull,0x3134637830206430ull,
0x7830203038373030ull,0x3533386330303032ull,0x6330323430783020ull,0x3009090a20303837ull,
0x3061316530306478ull,0x3063303878302064ull,0x3378302030383730ull,0x2031313630383030ull,
0x3730303134657830ull,0x783009090a203038ull,0x6466353063373033ull,0x6330306336783020ull,
0x3061783020386337ull,0x3020333030643230ull,0x3030303030303078ull,0x61783009090a2030ull,
0x2031336330303030ull,0x3738303034307830ull,0x3030617830203038ull,0x7830206432653030ull,
0x3038373830303430ull,0x3061783009090a20ull,0x3020393230313030ull,0x3837383030343078ull,
0x3230303178302030ull,0x3078302033303063ull,0x2030383230303030ull,0x333032783009090aull,
0x7830206430613963ull,0x6666666666666630ull,0x3065303064783020ull,0x3038783020643036ull,
0x0a20303837303063ull,0x3830303378300909ull,0x6578302031313630ull,0x2030383730303134ull,
0x6330303030617830ull,0x3034307830203531ull,0x090a203038373830ull,0x3130303061783009ull,
0x3430783020313130ull,0x3020303837383030ull,0x3161386334303278ull,0x6134303278302034ull,
0x09090a2038313838ull,0x6530303030617830ull,0x3034307830206430ull,0x7830203038373830ull,
0x3131613030303061ull,0x3431313430783020ull,0x3009090a20303837ull,0x3163303030306178ull,
0x3131343078302035ull,0x3278302030383734ull,0x2064303630303430ull,0x3763323034307830ull,
0x783009090a203038ull,0x3131383031383033ull,0x3031346336783020ull,0x3033783020303837ull,
0x3020353161303138ull,0x3837303134633678ull,0x61783009090a2030ull,0x2064303630303030ull,
0x3734313134307830ull,0x3030647830203038ull,0x7830203131383035ull,0x3038373430303430ull,
0x3033783009090a20ull,0x3020643036303138ull,0x3837303134633678ull,0x3430306478302030ull,
0x3078302064303630ull,0x2030383734303034ull,0x303061783009090aull,0x7830206430363030ull,
0x3038373431306332ull,0x6432303031783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3030303178300909ull,0x3078302064303866ull,0x2030383763333036ull,0x3030303030667830ull,
0x3030657830203130ull,0x090a203230303030ull,0x3434303061783009ull,0x3030783020333030ull,
0x3020303030303030ull,0x3134383130303278ull,0x3030303078302031ull,0x09090a2033303030ull,
0x6463343030337830ull,0x3263367830206466ull,0x7830203863376330ull,0x3330303434303031ull,
0x3030303030783020ull,0x3009090a20303832ull,0x3161393430303278ull,0x3030303078302031ull,
0x6478302033303030ull,0x2031313830653030ull,0x3730306330387830ull,0x783009090a203038ull,
0x3531383038303033ull,0x3030313465783020ull,0x3061783020303837ull,0x3020393130313030ull,
0x3837383030343078ull,0x61783009090a2030ull,0x2035313431303030ull,0x3738303034307830ull,
0x3430327830203038ull,0x7830203831633863ull,0x6331613861343032ull,0x3061783009090a20ull,
0x3020313132313030ull,0x3837383030343078ull,0x3030306178302030ull,0x3078302035316330ull,
0x2030383734313134ull,0x303061783009090aull,0x7830203931653030ull,0x3038373431313430ull,
0x3030343032783020ull,0x3430783020313138ull,0x0a20303837633230ull,0x3138303378300909ull,
0x3678302035316130ull,0x2030383730313463ull,0x6330313830337830ull,0x3463367830203931ull,
0x090a203038373031ull,0x3030303061783009ull,0x3430783020313138ull,0x3020303837343131ull,
0x3161303630306478ull,0x3030343078302035ull,0x09090a2030383734ull,0x3830313830337830ull,
0x3463367830203131ull,0x7830203038373031ull,0x3131383035303064ull,0x3430303430783020ull,
0x3009090a20303837ull,0x3138303030306178ull,0x3130633278302031ull,0x3278302030383734ull,
0x2064303630303030ull,0x3730313034307830ull,0x783009090a203038ull,0x6466333063373033ull,
0x6330306336783020ull,0x3061783020616337ull,0x3020333030623530ull,0x3030303030303078ull,
0x31783009090a2030ull,0x2033303062353030ull,0x3230303030307830ull,0x3030337830203038ull,
0x7830203131636330ull,0x3038373030323430ull,0x3033783009090a20ull,0x3020313138303230ull,
0x3837303031346378ull,0x3030303278302030ull,0x3078302031313863ull,0x2030383730313234ull,
0x303064783009090aull,0x7830203131383065ull,0x3038373030633038ull,0x3038303033783020ull,
0x3465783020393138ull,0x0a20303837303031ull,0x3030306178300909ull,0x3078302035313031ull,
0x2030383738303034ull,0x3831303030617830ull,0x3034307830203931ull,0x090a203038373830ull,
0x3863343032783009ull,0x3032783020343161ull,0x3020383163386134ull,0x3132313030306178ull,
0x3030343078302031ull,0x09090a2030383738ull,0x6130303030617830ull,0x3134307830203531ull,
0x7830203038373431ull,0x3931633030303061ull,0x3431313430783020ull,0x3009090a20303837ull,
0x3138303034303278ull,0x3230343078302031ull,0x3378302030383763ull,0x2035316130313830ull,
0x3730313463367830ull,0x783009090a203038ull,0x3931633031383033ull,0x3031346336783020ull,
0x3061783020303837ull,0x3020313138303030ull,0x3837343131343078ull,0x64783009090a2030ull,
0x2035316130363030ull,0x3734303034307830ull,0x3830337830203038ull,0x7830203131383031ull,
0x3038373031346336ull,0x3064783009090a20ull,0x3020313138303530ull,0x3837343030343078ull,
0x3030306178302030ull,0x3278302031313830ull,0x2030383734313063ull,0x303032783009090aull,
0x7830206430363030ull,0x3038373031303430ull,0x3030303066783020ull,0x3065783020313030ull,
0x0a20323030303030ull,0x3730306178300909ull,0x3078302033303034ull,0x2030303030303030ull,
0x3238313030327830ull,0x3030307830203131ull,0x090a203330303030ull,0x6334303033783009ull,
0x6336783020646666ull,0x3020386337633032ull,0x3030343730303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6363303030327830ull,0x3234307830203130ull,0x7830203038373030ull,
0x3130303032303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3038633030303278ull,
0x3032343078302031ull,0x6478302030383730ull,0x2031303030653030ull,0x3730306330387830ull,
0x783009090a203038ull,0x3531303038303033ull,0x3030313465783020ull,0x3061783020303837ull,
0x3020313130303030ull,0x3837383030343078ull,0x61783009090a2030ull,0x2035313431303030ull,
0x3738303034307830ull,0x3430327830203038ull,0x7830203031383863ull,0x3431613861343032ull,
0x3061783009090a20ull,0x3020313032303030ull,0x3837383030343078ull,0x3030306178302030ull,
0x3078302031313830ull,0x2030383734313134ull,0x303061783009090aull,0x7830203531613030ull,
0x3038373431313430ull,0x3030343032783020ull,0x3430783020313030ull,0x0a20303837633230ull,
0x3138303378300909ull,0x3678302031313830ull,0x2030383730313463ull,0x6130313830337830ull,
0x3463367830203531ull,0x090a203038373031ull,0x3030303061783009ull,0x3430783020313030ull,
0x3020303837343131ull,0x3138303530306478ull,0x3030343078302031ull,0x09090a2030383734ull,
0x3030313830337830ull,0x3463367830203130ull,0x7830203038373031ull,0x3130303034303064ull,
0x3430303430783020ull,0x3009090a20303837ull,0x3030303030306178ull,0x3130633278302031ull,
0x3278302030383734ull,0x2064303630303030ull,0x3730303034307830ull,0x783009090a203038ull,
0x6466373063373033ull,0x3830306336783020ull,0x3033783020616337ull,0x3020333030303030ull,
0x3832303030303078ull,0x61783009090a2030ull,0x2031313230303030ull,0x3734313034347830ull,
0x3030317830203038ull,0x7830203130363130ull,0x3038376330303434ull,0x3065783009090a20ull,
0x3020393161643430ull,0x3837303032303078ull,0x3030306178302030ull,0x3478302035303430ull,
0x2030383734313034ull,0x303031783009090aull,0x7830203130323130ull,0x3038376330303434ull,
0x6434303065783020ull,0x3430783020393061ull,0x0a20303837383132ull,0x3130306578300909ull,
0x3078302064306164ull,0x2030383730303230ull,0x6330303030627830ull,0x3038307830203531ull,
0x090a203038373830ull,0x6431303065783009ull,0x3430783020313061ull,0x3020303837633032ull,
0x3161643430306578ull,0x3132383078302035ull,0x09090a2030383734ull,0x3637323431627830ull,
0x3430627830203031ull,0x7830203830363030ull,0x3131383030303062ull,0x3431303030783020ull,
0x3009090a20303837ull,0x3061643130306578ull,0x3032383078302035ull,0x6278302030383738ull,
0x2030303237303431ull,0x3837343031627830ull,0x783009090a206331ull,0x3430303031303062ull,
0x3037303062783020ull,0x3062783020303063ull,0x3020353134643030ull,0x3837343032303078ull,
0x65783009090a2030ull,0x2039303030323830ull,0x3730303438307830ull,0x3430627830203038ull,
0x7830203032303036ull,0x3430363035303062ull,0x3065783009090a20ull,0x3020313130303238ull,
0x3837383034383078ull,0x3030306378302030ull,0x6278302038313030ull,0x2038306530383430ull,
0x343062783009090aull,0x7830206330323033ull,0x6331303034343062ull,0x3034303065783020ull,
0x3830783020353238ull,0x0a20303837383130ull,0x3230306378300909ull,0x6278302030323030ull,
0x2063306130333430ull,0x6530343030657830ull,0x3030307830203532ull,0x090a203038373432ull,
0x3032303065783009ull,0x3030783020643330ull,0x3020303837303230ull,0x3132303238306578ull,
0x3034383078302035ull,0x09090a2030383734ull,0x3230333030637830ull,0x3030307830203933ull,
0x7830203038373030ull,0x3532653034303065ull,0x3432303030783020ull,0x3009090a20303837ull,
0x3230303030306578ull,0x3330303078302031ull,0x6578302030383763ull,0x2031313230323830ull,
0x3734313438307830ull,0x783009090a203038ull,0x3534323033303065ull,0x3833303030783020ull,
0x3063783020303837ull,0x3020303432303130ull,0x3430313634306278ull,0x62783009090a2038ull,
0x2039333230303030ull,0x3730313038307830ull,0x3030657830203038ull,0x7830203531323031ull,
0x3038373434303030ull,0x3065783009090a20ull,0x3020643438303430ull,0x3837303430383078ull,
0x3235306278302030ull,0x6278302063336531ull,0x2038343031323530ull,0x303062783009090aull,
0x7830203135613030ull,0x3038373034303830ull,0x3134303065783020ull,0x3030783020643463ull,
0x0a20303837633430ull,0x3235306278300909ull,0x6278302038316330ull,0x2034356130343530ull,
0x6331343030657830ull,0x3030307830203934ull,0x090a203038376334ull,0x3234353062783009ull,
0x3062783020343432ull,0x3020303430323535ull,0x3165303730306578ull,0x3230303078302031ull,
0x09090a2030383734ull,0x6531303030627830ull,0x3030307830203931ull,0x7830203038373831ull,
0x6431633165303065ull,0x3834303030783020ull,0x3009090a20303837ull,0x3232323031306278ull,
0x3630306278302034ull,0x6278302030313830ull,0x2064316530303030ull,0x3734323030307830ull,
0x783009090a203038ull,0x3931343032303065ull,0x3031303030783020ull,0x3065783020303837ull,
0x3020643136303330ull,0x3837633130303078ull,0x62783009090a2030ull,0x2034343031363030ull,
0x6130373030627830ull,0x3130627830203034ull,0x7830203031323230ull,0x3432306134303062ull,
0x3062783009090a20ull,0x3020383338303934ull,0x3130323534306278ull,0x3934306278302034ull,
0x6278302034323232ull,0x2038333032653430ull,0x343062783009090aull,0x7830203834653035ull,
0x3431323238343062ull,0x3165303062783020ull,0x3062783020633132ull,0x0a20633363303534ull,
0x3730306278300909ull,0x6278302034313432ull,0x2034316531353030ull,0x3830353030627830ull,
0x3430627830203032ull,0x090a203031303134ull,0x3030303062783009ull,0x3830783020353261ull,
0x3020303837303130ull,0x6631643338303378ull,0x3036633678302064ull,0x09090a2038633738ull,
0x3066663331327830ull,0x6666307830203933ull,0x7830206666666666ull,0x3031323830303031ull,
0x3832303031783020ull,0x3009090a20383130ull,0x3136383030303178ull,0x3230303178302034ull,
0x3178302063313438ull,0x2033303030313130ull,0x3230303030307830ull,0x783009090a203038ull,
0x3132303130303062ull,0x3432303030783020ull,0x3062783020303837ull,0x3020646631313438ull,
0x6337343034303678ull,0x34783009090a2038ull,0x2033303030313130ull,0x3030303030307830ull,
0x3030357830203030ull,0x7830203330303030ull,0x3030313030303030ull,0x3063783009090a20ull,
0x3020643432303230ull,0x3837303030303078ull,0x3238306578302030ull,0x3078302031323230ull,
0x2030383734303438ull,0x383065783009090aull,0x7830203532303032ull,0x3038373030343830ull,
0x3031303063783020ull,0x3030783020313530ull,0x0a20303837303030ull,0x3330306578300909ull,
0x3078302064343030ull,0x2030383763343030ull,0x3230303430657830ull,0x3634307830203132ull,
0x090a203334303030ull,0x3030343065783009ull,0x3430783020353230ull,0x3020333430303036ull,
0x3530303130306578ull,0x3430303078302035ull,0x09090a2030383763ull,0x3031393030657830ull,
0x3038307830206435ull,0x7830203038373035ull,0x3935303030303062ull,0x3432303830783020ull,
0x3009090a20303837ull,0x3030303130306578ull,0x3530343078302031ull,0x6278302030383734ull,
0x2035303230303030ull,0x3730323038307830ull,0x783009090a203038ull,0x3132303136313065ull,
0x6335303030783020ull,0x3062783020303837ull,0x3020633436323034ull,0x3061323034306278ull,
0x62783009090a2030ull,0x2031303832303030ull,0x3730303038307830ull,0x3030657830203038ull,
0x7830203132323039ull,0x3038373032303030ull,0x3065783009090a20ull,0x3020353032303631ull,
0x3837303230303078ull,0x3030306278302030ull,0x6278302030303632ull,0x2030303030313030ull,
0x303065783009090aull,0x7830203930363032ull,0x3038373030303030ull,0x3232303062783020ull,
0x3062783020343261ull,0x0a20343032313930ull,0x3130306278300909ull,0x6278302030323239ull,
0x2030303032313530ull,0x3039313030627830ull,0x3530627830206334ull,0x090a203035303030ull,
0x3135353062783009ull,0x3062783020633032ull,0x3020303232313834ull,0x3232313335306278ull,
0x3435306278302034ull,0x09090a2063343030ull,0x3232343130627830ull,0x3530627830203434ull,
0x7830203034303233ull,0x6330343033343062ull,0x3139303062783020ull,0x3009090a20383030ull,
0x3230323135306278ull,0x3330306278302030ull,0x6278302038303430ull,0x2030323031323130ull,
0x3430333030627830ull,0x783009090a203432ull,0x3032303166343062ull,0x3131303062783020ull,
0x3062783020303432ull,0x3020633430303830ull,0x3030323630306278ull,0x62783009090a2038ull,
0x2063303632343030ull,0x3061323030627830ull,0x3530627830203434ull,0x7830206333363033ull,
0x3834326132303062ull,0x3062783009090a20ull,0x3020303536306634ull,0x3032383031306278ull,
0x3235306278302034ull,0x6278302038343032ull,0x2034353632303430ull,0x353062783009090aull,
0x7830203034633031ull,0x3434363234353062ull,0x3066343062783020ull,0x3062783020633338ull,
0x0a20303032313134ull,0x3231306278300909ull,0x6278302034303032ull,0x2034323031353530ull,
0x3232663030627830ull,0x3030627830203032ull,0x090a203030303031ull,0x3139303062783009ull,
0x3062783020343030ull,0x3020633365303030ull,0x3461303130306278ull,0x3230306278302030ull,
0x09090a2030306531ull,0x3630303130627830ull,0x3030627830203430ull,0x7830203830343830ull,
0x6430323030303062ull,0x6330303830783020ull,0x3009090a20303837ull,0x3232303238306578ull,
0x3034383078302031ull,0x6578302030383734ull,0x2035323030323830ull,0x3730303438307830ull,
0x783009090a203038ull,0x3830653132343062ull,0x3233343062783020ull,0x3065783020633030ull,
0x3020313232303034ull,0x3430303036343078ull,0x65783009090a2033ull,0x2035323030303430ull,
0x3030303634307830ull,0x3030637830203334ull,0x7830203034303030ull,0x6334323031303063ull,
0x3062783009090a20ull,0x3020383432303834ull,0x3330303934306278ull,0x3930306578302063ull,
0x3078302035343231ull,0x2030383730343038ull,0x303063783009090aull,0x7830203135323033ull,
0x3038373030303030ull,0x3138303065783020ull,0x3830783020353530ull,0x0a20303837633430ull,
0x3030306378300909ull,0x3078302031343430ull,0x2030383730303030ull,0x6531393030657830ull,
0x3030307830206434ull,0x090a203038373434ull,0x3033303065783009ull,0x3030783020353432ull,
0x3020303837303530ull,0x3534323830306578ull,0x3530303078302031ull,0x09090a2030383734ull,
0x3430303030657830ull,0x3030307830203134ull,0x7830203038373034ull,0x6434653139303065ull,
0x6334303030783020ull,0x3009090a20303837ull,0x3232303130306578ull,0x3430303078302035ull,
0x6578302030383734ull,0x2035353432383030ull,0x3730353030307830ull,0x783009090a203038ull,
0x3132303030303065ull,0x3034303030783020ull,0x3065783020303837ull,0x3020643365316630ull,
0x3837633430303078ull,0x65783009090a2030ull,0x2031353230313030ull,0x3734323034307830ull,
0x3130657830203038ull,0x7830203934343232ull,0x3038373435303030ull,0x3065783009090a20ull,
0x3020643430303030ull,0x3837303230343078ull,0x3435306278302030ull,0x6278302034343232ull,
0x2034353231343530ull,0x353062783009090aull,0x7830203035303233ull,0x3034303133353062ull,
0x3031303065783020ull,0x3830783020643432ull,0x0a20303837343530ull,0x3030306578300909ull,
0x3078302031343030ull,0x2030383730343038ull,0x3632313130627830ull,0x3130627830203434ull,
0x090a203034303234ull,0x3232313062783009ull,0x3062783020343432ull,0x3020633330326630ull,
0x3436303330306578ull,0x3430303078302039ull,0x09090a2030383734ull,0x3430323030657830ull,
0x3030307830206433ull,0x7830203038376333ull,0x3034323132313062ull,0x3166303062783020ull,
0x3009090a20343430ull,0x3432323031306278ull,0x3934306278302063ull,0x6278302034323032ull,
0x2030353061333130ull,0x3432393430627830ull,0x783009090a203834ull,0x3435363234353062ull,
0x3234353062783020ull,0x3062783020343232ull,0x3020303530323535ull,0x3232323834306278ull,
0x62783009090a2030ull,0x2034323231343130ull,0x6531383430627830ull,0x3030627830206333ull,
0x7830203132343230ull,0x3038373432303030ull,0x3132783009090a20ull,0x3020393363313030ull,
0x6337343134343078ull,0x3030306278302030ull,0x3078302031326531ull,0x2030383730323030ull,
0x303035783009090aull,0x7830203330303030ull,0x3030313030303030ull,0x3238303062783020ull,
0x3062783020343236ull,0x0a20633432313335ull,0x3335306278300909ull,0x6278302030323031ull,
0x2030323231383030ull,0x3131343830627830ull,0x3430367830206466ull,0x090a203863373430ull,
0x3862303031783009ull,0x3030783020333030ull,0x3020303832303030ull,0x3030303030303578ull,
0x3030303078302033ull,0x09090a2030383730ull,0x6331633730337830ull,0x3063367830203530ull,
0x7830203038373031ull,0x3130306430343032ull,0x3833323430783020ull,0x3009090a20303837ull,
0x3030303130306478ull,0x3030343078302031ull,0x3378302030383730ull,0x2064663130633730ull,
0x3738303063367830ull,0x783009090a203863ull,0x3330306132313061ull,0x3030303030783020ull,
0x3031783020303030ull,0x3020333030373231ull,0x3832303030303078ull,0x64783009090a2030ull,
0x2035303037303030ull,0x3730303030327830ull,0x3030327830203038ull,0x7830203130306530ull,
0x3038373030323430ull,0x3461783009090a20ull,0x3020393030303030ull,0x3837383032303078ull,
0x3030346178302030ull,0x3078302039313230ull,0x2030383738303230ull,0x303461783009090aull,
0x7830206431343030ull,0x3038373830323030ull,0x3032303034783020ull,0x3034783020383032ull,
0x0a20303132303630ull,0x3730303478300909ull,0x3078302035313230ull,0x2030383730303030ull,
0x3430303130337830ull,0x3134637830203930ull,0x090a203038373030ull,0x3030313033783009ull,
0x3463783020313138ull,0x3020303837303031ull,0x3161303031303378ull,0x3031346378302035ull,
0x09090a2030383730ull,0x3030323030367830ull,0x3030307830203530ull,0x7830203038373830ull,
0x3930303036303036ull,0x3031303030783020ull,0x3009090a20303837ull,0x3030303730303678ull,
0x3130303078302064ull,0x6178302030383734ull,0x2031303230303030ull,0x3763303034307830ull,
0x783009090a203038ull,0x3531343030303061ull,0x6330303430783020ull,0x3061783020303837ull,
0x3020393136303030ull,0x3837633030343078ull,0x31783009090a2030ull,0x2033303061323130ull,
0x3730303030307830ull,0x3030317830203038ull,0x7830203931386630ull,0x3038376333303430ull,
0x3031783009090a20ull,0x3020353138663030ull,0x3837633330363078ull,0x3030303178302030ull,
0x3078302031303866ull,0x2030383763333034ull,0x303031783009090aull,0x7830203530653130ull,
0x3238376330303434ull,0x3039313034783020ull,0x3030783020643034ull,0x0a20303837303030ull,
0x3130313278300909ull,0x3078302039306566ull,0x2033303030303030ull,0x3630383130367830ull,
0x3030307830203131ull,0x090a203038376330ull,0x3066313033783009ull,0x6365783020643034ull,
0x3020303837303031ull,0x3138303031303378ull,0x3031346378302031ull,0x09090a2030383730ull,
0x3630333830647830ull,0x3434307830206430ull,0x7830203038373030ull,0x3131343038313036ull,
0x3031303030783020ull,0x3009090a20303837ull,0x3036383230303278ull,0x3531303478302063ull,
0x3278302030323430ull,0x2031303830303030ull,0x3730303034307830ull,0x783009090a203038ull,
0x6431363031303033ull,0x3030316365783020ull,0x3036783020303837ull,0x3020313136303431ull,
0x3837303230303078ull,0x31783009090a2030ull,0x2063303438323030ull,0x6538303030327830ull,
0x3130337830203030ull,0x7830203131383030ull,0x3038373030313463ull,0x3032783009090a20ull,
0x3020333030643431ull,0x3837303030303078ull,0x3731303478302030ull,0x3078302031323430ull,
0x2030383730303030ull,0x313036783009090aull,0x7830206430343034ull,0x3038373031303030ull,
0x3030303031783020ull,0x3430783020313130ull,0x0a20303837633330ull,0x3631303678300909ull,
0x3078302031323630ull,0x2030383730323030ull,0x3638353030327830ull,0x3030317830203030ull,
0x090a206330343832ull,0x3130313033783009ull,0x3463783020353130ull,0x3020303837303031ull,
0x3065303030303278ull,0x3030343078302031ull,0x09090a2030383730ull,0x3430363130367830ull,
0x3030307830203530ull,0x7830203038373431ull,0x3330306434313032ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3032383630303278ull,0x3030303178302063ull,0x6178302034303038ull,
0x2064303830303030ull,0x3763303030307830ull,0x783009090a203038ull,0x3130653030303032ull,
0x6330303430783020ull,0x3033783020303837ull,0x3020393034303830ull,0x3837303031306378ull,
0x31783009090a2030ull,0x2064303430303030ull,0x3763333034307830ull,0x3130327830203038ull,
0x7830203330306434ull,0x3038373030303030ull,0x3064783009090a20ull,0x3020393036303230ull,
0x3837343030303078ull,0x6530306478302030ull,0x6178302035306131ull,0x2030383730303430ull,
0x303032783009090aull,0x7830203530613932ull,0x3330303030303030ull,0x3065303064783020ull,
0x3061783020313032ull,0x0a20303837303030ull,0x3030303378300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x3630303030617830ull,0x3134307830203132ull,0x090a203038373431ull,
0x3130303061783009ull,0x3434783020353230ull,0x3020303837343030ull,0x3330303030306178ull,
0x3131343078302031ull,0x09090a2030383734ull,0x3231303030397830ull,0x3030307830203933ull,
0x7830203038373030ull,0x3532383130303061ull,0x3436303434783020ull,0x3009090a20303837ull,
0x3363396533303278ull,0x6666663078302039ull,0x6378302066666666ull,0x2035323231653030ull,
0x3763303030307830ull,0x783009090a203063ull,0x3532323130303061ull,0x3436303438783020ull,
0x3034783020303837ull,0x3020643330323331ull,0x3837303030303078ull,0x36783009090a2030ull,
0x2064333232323130ull,0x3763333030307830ull,0x3130337830203038ull,0x7830206433653130ull,
0x3038373030313463ull,0x3036783009090a20ull,0x3020643330323231ull,0x3837633330303078ull,
0x3034303278302030ull,0x3078302064333831ull,0x2030383763333034ull,0x303061783009090aull,
0x7830206433653130ull,0x3038373436303434ull,0x3165303063783020ull,0x3030783020393365ull,
0x0a20306337633030ull,0x3030306178300909ull,0x3878302039336331ull,0x2030383734363034ull,
0x3231303030327830ull,0x3034307830203532ull,0x090a203038373833ull,0x3230313034783009ull,
0x3030783020393336ull,0x3020303837303030ull,0x3334323131303678ull,0x3330303078302039ull,
0x09090a2030383738ull,0x6331303130337830ull,0x3134637830203933ull,0x7830203038373030ull,
0x3933343230313036ull,0x3833303030783020ull,0x3009090a20303837ull,0x3363313030303378ull,
0x3330343078302031ull,0x3378302030383730ull,0x2031323031633030ull,0x3763303034367830ull,
0x783009090a203038ull,0x3130363030303064ull,0x3830303430783020ull,0x3033783020303837ull,
0x3020313030306631ull,0x3837303031346578ull,0x33783009090a2030ull,0x2035323031303030ull,
0x3734323034307830ull,0x3030617830203038ull,0x7830203132303030ull,0x3038373431306332ull,
0x3064783009090a20ull,0x3020313230313930ull,0x3837383030343078ull,0x6337303378302030ull,
0x3678302064663730ull,0x2038633734313063ull,0x303032783009090aull,0x7830203130303030ull,
0x3038373032303430ull,0x3033303064783020ull,0x3430783020313030ull,0x0a20303035633230ull,
0x3030303378300909ull,0x3078302033303030ull,0x2030383730303030ull,0x3030303030667830ull,
0x3030657830203130ull,0x090a203130303030ull,0x000000000a7d0a7dull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries[] = {{0,0}};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"481101bc4b5a515f",(char*)"Mandelbrot_sm10.cu",(char*)" ",__ptxEntries,__cubinEntries,__debugEntries,0,0,0,0,0,0x518a5ccc};
# 5 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;int __dummy_field;};
struct __T21 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;int __dummy_field;};
struct __T22 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;uchar4 __par7;int __par8;int __par9;int __dummy_field;};
struct __T23 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;uchar4 __par7;int __par8;int __par9;int __dummy_field;};
struct __T24 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;uchar4 __par7;int __par8;int __par9;int __dummy_field;};
struct __T25 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;uchar4 __par7;int __par8;int __par9;int __dummy_field;};
static void __sti____cudaRegisterAll_51_tmpxft_000062e6_00000000_17_Mandelbrot_sm10_cpp1_ii_daf12029(void) __attribute__((__constructor__));
void __device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffS_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4 & __par9, const int __par10, const int __par11){auto struct __T20 *__T2124;
char __[256]; *(char**)&__T2124 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2124->__par0 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2124->__par1 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2124->__par2 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2124->__par3 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2124->__par4 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2124->__par5 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2124->__par6 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2124->__par7 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2124->__par8 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2124->__par9 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2124->__par10 - (size_t)__T2124) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2124->__par11 - (size_t)__T2124) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS0_sm10__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS0_sm10__entry))); };}

}
void MandelbrotDS0_sm10__entry( uchar4 * __cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const uchar4 __cuda_9,const int __cuda_10,const int __cuda_11)
{__device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffS_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9, __cuda_10, __cuda_11);}
extern "C"{

void __device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffS_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4 & __par9, const int __par10, const int __par11){auto struct __T21 *__T2125;
char __[256]; *(char**)&__T2125 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2125->__par0 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2125->__par1 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2125->__par2 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2125->__par3 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2125->__par4 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2125->__par5 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2125->__par6 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2125->__par7 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2125->__par8 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2125->__par9 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2125->__par10 - (size_t)__T2125) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2125->__par11 - (size_t)__T2125) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS1_sm10__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS1_sm10__entry))); };}

}
void MandelbrotDS1_sm10__entry( uchar4 * __cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const uchar4 __cuda_9,const int __cuda_10,const int __cuda_11)
{__device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffS_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9, __cuda_10, __cuda_11);}
extern "C"{

static void __device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const uchar4 & __par7, const int __par8, const int __par9){auto struct __T22 *__T2128;
char __[256]; *(char**)&__T2128 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2128->__par0 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2128->__par1 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2128->__par2 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2128->__par3 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2128->__par4 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2128->__par5 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2128->__par6 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2128->__par7 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2128->__par8 - (size_t)__T2128) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2128->__par9 - (size_t)__T2128) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot0_sm10__entry<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot0_sm10__entry<float> ))); };}

}
template<>



void __wrapper__device_stub_Mandelbrot0_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const uchar4 &__cuda_7,const int &__cuda_8,const int &__cuda_9)
{__device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9);}
extern "C"{

static void __device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const uchar4 & __par7, const int __par8, const int __par9){auto struct __T23 *__T2129;
char __[256]; *(char**)&__T2129 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2129->__par0 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2129->__par1 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2129->__par2 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2129->__par3 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2129->__par4 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2129->__par5 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2129->__par6 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2129->__par7 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2129->__par8 - (size_t)__T2129) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2129->__par9 - (size_t)__T2129) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot0_sm10__entry<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot0_sm10__entry<double> ))); };}

}
template<>



void __wrapper__device_stub_Mandelbrot0_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const uchar4 &__cuda_7,const int &__cuda_8,const int &__cuda_9)
{__device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9);}
extern "C"{

static void __device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const uchar4 & __par7, const int __par8, const int __par9){auto struct __T24 *__T2132;
char __[256]; *(char**)&__T2132 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2132->__par0 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2132->__par1 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2132->__par2 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2132->__par3 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2132->__par4 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2132->__par5 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2132->__par6 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2132->__par7 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2132->__par8 - (size_t)__T2132) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2132->__par9 - (size_t)__T2132) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot1_sm10__entry<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot1_sm10__entry<float> ))); };}

}
template<>



void __wrapper__device_stub_Mandelbrot1_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const uchar4 &__cuda_7,const int &__cuda_8,const int &__cuda_9)
{__device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9);}
extern "C"{

static void __device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const uchar4 & __par7, const int __par8, const int __par9){auto struct __T25 *__T2133;
char __[256]; *(char**)&__T2133 = __;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2133->__par0 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2133->__par1 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2133->__par2 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2133->__par3 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2133->__par4 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2133->__par5 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2133->__par6 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2133->__par7 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2133->__par8 - (size_t)__T2133) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2133->__par9 - (size_t)__T2133) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot1_sm10__entry<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot1_sm10__entry<double> ))); };}

}
template<>



void __wrapper__device_stub_Mandelbrot1_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const uchar4 &__cuda_7,const int &__cuda_8,const int &__cuda_9)
{__device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii( __cuda_0, __cuda_1, __cuda_2, __cuda_3, __cuda_4, __cuda_5, __cuda_6, __cuda_7, __cuda_8, __cuda_9);}
extern "C"{
# 95 "/tmp/tmpxft_000062e6_00000000-4_Mandelbrot_sm10.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_000062e6_00000000_17_Mandelbrot_sm10_cpp1_ii_daf12029(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot1_sm10__entry<double> ), (char*)"_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii", "_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot1_sm10__entry<float> ), (char*)"_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii", "_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const uchar4, const int, const int))Mandelbrot0_sm10__entry<double> ), (char*)"_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii", "_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S0_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const uchar4, const int, const int))Mandelbrot0_sm10__entry<float> ), (char*)"_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii", "_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S0_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS1_sm10__entry), (char*)"_Z18MandelbrotDS1_sm10P6uchar4iiifffffS_ii", "_Z18MandelbrotDS1_sm10P6uchar4iiifffffS_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int))MandelbrotDS0_sm10__entry), (char*)"_Z18MandelbrotDS0_sm10P6uchar4iiifffffS_ii", "_Z18MandelbrotDS0_sm10P6uchar4iiifffffS_ii", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);}

}
# 257 "Mandelbrot_sm10.cu" 2

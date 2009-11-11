# 1 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.cpp"
# 1 "dxtc.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
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
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 2 3
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
# 60 "/usr/include/time.h" 3
extern "C" { typedef __clock_t clock_t; }
# 76 "/usr/include/time.h" 3
extern "C" { typedef __time_t time_t; }
# 92 "/usr/include/time.h" 3
extern "C" { typedef __clockid_t clockid_t; }
# 104 "/usr/include/time.h" 3
extern "C" { typedef __timer_t timer_t; }
# 120 "/usr/include/time.h" 3
extern "C" { struct timespec {

__time_t tv_sec;
long tv_nsec;
}; }
# 133 "/usr/include/time.h" 3
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
# 161 "/usr/include/time.h" 3
extern "C" { struct itimerspec {

timespec it_interval;
timespec it_value;
}; }


struct sigevent;
# 174 "/usr/include/time.h" 3
extern "C" { typedef __pid_t pid_t; }
# 183 "/usr/include/time.h" 3
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" time_t time(time_t *) throw();


extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__));



extern "C" time_t mktime(tm *) throw();
# 199 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw();
# 207 "/usr/include/time.h" 3
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


extern "C" { typedef __locale_t locale_t; }
# 217 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw();
# 224 "/usr/include/time.h" 3
extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw();
# 233 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *) throw();



extern "C" tm *localtime(const time_t *) throw();
# 243 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw();




extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 255 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *) throw();


extern "C" char *ctime(const time_t *) throw();
# 266 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw();



extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw();
# 276 "/usr/include/time.h" 3
extern "C" { extern char *__tzname[2]; }
extern "C" { extern int __daylight; }
extern "C" { extern long __timezone; }




extern "C" { extern char *tzname[2]; }



extern "C" void tzset() throw();



extern "C" { extern int daylight; }
extern "C" { extern long timezone; }
# 298 "/usr/include/time.h" 3
extern "C" int stime(const time_t *) throw();
# 313 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *) throw();


extern "C" time_t timelocal(tm *) throw();


extern "C" int dysize(int) throw() __attribute__((__const__));
# 328 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *);




extern "C" int clock_getres(clockid_t, timespec *) throw();


extern "C" int clock_gettime(clockid_t, timespec *) throw();


extern "C" int clock_settime(clockid_t, const timespec *) throw();
# 347 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *);




extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw();




extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw();




extern "C" int timer_delete(timer_t) throw();


extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw();




extern "C" int timer_gettime(timer_t, itimerspec *) throw();



extern "C" int timer_getoverrun(timer_t) throw();
# 390 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 399 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 413 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__);
# 43 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw();




extern "C" void *memmove(void *, const void *, size_t) throw();
# 56 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 64 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));
# 74 "/usr/include/string.h" 3
extern void *memchr(void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__));

extern const void *memchr(const void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__));
# 103 "/usr/include/string.h" 3
extern void *rawmemchr(void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__));

extern const void *rawmemchr(const void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__));
# 114 "/usr/include/string.h" 3
extern void *memrchr(void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__));

extern const void *memrchr(const void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__));
# 127 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw();




extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__));


extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__));



extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__));


extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw();
# 164 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));


extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw();
# 173 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__));
# 181 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__));
# 213 "/usr/include/string.h" 3
extern char *strchr(char *, int) throw() __asm__("strchr") __attribute__((__pure__));

extern const char *strchr(const char *, int) throw() __asm__("strchr") __attribute__((__pure__));
# 240 "/usr/include/string.h" 3
extern char *strrchr(char *, int) throw() __asm__("strrchr") __attribute__((__pure__));

extern const char *strrchr(const char *, int) throw() __asm__("strrchr") __attribute__((__pure__));
# 269 "/usr/include/string.h" 3
extern char *strchrnul(char *, int) throw() __asm__("strchrnul") __attribute__((__pure__));

extern const char *strchrnul(const char *, int) throw() __asm__("strchrnul") __attribute__((__pure__));
# 282 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__));



extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__));
# 292 "/usr/include/string.h" 3
extern char *strpbrk(char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__));

extern const char *strpbrk(const char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__));
# 319 "/usr/include/string.h" 3
extern char *strstr(char *, const char *) throw() __asm__("strstr") __attribute__((__pure__));

extern const char *strstr(const char *, const char *) throw() __asm__("strstr") __attribute__((__pure__));
# 346 "/usr/include/string.h" 3
extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw();
# 352 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();




extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();
# 365 "/usr/include/string.h" 3
extern char *strcasestr(char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__));

extern const char *strcasestr(const char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__));
# 380 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__));
# 386 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();


extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();
# 397 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__));
# 404 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__));
# 411 "/usr/include/string.h" 3
extern "C" char *strerror(int) throw();
# 436 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw();
# 443 "/usr/include/string.h" 3
extern "C" char *strerror_l(int, __locale_t) throw();
# 449 "/usr/include/string.h" 3
extern "C" void __bzero(void *, size_t) throw();



extern "C" void bcopy(const void *, void *, size_t) throw();



extern "C" void bzero(void *, size_t) throw();


extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));
# 467 "/usr/include/string.h" 3
extern char *index(char *, int) throw() __asm__("index") __attribute__((__pure__));

extern const char *index(const char *, int) throw() __asm__("index") __attribute__((__pure__));
# 495 "/usr/include/string.h" 3
extern char *rindex(char *, int) throw() __asm__("rindex") __attribute__((__pure__));

extern const char *rindex(const char *, int) throw() __asm__("rindex") __attribute__((__pure__));
# 521 "/usr/include/string.h" 3
extern "C" int ffs(int) throw() __attribute__((__const__));




extern "C" int ffsl(long) throw() __attribute__((__const__));

extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 534 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__));
# 545 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));



extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__));
# 557 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw();
# 564 "/usr/include/string.h" 3
extern "C" char *strsignal(int) throw();


extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw();

extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw();




extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();


extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();
# 584 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" char *strfry(char *) throw();


extern "C" void *memfrob(void *, size_t) throw();
# 599 "/usr/include/string.h" 3
extern char *basename(char *) throw() __asm__("basename");

extern const char *basename(const char *) throw() __asm__("basename");
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
# 524 "/usr/include/stdlib.h" 3
extern int at_quick_exit(void (*)(void)) throw() __asm__("at_quick_exit");
# 535 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw();
# 543 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 551 "/usr/include/stdlib.h" 3
extern "C" void quick_exit(int) throw() __attribute__((__noreturn__));
# 559 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 566 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw();




extern "C" char *__secure_getenv(const char *) throw();
# 578 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw();
# 584 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw();



extern "C" int unsetenv(const char *) throw();
# 595 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 604 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *) throw();
# 615 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *);
# 625 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *);
# 635 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw();
# 646 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int);
# 656 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int);
# 666 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 673 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw();
# 683 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 691 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }


extern "C" { typedef __compar_fn_t comparison_fn_t; }



extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 704 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);
# 710 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t);


extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *);
# 720 "/usr/include/stdlib.h" 3
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 734 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));

extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 742 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 756 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw();
# 762 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw();
# 768 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw();
# 774 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw();


extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw();


extern "C" char *qgcvt(long double, int, char *) throw();
# 786 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();


extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 808 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();


extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int wctomb(char *, wchar_t) throw();



extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();


extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 833 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw();
# 844 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw();
# 853 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw();
# 861 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 869 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();



extern "C" int unlockpt(int) throw();




extern "C" char *ptsname(int) throw();
# 885 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw();



extern "C" int getpt();
# 896 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 69 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
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
# 142 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
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
# 195 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
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
# 417 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 37 "/usr/include/c++/4.4/ext/type_traits.h" 3
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
# 77 "/usr/include/c++/4.4/cmath" 3
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
    typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value
        && __is_arithmetic < _Up > :: __value,
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
# 369 "/usr/include/c++/4.4/cmath" 3
inline double pow(double __x, int __i)
{ return __builtin_powi(__x, __i); }


inline float pow(float __x, int __n)
{ return __builtin_powif(__x, __n); }


inline long double pow(long double __x, int __n)
{ return __builtin_powil(__x, __n); }


template < typename _Tp, typename _Up >
    inline
    typename __gnu_cxx :: __promote_2 <
    typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value
        && __is_arithmetic < _Up > :: __value,
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
# 492 "/usr/include/c++/4.4/cmath" 3
namespace std __attribute__((visibility("default"))) {

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    fpclassify ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_fpclassify ( FP_NAN, FP_INFINITE, FP_NORMAL,
      FP_SUBNORMAL, FP_ZERO, __type ( __f ) );
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
# 35 "/usr/include/c++/4.4/bits/cmath.tcc" 3
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
# 49 "/usr/include/c++/4.4/cstddef" 3
namespace std __attribute__((visibility("default"))) {

using ::ptrdiff_t;
using ::size_t;

}
# 100 "/usr/include/c++/4.4/cstdlib" 3
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
# 157 "/usr/include/c++/4.4/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {


using ::lldiv_t;
# 166 "/usr/include/c++/4.4/cstdlib" 3
using ::_Exit;



inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }


using ::llabs;


inline lldiv_t div(long long __n, long long __d)
{ auto lldiv_t __q; (__q.quot) = __n / __d; (__q.rem) = __n % __d; return __q; }

using ::lldiv;
# 190 "/usr/include/c++/4.4/cstdlib" 3
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
# 95 "/usr/include/wchar.h" 3
extern "C" { typedef
# 84 "/usr/include/wchar.h" 3
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stdarg.h" 3
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
# 296 "/usr/include/stdio.h" 3
extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 302 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 309 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();



extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 320 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();



extern "C" void setlinebuf(FILE *) throw();
# 333 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 339 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);

extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 348 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 354 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list);

extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 363 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();



extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 376 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();


extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();


extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 394 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);


extern "C" int dprintf(int, const char *__restrict__, ...);
# 407 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 413 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);

extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 453 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 461 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);



extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 513 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
extern "C" int getc(FILE *);
# 520 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 532 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
extern "C" int getchar_unlocked();
# 543 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE *);
# 555 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
extern "C" int putc(int, FILE *);
# 562 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 576 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int, FILE *);
# 584 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
extern "C" int putchar_unlocked(int);
# 592 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);


extern "C" int putw(int, FILE *);
# 604 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 612 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 622 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 638 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);


extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 651 "/usr/include/stdio.h" 3
extern "C" __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__);
# 662 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 668 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 675 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 682 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 688 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 699 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 710 "/usr/include/stdio.h" 3
extern "C" size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__);

extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 722 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);




extern "C" long ftell(FILE *);




extern "C" void rewind(FILE *);
# 746 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);




extern "C" __off_t ftello(FILE *);
# 771 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);




extern "C" int fsetpos(FILE *, const fpos_t *);
# 791 "/usr/include/stdio.h" 3
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
# 819 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
extern "C" { extern const char *const sys_errlist[]; }


extern "C" { extern int _sys_nerr; }
extern "C" { extern const char *const _sys_errlist[]; }
# 831 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();




extern "C" int fileno_unlocked(FILE *) throw();
# 846 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 852 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 858 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 864 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);




struct obstack;


extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();


extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 886 "/usr/include/stdio.h" 3
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
# 143 "CudaMath.h"
inline float3 firstEigenVector(float matrix[6])
{


auto float3 v = make_float3((1.0F), (1.0F), (1.0F));
for (int i = 0; i < 8; i++) {
auto float x = ((v.x * matrix[0] + v.y * matrix[1]) + v.z * matrix[2]);
auto float y = ((v.x * matrix[1] + v.y * matrix[3]) + v.z * matrix[4]);
auto float z = ((v.x * matrix[2] + v.y * matrix[4]) + v.z * matrix[5]);
auto float m = max(max(x, y), z);
auto float iv = ((1.0F) / m);



v = make_float3(x * iv, y * iv, z * iv);
}

return v;
}
# 45 "dds.h"
extern "C" { typedef unsigned uint; }
extern "C" { typedef unsigned short ushort; }

struct DDSPixelFormat {
uint size;
uint flags;
uint fourcc;
uint bitcount;
uint rmask;
uint gmask;
uint bmask;
uint amask;
};

struct DDSCaps {
uint caps1;
uint caps2;
uint caps3;
uint caps4;
};


struct DDSHeader {
uint fourcc;
uint size;
uint flags;
uint height;
uint width;
uint pitch;
uint depth;
uint mipmapcount;
uint reserved[11];
DDSPixelFormat pf;
DDSCaps caps;
uint notused;
};

static const uint FOURCC_DDS = (((((unsigned)'D') | (((unsigned)'D') << 8)) | (((unsigned)'S') << 16)) | (((unsigned)' ') << 24));
static const uint FOURCC_DXT1 = (((((unsigned)'D') | (((unsigned)'X') << 8)) | (((unsigned)'T') << 16)) | (((unsigned)'1') << 24));
static const uint DDSD_WIDTH = (4U);
static const uint DDSD_HEIGHT = (2U);
static const uint DDSD_CAPS = (1U);
static const uint DDSD_PIXELFORMAT = (4096U);
static const uint DDSCAPS_TEXTURE = (4096U);
static const uint DDPF_FOURCC = (4U);
static const uint DDSD_LINEARSIZE = (524288U);
# 42 "permutations.h"
static void computePermutations(uint permutations[1024])
{
auto int indices[16];
auto int num = 0;




for (int m = 0; m < 16; ++m)
{
((indices)[m]) = 0;
}
auto const int imax = 15;
for (int i = imax; i >= 0; --i)
{

for (int m = i; m < 16; ++m)
{
((indices)[m]) = 2;
}
auto const int jmax = ((i == 0) ? 15 : 16);
for (int j = jmax; j >= i; --j)
{

if (j < 16)
{
((indices)[j]) = 1;
}

auto uint permutation = (0);

for (int p = 0; p < 16; p++) {
permutation |= ((indices)[p]) << (p * 2);

}

(permutations[num]) = permutation;

num++;
}
}
__cutilCondition(num == 151, (char *)("permutations.h"), 83);

for (int i = 0; i < 9; i++)
{
(permutations[num]) = (697685);
num++;
}
__cutilCondition(num == 160, (char *)("permutations.h"), 90);




for (int m = 0; m < 16; ++m)
{
((indices)[m]) = 0;
}

for (int i = imax; i >= 0; --i)
{

for (int m = i; m < 16; ++m)
{
((indices)[m]) = 2;
}
auto const int jmax = ((i == 0) ? 15 : 16);
for (int j = jmax; j >= i; --j)
{

for (int m = j; m < 16; ++m)
{
((indices)[m]) = 3;
}

auto int kmax = ((j == 0) ? 15 : 16);
for (int k = kmax; k >= j; --k)
{

if (k < 16)
{
((indices)[k]) = 1;
}

auto uint permutation = (0);

auto bool hasThree = false;
for (int p = 0; p < 16; p++) {
permutation |= ((indices)[p]) << (p * 2);


if (((indices)[p]) == 3) { hasThree = true; }
}

if (hasThree) {
(permutations[num]) = permutation;
num++;
}
}
}
}
__cutilCondition(num == 975, (char *)("permutations.h"), 142);




for (int i = 0; i < 49; i++)
{
(permutations[num]) = (11206485);
num++;
}

__cutilCondition(num == 1024, (char *)("permutations.h"), 153);
}
# 79 "dxtc.cu"
static float3 kColorMetric__cuda_shadow_variable__;
# 200 "dxtc.cu"
static float alphaTable4__cuda_shadow_variable__[4];
static float alphaTable3__cuda_shadow_variable__[4];
static int prods4__cuda_shadow_variable__[4];
static int prods3__cuda_shadow_variable__[4];
# 508 "dxtc.cu"
void compress__entry(const uint *permutations, const uint *image, uint2 *result);
# 544 "dxtc.cu"
union Color32 {
struct {
unsigned char b; unsigned char g; unsigned char r; unsigned char a;
};
unsigned u;
};

union Color16 {
struct {
unsigned short b:5;
unsigned short g:6;
unsigned short r:5;
};
unsigned short u;
};

struct BlockDXT1 {

Color16 col0;
Color16 col1;
union {
unsigned char row[4];
unsigned indices;
};

void decompress(Color32 [16]) const;
};

void BlockDXT1::decompress(Color32 *colors) const
{
auto Color32 palette[4];


(((palette)[0]).b) = (((this->col0).b) << 3) | (((this->col0).b) >> 2);
(((palette)[0]).g) = (((this->col0).g) << 2) | (((this->col0).g) >> 4);
(((palette)[0]).r) = (((this->col0).r) << 3) | (((this->col0).r) >> 2);
(((palette)[0]).a) = (255);

(((palette)[1]).r) = (((this->col1).r) << 3) | (((this->col1).r) >> 2);
(((palette)[1]).g) = (((this->col1).g) << 2) | (((this->col1).g) >> 4);
(((palette)[1]).b) = (((this->col1).b) << 3) | (((this->col1).b) >> 2);
(((palette)[1]).a) = (255);

if (((this->col0).u) > ((this->col1).u)) {

(((palette)[2]).r) = (2 * ((palette)[0]).r + ((palette)[1]).r) / 3;
(((palette)[2]).g) = (2 * ((palette)[0]).g + ((palette)[1]).g) / 3;
(((palette)[2]).b) = (2 * ((palette)[0]).b + ((palette)[1]).b) / 3;
(((palette)[2]).a) = (255);

(((palette)[3]).r) = (2 * ((palette)[1]).r + ((palette)[0]).r) / 3;
(((palette)[3]).g) = (2 * ((palette)[1]).g + ((palette)[0]).g) / 3;
(((palette)[3]).b) = (2 * ((palette)[1]).b + ((palette)[0]).b) / 3;
(((palette)[3]).a) = (255);
} else
{

(((palette)[2]).r) = (((palette)[0]).r + ((palette)[1]).r) / 2;
(((palette)[2]).g) = (((palette)[0]).g + ((palette)[1]).g) / 2;
(((palette)[2]).b) = (((palette)[0]).b + ((palette)[1]).b) / 2;
(((palette)[2]).a) = (255);

(((palette)[3]).r) = (0);
(((palette)[3]).g) = (0);
(((palette)[3]).b) = (0);
(((palette)[3]).a) = (0);
}

for (int i = 0; i < 16; i++)
{
(colors[i]) = (palette)[((this->indices) >> (2 * i)) & (3)];
}
}

static int compareColors(const Color32 *b0, const Color32 *b1)
{
auto int sum = 0;
for (int i = 0; i < 16; i++)
{
auto int r = ((b0[i]).r - (b1[i]).r);
auto int g = ((b0[i]).g - (b1[i]).g);
auto int b = ((b0[i]).b - (b1[i]).b);
sum += (r * r + g * g) + b * b;
}
return sum;
}

static int compareBlock(const BlockDXT1 *b0, const BlockDXT1 *b1)
{
auto Color32 colors0[16];
auto Color32 colors1[16];

if (memcmp(b0, b1, sizeof(BlockDXT1)) == 0)
{
return 0;
} else

{
b0->decompress(colors0);
b1->decompress(colors1);

return compareColors(colors0, colors1);
}
}
# 653 "dxtc.cu"
int main(int argc, char **argv)
{

if (cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
cutilDeviceInit(argc, argv); } else {

cudaSetDevice(cutGetMaxGflopsDeviceId()); }


auto unsigned char *data = (__null);
auto uint W; auto uint H;

auto char *image_path = cutFindFilePath("lena_std.ppm", argv[0]);
if (image_path == (0)) {
printf("Error, unable to find source image\n");
cudaThreadExit();
exit(1);
}

if (!(cutLoadPPM4ub(image_path, &data, &W, &H))) {
printf("Error, unable to open source image\n");
cudaThreadExit();
exit(1);
}

auto uint w; auto uint h;


w = W >> 4;
h = H >> 4;


auto const uint memSize = ((w * h) * (4));
__cutilCondition((0) != memSize, (char *)("dxtc.cu"), 686);

auto uint *image = ((uint *)malloc(memSize));


for (uint by = (0); by < (h / (4)); by++) {
for (uint bx = (0); bx < (w / (4)); bx++) {
for (int i = 0; i < 16; i++) {
auto const int x = (i & 3);
auto const int y = (i / 4);
(image[((by * w) / (4) + bx) * (16) + i]) = ((uint *)data)[(((by * (4) + y) * (4)) * (W / (4)) + bx * (4)) + x];

}
}
}


auto uint *d_data = (__null);
__cudaSafeCall(cudaMalloc((void **)(&d_data), memSize), "dxtc.cu", 704);


auto uint *d_result = (__null);
auto const uint compressedSize = (((w / (4)) * (h / (4))) * (8));
__cudaSafeCall(cudaMalloc((void **)(&d_result), compressedSize), "dxtc.cu", 709);
auto uint *result = ((uint *)malloc(compressedSize));


auto uint permutations[1024];
computePermutations(permutations);


auto uint *d_permutations = (__null);
__cudaSafeCall(cudaMalloc((void **)(&d_permutations), (1024) * sizeof(uint)), "dxtc.cu", 718);
__cudaSafeCall(cudaMemcpy(d_permutations, permutations, (1024) * sizeof(uint), cudaMemcpyHostToDevice), "dxtc.cu", 720);



auto uint timer;
__cutilCheckError(cutCreateTimer(&timer), "dxtc.cu", 724);

__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 726);
__cutilCheckError(cutStartTimer(timer), "dxtc.cu", 727);


__cudaSafeCall(cudaMemcpy(d_data, image, memSize, cudaMemcpyHostToDevice), "dxtc.cu", 730);

auto uint blocks = (((w + (3)) / (4)) * ((h + (3)) / (4)));
cudaConfigureCall(blocks, 64) ? ((void)0) : compress__entry(d_permutations, d_data, (uint2 *)d_result);

__cutilCheckMsg("compress", "dxtc.cu", 735);

__cudaSafeCall(cudaMemcpy(result, d_result, compressedSize, cudaMemcpyDeviceToHost), "dxtc.cu", 737);

__cudaSafeCall(cudaThreadSynchronize(), "dxtc.cu", 739);
__cutilCheckError(cutStopTimer(timer), "dxtc.cu", 740);

auto float time = cutGetTimerValue(timer);
printf("Time %f msec\n", time);

auto char output_filename[1024];
strcpy(output_filename, image_path);
strcpy((output_filename + strlen(image_path)) - 3, "dds");


auto FILE *fp = fopen(output_filename, "wb");
if (fp == (0)) {
printf("Error, unable to open output image\n");
cudaThreadExit();
exit(1);
}

auto DDSHeader header;
(header.fourcc) = FOURCC_DDS;
(header.size) = (124);
(header.flags) = (((((DDSD_WIDTH) | (DDSD_HEIGHT)) | (DDSD_CAPS)) | (DDSD_PIXELFORMAT)) | (DDSD_LINEARSIZE));
(header.height) = h;
(header.width) = w;
(header.pitch) = compressedSize;
(header.depth) = (0);
(header.mipmapcount) = (0);
memset(header.reserved, 0, sizeof(header.reserved));
((header.pf).size) = (32);
((header.pf).flags) = DDPF_FOURCC;
((header.pf).fourcc) = FOURCC_DXT1;
((header.pf).bitcount) = (0);
((header.pf).rmask) = (0);
((header.pf).gmask) = (0);
((header.pf).bmask) = (0);
((header.pf).amask) = (0);
((header.caps).caps1) = DDSCAPS_TEXTURE;
((header.caps).caps2) = (0);
((header.caps).caps3) = (0);
((header.caps).caps4) = (0);
(header.notused) = (0);

fwrite(&header, sizeof(DDSHeader), 1, fp);
fwrite(result, compressedSize, 1, fp);

fclose(fp);


auto const char *reference_image_path = (cutFindFilePath("lena_ref.dds", argv[0]));
if (reference_image_path == (0)) {
printf("Error, unable to find reference image\n");
cudaThreadExit();
exit(1);
}

fp = fopen(reference_image_path, "rb");
if (fp == (0)) {
printf("Error, unable to open reference image\n");
cudaThreadExit();
exit(1);
}

fseek(fp, sizeof(DDSHeader), 0);

auto uint referenceSize = (((W / (4)) * (H / (4))) * (8));
auto uint *reference = ((uint *)malloc(referenceSize));
fread(reference, referenceSize, 1, fp);

fclose(fp);

auto float rms = (0);

for (uint y = (0); y < h; y += (4))
{
for (uint x = (0); x < w; x += (4))
{
auto uint referenceBlockIdx = ((y / (4)) * (W / (4)) + x / (4));
auto uint resultBlockIdx = ((y / (4)) * (w / (4)) + x / (4));

auto int cmp = compareBlock((BlockDXT1 *)result + resultBlockIdx, (BlockDXT1 *)reference + referenceBlockIdx);
if (cmp != (0.0F)) {
printf("Error at (%d, %d):\t%f rms\n", x / (4), y / (4), ((float)cmp / (16)) / (3));
}
rms += cmp;
}
}
rms /= (w * h) * (3);

printf("RMS(reference, result) = %f\n", rms);

if (rms <= (0.0F))
{
printf("Test PASSED\n");
} else

{
printf("Test FAILED\n");
}


cutFree(image_path);
cutFree(data);
free(image);
__cudaSafeCall(cudaFree(d_permutations), "dxtc.cu", 842);
__cudaSafeCall(cudaFree(d_data), "dxtc.cu", 843);
__cudaSafeCall(cudaFree(d_result), "dxtc.cu", 844);
free(result);

__cutilCheckError(cutDeleteTimer(timer), "dxtc.cu", 847);

cudaThreadExit();

__cutilExit(argc, argv); return 0;
}

# 1 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_0000641b_00000000-3_dxtc.fatbin.c" 1
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
# 2 "/tmp/tmpxft_0000641b_00000000-3_dxtc.fatbin.c" 2




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
0x090a38383032203dull,0x32203d2020676572ull,0x2020726162090a38ull,0x6e6f63090a31203dull,
0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,0x756e676573090909ull,
0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,0x2020736574796209ull,
0x09090a3836203d20ull,0x09090a7b206d656dull,0x3030303030783009ull,0x3030783020663030ull,
0x3020666630303030ull,0x3030303030303078ull,0x3030303078302038ull,0x09090a2034303030ull,
0x3030303030783009ull,0x3030783020323030ull,0x3020313030303030ull,0x3030303038643378ull,
0x3038663378302030ull,0x09090a2030303030ull,0x3030303030783009ull,0x3030783020666433ull,
0x3020663930303030ull,0x3030303030303078ull,0x3030303078302033ull,0x09090a2030323030ull,
0x3030313134783009ull,0x3030783020303030ull,0x3020303034303030ull,0x3535353535353578ull,
0x3038303478302035ull,0x09090a2030303030ull,0x3030303030783009ull,0x7d09090a20663130ull,
0x6e6962090a7d090aull,0x090a7b2065646f63ull,0x3030303061783009ull,0x3430783020313030ull,
0x3020303837303030ull,0x6631303038303378ull,0x3134633678302064ull,0x09090a2038633730ull,
0x3062303130617830ull,0x3030307830203330ull,0x7830203030303030ull,0x3530303032303030ull,
0x3030303063783020ull,0x3009090a20303837ull,0x3030623031303178ull,0x3030303078302033ull,
0x3478302030383230ull,0x2035316332303131ull,0x3030303030307830ull,0x783009090a203330ull,
0x6430303032303033ull,0x3030313463783020ull,0x3033783020303837ull,0x3020313130303130ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2035313030303030ull,0x3734313034307830ull,
0x3430347830203038ull,0x7830203931303063ull,0x3330303030303030ull,0x3032783009090a20ull,
0x3020643136303030ull,0x3837303130343078ull,0x3238306478302030ull,0x3078302031323030ull,
0x2030383738303434ull,0x303033783009090aull,0x7830206430613032ull,0x3038373030313463ull,
0x3030303030783020ull,0x3063783020643063ull,0x0a20303837303030ull,0x6133303278300909ull,
0x3078302031316538ull,0x2062303030303030ull,0x3031633430347830ull,0x3030307830203531ull,
0x090a203330303030ull,0x6330303032783009ull,0x3430783020643063ull,0x3020303837633032ull,
0x3036306530306478ull,0x3063303878302064ull,0x09090a2030383730ull,0x3830323030307830ull,
0x3030637830203930ull,0x7830203038373030ull,0x3131613030303030ull,0x3030303063783020ull,
0x3009090a20303837ull,0x3136303138306478ull,0x3034343078302031ull,0x3378302030383730ull,
0x2035313630303130ull,0x3730303134637830ull,0x783009090a203038ull,0x3931363038303033ull,
0x3030313463783020ull,0x3061783020303837ull,0x3020643038303030ull,0x3837343030343478ull,
0x33783009090a2030ull,0x2031316130383130ull,0x3730303134657830ull,0x3130337830203038ull,
0x7830203531633038ull,0x3038373030313465ull,0x3063783009090a20ull,0x3020643036303130ull,
0x3038303862333078ull,0x3030306178302062ull,0x3478302031313830ull,0x2030383734303034ull,
0x303061783009090aull,0x7830203531613030ull,0x3038373430303434ull,0x3130306330783020ull,
0x3465783020313034ull,0x0a20303837633032ull,0x3130306378300909ull,0x3078302031313830ull,
0x2062303830386233ull,0x6130313030637830ull,0x6233307830203531ull,0x090a206230383038ull,
0x3130306330783009ull,0x3465783020313036ull,0x3020303837303132ull,0x3038313030633078ull,
0x3132346578302031ull,0x09090a2030383734ull,0x3437303063307830ull,0x3234657830203130ull,
0x7830203038376330ull,0x3130363730306330ull,0x3031323465783020ull,0x3009090a20303837ull,
0x3130643130306478ull,0x3030303278302031ull,0x3078302034383730ull,0x2031303837303063ull,
0x3734313234657830ull,0x783009090a203038ull,0x3931306330303062ull,0x6330323030783020ull,
0x3062783020343837ull,0x3020313232633030ull,0x3837303132303078ull,0x62783009090a2034ull,
0x2035323463303030ull,0x3734313230307830ull,0x3830647830203438ull,0x7830203932303033ull,
0x3038373830343430ull,0x3034783009090a20ull,0x3020393234316334ull,0x3030303030303078ull,
0x3030633078302033ull,0x6578302031303437ull,0x2030383738313234ull,0x303030783009090aull,
0x7830203131343130ull,0x3038373030303063ull,0x3730306330783020ull,0x3465783020313036ull,
0x0a20303837303232ull,0x3130306478300909ull,0x3278302031313064ull,0x2034383730303030ull,
0x3837303063307830ull,0x3234657830203130ull,0x090a203038373432ull,0x6330303062783009ull,
0x3030783020393130ull,0x3020343837383132ull,0x3232633030306278ull,0x3232303078302031ull,
0x09090a2034383730ull,0x3463303030627830ull,0x3230307830203532ull,0x7830203438373432ull,
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
0x3532346330303062ull,0x3432323030783020ull,0x6330783020343837ull,0x3020313034373030ull,
0x3837383132346578ull,0x30783009090a2030ull,0x2031303637303063ull,0x3730323234657830ull,
0x3063307830203038ull,0x7830203130383730ull,0x3038373432323465ull,0x3064783009090a20ull,
0x3020313130643130ull,0x3837303030303278ull,0x3638306578302030ull,0x3078302039313063ull,
0x2034383763303634ull,0x303063783009090aull,0x7830203132633036ull,0x3038373030303030ull,
0x3032303030783020ull,0x3063783020643065ull,0x0a20303837303030ull,0x3130633078300909ull,
0x6578302031303437ull,0x2030383730323234ull,0x3263363830657830ull,0x3634307830206431ull,
0x090a203438373031ull,0x3037303063783009ull,0x3030783020313263ull,0x3020303837303030ull,
0x3036373130633078ull,0x3232346578302031ull,0x09090a2030383730ull,0x3463363830657830ull,
0x3634307830203132ull,0x7830203438373431ull,0x3931633038303063ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3038373130633078ull,0x3132346578302031ull,0x6378302030383738ull,
0x2039316530373030ull,0x3730303030307830ull,0x783009090a203038ull,0x3130613731306330ull,
0x3831323465783020ull,0x3063783020303837ull,0x3020393165303830ull,0x3837303030303078ull,
0x30783009090a2030ull,0x2031306337313063ull,0x3738313234657830ull,0x3030637830203038ull,
0x7830206431303138ull,0x3038373030303030ull,0x3031783009090a20ull,0x3020313230383830ull,
0x3030303030303078ull,0x3130633078302033ull,0x6578302031306537ull,0x2030383763313234ull,
0x303033783009090aull,0x7830206466313130ull,0x3863376330306336ull,0x6636303061783020ull,
0x3030783020333030ull,0x0a20303030303030ull,0x3630303178300909ull,0x3078302033303066ull,
0x2030383230303030ull,0x3031303030327830ull,0x3034307830203931ull,0x090a203038373030ull,
0x3836343034783009ull,0x3030783020393163ull,0x3020333030303030ull,0x3063303230303078ull,
0x3030306378302064ull,0x09090a2030383730ull,0x3064353063647830ull,0x3030327830206430ull,
0x7830203038373030ull,0x3831306530306431ull,0x3636303962783020ull,0x3009090a20383130ull,
0x3030303030383078ull,0x3132346578302031ull,0x3178302030383738ull,0x2038313265303064ull,
0x3236363039627830ull,0x783009090a203831ull,0x3130323030303830ull,0x3831323465783020ull,
0x6431783020303837ull,0x3020383134653030ull,0x3134363630396278ull,0x30783009090a2038ull,
0x2031303430303038ull,0x3738313234657830ull,0x3064317830203038ull,0x7830203831366530ull,
0x3831363636303962ull,0x3830783009090a20ull,0x3020313036303030ull,0x3837383132346578ull,
0x3030643178302030ull,0x6278302038313865ull,0x2038313836363039ull,0x303830783009090aull,
0x7830203130383030ull,0x3038373831323465ull,0x6330306362783020ull,0x3030783020643161ull,
0x0a20303837633132ull,0x3030383078300909ull,0x6578302031306130ull,0x2030383763313234ull,
0x3031313030337830ull,0x3163657830203132ull,0x090a203238373030ull,0x3163373033783009ull,
0x6336783020646631ull,0x3020386337303130ull,0x3030633530303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x3064353030647830ull,0x3030327830203930ull,0x7830203038373030ull,
0x6331366530303931ull,0x6530303931783020ull,0x3009090a20303232ull,0x3138303030383178ull,
0x3030343478302039ull,0x6578302030383763ull,0x2064313236303039ull,0x3030386633307830ull,
0x783009090a203330ull,0x3132303630303965ull,0x3038663330783020ull,0x3965783020333030ull,
0x3020393134363030ull,0x3030303866333078ull,0x65783009090a2033ull,0x2064313836303039ull,
0x3030386633307830ull,0x3039657830203330ull,0x7830203132343630ull,0x3330303038663330ull,
0x3965783009090a20ull,0x3020393161363030ull,0x3030303866333078ull,0x3830306278302033ull,
0x3878302035326530ull,0x2030383730303030ull,0x303062783009090aull,0x7830203532633039ull,
0x3038373030303038ull,0x3130303039783020ull,0x3063783020343232ull,0x0a20383232313730ull,
0x3830306378300909ull,0x6378302063313231ull,0x2063323236613039ull,0x3636613039637830ull,
0x3030637830203033ull,0x090a203831633039ull,0x6361303863783009ull,0x3030783020313238ull,
0x3020303837303032ull,0x3230633730386578ull,0x3232303078302035ull,0x09090a2030383763ull,
0x3263373038657830ull,0x3230307830203932ull,0x7830203038373033ull,0x6431346337303865ull,
0x3032323030783020ull,0x3009090a20303837ull,0x3234633630386578ull,0x3232303078302031ull,
0x6578302030383734ull,0x2035323863363038ull,0x3738323230307830ull,0x783009090a203038ull,
0x3931616336303865ull,0x6331323030783020ull,0x3062783020303837ull,0x3020643130313930ull,
0x3837303030303878ull,0x62783009090a2030ull,0x2064316330373030ull,0x3730303030387830ull,
0x3030397830203038ull,0x7830206331653030ull,0x3432653039303063ull,0x3063783009090a20ull,
0x3020303265303830ull,0x3232363930396378ull,0x3930396378302038ull,0x6378302063323636ull,
0x2038316330373030ull,0x303863783009090aull,0x7830203133386339ull,0x3038373030323030ull,
0x6338303865783020ull,0x3030783020643130ull,0x0a20303837383232ull,0x3830386578300909ull,
0x3078302035323263ull,0x2030383763323230ull,0x3463383038657830ull,0x3230307830203932ull,
0x090a203038373033ull,0x6336303865783009ull,0x3030783020643134ull,0x3020303837633132ull,
0x3238633630386578ull,0x3232303078302031ull,0x09090a2030383734ull,0x6163363038657830ull,
0x3230307830203532ull,0x7830203038373832ull,0x3931653038303062ull,0x3030303038783020ull,
0x3009090a20303837ull,0x3163303930306278ull,0x3030303878302039ull,0x3978302030383730ull,
0x2038316330303030ull,0x6330383030637830ull,0x783009090a203032ull,0x6331633037303063ull,
0x3638303963783020ull,0x3963783020633232ull,0x3020383236363830ull,0x3163303930306378ull,
0x63783009090a2038ull,0x2031323863383038ull,0x3730303230307830ull,0x3038657830203038ull,
0x7830206432306337ull,0x3038376332323030ull,0x3865783009090a20ull,0x3020353232633730ull,
0x3837383232303078ull,0x3730386578302030ull,0x3078302064313463ull,0x2030383730323230ull,
0x303865783009090aull,0x7830203932346336ull,0x3038376332323030ull,0x6336303865783020ull,
0x3030783020313238ull,0x0a20303837343232ull,0x3630386578300909ull,0x3078302039316163ull,
0x2030383763313230ull,0x3031613030627830ull,0x3030387830206431ull,0x090a203038373030ull,
0x3037303062783009ull,0x3038783020643163ull,0x3020303837303030ull,0x3165303030303978ull,
0x3830306378302063ull,0x09090a2034326530ull,0x6530613030637830ull,0x3039637830203032ull,
0x7830203832323639ull,0x6332363639303963ull,0x3037303063783020ull,0x3009090a20383163ull,
0x3338633930386378ull,0x3032303078302031ull,0x6578302030383730ull,0x2064313063383038ull,
0x3738323230307830ull,0x783009090a203038ull,0x3532326338303865ull,0x6332323030783020ull,
0x3865783020303837ull,0x3020393234633830ull,0x3837303332303078ull,0x65783009090a2030ull,
0x2064313463363038ull,0x3763313230307830ull,0x3038657830203038ull,0x7830203132386336ull,
0x3038373432323030ull,0x3865783009090a20ull,0x3020353261633630ull,0x3837383232303078ull,
0x3830306278302030ull,0x3878302039316530ull,0x2030383730303030ull,0x303062783009090aull,
0x7830203931633039ull,0x3038373030303038ull,0x3030303039783020ull,0x3063783020383163ull,
0x0a20303263303830ull,0x3730306378300909ull,0x6378302063316330ull,0x2038323236383039ull,
0x3636383039637830ull,0x3030637830206332ull,0x090a203831633039ull,0x6338303863783009ull,
0x3030783020313338ull,0x3020303837303032ull,0x3230633730386578ull,0x3232303078302031ull,
0x09090a2030383738ull,0x3263373038657830ull,0x3230307830203532ull,0x7830203038376332ull,
0x3932346337303865ull,0x3033323030783020ull,0x3009090a20303837ull,0x3134633630386578ull,
0x3232303078302064ull,0x6578302030383730ull,0x2031323863363038ull,0x3734323230307830ull,
0x783009090a203038ull,0x3532616336303865ull,0x3832323030783020ull,0x3062783020303837ull,
0x3020393165303830ull,0x3837303030303878ull,0x62783009090a2030ull,0x2039316330393030ull,
0x3730303030387830ull,0x3030397830203038ull,0x7830203831633030ull,0x3032633038303063ull,
0x3063783009090a20ull,0x3020633163303730ull,0x3232363830396378ull,0x3830396378302063ull,
0x6378302038323636ull,0x2038316330393030ull,0x303863783009090aull,0x7830203132386338ull,
0x3038373030323030ull,0x6337303865783020ull,0x3030783020643230ull,0x0a20303837633232ull,
0x3730386578300909ull,0x3078302035323263ull,0x2030383738323230ull,0x3463373038657830ull,
0x3230307830206431ull,0x090a203038373032ull,0x6336303865783009ull,0x3030783020393234ull,
0x3020303837633232ull,0x3238633630386578ull,0x3232303078302031ull,0x09090a2030383734ull,
0x6163363038657830ull,0x3230307830203931ull,0x7830203038376331ull,0x6431303161303062ull,
0x3030303038783020ull,0x3009090a20303837ull,0x3163303730306278ull,0x3030303878302064ull,
0x3978302030383730ull,0x2063316530303030ull,0x6530383030637830ull,0x783009090a203432ull,
0x3032653061303063ull,0x3639303963783020ull,0x3963783020383232ull,0x3020633236363930ull,
0x3163303730306378ull,0x63783009090a2038ull,0x2031333863393038ull,0x3730303230307830ull,
0x3038657830203038ull,0x7830206431306338ull,0x3038373832323030ull,0x3865783009090a20ull,
0x3020353232633830ull,0x3837633232303078ull,0x3830386578302030ull,0x3078302039323463ull,
0x2030383730333230ull,0x303865783009090aull,0x7830206431346336ull,0x3038376331323030ull,
0x6336303865783020ull,0x3030783020313238ull,0x0a20303837343232ull,0x3630386578300909ull,
0x3078302035326163ull,0x2030383738323230ull,0x6530383030627830ull,0x3030387830203931ull,
0x090a203038373030ull,0x3039303062783009ull,0x3038783020393163ull,0x3020303837303030ull,
0x3163303030303978ull,0x3830306378302038ull,0x09090a2030326330ull,0x6330373030637830ull,
0x3030637830206331ull,0x7830203032383038ull,0x3931633039303063ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3136303730306578ull,0x3230303078302064ull,0x6578302030383730ull,
0x2039316130363030ull,0x3763313030307830ull,0x783009090a203038ull,0x3930306466303064ull,
0x3030303032783020ull,0x3430783020303837ull,0x3020313034663330ull,0x3837383132346578ull,
0x62783009090a2030ull,0x2031323263363038ull,0x3734303230367830ull,0x3038627830203038ull,
0x7830206431306336ull,0x3038373430323036ull,0x3862783009090a20ull,0x3020643236633630ull,
0x3837343032303678ull,0x3030306178302030ull,0x3278302035323031ull,0x2030383734313063ull,
0x303862783009090aull,0x7830203132616336ull,0x3038373430323036ull,0x6336303862783020ull,
0x3036783020393234ull,0x0a20303837343032ull,0x3030306178300909ull,0x3278302064323631ull,
0x2030383734313063ull,0x6530303030337830ull,0x3034307830203532ull,0x090a203038373432ull,
0x6336303862783009ull,0x3036783020643138ull,0x3020303837343032ull,0x3230313030306178ull,
0x3130633278302031ull,0x09090a2030383734ull,0x3439623030337830ull,0x3030337830203832ull,
0x7830206331653838ull,0x3032323961303032ull,0x3838303032783020ull,0x3009090a20633165ull,
0x3263633630386278ull,0x3032303678302031ull,0x3278302030383734ull,0x2064316530303430ull,
0x3730323034307830ull,0x783009090a203038ull,0x3132656336303862ull,0x3430323036783020ull,
0x3032783020303837ull,0x3020643165303034ull,0x3837303230343078ull,0x62783009090a2030ull,
0x2031323064363038ull,0x3734303230367830ull,0x3430327830203038ull,0x7830206431653030ull,
0x3038373032303430ull,0x3862783009090a20ull,0x3020313232643630ull,0x3837343032303678ull,
0x3034303278302030ull,0x3078302064316530ull,0x2030383730323034ull,0x303862783009090aull,
0x7830203132346436ull,0x3038373430323036ull,0x3030343032783020ull,0x3430783020643165ull,
0x0a20303837303230ull,0x3630386278300909ull,0x3678302031323664ull,0x2030383734303230ull,
0x6530303430327830ull,0x3034307830206431ull,0x090a203038373032ull,0x6436303862783009ull,
0x3036783020313238ull,0x3020303837343032ull,0x3165303034303278ull,0x3230343078302064ull,
0x09090a2030383730ull,0x6164363038627830ull,0x3230367830203132ull,0x7830203038373430ull,
0x6431653030343032ull,0x3032303430783020ull,0x3009090a20303837ull,0x3263643630386278ull,
0x3032303678302031ull,0x3278302030383734ull,0x2064316530303430ull,0x3730323034307830ull,
0x783009090a203038ull,0x3931656436303862ull,0x3430323036783020ull,0x3032783020303837ull,
0x3020393165303034ull,0x3837383130343078ull,0x31783009090a2030ull,0x2064313866303030ull,
0x3763333036307830ull,0x3034307830203038ull,0x7830203130346430ull,0x3038373831323465ull,
0x3033783009090a20ull,0x3020646666303030ull,0x6337383130633678ull,0x3031306178302038ull,
0x3078302033303032ull,0x2030303030303030ull,0x313031783009090aull,0x7830203330303230ull,
0x3038323030303030ull,0x3032303030783020ull,0x3063783020393065ull,0x0a20303837303030ull,
0x3330386478300909ull,0x3278302039303035ull,0x2030383730303030ull,0x3163363038337830ull,
0x3263367830206466ull,0x090a203863373431ull,0x3030303132783009ull,0x3430783020393163ull,
0x3020303035343134ull,0x3034643030343078ull,0x3132346578302031ull,0x09090a2030303538ull,
0x3030303030667830ull,0x3030657830203130ull,0x7830203230303030ull,0x6431653831303032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x6666303038303378ull,0x3134633678302064ull,
0x3178302038633734ull,0x2033303061663030ull,0x3230303030307830ull,0x783009090a203038ull,
0x3931633063343034ull,0x3030303030783020ull,0x3030783020333030ull,0x3020393063303030ull,
0x3837303030306378ull,0x30783009090a2030ull,0x2031303431303038ull,0x3763303234657830ull,
0x3038307830203038ull,0x7830203130363130ull,0x3038373031323465ull,0x3830783009090a20ull,
0x3020313038313030ull,0x3837343132346578ull,0x3030306678302030ull,0x6578302031303030ull,
0x2032303030303030ull,0x313638783009090aull,0x7830203330656666ull,0x3030303030303030ull,
0x3739313034783020ull,0x3030783020333030ull,0x0a20303030303030ull,0x3030303178300909ull,
0x3078302064323866ull,0x2030383763333034ull,0x3038663330317830ull,0x6637307830203131ull,
0x090a206666666637ull,0x3130303032783009ull,0x3430783020353136ull,0x3020303837303030ull,
0x6662303838303378ull,0x3134633678302064ull,0x09090a2038633730ull,0x3030303030357830ull,
0x3030307830203330ull,0x7830203038323030ull,0x6430613032303033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3038633030303278ull,0x3032343078302064ull,0x6478302030383763ull,
0x2064303630653030ull,0x3730306330387830ull,0x783009090a203038ull,0x3930613032303030ull,
0x3030303063783020ull,0x3033783020303837ull,0x3020646662303938ull,0x6337303134633678ull,
0x30783009090a2038ull,0x2031303462323038ull,0x3563303234657830ull,0x3030317830203030ull,
0x7830206431386630ull,0x3038376333303630ull,0x3031783009090a20ull,0x3020353130383832ull,
0x3030303030303078ull,0x3030303078302033ull,0x6378302039306130ull,0x2030383730303030ull,
0x303031783009090aull,0x7830203532386630ull,0x3038376333303430ull,0x6630303031783020ull,
0x3630783020393138ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302031323866ull,
0x2030383763333034ull,0x3866303030317830ull,0x3036307830203531ull,0x090a203038376333ull,
0x3037303033783009ull,0x3465783020393236ull,0x3020303837303030ull,0x3234316138306478ull,
0x3034343078302039ull,0x09090a2030383730ull,0x3431323030307830ull,0x3030637830206430ull,
0x7830203038373030ull,0x3932363030306331ull,0x6330303432783020ull,0x3009090a20303837ull,
0x3165383230303278ull,0x3030303078302064ull,0x6578302033303030ull,0x2035313263613061ull,
0x3734313230307830ull,0x783009090a203038ull,0x3132326361306165ull,0x3032323030783020ull,
0x6165783020303837ull,0x3020393132636130ull,0x3837383132303078ull,0x33783009090a2030ull,
0x2064666630623830ull,0x3734313463367830ull,0x3064327830203863ull,0x7830203532323130ull,
0x3038376332303430ull,0x3031783009090a20ull,0x3020333030303231ull,0x3832303030303078ull,
0x3830303378302030ull,0x6578302039323231ull,0x2030383730303163ull,0x383064783009090aull,
0x7830203133323131ull,0x3038373030343430ull,0x6431303064783020ull,0x3032783020393030ull,
0x0a20303837303030ull,0x3031303378300909ull,0x6578302064313231ull,0x2030383730303163ull,
0x3431313830647830ull,0x3434307830203932ull,0x090a203038373030ull,0x3130303061783009ull,
0x3434783020643338ull,0x3020303837343130ull,0x3230636338386578ull,0x3136383078302035ull,
0x09090a2030383734ull,0x6530303030617830ull,0x3034347830203134ull,0x7830203038373431ull,
0x6435343130303061ull,0x3431303434783020ull,0x3009090a20303837ull,0x3165316630306378ull,
0x3030303078302064ull,0x6578302030383730ull,0x2039323263633838ull,0x3730323638307830ull,
0x783009090a203038ull,0x3133653139303063ull,0x3030303030783020ull,0x3065783020303837ull,
0x3020643130323731ull,0x3837633130383078ull,0x63783009090a2030ull,0x2039336531613030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203133653235ull,0x3038373033303830ull,
0x3039783009090a20ull,0x3020353365303030ull,0x3837303030303078ull,0x3830306578302030ull,
0x3078302039336532ull,0x2030383738333038ull,0x303063783009090aull,0x7830206331613163ull,
0x3033613165303063ull,0x3030303061783020ull,0x3463783020643165ull,0x0a20303837343830ull,
0x3030306178300909ull,0x6378302031333831ull,0x2030383734383034ull,0x6530633730627830ull,
0x3030387830206431ull,0x090a203038373030ull,0x3163373062783009ull,0x3038783020313338ull,
0x3020303837303030ull,0x3365313530306378ull,0x3830306378302038ull,0x09090a2034346531ull,
0x6530303030637830ull,0x3134307830206431ull,0x7830203330303866ull,0x3133383130303063ull,
0x6337323430783020ull,0x3009090a20333030ull,0x3330323930306578ull,0x3330383078302039ull,
0x6578302030383738ull,0x2039343032613030ull,0x3734343038307830ull,0x783009090a203038ull,
0x3534653030303061ull,0x3430306363783020ull,0x3061783020303837ull,0x3020313538313030ull,
0x3837343030636378ull,0x63783009090a2030ull,0x2030336131653030ull,0x6131323130637830ull,
0x3030617830206334ull,0x7830206431323230ull,0x3038373436303438ull,0x3061783009090a20ull,
0x3020393338323030ull,0x3837343630343878ull,0x3030306178302030ull,0x6378302039343831ull,
0x2030383734383034ull,0x303061783009090aull,0x7830206434363230ull,0x3038373438303463ull,
0x3062303033783020ull,0x3463783020313365ull,0x0a20303837303031ull,0x3530303378300909ull,
0x6378302039336331ull,0x2030383730303134ull,0x3463633838657830ull,0x3638307830206431ull,
0x090a203038373831ull,0x3263373062783009ull,0x3038783020393434ull,0x3020303837303030ull,
0x3436326337306278ull,0x3030303878302064ull,0x09090a2030383730ull,0x3831653030647830ull,
0x3034307830203133ull,0x7830203038373430ull,0x3933653137303063ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3434323030306378ull,0x6631343078302039ull,0x6378302033303038ull,
0x2064343632303030ull,0x3063373234307830ull,0x783009090a203330ull,0x3535653136303063ull,
0x3030303030783020ull,0x3065783020303837ull,0x3020393365323630ull,0x3837383330383078ull,
0x61783009090a2030ull,0x2039343432303030ull,0x3734303063637830ull,0x3030617830203038ull,
0x7830206434363230ull,0x3038373430306363ull,0x3065783009090a20ull,0x3020353630323730ull,
0x3837343530383078ull,0x6530306378302030ull,0x3078302031366131ull,0x2030383730303030ull,
0x303061783009090aull,0x7830203535343230ull,0x3038373436303438ull,0x3230303061783020ull,
0x3438783020393536ull,0x0a20303837343630ull,0x3931306378300909ull,0x3078302039336131ull,
0x2030383730303030ull,0x3432313330637830ull,0x6433307830203934ull,0x090a203735333430ull,
0x3262303033783009ull,0x3463783020353361ull,0x3020303837303031ull,0x3563323530303378ull,
0x3031346378302035ull,0x09090a2030383730ull,0x3232313330637830ull,0x6433307830203534ull,
0x7830203735333430ull,0x3536343232313063ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3361313531306478ull,0x3030343078302035ull,0x6378302030383734ull,0x2038353232313130ull,
0x6532393130637830ull,0x783009090a203436ull,0x3535363239313063ull,0x3138633330783020ull,
0x3065783020333162ull,0x3020643430323631ull,0x3837343630303078ull,0x63783009090a2030ull,
0x2031353832393130ull,0x6231386333307830ull,0x3130637830203331ull,0x7830203436613235ull,
0x3835383234313063ull,0x3063783009090a20ull,0x3020353665323931ull,0x3837303030303078ull,
0x3631306578302030ull,0x3078302039353032ull,0x2030383734363030ull,0x303061783009090aull,
0x7830203933633130ull,0x3038373438303463ull,0x3163373062783020ull,0x3038783020393363ull,
0x0a20303837303030ull,0x3030306378300909ull,0x3078302039336331ull,0x2033303038663134ull,
0x6331303030617830ull,0x3063637830203933ull,0x090a203038373430ull,0x3131333063783009ull,
0x3330783020353663ull,0x3020373533343064ull,0x3632333931306378ull,0x6131306378302038ull,
0x09090a2038366532ull,0x3033303030617830ull,0x3034637830206435ull,0x7830203038373438ull,
0x6435653263373062ull,0x3030303038783020ull,0x3009090a20303837ull,0x3565323030306378ull,
0x6631343078302064ull,0x6178302033303038ull,0x2064356532303030ull,0x3734303063637830ull,
0x783009090a203038ull,0x3136653231333063ull,0x3430643330783020ull,0x3063783020373533ull,
0x3020643630333831ull,0x3837303030303078ull,0x65783009090a2030ull,0x2031343032623130ull,
0x3738363030307830ull,0x3130637830203038ull,0x7830203836613031ull,0x3431323232313063ull,
0x3065783009090a20ull,0x3020353165313530ull,0x3837383630383078ull,0x3431306378302030ull,
0x6378302034343031ull,0x2030323832353130ull,0x303065783009090aull,0x7830203132653138ull,
0x3038373434303830ull,0x3135313065783020ull,0x3430783020393234ull,0x0a20303837303230ull,
0x3831306378300909ull,0x6378302030326330ull,0x2038313033393130ull,0x3231323130657830ull,
0x3034307830203532ull,0x090a203038373431ull,0x3130303062783009ull,0x3030783020393234ull,
0x3020303837383230ull,0x3165313630306578ull,0x3230383078302035ull,0x09090a2030383730ull,
0x3231393030627830ull,0x3030627830203831ull,0x7830203032633261ull,0x3531653039313065ull,
0x3431303430783020ull,0x3009090a20303837ull,0x3136323630306278ull,0x3138306378302038ull,
0x6278302063313031ull,0x2035316130303030ull,0x3734313030307830ull,0x783009090a203038ull,
0x3931633030383065ull,0x6331303030783020ull,0x3062783020303837ull,0x3020353130323030ull,
0x3837343130303078ull,0x65783009090a2030ull,0x2035316130323830ull,0x3738313030307830ull,
0x3330637830203038ull,0x7830203531613039ull,0x3365383365643330ull,0x3061783009090a20ull,
0x3020643163313030ull,0x3837343630343878ull,0x3030306178302030ull,0x3878302039316532ull,
0x2030383734363034ull,0x303062783009090aull,0x7830206466623034ull,0x3863373430303036ull,
0x3137303064783020ull,0x3430783020643161ull,0x0a20303837343030ull,0x3630306478300909ull,
0x3078302039313831ull,0x2030383734303034ull,0x6331303030317830ull,0x3030307830203531ull,
0x090a203038366333ull,0x3130303031783009ull,0x3230783020313138ull,0x3020303836633330ull,
0x3036303030303178ull,0x3330343078302035ull,0x09090a2030383663ull,0x6130303030317830ull,
0x3036307830203131ull,0x7830203038366333ull,0x6432363930303032ull,0x3030303030783020ull,
0x3009090a20373030ull,0x6637316438303378ull,0x3134633678302064ull,0x3178302038633734ull,
0x2033303030313130ull,0x3230303030307830ull,0x783009090a203038ull,0x3330303030303035ull,
0x3030303030783020ull,0x3061783020303837ull,0x3020643061303030ull,0x3837303030343078ull,
0x61783009090a2030ull,0x2039303830303030ull,0x3730303034307830ull,0x3030337830203038ull,
0x7830206466373032ull,0x3863376330303436ull,0x3064783009090a20ull,0x3020353032306538ull,
0x3035383034343078ull,0x3030303178302030ull,0x3078302035313430ull,0x2030303563333034ull,
0x303031783009090aull,0x7830203930363030ull,0x3030356333303630ull,0x3030303031783020ull,
0x3430783020643061ull,0x0a20303035633330ull,0x3332303478300909ull,0x3078302033303030ull,
0x2030303030303030ull,0x3866303030317830ull,0x3036307830206432ull,0x090a203038376333ull,
0x3136303033783009ull,0x3463783020353136ull,0x3020303837303031ull,0x3161303030303278ull,
0x3030343078302035ull,0x09090a2030383730ull,0x6230393830337830ull,0x3463367830206466ull,
0x7830203863373031ull,0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3161386131303278ull,0x3030303078302039ull,0x3178302037313030ull,0x2035313038383230ull,
0x3030303030307830ull,0x783009090a203330ull,0x6430633032303030ull,0x3030303063783020ull,
0x3030783020303837ull,0x3020393061303030ull,0x3837303030306378ull,0x31783009090a2030ull,
0x2064313866303030ull,0x3763333034307830ull,0x3030317830203038ull,0x7830203532386630ull,
0x3038376333303630ull,0x3031783009090a20ull,0x3020393138663030ull,0x3837633330343078ull,
0x3030303178302030ull,0x3078302031323866ull,0x2030383763333036ull,0x303031783009090aull,
0x7830203531386630ull,0x3038376333303430ull,0x6337306333783020ull,0x3465783020393230ull,
0x0a20303837303032ull,0x6138306478300909ull,0x3078302039323431ull,0x2030383730303434ull,
0x3431323030307830ull,0x3030637830203131ull,0x090a203038373030ull,0x3030303031783009ull,
0x3432783020393265ull,0x3020343837633030ull,0x3165383230303278ull,0x3030303078302064ull,
0x09090a2033303030ull,0x3263613061657830ull,0x3230307830203531ull,0x7830203038373431ull,
0x3132326361306165ull,0x3032323030783020ull,0x3009090a20303837ull,0x3132636130616578ull,
0x3132303078302039ull,0x3378302030383738ull,0x2064666630623830ull,0x3734313463367830ull,
0x783009090a203863ull,0x3532323130303132ull,0x6333303430783020ull,0x3031783020343837ull,
0x3020333030646131ull,0x3832303030303078ull,0x33783009090a2030ull,0x2039323231383030ull,
0x3730303163657830ull,0x3830647830203038ull,0x7830203133323131ull,0x3038373030343430ull,
0x3064783009090a20ull,0x3020393030643130ull,0x3837303030303278ull,0x3031303378302030ull,
0x6578302064313231ull,0x2030383730303163ull,0x383064783009090aull,0x7830203932343131ull,
0x3038373030343430ull,0x3130303061783020ull,0x3434783020393338ull,0x0a20303837343130ull,
0x6638386578300909ull,0x3078302035323063ull,0x2030383734313638ull,0x6530303030617830ull,
0x3034347830206433ull,0x090a203038373431ull,0x3130303061783009ull,0x3434783020393534ull,
0x3020303837343130ull,0x3163316530306378ull,0x3030303078302064ull,0x09090a2030383730ull,
0x3263663838657830ull,0x3638307830203932ull,0x7830203038373032ull,0x3133633139303063ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3165313631306578ull,0x3130383078302064ull,
0x6378302030383763ull,0x2031346331613030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3133633235303065ull,0x3033303830783020ull,0x3039783020303837ull,0x3020353365303030ull,
0x3837303030303078ull,0x65783009090a2030ull,0x2031346332383030ull,0x3730343038307830ull,
0x3030637830203038ull,0x7830206331613163ull,0x3033613130313063ull,0x3061783009090a20ull,
0x3020643165303030ull,0x3837343830346378ull,0x3030306178302030ull,0x6378302031333831ull,
0x2030383734383034ull,0x373062783009090aull,0x7830206431653063ull,0x3038373030303038ull,
0x3163373062783020ull,0x3038783020313338ull,0x0a20303837303030ull,0x3530306378300909ull,
0x6378302030346331ull,0x2038346331383030ull,0x6530303030637830ull,0x3134307830206431ull,
0x090a203330303866ull,0x3130303063783009ull,0x3430783020313338ull,0x3020333030633732ull,
0x3465313930306578ull,0x3430383078302035ull,0x09090a2030383730ull,0x6531613030657830ull,
0x3038307830203934ull,0x7830203038373834ull,0x3134653030303061ull,0x3430306363783020ull,
0x3009090a20303837ull,0x3438313030306178ull,0x3030636378302064ull,0x6378302030383734ull,
0x2030336131313130ull,0x6131323130637830ull,0x783009090a203035ull,0x6431303230303061ull,
0x3436303438783020ull,0x3061783020303837ull,0x3020353436323030ull,0x3837343630343878ull,
0x61783009090a2030ull,0x2039343831303030ull,0x3734383034637830ull,0x3030617830203038ull,
0x7830203135383230ull,0x3038373438303463ull,0x3033783009090a20ull,0x3020313365306230ull,
0x3837303031346378ull,0x3530303378302030ull,0x6378302035343232ull,0x2030383730303134ull,
0x383865783009090aull,0x7830206431346366ull,0x3038373831363830ull,0x3263373062783020ull,
0x3038783020393434ull,0x0a20303837303030ull,0x6337306278300909ull,0x3878302031353832ull,
0x2030383730303030ull,0x3831313130647830ull,0x3034307830203133ull,0x090a203038373430ull,
0x3137303063783009ull,0x3030783020353463ull,0x3020303837303030ull,0x3434323030306378ull,
0x6631343078302039ull,0x09090a2033303038ull,0x3832303030637830ull,0x3234307830203535ull,
0x7830203330306337ull,0x6435633136303063ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3563323630306578ull,0x3430383078302031ull,0x6178302030383734ull,0x2035343432303030ull,
0x3734303063637830ull,0x783009090a203038ull,0x3934613230303061ull,0x3430306363783020ull,
0x3065783020303837ull,0x3020313665313730ull,0x3837633530383078ull,0x63783009090a2030ull,
0x2064356131343130ull,0x3730303030307830ull,0x3030617830203038ull,0x7830203135323230ull,
0x3038373436303438ull,0x3061783009090a20ull,0x3020353534323030ull,0x3837343630343878ull,
0x3831306378302030ull,0x3078302031366131ull,0x2030383730303030ull,0x333063783009090aull,
0x7830203534323231ull,0x3735333430643330ull,0x3262303033783020ull,0x3463783020353338ull,
0x0a20303837303031ull,0x3530303378300909ull,0x6378302031356132ull,0x2030383730303134ull,
0x3032313330637830ull,0x6433307830203134ull,0x090a203735333430ull,0x3231313063783009ull,
0x3030783020353632ull,0x3020303837303030ull,0x3361313431306478ull,0x3030343078302035ull,
0x09090a2030383734ull,0x3032303130637830ull,0x3130637830203435ull,0x7830203436633239ull,
0x3135343239313063ull,0x3138633330783020ull,0x3009090a20333162ull,0x3465313531306578ull,
0x3630303078302039ull,0x6378302030383734ull,0x2064343632393130ull,0x6231386333307830ull,
0x783009090a203331ull,0x3436383234313063ull,0x3233313063783020ull,0x3063783020343536ull,
0x3020353663323931ull,0x3837303030303078ull,0x65783009090a2030ull,0x2035356531353130ull,
0x3734363030307830ull,0x3030617830203038ull,0x7830203136303330ull,0x3038373438303463ull,
0x3062783009090a20ull,0x3020313630336337ull,0x3837303030303878ull,0x3030306378302030ull,
0x3078302031363033ull,0x2033303038663134ull,0x303061783009090aull,0x7830203136303330ull,
0x3038373430306363ull,0x3331333063783020ull,0x3330783020353630ull,0x0a20373533343064ull,
0x3931306378300909ull,0x6378302038363233ull,0x2038366332613130ull,0x6532303030617830ull,
0x3034637830203935ull,0x090a203038373438ull,0x3263373062783009ull,0x3038783020393563ull,
0x3020303837303030ull,0x3563323030306378ull,0x6631343078302039ull,0x09090a2033303038ull,
0x6332303030617830ull,0x3063637830203935ull,0x7830203038373430ull,0x6435633231333063ull,
0x3430643330783020ull,0x3009090a20373533ull,0x3665323731306378ull,0x3030303078302064ull,
0x6578302030383730ull,0x2064336531623130ull,0x3738363030307830ull,0x783009090a203038ull,
0x3836613030313063ull,0x3231313063783020ull,0x3065783020343130ull,0x3020353163313530ull,
0x3837383630383078ull,0x63783009090a2030ull,0x2030343031333130ull,0x3632343130637830ull,
0x3030657830203032ull,0x7830203132633138ull,0x3038373034303830ull,0x3065783009090a20ull,
0x3020393234313431ull,0x3837303230343078ull,0x3731306378302030ull,0x6378302030326330ull,
0x2038316532393130ull,0x313065783009090aull,0x7830203532323131ull,0x3038373431303430ull,
0x3130303062783020ull,0x3030783020393234ull,0x0a20303837383230ull,0x3630306578300909ull,
0x3078302035316331ull,0x2030383730323038ull,0x3231393030627830ull,0x3030627830203831ull,
0x090a203032613261ull,0x3039313065783009ull,0x3430783020353165ull,0x3020303837343130ull,
0x3134323630306278ull,0x3138306378302038ull,0x09090a2063313031ull,0x6130303030627830ull,
0x3030307830203531ull,0x7830203038373431ull,0x6431633030383065ull,0x6331303030783020ull,
0x3009090a20303837ull,0x3165313030306278ull,0x3130303078302035ull,0x6178302030383734ull,
0x2039313033303030ull,0x3734363034387830ull,0x783009090a203038ull,0x6431613032383065ull,
0x6331303030783020ull,0x3061783020303837ull,0x3020353163323030ull,0x3837343630343878ull,
0x64783009090a2030ull,0x2039316131363030ull,0x3734303034307830ull,0x3030637830203038ull,
0x7830206431653030ull,0x3330303038653330ull,0x3064783009090a20ull,0x3020353138313530ull,
0x3837343030343078ull,0x3430306278302030ull,0x3678302064666630ull,0x2038633734303030ull,
0x323061783009090aull,0x7830203330306232ull,0x3030303030303030ull,0x3130303061783020ull,
0x3430783020353134ull,0x0a20303837303030ull,0x3030306178300909ull,0x3078302039313831ull,
0x2030383730303034ull,0x3062323230317830ull,0x3030307830203330ull,0x090a203030313030ull,
0x3036303033783009ull,0x3436783020646662ull,0x3020386337633030ull,0x3030653030643178ull,
0x3230303178302034ull,0x09090a2038306138ull,0x6338303030317830ull,0x3030317830206330ull,
0x7830203031653832ull,0x3330306232323031ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3030303030633178ull,0x3030343478302035ull,0x6478302030383763ull,0x2035303030313030ull,
0x3763323034307830ull,0x783009090a203038ull,0x3530323031303033ull,0x3030313465783020ull,
0x3064783020303837ull,0x3020353032306538ull,0x3837303034343078ull,0x64783009090a2030ull,
0x2035303063313063ull,0x3738303234307830ull,0x3030317830203038ull,0x7830203431343830ull,
0x3830363832303031ull,0x3031783009090a20ull,0x3020643061303030ull,0x3837633330343078ull,
0x3030306678302030ull,0x6578302031303030ull,0x2032303030303030ull,0x303032783009090aull,
0x7830206432363931ull,0x3330303030303030ull,0x3161383033783020ull,0x6336783020646637ull,
0x0a20386337343134ull,0x6131303178300909ull,0x3078302033303030ull,0x2030383230303030ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x6630303430783009ull,
0x3465783020313034ull,0x3020303837303132ull,0x3030643830346478ull,0x3030303278302039ull,
0x09090a2030383730ull,0x3064333034647830ull,0x3030327830206430ull,0x7830203038373030ull,
0x3130343332303430ull,0x3030323465783020ull,0x3009090a20303837ull,0x3065666631363878ull,
0x3030303078302033ull,0x3378302030303030ull,0x2064663130303930ull,0x3730313463367830ull,
0x783009090a203863ull,0x3330303136323061ull,0x3030303030783020ull,0x3031783020303030ull,
0x3020333030313632ull,0x3832303030303078ull,0x64783009090a2030ull,0x2035303030313063ull,
0x3730303030327830ull,0x3034317830203038ull,0x7830203131303030ull,0x3038376330303434ull,
0x6362783009090a20ull,0x3020646631633430ull,0x6337303132303678ull,0x3432306178302038ull,
0x3078302033303034ull,0x2030303030303030ull,0x306331783009090aull,0x7830203131303030ull,
0x3038376330303434ull,0x3434323031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3130636478300909ull,0x3278302035303030ull,0x2030383730303030ull,0x3065303035317830ull,
0x3035317830203031ull,0x090a203431306530ull,0x3030306330783009ull,0x3465783020313030ull,
0x3020303837343132ull,0x3030303130386478ull,0x3030303278302035ull,0x09090a2030383730ull,
0x3030303034317830ull,0x3034347830203531ull,0x7830203038376330ull,0x3130303030303830ull,
0x3431323465783020ull,0x3009090a20303837ull,0x6631653430636278ull,0x3032303678302064ull,
0x3178302061633734ull,0x2031313032303063ull,0x3663303034347830ull,0x783009090a203038ull,
0x3531303230306331ull,0x6330303434783020ull,0x6330783020303836ull,0x3020313030303030ull,
0x3836343132346578ull,0x31783009090a2030ull,0x2035313032303038ull,0x3663303034347830ull,
0x3038307830203038ull,0x7830203130303030ull,0x3038363431323465ull,0x6362783009090a20ull,
0x3020646631643430ull,0x6337343032303678ull,0x3030633178302038ull,0x3478302031313031ull,
0x2030383663303034ull,0x306331783009090aull,0x7830203531303130ull,0x3038366330303434ull,
0x3030306330783020ull,0x3465783020313030ull,0x0a20303836343132ull,0x3030383178300909ull,
0x3478302035313031ull,0x2030383663303034ull,0x3030303038307830ull,0x3234657830203130ull,
0x090a203038363431ull,0x6334306362783009ull,0x3036783020646639ull,0x3020386337343032ull,
0x3138303030633178ull,0x3030343478302031ull,0x09090a2030383663ull,0x3830303063317830ull,
0x3034347830203531ull,0x7830203038366330ull,0x3130303030306330ull,0x3431323465783020ull,
0x3009090a20303836ull,0x3138303030383178ull,0x3030343478302035ull,0x3078302030383663ull,
0x2031303030303038ull,0x3634313234657830ull,0x783009090a203038ull,0x6466356334306362ull,
0x3430323036783020ull,0x6331783020386337ull,0x3020313134303030ull,0x3836633030343478ull,
0x31783009090a2030ull,0x2035313430303063ull,0x3663303034347830ull,0x3063307830203038ull,
0x7830203130303030ull,0x3038363431323465ull,0x3831783009090a20ull,0x3020353134303030ull,
0x3836633030343478ull,0x3030383078302030ull,0x6578302031303030ull,0x2030383634313234ull,
0x306362783009090aull,0x7830206466336334ull,0x3863373430323036ull,0x3030306331783020ull,
0x3434783020313132ull,0x0a20303837633030ull,0x3030633078300909ull,0x6578302031303030ull,
0x2030383630313234ull,0x3230303038317830ull,0x3034347830203131ull,0x090a203038366330ull,
0x3030303830783009ull,0x3465783020313030ull,0x3020303836303132ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x6566663136387830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3530306438303064ull,0x3030303032783020ull,0x3009090a20303837ull,
0x3130303030343178ull,0x3030343478302031ull,0x3878302030383763ull,0x2033306566663136ull,
0x3030303030307830ull,0x783009090a203030ull,0x6466393030303033ull,0x3431306336783020ull,
0x3033783020386337ull,0x3020333030303030ull,0x3832303030303078ull,0x33783009090a2030ull,
0x2031303630323030ull,0x3738303034367830ull,0x3030647830203038ull,0x7830203530303533ull,
0x3038373030303032ull,0x3064783009090a20ull,0x3020313032303030ull,0x3837303230343078ull,
0x3130343378302030ull,0x6378302031313263ull,0x2030383730303334ull,0x303433783009090aull,
0x7830203531346331ull,0x3038373030333463ull,0x6331303433783020ull,0x3463783020393136ull,
0x0a20303837303033ull,0x3130343378300909ull,0x6378302035303063ull,0x2030383730303334ull,
0x3030343030337830ull,0x3034657830203131ull,0x090a203038373030ull,0x3035303033783009ull,
0x3465783020353130ull,0x3020303837303030ull,0x3130303630303378ull,0x3030346578302039ull,
0x09090a2030383730ull,0x3030313030337830ull,0x3034657830203530ull,0x7830203038373030ull,
0x3131383061383064ull,0x3030343430783020ull,0x3009090a20303837ull,0x3161306138306478ull,
0x3034343078302035ull,0x6478302030383730ull,0x2039316330613830ull,0x3730303434307830ull,
0x783009090a203038ull,0x3530323061383064ull,0x3030343430783020ull,0x3033783020303837ull,
0x3020313138303230ull,0x3837303031346378ull,0x33783009090a2030ull,0x2035316130343030ull,
0x3730303134637830ull,0x3030337830203038ull,0x7830203931633036ull,0x3038373030313463ull,
0x3064783009090a20ull,0x3020353032303430ull,0x3837343030343078ull,0x3630306478302030ull,
0x3078302031316130ull,0x2030383734303034ull,0x303433783009090aull,0x7830203531386331ull,
0x3038373030333463ull,0x6331303433783020ull,0x3463783020393161ull,0x0a20303837303033ull,
0x3430306478300909ull,0x3078302035303230ull,0x2030383734303034ull,0x3030353030337830ull,
0x3034657830203131ull,0x090a203038373030ull,0x3036303033783009ull,0x3465783020353130ull,
0x3020303837303030ull,0x3163633130343378ull,0x3033346378302039ull,0x09090a2030383730ull,
0x6563313034337830ull,0x3334637830206431ull,0x7830203038373030ull,0x3131383061383064ull,
0x3030343430783020ull,0x3009090a20303837ull,0x3161306138306478ull,0x3034343078302035ull,
0x3378302030383730ull,0x2039313030363030ull,0x3730303034657830ull,0x783009090a203038ull,
0x6431303037303033ull,0x3030303465783020ull,0x3033783020303837ull,0x3020313138303830ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2035316130613030ull,0x3730303134637830ull,
0x3830647830203038ull,0x7830203931633061ull,0x3038373030343430ull,0x3064783009090a20ull,
0x3020643165306138ull,0x3837303034343078ull,0x3130343378302030ull,0x6378302031323064ull,
0x2030383730303334ull,0x303064783009090aull,0x7830203131383035ull,0x3038373430303430ull,
0x3063303033783020ull,0x3463783020353163ull,0x0a20303837303031ull,0x6530303378300909ull,
0x6378302039316530ull,0x2030383730303134ull,0x3030383030337830ull,0x3034657830206431ull,
0x090a203038373030ull,0x6431303433783009ull,0x3463783020313232ull,0x3020303837303033ull,
0x3032303430306478ull,0x3030343078302035ull,0x09090a2030383734ull,0x6130363030647830ull,
0x3034307830203131ull,0x7830203038373430ull,0x3531653061383064ull,0x3030343430783020ull,
0x3009090a20303837ull,0x3130303830303378ull,0x3030346578302039ull,0x3378302030383730ull,
0x2064313464313034ull,0x3730303334637830ull,0x783009090a203038ull,0x3530323034303064ull,
0x3430303430783020ull,0x3033783020303837ull,0x3020313161303031ull,0x3837303031346378ull,
0x64783009090a2030ull,0x2035316330613830ull,0x3730303434307830ull,0x3030337830203038ull,
0x7830203931303037ull,0x3038373030303465ull,0x3433783009090a20ull,0x3020643136643130ull,
0x3837303033346378ull,0x3430306478302030ull,0x3078302035303230ull,0x2030383734303034ull,
0x313033783009090aull,0x7830203131613032ull,0x3038373030313463ull,0x3061383064783020ull,
0x3430783020353163ull,0x0a20303837303034ull,0x3730303378300909ull,0x6578302039313030ull,
0x2030383730303034ull,0x3864313034337830ull,0x3334637830206431ull,0x090a203038373030ull,
0x3034303064783009ull,0x3430783020353032ull,0x3020303837343030ull,0x3161303431303378ull,
0x3031346378302031ull,0x09090a2030383730ull,0x6330613830647830ull,0x3434307830203531ull,
0x7830203038373030ull,0x3931303037303033ull,0x3030303465783020ull,0x3009090a20303837ull,
0x3161643130343378ull,0x3033346378302064ull,0x6478302030383730ull,0x2035303230343030ull,
0x3734303034307830ull,0x783009090a203038ull,0x3131613036313033ull,0x3030313463783020ull,
0x3064783020303837ull,0x3020353163306138ull,0x3837303034343078ull,0x33783009090a2030ull,
0x2039313030373030ull,0x3730303034657830ull,0x3034337830203038ull,0x7830206431636431ull,
0x3038373030333463ull,0x3064783009090a20ull,0x3020353032303430ull,0x3837343030343078ull,
0x3831303378302030ull,0x6378302031316130ull,0x2030383730303134ull,0x383064783009090aull,
0x7830203531633061ull,0x3038373030343430ull,0x3037303033783020ull,0x3465783020393130ull,
0x0a20303837303030ull,0x3430306478300909ull,0x3078302035303230ull,0x2030383734303034ull,
0x6130613130337830ull,0x3134637830203131ull,0x090a203038373030ull,0x3061383064783009ull,
0x3430783020353163ull,0x3020303837303034ull,0x3165643130343378ull,0x3033346378302039ull,
0x09090a2030383730ull,0x3230343030647830ull,0x3034307830203530ull,0x7830203038373430ull,
0x3131613063313033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3130303630303378ull,
0x3030346578302035ull,0x6178302030383730ull,0x2031306334303030ull,0x3730303234307830ull,
0x783009090a203038ull,0x3131323034303064ull,0x3430303430783020ull,0x3033783020303837ull,
0x3020353036303031ull,0x3837303031346378ull,0x33783009090a2030ull,0x2035316130653130ull,
0x3730303134637830ull,0x3030337830203038ull,0x7830206430303033ull,0x3038373030313463ull,
0x3064783009090a20ull,0x3020313034303130ull,0x3837343030343078ull,0x3530306478302030ull,
0x3078302035303830ull,0x2030383734303034ull,0x303032783009090aull,0x7830203930306430ull,
0x3038376330323430ull,0x3065303064783020ull,0x3061783020313034ull,0x0a20313837303038ull,
0x0000000a7d0a7d09ull
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
0x6d742f706d742f20ull,0x3030305f74667870ull,0x30305f6231343630ull,0x312d303030303030ull,
0x632e637478645f30ull,0x2f2820692e337070ull,0x494263632f706d74ull,0x584e36526a792e23ull,
0x2d2d2d2f2f090a29ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2f2f090a0aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x74704f202f2f090aull,0x2f090a3a736e6f69ull,0x2d2d2d2d2d2d2d2full,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2f2f090a2d2d2d2dull,0x7465677261542020ull,0x5349202c7874703aull,
0x2c33315f6d733a41ull,0x3a6e6169646e4520ull,0x202c656c7474696cull,0x207265746e696f50ull,
0x0a34363a657a6953ull,0x334f2d20202f2f09ull,0x696d6974704f2809ull,0x6c206e6f6974617aull,
0x2f090a296c657665ull,0x280930672d20202full,0x656c206775626544ull,0x2f2f090a296c6576ull,
0x522809326d2d2020ull,0x64612074726f7065ull,0x736569726f736976ull,0x2d2d2d2f2f090a29ull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x656c69662e090a0aull,
0x6d6f633c22093109ull,0x6e696c2d646e616dull,0x69662e090a223e65ull,0x742f22093209656cull,
0x6678706d742f706dull,0x3436303030305f74ull,0x30303030305f6231ull,0x78645f392d303030ull,
0x66616475632e6374ull,0x0a227570672e3265ull,0x3309656c69662e09ull,0x6c2f7273752f2209ull,
0x782f6363672f6269ull,0x696c2d34365f3638ull,0x2f756e672d78756eull,0x6e692f312e342e34ull,
0x74732f6564756c63ull,0x0a22682e66656464ull,0x3409656c69662e09ull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x7665642f7472632full,
0x746e75725f656369ull,0x090a22682e656d69ull,0x093509656c69662eull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x6665645f74736f68ull,
0x0a22682e73656e69ull,0x3609656c69662e09ull,0x6c2f7273752f2209ull,0x6475632f6c61636full,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x6e69746c6975622full,0x682e73657079745full,
0x656c69662e090a22ull,0x7273752f22093709ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x63697665642f6564ull,0x2e73657079745f65ull,0x6c69662e090a2268ull,
0x73752f2209380965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x766972642f656475ull,0x73657079745f7265ull,0x69662e090a22682eull,0x752f22093909656cull,
0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x7865742f6564756cull,
0x7079745f65727574ull,0x2e090a22682e7365ull,0x09303109656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x745f726f74636576ull,
0x0a22682e73657079ull,0x3109656c69662e09ull,0x2f7273752f220931ull,0x75632f6c61636f6cull,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x6563697665642f65ull,0x5f68636e75616c5full,
0x6574656d61726170ull,0x2e090a22682e7372ull,0x09323109656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x726f74732f747263ull,
0x73616c635f656761ull,0x662e090a22682e73ull,0x2209333109656c69ull,0x636e692f7273752full,
0x7469622f6564756cull,0x2e73657079742f73ull,0x6c69662e090a2268ull,0x752f220934310965ull,
0x756c636e692f7273ull,0x2e656d69742f6564ull,0x6c69662e090a2268ull,0x7543220935310965ull,
0x682e6874614d6164ull,0x656c69662e090a22ull,0x7478642209363109ull,0x2e090a2275632e63ull,
0x09373109656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x665f6e6f6d6d6f63ull,0x736e6f6974636e75ull,0x69662e090a22682eull,
0x2f2209383109656cull,0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x72632f6564756c63ull,0x6d5f636e75662f74ull,0x0a22682e6f726361ull,0x3109656c69662e09ull,
0x2f7273752f220939ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x665f6874616d2f65ull,0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209303209656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,
0x6e75665f65636976ull,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209313209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6874616d2f656475ull,
0x6e6174736e6f635full,0x2e090a22682e7374ull,0x09323209656c6966ull,0x6f6c2f7273752f22ull,
0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x74615f31315f6d73ull,
0x6e75665f63696d6full,0x682e736e6f697463ull,0x656c69662e090a22ull,0x73752f2209333209ull,
0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x315f6d732f656475ull,
0x63696d6f74615f32ull,0x6f6974636e75665full,0x2e090a22682e736eull,0x09343209656c6966ull,
0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,
0x6f645f33315f6d73ull,0x6e75665f656c6275ull,0x682e736e6f697463ull,0x656c69662e090a22ull,
0x73752f2209353209ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x747865742f656475ull,0x637465665f657275ull,0x6974636e75665f68ull,0x090a22682e736e6full,
0x363209656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x75665f6874616d2full,0x5f736e6f6974636eull,0x337874705f6c6264ull,
0x732e090a0a22682eull,0x612e206465726168ull,0x2e2034206e67696cull,0x7261766f63203862ull,
0x305f5f65636e6169ull,0x090a3b5d3438335bull,0x206465726168732eull,0x34206e67696c612eull,
0x646e692038622e20ull,0x5b315f5f73656369ull,0x2e090a3b5d363532ull,0x2e20646572616873ull,
0x2034206e67696c61ull,0x65705f732038622eull,0x6f69746174756d72ull,0x34365b325f5f736eull,
0x68732e090a3b5d30ull,0x6c612e2064657261ull,0x622e2034206e6769ull,0x335f5f7370642038ull,
0x2e090a3b5d34365bull,0x612e2074736e6f63ull,0x2e2034206e67696cull,0x6f6c6f436b203862ull,
0x5b63697274654d72ull,0x307b203d205d3231ull,0x362c3832312c302cull,0x32312c302c302c33ull,
0x302c302c33362c38ull,0x7d33362c3832312cull,0x736e6f632e090a3bull,0x6e67696c612e2074ull,
0x612038622e203420ull,0x6c6261546168706cull,0x3d205d36315b3465ull,0x36312c302c307b20ull,
0x2c302c302c35362cull,0x2c302c302c302c30ull,0x302c34362c323931ull,0x34362c34362c302cull,
0x6e6f632e090a3b7dull,0x67696c612e207473ull,0x2038622e2034206eull,0x6261546168706c61ull,
0x205d36315b33656cull,0x312c302c307b203dull,0x2c302c34362c3832ull,0x2c302c302c302c30ull,
0x302c34362c302c30ull,0x7d34362c302c302cull,0x736e6f632e090a3bull,0x6e67696c612e2074ull,
0x702038622e203420ull,0x36315b3473646f72ull,0x302c307b203d205dull,0x392c302c302c392cull,
0x312c322c302c302cull,0x342c322c302c342cull,0x090a3b7d302c312cull,0x2e2074736e6f632eull,
0x2034206e67696c61ull,0x646f72702038622eull,0x3d205d36315b3373ull,0x2c342c302c307b20ull,
0x2c302c342c302c30ull,0x2c342c312c312c30ull,0x2c312c342c312c30ull,0x652e090a0a3b7d30ull,
0x385a5f207972746eull,0x73736572706d6f63ull,0x35505f30536a4b50ull,0x0a282032746e6975ull,
0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x706d6f63385a5f5full,
0x536a4b5073736572ull,0x746e697535505f30ull,0x74756d7265705f32ull,0x0a2c736e6f697461ull,
0x6d617261702e0909ull,0x5f5f203436752e20ull,0x6d72617061647563ull,0x706d6f63385a5f5full,
0x536a4b5073736572ull,0x746e697535505f30ull,0x2c6567616d695f32ull,0x617261702e09090aull,
0x5f203436752e206dull,0x726170616475635full,0x6d6f63385a5f5f6dull,0x6a4b507373657270ull,
0x6e697535505f3053ull,0x6c757365725f3274ull,0x2e090a7b090a2974ull,0x3631752e20676572ull,
0x3b3e353c68722520ull,0x2e206765722e090aull,0x323c722520323375ull,0x722e090a3b3e3733ull,
0x203436752e206765ull,0x3b3e33373c647225ull,0x2e206765722e090aull,0x343c662520323366ull,
0x722e090a3b3e3735ull,0x646572702e206765ull,0x3b3e38323c702520ull,0x65726168732e090aull,
0x6e67696c612e2064ull,0x5f2038622e203420ull,0x6f635f616475635full,0x3836333173726f6cull,
0x090a3b5d3239315bull,0x206465726168732eull,0x34206e67696c612eull,0x635f5f2038622e20ull,
0x736d75735f616475ull,0x3239315b30363531ull,0x6168732e090a3b5dull,0x696c612e20646572ull,
0x38622e2034206e67ull,0x5f616475635f5f20ull,0x3537317366657278ull,0x090a3b5d34365b32ull,
0x206465726168732eull,0x34206e67696c612eull,0x635f5f2038622e20ull,0x6f7272655f616475ull,
0x325b363138317372ull,0x6c2e090a3b5d3635ull,0x303509363109636full,0x42424c240a300938ull,
0x6d6f63385a5f5f31ull,0x6a4b507373657270ull,0x6e697535505f3053ull,0x6f6c2e090a3a3274ull,
0x3631350936310963ull,0x2e747663090a3009ull,0x203631752e323373ull,0x7425202c31722509ull,
0x63090a3b782e6469ull,0x732e3436752e7476ull,0x3164722509203233ull,0x090a3b317225202cull,
0x752e6f6c2e6c756dull,0x3264722509203436ull,0x202c31647225202cull,0x2e766f6d090a3b34ull,
0x3272250920323375ull,0x73090a3b3531202cull,0x732e74672e707465ull,0x2c31702509203233ull,
0x7225202c31722520ull,0x31702540090a3b32ull,0x4c24092061726220ull,0x393337325f305f74ull,
0x636f6c2e090a3b34ull,0x0938343109363109ull,0x752e766f6d090a30ull,0x3364722509203436ull,
0x616475635f5f202cull,0x3173726f6c6f635full,0x6f6d090a3b383633ull,0x2509203436752e76ull,
0x635f5f202c346472ull,0x736d75735f616475ull,0x6d090a3b30363531ull,0x09203436752e766full,
0x6f63202c35647225ull,0x65636e6169726176ull,0x646c090a3b305f5full,0x752e6d617261702eull,
0x3664722509203436ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x736572706d6f6338ull,
0x505f30536a4b5073ull,0x695f32746e697535ull,0x090a3b5d6567616dull,0x2e3233732e747663ull,
0x3372250920363175ull,0x646961746325202cull,0x747663090a3b782eull,0x3233752e3631752eull,
0x202c316872250920ull,0x756d090a3b337225ull,0x752e656469772e6cull,0x2c34722509203631ull,
0x31202c3168722520ull,0x2e646461090a3b36ull,0x3572250920323373ull,0x25202c317225202cull,
0x747663090a3b3472ull,0x3233732e3436732eull,0x202c376472250920ull,0x756d090a3b357225ull,
0x3436752e6f6c2e6cull,0x202c386472250920ull,0x3b34202c37647225ull,0x36752e646461090aull,
0x2c39647225092034ull,0x25202c3664722520ull,0x646c090a3b386472ull,0x2e6c61626f6c672eull,
0x3672250920323375ull,0x2b396472255b202cull,0x6f6c2e090a3b5d30ull,0x3035310936310963ull,
0x2e646e61090a3009ull,0x3772250920323362ull,0x32202c367225202cull,0x6c756d090a3b3535ull,
0x203436752e6f6c2eull,0x202c303164722509ull,0x3231202c31647225ull,0x722e747663090a3bull,
0x33752e3233662e6eull,0x202c316625092032ull,0x6461090a3b377225ull,0x2509203436752e64ull,
0x7225202c31316472ull,0x647225202c303164ull,0x2e766f6d090a3b33ull,0x3266250920323366ull,
0x303862336630202cull,0x2020203b31383038ull,0x2e30202f2f092020ull,0x3735313239333030ull,
0x33662e6c756d090aull,0x202c336625092032ull,0x326625202c316625ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x31316472255b0920ull,0x336625202c5d302bull,0x09636f6c2e090a3bull,
0x3009313531093631ull,0x33622e6c6873090aull,0x202c387225092032ull,0x3b3631202c367225ull,
0x33752e726873090aull,0x202c397225092032ull,0x3b3432202c387225ull,0x6e722e747663090aull,
0x3233752e3233662eull,0x25202c3466250920ull,0x766f6d090a3b3972ull,0x662509203233662eull,
0x3862336630202c35ull,0x20203b3138303830ull,0x30202f2f09202020ull,0x353132393330302eull,
0x662e6c756d090a37ull,0x2c36662509203233ull,0x6625202c34662520ull,0x732e7473090a3b35ull,
0x33662e6465726168ull,0x316472255b092032ull,0x6625202c5d342b31ull,0x636f6c2e090a3b36ull,
0x0932353109363109ull,0x622e6c6873090a30ull,0x3031722509203233ull,0x38202c367225202cull,
0x752e726873090a3bull,0x3131722509203233ull,0x202c30317225202cull,0x747663090a3b3432ull,
0x2e3233662e6e722eull,0x3766250920323375ull,0x0a3b31317225202cull,0x3233662e766f6d09ull,
0x30202c3866250920ull,0x3830383038623366ull,0x0920202020203b31ull,0x3330302e30202f2full,
0x6d090a3735313239ull,0x09203233662e6c75ull,0x376625202c396625ull,0x090a3b386625202cull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x5d382b3131647225ull,0x090a3b396625202cull,
0x09363109636f6c2eull,0x61090a3009303631ull,0x09203436752e6464ull,0x25202c3231647225ull,
0x7225202c30316472ull,0x2e7473090a3b3464ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d302b3231ull,0x2e7473090a3b3366ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d342b3231ull,0x2e7473090a3b3666ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d382b3231ull,0x726f78090a3b3966ull,0x722509203233622eull,0x2c317225202c3231ull,
0x747663090a3b3820ull,0x3233732e3436732eull,0x2c33316472250920ull,0x090a3b3231722520ull,
0x752e6f6c2e6c756dull,0x3164722509203436ull,0x3331647225202c34ull,0x61090a3b3231202cull,
0x09203436752e6464ull,0x25202c3531647225ull,0x647225202c346472ull,0x2e646c090a3b3431ull,
0x662e646572616873ull,0x3031662509203233ull,0x35316472255b202cull,0x646c090a3b5d302bull,
0x2e6465726168732eull,0x3166250920323366ull,0x316472255b202c31ull,0x6c090a3b5d342b35ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3231ull,0x090a3b5d382b3531ull,
0x203233662e646461ull,0x25202c3331662509ull,0x30316625202c3366ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x32316472255b0920ull,0x316625202c5d302bull,0x2e646461090a3b33ull,
0x3166250920323366ull,0x202c366625202c34ull,0x73090a3b31316625ull,0x6465726168732e74ull,
0x255b09203233662eull,0x2c5d342b32316472ull,0x090a3b3431662520ull,0x203233662e646461ull,
0x25202c3531662509ull,0x32316625202c3966ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x32316472255b0920ull,0x316625202c5d382bull,0x2e726f78090a3b35ull,0x3172250920323362ull,
0x202c317225202c33ull,0x2e747663090a3b34ull,0x203233732e343673ull,0x202c363164722509ull,
0x6d090a3b33317225ull,0x36752e6f6c2e6c75ull,0x3731647225092034ull,0x2c3631647225202cull,
0x6461090a3b323120ull,0x2509203436752e64ull,0x7225202c38316472ull,0x31647225202c3464ull,
0x732e646c090a3b37ull,0x33662e6465726168ull,0x2c36316625092032ull,0x2b38316472255b20ull,
0x2e646c090a3b5d30ull,0x662e646572616873ull,0x3731662509203233ull,0x38316472255b202cull,
0x646c090a3b5d342bull,0x2e6465726168732eull,0x3166250920323366ull,0x316472255b202c38ull,
0x61090a3b5d382b38ull,0x09203233662e6464ull,0x6625202c39316625ull,0x36316625202c3331ull,
0x68732e7473090a3bull,0x3233662e64657261ull,0x32316472255b0920ull,0x316625202c5d302bull,
0x2e646461090a3b39ull,0x3266250920323366ull,0x2c34316625202c30ull,0x090a3b3731662520ull,
0x65726168732e7473ull,0x5b09203233662e64ull,0x5d342b3231647225ull,0x0a3b30326625202cull,
0x3233662e64646109ull,0x202c313266250920ull,0x6625202c35316625ull,0x2e7473090a3b3831ull,
0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d382b3231ull,0x6f78090a3b313266ull,
0x2509203233622e72ull,0x317225202c343172ull,0x7663090a3b32202cull,0x33732e3436732e74ull,
0x3931647225092032ull,0x0a3b34317225202cull,0x2e6f6c2e6c756d09ull,0x6472250920343675ull,
0x31647225202c3032ull,0x090a3b3231202c39ull,0x203436752e646461ull,0x202c313264722509ull,
0x7225202c34647225ull,0x646c090a3b303264ull,0x2e6465726168732eull,0x3266250920323366ull,
0x326472255b202c32ull,0x6c090a3b5d302b31ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3332ull,0x090a3b5d342b3132ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c343266ull,0x0a3b5d382b313264ull,0x3233662e64646109ull,0x202c353266250920ull,
0x6625202c39316625ull,0x2e7473090a3b3232ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d302b3231ull,0x6461090a3b353266ull,0x2509203233662e64ull,0x326625202c363266ull,
0x3b33326625202c30ull,0x6168732e7473090aull,0x203233662e646572ull,0x2b32316472255b09ull,
0x36326625202c5d34ull,0x662e646461090a3bull,0x3732662509203233ull,0x202c31326625202cull,
0x73090a3b34326625ull,0x6465726168732e74ull,0x255b09203233662eull,0x2c5d382b32316472ull,
0x090a3b3732662520ull,0x203233622e726f78ull,0x25202c3531722509ull,0x090a3b31202c3172ull,
0x2e3436732e747663ull,0x6472250920323373ull,0x35317225202c3232ull,0x6c2e6c756d090a3bull,
0x2509203436752e6full,0x7225202c33326472ull,0x3b3231202c323264ull,0x36752e646461090aull,
0x3432647225092034ull,0x202c34647225202cull,0x090a3b3332647225ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c383266ull,0x0a3b5d302b343264ull,0x726168732e646c09ull,
0x09203233662e6465ull,0x255b202c39326625ull,0x3b5d342b34326472ull,0x6168732e646c090aull,
0x203233662e646572ull,0x5b202c3033662509ull,0x5d382b3432647225ull,0x662e646461090a3bull,
0x3133662509203233ull,0x202c35326625202cull,0x73090a3b38326625ull,0x6465726168732e74ull,
0x255b09203233662eull,0x2c5d302b32316472ull,0x090a3b3133662520ull,0x203233662e646461ull,
0x25202c3233662509ull,0x326625202c363266ull,0x732e7473090a3b39ull,0x33662e6465726168ull,
0x316472255b092032ull,0x6625202c5d342b32ull,0x646461090a3b3233ull,0x662509203233662eull,
0x37326625202c3333ull,0x0a3b30336625202cull,0x726168732e747309ull,0x09203233662e6465ull,
0x382b32316472255bull,0x3b33336625202c5dull,0x3109636f6c2e090aull,0x0a30093531320935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5f5b202c34336625ull,0x75735f616475635full,
0x302b30363531736dull,0x2e766f6d090a3b5dull,0x3366250920323366ull,0x3864336630202c35ull,
0x20203b3030303030ull,0x2e30202f2f092020ull,0x756d090a35323630ull,0x2509203233662e6cull,
0x336625202c363366ull,0x3b35336625202c34ull,0x33662e627573090aull,0x2c37336625092032ull,
0x6625202c33662520ull,0x6c756d090a3b3633ull,0x203233732e6f6c2eull,0x25202c3631722509ull,
0x090a3b36202c3172ull,0x2e3436732e747663ull,0x6472250920323373ull,0x36317225202c3532ull,
0x6c2e6c756d090a3bull,0x2509203436752e6full,0x7225202c36326472ull,0x0a3b34202c353264ull,
0x3436752e64646109ull,0x2c37326472250920ull,0x25202c3564722520ull,0x6d090a3b36326472ull,
0x09203233662e6c75ull,0x6625202c38336625ull,0x37336625202c3733ull,0x68732e7473090a3bull,
0x3233662e64657261ull,0x37326472255b0920ull,0x336625202c5d302bull,0x636f6c2e090a3b38ull,
0x0936313209353109ull,0x68732e646c090a30ull,0x3233662e64657261ull,0x202c393366250920ull,
0x5f616475635f5f5bull,0x30363531736d7573ull,0x6f6d090a3b5d342bull,0x2509203233662e76ull,
0x336630202c303466ull,0x3b30303030303864ull,0x202f2f0920202020ull,0x090a353236302e30ull,
0x203233662e6c756dull,0x25202c3134662509ull,0x346625202c393366ull,0x2e627573090a3b30ull,
0x3466250920323366ull,0x202c366625202c32ull,0x6d090a3b31346625ull,0x09203233662e6c75ull,
0x6625202c33346625ull,0x32346625202c3733ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x37326472255b0920ull,0x346625202c5d342bull,0x636f6c2e090a3b33ull,0x0937313209353109ull,
0x68732e646c090a30ull,0x3233662e64657261ull,0x202c343466250920ull,0x5f616475635f5f5bull,
0x30363531736d7573ull,0x6f6d090a3b5d382bull,0x2509203233662e76ull,0x336630202c353466ull,
0x3b30303030303864ull,0x202f2f0920202020ull,0x090a353236302e30ull,0x203233662e6c756dull,
0x25202c3634662509ull,0x346625202c343466ull,0x2e627573090a3b35ull,0x3466250920323366ull,
0x202c396625202c37ull,0x6d090a3b36346625ull,0x09203233662e6c75ull,0x6625202c38346625ull,
0x37346625202c3733ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x37326472255b0920ull,
0x346625202c5d382bull,0x636f6c2e090a3b38ull,0x0938313209353109ull,0x662e6c756d090a30ull,
0x3934662509203233ull,0x202c32346625202cull,0x73090a3b32346625ull,0x6465726168732e74ull,
0x255b09203233662eull,0x5d32312b37326472ull,0x0a3b39346625202cull,0x353109636f6c2e09ull,
0x090a300939313209ull,0x203233662e6c756dull,0x25202c3035662509ull,0x346625202c323466ull,
0x732e7473090a3b37ull,0x33662e6465726168ull,0x326472255b092032ull,0x25202c5d36312b37ull,
0x6c2e090a3b303566ull,0x323209353109636full,0x6c756d090a300930ull,0x662509203233662eull,
0x37346625202c3135ull,0x0a3b37346625202cull,0x726168732e747309ull,0x09203233662e6465ull,
0x322b37326472255bull,0x31356625202c5d30ull,0x732e766f6d090a3bull,0x3731722509203233ull,
0x744c240a3b38202cull,0x38313438325f305full,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,
0x696c2079646f6220ull,0x202c30323220656eull,0x20676e697473656eull,0x31203a6874706564ull,
0x616d69747365202cull,0x7265746920646574ull,0x203a736e6f697461ull,0x0a6e776f6e6b6e75ull,
0x656c2e7074657309ull,0x702509203233732eull,0x2c37317225202c32ull,0x40090a3b31722520ull,
0x2061726220327025ull,0x325f305f744c2409ull,0x2f200a3b34373638ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3032ull,
0x64656c6562616c20ull,0x325f305f744c2420ull,0x6c2e090a38313438ull,0x323209353109636full,
0x646461090a300936ull,0x722509203233732eull,0x37317225202c3831ull,0x090a3b317225202cull,
0x732e6f6c2e6c756dull,0x3931722509203233ull,0x202c38317225202cull,0x2e747663090a3b36ull,
0x203233732e343673ull,0x202c383264722509ull,0x6d090a3b39317225ull,0x36752e6f6c2e6c75ull,
0x3932647225092034ull,0x2c3832647225202cull,0x646461090a3b3420ull,0x722509203436752eull,
0x647225202c303364ull,0x3932647225202c35ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x202c323566250920ull,0x302b37326472255bull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x2c33356625092032ull,0x2b30336472255b20ull,0x646461090a3b5d30ull,0x662509203233662eull,
0x32356625202c3435ull,0x0a3b33356625202cull,0x726168732e747309ull,0x09203233662e6465ull,
0x302b37326472255bull,0x3b34356625202c5dull,0x3109636f6c2e090aull,0x0a30093732320935ull,
0x726168732e646c09ull,0x09203233662e6465ull,0x255b202c35356625ull,0x3b5d342b37326472ull,
0x6168732e646c090aull,0x203233662e646572ull,0x5b202c3635662509ull,0x5d342b3033647225ull,
0x662e646461090a3bull,0x3735662509203233ull,0x202c35356625202cull,0x73090a3b36356625ull,
0x6465726168732e74ull,0x255b09203233662eull,0x2c5d342b37326472ull,0x090a3b3735662520ull,
0x09353109636f6c2eull,0x6c090a3009383232ull,0x6465726168732e64ull,0x662509203233662eull,
0x6472255b202c3835ull,0x090a3b5d382b3732ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c393566ull,0x0a3b5d382b303364ull,0x3233662e64646109ull,0x202c303666250920ull,
0x6625202c38356625ull,0x2e7473090a3b3935ull,0x662e646572616873ull,0x6472255b09203233ull,
0x25202c5d382b3732ull,0x6c2e090a3b303666ull,0x323209353109636full,0x2e646c090a300939ull,
0x662e646572616873ull,0x3136662509203233ull,0x37326472255b202cull,0x6c090a3b5d32312bull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3236ull,0x0a3b5d32312b3033ull,
0x3233662e64646109ull,0x202c333666250920ull,0x6625202c31366625ull,0x2e7473090a3b3236ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d32312b3732ull,0x2e090a3b33366625ull,
0x3209353109636f6cull,0x646c090a30093033ull,0x2e6465726168732eull,0x3666250920323366ull,
0x326472255b202c34ull,0x090a3b5d36312b37ull,0x65726168732e646cull,0x2509203233662e64ull,
0x72255b202c353666ull,0x3b5d36312b303364ull,0x33662e646461090aull,0x2c36366625092032ull,
0x25202c3436662520ull,0x7473090a3b353666ull,0x2e6465726168732eull,0x72255b0920323366ull,
0x2c5d36312b373264ull,0x090a3b3636662520ull,0x09353109636f6c2eull,0x6c090a3009313332ull,
0x6465726168732e64ull,0x662509203233662eull,0x6472255b202c3736ull,0x0a3b5d30322b3033ull,
0x3233662e64646109ull,0x202c313566250920ull,0x6625202c37366625ull,0x2e7473090a3b3135ull,
0x662e646572616873ull,0x6472255b09203233ull,0x202c5d30322b3732ull,0x4c240a3b31356625ull,
0x373638325f305f74ull,0x6c3c2f2f200a3a34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c30323220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x313438325f305f74ull,0x09636f6c2e090a38ull,0x3009323232093531ull,0x33732e726873090aull,
0x2c37317225092032ull,0x31202c3731722520ull,0x752e766f6d090a3bull,0x3032722509203233ull,
0x6573090a3b30202cull,0x33732e74672e7074ull,0x202c337025092032ull,0x7225202c37317225ull,
0x702540090a3b3032ull,0x2409206172622033ull,0x3438325f305f744cull,0x6f6c2e090a3b3831ull,
0x3833320935310963ull,0x2e766f6d090a3009ull,0x6472250920343675ull,0x75635f5f202c3133ull,
0x73666572785f6164ull,0x2e090a3b32353731ull,0x3109353109636f6cull,0x646c090a30093335ull,
0x2e6465726168732eull,0x3666250920323366ull,0x61766f635b202c38ull,0x5f5f65636e616972ull,
0x6c090a3b5d342b30ull,0x6465726168732e64ull,0x662509203233662eull,0x766f635b202c3936ull,
0x5f65636e61697261ull,0x0a3b5d32312b305full,0x3233662e766f6d09ull,0x202c303766250920ull,
0x3030303866336630ull,0x09202020203b3030ull,0x616d090a31202f2full,0x2509203233662e64ull,
0x376625202c313766ull,0x2c38366625202c30ull,0x090a3b3936662520ull,0x65726168732e646cull,
0x2509203233662e64ull,0x6f635b202c323766ull,0x65636e6169726176ull,0x0a3b5d382b305f5full,
0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c33376625ull,0x636e61697261766full,
0x5d36312b305f5f65ull,0x662e766f6d090a3bull,0x3437662509203233ull,0x303866336630202cull,
0x2020203b30303030ull,0x090a31202f2f0920ull,0x203233662e64616dull,0x25202c3537662509ull,
0x376625202c343766ull,0x3b33376625202c32ull,0x6168732e646c090aull,0x203233662e646572ull,
0x5b202c3637662509ull,0x6e61697261766f63ull,0x5d302b305f5f6563ull,0x662e766f6d090a3bull,
0x3737662509203233ull,0x303866336630202cull,0x2020203b30303030ull,0x090a31202f2f0920ull,
0x203233662e64616dull,0x25202c3837662509ull,0x376625202c363766ull,0x3b38366625202c37ull,
0x33662e766f6d090aull,0x2c39376625092032ull,0x3030386633663020ull,0x202020203b303030ull,
0x6d090a31202f2f09ull,0x09203233662e6461ull,0x6625202c30386625ull,0x33376625202c3937ull,
0x0a3b31376625202cull,0x726168732e646c09ull,0x09203233662e6465ull,0x635b202c31386625ull,
0x636e61697261766full,0x5d30322b305f5f65ull,0x662e766f6d090a3bull,0x3238662509203233ull,
0x303866336630202cull,0x2020203b30303030ull,0x090a31202f2f0920ull,0x203233662e64616dull,
0x25202c3338662509ull,0x386625202c323866ull,0x3b35376625202c31ull,0x33662e766f6d090aull,
0x2c34386625092032ull,0x3030386633663020ull,0x202020203b303030ull,0x6d090a31202f2f09ull,
0x09203233662e6461ull,0x6625202c35386625ull,0x34386625202c3237ull,0x0a3b38376625202cull,
0x3233662e78616d09ull,0x202c363866250920ull,0x6625202c30386625ull,0x78616d090a3b3538ull,
0x662509203233662eull,0x33386625202c3738ull,0x0a3b36386625202cull,0x7070612e70637209ull,
0x203233662e786f72ull,0x25202c3838662509ull,0x756d090a3b373866ull,0x2509203233662e6cull,
0x386625202c393866ull,0x3b38386625202c30ull,0x33662e6c756d090aull,0x2c30396625092032ull,
0x25202c3538662520ull,0x756d090a3b383866ull,0x2509203233662e6cull,0x386625202c313966ull,
0x3b38386625202c33ull,0x33662e6c756d090aull,0x2c32396625092032ull,0x25202c3938662520ull,
0x756d090a3b333766ull,0x2509203233662e6cull,0x386625202c333966ull,0x3b38366625202c39ull,
0x33662e6c756d090aull,0x2c34396625092032ull,0x25202c3938662520ull,0x616d090a3b393666ull,
0x2509203233662e64ull,0x396625202c353966ull,0x2c32376625202c30ull,0x090a3b3239662520ull,
0x203233662e64616dull,0x25202c3639662509ull,0x396625202c363766ull,0x3b33396625202c30ull,
0x33662e64616d090aull,0x2c37396625092032ull,0x25202c3039662520ull,0x396625202c383666ull,
0x2e64616d090a3b34ull,0x3966250920323366ull,0x2c31396625202c38ull,0x25202c3138662520ull,
0x616d090a3b353966ull,0x2509203233662e64ull,0x376625202c393966ull,0x2c31396625202c32ull,
0x090a3b3639662520ull,0x203233662e64616dull,0x202c303031662509ull,0x6625202c31396625ull,
0x37396625202c3337ull,0x662e78616d090a3bull,0x3031662509203233ull,0x2c39396625202c31ull,
0x0a3b303031662520ull,0x3233662e78616d09ull,0x2c32303166250920ull,0x25202c3839662520ull,
0x72090a3b31303166ull,0x6f727070612e7063ull,0x2509203233662e78ull,0x6625202c33303166ull,
0x6c2e090a3b323031ull,0x343109353109636full,0x6c756d090a300939ull,0x662509203233662eull,
0x396625202c343031ull,0x3330316625202c38ull,0x662e6c756d090a3bull,0x3031662509203233ull,
0x2c39396625202c35ull,0x0a3b333031662520ull,0x3233662e6c756d09ull,0x2c36303166250920ull,
0x202c303031662520ull,0x090a3b3330316625ull,0x203233662e6c756dull,0x202c373031662509ull,
0x25202c3630316625ull,0x616d090a3b383666ull,0x2509203233662e64ull,0x6625202c38303166ull,
0x30316625202c3637ull,0x3730316625202c35ull,0x662e64616d090a3bull,0x3031662509203233ull,
0x2c32376625202c39ull,0x202c343031662520ull,0x090a3b3830316625ull,0x09353109636f6c2eull,
0x6d090a3009303531ull,0x09203233662e6c75ull,0x25202c3031316625ull,0x6625202c36303166ull,
0x64616d090a3b3936ull,0x662509203233662eull,0x316625202c313131ull,0x38366625202c3530ull,
0x3b3031316625202cull,0x33662e64616d090aull,0x3231316625092032ull,0x2c3430316625202cull,
0x25202c3337662520ull,0x2e090a3b31313166ull,0x3109353109636f6cull,0x756d090a30093135ull,
0x2509203233662e6cull,0x6625202c33313166ull,0x376625202c363031ull,0x2e64616d090a3b33ull,
0x3166250920323366ull,0x30316625202c3431ull,0x2c32376625202c35ull,0x0a3b333131662520ull,
0x3233662e64616d09ull,0x2c35313166250920ull,0x202c343031662520ull,0x6625202c31386625ull,
0x6c2e090a3b343131ull,0x353109353109636full,0x78616d090a300937ull,0x662509203233662eull,
0x316625202c363131ull,0x31316625202c3930ull,0x2e78616d090a3b32ull,0x3166250920323366ull,
0x31316625202c3731ull,0x3531316625202c36ull,0x612e706372090a3bull,0x33662e786f727070ull,
0x3831316625092032ull,0x3b3731316625202cull,0x33662e6c756d090aull,0x3931316625092032ull,
0x2c3831316625202cull,0x0a3b393031662520ull,0x3233662e6c756d09ull,0x2c30323166250920ull,
0x202c383131662520ull,0x090a3b3231316625ull,0x203233662e6c756dull,0x202c313231662509ull,
0x25202c3831316625ull,0x2e090a3b35313166ull,0x3109353109636f6cull,0x756d090a30093934ull,
0x2509203233662e6cull,0x6625202c32323166ull,0x366625202c303231ull,0x2e64616d090a3b38ull,
0x3166250920323366ull,0x36376625202c3332ull,0x2c3931316625202cull,0x0a3b323231662520ull,
0x3233662e64616d09ull,0x2c39303166250920ull,0x25202c3237662520ull,0x6625202c31323166ull,
0x6c2e090a3b333231ull,0x353109353109636full,0x6c756d090a300937ull,0x662509203233662eull,
0x316625202c343231ull,0x39366625202c3032ull,0x662e6c756d090a3bull,0x3231662509203233ull,
0x3032316625202c35ull,0x0a3b33376625202cull,0x3233662e64616d09ull,0x2c36323166250920ull,
0x202c393131662520ull,0x6625202c38366625ull,0x616d090a3b343231ull,0x2509203233662e64ull,
0x6625202c37323166ull,0x376625202c393131ull,0x3532316625202c32ull,0x662e64616d090a3bull,
0x3231662509203233ull,0x3132316625202c38ull,0x202c33376625202cull,0x090a3b3632316625ull,
0x203233662e64616dull,0x202c393231662509ull,0x25202c3132316625ull,0x316625202c313866ull,
0x78616d090a3b3732ull,0x662509203233662eull,0x316625202c303331ull,0x30316625202c3832ull,
0x2e78616d090a3b39ull,0x3166250920323366ull,0x32316625202c3133ull,0x3033316625202c39ull,
0x612e706372090a3bull,0x33662e786f727070ull,0x3233316625092032ull,0x3b3133316625202cull,
0x33662e6c756d090aull,0x3333316625092032ull,0x2c3832316625202cull,0x0a3b323331662520ull,
0x3233662e6c756d09ull,0x2c34333166250920ull,0x202c393231662520ull,0x090a3b3233316625ull,
0x203233662e6c756dull,0x202c353331662509ull,0x25202c3233316625ull,0x2e090a3b39303166ull,
0x3109353109636f6cull,0x756d090a30093135ull,0x2509203233662e6cull,0x6625202c36333166ull,
0x376625202c333331ull,0x2e64616d090a3b33ull,0x3166250920323366ull,0x33316625202c3733ull,
0x2c32376625202c35ull,0x0a3b363331662520ull,0x3233662e64616d09ull,0x2c38333166250920ull,
0x202c343331662520ull,0x6625202c31386625ull,0x6c2e090a3b373331ull,0x353109353109636full,
0x6c756d090a300933ull,0x662509203233662eull,0x316625202c393331ull,0x38366625202c3333ull,
0x662e6c756d090a3bull,0x3431662509203233ull,0x3333316625202c30ull,0x0a3b39366625202cull,
0x3233662e64616d09ull,0x2c31343166250920ull,0x25202c3637662520ull,0x6625202c35333166ull,
0x616d090a3b393331ull,0x2509203233662e64ull,0x6625202c32343166ull,0x366625202c353331ull,
0x3034316625202c38ull,0x662e64616d090a3bull,0x3431662509203233ull,0x2c32376625202c33ull,
0x202c343331662520ull,0x090a3b3134316625ull,0x203233662e64616dull,0x202c343431662509ull,
0x25202c3433316625ull,0x316625202c333766ull,0x78616d090a3b3234ull,0x662509203233662eull,
0x316625202c353431ull,0x34316625202c3334ull,0x2e78616d090a3b34ull,0x3166250920323366ull,
0x34316625202c3634ull,0x3833316625202c35ull,0x612e706372090a3bull,0x33662e786f727070ull,
0x3734316625092032ull,0x3b3634316625202cull,0x3109636f6c2e090aull,0x0a30093735310935ull,
0x3233662e6c756d09ull,0x2c38343166250920ull,0x202c333431662520ull,0x090a3b3734316625ull,
0x203233662e6c756dull,0x202c333331662509ull,0x25202c3434316625ull,0x2e090a3b37343166ull,
0x3109353109636f6cull,0x756d090a30093934ull,0x2509203233662e6cull,0x6625202c39343166ull,
0x316625202c373431ull,0x6c756d090a3b3833ull,0x662509203233662eull,0x316625202c303531ull,
0x38366625202c3333ull,0x662e64616d090a3bull,0x3531662509203233ull,0x2c36376625202c31ull,
0x202c383431662520ull,0x090a3b3035316625ull,0x203233662e64616dull,0x202c393031662509ull,
0x6625202c32376625ull,0x316625202c393431ull,0x6f6c2e090a3b3135ull,0x3035310935310963ull,
0x2e6c756d090a3009ull,0x3166250920323366ull,0x33316625202c3235ull,0x3b39366625202c33ull,
0x33662e64616d090aull,0x3335316625092032ull,0x2c3834316625202cull,0x25202c3836662520ull,
0x6d090a3b32353166ull,0x09203233662e6461ull,0x25202c3231316625ull,0x6625202c39343166ull,
0x35316625202c3337ull,0x636f6c2e090a3b33ull,0x0931353109353109ull,0x662e6c756d090a30ull,
0x3531662509203233ull,0x3333316625202c34ull,0x0a3b33376625202cull,0x3233662e64616d09ull,
0x2c35353166250920ull,0x202c383431662520ull,0x6625202c32376625ull,0x616d090a3b343531ull,
0x2509203233662e64ull,0x6625202c35313166ull,0x386625202c393431ull,0x3535316625202c31ull,
0x09636f6c2e090a3bull,0x3009373531093531ull,0x33662e78616d090aull,0x3631316625092032ull,
0x2c3930316625202cull,0x0a3b323131662520ull,0x3233662e78616d09ull,0x2c37313166250920ull,
0x202c363131662520ull,0x090a3b3531316625ull,0x727070612e706372ull,0x09203233662e786full,
0x25202c3831316625ull,0x6d090a3b37313166ull,0x09203233662e6c75ull,0x25202c3635316625ull,
0x6625202c38313166ull,0x756d090a3b393031ull,0x2509203233662e6cull,0x6625202c37353166ull,
0x316625202c383131ull,0x6c756d090a3b3231ull,0x662509203233662eull,0x316625202c383531ull,
0x31316625202c3831ull,0x636f6c2e090a3b35ull,0x0939343109353109ull,0x662e6c756d090a30ull,
0x3531662509203233ull,0x3735316625202c39ull,0x0a3b38366625202cull,0x3233662e64616d09ull,
0x2c30363166250920ull,0x25202c3637662520ull,0x6625202c36353166ull,0x616d090a3b393531ull,
0x2509203233662e64ull,0x6625202c39303166ull,0x35316625202c3237ull,0x3036316625202c38ull,
0x09636f6c2e090a3bull,0x3009373531093531ull,0x33662e6c756d090aull,0x3432316625092032ull,
0x2c3735316625202cull,0x090a3b3936662520ull,0x203233662e6c756dull,0x202c353231662509ull,
0x25202c3735316625ull,0x616d090a3b333766ull,0x2509203233662e64ull,0x6625202c36323166ull,
0x366625202c363531ull,0x3432316625202c38ull,0x662e64616d090a3bull,0x3231662509203233ull,
0x3635316625202c37ull,0x202c32376625202cull,0x090a3b3532316625ull,0x203233662e64616dull,
0x202c383231662509ull,0x25202c3835316625ull,0x316625202c333766ull,0x64616d090a3b3632ull,
0x662509203233662eull,0x316625202c393231ull,0x31386625202c3835ull,0x3b3732316625202cull,
0x33662e78616d090aull,0x3033316625092032ull,0x2c3832316625202cull,0x0a3b393031662520ull,
0x3233662e78616d09ull,0x2c31333166250920ull,0x202c393231662520ull,0x090a3b3033316625ull,
0x727070612e706372ull,0x09203233662e786full,0x25202c3233316625ull,0x6d090a3b31333166ull,
0x09203233662e6c75ull,0x25202c3333316625ull,0x6625202c38323166ull,0x756d090a3b323331ull,
0x2509203233662e6cull,0x6625202c34333166ull,0x316625202c393231ull,0x6c756d090a3b3233ull,
0x662509203233662eull,0x316625202c353331ull,0x30316625202c3233ull,0x636f6c2e090a3b39ull,
0x0931353109353109ull,0x662e6c756d090a30ull,0x3331662509203233ull,0x3333316625202c36ull,
0x0a3b33376625202cull,0x3233662e64616d09ull,0x2c37333166250920ull,0x202c353331662520ull,
0x6625202c32376625ull,0x616d090a3b363331ull,0x2509203233662e64ull,0x6625202c31363166ull,
0x386625202c343331ull,0x3733316625202c31ull,0x09636f6c2e090a3bull,0x3009333531093531ull,
0x33662e6c756d090aull,0x3933316625092032ull,0x2c3333316625202cull,0x090a3b3836662520ull,
0x203233662e6c756dull,0x202c303431662509ull,0x25202c3333316625ull,0x616d090a3b393666ull,
0x2509203233662e64ull,0x6625202c31343166ull,0x33316625202c3637ull,0x3933316625202c35ull,
0x662e64616d090a3bull,0x3431662509203233ull,0x3533316625202c32ull,0x202c38366625202cull,
0x090a3b3034316625ull,0x203233662e64616dull,0x202c333431662509ull,0x6625202c32376625ull,
0x316625202c343331ull,0x64616d090a3b3134ull,0x662509203233662eull,0x316625202c343431ull,
0x33376625202c3433ull,0x3b3234316625202cull,0x33662e78616d090aull,0x3534316625092032ull,
0x2c3334316625202cull,0x0a3b343431662520ull,0x3233662e78616d09ull,0x2c36343166250920ull,
0x202c353431662520ull,0x090a3b3136316625ull,0x727070612e706372ull,0x09203233662e786full,
0x25202c3236316625ull,0x2e090a3b36343166ull,0x3109353109636f6cull,0x756d090a30093735ull,
0x2509203233662e6cull,0x6625202c38343166ull,0x316625202c333431ull,0x6c756d090a3b3236ull,
0x662509203233662eull,0x316625202c333331ull,0x36316625202c3434ull,0x636f6c2e090a3b32ull,
0x0933363109363109ull,0x662e6c756d090a30ull,0x3431662509203233ull,0x3236316625202c39ull,
0x3b3136316625202cull,0x33662e6c756d090aull,0x3336316625092032ull,0x25202c366625202cull,
0x6d090a3b33333166ull,0x09203233662e6461ull,0x25202c3436316625ull,0x34316625202c3366ull,
0x3336316625202c38ull,0x662e64616d090a3bull,0x3631662509203233ull,0x202c396625202c35ull,
0x25202c3934316625ull,0x6d090a3b34363166ull,0x09203436752e766full,0x64202c3233647225ull,
0x090a3b335f5f7370ull,0x203436752e646461ull,0x202c333364722509ull,0x7225202c32647225ull,
0x7473090a3b323364ull,0x2e6465726168732eull,0x72255b0920323366ull,0x202c5d302b333364ull,
0x090a3b3536316625ull,0x09363109636f6c2eull,0x6c090a3009383131ull,0x6465726168732e64ull,
0x662509203233662eull,0x70645b202c363631ull,0x5d36312b335f5f73ull,0x6c2e746573090a3bull,
0x33662e3233752e74ull,0x2c31327225092032ull,0x202c363631662520ull,0x090a3b3536316625ull,
0x203233732e67656eull,0x25202c3232722509ull,0x646c090a3b313272ull,0x2e6465726168732eull,
0x3166250920323366ull,0x7370645b202c3736ull,0x3b5d30322b335f5full,0x746c2e746573090aull,
0x3233662e3233752eull,0x202c333272250920ull,0x25202c3736316625ull,0x6e090a3b35363166ull,
0x09203233732e6765ull,0x7225202c34327225ull,0x646461090a3b3332ull,0x722509203233732eull,
0x32327225202c3532ull,0x0a3b34327225202cull,0x726168732e646c09ull,0x09203233662e6465ull,
0x5b202c3836316625ull,0x302b335f5f737064ull,0x2e746573090a3b5dull,0x662e3233752e746cull,
0x3632722509203233ull,0x2c3836316625202cull,0x0a3b353631662520ull,0x3233732e67656e09ull,
0x202c373272250920ull,0x6c090a3b36327225ull,0x6465726168732e64ull,0x662509203233662eull,
0x70645b202c393631ull,0x3b5d342b335f5f73ull,0x746c2e746573090aull,0x3233662e3233752eull,
0x202c383272250920ull,0x25202c3936316625ull,0x6e090a3b35363166ull,0x09203233732e6765ull,
0x7225202c39327225ull,0x646461090a3b3832ull,0x722509203233732eull,0x37327225202c3033ull,
0x0a3b39327225202cull,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3037316625ull,
0x382b335f5f737064ull,0x2e746573090a3b5dull,0x662e3233752e746cull,0x3133722509203233ull,
0x2c3037316625202cull,0x0a3b353631662520ull,0x3233732e67656e09ull,0x202c323372250920ull,
0x6c090a3b31337225ull,0x6465726168732e64ull,0x662509203233662eull,0x70645b202c313731ull,
0x5d32312b335f5f73ull,0x6c2e746573090a3bull,0x33662e3233752e74ull,0x2c33337225092032ull,
0x202c313731662520ull,0x090a3b3536316625ull,0x203233732e67656eull,0x25202c3433722509ull,
0x6461090a3b333372ull,0x2509203233732e64ull,0x337225202c353372ull,0x3b34337225202c32ull,
0x33732e646461090aull,0x2c36337225092032ull,0x25202c3033722520ull,0x6461090a3b353372ull,
0x2509203233732e64ull,0x327225202c373372ull,0x3b36337225202c35ull,0x6168732e646c090aull,
0x203233662e646572ull,0x202c323731662509ull,0x2b335f5f7370645bull,0x6573090a3b5d3432ull,
0x3233752e746c2e74ull,0x722509203233662eull,0x37316625202c3833ull,0x3536316625202c32ull,
0x732e67656e090a3bull,0x3933722509203233ull,0x0a3b38337225202cull,0x3233732e64646109ull,
0x202c373372250920ull,0x7225202c37337225ull,0x2e646c090a3b3933ull,0x662e646572616873ull,
0x3731662509203233ull,0x5f7370645b202c33ull,0x0a3b5d38322b335full,0x2e746c2e74657309ull,
0x203233662e323375ull,0x25202c3034722509ull,0x6625202c33373166ull,0x656e090a3b353631ull,
0x2509203233732e67ull,0x347225202c313472ull,0x2e646461090a3b30ull,0x3372250920323373ull,
0x2c37337225202c37ull,0x090a3b3134722520ull,0x65726168732e646cull,0x2509203233662e64ull,
0x645b202c34373166ull,0x32332b335f5f7370ull,0x2e746573090a3b5dull,0x662e3233752e746cull,
0x3234722509203233ull,0x2c3437316625202cull,0x0a3b353631662520ull,0x3233732e67656e09ull,
0x202c333472250920ull,0x61090a3b32347225ull,0x09203233732e6464ull,0x7225202c37337225ull,
0x33347225202c3733ull,0x68732e646c090a3bull,0x3233662e64657261ull,0x2c35373166250920ull,
0x335f5f7370645b20ull,0x73090a3b5d36332bull,0x33752e746c2e7465ull,0x2509203233662e32ull,
0x316625202c343472ull,0x36316625202c3537ull,0x2e67656e090a3b35ull,0x3472250920323373ull,
0x3b34347225202c35ull,0x33732e646461090aull,0x2c37337225092032ull,0x25202c3733722520ull,
0x646c090a3b353472ull,0x2e6465726168732eull,0x3166250920323366ull,0x7370645b202c3637ull,
0x3b5d30342b335f5full,0x746c2e746573090aull,0x3233662e3233752eull,0x202c363472250920ull,
0x25202c3637316625ull,0x6e090a3b35363166ull,0x09203233732e6765ull,0x7225202c37347225ull,
0x646461090a3b3634ull,0x722509203233732eull,0x37337225202c3733ull,0x0a3b37347225202cull,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3737316625ull,0x342b335f5f737064ull,
0x746573090a3b5d34ull,0x2e3233752e746c2eull,0x3472250920323366ull,0x3737316625202c38ull,
0x3b3536316625202cull,0x33732e67656e090aull,0x2c39347225092032ull,0x090a3b3834722520ull,
0x203233732e646461ull,0x25202c3733722509ull,0x347225202c373372ull,0x732e646c090a3b39ull,
0x33662e6465726168ull,0x3837316625092032ull,0x5f5f7370645b202cull,0x090a3b5d38342b33ull,
0x752e746c2e746573ull,0x09203233662e3233ull,0x6625202c30357225ull,0x316625202c383731ull,
0x67656e090a3b3536ull,0x722509203233732eull,0x30357225202c3135ull,0x732e646461090a3bull,
0x3733722509203233ull,0x202c37337225202cull,0x6c090a3b31357225ull,0x6465726168732e64ull,
0x662509203233662eull,0x70645b202c393731ull,0x5d32352b335f5f73ull,0x6c2e746573090a3bull,
0x33662e3233752e74ull,0x2c32357225092032ull,0x202c393731662520ull,0x090a3b3536316625ull,
0x203233732e67656eull,0x25202c3335722509ull,0x6461090a3b323572ull,0x2509203233732e64ull,
0x337225202c373372ull,0x3b33357225202c37ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c303831662509ull,0x2b335f5f7370645bull,0x6573090a3b5d3635ull,0x3233752e746c2e74ull,
0x722509203233662eull,0x38316625202c3435ull,0x3536316625202c30ull,0x732e67656e090a3bull,
0x3535722509203233ull,0x0a3b34357225202cull,0x3233732e64646109ull,0x202c373372250920ull,
0x7225202c37337225ull,0x2e646c090a3b3535ull,0x662e646572616873ull,0x3831662509203233ull,
0x5f7370645b202c31ull,0x0a3b5d30362b335full,0x2e746c2e74657309ull,0x203233662e323375ull,
0x25202c3635722509ull,0x6625202c31383166ull,0x656e090a3b353631ull,0x2509203233732e67ull,
0x357225202c373572ull,0x2e646461090a3b36ull,0x3572250920323373ull,0x2c37337225202c38ull,
0x090a3b3735722520ull,0x09363109636f6c2eull,0x61090a3009313231ull,0x09203436752e6464ull,
0x25202c3433647225ull,0x647225202c326472ull,0x766f6d090a3b3133ull,0x722509203233732eull,
0x38357225202c3935ull,0x68732e7473090a3bull,0x3233732e64657261ull,0x34336472255b0920ull,
0x357225202c5d302bull,0x636f6c2e090a3b38ull,0x3009343209363109ull,0x33732e766f6d090aull,
0x2c30367225092032ull,0x5f744c240a3b3020ull,0x3a34353939325f30ull,0x6f6f6c3c2f2f200aull,
0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x656e202c34322065ull,0x656420676e697473ull,
0x202c31203a687470ull,0x6f69746172657469ull,0x090a3531203a736eull,0x09363109636f6c2eull,
0x73090a3009373231ull,0x732e65672e707465ull,0x2c34702509203233ull,0x25202c3036722520ull,
0x702540090a3b3172ull,0x2409206172622034ull,0x3233345f305f744cull,0x3c2f2f200a3b3636ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x2c343220656e696cull,
0x616c206461656820ull,0x4c242064656c6562ull,0x353939325f305f74ull,0x752e747663090a34ull,
0x09203233732e3436ull,0x25202c3533647225ull,0x756d090a3b303672ull,0x3436752e6f6c2e6cull,
0x2c36336472250920ull,0x202c353364722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x33647225202c3733ull,0x3633647225202c31ull,0x68732e646c090a3bull,0x3233732e64657261ull,
0x202c313672250920ull,0x302b37336472255bull,0x70746573090a3b5dull,0x203233732e656e2eull,
0x7225202c35702509ull,0x39357225202c3136ull,0x2035702540090a3bull,0x744c240920617262ull,
0x36363233345f305full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x68202c343220656eull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34353939325f30ull,0x3233732e64646109ull,0x202c393572250920ull,0x3b31202c39357225ull,
0x6168732e7473090aull,0x203233732e646572ull,0x2b34336472255b09ull,0x39357225202c5d30ull,
0x5f305f744c240a3bull,0x240a3a3636323334ull,0x383836325f305f4cull,0x6c3c2f2f200a3a32ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x202c343220656e69ull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34353939325f305full,0x33732e646461090aull,
0x2c30367225092032ull,0x31202c3036722520ull,0x752e766f6d090a3bull,0x3236722509203233ull,
0x73090a3b3531202cull,0x732e656e2e707465ull,0x2c36702509203233ull,0x25202c3036722520ull,
0x2540090a3b323672ull,0x0920617262203670ull,0x39325f305f744c24ull,0x6c2e090a3b343539ull,
0x373109363109636full,0x747663090a300937ull,0x3233732e3436752eull,0x2c38336472250920ull,
0x090a3b3935722520ull,0x752e6f6c2e6c756dull,0x3364722509203436ull,0x3833647225202c39ull,
0x61090a3b3231202cull,0x09203436752e6464ull,0x25202c3034647225ull,0x647225202c336472ull,
0x2e7473090a3b3933ull,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d302b3034ull,
0x2e7473090a3b3366ull,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d342b3034ull,
0x2e7473090a3b3666ull,0x662e646572616873ull,0x6472255b09203233ull,0x25202c5d382b3034ull,
0x5f744c240a3b3966ull,0x3a34393337325f30ull,0x3109636f6c2e090aull,0x0a30093631350936ull,
0x3436752e766f6d09ull,0x202c336472250920ull,0x635f616475635f5full,0x36333173726f6c6full,
0x636f6c2e090a3b38ull,0x0938313509363109ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x363109636f6c2e09ull,0x090a300935323509ull,0x203233732e766f6dull,0x30202c3336722509ull,
0x662e766f6d090a3bull,0x3831662509203233ull,0x3766376630202c32ull,0x20203b6666666666ull,
0x342e33202f2f0920ull,0x38332b6532383230ull,0x36752e766f6d090aull,0x3134647225092034ull,
0x6d7265705f73202cull,0x736e6f6974617475ull,0x6f6d090a3b325f5full,0x2509203436752e76ull,
0x7270202c32346472ull,0x6d090a3b3473646full,0x09203436752e766full,0x61202c3334647225ull,
0x6c6261546168706cull,0x5f744c240a3b3465ull,0x3a38373930335f30ull,0x6f6f6c3c2f2f200aull,
0x20706f6f4c203e70ull,0x6e696c2079646f62ull,0x6e202c3532352065ull,0x6420676e69747365ull,
0x2c31203a68747065ull,0x74616d6974736520ull,0x6172657469206465ull,0x31203a736e6f6974ull,
0x09636f6c2e090a36ull,0x3009343433093631ull,0x33732e646461090aull,0x2c34367225092032ull,
0x25202c3336722520ull,0x766f6d090a3b3172ull,0x722509203233752eull,0x3b313939202c3536ull,
0x672e70746573090aull,0x2509203233732e74ull,0x34367225202c3770ull,0x0a3b35367225202cull,
0x7262203770254009ull,0x305f744c24092061ull,0x2f200a3b3835325full,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3520656e696c2079ull,0x64616568202c3532ull,
0x64656c6562616c20ull,0x335f305f744c2420ull,0x6c2e090a38373930ull,0x343309363109636full,
0x747663090a300937ull,0x3233732e3436752eull,0x2c34346472250920ull,0x090a3b3436722520ull,
0x752e6f6c2e6c756dull,0x3464722509203436ull,0x3434647225202c35ull,0x646c090a3b34202cull,
0x752e6d617261702eull,0x3464722509203436ull,0x75635f5f5b202c36ull,0x5f5f6d7261706164ull,
0x6572706d6f63385aull,0x5f30536a4b507373ull,0x5f32746e69753550ull,0x746174756d726570ull,
0x090a3b5d736e6f69ull,0x203436752e646461ull,0x202c373464722509ull,0x25202c3634647225ull,
0x6c090a3b35346472ull,0x6c61626f6c672e64ull,0x722509203233752eull,0x6472255b202c3636ull,
0x090a3b5d302b3734ull,0x203233752e766f6dull,0x31202c3736722509ull,0x746573090a3b3935ull,
0x3233732e74672e70ull,0x25202c3870250920ull,0x367225202c343672ull,0x38702540090a3b37ull,
0x4c24092061726220ull,0x333231335f305f74ull,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35323520656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x373930335f305f74ull,0x09636f6c2e090a38ull,0x3009383433093631ull,
0x36752e646461090aull,0x3834647225092034ull,0x2c3534647225202cull,0x0a3b313464722520ull,
0x726168732e747309ull,0x09203233752e6465ull,0x302b38346472255bull,0x3b36367225202c5dull,
0x335f305f744c240aull,0x2f200a3a34333231ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3520656e696c2079ull,0x64616568202c3532ull,0x64656c6562616c20ull,
0x335f305f744c2420ull,0x6c2e090a38373930ull,0x353309363109636full,0x766f6d090a300930ull,
0x722509203233732eull,0x090a3b30202c3836ull,0x203436732e766f6dull,0x202c393464722509ull,
0x6d090a3b33647225ull,0x09203233732e766full,0x3b30202c39367225ull,0x33662e766f6d090aull,
0x3338316625092032ull,0x303030306630202cull,0x2020203b30303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x30202c3438316625ull,0x3030303030303066ull,0x2f2f092020203b30ull,
0x2e766f6d090a3020ull,0x3166250920323366ull,0x30306630202c3538ull,0x203b303030303030ull,
0x0a30202f2f092020ull,0x32335f305f744c24ull,0x2f2f200a3a383532ull,0x4c203e706f6f6c3cull,
0x79646f6220706f6full,0x353320656e696c20ull,0x697473656e202c30ull,0x687470656420676eull,
0x657469202c31203aull,0x3a736e6f69746172ull,0x6f6c2e090a363120ull,0x3332320936310963ull,
0x2e726873090a3009ull,0x3772250920323375ull,0x2c36367225202c30ull,0x090a3b3836722520ull,
0x203233622e646e61ull,0x25202c3137722509ull,0x0a3b33202c303772ull,0x3436752e74766309ull,
0x722509203233752eull,0x377225202c303564ull,0x2e6c756d090a3b31ull,0x09203436752e6f6cull,
0x25202c3135647225ull,0x3b34202c30356472ull,0x36752e646461090aull,0x3235647225092034ull,
0x2c3135647225202cull,0x0a3b333464722520ull,0x736e6f632e646c09ull,0x2509203233662e74ull,
0x255b202c36383166ull,0x3b5d302b32356472ull,0x6168732e646c090aull,0x203233662e646572ull,
0x202c373831662509ull,0x302b39346472255bull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x3838316625092032ull,0x39346472255b202cull,0x646c090a3b5d342bull,0x2e6465726168732eull,
0x3166250920323366ull,0x6472255b202c3938ull,0x090a3b5d382b3934ull,0x203233662e64616dull,
0x202c353831662509ull,0x25202c3638316625ull,0x6625202c37383166ull,0x616d090a3b353831ull,
0x2509203233662e64ull,0x6625202c34383166ull,0x316625202c363831ull,0x38316625202c3838ull,
0x2e64616d090a3b34ull,0x3166250920323366ull,0x38316625202c3338ull,0x3938316625202c36ull,
0x3b3338316625202cull,0x3109636f6c2e090aull,0x0a30093432320936ull,0x3436752e64646109ull,
0x2c33356472250920ull,0x202c313564722520ull,0x090a3b3234647225ull,0x74736e6f632e646cull,
0x722509203233732eull,0x6472255b202c3237ull,0x090a3b5d302b3335ull,0x203233732e646461ull,
0x25202c3936722509ull,0x367225202c323772ull,0x2e646461090a3b39ull,0x6472250920343675ull,
0x34647225202c3934ull,0x090a3b3231202c39ull,0x203233732e646461ull,0x25202c3836722509ull,
0x0a3b32202c383672ull,0x3233752e766f6d09ull,0x202c333772250920ull,0x746573090a3b3233ull,
0x3233732e656e2e70ull,0x25202c3970250920ull,0x377225202c383672ull,0x39702540090a3b33ull,
0x4c24092061726220ull,0x353232335f305f74ull,0x6c3c2f2f200a3b38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35323520656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x373930335f305f74ull,0x09636f6c2e090a38ull,0x3009323632093631ull,
0x33622e646e61090aull,0x2c34377225092032ull,0x32202c3936722520ull,0x726873090a3b3535ull,
0x722509203233732eull,0x39367225202c3537ull,0x73090a3b3631202cull,0x09203233732e7268ull,
0x7225202c36377225ull,0x090a3b38202c3936ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5b202c30393166ull,0x75735f616475635full,0x302b30363531736dull,0x2e766f6d090a3b5dull,
0x3166250920323366ull,0x31346630202c3139ull,0x203b303030303031ull,0x0a39202f2f092020ull,
0x3233662e6c756d09ull,0x2c32393166250920ull,0x202c303931662520ull,0x090a3b3139316625ull,
0x65726168732e646cull,0x2509203233662e64ull,0x5f5b202c33393166ull,0x75735f616475635full,
0x342b30363531736dull,0x2e766f6d090a3b5dull,0x3166250920323366ull,0x31346630202c3439ull,
0x203b303030303031ull,0x0a39202f2f092020ull,0x3233662e6c756d09ull,0x2c35393166250920ull,
0x202c333931662520ull,0x090a3b3439316625ull,0x65726168732e646cull,0x2509203233662e64ull,
0x5f5b202c36393166ull,0x75735f616475635full,0x382b30363531736dull,0x2e766f6d090a3b5dull,
0x3166250920323366ull,0x31346630202c3739ull,0x203b303030303031ull,0x0a39202f2f092020ull,
0x3233662e6c756d09ull,0x2c38393166250920ull,0x202c363931662520ull,0x090a3b3739316625ull,
0x662e6e722e747663ull,0x09203233732e3233ull,0x25202c3939316625ull,0x7663090a3b343772ull,
0x3233662e6e722e74ull,0x662509203233732eull,0x377225202c303032ull,0x2e646e61090a3b35ull,
0x3772250920323362ull,0x2c36377225202c37ull,0x73090a3b35353220ull,0x09203233662e6275ull,
0x25202c3130326625ull,0x6625202c32393166ull,0x7573090a3b353831ull,0x2509203233662e62ull,
0x6625202c32303266ull,0x316625202c353931ull,0x627573090a3b3438ull,0x662509203233662eull,
0x316625202c333032ull,0x38316625202c3839ull,0x2e6c756d090a3b33ull,0x3266250920323366ull,
0x39316625202c3430ull,0x3939316625202c39ull,0x722e747663090a3bull,0x33732e3233662e6eull,
0x3530326625092032ull,0x0a3b37377225202cull,0x3233662e6c756d09ull,0x2c36303266250920ull,
0x202c393931662520ull,0x090a3b3130326625ull,0x203233662e6c756dull,0x202c373032662509ull,
0x25202c3939316625ull,0x6d090a3b32303266ull,0x09203233662e6c75ull,0x25202c3830326625ull,
0x6625202c39393166ull,0x756d090a3b333032ull,0x2509203233662e6cull,0x6625202c39303266ull,
0x326625202c303032ull,0x627573090a3b3530ull,0x662509203233662eull,0x326625202c303132ull,
0x30326625202c3930ull,0x2e6c756d090a3b34ull,0x3266250920323366ull,0x30326625202c3131ull,
0x3538316625202c35ull,0x662e6c756d090a3bull,0x3132662509203233ull,0x3530326625202c32ull,
0x3b3438316625202cull,0x33662e6c756d090aull,0x3331326625092032ull,0x2c3530326625202cull,
0x0a3b333831662520ull,0x7070612e70637209ull,0x203233662e786f72ull,0x202c343132662509ull,
0x090a3b3031326625ull,0x203233662e627573ull,0x202c353132662509ull,0x25202c3131326625ull,
0x73090a3b36303266ull,0x09203233662e6275ull,0x25202c3631326625ull,0x6625202c32313266ull,
0x7573090a3b373032ull,0x2509203233662e62ull,0x6625202c37313266ull,0x326625202c333132ull,
0x6c756d090a3b3830ull,0x662509203233662eull,0x326625202c383132ull,0x31326625202c3431ull,
0x2e6c756d090a3b35ull,0x3266250920323366ull,0x31326625202c3931ull,0x3631326625202c34ull,
0x662e6c756d090a3bull,0x3232662509203233ull,0x3431326625202c30ull,0x3b3731326625202cull,
0x61732e747663090aull,0x33662e3233662e74ull,0x3132326625092032ull,0x3b3831326625202cull,
0x61732e747663090aull,0x33662e3233662e74ull,0x3232326625092032ull,0x3b3931326625202cull,
0x61732e747663090aull,0x33662e3233662e74ull,0x3332326625092032ull,0x3b3032326625202cull,
0x33662e766f6d090aull,0x3432326625092032ull,0x386631346630202cull,0x2020203b30303030ull,
0x090a3133202f2f09ull,0x203233662e6c756dull,0x202c353232662509ull,0x25202c3132326625ull,
0x6d090a3b34323266ull,0x09203233662e766full,0x30202c3632326625ull,0x3030306337323466ull,
0x2f2f092020203b30ull,0x6c756d090a333620ull,0x662509203233662eull,0x326625202c373232ull,
0x32326625202c3232ull,0x2e766f6d090a3b36ull,0x3266250920323366ull,0x31346630202c3832ull,
0x203b303030303866ull,0x3133202f2f092020ull,0x33662e6c756d090aull,0x3932326625092032ull,
0x2c3332326625202cull,0x0a3b383232662520ull,0x696e722e74766309ull,0x3233662e3233662eull,
0x2c30333266250920ull,0x0a3b353232662520ull,0x696e722e74766309ull,0x3233662e3233662eull,
0x2c31333266250920ull,0x0a3b373232662520ull,0x696e722e74766309ull,0x3233662e3233662eull,
0x2c32333266250920ull,0x0a3b393232662520ull,0x697a722e74766309ull,0x3233662e3233752eull,
0x202c383772250920ull,0x090a3b3033326625ull,0x203233622e6c6873ull,0x25202c3937722509ull,
0x3b3131202c383772ull,0x7a722e747663090aull,0x33662e3233752e69ull,0x2c30387225092032ull,
0x0a3b313332662520ull,0x3233622e6c687309ull,0x202c313872250920ull,0x3b35202c30387225ull,
0x3233622e726f090aull,0x202c323872250920ull,0x7225202c39377225ull,0x747663090a3b3138ull,
0x3233752e697a722eull,0x722509203233662eull,0x33326625202c3338ull,0x622e726f090a3b32ull,
0x3438722509203233ull,0x202c32387225202cull,0x2e090a3b33387225ull,0x3209363109636f6cull,
0x756d090a30093336ull,0x2509203233662e6cull,0x6625202c33333266ull,0x316625202c393931ull,
0x6c756d090a3b3538ull,0x662509203233662eull,0x316625202c343332ull,0x38316625202c3939ull,
0x2e6c756d090a3b34ull,0x3266250920323366ull,0x39316625202c3533ull,0x3338316625202c39ull,
0x662e6c756d090a3bull,0x3332662509203233ull,0x3030326625202c36ull,0x3b3130326625202cull,
0x33662e6c756d090aull,0x3733326625092032ull,0x2c3030326625202cull,0x0a3b323032662520ull,
0x3233662e6c756d09ull,0x2c38333266250920ull,0x202c303032662520ull,0x090a3b3330326625ull,
0x203233662e627573ull,0x202c393332662509ull,0x25202c3633326625ull,0x73090a3b33333266ull,
0x09203233662e6275ull,0x25202c3034326625ull,0x6625202c37333266ull,0x7573090a3b343332ull,
0x2509203233662e62ull,0x6625202c31343266ull,0x326625202c383332ull,0x6c756d090a3b3533ull,
0x662509203233662eull,0x326625202c323432ull,0x31326625202c3933ull,0x2e6c756d090a3b34ull,
0x3266250920323366ull,0x34326625202c3334ull,0x3431326625202c30ull,0x662e6c756d090a3bull,
0x3432662509203233ull,0x3134326625202c34ull,0x3b3431326625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3534326625092032ull,0x3b3234326625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3634326625092032ull,0x3b3334326625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3734326625092032ull,0x3b3434326625202cull,0x33662e766f6d090aull,
0x3834326625092032ull,0x386631346630202cull,0x2020203b30303030ull,0x090a3133202f2f09ull,
0x203233662e6c756dull,0x202c393432662509ull,0x25202c3534326625ull,0x6d090a3b38343266ull,
0x09203233662e766full,0x30202c3035326625ull,0x3030306337323466ull,0x2f2f092020203b30ull,
0x6c756d090a333620ull,0x662509203233662eull,0x326625202c313532ull,0x35326625202c3634ull,
0x2e766f6d090a3b30ull,0x3266250920323366ull,0x31346630202c3235ull,0x203b303030303866ull,
0x3133202f2f092020ull,0x33662e6c756d090aull,0x3335326625092032ull,0x2c3734326625202cull,
0x0a3b323532662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c34353266250920ull,
0x0a3b393432662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c35353266250920ull,
0x0a3b313532662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c36353266250920ull,
0x0a3b333532662520ull,0x697a722e74766309ull,0x3233662e3233752eull,0x202c353872250920ull,
0x090a3b3435326625ull,0x203233622e6c6873ull,0x25202c3638722509ull,0x3b3131202c353872ull,
0x7a722e747663090aull,0x33662e3233752e69ull,0x2c37387225092032ull,0x0a3b353532662520ull,
0x3233622e6c687309ull,0x202c383872250920ull,0x3b35202c37387225ull,0x3233622e726f090aull,
0x202c393872250920ull,0x7225202c36387225ull,0x747663090a3b3838ull,0x3233752e697a722eull,
0x722509203233662eull,0x35326625202c3039ull,0x622e726f090a3b36ull,0x3139722509203233ull,
0x202c39387225202cull,0x2e090a3b30397225ull,0x3209363109636f6cull,0x6f6d090a30093636ull,
0x2509203233662e76ull,0x6630202c37353266ull,0x3137353334306433ull,0x202f2f092020203bull,
0x3737323233302e30ull,0x662e6c756d090a35ull,0x3532662509203233ull,0x3033326625202c38ull,
0x3b3735326625202cull,0x33662e6c756d090aull,0x3935326625092032ull,0x2c3835326625202cull,
0x0a3b383532662520ull,0x3233662e766f6d09ull,0x2c30363266250920ull,0x6231386333663020ull,
0x092020203b393131ull,0x3531302e30202f2full,0x756d090a35313338ull,0x2509203233662e6cull,
0x6625202c31363266ull,0x326625202c313332ull,0x6c756d090a3b3036ull,0x662509203233662eull,
0x326625202c323632ull,0x36326625202c3136ull,0x2e766f6d090a3b31ull,0x3266250920323366ull,
0x64336630202c3336ull,0x203b313735333430ull,0x2e30202f2f092020ull,0x0a35373732323330ull,
0x3233662e6c756d09ull,0x2c34363266250920ull,0x202c323332662520ull,0x090a3b3336326625ull,
0x203233662e6c756dull,0x202c353632662509ull,0x25202c3436326625ull,0x6d090a3b34363266ull,
0x09203233662e766full,0x30202c3636326625ull,0x3735333430643366ull,0x2f2f092020203b31ull,
0x37323233302e3020ull,0x2e6c756d090a3537ull,0x3266250920323366ull,0x35326625202c3736ull,
0x3636326625202c34ull,0x662e6c756d090a3bull,0x3632662509203233ull,0x3736326625202c38ull,
0x3b3736326625202cull,0x33662e766f6d090aull,0x3936326625092032ull,0x313863336630202cull,
0x2020203b39313162ull,0x31302e30202f2f09ull,0x6d090a3531333835ull,0x09203233662e6c75ull,
0x25202c3037326625ull,0x6625202c35353266ull,0x756d090a3b393632ull,0x2509203233662e6cull,
0x6625202c31373266ull,0x326625202c303732ull,0x766f6d090a3b3037ull,0x662509203233662eull,
0x336630202c323732ull,0x3b31373533343064ull,0x30202f2f09202020ull,0x353737323233302eull,
0x33662e6c756d090aull,0x3337326625092032ull,0x2c3635326625202cull,0x0a3b323732662520ull,
0x3233662e6c756d09ull,0x2c34373266250920ull,0x202c333732662520ull,0x090a3b3337326625ull,
0x203233662e6c756dull,0x202c353732662509ull,0x25202c3736326625ull,0x6d090a3b38353266ull,
0x09203233662e6c75ull,0x25202c3637326625ull,0x6625202c30373266ull,0x756d090a3b313632ull,
0x2509203233662e6cull,0x6625202c37373266ull,0x326625202c333732ull,0x6c756d090a3b3436ull,
0x662509203233662eull,0x326625202c383732ull,0x38316625202c3835ull,0x2e6c756d090a3b35ull,
0x3266250920323366ull,0x36326625202c3937ull,0x3438316625202c31ull,0x662e6c756d090a3bull,
0x3832662509203233ull,0x3436326625202c30ull,0x3b3338316625202cull,0x33662e6c756d090aull,
0x3138326625092032ull,0x2c3130326625202cull,0x0a3b373632662520ull,0x3233662e6c756d09ull,
0x2c32383266250920ull,0x202c323032662520ull,0x090a3b3037326625ull,0x203233662e6c756dull,
0x202c333832662509ull,0x25202c3330326625ull,0x2e090a3b33373266ull,0x3309363109636f6cull,
0x756d090a30093035ull,0x2509203233662e6cull,0x6625202c34383266ull,0x326625202c393931ull,
0x6c756d090a3b3637ull,0x662509203233662eull,0x316625202c353832ull,0x37326625202c3939ull,
0x2e6c756d090a3b35ull,0x3266250920323366ull,0x39316625202c3638ull,0x3737326625202c39ull,
0x662e6c756d090a3bull,0x3832662509203233ull,0x3030326625202c37ull,0x3b3236326625202cull,
0x33662e6c756d090aull,0x3838326625092032ull,0x2c3030326625202cull,0x0a3b393532662520ull,
0x3233662e6c756d09ull,0x2c39383266250920ull,0x202c303032662520ull,0x090a3b3536326625ull,
0x203233662e627573ull,0x202c303932662509ull,0x25202c3438326625ull,0x73090a3b39373266ull,
0x09203233662e6275ull,0x25202c3139326625ull,0x6625202c35383266ull,0x7573090a3b383732ull,
0x2509203233662e62ull,0x6625202c32393266ull,0x326625202c363832ull,0x6c756d090a3b3038ull,
0x662509203233662eull,0x326625202c333932ull,0x37326625202c3530ull,0x2e6c756d090a3b31ull,
0x3266250920323366ull,0x30326625202c3439ull,0x3836326625202c35ull,0x662e6c756d090a3bull,
0x3932662509203233ull,0x3530326625202c35ull,0x3b3437326625202cull,0x33662e627573090aull,
0x3639326625092032ull,0x2c3039326625202cull,0x0a3b323832662520ull,0x3233662e62757309ull,
0x2c37393266250920ull,0x202c313932662520ull,0x090a3b3138326625ull,0x203233662e627573ull,
0x202c383932662509ull,0x25202c3239326625ull,0x61090a3b33383266ull,0x09203233662e6464ull,
0x25202c3939326625ull,0x6625202c37383266ull,0x6461090a3b333932ull,0x2509203233662e64ull,
0x6625202c30303366ull,0x326625202c383832ull,0x646461090a3b3439ull,0x662509203233662eull,
0x326625202c313033ull,0x39326625202c3938ull,0x2e646461090a3b35ull,0x3366250920323366ull,
0x39326625202c3230ull,0x3639326625202c36ull,0x662e646461090a3bull,0x3033662509203233ull,
0x3739326625202c33ull,0x3b3739326625202cull,0x33662e646461090aull,0x3430336625092032ull,
0x2c3839326625202cull,0x0a3b383932662520ull,0x3233662e64646109ull,0x2c35303366250920ull,
0x202c393932662520ull,0x090a3b3230336625ull,0x203233662e646461ull,0x202c363033662509ull,
0x25202c3030336625ull,0x61090a3b33303366ull,0x09203233662e6464ull,0x25202c3730336625ull,
0x6625202c31303366ull,0x646c090a3b343033ull,0x662e74736e6f632eull,0x3033662509203233ull,
0x6c6f436b5b202c38ull,0x63697274654d726full,0x756d090a3b5d342bull,0x2509203233662e6cull,
0x6625202c39303366ull,0x336625202c383033ull,0x2e646c090a3b3530ull,0x33662e74736e6f63ull,
0x3031336625092032ull,0x6f6c6f436b5b202cull,0x2b63697274654d72ull,0x64616d090a3b5d30ull,
0x662509203233662eull,0x336625202c313133ull,0x31336625202c3630ull,0x3930336625202c30ull,
0x6f632e646c090a3bull,0x203233662e74736eull,0x202c323133662509ull,0x4d726f6c6f436b5bull,
0x5d382b6369727465ull,0x662e64616d090a3bull,0x3133662509203233ull,0x3730336625202c33ull,
0x2c3231336625202cull,0x0a3b313133662520ull,0x3233662e766f6d09ull,0x2c34313366250920ull,
0x3833656433663020ull,0x092020203b393365ull,0x3131312e30202f2full,0x6c756d090a313131ull,
0x662509203233662eull,0x336625202c353133ull,0x31336625202c3331ull,0x70746573090a3b34ull,
0x203233662e746c2eull,0x25202c3031702509ull,0x6625202c35313366ull,0x2140090a3b323831ull,
0x6172622030317025ull,0x5f305f744c240920ull,0x200a3b3037373233ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353235ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x2e090a3837393033ull,0x3309363109636f6cull,
0x6f6d090a30093435ull,0x2509203233662e76ull,0x6625202c32383166ull,0x6c2e090a3b353133ull,
0x353309363109636full,0x766f6d090a300935ull,0x722509203233732eull,0x36367225202c3239ull,
0x09636f6c2e090a3bull,0x3009363533093631ull,0x31752e747663090aull,0x2509203233752e36ull,
0x387225202c326872ull,0x636f6c2e090a3b34ull,0x0937353309363109ull,0x752e747663090a30ull,
0x09203233752e3631ull,0x7225202c33687225ull,0x5f744c240a3b3139ull,0x3a30373732335f30ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3532352065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a38373930335f30ull,
0x363109636f6c2e09ull,0x090a300931343309ull,0x203233732e646461ull,0x25202c3336722509ull,
0x3b3436202c333672ull,0x33752e766f6d090aull,0x2c33397225092032ull,0x090a3b3432303120ull,
0x2e656e2e70746573ull,0x3170250920323373ull,0x2c33367225202c31ull,0x090a3b3339722520ull,
0x7262203131702540ull,0x305f744c24092061ull,0x0a3b38373930335full,0x35325f305f744c24ull,
0x636f6c2e090a3a38ull,0x0939353309363109ull,0x752e747663090a30ull,0x09203631752e3233ull,
0x7225202c34397225ull,0x747663090a3b3368ull,0x3631752e3233752eull,0x202c353972250920ull,
0x73090a3b32687225ull,0x752e656c2e707465ull,0x3231702509203233ull,0x202c34397225202cull,
0x40090a3b35397225ull,0x6172622032317025ull,0x5f305f744c240920ull,0x090a3b3833353333ull,
0x09363109636f6c2eull,0x6f6d090a30093237ull,0x2509203233732e76ull,0x397225202c363972ull,
0x636f6c2e090a3b34ull,0x3009333709363109ull,0x33732e766f6d090aull,0x2c34397225092032ull,
0x090a3b3539722520ull,0x09363109636f6c2eull,0x6f6d090a30093437ull,0x2509203233732e76ull,
0x397225202c353972ull,0x636f6c2e090a3b36ull,0x0934363309363109ull,0x732e766f6d090a30ull,
0x3739722509203233ull,0x0a3b32397225202cull,0x3233622e726f7809ull,0x202c383972250920ull,
0x3431202c37397225ull,0x3536373535363133ull,0x732e766f6d090a3bull,0x3239722509203233ull,
0x0a3b38397225202cull,0x33335f305f744c24ull,0x6f6d090a3a383335ull,0x2509203233732e76ull,
0x0a3b30202c393972ull,0x3436752e766f6d09ull,0x2c34356472250920ull,0x3b3373646f727020ull,
0x36752e766f6d090aull,0x3535647225092034ull,0x546168706c61202cull,0x240a3b33656c6261ull,
0x3534335f305f744cull,0x3c2f2f200a3a3236ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,
0x34363320656e696cull,0x6e697473656e202cull,0x3a68747065642067ull,0x69747365202c3120ull,
0x746920646574616dull,0x736e6f6974617265ull,0x6f6c2e090a33203aull,0x3037330936310963ull,
0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x25202c3030317225ull,0x3b3436202c393972ull,
0x33732e646461090aull,0x3130317225092032ull,0x2c3030317225202cull,0x6d090a3b31722520ull,
0x09203233752e766full,0x31202c3230317225ull,0x746573090a3b3935ull,0x3233732e74672e70ull,
0x202c333170250920ull,0x25202c3130317225ull,0x40090a3b32303172ull,0x6172622033317025ull,
0x5f305f744c240920ull,0x2f2f200a3b343135ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x363320656e696c20ull,0x2064616568202c34ull,0x2064656c6562616cull,
0x34335f305f744c24ull,0x6f6c2e090a323635ull,0x3337330936310963ull,0x2e747663090a3009ull,
0x203233732e343675ull,0x202c363564722509ull,0x090a3b3130317225ull,0x752e6f6c2e6c756dull,
0x3564722509203436ull,0x3635647225202c37ull,0x6461090a3b34202cull,0x2509203436752e64ull,
0x7225202c38356472ull,0x647225202c313464ull,0x2e646c090a3b3735ull,0x752e646572616873ull,
0x3031722509203233ull,0x356472255b202c33ull,0x2e090a3b5d302b38ull,0x3309363109636f6cull,
0x6f6d090a30093437ull,0x2509203233732e76ull,0x3b30202c34303172ull,0x36732e766f6d090aull,
0x3935647225092034ull,0x0a3b33647225202cull,0x3233732e766f6d09ull,0x2c35303172250920ull,
0x766f6d090a3b3020ull,0x662509203233662eull,0x306630202c363133ull,0x3b30303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x3731336625092032ull,0x303030306630202cull,
0x2020203b30303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,0x30202c3831336625ull,
0x3030303030303066ull,0x2f2f092020203b30ull,0x305f744c240a3020ull,0x0a3a30333335335full,
0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,0x656e202c34373320ull,
0x656420676e697473ull,0x202c31203a687470ull,0x6f69746172657469ull,0x090a3631203a736eull,
0x09363109636f6c2eull,0x6c090a3009333733ull,0x6465726168732e64ull,0x722509203233752eull,
0x72255b202c333031ull,0x0a3b5d302b383564ull,0x363109636f6c2e09ull,0x090a300934383209ull,
0x203233752e726873ull,0x202c363031722509ull,0x25202c3330317225ull,0x61090a3b34303172ull,
0x09203233622e646eull,0x25202c3730317225ull,0x3b33202c36303172ull,0x36752e747663090aull,
0x2509203233752e34ull,0x7225202c30366472ull,0x756d090a3b373031ull,0x3436752e6f6c2e6cull,
0x2c31366472250920ull,0x202c303664722520ull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x36647225202c3236ull,0x3535647225202c31ull,0x6f632e646c090a3bull,0x203233662e74736eull,
0x202c393133662509ull,0x302b32366472255bull,0x732e646c090a3b5dull,0x33662e6465726168ull,
0x3032336625092032ull,0x39356472255b202cull,0x646c090a3b5d302bull,0x2e6465726168732eull,
0x3366250920323366ull,0x6472255b202c3132ull,0x090a3b5d342b3935ull,0x65726168732e646cull,
0x2509203233662e64ull,0x255b202c32323366ull,0x3b5d382b39356472ull,0x33662e64616d090aull,
0x3831336625092032ull,0x2c3931336625202cull,0x202c303233662520ull,0x090a3b3831336625ull,
0x203233662e64616dull,0x202c373133662509ull,0x25202c3931336625ull,0x6625202c31323366ull,
0x616d090a3b373133ull,0x2509203233662e64ull,0x6625202c36313366ull,0x336625202c393133ull,
0x31336625202c3232ull,0x636f6c2e090a3b36ull,0x0935383209363109ull,0x752e646461090a30ull,
0x3664722509203436ull,0x3136647225202c33ull,0x3b3435647225202cull,0x6e6f632e646c090aull,
0x09203233732e7473ull,0x5b202c3830317225ull,0x5d302b3336647225ull,0x732e646461090a3bull,
0x3031722509203233ull,0x3830317225202c35ull,0x3b3530317225202cull,0x36752e646461090aull,
0x3935647225092034ull,0x2c3935647225202cull,0x6461090a3b323120ull,0x2509203233732e64ull,
0x7225202c34303172ull,0x0a3b32202c343031ull,0x3233752e766f6d09ull,0x2c39303172250920ull,
0x6573090a3b323320ull,0x33732e656e2e7074ull,0x2c34317025092032ull,0x202c343031722520ull,
0x090a3b3930317225ull,0x7262203431702540ull,0x305f744c24092061ull,0x0a3b30333335335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34363320ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a32363534335full,
0x09363109636f6c2eull,0x61090a3009323233ull,0x09203233622e646eull,0x25202c3031317225ull,
0x3532202c35303172ull,0x2e726873090a3b35ull,0x3172250920323373ull,0x30317225202c3131ull,
0x090a3b3631202c35ull,0x203233732e726873ull,0x202c323131722509ull,0x38202c3530317225ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x2c33323366250920ull,0x616475635f5f5b20ull,
0x363531736d75735full,0x6d090a3b5d302b30ull,0x09203233662e766full,0x30202c3432336625ull,
0x3030303038303466ull,0x2f2f092020203b30ull,0x2e6c756d090a3420ull,0x3366250920323366ull,
0x32336625202c3532ull,0x3432336625202c33ull,0x68732e646c090a3bull,0x3233662e64657261ull,
0x2c36323366250920ull,0x616475635f5f5b20ull,0x363531736d75735full,0x6d090a3b5d342b30ull,
0x09203233662e766full,0x30202c3732336625ull,0x3030303038303466ull,0x2f2f092020203b30ull,
0x2e6c756d090a3420ull,0x3366250920323366ull,0x32336625202c3832ull,0x3732336625202c36ull,
0x68732e646c090a3bull,0x3233662e64657261ull,0x2c39323366250920ull,0x616475635f5f5b20ull,
0x363531736d75735full,0x6d090a3b5d382b30ull,0x09203233662e766full,0x30202c3033336625ull,
0x3030303038303466ull,0x2f2f092020203b30ull,0x2e6c756d090a3420ull,0x3366250920323366ull,
0x32336625202c3133ull,0x3033336625202c39ull,0x722e747663090a3bull,0x33732e3233662e6eull,
0x3233336625092032ull,0x3b3031317225202cull,0x6e722e747663090aull,0x3233732e3233662eull,
0x2c33333366250920ull,0x0a3b313131722520ull,0x3233622e646e6109ull,0x2c33313172250920ull,
0x202c323131722520ull,0x7573090a3b353532ull,0x2509203233662e62ull,0x6625202c34333366ull,
0x336625202c353233ull,0x627573090a3b3831ull,0x662509203233662eull,0x336625202c353333ull,
0x31336625202c3832ull,0x2e627573090a3b37ull,0x3366250920323366ull,0x33336625202c3633ull,
0x3631336625202c31ull,0x662e6c756d090a3bull,0x3333662509203233ull,0x3233336625202c37ull,
0x3b3233336625202cull,0x6e722e747663090aull,0x3233732e3233662eull,0x2c38333366250920ull,
0x0a3b333131722520ull,0x3233662e6c756d09ull,0x2c39333366250920ull,0x202c323333662520ull,
0x090a3b3433336625ull,0x203233662e6c756dull,0x202c303433662509ull,0x25202c3233336625ull,
0x6d090a3b35333366ull,0x09203233662e6c75ull,0x25202c3134336625ull,0x6625202c32333366ull,
0x756d090a3b363333ull,0x2509203233662e6cull,0x6625202c32343366ull,0x336625202c333333ull,
0x627573090a3b3833ull,0x662509203233662eull,0x336625202c333433ull,0x33336625202c3234ull,
0x2e6c756d090a3b37ull,0x3366250920323366ull,0x33336625202c3434ull,0x3831336625202c38ull,
0x662e6c756d090a3bull,0x3433662509203233ull,0x3833336625202c35ull,0x3b3731336625202cull,
0x33662e6c756d090aull,0x3634336625092032ull,0x2c3833336625202cull,0x0a3b363133662520ull,
0x7070612e70637209ull,0x203233662e786f72ull,0x202c373433662509ull,0x090a3b3334336625ull,
0x203233662e627573ull,0x202c383433662509ull,0x25202c3434336625ull,0x73090a3b39333366ull,
0x09203233662e6275ull,0x25202c3934336625ull,0x6625202c35343366ull,0x7573090a3b303433ull,
0x2509203233662e62ull,0x6625202c30353366ull,0x336625202c363433ull,0x6c756d090a3b3134ull,
0x662509203233662eull,0x336625202c313533ull,0x34336625202c3734ull,0x2e6c756d090a3b38ull,
0x3366250920323366ull,0x34336625202c3235ull,0x3934336625202c37ull,0x662e6c756d090a3bull,
0x3533662509203233ull,0x3734336625202c33ull,0x3b3035336625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3435336625092032ull,0x3b3135336625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3535336625092032ull,0x3b3235336625202cull,0x61732e747663090aull,
0x33662e3233662e74ull,0x3635336625092032ull,0x3b3335336625202cull,0x33662e766f6d090aull,
0x3735336625092032ull,0x386631346630202cull,0x2020203b30303030ull,0x090a3133202f2f09ull,
0x203233662e6c756dull,0x202c383533662509ull,0x25202c3435336625ull,0x6d090a3b37353366ull,
0x09203233662e766full,0x30202c3935336625ull,0x3030306337323466ull,0x2f2f092020203b30ull,
0x6c756d090a333620ull,0x662509203233662eull,0x336625202c303633ull,0x35336625202c3535ull,
0x2e766f6d090a3b39ull,0x3366250920323366ull,0x31346630202c3136ull,0x203b303030303866ull,
0x3133202f2f092020ull,0x33662e6c756d090aull,0x3236336625092032ull,0x2c3635336625202cull,
0x0a3b313633662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c33363366250920ull,
0x0a3b383533662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c34363366250920ull,
0x0a3b303633662520ull,0x696e722e74766309ull,0x3233662e3233662eull,0x2c35363366250920ull,
0x0a3b323633662520ull,0x697a722e74766309ull,0x3233662e3233752eull,0x2c34313172250920ull,
0x0a3b333633662520ull,0x3233622e6c687309ull,0x2c35313172250920ull,0x202c343131722520ull,
0x747663090a3b3131ull,0x3233752e697a722eull,0x722509203233662eull,0x336625202c363131ull,
0x6c6873090a3b3436ull,0x722509203233622eull,0x317225202c373131ull,0x090a3b35202c3631ull,
0x09203233622e726full,0x25202c3831317225ull,0x7225202c35313172ull,0x7663090a3b373131ull,
0x33752e697a722e74ull,0x2509203233662e32ull,0x6625202c39313172ull,0x726f090a3b353633ull,
0x722509203233622eull,0x317225202c303231ull,0x31317225202c3831ull,0x2e747663090a3b39ull,
0x203233752e363175ull,0x202c313231722509ull,0x090a3b3032317225ull,0x09363109636f6c2eull,
0x6d090a3009333233ull,0x09203233662e6c75ull,0x25202c3636336625ull,0x6625202c32333366ull,
0x756d090a3b383133ull,0x2509203233662e6cull,0x6625202c37363366ull,0x336625202c323333ull,
0x6c756d090a3b3731ull,0x662509203233662eull,0x336625202c383633ull,0x31336625202c3233ull,
0x2e6c756d090a3b36ull,0x3366250920323366ull,0x33336625202c3936ull,0x3433336625202c33ull,
0x662e6c756d090a3bull,0x3733662509203233ull,0x3333336625202c30ull,0x3b3533336625202cull,
0x33662e6c756d090aull,0x3137336625092032ull,0x2c3333336625202cull,0x0a3b363333662520ull,
0x3233662e62757309ull,0x2c32373366250920ull,0x202c393633662520ull,0x090a3b3636336625ull,
0x203233662e627573ull,0x202c333733662509ull,0x25202c3037336625ull,0x73090a3b37363366ull,
0x09203233662e6275ull,0x25202c3437336625ull,0x6625202c31373366ull,0x756d090a3b383633ull,
0x2509203233662e6cull,0x6625202c35373366ull,0x336625202c323733ull,0x6c756d090a3b3734ull,
0x662509203233662eull,0x336625202c363733ull,0x34336625202c3337ull,0x2e6c756d090a3b37ull,
0x3366250920323366ull,0x37336625202c3737ull,0x3734336625202c34ull,0x732e747663090a3bull,
0x662e3233662e7461ull,0x3733662509203233ull,0x3537336625202c38ull,0x732e747663090a3bull,
0x662e3233662e7461ull,0x3733662509203233ull,0x3637336625202c39ull,0x732e747663090a3bull,
0x662e3233662e7461ull,0x3833662509203233ull,0x3737336625202c30ull,0x662e766f6d090a3bull,
0x3833662509203233ull,0x6631346630202c31ull,0x20203b3030303038ull,0x0a3133202f2f0920ull,
0x3233662e6c756d09ull,0x2c32383366250920ull,0x202c383733662520ull,0x090a3b3138336625ull,
0x203233662e766f6dull,0x202c333833662509ull,0x3030633732346630ull,0x2f092020203b3030ull,
0x756d090a3336202full,0x2509203233662e6cull,0x6625202c34383366ull,0x336625202c393733ull,
0x766f6d090a3b3338ull,0x662509203233662eull,0x346630202c353833ull,0x3b30303030386631ull,
0x33202f2f09202020ull,0x662e6c756d090a31ull,0x3833662509203233ull,0x3038336625202c36ull,
0x3b3538336625202cull,0x6e722e747663090aull,0x33662e3233662e69ull,0x3738336625092032ull,
0x3b3238336625202cull,0x6e722e747663090aull,0x33662e3233662e69ull,0x3838336625092032ull,
0x3b3438336625202cull,0x6e722e747663090aull,0x33662e3233662e69ull,0x3938336625092032ull,
0x3b3638336625202cull,0x7a722e747663090aull,0x33662e3233752e69ull,0x3232317225092032ull,
0x3b3738336625202cull,0x33622e6c6873090aull,0x3332317225092032ull,0x2c3232317225202cull,
0x7663090a3b313120ull,0x33752e697a722e74ull,0x2509203233662e32ull,0x6625202c34323172ull,
0x6873090a3b383833ull,0x2509203233622e6cull,0x7225202c35323172ull,0x0a3b35202c343231ull,
0x203233622e726f09ull,0x202c363231722509ull,0x25202c3332317225ull,0x63090a3b35323172ull,
0x752e697a722e7476ull,0x09203233662e3233ull,0x25202c3732317225ull,0x6f090a3b39383366ull,
0x2509203233622e72ull,0x7225202c38323172ull,0x317225202c363231ull,0x747663090a3b3732ull,
0x3233752e3631752eull,0x2c39323172250920ull,0x0a3b383231722520ull,0x363109636f6c2e09ull,
0x090a300936323309ull,0x203233662e766f6dull,0x202c303933662509ull,0x3533343064336630ull,
0x2f092020203b3137ull,0x323233302e30202full,0x6c756d090a353737ull,0x662509203233662eull,
0x336625202c313933ull,0x39336625202c3336ull,0x2e6c756d090a3b30ull,0x3366250920323366ull,
0x39336625202c3239ull,0x3139336625202c31ull,0x662e766f6d090a3bull,0x3933662509203233ull,
0x3863336630202c33ull,0x20203b3931316231ull,0x302e30202f2f0920ull,0x090a353133383531ull,
0x203233662e6c756dull,0x202c343933662509ull,0x25202c3436336625ull,0x6d090a3b33393366ull,
0x09203233662e6c75ull,0x25202c3539336625ull,0x6625202c34393366ull,0x6f6d090a3b343933ull,
0x2509203233662e76ull,0x6630202c36393366ull,0x3137353334306433ull,0x202f2f092020203bull,
0x3737323233302e30ull,0x662e6c756d090a35ull,0x3933662509203233ull,0x3536336625202c37ull,
0x3b3639336625202cull,0x33662e6c756d090aull,0x3839336625092032ull,0x2c3739336625202cull,
0x0a3b373933662520ull,0x3233662e766f6d09ull,0x2c39393366250920ull,0x3334306433663020ull,
0x092020203b313735ull,0x3233302e30202f2full,0x756d090a35373732ull,0x2509203233662e6cull,
0x6625202c30303466ull,0x336625202c373833ull,0x6c756d090a3b3939ull,0x662509203233662eull,
0x346625202c313034ull,0x30346625202c3030ull,0x2e766f6d090a3b30ull,0x3466250920323366ull,
0x63336630202c3230ull,0x203b393131623138ull,0x2e30202f2f092020ull,0x0a35313338353130ull,
0x3233662e6c756d09ull,0x2c33303466250920ull,0x202c383833662520ull,0x090a3b3230346625ull,
0x203233662e6c756dull,0x202c343034662509ull,0x25202c3330346625ull,0x6d090a3b33303466ull,
0x09203233662e766full,0x30202c3530346625ull,0x3735333430643366ull,0x2f2f092020203b31ull,
0x37323233302e3020ull,0x2e6c756d090a3537ull,0x3466250920323366ull,0x38336625202c3630ull,
0x3530346625202c39ull,0x662e6c756d090a3bull,0x3034662509203233ull,0x3630346625202c37ull,
0x3b3630346625202cull,0x33662e6c756d090aull,0x3830346625092032ull,0x2c3030346625202cull,
0x0a3b313933662520ull,0x3233662e6c756d09ull,0x2c39303466250920ull,0x202c333034662520ull,
0x090a3b3439336625ull,0x203233662e6c756dull,0x202c303134662509ull,0x25202c3630346625ull,
0x6d090a3b37393366ull,0x09203233662e6c75ull,0x25202c3131346625ull,0x6625202c31393366ull,
0x756d090a3b383133ull,0x2509203233662e6cull,0x6625202c32313466ull,0x336625202c343933ull,
0x6c756d090a3b3731ull,0x662509203233662eull,0x336625202c333134ull,0x31336625202c3739ull,
0x2e6c756d090a3b36ull,0x3466250920323366ull,0x33336625202c3431ull,0x3030346625202c34ull,
0x662e6c756d090a3bull,0x3134662509203233ull,0x3533336625202c35ull,0x3b3330346625202cull,
0x33662e6c756d090aull,0x3631346625092032ull,0x2c3633336625202cull,0x0a3b363034662520ull,
0x363109636f6c2e09ull,0x090a300934373309ull,0x203233662e6c756dull,0x202c373134662509ull,
0x25202c3233336625ull,0x6d090a3b39303466ull,0x09203233662e6c75ull,0x25202c3831346625ull,
0x6625202c32333366ull,0x756d090a3b383034ull,0x2509203233662e6cull,0x6625202c39313466ull,
0x346625202c323333ull,0x6c756d090a3b3031ull,0x662509203233662eull,0x336625202c303234ull,
0x39336625202c3333ull,0x2e6c756d090a3b35ull,0x3466250920323366ull,0x33336625202c3132ull,
0x3239336625202c33ull,0x662e6c756d090a3bull,0x3234662509203233ull,0x3333336625202c32ull,
0x3b3839336625202cull,0x33662e627573090aull,0x3332346625092032ull,0x2c3731346625202cull,
0x0a3b323134662520ull,0x3233662e62757309ull,0x2c34323466250920ull,0x202c383134662520ull,
0x090a3b3131346625ull,0x203233662e627573ull,0x202c353234662509ull,0x25202c3931346625ull,
0x6d090a3b33313466ull,0x09203233662e6c75ull,0x25202c3632346625ull,0x6625202c38333366ull,
0x756d090a3b343034ull,0x2509203233662e6cull,0x6625202c37323466ull,0x346625202c383333ull,
0x6c756d090a3b3130ull,0x662509203233662eull,0x336625202c383234ull,0x30346625202c3833ull,
0x2e627573090a3b37ull,0x3466250920323366ull,0x32346625202c3932ull,0x3531346625202c33ull,
0x662e627573090a3bull,0x3334662509203233ull,0x3432346625202c30ull,0x3b3431346625202cull,
0x33662e627573090aull,0x3133346625092032ull,0x2c3532346625202cull,0x0a3b363134662520ull,
0x3233662e64646109ull,0x2c32333466250920ull,0x202c303234662520ull,0x090a3b3632346625ull,
0x203233662e646461ull,0x202c333334662509ull,0x25202c3132346625ull,0x61090a3b37323466ull,
0x09203233662e6464ull,0x25202c3433346625ull,0x6625202c32323466ull,0x6461090a3b383234ull,
0x2509203233662e64ull,0x6625202c35333466ull,0x346625202c393234ull,0x646461090a3b3932ull,
0x662509203233662eull,0x346625202c363334ull,0x33346625202c3033ull,0x2e646461090a3b30ull,
0x3466250920323366ull,0x33346625202c3733ull,0x3133346625202c31ull,0x662e646461090a3bull,
0x3334662509203233ull,0x3233346625202c38ull,0x3b3533346625202cull,0x33662e646461090aull,
0x3933346625092032ull,0x2c3333346625202cull,0x0a3b363334662520ull,0x3233662e64646109ull,
0x2c30343466250920ull,0x202c343334662520ull,0x090a3b3733346625ull,0x74736e6f632e646cull,
0x662509203233662eull,0x436b5b202c313434ull,0x7274654d726f6c6full,0x090a3b5d342b6369ull,
0x203233662e6c756dull,0x202c323434662509ull,0x25202c3134346625ull,0x6c090a3b38333466ull,
0x2e74736e6f632e64ull,0x3466250920323366ull,0x6f436b5b202c3334ull,0x697274654d726f6cull,
0x6d090a3b5d302b63ull,0x09203233662e6461ull,0x25202c3434346625ull,0x6625202c39333466ull,
0x346625202c333434ull,0x2e646c090a3b3234ull,0x33662e74736e6f63ull,0x3534346625092032ull,
0x6f6c6f436b5b202cull,0x2b63697274654d72ull,0x64616d090a3b5d38ull,0x662509203233662eull,
0x346625202c363434ull,0x34346625202c3034ull,0x3434346625202c35ull,0x662e766f6d090a3bull,
0x3434662509203233ull,0x3865336630202c37ull,0x20203b3030303030ull,0x322e30202f2f0920ull,
0x662e6c756d090a35ull,0x3434662509203233ull,0x3634346625202c38ull,0x3b3734346625202cull,
0x6c2e70746573090aull,0x2509203233662e74ull,0x346625202c353170ull,0x38316625202c3834ull,
0x70252140090a3b32ull,0x0920617262203531ull,0x36335f305f744c24ull,0x2f2f200a3b343533ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x363320656e696c20ull,
0x2064616568202c34ull,0x2064656c6562616cull,0x34335f305f744c24ull,0x6f6c2e090a323635ull,
0x3837330936310963ull,0x2e766f6d090a3009ull,0x3166250920323366ull,0x34346625202c3238ull,
0x636f6c2e090a3b38ull,0x0933373309363109ull,0x68732e646c090a30ull,0x3233752e64657261ull,
0x2c33303172250920ull,0x2b38356472255b20ull,0x6f6c2e090a3b5d30ull,0x3937330936310963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x30317225202c3033ull,0x636f6c2e090a3b33ull,
0x0930383309363109ull,0x732e766f6d090a30ull,0x3539722509203233ull,0x3b3132317225202cull,
0x3109636f6c2e090aull,0x0a30093138330936ull,0x3233732e766f6d09ull,0x202c343972250920ull,
0x090a3b3932317225ull,0x2e656c2e70746573ull,0x3170250920323375ull,0x3132317225202c36ull,
0x3b3932317225202cull,0x203631702540090aull,0x744c240920617262ull,0x30313636335f305full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c34363320656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x32363534335f305full,
0x3109636f6c2e090aull,0x090a300932370936ull,0x203233732e766f6dull,0x202c313331722509ull,
0x2e090a3b34397225ull,0x3709363109636f6cull,0x766f6d090a300933ull,0x722509203233732eull,
0x35397225202c3439ull,0x09636f6c2e090a3bull,0x0a30093437093631ull,0x3233732e766f6d09ull,
0x202c353972250920ull,0x090a3b3133317225ull,0x09363109636f6c2eull,0x6c090a3009333733ull,
0x6465726168732e64ull,0x722509203233752eull,0x72255b202c333031ull,0x0a3b5d302b383564ull,
0x363109636f6c2e09ull,0x090a300936383309ull,0x203233622e746f6eull,0x202c323331722509ull,
0x090a3b3330317225ull,0x203233752e726873ull,0x202c333331722509ull,0x31202c3233317225ull,
0x622e646e61090a3bull,0x3331722509203233ull,0x3333317225202c34ull,0x353631333431202cull,
0x78090a3b35363735ull,0x09203233622e726full,0x25202c3533317225ull,0x7225202c33303172ull,
0x6f6d090a3b343331ull,0x2509203233732e76ull,0x317225202c323972ull,0x617262090a3b3533ull,
0x4c240920696e752eull,0x353336335f305f74ull,0x305f744c240a3b34ull,0x0a3a30313636335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c34363320ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x090a32363534335full,
0x203233732e766f6dull,0x25202c3239722509ull,0x4c240a3b30333172ull,0x353336335f305f74ull,
0x305f744c240a3a34ull,0x0a3a32343835335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c34363320ull,0x6c6562616c206461ull,
0x305f744c24206465ull,0x090a32363534335full,0x09363109636f6c2eull,0x61090a3009373633ull,
0x09203233732e6464ull,0x7225202c39397225ull,0x090a3b31202c3939ull,0x203233752e766f6dull,
0x202c363331722509ull,0x70746573090a3b33ull,0x203233732e656e2eull,0x25202c3731702509ull,
0x317225202c393972ull,0x702540090a3b3633ull,0x0920617262203731ull,0x34335f305f744c24ull,
0x744c240a3b323635ull,0x0a3a3431355f305full,0x363109636f6c2e09ull,0x090a300931393309ull,
0x203436752e766f6dull,0x202c343664722509ull,0x655f616475635f5full,0x31383173726f7272ull,
0x2e646461090a3b36ull,0x6472250920343675ull,0x32647225202c3536ull,0x3b3436647225202cull,
0x6168732e7473090aull,0x203233662e646572ull,0x2b35366472255b09ull,0x38316625202c5d30ull,
0x636f6c2e090a3b32ull,0x0933303409363109ull,0x752e766f6d090a30ull,0x3664722509203436ull,
0x6369646e69202c36ull,0x090a3b315f5f7365ull,0x203436752e646461ull,0x202c373664722509ull,
0x7225202c32647225ull,0x7473090a3b363664ull,0x2e6465726168732eull,0x72255b0920323373ull,
0x202c5d302b373664ull,0x6c2e090a3b317225ull,0x333409363109636full,0x726162090a300939ull,
0x300920636e79732eull,0x752e766f6d090a3bull,0x3331722509203233ull,0x090a3b3133202c37ull,
0x2e74672e70746573ull,0x3170250920323373ull,0x202c317225202c38ull,0x090a3b3733317225ull,
0x7262203831702540ull,0x305f744c24092061ull,0x0a3b32343232345full,0x726168732e646c09ull,
0x09203233662e6465ull,0x5b202c3934346625ull,0x5d302b3536647225ull,0x68732e646c090a3bull,
0x3233662e64657261ull,0x2c30353466250920ull,0x2b35366472255b20ull,0x73090a3b5d383231ull,
0x662e74672e707465ull,0x3931702509203233ull,0x2c3934346625202cull,0x0a3b303534662520ull,
0x2039317025214009ull,0x744c240920617262ull,0x32383639335f305full,0x68732e646c090a3bull,
0x3233662e64657261ull,0x2c30353466250920ull,0x2b35366472255b20ull,0x2e090a3b5d383231ull,
0x3409363109636f6cull,0x6f6d090a30093534ull,0x2509203233662e76ull,0x6625202c39343466ull,
0x7473090a3b303534ull,0x2e6465726168732eull,0x72255b0920323366ull,0x202c5d302b353664ull,
0x090a3b3035346625ull,0x09363109636f6c2eull,0x6c090a3009363434ull,0x6465726168732e64ull,
0x722509203233732eull,0x72255b202c383331ull,0x5d3832312b373664ull,0x68732e7473090a3bull,
0x3233732e64657261ull,0x37366472255b0920ull,0x317225202c5d302bull,0x5f744c240a3b3833ull,
0x3a32383639335f30ull,0x6168732e646c090aull,0x203233662e646572ull,0x202c313534662509ull,
0x362b35366472255bull,0x746573090a3b5d34ull,0x3233662e74672e70ull,0x202c303270250920ull,
0x25202c3934346625ull,0x40090a3b31353466ull,0x7262203032702521ull,0x305f744c24092061ull,
0x0a3b34393130345full,0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3135346625ull,
0x34362b3536647225ull,0x636f6c2e090a3b5dull,0x0939343409363109ull,0x662e766f6d090a30ull,
0x3434662509203233ull,0x3135346625202c39ull,0x68732e7473090a3bull,0x3233662e64657261ull,
0x35366472255b0920ull,0x346625202c5d302bull,0x6f6c2e090a3b3135ull,0x3035340936310963ull,
0x732e646c090a3009ull,0x33732e6465726168ull,0x3933317225092032ull,0x37366472255b202cull,
0x73090a3b5d34362bull,0x6465726168732e74ull,0x255b09203233732eull,0x2c5d302b37366472ull,
0x0a3b393331722520ull,0x30345f305f744c24ull,0x646c090a3a343931ull,0x2e6465726168732eull,
0x3466250920323366ull,0x6472255b202c3235ull,0x0a3b5d32332b3536ull,0x74672e7074657309ull,
0x702509203233662eull,0x34346625202c3132ull,0x3235346625202c39ull,0x3270252140090a3bull,
0x2409206172622031ull,0x3730345f305f744cull,0x2e646c090a3b3630ull,0x662e646572616873ull,
0x3534662509203233ull,0x366472255b202c32ull,0x090a3b5d32332b35ull,0x09363109636f6c2eull,
0x6d090a3009333534ull,0x09203233662e766full,0x25202c3934346625ull,0x73090a3b32353466ull,
0x6465726168732e74ull,0x255b09203233662eull,0x2c5d302b35366472ull,0x0a3b323534662520ull,
0x363109636f6c2e09ull,0x090a300934353409ull,0x65726168732e646cull,0x2509203233732e64ull,
0x255b202c30343172ull,0x5d32332b37366472ull,0x68732e7473090a3bull,0x3233732e64657261ull,
0x37366472255b0920ull,0x317225202c5d302bull,0x5f744c240a3b3034ull,0x3a36303730345f30ull,
0x6168732e646c090aull,0x203233662e646572ull,0x202c333534662509ull,0x312b35366472255bull,
0x746573090a3b5d36ull,0x3233662e74672e70ull,0x202c323270250920ull,0x25202c3934346625ull,
0x40090a3b33353466ull,0x7262203232702521ull,0x305f744c24092061ull,0x0a3b38313231345full,
0x726168732e646c09ull,0x09203233662e6465ull,0x5b202c3335346625ull,0x36312b3536647225ull,
0x636f6c2e090a3b5dull,0x0937353409363109ull,0x662e766f6d090a30ull,0x3434662509203233ull,
0x3335346625202c39ull,0x68732e7473090a3bull,0x3233662e64657261ull,0x35366472255b0920ull,
0x346625202c5d302bull,0x6f6c2e090a3b3335ull,0x3835340936310963ull,0x732e646c090a3009ull,
0x33732e6465726168ull,0x3134317225092032ull,0x37366472255b202cull,0x73090a3b5d36312bull,
0x6465726168732e74ull,0x255b09203233732eull,0x2c5d302b37366472ull,0x0a3b313431722520ull,
0x31345f305f744c24ull,0x646c090a3a383132ull,0x2e6465726168732eull,0x3466250920323366ull,
0x6472255b202c3435ull,0x090a3b5d382b3536ull,0x2e74672e70746573ull,0x3270250920323366ull,
0x3934346625202c33ull,0x3b3435346625202cull,0x333270252140090aull,0x4c24092061726220ull,
0x333731345f305f74ull,0x732e646c090a3b30ull,0x33662e6465726168ull,0x3435346625092032ull,
0x35366472255b202cull,0x6c2e090a3b5d382bull,0x363409363109636full,0x766f6d090a300931ull,
0x662509203233662eull,0x346625202c393434ull,0x2e7473090a3b3435ull,0x662e646572616873ull,
0x6472255b09203233ull,0x25202c5d302b3536ull,0x2e090a3b34353466ull,0x3409363109636f6cull,
0x646c090a30093236ull,0x2e6465726168732eull,0x3172250920323373ull,0x6472255b202c3234ull,
0x090a3b5d382b3736ull,0x65726168732e7473ull,0x5b09203233732e64ull,0x5d302b3736647225ull,
0x3b3234317225202cull,0x345f305f744c240aull,0x6c090a3a30333731ull,0x6465726168732e64ull,
0x662509203233662eull,0x72255b202c353534ull,0x0a3b5d342b353664ull,0x74672e7074657309ull,
0x702509203233662eull,0x34346625202c3432ull,0x3535346625202c39ull,0x3270252140090a3bull,
0x2409206172622034ull,0x3232345f305f744cull,0x6f6c2e090a3b3234ull,0x3536340936310963ull,
0x732e7473090a3009ull,0x33662e6465726168ull,0x366472255b092032ull,0x6625202c5d302b35ull,
0x6c2e090a3b353534ull,0x363409363109636full,0x2e646c090a300936ull,0x732e646572616873ull,
0x3431722509203233ull,0x366472255b202c33ull,0x73090a3b5d342b37ull,0x6465726168732e74ull,
0x255b09203233732eull,0x2c5d302b37366472ull,0x0a3b333431722520ull,0x32345f305f744c24ull,
0x744c240a3a323432ull,0x30373139335f305full,0x09636f6c2e090a3aull,0x3009313734093631ull,
0x79732e726162090aull,0x090a3b300920636eull,0x65726168732e646cull,0x2509203233732e64ull,
0x695b202c34343172ull,0x5f5f73656369646eull,0x2e090a3b5d302b31ull,0x3509363109636f6cull,
0x6162090a30093033ull,0x0920636e79732e72ull,0x70746573090a3b30ull,0x203233732e656e2eull,
0x25202c3532702509ull,0x7225202c34343172ull,0x32702540090a3b31ull,0x2409206172622035ull,
0x3732345f305f744cull,0x6f6c2e090a3b3435ull,0x3439340936310963ull,0x70746573090a3009ull,
0x203233752e71652eull,0x25202c3632702509ull,0x397225202c343972ull,0x2e766f6d090a3b35ull,
0x3172250920323375ull,0x090a3b30202c3534ull,0x203233732e766f6dull,0x202c363431722509ull,
0x73090a3b32397225ull,0x203233752e706c65ull,0x202c373431722509ull,0x25202c3534317225ull,
0x7025202c36343172ull,0x2e646c090a3b3632ull,0x732e646572616873ull,0x3431722509203233ull,
0x75635f5f5b202c38ull,0x73666572785f6164ull,0x3b5d302b32353731ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c393431ull,0x090a3b32202c3834ull,0x203233752e726873ull,
0x202c303531722509ull,0x25202c3734317225ull,0x61090a3b39343172ull,0x09203233622e646eull,
0x25202c3135317225ull,0x3b33202c30353172ull,0x6168732e646c090aull,0x203233732e646572ull,
0x202c323531722509ull,0x5f616475635f5f5bull,0x3537317366657278ull,0x6d090a3b5d342b32ull,
0x33732e6f6c2e6c75ull,0x3335317225092032ull,0x2c3235317225202cull,0x726873090a3b3220ull,
0x722509203233752eull,0x317225202c343531ull,0x35317225202c3734ull,0x2e646e61090a3b33ull,
0x3172250920323362ull,0x35317225202c3535ull,0x73090a3b33202c34ull,0x09203233622e6c68ull,
0x25202c3635317225ull,0x3b32202c35353172ull,0x3233622e726f090aull,0x2c37353172250920ull,
0x202c313531722520ull,0x090a3b3635317225ull,0x65726168732e646cull,0x2509203233732e64ull,
0x5f5b202c38353172ull,0x72785f616475635full,0x2b32353731736665ull,0x6c756d090a3b5d38ull,
0x203233732e6f6c2eull,0x202c393531722509ull,0x32202c3835317225ull,0x752e726873090a3bull,
0x3631722509203233ull,0x3734317225202c30ull,0x3b3935317225202cull,0x33622e646e61090aull,
0x3136317225092032ull,0x2c3036317225202cull,0x6c6873090a3b3320ull,0x722509203233622eull,
0x317225202c323631ull,0x090a3b34202c3136ull,0x65726168732e646cull,0x2509203233732e64ull,
0x5f5b202c33363172ull,0x72785f616475635full,0x2b32353731736665ull,0x756d090a3b5d3231ull,
0x3233732e6f6c2e6cull,0x2c34363172250920ull,0x202c333631722520ull,0x2e726873090a3b32ull,
0x3172250920323375ull,0x34317225202c3536ull,0x3436317225202c37ull,0x622e646e61090a3bull,
0x3631722509203233ull,0x3536317225202c36ull,0x6873090a3b33202cull,0x2509203233622e6cull,
0x7225202c37363172ull,0x0a3b36202c363631ull,0x203233622e726f09ull,0x202c383631722509ull,
0x25202c3236317225ull,0x6f090a3b37363172ull,0x2509203233622e72ull,0x7225202c39363172ull,
0x317225202c373531ull,0x2e646c090a3b3836ull,0x732e646572616873ull,0x3731722509203233ull,
0x75635f5f5b202c30ull,0x73666572785f6164ull,0x5d36312b32353731ull,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c31373172ull,0x0a3b32202c303731ull,0x3233752e72687309ull,
0x2c32373172250920ull,0x202c373431722520ull,0x090a3b3137317225ull,0x203233622e646e61ull,
0x202c333731722509ull,0x33202c3237317225ull,0x622e6c6873090a3bull,0x3731722509203233ull,
0x3337317225202c34ull,0x646c090a3b38202cull,0x2e6465726168732eull,0x3172250920323373ull,
0x635f5f5b202c3537ull,0x666572785f616475ull,0x30322b3235373173ull,0x2e6c756d090a3b5dull,
0x09203233732e6f6cull,0x25202c3637317225ull,0x3b32202c35373172ull,0x33752e726873090aull,
0x3737317225092032ull,0x2c3734317225202cull,0x0a3b363731722520ull,0x3233622e646e6109ull,
0x2c38373172250920ull,0x202c373731722520ull,0x2e6c6873090a3b33ull,0x3172250920323362ull,
0x37317225202c3937ull,0x090a3b3031202c38ull,0x09203233622e726full,0x25202c3038317225ull,
0x7225202c34373172ull,0x726f090a3b393731ull,0x722509203233622eull,0x317225202c313831ull,
0x38317225202c3936ull,0x732e646c090a3b30ull,0x33732e6465726168ull,0x3238317225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d34322b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c333831ull,0x090a3b32202c3238ull,0x203233752e726873ull,
0x202c343831722509ull,0x25202c3734317225ull,0x61090a3b33383172ull,0x09203233622e646eull,
0x25202c3538317225ull,0x3b33202c34383172ull,0x33622e6c6873090aull,0x3638317225092032ull,
0x2c3538317225202cull,0x646c090a3b323120ull,0x2e6465726168732eull,0x3172250920323373ull,
0x635f5f5b202c3738ull,0x666572785f616475ull,0x38322b3235373173ull,0x2e6c756d090a3b5dull,
0x09203233732e6f6cull,0x25202c3838317225ull,0x3b32202c37383172ull,0x33752e726873090aull,
0x3938317225092032ull,0x2c3734317225202cull,0x0a3b383831722520ull,0x3233622e646e6109ull,
0x2c30393172250920ull,0x202c393831722520ull,0x2e6c6873090a3b33ull,0x3172250920323362ull,
0x39317225202c3139ull,0x090a3b3431202c30ull,0x09203233622e726full,0x25202c3239317225ull,
0x7225202c36383172ull,0x726f090a3b313931ull,0x722509203233622eull,0x317225202c333931ull,
0x39317225202c3138ull,0x732e646c090a3b32ull,0x33732e6465726168ull,0x3439317225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d32332b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c353931ull,0x090a3b32202c3439ull,0x203233752e726873ull,
0x202c363931722509ull,0x25202c3734317225ull,0x61090a3b35393172ull,0x09203233622e646eull,
0x25202c3739317225ull,0x3b33202c36393172ull,0x33622e6c6873090aull,0x3839317225092032ull,
0x2c3739317225202cull,0x726f090a3b363120ull,0x722509203233622eull,0x317225202c333931ull,
0x39317225202c3339ull,0x732e646c090a3b38ull,0x33732e6465726168ull,0x3939317225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d36332b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x317225202c303032ull,0x090a3b32202c3939ull,0x203233752e726873ull,
0x202c313032722509ull,0x25202c3734317225ull,0x61090a3b30303272ull,0x09203233622e646eull,
0x25202c3230327225ull,0x3b33202c31303272ull,0x33622e6c6873090aull,0x3330327225092032ull,
0x2c3230327225202cull,0x726f090a3b383120ull,0x722509203233622eull,0x317225202c333931ull,
0x30327225202c3339ull,0x732e646c090a3b33ull,0x33732e6465726168ull,0x3430327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d30342b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c353032ull,0x090a3b32202c3430ull,0x203233752e726873ull,
0x202c363032722509ull,0x25202c3734317225ull,0x61090a3b35303272ull,0x09203233622e646eull,
0x25202c3730327225ull,0x3b33202c36303272ull,0x33622e6c6873090aull,0x3830327225092032ull,
0x2c3730327225202cull,0x726f090a3b303220ull,0x722509203233622eull,0x317225202c333931ull,
0x30327225202c3339ull,0x732e646c090a3b38ull,0x33732e6465726168ull,0x3930327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d34342b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c303132ull,0x090a3b32202c3930ull,0x203233752e726873ull,
0x202c313132722509ull,0x25202c3734317225ull,0x61090a3b30313272ull,0x09203233622e646eull,
0x25202c3231327225ull,0x3b33202c31313272ull,0x33622e6c6873090aull,0x3331327225092032ull,
0x2c3231327225202cull,0x726f090a3b323220ull,0x722509203233622eull,0x317225202c333931ull,
0x31327225202c3339ull,0x732e646c090a3b33ull,0x33732e6465726168ull,0x3431327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d38342b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c353132ull,0x090a3b32202c3431ull,0x203233752e726873ull,
0x202c363132722509ull,0x25202c3734317225ull,0x61090a3b35313272ull,0x09203233622e646eull,
0x25202c3731327225ull,0x3b33202c36313272ull,0x33622e6c6873090aull,0x3831327225092032ull,
0x2c3731327225202cull,0x726f090a3b343220ull,0x722509203233622eull,0x317225202c333931ull,
0x31327225202c3339ull,0x732e646c090a3b38ull,0x33732e6465726168ull,0x3931327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d32352b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c303232ull,0x090a3b32202c3931ull,0x203233752e726873ull,
0x202c313232722509ull,0x25202c3734317225ull,0x61090a3b30323272ull,0x09203233622e646eull,
0x25202c3232327225ull,0x3b33202c31323272ull,0x33622e6c6873090aull,0x3332327225092032ull,
0x2c3232327225202cull,0x726f090a3b363220ull,0x722509203233622eull,0x317225202c333931ull,
0x32327225202c3339ull,0x732e646c090a3b33ull,0x33732e6465726168ull,0x3432327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d36352b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c353232ull,0x090a3b32202c3432ull,0x203233752e726873ull,
0x202c363232722509ull,0x25202c3734317225ull,0x61090a3b35323272ull,0x09203233622e646eull,
0x25202c3732327225ull,0x3b33202c36323272ull,0x33622e6c6873090aull,0x3832327225092032ull,
0x2c3732327225202cull,0x726f090a3b383220ull,0x722509203233622eull,0x317225202c333931ull,
0x32327225202c3339ull,0x732e646c090a3b38ull,0x33732e6465726168ull,0x3932327225092032ull,
0x6475635f5f5b202cull,0x3173666572785f61ull,0x3b5d30362b323537ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x327225202c303332ull,0x090a3b32202c3932ull,0x203233752e726873ull,
0x202c313332722509ull,0x25202c3734317225ull,0x73090a3b30333272ull,0x09203233622e6c68ull,
0x25202c3233327225ull,0x3033202c31333272ull,0x33622e726f090a3bull,0x3339317225092032ull,
0x2c3339317225202cull,0x0a3b323332722520ull,0x363109636f6c2e09ull,0x090a300938393409ull,
0x6d617261702e646cull,0x722509203436752eull,0x5f5f5b202c383664ull,0x6d72617061647563ull,
0x706d6f63385a5f5full,0x536a4b5073736572ull,0x746e697535505f30ull,0x746c757365725f32ull,
0x2e747663090a3b5dull,0x203631752e323373ull,0x202c333332722509ull,0x782e646961746325ull,
0x752e747663090a3bull,0x09203233732e3436ull,0x25202c3936647225ull,0x6d090a3b33333272ull,
0x36752e6f6c2e6c75ull,0x3037647225092034ull,0x2c3936647225202cull,0x646461090a3b3820ull,
0x722509203436752eull,0x647225202c313764ull,0x37647225202c3836ull,0x2e6c6873090a3b30ull,
0x3272250920323362ull,0x34397225202c3433ull,0x6f090a3b3631202cull,0x2509203233622e72ull,
0x7225202c35333272ull,0x33327225202c3539ull,0x672e7473090a3b34ull,0x32762e6c61626f6cull,
0x255b09203233752eull,0x2c5d302b31376472ull,0x2c35333272257b20ull,0x0a3b7d3339317225ull,
0x32345f305f744c24ull,0x6c2e090a3a343537ull,0x333509363109636full,0x697865090a300937ull,
0x6557444c240a3b74ull,0x6f63385a5f5f646eull,0x4b5073736572706dull,0x697535505f30536aull,
0x207d090a3a32746eull,0x6f63385a5f202f2full,0x4b5073736572706dull,0x697535505f30536aull,
0x0000000a0a32746eull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"603ac090b57baad6",(char*)"dxtc.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xb0c12441};
# 5 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.stub.c" 2




struct __T20 {const uint *__par0;const uint *__par1;uint2 *__par2;int __dummy_field;};
static void __sti____cudaRegisterAll_39_tmpxft_0000641b_00000000_7_dxtc_cpp1_ii_b480a5a9(void) __attribute__((__constructor__));
void __device_stub__Z8compressPKjS0_P5uint2(const uint *__par0, const uint *__par1, uint2 *__par2){auto struct __T20 *__T2328;
*(void**)(void*)&__T2328 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2328->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2328->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2328->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(const uint *, const uint *, uint2 *))compress__entry)); (void)cudaLaunch(((char *)((void ( *)(const uint *, const uint *, uint2 *))compress__entry))); };}

}
void compress__entry( const uint *__cuda_0,const uint *__cuda_1,uint2 *__cuda_2)
{__device_stub__Z8compressPKjS0_P5uint2( __cuda_0,__cuda_1,__cuda_2);}
extern "C"{
# 29 "/tmp/tmpxft_0000641b_00000000-1_dxtc.cudafe1.stub.c"
static void __sti____cudaRegisterAll_39_tmpxft_0000641b_00000000_7_dxtc_cpp1_ii_b480a5a9(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(const uint *, const uint *, uint2 *))compress__entry), (char*)"_Z8compressPKjS0_P5uint2", "_Z8compressPKjS0_P5uint2", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&kColorMetric__cuda_shadow_variable__, (char*)"kColorMetric", "kColorMetric", 0, 12, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable4__cuda_shadow_variable__, (char*)"alphaTable4", "alphaTable4", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&alphaTable3__cuda_shadow_variable__, (char*)"alphaTable3", "alphaTable3", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods4__cuda_shadow_variable__, (char*)"prods4", "prods4", 0, 16, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&prods3__cuda_shadow_variable__, (char*)"prods3", "prods3", 0, 16, 1, 0);}

}
# 854 "dxtc.cu" 2

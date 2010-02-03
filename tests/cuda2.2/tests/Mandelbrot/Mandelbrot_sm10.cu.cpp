# 1 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.cpp"
# 1 "Mandelbrot_sm10.cu"
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
extern "C" void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw();




extern "C" void *memmove(void *, const void *, size_t) throw();
# 56 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 64 "/usr/include/string.h" 3
extern "C" void *memset(void *, int, size_t) throw();


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
# 420 "/usr/local/cuda/bin/../include/math_functions.h"
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



extern "C" int __signbit(double) throw() __attribute__((__const__));




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



extern "C" int __signbitf(float) throw() __attribute__((__const__));




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



extern "C" int __signbitl(long double) throw() __attribute__((__const__));




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
# 444 "/usr/local/cuda/bin/../include/math_functions.h"
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




inline void cutilDeviceInit(int ARGC, char **ARGV)
{
auto int deviceCount;
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "../../sdk/cutil_inline_runtime.h", 148);
if (deviceCount == 0) {
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
exit(-1);
}
auto int dev = 0;
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }

auto cudaDeviceProp deviceProp;
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "../../sdk/cutil_inline_runtime.h", 158);
if ((deviceProp.major) < 1) {
fprintf(stderr, "cutil error: device does not support CUDA.\n");
exit(-1); }

if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
__cudaSafeCall(cudaSetDevice(dev), "../../sdk/cutil_inline_runtime.h", 165);
}




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
# 54 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
{
cuDevice = 0;
auto int deviceCount = 0;
auto CUresult err = cuInit(0);
if ((CUDA_SUCCESS) == err) {
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "../../sdk/cutil_inline_drvapi.h", 60); }
if (deviceCount == 0) {
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
exit(-1);
}
auto int dev = 0;
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
if (dev < 0) { dev = 0; }
if (dev > (deviceCount - 1)) { dev = deviceCount - 1; }
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "../../sdk/cutil_inline_drvapi.h", 69);
auto char name[100];
cuDeviceGetName(name, 100, cuDevice);
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
fprintf(stderr, "Using device %d: %s\n", dev, name); }
}



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
printf("CUDA %d.%02d Toolkit built this project.\n", 2030 / 1000, 2030 % 100);
printf("  [ %s ] requirements:\n", sSDKsample);
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
}
# 6 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);


extern "C" void RunMandelbrot1_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);



extern "C" void RunMandelbrot0_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);


extern "C" void RunMandelbrot1_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);



extern "C" int inEmulationMode();
# 15 "Mandelbrot_kernel.cu"
inline void dsdeq(float &a0, float &a1, double b)
{
a0 = (float)b;
a1 = (float)(b - a0);
}
# 440 "Mandelbrot_kernel.cu"
inline int iDivUp(int a, int b)
{
return ((a % b) != 0) ? (a / b + 1) : (a / b);
}
# 7 "Mandelbrot_sm10.cu"
template<class T> static void
__wrapper__device_stub_Mandelbrot0_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
animationFrame, const bool &isJ);
# 7 "Mandelbrot_sm10.cu"
template<class T> void
Mandelbrot0_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
animationFrame, const bool isJ){__wrapper__device_stub_Mandelbrot0_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,isJ);}
# 53 "Mandelbrot_sm10.cu"
void MandelbrotDS0_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float
yOff0, const float yOff1, const float xJP, const float yJP, const float scale, const uchar4
colors, const int frame, const int animationFrame, const bool isJ);
# 102 "Mandelbrot_sm10.cu"
template<class T> static void
__wrapper__device_stub_Mandelbrot1_sm10(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
animationFrame, const bool &isJ);
# 102 "Mandelbrot_sm10.cu"
template<class T> void
Mandelbrot1_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
animationFrame, const bool isJ){__wrapper__device_stub_Mandelbrot1_sm10<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,isJ);}
# 158 "Mandelbrot_sm10.cu"
void MandelbrotDS1_sm10__entry(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float
xOff0, const float xOff1, const float yOff0, const float yOff1, const float
xJP, const float yJP, const float scale, const uchar4 colors, const int
frame, const int animationFrame, const bool isJ);
# 218 "Mandelbrot_sm10.cu"
void RunMandelbrot0_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const float
xjp, const float yjp, const double scale, const uchar4 colors, const int frame, const int animationFrame, const int
mode, const bool isJ)
{
auto dim3 threads(16, 16);
auto dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));

switch (mode) {
default:
case 0:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10__entry< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);

break;
case 1:
auto float x0; auto float x1; auto float y0; auto float y1;
dsdeq(x0, x1, xOff);
dsdeq(y0, y1, yOff);
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS0_sm10__entry(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);

break;
case 2:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot0_sm10__entry< double> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, isJ);

break;
}

}


void RunMandelbrot1_sm10(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const float
xjp, const float yjp, const double scale, const uchar4 colors, const int
frame, const int animationFrame, const int mode, const bool isJ)
{
auto dim3 threads(16, 16);
auto dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));

switch (mode) {
default:
case 0:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10__entry< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);

break;
case 1:
auto float x0; auto float x1; auto float y0; auto float y1;
dsdeq(x0, x1, xOff);
dsdeq(y0, y1, yOff);
cudaConfigureCall(grid, threads) ? ((void)0) : MandelbrotDS1_sm10__entry(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, isJ);

break;
case 2:
cudaConfigureCall(grid, threads) ? ((void)0) : (Mandelbrot1_sm10__entry< double> )(dst, imageW, imageH, crunch, xOff, yOff, yjp, yjp, scale, colors, frame, animationFrame, isJ);

break;
}

__cutilCheckMsg("Mandelbrot1_sm10 kernel execution failed.\n", "Mandelbrot_sm10.cu", 273);
}

# 1 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 1

extern "C" {

# 1 "/tmp/tmpxft_000068e2_00000000-6_Mandelbrot_sm10.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000068e2_00000000-6_Mandelbrot_sm10.fatbin.c" 2




extern "C" {


static const unsigned long long __deviceText_$sm_13$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d33315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x2065646f630a7d6eull,
0x20656d616e090a7bull,0x614d36315a5f203dull,0x746f72626c65646eull,0x644930316d735f31ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,
0x206d656d6c090a62ull,0x656d73090a30203dull,0x090a3339203d206dull,0x32203d2020676572ull,
0x2020726162090a32ull,0x6e6f63090a30203dull,0x0909090a7b207473ull,0x20656d616e676573ull,
0x0a74736e6f63203dull,0x756e676573090909ull,0x090a31203d20206dull,0x74657366666f0909ull,
0x09090a30203d2020ull,0x2020736574796209ull,0x09090a3231203d20ull,0x09090a7b206d656dull,
0x3030303030783009ull,0x3030783020666633ull,0x3020613030303030ull,0x3030303030303078ull,
0x090a7d09090a2031ull,0x6f636e6962090a7dull,0x3009090a7b206564ull,0x3032303038306478ull,
0x3034303078302035ull,0x3178302030383730ull,0x2039303430303030ull,0x3734303030347830ull,
0x783009090a203038ull,0x6430323030303061ull,0x3030303430783020ull,0x3031783020303837ull,
0x3020353032303030ull,0x3837343030303478ull,0x61783009090a2030ull,0x2039303030303030ull,
0x3730303034307830ull,0x3030367830203038ull,0x7830203530653432ull,0x3038376330323030ull,
0x3036783009090a20ull,0x3020393063343130ull,0x3837383032303078ull,0x3130303378302030ull,
0x3678302064666663ull,0x2038633730313263ull,0x303033783009090aull,0x7830206466646332ull,
0x3863323031326336ull,0x3030303033783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303178300909ull,0x3478302031306330ull,0x2030383763303034ull,0x3030333030347830ull,
0x3030307830206430ull,0x090a203038373030ull,0x3032303036783009ull,0x3030783020643032ull,
0x3020303837633030ull,0x3036303031303378ull,0x3031346378302064ull,0x09090a2030383730ull,
0x3030323030367830ull,0x3030307830203130ull,0x7830203038376330ull,0x3130303030303032ull,
0x3830303430783020ull,0x3009090a20303837ull,0x3030303230303378ull,0x3031346378302064ull,
0x3278302030383730ull,0x2064323863303030ull,0x3763303234307830ull,0x783009090a203038ull,
0x6430363165303064ull,0x3030633038783020ull,0x3033783020303837ull,0x3020313136303830ull,
0x3837303031346578ull,0x33783009090a2030ull,0x2064663530633730ull,0x3763303063367830ull,
0x3030617830203863ull,0x7830203330306432ull,0x3030303030303030ull,0x3061783009090a20ull,
0x3020313263303030ull,0x3837383030343078ull,0x3030306178302030ull,0x3078302039326530ull,
0x2030383738303034ull,0x303061783009090aull,0x7830203532303130ull,0x3038373830303430ull,
0x6332303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x6333303278300909ull,
0x3078302064303639ull,0x2066666666666666ull,0x3630653030647830ull,0x6330387830206430ull,
0x090a203038373030ull,0x3038303033783009ull,0x3465783020313136ull,0x3020303837303031ull,
0x3163303030306178ull,0x3030343078302035ull,0x09090a2030383738ull,0x3031303030617830ull,
0x3034307830203131ull,0x7830203038373830ull,0x3431613838343032ull,0x3839343032783020ull,
0x3009090a20383138ull,0x3065303030306178ull,0x3030343078302064ull,0x6178302030383738ull,
0x2031316130303030ull,0x3734313134307830ull,0x783009090a203038ull,0x3531633030303061ull,
0x3431313430783020ull,0x3032783020303837ull,0x3020643036303034ull,0x3837383230343078ull,
0x33783009090a2030ull,0x2031313830313830ull,0x3730313463367830ull,0x3830337830203038ull,
0x7830203531613031ull,0x3038373031346336ull,0x3061783009090a20ull,0x3020643036303030ull,
0x3837343131343078ull,0x3530306478302030ull,0x3078302031313830ull,0x2030383734303034ull,
0x383033783009090aull,0x7830206430363031ull,0x3038373031346336ull,0x3034303064783020ull,
0x3430783020643036ull,0x0a20303837343030ull,0x3030306178300909ull,0x3278302064303630ull,
0x2030383734313063ull,0x3064323030317830ull,0x3030307830203330ull,0x090a203038373030ull,
0x6630303031783009ull,0x3630783020643038ull,0x3020303837633330ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x3034343030617830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3131343831303032ull,0x3030303030783020ull,0x3009090a20333030ull,
0x6664633430303378ull,0x3032633678302064ull,0x3178302038633763ull,0x2033303034343030ull,
0x3230303030307830ull,0x783009090a203038ull,0x3131363934303032ull,0x3030303030783020ull,
0x3064783020333030ull,0x3020313138306530ull,0x3837303063303878ull,0x33783009090a2030ull,
0x2035313830383030ull,0x3730303134657830ull,0x3030617830203038ull,0x7830203931303130ull,
0x3038373830303430ull,0x3061783009090a20ull,0x3020353134313030ull,0x3837383030343078ull,
0x3834303278302030ull,0x3278302038316338ull,0x2063316138393430ull,0x303061783009090aull,
0x7830203131323130ull,0x3038373830303430ull,0x3030303061783020ull,0x3430783020353163ull,
0x0a20303837343131ull,0x3030306178300909ull,0x3078302039316530ull,0x2030383734313134ull,
0x3830303430327830ull,0x3034307830203131ull,0x090a203038373832ull,0x3031383033783009ull,
0x6336783020353161ull,0x3020303837303134ull,0x3163303138303378ull,0x3134633678302039ull,
0x09090a2030383730ull,0x3830303030617830ull,0x3134307830203131ull,0x7830203038373431ull,
0x3531613036303064ull,0x3430303430783020ull,0x3009090a20303837ull,0x3138303138303378ull,
0x3134633678302031ull,0x6478302030383730ull,0x2031313830353030ull,0x3734303034307830ull,
0x783009090a203038ull,0x3131383030303061ull,0x3431306332783020ull,0x3032783020303837ull,
0x3020643036303030ull,0x3837303130343078ull,0x33783009090a2030ull,0x2064663330633730ull,
0x3763303063367830ull,0x3030617830206163ull,0x7830203330306235ull,0x3030303030303030ull,
0x3031783009090a20ull,0x3020333030623530ull,0x3832303030303078ull,0x3030303378302030ull,
0x3078302031316363ull,0x2030383730303234ull,0x303033783009090aull,0x7830203131383032ull,
0x3038373030313463ull,0x6330303032783020ull,0x3430783020313138ull,0x0a20303837303132ull,
0x6530306478300909ull,0x3878302031313830ull,0x2030383730306330ull,0x3830383030337830ull,
0x3134657830203931ull,0x090a203038373030ull,0x3130303061783009ull,0x3430783020353130ull,
0x3020303837383030ull,0x3138313030306178ull,0x3030343078302039ull,0x09090a2030383738ull,
0x6138383430327830ull,0x3430327830203431ull,0x7830203831633839ull,0x3131323130303061ull,
0x3830303430783020ull,0x3009090a20303837ull,0x3161303030306178ull,0x3131343078302035ull,
0x6178302030383734ull,0x2039316330303030ull,0x3734313134307830ull,0x783009090a203038ull,
0x3131383030343032ull,0x3832303430783020ull,0x3033783020303837ull,0x3020353161303138ull,
0x3837303134633678ull,0x33783009090a2030ull,0x2039316330313830ull,0x3730313463367830ull,
0x3030617830203038ull,0x7830203131383030ull,0x3038373431313430ull,0x3064783009090a20ull,
0x3020353161303630ull,0x3837343030343078ull,0x3138303378302030ull,0x3678302031313830ull,
0x2030383730313463ull,0x303064783009090aull,0x7830203131383035ull,0x3038373430303430ull,
0x3030303061783020ull,0x6332783020313138ull,0x0a20303837343130ull,0x3030303278300909ull,
0x3078302064303630ull,0x2030383730313034ull,0x3030303030667830ull,0x3030657830203130ull,
0x090a203230303030ull,0x3437303061783009ull,0x3030783020333030ull,0x3020303030303030ull,
0x3132383130303278ull,0x3030303078302031ull,0x09090a2033303030ull,0x6663343030337830ull,
0x3263367830206466ull,0x7830203863376330ull,0x3330303437303031ull,0x3030303030783020ull,
0x3009090a20303832ull,0x3063633030303278ull,0x3032343078302031ull,0x3378302030383730ull,
0x2031303030323030ull,0x3730303134637830ull,0x783009090a203038ull,0x3130386330303032ull,
0x3030323430783020ull,0x3064783020303837ull,0x3020313030306530ull,0x3837303063303878ull,
0x33783009090a2030ull,0x2035313030383030ull,0x3730303134657830ull,0x3030617830203038ull,
0x7830203131303030ull,0x3038373830303430ull,0x3061783009090a20ull,0x3020353134313030ull,
0x3837383030343078ull,0x3834303278302030ull,0x3278302030313838ull,0x2034316138393430ull,
0x303061783009090aull,0x7830203130323030ull,0x3038373830303430ull,0x3030303061783020ull,
0x3430783020313138ull,0x0a20303837343131ull,0x3030306178300909ull,0x3078302035316130ull,
0x2030383734313134ull,0x3030303430327830ull,0x3034307830203130ull,0x090a203038373832ull,
0x3031383033783009ull,0x6336783020313138ull,0x3020303837303134ull,0x3161303138303378ull,
0x3134633678302035ull,0x09090a2030383730ull,0x3030303030617830ull,0x3134307830203130ull,
0x7830203038373431ull,0x3131383035303064ull,0x3430303430783020ull,0x3009090a20303837ull,
0x3030303138303378ull,0x3134633678302031ull,0x6478302030383730ull,0x2031303030343030ull,
0x3734303034307830ull,0x783009090a203038ull,0x3130303030303061ull,0x3431306332783020ull,
0x3032783020303837ull,0x3020643036303030ull,0x3837303030343078ull,0x33783009090a2030ull,
0x2064663730633730ull,0x3738303063367830ull,0x3030337830206163ull,0x7830203330303030ull,
0x3038323030303030ull,0x3064783009090a20ull,0x3020353038623030ull,0x3837303030303278ull,
0x3030306178302030ull,0x3478302031333430ull,0x2030383730313434ull,0x303031783009090aull,
0x7830203930343230ull,0x3038376330303434ull,0x3230303031783020ull,0x3434783020643036ull,
0x0a20303837633030ull,0x3030313178300909ull,0x3178302038313466ull,0x2063313666303031ull,
0x3230303030617830ull,0x3434347830203131ull,0x090a203038373031ull,0x6630303131783009ull,
0x3131783020303038ull,0x3020343061663030ull,0x6631303030346178ull,0x3132633078302064ull,
0x09090a2038633738ull,0x3831323030657830ull,0x3030347830203133ull,0x7830203038373831ull,
0x3931343034303065ull,0x3030303034783020ull,0x3009090a20303837ull,0x3530313030303178ull,
0x3030343478302031ull,0x3178302030383763ull,0x2033303061383030ull,0x3130303030307830ull,
0x783009090a203030ull,0x3830636630303131ull,0x6630303131783020ull,0x3031783020633065ull,
0x3020313130323030ull,0x3837633030343478ull,0x31783009090a2030ull,0x2035313232303030ull,
0x3763303034347830ull,0x3030657830203038ull,0x7830203134633036ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020393438316330ull,0x3837303030303878ull,0x3030303178302030ull,
0x3178302030306338ull,0x2034306538323030ull,0x303031783009090aull,0x7830203833383930ull,
0x6333613932303031ull,0x3139303031783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3030303178300909ull,0x3078302031303038ull,0x2033303030303030ull,0x3038303030317830ull,
0x3030307830203530ull,0x090a203330303030ull,0x3830303031783009ull,0x3031783020383430ull,
0x3020633432383230ull,0x3430383030303178ull,0x3230303178302030ull,0x09090a2034343238ull,
0x3038303030317830ull,0x3030317830203833ull,0x7830206333323832ull,0x3830383930303031ull,
0x3932303031783020ull,0x3009090a20633061ull,0x3163383030303178ull,0x3230303178302030ull,
0x3478302034316538ull,0x2033303035643130ull,0x3030303030307830ull,0x783009090a203030ull,
0x6466316463373033ull,0x6330326336783020ull,0x3031783020386337ull,0x3020333030393930ull,
0x3832303030303078ull,0x65783009090a2030ull,0x2039313432303030ull,0x3730343030367830ull,
0x3030317830203038ull,0x7830203133303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020353330383030ull,0x3030303130343078ull,0x6330306578302033ull,0x6578302064666430ull,
0x2038633730313030ull,0x303031783009090aull,0x7830203330306239ull,0x3030313030303030ull,
0x3230303031783020ull,0x3430783020353538ull,0x0a20303837633330ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6331303030657830ull,0x3030387830203130ull,
0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,
0x3538616633303278ull,0x6666663078302035ull,0x09090a2066666666ull,0x3432303030657830ull,
0x3038367830203931ull,0x7830203038373034ull,0x3130383030303065ull,0x3030303036783020ull,
0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,
0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020333030616130ull,0x3832303030303078ull,
0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6261303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,0x3538616533303278ull,
0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,
0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,
0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020333030616230ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6262303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,
0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,
0x3036783020313030ull,0x3020303837303030ull,0x3538616433303278ull,0x6666663078302035ull,
0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,
0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,
0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,
0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,
0x3020333030616330ull,0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,
0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,
0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,
0x3863373031303065ull,0x6263303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,
0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,
0x3020303837303030ull,0x3538616333303278ull,0x6666663078302035ull,0x09090a2066666666ull,
0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,
0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,
0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,0x3020333030616430ull,
0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,
0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,
0x6264303031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,
0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,
0x3538616233303278ull,0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,
0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,
0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,
0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020333030616530ull,0x3832303030303078ull,
0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6265303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,0x3538616133303278ull,
0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,
0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,
0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020333030616630ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6266303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,
0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,
0x3036783020313030ull,0x3020303837303030ull,0x3538613933303278ull,0x6666663078302035ull,
0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,
0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,
0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,
0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,
0x3020333030613031ull,0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,
0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,
0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,
0x3863373031303065ull,0x6230313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,
0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,
0x3020303837303030ull,0x3538613833303278ull,0x6666663078302035ull,0x09090a2066666666ull,
0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,
0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,
0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,0x3020333030613131ull,
0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,
0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,
0x6231313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,
0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,
0x3538613733303278ull,0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,
0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,
0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,
0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020333030613231ull,0x3832303030303078ull,
0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6232313031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,0x3538613633303278ull,
0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,
0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,
0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020333030613331ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6233313031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,
0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,
0x3036783020313030ull,0x3020303837303030ull,0x3538613533303278ull,0x6666663078302035ull,
0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,
0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,
0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,
0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,
0x3020333030613431ull,0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,
0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,
0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,
0x3863373031303065ull,0x6234313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,
0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,
0x3020303837303030ull,0x3538613433303278ull,0x6666663078302035ull,0x09090a2066666666ull,
0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,
0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,
0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,0x3020333030613531ull,
0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,
0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,
0x6235313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,
0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,
0x3538613333303278ull,0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,
0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,
0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,
0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020333030613631ull,0x3832303030303078ull,
0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6236313031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,0x3538613233303278ull,
0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,
0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,
0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020333030613731ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6237313031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,
0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,
0x3036783020313030ull,0x3020303837303030ull,0x3538613133303278ull,0x6666663078302035ull,
0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,
0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,
0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,
0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,
0x3020333030613831ull,0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,
0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,
0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,
0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,
0x3863373031303065ull,0x6238313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,
0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,
0x3030387830203130ull,0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,
0x3020303837303030ull,0x3538613033303278ull,0x6666663078302035ull,0x09090a2066666666ull,
0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,
0x3030303036783020ull,0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,
0x6578302038633763ull,0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,
0x3133303030303065ull,0x3030303038783020ull,0x3031783020303837ull,0x3020333030613931ull,
0x3832303030303078ull,0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,
0x3030317830203038ull,0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020643430383030ull,0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,
0x2030383730333030ull,0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,
0x6239313031783020ull,0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,
0x090a203038373030ull,0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,
0x3538616632303278ull,0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,
0x3038367830203931ull,0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,
0x3009090a20303837ull,0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,
0x2039313430303030ull,0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,
0x3030303038783020ull,0x3031783020303837ull,0x3020333030616131ull,0x3832303030303078ull,
0x65783009090a2030ull,0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,
0x7830203934303830ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,
0x3030303130343078ull,0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,
0x313065783009090aull,0x7830206466313232ull,0x3863373031303065ull,0x6261313031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,
0x2030383730303030ull,0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,
0x3030303065783009ull,0x3036783020313030ull,0x3020303837303030ull,0x3538616532303278ull,
0x6666663078302035ull,0x09090a2066666666ull,0x6331303030657830ull,0x3038367830203931ull,
0x7830203038373033ull,0x3130383030303065ull,0x3030303036783020ull,0x3009090a20303837ull,
0x6662326337303378ull,0x3030633678302064ull,0x6578302038633763ull,0x2039313430303030ull,
0x3738313030367830ull,0x783009090a203038ull,0x3133303030303065ull,0x3030303038783020ull,
0x3031783020303837ull,0x3020333030616231ull,0x3832303030303078ull,0x65783009090a2030ull,
0x2039336330363030ull,0x3730303030387830ull,0x3030317830203038ull,0x7830203934303830ull,
0x3330303030303030ull,0x3031783009090a20ull,0x3020643430383030ull,0x3030303130343078ull,
0x3030306578302033ull,0x3678302031346331ull,0x2030383730333030ull,0x313065783009090aull,
0x7830206466313232ull,0x3863373031303065ull,0x6262313031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303578300909ull,0x3078302033303030ull,0x2030383730303030ull,
0x6330303030657830ull,0x3030387830203130ull,0x090a203038373030ull,0x6164323032783009ull,
0x6630783020313538ull,0x3020666666666666ull,0x3030303030306578ull,0x3030303678302031ull,
0x09090a2030383730ull,0x3832633730337830ull,0x3063367830203134ull,0x7830203064376330ull,
0x3931633130303065ull,0x3033303836783020ull,0x3009090a20303837ull,0x3038303030306578ull,
0x3030303678302031ull,0x6178302030383730ull,0x2064663132303030ull,0x3734313063307830ull,
0x783009090a203863ull,0x3931343030303065ull,0x3831303036783020ull,0x3065783020303837ull,
0x3020313330303030ull,0x3837303030303878ull,0x31783009090a2030ull,0x2033303062633130ull,
0x3231303030307830ull,0x3030657830203038ull,0x7830203933633036ull,0x3038373030303038ull,
0x3031783009090a20ull,0x3020393430383030ull,0x3030303030303078ull,0x3030303178302033ull,
0x3078302064343038ull,0x2033303030313034ull,0x303065783009090aull,0x7830203134633130ull,
0x3038373033303036ull,0x3232313065783020ull,0x3065783020646631ull,0x0a20386437303130ull,
0x6331303178300909ull,0x3078302033303064ull,0x2030303131303030ull,0x3832303030317830ull,
0x3036307830203535ull,0x090a203038376333ull,0x3030303035783009ull,0x3030783020333030ull,
0x3020303837303030ull,0x3063303030306578ull,0x3030303878302031ull,0x09090a2030383730ull,
0x6331303030657830ull,0x3038367830203931ull,0x7830203038373033ull,0x3130303030303065ull,
0x3030303036783020ull,0x3009090a20303837ull,0x3334303030306578ull,0x3130303678302039ull,
0x6578302030383738ull,0x2031303830303030ull,0x3730303030367830ull,0x783009090a203038ull,
0x3934633165303065ull,0x3030303038783020ull,0x3065783020303837ull,0x3020313430303030ull,
0x3837303030303878ull,0x31783009090a2030ull,0x2033303033393030ull,0x3730303030307830ull,
0x3730337830203038ull,0x7830203530613263ull,0x3038373031306336ull,0x3032783009090a20ull,
0x3020313030643034ull,0x3837343532343078ull,0x3130306478302030ull,0x3078302031303030ull,
0x2030383730303034ull,0x373033783009090aull,0x7830206466313063ull,0x3863373830306336ull,
0x6665313061783020ull,0x3030783020333030ull,0x0a20303030303030ull,0x6531303178300909ull,
0x3078302033303063ull,0x2030383230303030ull,0x3061303030647830ull,0x3030327830203530ull,
0x090a203038373030ull,0x6530303032783009ull,0x3430783020313063ull,0x3020303837303032ull,
0x3030303030346178ull,0x3032303078302039ull,0x09090a2030383738ull,0x3230303034617830ull,
0x3230307830203931ull,0x7830203038373830ull,0x6431343030303461ull,0x3830323030783020ull,
0x3009090a20303837ull,0x3032303230303478ull,0x3630303478302038ull,0x3478302030313230ull,
0x2035313230373030ull,0x3730303030307830ull,0x783009090a203038ull,0x3930343030313033ull,
0x3030313463783020ull,0x3033783020303837ull,0x3020313138303031ull,0x3837303031346378ull,
0x33783009090a2030ull,0x2035316130303130ull,0x3730303134637830ull,0x3030367830203038ull,
0x7830203530303032ull,0x3038373830303030ull,0x3036783009090a20ull,0x3020393030303630ull,
0x3837303130303078ull,0x3730303678302030ull,0x3078302064303030ull,0x2030383734313030ull,
0x303061783009090aull,0x7830203130323030ull,0x3038376330303430ull,0x3030303061783020ull,
0x3430783020353134ull,0x0a20303837633030ull,0x3030306178300909ull,0x3078302039313630ull,
0x2030383763303034ull,0x3066653130317830ull,0x3030307830203330ull,0x090a203038373030ull,
0x6630303031783009ull,0x3430783020393138ull,0x3020303837633330ull,0x3138663030303178ull,
0x3330363078302035ull,0x09090a2030383763ull,0x3866303030317830ull,0x3034307830203130ull,
0x7830203038376333ull,0x3530613230303031ull,0x6330303434783020ull,0x3009090a20323837ull,
0x3034303131303478ull,0x3030303078302064ull,0x3278302030383730ull,0x2039306165303031ull,
0x3738303634307830ull,0x783009090a203038ull,0x3131363030313036ull,0x6330303030783020ull,
0x3033783020303837ull,0x3020643034306631ull,0x3837303031636578ull,0x33783009090a2030ull,
0x2031313830303130ull,0x3730303134637830ull,0x3830647830203038ull,0x7830206430363032ull,
0x3038373030343430ull,0x3036783009090a20ull,0x3020313134303031ull,0x3837303130303078ull,
0x3230303278302030ull,0x3478302063303638ull,0x2030323430333130ull,0x303032783009090aull,
0x7830203130383030ull,0x3038373030303430ull,0x3031303033783020ull,0x6365783020643136ull,
0x0a20303837303031ull,0x3231303678300909ull,0x3078302031313630ull,0x2030383730323030ull,
0x3438323030317830ull,0x3030327830206330ull,0x090a203030653830ull,0x3030313033783009ull,
0x3463783020313138ull,0x3020303837303031ull,0x3030323132303278ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3430353130347830ull,0x3030307830203132ull,0x7830203038373030ull,
0x6430343032313036ull,0x3031303030783020ull,0x3009090a20303837ull,0x3130303030303178ull,
0x3330343078302031ull,0x3678302030383763ull,0x2031323630343130ull,0x3730323030307830ull,
0x783009090a203038ull,0x3030363835303032ull,0x3832303031783020ull,0x3033783020633034ull,
0x3020353130313031ull,0x3837303031346378ull,0x32783009090a2030ull,0x2031306530303030ull,
0x3730303034307830ull,0x3130367830203038ull,0x7830203530343034ull,0x3038373431303030ull,
0x3032783009090a20ull,0x3020333030323132ull,0x3837303030303078ull,0x3630303278302030ull,
0x3178302063303238ull,0x2034303038303030ull,0x303061783009090aull,0x7830206430383030ull,
0x3038376330303030ull,0x3030303032783020ull,0x3430783020313065ull,0x0a20303837633030ull,
0x3830303378300909ull,0x6378302039303430ull,0x2030383730303130ull,0x3430303030317830ull,
0x3034307830206430ull,0x090a203038376333ull,0x3231323032783009ull,0x3030783020333030ull,
0x3020303837303030ull,0x3036303230306478ull,0x3030303078302039ull,0x09090a2030383734ull,
0x3631653030647830ull,0x3430617830203530ull,0x7830203038373030ull,0x3530363932303032ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3032306530306478ull,0x3030306178302031ull,
0x3378302030383730ull,0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3132363030303061ull,0x3431313430783020ull,0x3061783020303837ull,0x3020313330313030ull,
0x3837343030343478ull,0x61783009090a2030ull,0x2035333030303030ull,0x3734313134307830ull,
0x3030397830203038ull,0x7830203933383130ull,0x3038373030303030ull,0x3061783009090a20ull,
0x3020313361313030ull,0x3837343630343478ull,0x6533303278302030ull,0x3078302039336339ull,
0x2066666666666666ull,0x303063783009090aull,0x7830203133383165ull,0x3063376330303030ull,
0x3130303061783020ull,0x3438783020313338ull,0x0a20303837343630ull,0x3931303478300909ull,
0x3078302064333032ull,0x2030383730303030ull,0x3232383130367830ull,0x3030307830206433ull,
0x090a203038376333ull,0x3130313033783009ull,0x3463783020643365ull,0x3020303837303031ull,
0x3330323831303678ull,0x3330303078302064ull,0x09090a2030383763ull,0x6131303430327830ull,
0x3034307830206433ull,0x7830203038376333ull,0x6433653130303061ull,0x3436303434783020ull,
0x3009090a20303837ull,0x3365316530306378ull,0x3030303078302039ull,0x6178302030633763ull,
0x2039336331303030ull,0x3734363034387830ull,0x783009090a203038ull,0x3133383130303032ull,
0x3833303430783020ull,0x3034783020303837ull,0x3020393332333031ull,0x3837303030303078ull,
0x36783009090a2030ull,0x2039333033313130ull,0x3738333030307830ull,0x3130337830203038ull,
0x7830203933633130ull,0x3038373030313463ull,0x3036783009090a20ull,0x3020393330333031ull,
0x3837383330303078ull,0x3030303378302030ull,0x3078302035336331ull,0x2030383734333034ull,
0x303033783009090aull,0x7830203132303164ull,0x3038376330303436ull,0x3030303064783020ull,
0x3430783020313036ull,0x0a20303837383030ull,0x6631303378300909ull,0x6578302031303030ull,
0x2030383730303134ull,0x3031303030337830ull,0x3034307830203133ull,0x090a203038373033ull,
0x3030303061783009ull,0x6332783020313230ull,0x3020303837343130ull,0x3230316330306478ull,
0x3030343078302031ull,0x09090a2030383738ull,0x3730633730337830ull,0x3063367830206466ull,
0x7830203863373431ull,0x3130303030303032ull,0x3032303430783020ull,0x3009090a20303837ull,
0x3030303330306478ull,0x3230343078302031ull,0x3378302030303563ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,
0x0a7d090a20313030ull,0x7b2065646f630a7dull,0x3d20656d616e090aull,0x6e614d38315a5f20ull,
0x44746f72626c6564ull,0x5030316d735f3153ull,0x6934726168637536ull,0x6666666666666969ull,
0x090a6269695f5366ull,0x30203d206d656d6cull,0x3d206d656d73090aull,0x676572090a373720ull,
0x090a3432203d2020ull,0x30203d2020726162ull,0x2074736e6f63090aull,0x6765730909090a7bull,
0x63203d20656d616eull,0x0909090a74736e6full,0x20206d756e676573ull,0x6f0909090a31203dull,
0x3d20207465736666ull,0x79620909090a3020ull,0x203d202020736574ull,0x6d656d09090a3432ull,
0x78300909090a7b20ull,0x6666333030303030ull,0x3030303030783020ull,0x3634783020613030ull,
0x3020303034303030ull,0x3030303030303078ull,0x78300909090a2031ull,0x3030303030383034ull,
0x6666666666783020ull,0x7d09090a20666666ull,0x6e6962090a7d090aull,0x090a7b2065646f63ull,
0x3030383064783009ull,0x3030783020353032ull,0x3020303837303034ull,0x3034303030303178ull,
0x3030303478302039ull,0x09090a2030383734ull,0x3230303030617830ull,0x3034307830206430ull,
0x7830203038373030ull,0x3530323030303031ull,0x3430303034783020ull,0x3009090a20303837ull,
0x3030303030306178ull,0x3030343078302039ull,0x3678302030383730ull,0x2035306534323030ull,
0x3763303230307830ull,0x783009090a203038ull,0x3930633431303036ull,0x3830323030783020ull,
0x3033783020303837ull,0x3020646666633130ull,0x6337303132633678ull,0x33783009090a2038ull,
0x2064666463323030ull,0x3230313263367830ull,0x3030337830203863ull,0x7830203330303030ull,
0x3030313030303030ull,0x3031783009090a20ull,0x3020313063303030ull,0x3837633030343478ull,
0x3330303478302030ull,0x3078302064303030ull,0x2030383730303030ull,0x303036783009090aull,
0x7830206430323032ull,0x3038376330303030ull,0x3030313033783020ull,0x3463783020643036ull,
0x0a20303837303031ull,0x3230303678300909ull,0x3078302031303030ull,0x2030383763303030ull,
0x3030303030327830ull,0x3034307830203130ull,0x090a203038373830ull,0x3032303033783009ull,
0x3463783020643030ull,0x3020303837303031ull,0x3338633030303278ull,0x3032343078302064ull,
0x09090a2030383763ull,0x6531653030647830ull,0x6330387830206430ull,0x7830203038373030ull,
0x3131363038303033ull,0x3030313465783020ull,0x3009090a20303837ull,0x6635306337303378ull,
0x3030633678302064ull,0x6178302038633763ull,0x2033303064323030ull,0x3030303030307830ull,
0x783009090a203030ull,0x3133633030303061ull,0x3830303430783020ull,0x3061783020303837ull,
0x3020643265303030ull,0x3837383030343078ull,0x61783009090a2030ull,0x2039323031303030ull,
0x3738303034307830ull,0x3030317830203038ull,0x7830203330306332ull,0x3038323030303030ull,
0x3032783009090a20ull,0x3020643065396333ull,0x6666666666663078ull,0x6530306478302066ull,
0x3878302064303630ull,0x2030383730306330ull,0x303033783009090aull,0x7830203131363038ull,
0x3038373030313465ull,0x3030303061783020ull,0x3430783020353163ull,0x0a20303837383030ull,
0x3030306178300909ull,0x3078302031313031ull,0x2030383738303034ull,0x6138633430327830ull,
0x3430327830203431ull,0x090a203831383861ull,0x3030303061783009ull,0x3430783020643065ull,
0x3020303837383030ull,0x3161303030306178ull,0x3131343078302031ull,0x09090a2030383734ull,
0x6330303030617830ull,0x3134307830203531ull,0x7830203038373431ull,0x6430363030343032ull,
0x6332303430783020ull,0x3009090a20303837ull,0x3138303138303378ull,0x3134633678302031ull,
0x3378302030383730ull,0x2035316130313830ull,0x3730313463367830ull,0x783009090a203038ull,
0x6430363030303061ull,0x3431313430783020ull,0x3064783020303837ull,0x3020313138303530ull,
0x3837343030343078ull,0x33783009090a2030ull,0x2064303630313830ull,0x3730313463367830ull,
0x3030647830203038ull,0x7830206430363034ull,0x3038373430303430ull,0x3061783009090a20ull,
0x3020643036303030ull,0x3837343130633278ull,0x3230303178302030ull,0x3078302033303064ull,
0x2030383730303030ull,0x303031783009090aull,0x7830206430386630ull,0x3038376333303630ull,
0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,0x3430306178300909ull,
0x3078302033303034ull,0x2030303030303030ull,0x3438313030327830ull,0x3030307830203131ull,
0x090a203330303030ull,0x6334303033783009ull,0x6336783020646664ull,0x3020386337633032ull,
0x3030343430303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x6539343030327830ull,
0x3030307830203131ull,0x7830203330303030ull,0x3131383065303064ull,0x3030633038783020ull,
0x3009090a20303837ull,0x3138303830303378ull,0x3031346578302035ull,0x6178302030383730ull,
0x2039313031303030ull,0x3738303034307830ull,0x783009090a203038ull,0x3531343130303061ull,
0x3830303430783020ull,0x3032783020303837ull,0x3020383163386334ull,0x3161386134303278ull,
0x61783009090a2063ull,0x2031313231303030ull,0x3738303034307830ull,0x3030617830203038ull,
0x7830203531633030ull,0x3038373431313430ull,0x3061783009090a20ull,0x3020393165303030ull,
0x3837343131343078ull,0x3034303278302030ull,0x3078302031313830ull,0x2030383763323034ull,
0x383033783009090aull,0x7830203531613031ull,0x3038373031346336ull,0x3031383033783020ull,
0x6336783020393163ull,0x0a20303837303134ull,0x3030306178300909ull,0x3078302031313830ull,
0x2030383734313134ull,0x6130363030647830ull,0x3034307830203531ull,0x090a203038373430ull,
0x3031383033783009ull,0x6336783020313138ull,0x3020303837303134ull,0x3138303530306478ull,
0x3030343078302031ull,0x09090a2030383734ull,0x3830303030617830ull,0x3063327830203131ull,
0x7830203038373431ull,0x6430363030303032ull,0x3031303430783020ull,0x3009090a20303837ull,
0x6633306337303378ull,0x3030633678302064ull,0x6178302061633763ull,0x2033303062353030ull,
0x3030303030307830ull,0x783009090a203030ull,0x3330306235303031ull,0x3030303030783020ull,
0x3033783020303832ull,0x3020313163633030ull,0x3837303032343078ull,0x33783009090a2030ull,
0x2031313830323030ull,0x3730303134637830ull,0x3030327830203038ull,0x7830203131386330ull,
0x3038373031323430ull,0x3064783009090a20ull,0x3020313138306530ull,0x3837303063303878ull,
0x3830303378302030ull,0x6578302039313830ull,0x2030383730303134ull,0x303061783009090aull,
0x7830203531303130ull,0x3038373830303430ull,0x3130303061783020ull,0x3430783020393138ull,
0x0a20303837383030ull,0x6334303278300909ull,0x3278302034316138ull,0x2038316338613430ull,
0x3231303030617830ull,0x3034307830203131ull,0x090a203038373830ull,0x3030303061783009ull,
0x3430783020353161ull,0x3020303837343131ull,0x3163303030306178ull,0x3131343078302039ull,
0x09090a2030383734ull,0x3830303430327830ull,0x3034307830203131ull,0x7830203038376332ull,
0x3531613031383033ull,0x3031346336783020ull,0x3009090a20303837ull,0x3163303138303378ull,
0x3134633678302039ull,0x6178302030383730ull,0x2031313830303030ull,0x3734313134307830ull,
0x783009090a203038ull,0x3531613036303064ull,0x3430303430783020ull,0x3033783020303837ull,
0x3020313138303138ull,0x3837303134633678ull,0x64783009090a2030ull,0x2031313830353030ull,
0x3734303034307830ull,0x3030617830203038ull,0x7830203131383030ull,0x3038373431306332ull,
0x3032783009090a20ull,0x3020643036303030ull,0x3837303130343078ull,0x3030306678302030ull,
0x6578302031303030ull,0x2032303030303030ull,0x303061783009090aull,0x7830203330303437ull,
0x3030303030303030ull,0x3831303032783020ull,0x3030783020313132ull,0x0a20333030303030ull,
0x3430303378300909ull,0x3678302064666663ull,0x2038633763303263ull,0x3034373030317830ull,
0x3030307830203330ull,0x090a203038323030ull,0x6330303032783009ull,0x3430783020313063ull,
0x3020303837303032ull,0x3030303230303378ull,0x3031346378302031ull,0x09090a2030383730ull,
0x3863303030327830ull,0x3234307830203130ull,0x7830203038373030ull,0x3130303065303064ull,
0x3030633038783020ull,0x3009090a20303837ull,0x3130303830303378ull,0x3031346578302035ull,
0x6178302030383730ull,0x2031313030303030ull,0x3738303034307830ull,0x783009090a203038ull,
0x3531343130303061ull,0x3830303430783020ull,0x3032783020303837ull,0x3020303138386334ull,
0x3161386134303278ull,0x61783009090a2034ull,0x2031303230303030ull,0x3738303034307830ull,
0x3030617830203038ull,0x7830203131383030ull,0x3038373431313430ull,0x3061783009090a20ull,
0x3020353161303030ull,0x3837343131343078ull,0x3034303278302030ull,0x3078302031303030ull,
0x2030383763323034ull,0x383033783009090aull,0x7830203131383031ull,0x3038373031346336ull,
0x3031383033783020ull,0x6336783020353161ull,0x0a20303837303134ull,0x3030306178300909ull,
0x3078302031303030ull,0x2030383734313134ull,0x3830353030647830ull,0x3034307830203131ull,
0x090a203038373430ull,0x3031383033783009ull,0x6336783020313030ull,0x3020303837303134ull,
0x3030303430306478ull,0x3030343078302031ull,0x09090a2030383734ull,0x3030303030617830ull,
0x3063327830203130ull,0x7830203038373431ull,0x6430363030303032ull,0x3030303430783020ull,
0x3009090a20303837ull,0x6637306337303378ull,0x3030633678302064ull,0x3378302061633738ull,
0x2033303030303030ull,0x3230303030307830ull,0x783009090a203038ull,0x3930343030303061ull,
0x3431303434783020ull,0x3061783020303837ull,0x3020313132303030ull,0x3837343130343478ull,
0x31783009090a2030ull,0x2030303266303031ull,0x3666303031317830ull,0x3030657830203430ull,
0x7830203130656432ull,0x3038373030323030ull,0x3065783009090a20ull,0x3020353165643430ull,
0x3837343032303078ull,0x3230306578302030ull,0x3078302035306564ull,0x2030383730303234ull,
0x303065783009090aull,0x7830203931656434ull,0x3038373431323430ull,0x3031343062783020ull,
0x3062783020633030ull,0x0a20633161303634ull,0x3230306578300909ull,0x3078302039306564ull,
0x2030383763303238ull,0x6564343030657830ull,0x3238307830203131ull,0x090a203038376331ull,
0x3731343162783009ull,0x3162783020343032ull,0x3020633036373634ull,0x3032303230306278ull,
0x3430306278302034ull,0x09090a2038303630ull,0x3437313031627830ull,0x3031627830203430ull,
0x7830203830383732ull,0x3833303031303062ull,0x3032303062783020ull,0x3009090a20343361ull,
0x3038393030306478ull,0x3030303278302035ull,0x6278302030383730ull,0x2030306331303430ull,
0x6131353430627830ull,0x783009090a206330ull,0x6466313030303461ull,0x3831326330783020ull,
0x3062783020386337ull,0x3020343232303034ull,0x3234303334306278ull,0x31783009090a2030ull,
0x2033303030623030ull,0x3130303030307830ull,0x3830657830203030ull,0x7830203130613132ull,
0x3038373433343830ull,0x3065783009090a20ull,0x3020313061313034ull,0x3430303036343078ull,
0x6430306378302033ull,0x6278302063306131ull,0x2038306131303430ull,0x303065783009090aull,
0x7830203131303030ull,0x3038376330303830ull,0x3138303063783020ull,0x3030783020353061ull,
0x0a20303837303030ull,0x3030306578300909ull,0x3078302031313430ull,0x2030383730313030ull,
0x6131383030657830ull,0x3030307830206431ull,0x090a203038373430ull,0x3132383065783009ull,
0x3830783020353063ull,0x3020303837383334ull,0x3163313930306378ull,0x3030303078302039ull,
0x09090a2030383730ull,0x3430303030657830ull,0x3030307830203531ull,0x7830203038373031ull,
0x3131613164303065ull,0x6331303030783020ull,0x3009090a20303837ull,0x3063313238306578ull,
0x3034383078302031ull,0x6578302030383734ull,0x2035346331393030ull,0x3738313030307830ull,
0x783009090a203038ull,0x3034633165303063ull,0x3033343062783020ull,0x3062783020383438ull,
0x3020393163313030ull,0x3837303030383078ull,0x65783009090a2030ull,0x2035306331653030ull,
0x3734343030307830ull,0x3030657830203038ull,0x7830206434303030ull,0x3038373034303830ull,
0x3062783009090a20ull,0x3020633165303235ull,0x3438303235306278ull,0x3030306278302038ull,
0x3078302031353230ull,0x2030383730343038ull,0x303065783009090aull,0x7830206434633030ull,
0x3038376334303030ull,0x3032353062783020ull,0x3062783020633036ull,0x0a20343532303435ull,
0x3030306578300909ull,0x3078302039346330ull,0x2030383763343030ull,0x3232343530627830ull,
0x3530627830203434ull,0x090a203034303235ull,0x3032303065783009ull,0x3030783020313034ull,
0x3020303837343130ull,0x3065303030306278ull,0x3030303078302039ull,0x09090a2030383763ull,
0x6330363030657830ull,0x3030307830206430ull,0x7830203038373834ull,0x3431323230313062ull,
0x3032303062783020ull,0x3009090a20303030ull,0x3036303030306278ull,0x3130303078302039ull,
0x6578302030383734ull,0x2031303031383030ull,0x3730303030307830ull,0x783009090a203038ull,
0x6430323139303065ull,0x3830303030783020ull,0x3062783020303837ull,0x3020303438303030ull,
0x3432303330306278ull,0x62783009090a2063ull,0x2038303032343430ull,0x3632313430627830ull,
0x3430627830203430ull,0x7830203434303032ull,0x3834363031343062ull,0x3131783009090a20ull,
0x3020303061663030ull,0x3063663030313178ull,0x3030303178302034ull,0x3078302031313866ull,
0x2030383763333034ull,0x303031783009090aull,0x7830203531386630ull,0x3038376333303630ull,
0x3930303031783020ull,0x3031783020633030ull,0x0a20383061393230ull,0x3030303178300909ull,
0x3178302063313239ull,0x2038316339323030ull,0x3061623030317830ull,0x3030307830203330ull,
0x090a203038373030ull,0x6630303031783009ull,0x3430783020393438ull,0x3020303837633330ull,
0x3438663030303178ull,0x3330363078302064ull,0x09090a2030383763ull,0x3866303030317830ull,
0x3034307830203534ull,0x7830203038376333ull,0x3134386630303031ull,0x6333303630783020ull,
0x3009090a20303837ull,0x3138663030303178ull,0x3330343078302064ull,0x3178302030383763ull,
0x2039313866303030ull,0x3763333036307830ull,0x783009090a203038ull,0x6430386630303031ull,
0x6333303430783020ull,0x3031783020303837ull,0x3020393038663030ull,0x3837633330363078ull,
0x31783009090a2030ull,0x2034306139303030ull,0x3039323030317830ull,0x3030317830203031ull,
0x7830203030633930ull,0x3431323932303031ull,0x3033783009090a20ull,0x3020646631643338ull,
0x6337383036633678ull,0x6633313278302038ull,0x3078302035333066ull,0x2066666666666666ull,
0x313031783009090aull,0x7830203330306431ull,0x3038323030303030ull,0x3230313062783020ull,
0x3062783020303236ull,0x0a20343230313335ull,0x3934306278300909ull,0x6278302038333031ull,
0x2034323032393430ull,0x3632653430627830ull,0x3030627830203833ull,0x090a203432323165ull,
0x3132313062783009ull,0x3062783020343232ull,0x3020343232313131ull,0x3330313930306278ull,
0x3834306278302038ull,0x09090a2030326331ull,0x3231383430627830ull,0x3030627830203032ull,
0x7830203032633138ull,0x6466313134383062ull,0x3430343036783020ull,0x3009090a20386337ull,
0x3030633131306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303063313130ull,
0x3130303030307830ull,0x783009090a203030ull,0x3532633032383065ull,0x3831343830783020ull,
0x3065783020303837ull,0x3020313234303238ull,0x3837383034383078ull,0x65783009090a2030ull,
0x2035326330303430ull,0x3030303634307830ull,0x3430657830203334ull,0x7830203132343030ull,
0x3334303030363430ull,0x3034783009090a20ull,0x3020333030633131ull,0x3030303030303078ull,
0x3630306278302030ull,0x6278302038353239ull,0x2038333039323030ull,0x303063783009090aull,
0x7830203135343037ull,0x3038373030303030ull,0x3033303065783020ull,0x3030783020353563ull,
0x0a20303837303530ull,0x3230306578300909ull,0x3078302031356330ull,0x2030383734353030ull,
0x6330323030637830ull,0x3030307830206435ull,0x090a203038373030ull,0x3032303065783009ull,
0x3430783020393163ull,0x3020303837303530ull,0x3030313930306578ull,0x3530383078302039ull,
0x09090a2030383763ull,0x6331393030657830ull,0x3030307830203930ull,0x7830203038373830ull,
0x3432613236343062ull,0x3236343062783020ull,0x3009090a20383138ull,0x3165323030306278ull,
0x3130383078302039ull,0x6578302030383738ull,0x2039306332383030ull,0x3738303030307830ull,
0x783009090a203038ull,0x3132633265303065ull,0x3830303030783020ull,0x3062783020303837ull,
0x3020383032313630ull,0x3034303830306278ull,0x65783009090a2038ull,0x2064303630373030ull,
0x3738303030307830ull,0x3030627830203038ull,0x7830203831383233ull,0x3830633036303062ull,
0x3062783009090a20ull,0x3020633134303634ull,0x3234303734306278ull,0x3435306278302030ull,
0x6278302034326330ull,0x2063316330373430ull,0x343062783009090aull,0x7830203831633038ull,
0x3032363039343062ull,0x3036303062783020ull,0x3062783020633065ull,0x0a20633036303830ull,
0x3830306278300909ull,0x6278302063313630ull,0x2034323430373030ull,0x3632303530627830ull,
0x3030627830203831ull,0x090a206330323039ull,0x3033353062783009ull,0x3062783020383363ull,
0x3020303236303934ull,0x3563306534306278ull,0x6530306278302030ull,0x09090a2034353032ull,
0x3039333030627830ull,0x3530627830203833ull,0x7830206334363234ull,0x3034323132343062ull,
0x3165343062783020ull,0x3009090a20343232ull,0x3032303834306278ull,0x3535306278302038ull,
0x6278302030323632ull,0x2063316530303530ull,0x3430393030627830ull,0x783009090a203830ull,
0x3032303132313062ull,0x3037303062783020ull,0x3062783020383034ull,0x3020343230313135ull,
0x3234303430306278ull,0x62783009090a2030ull,0x2038336330393030ull,0x3031333030627830ull,
0x3030627830203830ull,0x7830206331633130ull,0x6330363832303062ull,0x3062783009090a20ull,
0x3020303465306534ull,0x3030313334306278ull,0x3035306278302063ull,0x6378302030326530ull,
0x2034343630323030ull,0x343062783009090aull,0x7830206334633136ull,0x3833633138343062ull,
0x3032383065783020ull,0x3830783020313234ull,0x0a20303837383034ull,0x3230306578300909ull,
0x3078302039313630ull,0x2030383734343030ull,0x3030303530627830ull,0x3030637830203834ull,
0x090a203034343032ull,0x3030343065783009ull,0x3430783020313234ull,0x3020333430303036ull,
0x3434303230306578ull,0x3130303078302035ull,0x09090a2030383738ull,0x3231333530627830ull,
0x3130627830206334ull,0x7830203432633132ull,0x3934303138303065ull,0x3034303830783020ull,
0x3009090a20303837ull,0x3532323035306278ull,0x3834306278302030ull,0x6278302038333430ull,
0x2034323231333130ull,0x3232343530627830ull,0x783009090a203435ull,0x3934303165303065ull,
0x3834303030783020ull,0x3062783020303837ull,0x3020343261303930ull,0x3463303435306278ull,
0x62783009090a2063ull,0x2031353032303030ull,0x3734353038307830ull,0x3030657830203038ull,
0x7830203134303165ull,0x3038373834303030ull,0x3062783009090a20ull,0x3020383165303930ull,
0x3436323431306278ull,0x6530306578302038ull,0x3078302031346331ull,0x2030383730343030ull,
0x343062783009090aull,0x7830206331633037ull,0x3034303232313062ull,0x3130303062783020ull,
0x3830783020643132ull,0x0a20303837633130ull,0x3330306578300909ull,0x3078302035323630ull,
0x2030383730343030ull,0x6330373030637830ull,0x3030627830203834ull,0x090a203034323239ull,
0x3037303065783009ull,0x3030783020313563ull,0x3020303837383430ull,0x3463303630306378ull,
0x3135306278302063ull,0x09090a2034343032ull,0x6330363030657830ull,0x3030307830203934ull,
0x7830203038373035ull,0x3434323131353062ull,0x3233353062783020ull,0x3009090a20343234ull,
0x3538323934306278ull,0x3934306278302030ull,0x6278302034323432ull,0x2034323632393430ull,
0x3832393030627830ull,0x783009090a203035ull,0x3532633032383065ull,0x3831343830783020ull,
0x3065783020303837ull,0x3020353263303034ull,0x3430303036343078ull,0x65783009090a2033ull,
0x2064343231393030ull,0x3763343038307830ull,0x3030627830203038ull,0x7830203935633030ull,
0x3038373432303830ull,0x3065783009090a20ull,0x3020643432313631ull,0x3837633430303078ull,
0x3631306578302030ull,0x3078302064343231ull,0x2030383763343030ull,0x313065783009090aull,
0x7830206434633236ull,0x3038376334303030ull,0x3230303062783020ull,0x3030783020643436ull,
0x0a20303837303530ull,0x3730306578300909ull,0x3078302031356530ull,0x2030383763343030ull,
0x3432343130627830ull,0x3530627830206334ull,0x090a203834363232ull,0x3232353062783009ull,
0x3062783020383438ull,0x3020303530323331ull,0x3536613431306278ull,0x3535306278302034ull,
0x09090a2063353832ull,0x3032353530627830ull,0x3530627830203435ull,0x7830206335363237ull,
0x3435613237313062ull,0x3235313062783020ull,0x3009090a20343534ull,0x3532323531306278ull,
0x3731306278302063ull,0x6278302034353832ull,0x2030356132343530ull,0x6532343530627830ull,
0x783009090a203035ull,0x3533613130303132ull,0x3431343430783020ull,0x3035783020306337ull,
0x3020333030303030ull,0x3031303030303078ull,0x62783009090a2030ull,0x2031353832303030ull,
0x3734353030307830ull,0x3830627830203038ull,0x7830206466393234ull,0x3863373430343036ull,
0x3031783009090a20ull,0x3020333030636330ull,0x3832303030303078ull,0x3030303578302030ull,
0x3078302033303030ull,0x2030383730303030ull,0x303066783009090aull,0x7830203130303030ull,
0x3230303030303065ull,0x3163373033783020ull,0x6336783020353061ull,0x0a20303837303130ull,
0x3034303278300909ull,0x3078302031303064ull,0x2030383734333234ull,0x3030313030647830ull,
0x3034307830203130ull,0x090a203038373030ull,0x3063373033783009ull,0x6336783020646631ull,
0x3020386337383030ull,0x3030373331306178ull,0x3030303078302033ull,0x09090a2030303030ull,
0x3034333130317830ull,0x3030307830203330ull,0x7830203038323030ull,0x3530303830303064ull,
0x3030303032783020ull,0x3009090a20303837ull,0x3034653030303278ull,0x3032343078302031ull,
0x6178302030383730ull,0x2039303030303034ull,0x3738303230307830ull,0x783009090a203038ull,
0x3931323030303461ull,0x3830323030783020ull,0x3461783020303837ull,0x3020643134303030ull,
0x3837383032303078ull,0x34783009090a2030ull,0x2038303230323030ull,0x3230363030347830ull,
0x3030347830203031ull,0x7830203531323037ull,0x3038373030303030ull,0x3033783009090a20ull,
0x3020393034303031ull,0x3837303031346378ull,0x3031303378302030ull,0x6378302031313830ull,
0x2030383730303134ull,0x313033783009090aull,0x7830203531613030ull,0x3038373030313463ull,
0x3032303036783020ull,0x3030783020353030ull,0x0a20303837383030ull,0x3630303678300909ull,
0x3078302039303030ull,0x2030383730313030ull,0x3030373030367830ull,0x3030307830206430ull,
0x090a203038373431ull,0x3030303061783009ull,0x3430783020313032ull,0x3020303837633030ull,
0x3134303030306178ull,0x3030343078302035ull,0x09090a2030383763ull,0x3630303030617830ull,
0x3034307830203931ull,0x7830203038376330ull,0x3330303733313031ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3138663030303178ull,0x3330343078302039ull,0x3178302030383763ull,
0x2035313866303030ull,0x3763333036307830ull,0x783009090a203038ull,0x3130386630303031ull,
0x6333303430783020ull,0x3031783020303837ull,0x3020353032323030ull,0x3837633030343478ull,
0x34783009090a2032ull,0x2064303430393130ull,0x3730303030307830ull,0x3031327830203038ull,
0x7830203930326530ull,0x3038376330363430ull,0x3036783009090a20ull,0x3020313136303831ull,
0x3837633030303078ull,0x6631303378302030ull,0x6578302064303430ull,0x2030383730303163ull,
0x313033783009090aull,0x7830203131383030ull,0x3038373030313463ull,0x3033383064783020ull,
0x3430783020643036ull,0x0a20303837303034ull,0x3831303678300909ull,0x3078302031313430ull,
0x2030383730313030ull,0x3638323030327830ull,0x3130347830206330ull,0x090a203032343035ull,
0x3030303032783009ull,0x3430783020313038ull,0x3020303837303030ull,0x3136303130303378ull,
0x3031636578302064ull,0x09090a2030383730ull,0x3630343130367830ull,0x3030307830203131ull,
0x7830203038373032ull,0x6330343832303031ull,0x3830303032783020ull,0x3009090a20303065ull,
0x3138303031303378ull,0x3031346378302031ull,0x3278302030383730ull,0x2033303061353130ull,
0x3730303030307830ull,0x783009090a203038ull,0x3132343037313034ull,0x3030303030783020ull,
0x3036783020303837ull,0x3020643034303431ull,0x3837303130303078ull,0x31783009090a2030ull,
0x2031313030303030ull,0x3763333034307830ull,0x3130367830203038ull,0x7830203132363036ull,
0x3038373032303030ull,0x3032783009090a20ull,0x3020303036383530ull,0x3034383230303178ull,
0x3031303378302063ull,0x6378302035313031ull,0x2030383730303134ull,0x303032783009090aull,
0x7830203130653030ull,0x3038373030303430ull,0x3036313036783020ull,0x3030783020353034ull,
0x0a20303837343130ull,0x3531303278300909ull,0x3078302033303061ull,0x2030383730303030ull,
0x3238363030327830ull,0x3030317830206330ull,0x090a203430303830ull,0x3030303061783009ull,
0x3030783020643038ull,0x3020303837633030ull,0x3065303030303278ull,0x3030343078302031ull,
0x09090a2030383763ull,0x3430383030337830ull,0x3130637830203930ull,0x7830203038373030ull,
0x6430343030303031ull,0x6333303430783020ull,0x3009090a20303837ull,0x3030613531303278ull,
0x3030303078302033ull,0x6478302030383730ull,0x2039303630323030ull,0x3734303030307830ull,
0x783009090a203038ull,0x3530653165303064ull,0x3030343061783020ull,0x3032783020303837ull,
0x3020353065393230ull,0x3030303030303078ull,0x64783009090a2033ull,0x2031303230653030ull,
0x3730303030617830ull,0x3030337830203038ull,0x7830203330303030ull,0x3038373030303030ull,
0x3061783009090a20ull,0x3020313236303030ull,0x3837343131343078ull,0x3030306178302030ull,
0x3478302035323031ull,0x2030383734303034ull,0x303061783009090aull,0x7830203133303030ull,
0x3038373431313430ull,0x3130303039783020ull,0x3030783020353332ull,0x0a20303837303030ull,
0x3030306178300909ull,0x3478302035323831ull,0x2030383734363034ull,0x6139653330327830ull,
0x6666307830203533ull,0x090a206666666666ull,0x3164303063783009ull,0x3030783020353232ull,
0x3020306337633030ull,0x3232313030306178ull,0x3630343878302035ull,0x09090a2030383734ull,
0x3032333130347830ull,0x3030307830203933ull,0x7830203038373030ull,0x3933323232313036ull,
0x3833303030783020ull,0x3009090a20303837ull,0x3363313031303378ull,0x3031346378302039ull,
0x3678302030383730ull,0x2039333032323130ull,0x3738333030307830ull,0x783009090a203038ull,
0x3933383130343032ull,0x3833303430783020ull,0x3061783020303837ull,0x3020393363313030ull,
0x3837343630343478ull,0x63783009090a2030ull,0x2035336331643030ull,0x3763303030307830ull,
0x3030617830203063ull,0x7830203533613130ull,0x3038373436303438ull,0x3032783009090a20ull,
0x3020353232313030ull,0x3837343330343078ull,0x3031303478302030ull,0x3078302035333632ull,
0x2030383730303030ull,0x313036783009090aull,0x7830203533343231ull,0x3038373433303030ull,
0x3130313033783020ull,0x3463783020353361ull,0x0a20303837303031ull,0x3031303678300909ull,
0x3078302035333432ull,0x2030383734333030ull,0x6131303030337830ull,0x3034307830203133ull,
0x090a203038373033ull,0x3163303033783009ull,0x3436783020313230ull,0x3020303837633030ull,
0x3036303030306478ull,0x3030343078302031ull,0x09090a2030383738ull,0x3030663130337830ull,
0x3134657830203130ull,0x7830203038373030ull,0x3532303130303033ull,0x3432303430783020ull,
0x3009090a20303837ull,0x3230303030306178ull,0x3130633278302031ull,0x6478302030383734ull,
0x2031323031393030ull,0x3738303034307830ull,0x783009090a203038ull,0x6466373063373033ull,
0x3431306336783020ull,0x3032783020386337ull,0x3020313030303030ull,0x3837303230343078ull,
0x64783009090a2030ull,0x2031303030333030ull,0x3563323034307830ull,0x3030337830203030ull,
0x7830203330303030ull,0x3038373030303030ull,0x3066783009090a20ull,0x3020313030303030ull,
0x3030303030306578ull,0x0a7d0a7d090a2031ull,0x090a7b2065646f63ull,0x5f203d20656d616eull,
0x65646e614d36315aull,0x735f30746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f32535f32535f32ull,0x090a6269695f3053ull,0x30203d206d656d6cull,
0x3d206d656d73090aull,0x676572090a333920ull,0x090a3032203d2020ull,0x30203d2020726162ull,
0x2074736e6f63090aull,0x6765730909090a7bull,0x63203d20656d616eull,0x0909090a74736e6full,
0x20206d756e676573ull,0x6f0909090a31203dull,0x3d20207465736666ull,0x79620909090a3020ull,
0x203d202020736574ull,0x6d656d09090a3231ull,0x78300909090a7b20ull,0x6666333030303030ull,
0x3066663030783020ull,0x3030783020666630ull,0x0a20313030303030ull,0x090a7d090a7d0909ull,
0x2065646f636e6962ull,0x3064783009090a7bull,0x3020353032303038ull,0x3837303034303078ull,
0x3030303178302030ull,0x3478302039303430ull,0x2030383734303030ull,0x303061783009090aull,
0x7830206430323030ull,0x3038373030303430ull,0x3030303031783020ull,0x3034783020353032ull,
0x0a20303837343030ull,0x3030306178300909ull,0x3078302039303030ull,0x2030383730303034ull,
0x6534323030367830ull,0x3230307830203932ull,0x090a203038376330ull,0x3431303036783009ull,
0x3030783020643263ull,0x3020303837383032ull,0x6666636130303378ull,0x3132633678302064ull,
0x09090a2038633730ull,0x6463623030337830ull,0x3263367830206466ull,0x7830203863323031ull,
0x3330303030303033ull,0x3030303030783020ull,0x3009090a20303031ull,0x3038623030306478ull,
0x3030303278302035ull,0x6178302030383730ull,0x2031323631303030ull,0x3730313434347830ull,
0x783009090a203038ull,0x3930343230303031ull,0x6330303434783020ull,0x3031783020303837ull,
0x3020643036323030ull,0x3837633030343478ull,0x31783009090a2030ull,0x2030313466303031ull,
0x3666303031317830ull,0x3030617830203431ull,0x7830203931343130ull,0x3038373031343434ull,
0x3131783009090a20ull,0x3020303038663030ull,0x3061663030313178ull,0x3030346178302034ull,
0x3078302064663130ull,0x2038633738313263ull,0x303065783009090aull,0x7830203132303132ull,
0x3038373031303034ull,0x3036303065783020ull,0x3034783020393134ull,0x0a20303837303030ull,
0x3030303178300909ull,0x3478302039343031ull,0x2030383763303034ull,0x3065313030317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x6630303131783009ull,0x3131783020383063ull,
0x3020633065663030ull,0x3130323030303178ull,0x3030343478302031ull,0x09090a2030383763ull,
0x3232303030317830ull,0x3034347830203531ull,0x7830203038376330ull,0x3933633036303065ull,
0x3030303038783020ull,0x3009090a20303837ull,0x3430313830306578ull,0x3030303878302031ull,
0x3178302030383730ull,0x2030306338323030ull,0x6538303030317830ull,0x783009090a203430ull,
0x3033303932303031ull,0x3930303031783020ull,0x3031783020343332ull,0x3020333030353230ull,
0x3837303030303078ull,0x31783009090a2030ull,0x2031303038303030ull,0x3030303030307830ull,
0x3030317830203330ull,0x7830203530303830ull,0x3330303030303030ull,0x3031783009090a20ull,
0x3020303430383230ull,0x3432383030303178ull,0x3230303178302034ull,0x3178302038333038ull,
0x2063333238303030ull,0x303031783009090aull,0x7830203033303832ull,0x3433323830303031ull,
0x3932303031783020ull,0x3031783020383030ull,0x0a20633032393030ull,0x3230303178300909ull,
0x3178302030316338ull,0x2034316538303030ull,0x3039363130347830ull,0x3030307830203330ull,
0x090a203030303030ull,0x6463373033783009ull,0x6336783020646631ull,0x3020386337633032ull,
0x3030643230303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x3032303030657830ull,
0x3030367830203931ull,0x7830203038373833ull,0x3132303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3230383030303178ull,0x3130343078302035ull,0x6578302033303030ull,
0x2064666430383030ull,0x3730313030657830ull,0x783009090a203863ull,0x3330306632303031ull,
0x3030303030783020ull,0x3031783020303031ull,0x3020643434323030ull,0x3837633330363078ull,
0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,
0x7830203130383130ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,
0x3837303030303678ull,0x6633303278302030ull,0x3078302064343461ull,0x2066666666666666ull,
0x303065783009090aull,0x7830203931303230ull,0x3038373833303836ull,0x3030303065783020ull,
0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,
0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,0x3030653330303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,
0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030663330ull,0x3031303030303078ull,0x35783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,
0x6533303278302030ull,0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,
0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,
0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,
0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3030653430303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030663430ull,0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,0x6433303278302030ull,
0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,
0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,
0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,
0x3020303837303030ull,0x3030653530303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,
0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,
0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,0x3020333030663530ull,
0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,
0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,
0x3020313030303030ull,0x3837303030303678ull,0x6333303278302030ull,0x3078302064343461ull,
0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,
0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,
0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,
0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,
0x3030653630303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,
0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,
0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020333030663630ull,0x3031303030303078ull,
0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,
0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,
0x3837303030303678ull,0x6233303278302030ull,0x3078302064343461ull,0x2066666666666666ull,
0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,
0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,
0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,0x3030653730303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,
0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030663730ull,0x3031303030303078ull,0x35783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,
0x6133303278302030ull,0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,
0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,
0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,
0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3030653830303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030663830ull,0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,0x3933303278302030ull,
0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,
0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,
0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,
0x3020303837303030ull,0x3030653930303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,
0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,
0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,0x3020333030663930ull,
0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,
0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,
0x3020313030303030ull,0x3837303030303678ull,0x3833303278302030ull,0x3078302064343461ull,
0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,
0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,
0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,
0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,
0x3030656130303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,
0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,
0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020333030666130ull,0x3031303030303078ull,
0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,
0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,
0x3837303030303678ull,0x3733303278302030ull,0x3078302064343461ull,0x2066666666666666ull,
0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,
0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,
0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,0x3030656230303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,
0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030666230ull,0x3031303030303078ull,0x35783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,
0x3633303278302030ull,0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,
0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,
0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,
0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3030656330303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030666330ull,0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,0x3533303278302030ull,
0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,
0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,
0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,
0x3020303837303030ull,0x3030656430303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,
0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,
0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,0x3020333030666430ull,
0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,
0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,
0x3020313030303030ull,0x3837303030303678ull,0x3433303278302030ull,0x3078302064343461ull,
0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,
0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,
0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,
0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,
0x3030656530303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,
0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,
0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020333030666530ull,0x3031303030303078ull,
0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,
0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,
0x3837303030303678ull,0x3333303278302030ull,0x3078302064343461ull,0x2066666666666666ull,
0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,
0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,
0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,0x3030656630303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,
0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030666630ull,0x3031303030303078ull,0x35783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,
0x3233303278302030ull,0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,
0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,
0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,
0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3030653031303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030663031ull,0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,
0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,0x3133303278302030ull,
0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,
0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,
0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,
0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,
0x3020303837303030ull,0x3030653131303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,
0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,
0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,0x3020333030663131ull,
0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,
0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,
0x3020313030303030ull,0x3837303030303678ull,0x3033303278302030ull,0x3078302064343461ull,
0x2066666666666666ull,0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,
0x3030303065783020ull,0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,
0x3678302064663732ull,0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,
0x090a203038373831ull,0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,
0x3030653231303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,
0x3030387830203133ull,0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,
0x2039333831303030ull,0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,
0x3031303065783020ull,0x3031783020386337ull,0x3020333030663231ull,0x3031303030303078ull,
0x35783009090a2030ull,0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,
0x7830203130633030ull,0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,
0x3837303030303678ull,0x6632303278302030ull,0x3078302064343461ull,0x2066666666666666ull,
0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,
0x3036783020313038ull,0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,
0x2038633763303063ull,0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,
0x3030303065783009ull,0x3038783020313230ull,0x3020303837303030ull,0x3030653331303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,
0x7830203038373030ull,0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3430383030303178ull,0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,
0x3730323030367830ull,0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,
0x3031783020386337ull,0x3020333030663331ull,0x3031303030303078ull,0x35783009090a2030ull,
0x2033303030303030ull,0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,
0x3038373030303038ull,0x3065783009090a20ull,0x3020313030303030ull,0x3837303030303678ull,
0x6532303278302030ull,0x3078302064343461ull,0x2066666666666666ull,0x303065783009090aull,
0x7830203931383130ull,0x3038373032303836ull,0x3030303065783020ull,0x3036783020313038ull,
0x0a20303837303030ull,0x6337303378300909ull,0x3678302064663732ull,0x2038633763303063ull,
0x3430303030657830ull,0x3030367830203931ull,0x090a203038373831ull,0x3030303065783009ull,
0x3038783020313230ull,0x3020303837303030ull,0x3030653431303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x6330363030657830ull,0x3030387830203133ull,0x7830203038373030ull,
0x3134303830303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3430383030303178ull,
0x3130343078302035ull,0x6578302033303030ull,0x2039333831303030ull,0x3730323030367830ull,
0x783009090a203038ull,0x6466643130313065ull,0x3031303065783020ull,0x3031783020386337ull,
0x3020333030663431ull,0x3031303030303078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203130633030ull,0x3038373030303038ull,
0x3032783009090a20ull,0x3020393434616432ull,0x6666666666663078ull,0x3030306578302066ull,
0x3678302031303030ull,0x2030383730303030ull,0x373033783009090aull,0x7830203933343263ull,
0x3064376330306336ull,0x3130303065783020ull,0x3836783020393138ull,0x0a20303837303230ull,
0x3030306578300909ull,0x3678302031303830ull,0x2030383730303030ull,0x6431303030617830ull,
0x3063307830206466ull,0x090a203863373431ull,0x3030303065783009ull,0x3036783020393134ull,
0x3020303837383130ull,0x3230303030306578ull,0x3030303878302031ull,0x09090a2030383730ull,
0x3066353130317830ull,0x3030307830203330ull,0x7830203038323130ull,0x3133633036303065ull,
0x3030303038783020ull,0x3009090a20303837ull,0x3430383030303178ull,0x3030303078302031ull,
0x3178302033303030ull,0x2035343038303030ull,0x3030313034307830ull,0x783009090a203330ull,
0x3933383130303065ull,0x3032303036783020ull,0x3065783020303837ull,0x3020646664313031ull,
0x6437303130306578ull,0x31783009090a2038ull,0x2033303031363130ull,0x3131303030307830ull,
0x3030317830203030ull,0x7830206434343230ull,0x3038376333303430ull,0x3035783009090a20ull,
0x3020333030303030ull,0x3837303030303078ull,0x3030306578302030ull,0x3878302031306330ull,
0x2030383730303030ull,0x303065783009090aull,0x7830203931383130ull,0x3038373032303836ull,
0x3030303065783020ull,0x3036783020313030ull,0x0a20303837303030ull,0x3030306578300909ull,
0x3678302031333430ull,0x2030383738313030ull,0x3830303030657830ull,0x3030367830203130ull,
0x090a203038373030ull,0x3163303065783009ull,0x3038783020313438ull,0x3020303837303030ull,
0x3330303030306578ull,0x3030303878302039ull,0x09090a2030383730ull,0x3037323030317830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3530363263373033ull,0x3031306336783020ull,
0x3009090a20303837ull,0x3030643034303278ull,0x3432343078302031ull,0x6478302030383763ull,
0x2031303030313030ull,0x3730303034307830ull,0x783009090a203038ull,0x6466313063373033ull,
0x3830306336783020ull,0x3061783020386337ull,0x3020333030333831ull,0x3030303030303078ull,
0x31783009090a2030ull,0x2033303030383130ull,0x3230303030307830ull,0x3030647830203038ull,
0x7830203530306130ull,0x3038373030303032ull,0x3032783009090a20ull,0x3020313063653030ull,
0x3837303032343078ull,0x3030346178302030ull,0x3078302039303030ull,0x2030383738303230ull,
0x303461783009090aull,0x7830203931323030ull,0x3038373830323030ull,0x3030303461783020ull,
0x3030783020643134ull,0x0a20303837383032ull,0x3230303478300909ull,0x3478302038303230ull,
0x2030313230363030ull,0x3230373030347830ull,0x3030307830203531ull,0x090a203038373030ull,
0x3030313033783009ull,0x3463783020393034ull,0x3020303837303031ull,0x3138303031303378ull,
0x3031346378302031ull,0x09090a2030383730ull,0x6130303130337830ull,0x3134637830203531ull,
0x7830203038373030ull,0x3530303032303036ull,0x3830303030783020ull,0x3009090a20303837ull,
0x3030303630303678ull,0x3130303078302039ull,0x3678302030383730ull,0x2031303030373030ull,
0x3734313030307830ull,0x783009090a203038ull,0x6430323030303061ull,0x6330303430783020ull,
0x3061783020303837ull,0x3020393134303030ull,0x3837633030343078ull,0x61783009090a2030ull,
0x2035313030303030ull,0x3763303034307830ull,0x3130317830203038ull,0x7830203330303338ull,
0x3038373030303030ull,0x3031783009090a20ull,0x3020353138663030ull,0x3837633330363078ull,
0x3030303178302030ull,0x3078302039313866ull,0x2030383763333034ull,0x303031783009090aull,
0x7830206430386630ull,0x3038376333303630ull,0x3030303031783020ull,0x3434783020313063ull,
0x0a20323837633030ull,0x3531303478300909ull,0x3078302035303030ull,0x2030383730303030ull,
0x3230343130367830ull,0x3030307830203530ull,0x090a203038373430ull,0x3030313033783009ull,
0x3463783020353032ull,0x3020303837303031ull,0x3030303431303678ull,0x3030303078302031ull,
0x09090a2030383734ull,0x3030303030327830ull,0x3034307830203130ull,0x7830203038376332ull,
0x3130303032303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x6662656337303378ull,
0x3132633678302064ull,0x3278302038633734ull,0x2064313863303030ull,0x3730303234307830ull,
0x783009090a203038ull,0x3330303639313031ull,0x3030303030783020ull,0x3031783020303832ull,
0x3020353030303030ull,0x3030303030303078ull,0x31783009090a2033ull,0x2063303431303030ull,
0x3831323030317830ull,0x3030317830203030ull,0x7830203930633030ull,0x3038376333303030ull,
0x3064783009090a20ull,0x3020393030303138ull,0x3837303034343078ull,0x3138306478302030ull,
0x3078302031303230ull,0x2030383730303434ull,0x303033783009090aull,0x7830203530343038ull,
0x3038373030313463ull,0x3031303064783020ull,0x3430783020313030ull,0x0a20303837343030ull,
0x6530306478300909ull,0x6178302031306530ull,0x2030383730306330ull,0x3030303030337830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3065303064783009ull,0x3038783020313165ull,
0x3020303837303063ull,0x3061323030303178ull,0x3030343478302035ull,0x09090a2030383763ull,
0x3031303030617830ull,0x3030307830203134ull,0x7830203038373830ull,0x3930616530303132ull,
0x3830363430783020ull,0x3009090a20303837ull,0x3236303031303478ull,0x3030303078302035ull,
0x3378302030383730ull,0x2031303430663130ull,0x3730303163657830ull,0x783009090a203038ull,
0x3932323130313033ull,0x3030313463783020ull,0x3064783020303837ull,0x3020313030303238ull,
0x3837303034343078ull,0x33783009090a2030ull,0x2035323830383030ull,0x3730303134657830ull,
0x3130367830203038ull,0x7830203132343030ull,0x3038373832303030ull,0x3032783009090a20ull,
0x3020313030303030ull,0x3837383030343078ull,0x3030306178302030ull,0x3078302031323432ull,
0x2030383738303030ull,0x303032783009090aull,0x7830203532303130ull,0x3038376330303430ull,
0x3031303033783020ull,0x6365783020313230ull,0x0a20303837303031ull,0x3830303478300909ull,
0x3178302038323630ull,0x2063303438323030ull,0x3031303030327830ull,0x3034307830203130ull,
0x090a203038373432ull,0x3130313033783009ull,0x3463783020393334ull,0x3020303837303031ull,
0x3030626231303278ull,0x3030303078302033ull,0x09090a2030383730ull,0x3231303030617830ull,
0x3030307830203934ull,0x7830203038373830ull,0x6430343038303036ull,0x3833303030783020ull,
0x3009090a20303837ull,0x3130383030303178ull,0x3231303478302030ull,0x3278302038323630ull,
0x2030303638363030ull,0x3438323030317830ull,0x783009090a206330ull,0x3931343130313033ull,
0x3030313463783020ull,0x3032783020303837ull,0x3020313030313030ull,0x3837303030343078ull,
0x36783009090a2030ull,0x2035303430323130ull,0x3738313030307830ull,0x3130327830203038ull,
0x7830203330306262ull,0x3038373030303030ull,0x3032783009090a20ull,0x3020633032383530ull,
0x3030383030303178ull,0x3030306178302034ull,0x3078302064303830ull,0x2030383763303030ull,
0x303032783009090aull,0x7830203130303130ull,0x3038376330303430ull,0x3038303033783020ull,
0x3063783020393034ull,0x0a20303837303031ull,0x3030303178300909ull,0x3078302064303430ull,
0x2030383763333034ull,0x3062623130327830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3032303064783009ull,0x3030783020393036ull,0x3020303837343030ull,0x3065306530306478ull,
0x3034306178302035ull,0x09090a2030383730ull,0x6538323030327830ull,0x3030307830203530ull,
0x7830203330303030ull,0x3130323065303064ull,0x3030303061783020ull,0x3009090a20303837ull,
0x3030303030303378ull,0x3030303078302033ull,0x6178302030383730ull,0x2035323630303030ull,
0x3734313134307830ull,0x783009090a203038ull,0x3932323130303061ull,0x3430303434783020ull,
0x3061783020303837ull,0x3020643230303030ull,0x3837343131343078ull,0x39783009090a2030ull,
0x2031333431303030ull,0x3730303030307830ull,0x3030617830203038ull,0x7830203932363130ull,
0x3038373436303434ull,0x3032783009090a20ull,0x3020313338396533ull,0x6666666666663078ull,
0x6330306378302066ull,0x3078302039323431ull,0x2030633763303030ull,0x303061783009090aull,
0x7830203932343130ull,0x3038373436303438ull,0x3235313034783020ull,0x3030783020353334ull,
0x0a20303837303030ull,0x3431303678300909ull,0x3078302035333632ull,0x2030383734333030ull,
0x6131303130337830ull,0x3134637830203533ull,0x090a203038373030ull,0x3234313036783009ull,
0x3030783020353334ull,0x3020303837343330ull,0x3336313034303278ull,0x3330343078302035ull,
0x09090a2030383734ull,0x6131303030617830ull,0x3034347830203533ull,0x7830203038373436ull,
0x3133613163303063ull,0x6330303030783020ull,0x3009090a20306337ull,0x3338313030306178ull,
0x3630343878302031ull,0x3278302030383734ull,0x2039323431303030ull,0x3730333034307830ull,
0x783009090a203038ull,0x3133613232313034ull,0x3030303030783020ull,0x3036783020303837ull,
0x3020313338323331ull,0x3837303330303078ull,0x33783009090a2030ull,0x2031333831303130ull,
0x3730303134637830ull,0x3130367830203038ull,0x7830203133383232ull,0x3038373033303030ull,
0x3033783009090a20ull,0x3020643238313030ull,0x3837633230343078ull,0x6230303378302030ull,
0x3678302035323231ull,0x2030383763303034ull,0x303064783009090aull,0x7830203130363030ull,
0x3038373830303430ull,0x3066313033783020ull,0x3465783020313030ull,0x0a20303837303031ull,
0x3030303378300909ull,0x3078302039323231ull,0x2030383738323034ull,0x3030303030617830ull,
0x3063327830203532ull,0x090a203038373431ull,0x3161303064783009ull,0x3430783020353232ull,
0x3020303837383030ull,0x6637306337303378ull,0x3130633678302064ull,0x09090a2038633734ull,
0x3030303030327830ull,0x3034307830203130ull,0x7830203038373432ull,0x3130303033303064ull,
0x6332303430783020ull,0x3009090a20303035ull,0x3030303030303378ull,0x3030303078302033ull,
0x6678302030383730ull,0x2031303030303030ull,0x3030303030657830ull,0x7d0a7d090a203130ull,
0x0a7b2065646f630aull,0x203d20656d616e09ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f30ull,0x6969347261686375ull,0x6666666666666669ull,0x6c090a6269695f53ull,
0x0a30203d206d656dull,0x203d206d656d7309ull,0x20676572090a3737ull,0x62090a3232203d20ull,
0x0a30203d20207261ull,0x7b2074736e6f6309ull,0x6e6765730909090aull,0x6f63203d20656d61ull,
0x730909090a74736eull,0x3d20206d756e6765ull,0x666f0909090a3120ull,0x203d202074657366ull,
0x7479620909090a30ull,0x32203d2020207365ull,0x206d656d09090a34ull,0x3078300909090a7bull,
0x2066663330303030ull,0x3430303036347830ull,0x3030307830203030ull,0x7830203130303030ull,
0x3030303030383034ull,0x6678300909090a20ull,0x2066666666666666ull,0x3030666630307830ull,
0x0a7d09090a206666ull,0x636e6962090a7d09ull,0x09090a7b2065646full,0x3230303830647830ull,
0x3430307830203530ull,0x7830203038373030ull,0x3930343030303031ull,0x3430303034783020ull,
0x3009090a20303837ull,0x3032303030306178ull,0x3030343078302064ull,0x3178302030383730ull,
0x2035303230303030ull,0x3734303030347830ull,0x783009090a203038ull,0x3930303030303061ull,
0x3030303430783020ull,0x3036783020303837ull,0x3020643265343230ull,0x3837633032303078ull,
0x36783009090a2030ull,0x2035336334313030ull,0x3738303230307830ull,0x3030337830203038ull,
0x7830206466666362ull,0x3863373031326336ull,0x3033783009090a20ull,0x3020646664636430ull,
0x6332303132633678ull,0x3030303378302038ull,0x3078302033303030ull,0x2030303130303030ull,
0x303061783009090aull,0x7830203930613130ull,0x3038373431303434ull,0x3130303031783020ull,
0x3434783020313032ull,0x0a20303837633030ull,0x3030306178300909ull,0x3478302031313631ull,
0x2030383734313034ull,0x3631303030317830ull,0x3034347830203530ull,0x090a203038376330ull,
0x6432303065783009ull,0x3030783020313065ull,0x3020303837303032ull,0x3165643430306578ull,
0x3032303078302035ull,0x09090a2030383734ull,0x6564323030657830ull,0x3234307830203530ull,
0x7830203038373030ull,0x3931656434303065ull,0x3431323430783020ull,0x3009090a20303837ull,
0x3030303134306278ull,0x3634306278302063ull,0x6578302063316130ull,0x2039306564323030ull,
0x3763303238307830ull,0x783009090a203038ull,0x3131656434303065ull,0x6331323830783020ull,
0x3162783020303837ull,0x3020343032373134ull,0x3036373634316278ull,0x62783009090a2063ull,
0x2034303230323030ull,0x3630343030627830ull,0x3031627830203830ull,0x7830203430343731ull,
0x3830383732303162ull,0x3062783009090a20ull,0x3020303330303130ull,0x3261303230306278ull,
0x3030306478302038ull,0x3278302035303839ull,0x2030383730303030ull,0x343062783009090aull,
0x7830203030383130ull,0x6330343135343062ull,0x3030303461783020ull,0x6330783020646631ull,
0x0a20386337383132ull,0x3034306278300909ull,0x6278302034323230ull,0x2030323430333430ull,
0x3035343030317830ull,0x3030307830203330ull,0x090a203030313030ull,0x3131383065783009ull,
0x3830783020313034ull,0x3020303837383234ull,0x3034313034306578ull,0x3036343078302031ull,
0x09090a2033343030ull,0x3431613030637830ull,0x3430627830206330ull,0x7830203830343130ull,
0x3131303030303065ull,0x6330303830783020ull,0x3009090a20303837ull,0x3034313830306378ull,
0x3030303078302035ull,0x6578302030383730ull,0x2031313430303030ull,0x3730313030307830ull,
0x783009090a203038ull,0x6431343138303065ull,0x3430303030783020ull,0x3065783020303837ull,
0x3020353038313138ull,0x3837303334383078ull,0x63783009090a2030ull,0x2039313831393030ull,
0x3730303030307830ull,0x3030657830203038ull,0x7830203531343030ull,0x3038373031303030ull,
0x3065783009090a20ull,0x3020313134316130ull,0x3837633130303078ull,0x3138306578302030ull,
0x3078302031303831ull,0x2030383734303438ull,0x303065783009090aull,0x7830206433383139ull,
0x3038373831303030ull,0x3163303063783020ull,0x3062783020383338ull,0x0a20303438303334ull,
0x3030306278300909ull,0x3078302039313831ull,0x2030383730303038ull,0x3831633030657830ull,
0x3030307830203530ull,0x090a203038376333ull,0x3030303065783009ull,0x3830783020353430ull,
0x3020303837383330ull,0x3165303035306278ull,0x3035306278302063ull,0x09090a2030343830ull,
0x3230303030627830ull,0x3038307830203934ull,0x7830203038373833ull,0x3534633030303065ull,
0x3434303030783020ull,0x3009090a20303837ull,0x3036303035306278ull,0x3235306278302063ull,
0x6578302063343230ull,0x2031346330303030ull,0x3734343030307830ull,0x783009090a203038ull,
0x6333653132353062ull,0x3133353062783020ull,0x3065783020383363ull,0x3020313034303230ull,
0x3837343130303078ull,0x62783009090a2030ull,0x2039306530303030ull,0x3763303030307830ull,
0x3030657830203038ull,0x7830206430633036ull,0x3038373034303030ull,0x3062783009090a20ull,
0x3020343165316530ull,0x3030303230306278ull,0x3030306278302030ull,0x3078302039303630ull,
0x2030383734313030ull,0x303065783009090aull,0x7830203130303138ull,0x3038373030303030ull,
0x3139303065783020ull,0x3030783020643032ull,0x0a20303837383030ull,0x3030306278300909ull,
0x6278302038333830ull,0x2034343230333030ull,0x6331343430627830ull,0x3430627830203830ull,
0x090a203430323231ull,0x3032343062783009ull,0x3062783020633330ull,0x3020303436303134ull,
0x3061663030313178ull,0x3030313178302030ull,0x09090a2034306366ull,0x3866303030317830ull,
0x3036307830203131ull,0x7830203038376333ull,0x3531386630303031ull,0x6333303430783020ull,
0x3009090a20303837ull,0x3030393230303178ull,0x3030303178302063ull,0x3178302038303439ull,
0x2063313239323030ull,0x3839303030317830ull,0x783009090a203831ull,0x3330306634303031ull,
0x3030303030783020ull,0x3031783020303837ull,0x3020313438663030ull,0x3837633330363078ull,
0x31783009090a2030ull,0x2035343866303030ull,0x3763333034307830ull,0x3030317830203038ull,
0x7830206433386630ull,0x3038376333303630ull,0x3031783009090a20ull,0x3020393338663030ull,
0x3837633330343078ull,0x3030303178302030ull,0x3078302064313866ull,0x2030383763333036ull,
0x303031783009090aull,0x7830203931386630ull,0x3038376333303430ull,0x6630303031783020ull,
0x3630783020643038ull,0x0a20303837633330ull,0x3030303178300909ull,0x3078302039303866ull,
0x2030383763333034ull,0x3439323030317830ull,0x3030317830203430ull,0x090a203031303930ull,
0x3932303031783009ull,0x3031783020303038ull,0x3020343132393030ull,0x6631643238303378ull,
0x3036633678302064ull,0x09090a2038633738ull,0x3066663331327830ull,0x6666307830203932ull,
0x7830206666666666ull,0x3330303262303031ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3232326530306278ull,0x3135306278302030ull,0x6278302034323031ull,0x2030333031393430ull,
0x6331393430627830ull,0x783009090a203432ull,0x3033323263343062ull,0x3163303062783020ull,
0x3062783020343232ull,0x3020343232313031ull,0x3232316630306278ull,0x62783009090a2034ull,
0x2030333031393030ull,0x3831383430627830ull,0x3430627830203032ull,0x7830203032323138ull,
0x3032383138303062ull,0x3062783009090a20ull,0x3020646631313338ull,0x6337343034303678ull,
0x6230306178302038ull,0x3078302033303031ull,0x2030303030303030ull,0x303031783009090aull,
0x7830203330303162ull,0x3030313030303030ull,0x3031383065783020ull,0x3830783020353263ull,
0x0a20303837383134ull,0x3138306578300909ull,0x3078302031323430ull,0x2030383738303438ull,
0x6330303430657830ull,0x3634307830203532ull,0x090a203334303030ull,0x3030343065783009ull,
0x3430783020313234ull,0x3020333430303036ull,0x3030316230303478ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3239363030627830ull,0x3030627830203035ull,0x7830203033303932ull,
0x3934343037303063ull,0x3030303030783020ull,0x3009090a20303837ull,0x3463303330306578ull,
0x3430303078302064ull,0x6578302030383738ull,0x2039346330323030ull,0x3763343030307830ull,
0x783009090a203038ull,0x3535633032303063ull,0x3030303030783020ull,0x3065783020303837ull,
0x3020393163303230ull,0x3837383430343078ull,0x65783009090a2030ull,0x2039303031393030ull,
0x3734353038307830ull,0x3030657830203038ull,0x7830203930383139ull,0x3038373830303030ull,
0x3062783009090a20ull,0x3020343236323634ull,0x3134323634306278ull,0x3030306278302038ull,
0x3078302039316132ull,0x2030383738313038ull,0x303065783009090aull,0x7830203930383238ull,
0x3038373830303030ull,0x3263303065783020ull,0x3030783020313238ull,0x0a20303837383030ull,
0x3630306278300909ull,0x6278302038303231ull,0x2038303430383030ull,0x3630373030657830ull,
0x3030307830206430ull,0x090a203038373830ull,0x3233303062783009ull,0x3062783020383134ull,
0x3020383063303630ull,0x3134303634306278ull,0x3734306278302063ull,0x09090a2030323430ull,
0x6330323530627830ull,0x3430627830203432ull,0x7830206331633037ull,0x3831633038343062ull,
0x3039343062783020ull,0x3009090a20303236ull,0x3065303630306278ull,0x3830306278302063ull,
0x6278302063303630ull,0x2063313630383030ull,0x3430373030627830ull,0x783009090a203432ull,
0x3831323265343062ull,0x3039303062783020ull,0x3062783020633032ull,0x3020303363303135ull,
0x3236303934306278ull,0x62783009090a2030ull,0x2038346330633430ull,0x6331633030627830ull,
0x3030627830206334ull,0x7830203033303933ull,0x3434323232353062ull,0x3062783009090a20ull,
0x3020383332313234ull,0x3232316334306278ull,0x3834306278302034ull,0x6278302038303230ull,
0x2030323232333530ull,0x343062783009090aull,0x7830206331653065ull,0x3830343039303062ull,
0x3130313062783020ull,0x3062783020303230ull,0x0a20383034303730ull,0x6634306278300909ull,
0x6278302034323031ull,0x2030323430343030ull,0x6330393030627830ull,0x3030627830203033ull,
0x090a203830303133ull,0x3130303062783009ull,0x3062783020633138ull,0x3020633036383230ull,
0x3365306334306278ull,0x3334306278302038ull,0x09090a2063303031ull,0x6530653430627830ull,
0x3030637830203032ull,0x7830206333363032ull,0x3434383136343062ull,0x3138343062783020ull,
0x3009090a20303338ull,0x3234303138306578ull,0x3034383078302031ull,0x6578302030383738ull,
0x2039313630323030ull,0x3763333030307830ull,0x783009090a203038ull,0x3034303065343062ull,
0x3032303063783020ull,0x3065783020383334ull,0x3020313234303034ull,0x3430303036343078ull,
0x65783009090a2033ull,0x2064333430323030ull,0x3738313030307830ull,0x3530627830203038ull,
0x7830203434323131ull,0x3432383130313062ull,0x3065783009090a20ull,0x3020313430313830ull,
0x3837383330383078ull,0x6534306278302030ull,0x6278302038346531ull,0x2030333430383430ull,
0x313062783009090aull,0x7830203432323131ull,0x6334653132353062ull,0x3163303065783020ull,
0x3030783020313430ull,0x0a20303837303430ull,0x3930306278300909ull,0x6278302034326130ull,
0x2034346330323530ull,0x6331303030627830ull,0x3038307830203934ull,0x090a203038376334ull,
0x3163303065783009ull,0x3030783020393330ull,0x3020303837303430ull,0x3165303930306278ull,
0x3231306278302038ull,0x09090a2030343232ull,0x3831633030657830ull,0x3030307830203933ull,
0x7830203038373833ull,0x6331633037343062ull,0x3130313062783020ull,0x3009090a20383363ull,
0x3132313030306278ull,0x3130383078302064ull,0x6578302030383763ull,0x2035323630333030ull,
0x3738333030307830ull,0x783009090a203038ull,0x3034633037303063ull,0x3139303062783020ull,
0x3065783020383365ull,0x3020393463303730ull,0x3837303430303078ull,0x63783009090a2030ull,
0x2034346330363030ull,0x6331663430627830ull,0x3030657830206333ull,0x7830203134633036ull,
0x3038373834303030ull,0x3062783009090a20ull,0x3020633332316634ull,0x3230323135306278ull,
0x3934306278302034ull,0x6278302038343432ull,0x2034323032393430ull,0x343062783009090aull,
0x7830203432323239ull,0x3834343239303062ull,0x3031383065783020ull,0x3830783020353263ull,
0x0a20303837383134ull,0x3034306578300909ull,0x3078302035326330ull,0x2033343030303634ull,
0x3231393030657830ull,0x3038307830203534ull,0x090a203038373434ull,0x3030303062783009ull,
0x3830783020313563ull,0x3020303837343230ull,0x3432313431306578ull,0x3430303078302035ull,
0x09090a2030383734ull,0x3231343130657830ull,0x3030307830203534ull,0x7830203038373434ull,
0x3534383234313065ull,0x3434303030783020ull,0x3009090a20303837ull,0x3432323030306278ull,
0x3430303078302035ull,0x6578302030383738ull,0x2039346530373030ull,0x3734343030307830ull,
0x783009090a203038ull,0x3434303232313062ull,0x3230353062783020ull,0x3062783020303432ull,
0x3020303434323035ull,0x3463313131306278ull,0x62783009090a2038ull,0x2063343261323130ull,
0x3432333530627830ull,0x3530627830203435ull,0x7830206334633133ull,0x3435323235353062ull,
0x3062783009090a20ull,0x3020633436323531ull,0x3430323331306278ull,0x3331306278302063ull,
0x6278302034356531ull,0x2063343432353130ull,0x353062783009090aull,0x7830203834363232ull,
0x3834613232353062ull,0x3130303132783020ull,0x3430783020393234ull,0x0a20306337303134ull,
0x3030303578300909ull,0x3078302033303030ull,0x2030303130303030ull,0x3432303030627830ull,
0x3030307830203934ull,0x090a203038376334ull,0x3233383062783009ull,0x3036783020646635ull,
0x3020386337343034ull,0x3030313630303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x3030303030357830ull,0x3030307830203330ull,0x7830203038373030ull,0x3130303030303066ull,
0x3030303065783020ull,0x3009090a20323030ull,0x3034316337303378ull,0x3130633678302035ull,
0x3278302030383730ull,0x2031303064303430ull,0x3738323234307830ull,0x783009090a203038ull,
0x3130303031303064ull,0x3030303430783020ull,0x3033783020303837ull,0x3020646631306337ull,
0x6337383030633678ull,0x61783009090a2038ull,0x2033303063633030ull,0x3030303030307830ull,
0x3030317830203030ull,0x7830203330303963ull,0x3038323030303030ull,0x3064783009090a20ull,
0x3020353030383030ull,0x3837303030303278ull,0x3030303278302030ull,0x3078302031303465ull,
0x2030383730303234ull,0x303461783009090aull,0x7830203930303030ull,0x3038373830323030ull,
0x3030303461783020ull,0x3030783020393132ull,0x0a20303837383032ull,0x3030346178300909ull,
0x3078302064313430ull,0x2030383738303230ull,0x3230323030347830ull,0x3030347830203830ull,
0x090a203031323036ull,0x3037303034783009ull,0x3030783020353132ull,0x3020303837303030ull,
0x3034303031303378ull,0x3031346378302039ull,0x09090a2030383730ull,0x3830303130337830ull,
0x3134637830203131ull,0x7830203038373030ull,0x3531613030313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3030303230303678ull,0x3030303078302035ull,0x3678302030383738ull,
0x2039303030363030ull,0x3730313030307830ull,0x783009090a203038ull,0x3130303037303036ull,
0x3431303030783020ull,0x3061783020303837ull,0x3020643032303030ull,0x3837633030343078ull,
0x61783009090a2030ull,0x2035313430303030ull,0x3763303034307830ull,0x3030617830203038ull,
0x7830203931303030ull,0x3038376330303430ull,0x3031783009090a20ull,0x3020333030636330ull,
0x3837303030303078ull,0x3030303178302030ull,0x3078302039313866ull,0x2030383763333036ull,
0x303031783009090aull,0x7830203531386630ull,0x3038376333303430ull,0x6630303031783020ull,
0x3630783020643038ull,0x0a20303837633330ull,0x3030303178300909ull,0x3478302031306330ull,
0x2032383763303034ull,0x3030373130347830ull,0x3030307830203530ull,0x090a203038373030ull,
0x3036313036783009ull,0x3030783020353032ull,0x3020303837343030ull,0x3032303031303378ull,
0x3031346378302035ull,0x09090a2030383730ull,0x3030363130367830ull,0x3030307830203130ull,
0x7830203038373430ull,0x3130303030303032ull,0x3433303430783020ull,0x3009090a20303837ull,
0x3030303230303378ull,0x3031346378302031ull,0x3378302030383730ull,0x2064663365633730ull,
0x3734313263367830ull,0x783009090a203863ull,0x6431386330303032ull,0x3030323430783020ull,
0x3031783020303837ull,0x3020333030666430ull,0x3832303030303078ull,0x31783009090a2030ull,
0x2035303030303030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830206330383130ull,
0x3030343132303031ull,0x3031783009090a20ull,0x3020393063303030ull,0x3837633330303078ull,
0x3538306478302030ull,0x3078302039303030ull,0x2030383730303434ull,0x383064783009090aull,
0x7830203130323035ull,0x3038373030343430ull,0x3038303033783020ull,0x3463783020353034ull,
0x0a20303837303031ull,0x3130306478300909ull,0x3078302031303030ull,0x2030383734303034ull,
0x6530653030647830ull,0x6330617830203130ull,0x090a203038373030ull,0x3030303033783009ull,
0x3030783020333030ull,0x3020303837303030ull,0x3165306530306478ull,0x3063303878302031ull,
0x09090a2030383730ull,0x3232303030317830ull,0x3034347830203530ull,0x7830203038376330ull,
0x3134303130303061ull,0x3830303030783020ull,0x3009090a20303837ull,0x3032653030313278ull,
0x3036343078302039ull,0x3478302030383738ull,0x2035323630303130ull,0x3730303030307830ull,
0x783009090a203038ull,0x3130343066313033ull,0x3030316365783020ull,0x3033783020303837ull,
0x3020393232313031ull,0x3837303031346378ull,0x64783009090a2030ull,0x2031303030323830ull,
0x3730303434307830ull,0x3030337830203038ull,0x7830203532383038ull,0x3038373030313465ull,
0x3036783009090a20ull,0x3020313234303031ull,0x3837383230303078ull,0x3030303278302030ull,
0x3078302031303030ull,0x2030383738303034ull,0x303061783009090aull,0x7830203132343230ull,
0x3038373830303030ull,0x3130303032783020ull,0x3430783020353230ull,0x0a20303837633030ull,
0x3130303378300909ull,0x6578302031323030ull,0x2030383730303163ull,0x3630383030347830ull,
0x3030317830203832ull,0x090a206330343832ull,0x3130303032783009ull,0x3430783020313030ull,
0x3020303837343230ull,0x3334313031303378ull,0x3031346378302039ull,0x09090a2030383730ull,
0x3034303130327830ull,0x3030307830203330ull,0x7830203038373030ull,0x3934323130303061ull,
0x3830303030783020ull,0x3009090a20303837ull,0x3034303830303678ull,0x3330303078302064ull,
0x3178302030383738ull,0x2030313038303030ull,0x3630323130347830ull,0x783009090a203832ull,
0x3030363835303032ull,0x3832303031783020ull,0x3033783020633034ull,0x3020353134313031ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2031303031303030ull,0x3730303034307830ull,
0x3130367830203038ull,0x7830203530343032ull,0x3038373431303030ull,0x3032783009090a20ull,
0x3020333030343031ull,0x3837303030303078ull,0x3630303278302030ull,0x3178302063303238ull,
0x2034303038303030ull,0x303061783009090aull,0x7830206430383030ull,0x3038376330303030ull,
0x3130303032783020ull,0x3430783020313030ull,0x0a20303837633030ull,0x3830303378300909ull,
0x6378302039303430ull,0x2030383730303130ull,0x3430303030317830ull,0x3034307830206430ull,
0x090a203038376333ull,0x3430313032783009ull,0x3030783020333030ull,0x3020303837303030ull,
0x3036303230306478ull,0x3030303078302039ull,0x09090a2030383734ull,0x6530653030647830ull,
0x3430617830203530ull,0x7830203038373030ull,0x3530653832303032ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3032306530306478ull,0x3030306178302031ull,0x3378302030383730ull,
0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,0x3532363030303061ull,
0x3431313430783020ull,0x3061783020303837ull,0x3020393232313030ull,0x3837343030343478ull,
0x61783009090a2030ull,0x2064323030303030ull,0x3734313134307830ull,0x3030397830203038ull,
0x7830203133343130ull,0x3038373030303030ull,0x3061783009090a20ull,0x3020393236313030ull,
0x3837343630343478ull,0x6533303278302030ull,0x3078302031333839ull,0x2066666666666666ull,
0x303063783009090aull,0x7830203932343163ull,0x3063376330303030ull,0x3130303061783020ull,
0x3438783020393234ull,0x0a20303837343630ull,0x3531303478300909ull,0x3078302035333432ull,
0x2030383730303030ull,0x3632343130367830ull,0x3030307830203533ull,0x090a203038373433ull,
0x3130313033783009ull,0x3463783020353361ull,0x3020303837303031ull,0x3334323431303678ull,
0x3330303078302035ull,0x09090a2030383734ull,0x3631303430327830ull,0x3034307830203533ull,
0x7830203038373433ull,0x3533613130303061ull,0x3436303434783020ull,0x3009090a20303837ull,
0x3361316330306378ull,0x3030303078302031ull,0x6178302030633763ull,0x2031333831303030ull,
0x3734363034387830ull,0x783009090a203038ull,0x3932343130303032ull,0x3033303430783020ull,
0x3034783020303837ull,0x3020313361323231ull,0x3837303030303078ull,0x36783009090a2030ull,
0x2031333832333130ull,0x3730333030307830ull,0x3130337830203038ull,0x7830203133383130ull,
0x3038373030313463ull,0x3036783009090a20ull,0x3020313338323231ull,0x3837303330303078ull,
0x3030303378302030ull,0x3078302064323831ull,0x2030383763323034ull,0x303033783009090aull,
0x7830203532323162ull,0x3038376330303436ull,0x3030303064783020ull,0x3430783020313036ull,
0x0a20303837383030ull,0x6631303378300909ull,0x6578302031303030ull,0x2030383730303134ull,
0x3231303030337830ull,0x3034307830203932ull,0x090a203038373832ull,0x3030303061783009ull,
0x6332783020353230ull,0x3020303837343130ull,0x3232316130306478ull,0x3030343078302035ull,
0x09090a2030383738ull,0x3730633730337830ull,0x3063367830206466ull,0x7830203863373431ull,
0x3130303030303032ull,0x3432303430783020ull,0x3009090a20303837ull,0x3030303330306478ull,
0x3230343078302031ull,0x3378302030303563ull,0x2033303030303030ull,0x3730303030307830ull,
0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,0x0a7d090a20313030ull,
0x7b2065646f630a7dull,0x3d20656d616e090aull,0x6e614d36315a5f20ull,0x31746f72626c6564ull,
0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,
0x6269695f30535f32ull,0x3d206d656d6c090aull,0x6d656d73090a3020ull,0x72090a3936203d20ull,
0x3531203d20206765ull,0x3d2020726162090aull,0x736e6f63090a3020ull,0x730909090a7b2074ull,
0x3d20656d616e6765ull,0x090a74736e6f6320ull,0x6d756e6765730909ull,0x09090a31203d2020ull,
0x2074657366666f09ull,0x0909090a30203d20ull,0x2020207365747962ull,0x6d09090a3631203dull,
0x0909090a7b206d65ull,0x3330303030307830ull,0x3030307830206666ull,0x7830206130303030ull,
0x3030303030383034ull,0x3030303030783020ull,0x7d09090a20313030ull,0x6e6962090a7d090aull,
0x090a7b2065646f63ull,0x3030383064783009ull,0x3030783020353032ull,0x3020303837303034ull,
0x3034303030303178ull,0x3030303478302039ull,0x09090a2030383734ull,0x3230303030617830ull,
0x3034307830206430ull,0x7830203038373030ull,0x3530323030303031ull,0x3430303034783020ull,
0x3009090a20303837ull,0x3030303030306178ull,0x3030343078302039ull,0x3678302030383730ull,
0x2035306534323030ull,0x3763303230307830ull,0x783009090a203038ull,0x6430633431303036ull,
0x3830323030783020ull,0x3033783020303837ull,0x3020646666633130ull,0x6337303132633678ull,
0x33783009090a2038ull,0x2064666463333030ull,0x3230313263367830ull,0x3030337830203863ull,
0x7830203330303030ull,0x3030313030303030ull,0x3031783009090a20ull,0x3020313063303030ull,
0x3837633030343478ull,0x3330303478302030ull,0x3078302039303030ull,0x2030383730303030ull,
0x303036783009090aull,0x7830203930323032ull,0x3038373830303030ull,0x3030313033783020ull,
0x3463783020393034ull,0x0a20303837303031ull,0x3230303678300909ull,0x3078302031303030ull,
0x2030383738303030ull,0x3030303030327830ull,0x3034307830203132ull,0x090a203038376330ull,
0x3132303033783009ull,0x3463783020313030ull,0x3020303837303031ull,0x3138633030303278ull,
0x3032343078302064ull,0x09090a2030383730ull,0x6530653030647830ull,0x6330387830203130ull,
0x7830203038373030ull,0x3930303038303033ull,0x3030313465783020ull,0x3009090a20303837ull,
0x6637306337303378ull,0x3030633678302064ull,0x6178302038633763ull,0x2033303064323030ull,
0x3030303030307830ull,0x783009090a203030ull,0x3931303030303061ull,0x3830303430783020ull,
0x3061783020303837ull,0x3020313132303030ull,0x3837383030343078ull,0x61783009090a2030ull,
0x2035313830303030ull,0x3738303034307830ull,0x3030317830203038ull,0x7830203330306332ull,
0x3038323030303030ull,0x3032783009090a20ull,0x3020313065386333ull,0x6666666666663078ull,
0x6530306478302066ull,0x3878302031303030ull,0x2030383730306330ull,0x303033783009090aull,
0x7830203930303038ull,0x3038373030313465ull,0x3030303061783020ull,0x3430783020353230ull,
0x0a20303837383030ull,0x3030306178300909ull,0x3078302039303830ull,0x2030383738303034ull,
0x3239363430327830ull,0x3430327830203432ull,0x090a203832343835ull,0x3030303061783009ull,
0x3430783020313032ull,0x3020303837383030ull,0x3032313030306178ull,0x3131343078302039ull,
0x09090a2030383734ull,0x3431303030617830ull,0x3134307830203532ull,0x7830203038373431ull,
0x3130303030343032ull,0x3031303430783020ull,0x3009090a20303837ull,0x3034303138303378ull,
0x3134633678302039ull,0x3378302030383730ull,0x2035323231313830ull,0x3730313463367830ull,
0x783009090a203038ull,0x3130303030303061ull,0x3431313430783020ull,0x3064783020303837ull,
0x3020393034303930ull,0x3837343030343078ull,0x33783009090a2030ull,0x2031303030313830ull,
0x3730313463367830ull,0x3030647830203038ull,0x7830203130303032ull,0x3038373430303430ull,
0x3061783009090a20ull,0x3020353230303030ull,0x3837343130633278ull,0x3230303178302030ull,
0x3078302033303064ull,0x2030383730303030ull,0x303031783009090aull,0x7830203532386630ull,
0x3038376333303630ull,0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,
0x3430306178300909ull,0x3078302033303034ull,0x2030303030303030ull,0x3638313030327830ull,
0x3030307830203130ull,0x090a203330303030ull,0x6330303033783009ull,0x6336783020646664ull,
0x3020386337633032ull,0x3030343430303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x6538343030327830ull,0x3030307830203130ull,0x7830203330303030ull,0x3130303065303064ull,
0x3030633038783020ull,0x3009090a20303837ull,0x3030303830303378ull,0x3031346578302039ull,
0x6178302030383730ull,0x2039323030303030ull,0x3738303034307830ull,0x783009090a203038ull,
0x3930383030303061ull,0x3830303430783020ull,0x3032783020303837ull,0x3020383234393634ull,
0x3234383534303278ull,0x61783009090a2063ull,0x2031303230303030ull,0x3738303034307830ull,
0x3030617830203038ull,0x7830203930343130ull,0x3038373431313430ull,0x3061783009090a20ull,
0x3020393236313030ull,0x3837343131343078ull,0x3034303278302030ull,0x3078302031303030ull,
0x2030383730313034ull,0x383033783009090aull,0x7830203930343031ull,0x3038373031346336ull,
0x3131383033783020ull,0x6336783020393234ull,0x0a20303837303134ull,0x3030306178300909ull,
0x3078302031303030ull,0x2030383734313134ull,0x3430613030647830ull,0x3034307830203930ull,
0x090a203038373430ull,0x3031383033783009ull,0x6336783020313030ull,0x3020303837303134ull,
0x3030303230306478ull,0x3030343078302031ull,0x09090a2030383734ull,0x3030303030617830ull,
0x3063327830203130ull,0x7830203038373431ull,0x3532323130303032ull,0x3030303430783020ull,
0x3009090a20303837ull,0x6633306337303378ull,0x3030633678302064ull,0x6178302061633763ull,
0x2033303062353030ull,0x3030303030307830ull,0x783009090a203030ull,0x3330306235303031ull,
0x3030303030783020ull,0x3033783020303832ull,0x3020313063633030ull,0x3837303232343078ull,
0x33783009090a2030ull,0x2031303030323030ull,0x3730303134637830ull,0x3030327830203038ull,
0x7830203130386330ull,0x3038373030323430ull,0x3064783009090a20ull,0x3020313030306530ull,
0x3837303063303878ull,0x3830303378302030ull,0x6578302039303030ull,0x2030383730303134ull,
0x303061783009090aull,0x7830203932303030ull,0x3038373830303430ull,0x3030303061783020ull,
0x3430783020393038ull,0x0a20303837383030ull,0x3634303278300909ull,0x3278302038323439ull,
0x2063323438353430ull,0x3230303030617830ull,0x3034307830203130ull,0x090a203038373830ull,
0x3130303061783009ull,0x3430783020393034ull,0x3020303837343131ull,0x3236313030306178ull,
0x3131343078302039ull,0x09090a2030383734ull,0x3030303430327830ull,0x3034307830203130ull,
0x7830203038373031ull,0x3930343031383033ull,0x3031346336783020ull,0x3009090a20303837ull,
0x3234313138303378ull,0x3134633678302039ull,0x6178302030383730ull,0x2031303030303030ull,
0x3734313134307830ull,0x783009090a203038ull,0x3930343061303064ull,0x3430303430783020ull,
0x3033783020303837ull,0x3020313030303138ull,0x3837303134633678ull,0x64783009090a2030ull,
0x2031303030323030ull,0x3734303034307830ull,0x3030617830203038ull,0x7830203130303030ull,
0x3038373431306332ull,0x3032783009090a20ull,0x3020353232313030ull,0x3837303030343078ull,
0x3030306678302030ull,0x6578302031303030ull,0x2032303030303030ull,0x303061783009090aull,
0x7830203330303437ull,0x3030303030303030ull,0x3831303032783020ull,0x3030783020313032ull,
0x0a20333030303030ull,0x3030303378300909ull,0x3678302064666663ull,0x2038633763303263ull,
0x3034373030317830ull,0x3030307830203330ull,0x090a203038323030ull,0x6330303032783009ull,
0x3430783020313063ull,0x3020303837303232ull,0x3030303230303378ull,0x3031346378302031ull,
0x09090a2030383730ull,0x3863303030327830ull,0x3234307830203130ull,0x7830203038373030ull,
0x3130303065303064ull,0x3030633038783020ull,0x3009090a20303837ull,0x3030303830303378ull,
0x3031346578302039ull,0x6178302030383730ull,0x2031323030303030ull,0x3738303034307830ull,
0x783009090a203038ull,0x3930383030303061ull,0x3830303430783020ull,0x3032783020303837ull,
0x3020303230393634ull,0x3234383534303278ull,0x61783009090a2038ull,0x2031303230303030ull,
0x3738303034307830ull,0x3030617830203038ull,0x7830203930303130ull,0x3038373431313430ull,
0x3061783009090a20ull,0x3020313234313030ull,0x3837343131343078ull,0x3034303278302030ull,
0x3078302031303030ull,0x2030383730313034ull,0x383033783009090aull,0x7830203930343031ull,
0x3038373031346336ull,0x3131383033783020ull,0x6336783020313230ull,0x0a20303837303134ull,
0x3030306178300909ull,0x3078302031303030ull,0x2030383734313134ull,0x3430383030647830ull,
0x3034307830203930ull,0x090a203038373430ull,0x3031383033783009ull,0x6336783020313030ull,
0x3020303837303134ull,0x3030303230306478ull,0x3030343078302031ull,0x09090a2030383734ull,
0x3030303030617830ull,0x3063327830203130ull,0x7830203038373431ull,0x3532323130303032ull,
0x3030303430783020ull,0x3009090a20303837ull,0x6633316337303378ull,0x3030633678302064ull,
0x3378302061633738ull,0x2033303030303030ull,0x3230303030307830ull,0x783009090a203038ull,
0x3530383830303064ull,0x3030303032783020ull,0x3061783020303837ull,0x3020393036303030ull,
0x3837343130343478ull,0x61783009090a2030ull,0x2031323230303030ull,0x3734313034347830ull,
0x3031317830203038ull,0x7830203030326630ull,0x3430346630303131ull,0x3461783009090a20ull,
0x3020646631303030ull,0x6337383132633078ull,0x3230306578302038ull,0x3078302064306164ull,
0x2030383730303230ull,0x303065783009090aull,0x7830203132616438ull,0x3038373430323030ull,
0x3130303031783020ull,0x3434783020313030ull,0x0a20303837633030ull,0x3830303178300909ull,
0x3078302033303033ull,0x2030303130303030ull,0x3666303031317830ull,0x3031317830203430ull,
0x090a203830386630ull,0x3138303063783009ull,0x3063783020633230ull,0x3020303336303330ull,
0x3230393030303178ull,0x3230303178302034ull,0x09090a2038323638ull,0x3038383030317830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3133386630303031ull,0x6333303430783020ull,
0x3009090a20303837ull,0x3238663030303178ull,0x3330363078302064ull,0x3178302030383763ull,
0x2039323866303030ull,0x3763333034307830ull,0x783009090a203038ull,0x3532386630303031ull,
0x6333303630783020ull,0x3031783020303837ull,0x3020343036383030ull,0x3030393230303178ull,
0x34783009090a2038ull,0x2033303036353130ull,0x3030303030307830ull,0x3730337830203030ull,
0x7830206466316463ull,0x3863376330326336ull,0x3031783009090a20ull,0x3020333030653830ull,
0x3832303030303078ull,0x3030306278302030ull,0x3078302064303831ull,0x2030383763323030ull,
0x383062783009090aull,0x7830206466373032ull,0x3863373031343036ull,0x3039303031783020ull,
0x3030783020333030ull,0x0a20303031303030ull,0x3030303178300909ull,0x3078302064303030ull,
0x2030383763333034ull,0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,
0x3139303063783009ull,0x3062783020633034ull,0x3020303236303330ull,0x3030386633303278ull,
0x6666663078302064ull,0x09090a2066666666ull,0x3831623430627830ull,0x3030627830203432ull,
0x7830203032343038ull,0x6466373063373033ull,0x6330306336783020ull,0x3009090a20386337ull,
0x3232303930306278ull,0x3830306378302034ull,0x3178302038323031ull,0x2033303039393030ull,
0x3230303030307830ull,0x783009090a203038ull,0x6332323139303063ull,0x3161303062783020ull,
0x3062783020303336ull,0x3020646639313238ull,0x6337303134303678ull,0x31783009090a2038ull,
0x2033303061393030ull,0x3130303030307830ull,0x3030357830203030ull,0x7830203330303030ull,
0x3038373030303030ull,0x3063783009090a20ull,0x3020633032313830ull,0x3236303330306278ull,
0x6533303278302030ull,0x3078302064303038ull,0x2066666666666666ull,0x343062783009090aull,
0x7830203432363161ull,0x3032343038303062ull,0x3063373033783020ull,0x6336783020646637ull,
0x0a20386337633030ull,0x3930306278300909ull,0x6378302034323230ull,0x2038323031383030ull,
0x3033613030317830ull,0x3030307830203330ull,0x090a203038323030ull,0x3139303063783009ull,
0x3062783020633232ull,0x3020303336316130ull,0x6639313238306278ull,0x3134303678302064ull,
0x09090a2038633730ull,0x3034613030317830ull,0x3030307830203330ull,0x7830203030313030ull,
0x3330303030303035ull,0x3030303030783020ull,0x3009090a20303837ull,0x3032313830306378ull,
0x3330306278302063ull,0x3278302030323630ull,0x2064303038643330ull,0x6666666666307830ull,
0x783009090a206666ull,0x3432363161343062ull,0x3038303062783020ull,0x3033783020303234ull,
0x3020646637306337ull,0x6337633030633678ull,0x62783009090a2038ull,0x2034323230393030ull,
0x3031383030637830ull,0x3030317830203832ull,0x7830203330306461ull,0x3038323030303030ull,
0x3063783009090a20ull,0x3020633232313930ull,0x3336316130306278ull,0x3238306278302030ull,
0x3678302064663931ull,0x2038633730313430ull,0x303031783009090aull,0x7830203330306561ull,
0x3030313030303030ull,0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,
0x3830306378300909ull,0x6278302063303231ull,0x2030323630333030ull,0x3038633330327830ull,
0x6666307830206430ull,0x090a206666666666ull,0x3161343062783009ull,0x3062783020343236ull,
0x3020303234303830ull,0x6637306337303378ull,0x3030633678302064ull,0x09090a2038633763ull,
0x3230393030627830ull,0x3030637830203432ull,0x7830203832303138ull,0x3330303762303031ull,
0x3030303030783020ull,0x3009090a20303832ull,0x3232313930306378ull,0x6130306278302063ull,
0x6278302030333631ull,0x2064663931323830ull,0x3730313430367830ull,0x783009090a203863ull,
0x3330303862303031ull,0x3030303030783020ull,0x3035783020303031ull,0x3020333030303030ull,
0x3837303030303078ull,0x63783009090a2030ull,0x2063303231383030ull,0x3630333030627830ull,
0x3330327830203032ull,0x7830206430303862ull,0x6666666666666630ull,0x3062783009090a20ull,
0x3020343236316134ull,0x3234303830306278ull,0x6337303378302030ull,0x3678302064663730ull,
0x2038633763303063ull,0x303062783009090aull,0x7830203432323039ull,0x3832303138303063ull,
0x3163303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,0x3930306378300909ull,
0x6278302063323231ull,0x2030333631613030ull,0x3931323830627830ull,0x3430367830206466ull,
0x090a203863373031ull,0x3263303031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,0x3231383030637830ull,
0x3030627830206330ull,0x7830203032363033ull,0x6430303861333032ull,0x6666666630783020ull,
0x3009090a20666666ull,0x3236316134306278ull,0x3830306278302034ull,0x3378302030323430ull,
0x2064663730633730ull,0x3763303063367830ull,0x783009090a203863ull,0x3432323039303062ull,
0x3138303063783020ull,0x3031783020383230ull,0x3020333030626330ull,0x3832303030303078ull,
0x63783009090a2030ull,0x2063323231393030ull,0x3631613030627830ull,0x3830627830203033ull,
0x7830206466393132ull,0x3863373031343036ull,0x3031783009090a20ull,0x3020333030636330ull,
0x3031303030303078ull,0x3030303578302030ull,0x3078302033303030ull,0x2030383730303030ull,
0x303063783009090aull,0x7830206330323138ull,0x3032363033303062ull,0x3839333032783020ull,
0x6630783020643030ull,0x0a20666666666666ull,0x6134306278300909ull,0x6278302034323631ull,
0x2030323430383030ull,0x3730633730337830ull,0x3063367830206466ull,0x090a203863376330ull,
0x3039303062783009ull,0x3063783020343232ull,0x3020383230313830ull,0x3030356430303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x3231393030637830ull,0x3030627830206332ull,
0x7830203033363161ull,0x6466393132383062ull,0x3031343036783020ull,0x3009090a20386337ull,
0x3030366430303178ull,0x3030303078302033ull,0x3578302030303130ull,0x2033303030303030ull,
0x3730303030307830ull,0x783009090a203038ull,0x6330323138303063ull,0x3033303062783020ull,
0x3032783020303236ull,0x3020643030383833ull,0x6666666666663078ull,0x62783009090a2066ull,
0x2034323631613430ull,0x3430383030627830ull,0x3730337830203032ull,0x7830206466373063ull,
0x3863376330306336ull,0x3062783009090a20ull,0x3020343232303930ull,0x3230313830306378ull,
0x6430303178302038ull,0x3078302033303066ull,0x2030383230303030ull,0x303063783009090aull,
0x7830206332323139ull,0x3033363161303062ull,0x3132383062783020ull,0x3036783020646639ull,
0x0a20386337303134ull,0x6530303178300909ull,0x3078302033303030ull,0x2030303130303030ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3138303063783009ull,
0x3062783020633032ull,0x3020303236303330ull,0x3030383733303278ull,0x6666663078302064ull,
0x09090a2066666666ull,0x3631613430627830ull,0x3030627830203432ull,0x7830203032343038ull,
0x6466373063373033ull,0x6330306336783020ull,0x3009090a20386337ull,0x3232303930306278ull,
0x3830306378302034ull,0x3178302038323031ull,0x2033303039653030ull,0x3230303030307830ull,
0x783009090a203038ull,0x6332323139303063ull,0x3161303062783020ull,0x3062783020303336ull,
0x3020646639313238ull,0x6337303134303678ull,0x31783009090a2038ull,0x2033303061653030ull,
0x3130303030307830ull,0x3030357830203030ull,0x7830203330303030ull,0x3038373030303030ull,
0x3063783009090a20ull,0x3020633032313830ull,0x3236303330306278ull,0x3633303278302030ull,
0x3078302064303038ull,0x2066666666666666ull,0x343062783009090aull,0x7830203432363161ull,
0x3032343038303062ull,0x3063373033783020ull,0x6336783020646637ull,0x0a20386337633030ull,
0x3930306278300909ull,0x6378302034323230ull,0x2038323031383030ull,0x3033663030317830ull,
0x3030307830203330ull,0x090a203038323030ull,0x3139303063783009ull,0x3062783020633232ull,
0x3020303336316130ull,0x6639313238306278ull,0x3134303678302064ull,0x09090a2038633730ull,
0x3034663030317830ull,0x3030307830203330ull,0x7830203030313030ull,0x3330303030303035ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3032313830306378ull,0x3330306278302063ull,
0x3278302030323630ull,0x2064303038353330ull,0x6666666666307830ull,0x783009090a206666ull,
0x3432363161343062ull,0x3038303062783020ull,0x3033783020303234ull,0x3020646637306337ull,
0x6337633030633678ull,0x62783009090a2038ull,0x2034323230393030ull,0x3031383030637830ull,
0x3030317830203832ull,0x7830203330306466ull,0x3038323030303030ull,0x3063783009090a20ull,
0x3020633232313930ull,0x3336316130306278ull,0x3238306278302030ull,0x3678302064663931ull,
0x2038633730313430ull,0x303031783009090aull,0x7830203330306566ull,0x3030313030303030ull,
0x3030303035783020ull,0x3030783020333030ull,0x0a20303837303030ull,0x3830306378300909ull,
0x6278302063303231ull,0x2030323630333030ull,0x3038343330327830ull,0x6666307830206430ull,
0x090a206666666666ull,0x3161343062783009ull,0x3062783020343236ull,0x3020303234303830ull,
0x6637306337303378ull,0x3030633678302064ull,0x09090a2038633763ull,0x3230393030627830ull,
0x3030637830203432ull,0x7830203832303138ull,0x3330303730313031ull,0x3030303030783020ull,
0x3009090a20303832ull,0x3232313930306378ull,0x6130306278302063ull,0x6278302030333631ull,
0x2064663931323830ull,0x3730313430367830ull,0x783009090a203863ull,0x3330303830313031ull,
0x3030303030783020ull,0x3035783020303031ull,0x3020333030303030ull,0x3837303030303078ull,
0x63783009090a2030ull,0x2063303231383030ull,0x3630333030627830ull,0x3330327830203032ull,
0x7830206430303833ull,0x6666666666666630ull,0x3062783009090a20ull,0x3020343236316134ull,
0x3234303830306278ull,0x6337303378302030ull,0x3678302064663730ull,0x2038633763303063ull,
0x303062783009090aull,0x7830203432323039ull,0x3832303138303063ull,0x3131313031783020ull,
0x3030783020333030ull,0x0a20303832303030ull,0x3930306378300909ull,0x6278302063323231ull,
0x2030333631613030ull,0x3931323830627830ull,0x3430367830206466ull,0x090a203863373031ull,
0x3231313031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3030303030303578ull,
0x3030303078302033ull,0x09090a2030383730ull,0x3231383030637830ull,0x3030627830206330ull,
0x7830203032363033ull,0x6430303832333032ull,0x6666666630783020ull,0x3009090a20666666ull,
0x3236316134306278ull,0x3830306278302034ull,0x3378302030323430ull,0x2064663730633730ull,
0x3763303063367830ull,0x783009090a203863ull,0x3432323039303062ull,0x3138303063783020ull,
0x3031783020383230ull,0x3020333030623131ull,0x3832303030303078ull,0x63783009090a2030ull,
0x2063323231393030ull,0x3631613030627830ull,0x3830627830203033ull,0x7830206466393132ull,
0x3863373031343036ull,0x3031783009090a20ull,0x3020333030633131ull,0x3031303030303078ull,
0x3030303578302030ull,0x3078302033303030ull,0x2030383730303030ull,0x303063783009090aull,
0x7830206330323138ull,0x3032363033303062ull,0x3831333032783020ull,0x6630783020643030ull,
0x0a20666666666666ull,0x6134306278300909ull,0x6278302034323631ull,0x2030323430383030ull,
0x3730633730337830ull,0x3063367830206466ull,0x090a203863376330ull,0x3039303062783009ull,
0x3063783020343232ull,0x3020383230313830ull,0x3030353231303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x3231393030637830ull,0x3030627830206332ull,0x7830203033363161ull,
0x6466393132383062ull,0x3031343036783020ull,0x3009090a20386337ull,0x3030363231303178ull,
0x3030303078302033ull,0x3578302030303130ull,0x2033303030303030ull,0x3730303030307830ull,
0x783009090a203038ull,0x6330323138303063ull,0x3033303062783020ull,0x3032783020303236ull,
0x3020643030383033ull,0x6666666666663078ull,0x62783009090a2066ull,0x2034323631613430ull,
0x3430383030627830ull,0x3730337830203032ull,0x7830206466373063ull,0x3863376330306336ull,
0x3062783009090a20ull,0x3020343232303930ull,0x3230313830306378ull,0x3231303178302038ull,
0x3078302033303066ull,0x2030383230303030ull,0x303063783009090aull,0x7830206332323139ull,
0x3033363161303062ull,0x3132383062783020ull,0x3036783020646639ull,0x0a20386337303134ull,
0x3331303178300909ull,0x3078302033303030ull,0x2030303130303030ull,0x3030303030357830ull,
0x3030307830203330ull,0x090a203038373030ull,0x3138303063783009ull,0x3062783020633032ull,
0x3020303236303330ull,0x3030386632303278ull,0x6666663078302064ull,0x09090a2066666666ull,
0x3631613430627830ull,0x3030627830203432ull,0x7830203032343038ull,0x6466373063373033ull,
0x6330306336783020ull,0x3009090a20386337ull,0x3232303930306278ull,0x3830306378302034ull,
0x3178302038323031ull,0x2033303039333130ull,0x3230303030307830ull,0x783009090a203038ull,
0x6332323139303063ull,0x3161303062783020ull,0x3062783020303336ull,0x3020646639313238ull,
0x6337303134303678ull,0x31783009090a2038ull,0x2033303061333130ull,0x3130303030307830ull,
0x3030357830203030ull,0x7830203330303030ull,0x3038373030303030ull,0x3063783009090a20ull,
0x3020633032313830ull,0x3236303330306278ull,0x6532303278302030ull,0x3078302064303038ull,
0x2066666666666666ull,0x343062783009090aull,0x7830203432363161ull,0x3032343038303062ull,
0x3063373033783020ull,0x6336783020646637ull,0x0a20386337633030ull,0x3930306278300909ull,
0x6378302034323230ull,0x2038323031383030ull,0x3033343130317830ull,0x3030307830203330ull,
0x090a203038323030ull,0x3139303063783009ull,0x3062783020633232ull,0x3020303336316130ull,
0x6639313238306278ull,0x3134303678302064ull,0x09090a2038633730ull,0x3034343130317830ull,
0x3030307830203330ull,0x7830203030313030ull,0x3330303030303035ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3032313830306378ull,0x3030303078302064ull,0x3278302030383730ull,
0x2031303038643230ull,0x6666666666307830ull,0x783009090a206666ull,0x6430363030303062ull,
0x6330303030783020ull,0x3033783020303837ull,0x3020353230306337ull,0x6437633030633678ull,
0x62783009090a2030ull,0x2030323631613430ull,0x3430333030627830ull,0x3030617830206330ull,
0x7830206466333130ull,0x3863373431306330ull,0x3062783009090a20ull,0x3020303232303830ull,
0x3236303330306378ull,0x3431303178302034ull,0x3078302033303066ull,0x2030383231303030ull,
0x303063783009090aull,0x7830203832303138ull,0x6332343139303062ull,0x3132383062783020ull,
0x3036783020646637ull,0x0a20386437303134ull,0x3531303178300909ull,0x3078302033303031ull,
0x2030303131303030ull,0x3030303030317830ull,0x3036307830206430ull,0x090a203038376333ull,
0x3030303035783009ull,0x3030783020333030ull,0x3020303837303030ull,0x3030313330306378ull,
0x3934306278302063ull,0x09090a2030323431ull,0x3630333030627830ull,0x3030627830206330ull,
0x7830203832323038ull,0x3432343033303062ull,0x3161303063783020ull,0x3009090a20303334ull,
0x3232313930306378ull,0x3030303078302064ull,0x3178302030383730ull,0x2033303061383030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3530363063373033ull,0x3031306336783020ull,
0x3032783020303837ull,0x3020313030643034ull,0x3837633032343078ull,0x64783009090a2030ull,
0x2031303030313030ull,0x3730303034307830ull,0x3730337830203038ull,0x7830206466313063ull,
0x3863373830306336ull,0x3061783009090a20ull,0x3020333030303731ull,0x3030303030303078ull,
0x3631303178302030ull,0x3078302033303064ull,0x2030383230303030ull,0x303064783009090aull,
0x7830203530303730ull,0x3038373030303032ull,0x6530303032783020ull,0x3430783020313030ull,
0x0a20303837303032ull,0x3030346178300909ull,0x3078302039303030ull,0x2030383738303230ull,
0x3230303034617830ull,0x3230307830203931ull,0x090a203038373830ull,0x3030303461783009ull,
0x3030783020643134ull,0x3020303837383032ull,0x3032303230303478ull,0x3630303478302038ull,
0x09090a2030323230ull,0x3230373030347830ull,0x3030307830203532ull,0x7830203038373030ull,
0x3930343030313033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3230313031303378ull,
0x3031346378302031ull,0x3378302030383730ull,0x2035323231303130ull,0x3730303134637830ull,
0x783009090a203038ull,0x3530303032303036ull,0x3830303030783020ull,0x3036783020303837ull,
0x3020393030303630ull,0x3837303230303078ull,0x36783009090a2030ull,0x2064303030373030ull,
0x3734323030307830ull,0x3030617830203038ull,0x7830203130323030ull,0x3038376330303430ull,
0x3061783009090a20ull,0x3020353234303030ull,0x3837633030343078ull,0x3030306178302030ull,
0x3078302031323630ull,0x2030383763303034ull,0x313031783009090aull,0x7830203330303037ull,
0x3038373030303030ull,0x6630303031783020ull,0x3430783020313238ull,0x0a20303837633330ull,
0x3030303178300909ull,0x3078302035323866ull,0x2030383763333036ull,0x3866303030317830ull,
0x3034307830203130ull,0x090a203038376333ull,0x3130303031783009ull,0x3434783020353065ull,
0x3020323837633030ull,0x3034306430303478ull,0x3030303078302064ull,0x09090a2030383730ull,
0x6566313031327830ull,0x3030307830203930ull,0x7830203330303030ull,0x3932363063303036ull,
0x6330303030783020ull,0x3009090a20303837ull,0x3034306631303378ull,0x3031636578302064ull,
0x3478302030383730ull,0x2064323430623030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3932343130313033ull,0x3030313463783020ull,0x3064783020303837ull,0x3020643036303338ull,
0x3837303034343078ull,0x36783009090a2030ull,0x2064323630613030ull,0x3763323030307830ull,
0x3030367830203038ull,0x7830203931343063ull,0x3038373832303030ull,0x3032783009090a20ull,
0x3020643036303030ull,0x3837383030343078ull,0x3031303378302030ull,0x6378302039323631ull,
0x2030383730303134ull,0x303032783009090aull,0x7830203130633030ull,0x3038373030303430ull,
0x3031303033783020ull,0x6365783020393136ull,0x0a20303837303031ull,0x6130303678300909ull,
0x3078302035313430ull,0x2030383738323030ull,0x3438323030317830ull,0x3030327830206330ull,
0x090a203030633830ull,0x3030303032783009ull,0x3430783020393361ull,0x3020303837343230ull,
0x3030343931303278ull,0x3030303078302033ull,0x09090a2030383730ull,0x3038303030317830ull,
0x3030317830203431ull,0x7830206330343832ull,0x3130633030303032ull,0x3833303430783020ull,
0x3009090a20303837ull,0x3261303030306178ull,0x3030303078302039ull,0x3278302030383763ull,
0x2033303034393130ull,0x3730303030307830ull,0x783009090a203038ull,0x6430343039303034ull,
0x3030303030783020ull,0x3036783020303837ull,0x3020643036303830ull,0x3837633030303078ull,
0x33783009090a2030ull,0x2064303630303130ull,0x3730303134637830ull,0x3030367830203038ull,
0x7830203530343038ull,0x3038376330303030ull,0x3032783009090a20ull,0x3020633032383830ull,
0x3030383030303178ull,0x3030303278302034ull,0x3078302031306330ull,0x2030383763303034ull,
0x303033783009090aull,0x7830203930343038ull,0x3038373030313063ull,0x3030303031783020ull,
0x3430783020643034ull,0x0a20303837633330ull,0x3931303278300909ull,0x3078302033303034ull,
0x2030383730303030ull,0x3431323030647830ull,0x3030307830203930ull,0x090a203038373430ull,
0x3065303064783009ull,0x3061783020353065ull,0x3020303837303034ull,0x3065383230303278ull,
0x3030303078302035ull,0x09090a2033303030ull,0x3230653030647830ull,0x3030617830203130ull,
0x7830203038373030ull,0x3330303030303033ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3236303030306178ull,0x3131343078302035ull,0x6178302030383734ull,0x2039323231303030ull,
0x3734303034347830ull,0x783009090a203038ull,0x6432303030303061ull,0x3431313430783020ull,
0x3039783020303837ull,0x3020313334313030ull,0x3837303030303078ull,0x61783009090a2030ull,
0x2039323631303030ull,0x3734363034347830ull,0x3330327830203038ull,0x7830203133383965ull,
0x6666666666666630ull,0x3063783009090a20ull,0x3020393234316330ull,0x6337633030303078ull,
0x3030306178302030ull,0x3878302039323431ull,0x2030383734363034ull,0x313034783009090aull,
0x7830203533343235ull,0x3038373030303030ull,0x3234313036783020ull,0x3030783020353336ull,
0x0a20303837343330ull,0x3031303378300909ull,0x6378302035336131ull,0x2030383730303134ull,
0x3432343130367830ull,0x3030307830203533ull,0x090a203038373433ull,0x3130343032783009ull,
0x3430783020353336ull,0x3020303837343330ull,0x3361313030306178ull,0x3630343478302035ull,
0x09090a2030383734ull,0x6131633030637830ull,0x3030307830203133ull,0x7830203063376330ull,
0x3133383130303061ull,0x3436303438783020ull,0x3009090a20303837ull,0x3234313030303278ull,
0x3330343078302039ull,0x3478302030383730ull,0x2031336132323130ull,0x3730303030307830ull,
0x783009090a203038ull,0x3133383233313036ull,0x3033303030783020ull,0x3033783020303837ull,
0x3020313338313031ull,0x3837303031346378ull,0x36783009090a2030ull,0x2031333832323130ull,
0x3730333030307830ull,0x3030337830203038ull,0x7830206432383130ull,0x3038376332303430ull,
0x3033783009090a20ull,0x3020353232316230ull,0x3837633030343678ull,0x3030306478302030ull,
0x3078302031303630ull,0x2030383738303034ull,0x313033783009090aull,0x7830203130303066ull,
0x3038373030313465ull,0x3130303033783020ull,0x3430783020393232ull,0x0a20303837383230ull,
0x3030306178300909ull,0x3278302035323030ull,0x2030383734313063ull,0x3231613030647830ull,
0x3034307830203532ull,0x090a203038373830ull,0x3063373033783009ull,0x6336783020646637ull,
0x3020386337343130ull,0x3030303030303278ull,0x3230343078302031ull,0x09090a2030383734ull,
0x3030333030647830ull,0x3034307830203130ull,0x7830203030356332ull,0x3330303030303033ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3030303030306678ull,0x3030306578302031ull,
0x7d090a2031303030ull,0x2065646f630a7d0aull,0x20656d616e090a7bull,0x614d36315a5f203dull,
0x746f72626c65646eull,0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f32535f32535f32ull,0x69695f30535f3253ull,0x206d656d6c090a62ull,0x656d73090a30203dull,
0x090a3936203d206dull,0x31203d2020676572ull,0x2020726162090a35ull,0x6e6f63090a30203dull,
0x0909090a7b207473ull,0x20656d616e676573ull,0x0a74736e6f63203dull,0x756e676573090909ull,
0x090a31203d20206dull,0x74657366666f0909ull,0x09090a30203d2020ull,0x2020736574796209ull,
0x09090a3631203d20ull,0x09090a7b206d656dull,0x3030303030783009ull,0x3034783020666633ull,
0x3020303030303038ull,0x6630306666303078ull,0x3030303078302066ull,0x09090a2031303030ull,
0x6962090a7d090a7dull,0x0a7b2065646f636eull,0x3038306478300909ull,0x3078302035303230ull,
0x2030383730303430ull,0x3430303030317830ull,0x3030347830203930ull,0x090a203038373430ull,
0x3030303061783009ull,0x3430783020643032ull,0x3020303837303030ull,0x3032303030303178ull,
0x3030303478302035ull,0x09090a2030383734ull,0x3030303030617830ull,0x3034307830203930ull,
0x7830203038373030ull,0x6431653432303036ull,0x6330323030783020ull,0x3009090a20303837ull,
0x3263343130303678ull,0x3032303078302031ull,0x3378302030383738ull,0x2064666663373030ull,
0x3730313263367830ull,0x783009090a203863ull,0x6466646338303033ull,0x3031326336783020ull,
0x3033783020386332ull,0x3020333030303030ull,0x3031303030303078ull,0x64783009090a2030ull,
0x2035303838303030ull,0x3730303030327830ull,0x3030617830203038ull,0x7830203930303130ull,
0x3038373431303434ull,0x3031783009090a20ull,0x3020313032313030ull,0x3837633030343478ull,
0x3030306178302030ull,0x3478302031316530ull,0x2030383734313034ull,0x303031783009090aull,
0x7830203530343130ull,0x3038376330303434ull,0x3030303461783020ull,0x6330783020646631ull,
0x0a20386337383132ull,0x3230306578300909ull,0x3078302064306164ull,0x2030383730303230ull,
0x6164343030657830ull,0x3230307830203131ull,0x090a203038373430ull,0x3130303031783009ull,
0x3434783020313030ull,0x3020303837633030ull,0x3030383130303178ull,0x3030303078302033ull,
0x09090a2030303130ull,0x3666303031317830ull,0x3031317830203430ull,0x7830203830386630ull,
0x3432383034303063ull,0x3033303063783020ull,0x3009090a20383236ull,0x3138383230303178ull,
0x3030303178302034ull,0x3178302038313638ull,0x2033303064313030ull,0x3730303030307830ull,
0x783009090a203038ull,0x3932386630303031ull,0x6333303630783020ull,0x3031783020303837ull,
0x3020353238663030ull,0x3837633330343078ull,0x31783009090a2030ull,0x2039313866303030ull,
0x3763333036307830ull,0x3030317830203038ull,0x7830203531386630ull,0x3038376333303430ull,
0x3031783009090a20ull,0x3020343036383230ull,0x3038383030303178ull,0x6630303478302038ull,
0x3078302033303062ull,0x2030303030303030ull,0x373033783009090aull,0x7830206466316463ull,
0x3863376330326336ull,0x3332303031783020ull,0x3030783020333030ull,0x0a20303832303030ull,
0x3030306278300909ull,0x3078302064303431ull,0x2030383734323030ull,0x3730313830627830ull,
0x3430367830206466ull,0x090a203863373031ull,0x3432303031783009ull,0x3030783020333030ull,
0x3020303031303030ull,0x3030303030303578ull,0x3030303078302033ull,0x09090a2030383730ull,
0x6330353030637830ull,0x3030627830206330ull,0x7830203031363033ull,0x6430303866333032ull,
0x6666666630783020ull,0x3009090a20666666ull,0x3134313934306278ull,0x3430306278302034ull,
0x3378302030313430ull,0x2064663730633730ull,0x3763303063367830ull,0x783009090a203863ull,
0x3431323035303062ull,0x3034303063783020ull,0x3031783020383138ull,0x3020333030643230ull,
0x3832303030303078ull,0x63783009090a2030ull,0x2034326130353030ull,0x3231363030627830ull,
0x3830627830203832ull,0x7830206466353131ull,0x3863373031343036ull,0x3031783009090a20ull,
0x3020333030663230ull,0x3031303030303078ull,0x3030303178302030ull,0x3078302031303630ull,
0x2030383763333036ull,0x303035783009090aull,0x7830203330303030ull,0x3038373030303030ull,
0x3034303063783020ull,0x3062783020633061ull,0x0a20303136303330ull,0x6533303278300909ull,
0x3078302064303038ull,0x2066666666666666ull,0x3231363430627830ull,0x3030627830203431ull,
0x090a203031343034ull,0x3063373033783009ull,0x6336783020646637ull,0x3020386337633030ull,
0x3132303530306278ull,0x3430306378302034ull,0x09090a2038313830ull,0x3038333030317830ull,
0x3030307830203330ull,0x7830203038323030ull,0x3432613035303063ull,0x3136303062783020ull,
0x3009090a20383232ull,0x6635313138306278ull,0x3134303678302064ull,0x3178302038633730ull,
0x2033303061333030ull,0x3130303030307830ull,0x783009090a203030ull,0x3130363030303031ull,
0x6333303430783020ull,0x3035783020303837ull,0x3020333030303030ull,0x3837303030303078ull,
0x63783009090a2030ull,0x2063306130343030ull,0x3630333030627830ull,0x3330327830203031ull,
0x7830206430303864ull,0x6666666666666630ull,0x3062783009090a20ull,0x3020343132313634ull,
0x3134303430306278ull,0x6337303378302030ull,0x3678302064663730ull,0x2038633763303063ull,
0x303062783009090aull,0x7830203431323035ull,0x3831383034303063ull,0x3334303031783020ull,
0x3030783020333030ull,0x0a20303832303030ull,0x3530306378300909ull,0x6278302034326130ull,
0x2038323231363030ull,0x3531313830627830ull,0x3430367830206466ull,0x090a203863373031ull,
0x3534303031783009ull,0x3030783020333030ull,0x3020303031303030ull,0x3036303030303178ull,
0x3330363078302031ull,0x09090a2030383763ull,0x3030303030357830ull,0x3030307830203330ull,
0x7830203038373030ull,0x6330613034303063ull,0x3033303062783020ull,0x3009090a20303136ull,
0x3030386333303278ull,0x6666663078302064ull,0x6278302066666666ull,0x2034313231363430ull,
0x3430343030627830ull,0x783009090a203031ull,0x6466373063373033ull,0x6330306336783020ull,
0x3062783020386337ull,0x3020343132303530ull,0x3138303430306378ull,0x31783009090a2038ull,
0x2033303065343030ull,0x3230303030307830ull,0x3030637830203038ull,0x7830203432613035ull,
0x3832323136303062ull,0x3062783009090a20ull,0x3020646635313138ull,0x6337303134303678ull,
0x3530303178302038ull,0x3078302033303030ull,0x2030303130303030ull,0x303031783009090aull,
0x7830203130363030ull,0x3038376333303430ull,0x3030303035783020ull,0x3030783020333030ull,
0x0a20303837303030ull,0x3430306378300909ull,0x6278302063306130ull,0x2030313630333030ull,
0x3038623330327830ull,0x6666307830206430ull,0x090a206666666666ull,0x3136343062783009ull,
0x3062783020343132ull,0x3020303134303430ull,0x6637306337303378ull,0x3030633678302064ull,
0x09090a2038633763ull,0x3230353030627830ull,0x3030637830203431ull,0x7830203831383034ull,
0x3330303935303031ull,0x3030303030783020ull,0x3009090a20303832ull,0x3261303530306378ull,
0x3630306278302034ull,0x6278302038323231ull,0x2064663531313830ull,0x3730313430367830ull,
0x783009090a203863ull,0x3330306235303031ull,0x3030303030783020ull,0x3031783020303031ull,
0x3020313036303030ull,0x3837633330363078ull,0x35783009090a2030ull,0x2033303030303030ull,
0x3730303030307830ull,0x3030637830203038ull,0x7830206330613034ull,0x3031363033303062ull,
0x3032783009090a20ull,0x3020643030386133ull,0x6666666666663078ull,0x3634306278302066ull,
0x6278302034313231ull,0x2030313430343030ull,0x373033783009090aull,0x7830206466373063ull,
0x3863376330306336ull,0x3035303062783020ull,0x3063783020343132ull,0x0a20383138303430ull,
0x3630303178300909ull,0x3078302033303034ull,0x2030383230303030ull,0x6130353030637830ull,
0x3030627830203432ull,0x090a203832323136ull,0x3131383062783009ull,0x3036783020646635ull,
0x3020386337303134ull,0x3030363630303178ull,0x3030303078302033ull,0x09090a2030303130ull,
0x3630303030317830ull,0x3034307830203130ull,0x7830203038376333ull,0x3330303030303035ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3061303430306378ull,0x3330306278302063ull,
0x3278302030313630ull,0x2064303038393330ull,0x6666666666307830ull,0x783009090a206666ull,
0x3431323136343062ull,0x3034303062783020ull,0x3033783020303134ull,0x3020646637306337ull,
0x6337633030633678ull,0x62783009090a2038ull,0x2034313230353030ull,0x3830343030637830ull,
0x3030317830203831ull,0x7830203330306636ull,0x3038323030303030ull,0x3063783009090a20ull,
0x3020343261303530ull,0x3232313630306278ull,0x3138306278302038ull,0x3678302064663531ull,
0x2038633730313430ull,0x303031783009090aull,0x7830203330303137ull,0x3030313030303030ull,
0x3030303031783020ull,0x3630783020313036ull,0x0a20303837633330ull,0x3030303578300909ull,
0x3078302033303030ull,0x2030383730303030ull,0x6130343030637830ull,0x3030627830206330ull,
0x090a203031363033ull,0x3838333032783009ull,0x6630783020643030ull,0x3020666666666666ull,
0x3132313634306278ull,0x3430306278302034ull,0x09090a2030313430ull,0x3730633730337830ull,
0x3063367830206466ull,0x7830203863376330ull,0x3431323035303062ull,0x3034303063783020ull,
0x3009090a20383138ull,0x3030613730303178ull,0x3030303078302033ull,0x6378302030383230ull,
0x2034326130353030ull,0x3231363030627830ull,0x783009090a203832ull,0x6466353131383062ull,
0x3031343036783020ull,0x3031783020386337ull,0x3020333030633730ull,0x3031303030303078ull,
0x31783009090a2030ull,0x2031303630303030ull,0x3763333034307830ull,0x3030357830203038ull,
0x7830203330303030ull,0x3038373030303030ull,0x3063783009090a20ull,0x3020633061303430ull,
0x3136303330306278ull,0x3733303278302030ull,0x3078302064303038ull,0x2066666666666666ull,
0x343062783009090aull,0x7830203431323136ull,0x3031343034303062ull,0x3063373033783020ull,
0x6336783020646637ull,0x0a20386337633030ull,0x3530306278300909ull,0x6378302034313230ull,
0x2038313830343030ull,0x3035383030317830ull,0x3030307830203330ull,0x090a203038323030ull,
0x3035303063783009ull,0x3062783020343261ull,0x3020383232313630ull,0x6635313138306278ull,
0x3134303678302064ull,0x09090a2038633730ull,0x3037383030317830ull,0x3030307830203330ull,
0x7830203030313030ull,0x3130363030303031ull,0x6333303630783020ull,0x3009090a20303837ull,
0x3030303030303578ull,0x3030303078302033ull,0x6378302030383730ull,0x2063306130343030ull,
0x3630333030627830ull,0x783009090a203031ull,0x6430303836333032ull,0x6666666630783020ull,
0x3062783020666666ull,0x3020343132313634ull,0x3134303430306278ull,0x33783009090a2030ull,
0x2064663730633730ull,0x3763303063367830ull,0x3030627830203863ull,0x7830203431323035ull,
0x3831383034303063ull,0x3031783009090a20ull,0x3020333030303930ull,0x3832303030303078ull,
0x3530306378302030ull,0x6278302034326130ull,0x2038323231363030ull,0x383062783009090aull,
0x7830206466353131ull,0x3863373031343036ull,0x3239303031783020ull,0x3030783020333030ull,
0x0a20303031303030ull,0x3030303178300909ull,0x3078302031303630ull,0x2030383763333034ull,
0x3030303030357830ull,0x3030307830203330ull,0x090a203038373030ull,0x3034303063783009ull,
0x3062783020633061ull,0x3020303136303330ull,0x3030383533303278ull,0x6666663078302064ull,
0x09090a2066666666ull,0x3231363430627830ull,0x3030627830203431ull,0x7830203031343034ull,
0x6466373063373033ull,0x6330306336783020ull,0x3009090a20386337ull,0x3132303530306278ull,
0x3430306378302034ull,0x3178302038313830ull,0x2033303062393030ull,0x3230303030307830ull,
0x783009090a203038ull,0x3432613035303063ull,0x3136303062783020ull,0x3062783020383232ull,
0x3020646635313138ull,0x6337303134303678ull,0x31783009090a2038ull,0x2033303064393030ull,
0x3130303030307830ull,0x3030317830203030ull,0x7830203130363030ull,0x3038376333303630ull,
0x3035783009090a20ull,0x3020333030303030ull,0x3837303030303078ull,0x3430306378302030ull,
0x6278302063306130ull,0x2030313630333030ull,0x333032783009090aull,0x7830206430303834ull,
0x6666666666666630ull,0x3136343062783020ull,0x3062783020343132ull,0x0a20303134303430ull,
0x6337303378300909ull,0x3678302064663730ull,0x2038633763303063ull,0x3230353030627830ull,
0x3030637830203431ull,0x090a203831383034ull,0x3661303031783009ull,0x3030783020333030ull,
0x3020303832303030ull,0x3261303530306378ull,0x3630306278302034ull,0x09090a2038323231ull,
0x3531313830627830ull,0x3430367830206466ull,0x7830203863373031ull,0x3330303861303031ull,
0x3030303030783020ull,0x3009090a20303031ull,0x3036303030303178ull,0x3330343078302031ull,
0x3578302030383763ull,0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,
0x6330613034303063ull,0x3033303062783020ull,0x3032783020303136ull,0x3020643030383333ull,
0x6666666666663078ull,0x62783009090a2066ull,0x2034313231363430ull,0x3430343030627830ull,
0x3730337830203031ull,0x7830206466373063ull,0x3863376330306336ull,0x3062783009090a20ull,
0x3020343132303530ull,0x3138303430306378ull,0x6230303178302038ull,0x3078302033303031ull,
0x2030383230303030ull,0x303063783009090aull,0x7830203432613035ull,0x3832323136303062ull,
0x3131383062783020ull,0x3036783020646635ull,0x0a20386337303134ull,0x6230303178300909ull,
0x3078302033303033ull,0x2030303130303030ull,0x3630303030317830ull,0x3036307830203130ull,
0x090a203038376333ull,0x3030303035783009ull,0x3030783020333030ull,0x3020303837303030ull,
0x3061303430306378ull,0x3330306278302063ull,0x09090a2030313630ull,0x3038323330327830ull,
0x6666307830206430ull,0x7830206666666666ull,0x3431323136343062ull,0x3034303062783020ull,
0x3009090a20303134ull,0x6637306337303378ull,0x3030633678302064ull,0x6278302038633763ull,
0x2034313230353030ull,0x3830343030637830ull,0x783009090a203831ull,0x3330306362303031ull,
0x3030303030783020ull,0x3063783020303832ull,0x3020343261303530ull,0x3232313630306278ull,
0x62783009090a2038ull,0x2064663531313830ull,0x3730313430367830ull,0x3030317830203863ull,
0x7830203330306562ull,0x3030313030303030ull,0x3031783009090a20ull,0x3020313036303030ull,
0x3837633330343078ull,0x3030303578302030ull,0x3078302033303030ull,0x2030383730303030ull,
0x303063783009090aull,0x7830206330613034ull,0x3031363033303062ull,0x3831333032783020ull,
0x6630783020643030ull,0x0a20666666666666ull,0x3634306278300909ull,0x6278302034313231ull,
0x2030313430343030ull,0x3730633730337830ull,0x3063367830206466ull,0x090a203863376330ull,
0x3035303062783009ull,0x3063783020343132ull,0x3020383138303430ull,0x3030376330303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x6130353030637830ull,0x3030627830203432ull,
0x7830203832323136ull,0x6466353131383062ull,0x3031343036783020ull,0x3009090a20386337ull,
0x3030396330303178ull,0x3030303078302033ull,0x3178302030303130ull,0x2031303630303030ull,
0x3763333036307830ull,0x783009090a203038ull,0x3330303030303035ull,0x3030303030783020ull,
0x3063783020303837ull,0x3020633061303430ull,0x3136303330306278ull,0x32783009090a2030ull,
0x2064303038303330ull,0x6666666666307830ull,0x3430627830206666ull,0x7830203431323136ull,
0x3031343034303062ull,0x3033783009090a20ull,0x3020646637306337ull,0x6337633030633678ull,
0x3530306278302038ull,0x6378302034313230ull,0x2038313830343030ull,0x303031783009090aull,
0x7830203330303264ull,0x3038323030303030ull,0x3035303063783020ull,0x3062783020343261ull,
0x0a20383232313630ull,0x3138306278300909ull,0x3678302064663531ull,0x2038633730313430ull,
0x3034643030317830ull,0x3030307830203330ull,0x090a203030313030ull,0x3030303031783009ull,
0x3430783020313036ull,0x3020303837633330ull,0x3030303030303578ull,0x3030303078302033ull,
0x09090a2030383730ull,0x6130343030637830ull,0x3030627830206330ull,0x7830203031363033ull,
0x6430303866323032ull,0x6666666630783020ull,0x3009090a20666666ull,0x3132313634306278ull,
0x3430306278302034ull,0x3378302030313430ull,0x2064663730633730ull,0x3763303063367830ull,
0x783009090a203863ull,0x3431323035303062ull,0x3034303063783020ull,0x3031783020383138ull,
0x3020333030646430ull,0x3832303030303078ull,0x63783009090a2030ull,0x2034326130353030ull,
0x3231363030627830ull,0x3830627830203832ull,0x7830206466353131ull,0x3863373031343036ull,
0x3031783009090a20ull,0x3020333030666430ull,0x3031303030303078ull,0x3030303178302030ull,
0x3078302031303630ull,0x2030383763333036ull,0x303035783009090aull,0x7830203330303030ull,
0x3038373030303030ull,0x3034303063783020ull,0x3062783020633061ull,0x0a20303136303330ull,
0x6532303278300909ull,0x3078302064303038ull,0x2066666666666666ull,0x3231363430627830ull,
0x3030627830203431ull,0x090a203031343034ull,0x3063373033783009ull,0x6336783020646637ull,
0x3020386337633030ull,0x3132303530306278ull,0x3430306378302034ull,0x09090a2038313830ull,
0x3038653030317830ull,0x3030307830203330ull,0x7830203038323030ull,0x3432613035303063ull,
0x3136303062783020ull,0x3009090a20383232ull,0x6635313138306278ull,0x3134303678302064ull,
0x3178302038633730ull,0x2033303061653030ull,0x3130303030307830ull,0x783009090a203030ull,
0x3130363030303031ull,0x6333303430783020ull,0x3035783020303837ull,0x3020333030303030ull,
0x3837303030303078ull,0x63783009090a2030ull,0x2064306130343030ull,0x3730303030307830ull,
0x3230327830203038ull,0x7830203130303864ull,0x6666666666666630ull,0x3062783009090a20ull,
0x3020643036303030ull,0x3837633030303078ull,0x6337303378302030ull,0x3678302035313030ull,
0x2030643763303063ull,0x343062783009090aull,0x7830203031323136ull,0x6330343033303062ull,
0x3030303061783020ull,0x6330783020646662ull,0x0a20386337343130ull,0x3430306278300909ull,
0x6378302030313230ull,0x2034313630333030ull,0x3035663030317830ull,0x3030307830203330ull,
0x090a203038323130ull,0x3034303063783009ull,0x3062783020383138ull,0x3020343263303530ull,
0x6633313138306278ull,0x3134303678302064ull,0x09090a2038643730ull,0x3036663030317830ull,
0x3030307830203330ull,0x7830203030313130ull,0x3330303030303035ull,0x3030303030783020ull,
0x3009090a20303837ull,0x3038303330306378ull,0x3534306278302063ull,0x6278302030316330ull,
0x2063303630333030ull,0x3230343030627830ull,0x783009090a203831ull,0x3431343033303062ull,
0x3036303063783020ull,0x3063783020383263ull,0x3020353261303530ull,0x3837303030303078ull,
0x31783009090a2030ull,0x2033303066313030ull,0x3730303030307830ull,0x3730337830203038ull,
0x7830203530303063ull,0x3038373031306336ull,0x3032783009090a20ull,0x3020313030643034ull,
0x3837303032343078ull,0x3130306478302030ull,0x3078302031303030ull,0x2030383730303034ull,
0x373033783009090aull,0x7830206466313063ull,0x3863373830306336ull,0x3531313061783020ull,
0x3030783020333030ull,0x0a20303030303030ull,0x3131303178300909ull,0x3078302033303032ull,
0x2030383230303030ull,0x3037303030647830ull,0x3030327830203530ull,0x090a203038373030ull,
0x6530303032783009ull,0x3430783020313030ull,0x3020303837303032ull,0x3030303030346178ull,
0x3032303078302039ull,0x09090a2030383738ull,0x3230303034617830ull,0x3230307830203931ull,
0x7830203038373830ull,0x6431343030303461ull,0x3830323030783020ull,0x3009090a20303837ull,
0x3032303230303478ull,0x3630303478302038ull,0x3478302030313230ull,0x2035313230373030ull,
0x3730303030307830ull,0x783009090a203038ull,0x3930343030313033ull,0x3030313463783020ull,
0x3033783020303837ull,0x3020313138303031ull,0x3837303031346378ull,0x33783009090a2030ull,
0x2035316130303130ull,0x3730303134637830ull,0x3030367830203038ull,0x7830203530303032ull,
0x3038373830303030ull,0x3036783009090a20ull,0x3020393030303630ull,0x3837303130303078ull,
0x3730303678302030ull,0x3078302031303030ull,0x2030383734313030ull,0x303061783009090aull,
0x7830206430323030ull,0x3038376330303430ull,0x3030303061783020ull,0x3430783020353134ull,
0x0a20303837633030ull,0x3030306178300909ull,0x3078302031313030ull,0x2030383763303034ull,
0x3035313130317830ull,0x3030307830203330ull,0x090a203038373030ull,0x6630303031783009ull,
0x3630783020313138ull,0x3020303837633330ull,0x3138663030303178ull,0x3330343078302035ull,
0x09090a2030383763ull,0x3866303030317830ull,0x3036307830206430ull,0x7830203038376333ull,
0x3130633030303031ull,0x6330303434783020ull,0x3009090a20323837ull,0x3030306630303478ull,
0x3030303078302035ull,0x3678302030383730ull,0x2035303230653030ull,0x3734303030307830ull,
0x783009090a203038ull,0x3530323030313033ull,0x3030313463783020ull,0x3036783020303837ull,
0x3020313030306530ull,0x3837343030303078ull,0x32783009090a2030ull,0x2031303030303030ull,
0x3730323034307830ull,0x3030337830203038ull,0x7830203130303032ull,0x3038373030313463ull,
0x3033783009090a20ull,0x3020646666646337ull,0x6337343132633678ull,0x3030303278302038ull,
0x3078302064313863ull,0x2030383730303234ull,0x313031783009090aull,0x7830203330303832ull,
0x3038323030303030ull,0x3030303031783020ull,0x3030783020353030ull,0x0a20333030303030ull,
0x3030303178300909ull,0x3178302063303031ull,0x2030303431323030ull,0x6330303030317830ull,
0x3030307830203930ull,0x090a203038376333ull,0x3032383064783009ull,0x3430783020393030ull,
0x3020303837303034ull,0x3032303238306478ull,0x3034343078302031ull,0x09090a2030383730ull,
0x3430383030337830ull,0x3134637830203530ull,0x7830203038373030ull,0x3130303031303064ull,
0x3430303430783020ull,0x3009090a20303837ull,0x3065306530306478ull,0x3063306178302031ull,
0x3378302030383730ull,0x2033303030303030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3931653065303064ull,0x3030633038783020ull,0x3031783020303837ull,0x3020353065313030ull,
0x3837633030343478ull,0x61783009090a2030ull,0x2039343831303030ull,0x3738303030307830ull,
0x3031327830203038ull,0x7830203930656631ull,0x3330303030303030ull,0x3033783009090a20ull,
0x3020313063303830ull,0x3837303031346578ull,0x3231303478302030ull,0x3078302039323630ull,
0x2030383730303030ull,0x313033783009090aull,0x7830203132343066ull,0x3038373030316365ull,
0x3030303061783020ull,0x3030783020313030ull,0x0a20303837383030ull,0x3031303378300909ull,
0x6378302039323431ull,0x2030383730303134ull,0x3031333830647830ull,0x3434307830203132ull,
0x090a203038373030ull,0x3030303034783009ull,0x3030783020643236ull,0x3020303837303030ull,
0x3234303231303678ull,0x3230303078302035ull,0x09090a2030383738ull,0x3031303030327830ull,
0x3034307830203132ull,0x7830203038373830ull,0x3932363130313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3232313030303278ull,0x3030343078302035ull,0x3378302030383763ull,
0x2031323031313030ull,0x3730303163657830ull,0x783009090a203038ull,0x3932343030303036ull,
0x3832303030783020ull,0x3031783020303837ull,0x3020633034383230ull,0x3030393930303278ull,
0x32783009090a2030ull,0x2039333431303030ull,0x3734313034307830ull,0x3130327830203038ull,
0x7830203330306534ull,0x3038373030303030ull,0x3031783009090a20ull,0x3020343130383030ull,
0x3034383230303178ull,0x3030303278302063ull,0x3078302031303031ull,0x2030383738333034ull,
0x303061783009090aull,0x7830203932613030ull,0x3038376330303030ull,0x6534313032783020ull,
0x3030783020333030ull,0x0a20303837303030ull,0x3030306178300909ull,0x3078302039316131ull,
0x2030383738303030ull,0x3630363030347830ull,0x3030307830203931ull,0x090a203038373030ull,
0x3030313033783009ull,0x3463783020393163ull,0x3020303837303031ull,0x3034303630303678ull,
0x3130303078302035ull,0x09090a2030383738ull,0x3238343030327830ull,0x3030317830206330ull,
0x7830203430303830ull,0x3130303130303032ull,0x6330303430783020ull,0x3009090a20303837ull,
0x3034303830303378ull,0x3031306378302039ull,0x3178302030383730ull,0x2064303430303030ull,
0x3763333034307830ull,0x783009090a203038ull,0x3330306534313032ull,0x3030303030783020ull,
0x3064783020303837ull,0x3020393034313230ull,0x3837343030303078ull,0x64783009090a2030ull,
0x2035306530653030ull,0x3730303430617830ull,0x3030327830203038ull,0x7830203530653832ull,
0x3330303030303030ull,0x3064783009090a20ull,0x3020313032306530ull,0x3837303030306178ull,
0x3030303378302030ull,0x3078302033303030ull,0x2030383730303030ull,0x303061783009090aull,
0x7830203532363030ull,0x3038373431313430ull,0x3130303061783020ull,0x3434783020393232ull,
0x0a20303837343030ull,0x3030306178300909ull,0x3078302064323030ull,0x2030383734313134ull,
0x3431303030397830ull,0x3030307830203133ull,0x090a203038373030ull,0x3130303061783009ull,
0x3434783020393236ull,0x3020303837343630ull,0x3338396533303278ull,0x6666663078302031ull,
0x09090a2066666666ull,0x3431633030637830ull,0x3030307830203932ull,0x7830203063376330ull,
0x3932343130303061ull,0x3436303438783020ull,0x3009090a20303837ull,0x3334323531303478ull,
0x3030303078302035ull,0x3678302030383730ull,0x2035333632343130ull,0x3734333030307830ull,
0x783009090a203038ull,0x3533613130313033ull,0x3030313463783020ull,0x3036783020303837ull,
0x3020353334323431ull,0x3837343330303078ull,0x32783009090a2030ull,0x2035333631303430ull,
0x3734333034307830ull,0x3030617830203038ull,0x7830203533613130ull,0x3038373436303434ull,
0x3063783009090a20ull,0x3020313361316330ull,0x6337633030303078ull,0x3030306178302030ull,
0x3878302031333831ull,0x2030383734363034ull,0x303032783009090aull,0x7830203932343130ull,
0x3038373033303430ull,0x3232313034783020ull,0x3030783020313361ull,0x0a20303837303030ull,
0x3331303678300909ull,0x3078302031333832ull,0x2030383730333030ull,0x3831303130337830ull,
0x3134637830203133ull,0x090a203038373030ull,0x3232313036783009ull,0x3030783020313338ull,
0x3020303837303330ull,0x3238313030303378ull,0x3230343078302064ull,0x09090a2030383763ull,
0x3231623030337830ull,0x3034367830203532ull,0x7830203038376330ull,0x3130363030303064ull,
0x3830303430783020ull,0x3009090a20303837ull,0x3030306631303378ull,0x3031346578302031ull,
0x3378302030383730ull,0x2039323231303030ull,0x3738323034307830ull,0x783009090a203038ull,
0x3532303030303061ull,0x3431306332783020ull,0x3064783020303837ull,0x3020353232316130ull,
0x3837383030343078ull,0x33783009090a2030ull,0x2064663730633730ull,0x3734313063367830ull,
0x3030327830203863ull,0x7830203130303030ull,0x3038373432303430ull,0x3064783009090a20ull,
0x3020313030303330ull,0x3035633230343078ull,0x3030303378302030ull,0x3078302033303030ull,
0x2030383730303030ull,0x303066783009090aull,0x7830203130303030ull,0x3130303030303065ull,
0x000a7d0a7d090a20ull
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
0x6d742f706d742f20ull,0x3030305f74667870ull,0x30305f3265383630ull,0x312d303030303030ull,
0x6c65646e614d5f39ull,0x316d735f746f7262ull,0x692e337070632e30ull,0x632f706d742f2820ull,
0x31337a2e23494263ull,0x2f2f090a2947327aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2f2f090a0a2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x202f2f090a2d2d2dull,0x3a736e6f6974704full,0x2d2d2d2d2f2f090aull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x72615420202f2f09ull,
0x2c7874703a746567ull,0x5f6d733a41534920ull,0x69646e45202c3331ull,0x6c7474696c3a6e61ull,
0x746e696f50202c65ull,0x3a657a6953207265ull,0x20202f2f090a3436ull,0x74704f2809334f2dull,
0x6f6974617a696d69ull,0x296c6576656c206eull,0x672d20202f2f090aull,0x6775626544280930ull,
0x0a296c6576656c20ull,0x326d2d20202f2f09ull,0x74726f7065522809ull,0x726f736976646120ull,
0x2f2f090a29736569ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x662e090a0a2d2d2dull,0x3c22093109656c69ull,0x2d646e616d6d6f63ull,0x090a223e656e696cull,
0x093209656c69662eull,0x6d742f706d742f22ull,0x3030305f74667870ull,0x30305f3265383630ull,
0x312d303030303030ull,0x6c65646e614d5f38ull,0x316d735f746f7262ull,0x6566616475632e30ull,
0x090a227570672e32ull,0x093309656c69662eull,0x696c2f7273752f22ull,0x38782f6363672f62ull,
0x6e696c2d34365f36ull,0x342f756e672d7875ull,0x636e692f312e342eull,0x6474732f6564756cull,
0x090a22682e666564ull,0x093409656c69662eull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x697665642f747263ull,0x69746e75725f6563ull,
0x2e090a22682e656dull,0x22093509656c6966ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x682f6564756c636eull,0x696665645f74736full,0x090a22682e73656eull,
0x093609656c69662eull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x5f6e69746c697562ull,0x22682e7365707974ull,0x09656c69662e090aull,
0x2f7273752f220937ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,
0x6563697665642f65ull,0x682e73657079745full,0x656c69662e090a22ull,0x7273752f22093809ull,
0x632f6c61636f6c2full,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x65766972642f6564ull,
0x2e73657079745f72ull,0x6c69662e090a2268ull,0x73752f2209390965ull,0x2f6c61636f6c2f72ull,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x747865742f656475ull,0x657079745f657275ull,
0x662e090a22682e73ull,0x2209303109656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x762f6564756c636eull,0x79745f726f746365ull,0x090a22682e736570ull,
0x313109656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x5f6563697665642full,0x705f68636e75616cull,0x726574656d617261ull,
0x662e090a22682e73ull,0x2209323109656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x632f6564756c636eull,0x61726f74732f7472ull,0x7373616c635f6567ull,
0x69662e090a22682eull,0x2f2209333109656cull,0x6c636e692f727375ull,0x737469622f656475ull,
0x682e73657079742full,0x656c69662e090a22ull,0x73752f2209343109ull,0x64756c636e692f72ull,
0x682e656d69742f65ull,0x656c69662e090a22ull,0x6e614d2209353109ull,0x5f746f72626c6564ull,
0x632e6c656e72656bull,0x6c69662e090a2275ull,0x614d220936310965ull,0x746f72626c65646eull,
0x75632e30316d735full,0x656c69662e090a22ull,0x73752f2209373109ull,0x2f6c61636f6c2f72ull,
0x6e69622f61647563ull,0x6c636e692f2e2e2full,0x6d6d6f632f656475ull,0x74636e75665f6e6full,
0x0a22682e736e6f69ull,0x3109656c69662e09ull,0x2f7273752f220938ull,0x75632f6c61636f6cull,
0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x75662f7472632f65ull,0x6f7263616d5f636eull,
0x69662e090a22682eull,0x2f2209393109656cull,0x61636f6c2f727375ull,0x622f616475632f6cull,
0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,0x74636e75665f6874ull,0x0a22682e736e6f69ull,
0x3209656c69662e09ull,0x2f7273752f220930ull,0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,
0x64756c636e692f2eull,0x6563697665642f65ull,0x6f6974636e75665full,0x2e090a22682e736eull,
0x09313209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x6e6f635f6874616dull,0x682e73746e617473ull,0x656c69662e090a22ull,
0x73752f2209323209ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x315f6d732f656475ull,0x63696d6f74615f31ull,0x6f6974636e75665full,0x2e090a22682e736eull,
0x09333209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,0x2f2e2e2f6e69622full,
0x2f6564756c636e69ull,0x74615f32315f6d73ull,0x6e75665f63696d6full,0x682e736e6f697463ull,
0x656c69662e090a22ull,0x73752f2209343209ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x315f6d732f656475ull,0x656c62756f645f33ull,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09353209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x5f65727574786574ull,0x75665f6863746566ull,
0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x752f220936320965ull,0x6c61636f6c2f7273ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x74616d2f6564756cull,0x6974636e75665f68ull,
0x5f6c62645f736e6full,0x0a22682e33787470ull,0x72746e652e090a0aull,0x614d38315a5f2079ull,
0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,0x6666666666696969ull,
0x206269695f536666ull,0x7261702e09090a28ull,0x203436752e206d61ull,0x6170616475635f5full,
0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x6269695f53666666ull,0x09090a2c7473645full,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,0x305344746f72626cull,
0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,0x616d695f6269695full,
0x2e09090a2c576567ull,0x732e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,
0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x5f53666666666666ull,0x67616d695f626969ull,0x702e09090a2c4865ull,0x33732e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f305344746f72ull,
0x686375365030316dull,0x6666696969347261ull,0x695f536666666666ull,0x636e7572635f6269ull,
0x61702e09090a2c68ull,0x3233662e206d6172ull,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,
0x69695f5366666666ull,0x2c3066664f785f62ull,0x617261702e09090aull,0x5f203233662e206dull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,
0x3472616863753650ull,0x6666666666696969ull,0x5f6269695f536666ull,0x090a2c3166664f78ull,
0x206d617261702e09ull,0x635f5f203233662eull,0x5f6d726170616475ull,0x646e614d38315a5full,
0x5344746f72626c65ull,0x365030316d735f30ull,0x6969347261686375ull,0x6666666666666669ull,
0x4f795f6269695f53ull,0x2e09090a2c306666ull,0x662e206d61726170ull,0x6475635f5f203233ull,
0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,
0x6669696934726168ull,0x5f53666666666666ull,0x66664f795f626969ull,0x61702e09090a2c31ull,
0x3233662e206d6172ull,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,
0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,
0x090a2c504a785f62ull,0x206d617261702e09ull,0x635f5f203233662eull,0x5f6d726170616475ull,
0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f30ull,0x6969347261686375ull,
0x6666666666666669ull,0x4a795f6269695f53ull,0x61702e09090a2c50ull,0x3233662e206d6172ull,
0x70616475635f5f20ull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f305344746full,
0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,0x2c656c6163735f62ull,
0x617261702e09090aull,0x6e67696c612e206dull,0x5f2038622e203420ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x345b73726f6c6f63ull,0x61702e09090a2c5dull,
0x3233732e206d6172ull,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,
0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,
0x2c656d6172665f62ull,0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x6f6974616d696e61ull,0x0a2c656d6172466eull,
0x6d617261702e0909ull,0x635f5f2038732e20ull,0x5f6d726170616475ull,0x646e614d38315a5full,
0x5344746f72626c65ull,0x365030316d735f30ull,0x6969347261686375ull,0x6666666666666669ull,
0x73695f6269695f53ull,0x2e090a7b090a294aull,0x3631752e20676572ull,0x3b3e363c68722520ull,
0x2e206765722e090aull,0x363c722520323375ull,0x65722e090a3b3e34ull,0x25203436752e2067ull,
0x090a3b3e363c6472ull,0x33662e206765722eull,0x3532323c66252032ull,0x6765722e090a3b3eull,
0x2520646572702e20ull,0x090a3b3e31313c70ull,0x09363109636f6c2eull,0x424c240a30093535ull,
0x4d38315a5f5f3142ull,0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x6269695f53666666ull,0x752e766f6d090a3aull,0x3168722509203631ull,
0x646961746325202cull,0x766f6d090a3b782eull,0x722509203631752eull,0x69746e25202c3268ull,
0x756d090a3b782e64ull,0x752e656469772e6cull,0x2c31722509203631ull,0x25202c3168722520ull,
0x6f6d090a3b326872ull,0x2509203631752e76ull,0x746325202c336872ull,0x090a3b792e646961ull,
0x203631752e766f6dull,0x25202c3468722509ull,0x0a3b792e6469746eull,0x6469772e6c756d09ull,
0x2509203631752e65ull,0x33687225202c3272ull,0x0a3b34687225202cull,0x3233752e74766309ull,
0x722509203631752eull,0x2e64697425202c33ull,0x2e646461090a3b78ull,0x3472250920323375ull,
0x25202c337225202cull,0x747663090a3b3172ull,0x3631752e3233752eull,0x25202c3572250920ull,
0x090a3b792e646974ull,0x203233752e646461ull,0x7225202c36722509ull,0x0a3b327225202c35ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x635f5f5b202c3772ull,0x5f6d726170616475ull,
0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f30ull,0x6969347261686375ull,
0x6666666666666669ull,0x6d695f6269695f53ull,0x090a3b5d57656761ull,0x6d617261702e646cull,
0x722509203233732eull,0x75635f5f5b202c38ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x305344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,
0x616d695f6269695full,0x73090a3b5d486567ull,0x33752e74672e7465ull,0x2509203233732e32ull,
0x2c387225202c3972ull,0x6e090a3b36722520ull,0x09203233732e6765ull,0x7225202c30317225ull,
0x2e746573090a3b39ull,0x732e3233752e7467ull,0x3131722509203233ull,0x25202c377225202cull,
0x67656e090a3b3472ull,0x722509203233732eull,0x31317225202c3231ull,0x622e646e61090a3bull,
0x3331722509203233ull,0x202c30317225202cull,0x6d090a3b32317225ull,0x09203233752e766full,
0x3b30202c34317225ull,0x652e70746573090aull,0x2509203233732e71ull,0x33317225202c3170ull,
0x0a3b34317225202cull,0x7262203170254009ull,0x305f744c24092061ull,0x090a3b303534385full,
0x09363109636f6c2eull,0x7663090a30093636ull,0x3233662e6e722e74ull,0x662509203233732eull,
0x0a3b347225202c31ull,0x617261702e646c09ull,0x2509203233662e6dull,0x635f5f5b202c3266ull,
0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f30ull,
0x6969347261686375ull,0x6666666666666669ull,0x63735f6269695f53ull,0x6d090a3b5d656c61ull,
0x09203233662e6c75ull,0x316625202c336625ull,0x090a3b326625202cull,0x6d617261702e646cull,
0x662509203233662eull,0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x305344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,
0x664f785f6269695full,0x6461090a3b5d3066ull,0x2509203233662e64ull,0x2c336625202c3566ull,
0x73090a3b34662520ull,0x09203233662e6275ull,0x356625202c366625ull,0x090a3b336625202cull,
0x203233662e627573ull,0x6625202c37662509ull,0x0a3b366625202c34ull,0x3233662e62757309ull,
0x25202c3866250920ull,0x3b366625202c3566ull,0x33662e627573090aull,0x202c396625092032ull,
0x386625202c336625ull,0x662e646461090a3bull,0x3031662509203233ull,0x25202c376625202cull,
0x2e646c090a3b3966ull,0x33662e6d61726170ull,0x2c31316625092032ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,
0x6666696969347261ull,0x695f536666666666ull,0x3166664f785f6269ull,0x2e646461090a3b5dull,
0x3166250920323366ull,0x2c31316625202c32ull,0x090a3b3031662520ull,0x203233662e646461ull,
0x25202c3331662509ull,0x32316625202c3566ull,0x662e627573090a3bull,0x3431662509203233ull,
0x202c33316625202cull,0x7573090a3b356625ull,0x2509203233662e62ull,0x316625202c353166ull,
0x3b34316625202c32ull,0x3109636f6c2e090aull,0x090a300937360936ull,0x662e6e722e747663ull,
0x09203233732e3233ull,0x7225202c36316625ull,0x2e6c756d090a3b36ull,0x3166250920323366ull,
0x2c36316625202c37ull,0x6c090a3b32662520ull,0x2e6d617261702e64ull,0x3166250920323366ull,
0x75635f5f5b202c38ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,0x305344746f72626cull,
0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,0x664f795f6269695full,
0x6461090a3b5d3066ull,0x2509203233662e64ull,0x316625202c393166ull,0x3b38316625202c37ull,
0x33662e627573090aull,0x2c30326625092032ull,0x25202c3931662520ull,0x7573090a3b373166ull,
0x2509203233662e62ull,0x316625202c313266ull,0x3b30326625202c38ull,0x33662e627573090aull,
0x2c32326625092032ull,0x25202c3931662520ull,0x7573090a3b303266ull,0x2509203233662e62ull,
0x316625202c333266ull,0x3b32326625202c37ull,0x33662e646461090aull,0x2c34326625092032ull,
0x25202c3132662520ull,0x646c090a3b333266ull,0x662e6d617261702eull,0x3532662509203233ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,0x5f305344746f7262ull,
0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,0x66664f795f626969ull,
0x646461090a3b5d31ull,0x662509203233662eull,0x35326625202c3632ull,0x0a3b34326625202cull,
0x3233662e64646109ull,0x202c373266250920ull,0x6625202c39316625ull,0x627573090a3b3632ull,
0x662509203233662eull,0x37326625202c3832ull,0x0a3b39316625202cull,0x3233662e62757309ull,
0x202c393266250920ull,0x6625202c36326625ull,0x6f6c2e090a3b3832ull,0x0930370936310963ull,
0x61702e646c090a30ull,0x092038732e6d6172ull,0x5f5b202c35317225ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x6d090a3b5d4a7369ull,0x09203233752e766full,
0x3b30202c36317225ull,0x652e70746573090aull,0x2509203233732e71ull,0x35317225202c3270ull,
0x0a3b36317225202cull,0x7262203270254009ull,0x305f744c24092061ull,0x090a3b323836375full,
0x09353109636f6c2eull,0x6c090a3009353833ull,0x2e6d617261702e64ull,0x3366250920323366ull,
0x75635f5f5b202c30ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,0x305344746f72626cull,
0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,0x504a785f6269695full,
0x636f6c2e090a3b5dull,0x0937383309353109ull,0x61702e646c090a30ull,0x203233662e6d6172ull,
0x5b202c3133662509ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,
0x316d735f30534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6269695f53666666ull,
0x090a3b5d504a795full,0x09353109636f6c2eull,0x6d090a3009393833ull,0x09203233662e766full,
0x6625202c32336625ull,0x6f6c2e090a3b3732ull,0x3039330935310963ull,0x2e766f6d090a3009ull,
0x3366250920323366ull,0x3b39326625202c33ull,0x3109636f6c2e090aull,0x0a30093139330935ull,
0x3233662e766f6d09ull,0x202c343366250920ull,0x2e090a3b33316625ull,0x3309353109636f6cull,
0x6f6d090a30093239ull,0x2509203233662e76ull,0x316625202c353366ull,0x636f6c2e090a3b35ull,
0x0933393309353109ull,0x662e766f6d090a30ull,0x3633662509203233ull,0x303036346630202cull,
0x2020203b30303430ull,0x393138202f2f0920ull,0x662e6c756d090a33ull,0x3733662509203233ull,
0x202c37326625202cull,0x73090a3b36336625ull,0x09203233662e6275ull,0x6625202c38336625ull,
0x37326625202c3733ull,0x662e627573090a3bull,0x3933662509203233ull,0x202c37336625202cull,
0x73090a3b38336625ull,0x09203233662e6275ull,0x6625202c30346625ull,0x39336625202c3732ull,
0x662e6c756d090a3bull,0x3134662509203233ull,0x202c37326625202cull,0x6d090a3b37326625ull,
0x09203233662e6c75ull,0x6625202c32346625ull,0x39326625202c3732ull,0x662e64616d090a3bull,
0x3334662509203233ull,0x202c37326625202cull,0x6625202c39326625ull,0x646461090a3b3234ull,
0x662509203233662eull,0x31346625202c3434ull,0x0a3b33346625202cull,0x3233662e6c756d09ull,
0x202c353466250920ull,0x6625202c39336625ull,0x627573090a3b3933ull,0x662509203233662eull,
0x35346625202c3634ull,0x0a3b31346625202cull,0x3233662e62757309ull,0x202c373466250920ull,
0x6625202c34346625ull,0x64616d090a3b3134ull,0x662509203233662eull,0x39336625202c3834ull,
0x202c30346625202cull,0x73090a3b36346625ull,0x09203233662e6275ull,0x6625202c39346625ull,
0x37346625202c3434ull,0x662e627573090a3bull,0x3035662509203233ull,0x202c33346625202cull,
0x6d090a3b37346625ull,0x09203233662e6461ull,0x6625202c31356625ull,0x30346625202c3933ull,
0x0a3b38346625202cull,0x3233662e62757309ull,0x202c323566250920ull,0x6625202c31346625ull,
0x64616d090a3b3934ull,0x662509203233662eull,0x30346625202c3335ull,0x202c30346625202cull,
0x61090a3b31356625ull,0x09203233662e6464ull,0x6625202c34356625ull,0x32356625202c3035ull,
0x662e646461090a3bull,0x3535662509203233ull,0x202c33356625202cull,0x6d090a3b34356625ull,
0x09203233662e6461ull,0x6625202c36356625ull,0x39326625202c3932ull,0x0a3b35356625202cull,
0x3233662e64646109ull,0x202c373566250920ull,0x6625202c34346625ull,0x766f6d090a3b3635ull,
0x662509203233662eull,0x37356625202c3835ull,0x662e627573090a3bull,0x3935662509203233ull,
0x202c37356625202cull,0x73090a3b34346625ull,0x09203233662e6275ull,0x6625202c30366625ull,
0x39356625202c3635ull,0x09636f6c2e090a3bull,0x3009343933093531ull,0x33662e766f6d090aull,
0x2c31366625092032ull,0x3030303634663020ull,0x202020203b303034ull,0x33393138202f2f09ull,
0x33662e6c756d090aull,0x2c32366625092032ull,0x25202c3331662520ull,0x7573090a3b313666ull,
0x2509203233662e62ull,0x366625202c333666ull,0x3b33316625202c32ull,0x33662e627573090aull,
0x2c34366625092032ull,0x25202c3236662520ull,0x7573090a3b333666ull,0x2509203233662e62ull,
0x316625202c353666ull,0x3b34366625202c33ull,0x33662e6c756d090aull,0x2c36366625092032ull,
0x25202c3331662520ull,0x756d090a3b333166ull,0x2509203233662e6cull,0x316625202c373666ull,
0x3b35316625202c33ull,0x33662e64616d090aull,0x2c38366625092032ull,0x25202c3331662520ull,
0x366625202c353166ull,0x2e646461090a3b37ull,0x3666250920323366ull,0x2c36366625202c39ull,
0x090a3b3836662520ull,0x203233662e6c756dull,0x25202c3037662509ull,0x366625202c343666ull,
0x2e627573090a3b34ull,0x3766250920323366ull,0x2c30376625202c31ull,0x090a3b3636662520ull,
0x203233662e627573ull,0x25202c3237662509ull,0x366625202c393666ull,0x2e64616d090a3b36ull,
0x3766250920323366ull,0x2c34366625202c33ull,0x25202c3536662520ull,0x7573090a3b313766ull,
0x2509203233662e62ull,0x366625202c343766ull,0x3b32376625202c39ull,0x33662e627573090aull,
0x2c35376625092032ull,0x25202c3836662520ull,0x616d090a3b323766ull,0x2509203233662e64ull,
0x366625202c363766ull,0x2c35366625202c34ull,0x090a3b3337662520ull,0x203233662e627573ull,
0x25202c3737662509ull,0x376625202c363666ull,0x2e64616d090a3b34ull,0x3766250920323366ull,
0x2c35366625202c38ull,0x25202c3536662520ull,0x6461090a3b363766ull,0x2509203233662e64ull,
0x376625202c393766ull,0x3b37376625202c35ull,0x33662e646461090aull,0x2c30386625092032ull,
0x25202c3837662520ull,0x616d090a3b393766ull,0x2509203233662e64ull,0x316625202c313866ull,
0x2c35316625202c35ull,0x090a3b3038662520ull,0x203233662e646461ull,0x25202c3238662509ull,
0x386625202c393666ull,0x2e766f6d090a3b31ull,0x3866250920323366ull,0x3b32386625202c33ull,
0x33662e627573090aull,0x2c34386625092032ull,0x25202c3238662520ull,0x7573090a3b393666ull,
0x2509203233662e62ull,0x386625202c353866ull,0x3b34386625202c31ull,0x33662e766f6d090aull,
0x2c36386625092032ull,0x3030303030663020ull,0x202020203b303030ull,0x6d090a30202f2f09ull,
0x09203233662e766full,0x6630202c37386625ull,0x3030303030303030ull,0x2f2f09202020203bull,
0x2e617262090a3020ull,0x744c240920696e75ull,0x3b363234375f305full,0x375f305f744c240aull,
0x6c2e090a3a323836ull,0x393309353109636full,0x766f6d090a300937ull,0x662509203233662eull,
0x33316625202c3033ull,0x09636f6c2e090a3bull,0x3009383933093531ull,0x33662e766f6d090aull,
0x2c37386625092032ull,0x090a3b3531662520ull,0x09353109636f6c2eull,0x6d090a3009393933ull,
0x09203233662e766full,0x6625202c31336625ull,0x6f6c2e090a3b3732ull,0x3030340935310963ull,
0x2e766f6d090a3009ull,0x3866250920323366ull,0x3b39326625202c36ull,0x3109636f6c2e090aull,
0x0a30093830340935ull,0x3233662e766f6d09ull,0x202c353866250920ull,0x3030303030306630ull,
0x09202020203b3030ull,0x6f6d090a30202f2full,0x2509203233662e76ull,0x306630202c333866ull,
0x3b30303030303030ull,0x202f2f0920202020ull,0x662e766f6d090a30ull,0x3036662509203233ull,
0x303030306630202cull,0x2020203b30303030ull,0x090a30202f2f0920ull,0x203233662e766f6dull,
0x30202c3835662509ull,0x3030303030303066ull,0x2f09202020203b30ull,0x766f6d090a30202full,
0x662509203233662eull,0x30306630202c3533ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x33662e766f6d090aull,0x2c34336625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c33336625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3366250920323366ull,0x3030306630202c32ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x34375f305f744c24ull,0x6f6c2e090a3a3632ull,
0x3231340935310963ull,0x702e646c090a3009ull,0x3233732e6d617261ull,0x202c373172250920ull,
0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f305344746full,
0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,0x68636e7572635f62ull,
0x2e627573090a3b5dull,0x3172250920323373ull,0x2c37317225202c38ull,0x766f6d090a3b3120ull,
0x722509203233752eull,0x090a3b31202c3931ull,0x2e71652e70746573ull,0x3370250920323373ull,
0x202c37317225202cull,0x40090a3b39317225ull,0x2061726220337025ull,0x385f305f744c2409ull,
0x6461090a3b323639ull,0x2509203233662e64ull,0x386625202c383866ull,0x3b38356625202c33ull,
0x33662e627573090aull,0x2c39386625092032ull,0x25202c3838662520ull,0x7573090a3b333866ull,
0x2509203233662e62ull,0x386625202c303966ull,0x3b39386625202c38ull,0x33662e627573090aull,
0x2c31396625092032ull,0x25202c3835662520ull,0x7573090a3b393866ull,0x2509203233662e62ull,
0x386625202c323966ull,0x3b30396625202c33ull,0x33662e646461090aull,0x2c33396625092032ull,
0x25202c3139662520ull,0x6461090a3b323966ull,0x2509203233662e64ull,0x396625202c343966ull,
0x3b35386625202c33ull,0x33662e646461090aull,0x2c35396625092032ull,0x25202c3439662520ull,
0x6461090a3b303666ull,0x2509203233662e64ull,0x386625202c363966ull,0x3b35396625202c38ull,
0x33662e627573090aull,0x2c37396625092032ull,0x25202c3639662520ull,0x7573090a3b383866ull,
0x2509203233662e62ull,0x396625202c383966ull,0x3b37396625202c35ull,0x33662e646461090aull,
0x2c39396625092032ull,0x25202c3639662520ull,0x6f6d090a3b383966ull,0x2509203233662e76ull,
0x6630202c30303166ull,0x3030303030383034ull,0x202f2f092020203bull,0x2e70746573090a34ull,
0x09203233662e746cull,0x396625202c347025ull,0x3030316625202c39ull,0x3470252140090a3bull,
0x4c24092061726220ull,0x323639385f305f74ull,0x662e766f6d090a3bull,0x3031662509203233ull,
0x3036346630202c31ull,0x20203b3030343030ull,0x393138202f2f0920ull,0x662e6c756d090a33ull,
0x3031662509203233ull,0x2c34336625202c32ull,0x0a3b313031662520ull,0x3233662e766f6d09ull,
0x2c33303166250920ull,0x3030303634663020ull,0x092020203b303034ull,0x0a33393138202f2full,
0x3233662e6c756d09ull,0x2c34303166250920ull,0x25202c3233662520ull,0x73090a3b33303166ull,
0x09203233662e6275ull,0x25202c3530316625ull,0x6625202c32303166ull,0x627573090a3b3433ull,
0x662509203233662eull,0x316625202c363031ull,0x32336625202c3430ull,0x662e627573090a3bull,
0x3031662509203233ull,0x3230316625202c37ull,0x3b3530316625202cull,0x33662e627573090aull,
0x3830316625092032ull,0x2c3430316625202cull,0x0a3b363031662520ull,0x3233662e62757309ull,
0x2c39303166250920ull,0x25202c3433662520ull,0x73090a3b37303166ull,0x09203233662e6275ull,
0x25202c3031316625ull,0x316625202c323366ull,0x305f4c240a3b3830ull,0x200a3a303938355full,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a333134ull,
0x3331340935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,0x35336625202c3131ull,
0x0a3b32336625202cull,0x3233662e6c756d09ull,0x2c32313166250920ull,0x25202c3433662520ull,
0x616d090a3b323366ull,0x2509203233662e64ull,0x6625202c33313166ull,0x33336625202c3433ull,
0x3b3131316625202cull,0x33662e646461090aull,0x3431316625092032ull,0x2c3231316625202cull,
0x0a3b333131662520ull,0x3233662e62757309ull,0x2c35313166250920ull,0x202c343131662520ull,
0x090a3b3231316625ull,0x203233662e6c756dull,0x202c363131662509ull,0x25202c3730316625ull,
0x73090a3b38303166ull,0x09203233662e6275ull,0x25202c3731316625ull,0x6625202c36313166ull,
0x7573090a3b323131ull,0x2509203233662e62ull,0x6625202c38313166ull,0x316625202c333131ull,
0x627573090a3b3531ull,0x662509203233662eull,0x316625202c393131ull,0x31316625202c3431ull,
0x2e64616d090a3b35ull,0x3166250920323366ull,0x30316625202c3032ull,0x3031316625202c37ull,
0x3b3731316625202cull,0x33662e627573090aull,0x3132316625092032ull,0x2c3231316625202cull,
0x0a3b393131662520ull,0x3233662e64616d09ull,0x2c32323166250920ull,0x202c383031662520ull,
0x25202c3930316625ull,0x61090a3b30323166ull,0x09203233662e6464ull,0x25202c3332316625ull,
0x6625202c38313166ull,0x616d090a3b313231ull,0x2509203233662e64ull,0x6625202c34323166ull,
0x316625202c393031ull,0x32316625202c3031ull,0x2e646461090a3b32ull,0x3166250920323366ull,
0x32316625202c3532ull,0x3432316625202c33ull,0x662e64616d090a3bull,0x3231662509203233ull,
0x2c35336625202c36ull,0x25202c3333662520ull,0x61090a3b35323166ull,0x09203233662e6464ull,
0x25202c3732316625ull,0x6625202c34313166ull,0x7573090a3b363231ull,0x2509203233662e62ull,
0x6625202c38323166ull,0x316625202c373231ull,0x627573090a3b3431ull,0x662509203233662eull,
0x32316625202c3333ull,0x3832316625202c36ull,0x09636f6c2e090a3bull,0x3009343134093531ull,
0x33662e646461090aull,0x3932316625092032ull,0x2c3732316625202cull,0x0a3b373231662520ull,
0x3233662e62757309ull,0x2c30333166250920ull,0x202c393231662520ull,0x090a3b3732316625ull,
0x203233662e627573ull,0x202c313331662509ull,0x25202c3732316625ull,0x73090a3b30333166ull,
0x09203233662e6275ull,0x25202c3233316625ull,0x6625202c39323166ull,0x7573090a3b303331ull,
0x2509203233662e62ull,0x6625202c33333166ull,0x316625202c373231ull,0x646461090a3b3233ull,
0x662509203233662eull,0x316625202c343331ull,0x33316625202c3133ull,0x2e646461090a3b33ull,
0x3166250920323366ull,0x33316625202c3533ull,0x3b33336625202c34ull,0x33662e646461090aull,
0x3633316625092032ull,0x2c3533316625202cull,0x090a3b3333662520ull,0x203233662e646461ull,
0x202c373331662509ull,0x25202c3932316625ull,0x73090a3b36333166ull,0x09203233662e6275ull,
0x25202c3833316625ull,0x6625202c37333166ull,0x7573090a3b393231ull,0x2509203233662e62ull,
0x316625202c333366ull,0x33316625202c3633ull,0x636f6c2e090a3b38ull,0x0935313409353109ull,
0x662e646461090a30ull,0x3331662509203233ull,0x3733316625202c39ull,0x0a3b31336625202cull,
0x3233662e62757309ull,0x2c30343166250920ull,0x202c393331662520ull,0x090a3b3733316625ull,
0x203233662e627573ull,0x202c313431662509ull,0x25202c3933316625ull,0x73090a3b30343166ull,
0x09203233662e6275ull,0x25202c3234316625ull,0x316625202c313366ull,0x627573090a3b3034ull,
0x662509203233662eull,0x316625202c333431ull,0x34316625202c3733ull,0x2e646461090a3b31ull,
0x3166250920323366ull,0x34316625202c3434ull,0x3334316625202c32ull,0x662e646461090a3bull,
0x3431662509203233ull,0x3434316625202c35ull,0x0a3b33336625202cull,0x3233662e64646109ull,
0x2c36343166250920ull,0x202c353431662520ull,0x61090a3b36386625ull,0x09203233662e6464ull,
0x25202c3734316625ull,0x6625202c39333166ull,0x6f6d090a3b363431ull,0x2509203233662e76ull,
0x316625202c323366ull,0x627573090a3b3734ull,0x662509203233662eull,0x316625202c383431ull,
0x33316625202c3734ull,0x2e627573090a3b39ull,0x3366250920323366ull,0x3634316625202c33ull,
0x3b3834316625202cull,0x3109636f6c2e090aull,0x0a30093831340935ull,0x3233662e62757309ull,
0x2c39343166250920ull,0x25202c3338662520ull,0x7573090a3b383566ull,0x2509203233662e62ull,
0x6625202c30353166ull,0x386625202c393431ull,0x2e627573090a3b33ull,0x3166250920323366ull,
0x34316625202c3135ull,0x3035316625202c39ull,0x662e646461090a3bull,0x3531662509203233ull,
0x3035316625202c32ull,0x0a3b38356625202cull,0x3233662e62757309ull,0x2c33353166250920ull,
0x25202c3338662520ull,0x73090a3b31353166ull,0x09203233662e6275ull,0x25202c3435316625ull,
0x6625202c33353166ull,0x6461090a3b323531ull,0x2509203233662e64ull,0x6625202c35353166ull,
0x386625202c343531ull,0x2e627573090a3b35ull,0x3166250920323366ull,0x35316625202c3635ull,
0x3b30366625202c35ull,0x33662e646461090aull,0x3735316625092032ull,0x2c3934316625202cull,
0x0a3b363531662520ull,0x3233662e64646109ull,0x2c38353166250920ull,0x202c373531662520ull,
0x73090a3b30336625ull,0x09203233662e6275ull,0x25202c3935316625ull,0x6625202c38353166ull,
0x7573090a3b373531ull,0x2509203233662e62ull,0x6625202c30363166ull,0x316625202c383531ull,
0x627573090a3b3935ull,0x662509203233662eull,0x316625202c313631ull,0x36316625202c3735ull,
0x2e627573090a3b30ull,0x3166250920323366ull,0x30336625202c3236ull,0x3b3935316625202cull,
0x33662e646461090aull,0x3336316625092032ull,0x2c3136316625202cull,0x0a3b323631662520ull,
0x3233662e62757309ull,0x2c34363166250920ull,0x202c373531662520ull,0x090a3b3934316625ull,
0x203233662e627573ull,0x202c353631662509ull,0x25202c3635316625ull,0x61090a3b34363166ull,
0x09203233662e6464ull,0x25202c3636316625ull,0x6625202c33363166ull,0x6461090a3b353631ull,
0x2509203233662e64ull,0x6625202c37363166ull,0x36316625202c3738ull,0x2e646461090a3b36ull,
0x3166250920323366ull,0x35316625202c3836ull,0x3736316625202c38ull,0x662e766f6d090a3bull,
0x3433662509203233ull,0x3b3836316625202cull,0x33662e627573090aull,0x3936316625092032ull,
0x2c3836316625202cull,0x0a3b383531662520ull,0x3233662e62757309ull,0x202c353366250920ull,
0x25202c3736316625ull,0x2e090a3b39363166ull,0x3409353109636f6cull,0x6f6d090a30093032ull,
0x2509203233662e76ull,0x6630202c30373166ull,0x3030343030303634ull,0x202f2f092020203bull,
0x756d090a33393138ull,0x2509203233662e6cull,0x6625202c31373166ull,0x316625202c373431ull,
0x6c756d090a3b3037ull,0x662509203233662eull,0x316625202c323731ull,0x33336625202c3734ull,
0x662e6c756d090a3bull,0x3731662509203233ull,0x3734316625202c33ull,0x3b3734316625202cull,
0x33662e627573090aull,0x3437316625092032ull,0x2c3137316625202cull,0x0a3b373431662520ull,
0x3233662e64616d09ull,0x2c35373166250920ull,0x202c373431662520ull,0x6625202c33336625ull,
0x7573090a3b323731ull,0x2509203233662e62ull,0x6625202c38303166ull,0x316625202c313731ull,
0x646461090a3b3437ull,0x662509203233662eull,0x316625202c363731ull,0x37316625202c3337ull,
0x2e627573090a3b35ull,0x3166250920323366ull,0x34316625202c3031ull,0x3830316625202c37ull,
0x662e6c756d090a3bull,0x3731662509203233ull,0x3830316625202c37ull,0x3b3830316625202cull,
0x33662e627573090aull,0x3837316625092032ull,0x2c3737316625202cull,0x0a3b333731662520ull,
0x3233662e62757309ull,0x2c39373166250920ull,0x202c363731662520ull,0x090a3b3337316625ull,
0x203233662e64616dull,0x202c303831662509ull,0x25202c3830316625ull,0x6625202c30313166ull,
0x7573090a3b383731ull,0x2509203233662e62ull,0x6625202c31383166ull,0x316625202c353731ull,
0x627573090a3b3937ull,0x662509203233662eull,0x316625202c323831ull,0x37316625202c3637ull,
0x2e64616d090a3b39ull,0x3166250920323366ull,0x30316625202c3338ull,0x3031316625202c38ull,
0x3b3038316625202cull,0x33662e627573090aull,0x3438316625092032ull,0x2c3337316625202cull,
0x0a3b323831662520ull,0x3233662e64616d09ull,0x2c35383166250920ull,0x202c303131662520ull,
0x25202c3031316625ull,0x61090a3b33383166ull,0x09203233662e6464ull,0x25202c3638316625ull,
0x6625202c31383166ull,0x6461090a3b343831ull,0x2509203233662e64ull,0x6625202c37383166ull,
0x316625202c353831ull,0x64616d090a3b3638ull,0x662509203233662eull,0x336625202c383831ull,
0x2c33336625202c33ull,0x0a3b373831662520ull,0x3233662e64646109ull,0x2c39383166250920ull,
0x202c363731662520ull,0x090a3b3838316625ull,0x203233662e766f6dull,0x25202c3835662509ull,
0x73090a3b39383166ull,0x09203233662e6275ull,0x25202c3039316625ull,0x6625202c39383166ull,
0x7573090a3b363731ull,0x2509203233662e62ull,0x316625202c303666ull,0x39316625202c3838ull,
0x636f6c2e090a3b30ull,0x0931323409353109ull,0x662e766f6d090a30ull,0x3931662509203233ull,
0x3036346630202c31ull,0x20203b3030343030ull,0x393138202f2f0920ull,0x662e6c756d090a33ull,
0x3931662509203233ull,0x3836316625202c32ull,0x3b3139316625202cull,0x33662e6c756d090aull,
0x3339316625092032ull,0x2c3836316625202cull,0x090a3b3533662520ull,0x203233662e6c756dull,
0x202c343931662509ull,0x25202c3836316625ull,0x73090a3b38363166ull,0x09203233662e6275ull,
0x25202c3539316625ull,0x6625202c32393166ull,0x616d090a3b383631ull,0x2509203233662e64ull,
0x6625202c36393166ull,0x336625202c383631ull,0x3339316625202c35ull,0x662e627573090a3bull,
0x3031662509203233ull,0x3239316625202c37ull,0x3b3539316625202cull,0x33662e646461090aull,
0x3739316625092032ull,0x2c3439316625202cull,0x0a3b363931662520ull,0x3233662e62757309ull,
0x2c39303166250920ull,0x202c383631662520ull,0x090a3b3730316625ull,0x203233662e6c756dull,
0x202c383931662509ull,0x25202c3730316625ull,0x73090a3b37303166ull,0x09203233662e6275ull,
0x25202c3939316625ull,0x6625202c38393166ull,0x7573090a3b343931ull,0x2509203233662e62ull,
0x6625202c30303266ull,0x316625202c373931ull,0x64616d090a3b3439ull,0x662509203233662eull,
0x316625202c313032ull,0x30316625202c3730ull,0x3939316625202c39ull,0x662e627573090a3bull,
0x3032662509203233ull,0x3639316625202c32ull,0x3b3030326625202cull,0x33662e627573090aull,
0x3330326625092032ull,0x2c3739316625202cull,0x0a3b303032662520ull,0x3233662e64616d09ull,
0x2c34303266250920ull,0x202c373031662520ull,0x25202c3930316625ull,0x73090a3b31303266ull,
0x09203233662e6275ull,0x25202c3530326625ull,0x6625202c34393166ull,0x616d090a3b333032ull,
0x2509203233662e64ull,0x6625202c36303266ull,0x316625202c393031ull,0x30326625202c3930ull,
0x2e646461090a3b34ull,0x3266250920323366ull,0x30326625202c3730ull,0x3530326625202c32ull,
0x662e646461090a3bull,0x3032662509203233ull,0x3630326625202c38ull,0x3b3730326625202cull,
0x33662e64616d090aull,0x3930326625092032ull,0x202c35336625202cull,0x6625202c35336625ull,
0x6461090a3b383032ull,0x2509203233662e64ull,0x6625202c30313266ull,0x326625202c373931ull,
0x766f6d090a3b3930ull,0x662509203233662eull,0x31326625202c3338ull,0x2e627573090a3b30ull,
0x3266250920323366ull,0x31326625202c3131ull,0x3739316625202c30ull,0x662e627573090a3bull,
0x3538662509203233ull,0x2c3930326625202cull,0x0a3b313132662520ull,0x353109636f6c2e09ull,
0x090a300932323409ull,0x203233662e646461ull,0x202c323132662509ull,0x25202c3938316625ull,
0x73090a3b30313266ull,0x09203233662e6275ull,0x25202c3331326625ull,0x6625202c32313266ull,
0x7573090a3b303132ull,0x2509203233662e62ull,0x6625202c34313266ull,0x326625202c393831ull,
0x627573090a3b3331ull,0x662509203233662eull,0x326625202c353132ull,0x31326625202c3231ull,
0x2e627573090a3b33ull,0x3266250920323366ull,0x31326625202c3631ull,0x3531326625202c30ull,
0x662e646461090a3bull,0x3132662509203233ull,0x3431326625202c37ull,0x3b3631326625202cull,
0x33662e646461090aull,0x3831326625092032ull,0x202c35386625202cull,0x090a3b3731326625ull,
0x203233662e646461ull,0x202c393132662509ull,0x6625202c30366625ull,0x6461090a3b383132ull,
0x2509203233662e64ull,0x6625202c33313266ull,0x326625202c323132ull,0x627573090a3b3931ull,
0x662509203233662eull,0x326625202c303232ull,0x31326625202c3331ull,0x2e627573090a3b32ull,
0x3266250920323366ull,0x31326625202c3132ull,0x3032326625202c39ull,0x09636f6c2e090a3bull,
0x3009323134093531ull,0x33732e627573090aull,0x2c38317225092032ull,0x31202c3831722520ull,
0x752e766f6d090a3bull,0x3032722509203233ull,0x6573090a3b30202cull,0x33732e71652e7074ull,
0x202c357025092032ull,0x7225202c38317225ull,0x702540090a3b3032ull,0x2409206172622035ull,
0x3639385f305f744cull,0x6c3c2f2f200a3b32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c33313420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x0a303938355f305full,0x3233662e64646109ull,0x2c32323266250920ull,0x202c313232662520ull,
0x090a3b3331326625ull,0x203233662e766f6dull,0x202c333232662509ull,0x3030303830346630ull,
0x2f092020203b3030ull,0x746573090a34202full,0x3233662e746c2e70ull,0x25202c3670250920ull,
0x6625202c32323266ull,0x2540090a3b333232ull,0x0920617262203670ull,0x3938355f305f4c24ull,
0x305f744c240a3b30ull,0x240a3a323639385full,0x363431365f305f4cull,0x09636f6c2e090a3aull,
0x0a30093037093631ull,0x3233732e766f6d09ull,0x202c313272250920ull,0x70746573090a3b30ull,
0x203233732e74672eull,0x7225202c37702509ull,0x31327225202c3831ull,0x732e627573090a3bull,
0x3232722509203233ull,0x202c37317225202cull,0x6d090a3b38317225ull,0x09203233732e766full,
0x3b30202c33327225ull,0x732e706c6573090aull,0x3432722509203233ull,0x202c32327225202cull,
0x7025202c33327225ull,0x2e766f6d090a3b37ull,0x3272250920323375ull,0x73090a3b30202c35ull,
0x732e71652e707465ull,0x2c38702509203233ull,0x25202c3432722520ull,0x2540090a3b353272ull,
0x0920617262203870ull,0x31385f305f744c24ull,0x6f6c2e090a3b3439ull,0x0937370936310963ull,
0x61702e646c090a30ull,0x203233732e6d6172ull,0x5b202c3632722509ull,0x6170616475635f5full,
0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x6269695f53666666ull,0x6974616d696e615full,0x5d656d6172466e6full,
0x732e646461090a3bull,0x3732722509203233ull,0x202c36327225202cull,0x6c090a3b34327225ull,
0x2e6d617261702e64ull,0x3832722509203875ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x5f53666666666666ull,0x6f6c6f635f626969ull,0x090a3b5d302b7372ull,0x732e6f6c2e6c756dull,
0x3932722509203233ull,0x202c37327225202cull,0x63090a3b38327225ull,0x33752e38752e7476ull,
0x2c30337225092032ull,0x090a3b3932722520ull,0x09363109636f6c2eull,0x646c090a30093837ull,
0x752e6d617261702eull,0x2c31337225092038ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f305344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x695f536666666666ull,0x726f6c6f635f6269ull,0x6d090a3b5d312b73ull,0x33732e6f6c2e6c75ull,
0x2c32337225092032ull,0x25202c3732722520ull,0x7663090a3b313372ull,0x3233752e38752e74ull,
0x202c333372250920ull,0x2e090a3b32337225ull,0x3709363109636f6cull,0x2e646c090a300939ull,
0x38752e6d61726170ull,0x202c343372250920ull,0x70616475635f5f5bull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f305344746full,0x6168637536503031ull,0x6666666969693472ull,
0x69695f5366666666ull,0x73726f6c6f635f62ull,0x756d090a3b5d322bull,0x3233732e6f6c2e6cull,
0x202c353372250920ull,0x7225202c37327225ull,0x747663090a3b3433ull,0x203233752e38752eull,
0x25202c3633722509ull,0x7262090a3b353372ull,0x240920696e752e61ull,0x3339375f305f744cull,
0x305f744c240a3b38ull,0x090a3a343931385full,0x09363109636f6c2eull,0x6f6d090a30093338ull,
0x2509203233752e76ull,0x0a3b30202c363372ull,0x3233752e766f6d09ull,0x202c333372250920ull,
0x2e766f6d090a3b30ull,0x3372250920323375ull,0x4c240a3b30202c30ull,0x383339375f305f74ull,
0x61702e646c090a3aull,0x203436752e6d6172ull,0x5b202c3164722509ull,0x6170616475635f5full,
0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,0x316d735f30534474ull,0x7261686375365030ull,
0x6666666669696934ull,0x6269695f53666666ull,0x090a3b5d7473645full,0x732e6f6c2e6c756dull,
0x3733722509203233ull,0x25202c377225202cull,0x646461090a3b3672ull,0x722509203233732eull,
0x2c347225202c3833ull,0x090a3b3733722520ull,0x2e3436752e747663ull,0x6472250920323373ull,
0x3b38337225202c32ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x32647225202c3364ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x647225202c346472ull,0x3b33647225202c31ull,
0x7261702e646c090aull,0x09203233732e6d61ull,0x5f5b202c39337225ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f305344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x0a3b5d656d617266ull,0x3233752e766f6d09ull,
0x202c303472250920ull,0x70746573090a3b30ull,0x203233732e656e2eull,0x7225202c39702509ull,
0x30347225202c3933ull,0x2039702540090a3bull,0x744c240920617262ull,0x3b363037385f305full,
0x3109636f6c2e090aull,0x090a300930390936ull,0x203233752e766f6dull,0x30202c3134722509ull,
0x6c672e7473090a3bull,0x2e34762e6c61626full,0x6472255b09203875ull,0x257b202c5d302b34ull,
0x333372252c303372ull,0x72252c363372252cull,0x7262090a3b7d3134ull,0x240920696e752e61ull,
0x3534385f305f744cull,0x305f744c240a3b30ull,0x090a3a363037385full,0x09363109636f6c2eull,
0x6461090a30093439ull,0x2509203233732e64ull,0x337225202c323472ull,0x73090a3b31202c39ull,
0x09203233732e7268ull,0x7225202c33347225ull,0x0a3b3133202c3234ull,0x3233732e766f6d09ull,
0x202c343472250920ull,0x2e646e61090a3b31ull,0x3472250920323362ull,0x2c33347225202c35ull,
0x090a3b3434722520ull,0x203233732e646461ull,0x25202c3634722509ull,0x347225202c353472ull,
0x2e726873090a3b32ull,0x3472250920323373ull,0x2c36347225202c37ull,0x2e646c090a3b3120ull,
0x762e6c61626f6c67ull,0x257b092038752e34ull,0x393472252c383472ull,0x7d5f2c303572252cull,
0x2b346472255b202cull,0x6c756d090a3b5d30ull,0x203233732e6f6c2eull,0x25202c3135722509ull,
0x347225202c393372ull,0x2e646461090a3b38ull,0x3572250920323373ull,0x2c30337225202c32ull,
0x090a3b3135722520ull,0x203233732e646461ull,0x25202c3335722509ull,0x357225202c373472ull,
0x2e766964090a3b32ull,0x3572250920323373ull,0x2c33357225202c34ull,0x090a3b3234722520ull,
0x09363109636f6c2eull,0x756d090a30093539ull,0x3233732e6f6c2e6cull,0x202c353572250920ull,
0x7225202c39337225ull,0x646461090a3b3934ull,0x722509203233732eull,0x33337225202c3635ull,
0x0a3b35357225202cull,0x3233732e64646109ull,0x202c373572250920ull,0x7225202c37347225ull,
0x766964090a3b3635ull,0x722509203233732eull,0x37357225202c3835ull,0x0a3b32347225202cull,
0x626f6c672e747309ull,0x38752e32762e6c61ull,0x2b346472255b0920ull,0x3572257b202c5d30ull,
0x3b7d383572252c34ull,0x3109636f6c2e090aull,0x090a300936390936ull,0x732e6f6c2e6c756dull,
0x3935722509203233ull,0x202c39337225202cull,0x61090a3b30357225ull,0x09203233732e6464ull,
0x7225202c30367225ull,0x39357225202c3633ull,0x732e646461090a3bull,0x3136722509203233ull,
0x202c37347225202cull,0x64090a3b30367225ull,0x09203233732e7669ull,0x7225202c32367225ull,
0x32347225202c3136ull,0x6c672e7473090a3bull,0x2038752e6c61626full,0x322b346472255b09ull,
0x3b32367225202c5dull,0x385f305f744c240aull,0x744c240a3a303534ull,0x3a343139365f305full,
0x3109636f6c2e090aull,0x090a300939390936ull,0x4c240a3b74697865ull,0x5a5f5f646e655744ull,
0x6c65646e614d3831ull,0x5f305344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,
0x5f53666666666666ull,0x207d090a3a626969ull,0x4d38315a5f202f2full,0x6f72626c65646e61ull,
0x316d735f30534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6269695f53666666ull,
0x72746e652e090a0aull,0x614d38315a5f2079ull,0x746f72626c65646eull,0x30316d735f315344ull,
0x3472616863753650ull,0x6666666666696969ull,0x206269695f536666ull,0x7261702e09090a28ull,
0x203436752e206d61ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,
0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6269695f53666666ull,
0x09090a2c7473645full,0x2e206d617261702eull,0x75635f5f20323373ull,0x5f5f6d7261706164ull,
0x65646e614d38315aull,0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,
0x5366666666666666ull,0x616d695f6269695full,0x2e09090a2c576567ull,0x732e206d61726170ull,
0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,0x5f315344746f7262ull,
0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,0x67616d695f626969ull,
0x702e09090a2c4865ull,0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,
0x626c65646e614d38ull,0x735f315344746f72ull,0x686375365030316dull,0x6666696969347261ull,
0x695f536666666666ull,0x636e7572635f6269ull,0x61702e09090a2c68ull,0x3233662e206d6172ull,
0x70616475635f5f20ull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,
0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,0x2c3066664f785f62ull,
0x617261702e09090aull,0x5f203233662e206dull,0x726170616475635full,0x614d38315a5f5f6dull,
0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,
0x5f6269695f536666ull,0x090a2c3166664f78ull,0x206d617261702e09ull,0x635f5f203233662eull,
0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f31ull,
0x6969347261686375ull,0x6666666666666669ull,0x4f795f6269695f53ull,0x2e09090a2c306666ull,
0x662e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,
0x5f315344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,
0x66664f795f626969ull,0x61702e09090a2c31ull,0x3233662e206d6172ull,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x69695f5366666666ull,0x090a2c504a785f62ull,0x206d617261702e09ull,
0x635f5f203233662eull,0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,
0x365030316d735f31ull,0x6969347261686375ull,0x6666666666666669ull,0x4a795f6269695f53ull,
0x61702e09090a2c50ull,0x3233662e206d6172ull,0x70616475635f5f20ull,0x38315a5f5f6d7261ull,
0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,
0x69695f5366666666ull,0x2c656c6163735f62ull,0x617261702e09090aull,0x6e67696c612e206dull,
0x5f2038622e203420ull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,0x5f6269695f536666ull,
0x345b73726f6c6f63ull,0x61702e09090a2c5dull,0x3233732e206d6172ull,0x70616475635f5f20ull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x69695f5366666666ull,0x2c656d6172665f62ull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,
0x30316d735f315344ull,0x3472616863753650ull,0x6666666666696969ull,0x5f6269695f536666ull,
0x6f6974616d696e61ull,0x0a2c656d6172466eull,0x6d617261702e0909ull,0x635f5f2038732e20ull,
0x5f6d726170616475ull,0x646e614d38315a5full,0x5344746f72626c65ull,0x365030316d735f31ull,
0x6969347261686375ull,0x6666666666666669ull,0x73695f6269695f53ull,0x2e090a7b090a294aull,
0x3631752e20676572ull,0x3b3e363c68722520ull,0x2e206765722e090aull,0x313c722520323375ull,
0x722e090a3b3e3934ull,0x203436752e206765ull,0x3b3e32313c647225ull,0x2e206765722e090aull,
0x323c662520323366ull,0x722e090a3b3e3532ull,0x646572702e206765ull,0x3b3e35313c702520ull,
0x3109636f6c2e090aull,0x0a30093136310936ull,0x5a5f5f3142424c24ull,0x6c65646e614d3831ull,
0x5f315344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,
0x6f6d090a3a626969ull,0x2509203631752e76ull,0x746325202c316872ull,0x090a3b782e646961ull,
0x203631752e766f6dull,0x25202c3268722509ull,0x0a3b782e6469746eull,0x6469772e6c756d09ull,
0x2509203631752e65ull,0x31687225202c3172ull,0x0a3b32687225202cull,0x3631752e766f6d09ull,
0x202c336872250920ull,0x792e646961746325ull,0x752e766f6d090a3bull,0x3468722509203631ull,
0x2e6469746e25202cull,0x2e6c756d090a3b79ull,0x3631752e65646977ull,0x25202c3272250920ull,
0x687225202c336872ull,0x2e747663090a3b34ull,0x203631752e323375ull,0x7425202c33722509ull,
0x61090a3b782e6469ull,0x09203233752e6464ull,0x337225202c347225ull,0x090a3b317225202cull,
0x2e3233752e747663ull,0x3572250920363175ull,0x792e64697425202cull,0x752e646461090a3bull,
0x2c36722509203233ull,0x7225202c35722520ull,0x702e646c090a3b32ull,0x3233732e6d617261ull,
0x5b202c3772250920ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,
0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6269695f53666666ull,
0x5d486567616d695full,0x61702e646c090a3bull,0x203233732e6d6172ull,0x5f5b202c38722509ull,
0x726170616475635full,0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f315344ull,
0x3472616863753650ull,0x6666666666696969ull,0x5f6269695f536666ull,0x3b5d576567616d69ull,
0x74672e746573090aull,0x3233732e3233752eull,0x25202c3972250920ull,0x3b367225202c3772ull,
0x33732e67656e090aull,0x2c30317225092032ull,0x73090a3b39722520ull,0x33752e74672e7465ull,
0x2509203233732e32ull,0x387225202c313172ull,0x090a3b347225202cull,0x203233732e67656eull,
0x25202c3231722509ull,0x6e61090a3b313172ull,0x2509203233622e64ull,0x317225202c333172ull,
0x3b32317225202c30ull,0x33752e766f6d090aull,0x2c34317225092032ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x25202c3170250920ull,0x317225202c333172ull,0x31702540090a3b34ull,
0x4c24092061726220ull,0x343636315f315f74ull,0x636f6c2e090a3b32ull,0x0939363109363109ull,
0x6c2e6c756d090a30ull,0x2509203233732e6full,0x387225202c353172ull,0x090a3b367225202cull,
0x203233732e646461ull,0x25202c3631722509ull,0x35317225202c3472ull,0x61702e646c090a3bull,
0x203436752e6d6172ull,0x5b202c3164722509ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,
0x6f72626c65646e61ull,0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,
0x6269695f53666666ull,0x090a3b5d7473645full,0x2e3436752e747663ull,0x6472250920323373ull,
0x3b36317225202c32ull,0x6f6c2e6c756d090aull,0x722509203436752eull,0x32647225202c3364ull,
0x6461090a3b34202cull,0x2509203436752e64ull,0x647225202c346472ull,0x3b33647225202c31ull,
0x6f6c672e646c090aull,0x752e34762e6c6162ull,0x373172257b092038ull,0x72252c383172252cull,
0x5b202c7d5f2c3931ull,0x3b5d302b34647225ull,0x33752e766f6d090aull,0x2c30327225092032ull,
0x746573090a3b3020ull,0x3233732e656c2e70ull,0x25202c3270250920ull,0x30327225202c3472ull,
0x2032702540090a3bull,0x744c240920617262ull,0x30353834315f315full,0x6c672e646c090a3bull,
0x2e34762e6c61626full,0x3272257b09203875ull,0x252c323272252c31ull,0x202c7d5f2c333272ull,
0x342d2b346472255bull,0x636f6c2e090a3b5dull,0x0934373109363109ull,0x732e627573090a30ull,
0x3432722509203233ull,0x202c33327225202cull,0x61090a3b39317225ull,0x09203233732e7362ull,
0x7225202c35327225ull,0x766f6d090a3b3432ull,0x722509203233732eull,0x0a3b3031202c3632ull,
0x2e74672e74657309ull,0x203233732e323375ull,0x25202c3732722509ull,0x327225202c353272ull,
0x2e67656e090a3b36ull,0x3272250920323373ull,0x3b37327225202c38ull,0x33732e627573090aull,
0x2c39327225092032ull,0x25202c3132722520ull,0x6261090a3b373172ull,0x2509203233732e73ull,
0x327225202c303372ull,0x2e766f6d090a3b39ull,0x3372250920323373ull,0x090a3b3031202c31ull,
0x752e74672e746573ull,0x09203233732e3233ull,0x7225202c32337225ull,0x31337225202c3033ull,
0x732e67656e090a3bull,0x3333722509203233ull,0x0a3b32337225202cull,0x3233732e62757309ull,
0x202c343372250920ull,0x7225202c32327225ull,0x736261090a3b3831ull,0x722509203233732eull,
0x34337225202c3533ull,0x732e766f6d090a3bull,0x3633722509203233ull,0x73090a3b3031202cull,
0x33752e74672e7465ull,0x2509203233732e32ull,0x337225202c373372ull,0x3b36337225202c35ull,
0x33732e67656e090aull,0x2c38337225092032ull,0x090a3b3733722520ull,0x09203233622e726full,
0x7225202c39337225ull,0x38337225202c3333ull,0x33622e726f090a3bull,0x2c30347225092032ull,
0x25202c3832722520ull,0x7262090a3b393372ull,0x240920696e752e61ull,0x3534315f315f744cull,
0x5f744c240a3b3439ull,0x3a30353834315f31ull,0x33732e766f6d090aull,0x2c30347225092032ull,
0x5f744c240a3b3020ull,0x3a34393534315f31ull,0x33732e646461090aull,0x2c31347225092032ull,
0x3b31202c34722520ull,0x6c2e70746573090aull,0x2509203233732e65ull,0x2c387225202c3370ull,
0x090a3b3134722520ull,0x6172622033702540ull,0x5f315f744c240920ull,0x090a3b3630313531ull,
0x61626f6c672e646cull,0x2038752e34762e6cull,0x252c323472257b09ull,0x343472252c333472ull,
0x72255b202c7d5f2cull,0x090a3b5d342b3464ull,0x09363109636f6c2eull,0x73090a3009363731ull,
0x09203233732e6275ull,0x7225202c35347225ull,0x39317225202c3434ull,0x732e736261090a3bull,
0x3634722509203233ull,0x0a3b35347225202cull,0x3233732e766f6d09ull,0x202c373472250920ull,
0x746573090a3b3031ull,0x2e3233752e74672eull,0x3472250920323373ull,0x2c36347225202c38ull,
0x090a3b3734722520ull,0x203233732e67656eull,0x25202c3934722509ull,0x7573090a3b383472ull,
0x2509203233732e62ull,0x347225202c303572ull,0x3b37317225202c32ull,0x33732e736261090aull,
0x2c31357225092032ull,0x090a3b3035722520ull,0x203233732e766f6dull,0x31202c3235722509ull,
0x2e746573090a3b30ull,0x732e3233752e7467ull,0x3335722509203233ull,0x202c31357225202cull,
0x6e090a3b32357225ull,0x09203233732e6765ull,0x7225202c34357225ull,0x627573090a3b3335ull,
0x722509203233732eull,0x33347225202c3535ull,0x0a3b38317225202cull,0x3233732e73626109ull,
0x202c363572250920ull,0x6d090a3b35357225ull,0x09203233732e766full,0x3031202c37357225ull,
0x672e746573090a3bull,0x33732e3233752e74ull,0x2c38357225092032ull,0x25202c3635722520ull,
0x656e090a3b373572ull,0x2509203233732e67ull,0x357225202c393572ull,0x622e726f090a3b38ull,
0x3036722509203233ull,0x202c34357225202cull,0x6f090a3b39357225ull,0x2509203233622e72ull,
0x347225202c313672ull,0x3b30367225202c39ull,0x33732e646461090aull,0x2c30347225092032ull,
0x25202c3034722520ull,0x744c240a3b313672ull,0x36303135315f315full,0x752e766f6d090a3aull,
0x3236722509203233ull,0x6573090a3b30202cull,0x33732e656c2e7074ull,0x202c347025092032ull,
0x367225202c367225ull,0x34702540090a3b32ull,0x4c24092061726220ull,0x313635315f315f74ull,
0x636f6c2e090a3b38ull,0x0938373109363109ull,0x732e627573090a30ull,0x3336722509203233ull,
0x202c36317225202cull,0x7663090a3b387225ull,0x33732e3436732e74ull,0x2c35647225092032ull,
0x090a3b3336722520ull,0x752e6f6c2e6c756dull,0x3664722509203436ull,0x202c35647225202cull,
0x2e646461090a3b34ull,0x6472250920343675ull,0x2c31647225202c37ull,0x090a3b3664722520ull,
0x61626f6c672e646cull,0x2038752e34762e6cull,0x252c343672257b09ull,0x363672252c353672ull,
0x72255b202c7d5f2cull,0x090a3b5d302b3764ull,0x203233732e627573ull,0x25202c3736722509ull,
0x317225202c363672ull,0x2e736261090a3b39ull,0x3672250920323373ull,0x3b37367225202c38ull,
0x33732e766f6d090aull,0x2c39367225092032ull,0x6573090a3b303120ull,0x3233752e74672e74ull,
0x722509203233732eull,0x38367225202c3037ull,0x0a3b39367225202cull,0x3233732e67656e09ull,
0x202c313772250920ull,0x73090a3b30377225ull,0x09203233732e6275ull,0x7225202c32377225ull,
0x37317225202c3436ull,0x732e736261090a3bull,0x3337722509203233ull,0x0a3b32377225202cull,
0x3233732e766f6d09ull,0x202c343772250920ull,0x746573090a3b3031ull,0x2e3233752e74672eull,
0x3772250920323373ull,0x2c33377225202c35ull,0x090a3b3437722520ull,0x203233732e67656eull,
0x25202c3637722509ull,0x7573090a3b353772ull,0x2509203233732e62ull,0x367225202c373772ull,
0x3b38317225202c35ull,0x33732e736261090aull,0x2c38377225092032ull,0x090a3b3737722520ull,
0x203233732e766f6dull,0x31202c3937722509ull,0x2e746573090a3b30ull,0x732e3233752e7467ull,
0x3038722509203233ull,0x202c38377225202cull,0x6e090a3b39377225ull,0x09203233732e6765ull,
0x7225202c31387225ull,0x2e726f090a3b3038ull,0x3872250920323362ull,0x2c36377225202c32ull,
0x090a3b3138722520ull,0x09203233622e726full,0x7225202c33387225ull,0x32387225202c3137ull,
0x732e646461090a3bull,0x3034722509203233ull,0x202c30347225202cull,0x4c240a3b33387225ull,
0x313635315f315f74ull,0x2e646461090a3a38ull,0x3872250920323373ull,0x202c367225202c34ull,
0x70746573090a3b31ull,0x203233732e656c2eull,0x7225202c35702509ull,0x3b34387225202c37ull,
0x622035702540090aull,0x5f744c2409206172ull,0x3b30333136315f31ull,0x3109636f6c2e090aull,
0x0a30093038310936ull,0x3233732e64646109ull,0x202c353872250920ull,0x7225202c36317225ull,
0x2e747663090a3b38ull,0x203233732e343673ull,0x25202c3864722509ull,0x756d090a3b353872ull,
0x3436752e6f6c2e6cull,0x202c396472250920ull,0x3b34202c38647225ull,0x36752e646461090aull,
0x3031647225092034ull,0x202c31647225202cull,0x6c090a3b39647225ull,0x6c61626f6c672e64ull,
0x092038752e34762eull,0x72252c363872257bull,0x2c383872252c3738ull,0x6472255b202c7d5full,
0x090a3b5d302b3031ull,0x203233732e627573ull,0x25202c3938722509ull,0x317225202c383872ull,
0x2e736261090a3b39ull,0x3972250920323373ull,0x3b39387225202c30ull,0x33732e766f6d090aull,
0x2c31397225092032ull,0x6573090a3b303120ull,0x3233752e74672e74ull,0x722509203233732eull,
0x30397225202c3239ull,0x0a3b31397225202cull,0x3233732e67656e09ull,0x202c333972250920ull,
0x73090a3b32397225ull,0x09203233732e6275ull,0x7225202c34397225ull,0x37317225202c3638ull,
0x732e736261090a3bull,0x3539722509203233ull,0x0a3b34397225202cull,0x3233732e766f6d09ull,
0x202c363972250920ull,0x746573090a3b3031ull,0x2e3233752e74672eull,0x3972250920323373ull,
0x2c35397225202c37ull,0x090a3b3639722520ull,0x203233732e67656eull,0x25202c3839722509ull,
0x7573090a3b373972ull,0x2509203233732e62ull,0x387225202c393972ull,0x3b38317225202c37ull,
0x33732e736261090aull,0x3030317225092032ull,0x0a3b39397225202cull,0x3233732e766f6d09ull,
0x2c31303172250920ull,0x6573090a3b303120ull,0x3233752e74672e74ull,0x722509203233732eull,
0x317225202c323031ull,0x30317225202c3030ull,0x2e67656e090a3b31ull,0x3172250920323373ull,
0x30317225202c3330ull,0x622e726f090a3b32ull,0x3031722509203233ull,0x2c38397225202c34ull,
0x0a3b333031722520ull,0x203233622e726f09ull,0x202c353031722509ull,0x7225202c33397225ull,
0x6461090a3b343031ull,0x2509203233732e64ull,0x347225202c303472ull,0x3530317225202c30ull,
0x5f315f744c240a3bull,0x090a3a3033313631ull,0x203233752e766f6dull,0x202c363031722509ull,
0x70746573090a3b30ull,0x203233732e71652eull,0x7225202c36702509ull,0x30317225202c3034ull,
0x36702540090a3b36ull,0x4c24092061726220ull,0x343636315f315f74ull,0x636f6c2e090a3b32ull,
0x0937383109363109ull,0x722e747663090a30ull,0x33732e3233662e6eull,0x202c316625092032ull,
0x646c090a3b347225ull,0x662e6d617261702eull,0x2c32662509203233ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f315344746f72ull,0x686375365030316dull,
0x6666696969347261ull,0x695f536666666666ull,0x656c6163735f6269ull,0x2e6c756d090a3b5dull,
0x3366250920323366ull,0x25202c316625202cull,0x2e646c090a3b3266ull,0x33662e6d61726170ull,
0x202c346625092032ull,0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,
0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,
0x5d3066664f785f62ull,0x662e646461090a3bull,0x2c35662509203233ull,0x6625202c33662520ull,
0x2e627573090a3b34ull,0x3666250920323366ull,0x25202c356625202cull,0x627573090a3b3366ull,
0x662509203233662eull,0x202c346625202c37ull,0x7573090a3b366625ull,0x2509203233662e62ull,
0x2c356625202c3866ull,0x73090a3b36662520ull,0x09203233662e6275ull,0x336625202c396625ull,
0x090a3b386625202cull,0x203233662e646461ull,0x25202c3031662509ull,0x3b396625202c3766ull,
0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5b202c31316625ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x0a3b5d3166664f78ull,0x3233662e64646109ull,
0x202c323166250920ull,0x6625202c31316625ull,0x646461090a3b3031ull,0x662509203233662eull,
0x2c356625202c3331ull,0x090a3b3231662520ull,0x203233662e627573ull,0x25202c3431662509ull,
0x356625202c333166ull,0x662e627573090a3bull,0x3531662509203233ull,0x202c32316625202cull,
0x2e090a3b34316625ull,0x3109363109636f6cull,0x7663090a30093838ull,0x3233662e6e722e74ull,
0x662509203233732eull,0x3b367225202c3631ull,0x33662e6c756d090aull,0x2c37316625092032ull,
0x25202c3631662520ull,0x2e646c090a3b3266ull,0x33662e6d61726170ull,0x2c38316625092032ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d38ull,0x735f315344746f72ull,
0x686375365030316dull,0x6666696969347261ull,0x695f536666666666ull,0x3066664f795f6269ull,
0x2e646461090a3b5dull,0x3166250920323366ull,0x2c37316625202c39ull,0x090a3b3831662520ull,
0x203233662e627573ull,0x25202c3032662509ull,0x316625202c393166ull,0x2e627573090a3b37ull,
0x3266250920323366ull,0x2c38316625202c31ull,0x090a3b3032662520ull,0x203233662e627573ull,
0x25202c3232662509ull,0x326625202c393166ull,0x2e627573090a3b30ull,0x3266250920323366ull,
0x2c37316625202c33ull,0x090a3b3232662520ull,0x203233662e646461ull,0x25202c3432662509ull,
0x326625202c313266ull,0x702e646c090a3b33ull,0x3233662e6d617261ull,0x202c353266250920ull,
0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,
0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,0x5d3166664f795f62ull,
0x662e646461090a3bull,0x3632662509203233ull,0x202c35326625202cull,0x61090a3b34326625ull,
0x09203233662e6464ull,0x6625202c37326625ull,0x36326625202c3931ull,0x662e627573090a3bull,
0x3832662509203233ull,0x202c37326625202cull,0x73090a3b39316625ull,0x09203233662e6275ull,
0x6625202c39326625ull,0x38326625202c3632ull,0x09636f6c2e090a3bull,0x3009313931093631ull,
0x7261702e646c090aull,0x25092038732e6d61ull,0x5f5b202c37303172ull,0x726170616475635full,
0x614d38315a5f5f6dull,0x746f72626c65646eull,0x30316d735f315344ull,0x3472616863753650ull,
0x6666666666696969ull,0x5f6269695f536666ull,0x6d090a3b5d4a7369ull,0x09203233752e766full,
0x30202c3830317225ull,0x2e70746573090a3bull,0x09203233732e7165ull,0x317225202c377025ull,
0x30317225202c3730ull,0x37702540090a3b38ull,0x4c24092061726220ull,0x313437315f315f74ull,
0x636f6c2e090a3b30ull,0x0935383309353109ull,0x61702e646c090a30ull,0x203233662e6d6172ull,
0x5b202c3033662509ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,0x6f72626c65646e61ull,
0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,0x6269695f53666666ull,
0x090a3b5d504a785full,0x09353109636f6c2eull,0x6c090a3009373833ull,0x2e6d617261702e64ull,
0x3366250920323366ull,0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x65646e614d38315aull,
0x315344746f72626cull,0x75365030316d735full,0x6969693472616863ull,0x5366666666666666ull,
0x504a795f6269695full,0x636f6c2e090a3b5dull,0x0939383309353109ull,0x662e766f6d090a30ull,
0x3233662509203233ull,0x0a3b37326625202cull,0x353109636f6c2e09ull,0x090a300930393309ull,
0x203233662e766f6dull,0x25202c3333662509ull,0x6c2e090a3b393266ull,0x393309353109636full,
0x766f6d090a300931ull,0x662509203233662eull,0x33316625202c3433ull,0x09636f6c2e090a3bull,
0x3009323933093531ull,0x33662e766f6d090aull,0x2c35336625092032ull,0x090a3b3531662520ull,
0x09353109636f6c2eull,0x6d090a3009333933ull,0x09203233662e766full,0x6630202c36336625ull,
0x3030343030303634ull,0x2f2f09202020203bull,0x6d090a3339313820ull,0x09203233662e6c75ull,
0x6625202c37336625ull,0x36336625202c3732ull,0x662e627573090a3bull,0x3833662509203233ull,
0x202c37336625202cull,0x73090a3b37326625ull,0x09203233662e6275ull,0x6625202c39336625ull,
0x38336625202c3733ull,0x662e627573090a3bull,0x3034662509203233ull,0x202c37326625202cull,
0x6d090a3b39336625ull,0x09203233662e6c75ull,0x6625202c31346625ull,0x37326625202c3732ull,
0x662e6c756d090a3bull,0x3234662509203233ull,0x202c37326625202cull,0x6d090a3b39326625ull,
0x09203233662e6461ull,0x6625202c33346625ull,0x39326625202c3732ull,0x0a3b32346625202cull,
0x3233662e64646109ull,0x202c343466250920ull,0x6625202c31346625ull,0x6c756d090a3b3334ull,
0x662509203233662eull,0x39336625202c3534ull,0x0a3b39336625202cull,0x3233662e62757309ull,
0x202c363466250920ull,0x6625202c35346625ull,0x627573090a3b3134ull,0x662509203233662eull,
0x34346625202c3734ull,0x0a3b31346625202cull,0x3233662e64616d09ull,0x202c383466250920ull,
0x6625202c39336625ull,0x36346625202c3034ull,0x662e627573090a3bull,0x3934662509203233ull,
0x202c34346625202cull,0x73090a3b37346625ull,0x09203233662e6275ull,0x6625202c30356625ull,
0x37346625202c3334ull,0x662e64616d090a3bull,0x3135662509203233ull,0x202c39336625202cull,
0x6625202c30346625ull,0x627573090a3b3834ull,0x662509203233662eull,0x31346625202c3235ull,
0x0a3b39346625202cull,0x3233662e64616d09ull,0x202c333566250920ull,0x6625202c30346625ull,
0x31356625202c3034ull,0x662e646461090a3bull,0x3435662509203233ull,0x202c30356625202cull,
0x61090a3b32356625ull,0x09203233662e6464ull,0x6625202c35356625ull,0x34356625202c3335ull,
0x662e64616d090a3bull,0x3635662509203233ull,0x202c39326625202cull,0x6625202c39326625ull,
0x646461090a3b3535ull,0x662509203233662eull,0x34346625202c3735ull,0x0a3b36356625202cull,
0x3233662e766f6d09ull,0x202c383566250920ull,0x73090a3b37356625ull,0x09203233662e6275ull,
0x6625202c39356625ull,0x34346625202c3735ull,0x662e627573090a3bull,0x3036662509203233ull,
0x202c36356625202cull,0x2e090a3b39356625ull,0x3309353109636f6cull,0x6f6d090a30093439ull,
0x2509203233662e76ull,0x346630202c313666ull,0x3b30303430303036ull,0x202f2f0920202020ull,
0x756d090a33393138ull,0x2509203233662e6cull,0x316625202c323666ull,0x3b31366625202c33ull,
0x33662e627573090aull,0x2c33366625092032ull,0x25202c3236662520ull,0x7573090a3b333166ull,
0x2509203233662e62ull,0x366625202c343666ull,0x3b33366625202c32ull,0x33662e627573090aull,
0x2c35366625092032ull,0x25202c3331662520ull,0x756d090a3b343666ull,0x2509203233662e6cull,
0x316625202c363666ull,0x3b33316625202c33ull,0x33662e6c756d090aull,0x2c37366625092032ull,
0x25202c3331662520ull,0x616d090a3b353166ull,0x2509203233662e64ull,0x316625202c383666ull,
0x2c35316625202c33ull,0x090a3b3736662520ull,0x203233662e646461ull,0x25202c3936662509ull,
0x366625202c363666ull,0x2e6c756d090a3b38ull,0x3766250920323366ull,0x2c34366625202c30ull,
0x090a3b3436662520ull,0x203233662e627573ull,0x25202c3137662509ull,0x366625202c303766ull,
0x2e627573090a3b36ull,0x3766250920323366ull,0x2c39366625202c32ull,0x090a3b3636662520ull,
0x203233662e64616dull,0x25202c3337662509ull,0x366625202c343666ull,0x3b31376625202c35ull,
0x33662e627573090aull,0x2c34376625092032ull,0x25202c3936662520ull,0x7573090a3b323766ull,
0x2509203233662e62ull,0x366625202c353766ull,0x3b32376625202c38ull,0x33662e64616d090aull,
0x2c36376625092032ull,0x25202c3436662520ull,0x376625202c353666ull,0x2e627573090a3b33ull,
0x3766250920323366ull,0x2c36366625202c37ull,0x090a3b3437662520ull,0x203233662e64616dull,
0x25202c3837662509ull,0x366625202c353666ull,0x3b36376625202c35ull,0x33662e646461090aull,
0x2c39376625092032ull,0x25202c3537662520ull,0x6461090a3b373766ull,0x2509203233662e64ull,
0x376625202c303866ull,0x3b39376625202c38ull,0x33662e64616d090aull,0x2c31386625092032ull,
0x25202c3531662520ull,0x386625202c353166ull,0x2e646461090a3b30ull,0x3866250920323366ull,
0x2c39366625202c32ull,0x090a3b3138662520ull,0x203233662e766f6dull,0x25202c3338662509ull,
0x7573090a3b323866ull,0x2509203233662e62ull,0x386625202c343866ull,0x3b39366625202c32ull,
0x33662e627573090aull,0x2c35386625092032ull,0x25202c3138662520ull,0x6f6d090a3b343866ull,
0x2509203233662e76ull,0x306630202c363866ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3738662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x20696e752e617262ull,0x315f315f744c2409ull,0x4c240a3b34353137ull,
0x313437315f315f74ull,0x636f6c2e090a3a30ull,0x0937393309353109ull,0x662e766f6d090a30ull,
0x3033662509203233ull,0x0a3b33316625202cull,0x353109636f6c2e09ull,0x090a300938393309ull,
0x203233662e766f6dull,0x25202c3738662509ull,0x6c2e090a3b353166ull,0x393309353109636full,
0x766f6d090a300939ull,0x662509203233662eull,0x37326625202c3133ull,0x09636f6c2e090a3bull,
0x3009303034093531ull,0x33662e766f6d090aull,0x2c36386625092032ull,0x090a3b3932662520ull,
0x09353109636f6c2eull,0x6d090a3009383034ull,0x09203233662e766full,0x6630202c35386625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3866250920323366ull,
0x3030306630202c33ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x3233662e766f6d09ull,
0x202c303666250920ull,0x3030303030306630ull,0x09202020203b3030ull,0x6f6d090a30202f2full,
0x2509203233662e76ull,0x306630202c383566ull,0x3b30303030303030ull,0x202f2f0920202020ull,
0x662e766f6d090a30ull,0x3533662509203233ull,0x303030306630202cull,0x2020203b30303030ull,
0x090a30202f2f0920ull,0x203233662e766f6dull,0x30202c3433662509ull,0x3030303030303066ull,
0x2f09202020203b30ull,0x766f6d090a30202full,0x662509203233662eull,0x30306630202c3333ull,
0x203b303030303030ull,0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c32336625092032ull,
0x3030303030663020ull,0x202020203b303030ull,0x4c240a30202f2f09ull,0x353137315f315f74ull,
0x636f6c2e090a3a34ull,0x0932313409353109ull,0x61702e646c090a30ull,0x203233732e6d6172ull,
0x202c393031722509ull,0x70616475635f5f5bull,0x38315a5f5f6d7261ull,0x72626c65646e614dull,
0x6d735f315344746full,0x6168637536503031ull,0x6666666969693472ull,0x69695f5366666666ull,
0x68636e7572635f62ull,0x2e627573090a3b5dull,0x3172250920323373ull,0x30317225202c3031ull,
0x6d090a3b31202c39ull,0x09203233752e766full,0x31202c3131317225ull,0x2e70746573090a3bull,
0x09203233732e7165ull,0x317225202c387025ull,0x31317225202c3930ull,0x38702540090a3b31ull,
0x4c24092061726220ull,0x373138315f315f74ull,0x2e646461090a3b38ull,0x3866250920323366ull,
0x2c33386625202c38ull,0x090a3b3835662520ull,0x203233662e627573ull,0x25202c3938662509ull,
0x386625202c383866ull,0x2e627573090a3b33ull,0x3966250920323366ull,0x2c38386625202c30ull,
0x090a3b3938662520ull,0x203233662e627573ull,0x25202c3139662509ull,0x386625202c383566ull,
0x2e627573090a3b39ull,0x3966250920323366ull,0x2c33386625202c32ull,0x090a3b3039662520ull,
0x203233662e646461ull,0x25202c3339662509ull,0x396625202c313966ull,0x2e646461090a3b32ull,
0x3966250920323366ull,0x2c33396625202c34ull,0x090a3b3538662520ull,0x203233662e646461ull,
0x25202c3539662509ull,0x366625202c343966ull,0x2e646461090a3b30ull,0x3966250920323366ull,
0x2c38386625202c36ull,0x090a3b3539662520ull,0x203233662e627573ull,0x25202c3739662509ull,
0x386625202c363966ull,0x2e627573090a3b38ull,0x3966250920323366ull,0x2c35396625202c38ull,
0x090a3b3739662520ull,0x203233662e646461ull,0x25202c3939662509ull,0x396625202c363966ull,
0x2e766f6d090a3b38ull,0x3166250920323366ull,0x30346630202c3030ull,0x203b303030303038ull,
0x0a34202f2f092020ull,0x746c2e7074657309ull,0x702509203233662eull,0x2c39396625202c39ull,
0x0a3b303031662520ull,0x6220397025214009ull,0x5f744c2409206172ull,0x3b38373138315f31ull,
0x33662e766f6d090aull,0x3130316625092032ull,0x303036346630202cull,0x2020203b30303430ull,
0x33393138202f2f09ull,0x33662e6c756d090aull,0x3230316625092032ull,0x202c34336625202cull,
0x090a3b3130316625ull,0x203233662e766f6dull,0x202c333031662509ull,0x3430303036346630ull,
0x2f092020203b3030ull,0x090a33393138202full,0x203233662e6c756dull,0x202c343031662509ull,
0x6625202c32336625ull,0x7573090a3b333031ull,0x2509203233662e62ull,0x6625202c35303166ull,
0x336625202c323031ull,0x2e627573090a3b34ull,0x3166250920323366ull,0x30316625202c3630ull,
0x3b32336625202c34ull,0x33662e627573090aull,0x3730316625092032ull,0x2c3230316625202cull,
0x0a3b353031662520ull,0x3233662e62757309ull,0x2c38303166250920ull,0x202c343031662520ull,
0x090a3b3630316625ull,0x203233662e627573ull,0x202c393031662509ull,0x6625202c34336625ull,
0x7573090a3b373031ull,0x2509203233662e62ull,0x6625202c30313166ull,0x30316625202c3233ull,
0x5f315f4c240a3b38ull,0x200a3a3835303331ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,
0x20656e696c207964ull,0x6f6c2e090a333134ull,0x3331340935310963ull,0x2e6c756d090a3009ull,
0x3166250920323366ull,0x35336625202c3131ull,0x0a3b32336625202cull,0x3233662e6c756d09ull,
0x2c32313166250920ull,0x25202c3433662520ull,0x616d090a3b323366ull,0x2509203233662e64ull,
0x6625202c33313166ull,0x33336625202c3433ull,0x3b3131316625202cull,0x33662e646461090aull,
0x3431316625092032ull,0x2c3231316625202cull,0x0a3b333131662520ull,0x3233662e62757309ull,
0x2c35313166250920ull,0x202c343131662520ull,0x090a3b3231316625ull,0x203233662e6c756dull,
0x202c363131662509ull,0x25202c3730316625ull,0x73090a3b38303166ull,0x09203233662e6275ull,
0x25202c3731316625ull,0x6625202c36313166ull,0x7573090a3b323131ull,0x2509203233662e62ull,
0x6625202c38313166ull,0x316625202c333131ull,0x627573090a3b3531ull,0x662509203233662eull,
0x316625202c393131ull,0x31316625202c3431ull,0x2e64616d090a3b35ull,0x3166250920323366ull,
0x30316625202c3032ull,0x3031316625202c37ull,0x3b3731316625202cull,0x33662e627573090aull,
0x3132316625092032ull,0x2c3231316625202cull,0x0a3b393131662520ull,0x3233662e64616d09ull,
0x2c32323166250920ull,0x202c383031662520ull,0x25202c3930316625ull,0x61090a3b30323166ull,
0x09203233662e6464ull,0x25202c3332316625ull,0x6625202c38313166ull,0x616d090a3b313231ull,
0x2509203233662e64ull,0x6625202c34323166ull,0x316625202c393031ull,0x32316625202c3031ull,
0x2e646461090a3b32ull,0x3166250920323366ull,0x32316625202c3532ull,0x3432316625202c33ull,
0x662e64616d090a3bull,0x3231662509203233ull,0x2c35336625202c36ull,0x25202c3333662520ull,
0x61090a3b35323166ull,0x09203233662e6464ull,0x25202c3732316625ull,0x6625202c34313166ull,
0x7573090a3b363231ull,0x2509203233662e62ull,0x6625202c38323166ull,0x316625202c373231ull,
0x627573090a3b3431ull,0x662509203233662eull,0x32316625202c3333ull,0x3832316625202c36ull,
0x09636f6c2e090a3bull,0x3009343134093531ull,0x33662e646461090aull,0x3932316625092032ull,
0x2c3732316625202cull,0x0a3b373231662520ull,0x3233662e62757309ull,0x2c30333166250920ull,
0x202c393231662520ull,0x090a3b3732316625ull,0x203233662e627573ull,0x202c313331662509ull,
0x25202c3732316625ull,0x73090a3b30333166ull,0x09203233662e6275ull,0x25202c3233316625ull,
0x6625202c39323166ull,0x7573090a3b303331ull,0x2509203233662e62ull,0x6625202c33333166ull,
0x316625202c373231ull,0x646461090a3b3233ull,0x662509203233662eull,0x316625202c343331ull,
0x33316625202c3133ull,0x2e646461090a3b33ull,0x3166250920323366ull,0x33316625202c3533ull,
0x3b33336625202c34ull,0x33662e646461090aull,0x3633316625092032ull,0x2c3533316625202cull,
0x090a3b3333662520ull,0x203233662e646461ull,0x202c373331662509ull,0x25202c3932316625ull,
0x73090a3b36333166ull,0x09203233662e6275ull,0x25202c3833316625ull,0x6625202c37333166ull,
0x7573090a3b393231ull,0x2509203233662e62ull,0x316625202c333366ull,0x33316625202c3633ull,
0x636f6c2e090a3b38ull,0x0935313409353109ull,0x662e646461090a30ull,0x3331662509203233ull,
0x3733316625202c39ull,0x0a3b31336625202cull,0x3233662e62757309ull,0x2c30343166250920ull,
0x202c393331662520ull,0x090a3b3733316625ull,0x203233662e627573ull,0x202c313431662509ull,
0x25202c3933316625ull,0x73090a3b30343166ull,0x09203233662e6275ull,0x25202c3234316625ull,
0x316625202c313366ull,0x627573090a3b3034ull,0x662509203233662eull,0x316625202c333431ull,
0x34316625202c3733ull,0x2e646461090a3b31ull,0x3166250920323366ull,0x34316625202c3434ull,
0x3334316625202c32ull,0x662e646461090a3bull,0x3431662509203233ull,0x3434316625202c35ull,
0x0a3b33336625202cull,0x3233662e64646109ull,0x2c36343166250920ull,0x202c353431662520ull,
0x61090a3b36386625ull,0x09203233662e6464ull,0x25202c3734316625ull,0x6625202c39333166ull,
0x6f6d090a3b363431ull,0x2509203233662e76ull,0x316625202c323366ull,0x627573090a3b3734ull,
0x662509203233662eull,0x316625202c383431ull,0x33316625202c3734ull,0x2e627573090a3b39ull,
0x3366250920323366ull,0x3634316625202c33ull,0x3b3834316625202cull,0x3109636f6c2e090aull,
0x0a30093831340935ull,0x3233662e62757309ull,0x2c39343166250920ull,0x25202c3338662520ull,
0x7573090a3b383566ull,0x2509203233662e62ull,0x6625202c30353166ull,0x386625202c393431ull,
0x2e627573090a3b33ull,0x3166250920323366ull,0x34316625202c3135ull,0x3035316625202c39ull,
0x662e646461090a3bull,0x3531662509203233ull,0x3035316625202c32ull,0x0a3b38356625202cull,
0x3233662e62757309ull,0x2c33353166250920ull,0x25202c3338662520ull,0x73090a3b31353166ull,
0x09203233662e6275ull,0x25202c3435316625ull,0x6625202c33353166ull,0x6461090a3b323531ull,
0x2509203233662e64ull,0x6625202c35353166ull,0x386625202c343531ull,0x2e627573090a3b35ull,
0x3166250920323366ull,0x35316625202c3635ull,0x3b30366625202c35ull,0x33662e646461090aull,
0x3735316625092032ull,0x2c3934316625202cull,0x0a3b363531662520ull,0x3233662e64646109ull,
0x2c38353166250920ull,0x202c373531662520ull,0x73090a3b30336625ull,0x09203233662e6275ull,
0x25202c3935316625ull,0x6625202c38353166ull,0x7573090a3b373531ull,0x2509203233662e62ull,
0x6625202c30363166ull,0x316625202c383531ull,0x627573090a3b3935ull,0x662509203233662eull,
0x316625202c313631ull,0x36316625202c3735ull,0x2e627573090a3b30ull,0x3166250920323366ull,
0x30336625202c3236ull,0x3b3935316625202cull,0x33662e646461090aull,0x3336316625092032ull,
0x2c3136316625202cull,0x0a3b323631662520ull,0x3233662e62757309ull,0x2c34363166250920ull,
0x202c373531662520ull,0x090a3b3934316625ull,0x203233662e627573ull,0x202c353631662509ull,
0x25202c3635316625ull,0x61090a3b34363166ull,0x09203233662e6464ull,0x25202c3636316625ull,
0x6625202c33363166ull,0x6461090a3b353631ull,0x2509203233662e64ull,0x6625202c37363166ull,
0x36316625202c3738ull,0x2e646461090a3b36ull,0x3166250920323366ull,0x35316625202c3836ull,
0x3736316625202c38ull,0x662e766f6d090a3bull,0x3433662509203233ull,0x3b3836316625202cull,
0x33662e627573090aull,0x3936316625092032ull,0x2c3836316625202cull,0x0a3b383531662520ull,
0x3233662e62757309ull,0x202c353366250920ull,0x25202c3736316625ull,0x2e090a3b39363166ull,
0x3409353109636f6cull,0x6f6d090a30093032ull,0x2509203233662e76ull,0x6630202c30373166ull,
0x3030343030303634ull,0x202f2f092020203bull,0x756d090a33393138ull,0x2509203233662e6cull,
0x6625202c31373166ull,0x316625202c373431ull,0x6c756d090a3b3037ull,0x662509203233662eull,
0x316625202c323731ull,0x33336625202c3734ull,0x662e6c756d090a3bull,0x3731662509203233ull,
0x3734316625202c33ull,0x3b3734316625202cull,0x33662e627573090aull,0x3437316625092032ull,
0x2c3137316625202cull,0x0a3b373431662520ull,0x3233662e64616d09ull,0x2c35373166250920ull,
0x202c373431662520ull,0x6625202c33336625ull,0x7573090a3b323731ull,0x2509203233662e62ull,
0x6625202c38303166ull,0x316625202c313731ull,0x646461090a3b3437ull,0x662509203233662eull,
0x316625202c363731ull,0x37316625202c3337ull,0x2e627573090a3b35ull,0x3166250920323366ull,
0x34316625202c3031ull,0x3830316625202c37ull,0x662e6c756d090a3bull,0x3731662509203233ull,
0x3830316625202c37ull,0x3b3830316625202cull,0x33662e627573090aull,0x3837316625092032ull,
0x2c3737316625202cull,0x0a3b333731662520ull,0x3233662e62757309ull,0x2c39373166250920ull,
0x202c363731662520ull,0x090a3b3337316625ull,0x203233662e64616dull,0x202c303831662509ull,
0x25202c3830316625ull,0x6625202c30313166ull,0x7573090a3b383731ull,0x2509203233662e62ull,
0x6625202c31383166ull,0x316625202c353731ull,0x627573090a3b3937ull,0x662509203233662eull,
0x316625202c323831ull,0x37316625202c3637ull,0x2e64616d090a3b39ull,0x3166250920323366ull,
0x30316625202c3338ull,0x3031316625202c38ull,0x3b3038316625202cull,0x33662e627573090aull,
0x3438316625092032ull,0x2c3337316625202cull,0x0a3b323831662520ull,0x3233662e64616d09ull,
0x2c35383166250920ull,0x202c303131662520ull,0x25202c3031316625ull,0x61090a3b33383166ull,
0x09203233662e6464ull,0x25202c3638316625ull,0x6625202c31383166ull,0x6461090a3b343831ull,
0x2509203233662e64ull,0x6625202c37383166ull,0x316625202c353831ull,0x64616d090a3b3638ull,
0x662509203233662eull,0x336625202c383831ull,0x2c33336625202c33ull,0x0a3b373831662520ull,
0x3233662e64646109ull,0x2c39383166250920ull,0x202c363731662520ull,0x090a3b3838316625ull,
0x203233662e766f6dull,0x25202c3835662509ull,0x73090a3b39383166ull,0x09203233662e6275ull,
0x25202c3039316625ull,0x6625202c39383166ull,0x7573090a3b363731ull,0x2509203233662e62ull,
0x316625202c303666ull,0x39316625202c3838ull,0x636f6c2e090a3b30ull,0x0931323409353109ull,
0x662e766f6d090a30ull,0x3931662509203233ull,0x3036346630202c31ull,0x20203b3030343030ull,
0x393138202f2f0920ull,0x662e6c756d090a33ull,0x3931662509203233ull,0x3836316625202c32ull,
0x3b3139316625202cull,0x33662e6c756d090aull,0x3339316625092032ull,0x2c3836316625202cull,
0x090a3b3533662520ull,0x203233662e6c756dull,0x202c343931662509ull,0x25202c3836316625ull,
0x73090a3b38363166ull,0x09203233662e6275ull,0x25202c3539316625ull,0x6625202c32393166ull,
0x616d090a3b383631ull,0x2509203233662e64ull,0x6625202c36393166ull,0x336625202c383631ull,
0x3339316625202c35ull,0x662e627573090a3bull,0x3031662509203233ull,0x3239316625202c37ull,
0x3b3539316625202cull,0x33662e646461090aull,0x3739316625092032ull,0x2c3439316625202cull,
0x0a3b363931662520ull,0x3233662e62757309ull,0x2c39303166250920ull,0x202c383631662520ull,
0x090a3b3730316625ull,0x203233662e6c756dull,0x202c383931662509ull,0x25202c3730316625ull,
0x73090a3b37303166ull,0x09203233662e6275ull,0x25202c3939316625ull,0x6625202c38393166ull,
0x7573090a3b343931ull,0x2509203233662e62ull,0x6625202c30303266ull,0x316625202c373931ull,
0x64616d090a3b3439ull,0x662509203233662eull,0x316625202c313032ull,0x30316625202c3730ull,
0x3939316625202c39ull,0x662e627573090a3bull,0x3032662509203233ull,0x3639316625202c32ull,
0x3b3030326625202cull,0x33662e627573090aull,0x3330326625092032ull,0x2c3739316625202cull,
0x0a3b303032662520ull,0x3233662e64616d09ull,0x2c34303266250920ull,0x202c373031662520ull,
0x25202c3930316625ull,0x73090a3b31303266ull,0x09203233662e6275ull,0x25202c3530326625ull,
0x6625202c34393166ull,0x616d090a3b333032ull,0x2509203233662e64ull,0x6625202c36303266ull,
0x316625202c393031ull,0x30326625202c3930ull,0x2e646461090a3b34ull,0x3266250920323366ull,
0x30326625202c3730ull,0x3530326625202c32ull,0x662e646461090a3bull,0x3032662509203233ull,
0x3630326625202c38ull,0x3b3730326625202cull,0x33662e64616d090aull,0x3930326625092032ull,
0x202c35336625202cull,0x6625202c35336625ull,0x6461090a3b383032ull,0x2509203233662e64ull,
0x6625202c30313266ull,0x326625202c373931ull,0x766f6d090a3b3930ull,0x662509203233662eull,
0x31326625202c3338ull,0x2e627573090a3b30ull,0x3266250920323366ull,0x31326625202c3131ull,
0x3739316625202c30ull,0x662e627573090a3bull,0x3538662509203233ull,0x2c3930326625202cull,
0x0a3b313132662520ull,0x353109636f6c2e09ull,0x090a300932323409ull,0x203233662e646461ull,
0x202c323132662509ull,0x25202c3938316625ull,0x73090a3b30313266ull,0x09203233662e6275ull,
0x25202c3331326625ull,0x6625202c32313266ull,0x7573090a3b303132ull,0x2509203233662e62ull,
0x6625202c34313266ull,0x326625202c393831ull,0x627573090a3b3331ull,0x662509203233662eull,
0x326625202c353132ull,0x31326625202c3231ull,0x2e627573090a3b33ull,0x3266250920323366ull,
0x31326625202c3631ull,0x3531326625202c30ull,0x662e646461090a3bull,0x3132662509203233ull,
0x3431326625202c37ull,0x3b3631326625202cull,0x33662e646461090aull,0x3831326625092032ull,
0x202c35386625202cull,0x090a3b3731326625ull,0x203233662e646461ull,0x202c393132662509ull,
0x6625202c30366625ull,0x6461090a3b383132ull,0x2509203233662e64ull,0x6625202c33313266ull,
0x326625202c323132ull,0x627573090a3b3931ull,0x662509203233662eull,0x326625202c303232ull,
0x31326625202c3331ull,0x2e627573090a3b32ull,0x3266250920323366ull,0x31326625202c3132ull,
0x3032326625202c39ull,0x09636f6c2e090a3bull,0x3009323134093531ull,0x33732e627573090aull,
0x3031317225092032ull,0x2c3031317225202cull,0x766f6d090a3b3120ull,0x722509203233752eull,
0x0a3b30202c323131ull,0x71652e7074657309ull,0x702509203233732eull,0x31317225202c3031ull,
0x3231317225202c30ull,0x3031702540090a3bull,0x4c24092061726220ull,0x373138315f315f74ull,
0x6c3c2f2f200a3b38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c33313420656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x38353033315f315full,
0x33662e646461090aull,0x3232326625092032ull,0x2c3132326625202cull,0x0a3b333132662520ull,
0x3233662e766f6d09ull,0x2c33323266250920ull,0x3030383034663020ull,0x092020203b303030ull,
0x6573090a34202f2full,0x33662e746c2e7074ull,0x2c31317025092032ull,0x202c323232662520ull,
0x090a3b3332326625ull,0x7262203131702540ull,0x5f315f4c24092061ull,0x240a3b3835303331ull,
0x3138315f315f744cull,0x315f4c240a3a3837ull,0x0a3a34313333315full,0x363109636f6c2e09ull,
0x090a300931393109ull,0x203233732e766f6dull,0x202c333131722509ull,0x70746573090a3b30ull,
0x203233732e74672eull,0x25202c3231702509ull,0x7225202c30313172ull,0x7573090a3b333131ull,
0x2509203233732e62ull,0x7225202c34313172ull,0x317225202c393031ull,0x766f6d090a3b3031ull,
0x722509203233732eull,0x0a3b30202c353131ull,0x33732e706c657309ull,0x3631317225092032ull,
0x2c3431317225202cull,0x202c353131722520ull,0x6d090a3b32317025ull,0x09203233752e766full,
0x30202c3731317225ull,0x2e70746573090a3bull,0x09203233732e7165ull,0x7225202c33317025ull,
0x317225202c363131ull,0x702540090a3b3731ull,0x0920617262203331ull,0x37315f315f744c24ull,
0x6c2e090a3b323239ull,0x393109363109636full,0x2e646c090a300938ull,0x33732e6d61726170ull,
0x3831317225092032ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3831ull,
0x5f315344746f7262ull,0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,
0x6d696e615f626969ull,0x6172466e6f697461ull,0x6461090a3b5d656dull,0x2509203233732e64ull,
0x7225202c39313172ull,0x317225202c383131ull,0x2e646c090a3b3631ull,0x38752e6d61726170ull,
0x2c30323172250920ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d38ull,
0x735f315344746f72ull,0x686375365030316dull,0x6666696969347261ull,0x695f536666666666ull,
0x726f6c6f635f6269ull,0x6d090a3b5d302b73ull,0x33732e6f6c2e6c75ull,0x3132317225092032ull,
0x2c3931317225202cull,0x0a3b303231722520ull,0x2e38752e74766309ull,0x3172250920323375ull,
0x32317225202c3232ull,0x636f6c2e090a3b31ull,0x0939393109363109ull,0x61702e646c090a30ull,
0x092038752e6d6172ull,0x5b202c3332317225ull,0x6170616475635f5full,0x4d38315a5f5f6d72ull,
0x6f72626c65646e61ull,0x316d735f31534474ull,0x7261686375365030ull,0x6666666669696934ull,
0x6269695f53666666ull,0x2b73726f6c6f635full,0x6c756d090a3b5d31ull,0x203233732e6f6c2eull,
0x202c343231722509ull,0x25202c3931317225ull,0x63090a3b33323172ull,0x33752e38752e7476ull,
0x3532317225092032ull,0x3b3432317225202cull,0x3109636f6c2e090aull,0x0a30093030320936ull,
0x617261702e646c09ull,0x7225092038752e6dull,0x5f5f5b202c363231ull,0x6d72617061647563ull,
0x6e614d38315a5f5full,0x44746f72626c6564ull,0x5030316d735f3153ull,0x6934726168637536ull,
0x6666666666666969ull,0x635f6269695f5366ull,0x5d322b73726f6c6full,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c37323172ull,0x317225202c393131ull,0x747663090a3b3632ull,
0x203233752e38752eull,0x202c383231722509ull,0x090a3b3732317225ull,0x20696e752e617262ull,
0x315f315f744c2409ull,0x4c240a3b36363637ull,0x323937315f315f74ull,0x636f6c2e090a3a32ull,
0x0934303209363109ull,0x752e766f6d090a30ull,0x3231722509203233ull,0x6d090a3b30202c38ull,
0x09203233752e766full,0x30202c3532317225ull,0x752e766f6d090a3bull,0x3231722509203233ull,
0x4c240a3b30202c32ull,0x363637315f315f74ull,0x636f6c2e090a3a36ull,0x0930313209363109ull,
0x61702e646c090a30ull,0x203233732e6d6172ull,0x202c393231722509ull,0x70616475635f5f5bull,
0x38315a5f5f6d7261ull,0x72626c65646e614dull,0x6d735f315344746full,0x6168637536503031ull,
0x6666666969693472ull,0x69695f5366666666ull,0x5d656d6172665f62ull,0x732e646461090a3bull,
0x3331722509203233ull,0x3932317225202c30ull,0x6873090a3b31202cull,0x2509203233732e72ull,
0x7225202c31333172ull,0x3b3133202c303331ull,0x33732e766f6d090aull,0x3233317225092032ull,
0x6e61090a3b31202cull,0x2509203233622e64ull,0x7225202c33333172ull,0x317225202c313331ull,
0x646461090a3b3233ull,0x722509203233732eull,0x317225202c343331ull,0x33317225202c3333ull,
0x2e726873090a3b30ull,0x3172250920323373ull,0x33317225202c3533ull,0x6d090a3b31202c34ull,
0x33732e6f6c2e6c75ull,0x3633317225092032ull,0x2c3932317225202cull,0x090a3b3731722520ull,
0x203233732e646461ull,0x202c373331722509ull,0x25202c3232317225ull,0x61090a3b36333172ull,
0x09203233732e6464ull,0x25202c3833317225ull,0x7225202c35333172ull,0x6964090a3b373331ull,
0x2509203233732e76ull,0x7225202c39333172ull,0x317225202c383331ull,0x6f6c2e090a3b3033ull,
0x3131320936310963ull,0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x25202c3034317225ull,
0x7225202c39323172ull,0x646461090a3b3831ull,0x722509203233732eull,0x317225202c313431ull,
0x34317225202c3532ull,0x2e646461090a3b30ull,0x3172250920323373ull,0x33317225202c3234ull,
0x3134317225202c35ull,0x732e766964090a3bull,0x3431722509203233ull,0x3234317225202c33ull,
0x3b3033317225202cull,0x6f6c672e7473090aull,0x752e32762e6c6162ull,0x346472255b092038ull,
0x72257b202c5d302bull,0x343172252c393331ull,0x6f6c2e090a3b7d33ull,0x3231320936310963ull,
0x2e6c756d090a3009ull,0x09203233732e6f6cull,0x25202c3434317225ull,0x7225202c39323172ull,
0x646461090a3b3931ull,0x722509203233732eull,0x317225202c353431ull,0x34317225202c3832ull,
0x2e646461090a3b34ull,0x3172250920323373ull,0x33317225202c3634ull,0x3534317225202c35ull,
0x732e766964090a3bull,0x3431722509203233ull,0x3634317225202c37ull,0x3b3033317225202cull,
0x6f6c672e7473090aull,0x092038752e6c6162ull,0x5d322b346472255bull,0x3b3734317225202cull,
0x315f315f744c240aull,0x4c240a3a32343636ull,0x383034315f315f74ull,0x636f6c2e090a3a32ull,
0x0935313209363109ull,0x3b74697865090a30ull,0x646e6557444c240aull,0x6e614d38315a5f5full,
0x44746f72626c6564ull,0x5030316d735f3153ull,0x6934726168637536ull,0x6666666666666969ull,
0x0a3a6269695f5366ull,0x5a5f202f2f207d09ull,0x6c65646e614d3831ull,0x5f315344746f7262ull,
0x6375365030316d73ull,0x6669696934726168ull,0x5f53666666666666ull,0x652e090a0a626969ull,
0x315a5f207972746eull,0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645664930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x30535f32535f3253ull,0x090a28206269695full,
0x206d617261702e09ull,0x635f5f203436752eull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f30746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x32535f32535f3253ull,0x5f6269695f30535full,0x2e09090a2c747364ull,0x732e206d61726170ull,
0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,
0x6d695f6269695f30ull,0x09090a2c57656761ull,0x2e206d617261702eull,0x75635f5f20323373ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,0x695f6269695f3053ull,
0x090a2c486567616dull,0x206d617261702e09ull,0x635f5f203233732eull,0x5f6d726170616475ull,
0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x32535f32535f3253ull,0x5f6269695f30535full,0x0a2c68636e757263ull,
0x6d617261702e0909ull,0x5f5f203233662e20ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x30746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x535f32535f32535full,0x6269695f30535f32ull,0x090a2c66664f785full,0x206d617261702e09ull,
0x635f5f203233662eull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x5f6269695f30535full,0x09090a2c66664f79ull,0x2e206d617261702eull,0x75635f5f20323366ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,0x785f6269695f3053ull,
0x702e09090a2c504aull,0x33662e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x30535f32535f3253ull,0x504a795f6269695full,0x7261702e09090a2cull,
0x203233662e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3074ull,0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,
0x695f30535f32535full,0x656c6163735f6269ull,0x7261702e09090a2cull,0x67696c612e206d61ull,
0x2038622e2034206eull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3074ull,0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,
0x695f30535f32535full,0x726f6c6f635f6269ull,0x09090a2c5d345b73ull,0x2e206d617261702eull,
0x75635f5f20323373ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,
0x665f6269695f3053ull,0x09090a2c656d6172ull,0x2e206d617261702eull,0x75635f5f20323373ull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,0x615f6269695f3053ull,
0x6e6f6974616d696eull,0x090a2c656d617246ull,0x206d617261702e09ull,0x75635f5f2038732eull,
0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,0x507645664930316dull,
0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,0x695f6269695f3053ull,
0x090a7b090a294a73ull,0x31752e206765722eull,0x3e363c6872252036ull,0x206765722e090a3bull,
0x3c7225203233752eull,0x2e090a3b3e313031ull,0x3436752e20676572ull,0x3b3e363c64722520ull,
0x2e206765722e090aull,0x313c662520323366ull,0x722e090a3b3e3631ull,0x646572702e206765ull,
0x3b3e36343c702520ull,0x3109636f6c2e090aull,0x240a300930310936ull,0x315a5f5f3142424cull,
0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x30535f32535f3253ull,0x6d090a3a6269695full,0x09203631752e766full,
0x6325202c31687225ull,0x0a3b782e64696174ull,0x3631752e766f6d09ull,0x202c326872250920ull,
0x3b782e6469746e25ull,0x69772e6c756d090aull,0x09203631752e6564ull,0x687225202c317225ull,
0x3b32687225202c31ull,0x31752e766f6d090aull,0x2c33687225092036ull,0x2e64696174632520ull,
0x2e766f6d090a3b79ull,0x6872250920363175ull,0x6469746e25202c34ull,0x6c756d090a3b792eull,
0x31752e656469772eull,0x202c327225092036ull,0x7225202c33687225ull,0x747663090a3b3468ull,
0x3631752e3233752eull,0x25202c3372250920ull,0x090a3b782e646974ull,0x203233752e646461ull,
0x7225202c34722509ull,0x0a3b317225202c33ull,0x3233752e74766309ull,0x722509203631752eull,
0x2e64697425202c35ull,0x2e646461090a3b79ull,0x3672250920323375ull,0x25202c357225202cull,
0x2e646c090a3b3272ull,0x33732e6d61726170ull,0x202c377225092032ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x67616d695f626969ull,
0x646c090a3b5d5765ull,0x732e6d617261702eull,0x2c38722509203233ull,0x616475635f5f5b20ull,
0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645664930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x30535f32535f3253ull,0x616d695f6269695full,
0x73090a3b5d486567ull,0x33752e74672e7465ull,0x2509203233732e32ull,0x2c387225202c3972ull,
0x6e090a3b36722520ull,0x09203233732e6765ull,0x7225202c30317225ull,0x2e746573090a3b39ull,
0x732e3233752e7467ull,0x3131722509203233ull,0x25202c377225202cull,0x67656e090a3b3472ull,
0x722509203233732eull,0x31317225202c3231ull,0x622e646e61090a3bull,0x3331722509203233ull,
0x202c30317225202cull,0x6d090a3b32317225ull,0x09203233752e766full,0x3b30202c34317225ull,
0x652e70746573090aull,0x2509203233732e71ull,0x33317225202c3170ull,0x0a3b34317225202cull,
0x7262203170254009ull,0x325f744c24092061ull,0x0a3b34353336335full,0x353109636f6c2e09ull,
0x090a300931333109ull,0x6d617261702e646cull,0x722509203233732eull,0x635f5f5b202c3531ull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645664930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,0x5f6269695f30535full,
0x3b5d68636e757263ull,0x33732e766f6d090aull,0x2c36317225092032ull,0x090a3b3531722520ull,
0x662e6e722e747663ull,0x09203233732e3233ull,0x347225202c316625ull,0x722e747663090a3bull,
0x33732e3233662e6eull,0x202c326625092032ull,0x646c090a3b367225ull,0x662e6d617261702eull,
0x2c33662509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x30535f32535f3253ull,0x6163735f6269695full,0x646c090a3b5d656cull,0x662e6d617261702eull,
0x2c34662509203233ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x30535f32535f3253ull,0x664f785f6269695full,0x64616d090a3b5d66ull,0x662509203233662eull,
0x202c316625202c35ull,0x346625202c336625ull,0x61702e646c090a3bull,0x203233662e6d6172ull,
0x5f5b202c36662509ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,
0x69695f30535f3253ull,0x3b5d66664f795f62ull,0x33662e64616d090aull,0x202c376625092032ull,
0x336625202c326625ull,0x090a3b366625202cull,0x6d617261702e646cull,0x317225092038732eull,
0x75635f5f5b202c37ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,
0x695f6269695f3053ull,0x6f6d090a3b5d4a73ull,0x2509203233752e76ull,0x0a3b30202c383172ull,
0x71652e7074657309ull,0x702509203233732eull,0x2c37317225202c32ull,0x090a3b3831722520ull,
0x6172622032702540ull,0x5f325f744c240920ull,0x090a3b3232313733ull,0x09353109636f6c2eull,
0x6c090a3009363331ull,0x2e6d617261702e64ull,0x3866250920323366ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764566493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x4a785f6269695f30ull,
0x6f6c2e090a3b5d50ull,0x3733310935310963ull,0x702e646c090a3009ull,0x3233662e6d617261ull,
0x5b202c3966250920ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3074ull,0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,
0x695f30535f32535full,0x3b5d504a795f6269ull,0x3109636f6c2e090aull,0x0a30093833310935ull,
0x3233662e766f6d09ull,0x202c303166250920ull,0x6c2e090a3b376625ull,0x333109353109636full,
0x766f6d090a300939ull,0x662509203233662eull,0x3b356625202c3131ull,0x3109636f6c2e090aull,
0x0a30093034310935ull,0x3233662e6c756d09ull,0x202c323166250920ull,0x376625202c376625ull,
0x09636f6c2e090a3bull,0x3009313431093531ull,0x33662e6c756d090aull,0x2c33316625092032ull,
0x6625202c35662520ull,0x2e617262090a3b35ull,0x744c240920696e75ull,0x36363836335f325full,
0x5f325f744c240a3bull,0x090a3a3232313733ull,0x09353109636f6c2eull,0x6d090a3009353431ull,
0x09203233662e766full,0x356625202c386625ull,0x09636f6c2e090a3bull,0x3009363431093531ull,
0x33662e766f6d090aull,0x202c396625092032ull,0x6c2e090a3b376625ull,0x353109353109636full,
0x766f6d090a300930ull,0x662509203233662eull,0x30306630202c3331ull,0x203b303030303030ull,
0x30202f2f09202020ull,0x33662e766f6d090aull,0x2c32316625092032ull,0x3030303030663020ull,
0x202020203b303030ull,0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c31316625ull,
0x3030303030303030ull,0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3166250920323366ull,
0x3030306630202c30ull,0x20203b3030303030ull,0x0a30202f2f092020ull,0x36335f325f744c24ull,
0x6f6d090a3a363638ull,0x2509203233732e76ull,0x0a3b30202c393172ull,0x656c2e7074657309ull,
0x702509203233732eull,0x2c35317225202c33ull,0x240a3b3931722520ull,0x3939315f325f744cull,
0x3c2f2f200a3a3037ull,0x6f4c203e706f6f6cull,0x2079646f6220706full,0x35353120656e696cull,
0x3109636f6c2e090aull,0x0a30093535310935ull,0x7262203370254009ull,0x5f325f4c24092061ull,
0x200a3b3037333632ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x61090a3037393931ull,0x09203233662e6464ull,0x6625202c34316625ull,0x32316625202c3331ull,
0x662e766f6d090a3bull,0x3531662509203233ull,0x303830346630202cull,0x2020203b30303030ull,
0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3470250920323366ull,0x202c34316625202cull,
0x40090a3b35316625ull,0x6172622034702521ull,0x325f325f4c240920ull,0x4c240a3b34313136ull,
0x30373336325f325full,0x732e766f6d090a3aull,0x3032722509203233ull,0x0a3b36317225202cull,
0x696e752e61726209ull,0x5f325f744c240920ull,0x5f4c240a3b383532ull,0x3a34313136325f32ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a30373939315f32ull,
0x353109636f6c2e09ull,0x090a300937353109ull,0x203233662e6c756dull,0x25202c3631662509ull,
0x316625202c313166ull,0x2e646461090a3b30ull,0x3166250920323366ull,0x2c36316625202c37ull,
0x090a3b3631662520ull,0x203233662e646461ull,0x25202c3031662509ull,0x37316625202c3966ull,
0x09636f6c2e090a3bull,0x3009383531093531ull,0x33662e627573090aull,0x2c38316625092032ull,
0x25202c3331662520ull,0x6461090a3b323166ull,0x2509203233662e64ull,0x386625202c313166ull,
0x0a3b38316625202cull,0x353109636f6c2e09ull,0x090a300939353109ull,0x203233662e6c756dull,
0x25202c3931662509ull,0x316625202c303166ull,0x636f6c2e090a3b30ull,0x0937353109353109ull,
0x732e627573090a30ull,0x3132722509203233ull,0x202c36317225202cull,0x2e766f6d090a3b31ull,
0x3272250920323375ull,0x73090a3b30202c32ull,0x732e656c2e707465ull,0x2c35702509203233ull,
0x25202c3132722520ull,0x2540090a3b323272ull,0x0920617262203570ull,0x3836325f325f4c24ull,
0x3c2f2f200a3b3238ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3939315f325f744cull,
0x2e6c756d090a3037ull,0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,
0x203233662e646461ull,0x25202c3132662509ull,0x316625202c303266ull,0x2e766f6d090a3b39ull,
0x3266250920323366ull,0x3830346630202c32ull,0x20203b3030303030ull,0x0a34202f2f092020ull,
0x74672e7074657309ull,0x702509203233662eull,0x2c31326625202c36ull,0x090a3b3232662520ull,
0x7262203670252140ull,0x5f325f4c24092061ull,0x240a3b3632363632ull,0x383836325f325f4cull,
0x2e766f6d090a3a32ull,0x3272250920323373ull,0x3b31327225202c30ull,0x6e752e617262090aull,
0x325f744c24092069ull,0x4c240a3b3835325full,0x36323636325f325full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f325full,0x3109636f6c2e090aull,
0x0a30093636310935ull,0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,
0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3332ull,0x0a3b36316625202cull,
0x3233662e64646109ull,0x202c303166250920ull,0x326625202c396625ull,0x636f6c2e090a3b33ull,
0x0937363109353109ull,0x662e627573090a30ull,0x3432662509203233ull,0x202c30326625202cull,
0x61090a3b39316625ull,0x09203233662e6464ull,0x6625202c31316625ull,0x3b34326625202c38ull,
0x3109636f6c2e090aull,0x0a30093836310935ull,0x3233662e6c756d09ull,0x202c353266250920ull,
0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3636310935310963ull,0x2e627573090a3009ull,
0x3272250920323373ull,0x2c36317225202c33ull,0x766f6d090a3b3220ull,0x722509203233752eull,
0x090a3b30202c3432ull,0x2e656c2e70746573ull,0x3770250920323373ull,0x202c33327225202cull,
0x40090a3b34327225ull,0x2061726220377025ull,0x37325f325f4c2409ull,0x2f2f200a3b343933ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x39315f325f744c24ull,0x6c756d090a303739ull,
0x662509203233662eull,0x31316625202c3032ull,0x0a3b31316625202cull,0x3233662e64646109ull,
0x202c363266250920ull,0x6625202c30326625ull,0x766f6d090a3b3532ull,0x662509203233662eull,
0x30346630202c3732ull,0x203b303030303038ull,0x34202f2f09202020ull,0x672e70746573090aull,
0x2509203233662e74ull,0x36326625202c3870ull,0x0a3b37326625202cull,0x6220387025214009ull,
0x325f4c2409206172ull,0x0a3b38333137325full,0x3337325f325f4c24ull,0x766f6d090a3a3439ull,
0x722509203233732eull,0x33327225202c3032ull,0x752e617262090a3bull,0x5f744c240920696eull,
0x240a3b3835325f32ull,0x333137325f325f4cull,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x373939315f325f74ull,0x09636f6c2e090a30ull,0x3009353731093531ull,
0x33662e6c756d090aull,0x2c36316625092032ull,0x25202c3131662520ull,0x6461090a3b303166ull,
0x2509203233662e64ull,0x316625202c383266ull,0x3b36316625202c36ull,0x33662e646461090aull,
0x2c30316625092032ull,0x6625202c39662520ull,0x6f6c2e090a3b3832ull,0x3637310935310963ull,
0x2e627573090a3009ull,0x3266250920323366ull,0x2c30326625202c39ull,0x090a3b3532662520ull,
0x203233662e646461ull,0x25202c3131662509ull,0x39326625202c3866ull,0x09636f6c2e090a3bull,
0x3009373731093531ull,0x33662e6c756d090aull,0x2c30336625092032ull,0x25202c3031662520ull,
0x6c2e090a3b303166ull,0x373109353109636full,0x627573090a300935ull,0x722509203233732eull,
0x36317225202c3532ull,0x6f6d090a3b33202cull,0x2509203233752e76ull,0x0a3b30202c363272ull,
0x656c2e7074657309ull,0x702509203233732eull,0x2c35327225202c39ull,0x090a3b3632722520ull,
0x6172622039702540ull,0x325f325f4c240920ull,0x2f200a3b36303937ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x315f325f744c2420ull,0x756d090a30373939ull,0x2509203233662e6cull,
0x316625202c303266ull,0x3b31316625202c31ull,0x33662e646461090aull,0x2c31336625092032ull,
0x25202c3032662520ull,0x6f6d090a3b303366ull,0x2509203233662e76ull,0x346630202c323366ull,
0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,0x09203233662e7467ull,
0x6625202c30317025ull,0x32336625202c3133ull,0x3170252140090a3bull,0x2409206172622030ull,
0x353637325f325f4cull,0x5f325f4c240a3b30ull,0x090a3a3630393732ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b353272ull,0x240920696e752e61ull,0x3835325f325f744cull,
0x325f325f4c240a3bull,0x2f200a3a30353637ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f325f744c2420ull,0x6c2e090a30373939ull,0x383109353109636full,0x6c756d090a300934ull,
0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,0x3233662e64646109ull,
0x202c333366250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,0x662509203233662eull,
0x2c396625202c3031ull,0x090a3b3333662520ull,0x09353109636f6c2eull,0x73090a3009353831ull,
0x09203233662e6275ull,0x6625202c34336625ull,0x30336625202c3032ull,0x662e646461090a3bull,
0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b343366ull,0x383109353109636full,
0x6c756d090a300936ull,0x662509203233662eull,0x30316625202c3533ull,0x0a3b30316625202cull,
0x353109636f6c2e09ull,0x090a300934383109ull,0x203233732e627573ull,0x25202c3732722509ull,
0x0a3b34202c363172ull,0x3233752e766f6d09ull,0x202c383272250920ull,0x70746573090a3b30ull,
0x203233732e656c2eull,0x25202c3131702509ull,0x327225202c373272ull,0x31702540090a3b38ull,
0x2409206172622031ull,0x313438325f325f4cull,0x6c3c2f2f200a3b38ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x373939315f325f74ull,0x662e6c756d090a30ull,0x3032662509203233ull,
0x202c31316625202cull,0x61090a3b31316625ull,0x09203233662e6464ull,0x6625202c36336625ull,
0x35336625202c3032ull,0x662e766f6d090a3bull,0x3733662509203233ull,0x303830346630202cull,
0x2020203b30303030ull,0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3170250920323366ull,
0x2c36336625202c32ull,0x090a3b3733662520ull,0x6220323170252140ull,0x325f4c2409206172ull,
0x0a3b32363138325full,0x3438325f325f4c24ull,0x766f6d090a3a3831ull,0x722509203233732eull,
0x37327225202c3032ull,0x752e617262090a3bull,0x5f744c240920696eull,0x240a3b3835325f32ull,
0x363138325f325f4cull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x373939315f325f74ull,0x09636f6c2e090a30ull,0x3009333931093531ull,0x33662e6c756d090aull,
0x2c36316625092032ull,0x25202c3131662520ull,0x6461090a3b303166ull,0x2509203233662e64ull,
0x316625202c383366ull,0x3b36316625202c36ull,0x33662e646461090aull,0x2c30316625092032ull,
0x6625202c39662520ull,0x6f6c2e090a3b3833ull,0x3439310935310963ull,0x2e627573090a3009ull,
0x3366250920323366ull,0x2c30326625202c39ull,0x090a3b3533662520ull,0x203233662e646461ull,
0x25202c3131662509ull,0x39336625202c3866ull,0x09636f6c2e090a3bull,0x3009353931093531ull,
0x33662e6c756d090aull,0x2c30346625092032ull,0x25202c3031662520ull,0x6c2e090a3b303166ull,
0x393109353109636full,0x627573090a300933ull,0x722509203233732eull,0x36317225202c3932ull,
0x6f6d090a3b35202cull,0x2509203233752e76ull,0x0a3b30202c303372ull,0x656c2e7074657309ull,
0x702509203233732eull,0x39327225202c3331ull,0x0a3b30337225202cull,0x6220333170254009ull,
0x325f4c2409206172ull,0x0a3b30333938325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a30373939315full,0x203233662e6c756dull,0x25202c3032662509ull,
0x316625202c313166ull,0x2e646461090a3b31ull,0x3466250920323366ull,0x2c30326625202c31ull,
0x090a3b3034662520ull,0x203233662e766f6dull,0x30202c3234662509ull,0x3030303038303466ull,
0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,0x202c343170250920ull,
0x6625202c31346625ull,0x252140090a3b3234ull,0x2061726220343170ull,0x38325f325f4c2409ull,
0x5f4c240a3b343736ull,0x3a30333938325f32ull,0x33732e766f6d090aull,0x2c30327225092032ull,
0x090a3b3932722520ull,0x20696e752e617262ull,0x325f325f744c2409ull,0x325f4c240a3b3835ull,
0x0a3a34373638325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,0x325f744c24206465ull,
0x090a30373939315full,0x09353109636f6c2eull,0x6d090a3009323032ull,0x09203233662e6c75ull,
0x6625202c36316625ull,0x30316625202c3131ull,0x662e646461090a3bull,0x3334662509203233ull,
0x202c36316625202cull,0x61090a3b36316625ull,0x09203233662e6464ull,0x6625202c30316625ull,
0x3b33346625202c39ull,0x3109636f6c2e090aull,0x0a30093330320935ull,0x3233662e62757309ull,
0x202c343466250920ull,0x6625202c30326625ull,0x646461090a3b3034ull,0x662509203233662eull,
0x2c386625202c3131ull,0x090a3b3434662520ull,0x09353109636f6c2eull,0x6d090a3009343032ull,
0x09203233662e6c75ull,0x6625202c35346625ull,0x30316625202c3031ull,0x09636f6c2e090a3bull,
0x3009323032093531ull,0x33732e627573090aull,0x2c31337225092032ull,0x36202c3631722520ull,
0x752e766f6d090a3bull,0x3233722509203233ull,0x6573090a3b30202cull,0x33732e656c2e7074ull,
0x2c35317025092032ull,0x25202c3133722520ull,0x2540090a3b323372ull,0x2061726220353170ull,
0x39325f325f4c2409ull,0x2f2f200a3b323434ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,
0x39315f325f744c24ull,0x6c756d090a303739ull,0x662509203233662eull,0x31316625202c3032ull,
0x0a3b31316625202cull,0x3233662e64646109ull,0x202c363466250920ull,0x6625202c30326625ull,
0x766f6d090a3b3534ull,0x662509203233662eull,0x30346630202c3734ull,0x203b303030303038ull,
0x34202f2f09202020ull,0x672e70746573090aull,0x2509203233662e74ull,0x346625202c363170ull,
0x3b37346625202c36ull,0x363170252140090aull,0x4c24092061726220ull,0x36383139325f325full,
0x325f325f4c240a3bull,0x6d090a3a32343439ull,0x09203233732e766full,0x7225202c30327225ull,
0x617262090a3b3133ull,0x4c240920696e752eull,0x3b3835325f325f74ull,0x39325f325f4c240aull,
0x2f2f200a3a363831ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,0x39315f325f744c24ull,
0x6f6c2e090a303739ull,0x3131320935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,
0x2c31316625202c36ull,0x090a3b3031662520ull,0x203233662e646461ull,0x25202c3834662509ull,
0x316625202c363166ull,0x2e646461090a3b36ull,0x3166250920323366ull,0x202c396625202c30ull,
0x2e090a3b38346625ull,0x3209353109636f6cull,0x7573090a30093231ull,0x2509203233662e62ull,
0x326625202c393466ull,0x3b35346625202c30ull,0x33662e646461090aull,0x2c31316625092032ull,
0x6625202c38662520ull,0x6f6c2e090a3b3934ull,0x3331320935310963ull,0x2e6c756d090a3009ull,
0x3566250920323366ull,0x2c30316625202c30ull,0x090a3b3031662520ull,0x09353109636f6c2eull,
0x73090a3009313132ull,0x09203233732e6275ull,0x7225202c33337225ull,0x090a3b37202c3631ull,
0x203233752e766f6dull,0x30202c3433722509ull,0x2e70746573090a3bull,0x09203233732e656cull,
0x7225202c37317025ull,0x34337225202c3333ull,0x3731702540090a3bull,0x4c24092061726220ull,
0x34353939325f325full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x30373939315f325full,0x33662e6c756d090aull,0x2c30326625092032ull,0x25202c3131662520ull,
0x6461090a3b313166ull,0x2509203233662e64ull,0x326625202c313566ull,0x3b30356625202c30ull,
0x33662e766f6d090aull,0x2c32356625092032ull,0x3030383034663020ull,0x202020203b303030ull,
0x73090a34202f2f09ull,0x662e74672e707465ull,0x3831702509203233ull,0x202c31356625202cull,
0x40090a3b32356625ull,0x7262203831702521ull,0x5f325f4c24092061ull,0x240a3b3839363932ull,
0x353939325f325f4cull,0x2e766f6d090a3a34ull,0x3272250920323373ull,0x3b33337225202c30ull,
0x6e752e617262090aull,0x325f744c24092069ull,0x4c240a3b3835325full,0x38393639325f325full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f325full,
0x3109636f6c2e090aull,0x0a30093032320935ull,0x3233662e6c756d09ull,0x202c363166250920ull,
0x6625202c31316625ull,0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3335ull,
0x0a3b36316625202cull,0x3233662e64646109ull,0x202c303166250920ull,0x356625202c396625ull,
0x636f6c2e090a3b33ull,0x0931323209353109ull,0x662e627573090a30ull,0x3435662509203233ull,
0x202c30326625202cull,0x61090a3b30356625ull,0x09203233662e6464ull,0x6625202c31316625ull,
0x3b34356625202c38ull,0x3109636f6c2e090aull,0x0a30093232320935ull,0x3233662e6c756d09ull,
0x202c353566250920ull,0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3032320935310963ull,
0x2e627573090a3009ull,0x3372250920323373ull,0x2c36317225202c35ull,0x766f6d090a3b3820ull,
0x722509203233752eull,0x090a3b30202c3633ull,0x2e656c2e70746573ull,0x3170250920323373ull,
0x2c35337225202c39ull,0x090a3b3633722520ull,0x7262203931702540ull,0x5f325f4c24092061ull,
0x200a3b3636343033ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,0x5f325f744c242064ull,
0x6d090a3037393931ull,0x09203233662e6c75ull,0x6625202c30326625ull,0x31316625202c3131ull,
0x662e646461090a3bull,0x3635662509203233ull,0x202c30326625202cull,0x6d090a3b35356625ull,
0x09203233662e766full,0x6630202c37356625ull,0x3030303030383034ull,0x2f2f09202020203bull,
0x70746573090a3420ull,0x203233662e74672eull,0x25202c3032702509ull,0x356625202c363566ull,
0x70252140090a3b37ull,0x0920617262203032ull,0x3230335f325f4c24ull,0x325f4c240a3b3031ull,
0x0a3a36363430335full,0x3233732e766f6d09ull,0x202c303272250920ull,0x62090a3b35337225ull,
0x0920696e752e6172ull,0x35325f325f744c24ull,0x5f325f4c240a3b38ull,0x200a3a3031323033ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353531ull,0x656c6562616c2064ull,0x5f325f744c242064ull,0x2e090a3037393931ull,
0x3209353109636f6cull,0x756d090a30093932ull,0x2509203233662e6cull,0x316625202c363166ull,
0x3b30316625202c31ull,0x33662e646461090aull,0x2c38356625092032ull,0x25202c3631662520ull,
0x6461090a3b363166ull,0x2509203233662e64ull,0x396625202c303166ull,0x0a3b38356625202cull,
0x353109636f6c2e09ull,0x090a300930333209ull,0x203233662e627573ull,0x25202c3935662509ull,
0x356625202c303266ull,0x2e646461090a3b35ull,0x3166250920323366ull,0x202c386625202c31ull,
0x2e090a3b39356625ull,0x3209353109636f6cull,0x756d090a30093133ull,0x2509203233662e6cull,
0x316625202c303666ull,0x3b30316625202c30ull,0x3109636f6c2e090aull,0x0a30093932320935ull,
0x3233732e62757309ull,0x202c373372250920ull,0x3b39202c36317225ull,0x33752e766f6d090aull,
0x2c38337225092032ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c313270250920ull,
0x7225202c37337225ull,0x702540090a3b3833ull,0x0920617262203132ull,0x3930335f325f4c24ull,
0x3c2f2f200a3b3837ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3939315f325f744cull,
0x2e6c756d090a3037ull,0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,
0x203233662e646461ull,0x25202c3136662509ull,0x366625202c303266ull,0x2e766f6d090a3b30ull,
0x3666250920323366ull,0x3830346630202c32ull,0x20203b3030303030ull,0x0a34202f2f092020ull,
0x74672e7074657309ull,0x702509203233662eull,0x31366625202c3232ull,0x0a3b32366625202cull,
0x2032327025214009ull,0x5f4c240920617262ull,0x3b32323730335f32ull,0x30335f325f4c240aull,
0x6f6d090a3a383739ull,0x2509203233732e76ull,0x337225202c303272ull,0x2e617262090a3b37ull,
0x744c240920696e75ull,0x0a3b3835325f325full,0x3730335f325f4c24ull,0x3c2f2f200a3a3232ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3939315f325f744cull,0x636f6c2e090a3037ull,
0x0938333209353109ull,0x662e6c756d090a30ull,0x3631662509203233ull,0x202c31316625202cull,
0x61090a3b30316625ull,0x09203233662e6464ull,0x6625202c33366625ull,0x36316625202c3631ull,
0x662e646461090a3bull,0x3031662509203233ull,0x25202c396625202cull,0x6c2e090a3b333666ull,
0x333209353109636full,0x627573090a300939ull,0x662509203233662eull,0x30326625202c3436ull,
0x0a3b30366625202cull,0x3233662e64646109ull,0x202c313166250920ull,0x366625202c386625ull,
0x636f6c2e090a3b34ull,0x0930343209353109ull,0x662e6c756d090a30ull,0x3536662509203233ull,
0x202c30316625202cull,0x2e090a3b30316625ull,0x3209353109636f6cull,0x7573090a30093833ull,
0x2509203233732e62ull,0x317225202c393372ull,0x090a3b3031202c36ull,0x203233752e766f6dull,
0x30202c3034722509ull,0x2e70746573090a3bull,0x09203233732e656cull,0x7225202c33327025ull,
0x30347225202c3933ull,0x3332702540090a3bull,0x4c24092061726220ull,0x30393431335f325full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f325full,
0x33662e6c756d090aull,0x2c30326625092032ull,0x25202c3131662520ull,0x6461090a3b313166ull,
0x2509203233662e64ull,0x326625202c363666ull,0x3b35366625202c30ull,0x33662e766f6d090aull,
0x2c37366625092032ull,0x3030383034663020ull,0x202020203b303030ull,0x73090a34202f2f09ull,
0x662e74672e707465ull,0x3432702509203233ull,0x202c36366625202cull,0x40090a3b37366625ull,
0x7262203432702521ull,0x5f325f4c24092061ull,0x240a3b3433323133ull,0x393431335f325f4cull,
0x2e766f6d090a3a30ull,0x3272250920323373ull,0x3b39337225202c30ull,0x6e752e617262090aull,
0x325f744c24092069ull,0x4c240a3b3835325full,0x34333231335f325full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f325full,0x3109636f6c2e090aull,
0x0a30093734320935ull,0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,
0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3836ull,0x0a3b36316625202cull,
0x3233662e64646109ull,0x202c303166250920ull,0x366625202c396625ull,0x636f6c2e090a3b38ull,
0x0938343209353109ull,0x662e627573090a30ull,0x3936662509203233ull,0x202c30326625202cull,
0x61090a3b35366625ull,0x09203233662e6464ull,0x6625202c31316625ull,0x3b39366625202c38ull,
0x3109636f6c2e090aull,0x0a30093934320935ull,0x3233662e6c756d09ull,0x202c303766250920ull,
0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3734320935310963ull,0x2e627573090a3009ull,
0x3472250920323373ull,0x2c36317225202c31ull,0x6f6d090a3b313120ull,0x2509203233752e76ull,
0x0a3b30202c323472ull,0x656c2e7074657309ull,0x702509203233732eull,0x31347225202c3532ull,
0x0a3b32347225202cull,0x6220353270254009ull,0x325f4c2409206172ull,0x0a3b32303032335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x325f744c24206465ull,0x090a30373939315full,
0x203233662e6c756dull,0x25202c3032662509ull,0x316625202c313166ull,0x2e646461090a3b31ull,
0x3766250920323366ull,0x2c30326625202c31ull,0x090a3b3037662520ull,0x203233662e766f6dull,
0x30202c3237662509ull,0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,
0x3233662e74672e70ull,0x202c363270250920ull,0x6625202c31376625ull,0x252140090a3b3237ull,
0x2061726220363270ull,0x31335f325f4c2409ull,0x5f4c240a3b363437ull,0x3a32303032335f32ull,
0x33732e766f6d090aull,0x2c30327225092032ull,0x090a3b3134722520ull,0x20696e752e617262ull,
0x325f325f744c2409ull,0x325f4c240a3b3835ull,0x0a3a36343731335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a30373939315full,0x09353109636f6c2eull,
0x6d090a3009363532ull,0x09203233662e6c75ull,0x6625202c36316625ull,0x30316625202c3131ull,
0x662e646461090a3bull,0x3337662509203233ull,0x202c36316625202cull,0x61090a3b36316625ull,
0x09203233662e6464ull,0x6625202c30316625ull,0x3b33376625202c39ull,0x3109636f6c2e090aull,
0x0a30093735320935ull,0x3233662e62757309ull,0x202c343766250920ull,0x6625202c30326625ull,
0x646461090a3b3037ull,0x662509203233662eull,0x2c386625202c3131ull,0x090a3b3437662520ull,
0x09353109636f6c2eull,0x6d090a3009383532ull,0x09203233662e6c75ull,0x6625202c35376625ull,
0x30316625202c3031ull,0x09636f6c2e090a3bull,0x3009363532093531ull,0x33732e627573090aull,
0x2c33347225092032ull,0x31202c3631722520ull,0x2e766f6d090a3b32ull,0x3472250920323375ull,
0x73090a3b30202c34ull,0x732e656c2e707465ull,0x3732702509203233ull,0x202c33347225202cull,
0x40090a3b34347225ull,0x6172622037327025ull,0x335f325f4c240920ull,0x2f200a3b34313532ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x315f325f744c2420ull,0x756d090a30373939ull,
0x2509203233662e6cull,0x316625202c303266ull,0x3b31316625202c31ull,0x33662e646461090aull,
0x2c36376625092032ull,0x25202c3032662520ull,0x6f6d090a3b353766ull,0x2509203233662e76ull,
0x346630202c373766ull,0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,
0x09203233662e7467ull,0x6625202c38327025ull,0x37376625202c3637ull,0x3270252140090a3bull,
0x2409206172622038ull,0x353232335f325f4cull,0x5f325f4c240a3b38ull,0x090a3a3431353233ull,
0x203233732e766f6dull,0x25202c3032722509ull,0x7262090a3b333472ull,0x240920696e752e61ull,
0x3835325f325f744cull,0x335f325f4c240a3bull,0x2f200a3a38353232ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x315f325f744c2420ull,0x6c2e090a30373939ull,0x363209353109636full,
0x6c756d090a300935ull,0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,
0x3233662e64646109ull,0x202c383766250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,
0x662509203233662eull,0x2c396625202c3031ull,0x090a3b3837662520ull,0x09353109636f6c2eull,
0x73090a3009363632ull,0x09203233662e6275ull,0x6625202c39376625ull,0x35376625202c3032ull,
0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b393766ull,
0x363209353109636full,0x6c756d090a300937ull,0x662509203233662eull,0x30316625202c3038ull,
0x0a3b30316625202cull,0x353109636f6c2e09ull,0x090a300935363209ull,0x203233732e627573ull,
0x25202c3534722509ull,0x3b3331202c363172ull,0x33752e766f6d090aull,0x2c36347225092032ull,
0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c393270250920ull,0x7225202c35347225ull,
0x702540090a3b3634ull,0x0920617262203932ull,0x3033335f325f4c24ull,0x3c2f2f200a3b3632ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3939315f325f744cull,0x2e6c756d090a3037ull,
0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,0x203233662e646461ull,
0x25202c3138662509ull,0x386625202c303266ull,0x2e766f6d090a3b30ull,0x3866250920323366ull,
0x3830346630202c32ull,0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,
0x702509203233662eull,0x31386625202c3033ull,0x0a3b32386625202cull,0x2030337025214009ull,
0x5f4c240920617262ull,0x3b30373732335f32ull,0x33335f325f4c240aull,0x6f6d090a3a363230ull,
0x2509203233732e76ull,0x347225202c303272ull,0x2e617262090a3b35ull,0x744c240920696e75ull,
0x0a3b3835325f325full,0x3732335f325f4c24ull,0x3c2f2f200a3a3037ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3939315f325f744cull,0x636f6c2e090a3037ull,0x0934373209353109ull,
0x662e6c756d090a30ull,0x3631662509203233ull,0x202c31316625202cull,0x61090a3b30316625ull,
0x09203233662e6464ull,0x6625202c33386625ull,0x36316625202c3631ull,0x662e646461090a3bull,
0x3031662509203233ull,0x25202c396625202cull,0x6c2e090a3b333866ull,0x373209353109636full,
0x627573090a300935ull,0x662509203233662eull,0x30326625202c3438ull,0x0a3b30386625202cull,
0x3233662e64646109ull,0x202c313166250920ull,0x386625202c386625ull,0x636f6c2e090a3b34ull,
0x0936373209353109ull,0x662e6c756d090a30ull,0x3538662509203233ull,0x202c30316625202cull,
0x2e090a3b30316625ull,0x3209353109636f6cull,0x7573090a30093437ull,0x2509203233732e62ull,
0x317225202c373472ull,0x090a3b3431202c36ull,0x203233752e766f6dull,0x30202c3834722509ull,
0x2e70746573090a3bull,0x09203233732e656cull,0x7225202c31337025ull,0x38347225202c3734ull,
0x3133702540090a3bull,0x4c24092061726220ull,0x38333533335f325full,0x6f6c3c2f2f200a3bull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f325full,0x33662e6c756d090aull,
0x2c30326625092032ull,0x25202c3131662520ull,0x6461090a3b313166ull,0x2509203233662e64ull,
0x326625202c363866ull,0x3b35386625202c30ull,0x33662e766f6d090aull,0x2c37386625092032ull,
0x3030383034663020ull,0x202020203b303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3233702509203233ull,0x202c36386625202cull,0x40090a3b37386625ull,0x7262203233702521ull,
0x5f325f4c24092061ull,0x240a3b3238323333ull,0x333533335f325f4cull,0x2e766f6d090a3a38ull,
0x3272250920323373ull,0x3b37347225202c30ull,0x6e752e617262090aull,0x325f744c24092069ull,
0x4c240a3b3835325full,0x32383233335f325full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x30373939315f325full,0x3109636f6c2e090aull,0x0a30093338320935ull,
0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,0x646461090a3b3031ull,
0x662509203233662eull,0x36316625202c3838ull,0x0a3b36316625202cull,0x3233662e64646109ull,
0x202c303166250920ull,0x386625202c396625ull,0x636f6c2e090a3b38ull,0x0934383209353109ull,
0x662e627573090a30ull,0x3938662509203233ull,0x202c30326625202cull,0x61090a3b35386625ull,
0x09203233662e6464ull,0x6625202c31316625ull,0x3b39386625202c38ull,0x3109636f6c2e090aull,
0x0a30093538320935ull,0x3233662e6c756d09ull,0x202c303966250920ull,0x6625202c30316625ull,
0x6f6c2e090a3b3031ull,0x3338320935310963ull,0x2e627573090a3009ull,0x3472250920323373ull,
0x2c36317225202c39ull,0x6f6d090a3b353120ull,0x2509203233752e76ull,0x0a3b30202c303572ull,
0x656c2e7074657309ull,0x702509203233732eull,0x39347225202c3333ull,0x0a3b30357225202cull,
0x6220333370254009ull,0x325f4c2409206172ull,0x0a3b30353034335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x325f744c24206465ull,0x090a30373939315full,0x203233662e6c756dull,
0x25202c3032662509ull,0x316625202c313166ull,0x2e646461090a3b31ull,0x3966250920323366ull,
0x2c30326625202c31ull,0x090a3b3039662520ull,0x203233662e766f6dull,0x30202c3239662509ull,
0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,
0x202c343370250920ull,0x6625202c31396625ull,0x252140090a3b3239ull,0x2061726220343370ull,
0x33335f325f4c2409ull,0x5f4c240a3b343937ull,0x3a30353034335f32ull,0x33732e766f6d090aull,
0x2c30327225092032ull,0x090a3b3934722520ull,0x20696e752e617262ull,0x325f325f744c2409ull,
0x325f4c240a3b3835ull,0x0a3a34393733335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,
0x325f744c24206465ull,0x090a30373939315full,0x09353109636f6c2eull,0x6d090a3009323932ull,
0x09203233662e6c75ull,0x6625202c36316625ull,0x30316625202c3131ull,0x662e646461090a3bull,
0x3339662509203233ull,0x202c36316625202cull,0x61090a3b36316625ull,0x09203233662e6464ull,
0x6625202c30316625ull,0x3b33396625202c39ull,0x3109636f6c2e090aull,0x0a30093339320935ull,
0x3233662e62757309ull,0x202c343966250920ull,0x6625202c30326625ull,0x646461090a3b3039ull,
0x662509203233662eull,0x2c386625202c3131ull,0x090a3b3439662520ull,0x09353109636f6c2eull,
0x6d090a3009343932ull,0x09203233662e6c75ull,0x6625202c35396625ull,0x30316625202c3031ull,
0x09636f6c2e090a3bull,0x3009323932093531ull,0x33732e627573090aull,0x2c31357225092032ull,
0x31202c3631722520ull,0x2e766f6d090a3b36ull,0x3572250920323375ull,0x73090a3b30202c32ull,
0x732e656c2e707465ull,0x3533702509203233ull,0x202c31357225202cull,0x40090a3b32357225ull,
0x6172622035337025ull,0x335f325f4c240920ull,0x2f200a3b32363534ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x315f325f744c2420ull,0x756d090a30373939ull,0x2509203233662e6cull,
0x316625202c303266ull,0x3b31316625202c31ull,0x33662e646461090aull,0x2c36396625092032ull,
0x25202c3032662520ull,0x6f6d090a3b353966ull,0x2509203233662e76ull,0x346630202c373966ull,
0x3b30303030303830ull,0x202f2f0920202020ull,0x2e70746573090a34ull,0x09203233662e7467ull,
0x6625202c36337025ull,0x37396625202c3639ull,0x3370252140090a3bull,0x2409206172622036ull,
0x303334335f325f4cull,0x5f325f4c240a3b36ull,0x090a3a3236353433ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b313572ull,0x240920696e752e61ull,0x3835325f325f744cull,
0x335f325f4c240a3bull,0x2f200a3a36303334ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f325f744c2420ull,0x6c2e090a30373939ull,0x303309353109636full,0x6c756d090a300931ull,
0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,0x3233662e64646109ull,
0x202c383966250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,0x662509203233662eull,
0x2c396625202c3031ull,0x090a3b3839662520ull,0x09353109636f6c2eull,0x73090a3009323033ull,
0x09203233662e6275ull,0x6625202c39396625ull,0x35396625202c3032ull,0x662e646461090a3bull,
0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b393966ull,0x303309353109636full,
0x6c756d090a300933ull,0x662509203233662eull,0x316625202c303031ull,0x3b30316625202c30ull,
0x3109636f6c2e090aull,0x0a30093130330935ull,0x3233732e62757309ull,0x202c333572250920ull,
0x3731202c36317225ull,0x752e766f6d090a3bull,0x3435722509203233ull,0x6573090a3b30202cull,
0x33732e656c2e7074ull,0x2c37337025092032ull,0x25202c3335722520ull,0x2540090a3b343572ull,
0x2061726220373370ull,0x35335f325f4c2409ull,0x2f2f200a3b343730ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,
0x2064656c6562616cull,0x39315f325f744c24ull,0x6c756d090a303739ull,0x662509203233662eull,
0x31316625202c3032ull,0x0a3b31316625202cull,0x3233662e64646109ull,0x2c31303166250920ull,
0x25202c3032662520ull,0x6d090a3b30303166ull,0x09203233662e766full,0x30202c3230316625ull,
0x3030303038303466ull,0x2f2f092020203b30ull,0x70746573090a3420ull,0x203233662e74672eull,
0x25202c3833702509ull,0x6625202c31303166ull,0x2140090a3b323031ull,0x6172622038337025ull,
0x335f325f4c240920ull,0x4c240a3b38313834ull,0x34373035335f325full,0x732e766f6d090a3aull,
0x3032722509203233ull,0x0a3b33357225202cull,0x696e752e61726209ull,0x5f325f744c240920ull,
0x5f4c240a3b383532ull,0x3a38313834335f32ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a30373939315f32ull,0x353109636f6c2e09ull,0x090a300930313309ull,
0x203233662e6c756dull,0x25202c3631662509ull,0x316625202c313166ull,0x2e646461090a3b30ull,
0x3166250920323366ull,0x36316625202c3330ull,0x0a3b36316625202cull,0x3233662e64646109ull,
0x202c303166250920ull,0x316625202c396625ull,0x6f6c2e090a3b3330ull,0x3131330935310963ull,
0x2e627573090a3009ull,0x3166250920323366ull,0x30326625202c3430ull,0x3b3030316625202cull,
0x33662e646461090aull,0x2c31316625092032ull,0x6625202c38662520ull,0x6c2e090a3b343031ull,
0x313309353109636full,0x6c756d090a300932ull,0x662509203233662eull,0x316625202c353031ull,
0x3b30316625202c30ull,0x3109636f6c2e090aull,0x0a30093031330935ull,0x3233732e62757309ull,
0x202c353572250920ull,0x3831202c36317225ull,0x752e766f6d090a3bull,0x3635722509203233ull,
0x6573090a3b30202cull,0x33732e656c2e7074ull,0x2c39337025092032ull,0x25202c3535722520ull,
0x2540090a3b363572ull,0x2061726220393370ull,0x35335f325f4c2409ull,0x2f2f200a3b363835ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x39315f325f744c24ull,0x6c756d090a303739ull,
0x662509203233662eull,0x31316625202c3032ull,0x0a3b31316625202cull,0x3233662e64646109ull,
0x2c36303166250920ull,0x25202c3032662520ull,0x6d090a3b35303166ull,0x09203233662e766full,
0x30202c3730316625ull,0x3030303038303466ull,0x2f2f092020203b30ull,0x70746573090a3420ull,
0x203233662e74672eull,0x25202c3034702509ull,0x6625202c36303166ull,0x2140090a3b373031ull,
0x6172622030347025ull,0x335f325f4c240920ull,0x4c240a3b30333335ull,0x36383535335f325full,
0x732e766f6d090a3aull,0x3032722509203233ull,0x0a3b35357225202cull,0x696e752e61726209ull,
0x5f325f744c240920ull,0x5f4c240a3b383532ull,0x3a30333335335f32ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a30373939315f32ull,0x353109636f6c2e09ull,
0x090a300939313309ull,0x203233662e6c756dull,0x25202c3631662509ull,0x316625202c313166ull,
0x2e646461090a3b30ull,0x3166250920323366ull,0x36316625202c3830ull,0x0a3b36316625202cull,
0x3233662e64646109ull,0x202c303166250920ull,0x316625202c396625ull,0x6f6c2e090a3b3830ull,
0x3032330935310963ull,0x2e627573090a3009ull,0x3166250920323366ull,0x30326625202c3930ull,
0x3b3530316625202cull,0x33662e646461090aull,0x2c31316625092032ull,0x6625202c38662520ull,
0x6c2e090a3b393031ull,0x323309353109636full,0x6c756d090a300931ull,0x662509203233662eull,
0x316625202c303131ull,0x3b30316625202c30ull,0x3109636f6c2e090aull,0x0a30093532330935ull,
0x3233732e62757309ull,0x202c363172250920ull,0x3931202c36317225ull,0x09636f6c2e090a3bull,
0x3009393133093531ull,0x33732e766f6d090aull,0x2c37357225092032ull,0x746573090a3b3020ull,
0x3233732e656c2e70ull,0x25202c3370250920ull,0x357225202c363172ull,0x33702540090a3b37ull,
0x4c24092061726220ull,0x38393036335f325full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x30373939315f325full,0x33662e6c756d090aull,0x2c30326625092032ull,
0x25202c3131662520ull,0x6461090a3b313166ull,0x2509203233662e64ull,0x6625202c31313166ull,
0x31316625202c3032ull,0x2e766f6d090a3b30ull,0x3166250920323366ull,0x30346630202c3231ull,
0x203b303030303038ull,0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,
0x31316625202c3134ull,0x3231316625202c31ull,0x3470252140090a3bull,0x2409206172622031ull,
0x343835335f325f4cull,0x5f325f4c240a3b32ull,0x090a3a3839303633ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b363172ull,0x240920696e752e61ull,0x3835325f325f744cull,
0x335f325f4c240a3bull,0x2f200a3a32343835ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f325f744c2420ull,0x6c2e090a30373939ull,0x323309353109636full,0x6c756d090a300938ull,
0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,0x3233662e64646109ull,
0x2c33313166250920ull,0x25202c3631662520ull,0x6461090a3b363166ull,0x2509203233662e64ull,
0x396625202c303166ull,0x3b3331316625202cull,0x3109636f6c2e090aull,0x0a30093932330935ull,
0x3233662e62757309ull,0x2c34313166250920ull,0x25202c3032662520ull,0x61090a3b30313166ull,
0x09203233662e6464ull,0x6625202c31316625ull,0x3431316625202c38ull,0x09636f6c2e090a3bull,
0x3009303333093531ull,0x33662e6c756d090aull,0x2c32316625092032ull,0x25202c3031662520ull,
0x6c2e090a3b303166ull,0x333309353109636full,0x6c756d090a300931ull,0x662509203233662eull,
0x31316625202c3331ull,0x0a3b31316625202cull,0x353109636f6c2e09ull,0x090a300938323309ull,
0x20696e752e617262ull,0x315f325f744c2409ull,0x4c240a3b30373939ull,0x3a3835325f325f74ull,
0x3109636f6c2e090aull,0x090a300931320936ull,0x203233732e766f6dull,0x30202c3835722509ull,
0x2e70746573090a3bull,0x09203233732e7467ull,0x7225202c32347025ull,0x38357225202c3032ull,
0x732e627573090a3bull,0x3935722509203233ull,0x202c35317225202cull,0x6d090a3b30327225ull,
0x09203233732e766full,0x3b30202c30367225ull,0x732e706c6573090aull,0x3136722509203233ull,
0x202c39357225202cull,0x7025202c30367225ull,0x766f6d090a3b3234ull,0x722509203233752eull,
0x090a3b30202c3236ull,0x2e71652e70746573ull,0x3470250920323373ull,0x2c31367225202c33ull,
0x090a3b3236722520ull,0x7262203334702540ull,0x325f744c24092061ull,0x0a3b34333637335full,
0x363109636f6c2e09ull,0x6c090a3009383209ull,0x2e6d617261702e64ull,0x3672250920323373ull,
0x75635f5f5b202c33ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,
0x615f6269695f3053ull,0x6e6f6974616d696eull,0x0a3b5d656d617246ull,0x3233732e64646109ull,
0x202c343672250920ull,0x7225202c33367225ull,0x2e646c090a3b3136ull,0x38752e6d61726170ull,
0x202c353672250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f30746full,0x6375365076456649ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x6f6c6f635f626969ull,0x090a3b5d302b7372ull,0x732e6f6c2e6c756dull,
0x3636722509203233ull,0x202c34367225202cull,0x63090a3b35367225ull,0x33752e38752e7476ull,
0x2c37367225092032ull,0x090a3b3636722520ull,0x09363109636f6c2eull,0x646c090a30093932ull,
0x752e6d617261702eull,0x2c38367225092038ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f30746f72ull,0x7536507645664930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x30535f32535f3253ull,0x6c6f635f6269695full,0x0a3b5d312b73726full,
0x2e6f6c2e6c756d09ull,0x3672250920323373ull,0x2c34367225202c39ull,0x090a3b3836722520ull,
0x752e38752e747663ull,0x3037722509203233ull,0x0a3b39367225202cull,0x363109636f6c2e09ull,
0x6c090a3009303309ull,0x2e6d617261702e64ull,0x3137722509203875ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764566493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x6f635f6269695f30ull,
0x3b5d322b73726f6cull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x34367225202c3237ull,
0x0a3b31377225202cull,0x2e38752e74766309ull,0x3772250920323375ull,0x3b32377225202c33ull,
0x6e752e617262090aull,0x325f744c24092069ull,0x0a3b38373337335full,0x37335f325f744c24ull,
0x6c2e090a3a343336ull,0x343309363109636full,0x2e766f6d090a3009ull,0x3772250920323375ull,
0x6d090a3b30202c33ull,0x09203233752e766full,0x3b30202c30377225ull,0x33752e766f6d090aull,
0x2c37367225092032ull,0x5f744c240a3b3020ull,0x3a38373337335f32ull,0x7261702e646c090aull,
0x09203436752e6d61ull,0x5f5b202c31647225ull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x664930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f32535f32535f32ull,0x69695f30535f3253ull,0x0a3b5d7473645f62ull,0x2e6f6c2e6c756d09ull,
0x3772250920323373ull,0x202c377225202c34ull,0x6461090a3b367225ull,0x2509203233732e64ull,
0x347225202c353772ull,0x0a3b34377225202cull,0x3436752e74766309ull,0x722509203233732eull,
0x35377225202c3264ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x647225202c336472ull,
0x61090a3b34202c32ull,0x09203436752e6464ull,0x7225202c34647225ull,0x33647225202c3164ull,
0x61702e646c090a3bull,0x203233732e6d6172ull,0x5b202c3637722509ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764566ull,
0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,0x656d6172665f6269ull,
0x2e766f6d090a3b5dull,0x3772250920323375ull,0x73090a3b30202c37ull,0x732e656e2e707465ull,
0x3434702509203233ull,0x202c36377225202cull,0x40090a3b37377225ull,0x6172622034347025ull,
0x5f325f744c240920ull,0x090a3b3634313833ull,0x09363109636f6c2eull,0x6f6d090a30093134ull,
0x2509203233752e76ull,0x0a3b30202c383772ull,0x626f6c672e747309ull,0x38752e34762e6c61ull,
0x2b346472255b0920ull,0x3672257b202c5d30ull,0x252c303772252c37ull,0x383772252c333772ull,
0x2e617262090a3b7dull,0x744c240920696e75ull,0x30393837335f325full,0x5f325f744c240a3bull,
0x090a3a3634313833ull,0x09363109636f6c2eull,0x6461090a30093534ull,0x2509203233732e64ull,
0x377225202c393772ull,0x73090a3b31202c36ull,0x09203233732e7268ull,0x7225202c30387225ull,
0x0a3b3133202c3937ull,0x3233732e766f6d09ull,0x202c313872250920ull,0x2e646e61090a3b31ull,
0x3872250920323362ull,0x2c30387225202c32ull,0x090a3b3138722520ull,0x203233732e646461ull,
0x25202c3338722509ull,0x377225202c323872ull,0x2e726873090a3b39ull,0x3872250920323373ull,
0x2c33387225202c34ull,0x2e646c090a3b3120ull,0x762e6c61626f6c67ull,0x257b092038752e34ull,
0x363872252c353872ull,0x7d5f2c373872252cull,0x2b346472255b202cull,0x6c756d090a3b5d30ull,
0x203233732e6f6c2eull,0x25202c3838722509ull,0x387225202c363772ull,0x2e646461090a3b35ull,
0x3872250920323373ull,0x2c37367225202c39ull,0x090a3b3838722520ull,0x203233732e646461ull,
0x25202c3039722509ull,0x387225202c343872ull,0x2e766964090a3b39ull,0x3972250920323373ull,
0x2c30397225202c31ull,0x090a3b3937722520ull,0x09363109636f6c2eull,0x756d090a30093634ull,
0x3233732e6f6c2e6cull,0x202c323972250920ull,0x7225202c36377225ull,0x646461090a3b3638ull,
0x722509203233732eull,0x30377225202c3339ull,0x0a3b32397225202cull,0x3233732e64646109ull,
0x202c343972250920ull,0x7225202c34387225ull,0x766964090a3b3339ull,0x722509203233732eull,
0x34397225202c3539ull,0x0a3b39377225202cull,0x626f6c672e747309ull,0x38752e32762e6c61ull,
0x2b346472255b0920ull,0x3972257b202c5d30ull,0x3b7d353972252c31ull,0x3109636f6c2e090aull,
0x090a300937340936ull,0x732e6f6c2e6c756dull,0x3639722509203233ull,0x202c36377225202cull,
0x61090a3b37387225ull,0x09203233732e6464ull,0x7225202c37397225ull,0x36397225202c3337ull,
0x732e646461090a3bull,0x3839722509203233ull,0x202c34387225202cull,0x64090a3b37397225ull,
0x09203233732e7669ull,0x7225202c39397225ull,0x39377225202c3839ull,0x6c672e7473090a3bull,
0x2038752e6c61626full,0x322b346472255b09ull,0x3b39397225202c5dull,0x335f325f744c240aull,
0x4c240a3a30393837ull,0x353336335f325f74ull,0x636f6c2e090a3a34ull,0x3009303509363109ull,
0x0a3b74697865090aull,0x5f646e6557444c24ull,0x646e614d36315a5full,0x5f30746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x3a6269695f30535full,0x5f202f2f207d090aull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645664930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,
0x0a0a6269695f3053ull,0x207972746e652e09ull,0x646e614d36315a5full,0x5f30746f72626c65ull,
0x7645644930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x206269695f30535full,0x7261702e09090a28ull,0x203436752e206d61ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764564ull,
0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,0x0a2c7473645f6269ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x30746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x535f32535f32535full,0x6269695f30535f32ull,0x2c576567616d695full,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,
0x69695f30535f3253ull,0x486567616d695f62ull,0x7261702e09090a2cull,0x203233732e206d61ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3074ull,
0x6863753650764564ull,0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,
0x636e7572635f6269ull,0x61702e09090a2c68ull,0x3436662e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x66664f785f626969ull,
0x7261702e09090a2cull,0x203436662e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3074ull,0x6863753650764564ull,0x5f54696969347261ull,
0x32535f32535f3253ull,0x695f30535f32535full,0x2c66664f795f6269ull,0x617261702e09090aull,
0x5f203436662e206dull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,
0x69695f30535f3253ull,0x090a2c504a785f62ull,0x206d617261702e09ull,0x635f5f203436662eull,
0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,0x7645644930316d73ull,
0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,0x5f6269695f30535full,
0x2e09090a2c504a79ull,0x662e206d61726170ull,0x6475635f5f203436ull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x535f32535f32535full,0x63735f6269695f30ull,0x2e09090a2c656c61ull,
0x612e206d61726170ull,0x2e2034206e67696cull,0x6475635f5f203862ull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x535f32535f32535full,0x6f635f6269695f30ull,0x2c5d345b73726f6cull,
0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f32535f32535f32ull,0x69695f30535f3253ull,0x2c656d6172665f62ull,0x617261702e09090aull,
0x5f203233732e206dull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,
0x69695f30535f3253ull,0x74616d696e615f62ull,0x656d6172466e6f69ull,0x7261702e09090a2cull,
0x5f2038732e206d61ull,0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,
0x644930316d735f30ull,0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,
0x69695f30535f3253ull,0x090a294a73695f62ull,0x206765722e090a7bull,0x687225203631752eull,
0x722e090a3b3e363cull,0x203233752e206765ull,0x3b3e3130313c7225ull,0x2e206765722e090aull,
0x3c64722520343675ull,0x65722e090a3b3e36ull,0x25203436662e2067ull,0x3b3e3631313c6466ull,
0x2e206765722e090aull,0x3c70252064657270ull,0x6c2e090a3b3e3634ull,0x303109363109636full,
0x3142424c240a3009ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,0x45644930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,
0x752e766f6d090a3aull,0x3168722509203631ull,0x646961746325202cull,0x766f6d090a3b782eull,
0x722509203631752eull,0x69746e25202c3268ull,0x756d090a3b782e64ull,0x752e656469772e6cull,
0x2c31722509203631ull,0x25202c3168722520ull,0x6f6d090a3b326872ull,0x2509203631752e76ull,
0x746325202c336872ull,0x090a3b792e646961ull,0x203631752e766f6dull,0x25202c3468722509ull,
0x0a3b792e6469746eull,0x6469772e6c756d09ull,0x2509203631752e65ull,0x33687225202c3272ull,
0x0a3b34687225202cull,0x3233752e74766309ull,0x722509203631752eull,0x2e64697425202c33ull,
0x2e646461090a3b78ull,0x3472250920323375ull,0x25202c337225202cull,0x747663090a3b3172ull,
0x3631752e3233752eull,0x25202c3572250920ull,0x090a3b792e646974ull,0x203233752e646461ull,
0x7225202c36722509ull,0x0a3b327225202c35ull,0x617261702e646c09ull,0x2509203233732e6dull,
0x635f5f5b202c3772ull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f30746f72626c65ull,
0x7645644930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x5f6269695f30535full,0x3b5d576567616d69ull,0x7261702e646c090aull,0x09203233732e6d61ull,
0x5f5f5b202c387225ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x30746f72626c6564ull,
0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,
0x6269695f30535f32ull,0x5d486567616d695full,0x672e746573090a3bull,0x33732e3233752e74ull,
0x202c397225092032ull,0x367225202c387225ull,0x732e67656e090a3bull,0x3031722509203233ull,
0x090a3b397225202cull,0x752e74672e746573ull,0x09203233732e3233ull,0x7225202c31317225ull,
0x0a3b347225202c37ull,0x3233732e67656e09ull,0x202c323172250920ull,0x61090a3b31317225ull,
0x09203233622e646eull,0x7225202c33317225ull,0x32317225202c3031ull,0x752e766f6d090a3bull,
0x3431722509203233ull,0x6573090a3b30202cull,0x33732e71652e7074ull,0x202c317025092032ull,
0x7225202c33317225ull,0x702540090a3b3431ull,0x2409206172622031ull,0x3336335f335f744cull,
0x6f6c2e090a3b3435ull,0x3133310935310963ull,0x702e646c090a3009ull,0x3233732e6d617261ull,
0x202c353172250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x6e7572635f626969ull,0x6f6d090a3b5d6863ull,0x2509203233732e76ull,
0x317225202c363172ull,0x702e646c090a3b35ull,0x3436662e6d617261ull,0x202c316466250920ull,
0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,
0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,
0x6c6163735f626969ull,0x2e646c090a3b5d65ull,0x36662e6d61726170ull,0x2c32646625092034ull,
0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f30746f72ull,
0x7536507645644930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x30535f32535f3253ull,
0x664f785f6269695full,0x747663090a3b5d66ull,0x2e3436662e6e722eull,0x6466250920323373ull,
0x0a3b347225202c33ull,0x2e6e722e64616d09ull,0x6466250920343666ull,0x2c33646625202c34ull,
0x25202c3164662520ull,0x646c090a3b326466ull,0x662e6d617261702eull,0x3564662509203436ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,
0x4f795f6269695f30ull,0x7663090a3b5d6666ull,0x3436662e6e722e74ull,0x662509203233732eull,
0x3b367225202c3664ull,0x6e722e64616d090aull,0x662509203436662eull,0x36646625202c3764ull,
0x202c31646625202cull,0x6c090a3b35646625ull,0x2e6d617261702e64ull,0x3731722509203873ull,
0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,
0x73695f6269695f30ull,0x766f6d090a3b5d4aull,0x722509203233752eull,0x090a3b30202c3831ull,
0x2e71652e70746573ull,0x3270250920323373ull,0x202c37317225202cull,0x40090a3b38317225ull,
0x2061726220327025ull,0x335f335f744c2409ull,0x2e090a3b32323137ull,0x3109353109636f6cull,
0x646c090a30093633ull,0x662e6d617261702eull,0x3864662509203436ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x4a785f6269695f30ull,
0x6f6c2e090a3b5d50ull,0x3733310935310963ull,0x702e646c090a3009ull,0x3436662e6d617261ull,
0x202c396466250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f30746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x5d504a795f626969ull,0x09636f6c2e090a3bull,0x3009383331093531ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x0a3b37646625202cull,0x353109636f6c2e09ull,
0x090a300939333109ull,0x203436662e766f6dull,0x202c313164662509ull,0x2e090a3b34646625ull,
0x3109353109636f6cull,0x756d090a30093034ull,0x2509203436662e6cull,0x6625202c32316466ull,
0x37646625202c3764ull,0x09636f6c2e090a3bull,0x3009313431093531ull,0x36662e6c756d090aull,
0x3331646625092034ull,0x202c34646625202cull,0x62090a3b34646625ull,0x0920696e752e6172ull,
0x36335f335f744c24ull,0x744c240a3b363638ull,0x32323137335f335full,0x09636f6c2e090a3aull,
0x3009353431093531ull,0x36662e766f6d090aull,0x2c38646625092034ull,0x090a3b3464662520ull,
0x09353109636f6c2eull,0x6d090a3009363431ull,0x09203436662e766full,0x6625202c39646625ull,
0x6f6c2e090a3b3764ull,0x3035310935310963ull,0x2e766f6d090a3009ull,0x6466250920343666ull,
0x30306430202c3331ull,0x3030303030303030ull,0x093b303030303030ull,0x6f6d090a30202f2full,
0x2509203436662e76ull,0x6430202c32316466ull,0x3030303030303030ull,0x3030303030303030ull,
0x090a30202f2f093bull,0x203436662e766f6dull,0x202c313164662509ull,0x3030303030306430ull,
0x3030303030303030ull,0x30202f2f093b3030ull,0x36662e766f6d090aull,0x3031646625092034ull,
0x303030306430202cull,0x3030303030303030ull,0x2f2f093b30303030ull,0x335f744c240a3020ull,
0x0a3a36363836335full,0x3233732e766f6d09ull,0x202c393172250920ull,0x70746573090a3b30ull,
0x203233732e656c2eull,0x7225202c33702509ull,0x39317225202c3531ull,0x5f335f744c240a3bull,
0x200a3a3037393931ull,0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,
0x6f6c2e090a353531ull,0x3535310935310963ull,0x33702540090a3009ull,0x4c24092061726220ull,
0x30373336325f335full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x30373939315f335full,0x36662e646461090aull,0x3431646625092034ull,0x2c3331646625202cull,
0x0a3b323164662520ull,0x3436662e766f6d09ull,0x2c35316466250920ull,0x3030313034643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,
0x646625202c347025ull,0x31646625202c3431ull,0x70252140090a3b35ull,0x2409206172622034ull,
0x313136325f335f4cull,0x5f335f4c240a3b34ull,0x090a3a3037333632ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b363172ull,0x240920696e752e61ull,0x3835325f335f744cull,
0x325f335f4c240a3bull,0x2f200a3a34313136ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f335f744c2420ull,0x6c2e090a30373939ull,0x353109353109636full,0x6c756d090a300937ull,
0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,0x2e646461090a3b30ull,
0x6466250920343666ull,0x31646625202c3731ull,0x3631646625202c36ull,0x662e646461090a3bull,
0x3164662509203436ull,0x2c39646625202c30ull,0x0a3b373164662520ull,0x353109636f6c2e09ull,
0x090a300938353109ull,0x203436662e627573ull,0x202c383164662509ull,0x25202c3331646625ull,
0x61090a3b32316466ull,0x09203436662e6464ull,0x25202c3131646625ull,0x646625202c386466ull,
0x6f6c2e090a3b3831ull,0x3935310935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x31646625202c3931ull,0x3031646625202c30ull,0x09636f6c2e090a3bull,0x3009373531093531ull,
0x33732e627573090aull,0x2c31327225092032ull,0x31202c3631722520ull,0x752e766f6d090a3bull,
0x3232722509203233ull,0x6573090a3b30202cull,0x33732e656c2e7074ull,0x202c357025092032ull,
0x7225202c31327225ull,0x702540090a3b3232ull,0x2409206172622035ull,0x383836325f335f4cull,
0x6c3c2f2f200a3b32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x373939315f335f74ull,
0x662e6c756d090a30ull,0x3264662509203436ull,0x3131646625202c30ull,0x3b3131646625202cull,
0x36662e646461090aull,0x3132646625092034ull,0x2c3032646625202cull,0x0a3b393164662520ull,
0x3436662e766f6d09ull,0x2c32326466250920ull,0x3030313034643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,0x646625202c367025ull,
0x32646625202c3132ull,0x70252140090a3b32ull,0x2409206172622036ull,0x323636325f335f4cull,
0x5f335f4c240a3b36ull,0x090a3a3238383632ull,0x203233732e766f6dull,0x25202c3032722509ull,
0x7262090a3b313272ull,0x240920696e752e61ull,0x3835325f335f744cull,0x325f335f4c240a3bull,
0x2f200a3a36323636ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x315f335f744c2420ull,
0x6c2e090a30373939ull,0x363109353109636full,0x6c756d090a300936ull,0x662509203436662eull,
0x646625202c363164ull,0x31646625202c3131ull,0x2e646461090a3b30ull,0x6466250920343666ull,
0x31646625202c3332ull,0x3631646625202c36ull,0x662e646461090a3bull,0x3164662509203436ull,
0x2c39646625202c30ull,0x0a3b333264662520ull,0x353109636f6c2e09ull,0x090a300937363109ull,
0x203436662e627573ull,0x202c343264662509ull,0x25202c3032646625ull,0x61090a3b39316466ull,
0x09203436662e6464ull,0x25202c3131646625ull,0x646625202c386466ull,0x6f6c2e090a3b3432ull,
0x3836310935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3532ull,
0x3031646625202c30ull,0x09636f6c2e090a3bull,0x3009363631093531ull,0x33732e627573090aull,
0x2c33327225092032ull,0x32202c3631722520ull,0x752e766f6d090a3bull,0x3432722509203233ull,
0x6573090a3b30202cull,0x33732e656c2e7074ull,0x202c377025092032ull,0x7225202c33327225ull,
0x702540090a3b3432ull,0x2409206172622037ull,0x393337325f335f4cull,0x6c3c2f2f200a3b34ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x373939315f335f74ull,0x662e6c756d090a30ull,
0x3264662509203436ull,0x3131646625202c30ull,0x3b3131646625202cull,0x36662e646461090aull,
0x3632646625092034ull,0x2c3032646625202cull,0x0a3b353264662520ull,0x3436662e766f6d09ull,
0x2c37326466250920ull,0x3030313034643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x2e70746573090a34ull,0x09203436662e7467ull,0x646625202c387025ull,0x32646625202c3632ull,
0x70252140090a3b37ull,0x2409206172622038ull,0x333137325f335f4cull,0x5f335f4c240a3b38ull,
0x090a3a3439333732ull,0x203233732e766f6dull,0x25202c3032722509ull,0x7262090a3b333272ull,
0x240920696e752e61ull,0x3835325f335f744cull,0x325f335f4c240a3bull,0x2f200a3a38333137ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x315f335f744c2420ull,0x6c2e090a30373939ull,
0x373109353109636full,0x6c756d090a300935ull,0x662509203436662eull,0x646625202c363164ull,
0x31646625202c3131ull,0x2e646461090a3b30ull,0x6466250920343666ull,0x31646625202c3832ull,
0x3631646625202c36ull,0x662e646461090a3bull,0x3164662509203436ull,0x2c39646625202c30ull,
0x0a3b383264662520ull,0x353109636f6c2e09ull,0x090a300936373109ull,0x203436662e627573ull,
0x202c393264662509ull,0x25202c3032646625ull,0x61090a3b35326466ull,0x09203436662e6464ull,
0x25202c3131646625ull,0x646625202c386466ull,0x6f6c2e090a3b3932ull,0x3737310935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3033ull,0x3031646625202c30ull,
0x09636f6c2e090a3bull,0x3009353731093531ull,0x33732e627573090aull,0x2c35327225092032ull,
0x33202c3631722520ull,0x752e766f6d090a3bull,0x3632722509203233ull,0x6573090a3b30202cull,
0x33732e656c2e7074ull,0x202c397025092032ull,0x7225202c35327225ull,0x702540090a3b3632ull,
0x2409206172622039ull,0x303937325f335f4cull,0x6c3c2f2f200a3b36ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x373939315f335f74ull,0x662e6c756d090a30ull,0x3264662509203436ull,
0x3131646625202c30ull,0x3b3131646625202cull,0x36662e646461090aull,0x3133646625092034ull,
0x2c3032646625202cull,0x0a3b303364662520ull,0x3436662e766f6d09ull,0x2c32336466250920ull,
0x3030313034643020ull,0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a34ull,
0x09203436662e7467ull,0x6625202c30317025ull,0x646625202c313364ull,0x252140090a3b3233ull,
0x2061726220303170ull,0x37325f335f4c2409ull,0x5f4c240a3b303536ull,0x3a36303937325f33ull,
0x33732e766f6d090aull,0x2c30327225092032ull,0x090a3b3532722520ull,0x20696e752e617262ull,
0x325f335f744c2409ull,0x335f4c240a3b3835ull,0x0a3a30353637325full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a30373939315full,0x09353109636f6c2eull,
0x6d090a3009343831ull,0x09203436662e6c75ull,0x25202c3631646625ull,0x6625202c31316466ull,
0x6461090a3b303164ull,0x2509203436662e64ull,0x6625202c33336466ull,0x646625202c363164ull,
0x646461090a3b3631ull,0x662509203436662eull,0x646625202c303164ull,0x3333646625202c39ull,
0x09636f6c2e090a3bull,0x3009353831093531ull,0x36662e627573090aull,0x3433646625092034ull,
0x2c3032646625202cull,0x0a3b303364662520ull,0x3436662e64646109ull,0x2c31316466250920ull,
0x25202c3864662520ull,0x2e090a3b34336466ull,0x3109353109636f6cull,0x756d090a30093638ull,
0x2509203436662e6cull,0x6625202c35336466ull,0x646625202c303164ull,0x6f6c2e090a3b3031ull,
0x3438310935310963ull,0x2e627573090a3009ull,0x3272250920323373ull,0x2c36317225202c37ull,
0x766f6d090a3b3420ull,0x722509203233752eull,0x090a3b30202c3832ull,0x2e656c2e70746573ull,
0x3170250920323373ull,0x2c37327225202c31ull,0x090a3b3832722520ull,0x7262203131702540ull,
0x5f335f4c24092061ull,0x200a3b3831343832ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3037393931ull,0x09203436662e6c75ull,0x25202c3032646625ull,
0x6625202c31316466ull,0x6461090a3b313164ull,0x2509203436662e64ull,0x6625202c36336466ull,
0x646625202c303264ull,0x766f6d090a3b3533ull,0x662509203436662eull,0x346430202c373364ull,
0x3030303030303130ull,0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3231702509203436ull,0x2c3633646625202cull,0x0a3b373364662520ull,0x2032317025214009ull,
0x5f4c240920617262ull,0x3b32363138325f33ull,0x38325f335f4c240aull,0x6f6d090a3a383134ull,
0x2509203233732e76ull,0x327225202c303272ull,0x2e617262090a3b37ull,0x744c240920696e75ull,
0x0a3b3835325f335full,0x3138325f335f4c24ull,0x3c2f2f200a3a3236ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3939315f335f744cull,0x636f6c2e090a3037ull,0x0933393109353109ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x3131646625202c36ull,0x3b3031646625202cull,
0x36662e646461090aull,0x3833646625092034ull,0x2c3631646625202cull,0x0a3b363164662520ull,
0x3436662e64646109ull,0x2c30316466250920ull,0x25202c3964662520ull,0x2e090a3b38336466ull,
0x3109353109636f6cull,0x7573090a30093439ull,0x2509203436662e62ull,0x6625202c39336466ull,
0x646625202c303264ull,0x646461090a3b3533ull,0x662509203436662eull,0x646625202c313164ull,
0x3933646625202c38ull,0x09636f6c2e090a3bull,0x3009353931093531ull,0x36662e6c756d090aull,
0x3034646625092034ull,0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,
0x090a300933393109ull,0x203233732e627573ull,0x25202c3932722509ull,0x0a3b35202c363172ull,
0x3233752e766f6d09ull,0x202c303372250920ull,0x70746573090a3b30ull,0x203233732e656c2eull,
0x25202c3331702509ull,0x337225202c393272ull,0x31702540090a3b30ull,0x2409206172622033ull,
0x333938325f335f4cull,0x6c3c2f2f200a3b30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x373939315f335f74ull,0x662e6c756d090a30ull,0x3264662509203436ull,0x3131646625202c30ull,
0x3b3131646625202cull,0x36662e646461090aull,0x3134646625092034ull,0x2c3032646625202cull,
0x0a3b303464662520ull,0x3436662e766f6d09ull,0x2c32346466250920ull,0x3030313034643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,
0x6625202c34317025ull,0x646625202c313464ull,0x252140090a3b3234ull,0x2061726220343170ull,
0x38325f335f4c2409ull,0x5f4c240a3b343736ull,0x3a30333938325f33ull,0x33732e766f6d090aull,
0x2c30327225092032ull,0x090a3b3932722520ull,0x20696e752e617262ull,0x325f335f744c2409ull,
0x335f4c240a3b3835ull,0x0a3a34373638325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,
0x335f744c24206465ull,0x090a30373939315full,0x09353109636f6c2eull,0x6d090a3009323032ull,
0x09203436662e6c75ull,0x25202c3631646625ull,0x6625202c31316466ull,0x6461090a3b303164ull,
0x2509203436662e64ull,0x6625202c33346466ull,0x646625202c363164ull,0x646461090a3b3631ull,
0x662509203436662eull,0x646625202c303164ull,0x3334646625202c39ull,0x09636f6c2e090a3bull,
0x3009333032093531ull,0x36662e627573090aull,0x3434646625092034ull,0x2c3032646625202cull,
0x0a3b303464662520ull,0x3436662e64646109ull,0x2c31316466250920ull,0x25202c3864662520ull,
0x2e090a3b34346466ull,0x3209353109636f6cull,0x756d090a30093430ull,0x2509203436662e6cull,
0x6625202c35346466ull,0x646625202c303164ull,0x6f6c2e090a3b3031ull,0x3230320935310963ull,
0x2e627573090a3009ull,0x3372250920323373ull,0x2c36317225202c31ull,0x766f6d090a3b3620ull,
0x722509203233752eull,0x090a3b30202c3233ull,0x2e656c2e70746573ull,0x3170250920323373ull,
0x2c31337225202c35ull,0x090a3b3233722520ull,0x7262203531702540ull,0x5f335f4c24092061ull,
0x200a3b3234343932ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,0x5f335f744c242064ull,
0x6d090a3037393931ull,0x09203436662e6c75ull,0x25202c3032646625ull,0x6625202c31316466ull,
0x6461090a3b313164ull,0x2509203436662e64ull,0x6625202c36346466ull,0x646625202c303264ull,
0x766f6d090a3b3534ull,0x662509203436662eull,0x346430202c373464ull,0x3030303030303130ull,
0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3631702509203436ull,
0x2c3634646625202cull,0x0a3b373464662520ull,0x2036317025214009ull,0x5f4c240920617262ull,
0x3b36383139325f33ull,0x39325f335f4c240aull,0x6f6d090a3a323434ull,0x2509203233732e76ull,
0x337225202c303272ull,0x2e617262090a3b31ull,0x744c240920696e75ull,0x0a3b3835325f335full,
0x3139325f335f4c24ull,0x3c2f2f200a3a3638ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3939315f335f744cull,0x636f6c2e090a3037ull,0x0931313209353109ull,0x662e6c756d090a30ull,
0x3164662509203436ull,0x3131646625202c36ull,0x3b3031646625202cull,0x36662e646461090aull,
0x3834646625092034ull,0x2c3631646625202cull,0x0a3b363164662520ull,0x3436662e64646109ull,
0x2c30316466250920ull,0x25202c3964662520ull,0x2e090a3b38346466ull,0x3209353109636f6cull,
0x7573090a30093231ull,0x2509203436662e62ull,0x6625202c39346466ull,0x646625202c303264ull,
0x646461090a3b3534ull,0x662509203436662eull,0x646625202c313164ull,0x3934646625202c38ull,
0x09636f6c2e090a3bull,0x3009333132093531ull,0x36662e6c756d090aull,0x3035646625092034ull,
0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,0x090a300931313209ull,
0x203233732e627573ull,0x25202c3333722509ull,0x0a3b37202c363172ull,0x3233752e766f6d09ull,
0x202c343372250920ull,0x70746573090a3b30ull,0x203233732e656c2eull,0x25202c3731702509ull,
0x337225202c333372ull,0x31702540090a3b34ull,0x2409206172622037ull,0x353939325f335f4cull,
0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x373939315f335f74ull,
0x662e6c756d090a30ull,0x3264662509203436ull,0x3131646625202c30ull,0x3b3131646625202cull,
0x36662e646461090aull,0x3135646625092034ull,0x2c3032646625202cull,0x0a3b303564662520ull,
0x3436662e766f6d09ull,0x2c32356466250920ull,0x3030313034643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,0x6625202c38317025ull,
0x646625202c313564ull,0x252140090a3b3235ull,0x2061726220383170ull,0x39325f335f4c2409ull,
0x5f4c240a3b383936ull,0x3a34353939325f33ull,0x33732e766f6d090aull,0x2c30327225092032ull,
0x090a3b3333722520ull,0x20696e752e617262ull,0x325f335f744c2409ull,0x335f4c240a3b3835ull,
0x0a3a38393639325full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,0x335f744c24206465ull,
0x090a30373939315full,0x09353109636f6c2eull,0x6d090a3009303232ull,0x09203436662e6c75ull,
0x25202c3631646625ull,0x6625202c31316466ull,0x6461090a3b303164ull,0x2509203436662e64ull,
0x6625202c33356466ull,0x646625202c363164ull,0x646461090a3b3631ull,0x662509203436662eull,
0x646625202c303164ull,0x3335646625202c39ull,0x09636f6c2e090a3bull,0x3009313232093531ull,
0x36662e627573090aull,0x3435646625092034ull,0x2c3032646625202cull,0x0a3b303564662520ull,
0x3436662e64646109ull,0x2c31316466250920ull,0x25202c3864662520ull,0x2e090a3b34356466ull,
0x3209353109636f6cull,0x756d090a30093232ull,0x2509203436662e6cull,0x6625202c35356466ull,
0x646625202c303164ull,0x6f6c2e090a3b3031ull,0x3032320935310963ull,0x2e627573090a3009ull,
0x3372250920323373ull,0x2c36317225202c35ull,0x766f6d090a3b3820ull,0x722509203233752eull,
0x090a3b30202c3633ull,0x2e656c2e70746573ull,0x3170250920323373ull,0x2c35337225202c39ull,
0x090a3b3633722520ull,0x7262203931702540ull,0x5f335f4c24092061ull,0x200a3b3636343033ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353531ull,0x656c6562616c2064ull,0x5f335f744c242064ull,0x6d090a3037393931ull,
0x09203436662e6c75ull,0x25202c3032646625ull,0x6625202c31316466ull,0x6461090a3b313164ull,
0x2509203436662e64ull,0x6625202c36356466ull,0x646625202c303264ull,0x766f6d090a3b3535ull,
0x662509203436662eull,0x346430202c373564ull,0x3030303030303130ull,0x3b30303030303030ull,
0x73090a34202f2f09ull,0x662e74672e707465ull,0x3032702509203436ull,0x2c3635646625202cull,
0x0a3b373564662520ull,0x2030327025214009ull,0x5f4c240920617262ull,0x3b30313230335f33ull,
0x30335f335f4c240aull,0x6f6d090a3a363634ull,0x2509203233732e76ull,0x337225202c303272ull,
0x2e617262090a3b35ull,0x744c240920696e75ull,0x0a3b3835325f335full,0x3230335f335f4c24ull,
0x3c2f2f200a3a3031ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3939315f335f744cull,
0x636f6c2e090a3037ull,0x0939323209353109ull,0x662e6c756d090a30ull,0x3164662509203436ull,
0x3131646625202c36ull,0x3b3031646625202cull,0x36662e646461090aull,0x3835646625092034ull,
0x2c3631646625202cull,0x0a3b363164662520ull,0x3436662e64646109ull,0x2c30316466250920ull,
0x25202c3964662520ull,0x2e090a3b38356466ull,0x3209353109636f6cull,0x7573090a30093033ull,
0x2509203436662e62ull,0x6625202c39356466ull,0x646625202c303264ull,0x646461090a3b3535ull,
0x662509203436662eull,0x646625202c313164ull,0x3935646625202c38ull,0x09636f6c2e090a3bull,
0x3009313332093531ull,0x36662e6c756d090aull,0x3036646625092034ull,0x2c3031646625202cull,
0x0a3b303164662520ull,0x353109636f6c2e09ull,0x090a300939323209ull,0x203233732e627573ull,
0x25202c3733722509ull,0x0a3b39202c363172ull,0x3233752e766f6d09ull,0x202c383372250920ull,
0x70746573090a3b30ull,0x203233732e656c2eull,0x25202c3132702509ull,0x337225202c373372ull,
0x32702540090a3b38ull,0x2409206172622031ull,0x373930335f335f4cull,0x6c3c2f2f200a3b38ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x373939315f335f74ull,0x662e6c756d090a30ull,
0x3264662509203436ull,0x3131646625202c30ull,0x3b3131646625202cull,0x36662e646461090aull,
0x3136646625092034ull,0x2c3032646625202cull,0x0a3b303664662520ull,0x3436662e766f6d09ull,
0x2c32366466250920ull,0x3030313034643020ull,0x3030303030303030ull,0x202f2f093b303030ull,
0x2e70746573090a34ull,0x09203436662e7467ull,0x6625202c32327025ull,0x646625202c313664ull,
0x252140090a3b3236ull,0x2061726220323270ull,0x30335f335f4c2409ull,0x5f4c240a3b323237ull,
0x3a38373930335f33ull,0x33732e766f6d090aull,0x2c30327225092032ull,0x090a3b3733722520ull,
0x20696e752e617262ull,0x325f335f744c2409ull,0x335f4c240a3b3835ull,0x0a3a32323730335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x335f744c24206465ull,0x090a30373939315full,
0x09353109636f6c2eull,0x6d090a3009383332ull,0x09203436662e6c75ull,0x25202c3631646625ull,
0x6625202c31316466ull,0x6461090a3b303164ull,0x2509203436662e64ull,0x6625202c33366466ull,
0x646625202c363164ull,0x646461090a3b3631ull,0x662509203436662eull,0x646625202c303164ull,
0x3336646625202c39ull,0x09636f6c2e090a3bull,0x3009393332093531ull,0x36662e627573090aull,
0x3436646625092034ull,0x2c3032646625202cull,0x0a3b303664662520ull,0x3436662e64646109ull,
0x2c31316466250920ull,0x25202c3864662520ull,0x2e090a3b34366466ull,0x3209353109636f6cull,
0x756d090a30093034ull,0x2509203436662e6cull,0x6625202c35366466ull,0x646625202c303164ull,
0x6f6c2e090a3b3031ull,0x3833320935310963ull,0x2e627573090a3009ull,0x3372250920323373ull,
0x2c36317225202c39ull,0x6f6d090a3b303120ull,0x2509203233752e76ull,0x0a3b30202c303472ull,
0x656c2e7074657309ull,0x702509203233732eull,0x39337225202c3332ull,0x0a3b30347225202cull,
0x6220333270254009ull,0x335f4c2409206172ull,0x0a3b30393431335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x335f744c24206465ull,0x090a30373939315full,0x203436662e6c756dull,
0x202c303264662509ull,0x25202c3131646625ull,0x61090a3b31316466ull,0x09203436662e6464ull,
0x25202c3636646625ull,0x6625202c30326466ull,0x6f6d090a3b353664ull,0x2509203436662e76ull,
0x6430202c37366466ull,0x3030303030313034ull,0x3030303030303030ull,0x090a34202f2f093bull,
0x2e74672e70746573ull,0x3270250920343666ull,0x3636646625202c34ull,0x3b3736646625202cull,
0x343270252140090aull,0x4c24092061726220ull,0x34333231335f335full,0x335f335f4c240a3bull,
0x6d090a3a30393431ull,0x09203233732e766full,0x7225202c30327225ull,0x617262090a3b3933ull,
0x4c240920696e752eull,0x3b3835325f335f74ull,0x31335f335f4c240aull,0x2f2f200a3a343332ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x39315f335f744c24ull,0x6f6c2e090a303739ull,
0x3734320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3631ull,
0x3031646625202c31ull,0x662e646461090a3bull,0x3664662509203436ull,0x3631646625202c38ull,
0x3b3631646625202cull,0x36662e646461090aull,0x3031646625092034ull,0x202c39646625202cull,
0x090a3b3836646625ull,0x09353109636f6c2eull,0x73090a3009383432ull,0x09203436662e6275ull,
0x25202c3936646625ull,0x6625202c30326466ull,0x6461090a3b353664ull,0x2509203436662e64ull,
0x6625202c31316466ull,0x36646625202c3864ull,0x636f6c2e090a3b39ull,0x0939343209353109ull,
0x662e6c756d090a30ull,0x3764662509203436ull,0x3031646625202c30ull,0x3b3031646625202cull,
0x3109636f6c2e090aull,0x0a30093734320935ull,0x3233732e62757309ull,0x202c313472250920ull,
0x3131202c36317225ull,0x752e766f6d090a3bull,0x3234722509203233ull,0x6573090a3b30202cull,
0x33732e656c2e7074ull,0x2c35327025092032ull,0x25202c3134722520ull,0x2540090a3b323472ull,
0x2061726220353270ull,0x32335f335f4c2409ull,0x2f2f200a3b323030ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,
0x2064656c6562616cull,0x39315f335f744c24ull,0x6c756d090a303739ull,0x662509203436662eull,
0x646625202c303264ull,0x31646625202c3131ull,0x2e646461090a3b31ull,0x6466250920343666ull,
0x32646625202c3137ull,0x3037646625202c30ull,0x662e766f6d090a3bull,0x3764662509203436ull,
0x3130346430202c32ull,0x3030303030303030ull,0x2f093b3030303030ull,0x746573090a34202full,
0x3436662e74672e70ull,0x202c363270250920ull,0x25202c3137646625ull,0x40090a3b32376466ull,
0x7262203632702521ull,0x5f335f4c24092061ull,0x240a3b3634373133ull,0x303032335f335f4cull,
0x2e766f6d090a3a32ull,0x3272250920323373ull,0x3b31347225202c30ull,0x6e752e617262090aull,
0x335f744c24092069ull,0x4c240a3b3835325full,0x36343731335f335full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x30373939315f335full,0x3109636f6c2e090aull,
0x0a30093635320935ull,0x3436662e6c756d09ull,0x2c36316466250920ull,0x202c313164662520ull,
0x090a3b3031646625ull,0x203436662e646461ull,0x202c333764662509ull,0x25202c3631646625ull,
0x61090a3b36316466ull,0x09203436662e6464ull,0x25202c3031646625ull,0x646625202c396466ull,
0x6f6c2e090a3b3337ull,0x3735320935310963ull,0x2e627573090a3009ull,0x6466250920343666ull,
0x32646625202c3437ull,0x3037646625202c30ull,0x662e646461090a3bull,0x3164662509203436ull,
0x2c38646625202c31ull,0x0a3b343764662520ull,0x353109636f6c2e09ull,0x090a300938353209ull,
0x203436662e6c756dull,0x202c353764662509ull,0x25202c3031646625ull,0x2e090a3b30316466ull,
0x3209353109636f6cull,0x7573090a30093635ull,0x2509203233732e62ull,0x317225202c333472ull,
0x090a3b3231202c36ull,0x203233752e766f6dull,0x30202c3434722509ull,0x2e70746573090a3bull,
0x09203233732e656cull,0x7225202c37327025ull,0x34347225202c3334ull,0x3732702540090a3bull,
0x4c24092061726220ull,0x34313532335f335full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x30373939315f335full,0x36662e6c756d090aull,0x3032646625092034ull,
0x2c3131646625202cull,0x0a3b313164662520ull,0x3436662e64646109ull,0x2c36376466250920ull,
0x202c303264662520ull,0x090a3b3537646625ull,0x203436662e766f6dull,0x202c373764662509ull,
0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,0x672e70746573090aull,
0x2509203436662e74ull,0x646625202c383270ull,0x37646625202c3637ull,0x70252140090a3b37ull,
0x0920617262203832ull,0x3232335f335f4c24ull,0x335f4c240a3b3835ull,0x0a3a34313532335full,
0x3233732e766f6d09ull,0x202c303272250920ull,0x62090a3b33347225ull,0x0920696e752e6172ull,
0x35325f335f744c24ull,0x5f335f4c240a3b38ull,0x200a3a3835323233ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,
0x656c6562616c2064ull,0x5f335f744c242064ull,0x2e090a3037393931ull,0x3209353109636f6cull,
0x756d090a30093536ull,0x2509203436662e6cull,0x6625202c36316466ull,0x646625202c313164ull,
0x646461090a3b3031ull,0x662509203436662eull,0x646625202c383764ull,0x31646625202c3631ull,
0x2e646461090a3b36ull,0x6466250920343666ull,0x39646625202c3031ull,0x3b3837646625202cull,
0x3109636f6c2e090aull,0x0a30093636320935ull,0x3436662e62757309ull,0x2c39376466250920ull,
0x202c303264662520ull,0x090a3b3537646625ull,0x203436662e646461ull,0x202c313164662509ull,
0x6625202c38646625ull,0x6c2e090a3b393764ull,0x363209353109636full,0x6c756d090a300937ull,
0x662509203436662eull,0x646625202c303864ull,0x31646625202c3031ull,0x636f6c2e090a3b30ull,
0x0935363209353109ull,0x732e627573090a30ull,0x3534722509203233ull,0x202c36317225202cull,
0x766f6d090a3b3331ull,0x722509203233752eull,0x090a3b30202c3634ull,0x2e656c2e70746573ull,
0x3270250920323373ull,0x2c35347225202c39ull,0x090a3b3634722520ull,0x7262203932702540ull,
0x5f335f4c24092061ull,0x200a3b3632303333ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,
0x5f335f744c242064ull,0x6d090a3037393931ull,0x09203436662e6c75ull,0x25202c3032646625ull,
0x6625202c31316466ull,0x6461090a3b313164ull,0x2509203436662e64ull,0x6625202c31386466ull,
0x646625202c303264ull,0x766f6d090a3b3038ull,0x662509203436662eull,0x346430202c323864ull,
0x3030303030303130ull,0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3033702509203436ull,0x2c3138646625202cull,0x0a3b323864662520ull,0x2030337025214009ull,
0x5f4c240920617262ull,0x3b30373732335f33ull,0x33335f335f4c240aull,0x6f6d090a3a363230ull,
0x2509203233732e76ull,0x347225202c303272ull,0x2e617262090a3b35ull,0x744c240920696e75ull,
0x0a3b3835325f335full,0x3732335f335f4c24ull,0x3c2f2f200a3a3037ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3939315f335f744cull,0x636f6c2e090a3037ull,0x0934373209353109ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x3131646625202c36ull,0x3b3031646625202cull,
0x36662e646461090aull,0x3338646625092034ull,0x2c3631646625202cull,0x0a3b363164662520ull,
0x3436662e64646109ull,0x2c30316466250920ull,0x25202c3964662520ull,0x2e090a3b33386466ull,
0x3209353109636f6cull,0x7573090a30093537ull,0x2509203436662e62ull,0x6625202c34386466ull,
0x646625202c303264ull,0x646461090a3b3038ull,0x662509203436662eull,0x646625202c313164ull,
0x3438646625202c38ull,0x09636f6c2e090a3bull,0x3009363732093531ull,0x36662e6c756d090aull,
0x3538646625092034ull,0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,
0x090a300934373209ull,0x203233732e627573ull,0x25202c3734722509ull,0x3b3431202c363172ull,
0x33752e766f6d090aull,0x2c38347225092032ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,
0x202c313370250920ull,0x7225202c37347225ull,0x702540090a3b3834ull,0x0920617262203133ull,
0x3533335f335f4c24ull,0x3c2f2f200a3b3833ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3939315f335f744cull,0x2e6c756d090a3037ull,0x6466250920343666ull,0x31646625202c3032ull,
0x3131646625202c31ull,0x662e646461090a3bull,0x3864662509203436ull,0x3032646625202c36ull,
0x3b3538646625202cull,0x36662e766f6d090aull,0x3738646625092034ull,0x303130346430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3420ull,0x203436662e74672eull,
0x25202c3233702509ull,0x6625202c36386466ull,0x2140090a3b373864ull,0x6172622032337025ull,
0x335f335f4c240920ull,0x4c240a3b32383233ull,0x38333533335f335full,0x732e766f6d090a3aull,
0x3032722509203233ull,0x0a3b37347225202cull,0x696e752e61726209ull,0x5f335f744c240920ull,
0x5f4c240a3b383532ull,0x3a32383233335f33ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a30373939315f33ull,0x353109636f6c2e09ull,0x090a300933383209ull,
0x203436662e6c756dull,0x202c363164662509ull,0x25202c3131646625ull,0x61090a3b30316466ull,
0x09203436662e6464ull,0x25202c3838646625ull,0x6625202c36316466ull,0x6461090a3b363164ull,
0x2509203436662e64ull,0x6625202c30316466ull,0x38646625202c3964ull,0x636f6c2e090a3b38ull,
0x0934383209353109ull,0x662e627573090a30ull,0x3864662509203436ull,0x3032646625202c39ull,
0x3b3538646625202cull,0x36662e646461090aull,0x3131646625092034ull,0x202c38646625202cull,
0x090a3b3938646625ull,0x09353109636f6c2eull,0x6d090a3009353832ull,0x09203436662e6c75ull,
0x25202c3039646625ull,0x6625202c30316466ull,0x6c2e090a3b303164ull,0x383209353109636full,
0x627573090a300933ull,0x722509203233732eull,0x36317225202c3934ull,0x6d090a3b3531202cull,
0x09203233752e766full,0x3b30202c30357225ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x347225202c333370ull,0x3b30357225202c39ull,0x203333702540090aull,0x5f4c240920617262ull,
0x3b30353034335f33ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a30373939315f33ull,0x3436662e6c756d09ull,0x2c30326466250920ull,0x202c313164662520ull,
0x090a3b3131646625ull,0x203436662e646461ull,0x202c313964662509ull,0x25202c3032646625ull,
0x6d090a3b30396466ull,0x09203436662e766full,0x30202c3239646625ull,0x3030303031303464ull,
0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,
0x39646625202c3433ull,0x3239646625202c31ull,0x3370252140090a3bull,0x2409206172622034ull,
0x393733335f335f4cull,0x5f335f4c240a3b34ull,0x090a3a3035303433ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b393472ull,0x240920696e752e61ull,0x3835325f335f744cull,
0x335f335f4c240a3bull,0x2f200a3a34393733ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f335f744c2420ull,0x6c2e090a30373939ull,0x393209353109636full,0x6c756d090a300932ull,
0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,0x2e646461090a3b30ull,
0x6466250920343666ull,0x31646625202c3339ull,0x3631646625202c36ull,0x662e646461090a3bull,
0x3164662509203436ull,0x2c39646625202c30ull,0x0a3b333964662520ull,0x353109636f6c2e09ull,
0x090a300933393209ull,0x203436662e627573ull,0x202c343964662509ull,0x25202c3032646625ull,
0x61090a3b30396466ull,0x09203436662e6464ull,0x25202c3131646625ull,0x646625202c386466ull,
0x6f6c2e090a3b3439ull,0x3439320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x31646625202c3539ull,0x3031646625202c30ull,0x09636f6c2e090a3bull,0x3009323932093531ull,
0x33732e627573090aull,0x2c31357225092032ull,0x31202c3631722520ull,0x2e766f6d090a3b36ull,
0x3572250920323375ull,0x73090a3b30202c32ull,0x732e656c2e707465ull,0x3533702509203233ull,
0x202c31357225202cull,0x40090a3b32357225ull,0x6172622035337025ull,0x335f335f4c240920ull,
0x2f200a3b32363534ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x315f335f744c2420ull,
0x756d090a30373939ull,0x2509203436662e6cull,0x6625202c30326466ull,0x646625202c313164ull,
0x646461090a3b3131ull,0x662509203436662eull,0x646625202c363964ull,0x39646625202c3032ull,
0x2e766f6d090a3b35ull,0x6466250920343666ull,0x30346430202c3739ull,0x3030303030303031ull,
0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,0x2c36337025092034ull,
0x202c363964662520ull,0x090a3b3739646625ull,0x6220363370252140ull,0x335f4c2409206172ull,
0x0a3b36303334335full,0x3534335f335f4c24ull,0x766f6d090a3a3236ull,0x722509203233732eull,
0x31357225202c3032ull,0x752e617262090a3bull,0x5f744c240920696eull,0x240a3b3835325f33ull,
0x303334335f335f4cull,0x6c3c2f2f200a3a36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x373939315f335f74ull,0x09636f6c2e090a30ull,0x3009313033093531ull,0x36662e6c756d090aull,
0x3631646625092034ull,0x2c3131646625202cull,0x0a3b303164662520ull,0x3436662e64646109ull,
0x2c38396466250920ull,0x202c363164662520ull,0x090a3b3631646625ull,0x203436662e646461ull,
0x202c303164662509ull,0x6625202c39646625ull,0x6c2e090a3b383964ull,0x303309353109636full,
0x627573090a300932ull,0x662509203436662eull,0x646625202c393964ull,0x39646625202c3032ull,
0x2e646461090a3b35ull,0x6466250920343666ull,0x38646625202c3131ull,0x3b3939646625202cull,
0x3109636f6c2e090aull,0x0a30093330330935ull,0x3436662e6c756d09ull,0x3030316466250920ull,
0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,0x090a300931303309ull,
0x203233732e627573ull,0x25202c3335722509ull,0x3b3731202c363172ull,0x33752e766f6d090aull,
0x2c34357225092032ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c373370250920ull,
0x7225202c33357225ull,0x702540090a3b3435ull,0x0920617262203733ull,0x3035335f335f4c24ull,
0x3c2f2f200a3b3437ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3939315f335f744cull,
0x2e6c756d090a3037ull,0x6466250920343666ull,0x31646625202c3032ull,0x3131646625202c31ull,
0x662e646461090a3bull,0x3164662509203436ull,0x32646625202c3130ull,0x3031646625202c30ull,
0x2e766f6d090a3b30ull,0x6466250920343666ull,0x346430202c323031ull,0x3030303030303130ull,
0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3833702509203436ull,
0x313031646625202cull,0x323031646625202cull,0x3370252140090a3bull,0x2409206172622038ull,
0x313834335f335f4cull,0x5f335f4c240a3b38ull,0x090a3a3437303533ull,0x203233732e766f6dull,
0x25202c3032722509ull,0x7262090a3b333572ull,0x240920696e752e61ull,0x3835325f335f744cull,
0x335f335f4c240a3bull,0x2f200a3a38313834ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x315f335f744c2420ull,0x6c2e090a30373939ull,0x313309353109636full,0x6c756d090a300930ull,
0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,0x2e646461090a3b30ull,
0x6466250920343666ull,0x646625202c333031ull,0x31646625202c3631ull,0x2e646461090a3b36ull,
0x6466250920343666ull,0x39646625202c3031ull,0x333031646625202cull,0x09636f6c2e090a3bull,
0x3009313133093531ull,0x36662e627573090aull,0x3031646625092034ull,0x3032646625202c34ull,
0x303031646625202cull,0x662e646461090a3bull,0x3164662509203436ull,0x2c38646625202c31ull,
0x3b34303164662520ull,0x3109636f6c2e090aull,0x0a30093231330935ull,0x3436662e6c756d09ull,
0x3530316466250920ull,0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,
0x090a300930313309ull,0x203233732e627573ull,0x25202c3535722509ull,0x3b3831202c363172ull,
0x33752e766f6d090aull,0x2c36357225092032ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,
0x202c393370250920ull,0x7225202c35357225ull,0x702540090a3b3635ull,0x0920617262203933ull,
0x3535335f335f4c24ull,0x3c2f2f200a3b3638ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3939315f335f744cull,0x2e6c756d090a3037ull,0x6466250920343666ull,0x31646625202c3032ull,
0x3131646625202c31ull,0x662e646461090a3bull,0x3164662509203436ull,0x32646625202c3630ull,
0x3031646625202c30ull,0x2e766f6d090a3b35ull,0x6466250920343666ull,0x346430202c373031ull,
0x3030303030303130ull,0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3034702509203436ull,0x363031646625202cull,0x373031646625202cull,0x3470252140090a3bull,
0x2409206172622030ull,0x333335335f335f4cull,0x5f335f4c240a3b30ull,0x090a3a3638353533ull,
0x203233732e766f6dull,0x25202c3032722509ull,0x7262090a3b353572ull,0x240920696e752e61ull,
0x3835325f335f744cull,0x335f335f4c240a3bull,0x2f200a3a30333335ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x315f335f744c2420ull,0x6c2e090a30373939ull,0x313309353109636full,
0x6c756d090a300939ull,0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,
0x2e646461090a3b30ull,0x6466250920343666ull,0x646625202c383031ull,0x31646625202c3631ull,
0x2e646461090a3b36ull,0x6466250920343666ull,0x39646625202c3031ull,0x383031646625202cull,
0x09636f6c2e090a3bull,0x3009303233093531ull,0x36662e627573090aull,0x3031646625092034ull,
0x3032646625202c39ull,0x353031646625202cull,0x662e646461090a3bull,0x3164662509203436ull,
0x2c38646625202c31ull,0x3b39303164662520ull,0x3109636f6c2e090aull,0x0a30093132330935ull,
0x3436662e6c756d09ull,0x3031316466250920ull,0x2c3031646625202cull,0x0a3b303164662520ull,
0x353109636f6c2e09ull,0x090a300935323309ull,0x203233732e627573ull,0x25202c3631722509ull,
0x3b3931202c363172ull,0x3109636f6c2e090aull,0x0a30093931330935ull,0x3233732e766f6d09ull,
0x202c373572250920ull,0x70746573090a3b30ull,0x203233732e656c2eull,0x7225202c33702509ull,
0x37357225202c3631ull,0x2033702540090a3bull,0x5f4c240920617262ull,0x3b38393036335f33ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a30373939315f33ull,
0x3436662e6c756d09ull,0x2c30326466250920ull,0x202c313164662520ull,0x090a3b3131646625ull,
0x203436662e646461ull,0x2c31313164662509ull,0x202c303264662520ull,0x0a3b303131646625ull,
0x3436662e766f6d09ull,0x3231316466250920ull,0x303130346430202cull,0x3030303030303030ull,
0x2f2f093b30303030ull,0x70746573090a3420ull,0x203436662e74672eull,0x25202c3134702509ull,
0x25202c3131316466ull,0x090a3b3231316466ull,0x6220313470252140ull,0x335f4c2409206172ull,
0x0a3b32343835335full,0x3036335f335f4c24ull,0x766f6d090a3a3839ull,0x722509203233732eull,
0x36317225202c3032ull,0x752e617262090a3bull,0x5f744c240920696eull,0x240a3b3835325f33ull,
0x343835335f335f4cull,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x373939315f335f74ull,0x09636f6c2e090a30ull,0x3009383233093531ull,0x36662e6c756d090aull,
0x3631646625092034ull,0x2c3131646625202cull,0x0a3b303164662520ull,0x3436662e64646109ull,
0x3331316466250920ull,0x2c3631646625202cull,0x0a3b363164662520ull,0x3436662e64646109ull,
0x2c30316466250920ull,0x25202c3964662520ull,0x090a3b3331316466ull,0x09353109636f6c2eull,
0x73090a3009393233ull,0x09203436662e6275ull,0x202c343131646625ull,0x25202c3032646625ull,
0x090a3b3031316466ull,0x203436662e646461ull,0x202c313164662509ull,0x6625202c38646625ull,
0x2e090a3b34313164ull,0x3309353109636f6cull,0x756d090a30093033ull,0x2509203436662e6cull,
0x6625202c32316466ull,0x646625202c303164ull,0x6f6c2e090a3b3031ull,0x3133330935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3331ull,0x3131646625202c31ull,
0x09636f6c2e090a3bull,0x3009383233093531ull,0x6e752e617262090aull,0x335f744c24092069ull,
0x0a3b30373939315full,0x35325f335f744c24ull,0x636f6c2e090a3a38ull,0x3009313209363109ull,
0x33732e766f6d090aull,0x2c38357225092032ull,0x746573090a3b3020ull,0x3233732e74672e70ull,
0x202c323470250920ull,0x7225202c30327225ull,0x627573090a3b3835ull,0x722509203233732eull,
0x35317225202c3935ull,0x0a3b30327225202cull,0x3233732e766f6d09ull,0x202c303672250920ull,
0x706c6573090a3b30ull,0x722509203233732eull,0x39357225202c3136ull,0x202c30367225202cull,
0x6d090a3b32347025ull,0x09203233752e766full,0x3b30202c32367225ull,0x652e70746573090aull,
0x2509203233732e71ull,0x367225202c333470ull,0x3b32367225202c31ull,0x203334702540090aull,
0x744c240920617262ull,0x34333637335f335full,0x09636f6c2e090a3bull,0x0a30093832093631ull,
0x617261702e646c09ull,0x2509203233732e6dull,0x5f5f5b202c333672ull,0x6d72617061647563ull,
0x6e614d36315a5f5full,0x30746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,0x6974616d696e615full,
0x5d656d6172466e6full,0x732e646461090a3bull,0x3436722509203233ull,0x202c33367225202cull,
0x6c090a3b31367225ull,0x2e6d617261702e64ull,0x3536722509203875ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f30746f7262ull,0x3650764564493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x6f635f6269695f30ull,
0x3b5d302b73726f6cull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x34367225202c3636ull,
0x0a3b35367225202cull,0x2e38752e74766309ull,0x3672250920323375ull,0x3b36367225202c37ull,
0x3109636f6c2e090aull,0x090a300939320936ull,0x6d617261702e646cull,0x367225092038752eull,
0x75635f5f5b202c38ull,0x5f5f6d7261706164ull,0x65646e614d36315aull,0x735f30746f72626cull,
0x507645644930316dull,0x6934726168637536ull,0x535f32535f546969ull,0x5f32535f32535f32ull,
0x635f6269695f3053ull,0x5d312b73726f6c6full,0x6c2e6c756d090a3bull,0x2509203233732e6full,
0x367225202c393672ull,0x3b38367225202c34ull,0x38752e747663090aull,0x722509203233752eull,
0x39367225202c3037ull,0x09636f6c2e090a3bull,0x0a30093033093631ull,0x617261702e646c09ull,
0x7225092038752e6dull,0x635f5f5b202c3137ull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f30746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x32535f32535f3253ull,0x5f6269695f30535full,0x322b73726f6c6f63ull,0x2e6c756d090a3b5dull,
0x09203233732e6f6cull,0x7225202c32377225ull,0x31377225202c3436ull,0x752e747663090a3bull,
0x2509203233752e38ull,0x377225202c333772ull,0x2e617262090a3b32ull,0x744c240920696e75ull,
0x38373337335f335full,0x5f335f744c240a3bull,0x090a3a3433363733ull,0x09363109636f6c2eull,
0x6f6d090a30093433ull,0x2509203233752e76ull,0x0a3b30202c333772ull,0x3233752e766f6d09ull,
0x202c303772250920ull,0x2e766f6d090a3b30ull,0x3672250920323375ull,0x4c240a3b30202c37ull,
0x373337335f335f74ull,0x702e646c090a3a38ull,0x3436752e6d617261ull,0x202c316472250920ull,
0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f30746full,
0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,
0x5d7473645f626969ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,0x377225202c343772ull,
0x090a3b367225202cull,0x203233732e646461ull,0x25202c3537722509ull,0x34377225202c3472ull,
0x752e747663090a3bull,0x09203233732e3436ull,0x7225202c32647225ull,0x6c756d090a3b3537ull,
0x203436752e6f6c2eull,0x25202c3364722509ull,0x0a3b34202c326472ull,0x3436752e64646109ull,
0x202c346472250920ull,0x7225202c31647225ull,0x2e646c090a3b3364ull,0x33732e6d61726170ull,
0x2c36377225092032ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f30746f72ull,0x7536507645644930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x30535f32535f3253ull,0x6172665f6269695full,0x6f6d090a3b5d656dull,0x2509203233752e76ull,
0x0a3b30202c373772ull,0x656e2e7074657309ull,0x702509203233732eull,0x36377225202c3434ull,
0x0a3b37377225202cull,0x6220343470254009ull,0x5f744c2409206172ull,0x3b36343138335f33ull,
0x3109636f6c2e090aull,0x090a300931340936ull,0x203233752e766f6dull,0x30202c3837722509ull,
0x6c672e7473090a3bull,0x2e34762e6c61626full,0x6472255b09203875ull,0x257b202c5d302b34ull,
0x303772252c373672ull,0x72252c333772252cull,0x7262090a3b7d3837ull,0x240920696e752e61ull,
0x3837335f335f744cull,0x5f744c240a3b3039ull,0x3a36343138335f33ull,0x3109636f6c2e090aull,
0x090a300935340936ull,0x203233732e646461ull,0x25202c3937722509ull,0x0a3b31202c363772ull,
0x3233732e72687309ull,0x202c303872250920ull,0x3133202c39377225ull,0x732e766f6d090a3bull,
0x3138722509203233ull,0x6e61090a3b31202cull,0x2509203233622e64ull,0x387225202c323872ull,
0x3b31387225202c30ull,0x33732e646461090aull,0x2c33387225092032ull,0x25202c3238722520ull,
0x6873090a3b393772ull,0x2509203233732e72ull,0x387225202c343872ull,0x6c090a3b31202c33ull,
0x6c61626f6c672e64ull,0x092038752e34762eull,0x72252c353872257bull,0x2c373872252c3638ull,
0x6472255b202c7d5full,0x6d090a3b5d302b34ull,0x33732e6f6c2e6c75ull,0x2c38387225092032ull,
0x25202c3637722520ull,0x6461090a3b353872ull,0x2509203233732e64ull,0x367225202c393872ull,
0x3b38387225202c37ull,0x33732e646461090aull,0x2c30397225092032ull,0x25202c3438722520ull,
0x6964090a3b393872ull,0x2509203233732e76ull,0x397225202c313972ull,0x3b39377225202c30ull,
0x3109636f6c2e090aull,0x090a300936340936ull,0x732e6f6c2e6c756dull,0x3239722509203233ull,
0x202c36377225202cull,0x61090a3b36387225ull,0x09203233732e6464ull,0x7225202c33397225ull,
0x32397225202c3037ull,0x732e646461090a3bull,0x3439722509203233ull,0x202c34387225202cull,
0x64090a3b33397225ull,0x09203233732e7669ull,0x7225202c35397225ull,0x39377225202c3439ull,
0x6c672e7473090a3bull,0x2e32762e6c61626full,0x6472255b09203875ull,0x257b202c5d302b34ull,
0x353972252c313972ull,0x636f6c2e090a3b7dull,0x3009373409363109ull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x36377225202c3639ull,0x0a3b37387225202cull,0x3233732e64646109ull,
0x202c373972250920ull,0x7225202c33377225ull,0x646461090a3b3639ull,0x722509203233732eull,
0x34387225202c3839ull,0x0a3b37397225202cull,0x3233732e76696409ull,0x202c393972250920ull,
0x7225202c38397225ull,0x2e7473090a3b3937ull,0x752e6c61626f6c67ull,0x346472255b092038ull,
0x397225202c5d322bull,0x335f744c240a3b39ull,0x0a3a30393837335full,0x36335f335f744c24ull,
0x6c2e090a3a343533ull,0x303509363109636full,0x74697865090a3009ull,0x6e6557444c240a3bull,
0x614d36315a5f5f64ull,0x746f72626c65646eull,0x644930316d735f30ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x2f2f207d090a3a62ull,
0x6e614d36315a5f20ull,0x30746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,0x72746e652e090a0aull,
0x614d36315a5f2079ull,0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x702e09090a282062ull,
0x36752e206d617261ull,0x616475635f5f2034ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f31746f72ull,0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x30535f32535f3253ull,0x7473645f6269695full,0x7261702e09090a2cull,0x203233732e206d61ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,
0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,
0x6567616d695f6269ull,0x61702e09090a2c57ull,0x3233732e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x67616d695f626969ull,
0x702e09090a2c4865ull,0x33732e206d617261ull,0x616475635f5f2032ull,0x315a5f5f6d726170ull,
0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645664930ull,0x6969693472616863ull,
0x5f32535f32535f54ull,0x30535f32535f3253ull,0x7572635f6269695full,0x2e09090a2c68636eull,
0x662e206d61726170ull,0x6475635f5f203233ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,
0x6d735f31746f7262ull,0x3650764566493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x535f32535f32535full,0x4f785f6269695f30ull,0x702e09090a2c6666ull,0x33662e206d617261ull,
0x616475635f5f2032ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,0x316d735f31746f72ull,
0x7536507645664930ull,0x6969693472616863ull,0x5f32535f32535f54ull,0x30535f32535f3253ull,
0x664f795f6269695full,0x61702e09090a2c66ull,0x3233662e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x2c504a785f626969ull,
0x617261702e09090aull,0x5f203233662e206dull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f32535f32535f32ull,0x69695f30535f3253ull,0x090a2c504a795f62ull,0x206d617261702e09ull,
0x635f5f203233662eull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x5f6269695f30535full,0x090a2c656c616373ull,0x206d617261702e09ull,0x34206e67696c612eull,
0x635f5f2038622e20ull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,
0x7645664930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x5f6269695f30535full,0x345b73726f6c6f63ull,0x61702e09090a2c5dull,0x3233732e206d6172ull,
0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,
0x6375365076456649ull,0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,
0x6d6172665f626969ull,0x61702e09090a2c65ull,0x3233732e206d6172ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x6d696e615f626969ull,
0x6172466e6f697461ull,0x702e09090a2c656dull,0x38732e206d617261ull,0x70616475635f5f20ull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x294a73695f626969ull,
0x65722e090a7b090aull,0x25203631752e2067ull,0x090a3b3e363c6872ull,0x33752e206765722eull,
0x3638313c72252032ull,0x6765722e090a3b3eull,0x7225203436752e20ull,0x090a3b3e32313c64ull,
0x33662e206765722eull,0x3631313c66252032ull,0x6765722e090a3b3eull,0x2520646572702e20ull,
0x090a3b3e30353c70ull,0x09363109636f6c2eull,0x4c240a3009353031ull,0x36315a5f5f314242ull,
0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,0x5469696934726168ull,
0x535f32535f32535full,0x5f30535f32535f32ull,0x6f6d090a3a626969ull,0x2509203631752e76ull,
0x746325202c316872ull,0x090a3b782e646961ull,0x203631752e766f6dull,0x25202c3268722509ull,
0x0a3b782e6469746eull,0x6469772e6c756d09ull,0x2509203631752e65ull,0x31687225202c3172ull,
0x0a3b32687225202cull,0x3631752e766f6d09ull,0x202c336872250920ull,0x792e646961746325ull,
0x752e766f6d090a3bull,0x3468722509203631ull,0x2e6469746e25202cull,0x2e6c756d090a3b79ull,
0x3631752e65646977ull,0x25202c3272250920ull,0x687225202c336872ull,0x2e747663090a3b34ull,
0x203631752e323375ull,0x7425202c33722509ull,0x61090a3b782e6469ull,0x09203233752e6464ull,
0x337225202c347225ull,0x090a3b317225202cull,0x2e3233752e747663ull,0x3572250920363175ull,
0x792e64697425202cull,0x752e646461090a3bull,0x2c36722509203233ull,0x7225202c35722520ull,
0x702e646c090a3b32ull,0x3233732e6d617261ull,0x5b202c3772250920ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764566ull,
0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,0x6567616d695f6269ull,
0x2e646c090a3b5d48ull,0x33732e6d61726170ull,0x202c387225092032ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x67616d695f626969ull,
0x6573090a3b5d5765ull,0x3233752e74672e74ull,0x722509203233732eull,0x202c377225202c39ull,
0x656e090a3b367225ull,0x2509203233732e67ull,0x397225202c303172ull,0x672e746573090a3bull,
0x33732e3233752e74ull,0x2c31317225092032ull,0x7225202c38722520ull,0x2e67656e090a3b34ull,
0x3172250920323373ull,0x3b31317225202c32ull,0x33622e646e61090aull,0x2c33317225092032ull,
0x25202c3031722520ull,0x6f6d090a3b323172ull,0x2509203233752e76ull,0x0a3b30202c343172ull,
0x71652e7074657309ull,0x702509203233732eull,0x2c33317225202c31ull,0x090a3b3431722520ull,
0x6172622031702540ull,0x5f345f744c240920ull,0x090a3b3232353334ull,0x09363109636f6c2eull,
0x6d090a3009333131ull,0x33732e6f6c2e6c75ull,0x2c35317225092032ull,0x7225202c38722520ull,
0x2e646461090a3b36ull,0x3172250920323373ull,0x202c347225202c36ull,0x6c090a3b35317225ull,
0x2e6d617261702e64ull,0x6472250920343675ull,0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645664930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f32535f32535f32ull,0x645f6269695f3053ull,0x7663090a3b5d7473ull,
0x33732e3436752e74ull,0x2c32647225092032ull,0x090a3b3631722520ull,0x752e6f6c2e6c756dull,
0x3364722509203436ull,0x202c32647225202cull,0x2e646461090a3b34ull,0x6472250920343675ull,
0x2c31647225202c34ull,0x090a3b3364722520ull,0x61626f6c672e646cull,0x2038752e34762e6cull,
0x252c373172257b09ull,0x393172252c383172ull,0x72255b202c7d5f2cull,0x090a3b5d302b3464ull,
0x203233752e766f6dull,0x30202c3032722509ull,0x2e70746573090a3bull,0x09203233732e656cull,
0x347225202c327025ull,0x0a3b30327225202cull,0x7262203270254009ull,0x345f744c24092061ull,
0x0a3b30393234345full,0x626f6c672e646c09ull,0x38752e34762e6c61ull,0x2c313272257b0920ull,
0x3272252c32327225ull,0x255b202c7d5f2c33ull,0x3b5d342d2b346472ull,0x3109636f6c2e090aull,
0x0a30093831310936ull,0x3233732e62757309ull,0x202c343272250920ull,0x7225202c33327225ull,
0x736261090a3b3931ull,0x722509203233732eull,0x34327225202c3532ull,0x732e766f6d090a3bull,
0x3632722509203233ull,0x73090a3b3031202cull,0x33752e74672e7465ull,0x2509203233732e32ull,
0x327225202c373272ull,0x3b36327225202c35ull,0x33732e67656e090aull,0x2c38327225092032ull,
0x090a3b3732722520ull,0x203233732e627573ull,0x25202c3932722509ull,0x317225202c313272ull,
0x2e736261090a3b37ull,0x3372250920323373ull,0x3b39327225202c30ull,0x33732e766f6d090aull,
0x2c31337225092032ull,0x6573090a3b303120ull,0x3233752e74672e74ull,0x722509203233732eull,
0x30337225202c3233ull,0x0a3b31337225202cull,0x3233732e67656e09ull,0x202c333372250920ull,
0x73090a3b32337225ull,0x09203233732e6275ull,0x7225202c34337225ull,0x38317225202c3232ull,
0x732e736261090a3bull,0x3533722509203233ull,0x0a3b34337225202cull,0x3233732e766f6d09ull,
0x202c363372250920ull,0x746573090a3b3031ull,0x2e3233752e74672eull,0x3372250920323373ull,
0x2c35337225202c37ull,0x090a3b3633722520ull,0x203233732e67656eull,0x25202c3833722509ull,
0x726f090a3b373372ull,0x722509203233622eull,0x33337225202c3933ull,0x0a3b38337225202cull,
0x203233622e726f09ull,0x25202c3034722509ull,0x337225202c383272ull,0x2e617262090a3b39ull,
0x744c240920696e75ull,0x34333034345f345full,0x5f345f744c240a3bull,0x090a3a3039323434ull,
0x203233732e766f6dull,0x30202c3034722509ull,0x5f345f744c240a3bull,0x090a3a3433303434ull,
0x203233732e646461ull,0x25202c3134722509ull,0x090a3b31202c3472ull,0x2e656c2e70746573ull,
0x3370250920323373ull,0x25202c387225202cull,0x2540090a3b313472ull,0x0920617262203370ull,
0x34345f345f744c24ull,0x646c090a3b363435ull,0x2e6c61626f6c672eull,0x7b092038752e3476ull,
0x3472252c32347225ull,0x5f2c343472252c33ull,0x346472255b202c7dull,0x6c2e090a3b5d342bull,
0x323109363109636full,0x627573090a300930ull,0x722509203233732eull,0x34347225202c3534ull,
0x0a3b39317225202cull,0x3233732e73626109ull,0x202c363472250920ull,0x6d090a3b35347225ull,
0x09203233732e766full,0x3031202c37347225ull,0x672e746573090a3bull,0x33732e3233752e74ull,
0x2c38347225092032ull,0x25202c3634722520ull,0x656e090a3b373472ull,0x2509203233732e67ull,
0x347225202c393472ull,0x2e627573090a3b38ull,0x3572250920323373ull,0x2c32347225202c30ull,
0x090a3b3731722520ull,0x203233732e736261ull,0x25202c3135722509ull,0x6f6d090a3b303572ull,
0x2509203233732e76ull,0x3b3031202c323572ull,0x74672e746573090aull,0x3233732e3233752eull,
0x202c333572250920ull,0x7225202c31357225ull,0x67656e090a3b3235ull,0x722509203233732eull,
0x33357225202c3435ull,0x732e627573090a3bull,0x3535722509203233ull,0x202c33347225202cull,
0x61090a3b38317225ull,0x09203233732e7362ull,0x7225202c36357225ull,0x766f6d090a3b3535ull,
0x722509203233732eull,0x0a3b3031202c3735ull,0x2e74672e74657309ull,0x203233732e323375ull,
0x25202c3835722509ull,0x357225202c363572ull,0x2e67656e090a3b37ull,0x3572250920323373ull,
0x3b38357225202c39ull,0x3233622e726f090aull,0x202c303672250920ull,0x7225202c34357225ull,
0x2e726f090a3b3935ull,0x3672250920323362ull,0x2c39347225202c31ull,0x090a3b3036722520ull,
0x203233732e646461ull,0x25202c3034722509ull,0x367225202c303472ull,0x345f744c240a3b31ull,
0x0a3a36343534345full,0x3233752e766f6d09ull,0x202c323672250920ull,0x70746573090a3b30ull,
0x203233732e656c2eull,0x7225202c34702509ull,0x3b32367225202c36ull,0x622034702540090aull,
0x5f744c2409206172ull,0x3b38353035345f34ull,0x3109636f6c2e090aull,0x0a30093232310936ull,
0x3233732e62757309ull,0x202c333672250920ull,0x7225202c36317225ull,0x2e747663090a3b38ull,
0x203233732e343673ull,0x25202c3564722509ull,0x756d090a3b333672ull,0x3436752e6f6c2e6cull,
0x202c366472250920ull,0x3b34202c35647225ull,0x36752e646461090aull,0x2c37647225092034ull,
0x25202c3164722520ull,0x646c090a3b366472ull,0x2e6c61626f6c672eull,0x7b092038752e3476ull,
0x3672252c34367225ull,0x5f2c363672252c35ull,0x376472255b202c7dull,0x7573090a3b5d302bull,
0x2509203233732e62ull,0x367225202c373672ull,0x3b39317225202c36ull,0x33732e736261090aull,
0x2c38367225092032ull,0x090a3b3736722520ull,0x203233732e766f6dull,0x31202c3936722509ull,
0x2e746573090a3b30ull,0x732e3233752e7467ull,0x3037722509203233ull,0x202c38367225202cull,
0x6e090a3b39367225ull,0x09203233732e6765ull,0x7225202c31377225ull,0x627573090a3b3037ull,
0x722509203233732eull,0x34367225202c3237ull,0x0a3b37317225202cull,0x3233732e73626109ull,
0x202c333772250920ull,0x6d090a3b32377225ull,0x09203233732e766full,0x3031202c34377225ull,
0x672e746573090a3bull,0x33732e3233752e74ull,0x2c35377225092032ull,0x25202c3337722520ull,
0x656e090a3b343772ull,0x2509203233732e67ull,0x377225202c363772ull,0x2e627573090a3b35ull,
0x3772250920323373ull,0x2c35367225202c37ull,0x090a3b3831722520ull,0x203233732e736261ull,
0x25202c3837722509ull,0x6f6d090a3b373772ull,0x2509203233732e76ull,0x3b3031202c393772ull,
0x74672e746573090aull,0x3233732e3233752eull,0x202c303872250920ull,0x7225202c38377225ull,
0x67656e090a3b3937ull,0x722509203233732eull,0x30387225202c3138ull,0x33622e726f090a3bull,
0x2c32387225092032ull,0x25202c3637722520ull,0x726f090a3b313872ull,0x722509203233622eull,
0x31377225202c3338ull,0x0a3b32387225202cull,0x3233732e64646109ull,0x202c303472250920ull,
0x7225202c30347225ull,0x5f744c240a3b3338ull,0x3a38353035345f34ull,0x33732e646461090aull,
0x2c34387225092032ull,0x3b31202c36722520ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x2c377225202c3570ull,0x090a3b3438722520ull,0x6172622035702540ull,0x5f345f744c240920ull,
0x090a3b3037353534ull,0x09363109636f6c2eull,0x61090a3009343231ull,0x09203233732e6464ull,
0x7225202c35387225ull,0x3b387225202c3631ull,0x36732e747663090aull,0x2509203233732e34ull,
0x387225202c386472ull,0x2e6c756d090a3b35ull,0x09203436752e6f6cull,0x7225202c39647225ull,
0x090a3b34202c3864ull,0x203436752e646461ull,0x202c303164722509ull,0x7225202c31647225ull,
0x2e646c090a3b3964ull,0x762e6c61626f6c67ull,0x257b092038752e34ull,0x373872252c363872ull,
0x7d5f2c383872252cull,0x30316472255b202cull,0x7573090a3b5d302bull,0x2509203233732e62ull,
0x387225202c393872ull,0x3b39317225202c38ull,0x33732e736261090aull,0x2c30397225092032ull,
0x090a3b3938722520ull,0x203233732e766f6dull,0x31202c3139722509ull,0x2e746573090a3b30ull,
0x732e3233752e7467ull,0x3239722509203233ull,0x202c30397225202cull,0x6e090a3b31397225ull,
0x09203233732e6765ull,0x7225202c33397225ull,0x627573090a3b3239ull,0x722509203233732eull,
0x36387225202c3439ull,0x0a3b37317225202cull,0x3233732e73626109ull,0x202c353972250920ull,
0x6d090a3b34397225ull,0x09203233732e766full,0x3031202c36397225ull,0x672e746573090a3bull,
0x33732e3233752e74ull,0x2c37397225092032ull,0x25202c3539722520ull,0x656e090a3b363972ull,
0x2509203233732e67ull,0x397225202c383972ull,0x2e627573090a3b37ull,0x3972250920323373ull,
0x2c37387225202c39ull,0x090a3b3831722520ull,0x203233732e736261ull,0x202c303031722509ull,
0x6d090a3b39397225ull,0x09203233732e766full,0x31202c3130317225ull,0x2e746573090a3b30ull,
0x732e3233752e7467ull,0x3031722509203233ull,0x3030317225202c32ull,0x3b3130317225202cull,
0x33732e67656e090aull,0x3330317225092032ull,0x3b3230317225202cull,0x3233622e726f090aull,
0x2c34303172250920ull,0x25202c3839722520ull,0x6f090a3b33303172ull,0x2509203233622e72ull,
0x7225202c35303172ull,0x30317225202c3339ull,0x2e646461090a3b34ull,0x3472250920323373ull,
0x2c30347225202c30ull,0x0a3b353031722520ull,0x35345f345f744c24ull,0x6f6d090a3a303735ull,
0x2509203233752e76ull,0x3b30202c36303172ull,0x652e70746573090aull,0x2509203233732e71ull,
0x30347225202c3670ull,0x3b3630317225202cull,0x622036702540090aull,0x5f744c2409206172ull,
0x3b32383036345f34ull,0x3109636f6c2e090aull,0x0a30093133310935ull,0x617261702e646c09ull,
0x2509203233732e6dull,0x5f5b202c37303172ull,0x726170616475635full,0x614d36315a5f5f6dull,
0x746f72626c65646eull,0x664930316d735f31ull,0x6168637536507645ull,0x535f546969693472ull,
0x5f32535f32535f32ull,0x69695f30535f3253ull,0x68636e7572635f62ull,0x2e766f6d090a3b5dull,
0x3172250920323373ull,0x30317225202c3830ull,0x2e747663090a3b37ull,0x732e3233662e6e72ull,
0x2c31662509203233ull,0x63090a3b34722520ull,0x33662e6e722e7476ull,0x2509203233732e32ull,
0x3b367225202c3266ull,0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c336625ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,
0x3b5d656c6163735full,0x7261702e646c090aull,0x09203233662e6d61ull,0x5f5f5b202c346625ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,
0x0a3b5d66664f785full,0x3233662e64616d09ull,0x25202c3566250920ull,0x2c336625202c3166ull,
0x6c090a3b34662520ull,0x2e6d617261702e64ull,0x3666250920323366ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x4f795f6269695f30ull,
0x616d090a3b5d6666ull,0x2509203233662e64ull,0x2c326625202c3766ull,0x6625202c33662520ull,
0x702e646c090a3b36ull,0x2038732e6d617261ull,0x202c393031722509ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x5d4a73695f626969ull,
0x752e766f6d090a3bull,0x3131722509203233ull,0x73090a3b30202c30ull,0x732e71652e707465ull,
0x2c37702509203233ull,0x202c393031722520ull,0x090a3b3031317225ull,0x6172622037702540ull,
0x5f345f744c240920ull,0x090a3b3035383634ull,0x09353109636f6c2eull,0x6c090a3009363331ull,
0x2e6d617261702e64ull,0x3866250920323366ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764566493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x535f32535f32535full,0x4a785f6269695f30ull,0x6f6c2e090a3b5d50ull,
0x3733310935310963ull,0x702e646c090a3009ull,0x3233662e6d617261ull,0x5b202c3966250920ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,
0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,
0x3b5d504a795f6269ull,0x3109636f6c2e090aull,0x0a30093833310935ull,0x3233662e766f6d09ull,
0x202c303166250920ull,0x6c2e090a3b376625ull,0x333109353109636full,0x766f6d090a300939ull,
0x662509203233662eull,0x3b356625202c3131ull,0x3109636f6c2e090aull,0x0a30093034310935ull,
0x3233662e6c756d09ull,0x202c323166250920ull,0x376625202c376625ull,0x09636f6c2e090a3bull,
0x3009313431093531ull,0x33662e6c756d090aull,0x2c33316625092032ull,0x6625202c35662520ull,
0x2e617262090a3b35ull,0x744c240920696e75ull,0x34393536345f345full,0x5f345f744c240a3bull,
0x090a3a3035383634ull,0x09353109636f6c2eull,0x6d090a3009353431ull,0x09203233662e766full,
0x356625202c386625ull,0x09636f6c2e090a3bull,0x3009363431093531ull,0x33662e766f6d090aull,
0x202c396625092032ull,0x6c2e090a3b376625ull,0x353109353109636full,0x766f6d090a300930ull,
0x662509203233662eull,0x30306630202c3331ull,0x203b303030303030ull,0x30202f2f09202020ull,
0x33662e766f6d090aull,0x2c32316625092032ull,0x3030303030663020ull,0x202020203b303030ull,
0x6d090a30202f2f09ull,0x09203233662e766full,0x6630202c31316625ull,0x3030303030303030ull,
0x2f2f09202020203bull,0x2e766f6d090a3020ull,0x3166250920323366ull,0x3030306630202c30ull,
0x20203b3030303030ull,0x0a30202f2f092020ull,0x36345f345f744c24ull,0x6f6d090a3a343935ull,
0x2509203233732e76ull,0x3b30202c31313172ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x30317225202c3870ull,0x3131317225202c37ull,0x5f345f744c240a3bull,0x200a3a3439333732ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a353531ull,
0x3535310935310963ull,0x38702540090a3009ull,0x4c24092061726220ull,0x38333533335f345full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f345full,
0x33662e646461090aull,0x2c34316625092032ull,0x25202c3331662520ull,0x6f6d090a3b323166ull,
0x2509203233662e76ull,0x346630202c353166ull,0x3b30303030303830ull,0x202f2f0920202020ull,
0x2e70746573090a34ull,0x09203233662e7467ull,0x316625202c397025ull,0x3b35316625202c34ull,
0x203970252140090aull,0x5f4c240920617262ull,0x3b32383233335f34ull,0x33335f345f4c240aull,
0x6f6d090a3a383335ull,0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b383031ull,
0x240920696e752e61ull,0x3835325f345f744cull,0x335f345f4c240a3bull,0x2f200a3a32383233ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f345f744c2420ull,0x6c2e090a34393337ull,
0x353109353109636full,0x6c756d090a300937ull,0x662509203233662eull,0x31316625202c3631ull,
0x0a3b30316625202cull,0x3233662e64646109ull,0x202c373166250920ull,0x6625202c36316625ull,
0x646461090a3b3631ull,0x662509203233662eull,0x2c396625202c3031ull,0x090a3b3731662520ull,
0x09353109636f6c2eull,0x73090a3009383531ull,0x09203233662e6275ull,0x6625202c38316625ull,
0x32316625202c3331ull,0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,
0x6c2e090a3b383166ull,0x353109353109636full,0x6c756d090a300939ull,0x662509203233662eull,
0x30316625202c3931ull,0x0a3b30316625202cull,0x353109636f6c2e09ull,0x090a300937353109ull,
0x203233732e627573ull,0x202c333131722509ull,0x31202c3830317225ull,0x752e766f6d090a3bull,
0x3131722509203233ull,0x73090a3b30202c34ull,0x732e656c2e707465ull,0x3031702509203233ull,
0x2c3331317225202cull,0x0a3b343131722520ull,0x6220303170254009ull,0x345f4c2409206172ull,
0x0a3b30353034335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,0x345f744c24206465ull,
0x090a34393337325full,0x203233662e6c756dull,0x25202c3032662509ull,0x316625202c313166ull,
0x2e646461090a3b31ull,0x3266250920323366ull,0x2c30326625202c31ull,0x090a3b3931662520ull,
0x203233662e766f6dull,0x30202c3232662509ull,0x3030303038303466ull,0x2f09202020203b30ull,
0x746573090a34202full,0x3233662e74672e70ull,0x202c313170250920ull,0x6625202c31326625ull,
0x252140090a3b3232ull,0x2061726220313170ull,0x33335f345f4c2409ull,0x5f4c240a3b343937ull,
0x3a30353034335f34ull,0x33732e766f6d090aull,0x3231317225092032ull,0x3b3331317225202cull,
0x6e752e617262090aull,0x345f744c24092069ull,0x4c240a3b3835325full,0x34393733335f345full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f345full,
0x3109636f6c2e090aull,0x0a30093636310935ull,0x3233662e6c756d09ull,0x202c363166250920ull,
0x6625202c31316625ull,0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3332ull,
0x0a3b36316625202cull,0x3233662e64646109ull,0x202c303166250920ull,0x326625202c396625ull,
0x636f6c2e090a3b33ull,0x0937363109353109ull,0x662e627573090a30ull,0x3432662509203233ull,
0x202c30326625202cull,0x61090a3b39316625ull,0x09203233662e6464ull,0x6625202c31316625ull,
0x3b34326625202c38ull,0x3109636f6c2e090aull,0x0a30093836310935ull,0x3233662e6c756d09ull,
0x202c353266250920ull,0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3636310935310963ull,
0x2e627573090a3009ull,0x3172250920323373ull,0x30317225202c3531ull,0x6d090a3b32202c38ull,
0x09203233752e766full,0x30202c3631317225ull,0x2e70746573090a3bull,0x09203233732e656cull,
0x7225202c32317025ull,0x317225202c353131ull,0x702540090a3b3631ull,0x0920617262203231ull,
0x3534335f345f4c24ull,0x3c2f2f200a3b3236ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3337325f345f744cull,0x2e6c756d090a3439ull,0x3266250920323366ull,0x2c31316625202c30ull,
0x090a3b3131662520ull,0x203233662e646461ull,0x25202c3632662509ull,0x326625202c303266ull,
0x2e766f6d090a3b35ull,0x3266250920323366ull,0x3830346630202c37ull,0x20203b3030303030ull,
0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,0x36326625202c3331ull,
0x0a3b37326625202cull,0x2033317025214009ull,0x5f4c240920617262ull,0x3b36303334335f34ull,
0x34335f345f4c240aull,0x6f6d090a3a323635ull,0x2509203233732e76ull,0x7225202c32313172ull,
0x7262090a3b353131ull,0x240920696e752e61ull,0x3835325f345f744cull,0x335f345f4c240a3bull,
0x2f200a3a36303334ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x325f345f744c2420ull,
0x6c2e090a34393337ull,0x373109353109636full,0x6c756d090a300935ull,0x662509203233662eull,
0x31316625202c3631ull,0x0a3b30316625202cull,0x3233662e64646109ull,0x202c383266250920ull,
0x6625202c36316625ull,0x646461090a3b3631ull,0x662509203233662eull,0x2c396625202c3031ull,
0x090a3b3832662520ull,0x09353109636f6c2eull,0x73090a3009363731ull,0x09203233662e6275ull,
0x6625202c39326625ull,0x35326625202c3032ull,0x662e646461090a3bull,0x3131662509203233ull,
0x25202c386625202cull,0x6c2e090a3b393266ull,0x373109353109636full,0x6c756d090a300937ull,
0x662509203233662eull,0x30316625202c3033ull,0x0a3b30316625202cull,0x353109636f6c2e09ull,
0x090a300935373109ull,0x203233732e627573ull,0x202c373131722509ull,0x33202c3830317225ull,
0x752e766f6d090a3bull,0x3131722509203233ull,0x73090a3b30202c38ull,0x732e656c2e707465ull,
0x3431702509203233ull,0x2c3731317225202cull,0x0a3b383131722520ull,0x6220343170254009ull,
0x345f4c2409206172ull,0x0a3b34373035335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,
0x345f744c24206465ull,0x090a34393337325full,0x203233662e6c756dull,0x25202c3032662509ull,
0x316625202c313166ull,0x2e646461090a3b31ull,0x3366250920323366ull,0x2c30326625202c31ull,
0x090a3b3033662520ull,0x203233662e766f6dull,0x30202c3233662509ull,0x3030303038303466ull,
0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,0x202c353170250920ull,
0x6625202c31336625ull,0x252140090a3b3233ull,0x2061726220353170ull,0x34335f345f4c2409ull,
0x5f4c240a3b383138ull,0x3a34373035335f34ull,0x33732e766f6d090aull,0x3231317225092032ull,
0x3b3731317225202cull,0x6e752e617262090aull,0x345f744c24092069ull,0x4c240a3b3835325full,
0x38313834335f345full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34393337325f345full,0x3109636f6c2e090aull,0x0a30093438310935ull,0x3233662e6c756d09ull,
0x202c363166250920ull,0x6625202c31316625ull,0x646461090a3b3031ull,0x662509203233662eull,
0x36316625202c3333ull,0x0a3b36316625202cull,0x3233662e64646109ull,0x202c303166250920ull,
0x336625202c396625ull,0x636f6c2e090a3b33ull,0x0935383109353109ull,0x662e627573090a30ull,
0x3433662509203233ull,0x202c30326625202cull,0x61090a3b30336625ull,0x09203233662e6464ull,
0x6625202c31316625ull,0x3b34336625202c38ull,0x3109636f6c2e090aull,0x0a30093638310935ull,
0x3233662e6c756d09ull,0x202c353366250920ull,0x6625202c30316625ull,0x6f6c2e090a3b3031ull,
0x3438310935310963ull,0x2e627573090a3009ull,0x3172250920323373ull,0x30317225202c3931ull,
0x6d090a3b34202c38ull,0x09203233752e766full,0x30202c3032317225ull,0x2e70746573090a3bull,
0x09203233732e656cull,0x7225202c36317025ull,0x317225202c393131ull,0x702540090a3b3032ull,
0x0920617262203631ull,0x3535335f345f4c24ull,0x3c2f2f200a3b3638ull,0x6150203e706f6f6cull,
0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,
0x242064656c656261ull,0x3337325f345f744cull,0x2e6c756d090a3439ull,0x3266250920323366ull,
0x2c31316625202c30ull,0x090a3b3131662520ull,0x203233662e646461ull,0x25202c3633662509ull,
0x336625202c303266ull,0x2e766f6d090a3b35ull,0x3366250920323366ull,0x3830346630202c37ull,
0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,0x702509203233662eull,
0x36336625202c3731ull,0x0a3b37336625202cull,0x2037317025214009ull,0x5f4c240920617262ull,
0x3b30333335335f34ull,0x35335f345f4c240aull,0x6f6d090a3a363835ull,0x2509203233732e76ull,
0x7225202c32313172ull,0x7262090a3b393131ull,0x240920696e752e61ull,0x3835325f345f744cull,
0x335f345f4c240a3bull,0x2f200a3a30333335ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x325f345f744c2420ull,0x6c2e090a34393337ull,0x393109353109636full,0x6c756d090a300933ull,
0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,0x3233662e64646109ull,
0x202c383366250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,0x662509203233662eull,
0x2c396625202c3031ull,0x090a3b3833662520ull,0x09353109636f6c2eull,0x73090a3009343931ull,
0x09203233662e6275ull,0x6625202c39336625ull,0x35336625202c3032ull,0x662e646461090a3bull,
0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b393366ull,0x393109353109636full,
0x6c756d090a300935ull,0x662509203233662eull,0x30316625202c3034ull,0x0a3b30316625202cull,
0x353109636f6c2e09ull,0x090a300933393109ull,0x203233732e627573ull,0x202c313231722509ull,
0x35202c3830317225ull,0x752e766f6d090a3bull,0x3231722509203233ull,0x73090a3b30202c32ull,
0x732e656c2e707465ull,0x3831702509203233ull,0x2c3132317225202cull,0x0a3b323231722520ull,
0x6220383170254009ull,0x345f4c2409206172ull,0x0a3b38393036335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x345f744c24206465ull,0x090a34393337325full,0x203233662e6c756dull,
0x25202c3032662509ull,0x316625202c313166ull,0x2e646461090a3b31ull,0x3466250920323366ull,
0x2c30326625202c31ull,0x090a3b3034662520ull,0x203233662e766f6dull,0x30202c3234662509ull,
0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,0x3233662e74672e70ull,
0x202c393170250920ull,0x6625202c31346625ull,0x252140090a3b3234ull,0x2061726220393170ull,
0x35335f345f4c2409ull,0x5f4c240a3b323438ull,0x3a38393036335f34ull,0x33732e766f6d090aull,
0x3231317225092032ull,0x3b3132317225202cull,0x6e752e617262090aull,0x345f744c24092069ull,
0x4c240a3b3835325full,0x32343835335f345full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34393337325f345full,0x3109636f6c2e090aull,0x0a30093230320935ull,
0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,0x646461090a3b3031ull,
0x662509203233662eull,0x36316625202c3334ull,0x0a3b36316625202cull,0x3233662e64646109ull,
0x202c303166250920ull,0x346625202c396625ull,0x636f6c2e090a3b33ull,0x0933303209353109ull,
0x662e627573090a30ull,0x3434662509203233ull,0x202c30326625202cull,0x61090a3b30346625ull,
0x09203233662e6464ull,0x6625202c31316625ull,0x3b34346625202c38ull,0x3109636f6c2e090aull,
0x0a30093430320935ull,0x3233662e6c756d09ull,0x202c353466250920ull,0x6625202c30316625ull,
0x6f6c2e090a3b3031ull,0x3230320935310963ull,0x2e627573090a3009ull,0x3172250920323373ull,
0x30317225202c3332ull,0x6d090a3b36202c38ull,0x09203233752e766full,0x30202c3432317225ull,
0x2e70746573090a3bull,0x09203233732e656cull,0x7225202c30327025ull,0x317225202c333231ull,
0x702540090a3b3432ull,0x0920617262203032ull,0x3636335f345f4c24ull,0x3c2f2f200a3b3031ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3337325f345f744cull,0x2e6c756d090a3439ull,
0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,0x203233662e646461ull,
0x25202c3634662509ull,0x346625202c303266ull,0x2e766f6d090a3b35ull,0x3466250920323366ull,
0x3830346630202c37ull,0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,
0x702509203233662eull,0x36346625202c3132ull,0x0a3b37346625202cull,0x2031327025214009ull,
0x5f4c240920617262ull,0x3b34353336335f34ull,0x36335f345f4c240aull,0x6f6d090a3a303136ull,
0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b333231ull,0x240920696e752e61ull,
0x3835325f345f744cull,0x335f345f4c240a3bull,0x2f200a3a34353336ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x325f345f744c2420ull,0x6c2e090a34393337ull,0x313209353109636full,
0x6c756d090a300931ull,0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,
0x3233662e64646109ull,0x202c383466250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,
0x662509203233662eull,0x2c396625202c3031ull,0x090a3b3834662520ull,0x09353109636f6c2eull,
0x73090a3009323132ull,0x09203233662e6275ull,0x6625202c39346625ull,0x35346625202c3032ull,
0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b393466ull,
0x313209353109636full,0x6c756d090a300933ull,0x662509203233662eull,0x30316625202c3035ull,
0x0a3b30316625202cull,0x353109636f6c2e09ull,0x090a300931313209ull,0x203233732e627573ull,
0x202c353231722509ull,0x37202c3830317225ull,0x752e766f6d090a3bull,0x3231722509203233ull,
0x73090a3b30202c36ull,0x732e656c2e707465ull,0x3232702509203233ull,0x2c3532317225202cull,
0x0a3b363231722520ull,0x6220323270254009ull,0x345f4c2409206172ull,0x0a3b32323137335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a34393337325full,
0x203233662e6c756dull,0x25202c3032662509ull,0x316625202c313166ull,0x2e646461090a3b31ull,
0x3566250920323366ull,0x2c30326625202c31ull,0x090a3b3035662520ull,0x203233662e766f6dull,
0x30202c3235662509ull,0x3030303038303466ull,0x2f09202020203b30ull,0x746573090a34202full,
0x3233662e74672e70ull,0x202c333270250920ull,0x6625202c31356625ull,0x252140090a3b3235ull,
0x2061726220333270ull,0x36335f345f4c2409ull,0x5f4c240a3b363638ull,0x3a32323137335f34ull,
0x33732e766f6d090aull,0x3231317225092032ull,0x3b3532317225202cull,0x6e752e617262090aull,
0x345f744c24092069ull,0x4c240a3b3835325full,0x36363836335f345full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f345full,0x3109636f6c2e090aull,
0x0a30093032320935ull,0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,
0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3335ull,0x0a3b36316625202cull,
0x3233662e64646109ull,0x202c303166250920ull,0x356625202c396625ull,0x636f6c2e090a3b33ull,
0x0931323209353109ull,0x662e627573090a30ull,0x3435662509203233ull,0x202c30326625202cull,
0x61090a3b30356625ull,0x09203233662e6464ull,0x6625202c31316625ull,0x3b34356625202c38ull,
0x3109636f6c2e090aull,0x0a30093232320935ull,0x3233662e6c756d09ull,0x202c353566250920ull,
0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3032320935310963ull,0x2e627573090a3009ull,
0x3172250920323373ull,0x30317225202c3732ull,0x6d090a3b38202c38ull,0x09203233752e766full,
0x30202c3832317225ull,0x2e70746573090a3bull,0x09203233732e656cull,0x7225202c34327025ull,
0x317225202c373231ull,0x702540090a3b3832ull,0x0920617262203432ull,0x3637335f345f4c24ull,
0x3c2f2f200a3b3433ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3337325f345f744cull,
0x2e6c756d090a3439ull,0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,
0x203233662e646461ull,0x25202c3635662509ull,0x356625202c303266ull,0x2e766f6d090a3b35ull,
0x3566250920323366ull,0x3830346630202c37ull,0x20203b3030303030ull,0x0a34202f2f092020ull,
0x74672e7074657309ull,0x702509203233662eull,0x36356625202c3532ull,0x0a3b37356625202cull,
0x2035327025214009ull,0x5f4c240920617262ull,0x3b38373337335f34ull,0x37335f345f4c240aull,
0x6f6d090a3a343336ull,0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b373231ull,
0x240920696e752e61ull,0x3835325f345f744cull,0x335f345f4c240a3bull,0x2f200a3a38373337ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f345f744c2420ull,0x6c2e090a34393337ull,
0x323209353109636full,0x6c756d090a300939ull,0x662509203233662eull,0x31316625202c3631ull,
0x0a3b30316625202cull,0x3233662e64646109ull,0x202c383566250920ull,0x6625202c36316625ull,
0x646461090a3b3631ull,0x662509203233662eull,0x2c396625202c3031ull,0x090a3b3835662520ull,
0x09353109636f6c2eull,0x73090a3009303332ull,0x09203233662e6275ull,0x6625202c39356625ull,
0x35356625202c3032ull,0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,
0x6c2e090a3b393566ull,0x333209353109636full,0x6c756d090a300931ull,0x662509203233662eull,
0x30316625202c3036ull,0x0a3b30316625202cull,0x353109636f6c2e09ull,0x090a300939323209ull,
0x203233732e627573ull,0x202c393231722509ull,0x39202c3830317225ull,0x752e766f6d090a3bull,
0x3331722509203233ull,0x73090a3b30202c30ull,0x732e656c2e707465ull,0x3632702509203233ull,
0x2c3932317225202cull,0x0a3b303331722520ull,0x6220363270254009ull,0x345f4c2409206172ull,
0x0a3b36343138335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,0x345f744c24206465ull,
0x090a34393337325full,0x203233662e6c756dull,0x25202c3032662509ull,0x316625202c313166ull,
0x2e646461090a3b31ull,0x3666250920323366ull,0x2c30326625202c31ull,0x090a3b3036662520ull,
0x203233662e766f6dull,0x30202c3236662509ull,0x3030303038303466ull,0x2f09202020203b30ull,
0x746573090a34202full,0x3233662e74672e70ull,0x202c373270250920ull,0x6625202c31366625ull,
0x252140090a3b3236ull,0x2061726220373270ull,0x37335f345f4c2409ull,0x5f4c240a3b303938ull,
0x3a36343138335f34ull,0x33732e766f6d090aull,0x3231317225092032ull,0x3b3932317225202cull,
0x6e752e617262090aull,0x345f744c24092069ull,0x4c240a3b3835325full,0x30393837335f345full,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f345full,
0x3109636f6c2e090aull,0x0a30093833320935ull,0x3233662e6c756d09ull,0x202c363166250920ull,
0x6625202c31316625ull,0x646461090a3b3031ull,0x662509203233662eull,0x36316625202c3336ull,
0x0a3b36316625202cull,0x3233662e64646109ull,0x202c303166250920ull,0x366625202c396625ull,
0x636f6c2e090a3b33ull,0x0939333209353109ull,0x662e627573090a30ull,0x3436662509203233ull,
0x202c30326625202cull,0x61090a3b30366625ull,0x09203233662e6464ull,0x6625202c31316625ull,
0x3b34366625202c38ull,0x3109636f6c2e090aull,0x0a30093034320935ull,0x3233662e6c756d09ull,
0x202c353666250920ull,0x6625202c30316625ull,0x6f6c2e090a3b3031ull,0x3833320935310963ull,
0x2e627573090a3009ull,0x3172250920323373ull,0x30317225202c3133ull,0x090a3b3031202c38ull,
0x203233752e766f6dull,0x202c323331722509ull,0x70746573090a3b30ull,0x203233732e656c2eull,
0x25202c3832702509ull,0x7225202c31333172ull,0x2540090a3b323331ull,0x2061726220383270ull,
0x38335f345f4c2409ull,0x2f2f200a3b383536ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,
0x37325f345f744c24ull,0x6c756d090a343933ull,0x662509203233662eull,0x31316625202c3032ull,
0x0a3b31316625202cull,0x3233662e64646109ull,0x202c363666250920ull,0x6625202c30326625ull,
0x766f6d090a3b3536ull,0x662509203233662eull,0x30346630202c3736ull,0x203b303030303038ull,
0x34202f2f09202020ull,0x672e70746573090aull,0x2509203233662e74ull,0x366625202c393270ull,
0x3b37366625202c36ull,0x393270252140090aull,0x4c24092061726220ull,0x32303438335f345full,
0x335f345f4c240a3bull,0x6d090a3a38353638ull,0x09203233732e766full,0x25202c3231317225ull,
0x62090a3b31333172ull,0x0920696e752e6172ull,0x35325f345f744c24ull,0x5f345f4c240a3b38ull,
0x200a3a3230343833ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,0x5f345f744c242064ull,
0x2e090a3439333732ull,0x3209353109636f6cull,0x756d090a30093734ull,0x2509203233662e6cull,
0x316625202c363166ull,0x3b30316625202c31ull,0x33662e646461090aull,0x2c38366625092032ull,
0x25202c3631662520ull,0x6461090a3b363166ull,0x2509203233662e64ull,0x396625202c303166ull,
0x0a3b38366625202cull,0x353109636f6c2e09ull,0x090a300938343209ull,0x203233662e627573ull,
0x25202c3936662509ull,0x366625202c303266ull,0x2e646461090a3b35ull,0x3166250920323366ull,
0x202c386625202c31ull,0x2e090a3b39366625ull,0x3209353109636f6cull,0x756d090a30093934ull,
0x2509203233662e6cull,0x316625202c303766ull,0x3b30316625202c30ull,0x3109636f6c2e090aull,
0x0a30093734320935ull,0x3233732e62757309ull,0x2c33333172250920ull,0x202c383031722520ull,
0x766f6d090a3b3131ull,0x722509203233752eull,0x0a3b30202c343331ull,0x656c2e7074657309ull,
0x702509203233732eull,0x33317225202c3033ull,0x3433317225202c33ull,0x3033702540090a3bull,
0x4c24092061726220ull,0x30373139335f345full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34393337325f345full,0x33662e6c756d090aull,0x2c30326625092032ull,
0x25202c3131662520ull,0x6461090a3b313166ull,0x2509203233662e64ull,0x326625202c313766ull,
0x3b30376625202c30ull,0x33662e766f6d090aull,0x2c32376625092032ull,0x3030383034663020ull,
0x202020203b303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,0x3133702509203233ull,
0x202c31376625202cull,0x40090a3b32376625ull,0x7262203133702521ull,0x5f345f4c24092061ull,
0x240a3b3431393833ull,0x373139335f345f4cull,0x2e766f6d090a3a30ull,0x3172250920323373ull,
0x33317225202c3231ull,0x2e617262090a3b33ull,0x744c240920696e75ull,0x0a3b3835325f345full,
0x3938335f345f4c24ull,0x3c2f2f200a3a3431ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3337325f345f744cull,0x636f6c2e090a3439ull,0x0936353209353109ull,0x662e6c756d090a30ull,
0x3631662509203233ull,0x202c31316625202cull,0x61090a3b30316625ull,0x09203233662e6464ull,
0x6625202c33376625ull,0x36316625202c3631ull,0x662e646461090a3bull,0x3031662509203233ull,
0x25202c396625202cull,0x6c2e090a3b333766ull,0x353209353109636full,0x627573090a300937ull,
0x662509203233662eull,0x30326625202c3437ull,0x0a3b30376625202cull,0x3233662e64646109ull,
0x202c313166250920ull,0x376625202c386625ull,0x636f6c2e090a3b34ull,0x0938353209353109ull,
0x662e6c756d090a30ull,0x3537662509203233ull,0x202c30316625202cull,0x2e090a3b30316625ull,
0x3209353109636f6cull,0x7573090a30093635ull,0x2509203233732e62ull,0x7225202c35333172ull,
0x3b3231202c383031ull,0x33752e766f6d090aull,0x3633317225092032ull,0x6573090a3b30202cull,
0x33732e656c2e7074ull,0x2c32337025092032ull,0x202c353331722520ull,0x090a3b3633317225ull,
0x7262203233702540ull,0x5f345f4c24092061ull,0x200a3b3238363933ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,
0x656c6562616c2064ull,0x5f345f744c242064ull,0x6d090a3439333732ull,0x09203233662e6c75ull,
0x6625202c30326625ull,0x31316625202c3131ull,0x662e646461090a3bull,0x3637662509203233ull,
0x202c30326625202cull,0x6d090a3b35376625ull,0x09203233662e766full,0x6630202c37376625ull,
0x3030303030383034ull,0x2f2f09202020203bull,0x70746573090a3420ull,0x203233662e74672eull,
0x25202c3333702509ull,0x376625202c363766ull,0x70252140090a3b37ull,0x0920617262203333ull,
0x3439335f345f4c24ull,0x345f4c240a3b3632ull,0x0a3a32383639335full,0x3233732e766f6d09ull,
0x2c32313172250920ull,0x0a3b353331722520ull,0x696e752e61726209ull,0x5f345f744c240920ull,
0x5f4c240a3b383532ull,0x3a36323439335f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a34393337325f34ull,0x353109636f6c2e09ull,0x090a300935363209ull,
0x203233662e6c756dull,0x25202c3631662509ull,0x316625202c313166ull,0x2e646461090a3b30ull,
0x3766250920323366ull,0x2c36316625202c38ull,0x090a3b3631662520ull,0x203233662e646461ull,
0x25202c3031662509ull,0x38376625202c3966ull,0x09636f6c2e090a3bull,0x3009363632093531ull,
0x33662e627573090aull,0x2c39376625092032ull,0x25202c3032662520ull,0x6461090a3b353766ull,
0x2509203233662e64ull,0x386625202c313166ull,0x0a3b39376625202cull,0x353109636f6c2e09ull,
0x090a300937363209ull,0x203233662e6c756dull,0x25202c3038662509ull,0x316625202c303166ull,
0x636f6c2e090a3b30ull,0x0935363209353109ull,0x732e627573090a30ull,0x3331722509203233ull,
0x3830317225202c37ull,0x6d090a3b3331202cull,0x09203233752e766full,0x30202c3833317225ull,
0x2e70746573090a3bull,0x09203233732e656cull,0x7225202c34337025ull,0x317225202c373331ull,
0x702540090a3b3833ull,0x0920617262203433ull,0x3130345f345f4c24ull,0x3c2f2f200a3b3439ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3337325f345f744cull,0x2e6c756d090a3439ull,
0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,0x203233662e646461ull,
0x25202c3138662509ull,0x386625202c303266ull,0x2e766f6d090a3b30ull,0x3866250920323366ull,
0x3830346630202c32ull,0x20203b3030303030ull,0x0a34202f2f092020ull,0x74672e7074657309ull,
0x702509203233662eull,0x31386625202c3533ull,0x0a3b32386625202cull,0x2035337025214009ull,
0x5f4c240920617262ull,0x3b38333939335f34ull,0x30345f345f4c240aull,0x6f6d090a3a343931ull,
0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b373331ull,0x240920696e752e61ull,
0x3835325f345f744cull,0x335f345f4c240a3bull,0x2f200a3a38333939ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x325f345f744c2420ull,0x6c2e090a34393337ull,0x373209353109636full,
0x6c756d090a300934ull,0x662509203233662eull,0x31316625202c3631ull,0x0a3b30316625202cull,
0x3233662e64646109ull,0x202c333866250920ull,0x6625202c36316625ull,0x646461090a3b3631ull,
0x662509203233662eull,0x2c396625202c3031ull,0x090a3b3338662520ull,0x09353109636f6c2eull,
0x73090a3009353732ull,0x09203233662e6275ull,0x6625202c34386625ull,0x30386625202c3032ull,
0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,0x6c2e090a3b343866ull,
0x373209353109636full,0x6c756d090a300936ull,0x662509203233662eull,0x30316625202c3538ull,
0x0a3b30316625202cull,0x353109636f6c2e09ull,0x090a300934373209ull,0x203233732e627573ull,
0x202c393331722509ull,0x31202c3830317225ull,0x2e766f6d090a3b34ull,0x3172250920323375ull,
0x090a3b30202c3034ull,0x2e656c2e70746573ull,0x3370250920323373ull,0x3933317225202c36ull,
0x3b3034317225202cull,0x203633702540090aull,0x5f4c240920617262ull,0x3b36303730345f34ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34393337325f34ull,
0x3233662e6c756d09ull,0x202c303266250920ull,0x6625202c31316625ull,0x646461090a3b3131ull,
0x662509203233662eull,0x30326625202c3638ull,0x0a3b35386625202cull,0x3233662e766f6d09ull,
0x202c373866250920ull,0x3030303830346630ull,0x09202020203b3030ull,0x6573090a34202f2full,
0x33662e74672e7074ull,0x2c37337025092032ull,0x25202c3638662520ull,0x2140090a3b373866ull,
0x6172622037337025ull,0x345f345f4c240920ull,0x4c240a3b30353430ull,0x36303730345f345full,
0x732e766f6d090a3aull,0x3131722509203233ull,0x3933317225202c32ull,0x752e617262090a3bull,
0x5f744c240920696eull,0x240a3b3835325f34ull,0x353430345f345f4cull,0x6c3c2f2f200a3a30ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x393337325f345f74ull,0x09636f6c2e090a34ull,
0x3009333832093531ull,0x33662e6c756d090aull,0x2c36316625092032ull,0x25202c3131662520ull,
0x6461090a3b303166ull,0x2509203233662e64ull,0x316625202c383866ull,0x3b36316625202c36ull,
0x33662e646461090aull,0x2c30316625092032ull,0x6625202c39662520ull,0x6f6c2e090a3b3838ull,
0x3438320935310963ull,0x2e627573090a3009ull,0x3866250920323366ull,0x2c30326625202c39ull,
0x090a3b3538662520ull,0x203233662e646461ull,0x25202c3131662509ull,0x39386625202c3866ull,
0x09636f6c2e090a3bull,0x3009353832093531ull,0x33662e6c756d090aull,0x2c30396625092032ull,
0x25202c3031662520ull,0x6c2e090a3b303166ull,0x383209353109636full,0x627573090a300933ull,
0x722509203233732eull,0x317225202c313431ull,0x0a3b3531202c3830ull,0x3233752e766f6d09ull,
0x2c32343172250920ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c383370250920ull,
0x25202c3134317225ull,0x40090a3b32343172ull,0x6172622038337025ull,0x345f345f4c240920ull,
0x2f200a3b38313231ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x325f345f744c2420ull,
0x756d090a34393337ull,0x2509203233662e6cull,0x316625202c303266ull,0x3b31316625202c31ull,
0x33662e646461090aull,0x2c31396625092032ull,0x25202c3032662520ull,0x6f6d090a3b303966ull,
0x2509203233662e76ull,0x346630202c323966ull,0x3b30303030303830ull,0x202f2f0920202020ull,
0x2e70746573090a34ull,0x09203233662e7467ull,0x6625202c39337025ull,0x32396625202c3139ull,
0x3370252140090a3bull,0x2409206172622039ull,0x363930345f345f4cull,0x5f345f4c240a3b32ull,
0x090a3a3831323134ull,0x203233732e766f6dull,0x202c323131722509ull,0x090a3b3134317225ull,
0x20696e752e617262ull,0x325f345f744c2409ull,0x345f4c240a3b3835ull,0x0a3a32363930345full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a34393337325full,
0x09353109636f6c2eull,0x6d090a3009323932ull,0x09203233662e6c75ull,0x6625202c36316625ull,
0x30316625202c3131ull,0x662e646461090a3bull,0x3339662509203233ull,0x202c36316625202cull,
0x61090a3b36316625ull,0x09203233662e6464ull,0x6625202c30316625ull,0x3b33396625202c39ull,
0x3109636f6c2e090aull,0x0a30093339320935ull,0x3233662e62757309ull,0x202c343966250920ull,
0x6625202c30326625ull,0x646461090a3b3039ull,0x662509203233662eull,0x2c386625202c3131ull,
0x090a3b3439662520ull,0x09353109636f6c2eull,0x6d090a3009343932ull,0x09203233662e6c75ull,
0x6625202c35396625ull,0x30316625202c3031ull,0x09636f6c2e090a3bull,0x3009323932093531ull,
0x33732e627573090aull,0x3334317225092032ull,0x2c3830317225202cull,0x6f6d090a3b363120ull,
0x2509203233752e76ull,0x3b30202c34343172ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x317225202c303470ull,0x34317225202c3334ull,0x34702540090a3b34ull,0x2409206172622030ull,
0x333731345f345f4cull,0x6c3c2f2f200a3b30ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x393337325f345f74ull,0x662e6c756d090a34ull,0x3032662509203233ull,0x202c31316625202cull,
0x61090a3b31316625ull,0x09203233662e6464ull,0x6625202c36396625ull,0x35396625202c3032ull,
0x662e766f6d090a3bull,0x3739662509203233ull,0x303830346630202cull,0x2020203b30303030ull,
0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3470250920323366ull,0x2c36396625202c31ull,
0x090a3b3739662520ull,0x6220313470252140ull,0x345f4c2409206172ull,0x0a3b34373431345full,
0x3731345f345f4c24ull,0x766f6d090a3a3033ull,0x722509203233732eull,0x317225202c323131ull,
0x617262090a3b3334ull,0x4c240920696e752eull,0x3b3835325f345f74ull,0x31345f345f4c240aull,
0x2f2f200a3a343734ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,0x37325f345f744c24ull,
0x6f6c2e090a343933ull,0x3130330935310963ull,0x2e6c756d090a3009ull,0x3166250920323366ull,
0x2c31316625202c36ull,0x090a3b3031662520ull,0x203233662e646461ull,0x25202c3839662509ull,
0x316625202c363166ull,0x2e646461090a3b36ull,0x3166250920323366ull,0x202c396625202c30ull,
0x2e090a3b38396625ull,0x3309353109636f6cull,0x7573090a30093230ull,0x2509203233662e62ull,
0x326625202c393966ull,0x3b35396625202c30ull,0x33662e646461090aull,0x2c31316625092032ull,
0x6625202c38662520ull,0x6f6c2e090a3b3939ull,0x3330330935310963ull,0x2e6c756d090a3009ull,
0x3166250920323366ull,0x30316625202c3030ull,0x0a3b30316625202cull,0x353109636f6c2e09ull,
0x090a300931303309ull,0x203233732e627573ull,0x202c353431722509ull,0x31202c3830317225ull,
0x2e766f6d090a3b37ull,0x3172250920323375ull,0x090a3b30202c3634ull,0x2e656c2e70746573ull,
0x3470250920323373ull,0x3534317225202c32ull,0x3b3634317225202cull,0x203234702540090aull,
0x5f4c240920617262ull,0x3b32343232345f34ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a34393337325f34ull,0x3233662e6c756d09ull,0x202c303266250920ull,
0x6625202c31316625ull,0x646461090a3b3131ull,0x662509203233662eull,0x326625202c313031ull,
0x3030316625202c30ull,0x662e766f6d090a3bull,0x3031662509203233ull,0x3830346630202c32ull,
0x20203b3030303030ull,0x090a34202f2f0920ull,0x2e74672e70746573ull,0x3470250920323366ull,
0x3130316625202c33ull,0x3b3230316625202cull,0x333470252140090aull,0x4c24092061726220ull,
0x36383931345f345full,0x345f345f4c240a3bull,0x6d090a3a32343232ull,0x09203233732e766full,
0x25202c3231317225ull,0x62090a3b35343172ull,0x0920696e752e6172ull,0x35325f345f744c24ull,
0x5f345f4c240a3b38ull,0x200a3a3638393134ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,
0x5f345f744c242064ull,0x2e090a3439333732ull,0x3309353109636f6cull,0x756d090a30093031ull,
0x2509203233662e6cull,0x316625202c363166ull,0x3b30316625202c31ull,0x33662e646461090aull,
0x3330316625092032ull,0x202c36316625202cull,0x61090a3b36316625ull,0x09203233662e6464ull,
0x6625202c30316625ull,0x3330316625202c39ull,0x09636f6c2e090a3bull,0x3009313133093531ull,
0x33662e627573090aull,0x3430316625092032ull,0x202c30326625202cull,0x090a3b3030316625ull,
0x203233662e646461ull,0x25202c3131662509ull,0x30316625202c3866ull,0x636f6c2e090a3b34ull,
0x0932313309353109ull,0x662e6c756d090a30ull,0x3031662509203233ull,0x2c30316625202c35ull,
0x090a3b3031662520ull,0x09353109636f6c2eull,0x73090a3009303133ull,0x09203233732e6275ull,
0x25202c3734317225ull,0x3831202c38303172ull,0x752e766f6d090a3bull,0x3431722509203233ull,
0x73090a3b30202c38ull,0x732e656c2e707465ull,0x3434702509203233ull,0x2c3734317225202cull,
0x0a3b383431722520ull,0x6220343470254009ull,0x345f4c2409206172ull,0x0a3b34353732345full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x345f744c24206465ull,0x090a34393337325full,
0x203233662e6c756dull,0x25202c3032662509ull,0x316625202c313166ull,0x2e646461090a3b31ull,
0x3166250920323366ull,0x30326625202c3630ull,0x3b3530316625202cull,0x33662e766f6d090aull,
0x3730316625092032ull,0x303830346630202cull,0x2020203b30303030ull,0x73090a34202f2f09ull,
0x662e74672e707465ull,0x3534702509203233ull,0x2c3630316625202cull,0x0a3b373031662520ull,
0x2035347025214009ull,0x5f4c240920617262ull,0x3b38393432345f34ull,0x32345f345f4c240aull,
0x6f6d090a3a343537ull,0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b373431ull,
0x240920696e752e61ull,0x3835325f345f744cull,0x345f345f4c240a3bull,0x2f200a3a38393432ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f345f744c2420ull,0x6c2e090a34393337ull,
0x313309353109636full,0x6c756d090a300939ull,0x662509203233662eull,0x31316625202c3631ull,
0x0a3b30316625202cull,0x3233662e64646109ull,0x2c38303166250920ull,0x25202c3631662520ull,
0x6461090a3b363166ull,0x2509203233662e64ull,0x396625202c303166ull,0x3b3830316625202cull,
0x3109636f6c2e090aull,0x0a30093032330935ull,0x3233662e62757309ull,0x2c39303166250920ull,
0x25202c3032662520ull,0x61090a3b35303166ull,0x09203233662e6464ull,0x6625202c31316625ull,
0x3930316625202c38ull,0x09636f6c2e090a3bull,0x3009313233093531ull,0x33662e6c756d090aull,
0x3031316625092032ull,0x202c30316625202cull,0x2e090a3b30316625ull,0x3309353109636f6cull,
0x7573090a30093532ull,0x2509203233732e62ull,0x7225202c38303172ull,0x3b3931202c383031ull,
0x3109636f6c2e090aull,0x0a30093931330935ull,0x3233732e766f6d09ull,0x2c39343172250920ull,
0x746573090a3b3020ull,0x3233732e656c2e70ull,0x25202c3870250920ull,0x7225202c38303172ull,
0x2540090a3b393431ull,0x0920617262203870ull,0x3233345f345f4c24ull,0x3c2f2f200a3b3636ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x35353120656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3337325f345f744cull,0x2e6c756d090a3439ull,
0x3266250920323366ull,0x2c31316625202c30ull,0x090a3b3131662520ull,0x203233662e646461ull,
0x202c313131662509ull,0x6625202c30326625ull,0x6f6d090a3b303131ull,0x2509203233662e76ull,
0x6630202c32313166ull,0x3030303030383034ull,0x202f2f092020203bull,0x2e70746573090a34ull,
0x09203233662e7467ull,0x6625202c36347025ull,0x316625202c313131ull,0x252140090a3b3231ull,
0x2061726220363470ull,0x33345f345f4c2409ull,0x5f4c240a3b303130ull,0x3a36363233345f34ull,
0x33732e766f6d090aull,0x3231317225092032ull,0x3b3830317225202cull,0x6e752e617262090aull,
0x345f744c24092069ull,0x4c240a3b3835325full,0x30313033345f345full,0x6f6c3c2f2f200a3aull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f345full,0x3109636f6c2e090aull,
0x0a30093832330935ull,0x3233662e6c756d09ull,0x202c363166250920ull,0x6625202c31316625ull,
0x646461090a3b3031ull,0x662509203233662eull,0x316625202c333131ull,0x3b36316625202c36ull,
0x33662e646461090aull,0x2c30316625092032ull,0x6625202c39662520ull,0x6c2e090a3b333131ull,
0x323309353109636full,0x627573090a300939ull,0x662509203233662eull,0x326625202c343131ull,
0x3031316625202c30ull,0x662e646461090a3bull,0x3131662509203233ull,0x25202c386625202cull,
0x2e090a3b34313166ull,0x3309353109636f6cull,0x756d090a30093033ull,0x2509203233662e6cull,
0x316625202c323166ull,0x3b30316625202c30ull,0x3109636f6c2e090aull,0x0a30093133330935ull,
0x3233662e6c756d09ull,0x202c333166250920ull,0x6625202c31316625ull,0x6f6c2e090a3b3131ull,
0x3832330935310963ull,0x2e617262090a3009ull,0x744c240920696e75ull,0x34393337325f345full,
0x5f345f744c240a3bull,0x6c2e090a3a383532ull,0x333109363109636full,0x766f6d090a300931ull,
0x722509203233732eull,0x0a3b30202c303531ull,0x74672e7074657309ull,0x702509203233732eull,
0x31317225202c3734ull,0x3035317225202c32ull,0x732e627573090a3bull,0x3531722509203233ull,
0x3730317225202c31ull,0x3b3231317225202cull,0x33732e766f6d090aull,0x3235317225092032ull,
0x6573090a3b30202cull,0x09203233732e706cull,0x25202c3335317225ull,0x7225202c31353172ull,
0x347025202c323531ull,0x2e766f6d090a3b37ull,0x3172250920323375ull,0x090a3b30202c3435ull,
0x2e71652e70746573ull,0x3470250920323373ull,0x3335317225202c38ull,0x3b3435317225202cull,
0x203834702540090aull,0x744c240920617262ull,0x32363337345f345full,0x09636f6c2e090a3bull,
0x3009383331093631ull,0x7261702e646c090aull,0x09203233732e6d61ull,0x5b202c3535317225ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,
0x6863753650764566ull,0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,
0x616d696e615f6269ull,0x6d6172466e6f6974ull,0x646461090a3b5d65ull,0x722509203233732eull,
0x317225202c363531ull,0x35317225202c3535ull,0x702e646c090a3b33ull,0x2038752e6d617261ull,
0x202c373531722509ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456649ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x6f6c6f635f626969ull,0x090a3b5d302b7372ull,0x732e6f6c2e6c756dull,
0x3531722509203233ull,0x3635317225202c38ull,0x3b3735317225202cull,0x38752e747663090aull,
0x722509203233752eull,0x317225202c393531ull,0x6f6c2e090a3b3835ull,0x3933310936310963ull,
0x702e646c090a3009ull,0x2038752e6d617261ull,0x202c303631722509ull,0x70616475635f5f5bull,
0x36315a5f5f6d7261ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456649ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x6f6c6f635f626969ull,
0x090a3b5d312b7372ull,0x732e6f6c2e6c756dull,0x3631722509203233ull,0x3635317225202c31ull,
0x3b3036317225202cull,0x38752e747663090aull,0x722509203233752eull,0x317225202c323631ull,
0x6f6c2e090a3b3136ull,0x3034310936310963ull,0x702e646c090a3009ull,0x2038752e6d617261ull,
0x202c333631722509ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456649ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x6f6c6f635f626969ull,0x090a3b5d322b7372ull,0x732e6f6c2e6c756dull,
0x3631722509203233ull,0x3635317225202c34ull,0x3b3336317225202cull,0x38752e747663090aull,
0x722509203233752eull,0x317225202c353631ull,0x617262090a3b3436ull,0x4c240920696e752eull,
0x303137345f345f74ull,0x345f744c240a3b36ull,0x0a3a32363337345full,0x363109636f6c2e09ull,
0x090a300934343109ull,0x203233752e766f6dull,0x202c353631722509ull,0x2e766f6d090a3b30ull,
0x3172250920323375ull,0x090a3b30202c3236ull,0x203233752e766f6dull,0x202c393531722509ull,
0x345f744c240a3b30ull,0x0a3a36303137345full,0x363109636f6c2e09ull,0x090a300930353109ull,
0x6d617261702e646cull,0x722509203233732eull,0x5f5f5b202c363631ull,0x6d72617061647563ull,
0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45664930316d735full,0x7261686375365076ull,
0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,0x3b5d656d6172665full,
0x33732e646461090aull,0x3736317225092032ull,0x2c3636317225202cull,0x726873090a3b3120ull,
0x722509203233732eull,0x317225202c383631ull,0x0a3b3133202c3736ull,0x3233732e766f6d09ull,
0x2c39363172250920ull,0x646e61090a3b3120ull,0x722509203233622eull,0x317225202c303731ull,
0x36317225202c3836ull,0x2e646461090a3b39ull,0x3172250920323373ull,0x37317225202c3137ull,
0x3736317225202c30ull,0x732e726873090a3bull,0x3731722509203233ull,0x3137317225202c32ull,
0x756d090a3b31202cull,0x3233732e6f6c2e6cull,0x2c33373172250920ull,0x202c363631722520ull,
0x61090a3b37317225ull,0x09203233732e6464ull,0x25202c3437317225ull,0x7225202c39353172ull,
0x6461090a3b333731ull,0x2509203233732e64ull,0x7225202c35373172ull,0x317225202c323731ull,
0x766964090a3b3437ull,0x722509203233732eull,0x317225202c363731ull,0x36317225202c3537ull,
0x636f6c2e090a3b37ull,0x0931353109363109ull,0x6c2e6c756d090a30ull,0x2509203233732e6full,
0x7225202c37373172ull,0x317225202c363631ull,0x2e646461090a3b38ull,0x3172250920323373ull,
0x36317225202c3837ull,0x3737317225202c32ull,0x732e646461090a3bull,0x3731722509203233ull,
0x3237317225202c39ull,0x3b3837317225202cull,0x33732e766964090aull,0x3038317225092032ull,
0x2c3937317225202cull,0x0a3b373631722520ull,0x626f6c672e747309ull,0x38752e32762e6c61ull,
0x2b346472255b0920ull,0x3172257b202c5d30ull,0x30383172252c3637ull,0x636f6c2e090a3b7dull,
0x0932353109363109ull,0x6c2e6c756d090a30ull,0x2509203233732e6full,0x7225202c31383172ull,
0x317225202c363631ull,0x2e646461090a3b39ull,0x3172250920323373ull,0x36317225202c3238ull,
0x3138317225202c35ull,0x732e646461090a3bull,0x3831722509203233ull,0x3237317225202c33ull,
0x3b3238317225202cull,0x33732e766964090aull,0x3438317225092032ull,0x2c3338317225202cull,
0x0a3b373631722520ull,0x626f6c672e747309ull,0x5b092038752e6c61ull,0x2c5d322b34647225ull,
0x0a3b343831722520ull,0x36345f345f744c24ull,0x744c240a3a323830ull,0x32323533345f345full,
0x09636f6c2e090a3aull,0x3009353531093631ull,0x0a3b74697865090aull,0x5f646e6557444c24ull,
0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645664930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x32535f32535f3253ull,0x3a6269695f30535full,0x5f202f2f207d090aull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645664930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f32535f32535f32ull,0x0a0a6269695f3053ull,0x207972746e652e09ull,
0x646e614d36315a5full,0x5f31746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,
0x5f32535f54696969ull,0x32535f32535f3253ull,0x206269695f30535full,0x7261702e09090a28ull,
0x203436752e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x32535f32535f3253ull,
0x695f30535f32535full,0x0a2c7473645f6269ull,0x6d617261702e0909ull,0x5f5f203233732e20ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45644930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,
0x2c576567616d695full,0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x486567616d695f62ull,
0x7261702e09090a2cull,0x203233732e206d61ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,
0x32535f32535f3253ull,0x695f30535f32535full,0x636e7572635f6269ull,0x61702e09090a2c68ull,
0x3436662e206d6172ull,0x70616475635f5f20ull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x66664f785f626969ull,0x7261702e09090a2cull,0x203436662e206d61ull,
0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,
0x6863753650764564ull,0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,
0x2c66664f795f6269ull,0x617261702e09090aull,0x5f203436662e206dull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x090a2c504a785f62ull,
0x206d617261702e09ull,0x635f5f203436662eull,0x5f6d726170616475ull,0x646e614d36315a5full,
0x5f31746f72626c65ull,0x7645644930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,
0x32535f32535f3253ull,0x5f6269695f30535full,0x2e09090a2c504a79ull,0x662e206d61726170ull,
0x6475635f5f203436ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,
0x63735f6269695f30ull,0x2e09090a2c656c61ull,0x612e206d61726170ull,0x2e2034206e67696cull,
0x6475635f5f203862ull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,
0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,
0x6f635f6269695f30ull,0x2c5d345b73726f6cull,0x617261702e09090aull,0x5f203233732e206dull,
0x726170616475635full,0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,
0x6168637536507645ull,0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,
0x2c656d6172665f62ull,0x617261702e09090aull,0x5f203233732e206dull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x74616d696e615f62ull,
0x656d6172466e6f69ull,0x7261702e09090a2cull,0x5f2038732e206d61ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x090a294a73695f62ull,
0x206765722e090a7bull,0x687225203631752eull,0x722e090a3b3e363cull,0x203233752e206765ull,
0x3b3e3638313c7225ull,0x2e206765722e090aull,0x3c64722520343675ull,0x722e090a3b3e3231ull,
0x203436662e206765ull,0x3e3631313c646625ull,0x206765722e090a3bull,0x702520646572702eull,
0x2e090a3b3e30353cull,0x3109363109636f6cull,0x424c240a30093530ull,0x4d36315a5f5f3142ull,
0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,
0x32535f32535f3253ull,0x695f30535f32535full,0x766f6d090a3a6269ull,0x722509203631752eull,
0x61746325202c3168ull,0x6d090a3b782e6469ull,0x09203631752e766full,0x6e25202c32687225ull,
0x090a3b782e646974ull,0x656469772e6c756dull,0x722509203631752eull,0x2c31687225202c31ull,
0x090a3b3268722520ull,0x203631752e766f6dull,0x25202c3368722509ull,0x3b792e6469617463ull,
0x31752e766f6d090aull,0x2c34687225092036ull,0x792e6469746e2520ull,0x772e6c756d090a3bull,
0x203631752e656469ull,0x7225202c32722509ull,0x34687225202c3368ull,0x752e747663090a3bull,
0x09203631752e3233ull,0x697425202c337225ull,0x6461090a3b782e64ull,0x2509203233752e64ull,
0x2c337225202c3472ull,0x63090a3b31722520ull,0x752e3233752e7476ull,0x2c35722509203631ull,
0x3b792e6469742520ull,0x33752e646461090aull,0x202c367225092032ull,0x327225202c357225ull,
0x61702e646c090a3bull,0x203233732e6d6172ull,0x5f5b202c37722509ull,0x726170616475635full,
0x614d36315a5f5f6dull,0x746f72626c65646eull,0x644930316d735f31ull,0x6168637536507645ull,
0x535f546969693472ull,0x5f32535f32535f32ull,0x69695f30535f3253ull,0x486567616d695f62ull,
0x702e646c090a3b5dull,0x3233732e6d617261ull,0x5b202c3872250920ull,0x6170616475635f5full,
0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,0x4930316d735f3174ull,0x6863753650764564ull,
0x5f54696969347261ull,0x32535f32535f3253ull,0x695f30535f32535full,0x6567616d695f6269ull,
0x746573090a3b5d57ull,0x2e3233752e74672eull,0x3972250920323373ull,0x25202c377225202cull,
0x67656e090a3b3672ull,0x722509203233732eull,0x3b397225202c3031ull,0x74672e746573090aull,
0x3233732e3233752eull,0x202c313172250920ull,0x347225202c387225ull,0x732e67656e090a3bull,
0x3231722509203233ull,0x0a3b31317225202cull,0x3233622e646e6109ull,0x202c333172250920ull,
0x7225202c30317225ull,0x766f6d090a3b3231ull,0x722509203233752eull,0x090a3b30202c3431ull,
0x2e71652e70746573ull,0x3170250920323373ull,0x202c33317225202cull,0x40090a3b34317225ull,
0x2061726220317025ull,0x345f355f744c2409ull,0x2e090a3b32323533ull,0x3109363109636f6cull,
0x756d090a30093331ull,0x3233732e6f6c2e6cull,0x202c353172250920ull,0x367225202c387225ull,
0x732e646461090a3bull,0x3631722509203233ull,0x25202c347225202cull,0x646c090a3b353172ull,
0x752e6d617261702eull,0x3164722509203436ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764564493031ull,0x6969347261686375ull,
0x32535f32535f5469ull,0x535f32535f32535full,0x73645f6269695f30ull,0x747663090a3b5d74ull,
0x3233732e3436752eull,0x202c326472250920ull,0x6d090a3b36317225ull,0x36752e6f6c2e6c75ull,
0x2c33647225092034ull,0x34202c3264722520ull,0x752e646461090a3bull,0x3464722509203436ull,
0x202c31647225202cull,0x6c090a3b33647225ull,0x6c61626f6c672e64ull,0x092038752e34762eull,
0x72252c373172257bull,0x2c393172252c3831ull,0x6472255b202c7d5full,0x6d090a3b5d302b34ull,
0x09203233752e766full,0x3b30202c30327225ull,0x6c2e70746573090aull,0x2509203233732e65ull,
0x2c347225202c3270ull,0x090a3b3032722520ull,0x6172622032702540ull,0x5f355f744c240920ull,
0x090a3b3039323434ull,0x61626f6c672e646cull,0x2038752e34762e6cull,0x252c313272257b09ull,
0x333272252c323272ull,0x72255b202c7d5f2cull,0x0a3b5d342d2b3464ull,0x363109636f6c2e09ull,
0x090a300938313109ull,0x203233732e627573ull,0x25202c3432722509ull,0x317225202c333272ull,
0x2e736261090a3b39ull,0x3272250920323373ull,0x3b34327225202c35ull,0x33732e766f6d090aull,
0x2c36327225092032ull,0x6573090a3b303120ull,0x3233752e74672e74ull,0x722509203233732eull,
0x35327225202c3732ull,0x0a3b36327225202cull,0x3233732e67656e09ull,0x202c383272250920ull,
0x73090a3b37327225ull,0x09203233732e6275ull,0x7225202c39327225ull,0x37317225202c3132ull,
0x732e736261090a3bull,0x3033722509203233ull,0x0a3b39327225202cull,0x3233732e766f6d09ull,
0x202c313372250920ull,0x746573090a3b3031ull,0x2e3233752e74672eull,0x3372250920323373ull,
0x2c30337225202c32ull,0x090a3b3133722520ull,0x203233732e67656eull,0x25202c3333722509ull,
0x7573090a3b323372ull,0x2509203233732e62ull,0x327225202c343372ull,0x3b38317225202c32ull,
0x33732e736261090aull,0x2c35337225092032ull,0x090a3b3433722520ull,0x203233732e766f6dull,
0x31202c3633722509ull,0x2e746573090a3b30ull,0x732e3233752e7467ull,0x3733722509203233ull,
0x202c35337225202cull,0x6e090a3b36337225ull,0x09203233732e6765ull,0x7225202c38337225ull,
0x2e726f090a3b3733ull,0x3372250920323362ull,0x2c33337225202c39ull,0x090a3b3833722520ull,
0x09203233622e726full,0x7225202c30347225ull,0x39337225202c3832ull,0x752e617262090a3bull,
0x5f744c240920696eull,0x3b34333034345f35ull,0x345f355f744c240aull,0x6d090a3a30393234ull,
0x09203233732e766full,0x3b30202c30347225ull,0x345f355f744c240aull,0x61090a3a34333034ull,
0x09203233732e6464ull,0x7225202c31347225ull,0x73090a3b31202c34ull,0x732e656c2e707465ull,
0x2c33702509203233ull,0x7225202c38722520ull,0x702540090a3b3134ull,0x2409206172622033ull,
0x3534345f355f744cull,0x2e646c090a3b3634ull,0x762e6c61626f6c67ull,0x257b092038752e34ull,
0x333472252c323472ull,0x7d5f2c343472252cull,0x2b346472255b202cull,0x6f6c2e090a3b5d34ull,
0x3032310936310963ull,0x2e627573090a3009ull,0x3472250920323373ull,0x2c34347225202c35ull,
0x090a3b3931722520ull,0x203233732e736261ull,0x25202c3634722509ull,0x6f6d090a3b353472ull,
0x2509203233732e76ull,0x3b3031202c373472ull,0x74672e746573090aull,0x3233732e3233752eull,
0x202c383472250920ull,0x7225202c36347225ull,0x67656e090a3b3734ull,0x722509203233732eull,
0x38347225202c3934ull,0x732e627573090a3bull,0x3035722509203233ull,0x202c32347225202cull,
0x61090a3b37317225ull,0x09203233732e7362ull,0x7225202c31357225ull,0x766f6d090a3b3035ull,
0x722509203233732eull,0x0a3b3031202c3235ull,0x2e74672e74657309ull,0x203233732e323375ull,
0x25202c3335722509ull,0x357225202c313572ull,0x2e67656e090a3b32ull,0x3572250920323373ull,
0x3b33357225202c34ull,0x33732e627573090aull,0x2c35357225092032ull,0x25202c3334722520ull,
0x6261090a3b383172ull,0x2509203233732e73ull,0x357225202c363572ull,0x2e766f6d090a3b35ull,
0x3572250920323373ull,0x090a3b3031202c37ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x7225202c38357225ull,0x37357225202c3635ull,0x732e67656e090a3bull,0x3935722509203233ull,
0x0a3b38357225202cull,0x203233622e726f09ull,0x25202c3036722509ull,0x357225202c343572ull,
0x622e726f090a3b39ull,0x3136722509203233ull,0x202c39347225202cull,0x61090a3b30367225ull,
0x09203233732e6464ull,0x7225202c30347225ull,0x31367225202c3034ull,0x5f355f744c240a3bull,
0x090a3a3634353434ull,0x203233752e766f6dull,0x30202c3236722509ull,0x2e70746573090a3bull,
0x09203233732e656cull,0x367225202c347025ull,0x0a3b32367225202cull,0x7262203470254009ull,
0x355f744c24092061ull,0x0a3b38353035345full,0x363109636f6c2e09ull,0x090a300932323109ull,
0x203233732e627573ull,0x25202c3336722509ull,0x387225202c363172ull,0x732e747663090a3bull,
0x09203233732e3436ull,0x7225202c35647225ull,0x6c756d090a3b3336ull,0x203436752e6f6c2eull,
0x25202c3664722509ull,0x0a3b34202c356472ull,0x3436752e64646109ull,0x202c376472250920ull,
0x7225202c31647225ull,0x2e646c090a3b3664ull,0x762e6c61626f6c67ull,0x257b092038752e34ull,
0x353672252c343672ull,0x7d5f2c363672252cull,0x2b376472255b202cull,0x627573090a3b5d30ull,
0x722509203233732eull,0x36367225202c3736ull,0x0a3b39317225202cull,0x3233732e73626109ull,
0x202c383672250920ull,0x6d090a3b37367225ull,0x09203233732e766full,0x3031202c39367225ull,
0x672e746573090a3bull,0x33732e3233752e74ull,0x2c30377225092032ull,0x25202c3836722520ull,
0x656e090a3b393672ull,0x2509203233732e67ull,0x377225202c313772ull,0x2e627573090a3b30ull,
0x3772250920323373ull,0x2c34367225202c32ull,0x090a3b3731722520ull,0x203233732e736261ull,
0x25202c3337722509ull,0x6f6d090a3b323772ull,0x2509203233732e76ull,0x3b3031202c343772ull,
0x74672e746573090aull,0x3233732e3233752eull,0x202c353772250920ull,0x7225202c33377225ull,
0x67656e090a3b3437ull,0x722509203233732eull,0x35377225202c3637ull,0x732e627573090a3bull,
0x3737722509203233ull,0x202c35367225202cull,0x61090a3b38317225ull,0x09203233732e7362ull,
0x7225202c38377225ull,0x766f6d090a3b3737ull,0x722509203233732eull,0x0a3b3031202c3937ull,
0x2e74672e74657309ull,0x203233732e323375ull,0x25202c3038722509ull,0x377225202c383772ull,
0x2e67656e090a3b39ull,0x3872250920323373ull,0x3b30387225202c31ull,0x3233622e726f090aull,
0x202c323872250920ull,0x7225202c36377225ull,0x2e726f090a3b3138ull,0x3872250920323362ull,
0x2c31377225202c33ull,0x090a3b3238722520ull,0x203233732e646461ull,0x25202c3034722509ull,
0x387225202c303472ull,0x355f744c240a3b33ull,0x0a3a38353035345full,0x3233732e64646109ull,
0x202c343872250920ull,0x0a3b31202c367225ull,0x656c2e7074657309ull,0x702509203233732eull,
0x202c377225202c35ull,0x40090a3b34387225ull,0x2061726220357025ull,0x345f355f744c2409ull,
0x2e090a3b30373535ull,0x3109363109636f6cull,0x6461090a30093432ull,0x2509203233732e64ull,
0x317225202c353872ull,0x0a3b387225202c36ull,0x3436732e74766309ull,0x722509203233732eull,
0x35387225202c3864ull,0x6c2e6c756d090a3bull,0x2509203436752e6full,0x647225202c396472ull,
0x61090a3b34202c38ull,0x09203436752e6464ull,0x25202c3031647225ull,0x647225202c316472ull,
0x672e646c090a3b39ull,0x34762e6c61626f6cull,0x72257b092038752eull,0x2c373872252c3638ull,
0x2c7d5f2c38387225ull,0x2b30316472255b20ull,0x627573090a3b5d30ull,0x722509203233732eull,
0x38387225202c3938ull,0x0a3b39317225202cull,0x3233732e73626109ull,0x202c303972250920ull,
0x6d090a3b39387225ull,0x09203233732e766full,0x3031202c31397225ull,0x672e746573090a3bull,
0x33732e3233752e74ull,0x2c32397225092032ull,0x25202c3039722520ull,0x656e090a3b313972ull,
0x2509203233732e67ull,0x397225202c333972ull,0x2e627573090a3b32ull,0x3972250920323373ull,
0x2c36387225202c34ull,0x090a3b3731722520ull,0x203233732e736261ull,0x25202c3539722509ull,
0x6f6d090a3b343972ull,0x2509203233732e76ull,0x3b3031202c363972ull,0x74672e746573090aull,
0x3233732e3233752eull,0x202c373972250920ull,0x7225202c35397225ull,0x67656e090a3b3639ull,
0x722509203233732eull,0x37397225202c3839ull,0x732e627573090a3bull,0x3939722509203233ull,
0x202c37387225202cull,0x61090a3b38317225ull,0x09203233732e7362ull,0x25202c3030317225ull,
0x6f6d090a3b393972ull,0x2509203233732e76ull,0x3031202c31303172ull,0x672e746573090a3bull,
0x33732e3233752e74ull,0x3230317225092032ull,0x2c3030317225202cull,0x0a3b313031722520ull,
0x3233732e67656e09ull,0x2c33303172250920ull,0x0a3b323031722520ull,0x203233622e726f09ull,
0x202c343031722509ull,0x7225202c38397225ull,0x726f090a3b333031ull,0x722509203233622eull,
0x397225202c353031ull,0x3430317225202c33ull,0x732e646461090a3bull,0x3034722509203233ull,
0x202c30347225202cull,0x240a3b3530317225ull,0x3535345f355f744cull,0x766f6d090a3a3037ull,
0x722509203233752eull,0x0a3b30202c363031ull,0x71652e7074657309ull,0x702509203233732eull,
0x2c30347225202c36ull,0x0a3b363031722520ull,0x7262203670254009ull,0x355f744c24092061ull,
0x0a3b32383036345full,0x353109636f6c2e09ull,0x090a300931333109ull,0x6d617261702e646cull,
0x722509203233732eull,0x5f5f5b202c373031ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x535f32535f32535full,0x6269695f30535f32ull,0x5d68636e7572635full,0x732e766f6d090a3bull,
0x3031722509203233ull,0x3730317225202c38ull,0x61702e646c090a3bull,0x203436662e6d6172ull,
0x5b202c3164662509ull,0x6170616475635f5full,0x4d36315a5f5f6d72ull,0x6f72626c65646e61ull,
0x4930316d735f3174ull,0x6863753650764564ull,0x5f54696969347261ull,0x32535f32535f3253ull,
0x695f30535f32535full,0x656c6163735f6269ull,0x702e646c090a3b5dull,0x3436662e6d617261ull,
0x202c326466250920ull,0x70616475635f5f5bull,0x36315a5f5f6d7261ull,0x72626c65646e614dull,
0x30316d735f31746full,0x6375365076456449ull,0x5469696934726168ull,0x535f32535f32535full,
0x5f30535f32535f32ull,0x66664f785f626969ull,0x2e747663090a3b5dull,0x732e3436662e6e72ull,
0x3364662509203233ull,0x090a3b347225202cull,0x662e6e722e64616dull,0x3464662509203436ull,
0x202c33646625202cull,0x6625202c31646625ull,0x2e646c090a3b3264ull,0x36662e6d61726170ull,
0x2c35646625092034ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,0x626c65646e614d36ull,
0x316d735f31746f72ull,0x7536507645644930ull,0x6969693472616863ull,0x5f32535f32535f54ull,
0x30535f32535f3253ull,0x664f795f6269695full,0x747663090a3b5d66ull,0x2e3436662e6e722eull,
0x6466250920323373ull,0x0a3b367225202c36ull,0x2e6e722e64616d09ull,0x6466250920343666ull,
0x2c36646625202c37ull,0x25202c3164662520ull,0x646c090a3b356466ull,0x732e6d617261702eull,
0x3930317225092038ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,
0x6d735f31746f7262ull,0x3650764564493031ull,0x6969347261686375ull,0x32535f32535f5469ull,
0x535f32535f32535full,0x73695f6269695f30ull,0x766f6d090a3b5d4aull,0x722509203233752eull,
0x0a3b30202c303131ull,0x71652e7074657309ull,0x702509203233732eull,0x3930317225202c37ull,
0x3b3031317225202cull,0x622037702540090aull,0x5f744c2409206172ull,0x3b30353836345f35ull,
0x3109636f6c2e090aull,0x0a30093633310935ull,0x617261702e646c09ull,0x2509203436662e6dull,
0x5f5f5b202c386466ull,0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,
0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,
0x6269695f30535f32ull,0x090a3b5d504a785full,0x09353109636f6c2eull,0x6c090a3009373331ull,
0x2e6d617261702e64ull,0x6466250920343666ull,0x75635f5f5b202c39ull,0x5f5f6d7261706164ull,
0x65646e614d36315aull,0x735f31746f72626cull,0x507645644930316dull,0x6934726168637536ull,
0x535f32535f546969ull,0x5f32535f32535f32ull,0x795f6269695f3053ull,0x6c2e090a3b5d504aull,
0x333109353109636full,0x766f6d090a300938ull,0x662509203436662eull,0x646625202c303164ull,
0x636f6c2e090a3b37ull,0x0939333109353109ull,0x662e766f6d090a30ull,0x3164662509203436ull,
0x3b34646625202c31ull,0x3109636f6c2e090aull,0x0a30093034310935ull,0x3436662e6c756d09ull,
0x2c32316466250920ull,0x25202c3764662520ull,0x6c2e090a3b376466ull,0x343109353109636full,
0x6c756d090a300931ull,0x662509203436662eull,0x646625202c333164ull,0x3b34646625202c34ull,
0x6e752e617262090aull,0x355f744c24092069ull,0x0a3b34393536345full,0x36345f355f744c24ull,
0x6c2e090a3a303538ull,0x343109353109636full,0x766f6d090a300935ull,0x662509203436662eull,
0x34646625202c3864ull,0x09636f6c2e090a3bull,0x3009363431093531ull,0x36662e766f6d090aull,
0x2c39646625092034ull,0x090a3b3764662520ull,0x09353109636f6c2eull,0x6d090a3009303531ull,
0x09203436662e766full,0x30202c3331646625ull,0x3030303030303064ull,0x3030303030303030ull,
0x0a30202f2f093b30ull,0x3436662e766f6d09ull,0x2c32316466250920ull,0x3030303030643020ull,
0x3030303030303030ull,0x202f2f093b303030ull,0x662e766f6d090a30ull,0x3164662509203436ull,
0x3030306430202c31ull,0x3030303030303030ull,0x2f093b3030303030ull,0x766f6d090a30202full,
0x662509203436662eull,0x306430202c303164ull,0x3030303030303030ull,0x3b30303030303030ull,
0x4c240a30202f2f09ull,0x393536345f355f74ull,0x2e766f6d090a3a34ull,0x3172250920323373ull,
0x090a3b30202c3131ull,0x2e656c2e70746573ull,0x3870250920323373ull,0x2c3730317225202cull,
0x0a3b313131722520ull,0x37325f355f744c24ull,0x2f2f200a3a343933ull,0x4c203e706f6f6c3cull,
0x79646f6220706f6full,0x353120656e696c20ull,0x09636f6c2e090a35ull,0x3009353531093531ull,
0x622038702540090aull,0x355f4c2409206172ull,0x0a3b38333533335full,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,
0x6c6562616c206461ull,0x355f744c24206465ull,0x090a34393337325full,0x203436662e646461ull,
0x202c343164662509ull,0x25202c3331646625ull,0x6d090a3b32316466ull,0x09203436662e766full,
0x30202c3531646625ull,0x3030303031303464ull,0x3030303030303030ull,0x0a34202f2f093b30ull,
0x74672e7074657309ull,0x702509203436662eull,0x3431646625202c39ull,0x3b3531646625202cull,
0x203970252140090aull,0x5f4c240920617262ull,0x3b32383233335f35ull,0x33335f355f4c240aull,
0x6f6d090a3a383335ull,0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b383031ull,
0x240920696e752e61ull,0x3835325f355f744cull,0x335f355f4c240a3bull,0x2f200a3a32383233ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f355f744c2420ull,0x6c2e090a34393337ull,
0x353109353109636full,0x6c756d090a300937ull,0x662509203436662eull,0x646625202c363164ull,
0x31646625202c3131ull,0x2e646461090a3b30ull,0x6466250920343666ull,0x31646625202c3731ull,
0x3631646625202c36ull,0x662e646461090a3bull,0x3164662509203436ull,0x2c39646625202c30ull,
0x0a3b373164662520ull,0x353109636f6c2e09ull,0x090a300938353109ull,0x203436662e627573ull,
0x202c383164662509ull,0x25202c3331646625ull,0x61090a3b32316466ull,0x09203436662e6464ull,
0x25202c3131646625ull,0x646625202c386466ull,0x6f6c2e090a3b3831ull,0x3935310935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3931ull,0x3031646625202c30ull,
0x09636f6c2e090a3bull,0x3009373531093531ull,0x33732e627573090aull,0x3331317225092032ull,
0x2c3830317225202cull,0x766f6d090a3b3120ull,0x722509203233752eull,0x0a3b30202c343131ull,
0x656c2e7074657309ull,0x702509203233732eull,0x31317225202c3031ull,0x3431317225202c33ull,
0x3031702540090a3bull,0x4c24092061726220ull,0x30353034335f355full,0x6f6c3c2f2f200a3bull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f355full,0x36662e6c756d090aull,
0x3032646625092034ull,0x2c3131646625202cull,0x0a3b313164662520ull,0x3436662e64646109ull,
0x2c31326466250920ull,0x202c303264662520ull,0x090a3b3931646625ull,0x203436662e766f6dull,
0x202c323264662509ull,0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,
0x672e70746573090aull,0x2509203436662e74ull,0x646625202c313170ull,0x32646625202c3132ull,
0x70252140090a3b32ull,0x0920617262203131ull,0x3733335f355f4c24ull,0x355f4c240a3b3439ull,
0x0a3a30353034335full,0x3233732e766f6d09ull,0x2c32313172250920ull,0x0a3b333131722520ull,
0x696e752e61726209ull,0x5f355f744c240920ull,0x5f4c240a3b383532ull,0x3a34393733335f35ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34393337325f35ull,
0x353109636f6c2e09ull,0x090a300936363109ull,0x203436662e6c756dull,0x202c363164662509ull,
0x25202c3131646625ull,0x61090a3b30316466ull,0x09203436662e6464ull,0x25202c3332646625ull,
0x6625202c36316466ull,0x6461090a3b363164ull,0x2509203436662e64ull,0x6625202c30316466ull,
0x32646625202c3964ull,0x636f6c2e090a3b33ull,0x0937363109353109ull,0x662e627573090a30ull,
0x3264662509203436ull,0x3032646625202c34ull,0x3b3931646625202cull,0x36662e646461090aull,
0x3131646625092034ull,0x202c38646625202cull,0x090a3b3432646625ull,0x09353109636f6c2eull,
0x6d090a3009383631ull,0x09203436662e6c75ull,0x25202c3532646625ull,0x6625202c30316466ull,
0x6c2e090a3b303164ull,0x363109353109636full,0x627573090a300936ull,0x722509203233732eull,
0x317225202c353131ull,0x090a3b32202c3830ull,0x203233752e766f6dull,0x202c363131722509ull,
0x70746573090a3b30ull,0x203233732e656c2eull,0x25202c3231702509ull,0x7225202c35313172ull,
0x2540090a3b363131ull,0x2061726220323170ull,0x34335f355f4c2409ull,0x2f2f200a3b323635ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x37325f355f744c24ull,0x6c756d090a343933ull,
0x662509203436662eull,0x646625202c303264ull,0x31646625202c3131ull,0x2e646461090a3b31ull,
0x6466250920343666ull,0x32646625202c3632ull,0x3532646625202c30ull,0x662e766f6d090a3bull,
0x3264662509203436ull,0x3130346430202c37ull,0x3030303030303030ull,0x2f093b3030303030ull,
0x746573090a34202full,0x3436662e74672e70ull,0x202c333170250920ull,0x25202c3632646625ull,
0x40090a3b37326466ull,0x7262203331702521ull,0x5f355f4c24092061ull,0x240a3b3630333433ull,
0x363534335f355f4cull,0x2e766f6d090a3a32ull,0x3172250920323373ull,0x31317225202c3231ull,
0x2e617262090a3b35ull,0x744c240920696e75ull,0x0a3b3835325f355full,0x3334335f355f4c24ull,
0x3c2f2f200a3a3630ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3337325f355f744cull,
0x636f6c2e090a3439ull,0x0935373109353109ull,0x662e6c756d090a30ull,0x3164662509203436ull,
0x3131646625202c36ull,0x3b3031646625202cull,0x36662e646461090aull,0x3832646625092034ull,
0x2c3631646625202cull,0x0a3b363164662520ull,0x3436662e64646109ull,0x2c30316466250920ull,
0x25202c3964662520ull,0x2e090a3b38326466ull,0x3109353109636f6cull,0x7573090a30093637ull,
0x2509203436662e62ull,0x6625202c39326466ull,0x646625202c303264ull,0x646461090a3b3532ull,
0x662509203436662eull,0x646625202c313164ull,0x3932646625202c38ull,0x09636f6c2e090a3bull,
0x3009373731093531ull,0x36662e6c756d090aull,0x3033646625092034ull,0x2c3031646625202cull,
0x0a3b303164662520ull,0x353109636f6c2e09ull,0x090a300935373109ull,0x203233732e627573ull,
0x202c373131722509ull,0x33202c3830317225ull,0x752e766f6d090a3bull,0x3131722509203233ull,
0x73090a3b30202c38ull,0x732e656c2e707465ull,0x3431702509203233ull,0x2c3731317225202cull,
0x0a3b383131722520ull,0x6220343170254009ull,0x355f4c2409206172ull,0x0a3b34373035335full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c35353120ull,0x6c6562616c206461ull,0x355f744c24206465ull,0x090a34393337325full,
0x203436662e6c756dull,0x202c303264662509ull,0x25202c3131646625ull,0x61090a3b31316466ull,
0x09203436662e6464ull,0x25202c3133646625ull,0x6625202c30326466ull,0x6f6d090a3b303364ull,
0x2509203436662e76ull,0x6430202c32336466ull,0x3030303030313034ull,0x3030303030303030ull,
0x090a34202f2f093bull,0x2e74672e70746573ull,0x3170250920343666ull,0x3133646625202c35ull,
0x3b3233646625202cull,0x353170252140090aull,0x4c24092061726220ull,0x38313834335f355full,
0x335f355f4c240a3bull,0x6d090a3a34373035ull,0x09203233732e766full,0x25202c3231317225ull,
0x62090a3b37313172ull,0x0920696e752e6172ull,0x35325f355f744c24ull,0x5f355f4c240a3b38ull,
0x200a3a3831383433ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,0x5f355f744c242064ull,
0x2e090a3439333732ull,0x3109353109636f6cull,0x756d090a30093438ull,0x2509203436662e6cull,
0x6625202c36316466ull,0x646625202c313164ull,0x646461090a3b3031ull,0x662509203436662eull,
0x646625202c333364ull,0x31646625202c3631ull,0x2e646461090a3b36ull,0x6466250920343666ull,
0x39646625202c3031ull,0x3b3333646625202cull,0x3109636f6c2e090aull,0x0a30093538310935ull,
0x3436662e62757309ull,0x2c34336466250920ull,0x202c303264662520ull,0x090a3b3033646625ull,
0x203436662e646461ull,0x202c313164662509ull,0x6625202c38646625ull,0x6c2e090a3b343364ull,
0x383109353109636full,0x6c756d090a300936ull,0x662509203436662eull,0x646625202c353364ull,
0x31646625202c3031ull,0x636f6c2e090a3b30ull,0x0934383109353109ull,0x732e627573090a30ull,
0x3131722509203233ull,0x3830317225202c39ull,0x6f6d090a3b34202cull,0x2509203233752e76ull,
0x3b30202c30323172ull,0x6c2e70746573090aull,0x2509203233732e65ull,0x317225202c363170ull,
0x32317225202c3931ull,0x31702540090a3b30ull,0x2409206172622036ull,0x383535335f355f4cull,
0x6c3c2f2f200a3b36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,
0x2c35353120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,0x393337325f355f74ull,
0x662e6c756d090a34ull,0x3264662509203436ull,0x3131646625202c30ull,0x3b3131646625202cull,
0x36662e646461090aull,0x3633646625092034ull,0x2c3032646625202cull,0x0a3b353364662520ull,
0x3436662e766f6d09ull,0x2c37336466250920ull,0x3030313034643020ull,0x3030303030303030ull,
0x202f2f093b303030ull,0x2e70746573090a34ull,0x09203436662e7467ull,0x6625202c37317025ull,
0x646625202c363364ull,0x252140090a3b3733ull,0x2061726220373170ull,0x35335f355f4c2409ull,
0x5f4c240a3b303333ull,0x3a36383535335f35ull,0x33732e766f6d090aull,0x3231317225092032ull,
0x3b3931317225202cull,0x6e752e617262090aull,0x355f744c24092069ull,0x4c240a3b3835325full,
0x30333335335f355full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34393337325f355full,0x3109636f6c2e090aull,0x0a30093339310935ull,0x3436662e6c756d09ull,
0x2c36316466250920ull,0x202c313164662520ull,0x090a3b3031646625ull,0x203436662e646461ull,
0x202c383364662509ull,0x25202c3631646625ull,0x61090a3b36316466ull,0x09203436662e6464ull,
0x25202c3031646625ull,0x646625202c396466ull,0x6f6c2e090a3b3833ull,0x3439310935310963ull,
0x2e627573090a3009ull,0x6466250920343666ull,0x32646625202c3933ull,0x3533646625202c30ull,
0x662e646461090a3bull,0x3164662509203436ull,0x2c38646625202c31ull,0x0a3b393364662520ull,
0x353109636f6c2e09ull,0x090a300935393109ull,0x203436662e6c756dull,0x202c303464662509ull,
0x25202c3031646625ull,0x2e090a3b30316466ull,0x3109353109636f6cull,0x7573090a30093339ull,
0x2509203233732e62ull,0x7225202c31323172ull,0x0a3b35202c383031ull,0x3233752e766f6d09ull,
0x2c32323172250920ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c383170250920ull,
0x25202c3132317225ull,0x40090a3b32323172ull,0x6172622038317025ull,0x335f355f4c240920ull,
0x2f200a3b38393036ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x325f355f744c2420ull,
0x756d090a34393337ull,0x2509203436662e6cull,0x6625202c30326466ull,0x646625202c313164ull,
0x646461090a3b3131ull,0x662509203436662eull,0x646625202c313464ull,0x34646625202c3032ull,
0x2e766f6d090a3b30ull,0x6466250920343666ull,0x30346430202c3234ull,0x3030303030303031ull,
0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,0x2c39317025092034ull,
0x202c313464662520ull,0x090a3b3234646625ull,0x6220393170252140ull,0x355f4c2409206172ull,
0x0a3b32343835335full,0x3036335f355f4c24ull,0x766f6d090a3a3839ull,0x722509203233732eull,
0x317225202c323131ull,0x617262090a3b3132ull,0x4c240920696e752eull,0x3b3835325f355f74ull,
0x35335f355f4c240aull,0x2f2f200a3a323438ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,
0x37325f355f744c24ull,0x6f6c2e090a343933ull,0x3230320935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x31646625202c3631ull,0x3031646625202c31ull,0x662e646461090a3bull,
0x3464662509203436ull,0x3631646625202c33ull,0x3b3631646625202cull,0x36662e646461090aull,
0x3031646625092034ull,0x202c39646625202cull,0x090a3b3334646625ull,0x09353109636f6c2eull,
0x73090a3009333032ull,0x09203436662e6275ull,0x25202c3434646625ull,0x6625202c30326466ull,
0x6461090a3b303464ull,0x2509203436662e64ull,0x6625202c31316466ull,0x34646625202c3864ull,
0x636f6c2e090a3b34ull,0x0934303209353109ull,0x662e6c756d090a30ull,0x3464662509203436ull,
0x3031646625202c35ull,0x3b3031646625202cull,0x3109636f6c2e090aull,0x0a30093230320935ull,
0x3233732e62757309ull,0x2c33323172250920ull,0x202c383031722520ull,0x2e766f6d090a3b36ull,
0x3172250920323375ull,0x090a3b30202c3432ull,0x2e656c2e70746573ull,0x3270250920323373ull,
0x3332317225202c30ull,0x3b3432317225202cull,0x203032702540090aull,0x5f4c240920617262ull,
0x3b30313636335f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34393337325f35ull,0x3436662e6c756d09ull,0x2c30326466250920ull,0x202c313164662520ull,
0x090a3b3131646625ull,0x203436662e646461ull,0x202c363464662509ull,0x25202c3032646625ull,
0x6d090a3b35346466ull,0x09203436662e766full,0x30202c3734646625ull,0x3030303031303464ull,
0x3030303030303030ull,0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,
0x34646625202c3132ull,0x3734646625202c36ull,0x3270252140090a3bull,0x2409206172622031ull,
0x353336335f355f4cull,0x5f355f4c240a3b34ull,0x090a3a3031363633ull,0x203233732e766f6dull,
0x202c323131722509ull,0x090a3b3332317225ull,0x20696e752e617262ull,0x325f355f744c2409ull,
0x355f4c240a3b3835ull,0x0a3a34353336335full,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c35353120ull,0x6c6562616c206461ull,
0x355f744c24206465ull,0x090a34393337325full,0x09353109636f6c2eull,0x6d090a3009313132ull,
0x09203436662e6c75ull,0x25202c3631646625ull,0x6625202c31316466ull,0x6461090a3b303164ull,
0x2509203436662e64ull,0x6625202c38346466ull,0x646625202c363164ull,0x646461090a3b3631ull,
0x662509203436662eull,0x646625202c303164ull,0x3834646625202c39ull,0x09636f6c2e090a3bull,
0x3009323132093531ull,0x36662e627573090aull,0x3934646625092034ull,0x2c3032646625202cull,
0x0a3b353464662520ull,0x3436662e64646109ull,0x2c31316466250920ull,0x25202c3864662520ull,
0x2e090a3b39346466ull,0x3209353109636f6cull,0x756d090a30093331ull,0x2509203436662e6cull,
0x6625202c30356466ull,0x646625202c303164ull,0x6f6c2e090a3b3031ull,0x3131320935310963ull,
0x2e627573090a3009ull,0x3172250920323373ull,0x30317225202c3532ull,0x6d090a3b37202c38ull,
0x09203233752e766full,0x30202c3632317225ull,0x2e70746573090a3bull,0x09203233732e656cull,
0x7225202c32327025ull,0x317225202c353231ull,0x702540090a3b3632ull,0x0920617262203232ull,
0x3137335f355f4c24ull,0x3c2f2f200a3b3232ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x35353120656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3337325f355f744cull,0x2e6c756d090a3439ull,0x6466250920343666ull,0x31646625202c3032ull,
0x3131646625202c31ull,0x662e646461090a3bull,0x3564662509203436ull,0x3032646625202c31ull,
0x3b3035646625202cull,0x36662e766f6d090aull,0x3235646625092034ull,0x303130346430202cull,
0x3030303030303030ull,0x2f2f093b30303030ull,0x70746573090a3420ull,0x203436662e74672eull,
0x25202c3332702509ull,0x6625202c31356466ull,0x2140090a3b323564ull,0x6172622033327025ull,
0x335f355f4c240920ull,0x4c240a3b36363836ull,0x32323137335f355full,0x732e766f6d090a3aull,
0x3131722509203233ull,0x3532317225202c32ull,0x752e617262090a3bull,0x5f744c240920696eull,
0x240a3b3835325f35ull,0x363836335f355f4cull,0x6c3c2f2f200a3a36ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x393337325f355f74ull,0x09636f6c2e090a34ull,0x3009303232093531ull,
0x36662e6c756d090aull,0x3631646625092034ull,0x2c3131646625202cull,0x0a3b303164662520ull,
0x3436662e64646109ull,0x2c33356466250920ull,0x202c363164662520ull,0x090a3b3631646625ull,
0x203436662e646461ull,0x202c303164662509ull,0x6625202c39646625ull,0x6c2e090a3b333564ull,
0x323209353109636full,0x627573090a300931ull,0x662509203436662eull,0x646625202c343564ull,
0x35646625202c3032ull,0x2e646461090a3b30ull,0x6466250920343666ull,0x38646625202c3131ull,
0x3b3435646625202cull,0x3109636f6c2e090aull,0x0a30093232320935ull,0x3436662e6c756d09ull,
0x2c35356466250920ull,0x202c303164662520ull,0x090a3b3031646625ull,0x09353109636f6c2eull,
0x73090a3009303232ull,0x09203233732e6275ull,0x25202c3732317225ull,0x3b38202c38303172ull,
0x33752e766f6d090aull,0x3832317225092032ull,0x6573090a3b30202cull,0x33732e656c2e7074ull,
0x2c34327025092032ull,0x202c373231722520ull,0x090a3b3832317225ull,0x7262203432702540ull,
0x5f355f4c24092061ull,0x200a3b3433363733ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,
0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c353531ull,0x656c6562616c2064ull,
0x5f355f744c242064ull,0x6d090a3439333732ull,0x09203436662e6c75ull,0x25202c3032646625ull,
0x6625202c31316466ull,0x6461090a3b313164ull,0x2509203436662e64ull,0x6625202c36356466ull,
0x646625202c303264ull,0x766f6d090a3b3535ull,0x662509203436662eull,0x346430202c373564ull,
0x3030303030303130ull,0x3b30303030303030ull,0x73090a34202f2f09ull,0x662e74672e707465ull,
0x3532702509203436ull,0x2c3635646625202cull,0x0a3b373564662520ull,0x2035327025214009ull,
0x5f4c240920617262ull,0x3b38373337335f35ull,0x37335f355f4c240aull,0x6f6d090a3a343336ull,
0x2509203233732e76ull,0x7225202c32313172ull,0x7262090a3b373231ull,0x240920696e752e61ull,
0x3835325f355f744cull,0x335f355f4c240a3bull,0x2f200a3a38373337ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x325f355f744c2420ull,0x6c2e090a34393337ull,0x323209353109636full,
0x6c756d090a300939ull,0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,
0x2e646461090a3b30ull,0x6466250920343666ull,0x31646625202c3835ull,0x3631646625202c36ull,
0x662e646461090a3bull,0x3164662509203436ull,0x2c39646625202c30ull,0x0a3b383564662520ull,
0x353109636f6c2e09ull,0x090a300930333209ull,0x203436662e627573ull,0x202c393564662509ull,
0x25202c3032646625ull,0x61090a3b35356466ull,0x09203436662e6464ull,0x25202c3131646625ull,
0x646625202c386466ull,0x6f6c2e090a3b3935ull,0x3133320935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x31646625202c3036ull,0x3031646625202c30ull,0x09636f6c2e090a3bull,
0x3009393232093531ull,0x33732e627573090aull,0x3932317225092032ull,0x2c3830317225202cull,
0x766f6d090a3b3920ull,0x722509203233752eull,0x0a3b30202c303331ull,0x656c2e7074657309ull,
0x702509203233732eull,0x32317225202c3632ull,0x3033317225202c39ull,0x3632702540090a3bull,
0x4c24092061726220ull,0x36343138335f355full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x34393337325f355full,0x36662e6c756d090aull,0x3032646625092034ull,
0x2c3131646625202cull,0x0a3b313164662520ull,0x3436662e64646109ull,0x2c31366466250920ull,
0x202c303264662520ull,0x090a3b3036646625ull,0x203436662e766f6dull,0x202c323664662509ull,
0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,0x672e70746573090aull,
0x2509203436662e74ull,0x646625202c373270ull,0x36646625202c3136ull,0x70252140090a3b32ull,
0x0920617262203732ull,0x3837335f355f4c24ull,0x355f4c240a3b3039ull,0x0a3a36343138335full,
0x3233732e766f6d09ull,0x2c32313172250920ull,0x0a3b393231722520ull,0x696e752e61726209ull,
0x5f355f744c240920ull,0x5f4c240a3b383532ull,0x3a30393837335f35ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x0a34393337325f35ull,0x353109636f6c2e09ull,
0x090a300938333209ull,0x203436662e6c756dull,0x202c363164662509ull,0x25202c3131646625ull,
0x61090a3b30316466ull,0x09203436662e6464ull,0x25202c3336646625ull,0x6625202c36316466ull,
0x6461090a3b363164ull,0x2509203436662e64ull,0x6625202c30316466ull,0x36646625202c3964ull,
0x636f6c2e090a3b33ull,0x0939333209353109ull,0x662e627573090a30ull,0x3664662509203436ull,
0x3032646625202c34ull,0x3b3036646625202cull,0x36662e646461090aull,0x3131646625092034ull,
0x202c38646625202cull,0x090a3b3436646625ull,0x09353109636f6c2eull,0x6d090a3009303432ull,
0x09203436662e6c75ull,0x25202c3536646625ull,0x6625202c30316466ull,0x6c2e090a3b303164ull,
0x333209353109636full,0x627573090a300938ull,0x722509203233732eull,0x317225202c313331ull,
0x0a3b3031202c3830ull,0x3233752e766f6d09ull,0x2c32333172250920ull,0x746573090a3b3020ull,
0x3233732e656c2e70ull,0x202c383270250920ull,0x25202c3133317225ull,0x40090a3b32333172ull,
0x6172622038327025ull,0x335f355f4c240920ull,0x2f200a3b38353638ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,
0x64656c6562616c20ull,0x325f355f744c2420ull,0x756d090a34393337ull,0x2509203436662e6cull,
0x6625202c30326466ull,0x646625202c313164ull,0x646461090a3b3131ull,0x662509203436662eull,
0x646625202c363664ull,0x36646625202c3032ull,0x2e766f6d090a3b35ull,0x6466250920343666ull,
0x30346430202c3736ull,0x3030303030303031ull,0x093b303030303030ull,0x6573090a34202f2full,
0x36662e74672e7074ull,0x2c39327025092034ull,0x202c363664662520ull,0x090a3b3736646625ull,
0x6220393270252140ull,0x355f4c2409206172ull,0x0a3b32303438335full,0x3638335f355f4c24ull,
0x766f6d090a3a3835ull,0x722509203233732eull,0x317225202c323131ull,0x617262090a3b3133ull,
0x4c240920696e752eull,0x3b3835325f355f74ull,0x38335f355f4c240aull,0x2f2f200a3a323034ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,
0x2064616568202c35ull,0x2064656c6562616cull,0x37325f355f744c24ull,0x6f6c2e090a343933ull,
0x3734320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3631ull,
0x3031646625202c31ull,0x662e646461090a3bull,0x3664662509203436ull,0x3631646625202c38ull,
0x3b3631646625202cull,0x36662e646461090aull,0x3031646625092034ull,0x202c39646625202cull,
0x090a3b3836646625ull,0x09353109636f6c2eull,0x73090a3009383432ull,0x09203436662e6275ull,
0x25202c3936646625ull,0x6625202c30326466ull,0x6461090a3b353664ull,0x2509203436662e64ull,
0x6625202c31316466ull,0x36646625202c3864ull,0x636f6c2e090a3b39ull,0x0939343209353109ull,
0x662e6c756d090a30ull,0x3764662509203436ull,0x3031646625202c30ull,0x3b3031646625202cull,
0x3109636f6c2e090aull,0x0a30093734320935ull,0x3233732e62757309ull,0x2c33333172250920ull,
0x202c383031722520ull,0x766f6d090a3b3131ull,0x722509203233752eull,0x0a3b30202c343331ull,
0x656c2e7074657309ull,0x702509203233732eull,0x33317225202c3033ull,0x3433317225202c33ull,
0x3033702540090a3bull,0x4c24092061726220ull,0x30373139335f355full,0x6f6c3c2f2f200a3bull,
0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c35353120656eull,
0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f355full,0x36662e6c756d090aull,
0x3032646625092034ull,0x2c3131646625202cull,0x0a3b313164662520ull,0x3436662e64646109ull,
0x2c31376466250920ull,0x202c303264662520ull,0x090a3b3037646625ull,0x203436662e766f6dull,
0x202c323764662509ull,0x3030303130346430ull,0x3030303030303030ull,0x34202f2f093b3030ull,
0x672e70746573090aull,0x2509203436662e74ull,0x646625202c313370ull,0x37646625202c3137ull,
0x70252140090a3b32ull,0x0920617262203133ull,0x3938335f355f4c24ull,0x355f4c240a3b3431ull,
0x0a3a30373139335full,0x3233732e766f6d09ull,0x2c32313172250920ull,0x0a3b333331722520ull,
0x696e752e61726209ull,0x5f355f744c240920ull,0x5f4c240a3b383532ull,0x3a34313938335f35ull,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x0a34393337325f35ull,
0x353109636f6c2e09ull,0x090a300936353209ull,0x203436662e6c756dull,0x202c363164662509ull,
0x25202c3131646625ull,0x61090a3b30316466ull,0x09203436662e6464ull,0x25202c3337646625ull,
0x6625202c36316466ull,0x6461090a3b363164ull,0x2509203436662e64ull,0x6625202c30316466ull,
0x37646625202c3964ull,0x636f6c2e090a3b33ull,0x0937353209353109ull,0x662e627573090a30ull,
0x3764662509203436ull,0x3032646625202c34ull,0x3b3037646625202cull,0x36662e646461090aull,
0x3131646625092034ull,0x202c38646625202cull,0x090a3b3437646625ull,0x09353109636f6c2eull,
0x6d090a3009383532ull,0x09203436662e6c75ull,0x25202c3537646625ull,0x6625202c30316466ull,
0x6c2e090a3b303164ull,0x353209353109636full,0x627573090a300936ull,0x722509203233732eull,
0x317225202c353331ull,0x0a3b3231202c3830ull,0x3233752e766f6d09ull,0x2c36333172250920ull,
0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c323370250920ull,0x25202c3533317225ull,
0x40090a3b36333172ull,0x6172622032337025ull,0x335f355f4c240920ull,0x2f200a3b32383639ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f355f744c2420ull,0x756d090a34393337ull,
0x2509203436662e6cull,0x6625202c30326466ull,0x646625202c313164ull,0x646461090a3b3131ull,
0x662509203436662eull,0x646625202c363764ull,0x37646625202c3032ull,0x2e766f6d090a3b35ull,
0x6466250920343666ull,0x30346430202c3737ull,0x3030303030303031ull,0x093b303030303030ull,
0x6573090a34202f2full,0x36662e74672e7074ull,0x2c33337025092034ull,0x202c363764662520ull,
0x090a3b3737646625ull,0x6220333370252140ull,0x355f4c2409206172ull,0x0a3b36323439335full,
0x3639335f355f4c24ull,0x766f6d090a3a3238ull,0x722509203233732eull,0x317225202c323131ull,
0x617262090a3b3533ull,0x4c240920696e752eull,0x3b3835325f355f74ull,0x39335f355f4c240aull,
0x2f2f200a3a363234ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,0x37325f355f744c24ull,
0x6f6c2e090a343933ull,0x3536320935310963ull,0x2e6c756d090a3009ull,0x6466250920343666ull,
0x31646625202c3631ull,0x3031646625202c31ull,0x662e646461090a3bull,0x3764662509203436ull,
0x3631646625202c38ull,0x3b3631646625202cull,0x36662e646461090aull,0x3031646625092034ull,
0x202c39646625202cull,0x090a3b3837646625ull,0x09353109636f6c2eull,0x73090a3009363632ull,
0x09203436662e6275ull,0x25202c3937646625ull,0x6625202c30326466ull,0x6461090a3b353764ull,
0x2509203436662e64ull,0x6625202c31316466ull,0x37646625202c3864ull,0x636f6c2e090a3b39ull,
0x0937363209353109ull,0x662e6c756d090a30ull,0x3864662509203436ull,0x3031646625202c30ull,
0x3b3031646625202cull,0x3109636f6c2e090aull,0x0a30093536320935ull,0x3233732e62757309ull,
0x2c37333172250920ull,0x202c383031722520ull,0x766f6d090a3b3331ull,0x722509203233752eull,
0x0a3b30202c383331ull,0x656c2e7074657309ull,0x702509203233732eull,0x33317225202c3433ull,
0x3833317225202c37ull,0x3433702540090a3bull,0x4c24092061726220ull,0x34393130345f355full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f355full,
0x36662e6c756d090aull,0x3032646625092034ull,0x2c3131646625202cull,0x0a3b313164662520ull,
0x3436662e64646109ull,0x2c31386466250920ull,0x202c303264662520ull,0x090a3b3038646625ull,
0x203436662e766f6dull,0x202c323864662509ull,0x3030303130346430ull,0x3030303030303030ull,
0x34202f2f093b3030ull,0x672e70746573090aull,0x2509203436662e74ull,0x646625202c353370ull,
0x38646625202c3138ull,0x70252140090a3b32ull,0x0920617262203533ull,0x3939335f355f4c24ull,
0x355f4c240a3b3833ull,0x0a3a34393130345full,0x3233732e766f6d09ull,0x2c32313172250920ull,
0x0a3b373331722520ull,0x696e752e61726209ull,0x5f355f744c240920ull,0x5f4c240a3b383532ull,
0x3a38333939335f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x0a34393337325f35ull,0x353109636f6c2e09ull,0x090a300934373209ull,0x203436662e6c756dull,
0x202c363164662509ull,0x25202c3131646625ull,0x61090a3b30316466ull,0x09203436662e6464ull,
0x25202c3338646625ull,0x6625202c36316466ull,0x6461090a3b363164ull,0x2509203436662e64ull,
0x6625202c30316466ull,0x38646625202c3964ull,0x636f6c2e090a3b33ull,0x0935373209353109ull,
0x662e627573090a30ull,0x3864662509203436ull,0x3032646625202c34ull,0x3b3038646625202cull,
0x36662e646461090aull,0x3131646625092034ull,0x202c38646625202cull,0x090a3b3438646625ull,
0x09353109636f6c2eull,0x6d090a3009363732ull,0x09203436662e6c75ull,0x25202c3538646625ull,
0x6625202c30316466ull,0x6c2e090a3b303164ull,0x373209353109636full,0x627573090a300934ull,
0x722509203233732eull,0x317225202c393331ull,0x0a3b3431202c3830ull,0x3233752e766f6d09ull,
0x2c30343172250920ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,0x202c363370250920ull,
0x25202c3933317225ull,0x40090a3b30343172ull,0x6172622036337025ull,0x345f355f4c240920ull,
0x2f200a3b36303730ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,0x325f355f744c2420ull,
0x756d090a34393337ull,0x2509203436662e6cull,0x6625202c30326466ull,0x646625202c313164ull,
0x646461090a3b3131ull,0x662509203436662eull,0x646625202c363864ull,0x38646625202c3032ull,
0x2e766f6d090a3b35ull,0x6466250920343666ull,0x30346430202c3738ull,0x3030303030303031ull,
0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,0x2c37337025092034ull,
0x202c363864662520ull,0x090a3b3738646625ull,0x6220373370252140ull,0x355f4c2409206172ull,
0x0a3b30353430345full,0x3730345f355f4c24ull,0x766f6d090a3a3630ull,0x722509203233732eull,
0x317225202c323131ull,0x617262090a3b3933ull,0x4c240920696e752eull,0x3b3835325f355f74ull,
0x30345f355f4c240aull,0x2f2f200a3a303534ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,0x2064656c6562616cull,
0x37325f355f744c24ull,0x6f6c2e090a343933ull,0x3338320935310963ull,0x2e6c756d090a3009ull,
0x6466250920343666ull,0x31646625202c3631ull,0x3031646625202c31ull,0x662e646461090a3bull,
0x3864662509203436ull,0x3631646625202c38ull,0x3b3631646625202cull,0x36662e646461090aull,
0x3031646625092034ull,0x202c39646625202cull,0x090a3b3838646625ull,0x09353109636f6c2eull,
0x73090a3009343832ull,0x09203436662e6275ull,0x25202c3938646625ull,0x6625202c30326466ull,
0x6461090a3b353864ull,0x2509203436662e64ull,0x6625202c31316466ull,0x38646625202c3864ull,
0x636f6c2e090a3b39ull,0x0935383209353109ull,0x662e6c756d090a30ull,0x3964662509203436ull,
0x3031646625202c30ull,0x3b3031646625202cull,0x3109636f6c2e090aull,0x0a30093338320935ull,
0x3233732e62757309ull,0x2c31343172250920ull,0x202c383031722520ull,0x766f6d090a3b3531ull,
0x722509203233752eull,0x0a3b30202c323431ull,0x656c2e7074657309ull,0x702509203233732eull,
0x34317225202c3833ull,0x3234317225202c31ull,0x3833702540090a3bull,0x4c24092061726220ull,
0x38313231345f355full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34393337325f355full,0x36662e6c756d090aull,0x3032646625092034ull,0x2c3131646625202cull,
0x0a3b313164662520ull,0x3436662e64646109ull,0x2c31396466250920ull,0x202c303264662520ull,
0x090a3b3039646625ull,0x203436662e766f6dull,0x202c323964662509ull,0x3030303130346430ull,
0x3030303030303030ull,0x34202f2f093b3030ull,0x672e70746573090aull,0x2509203436662e74ull,
0x646625202c393370ull,0x39646625202c3139ull,0x70252140090a3b32ull,0x0920617262203933ull,
0x3930345f355f4c24ull,0x355f4c240a3b3236ull,0x0a3a38313231345full,0x3233732e766f6d09ull,
0x2c32313172250920ull,0x0a3b313431722520ull,0x696e752e61726209ull,0x5f355f744c240920ull,
0x5f4c240a3b383532ull,0x3a32363930345f35ull,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3535312065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x0a34393337325f35ull,0x353109636f6c2e09ull,0x090a300932393209ull,
0x203436662e6c756dull,0x202c363164662509ull,0x25202c3131646625ull,0x61090a3b30316466ull,
0x09203436662e6464ull,0x25202c3339646625ull,0x6625202c36316466ull,0x6461090a3b363164ull,
0x2509203436662e64ull,0x6625202c30316466ull,0x39646625202c3964ull,0x636f6c2e090a3b33ull,
0x0933393209353109ull,0x662e627573090a30ull,0x3964662509203436ull,0x3032646625202c34ull,
0x3b3039646625202cull,0x36662e646461090aull,0x3131646625092034ull,0x202c38646625202cull,
0x090a3b3439646625ull,0x09353109636f6c2eull,0x6d090a3009343932ull,0x09203436662e6c75ull,
0x25202c3539646625ull,0x6625202c30316466ull,0x6c2e090a3b303164ull,0x393209353109636full,
0x627573090a300932ull,0x722509203233732eull,0x317225202c333431ull,0x0a3b3631202c3830ull,
0x3233752e766f6d09ull,0x2c34343172250920ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,
0x202c303470250920ull,0x25202c3334317225ull,0x40090a3b34343172ull,0x6172622030347025ull,
0x345f355f4c240920ull,0x2f200a3b30333731ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x325f355f744c2420ull,0x756d090a34393337ull,0x2509203436662e6cull,0x6625202c30326466ull,
0x646625202c313164ull,0x646461090a3b3131ull,0x662509203436662eull,0x646625202c363964ull,
0x39646625202c3032ull,0x2e766f6d090a3b35ull,0x6466250920343666ull,0x30346430202c3739ull,
0x3030303030303031ull,0x093b303030303030ull,0x6573090a34202f2full,0x36662e74672e7074ull,
0x2c31347025092034ull,0x202c363964662520ull,0x090a3b3739646625ull,0x6220313470252140ull,
0x355f4c2409206172ull,0x0a3b34373431345full,0x3731345f355f4c24ull,0x766f6d090a3a3033ull,
0x722509203233732eull,0x317225202c323131ull,0x617262090a3b3334ull,0x4c240920696e752eull,
0x3b3835325f355f74ull,0x31345f355f4c240aull,0x2f2f200a3a343734ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x353120656e696c20ull,0x2064616568202c35ull,
0x2064656c6562616cull,0x37325f355f744c24ull,0x6f6c2e090a343933ull,0x3130330935310963ull,
0x2e6c756d090a3009ull,0x6466250920343666ull,0x31646625202c3631ull,0x3031646625202c31ull,
0x662e646461090a3bull,0x3964662509203436ull,0x3631646625202c38ull,0x3b3631646625202cull,
0x36662e646461090aull,0x3031646625092034ull,0x202c39646625202cull,0x090a3b3839646625ull,
0x09353109636f6c2eull,0x73090a3009323033ull,0x09203436662e6275ull,0x25202c3939646625ull,
0x6625202c30326466ull,0x6461090a3b353964ull,0x2509203436662e64ull,0x6625202c31316466ull,
0x39646625202c3864ull,0x636f6c2e090a3b39ull,0x0933303309353109ull,0x662e6c756d090a30ull,
0x3164662509203436ull,0x31646625202c3030ull,0x3031646625202c30ull,0x09636f6c2e090a3bull,
0x3009313033093531ull,0x33732e627573090aull,0x3534317225092032ull,0x2c3830317225202cull,
0x6f6d090a3b373120ull,0x2509203233752e76ull,0x3b30202c36343172ull,0x6c2e70746573090aull,
0x2509203233732e65ull,0x317225202c323470ull,0x34317225202c3534ull,0x34702540090a3b36ull,
0x2409206172622032ull,0x343232345f355f4cull,0x6c3c2f2f200a3b32ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c35353120656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x393337325f355f74ull,0x662e6c756d090a34ull,0x3264662509203436ull,
0x3131646625202c30ull,0x3b3131646625202cull,0x36662e646461090aull,0x3031646625092034ull,
0x3032646625202c31ull,0x303031646625202cull,0x662e766f6d090a3bull,0x3164662509203436ull,
0x30346430202c3230ull,0x3030303030303031ull,0x093b303030303030ull,0x6573090a34202f2full,
0x36662e74672e7074ull,0x2c33347025092034ull,0x2c31303164662520ull,0x3b32303164662520ull,
0x333470252140090aull,0x4c24092061726220ull,0x36383931345f355full,0x345f355f4c240a3bull,
0x6d090a3a32343232ull,0x09203233732e766full,0x25202c3231317225ull,0x62090a3b35343172ull,
0x0920696e752e6172ull,0x35325f355f744c24ull,0x5f355f4c240a3b38ull,0x200a3a3638393134ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c353531ull,0x656c6562616c2064ull,0x5f355f744c242064ull,0x2e090a3439333732ull,
0x3309353109636f6cull,0x756d090a30093031ull,0x2509203436662e6cull,0x6625202c36316466ull,
0x646625202c313164ull,0x646461090a3b3031ull,0x662509203436662eull,0x6625202c33303164ull,
0x646625202c363164ull,0x646461090a3b3631ull,0x662509203436662eull,0x646625202c303164ull,
0x3031646625202c39ull,0x636f6c2e090a3b33ull,0x0931313309353109ull,0x662e627573090a30ull,
0x3164662509203436ull,0x32646625202c3430ull,0x3031646625202c30ull,0x2e646461090a3b30ull,
0x6466250920343666ull,0x38646625202c3131ull,0x343031646625202cull,0x09636f6c2e090a3bull,
0x3009323133093531ull,0x36662e6c756d090aull,0x3031646625092034ull,0x3031646625202c35ull,
0x3b3031646625202cull,0x3109636f6c2e090aull,0x0a30093031330935ull,0x3233732e62757309ull,
0x2c37343172250920ull,0x202c383031722520ull,0x766f6d090a3b3831ull,0x722509203233752eull,
0x0a3b30202c383431ull,0x656c2e7074657309ull,0x702509203233732eull,0x34317225202c3434ull,
0x3834317225202c37ull,0x3434702540090a3bull,0x4c24092061726220ull,0x34353732345f355full,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x34393337325f355full,
0x36662e6c756d090aull,0x3032646625092034ull,0x2c3131646625202cull,0x0a3b313164662520ull,
0x3436662e64646109ull,0x3630316466250920ull,0x2c3032646625202cull,0x3b35303164662520ull,
0x36662e766f6d090aull,0x3031646625092034ull,0x3130346430202c37ull,0x3030303030303030ull,
0x2f093b3030303030ull,0x746573090a34202full,0x3436662e74672e70ull,0x202c353470250920ull,
0x202c363031646625ull,0x0a3b373031646625ull,0x2035347025214009ull,0x5f4c240920617262ull,
0x3b38393432345f35ull,0x32345f355f4c240aull,0x6f6d090a3a343537ull,0x2509203233732e76ull,
0x7225202c32313172ull,0x7262090a3b373431ull,0x240920696e752e61ull,0x3835325f355f744cull,
0x345f355f4c240a3bull,0x2f200a3a38393432ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3535ull,0x64656c6562616c20ull,
0x325f355f744c2420ull,0x6c2e090a34393337ull,0x313309353109636full,0x6c756d090a300939ull,
0x662509203436662eull,0x646625202c363164ull,0x31646625202c3131ull,0x2e646461090a3b30ull,
0x6466250920343666ull,0x646625202c383031ull,0x31646625202c3631ull,0x2e646461090a3b36ull,
0x6466250920343666ull,0x39646625202c3031ull,0x383031646625202cull,0x09636f6c2e090a3bull,
0x3009303233093531ull,0x36662e627573090aull,0x3031646625092034ull,0x3032646625202c39ull,
0x353031646625202cull,0x662e646461090a3bull,0x3164662509203436ull,0x2c38646625202c31ull,
0x3b39303164662520ull,0x3109636f6c2e090aull,0x0a30093132330935ull,0x3436662e6c756d09ull,
0x3031316466250920ull,0x2c3031646625202cull,0x0a3b303164662520ull,0x353109636f6c2e09ull,
0x090a300935323309ull,0x203233732e627573ull,0x202c383031722509ull,0x31202c3830317225ull,
0x636f6c2e090a3b39ull,0x0939313309353109ull,0x732e766f6d090a30ull,0x3431722509203233ull,
0x73090a3b30202c39ull,0x732e656c2e707465ull,0x2c38702509203233ull,0x202c383031722520ull,
0x090a3b3934317225ull,0x6172622038702540ull,0x345f355f4c240920ull,0x2f200a3b36363233ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3535ull,0x64656c6562616c20ull,0x325f355f744c2420ull,0x756d090a34393337ull,
0x2509203436662e6cull,0x6625202c30326466ull,0x646625202c313164ull,0x646461090a3b3131ull,
0x662509203436662eull,0x6625202c31313164ull,0x646625202c303264ull,0x6f6d090a3b303131ull,
0x2509203436662e76ull,0x30202c3231316466ull,0x3030303031303464ull,0x3030303030303030ull,
0x0a34202f2f093b30ull,0x74672e7074657309ull,0x702509203436662eull,0x31646625202c3634ull,
0x31646625202c3131ull,0x252140090a3b3231ull,0x2061726220363470ull,0x33345f355f4c2409ull,
0x5f4c240a3b303130ull,0x3a36363233345f35ull,0x33732e766f6d090aull,0x3231317225092032ull,
0x3b3830317225202cull,0x6e752e617262090aull,0x355f744c24092069ull,0x4c240a3b3835325full,
0x30313033345f355full,0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c35353120656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x34393337325f355full,0x3109636f6c2e090aull,0x0a30093832330935ull,0x3436662e6c756d09ull,
0x2c36316466250920ull,0x202c313164662520ull,0x090a3b3031646625ull,0x203436662e646461ull,
0x2c33313164662509ull,0x202c363164662520ull,0x090a3b3631646625ull,0x203436662e646461ull,
0x202c303164662509ull,0x6625202c39646625ull,0x2e090a3b33313164ull,0x3309353109636f6cull,
0x7573090a30093932ull,0x2509203436662e62ull,0x25202c3431316466ull,0x6625202c30326466ull,
0x61090a3b30313164ull,0x09203436662e6464ull,0x25202c3131646625ull,0x646625202c386466ull,
0x6c2e090a3b343131ull,0x333309353109636full,0x6c756d090a300930ull,0x662509203436662eull,
0x646625202c323164ull,0x31646625202c3031ull,0x636f6c2e090a3b30ull,0x0931333309353109ull,
0x662e6c756d090a30ull,0x3164662509203436ull,0x3131646625202c33ull,0x3b3131646625202cull,
0x3109636f6c2e090aull,0x0a30093832330935ull,0x696e752e61726209ull,0x5f355f744c240920ull,
0x240a3b3439333732ull,0x3835325f355f744cull,0x09636f6c2e090a3aull,0x3009313331093631ull,
0x33732e766f6d090aull,0x3035317225092032ull,0x6573090a3b30202cull,0x33732e74672e7074ull,
0x2c37347025092032ull,0x202c323131722520ull,0x090a3b3035317225ull,0x203233732e627573ull,
0x202c313531722509ull,0x25202c3730317225ull,0x6d090a3b32313172ull,0x09203233732e766full,
0x30202c3235317225ull,0x2e706c6573090a3bull,0x3172250920323373ull,0x35317225202c3335ull,
0x3235317225202c31ull,0x0a3b37347025202cull,0x3233752e766f6d09ull,0x2c34353172250920ull,
0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c383470250920ull,0x25202c3335317225ull,
0x40090a3b34353172ull,0x6172622038347025ull,0x5f355f744c240920ull,0x090a3b3236333734ull,
0x09363109636f6c2eull,0x6c090a3009383331ull,0x2e6d617261702e64ull,0x3172250920323373ull,
0x635f5f5b202c3535ull,0x5f6d726170616475ull,0x646e614d36315a5full,0x5f31746f72626c65ull,
0x7645644930316d73ull,0x3472616863753650ull,0x5f32535f54696969ull,0x32535f32535f3253ull,
0x5f6269695f30535full,0x6f6974616d696e61ull,0x3b5d656d6172466eull,0x33732e646461090aull,
0x3635317225092032ull,0x2c3535317225202cull,0x0a3b333531722520ull,0x617261702e646c09ull,
0x7225092038752e6dull,0x5f5f5b202c373531ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x535f32535f32535full,0x6269695f30535f32ull,0x2b73726f6c6f635full,0x6c756d090a3b5d30ull,
0x203233732e6f6c2eull,0x202c383531722509ull,0x25202c3635317225ull,0x63090a3b37353172ull,
0x33752e38752e7476ull,0x3935317225092032ull,0x3b3835317225202cull,0x3109636f6c2e090aull,
0x0a30093933310936ull,0x617261702e646c09ull,0x7225092038752e6dull,0x5f5f5b202c303631ull,
0x6d72617061647563ull,0x6e614d36315a5f5full,0x31746f72626c6564ull,0x45644930316d735full,
0x7261686375365076ull,0x32535f5469696934ull,0x535f32535f32535full,0x6269695f30535f32ull,
0x2b73726f6c6f635full,0x6c756d090a3b5d31ull,0x203233732e6f6c2eull,0x202c313631722509ull,
0x25202c3635317225ull,0x63090a3b30363172ull,0x33752e38752e7476ull,0x3236317225092032ull,
0x3b3136317225202cull,0x3109636f6c2e090aull,0x0a30093034310936ull,0x617261702e646c09ull,
0x7225092038752e6dull,0x5f5f5b202c333631ull,0x6d72617061647563ull,0x6e614d36315a5f5full,
0x31746f72626c6564ull,0x45644930316d735full,0x7261686375365076ull,0x32535f5469696934ull,
0x535f32535f32535full,0x6269695f30535f32ull,0x2b73726f6c6f635full,0x6c756d090a3b5d32ull,
0x203233732e6f6c2eull,0x202c343631722509ull,0x25202c3635317225ull,0x63090a3b33363172ull,
0x33752e38752e7476ull,0x3536317225092032ull,0x3b3436317225202cull,0x6e752e617262090aull,
0x355f744c24092069ull,0x0a3b36303137345full,0x37345f355f744c24ull,0x6c2e090a3a323633ull,
0x343109363109636full,0x766f6d090a300934ull,0x722509203233752eull,0x0a3b30202c353631ull,
0x3233752e766f6d09ull,0x2c32363172250920ull,0x766f6d090a3b3020ull,0x722509203233752eull,
0x0a3b30202c393531ull,0x37345f355f744c24ull,0x6c2e090a3a363031ull,0x353109363109636full,
0x2e646c090a300930ull,0x33732e6d61726170ull,0x3636317225092032ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6c65646e614d3631ull,0x6d735f31746f7262ull,0x3650764564493031ull,
0x6969347261686375ull,0x32535f32535f5469ull,0x535f32535f32535full,0x72665f6269695f30ull,
0x61090a3b5d656d61ull,0x09203233732e6464ull,0x25202c3736317225ull,0x3b31202c36363172ull,
0x33732e726873090aull,0x3836317225092032ull,0x2c3736317225202cull,0x6f6d090a3b313320ull,
0x2509203233732e76ull,0x3b31202c39363172ull,0x33622e646e61090aull,0x3037317225092032ull,
0x2c3836317225202cull,0x0a3b393631722520ull,0x3233732e64646109ull,0x2c31373172250920ull,
0x202c303731722520ull,0x090a3b3736317225ull,0x203233732e726873ull,0x202c323731722509ull,
0x31202c3137317225ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,0x7225202c33373172ull,
0x317225202c363631ull,0x2e646461090a3b37ull,0x3172250920323373ull,0x35317225202c3437ull,
0x3337317225202c39ull,0x732e646461090a3bull,0x3731722509203233ull,0x3237317225202c35ull,
0x3b3437317225202cull,0x33732e766964090aull,0x3637317225092032ull,0x2c3537317225202cull,
0x0a3b373631722520ull,0x363109636f6c2e09ull,0x090a300931353109ull,0x732e6f6c2e6c756dull,
0x3731722509203233ull,0x3636317225202c37ull,0x0a3b38317225202cull,0x3233732e64646109ull,
0x2c38373172250920ull,0x202c323631722520ull,0x090a3b3737317225ull,0x203233732e646461ull,
0x202c393731722509ull,0x25202c3237317225ull,0x64090a3b38373172ull,0x09203233732e7669ull,
0x25202c3038317225ull,0x7225202c39373172ull,0x7473090a3b373631ull,0x2e6c61626f6c672eull,
0x5b092038752e3276ull,0x2c5d302b34647225ull,0x2c36373172257b20ull,0x0a3b7d3038317225ull,
0x363109636f6c2e09ull,0x090a300932353109ull,0x732e6f6c2e6c756dull,0x3831722509203233ull,
0x3636317225202c31ull,0x0a3b39317225202cull,0x3233732e64646109ull,0x2c32383172250920ull,
0x202c353631722520ull,0x090a3b3138317225ull,0x203233732e646461ull,0x202c333831722509ull,
0x25202c3237317225ull,0x64090a3b32383172ull,0x09203233732e7669ull,0x25202c3438317225ull,
0x7225202c33383172ull,0x7473090a3b373631ull,0x2e6c61626f6c672eull,0x6472255b09203875ull,
0x7225202c5d322b34ull,0x744c240a3b343831ull,0x32383036345f355full,0x5f355f744c240a3aull,
0x090a3a3232353334ull,0x09363109636f6c2eull,0x65090a3009353531ull,0x444c240a3b746978ull,
0x315a5f5f646e6557ull,0x626c65646e614d36ull,0x316d735f31746f72ull,0x7536507645644930ull,
0x6969693472616863ull,0x5f32535f32535f54ull,0x30535f32535f3253ull,0x7d090a3a6269695full,
0x36315a5f202f2f20ull,0x72626c65646e614dull,0x30316d735f31746full,0x6375365076456449ull,
0x5469696934726168ull,0x535f32535f32535full,0x5f30535f32535f32ull,0x0000000a0a626969ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_13",(char*)__deviceText_$sm_13$},{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"7d33fd41b3d20104",(char*)"Mandelbrot_sm10.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x363193e1};
# 5 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 2
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
# 6 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.stub.c" 2




struct __T20 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;char __par14;int __dummy_field;};




struct __T21 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;char __par14;int __dummy_field;};




struct __T22 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};




struct __T23 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};




struct __T24 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};




struct __T25 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;char __par12;int __dummy_field;};
static void __sti____cudaRegisterAll_51_tmpxft_000068e2_00000000_16_Mandelbrot_sm10_cpp1_ii_2099b970(void) __attribute__((__constructor__));
void __device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4 & __par11, const int __par12, const int __par13, const bool __par14){auto struct __T20 *__T2124;
*(void**)(void*)&__T2124 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2124->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2124->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2124->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2124->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2124->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2124->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2124->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2124->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2124->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2124->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2124->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2124->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2124->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2124->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2124->__par14) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10__entry))); };}

}
void MandelbrotDS0_sm10__entry( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const bool __cuda_14)
{__device_stub__Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
extern "C"{

void __device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4 & __par11, const int __par12, const int __par13, const bool __par14){auto struct __T21 *__T2125;
*(void**)(void*)&__T2125 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2125->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2125->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2125->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2125->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2125->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2125->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2125->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2125->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2125->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2125->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2125->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2125->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2125->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2125->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2125->__par14) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10__entry)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10__entry))); };}

}
void MandelbrotDS1_sm10__entry( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const bool __cuda_14)
{__device_stub__Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
extern "C"{

static void __device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4 & __par9, const int __par10, const int __par11, const bool __par12){auto struct __T22 *__T2128;
*(void**)(void*)&__T2128 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2128->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2128->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2128->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2128->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2128->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2128->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2128->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2128->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2128->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2128->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2128->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2128->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2128->__par12) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<float> ))); };}

}
template<> void __wrapper__device_stub_Mandelbrot0_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12)
{__device_stub__Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
extern "C"{

static void __device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4 & __par9, const int __par10, const int __par11, const bool __par12){auto struct __T23 *__T2129;
*(void**)(void*)&__T2129 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2129->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2129->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2129->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2129->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2129->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2129->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2129->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2129->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2129->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2129->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2129->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2129->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2129->__par12) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<double> ))); };}

}
template<> void __wrapper__device_stub_Mandelbrot0_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12)
{__device_stub__Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
extern "C"{

static void __device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4 & __par9, const int __par10, const int __par11, const bool __par12){auto struct __T24 *__T2135;
*(void**)(void*)&__T2135 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2135->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2135->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2135->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2135->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2135->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2135->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2135->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2135->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2135->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2135->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2135->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2135->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2135->__par12) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<float> ))); };}

}
template<> void __wrapper__device_stub_Mandelbrot1_sm10<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12)
{__device_stub__Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
extern "C"{

static void __device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4 & __par9, const int __par10, const int __par11, const bool __par12){auto struct __T25 *__T2136;
*(void**)(void*)&__T2136 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2136->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2136->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2136->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2136->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2136->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2136->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2136->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2136->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2136->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2136->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2136->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2136->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2136->__par12) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<double> ))); };}

}
template<> void __wrapper__device_stub_Mandelbrot1_sm10<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const bool &__cuda_12)
{__device_stub__Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12);}
extern "C"{
# 139 "/tmp/tmpxft_000068e2_00000000-4_Mandelbrot_sm10.cudafe1.stub.c"
static void __sti____cudaRegisterAll_51_tmpxft_000068e2_00000000_16_Mandelbrot_sm10_cpp1_ii_2099b970(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<double> ), (char*)"_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot1_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot1_sm10__entry<float> ), (char*)"_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot1_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<double> ), (char*)"_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot0_sm10IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))Mandelbrot0_sm10__entry<float> ), (char*)"_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", "_Z16Mandelbrot0_sm10IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS1_sm10__entry), (char*)"_Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib", "_Z18MandelbrotDS1_sm10P6uchar4iiifffffffS_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const bool))MandelbrotDS0_sm10__entry), (char*)"_Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib", "_Z18MandelbrotDS0_sm10P6uchar4iiifffffffS_iib", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);}

}
# 276 "Mandelbrot_sm10.cu" 2

# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.cpp"
# 1 "MonteCarlo_SM13.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
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
# 94 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
  cudaErrorInvalidSurface = 37,
  cudaErrorNoDevice = 38,
  cudaErrorECCUncorrectable = 39,
  cudaErrorSharedObjectSymbolNotFound = 40,
  cudaErrorSharedObjectInitFailed = 41,
  cudaErrorUnsupportedLimit = 42,
  cudaErrorDuplicateVariableName = 43,
  cudaErrorDuplicateTextureName = 44,
  cudaErrorDuplicateSurfaceName = 45,
  cudaErrorDevicesUnavailable = 46,
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





struct cudaGraphicsResource;





enum cudaGraphicsRegisterFlags
{
  cudaGraphicsRegisterFlagsNone = 0
};





enum cudaGraphicsMapFlags
{
  cudaGraphicsMapFlagsNone = 0,
  cudaGraphicsMapFlagsReadOnly = 1,
  cudaGraphicsMapFlagsWriteDiscard = 2
};





enum cudaGraphicsCubeFace {
  cudaGraphicsCubeFacePositiveX = 0x00,
  cudaGraphicsCubeFaceNegativeX = 0x01,
  cudaGraphicsCubeFacePositiveY = 0x02,
  cudaGraphicsCubeFaceNegativeY = 0x03,
  cudaGraphicsCubeFacePositiveZ = 0x04,
  cudaGraphicsCubeFaceNegativeZ = 0x05
};





struct cudaFuncAttributes
{
   size_t sharedSizeBytes;
   size_t constSizeBytes;
   size_t localSizeBytes;
   int maxThreadsPerBlock;
   int numRegs;





   int ptxVersion;





   int binaryVersion;
   int __cudaReserved[6];
};





enum cudaFuncCache
{
  cudaFuncCachePreferNone = 0,
  cudaFuncCachePreferShared = 1,
  cudaFuncCachePreferL1 = 2
};





enum cudaComputeMode
{
  cudaComputeModeDefault = 0,
  cudaComputeModeExclusive = 1,
  cudaComputeModeProhibited = 2
};





enum cudaLimit
{
    cudaLimitStackSize = 0x00,
    cudaLimitPrintfFifoSize = 0x01
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
  int maxTexture1D;
  int maxTexture2D[2];
  int maxTexture3D[3];
  int maxTexture2DArray[3];
  size_t surfaceAlignment;
  int concurrentKernels;
  int ECCEnabled;
  int __cudaReserved[24];
};
# 424 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct CUuuid_st cudaUUID_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/surface_types.h" 3
enum cudaSurfaceBoundaryMode
{
  cudaBoundaryModeZero = 0,
  cudaBoundaryModeClamp = 1,
  cudaBoundaryModeTrap = 2
};


enum cudaSurfaceFormatMode
{
  cudaFormatModeForced,
  cudaFormatModeAuto
};


struct surfaceReference
{
  struct cudaChannelFormatDesc channelDesc;
};
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap,
  cudaAddressModeClamp,
  cudaAddressModeMirror
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
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 45 "/usr/local/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 46 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 47 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 75 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct char1
{
  signed char x;
};


struct uchar1
{
  unsigned char x;
};


struct __attribute__((aligned(2))) char2
{
  signed char x, y;
};


struct __attribute__((aligned(2))) uchar2
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


struct __attribute__((aligned(4))) char4
{
  signed char x, y, z, w;
};


struct __attribute__((aligned(4))) uchar4
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


struct __attribute__((aligned(4))) short2
{
  short x, y;
};


struct __attribute__((aligned(4))) ushort2
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


struct __attribute__((aligned(8))) short4 { short x; short y; short z; short w; };


struct __attribute__((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; };


struct int1
{
  int x;
};


struct uint1
{
  unsigned int x;
};


struct __attribute__((aligned(8))) int2 { int x; int y; };


struct __attribute__((aligned(8))) uint2 { unsigned int x; unsigned int y; };


struct int3
{
  int x, y, z;
};


struct uint3
{
  unsigned int x, y, z;
};


struct __attribute__((aligned(16))) int4
{
  int x, y, z, w;
};


struct __attribute__((aligned(16))) uint4
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
# 229 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct __attribute__((aligned(2*sizeof(long int)))) long2
{
  long int x, y;
};


struct __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
};




struct long3
{
  long int x, y, z;
};


struct ulong3
{
  unsigned long int x, y, z;
};


struct __attribute__((aligned(16))) long4
{
  long int x, y, z, w;
};


struct __attribute__((aligned(16))) ulong4
{
  unsigned long int x, y, z, w;
};


struct float1
{
  float x;
};


struct __attribute__((aligned(8))) float2 { float x; float y; };


struct float3
{
  float x, y, z;
};


struct __attribute__((aligned(16))) float4
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


struct __attribute__((aligned(16))) longlong2
{
  long long int x, y;
};


struct __attribute__((aligned(16))) ulonglong2
{
  unsigned long long int x, y;
};


struct longlong3
{
  long long int x, y, z;
};


struct ulonglong3
{
  unsigned long long int x, y, z;
};


struct __attribute__((aligned(16))) longlong4
{
  long long int x, y, z ,w;
};


struct __attribute__((aligned(16))) ulonglong4
{
  unsigned long long int x, y, z, w;
};


struct double1
{
  double x;
};


struct __attribute__((aligned(16))) double2
{
  double x, y;
};


struct double3
{
  double x, y, z;
};


struct __attribute__((aligned(16))) double4
{
  double x, y, z, w;
};
# 366 "/usr/local/cuda/bin/../include/vector_types.h" 3
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

typedef struct longlong3 longlong3;

typedef struct ulonglong3 ulonglong3;

typedef struct longlong4 longlong4;

typedef struct ulonglong4 ulonglong4;

typedef struct double1 double1;

typedef struct double2 double2;

typedef struct double3 double3;

typedef struct double4 double4;
# 469 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 70 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stddef.h" 2 3
# 94 "/usr/local/cuda/bin/../include/driver_types.h"
# 156 "/usr/local/cuda/bin/../include/driver_types.h"
# 168 "/usr/local/cuda/bin/../include/driver_types.h"
# 181 "/usr/local/cuda/bin/../include/driver_types.h"
# 187 "/usr/local/cuda/bin/../include/driver_types.h"
# 200 "/usr/local/cuda/bin/../include/driver_types.h"
# 213 "/usr/local/cuda/bin/../include/driver_types.h"
# 225 "/usr/local/cuda/bin/../include/driver_types.h"
# 236 "/usr/local/cuda/bin/../include/driver_types.h"
# 254 "/usr/local/cuda/bin/../include/driver_types.h"
# 260 "/usr/local/cuda/bin/../include/driver_types.h"
# 269 "/usr/local/cuda/bin/../include/driver_types.h"
# 280 "/usr/local/cuda/bin/../include/driver_types.h"
# 293 "/usr/local/cuda/bin/../include/driver_types.h"
# 319 "/usr/local/cuda/bin/../include/driver_types.h"
# 330 "/usr/local/cuda/bin/../include/driver_types.h"
# 341 "/usr/local/cuda/bin/../include/driver_types.h"
# 351 "/usr/local/cuda/bin/../include/driver_types.h"
# 424 "/usr/local/cuda/bin/../include/driver_types.h"
# 430 "/usr/local/cuda/bin/../include/driver_types.h"
# 436 "/usr/local/cuda/bin/../include/driver_types.h"
# 442 "/usr/local/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda/bin/../include/surface_types.h"
# 62 "/usr/local/cuda/bin/../include/surface_types.h"
# 69 "/usr/local/cuda/bin/../include/surface_types.h"
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
# 62 "/usr/local/cuda/bin/../include/texture_types.h"
# 69 "/usr/local/cuda/bin/../include/texture_types.h"
# 76 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/vector_types.h"
# 81 "/usr/local/cuda/bin/../include/vector_types.h"
# 87 "/usr/local/cuda/bin/../include/vector_types.h"
# 93 "/usr/local/cuda/bin/../include/vector_types.h"
# 99 "/usr/local/cuda/bin/../include/vector_types.h"
# 105 "/usr/local/cuda/bin/../include/vector_types.h"
# 111 "/usr/local/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
# 123 "/usr/local/cuda/bin/../include/vector_types.h"
# 129 "/usr/local/cuda/bin/../include/vector_types.h"
# 135 "/usr/local/cuda/bin/../include/vector_types.h"
# 141 "/usr/local/cuda/bin/../include/vector_types.h"
# 147 "/usr/local/cuda/bin/../include/vector_types.h"
# 153 "/usr/local/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
# 162 "/usr/local/cuda/bin/../include/vector_types.h"
# 165 "/usr/local/cuda/bin/../include/vector_types.h"
# 171 "/usr/local/cuda/bin/../include/vector_types.h"
# 177 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
# 189 "/usr/local/cuda/bin/../include/vector_types.h"
# 195 "/usr/local/cuda/bin/../include/vector_types.h"
# 201 "/usr/local/cuda/bin/../include/vector_types.h"
# 207 "/usr/local/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
# 229 "/usr/local/cuda/bin/../include/vector_types.h"
# 235 "/usr/local/cuda/bin/../include/vector_types.h"
# 243 "/usr/local/cuda/bin/../include/vector_types.h"
# 249 "/usr/local/cuda/bin/../include/vector_types.h"
# 255 "/usr/local/cuda/bin/../include/vector_types.h"
# 261 "/usr/local/cuda/bin/../include/vector_types.h"
# 267 "/usr/local/cuda/bin/../include/vector_types.h"
# 273 "/usr/local/cuda/bin/../include/vector_types.h"
# 276 "/usr/local/cuda/bin/../include/vector_types.h"
# 282 "/usr/local/cuda/bin/../include/vector_types.h"
# 288 "/usr/local/cuda/bin/../include/vector_types.h"
# 294 "/usr/local/cuda/bin/../include/vector_types.h"
# 300 "/usr/local/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
# 312 "/usr/local/cuda/bin/../include/vector_types.h"
# 318 "/usr/local/cuda/bin/../include/vector_types.h"
# 324 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 336 "/usr/local/cuda/bin/../include/vector_types.h"
# 342 "/usr/local/cuda/bin/../include/vector_types.h"
# 348 "/usr/local/cuda/bin/../include/vector_types.h"
# 354 "/usr/local/cuda/bin/../include/vector_types.h"
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
# 90 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0));
# 91 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 92 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 93 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0);
# 101 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0));
# 105 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 109 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 110 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 111 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 119 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 120 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 122 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 125 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 126 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 127 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 128 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 129 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 137 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 139 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 140 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 141 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 142 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 143 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 144 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 152 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 153 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 162 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 171 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 172 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 173 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 174 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 175 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 176 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 185 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 186 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 187 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 188 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 189 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 198 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceAlignmentOffset(size_t *, const surfaceReference *);
# 199 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 208 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 216 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 217 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 218 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 226 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 227 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 228 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache);
# 229 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 230 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 238 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 239 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 240 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 241 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 249 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 250 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
# 251 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0);
# 252 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 253 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 254 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 255 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 263 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 264 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 272 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 273 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 274 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t);
# 275 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit);
# 283 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 284 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 285 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *);
# 294 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource *);
# 295 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource *, unsigned);
# 296 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource **, cudaStream_t = 0);
# 297 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource **, cudaStream_t = 0);
# 298 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource *);
# 299 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource *, unsigned, unsigned);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 94 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 95 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 96 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 98 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 99 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 100 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 102 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 103 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 105 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 106 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 107 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 109 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 110 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 113 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 120 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 127 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 133 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 135 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 138 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 141 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 142 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 145 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 148 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 149 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 152 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 159 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 166 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 173 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 180 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 187 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 194 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 197 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 201 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 204 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 208 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 215 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 222 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 229 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 236 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 243 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 250 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 253 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 257 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 260 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 264 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 271 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 278 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 285 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 292 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 299 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 365 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 366 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 367 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 369 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 370 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 372 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 373 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 374 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 376 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 377 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 380 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 387 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 55 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 56 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 57 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 59 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 60 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 61 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 62 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 64 "/usr/local/cuda/bin/../include/driver_functions.h"
return s;
# 65 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 67 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 68 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 69 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 71 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 72 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 73 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 75 "/usr/local/cuda/bin/../include/driver_functions.h"
return p;
# 76 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 78 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 79 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 80 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 82 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 83 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 84 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 86 "/usr/local/cuda/bin/../include/driver_functions.h"
return e;
# 87 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 55 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 56 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 57 "/usr/local/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 58 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 60 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 61 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 62 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 63 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 65 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 66 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 67 "/usr/local/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 68 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 70 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 71 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 72 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 73 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 75 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 76 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 77 "/usr/local/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 78 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 80 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 81 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 82 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 83 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 85 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 86 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 87 "/usr/local/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 88 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 90 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 91 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 92 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 93 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 95 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 96 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 97 "/usr/local/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 98 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 100 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 101 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 102 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 103 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 105 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 106 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 107 "/usr/local/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 108 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 110 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 111 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 112 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 113 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 115 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 116 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 117 "/usr/local/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 118 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 120 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 121 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 122 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 123 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 125 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 126 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 127 "/usr/local/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 128 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 130 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 131 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 132 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 133 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 135 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 136 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 137 "/usr/local/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 138 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 140 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 141 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 142 "/usr/local/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 143 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 145 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 146 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 147 "/usr/local/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 148 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 150 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 151 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 152 "/usr/local/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 153 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 155 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 156 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 157 "/usr/local/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 158 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 160 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 161 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 162 "/usr/local/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 163 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 165 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 166 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 167 "/usr/local/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 168 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 170 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 171 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 172 "/usr/local/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 173 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 175 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 176 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 177 "/usr/local/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 178 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 180 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 181 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 182 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 183 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 185 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 186 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 187 "/usr/local/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 188 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 190 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 191 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 192 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 193 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 195 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 196 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 197 "/usr/local/cuda/bin/../include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 198 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 200 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 201 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 202 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 203 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 205 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 206 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 207 "/usr/local/cuda/bin/../include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 208 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 210 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 211 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 212 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 213 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 215 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 216 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 217 "/usr/local/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 218 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 220 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 221 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 222 "/usr/local/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 223 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 225 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 226 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 227 "/usr/local/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 228 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 230 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 231 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 232 "/usr/local/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 233 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 235 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 236 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 237 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 238 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 240 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 241 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 242 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 243 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 245 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 246 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 247 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 248 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 250 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 251 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 252 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 253 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 255 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 256 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 257 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 258 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 260 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 261 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 262 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 263 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 265 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 266 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 267 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 268 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 270 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 271 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 272 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 273 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 275 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 276 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 277 "/usr/local/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 278 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 280 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 281 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 282 "/usr/local/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 283 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 285 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 286 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 287 "/usr/local/cuda/bin/../include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 288 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 290 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 291 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 292 "/usr/local/cuda/bin/../include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 293 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 43 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 48 "/usr/include/string.h" 3
extern "C" void *memmove(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 56 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 64 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
# 67 "/usr/include/string.h" 3
extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 74 "/usr/include/string.h" 3
extern void *memchr(void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 76 "/usr/include/string.h" 3
extern const void *memchr(const void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 103 "/usr/include/string.h" 3
void *rawmemchr(void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 105 "/usr/include/string.h" 3
const void *rawmemchr(const void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 114 "/usr/include/string.h" 3
void *memrchr(void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 116 "/usr/include/string.h" 3
const void *memrchr(const void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 127 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 130 "/usr/include/string.h" 3
extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 135 "/usr/include/string.h" 3
extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 138 "/usr/include/string.h" 3
extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 142 "/usr/include/string.h" 3
extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 145 "/usr/include/string.h" 3
extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 149 "/usr/include/string.h" 3
extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 152 "/usr/include/string.h" 3
extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(2)));
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
# 43 "/usr/include/xlocale.h" 3
extern "C" { typedef __locale_t locale_t; }
# 164 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 167 "/usr/include/string.h" 3
extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 173 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__)) __attribute__((nonnull(1)));
# 181 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__)) __attribute__((nonnull(1)));
# 213 "/usr/include/string.h" 3
extern char *strchr(char *, int) throw() __asm__("strchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 215 "/usr/include/string.h" 3
extern const char *strchr(const char *, int) throw() __asm__("strchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 240 "/usr/include/string.h" 3
extern char *strrchr(char *, int) throw() __asm__("strrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 242 "/usr/include/string.h" 3
extern const char *strrchr(const char *, int) throw() __asm__("strrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 269 "/usr/include/string.h" 3
char *strchrnul(char *, int) throw() __asm__("strchrnul") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 271 "/usr/include/string.h" 3
const char *strchrnul(const char *, int) throw() __asm__("strchrnul") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 282 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 286 "/usr/include/string.h" 3
extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 292 "/usr/include/string.h" 3
extern char *strpbrk(char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 294 "/usr/include/string.h" 3
extern const char *strpbrk(const char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 319 "/usr/include/string.h" 3
extern char *strstr(char *, const char *) throw() __asm__("strstr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 321 "/usr/include/string.h" 3
extern const char *strstr(const char *, const char *) throw() __asm__("strstr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 346 "/usr/include/string.h" 3
extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(2)));
# 352 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 357 "/usr/include/string.h" 3
extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 365 "/usr/include/string.h" 3
char *strcasestr(char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 367 "/usr/include/string.h" 3
const char *strcasestr(const char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 380 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 386 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 389 "/usr/include/string.h" 3
extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 397 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 404 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 411 "/usr/include/string.h" 3
extern "C" char *strerror(int) throw();
# 436 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 443 "/usr/include/string.h" 3
extern "C" char *strerror_l(int, __locale_t) throw();
# 449 "/usr/include/string.h" 3
extern "C" void __bzero(void *, size_t) throw() __attribute__((nonnull(1)));
# 453 "/usr/include/string.h" 3
extern "C" void bcopy(const void *, void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 457 "/usr/include/string.h" 3
extern "C" void bzero(void *, size_t) throw() __attribute__((nonnull(1)));
# 460 "/usr/include/string.h" 3
extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 467 "/usr/include/string.h" 3
extern char *index(char *, int) throw() __asm__("index") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 469 "/usr/include/string.h" 3
extern const char *index(const char *, int) throw() __asm__("index") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 495 "/usr/include/string.h" 3
extern char *rindex(char *, int) throw() __asm__("rindex") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 497 "/usr/include/string.h" 3
extern const char *rindex(const char *, int) throw() __asm__("rindex") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 521 "/usr/include/string.h" 3
extern "C" int ffs(int) throw() __attribute__((__const__));
# 526 "/usr/include/string.h" 3
extern "C" int ffsl(long) throw() __attribute__((__const__));
# 528 "/usr/include/string.h" 3
extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 534 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 538 "/usr/include/string.h" 3
extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 545 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 549 "/usr/include/string.h" 3
extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 557 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 564 "/usr/include/string.h" 3
extern "C" char *strsignal(int) throw();
# 567 "/usr/include/string.h" 3
extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 569 "/usr/include/string.h" 3
extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 574 "/usr/include/string.h" 3
extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 577 "/usr/include/string.h" 3
extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 584 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 588 "/usr/include/string.h" 3
extern "C" char *strfry(char *) throw() __attribute__((nonnull(1)));
# 591 "/usr/include/string.h" 3
extern "C" void *memfrob(void *, size_t) throw() __attribute__((nonnull(1)));
# 599 "/usr/include/string.h" 3
char *basename(char *) throw() __asm__("basename") __attribute__((nonnull(1)));
# 601 "/usr/include/string.h" 3
const char *basename(const char *) throw() __asm__("basename") __attribute__((nonnull(1)));
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
extern "C" { typedef struct { int __val[2]; } __fsid_t; }
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
# 122 "/usr/include/time.h" 3
__time_t tv_sec;
# 123 "/usr/include/time.h" 3
long tv_nsec;
# 124 "/usr/include/time.h" 3
}; }
# 133 "/usr/include/time.h" 3
extern "C" { struct tm {
# 135 "/usr/include/time.h" 3
int tm_sec;
# 136 "/usr/include/time.h" 3
int tm_min;
# 137 "/usr/include/time.h" 3
int tm_hour;
# 138 "/usr/include/time.h" 3
int tm_mday;
# 139 "/usr/include/time.h" 3
int tm_mon;
# 140 "/usr/include/time.h" 3
int tm_year;
# 141 "/usr/include/time.h" 3
int tm_wday;
# 142 "/usr/include/time.h" 3
int tm_yday;
# 143 "/usr/include/time.h" 3
int tm_isdst;
# 146 "/usr/include/time.h" 3
long tm_gmtoff;
# 147 "/usr/include/time.h" 3
const char *tm_zone;
# 152 "/usr/include/time.h" 3
}; }
# 161 "/usr/include/time.h" 3
extern "C" { struct itimerspec {
# 163 "/usr/include/time.h" 3
timespec it_interval;
# 164 "/usr/include/time.h" 3
timespec it_value;
# 165 "/usr/include/time.h" 3
}; }
# 168 "/usr/include/time.h" 3
struct sigevent;
# 174 "/usr/include/time.h" 3
extern "C" { typedef __pid_t pid_t; }
# 183 "/usr/include/time.h" 3
extern "C" __attribute__((weak)) clock_t clock() throw();
# 186 "/usr/include/time.h" 3
extern "C" time_t time(time_t *) throw();
# 189 "/usr/include/time.h" 3
extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__));
# 193 "/usr/include/time.h" 3
extern "C" time_t mktime(tm *) throw();
# 199 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw();
# 207 "/usr/include/time.h" 3
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw();
# 217 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw();
# 224 "/usr/include/time.h" 3
extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw();
# 233 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *) throw();
# 237 "/usr/include/time.h" 3
extern "C" tm *localtime(const time_t *) throw();
# 243 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 248 "/usr/include/time.h" 3
extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 255 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *) throw();
# 258 "/usr/include/time.h" 3
extern "C" char *ctime(const time_t *) throw();
# 266 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw();
# 270 "/usr/include/time.h" 3
extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw();
# 276 "/usr/include/time.h" 3
extern "C" { extern char *__tzname[2]; }
# 277 "/usr/include/time.h" 3
extern "C" { extern int __daylight; }
# 278 "/usr/include/time.h" 3
extern "C" { extern long __timezone; }
# 283 "/usr/include/time.h" 3
extern "C" { extern char *tzname[2]; }
# 287 "/usr/include/time.h" 3
extern "C" void tzset() throw();
# 291 "/usr/include/time.h" 3
extern "C" { extern int daylight; }
# 292 "/usr/include/time.h" 3
extern "C" { extern long timezone; }
# 298 "/usr/include/time.h" 3
extern "C" int stime(const time_t *) throw();
# 313 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *) throw();
# 316 "/usr/include/time.h" 3
extern "C" time_t timelocal(tm *) throw();
# 319 "/usr/include/time.h" 3
extern "C" int dysize(int) throw() __attribute__((__const__));
# 328 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *);
# 333 "/usr/include/time.h" 3
extern "C" int clock_getres(clockid_t, timespec *) throw();
# 336 "/usr/include/time.h" 3
extern "C" int clock_gettime(clockid_t, timespec *) throw();
# 339 "/usr/include/time.h" 3
extern "C" int clock_settime(clockid_t, const timespec *) throw();
# 347 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *);
# 352 "/usr/include/time.h" 3
extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw();
# 357 "/usr/include/time.h" 3
extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw();
# 362 "/usr/include/time.h" 3
extern "C" int timer_delete(timer_t) throw();
# 365 "/usr/include/time.h" 3
extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw();
# 370 "/usr/include/time.h" 3
extern "C" int timer_gettime(timer_t, itimerspec *) throw();
# 374 "/usr/include/time.h" 3
extern "C" int timer_getoverrun(timer_t) throw();
# 390 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 399 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 413 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__);
# 57 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) clock_t clock() throw();
# 59 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
# 61 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memcpy(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 66 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 68 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 70 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 72 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fabs(double) throw() __attribute__((__const__));
# 74 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__));
# 77 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int min(int, int);
# 79 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umin(unsigned, unsigned);
# 81 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmin(long long, long long);
# 83 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 85 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fminf(float, float) throw();
# 87 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmin(double, double) throw();
# 90 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int max(int, int);
# 92 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umax(unsigned, unsigned);
# 94 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmax(long long, long long);
# 96 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 98 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaxf(float, float) throw();
# 100 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmax(double, double) throw();
# 103 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sin(double) throw();
# 105 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinf(float) throw();
# 108 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cos(double) throw();
# 110 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cosf(float) throw();
# 113 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincos(double, double *, double *) throw();
# 115 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincosf(float, float *, float *) throw();
# 118 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tan(double) throw();
# 120 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanf(float) throw();
# 123 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sqrt(double) throw();
# 125 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sqrtf(float) throw();
# 128 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rsqrt(double);
# 130 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rsqrtf(float);
# 133 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp2(double) throw();
# 135 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp2f(float) throw();
# 138 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp10(double) throw();
# 140 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp10f(float) throw();
# 143 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double expm1(double) throw();
# 145 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expm1f(float) throw();
# 148 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log2(double) throw();
# 150 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log2f(float) throw();
# 153 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log10(double) throw();
# 155 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log10f(float) throw();
# 158 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log(double) throw();
# 160 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logf(float) throw();
# 163 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log1p(double) throw();
# 165 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log1pf(float) throw();
# 168 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double floor(double) throw() __attribute__((__const__));
# 170 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float floorf(float) throw() __attribute__((__const__));
# 173 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp(double) throw();
# 175 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expf(float) throw();
# 178 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cosh(double) throw();
# 180 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float coshf(float) throw();
# 183 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinh(double) throw();
# 185 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinhf(float) throw();
# 188 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tanh(double) throw();
# 190 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanhf(float) throw();
# 193 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acosh(double) throw();
# 195 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acoshf(float) throw();
# 198 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asinh(double) throw();
# 200 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinhf(float) throw();
# 203 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atanh(double) throw();
# 205 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanhf(float) throw();
# 208 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ldexp(double, int) throw();
# 210 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ldexpf(float, int) throw();
# 213 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double logb(double) throw();
# 215 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logbf(float) throw();
# 218 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogb(double) throw();
# 220 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogbf(float) throw();
# 223 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbn(double, int) throw();
# 225 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalbnf(float, int) throw();
# 228 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbln(double, long) throw();
# 230 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalblnf(float, long) throw();
# 233 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double frexp(double, int *) throw();
# 235 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float frexpf(float, int *) throw();
# 238 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double round(double) throw() __attribute__((__const__));
# 240 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float roundf(float) throw() __attribute__((__const__));
# 243 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lround(double) throw();
# 245 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lroundf(float) throw();
# 248 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llround(double) throw();
# 250 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llroundf(float) throw();
# 253 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rint(double) throw();
# 255 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rintf(float) throw();
# 258 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrint(double) throw();
# 260 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrintf(float) throw();
# 263 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrint(double) throw();
# 265 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrintf(float) throw();
# 268 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nearbyint(double) throw();
# 270 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nearbyintf(float) throw();
# 273 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ceil(double) throw() __attribute__((__const__));
# 275 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__));
# 278 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double trunc(double) throw() __attribute__((__const__));
# 280 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float truncf(float) throw() __attribute__((__const__));
# 283 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fdim(double, double) throw();
# 285 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fdimf(float, float) throw();
# 288 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan2(double, double) throw();
# 290 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atan2f(float, float) throw();
# 293 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan(double) throw();
# 295 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanf(float) throw();
# 298 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asin(double) throw();
# 300 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinf(float) throw();
# 303 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acos(double) throw();
# 305 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acosf(float) throw();
# 308 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double hypot(double, double) throw();
# 310 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float hypotf(float, float) throw();
# 313 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cbrt(double) throw();
# 315 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cbrtf(float) throw();
# 318 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rcbrt(double);
# 320 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rcbrtf(float);
# 323 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinpi(double);
# 325 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinpif(float);
# 328 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double pow(double, double) throw();
# 330 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float powf(float, float) throw();
# 333 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double modf(double, double *) throw();
# 335 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float modff(float, float *) throw();
# 338 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmod(double, double) throw();
# 340 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmodf(float, float) throw();
# 343 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remainder(double, double) throw();
# 345 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remainderf(float, float) throw();
# 348 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remquo(double, double, int *) throw();
# 350 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remquof(float, float, int *) throw();
# 353 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erf(double) throw();
# 355 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erff(float) throw();
# 358 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfinv(double);
# 360 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfinvf(float);
# 363 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfc(double) throw();
# 365 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcf(float) throw();
# 368 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfcinv(double);
# 370 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcinvf(float);
# 373 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double lgamma(double) throw();
# 375 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float lgammaf(float) throw();
# 378 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tgamma(double) throw();
# 380 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tgammaf(float) throw();
# 383 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__));
# 385 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__));
# 388 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__));
# 390 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__));
# 393 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__));
# 395 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__));
# 398 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__));
# 400 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__));
# 403 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__));
# 405 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__));
# 419 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finite(double) throw() __attribute__((__const__));
# 421 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__));
# 423 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__));
# 428 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__));
# 431 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fma(double, double, double) throw();
# 433 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaf(float, float, float) throw();
# 441 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__));
# 443 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__));
# 445 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__));
# 455 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finitel(long double) throw() __attribute__((__const__));
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
# 32 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double acos(double) throw(); extern "C" double __acos(double) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double asin(double) throw(); extern "C" double __asin(double) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double atan(double) throw(); extern "C" double __atan(double) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double cos(double) throw(); extern "C" double __cos(double) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double sin(double) throw(); extern "C" double __sin(double) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double tan(double) throw(); extern "C" double __tan(double) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double cosh(double) throw(); extern "C" double __cosh(double) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double sinh(double) throw(); extern "C" double __sinh(double) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double tanh(double) throw(); extern "C" double __tanh(double) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double acosh(double) throw(); extern "C" double __acosh(double) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double asinh(double) throw(); extern "C" double __asinh(double) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double atanh(double) throw(); extern "C" double __atanh(double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double exp(double) throw(); extern "C" double __exp(double) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double log(double) throw(); extern "C" double __log(double) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double log10(double) throw(); extern "C" double __log10(double) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double exp10(double) throw(); extern "C" double __exp10(double) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double expm1(double) throw(); extern "C" double __expm1(double) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double log1p(double) throw(); extern "C" double __log1p(double) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double logb(double) throw(); extern "C" double __logb(double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double exp2(double) throw(); extern "C" double __exp2(double) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double log2(double) throw(); extern "C" double __log2(double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __finite(double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finite(double) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" double significand(double) throw(); extern "C" double __significand(double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__));
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
extern "C" __attribute__((weak)) double erf(double) throw(); extern "C" double __erf(double) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double erfc(double) throw(); extern "C" double __erfc(double) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double rint(double) throw(); extern "C" double __rint(double) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long lrint(double) throw(); extern "C" long __lrint(double) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long lround(double) throw(); extern "C" long __lround(double) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long long llround(double) throw(); extern "C" long long __llround(double) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassify(double) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float acosf(float) throw(); extern "C" float __acosf(float) throw();
# 57 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float asinf(float) throw(); extern "C" float __asinf(float) throw();
# 59 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float atanf(float) throw(); extern "C" float __atanf(float) throw();
# 61 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw();
# 64 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float cosf(float) throw();
# 66 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float sinf(float) throw();
# 68 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float tanf(float) throw();
# 73 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float coshf(float) throw(); extern "C" float __coshf(float) throw();
# 75 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw();
# 77 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw();
# 82 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) void sincosf(float, float *, float *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw();
# 91 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw();
# 93 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float expf(float) throw();
# 104 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw();
# 107 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw();
# 110 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float logf(float) throw();
# 113 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float log10f(float) throw();
# 116 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw();
# 121 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float exp10f(float) throw();
# 123 "/usr/include/bits/mathcalls.h" 3
extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw();
# 132 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw();
# 135 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float logbf(float) throw(); extern "C" float __logbf(float) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw();
# 145 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float log2f(float) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float powf(float, float) throw();
# 157 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__));
# 182 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__));
# 185 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__));
# 188 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw();
# 193 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float) throw() __attribute__((__const__));
# 205 "/usr/include/bits/mathcalls.h" 3
extern "C" int finitef(float) throw() __attribute__((__const__));
# 208 "/usr/include/bits/mathcalls.h" 3
extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw();
# 212 "/usr/include/bits/mathcalls.h" 3
extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__));
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
extern "C" __attribute__((weak)) float erff(float) throw(); extern "C" float __erff(float) throw();
# 251 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
# 252 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float rintf(float) throw(); extern "C" float __rintf(float) throw();
# 283 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__));
# 285 "/usr/include/bits/mathcalls.h" 3
extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__));
# 289 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw();
# 293 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw();
# 297 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw();
# 302 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw();
# 306 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw();
# 310 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__));
# 314 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__));
# 319 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw();
# 327 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw();
# 331 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw();
# 332 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw();
# 336 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw();
# 339 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw();
# 342 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw();
# 346 "/usr/include/bits/mathcalls.h" 3
extern "C" int __fpclassifyf(float) throw() __attribute__((__const__));
# 350 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw();
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
extern "C" __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__));
# 196 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((weak)) int __finitel(long double) throw() __attribute__((__const__));
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
extern "C" __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__));
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
extern "C" __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__));
# 355 "/usr/include/bits/mathcalls.h" 3
extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw();
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 199 "/usr/include/math.h" 3
enum {
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
struct {
# 100 "/usr/include/stdlib.h" 3
int quot;
# 101 "/usr/include/stdlib.h" 3
int rem;
# 102 "/usr/include/stdlib.h" 3
} div_t; }
# 110 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 107 "/usr/include/stdlib.h" 3
struct {
# 108 "/usr/include/stdlib.h" 3
long quot;
# 109 "/usr/include/stdlib.h" 3
long rem;
# 110 "/usr/include/stdlib.h" 3
} ldiv_t; }
# 122 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 119 "/usr/include/stdlib.h" 3
struct {
# 120 "/usr/include/stdlib.h" 3
long long quot;
# 121 "/usr/include/stdlib.h" 3
long long rem;
# 122 "/usr/include/stdlib.h" 3
} lldiv_t; }
# 140 "/usr/include/stdlib.h" 3
extern "C" size_t __ctype_get_mb_cur_max() throw();
# 145 "/usr/include/stdlib.h" 3
extern "C" double atof(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 148 "/usr/include/stdlib.h" 3
extern "C" int atoi(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 151 "/usr/include/stdlib.h" 3
extern "C" long atol(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 158 "/usr/include/stdlib.h" 3
extern "C" long long atoll(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 165 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1)));
# 173 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1)));
# 176 "/usr/include/stdlib.h" 3
extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1)));
# 184 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 188 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 196 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 201 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 210 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 215 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1)));
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 244 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 250 "/usr/include/stdlib.h" 3
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 256 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 261 "/usr/include/stdlib.h" 3
extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 265 "/usr/include/stdlib.h" 3
extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 269 "/usr/include/stdlib.h" 3
extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long) throw();
# 314 "/usr/include/stdlib.h" 3
extern "C" long a64l(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
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
struct {
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
struct {
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
union {
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
union {
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
union {
# 108 "/usr/include/bits/pthreadtypes.h" 3
char __size[4];
# 109 "/usr/include/bits/pthreadtypes.h" 3
int __align;
# 110 "/usr/include/bits/pthreadtypes.h" 3
} pthread_mutexattr_t; }
# 130 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 116 "/usr/include/bits/pthreadtypes.h" 3
union {
# 118 "/usr/include/bits/pthreadtypes.h" 3
struct {
# 119 "/usr/include/bits/pthreadtypes.h" 3
int __lock;
# 120 "/usr/include/bits/pthreadtypes.h" 3
unsigned __futex;
# 121 "/usr/include/bits/pthreadtypes.h" 3
__extension__ unsigned long long __total_seq;
# 122 "/usr/include/bits/pthreadtypes.h" 3
__extension__ unsigned long long __wakeup_seq;
# 123 "/usr/include/bits/pthreadtypes.h" 3
__extension__ unsigned long long __woken_seq;
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
__extension__ long long __align;
# 130 "/usr/include/bits/pthreadtypes.h" 3
} pthread_cond_t; }
# 136 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 133 "/usr/include/bits/pthreadtypes.h" 3
union {
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
union {
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
union {
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
union {
# 208 "/usr/include/bits/pthreadtypes.h" 3
char __size[32];
# 209 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 210 "/usr/include/bits/pthreadtypes.h" 3
} pthread_barrier_t; }
# 216 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 213 "/usr/include/bits/pthreadtypes.h" 3
union {
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
extern "C" char *initstate(unsigned, char *, size_t) throw() __attribute__((nonnull(2)));
# 341 "/usr/include/stdlib.h" 3
extern "C" char *setstate(char *) throw() __attribute__((nonnull(1)));
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
extern "C" int random_r(random_data *__restrict__, int32_t *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 363 "/usr/include/stdlib.h" 3
extern "C" int srandom_r(unsigned, random_data *) throw() __attribute__((nonnull(2)));
# 366 "/usr/include/stdlib.h" 3
extern "C" int initstate_r(unsigned, char *__restrict__, size_t, random_data *__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 371 "/usr/include/stdlib.h" 3
extern "C" int setstate_r(char *__restrict__, random_data *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 380 "/usr/include/stdlib.h" 3
extern "C" int rand() throw();
# 382 "/usr/include/stdlib.h" 3
extern "C" void srand(unsigned) throw();
# 387 "/usr/include/stdlib.h" 3
extern "C" int rand_r(unsigned *) throw();
# 395 "/usr/include/stdlib.h" 3
extern "C" double drand48() throw();
# 396 "/usr/include/stdlib.h" 3
extern "C" double erand48(unsigned short [3]) throw() __attribute__((nonnull(1)));
# 399 "/usr/include/stdlib.h" 3
extern "C" long lrand48() throw();
# 400 "/usr/include/stdlib.h" 3
extern "C" long nrand48(unsigned short [3]) throw() __attribute__((nonnull(1)));
# 404 "/usr/include/stdlib.h" 3
extern "C" long mrand48() throw();
# 405 "/usr/include/stdlib.h" 3
extern "C" long jrand48(unsigned short [3]) throw() __attribute__((nonnull(1)));
# 409 "/usr/include/stdlib.h" 3
extern "C" void srand48(long) throw();
# 410 "/usr/include/stdlib.h" 3
extern "C" unsigned short *seed48(unsigned short [3]) throw() __attribute__((nonnull(1)));
# 412 "/usr/include/stdlib.h" 3
extern "C" void lcong48(unsigned short [7]) throw() __attribute__((nonnull(1)));
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
extern "C" int drand48_r(drand48_data *__restrict__, double *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 430 "/usr/include/stdlib.h" 3
extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__, double *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 435 "/usr/include/stdlib.h" 3
extern "C" int lrand48_r(drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 438 "/usr/include/stdlib.h" 3
extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 444 "/usr/include/stdlib.h" 3
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 447 "/usr/include/stdlib.h" 3
extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 453 "/usr/include/stdlib.h" 3
extern "C" int srand48_r(long, drand48_data *) throw() __attribute__((nonnull(2)));
# 456 "/usr/include/stdlib.h" 3
extern "C" int seed48_r(unsigned short [3], drand48_data *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 459 "/usr/include/stdlib.h" 3
extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 471 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__));
# 473 "/usr/include/stdlib.h" 3
extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__));
# 485 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void *, size_t) throw() __attribute__((__warn_unused_result__));
# 488 "/usr/include/stdlib.h" 3
extern "C" void free(void *) throw();
# 493 "/usr/include/stdlib.h" 3
extern "C" void cfree(void *) throw();
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw();
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__));
# 507 "/usr/include/stdlib.h" 3
extern "C" int posix_memalign(void **, size_t, size_t) throw() __attribute__((nonnull(1)));
# 513 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute__((__noreturn__));
# 517 "/usr/include/stdlib.h" 3
extern "C" int atexit(void (*)(void)) throw() __attribute__((nonnull(1)));
# 524 "/usr/include/stdlib.h" 3
int at_quick_exit(void (*)(void)) throw() __asm__("at_quick_exit") __attribute__((nonnull(1)));
# 535 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw() __attribute__((nonnull(1)));
# 543 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 551 "/usr/include/stdlib.h" 3
extern "C" void quick_exit(int) throw() __attribute__((__noreturn__));
# 559 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 566 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw() __attribute__((nonnull(1)));
# 571 "/usr/include/stdlib.h" 3
extern "C" char *__secure_getenv(const char *) throw() __attribute__((nonnull(1)));
# 578 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw() __attribute__((nonnull(1)));
# 584 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw() __attribute__((nonnull(2)));
# 588 "/usr/include/stdlib.h" 3
extern "C" int unsetenv(const char *) throw();
# 595 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 604 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *) throw() __attribute__((nonnull(1)));
# 615 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *) __attribute__((nonnull(1)));
# 625 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *) __attribute__((nonnull(1)));
# 635 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw() __attribute__((nonnull(1)));
# 646 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int) __attribute__((nonnull(1)));
# 656 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int) __attribute__((nonnull(1)));
# 666 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 673 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw() __attribute__((nonnull(1)));
# 683 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 691 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 694 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 698 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 704 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(5)));
# 710 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 713 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 720 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 721 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 725 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 734 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));
# 736 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 742 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 756 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 762 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 768 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw() __attribute__((nonnull(3)));
# 774 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 777 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 780 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double, int, char *) throw() __attribute__((nonnull(3)));
# 786 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 789 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 793 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 797 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 808 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();
# 811 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 815 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t) throw();
# 819 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 822 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 833 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw() __attribute__((nonnull(1)));
# 844 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 853 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw() __attribute__((nonnull(1)));
# 861 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 869 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();
# 873 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int) throw();
# 878 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int) throw();
# 885 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 889 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 896 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw() __attribute__((nonnull(1)));
# 69 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 71 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container> class __normal_iterator;
# 74 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 76 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
namespace std __attribute__((visibility("default"))) {
# 78 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __true_type { };
# 79 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __false_type { };
# 81 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<bool __T0>
# 82 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __truth_type {
# 83 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 86 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 87 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 91 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Sp, class _Tp>
# 92 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __traitor {
# 94 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
# 95 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 96 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 99 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class , class >
# 100 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same {
# 102 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 103 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 104 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 106 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 107 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 109 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 110 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 111 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 114 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 115 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_void {
# 117 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 118 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 119 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 122 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_void< void> {
# 124 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 125 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 126 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 131 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 132 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_integer {
# 134 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 135 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 136 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 142 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {
# 144 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 145 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 146 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 149 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< char> {
# 151 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 152 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 153 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 156 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< signed char> {
# 158 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 159 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 160 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 163 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned char> {
# 165 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 166 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 167 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 171 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< wchar_t> {
# 173 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 174 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 175 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 195 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< short> {
# 197 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 198 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 199 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 202 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned short> {
# 204 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 205 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 206 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 209 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< int> {
# 211 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 212 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 213 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 216 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned> {
# 218 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 219 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 220 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 223 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long> {
# 225 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 226 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 227 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 230 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long> {
# 232 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 233 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 234 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 237 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long long> {
# 239 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 240 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 241 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 244 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long long> {
# 246 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 247 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 248 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 253 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 254 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_floating {
# 256 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 257 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 258 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 262 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_floating< float> {
# 264 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 265 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 266 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 269 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_floating< double> {
# 271 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 272 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 273 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 276 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_floating< long double> {
# 278 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 279 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 280 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 285 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 286 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 288 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 289 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 290 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 292 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 293 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 295 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 296 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 297 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 302 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 303 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 305 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 306 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 307 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 309 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Iterator, class _Container>
# 310 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 313 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 314 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 315 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 320 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 321 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 323 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 328 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 329 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 331 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 336 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 337 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 339 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 344 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 345 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_char {
# 347 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 348 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 349 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 352 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_char< char> {
# 354 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 355 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 356 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 360 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_char< wchar_t> {
# 362 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 363 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 364 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 367 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 368 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_byte {
# 370 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 371 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 372 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 375 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_byte< char> {
# 377 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 378 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 379 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 382 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_byte< signed char> {
# 384 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 385 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 386 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 389 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<> struct __is_byte< unsigned char> {
# 391 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 392 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 393 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 398 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
template<class _Tp>
# 399 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
struct __is_move_iterator {
# 401 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
enum { __value};
# 402 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 403 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
};
# 417 "/usr/include/c++/4.4/bits/cpp_type_traits.h" 3
}
# 37 "/usr/include/c++/4.4/ext/type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 40 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<bool __T1, class >
# 41 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if {
# 42 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 44 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 45 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 46 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 50 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<bool _Cond, class _Iftrue, class _Iffalse>
# 51 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type {
# 52 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 54 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Iftrue, class _Iffalse>
# 55 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 56 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 60 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 61 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __add_unsigned {
# 64 "/usr/include/c++/4.4/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 67 "/usr/include/c++/4.4/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 68 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 71 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< char> {
# 72 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned char __type; };
# 75 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< signed char> {
# 76 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned char __type; };
# 79 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< short> {
# 80 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned short __type; };
# 83 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< int> {
# 84 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned __type; };
# 87 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< long> {
# 88 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned long __type; };
# 91 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< long long> {
# 92 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef unsigned long long __type; };
# 96 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< bool> ;
# 99 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __add_unsigned< wchar_t> ;
# 103 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 104 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __remove_unsigned {
# 107 "/usr/include/c++/4.4/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 110 "/usr/include/c++/4.4/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 111 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 114 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< char> {
# 115 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef signed char __type; };
# 118 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned char> {
# 119 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef signed char __type; };
# 122 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned short> {
# 123 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef short __type; };
# 126 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned> {
# 127 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef int __type; };
# 130 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long> {
# 131 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef long __type; };
# 134 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long long> {
# 135 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef long long __type; };
# 139 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< bool> ;
# 142 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<> struct __remove_unsigned< wchar_t> ;
# 146 "/usr/include/c++/4.4/ext/type_traits.h" 3
template < typename _Type >
    inline bool
    __is_null_pointer ( _Type * __ptr )
    { return __ptr == 0; }
# 151 "/usr/include/c++/4.4/ext/type_traits.h" 3
template < typename _Type >
    inline bool
    __is_null_pointer ( _Type )
    { return false; }
# 158 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
# 159 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote {
# 160 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef double __type; };
# 162 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp>
# 163 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote< _Tp, false> {
# 164 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef _Tp __type; };
# 166 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp, class _Up>
# 167 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote_2 {
# 170 "/usr/include/c++/4.4/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 171 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 174 "/usr/include/c++/4.4/ext/type_traits.h" 3
public: typedef __typeof__(__type1() + __type2()) __type;
# 175 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 177 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp, class _Up, class _Vp>
# 178 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote_3 {
# 181 "/usr/include/c++/4.4/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 182 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 183 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 186 "/usr/include/c++/4.4/ext/type_traits.h" 3
public: typedef __typeof__((__type1() + __type2()) + __type3()) __type;
# 187 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 189 "/usr/include/c++/4.4/ext/type_traits.h" 3
template<class _Tp, class _Up, class _Vp, class _Wp>
# 190 "/usr/include/c++/4.4/ext/type_traits.h" 3
struct __promote_4 {
# 193 "/usr/include/c++/4.4/ext/type_traits.h" 3
private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
# 194 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
# 195 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
# 196 "/usr/include/c++/4.4/ext/type_traits.h" 3
typedef typename __promote< _Wp, std::__is_integer< _Wp> ::__value> ::__type __type4;
# 199 "/usr/include/c++/4.4/ext/type_traits.h" 3
public: typedef __typeof__(((__type1() + __type2()) + __type3()) + __type4()) __type;
# 200 "/usr/include/c++/4.4/ext/type_traits.h" 3
};
# 202 "/usr/include/c++/4.4/ext/type_traits.h" 3
}
# 77 "/usr/include/c++/4.4/cmath" 3
namespace std __attribute__((visibility("default"))) {
# 81 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    _Tp __cmath_power ( _Tp, unsigned int );
# 84 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }
# 94 "/usr/include/c++/4.4/cmath" 3
inline double abs(double __x)
# 95 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fabs(__x); }
# 98 "/usr/include/c++/4.4/cmath" 3
inline float abs(float __x)
# 99 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fabsf(__x); }
# 102 "/usr/include/c++/4.4/cmath" 3
inline long double abs(long double __x)
# 103 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fabsl(__x); }
# 105 "/usr/include/c++/4.4/cmath" 3
using ::acos;
# 108 "/usr/include/c++/4.4/cmath" 3
inline float acos(float __x)
# 109 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_acosf(__x); }
# 112 "/usr/include/c++/4.4/cmath" 3
inline long double acos(long double __x)
# 113 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_acosl(__x); }
# 115 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }
# 121 "/usr/include/c++/4.4/cmath" 3
using ::asin;
# 124 "/usr/include/c++/4.4/cmath" 3
inline float asin(float __x)
# 125 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_asinf(__x); }
# 128 "/usr/include/c++/4.4/cmath" 3
inline long double asin(long double __x)
# 129 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_asinl(__x); }
# 131 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }
# 137 "/usr/include/c++/4.4/cmath" 3
using ::atan;
# 140 "/usr/include/c++/4.4/cmath" 3
inline float atan(float __x)
# 141 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_atanf(__x); }
# 144 "/usr/include/c++/4.4/cmath" 3
inline long double atan(long double __x)
# 145 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_atanl(__x); }
# 147 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }
# 153 "/usr/include/c++/4.4/cmath" 3
using ::atan2;
# 156 "/usr/include/c++/4.4/cmath" 3
inline float atan2(float __y, float __x)
# 157 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_atan2f(__y, __x); }
# 160 "/usr/include/c++/4.4/cmath" 3
inline long double atan2(long double __y, long double __x)
# 161 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_atan2l(__y, __x); }
# 163 "/usr/include/c++/4.4/cmath" 3
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
# 175 "/usr/include/c++/4.4/cmath" 3
using ::ceil;
# 178 "/usr/include/c++/4.4/cmath" 3
inline float ceil(float __x)
# 179 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_ceilf(__x); }
# 182 "/usr/include/c++/4.4/cmath" 3
inline long double ceil(long double __x)
# 183 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_ceill(__x); }
# 185 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }
# 191 "/usr/include/c++/4.4/cmath" 3
using ::cos;
# 194 "/usr/include/c++/4.4/cmath" 3
inline float cos(float __x)
# 195 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_cosf(__x); }
# 198 "/usr/include/c++/4.4/cmath" 3
inline long double cos(long double __x)
# 199 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_cosl(__x); }
# 201 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }
# 207 "/usr/include/c++/4.4/cmath" 3
using ::cosh;
# 210 "/usr/include/c++/4.4/cmath" 3
inline float cosh(float __x)
# 211 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_coshf(__x); }
# 214 "/usr/include/c++/4.4/cmath" 3
inline long double cosh(long double __x)
# 215 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_coshl(__x); }
# 217 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }
# 223 "/usr/include/c++/4.4/cmath" 3
using ::exp;
# 226 "/usr/include/c++/4.4/cmath" 3
inline float exp(float __x)
# 227 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_expf(__x); }
# 230 "/usr/include/c++/4.4/cmath" 3
inline long double exp(long double __x)
# 231 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_expl(__x); }
# 233 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }
# 239 "/usr/include/c++/4.4/cmath" 3
using ::fabs;
# 242 "/usr/include/c++/4.4/cmath" 3
inline float fabs(float __x)
# 243 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fabsf(__x); }
# 246 "/usr/include/c++/4.4/cmath" 3
inline long double fabs(long double __x)
# 247 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fabsl(__x); }
# 249 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }
# 255 "/usr/include/c++/4.4/cmath" 3
using ::floor;
# 258 "/usr/include/c++/4.4/cmath" 3
inline float floor(float __x)
# 259 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_floorf(__x); }
# 262 "/usr/include/c++/4.4/cmath" 3
inline long double floor(long double __x)
# 263 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_floorl(__x); }
# 265 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }
# 271 "/usr/include/c++/4.4/cmath" 3
using ::fmod;
# 274 "/usr/include/c++/4.4/cmath" 3
inline float fmod(float __x, float __y)
# 275 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fmodf(__x, __y); }
# 278 "/usr/include/c++/4.4/cmath" 3
inline long double fmod(long double __x, long double __y)
# 279 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_fmodl(__x, __y); }
# 281 "/usr/include/c++/4.4/cmath" 3
using ::frexp;
# 284 "/usr/include/c++/4.4/cmath" 3
inline float frexp(float __x, int *__exp)
# 285 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_frexpf(__x, __exp); }
# 288 "/usr/include/c++/4.4/cmath" 3
inline long double frexp(long double __x, int *__exp)
# 289 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_frexpl(__x, __exp); }
# 291 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }
# 297 "/usr/include/c++/4.4/cmath" 3
using ::ldexp;
# 300 "/usr/include/c++/4.4/cmath" 3
inline float ldexp(float __x, int __exp)
# 301 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_ldexpf(__x, __exp); }
# 304 "/usr/include/c++/4.4/cmath" 3
inline long double ldexp(long double __x, int __exp)
# 305 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_ldexpl(__x, __exp); }
# 307 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }
# 313 "/usr/include/c++/4.4/cmath" 3
using ::log;
# 316 "/usr/include/c++/4.4/cmath" 3
inline float log(float __x)
# 317 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_logf(__x); }
# 320 "/usr/include/c++/4.4/cmath" 3
inline long double log(long double __x)
# 321 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_logl(__x); }
# 323 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }
# 329 "/usr/include/c++/4.4/cmath" 3
using ::log10;
# 332 "/usr/include/c++/4.4/cmath" 3
inline float log10(float __x)
# 333 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_log10f(__x); }
# 336 "/usr/include/c++/4.4/cmath" 3
inline long double log10(long double __x)
# 337 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_log10l(__x); }
# 339 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }
# 345 "/usr/include/c++/4.4/cmath" 3
using ::modf;
# 348 "/usr/include/c++/4.4/cmath" 3
inline float modf(float __x, float *__iptr)
# 349 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_modff(__x, __iptr); }
# 352 "/usr/include/c++/4.4/cmath" 3
inline long double modf(long double __x, long double *__iptr)
# 353 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_modfl(__x, __iptr); }
# 355 "/usr/include/c++/4.4/cmath" 3
using ::pow;
# 358 "/usr/include/c++/4.4/cmath" 3
inline float pow(float __x, float __y)
# 359 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_powf(__x, __y); }
# 362 "/usr/include/c++/4.4/cmath" 3
inline long double pow(long double __x, long double __y)
# 363 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_powl(__x, __y); }
# 369 "/usr/include/c++/4.4/cmath" 3
inline double pow(double __x, int __i)
# 370 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_powi(__x, __i); }
# 373 "/usr/include/c++/4.4/cmath" 3
inline float pow(float __x, int __n)
# 374 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_powif(__x, __n); }
# 377 "/usr/include/c++/4.4/cmath" 3
inline long double pow(long double __x, int __n)
# 378 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_powil(__x, __n); }
# 381 "/usr/include/c++/4.4/cmath" 3
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
# 393 "/usr/include/c++/4.4/cmath" 3
using ::sin;
# 396 "/usr/include/c++/4.4/cmath" 3
inline float sin(float __x)
# 397 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sinf(__x); }
# 400 "/usr/include/c++/4.4/cmath" 3
inline long double sin(long double __x)
# 401 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sinl(__x); }
# 403 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }
# 409 "/usr/include/c++/4.4/cmath" 3
using ::sinh;
# 412 "/usr/include/c++/4.4/cmath" 3
inline float sinh(float __x)
# 413 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sinhf(__x); }
# 416 "/usr/include/c++/4.4/cmath" 3
inline long double sinh(long double __x)
# 417 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sinhl(__x); }
# 419 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }
# 425 "/usr/include/c++/4.4/cmath" 3
using ::sqrt;
# 428 "/usr/include/c++/4.4/cmath" 3
inline float sqrt(float __x)
# 429 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sqrtf(__x); }
# 432 "/usr/include/c++/4.4/cmath" 3
inline long double sqrt(long double __x)
# 433 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_sqrtl(__x); }
# 435 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }
# 441 "/usr/include/c++/4.4/cmath" 3
using ::tan;
# 444 "/usr/include/c++/4.4/cmath" 3
inline float tan(float __x)
# 445 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_tanf(__x); }
# 448 "/usr/include/c++/4.4/cmath" 3
inline long double tan(long double __x)
# 449 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_tanl(__x); }
# 451 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }
# 457 "/usr/include/c++/4.4/cmath" 3
using ::tanh;
# 460 "/usr/include/c++/4.4/cmath" 3
inline float tanh(float __x)
# 461 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_tanhf(__x); }
# 464 "/usr/include/c++/4.4/cmath" 3
inline long double tanh(long double __x)
# 465 "/usr/include/c++/4.4/cmath" 3
{ return __builtin_tanhl(__x); }
# 467 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }
# 473 "/usr/include/c++/4.4/cmath" 3
}
# 492 "/usr/include/c++/4.4/cmath" 3
namespace std __attribute__((visibility("default"))) {
# 494 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    fpclassify ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_fpclassify ( FP_NAN, FP_INFINITE, FP_NORMAL,
      FP_SUBNORMAL, FP_ZERO, __type ( __f ) );
    }
# 504 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isfinite ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isfinite ( __type ( __f ) );
    }
# 513 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isinf ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isinf ( __type ( __f ) );
    }
# 522 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnan ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnan ( __type ( __f ) );
    }
# 531 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnormal ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnormal ( __type ( __f ) );
    }
# 540 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    signbit ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_signbit ( __type ( __f ) );
    }
# 549 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreater ( __type ( __f1 ), __type ( __f2 ) );
    }
# 558 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreaterequal ( __type ( __f1 ), __type ( __f2 ) );
    }
# 567 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isless ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isless ( __type ( __f1 ), __type ( __f2 ) );
    }
# 576 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessequal ( __type ( __f1 ), __type ( __f2 ) );
    }
# 585 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessgreater ( __type ( __f1 ), __type ( __f2 ) );
    }
# 594 "/usr/include/c++/4.4/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isunordered ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isunordered ( __type ( __f1 ), __type ( __f2 ) );
    }
# 603 "/usr/include/c++/4.4/cmath" 3
}
# 35 "/usr/include/c++/4.4/bits/cmath.tcc" 3
namespace std __attribute__((visibility("default"))) {
# 37 "/usr/include/c++/4.4/bits/cmath.tcc" 3
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
# 53 "/usr/include/c++/4.4/bits/cmath.tcc" 3
}
# 49 "/usr/include/c++/4.4/cstddef" 3
namespace std __attribute__((visibility("default"))) {
# 51 "/usr/include/c++/4.4/cstddef" 3
using ::ptrdiff_t;
# 52 "/usr/include/c++/4.4/cstddef" 3
using ::size_t;
# 54 "/usr/include/c++/4.4/cstddef" 3
}
# 100 "/usr/include/c++/4.4/cstdlib" 3
namespace std __attribute__((visibility("default"))) {
# 102 "/usr/include/c++/4.4/cstdlib" 3
using ::div_t;
# 103 "/usr/include/c++/4.4/cstdlib" 3
using ::ldiv_t;
# 105 "/usr/include/c++/4.4/cstdlib" 3
using ::abort;
# 106 "/usr/include/c++/4.4/cstdlib" 3
using ::abs;
# 107 "/usr/include/c++/4.4/cstdlib" 3
using ::atexit;
# 108 "/usr/include/c++/4.4/cstdlib" 3
using ::atof;
# 109 "/usr/include/c++/4.4/cstdlib" 3
using ::atoi;
# 110 "/usr/include/c++/4.4/cstdlib" 3
using ::atol;
# 111 "/usr/include/c++/4.4/cstdlib" 3
using ::bsearch;
# 112 "/usr/include/c++/4.4/cstdlib" 3
using ::calloc;
# 113 "/usr/include/c++/4.4/cstdlib" 3
using ::div;
# 114 "/usr/include/c++/4.4/cstdlib" 3
using ::exit;
# 115 "/usr/include/c++/4.4/cstdlib" 3
using ::free;
# 116 "/usr/include/c++/4.4/cstdlib" 3
using ::getenv;
# 117 "/usr/include/c++/4.4/cstdlib" 3
using ::labs;
# 118 "/usr/include/c++/4.4/cstdlib" 3
using ::ldiv;
# 119 "/usr/include/c++/4.4/cstdlib" 3
using ::malloc;
# 121 "/usr/include/c++/4.4/cstdlib" 3
using ::mblen;
# 122 "/usr/include/c++/4.4/cstdlib" 3
using ::mbstowcs;
# 123 "/usr/include/c++/4.4/cstdlib" 3
using ::mbtowc;
# 125 "/usr/include/c++/4.4/cstdlib" 3
using ::qsort;
# 126 "/usr/include/c++/4.4/cstdlib" 3
using ::rand;
# 127 "/usr/include/c++/4.4/cstdlib" 3
using ::realloc;
# 128 "/usr/include/c++/4.4/cstdlib" 3
using ::srand;
# 129 "/usr/include/c++/4.4/cstdlib" 3
using ::strtod;
# 130 "/usr/include/c++/4.4/cstdlib" 3
using ::strtol;
# 131 "/usr/include/c++/4.4/cstdlib" 3
using ::strtoul;
# 132 "/usr/include/c++/4.4/cstdlib" 3
using ::system;
# 134 "/usr/include/c++/4.4/cstdlib" 3
using ::wcstombs;
# 135 "/usr/include/c++/4.4/cstdlib" 3
using ::wctomb;
# 139 "/usr/include/c++/4.4/cstdlib" 3
inline long abs(long __i) { return labs(__i); }
# 142 "/usr/include/c++/4.4/cstdlib" 3
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }
# 144 "/usr/include/c++/4.4/cstdlib" 3
}
# 157 "/usr/include/c++/4.4/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {
# 160 "/usr/include/c++/4.4/cstdlib" 3
using ::lldiv_t;
# 166 "/usr/include/c++/4.4/cstdlib" 3
using ::_Exit;
# 170 "/usr/include/c++/4.4/cstdlib" 3
inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }
# 173 "/usr/include/c++/4.4/cstdlib" 3
using ::llabs;
# 176 "/usr/include/c++/4.4/cstdlib" 3
inline lldiv_t div(long long __n, long long __d)
# 177 "/usr/include/c++/4.4/cstdlib" 3
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; }
# 179 "/usr/include/c++/4.4/cstdlib" 3
using ::lldiv;
# 190 "/usr/include/c++/4.4/cstdlib" 3
using ::atoll;
# 191 "/usr/include/c++/4.4/cstdlib" 3
using ::strtoll;
# 192 "/usr/include/c++/4.4/cstdlib" 3
using ::strtoull;
# 194 "/usr/include/c++/4.4/cstdlib" 3
using ::strtof;
# 195 "/usr/include/c++/4.4/cstdlib" 3
using ::strtold;
# 197 "/usr/include/c++/4.4/cstdlib" 3
}
# 199 "/usr/include/c++/4.4/cstdlib" 3
namespace std __attribute__((visibility("default"))) {
# 202 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::lldiv_t;
# 204 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::_Exit;
# 205 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::abs;
# 207 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::llabs;
# 208 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::div;
# 209 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::lldiv;
# 211 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::atoll;
# 212 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::strtof;
# 213 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::strtoll;
# 214 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::strtoull;
# 215 "/usr/include/c++/4.4/cstdlib" 3
using __gnu_cxx::strtold;
# 217 "/usr/include/c++/4.4/cstdlib" 3
}
# 497 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 499 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 500 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 502 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 504 "/usr/local/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 505 "/usr/local/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 506 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 508 "/usr/local/cuda/bin/../include/math_functions.h"
using std::abs;
# 509 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fabs;
# 510 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ceil;
# 511 "/usr/local/cuda/bin/../include/math_functions.h"
using std::floor;
# 512 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 513 "/usr/local/cuda/bin/../include/math_functions.h"
using std::pow;
# 514 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log;
# 515 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log10;
# 516 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fmod;
# 517 "/usr/local/cuda/bin/../include/math_functions.h"
using std::modf;
# 518 "/usr/local/cuda/bin/../include/math_functions.h"
using std::exp;
# 519 "/usr/local/cuda/bin/../include/math_functions.h"
using std::frexp;
# 520 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 521 "/usr/local/cuda/bin/../include/math_functions.h"
using std::asin;
# 522 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sin;
# 523 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sinh;
# 524 "/usr/local/cuda/bin/../include/math_functions.h"
using std::acos;
# 525 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cos;
# 526 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cosh;
# 527 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan;
# 528 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan2;
# 529 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tan;
# 530 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tanh;
# 584 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 587 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 588 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 589 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 590 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 591 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 592 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 593 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 594 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 595 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 596 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 597 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 598 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 599 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 600 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 601 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 602 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 603 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 604 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 605 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 606 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 607 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 608 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 609 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 610 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 611 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 612 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 613 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 616 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 619 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 620 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 621 "/usr/local/cuda/bin/../include/math_functions.h"
return logbf(a);
# 622 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 624 "/usr/local/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 625 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 626 "/usr/local/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 627 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 629 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 630 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 631 "/usr/local/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 632 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 634 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 635 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 636 "/usr/local/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 637 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 639 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 640 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 641 "/usr/local/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 642 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 644 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 645 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 646 "/usr/local/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 647 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 649 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 650 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 651 "/usr/local/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 652 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 654 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 655 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 656 "/usr/local/cuda/bin/../include/math_functions.h"
return log2f(a);
# 657 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 659 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 660 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 661 "/usr/local/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 662 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 664 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 665 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 666 "/usr/local/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 667 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 669 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 670 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 671 "/usr/local/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 672 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 674 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 675 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 676 "/usr/local/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 677 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 679 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 680 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 681 "/usr/local/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 682 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 684 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 685 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 686 "/usr/local/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 687 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 689 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 690 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 691 "/usr/local/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 692 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 694 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 695 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 696 "/usr/local/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 697 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 699 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 700 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 701 "/usr/local/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 702 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 704 "/usr/local/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 705 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 706 "/usr/local/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 707 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 709 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 710 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 711 "/usr/local/cuda/bin/../include/math_functions.h"
return erff(a);
# 712 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 714 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 715 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 716 "/usr/local/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 717 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 719 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 720 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 721 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 722 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 724 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 725 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 726 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 727 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 729 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 730 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 731 "/usr/local/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 732 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 734 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 735 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 736 "/usr/local/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 737 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 739 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 740 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 741 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 742 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 744 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 745 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 746 "/usr/local/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 747 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 749 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 750 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 751 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 752 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 754 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 755 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 756 "/usr/local/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 757 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 759 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 760 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 761 "/usr/local/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 762 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 764 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 765 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 766 "/usr/local/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 767 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 769 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 770 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 771 "/usr/local/cuda/bin/../include/math_functions.h"
return roundf(a);
# 772 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 774 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 775 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 776 "/usr/local/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 777 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 779 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 780 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 781 "/usr/local/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 782 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 784 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 785 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 786 "/usr/local/cuda/bin/../include/math_functions.h"
return truncf(a);
# 787 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 789 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 790 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 791 "/usr/local/cuda/bin/../include/math_functions.h"
return rintf(a);
# 792 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 794 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 795 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 796 "/usr/local/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 797 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 799 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 800 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 801 "/usr/local/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 802 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 804 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 805 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 806 "/usr/local/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 807 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 809 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 810 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 811 "/usr/local/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 812 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 814 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 815 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 816 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 817 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 819 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 820 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 821 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 822 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 824 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 825 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 826 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 827 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 829 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 830 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 831 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 832 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 834 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 835 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 836 "/usr/local/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 837 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 839 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 840 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 841 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 842 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 844 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 845 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 846 "/usr/local/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 847 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 849 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 850 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 851 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 852 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 854 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 855 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 856 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 857 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 859 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 860 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 861 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 862 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 864 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 865 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 866 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 867 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 869 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 870 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 871 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 872 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 874 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 875 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 876 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 877 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 879 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 880 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 881 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 882 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 884 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 885 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 886 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 887 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 889 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 890 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 891 "/usr/local/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 892 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 894 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 895 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 896 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 897 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 899 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 900 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 901 "/usr/local/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 902 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 904 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 905 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 906 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 907 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 909 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 910 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 911 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 912 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 914 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 915 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 916 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 917 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 919 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 920 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 921 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 922 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 924 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 925 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 926 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 927 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 929 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 930 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 931 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 932 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 934 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 935 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 936 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 937 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 60 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template<class T, int dim = 1>
# 61 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 63 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 64 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 65 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 66 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 68 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 69 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 70 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 71 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 72 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 75 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template<int dim>
# 76 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 78 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 79 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 80 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 81 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 82 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 60 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 61 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 63 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 64 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 65 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 66 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 67 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 68 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 69 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 70 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 71 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 72 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 73 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 75 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 76 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 77 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 78 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
desc)
# 79 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 80 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 81 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 82 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 83 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 84 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 85 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 86 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 87 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
};
# 329 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mulhi(int a, int b)
# 330 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 332 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 334 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, unsigned b)
# 335 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 337 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(int a, unsigned b)
# 340 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, int b)
# 345 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 347 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline long long mul64hi(long long a, long long b)
# 350 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 352 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 355 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 357 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(long long a, unsigned long long b)
# 360 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, long long b)
# 365 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 367 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float_as_int(float a)
# 370 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int_as_float(int a)
# 375 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 377 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float saturate(float a)
# 380 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 382 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mul24(int a, int b)
# 385 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned umul24(unsigned a, unsigned b)
# 390 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 392 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void trap()
# 395 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 397 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 399 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void brkpt(int c)
# 400 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 404 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void syncthreads()
# 405 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 407 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 409 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void prof_trigger(int e)
# 410 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void threadfence(bool global)
# 430 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 432 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 434 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float2int(float a, cudaRoundMode mode)
# 435 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 440 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 442 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned float2uint(float a, cudaRoundMode mode)
# 443 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 448 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 450 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int2float(int a, cudaRoundMode mode)
# 451 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 456 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 458 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float uint2float(unsigned a, cudaRoundMode mode)
# 459 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 464 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 102 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAdd(int *address, int val)
# 103 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 105 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 107 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAdd(unsigned *address, unsigned val)
# 108 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicSub(int *address, int val)
# 113 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 115 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicSub(unsigned *address, unsigned val)
# 118 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 120 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicExch(int *address, int val)
# 123 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 125 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicExch(unsigned *address, unsigned val)
# 128 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 130 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline float atomicExch(float *address, float val)
# 133 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 135 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMin(int *address, int val)
# 138 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMin(unsigned *address, unsigned val)
# 143 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMax(int *address, int val)
# 148 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 150 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMax(unsigned *address, unsigned val)
# 153 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 155 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicInc(unsigned *address, unsigned val)
# 158 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicDec(unsigned *address, unsigned val)
# 163 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAnd(int *address, int val)
# 168 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 170 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAnd(unsigned *address, unsigned val)
# 173 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 175 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicOr(int *address, int val)
# 178 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicOr(unsigned *address, unsigned val)
# 183 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 185 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicXor(int *address, int val)
# 188 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 190 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicXor(unsigned *address, unsigned val)
# 193 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 195 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicCAS(int *address, int compare, int val)
# 198 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 203 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 205 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 75 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 76 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 78 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 80 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 81 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 83 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 85 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 86 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 88 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool any(bool cond)
# 91 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 93 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool all(bool cond)
# 96 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 98 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 170 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double fma(double a, double b, double c, cudaRoundMode mode)
# 171 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 176 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 178 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dmul(double a, double b, cudaRoundMode mode)
# 179 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 184 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 186 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dadd(double a, double b, cudaRoundMode mode)
# 187 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 194 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline int double2int(double a, cudaRoundMode mode)
# 195 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned double2uint(double a, cudaRoundMode mode)
# 203 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 208 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 210 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline long long double2ll(double a, cudaRoundMode mode)
# 211 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 216 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 218 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned long long double2ull(double a, cudaRoundMode mode)
# 219 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 224 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 226 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ll2double(long long a, cudaRoundMode mode)
# 227 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 234 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ull2double(unsigned long long a, cudaRoundMode mode)
# 235 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 240 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 242 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double int2double(int a, cudaRoundMode mode)
# 243 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 245 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double uint2double(unsigned a, cudaRoundMode mode)
# 248 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 252 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double float2double(float a, cudaRoundMode mode)
# 253 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 66 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
static __attribute__((unused)) inline float atomicAdd(float *address, float val)
# 67 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;
# 69 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 124 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline unsigned ballot(bool pred)
# 125 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 127 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 129 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline int syncthreads_count(bool pred)
# 130 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 132 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 134 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_and(bool pred)
# 135 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 137 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 139 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_or(bool pred)
# 140 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 142 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 97 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 98 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode)
# 99 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 106 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 108 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T
# 109 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 110 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 116 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 118 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 119 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 120 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 122 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 125 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 126 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 128 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 131 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 132 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 134 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 138 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 143 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 144 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 146 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 149 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 155 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 156 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 166 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 174 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 189 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 196 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 198 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 201 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 202 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 204 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 207 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 208 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 218 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 226 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 238 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 241 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 242 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 244 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 248 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 253 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 254 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 256 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 259 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 264 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 270 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 278 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 290 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 294 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 296 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 299 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 300 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 302 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 305 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 306 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 308 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 311 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 316 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 322 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 385 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 386 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 388 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 391 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 392 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 394 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 398 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 410 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 457 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 458 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode)
# 459 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 466 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T
# 469 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 470 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 476 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 478 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 479 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 480 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 482 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 485 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 486 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 488 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 492 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 494 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 497 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 498 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 500 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 503 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 504 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 506 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 509 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 510 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 512 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 516 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 520 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 526 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 534 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 540 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 546 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 549 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 550 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 555 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 556 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 558 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 562 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 564 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 567 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 568 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 572 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 578 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 586 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 592 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 598 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 601 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 602 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 604 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 607 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 608 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 610 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 613 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 614 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 616 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 619 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 620 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 624 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 630 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 638 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 644 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 650 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 653 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 654 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 659 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 660 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 662 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 665 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 666 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 668 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 672 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 682 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 745 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 746 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 748 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 751 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 752 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 754 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 757 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 758 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 762 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 770 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 817 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 818 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode)
# 819 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 837 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 839 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 840 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 841 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 843 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 846 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 847 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 849 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 852 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 854 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 856 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 857 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 859 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 862 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 864 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 867 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 869 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 872 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 877 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 879 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 882 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 884 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 887 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 889 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 892 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 894 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 897 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 899 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 902 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 904 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 907 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 909 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 912 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 914 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 917 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 919 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 922 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 924 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 927 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 929 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 932 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 934 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 937 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 939 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 942 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 947 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 949 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 952 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 954 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 957 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 959 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 962 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 964 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 967 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 969 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 972 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 974 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 977 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 979 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 982 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 984 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 987 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 989 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 992 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 994 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 997 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 999 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1045 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1046 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1048 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1050 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1051 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1053 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1055 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1056 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1058 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1061 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1063 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1110 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 1111 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode)
# 1112 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1130 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1132 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 1133 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1134 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1136 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1139 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1140 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1142 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1145 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1147 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1149 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1155 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1157 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1160 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1162 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1165 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1167 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1172 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1175 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1177 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1180 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1185 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1187 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1195 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1197 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1200 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1205 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1207 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1210 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1215 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1217 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1220 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1222 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1225 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1227 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1235 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1240 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1242 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1245 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1247 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1250 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1255 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1257 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1262 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1265 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1267 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1270 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1272 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1275 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1277 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1280 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1282 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1285 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1287 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1290 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1292 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1338 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1339 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1341 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1343 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1344 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1346 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1348 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1349 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1351 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1354 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 61 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 63 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 65 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 68 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetch(texture< T, dim, readMode> , float4, int);
# 70 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetch(texture< T, dim, readMode> , float4, int);
# 72 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetch(texture< T, dim, readMode> , float4, int);
# 80 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 81 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 89 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 92 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 96 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 98 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 99 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 103 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 158 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 172 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 179 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 193 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 207 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 220 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 222 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 227 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 234 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 241 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 343 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 344 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 351 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 357 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 358 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 390 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 460 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 468 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 481 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 489 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 497 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 530 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 538 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 545 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 559 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 566 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 607 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 614 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 621 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 628 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 635 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 642 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 649 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 664 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 669 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 683 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 803 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 805 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 806 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 810 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 817 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 824 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 832 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 890 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 898 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 906 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 915 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 920 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 923 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 928 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 936 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 952 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 968 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 976 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 985 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 993 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 996 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1000 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1003 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1007 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1010 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1028 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1058 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1062 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1069 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1072 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1076 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1083 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1111 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1259 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1266 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1273 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1281 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1282 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1302 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1323 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1331 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1339 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1347 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1372 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1393 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1401 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1409 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1417 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1425 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1434 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1442 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1449 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1452 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1456 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1463 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1470 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1477 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1487 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1498 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1511 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1514 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1518 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1525 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1532 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1535 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1539 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1542 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1546 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1549 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1553 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1556 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1560 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1597 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1604 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1611 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1618 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1701 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1708 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1715 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1722 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1730 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1731 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1740 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1743 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1750 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1751 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1759 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1764 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1772 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1775 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1780 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1791 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1796 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1804 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1818 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1821 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1826 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1829 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1834 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1837 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 102 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 103 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 104 "/usr/local/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 105 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset)
# 107 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 108 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 109 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 111 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 112 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 113 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 114 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 115 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 117 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 118 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 119 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 121 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 122 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 123 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 124 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 125 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 127 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 128 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 129 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 131 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 132 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 133 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 134 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 136 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 137 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 140 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 141 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 142 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 143 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 145 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 146 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size);
# 147 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 149 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 150 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 151 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 152 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 153 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 154 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height)
# 156 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 157 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 158 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 173 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 174 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 175 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 176 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 177 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 178 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 180 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 181 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 182 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 184 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 185 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 186 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 187 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 188 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 189 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 190 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 192 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 193 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 194 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 196 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 197 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 198 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 199 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 200 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 201 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 202 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 204 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 205 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 206 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 209 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 210 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 211 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 212 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 213 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 214 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 215 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 217 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 218 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 219 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 228 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 229 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 230 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 231 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 232 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 234 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 235 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 236 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 238 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 239 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 240 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 241 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 242 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 243 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 244 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 246 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 247 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 248 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 250 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 251 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 253 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 254 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 255 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 256 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 258 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 259 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 260 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 262 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 263 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 264 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 265 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 266 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 267 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 268 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 269 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 271 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 272 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 273 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 276 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 277 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 279 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 280 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 281 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 308 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 309 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 310 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 311 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 313 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 314 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 315 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 323 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 324 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, char *
# 325 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 327 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 328 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 329 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 356 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 357 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 358 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 359 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 361 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 362 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 363 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 412 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 413 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 414 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 415 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 416 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 417 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 418 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 420 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 421 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 422 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 456 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 457 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 458 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 459 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 460 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 461 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 463 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 464 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.texture< T, dim, readMode> ::channelDesc), size);
# 465 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 511 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 512 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 513 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 514 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 515 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 516 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 517 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 518 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 519 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 521 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 522 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 523 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 553 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 554 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 555 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 556 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 557 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 559 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 560 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 561 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 590 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 591 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 592 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 593 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 595 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 596 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 597 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 599 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 600 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 628 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 629 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 630 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 632 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 633 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 634 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 667 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 668 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 669 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 670 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 672 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 673 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 674 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 724 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 725 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 726 "/usr/local/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 727 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 729 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 730 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 731 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 768 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 769 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 770 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 772 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 773 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 774 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 805 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 806 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 807 "/usr/local/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 808 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 810 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 811 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 812 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 835 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 836 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 837 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 838 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 839 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 841 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 842 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 843 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 865 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 866 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 867 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 868 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 870 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 871 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 872 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 874 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 875 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;
# 49 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 95 "/usr/include/wchar.h" 3
extern "C" { typedef
# 84 "/usr/include/wchar.h" 3
struct {
# 85 "/usr/include/wchar.h" 3
int __count;
# 87 "/usr/include/wchar.h" 3
union {
# 89 "/usr/include/wchar.h" 3
unsigned __wch;
# 93 "/usr/include/wchar.h" 3
char __wchb[4];
# 94 "/usr/include/wchar.h" 3
} __value;
# 95 "/usr/include/wchar.h" 3
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 23 "/usr/include/_G_config.h" 3
struct {
# 24 "/usr/include/_G_config.h" 3
__off_t __pos;
# 25 "/usr/include/_G_config.h" 3
__mbstate_t __state;
# 26 "/usr/include/_G_config.h" 3
} _G_fpos_t; }
# 31 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 28 "/usr/include/_G_config.h" 3
struct {
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.1/include/stdarg.h" 3
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
struct {
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
# 296 "/usr/include/stdio.h" 3
extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 302 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 309 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();
# 313 "/usr/include/stdio.h" 3
extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 320 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();
# 324 "/usr/include/stdio.h" 3
extern "C" void setlinebuf(FILE *) throw();
# 333 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 339 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);
# 341 "/usr/include/stdio.h" 3
extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 348 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 354 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list);
# 356 "/usr/include/stdio.h" 3
extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 363 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();
# 367 "/usr/include/stdio.h" 3
extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 376 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 379 "/usr/include/stdio.h" 3
extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 382 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 394 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);
# 397 "/usr/include/stdio.h" 3
extern "C" int dprintf(int, const char *__restrict__, ...);
# 407 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 413 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);
# 415 "/usr/include/stdio.h" 3
extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 453 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 461 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);
# 465 "/usr/include/stdio.h" 3
extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 513 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
# 514 "/usr/include/stdio.h" 3
extern "C" int getc(FILE *);
# 520 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 532 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
# 533 "/usr/include/stdio.h" 3
extern "C" int getchar_unlocked();
# 543 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE *);
# 555 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
# 556 "/usr/include/stdio.h" 3
extern "C" int putc(int, FILE *);
# 562 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 576 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int, FILE *);
# 584 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
# 585 "/usr/include/stdio.h" 3
extern "C" int putchar_unlocked(int);
# 592 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);
# 595 "/usr/include/stdio.h" 3
extern "C" int putw(int, FILE *);
# 604 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 612 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 622 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 638 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 641 "/usr/include/stdio.h" 3
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
# 712 "/usr/include/stdio.h" 3
extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 722 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);
# 727 "/usr/include/stdio.h" 3
extern "C" long ftell(FILE *);
# 732 "/usr/include/stdio.h" 3
extern "C" void rewind(FILE *);
# 746 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);
# 751 "/usr/include/stdio.h" 3
extern "C" __off_t ftello(FILE *);
# 771 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);
# 776 "/usr/include/stdio.h" 3
extern "C" int fsetpos(FILE *, const fpos_t *);
# 791 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int);
# 792 "/usr/include/stdio.h" 3
extern "C" __off64_t ftello64(FILE *);
# 793 "/usr/include/stdio.h" 3
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__);
# 794 "/usr/include/stdio.h" 3
extern "C" int fsetpos64(FILE *, const fpos64_t *);
# 799 "/usr/include/stdio.h" 3
extern "C" void clearerr(FILE *) throw();
# 801 "/usr/include/stdio.h" 3
extern "C" int feof(FILE *) throw();
# 803 "/usr/include/stdio.h" 3
extern "C" int ferror(FILE *) throw();
# 808 "/usr/include/stdio.h" 3
extern "C" void clearerr_unlocked(FILE *) throw();
# 809 "/usr/include/stdio.h" 3
extern "C" int feof_unlocked(FILE *) throw();
# 810 "/usr/include/stdio.h" 3
extern "C" int ferror_unlocked(FILE *) throw();
# 819 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
# 28 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const sys_errlist[]; }
# 31 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int _sys_nerr; }
# 32 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const _sys_errlist[]; }
# 831 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();
# 836 "/usr/include/stdio.h" 3
extern "C" int fileno_unlocked(FILE *) throw();
# 846 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 852 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 858 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 864 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);
# 869 "/usr/include/stdio.h" 3
struct obstack;
# 872 "/usr/include/stdio.h" 3
extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();
# 875 "/usr/include/stdio.h" 3
extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 886 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();
# 890 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE *) throw();
# 893 "/usr/include/stdio.h" 3
extern "C" void funlockfile(FILE *) throw();
# 62 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 64 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 65 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 66 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 67 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 68 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 69 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 70 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 71 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 72 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 73 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 77 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 75 "/usr/local/cuda/bin/../include/cuda.h"
struct CUuuid_st {
# 76 "/usr/local/cuda/bin/../include/cuda.h"
char bytes[16];
# 77 "/usr/local/cuda/bin/../include/cuda.h"
} CUuuid; }
# 97 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 88 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 89 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 90 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 91 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 92 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 93 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 94 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 95 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 96 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 97 "/usr/local/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 105 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 102 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 103 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 104 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC
# 105 "/usr/local/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 119 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 110 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 111 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 112 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 113 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 114 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 115 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 116 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 117 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 118 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 119 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 128 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 124 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 125 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 126 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 127 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR
# 128 "/usr/local/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 136 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 133 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 134 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 135 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 136 "/usr/local/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 177 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 141 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 142 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 143 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 144 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 145 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 146 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 147 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 148 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 149 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 150 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 151 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 152 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 153 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 154 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 155 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 156 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 157 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 159 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 160 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 161 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 162 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 163 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 164 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 165 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 166 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 167 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 168 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 169 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 170 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 171 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 172 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 173 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 174 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 175 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 176 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED
# 177 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 193 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 182 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 183 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 184 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 185 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 186 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 187 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 188 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 189 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 190 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 191 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 192 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 193 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 240 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 198 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 204 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 211 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 217 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 222 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 227 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 232 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 237 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 240 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 249 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 245 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 246 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 247 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 248 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 249 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 258 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 254 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 255 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 256 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 257 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 258 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 267 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 263 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 264 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 265 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 266 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 267 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 359 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 272 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 278 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 291 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 298 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 306 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 314 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 322 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 330 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 337 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 344 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 350 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 357 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 359 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 371 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 364 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 366 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 367 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 369 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 370 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20
# 371 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 384 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 376 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 379 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 382 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 384 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 391 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 389 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 390 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 391 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 400 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 396 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 397 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 398 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 399 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 400 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 412 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 405 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 406 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 407 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 408 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 409 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 410 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 411 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 412 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 420 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 417 "/usr/local/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 418 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 419 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE
# 420 "/usr/local/cuda/bin/../include/cuda.h"
} CUlimit; }
# 477 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 431 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 433 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 434 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 435 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 436 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 437 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 439 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 440 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 442 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 443 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 444 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 445 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 446 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 447 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 448 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 449 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 450 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 451 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 452 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 453 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 454 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 455 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 457 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 458 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 459 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 460 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 462 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 464 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 466 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 468 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 469 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 470 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 471 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 473 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_POINTER_IS_64BIT = 800,
# 474 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SIZE_IS_64BIT,
# 476 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 477 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 523 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 503 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 505 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 506 "/usr/local/cuda/bin/../include/cuda.h"
srcY;
# 507 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 508 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 509 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 510 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 511 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 513 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 514 "/usr/local/cuda/bin/../include/cuda.h"
dstY;
# 515 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 516 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 517 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 518 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 519 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 521 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 522 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 523 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 557 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 528 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 530 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 531 "/usr/local/cuda/bin/../include/cuda.h"
srcY,
# 532 "/usr/local/cuda/bin/../include/cuda.h"
srcZ;
# 533 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 534 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 535 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 536 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 537 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 538 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 539 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 540 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcHeight;
# 542 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 543 "/usr/local/cuda/bin/../include/cuda.h"
dstY,
# 544 "/usr/local/cuda/bin/../include/cuda.h"
dstZ;
# 545 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 546 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 547 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 548 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 549 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 550 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 551 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 552 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstHeight;
# 554 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 555 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 556 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 557 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 570 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 563 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 564 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 565 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 567 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 569 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 570 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 586 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 576 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 577 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 578 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 579 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 581 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 583 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 585 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 586 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 634 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 639 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 647 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 648 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 649 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 650 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 651 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 652 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 653 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 661 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 662 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 663 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 664 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 665 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 666 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 667 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 668 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 677 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 678 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 679 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 680 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 681 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 682 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 683 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 684 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 685 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref *, CUmodule, const char *);
# 693 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 695 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 696 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 704 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 705 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 707 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 708 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 710 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 712 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 713 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 726 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 727 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 730 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 733 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 734 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 737 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 738 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 741 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 745 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 746 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 750 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 765 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 767 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 771 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync(CUdeviceptr, CUdeviceptr, unsigned, CUstream);
# 775 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 781 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 784 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 791 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 792 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 793 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 795 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 796 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 797 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 806 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 807 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 808 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 809 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction, CUfunc_cache);
# 817 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 818 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 819 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 821 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 822 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 830 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 831 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 834 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 835 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, unsigned);
# 836 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 837 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 838 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 839 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 841 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 842 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 844 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 845 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 846 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 854 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref, CUarray, unsigned);
# 855 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray *, CUsurfref);
# 863 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 864 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 865 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 866 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 867 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 876 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 877 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 878 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 885 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 886 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 887 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 888 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 889 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 890 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 897 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 898 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 899 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 900 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 907 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 908 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 909 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *, unsigned *, CUgraphicsResource);
# 910 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 911 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 912 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 919 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void **, const CUuuid *);
# 927 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit, size_t);
# 928 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t *, CUlimit);
# 64 "../../sdk/cutil.h"
enum CUTBoolean {
# 66 "../../sdk/cutil.h"
CUTFalse,
# 67 "../../sdk/cutil.h"
CUTTrue
# 68 "../../sdk/cutil.h"
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
# 20 "../../sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 21 "../../sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 22 "../../sdk/cutil_inline_bankchecker.h"
{
# 23 "../../sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 24 "../../sdk/cutil_inline_bankchecker.h"
}
# 162 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef float2 cuFloatComplex; }
# 164 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCrealf(cuFloatComplex x)
# 165 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 166 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 167 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 169 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCimagf(cuFloatComplex x)
# 170 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 171 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 172 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 174 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex make_cuFloatComplex(float
# 175 "/usr/local/cuda/bin/../include/cuComplex.h"
r, float i)
# 176 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 177 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex res;
# 178 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 179 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 180 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 181 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 183 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuConjf(cuFloatComplex x)
# 184 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 185 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x), -cuCimagf(x));
# 186 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 187 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCaddf(cuFloatComplex x, cuFloatComplex
# 188 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 189 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 190 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) + cuCrealf(y), cuCimagf(x) + cuCimagf(y));
# 192 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 194 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCsubf(cuFloatComplex x, cuFloatComplex
# 195 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 196 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 197 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(cuCrealf(x) - cuCrealf(y), cuCimagf(x) - cuCimagf(y));
# 199 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 206 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCmulf(cuFloatComplex x, cuFloatComplex
# 207 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 208 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 209 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex prod;
# 210 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuFloatComplex((cuCrealf(x) * cuCrealf(y)) - (cuCimagf(x) * cuCimagf(y)), (cuCrealf(x) * cuCimagf(y)) + (cuCimagf(x) * cuCrealf(y)));
# 214 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 215 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 222 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuFloatComplex cuCdivf(cuFloatComplex x, cuFloatComplex
# 223 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 224 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 225 "/usr/local/cuda/bin/../include/cuComplex.h"
cuFloatComplex quot;
# 226 "/usr/local/cuda/bin/../include/cuComplex.h"
float s = (fabsf(cuCrealf(y)) + fabsf(cuCimagf(y)));
# 227 "/usr/local/cuda/bin/../include/cuComplex.h"
float oos = ((1.0F) / s);
# 228 "/usr/local/cuda/bin/../include/cuComplex.h"
float ars = (cuCrealf(x) * oos);
# 229 "/usr/local/cuda/bin/../include/cuComplex.h"
float ais = (cuCimagf(x) * oos);
# 230 "/usr/local/cuda/bin/../include/cuComplex.h"
float brs = (cuCrealf(y) * oos);
# 231 "/usr/local/cuda/bin/../include/cuComplex.h"
float bis = (cuCimagf(y) * oos);
# 232 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 233 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0F) / s);
# 234 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuFloatComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 236 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 237 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 247 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline float cuCabsf(cuFloatComplex x)
# 248 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 249 "/usr/local/cuda/bin/../include/cuComplex.h"
float a = cuCrealf(x);
# 250 "/usr/local/cuda/bin/../include/cuComplex.h"
float b = cuCimagf(x);
# 251 "/usr/local/cuda/bin/../include/cuComplex.h"
float v, w, t;
# 252 "/usr/local/cuda/bin/../include/cuComplex.h"
a = fabsf(a);
# 253 "/usr/local/cuda/bin/../include/cuComplex.h"
b = fabsf(b);
# 254 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 255 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 256 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 257 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 258 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 259 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 260 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 261 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 262 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0F) + (t * t));
# 263 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * sqrtf(t));
# 264 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0F)) || (v > (3.402823466e+38F))) || (w > (3.402823466e+38F))) {
# 265 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 266 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 267 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 268 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 271 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { typedef double2 cuDoubleComplex; }
# 273 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCreal(cuDoubleComplex x)
# 274 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 275 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.x;
# 276 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 278 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCimag(cuDoubleComplex x)
# 279 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 280 "/usr/local/cuda/bin/../include/cuComplex.h"
return x.y;
# 281 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 283 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex make_cuDoubleComplex(double
# 284 "/usr/local/cuda/bin/../include/cuComplex.h"
r, double i)
# 285 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 286 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex res;
# 287 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.x) = r;
# 288 "/usr/local/cuda/bin/../include/cuComplex.h"
(res.y) = i;
# 289 "/usr/local/cuda/bin/../include/cuComplex.h"
return res;
# 290 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 292 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuConj(cuDoubleComplex x)
# 293 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 294 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x), -cuCimag(x));
# 295 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 297 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCadd(cuDoubleComplex x, cuDoubleComplex
# 298 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 299 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 300 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) + cuCreal(y), cuCimag(x) + cuCimag(y));
# 302 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 304 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCsub(cuDoubleComplex x, cuDoubleComplex
# 305 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 306 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 307 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(cuCreal(x) - cuCreal(y), cuCimag(x) - cuCimag(y));
# 309 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 316 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCmul(cuDoubleComplex x, cuDoubleComplex
# 317 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 318 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 319 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex prod;
# 320 "/usr/local/cuda/bin/../include/cuComplex.h"
prod = make_cuDoubleComplex((cuCreal(x) * cuCreal(y)) - (cuCimag(x) * cuCimag(y)), (cuCreal(x) * cuCimag(y)) + (cuCimag(x) * cuCreal(y)));
# 324 "/usr/local/cuda/bin/../include/cuComplex.h"
return prod;
# 325 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 332 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline cuDoubleComplex cuCdiv(cuDoubleComplex x, cuDoubleComplex
# 333 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 334 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 335 "/usr/local/cuda/bin/../include/cuComplex.h"
cuDoubleComplex quot;
# 336 "/usr/local/cuda/bin/../include/cuComplex.h"
double s = (fabs(cuCreal(y)) + fabs(cuCimag(y)));
# 337 "/usr/local/cuda/bin/../include/cuComplex.h"
double oos = ((1.0) / s);
# 338 "/usr/local/cuda/bin/../include/cuComplex.h"
double ars = (cuCreal(x) * oos);
# 339 "/usr/local/cuda/bin/../include/cuComplex.h"
double ais = (cuCimag(x) * oos);
# 340 "/usr/local/cuda/bin/../include/cuComplex.h"
double brs = (cuCreal(y) * oos);
# 341 "/usr/local/cuda/bin/../include/cuComplex.h"
double bis = (cuCimag(y) * oos);
# 342 "/usr/local/cuda/bin/../include/cuComplex.h"
s = ((brs * brs) + (bis * bis));
# 343 "/usr/local/cuda/bin/../include/cuComplex.h"
oos = ((1.0) / s);
# 344 "/usr/local/cuda/bin/../include/cuComplex.h"
quot = make_cuDoubleComplex(((ars * brs) + (ais * bis)) * oos, ((ais * brs) - (ars * bis)) * oos);
# 346 "/usr/local/cuda/bin/../include/cuComplex.h"
return quot;
# 347 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 355 "/usr/local/cuda/bin/../include/cuComplex.h"
extern "C" { static inline double cuCabs(cuDoubleComplex x)
# 356 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 357 "/usr/local/cuda/bin/../include/cuComplex.h"
double a = cuCreal(x);
# 358 "/usr/local/cuda/bin/../include/cuComplex.h"
double b = cuCimag(x);
# 359 "/usr/local/cuda/bin/../include/cuComplex.h"
double v, w, t;
# 360 "/usr/local/cuda/bin/../include/cuComplex.h"
a = fabs(a);
# 361 "/usr/local/cuda/bin/../include/cuComplex.h"
b = fabs(b);
# 362 "/usr/local/cuda/bin/../include/cuComplex.h"
if (a > b) {
# 363 "/usr/local/cuda/bin/../include/cuComplex.h"
v = a;
# 364 "/usr/local/cuda/bin/../include/cuComplex.h"
w = b;
# 365 "/usr/local/cuda/bin/../include/cuComplex.h"
} else {
# 366 "/usr/local/cuda/bin/../include/cuComplex.h"
v = b;
# 367 "/usr/local/cuda/bin/../include/cuComplex.h"
w = a;
# 368 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 369 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (w / v);
# 370 "/usr/local/cuda/bin/../include/cuComplex.h"
t = ((1.0) + (t * t));
# 371 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v * sqrt(t));
# 372 "/usr/local/cuda/bin/../include/cuComplex.h"
if (((v == (0.0)) || (v > (1.797693134862315708e+308))) || (w > (1.797693134862315708e+308)))
# 373 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 374 "/usr/local/cuda/bin/../include/cuComplex.h"
t = (v + w);
# 375 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 376 "/usr/local/cuda/bin/../include/cuComplex.h"
return t;
# 377 "/usr/local/cuda/bin/../include/cuComplex.h"
} }
# 386 "/usr/local/cuda/bin/../include/cuComplex.h"
typedef cuFloatComplex cuComplex;
# 387 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuComplex make_cuComplex(float x, float
# 388 "/usr/local/cuda/bin/../include/cuComplex.h"
y)
# 389 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 390 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex(x, y);
# 391 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 394 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuComplexFloatToDouble(cuFloatComplex
# 395 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 396 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 397 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex((double)cuCrealf(c), (double)cuCimagf(c));
# 398 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 400 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuFloatComplex cuComplexDoubleToFloat(cuDoubleComplex
# 401 "/usr/local/cuda/bin/../include/cuComplex.h"
c)
# 402 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 403 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuFloatComplex((float)cuCreal(c), (float)cuCimag(c));
# 404 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 407 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuComplex cuCfmaf(cuComplex x, cuComplex y, cuComplex d)
# 408 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 409 "/usr/local/cuda/bin/../include/cuComplex.h"
float real_res;
# 410 "/usr/local/cuda/bin/../include/cuComplex.h"
float imag_res;
# 412 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((cuCrealf(x) * cuCrealf(y)) + cuCrealf(d));
# 413 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCrealf(x) * cuCimagf(y)) + cuCimagf(d));
# 415 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimagf(x) * cuCimagf(y))) + real_res);
# 416 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimagf(x) * cuCrealf(y)) + imag_res);
# 418 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuComplex(real_res, imag_res);
# 419 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 421 "/usr/local/cuda/bin/../include/cuComplex.h"
static inline cuDoubleComplex cuCfma(cuDoubleComplex x, cuDoubleComplex y, cuDoubleComplex d)
# 422 "/usr/local/cuda/bin/../include/cuComplex.h"
{
# 423 "/usr/local/cuda/bin/../include/cuComplex.h"
double real_res;
# 424 "/usr/local/cuda/bin/../include/cuComplex.h"
double imag_res;
# 426 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((cuCreal(x) * cuCreal(y)) + cuCreal(d));
# 427 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCreal(x) * cuCimag(y)) + cuCimag(d));
# 429 "/usr/local/cuda/bin/../include/cuComplex.h"
real_res = ((-(cuCimag(x) * cuCimag(y))) + real_res);
# 430 "/usr/local/cuda/bin/../include/cuComplex.h"
imag_res = ((cuCimag(x) * cuCreal(y)) + imag_res);
# 432 "/usr/local/cuda/bin/../include/cuComplex.h"
return make_cuDoubleComplex(real_res, imag_res);
# 433 "/usr/local/cuda/bin/../include/cuComplex.h"
}
# 71 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 61 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftResult_t {
# 62 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_SUCCESS,
# 63 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_INVALID_PLAN,
# 64 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_ALLOC_FAILED,
# 65 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_INVALID_TYPE,
# 66 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_INVALID_VALUE,
# 67 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_INTERNAL_ERROR,
# 68 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_EXEC_FAILED,
# 69 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_SETUP_FAILED,
# 70 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_INVALID_SIZE
# 71 "/usr/local/cuda/bin/../include/cufft.h"
} cufftResult; }
# 76 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef unsigned cufftHandle; }
# 80 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef float cufftReal; }
# 81 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef double cufftDoubleReal; }
# 86 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuComplex cufftComplex; }
# 87 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef cuDoubleComplex cufftDoubleComplex; }
# 101 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 94 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftType_t {
# 95 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_R2C = 42,
# 96 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2R = 44,
# 97 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_C2C = 41,
# 98 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_D2Z = 106,
# 99 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2D = 108,
# 100 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_Z2Z = 105
# 101 "/usr/local/cuda/bin/../include/cufft.h"
} cufftType; }
# 130 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" { typedef
# 125 "/usr/local/cuda/bin/../include/cufft.h"
enum cufftCompatibility_t {
# 126 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_NORMAL,
# 127 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_PADDING,
# 128 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_C2R_ASYMMETRIC,
# 129 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW
# 130 "/usr/local/cuda/bin/../include/cufft.h"
} cufftCompatibility; }
# 133 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 138 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 142 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 146 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int);
# 154 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 156 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 161 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 165 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 169 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);
# 174 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);
# 178 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);
# 182 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 185 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetCompatibilityMode(cufftHandle, cufftCompatibility);
# 22 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 23 "../../sdk/cutil_inline_runtime.h"
{
# 24 "../../sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 25 "../../sdk/cutil_inline_runtime.h"
exit(1);
# 26 "../../sdk/cutil_inline_runtime.h"
}
# 27 "../../sdk/cutil_inline_runtime.h"
}
# 29 "../../sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 30 "../../sdk/cutil_inline_runtime.h"
{
# 31 "../../sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 32 "../../sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 33 "../../sdk/cutil_inline_runtime.h"
fflush(stdout);
# 34 "../../sdk/cutil_inline_runtime.h"
fflush(stderr);
# 35 "../../sdk/cutil_inline_runtime.h"
getchar();
# 36 "../../sdk/cutil_inline_runtime.h"
}
# 37 "../../sdk/cutil_inline_runtime.h"
exit(0);
# 38 "../../sdk/cutil_inline_runtime.h"
}
# 41 "../../sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 42 "../../sdk/cutil_inline_runtime.h"
{
# 43 "../../sdk/cutil_inline_runtime.h"
int device_count = 0;
# 44 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 46 "../../sdk/cutil_inline_runtime.h"
cudaDeviceProp device_properties;
# 47 "../../sdk/cutil_inline_runtime.h"
int max_gflops_device = 0;
# 48 "../../sdk/cutil_inline_runtime.h"
int max_gflops = 0;
# 50 "../../sdk/cutil_inline_runtime.h"
int current_device = 0;
# 51 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 52 "../../sdk/cutil_inline_runtime.h"
max_gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 53 "../../sdk/cutil_inline_runtime.h"
++current_device;
# 55 "../../sdk/cutil_inline_runtime.h"
while (current_device < device_count)
# 56 "../../sdk/cutil_inline_runtime.h"
{
# 57 "../../sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 58 "../../sdk/cutil_inline_runtime.h"
int gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 59 "../../sdk/cutil_inline_runtime.h"
if (gflops > max_gflops)
# 60 "../../sdk/cutil_inline_runtime.h"
{
# 61 "../../sdk/cutil_inline_runtime.h"
max_gflops = gflops;
# 62 "../../sdk/cutil_inline_runtime.h"
max_gflops_device = current_device;
# 63 "../../sdk/cutil_inline_runtime.h"
}
# 64 "../../sdk/cutil_inline_runtime.h"
++current_device;
# 65 "../../sdk/cutil_inline_runtime.h"
}
# 67 "../../sdk/cutil_inline_runtime.h"
return max_gflops_device;
# 68 "../../sdk/cutil_inline_runtime.h"
}
# 70 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 71 "../../sdk/cutil_inline_runtime.h"
{
# 72 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 73 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 75 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 76 "../../sdk/cutil_inline_runtime.h"
}
# 77 "../../sdk/cutil_inline_runtime.h"
}
# 79 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 80 "../../sdk/cutil_inline_runtime.h"
{
# 81 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 82 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 84 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 85 "../../sdk/cutil_inline_runtime.h"
}
# 86 "../../sdk/cutil_inline_runtime.h"
}
# 88 "../../sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 89 "../../sdk/cutil_inline_runtime.h"
{
# 90 "../../sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 91 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 92 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 94 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 95 "../../sdk/cutil_inline_runtime.h"
}
# 96 "../../sdk/cutil_inline_runtime.h"
}
# 98 "../../sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 99 "../../sdk/cutil_inline_runtime.h"
{
# 100 "../../sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 101 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 103 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 104 "../../sdk/cutil_inline_runtime.h"
}
# 105 "../../sdk/cutil_inline_runtime.h"
}
# 107 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 108 "../../sdk/cutil_inline_runtime.h"
{
# 109 "../../sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 110 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 112 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 113 "../../sdk/cutil_inline_runtime.h"
}
# 114 "../../sdk/cutil_inline_runtime.h"
}
# 116 "../../sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 117 "../../sdk/cutil_inline_runtime.h"
{
# 118 "../../sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 119 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 120 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 122 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 123 "../../sdk/cutil_inline_runtime.h"
}
# 132 "../../sdk/cutil_inline_runtime.h"
}
# 133 "../../sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 134 "../../sdk/cutil_inline_runtime.h"
{
# 135 "../../sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 136 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 138 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 139 "../../sdk/cutil_inline_runtime.h"
}
# 140 "../../sdk/cutil_inline_runtime.h"
}
# 145 "../../sdk/cutil_inline_runtime.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 146 "../../sdk/cutil_inline_runtime.h"
{
# 147 "../../sdk/cutil_inline_runtime.h"
int deviceCount;
# 148 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "../../sdk/cutil_inline_runtime.h", 148);
# 149 "../../sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 150 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 151 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 152 "../../sdk/cutil_inline_runtime.h"
}
# 153 "../../sdk/cutil_inline_runtime.h"
int dev = 0;
# 154 "../../sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 155 "../../sdk/cutil_inline_runtime.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 157 "../../sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 158 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "../../sdk/cutil_inline_runtime.h", 158);
# 159 "../../sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 160 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 161 "../../sdk/cutil_inline_runtime.h"
exit(-1); }
# 163 "../../sdk/cutil_inline_runtime.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 164 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 165 "../../sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "../../sdk/cutil_inline_runtime.h", 165);
# 166 "../../sdk/cutil_inline_runtime.h"
}
# 171 "../../sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 172 "../../sdk/cutil_inline_runtime.h"
{
# 173 "../../sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 174 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 175 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 177 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 178 "../../sdk/cutil_inline_runtime.h"
}
# 179 "../../sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 180 "../../sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "../../sdk/cutil_inline_runtime.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 183 "../../sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "../../sdk/cutil_inline_runtime.h"
}
# 185 "../../sdk/cutil_inline_runtime.h"
}
# 16 "../../sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 17 "../../sdk/cutil_inline_drvapi.h"
{
# 18 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 19 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 21 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 22 "../../sdk/cutil_inline_drvapi.h"
}
# 23 "../../sdk/cutil_inline_drvapi.h"
}
# 24 "../../sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 25 "../../sdk/cutil_inline_drvapi.h"
{
# 26 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 27 "../../sdk/cutil_inline_drvapi.h"
}
# 29 "../../sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 30 "../../sdk/cutil_inline_drvapi.h"
{
# 31 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 32 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 33 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 35 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 36 "../../sdk/cutil_inline_drvapi.h"
}
# 37 "../../sdk/cutil_inline_drvapi.h"
}
# 39 "../../sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 40 "../../sdk/cutil_inline_drvapi.h"
{
# 41 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 42 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 43 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 44 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 46 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 47 "../../sdk/cutil_inline_drvapi.h"
}
# 48 "../../sdk/cutil_inline_drvapi.h"
}
# 54 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 55 "../../sdk/cutil_inline_drvapi.h"
{
# 56 "../../sdk/cutil_inline_drvapi.h"
cuDevice = 0;
# 57 "../../sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 58 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 59 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 60 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "../../sdk/cutil_inline_drvapi.h", 60); }
# 61 "../../sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 62 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 63 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 64 "../../sdk/cutil_inline_drvapi.h"
}
# 65 "../../sdk/cutil_inline_drvapi.h"
int dev = 0;
# 66 "../../sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 67 "../../sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 68 "../../sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 69 "../../sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "../../sdk/cutil_inline_drvapi.h", 69);
# 70 "../../sdk/cutil_inline_drvapi.h"
char name[100];
# 71 "../../sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 72 "../../sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 73 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 74 "../../sdk/cutil_inline_drvapi.h"
}
# 78 "../../sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 79 "../../sdk/cutil_inline_drvapi.h"
{
# 80 "../../sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 81 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 82 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 84 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 85 "../../sdk/cutil_inline_drvapi.h"
}
# 86 "../../sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 87 "../../sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 88 "../../sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 90 "../../sdk/cutil_inline_drvapi.h"
exit(-1);
# 91 "../../sdk/cutil_inline_drvapi.h"
}
# 92 "../../sdk/cutil_inline_drvapi.h"
}
# 12 "../../sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 13 "../../sdk/cutil_inline.h"
{
# 14 "../../sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 3010 / 1000, 3010 % 100);
# 15 "../../sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "../../sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "../../sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "../../sdk/cutil_inline.h"
}
# 52 "realtype.h"
typedef double real;
# 52 "MonteCarlo_common.h"
typedef
# 46 "MonteCarlo_common.h"
struct {
# 47 "MonteCarlo_common.h"
float S;
# 48 "MonteCarlo_common.h"
float X;
# 49 "MonteCarlo_common.h"
float T;
# 50 "MonteCarlo_common.h"
float R;
# 51 "MonteCarlo_common.h"
float V;
# 52 "MonteCarlo_common.h"
} TOptionData;
# 61 "MonteCarlo_common.h"
typedef
# 58 "MonteCarlo_common.h"
struct __attribute__((__aligned__(8))) {
# 59 "MonteCarlo_common.h"
float Expected;
# 60 "MonteCarlo_common.h"
float Confidence;
# 61 "MonteCarlo_common.h"
} TOptionValue;
# 85 "MonteCarlo_common.h"
typedef
# 64 "MonteCarlo_common.h"
struct {
# 66 "MonteCarlo_common.h"
int device;
# 68 "MonteCarlo_common.h"
int optionCount;
# 71 "MonteCarlo_common.h"
TOptionData *optionData;
# 72 "MonteCarlo_common.h"
TOptionValue *callValue;
# 74 "MonteCarlo_common.h"
void *d_Buffer;
# 77 "MonteCarlo_common.h"
unsigned seed;
# 79 "MonteCarlo_common.h"
int pathN;
# 81 "MonteCarlo_common.h"
float *d_Samples;
# 84 "MonteCarlo_common.h"
float time;
# 85 "MonteCarlo_common.h"
} TOptionPlan;
# 50 "MonteCarlo_reduction.cuh"
template<class T, unsigned blockSize> __attribute__((unused)) void
# 51 "MonteCarlo_reduction.cuh"
sumReduceSharedMem(T *sum, T *sum2, int tid)
# 52 "MonteCarlo_reduction.cuh"
{int volatile ___ = 1;
# 64 "MonteCarlo_reduction.cuh"
exit(___);}
# 74 "MonteCarlo_reduction.cuh"
template<class T, int SUM_N, int blockSize> __attribute__((unused)) void
# 75 "MonteCarlo_reduction.cuh"
sumReduce(T *sum, T *sum2)
# 76 "MonteCarlo_reduction.cuh"
{int volatile ___ = 1;
# 91 "MonteCarlo_reduction.cuh"
exit(___);}
# 73 "MonteCarlo_kernel.cuh"
typedef
# 68 "MonteCarlo_kernel.cuh"
struct {
# 69 "MonteCarlo_kernel.cuh"
real S;
# 70 "MonteCarlo_kernel.cuh"
real X;
# 71 "MonteCarlo_kernel.cuh"
real MuByT;
# 72 "MonteCarlo_kernel.cuh"
real VBySqrtT;
# 73 "MonteCarlo_kernel.cuh"
} __TOptionData;
# 74 "MonteCarlo_kernel.cuh"
static __TOptionData d_OptionData[2048];
# 80 "MonteCarlo_kernel.cuh"
typedef
# 77 "MonteCarlo_kernel.cuh"
struct {
# 78 "MonteCarlo_kernel.cuh"
real Expected;
# 79 "MonteCarlo_kernel.cuh"
real Confidence;
# 80 "MonteCarlo_kernel.cuh"
} __TOptionValue;
# 81 "MonteCarlo_kernel.cuh"
static __TOptionValue d_CallValue[2048];
# 94 "MonteCarlo_kernel.cuh"
__attribute__((unused)) inline double endCallValue(double S, double X, double r, double MuByT, double VBySqrtT) {int volatile ___ = 1;
# 97 "MonteCarlo_kernel.cuh"
exit(___);}
# 109 "MonteCarlo_kernel.cuh"
static void MonteCarloKernel(__TOptionValue *
# 110 "MonteCarlo_kernel.cuh"
d_Buffer, float *
# 111 "MonteCarlo_kernel.cuh"
d_Samples, int
# 112 "MonteCarlo_kernel.cuh"
pathN) ;
# 147 "MonteCarlo_kernel.cuh"
static void MonteCarloOneBlockPerOption(float *
# 148 "MonteCarlo_kernel.cuh"
d_Samples, int
# 149 "MonteCarlo_kernel.cuh"
pathN) ;
# 191 "MonteCarlo_kernel.cuh"
static void MonteCarloReduce(__TOptionValue *
# 192 "MonteCarlo_kernel.cuh"
d_Buffer, int
# 193 "MonteCarlo_kernel.cuh"
accumN) ;
# 228 "MonteCarlo_kernel.cuh"
static void initMonteCarloGPU(TOptionPlan *plan) {
# 229 "MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 230 "MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 231 "MonteCarlo_kernel.cuh"
const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 232 "MonteCarlo_kernel.cuh"
const int accumN = (256 * blocksPerOption);
# 233 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMalloc((void **)(&(plan->d_Buffer)), (accumN * (plan->optionCount)) * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 236);
# 237 "MonteCarlo_kernel.cuh"
}
# 238 "MonteCarlo_kernel.cuh"
}
# 241 "MonteCarlo_kernel.cuh"
static void closeMonteCarloGPU(TOptionPlan *plan) {
# 242 "MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 243 "MonteCarlo_kernel.cuh"
if (doMultiBlock) { __cudaSafeCall(cudaFree(plan->d_Buffer), "MonteCarlo_kernel.cuh", 243); }
# 244 "MonteCarlo_kernel.cuh"
}
# 247 "MonteCarlo_kernel.cuh"
static void MonteCarloGPU(TOptionPlan *plan) {
# 248 "MonteCarlo_kernel.cuh"
__TOptionData h_OptionData[2048];
# 249 "MonteCarlo_kernel.cuh"
__TOptionValue h_CallValue[2048];
# 251 "MonteCarlo_kernel.cuh"
if (((plan->optionCount) <= 0) || ((plan->optionCount) > 2048)) {
# 252 "MonteCarlo_kernel.cuh"
printf("MonteCarloGPU(): bad option count.\n");
# 253 "MonteCarlo_kernel.cuh"
return;
# 254 "MonteCarlo_kernel.cuh"
}
# 256 "MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 257 "MonteCarlo_kernel.cuh"
const double T = (((plan->optionData)[i]).T);
# 258 "MonteCarlo_kernel.cuh"
const double R = (((plan->optionData)[i]).R);
# 259 "MonteCarlo_kernel.cuh"
const double V = (((plan->optionData)[i]).V);
# 260 "MonteCarlo_kernel.cuh"
const double MuByT = ((R - (((0.5) * V) * V)) * T);
# 261 "MonteCarlo_kernel.cuh"
const double VBySqrtT = (V * sqrt(T));
# 262 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).S) = ((real)(((plan->optionData)[i]).S));
# 263 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).X) = ((real)(((plan->optionData)[i]).X));
# 264 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).MuByT) = ((real)MuByT);
# 265 "MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).VBySqrtT) = ((real)VBySqrtT);
# 266 "MonteCarlo_kernel.cuh"
}
# 268 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyToSymbol(d_OptionData, h_OptionData, (plan->optionCount) * sizeof(__TOptionData)), "MonteCarlo_kernel.cuh", 272);
# 274 "MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 275 "MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 276 "MonteCarlo_kernel.cuh"
const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 277 "MonteCarlo_kernel.cuh"
const int accumN = (256 * blocksPerOption);
# 278 "MonteCarlo_kernel.cuh"
const dim3 gridMain(blocksPerOption, plan->optionCount);
# 279 "MonteCarlo_kernel.cuh"
cudaConfigureCall(gridMain, 256) ? ((void)0) : MonteCarloKernel((__TOptionValue *)(plan->d_Buffer), plan->d_Samples, plan->pathN);
# 284 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloKernel() execution failed\n", "MonteCarlo_kernel.cuh", 284);
# 285 "MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloReduce((__TOptionValue *)(plan->d_Buffer), accumN);
# 289 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloReduce() execution failed\n", "MonteCarlo_kernel.cuh", 289);
# 290 "MonteCarlo_kernel.cuh"
} else {
# 291 "MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloOneBlockPerOption(plan->d_Samples, plan->pathN);
# 295 "MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloOneBlockPerOption() execution failed\n", "MonteCarlo_kernel.cuh", 295);
# 296 "MonteCarlo_kernel.cuh"
}
# 297 "MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyFromSymbol(h_CallValue, d_CallValue, (plan->optionCount) * sizeof(__TOptionValue)), "MonteCarlo_kernel.cuh", 301);
# 303 "MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 304 "MonteCarlo_kernel.cuh"
const double RT = ((((plan->optionData)[i]).R) * (((plan->optionData)[i]).T));
# 305 "MonteCarlo_kernel.cuh"
const double sum = (((h_CallValue)[i]).Expected);
# 306 "MonteCarlo_kernel.cuh"
const double sum2 = (((h_CallValue)[i]).Confidence);
# 307 "MonteCarlo_kernel.cuh"
const double pathN = (plan->pathN);
# 309 "MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Expected) = ((float)((exp(-RT) * sum) / pathN));
# 311 "MonteCarlo_kernel.cuh"
double stdDev = sqrt(((pathN * sum2) - (sum * sum)) / (pathN * (pathN - (1))));
# 313 "MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Confidence) = ((float)(((exp(-RT) * (1.959999999999999964)) * stdDev) / sqrt(pathN)));
# 314 "MonteCarlo_kernel.cuh"
}
# 315 "MonteCarlo_kernel.cuh"
}
# 99 "quasirandomGenerator_kernel.cuh"
__attribute__((unused)) inline double MoroInvCNDgpu(double P) {int volatile ___ = 1;
# 137 "quasirandomGenerator_kernel.cuh"
exit(___);}
# 193 "quasirandomGenerator_kernel.cuh"
__attribute__((unused)) inline double AcklamInvCNDgpu(double P) {int volatile ___ = 1;
# 240 "quasirandomGenerator_kernel.cuh"
exit(___);}
# 248 "quasirandomGenerator_kernel.cuh"
static void inverseCNDKernel(float *
# 249 "quasirandomGenerator_kernel.cuh"
d_Output, float *
# 250 "quasirandomGenerator_kernel.cuh"
d_Input, unsigned
# 251 "quasirandomGenerator_kernel.cuh"
pathN) ;
# 274 "quasirandomGenerator_kernel.cuh"
static void inverseCNDgpu(float *d_Output, float *d_Input, unsigned N) {
# 275 "quasirandomGenerator_kernel.cuh"
cudaConfigureCall(128, 128) ? ((void)0) : inverseCNDKernel(d_Output, d_Input, N);
# 276 "quasirandomGenerator_kernel.cuh"
__cutilCheckMsg("inverseCNDKernel() execution failed.\n", "quasirandomGenerator_kernel.cuh", 276);
# 277 "quasirandomGenerator_kernel.cuh"
}
# 44 "MonteCarlo_SM13.cu"
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan) {
# 45 "MonteCarlo_SM13.cu"
initMonteCarloGPU(plan);
# 46 "MonteCarlo_SM13.cu"
}
# 48 "MonteCarlo_SM13.cu"
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan) {
# 49 "MonteCarlo_SM13.cu"
closeMonteCarloGPU(plan);
# 50 "MonteCarlo_SM13.cu"
}
# 52 "MonteCarlo_SM13.cu"
extern "C" void MonteCarlo_SM13(TOptionPlan *plan) {
# 53 "MonteCarlo_SM13.cu"
MonteCarloGPU(plan);
# 54 "MonteCarlo_SM13.cu"
}
# 56 "MonteCarlo_SM13.cu"
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned N) {
# 57 "MonteCarlo_SM13.cu"
inverseCNDgpu(d_Output, d_Input, N);
# 58 "MonteCarlo_SM13.cu"
}
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00007ce1_00000000-3_MonteCarlo_SM13.fatbin.c" 1
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

typedef struct __cudaFatElfEntryRec {
    char* gpuProfileName;
    char* elf;
    struct __cudaFatElfEntryRec *next;
    unsigned int size;
} __cudaFatElfEntry;

typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 152 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 166 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
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
    __cudaFatElfEntry *elf;
} __cudaFatCudaBinary;
# 203 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode,
        __cudaFatForcePTX
    } __cudaFatCompilationPolicy;
# 227 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 240 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
unsigned char fatCheckJitForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *ptx );
# 250 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );





void __cudaFatFreePTX( char* ptx );


}
# 2 "/tmp/tmpxft_00007ce1_00000000-3_MonteCarlo_SM13.fatbin.c" 2



asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_13$:\n"
".quad 0x33010102464c457f,0x0000000000000002,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000014ec8,0x0000000000000040,0x00380040000d000d,0x000100180040000b\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000640\n"
".quad 0x000000000000033a,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x000000000000097a\n"
".quad 0x00000000000000a7,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000a21\n"
".quad 0x00000000000002e8,0x0000001900000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x000000010000012b,0x0000000000000006,0x0000000000000000,0x0000000000000d09\n"
".quad 0x00000000000003f0,0x1a00000c00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001c0,0x0000000000000002,0x0000000000000000,0x00000000000010f9\n"
".quad 0x0000000000000018,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000015a,0x0000000000000002,0x0000000000000000,0x0000000000001111\n"
".quad 0x000000000000001c,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000018c,0x0000000000000003,0x0000000000000000,0x000000000000112d\n"
".quad 0x0000000000000024,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000d6,0x0000000000100006,0x0000000000000000,0x000000000000112d\n"
".quad 0x0000000000000960,0x1d00000a00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000002d9,0x0000000000000002,0x0000000000000000,0x0000000000001a8d\n"
".quad 0x0000000000000038,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000ff,0x0000000000000002,0x0000000000000000,0x0000000000001ac5\n"
".quad 0x0000000000000018,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000002ab,0x0000000000000003,0x0000000000000000,0x0000000000001add\n"
".quad 0x0000000000001020,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000079,0x0000000000100006,0x0000000000000000,0x0000000000001add\n"
".quad 0x00000000000006e0,0x1000000800000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000229,0x0000000000000002,0x0000000000000000,0x00000000000021bd\n"
".quad 0x0000000000000020,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000a6,0x0000000000000002,0x0000000000000000,0x00000000000021dd\n"
".quad 0x0000000000000018,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000001f7,0x0000000000000003,0x0000000000000000,0x00000000000021f5\n"
".quad 0x0000000000001020,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x00000000000021f5\n"
".quad 0x0000000000002c70,0x1700000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000283,0x0000000000000002,0x0000000000000000,0x0000000000004e65\n"
".quad 0x0000000000000030,0x0000001000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000056,0x0000000000000002,0x0000000000000000,0x0000000000004e95\n"
".quad 0x000000000000001c,0x0000001000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000025e,0x0000000000000003,0x0000000000000000,0x0000000000004eb1\n"
".quad 0x0000000000000024,0x0000001000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000032c,0x0000000000000002,0x0000000000000000,0x0000000000004eb1\n"
".quad 0x0000000000010000,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000030a,0x0000000000000002,0x0000000000000000,0x0000000000014eb1\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000000000008,0x0000000000000000\n"
".quad 0x0000000900000319,0x0000000000000000,0x0000000000000000,0x0000000000014eb5\n"
".quad 0x0000000000000010,0x0000001500000003,0x0000000000000004,0x0000000000000010\n"
".quad 0x000000080000002b,0x0000000000000003,0x0000000000000000,0x0000000000014ec5\n"
".quad 0x0000000000008000,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x36315a5f2e747865\n"
".quad 0x4365737265766e69,0x6c656e72654b444e,0x6e2e006a5f536650,0x5f2e6f666e692e76\n"
".quad 0x7265766e6936315a,0x72654b444e436573,0x6a5f5366506c656e,0x5f2e747865742e00\n"
".quad 0x65746e6f4d36315a,0x6465526f6c726143,0x5f5f343150656375,0x566e6f6974704f54\n"
".quad 0x6e2e006965756c61,0x5f2e6f666e692e76,0x65746e6f4d36315a,0x6465526f6c726143\n"
".quad 0x5f5f343150656375,0x566e6f6974704f54,0x742e006965756c61,0x37325a5f2e747865\n"
".quad 0x72614365746e6f4d,0x6f6c42656e4f6f6c,0x74704f7265506b63,0x2e006966506e6f69\n"
".quad 0x2e6f666e692e766e,0x746e6f4d37325a5f,0x6e4f6f6c72614365,0x65506b636f6c4265\n"
".quad 0x506e6f6974704f72,0x747865742e006966,0x6e6f4d36315a5f2e,0x4b6f6c7261436574\n"
".quad 0x3431506c656e7265,0x6f6974704f545f5f,0x665065756c61566e,0x6e692e766e2e0069\n"
".quad 0x4d36315a5f2e6f66,0x6c72614365746e6f,0x506c656e72654b6f,0x74704f545f5f3431\n"
".quad 0x65756c61566e6f69,0x2e766e2e00696650,0x5f2e646572616873,0x65746e6f4d36315a\n"
".quad 0x72654b6f6c726143,0x5f5f3431506c656e,0x566e6f6974704f54,0x0069665065756c61\n"
".quad 0x736e6f632e766e2e,0x5a5f2e31746e6174,0x4365746e6f4d3631,0x6e72654b6f6c7261\n"
".quad 0x545f5f3431506c65,0x61566e6f6974704f,0x2e0069665065756c,0x65726168732e766e\n"
".quad 0x6f4d36315a5f2e64,0x6f6c72614365746e,0x3150656375646552,0x6974704f545f5f34\n"
".quad 0x6965756c61566e6f,0x6e6f632e766e2e00,0x5f2e31746e617473,0x65746e6f4d36315a\n"
".quad 0x6465526f6c726143,0x5f5f343150656375,0x566e6f6974704f54,0x6e2e006965756c61\n"
".quad 0x6465726168732e76,0x766e6936315a5f2e,0x4b444e4365737265,0x5366506c656e7265\n"
".quad 0x632e766e2e006a5f,0x31746e6174736e6f,0x766e6936315a5f2e,0x4b444e4365737265\n"
".quad 0x5366506c656e7265,0x732e766e2e006a5f,0x5a5f2e6465726168,0x4365746e6f4d3732\n"
".quad 0x42656e4f6f6c7261,0x4f7265506b636f6c,0x6966506e6f697470,0x6e6f632e766e2e00\n"
".quad 0x5f2e31746e617473,0x65746e6f4d37325a,0x656e4f6f6c726143,0x7265506b636f6c42\n"
".quad 0x66506e6f6974704f,0x6f632e766e2e0069,0x3431746e6174736e,0x766e2e6c65722e00\n"
".quad 0x6e6174736e6f632e,0x2e766e2e00343174,0x746e6174736e6f63,0x6936315a5f000030\n"
".quad 0x4e4365737265766e,0x506c656e72654b44,0x315a5f006a5f5366,0x614365746e6f4d36\n"
".quad 0x63756465526f6c72,0x4f545f5f34315065,0x6c61566e6f697470,0x37325a5f00696575\n"
".quad 0x72614365746e6f4d,0x6f6c42656e4f6f6c,0x74704f7265506b63,0x5f006966506e6f69\n"
".quad 0x65746e6f4d36315a,0x72654b6f6c726143,0x5f5f3431506c656e,0x566e6f6974704f54\n"
".quad 0x0069665065756c61,0x61566c6c61435f64,0x704f5f640065756c,0x617461446e6f6974\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0100030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0200030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0300030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000030000000000,0x0000000000000000,0x0000000000000000,0x1700030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x1000030000000000,0x0000000000000000\n"
".quad 0x00000000002c7000,0x1200030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0c00030000000000,0x0000000000000000,0x000000000006e000,0x0e00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0800030000000000,0x0000000000000000\n"
".quad 0x0000000000096000,0x0a00030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0400030000000000,0x0000000000000000,0x000000000003f000,0x0600030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0700030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0500030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0f00030000000000,0x0000000000000000,0x0000000000000000,0x0d00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x1300030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x1100030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0b00030000000000,0x0000000000000000,0x0000000000000000,0x0900030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x1500030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x1600030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x1400030000000000,0x0000000000000000,0x0000000000000000,0x1010120000000100\n"
".quad 0x0000000000000000,0x0000000000000000,0x0c10120000001b00,0x0000000000000000\n"
".quad 0x0000000000000000,0x0810120000004200,0x0000000000000000,0x0000000000000000\n"
".quad 0x0410120000006500,0x0000000000000000,0x0000000000000000,0x1700110000008e00\n"
".quad 0x0000000000000000,0x0000000000800000,0x1400110000009a00,0x0000000000000000\n"
".quad 0x0000000001000000,0x0047801000020500,0x000780a000000540,0x20478060014c5504\n"
".quad 0x20c7c83015d1fd00,0x000000a00740036c,0x200780a0004e3100,0x03c78010002a5104\n"
".quad 0x0002801006f00306,0x0007800005180500,0x00478010000201c0,0x1007803002280540\n"
".quad 0x00000310008009c4,0x0000031000800d00,0x00c7801400081100,0x00c78014000a1524\n"
".quad 0x00c78014000c1924,0x00c78014000e1d24,0x00c7801400042124,0x00c7801400062524\n"
".quad 0x2007804000483524,0x00c7801400002900,0x00c7801400022d24,0x0084002101ec5824\n"
".quad 0x03c7801000060510,0x10078030021a5d06,0xc00780d00e2c39c4,0x400780a0001c3980\n"
".quad 0x010780e00e0c39c4,0x029e4410009c4040,0x4047c8308023fd10,0x40c148308123fd6c\n"
".quad 0x000000a006400364,0x03c7801000224100,0x0001001005b00304,0x52b82f103e804100\n"
".quad 0xff71571007804506,0x000780e0101c4103,0x404780a000204180,0x464780a0002061cc\n"
".quad 0x4107c8308231fd88,0x410500210030616c,0x40c50010000a6504,0x40c2801000066524\n"
".quad 0xefa39f102f804924,0xfe62e71002804d0f,0x038780e01220390b,0xb39803103f804940\n"
".quad 0xc7abcb101e804d03,0x038780e01220390b,0xcf58bb102d804140,0xe21f07103f80450c\n"
".quad 0xa6c3bb102f804903,0xe5afdb1001804d0d,0x048780e0101c4103,0x60f80f1026804940\n"
".quad 0xe927e71015804d0f,0x048780e0101c4103,0xf02d671026804940,0xec71df101a804d08\n"
".quad 0x048780e0101c4103,0x3b894f1020804940,0xefa01b1020804d01,0x048780e0101c4103\n"
".quad 0xd3af7b1008804940,0xf2a01b1020804d01,0x048780e0101c4103,0x6c3a1f102c804940\n"
".quad 0xf56c17102c804d01,0x048780e0101c4103,0x1109171021804940,0xf811131011804d01\n"
".quad 0x048780e0101c4103,0x55554f1001804940,0xfa55571015804d05,0x048780e0101c4103\n"
".quad 0x555557102f804940,0xfc55571015804d05,0x048780e0101c4103,0x0000031000804940\n"
".quad 0xfe00031000804d00,0x048780e0101c4103,0x000780e0101c4140,0x1007803014304980\n"
".quad 0x038780e00e2041c4,0x03c7801000f83940,0xfe00032000a43d06,0x038780e00e203903\n"
".quad 0x03c7801000f84140,0x03c7801000324504,0x000780e0101c4106,0x0007801006400380\n"
".quad 0x0187c8307c21fd00,0x000003100080496c,0xff00031000804d00,0x0000031000804107\n"
".quad 0x0000031000804500,0x10c7d8e0121dfd00,0x03c28010002645e0,0x03c2801000244104\n"
".quad 0x039500e0001c4104,0x020782e010144160,0x0000031000803948,0x0000031000803d00\n"
".quad 0x03478020002a5500,0x000780e00e203904,0x2107c83015d1fdc0,0x008780e0001c096c\n"
".quad 0x000780e00e1c0160,0x05878020002e5940,0x0002801001900304,0x0007801007400300\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0084001100222000,0x03c7801000060510\n"
".quad 0x2007804008483504,0x000782401b301100,0x010780601a321100,0x1007803010081100\n"
".quad 0x010780601a3011c4,0x0507802000081100,0x1007803004081104,0x2107802000c811c4\n"
".quad 0x800780d00e080904,0x00000320088809a0,0x800781d00e040100,0x862e42c0874911a0\n"
".quad 0x000000fffffc0340,0x9000000000003740,0x000000000c0b043c,0x0000100000000800\n"
".quad 0x22011000080d0400,0x00004d0000002000,0x80260104000780a0,0x0001fd6c40c7d030\n"
".quad 0x0830030c0147c8a0,0x00264900000000a0,0x0830030603c78010,0x004c010000110010\n"
".quad 0x00426104200780a0,0x05000504200780a0,0x032401c000078000,0x00245dc410078030\n"
".quad 0x0330590403c78010,0x208055c410078030,0x2080510000008320,0x0008190000000320\n"
".quad 0x000a1d2400c78014,0x000c212400c78014,0x000e252400c78014,0x0004292400c78014\n"
".quad 0x00062d2400c78014,0x0000312400c78014,0x0002352400c78014,0x13cdfd2400c78014\n"
".quad 0x0780036c20c7d830,0x00266500000000a0,0x0750030603c78010,0x022e010000128010\n"
".quad 0x008009c410078030,0x00800d0000000310,0x00e8680000000310,0x0006051000840021\n"
".quad 0x0e34110603c78010,0x00081180c00780d0,0x041011c4400780a0,0x00883840018780e0\n"
".quad 0x811ffd10028a3c10,0x821ffd6c4047d830,0x06a0036440d15830,0x001e3900000000a0\n"
".quad 0x0610030403c78010,0x3e80390000110010,0x07803d0652b82f10,0x0e083903ff715710\n"
".quad 0x001c3980000780e0,0x001c6dcc404780a0,0x8337fd88464780a0,0x00366d6c4107d830\n"
".quad 0x001a710443150021,0x0016712440d50010,0x2f80412440d28010,0x0280450fefa39f10\n"
".quad 0x101c110bfe62e710,0x3f804140010780e0,0x1e804503b3980310,0x101c110bc7abcb10\n"
".quad 0x2d803940010780e0,0x3f803d0ccf58bb10,0x2f804103e21f0710,0x0180450da6c3bb10\n"
".quad 0x0e083903e5afdb10,0x26804140040780e0,0x1580450f60f80f10,0x0e083903e927e710\n"
".quad 0x26804140040780e0,0x1a804508f02d6710,0x0e083903ec71df10,0x20804140040780e0\n"
".quad 0x208045013b894f10,0x0e083903efa01b10,0x08804140040780e0,0x20804501d3af7b10\n"
".quad 0x0e083903f2a01b10,0x2c804140040780e0,0x2c8045016c3a1f10,0x0e083903f56c1710\n"
".quad 0x21804140040780e0,0x1180450111091710,0x0e083903f8111310,0x01804140040780e0\n"
".quad 0x1580450555554f10,0x0e083903fa555710,0x2f804140040780e0,0x1580450555555710\n"
".quad 0x0e083903fc555710,0x00804140040780e0,0x0080450000000310,0x0e083903fe000310\n"
".quad 0x0e083940040780e0,0x14364180000780e0,0x041c39c410078030,0x00f81140010780e0\n"
".quad 0x00a0150603c78010,0x041c1103fe000320,0x00f83940010780e0,0x00383d0403c78010\n"
".quad 0x0e08390603c78010,0x06a00380000780e0,0x7c1dfd0000078010,0x0080416c0187d830\n"
".quad 0x0080450000000310,0x00803907ff000310,0x00803d0000000310,0x1009fd0000000310\n"
".quad 0x00223de010c7e8e0,0x0020390403d28010,0x0008390403d28010,0x0e183960012500e0\n"
".quad 0x00801148028782e0,0x0080150000000310,0x00b2650000000310,0x041c110000001320\n"
".quad 0x19cdfdc0000780e0,0x0008096c2107d830,0x04080160008780e0,0x00b46940000780e0\n"
".quad 0x01f0030000004320,0x0780030000128010,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0084000000000310,0x002a051002860410,0x000001c000078200,0x000201e420878004\n"
".quad 0x002805e420c78004,0x00264dc000078000,0x0000010406078020,0x000201e420078004\n"
".quad 0x8027fde420478004,0x18ae5c6c40c7d830,0x002c552014ac5020,0x0160030405478020\n"
".quad 0x0000010000128010,0x121003e0000002f0,0x00240100000000a0,0x1210030403c78010\n"
".quad 0x1ffe030000010010,0x8401fd0000000086,0x0990036c4107c830,0x09900300000000a0\n"
".quad 0x0300050000028010,0x041009c000078000,0x04120d4400c78014,0x0610114400c78014\n"
".quad 0x0612154400c78014,0x0004094400c78014,0x04100160010780e0,0x041201e420878004\n"
".quad 0x00f008e420c78004,0x0210111500f20c15,0x0212154400c78014,0x0004094400c78014\n"
".quad 0x00100160010780e0,0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0\n"
".quad 0x8501fd0000000086,0x0ac0036c4107c830,0x0ac00300000000a0,0x0300050000028010\n"
".quad 0x041009c000078000,0x04120d4400c78014,0x0510114400c78014,0x0512154400c78014\n"
".quad 0x0004094400c78014,0x04100160010780e0,0x041201e420878004,0x00f008e420c78004\n"
".quad 0x0110111500f20c15,0x0112154400c78014,0x0004094400c78014,0x00100160010780e0\n"
".quad 0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0,0x8601fd0000000086\n"
".quad 0x0bf0036c4107c830,0x0bf00300000000a0,0x0300050000028010,0x041009c000078000\n"
".quad 0x04120d4400c78014,0x0490114400c78014,0x0492154400c78014,0x0004094400c78014\n"
".quad 0x04100160010780e0,0x041201e420878004,0x00f008e420c78004,0x0090111500f20c15\n"
".quad 0x0092154400c78014,0x0004094400c78014,0x00100160010780e0,0x001201e420878004\n"
".quad 0x000001e420c78004,0x1ffe03e0000002f0,0x8701fd0000000086,0x0d20036c4107c830\n"
".quad 0x0d200300000000a0,0x0300050000028010,0x041009c000078000,0x04120d4400c78014\n"
".quad 0x0450114400c78014,0x0452154400c78014,0x0004094400c78014,0x04100160010780e0\n"
".quad 0x041201e420878004,0x00f008e420c78004,0x0050111500f20c15,0x0052154400c78014\n"
".quad 0x0004094400c78014,0x00100160010780e0,0x001201e420878004,0x000001e420c78004\n"
".quad 0x1ffe03e0000002f0,0x8801fd0000000086,0x0e50036c4107c830,0x0e500300000000a0\n"
".quad 0x0300050000028010,0x041009c000078000,0x04120d4400c78014,0x0430114400c78014\n"
".quad 0x0432154400c78014,0x0004094400c78014,0x04100160010780e0,0x041201e420878004\n"
".quad 0x00f008e420c78004,0x0030111500f20c15,0x0032154400c78014,0x0004094400c78014\n"
".quad 0x00100160010780e0,0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0\n"
".quad 0x8901fd0000000086,0x0f80036c4107c830,0x0f800300000000a0,0x0300050000028010\n"
".quad 0x041009c000078000,0x04120d4400c78014,0x0420114400c78014,0x0422154400c78014\n"
".quad 0x0004094400c78014,0x04100160010780e0,0x041201e420878004,0x00f008e420c78004\n"
".quad 0x0020111500f20c15,0x0022154400c78014,0x0004094400c78014,0x00100160010780e0\n"
".quad 0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0,0x8a01fd0000000086\n"
".quad 0x10a0036c4107c830,0x10a00300000000a0,0x0300050000028010,0x041009c000078000\n"
".quad 0x04120d4400c78014,0x0418114400c78014,0x041a154400c78014,0x0004094400c78014\n"
".quad 0x04100160010780e0,0x041201e420878004,0x00f008e420c78004,0x00f8101500f20c15\n"
".quad 0x0004091500fa1415,0x00100160010780e0,0x001201e420878004,0x000001e420c78004\n"
".quad 0x1ffe03e0000002f0,0x7c01fd0000000086,0x11c0036c0107c830,0x11c00300000000a0\n"
".quad 0x0300050000028010,0x041009c000078000,0x04120d4400c78014,0x0414114400c78014\n"
".quad 0x0416154400c78014,0x0004094400c78014,0x04100160010780e0,0x041201e420878004\n"
".quad 0x00f008e420c78004,0x00f4101500f20c15,0x0004091500f61415,0x00100160010780e0\n"
".quad 0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0,0x0080010000000086\n"
".quad 0x8001fd0000001320,0x0870036c40c7c830,0x7c25fd0000028010,0x000003640147ca30\n"
".quad 0x004c010000028030,0x04000904200780a0,0x041001c410078030,0x0412054400c78010\n"
".quad 0x0004094400c78010,0x0e04010780078021,0x00f000a0800780d0,0x0884091100f20411\n"
".quad 0x0e04010000000320,0x0000ffa0800781d0,0x862e42c087491100,0x00007ffffffc0340\n"
".quad 0x00001f0000003f00,0x0000070000000f00,0x0000010000000300,0x0000374000000000\n"
".quad 0x080b043c90000000,0x0000080000000000,0x23011800080d0400,0x0000150000002000\n"
".quad 0x800a0104000780a0,0x0001fd6c40c7d030,0x0330030c0147c8a0,0x000a1100000000a0\n"
".quad 0x0330030603c78010,0x000c010000110010,0x014c054400c78010,0x1002050020078040\n"
".quad 0x00421dc410078030,0x004c0504200780a0,0x0008190020478060,0x0308010403c78010\n"
".quad 0x040205c410078030,0x030e35c410078030,0x208031c410078030,0x20802d0000008320\n"
".quad 0x00c8390000000320,0x05cdfd0420478020,0x0280036c20c7d830,0x000a2900000000a0\n"
".quad 0x0250030603c78010,0x040c010000128010,0x008009c410078030,0x00800d0000000310\n"
".quad 0x009c3c0000000310,0x0006051000840020,0x0e1e210603c78010,0x00100980800780d0\n"
".quad 0x089e2160008780e0,0x0e10210000000320,0x00100180800780d0,0x00942960000780e0\n"
".quad 0x0acdfd0000001320,0x009e3d6c2107d830,0x01b0030000010320,0x0280030000128010\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0084000000000310,0x0018051002860410\n"
".quad 0x000001c000078200,0x000201e420878004,0x001605e420c78004,0x000a15c000078000\n"
".quad 0x0000010401c78020,0x000201e420078004,0x800bfde420478004,0x078c186c40c7d830\n"
".quad 0x001a31200b9a2c20,0x0120030403078020,0x0000010000128010,0x0d1003e0000002f0\n"
".quad 0x00080100000000a0,0x0d10030403c78010,0x1ffe030000010010,0x8101fd0000000086\n"
".quad 0x0490036c4107c830,0x04900300000000a0,0x0300050000028010,0x041009c000078000\n"
".quad 0x04120d4400c78014,0x0610194400c78014,0x06121d4400c78014,0x0004094400c78014\n"
".quad 0x04100160018780e0,0x041201e420878004,0x00f008e420c78004,0x0210191500f20c15\n"
".quad 0x02121d4400c78014,0x0004094400c78014,0x00100160018780e0,0x001201e420878004\n"
".quad 0x000001e420c78004,0x1ffe03e0000002f0,0x8201fd0000000086,0x05c0036c4107c830\n"
".quad 0x05c00300000000a0,0x0300050000028010,0x041009c000078000,0x04120d4400c78014\n"
".quad 0x0510194400c78014,0x05121d4400c78014,0x0004094400c78014,0x04100160018780e0\n"
".quad 0x041201e420878004,0x00f008e420c78004,0x0110191500f20c15,0x01121d4400c78014\n"
".quad 0x0004094400c78014,0x00100160018780e0,0x001201e420878004,0x000001e420c78004\n"
".quad 0x1ffe03e0000002f0,0x8301fd0000000086,0x06f0036c4107c830,0x06f00300000000a0\n"
".quad 0x0300050000028010,0x041009c000078000,0x04120d4400c78014,0x0490194400c78014\n"
".quad 0x04921d4400c78014,0x0004094400c78014,0x04100160018780e0,0x041201e420878004\n"
".quad 0x00f008e420c78004,0x0090191500f20c15,0x00921d4400c78014,0x0004094400c78014\n"
".quad 0x00100160018780e0,0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0\n"
".quad 0x8401fd0000000086,0x0820036c4107c830,0x08200300000000a0,0x0300050000028010\n"
".quad 0x041009c000078000,0x04120d4400c78014,0x0450194400c78014,0x04521d4400c78014\n"
".quad 0x0004094400c78014,0x04100160018780e0,0x041201e420878004,0x00f008e420c78004\n"
".quad 0x0050191500f20c15,0x00521d4400c78014,0x0004094400c78014,0x00100160018780e0\n"
".quad 0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0,0x8501fd0000000086\n"
".quad 0x0950036c4107c830,0x09500300000000a0,0x0300050000028010,0x041009c000078000\n"
".quad 0x04120d4400c78014,0x0430194400c78014,0x04321d4400c78014,0x0004094400c78014\n"
".quad 0x04100160018780e0,0x041201e420878004,0x00f008e420c78004,0x0030191500f20c15\n"
".quad 0x00321d4400c78014,0x0004094400c78014,0x00100160018780e0,0x001201e420878004\n"
".quad 0x000001e420c78004,0x1ffe03e0000002f0,0x8601fd0000000086,0x0a80036c4107c830\n"
".quad 0x0a800300000000a0,0x0300050000028010,0x041009c000078000,0x04120d4400c78014\n"
".quad 0x0420194400c78014,0x04221d4400c78014,0x0004094400c78014,0x04100160018780e0\n"
".quad 0x041201e420878004,0x00f008e420c78004,0x0020191500f20c15,0x00221d4400c78014\n"
".quad 0x0004094400c78014,0x00100160018780e0,0x001201e420878004,0x000001e420c78004\n"
".quad 0x1ffe03e0000002f0,0x8701fd0000000086,0x0ba0036c4107c830,0x0ba00300000000a0\n"
".quad 0x0300050000028010,0x041009c000078000,0x04120d4400c78014,0x0418194400c78014\n"
".quad 0x041a1d4400c78014,0x0004094400c78014,0x04100160018780e0,0x041201e420878004\n"
".quad 0x00f008e420c78004,0x00f8181500f20c15,0x0004091500fa1c15,0x00100160018780e0\n"
".quad 0x001201e420878004,0x000001e420c78004,0x1ffe03e0000002f0,0x7c01fd0000000086\n"
".quad 0x0cc0036c0107c830,0x0cc00300000000a0,0x0300050000028010,0x041009c000078000\n"
".quad 0x04120d4400c78014,0x0414194400c78014,0x04161d4400c78014,0x0004094400c78014\n"
".quad 0x04100160018780e0,0x041201e420878004,0x00f008e420c78004,0x00f4181500f20c15\n"
".quad 0x0004091500f61c15,0x00100160018780e0,0x001201e420878004,0x000001e420c78004\n"
".quad 0x1ffe03e0000002f0,0x0080010000000086,0x8001fd0000001320,0x0370036c40c7c830\n"
".quad 0x7c09fd0000028010,0x000003640147ca30,0x004c010000028030,0x04000904200780a0\n"
".quad 0x041001c410078030,0x0412054400c78010,0x0004094400c78010,0x0e04010780078021\n"
".quad 0x00f000a0800780d0,0x0884091100f20411,0x0e04010000000320,0x0000ffa0800781d0\n"
".quad 0x00003f0000007f00,0x00000f0000001f00,0x0000030000000700,0x080b040000000100\n"
".quad 0x0000080000000000,0x22011000080d0400,0x7ccdfd0000002000,0x7ccffd642087c830\n"
".quad 0x004c05642082c830,0x00423104200780a0,0x00000104200780a0,0x20c00304000780a0\n"
".quad 0x0118410000028010,0x10d1fd6000078060,0x0000036420c7c830,0x0048050000028030\n"
".quad 0x02200104200780a0,0x411850c410078030,0x00c8452100ec4840,0x02284d0420078020\n"
".quad 0x0e2401c410078030,0x00800980c00780d0,0x00800d0000000310,0x00001103ff000310\n"
".quad 0x0209fdc4400780a0,0x008001e00187c8e0,0x0080050000000310,0x0009fd0000000310\n"
".quad 0x205003e000c148e0,0x01b00300000000a0,0x0080090000010010,0x00800d0000000310\n"
".quad 0x2050030fff800310,0x0080010000078010,0x0080050000000310,0x2180090bfe000310\n"
".quad 0x07800d0ae147af10,0x00080103fdae1710,0x0201fd60000780e0,0x204003e01047c8e0\n"
".quad 0x04100300000000a0,0x0000090000010010,0x38801180000780e0,0x2980150573777710\n"
".quad 0x3c80190c03970f10,0x12801d0c473c6f10,0x07802904044b2310,0x30802d020558a710\n"
".quad 0x3d8021040090bf10,0x2f802500701e5710,0x0404110c0350ff10,0x0a042940018780e0\n"
".quad 0x1e801940020780e0,0x30801d0ae54a3f10,0x2c80210c0329d710,0x1780250918150310\n"
".quad 0x0404110403715710,0x0a042940018780e0,0x0d801940020780e0,0x13801d01b2862310\n"
".quad 0x2d8021040040db10,0x3080250065507310,0x0404110c020f2710,0x0a042140018780e0\n"
".quad 0x00801940020780e0,0x00801d0000000310,0x04000103ff000310,0x08040980000780e0\n"
".quad 0x41400340018780e0,0x0280080000078020,0x2040031000820c10,0x0080090000078010\n"
".quad 0x00800d0000000310,0x0201fd0000000310,0x1e4003e00107c8e0,0x11700300000000a0\n"
".quad 0x0080090000010010,0x00800d0000000310,0x00081103ff000310,0x00800964008780e0\n"
".quad 0x00800d0000000310,0x0209fd0000000310,0x008019e00107c8e0,0x00801d0000000310\n"
".quad 0x02880807ff000310,0x0609fd10008a0c10,0x0ad003e00042c8e0,0x00061900000000a0\n"
".quad 0x09b0030603c78010,0x800dfd0000010010,0x000a09644107c830,0x000c0d2440c50010\n"
".quad 0x0208092440c50010,0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010\n"
".quad 0x14061504400780d0,0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020\n"
".quad 0x0084106440c7c830,0x000a151002861410,0x001c390442050021,0x0080190442450021\n"
".quad 0x00801d0000000310,0x00082103ff000310,0x00100960018780e0,0x000409c0404780a0\n"
".quad 0x0004090000078090,0x021019c4400780a0,0x00802144018780e0,0x0080250000000310\n"
".quad 0x060c190bff000310,0x00081140018780e0,0x020c1960020780e0,0x06080940008780e0\n"
".quad 0x00040980000780e0,0x1e802960008780e0,0x0b802d03ae80f310,0x04803103eb138310\n"
".quad 0x25803508b7a8b310,0x02042103ed0ee310,0x0a102980000780e0,0x2f803140030780e0\n"
".quad 0x26803509f0267710,0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710\n"
".quad 0x0a102903f1745f10,0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10\n"
".quad 0x2d803140030780e0,0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0\n"
".quad 0x19803509999a3f10,0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710\n"
".quad 0x0a102903fb555710,0x00043140030780e0,0x00183164010780e0,0x04041160030780e0\n"
".quad 0x0a102144030780e0,0x040c2980000780e0,0x001c1180000780e0,0x009c3944410780a0\n"
".quad 0x2f80190000000330,0x02801d0fefa39f10,0x08043103fe62e710,0x001c2140028780e0\n"
".quad 0x06082944410780a0,0x06101940008780e0,0x00040940028780e0,0x00181964018780e0\n"
".quad 0x3f800968008780e0,0x1e800d03b3980310,0x02080903c7abcb10,0x00141140018780e0\n"
".quad 0x0ad00360008780e0,0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310\n"
".quad 0x0a1003e010c7c8e0,0x0008110000028010,0x0ad00360010780e0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x0209fd0000000310,0x0a8003e00087c8e0,0x0080110000010010\n"
".quad 0x0080150000000310,0x0ad0030fff000310,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0209fd07ff000310,0x001411e00087c8e0,0x0016152440c10010,0x0008192440c10010\n"
".quad 0x008009e4404782a0,0x00800d0000000310,0x020dfd0000000310,0x008021e00107c8e0\n"
".quad 0x0080250000000310,0x008c0807ff000310,0x080dfd10028e0c10,0x115003e00042c8e0\n"
".quad 0x00062100000000a0,0x1000030403c78010,0x8011fd0000010010,0x000a09644107c830\n"
".quad 0x000c0d2440c50010,0x020c092440c50010,0x000e1180000500e0,0x0008112440c50010\n"
".quad 0x8106192440c28010,0x14061504400780d0,0x820c0dec10078030,0x00083904404780d0\n"
".quad 0x8307fd0401478020,0x0284106440c7c830,0x000a151000861410,0x001c390442050021\n"
".quad 0x0080190442450021,0x00801d0000000310,0x00082103ff000310,0x00100960018780e0\n"
".quad 0x000409c0404780a0,0x0004090000078090,0x021019c4400780a0,0x00802144018780e0\n"
".quad 0x0080250000000310,0x060c190bff000310,0x00081140018780e0,0x020c1960020780e0\n"
".quad 0x06080940008780e0,0x00040980000780e0,0x1e802960008780e0,0x0b802d03ae80f310\n"
".quad 0x04803103eb138310,0x25803508b7a8b310,0x02042103ed0ee310,0x0a102980000780e0\n"
".quad 0x2f803140030780e0,0x26803509f0267710,0x0a102903ef3b2710,0x16803140030780e0\n"
".quad 0x0b80350a9ab09710,0x0a102903f1745f10,0x14803140030780e0,0x07803502d1b51710\n"
".quad 0x0a102903f3c71f10,0x2d803140030780e0,0x2480350923be7310,0x0a102903f6249310\n"
".quad 0x04803140030780e0,0x19803509999a3f10,0x0a102903f8999b10,0x14803140030780e0\n"
".quad 0x1580350555555710,0x0a102903fb555710,0x00043140030780e0,0x00183164010780e0\n"
".quad 0x04041160030780e0,0x0a102144030780e0,0x040c2980000780e0,0x001c1180000780e0\n"
".quad 0x009c3944410780a0,0x2f80190000000330,0x02801d0fefa39f10,0x08043103fe62e710\n"
".quad 0x001c2140028780e0,0x06082944410780a0,0x06101940008780e0,0x00040940028780e0\n"
".quad 0x00181964018780e0,0x3f800968008780e0,0x1e800d03b3980310,0x02080903c7abcb10\n"
".quad 0x00140940018780e0,0x11500360008780e0,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0209fd07ff000310,0x107003e010c7c8e0,0x0008090000028010,0x00040960010780e0\n"
".quad 0x115003e4404780a0,0x0080090000078010,0x00800d0000000310,0x020dfd0000000310\n"
".quad 0x10e003e00087c8e0,0x0080090000010010,0x00800d0000000310,0x1150030fff000310\n"
".quad 0x0080090000078010,0x00800d0000000310,0x020dfd07ff000310,0x000c09e00087c8e0\n"
".quad 0x000e0d0603c68010,0x0014090403c68010,0x00160d2440c10010,0x0000012440c10010\n"
".quad 0x1e4003e0000002f0,0x0080090000078010,0x00800d0000000310,0x0209fd0000000310\n"
".quad 0x008019e00107c8e0,0x00801d0000000310,0x02880807ff000310,0x0609fd10008a0c10\n"
".quad 0x17b003e00042c8e0,0x00061900000000a0,0x1690030603c78010,0x800dfd0000010010\n"
".quad 0x000a09644107c830,0x000c0d2440c50010,0x0208092440c50010,0x000e1180000500e0\n"
".quad 0x0008112440c50010,0x8106192440c28010,0x14061504400780d0,0x820c0dec10078030\n"
".quad 0x00083904404780d0,0x8307fd0401478020,0x0084106440c7c830,0x000a151002861410\n"
".quad 0x001c390442050021,0x0080190442450021,0x00801d0000000310,0x00082103ff000310\n"
".quad 0x00100960018780e0,0x000409c0404780a0,0x0004090000078090,0x021019c4400780a0\n"
".quad 0x00802144018780e0,0x0080250000000310,0x060c190bff000310,0x00081140018780e0\n"
".quad 0x020c1960020780e0,0x06080940008780e0,0x00040980000780e0,0x1e802960008780e0\n"
".quad 0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310,0x02042103ed0ee310\n"
".quad 0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710,0x0a102903ef3b2710\n"
".quad 0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10,0x14803140030780e0\n"
".quad 0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0,0x2480350923be7310\n"
".quad 0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10,0x0a102903f8999b10\n"
".quad 0x14803140030780e0,0x1580350555555710,0x0a102903fb555710,0x00043140030780e0\n"
".quad 0x00183164010780e0,0x04041160030780e0,0x0a102144030780e0,0x040c2980000780e0\n"
".quad 0x001c1180000780e0,0x009c3944410780a0,0x2f80190000000330,0x02801d0fefa39f10\n"
".quad 0x08043103fe62e710,0x001c2140028780e0,0x06082944410780a0,0x06101940008780e0\n"
".quad 0x00040940028780e0,0x00181964018780e0,0x3f800968008780e0,0x1e800d03b3980310\n"
".quad 0x02080903c7abcb10,0x00141140018780e0,0x17b00360008780e0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x0209fd07ff000310,0x16f003e010c7c8e0,0x0008110000028010\n"
".quad 0x17b00360010780e0,0x0080090000078010,0x00800d0000000310,0x0209fd0000000310\n"
".quad 0x176003e00087c8e0,0x0080110000010010,0x0080150000000310,0x17b0030fff000310\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x001411e00087c8e0\n"
".quad 0x0016152440c10010,0x0008192440c10010,0x008009e4404782a0,0x00800d0000000310\n"
".quad 0x020dfd0000000310,0x008021e00107c8e0,0x0080250000000310,0x008c0807ff000310\n"
".quad 0x080dfd10028e0c10,0x1e3003e00042c8e0,0x00062100000000a0,0x1ce0030403c78010\n"
".quad 0x8011fd0000010010,0x000a09644107c830,0x000c0d2440c50010,0x020c092440c50010\n"
".quad 0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010,0x14061504400780d0\n"
".quad 0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020,0x0284106440c7c830\n"
".quad 0x000a151000861410,0x001c390442050021,0x0080190442450021,0x00801d0000000310\n"
".quad 0x00082103ff000310,0x00100960018780e0,0x000409c0404780a0,0x0004090000078090\n"
".quad 0x021019c4400780a0,0x00802144018780e0,0x0080250000000310,0x060c190bff000310\n"
".quad 0x00081140018780e0,0x020c1960020780e0,0x06080940008780e0,0x00040980000780e0\n"
".quad 0x1e802960008780e0,0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310\n"
".quad 0x02042103ed0ee310,0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710\n"
".quad 0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10\n"
".quad 0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0\n"
".quad 0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10\n"
".quad 0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710,0x0a102903fb555710\n"
".quad 0x00043140030780e0,0x00183164010780e0,0x04041160030780e0,0x0a102144030780e0\n"
".quad 0x040c2980000780e0,0x001c1180000780e0,0x009c3944410780a0,0x2f80190000000330\n"
".quad 0x02801d0fefa39f10,0x08043103fe62e710,0x001c2140028780e0,0x06082944410780a0\n"
".quad 0x06101940008780e0,0x00040940028780e0,0x00181964018780e0,0x3f800968008780e0\n"
".quad 0x1e800d03b3980310,0x02080903c7abcb10,0x00140940018780e0,0x1e300360008780e0\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x1d5003e010c7c8e0\n"
".quad 0x0008090000028010,0x00040960010780e0,0x1e3003e4404780a0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x020dfd0000000310,0x1dc003e00087c8e0,0x0080090000010010\n"
".quad 0x00800d0000000310,0x1e30030fff000310,0x0080090000078010,0x00800d0000000310\n"
".quad 0x020dfd07ff000310,0x000c09e00087c8e0,0x000e0d0603c68010,0x0014090403c68010\n"
".quad 0x00160d2440c10010,0x0000012440c10010,0x000001e0000002f0,0x2d8019e0000002f0\n"
".quad 0x05801d00a02d5b10,0x16801103e9a93f10,0x1580150709b7b710,0x06041903e9361f10\n"
".quad 0x08801140010780e0,0x328015005f582310,0x06041903f00deb10,0x06801140010780e0\n"
".quad 0x2e80150a0a988710,0x06041903f39e6310,0x05801140010780e0,0x0380150e53e67b10\n"
".quad 0x06041903f6f76710,0x37801140010780e0,0x2d8015073e442310,0x06041903f9c4eb10\n"
".quad 0x06801140010780e0,0x0780150266906b10,0x06041903fc495310,0x31801140010780e0\n"
".quad 0x0680150cf8bc1310,0x06041103fef3cf10,0x2d801940010780e0,0x32801d0c3e403710\n"
".quad 0x00802103fd599310,0x0080250000000310,0x0404110000000310,0x0801fd40018780e0\n"
".quad 0x028808e00047c8e0,0x00080910008a0c10,0x000001e4404280a0,0x000401e0000002f0\n"
".quad 0x002841c0404782a0,0x0e22010404078020,0x10d1fda0c00780d0,0x13a448642107c830\n"
".quad 0x00e0032011a64420,0x0000030000028010,0x0118490000078030,0x12d1fd6000078060\n"
".quad 0x0000036420c7c830,0x01f0010000028030,0x0000010000000321,0x00483d44400780a0\n"
".quad 0x4f600304200780a0,0x0f18550000078020,0x0224090001078040,0x00c851c410078030\n"
".quad 0x022a4d0420878020,0x028040c410078030,0x01a4011000824410,0x0000010000000320\n"
".quad 0x00800944400780a0,0x00800d0000000310,0x10001103ff000310,0x0209fd80000780e0\n"
".quad 0x008001e00187c8e0,0x0080050000000310,0x0009fd0000000310,0x40d003e000c148e0\n"
".quad 0x22600300000000a0,0x0080090000010010,0x00800d0000000310,0x40d0030fff800310\n"
".quad 0x0080010000078010,0x0080050000000310,0x2180090bfe000310,0x07800d0ae147af10\n"
".quad 0x00080103fdae1710,0x0201fd60000780e0,0x40c003e01047c8e0,0x24c00300000000a0\n"
".quad 0x0000110000010010,0x38801980000780e0,0x29801d0573777710,0x3c80090c03970f10\n"
".quad 0x12800d0c473c6f10,0x07802904044b2310,0x30802d020558a710,0x3d8021040090bf10\n"
".quad 0x2f802500701e5710,0x0608090c0350ff10,0x0a082940008780e0,0x1e801940020780e0\n"
".quad 0x30801d0ae54a3f10,0x2c80210c0329d710,0x1780250918150310,0x0208090403715710\n"
".quad 0x0a082940018780e0,0x0d801940020780e0,0x13801d01b2862310,0x2d8021040040db10\n"
".quad 0x3080250065507310,0x0208090c020f2710,0x0a082140018780e0,0x00801940020780e0\n"
".quad 0x00801d0000000310,0x02000103ff000310,0x08080980000780e0,0x41400340018780e0\n"
".quad 0x0280080000078020,0x40c0031000820c10,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0201fd0000000310,0x3ec003e00107c8e0,0x32100300000000a0,0x0080090000010010\n"
".quad 0x00800d0000000310,0x00081103ff000310,0x00800964008780e0,0x00800d0000000310\n"
".quad 0x0209fd0000000310,0x008019e00107c8e0,0x00801d0000000310,0x02880807ff000310\n"
".quad 0x0609fd10008a0c10,0x2b8003e00042c8e0,0x00061900000000a0,0x2a60030603c78010\n"
".quad 0x800dfd0000010010,0x000a09644107c830,0x000c0d2440c50010,0x0208092440c50010\n"
".quad 0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010,0x14061504400780d0\n"
".quad 0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020,0x0084106440c7c830\n"
".quad 0x000a151002861410,0x001c390442050021,0x0080190442450021,0x00801d0000000310\n"
".quad 0x00082103ff000310,0x00100960018780e0,0x000409c0404780a0,0x0004090000078090\n"
".quad 0x021019c4400780a0,0x00802144018780e0,0x0080250000000310,0x060c190bff000310\n"
".quad 0x00081140018780e0,0x020c1960020780e0,0x06080940008780e0,0x00040980000780e0\n"
".quad 0x1e802960008780e0,0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310\n"
".quad 0x02042103ed0ee310,0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710\n"
".quad 0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10\n"
".quad 0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0\n"
".quad 0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10\n"
".quad 0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710,0x0a102903fb555710\n"
".quad 0x0a102140030780e0,0x00042980000780e0,0x00142964010780e0,0x04041160028780e0\n"
".quad 0x040c2944028780e0,0x001c1180000780e0,0x009c3944410780a0,0x2f80190000000330\n"
".quad 0x02801d0fefa39f10,0x08043103fe62e710,0x001c2140028780e0,0x06082944410780a0\n"
".quad 0x06101940008780e0,0x00040940028780e0,0x00181964018780e0,0x3f800968008780e0\n"
".quad 0x1e800d03b3980310,0x02080903c7abcb10,0x00141140018780e0,0x2b800360008780e0\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x2ac003e010c7c8e0\n"
".quad 0x0008110000028010,0x2b800360010780e0,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0209fd0000000310,0x2b3003e00087c8e0,0x0080110000010010,0x0080150000000310\n"
".quad 0x2b80030fff000310,0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310\n"
".quad 0x001411e00087c8e0,0x0016152440c10010,0x0008192440c10010,0x008009e4404782a0\n"
".quad 0x00800d0000000310,0x020dfd0000000310,0x008021e00107c8e0,0x0080250000000310\n"
".quad 0x008c0807ff000310,0x080dfd10028e0c10,0x31f003e00042c8e0,0x00062100000000a0\n"
".quad 0x30a0030403c78010,0x8011fd0000010010,0x000a09644107c830,0x000c0d2440c50010\n"
".quad 0x020c092440c50010,0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010\n"
".quad 0x14061504400780d0,0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020\n"
".quad 0x00060d6440c7c830,0x001c390442050021,0x0080190442450021,0x00801d0000000310\n"
".quad 0x00042103ff000310,0x00101160018780e0,0x000811c0404780a0,0x0008110000078090\n"
".quad 0x041019c4400780a0,0x00802144018780e0,0x0080250000000310,0x060c190bff000310\n"
".quad 0x00040940018780e0,0x040c1160020780e0,0x04041940010780e0,0x000c1980000780e0\n"
".quad 0x1e802960018780e0,0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310\n"
".quad 0x060c2103ed0ee310,0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710\n"
".quad 0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10\n"
".quad 0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0\n"
".quad 0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10\n"
".quad 0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710,0x0a102903fb555710\n"
".quad 0x0a102140030780e0,0x000c2980000780e0,0x00142964008780e0,0x020c0960028780e0\n"
".quad 0x02082944028780e0,0x001c0980000780e0,0x009c3944410780a0,0x2f80110000000330\n"
".quad 0x0280150fefa39f10,0x080c3103fe62e710,0x001c2140028780e0,0x04042944410780a0\n"
".quad 0x04101140018780e0,0x000c1140028780e0,0x00181964010780e0,0x3f801168010780e0\n"
".quad 0x1e801503b3980310,0x04040903c7abcb10,0x00140940018780e0,0x31f00360008780e0\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x311003e010c7c8e0\n"
".quad 0x0008090000028010,0x00040960010780e0,0x31f003e4404780a0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x020dfd0000000310,0x318003e00087c8e0,0x0080090000010010\n"
".quad 0x00800d0000000310,0x31f0030fff000310,0x0080090000078010,0x00800d0000000310\n"
".quad 0x020dfd07ff000310,0x000c09e00087c8e0,0x000e0d0603c68010,0x0014090403c68010\n"
".quad 0x00160d2440c10010,0x0000012440c10010,0x3ec003e0000002f0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x0209fd0000000310,0x008019e00107c8e0,0x00801d0000000310\n"
".quad 0x02880807ff000310,0x0609fd10008a0c10,0x384003e00042c8e0,0x00061900000000a0\n"
".quad 0x3720030603c78010,0x800dfd0000010010,0x000a09644107c830,0x000c0d2440c50010\n"
".quad 0x0208092440c50010,0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010\n"
".quad 0x14061504400780d0,0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020\n"
".quad 0x00060d6440c7c830,0x001c390442050021,0x0080190442450021,0x00801d0000000310\n"
".quad 0x00042103ff000310,0x00101160018780e0,0x000811c0404780a0,0x0008110000078090\n"
".quad 0x041019c4400780a0,0x00802144018780e0,0x0080250000000310,0x060c190bff000310\n"
".quad 0x00040940018780e0,0x040c1160020780e0,0x04041940010780e0,0x000c1980000780e0\n"
".quad 0x1e802960018780e0,0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310\n"
".quad 0x060c2103ed0ee310,0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710\n"
".quad 0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10\n"
".quad 0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0\n"
".quad 0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10\n"
".quad 0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710,0x0a102903fb555710\n"
".quad 0x0a102140030780e0,0x000c2980000780e0,0x00142964008780e0,0x020c0960028780e0\n"
".quad 0x02082944028780e0,0x001c0980000780e0,0x009c3944410780a0,0x2f80110000000330\n"
".quad 0x0280150fefa39f10,0x080c3103fe62e710,0x001c2140028780e0,0x04042944410780a0\n"
".quad 0x04101140018780e0,0x000c1140028780e0,0x00181964010780e0,0x3f801168010780e0\n"
".quad 0x1e801503b3980310,0x04040903c7abcb10,0x00141140018780e0,0x38400360008780e0\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x378003e010c7c8e0\n"
".quad 0x0008110000028010,0x38400360010780e0,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0209fd0000000310,0x37f003e00087c8e0,0x0080110000010010,0x0080150000000310\n"
".quad 0x3840030fff000310,0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310\n"
".quad 0x001411e00087c8e0,0x0016152440c10010,0x0008192440c10010,0x008009e4404782a0\n"
".quad 0x00800d0000000310,0x020dfd0000000310,0x008021e00107c8e0,0x0080250000000310\n"
".quad 0x008c0807ff000310,0x080dfd10028e0c10,0x3eb003e00042c8e0,0x00062100000000a0\n"
".quad 0x3d60030403c78010,0x8011fd0000010010,0x000a09644107c830,0x000c0d2440c50010\n"
".quad 0x020c092440c50010,0x000e1180000500e0,0x0008112440c50010,0x8106192440c28010\n"
".quad 0x14061504400780d0,0x820c0dec10078030,0x00083904404780d0,0x8307fd0401478020\n"
".quad 0x00060d6440c7c830,0x001c390442050021,0x0080190442450021,0x00801d0000000310\n"
".quad 0x00042103ff000310,0x00101160018780e0,0x000811c0404780a0,0x0008110000078090\n"
".quad 0x041019c4400780a0,0x00802144018780e0,0x0080250000000310,0x060c190bff000310\n"
".quad 0x00040940018780e0,0x040c1160020780e0,0x04041940010780e0,0x000c1980000780e0\n"
".quad 0x1e802960018780e0,0x0b802d03ae80f310,0x04803103eb138310,0x25803508b7a8b310\n"
".quad 0x060c2103ed0ee310,0x0a102980000780e0,0x2f803140030780e0,0x26803509f0267710\n"
".quad 0x0a102903ef3b2710,0x16803140030780e0,0x0b80350a9ab09710,0x0a102903f1745f10\n"
".quad 0x14803140030780e0,0x07803502d1b51710,0x0a102903f3c71f10,0x2d803140030780e0\n"
".quad 0x2480350923be7310,0x0a102903f6249310,0x04803140030780e0,0x19803509999a3f10\n"
".quad 0x0a102903f8999b10,0x14803140030780e0,0x1580350555555710,0x0a102903fb555710\n"
".quad 0x0a102140030780e0,0x000c2980000780e0,0x00142964008780e0,0x020c0960028780e0\n"
".quad 0x02082944028780e0,0x001c0980000780e0,0x009c3944410780a0,0x2f80110000000330\n"
".quad 0x0280150fefa39f10,0x080c3103fe62e710,0x001c2140028780e0,0x04042944410780a0\n"
".quad 0x04101140018780e0,0x000c1140028780e0,0x00181964010780e0,0x3f801168010780e0\n"
".quad 0x1e801503b3980310,0x04040903c7abcb10,0x00140940018780e0,0x3eb00360008780e0\n"
".quad 0x0080090000078010,0x00800d0000000310,0x0209fd07ff000310,0x3dd003e010c7c8e0\n"
".quad 0x0008090000028010,0x00040960010780e0,0x3eb003e4404780a0,0x0080090000078010\n"
".quad 0x00800d0000000310,0x020dfd0000000310,0x3e4003e00087c8e0,0x0080090000010010\n"
".quad 0x00800d0000000310,0x3eb0030fff000310,0x0080090000078010,0x00800d0000000310\n"
".quad 0x020dfd07ff000310,0x000c09e00087c8e0,0x000e0d0603c68010,0x0014090403c68010\n"
".quad 0x00160d2440c10010,0x0000012440c10010,0x000001e0000002f0,0x2d8019e0000002f0\n"
".quad 0x05801d00a02d5b10,0x16801103e9a93f10,0x1580150709b7b710,0x06041903e9361f10\n"
".quad 0x08801140010780e0,0x328015005f582310,0x06041903f00deb10,0x06801140010780e0\n"
".quad 0x2e80150a0a988710,0x06041903f39e6310,0x05801140010780e0,0x0380150e53e67b10\n"
".quad 0x06041903f6f76710,0x37801140010780e0,0x2d8015073e442310,0x06041903f9c4eb10\n"
".quad 0x06801140010780e0,0x0780150266906b10,0x06041903fc495310,0x31801140010780e0\n"
".quad 0x0680150cf8bc1310,0x06041903fef3cf10,0x2d801140010780e0,0x3280150c3e403710\n"
".quad 0x00802103fd599310,0x0080250000000310,0x0604110000000310,0x0801fd40010780e0\n"
".quad 0x028808e00047c8e0,0x00080910008a0c10,0x000001e4404280a0,0x000401e0000002f0\n"
".quad 0x002a49c0404782a0,0x0e28010404878020,0x12d1fda0c00780d0,0x002851642107c830\n"
".quad 0x2180030404c78020,0x0000030000028010,0x0004110000078030,0x0006150603c78010\n"
".quad 0x0000190403c78010,0x00021d0603c78010,0x0000290403c78010,0x00022d0603c78010\n"
".quad 0x0004310403c78010,0x0006350603c78010,0x1406090403c78010,0x3f8001e410078030\n"
".quad 0x0004090000007f10,0x3f843904000780d0,0x1402050fffffff20,0x000201e410078030\n"
".quad 0x3f803d04000780d0,0x0080590fffffff20,0x3e80010000000310,0x001ffd0000007f10\n"
".quad 0x001dfd640187c830,0x47c0036401814830,0x47c00300000000a0,0x000c090000010010\n"
".quad 0x008001c4504780a0,0x0080050000000310,0x0005fd07ff000310,0x432003e000c7c8e0\n"
".quad 0x0014010000028010,0x0080050603c78010,0x0116050000800310,0x00000304004780d0\n"
".quad 0x0008090000078030,0x008001c4504780a0,0x0080050000000310,0x0005fd07ff000310\n"
".quad 0x43b003e000c7c8e0,0x0018010000028010,0x0080050403c78010,0x011a050000800310\n"
".quad 0x00000304004780d0,0x0080010000078030,0x0080050000000310,0x000c210000000310\n"
".quad 0x008001e0008780e0,0x000c090000000310,0x008005c4504780a0,0x0008010000000310\n"
".quad 0x001021e0008780e0,0x00800104000780d0,0x0080050000000310,0x00042507ff000310\n"
".quad 0x000809e0008780e0,0x000401c4504780a0,0x001201e0008780e0,0x0011fd04000780d0\n"
".quad 0x44e003040047c8d0,0x0080010000010010,0x0080050000000310,0x0000030fff800310\n"
".quad 0x0008210000078030,0x008001c4504780a0,0x0080050000000310,0x0080090000000310\n"
".quad 0x00800d0000000310,0x0211fd07ff000310,0x000dfde00087c8e0,0x45b003e0008148e0\n"
".quad 0x0d16010000010010,0x00800504008780d0,0x0100050800000310,0x00800104000780d0\n"
".quad 0x0000030000000310,0x000c210000078030,0x008001c4504780a0,0x0080050000000310\n"
".quad 0x0080090000000310,0x00800d0000000310,0x0211fd07ff000310,0x0009fde00087c8e0\n"
".quad 0x46a003e0008148e0,0x0d16010000010010,0x00800504008780d0,0x0100010800000310\n"
".quad 0x00800504000780d0,0x01000507ff000310,0x00800104004780d0,0x0000030000000310\n"
".quad 0x0080010000078030,0x001ffd0000000310,0x4720036c0047c830,0x47200300000000a0\n"
".quad 0x0080010000010010,0x0080050000000310,0x000c290435000310,0x0a805980000780e0\n"
".quad 0x0000010fffffff10,0x008001e0000002f0,0x001dfd0000000310,0x47b0036c0047c830\n"
".quad 0x47b00300000000a0,0x0080010000010010,0x0080050000000310,0x0008310435000310\n"
".quad 0x36ac5980000780e0,0x0000010000000320,0x001801e0000002f0,0x029c310603c78210\n"
".quad 0x1418050fffffc320,0x401a05c410078030,0x0000090400478020,0x000409c0464780a0\n"
".quad 0x0014190000078090,0x029e350403c78010,0x0004110fffffc320,0x008009c4400780a0\n"
".quad 0x00800d0000000310,0x00082103ff000310,0x08103944008780e0,0x08082180000780e0\n"
".quad 0x081c2140010780e0,0x08000940020780e0,0x02100944008780e0,0x141a1d40020780e0\n"
".quad 0x40161dc410078030,0x040c110401c78020,0x00082980000780e0,0x08141144018780e0\n"
".quad 0x00080140010780e0,0x02001944018780e0,0x000e2140010780e0,0x140e1d0603c78010\n"
".quad 0x3f8025e410078030,0x090e1d0000007f10,0x018e1d04000780d0,0x0018250fffffc320\n"
".quad 0x000e250403478030,0x0012290402478020,0x3e94250405878020,0x3d802d0000003f20\n"
".quad 0x0b13fd0000007f10,0x4f30036400c7c830,0x4a600300000000a0,0x000c010000010010\n"
".quad 0x4014050403c78010,0x1402050401c78020,0x001005c410078030,0x4f30030400478020\n"
".quad 0x3f80190000078010,0x0615fd0000003f10,0x4f20036c0107c830,0x4b000300000000a0\n"
".quad 0x0080010000010010,0x0010010800000310,0x00800504000780d0,0x01000507ff000310\n"
".quad 0x00800104004780d0,0x4f20030000000310,0x0080190000078010,0x06102d0800000310\n"
".quad 0x0c801904000780d0,0x0615fd0fffffbf10,0x4f10036c0047c830,0x4b900300000000a0\n"
".quad 0x0080010000010010,0x0016050000000310,0x4f10030603c78010,0x0200210000078010\n"
".quad 0x02001940810780e0,0x06101940410780e0,0x000c19e0034780e0,0x0200012c014780a0\n"
".quad 0x3f800940c10780e0,0x0202050000ffff10,0x00800904000780d0,0x0202050001000310\n"
".quad 0x3f940904004780d0,0x0084090000003f20,0x20800d0000000330,0x0305fd0000000310\n"
".quad 0x4cf0036c0187c830,0x4cf00300000000a0,0x00800d0000010010,0x0300010000000310\n"
".quad 0x0000016c01478030,0x000c192c014780a0,0x00020104004780d0,0x0080050403c78010\n"
".quad 0x2084090000000310,0x0000010fffffff20,0x00800de0000002f0,0x0305fd0000000310\n"
".quad 0x20840d6c0147c830,0x0302150000000330,0x020011c400068030,0x03000de400068030\n"
".quad 0x050801c400068030,0x00801104004680d0,0x04060d0000000310,0x00060d6c01468030\n"
".quad 0x030c192c014680a0,0x02020504004680d0,0x018009e400068030,0x02000d0000000310\n"
".quad 0x01000104000780d0,0x1f0211e410078030,0x040001c410078030,0x02000904004780d0\n"
".quad 0x020c0904000780d0,0x02060904004780d0,0x01020504000780d0,0x00800de410078030\n"
".quad 0x0305fd0000000310,0x4f00036c0147c830,0x4f000300000000a0,0x0180010000010010\n"
".quad 0x0080090000000320,0x0201fd0000000310,0x4ef0036c0087c830,0x4ef00300000000a0\n"
".quad 0x0182050000010010,0x0000010000000320,0x0b0205e0000002f0,0x00000104004782d0\n"
".quad 0x000001e0000002f0,0x000001e0000002f0,0x000003e0000002f0,0x0000010000078030\n"
".quad 0x008009e0000000f0,0x02020907ff000310,0x14043504000780d0,0x3d8009e410078030\n"
".quad 0x3f9a250000007f10,0x0213fd0fffffff20,0x58b0036400c7c830,0x00000900000000a0\n"
".quad 0x00020d0603c78010,0x0002210403c78010,0x5240030603c78010,0x00f8110000028010\n"
".quad 0x0080150403c78010,0x00041907ff000310,0x0609fdc4504780a0,0x00f811e00187c8e0\n"
".quad 0x0080150603c78010,0x50b00307ff000310,0x0080050000028010,0x0110050000800310\n"
".quad 0x58b00304004780d0,0x0609fd0000078010,0x511003e00087c8e0,0x0080010000010010\n"
".quad 0x0010050800000310,0x00f80104000780d0,0x58b0030403c78010,0x00f8110000078010\n"
".quad 0x00f8150603c78010,0x0405fd0403c78010,0x51b003e00087c8e0,0x0080010000010010\n"
".quad 0x0010010800000310,0x00800504000780d0,0x01000507ff000310,0x00f80104004780d0\n"
".quad 0x58b0030603c78010,0x7c13fd0000078010,0x5220036c0187c830,0x0080010000028010\n"
".quad 0x0080050000000310,0x0004010435000310,0x36803980000780e0,0x5250030000000310\n"
".quad 0x00f8390000078010,0x5250030403c78010,0x00f8390000078010,0x019a090603c78010\n"
".quad 0x1404090fffffc320,0x400205c410078030,0x0000090400878020,0x000419c0464780a0\n"
".quad 0x0080090000078090,0x00800d0000000310,0x00001103ff000310,0x000c01e4404780a0\n"
".quad 0x000819c4400780a0,0x000c2940008780e0,0x060c2140000780e0,0x0a102980000780e0\n"
".quad 0x0a082140028780e0,0x08142140008780e0,0x0a0c0140028780e0,0x00081140000780e0\n"
".quad 0x00801940008780e0,0x08080907ff000310,0x06061940000780e0,0x140c1904000780d0\n"
".quad 0x001a1de410078030,0x000e2d0401878030,0x3d80290403878020,0x3e961d0000007f10\n"
".quad 0x0a0ffd0000003f20,0x58a003640107c830,0x54700300000000a0,0x4016010000028010\n"
".quad 0x3f80010401878020,0x1400010000003f20,0x000605c410078030,0x0004010400078020\n"
".quad 0x58a0030403c78010,0x3f80090000078010,0x0217fd0000003f10,0x5500036c00c7c830\n"
".quad 0x0080010000028010,0x0006010800000310,0x00800504000780d0,0x01000507ff000310\n"
".quad 0x00f80104004780d0,0x58a0030603c78010,0x0c80090000078010,0x0080190fffffbf10\n"
".quad 0x0217fd0800000310,0x0606296c0187c830,0x55800304000780d0,0x00f8010000028010\n"
".quad 0x0014050403c78010,0x58a0030603c78010,0x0808090000078010,0x08081940400780e0\n"
".quad 0x08080140800780e0,0x3f801140c00780e0,0x0402150000ffff10,0x01960504000780d0\n"
".quad 0x0080210fffffc330,0x1f80110001000310,0x06040d0000000310,0x080a09e0014780e0\n"
".quad 0x0403fd04004780d0,0x56c0036c00c7c830,0x00061100000000a0,0x56c0032c014780a0\n"
".quad 0x7c00010000028010,0x0000016c01478030,0x0008112c014780a0,0x20820504004780d0\n"
".quad 0x0004010fffffff20,0x00f8090403c78010,0x7c03fd0603c78010,0x5780036c0087ca30\n"
".quad 0x57800300000000a0,0x20820d0000028010,0x0300150000000330,0x7c0a15c400078030\n"
".quad 0x0304196c01478030,0x010001c400078030,0x000a0de400078030,0x0104092c014780a0\n"
".quad 0x060001e400078030,0x03081104004780d0,0x01000504004780d0,0x1f040de410078230\n"
".quad 0x03020dc410078030,0x01800504004780d0,0x0106150000000310,0x01000104000780d0\n"
".quad 0x05080504000780d0,0x0101fd04004780d0,0x588003040007c8d0,0x01040100000000a0\n"
".quad 0x588003e410078030,0x0180050000010010,0x00060d0000000310,0x018005040047c020\n"
".quad 0x0000050000000320,0x0002010403c68010,0x0014050603c78010,0x00060104004782d0\n"
".quad 0x0000010403c78010,0x000001e0000002f0,0x000003e0000002f0,0x0000010000078030\n"
".quad 0x0fffffe0000001f0,0xf00000800fffff00,0xfffc013ff6a09e3f,0x50000000000000ff\n"
".quad 0xf00000fffffbcb43,0x00000000000001ff,0x0c0b04fff8000000,0x0000080000000000\n"
".quad 0x080d040000001000,0x000020002e017000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000010000000000\n"
".quad 0x0000000000001d00,0x0000000500000006,0x0000000000014ec8,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000268,0x0000000000000268,0x0000000000000004\n"
".quad 0x00001c0560000000,0x0000000000000d09,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000424,0x0000000000000424,0x0000000000000004,0x00001c0660000000\n"
".quad 0x000000000000112d,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000024,0x0000000000000004,0x00001b0560000000,0x000000000000112d\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000000000009b0,0x00000000000009b0\n"
".quad 0x0000000000000004,0x00001b0660000000,0x0000000000001add,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000001020,0x0000000000000004\n"
".quad 0x00001a0560000000,0x0000000000001add,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000718,0x0000000000000718,0x0000000000000004,0x00001a0660000000\n"
".quad 0x00000000000021f5,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000001020,0x0000000000000004,0x0000190560000000,0x00000000000021f5\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000002cbc,0x0000000000002cbc\n"
".quad 0x0000000000000004,0x0000190660000000,0x0000000000004eb1,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000024,0x0000000000000004\n"
".quad 0x0000000500000001,0x0000000000004eb1,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000010014,0x0000000000010014,0x0000000000000004,0x0000000600000001\n"
".quad 0x0000000000014ec5,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000008000,0x0000000000000004,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_13$[10791];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_13$:\n"
".quad 0x6f69737265762e09,0x2e090a342e31206e,0x7320746567726174,0x2f2f090a33315f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220312e33206363\n"
".quad 0x206e6f20746c6975,0x2d34302d30313032,0x2d2f2f090a0a3732,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f\n"
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f3165633730,0x372d303030303030\n"
".quad 0x614365746e6f4d5f,0x33314d535f6f6c72,0x20692e337070632e,0x63632f706d742f28\n"
".quad 0x3946594a2e234942,0x2d2f2f090a294544,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2f2f090a0a2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x4f202f2f090a2d2d,0x0a3a736e6f697470,0x2d2d2d2d2d2f2f09\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x090a2d2d2d2d2d2d,0x6772615420202f2f\n"
".quad 0x202c7874703a7465,0x315f6d733a415349,0x6169646e45202c33,0x656c7474696c3a6e\n"
".quad 0x65746e696f50202c,0x363a657a69532072,0x2d20202f2f090a34,0x6974704f2809334f\n"
".quad 0x6e6f6974617a696d,0x0a296c6576656c20,0x30672d20202f2f09,0x2067756265442809\n"
".quad 0x090a296c6576656c,0x09326d2d20202f2f,0x2074726f70655228,0x69726f7369766461\n"
".quad 0x2d2f2f090a297365,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x69662e090a0a2d2d,0x633c22093109656c,0x6c2d646e616d6d6f,0x2e090a223e656e69\n"
".quad 0x22093209656c6966,0x706d742f706d742f,0x303030305f746678,0x3030305f31656337\n"
".quad 0x5f362d3030303030,0x72614365746e6f4d,0x2e33314d535f6f6c,0x2e32656661647563\n"
".quad 0x662e090a22757067,0x4d22093309656c69,0x6c72614365746e6f,0x6c656e72656b5f6f\n"
".quad 0x2e090a226875632e,0x22093409656c6966,0x62696c2f7273752f,0x3638782f6363672f\n"
".quad 0x756e696c2d34365f,0x2e342f756e672d78,0x6c636e692f312e34,0x646474732f656475\n"
".quad 0x2e090a22682e6665,0x22093509656c6966,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x632f6564756c636e,0x63697665642f7472,0x6d69746e75725f65\n"
".quad 0x662e090a22682e65,0x2f22093609656c69,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x6f682f6564756c63,0x6e696665645f7473,0x2e090a22682e7365\n"
".quad 0x22093709656c6966,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x622f6564756c636e,0x745f6e69746c6975,0x0a22682e73657079,0x3809656c69662e09\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x5f6563697665642f,0x22682e7365707974,0x09656c69662e090a,0x2f7273752f220939\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x7265766972642f65\n"
".quad 0x682e73657079745f,0x656c69662e090a22,0x73752f2209303109,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x667275732f656475,0x657079745f656361\n"
".quad 0x662e090a22682e73,0x2209313109656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x742f6564756c636e,0x745f657275747865,0x0a22682e73657079\n"
".quad 0x3109656c69662e09,0x2f7273752f220932,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x726f746365762f65,0x682e73657079745f,0x656c69662e090a22\n"
".quad 0x73752f2209333109,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x697665642f656475,0x636e75616c5f6563,0x656d617261705f68,0x0a22682e73726574\n"
".quad 0x3109656c69662e09,0x2f7273752f220934,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x74732f7472632f65,0x6c635f656761726f,0x090a22682e737361\n"
".quad 0x353109656c69662e,0x692f7273752f2209,0x622f6564756c636e,0x657079742f737469\n"
".quad 0x662e090a22682e73,0x2209363109656c69,0x636e692f7273752f,0x6d69742f6564756c\n"
".quad 0x662e090a22682e65,0x2209373109656c69,0x657079746c616572,0x69662e090a22682e\n"
".quad 0x4d2209383109656c,0x6c72614365746e6f,0x7463756465725f6f,0x226875632e6e6f69\n"
".quad 0x09656c69662e090a,0x7361757122093931,0x476d6f646e617269,0x726f746172656e65\n"
".quad 0x2e6c656e72656b5f,0x662e090a22687563,0x2209303209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x632f6564756c636e,0x75665f6e6f6d6d6f\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220931320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x74616d2f6564756c,0x6974636e75665f68\n"
".quad 0x090a22682e736e6f,0x323209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x6f635f6874616d2f,0x2e73746e6174736e\n"
".quad 0x6c69662e090a2268,0x752f220933320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x7665642f6564756c,0x636e75665f656369,0x22682e736e6f6974\n"
".quad 0x09656c69662e090a,0x7273752f22093432,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x31315f6d732f6564,0x5f63696d6f74615f,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209353209656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x732f6564756c636e,0x6f74615f32315f6d,0x636e75665f63696d\n"
".quad 0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093632,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x33315f6d732f6564,0x5f656c62756f645f\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209373209656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x732f6564756c636e,0x6f74615f30325f6d\n"
".quad 0x636e75665f63696d,0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093832\n"
".quad 0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e,0x30325f6d732f6564\n"
".quad 0x736e6972746e695f,0x090a22682e736369,0x393209656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x656361667275732f\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09303309656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x5f65727574786574\n"
".quad 0x75665f6863746566,0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220931330965\n"
".quad 0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e,0x74616d2f6564756c\n"
".quad 0x6974636e75665f68,0x5f6c62645f736e6f,0x0a22682e33787470,0x74736e6f632e090a\n"
".quad 0x206e67696c612e20,0x5f642038622e2038,0x61446e6f6974704f,0x36333535365b6174\n"
".quad 0x6f6c672e090a3b5d,0x696c612e206c6162,0x38622e2038206e67,0x566c6c61435f6420\n"
".quad 0x3732335b65756c61,0x2e090a0a3b5d3836,0x5a5f207972746e65,0x4365746e6f4d3631\n"
".quad 0x6e72654b6f6c7261,0x545f5f3431506c65,0x61566e6f6974704f,0x282069665065756c\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x6f4d36315a5f5f6d\n"
".quad 0x6f6c72614365746e,0x31506c656e72654b,0x6974704f545f5f34,0x5065756c61566e6f\n"
".quad 0x6675425f645f6966,0x2e09090a2c726566,0x752e206d61726170,0x6475635f5f203436\n"
".quad 0x5a5f5f6d72617061,0x4365746e6f4d3631,0x6e72654b6f6c7261,0x545f5f3431506c65\n"
".quad 0x61566e6f6974704f,0x645f69665065756c,0x73656c706d61535f,0x7261702e09090a2c\n"
".quad 0x203233732e206d61,0x6170616475635f5f,0x4d36315a5f5f6d72,0x6c72614365746e6f\n"
".quad 0x506c656e72654b6f,0x74704f545f5f3431,0x65756c61566e6f69,0x687461705f696650\n"
".quad 0x2e090a7b090a294e,0x3631752e20676572,0x3b3e353c68722520,0x2e206765722e090a\n"
".quad 0x333c722520323375,0x65722e090a3b3e30,0x25203436752e2067,0x0a3b3e36313c6472\n"
".quad 0x662e206765722e09,0x3e333c6625203233,0x206765722e090a3b,0x646625203436662e\n"
".quad 0x2e090a3b3e34353c,0x6572702e20676572,0x3b3e383c70252064,0x3309636f6c2e090a\n"
".quad 0x240a300932313109,0x315a5f5f3142424c,0x614365746e6f4d36,0x656e72654b6f6c72\n"
".quad 0x4f545f5f3431506c,0x6c61566e6f697470,0x090a3a6966506575,0x31093309636f6c2e\n"
".quad 0x6f6d090a30093932,0x2509203631752e76,0x746e25202c316872,0x6d090a3b782e6469\n"
".quad 0x09203631752e766f,0x6325202c32687225,0x0a3b782e64696174,0x6469772e6c756d09\n"
".quad 0x2509203631752e65,0x32687225202c3172,0x0a3b31687225202c,0x3233752e74766309\n"
".quad 0x722509203631752e,0x2e64697425202c32,0x2e646461090a3b78,0x3372250920323375\n"
".quad 0x25202c327225202c,0x766f6d090a3b3172,0x722509203233732e,0x0a3b337225202c34\n"
".quad 0x3233732e74766309,0x722509203631752e,0x6961746325202c35,0x6f6d090a3b792e64\n"
".quad 0x2509203631752e76,0x636e25202c336872,0x0a3b782e64696174,0x617261702e646c09\n"
".quad 0x2509203233732e6d,0x635f5f5b202c3672,0x5f6d726170616475,0x746e6f4d36315a5f\n"
".quad 0x654b6f6c72614365,0x5f3431506c656e72,0x6e6f6974704f545f,0x69665065756c6156\n"
".quad 0x3b5d4e687461705f,0x6c2e70746573090a,0x2509203233732e65,0x2c367225202c3170\n"
".quad 0x40090a3b33722520,0x2061726220317025,0x375f305f744c2409,0x756d090a3b323836\n"
".quad 0x752e656469772e6c,0x2c37722509203631,0x25202c3368722520,0x7663090a3b316872\n"
".quad 0x33752e3436732e74,0x2c31647225092032,0x6d090a3b37722520,0x2e656469772e6c75\n"
".quad 0x6472250920323375,0x202c377225202c32,0x702e646c090a3b34,0x3436752e6d617261\n"
".quad 0x202c336472250920,0x70616475635f5f5b,0x36315a5f5f6d7261,0x72614365746e6f4d\n"
".quad 0x6c656e72654b6f6c,0x704f545f5f343150,0x756c61566e6f6974,0x535f645f69665065\n"
".quad 0x3b5d73656c706d61,0x36732e747663090a,0x2509203233732e34,0x337225202c346472\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x25202c3564722509,0x090a3b34202c3372\n"
".quad 0x203436752e646461,0x25202c3664722509,0x647225202c336472,0x2e766f6d090a3b35\n"
".quad 0x6472250920343675,0x74704f5f64202c37,0x3b617461446e6f69,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x357225202c386472,0x772e6c756d090a3b,0x203233732e656469\n"
".quad 0x25202c3964722509,0x0a3b3233202c3572,0x3436752e64646109,0x2c30316472250920\n"
".quad 0x25202c3764722520,0x646c090a3b396472,0x662e74736e6f632e,0x3164662509203436\n"
".quad 0x30316472255b202c,0x6c090a3b5d36312b,0x2e74736e6f632e64,0x6466250920343666\n"
".quad 0x316472255b202c32,0x090a3b5d34322b30,0x74736e6f632e646c,0x662509203436662e\n"
".quad 0x6472255b202c3364,0x090a3b5d382b3031,0x74736e6f632e646c,0x662509203436662e\n"
".quad 0x6472255b202c3464,0x090a3b5d302b3031,0x203436662e766f6d,0x30202c3564662509\n"
".quad 0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30,0x3436662e766f6d09\n"
".quad 0x202c366466250920,0x3030303030306430,0x3030303030303030,0x30202f2f093b3030\n"
".quad 0x365f305f744c240a,0x2f2f200a3a363431,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x323120656e696c20,0x697473656e202c39,0x687470656420676e,0x747365202c31203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x3009303331093309,0x6f6c672e646c090a,0x203233662e6c6162,0x255b202c31662509\n"
".quad 0x0a3b5d302b366472,0x3436662e74766309,0x662509203233662e,0x3b316625202c3764\n"
".quad 0x3309636f6c2e090a,0x090a300931333109,0x662e6e722e64616d,0x3864662509203436\n"
".quad 0x202c32646625202c,0x6625202c37646625,0x766f6d090a3b3164,0x257b09203436622e\n"
".quad 0x2c7d3972252c3872,0x090a3b3864662520,0x203233732e766f6d,0x2d202c3031722509\n"
".quad 0x3735373834363031,0x746573090a3b3935,0x2e3233752e746c2e,0x3172250920323373\n"
".quad 0x202c397225202c31,0x6e090a3b30317225,0x09203233732e6765,0x7225202c32317225\n"
".quad 0x766f6d090a3b3131,0x722509203233752e,0x32383031202c3331,0x0a3b303934353335\n"
".quad 0x2e656c2e74657309,0x203233752e323375,0x25202c3431722509,0x33317225202c3972\n"
".quad 0x732e67656e090a3b,0x3531722509203233,0x0a3b34317225202c,0x203233622e726f09\n"
".quad 0x25202c3631722509,0x317225202c323172,0x2e766f6d090a3b35,0x3172250920323375\n"
".quad 0x73090a3b30202c37,0x732e71652e707465,0x2c32702509203233,0x25202c3631722520\n"
".quad 0x2540090a3b373172,0x0920617262203270,0x34365f305f744c24,0x3c2f2f200a3b3230\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39323120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3431365f305f744c,0x09636f6c2e090a36\n"
".quad 0x3009353037093133,0x36662e766f6d090a,0x2c39646625092034,0x3137666633643020\n"
".quad 0x3862323536373435,0x202f2f093b656632,0x090a373234342e31,0x203436662e6c756d\n"
".quad 0x202c303164662509,0x6625202c38646625,0x747663090a3b3964,0x3436662e696e722e\n"
".quad 0x662509203436662e,0x646625202c313164,0x747663090a3b3031,0x3233732e697a722e\n"
".quad 0x722509203436662e,0x31646625202c3831,0x2e766f6d090a3b31,0x3172250920323373\n"
".quad 0x3b38317225202c39,0x33752e766f6d090a,0x2c30327225092032,0x0a3b313230312d20\n"
".quad 0x74672e7074657309,0x702509203233732e,0x2c38317225202c33,0x090a3b3032722520\n"
".quad 0x6172622033702540,0x5f305f744c240920,0x2f200a3b30373137,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3932\n"
".quad 0x64656c6562616c20,0x365f305f744c2420,0x6f6c2e090a363431,0x3031370931330963\n"
".quad 0x2e646461090a3009,0x3172250920323373,0x2c38317225202c39,0x6f6d090a3b353520\n"
".quad 0x2509203233732e76,0x313031202c313272,0x3b34343130373036,0x6e752e617262090a\n"
".quad 0x305f744c24092069,0x240a3b343139365f,0x3731375f305f744c,0x6c3c2f2f200a3a30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363431365f305f74,0x33732e766f6d090a\n"
".quad 0x2c31327225092032,0x3134373337303120,0x744c240a3b343238,0x3a343139365f305f\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3932312065,0x6562616c20646165,0x5f744c242064656c,0x090a363431365f30\n"
".quad 0x09313309636f6c2e,0x6d090a3009353133,0x09203436662e766f,0x30202c3231646625\n"
".quad 0x3465323665666264,0x6539336166656632,0x302d202f2f093b66,0x0a3734313339362e\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x31646625202c3331,0x3231646625202c31\n"
".quad 0x0a3b38646625202c,0x3436662e766f6d09,0x2c34316466250920,0x6261376362643020\n"
".quad 0x3839336233653963,0x202f2f093b663330,0x35303931332e322d,0x616d090a37312d65\n"
".quad 0x3436662e6e722e64,0x2c35316466250920,0x202c313164662520,0x25202c3431646625\n"
".quad 0x6d090a3b33316466,0x09203436662e766f,0x30202c3631646625,0x3730663132653364\n"
".quad 0x6162383566636366,0x2e32202f2f093b64,0x302d653334383830,0x662e766f6d090a39\n"
".quad 0x3164662509203436,0x3565336430202c37,0x3661643138646661,0x2f093b6661623363\n"
".quad 0x363331352e32202f,0x6d090a38302d6536,0x36662e6e722e6461,0x3831646625092034\n"
".quad 0x2c3631646625202c,0x202c353164662520,0x090a3b3731646625,0x09313309636f6c2e\n"
".quad 0x6d090a3009363133,0x09203436662e766f,0x30202c3931646625,0x3565373239653364\n"
".quad 0x6530386630366635,0x2e32202f2f093b36,0x302d653537353537,0x722e64616d090a37\n"
".quad 0x2509203436662e6e,0x6625202c30326466,0x646625202c383164,0x31646625202c3531\n"
".quad 0x636f6c2e090a3b39,0x0937313309313309,0x662e766f6d090a30,0x3264662509203436\n"
".quad 0x6365336430202c31,0x3066386164643137,0x2f093b3636366432,0x373535372e32202f\n"
".quad 0x6d090a36302d6532,0x36662e6e722e6461,0x3232646625092034,0x2c3032646625202c\n"
".quad 0x202c353164662520,0x090a3b3132646625,0x09313309636f6c2e,0x6d090a3009383133\n"
".quad 0x09203436662e766f,0x30202c3332646625,0x6131306166653364,0x6534393862333130\n"
".quad 0x2e32202f2f093b30,0x302d653631303834,0x722e64616d090a35,0x2509203436662e6e\n"
".quad 0x6625202c34326466,0x646625202c323264,0x32646625202c3531,0x636f6c2e090a3b33\n"
".quad 0x0939313309313309,0x662e766f6d090a30,0x3264662509203436,0x3266336430202c35\n"
".quad 0x3364313061313061,0x2f093b3838376661,0x313030302e30202f,0x6d090a3331343839\n"
".quad 0x36662e6e722e6461,0x3632646625092034,0x2c3432646625202c,0x202c353164662520\n"
".quad 0x090a3b3532646625,0x09313309636f6c2e,0x6d090a3009303233,0x09203436662e766f\n"
".quad 0x30202c3732646625,0x3631633635663364,0x6531613363363163,0x2e30202f2f093b63\n"
".quad 0x3938383833313030,0x6e722e64616d090a,0x662509203436662e,0x646625202c383264\n"
".quad 0x31646625202c3632,0x3732646625202c35,0x09636f6c2e090a3b,0x3009313233093133\n"
".quad 0x36662e766f6d090a,0x3932646625092034,0x313866336430202c,0x3031313131313131\n"
".quad 0x2f2f093b31363139,0x33333830302e3020,0x64616d090a333333,0x203436662e6e722e\n"
".quad 0x202c303364662509,0x25202c3832646625,0x6625202c35316466,0x6c2e090a3b393264\n"
".quad 0x323309313309636f,0x766f6d090a300932,0x662509203436662e,0x336430202c313364\n"
".quad 0x3535353535356166,0x3b31633435353535,0x34302e30202f2f09,0x6d090a3736363631\n"
".quad 0x36662e6e722e6461,0x3233646625092034,0x2c3033646625202c,0x202c353164662520\n"
".quad 0x090a3b3133646625,0x09313309636f6c2e,0x6d090a3009333233,0x09203436662e766f\n"
".quad 0x30202c3333646625,0x3535353563663364,0x3635353535353535,0x2e30202f2f093b66\n"
".quad 0x090a373636363631,0x662e6e722e64616d,0x3364662509203436,0x3233646625202c34\n"
".quad 0x2c3531646625202c,0x0a3b333364662520,0x313309636f6c2e09,0x090a300934323309\n"
".quad 0x203436662e766f6d,0x202c353364662509,0x3030306566336430,0x3030303030303030\n"
".quad 0x30202f2f093b3030,0x2e64616d090a352e,0x09203436662e6e72,0x25202c3633646625\n"
".quad 0x6625202c34336466,0x646625202c353164,0x6f6c2e090a3b3533,0x3632330931330963\n"
".quad 0x2e6c756d090a3009,0x6466250920343666,0x31646625202c3733,0x3633646625202c35\n"
".quad 0x722e64616d090a3b,0x2509203436662e6e,0x6625202c38336466,0x646625202c373364\n"
".quad 0x31646625202c3531,0x636f6c2e090a3b35,0x0938323709313309,0x622e6c6873090a30\n"
".quad 0x3232722509203233,0x202c39317225202c,0x646461090a3b3032,0x722509203233732e\n"
".quad 0x32327225202c3332,0x343631373031202c,0x6d090a3b32373634,0x09203233732e766f\n"
".quad 0x3b30202c34327225,0x36622e766f6d090a,0x3933646625092034,0x2c343272257b202c\n"
".quad 0x090a3b7d33327225,0x662e6e722e64616d,0x3464662509203436,0x3833646625202c30\n"
".quad 0x2c3933646625202c,0x0a3b393364662520,0x3233732e766f6d09,0x202c353272250920\n"
".quad 0x2e766f6d090a3b30,0x6466250920343662,0x3272257b202c3134,0x3b7d313272252c35\n"
".quad 0x36662e6c756d090a,0x3234646625092034,0x2c3034646625202c,0x0a3b313464662520\n"
".quad 0x696e752e61726209,0x5f305f744c240920,0x744c240a3b383532,0x3a323034365f305f\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3932312065,0x6562616c20646165,0x5f744c242064656c,0x090a363431365f30\n"
".quad 0x09313309636f6c2e,0x6d090a3009323337,0x09203436662e766f,0x30202c3334646625\n"
".quad 0x3030303066663764,0x3030303030303030,0x6e69202f2f093b30,0x662e766f6d090a66\n"
".quad 0x3464662509203436,0x3030306430202c34,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x766f6d090a30202f,0x722509203233732e,0x090a3b30202c3632,0x2e65672e70746573\n"
".quad 0x3470250920323373,0x25202c397225202c,0x6573090a3b363272,0x09203436662e706c\n"
".quad 0x25202c3534646625,0x6625202c33346466,0x347025202c343464,0x662e646461090a3b\n"
".quad 0x3464662509203436,0x2c38646625202c36,0x090a3b3864662520,0x203436662e736261\n"
".quad 0x202c373464662509,0x6d090a3b38646625,0x09203436662e766f,0x30202c3834646625\n"
".quad 0x3030303066663764,0x3030303030303030,0x6e69202f2f093b30,0x2e70746573090a66\n"
".quad 0x09203436662e656c,0x646625202c357025,0x34646625202c3734,0x706c6573090a3b38\n"
".quad 0x662509203436662e,0x646625202c323464,0x34646625202c3534,0x0a3b357025202c36\n"
".quad 0x35325f305f744c24,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c39323120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363431365f305f74,0x3309636f6c2e090a,0x090a300932333109,0x203436662e6c756d\n"
".quad 0x202c393464662509,0x6625202c34646625,0x7573090a3b323464,0x2509203436662e62\n"
".quad 0x6625202c30356466,0x646625202c393464,0x2e766f6d090a3b33,0x6466250920343666\n"
".quad 0x30306430202c3135,0x3030303030303030,0x093b303030303030,0x616d090a30202f2f\n"
".quad 0x2509203436662e78,0x6625202c32356466,0x646625202c303564,0x646461090a3b3135\n"
".quad 0x662509203436662e,0x35646625202c3664,0x3b36646625202c32,0x3309636f6c2e090a\n"
".quad 0x090a300933333109,0x662e6e722e64616d,0x3564662509203436,0x2c3235646625202c\n"
".quad 0x202c323564662520,0x61090a3b35646625,0x09203233732e6464,0x347225202c347225\n"
".quad 0x090a3b377225202c,0x203436752e646461,0x25202c3664722509,0x647225202c326472\n"
".quad 0x636f6c2e090a3b36,0x3009393231093309,0x7261702e646c090a,0x09203233732e6d61\n"
".quad 0x5f5f5b202c367225,0x6d72617061647563,0x6e6f4d36315a5f5f,0x4b6f6c7261436574\n"
".quad 0x3431506c656e7265,0x6f6974704f545f5f,0x665065756c61566e,0x5d4e687461705f69\n"
".quad 0x09636f6c2e090a3b,0x0a30093333310933,0x746c2e7074657309,0x702509203233732e\n"
".quad 0x202c347225202c36,0x2540090a3b367225,0x0920617262203670,0x31365f305f744c24\n"
".quad 0x617262090a3b3634,0x4c240920696e752e,0x343336355f305f74,0x5f305f744c240a3b\n"
".quad 0x6d090a3a32383637,0x2e656469772e6c75,0x3772250920363175,0x202c33687225202c\n"
".quad 0x6d090a3b31687225,0x09203436662e766f,0x6430202c35646625,0x3030303030303030\n"
".quad 0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d,0x30202c3664662509\n"
".quad 0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30,0x36355f305f744c24\n"
".quad 0x6f6c2e090a3a3433,0x0935333109330963,0x61702e646c090a30,0x203436752e6d6172\n"
".quad 0x202c313164722509,0x70616475635f5f5b,0x36315a5f5f6d7261,0x72614365746e6f4d\n"
".quad 0x6c656e72654b6f6c,0x704f545f5f343150,0x756c61566e6f6974,0x425f645f69665065\n"
".quad 0x0a3b5d7265666675,0x2e6f6c2e6c756d09,0x3272250920323373,0x202c357225202c37\n"
".quad 0x6461090a3b377225,0x2509203233732e64,0x337225202c383272,0x0a3b37327225202c\n"
".quad 0x3436732e74766309,0x722509203233732e,0x327225202c323164,0x2e6c756d090a3b38\n"
".quad 0x3233732e65646977,0x2c33316472250920,0x31202c3832722520,0x2e646461090a3b36\n"
".quad 0x6472250920343675,0x31647225202c3431,0x3331647225202c31,0x6c672e7473090a3b\n"
".quad 0x3436662e6c61626f,0x34316472255b0920,0x646625202c5d302b,0x672e7473090a3b36\n"
".quad 0x36662e6c61626f6c,0x316472255b092034,0x6625202c5d382b34,0x6f6c2e090a3b3564\n"
".quad 0x0936333109330963,0x3b74697865090a30,0x646e6557444c240a,0x6e6f4d36315a5f5f\n"
".quad 0x4b6f6c7261436574,0x3431506c656e7265,0x6f6974704f545f5f,0x665065756c61566e\n"
".quad 0x2f2f207d090a3a69,0x6e6f4d36315a5f20,0x4b6f6c7261436574,0x3431506c656e7265\n"
".quad 0x6f6974704f545f5f,0x665065756c61566e,0x746e652e090a0a69,0x4d37325a5f207972\n"
".quad 0x6c72614365746e6f,0x636f6c42656e4f6f,0x6974704f7265506b,0x0a28206966506e6f\n"
".quad 0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563,0x6e6f4d37325a5f5f\n"
".quad 0x4f6f6c7261436574,0x506b636f6c42656e,0x6e6f6974704f7265,0x61535f645f696650\n"
".quad 0x090a2c73656c706d,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x746e6f4d37325a5f,0x6e4f6f6c72614365,0x65506b636f6c4265,0x506e6f6974704f72\n"
".quad 0x4e687461705f6966,0x722e090a7b090a29,0x203233752e206765,0x0a3b3e37353c7225\n"
".quad 0x752e206765722e09,0x333c647225203436,0x65722e090a3b3e33,0x25203233662e2067\n"
".quad 0x2e090a3b3e333c66,0x3436662e20676572,0x3430313c64662520,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x090a3b3e30323c70,0x206465726168732e,0x38206e67696c612e\n"
".quad 0x635f5f2038622e20,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3436325f7261765f\n"
".quad 0x5f735f34335f3430,0x6c6c6143326d7553,0x30325b3434333839,0x732e090a3b5d3834\n"
".quad 0x612e206465726168,0x2e2038206e67696c,0x6475635f5f203862,0x616475635f5f5f61\n"
".quad 0x765f6c61636f6c5f,0x33303436325f7261,0x75535f735f34335f,0x3030316c6c61436d\n"
".quad 0x383430325b323933,0x636f6c2e090a3b5d,0x3009393431093309,0x5f5f3142424c240a\n"
".quad 0x65746e6f4d37325a,0x656e4f6f6c726143,0x7265506b636f6c42,0x66506e6f6974704f\n"
".quad 0x636f6c2e090a3a69,0x3009343631093309,0x33732e747663090a,0x2509203631752e32\n"
".quad 0x64697425202c3172,0x766f6d090a3b782e,0x722509203233732e,0x0a3b317225202c32\n"
".quad 0x3233732e766f6d09,0x32202c3372250920,0x746573090a3b3535,0x3233732e656c2e70\n"
".quad 0x25202c3170250920,0x3b337225202c3172,0x203170252140090a,0x744c240920617262\n"
".quad 0x30333532325f315f,0x752e766f6d090a3b,0x3164722509203436,0x616475635f5f202c\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f34303436325f72,0x6d75535f735f3433\n"
".quad 0x3338396c6c614332,0x766f6d090a3b3434,0x722509203436752e,0x75635f5f202c3264\n"
".quad 0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x303436325f726176,0x535f735f34335f33\n"
".quad 0x30316c6c61436d75,0x6d090a3b32393330,0x09203436752e766f,0x5f64202c33647225\n"
".quad 0x61446e6f6974704f,0x747663090a3b6174,0x3631752e3233732e,0x25202c3472250920\n"
".quad 0x3b782e6469617463,0x36732e747663090a,0x2509203233732e34,0x347225202c346472\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x25202c3564722509,0x0a3b3233202c3472\n"
".quad 0x3436752e64646109,0x202c366472250920,0x7225202c33647225,0x2e646c090a3b3564\n"
".quad 0x36662e74736e6f63,0x2c31646625092034,0x312b366472255b20,0x2e646c090a3b5d36\n"
".quad 0x36662e74736e6f63,0x2c32646625092034,0x322b366472255b20,0x2e646c090a3b5d34\n"
".quad 0x36662e74736e6f63,0x2c33646625092034,0x382b366472255b20,0x632e646c090a3b5d\n"
".quad 0x3436662e74736e6f,0x202c346466250920,0x5d302b366472255b,0x732e747663090a3b\n"
".quad 0x09203233732e3436,0x7225202c37647225,0x2e766f6d090a3b31,0x6472250920343673\n"
".quad 0x3b37647225202c38,0x33752e747663090a,0x2509203631752e32,0x69746e25202c3572\n"
".quad 0x7663090a3b782e64,0x33752e3436732e74,0x2c39647225092032,0x6d090a3b35722520\n"
".quad 0x2e656469772e6c75,0x6472250920323373,0x2c317225202c3031,0x6c756d090a3b3820\n"
".quad 0x33752e656469772e,0x3131647225092032,0x38202c357225202c,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x3031647225202c32,0x0a3b32647225202c,0x3436752e64646109\n"
".quad 0x2c33316472250920,0x202c303164722520,0x6c090a3b31647225,0x2e6d617261702e64\n"
".quad 0x3672250920323373,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x4365746e6f4d3732\n"
".quad 0x42656e4f6f6c7261,0x4f7265506b636f6c,0x6966506e6f697470,0x3b5d4e687461705f\n"
".quad 0x325f315f744c240a,0x2f200a3a32343033,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3120656e696c2079,0x7473656e202c3436,0x7470656420676e69,0x7365202c31203a68\n"
".quad 0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f\n"
".quad 0x0936363109330963,0x732e766f6d090a30,0x2c37722509203233,0x2e090a3b32722520\n"
".quad 0x3631093309636f6c,0x2e646c090a300934,0x33732e6d61726170,0x202c367225092032\n"
".quad 0x70616475635f5f5b,0x37325a5f5f6d7261,0x72614365746e6f4d,0x6f6c42656e4f6f6c\n"
".quad 0x74704f7265506b63,0x705f6966506e6f69,0x090a3b5d4e687461,0x31093309636f6c2e\n"
".quad 0x6573090a30093636,0x33732e65672e7074,0x202c327025092032,0x367225202c327225\n"
".quad 0x2032702540090a3b,0x744c240920617262,0x30393431335f315f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c34363120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32343033325f315f,0x3309636f6c2e090a\n"
".quad 0x090a300934363109,0x6d617261702e646c,0x722509203233732e,0x75635f5f5b202c36\n"
".quad 0x5f5f6d7261706164,0x65746e6f4d37325a,0x656e4f6f6c726143,0x7265506b636f6c42\n"
".quad 0x66506e6f6974704f,0x5d4e687461705f69,0x09636f6c2e090a3b,0x0a30093636310933\n"
".quad 0x3233732e62757309,0x25202c3872250920,0x3b327225202c3672,0x33732e646461090a\n"
".quad 0x202c397225092032,0x353532202c387225,0x732e726873090a3b,0x3031722509203233\n"
".quad 0x33202c397225202c,0x2e766f6d090a3b31,0x3172250920323373,0x0a3b353532202c31\n"
".quad 0x3233622e646e6109,0x202c323172250920,0x7225202c30317225,0x646461090a3b3131\n"
".quad 0x722509203233732e,0x32317225202c3331,0x090a3b397225202c,0x203233732e726873\n"
".quad 0x25202c3431722509,0x0a3b38202c333172,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5b202c34316472,0x726170616475635f,0x6f4d37325a5f5f6d,0x6f6c72614365746e\n"
".quad 0x6b636f6c42656e4f,0x6f6974704f726550,0x535f645f6966506e,0x3b5d73656c706d61\n"
".quad 0x6f6c2e6c756d090a,0x722509203436752e,0x647225202c353164,0x61090a3b34202c38\n"
".quad 0x09203436752e6464,0x25202c3631647225,0x7225202c34316472,0x6f6d090a3b353164\n"
".quad 0x2509203436662e76,0x306430202c356466,0x3030303030303030,0x3b30303030303030\n"
".quad 0x6d090a30202f2f09,0x09203436662e766f,0x6430202c36646625,0x3030303030303030\n"
".quad 0x3030303030303030,0x200a30202f2f093b,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c343631,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x6d090a3234303332,0x09203233732e766f,0x7225202c35317225\n"
".quad 0x5f744c240a3b3431,0x3a30313833325f31,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x6e202c3636312065,0x6420676e69747365,0x2c32203a68747065\n"
".quad 0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e\n"
".quad 0x31093309636f6c2e,0x646c090a30093736,0x2e6c61626f6c672e,0x3166250920323366\n"
".quad 0x36316472255b202c,0x7663090a3b5d302b,0x33662e3436662e74,0x2c37646625092032\n"
".quad 0x2e090a3b31662520,0x3631093309636f6c,0x64616d090a300938,0x203436662e6e722e\n"
".quad 0x25202c3864662509,0x646625202c326466,0x3b31646625202c37,0x36622e766f6d090a\n"
".quad 0x363172257b092034,0x202c7d373172252c,0x6d090a3b38646625,0x09203233732e766f\n"
".quad 0x312d202c38317225,0x3537353738343630,0x2e746573090a3b39,0x732e3233752e746c\n"
".quad 0x3931722509203233,0x202c37317225202c,0x6e090a3b38317225,0x09203233732e6765\n"
".quad 0x7225202c30327225,0x766f6d090a3b3931,0x722509203233752e,0x32383031202c3132\n"
".quad 0x0a3b303934353335,0x2e656c2e74657309,0x203233752e323375,0x25202c3232722509\n"
".quad 0x327225202c373172,0x2e67656e090a3b31,0x3272250920323373,0x3b32327225202c33\n"
".quad 0x3233622e726f090a,0x202c343272250920,0x7225202c30327225,0x766f6d090a3b3332\n"
".quad 0x722509203233752e,0x090a3b30202c3532,0x2e71652e70746573,0x3370250920323373\n"
".quad 0x202c34327225202c,0x40090a3b35327225,0x2061726220337025,0x325f315f744c2409\n"
".quad 0x2f200a3b36363034,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3636,0x64656c6562616c20,0x325f315f744c2420\n"
".quad 0x6c2e090a30313833,0x303709313309636f,0x766f6d090a300935,0x662509203436662e\n"
".quad 0x66336430202c3964,0x3536373435313766,0x093b656632386232,0x3234342e31202f2f\n"
".quad 0x662e6c756d090a37,0x3164662509203436,0x2c38646625202c30,0x090a3b3964662520\n"
".quad 0x2e696e722e747663,0x203436662e343666,0x202c313164662509,0x090a3b3031646625\n"
".quad 0x2e697a722e747663,0x203436662e323373,0x25202c3632722509,0x6d090a3b31316466\n"
".quad 0x09203233732e766f,0x7225202c37327225,0x766f6d090a3b3632,0x722509203233752e\n"
".quad 0x3230312d202c3832,0x70746573090a3b31,0x203233732e74672e,0x7225202c34702509\n"
".quad 0x38327225202c3632,0x2034702540090a3b,0x744c240920617262,0x34333834325f315f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36363120656e,0x62616c2064616568,0x744c242064656c65,0x30313833325f315f\n"
".quad 0x3309636f6c2e090a,0x0a30093031370931,0x3233732e64646109,0x202c373272250920\n"
".quad 0x3535202c36327225,0x732e766f6d090a3b,0x3932722509203233,0x373036313031202c\n"
".quad 0x62090a3b34343130,0x0920696e752e6172,0x34325f315f744c24,0x744c240a3b383735\n"
".quad 0x34333834325f315f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36363120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313833325f315f,0x33732e766f6d090a,0x2c39327225092032,0x3134373337303120\n"
".quad 0x744c240a3b343238,0x38373534325f315f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36363120656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30313833325f315f,0x3309636f6c2e090a,0x0a30093531330931\n"
".quad 0x3436662e766f6d09,0x2c32316466250920,0x3236656662643020,0x3361666566323465\n"
".quad 0x202f2f093b666539,0x34313339362e302d,0x722e64616d090a37,0x2509203436662e6e\n"
".quad 0x6625202c33316466,0x646625202c313164,0x38646625202c3231,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x3763626430202c34,0x3362336539636261,0x2f093b6633303839\n"
".quad 0x3931332e322d202f,0x090a37312d653530,0x662e6e722e64616d,0x3164662509203436\n"
".quad 0x3131646625202c35,0x2c3431646625202c,0x0a3b333164662520,0x3436662e766f6d09\n"
".quad 0x2c36316466250920,0x6631326533643020,0x3835666363663730,0x202f2f093b646162\n"
".quad 0x6533343838302e32,0x766f6d090a39302d,0x662509203436662e,0x336430202c373164\n"
".quad 0x6431386466613565,0x3b66616233633661,0x31352e32202f2f09,0x0a38302d65363633\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x31646625202c3831,0x3531646625202c36\n"
".quad 0x3b3731646625202c,0x3309636f6c2e090a,0x0a30093631330931,0x3436662e766f6d09\n"
".quad 0x2c39316466250920,0x3732396533643020,0x3866303666353565,0x202f2f093b366530\n"
".quad 0x6535373535372e32,0x64616d090a37302d,0x203436662e6e722e,0x202c303264662509\n"
".quad 0x25202c3831646625,0x6625202c35316466,0x6c2e090a3b393164,0x313309313309636f\n"
".quad 0x766f6d090a300937,0x662509203436662e,0x336430202c313264,0x3861646431376365\n"
".quad 0x3b36363664323066,0x35372e32202f2f09,0x0a36302d65323735,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x32646625202c3232,0x3531646625202c30,0x3b3132646625202c\n"
".quad 0x3309636f6c2e090a,0x0a30093831330931,0x3436662e766f6d09,0x2c33326466250920\n"
".quad 0x3061666533643020,0x3938623331306131,0x202f2f093b306534,0x6536313038342e32\n"
".quad 0x64616d090a35302d,0x203436662e6e722e,0x202c343264662509,0x25202c3232646625\n"
".quad 0x6625202c35316466,0x6c2e090a3b333264,0x313309313309636f,0x766f6d090a300939\n"
".quad 0x662509203436662e,0x336430202c353264,0x3130613130613266,0x3b38383766613364\n"
".quad 0x30302e30202f2f09,0x0a33313438393130,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x32646625202c3632,0x3531646625202c34,0x3b3532646625202c,0x3309636f6c2e090a\n"
".quad 0x0a30093032330931,0x3436662e766f6d09,0x2c37326466250920,0x6336356633643020\n"
".quad 0x6133633631633631,0x202f2f093b636531,0x3838333130302e30,0x2e64616d090a3938\n"
".quad 0x09203436662e6e72,0x25202c3832646625,0x6625202c36326466,0x646625202c353164\n"
".quad 0x6f6c2e090a3b3732,0x3132330931330963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x66336430202c3932,0x3131313131313138,0x093b313631393031,0x3830302e30202f2f\n"
".quad 0x6d090a3333333333,0x36662e6e722e6461,0x3033646625092034,0x2c3832646625202c\n"
".quad 0x202c353164662520,0x090a3b3932646625,0x09313309636f6c2e,0x6d090a3009323233\n"
".quad 0x09203436662e766f,0x30202c3133646625,0x3535353561663364,0x6334353535353535\n"
".quad 0x2e30202f2f093b31,0x0a37363636313430,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x33646625202c3233,0x3531646625202c30,0x3b3133646625202c,0x3309636f6c2e090a\n"
".quad 0x0a30093332330931,0x3436662e766f6d09,0x2c33336466250920,0x3535636633643020\n"
".quad 0x3535353535353535,0x202f2f093b663635,0x3736363636312e30,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x646625202c343364,0x31646625202c3233,0x3333646625202c35\n"
".quad 0x09636f6c2e090a3b,0x3009343233093133,0x36662e766f6d090a,0x3533646625092034\n"
".quad 0x306566336430202c,0x3030303030303030,0x2f2f093b30303030,0x616d090a352e3020\n"
".quad 0x3436662e6e722e64,0x2c36336466250920,0x202c343364662520,0x25202c3531646625\n"
".quad 0x2e090a3b35336466,0x3309313309636f6c,0x756d090a30093632,0x2509203436662e6c\n"
".quad 0x6625202c37336466,0x646625202c353164,0x64616d090a3b3633,0x203436662e6e722e\n"
".quad 0x202c383364662509,0x25202c3733646625,0x6625202c35316466,0x6c2e090a3b353164\n"
".quad 0x323709313309636f,0x6c6873090a300938,0x722509203233622e,0x37327225202c3033\n"
".quad 0x61090a3b3032202c,0x09203233732e6464,0x7225202c31337225,0x31373031202c3033\n"
".quad 0x0a3b323736343436,0x3233732e766f6d09,0x202c323372250920,0x2e766f6d090a3b30\n"
".quad 0x6466250920343662,0x3372257b202c3933,0x3b7d313372252c32,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x646625202c303464,0x33646625202c3833,0x3933646625202c39\n"
".quad 0x732e766f6d090a3b,0x3333722509203233,0x6f6d090a3b30202c,0x2509203436622e76\n"
".quad 0x257b202c31346466,0x393272252c333372,0x2e6c756d090a3b7d,0x6466250920343666\n"
".quad 0x34646625202c3234,0x3134646625202c30,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x240a3b3835325f31,0x3034325f315f744c,0x3c2f2f200a3a3636,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36363120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3833325f315f744c,0x636f6c2e090a3031,0x0932333709313309\n"
".quad 0x662e766f6d090a30,0x3464662509203436,0x6666376430202c33,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x6d090a666e69202f,0x09203436662e766f,0x30202c3434646625\n"
".quad 0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30,0x3233732e766f6d09\n"
".quad 0x202c343372250920,0x70746573090a3b30,0x203233732e65672e,0x7225202c35702509\n"
".quad 0x34337225202c3731,0x2e706c6573090a3b,0x6466250920343666,0x34646625202c3534\n"
".quad 0x3434646625202c33,0x090a3b357025202c,0x203436662e646461,0x202c363464662509\n"
".quad 0x6625202c38646625,0x736261090a3b3864,0x662509203436662e,0x646625202c373464\n"
".quad 0x2e766f6d090a3b38,0x6466250920343666,0x66376430202c3834,0x3030303030303066\n"
".quad 0x093b303030303030,0x090a666e69202f2f,0x2e656c2e70746573,0x3670250920343666\n"
".quad 0x2c3734646625202c,0x0a3b383464662520,0x36662e706c657309,0x3234646625092034\n"
".quad 0x2c3534646625202c,0x202c363464662520,0x744c240a3b367025,0x0a3a3835325f315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36363120,0x6c6562616c206461,0x315f744c24206465,0x090a30313833325f\n"
".quad 0x31093309636f6c2e,0x756d090a30093936,0x2509203436662e6c,0x6625202c39346466\n"
".quad 0x34646625202c3464,0x2e627573090a3b32,0x6466250920343666,0x34646625202c3035\n"
".quad 0x3b33646625202c39,0x36662e766f6d090a,0x3135646625092034,0x303030306430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x2e78616d090a3020,0x6466250920343666\n"
".quad 0x35646625202c3235,0x3135646625202c30,0x662e646461090a3b,0x3664662509203436\n"
".quad 0x2c3235646625202c,0x090a3b3664662520,0x31093309636f6c2e,0x616d090a30093037\n"
".quad 0x3436662e6e722e64,0x202c356466250920,0x25202c3235646625,0x6625202c32356466\n"
".quad 0x646461090a3b3564,0x722509203233732e,0x202c377225202c37,0x6461090a3b363532\n"
".quad 0x2509203436752e64,0x7225202c36316472,0x323031202c363164,0x636f6c2e090a3b34\n"
".quad 0x3009343631093309,0x7261702e646c090a,0x09203233732e6d61,0x5f5f5b202c367225\n"
".quad 0x6d72617061647563,0x6e6f4d37325a5f5f,0x4f6f6c7261436574,0x506b636f6c42656e\n"
".quad 0x6e6f6974704f7265,0x687461705f696650,0x6f6c2e090a3b5d4e,0x0930373109330963\n"
".quad 0x2e70746573090a30,0x09203233732e746c,0x377225202c377025,0x090a3b367225202c\n"
".quad 0x6172622037702540,0x5f315f744c240920,0x200a3b3031383332,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c343631\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x62090a3234303332,0x0920696e752e6172\n"
".quad 0x33325f315f744c24,0x744c240a3b383932,0x30393431335f315f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c34363120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32343033325f315f,0x36662e766f6d090a\n"
".quad 0x2c35646625092034,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x662e766f6d090a30,0x3664662509203436,0x303030306430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x315f744c240a3020,0x0a3a38393233325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c34363120\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x090a32343033325f,0x31093309636f6c2e\n"
".quad 0x7473090a30093237,0x2e6465726168732e,0x72255b0920343666,0x202c5d302b323164\n"
".quad 0x2e090a3b36646625,0x3731093309636f6c,0x2e7473090a300933,0x662e646572616873\n"
".quad 0x6472255b09203436,0x25202c5d302b3331,0x6461090a3b356466,0x2509203233752e64\n"
".quad 0x2c327225202c3272,0x61090a3b35722520,0x09203436732e6464,0x7225202c38647225\n"
".quad 0x39647225202c3864,0x752e646461090a3b,0x3164722509203436,0x3131647225202c33\n"
".quad 0x3b3331647225202c,0x36752e646461090a,0x3231647225092034,0x2c3131647225202c\n"
".quad 0x0a3b323164722520,0x3233752e766f6d09,0x202c353372250920,0x6573090a3b353532\n"
".quad 0x33732e656c2e7074,0x202c387025092032,0x337225202c327225,0x38702540090a3b35\n"
".quad 0x4c24092061726220,0x343033325f315f74,0x315f744c240a3b32,0x0a3a30333532325f\n"
".quad 0x093309636f6c2e09,0x6d090a3009383731,0x09203436752e766f,0x5f5f202c31647225\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x36325f7261765f6c,0x735f34335f343034\n"
".quad 0x6c6143326d75535f,0x0a3b34343338396c,0x3436752e766f6d09,0x202c326472250920\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x34335f3330343632\n"
".quad 0x61436d75535f735f,0x3239333030316c6c,0x09636f6c2e090a3b,0x0a30093837093831\n"
".quad 0x3233732e766f6d09,0x202c363372250920,0x2140090a3b317225,0x2061726220317025\n"
".quad 0x325f315f744c2409,0x6d090a3b32303635,0x09203233732e766f,0x3135202c37337225\n"
".quad 0x2e627573090a3b31,0x3372250920323373,0x2c37337225202c38,0x73090a3b31722520\n"
".quad 0x09203233732e7268,0x7225202c39337225,0x0a3b3133202c3833,0x3233732e766f6d09\n"
".quad 0x202c303472250920,0x6e61090a3b353532,0x2509203233622e64,0x337225202c313472\n"
".quad 0x3b30347225202c39,0x33732e646461090a,0x2c32347225092032,0x25202c3134722520\n"
".quad 0x6873090a3b383372,0x2509203233732e72,0x347225202c333472,0x6d090a3b38202c32\n"
".quad 0x09203233732e766f,0x7225202c34347225,0x5f744c240a3b3334,0x3a34313136325f31\n"
".quad 0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62,0x656e202c38372065\n"
".quad 0x656420676e697473,0x202c31203a687470,0x6574616d69747365,0x7461726574692064\n"
".quad 0x6e75203a736e6f69,0x2e090a6e776f6e6b,0x3709383109636f6c,0x726162090a300939\n"
".quad 0x300920636e79732e,0x09636f6c2e090a3b,0x0a30093038093831,0x3233752e766f6d09\n"
".quad 0x202c353472250920,0x6573090a3b373231,0x33732e74672e7074,0x202c397025092032\n"
".quad 0x7225202c36337225,0x702540090a3b3534,0x2409206172622039,0x3336325f315f744c\n"
".quad 0x3c2f2f200a3b3037,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c383720656e696c,0x616c206461656820,0x4c242064656c6562,0x313136325f315f74\n"
".quad 0x09636f6c2e090a34,0x0a30093535093831,0x3436732e74766309,0x722509203233732e\n"
".quad 0x337225202c373164,0x2e6c756d090a3b36,0x3233732e65646977,0x2c38316472250920\n"
".quad 0x38202c3633722520,0x752e646461090a3b,0x3164722509203436,0x3831647225202c39\n"
".quad 0x0a3b32647225202c,0x726168732e646c09,0x09203436662e6465,0x5b202c3335646625\n"
".quad 0x5d302b3931647225,0x68732e646c090a3b,0x3436662e64657261,0x2c34356466250920\n"
".quad 0x2b39316472255b20,0x090a3b5d34323031,0x203436662e646461,0x202c353564662509\n"
".quad 0x25202c3335646625,0x73090a3b34356466,0x6465726168732e74,0x255b09203436662e\n"
".quad 0x2c5d302b39316472,0x0a3b353564662520,0x3436752e64646109,0x2c30326472250920\n"
".quad 0x202c383164722520,0x6c090a3b31647225,0x6465726168732e64,0x662509203436662e\n"
".quad 0x72255b202c363564,0x0a3b5d302b303264,0x726168732e646c09,0x09203436662e6465\n"
".quad 0x5b202c3735646625,0x30312b3032647225,0x6461090a3b5d3432,0x2509203436662e64\n"
".quad 0x6625202c38356466,0x646625202c363564,0x2e7473090a3b3735,0x662e646572616873\n"
".quad 0x6472255b09203436,0x25202c5d302b3032,0x4c240a3b38356466,0x373336325f315f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x202c383720656e69,0x62616c2064616568,0x744c242064656c65,0x34313136325f315f\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x203233752e766f6d,0x36202c3634722509\n"
".quad 0x70746573090a3b33,0x203233732e74672e,0x25202c3031702509,0x347225202c363372\n"
".quad 0x31702540090a3b36,0x2409206172622030,0x3836325f315f744c,0x3c2f2f200a3b3238\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c383720656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x313136325f315f74,0x09636f6c2e090a34\n"
".quad 0x0a30093635093831,0x3436732e74766309,0x722509203233732e,0x337225202c313264\n"
".quad 0x2e6c756d090a3b36,0x3233732e65646977,0x2c38316472250920,0x38202c3633722520\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x3831647225202c39,0x0a3b32647225202c\n"
".quad 0x726168732e646c09,0x09203436662e6465,0x5b202c3935646625,0x5d302b3931647225\n"
".quad 0x68732e646c090a3b,0x3436662e64657261,0x2c30366466250920,0x2b39316472255b20\n"
".quad 0x61090a3b5d323135,0x09203436662e6464,0x25202c3136646625,0x6625202c39356466\n"
".quad 0x7473090a3b303664,0x2e6465726168732e,0x72255b0920343666,0x202c5d302b393164\n"
".quad 0x090a3b3136646625,0x203436752e646461,0x202c303264722509,0x25202c3831647225\n"
".quad 0x646c090a3b316472,0x2e6465726168732e,0x6466250920343666,0x6472255b202c3236\n"
".quad 0x090a3b5d302b3032,0x65726168732e646c,0x2509203436662e64,0x255b202c33366466\n"
".quad 0x3231352b30326472,0x2e646461090a3b5d,0x6466250920343666,0x36646625202c3436\n"
".quad 0x3336646625202c32,0x68732e7473090a3b,0x3436662e64657261,0x30326472255b0920\n"
".quad 0x646625202c5d302b,0x5f744c240a3b3436,0x3a32383836325f31,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38372065\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x090a34313136325f,0x636e79732e726162\n"
".quad 0x6f6d090a3b300920,0x2509203233752e76,0x3b3133202c373472,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x337225202c313170,0x3b37347225202c36,0x203131702540090a\n"
".quad 0x744c240920617262,0x34393337325f315f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383720656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313136325f31,0x383109636f6c2e09,0x63090a3009383509\n"
".quad 0x732e3436732e7476,0x3264722509203233,0x3b36337225202c32,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x25202c3831647225,0x0a3b38202c363372,0x3436752e64646109\n"
".quad 0x2c39316472250920,0x202c383164722520,0x6c090a3b32647225,0x6465726168732e64\n"
".quad 0x662509203436662e,0x72255b202c353664,0x0a3b5d302b393164,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x5b202c3636646625,0x35322b3931647225,0x646461090a3b5d36\n"
".quad 0x662509203436662e,0x646625202c373664,0x36646625202c3536,0x732e7473090a3b36\n"
".quad 0x36662e6465726168,0x316472255b092034,0x6625202c5d302b39,0x6461090a3b373664\n"
".quad 0x2509203436752e64,0x7225202c30326472,0x647225202c383164,0x732e646c090a3b31\n"
".quad 0x36662e6465726168,0x3836646625092034,0x30326472255b202c,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x6466250920343666,0x6472255b202c3936,0x3b5d3635322b3032\n"
".quad 0x36662e646461090a,0x3037646625092034,0x2c3836646625202c,0x0a3b393664662520\n"
".quad 0x726168732e747309,0x09203436662e6465,0x302b30326472255b,0x3037646625202c5d\n"
".quad 0x5f315f744c240a3b,0x200a3a3439333732,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3837,0x64656c6562616c20\n"
".quad 0x325f315f744c2420,0x6162090a34313136,0x0920636e79732e72,0x2e766f6d090a3b30\n"
".quad 0x3472250920323375,0x090a3b3531202c38,0x2e74672e70746573,0x3170250920323373\n"
".quad 0x2c36337225202c32,0x090a3b3834722520,0x7262203231702540,0x315f744c24092061\n"
".quad 0x0a3b36303937325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x2e090a3431313632,0x3509383109636f6c,0x747663090a300939,0x3233732e3436732e\n"
".quad 0x2c33326472250920,0x090a3b3633722520,0x656469772e6c756d,0x722509203233732e\n"
".quad 0x337225202c383164,0x61090a3b38202c36,0x09203436752e6464,0x25202c3931647225\n"
".quad 0x7225202c38316472,0x2e646c090a3b3264,0x662e646572616873,0x3764662509203436\n"
".quad 0x316472255b202c31,0x6c090a3b5d302b39,0x6465726168732e64,0x662509203436662e\n"
".quad 0x72255b202c323764,0x5d3832312b393164,0x662e646461090a3b,0x3764662509203436\n"
".quad 0x3137646625202c33,0x3b3237646625202c,0x6168732e7473090a,0x203436662e646572\n"
".quad 0x2b39316472255b09,0x37646625202c5d30,0x2e646461090a3b33,0x6472250920343675\n"
".quad 0x31647225202c3032,0x3b31647225202c38,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c343764662509,0x302b30326472255b,0x732e646c090a3b5d,0x36662e6465726168\n"
".quad 0x3537646625092034,0x30326472255b202c,0x090a3b5d3832312b,0x203436662e646461\n"
".quad 0x202c363764662509,0x25202c3437646625,0x73090a3b35376466,0x6465726168732e74\n"
".quad 0x255b09203436662e,0x2c5d302b30326472,0x0a3b363764662520,0x37325f315f744c24\n"
".quad 0x2f2f200a3a363039,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x383720656e696c20,0x6c2064616568202c,0x242064656c656261,0x3136325f315f744c\n"
".quad 0x2e726162090a3431,0x3b300920636e7973,0x33752e766f6d090a,0x2c39347225092032\n"
".quad 0x746573090a3b3720,0x3233732e74672e70,0x202c333170250920,0x7225202c36337225\n"
".quad 0x702540090a3b3934,0x0920617262203331,0x38325f315f744c24,0x2f2f200a3b383134\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383720656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3136325f315f744c,0x636f6c2e090a3431\n"
".quad 0x3009303609383109,0x36732e747663090a,0x2509203233732e34,0x7225202c34326472\n"
".quad 0x6c756d090a3b3633,0x33732e656469772e,0x3831647225092032,0x202c36337225202c\n"
".quad 0x2e646461090a3b38,0x6472250920343675,0x31647225202c3931,0x3b32647225202c38\n"
".quad 0x6168732e646c090a,0x203436662e646572,0x202c373764662509,0x302b39316472255b\n"
".quad 0x732e646c090a3b5d,0x36662e6465726168,0x3837646625092034,0x39316472255b202c\n"
".quad 0x61090a3b5d34362b,0x09203436662e6464,0x25202c3937646625,0x6625202c37376466\n"
".quad 0x7473090a3b383764,0x2e6465726168732e,0x72255b0920343666,0x202c5d302b393164\n"
".quad 0x090a3b3937646625,0x203436752e646461,0x202c303264722509,0x25202c3831647225\n"
".quad 0x646c090a3b316472,0x2e6465726168732e,0x6466250920343666,0x6472255b202c3038\n"
".quad 0x090a3b5d302b3032,0x65726168732e646c,0x2509203436662e64,0x255b202c31386466\n"
".quad 0x5d34362b30326472,0x662e646461090a3b,0x3864662509203436,0x3038646625202c32\n"
".quad 0x3b3138646625202c,0x6168732e7473090a,0x203436662e646572,0x2b30326472255b09\n"
".quad 0x38646625202c5d30,0x315f744c240a3b32,0x0a3a38313438325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383720\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x62090a3431313632,0x20636e79732e7261\n"
".quad 0x766f6d090a3b3009,0x722509203233752e,0x090a3b33202c3035,0x2e74672e70746573\n"
".quad 0x3170250920323373,0x2c36337225202c34,0x090a3b3035722520,0x7262203431702540\n"
".quad 0x315f744c24092061,0x0a3b30333938325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x2e090a3431313632,0x3609383109636f6c,0x747663090a300931\n"
".quad 0x3233732e3436732e,0x2c35326472250920,0x090a3b3633722520,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x337225202c383164,0x61090a3b38202c36,0x09203436752e6464\n"
".quad 0x25202c3931647225,0x7225202c38316472,0x2e646c090a3b3264,0x662e646572616873\n"
".quad 0x3864662509203436,0x316472255b202c33,0x6c090a3b5d302b39,0x6465726168732e64\n"
".quad 0x662509203436662e,0x72255b202c343864,0x3b5d32332b393164,0x36662e646461090a\n"
".quad 0x3538646625092034,0x2c3338646625202c,0x0a3b343864662520,0x726168732e747309\n"
".quad 0x09203436662e6465,0x302b39316472255b,0x3538646625202c5d,0x752e646461090a3b\n"
".quad 0x3264722509203436,0x3831647225202c30,0x0a3b31647225202c,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x5b202c3638646625,0x5d302b3032647225,0x68732e646c090a3b\n"
".quad 0x3436662e64657261,0x2c37386466250920,0x2b30326472255b20,0x6461090a3b5d3233\n"
".quad 0x2509203436662e64,0x6625202c38386466,0x646625202c363864,0x2e7473090a3b3738\n"
".quad 0x662e646572616873,0x6472255b09203436,0x25202c5d302b3032,0x4c240a3b38386466\n"
".quad 0x333938325f315f74,0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313136325f315f,0x79732e726162090a,0x090a3b300920636e,0x203233752e766f6d\n"
".quad 0x31202c3135722509,0x2e70746573090a3b,0x09203233732e7467,0x7225202c35317025\n"
".quad 0x31357225202c3633,0x3531702540090a3b,0x4c24092061726220,0x343439325f315f74\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x202c383720656e69,0x62616c2064616568,0x744c242064656c65,0x34313136325f315f\n"
".quad 0x3109636f6c2e090a,0x090a300932360938,0x2e3436732e747663,0x6472250920323373\n"
".quad 0x36337225202c3632,0x772e6c756d090a3b,0x203233732e656469,0x202c383164722509\n"
".quad 0x3b38202c36337225,0x36752e646461090a,0x3931647225092034,0x2c3831647225202c\n"
".quad 0x090a3b3264722520,0x65726168732e646c,0x2509203436662e64,0x255b202c39386466\n"
".quad 0x3b5d302b39316472,0x6168732e646c090a,0x203436662e646572,0x202c303964662509\n"
".quad 0x312b39316472255b,0x646461090a3b5d36,0x662509203436662e,0x646625202c313964\n"
".quad 0x39646625202c3938,0x732e7473090a3b30,0x36662e6465726168,0x316472255b092034\n"
".quad 0x6625202c5d302b39,0x6461090a3b313964,0x2509203436752e64,0x7225202c30326472\n"
".quad 0x647225202c383164,0x732e646c090a3b31,0x36662e6465726168,0x3239646625092034\n"
".quad 0x30326472255b202c,0x646c090a3b5d302b,0x2e6465726168732e,0x6466250920343666\n"
".quad 0x6472255b202c3339,0x0a3b5d36312b3032,0x3436662e64646109,0x2c34396466250920\n"
".quad 0x202c323964662520,0x090a3b3339646625,0x65726168732e7473,0x5b09203436662e64\n"
".quad 0x5d302b3032647225,0x3b3439646625202c,0x325f315f744c240a,0x2f200a3a32343439\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3720656e696c2079\n"
".quad 0x2064616568202c38,0x2064656c6562616c,0x36325f315f744c24,0x726162090a343131\n"
".quad 0x300920636e79732e,0x752e766f6d090a3b,0x3235722509203233,0x6573090a3b30202c\n"
".quad 0x33732e74672e7074,0x2c36317025092032,0x25202c3633722520,0x2540090a3b323572\n"
".quad 0x2061726220363170,0x325f315f744c2409,0x2f200a3b34353939,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3720656e696c2079,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x36325f315f744c24,0x6f6c2e090a343131,0x0933360938310963\n"
".quad 0x732e747663090a30,0x09203233732e3436,0x25202c3732647225,0x756d090a3b363372\n"
".quad 0x732e656469772e6c,0x3164722509203233,0x2c36337225202c38,0x646461090a3b3820\n"
".quad 0x722509203436752e,0x647225202c393164,0x32647225202c3831,0x68732e646c090a3b\n"
".quad 0x3436662e64657261,0x2c35396466250920,0x2b39316472255b20,0x2e646c090a3b5d30\n"
".quad 0x662e646572616873,0x3964662509203436,0x316472255b202c36,0x61090a3b5d382b39\n"
".quad 0x09203436662e6464,0x25202c3739646625,0x6625202c35396466,0x7473090a3b363964\n"
".quad 0x2e6465726168732e,0x72255b0920343666,0x202c5d302b393164,0x090a3b3739646625\n"
".quad 0x203436752e646461,0x202c303264722509,0x25202c3831647225,0x646c090a3b316472\n"
".quad 0x2e6465726168732e,0x6466250920343666,0x6472255b202c3839,0x090a3b5d302b3032\n"
".quad 0x65726168732e646c,0x2509203436662e64,0x255b202c39396466,0x3b5d382b30326472\n"
".quad 0x36662e646461090a,0x3031646625092034,0x3839646625202c30,0x3b3939646625202c\n"
".quad 0x6168732e7473090a,0x203436662e646572,0x2b30326472255b09,0x31646625202c5d30\n"
".quad 0x5f744c240a3b3030,0x3a34353939325f31,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38372065,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x090a34313136325f,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x303809383109636f,0x2e646461090a3009,0x3372250920323373,0x2c36337225202c36\n"
".quad 0x6d090a3b36353220,0x09203233752e766f,0x3532202c33357225,0x70746573090a3b35\n"
".quad 0x203233732e656c2e,0x25202c3731702509,0x357225202c363372,0x31702540090a3b33\n"
".quad 0x2409206172622037,0x3136325f315f744c,0x5f744c240a3b3431,0x3a32303635325f31\n"
".quad 0x3309636f6c2e090a,0x090a300938373109,0x203233752e766f6d,0x30202c3435722509\n"
".quad 0x2e70746573090a3b,0x09203233752e656e,0x7225202c38317025,0x3b34357225202c31\n"
".quad 0x203831702540090a,0x744c240920617262,0x32323730335f315f,0x09636f6c2e090a3b\n"
".quad 0x0a30093138310933,0x3436752e766f6d09,0x2c38326472250920,0x566c6c61435f6420\n"
".quad 0x63090a3b65756c61,0x752e3233732e7476,0x3535722509203631,0x646961746325202c\n"
".quad 0x747663090a3b782e,0x3233732e3436732e,0x2c39326472250920,0x090a3b3535722520\n"
".quad 0x656469772e6c756d,0x722509203233732e,0x357225202c303364,0x090a3b3631202c35\n"
".quad 0x203436752e646461,0x202c313364722509,0x25202c3832647225,0x6c090a3b30336472\n"
".quad 0x6465726168732e64,0x662509203436662e,0x5f5b202c31303164,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f34335f33303436,0x6c61436d75535f73\n"
".quad 0x2b3239333030316c,0x2e7473090a3b5d30,0x662e6c61626f6c67,0x6472255b09203436\n"
".quad 0x25202c5d302b3133,0x090a3b3130316466,0x65726168732e646c,0x2509203436662e64\n"
".quad 0x5b202c3230316466,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x34335f3430343632,0x43326d75535f735f,0x34343338396c6c61,0x7473090a3b5d302b\n"
".quad 0x2e6c61626f6c672e,0x72255b0920343666,0x202c5d382b313364,0x0a3b323031646625\n"
".quad 0x30335f315f744c24,0x6c2e090a3a323237,0x333831093309636f,0x74697865090a3009\n"
".quad 0x6e6557444c240a3b,0x6f4d37325a5f5f64,0x6f6c72614365746e,0x6b636f6c42656e4f\n"
".quad 0x6f6974704f726550,0x7d090a3a6966506e,0x37325a5f202f2f20,0x72614365746e6f4d\n"
".quad 0x6f6c42656e4f6f6c,0x74704f7265506b63,0x0a0a6966506e6f69,0x207972746e652e09\n"
".quad 0x746e6f4d36315a5f,0x65526f6c72614365,0x5f34315065637564,0x6e6f6974704f545f\n"
".quad 0x28206965756c6156,0x617261702e09090a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x6f4d36315a5f5f6d,0x6f6c72614365746e,0x3150656375646552,0x6974704f545f5f34\n"
".quad 0x6965756c61566e6f,0x65666675425f645f,0x61702e09090a2c72,0x3233732e206d6172\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72614365746e6f4d,0x6563756465526f6c\n"
".quad 0x704f545f5f343150,0x756c61566e6f6974,0x6d756363615f6965,0x2e090a7b090a294e\n"
".quad 0x3233752e20676572,0x3b3e39333c722520,0x2e206765722e090a,0x3c64722520343675\n"
".quad 0x722e090a3b3e3233,0x203436662e206765,0x3b3e36353c646625,0x2e206765722e090a\n"
".quad 0x3c70252064657270,0x732e090a3b3e3631,0x612e206465726168,0x2e2038206e67696c\n"
".quad 0x6475635f5f203862,0x616475635f5f5f61,0x765f6c61636f6c5f,0x38343436325f7261\n"
".quad 0x75535f735f34335f,0x30316c6c6143326d,0x3430325b36353432,0x68732e090a3b5d38\n"
".quad 0x6c612e2064657261,0x622e2038206e6769,0x616475635f5f2038,0x5f616475635f5f5f\n"
".quad 0x61765f6c61636f6c,0x5f37343436325f72,0x6d75535f735f3433,0x353430316c6c6143\n"
".quad 0x5d383430325b3430,0x09636f6c2e090a3b,0x0a30093339310933,0x5a5f5f3142424c24\n"
".quad 0x4365746e6f4d3631,0x756465526f6c7261,0x545f5f3431506563,0x61566e6f6974704f\n"
".quad 0x2e090a3a6965756c,0x3032093309636f6c,0x747663090a300932,0x3631752e3233732e\n"
".quad 0x25202c3172250920,0x090a3b782e646974,0x203233732e766f6d,0x7225202c32722509\n"
".quad 0x2e766f6d090a3b31,0x3372250920323373,0x090a3b353532202c,0x2e656c2e70746573\n"
".quad 0x3170250920323373,0x25202c317225202c,0x252140090a3b3372,0x0920617262203170\n"
".quad 0x38315f325f744c24,0x6f6d090a3b383731,0x2509203436752e76,0x635f5f202c316472\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3436325f7261765f,0x5f735f34335f3834\n"
".quad 0x6c6c6143326d7553,0x0a3b363534323031,0x3436752e766f6d09,0x202c326472250920\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x34335f3734343632\n"
".quad 0x61436d75535f735f,0x3430353430316c6c,0x61702e646c090a3b,0x203233752e6d6172\n"
".quad 0x5f5b202c34722509,0x726170616475635f,0x6f4d36315a5f5f6d,0x6f6c72614365746e\n"
".quad 0x3150656375646552,0x6974704f545f5f34,0x6965756c61566e6f,0x5d4e6d756363615f\n"
".quad 0x61702e646c090a3b,0x203436752e6d6172,0x5b202c3364722509,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6c72614365746e6f,0x506563756465526f,0x74704f545f5f3431\n"
".quad 0x65756c61566e6f69,0x666675425f645f69,0x7663090a3b5d7265,0x31752e3233752e74\n"
".quad 0x202c357225092036,0x782e646961746325,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x2c357225202c3672,0x63090a3b34722520,0x752e3436752e7476,0x3464722509203233\n"
".quad 0x090a3b367225202c,0x656469772e6c756d,0x722509203233752e,0x2c367225202c3564\n"
".quad 0x6461090a3b363120,0x2509203436752e64,0x647225202c366472,0x3b35647225202c33\n"
".quad 0x36732e747663090a,0x2509203233732e34,0x317225202c376472,0x732e766f6d090a3b\n"
".quad 0x3864722509203436,0x0a3b37647225202c,0x3233752e74766309,0x722509203631752e\n"
".quad 0x6469746e25202c37,0x747663090a3b782e,0x3233752e3436732e,0x202c396472250920\n"
".quad 0x756d090a3b377225,0x732e656469772e6c,0x3164722509203233,0x202c317225202c30\n"
".quad 0x2e6c756d090a3b38,0x3233752e65646977,0x2c31316472250920,0x3b38202c37722520\n"
".quad 0x36752e646461090a,0x3231647225092034,0x2c3031647225202c,0x090a3b3264722520\n"
".quad 0x203436752e646461,0x202c333164722509,0x25202c3031647225,0x744c240a3b316472\n"
".quad 0x30393638315f325f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x202c32303220656e,0x20676e697473656e,0x31203a6874706564,0x616d69747365202c\n"
".quad 0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75,0x093309636f6c2e09\n"
".quad 0x6d090a3009343032,0x09203233732e766f,0x327225202c387225,0x09636f6c2e090a3b\n"
".quad 0x0a30093230320933,0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3472\n"
".quad 0x5f6d726170616475,0x746e6f4d36315a5f,0x65526f6c72614365,0x5f34315065637564\n"
".quad 0x6e6f6974704f545f,0x615f6965756c6156,0x0a3b5d4e6d756363,0x093309636f6c2e09\n"
".quad 0x73090a3009343032,0x732e65672e707465,0x2c32702509203233,0x7225202c32722520\n"
".quad 0x32702540090a3b34,0x4c24092061726220,0x313136325f325f74,0x6c3c2f2f200a3b34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c32303220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x393638315f325f74,0x09636f6c2e090a30\n"
".quad 0x0a30093230320933,0x617261702e646c09,0x2509203233752e6d,0x635f5f5b202c3472\n"
".quad 0x5f6d726170616475,0x746e6f4d36315a5f,0x65526f6c72614365,0x5f34315065637564\n"
".quad 0x6e6f6974704f545f,0x615f6965756c6156,0x0a3b5d4e6d756363,0x093309636f6c2e09\n"
".quad 0x73090a3009343032,0x09203233732e6275,0x347225202c397225,0x090a3b327225202c\n"
".quad 0x203233732e646461,0x25202c3031722509,0x3b353532202c3972,0x33732e726873090a\n"
".quad 0x2c31317225092032,0x33202c3031722520,0x2e766f6d090a3b31,0x3172250920323373\n"
".quad 0x0a3b353532202c32,0x3233622e646e6109,0x202c333172250920,0x7225202c31317225\n"
".quad 0x646461090a3b3231,0x722509203233732e,0x33317225202c3431,0x0a3b30317225202c\n"
".quad 0x3233732e72687309,0x202c353172250920,0x3b38202c34317225,0x6f6c2e6c756d090a\n"
".quad 0x722509203436752e,0x647225202c343164,0x090a3b3631202c38,0x203436732e646461\n"
".quad 0x202c353164722509,0x7225202c36647225,0x6f6d090a3b343164,0x2509203436662e76\n"
".quad 0x306430202c316466,0x3030303030303030,0x3b30303030303030,0x6d090a30202f2f09\n"
".quad 0x09203436662e766f,0x6430202c32646625,0x3030303030303030,0x3030303030303030\n"
".quad 0x200a30202f2f093b,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c323032,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x6d090a3039363831,0x09203233732e766f,0x7225202c36317225,0x5f744c240a3b3531\n"
".quad 0x3a38353439315f32,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70,0x6e696c2079646f62\n"
".quad 0x6e202c3430322065,0x6420676e69747365,0x2c32203a68747065,0x74616d6974736520\n"
".quad 0x6172657469206465,0x75203a736e6f6974,0x090a6e776f6e6b6e,0x32093309636f6c2e\n"
".quad 0x646c090a30093630,0x2e6c61626f6c672e,0x6466250920343666,0x316472255b202c33\n"
".quad 0x61090a3b5d302b35,0x09203436662e6464,0x6625202c32646625,0x32646625202c3364\n"
".quad 0x09636f6c2e090a3b,0x0a30093730320933,0x626f6c672e646c09,0x09203436662e6c61\n"
".quad 0x255b202c34646625,0x3b5d382b35316472,0x36662e646461090a,0x2c31646625092034\n"
".quad 0x25202c3464662520,0x6461090a3b316466,0x2509203233732e64,0x2c387225202c3872\n"
".quad 0x61090a3b36353220,0x09203436732e6464,0x25202c3531647225,0x3034202c35316472\n"
".quad 0x6f6c2e090a3b3639,0x0932303209330963,0x61702e646c090a30,0x203233752e6d6172\n"
".quad 0x5f5b202c34722509,0x726170616475635f,0x6f4d36315a5f5f6d,0x6f6c72614365746e\n"
".quad 0x3150656375646552,0x6974704f545f5f34,0x6965756c61566e6f,0x5d4e6d756363615f\n"
".quad 0x09636f6c2e090a3b,0x0a30093730320933,0x746c2e7074657309,0x702509203233732e\n"
".quad 0x202c387225202c33,0x2540090a3b347225,0x0920617262203370,0x39315f325f744c24\n"
".quad 0x2f2f200a3b383534,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x303220656e696c20,0x2064616568202c32,0x2064656c6562616c,0x38315f325f744c24\n"
".quad 0x617262090a303936,0x4c240920696e752e,0x343938315f325f74,0x325f744c240a3b36\n"
".quad 0x0a3a34313136325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c32303220,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a30393638315f,0x203436662e766f6d,0x30202c3164662509,0x3030303030303064\n"
".quad 0x3030303030303030,0x0a30202f2f093b30,0x3436662e766f6d09,0x202c326466250920\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x315f325f744c240a\n"
".quad 0x2f200a3a36343938,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3230,0x64656c6562616c20,0x315f325f744c2420\n"
".quad 0x6c2e090a30393638,0x393032093309636f,0x732e7473090a3009,0x36662e6465726168\n"
".quad 0x316472255b092034,0x6625202c5d302b32,0x6f6c2e090a3b3264,0x0930313209330963\n"
".quad 0x68732e7473090a30,0x3436662e64657261,0x33316472255b0920,0x646625202c5d302b\n"
".quad 0x2e646461090a3b31,0x3272250920323375,0x25202c327225202c,0x646461090a3b3772\n"
".quad 0x722509203436732e,0x38647225202c3864,0x0a3b39647225202c,0x3436752e64646109\n"
".quad 0x2c33316472250920,0x202c313164722520,0x090a3b3331647225,0x203436752e646461\n"
".quad 0x202c323164722509,0x25202c3131647225,0x6d090a3b32316472,0x09203233752e766f\n"
".quad 0x3532202c37317225,0x70746573090a3b35,0x203233732e656c2e,0x7225202c34702509\n"
".quad 0x3b37317225202c32,0x622034702540090a,0x5f744c2409206172,0x3b30393638315f32\n"
".quad 0x315f325f744c240a,0x2e090a3a38373138,0x3132093309636f6c,0x766f6d090a300935\n"
".quad 0x722509203436752e,0x75635f5f202c3164,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x343436325f726176,0x535f735f34335f38,0x316c6c6143326d75,0x090a3b3635343230\n"
".quad 0x203436752e766f6d,0x5f202c3264722509,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f34335f37343436,0x6c61436d75535f73,0x3b3430353430316c\n"
".quad 0x3109636f6c2e090a,0x090a300938370938,0x203233732e766f6d,0x25202c3831722509\n"
".quad 0x252140090a3b3172,0x0920617262203170,0x30325f325f744c24,0x6f6d090a3b363232\n"
".quad 0x2509203233732e76,0x313135202c393172,0x732e627573090a3b,0x3032722509203233\n"
".quad 0x202c39317225202c,0x6873090a3b317225,0x2509203233732e72,0x327225202c313272\n"
".quad 0x090a3b3133202c30,0x203233732e766f6d,0x32202c3232722509,0x646e61090a3b3535\n"
".quad 0x722509203233622e,0x31327225202c3332,0x0a3b32327225202c,0x3233732e64646109\n"
".quad 0x202c343272250920,0x7225202c33327225,0x726873090a3b3032,0x722509203233732e\n"
".quad 0x34327225202c3532,0x6f6d090a3b38202c,0x2509203233732e76,0x327225202c363272\n"
".quad 0x325f744c240a3b35,0x0a3a38333730325f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x73656e202c383720,0x70656420676e6974,0x65202c31203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f,0x6c2e090a6e776f6e\n"
".quad 0x393709383109636f,0x2e726162090a3009,0x3b300920636e7973,0x3109636f6c2e090a\n"
".quad 0x090a300930380938,0x203233752e766f6d,0x31202c3732722509,0x746573090a3b3732\n"
".quad 0x3233732e74672e70,0x25202c3570250920,0x327225202c383172,0x35702540090a3b37\n"
".quad 0x4c24092061726220,0x393930325f325f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333730325f325f,0x3109636f6c2e090a,0x090a300935350938\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x38317225202c3631,0x772e6c756d090a3b\n"
".quad 0x203233732e656469,0x202c373164722509,0x3b38202c38317225,0x36752e646461090a\n"
".quad 0x3831647225092034,0x2c3731647225202c,0x090a3b3264722520,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x72255b202c356466,0x0a3b5d302b383164,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x255b202c36646625,0x3230312b38316472,0x646461090a3b5d34\n"
".quad 0x662509203436662e,0x35646625202c3764,0x0a3b36646625202c,0x726168732e747309\n"
".quad 0x09203436662e6465,0x302b38316472255b,0x3b37646625202c5d,0x36752e646461090a\n"
".quad 0x3931647225092034,0x2c3731647225202c,0x090a3b3164722520,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x72255b202c386466,0x0a3b5d302b393164,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x255b202c39646625,0x3230312b39316472,0x646461090a3b5d34\n"
".quad 0x662509203436662e,0x646625202c303164,0x3b39646625202c38,0x6168732e7473090a\n"
".quad 0x203436662e646572,0x2b39316472255b09,0x31646625202c5d30,0x325f744c240a3b30\n"
".quad 0x0a3a34393930325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x62090a3833373032,0x20636e79732e7261,0x766f6d090a3b3009,0x722509203233752e\n"
".quad 0x0a3b3336202c3832,0x74672e7074657309,0x702509203233732e,0x2c38317225202c36\n"
".quad 0x090a3b3832722520,0x6172622036702540,0x5f325f744c240920,0x200a3b3630353132\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3837,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a38333730\n"
".quad 0x363509383109636f,0x2e747663090a3009,0x203233732e343673,0x202c303264722509\n"
".quad 0x6d090a3b38317225,0x2e656469772e6c75,0x6472250920323373,0x38317225202c3731\n"
".quad 0x6461090a3b38202c,0x2509203436752e64,0x7225202c38316472,0x647225202c373164\n"
".quad 0x732e646c090a3b32,0x36662e6465726168,0x3131646625092034,0x38316472255b202c\n"
".quad 0x646c090a3b5d302b,0x2e6465726168732e,0x6466250920343666,0x6472255b202c3231\n"
".quad 0x3b5d3231352b3831,0x36662e646461090a,0x3331646625092034,0x2c3131646625202c\n"
".quad 0x0a3b323164662520,0x726168732e747309,0x09203436662e6465,0x302b38316472255b\n"
".quad 0x3331646625202c5d,0x752e646461090a3b,0x3164722509203436,0x3731647225202c39\n"
".quad 0x0a3b31647225202c,0x726168732e646c09,0x09203436662e6465,0x5b202c3431646625\n"
".quad 0x5d302b3931647225,0x68732e646c090a3b,0x3436662e64657261,0x2c35316466250920\n"
".quad 0x2b39316472255b20,0x61090a3b5d323135,0x09203436662e6464,0x25202c3631646625\n"
".quad 0x6625202c34316466,0x7473090a3b353164,0x2e6465726168732e,0x72255b0920343666\n"
".quad 0x202c5d302b393164,0x240a3b3631646625,0x3531325f325f744c,0x3c2f2f200a3a3630\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c383720656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333730325f325f74,0x732e726162090a38\n"
".quad 0x0a3b300920636e79,0x3233752e766f6d09,0x202c393272250920,0x746573090a3b3133\n"
".quad 0x3233732e74672e70,0x25202c3770250920,0x327225202c383172,0x37702540090a3b39\n"
".quad 0x4c24092061726220,0x313032325f325f74,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333730325f325f,0x3109636f6c2e090a,0x090a300938350938\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x38317225202c3132,0x772e6c756d090a3b\n"
".quad 0x203233732e656469,0x202c373164722509,0x3b38202c38317225,0x36752e646461090a\n"
".quad 0x3831647225092034,0x2c3731647225202c,0x090a3b3264722520,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c37316466,0x3b5d302b38316472,0x6168732e646c090a\n"
".quad 0x203436662e646572,0x202c383164662509,0x322b38316472255b,0x6461090a3b5d3635\n"
".quad 0x2509203436662e64,0x6625202c39316466,0x646625202c373164,0x2e7473090a3b3831\n"
".quad 0x662e646572616873,0x6472255b09203436,0x25202c5d302b3831,0x61090a3b39316466\n"
".quad 0x09203436752e6464,0x25202c3931647225,0x7225202c37316472,0x2e646c090a3b3164\n"
".quad 0x662e646572616873,0x3264662509203436,0x316472255b202c30,0x6c090a3b5d302b39\n"
".quad 0x6465726168732e64,0x662509203436662e,0x72255b202c313264,0x5d3635322b393164\n"
".quad 0x662e646461090a3b,0x3264662509203436,0x3032646625202c32,0x3b3132646625202c\n"
".quad 0x6168732e7473090a,0x203436662e646572,0x2b39316472255b09,0x32646625202c5d30\n"
".quad 0x325f744c240a3b32,0x0a3a38313032325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064\n"
".quad 0x5f325f744c242064,0x62090a3833373032,0x20636e79732e7261,0x766f6d090a3b3009\n"
".quad 0x722509203233752e,0x0a3b3531202c3033,0x74672e7074657309,0x702509203233732e\n"
".quad 0x2c38317225202c38,0x090a3b3033722520,0x6172622038702540,0x5f325f744c240920\n"
".quad 0x200a3b3033353232,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3837,0x64656c6562616c20,0x325f325f744c2420\n"
".quad 0x6c2e090a38333730,0x393509383109636f,0x2e747663090a3009,0x203233732e343673\n"
".quad 0x202c323264722509,0x6d090a3b38317225,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x38317225202c3731,0x6461090a3b38202c,0x2509203436752e64,0x7225202c38316472\n"
".quad 0x647225202c373164,0x732e646c090a3b32,0x36662e6465726168,0x3332646625092034\n"
".quad 0x38316472255b202c,0x646c090a3b5d302b,0x2e6465726168732e,0x6466250920343666\n"
".quad 0x6472255b202c3432,0x3b5d3832312b3831,0x36662e646461090a,0x3532646625092034\n"
".quad 0x2c3332646625202c,0x0a3b343264662520,0x726168732e747309,0x09203436662e6465\n"
".quad 0x302b38316472255b,0x3532646625202c5d,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x3731647225202c39,0x0a3b31647225202c,0x726168732e646c09,0x09203436662e6465\n"
".quad 0x5b202c3632646625,0x5d302b3931647225,0x68732e646c090a3b,0x3436662e64657261\n"
".quad 0x2c37326466250920,0x2b39316472255b20,0x61090a3b5d383231,0x09203436662e6464\n"
".quad 0x25202c3832646625,0x6625202c36326466,0x7473090a3b373264,0x2e6465726168732e\n"
".quad 0x72255b0920343666,0x202c5d302b393164,0x240a3b3832646625,0x3532325f325f744c\n"
".quad 0x3c2f2f200a3a3033,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c383720656e696c,0x616c206461656820,0x4c242064656c6562,0x333730325f325f74\n"
".quad 0x732e726162090a38,0x0a3b300920636e79,0x3233752e766f6d09,0x202c313372250920\n"
".quad 0x70746573090a3b37,0x203233732e74672e,0x7225202c39702509,0x31337225202c3831\n"
".quad 0x2039702540090a3b,0x744c240920617262,0x32343033325f325f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383720656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38333730325f32,0x383109636f6c2e09\n"
".quad 0x63090a3009303609,0x732e3436732e7476,0x3264722509203233,0x3b38317225202c33\n"
".quad 0x69772e6c756d090a,0x09203233732e6564,0x25202c3731647225,0x0a3b38202c383172\n"
".quad 0x3436752e64646109,0x2c38316472250920,0x202c373164722520,0x6c090a3b32647225\n"
".quad 0x6465726168732e64,0x662509203436662e,0x72255b202c393264,0x0a3b5d302b383164\n"
".quad 0x726168732e646c09,0x09203436662e6465,0x5b202c3033646625,0x34362b3831647225\n"
".quad 0x2e646461090a3b5d,0x6466250920343666,0x32646625202c3133,0x3033646625202c39\n"
".quad 0x68732e7473090a3b,0x3436662e64657261,0x38316472255b0920,0x646625202c5d302b\n"
".quad 0x646461090a3b3133,0x722509203436752e,0x647225202c393164,0x31647225202c3731\n"
".quad 0x68732e646c090a3b,0x3436662e64657261,0x2c32336466250920,0x2b39316472255b20\n"
".quad 0x2e646c090a3b5d30,0x662e646572616873,0x3364662509203436,0x316472255b202c33\n"
".quad 0x090a3b5d34362b39,0x203436662e646461,0x202c343364662509,0x25202c3233646625\n"
".quad 0x73090a3b33336466,0x6465726168732e74,0x255b09203436662e,0x2c5d302b39316472\n"
".quad 0x0a3b343364662520,0x33325f325f744c24,0x2f2f200a3a323430,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x383720656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3730325f325f744c,0x2e726162090a3833,0x3b300920636e7973\n"
".quad 0x33752e766f6d090a,0x2c32337225092032,0x746573090a3b3320,0x3233732e74672e70\n"
".quad 0x202c303170250920,0x7225202c38317225,0x702540090a3b3233,0x0920617262203031\n"
".quad 0x33325f325f744c24,0x2f2f200a3b343535,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x383720656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3730325f325f744c,0x636f6c2e090a3833,0x3009313609383109,0x36732e747663090a\n"
".quad 0x2509203233732e34,0x7225202c34326472,0x6c756d090a3b3831,0x33732e656469772e\n"
".quad 0x3731647225092032,0x202c38317225202c,0x2e646461090a3b38,0x6472250920343675\n"
".quad 0x31647225202c3831,0x3b32647225202c37,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c353364662509,0x302b38316472255b,0x732e646c090a3b5d,0x36662e6465726168\n"
".quad 0x3633646625092034,0x38316472255b202c,0x61090a3b5d32332b,0x09203436662e6464\n"
".quad 0x25202c3733646625,0x6625202c35336466,0x7473090a3b363364,0x2e6465726168732e\n"
".quad 0x72255b0920343666,0x202c5d302b383164,0x090a3b3733646625,0x203436752e646461\n"
".quad 0x202c393164722509,0x25202c3731647225,0x646c090a3b316472,0x2e6465726168732e\n"
".quad 0x6466250920343666,0x6472255b202c3833,0x090a3b5d302b3931,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c39336466,0x5d32332b39316472,0x662e646461090a3b\n"
".quad 0x3464662509203436,0x3833646625202c30,0x3b3933646625202c,0x6168732e7473090a\n"
".quad 0x203436662e646572,0x2b39316472255b09,0x34646625202c5d30,0x325f744c240a3b30\n"
".quad 0x0a3a34353533325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x62090a3833373032,0x20636e79732e7261,0x766f6d090a3b3009,0x722509203233752e\n"
".quad 0x090a3b31202c3333,0x2e74672e70746573,0x3170250920323373,0x2c38317225202c31\n"
".quad 0x090a3b3333722520,0x7262203131702540,0x325f744c24092061,0x0a3b36363034325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c383720,0x656c6562616c2064,0x5f325f744c242064,0x2e090a3833373032\n"
".quad 0x3609383109636f6c,0x747663090a300932,0x3233732e3436732e,0x2c35326472250920\n"
".quad 0x090a3b3831722520,0x656469772e6c756d,0x722509203233732e,0x317225202c373164\n"
".quad 0x61090a3b38202c38,0x09203436752e6464,0x25202c3831647225,0x7225202c37316472\n"
".quad 0x2e646c090a3b3264,0x662e646572616873,0x3464662509203436,0x316472255b202c31\n"
".quad 0x6c090a3b5d302b38,0x6465726168732e64,0x662509203436662e,0x72255b202c323464\n"
".quad 0x3b5d36312b383164,0x36662e646461090a,0x3334646625092034,0x2c3134646625202c\n"
".quad 0x0a3b323464662520,0x726168732e747309,0x09203436662e6465,0x302b38316472255b\n"
".quad 0x3334646625202c5d,0x752e646461090a3b,0x3164722509203436,0x3731647225202c39\n"
".quad 0x0a3b31647225202c,0x726168732e646c09,0x09203436662e6465,0x5b202c3434646625\n"
".quad 0x5d302b3931647225,0x68732e646c090a3b,0x3436662e64657261,0x2c35346466250920\n"
".quad 0x2b39316472255b20,0x6461090a3b5d3631,0x2509203436662e64,0x6625202c36346466\n"
".quad 0x646625202c343464,0x2e7473090a3b3534,0x662e646572616873,0x6472255b09203436\n"
".quad 0x25202c5d302b3931,0x4c240a3b36346466,0x363034325f325f74,0x6c3c2f2f200a3a36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x38333730325f325f,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x203233752e766f6d,0x30202c3433722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x7225202c32317025,0x34337225202c3831,0x3231702540090a3b\n"
".quad 0x4c24092061726220,0x373534325f325f74,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333730325f325f,0x3109636f6c2e090a,0x090a300933360938\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x38317225202c3632,0x772e6c756d090a3b\n"
".quad 0x203233732e656469,0x202c373164722509,0x3b38202c38317225,0x36752e646461090a\n"
".quad 0x3831647225092034,0x2c3731647225202c,0x090a3b3264722520,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c37346466,0x3b5d302b38316472,0x6168732e646c090a\n"
".quad 0x203436662e646572,0x202c383464662509,0x382b38316472255b,0x2e646461090a3b5d\n"
".quad 0x6466250920343666,0x34646625202c3934,0x3834646625202c37,0x68732e7473090a3b\n"
".quad 0x3436662e64657261,0x38316472255b0920,0x646625202c5d302b,0x646461090a3b3934\n"
".quad 0x722509203436752e,0x647225202c393164,0x31647225202c3731,0x68732e646c090a3b\n"
".quad 0x3436662e64657261,0x2c30356466250920,0x2b39316472255b20,0x2e646c090a3b5d30\n"
".quad 0x662e646572616873,0x3564662509203436,0x316472255b202c31,0x61090a3b5d382b39\n"
".quad 0x09203436662e6464,0x25202c3235646625,0x6625202c30356466,0x7473090a3b313564\n"
".quad 0x2e6465726168732e,0x72255b0920343666,0x202c5d302b393164,0x240a3b3235646625\n"
".quad 0x3534325f325f744c,0x3c2f2f200a3a3837,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c383720656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333730325f325f74,0x732e726162090a38,0x0a3b300920636e79,0x383109636f6c2e09\n"
".quad 0x61090a3009303809,0x09203233732e6464,0x7225202c38317225,0x3b363532202c3831\n"
".quad 0x33752e766f6d090a,0x2c35337225092032,0x73090a3b35353220,0x732e656c2e707465\n"
".quad 0x3331702509203233,0x202c38317225202c,0x40090a3b35337225,0x6172622033317025\n"
".quad 0x5f325f744c240920,0x240a3b3833373032,0x3230325f325f744c,0x6f6c2e090a3a3632\n"
".quad 0x0935313209330963,0x752e766f6d090a30,0x3633722509203233,0x6573090a3b30202c\n"
".quad 0x33752e656e2e7074,0x2c34317025092032,0x7225202c31722520,0x702540090a3b3633\n"
".quad 0x0920617262203431,0x35325f325f744c24,0x6c2e090a3b363433,0x383132093309636f\n"
".quad 0x2e766f6d090a3009,0x6472250920343675,0x61435f64202c3732,0x3b65756c61566c6c\n"
".quad 0x33752e747663090a,0x2509203631752e32,0x746325202c373372,0x090a3b782e646961\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x37337225202c3832,0x772e6c756d090a3b\n"
".quad 0x203233752e656469,0x202c393264722509,0x3631202c37337225,0x752e646461090a3b\n"
".quad 0x3364722509203436,0x3732647225202c30,0x3b3932647225202c,0x6168732e646c090a\n"
".quad 0x203436662e646572,0x202c333564662509,0x5f616475635f5f5b,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f37343436325f,0x436d75535f735f34,0x30353430316c6c61\n"
".quad 0x73090a3b5d302b34,0x6c61626f6c672e74,0x255b09203436662e,0x2c5d302b30336472\n"
".quad 0x0a3b333564662520,0x726168732e646c09,0x09203436662e6465,0x5b202c3435646625\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x34335f3834343632\n"
".quad 0x43326d75535f735f,0x35343230316c6c61,0x73090a3b5d302b36,0x6c61626f6c672e74\n"
".quad 0x255b09203436662e,0x2c5d382b30336472,0x0a3b343564662520,0x35325f325f744c24\n"
".quad 0x6c2e090a3a363433,0x303232093309636f,0x74697865090a3009,0x6e6557444c240a3b\n"
".quad 0x6f4d36315a5f5f64,0x6f6c72614365746e,0x3150656375646552,0x6974704f545f5f34\n"
".quad 0x6965756c61566e6f,0x202f2f207d090a3a,0x746e6f4d36315a5f,0x65526f6c72614365\n"
".quad 0x5f34315065637564,0x6e6f6974704f545f,0x0a0a6965756c6156,0x207972746e652e09\n"
".quad 0x65766e6936315a5f,0x654b444e43657372,0x5f5366506c656e72,0x702e09090a28206a\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x315a5f5f6d726170,0x65737265766e6936\n"
".quad 0x656e72654b444e43,0x645f6a5f5366506c,0x2c74757074754f5f,0x617261702e09090a\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x6e6936315a5f5f6d,0x444e436573726576\n"
".quad 0x66506c656e72654b,0x6e495f645f6a5f53,0x2e09090a2c747570,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x737265766e693631,0x6e72654b444e4365\n"
".quad 0x5f6a5f5366506c65,0x090a294e68746170,0x206765722e090a7b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e353931,0x3436752e20676572,0x3e37313c64722520,0x206765722e090a3b\n"
".quad 0x3c6625203233662e,0x722e090a3b3e3431,0x203436662e206765,0x3e3934343c646625\n"
".quad 0x206765722e090a3b,0x702520646572702e,0x2e090a3b3e33363c,0x3209393109636f6c\n"
".quad 0x424c240a30093135,0x6936315a5f5f3142,0x4e4365737265766e,0x506c656e72654b44\n"
".quad 0x6c090a3a6a5f5366,0x2e6d617261702e64,0x3172250920323375,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x737265766e693631,0x6e72654b444e4365,0x5f6a5f5366506c65\n"
".quad 0x0a3b5d4e68746170,0x3233752e74766309,0x722509203631752e,0x2e64697425202c32\n"
".quad 0x2e747663090a3b78,0x203631752e323375,0x6325202c33722509,0x0a3b782e64696174\n"
".quad 0x3233752e74766309,0x722509203631752e,0x6469746e25202c34,0x2e646c090a3b782e\n"
".quad 0x36752e6d61726170,0x2c31647225092034,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x65737265766e6936,0x656e72654b444e43,0x645f6a5f5366506c,0x3b5d7475706e495f\n"
".quad 0x36752e766f6d090a,0x2c32647225092034,0x746573090a3b3020,0x3436752e71652e70\n"
".quad 0x25202c3170250920,0x647225202c316472,0x31702540090a3b32,0x4c24092061726220\n"
".quad 0x363036355f335f74,0x636f6c2e090a3b36,0x0939353209393109,0x34326c756d090a30\n"
".quad 0x203233752e6f6c2e,0x7225202c35722509,0x0a3b337225202c34,0x3233752e64646109\n"
".quad 0x25202c3672250920,0x3b327225202c3572,0x33732e766f6d090a,0x202c377225092032\n"
".quad 0x6c2e090a3b367225,0x353209393109636f,0x2e646c090a300931,0x33752e6d61726170\n"
".quad 0x202c317225092032,0x70616475635f5f5b,0x36315a5f5f6d7261,0x4365737265766e69\n"
".quad 0x6c656e72654b444e,0x61705f6a5f536650,0x2e090a3b5d4e6874,0x3209393109636f6c\n"
".quad 0x6573090a30093935,0x33752e65672e7074,0x202c327025092032,0x317225202c367225\n"
".quad 0x2032702540090a3b,0x744c240920617262,0x32323139365f335f,0x752e747663090a3b\n"
".quad 0x09203631752e3233,0x636e25202c387225,0x0a3b782e64696174,0x6c2e34326c756d09\n"
".quad 0x2509203233752e6f,0x2c347225202c3972,0x63090a3b38722520,0x752e3436752e7476\n"
".quad 0x3364722509203233,0x090a3b367225202c,0x2e3436732e747663,0x6472250920323375\n"
".quad 0x0a3b397225202c34,0x6469772e6c756d09,0x2509203233752e65,0x367225202c356472\n"
".quad 0x756d090a3b34202c,0x752e656469772e6c,0x3664722509203233,0x34202c397225202c\n"
".quad 0x09636f6c2e090a3b,0x3009313532093931,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c31647225,0x726170616475635f,0x6e6936315a5f5f6d,0x444e436573726576\n"
".quad 0x66506c656e72654b,0x6e495f645f6a5f53,0x2e090a3b5d747570,0x3209393109636f6c\n"
".quad 0x6461090a30093935,0x2509203436752e64,0x647225202c376472,0x3b31647225202c35\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x5f5b202c38647225,0x726170616475635f\n"
".quad 0x6e6936315a5f5f6d,0x444e436573726576,0x66506c656e72654b,0x754f5f645f6a5f53\n"
".quad 0x090a3b5d74757074,0x203436752e646461,0x25202c3964722509,0x647225202c386472\n"
".quad 0x335f744c240a3b35,0x0a3a34333836355f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x6c2e090a30363220,0x363209393109636f,0x2e646c090a300930\n"
".quad 0x662e6c61626f6c67,0x2c31662509203233,0x302b376472255b20,0x2e747663090a3b5d\n"
".quad 0x203233662e343666,0x25202c3164662509,0x6f6c2e090a3b3166,0x3136320939310963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x6666336430202c32,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x746573090a31202f,0x2e3233752e65672e,0x3172250920343666\n"
".quad 0x2c31646625202c30,0x090a3b3264662520,0x203233732e67656e,0x25202c3131722509\n"
".quad 0x6f6d090a3b303172,0x2509203436662e76,0x306430202c336466,0x3030303030303030\n"
".quad 0x3b30303030303030,0x73090a30202f2f09,0x33752e656c2e7465,0x2509203436662e32\n"
".quad 0x646625202c323172,0x3b33646625202c31,0x33732e67656e090a,0x2c33317225092032\n"
".quad 0x090a3b3231722520,0x09203233622e726f,0x7225202c34317225,0x33317225202c3131\n"
".quad 0x752e766f6d090a3b,0x3531722509203233,0x6573090a3b30202c,0x33732e71652e7074\n"
".quad 0x202c337025092032,0x7225202c34317225,0x702540090a3b3531,0x2409206172622033\n"
".quad 0x3037355f335f744c,0x3c2f2f200a3b3039,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x30363220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3836355f335f744c,0x2e766f6d090a3433,0x6466250920343666,0x6666666430202c34\n"
".quad 0x3030303030303038,0x2f093b3030303030,0x62090a6e616e202f,0x0920696e752e6172\n"
".quad 0x38325f335f744c24,0x5f744c240a3b3831,0x3a30393037355f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3036322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33,0x3436662e766f6d09\n"
".quad 0x202c356466250920,0x3030306566626430,0x3030303030303030,0x2d202f2f093b3030\n"
".quad 0x646461090a352e30,0x662509203436662e,0x31646625202c3664,0x0a3b35646625202c\n"
".quad 0x3436662e73626109,0x202c376466250920,0x6d090a3b36646625,0x09203436662e766f\n"
".quad 0x6430202c38646625,0x3734316561646633,0x3165613734316561,0x342e30202f2f093b\n"
".quad 0x2e70746573090a32,0x09203436662e746c,0x646625202c347025,0x3b38646625202c37\n"
".quad 0x203470252140090a,0x744c240920617262,0x38353837355f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333836355f335f,0x3109636f6c2e090a\n"
".quad 0x0a30093532310939,0x3436662e6c756d09,0x202c396466250920,0x6625202c36646625\n"
".quad 0x766f6d090a3b3664,0x662509203436662e,0x346430202c303164,0x3133396430343030\n"
".quad 0x3b64303236383262,0x30352e32202f2f09,0x766f6d090a333636,0x662509203436662e\n"
".quad 0x636430202c313164,0x6130376439323330,0x3b65643361343565,0x2e38312d202f2f09\n"
".quad 0x766f6d090a353136,0x662509203436662e,0x346430202c323164,0x6332313262343430\n"
".quad 0x3b63663663333734,0x332e3134202f2f09,0x766f6d090a323139,0x662509203436662e\n"
".quad 0x636430202c333164,0x3539653037393330,0x3b38373737373337,0x2e35322d202f2f09\n"
".quad 0x616d090a31313434,0x3436662e6e722e64,0x2c34316466250920,0x202c333164662520\n"
".quad 0x6625202c39646625,0x616d090a3b323164,0x3436662e6e722e64,0x2c35316466250920\n"
".quad 0x25202c3964662520,0x6625202c34316466,0x616d090a3b313164,0x3436662e6e722e64\n"
".quad 0x2c36316466250920,0x25202c3964662520,0x6625202c35316466,0x756d090a3b303164\n"
".quad 0x2509203436662e6c,0x6625202c37316466,0x31646625202c3664,0x2e766f6d090a3b36\n"
".quad 0x6466250920343666,0x66336430202c3831,0x3030303030303066,0x093b303030303030\n"
".quad 0x6f6d090a31202f2f,0x2509203436662e76,0x6430202c39316466,0x3037326630323063\n"
".quad 0x6432373035353630,0x2e382d202f2f093b,0x6d090a3135333734,0x09203436662e766f\n"
".quad 0x30202c3032646625,0x3535313733303464,0x3230353138313937,0x3332202f2f093b63\n"
".quad 0x6d090a343338302e,0x09203436662e766f,0x30202c3132646625,0x6566303533306364\n"
".quad 0x3735653130373066,0x322d202f2f093b64,0x090a323236302e31,0x203436662e766f6d\n"
".quad 0x202c323264662509,0x6230393030346430,0x6138353530323066,0x33202f2f093b3734\n"
".quad 0x090a33383033312e,0x662e6e722e64616d,0x3264662509203436,0x3232646625202c33\n"
".quad 0x202c39646625202c,0x090a3b3132646625,0x662e6e722e64616d,0x3264662509203436\n"
".quad 0x2c39646625202c34,0x202c333264662520,0x090a3b3032646625,0x662e6e722e64616d\n"
".quad 0x3264662509203436,0x2c39646625202c35,0x202c343264662520,0x090a3b3931646625\n"
".quad 0x662e6e722e64616d,0x3264662509203436,0x2c39646625202c36,0x202c353264662520\n"
".quad 0x090a3b3831646625,0x662e6e722e766964,0x3264662509203436,0x3731646625202c37\n"
".quad 0x3b3632646625202c,0x6e752e617262090a,0x335f744c24092069,0x0a3b32303637355f\n"
".quad 0x37355f335f744c24,0x2f2f200a3a383538,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x766f6d090a343338,0x662509203436662e,0x306430202c383264\n"
".quad 0x3030303030303030,0x3b30303030303030,0x73090a30202f2f09,0x662e74672e707465\n"
".quad 0x2c35702509203436,0x25202c3664662520,0x40090a3b38326466,0x6172622035702521\n"
".quad 0x5f335f744c240920,0x200a3b3037333835,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c303632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x2e090a3433383635,0x3409313309636f6c,0x6f6d090a30093239\n"
".quad 0x2509203436662e76,0x6430202c39326466,0x3030303030666633,0x3030303030303030\n"
".quad 0x090a31202f2f093b,0x203436662e627573,0x202c303364662509,0x25202c3932646625\n"
".quad 0x6f6d090a3b316466,0x7b09203436622e76,0x3172252c36317225,0x33646625202c7d37\n"
".quad 0x2e766f6d090a3b30,0x3172250920323373,0x3b37317225202c38,0x3309636f6c2e090a\n"
".quad 0x0a30093339340931,0x3436622e766f6d09,0x2c393172257b0920,0x25202c7d30327225\n"
".quad 0x2e090a3b30336466,0x3409313309636f6c,0x6f6d090a30093539,0x2509203436662e76\n"
".quad 0x6430202c31336466,0x3030303030303030,0x3030303030303030,0x090a30202f2f093b\n"
".quad 0x752e74672e746573,0x09203436662e3233,0x6625202c31327225,0x646625202c303364\n"
".quad 0x67656e090a3b3133,0x722509203233732e,0x31327225202c3232,0x662e766f6d090a3b\n"
".quad 0x3364662509203436,0x6666376430202c32,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x73090a666e69202f,0x33752e746c2e7465,0x2509203436662e32,0x646625202c333272\n"
".quad 0x33646625202c3033,0x2e67656e090a3b32,0x3272250920323373,0x3b33327225202c34\n"
".quad 0x33622e646e61090a,0x2c35327225092032,0x25202c3232722520,0x6f6d090a3b343272\n"
".quad 0x2509203233752e76,0x0a3b30202c363272,0x71652e7074657309,0x702509203233732e\n"
".quad 0x2c35327225202c36,0x090a3b3632722520,0x6172622036702540,0x5f335f744c240920\n"
".quad 0x200a3b3238363933,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x6d090a3433383635,0x09203233752e766f,0x3031202c37327225,0x090a3b3537353834\n"
".quad 0x2e74672e70746573,0x3770250920323375,0x202c37317225202c,0x40090a3b37327225\n"
".quad 0x2061726220377025,0x355f335f744c2409,0x2f200a3b32383838,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3036\n"
".quad 0x64656c6562616c20,0x355f335f744c2420,0x6c2e090a34333836,0x303509313309636f\n"
".quad 0x766f6d090a300931,0x662509203436662e,0x346430202c333364,0x3030303030303533\n"
".quad 0x3b30303030303030,0x30382e31202f2f09,0x0a36312b65343431,0x3436662e6c756d09\n"
".quad 0x2c34336466250920,0x202c303364662520,0x090a3b3333646625,0x203436622e766f6d\n"
".quad 0x252c383272257b09,0x6625202c7d383172,0x6c2e090a3b343364,0x303509313309636f\n"
".quad 0x766f6d090a300932,0x257b09203436622e,0x393272252c393172,0x3433646625202c7d\n"
".quad 0x732e766f6d090a3b,0x3033722509203233,0x3b373730312d202c,0x6e752e617262090a\n"
".quad 0x335f744c24092069,0x0a3b36323638355f,0x38355f335f744c24,0x2f2f200a3a323838\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338\n"
".quad 0x722509203233732e,0x3230312d202c3033,0x335f744c240a3b33,0x0a3a36323638355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c30363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f\n"
".quad 0x09313309636f6c2e,0x73090a3009373035,0x09203233732e7268,0x7225202c31337225\n"
".quad 0x0a3b3032202c3831,0x3233732e64646109,0x202c303372250920,0x7225202c30337225\n"
".quad 0x6f6c2e090a3b3133,0x3930350931330963,0x2e646e61090a3009,0x3372250920323362\n"
".quad 0x2c38317225202c32,0x3334363431322d20,0x6f090a3b33373035,0x2509203233622e72\n"
".quad 0x337225202c333372,0x3632373031202c32,0x090a3b3834323339,0x203436622e766f6d\n"
".quad 0x202c353364662509,0x72252c393172257b,0x6f6d090a3b7d3333,0x2509203233752e76\n"
".quad 0x373031202c343372,0x3b32383537323133,0x6c2e70746573090a,0x2509203233752e65\n"
".quad 0x33337225202c3870,0x0a3b34337225202c,0x7262203870254009,0x335f744c24092061\n"
".quad 0x0a3b38333139355f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30363220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x09313309636f6c2e,0x6d090a3009313135,0x09203436622e766f\n"
".quad 0x72252c353372257b,0x646625202c7d3633,0x627573090a3b3533,0x722509203233732e\n"
".quad 0x36337225202c3733,0x373538343031202c,0x2e766f6d090a3b36,0x72257b0920343662\n"
".quad 0x7d393372252c3833,0x3b3533646625202c,0x36622e766f6d090a,0x3533646625092034\n"
".quad 0x2c383372257b202c,0x090a3b7d37337225,0x09313309636f6c2e,0x61090a3009323135\n"
".quad 0x09203233732e6464,0x7225202c30337225,0x240a3b31202c3033,0x3139355f335f744c\n"
".quad 0x3c2f2f200a3a3833,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30363220656e696c,0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c\n"
".quad 0x636f6c2e090a3433,0x0938313509313309,0x662e766f6d090a30,0x3364662509203436\n"
".quad 0x6666626430202c36,0x3030303030303030,0x2f093b3030303030,0x6461090a312d202f\n"
".quad 0x2509203436662e64,0x6625202c37336466,0x646625202c353364,0x766f6d090a3b3633\n"
".quad 0x662509203436662e,0x336430202c383364,0x3030303030306666,0x3b30303030303030\n"
".quad 0x61090a31202f2f09,0x09203436662e6464,0x25202c3933646625,0x6625202c35336466\n"
".quad 0x7663090a3b383364,0x3233662e6e722e74,0x662509203436662e,0x3933646625202c32\n"
".quad 0x612e706372090a3b,0x33662e786f727070,0x202c336625092032,0x7663090a3b326625\n"
".quad 0x33662e3436662e74,0x3034646625092032,0x090a3b336625202c,0x203436662e67656e\n"
".quad 0x202c313464662509,0x090a3b3933646625,0x203436662e766f6d,0x202c323464662509\n"
".quad 0x3030306666336430,0x3030303030303030,0x31202f2f093b3030,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x646625202c333464,0x34646625202c3134,0x3234646625202c30\n"
".quad 0x722e64616d090a3b,0x2509203436662e6e,0x6625202c34346466,0x646625202c333464\n"
".quad 0x34646625202c3334,0x2e64616d090a3b33,0x09203436662e6e72,0x25202c3534646625\n"
".quad 0x6625202c34346466,0x646625202c303464,0x6c756d090a3b3034,0x662509203436662e\n"
".quad 0x646625202c363464,0x34646625202c3733,0x636f6c2e090a3b35,0x0938323509313309\n"
".quad 0x662e646461090a30,0x3464662509203436,0x3634646625202c37,0x3b3634646625202c\n"
".quad 0x36662e6c756d090a,0x3834646625092034,0x2c3734646625202c,0x0a3b373464662520\n"
".quad 0x3436662e766f6d09,0x2c39346466250920,0x3331626533643020,0x3038656133623038\n"
".quad 0x202f2f093b653166,0x6533333632302e31,0x766f6d090a36302d,0x662509203436662e\n"
".quad 0x336430202c303564,0x3835326565306465,0x3b34306238613762,0x33302e34202f2f09\n"
".quad 0x0a36302d65393436,0x2e6e722e64616d09,0x6466250920343666,0x34646625202c3135\n"
".quad 0x3834646625202c39,0x3b3035646625202c,0x36662e766f6d090a,0x3235646625092034\n"
".quad 0x336665336430202c,0x3230663936363262,0x2f2f093b66363736,0x34343837382e3120\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x2c33356466250920,0x202c313564662520\n"
".quad 0x25202c3834646625,0x6d090a3b32356466,0x09203436662e766f,0x30202c3435646625\n"
".quad 0x6335343731663364,0x3539306261396162,0x2e38202f2f093b36,0x302d653138373738\n"
".quad 0x722e64616d090a35,0x2509203436662e6e,0x6625202c35356466,0x646625202c333564\n"
".quad 0x35646625202c3834,0x2e766f6d090a3b34,0x6466250920343666,0x66336430202c3635\n"
".quad 0x6432376331376333,0x093b343531356231,0x3030302e30202f2f,0x090a383230343334\n"
".quad 0x662e6e722e64616d,0x3564662509203436,0x3535646625202c37,0x2c3834646625202c\n"
".quad 0x0a3b363564662520,0x3436662e766f6d09,0x2c38356466250920,0x3432366633643020\n"
".quad 0x6562333239343239,0x202f2f093b643237,0x3233323230302e30,0x2e64616d090a3431\n"
".quad 0x09203436662e6e72,0x25202c3935646625,0x6625202c37356466,0x646625202c383464\n"
".quad 0x766f6d090a3b3835,0x662509203436662e,0x336430202c303664,0x3939393939393866\n"
".quad 0x3b34633361393939,0x31302e30202f2f09,0x2e64616d090a3532,0x09203436662e6e72\n"
".quad 0x25202c3136646625,0x6625202c39356466,0x646625202c383464,0x6f6c2e090a3b3036\n"
".quad 0x3932350931330963,0x2e766f6d090a3009,0x6466250920343666,0x66336430202c3236\n"
".quad 0x3535353535353562,0x093b343535353535,0x3338302e30202f2f,0x616d090a33333333\n"
".quad 0x3436662e6e722e64,0x2c33366466250920,0x202c313664662520,0x25202c3834646625\n"
".quad 0x2e090a3b32366466,0x3509313309636f6c,0x7573090a30093233,0x2509203436662e62\n"
".quad 0x6625202c34366466,0x646625202c373364,0x67656e090a3b3734,0x662509203436662e\n"
".quad 0x646625202c353664,0x646461090a3b3734,0x662509203436662e,0x646625202c363664\n"
".quad 0x36646625202c3436,0x2e64616d090a3b34,0x09203436662e6e72,0x25202c3736646625\n"
".quad 0x6625202c35366466,0x646625202c373364,0x6c756d090a3b3636,0x662509203436662e\n"
".quad 0x646625202c383664,0x36646625202c3534,0x636f6c2e090a3b37,0x0935333509313309\n"
".quad 0x662e6c756d090a30,0x3664662509203436,0x3834646625202c39,0x3b3336646625202c\n"
".quad 0x36662e6c756d090a,0x3037646625092034,0x2c3734646625202c,0x0a3b393664662520\n"
".quad 0x2e6e722e74766309,0x203233732e343666,0x202c313764662509,0x6d090a3b30337225\n"
".quad 0x09203436662e766f,0x30202c3237646625,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3764662509203436\n"
".quad 0x3137646625202c33,0x2c3237646625202c,0x0a3b373464662520,0x3436662e766f6d09\n"
".quad 0x2c34376466250920,0x6261376333643020,0x3839336233653963,0x202f2f093b663330\n"
".quad 0x6535303931332e32,0x646461090a37312d,0x662509203436662e,0x646625202c353764\n"
".quad 0x36646625202c3037,0x2e67656e090a3b38,0x3472250920323373,0x3b30337225202c30\n"
".quad 0x6e722e747663090a,0x3233732e3436662e,0x2c36376466250920,0x090a3b3034722520\n"
".quad 0x203436662e766f6d,0x202c373764662509,0x6532366566336430,0x3933616665663234\n"
".quad 0x30202f2f093b6665,0x0a3734313339362e,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x37646625202c3837,0x3737646625202c36,0x3b3337646625202c,0x36662e627573090a\n"
".quad 0x3937646625092034,0x2c3837646625202c,0x0a3b373464662520,0x3436662e62757309\n"
".quad 0x2c30386466250920,0x202c353764662520,0x090a3b3937646625,0x662e6e722e64616d\n"
".quad 0x3864662509203436,0x3137646625202c31,0x2c3437646625202c,0x0a3b303864662520\n"
".quad 0x3436662e64646109,0x2c32386466250920,0x202c333764662520,0x090a3b3138646625\n"
".quad 0x20696e752e617262,0x345f335f744c2409,0x744c240a3b383930,0x32383639335f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30363220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x3309636f6c2e090a,0x0a30093834350931,0x3436662e73626109,0x2c33386466250920\n"
".quad 0x0a3b303364662520,0x3436662e766f6d09,0x2c34386466250920,0x3030666637643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x746573090a666e69,0x3436662e656c2e70\n"
".quad 0x25202c3970250920,0x6625202c33386466,0x2540090a3b343864,0x0920617262203970\n"
".quad 0x39355f335f744c24,0x2f2f200a3b303536,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x646461090a343338,0x662509203436662e,0x646625202c323864\n"
".quad 0x33646625202c3033,0x2e617262090a3b30,0x744c240920696e75,0x3b383930345f335f\n"
".quad 0x355f335f744c240a,0x2f200a3a30353639,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3036,0x64656c6562616c20\n"
".quad 0x355f335f744c2420,0x6f6d090a34333836,0x2509203436662e76,0x6430202c35386466\n"
".quad 0x3030303030303030,0x3030303030303030,0x090a30202f2f093b,0x2e71652e70746573\n"
".quad 0x3170250920343666,0x3033646625202c30,0x3b3538646625202c,0x303170252140090a\n"
".quad 0x4c24092061726220,0x363130365f335f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30363220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333836355f335f74,0x662e766f6d090a34,0x3864662509203436\n"
".quad 0x6666666430202c32,0x3030303030303030,0x2f093b3030303030,0x090a666e692d202f\n"
".quad 0x20696e752e617262,0x345f335f744c2409,0x744c240a3b383930,0x32363130365f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30363220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x36662e766f6d090a,0x3638646625092034,0x306666376430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x6573090a666e6920,0x36662e71652e7074,0x2c31317025092034\n"
".quad 0x202c303364662520,0x090a3b3638646625,0x6220313170252140,0x5f744c2409206172\n"
".quad 0x3b34373630365f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x3436662e766f6d09,0x2c32386466250920,0x0a3b303364662520\n"
".quad 0x696e752e61726209,0x5f335f744c240920,0x4c240a3b38393034,0x373630365f335f74\n"
".quad 0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x662e766f6d090a34,0x3864662509203436,0x6666666430202c32,0x3030303030303038\n"
".quad 0x2f093b3030303030,0x4c240a6e616e202f,0x383930345f335f74,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a\n"
".quad 0x0a30093239340931,0x3436662e67656e09,0x2c37386466250920,0x0a3b323864662520\n"
".quad 0x3436622e766f6d09,0x2c313472257b0920,0x25202c7d32347225,0x6d090a3b37386466\n"
".quad 0x09203233732e766f,0x7225202c38317225,0x6f6c2e090a3b3234,0x3339340931330963\n"
".quad 0x2e766f6d090a3009,0x72257b0920343662,0x7d333472252c3931,0x3b3738646625202c\n"
".quad 0x3309636f6c2e090a,0x0a30093539340931,0x3436662e766f6d09,0x2c38386466250920\n"
".quad 0x3030303030643020,0x3030303030303030,0x202f2f093b303030,0x672e746573090a30\n"
".quad 0x36662e3233752e74,0x2c34347225092034,0x202c373864662520,0x090a3b3838646625\n"
".quad 0x203233732e67656e,0x25202c3534722509,0x6f6d090a3b343472,0x2509203436662e76\n"
".quad 0x6430202c39386466,0x3030303030666637,0x3030303030303030,0x666e69202f2f093b\n"
".quad 0x746c2e746573090a,0x3436662e3233752e,0x202c363472250920,0x25202c3738646625\n"
".quad 0x6e090a3b39386466,0x09203233732e6765,0x7225202c37347225,0x646e61090a3b3634\n"
".quad 0x722509203233622e,0x35347225202c3834,0x0a3b37347225202c,0x3233752e766f6d09\n"
".quad 0x202c393472250920,0x70746573090a3b30,0x203233732e71652e,0x25202c3231702509\n"
".quad 0x347225202c383472,0x31702540090a3b39,0x2409206172622032,0x3231345f335f744c\n"
".quad 0x3c2f2f200a3b3831,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x30363220656e696c,0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c\n"
".quad 0x2e766f6d090a3433,0x3572250920323375,0x3538343031202c30,0x746573090a3b3537\n"
".quad 0x3233752e74672e70,0x202c333170250920,0x7225202c32347225,0x702540090a3b3035\n"
".quad 0x0920617262203331,0x31365f335f744c24,0x2f2f200a3b323434,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338,0x3130350931330963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x33346430202c3039,0x3030303030303035\n"
".quad 0x093b303030303030,0x3130382e31202f2f,0x090a36312b653434,0x203436662e6c756d\n"
".quad 0x202c313964662509,0x25202c3738646625,0x6d090a3b30396466,0x09203436622e766f\n"
".quad 0x72252c313572257b,0x646625202c7d3831,0x6f6c2e090a3b3139,0x3230350931330963\n"
".quad 0x2e766f6d090a3009,0x72257b0920343662,0x7d323572252c3931,0x3b3139646625202c\n"
".quad 0x33732e766f6d090a,0x2c30337225092032,0x0a3b373730312d20,0x696e752e61726209\n"
".quad 0x5f335f744c240920,0x240a3b3638313136,0x3431365f335f744c,0x3c2f2f200a3a3234\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c,0x2e766f6d090a3433\n"
".quad 0x3372250920323373,0x333230312d202c30,0x5f335f744c240a3b,0x200a3a3638313136\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635\n"
".quad 0x3509313309636f6c,0x6873090a30093730,0x2509203233732e72,0x317225202c333572\n"
".quad 0x090a3b3032202c38,0x203233732e646461,0x25202c3033722509,0x357225202c303372\n"
".quad 0x636f6c2e090a3b33,0x0939303509313309,0x622e646e61090a30,0x3233722509203233\n"
".quad 0x202c38317225202c,0x353334363431322d,0x726f090a3b333730,0x722509203233622e\n"
".quad 0x32337225202c3333,0x393632373031202c,0x6d090a3b38343233,0x09203436622e766f\n"
".quad 0x7b202c3533646625,0x3372252c39317225,0x766f6d090a3b7d33,0x722509203233752e\n"
".quad 0x33373031202c3435,0x0a3b323835373231,0x656c2e7074657309,0x702509203233752e\n"
".quad 0x33337225202c3431,0x0a3b34357225202c,0x6220343170254009,0x5f744c2409206172\n"
".quad 0x3b38393631365f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x313309636f6c2e09,0x090a300931313509,0x203436622e766f6d\n"
".quad 0x252c353572257b09,0x6625202c7d363572,0x7573090a3b353364,0x2509203233732e62\n"
".quad 0x357225202c373572,0x3538343031202c36,0x766f6d090a3b3637,0x257b09203436622e\n"
".quad 0x393572252c383572,0x3533646625202c7d,0x622e766f6d090a3b,0x3364662509203436\n"
".quad 0x383572257b202c35,0x0a3b7d373572252c,0x313309636f6c2e09,0x090a300932313509\n"
".quad 0x203233732e646461,0x25202c3033722509,0x0a3b31202c303372,0x31365f335f744c24\n"
".quad 0x2f2f200a3a383936,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x6f6c2e090a343338,0x3831350931330963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x66626430202c3239,0x3030303030303066,0x093b303030303030,0x61090a312d202f2f\n"
".quad 0x09203436662e6464,0x25202c3733646625,0x6625202c35336466,0x6f6d090a3b323964\n"
".quad 0x2509203436662e76,0x6430202c33396466,0x3030303030666633,0x3030303030303030\n"
".quad 0x090a31202f2f093b,0x203436662e646461,0x202c393364662509,0x25202c3533646625\n"
".quad 0x63090a3b33396466,0x33662e6e722e7476,0x2509203436662e32,0x33646625202c3266\n"
".quad 0x2e706372090a3b39,0x662e786f72707061,0x2c34662509203233,0x63090a3b32662520\n"
".quad 0x662e3436662e7476,0x3464662509203233,0x0a3b346625202c30,0x3436662e67656e09\n"
".quad 0x2c34396466250920,0x0a3b393364662520,0x3436662e766f6d09,0x2c35396466250920\n"
".quad 0x3030666633643020,0x3030303030303030,0x202f2f093b303030,0x722e64616d090a31\n"
".quad 0x2509203436662e6e,0x6625202c33346466,0x646625202c343964,0x39646625202c3034\n"
".quad 0x2e64616d090a3b35,0x09203436662e6e72,0x25202c3434646625,0x6625202c33346466\n"
".quad 0x646625202c333464,0x64616d090a3b3334,0x203436662e6e722e,0x202c353464662509\n"
".quad 0x25202c3434646625,0x6625202c30346466,0x756d090a3b303464,0x2509203436662e6c\n"
".quad 0x6625202c36346466,0x646625202c373364,0x6f6c2e090a3b3534,0x3832350931330963\n"
".quad 0x2e646461090a3009,0x6466250920343666,0x34646625202c3734,0x3634646625202c36\n"
".quad 0x662e6c756d090a3b,0x3464662509203436,0x3734646625202c38,0x3b3734646625202c\n"
".quad 0x36662e766f6d090a,0x3639646625092034,0x316265336430202c,0x3865613362303833\n"
".quad 0x2f2f093b65316630,0x33333632302e3120,0x6f6d090a36302d65,0x2509203436662e76\n"
".quad 0x6430202c37396466,0x3532656530646533,0x3430623861376238,0x302e34202f2f093b\n"
".quad 0x36302d6539343633,0x6e722e64616d090a,0x662509203436662e,0x646625202c383964\n"
".quad 0x34646625202c3639,0x3739646625202c38,0x662e766f6d090a3b,0x3964662509203436\n"
".quad 0x6665336430202c39,0x3066393636326233,0x2f093b6636373632,0x343837382e31202f\n"
".quad 0x6d090a35302d6534,0x36662e6e722e6461,0x3031646625092034,0x3839646625202c30\n"
".quad 0x2c3834646625202c,0x0a3b393964662520,0x3436662e766f6d09,0x3130316466250920\n"
".quad 0x373166336430202c,0x6261396162633534,0x2f2f093b36353930,0x31383737382e3820\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x3230316466250920,0x303031646625202c\n"
".quad 0x2c3834646625202c,0x3b31303164662520,0x36662e766f6d090a,0x3031646625092034\n"
".quad 0x3366336430202c33,0x3164323763313763,0x2f093b3435313562,0x343030302e30202f\n"
".quad 0x6d090a3832303433,0x36662e6e722e6461,0x3031646625092034,0x3031646625202c34\n"
".quad 0x3834646625202c32,0x333031646625202c,0x662e766f6d090a3b,0x3164662509203436\n"
".quad 0x66336430202c3530,0x3239343239343236,0x093b643237656233,0x3230302e30202f2f\n"
".quad 0x6d090a3431323332,0x36662e6e722e6461,0x3031646625092034,0x3031646625202c36\n"
".quad 0x3834646625202c34,0x353031646625202c,0x662e766f6d090a3b,0x3164662509203436\n"
".quad 0x66336430202c3730,0x3939393939393938,0x093b346333613939,0x3231302e30202f2f\n"
".quad 0x722e64616d090a35,0x2509203436662e6e,0x25202c3830316466,0x25202c3630316466\n"
".quad 0x6625202c38346466,0x2e090a3b37303164,0x3509313309636f6c,0x6f6d090a30093932\n"
".quad 0x2509203436662e76,0x30202c3930316466,0x3535353562663364,0x3535353535353535\n"
".quad 0x2e30202f2f093b34,0x0a33333333333830,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x646625202c303131,0x646625202c383031,0x31646625202c3834,0x6f6c2e090a3b3930\n"
".quad 0x3233350931330963,0x2e627573090a3009,0x6466250920343666,0x33646625202c3436\n"
".quad 0x3734646625202c37,0x662e67656e090a3b,0x3164662509203436,0x34646625202c3131\n"
".quad 0x2e646461090a3b37,0x6466250920343666,0x646625202c323131,0x36646625202c3436\n"
".quad 0x2e64616d090a3b34,0x09203436662e6e72,0x202c333131646625,0x202c313131646625\n"
".quad 0x25202c3733646625,0x090a3b3231316466,0x203436662e6c756d,0x202c383664662509\n"
".quad 0x25202c3534646625,0x090a3b3331316466,0x09313309636f6c2e,0x6d090a3009353335\n"
".quad 0x09203436662e6c75,0x202c343131646625,0x25202c3834646625,0x090a3b3031316466\n"
".quad 0x203436662e6c756d,0x202c303764662509,0x25202c3734646625,0x090a3b3431316466\n"
".quad 0x662e6e722e747663,0x09203233732e3436,0x25202c3137646625,0x6f6d090a3b303372\n"
".quad 0x2509203436662e76,0x30202c3531316466,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3764662509203436\n"
".quad 0x3137646625202c33,0x353131646625202c,0x3b3734646625202c,0x36662e766f6d090a\n"
".quad 0x3131646625092034,0x3763336430202c36,0x3362336539636261,0x2f093b6633303839\n"
".quad 0x303931332e32202f,0x61090a37312d6535,0x09203436662e6464,0x202c373131646625\n"
".quad 0x25202c3037646625,0x6e090a3b38366466,0x09203233732e6765,0x7225202c30367225\n"
".quad 0x747663090a3b3033,0x2e3436662e6e722e,0x6466250920323373,0x367225202c383131\n"
".quad 0x2e766f6d090a3b30,0x6466250920343666,0x336430202c393131,0x6632346532366566\n"
".quad 0x3b66653933616665,0x39362e30202f2f09,0x616d090a37343133,0x3436662e6e722e64\n"
".quad 0x3032316466250920,0x383131646625202c,0x393131646625202c,0x3b3337646625202c\n"
".quad 0x36662e627573090a,0x3231646625092034,0x3231646625202c31,0x3734646625202c30\n"
".quad 0x662e627573090a3b,0x3164662509203436,0x31646625202c3232,0x31646625202c3731\n"
".quad 0x64616d090a3b3132,0x203436662e6e722e,0x2c33323164662509,0x202c313764662520\n"
".quad 0x202c363131646625,0x0a3b323231646625,0x3436662e64646109,0x3432316466250920\n"
".quad 0x2c3337646625202c,0x3b33323164662520,0x6e752e617262090a,0x335f744c24092069\n"
".quad 0x240a3b303136345f,0x3231345f335f744c,0x3c2f2f200a3a3831,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836355f335f744c,0x636f6c2e090a3433,0x0938343509313309\n"
".quad 0x662e736261090a30,0x3164662509203436,0x38646625202c3532,0x2e766f6d090a3b32\n"
".quad 0x6466250920343666,0x376430202c363231,0x3030303030306666,0x3b30303030303030\n"
".quad 0x0a666e69202f2f09,0x656c2e7074657309,0x702509203436662e,0x31646625202c3531\n"
".quad 0x31646625202c3532,0x702540090a3b3632,0x0920617262203531,0x32365f335f744c24\n"
".quad 0x2f2f200a3b303132,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x646461090a343338,0x662509203436662e,0x6625202c37323164,0x646625202c323864\n"
".quad 0x67656e090a3b3238,0x662509203436662e,0x6625202c34323164,0x62090a3b37323164\n"
".quad 0x0920696e752e6172,0x36345f335f744c24,0x5f744c240a3b3031,0x3a30313232365f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33\n"
".quad 0x3436662e766f6d09,0x3832316466250920,0x303030306430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x70746573090a3020,0x203436662e71652e,0x25202c3631702509\n"
".quad 0x6625202c37386466,0x40090a3b38323164,0x7262203631702521,0x335f744c24092061\n"
".quad 0x0a3b32323732365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c30363220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x203436662e766f6d,0x2c34323164662509,0x3030666666643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x7262090a666e692d,0x240920696e752e61\n"
".quad 0x3136345f335f744c,0x335f744c240a3b30,0x0a3a32323732365f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30363220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f,0x203436662e766f6d\n"
".quad 0x2c39323164662509,0x3030666637643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x746573090a666e69,0x3436662e71652e70,0x202c373170250920,0x25202c3738646625\n"
".quad 0x090a3b3932316466,0x6220373170252140,0x5f744c2409206172,0x3b34333233365f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33\n"
".quad 0x3436662e766f6d09,0x3432316466250920,0x3b3738646625202c,0x6e752e617262090a\n"
".quad 0x335f744c24092069,0x240a3b303136345f,0x3233365f335f744c,0x3c2f2f200a3a3433\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x30363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c,0x2e766f6d090a3433\n"
".quad 0x6466250920343666,0x666430202c343231,0x3030303030386666,0x3b30303030303030\n"
".quad 0x0a6e616e202f2f09,0x36345f335f744c24,0x3c2f2f200a3a3031,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836355f335f744c,0x636f6c2e090a3433,0x0938323109393109\n"
".quad 0x662e766f6d090a30,0x3264662509203436,0x3231646625202c37,0x2e617262090a3b34\n"
".quad 0x744c240920696e75,0x34313138355f335f,0x5f335f744c240a3b,0x200a3a3037333835\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635\n"
".quad 0x3409313309636f6c,0x6f6d090a30093239,0x7b09203436622e76,0x3672252c31367225\n"
".quad 0x31646625202c7d32,0x732e766f6d090a3b,0x3831722509203233,0x0a3b32367225202c\n"
".quad 0x313309636f6c2e09,0x090a300933393409,0x203436622e766f6d,0x252c393172257b09\n"
".quad 0x6625202c7d333672,0x6f6c2e090a3b3164,0x3539340931330963,0x2e766f6d090a3009\n"
".quad 0x6466250920343666,0x306430202c303331,0x3030303030303030,0x3b30303030303030\n"
".quad 0x73090a30202f2f09,0x33752e74672e7465,0x2509203436662e32,0x646625202c343672\n"
".quad 0x3331646625202c31,0x2e67656e090a3b30,0x3672250920323373,0x3b34367225202c35\n"
".quad 0x36662e766f6d090a,0x3331646625092034,0x6666376430202c31,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x73090a666e69202f,0x33752e746c2e7465,0x2509203436662e32\n"
".quad 0x646625202c363672,0x3331646625202c31,0x2e67656e090a3b31,0x3672250920323373\n"
".quad 0x3b36367225202c37,0x33622e646e61090a,0x2c38367225092032,0x25202c3536722520\n"
".quad 0x6f6d090a3b373672,0x2509203233752e76,0x0a3b30202c393672,0x71652e7074657309\n"
".quad 0x702509203233732e,0x38367225202c3831,0x0a3b39367225202c,0x6220383170254009\n"
".quad 0x5f744c2409206172,0x3b34353732345f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333836355f33,0x3233752e766f6d09,0x202c303772250920\n"
".quad 0x3b35373538343031,0x672e70746573090a,0x2509203233752e74,0x367225202c393170\n"
".quad 0x3b30377225202c32,0x203931702540090a,0x744c240920617262,0x32303034365f335f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c30363220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x3309636f6c2e090a,0x0a30093130350931,0x3436662e766f6d09,0x3233316466250920\n"
".quad 0x303533346430202c,0x3030303030303030,0x2f2f093b30303030,0x34343130382e3120\n"
".quad 0x756d090a36312b65,0x2509203436662e6c,0x25202c3333316466,0x646625202c316466\n"
".quad 0x6f6d090a3b323331,0x7b09203436622e76,0x3172252c31377225,0x31646625202c7d38\n"
".quad 0x6f6c2e090a3b3333,0x3230350931330963,0x2e766f6d090a3009,0x72257b0920343662\n"
".quad 0x7d323772252c3931,0x333331646625202c,0x732e766f6d090a3b,0x3033722509203233\n"
".quad 0x3b373730312d202c,0x6e752e617262090a,0x335f744c24092069,0x0a3b36343733365f\n"
".quad 0x34365f335f744c24,0x2f2f200a3a323030,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x766f6d090a343338,0x722509203233732e,0x3230312d202c3033\n"
".quad 0x335f744c240a3b33,0x0a3a36343733365f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30363220,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a34333836355f,0x09313309636f6c2e,0x73090a3009373035\n"
".quad 0x09203233732e7268,0x7225202c33377225,0x0a3b3032202c3831,0x3233732e64646109\n"
".quad 0x202c303372250920,0x7225202c30337225,0x6f6c2e090a3b3337,0x3930350931330963\n"
".quad 0x2e646e61090a3009,0x3372250920323362,0x2c38317225202c32,0x3334363431322d20\n"
".quad 0x6f090a3b33373035,0x2509203233622e72,0x337225202c333372,0x3632373031202c32\n"
".quad 0x090a3b3834323339,0x203436622e766f6d,0x202c353364662509,0x72252c393172257b\n"
".quad 0x6f6d090a3b7d3333,0x2509203233752e76,0x373031202c343772,0x3b32383537323133\n"
".quad 0x6c2e70746573090a,0x2509203233752e65,0x337225202c303270,0x3b34377225202c33\n"
".quad 0x203032702540090a,0x744c240920617262,0x38353234365f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a\n"
".quad 0x0a30093131350931,0x3436622e766f6d09,0x2c353772257b0920,0x25202c7d36377225\n"
".quad 0x73090a3b35336466,0x09203233732e6275,0x7225202c37377225,0x38343031202c3637\n"
".quad 0x6f6d090a3b363735,0x7b09203436622e76,0x3772252c38377225,0x33646625202c7d39\n"
".quad 0x2e766f6d090a3b35,0x6466250920343662,0x3772257b202c3533,0x3b7d373772252c38\n"
".quad 0x3309636f6c2e090a,0x0a30093231350931,0x3233732e64646109,0x202c303372250920\n"
".quad 0x3b31202c30337225,0x365f335f744c240a,0x2f200a3a38353234,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3036\n"
".quad 0x64656c6562616c20,0x355f335f744c2420,0x6c2e090a34333836,0x313509313309636f\n"
".quad 0x766f6d090a300938,0x662509203436662e,0x6430202c34333164,0x3030303030666662\n"
".quad 0x3030303030303030,0x0a312d202f2f093b,0x3436662e64646109,0x2c37336466250920\n"
".quad 0x202c353364662520,0x0a3b343331646625,0x3436662e766f6d09,0x3533316466250920\n"
".quad 0x306666336430202c,0x3030303030303030,0x2f2f093b30303030,0x2e646461090a3120\n"
".quad 0x6466250920343666,0x33646625202c3933,0x3331646625202c35,0x2e747663090a3b35\n"
".quad 0x662e3233662e6e72,0x2c32662509203436,0x0a3b393364662520,0x7070612e70637209\n"
".quad 0x203233662e786f72,0x6625202c35662509,0x2e747663090a3b32,0x203233662e343666\n"
".quad 0x202c303464662509,0x656e090a3b356625,0x2509203436662e67,0x25202c3633316466\n"
".quad 0x6d090a3b39336466,0x09203436662e766f,0x202c373331646625,0x3030306666336430\n"
".quad 0x3030303030303030,0x31202f2f093b3030,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x646625202c333464,0x646625202c363331,0x31646625202c3034,0x64616d090a3b3733\n"
".quad 0x203436662e6e722e,0x202c343464662509,0x25202c3334646625,0x6625202c33346466\n"
".quad 0x616d090a3b333464,0x3436662e6e722e64,0x2c35346466250920,0x202c343464662520\n"
".quad 0x25202c3034646625,0x6d090a3b30346466,0x09203436662e6c75,0x25202c3634646625\n"
".quad 0x6625202c37336466,0x6c2e090a3b353464,0x323509313309636f,0x646461090a300938\n"
".quad 0x662509203436662e,0x646625202c373464,0x34646625202c3634,0x2e6c756d090a3b36\n"
".quad 0x6466250920343666,0x34646625202c3834,0x3734646625202c37,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x65336430202c3833,0x6133623038333162,0x093b653166303865\n"
".quad 0x3632302e31202f2f,0x090a36302d653333,0x203436662e766f6d,0x2c39333164662509\n"
".quad 0x6530646533643020,0x3861376238353265,0x202f2f093b343062,0x6539343633302e34\n"
".quad 0x64616d090a36302d,0x203436662e6e722e,0x2c30343164662509,0x2c38333164662520\n"
".quad 0x202c383464662520,0x0a3b393331646625,0x3436662e766f6d09,0x3134316466250920\n"
".quad 0x336665336430202c,0x3230663936363262,0x2f2f093b66363736,0x34343837382e3120\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x3234316466250920,0x303431646625202c\n"
".quad 0x2c3834646625202c,0x3b31343164662520,0x36662e766f6d090a,0x3431646625092034\n"
".quad 0x3166336430202c33,0x6139616263353437,0x2f093b3635393062,0x383737382e38202f\n"
".quad 0x6d090a35302d6531,0x36662e6e722e6461,0x3431646625092034,0x3431646625202c34\n"
".quad 0x3834646625202c32,0x333431646625202c,0x662e766f6d090a3b,0x3164662509203436\n"
".quad 0x66336430202c3534,0x6432376331376333,0x093b343531356231,0x3030302e30202f2f\n"
".quad 0x090a383230343334,0x662e6e722e64616d,0x3164662509203436,0x31646625202c3634\n"
".quad 0x34646625202c3434,0x3431646625202c38,0x2e766f6d090a3b35,0x6466250920343666\n"
".quad 0x336430202c373431,0x3934323934323666,0x3b64323765623332,0x30302e30202f2f09\n"
".quad 0x090a343132333232,0x662e6e722e64616d,0x3164662509203436,0x31646625202c3834\n"
".quad 0x34646625202c3634,0x3431646625202c38,0x2e766f6d090a3b37,0x6466250920343666\n"
".quad 0x336430202c393431,0x3939393939393866,0x3b34633361393939,0x31302e30202f2f09\n"
".quad 0x2e64616d090a3532,0x09203436662e6e72,0x202c303531646625,0x202c383431646625\n"
".quad 0x25202c3834646625,0x090a3b3934316466,0x09313309636f6c2e,0x6d090a3009393235\n"
".quad 0x09203436662e766f,0x202c313531646625,0x3535356266336430,0x3535353535353535\n"
".quad 0x30202f2f093b3435,0x333333333338302e,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x6625202c32353164,0x6625202c30353164,0x646625202c383464,0x6c2e090a3b313531\n"
".quad 0x333509313309636f,0x627573090a300932,0x662509203436662e,0x646625202c343664\n"
".quad 0x34646625202c3733,0x2e67656e090a3b37,0x6466250920343666,0x646625202c333531\n"
".quad 0x646461090a3b3734,0x662509203436662e,0x6625202c34353164,0x646625202c343664\n"
".quad 0x64616d090a3b3436,0x203436662e6e722e,0x2c35353164662509,0x2c33353164662520\n"
".quad 0x202c373364662520,0x0a3b343531646625,0x3436662e6c756d09,0x2c38366466250920\n"
".quad 0x202c353464662520,0x0a3b353531646625,0x313309636f6c2e09,0x090a300935333509\n"
".quad 0x203436662e6c756d,0x2c36353164662509,0x202c383464662520,0x0a3b323531646625\n"
".quad 0x3436662e6c756d09,0x2c30376466250920,0x202c373464662520,0x0a3b363531646625\n"
".quad 0x2e6e722e74766309,0x203233732e343666,0x202c313764662509,0x6d090a3b30337225\n"
".quad 0x09203436662e766f,0x202c373531646625,0x6532366566336430,0x3933616665663234\n"
".quad 0x30202f2f093b6665,0x0a3734313339362e,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x37646625202c3337,0x3531646625202c31,0x3734646625202c37,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x63336430202c3835,0x6233653963626137,0x093b663330383933\n"
".quad 0x3931332e32202f2f,0x090a37312d653530,0x203436662e646461,0x2c39353164662509\n"
".quad 0x202c303764662520,0x090a3b3836646625,0x203233732e67656e,0x25202c3038722509\n"
".quad 0x7663090a3b303372,0x3436662e6e722e74,0x662509203233732e,0x7225202c30363164\n"
".quad 0x766f6d090a3b3038,0x662509203436662e,0x6430202c31363164,0x3234653236656633\n"
".quad 0x6665393361666566,0x362e30202f2f093b,0x6d090a3734313339,0x36662e6e722e6461\n"
".quad 0x3631646625092034,0x3631646625202c32,0x3631646625202c30,0x3337646625202c31\n"
".quad 0x662e627573090a3b,0x3164662509203436,0x31646625202c3336,0x34646625202c3236\n"
".quad 0x2e627573090a3b37,0x6466250920343666,0x646625202c343631,0x646625202c393531\n"
".quad 0x616d090a3b333631,0x3436662e6e722e64,0x3536316466250920,0x2c3137646625202c\n"
".quad 0x2c38353164662520,0x3b34363164662520,0x36662e646461090a,0x3631646625092034\n"
".quad 0x3337646625202c36,0x353631646625202c,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x0a3b343730335f33,0x32345f335f744c24,0x2f2f200a3a343537,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338,0x3834350931330963\n"
".quad 0x2e736261090a3009,0x6466250920343666,0x646625202c373631,0x2e766f6d090a3b31\n"
".quad 0x6466250920343666,0x376430202c383631,0x3030303030306666,0x3b30303030303030\n"
".quad 0x0a666e69202f2f09,0x656c2e7074657309,0x702509203436662e,0x31646625202c3132\n"
".quad 0x31646625202c3736,0x702540090a3b3836,0x0920617262203132,0x34365f335f744c24\n"
".quad 0x2f2f200a3b303737,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x646461090a343338,0x662509203436662e,0x6625202c36363164,0x31646625202c3164\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x0a3b343730335f33,0x34365f335f744c24\n"
".quad 0x2f2f200a3a303737,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x766f6d090a343338,0x662509203436662e,0x6430202c39363164,0x3030303030303030\n"
".quad 0x3030303030303030,0x090a30202f2f093b,0x2e71652e70746573,0x3270250920343666\n"
".quad 0x2c31646625202c32,0x3b39363164662520,0x323270252140090a,0x4c24092061726220\n"
".quad 0x383235365f335f74,0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333836355f335f74,0x662e766f6d090a34,0x3164662509203436,0x66666430202c3636\n"
".quad 0x3030303030303066,0x093b303030303030,0x0a666e692d202f2f,0x696e752e61726209\n"
".quad 0x5f335f744c240920,0x4c240a3b34373033,0x383235365f335f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c30363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333836355f335f74,0x662e766f6d090a34\n"
".quad 0x3164662509203436,0x66376430202c3037,0x3030303030303066,0x093b303030303030\n"
".quad 0x090a666e69202f2f,0x2e71652e70746573,0x3270250920343666,0x2c31646625202c33\n"
".quad 0x3b30373164662520,0x333270252140090a,0x4c24092061726220,0x393735365f335f74\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x662e766f6d090a34,0x3164662509203436,0x31646625202c3636,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x0a3b343730335f33,0x35365f335f744c24,0x2f2f200a3a343937\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338\n"
".quad 0x662509203436662e,0x6430202c36363164,0x3030303038666666,0x3030303030303030\n"
".quad 0x6e616e202f2f093b,0x335f335f744c240a,0x2f2f200a3a343730,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c30\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338,0x3239340931330963\n"
".quad 0x2e67656e090a3009,0x6466250920343666,0x646625202c313731,0x6f6d090a3b363631\n"
".quad 0x7b09203436622e76,0x3872252c31387225,0x31646625202c7d32,0x766f6d090a3b3137\n"
".quad 0x722509203233732e,0x32387225202c3831,0x09636f6c2e090a3b,0x3009333934093133\n"
".quad 0x36622e766f6d090a,0x393172257b092034,0x202c7d333872252c,0x0a3b313731646625\n"
".quad 0x313309636f6c2e09,0x090a300935393409,0x203436662e766f6d,0x2c32373164662509\n"
".quad 0x3030303030643020,0x3030303030303030,0x202f2f093b303030,0x672e746573090a30\n"
".quad 0x36662e3233752e74,0x2c34387225092034,0x2c31373164662520,0x3b32373164662520\n"
".quad 0x33732e67656e090a,0x2c35387225092032,0x090a3b3438722520,0x203436662e766f6d\n"
".quad 0x2c33373164662509,0x3030666637643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x746573090a666e69,0x2e3233752e746c2e,0x3872250920343666,0x3731646625202c36\n"
".quad 0x3731646625202c31,0x2e67656e090a3b33,0x3872250920323373,0x3b36387225202c37\n"
".quad 0x33622e646e61090a,0x2c38387225092032,0x25202c3538722520,0x6f6d090a3b373872\n"
".quad 0x2509203233752e76,0x0a3b30202c393872,0x71652e7074657309,0x702509203233732e\n"
".quad 0x38387225202c3432,0x0a3b39387225202c,0x6220343270254009,0x5f744c2409206172\n"
".quad 0x3b30393234345f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x3233752e766f6d09,0x202c303972250920,0x3b35373538343031\n"
".quad 0x672e70746573090a,0x2509203233752e74,0x387225202c353270,0x3b30397225202c32\n"
".quad 0x203532702540090a,0x744c240920617262,0x32363536365f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c30363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a\n"
".quad 0x0a30093130350931,0x3436662e766f6d09,0x3437316466250920,0x303533346430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x34343130382e3120,0x756d090a36312b65\n"
".quad 0x2509203436662e6c,0x25202c3537316466,0x25202c3137316466,0x090a3b3437316466\n"
".quad 0x203436622e766f6d,0x252c313972257b09,0x6625202c7d383172,0x2e090a3b35373164\n"
".quad 0x3509313309636f6c,0x6f6d090a30093230,0x7b09203436622e76,0x3972252c39317225\n"
".quad 0x31646625202c7d32,0x766f6d090a3b3537,0x722509203233732e,0x3730312d202c3033\n"
".quad 0x2e617262090a3b37,0x744c240920696e75,0x36303336365f335f,0x5f335f744c240a3b\n"
".quad 0x200a3a3236353636,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x6d090a3433383635,0x09203233732e766f,0x312d202c30337225,0x744c240a3b333230\n"
".quad 0x36303336365f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c30363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333836355f335f,0x3309636f6c2e090a,0x0a30093730350931,0x3233732e72687309\n"
".quad 0x202c333972250920,0x3032202c38317225,0x732e646461090a3b,0x3033722509203233\n"
".quad 0x202c30337225202c,0x2e090a3b33397225,0x3509313309636f6c,0x6e61090a30093930\n"
".quad 0x2509203233622e64,0x317225202c323372,0x363431322d202c38,0x0a3b333730353334\n"
".quad 0x203233622e726f09,0x25202c3333722509,0x373031202c323372,0x3b38343233393632\n"
".quad 0x36622e766f6d090a,0x3533646625092034,0x2c393172257b202c,0x090a3b7d33337225\n"
".quad 0x203233752e766f6d,0x31202c3439722509,0x3835373231333730,0x70746573090a3b32\n"
".quad 0x203233752e656c2e,0x25202c3632702509,0x397225202c333372,0x32702540090a3b34\n"
".quad 0x2409206172622036,0x3836365f335f744c,0x3c2f2f200a3b3831,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x30363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836355f335f744c,0x636f6c2e090a3433,0x0931313509313309\n"
".quad 0x622e766f6d090a30,0x3972257b09203436,0x2c7d363972252c35,0x0a3b353364662520\n"
".quad 0x3233732e62757309,0x202c373972250920,0x3031202c36397225,0x090a3b3637353834\n"
".quad 0x203436622e766f6d,0x252c383972257b09,0x6625202c7d393972,0x6f6d090a3b353364\n"
".quad 0x2509203436622e76,0x257b202c35336466,0x373972252c383972,0x636f6c2e090a3b7d\n"
".quad 0x0932313509313309,0x732e646461090a30,0x3033722509203233,0x202c30337225202c\n"
".quad 0x335f744c240a3b31,0x0a3a38313836365f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c30363220,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a34333836355f,0x09313309636f6c2e,0x6d090a3009383135\n"
".quad 0x09203436662e766f,0x202c363731646625,0x3030306666626430,0x3030303030303030\n"
".quad 0x2d202f2f093b3030,0x662e646461090a31,0x3364662509203436,0x3533646625202c37\n"
".quad 0x363731646625202c,0x662e766f6d090a3b,0x3164662509203436,0x66336430202c3737\n"
".quad 0x3030303030303066,0x093b303030303030,0x6461090a31202f2f,0x2509203436662e64\n"
".quad 0x6625202c39336466,0x646625202c353364,0x7663090a3b373731,0x3233662e6e722e74\n"
".quad 0x662509203436662e,0x3933646625202c32,0x612e706372090a3b,0x33662e786f727070\n"
".quad 0x202c366625092032,0x7663090a3b326625,0x33662e3436662e74,0x3034646625092032\n"
".quad 0x090a3b366625202c,0x203436662e67656e,0x2c38373164662509,0x0a3b393364662520\n"
".quad 0x3436662e766f6d09,0x3937316466250920,0x306666336430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x2e64616d090a3120,0x09203436662e6e72,0x25202c3334646625\n"
".quad 0x25202c3837316466,0x6625202c30346466,0x6d090a3b39373164,0x36662e6e722e6461\n"
".quad 0x3434646625092034,0x2c3334646625202c,0x202c333464662520,0x090a3b3334646625\n"
".quad 0x662e6e722e64616d,0x3464662509203436,0x3434646625202c35,0x2c3034646625202c\n"
".quad 0x0a3b303464662520,0x3436662e6c756d09,0x2c36346466250920,0x202c373364662520\n"
".quad 0x090a3b3534646625,0x09313309636f6c2e,0x61090a3009383235,0x09203436662e6464\n"
".quad 0x25202c3734646625,0x6625202c36346466,0x756d090a3b363464,0x2509203436662e6c\n"
".quad 0x6625202c38346466,0x646625202c373464,0x766f6d090a3b3734,0x662509203436662e\n"
".quad 0x6430202c30383164,0x6230383331626533,0x6531663038656133,0x302e31202f2f093b\n"
".quad 0x36302d6533333632,0x36662e766f6d090a,0x3831646625092034,0x6465336430202c31\n"
".quad 0x3762383532656530,0x2f093b3430623861,0x343633302e34202f,0x6d090a36302d6539\n"
".quad 0x36662e6e722e6461,0x3831646625092034,0x3831646625202c32,0x3834646625202c30\n"
".quad 0x313831646625202c,0x662e766f6d090a3b,0x3164662509203436,0x65336430202c3338\n"
".quad 0x6639363632623366,0x093b663637363230,0x3837382e31202f2f,0x090a35302d653434\n"
".quad 0x662e6e722e64616d,0x3164662509203436,0x31646625202c3438,0x34646625202c3238\n"
".quad 0x3831646625202c38,0x2e766f6d090a3b33,0x6466250920343666,0x336430202c353831\n"
".quad 0x6162633534373166,0x3b36353930626139,0x37382e38202f2f09,0x0a35302d65313837\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x646625202c363831,0x646625202c343831\n"
".quad 0x31646625202c3834,0x766f6d090a3b3538,0x662509203436662e,0x6430202c37383164\n"
".quad 0x3763313763336633,0x3435313562316432,0x302e30202f2f093b,0x3832303433343030\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c38383164,0x6625202c36383164\n"
".quad 0x646625202c383464,0x6f6d090a3b373831,0x2509203436662e76,0x30202c3938316466\n"
".quad 0x3239343236663364,0x3237656233323934,0x2e30202f2f093b64,0x3431323332323030\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c30393164,0x6625202c38383164\n"
".quad 0x646625202c383464,0x6f6d090a3b393831,0x2509203436662e76,0x30202c3139316466\n"
".quad 0x3939393938663364,0x6333613939393939,0x2e30202f2f093b34,0x616d090a35323130\n"
".quad 0x3436662e6e722e64,0x3239316466250920,0x303931646625202c,0x2c3834646625202c\n"
".quad 0x3b31393164662520,0x3309636f6c2e090a,0x0a30093932350931,0x3436662e766f6d09\n"
".quad 0x3339316466250920,0x356266336430202c,0x3535353535353535,0x2f2f093b34353535\n"
".quad 0x33333338302e3020,0x2e64616d090a3333,0x09203436662e6e72,0x202c343931646625\n"
".quad 0x202c323931646625,0x25202c3834646625,0x090a3b3339316466,0x09313309636f6c2e\n"
".quad 0x73090a3009323335,0x09203436662e6275,0x25202c3436646625,0x6625202c37336466\n"
".quad 0x656e090a3b373464,0x2509203436662e67,0x25202c3539316466,0x61090a3b37346466\n"
".quad 0x09203436662e6464,0x202c363931646625,0x25202c3436646625,0x6d090a3b34366466\n"
".quad 0x36662e6e722e6461,0x3931646625092034,0x3931646625202c37,0x3733646625202c35\n"
".quad 0x363931646625202c,0x662e6c756d090a3b,0x3664662509203436,0x3534646625202c38\n"
".quad 0x373931646625202c,0x09636f6c2e090a3b,0x3009353335093133,0x36662e6c756d090a\n"
".quad 0x3931646625092034,0x3834646625202c38,0x343931646625202c,0x662e6c756d090a3b\n"
".quad 0x3764662509203436,0x3734646625202c30,0x383931646625202c,0x722e747663090a3b\n"
".quad 0x33732e3436662e6e,0x3137646625092032,0x0a3b30337225202c,0x3436662e766f6d09\n"
".quad 0x3939316466250920,0x366566336430202c,0x6166656632346532,0x2f2f093b66653933\n"
".quad 0x34313339362e3020,0x722e64616d090a37,0x2509203436662e6e,0x6625202c33376466\n"
".quad 0x646625202c313764,0x646625202c393931,0x766f6d090a3b3734,0x662509203436662e\n"
".quad 0x6430202c30303264,0x6539636261376333,0x6633303839336233,0x332e32202f2f093b\n"
".quad 0x37312d6535303931,0x36662e646461090a,0x3032646625092034,0x3037646625202c31\n"
".quad 0x3b3836646625202c,0x33732e67656e090a,0x3030317225092032,0x0a3b30337225202c\n"
".quad 0x2e6e722e74766309,0x203233732e343666,0x2c32303264662509,0x0a3b303031722520\n"
".quad 0x3436662e766f6d09,0x3330326466250920,0x366566336430202c,0x6166656632346532\n"
".quad 0x2f2f093b66653933,0x34313339362e3020,0x722e64616d090a37,0x2509203436662e6e\n"
".quad 0x25202c3430326466,0x25202c3230326466,0x25202c3330326466,0x73090a3b33376466\n"
".quad 0x09203436662e6275,0x202c353032646625,0x202c343032646625,0x090a3b3734646625\n"
".quad 0x203436662e627573,0x2c36303264662509,0x2c31303264662520,0x3b35303264662520\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c37303264,0x646625202c313764\n"
".quad 0x646625202c303032,0x6461090a3b363032,0x2509203436662e64,0x25202c3830326466\n"
".quad 0x6625202c33376466,0x62090a3b37303264,0x0920696e752e6172,0x35335f335f744c24\n"
".quad 0x5f744c240a3b3638,0x3a30393234345f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333836355f33,0x313309636f6c2e09,0x090a300938343509\n"
".quad 0x203436662e736261,0x2c39303264662509,0x3b36363164662520,0x36662e766f6d090a\n"
".quad 0x3132646625092034,0x6666376430202c30,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x73090a666e69202f,0x662e656c2e707465,0x3732702509203436,0x393032646625202c\n"
".quad 0x303132646625202c,0x3732702540090a3b,0x4c24092061726220,0x333337365f335f74\n"
".quad 0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x662e646461090a34,0x3264662509203436,0x31646625202c3131,0x31646625202c3636\n"
".quad 0x67656e090a3b3636,0x662509203436662e,0x6625202c38303264,0x62090a3b31313264\n"
".quad 0x0920696e752e6172,0x35335f335f744c24,0x5f744c240a3b3638,0x3a30333337365f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33\n"
".quad 0x3436662e766f6d09,0x3231326466250920,0x303030306430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x70746573090a3020,0x203436662e71652e,0x25202c3832702509\n"
".quad 0x25202c3137316466,0x090a3b3231326466,0x6220383270252140,0x5f744c2409206172\n"
".quad 0x3b32343837365f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3036322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x3436662e766f6d09,0x3830326466250920,0x306666666430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x62090a666e692d20,0x0920696e752e6172\n"
".quad 0x35335f335f744c24,0x5f744c240a3b3638,0x3a32343837365f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3036322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33,0x3436662e766f6d09\n"
".quad 0x3331326466250920,0x306666376430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x6573090a666e6920,0x36662e71652e7074,0x2c39327025092034,0x2c31373164662520\n"
".quad 0x3b33313264662520,0x393270252140090a,0x4c24092061726220,0x353338365f335f74\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x662e766f6d090a34,0x3264662509203436,0x31646625202c3830,0x617262090a3b3137\n"
".quad 0x4c240920696e752e,0x363835335f335f74,0x5f335f744c240a3b,0x200a3a3435333836\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064,0x6d090a3433383635\n"
".quad 0x09203436662e766f,0x202c383032646625,0x3030386666666430,0x3030303030303030\n"
".quad 0x6e202f2f093b3030,0x335f744c240a6e61,0x200a3a363835335f,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c303632\n"
".quad 0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635,0x3109393109636f6c\n"
".quad 0x6f6d090a30093033,0x2509203436662e76,0x6625202c37326466,0x4c240a3b38303264\n"
".quad 0x313138355f335f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c30363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333836355f335f74,0x09636f6c2e090a34,0x3009323331093931,0x36662e766f6d090a\n"
".quad 0x3132646625092034,0x6466336430202c34,0x6533633233393935,0x2f093b6436333034\n"
".quad 0x343733332e30202f,0x2e766f6d090a3537,0x6466250920343666,0x336430202c353132\n"
".quad 0x6336636333666566,0x3b31333163623866,0x37392e30202f2f09,0x6f6d090a39363136\n"
".quad 0x2509203436662e76,0x30202c3631326466,0x3035393463663364,0x3836303936363237\n"
".quad 0x2e30202f2f093b36,0x090a383937303631,0x203436662e766f6d,0x2c37313264662509\n"
".quad 0x3463396633643020,0x3434653337646165,0x202f2f093b373332,0x3334363732302e30\n"
".quad 0x662e766f6d090a39,0x3264662509203436,0x66336430202c3831,0x3565333436376636\n"
".quad 0x093b353837366533,0x3330302e30202f2f,0x6d090a3735303438,0x09203436662e766f\n"
".quad 0x202c393132646625,0x3665393366336430,0x3838396130616532,0x30202f2f093b3634\n"
".quad 0x313539333030302e,0x662e766f6d090a39,0x3264662509203436,0x66336430202c3032\n"
".quad 0x3530326265643030,0x093b383032383566,0x3731322e33202f2f,0x090a35302d653836\n"
".quad 0x203436662e766f6d,0x2c31323264662509,0x3633396533643020,0x3762393037356431\n"
".quad 0x202f2f093b363562,0x6537313838382e32,0x766f6d090a37302d,0x662509203436662e\n"
".quad 0x6430202c32323264,0x3563333961396533,0x6461356432306130,0x392e33202f2f093b\n"
".quad 0x37302d6532333036,0x6e722e64616d090a,0x662509203436662e,0x6625202c33323264\n"
".quad 0x6625202c32323264,0x646625202c373264,0x616d090a3b313232,0x3436662e6e722e64\n"
".quad 0x3432326466250920,0x2c3732646625202c,0x2c33323264662520,0x3b30323264662520\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c35323264,0x646625202c373264\n"
".quad 0x646625202c343232,0x616d090a3b393132,0x3436662e6e722e64,0x3632326466250920\n"
".quad 0x2c3732646625202c,0x2c35323264662520,0x3b38313264662520,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x6625202c37323264,0x646625202c373264,0x646625202c363232\n"
".quad 0x616d090a3b373132,0x3436662e6e722e64,0x3832326466250920,0x2c3732646625202c\n"
".quad 0x2c37323264662520,0x3b36313264662520,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x6625202c39323264,0x646625202c373264,0x646625202c383232,0x616d090a3b353132\n"
".quad 0x3436662e6e722e64,0x3033326466250920,0x2c3732646625202c,0x2c39323264662520\n"
".quad 0x3b34313264662520,0x36662e67656e090a,0x3332646625092034,0x3332646625202c31\n"
".quad 0x2e766f6d090a3b30,0x6466250920343666,0x306430202c323332,0x3030303030303030\n"
".quad 0x3b30303030303030,0x73090a30202f2f09,0x662e746c2e707465,0x3033702509203436\n"
".quad 0x202c36646625202c,0x0a3b323332646625,0x36662e706c657309,0x3732646625092034\n"
".quad 0x313332646625202c,0x303332646625202c,0x0a3b30337025202c,0x37355f335f744c24\n"
".quad 0x2f2f200a3a323036,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c30,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x766f6d090a343338,0x662509203436662e,0x32646625202c3464,0x335f744c240a3b37\n"
".quad 0x200a3a383138325f,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c303632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3433383635,0x3209393109636f6c,0x7663090a30093136,0x3233662e6e722e74\n"
".quad 0x662509203436662e,0x3b34646625202c37,0x6f6c672e7473090a,0x203233662e6c6162\n"
".quad 0x302b396472255b09,0x0a3b376625202c5d,0x3233752e64646109,0x25202c3772250920\n"
".quad 0x3b377225202c3972,0x36752e646461090a,0x2c39647225092034,0x25202c3964722520\n"
".quad 0x6461090a3b366472,0x2509203436752e64,0x647225202c376472,0x3b36647225202c37\n"
".quad 0x3109636f6c2e090a,0x0a30093135320939,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x635f5f5b202c3172,0x5f6d726170616475,0x65766e6936315a5f,0x654b444e43657372\n"
".quad 0x5f5366506c656e72,0x5d4e687461705f6a,0x09636f6c2e090a3b,0x3009313632093931\n"
".quad 0x6c2e70746573090a,0x2509203233752e74,0x377225202c313370,0x090a3b317225202c\n"
".quad 0x7262203133702540,0x335f744c24092061,0x0a3b34333836355f,0x696e752e61726209\n"
".quad 0x5f335f744c240920,0x240a3b3232313936,0x3036355f335f744c,0x6f6c2e090a3a3636\n"
".quad 0x3736320939310963,0x326c756d090a3009,0x3233752e6f6c2e34,0x2c31303172250920\n"
".quad 0x7225202c34722520,0x2e646461090a3b33,0x3172250920323375,0x30317225202c3230\n"
".quad 0x0a3b327225202c31,0x3233732e766f6d09,0x2c33303172250920,0x0a3b323031722520\n"
".quad 0x393109636f6c2e09,0x090a300931353209,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x75635f5f5b202c31,0x5f5f6d7261706164,0x7265766e6936315a,0x72654b444e436573\n"
".quad 0x6a5f5366506c656e,0x3b5d4e687461705f,0x3109636f6c2e090a,0x0a30093736320939\n"
".quad 0x65672e7074657309,0x702509203233752e,0x30317225202c3233,0x0a3b317225202c32\n"
".quad 0x6220323370254009,0x5f744c2409206172,0x3b32323139365f33,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x7225202c30316472,0x7663090a3b323031,0x31752e3233752e74\n"
".quad 0x3430317225092036,0x696174636e25202c,0x756d090a3b782e64,0x752e6f6c2e34326c\n"
".quad 0x3031722509203233,0x202c347225202c35,0x090a3b3430317225,0x656469772e6c756d\n"
".quad 0x722509203233752e,0x317225202c313164,0x090a3b34202c3230,0x2e3436732e747663\n"
".quad 0x6472250920323375,0x30317225202c3231,0x636f6c2e090a3b35,0x0931353209393109\n"
".quad 0x61702e646c090a30,0x203233752e6d6172,0x5f5b202c31722509,0x726170616475635f\n"
".quad 0x6e6936315a5f5f6d,0x444e436573726576,0x66506c656e72654b,0x687461705f6a5f53\n"
".quad 0x6f6c2e090a3b5d4e,0x3736320939310963,0x2e646461090a3009,0x3172250920323375\n"
".quad 0x2c317225202c3630,0x747663090a3b3120,0x2e3436662e6e722e,0x6466250920323375\n"
".quad 0x317225202c333332,0x706372090a3b3630,0x203436662e6e722e,0x2c34333264662509\n"
".quad 0x3b33333264662520,0x7261702e646c090a,0x09203436752e6d61,0x5b202c3331647225\n"
".quad 0x6170616475635f5f,0x6936315a5f5f6d72,0x4e4365737265766e,0x506c656e72654b44\n"
".quad 0x4f5f645f6a5f5366,0x0a3b5d7475707475,0x3436752e64646109,0x2c34316472250920\n"
".quad 0x202c333164722520,0x090a3b3131647225,0x656469772e6c756d,0x722509203233752e\n"
".quad 0x317225202c353164,0x240a3b34202c3530,0x3639365f335f744c,0x3c2f2f200a3a3433\n"
".quad 0x6f4c203e706f6f6c,0x2079646f6220706f,0x39363220656e696c,0x3109636f6c2e090a\n"
".quad 0x0a30093936320939,0x3233752e64646109,0x2c37303172250920,0x202c333031722520\n"
".quad 0x2e747663090a3b31,0x752e3436662e6e72,0x3264662509203233,0x30317225202c3533\n"
".quad 0x2e6c756d090a3b37,0x6466250920343666,0x646625202c363332,0x646625202c353332\n"
".quad 0x6f6d090a3b343332,0x2509203436662e76,0x30202c3733326466,0x3030303066663364\n"
".quad 0x3030303030303030,0x0a31202f2f093b30,0x2e65672e74657309,0x203436662e323375\n"
".quad 0x202c383031722509,0x202c363332646625,0x0a3b373332646625,0x3233732e67656e09\n"
".quad 0x2c39303172250920,0x0a3b383031722520,0x3436662e766f6d09,0x3833326466250920\n"
".quad 0x303030306430202c,0x3030303030303030,0x2f2f093b30303030,0x2e746573090a3020\n"
".quad 0x662e3233752e656c,0x3131722509203436,0x3332646625202c30,0x3332646625202c36\n"
".quad 0x2e67656e090a3b38,0x3172250920323373,0x31317225202c3131,0x622e726f090a3b30\n"
".quad 0x3131722509203233,0x3930317225202c32,0x3b3131317225202c,0x33752e766f6d090a\n"
".quad 0x3331317225092032,0x6573090a3b30202c,0x33732e71652e7074,0x2c33337025092032\n"
".quad 0x202c323131722520,0x090a3b3331317225,0x7262203333702540,0x335f744c24092061\n"
".quad 0x0a3b30393839365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39363220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333639365f,0x203436662e766f6d,0x2c39333264662509,0x3038666666643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x617262090a6e616e,0x4c240920696e752e\n"
".quad 0x3b3835325f335f74,0x365f335f744c240a,0x2f200a3a30393839,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3936\n"
".quad 0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639,0x2509203436662e76\n"
".quad 0x30202c3034326466,0x3030303065666264,0x3030303030303030,0x302d202f2f093b30\n"
".quad 0x2e646461090a352e,0x6466250920343666,0x646625202c313432,0x646625202c363332\n"
".quad 0x6261090a3b303432,0x2509203436662e73,0x25202c3234326466,0x090a3b3134326466\n"
".quad 0x203436662e766f6d,0x2c33343264662509,0x6561646633643020,0x3734316561373431\n"
".quad 0x202f2f093b316561,0x6573090a32342e30,0x36662e746c2e7074,0x2c34337025092034\n"
".quad 0x2c32343264662520,0x3b33343264662520,0x343370252140090a,0x4c24092061726220\n"
".quad 0x353630375f335f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333639365f335f74,0x09636f6c2e090a34,0x3009353231093931,0x36662e6c756d090a\n"
".quad 0x3432646625092034,0x3432646625202c34,0x3432646625202c31,0x2e766f6d090a3b31\n"
".quad 0x6466250920343666,0x346430202c353432,0x3133396430343030,0x3b64303236383262\n"
".quad 0x30352e32202f2f09,0x766f6d090a333636,0x662509203436662e,0x6430202c36343264\n"
".quad 0x3037643932333063,0x6564336134356561,0x38312d202f2f093b,0x6f6d090a3531362e\n"
".quad 0x2509203436662e76,0x30202c3734326466,0x3132623434303464,0x6636633337346332\n"
".quad 0x3134202f2f093b63,0x6d090a323139332e,0x09203436662e766f,0x202c383432646625\n"
".quad 0x3037393330636430,0x3737373337353965,0x2d202f2f093b3837,0x0a313134342e3532\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x646625202c393432,0x646625202c383432\n"
".quad 0x646625202c343432,0x616d090a3b373432,0x3436662e6e722e64,0x3035326466250920\n"
".quad 0x343432646625202c,0x393432646625202c,0x363432646625202c,0x722e64616d090a3b\n"
".quad 0x2509203436662e6e,0x25202c3135326466,0x25202c3434326466,0x25202c3035326466\n"
".quad 0x090a3b3534326466,0x203436662e6c756d,0x2c32353264662509,0x2c31343264662520\n"
".quad 0x3b31353264662520,0x36662e766f6d090a,0x3532646625092034,0x6666336430202c33\n"
".quad 0x3030303030303030,0x2f093b3030303030,0x766f6d090a31202f,0x662509203436662e\n"
".quad 0x6430202c34353264,0x3037326630323063,0x6432373035353630,0x2e382d202f2f093b\n"
".quad 0x6d090a3135333734,0x09203436662e766f,0x202c353532646625,0x3531373330346430\n"
".quad 0x3035313831393735,0x32202f2f093b6332,0x090a343338302e33,0x203436662e766f6d\n"
".quad 0x2c36353264662509,0x3035333063643020,0x6531303730666566,0x202f2f093b643735\n"
".quad 0x323236302e31322d,0x36662e766f6d090a,0x3532646625092034,0x3030346430202c37\n"
".quad 0x3530323066623039,0x2f093b3734613835,0x383033312e33202f,0x722e64616d090a33\n"
".quad 0x2509203436662e6e,0x25202c3835326466,0x25202c3735326466,0x25202c3434326466\n"
".quad 0x090a3b3635326466,0x662e6e722e64616d,0x3264662509203436,0x32646625202c3935\n"
".quad 0x32646625202c3434,0x32646625202c3835,0x64616d090a3b3535,0x203436662e6e722e\n"
".quad 0x2c30363264662509,0x2c34343264662520,0x2c39353264662520,0x3b34353264662520\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c31363264,0x6625202c34343264\n"
".quad 0x6625202c30363264,0x64090a3b33353264,0x36662e6e722e7669,0x3732646625092034\n"
".quad 0x323532646625202c,0x313632646625202c,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b32303430375f33,0x375f335f744c240a,0x2f200a3a38353630,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3936\n"
".quad 0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639,0x2509203436662e76\n"
".quad 0x30202c3236326466,0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30\n"
".quad 0x74672e7074657309,0x702509203436662e,0x32646625202c3533,0x32646625202c3134\n"
".quad 0x252140090a3b3236,0x2061726220353370,0x375f335f744c2409,0x2f200a3b30373131\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3936,0x64656c6562616c20,0x365f335f744c2420,0x6c2e090a34333639\n"
".quad 0x393409313309636f,0x766f6d090a300932,0x662509203436662e,0x6430202c33363264\n"
".quad 0x3030303030666633,0x3030303030303030,0x090a31202f2f093b,0x203436662e627573\n"
".quad 0x2c34363264662509,0x2c33363264662520,0x3b36333264662520,0x36622e766f6d090a\n"
".quad 0x313172257b092034,0x7d35313172252c34,0x343632646625202c,0x732e766f6d090a3b\n"
".quad 0x3831722509203233,0x3b3531317225202c,0x3309636f6c2e090a,0x0a30093339340931\n"
".quad 0x3436622e766f6d09,0x2c393172257b0920,0x202c7d3631317225,0x0a3b343632646625\n"
".quad 0x313309636f6c2e09,0x090a300935393409,0x203436662e766f6d,0x2c35363264662509\n"
".quad 0x3030303030643020,0x3030303030303030,0x202f2f093b303030,0x672e746573090a30\n"
".quad 0x36662e3233752e74,0x3731317225092034,0x343632646625202c,0x353632646625202c\n"
".quad 0x732e67656e090a3b,0x3131722509203233,0x3731317225202c38,0x662e766f6d090a3b\n"
".quad 0x3264662509203436,0x66376430202c3636,0x3030303030303066,0x093b303030303030\n"
".quad 0x090a666e69202f2f,0x752e746c2e746573,0x09203436662e3233,0x25202c3931317225\n"
".quad 0x25202c3436326466,0x090a3b3636326466,0x203233732e67656e,0x202c303231722509\n"
".quad 0x090a3b3931317225,0x203233622e646e61,0x202c313231722509,0x25202c3831317225\n"
".quad 0x6d090a3b30323172,0x09203233752e766f,0x30202c3232317225,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x7225202c36337025,0x317225202c313231,0x702540090a3b3232\n"
".quad 0x0920617262203633,0x37345f335f744c24,0x2f2f200a3b323633,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x39365f335f744c24,0x766f6d090a343336,0x722509203233752e\n"
".quad 0x343031202c333231,0x73090a3b35373538,0x752e74672e707465,0x3733702509203233\n"
".quad 0x2c3531317225202c,0x0a3b333231722520,0x6220373370254009,0x5f744c2409206172\n"
".quad 0x3b32383631375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3936322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333639365f33,0x313309636f6c2e09,0x090a300931303509,0x203436662e766f6d\n"
".quad 0x2c37363264662509,0x3030353334643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x6534343130382e31,0x6c756d090a36312b,0x662509203436662e,0x6625202c38363264\n"
".quad 0x6625202c34363264,0x6d090a3b37363264,0x09203436622e766f,0x252c34323172257b\n"
".quad 0x6625202c7d383172,0x2e090a3b38363264,0x3509313309636f6c,0x6f6d090a30093230\n"
".quad 0x7b09203436622e76,0x3172252c39317225,0x646625202c7d3532,0x6f6d090a3b383632\n"
".quad 0x2509203233732e76,0x30312d202c303372,0x617262090a3b3737,0x4c240920696e752e\n"
".quad 0x323431375f335f74,0x335f744c240a3b36,0x0a3a32383631375f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f,0x203233732e766f6d\n"
".quad 0x2d202c3033722509,0x4c240a3b33323031,0x323431375f335f74,0x6c3c2f2f200a3a36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333639365f335f74,0x09636f6c2e090a34\n"
".quad 0x3009373035093133,0x33732e726873090a,0x3632317225092032,0x202c38317225202c\n"
".quad 0x646461090a3b3032,0x722509203233732e,0x30337225202c3033,0x3b3632317225202c\n"
".quad 0x3309636f6c2e090a,0x0a30093930350931,0x3233622e646e6109,0x202c323372250920\n"
".quad 0x322d202c38317225,0x3730353334363431,0x622e726f090a3b33,0x3333722509203233\n"
".quad 0x202c32337225202c,0x3233393632373031,0x766f6d090a3b3834,0x662509203436622e\n"
".quad 0x72257b202c353364,0x7d333372252c3931,0x752e766f6d090a3b,0x3231722509203233\n"
".quad 0x3133373031202c37,0x090a3b3238353732,0x2e656c2e70746573,0x3370250920323375\n"
".quad 0x2c33337225202c38,0x0a3b373231722520,0x6220383370254009,0x5f744c2409206172\n"
".quad 0x3b38333931375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3936322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333639365f33,0x313309636f6c2e09,0x090a300931313509,0x203436622e766f6d\n"
".quad 0x2c38323172257b09,0x202c7d3932317225,0x090a3b3533646625,0x203233732e627573\n"
".quad 0x202c303331722509,0x31202c3932317225,0x0a3b363735383430,0x3436622e766f6d09\n"
".quad 0x31333172257b0920,0x2c7d32333172252c,0x0a3b353364662520,0x3436622e766f6d09\n"
".quad 0x2c35336466250920,0x2c31333172257b20,0x0a3b7d3033317225,0x313309636f6c2e09\n"
".quad 0x090a300932313509,0x203233732e646461,0x25202c3033722509,0x0a3b31202c303372\n"
".quad 0x31375f335f744c24,0x2f2f200a3a383339,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x39365f335f744c24,0x6f6c2e090a343336,0x3831350931330963,0x2e766f6d090a3009\n"
".quad 0x6466250920343666,0x626430202c393632,0x3030303030306666,0x3b30303030303030\n"
".quad 0x090a312d202f2f09,0x203436662e646461,0x202c373364662509,0x25202c3533646625\n"
".quad 0x090a3b3936326466,0x203436662e766f6d,0x2c30373264662509,0x3030666633643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x662e646461090a31,0x3364662509203436\n"
".quad 0x3533646625202c39,0x303732646625202c,0x722e747663090a3b,0x36662e3233662e6e\n"
".quad 0x202c326625092034,0x090a3b3933646625,0x727070612e706372,0x09203233662e786f\n"
".quad 0x326625202c386625,0x662e747663090a3b,0x09203233662e3436,0x25202c3034646625\n"
".quad 0x67656e090a3b3866,0x662509203436662e,0x6625202c31373264,0x6f6d090a3b393364\n"
".quad 0x2509203436662e76,0x30202c3237326466,0x3030303066663364,0x3030303030303030\n"
".quad 0x0a31202f2f093b30,0x2e6e722e64616d09,0x6466250920343666,0x32646625202c3334\n"
".quad 0x34646625202c3137,0x3732646625202c30,0x2e64616d090a3b32,0x09203436662e6e72\n"
".quad 0x25202c3434646625,0x6625202c33346466,0x646625202c333464,0x64616d090a3b3334\n"
".quad 0x203436662e6e722e,0x202c353464662509,0x25202c3434646625,0x6625202c30346466\n"
".quad 0x756d090a3b303464,0x2509203436662e6c,0x6625202c36346466,0x646625202c373364\n"
".quad 0x6f6c2e090a3b3534,0x3832350931330963,0x2e646461090a3009,0x6466250920343666\n"
".quad 0x34646625202c3734,0x3634646625202c36,0x662e6c756d090a3b,0x3464662509203436\n"
".quad 0x3734646625202c38,0x3b3734646625202c,0x36662e766f6d090a,0x3732646625092034\n"
".quad 0x6265336430202c33,0x6561336230383331,0x2f093b6531663038,0x333632302e31202f\n"
".quad 0x6d090a36302d6533,0x09203436662e766f,0x202c343732646625,0x6565306465336430\n"
".quad 0x6238613762383532,0x34202f2f093b3430,0x2d6539343633302e,0x2e64616d090a3630\n"
".quad 0x09203436662e6e72,0x202c353732646625,0x202c333732646625,0x25202c3834646625\n"
".quad 0x090a3b3437326466,0x203436662e766f6d,0x2c36373264662509,0x6233666533643020\n"
".quad 0x3632306639363632,0x202f2f093b663637,0x6534343837382e31,0x64616d090a35302d\n"
".quad 0x203436662e6e722e,0x2c37373264662509,0x2c35373264662520,0x202c383464662520\n"
".quad 0x0a3b363732646625,0x3436662e766f6d09,0x3837326466250920,0x373166336430202c\n"
".quad 0x6261396162633534,0x2f2f093b36353930,0x31383737382e3820,0x616d090a35302d65\n"
".quad 0x3436662e6e722e64,0x3937326466250920,0x373732646625202c,0x2c3834646625202c\n"
".quad 0x3b38373264662520,0x36662e766f6d090a,0x3832646625092034,0x3366336430202c30\n"
".quad 0x3164323763313763,0x2f093b3435313562,0x343030302e30202f,0x6d090a3832303433\n"
".quad 0x36662e6e722e6461,0x3832646625092034,0x3732646625202c31,0x3834646625202c39\n"
".quad 0x303832646625202c,0x662e766f6d090a3b,0x3264662509203436,0x66336430202c3238\n"
".quad 0x3239343239343236,0x093b643237656233,0x3230302e30202f2f,0x6d090a3431323332\n"
".quad 0x36662e6e722e6461,0x3832646625092034,0x3832646625202c33,0x3834646625202c31\n"
".quad 0x323832646625202c,0x662e766f6d090a3b,0x3264662509203436,0x66336430202c3438\n"
".quad 0x3939393939393938,0x093b346333613939,0x3231302e30202f2f,0x722e64616d090a35\n"
".quad 0x2509203436662e6e,0x25202c3538326466,0x25202c3338326466,0x6625202c38346466\n"
".quad 0x2e090a3b34383264,0x3509313309636f6c,0x6f6d090a30093932,0x2509203436662e76\n"
".quad 0x30202c3638326466,0x3535353562663364,0x3535353535353535,0x2e30202f2f093b34\n"
".quad 0x0a33333333333830,0x2e6e722e64616d09,0x6466250920343666,0x646625202c373832\n"
".quad 0x646625202c353832,0x32646625202c3834,0x6f6c2e090a3b3638,0x3233350931330963\n"
".quad 0x2e627573090a3009,0x6466250920343666,0x33646625202c3436,0x3734646625202c37\n"
".quad 0x662e67656e090a3b,0x3264662509203436,0x34646625202c3838,0x2e646461090a3b37\n"
".quad 0x6466250920343666,0x646625202c393832,0x36646625202c3436,0x2e64616d090a3b34\n"
".quad 0x09203436662e6e72,0x202c303932646625,0x202c383832646625,0x25202c3733646625\n"
".quad 0x090a3b3938326466,0x203436662e6c756d,0x202c383664662509,0x25202c3534646625\n"
".quad 0x090a3b3039326466,0x09313309636f6c2e,0x6d090a3009353335,0x09203436662e6c75\n"
".quad 0x202c313932646625,0x25202c3834646625,0x090a3b3738326466,0x203436662e6c756d\n"
".quad 0x202c303764662509,0x25202c3734646625,0x090a3b3139326466,0x662e6e722e747663\n"
".quad 0x09203233732e3436,0x25202c3137646625,0x6f6d090a3b303372,0x2509203436662e76\n"
".quad 0x30202c3239326466,0x3465323665663364,0x6539336166656632,0x2e30202f2f093b66\n"
".quad 0x090a373431333936,0x662e6e722e64616d,0x3764662509203436,0x3137646625202c33\n"
".quad 0x323932646625202c,0x3b3734646625202c,0x36662e766f6d090a,0x3932646625092034\n"
".quad 0x3763336430202c33,0x3362336539636261,0x2f093b6633303839,0x303931332e32202f\n"
".quad 0x61090a37312d6535,0x09203436662e6464,0x202c343932646625,0x25202c3037646625\n"
".quad 0x6e090a3b38366466,0x09203233732e6765,0x25202c3333317225,0x7663090a3b303372\n"
".quad 0x3436662e6e722e74,0x662509203233732e,0x7225202c35393264,0x6f6d090a3b333331\n"
".quad 0x2509203436662e76,0x30202c3639326466,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3264662509203436\n"
".quad 0x32646625202c3739,0x32646625202c3539,0x37646625202c3639,0x2e627573090a3b33\n"
".quad 0x6466250920343666,0x646625202c383932,0x646625202c373932,0x627573090a3b3734\n"
".quad 0x662509203436662e,0x6625202c39393264,0x6625202c34393264,0x6d090a3b38393264\n"
".quad 0x36662e6e722e6461,0x3033646625092034,0x3137646625202c30,0x333932646625202c\n"
".quad 0x393932646625202c,0x662e646461090a3b,0x3864662509203436,0x3337646625202c32\n"
".quad 0x303033646625202c,0x752e617262090a3b,0x5f744c240920696e,0x0a3b383335315f33\n"
".quad 0x37345f335f744c24,0x2f2f200a3a323633,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x39365f335f744c24,0x6f6c2e090a343336,0x3834350931330963,0x2e736261090a3009\n"
".quad 0x6466250920343666,0x646625202c313033,0x6f6d090a3b343632,0x2509203436662e76\n"
".quad 0x30202c3230336466,0x3030303066663764,0x3030303030303030,0x6e69202f2f093b30\n"
".quad 0x2e70746573090a66,0x09203436662e656c,0x6625202c39337025,0x6625202c31303364\n"
".quad 0x40090a3b32303364,0x6172622039337025,0x5f335f744c240920,0x200a3b3035343237\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c393632,0x656c6562616c2064,0x5f335f744c242064,0x61090a3433363936\n"
".quad 0x09203436662e6464,0x25202c3238646625,0x25202c3436326466,0x090a3b3436326466\n"
".quad 0x20696e752e617262,0x315f335f744c2409,0x744c240a3b383335,0x30353432375f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363220656e,0x62616c2064616568,0x744c242064656c65,0x34333639365f335f\n"
".quad 0x36662e766f6d090a,0x3033646625092034,0x3030306430202c33,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x746573090a30202f,0x3436662e71652e70,0x202c303470250920\n"
".quad 0x202c343632646625,0x0a3b333033646625,0x2030347025214009,0x744c240920617262\n"
".quad 0x32363932375f335f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c39363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333639365f335f,0x36662e766f6d090a,0x3238646625092034,0x306666666430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x62090a666e692d20,0x0920696e752e6172\n"
".quad 0x35315f335f744c24,0x5f744c240a3b3833,0x3a32363932375f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3936322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33,0x3436662e766f6d09\n"
".quad 0x3430336466250920,0x306666376430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x6573090a666e6920,0x36662e71652e7074,0x2c31347025092034,0x2c34363264662520\n"
".quad 0x3b34303364662520,0x313470252140090a,0x4c24092061726220,0x373433375f335f74\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x662e766f6d090a34,0x3864662509203436,0x3632646625202c32,0x2e617262090a3b34\n"
".quad 0x744c240920696e75,0x3b383335315f335f,0x375f335f744c240a,0x2f200a3a34373433\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3936,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203436662e76,0x6430202c32386466,0x3030303038666666,0x3030303030303030\n"
".quad 0x6e616e202f2f093b,0x315f335f744c240a,0x2f2f200a3a383335,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336,0x3239340931330963\n"
".quad 0x2e67656e090a3009,0x6466250920343666,0x646625202c353033,0x766f6d090a3b3238\n"
".quad 0x257b09203436622e,0x3172252c34333172,0x646625202c7d3533,0x6f6d090a3b353033\n"
".quad 0x2509203233732e76,0x317225202c383172,0x6f6c2e090a3b3533,0x3339340931330963\n"
".quad 0x2e766f6d090a3009,0x72257b0920343662,0x36333172252c3931,0x3033646625202c7d\n"
".quad 0x636f6c2e090a3b35,0x0935393409313309,0x662e766f6d090a30,0x3364662509203436\n"
".quad 0x30306430202c3630,0x3030303030303030,0x093b303030303030,0x6573090a30202f2f\n"
".quad 0x3233752e74672e74,0x722509203436662e,0x646625202c373331,0x646625202c353033\n"
".quad 0x656e090a3b363033,0x2509203233732e67,0x7225202c38333172,0x6f6d090a3b373331\n"
".quad 0x2509203436662e76,0x30202c3730336466,0x3030303066663764,0x3030303030303030\n"
".quad 0x6e69202f2f093b30,0x6c2e746573090a66,0x36662e3233752e74,0x3933317225092034\n"
".quad 0x353033646625202c,0x373033646625202c,0x732e67656e090a3b,0x3431722509203233\n"
".quad 0x3933317225202c30,0x622e646e61090a3b,0x3431722509203233,0x3833317225202c31\n"
".quad 0x3b3034317225202c,0x33752e766f6d090a,0x3234317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c32347025092032,0x202c313431722520,0x090a3b3234317225\n"
".quad 0x7262203234702540,0x335f744c24092061,0x0a3b38393838345f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f,0x203233752e766f6d\n"
".quad 0x202c333431722509,0x3b35373538343031,0x672e70746573090a,0x2509203233752e74\n"
".quad 0x317225202c333470,0x34317225202c3533,0x34702540090a3b33,0x2409206172622033\n"
".quad 0x3234375f335f744c,0x3c2f2f200a3b3234,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39363220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3639365f335f744c,0x636f6c2e090a3433,0x0931303509313309,0x662e766f6d090a30\n"
".quad 0x3364662509203436,0x33346430202c3830,0x3030303030303035,0x093b303030303030\n"
".quad 0x3130382e31202f2f,0x090a36312b653434,0x203436662e6c756d,0x2c39303364662509\n"
".quad 0x2c35303364662520,0x3b38303364662520,0x36622e766f6d090a,0x343172257b092034\n"
".quad 0x2c7d383172252c34,0x3b39303364662520,0x3309636f6c2e090a,0x0a30093230350931\n"
".quad 0x3436622e766f6d09,0x2c393172257b0920,0x202c7d3534317225,0x0a3b393033646625\n"
".quad 0x3233732e766f6d09,0x202c303372250920,0x090a3b373730312d,0x20696e752e617262\n"
".quad 0x375f335f744c2409,0x4c240a3b36383933,0x343234375f335f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333639365f335f74,0x732e766f6d090a34\n"
".quad 0x3033722509203233,0x3b333230312d202c,0x375f335f744c240a,0x2f200a3a36383933\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3936,0x64656c6562616c20,0x365f335f744c2420,0x6c2e090a34333639\n"
".quad 0x303509313309636f,0x726873090a300937,0x722509203233732e,0x317225202c363431\n"
".quad 0x090a3b3032202c38,0x203233732e646461,0x25202c3033722509,0x317225202c303372\n"
".quad 0x6f6c2e090a3b3634,0x3930350931330963,0x2e646e61090a3009,0x3372250920323362\n"
".quad 0x2c38317225202c32,0x3334363431322d20,0x6f090a3b33373035,0x2509203233622e72\n"
".quad 0x337225202c333372,0x3632373031202c32,0x090a3b3834323339,0x203436622e766f6d\n"
".quad 0x202c353364662509,0x72252c393172257b,0x6f6d090a3b7d3333,0x2509203233752e76\n"
".quad 0x3031202c37343172,0x3238353732313337,0x2e70746573090a3b,0x09203233752e656c\n"
".quad 0x7225202c34347025,0x34317225202c3333,0x34702540090a3b37,0x2409206172622034\n"
".quad 0x3434375f335f744c,0x3c2f2f200a3b3839,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39363220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3639365f335f744c,0x636f6c2e090a3433,0x0931313509313309,0x622e766f6d090a30\n"
".quad 0x3172257b09203436,0x39343172252c3834,0x3533646625202c7d,0x732e627573090a3b\n"
".quad 0x3531722509203233,0x3934317225202c30,0x373538343031202c,0x2e766f6d090a3b36\n"
".quad 0x72257b0920343662,0x353172252c313531,0x33646625202c7d32,0x2e766f6d090a3b35\n"
".quad 0x6466250920343662,0x3172257b202c3533,0x30353172252c3135,0x636f6c2e090a3b7d\n"
".quad 0x0932313509313309,0x732e646461090a30,0x3033722509203233,0x202c30337225202c\n"
".quad 0x335f744c240a3b31,0x0a3a38393434375f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a34333639365f,0x09313309636f6c2e,0x6d090a3009383135\n"
".quad 0x09203436662e766f,0x202c303133646625,0x3030306666626430,0x3030303030303030\n"
".quad 0x2d202f2f093b3030,0x662e646461090a31,0x3364662509203436,0x3533646625202c37\n"
".quad 0x303133646625202c,0x662e766f6d090a3b,0x3364662509203436,0x66336430202c3131\n"
".quad 0x3030303030303066,0x093b303030303030,0x6461090a31202f2f,0x2509203436662e64\n"
".quad 0x6625202c39336466,0x646625202c353364,0x7663090a3b313133,0x3233662e6e722e74\n"
".quad 0x662509203436662e,0x3933646625202c32,0x612e706372090a3b,0x33662e786f727070\n"
".quad 0x202c396625092032,0x7663090a3b326625,0x33662e3436662e74,0x3034646625092032\n"
".quad 0x090a3b396625202c,0x203436662e67656e,0x2c32313364662509,0x0a3b393364662520\n"
".quad 0x3436662e766f6d09,0x3331336466250920,0x306666336430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x2e64616d090a3120,0x09203436662e6e72,0x25202c3334646625\n"
".quad 0x25202c3231336466,0x6625202c30346466,0x6d090a3b33313364,0x36662e6e722e6461\n"
".quad 0x3434646625092034,0x2c3334646625202c,0x202c333464662520,0x090a3b3334646625\n"
".quad 0x662e6e722e64616d,0x3464662509203436,0x3434646625202c35,0x2c3034646625202c\n"
".quad 0x0a3b303464662520,0x3436662e6c756d09,0x2c36346466250920,0x202c373364662520\n"
".quad 0x090a3b3534646625,0x09313309636f6c2e,0x61090a3009383235,0x09203436662e6464\n"
".quad 0x25202c3734646625,0x6625202c36346466,0x756d090a3b363464,0x2509203436662e6c\n"
".quad 0x6625202c38346466,0x646625202c373464,0x766f6d090a3b3734,0x662509203436662e\n"
".quad 0x6430202c34313364,0x6230383331626533,0x6531663038656133,0x302e31202f2f093b\n"
".quad 0x36302d6533333632,0x36662e766f6d090a,0x3133646625092034,0x6465336430202c35\n"
".quad 0x3762383532656530,0x2f093b3430623861,0x343633302e34202f,0x6d090a36302d6539\n"
".quad 0x36662e6e722e6461,0x3133646625092034,0x3133646625202c36,0x3834646625202c34\n"
".quad 0x353133646625202c,0x662e766f6d090a3b,0x3364662509203436,0x65336430202c3731\n"
".quad 0x6639363632623366,0x093b663637363230,0x3837382e31202f2f,0x090a35302d653434\n"
".quad 0x662e6e722e64616d,0x3364662509203436,0x33646625202c3831,0x34646625202c3631\n"
".quad 0x3133646625202c38,0x2e766f6d090a3b37,0x6466250920343666,0x336430202c393133\n"
".quad 0x6162633534373166,0x3b36353930626139,0x37382e38202f2f09,0x0a35302d65313837\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x646625202c303233,0x646625202c383133\n"
".quad 0x33646625202c3834,0x766f6d090a3b3931,0x662509203436662e,0x6430202c31323364\n"
".quad 0x3763313763336633,0x3435313562316432,0x302e30202f2f093b,0x3832303433343030\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c32323364,0x6625202c30323364\n"
".quad 0x646625202c383464,0x6f6d090a3b313233,0x2509203436662e76,0x30202c3332336466\n"
".quad 0x3239343236663364,0x3237656233323934,0x2e30202f2f093b64,0x3431323332323030\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c34323364,0x6625202c32323364\n"
".quad 0x646625202c383464,0x6f6d090a3b333233,0x2509203436662e76,0x30202c3532336466\n"
".quad 0x3939393938663364,0x6333613939393939,0x2e30202f2f093b34,0x616d090a35323130\n"
".quad 0x3436662e6e722e64,0x3632336466250920,0x343233646625202c,0x2c3834646625202c\n"
".quad 0x3b35323364662520,0x3309636f6c2e090a,0x0a30093932350931,0x3436662e766f6d09\n"
".quad 0x3732336466250920,0x356266336430202c,0x3535353535353535,0x2f2f093b34353535\n"
".quad 0x33333338302e3020,0x2e64616d090a3333,0x09203436662e6e72,0x202c383233646625\n"
".quad 0x202c363233646625,0x25202c3834646625,0x090a3b3732336466,0x09313309636f6c2e\n"
".quad 0x73090a3009323335,0x09203436662e6275,0x25202c3436646625,0x6625202c37336466\n"
".quad 0x656e090a3b373464,0x2509203436662e67,0x25202c3932336466,0x61090a3b37346466\n"
".quad 0x09203436662e6464,0x202c303333646625,0x25202c3436646625,0x6d090a3b34366466\n"
".quad 0x36662e6e722e6461,0x3333646625092034,0x3233646625202c31,0x3733646625202c39\n"
".quad 0x303333646625202c,0x662e6c756d090a3b,0x3664662509203436,0x3534646625202c38\n"
".quad 0x313333646625202c,0x09636f6c2e090a3b,0x3009353335093133,0x36662e6c756d090a\n"
".quad 0x3333646625092034,0x3834646625202c32,0x383233646625202c,0x662e6c756d090a3b\n"
".quad 0x3764662509203436,0x3734646625202c30,0x323333646625202c,0x722e747663090a3b\n"
".quad 0x33732e3436662e6e,0x3137646625092032,0x0a3b30337225202c,0x3436662e766f6d09\n"
".quad 0x3333336466250920,0x366566336430202c,0x6166656632346532,0x2f2f093b66653933\n"
".quad 0x34313339362e3020,0x722e64616d090a37,0x2509203436662e6e,0x6625202c33376466\n"
".quad 0x646625202c313764,0x646625202c333333,0x766f6d090a3b3734,0x662509203436662e\n"
".quad 0x6430202c34333364,0x6539636261376333,0x6633303839336233,0x332e32202f2f093b\n"
".quad 0x37312d6535303931,0x36662e646461090a,0x3333646625092034,0x3037646625202c35\n"
".quad 0x3b3836646625202c,0x33732e67656e090a,0x3335317225092032,0x0a3b30337225202c\n"
".quad 0x2e6e722e74766309,0x203233732e343666,0x2c36333364662509,0x0a3b333531722520\n"
".quad 0x3436662e766f6d09,0x3733336466250920,0x366566336430202c,0x6166656632346532\n"
".quad 0x2f2f093b66653933,0x34313339362e3020,0x722e64616d090a37,0x2509203436662e6e\n"
".quad 0x25202c3833336466,0x25202c3633336466,0x25202c3733336466,0x73090a3b33376466\n"
".quad 0x09203436662e6275,0x202c393333646625,0x202c383333646625,0x090a3b3734646625\n"
".quad 0x203436662e627573,0x2c30343364662509,0x2c35333364662520,0x3b39333364662520\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c31343364,0x646625202c313764\n"
".quad 0x646625202c343333,0x6461090a3b303433,0x2509203436662e64,0x25202c3432316466\n"
".quad 0x6625202c33376466,0x62090a3b31343364,0x0920696e752e6172,0x30325f335f744c24\n"
".quad 0x5f744c240a3b3035,0x3a38393838345f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3936322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09,0x090a300938343509\n"
".quad 0x203436662e736261,0x2c32343364662509,0x0a3b323864662520,0x3436662e766f6d09\n"
".quad 0x3334336466250920,0x306666376430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x6573090a666e6920,0x36662e656c2e7074,0x2c35347025092034,0x2c32343364662520\n"
".quad 0x3b33343364662520,0x203534702540090a,0x744c240920617262,0x30313035375f335f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363220656e,0x62616c2064616568,0x744c242064656c65,0x34333639365f335f\n"
".quad 0x36662e646461090a,0x3433646625092034,0x3238646625202c34,0x3b3238646625202c\n"
".quad 0x36662e67656e090a,0x3231646625092034,0x3433646625202c34,0x2e617262090a3b34\n"
".quad 0x744c240920696e75,0x3b303530325f335f,0x375f335f744c240a,0x2f200a3a30313035\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3936,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203436662e76,0x30202c3534336466,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x71652e7074657309,0x702509203436662e,0x33646625202c3634\n"
".quad 0x33646625202c3530,0x252140090a3b3534,0x2061726220363470,0x375f335f744c2409\n"
".quad 0x2f200a3b32323535,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3936,0x64656c6562616c20,0x365f335f744c2420\n"
".quad 0x6f6d090a34333639,0x2509203436662e76,0x30202c3432316466,0x3030303066666664\n"
".quad 0x3030303030303030,0x692d202f2f093b30,0x2e617262090a666e,0x744c240920696e75\n"
".quad 0x3b303530325f335f,0x375f335f744c240a,0x2f200a3a32323535,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3936\n"
".quad 0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639,0x2509203436662e76\n"
".quad 0x30202c3634336466,0x3030303066663764,0x3030303030303030,0x6e69202f2f093b30\n"
".quad 0x2e70746573090a66,0x09203436662e7165,0x6625202c37347025,0x6625202c35303364\n"
".quad 0x40090a3b36343364,0x7262203734702521,0x335f744c24092061,0x0a3b34333036375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f\n"
".quad 0x203436662e766f6d,0x2c34323164662509,0x3b35303364662520,0x6e752e617262090a\n"
".quad 0x335f744c24092069,0x240a3b303530325f,0x3036375f335f744c,0x3c2f2f200a3a3433\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433\n"
".quad 0x6466250920343666,0x666430202c343231,0x3030303030386666,0x3b30303030303030\n"
".quad 0x0a6e616e202f2f09,0x30325f335f744c24,0x3c2f2f200a3a3035,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x39363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3639365f335f744c,0x636f6c2e090a3433,0x0938323109393109\n"
".quad 0x662e766f6d090a30,0x3264662509203436,0x3231646625202c37,0x2e617262090a3b34\n"
".quad 0x744c240920696e75,0x34313930375f335f,0x5f335f744c240a3b,0x200a3a3037313137\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c393632,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433363936\n"
".quad 0x3409313309636f6c,0x6f6d090a30093239,0x7b09203436622e76,0x72252c3435317225\n"
".quad 0x6625202c7d353531,0x6d090a3b36333264,0x09203233732e766f,0x7225202c38317225\n"
".quad 0x6c2e090a3b353531,0x393409313309636f,0x766f6d090a300933,0x257b09203436622e\n"
".quad 0x353172252c393172,0x32646625202c7d36,0x6f6c2e090a3b3633,0x3539340931330963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x306430202c373433,0x3030303030303030\n"
".quad 0x3b30303030303030,0x73090a30202f2f09,0x33752e74672e7465,0x2509203436662e32\n"
".quad 0x6625202c37353172,0x6625202c36333264,0x6e090a3b37343364,0x09203233732e6765\n"
".quad 0x25202c3835317225,0x6d090a3b37353172,0x09203436662e766f,0x202c383433646625\n"
".quad 0x3030306666376430,0x3030303030303030,0x69202f2f093b3030,0x2e746573090a666e\n"
".quad 0x662e3233752e746c,0x3531722509203436,0x3332646625202c39,0x3433646625202c36\n"
".quad 0x2e67656e090a3b38,0x3172250920323373,0x35317225202c3036,0x2e646e61090a3b39\n"
".quad 0x3172250920323362,0x35317225202c3136,0x3036317225202c38,0x752e766f6d090a3b\n"
".quad 0x3631722509203233,0x73090a3b30202c32,0x732e71652e707465,0x3834702509203233\n"
".quad 0x2c3136317225202c,0x0a3b323631722520,0x6220383470254009,0x5f744c2409206172\n"
".quad 0x3b34333430355f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3936322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333639365f33,0x3233752e766f6d09,0x2c33363172250920,0x3537353834303120\n"
".quad 0x2e70746573090a3b,0x09203233752e7467,0x7225202c39347025,0x317225202c353531\n"
".quad 0x702540090a3b3336,0x0920617262203934,0x36375f335f744c24,0x2f2f200a3b323038\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336\n"
".quad 0x3130350931330963,0x2e766f6d090a3009,0x6466250920343666,0x346430202c393433\n"
".quad 0x3030303030303533,0x3b30303030303030,0x30382e31202f2f09,0x0a36312b65343431\n"
".quad 0x3436662e6c756d09,0x3035336466250920,0x363332646625202c,0x393433646625202c\n"
".quad 0x622e766f6d090a3b,0x3172257b09203436,0x7d383172252c3436,0x303533646625202c\n"
".quad 0x09636f6c2e090a3b,0x3009323035093133,0x36622e766f6d090a,0x393172257b092034\n"
".quad 0x2c7d35363172252c,0x3b30353364662520,0x33732e766f6d090a,0x2c30337225092032\n"
".quad 0x0a3b373730312d20,0x696e752e61726209,0x5f335f744c240920,0x240a3b3634353637\n"
".quad 0x3836375f335f744c,0x3c2f2f200a3a3230,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39363220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3639365f335f744c,0x2e766f6d090a3433,0x3372250920323373,0x333230312d202c30\n"
".quad 0x5f335f744c240a3b,0x200a3a3634353637,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x2e090a3433363936,0x3509313309636f6c,0x6873090a30093730\n"
".quad 0x2509203233732e72,0x7225202c36363172,0x0a3b3032202c3831,0x3233732e64646109\n"
".quad 0x202c303372250920,0x7225202c30337225,0x6c2e090a3b363631,0x303509313309636f\n"
".quad 0x646e61090a300939,0x722509203233622e,0x38317225202c3233,0x34363431322d202c\n"
".quad 0x090a3b3337303533,0x09203233622e726f,0x7225202c33337225,0x32373031202c3233\n"
".quad 0x0a3b383432333936,0x3436622e766f6d09,0x2c35336466250920,0x252c393172257b20\n"
".quad 0x6d090a3b7d333372,0x09203233752e766f,0x31202c3736317225,0x3835373231333730\n"
".quad 0x70746573090a3b32,0x203233752e656c2e,0x25202c3035702509,0x317225202c333372\n"
".quad 0x702540090a3b3736,0x0920617262203035,0x37375f335f744c24,0x2f2f200a3b383530\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336\n"
".quad 0x3131350931330963,0x2e766f6d090a3009,0x72257b0920343662,0x363172252c383631\n"
".quad 0x33646625202c7d39,0x2e627573090a3b35,0x3172250920323373,0x36317225202c3037\n"
".quad 0x3538343031202c39,0x766f6d090a3b3637,0x257b09203436622e,0x3172252c31373172\n"
".quad 0x646625202c7d3237,0x766f6d090a3b3533,0x662509203436622e,0x72257b202c353364\n"
".quad 0x373172252c313731,0x6f6c2e090a3b7d30,0x3231350931330963,0x2e646461090a3009\n"
".quad 0x3372250920323373,0x2c30337225202c30,0x5f744c240a3b3120,0x3a38353037375f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3936322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33\n"
".quad 0x313309636f6c2e09,0x090a300938313509,0x203436662e766f6d,0x2c31353364662509\n"
".quad 0x3030666662643020,0x3030303030303030,0x202f2f093b303030,0x2e646461090a312d\n"
".quad 0x6466250920343666,0x33646625202c3733,0x3533646625202c35,0x2e766f6d090a3b31\n"
".quad 0x6466250920343666,0x336430202c323533,0x3030303030306666,0x3b30303030303030\n"
".quad 0x61090a31202f2f09,0x09203436662e6464,0x25202c3933646625,0x6625202c35336466\n"
".quad 0x63090a3b32353364,0x33662e6e722e7476,0x2509203436662e32,0x33646625202c3266\n"
".quad 0x2e706372090a3b39,0x662e786f72707061,0x3031662509203233,0x090a3b326625202c\n"
".quad 0x2e3436662e747663,0x6466250920323366,0x30316625202c3034,0x662e67656e090a3b\n"
".quad 0x3364662509203436,0x33646625202c3335,0x2e766f6d090a3b39,0x6466250920343666\n"
".quad 0x336430202c343533,0x3030303030306666,0x3b30303030303030,0x6d090a31202f2f09\n"
".quad 0x36662e6e722e6461,0x3334646625092034,0x333533646625202c,0x2c3034646625202c\n"
".quad 0x3b34353364662520,0x6e722e64616d090a,0x662509203436662e,0x646625202c343464\n"
".quad 0x34646625202c3334,0x3334646625202c33,0x722e64616d090a3b,0x2509203436662e6e\n"
".quad 0x6625202c35346466,0x646625202c343464,0x34646625202c3034,0x2e6c756d090a3b30\n"
".quad 0x6466250920343666,0x33646625202c3634,0x3534646625202c37,0x09636f6c2e090a3b\n"
".quad 0x3009383235093133,0x36662e646461090a,0x3734646625092034,0x2c3634646625202c\n"
".quad 0x0a3b363464662520,0x3436662e6c756d09,0x2c38346466250920,0x202c373464662520\n"
".quad 0x090a3b3734646625,0x203436662e766f6d,0x2c35353364662509,0x3331626533643020\n"
".quad 0x3038656133623038,0x202f2f093b653166,0x6533333632302e31,0x766f6d090a36302d\n"
".quad 0x662509203436662e,0x6430202c36353364,0x3532656530646533,0x3430623861376238\n"
".quad 0x302e34202f2f093b,0x36302d6539343633,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x6625202c37353364,0x6625202c35353364,0x646625202c383464,0x6f6d090a3b363533\n"
".quad 0x2509203436662e76,0x30202c3835336466,0x3632623366653364,0x3637363230663936\n"
".quad 0x2e31202f2f093b66,0x302d653434383738,0x722e64616d090a35,0x2509203436662e6e\n"
".quad 0x25202c3935336466,0x25202c3735336466,0x6625202c38346466,0x6d090a3b38353364\n"
".quad 0x09203436662e766f,0x202c303633646625,0x3534373166336430,0x3930626139616263\n"
".quad 0x38202f2f093b3635,0x2d6531383737382e,0x2e64616d090a3530,0x09203436662e6e72\n"
".quad 0x202c313633646625,0x202c393533646625,0x25202c3834646625,0x090a3b3036336466\n"
".quad 0x203436662e766f6d,0x2c32363364662509,0x3763336633643020,0x3562316432376331\n"
".quad 0x202f2f093b343531,0x3433343030302e30,0x64616d090a383230,0x203436662e6e722e\n"
".quad 0x2c33363364662509,0x2c31363364662520,0x202c383464662520,0x0a3b323633646625\n"
".quad 0x3436662e766f6d09,0x3436336466250920,0x323666336430202c,0x6233323934323934\n"
".quad 0x2f2f093b64323765,0x33323230302e3020,0x64616d090a343132,0x203436662e6e722e\n"
".quad 0x2c35363364662509,0x2c33363364662520,0x202c383464662520,0x0a3b343633646625\n"
".quad 0x3436662e766f6d09,0x3636336466250920,0x393866336430202c,0x3939393939393939\n"
".quad 0x2f2f093b34633361,0x0a353231302e3020,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x646625202c373633,0x646625202c353633,0x33646625202c3834,0x6f6c2e090a3b3636\n"
".quad 0x3932350931330963,0x2e766f6d090a3009,0x6466250920343666,0x336430202c383633\n"
".quad 0x3535353535356266,0x3b34353535353535,0x38302e30202f2f09,0x6d090a3333333333\n"
".quad 0x36662e6e722e6461,0x3633646625092034,0x3633646625202c39,0x3834646625202c37\n"
".quad 0x383633646625202c,0x09636f6c2e090a3b,0x3009323335093133,0x36662e627573090a\n"
".quad 0x3436646625092034,0x2c3733646625202c,0x0a3b373464662520,0x3436662e67656e09\n"
".quad 0x3037336466250920,0x3b3734646625202c,0x36662e646461090a,0x3733646625092034\n"
".quad 0x3436646625202c31,0x3b3436646625202c,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x6625202c32373364,0x6625202c30373364,0x646625202c373364,0x756d090a3b313733\n"
".quad 0x2509203436662e6c,0x6625202c38366466,0x646625202c353464,0x6c2e090a3b323733\n"
".quad 0x333509313309636f,0x6c756d090a300935,0x662509203436662e,0x6625202c33373364\n"
".quad 0x646625202c383464,0x756d090a3b393633,0x2509203436662e6c,0x6625202c30376466\n"
".quad 0x646625202c373464,0x7663090a3b333733,0x3436662e6e722e74,0x662509203233732e\n"
".quad 0x337225202c313764,0x2e766f6d090a3b30,0x6466250920343666,0x336430202c343733\n"
".quad 0x6632346532366566,0x3b66653933616665,0x39362e30202f2f09,0x616d090a37343133\n"
".quad 0x3436662e6e722e64,0x2c33376466250920,0x202c313764662520,0x202c343733646625\n"
".quad 0x090a3b3734646625,0x203436662e766f6d,0x2c35373364662509,0x6261376333643020\n"
".quad 0x3839336233653963,0x202f2f093b663330,0x6535303931332e32,0x646461090a37312d\n"
".quad 0x662509203436662e,0x6625202c36373364,0x646625202c303764,0x67656e090a3b3836\n"
".quad 0x722509203233732e,0x337225202c333731,0x2e747663090a3b30,0x732e3436662e6e72\n"
".quad 0x3364662509203233,0x37317225202c3737,0x2e766f6d090a3b33,0x6466250920343666\n"
".quad 0x336430202c383733,0x6632346532366566,0x3b66653933616665,0x39362e30202f2f09\n"
".quad 0x616d090a37343133,0x3436662e6e722e64,0x3937336466250920,0x373733646625202c\n"
".quad 0x383733646625202c,0x3b3337646625202c,0x36662e627573090a,0x3833646625092034\n"
".quad 0x3733646625202c30,0x3734646625202c39,0x662e627573090a3b,0x3364662509203436\n"
".quad 0x33646625202c3138,0x33646625202c3637,0x64616d090a3b3038,0x203436662e6e722e\n"
".quad 0x2c32383364662509,0x202c313764662520,0x202c353733646625,0x0a3b313833646625\n"
".quad 0x3436662e64646109,0x3636316466250920,0x2c3337646625202c,0x3b32383364662520\n"
".quad 0x6e752e617262090a,0x335f744c24092069,0x4c240a3b3431355f,0x333430355f335f74\n"
".quad 0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009383435093133,0x36662e736261090a,0x3833646625092034\n"
".quad 0x3332646625202c33,0x2e766f6d090a3b36,0x6466250920343666,0x376430202c343833\n"
".quad 0x3030303030306666,0x3b30303030303030,0x0a666e69202f2f09,0x656c2e7074657309\n"
".quad 0x702509203436662e,0x33646625202c3135,0x33646625202c3338,0x702540090a3b3438\n"
".quad 0x0920617262203135,0x37375f335f744c24,0x2f2f200a3b303735,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x39365f335f744c24,0x646461090a343336,0x662509203436662e\n"
".quad 0x6625202c36363164,0x6625202c36333264,0x62090a3b36333264,0x0920696e752e6172\n"
".quad 0x31355f335f744c24,0x335f744c240a3b34,0x0a3a30373537375f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f,0x203436662e766f6d\n"
".quad 0x2c35383364662509,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x2e70746573090a30,0x09203436662e7165,0x6625202c32357025,0x6625202c36333264\n"
".quad 0x40090a3b35383364,0x7262203235702521,0x335f744c24092061,0x0a3b32383038375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f\n"
".quad 0x203436662e766f6d,0x2c36363164662509,0x3030666666643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x7262090a666e692d,0x240920696e752e61,0x3431355f335f744c\n"
".quad 0x5f335f744c240a3b,0x200a3a3238303837,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x6d090a3433363936,0x09203436662e766f,0x202c363833646625\n"
".quad 0x3030306666376430,0x3030303030303030,0x69202f2f093b3030,0x70746573090a666e\n"
".quad 0x203436662e71652e,0x25202c3335702509,0x25202c3633326466,0x090a3b3638336466\n"
".quad 0x6220333570252140,0x5f744c2409206172,0x3b34393538375f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3936322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33,0x3436662e766f6d09\n"
".quad 0x3636316466250920,0x363332646625202c,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x240a3b3431355f33,0x3538375f335f744c,0x3c2f2f200a3a3439,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x39363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433,0x6466250920343666\n"
".quad 0x666430202c363631,0x3030303030386666,0x3b30303030303030,0x0a6e616e202f2f09\n"
".quad 0x31355f335f744c24,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333639365f335f74,0x09636f6c2e090a34,0x3009323934093133,0x36662e67656e090a\n"
".quad 0x3833646625092034,0x3631646625202c37,0x2e766f6d090a3b36,0x72257b0920343662\n"
".quad 0x373172252c343731,0x33646625202c7d35,0x766f6d090a3b3738,0x722509203233732e\n"
".quad 0x37317225202c3831,0x636f6c2e090a3b35,0x0933393409313309,0x622e766f6d090a30\n"
".quad 0x3172257b09203436,0x7d36373172252c39,0x373833646625202c,0x09636f6c2e090a3b\n"
".quad 0x3009353934093133,0x36662e766f6d090a,0x3833646625092034,0x3030306430202c38\n"
".quad 0x3030303030303030,0x2f093b3030303030,0x746573090a30202f,0x2e3233752e74672e\n"
".quad 0x3172250920343666,0x33646625202c3737,0x33646625202c3738,0x67656e090a3b3838\n"
".quad 0x722509203233732e,0x317225202c383731,0x766f6d090a3b3737,0x662509203436662e\n"
".quad 0x6430202c39383364,0x3030303030666637,0x3030303030303030,0x666e69202f2f093b\n"
".quad 0x746c2e746573090a,0x3436662e3233752e,0x2c39373172250920,0x2c37383364662520\n"
".quad 0x3b39383364662520,0x33732e67656e090a,0x3038317225092032,0x3b3937317225202c\n"
".quad 0x33622e646e61090a,0x3138317225092032,0x2c3837317225202c,0x0a3b303831722520\n"
".quad 0x3233752e766f6d09,0x2c32383172250920,0x746573090a3b3020,0x3233732e71652e70\n"
".quad 0x202c343570250920,0x25202c3138317225,0x40090a3b32383172,0x6172622034357025\n"
".quad 0x5f335f744c240920,0x200a3b3037393135,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x6d090a3433363936,0x09203233752e766f,0x31202c3338317225\n"
".quad 0x0a3b353735383430,0x74672e7074657309,0x702509203233752e,0x37317225202c3535\n"
".quad 0x3338317225202c35,0x3535702540090a3b,0x4c24092061726220,0x363339375f335f74\n"
".quad 0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009313035093133,0x36662e766f6d090a,0x3933646625092034\n"
".quad 0x3533346430202c30,0x3030303030303030,0x2f093b3030303030,0x343130382e31202f\n"
".quad 0x6d090a36312b6534,0x09203436662e6c75,0x202c313933646625,0x202c373833646625\n"
".quad 0x0a3b303933646625,0x3436622e766f6d09,0x34383172257b0920,0x202c7d383172252c\n"
".quad 0x0a3b313933646625,0x313309636f6c2e09,0x090a300932303509,0x203436622e766f6d\n"
".quad 0x252c393172257b09,0x25202c7d35383172,0x090a3b3139336466,0x203233732e766f6d\n"
".quad 0x2d202c3033722509,0x62090a3b37373031,0x0920696e752e6172,0x39375f335f744c24\n"
".quad 0x744c240a3b363031,0x32363339375f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39363220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333639365f335f,0x33732e766f6d090a,0x2c30337225092032\n"
".quad 0x0a3b333230312d20,0x39375f335f744c24,0x2f2f200a3a363031,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336,0x3730350931330963\n"
".quad 0x2e726873090a3009,0x3172250920323373,0x38317225202c3638,0x61090a3b3032202c\n"
".quad 0x09203233732e6464,0x7225202c30337225,0x38317225202c3033,0x636f6c2e090a3b36\n"
".quad 0x0939303509313309,0x622e646e61090a30,0x3233722509203233,0x202c38317225202c\n"
".quad 0x353334363431322d,0x726f090a3b333730,0x722509203233622e,0x32337225202c3333\n"
".quad 0x393632373031202c,0x6d090a3b38343233,0x09203436622e766f,0x7b202c3533646625\n"
".quad 0x3372252c39317225,0x766f6d090a3b7d33,0x722509203233752e,0x373031202c373831\n"
".quad 0x3b32383537323133,0x6c2e70746573090a,0x2509203233752e65,0x337225202c363570\n"
".quad 0x3738317225202c33,0x3635702540090a3b,0x4c24092061726220,0x313639375f335f74\n"
".quad 0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009313135093133,0x36622e766f6d090a,0x383172257b092034\n"
".quad 0x7d39383172252c38,0x3b3533646625202c,0x33732e627573090a,0x3039317225092032\n"
".quad 0x2c3938317225202c,0x3637353834303120,0x622e766f6d090a3b,0x3172257b09203436\n"
".quad 0x32393172252c3139,0x3533646625202c7d,0x622e766f6d090a3b,0x3364662509203436\n"
".quad 0x393172257b202c35,0x7d30393172252c31,0x09636f6c2e090a3b,0x3009323135093133\n"
".quad 0x33732e646461090a,0x2c30337225092032,0x31202c3033722520,0x5f335f744c240a3b\n"
".quad 0x200a3a3831363937,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c393632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3433363936,0x3509313309636f6c,0x6f6d090a30093831,0x2509203436662e76\n"
".quad 0x30202c3239336466,0x3030303066666264,0x3030303030303030,0x312d202f2f093b30\n"
".quad 0x36662e646461090a,0x3733646625092034,0x2c3533646625202c,0x3b32393364662520\n"
".quad 0x36662e766f6d090a,0x3933646625092034,0x6666336430202c33,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x646461090a31202f,0x662509203436662e,0x646625202c393364\n"
".quad 0x33646625202c3533,0x747663090a3b3339,0x2e3233662e6e722e,0x3266250920343666\n"
".quad 0x3b3933646625202c,0x70612e706372090a,0x3233662e786f7270,0x202c313166250920\n"
".quad 0x7663090a3b326625,0x33662e3436662e74,0x3034646625092032,0x0a3b31316625202c\n"
".quad 0x3436662e67656e09,0x3439336466250920,0x3b3933646625202c,0x36662e766f6d090a\n"
".quad 0x3933646625092034,0x6666336430202c35,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x64616d090a31202f,0x203436662e6e722e,0x202c333464662509,0x202c343933646625\n"
".quad 0x25202c3034646625,0x090a3b3539336466,0x662e6e722e64616d,0x3464662509203436\n"
".quad 0x3334646625202c34,0x2c3334646625202c,0x0a3b333464662520,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x34646625202c3534,0x3034646625202c34,0x3b3034646625202c\n"
".quad 0x36662e6c756d090a,0x3634646625092034,0x2c3733646625202c,0x0a3b353464662520\n"
".quad 0x313309636f6c2e09,0x090a300938323509,0x203436662e646461,0x202c373464662509\n"
".quad 0x25202c3634646625,0x6d090a3b36346466,0x09203436662e6c75,0x25202c3834646625\n"
".quad 0x6625202c37346466,0x6f6d090a3b373464,0x2509203436662e76,0x30202c3639336466\n"
".quad 0x3038333162653364,0x3166303865613362,0x2e31202f2f093b65,0x302d653333363230\n"
".quad 0x662e766f6d090a36,0x3364662509203436,0x65336430202c3739,0x6238353265653064\n"
".quad 0x093b343062386137,0x3633302e34202f2f,0x090a36302d653934,0x662e6e722e64616d\n"
".quad 0x3364662509203436,0x33646625202c3839,0x34646625202c3639,0x3933646625202c38\n"
".quad 0x2e766f6d090a3b37,0x6466250920343666,0x336430202c393933,0x3936363262336665\n"
".quad 0x3b66363736323066,0x37382e31202f2f09,0x0a35302d65343438,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x646625202c303034,0x646625202c383933,0x33646625202c3834\n"
".quad 0x766f6d090a3b3939,0x662509203436662e,0x6430202c31303464,0x6263353437316633\n"
".quad 0x3635393062613961,0x382e38202f2f093b,0x35302d6531383737,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x6625202c32303464,0x6625202c30303464,0x646625202c383464\n"
".quad 0x6f6d090a3b313034,0x2509203436662e76,0x30202c3330346466,0x6331376333663364\n"
".quad 0x3531356231643237,0x2e30202f2f093b34,0x3230343334303030,0x722e64616d090a38\n"
".quad 0x2509203436662e6e,0x25202c3430346466,0x25202c3230346466,0x6625202c38346466\n"
".quad 0x6d090a3b33303464,0x09203436662e766f,0x202c353034646625,0x3934323666336430\n"
".quad 0x3765623332393432,0x30202f2f093b6432,0x313233323230302e,0x722e64616d090a34\n"
".quad 0x2509203436662e6e,0x25202c3630346466,0x25202c3430346466,0x6625202c38346466\n"
".quad 0x6d090a3b35303464,0x09203436662e766f,0x202c373034646625,0x3939393866336430\n"
".quad 0x3361393939393939,0x30202f2f093b3463,0x6d090a353231302e,0x36662e6e722e6461\n"
".quad 0x3034646625092034,0x3034646625202c38,0x3834646625202c36,0x373034646625202c\n"
".quad 0x09636f6c2e090a3b,0x3009393235093133,0x36662e766f6d090a,0x3034646625092034\n"
".quad 0x6266336430202c39,0x3535353535353535,0x2f093b3435353535,0x333338302e30202f\n"
".quad 0x64616d090a333333,0x203436662e6e722e,0x2c30313464662509,0x2c38303464662520\n"
".quad 0x202c383464662520,0x0a3b393034646625,0x313309636f6c2e09,0x090a300932333509\n"
".quad 0x203436662e627573,0x202c343664662509,0x25202c3733646625,0x6e090a3b37346466\n"
".quad 0x09203436662e6765,0x202c313134646625,0x090a3b3734646625,0x203436662e646461\n"
".quad 0x2c32313464662509,0x202c343664662520,0x090a3b3436646625,0x662e6e722e64616d\n"
".quad 0x3464662509203436,0x34646625202c3331,0x33646625202c3131,0x3134646625202c37\n"
".quad 0x2e6c756d090a3b32,0x6466250920343666,0x34646625202c3836,0x3134646625202c35\n"
".quad 0x636f6c2e090a3b33,0x0935333509313309,0x662e6c756d090a30,0x3464662509203436\n"
".quad 0x34646625202c3431,0x3134646625202c38,0x2e6c756d090a3b30,0x6466250920343666\n"
".quad 0x34646625202c3037,0x3134646625202c37,0x2e747663090a3b34,0x732e3436662e6e72\n"
".quad 0x3764662509203233,0x3b30337225202c31,0x36662e766f6d090a,0x3134646625092034\n"
".quad 0x6566336430202c35,0x6665663234653236,0x2f093b6665393361,0x313339362e30202f\n"
".quad 0x2e64616d090a3734,0x09203436662e6e72,0x25202c3337646625,0x6625202c31376466\n"
".quad 0x6625202c35313464,0x6f6d090a3b373464,0x2509203436662e76,0x30202c3631346466\n"
".quad 0x3963626137633364,0x3330383933623365,0x2e32202f2f093b66,0x312d653530393133\n"
".quad 0x662e646461090a37,0x3464662509203436,0x37646625202c3731,0x3836646625202c30\n"
".quad 0x732e67656e090a3b,0x3931722509203233,0x3b30337225202c33,0x6e722e747663090a\n"
".quad 0x3233732e3436662e,0x3831346466250920,0x3b3339317225202c,0x36662e766f6d090a\n"
".quad 0x3134646625092034,0x6566336430202c39,0x6665663234653236,0x2f093b6665393361\n"
".quad 0x313339362e30202f,0x2e64616d090a3734,0x09203436662e6e72,0x202c303234646625\n"
".quad 0x202c383134646625,0x202c393134646625,0x090a3b3337646625,0x203436662e627573\n"
".quad 0x2c31323464662509,0x2c30323464662520,0x0a3b373464662520,0x3436662e62757309\n"
".quad 0x3232346466250920,0x373134646625202c,0x313234646625202c,0x722e64616d090a3b\n"
".quad 0x2509203436662e6e,0x25202c3332346466,0x6625202c31376466,0x6625202c36313464\n"
".quad 0x61090a3b32323464,0x09203436662e6464,0x202c383032646625,0x25202c3337646625\n"
".quad 0x090a3b3332346466,0x20696e752e617262,0x315f335f744c2409,0x744c240a3b363230\n"
".quad 0x30373931355f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c39363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333639365f335f,0x3309636f6c2e090a,0x0a30093834350931,0x3436662e73626109\n"
".quad 0x3432346466250920,0x363631646625202c,0x662e766f6d090a3b,0x3464662509203436\n"
".quad 0x66376430202c3532,0x3030303030303066,0x093b303030303030,0x090a666e69202f2f\n"
".quad 0x2e656c2e70746573,0x3570250920343666,0x3234646625202c37,0x3234646625202c34\n"
".quad 0x35702540090a3b35,0x2409206172622037,0x3130385f335f744c,0x3c2f2f200a3b3033\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c,0x2e646461090a3433\n"
".quad 0x6466250920343666,0x646625202c363234,0x646625202c363631,0x656e090a3b363631\n"
".quad 0x2509203436662e67,0x25202c3830326466,0x090a3b3632346466,0x20696e752e617262\n"
".quad 0x315f335f744c2409,0x744c240a3b363230,0x30333130385f335f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c39363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333639365f335f,0x36662e766f6d090a\n"
".quad 0x3234646625092034,0x3030306430202c37,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x746573090a30202f,0x3436662e71652e70,0x202c383570250920,0x202c373833646625\n"
".quad 0x0a3b373234646625,0x2038357025214009,0x744c240920617262,0x32343630385f335f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363220656e,0x62616c2064616568,0x744c242064656c65,0x34333639365f335f\n"
".quad 0x36662e766f6d090a,0x3032646625092034,0x6666666430202c38,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x090a666e692d202f,0x20696e752e617262,0x315f335f744c2409\n"
".quad 0x744c240a3b363230,0x32343630385f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39363220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333639365f335f,0x36662e766f6d090a,0x3234646625092034\n"
".quad 0x6666376430202c38,0x3030303030303030,0x2f093b3030303030,0x73090a666e69202f\n"
".quad 0x662e71652e707465,0x3935702509203436,0x373833646625202c,0x383234646625202c\n"
".quad 0x3570252140090a3b,0x2409206172622039,0x3131385f335f744c,0x3c2f2f200a3b3435\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433\n"
".quad 0x6466250920343666,0x646625202c383032,0x7262090a3b373833,0x240920696e752e61\n"
".quad 0x3230315f335f744c,0x335f744c240a3b36,0x0a3a34353131385f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f,0x203436662e766f6d\n"
".quad 0x2c38303264662509,0x3038666666643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x5f744c240a6e616e,0x0a3a363230315f33,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39363220,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a34333639365f,0x09393109636f6c2e,0x6d090a3009303331\n"
".quad 0x09203436662e766f,0x25202c3732646625,0x240a3b3830326466,0x3930375f335f744c\n"
".quad 0x3c2f2f200a3a3431,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39363220656e696c,0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c\n"
".quad 0x636f6c2e090a3433,0x0932333109393109,0x662e766f6d090a30,0x3464662509203436\n"
".quad 0x66336430202c3932,0x3363323339393564,0x093b643633303465,0x3733332e30202f2f\n"
".quad 0x766f6d090a353734,0x662509203436662e,0x6430202c30333464,0x3663633366656633\n"
".quad 0x3133316362386663,0x392e30202f2f093b,0x6d090a3936313637,0x09203436662e766f\n"
".quad 0x202c313334646625,0x3539346366336430,0x3630393636323730,0x30202f2f093b3638\n"
".quad 0x0a3839373036312e,0x3436662e766f6d09,0x3233346466250920,0x633966336430202c\n"
".quad 0x3465333764616534,0x2f2f093b37333234,0x34363732302e3020,0x2e766f6d090a3933\n"
".quad 0x6466250920343666,0x336430202c333334,0x6533343637663666,0x3b35383736653335\n"
".quad 0x30302e30202f2f09,0x090a373530343833,0x203436662e766f6d,0x2c34333464662509\n"
".quad 0x6539336633643020,0x3839613061653236,0x202f2f093b363438,0x3539333030302e30\n"
".quad 0x2e766f6d090a3931,0x6466250920343666,0x336430202c353334,0x3032626564303066\n"
".quad 0x3b38303238356635,0x31322e33202f2f09,0x0a35302d65383637,0x3436662e766f6d09\n"
".quad 0x3633346466250920,0x333965336430202c,0x6239303735643136,0x2f2f093b36356237\n"
".quad 0x37313838382e3220,0x6f6d090a37302d65,0x2509203436662e76,0x30202c3733346466\n"
".quad 0x6333396139653364,0x6135643230613035,0x2e33202f2f093b64,0x302d653233303639\n"
".quad 0x722e64616d090a37,0x2509203436662e6e,0x25202c3833346466,0x25202c3733346466\n"
".quad 0x6625202c37326466,0x6d090a3b36333464,0x36662e6e722e6461,0x3334646625092034\n"
".quad 0x3732646625202c39,0x383334646625202c,0x353334646625202c,0x722e64616d090a3b\n"
".quad 0x2509203436662e6e,0x25202c3034346466,0x6625202c37326466,0x6625202c39333464\n"
".quad 0x6d090a3b34333464,0x36662e6e722e6461,0x3434646625092034,0x3732646625202c31\n"
".quad 0x303434646625202c,0x333334646625202c,0x722e64616d090a3b,0x2509203436662e6e\n"
".quad 0x25202c3234346466,0x6625202c37326466,0x6625202c31343464,0x6d090a3b32333464\n"
".quad 0x36662e6e722e6461,0x3434646625092034,0x3732646625202c33,0x323434646625202c\n"
".quad 0x313334646625202c,0x722e64616d090a3b,0x2509203436662e6e,0x25202c3434346466\n"
".quad 0x6625202c37326466,0x6625202c33343464,0x6d090a3b30333464,0x36662e6e722e6461\n"
".quad 0x3434646625092034,0x3732646625202c35,0x343434646625202c,0x393234646625202c\n"
".quad 0x662e67656e090a3b,0x3464662509203436,0x34646625202c3634,0x766f6d090a3b3534\n"
".quad 0x662509203436662e,0x6430202c37343464,0x3030303030303030,0x3030303030303030\n"
".quad 0x090a30202f2f093b,0x2e746c2e70746573,0x3670250920343666,0x3432646625202c30\n"
".quad 0x3434646625202c31,0x706c6573090a3b37,0x662509203436662e,0x646625202c373264\n"
".quad 0x646625202c363434,0x367025202c353434,0x335f744c240a3b30,0x0a3a32303430375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f\n"
".quad 0x203436662e766f6d,0x2c39333264662509,0x0a3b373264662520,0x35325f335f744c24\n"
".quad 0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009393632093931,0x6e722e747663090a,0x3436662e3233662e\n"
".quad 0x202c323166250920,0x0a3b393332646625,0x626f6c672e747309,0x09203233662e6c61\n"
".quad 0x302b34316472255b,0x3b32316625202c5d,0x33752e646461090a,0x3330317225092032\n"
".quad 0x2c3530317225202c,0x0a3b333031722520,0x3436752e64646109,0x2c34316472250920\n"
".quad 0x202c343164722520,0x090a3b3531647225,0x09393109636f6c2e,0x6c090a3009313532\n"
".quad 0x2e6d617261702e64,0x3172250920323375,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x737265766e693631,0x6e72654b444e4365,0x5f6a5f5366506c65,0x0a3b5d4e68746170\n"
".quad 0x393109636f6c2e09,0x090a300939363209,0x2e746c2e70746573,0x3670250920323375\n"
".quad 0x3330317225202c31,0x090a3b317225202c,0x7262203136702540,0x335f744c24092061\n"
".quad 0x0a3b34333639365f,0x39365f335f744c24,0x744c240a3a323231,0x30313835355f335f\n"
".quad 0x09636f6c2e090a3a,0x3009323732093931,0x0a3b74697865090a,0x5f646e6557444c24\n"
".quad 0x65766e6936315a5f,0x654b444e43657372,0x5f5366506c656e72,0x2f2f207d090a3a6a\n"
".quad 0x766e6936315a5f20,0x4b444e4365737265,0x5366506c656e7265,0x000000000a0a6a5f\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_13$[9924];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"3bc3662b34f016bc",(char*)"MonteCarlo_SM13.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xa7b791db,&__elfEntries1};
# 2 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 93 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
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



extern int atexit(void(*)(void)) throw();







}

static void **__cudaFatCubinHandle;

static void __cudaUnregisterBinaryUtil(void)
{
  __cudaUnregisterFatBinary(__cudaFatCubinHandle);
}

# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 87 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 948 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 949 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 2969 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 2970 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 4679 "/usr/local/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) double rcbrt(double a); double rcbrt(double a)
{
  double s, t;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return 1.0 / a;
  }
  s = fabs(a);
  t = exp2(-3.3333333333333333e-1 * log2(s));
  t = ((t*t) * (-s*t) + 1.0) * (3.3333333333333333e-1*t) + t;



  if (__signbit(a))

  {
    t = -t;
  }
  return t;
}

extern __attribute__((__weak__)) double sinpi(double a); double sinpi(double a)
{
  int n;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return sin (a);
  }
  if (a == floor(a)) {
    return ((a / 1.0e308) / 1.0e308) / 1.0e308;
  }
  a = remquo (a, 0.5, &n);
  a = a * 3.1415926535897931e+0;
  if (n & 1) {
    a = cos (a);
  } else {
    a = sin (a);
  }
  if (n & 2) {
    a = -a;
  }
  return a;
}

extern __attribute__((__weak__)) double erfinv(double a); double erfinv(double a)
{
  double p, q, t, fa;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  fa = fabs(a);
  if (fa >= 1.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;
    if (fa == 1.0) {
      t = a * exp(1000.0);
    }
  } else if (fa >= 0.9375) {




    t = log1p(-fa);
    t = 1.0 / sqrt(-t);
    p = 2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q = t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
    if (a < 0.0) t = -t;
  } else if (fa >= 0.75) {




    t = a * a - .87890625;
    p = .21489185007307062000e+0;
    p = p * t - .64200071507209448655e+1;
    p = p * t + .29631331505876308123e+2;
    p = p * t - .47644367129787181803e+2;
    p = p * t + .34810057749357500873e+2;
    p = p * t - .12954198980646771502e+2;
    p = p * t + .25349389220714893917e+1;
    p = p * t - .24758242362823355486e+0;
    p = p * t + .94897362808681080020e-2;
    q = t - .12831383833953226499e+2;
    q = q * t + .41409991778428888716e+2;
    q = q * t - .53715373448862143349e+2;
    q = q * t + .33880176779595142685e+2;
    q = q * t - .11315360624238054876e+2;
    q = q * t + .20369295047216351160e+1;
    q = q * t - .18611650627372178511e+0;
    q = q * t + .67544512778850945940e-2;
    p = p / q;
    t = a * p;
  } else {




    t = a * a - .5625;
    p = - .23886240104308755900e+2;
    p = p * t + .45560204272689128170e+3;
    p = p * t - .22977467176607144887e+4;
    p = p * t + .46631433533434331287e+4;
    p = p * t - .43799652308386926161e+4;
    p = p * t + .19007153590528134753e+4;
    p = p * t - .30786872642313695280e+3;
    q = t - .83288327901936570000e+2;
    q = q * t + .92741319160935318800e+3;
    q = q * t - .35088976383877264098e+4;
    q = q * t + .59039348134843665626e+4;
    q = q * t - .48481635430048872102e+4;
    q = q * t + .18997769186453057810e+4;
    q = q * t - .28386514725366621129e+3;
    p = p / q;
    t = a * p;
  }
  return t;
}

extern __attribute__((__weak__)) double erfcinv(double a); double erfcinv(double a)
{
  double t;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  if (__isnan(a)) {
    return a + a;
  }
  if (a <= 0.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;
    if (a == 0.0) {
        t = (1.0 - a) * exp(1000.0);
    }
  }
  else if (a >= 0.0625) {
    t = erfinv (1.0 - a);
  }
  else if (a >= 1e-100) {




    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p = 2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q = t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
  }
  else {




    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p = 6.9952990607058154858e-1;
    p = p * t + 1.9507620287580568829e+0;
    p = p * t + 8.2810030904462690216e-1;
    p = p * t + 1.1279046353630280005e-1;
    p = p * t + 6.0537914739162189689e-3;
    p = p * t + 1.3714329569665128933e-4;
    p = p * t + 1.2964481560643197452e-6;
    p = p * t + 4.6156006321345332510e-9;
    p = p * t + 4.5344689563209398450e-12;
    q = t + 1.5771922386662040546e+0;
    q = q * t + 2.1238242087454993542e+0;
    q = q * t + 8.4001814918178042919e-1;
    q = q * t + 1.1311889334355782065e-1;
    q = q * t + 6.0574830550097140404e-3;
    q = q * t + 1.3715891988350205065e-4;
    q = q * t + 1.2964671850944981713e-6;
    q = q * t + 4.6156017600933592558e-9;
    q = q * t + 4.5344687377088206783e-12;
    t = p / (q * t);
  }
  return t;
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}

extern __attribute__((__weak__)) float rcbrtf(float a); float rcbrtf(float a)
{
  return (float)rcbrt((double)a);
}

extern __attribute__((__weak__)) float sinpif(float a); float sinpif(float a)
{
  return (float)sinpi((double)a);
}

extern __attribute__((__weak__)) float erfinvf(float a); float erfinvf(float a)
{
  return (float)erfinv((double)a);
}

extern __attribute__((__weak__)) float erfcinvf(float a); float erfcinvf(float a)
{
  return (float)erfcinv((double)a);
}







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
# 5002 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx3.h" 1 3
# 5003 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 88 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 166 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2
struct __T20 {__TOptionValue *__par0;float *__par1;int __par2;int __dummy_field;};
struct __T21 {float *__par0;int __par1;int __dummy_field;};
struct __T22 {__TOptionValue *__par0;int __par1;int __dummy_field;};
struct __T23 {float *__par0;float *__par1;unsigned __par2;int __dummy_field;};
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *, float *, int);
static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi(float *, int);
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei(__TOptionValue *, int);
static void __device_stub__Z16inverseCNDKernelPfS_j(float *, float *, unsigned);
static void __sti____cudaRegisterAll_50_tmpxft_00007ce1_00000000_4_MonteCarlo_SM13_cpp1_ii_9123f87d(void) __attribute__((__constructor__));
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *__par0, float *__par1, int __par2){ struct __T20 *__T24;
*(void**)(void*)&__T24 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel))); };}
static void MonteCarloKernel( __TOptionValue *__cuda_0,float *__cuda_1,int __cuda_2)
# 113 "MonteCarlo_kernel.cuh"
{__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi( __cuda_0,__cuda_1,__cuda_2);
# 136 "MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi( float *__par0, int __par1) { struct __T21 *__T25;
*(void**)(void*)&__T25 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption)); (void)cudaLaunch(((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption))); }; }
static void MonteCarloOneBlockPerOption( float *__cuda_0,int __cuda_1)
# 150 "MonteCarlo_kernel.cuh"
{__device_stub__Z27MonteCarloOneBlockPerOptionPfi( __cuda_0,__cuda_1);
# 183 "MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei( __TOptionValue *__par0, int __par1) { struct __T22 *__T26;
*(void**)(void*)&__T26 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T26->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T26->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce))); }; }
static void MonteCarloReduce( __TOptionValue *__cuda_0,int __cuda_1)
# 194 "MonteCarlo_kernel.cuh"
{__device_stub__Z16MonteCarloReduceP14__TOptionValuei( __cuda_0,__cuda_1);
# 220 "MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z16inverseCNDKernelPfS_j( float *__par0, float *__par1, unsigned __par2) { struct __T23 *__T233;
*(void**)(void*)&__T233 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T233->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T233->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T233->__par2) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel))); }; }
static void inverseCNDKernel( float *__cuda_0,float *__cuda_1,unsigned __cuda_2)
# 252 "quasirandomGenerator_kernel.cuh"
{__device_stub__Z16inverseCNDKernelPfS_j( __cuda_0,__cuda_1,__cuda_2);
# 272 "quasirandomGenerator_kernel.cuh"
}
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __sti____cudaRegisterAll_50_tmpxft_00007ce1_00000000_4_MonteCarlo_SM13_cpp1_ii_9123f87d(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, unsigned))inverseCNDKernel), (char*)"_Z16inverseCNDKernelPfS_j", "_Z16inverseCNDKernelPfS_j", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, int))MonteCarloReduce), (char*)"_Z16MonteCarloReduceP14__TOptionValuei", "_Z16MonteCarloReduceP14__TOptionValuei", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))MonteCarloOneBlockPerOption), (char*)"_Z27MonteCarloOneBlockPerOptionPfi", "_Z27MonteCarloOneBlockPerOptionPfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel), (char*)"_Z16MonteCarloKernelP14__TOptionValuePfi", "_Z16MonteCarloKernelP14__TOptionValuePfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_OptionData, (char*)"d_OptionData", "d_OptionData", 0, 65536, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_CallValue, (char*)"d_CallValue", "d_CallValue", 0, 32768, 0, 0); }
# 1 "/tmp/tmpxft_00007ce1_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2

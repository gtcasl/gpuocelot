# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.cpp"
# 1 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3
typedef int ptrdiff_t;
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3
typedef unsigned size_t;
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
  int pciBusID;
  int pciDeviceID;
  int __cudaReserved[22];
};
# 426 "/usr/local/cuda/bin/../include/driver_types.h" 3
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
# 213 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 2 3
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
# 426 "/usr/local/cuda/bin/../include/driver_types.h"
# 432 "/usr/local/cuda/bin/../include/driver_types.h"
# 438 "/usr/local/cuda/bin/../include/driver_types.h"
# 444 "/usr/local/cuda/bin/../include/driver_types.h"
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
# 307 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long> ()
# 308 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 309 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 311 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 312 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 314 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> ()
# 315 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 316 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 318 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 319 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 321 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> ()
# 322 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 323 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 325 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 326 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 328 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> ()
# 329 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 330 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 332 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 333 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 335 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> ()
# 336 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 337 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 339 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 340 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 342 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> ()
# 343 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 344 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 346 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 347 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 349 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> ()
# 350 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 351 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 353 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 354 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 356 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> ()
# 357 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 358 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 360 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 361 "/usr/local/cuda/bin/../include/channel_descriptor.h"
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
# 47 "/usr/include/bits/types.h" 3
extern "C" { typedef signed long long __int64_t; }
# 48 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long long __uint64_t; }
# 56 "/usr/include/bits/types.h" 3
extern "C" { typedef long long __quad_t; }
# 57 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long long __u_quad_t; }
# 134 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __dev_t; }
# 135 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __uid_t; }
# 136 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __gid_t; }
# 137 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __ino_t; }
# 138 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __ino64_t; }
# 139 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __mode_t; }
# 140 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned __nlink_t; }
# 141 "/usr/include/bits/types.h" 3
extern "C" { typedef long __off_t; }
# 142 "/usr/include/bits/types.h" 3
extern "C" { typedef __quad_t __off64_t; }
# 143 "/usr/include/bits/types.h" 3
extern "C" { typedef int __pid_t; }
# 144 "/usr/include/bits/types.h" 3
extern "C" { typedef struct { int __val[2]; } __fsid_t; }
# 145 "/usr/include/bits/types.h" 3
extern "C" { typedef long __clock_t; }
# 146 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __rlim_t; }
# 147 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __rlim64_t; }
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
extern "C" { typedef __quad_t __blkcnt64_t; }
# 173 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsblkcnt_t; }
# 174 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __fsblkcnt64_t; }
# 177 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __fsfilcnt_t; }
# 178 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __fsfilcnt64_t; }
# 180 "/usr/include/bits/types.h" 3
extern "C" { typedef int __ssize_t; }
# 184 "/usr/include/bits/types.h" 3
extern "C" { typedef __off64_t __loff_t; }
# 185 "/usr/include/bits/types.h" 3
extern "C" { typedef __quad_t *__qaddr_t; }
# 186 "/usr/include/bits/types.h" 3
extern "C" { typedef char *__caddr_t; }
# 189 "/usr/include/bits/types.h" 3
extern "C" { typedef int __intptr_t; }
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
# 38 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef long double float_t; }
# 40 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef long double double_t; }
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
# 161 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 203 "/usr/include/math.h" 3
enum {
# 204 "/usr/include/math.h" 3
FP_NAN,
# 206 "/usr/include/math.h" 3
FP_INFINITE,
# 208 "/usr/include/math.h" 3
FP_ZERO,
# 210 "/usr/include/math.h" 3
FP_SUBNORMAL,
# 212 "/usr/include/math.h" 3
FP_NORMAL
# 214 "/usr/include/math.h" 3
};
# 302 "/usr/include/math.h" 3
extern "C" { typedef
# 296 "/usr/include/math.h" 3
enum {
# 297 "/usr/include/math.h" 3
_IEEE_ = (-1),
# 298 "/usr/include/math.h" 3
_SVID_,
# 299 "/usr/include/math.h" 3
_XOPEN_,
# 300 "/usr/include/math.h" 3
_POSIX_,
# 301 "/usr/include/math.h" 3
_ISOC_
# 302 "/usr/include/math.h" 3
} _LIB_VERSION_TYPE; }
# 307 "/usr/include/math.h" 3
extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; }
# 318 "/usr/include/math.h" 3
extern "C" { struct __exception {
# 323 "/usr/include/math.h" 3
int type;
# 324 "/usr/include/math.h" 3
char *name;
# 325 "/usr/include/math.h" 3
double arg1;
# 326 "/usr/include/math.h" 3
double arg2;
# 327 "/usr/include/math.h" 3
double retval;
# 328 "/usr/include/math.h" 3
}; }
# 331 "/usr/include/math.h" 3
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
extern "C" { typedef long long int64_t; }
# 201 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned char u_int8_t; }
# 202 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned short u_int16_t; }
# 203 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned u_int32_t; }
# 204 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long long u_int64_t; }
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
__fd_mask fds_bits[(1024 / (8 * ((int)sizeof(__fd_mask))))];
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
char __size[36];
# 56 "/usr/include/bits/pthreadtypes.h" 3
long __align;
# 57 "/usr/include/bits/pthreadtypes.h" 3
} pthread_attr_t; }
# 70 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 67 "/usr/include/bits/pthreadtypes.h" 3
struct __pthread_internal_slist {
# 69 "/usr/include/bits/pthreadtypes.h" 3
__pthread_internal_slist *__next;
# 70 "/usr/include/bits/pthreadtypes.h" 3
} __pthread_slist_t; }
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
# 88 "/usr/include/bits/pthreadtypes.h" 3
int __kind;
# 94 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nusers;
# 96 "/usr/include/bits/pthreadtypes.h" 3
union {
# 97 "/usr/include/bits/pthreadtypes.h" 3
int __spins;
# 98 "/usr/include/bits/pthreadtypes.h" 3
__pthread_slist_t __list;
# 99 "/usr/include/bits/pthreadtypes.h" 3
};
# 101 "/usr/include/bits/pthreadtypes.h" 3
} __data;
# 102 "/usr/include/bits/pthreadtypes.h" 3
char __size[24];
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
# 171 "/usr/include/bits/pthreadtypes.h" 3
struct {
# 172 "/usr/include/bits/pthreadtypes.h" 3
int __lock;
# 173 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_readers;
# 174 "/usr/include/bits/pthreadtypes.h" 3
unsigned __readers_wakeup;
# 175 "/usr/include/bits/pthreadtypes.h" 3
unsigned __writer_wakeup;
# 176 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_readers_queued;
# 177 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nr_writers_queued;
# 180 "/usr/include/bits/pthreadtypes.h" 3
unsigned char __flags;
# 181 "/usr/include/bits/pthreadtypes.h" 3
unsigned char __shared;
# 182 "/usr/include/bits/pthreadtypes.h" 3
unsigned char __pad1;
# 183 "/usr/include/bits/pthreadtypes.h" 3
unsigned char __pad2;
# 184 "/usr/include/bits/pthreadtypes.h" 3
int __writer;
# 185 "/usr/include/bits/pthreadtypes.h" 3
} __data;
# 187 "/usr/include/bits/pthreadtypes.h" 3
char __size[32];
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
char __size[20];
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
# 637 "/usr/include/stdlib.h" 3
extern "C" int mkstemps(char *, int) __attribute__((nonnull(1)));
# 647 "/usr/include/stdlib.h" 3
extern "C" int mkstemps64(char *, int) __attribute__((nonnull(1)));
# 658 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw() __attribute__((nonnull(1)));
# 669 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int) __attribute__((nonnull(1)));
# 679 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int) __attribute__((nonnull(1)));
# 689 "/usr/include/stdlib.h" 3
extern "C" int mkostemps(char *, int, int) __attribute__((nonnull(1)));
# 701 "/usr/include/stdlib.h" 3
extern "C" int mkostemps64(char *, int, int) __attribute__((nonnull(1)));
# 712 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 719 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw() __attribute__((nonnull(1)));
# 729 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 737 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 740 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 744 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 750 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(5)));
# 756 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 759 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 766 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 767 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 771 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 780 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));
# 782 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 788 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 802 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 808 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 814 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw() __attribute__((nonnull(3)));
# 820 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 823 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 826 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double, int, char *) throw() __attribute__((nonnull(3)));
# 832 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 835 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 839 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 843 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 854 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();
# 857 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 861 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t) throw();
# 865 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 868 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 879 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw() __attribute__((nonnull(1)));
# 890 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 899 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw() __attribute__((nonnull(1)));
# 907 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 915 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();
# 919 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int) throw();
# 924 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int) throw();
# 931 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 935 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 942 "/usr/include/stdlib.h" 3
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
# 327 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 328 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 330 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 333 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 334 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 336 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 340 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 345 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 346 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 351 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 352 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 360 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 364 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 367 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 368 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 375 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 376 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 380 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 687 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 688 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 693 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 694 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 696 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 700 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 702 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 705 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 706 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 708 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 711 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 712 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 716 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 719 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 720 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 724 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 727 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline long4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 728 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 732 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 735 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> inline ulong4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 736 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 740 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 1003 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1004 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1006 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1008 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1009 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1011 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1013 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1014 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1016 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1018 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1019 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1024 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1026 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1028 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1029 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1031 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1033 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1034 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1036 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1038 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulong4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1039 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1041 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 1296 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1297 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1302 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1304 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1306 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1307 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1309 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1311 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1314 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1316 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1317 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1319 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1321 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1322 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1324 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1326 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1327 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1329 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1331 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulong4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1332 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1334 "/usr/local/cuda/bin/../include/surface_functions.h"
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
# 279 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long tex1Dfetch(texture< long, 1, cudaReadModeElementType> t, int x)
# 280 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 286 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned long tex1Dfetch(texture< unsigned long, 1, cudaReadModeElementType> t, int x)
# 287 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long1 tex1Dfetch(texture< long1, 1, cudaReadModeElementType> t, int x)
# 294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 298 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 300 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong1 tex1Dfetch(texture< ulong1, 1, cudaReadModeElementType> t, int x)
# 301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 305 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long2 tex1Dfetch(texture< long2, 1, cudaReadModeElementType> t, int x)
# 308 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 312 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong2 tex1Dfetch(texture< ulong2, 1, cudaReadModeElementType> t, int x)
# 315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 319 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 321 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long4 tex1Dfetch(texture< long4, 1, cudaReadModeElementType> t, int x)
# 322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 328 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong4 tex1Dfetch(texture< ulong4, 1, cudaReadModeElementType> t, int x)
# 329 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 734 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long tex1D(texture< long, 1, cudaReadModeElementType> t, float x)
# 735 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 741 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned long tex1D(texture< unsigned long, 1, cudaReadModeElementType> t, float x)
# 742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 746 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long1 tex1D(texture< long1, 1, cudaReadModeElementType> t, float x)
# 749 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 753 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 755 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong1 tex1D(texture< ulong1, 1, cudaReadModeElementType> t, float x)
# 756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 760 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 762 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long2 tex1D(texture< long2, 1, cudaReadModeElementType> t, float x)
# 763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 769 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong2 tex1D(texture< ulong2, 1, cudaReadModeElementType> t, float x)
# 770 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 776 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long4 tex1D(texture< long4, 1, cudaReadModeElementType> t, float x)
# 777 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 781 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong4 tex1D(texture< ulong4, 1, cudaReadModeElementType> t, float x)
# 784 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 1183 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long tex2D(texture< long, 2, cudaReadModeElementType> t, float x, float y)
# 1184 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1190 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned long tex2D(texture< unsigned long, 2, cudaReadModeElementType> t, float x, float y)
# 1191 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1197 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long1 tex2D(texture< long1, 2, cudaReadModeElementType> t, float x, float y)
# 1198 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong1 tex2D(texture< ulong1, 2, cudaReadModeElementType> t, float x, float y)
# 1205 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1209 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1211 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long2 tex2D(texture< long2, 2, cudaReadModeElementType> t, float x, float y)
# 1212 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1218 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong2 tex2D(texture< ulong2, 2, cudaReadModeElementType> t, float x, float y)
# 1219 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1225 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long4 tex2D(texture< long4, 2, cudaReadModeElementType> t, float x, float y)
# 1226 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1232 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong4 tex2D(texture< ulong4, 2, cudaReadModeElementType> t, float x, float y)
# 1233 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 1632 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long tex3D(texture< long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1633 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1639 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned long tex3D(texture< unsigned long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1640 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1646 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long1 tex3D(texture< long1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1647 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1653 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong1 tex3D(texture< ulong1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1654 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1658 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1660 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long2 tex3D(texture< long2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1661 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1667 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong2 tex3D(texture< ulong2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1668 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1674 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline long4 tex3D(texture< long4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1675 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1681 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ulong4 tex3D(texture< ulong4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1682 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
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
# 40 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/va.h" 3
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
# 460 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *);
# 461 "/usr/include/libio.h" 3
extern "C" int _IO_putc(int, _IO_FILE *);
# 462 "/usr/include/libio.h" 3
extern "C" int _IO_feof(_IO_FILE *) throw();
# 463 "/usr/include/libio.h" 3
extern "C" int _IO_ferror(_IO_FILE *) throw();
# 465 "/usr/include/libio.h" 3
extern "C" int _IO_peekc_locked(_IO_FILE *);
# 471 "/usr/include/libio.h" 3
extern "C" void _IO_flockfile(_IO_FILE *) throw();
# 472 "/usr/include/libio.h" 3
extern "C" void _IO_funlockfile(_IO_FILE *) throw();
# 473 "/usr/include/libio.h" 3
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw();
# 490 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__);
# 492 "/usr/include/libio.h" 3
extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 494 "/usr/include/libio.h" 3
extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
# 495 "/usr/include/libio.h" 3
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t);
# 497 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
# 498 "/usr/include/libio.h" 3
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);
# 500 "/usr/include/libio.h" 3
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
# 179 "/usr/local/cuda/bin/../include/cuda.h"
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
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 177 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 178 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID
# 179 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 195 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 184 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 185 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 186 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 187 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 188 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 189 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 190 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 191 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 192 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 193 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 194 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 195 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 242 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 200 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 206 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 213 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 219 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 224 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 229 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 234 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 241 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 242 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 251 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 247 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 248 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 249 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 250 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 251 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 260 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 256 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 257 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 258 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 259 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 260 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 269 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 265 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 266 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 267 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 268 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 269 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 361 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 274 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 280 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 293 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 300 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 308 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 316 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 324 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 332 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 339 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 346 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 352 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 359 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 361 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 373 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 366 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 369 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 370 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 371 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 372 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20
# 373 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 386 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 378 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 381 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 384 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 386 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 393 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 391 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 392 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 393 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 402 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 398 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 399 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 400 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 401 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 402 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 414 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 407 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 408 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 409 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 410 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 411 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 412 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 413 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 414 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 422 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 419 "/usr/local/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 420 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 421 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE
# 422 "/usr/local/cuda/bin/../include/cuda.h"
} CUlimit; }
# 479 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 433 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 435 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 436 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 437 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 438 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 439 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 441 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 442 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 444 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 445 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 446 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 447 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 448 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 449 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 450 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 451 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 452 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 453 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 454 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 455 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 456 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 457 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 459 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 460 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 461 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 462 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 464 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 466 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 468 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 470 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 471 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 472 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 473 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 475 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_POINTER_IS_64BIT = 800,
# 476 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SIZE_IS_64BIT,
# 478 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 479 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 525 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 505 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 507 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 508 "/usr/local/cuda/bin/../include/cuda.h"
srcY;
# 509 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 510 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 511 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 512 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 513 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 515 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 516 "/usr/local/cuda/bin/../include/cuda.h"
dstY;
# 517 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 518 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 519 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 520 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 521 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 523 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 524 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 525 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 559 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 530 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 532 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcXInBytes,
# 533 "/usr/local/cuda/bin/../include/cuda.h"
srcY,
# 534 "/usr/local/cuda/bin/../include/cuda.h"
srcZ;
# 535 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcLOD;
# 536 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 537 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 538 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 539 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 540 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 541 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcPitch;
# 542 "/usr/local/cuda/bin/../include/cuda.h"
unsigned srcHeight;
# 544 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstXInBytes,
# 545 "/usr/local/cuda/bin/../include/cuda.h"
dstY,
# 546 "/usr/local/cuda/bin/../include/cuda.h"
dstZ;
# 547 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstLOD;
# 548 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 549 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 550 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 551 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 552 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 553 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstPitch;
# 554 "/usr/local/cuda/bin/../include/cuda.h"
unsigned dstHeight;
# 556 "/usr/local/cuda/bin/../include/cuda.h"
unsigned WidthInBytes;
# 557 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 558 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 559 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 572 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 565 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 566 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 567 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 569 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 571 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 572 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 588 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 578 "/usr/local/cuda/bin/../include/cuda.h"
struct {
# 579 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Width;
# 580 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Height;
# 581 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Depth;
# 583 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 585 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 587 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 588 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 636 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 641 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 649 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 650 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 651 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 652 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 653 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem(unsigned *, CUdevice);
# 654 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 655 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 663 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate(CUcontext *, unsigned, CUdevice);
# 664 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 665 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 666 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 667 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 668 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 669 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 670 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 679 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 680 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 681 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 682 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 683 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 684 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 685 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal(CUdeviceptr *, unsigned *, CUmodule, const char *);
# 686 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 687 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref *, CUmodule, const char *);
# 695 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo(unsigned *, unsigned *);
# 697 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc(CUdeviceptr *, unsigned);
# 698 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch(CUdeviceptr *, unsigned *, unsigned, unsigned, unsigned);
# 706 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree(CUdeviceptr);
# 707 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange(CUdeviceptr *, unsigned *, CUdeviceptr);
# 709 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost(void **, unsigned);
# 710 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 712 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 714 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer(CUdeviceptr *, void *, unsigned);
# 715 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 728 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD(CUdeviceptr, const void *, unsigned);
# 729 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH(void *, CUdeviceptr, unsigned);
# 732 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD(CUdeviceptr, CUdeviceptr, unsigned);
# 735 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA(CUarray, unsigned, CUdeviceptr, unsigned);
# 736 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD(CUdeviceptr, CUarray, unsigned, unsigned);
# 739 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA(CUarray, unsigned, const void *, unsigned);
# 740 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH(void *, CUarray, unsigned, unsigned);
# 743 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA(CUarray, unsigned, CUarray, unsigned, unsigned);
# 747 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D(const CUDA_MEMCPY2D *);
# 748 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *);
# 752 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D(const CUDA_MEMCPY3D *);
# 767 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync(CUdeviceptr, const void *, unsigned, CUstream);
# 769 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync(void *, CUdeviceptr, unsigned, CUstream);
# 773 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync(CUdeviceptr, CUdeviceptr, unsigned, CUstream);
# 777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync(CUarray, unsigned, const void *, unsigned, CUstream);
# 779 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync(void *, CUarray, unsigned, unsigned, CUstream);
# 783 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *, CUstream);
# 786 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *, CUstream);
# 793 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8(CUdeviceptr, unsigned char, unsigned);
# 794 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16(CUdeviceptr, unsigned short, unsigned);
# 795 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32(CUdeviceptr, unsigned, unsigned);
# 797 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8(CUdeviceptr, unsigned, unsigned char, unsigned, unsigned);
# 798 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16(CUdeviceptr, unsigned, unsigned short, unsigned, unsigned);
# 799 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32(CUdeviceptr, unsigned, unsigned, unsigned, unsigned);
# 808 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 809 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 810 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 811 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction, CUfunc_cache);
# 819 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 820 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 821 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 823 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 824 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 832 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 835 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 836 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress(unsigned *, CUtexref, CUdeviceptr, unsigned);
# 837 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, unsigned);
# 838 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 839 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 840 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 841 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress(CUdeviceptr *, CUtexref);
# 844 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 845 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 846 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 847 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 848 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 856 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref, CUarray, unsigned);
# 857 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray *, CUsurfref);
# 865 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 866 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 867 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 868 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 869 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 878 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 879 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 880 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 887 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 888 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 889 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 890 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 891 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 892 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 899 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 900 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 901 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 902 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 909 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 910 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 911 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *, unsigned *, CUgraphicsResource);
# 912 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 913 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 914 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 921 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void **, const CUuuid *);
# 929 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit, size_t);
# 930 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t *, CUlimit);
# 64 "sdk/cutil.h"
enum CUTBoolean {
# 66 "sdk/cutil.h"
CUTFalse,
# 67 "sdk/cutil.h"
CUTTrue
# 68 "sdk/cutil.h"
};
# 76 "sdk/cutil.h"
extern "C" void cutFree(void *);
# 94 "sdk/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 107 "sdk/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 122 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 138 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 154 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 169 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 185 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 201 "sdk/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 215 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 229 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 241 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 253 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 265 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 277 "sdk/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 293 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 306 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 320 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 336 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 352 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 367 "sdk/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 379 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 391 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 404 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 416 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 428 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 440 "sdk/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 461 "sdk/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 475 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 489 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 503 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 518 "sdk/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 532 "sdk/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 544 "sdk/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 557 "sdk/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 571 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 584 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 599 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 613 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 627 "sdk/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 642 "sdk/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 657 "sdk/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 672 "sdk/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 685 "sdk/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 694 "sdk/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 702 "sdk/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 710 "sdk/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 718 "sdk/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 727 "sdk/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 738 "sdk/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 19 "sdk/cutil_inline_bankchecker.h"
inline void __cutilBankChecker(unsigned tidx, unsigned tidy, unsigned tidz, unsigned
# 20 "sdk/cutil_inline_bankchecker.h"
bdimx, unsigned bdimy, unsigned bdimz, char *
# 21 "sdk/cutil_inline_bankchecker.h"
aname, int index, char *file, int line)
# 22 "sdk/cutil_inline_bankchecker.h"
{
# 23 "sdk/cutil_inline_bankchecker.h"
cutCheckBankAccess(tidx, tidy, tidz, bdimx, bdimy, bdimz, file, line, aname, index);
# 24 "sdk/cutil_inline_bankchecker.h"
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
CUFFT_COMPATIBILITY_NATIVE,
# 127 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_PADDING,
# 128 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ASYMMETRIC,
# 129 "/usr/local/cuda/bin/../include/cufft.h"
CUFFT_COMPATIBILITY_FFTW_ALL
# 130 "/usr/local/cuda/bin/../include/cufft.h"
} cufftCompatibility; }
# 134 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan1d(cufftHandle *, int, cufftType, int);
# 139 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan2d(cufftHandle *, int, int, cufftType);
# 143 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlan3d(cufftHandle *, int, int, int, cufftType);
# 147 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftPlanMany(cufftHandle *, int, int *, int *, int, int, int *, int, int, cufftType, int);
# 155 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftDestroy(cufftHandle);
# 157 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2C(cufftHandle, cufftComplex *, cufftComplex *, int);
# 162 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecR2C(cufftHandle, cufftReal *, cufftComplex *);
# 166 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecC2R(cufftHandle, cufftComplex *, cufftReal *);
# 170 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2Z(cufftHandle, cufftDoubleComplex *, cufftDoubleComplex *, int);
# 175 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecD2Z(cufftHandle, cufftDoubleReal *, cufftDoubleComplex *);
# 179 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftExecZ2D(cufftHandle, cufftDoubleComplex *, cufftDoubleReal *);
# 183 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetStream(cufftHandle, cudaStream_t);
# 186 "/usr/local/cuda/bin/../include/cufft.h"
extern "C" cufftResult cufftSetCompatibilityMode(cufftHandle, cufftCompatibility);
# 22 "sdk/cutil_inline_runtime.h"
inline void __cutilCondition(int val, char *file, int line)
# 23 "sdk/cutil_inline_runtime.h"
{
# 24 "sdk/cutil_inline_runtime.h"
if ((CUTFalse) == (cutCheckCondition(val, file, line))) {
# 25 "sdk/cutil_inline_runtime.h"
exit(1);
# 26 "sdk/cutil_inline_runtime.h"
}
# 27 "sdk/cutil_inline_runtime.h"
}
# 29 "sdk/cutil_inline_runtime.h"
inline void __cutilExit(int argc, char **argv)
# 30 "sdk/cutil_inline_runtime.h"
{
# 31 "sdk/cutil_inline_runtime.h"
if (!(cutCheckCmdLineFlag(argc, (const char **)argv, "noprompt"))) {
# 32 "sdk/cutil_inline_runtime.h"
printf("\nPress ENTER to exit...\n");
# 33 "sdk/cutil_inline_runtime.h"
fflush(stdout);
# 34 "sdk/cutil_inline_runtime.h"
fflush(stderr);
# 35 "sdk/cutil_inline_runtime.h"
getchar();
# 36 "sdk/cutil_inline_runtime.h"
}
# 37 "sdk/cutil_inline_runtime.h"
exit(0);
# 38 "sdk/cutil_inline_runtime.h"
}
# 41 "sdk/cutil_inline_runtime.h"
inline int cutGetMaxGflopsDeviceId()
# 42 "sdk/cutil_inline_runtime.h"
{
# 43 "sdk/cutil_inline_runtime.h"
int device_count = 0;
# 44 "sdk/cutil_inline_runtime.h"
cudaGetDeviceCount(&device_count);
# 46 "sdk/cutil_inline_runtime.h"
cudaDeviceProp device_properties;
# 47 "sdk/cutil_inline_runtime.h"
int max_gflops_device = 0;
# 48 "sdk/cutil_inline_runtime.h"
int max_gflops = 0;
# 50 "sdk/cutil_inline_runtime.h"
int current_device = 0;
# 51 "sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 52 "sdk/cutil_inline_runtime.h"
max_gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 53 "sdk/cutil_inline_runtime.h"
++current_device;
# 55 "sdk/cutil_inline_runtime.h"
while (current_device < device_count)
# 56 "sdk/cutil_inline_runtime.h"
{
# 57 "sdk/cutil_inline_runtime.h"
cudaGetDeviceProperties(&device_properties, current_device);
# 58 "sdk/cutil_inline_runtime.h"
int gflops = ((device_properties.multiProcessorCount) * (device_properties.clockRate));
# 59 "sdk/cutil_inline_runtime.h"
if (gflops > max_gflops)
# 60 "sdk/cutil_inline_runtime.h"
{
# 61 "sdk/cutil_inline_runtime.h"
max_gflops = gflops;
# 62 "sdk/cutil_inline_runtime.h"
max_gflops_device = current_device;
# 63 "sdk/cutil_inline_runtime.h"
}
# 64 "sdk/cutil_inline_runtime.h"
++current_device;
# 65 "sdk/cutil_inline_runtime.h"
}
# 67 "sdk/cutil_inline_runtime.h"
return max_gflops_device;
# 68 "sdk/cutil_inline_runtime.h"
}
# 70 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeCallNoSync(cudaError err, const char *file, const int line)
# 71 "sdk/cutil_inline_runtime.h"
{
# 72 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 73 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCallNoSync() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 75 "sdk/cutil_inline_runtime.h"
exit(-1);
# 76 "sdk/cutil_inline_runtime.h"
}
# 77 "sdk/cutil_inline_runtime.h"
}
# 79 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeCall(cudaError err, const char *file, const int line)
# 80 "sdk/cutil_inline_runtime.h"
{
# 81 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 82 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaSafeCall() Runtime API error in file <%s>, line %i : %s.\n", file, line, cudaGetErrorString(err));
# 84 "sdk/cutil_inline_runtime.h"
exit(-1);
# 85 "sdk/cutil_inline_runtime.h"
}
# 86 "sdk/cutil_inline_runtime.h"
}
# 88 "sdk/cutil_inline_runtime.h"
inline void __cudaSafeThreadSync(const char *file, const int line)
# 89 "sdk/cutil_inline_runtime.h"
{
# 90 "sdk/cutil_inline_runtime.h"
cudaError err = cudaThreadSynchronize();
# 91 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 92 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cudaThreadSynchronize() Driver API error in file \'%s\' in line %i : %s.\n", file, line, cudaGetErrorString(err));
# 94 "sdk/cutil_inline_runtime.h"
exit(-1);
# 95 "sdk/cutil_inline_runtime.h"
}
# 96 "sdk/cutil_inline_runtime.h"
}
# 98 "sdk/cutil_inline_runtime.h"
inline void __cufftSafeCall(cufftResult err, const char *file, const int line)
# 99 "sdk/cutil_inline_runtime.h"
{
# 100 "sdk/cutil_inline_runtime.h"
if ((CUFFT_SUCCESS) != err) {
# 101 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cufftSafeCall() CUFFT error in file <%s>, line %i.\n", file, line);
# 103 "sdk/cutil_inline_runtime.h"
exit(-1);
# 104 "sdk/cutil_inline_runtime.h"
}
# 105 "sdk/cutil_inline_runtime.h"
}
# 107 "sdk/cutil_inline_runtime.h"
inline void __cutilCheckError(CUTBoolean err, const char *file, const int line)
# 108 "sdk/cutil_inline_runtime.h"
{
# 109 "sdk/cutil_inline_runtime.h"
if ((CUTTrue) != err) {
# 110 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error in file <%s>, line %i.\n", file, line);
# 112 "sdk/cutil_inline_runtime.h"
exit(-1);
# 113 "sdk/cutil_inline_runtime.h"
}
# 114 "sdk/cutil_inline_runtime.h"
}
# 116 "sdk/cutil_inline_runtime.h"
inline void __cutilCheckMsg(const char *errorMessage, const char *file, const int line)
# 117 "sdk/cutil_inline_runtime.h"
{
# 118 "sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 119 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 120 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilCheckMsg() CUTIL CUDA error: %s in file <%s>, line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 122 "sdk/cutil_inline_runtime.h"
exit(-1);
# 123 "sdk/cutil_inline_runtime.h"
}
# 132 "sdk/cutil_inline_runtime.h"
}
# 133 "sdk/cutil_inline_runtime.h"
inline void __cutilSafeMalloc(void *pointer, const char *file, const int line)
# 134 "sdk/cutil_inline_runtime.h"
{
# 135 "sdk/cutil_inline_runtime.h"
if (!(pointer)) {
# 136 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutilSafeMalloc host malloc failure in file <%s>, line %i\n", file, line);
# 138 "sdk/cutil_inline_runtime.h"
exit(-1);
# 139 "sdk/cutil_inline_runtime.h"
}
# 140 "sdk/cutil_inline_runtime.h"
}
# 145 "sdk/cutil_inline_runtime.h"
inline void cutilDeviceInit(int ARGC, char **ARGV)
# 146 "sdk/cutil_inline_runtime.h"
{
# 147 "sdk/cutil_inline_runtime.h"
int deviceCount;
# 148 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceCount(&deviceCount), "sdk/cutil_inline_runtime.h", 148);
# 149 "sdk/cutil_inline_runtime.h"
if (deviceCount == 0) {
# 150 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUTIL CUDA error: no devices supporting CUDA.\n");
# 151 "sdk/cutil_inline_runtime.h"
exit(-1);
# 152 "sdk/cutil_inline_runtime.h"
}
# 153 "sdk/cutil_inline_runtime.h"
int dev = 0;
# 154 "sdk/cutil_inline_runtime.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 155 "sdk/cutil_inline_runtime.h"
if (dev < 0) { dev = 0; } if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 157 "sdk/cutil_inline_runtime.h"
cudaDeviceProp deviceProp;
# 158 "sdk/cutil_inline_runtime.h"
__cudaSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev), "sdk/cutil_inline_runtime.h", 158);
# 159 "sdk/cutil_inline_runtime.h"
if ((deviceProp.major) < 1) {
# 160 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "cutil error: device does not support CUDA.\n");
# 161 "sdk/cutil_inline_runtime.h"
exit(-1); }
# 163 "sdk/cutil_inline_runtime.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 164 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "Using device %d: %s\n", dev, deviceProp.name); }
# 165 "sdk/cutil_inline_runtime.h"
__cudaSafeCall(cudaSetDevice(dev), "sdk/cutil_inline_runtime.h", 165);
# 166 "sdk/cutil_inline_runtime.h"
}
# 171 "sdk/cutil_inline_runtime.h"
inline void cutilCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 172 "sdk/cutil_inline_runtime.h"
{
# 173 "sdk/cutil_inline_runtime.h"
cudaError_t err = cudaGetLastError();
# 174 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 175 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "CUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 177 "sdk/cutil_inline_runtime.h"
exit(-1);
# 178 "sdk/cutil_inline_runtime.h"
}
# 179 "sdk/cutil_inline_runtime.h"
err = cudaThreadSynchronize();
# 180 "sdk/cutil_inline_runtime.h"
if ((cudaSuccess) != err) {
# 181 "sdk/cutil_inline_runtime.h"
fprintf(stderr, "CCUDA error: %s in file \'%s\' in line %i : %s.\n", errorMessage, file, line, cudaGetErrorString(err));
# 183 "sdk/cutil_inline_runtime.h"
exit(-1);
# 184 "sdk/cutil_inline_runtime.h"
}
# 185 "sdk/cutil_inline_runtime.h"
}
# 16 "sdk/cutil_inline_drvapi.h"
inline void __cuSafeCallNoSync(CUresult err, const char *file, const int line)
# 17 "sdk/cutil_inline_drvapi.h"
{
# 18 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 19 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n", err, file, line);
# 21 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 22 "sdk/cutil_inline_drvapi.h"
}
# 23 "sdk/cutil_inline_drvapi.h"
}
# 24 "sdk/cutil_inline_drvapi.h"
inline void __cuSafeCall(CUresult err, const char *file, const int line)
# 25 "sdk/cutil_inline_drvapi.h"
{
# 26 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(err, file, line);
# 27 "sdk/cutil_inline_drvapi.h"
}
# 29 "sdk/cutil_inline_drvapi.h"
inline void __cuCtxSync(const char *file, const int line)
# 30 "sdk/cutil_inline_drvapi.h"
{
# 31 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 32 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 33 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cuCtxSynchronize() API error = %04d in file <%s>, line %i.\n", err, file, line);
# 35 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 36 "sdk/cutil_inline_drvapi.h"
}
# 37 "sdk/cutil_inline_drvapi.h"
}
# 39 "sdk/cutil_inline_drvapi.h"
inline void __cuCheckMsg(const char *msg, const char *file, const int line)
# 40 "sdk/cutil_inline_drvapi.h"
{
# 41 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 42 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 43 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> %s", msg);
# 44 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "cutilDrvCheckMsg -> cuCtxSynchronize API error = %04d in file <%s>, line %i.\n", err, file, line);
# 46 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 47 "sdk/cutil_inline_drvapi.h"
}
# 48 "sdk/cutil_inline_drvapi.h"
}
# 54 "sdk/cutil_inline_drvapi.h"
inline void cutilDeviceInitDrv(int cuDevice, int ARGC, char **ARGV)
# 55 "sdk/cutil_inline_drvapi.h"
{
# 56 "sdk/cutil_inline_drvapi.h"
cuDevice = 0;
# 57 "sdk/cutil_inline_drvapi.h"
int deviceCount = 0;
# 58 "sdk/cutil_inline_drvapi.h"
CUresult err = cuInit(0);
# 59 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) == err) {
# 60 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGetCount(&deviceCount), "sdk/cutil_inline_drvapi.h", 60); }
# 61 "sdk/cutil_inline_drvapi.h"
if (deviceCount == 0) {
# 62 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "CUTIL DeviceInitDrv error: no devices supporting CUDA\n");
# 63 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 64 "sdk/cutil_inline_drvapi.h"
}
# 65 "sdk/cutil_inline_drvapi.h"
int dev = 0;
# 66 "sdk/cutil_inline_drvapi.h"
cutGetCmdLineArgumenti(ARGC, (const char **)ARGV, "device", &dev);
# 67 "sdk/cutil_inline_drvapi.h"
if (dev < 0) { dev = 0; }
# 68 "sdk/cutil_inline_drvapi.h"
if (dev > (deviceCount - 1)) { dev = (deviceCount - 1); }
# 69 "sdk/cutil_inline_drvapi.h"
__cuSafeCallNoSync(cuDeviceGet(&cuDevice, dev), "sdk/cutil_inline_drvapi.h", 69);
# 70 "sdk/cutil_inline_drvapi.h"
char name[100];
# 71 "sdk/cutil_inline_drvapi.h"
cuDeviceGetName(name, 100, cuDevice);
# 72 "sdk/cutil_inline_drvapi.h"
if ((cutCheckCmdLineFlag(ARGC, (const char **)ARGV, "quiet")) == (CUTFalse)) {
# 73 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Using device %d: %s\n", dev, name); }
# 74 "sdk/cutil_inline_drvapi.h"
}
# 78 "sdk/cutil_inline_drvapi.h"
inline void cutilDrvCudaCheckCtxLost(const char *errorMessage, const char *file, const int line)
# 79 "sdk/cutil_inline_drvapi.h"
{
# 80 "sdk/cutil_inline_drvapi.h"
CUresult err = cuCtxSynchronize();
# 81 "sdk/cutil_inline_drvapi.h"
if ((CUDA_ERROR_INVALID_CONTEXT) != err) {
# 82 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 84 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 85 "sdk/cutil_inline_drvapi.h"
}
# 86 "sdk/cutil_inline_drvapi.h"
err = cuCtxSynchronize();
# 87 "sdk/cutil_inline_drvapi.h"
if ((CUDA_SUCCESS) != err) {
# 88 "sdk/cutil_inline_drvapi.h"
fprintf(stderr, "Cuda error: %s in file \'%s\' in line %i\n", errorMessage, file, line);
# 90 "sdk/cutil_inline_drvapi.h"
exit(-1);
# 91 "sdk/cutil_inline_drvapi.h"
}
# 92 "sdk/cutil_inline_drvapi.h"
}
# 12 "sdk/cutil_inline.h"
inline void print_NVCC_min_spec(const char *sSDKsample, const char *sNVCCReq, const char *sDriverReq)
# 13 "sdk/cutil_inline.h"
{
# 14 "sdk/cutil_inline.h"
printf("CUDA %d.%02d Toolkit built this project.\n", 3010 / 1000, 3010 % 100);
# 15 "sdk/cutil_inline.h"
printf("  [ %s ] requirements:\n", sSDKsample);
# 16 "sdk/cutil_inline.h"
printf(" -> CUDA %s Toolkit\n", sNVCCReq);
# 17 "sdk/cutil_inline.h"
printf(" -> %s NVIDIA Display Driver.\n", sDriverReq);
# 18 "sdk/cutil_inline.h"
}
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/realtype.h"
typedef double real;
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
typedef
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
struct {
# 47 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float S;
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float X;
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float T;
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float R;
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float V;
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
} TOptionData;
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
typedef
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
struct __attribute__((__aligned__(8))) {
# 59 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float Expected;
# 60 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float Confidence;
# 61 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
} TOptionValue;
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
typedef
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
struct {
# 66 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
int device;
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
int optionCount;
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
TOptionData *optionData;
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
TOptionValue *callValue;
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
void *d_Buffer;
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
unsigned seed;
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
int pathN;
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float *d_Samples;
# 84 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
float time;
# 85 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_common.h"
} TOptionPlan;
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
template<class T, unsigned blockSize> __attribute__((unused)) void
# 51 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
sumReduceSharedMem(T *sum, T *sum2, int tid)
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
{int volatile ___ = 1;
# 64 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
exit(___);}
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
template<class T, int SUM_N, int blockSize> __attribute__((unused)) void
# 75 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
sumReduce(T *sum, T *sum2)
# 76 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
{int volatile ___ = 1;
# 91 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh"
exit(___);}
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
typedef
# 68 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
struct {
# 69 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real S;
# 70 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real X;
# 71 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real MuByT;
# 72 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real VBySqrtT;
# 73 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
} __TOptionData;
# 74 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static __TOptionData d_OptionData[2048];
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
typedef
# 77 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
struct {
# 78 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real Expected;
# 79 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
real Confidence;
# 80 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
} __TOptionValue;
# 81 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static __TOptionValue d_CallValue[2048];
# 94 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__attribute__((unused)) inline double endCallValue(double S, double X, double r, double MuByT, double VBySqrtT) {int volatile ___ = 1;
# 97 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
exit(___);}
# 109 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void MonteCarloKernel(__TOptionValue *
# 110 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
d_Buffer, float *
# 111 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
d_Samples, int
# 112 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
pathN) ;
# 147 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void MonteCarloOneBlockPerOption(float *
# 148 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
d_Samples, int
# 149 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
pathN) ;
# 191 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void MonteCarloReduce(__TOptionValue *
# 192 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
d_Buffer, int
# 193 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
accumN) ;
# 228 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void initMonteCarloGPU(TOptionPlan *plan) {
# 229 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 230 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 231 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 232 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int accumN = (256 * blocksPerOption);
# 233 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMalloc((void **)(&(plan->d_Buffer)), (accumN * (plan->optionCount)) * sizeof(__TOptionValue)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 236);
# 237 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 238 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 241 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void closeMonteCarloGPU(TOptionPlan *plan) {
# 242 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 243 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
if (doMultiBlock) { __cudaSafeCall(cudaFree(plan->d_Buffer), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 243); }
# 244 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 247 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
static void MonteCarloGPU(TOptionPlan *plan) {
# 248 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__TOptionData h_OptionData[2048];
# 249 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__TOptionValue h_CallValue[2048];
# 251 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
if (((plan->optionCount) <= 0) || ((plan->optionCount) > 2048)) {
# 252 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
printf("MonteCarloGPU(): bad option count.\n");
# 253 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
return;
# 254 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 256 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 257 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double T = (((plan->optionData)[i]).T);
# 258 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double R = (((plan->optionData)[i]).R);
# 259 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double V = (((plan->optionData)[i]).V);
# 260 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double MuByT = ((R - (((0.5) * V) * V)) * T);
# 261 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double VBySqrtT = (V * sqrt(T));
# 262 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).S) = ((real)(((plan->optionData)[i]).S));
# 263 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).X) = ((real)(((plan->optionData)[i]).X));
# 264 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).MuByT) = ((real)MuByT);
# 265 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((h_OptionData)[i]).VBySqrtT) = ((real)VBySqrtT);
# 266 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 268 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyToSymbol(d_OptionData, h_OptionData, (plan->optionCount) * sizeof(__TOptionData)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 272);
# 274 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int doMultiBlock = (((plan->pathN) / (plan->optionCount)) >= 8192);
# 275 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
if (doMultiBlock) {
# 276 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int blocksPerOption = (((plan->optionCount) < 16) ? 64 : 16);
# 277 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const int accumN = (256 * blocksPerOption);
# 278 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const dim3 gridMain(blocksPerOption, plan->optionCount);
# 279 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
cudaConfigureCall(gridMain, 256) ? ((void)0) : MonteCarloKernel((__TOptionValue *)(plan->d_Buffer), plan->d_Samples, plan->pathN);
# 284 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloKernel() execution failed\n", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 284);
# 285 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloReduce((__TOptionValue *)(plan->d_Buffer), accumN);
# 289 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloReduce() execution failed\n", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 289);
# 290 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
} else {
# 291 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
cudaConfigureCall(plan->optionCount, 256) ? ((void)0) : MonteCarloOneBlockPerOption(plan->d_Samples, plan->pathN);
# 295 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cutilCheckMsg("MonteCarloOneBlockPerOption() execution failed\n", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 295);
# 296 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 297 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
__cudaSafeCall(cudaMemcpyFromSymbol(h_CallValue, d_CallValue, (plan->optionCount) * sizeof(__TOptionValue)), "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh", 301);
# 303 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
for (int i = 0; i < (plan->optionCount); i++) {
# 304 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double RT = ((((plan->optionData)[i]).R) * (((plan->optionData)[i]).T));
# 305 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double sum = (((h_CallValue)[i]).Expected);
# 306 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double sum2 = (((h_CallValue)[i]).Confidence);
# 307 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
const double pathN = (plan->pathN);
# 309 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Expected) = ((float)((exp(-RT) * sum) / pathN));
# 311 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
double stdDev = sqrt(((pathN * sum2) - (sum * sum)) / (pathN * (pathN - (1))));
# 313 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
(((plan->callValue)[i]).Confidence) = ((float)(((exp(-RT) * (1.959999999999999964)) * stdDev) / sqrt(pathN)));
# 314 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 315 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 99 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
__attribute__((unused)) inline double MoroInvCNDgpu(double P) {int volatile ___ = 1;
# 137 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
exit(___);}
# 193 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
__attribute__((unused)) inline double AcklamInvCNDgpu(double P) {int volatile ___ = 1;
# 240 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
exit(___);}
# 248 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
static void inverseCNDKernel(float *
# 249 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
d_Output, float *
# 250 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
d_Input, unsigned
# 251 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
pathN) ;
# 274 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
static void inverseCNDgpu(float *d_Output, float *d_Input, unsigned N) {
# 275 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
cudaConfigureCall(128, 128) ? ((void)0) : inverseCNDKernel(d_Output, d_Input, N);
# 276 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
__cutilCheckMsg("inverseCNDKernel() execution failed.\n", "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh", 276);
# 277 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
}
# 44 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan) {
# 45 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
initMonteCarloGPU(plan);
# 46 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
}
# 48 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan) {
# 49 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
closeMonteCarloGPU(plan);
# 50 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
}
# 52 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
extern "C" void MonteCarlo_SM13(TOptionPlan *plan) {
# 53 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
MonteCarloGPU(plan);
# 54 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
}
# 56 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned N) {
# 57 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
inverseCNDgpu(d_Output, d_Input, N);
# 58 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu"
}
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_000022bd_00000000-3_MonteCarlo_SM13.fatbin.c" 1
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
# 2 "/tmp/tmpxft_000022bd_00000000-3_MonteCarlo_SM13.fatbin.c" 2



asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_13$:\n"
".quad 0x33010101464c457f,0x0000000000000002,0x0000000100be0002,0x00014b2c00000000\n"
".quad 0x000d000d00000034,0x0028000b00200034,0x0000000000010018,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000100000000\n"
".quad 0x0000000000000003,0x000003f400000000,0x000000000000033a,0x0000000400000000\n"
".quad 0x0000000b00000000,0x0000000000000003,0x0000072e00000000,0x00000000000000a7\n"
".quad 0x0000000100000000,0x0000001300000000,0x0000000000000002,0x000007d500000000\n"
".quad 0x00000002000001f0,0x0000000100000019,0x0000012b00000010,0x0000000600000001\n"
".quad 0x000009c500000000,0x00000003000003e8,0x000000041a00000c,0x000001c000000000\n"
".quad 0x0000000200000001,0x00000dad00000000,0x0000000000000018,0x0000000400000004\n"
".quad 0x0000015a00000000,0x0000000200000001,0x00000dc500000000,0x000000000000001c\n"
".quad 0x0000000100000004,0x0000018c00000000,0x0000000300000008,0x00000de100000000\n"
".quad 0x000000000000001c,0x0000000400000004,0x000000d600000000,0x0010000600000001\n"
".quad 0x00000de100000000,0x0000000300000938,0x000000041c00000a,0x000002d900000000\n"
".quad 0x0000000200000001,0x0000171900000000,0x0000000000000038,0x0000000400000008\n"
".quad 0x000000ff00000000,0x0000000200000001,0x0000175100000000,0x0000000000000018\n"
".quad 0x0000000100000008,0x000002ab00000000,0x0000000300000008,0x0000176900000000\n"
".quad 0x0000000000001018,0x0000000400000008,0x0000007900000000,0x0010000600000001\n"
".quad 0x0000176900000000,0x00000003000006b8,0x0000000411000008,0x0000022900000000\n"
".quad 0x0000000200000001,0x00001e2100000000,0x0000000000000020,0x000000040000000c\n"
".quad 0x000000a600000000,0x0000000200000001,0x00001e4100000000,0x0000000000000018\n"
".quad 0x000000010000000c,0x000001f700000000,0x0000000300000008,0x00001e5900000000\n"
".quad 0x0000000000001018,0x000000040000000c,0x0000003600000000,0x0000000600000001\n"
".quad 0x00001e5900000000,0x0000000300002c78,0x0000000418000006,0x0000028300000000\n"
".quad 0x0000000200000001,0x00004ad100000000,0x0000000000000030,0x0000000400000010\n"
".quad 0x0000005600000000,0x0000000200000001,0x00004b0100000000,0x000000000000001c\n"
".quad 0x0000000100000010,0x0000025e00000000,0x0000000300000008,0x00004b1d00000000\n"
".quad 0x000000000000001c,0x0000000400000010,0x0000032c00000000,0x0000000200000001\n"
".quad 0x00004b1d00000000,0x0000000000010000,0x0000000400000000,0x0000030a00000000\n"
".quad 0x0000000200000001,0x00014b1d00000000,0x0000000000000004,0x0000000800000000\n"
".quad 0x0000031900000000,0x0000000000000009,0x00014b2100000000,0x0000000300000008\n"
".quad 0x0000000400000015,0x0000002b00000008,0x0000000300000008,0x00014b2900000000\n"
".quad 0x0000000000008000,0x0000000400000000,0x68732e0000000000,0x2e00626174727473\n"
".quad 0x2e00626174727473,0x2e006261746d7973,0x61626f6c672e766e,0x2e0074696e692e6c\n"
".quad 0x61626f6c672e766e,0x2e747865742e006c,0x65766e6936315a5f,0x654b444e43657372\n"
".quad 0x5f5366506c656e72,0x6e692e766e2e006a,0x6936315a5f2e6f66,0x4e4365737265766e\n"
".quad 0x506c656e72654b44,0x65742e006a5f5366,0x4d36315a5f2e7478,0x6c72614365746e6f\n"
".quad 0x506563756465526f,0x74704f545f5f3431,0x65756c61566e6f69,0x6e692e766e2e0069\n"
".quad 0x4d36315a5f2e6f66,0x6c72614365746e6f,0x506563756465526f,0x74704f545f5f3431\n"
".quad 0x65756c61566e6f69,0x2e747865742e0069,0x746e6f4d37325a5f,0x6e4f6f6c72614365\n"
".quad 0x65506b636f6c4265,0x506e6f6974704f72,0x692e766e2e006966,0x37325a5f2e6f666e\n"
".quad 0x72614365746e6f4d,0x6f6c42656e4f6f6c,0x74704f7265506b63,0x2e006966506e6f69\n"
".quad 0x315a5f2e74786574,0x614365746e6f4d36,0x656e72654b6f6c72,0x4f545f5f3431506c\n"
".quad 0x6c61566e6f697470,0x6e2e006966506575,0x5f2e6f666e692e76,0x65746e6f4d36315a\n"
".quad 0x72654b6f6c726143,0x5f5f3431506c656e,0x566e6f6974704f54,0x0069665065756c61\n"
".quad 0x726168732e766e2e,0x4d36315a5f2e6465,0x6c72614365746e6f,0x506c656e72654b6f\n"
".quad 0x74704f545f5f3431,0x65756c61566e6f69,0x2e766e2e00696650,0x746e6174736e6f63\n"
".quad 0x6f4d36315a5f2e31,0x6f6c72614365746e,0x31506c656e72654b,0x6974704f545f5f34\n"
".quad 0x5065756c61566e6f,0x732e766e2e006966,0x5a5f2e6465726168,0x4365746e6f4d3631\n"
".quad 0x756465526f6c7261,0x545f5f3431506563,0x61566e6f6974704f,0x766e2e006965756c\n"
".quad 0x6e6174736e6f632e,0x4d36315a5f2e3174,0x6c72614365746e6f,0x506563756465526f\n"
".quad 0x74704f545f5f3431,0x65756c61566e6f69,0x68732e766e2e0069,0x315a5f2e64657261\n"
".quad 0x65737265766e6936,0x656e72654b444e43,0x2e006a5f5366506c,0x74736e6f632e766e\n"
".quad 0x315a5f2e31746e61,0x65737265766e6936,0x656e72654b444e43,0x2e006a5f5366506c\n"
".quad 0x65726168732e766e,0x6f4d37325a5f2e64,0x6f6c72614365746e,0x6b636f6c42656e4f\n"
".quad 0x6f6974704f726550,0x766e2e006966506e,0x6e6174736e6f632e,0x4d37325a5f2e3174\n"
".quad 0x6c72614365746e6f,0x636f6c42656e4f6f,0x6974704f7265506b,0x6e2e006966506e6f\n"
".quad 0x6174736e6f632e76,0x65722e003431746e,0x6e6f632e766e2e6c,0x003431746e617473\n"
".quad 0x736e6f632e766e2e,0x5f000030746e6174,0x7265766e6936315a,0x72654b444e436573\n"
".quad 0x6a5f5366506c656e,0x6e6f4d36315a5f00,0x526f6c7261436574,0x3431506563756465\n"
".quad 0x6f6974704f545f5f,0x006965756c61566e,0x746e6f4d37325a5f,0x6e4f6f6c72614365\n"
".quad 0x65506b636f6c4265,0x506e6f6974704f72,0x4d36315a5f006966,0x6c72614365746e6f\n"
".quad 0x506c656e72654b6f,0x74704f545f5f3431,0x65756c61566e6f69,0x61435f6400696650\n"
".quad 0x0065756c61566c6c,0x6e6f6974704f5f64,0x0000000061746144,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000001000300,0x0000000000000000\n"
".quad 0x0000000002000300,0x0000000000000000,0x0000000003000300,0x0000000000000000\n"
".quad 0x0000000000000300,0x0000000000000000,0x0000000017000300,0x002c780000000000\n"
".quad 0x0000000010000300,0x0000000000000000,0x0000000012000300,0x0006b80000000000\n"
".quad 0x000000000c000300,0x0000000000000000,0x000000000e000300,0x0009380000000000\n"
".quad 0x0000000008000300,0x0000000000000000,0x000000000a000300,0x0003e80000000000\n"
".quad 0x0000000004000300,0x0000000000000000,0x0000000006000300,0x0000000000000000\n"
".quad 0x0000000007000300,0x0000000000000000,0x0000000005000300,0x0000000000000000\n"
".quad 0x000000000f000300,0x0000000000000000,0x000000000d000300,0x0000000000000000\n"
".quad 0x0000000013000300,0x0000000000000000,0x0000000011000300,0x0000000000000000\n"
".quad 0x000000000b000300,0x0000000000000000,0x0000000009000300,0x0000000000000000\n"
".quad 0x0000000015000300,0x0000000000000000,0x0000000016000300,0x0000000000000000\n"
".quad 0x0000010014000300,0x0000000000000000,0x00001b0010101200,0x0000000000000000\n"
".quad 0x000042000c101200,0x0000000000000000,0x0000650008101200,0x0000000000000000\n"
".quad 0x00008e0004101200,0x0080000000000000,0x00009a0017001100,0x0100000000000000\n"
".quad 0x0002050014001100,0x0000054000478010,0x014c5104000780a0,0x14cdfd0020478060\n"
".quad 0x0730036c20c7c830,0x004e3100000000a0,0x06e00304200780a0,0x0518050000028010\n"
".quad 0x000201c000078000,0x0228054000478010,0x02cc39c410078030,0x008009c430078030\n"
".quad 0x00800d0000000310,0x0008110000000310,0x000a152400c78014,0x000c192400c78014\n"
".quad 0x000e1d2400c78014,0x0004212400c78014,0x0006252400c78014,0x0000292400c78014\n"
".quad 0x00022d2400c78014,0x0028342400c78014,0x0eea5c2101ea5841,0x0006051002840021\n"
".quad 0x021a550403c78010,0x0e2c39c410078030,0x001c3980c00780d0,0x0e0c39c4400780a0\n"
".quad 0x029c4040010780e0,0x8023fd10009e4410,0x8123fd6c4047c830,0x0640036440c14830\n"
".quad 0x00224100000000a0,0x05b0030603c78010,0x3e80410000010010,0x0780450652b82f10\n"
".quad 0x101c4103ff715710,0x00204180000780e0,0x002061cc404780a0,0x8231fd88464780a0\n"
".quad 0x0030616c4107c830,0x000a650441050021,0x0006652440c50010,0x2f80492440c28010\n"
".quad 0x02804d0fefa39f10,0x1220390bfe62e710,0x3f804940038780e0,0x1e804d03b3980310\n"
".quad 0x1220390bc7abcb10,0x2d804140038780e0,0x3f80450ccf58bb10,0x2f804903e21f0710\n"
".quad 0x01804d0da6c3bb10,0x101c4103e5afdb10,0x26804940048780e0,0x15804d0f60f80f10\n"
".quad 0x101c4103e927e710,0x26804940048780e0,0x1a804d08f02d6710,0x101c4103ec71df10\n"
".quad 0x20804940048780e0,0x20804d013b894f10,0x101c4103efa01b10,0x08804940048780e0\n"
".quad 0x20804d01d3af7b10,0x101c4103f2a01b10,0x2c804940048780e0,0x2c804d016c3a1f10\n"
".quad 0x101c4103f56c1710,0x21804940048780e0,0x11804d0111091710,0x101c4103f8111310\n"
".quad 0x01804940048780e0,0x15804d0555554f10,0x101c4103fa555710,0x2f804940048780e0\n"
".quad 0x15804d0555555710,0x101c4103fc555710,0x00804940048780e0,0x00804d0000000310\n"
".quad 0x101c4103fe000310,0x101c4140048780e0,0x14304980000780e0,0x0e2041c410078030\n"
".quad 0x00f83940038780e0,0x00a43d0403c78010,0x0e203903fe000320,0x00f84140038780e0\n"
".quad 0x0032450603c78010,0x101c410403c78010,0x06400380000780e0,0x7c21fd0000078010\n"
".quad 0x0080496c0187c830,0x00804d0000000310,0x00804107ff000310,0x0080450000000310\n"
".quad 0x121dfd0000000310,0x002645e010c7d8e0,0x0024410403c28010,0x001c410403c28010\n"
".quad 0x10144160039500e0,0x00803948020782e0,0x00803d0000000310,0x002a590000000310\n"
".quad 0x0e20390405878020,0x172dfdc0000780e0,0x001c09640047c830,0x0e1c0160008780e0\n"
".quad 0x01900340000780e0,0x0730030000028010,0x0080090000078010,0x00800d0000000310\n"
".quad 0x0022200000000310,0x0006051002840011,0x0848350403c78010,0x1b30110020078040\n"
".quad 0x1a32110000078240,0x1008110001078060,0x1a3011c410078030,0x0008110001078060\n"
".quad 0x0408110405078020,0x00c811c410078030,0x0e08090421078020,0x088809a0800780d0\n"
".quad 0x0e04010000000320,0x874911a0800781d0,0xfffc0340862e42c0,0x00003740000000ff\n"
".quad 0x0c0b043c90000000,0x0000040000000000,0x080d040000000800,0x0000200022011000\n"
".quad 0x000780a000004d00,0x40c7d03080260104,0x0147c8a00001fd6c,0x000000a00800030c\n"
".quad 0x03c7801000264900,0x0011001008000306,0x200780a0004c0100,0x200780a000425104\n"
".quad 0x1007803003240504,0x00078000050005c4,0x10078030032855c0,0x00000320188259c4\n"
".quad 0x0000832018825d00,0x00c7801400081900,0x00c78014000a1d24,0x00c78014000c2124\n"
".quad 0x00c78014000e2524,0x00c7801400042924,0x00c7801400062d24,0x00c7801400003124\n"
".quad 0x00c7801400023524,0x20c7d83013cbfd24,0x000000a00760036c,0x0012801007300300\n"
".quad 0x1007803002260100,0x3007803002ca05c4,0x00000310008009c4,0x0000031000800d00\n"
".quad 0x01e8642100e86000,0x0286041000840021,0xc00780d00e301110,0x400780a000081180\n"
".quad 0x018780e0041011c4,0x028a3c1000883840,0x4047d830811ffd10,0x40d15830821ffd6c\n"
".quad 0x000000a006900364,0x03c78010001e3900,0x0011001006000304,0x52b82f103e803900\n"
".quad 0xff71571007803d06,0x000780e00e083903,0x404780a0001c3980,0x464780a0001c69cc\n"
".quad 0x4107d8308335fd88,0x431500210034696c,0x40d50010001a6d04,0x40d2801000166d24\n"
".quad 0xefa39f102f804124,0xfe62e7100280450f,0x010780e0101c110b,0xb39803103f804140\n"
".quad 0xc7abcb101e804503,0x010780e0101c110b,0xcf58bb102d803940,0xe21f07103f803d0c\n"
".quad 0xa6c3bb102f804103,0xe5afdb100180450d,0x040780e00e083903,0x60f80f1026804140\n"
".quad 0xe927e7101580450f,0x040780e00e083903,0xf02d671026804140,0xec71df101a804508\n"
".quad 0x040780e00e083903,0x3b894f1020804140,0xefa01b1020804501,0x040780e00e083903\n"
".quad 0xd3af7b1008804140,0xf2a01b1020804501,0x040780e00e083903,0x6c3a1f102c804140\n"
".quad 0xf56c17102c804501,0x040780e00e083903,0x1109171021804140,0xf811131011804501\n"
".quad 0x040780e00e083903,0x55554f1001804140,0xfa55571015804505,0x040780e00e083903\n"
".quad 0x555557102f804140,0xfc55571015804505,0x040780e00e083903,0x0000031000804140\n"
".quad 0xfe00031000804500,0x040780e00e083903,0x000780e00e083940,0x010780e0041c1180\n"
".quad 0x1007803014343d40,0x03c7801000f839c4,0xfe000320009e3d06,0x038780e00e081103\n"
".quad 0x03c7801000f83940,0x03c7801000363d04,0x000780e00e083906,0x0007801006900380\n"
".quad 0x0187d8307c1dfd00,0x000003100080416c,0xff00031000804500,0x0000031000803907\n"
".quad 0x0000031000803d00,0x10c7e8e01009fd00,0x03d2801000223de0,0x03d2801000203904\n"
".quad 0x012500e000083904,0x028782e00e183960,0x0000031000801148,0x0000031000801500\n"
".quad 0x0000432000b06100,0x000780e0041c1100,0x0047d8301931fdc0,0x008780e000080964\n"
".quad 0x000780e004080160,0x0012801001e00340,0x0007801007600300,0x0000031000800900\n"
".quad 0x0000031000800d00,0x0286041000840000,0x00078200002c0510,0x20878004000001c0\n"
".quad 0x20c78004000201e4,0x0507802000264de4,0x00078000002e0504,0x40c7d8308027fdc0\n"
".quad 0x200780040000016c,0x20478004000201e4,0x15ac582015ae5ce4,0x0012801001500320\n"
".quad 0x000002f000000100,0x000000a011d003e0,0x03c7801000240100,0x0001001011d00304\n"
".quad 0x000000861ffe0300,0x4107c8308401fd00,0x000000a00960036c,0x0002801009600300\n"
".quad 0x0007800003000500,0x00ee0c1500ec08c0,0x00c78014020c1115,0x00c78014020e1544\n"
".quad 0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4\n"
".quad 0x00c78014040e0d44,0x00c78014060c1144,0x00c78014060e1544,0x010780e000040944\n"
".quad 0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x4107c8308501fd00,0x000000a00a90036c,0x000280100a900300,0x0007800003000500\n"
".quad 0x00ee0c1500ec08c0,0x00c78014010c1115,0x00c78014010e1544,0x010780e000040944\n"
".quad 0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44\n"
".quad 0x00c78014050c1144,0x00c78014050e1544,0x010780e000040944,0x20878004040c0160\n"
".quad 0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308601fd00\n"
".quad 0x000000a00bc0036c,0x000280100bc00300,0x0007800003000500,0x00ee0c1500ec08c0\n"
".quad 0x00c78014008c1115,0x00c78014008e1544,0x010780e000040944,0x20878004000c0160\n"
".quad 0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014048c1144\n"
".quad 0x00c78014048e1544,0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308701fd00,0x000000a00cf0036c\n"
".quad 0x000280100cf00300,0x0007800003000500,0x00ee0c1500ec08c0,0x00c78014004c1115\n"
".quad 0x00c78014004e1544,0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4\n"
".quad 0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014044c1144,0x00c78014044e1544\n"
".quad 0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x4107c8308801fd00,0x000000a00e20036c,0x000280100e200300\n"
".quad 0x0007800003000500,0x00ee0c1500ec08c0,0x00c78014002c1115,0x00c78014002e1544\n"
".quad 0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4\n"
".quad 0x00c78014040e0d44,0x00c78014042c1144,0x00c78014042e1544,0x010780e000040944\n"
".quad 0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x4107c8308901fd00,0x000000a00f40036c,0x000280100f400300,0x0007800003000500\n"
".quad 0x00ee0c1500ec08c0,0x00fe141500fc1015,0x010780e000040915,0x20878004000c0160\n"
".quad 0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014041c1144\n"
".quad 0x00c78014041e1544,0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308a01fd00,0x000000a01060036c\n"
".quad 0x0002801010600300,0x0007800003000500,0x00ee0c1500ec08c0,0x00f6141500f41015\n"
".quad 0x010780e000040915,0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4\n"
".quad 0x00c78014040e0d44,0x00c7801404141144,0x00c7801404161544,0x010780e000040944\n"
".quad 0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x0107c8307c01fd00,0x000000a01180036c,0x0002801011800300,0x0007800003000500\n"
".quad 0x00ee0c1500ec08c0,0x00f2141500f01015,0x010780e000040915,0x20878004000c0160\n"
".quad 0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44,0x00c7801404101144\n"
".quad 0x00c7801404121544,0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x0000132000800100,0x40c7c8308001fd00\n"
".quad 0x000280100840036c,0x0147ca307c25fd00,0x0002803000000364,0x0000031010001100\n"
".quad 0x00ee041100ec0000,0xa0078061044c0911,0x800780d00e040103,0x00c78010040c01a0\n"
".quad 0x00c78010040e0544,0x0000032008840944,0x800781d00e040100,0x874911000000ffa0\n"
".quad 0xfffc0340862e42c0,0x00003f0000007fff,0x00000f0000001f00,0x0000030000000700\n"
".quad 0x0000000000000100,0x9000000000003740,0x00000000080b043c,0x080d040000000400\n"
".quad 0x0000200023011800,0x000780a000000500,0x40c7d03080020104,0x0147c8a00001fd6c\n"
".quad 0x000000a00300030c,0x03c7801000020100,0x0011001003000306,0x00c78010000a0900\n"
".quad 0x20078040054c0d44,0x1007803010060d00,0x20c78060044c09c4,0x200780a000422900\n"
".quad 0x1007803003000d04,0x10078030040409c4,0x10078030031435c4,0x00000320188631c4\n"
".quad 0x0000832018862d00,0x2087802000c83900,0x20c7d83001cbfd04,0x000000a00260036c\n"
".quad 0x0012801002300300,0x1007803004020900,0x3007803004ca0dc4,0x00000310008011c4\n"
".quad 0x0000031000801500,0x039c40200e843c00,0x028a0c1000880820,0x00000320089e1910\n"
".quad 0x800780d00e1e2100,0x800780d00e0c1980,0x010780e000101180,0x008780e0000c0960\n"
".quad 0x00010320009e3d60,0x0047d830101ffd00,0x0012801001a00364,0x0007801002600300\n"
".quad 0x0000031000801100,0x0000031000801500,0x028a0c1000880800,0x0007820000180510\n"
".quad 0x21078004000001c0,0x21478004000201e4,0x02878020000205e4,0x0007800000160504\n"
".quad 0x40c7d8308003fdc0,0x208780040000016c,0x20c78004000201e4,0x0d9830200d962ce4\n"
".quad 0x0012801001100320,0x000002f000000100,0x000000a00cd003e0,0x03c7801000000500\n"
".quad 0x000100100cd00304,0x000000861ffe0300,0x4107c8308103fd00,0x000000a00460036c\n"
".quad 0x0002801004600300,0x0007800003020500,0x00ee0c1500ec08c0,0x00c78014020c1115\n"
".quad 0x00c78014020e1544,0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4\n"
".quad 0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014060c1144,0x00c78014060e1544\n"
".quad 0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x4107c8308203fd00,0x000000a00590036c,0x0002801005900300\n"
".quad 0x0007800003020500,0x00ee0c1500ec08c0,0x00c78014010c1115,0x00c78014010e1544\n"
".quad 0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4\n"
".quad 0x00c78014040e0d44,0x00c78014050c1144,0x00c78014050e1544,0x010780e000040944\n"
".quad 0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0\n"
".quad 0x4107c8308303fd00,0x000000a006c0036c,0x0002801006c00300,0x0007800003020500\n"
".quad 0x00ee0c1500ec08c0,0x00c78014008c1115,0x00c78014008e1544,0x010780e000040944\n"
".quad 0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44\n"
".quad 0x00c78014048c1144,0x00c78014048e1544,0x010780e000040944,0x20878004040c0160\n"
".quad 0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308403fd00\n"
".quad 0x000000a007f0036c,0x0002801007f00300,0x0007800003020500,0x00ee0c1500ec08c0\n"
".quad 0x00c78014004c1115,0x00c78014004e1544,0x010780e000040944,0x20878004000c0160\n"
".quad 0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014044c1144\n"
".quad 0x00c78014044e1544,0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308503fd00,0x000000a00920036c\n"
".quad 0x0002801009200300,0x0007800003020500,0x00ee0c1500ec08c0,0x00c78014002c1115\n"
".quad 0x00c78014002e1544,0x010780e000040944,0x20878004000c0160,0x20c78004000e01e4\n"
".quad 0x00c78014040c09e4,0x00c78014040e0d44,0x00c78014042c1144,0x00c78014042e1544\n"
".quad 0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x4107c8308603fd00,0x000000a00a40036c,0x000280100a400300\n"
".quad 0x0007800003020500,0x00ee0c1500ec08c0,0x00fe141500fc1015,0x010780e000040915\n"
".quad 0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44\n"
".quad 0x00c78014041c1144,0x00c78014041e1544,0x010780e000040944,0x20878004040c0160\n"
".quad 0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0,0x4107c8308703fd00\n"
".quad 0x000000a00b60036c,0x000280100b600300,0x0007800003020500,0x00ee0c1500ec08c0\n"
".quad 0x00f6141500f41015,0x010780e000040915,0x20878004000c0160,0x20c78004000e01e4\n"
".quad 0x00c78014040c09e4,0x00c78014040e0d44,0x00c7801404141144,0x00c7801404161544\n"
".quad 0x010780e000040944,0x20878004040c0160,0x20c78004040e01e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x0107c8307c03fd00,0x000000a00c80036c,0x000280100c800300\n"
".quad 0x0007800003020500,0x00ee0c1500ec08c0,0x00f2141500f01015,0x010780e000040915\n"
".quad 0x20878004000c0160,0x20c78004000e01e4,0x00c78014040c09e4,0x00c78014040e0d44\n"
".quad 0x00c7801404101144,0x00c7801404121544,0x010780e000040944,0x20878004040c0160\n"
".quad 0x20c78004040e01e4,0x000002f0000001e4,0x000000861ffe03e0,0x0000132000820500\n"
".quad 0x40c7c8308003fd00,0x000280100340036c,0x0147ca307c01fd00,0x0002803000000364\n"
".quad 0x0000031010001100,0x00ee041100ec0000,0xa0078061044c0911,0x800780d00e040103\n"
".quad 0x00c78010040c01a0,0x00c78010040e0544,0x0000032008840944,0x800781d00e040100\n"
".quad 0x00007f000000ffa0,0x00001f0000003f00,0x0000070000000f00,0x0000010000000300\n"
".quad 0x00000000080b0400,0x080d040000000400,0x0000200022011000,0x2087c8307ccbfd00\n"
".quad 0x200780a0004c0564,0x200780a000423104,0x000780a000000104,0x0002801020c00304\n"
".quad 0x0007806001180100,0x20c7c83000cdfd60,0x0002803000000364,0x200780a000480500\n"
".quad 0x1007803002000904,0x3007803002cc0dc4,0x02ea4440411800c4,0x03ea482102e84c21\n"
".quad 0x1007803002004121,0xc00780d00e2201c4,0x0000031000800980,0xff00031000800d00\n"
".quad 0x400780a000001103,0x0187c8e00209fdc4,0x00000310008001e0,0x0000031000800500\n"
".quad 0x00c148e00009fd00,0x000000a0205003e0,0x0001001001b00300,0x0000031000800900\n"
".quad 0xff80031000800d00,0x000780102050030f,0x0000031000800100,0xfe00031000800500\n"
".quad 0xe147af102180090b,0xfdae171007800d0a,0x000780e000080103,0x1047c8e00201fd60\n"
".quad 0x000000a0204003e0,0x0001001004100300,0x000780e000001900,0x7377771038802180\n"
".quad 0x03970f1029802505,0x473c6f103c80110c,0x044b23101280150c,0x0558a71007802904\n"
".quad 0x0090bf1030802d02,0x701e57103d800904,0x0350ff102f800d00,0x010780e0080c110c\n"
".quad 0x008780e00a0c2940,0xe54a3f101e802140,0x0329d7103080250a,0x181503102c80090c\n"
".quad 0x0371571017800d09,0x020780e0040c1104,0x008780e00a0c2940,0xb28623100d802140\n"
".quad 0x0040db1013802501,0x655073102d800904,0x020f271030800d00,0x020780e0040c110c\n"
".quad 0x008780e00a0c2140,0x0000031000800940,0xff00031000800d00,0x000780e004000103\n"
".quad 0x008780e0080c0980,0x0007802041500340,0x00820c1002800800,0x0007801020400310\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0107c8e00201fd00,0x000000a01e4003e0\n"
".quad 0x0001001011700300,0x0000031000800900,0xff00031000800d00,0x008780e000081103\n"
".quad 0x0000031000800964,0x0000031000800d00,0x0107c8e00209fd00,0x00000310008019e0\n"
".quad 0xff00031000801d00,0x008a0c1002880807,0x0042c8e00609fd10,0x000000a00ad003e0\n"
".quad 0x03c7801000061900,0x0001001009b00306,0x4107c830800dfd00,0x40c50010000a0964\n"
".quad 0x40c50010000c0d24,0x000500e002080924,0x40c50010000e1180,0x40c2801000081124\n"
".quad 0x400780d081061924,0x1007803014061504,0x404780d0820c0dec,0x0147802000085104\n"
".quad 0x40c7c8308307fd04,0x02861c1000841864,0x42050021000e1d10,0x4245002100285104\n"
".quad 0x0000031000801104,0xff00031000801500,0x010780e0000c2103,0x404780a000100960\n"
".quad 0x00078090000409c0,0x400780a000040900,0x010780e0021011c4,0x0000031000802144\n"
".quad 0xff00031000802500,0x010780e00408110b,0x020780e0000c2140,0x008780e002081960\n"
".quad 0x000780e006100940,0x008780e000041180,0xae80f3101e802960,0xeb1383100b802d03\n"
".quad 0xb7a8b31004803103,0xed0ee31025803508,0x000780e004080903,0x030780e00a042980\n"
".quad 0xf02677102f803140,0xef3b271026803509,0x030780e00a042903,0x9ab0971016803140\n"
".quad 0xf1745f100b80350a,0x030780e00a042903,0xd1b5171014803140,0xf3c71f1007803502\n"
".quad 0x030780e00a042903,0x23be73102d803140,0xf624931024803509,0x030780e00a042903\n"
".quad 0x999a3f1004803140,0xf8999b1019803509,0x020780e000083903,0x030780e00a042964\n"
".quad 0x5555571014803140,0xfb55571015803505,0x038780e0001c3903,0x030780e00a042960\n"
".quad 0x038780e008082140,0x410780a000283144,0x0000033000a85144,0xefa39f102f803900\n"
".quad 0xfe62e71002803d0f,0x000780e00a040903,0x000780e0080c1980,0x410780a000282180\n"
".quad 0x010780e00e182944,0x028780e00e102140,0x018780e002080940,0x020780e000081140\n"
".quad 0x010780e000041164,0xb39803103f800968,0xc7abcb101e800d03,0x010780e002180903\n"
".quad 0x008780e000141140,0x000780100ad00360,0x0000031000800900,0xff00031000800d00\n"
".quad 0x10c7c8e00209fd07,0x000280100a1003e0,0x010780e000081100,0x000780100ad00360\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0087c8e00209fd00,0x000100100a8003e0\n"
".quad 0x0000031000801100,0xff00031000801500,0x000780100ad0030f,0x0000031000800900\n"
".quad 0xff00031000800d00,0x0087c8e00209fd07,0x40c10010001411e0,0x40c1001000161524\n"
".quad 0x404782a000081924,0x00000310008009e4,0x0000031000800d00,0x0107c8e0020dfd00\n"
".quad 0x00000310008021e0,0xff00031000802500,0x028e0c10008c0807,0x0042c8e0080dfd10\n"
".quad 0x000000a0115003e0,0x03c7801000062100,0x0001001010000304,0x4107c8308011fd00\n"
".quad 0x40c50010000a0964,0x40c50010000c0d24,0x000500e0020c0924,0x40c50010000e1180\n"
".quad 0x40c2801000081124,0x400780d081061924,0x1007803014061504,0x404780d0820c0dec\n"
".quad 0x0147802000085104,0x40c7c8308307fd04,0x00861c1002841864,0x42050021000e1d10\n"
".quad 0x4245002100285104,0x0000031000801104,0xff00031000801500,0x010780e0000c2103\n"
".quad 0x404780a000100960,0x00078090000409c0,0x400780a000040900,0x010780e0021011c4\n"
".quad 0x0000031000802144,0xff00031000802500,0x010780e00408110b,0x020780e0000c2140\n"
".quad 0x008780e002081960,0x000780e006100940,0x008780e000041180,0xae80f3101e802960\n"
".quad 0xeb1383100b802d03,0xb7a8b31004803103,0xed0ee31025803508,0x000780e004080903\n"
".quad 0x030780e00a042980,0xf02677102f803140,0xef3b271026803509,0x030780e00a042903\n"
".quad 0x9ab0971016803140,0xf1745f100b80350a,0x030780e00a042903,0xd1b5171014803140\n"
".quad 0xf3c71f1007803502,0x030780e00a042903,0x23be73102d803140,0xf624931024803509\n"
".quad 0x030780e00a042903,0x999a3f1004803140,0xf8999b1019803509,0x020780e000083903\n"
".quad 0x030780e00a042964,0x5555571014803140,0xfb55571015803505,0x038780e0001c3903\n"
".quad 0x030780e00a042960,0x038780e008082140,0x410780a000283144,0x0000033000a85144\n"
".quad 0xefa39f102f803900,0xfe62e71002803d0f,0x000780e00a040903,0x000780e0080c1980\n"
".quad 0x410780a000282180,0x010780e00e182944,0x028780e00e102140,0x018780e002080940\n"
".quad 0x020780e000081140,0x010780e000041164,0xb39803103f800968,0xc7abcb101e800d03\n"
".quad 0x010780e002180903,0x008780e000140940,0x0007801011500360,0x0000031000800900\n"
".quad 0xff00031000800d00,0x10c7c8e00209fd07,0x00028010107003e0,0x010780e000080900\n"
".quad 0x404780a000040960,0x00078010115003e4,0x0000031000800900,0x0000031000800d00\n"
".quad 0x0087c8e0020dfd00,0x0001001010e003e0,0x0000031000800900,0xff00031000800d00\n"
".quad 0x000780101150030f,0x0000031000800900,0xff00031000800d00,0x0087c8e0020dfd07\n"
".quad 0x03c68010000c09e0,0x03c68010000e0d06,0x40c1001000140904,0x40c1001000160d24\n"
".quad 0x000002f000000124,0x000780101e4003e0,0x0000031000800900,0x0000031000800d00\n"
".quad 0x0107c8e00209fd00,0x00000310008019e0,0xff00031000801d00,0x008a0c1002880807\n"
".quad 0x0042c8e00609fd10,0x000000a017b003e0,0x03c7801000061900,0x0001001016900306\n"
".quad 0x4107c830800dfd00,0x40c50010000a0964,0x40c50010000c0d24,0x000500e002080924\n"
".quad 0x40c50010000e1180,0x40c2801000081124,0x400780d081061924,0x1007803014061504\n"
".quad 0x404780d0820c0dec,0x0147802000085104,0x40c7c8308307fd04,0x02861c1000841864\n"
".quad 0x42050021000e1d10,0x4245002100285104,0x0000031000801104,0xff00031000801500\n"
".quad 0x010780e0000c2103,0x404780a000100960,0x00078090000409c0,0x400780a000040900\n"
".quad 0x010780e0021011c4,0x0000031000802144,0xff00031000802500,0x010780e00408110b\n"
".quad 0x020780e0000c2140,0x008780e002081960,0x000780e006100940,0x008780e000041180\n"
".quad 0xae80f3101e802960,0xeb1383100b802d03,0xb7a8b31004803103,0xed0ee31025803508\n"
".quad 0x000780e004080903,0x030780e00a042980,0xf02677102f803140,0xef3b271026803509\n"
".quad 0x030780e00a042903,0x9ab0971016803140,0xf1745f100b80350a,0x030780e00a042903\n"
".quad 0xd1b5171014803140,0xf3c71f1007803502,0x030780e00a042903,0x23be73102d803140\n"
".quad 0xf624931024803509,0x030780e00a042903,0x999a3f1004803140,0xf8999b1019803509\n"
".quad 0x020780e000083903,0x030780e00a042964,0x5555571014803140,0xfb55571015803505\n"
".quad 0x038780e0001c3903,0x030780e00a042960,0x038780e008082140,0x410780a000283144\n"
".quad 0x0000033000a85144,0xefa39f102f803900,0xfe62e71002803d0f,0x000780e00a040903\n"
".quad 0x000780e0080c1980,0x410780a000282180,0x010780e00e182944,0x028780e00e102140\n"
".quad 0x018780e002080940,0x020780e000081140,0x010780e000041164,0xb39803103f800968\n"
".quad 0xc7abcb101e800d03,0x010780e002180903,0x008780e000141140,0x0007801017b00360\n"
".quad 0x0000031000800900,0xff00031000800d00,0x10c7c8e00209fd07,0x0002801016f003e0\n"
".quad 0x010780e000081100,0x0007801017b00360,0x0000031000800900,0x0000031000800d00\n"
".quad 0x0087c8e00209fd00,0x00010010176003e0,0x0000031000801100,0xff00031000801500\n"
".quad 0x0007801017b0030f,0x0000031000800900,0xff00031000800d00,0x0087c8e00209fd07\n"
".quad 0x40c10010001411e0,0x40c1001000161524,0x404782a000081924,0x00000310008009e4\n"
".quad 0x0000031000800d00,0x0107c8e0020dfd00,0x00000310008021e0,0xff00031000802500\n"
".quad 0x028e0c10008c0807,0x0042c8e0080dfd10,0x000000a01e3003e0,0x03c7801000062100\n"
".quad 0x000100101ce00304,0x4107c8308011fd00,0x40c50010000a0964,0x40c50010000c0d24\n"
".quad 0x000500e0020c0924,0x40c50010000e1180,0x40c2801000081124,0x400780d081061924\n"
".quad 0x1007803014061504,0x404780d0820c0dec,0x0147802000085104,0x40c7c8308307fd04\n"
".quad 0x00861c1002841864,0x42050021000e1d10,0x4245002100285104,0x0000031000801104\n"
".quad 0xff00031000801500,0x010780e0000c2103,0x404780a000100960,0x00078090000409c0\n"
".quad 0x400780a000040900,0x010780e0021011c4,0x0000031000802144,0xff00031000802500\n"
".quad 0x010780e00408110b,0x020780e0000c2140,0x008780e002081960,0x000780e006100940\n"
".quad 0x008780e000041180,0xae80f3101e802960,0xeb1383100b802d03,0xb7a8b31004803103\n"
".quad 0xed0ee31025803508,0x000780e004080903,0x030780e00a042980,0xf02677102f803140\n"
".quad 0xef3b271026803509,0x030780e00a042903,0x9ab0971016803140,0xf1745f100b80350a\n"
".quad 0x030780e00a042903,0xd1b5171014803140,0xf3c71f1007803502,0x030780e00a042903\n"
".quad 0x23be73102d803140,0xf624931024803509,0x030780e00a042903,0x999a3f1004803140\n"
".quad 0xf8999b1019803509,0x020780e000083903,0x030780e00a042964,0x5555571014803140\n"
".quad 0xfb55571015803505,0x038780e0001c3903,0x030780e00a042960,0x038780e008082140\n"
".quad 0x410780a000283144,0x0000033000a85144,0xefa39f102f803900,0xfe62e71002803d0f\n"
".quad 0x000780e00a040903,0x000780e0080c1980,0x410780a000282180,0x010780e00e182944\n"
".quad 0x028780e00e102140,0x018780e002080940,0x020780e000081140,0x010780e000041164\n"
".quad 0xb39803103f800968,0xc7abcb101e800d03,0x010780e002180903,0x008780e000140940\n"
".quad 0x000780101e300360,0x0000031000800900,0xff00031000800d00,0x10c7c8e00209fd07\n"
".quad 0x000280101d5003e0,0x010780e000080900,0x404780a000040960,0x000780101e3003e4\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0087c8e0020dfd00,0x000100101dc003e0\n"
".quad 0x0000031000800900,0xff00031000800d00,0x000780101e30030f,0x0000031000800900\n"
".quad 0xff00031000800d00,0x0087c8e0020dfd07,0x03c68010000c09e0,0x03c68010000e0d06\n"
".quad 0x40c1001000140904,0x40c1001000160d24,0x000002f000000124,0x000002f0000001e0\n"
".quad 0xa02d5b102d8019e0,0xe9a93f1005801d00,0x09b7b71016801103,0xe9361f1015801507\n"
".quad 0x010780e006041903,0x5f58231008801140,0xf00deb1032801500,0x010780e006041903\n"
".quad 0x0a98871006801140,0xf39e63102e80150a,0x010780e006041903,0x53e67b1005801140\n"
".quad 0xf6f767100380150e,0x010780e006041903,0x3e44231037801140,0xf9c4eb102d801507\n"
".quad 0x010780e006041903,0x66906b1006801140,0xfc49531007801502,0x010780e006041903\n"
".quad 0xf8bc131031801140,0xfef3cf100680150c,0x010780e006042103,0x3e4037102d801140\n"
".quad 0xfd5993103280150c,0x0000031000801903,0x0000031000801d00,0x010780e008041100\n"
".quad 0x0047c8e00601fd40,0x008a0c10028808e0,0x404280a000080910,0x000002f0000001e4\n"
".quad 0x404782a0000401e0,0x04478020002045c0,0xc00780d00e260104,0x0047c8301223fda0\n"
".quad 0x0407802000264d64,0x0002801000e00304,0x0007803000000300,0x0007806001184900\n"
".quad 0x20c7c83012cdfd60,0x0002803000000364,0x0000032101ec0100,0x400780a000000100\n"
".quad 0x200780a000483d44,0x000780204f700304,0x010780400f184d00,0x1007803002240900\n"
".quad 0x3007803002cc0dc4,0x03e8542102e850c4,0x1007803002265921,0x00824410028040c4\n"
".quad 0x0000032001a40110,0x400780a000000100,0x0000031000800944,0xff00031000800d00\n"
".quad 0x000780e010001103,0x0187c8e00209fd80,0x00000310008001e0,0x0000031000800500\n"
".quad 0x00c148e00009fd00,0x000000a040e003e0,0x0001001022700300,0x0000031000800900\n"
".quad 0xff80031000800d00,0x0007801040e0030f,0x0000031000800100,0xfe00031000800500\n"
".quad 0xe147af102180090b,0xfdae171007800d0a,0x000780e000080103,0x1047c8e00201fd60\n"
".quad 0x000000a040d003e0,0x0001001024d00300,0x000780e000001100,0x7377771038801980\n"
".quad 0x03970f1029801d05,0x473c6f103c80090c,0x044b231012800d0c,0x0558a71007802904\n"
".quad 0x0090bf1030802d02,0x701e57103d802104,0x0350ff102f802500,0x008780e00608090c\n"
".quad 0x020780e00a082940,0xe54a3f101e801940,0x0329d71030801d0a,0x181503102c80210c\n"
".quad 0x0371571017802509,0x018780e002080904,0x020780e00a082940,0xb28623100d801940\n"
".quad 0x0040db1013801d01,0x655073102d802104,0x020f271030802500,0x018780e00208090c\n"
".quad 0x020780e00a082140,0x0000031000801940,0xff00031000801d00,0x000780e002000103\n"
".quad 0x018780e008080980,0x0007802041500340,0x00820c1002800800,0x0007801040d00310\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0107c8e00201fd00,0x000000a03ed003e0\n"
".quad 0x0001001032200300,0x0000031000800900,0xff00031000800d00,0x008780e000081103\n"
".quad 0x0000031000800964,0x0000031000800d00,0x0107c8e00209fd00,0x00000310008019e0\n"
".quad 0xff00031000801d00,0x008a0c1002880807,0x0042c8e00609fd10,0x000000a02b9003e0\n"
".quad 0x03c7801000061900,0x000100102a700306,0x4107c830800dfd00,0x40c50010000a0964\n"
".quad 0x40c50010000c0d24,0x000500e002080924,0x40c50010000e1180,0x40c2801000081124\n"
".quad 0x400780d081061924,0x1007803014061504,0x404780d0820c0dec,0x0147802000083904\n"
".quad 0x40c7c8308307fd04,0x0286141000841064,0x42050021000a1510,0x42450021001c3904\n"
".quad 0x0000031000801904,0xff00031000801d00,0x018780e000082103,0x404780a000100960\n"
".quad 0x00078090000409c0,0x400780a000040900,0x018780e0021019c4,0x0000031000802144\n"
".quad 0xff00031000802500,0x018780e0060c190b,0x020780e000081140,0x008780e0020c1960\n"
".quad 0x000780e006080940,0x008780e000040980,0xae80f3101e802960,0xeb1383100b802d03\n"
".quad 0xb7a8b31004803103,0xed0ee31025803508,0x000780e002042103,0x030780e00a102980\n"
".quad 0xf02677102f803140,0xef3b271026803509,0x030780e00a102903,0x9ab0971016803140\n"
".quad 0xf1745f100b80350a,0x030780e00a102903,0xd1b5171014803140,0xf3c71f1007803502\n"
".quad 0x030780e00a102903,0x23be73102d803140,0xf624931024803509,0x030780e00a102903\n"
".quad 0x999a3f1004803140,0xf8999b1019803509,0x030780e00a102903,0x5555571014803140\n"
".quad 0xfb55571015803505,0x030780e00a102903,0x000780e00a102140,0x010780e000042980\n"
".quad 0x028780e000142964,0x028780e004041160,0x000780e0040c2944,0x410780a0001c1180\n"
".quad 0x00000330009c3944,0xefa39f102f801900,0xfe62e71002801d0f,0x028780e008043103\n"
".quad 0x410780a0001c2140,0x008780e006082944,0x028780e006101940,0x018780e000040940\n"
".quad 0x008780e000181964,0xb39803103f800968,0xc7abcb101e800d03,0x018780e002080903\n"
".quad 0x008780e000141140,0x000780102b900360,0x0000031000800900,0xff00031000800d00\n"
".quad 0x10c7c8e00209fd07,0x000280102ad003e0,0x010780e000081100,0x000780102b900360\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0087c8e00209fd00,0x000100102b4003e0\n"
".quad 0x0000031000801100,0xff00031000801500,0x000780102b90030f,0x0000031000800900\n"
".quad 0xff00031000800d00,0x0087c8e00209fd07,0x40c10010001411e0,0x40c1001000161524\n"
".quad 0x404782a000081924,0x00000310008009e4,0x0000031000800d00,0x0107c8e0020dfd00\n"
".quad 0x00000310008021e0,0xff00031000802500,0x028e0c10008c0807,0x0042c8e0080dfd10\n"
".quad 0x000000a0320003e0,0x03c7801000062100,0x0001001030b00304,0x4107c8308011fd00\n"
".quad 0x40c50010000a0964,0x40c50010000c0d24,0x000500e0020c0924,0x40c50010000e1180\n"
".quad 0x40c2801000081124,0x400780d081061924,0x1007803014061504,0x404780d0820c0dec\n"
".quad 0x0147802000083904,0x40c7c8308307fd04,0x4205002100060d64,0x42450021001c3904\n"
".quad 0x0000031000801904,0xff00031000801d00,0x018780e000042103,0x404780a000101160\n"
".quad 0x00078090000811c0,0x400780a000081100,0x018780e0041019c4,0x0000031000802144\n"
".quad 0xff00031000802500,0x018780e0060c190b,0x020780e000040940,0x010780e0040c1160\n"
".quad 0x000780e004041940,0x018780e0000c1980,0xae80f3101e802960,0xeb1383100b802d03\n"
".quad 0xb7a8b31004803103,0xed0ee31025803508,0x000780e0060c2103,0x030780e00a102980\n"
".quad 0xf02677102f803140,0xef3b271026803509,0x030780e00a102903,0x9ab0971016803140\n"
".quad 0xf1745f100b80350a,0x030780e00a102903,0xd1b5171014803140,0xf3c71f1007803502\n"
".quad 0x030780e00a102903,0x23be73102d803140,0xf624931024803509,0x030780e00a102903\n"
".quad 0x999a3f1004803140,0xf8999b1019803509,0x030780e00a102903,0x5555571014803140\n"
".quad 0xfb55571015803505,0x030780e00a102903,0x000780e00a102140,0x008780e0000c2980\n"
".quad 0x028780e000142964,0x028780e0020c0960,0x000780e002082944,0x410780a0001c0980\n"
".quad 0x00000330009c3944,0xefa39f102f801100,0xfe62e7100280150f,0x028780e0080c3103\n"
".quad 0x410780a0001c2140,0x018780e004042944,0x028780e004101140,0x010780e0000c1140\n"
".quad 0x010780e000181964,0xb39803103f801168,0xc7abcb101e801503,0x018780e004040903\n"
".quad 0x008780e000140940,0x0007801032000360,0x0000031000800900,0xff00031000800d00\n"
".quad 0x10c7c8e00209fd07,0x00028010312003e0,0x010780e000080900,0x404780a000040960\n"
".quad 0x00078010320003e4,0x0000031000800900,0x0000031000800d00,0x0087c8e0020dfd00\n"
".quad 0x00010010319003e0,0x0000031000800900,0xff00031000800d00,0x000780103200030f\n"
".quad 0x0000031000800900,0xff00031000800d00,0x0087c8e0020dfd07,0x03c68010000c09e0\n"
".quad 0x03c68010000e0d06,0x40c1001000140904,0x40c1001000160d24,0x000002f000000124\n"
".quad 0x000780103ed003e0,0x0000031000800900,0x0000031000800d00,0x0107c8e00209fd00\n"
".quad 0x00000310008019e0,0xff00031000801d00,0x008a0c1002880807,0x0042c8e00609fd10\n"
".quad 0x000000a0385003e0,0x03c7801000061900,0x0001001037300306,0x4107c830800dfd00\n"
".quad 0x40c50010000a0964,0x40c50010000c0d24,0x000500e002080924,0x40c50010000e1180\n"
".quad 0x40c2801000081124,0x400780d081061924,0x1007803014061504,0x404780d0820c0dec\n"
".quad 0x0147802000083904,0x40c7c8308307fd04,0x4205002100060d64,0x42450021001c3904\n"
".quad 0x0000031000801904,0xff00031000801d00,0x018780e000042103,0x404780a000101160\n"
".quad 0x00078090000811c0,0x400780a000081100,0x018780e0041019c4,0x0000031000802144\n"
".quad 0xff00031000802500,0x018780e0060c190b,0x020780e000040940,0x010780e0040c1160\n"
".quad 0x000780e004041940,0x018780e0000c1980,0xae80f3101e802960,0xeb1383100b802d03\n"
".quad 0xb7a8b31004803103,0xed0ee31025803508,0x000780e0060c2103,0x030780e00a102980\n"
".quad 0xf02677102f803140,0xef3b271026803509,0x030780e00a102903,0x9ab0971016803140\n"
".quad 0xf1745f100b80350a,0x030780e00a102903,0xd1b5171014803140,0xf3c71f1007803502\n"
".quad 0x030780e00a102903,0x23be73102d803140,0xf624931024803509,0x030780e00a102903\n"
".quad 0x999a3f1004803140,0xf8999b1019803509,0x030780e00a102903,0x5555571014803140\n"
".quad 0xfb55571015803505,0x030780e00a102903,0x000780e00a102140,0x008780e0000c2980\n"
".quad 0x028780e000142964,0x028780e0020c0960,0x000780e002082944,0x410780a0001c0980\n"
".quad 0x00000330009c3944,0xefa39f102f801100,0xfe62e7100280150f,0x028780e0080c3103\n"
".quad 0x410780a0001c2140,0x018780e004042944,0x028780e004101140,0x010780e0000c1140\n"
".quad 0x010780e000181964,0xb39803103f801168,0xc7abcb101e801503,0x018780e004040903\n"
".quad 0x008780e000141140,0x0007801038500360,0x0000031000800900,0xff00031000800d00\n"
".quad 0x10c7c8e00209fd07,0x00028010379003e0,0x010780e000081100,0x0007801038500360\n"
".quad 0x0000031000800900,0x0000031000800d00,0x0087c8e00209fd00,0x00010010380003e0\n"
".quad 0x0000031000801100,0xff00031000801500,0x000780103850030f,0x0000031000800900\n"
".quad 0xff00031000800d00,0x0087c8e00209fd07,0x40c10010001411e0,0x40c1001000161524\n"
".quad 0x404782a000081924,0x00000310008009e4,0x0000031000800d00,0x0107c8e0020dfd00\n"
".quad 0x00000310008021e0,0xff00031000802500,0x028e0c10008c0807,0x0042c8e0080dfd10\n"
".quad 0x000000a03ec003e0,0x03c7801000062100,0x000100103d700304,0x4107c8308011fd00\n"
".quad 0x40c50010000a0964,0x40c50010000c0d24,0x000500e0020c0924,0x40c50010000e1180\n"
".quad 0x40c2801000081124,0x400780d081061924,0x1007803014061504,0x404780d0820c0dec\n"
".quad 0x0147802000083904,0x40c7c8308307fd04,0x4205002100060d64,0x42450021001c3904\n"
".quad 0x0000031000801904,0xff00031000801d00,0x018780e000042103,0x404780a000101160\n"
".quad 0x00078090000811c0,0x400780a000081100,0x018780e0041019c4,0x0000031000802144\n"
".quad 0xff00031000802500,0x018780e0060c190b,0x020780e000040940,0x010780e0040c1160\n"
".quad 0x000780e004041940,0x018780e0000c1980,0xae80f3101e802960,0xeb1383100b802d03\n"
".quad 0xb7a8b31004803103,0xed0ee31025803508,0x000780e0060c2103,0x030780e00a102980\n"
".quad 0xf02677102f803140,0xef3b271026803509,0x030780e00a102903,0x9ab0971016803140\n"
".quad 0xf1745f100b80350a,0x030780e00a102903,0xd1b5171014803140,0xf3c71f1007803502\n"
".quad 0x030780e00a102903,0x23be73102d803140,0xf624931024803509,0x030780e00a102903\n"
".quad 0x999a3f1004803140,0xf8999b1019803509,0x030780e00a102903,0x5555571014803140\n"
".quad 0xfb55571015803505,0x030780e00a102903,0x000780e00a102140,0x008780e0000c2980\n"
".quad 0x028780e000142964,0x028780e0020c0960,0x000780e002082944,0x410780a0001c0980\n"
".quad 0x00000330009c3944,0xefa39f102f801100,0xfe62e7100280150f,0x028780e0080c3103\n"
".quad 0x410780a0001c2140,0x018780e004042944,0x028780e004101140,0x010780e0000c1140\n"
".quad 0x010780e000181964,0xb39803103f801168,0xc7abcb101e801503,0x018780e004040903\n"
".quad 0x008780e000140940,0x000780103ec00360,0x0000031000800900,0xff00031000800d00\n"
".quad 0x10c7c8e00209fd07,0x000280103de003e0,0x010780e000080900,0x404780a000040960\n"
".quad 0x000780103ec003e4,0x0000031000800900,0x0000031000800d00,0x0087c8e0020dfd00\n"
".quad 0x000100103e5003e0,0x0000031000800900,0xff00031000800d00,0x000780103ec0030f\n"
".quad 0x0000031000800900,0xff00031000800d00,0x0087c8e0020dfd07,0x03c68010000c09e0\n"
".quad 0x03c68010000e0d06,0x40c1001000140904,0x40c1001000160d24,0x000002f000000124\n"
".quad 0x000002f0000001e0,0xa02d5b102d8019e0,0xe9a93f1005801d00,0x09b7b71016801103\n"
".quad 0xe9361f1015801507,0x010780e006041903,0x5f58231008801140,0xf00deb1032801500\n"
".quad 0x010780e006041903,0x0a98871006801140,0xf39e63102e80150a,0x010780e006041903\n"
".quad 0x53e67b1005801140,0xf6f767100380150e,0x010780e006041903,0x3e44231037801140\n"
".quad 0xf9c4eb102d801507,0x010780e006041903,0x66906b1006801140,0xfc49531007801502\n"
".quad 0x010780e006041903,0xf8bc131031801140,0xfef3cf100680150c,0x010780e006041903\n"
".quad 0x3e4037102d801140,0xfd5993103280150c,0x0000031000802103,0x0000031000802500\n"
".quad 0x010780e006041100,0x0047c8e00801fd40,0x008a0c10028808e0,0x404280a000080910\n"
".quad 0x000002f0000001e4,0x404782a0000401e0,0xc00780d00e2801c0,0x05878020002851a0\n"
".quad 0x0047c8301529fd04,0x0487802000264964,0x0002801021900304,0x0007803000000300\n"
".quad 0x03c7801000041100,0x03c7801000061506,0x03c7801000001904,0x03c7801000021d06\n"
".quad 0x03c7801000002904,0x03c7801000022d06,0x03c7801000043104,0x03c7801000063506\n"
".quad 0x1007803014060904,0x00007f103f8001e4,0x000780d000040900,0xffffff203f843904\n"
".quad 0x100780301402050f,0x000780d0000201e4,0xffffff203f803d04,0x0000031000805d0f\n"
".quad 0x00007f103e800100,0x0187c830001ffd00,0x01814830001dfd64,0x000000a047d00364\n"
".quad 0x0001001047d00300,0x504780a0000c0900,0x00000310008001c4,0xff00031000800500\n"
".quad 0x00c7c8e00005fd07,0x00028010433003e0,0x03c7801000140100,0x0080031000800506\n"
".quad 0x004780d001160500,0x0007803000000304,0x504780a000080900,0x00000310008001c4\n"
".quad 0xff00031000800500,0x00c7c8e00005fd07,0x0002801043c003e0,0x03c7801000180100\n"
".quad 0x0080031000800504,0x004780d0011a0500,0x0007803000000304,0x0000031000800100\n"
".quad 0x0000031000800500,0x008780e0000c2100,0x00000310008001e0,0x504780a0000c0900\n"
".quad 0x00000310008005c4,0x008780e000080100,0x000780d0001021e0,0x0000031000800104\n"
".quad 0xff00031000800500,0x008780e000042507,0x504780a0000809e0,0x008780e0000401c4\n"
".quad 0x000780d0001201e0,0x0047c8d00011fd04,0x0001001044f00304,0x0000031000800100\n"
".quad 0xff80031000800500,0x000780300000030f,0x504780a000082100,0x00000310008001c4\n"
".quad 0x0000031000800500,0x0000031000800900,0xff00031000800d00,0x0087c8e00211fd07\n"
".quad 0x008148e0000dfde0,0x0001001045c003e0,0x008780d00d160100,0x0000031000800504\n"
".quad 0x000780d001000508,0x0000031000800104,0x0007803000000300,0x504780a0000c2100\n"
".quad 0x00000310008001c4,0x0000031000800500,0x0000031000800900,0xff00031000800d00\n"
".quad 0x0087c8e00211fd07,0x008148e00009fde0,0x0001001046b003e0,0x008780d00d160100\n"
".quad 0x0000031000800504,0x000780d001000108,0xff00031000800504,0x004780d001000507\n"
".quad 0x0000031000800104,0x0007803000000300,0x0000031000800100,0x0047c830001ffd00\n"
".quad 0x000000a04730036c,0x0001001047300300,0x0000031000800100,0x3500031000800500\n"
".quad 0x000780e0000c2904,0xffffff100a805d80,0x000002f00000010f,0x00000310008001e0\n"
".quad 0x0047c830001dfd00,0x000000a047c0036c,0x0001001047c00300,0x0000031000800100\n"
".quad 0x3500031000800500,0x000780e000083104,0x0000032036ae5d80,0x000002f000000100\n"
".quad 0x03c78210001801e0,0xffffc320029c3106,0x100780301418050f,0x00478020401a05c4\n"
".quad 0x464780a000000904,0x00078090000409c0,0x03c7801000141900,0xffffc320029e3504\n"
".quad 0x400780a00004110f,0x00000310008009c4,0xff00031000800d00,0x008780e000082103\n"
".quad 0x000780e008103944,0x010780e008082180,0x020780e0081c2140,0x008780e008000940\n"
".quad 0x020780e002100944,0x10078030141a1d40,0x01c7802040161dc4,0x000780e0040c1104\n"
".quad 0x018780e000082980,0x010780e008141144,0x018780e000080140,0x010780e002001944\n"
".quad 0x03c78010000e2140,0x10078030140e1d06,0x00007f103f8025e4,0x000780d0090e1d00\n"
".quad 0xffffc320018e1d04,0x034780300018250f,0x02478020000e2504,0x05c7802000122904\n"
".quad 0x00003f203e942504,0x00007f103d802d00,0x00c7c8300b13fd00,0x000000a04f400364\n"
".quad 0x000100104a700300,0x03c78010000c0100,0x01c7802040140504,0x1007803014020504\n"
".quad 0x00478020001005c4,0x000780104f400304,0x00003f103f801900,0x0107c8300615fd00\n"
".quad 0x000000a04f30036c,0x000100104b100300,0x0000031000800100,0x000780d000100108\n"
".quad 0xff00031000800504,0x004780d001000507,0x0000031000800104,0x000780104f300300\n"
".quad 0x0000031000801900,0x000780d006102d08,0xffffbf100c801904,0x0047c8300615fd0f\n"
".quad 0x000000a04f20036c,0x000100104ba00300,0x0000031000800100,0x03c7801000160500\n"
".quad 0x000780104f200306,0x810780e002002100,0x410780e002001940,0x034780e006101940\n"
".quad 0x014780a0000c19e0,0xc10780e00200012c,0x00ffff103f800940,0x000780d002020500\n"
".quad 0x0100031000800904,0x004780d002020500,0x00003f203f940904,0x0000033000840900\n"
".quad 0x0000031020800d00,0x0187c8300305fd00,0x000000a04d00036c,0x000100104d000300\n"
".quad 0x0000031000800d00,0x0147803003000100,0x014780a00000016c,0x004780d0000c192c\n"
".quad 0x03c7801000020104,0x0000031000800504,0xffffff2020840900,0x000002f00000010f\n"
".quad 0x0000031000800de0,0x0147c8300305fd00,0x0000033020840d6c,0x0006803003021500\n"
".quad 0x00068030020011c4,0x0006803003000de4,0x004680d0050801c4,0x0000031000801104\n"
".quad 0x0146803004060d00,0x014680a000060d6c,0x004680d0030c192c,0x0006803002020504\n"
".quad 0x00000310018009e4,0x000780d002000d00,0x1007803001000104,0x100780301f0211e4\n"
".quad 0x004780d0040001c4,0x000780d002000904,0x004780d0020c0904,0x000780d002060904\n"
".quad 0x1007803001020504,0x0000031000800de4,0x0147c8300305fd00,0x000000a04f10036c\n"
".quad 0x000100104f100300,0x0000032001800100,0x0000031000800900,0x0087c8300201fd00\n"
".quad 0x000000a04f00036c,0x000100104f000300,0x0000032001820500,0x000002f000000100\n"
".quad 0x004782d00b0205e0,0x000002f000000104,0x000002f0000001e0,0x000002f0000001e0\n"
".quad 0x00078030000003e0,0x000000f000000100,0xff000310008009e0,0x000780d002020907\n"
".quad 0x1007803014043504,0x00007f103d8009e4,0xffffff203f9a2500,0x00c7c8300213fd0f\n"
".quad 0x000000a058c00364,0x03c7801000000900,0x03c7801000020d06,0x03c7801000022104\n"
".quad 0x0002801052500306,0x03c7801000f81100,0xff00031000801504,0x504780a000041907\n"
".quad 0x0187c8e00609fdc4,0x03c7801000f811e0,0xff00031000801506,0x0002801050c00307\n"
".quad 0x0080031000800500,0x004780d001100500,0x0007801058c00304,0x0087c8e00609fd00\n"
".quad 0x00010010512003e0,0x0000031000800100,0x000780d000100508,0x03c7801000f80104\n"
".quad 0x0007801058c00304,0x03c7801000f81100,0x03c7801000f81506,0x0087c8e00405fd04\n"
".quad 0x0001001051c003e0,0x0000031000800100,0x000780d000100108,0xff00031000800504\n"
".quad 0x004780d001000507,0x03c7801000f80104,0x0007801058c00306,0x0187c8307c13fd00\n"
".quad 0x000280105230036c,0x0000031000800100,0x3500031000800500,0x000780e000040104\n"
".quad 0x0000031036803980,0x0007801052600300,0x03c7801000f83900,0x0007801052600304\n"
".quad 0x03c7801000f83900,0xffffc320019a0906,0x100780301404090f,0x00878020400205c4\n"
".quad 0x464780a000000904,0x00078090000419c0,0x0000031000800900,0xff00031000800d00\n"
".quad 0x404780a000001103,0x400780a0000c01e4,0x008780e0000819c4,0x000780e0000c2940\n"
".quad 0x000780e0060c2140,0x028780e00a102980,0x008780e00a082140,0x028780e008142140\n"
".quad 0x000780e00a0c0140,0x008780e000081140,0xff00031000801940,0x000780e008080907\n"
".quad 0x000780d006061940,0x10078030140c1904,0x01878030001a1de4,0x03878020000e2d04\n"
".quad 0x00007f103d802904,0x00003f203e961d00,0x0107c8300a0ffd00,0x000000a058b00364\n"
".quad 0x0002801054800300,0x0187802040160100,0x00003f203f800104,0x1007803014000100\n"
".quad 0x00078020000605c4,0x03c7801000040104,0x0007801058b00304,0x00003f103f800900\n"
".quad 0x00c7c8300217fd00,0x000280105510036c,0x0000031000800100,0x000780d000060108\n"
".quad 0xff00031000800504,0x004780d001000507,0x03c7801000f80104,0x0007801058b00306\n"
".quad 0xffffbf100c800900,0x000003100080190f,0x0187c8300217fd08,0x000780d00606296c\n"
".quad 0x0002801055900304,0x03c7801000f80100,0x03c7801000140504,0x0007801058b00306\n"
".quad 0x400780e008080900,0x800780e008081940,0xc00780e008080140,0x00ffff103f801140\n"
".quad 0x000780d004021500,0xffffc33001960504,0x010003100080210f,0x000003101f801100\n"
".quad 0x014780e006040d00,0x004780d0080a09e0,0x00c7c8300403fd04,0x000000a056d0036c\n"
".quad 0x014780a000061100,0x0002801056d0032c,0x014780307c000100,0x014780a00000016c\n"
".quad 0x004780d00008112c,0xffffff2020820504,0x03c780100004010f,0x03c7801000f80904\n"
".quad 0x0087ca307c03fd06,0x000000a05790036c,0x0002801057900300,0x0000033020820d00\n"
".quad 0x0007803003001500,0x014780307c0a15c4,0x000780300304196c,0x00078030010001c4\n"
".quad 0x014780a0000a0de4,0x000780300104092c,0x004780d0060001e4,0x004780d003081104\n"
".quad 0x1007823001000504,0x100780301f040de4,0x004780d003020dc4,0x0000031001800504\n"
".quad 0x000780d001061500,0x000780d001000104,0x004780d005080504,0x0007c8d00101fd04\n"
".quad 0x000000a058900304,0x1007803001040100,0x00010010589003e4,0x0000031001800500\n"
".quad 0x0047c02000060d00,0x0000032001800504,0x03c6801000000500,0x03c7801000020104\n"
".quad 0x004782d000140506,0x03c7801000060104,0x000002f000000104,0x000002f0000001e0\n"
".quad 0x00078030000003e0,0x000001f000000100,0x0fffff000fffffe0,0xf6a09e3ff0000080\n"
".quad 0x000000fffffc013f,0xfffbcb4350000000,0x000001fff00000ff,0xf800000000000000\n"
".quad 0x000000000c0b04ff,0x0000080000000400,0x2e017000080d0400,0x0000000000002000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x001d010000000000,0x0000000600000000,0x0000000000014b2c,0x0000016000000000\n"
".quad 0x0000000500000160,0x6000000000000004,0x00000000000009c5,0x0000041c00000000\n"
".quad 0x00001c050000041c,0x6000000000000004,0x0000000000000de1,0x0000000000000000\n"
".quad 0x00001c060000001c,0x6000000000000004,0x0000000000000de1,0x0000098800000000\n"
".quad 0x00001b0500000988,0x6000000000000004,0x0000000000001769,0x0000000000000000\n"
".quad 0x00001b0600001018,0x6000000000000004,0x0000000000001769,0x000006f000000000\n"
".quad 0x00001a05000006f0,0x6000000000000004,0x0000000000001e59,0x0000000000000000\n"
".quad 0x00001a0600001018,0x6000000000000004,0x0000000000001e59,0x00002cc400000000\n"
".quad 0x0000190500002cc4,0x6000000000000004,0x0000000000004b1d,0x0000000000000000\n"
".quad 0x000019060000001c,0x0000000100000004,0x0000000000004b1d,0x0001000c00000000\n"
".quad 0x000000050001000c,0x0000000100000004,0x0000000000014b29,0x0000000000000000\n"
".quad 0x0000000600008000,0x0000000000000004\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_13$[10642];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_13$:\n"
".quad 0x6f69737265762e09,0x2e090a342e31206e,0x7320746567726174,0x2f2f090a33315f6d\n"
".quad 0x656c69706d6f6320,0x2f20687469772064,0x61636f6c2f727375,0x6f2f616475632f6c\n"
".quad 0x696c2f34366e6570,0x2f090a65622f2f62,0x6e65706f766e202f,0x6220312e33206363\n"
".quad 0x206e6f20746c6975,0x2d36302d30313032,0x2d2f2f090a0a3730,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f\n"
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f6462323230,0x372d303030303030\n"
".quad 0x614365746e6f4d5f,0x33314d535f6f6c72,0x20692e337070632e,0x63632f706d742f28\n"
".quad 0x53354a562e234942,0x2d2f2f090a29466c,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2f2f090a0a2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x4f202f2f090a2d2d,0x0a3a736e6f697470,0x2d2d2d2d2d2f2f09\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x090a2d2d2d2d2d2d,0x6772615420202f2f\n"
".quad 0x202c7874703a7465,0x315f6d733a415349,0x6169646e45202c33,0x656c7474696c3a6e\n"
".quad 0x65746e696f50202c,0x333a657a69532072,0x2d20202f2f090a32,0x6974704f2809334f\n"
".quad 0x6e6f6974617a696d,0x0a296c6576656c20,0x30672d20202f2f09,0x2067756265442809\n"
".quad 0x090a296c6576656c,0x09326d2d20202f2f,0x2074726f70655228,0x69726f7369766461\n"
".quad 0x2d2f2f090a297365,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x69662e090a0a2d2d,0x633c22093109656c,0x6c2d646e616d6d6f,0x2e090a223e656e69\n"
".quad 0x22093209656c6966,0x706d742f706d742f,0x303030305f746678,0x3030305f64623232\n"
".quad 0x5f362d3030303030,0x72614365746e6f4d,0x2e33314d535f6f6c,0x2e32656661647563\n"
".quad 0x662e090a22757067,0x2f22093309656c69,0x726f6e2f656d6f68,0x636568632f6c616d\n"
".quad 0x7570672f74756f6b,0x742f746f6c65636f,0x6475632f73747365,0x7365742f322e3261\n"
".quad 0x65746e6f4d2f7374,0x6c754d6f6c726143,0x6f4d2f5550476974,0x6f6c72614365746e\n"
".quad 0x2e6c656e72656b5f,0x662e090a22687563,0x2f22093409656c69,0x2f62696c2f727375\n"
".quad 0x363834692f636367,0x672d78756e696c2d,0x332e342e342f756e,0x6564756c636e692f\n"
".quad 0x2e6665646474732f,0x6c69662e090a2268,0x73752f2209350965,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x2f7472632f656475,0x725f656369766564\n"
".quad 0x682e656d69746e75,0x656c69662e090a22,0x7273752f22093609,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x5f74736f682f6564,0x2e73656e69666564\n"
".quad 0x6c69662e090a2268,0x73752f2209370965,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x6c6975622f656475,0x657079745f6e6974,0x662e090a22682e73\n"
".quad 0x2f22093809656c69,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x65642f6564756c63,0x7079745f65636976,0x2e090a22682e7365,0x22093909656c6966\n"
".quad 0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962,0x642f6564756c636e\n"
".quad 0x79745f7265766972,0x090a22682e736570,0x303109656c69662e,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x656361667275732f\n"
".quad 0x682e73657079745f,0x656c69662e090a22,0x73752f2209313109,0x2f6c61636f6c2f72\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x747865742f656475,0x657079745f657275\n"
".quad 0x662e090a22682e73,0x2209323109656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x762f6564756c636e,0x79745f726f746365,0x090a22682e736570\n"
".quad 0x333109656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x5f6563697665642f,0x705f68636e75616c,0x726574656d617261\n"
".quad 0x662e090a22682e73,0x2209343109656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x632f6564756c636e,0x61726f74732f7472,0x7373616c635f6567\n"
".quad 0x69662e090a22682e,0x2f2209353109656c,0x6c636e692f727375,0x737469622f656475\n"
".quad 0x682e73657079742f,0x656c69662e090a22,0x73752f2209363109,0x64756c636e692f72\n"
".quad 0x682e656d69742f65,0x656c69662e090a22,0x6f682f2209373109,0x616d726f6e2f656d\n"
".quad 0x6f6b636568632f6c,0x636f7570672f7475,0x7365742f746f6c65,0x32616475632f7374\n"
".quad 0x73747365742f322e,0x614365746e6f4d2f,0x69746c754d6f6c72,0x6c6165722f555047\n"
".quad 0x0a22682e65707974,0x3109656c69662e09,0x656d6f682f220938,0x2f6c616d726f6e2f\n"
".quad 0x74756f6b63656863,0x6c65636f7570672f,0x73747365742f746f,0x322e32616475632f\n"
".quad 0x4d2f73747365742f,0x6c72614365746e6f,0x504769746c754d6f,0x4365746e6f4d2f55\n"
".quad 0x6465725f6f6c7261,0x632e6e6f69746375,0x69662e090a226875,0x2f2209393109656c\n"
".quad 0x726f6e2f656d6f68,0x636568632f6c616d,0x7570672f74756f6b,0x742f746f6c65636f\n"
".quad 0x6475632f73747365,0x7365742f322e3261,0x65746e6f4d2f7374,0x6c754d6f6c726143\n"
".quad 0x75712f5550476974,0x6f646e6172697361,0x746172656e65476d,0x656e72656b5f726f\n"
".quad 0x090a226875632e6c,0x303209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f6e6f6d6d6f632f,0x6e6f6974636e7566\n"
".quad 0x662e090a22682e73,0x2209313209656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x636e75665f687461,0x22682e736e6f6974\n"
".quad 0x09656c69662e090a,0x7273752f22093232,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x5f6874616d2f6564,0x746e6174736e6f63,0x662e090a22682e73\n"
".quad 0x2209333209656c69,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x642f6564756c636e,0x75665f6563697665,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220934320965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x5f6d732f6564756c,0x696d6f74615f3131,0x6974636e75665f63,0x090a22682e736e6f\n"
".quad 0x353209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x615f32315f6d732f,0x75665f63696d6f74,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220936320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x6c62756f645f3331,0x6974636e75665f65\n"
".quad 0x090a22682e736e6f,0x373209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x615f30325f6d732f,0x75665f63696d6f74\n"
".quad 0x2e736e6f6974636e,0x6c69662e090a2268,0x752f220938320965,0x6c61636f6c2f7273\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x6972746e695f3032\n"
".quad 0x22682e736369736e,0x09656c69662e090a,0x7273752f22093932,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x61667275732f6564,0x74636e75665f6563\n"
".quad 0x0a22682e736e6f69,0x3309656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x7275747865742f65,0x5f68637465665f65\n"
".quad 0x6e6f6974636e7566,0x662e090a22682e73,0x2209313309656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x6d2f6564756c636e,0x636e75665f687461\n"
".quad 0x62645f736e6f6974,0x682e337874705f6c,0x6e6f632e090a0a22,0x67696c612e207473\n"
".quad 0x2038622e2038206e,0x6e6f6974704f5f64,0x3535365b61746144,0x672e090a3b5d3633\n"
".quad 0x612e206c61626f6c,0x2e2038206e67696c,0x6c61435f64203862,0x335b65756c61566c\n"
".quad 0x0a0a3b5d38363732,0x207972746e652e09,0x746e6f4d36315a5f,0x654b6f6c72614365\n"
".quad 0x5f3431506c656e72,0x6e6f6974704f545f,0x69665065756c6156,0x61702e09090a2820\n"
".quad 0x3233752e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261,0x72614365746e6f4d\n"
".quad 0x6c656e72654b6f6c,0x704f545f5f343150,0x756c61566e6f6974,0x425f645f69665065\n"
".quad 0x090a2c7265666675,0x206d617261702e09,0x635f5f203233752e,0x5f6d726170616475\n"
".quad 0x746e6f4d36315a5f,0x654b6f6c72614365,0x5f3431506c656e72,0x6e6f6974704f545f\n"
".quad 0x69665065756c6156,0x6c706d61535f645f,0x702e09090a2c7365,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x614365746e6f4d36,0x656e72654b6f6c72\n"
".quad 0x4f545f5f3431506c,0x6c61566e6f697470,0x61705f6966506575,0x0a7b090a294e6874\n"
".quad 0x752e206765722e09,0x353c687225203631,0x6765722e090a3b3e,0x7225203233752e20\n"
".quad 0x2e090a3b3e31343c,0x3233662e20676572,0x0a3b3e333c662520,0x662e206765722e09\n"
".quad 0x353c646625203436,0x65722e090a3b3e34,0x20646572702e2067,0x090a3b3e383c7025\n"
".quad 0x31093309636f6c2e,0x444c240a30093231,0x5f5f6e6967656257,0x65746e6f4d36315a\n"
".quad 0x72654b6f6c726143,0x5f5f3431506c656e,0x566e6f6974704f54,0x3a69665065756c61\n"
".quad 0x3309636f6c2e090a,0x090a300939323109,0x203631752e766f6d,0x25202c3168722509\n"
".quad 0x0a3b782e6469746e,0x3631752e766f6d09,0x202c326872250920,0x782e646961746325\n"
".quad 0x772e6c756d090a3b,0x203631752e656469,0x7225202c31722509,0x31687225202c3268\n"
".quad 0x752e747663090a3b,0x09203631752e3233,0x697425202c327225,0x6461090a3b782e64\n"
".quad 0x2509203233752e64,0x2c327225202c3372,0x63090a3b31722520,0x752e3233732e7476\n"
".quad 0x2c34722509203631,0x2e64696174632520,0x2e766f6d090a3b79,0x6872250920363175\n"
".quad 0x6174636e25202c33,0x6c090a3b782e6469,0x2e6d617261702e64,0x3572250920323373\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x4365746e6f4d3631,0x6e72654b6f6c7261\n"
".quad 0x545f5f3431506c65,0x61566e6f6974704f,0x705f69665065756c,0x090a3b5d4e687461\n"
".quad 0x2e656c2e70746573,0x3170250920323373,0x25202c357225202c,0x702540090a3b3372\n"
".quad 0x2409206172622031,0x3836375f305f744c,0x2e6c756d090a3b32,0x3631752e65646977\n"
".quad 0x25202c3672250920,0x687225202c336872,0x2e6c756d090a3b31,0x09203233752e6f6c\n"
".quad 0x337225202c377225,0x646c090a3b34202c,0x732e6d617261702e,0x2c35722509203233\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x614365746e6f4d36,0x656e72654b6f6c72\n"
".quad 0x4f545f5f3431506c,0x6c61566e6f697470,0x61705f6966506575,0x6d090a3b5d4e6874\n"
".quad 0x33752e6f6c2e6c75,0x202c387225092032,0x0a3b34202c357225,0x2e6f6c2e6c756d09\n"
".quad 0x3972250920323375,0x34202c367225202c,0x34326c756d090a3b,0x203233752e6f6c2e\n"
".quad 0x25202c3031722509,0x0a3b3233202c3472,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5f5b202c313172,0x6d72617061647563,0x6e6f4d36315a5f5f,0x4b6f6c7261436574\n"
".quad 0x3431506c656e7265,0x6f6974704f545f5f,0x665065756c61566e,0x706d61535f645f69\n"
".quad 0x61090a3b5d73656c,0x09203233752e6464,0x7225202c32317225,0x3b31317225202c37\n"
".quad 0x33752e646461090a,0x2c33317225092032,0x7225202c38722520,0x766f6d090a3b3131\n"
".quad 0x722509203233752e,0x704f5f64202c3431,0x617461446e6f6974,0x752e646461090a3b\n"
".quad 0x3531722509203233,0x202c30317225202c,0x6c090a3b34317225,0x2e74736e6f632e64\n"
".quad 0x6466250920343666,0x353172255b202c31,0x6c090a3b5d36312b,0x2e74736e6f632e64\n"
".quad 0x6466250920343666,0x353172255b202c32,0x6c090a3b5d34322b,0x2e74736e6f632e64\n"
".quad 0x6466250920343666,0x353172255b202c33,0x646c090a3b5d382b,0x662e74736e6f632e\n"
".quad 0x3464662509203436,0x2b353172255b202c,0x766f6d090a3b5d30,0x662509203436662e\n"
".quad 0x30306430202c3564,0x3030303030303030,0x093b303030303030,0x6f6d090a30202f2f\n"
".quad 0x2509203436662e76,0x306430202c366466,0x3030303030303030,0x3b30303030303030\n"
".quad 0x4c240a30202f2f09,0x363431365f305f74,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x202c39323120656e,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x616d69747365202c,0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75\n"
".quad 0x093309636f6c2e09,0x6c090a3009303331,0x6c61626f6c672e64,0x662509203233662e\n"
".quad 0x323172255b202c31,0x7663090a3b5d302b,0x33662e3436662e74,0x2c37646625092032\n"
".quad 0x2e090a3b31662520,0x3331093309636f6c,0x64616d090a300931,0x203436662e6e722e\n"
".quad 0x25202c3864662509,0x646625202c326466,0x3b31646625202c37,0x36622e766f6d090a\n"
".quad 0x363172257b092034,0x202c7d373172252c,0x6d090a3b38646625,0x09203233732e766f\n"
".quad 0x312d202c38317225,0x3537353738343630,0x2e746573090a3b39,0x732e3233752e746c\n"
".quad 0x3931722509203233,0x202c37317225202c,0x6e090a3b38317225,0x09203233732e6765\n"
".quad 0x7225202c30327225,0x766f6d090a3b3931,0x722509203233752e,0x32383031202c3132\n"
".quad 0x0a3b303934353335,0x2e656c2e74657309,0x203233752e323375,0x25202c3232722509\n"
".quad 0x327225202c373172,0x2e67656e090a3b31,0x3272250920323373,0x3b32327225202c33\n"
".quad 0x3233622e726f090a,0x202c343272250920,0x7225202c30327225,0x766f6d090a3b3332\n"
".quad 0x722509203233752e,0x090a3b30202c3532,0x2e71652e70746573,0x3270250920323373\n"
".quad 0x202c34327225202c,0x40090a3b35327225,0x2061726220327025,0x365f305f744c2409\n"
".quad 0x2f2f200a3b323034,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323120656e696c20,0x2064616568202c39,0x2064656c6562616c,0x31365f305f744c24\n"
".quad 0x636f6c2e090a3634,0x0935303709313309,0x662e766f6d090a30,0x3964662509203436\n"
".quad 0x376666336430202c,0x6232353637343531,0x2f2f093b65663238,0x0a373234342e3120\n"
".quad 0x3436662e6c756d09,0x2c30316466250920,0x25202c3864662520,0x7663090a3b396466\n"
".quad 0x36662e696e722e74,0x2509203436662e34,0x6625202c31316466,0x7663090a3b303164\n"
".quad 0x33732e697a722e74,0x2509203436662e32,0x646625202c363272,0x766f6d090a3b3131\n"
".quad 0x722509203233732e,0x36327225202c3732,0x752e766f6d090a3b,0x3832722509203233\n"
".quad 0x3b313230312d202c,0x672e70746573090a,0x2509203233732e74,0x36327225202c3370\n"
".quad 0x0a3b38327225202c,0x7262203370254009,0x305f744c24092061,0x200a3b303731375f\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c393231,0x656c6562616c2064,0x5f305f744c242064,0x6c2e090a36343136\n"
".quad 0x313709313309636f,0x646461090a300930,0x722509203233732e,0x36327225202c3732\n"
".quad 0x6d090a3b3535202c,0x09203233732e766f,0x3031202c39327225,0x3434313037303631\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x0a3b343139365f30,0x31375f305f744c24\n"
".quad 0x3c2f2f200a3a3037,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39323120656e696c,0x6c2064616568202c,0x242064656c656261,0x3431365f305f744c\n"
".quad 0x732e766f6d090a36,0x3932722509203233,0x343733373031202c,0x4c240a3b34323831\n"
".quad 0x343139365f305f74,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c39323120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x0a363431365f305f,0x313309636f6c2e09,0x090a300935313309,0x203436662e766f6d\n"
".quad 0x202c323164662509,0x6532366566626430,0x3933616665663234,0x2d202f2f093b6665\n"
".quad 0x3734313339362e30,0x6e722e64616d090a,0x662509203436662e,0x646625202c333164\n"
".quad 0x31646625202c3131,0x3b38646625202c32,0x36662e766f6d090a,0x3431646625092034\n"
".quad 0x613763626430202c,0x3933623365396362,0x2f2f093b66333038,0x303931332e322d20\n"
".quad 0x6d090a37312d6535,0x36662e6e722e6461,0x3531646625092034,0x2c3131646625202c\n"
".quad 0x202c343164662520,0x090a3b3331646625,0x203436662e766f6d,0x202c363164662509\n"
".quad 0x3066313265336430,0x6238356663636637,0x32202f2f093b6461,0x2d6533343838302e\n"
".quad 0x2e766f6d090a3930,0x6466250920343666,0x65336430202c3731,0x6164313864666135\n"
".quad 0x093b666162336336,0x3331352e32202f2f,0x090a38302d653636,0x662e6e722e64616d\n"
".quad 0x3164662509203436,0x3631646625202c38,0x2c3531646625202c,0x0a3b373164662520\n"
".quad 0x313309636f6c2e09,0x090a300936313309,0x203436662e766f6d,0x202c393164662509\n"
".quad 0x6537323965336430,0x3038663036663535,0x32202f2f093b3665,0x2d6535373535372e\n"
".quad 0x2e64616d090a3730,0x09203436662e6e72,0x25202c3032646625,0x6625202c38316466\n"
".quad 0x646625202c353164,0x6f6c2e090a3b3931,0x3731330931330963,0x2e766f6d090a3009\n"
".quad 0x6466250920343666,0x65336430202c3132,0x6638616464313763,0x093b363636643230\n"
".quad 0x3535372e32202f2f,0x090a36302d653237,0x662e6e722e64616d,0x3264662509203436\n"
".quad 0x3032646625202c32,0x2c3531646625202c,0x0a3b313264662520,0x313309636f6c2e09\n"
".quad 0x090a300938313309,0x203436662e766f6d,0x202c333264662509,0x3130616665336430\n"
".quad 0x3439386233313061,0x32202f2f093b3065,0x2d6536313038342e,0x2e64616d090a3530\n"
".quad 0x09203436662e6e72,0x25202c3432646625,0x6625202c32326466,0x646625202c353164\n"
".quad 0x6f6c2e090a3b3332,0x3931330931330963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x66336430202c3532,0x6431306131306132,0x093b383837666133,0x3030302e30202f2f\n"
".quad 0x090a333134383931,0x662e6e722e64616d,0x3264662509203436,0x3432646625202c36\n"
".quad 0x2c3531646625202c,0x0a3b353264662520,0x313309636f6c2e09,0x090a300930323309\n"
".quad 0x203436662e766f6d,0x202c373264662509,0x3163363566336430,0x3161336336316336\n"
".quad 0x30202f2f093b6365,0x383838333130302e,0x722e64616d090a39,0x2509203436662e6e\n"
".quad 0x6625202c38326466,0x646625202c363264,0x32646625202c3531,0x636f6c2e090a3b37\n"
".quad 0x0931323309313309,0x662e766f6d090a30,0x3264662509203436,0x3866336430202c39\n"
".quad 0x3131313131313131,0x2f093b3136313930,0x333830302e30202f,0x616d090a33333333\n"
".quad 0x3436662e6e722e64,0x2c30336466250920,0x202c383264662520,0x25202c3531646625\n"
".quad 0x2e090a3b39326466,0x3309313309636f6c,0x6f6d090a30093232,0x2509203436662e76\n"
".quad 0x6430202c31336466,0x3535353535616633,0x3163343535353535,0x302e30202f2f093b\n"
".quad 0x090a373636363134,0x662e6e722e64616d,0x3364662509203436,0x3033646625202c32\n"
".quad 0x2c3531646625202c,0x0a3b313364662520,0x313309636f6c2e09,0x090a300933323309\n"
".quad 0x203436662e766f6d,0x202c333364662509,0x3535356366336430,0x3535353535353535\n"
".quad 0x30202f2f093b6636,0x0a3736363636312e,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x33646625202c3433,0x3531646625202c32,0x3b3333646625202c,0x3309636f6c2e090a\n"
".quad 0x0a30093432330931,0x3436662e766f6d09,0x2c35336466250920,0x3030656633643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x64616d090a352e30,0x203436662e6e722e\n"
".quad 0x202c363364662509,0x25202c3433646625,0x6625202c35316466,0x6c2e090a3b353364\n"
".quad 0x323309313309636f,0x6c756d090a300936,0x662509203436662e,0x646625202c373364\n"
".quad 0x33646625202c3531,0x2e64616d090a3b36,0x09203436662e6e72,0x25202c3833646625\n"
".quad 0x6625202c37336466,0x646625202c353164,0x6f6c2e090a3b3531,0x3832370931330963\n"
".quad 0x2e6c6873090a3009,0x3372250920323362,0x2c37327225202c30,0x6461090a3b303220\n"
".quad 0x2509203233732e64,0x337225202c313372,0x3631373031202c30,0x090a3b3237363434\n"
".quad 0x203233732e766f6d,0x30202c3233722509,0x622e766f6d090a3b,0x3364662509203436\n"
".quad 0x323372257b202c39,0x0a3b7d313372252c,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x33646625202c3034,0x3933646625202c38,0x3b3933646625202c,0x33732e766f6d090a\n"
".quad 0x2c33337225092032,0x766f6d090a3b3020,0x662509203436622e,0x72257b202c313464\n"
".quad 0x7d393272252c3333,0x662e6c756d090a3b,0x3464662509203436,0x3034646625202c32\n"
".quad 0x3b3134646625202c,0x6e752e617262090a,0x6557444c24092069,0x746e69725f69646e\n"
".quad 0x0a3b315f3730325f,0x34365f305f744c24,0x3c2f2f200a3a3230,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x39323120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3431365f305f744c,0x09636f6c2e090a36,0x3009323337093133\n"
".quad 0x36662e766f6d090a,0x3334646625092034,0x306666376430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x6f6d090a666e6920,0x2509203436662e76,0x6430202c34346466\n"
".quad 0x3030303030303030,0x3030303030303030,0x090a30202f2f093b,0x203233732e766f6d\n"
".quad 0x30202c3433722509,0x2e70746573090a3b,0x09203233732e6567,0x317225202c347025\n"
".quad 0x3b34337225202c37,0x662e706c6573090a,0x3464662509203436,0x3334646625202c35\n"
".quad 0x2c3434646625202c,0x61090a3b34702520,0x09203436662e6464,0x25202c3634646625\n"
".quad 0x646625202c386466,0x2e736261090a3b38,0x6466250920343666,0x38646625202c3734\n"
".quad 0x662e766f6d090a3b,0x3464662509203436,0x6666376430202c38,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x73090a666e69202f,0x662e656c2e707465,0x2c35702509203436\n"
".quad 0x202c373464662520,0x090a3b3834646625,0x3436662e706c6573,0x2c32346466250920\n"
".quad 0x202c353464662520,0x25202c3634646625,0x57444c240a3b3570,0x6e69725f69646e65\n"
".quad 0x3a315f3730325f74,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3932312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x090a363431365f30,0x31093309636f6c2e,0x756d090a30093233,0x2509203436662e6c\n"
".quad 0x6625202c39346466,0x34646625202c3464,0x2e627573090a3b32,0x6466250920343666\n"
".quad 0x34646625202c3035,0x3b33646625202c39,0x36662e766f6d090a,0x3135646625092034\n"
".quad 0x303030306430202c,0x3030303030303030,0x2f2f093b30303030,0x2e78616d090a3020\n"
".quad 0x6466250920343666,0x35646625202c3235,0x3135646625202c30,0x662e646461090a3b\n"
".quad 0x3664662509203436,0x2c3235646625202c,0x090a3b3664662520,0x31093309636f6c2e\n"
".quad 0x616d090a30093333,0x3436662e6e722e64,0x202c356466250920,0x25202c3235646625\n"
".quad 0x6625202c32356466,0x646461090a3b3564,0x722509203233752e,0x2c397225202c3231\n"
".quad 0x090a3b3231722520,0x2e746c2e70746573,0x3670250920323375,0x202c32317225202c\n"
".quad 0x40090a3b33317225,0x2061726220367025,0x365f305f744c2409,0x7262090a3b363431\n"
".quad 0x240920696e752e61,0x3336355f305f744c,0x305f744c240a3b34,0x090a3a323836375f\n"
".quad 0x656469772e6c756d,0x722509203631752e,0x2c33687225202c36,0x090a3b3168722520\n"
".quad 0x203436662e766f6d,0x30202c3564662509,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e766f6d09,0x202c366466250920,0x3030303030306430\n"
".quad 0x3030303030303030,0x30202f2f093b3030,0x355f305f744c240a,0x6c2e090a3a343336\n"
".quad 0x353331093309636f,0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c35337225\n"
".quad 0x0a3b367225202c34,0x3233732e64646109,0x202c363372250920,0x7225202c35337225\n"
".quad 0x2e6c756d090a3b33,0x09203233752e6f6c,0x7225202c37337225,0x0a3b3631202c3633\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x5f5f5b202c383372,0x6d72617061647563\n"
".quad 0x6e6f4d36315a5f5f,0x4b6f6c7261436574,0x3431506c656e7265,0x6f6974704f545f5f\n"
".quad 0x665065756c61566e,0x666675425f645f69,0x6461090a3b5d7265,0x2509203233752e64\n"
".quad 0x337225202c393372,0x3b37337225202c38,0x6f6c672e7473090a,0x203436662e6c6162\n"
".quad 0x302b393372255b09,0x3b36646625202c5d,0x6f6c672e7473090a,0x203436662e6c6162\n"
".quad 0x382b393372255b09,0x3b35646625202c5d,0x3309636f6c2e090a,0x090a300936333109\n"
".quad 0x4c240a3b74697865,0x5a5f5f646e655744,0x4365746e6f4d3631,0x6e72654b6f6c7261\n"
".quad 0x545f5f3431506c65,0x61566e6f6974704f,0x0a3a69665065756c,0x5a5f202f2f207d09\n"
".quad 0x4365746e6f4d3631,0x6e72654b6f6c7261,0x545f5f3431506c65,0x61566e6f6974704f\n"
".quad 0x0a0a69665065756c,0x207972746e652e09,0x746e6f4d37325a5f,0x6e4f6f6c72614365\n"
".quad 0x65506b636f6c4265,0x506e6f6974704f72,0x2e09090a28206966,0x752e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x4365746e6f4d3732,0x42656e4f6f6c7261\n"
".quad 0x4f7265506b636f6c,0x6966506e6f697470,0x6c706d61535f645f,0x702e09090a2c7365\n"
".quad 0x33732e206d617261,0x616475635f5f2032,0x325a5f5f6d726170,0x614365746e6f4d37\n"
".quad 0x6c42656e4f6f6c72,0x704f7265506b636f,0x5f6966506e6f6974,0x090a294e68746170\n"
".quad 0x206765722e090a7b,0x687225203631752e,0x722e090a3b3e343c,0x203233752e206765\n"
".quad 0x0a3b3e36373c7225,0x662e206765722e09,0x3e333c6625203233,0x206765722e090a3b\n"
".quad 0x646625203436662e,0x090a3b3e3430313c,0x72702e206765722e,0x30323c7025206465\n"
".quad 0x6168732e090a3b3e,0x696c612e20646572,0x38622e2038206e67,0x5f616475635f5f20\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x335f30393936325f,0x436d75535f735f34\n"
".quad 0x38323338396c6c61,0x0a3b5d383430325b,0x6465726168732e09,0x206e67696c612e20\n"
".quad 0x5f5f2038622e2038,0x635f5f5f61647563,0x61636f6c5f616475,0x36325f7261765f6c\n"
".quad 0x735f34335f313939,0x6c6143326d75535f,0x5b3637333030316c,0x090a3b5d38343032\n"
".quad 0x31093309636f6c2e,0x444c240a30093934,0x5f5f6e6967656257,0x65746e6f4d37325a\n"
".quad 0x656e4f6f6c726143,0x7265506b636f6c42,0x66506e6f6974704f,0x636f6c2e090a3a69\n"
".quad 0x3009343631093309,0x33732e747663090a,0x2509203631752e32,0x64697425202c3172\n"
".quad 0x766f6d090a3b782e,0x722509203233732e,0x0a3b317225202c32,0x3233732e766f6d09\n"
".quad 0x32202c3372250920,0x746573090a3b3535,0x3233732e656c2e70,0x25202c3170250920\n"
".quad 0x3b337225202c3172,0x203170252140090a,0x744c240920617262,0x30333532325f315f\n"
".quad 0x752e766f6d090a3b,0x2c34722509203233,0x5f616475635f5f20,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f30393936325f,0x436d75535f735f34,0x38323338396c6c61\n"
".quad 0x752e766f6d090a3b,0x2c35722509203233,0x5f616475635f5f20,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f31393936325f,0x326d75535f735f34,0x333030316c6c6143\n"
".quad 0x747663090a3b3637,0x3631752e3233732e,0x25202c3672250920,0x3b782e6469617463\n"
".quad 0x31752e747663090a,0x2509203233752e36,0x367225202c316872,0x772e6c756d090a3b\n"
".quad 0x203631752e656469,0x7225202c37722509,0x0a3b3233202c3168,0x3233752e766f6d09\n"
".quad 0x64202c3872250920,0x446e6f6974704f5f,0x6461090a3b617461,0x2509203233752e64\n"
".quad 0x2c377225202c3972,0x6c090a3b38722520,0x2e74736e6f632e64,0x6466250920343666\n"
".quad 0x2b3972255b202c31,0x646c090a3b5d3631,0x662e74736e6f632e,0x3264662509203436\n"
".quad 0x322b3972255b202c,0x2e646c090a3b5d34,0x36662e74736e6f63,0x2c33646625092034\n"
".quad 0x5d382b3972255b20,0x6f632e646c090a3b,0x203436662e74736e,0x5b202c3464662509\n"
".quad 0x0a3b5d302b397225,0x6c2e34326c756d09,0x2509203233752e6f,0x317225202c303172\n"
".quad 0x7663090a3b38202c,0x31752e3233752e74,0x2c31317225092036,0x782e6469746e2520\n"
".quad 0x34326c756d090a3b,0x203233752e6f6c2e,0x25202c3231722509,0x0a3b38202c313172\n"
".quad 0x3233752e64646109,0x202c333172250920,0x7225202c30317225,0x2e646461090a3b34\n"
".quad 0x3172250920323375,0x2c30317225202c34,0x6c090a3b35722520,0x2e6d617261702e64\n"
".quad 0x3172250920323373,0x75635f5f5b202c35,0x5f5f6d7261706164,0x65746e6f4d37325a\n"
".quad 0x656e4f6f6c726143,0x7265506b636f6c42,0x66506e6f6974704f,0x5d4e687461705f69\n"
".quad 0x5f315f744c240a3b,0x200a3a3234303332,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x73656e202c343631,0x70656420676e6974,0x65202c31203a6874\n"
".quad 0x646574616d697473,0x6974617265746920,0x6b6e75203a736e6f,0x646c090a6e776f6e\n"
".quad 0x732e6d617261702e,0x3531722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x4365746e6f4d3732,0x42656e4f6f6c7261,0x4f7265506b636f6c,0x6966506e6f697470\n"
".quad 0x3b5d4e687461705f,0x672e70746573090a,0x2509203233732e65,0x2c327225202c3270\n"
".quad 0x090a3b3531722520,0x6172622032702540,0x5f315f744c240920,0x200a3b3039343133\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c343631,0x656c6562616c2064,0x5f315f744c242064,0x6c090a3234303332\n"
".quad 0x2e6d617261702e64,0x3172250920323373,0x75635f5f5b202c35,0x5f5f6d7261706164\n"
".quad 0x65746e6f4d37325a,0x656e4f6f6c726143,0x7265506b636f6c42,0x66506e6f6974704f\n"
".quad 0x5d4e687461705f69,0x732e627573090a3b,0x3631722509203233,0x202c35317225202c\n"
".quad 0x6461090a3b327225,0x2509203233732e64,0x317225202c373172,0x0a3b353532202c36\n"
".quad 0x3233732e72687309,0x202c383172250920,0x3133202c37317225,0x732e766f6d090a3b\n"
".quad 0x3931722509203233,0x090a3b353532202c,0x203233622e646e61,0x25202c3032722509\n"
".quad 0x317225202c383172,0x2e646461090a3b39,0x3272250920323373,0x2c30327225202c31\n"
".quad 0x090a3b3731722520,0x203233732e726873,0x25202c3232722509,0x0a3b38202c313272\n"
".quad 0x2e6f6c2e6c756d09,0x3272250920323375,0x202c327225202c33,0x2e6c756d090a3b34\n"
".quad 0x09203233752e6f6c,0x7225202c34327225,0x090a3b34202c3531,0x6d617261702e646c\n"
".quad 0x722509203233752e,0x635f5f5b202c3532,0x5f6d726170616475,0x746e6f4d37325a5f\n"
".quad 0x6e4f6f6c72614365,0x65506b636f6c4265,0x506e6f6974704f72,0x6d61535f645f6966\n"
".quad 0x090a3b5d73656c70,0x203233752e646461,0x25202c3632722509,0x327225202c333272\n"
".quad 0x2e646461090a3b35,0x3272250920323375,0x2c34327225202c37,0x090a3b3532722520\n"
".quad 0x203436662e766f6d,0x30202c3564662509,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e766f6d09,0x202c366466250920,0x3030303030306430\n"
".quad 0x3030303030303030,0x30202f2f093b3030,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3436312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32343033325f31,0x3233732e766f6d09,0x202c383272250920\n"
".quad 0x4c240a3b32327225,0x313833325f315f74,0x6c3c2f2f200a3a30,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x2c34363120656e69,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6d69747365202c32,0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520\n"
".quad 0x3309636f6c2e090a,0x090a300937363109,0x61626f6c672e646c,0x2509203233662e6c\n"
".quad 0x3272255b202c3166,0x63090a3b5d302b36,0x662e3436662e7476,0x3764662509203233\n"
".quad 0x090a3b316625202c,0x31093309636f6c2e,0x616d090a30093836,0x3436662e6e722e64\n"
".quad 0x202c386466250920,0x6625202c32646625,0x31646625202c3764,0x622e766f6d090a3b\n"
".quad 0x3272257b09203436,0x2c7d303372252c39,0x090a3b3864662520,0x203233732e766f6d\n"
".quad 0x2d202c3133722509,0x3735373834363031,0x746573090a3b3935,0x2e3233752e746c2e\n"
".quad 0x3372250920323373,0x2c30337225202c32,0x090a3b3133722520,0x203233732e67656e\n"
".quad 0x25202c3333722509,0x6f6d090a3b323372,0x2509203233752e76,0x383031202c343372\n"
".quad 0x3b30393435333532,0x656c2e746573090a,0x3233752e3233752e,0x202c353372250920\n"
".quad 0x7225202c30337225,0x67656e090a3b3433,0x722509203233732e,0x35337225202c3633\n"
".quad 0x33622e726f090a3b,0x2c37337225092032,0x25202c3333722520,0x6f6d090a3b363372\n"
".quad 0x2509203233752e76,0x0a3b30202c383372,0x71652e7074657309,0x702509203233732e\n"
".quad 0x2c37337225202c33,0x090a3b3833722520,0x6172622033702540,0x5f315f744c240920\n"
".quad 0x200a3b3636303432,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c343631,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x2e090a3031383332,0x3709313309636f6c,0x6f6d090a30093530,0x2509203436662e76\n"
".quad 0x336430202c396466,0x3637343531376666,0x3b65663238623235,0x34342e31202f2f09\n"
".quad 0x2e6c756d090a3732,0x6466250920343666,0x38646625202c3031,0x0a3b39646625202c\n"
".quad 0x696e722e74766309,0x3436662e3436662e,0x2c31316466250920,0x0a3b303164662520\n"
".quad 0x697a722e74766309,0x3436662e3233732e,0x202c393372250920,0x090a3b3131646625\n"
".quad 0x203233732e766f6d,0x25202c3034722509,0x6f6d090a3b393372,0x2509203233752e76\n"
".quad 0x30312d202c313472,0x746573090a3b3132,0x3233732e74672e70,0x25202c3470250920\n"
".quad 0x347225202c393372,0x34702540090a3b31,0x4c24092061726220,0x333834325f315f74\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c34363120656e69,0x616c206461656820,0x4c242064656c6562,0x313833325f315f74\n"
".quad 0x09636f6c2e090a30,0x3009303137093133,0x33732e646461090a,0x2c30347225092032\n"
".quad 0x35202c3933722520,0x2e766f6d090a3b35,0x3472250920323373,0x3036313031202c32\n"
".quad 0x090a3b3434313037,0x20696e752e617262,0x325f315f744c2409,0x4c240a3b38373534\n"
".quad 0x333834325f315f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c34363120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313833325f315f74,0x732e766f6d090a30,0x3234722509203233,0x343733373031202c\n"
".quad 0x4c240a3b34323831,0x373534325f315f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c34363120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313833325f315f74,0x09636f6c2e090a30,0x3009353133093133\n"
".quad 0x36662e766f6d090a,0x3231646625092034,0x366566626430202c,0x6166656632346532\n"
".quad 0x2f2f093b66653933,0x313339362e302d20,0x2e64616d090a3734,0x09203436662e6e72\n"
".quad 0x25202c3331646625,0x6625202c31316466,0x646625202c323164,0x2e766f6d090a3b38\n"
".quad 0x6466250920343666,0x63626430202c3431,0x6233653963626137,0x093b663330383933\n"
".quad 0x31332e322d202f2f,0x0a37312d65353039,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x31646625202c3531,0x3431646625202c31,0x3b3331646625202c,0x36662e766f6d090a\n"
".quad 0x3631646625092034,0x313265336430202c,0x3566636366373066,0x2f2f093b64616238\n"
".quad 0x33343838302e3220,0x6f6d090a39302d65,0x2509203436662e76,0x6430202c37316466\n"
".quad 0x3138646661356533,0x6661623363366164,0x352e32202f2f093b,0x38302d6536363331\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x646625202c383164,0x31646625202c3631\n"
".quad 0x3731646625202c35,0x09636f6c2e090a3b,0x3009363133093133,0x36662e766f6d090a\n"
".quad 0x3931646625092034,0x323965336430202c,0x6630366635356537,0x2f2f093b36653038\n"
".quad 0x35373535372e3220,0x616d090a37302d65,0x3436662e6e722e64,0x2c30326466250920\n"
".quad 0x202c383164662520,0x25202c3531646625,0x2e090a3b39316466,0x3309313309636f6c\n"
".quad 0x6f6d090a30093731,0x2509203436662e76,0x6430202c31326466,0x6164643137636533\n"
".quad 0x3636366432306638,0x372e32202f2f093b,0x36302d6532373535,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x646625202c323264,0x31646625202c3032,0x3132646625202c35\n"
".quad 0x09636f6c2e090a3b,0x3009383133093133,0x36662e766f6d090a,0x3332646625092034\n"
".quad 0x616665336430202c,0x3862333130613130,0x2f2f093b30653439,0x36313038342e3220\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x2c34326466250920,0x202c323264662520\n"
".quad 0x25202c3531646625,0x2e090a3b33326466,0x3309313309636f6c,0x6f6d090a30093931\n"
".quad 0x2509203436662e76,0x6430202c35326466,0x3061313061326633,0x3838376661336431\n"
".quad 0x302e30202f2f093b,0x3331343839313030,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x646625202c363264,0x31646625202c3432,0x3532646625202c35,0x09636f6c2e090a3b\n"
".quad 0x3009303233093133,0x36662e766f6d090a,0x3732646625092034,0x363566336430202c\n"
".quad 0x3363363163363163,0x2f2f093b63653161,0x38333130302e3020,0x64616d090a393838\n"
".quad 0x203436662e6e722e,0x202c383264662509,0x25202c3632646625,0x6625202c35316466\n"
".quad 0x6c2e090a3b373264,0x323309313309636f,0x766f6d090a300931,0x662509203436662e\n"
".quad 0x336430202c393264,0x3131313131313866,0x3b31363139303131,0x30302e30202f2f09\n"
".quad 0x090a333333333338,0x662e6e722e64616d,0x3364662509203436,0x3832646625202c30\n"
".quad 0x2c3531646625202c,0x0a3b393264662520,0x313309636f6c2e09,0x090a300932323309\n"
".quad 0x203436662e766f6d,0x202c313364662509,0x3535356166336430,0x3435353535353535\n"
".quad 0x30202f2f093b3163,0x373636363134302e,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x646625202c323364,0x31646625202c3033,0x3133646625202c35,0x09636f6c2e090a3b\n"
".quad 0x3009333233093133,0x36662e766f6d090a,0x3333646625092034,0x356366336430202c\n"
".quad 0x3535353535353535,0x2f2f093b66363535,0x36363636312e3020,0x722e64616d090a37\n"
".quad 0x2509203436662e6e,0x6625202c34336466,0x646625202c323364,0x33646625202c3531\n"
".quad 0x636f6c2e090a3b33,0x0934323309313309,0x662e766f6d090a30,0x3364662509203436\n"
".quad 0x6566336430202c35,0x3030303030303030,0x2f093b3030303030,0x6d090a352e30202f\n"
".quad 0x36662e6e722e6461,0x3633646625092034,0x2c3433646625202c,0x202c353164662520\n"
".quad 0x090a3b3533646625,0x09313309636f6c2e,0x6d090a3009363233,0x09203436662e6c75\n"
".quad 0x25202c3733646625,0x6625202c35316466,0x616d090a3b363364,0x3436662e6e722e64\n"
".quad 0x2c38336466250920,0x202c373364662520,0x25202c3531646625,0x2e090a3b35316466\n"
".quad 0x3709313309636f6c,0x6873090a30093832,0x2509203233622e6c,0x347225202c333472\n"
".quad 0x090a3b3032202c30,0x203233732e646461,0x25202c3434722509,0x373031202c333472\n"
".quad 0x3b32373634343631,0x33732e766f6d090a,0x2c35347225092032,0x766f6d090a3b3020\n"
".quad 0x662509203436622e,0x72257b202c393364,0x7d343472252c3534,0x722e64616d090a3b\n"
".quad 0x2509203436662e6e,0x6625202c30346466,0x646625202c383364,0x33646625202c3933\n"
".quad 0x2e766f6d090a3b39,0x3472250920323373,0x6d090a3b30202c36,0x09203436622e766f\n"
".quad 0x7b202c3134646625,0x3472252c36347225,0x6c756d090a3b7d32,0x662509203436662e\n"
".quad 0x646625202c323464,0x34646625202c3034,0x2e617262090a3b31,0x444c240920696e75\n"
".quad 0x69725f69646e6557,0x315f3830325f746e,0x5f315f744c240a3b,0x200a3a3636303432\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c343631,0x656c6562616c2064,0x5f315f744c242064,0x2e090a3031383332\n"
".quad 0x3709313309636f6c,0x6f6d090a30093233,0x2509203436662e76,0x6430202c33346466\n"
".quad 0x3030303030666637,0x3030303030303030,0x666e69202f2f093b,0x36662e766f6d090a\n"
".quad 0x3434646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e766f6d090a3020,0x3472250920323373,0x73090a3b30202c37,0x732e65672e707465\n"
".quad 0x2c35702509203233,0x25202c3033722520,0x6573090a3b373472,0x09203436662e706c\n"
".quad 0x25202c3534646625,0x6625202c33346466,0x357025202c343464,0x662e646461090a3b\n"
".quad 0x3464662509203436,0x2c38646625202c36,0x090a3b3864662520,0x203436662e736261\n"
".quad 0x202c373464662509,0x6d090a3b38646625,0x09203436662e766f,0x30202c3834646625\n"
".quad 0x3030303066663764,0x3030303030303030,0x6e69202f2f093b30,0x2e70746573090a66\n"
".quad 0x09203436662e656c,0x646625202c367025,0x34646625202c3734,0x706c6573090a3b38\n"
".quad 0x662509203436662e,0x646625202c323464,0x34646625202c3534,0x0a3b367025202c36\n"
".quad 0x69646e6557444c24,0x30325f746e69725f,0x2f2f200a3a315f38,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363120656e696c20,0x2064616568202c34\n"
".quad 0x2064656c6562616c,0x33325f315f744c24,0x6f6c2e090a303138,0x0939363109330963\n"
".quad 0x662e6c756d090a30,0x3464662509203436,0x2c34646625202c39,0x0a3b323464662520\n"
".quad 0x3436662e62757309,0x2c30356466250920,0x202c393464662520,0x6d090a3b33646625\n"
".quad 0x09203436662e766f,0x30202c3135646625,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e78616d09,0x2c32356466250920,0x202c303564662520\n"
".quad 0x090a3b3135646625,0x203436662e646461,0x25202c3664662509,0x6625202c32356466\n"
".quad 0x6f6c2e090a3b3664,0x0930373109330963,0x722e64616d090a30,0x2509203436662e6e\n"
".quad 0x646625202c356466,0x35646625202c3235,0x3b35646625202c32,0x33752e646461090a\n"
".quad 0x2c36327225092032,0x31202c3632722520,0x6573090a3b343230,0x33752e746c2e7074\n"
".quad 0x202c377025092032,0x7225202c36327225,0x702540090a3b3732,0x2409206172622037\n"
".quad 0x3833325f315f744c,0x3c2f2f200a3b3031,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x34363120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3033325f315f744c,0x2e617262090a3234,0x744c240920696e75,0x38393233325f315f\n"
".quad 0x5f315f744c240a3b,0x200a3a3039343133,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c343631,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x6d090a3234303332,0x09203436662e766f,0x6430202c35646625\n"
".quad 0x3030303030303030,0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d\n"
".quad 0x30202c3664662509,0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30\n"
".quad 0x33325f315f744c24,0x2f2f200a3a383932,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x363120656e696c20,0x2064616568202c34,0x2064656c6562616c\n"
".quad 0x33325f315f744c24,0x6f6c2e090a323430,0x0932373109330963,0x68732e7473090a30\n"
".quad 0x3436662e64657261,0x2b333172255b0920,0x36646625202c5d30,0x09636f6c2e090a3b\n"
".quad 0x0a30093337310933,0x726168732e747309,0x09203436662e6465,0x5d302b343172255b\n"
".quad 0x0a3b35646625202c,0x3233752e64646109,0x25202c3272250920,0x31317225202c3272\n"
".quad 0x752e646461090a3b,0x3431722509203233,0x202c32317225202c,0x61090a3b34317225\n"
".quad 0x09203233752e6464,0x7225202c33317225,0x33317225202c3231,0x752e766f6d090a3b\n"
".quad 0x3834722509203233,0x090a3b353532202c,0x2e656c2e70746573,0x3870250920323373\n"
".quad 0x25202c327225202c,0x2540090a3b383472,0x0920617262203870,0x33325f315f744c24\n"
".quad 0x744c240a3b323430,0x30333532325f315f,0x09636f6c2e090a3a,0x0a30093837310933\n"
".quad 0x3233752e766f6d09,0x5f202c3472250920,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f34335f30393936,0x6c61436d75535f73,0x0a3b38323338396c\n"
".quad 0x3233752e766f6d09,0x5f202c3572250920,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f34335f31393936,0x6143326d75535f73,0x3637333030316c6c\n"
".quad 0x09636f6c2e090a3b,0x0a30093837093831,0x3233732e766f6d09,0x202c393472250920\n"
".quad 0x2140090a3b317225,0x2061726220317025,0x325f315f744c2409,0x6d090a3b32303635\n"
".quad 0x09203233732e766f,0x3135202c30357225,0x2e627573090a3b31,0x3572250920323373\n"
".quad 0x2c30357225202c31,0x73090a3b31722520,0x09203233732e7268,0x7225202c32357225\n"
".quad 0x0a3b3133202c3135,0x3233732e766f6d09,0x202c333572250920,0x6e61090a3b353532\n"
".quad 0x2509203233622e64,0x357225202c343572,0x3b33357225202c32,0x33732e646461090a\n"
".quad 0x2c35357225092032,0x25202c3435722520,0x6873090a3b313572,0x2509203233732e72\n"
".quad 0x357225202c363572,0x6d090a3b38202c35,0x09203233732e766f,0x7225202c37357225\n"
".quad 0x5f744c240a3b3635,0x3a34313136325f31,0x6f6f6c3c2f2f200a,0x20706f6f4c203e70\n"
".quad 0x6e696c2079646f62,0x656e202c38372065,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6574616d69747365,0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b\n"
".quad 0x3709383109636f6c,0x726162090a300939,0x300920636e79732e,0x09636f6c2e090a3b\n"
".quad 0x0a30093038093831,0x3233752e766f6d09,0x202c383572250920,0x6573090a3b373231\n"
".quad 0x33732e74672e7074,0x202c397025092032,0x7225202c39347225,0x702540090a3b3835\n"
".quad 0x2409206172622039,0x3336325f315f744c,0x3c2f2f200a3b3037,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x2c383720656e696c,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313136325f315f74,0x09636f6c2e090a34,0x0a30093535093831\n"
".quad 0x2e6f6c2e6c756d09,0x3572250920323375,0x2c39347225202c39,0x646461090a3b3820\n"
".quad 0x722509203233752e,0x39357225202c3036,0x090a3b347225202c,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c33356466,0x0a3b5d302b303672,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x5b202c3435646625,0x3230312b30367225,0x646461090a3b5d34\n"
".quad 0x662509203436662e,0x646625202c353564,0x35646625202c3335,0x732e7473090a3b34\n"
".quad 0x36662e6465726168,0x303672255b092034,0x646625202c5d302b,0x646461090a3b3535\n"
".quad 0x722509203233752e,0x39357225202c3136,0x090a3b357225202c,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c36356466,0x0a3b5d302b313672,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x5b202c3735646625,0x3230312b31367225,0x646461090a3b5d34\n"
".quad 0x662509203436662e,0x646625202c383564,0x35646625202c3635,0x732e7473090a3b37\n"
".quad 0x36662e6465726168,0x313672255b092034,0x646625202c5d302b,0x5f744c240a3b3835\n"
".quad 0x3a30373336325f31,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c38372065,0x6c6562616c206461,0x315f744c24206465\n"
".quad 0x090a34313136325f,0x636e79732e726162,0x6f6d090a3b300920,0x2509203233752e76\n"
".quad 0x3b3336202c323672,0x672e70746573090a,0x2509203233732e74,0x347225202c303170\n"
".quad 0x3b32367225202c39,0x203031702540090a,0x744c240920617262,0x32383836325f315f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c383720656e,0x6562616c20646165,0x5f744c242064656c,0x0a34313136325f31\n"
".quad 0x383109636f6c2e09,0x6d090a3009363509,0x33752e6f6c2e6c75,0x2c39357225092032\n"
".quad 0x38202c3934722520,0x752e646461090a3b,0x3036722509203233,0x202c39357225202c\n"
".quad 0x646c090a3b347225,0x2e6465726168732e,0x6466250920343666,0x3672255b202c3935\n"
".quad 0x6c090a3b5d302b30,0x6465726168732e64,0x662509203436662e,0x72255b202c303664\n"
".quad 0x3b5d3231352b3036,0x36662e646461090a,0x3136646625092034,0x2c3935646625202c\n"
".quad 0x0a3b303664662520,0x726168732e747309,0x09203436662e6465,0x5d302b303672255b\n"
".quad 0x3b3136646625202c,0x33752e646461090a,0x2c31367225092032,0x25202c3935722520\n"
".quad 0x2e646c090a3b3572,0x662e646572616873,0x3664662509203436,0x313672255b202c32\n"
".quad 0x646c090a3b5d302b,0x2e6465726168732e,0x6466250920343666,0x3672255b202c3336\n"
".quad 0x0a3b5d3231352b31,0x3436662e64646109,0x2c34366466250920,0x202c323664662520\n"
".quad 0x090a3b3336646625,0x65726168732e7473,0x5b09203436662e64,0x2c5d302b31367225\n"
".quad 0x0a3b343664662520,0x36325f315f744c24,0x2f2f200a3a323838,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x383720656e696c20,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3136325f315f744c,0x2e726162090a3431,0x3b300920636e7973\n"
".quad 0x33752e766f6d090a,0x2c33367225092032,0x6573090a3b313320,0x33732e74672e7074\n"
".quad 0x2c31317025092032,0x25202c3934722520,0x2540090a3b333672,0x2061726220313170\n"
".quad 0x325f315f744c2409,0x2f200a3b34393337,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3720656e696c2079,0x2064616568202c38,0x2064656c6562616c\n"
".quad 0x36325f315f744c24,0x6f6c2e090a343131,0x0938350938310963,0x6c2e6c756d090a30\n"
".quad 0x2509203233752e6f,0x347225202c393572,0x61090a3b38202c39,0x09203233752e6464\n"
".quad 0x7225202c30367225,0x3b347225202c3935,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c353664662509,0x5d302b303672255b,0x68732e646c090a3b,0x3436662e64657261\n"
".quad 0x2c36366466250920,0x322b303672255b20,0x6461090a3b5d3635,0x2509203436662e64\n"
".quad 0x6625202c37366466,0x646625202c353664,0x2e7473090a3b3636,0x662e646572616873\n"
".quad 0x3672255b09203436,0x6625202c5d302b30,0x6461090a3b373664,0x2509203233752e64\n"
".quad 0x357225202c313672,0x0a3b357225202c39,0x726168732e646c09,0x09203436662e6465\n"
".quad 0x5b202c3836646625,0x3b5d302b31367225,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c393664662509,0x35322b313672255b,0x646461090a3b5d36,0x662509203436662e\n"
".quad 0x646625202c303764,0x36646625202c3836,0x732e7473090a3b39,0x36662e6465726168\n"
".quad 0x313672255b092034,0x646625202c5d302b,0x5f744c240a3b3037,0x3a34393337325f31\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c38372065,0x6c6562616c206461,0x315f744c24206465,0x090a34313136325f\n"
".quad 0x636e79732e726162,0x6f6d090a3b300920,0x2509203233752e76,0x3b3531202c343672\n"
".quad 0x672e70746573090a,0x2509203233732e74,0x347225202c323170,0x3b34367225202c39\n"
".quad 0x203231702540090a,0x744c240920617262,0x36303937325f315f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383720656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34313136325f31,0x383109636f6c2e09\n"
".quad 0x6d090a3009393509,0x33752e6f6c2e6c75,0x2c39357225092032,0x38202c3934722520\n"
".quad 0x752e646461090a3b,0x3036722509203233,0x202c39357225202c,0x646c090a3b347225\n"
".quad 0x2e6465726168732e,0x6466250920343666,0x3672255b202c3137,0x6c090a3b5d302b30\n"
".quad 0x6465726168732e64,0x662509203436662e,0x72255b202c323764,0x3b5d3832312b3036\n"
".quad 0x36662e646461090a,0x3337646625092034,0x2c3137646625202c,0x0a3b323764662520\n"
".quad 0x726168732e747309,0x09203436662e6465,0x5d302b303672255b,0x3b3337646625202c\n"
".quad 0x33752e646461090a,0x2c31367225092032,0x25202c3935722520,0x2e646c090a3b3572\n"
".quad 0x662e646572616873,0x3764662509203436,0x313672255b202c34,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x6466250920343666,0x3672255b202c3537,0x0a3b5d3832312b31\n"
".quad 0x3436662e64646109,0x2c36376466250920,0x202c343764662520,0x090a3b3537646625\n"
".quad 0x65726168732e7473,0x5b09203436662e64,0x2c5d302b31367225,0x0a3b363764662520\n"
".quad 0x37325f315f744c24,0x2f2f200a3a363039,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x383720656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3136325f315f744c,0x2e726162090a3431,0x3b300920636e7973,0x33752e766f6d090a\n"
".quad 0x2c35367225092032,0x746573090a3b3720,0x3233732e74672e70,0x202c333170250920\n"
".quad 0x7225202c39347225,0x702540090a3b3536,0x0920617262203331,0x38325f315f744c24\n"
".quad 0x2f2f200a3b383134,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x383720656e696c20,0x6c2064616568202c,0x242064656c656261,0x3136325f315f744c\n"
".quad 0x636f6c2e090a3431,0x3009303609383109,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x39347225202c3935,0x6461090a3b38202c,0x2509203233752e64,0x357225202c303672\n"
".quad 0x0a3b347225202c39,0x726168732e646c09,0x09203436662e6465,0x5b202c3737646625\n"
".quad 0x3b5d302b30367225,0x6168732e646c090a,0x203436662e646572,0x202c383764662509\n"
".quad 0x34362b303672255b,0x2e646461090a3b5d,0x6466250920343666,0x37646625202c3937\n"
".quad 0x3837646625202c37,0x68732e7473090a3b,0x3436662e64657261,0x2b303672255b0920\n"
".quad 0x37646625202c5d30,0x2e646461090a3b39,0x3672250920323375,0x2c39357225202c31\n"
".quad 0x6c090a3b35722520,0x6465726168732e64,0x662509203436662e,0x72255b202c303864\n"
".quad 0x090a3b5d302b3136,0x65726168732e646c,0x2509203436662e64,0x255b202c31386466\n"
".quad 0x3b5d34362b313672,0x36662e646461090a,0x3238646625092034,0x2c3038646625202c\n"
".quad 0x0a3b313864662520,0x726168732e747309,0x09203436662e6465,0x5d302b313672255b\n"
".quad 0x3b3238646625202c,0x325f315f744c240a,0x2f200a3a38313438,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3720656e696c2079,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x36325f315f744c24,0x726162090a343131,0x300920636e79732e\n"
".quad 0x752e766f6d090a3b,0x3636722509203233,0x6573090a3b33202c,0x33732e74672e7074\n"
".quad 0x2c34317025092032,0x25202c3934722520,0x2540090a3b363672,0x2061726220343170\n"
".quad 0x325f315f744c2409,0x2f200a3b30333938,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3720656e696c2079,0x2064616568202c38,0x2064656c6562616c\n"
".quad 0x36325f315f744c24,0x6f6c2e090a343131,0x0931360938310963,0x6c2e6c756d090a30\n"
".quad 0x2509203233752e6f,0x347225202c393572,0x61090a3b38202c39,0x09203233752e6464\n"
".quad 0x7225202c30367225,0x3b347225202c3935,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c333864662509,0x5d302b303672255b,0x68732e646c090a3b,0x3436662e64657261\n"
".quad 0x2c34386466250920,0x332b303672255b20,0x646461090a3b5d32,0x662509203436662e\n"
".quad 0x646625202c353864,0x38646625202c3338,0x732e7473090a3b34,0x36662e6465726168\n"
".quad 0x303672255b092034,0x646625202c5d302b,0x646461090a3b3538,0x722509203233752e\n"
".quad 0x39357225202c3136,0x090a3b357225202c,0x65726168732e646c,0x2509203436662e64\n"
".quad 0x255b202c36386466,0x0a3b5d302b313672,0x726168732e646c09,0x09203436662e6465\n"
".quad 0x5b202c3738646625,0x5d32332b31367225,0x662e646461090a3b,0x3864662509203436\n"
".quad 0x3638646625202c38,0x3b3738646625202c,0x6168732e7473090a,0x203436662e646572\n"
".quad 0x302b313672255b09,0x3838646625202c5d,0x5f315f744c240a3b,0x200a3a3033393832\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3837,0x64656c6562616c20,0x325f315f744c2420,0x6162090a34313136\n"
".quad 0x0920636e79732e72,0x2e766f6d090a3b30,0x3672250920323375,0x73090a3b31202c37\n"
".quad 0x732e74672e707465,0x3531702509203233,0x202c39347225202c,0x40090a3b37367225\n"
".quad 0x6172622035317025,0x5f315f744c240920,0x200a3b3234343932,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3837\n"
".quad 0x64656c6562616c20,0x325f315f744c2420,0x6c2e090a34313136,0x323609383109636f\n"
".quad 0x2e6c756d090a3009,0x09203233752e6f6c,0x7225202c39357225,0x090a3b38202c3934\n"
".quad 0x203233752e646461,0x25202c3036722509,0x347225202c393572,0x68732e646c090a3b\n"
".quad 0x3436662e64657261,0x2c39386466250920,0x302b303672255b20,0x732e646c090a3b5d\n"
".quad 0x36662e6465726168,0x3039646625092034,0x2b303672255b202c,0x6461090a3b5d3631\n"
".quad 0x2509203436662e64,0x6625202c31396466,0x646625202c393864,0x2e7473090a3b3039\n"
".quad 0x662e646572616873,0x3672255b09203436,0x6625202c5d302b30,0x6461090a3b313964\n"
".quad 0x2509203233752e64,0x357225202c313672,0x0a3b357225202c39,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x5b202c3239646625,0x3b5d302b31367225,0x6168732e646c090a\n"
".quad 0x203436662e646572,0x202c333964662509,0x36312b313672255b,0x2e646461090a3b5d\n"
".quad 0x6466250920343666,0x39646625202c3439,0x3339646625202c32,0x68732e7473090a3b\n"
".quad 0x3436662e64657261,0x2b313672255b0920,0x39646625202c5d30,0x315f744c240a3b34\n"
".quad 0x0a3a32343439325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064,0x5f315f744c242064\n"
".quad 0x62090a3431313632,0x20636e79732e7261,0x766f6d090a3b3009,0x722509203233752e\n"
".quad 0x090a3b30202c3836,0x2e74672e70746573,0x3170250920323373,0x2c39347225202c36\n"
".quad 0x090a3b3836722520,0x7262203631702540,0x315f744c24092061,0x0a3b34353939325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c383720,0x656c6562616c2064,0x5f315f744c242064,0x2e090a3431313632\n"
".quad 0x3609383109636f6c,0x6c756d090a300933,0x203233752e6f6c2e,0x25202c3935722509\n"
".quad 0x0a3b38202c393472,0x3233752e64646109,0x202c303672250920,0x7225202c39357225\n"
".quad 0x732e646c090a3b34,0x36662e6465726168,0x3539646625092034,0x2b303672255b202c\n"
".quad 0x2e646c090a3b5d30,0x662e646572616873,0x3964662509203436,0x303672255b202c36\n"
".quad 0x6461090a3b5d382b,0x2509203436662e64,0x6625202c37396466,0x646625202c353964\n"
".quad 0x2e7473090a3b3639,0x662e646572616873,0x3672255b09203436,0x6625202c5d302b30\n"
".quad 0x6461090a3b373964,0x2509203233752e64,0x357225202c313672,0x0a3b357225202c39\n"
".quad 0x726168732e646c09,0x09203436662e6465,0x5b202c3839646625,0x3b5d302b31367225\n"
".quad 0x6168732e646c090a,0x203436662e646572,0x202c393964662509,0x5d382b313672255b\n"
".quad 0x662e646461090a3b,0x3164662509203436,0x39646625202c3030,0x3939646625202c38\n"
".quad 0x68732e7473090a3b,0x3436662e64657261,0x2b313672255b0920,0x31646625202c5d30\n"
".quad 0x5f744c240a3b3030,0x3a34353939325f31,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38372065,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x090a34313136325f,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x303809383109636f,0x2e646461090a3009,0x3472250920323373,0x2c39347225202c39\n"
".quad 0x6d090a3b36353220,0x09203233752e766f,0x3532202c39367225,0x70746573090a3b35\n"
".quad 0x203233732e656c2e,0x25202c3731702509,0x367225202c393472,0x31702540090a3b39\n"
".quad 0x2409206172622037,0x3136325f315f744c,0x5f744c240a3b3431,0x3a32303635325f31\n"
".quad 0x3309636f6c2e090a,0x090a300938373109,0x203233752e766f6d,0x30202c3037722509\n"
".quad 0x2e70746573090a3b,0x09203233752e656e,0x7225202c38317025,0x3b30377225202c31\n"
".quad 0x203831702540090a,0x744c240920617262,0x32323730335f315f,0x09636f6c2e090a3b\n"
".quad 0x0a30093138310933,0x3233732e74766309,0x722509203631752e,0x61746325202c3137\n"
".quad 0x63090a3b782e6469,0x752e3631752e7476,0x3268722509203233,0x0a3b31377225202c\n"
".quad 0x6469772e6c756d09,0x2509203631752e65,0x687225202c323772,0x090a3b3631202c32\n"
".quad 0x203233752e766f6d,0x64202c3337722509,0x6c61566c6c61435f,0x646461090a3b6575\n"
".quad 0x722509203233752e,0x32377225202c3437,0x0a3b33377225202c,0x726168732e646c09\n"
".quad 0x09203436662e6465,0x202c313031646625,0x5f616475635f5f5b,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f30393936325f,0x436d75535f735f34,0x38323338396c6c61\n"
".quad 0x7473090a3b5d302b,0x2e6c61626f6c672e,0x72255b0920343666,0x25202c5d302b3437\n"
".quad 0x090a3b3130316466,0x65726168732e646c,0x2509203436662e64,0x5b202c3230316466\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x34335f3139393632\n"
".quad 0x43326d75535f735f,0x37333030316c6c61,0x73090a3b5d302b36,0x6c61626f6c672e74\n"
".quad 0x255b09203436662e,0x202c5d382b343772,0x0a3b323031646625,0x30335f315f744c24\n"
".quad 0x6c2e090a3a323237,0x333831093309636f,0x74697865090a3009,0x6e6557444c240a3b\n"
".quad 0x6f4d37325a5f5f64,0x6f6c72614365746e,0x6b636f6c42656e4f,0x6f6974704f726550\n"
".quad 0x7d090a3a6966506e,0x37325a5f202f2f20,0x72614365746e6f4d,0x6f6c42656e4f6f6c\n"
".quad 0x74704f7265506b63,0x0a0a6966506e6f69,0x207972746e652e09,0x746e6f4d36315a5f\n"
".quad 0x65526f6c72614365,0x5f34315065637564,0x6e6f6974704f545f,0x28206965756c6156\n"
".quad 0x617261702e09090a,0x5f203233752e206d,0x726170616475635f,0x6f4d36315a5f5f6d\n"
".quad 0x6f6c72614365746e,0x3150656375646552,0x6974704f545f5f34,0x6965756c61566e6f\n"
".quad 0x65666675425f645f,0x61702e09090a2c72,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72614365746e6f4d,0x6563756465526f6c,0x704f545f5f343150\n"
".quad 0x756c61566e6f6974,0x6d756363615f6965,0x2e090a7b090a294e,0x3631752e20676572\n"
".quad 0x3b3e333c68722520,0x2e206765722e090a,0x353c722520323375,0x65722e090a3b3e36\n"
".quad 0x25203436662e2067,0x0a3b3e36353c6466,0x702e206765722e09,0x313c702520646572\n"
".quad 0x68732e090a3b3e36,0x6c612e2064657261,0x622e2038206e6769,0x616475635f5f2038\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f34333037325f72,0x6d75535f735f3433\n"
".quad 0x343230316c6c6143,0x5d383430325b3233,0x726168732e090a3b,0x67696c612e206465\n"
".quad 0x2038622e2038206e,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x34335f3533303732,0x43326d75535f735f,0x38343430316c6c61,0x3b5d383430325b30\n"
".quad 0x3309636f6c2e090a,0x240a300933393109,0x6e6967656257444c,0x6e6f4d36315a5f5f\n"
".quad 0x526f6c7261436574,0x3431506563756465,0x6f6974704f545f5f,0x3a6965756c61566e\n"
".quad 0x3309636f6c2e090a,0x090a300932303209,0x2e3233732e747663,0x3172250920363175\n"
".quad 0x782e64697425202c,0x732e766f6d090a3b,0x2c32722509203233,0x6d090a3b31722520\n"
".quad 0x09203233732e766f,0x353532202c337225,0x2e70746573090a3b,0x09203233732e656c\n"
".quad 0x317225202c317025,0x090a3b337225202c,0x7262203170252140,0x325f744c24092061\n"
".quad 0x0a3b38373138315f,0x3233752e766f6d09,0x5f202c3472250920,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f34335f34333037,0x6c61436d75535f73\n"
".quad 0x3b3233343230316c,0x33752e766f6d090a,0x202c357225092032,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x34335f3533303732,0x43326d75535f735f\n"
".quad 0x38343430316c6c61,0x702e646c090a3b30,0x3233752e6d617261,0x5b202c3672250920\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6c72614365746e6f,0x506563756465526f\n"
".quad 0x74704f545f5f3431,0x65756c61566e6f69,0x4e6d756363615f69,0x2e747663090a3b5d\n"
".quad 0x203631752e323375,0x6325202c37722509,0x0a3b782e64696174,0x2e6f6c2e6c756d09\n"
".quad 0x3872250920323375,0x25202c377225202c,0x6c756d090a3b3672,0x203233752e6f6c2e\n"
".quad 0x7225202c39722509,0x090a3b3631202c38,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x635f5f5b202c3031,0x5f6d726170616475,0x746e6f4d36315a5f,0x65526f6c72614365\n"
".quad 0x5f34315065637564,0x6e6f6974704f545f,0x645f6965756c6156,0x5d7265666675425f\n"
".quad 0x752e646461090a3b,0x3131722509203233,0x202c30317225202c,0x756d090a3b397225\n"
".quad 0x752e6f6c2e34326c,0x3231722509203233,0x38202c317225202c,0x752e747663090a3b\n"
".quad 0x09203631752e3233,0x6e25202c33317225,0x090a3b782e646974,0x6f6c2e34326c756d\n"
".quad 0x722509203233752e,0x33317225202c3431,0x6461090a3b38202c,0x2509203233752e64\n"
".quad 0x317225202c353172,0x0a3b347225202c32,0x3233752e64646109,0x202c363172250920\n"
".quad 0x7225202c32317225,0x325f744c240a3b35,0x0a3a30393638315f,0x706f6f6c3c2f2f20\n"
".quad 0x6220706f6f4c203e,0x656e696c2079646f,0x656e202c32303220,0x656420676e697473\n"
".quad 0x202c31203a687470,0x6574616d69747365,0x7461726574692064,0x6e75203a736e6f69\n"
".quad 0x6c090a6e776f6e6b,0x2e6d617261702e64,0x3672250920323375,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x4365746e6f4d3631,0x756465526f6c7261,0x545f5f3431506563\n"
".quad 0x61566e6f6974704f,0x6363615f6965756c,0x73090a3b5d4e6d75,0x732e65672e707465\n"
".quad 0x2c32702509203233,0x7225202c32722520,0x32702540090a3b36,0x4c24092061726220\n"
".quad 0x313136325f325f74,0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c32303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393638315f325f74,0x61702e646c090a30,0x203233752e6d6172,0x5f5b202c36722509\n"
".quad 0x726170616475635f,0x6f4d36315a5f5f6d,0x6f6c72614365746e,0x3150656375646552\n"
".quad 0x6974704f545f5f34,0x6965756c61566e6f,0x5d4e6d756363615f,0x732e627573090a3b\n"
".quad 0x3731722509203233,0x25202c367225202c,0x646461090a3b3272,0x722509203233732e\n"
".quad 0x37317225202c3831,0x090a3b353532202c,0x203233732e726873,0x25202c3931722509\n"
".quad 0x3b3133202c383172,0x33732e766f6d090a,0x2c30327225092032,0x61090a3b35353220\n"
".quad 0x09203233622e646e,0x7225202c31327225,0x30327225202c3931,0x732e646461090a3b\n"
".quad 0x3232722509203233,0x202c31327225202c,0x73090a3b38317225,0x09203233732e7268\n"
".quad 0x7225202c33327225,0x090a3b38202c3232,0x752e6f6c2e6c756d,0x3432722509203233\n"
".quad 0x31202c327225202c,0x2e6c756d090a3b36,0x09203233752e6f6c,0x7225202c35327225\n"
".quad 0x090a3b3631202c36,0x203233732e646461,0x25202c3632722509,0x317225202c343272\n"
".quad 0x2e646461090a3b31,0x3272250920323373,0x2c35327225202c37,0x090a3b3131722520\n"
".quad 0x203436662e766f6d,0x30202c3164662509,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x3436662e766f6d09,0x202c326466250920,0x3030303030306430\n"
".quad 0x3030303030303030,0x30202f2f093b3030,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3230322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a30393638315f32,0x3233732e766f6d09,0x202c383272250920\n"
".quad 0x4c240a3b33327225,0x353439315f325f74,0x6c3c2f2f200a3a38,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x2c32303220656e69,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6d69747365202c32,0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520\n"
".quad 0x3309636f6c2e090a,0x090a300936303209,0x61626f6c672e646c,0x2509203436662e6c\n"
".quad 0x72255b202c336466,0x090a3b5d302b3632,0x203436662e646461,0x25202c3264662509\n"
".quad 0x646625202c336466,0x636f6c2e090a3b32,0x3009373032093309,0x6f6c672e646c090a\n"
".quad 0x203436662e6c6162,0x5b202c3464662509,0x3b5d382b36327225,0x36662e646461090a\n"
".quad 0x2c31646625092034,0x25202c3464662520,0x6461090a3b316466,0x2509203233732e64\n"
".quad 0x327225202c363272,0x3b36393034202c36,0x6c2e70746573090a,0x2509203233752e74\n"
".quad 0x36327225202c3370,0x0a3b37327225202c,0x7262203370254009,0x325f744c24092061\n"
".quad 0x0a3b38353439315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c32303220,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a30393638315f,0x20696e752e617262,0x315f325f744c2409,0x4c240a3b36343938\n"
".quad 0x313136325f325f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c32303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393638315f325f74,0x662e766f6d090a30,0x3164662509203436,0x303030306430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x2e766f6d090a3020,0x6466250920343666\n"
".quad 0x3030306430202c32,0x3030303030303030,0x2f093b3030303030,0x5f744c240a30202f\n"
".quad 0x3a36343938315f32,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3230322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30393638315f32,0x093309636f6c2e09,0x73090a3009393032,0x6465726168732e74\n"
".quad 0x255b09203436662e,0x202c5d302b353172,0x2e090a3b32646625,0x3132093309636f6c\n"
".quad 0x2e7473090a300930,0x662e646572616873,0x3172255b09203436,0x6625202c5d302b36\n"
".quad 0x646461090a3b3164,0x722509203233752e,0x202c327225202c32,0x61090a3b33317225\n"
".quad 0x09203233752e6464,0x7225202c36317225,0x36317225202c3431,0x752e646461090a3b\n"
".quad 0x3531722509203233,0x202c34317225202c,0x6d090a3b35317225,0x09203233752e766f\n"
".quad 0x3532202c39327225,0x70746573090a3b35,0x203233732e656c2e,0x7225202c34702509\n"
".quad 0x3b39327225202c32,0x622034702540090a,0x5f744c2409206172,0x3b30393638315f32\n"
".quad 0x315f325f744c240a,0x2e090a3a38373138,0x3132093309636f6c,0x766f6d090a300935\n"
".quad 0x722509203233752e,0x6475635f5f202c34,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x34333037325f7261,0x75535f735f34335f,0x3230316c6c61436d,0x6f6d090a3b323334\n"
".quad 0x2509203233752e76,0x75635f5f202c3572,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x333037325f726176,0x535f735f34335f35,0x316c6c6143326d75,0x090a3b3038343430\n"
".quad 0x09383109636f6c2e,0x6f6d090a30093837,0x2509203233732e76,0x317225202c303372\n"
".quad 0x3170252140090a3b,0x4c24092061726220,0x323230325f325f74,0x2e766f6d090a3b36\n"
".quad 0x3372250920323373,0x0a3b313135202c31,0x3233732e62757309,0x202c323372250920\n"
".quad 0x7225202c31337225,0x2e726873090a3b31,0x3372250920323373,0x2c32337225202c33\n"
".quad 0x6f6d090a3b313320,0x2509203233732e76,0x353532202c343372,0x622e646e61090a3b\n"
".quad 0x3533722509203233,0x202c33337225202c,0x61090a3b34337225,0x09203233732e6464\n"
".quad 0x7225202c36337225,0x32337225202c3533,0x732e726873090a3b,0x3733722509203233\n"
".quad 0x202c36337225202c,0x2e766f6d090a3b38,0x3372250920323373,0x3b37337225202c38\n"
".quad 0x325f325f744c240a,0x2f200a3a38333730,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3720656e696c2079,0x697473656e202c38,0x687470656420676e,0x747365202c31203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x3009393709383109,0x79732e726162090a,0x090a3b300920636e,0x09383109636f6c2e\n"
".quad 0x6f6d090a30093038,0x2509203233752e76,0x373231202c393372,0x2e70746573090a3b\n"
".quad 0x09203233732e7467,0x337225202c357025,0x3b39337225202c30,0x622035702540090a\n"
".quad 0x5f744c2409206172,0x3b34393930325f32,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38372065,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a38333730325f,0x09383109636f6c2e,0x756d090a30093535\n"
".quad 0x3233752e6f6c2e6c,0x202c303472250920,0x3b38202c30337225,0x33752e646461090a\n"
".quad 0x2c31347225092032,0x25202c3034722520,0x2e646c090a3b3472,0x662e646572616873\n"
".quad 0x3564662509203436,0x2b313472255b202c,0x2e646c090a3b5d30,0x662e646572616873\n"
".quad 0x3664662509203436,0x2b313472255b202c,0x090a3b5d34323031,0x203436662e646461\n"
".quad 0x25202c3764662509,0x646625202c356466,0x732e7473090a3b36,0x36662e6465726168\n"
".quad 0x313472255b092034,0x646625202c5d302b,0x2e646461090a3b37,0x3472250920323375\n"
".quad 0x2c30347225202c32,0x6c090a3b35722520,0x6465726168732e64,0x662509203436662e\n"
".quad 0x3472255b202c3864,0x6c090a3b5d302b32,0x6465726168732e64,0x662509203436662e\n"
".quad 0x3472255b202c3964,0x3b5d343230312b32,0x36662e646461090a,0x3031646625092034\n"
".quad 0x202c38646625202c,0x73090a3b39646625,0x6465726168732e74,0x255b09203436662e\n"
".quad 0x202c5d302b323472,0x240a3b3031646625,0x3930325f325f744c,0x3c2f2f200a3a3439\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c383720656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333730325f325f74,0x732e726162090a38\n"
".quad 0x0a3b300920636e79,0x3233752e766f6d09,0x202c333472250920,0x746573090a3b3336\n"
".quad 0x3233732e74672e70,0x25202c3670250920,0x347225202c303372,0x36702540090a3b33\n"
".quad 0x4c24092061726220,0x303531325f325f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333730325f325f,0x3109636f6c2e090a,0x090a300936350938\n"
".quad 0x752e6f6c2e6c756d,0x3034722509203233,0x202c30337225202c,0x2e646461090a3b38\n"
".quad 0x3472250920323375,0x2c30347225202c31,0x6c090a3b34722520,0x6465726168732e64\n"
".quad 0x662509203436662e,0x72255b202c313164,0x090a3b5d302b3134,0x65726168732e646c\n"
".quad 0x2509203436662e64,0x255b202c32316466,0x5d3231352b313472,0x662e646461090a3b\n"
".quad 0x3164662509203436,0x3131646625202c33,0x3b3231646625202c,0x6168732e7473090a\n"
".quad 0x203436662e646572,0x302b313472255b09,0x3331646625202c5d,0x752e646461090a3b\n"
".quad 0x3234722509203233,0x202c30347225202c,0x646c090a3b357225,0x2e6465726168732e\n"
".quad 0x6466250920343666,0x3472255b202c3431,0x6c090a3b5d302b32,0x6465726168732e64\n"
".quad 0x662509203436662e,0x72255b202c353164,0x3b5d3231352b3234,0x36662e646461090a\n"
".quad 0x3631646625092034,0x2c3431646625202c,0x0a3b353164662520,0x726168732e747309\n"
".quad 0x09203436662e6465,0x5d302b323472255b,0x3b3631646625202c,0x325f325f744c240a\n"
".quad 0x2f200a3a36303531,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3720656e696c2079,0x2064616568202c38,0x2064656c6562616c,0x30325f325f744c24\n"
".quad 0x726162090a383337,0x300920636e79732e,0x752e766f6d090a3b,0x3434722509203233\n"
".quad 0x73090a3b3133202c,0x732e74672e707465,0x2c37702509203233,0x25202c3033722520\n"
".quad 0x2540090a3b343472,0x0920617262203770,0x32325f325f744c24,0x2f2f200a3b383130\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x383720656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3730325f325f744c,0x636f6c2e090a3833\n"
".quad 0x3009383509383109,0x6f6c2e6c756d090a,0x722509203233752e,0x30337225202c3034\n"
".quad 0x6461090a3b38202c,0x2509203233752e64,0x347225202c313472,0x0a3b347225202c30\n"
".quad 0x726168732e646c09,0x09203436662e6465,0x5b202c3731646625,0x3b5d302b31347225\n"
".quad 0x6168732e646c090a,0x203436662e646572,0x202c383164662509,0x35322b313472255b\n"
".quad 0x646461090a3b5d36,0x662509203436662e,0x646625202c393164,0x31646625202c3731\n"
".quad 0x732e7473090a3b38,0x36662e6465726168,0x313472255b092034,0x646625202c5d302b\n"
".quad 0x646461090a3b3931,0x722509203233752e,0x30347225202c3234,0x090a3b357225202c\n"
".quad 0x65726168732e646c,0x2509203436662e64,0x255b202c30326466,0x0a3b5d302b323472\n"
".quad 0x726168732e646c09,0x09203436662e6465,0x5b202c3132646625,0x3635322b32347225\n"
".quad 0x2e646461090a3b5d,0x6466250920343666,0x32646625202c3232,0x3132646625202c30\n"
".quad 0x68732e7473090a3b,0x3436662e64657261,0x2b323472255b0920,0x32646625202c5d30\n"
".quad 0x325f744c240a3b32,0x0a3a38313032325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064\n"
".quad 0x5f325f744c242064,0x62090a3833373032,0x20636e79732e7261,0x766f6d090a3b3009\n"
".quad 0x722509203233752e,0x0a3b3531202c3534,0x74672e7074657309,0x702509203233732e\n"
".quad 0x2c30337225202c38,0x090a3b3534722520,0x6172622038702540,0x5f325f744c240920\n"
".quad 0x200a3b3033353232,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3837,0x64656c6562616c20,0x325f325f744c2420\n"
".quad 0x6c2e090a38333730,0x393509383109636f,0x2e6c756d090a3009,0x09203233752e6f6c\n"
".quad 0x7225202c30347225,0x090a3b38202c3033,0x203233752e646461,0x25202c3134722509\n"
".quad 0x347225202c303472,0x68732e646c090a3b,0x3436662e64657261,0x2c33326466250920\n"
".quad 0x302b313472255b20,0x732e646c090a3b5d,0x36662e6465726168,0x3432646625092034\n"
".quad 0x2b313472255b202c,0x61090a3b5d383231,0x09203436662e6464,0x25202c3532646625\n"
".quad 0x6625202c33326466,0x7473090a3b343264,0x2e6465726168732e,0x72255b0920343666\n"
".quad 0x25202c5d302b3134,0x61090a3b35326466,0x09203233752e6464,0x7225202c32347225\n"
".quad 0x3b357225202c3034,0x6168732e646c090a,0x203436662e646572,0x202c363264662509\n"
".quad 0x5d302b323472255b,0x68732e646c090a3b,0x3436662e64657261,0x2c37326466250920\n"
".quad 0x312b323472255b20,0x6461090a3b5d3832,0x2509203436662e64,0x6625202c38326466\n"
".quad 0x646625202c363264,0x2e7473090a3b3732,0x662e646572616873,0x3472255b09203436\n"
".quad 0x6625202c5d302b32,0x744c240a3b383264,0x30333532325f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383720656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38333730325f32,0x6e79732e72616209\n"
".quad 0x6d090a3b30092063,0x09203233752e766f,0x3b37202c36347225,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x30337225202c3970,0x0a3b36347225202c,0x7262203970254009\n"
".quad 0x325f744c24092061,0x0a3b32343033325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c383720,0x656c6562616c2064\n"
".quad 0x5f325f744c242064,0x2e090a3833373032,0x3609383109636f6c,0x6c756d090a300930\n"
".quad 0x203233752e6f6c2e,0x25202c3034722509,0x0a3b38202c303372,0x3233752e64646109\n"
".quad 0x202c313472250920,0x7225202c30347225,0x732e646c090a3b34,0x36662e6465726168\n"
".quad 0x3932646625092034,0x2b313472255b202c,0x2e646c090a3b5d30,0x662e646572616873\n"
".quad 0x3364662509203436,0x313472255b202c30,0x61090a3b5d34362b,0x09203436662e6464\n"
".quad 0x25202c3133646625,0x6625202c39326466,0x7473090a3b303364,0x2e6465726168732e\n"
".quad 0x72255b0920343666,0x25202c5d302b3134,0x61090a3b31336466,0x09203233752e6464\n"
".quad 0x7225202c32347225,0x3b357225202c3034,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c323364662509,0x5d302b323472255b,0x68732e646c090a3b,0x3436662e64657261\n"
".quad 0x2c33336466250920,0x362b323472255b20,0x646461090a3b5d34,0x662509203436662e\n"
".quad 0x646625202c343364,0x33646625202c3233,0x732e7473090a3b33,0x36662e6465726168\n"
".quad 0x323472255b092034,0x646625202c5d302b,0x5f744c240a3b3433,0x3a32343033325f32\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c38372065,0x6c6562616c206461,0x325f744c24206465,0x090a38333730325f\n"
".quad 0x636e79732e726162,0x6f6d090a3b300920,0x2509203233752e76,0x0a3b33202c373472\n"
".quad 0x74672e7074657309,0x702509203233732e,0x30337225202c3031,0x0a3b37347225202c\n"
".quad 0x6220303170254009,0x5f744c2409206172,0x3b34353533325f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c38372065\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a38333730325f,0x09383109636f6c2e\n"
".quad 0x756d090a30093136,0x3233752e6f6c2e6c,0x202c303472250920,0x3b38202c30337225\n"
".quad 0x33752e646461090a,0x2c31347225092032,0x25202c3034722520,0x2e646c090a3b3472\n"
".quad 0x662e646572616873,0x3364662509203436,0x313472255b202c35,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x6466250920343666,0x3472255b202c3633,0x090a3b5d32332b31\n"
".quad 0x203436662e646461,0x202c373364662509,0x25202c3533646625,0x73090a3b36336466\n"
".quad 0x6465726168732e74,0x255b09203436662e,0x202c5d302b313472,0x090a3b3733646625\n"
".quad 0x203233752e646461,0x25202c3234722509,0x357225202c303472,0x68732e646c090a3b\n"
".quad 0x3436662e64657261,0x2c38336466250920,0x302b323472255b20,0x732e646c090a3b5d\n"
".quad 0x36662e6465726168,0x3933646625092034,0x2b323472255b202c,0x6461090a3b5d3233\n"
".quad 0x2509203436662e64,0x6625202c30346466,0x646625202c383364,0x2e7473090a3b3933\n"
".quad 0x662e646572616873,0x3472255b09203436,0x6625202c5d302b32,0x744c240a3b303464\n"
".quad 0x34353533325f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c383720656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38333730325f32,0x6e79732e72616209,0x6d090a3b30092063,0x09203233752e766f\n"
".quad 0x3b31202c38347225,0x672e70746573090a,0x2509203233732e74,0x337225202c313170\n"
".quad 0x3b38347225202c30,0x203131702540090a,0x744c240920617262,0x36363034325f325f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c383720656e,0x6562616c20646165,0x5f744c242064656c,0x0a38333730325f32\n"
".quad 0x383109636f6c2e09,0x6d090a3009323609,0x33752e6f6c2e6c75,0x2c30347225092032\n"
".quad 0x38202c3033722520,0x752e646461090a3b,0x3134722509203233,0x202c30347225202c\n"
".quad 0x646c090a3b347225,0x2e6465726168732e,0x6466250920343666,0x3472255b202c3134\n"
".quad 0x6c090a3b5d302b31,0x6465726168732e64,0x662509203436662e,0x72255b202c323464\n"
".quad 0x0a3b5d36312b3134,0x3436662e64646109,0x2c33346466250920,0x202c313464662520\n"
".quad 0x090a3b3234646625,0x65726168732e7473,0x5b09203436662e64,0x2c5d302b31347225\n"
".quad 0x0a3b333464662520,0x3233752e64646109,0x202c323472250920,0x7225202c30347225\n"
".quad 0x732e646c090a3b35,0x36662e6465726168,0x3434646625092034,0x2b323472255b202c\n"
".quad 0x2e646c090a3b5d30,0x662e646572616873,0x3464662509203436,0x323472255b202c35\n"
".quad 0x61090a3b5d36312b,0x09203436662e6464,0x25202c3634646625,0x6625202c34346466\n"
".quad 0x7473090a3b353464,0x2e6465726168732e,0x72255b0920343666,0x25202c5d302b3234\n"
".quad 0x4c240a3b36346466,0x363034325f325f74,0x6c3c2f2f200a3a36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38333730325f325f,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x203233752e766f6d,0x30202c3934722509,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x7225202c32317025,0x39347225202c3033,0x3231702540090a3b,0x4c24092061726220\n"
".quad 0x373534325f325f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x202c383720656e69,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38333730325f325f,0x3109636f6c2e090a,0x090a300933360938,0x752e6f6c2e6c756d\n"
".quad 0x3034722509203233,0x202c30337225202c,0x2e646461090a3b38,0x3472250920323375\n"
".quad 0x2c30347225202c31,0x6c090a3b34722520,0x6465726168732e64,0x662509203436662e\n"
".quad 0x72255b202c373464,0x090a3b5d302b3134,0x65726168732e646c,0x2509203436662e64\n"
".quad 0x255b202c38346466,0x0a3b5d382b313472,0x3436662e64646109,0x2c39346466250920\n"
".quad 0x202c373464662520,0x090a3b3834646625,0x65726168732e7473,0x5b09203436662e64\n"
".quad 0x2c5d302b31347225,0x0a3b393464662520,0x3233752e64646109,0x202c323472250920\n"
".quad 0x7225202c30347225,0x732e646c090a3b35,0x36662e6465726168,0x3035646625092034\n"
".quad 0x2b323472255b202c,0x2e646c090a3b5d30,0x662e646572616873,0x3564662509203436\n"
".quad 0x323472255b202c31,0x6461090a3b5d382b,0x2509203436662e64,0x6625202c32356466\n"
".quad 0x646625202c303564,0x2e7473090a3b3135,0x662e646572616873,0x3472255b09203436\n"
".quad 0x6625202c5d302b32,0x744c240a3b323564,0x38373534325f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x68202c383720656e\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38333730325f32,0x6e79732e72616209\n"
".quad 0x2e090a3b30092063,0x3809383109636f6c,0x646461090a300930,0x722509203233732e\n"
".quad 0x30337225202c3033,0x090a3b363532202c,0x203233752e766f6d,0x32202c3035722509\n"
".quad 0x746573090a3b3535,0x3233732e656c2e70,0x202c333170250920,0x7225202c30337225\n"
".quad 0x702540090a3b3035,0x0920617262203331,0x30325f325f744c24,0x744c240a3b383337\n"
".quad 0x36323230325f325f,0x09636f6c2e090a3a,0x0a30093531320933,0x3233752e766f6d09\n"
".quad 0x202c313572250920,0x70746573090a3b30,0x203233752e656e2e,0x25202c3431702509\n"
".quad 0x31357225202c3172,0x3431702540090a3b,0x4c24092061726220,0x343335325f325f74\n"
".quad 0x636f6c2e090a3b36,0x3009383132093309,0x31752e766f6d090a,0x2c31687225092036\n"
".quad 0x2e64696174632520,0x2e6c756d090a3b78,0x3631752e65646977,0x202c323572250920\n"
".quad 0x3631202c31687225,0x752e766f6d090a3b,0x3335722509203233,0x6c6c61435f64202c\n"
".quad 0x090a3b65756c6156,0x203233752e646461,0x25202c3435722509,0x357225202c323572\n"
".quad 0x732e646c090a3b33,0x36662e6465726168,0x3335646625092034,0x6475635f5f5b202c\n"
".quad 0x616475635f5f5f61,0x765f6c61636f6c5f,0x34333037325f7261,0x75535f735f34335f\n"
".quad 0x3230316c6c61436d,0x0a3b5d302b323334,0x626f6c672e747309,0x09203436662e6c61\n"
".quad 0x5d302b343572255b,0x3b3335646625202c,0x6168732e646c090a,0x203436662e646572\n"
".quad 0x202c343564662509,0x5f616475635f5f5b,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f35333037325f,0x326d75535f735f34,0x343430316c6c6143,0x090a3b5d302b3038\n"
".quad 0x61626f6c672e7473,0x5b09203436662e6c,0x2c5d382b34357225,0x0a3b343564662520\n"
".quad 0x35325f325f744c24,0x6c2e090a3a363433,0x303232093309636f,0x74697865090a3009\n"
".quad 0x6e6557444c240a3b,0x6f4d36315a5f5f64,0x6f6c72614365746e,0x3150656375646552\n"
".quad 0x6974704f545f5f34,0x6965756c61566e6f,0x202f2f207d090a3a,0x746e6f4d36315a5f\n"
".quad 0x65526f6c72614365,0x5f34315065637564,0x6e6f6974704f545f,0x0a0a6965756c6156\n"
".quad 0x207972746e652e09,0x65766e6936315a5f,0x654b444e43657372,0x5f5366506c656e72\n"
".quad 0x702e09090a28206a,0x33752e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x65737265766e6936,0x656e72654b444e43,0x645f6a5f5366506c,0x2c74757074754f5f\n"
".quad 0x617261702e09090a,0x5f203233752e206d,0x726170616475635f,0x6e6936315a5f5f6d\n"
".quad 0x444e436573726576,0x66506c656e72654b,0x6e495f645f6a5f53,0x2e09090a2c747570\n"
".quad 0x752e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x737265766e693631\n"
".quad 0x6e72654b444e4365,0x5f6a5f5366506c65,0x090a294e68746170,0x206765722e090a7b\n"
".quad 0x3c7225203233752e,0x2e090a3b3e393032,0x3233662e20676572,0x3b3e34313c662520\n"
".quad 0x2e206765722e090a,0x3c64662520343666,0x2e090a3b3e393434,0x6572702e20676572\n"
".quad 0x3e33363c70252064,0x09636f6c2e090a3b,0x3009313532093931,0x67656257444c240a\n"
".quad 0x6936315a5f5f6e69,0x4e4365737265766e,0x506c656e72654b44,0x6c090a3a6a5f5366\n"
".quad 0x2e6d617261702e64,0x3172250920323375,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x737265766e693631,0x6e72654b444e4365,0x5f6a5f5366506c65,0x0a3b5d4e68746170\n"
".quad 0x3233752e74766309,0x722509203631752e,0x2e64697425202c32,0x2e747663090a3b78\n"
".quad 0x203631752e323375,0x6325202c33722509,0x0a3b782e64696174,0x3233752e74766309\n"
".quad 0x722509203631752e,0x6469746e25202c34,0x2e646c090a3b782e,0x33752e6d61726170\n"
".quad 0x202c357225092032,0x70616475635f5f5b,0x36315a5f5f6d7261,0x4365737265766e69\n"
".quad 0x6c656e72654b444e,0x5f645f6a5f536650,0x0a3b5d7475706e49,0x3233752e766f6d09\n"
".quad 0x30202c3672250920,0x2e70746573090a3b,0x09203233752e7165,0x357225202c317025\n"
".quad 0x090a3b367225202c,0x6172622031702540,0x5f335f744c240920,0x090a3b3636303635\n"
".quad 0x09393109636f6c2e,0x6d090a3009393532,0x2e6f6c2e34326c75,0x3772250920323375\n"
".quad 0x25202c347225202c,0x646461090a3b3372,0x722509203233752e,0x202c377225202c38\n"
".quad 0x6c2e090a3b327225,0x353209393109636f,0x2e646c090a300931,0x33752e6d61726170\n"
".quad 0x202c317225092032,0x70616475635f5f5b,0x36315a5f5f6d7261,0x4365737265766e69\n"
".quad 0x6c656e72654b444e,0x61705f6a5f536650,0x2e090a3b5d4e6874,0x3209393109636f6c\n"
".quad 0x6573090a30093935,0x33752e65672e7074,0x202c327025092032,0x317225202c387225\n"
".quad 0x2032702540090a3b,0x744c240920617262,0x32323139365f335f,0x752e747663090a3b\n"
".quad 0x09203631752e3233,0x636e25202c397225,0x0a3b782e64696174,0x6c2e34326c756d09\n"
".quad 0x2509203233752e6f,0x347225202c303172,0x090a3b397225202c,0x752e6f6c2e6c756d\n"
".quad 0x3131722509203233,0x34202c387225202c,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x317225202c323172,0x2e090a3b34202c30,0x3209393109636f6c,0x646c090a30093135\n"
".quad 0x752e6d617261702e,0x2c31722509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x65737265766e6936,0x656e72654b444e43,0x705f6a5f5366506c,0x090a3b5d4e687461\n"
".quad 0x09393109636f6c2e,0x6d090a3009393532,0x33752e6f6c2e6c75,0x2c33317225092032\n"
".quad 0x3b34202c31722520,0x3109636f6c2e090a,0x0a30093135320939,0x617261702e646c09\n"
".quad 0x2509203233752e6d,0x635f5f5b202c3572,0x5f6d726170616475,0x65766e6936315a5f\n"
".quad 0x654b444e43657372,0x5f5366506c656e72,0x75706e495f645f6a,0x6f6c2e090a3b5d74\n"
".quad 0x3935320939310963,0x2e646461090a3009,0x3172250920323375,0x2c31317225202c34\n"
".quad 0x61090a3b35722520,0x09203233752e6464,0x7225202c35317225,0x3b357225202c3331\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c36317225,0x726170616475635f\n"
".quad 0x6e6936315a5f5f6d,0x444e436573726576,0x66506c656e72654b,0x754f5f645f6a5f53\n"
".quad 0x090a3b5d74757074,0x203233752e646461,0x25202c3731722509,0x317225202c363172\n"
".quad 0x335f744c240a3b31,0x0a3a34333836355f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x656e202c39353220,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6574616d69747365,0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b\n"
".quad 0x3209393109636f6c,0x646c090a30093036,0x2e6c61626f6c672e,0x3166250920323366\n"
".quad 0x2b343172255b202c,0x747663090a3b5d30,0x3233662e3436662e,0x202c316466250920\n"
".quad 0x6c2e090a3b316625,0x363209393109636f,0x766f6d090a300931,0x662509203436662e\n"
".quad 0x66336430202c3264,0x3030303030303066,0x093b303030303030,0x6573090a31202f2f\n"
".quad 0x3233752e65672e74,0x722509203436662e,0x31646625202c3831,0x0a3b32646625202c\n"
".quad 0x3233732e67656e09,0x202c393172250920,0x6d090a3b38317225,0x09203436662e766f\n"
".quad 0x6430202c33646625,0x3030303030303030,0x3030303030303030,0x090a30202f2f093b\n"
".quad 0x752e656c2e746573,0x09203436662e3233,0x6625202c30327225,0x33646625202c3164\n"
".quad 0x732e67656e090a3b,0x3132722509203233,0x0a3b30327225202c,0x203233622e726f09\n"
".quad 0x25202c3232722509,0x327225202c393172,0x2e766f6d090a3b31,0x3272250920323375\n"
".quad 0x73090a3b30202c33,0x732e71652e707465,0x2c33702509203233,0x25202c3232722520\n"
".quad 0x2540090a3b333272,0x0920617262203370,0x37355f335f744c24,0x2f2f200a3b303930\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338\n"
".quad 0x662509203436662e,0x66666430202c3464,0x3030303030303866,0x093b303030303030\n"
".quad 0x0a6e616e2d202f2f,0x696e752e61726209,0x6e6557444c240920,0x69766964665f6964\n"
".quad 0x315f3031325f6564,0x335f744c240a3b31,0x0a3a30393037355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39353220\n"
".quad 0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f,0x203436662e766f6d\n"
".quad 0x30202c3564662509,0x3030303065666264,0x3030303030303030,0x302d202f2f093b30\n"
".quad 0x2e646461090a352e,0x6466250920343666,0x2c31646625202c36,0x090a3b3564662520\n"
".quad 0x203436662e736261,0x25202c3764662509,0x6f6d090a3b366466,0x2509203436662e76\n"
".quad 0x336430202c386466,0x6137343165616466,0x3b31656137343165,0x32342e30202f2f09\n"
".quad 0x6c2e70746573090a,0x2509203436662e74,0x37646625202c3470,0x0a3b38646625202c\n"
".quad 0x6220347025214009,0x5f744c2409206172,0x3b38353837355f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3935322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33,0x393109636f6c2e09\n"
".quad 0x090a300935323109,0x203436662e6c756d,0x25202c3964662509,0x646625202c366466\n"
".quad 0x2e766f6d090a3b36,0x6466250920343666,0x30346430202c3031,0x6231333964303430\n"
".quad 0x093b643032363832,0x3630352e32202f2f,0x2e766f6d090a3336,0x6466250920343666\n"
".quad 0x30636430202c3131,0x6561303764393233,0x093b656433613435,0x362e38312d202f2f\n"
".quad 0x2e766f6d090a3531,0x6466250920343666,0x30346430202c3231,0x3463323132623434\n"
".quad 0x093b636636633337,0x39332e3134202f2f,0x2e766f6d090a3231,0x6466250920343666\n"
".quad 0x30636430202c3331,0x3735396530373933,0x093b383737373733,0x342e35322d202f2f\n"
".quad 0x64616d090a313134,0x203436662e6e722e,0x202c343164662509,0x25202c3331646625\n"
".quad 0x646625202c396466,0x64616d090a3b3231,0x203436662e6e722e,0x202c353164662509\n"
".quad 0x6625202c39646625,0x646625202c343164,0x64616d090a3b3131,0x203436662e6e722e\n"
".quad 0x202c363164662509,0x6625202c39646625,0x646625202c353164,0x6c756d090a3b3031\n"
".quad 0x662509203436662e,0x646625202c373164,0x3631646625202c36,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x6666336430202c38,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x766f6d090a31202f,0x662509203436662e,0x636430202c393164,0x3030373266303230\n"
".quad 0x3b64323730353536,0x342e382d202f2f09,0x6f6d090a31353337,0x2509203436662e76\n"
".quad 0x6430202c30326466,0x3735353137333034,0x6332303531383139,0x2e3332202f2f093b\n"
".quad 0x6f6d090a34333830,0x2509203436662e76,0x6430202c31326466,0x6665663035333063\n"
".quad 0x6437356531303730,0x31322d202f2f093b,0x6d090a323236302e,0x09203436662e766f\n"
".quad 0x30202c3232646625,0x6662303930303464,0x3461383535303230,0x2e33202f2f093b37\n"
".quad 0x6d090a3338303331,0x36662e6e722e6461,0x3332646625092034,0x2c3232646625202c\n"
".quad 0x25202c3964662520,0x6d090a3b31326466,0x36662e6e722e6461,0x3432646625092034\n"
".quad 0x202c39646625202c,0x25202c3332646625,0x6d090a3b30326466,0x36662e6e722e6461\n"
".quad 0x3532646625092034,0x202c39646625202c,0x25202c3432646625,0x6d090a3b39316466\n"
".quad 0x36662e6e722e6461,0x3632646625092034,0x202c39646625202c,0x25202c3532646625\n"
".quad 0x64090a3b38316466,0x36662e6e722e7669,0x3732646625092034,0x2c3731646625202c\n"
".quad 0x0a3b363264662520,0x696e752e61726209,0x5f335f744c240920,0x240a3b3230363735\n"
".quad 0x3837355f335f744c,0x3c2f2f200a3a3835,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39353220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3836355f335f744c,0x2e766f6d090a3433,0x6466250920343666,0x30306430202c3832\n"
".quad 0x3030303030303030,0x093b303030303030,0x6573090a30202f2f,0x36662e74672e7074\n"
".quad 0x202c357025092034,0x6625202c36646625,0x2140090a3b383264,0x2061726220357025\n"
".quad 0x355f335f744c2409,0x2f200a3b30373338,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3935,0x64656c6562616c20\n"
".quad 0x355f335f744c2420,0x6c2e090a34333836,0x393409313309636f,0x766f6d090a300932\n"
".quad 0x662509203436662e,0x336430202c393264,0x3030303030306666,0x3b30303030303030\n"
".quad 0x73090a31202f2f09,0x09203436662e6275,0x25202c3033646625,0x6625202c39326466\n"
".quad 0x766f6d090a3b3164,0x257b09203436622e,0x353272252c343272,0x3033646625202c7d\n"
".quad 0x732e766f6d090a3b,0x3632722509203233,0x0a3b35327225202c,0x313309636f6c2e09\n"
".quad 0x090a300933393409,0x203436622e766f6d,0x252c373272257b09,0x6625202c7d383272\n"
".quad 0x6c2e090a3b303364,0x393409313309636f,0x766f6d090a300935,0x662509203436662e\n"
".quad 0x306430202c313364,0x3030303030303030,0x3b30303030303030,0x73090a30202f2f09\n"
".quad 0x33752e74672e7465,0x2509203436662e32,0x646625202c393272,0x33646625202c3033\n"
".quad 0x2e67656e090a3b31,0x3372250920323373,0x3b39327225202c30,0x36662e766f6d090a\n"
".quad 0x3233646625092034,0x306666376430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x6573090a666e6920,0x3233752e746c2e74,0x722509203436662e,0x33646625202c3133\n"
".quad 0x3233646625202c30,0x732e67656e090a3b,0x3233722509203233,0x0a3b31337225202c\n"
".quad 0x3233622e646e6109,0x202c333372250920,0x7225202c30337225,0x766f6d090a3b3233\n"
".quad 0x722509203233752e,0x090a3b30202c3433,0x2e71652e70746573,0x3670250920323373\n"
".quad 0x202c33337225202c,0x40090a3b34337225,0x2061726220367025,0x335f335f744c2409\n"
".quad 0x2f200a3b32383639,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3935,0x64656c6562616c20,0x355f335f744c2420\n"
".quad 0x6f6d090a34333836,0x2509203233752e76,0x343031202c353372,0x73090a3b35373538\n"
".quad 0x752e74672e707465,0x2c37702509203233,0x25202c3532722520,0x2540090a3b353372\n"
".quad 0x0920617262203770,0x38355f335f744c24,0x2f2f200a3b323838,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338,0x3130350931330963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x33346430202c3333,0x3030303030303035\n"
".quad 0x093b303030303030,0x3130382e31202f2f,0x090a36312b653434,0x203436662e6c756d\n"
".quad 0x202c343364662509,0x25202c3033646625,0x6d090a3b33336466,0x09203436622e766f\n"
".quad 0x72252c363372257b,0x646625202c7d3632,0x6f6c2e090a3b3433,0x3230350931330963\n"
".quad 0x2e766f6d090a3009,0x72257b0920343662,0x7d373372252c3732,0x3b3433646625202c\n"
".quad 0x33732e766f6d090a,0x2c38337225092032,0x0a3b373730312d20,0x696e752e61726209\n"
".quad 0x5f335f744c240920,0x240a3b3632363835,0x3838355f335f744c,0x3c2f2f200a3a3238\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39353220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c,0x2e766f6d090a3433\n"
".quad 0x3372250920323373,0x333230312d202c38,0x5f335f744c240a3b,0x200a3a3632363835\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c393532,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635\n"
".quad 0x3509313309636f6c,0x6873090a30093730,0x2509203233732e72,0x327225202c393372\n"
".quad 0x090a3b3032202c36,0x203233732e646461,0x25202c3833722509,0x337225202c383372\n"
".quad 0x636f6c2e090a3b39,0x0939303509313309,0x622e646e61090a30,0x3034722509203233\n"
".quad 0x202c36327225202c,0x353334363431322d,0x726f090a3b333730,0x722509203233622e\n"
".quad 0x30347225202c3134,0x393632373031202c,0x6d090a3b38343233,0x09203436622e766f\n"
".quad 0x7b202c3533646625,0x3472252c37327225,0x766f6d090a3b7d31,0x722509203233752e\n"
".quad 0x33373031202c3234,0x0a3b323835373231,0x656c2e7074657309,0x702509203233752e\n"
".quad 0x2c31347225202c38,0x090a3b3234722520,0x6172622038702540,0x5f335f744c240920\n"
".quad 0x200a3b3833313935,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c393532,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3433383635,0x3509313309636f6c,0x6f6d090a30093131,0x7b09203436622e76\n"
".quad 0x3472252c33347225,0x33646625202c7d34,0x2e627573090a3b35,0x3472250920323373\n"
".quad 0x2c34347225202c35,0x3637353834303120,0x622e766f6d090a3b,0x3472257b09203436\n"
".quad 0x2c7d373472252c36,0x0a3b353364662520,0x3436622e766f6d09,0x2c35336466250920\n"
".quad 0x252c363472257b20,0x2e090a3b7d353472,0x3509313309636f6c,0x6461090a30093231\n"
".quad 0x2509203233732e64,0x337225202c383372,0x4c240a3b31202c38,0x333139355f335f74\n"
".quad 0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39353220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x09636f6c2e090a34,0x3009383135093133,0x36662e766f6d090a,0x3633646625092034\n"
".quad 0x306666626430202c,0x3030303030303030,0x2f2f093b30303030,0x646461090a312d20\n"
".quad 0x662509203436662e,0x646625202c373364,0x33646625202c3533,0x2e766f6d090a3b36\n"
".quad 0x6466250920343666,0x66336430202c3833,0x3030303030303066,0x093b303030303030\n"
".quad 0x6461090a31202f2f,0x2509203436662e64,0x6625202c39336466,0x646625202c353364\n"
".quad 0x747663090a3b3833,0x2e3233662e6e722e,0x3266250920343666,0x3b3933646625202c\n"
".quad 0x70612e706372090a,0x3233662e786f7270,0x25202c3366250920,0x747663090a3b3266\n"
".quad 0x3233662e3436662e,0x2c30346466250920,0x6e090a3b33662520,0x09203436662e6765\n"
".quad 0x25202c3134646625,0x6d090a3b39336466,0x09203436662e766f,0x30202c3234646625\n"
".quad 0x3030303066663364,0x3030303030303030,0x0a31202f2f093b30,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x34646625202c3334,0x3034646625202c31,0x3b3234646625202c\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x646625202c343464,0x34646625202c3334\n"
".quad 0x3334646625202c33,0x722e64616d090a3b,0x2509203436662e6e,0x6625202c35346466\n"
".quad 0x646625202c343464,0x34646625202c3034,0x2e6c756d090a3b30,0x6466250920343666\n"
".quad 0x33646625202c3634,0x3534646625202c37,0x09636f6c2e090a3b,0x3009383235093133\n"
".quad 0x36662e646461090a,0x3734646625092034,0x2c3634646625202c,0x0a3b363464662520\n"
".quad 0x3436662e6c756d09,0x2c38346466250920,0x202c373464662520,0x090a3b3734646625\n"
".quad 0x203436662e766f6d,0x202c393464662509,0x3833316265336430,0x6630386561336230\n"
".quad 0x31202f2f093b6531,0x2d6533333632302e,0x2e766f6d090a3630,0x6466250920343666\n"
".quad 0x65336430202c3035,0x6238353265653064,0x093b343062386137,0x3633302e34202f2f\n"
".quad 0x090a36302d653934,0x662e6e722e64616d,0x3564662509203436,0x3934646625202c31\n"
".quad 0x2c3834646625202c,0x0a3b303564662520,0x3436662e766f6d09,0x2c32356466250920\n"
".quad 0x6233666533643020,0x3632306639363632,0x202f2f093b663637,0x6534343837382e31\n"
".quad 0x64616d090a35302d,0x203436662e6e722e,0x202c333564662509,0x25202c3135646625\n"
".quad 0x6625202c38346466,0x6f6d090a3b323564,0x2509203436662e76,0x6430202c34356466\n"
".quad 0x6263353437316633,0x3635393062613961,0x382e38202f2f093b,0x35302d6531383737\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x646625202c353564,0x34646625202c3335\n"
".quad 0x3435646625202c38,0x662e766f6d090a3b,0x3564662509203436,0x3366336430202c36\n"
".quad 0x3164323763313763,0x2f093b3435313562,0x343030302e30202f,0x6d090a3832303433\n"
".quad 0x36662e6e722e6461,0x3735646625092034,0x2c3535646625202c,0x202c383464662520\n"
".quad 0x090a3b3635646625,0x203436662e766f6d,0x202c383564662509,0x3934323666336430\n"
".quad 0x3765623332393432,0x30202f2f093b6432,0x313233323230302e,0x722e64616d090a34\n"
".quad 0x2509203436662e6e,0x6625202c39356466,0x646625202c373564,0x35646625202c3834\n"
".quad 0x2e766f6d090a3b38,0x6466250920343666,0x66336430202c3036,0x3939393939393938\n"
".quad 0x093b346333613939,0x3231302e30202f2f,0x722e64616d090a35,0x2509203436662e6e\n"
".quad 0x6625202c31366466,0x646625202c393564,0x36646625202c3834,0x636f6c2e090a3b30\n"
".quad 0x0939323509313309,0x662e766f6d090a30,0x3664662509203436,0x6266336430202c32\n"
".quad 0x3535353535353535,0x2f093b3435353535,0x333338302e30202f,0x64616d090a333333\n"
".quad 0x203436662e6e722e,0x202c333664662509,0x25202c3136646625,0x6625202c38346466\n"
".quad 0x6c2e090a3b323664,0x333509313309636f,0x627573090a300932,0x662509203436662e\n"
".quad 0x646625202c343664,0x34646625202c3733,0x2e67656e090a3b37,0x6466250920343666\n"
".quad 0x34646625202c3536,0x2e646461090a3b37,0x6466250920343666,0x36646625202c3636\n"
".quad 0x3436646625202c34,0x722e64616d090a3b,0x2509203436662e6e,0x6625202c37366466\n"
".quad 0x646625202c353664,0x36646625202c3733,0x2e6c756d090a3b36,0x6466250920343666\n"
".quad 0x34646625202c3836,0x3736646625202c35,0x09636f6c2e090a3b,0x3009353335093133\n"
".quad 0x36662e6c756d090a,0x3936646625092034,0x2c3834646625202c,0x0a3b333664662520\n"
".quad 0x3436662e6c756d09,0x2c30376466250920,0x202c373464662520,0x090a3b3936646625\n"
".quad 0x662e6e722e747663,0x09203233732e3436,0x25202c3137646625,0x6f6d090a3b383372\n"
".quad 0x2509203436662e76,0x6430202c32376466,0x3234653236656633,0x6665393361666566\n"
".quad 0x362e30202f2f093b,0x6d090a3734313339,0x36662e6e722e6461,0x3337646625092034\n"
".quad 0x2c3137646625202c,0x202c323764662520,0x090a3b3734646625,0x203436662e766f6d\n"
".quad 0x202c343764662509,0x6362613763336430,0x3038393362336539,0x32202f2f093b6633\n"
".quad 0x2d6535303931332e,0x2e646461090a3731,0x6466250920343666,0x37646625202c3537\n"
".quad 0x3836646625202c30,0x732e67656e090a3b,0x3834722509203233,0x0a3b38337225202c\n"
".quad 0x2e6e722e74766309,0x203233732e343666,0x202c363764662509,0x6d090a3b38347225\n"
".quad 0x09203436662e766f,0x30202c3737646625,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3764662509203436\n"
".quad 0x3637646625202c38,0x2c3737646625202c,0x0a3b333764662520,0x3436662e62757309\n"
".quad 0x2c39376466250920,0x202c383764662520,0x090a3b3734646625,0x203436662e627573\n"
".quad 0x202c303864662509,0x25202c3537646625,0x6d090a3b39376466,0x36662e6e722e6461\n"
".quad 0x3138646625092034,0x2c3137646625202c,0x202c343764662520,0x090a3b3038646625\n"
".quad 0x203436662e646461,0x202c323864662509,0x25202c3337646625,0x62090a3b31386466\n"
".quad 0x0920696e752e6172,0x69646e6557444c24,0x7265746e695f5f5f,0x666c61685f6c616e\n"
".quad 0x3b36315f3031325f,0x335f335f744c240a,0x2f200a3a32383639,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3935\n"
".quad 0x64656c6562616c20,0x355f335f744c2420,0x6c2e090a34333836,0x343509313309636f\n"
".quad 0x736261090a300938,0x662509203436662e,0x646625202c333864,0x766f6d090a3b3033\n"
".quad 0x662509203436662e,0x376430202c343864,0x3030303030306666,0x3b30303030303030\n"
".quad 0x0a666e69202f2f09,0x656c2e7074657309,0x702509203436662e,0x3338646625202c39\n"
".quad 0x3b3438646625202c,0x622039702540090a,0x5f744c2409206172,0x3b30353639355f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3935322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33\n"
".quad 0x3436662e64646109,0x2c32386466250920,0x202c303364662520,0x090a3b3033646625\n"
".quad 0x20696e752e617262,0x646e6557444c2409,0x65746e695f5f5f69,0x6c61685f6c616e72\n"
".quad 0x36315f3031325f66,0x5f335f744c240a3b,0x200a3a3035363935,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393532\n"
".quad 0x656c6562616c2064,0x5f335f744c242064,0x6d090a3433383635,0x09203436662e766f\n"
".quad 0x30202c3538646625,0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30\n"
".quad 0x71652e7074657309,0x702509203436662e,0x33646625202c3031,0x3538646625202c30\n"
".quad 0x3170252140090a3b,0x2409206172622030,0x3130365f335f744c,0x3c2f2f200a3b3236\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x39353220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c,0x2e766f6d090a3433\n"
".quad 0x6466250920343666,0x66666430202c3238,0x3030303030303066,0x093b303030303030\n"
".quad 0x0a666e692d202f2f,0x696e752e61726209,0x6e6557444c240920,0x746e695f5f5f6964\n"
".quad 0x61685f6c616e7265,0x315f3031325f666c,0x335f744c240a3b36,0x0a3a32363130365f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f\n"
".quad 0x203436662e766f6d,0x202c363864662509,0x3030306666376430,0x3030303030303030\n"
".quad 0x69202f2f093b3030,0x70746573090a666e,0x203436662e71652e,0x25202c3131702509\n"
".quad 0x6625202c30336466,0x2140090a3b363864,0x6172622031317025,0x5f335f744c240920\n"
".quad 0x200a3b3437363036,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c393532,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x6d090a3433383635,0x09203436662e766f,0x25202c3238646625,0x62090a3b30336466\n"
".quad 0x0920696e752e6172,0x69646e6557444c24,0x7265746e695f5f5f,0x666c61685f6c616e\n"
".quad 0x3b36315f3031325f,0x365f335f744c240a,0x2f200a3a34373630,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3935\n"
".quad 0x64656c6562616c20,0x355f335f744c2420,0x6f6d090a34333836,0x2509203436662e76\n"
".quad 0x6430202c32386466,0x3030303038666666,0x3030303030303030,0x616e2d202f2f093b\n"
".quad 0x6e6557444c240a6e,0x746e695f5f5f6964,0x61685f6c616e7265,0x315f3031325f666c\n"
".quad 0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39353220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x09636f6c2e090a34,0x3009323934093133,0x36662e67656e090a,0x3738646625092034\n"
".quad 0x3b3238646625202c,0x36622e766f6d090a,0x393472257b092034,0x202c7d303572252c\n"
".quad 0x090a3b3738646625,0x203233732e766f6d,0x25202c3632722509,0x6c2e090a3b303572\n"
".quad 0x393409313309636f,0x766f6d090a300933,0x257b09203436622e,0x313572252c373272\n"
".quad 0x3738646625202c7d,0x09636f6c2e090a3b,0x3009353934093133,0x36662e766f6d090a\n"
".quad 0x3838646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e746573090a3020,0x662e3233752e7467,0x3235722509203436,0x2c3738646625202c\n"
".quad 0x0a3b383864662520,0x3233732e67656e09,0x202c333572250920,0x6d090a3b32357225\n"
".quad 0x09203436662e766f,0x30202c3938646625,0x3030303066663764,0x3030303030303030\n"
".quad 0x6e69202f2f093b30,0x6c2e746573090a66,0x36662e3233752e74,0x2c34357225092034\n"
".quad 0x202c373864662520,0x090a3b3938646625,0x203233732e67656e,0x25202c3535722509\n"
".quad 0x6e61090a3b343572,0x2509203233622e64,0x357225202c363572,0x3b35357225202c33\n"
".quad 0x33752e766f6d090a,0x2c37357225092032,0x746573090a3b3020,0x3233732e71652e70\n"
".quad 0x202c323170250920,0x7225202c36357225,0x702540090a3b3735,0x0920617262203231\n"
".quad 0x31345f335f744c24,0x2f2f200a3b383132,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x766f6d090a343338,0x722509203233752e,0x38343031202c3835\n"
".quad 0x6573090a3b353735,0x33752e74672e7074,0x2c33317025092032,0x25202c3035722520\n"
".quad 0x2540090a3b383572,0x2061726220333170,0x365f335f744c2409,0x2f200a3b32343431\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3935,0x64656c6562616c20,0x355f335f744c2420,0x6c2e090a34333836\n"
".quad 0x303509313309636f,0x766f6d090a300931,0x662509203436662e,0x346430202c303964\n"
".quad 0x3030303030303533,0x3b30303030303030,0x30382e31202f2f09,0x0a36312b65343431\n"
".quad 0x3436662e6c756d09,0x2c31396466250920,0x202c373864662520,0x090a3b3039646625\n"
".quad 0x203436622e766f6d,0x252c393572257b09,0x6625202c7d363272,0x6c2e090a3b313964\n"
".quad 0x303509313309636f,0x766f6d090a300932,0x257b09203436622e,0x303672252c373272\n"
".quad 0x3139646625202c7d,0x732e766f6d090a3b,0x3833722509203233,0x3b373730312d202c\n"
".quad 0x6e752e617262090a,0x335f744c24092069,0x0a3b36383131365f,0x31365f335f744c24\n"
".quad 0x2f2f200a3a323434,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x766f6d090a343338,0x722509203233732e,0x3230312d202c3833,0x335f744c240a3b33\n"
".quad 0x0a3a36383131365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x09313309636f6c2e,0x73090a3009373035,0x09203233732e7268\n"
".quad 0x7225202c31367225,0x0a3b3032202c3632,0x3233732e64646109,0x202c383372250920\n"
".quad 0x7225202c38337225,0x6f6c2e090a3b3136,0x3930350931330963,0x2e646e61090a3009\n"
".quad 0x3472250920323362,0x2c36327225202c30,0x3334363431322d20,0x6f090a3b33373035\n"
".quad 0x2509203233622e72,0x347225202c313472,0x3632373031202c30,0x090a3b3834323339\n"
".quad 0x203436622e766f6d,0x202c353364662509,0x72252c373272257b,0x6f6d090a3b7d3134\n"
".quad 0x2509203233752e76,0x373031202c323672,0x3b32383537323133,0x6c2e70746573090a\n"
".quad 0x2509203233752e65,0x347225202c343170,0x3b32367225202c31,0x203431702540090a\n"
".quad 0x744c240920617262,0x38393631365f335f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a,0x0a30093131350931\n"
".quad 0x3436622e766f6d09,0x2c333672257b0920,0x25202c7d34367225,0x73090a3b35336466\n"
".quad 0x09203233732e6275,0x7225202c35367225,0x38343031202c3436,0x6f6d090a3b363735\n"
".quad 0x7b09203436622e76,0x3672252c36367225,0x33646625202c7d37,0x2e766f6d090a3b35\n"
".quad 0x6466250920343662,0x3672257b202c3533,0x3b7d353672252c36,0x3309636f6c2e090a\n"
".quad 0x0a30093231350931,0x3233732e64646109,0x202c383372250920,0x3b31202c38337225\n"
".quad 0x365f335f744c240a,0x2f200a3a38393631,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3935,0x64656c6562616c20\n"
".quad 0x355f335f744c2420,0x6c2e090a34333836,0x313509313309636f,0x766f6d090a300938\n"
".quad 0x662509203436662e,0x626430202c323964,0x3030303030306666,0x3b30303030303030\n"
".quad 0x090a312d202f2f09,0x203436662e646461,0x202c373364662509,0x25202c3533646625\n"
".quad 0x6d090a3b32396466,0x09203436662e766f,0x30202c3339646625,0x3030303066663364\n"
".quad 0x3030303030303030,0x0a31202f2f093b30,0x3436662e64646109,0x2c39336466250920\n"
".quad 0x202c353364662520,0x090a3b3339646625,0x662e6e722e747663,0x09203436662e3233\n"
".quad 0x646625202c326625,0x706372090a3b3933,0x2e786f727070612e,0x3466250920323366\n"
".quad 0x090a3b326625202c,0x2e3436662e747663,0x6466250920323366,0x3b346625202c3034\n"
".quad 0x36662e67656e090a,0x3439646625092034,0x3b3933646625202c,0x36662e766f6d090a\n"
".quad 0x3539646625092034,0x306666336430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e64616d090a3120,0x09203436662e6e72,0x25202c3334646625,0x6625202c34396466\n"
".quad 0x646625202c303464,0x64616d090a3b3539,0x203436662e6e722e,0x202c343464662509\n"
".quad 0x25202c3334646625,0x6625202c33346466,0x616d090a3b333464,0x3436662e6e722e64\n"
".quad 0x2c35346466250920,0x202c343464662520,0x25202c3034646625,0x6d090a3b30346466\n"
".quad 0x09203436662e6c75,0x25202c3634646625,0x6625202c37336466,0x6c2e090a3b353464\n"
".quad 0x323509313309636f,0x646461090a300938,0x662509203436662e,0x646625202c373464\n"
".quad 0x34646625202c3634,0x2e6c756d090a3b36,0x6466250920343666,0x34646625202c3834\n"
".quad 0x3734646625202c37,0x662e766f6d090a3b,0x3964662509203436,0x6265336430202c36\n"
".quad 0x6561336230383331,0x2f093b6531663038,0x333632302e31202f,0x6d090a36302d6533\n"
".quad 0x09203436662e766f,0x30202c3739646625,0x3265653064653364,0x3062386137623835\n"
".quad 0x2e34202f2f093b34,0x302d653934363330,0x722e64616d090a36,0x2509203436662e6e\n"
".quad 0x6625202c38396466,0x646625202c363964,0x39646625202c3834,0x2e766f6d090a3b37\n"
".quad 0x6466250920343666,0x65336430202c3939,0x6639363632623366,0x093b663637363230\n"
".quad 0x3837382e31202f2f,0x090a35302d653434,0x662e6e722e64616d,0x3164662509203436\n"
".quad 0x39646625202c3030,0x3834646625202c38,0x3b3939646625202c,0x36662e766f6d090a\n"
".quad 0x3031646625092034,0x3166336430202c31,0x6139616263353437,0x2f093b3635393062\n"
".quad 0x383737382e38202f,0x6d090a35302d6531,0x36662e6e722e6461,0x3031646625092034\n"
".quad 0x3031646625202c32,0x3834646625202c30,0x313031646625202c,0x662e766f6d090a3b\n"
".quad 0x3164662509203436,0x66336430202c3330,0x6432376331376333,0x093b343531356231\n"
".quad 0x3030302e30202f2f,0x090a383230343334,0x662e6e722e64616d,0x3164662509203436\n"
".quad 0x31646625202c3430,0x34646625202c3230,0x3031646625202c38,0x2e766f6d090a3b33\n"
".quad 0x6466250920343666,0x336430202c353031,0x3934323934323666,0x3b64323765623332\n"
".quad 0x30302e30202f2f09,0x090a343132333232,0x662e6e722e64616d,0x3164662509203436\n"
".quad 0x31646625202c3630,0x34646625202c3430,0x3031646625202c38,0x2e766f6d090a3b35\n"
".quad 0x6466250920343666,0x336430202c373031,0x3939393939393866,0x3b34633361393939\n"
".quad 0x31302e30202f2f09,0x2e64616d090a3532,0x09203436662e6e72,0x202c383031646625\n"
".quad 0x202c363031646625,0x25202c3834646625,0x090a3b3730316466,0x09313309636f6c2e\n"
".quad 0x6d090a3009393235,0x09203436662e766f,0x202c393031646625,0x3535356266336430\n"
".quad 0x3535353535353535,0x30202f2f093b3435,0x333333333338302e,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x6625202c30313164,0x6625202c38303164,0x646625202c383464\n"
".quad 0x6c2e090a3b393031,0x333509313309636f,0x627573090a300932,0x662509203436662e\n"
".quad 0x646625202c343664,0x34646625202c3733,0x2e67656e090a3b37,0x6466250920343666\n"
".quad 0x646625202c313131,0x646461090a3b3734,0x662509203436662e,0x6625202c32313164\n"
".quad 0x646625202c343664,0x64616d090a3b3436,0x203436662e6e722e,0x2c33313164662509\n"
".quad 0x2c31313164662520,0x202c373364662520,0x0a3b323131646625,0x3436662e6c756d09\n"
".quad 0x2c38366466250920,0x202c353464662520,0x0a3b333131646625,0x313309636f6c2e09\n"
".quad 0x090a300935333509,0x203436662e6c756d,0x2c34313164662509,0x202c383464662520\n"
".quad 0x0a3b303131646625,0x3436662e6c756d09,0x2c30376466250920,0x202c373464662520\n"
".quad 0x0a3b343131646625,0x2e6e722e74766309,0x203233732e343666,0x202c313764662509\n"
".quad 0x6d090a3b38337225,0x09203436662e766f,0x202c353131646625,0x6532366566336430\n"
".quad 0x3933616665663234,0x30202f2f093b6665,0x0a3734313339362e,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x37646625202c3337,0x3131646625202c31,0x3734646625202c35\n"
".quad 0x662e766f6d090a3b,0x3164662509203436,0x63336430202c3631,0x6233653963626137\n"
".quad 0x093b663330383933,0x3931332e32202f2f,0x090a37312d653530,0x203436662e646461\n"
".quad 0x2c37313164662509,0x202c303764662520,0x090a3b3836646625,0x203233732e67656e\n"
".quad 0x25202c3836722509,0x7663090a3b383372,0x3436662e6e722e74,0x662509203233732e\n"
".quad 0x7225202c38313164,0x766f6d090a3b3836,0x662509203436662e,0x6430202c39313164\n"
".quad 0x3234653236656633,0x6665393361666566,0x362e30202f2f093b,0x6d090a3734313339\n"
".quad 0x36662e6e722e6461,0x3231646625092034,0x3131646625202c30,0x3131646625202c38\n"
".quad 0x3337646625202c39,0x662e627573090a3b,0x3164662509203436,0x31646625202c3132\n"
".quad 0x34646625202c3032,0x2e627573090a3b37,0x6466250920343666,0x646625202c323231\n"
".quad 0x646625202c373131,0x616d090a3b313231,0x3436662e6e722e64,0x3332316466250920\n"
".quad 0x2c3137646625202c,0x2c36313164662520,0x3b32323164662520,0x36662e646461090a\n"
".quad 0x3231646625092034,0x3337646625202c34,0x333231646625202c,0x752e617262090a3b\n"
".quad 0x57444c240920696e,0x695f5f5f69646e65,0x5f6c616e7265746e,0x3031325f666c6168\n"
".quad 0x744c240a3b38315f,0x38313231345f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a,0x0a30093834350931\n"
".quad 0x3436662e73626109,0x3532316466250920,0x3b3238646625202c,0x36662e766f6d090a\n"
".quad 0x3231646625092034,0x6666376430202c36,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x73090a666e69202f,0x662e656c2e707465,0x3531702509203436,0x353231646625202c\n"
".quad 0x363231646625202c,0x3531702540090a3b,0x4c24092061726220,0x313232365f335f74\n"
".quad 0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39353220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x662e646461090a34,0x3164662509203436,0x38646625202c3732,0x3238646625202c32\n"
".quad 0x662e67656e090a3b,0x3164662509203436,0x31646625202c3432,0x617262090a3b3732\n"
".quad 0x4c240920696e752e,0x5f5f69646e655744,0x616e7265746e695f,0x325f666c61685f6c\n"
".quad 0x240a3b38315f3031,0x3232365f335f744c,0x3c2f2f200a3a3031,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x39353220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3836355f335f744c,0x2e766f6d090a3433,0x6466250920343666\n"
".quad 0x306430202c383231,0x3030303030303030,0x3b30303030303030,0x73090a30202f2f09\n"
".quad 0x662e71652e707465,0x3631702509203436,0x2c3738646625202c,0x3b38323164662520\n"
".quad 0x363170252140090a,0x4c24092061726220,0x323732365f335f74,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39353220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333836355f335f74,0x662e766f6d090a34\n"
".quad 0x3164662509203436,0x66666430202c3432,0x3030303030303066,0x093b303030303030\n"
".quad 0x0a666e692d202f2f,0x696e752e61726209,0x6e6557444c240920,0x746e695f5f5f6964\n"
".quad 0x61685f6c616e7265,0x315f3031325f666c,0x335f744c240a3b38,0x0a3a32323732365f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f\n"
".quad 0x203436662e766f6d,0x2c39323164662509,0x3030666637643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x746573090a666e69,0x3436662e71652e70,0x202c373170250920\n"
".quad 0x25202c3738646625,0x090a3b3932316466,0x6220373170252140,0x5f744c2409206172\n"
".quad 0x3b34333233365f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3935322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x3436662e766f6d09,0x3432316466250920,0x3b3738646625202c\n"
".quad 0x6e752e617262090a,0x6557444c24092069,0x6e695f5f5f69646e,0x685f6c616e726574\n"
".quad 0x5f3031325f666c61,0x5f744c240a3b3831,0x3a34333233365f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3935322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33,0x3436662e766f6d09\n"
".quad 0x3432316466250920,0x386666666430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x4c240a6e616e2d20,0x5f5f69646e655744,0x616e7265746e695f,0x325f666c61685f6c\n"
".quad 0x200a3a38315f3031,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c393532,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3433383635,0x3109393109636f6c,0x6f6d090a30093832,0x2509203436662e76\n"
".quad 0x6625202c37326466,0x62090a3b34323164,0x0920696e752e6172,0x38355f335f744c24\n"
".quad 0x744c240a3b343131,0x30373338355f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a,0x0a30093239340931\n"
".quad 0x3436622e766f6d09,0x2c393672257b0920,0x25202c7d30377225,0x6f6d090a3b316466\n"
".quad 0x2509203233732e76,0x377225202c363272,0x636f6c2e090a3b30,0x0933393409313309\n"
".quad 0x622e766f6d090a30,0x3272257b09203436,0x2c7d313772252c37,0x090a3b3164662520\n"
".quad 0x09313309636f6c2e,0x6d090a3009353934,0x09203436662e766f,0x202c303331646625\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x74672e746573090a\n"
".quad 0x3436662e3233752e,0x202c323772250920,0x6625202c31646625,0x6e090a3b30333164\n"
".quad 0x09203233732e6765,0x7225202c33377225,0x766f6d090a3b3237,0x662509203436662e\n"
".quad 0x6430202c31333164,0x3030303030666637,0x3030303030303030,0x666e69202f2f093b\n"
".quad 0x746c2e746573090a,0x3436662e3233752e,0x202c343772250920,0x6625202c31646625\n"
".quad 0x6e090a3b31333164,0x09203233732e6765,0x7225202c35377225,0x646e61090a3b3437\n"
".quad 0x722509203233622e,0x33377225202c3637,0x0a3b35377225202c,0x3233752e766f6d09\n"
".quad 0x202c373772250920,0x70746573090a3b30,0x203233732e71652e,0x25202c3831702509\n"
".quad 0x377225202c363772,0x31702540090a3b37,0x2409206172622038,0x3732345f335f744c\n"
".quad 0x3c2f2f200a3b3435,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39353220656e696c,0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c\n"
".quad 0x2e766f6d090a3433,0x3772250920323375,0x3538343031202c38,0x746573090a3b3537\n"
".quad 0x3233752e74672e70,0x202c393170250920,0x7225202c30377225,0x702540090a3b3837\n"
".quad 0x0920617262203931,0x34365f335f744c24,0x2f2f200a3b323030,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338,0x3130350931330963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x346430202c323331,0x3030303030303533\n"
".quad 0x3b30303030303030,0x30382e31202f2f09,0x0a36312b65343431,0x3436662e6c756d09\n"
".quad 0x3333316466250920,0x202c31646625202c,0x0a3b323331646625,0x3436622e766f6d09\n"
".quad 0x2c393772257b0920,0x25202c7d36327225,0x090a3b3333316466,0x09313309636f6c2e\n"
".quad 0x6d090a3009323035,0x09203436622e766f,0x72252c373272257b,0x646625202c7d3038\n"
".quad 0x6f6d090a3b333331,0x2509203233732e76,0x30312d202c383372,0x617262090a3b3737\n"
".quad 0x4c240920696e752e,0x343733365f335f74,0x335f744c240a3b36,0x0a3a32303034365f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465,0x090a34333836355f\n"
".quad 0x203233732e766f6d,0x2d202c3833722509,0x4c240a3b33323031,0x343733365f335f74\n"
".quad 0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c39353220656e69,0x616c206461656820,0x4c242064656c6562,0x333836355f335f74\n"
".quad 0x09636f6c2e090a34,0x3009373035093133,0x33732e726873090a,0x2c31387225092032\n"
".quad 0x32202c3632722520,0x2e646461090a3b30,0x3372250920323373,0x2c38337225202c38\n"
".quad 0x090a3b3138722520,0x09313309636f6c2e,0x61090a3009393035,0x09203233622e646e\n"
".quad 0x7225202c30347225,0x3431322d202c3632,0x3b33373035333436,0x3233622e726f090a\n"
".quad 0x202c313472250920,0x3031202c30347225,0x3834323339363237,0x622e766f6d090a3b\n"
".quad 0x3364662509203436,0x373272257b202c35,0x0a3b7d313472252c,0x3233752e766f6d09\n"
".quad 0x202c323872250920,0x3537323133373031,0x746573090a3b3238,0x3233752e656c2e70\n"
".quad 0x202c303270250920,0x7225202c31347225,0x702540090a3b3238,0x0920617262203032\n"
".quad 0x34365f335f744c24,0x2f2f200a3b383532,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x6f6c2e090a343338,0x3131350931330963,0x2e766f6d090a3009\n"
".quad 0x72257b0920343662,0x7d343872252c3338,0x3b3533646625202c,0x33732e627573090a\n"
".quad 0x2c35387225092032,0x31202c3438722520,0x0a3b363735383430,0x3436622e766f6d09\n"
".quad 0x2c363872257b0920,0x25202c7d37387225,0x6d090a3b35336466,0x09203436622e766f\n"
".quad 0x7b202c3533646625,0x3872252c36387225,0x6f6c2e090a3b7d35,0x3231350931330963\n"
".quad 0x2e646461090a3009,0x3372250920323373,0x2c38337225202c38,0x5f744c240a3b3120\n"
".quad 0x3a38353234365f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3935322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333836355f33,0x313309636f6c2e09,0x090a300938313509,0x203436662e766f6d\n"
".quad 0x2c34333164662509,0x3030666662643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x2e646461090a312d,0x6466250920343666,0x33646625202c3733,0x3331646625202c35\n"
".quad 0x2e766f6d090a3b34,0x6466250920343666,0x336430202c353331,0x3030303030306666\n"
".quad 0x3b30303030303030,0x61090a31202f2f09,0x09203436662e6464,0x25202c3933646625\n"
".quad 0x6625202c35336466,0x63090a3b35333164,0x33662e6e722e7476,0x2509203436662e32\n"
".quad 0x33646625202c3266,0x2e706372090a3b39,0x662e786f72707061,0x2c35662509203233\n"
".quad 0x63090a3b32662520,0x662e3436662e7476,0x3464662509203233,0x0a3b356625202c30\n"
".quad 0x3436662e67656e09,0x3633316466250920,0x3b3933646625202c,0x36662e766f6d090a\n"
".quad 0x3331646625092034,0x6666336430202c37,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x64616d090a31202f,0x203436662e6e722e,0x202c333464662509,0x202c363331646625\n"
".quad 0x25202c3034646625,0x090a3b3733316466,0x662e6e722e64616d,0x3464662509203436\n"
".quad 0x3334646625202c34,0x2c3334646625202c,0x0a3b333464662520,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x34646625202c3534,0x3034646625202c34,0x3b3034646625202c\n"
".quad 0x36662e6c756d090a,0x3634646625092034,0x2c3733646625202c,0x0a3b353464662520\n"
".quad 0x313309636f6c2e09,0x090a300938323509,0x203436662e646461,0x202c373464662509\n"
".quad 0x25202c3634646625,0x6d090a3b36346466,0x09203436662e6c75,0x25202c3834646625\n"
".quad 0x6625202c37346466,0x6f6d090a3b373464,0x2509203436662e76,0x30202c3833316466\n"
".quad 0x3038333162653364,0x3166303865613362,0x2e31202f2f093b65,0x302d653333363230\n"
".quad 0x662e766f6d090a36,0x3164662509203436,0x65336430202c3933,0x6238353265653064\n"
".quad 0x093b343062386137,0x3633302e34202f2f,0x090a36302d653934,0x662e6e722e64616d\n"
".quad 0x3164662509203436,0x31646625202c3034,0x34646625202c3833,0x3331646625202c38\n"
".quad 0x2e766f6d090a3b39,0x6466250920343666,0x336430202c313431,0x3936363262336665\n"
".quad 0x3b66363736323066,0x37382e31202f2f09,0x0a35302d65343438,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x646625202c323431,0x646625202c303431,0x31646625202c3834\n"
".quad 0x766f6d090a3b3134,0x662509203436662e,0x6430202c33343164,0x6263353437316633\n"
".quad 0x3635393062613961,0x382e38202f2f093b,0x35302d6531383737,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x6625202c34343164,0x6625202c32343164,0x646625202c383464\n"
".quad 0x6f6d090a3b333431,0x2509203436662e76,0x30202c3534316466,0x6331376333663364\n"
".quad 0x3531356231643237,0x2e30202f2f093b34,0x3230343334303030,0x722e64616d090a38\n"
".quad 0x2509203436662e6e,0x25202c3634316466,0x25202c3434316466,0x6625202c38346466\n"
".quad 0x6d090a3b35343164,0x09203436662e766f,0x202c373431646625,0x3934323666336430\n"
".quad 0x3765623332393432,0x30202f2f093b6432,0x313233323230302e,0x722e64616d090a34\n"
".quad 0x2509203436662e6e,0x25202c3834316466,0x25202c3634316466,0x6625202c38346466\n"
".quad 0x6d090a3b37343164,0x09203436662e766f,0x202c393431646625,0x3939393866336430\n"
".quad 0x3361393939393939,0x30202f2f093b3463,0x6d090a353231302e,0x36662e6e722e6461\n"
".quad 0x3531646625092034,0x3431646625202c30,0x3834646625202c38,0x393431646625202c\n"
".quad 0x09636f6c2e090a3b,0x3009393235093133,0x36662e766f6d090a,0x3531646625092034\n"
".quad 0x6266336430202c31,0x3535353535353535,0x2f093b3435353535,0x333338302e30202f\n"
".quad 0x64616d090a333333,0x203436662e6e722e,0x2c32353164662509,0x2c30353164662520\n"
".quad 0x202c383464662520,0x0a3b313531646625,0x313309636f6c2e09,0x090a300932333509\n"
".quad 0x203436662e627573,0x202c343664662509,0x25202c3733646625,0x6e090a3b37346466\n"
".quad 0x09203436662e6765,0x202c333531646625,0x090a3b3734646625,0x203436662e646461\n"
".quad 0x2c34353164662509,0x202c343664662520,0x090a3b3436646625,0x662e6e722e64616d\n"
".quad 0x3164662509203436,0x31646625202c3535,0x33646625202c3335,0x3531646625202c37\n"
".quad 0x2e6c756d090a3b34,0x6466250920343666,0x34646625202c3836,0x3531646625202c35\n"
".quad 0x636f6c2e090a3b35,0x0935333509313309,0x662e6c756d090a30,0x3164662509203436\n"
".quad 0x34646625202c3635,0x3531646625202c38,0x2e6c756d090a3b32,0x6466250920343666\n"
".quad 0x34646625202c3037,0x3531646625202c37,0x2e747663090a3b36,0x732e3436662e6e72\n"
".quad 0x3764662509203233,0x3b38337225202c31,0x36662e766f6d090a,0x3531646625092034\n"
".quad 0x6566336430202c37,0x6665663234653236,0x2f093b6665393361,0x313339362e30202f\n"
".quad 0x2e64616d090a3734,0x09203436662e6e72,0x25202c3337646625,0x6625202c31376466\n"
".quad 0x6625202c37353164,0x6f6d090a3b373464,0x2509203436662e76,0x30202c3835316466\n"
".quad 0x3963626137633364,0x3330383933623365,0x2e32202f2f093b66,0x312d653530393133\n"
".quad 0x662e646461090a37,0x3164662509203436,0x37646625202c3935,0x3836646625202c30\n"
".quad 0x732e67656e090a3b,0x3838722509203233,0x0a3b38337225202c,0x2e6e722e74766309\n"
".quad 0x203233732e343666,0x2c30363164662509,0x090a3b3838722520,0x203436662e766f6d\n"
".quad 0x2c31363164662509,0x3236656633643020,0x3361666566323465,0x202f2f093b666539\n"
".quad 0x3734313339362e30,0x6e722e64616d090a,0x662509203436662e,0x6625202c32363164\n"
".quad 0x6625202c30363164,0x6625202c31363164,0x7573090a3b333764,0x2509203436662e62\n"
".quad 0x25202c3336316466,0x25202c3236316466,0x73090a3b37346466,0x09203436662e6275\n"
".quad 0x202c343631646625,0x202c393531646625,0x0a3b333631646625,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x646625202c353631,0x31646625202c3137,0x31646625202c3835\n"
".quad 0x646461090a3b3436,0x662509203436662e,0x6625202c36363164,0x646625202c333764\n"
".quad 0x7262090a3b353631,0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f\n"
".quad 0x5f666c61685f6c61,0x0a3b32315f303132,0x32345f335f744c24,0x2f2f200a3a343537\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24,0x6f6c2e090a343338\n"
".quad 0x3834350931330963,0x2e736261090a3009,0x6466250920343666,0x646625202c373631\n"
".quad 0x2e766f6d090a3b31,0x6466250920343666,0x376430202c383631,0x3030303030306666\n"
".quad 0x3b30303030303030,0x0a666e69202f2f09,0x656c2e7074657309,0x702509203436662e\n"
".quad 0x31646625202c3132,0x31646625202c3736,0x702540090a3b3836,0x0920617262203132\n"
".quad 0x34365f335f744c24,0x2f2f200a3b303737,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x646461090a343338,0x662509203436662e,0x6625202c36363164\n"
".quad 0x31646625202c3164,0x752e617262090a3b,0x57444c240920696e,0x695f5f5f69646e65\n"
".quad 0x5f6c616e7265746e,0x3031325f666c6168,0x744c240a3b32315f,0x30373734365f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39353220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x36662e766f6d090a,0x3631646625092034,0x3030306430202c39,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x746573090a30202f,0x3436662e71652e70,0x202c323270250920\n"
".quad 0x6625202c31646625,0x40090a3b39363164,0x7262203232702521,0x335f744c24092061\n"
".quad 0x0a3b32383235365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x203436662e766f6d,0x2c36363164662509,0x3030666666643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x7262090a666e692d,0x240920696e752e61\n"
".quad 0x5f69646e6557444c,0x6e7265746e695f5f,0x5f666c61685f6c61,0x0a3b32315f303132\n"
".quad 0x35365f335f744c24,0x2f2f200a3a323832,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x36355f335f744c24,0x766f6d090a343338,0x662509203436662e,0x6430202c30373164\n"
".quad 0x3030303030666637,0x3030303030303030,0x666e69202f2f093b,0x652e70746573090a\n"
".quad 0x2509203436662e71,0x646625202c333270,0x3731646625202c31,0x70252140090a3b30\n"
".quad 0x0920617262203332,0x35365f335f744c24,0x2f2f200a3b343937,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338,0x662509203436662e\n"
".quad 0x6625202c36363164,0x617262090a3b3164,0x4c240920696e752e,0x5f5f69646e655744\n"
".quad 0x616e7265746e695f,0x325f666c61685f6c,0x240a3b32315f3031,0x3735365f335f744c\n"
".quad 0x3c2f2f200a3a3439,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39353220656e696c,0x6c2064616568202c,0x242064656c656261,0x3836355f335f744c\n"
".quad 0x2e766f6d090a3433,0x6466250920343666,0x666430202c363631,0x3030303030386666\n"
".quad 0x3b30303030303030,0x6e616e2d202f2f09,0x646e6557444c240a,0x65746e695f5f5f69\n"
".quad 0x6c61685f6c616e72,0x32315f3031325f66,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c39353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a,0x0a30093239340931\n"
".quad 0x3436662e67656e09,0x3137316466250920,0x363631646625202c,0x622e766f6d090a3b\n"
".quad 0x3872257b09203436,0x2c7d303972252c39,0x3b31373164662520,0x33732e766f6d090a\n"
".quad 0x2c36327225092032,0x090a3b3039722520,0x09313309636f6c2e,0x6d090a3009333934\n"
".quad 0x09203436622e766f,0x72252c373272257b,0x646625202c7d3139,0x6c2e090a3b313731\n"
".quad 0x393409313309636f,0x766f6d090a300935,0x662509203436662e,0x6430202c32373164\n"
".quad 0x3030303030303030,0x3030303030303030,0x090a30202f2f093b,0x752e74672e746573\n"
".quad 0x09203436662e3233,0x6625202c32397225,0x6625202c31373164,0x6e090a3b32373164\n"
".quad 0x09203233732e6765,0x7225202c33397225,0x766f6d090a3b3239,0x662509203436662e\n"
".quad 0x6430202c33373164,0x3030303030666637,0x3030303030303030,0x666e69202f2f093b\n"
".quad 0x746c2e746573090a,0x3436662e3233752e,0x202c343972250920,0x202c313731646625\n"
".quad 0x0a3b333731646625,0x3233732e67656e09,0x202c353972250920,0x61090a3b34397225\n"
".quad 0x09203233622e646e,0x7225202c36397225,0x35397225202c3339,0x752e766f6d090a3b\n"
".quad 0x3739722509203233,0x6573090a3b30202c,0x33732e71652e7074,0x2c34327025092032\n"
".quad 0x25202c3639722520,0x2540090a3b373972,0x2061726220343270,0x345f335f744c2409\n"
".quad 0x2f200a3b30393234,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3935,0x64656c6562616c20,0x355f335f744c2420\n"
".quad 0x6f6d090a34333836,0x2509203233752e76,0x343031202c383972,0x73090a3b35373538\n"
".quad 0x752e74672e707465,0x3532702509203233,0x202c30397225202c,0x40090a3b38397225\n"
".quad 0x6172622035327025,0x5f335f744c240920,0x200a3b3236353636,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c393532\n"
".quad 0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635,0x3509313309636f6c\n"
".quad 0x6f6d090a30093130,0x2509203436662e76,0x30202c3437316466,0x3030303035333464\n"
".quad 0x3030303030303030,0x2e31202f2f093b30,0x312b653434313038,0x662e6c756d090a36\n"
".quad 0x3164662509203436,0x31646625202c3537,0x31646625202c3137,0x766f6d090a3b3437\n"
".quad 0x257b09203436622e,0x363272252c393972,0x3731646625202c7d,0x636f6c2e090a3b35\n"
".quad 0x0932303509313309,0x622e766f6d090a30,0x3272257b09203436,0x7d30303172252c37\n"
".quad 0x353731646625202c,0x732e766f6d090a3b,0x3833722509203233,0x3b373730312d202c\n"
".quad 0x6e752e617262090a,0x335f744c24092069,0x0a3b36303336365f,0x36365f335f744c24\n"
".quad 0x2f2f200a3a323635,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24\n"
".quad 0x766f6d090a343338,0x722509203233732e,0x3230312d202c3833,0x335f744c240a3b33\n"
".quad 0x0a3a36303336365f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x09313309636f6c2e,0x73090a3009373035,0x09203233732e7268\n"
".quad 0x25202c3130317225,0x3b3032202c363272,0x33732e646461090a,0x2c38337225092032\n"
".quad 0x25202c3833722520,0x2e090a3b31303172,0x3509313309636f6c,0x6e61090a30093930\n"
".quad 0x2509203233622e64,0x327225202c303472,0x363431322d202c36,0x0a3b333730353334\n"
".quad 0x203233622e726f09,0x25202c3134722509,0x373031202c303472,0x3b38343233393632\n"
".quad 0x36622e766f6d090a,0x3533646625092034,0x2c373272257b202c,0x090a3b7d31347225\n"
".quad 0x203233752e766f6d,0x202c323031722509,0x3537323133373031,0x746573090a3b3238\n"
".quad 0x3233752e656c2e70,0x202c363270250920,0x7225202c31347225,0x2540090a3b323031\n"
".quad 0x2061726220363270,0x365f335f744c2409,0x2f200a3b38313836,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3935\n"
".quad 0x64656c6562616c20,0x355f335f744c2420,0x6c2e090a34333836,0x313509313309636f\n"
".quad 0x766f6d090a300931,0x257b09203436622e,0x3172252c33303172,0x646625202c7d3430\n"
".quad 0x627573090a3b3533,0x722509203233732e,0x317225202c353031,0x38343031202c3430\n"
".quad 0x6f6d090a3b363735,0x7b09203436622e76,0x72252c3630317225,0x6625202c7d373031\n"
".quad 0x6f6d090a3b353364,0x2509203436622e76,0x257b202c35336466,0x3172252c36303172\n"
".quad 0x6c2e090a3b7d3530,0x313509313309636f,0x646461090a300932,0x722509203233732e\n"
".quad 0x38337225202c3833,0x744c240a3b31202c,0x38313836365f335f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c39353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333836355f335f,0x3309636f6c2e090a\n"
".quad 0x0a30093831350931,0x3436662e766f6d09,0x3637316466250920,0x306666626430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x646461090a312d20,0x662509203436662e\n"
".quad 0x646625202c373364,0x31646625202c3533,0x766f6d090a3b3637,0x662509203436662e\n"
".quad 0x6430202c37373164,0x3030303030666633,0x3030303030303030,0x090a31202f2f093b\n"
".quad 0x203436662e646461,0x202c393364662509,0x25202c3533646625,0x090a3b3737316466\n"
".quad 0x662e6e722e747663,0x09203436662e3233,0x646625202c326625,0x706372090a3b3933\n"
".quad 0x2e786f727070612e,0x3666250920323366,0x090a3b326625202c,0x2e3436662e747663\n"
".quad 0x6466250920323366,0x3b366625202c3034,0x36662e67656e090a,0x3731646625092034\n"
".quad 0x3933646625202c38,0x662e766f6d090a3b,0x3164662509203436,0x66336430202c3937\n"
".quad 0x3030303030303066,0x093b303030303030,0x616d090a31202f2f,0x3436662e6e722e64\n"
".quad 0x2c33346466250920,0x2c38373164662520,0x202c303464662520,0x0a3b393731646625\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x34646625202c3434,0x3334646625202c33\n"
".quad 0x3b3334646625202c,0x6e722e64616d090a,0x662509203436662e,0x646625202c353464\n"
".quad 0x34646625202c3434,0x3034646625202c30,0x662e6c756d090a3b,0x3464662509203436\n"
".quad 0x3733646625202c36,0x3b3534646625202c,0x3309636f6c2e090a,0x0a30093832350931\n"
".quad 0x3436662e64646109,0x2c37346466250920,0x202c363464662520,0x090a3b3634646625\n"
".quad 0x203436662e6c756d,0x202c383464662509,0x25202c3734646625,0x6d090a3b37346466\n"
".quad 0x09203436662e766f,0x202c303831646625,0x3833316265336430,0x6630386561336230\n"
".quad 0x31202f2f093b6531,0x2d6533333632302e,0x2e766f6d090a3630,0x6466250920343666\n"
".quad 0x336430202c313831,0x3835326565306465,0x3b34306238613762,0x33302e34202f2f09\n"
".quad 0x0a36302d65393436,0x2e6e722e64616d09,0x6466250920343666,0x646625202c323831\n"
".quad 0x646625202c303831,0x31646625202c3834,0x766f6d090a3b3138,0x662509203436662e\n"
".quad 0x6430202c33383164,0x3636326233666533,0x6636373632306639,0x382e31202f2f093b\n"
".quad 0x35302d6534343837,0x6e722e64616d090a,0x662509203436662e,0x6625202c34383164\n"
".quad 0x6625202c32383164,0x646625202c383464,0x6f6d090a3b333831,0x2509203436662e76\n"
".quad 0x30202c3538316466,0x6335343731663364,0x3539306261396162,0x2e38202f2f093b36\n"
".quad 0x302d653138373738,0x722e64616d090a35,0x2509203436662e6e,0x25202c3638316466\n"
".quad 0x25202c3438316466,0x6625202c38346466,0x6d090a3b35383164,0x09203436662e766f\n"
".quad 0x202c373831646625,0x3137633366336430,0x3135623164323763,0x30202f2f093b3435\n"
".quad 0x303433343030302e,0x2e64616d090a3832,0x09203436662e6e72,0x202c383831646625\n"
".quad 0x202c363831646625,0x25202c3834646625,0x090a3b3738316466,0x203436662e766f6d\n"
".quad 0x2c39383164662509,0x3432366633643020,0x6562333239343239,0x202f2f093b643237\n"
".quad 0x3233323230302e30,0x2e64616d090a3431,0x09203436662e6e72,0x202c303931646625\n"
".quad 0x202c383831646625,0x25202c3834646625,0x090a3b3938316466,0x203436662e766f6d\n"
".quad 0x2c31393164662509,0x3939386633643020,0x6139393939393939,0x202f2f093b346333\n"
".quad 0x090a353231302e30,0x662e6e722e64616d,0x3164662509203436,0x31646625202c3239\n"
".quad 0x34646625202c3039,0x3931646625202c38,0x636f6c2e090a3b31,0x0939323509313309\n"
".quad 0x662e766f6d090a30,0x3164662509203436,0x66336430202c3339,0x3535353535353562\n"
".quad 0x093b343535353535,0x3338302e30202f2f,0x616d090a33333333,0x3436662e6e722e64\n"
".quad 0x3439316466250920,0x323931646625202c,0x2c3834646625202c,0x3b33393164662520\n"
".quad 0x3309636f6c2e090a,0x0a30093233350931,0x3436662e62757309,0x2c34366466250920\n"
".quad 0x202c373364662520,0x090a3b3734646625,0x203436662e67656e,0x2c35393164662509\n"
".quad 0x0a3b373464662520,0x3436662e64646109,0x3639316466250920,0x2c3436646625202c\n"
".quad 0x0a3b343664662520,0x2e6e722e64616d09,0x6466250920343666,0x646625202c373931\n"
".quad 0x646625202c353931,0x31646625202c3733,0x6c756d090a3b3639,0x662509203436662e\n"
".quad 0x646625202c383664,0x31646625202c3534,0x6f6c2e090a3b3739,0x3533350931330963\n"
".quad 0x2e6c756d090a3009,0x6466250920343666,0x646625202c383931,0x31646625202c3834\n"
".quad 0x6c756d090a3b3439,0x662509203436662e,0x646625202c303764,0x31646625202c3734\n"
".quad 0x747663090a3b3839,0x2e3436662e6e722e,0x6466250920323373,0x38337225202c3137\n"
".quad 0x662e766f6d090a3b,0x3164662509203436,0x66336430202c3939,0x6566323465323665\n"
".quad 0x093b666539336166,0x3339362e30202f2f,0x64616d090a373431,0x203436662e6e722e\n"
".quad 0x202c333764662509,0x25202c3137646625,0x25202c3939316466,0x6d090a3b37346466\n"
".quad 0x09203436662e766f,0x202c303032646625,0x6362613763336430,0x3038393362336539\n"
".quad 0x32202f2f093b6633,0x2d6535303931332e,0x2e646461090a3731,0x6466250920343666\n"
".quad 0x646625202c313032,0x36646625202c3037,0x2e67656e090a3b38,0x3172250920323373\n"
".quad 0x38337225202c3830,0x722e747663090a3b,0x33732e3436662e6e,0x3032646625092032\n"
".quad 0x3830317225202c32,0x662e766f6d090a3b,0x3264662509203436,0x66336430202c3330\n"
".quad 0x6566323465323665,0x093b666539336166,0x3339362e30202f2f,0x64616d090a373431\n"
".quad 0x203436662e6e722e,0x2c34303264662509,0x2c32303264662520,0x2c33303264662520\n"
".quad 0x0a3b333764662520,0x3436662e62757309,0x3530326466250920,0x343032646625202c\n"
".quad 0x3b3734646625202c,0x36662e627573090a,0x3032646625092034,0x3032646625202c36\n"
".quad 0x3032646625202c31,0x2e64616d090a3b35,0x09203436662e6e72,0x202c373032646625\n"
".quad 0x25202c3137646625,0x25202c3030326466,0x090a3b3630326466,0x203436662e646461\n"
".quad 0x2c38303264662509,0x202c333764662520,0x0a3b373032646625,0x696e752e61726209\n"
".quad 0x6e6557444c240920,0x746e695f5f5f6964,0x61685f6c616e7265,0x315f3031325f666c\n"
".quad 0x335f744c240a3b34,0x0a3a30393234345f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c39353220,0x6c6562616c206461\n"
".quad 0x335f744c24206465,0x090a34333836355f,0x09313309636f6c2e,0x61090a3009383435\n"
".quad 0x09203436662e7362,0x202c393032646625,0x0a3b363631646625,0x3436662e766f6d09\n"
".quad 0x3031326466250920,0x306666376430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x6573090a666e6920,0x36662e656c2e7074,0x2c37327025092034,0x2c39303264662520\n"
".quad 0x3b30313264662520,0x203732702540090a,0x744c240920617262,0x30333337365f335f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39353220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x36662e646461090a,0x3132646625092034,0x3631646625202c31,0x3631646625202c36\n"
".quad 0x2e67656e090a3b36,0x6466250920343666,0x646625202c383032,0x7262090a3b313132\n"
".quad 0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f,0x5f666c61685f6c61\n"
".quad 0x0a3b34315f303132,0x37365f335f744c24,0x2f2f200a3a303333,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338,0x662509203436662e\n"
".quad 0x6430202c32313264,0x3030303030303030,0x3030303030303030,0x090a30202f2f093b\n"
".quad 0x2e71652e70746573,0x3270250920343666,0x3731646625202c38,0x3132646625202c31\n"
".quad 0x70252140090a3b32,0x0920617262203832,0x37365f335f744c24,0x2f2f200a3b323438\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338\n"
".quad 0x662509203436662e,0x6430202c38303264,0x3030303030666666,0x3030303030303030\n"
".quad 0x6e692d202f2f093b,0x752e617262090a66,0x57444c240920696e,0x695f5f5f69646e65\n"
".quad 0x5f6c616e7265746e,0x3031325f666c6168,0x744c240a3b34315f,0x32343837365f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39353220656e,0x62616c2064616568,0x744c242064656c65,0x34333836355f335f\n"
".quad 0x36662e766f6d090a,0x3132646625092034,0x6666376430202c33,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x73090a666e69202f,0x662e71652e707465,0x3932702509203436\n"
".quad 0x313731646625202c,0x333132646625202c,0x3270252140090a3b,0x2409206172622039\n"
".quad 0x3338365f335f744c,0x3c2f2f200a3b3435,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x39353220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3836355f335f744c,0x2e766f6d090a3433,0x6466250920343666,0x646625202c383032\n"
".quad 0x7262090a3b313731,0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f\n"
".quad 0x5f666c61685f6c61,0x0a3b34315f303132,0x38365f335f744c24,0x2f2f200a3a343533\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c39,0x2064656c6562616c,0x36355f335f744c24,0x766f6d090a343338\n"
".quad 0x662509203436662e,0x6430202c38303264,0x3030303038666666,0x3030303030303030\n"
".quad 0x616e2d202f2f093b,0x6e6557444c240a6e,0x746e695f5f5f6964,0x61685f6c616e7265\n"
".quad 0x315f3031325f666c,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c39353220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333836355f335f74,0x09636f6c2e090a34,0x3009303331093931,0x36662e766f6d090a\n"
".quad 0x3732646625092034,0x383032646625202c,0x5f335f744c240a3b,0x200a3a3431313835\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c393532,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433383635\n"
".quad 0x3109393109636f6c,0x6f6d090a30093233,0x2509203436662e76,0x30202c3431326466\n"
".quad 0x3339393564663364,0x3633303465336332,0x2e30202f2f093b64,0x090a353734373333\n"
".quad 0x203436662e766f6d,0x2c35313264662509,0x3366656633643020,0x6362386663366363\n"
".quad 0x202f2f093b313331,0x3936313637392e30,0x36662e766f6d090a,0x3132646625092034\n"
".quad 0x6366336430202c36,0x3636323730353934,0x2f093b3638363039,0x373036312e30202f\n"
".quad 0x2e766f6d090a3839,0x6466250920343666,0x336430202c373132,0x3764616534633966\n"
".quad 0x3b37333234346533,0x32302e30202f2f09,0x6d090a3933343637,0x09203436662e766f\n"
".quad 0x202c383132646625,0x3637663666336430,0x3736653335653334,0x30202f2f093b3538\n"
".quad 0x353034383330302e,0x662e766f6d090a37,0x3264662509203436,0x66336430202c3931\n"
".quad 0x3061653236653933,0x093b363438383961,0x3030302e30202f2f,0x6d090a3931353933\n"
".quad 0x09203436662e766f,0x202c303232646625,0x6564303066336430,0x3238356635303262\n"
".quad 0x33202f2f093b3830,0x2d6538363731322e,0x2e766f6d090a3530,0x6466250920343666\n"
".quad 0x336430202c313232,0x3735643136333965,0x3b36356237623930,0x38382e32202f2f09\n"
".quad 0x0a37302d65373138,0x3436662e766f6d09,0x3232326466250920,0x613965336430202c\n"
".quad 0x3230613035633339,0x2f2f093b64613564,0x32333036392e3320,0x616d090a37302d65\n"
".quad 0x3436662e6e722e64,0x3332326466250920,0x323232646625202c,0x2c3732646625202c\n"
".quad 0x3b31323264662520,0x6e722e64616d090a,0x662509203436662e,0x6625202c34323264\n"
".quad 0x646625202c373264,0x646625202c333232,0x616d090a3b303232,0x3436662e6e722e64\n"
".quad 0x3532326466250920,0x2c3732646625202c,0x2c34323264662520,0x3b39313264662520\n"
".quad 0x6e722e64616d090a,0x662509203436662e,0x6625202c36323264,0x646625202c373264\n"
".quad 0x646625202c353232,0x616d090a3b383132,0x3436662e6e722e64,0x3732326466250920\n"
".quad 0x2c3732646625202c,0x2c36323264662520,0x3b37313264662520,0x6e722e64616d090a\n"
".quad 0x662509203436662e,0x6625202c38323264,0x646625202c373264,0x646625202c373232\n"
".quad 0x616d090a3b363132,0x3436662e6e722e64,0x3932326466250920,0x2c3732646625202c\n"
".quad 0x2c38323264662520,0x3b35313264662520,0x6e722e64616d090a,0x662509203436662e\n"
".quad 0x6625202c30333264,0x646625202c373264,0x646625202c393232,0x656e090a3b343132\n"
".quad 0x2509203436662e67,0x25202c3133326466,0x090a3b3033326466,0x203436662e766f6d\n"
".quad 0x2c32333264662509,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x2e70746573090a30,0x09203436662e746c,0x6625202c30337025,0x32646625202c3664\n"
".quad 0x6c6573090a3b3233,0x2509203436662e70,0x6625202c37326466,0x6625202c31333264\n"
".quad 0x7025202c30333264,0x5f744c240a3b3033,0x3a32303637355f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3935322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333836355f33,0x3436662e766f6d09\n"
".quad 0x202c346466250920,0x240a3b3732646625,0x5f69646e6557444c,0x5f65646976696466\n"
".quad 0x0a3a31315f303132,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c39353220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333836355f,0x09393109636f6c2e,0x63090a3009313632,0x33662e6e722e7476\n"
".quad 0x2509203436662e32,0x34646625202c3766,0x6c672e7473090a3b,0x3233662e6c61626f\n"
".quad 0x2b373172255b0920,0x3b376625202c5d30,0x33752e646461090a,0x2c37317225092032\n"
".quad 0x25202c3731722520,0x6461090a3b323172,0x2509203233752e64,0x317225202c343172\n"
".quad 0x3b32317225202c34,0x6c2e70746573090a,0x2509203233752e74,0x317225202c313370\n"
".quad 0x3b35317225202c34,0x203133702540090a,0x744c240920617262,0x34333836355f335f\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b32323139365f33,0x355f335f744c240a\n"
".quad 0x2e090a3a36363036,0x3209393109636f6c,0x756d090a30093736,0x752e6f6c2e34326c\n"
".quad 0x3031722509203233,0x202c347225202c39,0x6461090a3b337225,0x2509203233752e64\n"
".quad 0x7225202c30313172,0x327225202c393031,0x732e766f6d090a3b,0x3131722509203233\n"
".quad 0x3031317225202c31,0x09636f6c2e090a3b,0x3009313532093931,0x7261702e646c090a\n"
".quad 0x09203233752e6d61,0x5f5f5b202c317225,0x6d72617061647563,0x766e6936315a5f5f\n"
".quad 0x4b444e4365737265,0x5366506c656e7265,0x4e687461705f6a5f,0x636f6c2e090a3b5d\n"
".quad 0x0937363209393109,0x2e70746573090a30,0x09203233752e6567,0x7225202c32337025\n"
".quad 0x317225202c303131,0x3233702540090a3b,0x4c24092061726220,0x323139365f335f74\n"
".quad 0x2e6c756d090a3b32,0x09203233752e6f6c,0x25202c3231317225,0x3b34202c30313172\n"
".quad 0x3109636f6c2e090a,0x0a30093135320939,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x635f5f5b202c3172,0x5f6d726170616475,0x65766e6936315a5f,0x654b444e43657372\n"
".quad 0x5f5366506c656e72,0x5d4e687461705f6a,0x09636f6c2e090a3b,0x3009373632093931\n"
".quad 0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c333131,0x7663090a3b34202c\n"
".quad 0x31752e3233752e74,0x3431317225092036,0x696174636e25202c,0x756d090a3b782e64\n"
".quad 0x752e6f6c2e34326c,0x3131722509203233,0x202c347225202c35,0x090a3b3431317225\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x5f5f5b202c363131,0x6d72617061647563\n"
".quad 0x766e6936315a5f5f,0x4b444e4365737265,0x5366506c656e7265,0x74754f5f645f6a5f\n"
".quad 0x61090a3b5d747570,0x09203233752e6464,0x25202c3731317225,0x7225202c32313172\n"
".quad 0x6461090a3b363131,0x2509203233752e64,0x7225202c38313172,0x317225202c333131\n"
".quad 0x6c756d090a3b3631,0x203233752e6f6c2e,0x202c393131722509,0x34202c3531317225\n"
".quad 0x752e646461090a3b,0x3231722509203233,0x202c317225202c30,0x2e747663090a3b31\n"
".quad 0x752e3436662e6e72,0x3264662509203233,0x32317225202c3333,0x2e706372090a3b30\n"
".quad 0x09203436662e6e72,0x202c343332646625,0x0a3b333332646625,0x39365f335f744c24\n"
".quad 0x2f2f200a3a343336,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x697473656e202c37,0x687470656420676e,0x747365202c31203a,0x6920646574616d69\n"
".quad 0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77,0x0939363209393109\n"
".quad 0x752e646461090a30,0x3231722509203233,0x3131317225202c31,0x7663090a3b31202c\n"
".quad 0x3436662e6e722e74,0x662509203233752e,0x7225202c35333264,0x756d090a3b313231\n"
".quad 0x2509203436662e6c,0x25202c3633326466,0x25202c3533326466,0x090a3b3433326466\n"
".quad 0x203436662e766f6d,0x2c37333264662509,0x3030666633643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x672e746573090a31,0x36662e3233752e65,0x3232317225092034\n"
".quad 0x363332646625202c,0x373332646625202c,0x732e67656e090a3b,0x3231722509203233\n"
".quad 0x3232317225202c33,0x662e766f6d090a3b,0x3264662509203436,0x30306430202c3833\n"
".quad 0x3030303030303030,0x093b303030303030,0x6573090a30202f2f,0x3233752e656c2e74\n"
".quad 0x722509203436662e,0x646625202c343231,0x646625202c363332,0x656e090a3b383332\n"
".quad 0x2509203233732e67,0x7225202c35323172,0x726f090a3b343231,0x722509203233622e\n"
".quad 0x317225202c363231,0x32317225202c3332,0x2e766f6d090a3b35,0x3172250920323375\n"
".quad 0x090a3b30202c3732,0x2e71652e70746573,0x3370250920323373,0x3632317225202c33\n"
".quad 0x3b3732317225202c,0x203333702540090a,0x744c240920617262,0x30393839365f335f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c37363220656e,0x62616c2064616568,0x744c242064656c65,0x34333639365f335f\n"
".quad 0x36662e766f6d090a,0x3332646625092034,0x6666666430202c39,0x3030303030303038\n"
".quad 0x2f093b3030303030,0x090a6e616e2d202f,0x20696e752e617262,0x646e6557444c2409\n"
".quad 0x6469766964665f69,0x3b315f3031325f65,0x365f335f744c240a,0x2f200a3a30393839\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203436662e76,0x30202c3034326466,0x3030303065666264,0x3030303030303030\n"
".quad 0x302d202f2f093b30,0x2e646461090a352e,0x6466250920343666,0x646625202c313432\n"
".quad 0x646625202c363332,0x6261090a3b303432,0x2509203436662e73,0x25202c3234326466\n"
".quad 0x090a3b3134326466,0x203436662e766f6d,0x2c33343264662509,0x6561646633643020\n"
".quad 0x3734316561373431,0x202f2f093b316561,0x6573090a32342e30,0x36662e746c2e7074\n"
".quad 0x2c34337025092034,0x2c32343264662520,0x3b33343264662520,0x343370252140090a\n"
".quad 0x4c24092061726220,0x353630375f335f74,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333639365f335f74,0x09636f6c2e090a34,0x3009353231093931\n"
".quad 0x36662e6c756d090a,0x3432646625092034,0x3432646625202c34,0x3432646625202c31\n"
".quad 0x2e766f6d090a3b31,0x6466250920343666,0x346430202c353432,0x3133396430343030\n"
".quad 0x3b64303236383262,0x30352e32202f2f09,0x766f6d090a333636,0x662509203436662e\n"
".quad 0x6430202c36343264,0x3037643932333063,0x6564336134356561,0x38312d202f2f093b\n"
".quad 0x6f6d090a3531362e,0x2509203436662e76,0x30202c3734326466,0x3132623434303464\n"
".quad 0x6636633337346332,0x3134202f2f093b63,0x6d090a323139332e,0x09203436662e766f\n"
".quad 0x202c383432646625,0x3037393330636430,0x3737373337353965,0x2d202f2f093b3837\n"
".quad 0x0a313134342e3532,0x2e6e722e64616d09,0x6466250920343666,0x646625202c393432\n"
".quad 0x646625202c383432,0x646625202c343432,0x616d090a3b373432,0x3436662e6e722e64\n"
".quad 0x3035326466250920,0x343432646625202c,0x393432646625202c,0x363432646625202c\n"
".quad 0x722e64616d090a3b,0x2509203436662e6e,0x25202c3135326466,0x25202c3434326466\n"
".quad 0x25202c3035326466,0x090a3b3534326466,0x203436662e6c756d,0x2c32353264662509\n"
".quad 0x2c31343264662520,0x3b31353264662520,0x36662e766f6d090a,0x3532646625092034\n"
".quad 0x6666336430202c33,0x3030303030303030,0x2f093b3030303030,0x766f6d090a31202f\n"
".quad 0x662509203436662e,0x6430202c34353264,0x3037326630323063,0x6432373035353630\n"
".quad 0x2e382d202f2f093b,0x6d090a3135333734,0x09203436662e766f,0x202c353532646625\n"
".quad 0x3531373330346430,0x3035313831393735,0x32202f2f093b6332,0x090a343338302e33\n"
".quad 0x203436662e766f6d,0x2c36353264662509,0x3035333063643020,0x6531303730666566\n"
".quad 0x202f2f093b643735,0x323236302e31322d,0x36662e766f6d090a,0x3532646625092034\n"
".quad 0x3030346430202c37,0x3530323066623039,0x2f093b3734613835,0x383033312e33202f\n"
".quad 0x722e64616d090a33,0x2509203436662e6e,0x25202c3835326466,0x25202c3735326466\n"
".quad 0x25202c3434326466,0x090a3b3635326466,0x662e6e722e64616d,0x3264662509203436\n"
".quad 0x32646625202c3935,0x32646625202c3434,0x32646625202c3835,0x64616d090a3b3535\n"
".quad 0x203436662e6e722e,0x2c30363264662509,0x2c34343264662520,0x2c39353264662520\n"
".quad 0x3b34353264662520,0x6e722e64616d090a,0x662509203436662e,0x6625202c31363264\n"
".quad 0x6625202c34343264,0x6625202c30363264,0x64090a3b33353264,0x36662e6e722e7669\n"
".quad 0x3732646625092034,0x323532646625202c,0x313632646625202c,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b32303430375f33,0x375f335f744c240a,0x2f200a3a38353630\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203436662e76,0x30202c3236326466,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x74672e7074657309,0x702509203436662e,0x32646625202c3533\n"
".quad 0x32646625202c3134,0x252140090a3b3236,0x2061726220353370,0x375f335f744c2409\n"
".quad 0x2f200a3b30373131,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420\n"
".quad 0x6c2e090a34333639,0x393409313309636f,0x766f6d090a300932,0x662509203436662e\n"
".quad 0x6430202c33363264,0x3030303030666633,0x3030303030303030,0x090a31202f2f093b\n"
".quad 0x203436662e627573,0x2c34363264662509,0x2c33363264662520,0x3b36333264662520\n"
".quad 0x36622e766f6d090a,0x323172257b092034,0x7d39323172252c38,0x343632646625202c\n"
".quad 0x732e766f6d090a3b,0x3632722509203233,0x3b3932317225202c,0x3309636f6c2e090a\n"
".quad 0x0a30093339340931,0x3436622e766f6d09,0x2c373272257b0920,0x202c7d3033317225\n"
".quad 0x0a3b343632646625,0x313309636f6c2e09,0x090a300935393409,0x203436662e766f6d\n"
".quad 0x2c35363264662509,0x3030303030643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x672e746573090a30,0x36662e3233752e74,0x3133317225092034,0x343632646625202c\n"
".quad 0x353632646625202c,0x732e67656e090a3b,0x3331722509203233,0x3133317225202c32\n"
".quad 0x662e766f6d090a3b,0x3264662509203436,0x66376430202c3636,0x3030303030303066\n"
".quad 0x093b303030303030,0x090a666e69202f2f,0x752e746c2e746573,0x09203436662e3233\n"
".quad 0x25202c3333317225,0x25202c3436326466,0x090a3b3636326466,0x203233732e67656e\n"
".quad 0x202c343331722509,0x090a3b3333317225,0x203233622e646e61,0x202c353331722509\n"
".quad 0x25202c3233317225,0x6d090a3b34333172,0x09203233752e766f,0x30202c3633317225\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x7225202c36337025,0x317225202c353331\n"
".quad 0x702540090a3b3633,0x0920617262203633,0x37345f335f744c24,0x2f2f200a3b323633\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c37,0x2064656c6562616c,0x39365f335f744c24,0x766f6d090a343336\n"
".quad 0x722509203233752e,0x343031202c373331,0x73090a3b35373538,0x752e74672e707465\n"
".quad 0x3733702509203233,0x2c3932317225202c,0x0a3b373331722520,0x6220373370254009\n"
".quad 0x5f744c2409206172,0x3b32383631375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09,0x090a300931303509\n"
".quad 0x203436662e766f6d,0x2c37363264662509,0x3030353334643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x6534343130382e31,0x6c756d090a36312b,0x662509203436662e\n"
".quad 0x6625202c38363264,0x6625202c34363264,0x6d090a3b37363264,0x09203436622e766f\n"
".quad 0x252c38333172257b,0x6625202c7d363272,0x2e090a3b38363264,0x3509313309636f6c\n"
".quad 0x6f6d090a30093230,0x7b09203436622e76,0x3172252c37327225,0x646625202c7d3933\n"
".quad 0x6f6d090a3b383632,0x2509203233732e76,0x30312d202c383372,0x617262090a3b3737\n"
".quad 0x4c240920696e752e,0x323431375f335f74,0x335f744c240a3b36,0x0a3a32383631375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c37363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f\n"
".quad 0x203233732e766f6d,0x2d202c3833722509,0x4c240a3b33323031,0x323431375f335f74\n"
".quad 0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c37363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009373035093133,0x33732e726873090a,0x3034317225092032\n"
".quad 0x202c36327225202c,0x646461090a3b3032,0x722509203233732e,0x38337225202c3833\n"
".quad 0x3b3034317225202c,0x3309636f6c2e090a,0x0a30093930350931,0x3233622e646e6109\n"
".quad 0x202c303472250920,0x322d202c36327225,0x3730353334363431,0x622e726f090a3b33\n"
".quad 0x3134722509203233,0x202c30347225202c,0x3233393632373031,0x766f6d090a3b3834\n"
".quad 0x662509203436622e,0x72257b202c353364,0x7d313472252c3732,0x752e766f6d090a3b\n"
".quad 0x3431722509203233,0x3133373031202c31,0x090a3b3238353732,0x2e656c2e70746573\n"
".quad 0x3370250920323375,0x2c31347225202c38,0x0a3b313431722520,0x6220383370254009\n"
".quad 0x5f744c2409206172,0x3b38333931375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09,0x090a300931313509\n"
".quad 0x203436622e766f6d,0x2c32343172257b09,0x202c7d3334317225,0x090a3b3533646625\n"
".quad 0x203233732e627573,0x202c343431722509,0x31202c3334317225,0x0a3b363735383430\n"
".quad 0x3436622e766f6d09,0x35343172257b0920,0x2c7d36343172252c,0x0a3b353364662520\n"
".quad 0x3436622e766f6d09,0x2c35336466250920,0x2c35343172257b20,0x0a3b7d3434317225\n"
".quad 0x313309636f6c2e09,0x090a300932313509,0x203233732e646461,0x25202c3833722509\n"
".quad 0x0a3b31202c383372,0x31375f335f744c24,0x2f2f200a3a383339,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20,0x2064616568202c37\n"
".quad 0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336,0x3831350931330963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x626430202c393632,0x3030303030306666\n"
".quad 0x3b30303030303030,0x090a312d202f2f09,0x203436662e646461,0x202c373364662509\n"
".quad 0x25202c3533646625,0x090a3b3936326466,0x203436662e766f6d,0x2c30373264662509\n"
".quad 0x3030666633643020,0x3030303030303030,0x202f2f093b303030,0x662e646461090a31\n"
".quad 0x3364662509203436,0x3533646625202c39,0x303732646625202c,0x722e747663090a3b\n"
".quad 0x36662e3233662e6e,0x202c326625092034,0x090a3b3933646625,0x727070612e706372\n"
".quad 0x09203233662e786f,0x326625202c386625,0x662e747663090a3b,0x09203233662e3436\n"
".quad 0x25202c3034646625,0x67656e090a3b3866,0x662509203436662e,0x6625202c31373264\n"
".quad 0x6f6d090a3b393364,0x2509203436662e76,0x30202c3237326466,0x3030303066663364\n"
".quad 0x3030303030303030,0x0a31202f2f093b30,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x32646625202c3334,0x34646625202c3137,0x3732646625202c30,0x2e64616d090a3b32\n"
".quad 0x09203436662e6e72,0x25202c3434646625,0x6625202c33346466,0x646625202c333464\n"
".quad 0x64616d090a3b3334,0x203436662e6e722e,0x202c353464662509,0x25202c3434646625\n"
".quad 0x6625202c30346466,0x756d090a3b303464,0x2509203436662e6c,0x6625202c36346466\n"
".quad 0x646625202c373364,0x6f6c2e090a3b3534,0x3832350931330963,0x2e646461090a3009\n"
".quad 0x6466250920343666,0x34646625202c3734,0x3634646625202c36,0x662e6c756d090a3b\n"
".quad 0x3464662509203436,0x3734646625202c38,0x3b3734646625202c,0x36662e766f6d090a\n"
".quad 0x3732646625092034,0x6265336430202c33,0x6561336230383331,0x2f093b6531663038\n"
".quad 0x333632302e31202f,0x6d090a36302d6533,0x09203436662e766f,0x202c343732646625\n"
".quad 0x6565306465336430,0x6238613762383532,0x34202f2f093b3430,0x2d6539343633302e\n"
".quad 0x2e64616d090a3630,0x09203436662e6e72,0x202c353732646625,0x202c333732646625\n"
".quad 0x25202c3834646625,0x090a3b3437326466,0x203436662e766f6d,0x2c36373264662509\n"
".quad 0x6233666533643020,0x3632306639363632,0x202f2f093b663637,0x6534343837382e31\n"
".quad 0x64616d090a35302d,0x203436662e6e722e,0x2c37373264662509,0x2c35373264662520\n"
".quad 0x202c383464662520,0x0a3b363732646625,0x3436662e766f6d09,0x3837326466250920\n"
".quad 0x373166336430202c,0x6261396162633534,0x2f2f093b36353930,0x31383737382e3820\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x3937326466250920,0x373732646625202c\n"
".quad 0x2c3834646625202c,0x3b38373264662520,0x36662e766f6d090a,0x3832646625092034\n"
".quad 0x3366336430202c30,0x3164323763313763,0x2f093b3435313562,0x343030302e30202f\n"
".quad 0x6d090a3832303433,0x36662e6e722e6461,0x3832646625092034,0x3732646625202c31\n"
".quad 0x3834646625202c39,0x303832646625202c,0x662e766f6d090a3b,0x3264662509203436\n"
".quad 0x66336430202c3238,0x3239343239343236,0x093b643237656233,0x3230302e30202f2f\n"
".quad 0x6d090a3431323332,0x36662e6e722e6461,0x3832646625092034,0x3832646625202c33\n"
".quad 0x3834646625202c31,0x323832646625202c,0x662e766f6d090a3b,0x3264662509203436\n"
".quad 0x66336430202c3438,0x3939393939393938,0x093b346333613939,0x3231302e30202f2f\n"
".quad 0x722e64616d090a35,0x2509203436662e6e,0x25202c3538326466,0x25202c3338326466\n"
".quad 0x6625202c38346466,0x2e090a3b34383264,0x3509313309636f6c,0x6f6d090a30093932\n"
".quad 0x2509203436662e76,0x30202c3638326466,0x3535353562663364,0x3535353535353535\n"
".quad 0x2e30202f2f093b34,0x0a33333333333830,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x646625202c373832,0x646625202c353832,0x32646625202c3834,0x6f6c2e090a3b3638\n"
".quad 0x3233350931330963,0x2e627573090a3009,0x6466250920343666,0x33646625202c3436\n"
".quad 0x3734646625202c37,0x662e67656e090a3b,0x3264662509203436,0x34646625202c3838\n"
".quad 0x2e646461090a3b37,0x6466250920343666,0x646625202c393832,0x36646625202c3436\n"
".quad 0x2e64616d090a3b34,0x09203436662e6e72,0x202c303932646625,0x202c383832646625\n"
".quad 0x25202c3733646625,0x090a3b3938326466,0x203436662e6c756d,0x202c383664662509\n"
".quad 0x25202c3534646625,0x090a3b3039326466,0x09313309636f6c2e,0x6d090a3009353335\n"
".quad 0x09203436662e6c75,0x202c313932646625,0x25202c3834646625,0x090a3b3738326466\n"
".quad 0x203436662e6c756d,0x202c303764662509,0x25202c3734646625,0x090a3b3139326466\n"
".quad 0x662e6e722e747663,0x09203233732e3436,0x25202c3137646625,0x6f6d090a3b383372\n"
".quad 0x2509203436662e76,0x30202c3239326466,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3764662509203436\n"
".quad 0x3137646625202c33,0x323932646625202c,0x3b3734646625202c,0x36662e766f6d090a\n"
".quad 0x3932646625092034,0x3763336430202c33,0x3362336539636261,0x2f093b6633303839\n"
".quad 0x303931332e32202f,0x61090a37312d6535,0x09203436662e6464,0x202c343932646625\n"
".quad 0x25202c3037646625,0x6e090a3b38366466,0x09203233732e6765,0x25202c3734317225\n"
".quad 0x7663090a3b383372,0x3436662e6e722e74,0x662509203233732e,0x7225202c35393264\n"
".quad 0x6f6d090a3b373431,0x2509203436662e76,0x30202c3639326466,0x3465323665663364\n"
".quad 0x6539336166656632,0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d\n"
".quad 0x3264662509203436,0x32646625202c3739,0x32646625202c3539,0x37646625202c3639\n"
".quad 0x2e627573090a3b33,0x6466250920343666,0x646625202c383932,0x646625202c373932\n"
".quad 0x627573090a3b3734,0x662509203436662e,0x6625202c39393264,0x6625202c34393264\n"
".quad 0x6d090a3b38393264,0x36662e6e722e6461,0x3033646625092034,0x3137646625202c30\n"
".quad 0x333932646625202c,0x393932646625202c,0x662e646461090a3b,0x3864662509203436\n"
".quad 0x3337646625202c32,0x303033646625202c,0x752e617262090a3b,0x57444c240920696e\n"
".quad 0x695f5f5f69646e65,0x5f6c616e7265746e,0x3031325f666c6168,0x5f744c240a3b365f\n"
".quad 0x3a32363337345f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333639365f33,0x313309636f6c2e09,0x090a300938343509,0x203436662e736261\n"
".quad 0x2c31303364662509,0x3b34363264662520,0x36662e766f6d090a,0x3033646625092034\n"
".quad 0x6666376430202c32,0x3030303030303030,0x2f093b3030303030,0x73090a666e69202f\n"
".quad 0x662e656c2e707465,0x3933702509203436,0x313033646625202c,0x323033646625202c\n"
".quad 0x3933702540090a3b,0x4c24092061726220,0x353432375f335f74,0x6c3c2f2f200a3b30\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333639365f335f74,0x662e646461090a34\n"
".quad 0x3864662509203436,0x3632646625202c32,0x3632646625202c34,0x2e617262090a3b34\n"
".quad 0x444c240920696e75,0x5f5f5f69646e6557,0x6c616e7265746e69,0x31325f666c61685f\n"
".quad 0x744c240a3b365f30,0x30353432375f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c37363220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333639365f335f,0x36662e766f6d090a,0x3033646625092034\n"
".quad 0x3030306430202c33,0x3030303030303030,0x2f093b3030303030,0x746573090a30202f\n"
".quad 0x3436662e71652e70,0x202c303470250920,0x202c343632646625,0x0a3b333033646625\n"
".quad 0x2030347025214009,0x744c240920617262,0x32363932375f335f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c37363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333639365f335f,0x36662e766f6d090a\n"
".quad 0x3238646625092034,0x306666666430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x62090a666e692d20,0x0920696e752e6172,0x69646e6557444c24,0x7265746e695f5f5f\n"
".quad 0x666c61685f6c616e,0x0a3b365f3031325f,0x32375f335f744c24,0x2f2f200a3a323639\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c37,0x2064656c6562616c,0x39365f335f744c24,0x766f6d090a343336\n"
".quad 0x662509203436662e,0x6430202c34303364,0x3030303030666637,0x3030303030303030\n"
".quad 0x666e69202f2f093b,0x652e70746573090a,0x2509203436662e71,0x646625202c313470\n"
".quad 0x646625202c343632,0x2140090a3b343033,0x6172622031347025,0x5f335f744c240920\n"
".quad 0x200a3b3437343337,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c373632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x6d090a3433363936,0x09203436662e766f,0x25202c3238646625,0x090a3b3436326466\n"
".quad 0x20696e752e617262,0x646e6557444c2409,0x65746e695f5f5f69,0x6c61685f6c616e72\n"
".quad 0x3b365f3031325f66,0x375f335f744c240a,0x2f200a3a34373433,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3736\n"
".quad 0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639,0x2509203436662e76\n"
".quad 0x6430202c32386466,0x3030303038666666,0x3030303030303030,0x616e2d202f2f093b\n"
".quad 0x6e6557444c240a6e,0x746e695f5f5f6964,0x61685f6c616e7265,0x365f3031325f666c\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c37363220656e,0x62616c2064616568,0x744c242064656c65,0x34333639365f335f\n"
".quad 0x3309636f6c2e090a,0x0a30093239340931,0x3436662e67656e09,0x3530336466250920\n"
".quad 0x3b3238646625202c,0x36622e766f6d090a,0x343172257b092034,0x7d39343172252c38\n"
".quad 0x353033646625202c,0x732e766f6d090a3b,0x3632722509203233,0x3b3934317225202c\n"
".quad 0x3309636f6c2e090a,0x0a30093339340931,0x3436622e766f6d09,0x2c373272257b0920\n"
".quad 0x202c7d3035317225,0x0a3b353033646625,0x313309636f6c2e09,0x090a300935393409\n"
".quad 0x203436662e766f6d,0x2c36303364662509,0x3030303030643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x672e746573090a30,0x36662e3233752e74,0x3135317225092034\n"
".quad 0x353033646625202c,0x363033646625202c,0x732e67656e090a3b,0x3531722509203233\n"
".quad 0x3135317225202c32,0x662e766f6d090a3b,0x3364662509203436,0x66376430202c3730\n"
".quad 0x3030303030303066,0x093b303030303030,0x090a666e69202f2f,0x752e746c2e746573\n"
".quad 0x09203436662e3233,0x25202c3335317225,0x25202c3530336466,0x090a3b3730336466\n"
".quad 0x203233732e67656e,0x202c343531722509,0x090a3b3335317225,0x203233622e646e61\n"
".quad 0x202c353531722509,0x25202c3235317225,0x6d090a3b34353172,0x09203233752e766f\n"
".quad 0x30202c3635317225,0x2e70746573090a3b,0x09203233732e7165,0x7225202c32347025\n"
".quad 0x317225202c353531,0x702540090a3b3635,0x0920617262203234,0x38345f335f744c24\n"
".quad 0x2f2f200a3b383938,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c37,0x2064656c6562616c,0x39365f335f744c24\n"
".quad 0x766f6d090a343336,0x722509203233752e,0x343031202c373531,0x73090a3b35373538\n"
".quad 0x752e74672e707465,0x3334702509203233,0x2c3934317225202c,0x0a3b373531722520\n"
".quad 0x6220333470254009,0x5f744c2409206172,0x3b32343234375f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09\n"
".quad 0x090a300931303509,0x203436662e766f6d,0x2c38303364662509,0x3030353334643020\n"
".quad 0x3030303030303030,0x202f2f093b303030,0x6534343130382e31,0x6c756d090a36312b\n"
".quad 0x662509203436662e,0x6625202c39303364,0x6625202c35303364,0x6d090a3b38303364\n"
".quad 0x09203436622e766f,0x252c38353172257b,0x6625202c7d363272,0x2e090a3b39303364\n"
".quad 0x3509313309636f6c,0x6f6d090a30093230,0x7b09203436622e76,0x3172252c37327225\n"
".quad 0x646625202c7d3935,0x6f6d090a3b393033,0x2509203233732e76,0x30312d202c383372\n"
".quad 0x617262090a3b3737,0x4c240920696e752e,0x383933375f335f74,0x335f744c240a3b36\n"
".quad 0x0a3a32343234375f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c37363220,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34333639365f,0x203233732e766f6d,0x2d202c3833722509,0x4c240a3b33323031\n"
".quad 0x383933375f335f74,0x6c3c2f2f200a3a36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c37363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333639365f335f74,0x09636f6c2e090a34,0x3009373035093133,0x33732e726873090a\n"
".quad 0x3036317225092032,0x202c36327225202c,0x646461090a3b3032,0x722509203233732e\n"
".quad 0x38337225202c3833,0x3b3036317225202c,0x3309636f6c2e090a,0x0a30093930350931\n"
".quad 0x3233622e646e6109,0x202c303472250920,0x322d202c36327225,0x3730353334363431\n"
".quad 0x622e726f090a3b33,0x3134722509203233,0x202c30347225202c,0x3233393632373031\n"
".quad 0x766f6d090a3b3834,0x662509203436622e,0x72257b202c353364,0x7d313472252c3732\n"
".quad 0x752e766f6d090a3b,0x3631722509203233,0x3133373031202c31,0x090a3b3238353732\n"
".quad 0x2e656c2e70746573,0x3470250920323375,0x2c31347225202c34,0x0a3b313631722520\n"
".quad 0x6220343470254009,0x5f744c2409206172,0x3b38393434375f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09\n"
".quad 0x090a300931313509,0x203436622e766f6d,0x2c32363172257b09,0x202c7d3336317225\n"
".quad 0x090a3b3533646625,0x203233732e627573,0x202c343631722509,0x31202c3336317225\n"
".quad 0x0a3b363735383430,0x3436622e766f6d09,0x35363172257b0920,0x2c7d36363172252c\n"
".quad 0x0a3b353364662520,0x3436622e766f6d09,0x2c35336466250920,0x2c35363172257b20\n"
".quad 0x0a3b7d3436317225,0x313309636f6c2e09,0x090a300932313509,0x203233732e646461\n"
".quad 0x25202c3833722509,0x0a3b31202c383372,0x34375f335f744c24,0x2f2f200a3a383934\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x363220656e696c20\n"
".quad 0x2064616568202c37,0x2064656c6562616c,0x39365f335f744c24,0x6f6c2e090a343336\n"
".quad 0x3831350931330963,0x2e766f6d090a3009,0x6466250920343666,0x626430202c303133\n"
".quad 0x3030303030306666,0x3b30303030303030,0x090a312d202f2f09,0x203436662e646461\n"
".quad 0x202c373364662509,0x25202c3533646625,0x090a3b3031336466,0x203436662e766f6d\n"
".quad 0x2c31313364662509,0x3030666633643020,0x3030303030303030,0x202f2f093b303030\n"
".quad 0x662e646461090a31,0x3364662509203436,0x3533646625202c39,0x313133646625202c\n"
".quad 0x722e747663090a3b,0x36662e3233662e6e,0x202c326625092034,0x090a3b3933646625\n"
".quad 0x727070612e706372,0x09203233662e786f,0x326625202c396625,0x662e747663090a3b\n"
".quad 0x09203233662e3436,0x25202c3034646625,0x67656e090a3b3966,0x662509203436662e\n"
".quad 0x6625202c32313364,0x6f6d090a3b393364,0x2509203436662e76,0x30202c3331336466\n"
".quad 0x3030303066663364,0x3030303030303030,0x0a31202f2f093b30,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x33646625202c3334,0x34646625202c3231,0x3133646625202c30\n"
".quad 0x2e64616d090a3b33,0x09203436662e6e72,0x25202c3434646625,0x6625202c33346466\n"
".quad 0x646625202c333464,0x64616d090a3b3334,0x203436662e6e722e,0x202c353464662509\n"
".quad 0x25202c3434646625,0x6625202c30346466,0x756d090a3b303464,0x2509203436662e6c\n"
".quad 0x6625202c36346466,0x646625202c373364,0x6f6c2e090a3b3534,0x3832350931330963\n"
".quad 0x2e646461090a3009,0x6466250920343666,0x34646625202c3734,0x3634646625202c36\n"
".quad 0x662e6c756d090a3b,0x3464662509203436,0x3734646625202c38,0x3b3734646625202c\n"
".quad 0x36662e766f6d090a,0x3133646625092034,0x6265336430202c34,0x6561336230383331\n"
".quad 0x2f093b6531663038,0x333632302e31202f,0x6d090a36302d6533,0x09203436662e766f\n"
".quad 0x202c353133646625,0x6565306465336430,0x6238613762383532,0x34202f2f093b3430\n"
".quad 0x2d6539343633302e,0x2e64616d090a3630,0x09203436662e6e72,0x202c363133646625\n"
".quad 0x202c343133646625,0x25202c3834646625,0x090a3b3531336466,0x203436662e766f6d\n"
".quad 0x2c37313364662509,0x6233666533643020,0x3632306639363632,0x202f2f093b663637\n"
".quad 0x6534343837382e31,0x64616d090a35302d,0x203436662e6e722e,0x2c38313364662509\n"
".quad 0x2c36313364662520,0x202c383464662520,0x0a3b373133646625,0x3436662e766f6d09\n"
".quad 0x3931336466250920,0x373166336430202c,0x6261396162633534,0x2f2f093b36353930\n"
".quad 0x31383737382e3820,0x616d090a35302d65,0x3436662e6e722e64,0x3032336466250920\n"
".quad 0x383133646625202c,0x2c3834646625202c,0x3b39313364662520,0x36662e766f6d090a\n"
".quad 0x3233646625092034,0x3366336430202c31,0x3164323763313763,0x2f093b3435313562\n"
".quad 0x343030302e30202f,0x6d090a3832303433,0x36662e6e722e6461,0x3233646625092034\n"
".quad 0x3233646625202c32,0x3834646625202c30,0x313233646625202c,0x662e766f6d090a3b\n"
".quad 0x3364662509203436,0x66336430202c3332,0x3239343239343236,0x093b643237656233\n"
".quad 0x3230302e30202f2f,0x6d090a3431323332,0x36662e6e722e6461,0x3233646625092034\n"
".quad 0x3233646625202c34,0x3834646625202c32,0x333233646625202c,0x662e766f6d090a3b\n"
".quad 0x3364662509203436,0x66336430202c3532,0x3939393939393938,0x093b346333613939\n"
".quad 0x3231302e30202f2f,0x722e64616d090a35,0x2509203436662e6e,0x25202c3632336466\n"
".quad 0x25202c3432336466,0x6625202c38346466,0x2e090a3b35323364,0x3509313309636f6c\n"
".quad 0x6f6d090a30093932,0x2509203436662e76,0x30202c3732336466,0x3535353562663364\n"
".quad 0x3535353535353535,0x2e30202f2f093b34,0x0a33333333333830,0x2e6e722e64616d09\n"
".quad 0x6466250920343666,0x646625202c383233,0x646625202c363233,0x33646625202c3834\n"
".quad 0x6f6c2e090a3b3732,0x3233350931330963,0x2e627573090a3009,0x6466250920343666\n"
".quad 0x33646625202c3436,0x3734646625202c37,0x662e67656e090a3b,0x3364662509203436\n"
".quad 0x34646625202c3932,0x2e646461090a3b37,0x6466250920343666,0x646625202c303333\n"
".quad 0x36646625202c3436,0x2e64616d090a3b34,0x09203436662e6e72,0x202c313333646625\n"
".quad 0x202c393233646625,0x25202c3733646625,0x090a3b3033336466,0x203436662e6c756d\n"
".quad 0x202c383664662509,0x25202c3534646625,0x090a3b3133336466,0x09313309636f6c2e\n"
".quad 0x6d090a3009353335,0x09203436662e6c75,0x202c323333646625,0x25202c3834646625\n"
".quad 0x090a3b3832336466,0x203436662e6c756d,0x202c303764662509,0x25202c3734646625\n"
".quad 0x090a3b3233336466,0x662e6e722e747663,0x09203233732e3436,0x25202c3137646625\n"
".quad 0x6f6d090a3b383372,0x2509203436662e76,0x30202c3333336466,0x3465323665663364\n"
".quad 0x6539336166656632,0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d\n"
".quad 0x3764662509203436,0x3137646625202c33,0x333333646625202c,0x3b3734646625202c\n"
".quad 0x36662e766f6d090a,0x3333646625092034,0x3763336430202c34,0x3362336539636261\n"
".quad 0x2f093b6633303839,0x303931332e32202f,0x61090a37312d6535,0x09203436662e6464\n"
".quad 0x202c353333646625,0x25202c3037646625,0x6e090a3b38366466,0x09203233732e6765\n"
".quad 0x25202c3736317225,0x7663090a3b383372,0x3436662e6e722e74,0x662509203233732e\n"
".quad 0x7225202c36333364,0x6f6d090a3b373631,0x2509203436662e76,0x30202c3733336466\n"
".quad 0x3465323665663364,0x6539336166656632,0x2e30202f2f093b66,0x090a373431333936\n"
".quad 0x662e6e722e64616d,0x3364662509203436,0x33646625202c3833,0x33646625202c3633\n"
".quad 0x37646625202c3733,0x2e627573090a3b33,0x6466250920343666,0x646625202c393333\n"
".quad 0x646625202c383333,0x627573090a3b3734,0x662509203436662e,0x6625202c30343364\n"
".quad 0x6625202c35333364,0x6d090a3b39333364,0x36662e6e722e6461,0x3433646625092034\n"
".quad 0x3137646625202c31,0x343333646625202c,0x303433646625202c,0x662e646461090a3b\n"
".quad 0x3164662509203436,0x37646625202c3432,0x3433646625202c33,0x2e617262090a3b31\n"
".quad 0x444c240920696e75,0x5f5f5f69646e6557,0x6c616e7265746e69,0x31325f666c61685f\n"
".quad 0x744c240a3b385f30,0x38393838345f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c37363220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34333639365f335f,0x3309636f6c2e090a,0x0a30093834350931\n"
".quad 0x3436662e73626109,0x3234336466250920,0x3b3238646625202c,0x36662e766f6d090a\n"
".quad 0x3433646625092034,0x6666376430202c33,0x3030303030303030,0x2f093b3030303030\n"
".quad 0x73090a666e69202f,0x662e656c2e707465,0x3534702509203436,0x323433646625202c\n"
".quad 0x333433646625202c,0x3534702540090a3b,0x4c24092061726220,0x313035375f335f74\n"
".quad 0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c37363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x662e646461090a34,0x3364662509203436,0x38646625202c3434,0x3238646625202c32\n"
".quad 0x662e67656e090a3b,0x3164662509203436,0x33646625202c3432,0x617262090a3b3434\n"
".quad 0x4c240920696e752e,0x5f5f69646e655744,0x616e7265746e695f,0x325f666c61685f6c\n"
".quad 0x4c240a3b385f3031,0x313035375f335f74,0x6c3c2f2f200a3a30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333639365f335f74,0x662e766f6d090a34,0x3364662509203436\n"
".quad 0x30306430202c3534,0x3030303030303030,0x093b303030303030,0x6573090a30202f2f\n"
".quad 0x36662e71652e7074,0x2c36347025092034,0x2c35303364662520,0x3b35343364662520\n"
".quad 0x363470252140090a,0x4c24092061726220,0x323535375f335f74,0x6c3c2f2f200a3b32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333639365f335f74,0x662e766f6d090a34\n"
".quad 0x3164662509203436,0x66666430202c3432,0x3030303030303066,0x093b303030303030\n"
".quad 0x0a666e692d202f2f,0x696e752e61726209,0x6e6557444c240920,0x746e695f5f5f6964\n"
".quad 0x61685f6c616e7265,0x385f3031325f666c,0x5f335f744c240a3b,0x200a3a3232353537\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c373632,0x656c6562616c2064,0x5f335f744c242064,0x6d090a3433363936\n"
".quad 0x09203436662e766f,0x202c363433646625,0x3030306666376430,0x3030303030303030\n"
".quad 0x69202f2f093b3030,0x70746573090a666e,0x203436662e71652e,0x25202c3734702509\n"
".quad 0x25202c3530336466,0x090a3b3634336466,0x6220373470252140,0x5f744c2409206172\n"
".quad 0x3b34333036375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34333639365f33,0x3436662e766f6d09,0x3432316466250920,0x353033646625202c\n"
".quad 0x752e617262090a3b,0x57444c240920696e,0x695f5f5f69646e65,0x5f6c616e7265746e\n"
".quad 0x3031325f666c6168,0x5f744c240a3b385f,0x3a34333036375f33,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33,0x3436662e766f6d09\n"
".quad 0x3432316466250920,0x386666666430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x4c240a6e616e2d20,0x5f5f69646e655744,0x616e7265746e695f,0x325f666c61685f6c\n"
".quad 0x2f200a3a385f3031,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420\n"
".quad 0x6c2e090a34333639,0x323109393109636f,0x766f6d090a300938,0x662509203436662e\n"
".quad 0x646625202c373264,0x7262090a3b343231,0x240920696e752e61,0x3930375f335f744c\n"
".quad 0x5f744c240a3b3431,0x3a30373131375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09,0x090a300932393409\n"
".quad 0x203436622e766f6d,0x2c38363172257b09,0x202c7d3936317225,0x0a3b363332646625\n"
".quad 0x3233732e766f6d09,0x202c363272250920,0x090a3b3936317225,0x09313309636f6c2e\n"
".quad 0x6d090a3009333934,0x09203436622e766f,0x72252c373272257b,0x6625202c7d303731\n"
".quad 0x2e090a3b36333264,0x3409313309636f6c,0x6f6d090a30093539,0x2509203436662e76\n"
".quad 0x30202c3734336466,0x3030303030303064,0x3030303030303030,0x0a30202f2f093b30\n"
".quad 0x2e74672e74657309,0x203436662e323375,0x202c313731722509,0x202c363332646625\n"
".quad 0x0a3b373433646625,0x3233732e67656e09,0x2c32373172250920,0x0a3b313731722520\n"
".quad 0x3436662e766f6d09,0x3834336466250920,0x306666376430202c,0x3030303030303030\n"
".quad 0x2f2f093b30303030,0x6573090a666e6920,0x3233752e746c2e74,0x722509203436662e\n"
".quad 0x646625202c333731,0x646625202c363332,0x656e090a3b383433,0x2509203233732e67\n"
".quad 0x7225202c34373172,0x6e61090a3b333731,0x2509203233622e64,0x7225202c35373172\n"
".quad 0x317225202c323731,0x766f6d090a3b3437,0x722509203233752e,0x0a3b30202c363731\n"
".quad 0x71652e7074657309,0x702509203233732e,0x37317225202c3834,0x3637317225202c35\n"
".quad 0x3834702540090a3b,0x4c24092061726220,0x333430355f335f74,0x6c3c2f2f200a3b34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x333639365f335f74,0x752e766f6d090a34\n"
".quad 0x3731722509203233,0x3538343031202c37,0x746573090a3b3537,0x3233752e74672e70\n"
".quad 0x202c393470250920,0x25202c3936317225,0x40090a3b37373172,0x6172622039347025\n"
".quad 0x5f335f744c240920,0x200a3b3230383637,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c373632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x2e090a3433363936,0x3509313309636f6c,0x6f6d090a30093130\n"
".quad 0x2509203436662e76,0x30202c3934336466,0x3030303035333464,0x3030303030303030\n"
".quad 0x2e31202f2f093b30,0x312b653434313038,0x662e6c756d090a36,0x3364662509203436\n"
".quad 0x32646625202c3035,0x33646625202c3633,0x766f6d090a3b3934,0x257b09203436622e\n"
".quad 0x3272252c38373172,0x33646625202c7d36,0x6f6c2e090a3b3035,0x3230350931330963\n"
".quad 0x2e766f6d090a3009,0x72257b0920343662,0x39373172252c3732,0x3533646625202c7d\n"
".quad 0x2e766f6d090a3b30,0x3372250920323373,0x373730312d202c38,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b36343536375f33,0x375f335f744c240a,0x2f200a3a32303836\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203233732e76,0x30312d202c383372,0x5f744c240a3b3332,0x3a36343536375f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3736322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33\n"
".quad 0x313309636f6c2e09,0x090a300937303509,0x203233732e726873,0x202c303831722509\n"
".quad 0x3032202c36327225,0x732e646461090a3b,0x3833722509203233,0x202c38337225202c\n"
".quad 0x090a3b3038317225,0x09313309636f6c2e,0x61090a3009393035,0x09203233622e646e\n"
".quad 0x7225202c30347225,0x3431322d202c3632,0x3b33373035333436,0x3233622e726f090a\n"
".quad 0x202c313472250920,0x3031202c30347225,0x3834323339363237,0x622e766f6d090a3b\n"
".quad 0x3364662509203436,0x373272257b202c35,0x0a3b7d313472252c,0x3233752e766f6d09\n"
".quad 0x2c31383172250920,0x3732313337303120,0x6573090a3b323835,0x33752e656c2e7074\n"
".quad 0x2c30357025092032,0x25202c3134722520,0x40090a3b31383172,0x6172622030357025\n"
".quad 0x5f335f744c240920,0x200a3b3835303737,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c373632,0x656c6562616c2064\n"
".quad 0x5f335f744c242064,0x2e090a3433363936,0x3509313309636f6c,0x6f6d090a30093131\n"
".quad 0x7b09203436622e76,0x72252c3238317225,0x6625202c7d333831,0x7573090a3b353364\n"
".quad 0x2509203233732e62,0x7225202c34383172,0x343031202c333831,0x6d090a3b36373538\n"
".quad 0x09203436622e766f,0x252c35383172257b,0x25202c7d36383172,0x6d090a3b35336466\n"
".quad 0x09203436622e766f,0x7b202c3533646625,0x72252c3538317225,0x2e090a3b7d343831\n"
".quad 0x3509313309636f6c,0x6461090a30093231,0x2509203233732e64,0x337225202c383372\n"
".quad 0x4c240a3b31202c38,0x353037375f335f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c37363220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x333639365f335f74,0x09636f6c2e090a34,0x3009383135093133\n"
".quad 0x36662e766f6d090a,0x3533646625092034,0x6666626430202c31,0x3030303030303030\n"
".quad 0x2f093b3030303030,0x6461090a312d202f,0x2509203436662e64,0x6625202c37336466\n"
".quad 0x646625202c353364,0x6f6d090a3b313533,0x2509203436662e76,0x30202c3235336466\n"
".quad 0x3030303066663364,0x3030303030303030,0x0a31202f2f093b30,0x3436662e64646109\n"
".quad 0x2c39336466250920,0x202c353364662520,0x0a3b323533646625,0x2e6e722e74766309\n"
".quad 0x203436662e323366,0x6625202c32662509,0x6372090a3b393364,0x786f727070612e70\n"
".quad 0x662509203233662e,0x3b326625202c3031,0x36662e747663090a,0x2509203233662e34\n"
".quad 0x6625202c30346466,0x67656e090a3b3031,0x662509203436662e,0x6625202c33353364\n"
".quad 0x6f6d090a3b393364,0x2509203436662e76,0x30202c3435336466,0x3030303066663364\n"
".quad 0x3030303030303030,0x0a31202f2f093b30,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x33646625202c3334,0x34646625202c3335,0x3533646625202c30,0x2e64616d090a3b34\n"
".quad 0x09203436662e6e72,0x25202c3434646625,0x6625202c33346466,0x646625202c333464\n"
".quad 0x64616d090a3b3334,0x203436662e6e722e,0x202c353464662509,0x25202c3434646625\n"
".quad 0x6625202c30346466,0x756d090a3b303464,0x2509203436662e6c,0x6625202c36346466\n"
".quad 0x646625202c373364,0x6f6c2e090a3b3534,0x3832350931330963,0x2e646461090a3009\n"
".quad 0x6466250920343666,0x34646625202c3734,0x3634646625202c36,0x662e6c756d090a3b\n"
".quad 0x3464662509203436,0x3734646625202c38,0x3b3734646625202c,0x36662e766f6d090a\n"
".quad 0x3533646625092034,0x6265336430202c35,0x6561336230383331,0x2f093b6531663038\n"
".quad 0x333632302e31202f,0x6d090a36302d6533,0x09203436662e766f,0x202c363533646625\n"
".quad 0x6565306465336430,0x6238613762383532,0x34202f2f093b3430,0x2d6539343633302e\n"
".quad 0x2e64616d090a3630,0x09203436662e6e72,0x202c373533646625,0x202c353533646625\n"
".quad 0x25202c3834646625,0x090a3b3635336466,0x203436662e766f6d,0x2c38353364662509\n"
".quad 0x6233666533643020,0x3632306639363632,0x202f2f093b663637,0x6534343837382e31\n"
".quad 0x64616d090a35302d,0x203436662e6e722e,0x2c39353364662509,0x2c37353364662520\n"
".quad 0x202c383464662520,0x0a3b383533646625,0x3436662e766f6d09,0x3036336466250920\n"
".quad 0x373166336430202c,0x6261396162633534,0x2f2f093b36353930,0x31383737382e3820\n"
".quad 0x616d090a35302d65,0x3436662e6e722e64,0x3136336466250920,0x393533646625202c\n"
".quad 0x2c3834646625202c,0x3b30363364662520,0x36662e766f6d090a,0x3633646625092034\n"
".quad 0x3366336430202c32,0x3164323763313763,0x2f093b3435313562,0x343030302e30202f\n"
".quad 0x6d090a3832303433,0x36662e6e722e6461,0x3633646625092034,0x3633646625202c33\n"
".quad 0x3834646625202c31,0x323633646625202c,0x662e766f6d090a3b,0x3364662509203436\n"
".quad 0x66336430202c3436,0x3239343239343236,0x093b643237656233,0x3230302e30202f2f\n"
".quad 0x6d090a3431323332,0x36662e6e722e6461,0x3633646625092034,0x3633646625202c35\n"
".quad 0x3834646625202c33,0x343633646625202c,0x662e766f6d090a3b,0x3364662509203436\n"
".quad 0x66336430202c3636,0x3939393939393938,0x093b346333613939,0x3231302e30202f2f\n"
".quad 0x722e64616d090a35,0x2509203436662e6e,0x25202c3736336466,0x25202c3536336466\n"
".quad 0x6625202c38346466,0x2e090a3b36363364,0x3509313309636f6c,0x6f6d090a30093932\n"
".quad 0x2509203436662e76,0x30202c3836336466,0x3535353562663364,0x3535353535353535\n"
".quad 0x2e30202f2f093b34,0x0a33333333333830,0x2e6e722e64616d09,0x6466250920343666\n"
".quad 0x646625202c393633,0x646625202c373633,0x33646625202c3834,0x6f6c2e090a3b3836\n"
".quad 0x3233350931330963,0x2e627573090a3009,0x6466250920343666,0x33646625202c3436\n"
".quad 0x3734646625202c37,0x662e67656e090a3b,0x3364662509203436,0x34646625202c3037\n"
".quad 0x2e646461090a3b37,0x6466250920343666,0x646625202c313733,0x36646625202c3436\n"
".quad 0x2e64616d090a3b34,0x09203436662e6e72,0x202c323733646625,0x202c303733646625\n"
".quad 0x25202c3733646625,0x090a3b3137336466,0x203436662e6c756d,0x202c383664662509\n"
".quad 0x25202c3534646625,0x090a3b3237336466,0x09313309636f6c2e,0x6d090a3009353335\n"
".quad 0x09203436662e6c75,0x202c333733646625,0x25202c3834646625,0x090a3b3936336466\n"
".quad 0x203436662e6c756d,0x202c303764662509,0x25202c3734646625,0x090a3b3337336466\n"
".quad 0x662e6e722e747663,0x09203233732e3436,0x25202c3137646625,0x6f6d090a3b383372\n"
".quad 0x2509203436662e76,0x30202c3437336466,0x3465323665663364,0x6539336166656632\n"
".quad 0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d,0x3764662509203436\n"
".quad 0x3137646625202c33,0x343733646625202c,0x3b3734646625202c,0x36662e766f6d090a\n"
".quad 0x3733646625092034,0x3763336430202c35,0x3362336539636261,0x2f093b6633303839\n"
".quad 0x303931332e32202f,0x61090a37312d6535,0x09203436662e6464,0x202c363733646625\n"
".quad 0x25202c3037646625,0x6e090a3b38366466,0x09203233732e6765,0x25202c3738317225\n"
".quad 0x7663090a3b383372,0x3436662e6e722e74,0x662509203233732e,0x7225202c37373364\n"
".quad 0x6f6d090a3b373831,0x2509203436662e76,0x30202c3837336466,0x3465323665663364\n"
".quad 0x6539336166656632,0x2e30202f2f093b66,0x090a373431333936,0x662e6e722e64616d\n"
".quad 0x3364662509203436,0x33646625202c3937,0x33646625202c3737,0x37646625202c3837\n"
".quad 0x2e627573090a3b33,0x6466250920343666,0x646625202c303833,0x646625202c393733\n"
".quad 0x627573090a3b3734,0x662509203436662e,0x6625202c31383364,0x6625202c36373364\n"
".quad 0x6d090a3b30383364,0x36662e6e722e6461,0x3833646625092034,0x3137646625202c32\n"
".quad 0x353733646625202c,0x313833646625202c,0x662e646461090a3b,0x3164662509203436\n"
".quad 0x37646625202c3636,0x3833646625202c33,0x2e617262090a3b32,0x444c240920696e75\n"
".quad 0x5f5f5f69646e6557,0x6c616e7265746e69,0x31325f666c61685f,0x744c240a3b325f30\n"
".quad 0x34333430355f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c37363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333639365f335f,0x3309636f6c2e090a,0x0a30093834350931,0x3436662e73626109\n"
".quad 0x3338336466250920,0x363332646625202c,0x662e766f6d090a3b,0x3364662509203436\n"
".quad 0x66376430202c3438,0x3030303030303066,0x093b303030303030,0x090a666e69202f2f\n"
".quad 0x2e656c2e70746573,0x3570250920343666,0x3833646625202c31,0x3833646625202c33\n"
".quad 0x35702540090a3b34,0x2409206172622031,0x3537375f335f744c,0x3c2f2f200a3b3037\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x37363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c,0x2e646461090a3433\n"
".quad 0x6466250920343666,0x646625202c363631,0x646625202c363332,0x7262090a3b363332\n"
".quad 0x240920696e752e61,0x5f69646e6557444c,0x6e7265746e695f5f,0x5f666c61685f6c61\n"
".quad 0x240a3b325f303132,0x3537375f335f744c,0x3c2f2f200a3a3037,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x37363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433,0x6466250920343666\n"
".quad 0x306430202c353833,0x3030303030303030,0x3b30303030303030,0x73090a30202f2f09\n"
".quad 0x662e71652e707465,0x3235702509203436,0x363332646625202c,0x353833646625202c\n"
".quad 0x3570252140090a3b,0x2409206172622032,0x3038375f335f744c,0x3c2f2f200a3b3238\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x37363220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433\n"
".quad 0x6466250920343666,0x666430202c363631,0x3030303030306666,0x3b30303030303030\n"
".quad 0x666e692d202f2f09,0x6e752e617262090a,0x6557444c24092069,0x6e695f5f5f69646e\n"
".quad 0x685f6c616e726574,0x5f3031325f666c61,0x335f744c240a3b32,0x0a3a32383038375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c37363220,0x6c6562616c206461,0x335f744c24206465,0x090a34333639365f\n"
".quad 0x203436662e766f6d,0x2c36383364662509,0x3030666637643020,0x3030303030303030\n"
".quad 0x202f2f093b303030,0x746573090a666e69,0x3436662e71652e70,0x202c333570250920\n"
".quad 0x202c363332646625,0x0a3b363833646625,0x2033357025214009,0x744c240920617262\n"
".quad 0x34393538375f335f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c37363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333639365f335f,0x36662e766f6d090a,0x3631646625092034,0x3332646625202c36\n"
".quad 0x2e617262090a3b36,0x444c240920696e75,0x5f5f5f69646e6557,0x6c616e7265746e69\n"
".quad 0x31325f666c61685f,0x744c240a3b325f30,0x34393538375f335f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c37363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333639365f335f,0x36662e766f6d090a\n"
".quad 0x3631646625092034,0x6666666430202c36,0x3030303030303038,0x2f093b3030303030\n"
".quad 0x240a6e616e2d202f,0x5f69646e6557444c,0x6e7265746e695f5f,0x5f666c61685f6c61\n"
".quad 0x200a3a325f303132,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c373632,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3433363936,0x3409313309636f6c,0x656e090a30093239,0x2509203436662e67\n"
".quad 0x25202c3738336466,0x090a3b3636316466,0x203436622e766f6d,0x2c38383172257b09\n"
".quad 0x202c7d3938317225,0x0a3b373833646625,0x3233732e766f6d09,0x202c363272250920\n"
".quad 0x090a3b3938317225,0x09313309636f6c2e,0x6d090a3009333934,0x09203436622e766f\n"
".quad 0x72252c373272257b,0x6625202c7d303931,0x2e090a3b37383364,0x3409313309636f6c\n"
".quad 0x6f6d090a30093539,0x2509203436662e76,0x30202c3838336466,0x3030303030303064\n"
".quad 0x3030303030303030,0x0a30202f2f093b30,0x2e74672e74657309,0x203436662e323375\n"
".quad 0x202c313931722509,0x202c373833646625,0x0a3b383833646625,0x3233732e67656e09\n"
".quad 0x2c32393172250920,0x0a3b313931722520,0x3436662e766f6d09,0x3938336466250920\n"
".quad 0x306666376430202c,0x3030303030303030,0x2f2f093b30303030,0x6573090a666e6920\n"
".quad 0x3233752e746c2e74,0x722509203436662e,0x646625202c333931,0x646625202c373833\n"
".quad 0x656e090a3b393833,0x2509203233732e67,0x7225202c34393172,0x6e61090a3b333931\n"
".quad 0x2509203233622e64,0x7225202c35393172,0x317225202c323931,0x766f6d090a3b3439\n"
".quad 0x722509203233752e,0x0a3b30202c363931,0x71652e7074657309,0x702509203233732e\n"
".quad 0x39317225202c3435,0x3639317225202c35,0x3435702540090a3b,0x4c24092061726220\n"
".quad 0x373931355f335f74,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c37363220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x333639365f335f74,0x752e766f6d090a34,0x3931722509203233,0x3538343031202c37\n"
".quad 0x746573090a3b3537,0x3233752e74672e70,0x202c353570250920,0x25202c3938317225\n"
".quad 0x40090a3b37393172,0x6172622035357025,0x5f335f744c240920,0x200a3b3236333937\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c373632,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433363936\n"
".quad 0x3509313309636f6c,0x6f6d090a30093130,0x2509203436662e76,0x30202c3039336466\n"
".quad 0x3030303035333464,0x3030303030303030,0x2e31202f2f093b30,0x312b653434313038\n"
".quad 0x662e6c756d090a36,0x3364662509203436,0x33646625202c3139,0x33646625202c3738\n"
".quad 0x766f6d090a3b3039,0x257b09203436622e,0x3272252c38393172,0x33646625202c7d36\n"
".quad 0x6f6c2e090a3b3139,0x3230350931330963,0x2e766f6d090a3009,0x72257b0920343662\n"
".quad 0x39393172252c3732,0x3933646625202c7d,0x2e766f6d090a3b31,0x3372250920323373\n"
".quad 0x373730312d202c38,0x752e617262090a3b,0x5f744c240920696e,0x3b36303139375f33\n"
".quad 0x375f335f744c240a,0x2f200a3a32363339,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3736,0x64656c6562616c20\n"
".quad 0x365f335f744c2420,0x6f6d090a34333639,0x2509203233732e76,0x30312d202c383372\n"
".quad 0x5f744c240a3b3332,0x3a36303139375f33,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x313309636f6c2e09,0x090a300937303509\n"
".quad 0x203233732e726873,0x202c303032722509,0x3032202c36327225,0x732e646461090a3b\n"
".quad 0x3833722509203233,0x202c38337225202c,0x090a3b3030327225,0x09313309636f6c2e\n"
".quad 0x61090a3009393035,0x09203233622e646e,0x7225202c30347225,0x3431322d202c3632\n"
".quad 0x3b33373035333436,0x3233622e726f090a,0x202c313472250920,0x3031202c30347225\n"
".quad 0x3834323339363237,0x622e766f6d090a3b,0x3364662509203436,0x373272257b202c35\n"
".quad 0x0a3b7d313472252c,0x3233752e766f6d09,0x2c31303272250920,0x3732313337303120\n"
".quad 0x6573090a3b323835,0x33752e656c2e7074,0x2c36357025092032,0x25202c3134722520\n"
".quad 0x40090a3b31303272,0x6172622036357025,0x5f335f744c240920,0x200a3b3831363937\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c373632,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3433363936\n"
".quad 0x3509313309636f6c,0x6f6d090a30093131,0x7b09203436622e76,0x72252c3230327225\n"
".quad 0x6625202c7d333032,0x7573090a3b353364,0x2509203233732e62,0x7225202c34303272\n"
".quad 0x343031202c333032,0x6d090a3b36373538,0x09203436622e766f,0x252c35303272257b\n"
".quad 0x25202c7d36303272,0x6d090a3b35336466,0x09203436622e766f,0x7b202c3533646625\n"
".quad 0x72252c3530327225,0x2e090a3b7d343032,0x3509313309636f6c,0x6461090a30093231\n"
".quad 0x2509203233732e64,0x337225202c383372,0x4c240a3b31202c38,0x313639375f335f74\n"
".quad 0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c37363220656e69,0x616c206461656820,0x4c242064656c6562,0x333639365f335f74\n"
".quad 0x09636f6c2e090a34,0x3009383135093133,0x36662e766f6d090a,0x3933646625092034\n"
".quad 0x6666626430202c32,0x3030303030303030,0x2f093b3030303030,0x6461090a312d202f\n"
".quad 0x2509203436662e64,0x6625202c37336466,0x646625202c353364,0x6f6d090a3b323933\n"
".quad 0x2509203436662e76,0x30202c3339336466,0x3030303066663364,0x3030303030303030\n"
".quad 0x0a31202f2f093b30,0x3436662e64646109,0x2c39336466250920,0x202c353364662520\n"
".quad 0x0a3b333933646625,0x2e6e722e74766309,0x203436662e323366,0x6625202c32662509\n"
".quad 0x6372090a3b393364,0x786f727070612e70,0x662509203233662e,0x3b326625202c3131\n"
".quad 0x36662e747663090a,0x2509203233662e34,0x6625202c30346466,0x67656e090a3b3131\n"
".quad 0x662509203436662e,0x6625202c34393364,0x6f6d090a3b393364,0x2509203436662e76\n"
".quad 0x30202c3539336466,0x3030303066663364,0x3030303030303030,0x0a31202f2f093b30\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x33646625202c3334,0x34646625202c3439\n"
".quad 0x3933646625202c30,0x2e64616d090a3b35,0x09203436662e6e72,0x25202c3434646625\n"
".quad 0x6625202c33346466,0x646625202c333464,0x64616d090a3b3334,0x203436662e6e722e\n"
".quad 0x202c353464662509,0x25202c3434646625,0x6625202c30346466,0x756d090a3b303464\n"
".quad 0x2509203436662e6c,0x6625202c36346466,0x646625202c373364,0x6f6c2e090a3b3534\n"
".quad 0x3832350931330963,0x2e646461090a3009,0x6466250920343666,0x34646625202c3734\n"
".quad 0x3634646625202c36,0x662e6c756d090a3b,0x3464662509203436,0x3734646625202c38\n"
".quad 0x3b3734646625202c,0x36662e766f6d090a,0x3933646625092034,0x6265336430202c36\n"
".quad 0x6561336230383331,0x2f093b6531663038,0x333632302e31202f,0x6d090a36302d6533\n"
".quad 0x09203436662e766f,0x202c373933646625,0x6565306465336430,0x6238613762383532\n"
".quad 0x34202f2f093b3430,0x2d6539343633302e,0x2e64616d090a3630,0x09203436662e6e72\n"
".quad 0x202c383933646625,0x202c363933646625,0x25202c3834646625,0x090a3b3739336466\n"
".quad 0x203436662e766f6d,0x2c39393364662509,0x6233666533643020,0x3632306639363632\n"
".quad 0x202f2f093b663637,0x6534343837382e31,0x64616d090a35302d,0x203436662e6e722e\n"
".quad 0x2c30303464662509,0x2c38393364662520,0x202c383464662520,0x0a3b393933646625\n"
".quad 0x3436662e766f6d09,0x3130346466250920,0x373166336430202c,0x6261396162633534\n"
".quad 0x2f2f093b36353930,0x31383737382e3820,0x616d090a35302d65,0x3436662e6e722e64\n"
".quad 0x3230346466250920,0x303034646625202c,0x2c3834646625202c,0x3b31303464662520\n"
".quad 0x36662e766f6d090a,0x3034646625092034,0x3366336430202c33,0x3164323763313763\n"
".quad 0x2f093b3435313562,0x343030302e30202f,0x6d090a3832303433,0x36662e6e722e6461\n"
".quad 0x3034646625092034,0x3034646625202c34,0x3834646625202c32,0x333034646625202c\n"
".quad 0x662e766f6d090a3b,0x3464662509203436,0x66336430202c3530,0x3239343239343236\n"
".quad 0x093b643237656233,0x3230302e30202f2f,0x6d090a3431323332,0x36662e6e722e6461\n"
".quad 0x3034646625092034,0x3034646625202c36,0x3834646625202c34,0x353034646625202c\n"
".quad 0x662e766f6d090a3b,0x3464662509203436,0x66336430202c3730,0x3939393939393938\n"
".quad 0x093b346333613939,0x3231302e30202f2f,0x722e64616d090a35,0x2509203436662e6e\n"
".quad 0x25202c3830346466,0x25202c3630346466,0x6625202c38346466,0x2e090a3b37303464\n"
".quad 0x3509313309636f6c,0x6f6d090a30093932,0x2509203436662e76,0x30202c3930346466\n"
".quad 0x3535353562663364,0x3535353535353535,0x2e30202f2f093b34,0x0a33333333333830\n"
".quad 0x2e6e722e64616d09,0x6466250920343666,0x646625202c303134,0x646625202c383034\n"
".quad 0x34646625202c3834,0x6f6c2e090a3b3930,0x3233350931330963,0x2e627573090a3009\n"
".quad 0x6466250920343666,0x33646625202c3436,0x3734646625202c37,0x662e67656e090a3b\n"
".quad 0x3464662509203436,0x34646625202c3131,0x2e646461090a3b37,0x6466250920343666\n"
".quad 0x646625202c323134,0x36646625202c3436,0x2e64616d090a3b34,0x09203436662e6e72\n"
".quad 0x202c333134646625,0x202c313134646625,0x25202c3733646625,0x090a3b3231346466\n"
".quad 0x203436662e6c756d,0x202c383664662509,0x25202c3534646625,0x090a3b3331346466\n"
".quad 0x09313309636f6c2e,0x6d090a3009353335,0x09203436662e6c75,0x202c343134646625\n"
".quad 0x25202c3834646625,0x090a3b3031346466,0x203436662e6c756d,0x202c303764662509\n"
".quad 0x25202c3734646625,0x090a3b3431346466,0x662e6e722e747663,0x09203233732e3436\n"
".quad 0x25202c3137646625,0x6f6d090a3b383372,0x2509203436662e76,0x30202c3531346466\n"
".quad 0x3465323665663364,0x6539336166656632,0x2e30202f2f093b66,0x090a373431333936\n"
".quad 0x662e6e722e64616d,0x3764662509203436,0x3137646625202c33,0x353134646625202c\n"
".quad 0x3b3734646625202c,0x36662e766f6d090a,0x3134646625092034,0x3763336430202c36\n"
".quad 0x3362336539636261,0x2f093b6633303839,0x303931332e32202f,0x61090a37312d6535\n"
".quad 0x09203436662e6464,0x202c373134646625,0x25202c3037646625,0x6e090a3b38366466\n"
".quad 0x09203233732e6765,0x25202c3730327225,0x7663090a3b383372,0x3436662e6e722e74\n"
".quad 0x662509203233732e,0x7225202c38313464,0x6f6d090a3b373032,0x2509203436662e76\n"
".quad 0x30202c3931346466,0x3465323665663364,0x6539336166656632,0x2e30202f2f093b66\n"
".quad 0x090a373431333936,0x662e6e722e64616d,0x3464662509203436,0x34646625202c3032\n"
".quad 0x34646625202c3831,0x37646625202c3931,0x2e627573090a3b33,0x6466250920343666\n"
".quad 0x646625202c313234,0x646625202c303234,0x627573090a3b3734,0x662509203436662e\n"
".quad 0x6625202c32323464,0x6625202c37313464,0x6d090a3b31323464,0x36662e6e722e6461\n"
".quad 0x3234646625092034,0x3137646625202c33,0x363134646625202c,0x323234646625202c\n"
".quad 0x662e646461090a3b,0x3264662509203436,0x37646625202c3830,0x3234646625202c33\n"
".quad 0x2e617262090a3b33,0x444c240920696e75,0x5f5f5f69646e6557,0x6c616e7265746e69\n"
".quad 0x31325f666c61685f,0x744c240a3b345f30,0x30373931355f335f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c37363220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34333639365f335f,0x3309636f6c2e090a\n"
".quad 0x0a30093834350931,0x3436662e73626109,0x3432346466250920,0x363631646625202c\n"
".quad 0x662e766f6d090a3b,0x3464662509203436,0x66376430202c3532,0x3030303030303066\n"
".quad 0x093b303030303030,0x090a666e69202f2f,0x2e656c2e70746573,0x3570250920343666\n"
".quad 0x3234646625202c37,0x3234646625202c34,0x35702540090a3b35,0x2409206172622037\n"
".quad 0x3130385f335f744c,0x3c2f2f200a3b3033,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x37363220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3639365f335f744c,0x2e646461090a3433,0x6466250920343666,0x646625202c363234\n"
".quad 0x646625202c363631,0x656e090a3b363631,0x2509203436662e67,0x25202c3830326466\n"
".quad 0x090a3b3632346466,0x20696e752e617262,0x646e6557444c2409,0x65746e695f5f5f69\n"
".quad 0x6c61685f6c616e72,0x3b345f3031325f66,0x385f335f744c240a,0x2f200a3a30333130\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420,0x6f6d090a34333639\n"
".quad 0x2509203436662e76,0x30202c3732346466,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x71652e7074657309,0x702509203436662e,0x33646625202c3835\n"
".quad 0x34646625202c3738,0x252140090a3b3732,0x2061726220383570,0x385f335f744c2409\n"
".quad 0x2f200a3b32343630,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3736,0x64656c6562616c20,0x365f335f744c2420\n"
".quad 0x6f6d090a34333639,0x2509203436662e76,0x30202c3830326466,0x3030303066666664\n"
".quad 0x3030303030303030,0x692d202f2f093b30,0x2e617262090a666e,0x444c240920696e75\n"
".quad 0x5f5f5f69646e6557,0x6c616e7265746e69,0x31325f666c61685f,0x744c240a3b345f30\n"
".quad 0x32343630385f335f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c37363220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34333639365f335f,0x36662e766f6d090a,0x3234646625092034,0x6666376430202c38\n"
".quad 0x3030303030303030,0x2f093b3030303030,0x73090a666e69202f,0x662e71652e707465\n"
".quad 0x3935702509203436,0x373833646625202c,0x383234646625202c,0x3570252140090a3b\n"
".quad 0x2409206172622039,0x3131385f335f744c,0x3c2f2f200a3b3435,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x37363220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3639365f335f744c,0x2e766f6d090a3433,0x6466250920343666\n"
".quad 0x646625202c383032,0x7262090a3b373833,0x240920696e752e61,0x5f69646e6557444c\n"
".quad 0x6e7265746e695f5f,0x5f666c61685f6c61,0x240a3b345f303132,0x3131385f335f744c\n"
".quad 0x3c2f2f200a3a3435,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x37363220656e696c,0x6c2064616568202c,0x242064656c656261,0x3639365f335f744c\n"
".quad 0x2e766f6d090a3433,0x6466250920343666,0x666430202c383032,0x3030303030386666\n"
".quad 0x3b30303030303030,0x6e616e2d202f2f09,0x646e6557444c240a,0x65746e695f5f5f69\n"
".quad 0x6c61685f6c616e72,0x3a345f3031325f66,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x393109636f6c2e09,0x090a300930333109\n"
".quad 0x203436662e766f6d,0x202c373264662509,0x0a3b383032646625,0x30375f335f744c24\n"
".quad 0x2f2f200a3a343139,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x363220656e696c20,0x2064616568202c37,0x2064656c6562616c,0x39365f335f744c24\n"
".quad 0x6f6c2e090a343336,0x3233310939310963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x336430202c393234,0x6332333939356466,0x3b64363330346533,0x33332e30202f2f09\n"
".quad 0x6f6d090a35373437,0x2509203436662e76,0x30202c3033346466,0x6363336665663364\n"
".quad 0x3331636238666336,0x2e30202f2f093b31,0x090a393631363739,0x203436662e766f6d\n"
".quad 0x2c31333464662509,0x3934636633643020,0x3039363632373035,0x202f2f093b363836\n"
".quad 0x3839373036312e30,0x36662e766f6d090a,0x3334646625092034,0x3966336430202c32\n"
".quad 0x6533376461653463,0x2f093b3733323434,0x363732302e30202f,0x766f6d090a393334\n"
".quad 0x662509203436662e,0x6430202c33333464,0x3334363766366633,0x3538373665333565\n"
".quad 0x302e30202f2f093b,0x0a37353034383330,0x3436662e766f6d09,0x3433346466250920\n"
".quad 0x393366336430202c,0x3961306165323665,0x2f2f093b36343838,0x39333030302e3020\n"
".quad 0x766f6d090a393135,0x662509203436662e,0x6430202c35333464,0x3262656430306633\n"
".quad 0x3830323835663530,0x322e33202f2f093b,0x35302d6538363731,0x36662e766f6d090a\n"
".quad 0x3334646625092034,0x3965336430202c36,0x3930373564313633,0x2f093b3635623762\n"
".quad 0x313838382e32202f,0x6d090a37302d6537,0x09203436662e766f,0x202c373334646625\n"
".quad 0x3339613965336430,0x3564323061303563,0x33202f2f093b6461,0x2d6532333036392e\n"
".quad 0x2e64616d090a3730,0x09203436662e6e72,0x202c383334646625,0x202c373334646625\n"
".quad 0x25202c3732646625,0x090a3b3633346466,0x662e6e722e64616d,0x3464662509203436\n"
".quad 0x32646625202c3933,0x3334646625202c37,0x3334646625202c38,0x2e64616d090a3b35\n"
".quad 0x09203436662e6e72,0x202c303434646625,0x25202c3732646625,0x25202c3933346466\n"
".quad 0x090a3b3433346466,0x662e6e722e64616d,0x3464662509203436,0x32646625202c3134\n"
".quad 0x3434646625202c37,0x3334646625202c30,0x2e64616d090a3b33,0x09203436662e6e72\n"
".quad 0x202c323434646625,0x25202c3732646625,0x25202c3134346466,0x090a3b3233346466\n"
".quad 0x662e6e722e64616d,0x3464662509203436,0x32646625202c3334,0x3434646625202c37\n"
".quad 0x3334646625202c32,0x2e64616d090a3b31,0x09203436662e6e72,0x202c343434646625\n"
".quad 0x25202c3732646625,0x25202c3334346466,0x090a3b3033346466,0x662e6e722e64616d\n"
".quad 0x3464662509203436,0x32646625202c3534,0x3434646625202c37,0x3234646625202c34\n"
".quad 0x2e67656e090a3b39,0x6466250920343666,0x646625202c363434,0x6f6d090a3b353434\n"
".quad 0x2509203436662e76,0x30202c3734346466,0x3030303030303064,0x3030303030303030\n"
".quad 0x0a30202f2f093b30,0x746c2e7074657309,0x702509203436662e,0x32646625202c3036\n"
".quad 0x34646625202c3134,0x6c6573090a3b3734,0x2509203436662e70,0x6625202c37326466\n"
".quad 0x6625202c36343464,0x7025202c35343464,0x5f744c240a3b3036,0x3a32303430375f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3736322065,0x6562616c20646165,0x5f744c242064656c,0x0a34333639365f33\n"
".quad 0x3436662e766f6d09,0x3933326466250920,0x3b3732646625202c,0x646e6557444c240a\n"
".quad 0x6469766964665f69,0x3a315f3031325f65,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3736322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34333639365f33,0x393109636f6c2e09,0x090a300939363209\n"
".quad 0x662e6e722e747663,0x09203436662e3233,0x6625202c32316625,0x73090a3b39333264\n"
".quad 0x6c61626f6c672e74,0x255b09203233662e,0x2c5d302b37313172,0x090a3b3231662520\n"
".quad 0x203233752e646461,0x202c313131722509,0x25202c3531317225,0x61090a3b31313172\n"
".quad 0x09203233752e6464,0x25202c3731317225,0x7225202c37313172,0x6573090a3b393131\n"
".quad 0x33752e746c2e7074,0x2c31367025092032,0x202c373131722520,0x090a3b3831317225\n"
".quad 0x7262203136702540,0x335f744c24092061,0x0a3b34333639365f,0x39365f335f744c24\n"
".quad 0x744c240a3a323231,0x30313835355f335f,0x09636f6c2e090a3a,0x3009323732093931\n"
".quad 0x0a3b74697865090a,0x5f646e6557444c24,0x65766e6936315a5f,0x654b444e43657372\n"
".quad 0x5f5366506c656e72,0x2f2f207d090a3a6a,0x766e6936315a5f20,0x4b444e4365737265\n"
".quad 0x5366506c656e7265,0x000000000a0a6a5f\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_13$[9886];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"6a1a38ed576c0cee",(char*)"/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x084011c2,&__elfEntries1};
# 2 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2
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
# 3 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2
struct __T20 {__TOptionValue *__par0;float *__par1;int __par2;int __dummy_field;};
struct __T21 {float *__par0;int __par1;int __dummy_field;};
struct __T22 {__TOptionValue *__par0;int __par1;int __dummy_field;};
struct __T23 {float *__par0;float *__par1;unsigned __par2;int __dummy_field;};
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *, float *, int);
static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi(float *, int);
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei(__TOptionValue *, int);
static void __device_stub__Z16inverseCNDKernelPfS_j(float *, float *, unsigned);
static void __sti____cudaRegisterAll_50_tmpxft_000022bd_00000000_4_MonteCarlo_SM13_cpp1_ii_9123f87d(void) __attribute__((__constructor__));
static void __device_stub__Z16MonteCarloKernelP14__TOptionValuePfi(__TOptionValue *__par0, float *__par1, int __par2){ struct __T20 *__T24;
*(void**)(void*)&__T24 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel))); };}
static void MonteCarloKernel( __TOptionValue *__cuda_0,float *__cuda_1,int __cuda_2)
# 113 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
{__device_stub__Z16MonteCarloKernelP14__TOptionValuePfi( __cuda_0,__cuda_1,__cuda_2);
# 136 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z27MonteCarloOneBlockPerOptionPfi( float *__par0, int __par1) { struct __T21 *__T25;
*(void**)(void*)&__T25 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T25->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T25->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption)); (void)cudaLaunch(((char *)((void ( *)(float *, int))MonteCarloOneBlockPerOption))); }; }
static void MonteCarloOneBlockPerOption( float *__cuda_0,int __cuda_1)
# 150 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
{__device_stub__Z27MonteCarloOneBlockPerOptionPfi( __cuda_0,__cuda_1);
# 183 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z16MonteCarloReduceP14__TOptionValuei( __TOptionValue *__par0, int __par1) { struct __T22 *__T26;
*(void**)(void*)&__T26 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T26->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T26->__par1) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce)); (void)cudaLaunch(((char *)((void ( *)(__TOptionValue *, int))MonteCarloReduce))); }; }
static void MonteCarloReduce( __TOptionValue *__cuda_0,int __cuda_1)
# 194 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
{__device_stub__Z16MonteCarloReduceP14__TOptionValuei( __cuda_0,__cuda_1);
# 220 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh"
}
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __device_stub__Z16inverseCNDKernelPfS_j( float *__par0, float *__par1, unsigned __par2) { struct __T23 *__T233;
*(void**)(void*)&__T233 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T233->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T233->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T233->__par2) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, unsigned))inverseCNDKernel))); }; }
static void inverseCNDKernel( float *__cuda_0,float *__cuda_1,unsigned __cuda_2)
# 252 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
{__device_stub__Z16inverseCNDKernelPfS_j( __cuda_0,__cuda_1,__cuda_2);
# 272 "/home/normal/checkout/gpuocelot/tests/cuda2.2/tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh"
}
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c"
static void __sti____cudaRegisterAll_50_tmpxft_000022bd_00000000_4_MonteCarlo_SM13_cpp1_ii_9123f87d(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, unsigned))inverseCNDKernel), (char*)"_Z16inverseCNDKernelPfS_j", "_Z16inverseCNDKernelPfS_j", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, int))MonteCarloReduce), (char*)"_Z16MonteCarloReduceP14__TOptionValuei", "_Z16MonteCarloReduceP14__TOptionValuei", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, int))MonteCarloOneBlockPerOption), (char*)"_Z27MonteCarloOneBlockPerOptionPfi", "_Z27MonteCarloOneBlockPerOptionPfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(__TOptionValue *, float *, int))MonteCarloKernel), (char*)"_Z16MonteCarloKernelP14__TOptionValuePfi", "_Z16MonteCarloKernelP14__TOptionValuePfi", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_OptionData, (char*)"d_OptionData", "d_OptionData", 0, 65536, 1, 0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&d_CallValue, (char*)"d_CallValue", "d_CallValue", 0, 32768, 0, 0); }
# 1 "/tmp/tmpxft_000022bd_00000000-1_MonteCarlo_SM13.cudafe1.stub.c" 2

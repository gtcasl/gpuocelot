# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.cpp"
# 1 "bisect_large.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 3
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
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stddef.h" 2 3
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
# 44 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 49 "/usr/include/string.h" 3
extern "C" void *memmove(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 57 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 65 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
# 68 "/usr/include/string.h" 3
extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 75 "/usr/include/string.h" 3
extern void *memchr(void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 77 "/usr/include/string.h" 3
extern const void *memchr(const void *, int, size_t) throw() __asm__("memchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 104 "/usr/include/string.h" 3
void *rawmemchr(void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 106 "/usr/include/string.h" 3
const void *rawmemchr(const void *, int) throw() __asm__("rawmemchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 115 "/usr/include/string.h" 3
void *memrchr(void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 117 "/usr/include/string.h" 3
const void *memrchr(const void *, int, size_t) throw() __asm__("memrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 128 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 131 "/usr/include/string.h" 3
extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 136 "/usr/include/string.h" 3
extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 139 "/usr/include/string.h" 3
extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 143 "/usr/include/string.h" 3
extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 146 "/usr/include/string.h" 3
extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 150 "/usr/include/string.h" 3
extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 153 "/usr/include/string.h" 3
extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(2)));
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef
# 28 "/usr/include/xlocale.h" 3
struct __locale_struct {
# 31 "/usr/include/xlocale.h" 3
struct __locale_data *__locales[13];
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
# 165 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 168 "/usr/include/string.h" 3
extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 175 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__)) __attribute__((nonnull(1)));
# 183 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__)) __attribute__((nonnull(1)));
# 215 "/usr/include/string.h" 3
extern char *strchr(char *, int) throw() __asm__("strchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 217 "/usr/include/string.h" 3
extern const char *strchr(const char *, int) throw() __asm__("strchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 242 "/usr/include/string.h" 3
extern char *strrchr(char *, int) throw() __asm__("strrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 244 "/usr/include/string.h" 3
extern const char *strrchr(const char *, int) throw() __asm__("strrchr") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 271 "/usr/include/string.h" 3
char *strchrnul(char *, int) throw() __asm__("strchrnul") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 273 "/usr/include/string.h" 3
const char *strchrnul(const char *, int) throw() __asm__("strchrnul") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 284 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 288 "/usr/include/string.h" 3
extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 294 "/usr/include/string.h" 3
extern char *strpbrk(char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 296 "/usr/include/string.h" 3
extern const char *strpbrk(const char *, const char *) throw() __asm__("strpbrk") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 321 "/usr/include/string.h" 3
extern char *strstr(char *, const char *) throw() __asm__("strstr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 323 "/usr/include/string.h" 3
extern const char *strstr(const char *, const char *) throw() __asm__("strstr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 348 "/usr/include/string.h" 3
extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(2)));
# 354 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 359 "/usr/include/string.h" 3
extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 367 "/usr/include/string.h" 3
char *strcasestr(char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 369 "/usr/include/string.h" 3
const char *strcasestr(const char *, const char *) throw() __asm__("strcasestr") __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 382 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(3)));
# 388 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 391 "/usr/include/string.h" 3
extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 399 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 406 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1)));
# 413 "/usr/include/string.h" 3
extern "C" char *strerror(int) throw();
# 438 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 445 "/usr/include/string.h" 3
extern "C" char *strerror_l(int, __locale_t) throw();
# 451 "/usr/include/string.h" 3
extern "C" void __bzero(void *, size_t) throw() __attribute__((nonnull(1)));
# 455 "/usr/include/string.h" 3
extern "C" void bcopy(const void *, void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 459 "/usr/include/string.h" 3
extern "C" void bzero(void *, size_t) throw() __attribute__((nonnull(1)));
# 462 "/usr/include/string.h" 3
extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 469 "/usr/include/string.h" 3
extern char *index(char *, int) throw() __asm__("index") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 471 "/usr/include/string.h" 3
extern const char *index(const char *, int) throw() __asm__("index") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 497 "/usr/include/string.h" 3
extern char *rindex(char *, int) throw() __asm__("rindex") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 499 "/usr/include/string.h" 3
extern const char *rindex(const char *, int) throw() __asm__("rindex") __attribute__((__pure__)) __attribute__((nonnull(1)));
# 523 "/usr/include/string.h" 3
extern "C" int ffs(int) throw() __attribute__((__const__));
# 528 "/usr/include/string.h" 3
extern "C" int ffsl(long) throw() __attribute__((__const__));
# 530 "/usr/include/string.h" 3
extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 536 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 540 "/usr/include/string.h" 3
extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 547 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 551 "/usr/include/string.h" 3
extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(4)));
# 559 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 566 "/usr/include/string.h" 3
extern "C" char *strsignal(int) throw();
# 569 "/usr/include/string.h" 3
extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 571 "/usr/include/string.h" 3
extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 576 "/usr/include/string.h" 3
extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 579 "/usr/include/string.h" 3
extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 586 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 590 "/usr/include/string.h" 3
extern "C" char *strfry(char *) throw() __attribute__((nonnull(1)));
# 593 "/usr/include/string.h" 3
extern "C" void *memfrob(void *, size_t) throw() __attribute__((nonnull(1)));
# 601 "/usr/include/string.h" 3
char *basename(char *) throw() __asm__("basename") __attribute__((nonnull(1)));
# 603 "/usr/include/string.h" 3
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
# 34 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
# 35 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_short u_short; }
# 36 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_int u_int; }
# 37 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_long u_long; }
# 38 "/usr/include/sys/types.h" 3
extern "C" { typedef __quad_t quad_t; }
# 39 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_quad_t u_quad_t; }
# 40 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsid_t fsid_t; }
# 45 "/usr/include/sys/types.h" 3
extern "C" { typedef __loff_t loff_t; }
# 49 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino_t ino_t; }
# 56 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino64_t ino64_t; }
# 61 "/usr/include/sys/types.h" 3
extern "C" { typedef __dev_t dev_t; }
# 66 "/usr/include/sys/types.h" 3
extern "C" { typedef __gid_t gid_t; }
# 71 "/usr/include/sys/types.h" 3
extern "C" { typedef __mode_t mode_t; }
# 76 "/usr/include/sys/types.h" 3
extern "C" { typedef __nlink_t nlink_t; }
# 81 "/usr/include/sys/types.h" 3
extern "C" { typedef __uid_t uid_t; }
# 87 "/usr/include/sys/types.h" 3
extern "C" { typedef __off_t off_t; }
# 94 "/usr/include/sys/types.h" 3
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
# 75 "/usr/include/bits/time.h" 3
extern "C" { struct timeval {
# 77 "/usr/include/bits/time.h" 3
__time_t tv_sec;
# 78 "/usr/include/bits/time.h" 3
__suseconds_t tv_usec;
# 79 "/usr/include/bits/time.h" 3
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
# 229 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 236 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt_t blkcnt_t; }
# 240 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }
# 244 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 263 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
# 264 "/usr/include/sys/types.h" 3
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
# 265 "/usr/include/sys/types.h" 3
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
# 503 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__));
# 508 "/usr/include/stdlib.h" 3
extern "C" int posix_memalign(void **, size_t, size_t) throw() __attribute__((nonnull(1)));
# 514 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute__((__noreturn__));
# 518 "/usr/include/stdlib.h" 3
extern "C" int atexit(void (*)(void)) throw() __attribute__((nonnull(1)));
# 525 "/usr/include/stdlib.h" 3
int at_quick_exit(void (*)(void)) throw() __asm__("at_quick_exit") __attribute__((nonnull(1)));
# 536 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw() __attribute__((nonnull(1)));
# 544 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 552 "/usr/include/stdlib.h" 3
extern "C" void quick_exit(int) throw() __attribute__((__noreturn__));
# 560 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 567 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw() __attribute__((nonnull(1)));
# 572 "/usr/include/stdlib.h" 3
extern "C" char *__secure_getenv(const char *) throw() __attribute__((nonnull(1)));
# 579 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw() __attribute__((nonnull(1)));
# 585 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw() __attribute__((nonnull(2)));
# 589 "/usr/include/stdlib.h" 3
extern "C" int unsetenv(const char *) throw() __attribute__((nonnull(1)));
# 596 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 606 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *) throw() __attribute__((nonnull(1)));
# 620 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *) __attribute__((nonnull(1)));
# 630 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *) __attribute__((nonnull(1)));
# 642 "/usr/include/stdlib.h" 3
extern "C" int mkstemps(char *, int) __attribute__((nonnull(1)));
# 652 "/usr/include/stdlib.h" 3
extern "C" int mkstemps64(char *, int) __attribute__((nonnull(1)));
# 663 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw() __attribute__((nonnull(1)));
# 674 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int) __attribute__((nonnull(1)));
# 684 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int) __attribute__((nonnull(1)));
# 694 "/usr/include/stdlib.h" 3
extern "C" int mkostemps(char *, int, int) __attribute__((nonnull(1)));
# 706 "/usr/include/stdlib.h" 3
extern "C" int mkostemps64(char *, int, int) __attribute__((nonnull(1)));
# 717 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 724 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw() __attribute__((nonnull(1)));
# 734 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 742 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 745 "/usr/include/stdlib.h" 3
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 749 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_d_fn_t)(const void *, const void *, void *); }
# 755 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(5)));
# 761 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 764 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, __compar_d_fn_t, void *) __attribute__((nonnull(1))) __attribute__((nonnull(4)));
# 771 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 772 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 776 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 785 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));
# 787 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 793 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 808 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 814 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 820 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw() __attribute__((nonnull(3)));
# 826 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 829 "/usr/include/stdlib.h" 3
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4)));
# 832 "/usr/include/stdlib.h" 3
extern "C" char *qgcvt(long double, int, char *) throw() __attribute__((nonnull(3)));
# 838 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 841 "/usr/include/stdlib.h" 3
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 845 "/usr/include/stdlib.h" 3
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 849 "/usr/include/stdlib.h" 3
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5)));
# 860 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();
# 863 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 867 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t) throw();
# 871 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();
# 874 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 885 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw() __attribute__((nonnull(1)));
# 896 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3)));
# 905 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw() __attribute__((nonnull(1)));
# 913 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 921 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();
# 925 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int) throw();
# 930 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int) throw();
# 937 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw() __attribute__((nonnull(2)));
# 941 "/usr/include/stdlib.h" 3
extern "C" int getpt();
# 948 "/usr/include/stdlib.h" 3
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.5/include/stdarg.h" 3
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
# 111 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos_t fpos_t; }
# 117 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 165 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; }
# 166 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdout; }
# 167 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stderr; }
# 175 "/usr/include/stdio.h" 3
extern "C" int remove(const char *) throw();
# 177 "/usr/include/stdio.h" 3
extern "C" int rename(const char *, const char *) throw();
# 182 "/usr/include/stdio.h" 3
extern "C" int renameat(int, const char *, int, const char *) throw();
# 192 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 202 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64();
# 206 "/usr/include/stdio.h" 3
extern "C" char *tmpnam(char *) throw();
# 212 "/usr/include/stdio.h" 3
extern "C" char *tmpnam_r(char *) throw();
# 224 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__));
# 234 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE *);
# 239 "/usr/include/stdio.h" 3
extern "C" int fflush(FILE *);
# 249 "/usr/include/stdio.h" 3
extern "C" int fflush_unlocked(FILE *);
# 259 "/usr/include/stdio.h" 3
extern "C" int fcloseall();
# 269 "/usr/include/stdio.h" 3
extern "C" FILE *fopen(const char *__restrict__, const char *__restrict__);
# 275 "/usr/include/stdio.h" 3
extern "C" FILE *freopen(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 294 "/usr/include/stdio.h" 3
extern "C" FILE *fopen64(const char *__restrict__, const char *__restrict__);
# 296 "/usr/include/stdio.h" 3
extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 303 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int, const char *) throw();
# 309 "/usr/include/stdio.h" 3
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw();
# 316 "/usr/include/stdio.h" 3
extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 322 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 329 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();
# 333 "/usr/include/stdio.h" 3
extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 340 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();
# 344 "/usr/include/stdio.h" 3
extern "C" void setlinebuf(FILE *) throw();
# 353 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 359 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);
# 361 "/usr/include/stdio.h" 3
extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 368 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 374 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list);
# 376 "/usr/include/stdio.h" 3
extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 383 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();
# 387 "/usr/include/stdio.h" 3
extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 396 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 399 "/usr/include/stdio.h" 3
extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 402 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 414 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);
# 417 "/usr/include/stdio.h" 3
extern "C" int dprintf(int, const char *__restrict__, ...);
# 427 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 433 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);
# 435 "/usr/include/stdio.h" 3
extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 473 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 481 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);
# 485 "/usr/include/stdio.h" 3
extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 533 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
# 534 "/usr/include/stdio.h" 3
extern "C" int getc(FILE *);
# 540 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 552 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
# 553 "/usr/include/stdio.h" 3
extern "C" int getchar_unlocked();
# 563 "/usr/include/stdio.h" 3
extern "C" int fgetc_unlocked(FILE *);
# 575 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
# 576 "/usr/include/stdio.h" 3
extern "C" int putc(int, FILE *);
# 582 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 596 "/usr/include/stdio.h" 3
extern "C" int fputc_unlocked(int, FILE *);
# 604 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
# 605 "/usr/include/stdio.h" 3
extern "C" int putchar_unlocked(int);
# 612 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);
# 615 "/usr/include/stdio.h" 3
extern "C" int putw(int, FILE *);
# 624 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 632 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 642 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 658 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 661 "/usr/include/stdio.h" 3
extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 671 "/usr/include/stdio.h" 3
extern "C" __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__);
# 682 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 688 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 695 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 702 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 708 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 719 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 730 "/usr/include/stdio.h" 3
extern "C" size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 732 "/usr/include/stdio.h" 3
extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 742 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);
# 747 "/usr/include/stdio.h" 3
extern "C" long ftell(FILE *);
# 752 "/usr/include/stdio.h" 3
extern "C" void rewind(FILE *);
# 766 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);
# 771 "/usr/include/stdio.h" 3
extern "C" __off_t ftello(FILE *);
# 791 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);
# 796 "/usr/include/stdio.h" 3
extern "C" int fsetpos(FILE *, const fpos_t *);
# 811 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int);
# 812 "/usr/include/stdio.h" 3
extern "C" __off64_t ftello64(FILE *);
# 813 "/usr/include/stdio.h" 3
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__);
# 814 "/usr/include/stdio.h" 3
extern "C" int fsetpos64(FILE *, const fpos64_t *);
# 819 "/usr/include/stdio.h" 3
extern "C" void clearerr(FILE *) throw();
# 821 "/usr/include/stdio.h" 3
extern "C" int feof(FILE *) throw();
# 823 "/usr/include/stdio.h" 3
extern "C" int ferror(FILE *) throw();
# 828 "/usr/include/stdio.h" 3
extern "C" void clearerr_unlocked(FILE *) throw();
# 829 "/usr/include/stdio.h" 3
extern "C" int feof_unlocked(FILE *) throw();
# 830 "/usr/include/stdio.h" 3
extern "C" int ferror_unlocked(FILE *) throw();
# 839 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
# 28 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const sys_errlist[]; }
# 31 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int _sys_nerr; }
# 32 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern const char *const _sys_errlist[]; }
# 851 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();
# 856 "/usr/include/stdio.h" 3
extern "C" int fileno_unlocked(FILE *) throw();
# 866 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 872 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 878 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 884 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);
# 889 "/usr/include/stdio.h" 3
struct obstack;
# 892 "/usr/include/stdio.h" 3
extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();
# 895 "/usr/include/stdio.h" 3
extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 906 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();
# 910 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE *) throw();
# 913 "/usr/include/stdio.h" 3
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
# 41 "structs.h"
struct InputData {
# 44 "structs.h"
float *a;
# 46 "structs.h"
float *b;
# 49 "structs.h"
float *g_a;
# 51 "structs.h"
float *g_b;
# 54 "structs.h"
float *g_b_raw;
# 56 "structs.h"
};
# 58 "structs.h"
struct ResultDataSmall {
# 61 "structs.h"
float *eigenvalues;
# 64 "structs.h"
float *g_left;
# 67 "structs.h"
float *g_right;
# 70 "structs.h"
unsigned *g_left_count;
# 73 "structs.h"
unsigned *g_right_count;
# 76 "structs.h"
unsigned *g_converged;
# 80 "structs.h"
unsigned mat_size_f;
# 81 "structs.h"
unsigned mat_size_ui;
# 83 "structs.h"
float *zero_f;
# 84 "structs.h"
unsigned *zero_ui;
# 85 "structs.h"
};
# 88 "structs.h"
struct ResultDataLarge {
# 91 "structs.h"
unsigned *g_num_one;
# 95 "structs.h"
unsigned *g_num_blocks_mult;
# 99 "structs.h"
float *g_left_one;
# 103 "structs.h"
float *g_right_one;
# 107 "structs.h"
unsigned *g_pos_one;
# 111 "structs.h"
float *g_left_mult;
# 115 "structs.h"
float *g_right_mult;
# 119 "structs.h"
unsigned *g_left_count_mult;
# 123 "structs.h"
unsigned *g_right_count_mult;
# 127 "structs.h"
unsigned *g_blocks_mult;
# 131 "structs.h"
unsigned *g_blocks_mult_sum;
# 135 "structs.h"
float *g_lambda_mult;
# 139 "structs.h"
unsigned *g_pos_mult;
# 141 "structs.h"
};
# 44 "util.h"
template<class T> inline void
# 46 "util.h"
freePtr(T *&ptr) {
# 48 "util.h"
if (__null != ptr) {
# 49 "util.h"
free(ptr);
# 50 "util.h"
ptr = __null;
# 51 "util.h"
}
# 52 "util.h"
}
# 57 "util.h"
template<class T> T
# 62 "util.h"
min(const T &lhs, const T &rhs) {
# 64 "util.h"
return (lhs < rhs) ? lhs : rhs;
# 65 "util.h"
}
# 70 "util.h"
template<class T> T
# 75 "util.h"
max(const T &lhs, const T &rhs) {
# 77 "util.h"
return (lhs < rhs) ? rhs : lhs;
# 78 "util.h"
}
# 83 "util.h"
template<class T> T
# 88 "util.h"
sign_i(const T &val) {
# 89 "util.h"
return (val < 0) ? (-1) : 1;
# 90 "util.h"
}
# 99 "util.h"
inline float sign_f(const float &val) {
# 100 "util.h"
return (val < (0.0F)) ? (-(1.0F)) : (1.0F);
# 101 "util.h"
}
# 110 "util.h"
inline double sign_d(const double &val) {
# 111 "util.h"
return (val < (0.0)) ? (-(1.0)) : (1.0);
# 112 "util.h"
}
# 117 "util.h"
template<class T> void
# 122 "util.h"
swap(T &lhs, T &rhs) {
# 124 "util.h"
T temp = rhs;
# 125 "util.h"
rhs = lhs;
# 126 "util.h"
lhs = temp;
# 127 "util.h"
}
# 136 "util.h"
extern "C" { inline unsigned getNumBlocksLinear(const unsigned num_threads, const unsigned
# 137 "util.h"
num_threads_block)
# 138 "util.h"
{
# 139 "util.h"
const unsigned block_rem = (((num_threads % num_threads_block) != (0)) ? 1 : 0);
# 141 "util.h"
return (num_threads / num_threads_block) + block_rem;
# 142 "util.h"
} }
# 64 "matlab.h"
extern "C" void writeTridiagSymMatlab(const char *, float *, float *, float *, const unsigned);
# 76 "matlab.h"
template<class T, class S> void writeMatrixMatlab(T &, const char *, S *&, const unsigned);
# 88 "matlab.h"
template<class T, class S> void writeVectorMatlab(T &, const char *, S *&, const unsigned);
# 102 "matlab.h"
template<class T, class S> void
# 104 "matlab.h"
writeMatrixMatlab(T &file, const char *mat_name, S *&
# 105 "matlab.h"
mat, const unsigned mat_size) {
# 107 "matlab.h"
const unsigned pitch = (sizeof(S) * mat_size);
# 109 "matlab.h"
(file << mat_name) << " = [";
# 110 "matlab.h"
for (unsigned i = (0); i < mat_size; ++i) {
# 111 "matlab.h"
for (unsigned j = (0); j < mat_size; ++j) {
# 113 "matlab.h"
(file << getMatrix(mat, pitch, i, j)) << " ";
# 114 "matlab.h"
}
# 115 "matlab.h"
if (i != (mat_size - (1))) {
# 116 "matlab.h"
file << "; ";
# 117 "matlab.h"
}
# 118 "matlab.h"
}
# 119 "matlab.h"
file << "];\n";
# 120 "matlab.h"
}
# 129 "matlab.h"
template<class T, class S> void
# 131 "matlab.h"
writeVectorMatlab(T &file, const char *vec_name, S *&
# 132 "matlab.h"
vec, const unsigned vec_len)
# 133 "matlab.h"
{
# 134 "matlab.h"
(file << vec_name) << " = [";
# 135 "matlab.h"
for (unsigned i = (0); i < vec_len; ++i) {
# 136 "matlab.h"
(file << (vec[i])) << " ";
# 137 "matlab.h"
}
# 138 "matlab.h"
file << "];\n";
# 139 "matlab.h"
}
# 54 "bisect_large.cuh"
extern "C" void computeEigenvaluesLargeMatrix(const InputData &, const ResultDataLarge &, const unsigned, const float, const float, const float, const unsigned);
# 65 "bisect_large.cuh"
extern "C" void initResultDataLargeMatrix(ResultDataLarge &, const unsigned);
# 72 "bisect_large.cuh"
extern "C" void cleanupResultDataLargeMatrix(ResultDataLarge &);
# 83 "bisect_large.cuh"
extern "C" void processResultDataLargeMatrix(const InputData &, const ResultDataLarge &, const unsigned, const char *, const unsigned, char *);
# 51 "bisect_util.cu"
__attribute__((unused)) inline int floorPow2(int n) {int volatile ___ = 1;
# 61 "bisect_util.cu"
exit(___);}
# 69 "bisect_util.cu"
__attribute__((unused)) inline int ceilPow2(int n) {int volatile ___ = 1;
# 79 "bisect_util.cu"
exit(___);}
# 89 "bisect_util.cu"
__attribute__((unused)) float computeMidpoint(const float left, const float right) {int volatile ___ = 1;
# 100 "bisect_util.cu"
exit(___);}
# 117 "bisect_util.cu"
template<class S, class T> __attribute__((unused)) void
# 120 "bisect_util.cu"
storeInterval(unsigned addr, float *
# 121 "bisect_util.cu"
s_left, float *s_right, T *
# 122 "bisect_util.cu"
s_left_count, T *s_right_count, float
# 123 "bisect_util.cu"
left, float right, S
# 124 "bisect_util.cu"
left_count, S right_count, float
# 125 "bisect_util.cu"
precision)
# 126 "bisect_util.cu"
{int volatile ___ = 1;
# 148 "bisect_util.cu"
exit(___);}
# 170 "bisect_util.cu"
__attribute__((unused)) unsigned computeNumSmallerEigenvals(float *g_d, float *g_s, const unsigned n, const float
# 171 "bisect_util.cu"
x, const unsigned
# 172 "bisect_util.cu"
tid, const unsigned
# 173 "bisect_util.cu"
num_intervals_active, float *
# 174 "bisect_util.cu"
s_d, float *s_s, unsigned
# 175 "bisect_util.cu"
converged)
# 177 "bisect_util.cu"
{int volatile ___ = 1;
# 205 "bisect_util.cu"
exit(___);}
# 227 "bisect_util.cu"
__attribute__((unused)) unsigned computeNumSmallerEigenvalsLarge(float *g_d, float *g_s, const unsigned n, const float
# 228 "bisect_util.cu"
x, const unsigned
# 229 "bisect_util.cu"
tid, const unsigned
# 230 "bisect_util.cu"
num_intervals_active, float *
# 231 "bisect_util.cu"
s_d, float *s_s, unsigned
# 232 "bisect_util.cu"
converged)
# 234 "bisect_util.cu"
{int volatile ___ = 1;
# 271 "bisect_util.cu"
exit(___);}
# 298 "bisect_util.cu"
template<class S, class T> __attribute__((unused)) void
# 301 "bisect_util.cu"
storeNonEmptyIntervals(unsigned addr, const unsigned
# 302 "bisect_util.cu"
num_threads_active, float *
# 303 "bisect_util.cu"
s_left, float *s_right, T *
# 304 "bisect_util.cu"
s_left_count, T *s_right_count, float
# 305 "bisect_util.cu"
left, float mid, float right, const S
# 306 "bisect_util.cu"
left_count, const S
# 307 "bisect_util.cu"
mid_count, const S
# 308 "bisect_util.cu"
right_count, float
# 309 "bisect_util.cu"
precision, unsigned &
# 310 "bisect_util.cu"
compact_second_chunk, T *
# 311 "bisect_util.cu"
s_compaction_list_exc, unsigned &
# 312 "bisect_util.cu"
is_active_second)
# 313 "bisect_util.cu"
{int volatile ___ = 1;
# 346 "bisect_util.cu"
exit(___);}
# 357 "bisect_util.cu"
template<class T> __attribute__((unused)) void
# 360 "bisect_util.cu"
createIndicesCompaction(T *s_compaction_list_exc, unsigned
# 361 "bisect_util.cu"
num_threads_compaction) {int volatile ___ = 1;
# 404 "bisect_util.cu"
exit(___);}
# 423 "bisect_util.cu"
template<class T> __attribute__((unused)) void
# 426 "bisect_util.cu"
compactIntervals(float *s_left, float *s_right, T *
# 427 "bisect_util.cu"
s_left_count, T *s_right_count, float
# 428 "bisect_util.cu"
mid, float right, unsigned
# 429 "bisect_util.cu"
mid_count, unsigned right_count, T *
# 430 "bisect_util.cu"
s_compaction_list, unsigned
# 431 "bisect_util.cu"
num_threads_active, unsigned
# 432 "bisect_util.cu"
is_active_second)
# 433 "bisect_util.cu"
{int volatile ___ = 1;
# 447 "bisect_util.cu"
exit(___);}
# 470 "bisect_util.cu"
template<class T, class S> __attribute__((unused)) void
# 473 "bisect_util.cu"
storeIntervalConverged(float *s_left, float *s_right, T *
# 474 "bisect_util.cu"
s_left_count, T *s_right_count, float &
# 475 "bisect_util.cu"
left, float &mid, float &right, S &
# 476 "bisect_util.cu"
left_count, S &mid_count, S &right_count, T *
# 477 "bisect_util.cu"
s_compaction_list_exc, unsigned &
# 478 "bisect_util.cu"
compact_second_chunk, const unsigned
# 479 "bisect_util.cu"
num_threads_active)
# 480 "bisect_util.cu"
{int volatile ___ = 1;
# 515 "bisect_util.cu"
exit(___);}
# 517 "bisect_util.cu"
template<class T, class S> __attribute__((unused)) void
# 520 "bisect_util.cu"
storeIntervalConverged(float *s_left, float *s_right, T *
# 521 "bisect_util.cu"
s_left_count, T *s_right_count, float &
# 522 "bisect_util.cu"
left, float &mid, float &right, S &
# 523 "bisect_util.cu"
left_count, S &mid_count, S &right_count, T *
# 524 "bisect_util.cu"
s_compaction_list_exc, unsigned &
# 525 "bisect_util.cu"
compact_second_chunk, const unsigned
# 526 "bisect_util.cu"
num_threads_active, unsigned &
# 527 "bisect_util.cu"
is_active_second)
# 528 "bisect_util.cu"
{int volatile ___ = 1;
# 563 "bisect_util.cu"
exit(___);}
# 582 "bisect_util.cu"
template<class T> __attribute__((unused)) void
# 585 "bisect_util.cu"
subdivideActiveInterval(const unsigned tid, float *
# 586 "bisect_util.cu"
s_left, float *s_right, T *
# 587 "bisect_util.cu"
s_left_count, T *s_right_count, const unsigned
# 588 "bisect_util.cu"
num_threads_active, float &
# 589 "bisect_util.cu"
left, float &right, unsigned &
# 590 "bisect_util.cu"
left_count, unsigned &right_count, float &
# 591 "bisect_util.cu"
mid, unsigned &all_threads_converged)
# 592 "bisect_util.cu"
{int volatile ___ = 1;
# 614 "bisect_util.cu"
exit(___);}
# 55 "bisect_kernel_large.cu"
__attribute__((unused)) void writeToGmem(const unsigned, const unsigned, const unsigned, const unsigned, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, float *, float *, unsigned short *, unsigned short *, unsigned *, unsigned *, unsigned short *, unsigned short *, unsigned);
# 77 "bisect_kernel_large.cu"
__attribute__((unused)) void compactStreamsFinal(const unsigned, const unsigned, const unsigned, unsigned &, float *, float *, unsigned short *, unsigned short *, unsigned short *&, unsigned short *&, unsigned short *&, unsigned short *, unsigned, unsigned, float &, float &, float &, float &, unsigned &, unsigned &, unsigned &, unsigned &, unsigned, unsigned, unsigned, unsigned);
# 97 "bisect_kernel_large.cu"
__attribute__((unused)) void scanCompactBlocksStartAddress(const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *);
# 108 "bisect_kernel_large.cu"
__attribute__((unused)) void scanSumBlocks(const unsigned, const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *);
# 121 "bisect_kernel_large.cu"
__attribute__((unused)) void scanInitial(const unsigned, const unsigned, const unsigned, const unsigned, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
# 135 "bisect_kernel_large.cu"
__attribute__((unused)) void storeNonEmptyIntervalsLarge(unsigned, const unsigned, float *, float *, unsigned short *, unsigned short *, float, float, float, const unsigned short, const unsigned short, const unsigned short, float, unsigned &, unsigned short *, unsigned &);
# 164 "bisect_kernel_large.cu"
void bisectKernelLarge(float *g_d, float *g_s, const unsigned n, const float
# 165 "bisect_kernel_large.cu"
lg, const float ug, const unsigned
# 166 "bisect_kernel_large.cu"
lg_eig_count, const unsigned
# 167 "bisect_kernel_large.cu"
ug_eig_count, float
# 168 "bisect_kernel_large.cu"
epsilon, unsigned *
# 169 "bisect_kernel_large.cu"
g_num_one, unsigned *
# 170 "bisect_kernel_large.cu"
g_num_blocks_mult, float *
# 171 "bisect_kernel_large.cu"
g_left_one, float *g_right_one, unsigned *
# 172 "bisect_kernel_large.cu"
g_pos_one, float *
# 173 "bisect_kernel_large.cu"
g_left_mult, float *g_right_mult, unsigned *
# 174 "bisect_kernel_large.cu"
g_left_count_mult, unsigned *
# 175 "bisect_kernel_large.cu"
g_right_count_mult, unsigned *
# 176 "bisect_kernel_large.cu"
g_blocks_mult, unsigned *
# 177 "bisect_kernel_large.cu"
g_blocks_mult_sum) ;
# 528 "bisect_kernel_large.cu"
__attribute__((unused)) void writeToGmem(const unsigned tid, const unsigned tid_2, const unsigned
# 529 "bisect_kernel_large.cu"
num_threads_active, const unsigned
# 530 "bisect_kernel_large.cu"
num_blocks_mult, float *
# 531 "bisect_kernel_large.cu"
g_left_one, float *g_right_one, unsigned *
# 532 "bisect_kernel_large.cu"
g_pos_one, float *
# 533 "bisect_kernel_large.cu"
g_left_mult, float *g_right_mult, unsigned *
# 534 "bisect_kernel_large.cu"
g_left_count_mult, unsigned *
# 535 "bisect_kernel_large.cu"
g_right_count_mult, float *
# 536 "bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 537 "bisect_kernel_large.cu"
s_left_count, unsigned short *s_right_count, unsigned *
# 538 "bisect_kernel_large.cu"
g_blocks_mult, unsigned *
# 539 "bisect_kernel_large.cu"
g_blocks_mult_sum, unsigned short *
# 540 "bisect_kernel_large.cu"
s_compaction_list, unsigned short *
# 541 "bisect_kernel_large.cu"
s_cl_helper, unsigned
# 542 "bisect_kernel_large.cu"
offset_mult_lambda)
# 543 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 589 "bisect_kernel_large.cu"
exit(___);}
# 596 "bisect_kernel_large.cu"
__attribute__((unused)) void compactStreamsFinal(const unsigned tid, const unsigned tid_2, const unsigned
# 597 "bisect_kernel_large.cu"
num_threads_active, unsigned &
# 598 "bisect_kernel_large.cu"
offset_mult_lambda, float *
# 599 "bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 600 "bisect_kernel_large.cu"
s_left_count, unsigned short *s_right_count, unsigned short *&
# 601 "bisect_kernel_large.cu"
s_cl_one, unsigned short *&s_cl_mult, unsigned short *&
# 602 "bisect_kernel_large.cu"
s_cl_blocking, unsigned short *s_cl_helper, unsigned
# 603 "bisect_kernel_large.cu"
is_one_lambda, unsigned is_one_lambda_2, float &
# 604 "bisect_kernel_large.cu"
left, float &right, float &left_2, float &right_2, unsigned &
# 605 "bisect_kernel_large.cu"
left_count, unsigned &right_count, unsigned &
# 606 "bisect_kernel_large.cu"
left_count_2, unsigned &right_count_2, unsigned
# 607 "bisect_kernel_large.cu"
c_block_iend, unsigned c_sum_block, unsigned
# 608 "bisect_kernel_large.cu"
c_block_iend_2, unsigned c_sum_block_2)
# 610 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 673 "bisect_kernel_large.cu"
exit(___);}
# 680 "bisect_kernel_large.cu"
__attribute__((unused)) void scanCompactBlocksStartAddress(const unsigned tid, const unsigned tid_2, const unsigned
# 681 "bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 682 "bisect_kernel_large.cu"
s_cl_blocking, unsigned short *
# 683 "bisect_kernel_large.cu"
s_cl_helper)
# 685 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 732 "bisect_kernel_large.cu"
exit(___);}
# 739 "bisect_kernel_large.cu"
__attribute__((unused)) void scanSumBlocks(const unsigned tid, const unsigned tid_2, const unsigned
# 740 "bisect_kernel_large.cu"
num_threads_active, const unsigned
# 741 "bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 742 "bisect_kernel_large.cu"
s_cl_blocking, unsigned short *
# 743 "bisect_kernel_large.cu"
s_cl_helper)
# 744 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 792 "bisect_kernel_large.cu"
exit(___);}
# 800 "bisect_kernel_large.cu"
__attribute__((unused)) void scanInitial(const unsigned tid, const unsigned tid_2, const unsigned
# 801 "bisect_kernel_large.cu"
num_threads_active, const unsigned
# 802 "bisect_kernel_large.cu"
num_threads_compaction, unsigned short *
# 803 "bisect_kernel_large.cu"
s_cl_one, unsigned short *s_cl_mult, unsigned short *
# 804 "bisect_kernel_large.cu"
s_cl_blocking, unsigned short *s_cl_helper)
# 806 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 886 "bisect_kernel_large.cu"
exit(___);}
# 894 "bisect_kernel_large.cu"
__attribute__((unused)) void storeNonEmptyIntervalsLarge(unsigned addr, const unsigned
# 895 "bisect_kernel_large.cu"
num_threads_active, float *
# 896 "bisect_kernel_large.cu"
s_left, float *s_right, unsigned short *
# 897 "bisect_kernel_large.cu"
s_left_count, unsigned short *
# 898 "bisect_kernel_large.cu"
s_right_count, float
# 899 "bisect_kernel_large.cu"
left, float mid, float right, const unsigned short
# 900 "bisect_kernel_large.cu"
left_count, const unsigned short
# 901 "bisect_kernel_large.cu"
mid_count, const unsigned short
# 902 "bisect_kernel_large.cu"
right_count, float
# 903 "bisect_kernel_large.cu"
epsilon, unsigned &
# 904 "bisect_kernel_large.cu"
compact_second_chunk, unsigned short *
# 905 "bisect_kernel_large.cu"
s_compaction_list, unsigned &
# 906 "bisect_kernel_large.cu"
is_active_second)
# 907 "bisect_kernel_large.cu"
{int volatile ___ = 1;
# 936 "bisect_kernel_large.cu"
exit(___);}
# 66 "bisect_kernel_large_onei.cu"
void bisectKernelLarge_OneIntervals(float *g_d, float *g_s, const unsigned n, unsigned
# 67 "bisect_kernel_large_onei.cu"
num_intervals, float *
# 68 "bisect_kernel_large_onei.cu"
g_left, float *g_right, unsigned *
# 69 "bisect_kernel_large_onei.cu"
g_pos, float
# 70 "bisect_kernel_large_onei.cu"
precision) ;
# 71 "bisect_kernel_large_multi.cu"
void bisectKernelLarge_MultIntervals(float *g_d, float *g_s, const unsigned n, unsigned *
# 72 "bisect_kernel_large_multi.cu"
blocks_mult, unsigned *
# 73 "bisect_kernel_large_multi.cu"
blocks_mult_sum, float *
# 74 "bisect_kernel_large_multi.cu"
g_left, float *g_right, unsigned *
# 75 "bisect_kernel_large_multi.cu"
g_left_count, unsigned *
# 76 "bisect_kernel_large_multi.cu"
g_right_count, float *
# 77 "bisect_kernel_large_multi.cu"
g_lambda, unsigned *g_pos, float
# 78 "bisect_kernel_large_multi.cu"
precision) ;
# 66 "bisect_large.cu"
void initResultDataLargeMatrix(ResultDataLarge &result, const unsigned mat_size) {
# 69 "bisect_large.cu"
unsigned zero = (0);
# 70 "bisect_large.cu"
unsigned mat_size_f = (sizeof(float) * mat_size);
# 71 "bisect_large.cu"
unsigned mat_size_ui = (sizeof(unsigned) * mat_size);
# 73 "bisect_large.cu"
float *tempf = ((float *)malloc(mat_size_f));
# 74 "bisect_large.cu"
unsigned *tempui = ((unsigned *)malloc(mat_size_ui));
# 75 "bisect_large.cu"
for (unsigned i = (0); i < mat_size; ++i) {
# 76 "bisect_large.cu"
(tempf[i]) = (0.0F);
# 77 "bisect_large.cu"
(tempui[i]) = (0);
# 78 "bisect_large.cu"
}
# 81 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_num_one)), sizeof(unsigned)), "bisect_large.cu", 82);
# 83 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_num_one, &zero, sizeof(unsigned), cudaMemcpyHostToDevice), "bisect_large.cu", 84);
# 88 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_num_blocks_mult)), sizeof(unsigned)), "bisect_large.cu", 89);
# 90 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_num_blocks_mult, &zero, sizeof(unsigned), cudaMemcpyHostToDevice), "bisect_large.cu", 92);
# 95 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_one)), mat_size_f), "bisect_large.cu", 95);
# 96 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_one)), mat_size_f), "bisect_large.cu", 96);
# 97 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_pos_one)), mat_size_ui), "bisect_large.cu", 97);
# 99 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_mult)), mat_size_f), "bisect_large.cu", 99);
# 100 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_mult)), mat_size_f), "bisect_large.cu", 100);
# 101 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_left_count_mult)), mat_size_ui), "bisect_large.cu", 102);
# 103 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_right_count_mult)), mat_size_ui), "bisect_large.cu", 104);
# 106 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_one, tempf, mat_size_f, cudaMemcpyHostToDevice), "bisect_large.cu", 107);
# 108 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_one, tempf, mat_size_f, cudaMemcpyHostToDevice), "bisect_large.cu", 109);
# 110 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_pos_one, tempui, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 111);
# 113 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "bisect_large.cu", 114);
# 115 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "bisect_large.cu", 116);
# 117 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_left_count_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 118);
# 119 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_right_count_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 120);
# 122 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_blocks_mult)), mat_size_ui), "bisect_large.cu", 122);
# 123 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_blocks_mult, tempui, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 124);
# 125 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_blocks_mult_sum)), mat_size_ui), "bisect_large.cu", 125);
# 126 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_blocks_mult_sum, tempui, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 127);
# 129 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_lambda_mult)), mat_size_f), "bisect_large.cu", 129);
# 130 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_lambda_mult, tempf, mat_size_f, cudaMemcpyHostToDevice), "bisect_large.cu", 131);
# 132 "bisect_large.cu"
__cudaSafeCall(cudaMalloc((void **)(&(result.g_pos_mult)), mat_size_ui), "bisect_large.cu", 132);
# 133 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(result.g_pos_mult, tempf, mat_size_ui, cudaMemcpyHostToDevice), "bisect_large.cu", 134);
# 135 "bisect_large.cu"
}
# 142 "bisect_large.cu"
void cleanupResultDataLargeMatrix(ResultDataLarge &result) {
# 144 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_num_one), "bisect_large.cu", 144);
# 145 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_num_blocks_mult), "bisect_large.cu", 145);
# 146 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_one), "bisect_large.cu", 146);
# 147 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_one), "bisect_large.cu", 147);
# 148 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_pos_one), "bisect_large.cu", 148);
# 149 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_mult), "bisect_large.cu", 149);
# 150 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_mult), "bisect_large.cu", 150);
# 151 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_left_count_mult), "bisect_large.cu", 151);
# 152 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_right_count_mult), "bisect_large.cu", 152);
# 153 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_blocks_mult), "bisect_large.cu", 153);
# 154 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_blocks_mult_sum), "bisect_large.cu", 154);
# 155 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_lambda_mult), "bisect_large.cu", 155);
# 156 "bisect_large.cu"
__cudaSafeCall(cudaFree(result.g_pos_mult), "bisect_large.cu", 156);
# 157 "bisect_large.cu"
}
# 170 "bisect_large.cu"
void computeEigenvaluesLargeMatrix(const InputData &input, const ResultDataLarge &result, const unsigned
# 171 "bisect_large.cu"
mat_size, const float precision, const float
# 172 "bisect_large.cu"
lg, const float ug, const unsigned
# 173 "bisect_large.cu"
iterations)
# 174 "bisect_large.cu"
{
# 175 "bisect_large.cu"
dim3 blocks(1, 1, 1);
# 176 "bisect_large.cu"
dim3 threads(256, 1, 1);
# 178 "bisect_large.cu"
unsigned timer_step1 = (0);
# 179 "bisect_large.cu"
unsigned timer_step2_one = (0);
# 180 "bisect_large.cu"
unsigned timer_step2_mult = (0);
# 181 "bisect_large.cu"
unsigned timer_total = (0);
# 182 "bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step1), "bisect_large.cu", 182);
# 183 "bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step2_one), "bisect_large.cu", 183);
# 184 "bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_step2_mult), "bisect_large.cu", 184);
# 185 "bisect_large.cu"
__cutilCheckError(cutCreateTimer(&timer_total), "bisect_large.cu", 185);
# 187 "bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_total), "bisect_large.cu", 187);
# 190 "bisect_large.cu"
for (unsigned iter = (0); iter < iterations; ++iter) {
# 192 "bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step1), "bisect_large.cu", 192);
# 193 "bisect_large.cu"
cudaConfigureCall(blocks, threads) ? ((void)0) : bisectKernelLarge(input.g_a, input.g_b, mat_size, lg, ug, 0, mat_size, precision, result.g_num_one, result.g_num_blocks_mult, result.g_left_one, result.g_right_one, result.g_pos_one, result.g_left_mult, result.g_right_mult, result.g_left_count_mult, result.g_right_count_mult, result.g_blocks_mult, result.g_blocks_mult_sum);
# 202 "bisect_large.cu"
__cudaSafeCall(cudaThreadSynchronize(), "bisect_large.cu", 202);
# 203 "bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step1), "bisect_large.cu", 203);
# 204 "bisect_large.cu"
__cutilCheckMsg("Kernel launch failed.", "bisect_large.cu", 204);
# 208 "bisect_large.cu"
unsigned num_one_intervals;
# 209 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_one_intervals, result.g_num_one, sizeof(unsigned), cudaMemcpyDeviceToHost), "bisect_large.cu", 211);
# 213 "bisect_large.cu"
dim3 grid_onei;
# 214 "bisect_large.cu"
(grid_onei.x) = getNumBlocksLinear(num_one_intervals, 256);
# 215 "bisect_large.cu"
dim3 threads_onei;
# 218 "bisect_large.cu"
(threads_onei.x) = (256);
# 222 "bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step2_one), "bisect_large.cu", 222);
# 224 "bisect_large.cu"
cudaConfigureCall(grid_onei, threads_onei) ? ((void)0) : bisectKernelLarge_OneIntervals(input.g_a, input.g_b, mat_size, num_one_intervals, result.g_left_one, result.g_right_one, result.g_pos_one, precision);
# 230 "bisect_large.cu"
__cudaSafeCall(cudaThreadSynchronize(), "bisect_large.cu", 230);
# 231 "bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step2_one), "bisect_large.cu", 231);
# 239 "bisect_large.cu"
unsigned num_blocks_mult = (0);
# 240 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_blocks_mult, result.g_num_blocks_mult, sizeof(unsigned), cudaMemcpyDeviceToHost), "bisect_large.cu", 242);
# 245 "bisect_large.cu"
dim3 grid_mult(num_blocks_mult, 1, 1);
# 246 "bisect_large.cu"
dim3 threads_mult(256, 1, 1);
# 248 "bisect_large.cu"
__cutilCheckError(cutStartTimer(timer_step2_mult), "bisect_large.cu", 248);
# 250 "bisect_large.cu"
cudaConfigureCall(grid_mult, threads_mult) ? ((void)0) : bisectKernelLarge_MultIntervals(input.g_a, input.g_b, mat_size, result.g_blocks_mult, result.g_blocks_mult_sum, result.g_left_mult, result.g_right_mult, result.g_left_count_mult, result.g_right_count_mult, result.g_lambda_mult, result.g_pos_mult, precision);
# 259 "bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_step2_mult), "bisect_large.cu", 259);
# 260 "bisect_large.cu"
__cutilCheckMsg("bisectKernelLarge_MultIntervals() FAILED.", "bisect_large.cu", 260);
# 261 "bisect_large.cu"
}
# 263 "bisect_large.cu"
__cutilCheckError(cutStopTimer(timer_total), "bisect_large.cu", 263);
# 266 "bisect_large.cu"
printf("Average time step 1: %f ms\n", cutGetTimerValue(timer_step1) / ((float)iterations));
# 268 "bisect_large.cu"
printf("Average time step 2, one intervals: %f ms\n", cutGetTimerValue(timer_step2_one) / ((float)iterations));
# 270 "bisect_large.cu"
printf("Average time step 2, mult intervals: %f ms\n", cutGetTimerValue(timer_step2_mult) / ((float)iterations));
# 273 "bisect_large.cu"
printf("Average time TOTAL: %f ms\n", cutGetTimerValue(timer_total) / ((float)iterations));
# 276 "bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step1), "bisect_large.cu", 276);
# 277 "bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step2_one), "bisect_large.cu", 277);
# 278 "bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_step2_mult), "bisect_large.cu", 278);
# 279 "bisect_large.cu"
__cutilCheckError(cutDeleteTimer(timer_total), "bisect_large.cu", 279);
# 280 "bisect_large.cu"
}
# 291 "bisect_large.cu"
void processResultDataLargeMatrix(const InputData &input, const ResultDataLarge &result, const unsigned
# 292 "bisect_large.cu"
mat_size, const char *
# 293 "bisect_large.cu"
filename, const unsigned
# 294 "bisect_large.cu"
user_defined, char *exec_path)
# 295 "bisect_large.cu"
{
# 296 "bisect_large.cu"
const unsigned mat_size_ui = (sizeof(unsigned) * mat_size);
# 297 "bisect_large.cu"
const unsigned mat_size_f = (sizeof(float) * mat_size);
# 301 "bisect_large.cu"
float *lambda_mult = ((float *)malloc(sizeof(float) * mat_size));
# 302 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(lambda_mult, result.g_lambda_mult, sizeof(float) * mat_size, cudaMemcpyDeviceToHost), "bisect_large.cu", 304);
# 305 "bisect_large.cu"
unsigned *pos_mult = ((unsigned *)malloc(sizeof(unsigned) * mat_size));
# 307 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(pos_mult, result.g_pos_mult, sizeof(unsigned) * mat_size, cudaMemcpyDeviceToHost), "bisect_large.cu", 309);
# 311 "bisect_large.cu"
unsigned *blocks_mult_sum = ((unsigned *)malloc(sizeof(unsigned) * mat_size));
# 313 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(blocks_mult_sum, result.g_blocks_mult_sum, sizeof(unsigned) * mat_size, cudaMemcpyDeviceToHost), "bisect_large.cu", 315);
# 317 "bisect_large.cu"
unsigned num_one_intervals;
# 318 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(&num_one_intervals, result.g_num_one, sizeof(unsigned), cudaMemcpyDeviceToHost), "bisect_large.cu", 320);
# 322 "bisect_large.cu"
unsigned sum_blocks_mult = (mat_size - num_one_intervals);
# 327 "bisect_large.cu"
float *left_one = ((float *)malloc(mat_size_f));
# 328 "bisect_large.cu"
float *right_one = ((float *)malloc(mat_size_f));
# 329 "bisect_large.cu"
unsigned *pos_one = ((unsigned *)malloc(mat_size_ui));
# 330 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(left_one, result.g_left_one, mat_size_f, cudaMemcpyDeviceToHost), "bisect_large.cu", 331);
# 332 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(right_one, result.g_right_one, mat_size_f, cudaMemcpyDeviceToHost), "bisect_large.cu", 333);
# 334 "bisect_large.cu"
__cudaSafeCall(cudaMemcpy(pos_one, result.g_pos_one, mat_size_ui, cudaMemcpyDeviceToHost), "bisect_large.cu", 335);
# 338 "bisect_large.cu"
float *eigenvals = ((float *)malloc(mat_size_f));
# 341 "bisect_large.cu"
for (unsigned i = (0); i < sum_blocks_mult; ++i) {
# 343 "bisect_large.cu"
(eigenvals[(pos_mult[i]) - (1)]) = (lambda_mult[i]);
# 344 "bisect_large.cu"
}
# 347 "bisect_large.cu"
unsigned index = (0);
# 348 "bisect_large.cu"
for (unsigned i = (0); i < num_one_intervals; (++i), (++index)) {
# 350 "bisect_large.cu"
(eigenvals[(pos_one[i]) - (1)]) = (left_one[i]);
# 351 "bisect_large.cu"
}
# 353 "bisect_large.cu"
if ((1) == user_defined) {
# 355 "bisect_large.cu"
writeTridiagSymMatlab(filename, input.a, (input.b) + 1, eigenvals, mat_size);
# 357 "bisect_large.cu"
} else
# 358 "bisect_large.cu"
{
# 362 "bisect_large.cu"
float *reference = (__null);
# 363 "bisect_large.cu"
unsigned input_data_size = (0);
# 365 "bisect_large.cu"
char *ref_path = cutFindFilePath("reference.dat", exec_path);
# 366 "bisect_large.cu"
__cutilCondition((0) != ref_path, (char *)("bisect_large.cu"), 366);
# 367 "bisect_large.cu"
__cutilCheckError(cutReadFilef(ref_path, &reference, &input_data_size), "bisect_large.cu", 367);
# 368 "bisect_large.cu"
__cutilCondition(input_data_size == mat_size, (char *)("bisect_large.cu"), 368);
# 372 "bisect_large.cu"
float tolerance = ((9.999999747e-06F) + (4.999999874e-06F));
# 374 "bisect_large.cu"
if ((CUTTrue) == (cutComparefe(reference, eigenvals, mat_size, tolerance))) {
# 375 "bisect_large.cu"
printf("\nTEST PASSED.\n");
# 376 "bisect_large.cu"
} else
# 377 "bisect_large.cu"
{
# 378 "bisect_large.cu"
printf("FAILED.\n");
# 379 "bisect_large.cu"
}
# 381 "bisect_large.cu"
cutFree(ref_path);
# 382 "bisect_large.cu"
cutFree(reference);
# 383 "bisect_large.cu"
}
# 385 "bisect_large.cu"
freePtr(eigenvals);
# 386 "bisect_large.cu"
freePtr(lambda_mult);
# 387 "bisect_large.cu"
freePtr(pos_mult);
# 388 "bisect_large.cu"
freePtr(blocks_mult_sum);
# 389 "bisect_large.cu"
freePtr(left_one);
# 390 "bisect_large.cu"
freePtr(right_one);
# 391 "bisect_large.cu"
freePtr(pos_one);
# 392 "bisect_large.cu"
}
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_00002266_00000000-3_bisect_large.fatbin.c" 1
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
# 2 "/tmp/tmpxft_00002266_00000000-3_bisect_large.fatbin.c" 2



asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_10$:\n"
".quad 0x6f69737265762e09,0x2e090a342e31206e,0x7320746567726174,0x616d202c30315f6d\n"
".quad 0x6f745f3436665f70,0x2f2f090a3233665f,0x656c69706d6f6320,0x2f20687469772064\n"
".quad 0x61636f6c2f727375,0x6f2f616475632f6c,0x696c2f34366e6570,0x2f090a65622f2f62\n"
".quad 0x6e65706f766e202f,0x6220312e33206363,0x206e6f20746c6975,0x2d36302d30313032\n"
".quad 0x2d2f2f090a0a3730,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x43202f2f090a2d2d,0x676e696c69706d6f,0x6d742f706d742f20,0x3030305f74667870\n"
".quad 0x30305f3636323230,0x372d303030303030,0x5f7463657369625f,0x70632e656772616c\n"
".quad 0x742f2820692e3370,0x23494263632f706d,0x2949776e4778652e,0x2d2d2d2d2f2f090a\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d,0x2d2d2d2d2f2f090a\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d,0x6974704f202f2f09\n"
".quad 0x2f2f090a3a736e6f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x202f2f090a2d2d2d,0x3a74656772615420,0x415349202c787470,0x202c30315f6d733a\n"
".quad 0x6c3a6e6169646e45,0x50202c656c747469,0x53207265746e696f,0x090a34363a657a69\n"
".quad 0x09334f2d20202f2f,0x7a696d6974704f28,0x656c206e6f697461,0x2f2f090a296c6576\n"
".quad 0x44280930672d2020,0x76656c2067756265,0x202f2f090a296c65,0x65522809326d2d20\n"
".quad 0x7664612074726f70,0x29736569726f7369,0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d,0x09656c69662e090a,0x6d6d6f633c220931\n"
".quad 0x656e696c2d646e61,0x6c69662e090a223e,0x6d742f2209320965,0x746678706d742f70\n"
".quad 0x363232303030305f,0x3030303030305f36,0x7369625f362d3030,0x6772616c5f746365\n"
".quad 0x6566616475632e65,0x090a227570672e32,0x093309656c69662e,0x696c2f7273752f22\n"
".quad 0x38782f6363672f62,0x6e696c2d34365f36,0x342f756e672d7875,0x636e692f352e342e\n"
".quad 0x6474732f6564756c,0x090a22682e666564,0x093409656c69662e,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x697665642f747263\n"
".quad 0x69746e75725f6563,0x2e090a22682e656d,0x22093509656c6966,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x682f6564756c636e,0x696665645f74736f\n"
".quad 0x090a22682e73656e,0x093609656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x5f6e69746c697562,0x22682e7365707974\n"
".quad 0x09656c69662e090a,0x2f7273752f220937,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x6563697665642f65,0x682e73657079745f,0x656c69662e090a22\n"
".quad 0x7273752f22093809,0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x65766972642f6564,0x2e73657079745f72,0x6c69662e090a2268,0x73752f2209390965\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x667275732f656475\n"
".quad 0x657079745f656361,0x662e090a22682e73,0x2209303109656c69,0x636f6c2f7273752f\n"
".quad 0x2f616475632f6c61,0x692f2e2e2f6e6962,0x742f6564756c636e,0x745f657275747865\n"
".quad 0x0a22682e73657079,0x3109656c69662e09,0x2f7273752f220931,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x726f746365762f65,0x682e73657079745f\n"
".quad 0x656c69662e090a22,0x73752f2209323109,0x2f6c61636f6c2f72,0x6e69622f61647563\n"
".quad 0x6c636e692f2e2e2f,0x697665642f656475,0x636e75616c5f6563,0x656d617261705f68\n"
".quad 0x0a22682e73726574,0x3109656c69662e09,0x2f7273752f220933,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x74732f7472632f65,0x6c635f656761726f\n"
".quad 0x090a22682e737361,0x343109656c69662e,0x692f7273752f2209,0x622f6564756c636e\n"
".quad 0x657079742f737469,0x662e090a22682e73,0x2209353109656c69,0x636e692f7273752f\n"
".quad 0x6d69742f6564756c,0x662e090a22682e65,0x2209363109656c69,0x755f746365736962\n"
".quad 0x0a2275632e6c6974,0x3109656c69662e09,0x6365736962220937,0x6c656e72656b5f74\n"
".quad 0x632e656772616c5f,0x6c69662e090a2275,0x6962220938310965,0x72656b5f74636573\n"
".quad 0x6772616c5f6c656e,0x632e69656e6f5f65,0x6c69662e090a2275,0x752f220939310965\n"
".quad 0x756c636e692f7273,0x342f2b2b632f6564,0x6874616d632f342e,0x656c69662e090a22\n"
".quad 0x73752f2209303209,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x6d6d6f632f656475,0x74636e75665f6e6f,0x0a22682e736e6f69,0x3209656c69662e09\n"
".quad 0x2f7273752f220931,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x665f6874616d2f65,0x736e6f6974636e75,0x69662e090a22682e,0x2f2209323209656c\n"
".quad 0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69,0x616d2f6564756c63\n"
".quad 0x74736e6f635f6874,0x0a22682e73746e61,0x3209656c69662e09,0x2f7273752f220933\n"
".quad 0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65\n"
".quad 0x6f6974636e75665f,0x2e090a22682e736e,0x09343209656c6966,0x6f6c2f7273752f22\n"
".quad 0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x74615f31315f6d73\n"
".quad 0x6e75665f63696d6f,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209353209\n"
".quad 0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f,0x315f6d732f656475\n"
".quad 0x63696d6f74615f32,0x6f6974636e75665f,0x2e090a22682e736e,0x09363209656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x6f645f33315f6d73,0x6e75665f656c6275,0x682e736e6f697463,0x656c69662e090a22\n"
".quad 0x73752f2209373209,0x2f6c61636f6c2f72,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x325f6d732f656475,0x63696d6f74615f30,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09383209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x6e695f30325f6d73,0x736369736e697274,0x69662e090a22682e\n"
".quad 0x2f2209393209656c,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x75732f6564756c63,0x75665f6563616672,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220930330965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x7865742f6564756c,0x7465665f65727574,0x74636e75665f6863,0x0a22682e736e6f69\n"
".quad 0x3309656c69662e09,0x2f7273752f220931,0x75632f6c61636f6c,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x665f6874616d2f65,0x736e6f6974636e75,0x7874705f6c62645f\n"
".quad 0x662e090a22682e31,0x2209323309656c69,0x6b5f746365736962,0x616c5f6c656e7265\n"
".quad 0x746c756d5f656772,0x0a0a0a2275632e69,0x207972746e652e09,0x6573696237315a5f\n"
".quad 0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a\n"
".quad 0x535f535f535f3053,0x5f30535f30535f30,0x09090a28205f3053,0x2e206d617261702e\n"
".quad 0x75635f5f20343675,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x0a2c645f675f5f30,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c\n"
".quad 0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053\n"
".quad 0x735f675f5f30535f,0x7261702e09090a2c,0x203233752e206d61,0x6170616475635f5f\n"
".quad 0x6237315a5f5f6d72,0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650\n"
".quad 0x535f30536a50666a,0x5f535f30535f535f,0x5f30535f30535f53,0x6e5f5f30535f3053\n"
".quad 0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f,0x6237315a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a\n"
".quad 0x5f535f30535f535f,0x5f30535f30535f53,0x6c5f5f30535f3053,0x61702e09090a2c67\n"
".quad 0x3233662e206d6172,0x70616475635f5f20,0x37315a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53\n"
".quad 0x30535f30535f535f,0x5f5f30535f30535f,0x702e09090a2c6775,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265\n"
".quad 0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53\n"
".quad 0x5f30535f30535f30,0x5f6769655f676c5f,0x090a2c746e756f63,0x206d617261702e09\n"
".quad 0x635f5f203233752e,0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x655f67755f5f3053,0x746e756f635f6769,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x6237315a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f\n"
".quad 0x5f30535f30535f53,0x655f5f30535f3053,0x0a2c6e6f6c697370,0x6d617261702e0909\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365\n"
".quad 0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f\n"
".quad 0x30535f30535f3053,0x6e5f675f5f30535f,0x0a2c656e6f5f6d75,0x6d617261702e0909\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365\n"
".quad 0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f\n"
".quad 0x30535f30535f3053,0x6e5f675f5f30535f,0x6b636f6c625f6d75,0x0a2c746c756d5f73\n"
".quad 0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563,0x73696237315a5f5f\n"
".quad 0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53,0x535f535f30536a50\n"
".quad 0x5f535f535f30535f,0x30535f30535f3053,0x6c5f675f5f30535f,0x2c656e6f5f746665\n"
".quad 0x617261702e09090a,0x5f203436752e206d,0x726170616475635f,0x696237315a5f5f6d\n"
".quad 0x6e72654b74636573,0x50656772614c6c65,0x6a6a66666a5f5366,0x5f535f30536a5066\n"
".quad 0x535f535f30535f53,0x535f30535f30535f,0x5f675f5f30535f30,0x6e6f5f7468676972\n"
".quad 0x61702e09090a2c65,0x3436752e206d6172,0x70616475635f5f20,0x37315a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a\n"
".quad 0x535f30535f535f53,0x30535f30535f535f,0x5f5f30535f30535f,0x6e6f5f736f705f67\n"
".quad 0x61702e09090a2c65,0x3436752e206d6172,0x70616475635f5f20,0x37315a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a\n"
".quad 0x535f30535f535f53,0x30535f30535f535f,0x5f5f30535f30535f,0x6d5f7466656c5f67\n"
".quad 0x2e09090a2c746c75,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x7463657369623731,0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666\n"
".quad 0x30535f535f535f30,0x5f30535f535f535f,0x30535f30535f3053,0x686769725f675f5f\n"
".quad 0x0a2c746c756d5f74,0x6d617261702e0909,0x5f5f203436752e20,0x6d72617061647563\n"
".quad 0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53\n"
".quad 0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053,0x6c5f675f5f30535f\n"
".quad 0x6e756f635f746665,0x0a2c746c756d5f74,0x6d617261702e0909,0x5f5f203436752e20\n"
".quad 0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c\n"
".quad 0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053\n"
".quad 0x725f675f5f30535f,0x756f635f74686769,0x2c746c756d5f746e,0x617261702e09090a\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573\n"
".quad 0x50656772614c6c65,0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53\n"
".quad 0x535f30535f30535f,0x5f675f5f30535f30,0x6d5f736b636f6c62,0x2e09090a2c746c75\n"
".quad 0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061,0x7463657369623731\n"
".quad 0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30\n"
".quad 0x5f30535f535f535f,0x30535f30535f3053,0x636f6c625f675f5f,0x5f746c756d5f736b\n"
".quad 0x0a7b090a296d7573,0x752e206765722e09,0x353c687225203631,0x65722e090a3b3e33\n"
".quad 0x25203233752e2067,0x0a3b3e3335323c72,0x752e206765722e09,0x313c647225203436\n"
".quad 0x722e090a3b3e3539,0x203233662e206765,0x0a3b3e30393c6625,0x662e206765722e09\n"
".quad 0x383c646625203436,0x6765722e090a3b3e,0x2520646572702e20,0x090a3b3e39383c70\n"
".quad 0x206465726168732e,0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3636325f7261765f,0x5f735f33335f3933,0x5b3832317466656c\n"
".quad 0x090a3b5d32353032,0x206465726168732e,0x32206e67696c612e,0x635f5f2038622e20\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3636325f7261765f,0x5f735f32345f3434\n"
".quad 0x756f635f7466656c,0x315b30383132746e,0x2e090a3b5d363230,0x2e20646572616873\n"
".quad 0x2032206e67696c61,0x75635f5f2038622e,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x343636325f726176,0x635f735f32345f38,0x6f69746361706d6f,0x32337473696c5f6e\n"
".quad 0x5d363230315b3630,0x726168732e090a3b,0x67696c612e206465,0x2038622e2034206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3034363632\n"
".quad 0x74686769725f735f,0x3530325b32333234,0x68732e090a3b5d32,0x6c612e2064657261\n"
".quad 0x622e2032206e6769,0x616475635f5f2038,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f35343636325f72,0x6769725f735f3234,0x746e756f635f7468,0x3230315b34383236\n"
".quad 0x68732e090a3b5d36,0x6c612e2064657261,0x622e2032206e6769,0x616475635f5f2038\n"
".quad 0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f34343836325f72,0x5f6c635f735f3234\n"
".quad 0x33377265706c6568,0x5d363230315b3031,0x726168732e090a3b,0x203233752e206465\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f33353636325f,0x6361706d6f635f30\n"
".quad 0x646e6f6365735f74,0x0a3b6b6e7568635f,0x6465726168732e09,0x5f5f203233752e20\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f38353636,0x657268745f6d756e\n"
".quad 0x697463615f736461,0x68732e090a3b6576,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x31363636325f7261,0x5f6d756e5f30345f,0x5f73646165726874\n"
".quad 0x69746361706d6f63,0x68732e090a3b6e6f,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x35353636325f7261,0x5f6c6c615f30345f,0x5f73646165726874\n"
".quad 0x65677265766e6f63,0x6168732e090a3b64,0x3233752e20646572,0x5f616475635f5f20\n"
".quad 0x61765f6c61636f6c,0x5f38323936325f72,0x625f6d756e5f3034,0x756d5f736b636f6c\n"
".quad 0x68732e090a3b746c,0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f\n"
".quad 0x30333936325f7261,0x7366666f5f30345f,0x5f746c756d5f7465,0x0a3b6164626d616c\n"
".quad 0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f30345f39323936,0x746c756d5f6d756e,0x09636f6c2e090a3b,0x3009373731093731\n"
".quad 0x67656257444c240a,0x6237315a5f5f6e69,0x72654b7463657369,0x656772614c6c656e\n"
".quad 0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f,0x5f30535f30535f53\n"
".quad 0x0a3a5f30535f3053,0x3436752e766f6d09,0x202c316472250920,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3933363632,0x317466656c5f735f\n"
".quad 0x766f6d090a3b3832,0x722509203436752e,0x75635f5f202c3264,0x6475635f5f5f6164\n"
".quad 0x5f6c61636f6c5f61,0x343636325f726176,0x6c5f735f32345f34,0x6e756f635f746665\n"
".quad 0x090a3b3038313274,0x203436752e766f6d,0x5f202c3364722509,0x5f5f5f616475635f\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f32345f38343636,0x6361706d6f635f73\n"
".quad 0x73696c5f6e6f6974,0x090a3b3630323374,0x203436752e766f6d,0x5f202c3464722509\n"
".quad 0x5f5f5f616475635f,0x636f6c5f61647563,0x325f7261765f6c61,0x5f33335f30343636\n"
".quad 0x3474686769725f73,0x6f6d090a3b323332,0x2509203436752e76,0x635f5f202c356472\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3636325f7261765f,0x5f735f32345f3534\n"
".quad 0x6f635f7468676972,0x3b34383236746e75,0x3109636f6c2e090a,0x0a30093631320937\n"
".quad 0x3233752e766f6d09,0x30202c3172250920,0x732e766f6d090a3b,0x2c32722509203233\n"
".quad 0x2e090a3b31722520,0x3209373109636f6c,0x6f6d090a30093731,0x2509203233752e76\n"
".quad 0x090a3b30202c3372,0x203233732e766f6d,0x7225202c34722509,0x636f6c2e090a3b33\n"
".quad 0x0936323209373109,0x752e747663090a30,0x09203631752e3233,0x697425202c357225\n"
".quad 0x7663090a3b782e64,0x33752e3436752e74,0x2c36647225092032,0x6d090a3b35722520\n"
".quad 0x2e656469772e6c75,0x6472250920323375,0x202c357225202c37,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x2c37647225202c38,0x090a3b3364722520,0x203631752e766f6d\n"
".quad 0x30202c3168722509,0x68732e7473090a3b,0x3631752e64657261,0x2b386472255b0920\n"
".quad 0x31687225202c5d30,0x09636f6c2e090a3b,0x3009373232093731,0x69772e6c756d090a\n"
".quad 0x09203233752e6564,0x7225202c39647225,0x61090a3b34202c35,0x09203436752e6464\n"
".quad 0x25202c3031647225,0x647225202c396472,0x2e766f6d090a3b31,0x3166250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x726168732e747309\n"
".quad 0x09203233662e6465,0x302b30316472255b,0x0a3b316625202c5d,0x373109636f6c2e09\n"
".quad 0x090a300938323209,0x203436752e646461,0x202c313164722509,0x7225202c39647225\n"
".quad 0x766f6d090a3b3464,0x662509203233662e,0x3030306630202c32,0x20203b3030303030\n"
".quad 0x30202f2f09202020,0x6168732e7473090a,0x203233662e646572,0x2b31316472255b09\n"
".quad 0x3b326625202c5d30,0x3109636f6c2e090a,0x0a30093932320937,0x3436752e64646109\n"
".quad 0x2c32316472250920,0x25202c3764722520,0x6f6d090a3b326472,0x2509203631752e76\n"
".quad 0x0a3b30202c326872,0x726168732e747309,0x09203631752e6465,0x302b32316472255b\n"
".quad 0x3b32687225202c5d,0x3109636f6c2e090a,0x0a30093033320937,0x3436752e64646109\n"
".quad 0x2c33316472250920,0x25202c3764722520,0x6f6d090a3b356472,0x2509203631752e76\n"
".quad 0x0a3b30202c336872,0x726168732e747309,0x09203631752e6465,0x302b33316472255b\n"
".quad 0x3b33687225202c5d,0x3109636f6c2e090a,0x0a30093233320937,0x6e79732e72616209\n"
".quad 0x6d090a3b30092063,0x09203233752e766f,0x0a3b30202c367225,0x71652e7074657309\n"
".quad 0x702509203233752e,0x202c357225202c31,0x2140090a3b367225,0x2061726220317025\n"
".quad 0x365f305f744c2409,0x2e090a3b38373339,0x3209373109636f6c,0x646c090a30093733\n"
".quad 0x662e6d617261702e,0x2c33662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x4b74636573696237,0x72614c6c656e7265,0x666a5f5366506567,0x30536a50666a6a66\n"
".quad 0x5f30535f535f535f,0x535f30535f535f53,0x5f30535f30535f30,0x73090a3b5d676c5f\n"
".quad 0x6465726168732e74,0x5f5b09203233662e,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f33335f39333636,0x32317466656c5f73,0x6625202c5d302b38\n"
".quad 0x636f6c2e090a3b33,0x0938333209373109,0x61702e646c090a30,0x203233662e6d6172\n"
".quad 0x5f5b202c34662509,0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573\n"
".quad 0x50656772614c6c65,0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53\n"
".quad 0x535f30535f30535f,0x67755f5f30535f30,0x732e7473090a3b5d,0x33662e6465726168\n"
".quad 0x75635f5f5b092032,0x6475635f5f5f6164,0x5f6c61636f6c5f61,0x343636325f726176\n"
".quad 0x725f735f33335f30,0x3233323474686769,0x346625202c5d302b,0x09636f6c2e090a3b\n"
".quad 0x3009393332093731,0x7261702e646c090a,0x09203233752e6d61,0x5f5f5b202c377225\n"
".quad 0x6d72617061647563,0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c\n"
".quad 0x666a6a66666a5f53,0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053\n"
".quad 0x5f676c5f5f30535f,0x6e756f635f676965,0x2e7473090a3b5d74,0x752e646572616873\n"
".quad 0x635f5f5b09203631,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3636325f7261765f\n"
".quad 0x5f735f32345f3434,0x756f635f7466656c,0x302b30383132746e,0x0a3b377225202c5d\n"
".quad 0x373109636f6c2e09,0x090a300930343209,0x6d617261702e646c,0x722509203233752e\n"
".quad 0x75635f5f5b202c38,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x69655f67755f5f30,0x5d746e756f635f67,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x6475635f5f5b0920,0x616475635f5f5f61,0x765f6c61636f6c5f\n"
".quad 0x35343636325f7261,0x69725f735f32345f,0x6e756f635f746867,0x5d302b3438323674\n"
".quad 0x090a3b387225202c,0x09373109636f6c2e,0x6d090a3009323432,0x09203233752e766f\n"
".quad 0x0a3b30202c397225,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f33353636325f72,0x61706d6f635f3034,0x6e6f6365735f7463\n"
".quad 0x5d6b6e7568635f64,0x090a3b397225202c,0x09373109636f6c2e,0x6d090a3009333432\n"
".quad 0x09203233752e766f,0x3b31202c30317225,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x616475635f5f5b09,0x765f6c61636f6c5f,0x38353636325f7261,0x5f6d756e5f30345f\n"
".quad 0x5f73646165726874,0x2c5d657669746361,0x090a3b3031722520,0x09373109636f6c2e\n"
".quad 0x6d090a3009353432,0x09203233752e766f,0x3b31202c31317225,0x6168732e7473090a\n"
".quad 0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f,0x31363636325f7261\n"
".quad 0x5f6d756e5f30345f,0x5f73646165726874,0x69746361706d6f63,0x317225202c5d6e6f\n"
".quad 0x636f6c2e090a3b31,0x0937343209373109,0x752e766f6d090a30,0x3231722509203233\n"
".quad 0x7473090a3b31202c,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f35353636,0x657268745f6c6c61,0x766e6f635f736461\n"
".quad 0x202c5d6465677265,0x4c240a3b32317225,0x373339365f305f74,0x636f6c2e090a3a38\n"
".quad 0x0930353209373109,0x732e726162090a30,0x0a3b300920636e79,0x3233752e74766309\n"
".quad 0x722509203631752e,0x69746e25202c3331,0x6f6d090a3b782e64,0x2509203233752e76\n"
".quad 0x0a3b30202c343172,0x3233662e766f6d09,0x30202c3566250920,0x3030303030303066\n"
".quad 0x0920202020203b30,0x6f6d090a30202f2f,0x2509203233662e76,0x30306630202c3666\n"
".quad 0x203b303030303030,0x202f2f0920202020,0x662e766f6d090a30,0x2c37662509203233\n"
".quad 0x3030303030663020,0x202020203b303030,0x240a30202f2f0920,0x3335345f305f744c\n"
".quad 0x3c2f2f200a3a3431,0x6f4c203e706f6f6c,0x2079646f6220706f,0x36353220656e696c\n"
".quad 0x3109636f6c2e090a,0x0a30093635320937,0x726168732e646c09,0x09203233732e6465\n"
".quad 0x5f5b202c35317225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3835363632\n"
".quad 0x7268745f6d756e5f,0x7463615f73646165,0x73090a3b5d657669,0x752e656c2e707465\n"
".quad 0x2c32702509203233,0x25202c3531722520,0x702540090a3b3572,0x2409206172622032\n"
".quad 0x3431375f305f744c,0x3c2f2f200a3b3632,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x36353220656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3335345f305f744c,0x636f6c2e090a3431,0x0936393509363109,0x68732e646c090a30\n"
".quad 0x3233662e64657261,0x5b202c3766250920,0x5d302b3031647225,0x09636f6c2e090a3b\n"
".quad 0x3009373935093631,0x6168732e646c090a,0x203233662e646572,0x255b202c36662509\n"
".quad 0x3b5d302b31316472,0x3109636f6c2e090a,0x0a30093839350936,0x726168732e646c09\n"
".quad 0x09203631752e6465,0x72255b202c317225,0x0a3b5d302b323164,0x363109636f6c2e09\n"
".quad 0x090a300939393509,0x65726168732e646c,0x2509203631752e64,0x6472255b202c3372\n"
".quad 0x090a3b5d302b3331,0x75656e2e70746573,0x702509203233662e,0x202c366625202c33\n"
".quad 0x2140090a3b376625,0x2061726220337025,0x375f305f744c2409,0x2f200a3b38353630\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3635,0x64656c6562616c20,0x345f305f744c2420,0x6c2e090a34313335\n"
".quad 0x303609363109636f,0x766f6d090a300934,0x662509203233662e,0x3030306630202c38\n"
".quad 0x20203b3030303030,0x30202f2f09202020,0x3109636f6c2e090a,0x0a30093639350936\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x72255b202c376625,0x0a3b5d302b303164\n"
".quad 0x363109636f6c2e09,0x090a300934303609,0x2e746c2e70746573,0x3470250920323366\n"
".quad 0x25202c376625202c,0x766f6d090a3b3866,0x662509203233662e,0x3030306630202c39\n"
".quad 0x20203b3030303030,0x30202f2f09202020,0x3109636f6c2e090a,0x0a30093739350936\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x72255b202c366625,0x0a3b5d302b313164\n"
".quad 0x363109636f6c2e09,0x090a300934303609,0x2e746c2e70746573,0x3570250920323366\n"
".quad 0x25202c366625202c,0x252140090a3b3966,0x0920617262203570,0x31375f305f744c24\n"
".quad 0x2f2f200a3b303731,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6f6c2e090a343133,0x0932390936310963,0x2e706c6573090a30,0x3172250920323373\n"
".quad 0x2c30202c31202c36,0x62090a3b34702520,0x0920696e752e6172,0x30375f305f744c24\n"
".quad 0x744c240a3b343139,0x30373131375f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34313335345f305f,0x732e706c6573090a,0x3631722509203233\n"
".quad 0x202c31202c30202c,0x744c240a3b347025,0x34313930375f305f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a\n"
".quad 0x0a30093739350936,0x726168732e646c09,0x09203233662e6465,0x72255b202c366625\n"
".quad 0x0a3b5d302b313164,0x363109636f6c2e09,0x090a300936393509,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x6472255b202c3766,0x090a3b5d302b3031,0x09363109636f6c2e\n"
".quad 0x73090a3009343036,0x09203233662e6275,0x6625202c30316625,0x0a3b376625202c36\n"
".quad 0x3233662e766f6d09,0x202c313166250920,0x3030303066336630,0x09202020203b3030\n"
".quad 0x090a352e30202f2f,0x203233662e64616d,0x25202c3231662509,0x316625202c303166\n"
".quad 0x0a3b376625202c31,0x3233662e64646109,0x202c333166250920,0x376625202c366625\n"
".quad 0x662e766f6d090a3b,0x3431662509203233,0x303066336630202c,0x2020203b30303030\n"
".quad 0x352e30202f2f0920,0x33662e6c756d090a,0x2c35316625092032,0x25202c3331662520\n"
".quad 0x656e090a3b343166,0x2509203233732e67,0x317225202c373172,0x74636c73090a3b36\n"
".quad 0x3233732e3233662e,0x25202c3566250920,0x316625202c353166,0x3b37317225202c32\n"
".quad 0x3109636f6c2e090a,0x0a30093530360936,0x3233752e766f6d09,0x202c383172250920\n"
".quad 0x732e7473090a3b30,0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164\n"
".quad 0x3636325f7261765f,0x6c615f30345f3535,0x6461657268745f6c,0x7265766e6f635f73\n"
".quad 0x7225202c5d646567,0x617262090a3b3831,0x4c240920696e752e,0x323431375f305f74\n"
".quad 0x305f744c240a3b36,0x0a3a38353630375f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a34313335345f,0x09363109636f6c2e,0x6c090a3009393935\n"
".quad 0x6465726168732e64,0x722509203631752e,0x316472255b202c33,0x2e090a3b5d302b33\n"
".quad 0x3509363109636f6c,0x646c090a30093839,0x2e6465726168732e,0x3172250920363175\n"
".quad 0x32316472255b202c,0x6c2e090a3b5d302b,0x303609363109636f,0x627573090a300935\n"
".quad 0x722509203233752e,0x2c337225202c3931,0x6d090a3b31722520,0x09203233752e766f\n"
".quad 0x3b31202c30327225,0x6c2e70746573090a,0x2509203233752e65,0x39317225202c3670\n"
".quad 0x0a3b30327225202c,0x7262203670254009,0x305f744c24092061,0x0a3b36323431375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f\n"
".quad 0x09363109636f6c2e,0x6d090a3009303136,0x09203233752e766f,0x3b30202c31327225\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09,0x765f6c61636f6c5f\n"
".quad 0x35353636325f7261,0x5f6c6c615f30345f,0x5f73646165726874,0x65677265766e6f63\n"
".quad 0x31327225202c5d64,0x5f305f744c240a3b,0x240a3a3632343137,0x3430375f305f744c\n"
".quad 0x5f744c240a3a3230,0x3a30393839365f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x373109636f6c2e09,0x090a300931363209\n"
".quad 0x636e79732e726162,0x6c2e090a3b300920,0x363209373109636f,0x2e646c090a300935\n"
".quad 0x752e646572616873,0x3232722509203233,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x353636325f726176,0x6c6c615f30345f35,0x736461657268745f,0x677265766e6f635f\n"
".quad 0x6f6d090a3b5d6465,0x2509203233752e76,0x0a3b31202c333272,0x71652e7074657309\n"
".quad 0x702509203233752e,0x2c32327225202c37,0x090a3b3332722520,0x6172622037702540\n"
".quad 0x5f305f744c240920,0x0a3b323038383031,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a34313335345f,0x09373109636f6c2e,0x6c090a3009333732\n"
".quad 0x6465726168732e64,0x722509203233752e,0x635f5f5b202c3432,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x6e5f30345f383536,0x61657268745f6d75,0x76697463615f7364\n"
".quad 0x6f6c2e090a3b5d65,0x3833320936310963,0x702e646c090a3009,0x3233752e6d617261\n"
".quad 0x202c353272250920,0x70616475635f5f5b,0x37315a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53\n"
".quad 0x30535f30535f535f,0x5f5f30535f30535f,0x766f6d090a3b5d6e,0x722509203233732e\n"
".quad 0x35327225202c3632,0x752e766f6d090a3b,0x3732722509203233,0x6573090a3b30202c\n"
".quad 0x33752e71652e7074,0x202c387025092032,0x7225202c35327225,0x702540090a3b3732\n"
".quad 0x2409206172622038,0x3930315f305f744c,0x2f2f200a3b383530,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133,0x3337320937310963\n"
".quad 0x732e646c090a3009,0x33752e6465726168,0x2c34327225092032,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x38353636325f7261,0x5f6d756e5f30345f,0x5f73646165726874\n"
".quad 0x3b5d657669746361,0x3109636f6c2e090a,0x0a30093833320936,0x74672e7074657309\n"
".quad 0x702509203233752e,0x2c34327225202c39,0x6d090a3b35722520,0x09203233752e766f\n"
".quad 0x3b30202c38327225,0x33752e766f6d090a,0x2c39327225092032,0x766f6d090a3b3020\n"
".quad 0x662509203233662e,0x66336630202c3631,0x203b303030303038,0x31202f2f09202020\n"
".quad 0x375f305f744c240a,0x2f200a3a30353432,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3220656e696c2079,0x7473656e202c3833,0x7470656420676e69,0x7365202c31203a68\n"
".quad 0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e,0x6f6c2e090a6e776f\n"
".quad 0x3334320936310963,0x2e726162090a3009,0x3b300920636e7973,0x33752e646461090a\n"
".quad 0x2c30337225092032,0x25202c3832722520,0x746573090a3b3572,0x3233752e656c2e70\n"
".quad 0x202c303170250920,0x7225202c35327225,0x702540090a3b3033,0x0920617262203031\n"
".quad 0x32375f305f744c24,0x2f2f200a3b363037,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x333220656e696c20,0x2064616568202c38,0x2064656c6562616c\n"
".quad 0x32375f305f744c24,0x6f6c2e090a303534,0x3834320936310963,0x2e747663090a3009\n"
".quad 0x203233752e343675,0x202c343164722509,0x61090a3b38327225,0x09203436752e6464\n"
".quad 0x25202c3531647225,0x7225202c34316472,0x6c756d090a3b3664,0x203436752e6f6c2e\n"
".quad 0x202c363164722509,0x34202c3531647225,0x61702e646c090a3b,0x203436752e6d6172\n"
".quad 0x202c373164722509,0x70616475635f5f5b,0x37315a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53\n"
".quad 0x30535f30535f535f,0x5f5f30535f30535f,0x61090a3b5d645f67,0x09203436752e6464\n"
".quad 0x25202c3831647225,0x7225202c37316472,0x646c090a3b363164,0x2e6c61626f6c672e\n"
".quad 0x3166250920323366,0x316472255b202c37,0x73090a3b5d302b38,0x6465726168732e74\n"
".quad 0x255b09203233662e,0x2c5d302b30316472,0x090a3b3731662520,0x09363109636f6c2e\n"
".quad 0x6c090a3009393432,0x2e6d617261702e64,0x6472250920343675,0x635f5f5b202c3931\n"
".quad 0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c\n"
".quad 0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30\n"
".quad 0x5d735f675f5f3053,0x752e646461090a3b,0x3264722509203436,0x3931647225202c30\n"
".quad 0x3b3631647225202c,0x6f6c672e646c090a,0x203233662e6c6162,0x5b202c3831662509\n"
".quad 0x342d2b3032647225,0x732e7473090a3b5d,0x33662e6465726168,0x316472255b092032\n"
".quad 0x6625202c5d302b31,0x5f744c240a3b3831,0x3a36303732375f30,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3833322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a30353432375f30,0x363109636f6c2e09\n"
".quad 0x090a300932353209,0x636e79732e726162,0x2140090a3b300920,0x2061726220397025\n"
".quad 0x375f305f744c2409,0x2f200a3b30333733,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3833,0x64656c6562616c20\n"
".quad 0x375f305f744c2420,0x696d090a30353432,0x2509203233752e6e,0x327225202c313372\n"
".quad 0x3b33317225202c36,0x33752e766f6d090a,0x2c32337225092032,0x746573090a3b3020\n"
".quad 0x3233752e71652e70,0x202c313170250920,0x7225202c31337225,0x702540090a3b3233\n"
".quad 0x0920617262203131,0x33375f305f744c24,0x2f2f200a3b303337,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x333220656e696c20,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x32375f305f744c24,0x766f6d090a303534,0x722509203233732e\n"
".quad 0x31337225202c3333,0x732e766f6d090a3b,0x3264722509203436,0x3b31647225202c31\n"
".quad 0x36732e766f6d090a,0x3232647225092034,0x0a3b34647225202c,0x3233752e766f6d09\n"
".quad 0x202c343372250920,0x6c3c2f2f200a3b30,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x353432375f305f74,0x732e766f6d090a30,0x3533722509203233,0x0a3b33337225202c\n"
".quad 0x34375f305f744c24,0x2f2f200a3a323432,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x697473656e202c32,0x687470656420676e,0x747365202c32203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x0930363209363109,0x68732e646c090a30,0x3233662e64657261,0x202c393166250920\n"
".quad 0x302b32326472255b,0x732e646c090a3b5d,0x33662e6465726168,0x2c30326625092032\n"
".quad 0x2b31326472255b20,0x627573090a3b5d30,0x662509203233662e,0x30326625202c3132\n"
".quad 0x090a3b356625202c,0x203233662e6c756d,0x25202c3232662509,0x316625202c393166\n"
".quad 0x2e766964090a3b39,0x3233662e6c6c7566,0x202c333266250920,0x6625202c32326625\n"
".quad 0x627573090a3b3631,0x662509203233662e,0x31326625202c3631,0x0a3b33326625202c\n"
".quad 0x363109636f6c2e09,0x090a300932363209,0x203233662e766f6d,0x30202c3432662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x746573090a30202f,0x2e3233752e746c2e\n"
".quad 0x3372250920323366,0x2c36316625202c36,0x090a3b3432662520,0x203233732e67656e\n"
".quad 0x25202c3733722509,0x6461090a3b363372,0x2509203233752e64,0x327225202c393272\n"
".quad 0x3b37337225202c39,0x33752e646461090a,0x2c34337225092032,0x31202c3433722520\n"
".quad 0x752e646461090a3b,0x3264722509203436,0x3232647225202c32,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x7225202c31326472,0x0a3b34202c313264,0x656e2e7074657309\n"
".quad 0x702509203233752e,0x31337225202c3231,0x0a3b34337225202c,0x6220323170254009\n"
".quad 0x5f744c2409206172,0x3b32343234375f30,0x375f305f744c240a,0x4c240a3a30333733\n"
".quad 0x313233375f305f74,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x353432375f305f74,0x09636f6c2e090a30,0x3009373632093631,0x33752e627573090a\n"
".quad 0x2c36327225092032,0x25202c3632722520,0x6461090a3b333172,0x2509203233752e64\n"
".quad 0x327225202c383272,0x3b33317225202c38,0x6c2e70746573090a,0x2509203233752e74\n"
".quad 0x327225202c333170,0x3b35327225202c38,0x203331702540090a,0x744c240920617262\n"
".quad 0x30353432375f305f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313335345f305f,0x6e752e617262090a,0x305f744c24092069,0x0a3b38333931375f\n"
".quad 0x30315f305f744c24,0x2f200a3a38353039,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20\n"
".quad 0x345f305f744c2420,0x6f6d090a34313335,0x2509203233752e76,0x0a3b30202c393272\n"
".quad 0x31375f305f744c24,0x2f2f200a3a383339,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c\n"
".quad 0x35345f305f744c24,0x6f6c2e090a343133,0x3738320937310963,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x6168732e646c090a,0x203233752e646572,0x5b202c3833722509\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f38353636325f,0x68745f6d756e5f30\n"
".quad 0x63615f7364616572,0x090a3b5d65766974,0x2e656c2e70746573,0x3170250920323375\n"
".quad 0x2c38337225202c34,0x40090a3b35722520,0x6172622034317025,0x5f305f744c240920\n"
".quad 0x200a3b3232353537,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c363532,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x63090a3431333534,0x752e3631752e7476,0x3933722509203233,0x090a3b337225202c\n"
".quad 0x2e3631752e747663,0x3472250920323375,0x0a3b317225202c30,0x656e2e7074657309\n"
".quad 0x2509203233662e75,0x366625202c353170,0x090a3b376625202c,0x6220353170252140\n"
".quad 0x5f744c2409206172,0x3b38373735375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x373109636f6c2e09,0x090a300934303309\n"
".quad 0x2e3631752e747663,0x3472250920323375,0x3b39327225202c31,0x33662e736261090a\n"
".quad 0x2c35326625092032,0x73090a3b35662520,0x752e656e2e707465,0x3631702509203233\n"
".quad 0x202c30347225202c,0x6c090a3b31347225,0x2e6d617261702e64,0x3266250920323366\n"
".quad 0x75635f5f5b202c36,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x6c697370655f5f30,0x6573090a3b5d6e6f,0x09203233732e706c\n"
".quad 0x2c31202c32347225,0x36317025202c3020,0x6e2e746573090a3b,0x33752e3233752e65\n"
".quad 0x2c33347225092032,0x25202c3134722520,0x656e090a3b393372,0x2509203233732e67\n"
".quad 0x347225202c343472,0x2e646e61090a3b33,0x3472250920323362,0x2c32347225202c35\n"
".quad 0x090a3b3434722520,0x203233752e766f6d,0x30202c3634722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x7225202c37317025,0x36347225202c3534,0x3731702540090a3b\n"
".quad 0x4c24092061726220,0x393236375f305f74,0x6c3c2f2f200a3b30,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x3009373231093631\n"
".quad 0x6168732e7473090a,0x203631752e646572,0x2b32316472255b09,0x30347225202c5d30\n"
".quad 0x09636f6c2e090a3b,0x3009383231093631,0x6168732e7473090a,0x203631752e646572\n"
".quad 0x2b33316472255b09,0x31347225202c5d30,0x09636f6c2e090a3b,0x3009333331093631\n"
".quad 0x33662e627573090a,0x2c37326625092032,0x6625202c35662520,0x2e736261090a3b37\n"
".quad 0x3266250920323366,0x3b37326625202c38,0x36662e747663090a,0x2509203233662e34\n"
".quad 0x326625202c316466,0x2e736261090a3b38,0x3266250920323366,0x0a3b376625202c39\n"
".quad 0x3233662e78616d09,0x202c303366250920,0x6625202c35326625,0x6f6c2e090a3b3932\n"
".quad 0x3430330937310963,0x702e646c090a3009,0x3233662e6d617261,0x202c363266250920\n"
".quad 0x70616475635f5f5b,0x37315a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53,0x30535f30535f535f\n"
".quad 0x5f5f30535f30535f,0x5d6e6f6c69737065,0x09636f6c2e090a3b,0x3009333331093631\n"
".quad 0x33662e6c756d090a,0x2c31336625092032,0x25202c3632662520,0x6f6d090a3b303366\n"
".quad 0x2509203233662e76,0x306630202c323366,0x3b35323432613233,0x202f2f0920202020\n"
".quad 0x6d090a37332d6535,0x09203233662e7861,0x6625202c33336625,0x32336625202c3133\n"
".quad 0x662e747663090a3b,0x09203233662e3436,0x6625202c32646625,0x746573090a3b3333\n"
".quad 0x3436662e656c2e70,0x202c383170250920,0x6625202c31646625,0x252140090a3b3264\n"
".quad 0x2061726220383170,0x375f305f744c2409,0x2f200a3b32303836,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635\n"
".quad 0x64656c6562616c20,0x345f305f744c2420,0x6c2e090a34313335,0x333109363109636f\n"
".quad 0x766f6d090a300936,0x662509203233662e,0x30306630202c3433,0x203b303030303030\n"
".quad 0x30202f2f09202020,0x6c2e70746573090a,0x2509203233662e74,0x376625202c393170\n"
".quad 0x0a3b34336625202c,0x6572702e766f6d09,0x202c347025092064,0x6d090a3b39317025\n"
".quad 0x20646572702e766f,0x25202c3032702509,0x6f6d090a3b313270,0x2509203233662e76\n"
".quad 0x306630202c353366,0x3b30303030303030,0x202f2f0920202020,0x2e70746573090a30\n"
".quad 0x09203233662e746c,0x6625202c32327025,0x3b35336625202c35,0x323270252140090a\n"
".quad 0x4c24092061726220,0x313337375f305f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x0a30093239093631\n"
".quad 0x33732e706c657309,0x2c37347225092032,0x25202c30202c3120,0x617262090a3b3470\n"
".quad 0x4c240920696e752e,0x353037375f305f74,0x305f744c240a3b38,0x0a3a34313337375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f\n"
".quad 0x3233732e706c6573,0x202c373472250920,0x7025202c31202c30,0x5f744c240a3b3931\n"
".quad 0x3a38353037375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34313335345f30,0x363109636f6c2e09,0x090a300939333109,0x203233662e646461\n"
".quad 0x25202c3633662509,0x3b376625202c3566,0x33662e766f6d090a,0x2c37336625092032\n"
".quad 0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09,0x3233662e64616d09\n"
".quad 0x202c383366250920,0x6625202c37326625,0x3b376625202c3733,0x33662e766f6d090a\n"
".quad 0x2c39336625092032,0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09\n"
".quad 0x3233662e6c756d09,0x202c303466250920,0x6625202c36336625,0x67656e090a3b3933\n"
".quad 0x722509203233732e,0x37347225202c3834,0x2e74636c73090a3b,0x203233732e323366\n"
".quad 0x25202c3134662509,0x336625202c303466,0x3b38347225202c38,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x2b30316472255b09,0x31346625202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009303431093631,0x6168732e7473090a,0x203233662e646572,0x2b31316472255b09\n"
".quad 0x31346625202c5d30,0x752e617262090a3b,0x5f744c240920696e,0x3b36343536375f30\n"
".quad 0x375f305f744c240a,0x2f200a3a32303836,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20\n"
".quad 0x345f305f744c2420,0x6c2e090a34313335,0x343109363109636f,0x2e7473090a300935\n"
".quad 0x662e646572616873,0x6472255b09203233,0x25202c5d302b3031,0x6f6c2e090a3b3766\n"
".quad 0x3634310936310963,0x732e7473090a3009,0x33662e6465726168,0x316472255b092032\n"
".quad 0x6625202c5d302b31,0x305f744c240a3b35,0x0a3a36343536375f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220\n"
".quad 0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f,0x09373109636f6c2e\n"
".quad 0x6d090a3009353139,0x09203631752e766f,0x3b31202c34687225,0x6168732e7473090a\n"
".quad 0x203631752e646572,0x322b386472255b09,0x3b34687225202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093631390937,0x3233752e766f6d09,0x202c393472250920,0x732e7473090a3b31\n"
".quad 0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164,0x3636325f7261765f\n"
".quad 0x6f635f30345f3335,0x65735f746361706d,0x7568635f646e6f63,0x347225202c5d6b6e\n"
".quad 0x2e766f6d090a3b39,0x3172250920323375,0x62090a3b31202c34,0x0920696e752e6172\n"
".quad 0x35375f305f744c24,0x744c240a3b323235,0x30393236375f305f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a\n"
".quad 0x0a30093432390937,0x3631752e766f6d09,0x202c356872250920,0x732e7473090a3b30\n"
".quad 0x31752e6465726168,0x386472255b092036,0x687225202c5d322b,0x70252140090a3b35\n"
".quad 0x0920617262203631,0x37375f305f744c24,0x2f2f200a3b363238,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133,0x3732310936310963\n"
".quad 0x732e7473090a3009,0x31752e6465726168,0x316472255b092036,0x7225202c5d302b32\n"
".quad 0x6f6c2e090a3b3034,0x3832310936310963,0x732e7473090a3009,0x31752e6465726168\n"
".quad 0x316472255b092036,0x7225202c5d302b33,0x6f6c2e090a3b3134,0x3333310936310963\n"
".quad 0x2e627573090a3009,0x3266250920323366,0x202c356625202c37,0x6261090a3b376625\n"
".quad 0x2509203233662e73,0x326625202c323466,0x2e747663090a3b37,0x203233662e343666\n"
".quad 0x25202c3364662509,0x6261090a3b323466,0x2509203233662e73,0x376625202c333466\n"
".quad 0x662e78616d090a3b,0x3434662509203233,0x202c35326625202c,0x2e090a3b33346625\n"
".quad 0x3309373109636f6c,0x646c090a30093430,0x662e6d617261702e,0x3632662509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623731,0x614c6c656e72654b\n"
".quad 0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30,0x5f30535f535f535f\n"
".quad 0x30535f30535f3053,0x6f6c697370655f5f,0x6f6c2e090a3b5d6e,0x3333310936310963\n"
".quad 0x2e6c756d090a3009,0x3466250920323366,0x2c36326625202c35,0x090a3b3434662520\n"
".quad 0x203233662e766f6d,0x30202c3634662509,0x3234326132333066,0x2f09202020203b35\n"
".quad 0x0a37332d6535202f,0x3233662e78616d09,0x202c373466250920,0x6625202c35346625\n"
".quad 0x747663090a3b3634,0x3233662e3436662e,0x202c346466250920,0x73090a3b37346625\n"
".quad 0x662e656c2e707465,0x3332702509203436,0x202c33646625202c,0x40090a3b34646625\n"
".quad 0x7262203332702521,0x305f744c24092061,0x0a3b38333338375f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220\n"
".quad 0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f,0x09363109636f6c2e\n"
".quad 0x6d090a3009363331,0x09203233662e766f,0x6630202c38346625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x70746573090a3020,0x203233662e746c2e,0x25202c3931702509\n"
".quad 0x38346625202c3766,0x702e766f6d090a3b,0x3470250920646572,0x0a3b39317025202c\n"
".quad 0x6572702e766f6d09,0x2c34327025092064,0x090a3b3132702520,0x203233662e766f6d\n"
".quad 0x30202c3934662509,0x3030303030303066,0x2f09202020203b30,0x746573090a30202f\n"
".quad 0x3233662e746c2e70,0x202c353270250920,0x346625202c356625,0x70252140090a3b39\n"
".quad 0x0920617262203532,0x38375f305f744c24,0x2f2f200a3b303538,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133,0x0932390936310963\n"
".quad 0x2e706c6573090a30,0x3572250920323373,0x2c30202c31202c30,0x62090a3b34702520\n"
".quad 0x0920696e752e6172,0x38375f305f744c24,0x744c240a3b343935,0x30353838375f305f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36353220656e,0x62616c2064616568,0x744c242064656c65,0x34313335345f305f\n"
".quad 0x732e706c6573090a,0x3035722509203233,0x202c31202c30202c,0x4c240a3b39317025\n"
".quad 0x393538375f305f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313335345f305f74,0x09636f6c2e090a34,0x3009393331093631,0x33662e646461090a\n"
".quad 0x2c30356625092032,0x6625202c35662520,0x2e766f6d090a3b37,0x3566250920323366\n"
".quad 0x3066336630202c31,0x20203b3030303030,0x2e30202f2f092020,0x662e64616d090a35\n"
".quad 0x3235662509203233,0x202c37326625202c,0x6625202c31356625,0x2e766f6d090a3b37\n"
".quad 0x3566250920323366,0x3066336630202c33,0x20203b3030303030,0x2e30202f2f092020\n"
".quad 0x662e6c756d090a35,0x3435662509203233,0x202c30356625202c,0x6e090a3b33356625\n"
".quad 0x09203233732e6765,0x7225202c31357225,0x636c73090a3b3035,0x33732e3233662e74\n"
".quad 0x2c35356625092032,0x25202c3435662520,0x357225202c323566,0x732e7473090a3b31\n"
".quad 0x33662e6465726168,0x316472255b092032,0x6625202c5d302b30,0x6f6c2e090a3b3535\n"
".quad 0x3034310936310963,0x732e7473090a3009,0x33662e6465726168,0x316472255b092032\n"
".quad 0x6625202c5d302b31,0x617262090a3b3535,0x4c240920696e752e,0x303139375f305f74\n"
".quad 0x305f744c240a3b36,0x0a3a38333338375f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a34313335345f,0x09363109636f6c2e,0x73090a3009353431\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x2c5d302b30316472,0x2e090a3b37662520\n"
".quad 0x3109363109636f6c,0x7473090a30093634,0x2e6465726168732e,0x72255b0920323366\n"
".quad 0x202c5d302b313164,0x7262090a3b356625,0x240920696e752e61,0x3139375f305f744c\n"
".quad 0x5f744c240a3b3630,0x3a36323837375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x363109636f6c2e09,0x090a300937323109\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x5d302b3231647225,0x0a3b31347225202c\n"
".quad 0x363109636f6c2e09,0x090a300938323109,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x5d302b3331647225,0x0a3b39337225202c,0x363109636f6c2e09,0x090a300933333109\n"
".quad 0x203233662e627573,0x25202c3635662509,0x3b356625202c3666,0x33662e736261090a\n"
".quad 0x2c37356625092032,0x090a3b3635662520,0x2e3436662e747663,0x6466250920323366\n"
".quad 0x3b37356625202c35,0x33662e736261090a,0x2c38356625092032,0x6d090a3b36662520\n"
".quad 0x09203233662e7861,0x6625202c39356625,0x38356625202c3532,0x09636f6c2e090a3b\n"
".quad 0x3009343033093731,0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c36326625\n"
".quad 0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65\n"
".quad 0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f\n"
".quad 0x70655f5f30535f30,0x0a3b5d6e6f6c6973,0x363109636f6c2e09,0x090a300933333109\n"
".quad 0x203233662e6c756d,0x25202c3036662509,0x356625202c363266,0x2e766f6d090a3b39\n"
".quad 0x3666250920323366,0x3233306630202c31,0x20203b3532343261,0x6535202f2f092020\n"
".quad 0x78616d090a37332d,0x662509203233662e,0x30366625202c3236,0x0a3b31366625202c\n"
".quad 0x3436662e74766309,0x662509203233662e,0x32366625202c3664,0x2e70746573090a3b\n"
".quad 0x09203436662e656c,0x6625202c36327025,0x36646625202c3564,0x3270252140090a3b\n"
".quad 0x2409206172622036,0x3339375f305f744c,0x3c2f2f200a3b3236,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x36353220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3335345f305f744c,0x636f6c2e090a3431,0x0936333109363109\n"
".quad 0x662e766f6d090a30,0x3336662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x2e746c2e70746573,0x3270250920323366,0x202c356625202c37\n"
".quad 0x6d090a3b33366625,0x20646572702e766f,0x25202c3832702509,0x6f6d090a3b373270\n"
".quad 0x0920646572702e76,0x7025202c39327025,0x766f6d090a3b3033,0x662509203233662e\n"
".quad 0x30306630202c3436,0x203b303030303030,0x30202f2f09202020,0x6c2e70746573090a\n"
".quad 0x2509203233662e74,0x366625202c313370,0x0a3b34366625202c,0x2031337025214009\n"
".quad 0x744c240920617262,0x34373839375f305f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a,0x090a300932390936\n"
".quad 0x3233732e706c6573,0x202c323572250920,0x7025202c30202c31,0x617262090a3b3832\n"
".quad 0x4c240920696e752e,0x313639375f305f74,0x305f744c240a3b38,0x0a3a34373839375f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f\n"
".quad 0x3233732e706c6573,0x202c323572250920,0x7025202c31202c30,0x5f744c240a3b3732\n"
".quad 0x3a38313639375f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a34313335345f30,0x363109636f6c2e09,0x090a300939333109,0x203233662e646461\n"
".quad 0x25202c3536662509,0x3b366625202c3566,0x33662e766f6d090a,0x2c36366625092032\n"
".quad 0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09,0x3233662e64616d09\n"
".quad 0x202c373666250920,0x6625202c36356625,0x3b356625202c3636,0x33662e766f6d090a\n"
".quad 0x2c38366625092032,0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09\n"
".quad 0x3233662e6c756d09,0x202c393666250920,0x6625202c35366625,0x67656e090a3b3836\n"
".quad 0x722509203233732e,0x32357225202c3335,0x2e74636c73090a3b,0x203233732e323366\n"
".quad 0x25202c3037662509,0x366625202c393666,0x3b33357225202c37,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x2b30316472255b09,0x30376625202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009303431093631,0x6168732e7473090a,0x203233662e646572,0x2b31316472255b09\n"
".quad 0x30376625202c5d30,0x752e617262090a3b,0x5f744c240920696e,0x3b36303139375f30\n"
".quad 0x375f305f744c240a,0x2f200a3a32363339,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20\n"
".quad 0x345f305f744c2420,0x6c2e090a34313335,0x343109363109636f,0x2e7473090a300935\n"
".quad 0x662e646572616873,0x6472255b09203233,0x25202c5d302b3031,0x6f6c2e090a3b3566\n"
".quad 0x3634310936310963,0x732e7473090a3009,0x33662e6465726168,0x316472255b092032\n"
".quad 0x6625202c5d302b31,0x305f744c240a3b36,0x0a3a36303139375f,0x37375f305f744c24\n"
".quad 0x2f2f200a3a303735,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24\n"
".quad 0x6f6c2e090a343133,0x3233390937310963,0x2e766f6d090a3009,0x3172250920323375\n"
".quad 0x62090a3b30202c34,0x0920696e752e6172,0x35375f305f744c24,0x744c240a3b323235\n"
".quad 0x38373735375f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313335345f305f,0x3109636f6c2e090a,0x0a30093831330937,0x726168732e747309\n"
".quad 0x09203233662e6465,0x302b30316472255b,0x0a3b376625202c5d,0x373109636f6c2e09\n"
".quad 0x090a300939313309,0x65726168732e7473,0x5b09203233662e64,0x5d302b3131647225\n"
".quad 0x090a3b376625202c,0x09373109636f6c2e,0x73090a3009303233,0x6465726168732e74\n"
".quad 0x255b09203631752e,0x2c5d302b32316472,0x090a3b3034722520,0x09373109636f6c2e\n"
".quad 0x73090a3009313233,0x6465726168732e74,0x255b09203631752e,0x2c5d302b33316472\n"
".quad 0x090a3b3933722520,0x09373109636f6c2e,0x6d090a3009333233,0x09203233752e766f\n"
".quad 0x3b30202c34317225,0x375f305f744c240a,0x4c240a3a32323535,0x313035375f305f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36353220656e69,0x616c206461656820,0x4c242064656c6562,0x313335345f305f74\n"
".quad 0x09636f6c2e090a34,0x3009383233093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5f5b202c343572,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f33353636,0x5f746361706d6f63,0x635f646e6f636573\n"
".quad 0x090a3b5d6b6e7568,0x203233752e766f6d,0x30202c3535722509,0x2e70746573090a3b\n"
".quad 0x09203233752e7165,0x7225202c32337025,0x35357225202c3435,0x3233702540090a3b\n"
".quad 0x4c24092061726220,0x313733385f305f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x3009363333093731\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x5b202c3635722509,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f31363636325f,0x68745f6d756e5f30,0x6f635f7364616572\n"
".quad 0x6e6f69746361706d,0x636f6c2e090a3b5d,0x0937363309363109,0x752e726873090a30\n"
".quad 0x3735722509203233,0x202c36357225202c,0x2e766f6d090a3b31,0x3572250920323373\n"
".quad 0x3b37357225202c38,0x33752e766f6d090a,0x2c39357225092032,0x746573090a3b3020\n"
".quad 0x3233732e656c2e70,0x202c333370250920,0x7225202c37357225,0x702540090a3b3935\n"
".quad 0x0920617262203333,0x30315f305f744c24,0x2f200a3b30373539,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635\n"
".quad 0x64656c6562616c20,0x345f305f744c2420,0x6f6d090a34313335,0x2509203233752e76\n"
".quad 0x0a3b31202c303672,0x31385f305f744c24,0x2f2f200a3a343531,0x4c203e706f6f6c3c\n"
".quad 0x79646f6220706f6f,0x363320656e696c20,0x09636f6c2e090a39,0x3009393633093631\n"
".quad 0x79732e726162090a,0x090a3b300920636e,0x2e656c2e70746573,0x3370250920323375\n"
".quad 0x2c38357225202c34,0x40090a3b35722520,0x6172622034337025,0x5f305f744c240920\n"
".quad 0x200a3b3031343138,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c393633,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x2e090a3435313138,0x3309363109636f6c,0x756d090a30093937,0x752e6f6c2e34326c\n"
".quad 0x3136722509203233,0x32202c357225202c,0x752e646461090a3b,0x3236722509203233\n"
".quad 0x202c31367225202c,0x2e646461090a3b31,0x3672250920323375,0x2c31367225202c33\n"
".quad 0x6c756d090a3b3220,0x203233752e6f6c2e,0x25202c3436722509,0x367225202c323672\n"
".quad 0x2e6c756d090a3b30,0x09203233752e6f6c,0x7225202c35367225,0x30367225202c3336\n"
".quad 0x752e766f6d090a3b,0x3636722509203233,0x6573090a3b30202c,0x33752e656e2e7074\n"
".quad 0x2c35337025092032,0x25202c3536722520,0x7573090a3b363672,0x2509203233752e62\n"
".quad 0x367225202c373672,0x6d090a3b31202c35,0x09203233752e766f,0x3b30202c38367225\n"
".quad 0x752e706c6573090a,0x3936722509203233,0x202c37367225202c,0x7025202c38367225\n"
".quad 0x747663090a3b3533,0x3233752e3436752e,0x2c33326472250920,0x090a3b3936722520\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x367225202c343264,0x61090a3b32202c39\n"
".quad 0x09203436752e6464,0x25202c3532647225,0x647225202c336472,0x2e646c090a3b3432\n"
".quad 0x752e646572616873,0x3668722509203631,0x35326472255b202c,0x7573090a3b5d322b\n"
".quad 0x2509203233752e62,0x367225202c303772,0x6d090a3b31202c34,0x09203233752e766f\n"
".quad 0x3b30202c31377225,0x33752e766f6d090a,0x2c32377225092032,0x746573090a3b3020\n"
".quad 0x3233752e656e2e70,0x202c363370250920,0x7225202c34367225,0x6c6573090a3b3237\n"
".quad 0x2509203233752e70,0x377225202c333772,0x2c31377225202c30,0x090a3b3633702520\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x33377225202c3632,0x772e6c756d090a3b\n"
".quad 0x203233752e656469,0x202c373264722509,0x3b32202c33377225,0x36752e646461090a\n"
".quad 0x3832647225092034,0x202c33647225202c,0x090a3b3732647225,0x65726168732e646c\n"
".quad 0x2509203631752e64,0x72255b202c376872,0x0a3b5d322b383264,0x3631752e64646109\n"
".quad 0x202c386872250920,0x7225202c36687225,0x2e7473090a3b3768,0x752e646572616873\n"
".quad 0x6472255b09203631,0x25202c5d322b3532,0x744c240a3b386872,0x30313431385f305f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c39363320656e,0x62616c2064616568,0x744c242064656c65,0x34353131385f305f\n"
".quad 0x3109636f6c2e090a,0x0a30093338330936,0x3233622e6c687309,0x202c303672250920\n"
".quad 0x3b31202c30367225,0x3109636f6c2e090a,0x0a30093736330936,0x3233732e72687309\n"
".quad 0x202c383572250920,0x3b31202c38357225,0x33752e766f6d090a,0x2c34377225092032\n"
".quad 0x746573090a3b3020,0x3233732e74672e70,0x202c373370250920,0x7225202c38357225\n"
".quad 0x702540090a3b3437,0x0920617262203733,0x31385f305f744c24,0x2f2f200a3b343531\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20\n"
".quad 0x2064616568202c36,0x2064656c6562616c,0x35345f305f744c24,0x617262090a343133\n"
".quad 0x4c240920696e752e,0x343630385f305f74,0x305f744c240a3b32,0x3a3037353930315f\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3635322065,0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30\n"
".quad 0x3233752e766f6d09,0x202c303672250920,0x305f744c240a3b31,0x0a3a32343630385f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465,0x090a34313335345f\n"
".quad 0x203233752e766f6d,0x32202c3537722509,0x2e70746573090a3b,0x09203233752e656c\n"
".quad 0x7225202c38337025,0x35377225202c3635,0x3833702540090a3b,0x4c24092061726220\n"
".quad 0x373132385f305f74,0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313335345f305f74,0x732e766f6d090a34,0x3637722509203233,0x744c240a3b32202c\n"
".quad 0x30393632385f305f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x202c37363320656e,0x20676e697473656e,0x31203a6874706564,0x616d69747365202c\n"
".quad 0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75,0x363109636f6c2e09\n"
".quad 0x090a300939383309,0x203233752e726873,0x25202c3036722509,0x0a3b31202c303672\n"
".quad 0x363109636f6c2e09,0x090a300930393309,0x636e79732e726162,0x7573090a3b300920\n"
".quad 0x2509203233752e62,0x377225202c373772,0x73090a3b31202c36,0x752e65672e707465\n"
".quad 0x3933702509203233,0x25202c357225202c,0x2540090a3b373772,0x2061726220393370\n"
".quad 0x385f305f744c2409,0x2f200a3b36343932,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3320656e696c2079,0x64616568202c3736,0x64656c6562616c20\n"
".quad 0x385f305f744c2420,0x6c2e090a30393632,0x393309363109636f,0x646461090a300937\n"
".quad 0x722509203233752e,0x2c357225202c3837,0x726873090a3b3120,0x722509203233752e\n"
".quad 0x30367225202c3937,0x756d090a3b31202c,0x3233752e6f6c2e6c,0x202c303872250920\n"
".quad 0x7225202c38377225,0x646461090a3b3036,0x722509203233752e,0x39377225202c3138\n"
".quad 0x0a3b30387225202c,0x3436752e74766309,0x722509203233752e,0x387225202c393264\n"
".quad 0x2e6c756d090a3b31,0x3233752e65646977,0x2c30336472250920,0x32202c3138722520\n"
".quad 0x752e646461090a3b,0x3364722509203436,0x2c33647225202c31,0x0a3b303364722520\n"
".quad 0x726168732e646c09,0x09203631752e6465,0x255b202c39687225,0x3b5d302b31336472\n"
".quad 0x36752e747663090a,0x2509203233752e34,0x7225202c32336472,0x6c756d090a3b3038\n"
".quad 0x33752e656469772e,0x3333647225092032,0x202c30387225202c,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x33647225202c3433,0x3b3333647225202c,0x6168732e646c090a\n"
".quad 0x203631752e646572,0x202c303168722509,0x302b34336472255b,0x2e646461090a3b5d\n"
".quad 0x6872250920363175,0x39687225202c3131,0x3b3031687225202c,0x6168732e7473090a\n"
".quad 0x203631752e646572,0x2b31336472255b09,0x31687225202c5d30,0x305f744c240a3b31\n"
".quad 0x0a3a36343932385f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c37363320,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a30393632385f,0x09363109636f6c2e,0x73090a3009373833,0x09203233622e6c68\n"
".quad 0x7225202c36377225,0x090a3b31202c3637,0x2e746c2e70746573,0x3470250920323375\n"
".quad 0x2c36377225202c30,0x090a3b3635722520,0x7262203034702540,0x305f744c24092061\n"
".quad 0x0a3b30393632385f,0x32385f305f744c24,0x2f2f200a3a383731,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353220656e696c20,0x2064616568202c36\n"
".quad 0x2064656c6562616c,0x35345f305f744c24,0x6f6c2e090a343133,0x3230340936310963\n"
".quad 0x2e726162090a3009,0x3b300920636e7973,0x3109636f6c2e090a,0x0a30093833330937\n"
".quad 0x726168732e646c09,0x09203233752e6465,0x5f5b202c32387225,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3835363632,0x7268745f6d756e5f,0x7463615f73646165\n"
".quad 0x6d090a3b5d657669,0x09203233752e766f,0x3b31202c33387225,0x71652e746573090a\n"
".quad 0x3233752e3233752e,0x202c343872250920,0x7225202c34317225,0x67656e090a3b3338\n"
".quad 0x722509203233732e,0x34387225202c3538,0x672e746573090a3b,0x33752e3233752e74\n"
".quad 0x2c36387225092032,0x25202c3238722520,0x67656e090a3b3572,0x722509203233732e\n"
".quad 0x36387225202c3738,0x622e646e61090a3b,0x3838722509203233,0x202c35387225202c\n"
".quad 0x6d090a3b37387225,0x09203233752e766f,0x3b30202c39387225,0x652e70746573090a\n"
".quad 0x2509203233732e71,0x387225202c313470,0x3b39387225202c38,0x203134702540090a\n"
".quad 0x744c240920617262,0x34313733385f305f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34313335345f305f,0x3109636f6c2e090a,0x0a30093034340936\n"
".quad 0x726168732e646c09,0x09203631752e6465,0x255b202c30397225,0x0a3b5d302b386472\n"
".quad 0x373109636f6c2e09,0x090a300938333309,0x65726168732e646c,0x2509203233752e64\n"
".quad 0x5f5f5b202c323872,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f38353636\n"
".quad 0x657268745f6d756e,0x697463615f736461,0x6c2e090a3b5d6576,0x343409363109636f\n"
".quad 0x646461090a300930,0x722509203233752e,0x32387225202c3139,0x0a3b30397225202c\n"
".quad 0x363109636f6c2e09,0x090a300932343409,0x2e3436752e747663,0x6472250920323375\n"
".quad 0x31397225202c3533,0x772e6c756d090a3b,0x203233752e656469,0x202c363364722509\n"
".quad 0x3b34202c31397225,0x36752e646461090a,0x3733647225092034,0x2c3633647225202c\n"
".quad 0x090a3b3164722520,0x65726168732e7473,0x5b09203233662e64,0x5d302b3733647225\n"
".quad 0x090a3b356625202c,0x09363109636f6c2e,0x61090a3009333434,0x09203436752e6464\n"
".quad 0x25202c3833647225,0x7225202c36336472,0x2e7473090a3b3464,0x662e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3833,0x6f6c2e090a3b3666,0x3434340936310963\n"
".quad 0x2e6c756d090a3009,0x3233752e65646977,0x2c39336472250920,0x32202c3139722520\n"
".quad 0x752e747663090a3b,0x09203233752e3631,0x7225202c32397225,0x646461090a3b3932\n"
".quad 0x722509203436752e,0x647225202c303464,0x32647225202c3933,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x30346472255b0920,0x397225202c5d302b,0x636f6c2e090a3b32\n"
".quad 0x0935343409363109,0x752e747663090a30,0x09203233752e3631,0x7225202c33397225\n"
".quad 0x2e646461090a3b33,0x6472250920343675,0x33647225202c3134,0x3b35647225202c39\n"
".quad 0x6168732e7473090a,0x203631752e646572,0x2b31346472255b09,0x33397225202c5d30\n"
".quad 0x5f305f744c240a3b,0x240a3a3431373338,0x3130385f305f744c,0x3c2f2f200a3a3033\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x36353220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3335345f305f744c,0x636f6c2e090a3431\n"
".quad 0x0934343309373109,0x732e726162090a30,0x0a3b300920636e79,0x6220317025214009\n"
".quad 0x5f744c2409206172,0x3b36323234385f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34313335345f30,0x373109636f6c2e09,0x090a300930353309\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5f5b202c343972,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f38353636,0x657268745f6d756e,0x697463615f736461\n"
".quad 0x7663090a3b5d6576,0x33752e3436752e74,0x3234647225092032,0x0a3b34397225202c\n"
".quad 0x6469772e6c756d09,0x2509203233752e65,0x7225202c33346472,0x090a3b32202c3439\n"
".quad 0x203436752e646461,0x202c343464722509,0x7225202c33647225,0x646c090a3b333464\n"
".quad 0x2e6465726168732e,0x3972250920363175,0x346472255b202c35,0x61090a3b5d302b34\n"
".quad 0x09203233752e6464,0x7225202c32387225,0x35397225202c3439,0x68732e7473090a3b\n"
".quad 0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x353636325f726176\n"
".quad 0x6d756e5f30345f38,0x736461657268745f,0x5d6576697463615f,0x0a3b32387225202c\n"
".quad 0x373109636f6c2e09,0x090a300931353309,0x203233732e627573,0x25202c3639722509\n"
".quad 0x0a3b31202c323872,0x3233622e646e6109,0x202c373972250920,0x7225202c32387225\n"
".quad 0x766f6d090a3b3639,0x722509203233752e,0x090a3b30202c3839,0x2e656e2e70746573\n"
".quad 0x3470250920323373,0x2c37397225202c32,0x090a3b3839722520,0x7262203234702540\n"
".quad 0x305f744c24092061,0x0a3b38333734385f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461\n"
".quad 0x305f744c24206465,0x090a34313335345f,0x203233732e766f6d,0x25202c3939722509\n"
".quad 0x7262090a3b323872,0x240920696e752e61,0x5f69646e6557444c,0x325f667078657266\n"
".quad 0x4c240a3b325f3432,0x333734385f305f74,0x6c3c2f2f200a3a38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x3009353832093931\n"
".quad 0x6e722e747663090a,0x3233732e3233662e,0x202c313766250920,0x6d090a3b32387225\n"
".quad 0x09203233662e766f,0x6625202c32376625,0x736261090a3b3137,0x662509203233662e\n"
".quad 0x31376625202c3337,0x662e766f6d090a3b,0x3437662509203233,0x303830306630202c\n"
".quad 0x2020203b30303030,0x312e31202f2f0920,0x38332d6539343537,0x6c2e70746573090a\n"
".quad 0x2509203233662e74,0x376625202c333470,0x3b34376625202c33,0x333470252140090a\n"
".quad 0x4c24092061726220,0x303535385f305f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36353220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313335345f305f74,0x09636f6c2e090a34,0x0939353332093132\n"
".quad 0x662e766f6d090a30,0x3537662509203233,0x303862346630202c,0x2020203b30303030\n"
".quad 0x362e31202f2f0920,0x37302b6532373737,0x33662e6c756d090a,0x2c32376625092032\n"
".quad 0x25202c3137662520,0x6f6d090a3b353766,0x2509203233752e76,0x3432202c30303172\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b30353235385f30,0x385f305f744c240a\n"
".quad 0x2f200a3a36303535,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3635,0x64656c6562616c20,0x345f305f744c2420\n"
".quad 0x6c2e090a34313335,0x333209313209636f,0x6f6d090a30093236,0x2509203233752e76\n"
".quad 0x3b30202c30303172,0x385f305f744c240a,0x2f200a3a30353235,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3635\n"
".quad 0x64656c6562616c20,0x345f305f744c2420,0x6c2e090a34313335,0x373709363109636f\n"
".quad 0x2e766f6d090a3009,0x3172250920323362,0x32376625202c3130,0x732e726873090a3b\n"
".quad 0x3031722509203233,0x3130317225202c32,0x61090a3b3332202c,0x09203233622e646e\n"
".quad 0x25202c3330317225,0x3532202c32303172,0x2e766f6d090a3b35,0x3172250920323375\n"
".quad 0x090a3b30202c3430,0x203233752e627573,0x202c353031722509,0x25202c3330317225\n"
".quad 0x73090a3b30303172,0x09203233752e6275,0x25202c3630317225,0x3231202c35303172\n"
".quad 0x2e766f6d090a3b36,0x3172250920323375,0x3b353532202c3730,0x71652e746573090a\n"
".quad 0x3233752e3233752e,0x2c38303172250920,0x202c333031722520,0x090a3b3730317225\n"
".quad 0x203233732e67656e,0x202c393031722509,0x090a3b3830317225,0x203233662e766f6d\n"
".quad 0x30202c3637662509,0x3030303030303066,0x2f09202020203b30,0x746573090a30202f\n"
".quad 0x2e3233752e71652e,0x3172250920323366,0x33376625202c3031,0x0a3b36376625202c\n"
".quad 0x3233732e67656e09,0x2c31313172250920,0x0a3b303131722520,0x203233622e726f09\n"
".quad 0x202c323131722509,0x25202c3930317225,0x6e090a3b31313172,0x09203233732e6765\n"
".quad 0x25202c3331317225,0x73090a3b32313172,0x2e3233752e74636c,0x3172250920323373\n"
".quad 0x30317225202c3431,0x3430317225202c36,0x3b3331317225202c,0x33622e6c6873090a\n"
".quad 0x2c39397225092032,0x31317225202c3120,0x6557444c240a3b34,0x786572665f69646e\n"
".quad 0x325f3432325f6670,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36353220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x34313335345f305f,0x3109636f6c2e090a,0x0a30093135330937,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f31363636325f72\n"
".quad 0x745f6d756e5f3034,0x635f736461657268,0x6f69746361706d6f,0x39397225202c5d6e\n"
".quad 0x09636f6c2e090a3b,0x3009333533093731,0x33752e766f6d090a,0x3531317225092032\n"
".quad 0x7473090a3b30202c,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f33353636,0x5f746361706d6f63,0x635f646e6f636573\n"
".quad 0x25202c5d6b6e7568,0x2e090a3b35313172,0x3309373109636f6c,0x6f6d090a30093435\n"
".quad 0x2509203233752e76,0x3b31202c36313172,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x616475635f5f5b09,0x765f6c61636f6c5f,0x35353636325f7261,0x5f6c6c615f30345f\n"
".quad 0x5f73646165726874,0x65677265766e6f63,0x31317225202c5d64,0x305f744c240a3b36\n"
".quad 0x0a3a36323234385f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36353220,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a34313335345f,0x09373109636f6c2e,0x62090a3009373533,0x20636e79732e7261\n"
".quad 0x6f6c2e090a3b3009,0x3036330937310963,0x732e646c090a3009,0x33752e6465726168\n"
".quad 0x3731317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x363636325f726176\n"
".quad 0x6d756e5f30345f31,0x736461657268745f,0x746361706d6f635f,0x73090a3b5d6e6f69\n"
".quad 0x752e74672e707465,0x3434702509203233,0x2c3731317225202c,0x090a3b3331722520\n"
".quad 0x7262203434702540,0x305f744c24092061,0x3b3230383830315f,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3635322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34313335345f30,0x696e752e61726209\n"
".quad 0x5f305f744c240920,0x240a3b3431333534,0x3830315f305f744c,0x744c240a3a323038\n"
".quad 0x0a3a3835325f305f,0x373109636f6c2e09,0x090a300934363309,0x636e79732e726162\n"
".quad 0x6c2e090a3b300920,0x373309373109636f,0x2e646c090a300939,0x752e646572616873\n"
".quad 0x2c31722509203631,0x2b32316472255b20,0x6f6c2e090a3b5d30,0x3038330937310963\n"
".quad 0x732e646c090a3009,0x31752e6465726168,0x202c337225092036,0x302b33316472255b\n"
".quad 0x2e646461090a3b5d,0x3172250920323375,0x33317225202c3831,0x090a3b357225202c\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x31317225202c3534,0x2e6c756d090a3b38\n"
".quad 0x3233752e65646977,0x2c36346472250920,0x202c383131722520,0x732e646c090a3b32\n"
".quad 0x33752e6465726168,0x3931317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x353636325f726176,0x6d756e5f30345f38,0x736461657268745f,0x5d6576697463615f\n"
".quad 0x2e70746573090a3b,0x09203233752e656c,0x7225202c35347025,0x317225202c393131\n"
".quad 0x702540090a3b3831,0x0920617262203534,0x35385f305f744c24,0x6c2e090a3b323637\n"
".quad 0x383309373109636f,0x646461090a300934,0x722509203436752e,0x647225202c373464\n"
".quad 0x32647225202c3634,0x68732e646c090a3b,0x3631752e64657261,0x2c30323172250920\n"
".quad 0x2b37346472255b20,0x766f6d090a3b5d30,0x722509203233732e,0x317225202c313231\n"
".quad 0x6f6c2e090a3b3032,0x3538330937310963,0x2e646461090a3009,0x6472250920343675\n"
".quad 0x34647225202c3834,0x3b35647225202c36,0x6168732e646c090a,0x203631752e646572\n"
".quad 0x202c323231722509,0x302b38346472255b,0x2e766f6d090a3b5d,0x3172250920323373\n"
".quad 0x32317225202c3332,0x305f744c240a3b32,0x0a3a32363735385f,0x6220317025214009\n"
".quad 0x5f744c2409206172,0x3b34373236385f30,0x3109636f6c2e090a,0x0a30093130340937\n"
".quad 0x3631752e766f6d09,0x2c32316872250920,0x2e7473090a3b3020,0x752e646572616873\n"
".quad 0x635f5f5b09203631,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3636325f7261765f\n"
".quad 0x5f735f32345f3434,0x756f635f7466656c,0x302b30383132746e,0x3231687225202c5d\n"
".quad 0x09636f6c2e090a3b,0x3009323034093731,0x31752e766f6d090a,0x3331687225092036\n"
".quad 0x7473090a3b30202c,0x2e6465726168732e,0x5f5f5b0920363175,0x635f5f5f61647563\n"
".quad 0x61636f6c5f616475,0x36325f7261765f6c,0x735f32345f353436,0x635f74686769725f\n"
".quad 0x34383236746e756f,0x687225202c5d302b,0x5f744c240a3b3331,0x3a34373236385f30\n"
".quad 0x3109636f6c2e090a,0x0a30093530340937,0x6e79732e72616209,0x6d090a3b30092063\n"
".quad 0x09203436752e766f,0x5f202c3934647225,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f32345f34343836,0x6c65685f6c635f73,0x3b30313337726570\n"
".quad 0x3109636f6c2e090a,0x0a30093531340937,0x3233752e62757309,0x2c34323172250920\n"
".quad 0x7225202c33722520,0x2e766f6d090a3b31,0x3172250920323375,0x090a3b31202c3532\n"
".quad 0x2e71652e70746573,0x3470250920323375,0x3432317225202c36,0x3b3532317225202c\n"
".quad 0x732e706c6573090a,0x3231722509203233,0x2c30202c31202c36,0x090a3b3634702520\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x5d322b3231647225,0x3b3632317225202c\n"
".quad 0x3109636f6c2e090a,0x0a30093631340937,0x3233752e766f6d09,0x2c37323172250920\n"
".quad 0x746573090a3b3120,0x3233752e656e2e70,0x202c373470250920,0x25202c3432317225\n"
".quad 0x73090a3b37323172,0x203233732e706c65,0x202c383231722509,0x7025202c30202c31\n"
".quad 0x2e7473090a3b3734,0x752e646572616873,0x6472255b09203631,0x25202c5d322b3331\n"
".quad 0x2e090a3b38323172,0x3409373109636f6c,0x6f6d090a30093931,0x2509203233752e76\n"
".quad 0x3b30202c39323172,0x752e706c6573090a,0x3331722509203233,0x3432317225202c30\n"
".quad 0x2c3932317225202c,0x090a3b3734702520,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x2c5d322b38647225,0x0a3b303331722520,0x373109636f6c2e09,0x090a300930323409\n"
".quad 0x203436752e646461,0x202c303564722509,0x7225202c37647225,0x6f6d090a3b393464\n"
".quad 0x2509203631752e76,0x3b30202c34316872,0x6168732e7473090a,0x203631752e646572\n"
".quad 0x2b30356472255b09,0x31687225202c5d30,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x34647225202c3135,0x3934647225202c36,0x68732e646c090a3b,0x3233752e64657261\n"
".quad 0x2c31333172250920,0x616475635f5f5b20,0x765f6c61636f6c5f,0x38353636325f7261\n"
".quad 0x5f6d756e5f30345f,0x5f73646165726874,0x3b5d657669746361,0x6c2e70746573090a\n"
".quad 0x2509203233752e65,0x317225202c383470,0x31317225202c3133,0x34702540090a3b38\n"
".quad 0x2409206172622038,0x3037385f305f744c,0x6f6c2e090a3b3234,0x3532340937310963\n"
".quad 0x2e766f6d090a3009,0x3172250920323373,0x32317225202c3233,0x2e766f6d090a3b33\n"
".quad 0x3172250920323373,0x32317225202c3333,0x2e627573090a3b31,0x3172250920323375\n"
".quad 0x33317225202c3433,0x3333317225202c32,0x752e766f6d090a3b,0x3331722509203233\n"
".quad 0x73090a3b31202c35,0x752e71652e707465,0x3934702509203233,0x2c3433317225202c\n"
".quad 0x0a3b353331722520,0x33732e706c657309,0x3633317225092032,0x202c30202c31202c\n"
".quad 0x6d090a3b39347025,0x09203233732e766f,0x25202c3733317225,0x2e090a3b36333172\n"
".quad 0x3409373109636f6c,0x6461090a30093732,0x2509203436752e64,0x7225202c32356472\n"
".quad 0x647225202c363464,0x732e7473090a3b32,0x31752e6465726168,0x356472255b092036\n"
".quad 0x7225202c5d322b32,0x6c2e090a3b363331,0x323409373109636f,0x766f6d090a300938\n"
".quad 0x722509203233752e,0x0a3b31202c383331,0x656e2e7074657309,0x702509203233752e\n"
".quad 0x33317225202c3035,0x3833317225202c34,0x2e706c6573090a3b,0x3172250920323373\n"
".quad 0x30202c31202c3933,0x0a3b30357025202c,0x3436752e64646109,0x2c33356472250920\n"
".quad 0x202c363464722520,0x73090a3b35647225,0x6465726168732e74,0x255b09203631752e\n"
".quad 0x2c5d322b33356472,0x0a3b393331722520,0x373109636f6c2e09,0x090a300931333409\n"
".quad 0x203233752e766f6d,0x202c303431722509,0x706c6573090a3b30,0x722509203233752e\n"
".quad 0x317225202c313431,0x34317225202c3433,0x3b30357025202c30,0x36752e646461090a\n"
".quad 0x3435647225092034,0x2c3634647225202c,0x090a3b3364722520,0x65726168732e7473\n"
".quad 0x5b09203631752e64,0x5d322b3435647225,0x3b3134317225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093233340937,0x3631752e766f6d09,0x2c35316872250920,0x2e7473090a3b3020\n"
".quad 0x752e646572616873,0x6472255b09203631,0x25202c5d302b3135,0x62090a3b35316872\n"
".quad 0x0920696e752e6172,0x36385f305f744c24,0x744c240a3b363837,0x32343037385f305f\n"
".quad 0x752e766f6d090a3a,0x3431722509203233,0x0a3b323135202c32,0x74672e7074657309\n"
".quad 0x702509203233752e,0x31317225202c3135,0x3234317225202c38,0x3135702540090a3b\n"
".quad 0x4c24092061726220,0x393237385f305f74,0x636f6c2e090a3b38,0x0937333409373109\n"
".quad 0x752e766f6d090a30,0x3168722509203631,0x61090a3b30202c36,0x09203436752e6464\n"
".quad 0x25202c3535647225,0x7225202c36346472,0x2e7473090a3b3364,0x752e646572616873\n"
".quad 0x6472255b09203631,0x25202c5d322b3535,0x2e090a3b36316872,0x3409373109636f6c\n"
".quad 0x6f6d090a30093833,0x2509203631752e76,0x3b30202c37316872,0x6168732e7473090a\n"
".quad 0x203631752e646572,0x2b31356472255b09,0x31687225202c5d30,0x305f744c240a3b37\n"
".quad 0x0a3a38393237385f,0x3233752e766f6d09,0x2c37333172250920,0x5f744c240a3b3020\n"
".quad 0x3a36383736385f30,0x3109636f6c2e090a,0x0a30093234340937,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x5b202c3334317225,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f31363636325f,0x68745f6d756e5f30,0x6f635f7364616572,0x6e6f69746361706d\n"
".quad 0x636f6c2e090a3b5d,0x0936313809373109,0x752e726873090a30,0x3735722509203233\n"
".quad 0x2c3334317225202c,0x766f6d090a3b3120,0x722509203233732e,0x357225202c343431\n"
".quad 0x2e766f6d090a3b37,0x3172250920323375,0x090a3b30202c3534,0x2e656c2e70746573\n"
".quad 0x3570250920323373,0x2c37357225202c32,0x0a3b353431722520,0x6220323570254009\n"
".quad 0x5f744c2409206172,0x3833333031315f30,0x752e766f6d090a3b,0x3431722509203233\n"
".quad 0x4c240a3b31202c36,0x323338385f305f74,0x6c3c2f2f200a3a32,0x6f6f4c203e706f6f\n"
".quad 0x6c2079646f622070,0x0a38313820656e69,0x373109636f6c2e09,0x090a300938313809\n"
".quad 0x636e79732e726162,0x6573090a3b300920,0x33752e656c2e7074,0x2c33357025092032\n"
".quad 0x202c343431722520,0x2540090a3b357225,0x2061726220333570,0x395f305f744c2409\n"
".quad 0x2f200a3b34313130,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3820656e696c2079,0x64616568202c3831,0x64656c6562616c20,0x385f305f744c2420\n"
".quad 0x6c2e090a32323338,0x323809373109636f,0x6c756d090a300935,0x33752e6f6c2e3432\n"
".quad 0x2c31367225092032,0x3b32202c35722520,0x33752e646461090a,0x3734317225092032\n"
".quad 0x202c31367225202c,0x2e646461090a3b31,0x3672250920323375,0x2c31367225202c33\n"
".quad 0x6c756d090a3b3220,0x203233752e6f6c2e,0x202c383431722509,0x25202c3734317225\n"
".quad 0x63090a3b36343172,0x752e3436752e7476,0x3564722509203233,0x3834317225202c36\n"
".quad 0x772e6c756d090a3b,0x203233752e656469,0x202c373564722509,0x32202c3834317225\n"
".quad 0x6c2e6c756d090a3b,0x2509203233752e6f,0x7225202c39343172,0x34317225202c3336\n"
".quad 0x2e747663090a3b36,0x203233752e343675,0x202c383564722509,0x090a3b3934317225\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x317225202c393564,0x090a3b32202c3934\n"
".quad 0x203436752e646461,0x202c303664722509,0x25202c3935647225,0x646c090a3b326472\n"
".quad 0x2e6465726168732e,0x6872250920363175,0x6472255b202c3831,0x090a3b5d302b3036\n"
".quad 0x203436752e646461,0x202c313664722509,0x25202c3735647225,0x646c090a3b326472\n"
".quad 0x2e6465726168732e,0x6872250920363175,0x6472255b202c3931,0x090a3b5d302b3136\n"
".quad 0x203631752e646461,0x202c303268722509,0x25202c3831687225,0x73090a3b39316872\n"
".quad 0x6465726168732e74,0x255b09203631752e,0x2c5d302b30366472,0x0a3b303268722520\n"
".quad 0x373109636f6c2e09,0x090a300936323809,0x203436752e646461,0x202c323664722509\n"
".quad 0x25202c3935647225,0x646c090a3b356472,0x2e6465726168732e,0x6872250920363175\n"
".quad 0x6472255b202c3132,0x090a3b5d302b3236,0x203436752e646461,0x202c333664722509\n"
".quad 0x25202c3735647225,0x646c090a3b356472,0x2e6465726168732e,0x6872250920363175\n"
".quad 0x6472255b202c3232,0x090a3b5d302b3336,0x203631752e646461,0x202c333268722509\n"
".quad 0x25202c3132687225,0x73090a3b32326872,0x6465726168732e74,0x255b09203631752e\n"
".quad 0x2c5d302b32366472,0x0a3b333268722520,0x373109636f6c2e09,0x090a300932323809\n"
".quad 0x203436752e646461,0x202c343664722509,0x25202c3735647225,0x61090a3b39346472\n"
".quad 0x09203436752e6464,0x25202c3536647225,0x7225202c39356472,0x646c090a3b393464\n"
".quad 0x2e6465726168732e,0x3172250920363175,0x6472255b202c3035,0x0a3b5d322d2b3436\n"
".quad 0x3233752e766f6d09,0x2c31353172250920,0x746573090a3b3120,0x3233752e656e2e70\n"
".quad 0x202c343570250920,0x25202c3035317225,0x40090a3b31353172,0x6172622034357025\n"
".quad 0x365f305f4c240920,0x2f200a3b32323139,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3820656e696c2079,0x64616568202c3831,0x64656c6562616c20\n"
".quad 0x385f305f744c2420,0x646c090a32323338,0x2e6465726168732e,0x3172250920363175\n"
".quad 0x6472255b202c3235,0x0a3b5d322d2b3536,0x3233752e766f6d09,0x2c33353172250920\n"
".quad 0x746573090a3b3120,0x3233752e71652e70,0x202c353570250920,0x25202c3235317225\n"
".quad 0x40090a3b33353172,0x6172622035357025,0x5f305f744c240920,0x240a3b3431313039\n"
".quad 0x323139365f305f4c,0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38313820656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x323338385f305f74,0x752e766f6d090a32,0x3531722509203233,0x6c090a3b31202c34\n"
".quad 0x6465726168732e64,0x722509203631752e,0x72255b202c303531,0x3b5d322d2b343664\n"
".quad 0x6e2e70746573090a,0x2509203233752e65,0x317225202c363570,0x35317225202c3035\n"
".quad 0x35702540090a3b34,0x2409206172622036,0x3339385f305f744c,0x3c2f2f200a3b3634\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x38313820656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3338385f305f744c,0x636f6c2e090a3232\n"
".quad 0x0939333809373109,0x752e766f6d090a30,0x3268722509203631,0x73090a3b31202c34\n"
".quad 0x6465726168732e74,0x255b09203631752e,0x5d322d2b35366472,0x3b3432687225202c\n"
".quad 0x6e752e617262090a,0x305f744c24092069,0x0a3b34313130395f,0x39385f305f744c24\n"
".quad 0x2f2f200a3a363433,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x313820656e696c20,0x2064616568202c38,0x2064656c6562616c,0x38385f305f744c24\n"
".quad 0x2e646c090a323233,0x752e646572616873,0x3531722509203631,0x366472255b202c35\n"
".quad 0x090a3b5d322d2b35,0x203233752e766f6d,0x202c363531722509,0x70746573090a3b31\n"
".quad 0x203233752e656e2e,0x25202c3735702509,0x7225202c35353172,0x2540090a3b363531\n"
".quad 0x2061726220373570,0x385f305f744c2409,0x2f200a3b38353839,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3820656e696c2079,0x64616568202c3831\n"
".quad 0x64656c6562616c20,0x385f305f744c2420,0x6c2e090a32323338,0x343809373109636f\n"
".quad 0x766f6d090a300933,0x722509203631752e,0x0a3b31202c353268,0x726168732e747309\n"
".quad 0x09203631752e6465,0x2d2b34366472255b,0x32687225202c5d32,0x2e617262090a3b35\n"
".quad 0x744c240920696e75,0x34313130395f305f,0x5f305f744c240a3b,0x200a3a3835383938\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383138,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3232333838\n"
".quad 0x3809373109636f6c,0x6461090a30093734,0x2509203436752e64,0x7225202c36366472\n"
".quad 0x647225202c373564,0x2e646461090a3b33,0x6472250920343675,0x35647225202c3736\n"
".quad 0x3b33647225202c39,0x6168732e646c090a,0x203631752e646572,0x202c373531722509\n"
".quad 0x302b36366472255b,0x732e646c090a3b5d,0x31752e6465726168,0x3835317225092036\n"
".quad 0x37366472255b202c,0x6461090a3b5d302b,0x2509203233732e64,0x7225202c39353172\n"
".quad 0x317225202c373531,0x766f6d090a3b3835,0x722509203233752e,0x363532202c303631\n"
".quad 0x2e70746573090a3b,0x09203233752e656c,0x7225202c38357025,0x317225202c393531\n"
".quad 0x702540090a3b3036,0x0920617262203835,0x30395f305f744c24,0x2f2f200a3b303733\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313820656e696c20\n"
".quad 0x2064616568202c38,0x2064656c6562616c,0x38385f305f744c24,0x6f6c2e090a323233\n"
".quad 0x3135380937310963,0x2e766f6d090a3009,0x6872250920363175,0x090a3b31202c3632\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x322d2b3436647225,0x3632687225202c5d\n"
".quad 0x09636f6c2e090a3b,0x3009323538093731,0x31752e766f6d090a,0x3732687225092036\n"
".quad 0x7473090a3b31202c,0x2e6465726168732e,0x72255b0920363175,0x2c5d322d2b353664\n"
".quad 0x0a3b373268722520,0x696e752e61726209,0x5f305f744c240920,0x240a3b3431313039\n"
".quad 0x3330395f305f744c,0x3c2f2f200a3a3037,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x38313820656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3338385f305f744c,0x636f6c2e090a3232,0x0936353809373109,0x68732e7473090a30\n"
".quad 0x3631752e64657261,0x37366472255b0920,0x317225202c5d302b,0x6f6c2e090a3b3935\n"
".quad 0x3735380937310963,0x2e766f6d090a3009,0x6872250920363175,0x090a3b30202c3832\n"
".quad 0x65726168732e7473,0x5b09203631752e64,0x5d302b3636647225,0x3b3832687225202c\n"
".quad 0x395f305f744c240a,0x4c240a3a34313130,0x303639385f305f74,0x305f744c240a3a32\n"
".quad 0x0a3a30393039385f,0x3838365f305f4c24,0x5f744c240a3a3636,0x3a38373538385f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3831382065,0x6562616c20646165,0x5f744c242064656c,0x0a32323338385f30\n"
".quad 0x373109636f6c2e09,0x090a300934363809,0x203233622e6c6873,0x202c363431722509\n"
".quad 0x31202c3634317225,0x09636f6c2e090a3b,0x3009363138093731,0x33732e726873090a\n"
".quad 0x3434317225092032,0x2c3434317225202c,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x0a3b30202c313631,0x74672e7074657309,0x702509203233732e,0x34317225202c3935\n"
".quad 0x3136317225202c34,0x3935702540090a3b,0x4c24092061726220,0x323338385f305f74\n"
".quad 0x2e617262090a3b32,0x744c240920696e75,0x30313837385f305f,0x5f305f744c240a3b\n"
".quad 0x0a3a383333303131,0x3233752e766f6d09,0x2c36343172250920,0x5f744c240a3b3120\n"
".quad 0x3a30313837385f30,0x33752e766f6d090a,0x3236317225092032,0x6573090a3b32202c\n"
".quad 0x33752e656c2e7074,0x2c30367025092032,0x202c333431722520,0x090a3b3236317225\n"
".quad 0x7262203036702540,0x305f744c24092061,0x0a3b32383830395f,0x3233732e766f6d09\n"
".quad 0x2c33363172250920,0x5f744c240a3b3220,0x3a34393331395f30,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3631382065,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09373109636f6c2e,0x73090a3009323738,0x09203233752e7268\n"
".quad 0x25202c3634317225,0x3b31202c36343172,0x3109636f6c2e090a,0x0a30093337380937\n"
".quad 0x6e79732e72616209,0x73090a3b30092063,0x09203233752e6275,0x25202c3436317225\n"
".quad 0x3b31202c33363172,0x672e70746573090a,0x2509203233752e65,0x357225202c313670\n"
".quad 0x3b3436317225202c,0x203136702540090a,0x744c240920617262,0x30353631395f305f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c36313820656e,0x62616c2064616568,0x744c242064656c65,0x34393331395f305f\n"
".quad 0x3109636f6c2e090a,0x0a30093138380937,0x3233752e64646109,0x202c383772250920\n"
".quad 0x0a3b31202c357225,0x3233752e72687309,0x2c35363172250920,0x202c363431722520\n"
".quad 0x2e6c756d090a3b31,0x09203233752e6f6c,0x25202c3636317225,0x317225202c383772\n"
".quad 0x747663090a3b3634,0x3233752e3436752e,0x2c38366472250920,0x0a3b363631722520\n"
".quad 0x6469772e6c756d09,0x2509203233752e65,0x7225202c39366472,0x0a3b32202c363631\n"
".quad 0x3233752e64646109,0x2c37363172250920,0x202c353631722520,0x090a3b3636317225\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x36317225202c3037,0x2e6c756d090a3b37\n"
".quad 0x3233752e65646977,0x2c31376472250920,0x202c373631722520,0x2e646461090a3b32\n"
".quad 0x6472250920343675,0x37647225202c3237,0x3b32647225202c31,0x6168732e646c090a\n"
".quad 0x203631752e646572,0x202c393268722509,0x302b32376472255b,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x36647225202c3337,0x3b32647225202c39,0x6168732e646c090a\n"
".quad 0x203631752e646572,0x202c303368722509,0x302b33376472255b,0x2e646461090a3b5d\n"
".quad 0x6872250920363175,0x32687225202c3133,0x3033687225202c39,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x32376472255b0920,0x687225202c5d302b,0x6f6c2e090a3b3133\n"
".quad 0x3238380937310963,0x2e646461090a3009,0x6472250920343675,0x37647225202c3437\n"
".quad 0x3b35647225202c31,0x6168732e646c090a,0x203631752e646572,0x202c323368722509\n"
".quad 0x302b34376472255b,0x2e646461090a3b5d,0x6472250920343675,0x36647225202c3537\n"
".quad 0x3b35647225202c39,0x6168732e646c090a,0x203631752e646572,0x202c333368722509\n"
".quad 0x302b35376472255b,0x2e646461090a3b5d,0x6872250920363175,0x33687225202c3433\n"
".quad 0x3333687225202c32,0x68732e7473090a3b,0x3631752e64657261,0x34376472255b0920\n"
".quad 0x687225202c5d302b,0x5f744c240a3b3433,0x3a30353631395f30,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3631382065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a34393331395f30,0x373109636f6c2e09\n"
".quad 0x090a300930373809,0x203233622e6c6873,0x202c333631722509,0x31202c3336317225\n"
".quad 0x2e70746573090a3b,0x09203233752e746c,0x7225202c32367025,0x317225202c333631\n"
".quad 0x702540090a3b3334,0x0920617262203236,0x31395f305f744c24,0x744c240a3b343933\n"
".quad 0x32383830395f305f,0x09636f6c2e090a3a,0x3009353434093731,0x6168732e646c090a\n"
".quad 0x203233732e646572,0x202c383631722509,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f38353636325f72,0x745f6d756e5f3034,0x615f736461657268,0x0a3b5d6576697463\n"
".quad 0x726168732e646c09,0x09203233732e6465,0x5b202c3936317225,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x345f31363636325f,0x68745f6d756e5f30,0x6f635f7364616572\n"
".quad 0x6e6f69746361706d,0x636f6c2e090a3b5d,0x0939343709373109,0x752e726873090a30\n"
".quad 0x3735722509203233,0x2c3936317225202c,0x766f6d090a3b3120,0x722509203233732e\n"
".quad 0x357225202c303731,0x2e766f6d090a3b37,0x3172250920323375,0x090a3b30202c3137\n"
".quad 0x2e656c2e70746573,0x3670250920323373,0x2c37357225202c33,0x0a3b313731722520\n"
".quad 0x6220333670254009,0x5f744c2409206172,0x3236333131315f30,0x752e766f6d090a3b\n"
".quad 0x3731722509203233,0x4c240a3b31202c32,0x333932395f305f74,0x6c3c2f2f200a3a30\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x0a31353720656e69,0x373109636f6c2e09\n"
".quad 0x090a300931353709,0x636e79732e726162,0x6573090a3b300920,0x33752e656c2e7074\n"
".quad 0x2c34367025092032,0x202c303731722520,0x2540090a3b357225,0x2061726220343670\n"
".quad 0x395f305f744c2409,0x2f200a3b36383133,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3720656e696c2079,0x64616568202c3135,0x64656c6562616c20\n"
".quad 0x395f305f744c2420,0x6c2e090a30333932,0x353709373109636f,0x6c756d090a300938\n"
".quad 0x33752e6f6c2e3432,0x2c31367225092032,0x3b32202c35722520,0x33752e646461090a\n"
".quad 0x2c33367225092032,0x32202c3136722520,0x6c2e6c756d090a3b,0x2509203233752e6f\n"
".quad 0x7225202c33373172,0x37317225202c3336,0x2e747663090a3b32,0x203233752e343675\n"
".quad 0x202c363764722509,0x090a3b3337317225,0x656469772e6c756d,0x722509203233752e\n"
".quad 0x317225202c373764,0x090a3b32202c3337,0x203436752e646461,0x202c383764722509\n"
".quad 0x7225202c33647225,0x646c090a3b373764,0x2e6465726168732e,0x6872250920363175\n"
".quad 0x6472255b202c3533,0x090a3b5d302b3837,0x203233752e646461,0x202c343731722509\n"
".quad 0x3b31202c31367225,0x6f6c2e6c756d090a,0x722509203233752e,0x317225202c353731\n"
".quad 0x37317225202c3237,0x2e747663090a3b34,0x203233752e343675,0x202c393764722509\n"
".quad 0x090a3b3537317225,0x656469772e6c756d,0x722509203233752e,0x317225202c303864\n"
".quad 0x090a3b32202c3537,0x203436752e646461,0x202c313864722509,0x7225202c33647225\n"
".quad 0x646c090a3b303864,0x2e6465726168732e,0x6872250920363175,0x6472255b202c3633\n"
".quad 0x090a3b5d302b3138,0x203631752e646461,0x202c373368722509,0x25202c3533687225\n"
".quad 0x73090a3b36336872,0x6465726168732e74,0x255b09203631752e,0x2c5d302b38376472\n"
".quad 0x0a3b373368722520,0x33395f305f744c24,0x2f2f200a3a363831,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353720656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x32395f305f744c24,0x6f6c2e090a303339,0x3136370937310963\n"
".quad 0x2e6c756d090a3009,0x09203233752e6f6c,0x25202c3237317225,0x3b32202c32373172\n"
".quad 0x3109636f6c2e090a,0x0a30093934370937,0x3233732e72687309,0x2c30373172250920\n"
".quad 0x202c303731722520,0x2e766f6d090a3b31,0x3172250920323375,0x090a3b30202c3637\n"
".quad 0x2e74672e70746573,0x3670250920323373,0x3037317225202c35,0x3b3637317225202c\n"
".quad 0x203536702540090a,0x744c240920617262,0x30333932395f305f,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b38313432395f30,0x315f305f744c240a,0x090a3a3236333131\n"
".quad 0x203233752e766f6d,0x202c323731722509,0x305f744c240a3b31,0x0a3a38313432395f\n"
".quad 0x3233752e62757309,0x2c37373172250920,0x202c393631722520,0x2e766f6d090a3b31\n"
".quad 0x3172250920323375,0x090a3b32202c3837,0x2e656c2e70746573,0x3670250920323375\n"
".quad 0x3737317225202c36,0x3b3837317225202c,0x203636702540090a,0x744c240920617262\n"
".quad 0x34353933395f305f,0x732e766f6d090a3b,0x3731722509203233,0x4c240a3b32202c39\n"
".quad 0x363434395f305f74,0x6c3c2f2f200a3a36,0x6f6f4c203e706f6f,0x6c2079646f622070\n"
".quad 0x2c39343720656e69,0x676e697473656e20,0x203a687470656420,0x6d69747365202c31\n"
".quad 0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520,0x3109636f6c2e090a\n"
".quad 0x0a30093836370937,0x3233752e72687309,0x2c32373172250920,0x202c323731722520\n"
".quad 0x636f6c2e090a3b31,0x0939363709373109,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x3233752e62757309,0x2c30383172250920,0x202c393731722520,0x70746573090a3b31\n"
".quad 0x203233752e65672e,0x25202c3736702509,0x38317225202c3572,0x36702540090a3b30\n"
".quad 0x2409206172622037,0x3734395f305f744c,0x3c2f2f200a3b3232,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x39343720656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3434395f305f744c,0x636f6c2e090a3636,0x0936373709373109\n"
".quad 0x752e646461090a30,0x3837722509203233,0x31202c357225202c,0x752e726873090a3b\n"
".quad 0x3831722509203233,0x3237317225202c31,0x756d090a3b31202c,0x3233752e6f6c2e6c\n"
".quad 0x2c32383172250920,0x25202c3837722520,0x61090a3b32373172,0x09203233752e6464\n"
".quad 0x25202c3338317225,0x7225202c31383172,0x7663090a3b323831,0x33752e3436752e74\n"
".quad 0x3238647225092032,0x3b3338317225202c,0x69772e6c756d090a,0x09203233752e6564\n"
".quad 0x25202c3338647225,0x3b32202c33383172,0x36752e646461090a,0x3438647225092034\n"
".quad 0x202c33647225202c,0x090a3b3338647225,0x65726168732e646c,0x2509203631752e64\n"
".quad 0x255b202c38336872,0x3b5d302b34386472,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c35386472,0x756d090a3b323831,0x752e656469772e6c,0x3864722509203233\n"
".quad 0x3238317225202c36,0x6461090a3b32202c,0x2509203436752e64,0x7225202c37386472\n"
".quad 0x38647225202c3364,0x732e646c090a3b36,0x31752e6465726168,0x3933687225092036\n"
".quad 0x37386472255b202c,0x6461090a3b5d302b,0x2509203631752e64,0x7225202c30346872\n"
".quad 0x687225202c383368,0x2e7473090a3b3933,0x752e646572616873,0x6472255b09203631\n"
".quad 0x25202c5d302b3438,0x4c240a3b30346872,0x323734395f305f74,0x6c3c2f2f200a3a32\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c39343720656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363434395f305f74,0x09636f6c2e090a36\n"
".quad 0x3009363637093731,0x33622e6c6873090a,0x3937317225092032,0x2c3937317225202c\n"
".quad 0x746573090a3b3120,0x3233752e746c2e70,0x202c383670250920,0x25202c3937317225\n"
".quad 0x40090a3b37373172,0x6172622038367025,0x5f305f744c240920,0x240a3b3636343439\n"
".quad 0x3933395f305f744c,0x6f6c2e090a3a3435,0x3038370937310963,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x203170252140090a,0x744c240920617262,0x30393435395f305f\n"
".quad 0x09636f6c2e090a3b,0x3009373837093731,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x7225202c38386472,0x756d090a3b393631,0x752e656469772e6c,0x3864722509203233\n"
".quad 0x3936317225202c39,0x7663090a3b32202c,0x33752e3436752e74,0x3039647225092032\n"
".quad 0x3b3836317225202c,0x69772e6c756d090a,0x09203233752e6564,0x25202c3139647225\n"
".quad 0x3b32202c38363172,0x36752e646461090a,0x3239647225092034,0x2c3938647225202c\n"
".quad 0x0a3b393464722520,0x726168732e646c09,0x09203631752e6465,0x5b202c3134687225\n"
".quad 0x322d2b3239647225,0x2e646461090a3b5d,0x6472250920343675,0x39647225202c3339\n"
".quad 0x3934647225202c31,0x68732e7473090a3b,0x3631752e64657261,0x33396472255b0920\n"
".quad 0x7225202c5d322d2b,0x6c2e090a3b313468,0x383709373109636f,0x646461090a300939\n"
".quad 0x722509203436752e,0x647225202c343964,0x33647225202c3938,0x68732e646c090a3b\n"
".quad 0x3631752e64657261,0x2c32346872250920,0x2b34396472255b20,0x646461090a3b5d30\n"
".quad 0x722509203436752e,0x647225202c353964,0x33647225202c3139,0x68732e7473090a3b\n"
".quad 0x3631752e64657261,0x35396472255b0920,0x687225202c5d302b,0x5f744c240a3b3234\n"
".quad 0x3a30393435395f30,0x3109636f6c2e090a,0x0a30093934340937,0x6e79732e72616209\n"
".quad 0x6c090a3b30092063,0x6465726168732e64,0x722509203631752e,0x72255b202c343831\n"
".quad 0x0a3b5d302b303564,0x3233752e766f6d09,0x2c35383172250920,0x746573090a3b3120\n"
".quad 0x3233752e656e2e70,0x202c393670250920,0x25202c3438317225,0x40090a3b35383172\n"
".quad 0x6172622039367025,0x5f305f744c240920,0x090a3b3835323639,0x09373109636f6c2e\n"
".quad 0x6c090a3009333634,0x6465726168732e64,0x722509203631752e,0x72255b202c363831\n"
".quad 0x0a3b5d322b333164,0x3233752e64646109,0x2c37383172250920,0x202c363831722520\n"
".quad 0x636f6c2e090a3b31,0x0934363409373109,0x68732e646c090a30,0x3631752e64657261\n"
".quad 0x2c33346872250920,0x322b386472255b20,0x2e617262090a3b5d,0x744c240920696e75\n"
".quad 0x32303036395f305f,0x5f305f744c240a3b,0x090a3a3835323639,0x203631752e766f6d\n"
".quad 0x202c333468722509,0x2e766f6d090a3b30,0x3172250920323375,0x240a3b30202c3738\n"
".quad 0x3036395f305f744c,0x2e646c090a3a3230,0x752e646572616873,0x3831722509203631\n"
".quad 0x356472255b202c38,0x6d090a3b5d302b31,0x09203233752e766f,0x31202c3938317225\n"
".quad 0x2e70746573090a3b,0x09203233752e656e,0x7225202c30377025,0x317225202c383831\n"
".quad 0x702540090a3b3938,0x0920617262203037,0x36395f305f744c24,0x6c2e090a3b303737\n"
".quad 0x363409373109636f,0x646461090a300939,0x722509203436752e,0x647225202c363964\n"
".quad 0x35647225202c3634,0x68732e646c090a3b,0x3631752e64657261,0x2c30393172250920\n"
".quad 0x2b36396472255b20,0x646461090a3b5d32,0x722509203233752e,0x317225202c313931\n"
".quad 0x090a3b31202c3039,0x09373109636f6c2e,0x61090a3009303734,0x09203436752e6464\n"
".quad 0x25202c3739647225,0x7225202c36346472,0x2e646c090a3b3364,0x752e646572616873\n"
".quad 0x3468722509203631,0x396472255b202c34,0x62090a3b5d322b37,0x0920696e752e6172\n"
".quad 0x36395f305f744c24,0x744c240a3b343135,0x30373736395f305f,0x752e766f6d090a3a\n"
".quad 0x3468722509203631,0x6d090a3b30202c34,0x09203233752e766f,0x30202c3139317225\n"
".quad 0x5f305f744c240a3b,0x090a3a3431353639,0x09373109636f6c2e,0x6c090a3009333734\n"
".quad 0x6465726168732e64,0x722509203233752e,0x5f5f5b202c323931,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f31363636,0x657268745f6d756e,0x706d6f635f736461\n"
".quad 0x3b5d6e6f69746361,0x3109636f6c2e090a,0x0a30093934340937,0x726168732e646c09\n"
".quad 0x09203631752e6465,0x5b202c3438317225,0x5d302b3035647225,0x09636f6c2e090a3b\n"
".quad 0x3009383836093731,0x6168732e7473090a,0x203631752e646572,0x322b386472255b09\n"
".quad 0x3438317225202c5d,0x2e70746573090a3b,0x09203233752e6567,0x7225202c31377025\n"
".quad 0x317225202c383131,0x702540090a3b3239,0x0920617262203137,0x37395f305f744c24\n"
".quad 0x6c2e090a3b363230,0x393609373109636f,0x646461090a300930,0x722509203436752e\n"
".quad 0x647225202c383964,0x33647225202c3634,0x09636f6c2e090a3b,0x3009343634093731\n"
".quad 0x6168732e646c090a,0x203631752e646572,0x202c383831722509,0x302b31356472255b\n"
".quad 0x636f6c2e090a3b5d,0x0930393609373109,0x68732e7473090a30,0x3631752e64657261\n"
".quad 0x38396472255b0920,0x317225202c5d322b,0x5f744c240a3b3838,0x3a36323037395f30\n"
".quad 0x3109636f6c2e090a,0x0a30093337340937,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5b202c3239317225,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f31363636325f\n"
".quad 0x68745f6d756e5f30,0x6f635f7364616572,0x6e6f69746361706d,0x636f6c2e090a3b5d\n"
".quad 0x0933303709373109,0x752e726873090a30,0x3931722509203233,0x3239317225202c33\n"
".quad 0x6f6d090a3b31202c,0x2509203233732e76,0x7225202c34393172,0x6f6d090a3b333931\n"
".quad 0x2509203233752e76,0x3b30202c35393172,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x317225202c323770,0x39317225202c3339,0x37702540090a3b35,0x2409206172622032\n"
".quad 0x3131315f305f744c,0x6f6d090a3b343738,0x2509203233752e76,0x3b31202c36393172\n"
".quad 0x395f305f744c240a,0x2f200a3a30353038,0x203e706f6f6c3c2f,0x646f6220706f6f4c\n"
".quad 0x3720656e696c2079,0x636f6c2e090a3530,0x0935303709373109,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x656c2e7074657309,0x702509203233752e,0x39317225202c3337\n"
".quad 0x0a3b357225202c34,0x6220333770254009,0x5f744c2409206172,0x3b36303338395f30\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3530372065,0x6562616c20646165,0x5f744c242064656c,0x0a30353038395f30\n"
".quad 0x373109636f6c2e09,0x090a300931313709,0x6f6c2e34326c756d,0x722509203233752e\n"
".quad 0x2c357225202c3136,0x646461090a3b3220,0x722509203233752e,0x31367225202c3336\n"
".quad 0x756d090a3b32202c,0x3233752e6f6c2e6c,0x2c37393172250920,0x25202c3336722520\n"
".quad 0x63090a3b36393172,0x752e3436752e7476,0x3964722509203233,0x3739317225202c39\n"
".quad 0x772e6c756d090a3b,0x203233752e656469,0x2c30303164722509,0x202c373931722520\n"
".quad 0x2e646461090a3b32,0x6472250920343675,0x647225202c313031,0x3031647225202c33\n"
".quad 0x732e646c090a3b30,0x31752e6465726168,0x3534687225092036,0x30316472255b202c\n"
".quad 0x61090a3b5d302b31,0x09203233752e6464,0x25202c3839317225,0x0a3b31202c313672\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323375,0x39317225202c3939,0x3839317225202c36\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x202c323031647225,0x090a3b3939317225\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x7225202c33303164,0x0a3b32202c393931\n"
".quad 0x3436752e64646109,0x3430316472250920,0x202c33647225202c,0x0a3b333031647225\n"
".quad 0x726168732e646c09,0x09203631752e6465,0x5b202c3634687225,0x302b343031647225\n"
".quad 0x2e646461090a3b5d,0x6872250920363175,0x34687225202c3734,0x3634687225202c35\n"
".quad 0x68732e7473090a3b,0x3631752e64657261,0x30316472255b0920,0x7225202c5d302b31\n"
".quad 0x744c240a3b373468,0x36303338395f305f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c35303720656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30353038395f305f,0x3109636f6c2e090a,0x0a30093431370937\n"
".quad 0x3233622e6c687309,0x2c36393172250920,0x202c363931722520,0x636f6c2e090a3b31\n"
".quad 0x0933303709373109,0x732e726873090a30,0x3931722509203233,0x3439317225202c34\n"
".quad 0x6f6d090a3b31202c,0x2509203233752e76,0x3b30202c30303272,0x672e70746573090a\n"
".quad 0x2509203233732e74,0x317225202c343770,0x30327225202c3439,0x37702540090a3b30\n"
".quad 0x2409206172622034,0x3038395f305f744c,0x617262090a3b3035,0x4c240920696e752e\n"
".quad 0x333537395f305f74,0x305f744c240a3b38,0x3a3437383131315f,0x33752e766f6d090a\n"
".quad 0x3639317225092032,0x744c240a3b31202c,0x38333537395f305f,0x752e766f6d090a3a\n"
".quad 0x3032722509203233,0x73090a3b32202c31,0x752e656c2e707465,0x3537702509203233\n"
".quad 0x2c3239317225202c,0x0a3b313032722520,0x6220353770254009,0x5f744c2409206172\n"
".quad 0x3b34373039395f30,0x33732e766f6d090a,0x3230327225092032,0x744c240a3b32202c\n"
".quad 0x36383539395f305f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x202c33303720656e,0x20676e697473656e,0x31203a6874706564,0x616d69747365202c\n"
".quad 0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75,0x373109636f6c2e09\n"
".quad 0x090a300930323709,0x203233752e726873,0x202c363931722509,0x31202c3639317225\n"
".quad 0x09636f6c2e090a3b,0x3009313237093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x203233752e627573,0x202c333032722509,0x31202c3230327225,0x2e70746573090a3b\n"
".quad 0x09203233752e6567,0x7225202c36377025,0x3330327225202c35,0x3637702540090a3b\n"
".quad 0x4c24092061726220,0x343839395f305f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c33303720656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x383539395f305f74,0x09636f6c2e090a36,0x3009383237093731\n"
".quad 0x33752e726873090a,0x3430327225092032,0x2c3639317225202c,0x646461090a3b3120\n"
".quad 0x722509203233752e,0x2c357225202c3837,0x6c756d090a3b3120,0x203233752e6f6c2e\n"
".quad 0x202c353032722509,0x7225202c38377225,0x6461090a3b363931,0x2509203233752e64\n"
".quad 0x7225202c36303272,0x327225202c343032,0x747663090a3b3530,0x3233752e3436752e\n"
".quad 0x3530316472250920,0x3b3630327225202c,0x69772e6c756d090a,0x09203233752e6564\n"
".quad 0x202c363031647225,0x32202c3630327225,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x33647225202c3730,0x363031647225202c,0x68732e646c090a3b,0x3631752e64657261\n"
".quad 0x2c38346872250920,0x3730316472255b20,0x7663090a3b5d302b,0x33752e3436752e74\n"
".quad 0x3031647225092032,0x3530327225202c38,0x772e6c756d090a3b,0x203233752e656469\n"
".quad 0x2c39303164722509,0x202c353032722520,0x2e646461090a3b32,0x6472250920343675\n"
".quad 0x647225202c303131,0x3031647225202c33,0x732e646c090a3b39,0x31752e6465726168\n"
".quad 0x3934687225092036,0x31316472255b202c,0x61090a3b5d302b30,0x09203631752e6464\n"
".quad 0x25202c3035687225,0x7225202c38346872,0x7473090a3b393468,0x2e6465726168732e\n"
".quad 0x72255b0920363175,0x2c5d302b37303164,0x0a3b303568722520,0x39395f305f744c24\n"
".quad 0x2f2f200a3a323438,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x303720656e696c20,0x2064616568202c33,0x2064656c6562616c,0x39395f305f744c24\n"
".quad 0x6f6c2e090a363835,0x3831370937310963,0x2e6c6873090a3009,0x3272250920323362\n"
".quad 0x30327225202c3230,0x73090a3b31202c32,0x752e746c2e707465,0x3737702509203233\n"
".quad 0x2c3230327225202c,0x0a3b323931722520,0x6220373770254009,0x5f744c2409206172\n"
".quad 0x3b36383539395f30,0x395f305f744c240a,0x2e090a3a34373039,0x3409373109636f6c\n"
".quad 0x6162090a30093837,0x0920636e79732e72,0x70252140090a3b30,0x2409206172622031\n"
".quad 0x3030315f305f744c,0x6c2e090a3b303136,0x383409373109636f,0x2e646c090a300936\n"
".quad 0x752e646572616873,0x3032722509203233,0x75635f5f5b202c37,0x6c61636f6c5f6164\n"
".quad 0x3636325f7261765f,0x756e5f30345f3835,0x6461657268745f6d,0x6576697463615f73\n"
".quad 0x2e747663090a3b5d,0x203233752e343675,0x2c31313164722509,0x0a3b373032722520\n"
".quad 0x6469772e6c756d09,0x2509203233752e65,0x25202c3231316472,0x3b32202c37303272\n"
".quad 0x36752e646461090a,0x3131647225092034,0x3131647225202c33,0x3b33647225202c32\n"
".quad 0x6168732e646c090a,0x203631752e646572,0x202c383032722509,0x2b3331316472255b\n"
".quad 0x2e7473090a3b5d30,0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x6e5f30345f383239,0x6b636f6c625f6d75,0x2c5d746c756d5f73\n"
".quad 0x0a3b383032722520,0x373109636f6c2e09,0x090a300937383409,0x203436752e646461\n"
".quad 0x2c34313164722509,0x2c32313164722520,0x090a3b3264722520,0x65726168732e646c\n"
".quad 0x2509203631752e64,0x255b202c39303272,0x5d302b3431316472,0x68732e7473090a3b\n"
".quad 0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x333936325f726176\n"
".quad 0x66666f5f30345f30,0x746c756d5f746573,0x5d6164626d616c5f,0x3b3930327225202c\n"
".quad 0x3109636f6c2e090a,0x0a30093838340937,0x3436752e64646109,0x3531316472250920\n"
".quad 0x323131647225202c,0x0a3b35647225202c,0x726168732e646c09,0x09203631752e6465\n"
".quad 0x5b202c3031327225,0x302b353131647225,0x732e7473090a3b5d,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3936325f7261765f,0x756e5f30345f3932\n"
".quad 0x2c5d746c756d5f6d,0x0a3b303132722520,0x373109636f6c2e09,0x090a300930393409\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x5f5b202c36313164,0x726170616475635f\n"
".quad 0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65,0x6a6a66666a5f5366\n"
".quad 0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f,0x5f675f5f30535f30\n"
".quad 0x5d656e6f5f6d756e,0x6c672e7473090a3b,0x3233752e6c61626f,0x31316472255b0920\n"
".quad 0x7225202c5d302b36,0x6c2e090a3b393032,0x393409373109636f,0x2e646c090a300931\n"
".quad 0x36752e6d61726170,0x3131647225092034,0x75635f5f5b202c37,0x5f5f6d7261706164\n"
".quad 0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261,0x6a50666a6a66666a\n"
".quad 0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f,0x6d756e5f675f5f30\n"
".quad 0x5f736b636f6c625f,0x090a3b5d746c756d,0x61626f6c672e7473,0x5b09203233752e6c\n"
".quad 0x302b373131647225,0x3830327225202c5d,0x5f305f744c240a3b,0x0a3a303136303031\n"
".quad 0x373109636f6c2e09,0x090a300933393409,0x636e79732e726162,0x6c2e090a3b300920\n"
".quad 0x313609373109636f,0x2e646c090a300932,0x662e646572616873,0x2c37662509203233\n"
".quad 0x2b30316472255b20,0x6f6c2e090a3b5d30,0x3331360937310963,0x732e646c090a3009\n"
".quad 0x33662e6465726168,0x202c366625092032,0x302b31316472255b,0x732e646c090a3b5d\n"
".quad 0x33752e6465726168,0x3131327225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x353636325f726176,0x6d756e5f30345f38,0x736461657268745f,0x5d6576697463615f\n"
".quad 0x2e70746573090a3b,0x09203233752e7467,0x7225202c38377025,0x317225202c313132\n"
".quad 0x252140090a3b3831,0x2061726220383770,0x315f305f744c2409,0x090a3b3232313130\n"
".quad 0x09373109636f6c2e,0x6d090a3009373136,0x36752e6f6c2e6c75,0x3131647225092034\n"
".quad 0x3534647225202c38,0x6461090a3b34202c,0x2509203436752e64,0x25202c3931316472\n"
".quad 0x25202c3831316472,0x646c090a3b316472,0x2e6465726168732e,0x3766250920323366\n"
".quad 0x316472255b202c37,0x090a3b5d302b3931,0x203233662e766f6d,0x25202c3837662509\n"
".quad 0x6c2e090a3b373766,0x313609373109636f,0x646461090a300938,0x722509203436752e\n"
".quad 0x7225202c30323164,0x7225202c38313164,0x2e646c090a3b3464,0x662e646572616873\n"
".quad 0x3937662509203233,0x32316472255b202c,0x6d090a3b5d302b30,0x09203233662e766f\n"
".quad 0x6625202c30386625,0x5f744c240a3b3937,0x3232313130315f30,0x09636f6c2e090a3a\n"
".quad 0x3009313236093731,0x363470252140090a,0x4c24092061726220,0x383130315f305f74\n"
".quad 0x6f6c2e090a3b3039,0x3433360937310963,0x732e646c090a3009,0x31752e6465726168\n"
".quad 0x3231327225092036,0x32316472255b202c,0x7262090a3b5d302b,0x240920696e752e61\n"
".quad 0x3130315f305f744c,0x744c240a3b343336,0x39383130315f305f,0x732e646c090a3a30\n"
".quad 0x31752e6465726168,0x3331327225092036,0x33316472255b202c,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x3272250920323375,0x635f5f5b202c3431,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x6f5f30345f303339,0x756d5f7465736666,0x64626d616c5f746c\n"
".quad 0x646461090a3b5d61,0x722509203233752e,0x327225202c323132,0x31327225202c3331\n"
".quad 0x305f744c240a3b34,0x3a3433363130315f,0x33752e766f6d090a,0x3531327225092032\n"
".quad 0x6573090a3b30202c,0x33752e656e2e7074,0x2c39377025092032,0x202c373831722520\n"
".quad 0x090a3b3531327225,0x6220393770252140,0x5f744c2409206172,0x3230343230315f30\n"
".quad 0x09636f6c2e090a3b,0x3009373336093731,0x6168732e646c090a,0x203631752e646572\n"
".quad 0x202c363132722509,0x5d302b386472255b,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3634313230315f30,0x5f305f744c240a3b,0x0a3a323034323031,0x3233752e766f6d09\n"
".quad 0x2c36313272250920,0x5f744c240a3b3020,0x3634313230315f30,0x3770252140090a3a\n"
".quad 0x2409206172622038,0x3230315f305f744c,0x6f6d090a3b343139,0x2509203233752e76\n"
".quad 0x3b31202c37313272,0x6e2e70746573090a,0x2509203233752e65,0x317225202c303870\n"
".quad 0x31327225202c3733,0x38702540090a3b37,0x2409206172622030,0x3330315f305f744c\n"
".quad 0x6c2e090a3b363234,0x343609373109636f,0x646461090a300931,0x722509203436752e\n"
".quad 0x7225202c31323164,0x647225202c363464,0x732e646c090a3b32,0x31752e6465726168\n"
".quad 0x3831327225092036,0x32316472255b202c,0x62090a3b5d302b31,0x0920696e752e6172\n"
".quad 0x30315f305f744c24,0x4c240a3b30373133,0x343330315f305f74,0x646461090a3a3632\n"
".quad 0x722509203436752e,0x7225202c32323164,0x647225202c363464,0x732e646c090a3b35\n"
".quad 0x31752e6465726168,0x3931327225092036,0x32316472255b202c,0x6c090a3b5d302b32\n"
".quad 0x6465726168732e64,0x722509203233752e,0x5f5f5b202c303232,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f30333936,0x6d5f74657366666f,0x626d616c5f746c75\n"
".quad 0x6461090a3b5d6164,0x2509203233752e64,0x7225202c38313272,0x327225202c393132\n"
".quad 0x5f744c240a3b3032,0x3037313330315f30,0x732e766f6d090a3a,0x3232722509203233\n"
".quad 0x3831327225202c31,0x752e766f6d090a3b,0x3232722509203233,0x73090a3b30202c32\n"
".quad 0x752e71652e707465,0x3138702509203233,0x2c3139317225202c,0x0a3b323232722520\n"
".quad 0x6220313870254009,0x5f744c2409206172,0x3833393330315f30,0x09636f6c2e090a3b\n"
".quad 0x3009343436093731,0x36752e646461090a,0x3231647225092034,0x3634647225202c33\n"
".quad 0x0a3b33647225202c,0x726168732e646c09,0x09203631752e6465,0x5b202c3332327225\n"
".quad 0x302b333231647225,0x2e617262090a3b5d,0x744c240920696e75,0x35363230315f305f\n"
".quad 0x305f744c240a3b38,0x3a3833393330315f,0x33752e766f6d090a,0x3332327225092032\n"
".quad 0x7262090a3b30202c,0x240920696e752e61,0x3230315f305f744c,0x744c240a3b383536\n"
".quad 0x31393230315f305f,0x2e766f6d090a3a34,0x3272250920323375,0x090a3b30202c3332\n"
".quad 0x203233752e766f6d,0x202c313232722509,0x305f744c240a3b30,0x3a3835363230315f\n"
".quad 0x3109636f6c2e090a,0x0a30093834360937,0x6e79732e72616209,0x2e090a3b30092063\n"
".quad 0x3609373109636f6c,0x7663090a30093135,0x33752e3436752e74,0x3231647225092032\n"
".quad 0x3231327225202c34,0x772e6c756d090a3b,0x203233752e656469,0x2c35323164722509\n"
".quad 0x202c323132722520,0x2e646461090a3b34,0x6472250920343675,0x647225202c363231\n"
".quad 0x647225202c353231,0x732e7473090a3b31,0x33662e6465726168,0x316472255b092032\n"
".quad 0x25202c5d302b3632,0x6f6c2e090a3b3766,0x3235360937310963,0x2e646461090a3009\n"
".quad 0x6472250920343675,0x647225202c373231,0x647225202c353231,0x732e7473090a3b34\n"
".quad 0x33662e6465726168,0x316472255b092032,0x25202c5d302b3732,0x6f6c2e090a3b3666\n"
".quad 0x3335360937310963,0x2e6c756d090a3009,0x3233752e65646977,0x3832316472250920\n"
".quad 0x2c3231327225202c,0x6c6873090a3b3220,0x722509203233622e,0x317225202c343232\n"
".quad 0x73090a3b3631202c,0x09203233752e7268,0x25202c3532327225,0x3631202c34323272\n"
".quad 0x752e646461090a3b,0x3164722509203436,0x31647225202c3932,0x32647225202c3832\n"
".quad 0x68732e7473090a3b,0x3631752e64657261,0x32316472255b0920,0x7225202c5d302b39\n"
".quad 0x6c2e090a3b353232,0x353609373109636f,0x6c6873090a300934,0x722509203233622e\n"
".quad 0x337225202c363232,0x73090a3b3631202c,0x09203233752e7268,0x25202c3732327225\n"
".quad 0x3631202c36323272,0x752e646461090a3b,0x3164722509203436,0x31647225202c3033\n"
".quad 0x35647225202c3832,0x68732e7473090a3b,0x3631752e64657261,0x33316472255b0920\n"
".quad 0x7225202c5d302b30,0x2140090a3b373232,0x6172622039377025,0x5f305f744c240920\n"
".quad 0x0a3b343931343031,0x373109636f6c2e09,0x090a300936353609,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x327225202c313331,0x6c756d090a3b3631,0x33752e656469772e\n"
".quad 0x3331647225092032,0x3631327225202c32,0x7573090a3b32202c,0x2509203233752e62\n"
".quad 0x7225202c38323272,0x0a3b31202c373831,0x3436752e64646109,0x3333316472250920\n"
".quad 0x323331647225202c,0x0a3b33647225202c,0x726168732e747309,0x09203631752e6465\n"
".quad 0x2b3333316472255b,0x32327225202c5d32,0x636f6c2e090a3b38,0x0937353609373109\n"
".quad 0x752e646461090a30,0x3164722509203436,0x31647225202c3433,0x34647225202c3233\n"
".quad 0x732e7473090a3b39,0x31752e6465726168,0x316472255b092036,0x25202c5d322b3433\n"
".quad 0x4c240a3b33346872,0x313430315f305f74,0x252140090a3a3439,0x2061726220383770\n"
".quad 0x315f305f744c2409,0x090a3b3831323530,0x09373109636f6c2e,0x63090a3009333636\n"
".quad 0x752e3436752e7476,0x3164722509203233,0x32327225202c3533,0x2e6c756d090a3b31\n"
".quad 0x3233752e65646977,0x3633316472250920,0x2c3132327225202c,0x766f6d090a3b3420\n"
".quad 0x662509203233662e,0x38376625202c3138,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3733,0x31647225202c3633,0x68732e7473090a3b,0x3233662e64657261\n"
".quad 0x33316472255b0920,0x6625202c5d302b37,0x6f6c2e090a3b3138,0x3436360937310963\n"
".quad 0x2e766f6d090a3009,0x3866250920323366,0x3b30386625202c32,0x36752e646461090a\n"
".quad 0x3331647225092034,0x3331647225202c38,0x3b34647225202c36,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x3833316472255b09,0x386625202c5d302b,0x636f6c2e090a3b32\n"
".quad 0x0935363609373109,0x772e6c756d090a30,0x203233752e656469,0x2c39333164722509\n"
".quad 0x202c313232722520,0x2e766f6d090a3b32,0x3272250920323373,0x32317225202c3932\n"
".quad 0x2e6c6873090a3b31,0x3272250920323362,0x32327225202c3033,0x090a3b3631202c39\n"
".quad 0x203233752e726873,0x202c313332722509,0x31202c3033327225,0x2e646461090a3b36\n"
".quad 0x6472250920343675,0x647225202c303431,0x647225202c393331,0x732e7473090a3b32\n"
".quad 0x31752e6465726168,0x316472255b092036,0x25202c5d302b3034,0x2e090a3b31333272\n"
".quad 0x3609373109636f6c,0x6f6d090a30093636,0x2509203233732e76,0x7225202c32333272\n"
".quad 0x6873090a3b333231,0x2509203233622e6c,0x7225202c33333272,0x3b3631202c323332\n"
".quad 0x33752e726873090a,0x3433327225092032,0x2c3333327225202c,0x6461090a3b363120\n"
".quad 0x2509203436752e64,0x25202c3134316472,0x25202c3933316472,0x7473090a3b356472\n"
".quad 0x2e6465726168732e,0x72255b0920363175,0x2c5d302b31343164,0x0a3b343332722520\n"
".quad 0x3233752e766f6d09,0x2c35333272250920,0x746573090a3b3020,0x3233752e71652e70\n"
".quad 0x202c323870250920,0x25202c3139317225,0x40090a3b35333272,0x6172622032387025\n"
".quad 0x5f305f744c240920,0x0a3b383132353031,0x373109636f6c2e09,0x090a300938363609\n"
".quad 0x2e3436752e747663,0x6472250920323375,0x327225202c323431,0x6c756d090a3b3332\n"
".quad 0x33752e656469772e,0x3431647225092032,0x3332327225202c33,0x7573090a3b32202c\n"
".quad 0x2509203233752e62,0x7225202c36333272,0x0a3b31202c313931,0x3436752e64646109\n"
".quad 0x3434316472250920,0x333431647225202c,0x0a3b33647225202c,0x726168732e747309\n"
".quad 0x09203631752e6465,0x2b3434316472255b,0x33327225202c5d32,0x636f6c2e090a3b36\n"
".quad 0x0939363609373109,0x752e646461090a30,0x3164722509203436,0x31647225202c3534\n"
".quad 0x34647225202c3334,0x732e7473090a3b39,0x31752e6465726168,0x316472255b092036\n"
".quad 0x25202c5d322b3534,0x4c240a3b34346872,0x323530315f305f74,0x5f744c240a3a3831\n"
".quad 0x3630373430315f30,0x09636f6c2e090a3a,0x3009353035093731,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x7262203170252140,0x305f744c24092061,0x3b3033373530315f\n"
".quad 0x3109636f6c2e090a,0x0a30093930350937,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5b202c3733327225,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f39323936325f\n"
".quad 0x756d5f6d756e5f30,0x646c090a3b5d746c,0x2e6465726168732e,0x3272250920323375\n"
".quad 0x635f5f5b202c3833,0x61636f6c5f616475,0x36325f7261765f6c,0x6e5f30345f383239\n"
".quad 0x6b636f6c625f6d75,0x3b5d746c756d5f73,0x36752e747663090a,0x2509203233752e34\n"
".quad 0x25202c3634316472,0x6d090a3b38333272,0x2e656469772e6c75,0x6472250920323375\n"
".quad 0x327225202c373431,0x090a3b32202c3833,0x203436752e646461,0x2c38343164722509\n"
".quad 0x25202c3364722520,0x090a3b3734316472,0x65726168732e7473,0x5b09203631752e64\n"
".quad 0x302b383431647225,0x3733327225202c5d,0x09636f6c2e090a3b,0x3009303135093731\n"
".quad 0x31752e766f6d090a,0x3135687225092036,0x7473090a3b30202c,0x2e6465726168732e\n"
".quad 0x5f5f5b0920363175,0x635f5f5f61647563,0x61636f6c5f616475,0x36325f7261765f6c\n"
".quad 0x735f32345f343438,0x706c65685f6c635f,0x302b303133377265,0x3135687225202c5d\n"
".quad 0x5f305f744c240a3b,0x0a3a303337353031,0x373109636f6c2e09,0x090a300933313509\n"
".quad 0x636e79732e726162,0x6c2e090a3b300920,0x313509373109636f,0x2e646c090a300936\n"
".quad 0x662e646572616873,0x3338662509203233,0x30316472255b202c,0x646c090a3b5d302b\n"
".quad 0x2e6465726168732e,0x3272250920323375,0x635f5f5b202c3930,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x6f5f30345f303339,0x756d5f7465736666,0x64626d616c5f746c\n"
".quad 0x746573090a3b5d61,0x3233752e656c2e70,0x202c333870250920,0x25202c3930327225\n"
".quad 0x702540090a3b3572,0x0920617262203338,0x30315f305f744c24,0x2e090a3b38393436\n"
".quad 0x3509373109636f6c,0x646c090a30093734,0x752e6d617261702e,0x3164722509203436\n"
".quad 0x635f5f5b202c3934,0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x656c5f675f5f3053,0x3b5d656e6f5f7466,0x36752e646461090a\n"
".quad 0x3531647225092034,0x3431647225202c30,0x3b39647225202c39,0x3109636f6c2e090a\n"
".quad 0x0a30093631350937,0x726168732e646c09,0x09203233662e6465,0x255b202c33386625\n"
".quad 0x3b5d302b30316472,0x3109636f6c2e090a,0x0a30093734350937,0x626f6c672e747309\n"
".quad 0x09203233662e6c61,0x2b3035316472255b,0x33386625202c5d30,0x09636f6c2e090a3b\n"
".quad 0x3009383435093731,0x6168732e646c090a,0x203233662e646572,0x5b202c3438662509\n"
".quad 0x5d302b3131647225,0x61702e646c090a3b,0x203436752e6d6172,0x2c31353164722509\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265\n"
".quad 0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53\n"
".quad 0x5f30535f30535f30,0x74686769725f675f,0x090a3b5d656e6f5f,0x203436752e646461\n"
".quad 0x2c32353164722509,0x2c31353164722520,0x090a3b3964722520,0x61626f6c672e7473\n"
".quad 0x5b09203233662e6c,0x302b323531647225,0x3b34386625202c5d,0x3109636f6c2e090a\n"
".quad 0x0a30093035350937,0x726168732e646c09,0x09203631752e6465,0x5b202c3933327225\n"
".quad 0x5d302b3331647225,0x61702e646c090a3b,0x203436752e6d6172,0x2c33353164722509\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265\n"
".quad 0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53\n"
".quad 0x5f30535f30535f30,0x6f5f736f705f675f,0x6461090a3b5d656e,0x2509203436752e64\n"
".quad 0x25202c3435316472,0x25202c3335316472,0x7473090a3b396472,0x2e6c61626f6c672e\n"
".quad 0x72255b0920323375,0x2c5d302b34353164,0x0a3b393332722520,0x696e752e61726209\n"
".quad 0x5f305f744c240920,0x0a3b323432363031,0x30315f305f744c24,0x2e090a3a38393436\n"
".quad 0x3509373109636f6c,0x646c090a30093631,0x2e6465726168732e,0x3272250920323375\n"
".quad 0x635f5f5b202c3930,0x61636f6c5f616475,0x36325f7261765f6c,0x6f5f30345f303339\n"
".quad 0x756d5f7465736666,0x64626d616c5f746c,0x6f6c2e090a3b5d61,0x3435350937310963\n"
".quad 0x2e627573090a3009,0x3272250920323375,0x2c357225202c3034,0x0a3b393032722520\n"
".quad 0x3436752e74766309,0x722509203233752e,0x7225202c35353164,0x756d090a3b303432\n"
".quad 0x752e656469772e6c,0x3164722509203233,0x34327225202c3635,0x6c090a3b34202c30\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x5f5f5b202c373531,0x6d72617061647563\n"
".quad 0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53\n"
".quad 0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053,0x6c5f675f5f30535f\n"
".quad 0x746c756d5f746665,0x2e646461090a3b5d,0x6472250920343675,0x647225202c383531\n"
".quad 0x647225202c373531,0x6c2e090a3b363531,0x313509373109636f,0x2e646c090a300936\n"
".quad 0x662e646572616873,0x3338662509203233,0x30316472255b202c,0x6c2e090a3b5d302b\n"
".quad 0x353509373109636f,0x2e7473090a300934,0x662e6c61626f6c67,0x6472255b09203233\n"
".quad 0x202c5d302b383531,0x2e090a3b33386625,0x3509373109636f6c,0x646c090a30093535\n"
".quad 0x2e6465726168732e,0x3866250920323366,0x316472255b202c35,0x6c090a3b5d302b31\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x5f5f5b202c393531,0x6d72617061647563\n"
".quad 0x73696237315a5f5f,0x656e72654b746365,0x6650656772614c6c,0x666a6a66666a5f53\n"
".quad 0x535f535f30536a50,0x5f535f535f30535f,0x30535f30535f3053,0x725f675f5f30535f\n"
".quad 0x6c756d5f74686769,0x646461090a3b5d74,0x722509203436752e,0x7225202c30363164\n"
".quad 0x7225202c39353164,0x73090a3b36353164,0x6c61626f6c672e74,0x255b09203233662e\n"
".quad 0x5d302b3036316472,0x0a3b35386625202c,0x373109636f6c2e09,0x090a300936353509\n"
".quad 0x65726168732e646c,0x2509203631752e64,0x255b202c31343272,0x3b5d302b32316472\n"
".quad 0x7261702e646c090a,0x09203436752e6d61,0x202c313631647225,0x70616475635f5f5b\n"
".quad 0x37315a5f5f6d7261,0x654b746365736962,0x6772614c6c656e72,0x66666a5f53665065\n"
".quad 0x5f30536a50666a6a,0x535f30535f535f53,0x30535f30535f535f,0x5f5f30535f30535f\n"
".quad 0x635f7466656c5f67,0x6c756d5f746e756f,0x646461090a3b5d74,0x722509203436752e\n"
".quad 0x7225202c32363164,0x7225202c31363164,0x73090a3b36353164,0x6c61626f6c672e74\n"
".quad 0x255b09203233752e,0x5d302b3236316472,0x3b3134327225202c,0x3109636f6c2e090a\n"
".quad 0x0a30093735350937,0x726168732e646c09,0x09203631752e6465,0x5b202c3234327225\n"
".quad 0x5d302b3331647225,0x61702e646c090a3b,0x203436752e6d6172,0x2c33363164722509\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265\n"
".quad 0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53\n"
".quad 0x5f30535f30535f30,0x74686769725f675f,0x6d5f746e756f635f,0x61090a3b5d746c75\n"
".quad 0x09203436752e6464,0x202c343631647225,0x202c333631647225,0x0a3b363531647225\n"
".quad 0x626f6c672e747309,0x09203233752e6c61,0x2b3436316472255b,0x34327225202c5d30\n"
".quad 0x305f744c240a3b32,0x3a3234323630315f,0x6168732e646c090a,0x203233752e646572\n"
".quad 0x202c333432722509,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38353636325f72\n"
".quad 0x745f6d756e5f3034,0x615f736461657268,0x0a3b5d6576697463,0x656c2e7074657309\n"
".quad 0x702509203233752e,0x34327225202c3438,0x3831317225202c33,0x3438702540090a3b\n"
".quad 0x4c24092061726220,0x323730315f305f74,0x6c756d090a3b3636,0x203436752e6f6c2e\n"
".quad 0x2c38313164722509,0x202c353464722520,0x2e646461090a3b34,0x6472250920343675\n"
".quad 0x647225202c353631,0x35647225202c3634,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3636,0x31647225202c3831,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3736,0x34647225202c3831,0x68732e646c090a3b,0x3233662e64657261\n"
".quad 0x202c363866250920,0x2b3636316472255b,0x6f6c2e090a3b5d30,0x3631350937310963\n"
".quad 0x732e646c090a3009,0x33752e6465726168,0x3930327225092032,0x6475635f5f5b202c\n"
".quad 0x5f6c61636f6c5f61,0x333936325f726176,0x66666f5f30345f30,0x746c756d5f746573\n"
".quad 0x5d6164626d616c5f,0x09636f6c2e090a3b,0x3009373535093731,0x672e70746573090a\n"
".quad 0x2509203233752e65,0x317225202c353870,0x30327225202c3831,0x38702540090a3b39\n"
".quad 0x2409206172622035,0x3730315f305f744c,0x6c2e090a3b323235,0x363509373109636f\n"
".quad 0x2e646c090a300934,0x36752e6d61726170,0x3631647225092034,0x75635f5f5b202c38\n"
".quad 0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74,0x5f53665065677261\n"
".quad 0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30,0x535f30535f30535f\n"
".quad 0x66656c5f675f5f30,0x0a3b5d656e6f5f74,0x3436752e64646109,0x3936316472250920\n"
".quad 0x383631647225202c,0x383131647225202c,0x09636f6c2e090a3b,0x3009373535093731\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x5b202c3638662509,0x302b363631647225\n"
".quad 0x636f6c2e090a3b5d,0x0934363509373109,0x6c672e7473090a30,0x3233662e6c61626f\n"
".quad 0x36316472255b0920,0x6625202c5d302b39,0x6f6c2e090a3b3638,0x3536350937310963\n"
".quad 0x732e646c090a3009,0x33662e6465726168,0x2c37386625092032,0x3736316472255b20\n"
".quad 0x646c090a3b5d302b,0x752e6d617261702e,0x3164722509203436,0x635f5f5b202c3037\n"
".quad 0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c\n"
".quad 0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30\n"
".quad 0x69725f675f5f3053,0x5d656e6f5f746867,0x752e646461090a3b,0x3164722509203436\n"
".quad 0x31647225202c3137,0x31647225202c3037,0x2e7473090a3b3831,0x662e6c61626f6c67\n"
".quad 0x6472255b09203233,0x202c5d302b313731,0x2e090a3b37386625,0x3509373109636f6c\n"
".quad 0x646c090a30093736,0x2e6465726168732e,0x3272250920363175,0x6472255b202c3434\n"
".quad 0x0a3b5d302b353631,0x617261702e646c09,0x2509203436752e6d,0x5b202c3237316472\n"
".quad 0x6170616475635f5f,0x6237315a5f5f6d72,0x72654b7463657369,0x656772614c6c656e\n"
".quad 0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f,0x5f30535f30535f53\n"
".quad 0x675f5f30535f3053,0x656e6f5f736f705f,0x2e646461090a3b5d,0x6472250920343675\n"
".quad 0x647225202c333731,0x647225202c323731,0x7473090a3b383131,0x2e6c61626f6c672e\n"
".quad 0x72255b0920323375,0x2c5d302b33373164,0x0a3b343432722520,0x696e752e61726209\n"
".quad 0x5f305f744c240920,0x0a3b363632373031,0x30315f305f744c24,0x2e090a3a32323537\n"
".quad 0x3509373109636f6c,0x646c090a30093631,0x2e6465726168732e,0x3272250920323375\n"
".quad 0x635f5f5b202c3930,0x61636f6c5f616475,0x36325f7261765f6c,0x6f5f30345f303339\n"
".quad 0x756d5f7465736666,0x64626d616c5f746c,0x6f6c2e090a3b5d61,0x3137350937310963\n"
".quad 0x2e627573090a3009,0x3272250920323375,0x31317225202c3534,0x3930327225202c38\n"
".quad 0x752e747663090a3b,0x09203233752e3436,0x202c343731647225,0x090a3b3534327225\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x7225202c35373164,0x0a3b34202c353432\n"
".quad 0x617261702e646c09,0x2509203436752e6d,0x5b202c3637316472,0x6170616475635f5f\n"
".quad 0x6237315a5f5f6d72,0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650\n"
".quad 0x535f30536a50666a,0x5f535f30535f535f,0x5f30535f30535f53,0x675f5f30535f3053\n"
".quad 0x756d5f7466656c5f,0x6461090a3b5d746c,0x2509203436752e64,0x25202c3737316472\n"
".quad 0x25202c3637316472,0x090a3b3537316472,0x09373109636f6c2e,0x6c090a3009373535\n"
".quad 0x6465726168732e64,0x662509203233662e,0x6472255b202c3638,0x0a3b5d302b363631\n"
".quad 0x373109636f6c2e09,0x090a300931373509,0x61626f6c672e7473,0x5b09203233662e6c\n"
".quad 0x302b373731647225,0x3b36386625202c5d,0x3109636f6c2e090a,0x0a30093237350937\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x255b202c38386625,0x5d302b3736316472\n"
".quad 0x61702e646c090a3b,0x203436752e6d6172,0x2c38373164722509,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x4b74636573696237,0x72614c6c656e7265,0x666a5f5366506567\n"
".quad 0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53,0x5f30535f30535f30\n"
".quad 0x74686769725f675f,0x0a3b5d746c756d5f,0x3436752e64646109,0x3937316472250920\n"
".quad 0x383731647225202c,0x353731647225202c,0x6c672e7473090a3b,0x3233662e6c61626f\n"
".quad 0x37316472255b0920,0x6625202c5d302b39,0x6f6c2e090a3b3838,0x3337350937310963\n"
".quad 0x2e646461090a3009,0x6472250920343675,0x647225202c303831,0x32647225202c3634\n"
".quad 0x68732e646c090a3b,0x3631752e64657261,0x2c36343272250920,0x3038316472255b20\n"
".quad 0x646c090a3b5d302b,0x752e6d617261702e,0x3164722509203436,0x635f5f5b202c3138\n"
".quad 0x5f6d726170616475,0x6573696237315a5f,0x6c656e72654b7463,0x536650656772614c\n"
".quad 0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053,0x5f30535f30535f30\n"
".quad 0x656c5f675f5f3053,0x746e756f635f7466,0x0a3b5d746c756d5f,0x3436752e64646109\n"
".quad 0x3238316472250920,0x313831647225202c,0x353731647225202c,0x6c672e7473090a3b\n"
".quad 0x3233752e6c61626f,0x38316472255b0920,0x7225202c5d302b32,0x6c2e090a3b363432\n"
".quad 0x373509373109636f,0x2e646c090a300934,0x752e646572616873,0x3432722509203631\n"
".quad 0x316472255b202c37,0x090a3b5d302b3536,0x6d617261702e646c,0x722509203436752e\n"
".quad 0x5f5b202c33383164,0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573\n"
".quad 0x50656772614c6c65,0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53\n"
".quad 0x535f30535f30535f,0x5f675f5f30535f30,0x6f635f7468676972,0x746c756d5f746e75\n"
".quad 0x2e646461090a3b5d,0x6472250920343675,0x647225202c343831,0x647225202c333831\n"
".quad 0x7473090a3b353731,0x2e6c61626f6c672e,0x72255b0920323375,0x2c5d302b34383164\n"
".quad 0x0a3b373432722520,0x30315f305f744c24,0x4c240a3a36363237,0x373630315f305f74\n"
".quad 0x2e646c090a3a3435,0x752e646572616873,0x3032722509203233,0x75635f5f5b202c38\n"
".quad 0x6c61636f6c5f6164,0x3936325f7261765f,0x756e5f30345f3832,0x736b636f6c625f6d\n"
".quad 0x0a3b5d746c756d5f,0x746c2e7074657309,0x702509203233752e,0x30327225202c3638\n"
".quad 0x0a3b357225202c38,0x6220363870254009,0x5f744c2409206172,0x3837373730315f30\n"
".quad 0x09636f6c2e090a3b,0x3009323835093731,0x6168732e646c090a,0x203631752e646572\n"
".quad 0x202c383432722509,0x5d302b386472255b,0x61702e646c090a3b,0x203436752e6d6172\n"
".quad 0x2c35383164722509,0x616475635f5f5b20,0x315a5f5f6d726170,0x4b74636573696237\n"
".quad 0x72614c6c656e7265,0x666a5f5366506567,0x30536a50666a6a66,0x5f30535f535f535f\n"
".quad 0x535f30535f535f53,0x5f30535f30535f30,0x6b636f6c625f675f,0x3b5d746c756d5f73\n"
".quad 0x36752e646461090a,0x3831647225092034,0x3831647225202c36,0x3b39647225202c35\n"
".quad 0x6f6c672e7473090a,0x203233752e6c6162,0x3638316472255b09,0x327225202c5d302b\n"
".quad 0x6f6c2e090a3b3834,0x3338350937310963,0x732e646c090a3009,0x31752e6465726168\n"
".quad 0x3934327225092036,0x30356472255b202c,0x646c090a3b5d302b,0x752e6d617261702e\n"
".quad 0x3164722509203436,0x635f5f5b202c3738,0x5f6d726170616475,0x6573696237315a5f\n"
".quad 0x6c656e72654b7463,0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a\n"
".quad 0x535f535f535f3053,0x5f30535f30535f30,0x6c625f675f5f3053,0x6c756d5f736b636f\n"
".quad 0x0a3b5d6d75735f74,0x3436752e64646109,0x3838316472250920,0x373831647225202c\n"
".quad 0x0a3b39647225202c,0x626f6c672e747309,0x09203233752e6c61,0x2b3838316472255b\n"
".quad 0x34327225202c5d30,0x305f744c240a3b39,0x3a3837373730315f,0x3109636f6c2e090a\n"
".quad 0x0a30093437350937,0x726168732e646c09,0x09203233752e6465,0x5b202c3830327225\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f38323936325f,0x6c625f6d756e5f30\n"
".quad 0x6c756d5f736b636f,0x6f6c2e090a3b5d74,0x3338350937310963,0x70746573090a3009\n"
".quad 0x203233752e74672e,0x25202c3738702509,0x7225202c38313172,0x2540090a3b383032\n"
".quad 0x2061726220373870,0x315f305f744c2409,0x090a3b3039323830,0x09373109636f6c2e\n"
".quad 0x6d090a3009363835,0x36752e6f6c2e6c75,0x3131647225092034,0x3534647225202c38\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x25202c3938316472,0x7225202c36346472\n"
".quad 0x2e646c090a3b3364,0x752e646572616873,0x3532722509203631,0x316472255b202c30\n"
".quad 0x090a3b5d302b3938,0x6d617261702e646c,0x722509203436752e,0x5f5b202c30393164\n"
".quad 0x726170616475635f,0x696237315a5f5f6d,0x6e72654b74636573,0x50656772614c6c65\n"
".quad 0x6a6a66666a5f5366,0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f\n"
".quad 0x5f675f5f30535f30,0x6d5f736b636f6c62,0x61090a3b5d746c75,0x09203436752e6464\n"
".quad 0x202c313931647225,0x202c303931647225,0x0a3b383131647225,0x626f6c672e747309\n"
".quad 0x09203233752e6c61,0x2b3139316472255b,0x35327225202c5d30,0x636f6c2e090a3b30\n"
".quad 0x0937383509373109,0x68732e646c090a30,0x3631752e64657261,0x2c31353272250920\n"
".quad 0x2b31356472255b20,0x2e646c090a3b5d30,0x36752e6d61726170,0x3931647225092034\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x636573696237315a,0x4c6c656e72654b74\n"
".quad 0x5f53665065677261,0x6a50666a6a66666a,0x535f535f535f3053,0x30535f535f535f30\n"
".quad 0x535f30535f30535f,0x6f6c625f675f5f30,0x746c756d5f736b63,0x090a3b5d6d75735f\n"
".quad 0x203436752e646461,0x2c33393164722509,0x2c32393164722520,0x3b38313164722520\n"
".quad 0x6f6c672e7473090a,0x203233752e6c6162,0x3339316472255b09,0x327225202c5d302b\n"
".quad 0x5f744c240a3b3135,0x3039323830315f30,0x09636f6c2e090a3a,0x3009323235093731\n"
".quad 0x0a3b74697865090a,0x5f646e6557444c24,0x6573696237315a5f,0x6c656e72654b7463\n"
".quad 0x536650656772614c,0x50666a6a66666a5f,0x5f535f535f30536a,0x535f535f535f3053\n"
".quad 0x5f30535f30535f30,0x207d090a3a5f3053,0x6237315a5f202f2f,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a,0x5f535f30535f535f\n"
".quad 0x5f30535f30535f53,0x0a0a5f30535f3053,0x207972746e652e09,0x6573696230335a5f\n"
".quad 0x6c656e72654b7463,0x6e4f5f656772614c,0x61767265746e4965,0x6a6a5f536650736c\n"
".quad 0x20666a505f535f53,0x7261702e09090a28,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x6230335a5f5f6d72,0x72654b7463657369,0x656772614c6c656e,0x65746e49656e4f5f\n"
".quad 0x536650736c617672,0x505f535f536a6a5f,0x0a2c645f675f666a,0x6d617261702e0909\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365\n"
".quad 0x4f5f656772614c6c,0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a\n"
".quad 0x09090a2c735f675f,0x2e206d617261702e,0x75635f5f20323375,0x5f5f6d7261706164\n"
".quad 0x636573696230335a,0x4c6c656e72654b74,0x656e4f5f65677261,0x6c61767265746e49\n"
".quad 0x536a6a5f53665073,0x6e5f666a505f535f,0x7261702e09090a2c,0x203233752e206d61\n"
".quad 0x6170616475635f5f,0x6230335a5f5f6d72,0x72654b7463657369,0x656772614c6c656e\n"
".quad 0x65746e49656e4f5f,0x536650736c617672,0x505f535f536a6a5f,0x695f6d756e5f666a\n"
".quad 0x736c61767265746e,0x7261702e09090a2c,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x6230335a5f5f6d72,0x72654b7463657369,0x656772614c6c656e,0x65746e49656e4f5f\n"
".quad 0x536650736c617672,0x505f535f536a6a5f,0x66656c5f675f666a,0x61702e09090a2c74\n"
".quad 0x3436752e206d6172,0x70616475635f5f20,0x30335a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x746e49656e4f5f65,0x6650736c61767265,0x5f535f536a6a5f53\n"
".quad 0x69725f675f666a50,0x2e09090a2c746867,0x752e206d61726170,0x6475635f5f203436\n"
".quad 0x5a5f5f6d72617061,0x7463657369623033,0x614c6c656e72654b,0x49656e4f5f656772\n"
".quad 0x736c61767265746e,0x5f536a6a5f536650,0x5f675f666a505f53,0x2e09090a2c736f70\n"
".quad 0x662e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061,0x7463657369623033\n"
".quad 0x614c6c656e72654b,0x49656e4f5f656772,0x736c61767265746e,0x5f536a6a5f536650\n"
".quad 0x72705f666a505f53,0x296e6f6973696365,0x65722e090a7b090a,0x25203233752e2067\n"
".quad 0x090a3b3e31343c72,0x36752e206765722e,0x39323c6472252034,0x6765722e090a3b3e\n"
".quad 0x6625203233662e20,0x2e090a3b3e32343c,0x6572702e20676572,0x3e38313c70252064\n"
".quad 0x726168732e090a3b,0x67696c612e206465,0x2038622e2034206e,0x5f5f616475635f5f\n"
".quad 0x6f6c5f616475635f,0x5f7261765f6c6163,0x33335f3037353732,0x5f7466656c5f735f\n"
".quad 0x3868637461726373,0x343230315b383833,0x6168732e090a3b5d,0x696c612e20646572\n"
".quad 0x38622e2034206e67,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x335f31373537325f,0x686769725f735f33,0x6374617263735f74,0x30315b3231343968\n"
".quad 0x732e090a3b5d3432,0x752e206465726168,0x6475635f5f203233,0x5f6c61636f6c5f61\n"
".quad 0x393537325f726176,0x6e6f635f30345f35,0x615f646567726576,0x61657268745f6c6c\n"
".quad 0x6f6c2e090a3b7364,0x0930370938310963,0x656257444c240a30,0x30335a5f5f6e6967\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x746e49656e4f5f65,0x6650736c61767265\n"
".quad 0x5f535f536a6a5f53,0x7663090a3a666a50,0x31752e3233752e74,0x202c317225092036\n"
".quad 0x3b782e6469746e25,0x33752e747663090a,0x2509203631752e32,0x61746325202c3272\n"
".quad 0x6d090a3b782e6469,0x33752e6f6c2e6c75,0x202c337225092032,0x317225202c327225\n"
".quad 0x752e747663090a3b,0x09203631752e3233,0x697425202c347225,0x6461090a3b782e64\n"
".quad 0x2509203233752e64,0x2c337225202c3572,0x6c090a3b34722520,0x2e6d617261702e64\n"
".quad 0x3672250920323375,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623033\n"
".quad 0x614c6c656e72654b,0x49656e4f5f656772,0x736c61767265746e,0x5f536a6a5f536650\n"
".quad 0x756e5f666a505f53,0x767265746e695f6d,0x73090a3b5d736c61,0x752e74672e707465\n"
".quad 0x2c31702509203233,0x7225202c36722520,0x70252140090a3b35,0x2409206172622031\n"
".quad 0x3336315f315f744c,0x6f6c2e090a3b3638,0x0932390938310963,0x752e747663090a30\n"
".quad 0x09203233752e3436,0x7225202c31647225,0x2e6c756d090a3b35,0x3233752e65646977\n"
".quad 0x202c326472250920,0x0a3b34202c357225,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5f5b202c336472,0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365\n"
".quad 0x4f5f656772614c6c,0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a\n"
".quad 0x5d7466656c5f675f,0x752e646461090a3b,0x3464722509203436,0x202c33647225202c\n"
".quad 0x6c090a3b32647225,0x6c61626f6c672e64,0x662509203233662e,0x346472255b202c31\n"
".quad 0x6f6d090a3b5d302b,0x2509203233662e76,0x3b316625202c3266,0x3109636f6c2e090a\n"
".quad 0x090a300933390938,0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3564\n"
".quad 0x5f6d726170616475,0x6573696230335a5f,0x6c656e72654b7463,0x6e4f5f656772614c\n"
".quad 0x61767265746e4965,0x6a6a5f536650736c,0x5f666a505f535f53,0x5d74686769725f67\n"
".quad 0x752e646461090a3b,0x3664722509203436,0x202c35647225202c,0x6c090a3b32647225\n"
".quad 0x6c61626f6c672e64,0x662509203233662e,0x366472255b202c33,0x6f6d090a3b5d302b\n"
".quad 0x2509203233662e76,0x3b336625202c3466,0x3109636f6c2e090a,0x090a300934390938\n"
".quad 0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3764,0x5f6d726170616475\n"
".quad 0x6573696230335a5f,0x6c656e72654b7463,0x6e4f5f656772614c,0x61767265746e4965\n"
".quad 0x6a6a5f536650736c,0x5f666a505f535f53,0x0a3b5d736f705f67,0x3436752e64646109\n"
".quad 0x202c386472250920,0x7225202c37647225,0x2e646c090a3b3264,0x752e6c61626f6c67\n"
".quad 0x2c37722509203233,0x302b386472255b20,0x2e766f6d090a3b5d,0x3872250920323373\n"
".quad 0x240a3b377225202c,0x3336315f315f744c,0x766f6d090a3a3638,0x722509203233752e\n"
".quad 0x73090a3b30202c39,0x752e656e2e707465,0x2c32702509203233,0x7225202c34722520\n"
".quad 0x32702540090a3b39,0x4c24092061726220,0x393836315f315f74,0x636f6c2e090a3b38\n"
".quad 0x0933303109383109,0x752e766f6d090a30,0x3031722509203233,0x7473090a3b30202c\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f30345f35393537,0x65677265766e6f63,0x68745f6c6c615f64,0x202c5d7364616572\n"
".quad 0x4c240a3b30317225,0x393836315f315f74,0x636f6c2e090a3a38,0x0935303109383109\n"
".quad 0x732e726162090a30,0x0a3b300920636e79,0x617261702e646c09,0x2509203233752e6d\n"
".quad 0x5f5f5b202c313172,0x6d72617061647563,0x73696230335a5f5f,0x656e72654b746365\n"
".quad 0x4f5f656772614c6c,0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a\n"
".quad 0x6f6d090a3b5d6e5f,0x2509203233752e76,0x0a3b30202c323172,0x74672e7074657309\n"
".quad 0x702509203233752e,0x2c31317225202c33,0x090a3b3231722520,0x3233732e706c6573\n"
".quad 0x202c333172250920,0x7025202c30202c31,0x2e766f6d090a3b31,0x3566250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x3233752e766f6d09\n"
".quad 0x202c343172250920,0x2e766f6d090a3b30,0x6472250920343675,0x6475635f5f202c39\n"
".quad 0x616475635f5f5f61,0x765f6c61636f6c5f,0x30373537325f7261,0x656c5f735f33335f\n"
".quad 0x74617263735f7466,0x0a3b383833386863,0x3436752e766f6d09,0x2c30316472250920\n"
".quad 0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f,0x335f31373537325f\n"
".quad 0x686769725f735f33,0x6374617263735f74,0x240a3b3231343968,0x3531315f315f744c\n"
".quad 0x3c2f2f200a3a3232,0x6f4c203e706f6f6c,0x2079646f6220706f,0x31313120656e696c\n"
".quad 0x3109636f6c2e090a,0x0a30093131310938,0x3233752e766f6d09,0x202c353172250920\n"
".quad 0x732e7473090a3b31,0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164\n"
".quad 0x3537325f7261765f,0x6f635f30345f3539,0x5f6465677265766e,0x657268745f6c6c61\n"
".quad 0x7225202c5d736461,0x766f6d090a3b3531,0x722509203233752e,0x090a3b30202c3631\n"
".quad 0x2e71652e70746573,0x3470250920323375,0x202c34317225202c,0x73090a3b36317225\n"
".quad 0x203233732e706c65,0x31202c3731722509,0x347025202c30202c,0x622e646e61090a3b\n"
".quad 0x3831722509203233,0x202c37317225202c,0x6d090a3b33317225,0x09203233752e766f\n"
".quad 0x3b30202c39317225,0x652e70746573090a,0x2509203233732e71,0x38317225202c3570\n"
".quad 0x0a3b39317225202c,0x7262203570254009,0x315f744c24092061,0x0a3b30313437315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465,0x090a32323531315f\n"
".quad 0x09383109636f6c2e,0x6d090a3009363131,0x09203233662e766f,0x326625202c366625\n"
".quad 0x662e766f6d090a3b,0x2c37662509203233,0x3030303030663020,0x202020203b303030\n"
".quad 0x090a30202f2f0920,0x2e746c2e70746573,0x3670250920323366,0x25202c366625202c\n"
".quad 0x766f6d090a3b3766,0x662509203233662e,0x0a3b346625202c38,0x3233662e766f6d09\n"
".quad 0x30202c3966250920,0x3030303030303066,0x0920202020203b30,0x6573090a30202f2f\n"
".quad 0x33662e746c2e7074,0x202c377025092032,0x396625202c386625,0x3770252140090a3b\n"
".quad 0x4c24092061726220,0x373138315f315f74,0x6c3c2f2f200a3b38,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31313120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x323531315f315f74,0x09636f6c2e090a32,0x0a30093239093631\n"
".quad 0x33732e706c657309,0x2c30327225092032,0x25202c30202c3120,0x617262090a3b3670\n"
".quad 0x4c240920696e752e,0x323937315f315f74,0x315f744c240a3b32,0x0a3a38373138315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465,0x090a32323531315f\n"
".quad 0x3233732e706c6573,0x202c303272250920,0x7025202c31202c30,0x315f744c240a3b36\n"
".quad 0x0a3a32323937315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465\n"
".quad 0x090a32323531315f,0x09383109636f6c2e,0x73090a3009363131,0x09203233662e6275\n"
".quad 0x6625202c30316625,0x0a3b366625202c38,0x3233662e766f6d09,0x202c313166250920\n"
".quad 0x3030303066336630,0x09202020203b3030,0x090a352e30202f2f,0x203233662e64616d\n"
".quad 0x25202c3231662509,0x316625202c303166,0x0a3b366625202c31,0x3233662e64646109\n"
".quad 0x202c333166250920,0x366625202c386625,0x662e766f6d090a3b,0x3431662509203233\n"
".quad 0x303066336630202c,0x2020203b30303030,0x352e30202f2f0920,0x33662e6c756d090a\n"
".quad 0x2c35316625092032,0x25202c3331662520,0x656e090a3b343166,0x2509203233732e67\n"
".quad 0x327225202c313272,0x74636c73090a3b30,0x3233732e3233662e,0x25202c3566250920\n"
".quad 0x316625202c353166,0x3b31327225202c32,0x315f315f744c240a,0x2f200a3a30313437\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3131,0x64656c6562616c20,0x315f315f744c2420,0x6c2e090a32323531\n"
".quad 0x333209363109636f,0x766f6d090a300938,0x722509203233732e,0x31317225202c3232\n"
".quad 0x3370252140090a3b,0x4c24092061726220,0x363034325f315f74,0x6c3c2f2f200a3b36\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31313120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x323531315f315f74,0x752e766f6d090a32\n"
".quad 0x3332722509203233,0x6f6d090a3b30202c,0x2509203233752e76,0x0a3b30202c343272\n"
".quad 0x3233662e766f6d09,0x202c363166250920,0x3030303866336630,0x09202020203b3030\n"
".quad 0x744c240a31202f2f,0x36343938315f315f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f\n"
".quad 0x696c2079646f6220,0x202c38333220656e,0x20676e697473656e,0x31203a6874706564\n"
".quad 0x616d69747365202c,0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75\n"
".quad 0x363109636f6c2e09,0x090a300933343209,0x636e79732e726162,0x6461090a3b300920\n"
".quad 0x2509203233752e64,0x327225202c353272,0x0a3b347225202c33,0x656c2e7074657309\n"
".quad 0x702509203233752e,0x2c31317225202c38,0x090a3b3532722520,0x6172622038702540\n"
".quad 0x5f315f744c240920,0x200a3b3230323931,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x2e090a3634393831,0x3209363109636f6c,0x7663090a30093834\n"
".quad 0x33752e3436752e74,0x3131647225092032,0x090a3b347225202c,0x656469772e6c756d\n"
".quad 0x722509203233752e,0x347225202c323164,0x7663090a3b34202c,0x33752e3436752e74\n"
".quad 0x3331647225092032,0x0a3b33327225202c,0x3436752e64646109,0x2c34316472250920\n"
".quad 0x202c333164722520,0x090a3b3131647225,0x752e6f6c2e6c756d,0x3164722509203436\n"
".quad 0x3431647225202c35,0x646c090a3b34202c,0x752e6d617261702e,0x3164722509203436\n"
".quad 0x75635f5f5b202c36,0x5f5f6d7261706164,0x636573696230335a,0x4c6c656e72654b74\n"
".quad 0x656e4f5f65677261,0x6c61767265746e49,0x536a6a5f53665073,0x675f666a505f535f\n"
".quad 0x6461090a3b5d645f,0x2509203436752e64,0x7225202c37316472,0x647225202c363164\n"
".quad 0x2e646c090a3b3531,0x662e6c61626f6c67,0x3731662509203233,0x37316472255b202c\n"
".quad 0x6461090a3b5d302b,0x2509203436752e64,0x7225202c38316472,0x647225202c323164\n"
".quad 0x732e7473090a3b39,0x33662e6465726168,0x316472255b092032,0x6625202c5d302b38\n"
".quad 0x6f6c2e090a3b3731,0x3934320936310963,0x702e646c090a3009,0x3436752e6d617261\n"
".quad 0x2c39316472250920,0x616475635f5f5b20,0x335a5f5f6d726170,0x4b74636573696230\n"
".quad 0x72614c6c656e7265,0x6e49656e4f5f6567,0x50736c6176726574,0x535f536a6a5f5366\n"
".quad 0x735f675f666a505f,0x2e646461090a3b5d,0x6472250920343675,0x31647225202c3032\n"
".quad 0x3531647225202c39,0x6c672e646c090a3b,0x3233662e6c61626f,0x202c383166250920\n"
".quad 0x2d2b30326472255b,0x646461090a3b5d34,0x722509203436752e,0x647225202c313264\n"
".quad 0x31647225202c3231,0x732e7473090a3b30,0x33662e6465726168,0x326472255b092032\n"
".quad 0x6625202c5d302b31,0x5f744c240a3b3831,0x3a32303239315f31,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3833322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a36343938315f31,0x363109636f6c2e09\n"
".quad 0x090a300932353209,0x636e79732e726162,0x2140090a3b300920,0x2061726220317025\n"
".quad 0x325f315f744c2409,0x2f200a3b36323230,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3833,0x64656c6562616c20\n"
".quad 0x315f315f744c2420,0x696d090a36343938,0x2509203233752e6e,0x327225202c363272\n"
".quad 0x0a3b317225202c32,0x3233752e766f6d09,0x202c373272250920,0x70746573090a3b30\n"
".quad 0x203233752e71652e,0x7225202c39702509,0x37327225202c3632,0x2039702540090a3b\n"
".quad 0x744c240920617262,0x36323230325f315f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c38333220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x36343938315f315f,0x33732e766f6d090a,0x2c38327225092032\n"
".quad 0x090a3b3632722520,0x203436732e766f6d,0x202c323264722509,0x6d090a3b39647225\n"
".quad 0x09203436732e766f,0x25202c3332647225,0x6d090a3b30316472,0x09203233752e766f\n"
".quad 0x3b30202c39327225,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3833322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a36343938315f31,0x3233732e766f6d09,0x202c303372250920,0x4c240a3b38327225\n"
".quad 0x333730325f315f74,0x6c3c2f2f200a3a38,0x6f6f4c203e706f6f,0x6c2079646f622070\n"
".quad 0x2c32353220656e69,0x676e697473656e20,0x203a687470656420,0x6d69747365202c32\n"
".quad 0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520,0x3109636f6c2e090a\n"
".quad 0x0a30093036320936,0x726168732e646c09,0x09203233662e6465,0x255b202c39316625\n"
".quad 0x3b5d302b33326472,0x6168732e646c090a,0x203233662e646572,0x5b202c3032662509\n"
".quad 0x5d302b3232647225,0x662e627573090a3b,0x3132662509203233,0x202c30326625202c\n"
".quad 0x756d090a3b356625,0x2509203233662e6c,0x316625202c323266,0x3b39316625202c39\n"
".quad 0x75662e766964090a,0x09203233662e6c6c,0x6625202c33326625,0x36316625202c3232\n"
".quad 0x662e627573090a3b,0x3631662509203233,0x202c31326625202c,0x2e090a3b33326625\n"
".quad 0x3209363109636f6c,0x6f6d090a30093236,0x2509203233662e76,0x306630202c343266\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x6c2e746573090a30,0x33662e3233752e74\n"
".quad 0x2c31337225092032,0x25202c3631662520,0x656e090a3b343266,0x2509203233732e67\n"
".quad 0x337225202c323372,0x2e646461090a3b31,0x3272250920323375,0x2c34327225202c34\n"
".quad 0x090a3b3233722520,0x203233752e646461,0x25202c3932722509,0x0a3b31202c393272\n"
".quad 0x3436752e64646109,0x2c33326472250920,0x202c333264722520,0x2e646461090a3b34\n"
".quad 0x6472250920343675,0x32647225202c3232,0x73090a3b34202c32,0x752e656e2e707465\n"
".quad 0x3031702509203233,0x202c36327225202c,0x40090a3b39327225,0x6172622030317025\n"
".quad 0x5f315f744c240920,0x240a3b3833373032,0x3230325f315f744c,0x5f744c240a3a3632\n"
".quad 0x3a34313739315f31,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3833322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a36343938315f31,0x363109636f6c2e09,0x090a300937363209,0x203233752e627573\n"
".quad 0x25202c3232722509,0x317225202c323272,0x752e646461090a3b,0x3332722509203233\n"
".quad 0x202c33327225202c,0x6573090a3b317225,0x33752e746c2e7074,0x2c31317025092032\n"
".quad 0x25202c3332722520,0x2540090a3b313172,0x2061726220313170,0x315f315f744c2409\n"
".quad 0x2f200a3b36343938,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3120656e696c2079,0x64616568202c3131,0x64656c6562616c20,0x315f315f744c2420\n"
".quad 0x7262090a32323531,0x240920696e752e61,0x3438315f315f744c,0x5f744c240a3b3433\n"
".quad 0x3a36363034325f31,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3131312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32323531315f31,0x3233752e766f6d09,0x202c343272250920,0x315f744c240a3b30\n"
".quad 0x0a3a34333438315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31313120,0x6c6562616c206461,0x315f744c24206465\n"
".quad 0x090a32323531315f,0x09383109636f6c2e,0x62090a3009363231,0x20636e79732e7261\n"
".quad 0x766f6d090a3b3009,0x722509203233752e,0x090a3b30202c3333,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x2c38317225202c32,0x090a3b3333722520,0x7262203231702540\n"
".quad 0x315f744c24092061,0x0a3b30333532325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31313120,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x090a32323531315f,0x203233732e766f6d,0x25202c3433722509\n"
".quad 0x746573090a3b3872,0x3233752e656e2e70,0x202c333170250920,0x7225202c34337225\n"
".quad 0x702540090a3b3432,0x0920617262203331,0x32325f315f744c24,0x2f2f200a3b343732\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x313120656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x31315f315f744c24,0x6f6c2e090a323235\n"
".quad 0x3333310938310963,0x2e766f6d090a3009,0x3866250920323366,0x090a3b356625202c\n"
".quad 0x203233662e766f6d,0x6625202c34662509,0x2e766f6d090a3b38,0x3666250920323366\n"
".quad 0x090a3b326625202c,0x20696e752e617262,0x325f315f744c2409,0x4c240a3b38313032\n"
".quad 0x373232325f315f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31313120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x323531315f315f74,0x09636f6c2e090a32,0x3009363331093831,0x33662e766f6d090a\n"
".quad 0x202c366625092032,0x6f6d090a3b356625,0x2509203233662e76,0x3b366625202c3266\n"
".quad 0x33662e766f6d090a,0x202c386625092032,0x744c240a3b346625,0x38313032325f315f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c31313120656e,0x62616c2064616568,0x744c242064656c65,0x32323531315f315f\n"
".quad 0x33662e627573090a,0x2c35326625092032,0x6625202c38662520,0x702e646c090a3b36\n"
".quad 0x3233662e6d617261,0x202c363266250920,0x70616475635f5f5b,0x30335a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x746e49656e4f5f65,0x6650736c61767265\n"
".quad 0x5f535f536a6a5f53,0x636572705f666a50,0x0a3b5d6e6f697369,0x3233662e73626109\n"
".quad 0x202c373266250920,0x6261090a3b386625,0x2509203233662e73,0x366625202c383266\n"
".quad 0x662e78616d090a3b,0x3932662509203233,0x202c37326625202c,0x6d090a3b38326625\n"
".quad 0x09203233662e6c75,0x6625202c30336625,0x39326625202c3632,0x662e6e696d090a3b\n"
".quad 0x3133662509203233,0x202c36326625202c,0x73090a3b30336625,0x662e746c2e707465\n"
".quad 0x3431702509203233,0x202c35326625202c,0x40090a3b31336625,0x7262203431702521\n"
".quad 0x315f744c24092061,0x0a3b36383732325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31313120,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x090a32323531315f,0x09383109636f6c2e,0x6d090a3009343431\n"
".quad 0x09203233662e766f,0x6630202c32336625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x70746573090a3020,0x203233662e746c2e,0x6625202c36702509,0x3b32336625202c36\n"
".quad 0x33662e766f6d090a,0x2c33336625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x73090a30202f2f09,0x662e746c2e707465,0x3531702509203233,0x25202c386625202c\n"
".quad 0x2140090a3b333366,0x6172622035317025,0x5f315f744c240920,0x200a3b3839323332\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313131,0x656c6562616c2064,0x5f315f744c242064,0x2e090a3232353131\n"
".quad 0x3909363109636f6c,0x6c6573090a300932,0x2509203233732e70,0x202c31202c353372\n"
".quad 0x0a3b367025202c30,0x696e752e61726209,0x5f315f744c240920,0x240a3b3234303332\n"
".quad 0x3233325f315f744c,0x3c2f2f200a3a3839,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x31313120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3531315f315f744c,0x706c6573090a3232,0x722509203233732e,0x31202c30202c3533\n"
".quad 0x240a3b367025202c,0x3033325f315f744c,0x3c2f2f200a3a3234,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31313120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3531315f315f744c,0x2e646461090a3232,0x3366250920323366\n"
".quad 0x202c386625202c34,0x6f6d090a3b366625,0x2509203233662e76,0x336630202c353366\n"
".quad 0x3b30303030303066,0x202f2f0920202020,0x64616d090a352e30,0x662509203233662e\n"
".quad 0x35326625202c3633,0x202c35336625202c,0x6f6d090a3b366625,0x2509203233662e76\n"
".quad 0x336630202c373366,0x3b30303030303066,0x202f2f0920202020,0x6c756d090a352e30\n"
".quad 0x662509203233662e,0x34336625202c3833,0x0a3b37336625202c,0x3233732e67656e09\n"
".quad 0x202c363372250920,0x73090a3b35337225,0x2e3233662e74636c,0x3366250920323373\n"
".quad 0x2c38336625202c39,0x25202c3633662520,0x6c2e090a3b363372,0x343109383109636f\n"
".quad 0x766f6d090a300935,0x662509203233662e,0x3b39336625202c32,0x3109636f6c2e090a\n"
".quad 0x0a30093634310938,0x3233662e766f6d09,0x25202c3466250920,0x6f6d090a3b393366\n"
".quad 0x2509203233752e76,0x0a3b31202c343172,0x696e752e61726209,0x5f315f744c240920\n"
".quad 0x240a3b3033353232,0x3732325f315f744c,0x3c2f2f200a3a3638,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31313120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3531315f315f744c,0x636f6c2e090a3232,0x0931353109383109\n"
".quad 0x752e766f6d090a30,0x3733722509203233,0x7473090a3b30202c,0x2e6465726168732e\n"
".quad 0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f35393537\n"
".quad 0x65677265766e6f63,0x68745f6c6c615f64,0x202c5d7364616572,0x4c240a3b37337225\n"
".quad 0x333532325f315f74,0x315f744c240a3a30,0x0a3a36303531325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31313120\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x090a32323531315f,0x09383109636f6c2e\n"
".quad 0x62090a3009353531,0x20636e79732e7261,0x6f6c2e090a3b3009,0x3835310938310963\n"
".quad 0x732e646c090a3009,0x33752e6465726168,0x2c38337225092032,0x616475635f5f5b20\n"
".quad 0x765f6c61636f6c5f,0x35393537325f7261,0x766e6f635f30345f,0x6c615f6465677265\n"
".quad 0x6461657268745f6c,0x766f6d090a3b5d73,0x722509203233752e,0x090a3b31202c3933\n"
".quad 0x2e71652e70746573,0x3170250920323375,0x2c38337225202c36,0x090a3b3933722520\n"
".quad 0x7262203631702540,0x315f744c24092061,0x2f200a3b3835325f,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3131\n"
".quad 0x64656c6562616c20,0x315f315f744c2420,0x6c2e090a32323531,0x363109383109636f\n"
".quad 0x726162090a300931,0x300920636e79732e,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b32323531315f31,0x325f315f744c240a,0x6f6c2e090a3a3835,0x3536310938310963\n"
".quad 0x2e726162090a3009,0x3b300920636e7973,0x203170252140090a,0x744c240920617262\n"
".quad 0x34353533325f315f,0x09636f6c2e090a3b,0x3009393631093831,0x33662e766f6d090a\n"
".quad 0x2c30346625092032,0x6c090a3b32662520,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x635f5f5b202c3432,0x5f6d726170616475,0x6573696230335a5f,0x6c656e72654b7463\n"
".quad 0x6e4f5f656772614c,0x61767265746e4965,0x6a6a5f536650736c,0x5f666a505f535f53\n"
".quad 0x3b5d7466656c5f67,0x36752e747663090a,0x2509203233752e34,0x7225202c35326472\n"
".quad 0x2e6c756d090a3b35,0x3233752e65646977,0x2c36326472250920,0x3b34202c35722520\n"
".quad 0x36752e646461090a,0x3732647225092034,0x2c3432647225202c,0x0a3b363264722520\n"
".quad 0x626f6c672e747309,0x09203233662e6c61,0x302b37326472255b,0x3b30346625202c5d\n"
".quad 0x325f315f744c240a,0x2e090a3a34353533,0x3109383109636f6c,0x7865090a30093237\n"
".quad 0x57444c240a3b7469,0x30335a5f5f646e65,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x746e49656e4f5f65,0x6650736c61767265,0x5f535f536a6a5f53,0x207d090a3a666a50\n"
".quad 0x6230335a5f202f2f,0x72654b7463657369,0x656772614c6c656e,0x65746e49656e4f5f\n"
".quad 0x536650736c617672,0x505f535f536a6a5f,0x6e652e090a0a666a,0x31335a5f20797274\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574\n"
".quad 0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053,0x702e09090a282066\n"
".quad 0x36752e206d617261,0x616475635f5f2034,0x335a5f5f6d726170,0x4b74636573696231\n"
".quad 0x72614c6c656e7265,0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650\n"
".quad 0x30535f535f535f30,0x30535f535f30535f,0x0a2c645f675f665f,0x6d617261702e0909\n"
".quad 0x5f5f203436752e20,0x6d72617061647563,0x73696231335a5f5f,0x656e72654b746365\n"
".quad 0x4d5f656772614c6c,0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a\n"
".quad 0x5f30535f30535f53,0x675f665f30535f53,0x702e09090a2c735f,0x33752e206d617261\n"
".quad 0x616475635f5f2032,0x335a5f5f6d726170,0x4b74636573696231,0x72614c6c656e7265\n"
".quad 0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650,0x30535f535f535f30\n"
".quad 0x30535f535f30535f,0x09090a2c6e5f665f,0x2e206d617261702e,0x75635f5f20343675\n"
".quad 0x5f5f6d7261706164,0x636573696231335a,0x4c6c656e72654b74,0x6c754d5f65677261\n"
".quad 0x61767265746e4974,0x506a5f536650736c,0x5f535f535f30536a,0x5f535f30535f3053\n"
".quad 0x6f6c625f665f3053,0x746c756d5f736b63,0x7261702e09090a2c,0x203436752e206d61\n"
".quad 0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369,0x656772614c6c656e\n"
".quad 0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53,0x535f30535f535f53\n"
".quad 0x665f30535f535f30,0x5f736b636f6c625f,0x6d75735f746c756d,0x7261702e09090a2c\n"
".quad 0x203436752e206d61,0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53\n"
".quad 0x535f30535f535f53,0x665f30535f535f30,0x2c7466656c5f675f,0x617261702e09090a\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x696231335a5f5f6d,0x6e72654b74636573\n"
".quad 0x5f656772614c6c65,0x65746e49746c754d,0x536650736c617672,0x535f30536a506a5f\n"
".quad 0x30535f30535f535f,0x5f665f30535f535f,0x2c74686769725f67,0x617261702e09090a\n"
".quad 0x5f203436752e206d,0x726170616475635f,0x696231335a5f5f6d,0x6e72654b74636573\n"
".quad 0x5f656772614c6c65,0x65746e49746c754d,0x536650736c617672,0x535f30536a506a5f\n"
".quad 0x30535f30535f535f,0x5f665f30535f535f,0x635f7466656c5f67,0x09090a2c746e756f\n"
".quad 0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164,0x636573696231335a\n"
".quad 0x4c6c656e72654b74,0x6c754d5f65677261,0x61767265746e4974,0x506a5f536650736c\n"
".quad 0x5f535f535f30536a,0x5f535f30535f3053,0x725f675f665f3053,0x756f635f74686769\n"
".quad 0x702e09090a2c746e,0x36752e206d617261,0x616475635f5f2034,0x335a5f5f6d726170\n"
".quad 0x4b74636573696231,0x72614c6c656e7265,0x49746c754d5f6567,0x736c61767265746e\n"
".quad 0x536a506a5f536650,0x30535f535f535f30,0x30535f535f30535f,0x6d616c5f675f665f\n"
".quad 0x2e09090a2c616462,0x752e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x7463657369623133,0x614c6c656e72654b,0x746c754d5f656772,0x6c61767265746e49\n"
".quad 0x6a506a5f53665073,0x535f535f535f3053,0x535f535f30535f30,0x6f705f675f665f30\n"
".quad 0x61702e09090a2c73,0x3233662e206d6172,0x70616475635f5f20,0x31335a5f5f6d7261\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574\n"
".quad 0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053,0x7369636572705f66\n"
".quad 0x0a7b090a296e6f69,0x752e206765722e09,0x36313c7225203233,0x65722e090a3b3e32\n"
".quad 0x25203436752e2067,0x0a3b3e36383c6472,0x662e206765722e09,0x35383c6625203233\n"
".quad 0x6765722e090a3b3e,0x6625203436662e20,0x2e090a3b3e383c64,0x6572702e20676572\n"
".quad 0x3e30353c70252064,0x726168732e090a3b,0x67696c612e206465,0x2038622e2034206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3337383732\n"
".quad 0x61706d6f635f735f,0x696c5f6e6f697463,0x5b32333530317473,0x090a3b5d32353032\n"
".quad 0x206465726168732e,0x34206e67696c612e,0x635f5f2038622e20,0x75635f5f5f616475\n"
".quad 0x6c61636f6c5f6164,0x3837325f7261765f,0x5f735f33335f3636,0x3532317468676972\n"
".quad 0x5d383430325b3438,0x726168732e090a3b,0x67696c612e206465,0x2038622e2034206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3037383732\n"
".quad 0x74686769725f735f,0x3431746e756f635f,0x383430325b323336,0x6168732e090a3b5d\n"
".quad 0x696c612e20646572,0x38622e2034206e67,0x5f616475635f5f20,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x335f35363837325f,0x7466656c5f735f33,0x30325b3038363631\n"
".quad 0x732e090a3b5d3834,0x612e206465726168,0x2e2034206e67696c,0x6475635f5f203862\n"
".quad 0x616475635f5f5f61,0x765f6c61636f6c5f,0x39363837325f7261,0x656c5f735f30345f\n"
".quad 0x746e756f635f7466,0x30325b3832373831,0x732e090a3b5d3834,0x752e206465726168\n"
".quad 0x6475635f5f203233,0x5f6c61636f6c5f61,0x383837325f726176,0x625f635f30345f37\n"
".quad 0x6174735f6b636f6c,0x68732e090a3b7472,0x33752e2064657261,0x616475635f5f2032\n"
".quad 0x765f6c61636f6c5f,0x38383837325f7261,0x6c625f635f30345f,0x3b646e655f6b636f\n"
".quad 0x65726168732e090a,0x5f203233752e2064,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x30345f3938383732,0x6b636f6c625f635f,0x5f74657366666f5f,0x0a3b74757074756f\n"
".quad 0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f30345f30383837,0x657268745f6d756e,0x697463615f736461,0x68732e090a3b6576\n"
".quad 0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f,0x32383837325f7261\n"
".quad 0x5f6d756e5f30345f,0x5f73646165726874,0x69746361706d6f63,0x68732e090a3b6e6f\n"
".quad 0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f,0x38373837325f7261\n"
".quad 0x5f6c6c615f30345f,0x5f73646165726874,0x65677265766e6f63,0x6168732e090a3b64\n"
".quad 0x3233752e20646572,0x5f616475635f5f20,0x61765f6c61636f6c,0x5f34383837325f72\n"
".quad 0x61706d6f635f3034,0x6e6f6365735f7463,0x3b6b6e7568635f64,0x3309636f6c2e090a\n"
".quad 0x240a300938370932,0x6e6967656257444c,0x73696231335a5f5f,0x656e72654b746365\n"
".quad 0x4d5f656772614c6c,0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a\n"
".quad 0x5f30535f30535f53,0x0a3a665f30535f53,0x3233752e74766309,0x722509203631752e\n"
".quad 0x2e64697425202c31,0x2e766f6d090a3b78,0x3272250920323375,0x6573090a3b30202c\n"
".quad 0x33752e71652e7074,0x202c317025092032,0x327225202c317225,0x3170252140090a3b\n"
".quad 0x4c24092061726220,0x333939335f325f74,0x636f6c2e090a3b38,0x0935323109323309\n"
".quad 0x752e747663090a30,0x09203631752e3436,0x6325202c31647225,0x0a3b782e64696174\n"
".quad 0x2e6f6c2e6c756d09,0x6472250920343675,0x2c31647225202c32,0x2e646c090a3b3420\n"
".quad 0x36752e6d61726170,0x2c33647225092034,0x616475635f5f5b20,0x335a5f5f6d726170\n"
".quad 0x4b74636573696231,0x72614c6c656e7265,0x49746c754d5f6567,0x736c61767265746e\n"
".quad 0x536a506a5f536650,0x30535f535f535f30,0x30535f535f30535f,0x6b636f6c625f665f\n"
".quad 0x3b5d746c756d5f73,0x36752e646461090a,0x2c34647225092034,0x25202c3264722520\n"
".quad 0x646c090a3b336472,0x2e6c61626f6c672e,0x3372250920323375,0x2b346472255b202c\n"
".quad 0x2e7473090a3b5d30,0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475\n"
".quad 0x37325f7261765f6c,0x635f30345f373838,0x735f6b636f6c625f,0x25202c5d74726174\n"
".quad 0x6f6c2e090a3b3372,0x3632310932330963,0x2e747663090a3009,0x203436752e323375\n"
".quad 0x7225202c34722509,0x747663090a3b3164,0x3233752e3436752e,0x202c356472250920\n"
".quad 0x756d090a3b347225,0x752e656469772e6c,0x3664722509203233,0x34202c347225202c\n"
".quad 0x752e646461090a3b,0x3764722509203436,0x202c33647225202c,0x6c090a3b36647225\n"
".quad 0x6c61626f6c672e64,0x722509203233752e,0x376472255b202c35,0x7473090a3b5d342b\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f30345f38383837,0x5f6b636f6c625f63,0x7225202c5d646e65,0x636f6c2e090a3b35\n"
".quad 0x0937323109323309,0x61702e646c090a30,0x203436752e6d6172,0x5b202c3864722509\n"
".quad 0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369,0x656772614c6c656e\n"
".quad 0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53,0x535f30535f535f53\n"
".quad 0x665f30535f535f30,0x5f736b636f6c625f,0x6d75735f746c756d,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x2c38647225202c39,0x090a3b3264722520,0x61626f6c672e646c\n"
".quad 0x2509203233752e6c,0x6472255b202c3672,0x73090a3b5d302b39,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3938383732\n"
".quad 0x6b636f6c625f635f,0x5f74657366666f5f,0x2c5d74757074756f,0x2e090a3b36722520\n"
".quad 0x3109323309636f6c,0x7573090a30093932,0x2509203233752e62,0x2c357225202c3772\n"
".quad 0x73090a3b33722520,0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x30345f3038383732,0x7268745f6d756e5f,0x7463615f73646165\n"
".quad 0x7225202c5d657669,0x636f6c2e090a3b37,0x0930333109323309,0x752e766f6d090a30\n"
".quad 0x2c38722509203233,0x2e7473090a3b3020,0x752e646572616873,0x635f5f5b09203233\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3837325f7261765f,0x5f735f30345f3337\n"
".quad 0x69746361706d6f63,0x317473696c5f6e6f,0x2c5d302b32333530,0x2e090a3b38722520\n"
".quad 0x3109323309636f6c,0x7573090a30093133,0x2509203233732e62,0x2c377225202c3972\n"
".quad 0x646e61090a3b3120,0x722509203233622e,0x2c377225202c3031,0x6d090a3b39722520\n"
".quad 0x09203233752e766f,0x3b30202c31317225,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x30317225202c3270,0x0a3b31317225202c,0x7262203270254009,0x325f744c24092061\n"
".quad 0x0a3b30353430345f,0x3233732e766f6d09,0x202c323172250920,0x7262090a3b377225\n"
".quad 0x240920696e752e61,0x5f69646e6557444c,0x325f667078657266,0x4c240a3b345f3632\n"
".quad 0x353430345f325f74,0x636f6c2e090a3a30,0x0935383209393109,0x722e747663090a30\n"
".quad 0x33732e3233662e6e,0x202c316625092032,0x6f6d090a3b377225,0x2509203233662e76\n"
".quad 0x3b316625202c3266,0x33662e736261090a,0x202c336625092032,0x6f6d090a3b316625\n"
".quad 0x2509203233662e76,0x30306630202c3466,0x203b303030303038,0x202f2f0920202020\n"
".quad 0x6539343537312e31,0x746573090a38332d,0x3233662e746c2e70,0x25202c3370250920\n"
".quad 0x3b346625202c3366,0x203370252140090a,0x744c240920617262,0x38313231345f325f\n"
".quad 0x09636f6c2e090a3b,0x0939353332093132,0x662e766f6d090a30,0x2c35662509203233\n"
".quad 0x3030386234663020,0x202020203b303030,0x362e31202f2f0920,0x37302b6532373737\n"
".quad 0x33662e6c756d090a,0x202c326625092032,0x356625202c316625,0x752e766f6d090a3b\n"
".quad 0x3331722509203233,0x62090a3b3432202c,0x0920696e752e6172,0x30345f325f744c24\n"
".quad 0x744c240a3b323639,0x38313231345f325f,0x09636f6c2e090a3a,0x0932363332093132\n"
".quad 0x752e766f6d090a30,0x3331722509203233,0x744c240a3b30202c,0x32363930345f325f\n"
".quad 0x09636f6c2e090a3a,0x0a30093737093631,0x3233622e766f6d09,0x202c343172250920\n"
".quad 0x6873090a3b326625,0x2509203233732e72,0x317225202c353172,0x090a3b3332202c34\n"
".quad 0x203233622e646e61,0x25202c3631722509,0x353532202c353172,0x752e766f6d090a3b\n"
".quad 0x3731722509203233,0x7573090a3b30202c,0x2509203233752e62,0x317225202c383172\n"
".quad 0x3b33317225202c36,0x33752e627573090a,0x2c39317225092032,0x31202c3831722520\n"
".quad 0x766f6d090a3b3632,0x722509203233752e,0x3b353532202c3032,0x71652e746573090a\n"
".quad 0x3233752e3233752e,0x202c313272250920,0x7225202c36317225,0x67656e090a3b3032\n"
".quad 0x722509203233732e,0x31327225202c3232,0x662e766f6d090a3b,0x2c36662509203233\n"
".quad 0x3030303030663020,0x202020203b303030,0x090a30202f2f0920,0x752e71652e746573\n"
".quad 0x09203233662e3233,0x6625202c33327225,0x0a3b366625202c33,0x3233732e67656e09\n"
".quad 0x202c343272250920,0x6f090a3b33327225,0x2509203233622e72,0x327225202c353272\n"
".quad 0x3b34327225202c32,0x33732e67656e090a,0x2c36327225092032,0x090a3b3532722520\n"
".quad 0x3233752e74636c73,0x722509203233732e,0x39317225202c3732,0x202c37317225202c\n"
".quad 0x73090a3b36327225,0x09203233622e6c68,0x2c31202c32317225,0x240a3b3732722520\n"
".quad 0x5f69646e6557444c,0x325f667078657266,0x2e090a3a345f3632,0x3109323309636f6c\n"
".quad 0x7473090a30093133,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f32383837,0x657268745f6d756e,0x706d6f635f736461\n"
".quad 0x2c5d6e6f69746361,0x090a3b3231722520,0x09323309636f6c2e,0x6d090a3009333331\n"
".quad 0x09203233752e766f,0x3b31202c38327225,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x616475635f5f5b09,0x765f6c61636f6c5f,0x38373837325f7261,0x5f6c6c615f30345f\n"
".quad 0x5f73646165726874,0x65677265766e6f63,0x38327225202c5d64,0x09636f6c2e090a3b\n"
".quad 0x3009343331093233,0x33752e766f6d090a,0x2c39327225092032,0x2e7473090a3b3020\n"
".quad 0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475,0x37325f7261765f6c\n"
".quad 0x635f30345f343838,0x735f746361706d6f,0x68635f646e6f6365,0x7225202c5d6b6e75\n"
".quad 0x5f744c240a3b3932,0x3a38333939335f32,0x3309636f6c2e090a,0x0a30093733310932\n"
".quad 0x6e79732e72616209,0x6c090a3b30092063,0x6465726168732e64,0x722509203233752e\n"
".quad 0x635f5f5b202c3033,0x61636f6c5f616475,0x37325f7261765f6c,0x6e5f30345f303838\n"
".quad 0x61657268745f6d75,0x76697463615f7364,0x746573090a3b5d65,0x3233752e656c2e70\n"
".quad 0x25202c3470250920,0x317225202c303372,0x2034702540090a3b,0x744c240920617262\n"
".quad 0x34373431345f325f,0x09636f6c2e090a3b,0x3009323431093233,0x36752e766f6d090a\n"
".quad 0x3031647225092034,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f36363837325f72,0x6769725f735f3333,0x3b34383532317468,0x36752e766f6d090a\n"
".quad 0x3131647225092034,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f30373837325f72,0x6769725f735f3034,0x746e756f635f7468,0x090a3b3233363431\n"
".quad 0x203436752e766f6d,0x202c323164722509,0x5f5f616475635f5f,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x33335f3536383732,0x317466656c5f735f,0x6d090a3b30383636\n"
".quad 0x09203436752e766f,0x5f202c3331647225,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f39363837,0x635f7466656c5f73,0x32373831746e756f\n"
".quad 0x2e747663090a3b38,0x203233752e343675,0x202c343164722509,0x756d090a3b317225\n"
".quad 0x752e656469772e6c,0x3164722509203233,0x202c317225202c35,0x732e646c090a3b34\n"
".quad 0x33752e6465726168,0x2c31337225092032,0x616475635f5f5b20,0x765f6c61636f6c5f\n"
".quad 0x37383837325f7261,0x6c625f635f30345f,0x726174735f6b636f,0x646461090a3b5d74\n"
".quad 0x722509203233752e,0x31337225202c3233,0x090a3b317225202c,0x2e3436752e747663\n"
".quad 0x6472250920323375,0x32337225202c3631,0x772e6c756d090a3b,0x203233752e656469\n"
".quad 0x202c373164722509,0x3b34202c32337225,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5b202c3831647225,0x6170616475635f5f,0x6231335a5f5f6d72,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265,0x5f30536a506a5f53\n"
".quad 0x535f30535f535f53,0x665f30535f535f30,0x5d7466656c5f675f,0x752e646461090a3b\n"
".quad 0x3164722509203436,0x3831647225202c39,0x3b3731647225202c,0x6f6c672e646c090a\n"
".quad 0x203233662e6c6162,0x255b202c37662509,0x3b5d302b39316472,0x36752e646461090a\n"
".quad 0x3032647225092034,0x2c3531647225202c,0x0a3b323164722520,0x726168732e747309\n"
".quad 0x09203233662e6465,0x302b30326472255b,0x0a3b376625202c5d,0x323309636f6c2e09\n"
".quad 0x090a300933343109,0x6d617261702e646c,0x722509203436752e,0x5f5f5b202c313264\n"
".quad 0x6d72617061647563,0x73696231335a5f5f,0x656e72654b746365,0x4d5f656772614c6c\n"
".quad 0x7265746e49746c75,0x5f536650736c6176,0x5f535f30536a506a,0x5f30535f30535f53\n"
".quad 0x675f665f30535f53,0x3b5d74686769725f,0x36752e646461090a,0x3232647225092034\n"
".quad 0x2c3132647225202c,0x0a3b373164722520,0x626f6c672e646c09,0x09203233662e6c61\n"
".quad 0x72255b202c386625,0x0a3b5d302b323264,0x3436752e64646109,0x2c33326472250920\n"
".quad 0x202c353164722520,0x090a3b3031647225,0x65726168732e7473,0x5b09203233662e64\n"
".quad 0x5d302b3332647225,0x090a3b386625202c,0x09323309636f6c2e,0x6c090a3009343431\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x635f5f5b202c3432,0x5f6d726170616475\n"
".quad 0x6573696231335a5f,0x6c656e72654b7463,0x754d5f656772614c,0x767265746e49746c\n"
".quad 0x6a5f536650736c61,0x535f535f30536a50,0x535f30535f30535f,0x5f675f665f30535f\n"
".quad 0x756f635f7466656c,0x6461090a3b5d746e,0x2509203436752e64,0x7225202c35326472\n"
".quad 0x647225202c343264,0x2e646c090a3b3731,0x752e6c61626f6c67,0x3333722509203233\n"
".quad 0x35326472255b202c,0x6461090a3b5d302b,0x2509203436752e64,0x7225202c36326472\n"
".quad 0x647225202c353164,0x2e7473090a3b3331,0x752e646572616873,0x6472255b09203233\n"
".quad 0x25202c5d302b3632,0x6c2e090a3b333372,0x343109323309636f,0x2e646c090a300935\n"
".quad 0x36752e6d61726170,0x3732647225092034,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x7463657369623133,0x614c6c656e72654b,0x746c754d5f656772,0x6c61767265746e49\n"
".quad 0x6a506a5f53665073,0x535f535f535f3053,0x535f535f30535f30,0x69725f675f665f30\n"
".quad 0x6e756f635f746867,0x646461090a3b5d74,0x722509203436752e,0x647225202c383264\n"
".quad 0x31647225202c3732,0x672e646c090a3b37,0x33752e6c61626f6c,0x2c34337225092032\n"
".quad 0x2b38326472255b20,0x646461090a3b5d30,0x722509203436752e,0x647225202c393264\n"
".quad 0x31647225202c3531,0x732e7473090a3b31,0x33752e6465726168,0x326472255b092032\n"
".quad 0x7225202c5d302b39,0x5f744c240a3b3433,0x3a34373431345f32,0x36752e766f6d090a\n"
".quad 0x3031647225092034,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f36363837325f72,0x6769725f735f3333,0x3b34383532317468,0x36752e766f6d090a\n"
".quad 0x3131647225092034,0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c\n"
".quad 0x5f30373837325f72,0x6769725f735f3034,0x746e756f635f7468,0x090a3b3233363431\n"
".quad 0x203436752e766f6d,0x202c323164722509,0x5f5f616475635f5f,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x33335f3536383732,0x317466656c5f735f,0x6d090a3b30383636\n"
".quad 0x09203436752e766f,0x5f202c3331647225,0x5f5f5f616475635f,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30345f39363837,0x635f7466656c5f73,0x32373831746e756f\n"
".quad 0x636f6c2e090a3b38,0x0938343109323309,0x732e726162090a30,0x0a3b300920636e79\n"
".quad 0x3233752e766f6d09,0x202c353372250920,0x2e766f6d090a3b30,0x3966250920323366\n"
".quad 0x303030306630202c,0x2020203b30303030,0x0a30202f2f092020,0x3436752e766f6d09\n"
".quad 0x2c30336472250920,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f33373837325f,0x706d6f635f735f30,0x6c5f6e6f69746361,0x3233353031747369\n"
".quad 0x5f325f744c240a3b,0x200a3a3236313832,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x6f6c2e090a353531,0x3535310932330963,0x732e646c090a3009\n"
".quad 0x33732e6465726168,0x2c36337225092032,0x616475635f5f5b20,0x765f6c61636f6c5f\n"
".quad 0x30383837325f7261,0x5f6d756e5f30345f,0x5f73646165726874,0x3b5d657669746361\n"
".quad 0x6c2e70746573090a,0x2509203233752e65,0x36337225202c3570,0x090a3b317225202c\n"
".quad 0x6172622035702540,0x5f325f744c240920,0x200a3b3232353334,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353531\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3236313832,0x3509363109636f6c\n"
".quad 0x7663090a30093639,0x33752e3436752e74,0x3133647225092032,0x090a3b317225202c\n"
".quad 0x656469772e6c756d,0x722509203233752e,0x317225202c353164,0x6461090a3b34202c\n"
".quad 0x2509203436752e64,0x7225202c32336472,0x647225202c353164,0x2e646c090a3b3231\n"
".quad 0x662e646572616873,0x3031662509203233,0x32336472255b202c,0x6f6d090a3b5d302b\n"
".quad 0x2509203233662e76,0x316625202c313166,0x636f6c2e090a3b30,0x0937393509363109\n"
".quad 0x752e646461090a30,0x3364722509203436,0x3531647225202c33,0x3b3031647225202c\n"
".quad 0x6168732e646c090a,0x203233662e646572,0x5b202c3231662509,0x5d302b3333647225\n"
".quad 0x662e766f6d090a3b,0x3331662509203233,0x0a3b32316625202c,0x363109636f6c2e09\n"
".quad 0x090a300938393509,0x203436752e646461,0x202c343364722509,0x25202c3531647225\n"
".quad 0x6c090a3b33316472,0x6465726168732e64,0x722509203233752e,0x6472255b202c3733\n"
".quad 0x090a3b5d302b3433,0x203233732e766f6d,0x25202c3833722509,0x6c2e090a3b373372\n"
".quad 0x393509363109636f,0x646461090a300939,0x722509203436752e,0x647225202c353364\n"
".quad 0x31647225202c3531,0x732e646c090a3b31,0x33752e6465726168,0x2c39337225092032\n"
".quad 0x2b35336472255b20,0x766f6d090a3b5d30,0x722509203233732e,0x39337225202c3034\n"
".quad 0x2e70746573090a3b,0x203233662e75656e,0x6625202c36702509,0x32316625202c3031\n"
".quad 0x3670252140090a3b,0x4c24092061726220,0x353732345f325f74,0x6c3c2f2f200a3b34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32\n"
".quad 0x3009343036093631,0x33662e766f6d090a,0x2c34316625092032,0x3030303030663020\n"
".quad 0x202020203b303030,0x2e090a30202f2f09,0x3509363109636f6c,0x646c090a30093639\n"
".quad 0x2e6465726168732e,0x3166250920323366,0x336472255b202c30,0x2e090a3b5d302b32\n"
".quad 0x3609363109636f6c,0x6573090a30093430,0x33662e746c2e7074,0x202c377025092032\n"
".quad 0x6625202c30316625,0x766f6d090a3b3431,0x662509203233662e,0x30306630202c3531\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x3109636f6c2e090a,0x0a30093739350936\n"
".quad 0x726168732e646c09,0x09203233662e6465,0x255b202c32316625,0x3b5d302b33336472\n"
".quad 0x3109636f6c2e090a,0x0a30093430360936,0x746c2e7074657309,0x702509203233662e\n"
".quad 0x2c32316625202c38,0x090a3b3531662520,0x7262203870252140,0x325f744c24092061\n"
".quad 0x0a3b36363233345f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a32363138325f,0x09363109636f6c2e,0x6573090a30093239,0x09203233732e706c\n"
".quad 0x2c31202c31347225,0x3b377025202c3020,0x6e752e617262090a,0x325f744c24092069\n"
".quad 0x0a3b30313033345f,0x33345f325f744c24,0x2f2f200a3a363632,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x38325f325f744c24,0x6c6573090a323631,0x2509203233732e70\n"
".quad 0x202c30202c313472,0x0a3b377025202c31,0x33345f325f744c24,0x2f2f200a3a303130\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631\n"
".quad 0x3739350936310963,0x732e646c090a3009,0x33662e6465726168,0x2c32316625092032\n"
".quad 0x2b33336472255b20,0x6f6c2e090a3b5d30,0x3639350936310963,0x732e646c090a3009\n"
".quad 0x33662e6465726168,0x2c30316625092032,0x2b32336472255b20,0x6f6c2e090a3b5d30\n"
".quad 0x3430360936310963,0x2e627573090a3009,0x3166250920323366,0x2c32316625202c36\n"
".quad 0x090a3b3031662520,0x203233662e766f6d,0x30202c3731662509,0x3030303030663366\n"
".quad 0x2f09202020203b30,0x6d090a352e30202f,0x09203233662e6461,0x6625202c38316625\n"
".quad 0x37316625202c3631,0x0a3b30316625202c,0x3233662e64646109,0x202c393166250920\n"
".quad 0x6625202c30316625,0x766f6d090a3b3231,0x662509203233662e,0x66336630202c3032\n"
".quad 0x203b303030303030,0x30202f2f09202020,0x2e6c756d090a352e,0x3266250920323366\n"
".quad 0x2c39316625202c31,0x090a3b3032662520,0x203233732e67656e,0x25202c3234722509\n"
".quad 0x6c73090a3b313472,0x732e3233662e7463,0x2c39662509203233,0x25202c3132662520\n"
".quad 0x347225202c383166,0x636f6c2e090a3b32,0x0935303609363109,0x752e766f6d090a30\n"
".quad 0x3334722509203233,0x7473090a3b30202c,0x2e6465726168732e,0x5f5f5b0920323375\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f38373837,0x657268745f6c6c61\n"
".quad 0x766e6f635f736461,0x202c5d6465677265,0x62090a3b33347225,0x0920696e752e6172\n"
".quad 0x33345f325f744c24,0x744c240a3b323235,0x34353732345f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a\n"
".quad 0x0a30093939350936,0x726168732e646c09,0x09203233752e6465,0x255b202c39337225\n"
".quad 0x3b5d302b35336472,0x3109636f6c2e090a,0x0a30093839350936,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x255b202c37337225,0x3b5d302b34336472,0x3109636f6c2e090a\n"
".quad 0x0a30093530360936,0x3233752e62757309,0x202c343472250920,0x7225202c39337225\n"
".quad 0x766f6d090a3b3733,0x722509203233752e,0x090a3b31202c3534,0x2e656c2e70746573\n"
".quad 0x3970250920323375,0x202c34347225202c,0x40090a3b35347225,0x2061726220397025\n"
".quad 0x345f325f744c2409,0x2f200a3b32323533,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20\n"
".quad 0x325f325f744c2420,0x6c2e090a32363138,0x313609363109636f,0x766f6d090a300930\n"
".quad 0x722509203233752e,0x090a3b30202c3634,0x65726168732e7473,0x5b09203233752e64\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f38373837325f,0x68745f6c6c615f30\n"
".quad 0x6f635f7364616572,0x5d6465677265766e,0x0a3b36347225202c,0x33345f325f744c24\n"
".quad 0x744c240a3a323235,0x38393432345f325f,0x5f325f744c240a3a,0x200a3a3638393134\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c353531,0x656c6562616c2064,0x5f325f744c242064,0x2e090a3236313832\n"
".quad 0x3109323309636f6c,0x6162090a30093136,0x0920636e79732e72,0x636f6c2e090a3b30\n"
".quad 0x0935363109323309,0x68732e646c090a30,0x3233752e64657261,0x202c373472250920\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f38373837325f72,0x745f6c6c615f3034\n"
".quad 0x635f736461657268,0x6465677265766e6f,0x2e766f6d090a3b5d,0x3472250920323375\n"
".quad 0x73090a3b31202c38,0x752e71652e707465,0x3031702509203233,0x202c37347225202c\n"
".quad 0x40090a3b38347225,0x6172622030317025,0x5f325f744c240920,0x2f2f200a3b383532\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631\n"
".quad 0x3237310932330963,0x732e646c090a3009,0x33752e6465726168,0x2c39347225092032\n"
".quad 0x616475635f5f5b20,0x765f6c61636f6c5f,0x30383837325f7261,0x5f6d756e5f30345f\n"
".quad 0x5f73646165726874,0x3b5d657669746361,0x3109636f6c2e090a,0x0a30093833320936\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x5f5f5b202c303572,0x6d72617061647563\n"
".quad 0x73696231335a5f5f,0x656e72654b746365,0x4d5f656772614c6c,0x7265746e49746c75\n"
".quad 0x5f536650736c6176,0x5f535f30536a506a,0x5f30535f30535f53,0x6e5f665f30535f53\n"
".quad 0x2e766f6d090a3b5d,0x3572250920323373,0x3b30357225202c31,0x33752e766f6d090a\n"
".quad 0x2c32357225092032,0x746573090a3b3020,0x3233752e71652e70,0x202c313170250920\n"
".quad 0x7225202c30357225,0x702540090a3b3235,0x0920617262203131,0x38355f325f744c24\n"
".quad 0x2f2f200a3b323838,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24\n"
".quad 0x747663090a323631,0x3233752e3436752e,0x2c34316472250920,0x2e090a3b31722520\n"
".quad 0x3109323309636f6c,0x646c090a30093237,0x2e6465726168732e,0x3472250920323375\n"
".quad 0x75635f5f5b202c39,0x6c61636f6c5f6164,0x3837325f7261765f,0x756e5f30345f3038\n"
".quad 0x6461657268745f6d,0x6576697463615f73,0x636f6c2e090a3b5d,0x0938333209363109\n"
".quad 0x2e70746573090a30,0x09203233752e7467,0x7225202c32317025,0x3b317225202c3934\n"
".quad 0x69772e6c756d090a,0x09203233752e6564,0x25202c3531647225,0x090a3b34202c3172\n"
".quad 0x2e3233752e747663,0x3572250920363175,0x6469746e25202c33,0x766f6d090a3b782e\n"
".quad 0x722509203233752e,0x090a3b30202c3435,0x203233752e766f6d,0x30202c3535722509\n"
".quad 0x662e766f6d090a3b,0x3232662509203233,0x303866336630202c,0x2020203b30303030\n"
".quad 0x240a31202f2f0920,0x3534345f325f744c,0x3c2f2f200a3a3634,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x38333220656e696c,0x6e697473656e202c,0x3a68747065642067\n"
".quad 0x69747365202c3120,0x746920646574616d,0x736e6f6974617265,0x776f6e6b6e75203a\n"
".quad 0x09636f6c2e090a6e,0x3009333432093631,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x203233752e646461,0x25202c3635722509,0x317225202c343572,0x2e70746573090a3b\n"
".quad 0x09203233752e656c,0x7225202c33317025,0x36357225202c3035,0x3331702540090a3b\n"
".quad 0x4c24092061726220,0x303834345f325f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38333220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x343534345f325f74,0x09636f6c2e090a36,0x3009383432093631\n"
".quad 0x36752e747663090a,0x2509203233752e34,0x7225202c36336472,0x646461090a3b3435\n"
".quad 0x722509203436752e,0x647225202c373364,0x31647225202c3633,0x2e6c756d090a3b34\n"
".quad 0x09203436752e6f6c,0x25202c3833647225,0x3b34202c37336472,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5b202c3933647225,0x6170616475635f5f,0x6231335a5f5f6d72\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x746e49746c754d5f,0x6650736c61767265\n"
".quad 0x5f30536a506a5f53,0x535f30535f535f53,0x665f30535f535f30,0x090a3b5d645f675f\n"
".quad 0x203436752e646461,0x202c303464722509,0x25202c3933647225,0x6c090a3b38336472\n"
".quad 0x6c61626f6c672e64,0x662509203233662e,0x6472255b202c3332,0x090a3b5d302b3034\n"
".quad 0x203436752e646461,0x202c313464722509,0x25202c3531647225,0x73090a3b32316472\n"
".quad 0x6465726168732e74,0x255b09203233662e,0x2c5d302b31346472,0x090a3b3332662520\n"
".quad 0x09363109636f6c2e,0x6c090a3009393432,0x2e6d617261702e64,0x6472250920343675\n"
".quad 0x635f5f5b202c3234,0x5f6d726170616475,0x6573696231335a5f,0x6c656e72654b7463\n"
".quad 0x754d5f656772614c,0x767265746e49746c,0x6a5f536650736c61,0x535f535f30536a50\n"
".quad 0x535f30535f30535f,0x5f675f665f30535f,0x646461090a3b5d73,0x722509203436752e\n"
".quad 0x647225202c333464,0x33647225202c3234,0x672e646c090a3b38,0x33662e6c61626f6c\n"
".quad 0x2c34326625092032,0x2b33346472255b20,0x6461090a3b5d342d,0x2509203436752e64\n"
".quad 0x7225202c34346472,0x647225202c353164,0x2e7473090a3b3031,0x662e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3434,0x744c240a3b343266,0x32303834345f325f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c38333220656e,0x62616c2064616568,0x744c242064656c65,0x36343534345f325f\n"
".quad 0x3109636f6c2e090a,0x0a30093235320936,0x6e79732e72616209,0x40090a3b30092063\n"
".quad 0x7262203231702521,0x325f744c24092061,0x0a3b36323835345f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c38333220\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a36343534345f,0x203233752e6e696d\n"
".quad 0x25202c3735722509,0x357225202c313572,0x2e766f6d090a3b33,0x3572250920323375\n"
".quad 0x73090a3b30202c38,0x752e71652e707465,0x3431702509203233,0x202c37357225202c\n"
".quad 0x40090a3b38357225,0x6172622034317025,0x5f325f744c240920,0x200a3b3632383534\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383332,0x656c6562616c2064,0x5f325f744c242064,0x6d090a3634353434\n"
".quad 0x09203233732e766f,0x7225202c39357225,0x766f6d090a3b3735,0x722509203436732e\n"
".quad 0x647225202c353464,0x766f6d090a3b3231,0x722509203436732e,0x647225202c363464\n"
".quad 0x766f6d090a3b3031,0x722509203233752e,0x200a3b30202c3036,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x6d090a3634353434,0x09203233732e766f\n"
".quad 0x7225202c31367225,0x5f744c240a3b3935,0x3a38333336345f32,0x6f6f6c3c2f2f200a\n"
".quad 0x20706f6f4c203e70,0x6e696c2079646f62,0x6e202c3235322065,0x6420676e69747365\n"
".quad 0x2c32203a68747065,0x74616d6974736520,0x6172657469206465,0x75203a736e6f6974\n"
".quad 0x090a6e776f6e6b6e,0x09363109636f6c2e,0x6c090a3009303632,0x6465726168732e64\n"
".quad 0x662509203233662e,0x6472255b202c3532,0x090a3b5d302b3634,0x65726168732e646c\n"
".quad 0x2509203233662e64,0x72255b202c363266,0x0a3b5d302b353464,0x3233662e62757309\n"
".quad 0x202c373266250920,0x6625202c36326625,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x2c35326625202c38,0x090a3b3532662520,0x6c6c75662e766964,0x662509203233662e\n"
".quad 0x38326625202c3932,0x0a3b32326625202c,0x3233662e62757309,0x202c323266250920\n"
".quad 0x6625202c37326625,0x6f6c2e090a3b3932,0x3236320936310963,0x2e766f6d090a3009\n"
".quad 0x3366250920323366,0x3030306630202c30,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x2e746c2e74657309,0x203233662e323375,0x25202c3236722509,0x336625202c323266\n"
".quad 0x2e67656e090a3b30,0x3672250920323373,0x3b32367225202c33,0x33752e646461090a\n"
".quad 0x2c35357225092032,0x25202c3535722520,0x6461090a3b333672,0x2509203233752e64\n"
".quad 0x367225202c303672,0x61090a3b31202c30,0x09203436752e6464,0x25202c3634647225\n"
".quad 0x3b34202c36346472,0x36752e646461090a,0x3534647225092034,0x2c3534647225202c\n"
".quad 0x746573090a3b3420,0x3233752e656e2e70,0x202c353170250920,0x7225202c37357225\n"
".quad 0x702540090a3b3036,0x0920617262203531,0x36345f325f744c24,0x744c240a3b383333\n"
".quad 0x36323835345f325f,0x5f325f744c240a3a,0x200a3a3431333534,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c383332\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3634353434,0x3209363109636f6c\n"
".quad 0x7573090a30093736,0x2509203233752e62,0x357225202c313572,0x3b33357225202c31\n"
".quad 0x33752e646461090a,0x2c34357225092032,0x25202c3335722520,0x6573090a3b343572\n"
".quad 0x33752e746c2e7074,0x2c36317025092032,0x25202c3435722520,0x2540090a3b303572\n"
".quad 0x2061726220363170,0x345f325f744c2409,0x2f200a3b36343534,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535\n"
".quad 0x64656c6562616c20,0x325f325f744c2420,0x7262090a32363138,0x240920696e752e61\n"
".quad 0x3034345f325f744c,0x5f744c240a3b3433,0x3a32383838355f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x3436752e74766309\n"
".quad 0x722509203233752e,0x317225202c373464,0x772e6c756d090a3b,0x203233752e656469\n"
".quad 0x202c353164722509,0x0a3b34202c317225,0x3233752e74766309,0x722509203631752e\n"
".quad 0x69746e25202c3335,0x6f6d090a3b782e64,0x2509203233752e76,0x0a3b30202c353572\n"
".quad 0x34345f325f744c24,0x2f2f200a3a343330,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x38325f325f744c24,0x6f6c2e090a323631,0x3237310932330963,0x2e766f6d090a3009\n"
".quad 0x3672250920323373,0x3b35357225202c34,0x3309636f6c2e090a,0x0a30093737310932\n"
".quad 0x6e79732e72616209,0x61090a3b30092063,0x09203436752e6464,0x25202c3834647225\n"
".quad 0x7225202c35316472,0x646c090a3b303364,0x2e6465726168732e,0x3672250920323375\n"
".quad 0x75635f5f5b202c35,0x6c61636f6c5f6164,0x3837325f7261765f,0x756e5f30345f3038\n"
".quad 0x6461657268745f6d,0x6576697463615f73,0x70746573090a3b5d,0x203233752e656c2e\n"
".quad 0x25202c3731702509,0x317225202c353672,0x3731702540090a3b,0x4c24092061726220\n"
".quad 0x323232355f325f74,0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363138325f325f74,0x752e646461090a32,0x3464722509203436,0x3531647225202c39\n"
".quad 0x3b3231647225202c,0x36752e646461090a,0x3035647225092034,0x2c3531647225202c\n"
".quad 0x0a3b313164722520,0x3436752e64646109,0x2c31356472250920,0x202c353164722520\n"
".quad 0x090a3b3031647225,0x203436752e646461,0x202c323564722509,0x25202c3531647225\n"
".quad 0x6d090a3b33316472,0x09203233732e766f,0x7225202c37337225,0x766f6d090a3b3833\n"
".quad 0x662509203233662e,0x31316625202c3031,0x732e766f6d090a3b,0x3933722509203233\n"
".quad 0x0a3b30347225202c,0x3233662e766f6d09,0x202c323166250920,0x73090a3b33316625\n"
".quad 0x2e75656e2e707465,0x3170250920323366,0x2c30316625202c38,0x090a3b3231662520\n"
".quad 0x6220383170252140,0x5f744c2409206172,0x3b34373837345f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x323309636f6c2e09\n"
".quad 0x090a300934383109,0x2e656e2e70746573,0x3170250920323375,0x2c34367225202c39\n"
".quad 0x090a3b3733722520,0x203233662e736261,0x25202c3133662509,0x2e646c090a3b3966\n"
".quad 0x33662e6d61726170,0x2c32336625092032,0x616475635f5f5b20,0x335a5f5f6d726170\n"
".quad 0x4b74636573696231,0x72614c6c656e7265,0x49746c754d5f6567,0x736c61767265746e\n"
".quad 0x536a506a5f536650,0x30535f535f535f30,0x30535f535f30535f,0x69636572705f665f\n"
".quad 0x090a3b5d6e6f6973,0x3233732e706c6573,0x202c363672250920,0x7025202c30202c31\n"
".quad 0x746573090a3b3931,0x2e3233752e656e2e,0x3672250920323375,0x2c34367225202c37\n"
".quad 0x090a3b3933722520,0x203233732e67656e,0x25202c3836722509,0x6e61090a3b373672\n"
".quad 0x2509203233622e64,0x367225202c393672,0x3b38367225202c36,0x33752e766f6d090a\n"
".quad 0x2c30377225092032,0x746573090a3b3020,0x3233732e71652e70,0x202c303270250920\n"
".quad 0x7225202c39367225,0x702540090a3b3037,0x0920617262203032,0x38345f325f744c24\n"
".quad 0x2f2f200a3b363833,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24\n"
".quad 0x6f6c2e090a323631,0x3732310936310963,0x732e7473090a3009,0x33752e6465726168\n"
".quad 0x356472255b092032,0x7225202c5d302b32,0x6f6c2e090a3b3733,0x3832310936310963\n"
".quad 0x732e7473090a3009,0x33752e6465726168,0x356472255b092032,0x7225202c5d302b30\n"
".quad 0x6f6c2e090a3b3436,0x3333310936310963,0x2e627573090a3009,0x3366250920323366\n"
".quad 0x202c396625202c33,0x61090a3b30316625,0x09203233662e7362,0x6625202c34336625\n"
".quad 0x747663090a3b3333,0x3233662e3436662e,0x202c316466250920,0x61090a3b34336625\n"
".quad 0x09203233662e7362,0x6625202c35336625,0x78616d090a3b3031,0x662509203233662e\n"
".quad 0x31336625202c3633,0x0a3b35336625202c,0x323309636f6c2e09,0x090a300934383109\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x635f5f5b202c3233,0x5f6d726170616475\n"
".quad 0x6573696231335a5f,0x6c656e72654b7463,0x754d5f656772614c,0x767265746e49746c\n"
".quad 0x6a5f536650736c61,0x535f535f30536a50,0x535f30535f30535f,0x72705f665f30535f\n"
".quad 0x5d6e6f6973696365,0x09636f6c2e090a3b,0x3009333331093631,0x33662e6c756d090a\n"
".quad 0x2c37336625092032,0x25202c3233662520,0x6f6d090a3b363366,0x2509203233662e76\n"
".quad 0x306630202c383366,0x3b35323432613233,0x202f2f0920202020,0x6d090a37332d6535\n"
".quad 0x09203233662e7861,0x6625202c39336625,0x38336625202c3733,0x662e747663090a3b\n"
".quad 0x09203233662e3436,0x6625202c32646625,0x746573090a3b3933,0x3436662e656c2e70\n"
".quad 0x202c313270250920,0x6625202c31646625,0x252140090a3b3264,0x2061726220313270\n"
".quad 0x345f325f744c2409,0x2f200a3b38393838,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20\n"
".quad 0x325f325f744c2420,0x6c2e090a32363138,0x333109363109636f,0x766f6d090a300936\n"
".quad 0x662509203233662e,0x30306630202c3034,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x6c2e70746573090a,0x2509203233662e74,0x316625202c323270,0x3b30346625202c30\n"
".quad 0x72702e766f6d090a,0x2c37702509206465,0x090a3b3232702520,0x646572702e766f6d\n"
".quad 0x202c333270250920,0x6d090a3b34327025,0x09203233662e766f,0x6630202c31346625\n"
".quad 0x3030303030303030,0x2f2f09202020203b,0x70746573090a3020,0x203233662e746c2e\n"
".quad 0x25202c3532702509,0x31346625202c3966,0x3270252140090a3b,0x2409206172622035\n"
".quad 0x3439345f325f744c,0x3c2f2f200a3b3031,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138325f325f744c,0x636f6c2e090a3236,0x3009323909363109,0x732e706c6573090a\n"
".quad 0x3137722509203233,0x202c30202c31202c,0x7262090a3b377025,0x240920696e752e61\n"
".quad 0x3139345f325f744c,0x5f744c240a3b3435,0x3a30313439345f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x33732e706c657309\n"
".quad 0x2c31377225092032,0x25202c31202c3020,0x744c240a3b323270,0x34353139345f325f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c35353120656e,0x62616c2064616568,0x744c242064656c65,0x32363138325f325f\n"
".quad 0x3109636f6c2e090a,0x0a30093933310936,0x3233662e64646109,0x202c323466250920\n"
".quad 0x6625202c30316625,0x2e766f6d090a3b39,0x3466250920323366,0x3066336630202c33\n"
".quad 0x20203b3030303030,0x2e30202f2f092020,0x662e64616d090a35,0x3434662509203233\n"
".quad 0x202c33336625202c,0x6625202c33346625,0x766f6d090a3b3031,0x662509203233662e\n"
".quad 0x66336630202c3534,0x203b303030303030,0x30202f2f09202020,0x2e6c756d090a352e\n"
".quad 0x3466250920323366,0x2c32346625202c36,0x090a3b3534662520,0x203233732e67656e\n"
".quad 0x25202c3237722509,0x6c73090a3b313772,0x732e3233662e7463,0x3734662509203233\n"
".quad 0x202c36346625202c,0x7225202c34346625,0x2e7473090a3b3237,0x662e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3934,0x6c2e090a3b373466,0x343109363109636f\n"
".quad 0x2e7473090a300930,0x662e646572616873,0x6472255b09203233,0x25202c5d302b3135\n"
".quad 0x7262090a3b373466,0x240920696e752e61,0x3638345f325f744c,0x5f744c240a3b3234\n"
".quad 0x3a38393838345f32,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3535312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a32363138325f32,0x363109636f6c2e09,0x090a300935343109,0x65726168732e7473\n"
".quad 0x5b09203233662e64,0x5d302b3934647225,0x0a3b30316625202c,0x363109636f6c2e09\n"
".quad 0x090a300936343109,0x65726168732e7473,0x5b09203233662e64,0x5d302b3135647225\n"
".quad 0x240a3b396625202c,0x3638345f325f744c,0x3c2f2f200a3a3234,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236,0x0934323309363109\n"
".quad 0x752e766f6d090a30,0x3337722509203233,0x7473090a3b31202c,0x2e6465726168732e\n"
".quad 0x72255b0920323375,0x202c5d342b383464,0x2e090a3b33377225,0x3309363109636f6c\n"
".quad 0x6f6d090a30093532,0x2509203233752e76,0x0a3b31202c343772,0x726168732e747309\n"
".quad 0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34383837325f72\n"
".quad 0x61706d6f635f3034,0x6e6f6365735f7463,0x5d6b6e7568635f64,0x0a3b34377225202c\n"
".quad 0x3233752e766f6d09,0x202c353372250920,0x2e617262090a3b31,0x744c240920696e75\n"
".quad 0x36323232355f325f,0x5f325f744c240a3b,0x200a3a3638333834,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353531\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3236313832,0x3309363109636f6c\n"
".quad 0x6f6d090a30093333,0x2509203233752e76,0x0a3b30202c353772,0x726168732e747309\n"
".quad 0x09203233752e6465,0x342b38346472255b,0x3b35377225202c5d,0x393170252140090a\n"
".quad 0x4c24092061726220,0x323939345f325f74,0x6c3c2f2f200a3b32,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32,0x3009373231093631\n"
".quad 0x6168732e7473090a,0x203233752e646572,0x2b32356472255b09,0x37337225202c5d30\n"
".quad 0x09636f6c2e090a3b,0x3009383231093631,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x2b30356472255b09,0x34367225202c5d30,0x09636f6c2e090a3b,0x3009333331093631\n"
".quad 0x33662e627573090a,0x2c33336625092032,0x6625202c39662520,0x736261090a3b3031\n"
".quad 0x662509203233662e,0x33336625202c3834,0x662e747663090a3b,0x09203233662e3436\n"
".quad 0x6625202c33646625,0x736261090a3b3834,0x662509203233662e,0x30316625202c3934\n"
".quad 0x662e78616d090a3b,0x3035662509203233,0x202c31336625202c,0x2e090a3b39346625\n"
".quad 0x3109323309636f6c,0x646c090a30093438,0x662e6d617261702e,0x3233662509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x7463657369623133,0x614c6c656e72654b\n"
".quad 0x746c754d5f656772,0x6c61767265746e49,0x6a506a5f53665073,0x535f535f535f3053\n"
".quad 0x535f535f30535f30,0x636572705f665f30,0x0a3b5d6e6f697369,0x363109636f6c2e09\n"
".quad 0x090a300933333109,0x203233662e6c756d,0x25202c3135662509,0x356625202c323366\n"
".quad 0x2e766f6d090a3b30,0x3566250920323366,0x3233306630202c32,0x20203b3532343261\n"
".quad 0x6535202f2f092020,0x78616d090a37332d,0x662509203233662e,0x31356625202c3335\n"
".quad 0x0a3b32356625202c,0x3436662e74766309,0x662509203233662e,0x33356625202c3464\n"
".quad 0x2e70746573090a3b,0x09203436662e656c,0x6625202c36327025,0x34646625202c3364\n"
".quad 0x3270252140090a3b,0x2409206172622036,0x3430355f325f744c,0x3c2f2f200a3b3433\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x35353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3138325f325f744c,0x636f6c2e090a3236\n"
".quad 0x0936333109363109,0x662e766f6d090a30,0x3435662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x2e746c2e70746573,0x3270250920323366\n"
".quad 0x2c30316625202c32,0x090a3b3435662520,0x646572702e766f6d,0x25202c3770250920\n"
".quad 0x6f6d090a3b323270,0x0920646572702e76,0x7025202c37327025,0x766f6d090a3b3432\n"
".quad 0x662509203233662e,0x30306630202c3535,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x6c2e70746573090a,0x2509203233662e74,0x396625202c383270,0x0a3b35356625202c\n"
".quad 0x2038327025214009,0x744c240920617262,0x36343930355f325f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a\n"
".quad 0x090a300932390936,0x3233732e706c6573,0x202c363772250920,0x7025202c30202c31\n"
".quad 0x2e617262090a3b37,0x744c240920696e75,0x30393630355f325f,0x5f325f744c240a3b\n"
".quad 0x200a3a3634393035,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353531,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x73090a3236313832,0x203233732e706c65,0x30202c3637722509,0x327025202c31202c\n"
".quad 0x325f744c240a3b32,0x0a3a30393630355f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a32363138325f,0x09363109636f6c2e,0x61090a3009393331\n"
".quad 0x09203233662e6464,0x6625202c36356625,0x3b396625202c3031,0x33662e766f6d090a\n"
".quad 0x2c37356625092032,0x3030306633663020,0x202020203b303030,0x0a352e30202f2f09\n"
".quad 0x3233662e64616d09,0x202c383566250920,0x6625202c33336625,0x30316625202c3735\n"
".quad 0x662e766f6d090a3b,0x3935662509203233,0x303066336630202c,0x2020203b30303030\n"
".quad 0x352e30202f2f0920,0x33662e6c756d090a,0x2c30366625092032,0x25202c3635662520\n"
".quad 0x656e090a3b393566,0x2509203233732e67,0x377225202c373772,0x74636c73090a3b36\n"
".quad 0x3233732e3233662e,0x202c313666250920,0x6625202c30366625,0x37377225202c3835\n"
".quad 0x68732e7473090a3b,0x3233662e64657261,0x39346472255b0920,0x366625202c5d302b\n"
".quad 0x636f6c2e090a3b31,0x0930343109363109,0x68732e7473090a30,0x3233662e64657261\n"
".quad 0x31356472255b0920,0x366625202c5d302b,0x2e617262090a3b31,0x744c240920696e75\n"
".quad 0x32303231355f325f,0x5f325f744c240a3b,0x200a3a3433343035,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353531\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3236313832,0x3109363109636f6c\n"
".quad 0x7473090a30093534,0x2e6465726168732e,0x72255b0920323366,0x202c5d302b393464\n"
".quad 0x2e090a3b30316625,0x3109363109636f6c,0x7473090a30093634,0x2e6465726168732e\n"
".quad 0x72255b0920323366,0x202c5d302b313564,0x7262090a3b396625,0x240920696e752e61\n"
".quad 0x3231355f325f744c,0x5f744c240a3b3230,0x3a32323939345f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32,0x363109636f6c2e09\n"
".quad 0x090a300937323109,0x65726168732e7473,0x5b09203233752e64,0x5d302b3235647225\n"
".quad 0x0a3b34367225202c,0x363109636f6c2e09,0x090a300938323109,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x5d302b3035647225,0x0a3b39337225202c,0x363109636f6c2e09\n"
".quad 0x090a300933333109,0x203233662e627573,0x25202c3236662509,0x396625202c323166\n"
".quad 0x662e736261090a3b,0x3336662509203233,0x0a3b32366625202c,0x3436662e74766309\n"
".quad 0x662509203233662e,0x33366625202c3564,0x662e736261090a3b,0x3436662509203233\n"
".quad 0x0a3b32316625202c,0x3233662e78616d09,0x202c353666250920,0x6625202c31336625\n"
".quad 0x6f6c2e090a3b3436,0x3438310932330963,0x702e646c090a3009,0x3233662e6d617261\n"
".quad 0x202c323366250920,0x70616475635f5f5b,0x31335a5f5f6d7261,0x654b746365736962\n"
".quad 0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366\n"
".quad 0x5f30535f535f535f,0x5f30535f535f3053,0x7369636572705f66,0x2e090a3b5d6e6f69\n"
".quad 0x3109363109636f6c,0x756d090a30093333,0x2509203233662e6c,0x336625202c363666\n"
".quad 0x3b35366625202c32,0x33662e766f6d090a,0x2c37366625092032,0x3261323330663020\n"
".quad 0x202020203b353234,0x332d6535202f2f09,0x662e78616d090a37,0x3836662509203233\n"
".quad 0x202c36366625202c,0x63090a3b37366625,0x662e3436662e7476,0x3664662509203233\n"
".quad 0x0a3b38366625202c,0x656c2e7074657309,0x702509203436662e,0x35646625202c3932\n"
".quad 0x0a3b36646625202c,0x2039327025214009,0x744c240920617262,0x38353431355f325f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c35353120656e,0x62616c2064616568,0x744c242064656c65,0x32363138325f325f\n"
".quad 0x3109636f6c2e090a,0x0a30093633310936,0x3233662e766f6d09,0x202c393666250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6573090a30202f2f,0x33662e746c2e7074\n"
".quad 0x2c30337025092032,0x6625202c39662520,0x766f6d090a3b3936,0x250920646572702e\n"
".quad 0x337025202c313370,0x2e766f6d090a3b30,0x7025092064657270,0x33337025202c3233\n"
".quad 0x662e766f6d090a3b,0x3037662509203233,0x303030306630202c,0x2020203b30303030\n"
".quad 0x090a30202f2f0920,0x2e746c2e70746573,0x3370250920323366,0x2c32316625202c34\n"
".quad 0x090a3b3037662520,0x6220343370252140,0x5f744c2409206172,0x3b30373931355f32\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3535312065,0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32\n"
".quad 0x363109636f6c2e09,0x73090a3009323909,0x203233732e706c65,0x31202c3837722509\n"
".quad 0x337025202c30202c,0x2e617262090a3b31,0x744c240920696e75,0x34313731355f325f\n"
".quad 0x5f325f744c240a3b,0x200a3a3037393135,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353531,0x656c6562616c2064\n"
".quad 0x5f325f744c242064,0x73090a3236313832,0x203233732e706c65,0x30202c3837722509\n"
".quad 0x337025202c31202c,0x325f744c240a3b30,0x0a3a34313731355f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f,0x09363109636f6c2e\n"
".quad 0x61090a3009393331,0x09203233662e6464,0x6625202c31376625,0x3b396625202c3231\n"
".quad 0x33662e766f6d090a,0x2c32376625092032,0x3030306633663020,0x202020203b303030\n"
".quad 0x0a352e30202f2f09,0x3233662e64616d09,0x202c333766250920,0x6625202c32366625\n"
".quad 0x3b396625202c3237,0x33662e766f6d090a,0x2c34376625092032,0x3030306633663020\n"
".quad 0x202020203b303030,0x0a352e30202f2f09,0x3233662e6c756d09,0x202c353766250920\n"
".quad 0x6625202c31376625,0x67656e090a3b3437,0x722509203233732e,0x38377225202c3937\n"
".quad 0x2e74636c73090a3b,0x203233732e323366,0x25202c3637662509,0x376625202c353766\n"
".quad 0x3b39377225202c33,0x6168732e7473090a,0x203233662e646572,0x2b39346472255b09\n"
".quad 0x36376625202c5d30,0x09636f6c2e090a3b,0x3009303431093631,0x6168732e7473090a\n"
".quad 0x203233662e646572,0x2b31356472255b09,0x36376625202c5d30,0x752e617262090a3b\n"
".quad 0x5f744c240920696e,0x3b32303231355f32,0x355f325f744c240a,0x2f200a3a38353431\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138\n"
".quad 0x343109363109636f,0x2e7473090a300935,0x662e646572616873,0x6472255b09203233\n"
".quad 0x25202c5d302b3934,0x6f6c2e090a3b3966,0x3634310936310963,0x732e7473090a3009\n"
".quad 0x33662e6465726168,0x356472255b092032,0x6625202c5d302b31,0x5f744c240a3b3231\n"
".quad 0x3a32303231355f32,0x345f325f744c240a,0x2f200a3a36363639,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535\n"
".quad 0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138,0x343309363109636f\n"
".quad 0x766f6d090a300931,0x722509203233752e,0x090a3b30202c3533,0x20696e752e617262\n"
".quad 0x355f325f744c2409,0x4c240a3b36323232,0x373837345f325f74,0x6c3c2f2f200a3a34\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35353120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x363138325f325f74,0x09636f6c2e090a32\n"
".quad 0x3009343931093233,0x33752e627573090a,0x2c30387225092032,0x25202c3933722520\n"
".quad 0x6f6d090a3b373372,0x2509203233752e76,0x0a3b31202c313872,0x656e2e7074657309\n"
".quad 0x702509203233752e,0x30387225202c3533,0x0a3b31387225202c,0x6220353370254009\n"
".quad 0x5f744c2409206172,0x3b32383432355f32,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3535312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363138325f32,0x363109636f6c2e09,0x090a300936333509\n"
".quad 0x65726168732e7473,0x5b09203233662e64,0x5d302b3934647225,0x0a3b30316625202c\n"
".quad 0x363109636f6c2e09,0x090a300937333509,0x65726168732e7473,0x5b09203233662e64\n"
".quad 0x5d302b3135647225,0x0a3b32316625202c,0x363109636f6c2e09,0x090a300938333509\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x5d302b3235647225,0x0a3b37337225202c\n"
".quad 0x363109636f6c2e09,0x090a300939333509,0x65726168732e7473,0x5b09203233752e64\n"
".quad 0x5d302b3035647225,0x0a3b39337225202c,0x363109636f6c2e09,0x090a300933343509\n"
".quad 0x203233752e766f6d,0x30202c3238722509,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x38346472255b0920,0x387225202c5d342b,0x2e766f6d090a3b32,0x3372250920323375\n"
".quad 0x62090a3b30202c35,0x0920696e752e6172,0x32355f325f744c24,0x744c240a3b363232\n"
".quad 0x32383432355f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x32363138325f325f,0x3109636f6c2e090a,0x0a30093834350936,0x3233752e72687309\n"
".quad 0x202c333872250920,0x3b31202c30387225,0x33752e646461090a,0x2c34387225092032\n"
".quad 0x25202c3338722520,0x6f6d090a3b373372,0x2509203233732e76,0x387225202c343672\n"
".quad 0x636f6c2e090a3b34,0x0931353509363109,0x68732e7473090a30,0x3233662e64657261\n"
".quad 0x39346472255b0920,0x316625202c5d302b,0x636f6c2e090a3b30,0x0932353509363109\n"
".quad 0x68732e7473090a30,0x3233662e64657261,0x31356472255b0920,0x316625202c5d302b\n"
".quad 0x636f6c2e090a3b32,0x0933353509363109,0x68732e7473090a30,0x3233752e64657261\n"
".quad 0x32356472255b0920,0x337225202c5d302b,0x636f6c2e090a3b37,0x0934353509363109\n"
".quad 0x68732e7473090a30,0x3233752e64657261,0x30356472255b0920,0x387225202c5d302b\n"
".quad 0x636f6c2e090a3b34,0x0936353509363109,0x662e766f6d090a30,0x2c39662509203233\n"
".quad 0x090a3b3031662520,0x09363109636f6c2e,0x6d090a3009303635,0x09203233752e766f\n"
".quad 0x3b31202c35387225,0x6168732e7473090a,0x203233752e646572,0x2b38346472255b09\n"
".quad 0x35387225202c5d34,0x09636f6c2e090a3b,0x3009313635093631,0x33752e766f6d090a\n"
".quad 0x2c36387225092032,0x2e7473090a3b3120,0x752e646572616873,0x635f5f5b09203233\n"
".quad 0x61636f6c5f616475,0x37325f7261765f6c,0x635f30345f343838,0x735f746361706d6f\n"
".quad 0x68635f646e6f6365,0x7225202c5d6b6e75,0x766f6d090a3b3638,0x722509203233752e\n"
".quad 0x240a3b31202c3533,0x3232355f325f744c,0x5f744c240a3a3632,0x3a38313637345f32\n"
".quad 0x345f325f744c240a,0x2f200a3a36303137,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3535,0x64656c6562616c20\n"
".quad 0x325f325f744c2420,0x6c2e090a32363138,0x303209323309636f,0x726162090a300934\n"
".quad 0x300920636e79732e,0x68732e646c090a3b,0x3233752e64657261,0x202c373872250920\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34383837325f72,0x61706d6f635f3034\n"
".quad 0x6e6f6365735f7463,0x5d6b6e7568635f64,0x752e766f6d090a3b,0x3838722509203233\n"
".quad 0x6573090a3b31202c,0x33752e656e2e7074,0x2c36337025092032,0x25202c3738722520\n"
".quad 0x2540090a3b383872,0x2061726220363370,0x355f325f744c2409,0x2f200a3b32323336\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3535,0x64656c6562616c20,0x325f325f744c2420,0x6c2e090a32363138\n"
".quad 0x313209323309636f,0x2e646c090a300930,0x752e646572616873,0x3938722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x383837325f726176,0x6d756e5f30345f32\n"
".quad 0x736461657268745f,0x746361706d6f635f,0x2e090a3b5d6e6f69,0x3309363109636f6c\n"
".quad 0x6873090a30093736,0x2509203233752e72,0x387225202c303972,0x6d090a3b31202c39\n"
".quad 0x09203233732e766f,0x7225202c31397225,0x766f6d090a3b3039,0x722509203233752e\n"
".quad 0x090a3b30202c3239,0x2e656c2e70746573,0x3370250920323373,0x2c30397225202c37\n"
".quad 0x090a3b3239722520,0x7262203733702540,0x325f744c24092061,0x0a3b34393339355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c35353120,0x6c6562616c206461,0x325f744c24206465,0x090a32363138325f\n"
".quad 0x203233752e766f6d,0x31202c3339722509,0x5f325f744c240a3b,0x200a3a3236373335\n"
".quad 0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964,0x6f6c2e090a393633\n"
".quad 0x3936330936310963,0x2e726162090a3009,0x3b300920636e7973,0x6c2e70746573090a\n"
".quad 0x2509203233752e65,0x397225202c383370,0x0a3b317225202c31,0x6220383370254009\n"
".quad 0x5f744c2409206172,0x3b38313034355f32,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3936332065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a32363733355f32,0x363109636f6c2e09,0x090a300939373309\n"
".quad 0x6f6c2e34326c756d,0x722509203233752e,0x2c317225202c3439,0x646461090a3b3220\n"
".quad 0x722509203233752e,0x34397225202c3539,0x6461090a3b31202c,0x2509203233752e64\n"
".quad 0x397225202c363972,0x6d090a3b32202c34,0x33752e6f6c2e6c75,0x2c37397225092032\n"
".quad 0x25202c3539722520,0x756d090a3b333972,0x3233752e6f6c2e6c,0x202c383972250920\n"
".quad 0x7225202c36397225,0x766f6d090a3b3339,0x722509203233752e,0x090a3b30202c3939\n"
".quad 0x2e656e2e70746573,0x3370250920323375,0x2c38397225202c39,0x090a3b3939722520\n"
".quad 0x203233752e627573,0x202c303031722509,0x3b31202c38397225,0x33752e766f6d090a\n"
".quad 0x3130317225092032,0x6573090a3b30202c,0x09203233752e706c,0x25202c3230317225\n"
".quad 0x7225202c30303172,0x337025202c313031,0x2e747663090a3b39,0x203233752e343675\n"
".quad 0x202c333564722509,0x090a3b3230317225,0x656469772e6c756d,0x722509203233752e\n"
".quad 0x317225202c343564,0x090a3b34202c3230,0x203436752e646461,0x202c353564722509\n"
".quad 0x25202c3033647225,0x6c090a3b34356472,0x6465726168732e64,0x722509203233752e\n"
".quad 0x72255b202c333031,0x0a3b5d342b353564,0x3233752e62757309,0x2c34303172250920\n"
".quad 0x31202c3739722520,0x752e766f6d090a3b,0x3031722509203233,0x6d090a3b30202c35\n"
".quad 0x09203233752e766f,0x30202c3630317225,0x2e70746573090a3b,0x09203233752e656e\n"
".quad 0x7225202c30347025,0x30317225202c3739,0x706c6573090a3b36,0x722509203233752e\n"
".quad 0x317225202c373031,0x30317225202c3430,0x3b30347025202c35,0x36752e747663090a\n"
".quad 0x2509203233752e34,0x7225202c36356472,0x756d090a3b373031,0x752e656469772e6c\n"
".quad 0x3564722509203233,0x3730317225202c37,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x7225202c38356472,0x647225202c303364,0x2e646c090a3b3735,0x752e646572616873\n"
".quad 0x3031722509203233,0x356472255b202c38,0x61090a3b5d342b38,0x09203233752e6464\n"
".quad 0x25202c3930317225,0x7225202c33303172,0x7473090a3b383031,0x2e6465726168732e\n"
".quad 0x72255b0920323375,0x202c5d342b353564,0x240a3b3930317225,0x3034355f325f744c\n"
".quad 0x3c2f2f200a3a3831,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x39363320656e696c,0x6c2064616568202c,0x242064656c656261,0x3733355f325f744c\n"
".quad 0x636f6c2e090a3236,0x0933383309363109,0x622e6c6873090a30,0x3339722509203233\n"
".quad 0x202c33397225202c,0x636f6c2e090a3b31,0x0937363309363109,0x732e726873090a30\n"
".quad 0x3139722509203233,0x202c31397225202c,0x2e766f6d090a3b31,0x3172250920323375\n"
".quad 0x090a3b30202c3031,0x2e74672e70746573,0x3470250920323373,0x2c31397225202c31\n"
".quad 0x0a3b303131722520,0x6220313470254009,0x5f744c2409206172,0x3b32363733355f32\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3535312065,0x6562616c20646165,0x5f744c242064656c,0x0a32363138325f32\n"
".quad 0x696e752e61726209,0x5f325f744c240920,0x240a3b3035323335,0x3339355f325f744c\n"
".quad 0x3c2f2f200a3a3439,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x35353120656e696c,0x6c2064616568202c,0x242064656c656261,0x3138325f325f744c\n"
".quad 0x2e766f6d090a3236,0x3972250920323375,0x4c240a3b31202c33,0x353233355f325f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562,0x363138325f325f74\n"
".quad 0x752e766f6d090a32,0x3131722509203233,0x73090a3b32202c31,0x752e656c2e707465\n"
".quad 0x3234702509203233,0x202c39387225202c,0x090a3b3131317225,0x7262203234702540\n"
".quad 0x325f744c24092061,0x0a3b36383734355f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a32363138325f,0x203233732e766f6d,0x202c323131722509\n"
".quad 0x325f744c240a3b32,0x0a3a38393235355f,0x706f6f6c3c2f2f20,0x6220706f6f4c203e\n"
".quad 0x656e696c2079646f,0x656e202c37363320,0x656420676e697473,0x202c31203a687470\n"
".quad 0x6574616d69747365,0x7461726574692064,0x6e75203a736e6f69,0x2e090a6e776f6e6b\n"
".quad 0x3309363109636f6c,0x6873090a30093938,0x2509203233752e72,0x397225202c333972\n"
".quad 0x2e090a3b31202c33,0x3309363109636f6c,0x6162090a30093039,0x0920636e79732e72\n"
".quad 0x2e627573090a3b30,0x3172250920323375,0x31317225202c3331,0x73090a3b31202c32\n"
".quad 0x752e65672e707465,0x3334702509203233,0x25202c317225202c,0x40090a3b33313172\n"
".quad 0x6172622033347025,0x5f325f744c240920,0x200a3b3435353535,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c373633\n"
".quad 0x656c6562616c2064,0x5f325f744c242064,0x2e090a3839323535,0x3309363109636f6c\n"
".quad 0x6873090a30093739,0x2509203233752e72,0x7225202c34313172,0x090a3b31202c3339\n"
".quad 0x203233752e646461,0x202c353131722509,0x0a3b31202c317225,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323375,0x31317225202c3631,0x3b33397225202c35,0x33752e646461090a\n"
".quad 0x3731317225092032,0x2c3431317225202c,0x0a3b363131722520,0x3436752e74766309\n"
".quad 0x722509203233752e,0x317225202c393564,0x6c756d090a3b3731,0x33752e656469772e\n"
".quad 0x3036647225092032,0x2c3731317225202c,0x646461090a3b3420,0x722509203436752e\n"
".quad 0x647225202c313664,0x36647225202c3033,0x732e646c090a3b30,0x33752e6465726168\n"
".quad 0x3831317225092032,0x31366472255b202c,0x7663090a3b5d302b,0x33752e3436752e74\n"
".quad 0x3236647225092032,0x3b3631317225202c,0x69772e6c756d090a,0x09203233752e6564\n"
".quad 0x25202c3336647225,0x3b34202c36313172,0x36752e646461090a,0x3436647225092034\n"
".quad 0x2c3033647225202c,0x0a3b333664722520,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5b202c3931317225,0x5d302b3436647225,0x752e646461090a3b,0x3231722509203233\n"
".quad 0x3831317225202c30,0x3b3931317225202c,0x6168732e7473090a,0x203233752e646572\n"
".quad 0x2b31366472255b09,0x32317225202c5d30,0x325f744c240a3b30,0x0a3a34353535355f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c37363320,0x6c6562616c206461,0x325f744c24206465,0x090a38393235355f\n"
".quad 0x09363109636f6c2e,0x73090a3009373833,0x09203233622e6c68,0x25202c3231317225\n"
".quad 0x3b31202c32313172,0x6c2e70746573090a,0x2509203233752e74,0x317225202c343470\n"
".quad 0x39387225202c3231,0x3434702540090a3b,0x4c24092061726220,0x393235355f325f74\n"
".quad 0x325f744c240a3b38,0x0a3a36383734355f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a32363138325f,0x09363109636f6c2e,0x62090a3009323034\n"
".quad 0x20636e79732e7261,0x6f6c2e090a3b3009,0x3231320932330963,0x732e646c090a3009\n"
".quad 0x33752e6465726168,0x3132317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61\n"
".quad 0x383837325f726176,0x6d756e5f30345f30,0x736461657268745f,0x5d6576697463615f\n"
".quad 0x752e766f6d090a3b,0x3231722509203233,0x73090a3b31202c32,0x33752e71652e7465\n"
".quad 0x2509203233752e32,0x7225202c33323172,0x32317225202c3533,0x2e67656e090a3b32\n"
".quad 0x3172250920323373,0x32317225202c3432,0x2e746573090a3b33,0x752e3233752e7467\n"
".quad 0x3231722509203233,0x3132317225202c35,0x090a3b317225202c,0x203233732e67656e\n"
".quad 0x202c363231722509,0x090a3b3532317225,0x203233622e646e61,0x202c373231722509\n"
".quad 0x25202c3432317225,0x6d090a3b36323172,0x09203233752e766f,0x30202c3832317225\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x7225202c35347025,0x317225202c373231\n"
".quad 0x702540090a3b3832,0x0920617262203534,0x36355f325f744c24,0x2f2f200a3b323233\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24,0x6f6c2e090a323631\n"
".quad 0x3034340936310963,0x732e646c090a3009,0x33752e6465726168,0x3932317225092032\n"
".quad 0x38346472255b202c,0x6c2e090a3b5d302b,0x313209323309636f,0x2e646c090a300932\n"
".quad 0x752e646572616873,0x3231722509203233,0x75635f5f5b202c31,0x6c61636f6c5f6164\n"
".quad 0x3837325f7261765f,0x756e5f30345f3038,0x6461657268745f6d,0x6576697463615f73\n"
".quad 0x636f6c2e090a3b5d,0x0930343409363109,0x752e646461090a30,0x3331722509203233\n"
".quad 0x3932317225202c30,0x3b3132317225202c,0x3109636f6c2e090a,0x0a30093234340936\n"
".quad 0x3436752e74766309,0x722509203233752e,0x317225202c353664,0x6c756d090a3b3033\n"
".quad 0x33752e656469772e,0x3636647225092032,0x2c3033317225202c,0x646461090a3b3420\n"
".quad 0x722509203436752e,0x647225202c373664,0x31647225202c3636,0x732e7473090a3b32\n"
".quad 0x33662e6465726168,0x366472255b092032,0x6625202c5d302b37,0x636f6c2e090a3b39\n"
".quad 0x0933343409363109,0x662e766f6d090a30,0x3737662509203233,0x0a3b33316625202c\n"
".quad 0x3436752e64646109,0x2c38366472250920,0x202c363664722520,0x090a3b3031647225\n"
".quad 0x65726168732e7473,0x5b09203233662e64,0x5d302b3836647225,0x0a3b37376625202c\n"
".quad 0x363109636f6c2e09,0x090a300934343409,0x203436752e646461,0x202c393664722509\n"
".quad 0x25202c3636647225,0x73090a3b33316472,0x6465726168732e74,0x255b09203233752e\n"
".quad 0x2c5d302b39366472,0x090a3b3436722520,0x09363109636f6c2e,0x6d090a3009353434\n"
".quad 0x09203233732e766f,0x25202c3133317225,0x6461090a3b303472,0x2509203436752e64\n"
".quad 0x7225202c30376472,0x647225202c363664,0x2e7473090a3b3131,0x752e646572616873\n"
".quad 0x6472255b09203233,0x25202c5d302b3037,0x4c240a3b31333172,0x323336355f325f74\n"
".quad 0x325f744c240a3a32,0x0a3a38333732355f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35353120,0x6c6562616c206461\n"
".quad 0x325f744c24206465,0x090a32363138325f,0x09323309636f6c2e,0x62090a3009383132\n"
".quad 0x20636e79732e7261,0x252140090a3b3009,0x0920617262203170,0x36355f325f744c24\n"
".quad 0x2f2f200a3b343338,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c,0x38325f325f744c24\n"
".quad 0x6f6c2e090a323631,0x3232320932330963,0x732e646c090a3009,0x33752e6465726168\n"
".quad 0x3233317225092032,0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x383837325f726176\n"
".quad 0x6d756e5f30345f30,0x736461657268745f,0x5d6576697463615f,0x752e747663090a3b\n"
".quad 0x09203233752e3436,0x25202c3137647225,0x6d090a3b32333172,0x2e656469772e6c75\n"
".quad 0x6472250920323375,0x33317225202c3237,0x61090a3b34202c32,0x09203436752e6464\n"
".quad 0x25202c3337647225,0x7225202c30336472,0x646c090a3b323764,0x2e6465726168732e\n"
".quad 0x3172250920323375,0x6472255b202c3333,0x090a3b5d302b3337,0x203233752e646461\n"
".quad 0x202c313231722509,0x25202c3333317225,0x73090a3b32333172,0x6465726168732e74\n"
".quad 0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30345f3038383732\n"
".quad 0x7268745f6d756e5f,0x7463615f73646165,0x7225202c5d657669,0x6c2e090a3b313231\n"
".quad 0x323209323309636f,0x627573090a300933,0x722509203233732e,0x317225202c343331\n"
".quad 0x090a3b31202c3132,0x203233622e646e61,0x202c353331722509,0x25202c3132317225\n"
".quad 0x6d090a3b34333172,0x09203233752e766f,0x30202c3633317225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c36347025,0x317225202c353331,0x702540090a3b3633\n"
".quad 0x0920617262203634,0x37355f325f744c24,0x2f2f200a3b363433,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35\n"
".quad 0x2064656c6562616c,0x38325f325f744c24,0x766f6d090a323631,0x722509203233732e\n"
".quad 0x317225202c373331,0x617262090a3b3132,0x4c240920696e752e,0x665f69646e655744\n"
".quad 0x32325f6670786572,0x744c240a3b325f36,0x36343337355f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a\n"
".quad 0x0a30093538320939,0x2e6e722e74766309,0x203233732e323366,0x25202c3837662509\n"
".quad 0x6d090a3b31323172,0x09203233662e766f,0x376625202c326625,0x2e736261090a3b38\n"
".quad 0x3766250920323366,0x3b38376625202c39,0x33662e766f6d090a,0x2c30386625092032\n"
".quad 0x3030383030663020,0x202020203b303030,0x37312e31202f2f09,0x0a38332d65393435\n"
".quad 0x746c2e7074657309,0x702509203233662e,0x39376625202c3734,0x0a3b30386625202c\n"
".quad 0x2037347025214009,0x744c240920617262,0x34313138355f325f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3209636f6c2e090a\n"
".quad 0x3009393533320931,0x33662e766f6d090a,0x2c31386625092032,0x3030386234663020\n"
".quad 0x202020203b303030,0x37362e31202f2f09,0x0a37302b65323737,0x3233662e6c756d09\n"
".quad 0x25202c3266250920,0x386625202c383766,0x2e766f6d090a3b31,0x3172250920323375\n"
".quad 0x090a3b3432202c33,0x20696e752e617262,0x355f325f744c2409,0x4c240a3b38353837\n"
".quad 0x313138355f325f74,0x6c3c2f2f200a3a34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c35353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x363138325f325f74,0x09636f6c2e090a32,0x0932363332093132,0x752e766f6d090a30\n"
".quad 0x3331722509203233,0x744c240a3b30202c,0x38353837355f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c35353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x32363138325f325f,0x3109636f6c2e090a\n"
".quad 0x090a300937370936,0x203233622e766f6d,0x202c383331722509,0x6873090a3b326625\n"
".quad 0x2509203233732e72,0x7225202c39333172,0x3b3332202c383331,0x33622e646e61090a\n"
".quad 0x3034317225092032,0x2c3933317225202c,0x6d090a3b35353220,0x09203233752e766f\n"
".quad 0x30202c3134317225,0x752e627573090a3b,0x3431722509203233,0x3034317225202c32\n"
".quad 0x0a3b33317225202c,0x3233752e62757309,0x2c33343172250920,0x202c323431722520\n"
".quad 0x6f6d090a3b363231,0x2509203233752e76,0x3532202c34343172,0x2e746573090a3b35\n"
".quad 0x752e3233752e7165,0x3431722509203233,0x3034317225202c35,0x3b3434317225202c\n"
".quad 0x33732e67656e090a,0x3634317225092032,0x3b3534317225202c,0x33662e766f6d090a\n"
".quad 0x2c32386625092032,0x3030303030663020,0x202020203b303030,0x73090a30202f2f09\n"
".quad 0x33752e71652e7465,0x2509203233662e32,0x6625202c37343172,0x32386625202c3937\n"
".quad 0x732e67656e090a3b,0x3431722509203233,0x3734317225202c38,0x33622e726f090a3b\n"
".quad 0x3934317225092032,0x2c3634317225202c,0x0a3b383431722520,0x3233732e67656e09\n"
".quad 0x2c30353172250920,0x0a3b393431722520,0x33752e74636c7309,0x2509203233732e32\n"
".quad 0x7225202c31353172,0x317225202c333431,0x35317225202c3134,0x2e6c6873090a3b30\n"
".quad 0x3172250920323362,0x25202c31202c3733,0x4c240a3b31353172,0x665f69646e655744\n"
".quad 0x32325f6670786572,0x2f2f200a3a325f36,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c35,0x2064656c6562616c\n"
".quad 0x38325f325f744c24,0x6f6c2e090a323631,0x3332320932330963,0x732e7473090a3009\n"
".quad 0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164,0x3837325f7261765f\n"
".quad 0x756e5f30345f3238,0x6461657268745f6d,0x6361706d6f635f73,0x25202c5d6e6f6974\n"
".quad 0x2e090a3b37333172,0x3209323309636f6c,0x6f6d090a30093532,0x2509203233752e76\n"
".quad 0x3b30202c32353172,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x34383837325f7261,0x706d6f635f30345f,0x6f6365735f746361\n"
".quad 0x6b6e7568635f646e,0x3235317225202c5d,0x09636f6c2e090a3b,0x3009363232093233\n"
".quad 0x33752e766f6d090a,0x3335317225092032,0x7473090a3b31202c,0x2e6465726168732e\n"
".quad 0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f38373837\n"
".quad 0x657268745f6c6c61,0x766e6f635f736461,0x202c5d6465677265,0x240a3b3335317225\n"
".quad 0x3836355f325f744c,0x3c2f2f200a3a3433,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35353120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3138325f325f744c,0x636f6c2e090a3236,0x0939323209323309,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x323309636f6c2e09,0x090a300932333209,0x203233752e766f6d\n"
".quad 0x202c343531722509,0x732e7473090a3b30,0x33752e6465726168,0x346472255b092032\n"
".quad 0x7225202c5d342b38,0x6c2e090a3b343531,0x333209323309636f,0x766f6d090a300933\n"
".quad 0x722509203233752e,0x0a3b30202c353531,0x3233752e64646109,0x2c36353172250920\n"
".quad 0x25202c3335722520,0x747663090a3b3172,0x3233752e3436752e,0x2c34376472250920\n"
".quad 0x0a3b363531722520,0x6469772e6c756d09,0x2509203233752e65,0x7225202c35376472\n"
".quad 0x0a3b34202c363531,0x3436752e64646109,0x2c36376472250920,0x202c303364722520\n"
".quad 0x090a3b3537647225,0x65726168732e7473,0x5b09203233752e64,0x5d342b3637647225\n"
".quad 0x3b3535317225202c,0x3309636f6c2e090a,0x0a30093533320932,0x6e79732e72616209\n"
".quad 0x2e090a3b30092063,0x3209323309636f6c,0x7262090a30093932,0x240920696e752e61\n"
".quad 0x3138325f325f744c,0x5f744c240a3b3236,0x090a3a3835325f32,0x09323309636f6c2e\n"
".quad 0x6c090a3009373332,0x6465726168732e64,0x722509203233752e,0x5f5f5b202c373531\n"
".quad 0x636f6c5f61647563,0x325f7261765f6c61,0x5f30345f30383837,0x657268745f6d756e\n"
".quad 0x697463615f736461,0x6573090a3b5d6576,0x33752e656c2e7074,0x2c38347025092032\n"
".quad 0x202c373531722520,0x2540090a3b317225,0x2061726220383470,0x355f325f744c2409\n"
".quad 0x2e090a3b30373338,0x3209323309636f6c,0x7663090a30093434,0x33752e3436752e74\n"
".quad 0x3431647225092032,0x090a3b317225202c,0x656469772e6c756d,0x722509203233752e\n"
".quad 0x317225202c353164,0x646c090a3b34202c,0x2e6465726168732e,0x3172250920323375\n"
".quad 0x635f5f5b202c3835,0x61636f6c5f616475,0x37325f7261765f6c,0x635f30345f393838\n"
".quad 0x6f5f6b636f6c625f,0x756f5f7465736666,0x090a3b5d74757074,0x203233752e646461\n"
".quad 0x202c393531722509,0x25202c3835317225,0x747663090a3b3172,0x3233752e3436752e\n"
".quad 0x2c37376472250920,0x0a3b393531722520,0x6469772e6c756d09,0x2509203233752e65\n"
".quad 0x7225202c38376472,0x0a3b34202c393531,0x3436752e64646109,0x2c39376472250920\n"
".quad 0x202c353164722520,0x090a3b3231647225,0x65726168732e646c,0x2509203233662e64\n"
".quad 0x72255b202c333866,0x0a3b5d302b393764,0x617261702e646c09,0x2509203436752e6d\n"
".quad 0x5f5b202c30386472,0x726170616475635f,0x696231335a5f5f6d,0x6e72654b74636573\n"
".quad 0x5f656772614c6c65,0x65746e49746c754d,0x536650736c617672,0x535f30536a506a5f\n"
".quad 0x30535f30535f535f,0x5f665f30535f535f,0x6164626d616c5f67,0x2e646461090a3b5d\n"
".quad 0x6472250920343675,0x38647225202c3138,0x3837647225202c30,0x6c672e7473090a3b\n"
".quad 0x3233662e6c61626f,0x31386472255b0920,0x386625202c5d302b,0x636f6c2e090a3b33\n"
".quad 0x0935343209323309,0x752e646461090a30,0x3864722509203436,0x3531647225202c32\n"
".quad 0x3b3131647225202c,0x6168732e646c090a,0x203233752e646572,0x202c303631722509\n"
".quad 0x302b32386472255b,0x702e646c090a3b5d,0x3436752e6d617261,0x2c33386472250920\n"
".quad 0x616475635f5f5b20,0x335a5f5f6d726170,0x4b74636573696231,0x72614c6c656e7265\n"
".quad 0x49746c754d5f6567,0x736c61767265746e,0x536a506a5f536650,0x30535f535f535f30\n"
".quad 0x30535f535f30535f,0x736f705f675f665f,0x2e646461090a3b5d,0x6472250920343675\n"
".quad 0x38647225202c3438,0x3837647225202c33,0x6c672e7473090a3b,0x3233752e6c61626f\n"
".quad 0x34386472255b0920,0x317225202c5d302b,0x5f744c240a3b3036,0x3a30373338355f32\n"
".quad 0x3309636f6c2e090a,0x0a30093734320932,0x240a3b7469786509,0x5f5f646e6557444c\n"
".quad 0x636573696231335a,0x4c6c656e72654b74,0x6c754d5f65677261,0x61767265746e4974\n"
".quad 0x506a5f536650736c,0x5f535f535f30536a,0x5f535f30535f3053,0x7d090a3a665f3053\n"
".quad 0x31335a5f202f2f20,0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65\n"
".quad 0x50736c6176726574,0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053\n"
".quad 0x00000000000a0a66\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_10$[11185];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_10$:\n"
".quad 0x33010102464c457f,0x0000000000000002,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000003be4,0x0000000000000040,0x00380040000a000a,0x0001001000400007\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000440\n"
".quad 0x0000000000000356,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000796\n"
".quad 0x00000000000000ab,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000000841\n"
".quad 0x00000000000001f8,0x0000001200000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000130,0x0000000000100006,0x0000000000000000,0x0000000000000a39\n"
".quad 0x0000000000001e38,0x1800000a00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001fe,0x0000000000000002,0x0000000000000000,0x0000000000002871\n"
".quad 0x000000000000003c,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000172,0x0000000000000002,0x0000000000000000,0x00000000000028ad\n"
".quad 0x000000000000005c,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000001b7,0x0000000000000003,0x0000000000000000,0x0000000000002909\n"
".quad 0x00000000000020bc,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000c1,0x0000000000100006,0x0000000000000000,0x0000000000002909\n"
".quad 0x0000000000000470,0x1200000800000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000283,0x0000000000000002,0x0000000000000000,0x0000000000002d79\n"
".quad 0x0000000000000010,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000f7,0x0000000000000002,0x0000000000000000,0x0000000000002d89\n"
".quad 0x0000000000000030,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000248,0x0000000000000003,0x0000000000000000,0x0000000000002db9\n"
".quad 0x0000000000000848,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000100006,0x0000000000000000,0x0000000000002db9\n"
".quad 0x0000000000000dc0,0x1000000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000030a,0x0000000000000002,0x0000000000000000,0x0000000000003b79\n"
".quad 0x0000000000000028,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000007a,0x0000000000000002,0x0000000000000000,0x0000000000003ba1\n"
".quad 0x0000000000000040,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000002c1,0x0000000000000003,0x0000000000000000,0x0000000000003be1\n"
".quad 0x000000000000288c,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x31335a5f2e747865\n"
".quad 0x654b746365736962,0x6772614c6c656e72,0x6e49746c754d5f65,0x50736c6176726574\n"
".quad 0x30536a506a5f5366,0x5f30535f535f535f,0x5f30535f535f3053,0x6e692e766e2e0066\n"
".quad 0x6231335a5f2e6f66,0x72654b7463657369,0x656772614c6c656e,0x746e49746c754d5f\n"
".quad 0x6650736c61767265,0x5f30536a506a5f53,0x535f30535f535f53,0x665f30535f535f30\n"
".quad 0x5f2e747865742e00,0x636573696230335a,0x4c6c656e72654b74,0x656e4f5f65677261\n"
".quad 0x6c61767265746e49,0x536a6a5f53665073,0x2e00666a505f535f,0x2e6f666e692e766e\n"
".quad 0x6573696230335a5f,0x6c656e72654b7463,0x6e4f5f656772614c,0x61767265746e4965\n"
".quad 0x6a6a5f536650736c,0x00666a505f535f53,0x5a5f2e747865742e,0x7463657369623731\n"
".quad 0x614c6c656e72654b,0x6a5f536650656772,0x536a50666a6a6666,0x30535f535f535f30\n"
".quad 0x5f30535f535f535f,0x30535f30535f3053,0x6e692e766e2e005f,0x6237315a5f2e6f66\n"
".quad 0x72654b7463657369,0x656772614c6c656e,0x6a66666a5f536650,0x535f30536a50666a\n"
".quad 0x5f535f30535f535f,0x5f30535f30535f53,0x2e005f30535f3053,0x65726168732e766e\n"
".quad 0x696237315a5f2e64,0x6e72654b74636573,0x50656772614c6c65,0x6a6a66666a5f5366\n"
".quad 0x5f535f30536a5066,0x535f535f30535f53,0x535f30535f30535f,0x6e2e005f30535f30\n"
".quad 0x6174736e6f632e76,0x37315a5f2e31746e,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x66666a5f53665065,0x5f30536a50666a6a,0x535f30535f535f53,0x30535f30535f535f\n"
".quad 0x005f30535f30535f,0x726168732e766e2e,0x6230335a5f2e6465,0x72654b7463657369\n"
".quad 0x656772614c6c656e,0x65746e49656e4f5f,0x536650736c617672,0x505f535f536a6a5f\n"
".quad 0x632e766e2e00666a,0x31746e6174736e6f,0x73696230335a5f2e,0x656e72654b746365\n"
".quad 0x4f5f656772614c6c,0x767265746e49656e,0x6a5f536650736c61,0x666a505f535f536a\n"
".quad 0x6168732e766e2e00,0x31335a5f2e646572,0x654b746365736962,0x6772614c6c656e72\n"
".quad 0x6e49746c754d5f65,0x50736c6176726574,0x30536a506a5f5366,0x5f30535f535f535f\n"
".quad 0x5f30535f535f3053,0x6f632e766e2e0066,0x2e31746e6174736e,0x6573696231335a5f\n"
".quad 0x6c656e72654b7463,0x754d5f656772614c,0x767265746e49746c,0x6a5f536650736c61\n"
".quad 0x535f535f30536a50,0x535f30535f30535f,0x5f0000665f30535f,0x636573696231335a\n"
".quad 0x4c6c656e72654b74,0x6c754d5f65677261,0x61767265746e4974,0x506a5f536650736c\n"
".quad 0x5f535f535f30536a,0x5f535f30535f3053,0x335a5f00665f3053,0x4b74636573696230\n"
".quad 0x72614c6c656e7265,0x6e49656e4f5f6567,0x50736c6176726574,0x535f536a6a5f5366\n"
".quad 0x315a5f00666a505f,0x4b74636573696237,0x72614c6c656e7265,0x666a5f5366506567\n"
".quad 0x30536a50666a6a66,0x5f30535f535f535f,0x535f30535f535f53,0x5f30535f30535f30\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0100030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0200030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0300030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000030000000000,0x0000000000000000,0x0000000000000000,0x0000030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0c00030000000000,0x0000000000000000\n"
".quad 0x00000000000dc000,0x0e00030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0800030000000000,0x0000000000000000,0x0000000000047000,0x0a00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0400030000000000,0x0000000000000000\n"
".quad 0x00000000001e3800,0x0600030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0700030000000000,0x0000000000000000,0x0000000000000000,0x0500030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0b00030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0900030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0f00030000000000,0x0000000000000000,0x0000000000000000,0x0d00030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0c10120000000100,0x0000000000000000\n"
".quad 0x0000000000000000,0x0810120000003f00,0x0000000000000000,0x0000000000000000\n"
".quad 0x0410120000006f00,0x0000000000000000,0x0000000000000000,0x000780a000000100\n"
".quad 0x0000031000001904,0x0007800002000900,0x00078000010005c0,0x018780040c9601c0\n"
".quad 0x3f078008004801e0,0x3f078008084c01e4,0x01878004089401e4,0x000067200b8045e0\n"
".quad 0x01878004189c0100,0x00000320248011e0,0x0000432026800d00,0x000047200a804100\n"
".quad 0x0000c7200e803d00,0x0007800002081100,0x0007800002060dc0,0x03c7801000f821c0\n"
".quad 0x03c7801000f81d04,0x1007803002003104,0x000000861ffe03c4,0x0087d0307c000d00\n"
".quad 0x0147c8a00007fd64,0x000000a00250030c,0x0011001002500300,0x23c7801000d20d00\n"
".quad 0x20c7800000480104,0x23c7801000d40de4,0x20c78000084c0104,0x23c7801000d60de4\n"
".quad 0x0187800008940104,0x23c7801000d80de0,0x01878000189c0104,0x0000031001800de0\n"
".quad 0x3f07800010500100,0x20c78000105201e4,0x20c78000105401e4,0x20c78000105601e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x200780a000424d00,0x03c7801000f85104\n"
".quad 0x03c7801000f80d04,0x03c7801000f81104,0x03c7801000f81504,0x000780d041480504\n"
".quad 0x20c7d83400c1fd20,0x000000a005400364,0x0012801005400300,0x23c7841000c01100\n"
".quad 0x2347d8bc04c1fd04,0x23c7841000c01560,0x23c7801c00c01104,0x0007800001200504\n"
".quad 0x200780a4004021c0,0x00078000011e0504,0x200780a400401dc0,0x0011001004d00304\n"
".quad 0x2047e8bc7cc1fd00,0x000000a004200360,0x2047dcb07cc1fd00,0x0021001004000360\n"
".quad 0x03c7801000f81900,0x40d2801000001904,0x0007801004200324,0x0000031001801900\n"
".quad 0x03d2801000f81900,0x23c7861000c00d04,0x23c7841000c01104,0x20c780bc00c00d04\n"
".quad 0x23c7841000c01508,0x0147d8a0000dfd04,0x410780e081060d2c,0x0560181d00e01000\n"
".quad 0x23c7841000c015bd,0x401e00c0810c0d04,0x3f07800010560100,0x00078010054003e4\n"
".quad 0x00078000011e0500,0x200780a400401dc0,0x0007800001200504,0x200780a4004021c0\n"
".quad 0x02078020400e1904,0x40c7d830800dfd04,0x3f15000010560164,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x000780d041580500,0x6087d83480c1fd20,0x0012801018700364\n"
".quad 0x2087d8307cd1fd00,0x23c7801000d01964,0x0012801008c00304,0x000780d041480500\n"
".quad 0x2107d83400c1fd20,0x03c7801000f84964,0xf800031000802904,0x03c7801000f82503\n"
".quad 0x000000861ffe0304,0x0007802000242d00,0x20c7e8300bd1fd04,0x000000a006e00364\n"
".quad 0x0022801006e00300,0x0007802000242d00,0x1007803002162d04,0x0be82c210bec58c4\n"
".quad 0xc00780d00e165521,0xffffff203cac2d80,0xc00780d00e162d0f,0x2547840000000180\n"
".quad 0x22c7800c000001e4,0x000002f0000001e4,0x000000861ffe03e0,0x000000a008700300\n"
".quad 0x0011001008700300,0x0007e030130c5500,0x00210010087003a4,0x00010b1018802d00\n"
".quad 0x00000b1010805900,0x0007800000160500,0x00078000002c09c0,0x03c7801000f859c0\n"
".quad 0x23c7801400c02d04,0x5107e8b08215fd04,0x0b602cb943605c60,0x402680c08a162dc5\n"
".quad 0x402680c08a142900,0x0007809000142900,0x05c780e00a162900,0x0000032001ac5904\n"
".quad 0x004780b07c142d00,0x0147e830162bfd60,0x02c7802040122564,0x000780d400080504\n"
".quad 0x000780d800080920,0x0022801007900320,0x0487822000264900,0x2107e83012d1fd04\n"
".quad 0x04c78020400c1964,0x0022801006100304,0x0007801008d00300,0x03c7801000f82500\n"
".quad 0x000000861ffe0304,0x000780d041480500,0x20c7d83400c1fd20,0x000000a011000364\n"
".quad 0x0012801011000300,0x0347d8b00509fd00,0x000780a0001c2d60,0x000780a000201904\n"
".quad 0x0011001010900304,0x000780a000242900,0x0147d0300a0c4904,0x014780300b145164\n"
".quad 0x400780d080245564,0x014780a000284904,0x0007e8d0122bfd2c,0x104780a000064904\n"
".quad 0x002100100c5003c4,0x100780b0120a2d00,0x45062cc10b7a4880,0x400780b0832451b0\n"
".quad 0x104780a000164980,0x004780a0002851c4,0x00078000012005c4,0x03078004000001c0\n"
".quad 0x00c7d8b01425fde0,0x00078000011e0560,0x05078004000001c0,0x000000a00bd003e0\n"
".quad 0x001100100bb00300,0x0047e0b07c0a1900,0x0047f8b07c07fd60,0x000000a00b400360\n"
".quad 0x0147d8a0000dfd00,0x003100100b20030c,0x03c7801000f81900,0x40e2801000001904\n"
".quad 0x000780100b400324,0x0000031001801900,0x03d2801000f81900,0x014782b000062904\n"
".quad 0x0147d8a0000dfd00,0xf00003c00014192c,0x415980e081161903,0x2187840000000100\n"
".quad 0x2187800c000001e4,0x000780100bd003e4,0x2147840000000100,0x20c7800c000001e4\n"
".quad 0x000002f0000001e4,0x00000310010031e0,0x0007800001220500,0x03078004000201c0\n"
".quad 0x00000310018019e0,0x2187800010500100,0x00000310018051e4,0x0007801011000300\n"
".quad 0x000003100000a100,0x0007800001220500,0x0a078004000201c0,0x000000a0107003e0\n"
".quad 0x001100100e900300,0x100780b0120a2d00,0x45062cc10b7a4880,0x400780b0832451b0\n"
".quad 0x104780a000164980,0x004780a0002851c4,0x00078000012005c4,0x03078004000001c0\n"
".quad 0x00c7d8b01425fde0,0x00078000011e0560,0x05078004000001c0,0x001100100e6003e0\n"
".quad 0x0047e0b07c0a1900,0x0047f8b07c07fd60,0x000000a00df00360,0x0147d8a0000dfd00\n"
".quad 0x003100100dd0030c,0x03c7801000f81900,0x40e2801000001904,0x000780100df00324\n"
".quad 0x0000031001801900,0x03d2801000f81900,0x014782b000062904,0x0147d8a0000dfd00\n"
".quad 0xf00003c00014192c,0x415980e081161903,0x2187840000000100,0x2187800c000001e4\n"
".quad 0x00078010107003e4,0x2147840000000100,0x20c7800c000001e4,0x00078010107003e4\n"
".quad 0x100780b012081900,0x430818c1067a4880,0x400780b0832451b0,0x104780a0000c4980\n"
".quad 0x004780a0002851c4,0x00078000012005c4,0x05078004000001c0,0x00c7d8b01425fde0\n"
".quad 0x00078000011e0560,0x05878004000001c0,0x00110010105003e0,0x0047e0b07c062900\n"
".quad 0x0047f8b07c09fd60,0x000000a00fe00360,0x0147d8a00015fd00,0x003100100fc0030c\n"
".quad 0x03c7801000f82900,0x40e2801000002904,0x000780100fe00324,0x0000031001802900\n"
".quad 0x03d2801000f82900,0x010782b000062d04,0x0147d8a00015fd00,0xf00003c00016292c\n"
".quad 0x40d980e0810c2903,0x2287840000000100,0x2287800c000001e4,0x00078010107003e4\n"
".quad 0x20c7840000000100,0x2107800c000001e4,0x03c7821000f851e4,0x0007801011000304\n"
".quad 0x2147840000000100,0x2147800c000001e4,0x00078000012005e4,0x03078004000001c0\n"
".quad 0x00078000011e05e0,0x05878004000001c0,0x03c7801000f851e0,0x000002f000000104\n"
".quad 0x000000861ffe03e0,0x000780d041400500,0x2087d8347cc1fd20,0x0012801016300364\n"
".quad 0x000780d041500500,0x3007803401c05520,0x23c7801400c049e4,0x00c7d8307c2bfd04\n"
".quad 0x0012801013a0036c,0x0000031001802900,0x000000861ffe0300,0x00c7d830002bfd00\n"
".quad 0x000000a013500364,0x0012801013500300,0x1007803001002d00,0x00000320029619c4\n"
".quad 0x0000032001962d00,0x0007804015185900,0x05878060141a5900,0x00078040162a5d00\n"
".quad 0x05c7806017285d00,0x10078030102e5d00,0x05c7e06016282dc4,0x10078030102c5900\n"
".quad 0xffffff203f962dc4,0x0587d0601418190f,0x03e5001000f82d00,0xffffff203f8c1904\n"
".quad 0x000780000116050f,0x03d5001000f819c0,0x000780d419300904,0x00078000010c0520\n"
".quad 0x23c78018004031c0,0x000780d419300900,0x2307802800403120,0x030780040c980100\n"
".quad 0x10078230012a55e0,0x0107d8307c2bfdec,0x100780300114296c,0x0012801011b003c4\n"
".quad 0x0007801013b00300,0x0000031001802900,0x40c7d8308425fd00,0x0012801015200364\n"
".quad 0x0000031002802d00,0x1007803001142900,0x000000861ffe03e4,0xffffff203f961900\n"
".quad 0x0187d8300601fd0f,0x000000a014f00364,0x0012801014f00300,0x0000032001801900\n"
".quad 0x0107804006141900,0x1007803001145500,0x00078000010c05e4,0x01878020002a19c0\n"
".quad 0x000780d4192c0904,0x00078000010c0520,0x23c78018004031c0,0x000780d4192c0900\n"
".quad 0x2307802800403120,0x030780040c960100,0x1007823001162de0,0x0047d8301217fdc4\n"
".quad 0x0012801013e00364,0x000000861ffe0300,0x4087d8308029fd00,0x000780d041480564\n"
".quad 0x2112d83400c1fd20,0x000000a016200364,0x0011001016200300,0x000780d041480900\n"
".quad 0x0007800001220520,0x200780a4004019c0,0x2187802800c01904,0x00078000020c0504\n"
".quad 0x20c78004004801c0,0x21078004084c01e4,0x00078000010c05e4,0x04878004089401c0\n"
".quad 0x03878004189c01e0,0x000002f0000001e0,0x000000861ffe03e0,0x000000a018200300\n"
".quad 0x0001001018200300,0x000780d041480500,0x2007800401c00920,0x000780d8192c09c0\n"
".quad 0x200780a800401920,0x2187802400c01904,0xffffff203f8c2504,0x0007d8d0090dfd0f\n"
".quad 0x2187800010520104,0x0015001017e003e4,0x014780a0000c1900,0x5047d8b0850dfd44\n"
".quad 0x104780a0000c2560,0x401680c08b0c19c4,0x40d6801000182900,0x03d1001000f82924\n"
".quad 0x10078030170c1904,0x400780d0860c19ec,0x4087d830860dfd04,0x02878020400c1964\n"
".quad 0x009158b07c13fd04,0xfffffb20028c1960,0x000003100180250f,0x03d6801000f81900\n"
".quad 0x0007803006121904,0x21878000105401c4,0x00000310018019e4,0x3f07800010500100\n"
".quad 0x21878000105601e4,0x000002f0000001e4,0x000000861ffe03e0,0x000780d041500500\n"
".quad 0x2107d83413c1fd20,0x0015001002c00364,0x000000861ffe0300,0x0007802000260d00\n"
".quad 0x000780d041480504,0x20c7d83403c1fd20,0x0007800001200564,0x200780a400402dc0\n"
".quad 0x00078000011e0504,0x200780a4004029c0,0x0015000001060504,0x001500d4112805c0\n"
".quad 0x201500a400403520,0x0015000001060504,0x001500d4313805c0,0x201500a400403920\n"
".quad 0x4046801000342104,0x0206800008940120,0x02068000189c01e0,0x000000861ffe03e0\n"
".quad 0x02c7802040141100,0x4087d03080081504,0x400780d0800a1564,0x4147803080081904\n"
".quad 0x014780a0000a2964,0x400780d0800c1d08,0x0007800001200504,0x02878004000201c0\n"
".quad 0x014780a0000e29e0,0x000780d006081108,0x00078000011e0504,0x02878004000201c0\n"
".quad 0x00078000012205e0,0x02078004000201c0,0x00000310000021e0,0x0007800001000500\n"
".quad 0x020780041c9e01c0,0x000780d0414805e0,0x20c7e83403c1fd20,0x0007800001060564\n"
".quad 0x000780d4393c05c0,0x0007800400002120,0x000000a01cb00340,0x0007800001000500\n"
".quad 0x000780d4393c05c0,0x0007800400002520,0x002280101c400340,0x03478020401c1100\n"
".quad 0x4087803080081504,0x400780d0800a4964,0x4147803080081904,0x014780a000242964\n"
".quad 0x400780d0800c1d08,0x0007800001060504,0x02878004089601c0,0x014780a0000e29e0\n"
".quad 0x000780d006081108,0x02878004189e0104,0x020780040c9801e0,0x00000310000021e0\n"
".quad 0x0007800000100500,0x02078004000001c0,0x000780101cb003e0,0x4107e8308707fd00\n"
".quad 0x4065001000342164,0x0025000001060520,0x022500040c9801c0,0x00250000001005e0\n"
".quad 0x02250004000001c0,0x03c7801000f849e0,0x000782d041500504,0x3007803401c04d20\n"
".quad 0x23c7801400c011e4,0x00c7e8307c27fd04,0x0022801023a0036c,0x0000031001801900\n"
".quad 0x000000861ffe0300,0x00c7e8300027fd00,0x000000a023500364,0x0022801023500300\n"
".quad 0x1007803001005500,0x0000032001aa15c4,0x000780400a1a1d00,0x01c780600b181d00\n"
".quad 0x10078030100e1d00,0x01c780600a1851c4,0x0007800001280900,0x000780d8112805c0\n"
".quad 0x23c7801400403920,0x0000032002aa1500,0x000780400d145500,0x054780600c165500\n"
".quad 0x10078030102a5500,0x054780600c1455c4,0x00078000012a0500,0x000780d4112809c0\n"
".quad 0x0007800800001520,0x2387802800402940,0x0287800408940100,0x00078000012809e0\n"
".quad 0x000780d8313809c0,0x0007800800001520,0x23c7801800402940,0x000780d431380900\n"
".quad 0x0007800800001d20,0x2287802800402940,0x02878004189c0100,0x00078000012809e0\n"
".quad 0x000780d8393809c0,0x0007800800001520,0x200780a800401540,0x0000e7200fa81d04\n"
".quad 0x0000e7200faa5500,0x4147e830800bfd00,0x002280101ff00364,0x00078000012a0900\n"
".quad 0x00078008000015c0,0xffffff203e8a1540,0x00078000000a090f,0x200780a8004015c0\n"
".quad 0x4087e830800bfd04,0x0022801023500364,0x00078000010e0900,0x00078008000015c0\n"
".quad 0xffffff203e8a1540,0x00078000000a090f,0x200780a8004015c0,0x4147e830800bfd04\n"
".quad 0x0022801020d00364,0x00078000012a0900,0x00078008000015c0,0xffffff203e8a1540\n"
".quad 0x00078000000a050f,0x00000310010029c0,0x0287800400000100,0x00078010235003e0\n"
".quad 0x00078000012a0900,0x00078008000015c0,0xffffff203e8a1540,0x00078000000a090f\n"
".quad 0x200780a8004015c0,0x4147e830800bfd04,0x0022801021b00364,0x00078000010e0900\n"
".quad 0x00078008000015c0,0xffffff203e8a1540,0x00078000000a050f,0x00000310010029c0\n"
".quad 0x0287800400000100,0x00078010235003e0,0x0007800001280900,0x000780d8192c09c0\n"
".quad 0x0007800800001520,0x200780a800401540,0x000780d4192c0904,0x0007800800005920\n"
".quad 0x200780a800405940,0x05878020000a1504,0x40c7e830880bfd04,0x0022801023100364\n"
".quad 0x00078000010e0900,0x00078008000015c0,0x00078000012a0940,0x0007800800001dc0\n"
".quad 0xffffff203e8a1540,0x00078000000a050f,0x00000310010029c0,0x0287800400000100\n"
".quad 0xffffff203e8e1de0,0x00078000000e050f,0x02878004000001c0,0x00078010235003e0\n"
".quad 0x028780040c960100,0x00000310000029e0,0x0007800001280900,0x028780080c9601c0\n"
".quad 0x1007823001264de0,0x0107e8307c27fdec,0x10078030010c196c,0x002280101d1003c4\n"
".quad 0x0007801023b00300,0x0000031001801900,0x40c7e8308409fd00,0x0022801025800364\n"
".quad 0x0000031002801d00,0x10078030010c1900,0x000000861ffe03e4,0xffffff203f8e1500\n"
".quad 0x0187e8300501fd0f,0x000000a025500364,0x0022801025500300,0x0000032001801500\n"
".quad 0x01078040050c4d00,0x10078030010c1500,0x04c78020000a15e4,0x0007800001260904\n"
".quad 0x000780d8112809c0,0x00078000010a0520,0x23c78018004029c0,0x000780d411280900\n"
".quad 0x2287802800402920,0x0287800408940100,0x00078000012609e0,0x000780d8313809c0\n"
".quad 0x23c7801800402920,0x000780d431380900,0x2287802800402920,0x02878004189c0100\n"
".quad 0x10078230010e1de0,0x0047e830040ffdc4,0x0022801023e00364,0x000780d041480500\n"
".quad 0x3007803401c24d20,0x00c7e8307c27fde4,0x23c7801400c2116c,0x2007800401c00504\n"
".quad 0x00078004000019c0,0x0022801027500340,0x0000031001801d00,0x000000861ffe0300\n"
".quad 0x00c7e8300027fd00,0x000000a027000364,0x0022801027000300,0x1007803001001500\n"
".quad 0x00000320018a51c4,0x01078040140e5100,0x00000320028a1500,0x0007800001280500\n"
".quad 0x01078040070a15c0,0x000780d4192c0900,0x00078000010a0520,0x23c78018004029c0\n"
".quad 0x000780d4192c0900,0x2287802800402920,0x028780040c960100,0x1007823001264de0\n"
".quad 0x0107e8307c27fdec,0x10078030010e1d6c,0x00228010260003c4,0x0007801027600300\n"
".quad 0x0000031001801d00,0xffffff203f884d00,0x40c7e8308427fd0f,0x0022801028e00364\n"
".quad 0x0000031002805100,0x10078030010e1d00,0x000000861ffe03e4,0xffffff203fa81500\n"
".quad 0x0187e8300501fd0f,0x000000a028b00364,0x0022801028b00300,0x0000032001801500\n"
".quad 0x01078040050e1500,0x10078030010e5500,0x00078000010a05e4,0x01478020002a15c0\n"
".quad 0x000780d4192c0904,0x00078000010a0520,0x23c78018004029c0,0x000780d4192c0900\n"
".quad 0x2287802800402920,0x028780040c960100,0x10078230012851e0,0x0047e8301329fdc4\n"
".quad 0x0022801027a00364,0x000000861ffe0300,0x000000a029a00300,0x0001001029a00300\n"
".quad 0x0007800001080900,0x000780d8393805c0,0x23c7801400402120,0x00078000000c0500\n"
".quad 0x020780041c9c01c0,0x000780d8192c05e0,0x23c7801400402120,0x00078000000c0500\n"
".quad 0x020780040c9601c0,0x000002f0000001e0,0x000000861ffe03e0,0x0007800000120500\n"
".quad 0x200780a4004011c0,0x4147e8308009fd04,0x00250000011e0564,0x202500a4004215c0\n"
".quad 0x0025000001220504,0x23e50014004221c0,0x40250021000a5100,0x4062801000342104\n"
".quad 0x03e2801000f85120,0x0007800000100504,0x200780a4004015c0,0x4147e830800bfd04\n"
".quad 0x000000a02b500364,0x002280102b300300,0x0007800001060500,0x000780d4313c05c0\n"
".quad 0x200780a400401520,0x0007800001060504,0x000780d4193005c0,0x23c7801400402520\n"
".quad 0x00000320018a4d00,0x000780102b500300,0x0000031000002500,0x03c7801000f84d00\n"
".quad 0x000782d041500504,0x20c7e83403c1fd20,0x0007800000120564,0x23c78014004029c0\n"
".quad 0x0007800001220500,0x02878004000201c0,0x00250000001005e0,0x23e50014004029c0\n"
".quad 0x0025000001060500,0x02a500040c9801c0,0x000780d0415005e0,0x3007803401c05520\n"
".quad 0x23c7801400c015e4,0x00c7e8307c2bfd04,0x002280102da0036c,0x0000031001801d00\n"
".quad 0x000000861ffe0300,0x00c7e830002bfd00,0x000000a02d500364,0x002280102d500300\n"
".quad 0x1007803001001900,0x00000320018c59c4,0x01078040160e5900,0x00000320028c1900\n"
".quad 0x00078000012c0500,0x01078040070c19c0,0x000780d4192c0900,0x00078000010c0520\n"
".quad 0x23c78018004031c0,0x000780d4192c0900,0x2307802800403120,0x030780040c960100\n"
".quad 0x10078230012a55e0,0x0107e8307c2bfdec,0x10078030010e1d6c,0x002280102c5003c4\n"
".quad 0x000780102db00300,0x0000031001801d00,0x40c7e830840bfd00,0x002280102f200364\n"
".quad 0x0000031002805500,0x10078030010e1d00,0x000000861ffe03e4,0xffffff203faa1900\n"
".quad 0x0187e8300601fd0f,0x000000a02ef00364,0x002280102ef00300,0x0000032001801900\n"
".quad 0x01078040060e1900,0x10078030010e5900,0x00078000010c05e4,0x01878020002c19c0\n"
".quad 0x000780d4192c0904,0x00078000010c0520,0x23c78018004031c0,0x000780d4192c0900\n"
".quad 0x2307802800403120,0x030780040c960100,0x10078230012a55e0,0x0047e830052bfdc4\n"
".quad 0x002280102de00364,0x000000861ffe0300,0x000000a030400300,0x0001001030400300\n"
".quad 0x000780d041480500,0x2007800401c00520,0x000780d4192c09c0,0x200780a800401920\n"
".quad 0x000780d411280904,0x2187800010580120,0x200780a800401de4,0x000780d431380504\n"
".quad 0x21c78000105a0120,0x200780a4004055e4,0x23c7801000dc1504,0xc00780d00e0a1d04\n"
".quad 0x23c7801000e015a0,0x25478000105c0104,0xc00780d00e0a19e4,0x000002f0000001a0\n"
".quad 0x000000861ffe03e0,0x000780d041480500,0x2107f03403c01d20,0x23c7841000c01564\n"
".quad 0x23c7801c00c01904,0x0147e8a0000ffd04,0x003680000206050c,0x003680d4012009c0\n"
".quad 0x23f6801800c00520,0x003680d421300504,0x23f6801400c00920,0x000000a031900304\n"
".quad 0x0011001031500300,0x0007800001200500,0x200780a4004059c0,0x0007801031900304\n"
".quad 0x000780d041680900,0x00078000011e0520,0x200780a400401dc0,0x21c7802800c05904\n"
".quad 0x0147f2307c281d04,0x0147d8a0000ffd64,0x003680000122050c,0x203680a400401dc0\n"
".quad 0x00368000010e0504,0x00368004000055c0,0x0031000001f80540,0x00310004000055c0\n"
".quad 0x000000a033a00340,0x0021001033800300,0x000000a032f00300,0x4147f8308025fd00\n"
".quad 0x0032801032a00364,0x0007800001060500,0x000780d4112805c0,0x200780a400401d20\n"
".quad 0x0007801032f00304,0x0007800001060500,0x000780d4313805c0,0x200780a400401d20\n"
".quad 0x000780d041680504,0x21c7802400c01d20,0x0087fa307c27fd04,0x0032801033600364\n"
".quad 0x0007800001060500,0x000780d4192c05c0,0x200780a400404920,0x0007800001240904\n"
".quad 0x0007801033a003c0,0x0007800001f80900,0x0007801033a003c0,0x0007800001f80900\n"
".quad 0x03c7801000f81dc0,0x000002f000000104,0x000000861ffe03e0,0x00078000022c0500\n"
".quad 0x00078004000049c0,0x2147800400480140,0x21878004084c01e4,0x400780d0891619e4\n"
".quad 0x00078000012c0504,0x00078004000015c0,0x400780d089141540,0x0307800408940104\n"
".quad 0x02878004189c01e0,0x43968021002815e0,0x00168000002a0504,0x029680040c9801c0\n"
".quad 0x021680041ca001e0,0x000000a0358003e0,0x0021001035800300,0x00078000020e0500\n"
".quad 0x20478004004801c0,0x20878004084c01e4,0x400780d0891a05e4,0x00078000010e0504\n"
".quad 0x400780d0891c09c0,0x0087800408940104,0x01078004189c01e0,0x0087d8307c27fde0\n"
".quad 0x4395002100260564,0x009500080c980104,0x025500081ca001e0,0x000002f0000001e0\n"
".quad 0x000000861ffe03e0,0x000000a036200300,0x0001001036200300,0x000780d041600500\n"
".quad 0x23c7801400c40520,0x2007800401c00504,0x008780040c9601c0,0x00000310000009e0\n"
".quad 0x008780001c9e0100,0x000002f0000001e0,0x000000861ffe03e0,0x000780d041680500\n"
".quad 0x20c7c83400c1fd20,0x000000a038400364,0x0002801037300300,0x23c7841000c00500\n"
".quad 0x23c7801c00c00904,0x00078000011e0504,0x200780a4004015c0,0x2307802000e41104\n"
".quad 0xc00780d00e080504,0x2307802000e805a0,0xc00780d00e020904,0x2307802000ec05a0\n"
".quad 0xc00780d00e021504,0x00078010384003a0,0x000780d041680500,0x2007803400c00920\n"
".quad 0x23c7841000c00504,0x1007803002040904,0x2087802000f011c4,0xc00780d00e080504\n"
".quad 0x23c7801c00c005a0,0x2087802000f41104,0xc00780d00e080504,0x00078000012005a0\n"
".quad 0x200780a4004011c0,0x2087802000f80504,0xc00780d00e021104,0x00078000011e05a0\n"
".quad 0x200780a4004011c0,0x2087802000fc0504,0xc00780d00e021104,0x000782d0414805a0\n"
".quad 0x20c7c83403c1fd20,0x000000a03ab00364,0x000280103ab00300,0x000780d041680500\n"
".quad 0x20c7c83403c1fd20,0x0000032024860964,0x0000432026860500,0x0007800002040d00\n"
".quad 0x00078000020209c0,0x00078000010605c0,0x000780d4313811c0,0x1007803002061120\n"
".quad 0x0002801039b003c4,0x00e0081d00e00400,0x200784a000401919,0x2107802000e41504\n"
".quad 0xc00780d00e0a0504,0x2107802000e805a0,0xc00780d00e020904,0x2107802000ec05a0\n"
".quad 0xc00780d00e021904,0x000780103ab003a0,0x000780d041680500,0x00e0043503e00820\n"
".quad 0x100780300204091d,0x2087802000f011c4,0xc00780d00e080504,0x23c7801800c005a0\n"
".quad 0x2087802000f41104,0x0007800001060504,0x000780d4112805c0,0xc00780d00e080520\n"
".quad 0x200780a4004011a0,0x2087802000f80504,0xc00780d00e021104,0x200784a0004011a0\n"
".quad 0x2087802000fc0504,0xc00780d00e021104,0x000002f0000001a0,0x000780d0416005e0\n"
".quad 0x2047c83400c1fd20,0x000000a03b900364,0x000280103b900300,0x0007800001220500\n"
".quad 0x200780a4004005c0,0x000780d001000504,0x2307802400c00120,0xc00780d00e000504\n"
".quad 0x00078000001209a0,0x200780a8004005c0,0x2307802400c40104,0xc00780d00e000504\n"
".quad 0x000782d0416005a0,0x2047c83403c1fd20,0x0002803000000364,0x000780d001000500\n"
".quad 0x0007800001060920,0x000780d8192c09c0,0x1007803002060120,0x200780a8004009c4\n"
".quad 0x2007802400c00504,0xc00780d00e020904,0x00078000001009a0,0x200780a8004005c0\n"
".quad 0x2007802400c40104,0xc00781d00e000504,0x00000000000001a0,0x2a24257e8000003f\n"
".quad 0x8000000000000203,0x000200000000ff00,0x00ffff0000010000,0x8000003e80000000\n"
".quad 0x000000000000184b,0x4c0b04ffffffff00,0x0000080000000000,0x0000140000001000\n"
".quad 0x00001c0000001800,0x0000240000002000,0x0000300000002800,0x0000400000003800\n"
".quad 0x0000500000004800,0x0000600000005800,0x0000700000006800,0x080d040000007800\n"
".quad 0x0000200021010800,0x03c7801000000900,0x200780a000421504,0x000780a000081904\n"
".quad 0x028c1c410a2c0804,0x2107d03007d20920,0x0147c8a00005fd64,0x000000a000f0030c\n"
".quad 0x0011001000f00300,0x10078030020e0900,0x2087802000d401c4,0xc00780d00e000104\n"
".quad 0x2087802000d80580,0xc00780d00e020504,0x2087802000dc0980,0xc00780d00e042104\n"
".quad 0x0147da307c0dfd80,0x3f15000004220164,0x000000861ffe03e4,0x03c7801000f82500\n"
".quad 0x2107d8307cd1fd04,0x03c7801000f80964,0x03c7801000f82904,0x40c2801000002504\n"
".quad 0x008780307c140d24,0x400780d080061164,0x0000031001800d04,0x0007e0d009082d00\n"
".quad 0x20c7800004220104,0x000000a002c003e4,0x0021001002c00300,0x000000a002700300\n"
".quad 0x0047f8b07c03fd00,0x0047e8b07c01fd60,0x0031001002500360,0x03c7801000f80900\n"
".quad 0x40e2801000000904,0x0007801002700324,0x0000031001800900,0x03e2801000f80900\n"
".quad 0x000782b000021104,0x0147e8a00005fd00,0x000780b000020d2c,0xf00003c000080908\n"
".quad 0x402980e081060903,0x23c7821000d00d00,0x0011001005f00304,0x000000a005d00300\n"
".quad 0x03c7801000f83100,0x03c7801000f83504,0xf800031000801104,0x000000861ffe0303\n"
".quad 0x0187802000183900,0x20c7e8300ed1fd04,0x000000a004000364,0x0022801004000300\n"
".quad 0x03078020000c3900,0x10078030021c3904,0x0ee838210eec40c4,0xc00780d00e1c3d21\n"
".quad 0x00078000020c0580,0xffffff203ca039c0,0xc00780d00e1c390f,0x23c7800400220180\n"
".quad 0x23878004022201e4,0x000002f0000001e4,0x000000861ffe03e0,0x000000a005900300\n"
".quad 0x0001001005900300,0x0007e03005063900,0x00210010059003a4,0x0000471004803d00\n"
".quad 0x00078000001e0500,0x0000071004803dc0,0x00078000001e0900,0x03c7801000f83dc0\n"
".quad 0x23c7801400c04504,0x5107e8b08209fd04,0x116044b942604060,0x402680c0832245c5\n"
".quad 0x402680c083081100,0x0007809000081100,0x040780e004221100,0x004780b07c084104\n"
".quad 0x04078020401a3560,0x00000320019e3d04,0x0147e8300f1dfd00,0x000780d400080564\n"
".quad 0x000780d800080920,0x0022801004b00320,0x03078220000a3100,0x2107e8300cd1fd04\n"
".quad 0x0147802040060d64,0x0022801003200304,0x000002f000000100,0x00078010060003e0\n"
".quad 0x03c7801000f83500,0x000000861ffe0304,0x0087e8307c17fd00,0x000000a00820036c\n"
".quad 0x0022801008200300,0x0147e8300d11fd00,0x03e5001000040d64,0x03e5001000040504\n"
".quad 0x03e5001000001104,0x03e2801000041104,0x03e2801000040104,0x03e2801000020d04\n"
".quad 0x180780b004062d04,0x200780c00be03180,0x010780b000062d00,0x200780b00ce03108\n"
".quad 0x0047e8b00c17fda0,0x0021001008100360,0x0047f8b07c07fd00,0x000000a007a00360\n"
".quad 0x0047e8b07c09fd00,0x0031001007800360,0x03c7801000f80100,0x40e2801000000104\n"
".quad 0x0007801007a00324,0x0000031001800100,0x03e2801000f80100,0x010782b000060504\n"
".quad 0x0147e8a00001fd00,0xf00003c00002052c,0x412980e081160503,0x0000031001802900\n"
".quad 0x03c7801000020100,0x0007801008200304,0x3f07800004220100,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x000780d010880500,0x6087e83480c1fd20,0x0022801008900364\n"
".quad 0x000000861ffe0300,0x0007801001700300,0x000000861ffe0300,0x0001003000000300\n"
".quad 0x10078030020e0500,0x2047802000d405c4,0xc00781d00e020104,0x00000000000001a0\n"
".quad 0x8000007e8000003f,0x00000000200b043e,0x0000100000000800,0x0000180000001400\n"
".quad 0x0000280000002000,0x080d040000003000,0x0000200022011000,0x0007d0a000000100\n"
".quad 0x000000a002a00304,0x0087c8307c01fd00,0x0016801002a00364,0x200780a0004c1500\n"
".quad 0x03c78010000a1904,0x10078030020c1904,0x10078030020a15c4,0x05f4182106f420c4\n"
".quad 0xc00780d00e0c1d21,0x2147802000d81580,0xc00780d00e0a1904,0x0000032004901580\n"
".quad 0xc00780d00e0a1500,0x21c7800014380180,0x21478000143a01e4,0x01478030000e15e4\n"
".quad 0x21878000143c0104,0xffffff203f8a19e4,0x21478000143e010f,0x0007d8d0060bfde4\n"
".quad 0x3f07800000360104,0x00150010026003e4,0x014780a0000a1500,0x5047d8b0800bfd44\n"
".quad 0x104780a0000a1960,0x401680c0870a15c4,0x40d6801000101d00,0x03d1001000f81d24\n"
".quad 0x10078030170a1504,0x400780d0810a15ec,0x4087d830810bfd04,0x01c78020400a1564\n"
".quad 0x009158b07c0dfd04,0xfffffb20028a1560,0x000003100180190f,0x03d6801000f81500\n"
".quad 0x00078030050c1504,0x21478000144001c4,0x00000310018015e4,0x2147800014420100\n"
".quad 0x3f078000144401e4,0x000002f0000001e4,0x000000861ffe03e0,0x000780d050f80500\n"
".quad 0x20c7d83400c1fd20,0x000000a004000364,0x0012801004000300,0x000780d050e00500\n"
".quad 0x2007802400c01520,0x10078030020a1504,0x00078000020005c4,0x2147802000dc19c0\n"
".quad 0xc00780d00e0c2104,0x2147802000e01980,0xc00780d00e0c1d04,0x2147802000e41980\n"
".quad 0xc00780d00e0c1904,0x2147802000e81580,0xc00780d00e0a1504,0x220780040c380180\n"
".quad 0x21c78004043801e4,0x21878004103801e4,0x21478004083801e4,0x000002f0000001e4\n"
".quad 0x000000861ffe03e0,0x03c7801000f82900,0x03c7801000f81504,0x000780d050f80504\n"
".quad 0x20c7d83400c1fd20,0x000000a007200364,0x0012801007200300,0x0007800002000500\n"
".quad 0x000063201c8005c0,0x000780d440e01100,0x0007800002020920,0x000780d410e00dc0\n"
".quad 0x23c7841000c00d20,0x000780d420e01104,0x000023201c800920,0x000780d430e00500\n"
".quad 0x23c7801c00c00520,0x23c7841000c01104,0x0007800002041104,0x000083201c801dc0\n"
".quad 0x2347d8b401c1fd00,0x000043201c801960,0x23c7801c00c00900,0x00078000020e0d04\n"
".quad 0x23c7801400c005c0,0x00078000020c0504,0x0011001006f003c0,0x2047ecb07cc1fd00\n"
".quad 0x000000a006500360,0x2047d8b87cc1fd00,0x0021001006300360,0x03c7801000f82100\n"
".quad 0x40d2801000042104,0x0007801006500324,0x0000031001802100,0x03d2801000f82100\n"
".quad 0x23c7821800c01504,0x23c7801800c01d04,0x214784b000c01504,0x23c7841000c01908\n"
".quad 0x0147d8a00011fd04,0x41c780e0830a152c,0x218780b800c01900,0x401e00c0830c1500\n"
".quad 0x3f07800014420100,0x00078010072003e4,0x46e0181d00e01800,0x40c7d830820dfd25\n"
".quad 0x3f15000014420164,0x000002f0000001e4,0x000000861ffe03e0,0x000780d051080500\n"
".quad 0x6087d83482c1fd20,0x001280101a900364,0x2087d8307cd1fd00,0x23c7801000d01964\n"
".quad 0x001280100ac00304,0x0007800002000500,0x000780d050f809c0,0x200780a000422d20\n"
".quad 0x03c7801000f83104,0x03c7801000f81d04,0xf800031000802104,0x2107d83800c1fd03\n"
".quad 0x000000861ffe0364,0x0007802000182500,0x20c7e83009d1fd04,0x000000a008e00364\n"
".quad 0x0022801008e00300,0x0007802000182500,0x1007803002122504,0x09e8242109ec38c4\n"
".quad 0xc00780d00e123521,0xffffff203c9c2580,0xc00780d00e12250f,0x234780040c380180\n"
".quad 0x22478004043801e4,0x000002f0000001e4,0x000000861ffe03e0,0x000000a00a700300\n"
".quad 0x001100100a700300,0x0007e0300b0c3500,0x002100100a7003a4,0x0000871030802500\n"
".quad 0x0007800000120900,0x00018710308025c0,0x0007800000120d00,0x03c7801000f839c0\n"
".quad 0x23c7801800c02504,0x5107e8b08411fd04,0x096024bd45603c60,0x402680c0891225c9\n"
".quad 0x402680c089102100,0x0007809000102100,0x03c780e008122100,0x004780b07c102504\n"
".quad 0x02478020400e1d60,0x00000320019c3904,0x0147e8300e1bfd00,0x000780d800080964\n"
".quad 0x000780dc00080d20,0x0022801009900320,0x0307822000163100,0x2107e8300cd1fd04\n"
".quad 0x02c78020400c1964,0x0022801008100304,0x000780100af00300,0x0007800002000500\n"
".quad 0x200780a000422dc0,0x03c7801000f81d04,0x03c78010000e1904,0x000000861ffe0304\n"
".quad 0x000780d050f80900,0x20c7d83800c1fd20,0x000000a013700364,0x0012801013700300\n"
".quad 0x0347d8b00203fd00,0x0011001012200360,0x0147d030030c1d00,0x01478030040c2164\n"
".quad 0x400780d0820e2564,0x014780a000101d04,0x0007e8d00713fd2c,0x104780a0000a1d04\n"
".quad 0x002100100e2003c4,0x100780b007021d00,0x200780c007f42180,0x004780b0000a1d00\n"
".quad 0x400780b085102508,0x104780a0000e2180,0x004780a0001225c4,0x20c78004103801c4\n"
".quad 0x00c7d8b00911fde4,0x000000a00dc00360,0x2187800408380100,0x001100100da003e4\n"
".quad 0x0047e0b07c022100,0x0047f8b07c0bfd60,0x000000a00d300360,0x0147d8a00011fd00\n"
".quad 0x003100100d10030c,0x03c7801000f82100,0x40e2801000042104,0x000780100d300324\n"
".quad 0x0000031001802100,0x03d2801000f82100,0x014782b000022504,0x0147d8a00011fd00\n"
".quad 0xf00003c00012212c,0x405980e0830e2103,0x220780040c380100,0x22078004043801e4\n"
".quad 0x000780100dc003e4,0x204780040c380100,0x21478004043801e4,0x000002f0000001e4\n"
".quad 0x0000031001801de0,0x21c7800400380100,0x21c78000144401e4,0x00000310018029e4\n"
".quad 0x0007801013700300,0x000000a012000300,0x3f07800400380100,0x00110010103003e4\n"
".quad 0x100780b007021d00,0x200780c007f42180,0x004780b0000a1d00,0x400780b085102508\n"
".quad 0x104780a0000e2180,0x004780a0001225c4,0x20c78004103801c4,0x00c7d8b00911fde4\n"
".quad 0x2187800408380160,0x00110010100003e4,0x0047e0b07c022100,0x0047f8b07c0bfd60\n"
".quad 0x000000a00f900360,0x0147d8a00011fd00,0x003100100f70030c,0x03c7801000f82100\n"
".quad 0x40e2801000042104,0x000780100f900324,0x0000031001802100,0x03d2801000f82100\n"
".quad 0x014782b000022504,0x0147d8a00011fd00,0xf00003c00012212c,0x405980e0830e2103\n"
".quad 0x220780040c380100,0x22078004043801e4,0x00078010120003e4,0x204780040c380100\n"
".quad 0x21478004043801e4,0x00078010120003e4,0x100780b007041d00,0x200780c007f42180\n"
".quad 0x014780b000041d00,0x400780b085102508,0x104780a0000e2180,0x004780a0001225c4\n"
".quad 0x21878004103801c4,0x00c7d8b00911fde4,0x2107800408380160,0x0011001011e003e4\n"
".quad 0x0047e0b07c0a2100,0x0047f8b07c05fd60,0x000000a011700360,0x0147d8a00011fd00\n"
".quad 0x003100101150030c,0x03c7801000f82100,0x40e2801000042104,0x0007801011700324\n"
".quad 0x0000031001802100,0x03d2801000f82100,0x014782b000042504,0x0147d8a00011fd00\n"
".quad 0xf00003c00012212c,0x415980e0830e2103,0x220780040c380100,0x22078004043801e4\n"
".quad 0x00078010120003e4,0x214780040c380100,0x20878004043801e4,0x03c7821000f829e4\n"
".quad 0x0007801013700304,0x00c7802040081d00,0x4147d830820ffd04,0x0012801012c00364\n"
".quad 0x204780040c380100,0x20878004043801e4,0x20c78004103801e4,0x21078004083801e4\n"
".quad 0x03c7801000f829e4,0x3f07800400380104,0x00078010137003e4,0x204780040c380100\n"
".quad 0x10078030010e15e4,0x20878004043801e4,0x00c78020000a19e4,0x20c7800410380104\n"
".quad 0x00000310018015e4,0x2187800408380100,0x21478004003801e4,0x21478000144401e4\n"
".quad 0x00000310018029e4,0x03c7801000021500,0x000002f000000104,0x000000861ffe03e0\n"
".quad 0x000780d051100900,0x6147d83882c1fd20,0x0012801018300364,0x000780d051000900\n"
".quad 0x3007803801c03120,0x00c7d8307c19fde4,0x23c7801800c0256c,0x0012801015f00304\n"
".quad 0x0000031001801d00,0x000000861ffe0300,0x00c7d8300019fd00,0x000000a015a00364\n"
".quad 0x0012801015a00300,0x1007803001003500,0x00000320029a21c4,0x000780400f203900\n"
".quad 0x038780600e223900,0x10078030101c3900,0x0387d0600e2021c4,0xffffff203f903900\n"
".quad 0x00000320019a210f,0x03d5001000f83900,0x00078000021c0904,0x00078040101e35c0\n"
".quad 0x03478060111c3500,0x10078030101a3500,0x0347d060101c21c4,0xffffff203f902100\n"
".quad 0x03d5001000f8210f,0x0007800002100d04,0x23c7801c00f821c0,0x2207802800f82104\n"
".quad 0x2207800800380104,0x10078230011831e4,0x0107d8307c19fdec,0x10078030010e1d6c\n"
".quad 0x00128010142003c4,0x0007801016000300,0x0000031001801d00,0x40c7d8308613fd00\n"
".quad 0x0012801017400364,0x0000031002803100,0x10078030010e1d00,0x000000861ffe03e4\n"
".quad 0xffffff203f982100,0x0187d8300801fd0f,0x000000a017100364,0x0012801017100300\n"
".quad 0x0000032001802100,0x10078030010e3500,0x089a3440480e20e4,0x0007800002100920\n"
".quad 0x00078000021a0dc0,0x23c7801800f621c0,0x2207802c00f62104,0x2207800c00360104\n"
".quad 0x10078230011831e4,0x0047d8300919fdc4,0x0012801016300364,0x000000861ffe0300\n"
".quad 0x4087d8308215fd00,0x000780d050f80964,0x2112d83800c1fd20,0x000000a018200364\n"
".quad 0x0011001018200300,0x000780d050f80900,0x23c7801800c01d20,0x21c7802400f61d04\n"
".quad 0x00078000020e0904,0x214780080c3801c0,0x20878008043801e4,0x21878008103801e4\n"
".quad 0x21078008083801e4,0x000002f0000001e4,0x000000861ffe03e0,0x000000a01a100300\n"
".quad 0x000100101a100300,0x000780d050f80900,0x23c7801800c01920,0x2007800802c00904\n"
".quad 0x2187802800f619c0,0xffffff203f8c1d04,0x0007d8d0070dfd0f,0x21878000143e0104\n"
".quad 0x0015001019d003e4,0x014780a0000c1900,0x5047d8b0800dfd44,0x104780a0000c1d60\n"
".quad 0x401680c0870c19c4,0x40d6801000102100,0x03d1001000f82124,0x10078030170c1904\n"
".quad 0x400780d0810c19ec,0x4087d830810dfd04,0x02078020400c1964,0x009158b07c0ffd04\n"
".quad 0xfffffb20028c1960,0x0000031001801d0f,0x03d6801000f81900,0x00078030060e1904\n"
".quad 0x21878000144001c4,0x00000310018019e4,0x3f07800014440100,0x21878000144201e4\n"
".quad 0x000002f0000001e4,0x000000861ffe03e0,0x0007802000161900,0x00078000020c0904\n"
".quad 0x3f078004003801c0,0x3f078008003801e4,0x000000861ffe03e4,0x0007801004400300\n"
".quad 0x000780d050f80500,0x20c7c83400c1fd20,0x0002803000000364,0x000780d050f00500\n"
".quad 0x0007800002000920,0x2007802400c001c0,0x000780d830e00504,0x1007803002000520\n"
".quad 0x23c7801400c001c4,0x2047802000ec0904,0x000780d820e00504,0xc00780d00e040120\n"
".quad 0x23c7801400c001a0,0x2047802000f00504,0xc00781d00e020104,0x0000ff00800000a0\n"
".quad 0x0000000000000100,0x2a24257e8000003f,0x8000000000000203,0x800000000000184b\n"
".quad 0x00000000300b043e,0x0000100000000800,0x0000200000001800,0x0000300000002800\n"
".quad 0x0000400000003800,0x0000500000004800,0x080d040000005800,0x0000200021010800\n"
".quad 0x0000000600000000,0x00003be400000005,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000018800000000,0x0000018800000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x00000a3900001405,0x0000000000000000,0x0000000000000000,0x00001ed000000000\n"
".quad 0x00001ed000000000,0x0000000400000000,0x6000000000000000,0x0000290900001406\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x000020bc00000000\n"
".quad 0x0000000400000000,0x6000000000000000,0x0000290900001305,0x0000000000000000\n"
".quad 0x0000000000000000,0x000004b000000000,0x000004b000000000,0x0000000400000000\n"
".quad 0x6000000000000000,0x00002db900001306,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000084800000000,0x0000000400000000,0x6000000000000000\n"
".quad 0x00002db900001205,0x0000000000000000,0x0000000000000000,0x00000e2800000000\n"
".quad 0x00000e2800000000,0x0000000400000000,0x6000000000000000,0x00003be100001206\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000288c00000000\n"
".quad 0x0000000400000000,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_10$[1966];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_10", (char*)__deviceText_$sm_10$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_10$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"d0f24496883a777e",(char*)"bisect_large.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xb0c12441,&__elfEntries1};
# 2 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c" 2
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
# 4996 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 4997 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 88 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 166 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c" 2
struct __T20 {float *__par0;float *__par1;unsigned __par2;float __par3;float __par4;unsigned __par5;unsigned __par6;float __par7;unsigned *__par8;unsigned *__par9;float *__par10;float *__par11;unsigned *__par12;float *__par13;float *__par14;unsigned *__par15;unsigned *__par16;unsigned *__par17;unsigned *__par18;int __dummy_field;};
struct __T21 {float *__par0;float *__par1;unsigned __par2;unsigned __par3;float *__par4;float *__par5;unsigned *__par6;float __par7;int __dummy_field;};
struct __T22 {float *__par0;float *__par1;unsigned __par2;unsigned *__par3;unsigned *__par4;float *__par5;float *__par6;unsigned *__par7;unsigned *__par8;float *__par9;unsigned *__par10;float __par11;int __dummy_field;};
extern void __device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *);
extern void __device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float);
extern void __device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float);
static void __sti____cudaRegisterAll_47_tmpxft_00002266_00000000_4_bisect_large_cpp1_ii_7621fe01(void) __attribute__((__constructor__));
void __device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_(float *__par0, float *__par1, const unsigned __par2, const float __par3, const float __par4, const unsigned __par5, const unsigned __par6, float __par7, unsigned *__par8, unsigned *__par9, float *__par10, float *__par11, unsigned *__par12, float *__par13, float *__par14, unsigned *__par15, unsigned *__par16, unsigned *__par17, unsigned *__par18){ struct __T20 *__T24;
*(void**)(void*)&__T24 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T24->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T24->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T24->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T24->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T24->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T24->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T24->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T24->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T24->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T24->__par14) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T24->__par15) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T24->__par16) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par17, sizeof(__par17), (size_t)&__T24->__par17) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par18, sizeof(__par18), (size_t)&__T24->__par18) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge))); };}
void bisectKernelLarge( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,const float __cuda_3,const float __cuda_4,const unsigned __cuda_5,const unsigned __cuda_6,float __cuda_7,unsigned *__cuda_8,unsigned *__cuda_9,float *__cuda_10,float *__cuda_11,unsigned *__cuda_12,float *__cuda_13,float *__cuda_14,unsigned *__cuda_15,unsigned *__cuda_16,unsigned *__cuda_17,unsigned *__cuda_18)
# 179 "bisect_kernel_large.cu"
{__device_stub__Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16,__cuda_17,__cuda_18);
# 522 "bisect_kernel_large.cu"
}
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c"
void __device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf( float *__par0, float *__par1, const unsigned __par2, unsigned __par3, float *__par4, float *__par5, unsigned *__par6, float __par7) { struct __T21 *__T28;
*(void**)(void*)&__T28 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T28->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T28->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T28->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T28->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T28->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T28->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T28->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T28->__par7) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals))); }; }
void bisectKernelLarge_OneIntervals( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,unsigned __cuda_3,float *__cuda_4,float *__cuda_5,unsigned *__cuda_6,float __cuda_7)
# 71 "bisect_kernel_large_onei.cu"
{__device_stub__Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);
# 172 "bisect_kernel_large_onei.cu"
}
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c"
void __device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f( float *__par0, float *__par1, const unsigned __par2, unsigned *__par3, unsigned *__par4, float *__par5, float *__par6, unsigned *__par7, unsigned *__par8, float *__par9, unsigned *__par10, float __par11) { struct __T22 *__T29;
*(void**)(void*)&__T29 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T29->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T29->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T29->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T29->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T29->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T29->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T29->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T29->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T29->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T29->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T29->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T29->__par11) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals)); (void)cudaLaunch(((char *)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals))); }; }
void bisectKernelLarge_MultIntervals( float *__cuda_0,float *__cuda_1,const unsigned __cuda_2,unsigned *__cuda_3,unsigned *__cuda_4,float *__cuda_5,float *__cuda_6,unsigned *__cuda_7,unsigned *__cuda_8,float *__cuda_9,unsigned *__cuda_10,float __cuda_11)
# 80 "bisect_kernel_large_multi.cu"
{__device_stub__Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11);
# 247 "bisect_kernel_large_multi.cu"
}
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c"
static void __sti____cudaRegisterAll_47_tmpxft_00002266_00000000_4_bisect_large_cpp1_ii_7621fe01(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, unsigned *, unsigned *, float *, float *, unsigned *, unsigned *, float *, unsigned *, float))bisectKernelLarge_MultIntervals), (char*)"_Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f", "_Z31bisectKernelLarge_MultIntervalsPfS_jPjS0_S_S_S0_S0_S_S0_f", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, unsigned, float *, float *, unsigned *, float))bisectKernelLarge_OneIntervals), (char*)"_Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf", "_Z30bisectKernelLarge_OneIntervalsPfS_jjS_S_Pjf", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, float *, const unsigned, const float, const float, const unsigned, const unsigned, float, unsigned *, unsigned *, float *, float *, unsigned *, float *, float *, unsigned *, unsigned *, unsigned *, unsigned *))bisectKernelLarge), (char*)"_Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_", "_Z17bisectKernelLargePfS_jffjjfPjS0_S_S_S0_S_S_S0_S0_S0_S0_", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_00002266_00000000-1_bisect_large.cudafe1.stub.c" 2

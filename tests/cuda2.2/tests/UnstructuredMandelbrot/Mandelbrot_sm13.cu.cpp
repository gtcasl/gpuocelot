# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.cpp"
# 1 "Mandelbrot_sm13.cu"
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
# 6 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);
# 9 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot1_sm10(uchar4 *, const int, const int, const int, const double, const double, const float, const float, const double, const uchar4, const int, const int, const int, const bool);
# 13 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot0_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);
# 16 "Mandelbrot_kernel.h"
extern "C" void RunMandelbrot1_sm13(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool);
# 20 "Mandelbrot_kernel.h"
extern "C" int inEmulationMode();
# 15 "Mandelbrot_kernel.cu"
inline void dsdeq(float &a0, float &a1, double b)
# 16 "Mandelbrot_kernel.cu"
{
# 17 "Mandelbrot_kernel.cu"
a0 = ((float)b);
# 18 "Mandelbrot_kernel.cu"
a1 = ((float)(b - a0));
# 19 "Mandelbrot_kernel.cu"
}
# 22 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsfeq(float &a0, float &a1, float b)
# 23 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 26 "Mandelbrot_kernel.cu"
exit(___);}
# 29 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsadd(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 30 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 39 "Mandelbrot_kernel.cu"
exit(___);}
# 42 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dssub(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 43 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 52 "Mandelbrot_kernel.cu"
exit(___);}
# 57 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline void dsmul(float &c0, float &c1, const float a0, const float a1, const float b0, const float b1)
# 58 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 82 "Mandelbrot_kernel.cu"
exit(___);}
# 126 "Mandelbrot_kernel.cu"
template<class T> __attribute__((unused)) inline void
# 127 "Mandelbrot_kernel.cu"
CalcMandelbrot(int *
# 128 "Mandelbrot_kernel.cu"
output, const T *
# 129 "Mandelbrot_kernel.cu"
xPos, const T
# 130 "Mandelbrot_kernel.cu"
yPos, const T
# 131 "Mandelbrot_kernel.cu"
xJParam, const T
# 132 "Mandelbrot_kernel.cu"
yJParam, const int
# 133 "Mandelbrot_kernel.cu"
crunch, const bool
# 134 "Mandelbrot_kernel.cu"
isJulia, const int
# 135 "Mandelbrot_kernel.cu"
points)
# 136 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 190 "Mandelbrot_kernel.cu"
exit(___);}
# 194 "Mandelbrot_kernel.cu"
template<class T> __attribute__((unused)) inline int
# 195 "Mandelbrot_kernel.cu"
CalcMandelbrot(const T
# 196 "Mandelbrot_kernel.cu"
xPos, const T
# 197 "Mandelbrot_kernel.cu"
yPos, const T
# 198 "Mandelbrot_kernel.cu"
xJParam, const T
# 199 "Mandelbrot_kernel.cu"
yJParam, const int
# 200 "Mandelbrot_kernel.cu"
crunch, const bool
# 201 "Mandelbrot_kernel.cu"
isJulia)
# 202 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 230 "Mandelbrot_kernel.cu"
exit(___);}
# 234 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline int CalcMandelbrotDS(const float
# 235 "Mandelbrot_kernel.cu"
xPos0, const float
# 236 "Mandelbrot_kernel.cu"
xPos1, const float
# 237 "Mandelbrot_kernel.cu"
yPos0, const float
# 238 "Mandelbrot_kernel.cu"
yPos1, const float
# 239 "Mandelbrot_kernel.cu"
xJParam, const float
# 240 "Mandelbrot_kernel.cu"
yJParam, const int
# 241 "Mandelbrot_kernel.cu"
crunch, const bool
# 242 "Mandelbrot_kernel.cu"
isJulia)
# 243 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 293 "Mandelbrot_kernel.cu"
exit(___);}
# 297 "Mandelbrot_kernel.cu"
__attribute__((unused)) inline int CheckColors(const uchar4 &color0, const uchar4 &color1)
# 298 "Mandelbrot_kernel.cu"
{int volatile ___ = 1;
# 303 "Mandelbrot_kernel.cu"
exit(___);}
# 308 "Mandelbrot_kernel.cu"
inline int iDivUp(int a, int b)
# 309 "Mandelbrot_kernel.cu"
{
# 310 "Mandelbrot_kernel.cu"
return ((a % b) != 0) ? ((a / b) + 1) : (a / b);
# 311 "Mandelbrot_kernel.cu"
}
# 21 "Mandelbrot_sm13.cu"
static unsigned blockCounter;
# 23 "Mandelbrot_sm13.cu"
template<class T, const int pointsPerThread> static void
# 24 "Mandelbrot_sm13.cu"
__wrapper__device_stub_Mandelbrot0_sm13(uchar4 *&dst, const int &imageW, const int &
# 25 "Mandelbrot_sm13.cu"
imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 26 "Mandelbrot_sm13.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &
# 27 "Mandelbrot_sm13.cu"
frame, const int &animationFrame, const int &gridWidth, const int &
# 28 "Mandelbrot_sm13.cu"
numBlocks, const bool &isJ) ;
# 23 "Mandelbrot_sm13.cu"
template<class T, const int pointsPerThread> void
# 24 "Mandelbrot_sm13.cu"
Mandelbrot0_sm13(uchar4 *dst, const int imageW, const int
# 25 "Mandelbrot_sm13.cu"
imageH, const int crunch, const T xOff, const T yOff, const T
# 26 "Mandelbrot_sm13.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int
# 27 "Mandelbrot_sm13.cu"
frame, const int animationFrame, const int gridWidth, const int
# 28 "Mandelbrot_sm13.cu"
numBlocks, const bool isJ)
# 29 "Mandelbrot_sm13.cu"
{__wrapper__device_stub_Mandelbrot0_sm13<T,pointsPerThread>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,gridWidth,numBlocks,isJ);
# 107 "Mandelbrot_sm13.cu"
}
# 111 "Mandelbrot_sm13.cu"
void MandelbrotDS0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float xOff0, const float xOff1, const float
# 112 "Mandelbrot_sm13.cu"
yOff0, const float yOff1, const float xJP, const float yJP, const float scale, const uchar4
# 113 "Mandelbrot_sm13.cu"
colors, const int frame, const int animationFrame, const int gridWidth, const int
# 114 "Mandelbrot_sm13.cu"
numBlocks, const bool isJ) ;
# 186 "Mandelbrot_sm13.cu"
template<class T> static void
# 187 "Mandelbrot_sm13.cu"
__wrapper__device_stub_Mandelbrot1_sm13(uchar4 *&dst, const int &imageW, const int &imageH, const int &crunch, const T &xOff, const T &yOff, const T &
# 188 "Mandelbrot_sm13.cu"
xJP, const T &yJP, const T &scale, const uchar4 &colors, const int &frame, const int &
# 189 "Mandelbrot_sm13.cu"
animationFrame, const int &gridWidth, const int &numBlocks, const bool &isJ) ;
# 186 "Mandelbrot_sm13.cu"
template<class T> void
# 187 "Mandelbrot_sm13.cu"
Mandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const T xOff, const T yOff, const T
# 188 "Mandelbrot_sm13.cu"
xJP, const T yJP, const T scale, const uchar4 colors, const int frame, const int
# 189 "Mandelbrot_sm13.cu"
animationFrame, const int gridWidth, const int numBlocks, const bool isJ)
# 190 "Mandelbrot_sm13.cu"
{__wrapper__device_stub_Mandelbrot1_sm13<T>(dst,imageW,imageH,crunch,xOff,yOff,xJP,yJP,scale,colors,frame,animationFrame,gridWidth,numBlocks,isJ);
# 267 "Mandelbrot_sm13.cu"
}
# 270 "Mandelbrot_sm13.cu"
void MandelbrotDS1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const float
# 271 "Mandelbrot_sm13.cu"
xOff0, const float xOff1, const float yOff0, const float yOff1, const float
# 272 "Mandelbrot_sm13.cu"
xJP, const float yJP, const float scale, const uchar4 colors, const int
# 273 "Mandelbrot_sm13.cu"
frame, const int animationFrame, const int gridWidth, const int numBlocks, const bool isJ) ;
# 362 "Mandelbrot_sm13.cu"
void RunMandelbrot0_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double
# 363 "Mandelbrot_sm13.cu"
xjp, const double yjp, const double scale, const uchar4 colors, const int frame, const int
# 364 "Mandelbrot_sm13.cu"
animationFrame, const int mode, const int numSMs, const bool isJ)
# 365 "Mandelbrot_sm13.cu"
{
# 366 "Mandelbrot_sm13.cu"
dim3 threads(16, 16);
# 367 "Mandelbrot_sm13.cu"
dim3 grid(iDivUp(iDivUp(imageW, 16), 16), iDivUp(imageH, 16));
# 370 "Mandelbrot_sm13.cu"
unsigned hBlockCounter = (0);
# 371 "Mandelbrot_sm13.cu"
__cudaSafeCall(cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned), 0, cudaMemcpyHostToDevice), "Mandelbrot_sm13.cu", 371);
# 373 "Mandelbrot_sm13.cu"
int numWorkerBlocks = numSMs;
# 375 "Mandelbrot_sm13.cu"
switch (mode) {
# 376 "Mandelbrot_sm13.cu"
default:
# 377 "Mandelbrot_sm13.cu"
case 0:
# 378 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot0_sm13< float, 16> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 380 "Mandelbrot_sm13.cu"
break;
# 381 "Mandelbrot_sm13.cu"
case 1:
# 382 "Mandelbrot_sm13.cu"
float x0, x1, y0, y1;
# 383 "Mandelbrot_sm13.cu"
dsdeq(x0, x1, xOff);
# 384 "Mandelbrot_sm13.cu"
dsdeq(y0, y1, yOff);
# 385 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : MandelbrotDS0_sm13(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 387 "Mandelbrot_sm13.cu"
break;
# 388 "Mandelbrot_sm13.cu"
case 2:
# 389 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot0_sm13< double, 16> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 391 "Mandelbrot_sm13.cu"
break;
# 392 "Mandelbrot_sm13.cu"
}
# 393 "Mandelbrot_sm13.cu"
__cutilCheckMsg("Mandelbrot0_sm13 kernel execution failed.\n", "Mandelbrot_sm13.cu", 393);
# 394 "Mandelbrot_sm13.cu"
}
# 397 "Mandelbrot_sm13.cu"
void RunMandelbrot1_sm13(uchar4 *dst, const int imageW, const int imageH, const int crunch, const double xOff, const double yOff, const double
# 398 "Mandelbrot_sm13.cu"
xjp, const double yjp, const double scale, const uchar4 colors, const int frame, const int
# 399 "Mandelbrot_sm13.cu"
animationFrame, const int mode, const int numSMs, const bool isJ)
# 400 "Mandelbrot_sm13.cu"
{
# 401 "Mandelbrot_sm13.cu"
dim3 threads(16, 16);
# 402 "Mandelbrot_sm13.cu"
dim3 grid(iDivUp(imageW, 16), iDivUp(imageH, 16));
# 405 "Mandelbrot_sm13.cu"
unsigned hBlockCounter = (0);
# 406 "Mandelbrot_sm13.cu"
__cudaSafeCall(cudaMemcpyToSymbol(blockCounter, &hBlockCounter, sizeof(unsigned), 0, cudaMemcpyHostToDevice), "Mandelbrot_sm13.cu", 406);
# 408 "Mandelbrot_sm13.cu"
int numWorkerBlocks = numSMs;
# 410 "Mandelbrot_sm13.cu"
switch (mode) {
# 411 "Mandelbrot_sm13.cu"
default:
# 412 "Mandelbrot_sm13.cu"
case 0:
# 413 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot1_sm13< float> )(dst, imageW, imageH, crunch, (float)xOff, (float)yOff, (float)xjp, (float)yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 415 "Mandelbrot_sm13.cu"
break;
# 416 "Mandelbrot_sm13.cu"
case 1:
# 417 "Mandelbrot_sm13.cu"
float x0, x1, y0, y1;
# 418 "Mandelbrot_sm13.cu"
dsdeq(x0, x1, xOff);
# 419 "Mandelbrot_sm13.cu"
dsdeq(y0, y1, yOff);
# 420 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : MandelbrotDS1_sm13(dst, imageW, imageH, crunch, x0, x1, y0, y1, xjp, yjp, (float)scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 422 "Mandelbrot_sm13.cu"
break;
# 423 "Mandelbrot_sm13.cu"
case 2:
# 424 "Mandelbrot_sm13.cu"
cudaConfigureCall(numWorkerBlocks, threads) ? ((void)0) : (Mandelbrot1_sm13< double> )(dst, imageW, imageH, crunch, xOff, yOff, xjp, yjp, scale, colors, frame, animationFrame, grid.x, (grid.x) * (grid.y), isJ);
# 426 "Mandelbrot_sm13.cu"
break;
# 427 "Mandelbrot_sm13.cu"
}
# 429 "Mandelbrot_sm13.cu"
__cutilCheckMsg("Mandelbrot1_sm13 kernel execution failed.\n", "Mandelbrot_sm13.cu", 429);
# 430 "Mandelbrot_sm13.cu"
}
# 434 "Mandelbrot_sm13.cu"
int inEmulationMode()
# 435 "Mandelbrot_sm13.cu"
{
# 437 "Mandelbrot_sm13.cu"
return 1;
# 441 "Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_0000241e_00000000-3_Mandelbrot_sm13.fatbin.c" 1
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
# 2 "/tmp/tmpxft_0000241e_00000000-3_Mandelbrot_sm13.fatbin.c" 2



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
".quad 0x6d742f706d742f20,0x3030305f74667870,0x30305f6531343230,0x372d303030303030\n"
".quad 0x626c65646e614d5f,0x33316d735f746f72,0x20692e337070632e,0x63632f706d742f28\n"
".quad 0x504b72632e234942,0x2d2f2f090a294252,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
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
".quad 0x22093209656c6966,0x706d742f706d742f,0x303030305f746678,0x3030305f65313432\n"
".quad 0x5f362d3030303030,0x72626c65646e614d,0x2e33316d735f746f,0x2e32656661647563\n"
".quad 0x662e090a22757067,0x2f22093309656c69,0x2f62696c2f727375,0x5f3638782f636367\n"
".quad 0x78756e696c2d3436,0x342e342f756e672d,0x756c636e692f352e,0x65646474732f6564\n"
".quad 0x662e090a22682e66,0x2f22093409656c69,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x72632f6564756c63,0x6563697665642f74,0x656d69746e75725f\n"
".quad 0x69662e090a22682e,0x752f22093509656c,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x736f682f6564756c,0x656e696665645f74,0x662e090a22682e73\n"
".quad 0x2f22093609656c69,0x61636f6c2f727375,0x622f616475632f6c,0x6e692f2e2e2f6e69\n"
".quad 0x75622f6564756c63,0x79745f6e69746c69,0x090a22682e736570,0x093709656c69662e\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f,0x2f6564756c636e69\n"
".quad 0x745f656369766564,0x0a22682e73657079,0x3809656c69662e09,0x6c2f7273752f2209\n"
".quad 0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f,0x5f7265766972642f\n"
".quad 0x22682e7365707974,0x09656c69662e090a,0x2f7273752f220939,0x75632f6c61636f6c\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6361667275732f65,0x2e73657079745f65\n"
".quad 0x6c69662e090a2268,0x752f220930310965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x7865742f6564756c,0x7079745f65727574,0x2e090a22682e7365\n"
".quad 0x09313109656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x745f726f74636576,0x0a22682e73657079,0x3109656c69662e09\n"
".quad 0x2f7273752f220932,0x75632f6c61636f6c,0x2e2f6e69622f6164,0x64756c636e692f2e\n"
".quad 0x6563697665642f65,0x5f68636e75616c5f,0x6574656d61726170,0x2e090a22682e7372\n"
".quad 0x09333109656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x726f74732f747263,0x73616c635f656761,0x662e090a22682e73\n"
".quad 0x2209343109656c69,0x636e692f7273752f,0x7469622f6564756c,0x2e73657079742f73\n"
".quad 0x6c69662e090a2268,0x752f220935310965,0x756c636e692f7273,0x2e656d69742f6564\n"
".quad 0x6c69662e090a2268,0x614d220936310965,0x746f72626c65646e,0x2e6c656e72656b5f\n"
".quad 0x69662e090a227563,0x4d2209373109656c,0x6f72626c65646e61,0x632e33316d735f74\n"
".quad 0x6c69662e090a2275,0x752f220938310965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x6d6f632f6564756c,0x636e75665f6e6f6d,0x22682e736e6f6974\n"
".quad 0x09656c69662e090a,0x7273752f22093931,0x632f6c61636f6c2f,0x2f6e69622f616475\n"
".quad 0x756c636e692f2e2e,0x5f6874616d2f6564,0x6e6f6974636e7566,0x662e090a22682e73\n"
".quad 0x2209303209656c69,0x636f6c2f7273752f,0x2f616475632f6c61,0x692f2e2e2f6e6962\n"
".quad 0x6d2f6564756c636e,0x736e6f635f687461,0x22682e73746e6174,0x09656c69662e090a\n"
".quad 0x7273752f22093132,0x632f6c61636f6c2f,0x2f6e69622f616475,0x756c636e692f2e2e\n"
".quad 0x63697665642f6564,0x6974636e75665f65,0x090a22682e736e6f,0x323209656c69662e\n"
".quad 0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61,0x6564756c636e692f\n"
".quad 0x615f31315f6d732f,0x75665f63696d6f74,0x2e736e6f6974636e,0x6c69662e090a2268\n"
".quad 0x752f220933320965,0x6c61636f6c2f7273,0x69622f616475632f,0x636e692f2e2e2f6e\n"
".quad 0x5f6d732f6564756c,0x696d6f74615f3231,0x6974636e75665f63,0x090a22682e736e6f\n"
".quad 0x343209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f,0x2e2e2f6e69622f61\n"
".quad 0x6564756c636e692f,0x645f33315f6d732f,0x75665f656c62756f,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220935320965,0x6c61636f6c2f7273,0x69622f616475632f\n"
".quad 0x636e692f2e2e2f6e,0x5f6d732f6564756c,0x696d6f74615f3032,0x6974636e75665f63\n"
".quad 0x090a22682e736e6f,0x363209656c69662e,0x6c2f7273752f2209,0x6475632f6c61636f\n"
".quad 0x2e2e2f6e69622f61,0x6564756c636e692f,0x695f30325f6d732f,0x6369736e6972746e\n"
".quad 0x662e090a22682e73,0x2209373209656c69,0x636f6c2f7273752f,0x2f616475632f6c61\n"
".quad 0x692f2e2e2f6e6962,0x732f6564756c636e,0x665f656361667275,0x736e6f6974636e75\n"
".quad 0x69662e090a22682e,0x2f2209383209656c,0x61636f6c2f727375,0x622f616475632f6c\n"
".quad 0x6e692f2e2e2f6e69,0x65742f6564756c63,0x65665f6572757478,0x636e75665f686374\n"
".quad 0x22682e736e6f6974,0x09656c69662e090a,0x7273752f22093932,0x632f6c61636f6c2f\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x5f6874616d2f6564,0x6e6f6974636e7566\n"
".quad 0x74705f6c62645f73,0x090a0a22682e3378,0x206c61626f6c672e,0x6f6c62203233752e\n"
".quad 0x65746e756f436b63,0x6e652e090a0a3b72,0x38315a5f20797274,0x72626c65646e614d\n"
".quad 0x6d735f305344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x09090a2820626969,0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x645f62696969695f,0x702e09090a2c7473,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72\n"
".quad 0x686375365033316d,0x6666696969347261,0x695f536666666666,0x616d695f62696969\n"
".quad 0x2e09090a2c576567,0x732e206d61726170,0x6475635f5f203233,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3831,0x5f305344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x6d695f6269696969,0x09090a2c48656761,0x2e206d617261702e\n"
".quad 0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c\n"
".quad 0x75365033316d735f,0x6969693472616863,0x5366666666666666,0x635f62696969695f\n"
".quad 0x090a2c68636e7572,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x090a2c3066664f78,0x206d617261702e09\n"
".quad 0x635f5f203233662e,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x090a2c3166664f78,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x090a2c3066664f79,0x206d617261702e09\n"
".quad 0x635f5f203233662e,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f30,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x090a2c3166664f79,0x206d617261702e09,0x635f5f203233662e,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x2e09090a2c504a78,0x662e206d61726170\n"
".quad 0x6475635f5f203233,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x4a795f6269696969\n"
".quad 0x61702e09090a2c50,0x3233662e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x6c6163735f626969,0x61702e09090a2c65,0x696c612e206d6172\n"
".quad 0x38622e2034206e67,0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x6d735f305344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x6f6c6f635f626969,0x090a2c5d345b7372,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f30\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x090a2c656d617266\n"
".quad 0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365033316d735f30,0x6969347261686375,0x6666666666666669\n"
".quad 0x5f62696969695f53,0x6f6974616d696e61,0x0a2c656d6172466e,0x6d617261702e0909\n"
".quad 0x5f5f203233732e20,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5033316d735f3053,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x646957646972675f,0x702e09090a2c6874,0x33732e206d617261,0x616475635f5f2032\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x6d756e5f62696969,0x0a2c736b636f6c42\n"
".quad 0x6d617261702e0909,0x635f5f2038732e20,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365033316d735f30,0x6969347261686375,0x6666666666666669\n"
".quad 0x5f62696969695f53,0x0a7b090a294a7369,0x752e206765722e09,0x3b31767225203233\n"
".quad 0x2e206765722e090a,0x393c722520323375,0x65722e090a3b3e30,0x25203436752e2067\n"
".quad 0x090a3b3e383c6472,0x33662e206765722e,0x3832323c66252032,0x6765722e090a3b3e\n"
".quad 0x2520646572702e20,0x090a3b3e37313c70,0x206465726168732e,0x635f5f203233752e\n"
".quad 0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f303335,0x65646e496b636f6c\n"
".quad 0x6168732e090a3b78,0x3233752e20646572,0x5f616475635f5f20,0x61765f6c61636f6c\n"
".quad 0x5f31333536325f72,0x6b636f6c625f3234,0x6168732e090a3b58,0x3233752e20646572\n"
".quad 0x5f616475635f5f20,0x61765f6c61636f6c,0x5f31333536325f72,0x6b636f6c625f3035\n"
".quad 0x636f6c2e090a3b59,0x0934313109373109,0x656257444c240a30,0x38315a5f5f6e6967\n"
".quad 0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x7663090a3a626969,0x31752e3233752e74,0x202c317225092036\n"
".quad 0x0a3b782e64697425,0x3233752e766f6d09,0x30202c3272250920,0x2e70746573090a3b\n"
".quad 0x09203233752e7165,0x317225202c317025,0x090a3b327225202c,0x2e3233752e747663\n"
".quad 0x3372250920363175,0x792e64697425202c,0x752e766f6d090a3b,0x2c34722509203233\n"
".quad 0x746573090a3b3020,0x3233752e71652e70,0x25202c3270250920,0x3b347225202c3372\n"
".quad 0x732e706c6573090a,0x2c35722509203233,0x25202c30202c3120,0x6c6573090a3b3170\n"
".quad 0x2509203233732e70,0x30202c31202c3672,0x090a3b327025202c,0x203233622e646e61\n"
".quad 0x7225202c37722509,0x0a3b367225202c35,0x3233752e766f6d09,0x30202c3872250920\n"
".quad 0x2e70746573090a3b,0x09203233732e7165,0x377225202c337025,0x090a3b387225202c\n"
".quad 0x6172622033702540,0x5f305f744c240920,0x2e090a3b36383939,0x3109373109636f6c\n"
".quad 0x6f6d090a30093132,0x2509203436752e76,0x6f6c62202c316472,0x65746e756f436b63\n"
".quad 0x2e766f6d090a3b72,0x3972250920323375,0x7461090a3b31202c,0x61626f6c672e6d6f\n"
".quad 0x33752e6464612e6c,0x2c30317225092032,0x2c5d316472255b20,0x6d090a3b39722520\n"
".quad 0x09203233732e766f,0x7225202c31317225,0x2e7473090a3b3031,0x752e646572616873\n"
".quad 0x635f5f5b09203233,0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f303335\n"
".quad 0x65646e496b636f6c,0x31317225202c5d78,0x09636f6c2e090a3b,0x3009323231093731\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c32317225,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f305344,0x3472616863753650\n"
".quad 0x6666666666696969,0x696969695f536666,0x6957646972675f62,0x72090a3b5d687464\n"
".quad 0x09203233752e6d65,0x7225202c33317225,0x32317225202c3131,0x68732e7473090a3b\n"
".quad 0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x333536325f726176\n"
".quad 0x6f6c625f32345f31,0x7225202c5d586b63,0x6f6c2e090a3b3331,0x3332310937310963\n"
".quad 0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34,0x090a3b3231722520\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x355f31333536325f,0x596b636f6c625f30,0x3b34317225202c5d,0x395f305f744c240a\n"
".quad 0x6c2e090a3a363839,0x323109373109636f,0x726162090a300935,0x300920636e79732e\n"
".quad 0x61702e646c090a3b,0x203233752e6d6172,0x5b202c3531722509,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f30534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x6c426d756e5f6269,0x090a3b5d736b636f\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5f5b202c363172,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f32345f30333536,0x646e496b636f6c62,0x6573090a3b5d7865\n"
".quad 0x33752e65672e7074,0x202c347025092032,0x7225202c36317225,0x702540090a3b3531\n"
".quad 0x2409206172622034,0x3430315f305f744c,0x2e646c090a3b3839,0x33732e6d61726170\n"
".quad 0x2c37317225092032,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38\n"
".quad 0x735f305344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x616d695f62696969,0x6c090a3b5d486567,0x2e6d617261702e64,0x3172250920323373\n"
".quad 0x75635f5f5b202c38,0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c\n"
".quad 0x75365033316d735f,0x6969693472616863,0x5366666666666666,0x695f62696969695f\n"
".quad 0x0a3b5d576567616d,0x3233752e74766309,0x722509203631752e,0x69746e25202c3931\n"
".quad 0x7663090a3b792e64,0x31752e3233752e74,0x2c30327225092036,0x782e6469746e2520\n"
".quad 0x5f305f744c240a3b,0x200a3a3031303131,0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20\n"
".quad 0x20656e696c207964,0x2e646c090a353231,0x752e646572616873,0x3132722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x333536325f726176,0x6f6c625f32345f31\n"
".quad 0x6d090a3b5d586b63,0x33752e6f6c2e6c75,0x2c32327225092032,0x25202c3132722520\n"
".quad 0x646c090a3b303272,0x2e6465726168732e,0x3272250920323375,0x75635f5f5b202c33\n"
".quad 0x6c61636f6c5f6164,0x3536325f7261765f,0x6c625f30355f3133,0x090a3b5d596b636f\n"
".quad 0x752e6f6c2e6c756d,0x3432722509203233,0x202c33327225202c,0x61090a3b39317225\n"
".quad 0x09203233752e6464,0x7225202c35327225,0x3b317225202c3232,0x33752e646461090a\n"
".quad 0x2c36327225092032,0x25202c3432722520,0x746573090a3b3372,0x2e3233752e74672e\n"
".quad 0x3272250920323373,0x2c37317225202c37,0x090a3b3632722520,0x203233732e67656e\n"
".quad 0x25202c3832722509,0x6573090a3b373272,0x3233752e74672e74,0x722509203233732e\n"
".quad 0x38317225202c3932,0x0a3b35327225202c,0x3233732e67656e09,0x202c303372250920\n"
".quad 0x61090a3b39327225,0x09203233622e646e,0x7225202c31337225,0x30337225202c3832\n"
".quad 0x752e766f6d090a3b,0x3233722509203233,0x6573090a3b30202c,0x33732e71652e7074\n"
".quad 0x202c357025092032,0x7225202c31337225,0x702540090a3b3233,0x2409206172622035\n"
".quad 0x3832315f305f744c,0x3c2f2f200a3b3230,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x35323120656e696c,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3031315f305f744c,0x636f6c2e090a3031,0x0930343109373109,0x722e747663090a30\n"
".quad 0x33732e3233662e6e,0x202c316625092032,0x6c090a3b35327225,0x2e6d617261702e64\n"
".quad 0x3266250920323366,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f305344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x63735f6269696969,0x6d090a3b5d656c61,0x09203233662e6c75,0x316625202c336625\n"
".quad 0x090a3b326625202c,0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c34\n"
".quad 0x5f5f6d7261706164,0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x785f62696969695f,0x090a3b5d3066664f\n"
".quad 0x203233662e646461,0x6625202c35662509,0x0a3b346625202c33,0x3233662e62757309\n"
".quad 0x25202c3666250920,0x3b336625202c3566,0x33662e627573090a,0x202c376625092032\n"
".quad 0x366625202c346625,0x662e627573090a3b,0x2c38662509203233,0x6625202c35662520\n"
".quad 0x2e627573090a3b36,0x3966250920323366,0x25202c336625202c,0x646461090a3b3866\n"
".quad 0x662509203233662e,0x2c376625202c3031,0x6c090a3b39662520,0x2e6d617261702e64\n"
".quad 0x3166250920323366,0x75635f5f5b202c31,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x305344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x785f62696969695f,0x090a3b5d3166664f,0x203233662e646461,0x25202c3231662509\n"
".quad 0x316625202c313166,0x2e646461090a3b30,0x3166250920323366,0x202c356625202c33\n"
".quad 0x73090a3b32316625,0x09203233662e6275,0x6625202c34316625,0x3b356625202c3331\n"
".quad 0x33662e627573090a,0x2c35316625092032,0x25202c3231662520,0x6c2e090a3b343166\n"
".quad 0x343109373109636f,0x747663090a300931,0x2e3233662e6e722e,0x3166250920323373\n"
".quad 0x3b36327225202c36,0x33662e6c756d090a,0x2c37316625092032,0x25202c3631662520\n"
".quad 0x2e646c090a3b3266,0x33662e6d61726170,0x2c38316625092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x664f795f62696969,0x6461090a3b5d3066\n"
".quad 0x2509203233662e64,0x316625202c393166,0x3b38316625202c37,0x33662e627573090a\n"
".quad 0x2c30326625092032,0x25202c3931662520,0x7573090a3b373166,0x2509203233662e62\n"
".quad 0x316625202c313266,0x3b30326625202c38,0x33662e627573090a,0x2c32326625092032\n"
".quad 0x25202c3931662520,0x7573090a3b303266,0x2509203233662e62,0x316625202c333266\n"
".quad 0x3b32326625202c37,0x33662e646461090a,0x2c34326625092032,0x25202c3132662520\n"
".quad 0x646c090a3b333266,0x662e6d617261702e,0x3532662509203233,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262,0x6375365033316d73\n"
".quad 0x6669696934726168,0x5f53666666666666,0x4f795f6269696969,0x61090a3b5d316666\n"
".quad 0x09203233662e6464,0x6625202c36326625,0x34326625202c3532,0x662e646461090a3b\n"
".quad 0x3732662509203233,0x202c39316625202c,0x73090a3b36326625,0x09203233662e6275\n"
".quad 0x6625202c38326625,0x39316625202c3732,0x662e627573090a3b,0x3932662509203233\n"
".quad 0x202c36326625202c,0x2e090a3b38326625,0x3109373109636f6c,0x646c090a30093434\n"
".quad 0x732e6d617261702e,0x2c33337225092038,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f305344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x4a73695f62696969,0x2e766f6d090a3b5d,0x3372250920323375\n"
".quad 0x73090a3b30202c34,0x732e71652e707465,0x2c36702509203233,0x25202c3333722520\n"
".quad 0x2540090a3b343372,0x0920617262203670,0x32315f305f744c24,0x2f2f200a3b343330\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x323120656e696c20\n"
".quad 0x2064616568202c35,0x2064656c6562616c,0x31315f305f744c24,0x6f6c2e090a303130\n"
".quad 0x3335320936310963,0x702e646c090a3009,0x3233662e6d617261,0x202c303366250920\n"
".quad 0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x5d504a785f626969\n"
".quad 0x09636f6c2e090a3b,0x3009353532093631,0x7261702e646c090a,0x09203233662e6d61\n"
".quad 0x5f5b202c31336625,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x33316d735f305344,0x3472616863753650,0x6666666666696969,0x696969695f536666\n"
".quad 0x0a3b5d504a795f62,0x363109636f6c2e09,0x090a300937353209,0x203233662e766f6d\n"
".quad 0x25202c3233662509,0x6c2e090a3b373266,0x353209363109636f,0x766f6d090a300938\n"
".quad 0x662509203233662e,0x39326625202c3333,0x09636f6c2e090a3b,0x3009393532093631\n"
".quad 0x33662e766f6d090a,0x2c34336625092032,0x090a3b3331662520,0x09363109636f6c2e\n"
".quad 0x6d090a3009303632,0x09203233662e766f,0x6625202c35336625,0x6f6c2e090a3b3531\n"
".quad 0x3136320936310963,0x2e766f6d090a3009,0x3366250920323366,0x3036346630202c36\n"
".quad 0x20203b3030343030,0x3138202f2f092020,0x2e6c756d090a3339,0x3366250920323366\n"
".quad 0x2c37326625202c37,0x090a3b3633662520,0x203233662e627573,0x25202c3833662509\n"
".quad 0x326625202c373366,0x2e627573090a3b37,0x3366250920323366,0x2c37336625202c39\n"
".quad 0x090a3b3833662520,0x203233662e627573,0x25202c3034662509,0x336625202c373266\n"
".quad 0x2e6c756d090a3b39,0x3466250920323366,0x2c37326625202c31,0x090a3b3732662520\n"
".quad 0x203233662e6c756d,0x25202c3234662509,0x326625202c373266,0x2e64616d090a3b39\n"
".quad 0x3466250920323366,0x2c37326625202c33,0x25202c3932662520,0x6461090a3b323466\n"
".quad 0x2509203233662e64,0x346625202c343466,0x3b33346625202c31,0x33662e6c756d090a\n"
".quad 0x2c35346625092032,0x25202c3933662520,0x7573090a3b393366,0x2509203233662e62\n"
".quad 0x346625202c363466,0x3b31346625202c35,0x33662e627573090a,0x2c37346625092032\n"
".quad 0x25202c3434662520,0x616d090a3b313466,0x2509203233662e64,0x336625202c383466\n"
".quad 0x2c30346625202c39,0x090a3b3634662520,0x203233662e627573,0x25202c3934662509\n"
".quad 0x346625202c343466,0x2e627573090a3b37,0x3566250920323366,0x2c33346625202c30\n"
".quad 0x090a3b3734662520,0x203233662e64616d,0x25202c3135662509,0x346625202c393366\n"
".quad 0x3b38346625202c30,0x33662e627573090a,0x2c32356625092032,0x25202c3134662520\n"
".quad 0x616d090a3b393466,0x2509203233662e64,0x346625202c333566,0x2c30346625202c30\n"
".quad 0x090a3b3135662520,0x203233662e646461,0x25202c3435662509,0x356625202c303566\n"
".quad 0x2e646461090a3b32,0x3566250920323366,0x2c33356625202c35,0x090a3b3435662520\n"
".quad 0x203233662e64616d,0x25202c3635662509,0x326625202c393266,0x3b35356625202c39\n"
".quad 0x33662e646461090a,0x2c37356625092032,0x25202c3434662520,0x6f6d090a3b363566\n"
".quad 0x2509203233662e76,0x356625202c383566,0x2e627573090a3b37,0x3566250920323366\n"
".quad 0x2c37356625202c39,0x090a3b3434662520,0x203233662e627573,0x25202c3036662509\n"
".quad 0x356625202c363566,0x636f6c2e090a3b39,0x0932363209363109,0x662e766f6d090a30\n"
".quad 0x3136662509203233,0x303036346630202c,0x2020203b30303430,0x393138202f2f0920\n"
".quad 0x662e6c756d090a33,0x3236662509203233,0x202c33316625202c,0x73090a3b31366625\n"
".quad 0x09203233662e6275,0x6625202c33366625,0x33316625202c3236,0x662e627573090a3b\n"
".quad 0x3436662509203233,0x202c32366625202c,0x73090a3b33366625,0x09203233662e6275\n"
".quad 0x6625202c35366625,0x34366625202c3331,0x662e6c756d090a3b,0x3636662509203233\n"
".quad 0x202c33316625202c,0x6d090a3b33316625,0x09203233662e6c75,0x6625202c37366625\n"
".quad 0x35316625202c3331,0x662e64616d090a3b,0x3836662509203233,0x202c33316625202c\n"
".quad 0x6625202c35316625,0x646461090a3b3736,0x662509203233662e,0x36366625202c3936\n"
".quad 0x0a3b38366625202c,0x3233662e6c756d09,0x202c303766250920,0x6625202c34366625\n"
".quad 0x627573090a3b3436,0x662509203233662e,0x30376625202c3137,0x0a3b36366625202c\n"
".quad 0x3233662e62757309,0x202c323766250920,0x6625202c39366625,0x64616d090a3b3636\n"
".quad 0x662509203233662e,0x34366625202c3337,0x202c35366625202c,0x73090a3b31376625\n"
".quad 0x09203233662e6275,0x6625202c34376625,0x32376625202c3936,0x662e627573090a3b\n"
".quad 0x3537662509203233,0x202c38366625202c,0x6d090a3b32376625,0x09203233662e6461\n"
".quad 0x6625202c36376625,0x35366625202c3436,0x0a3b33376625202c,0x3233662e62757309\n"
".quad 0x202c373766250920,0x6625202c36366625,0x64616d090a3b3437,0x662509203233662e\n"
".quad 0x35366625202c3837,0x202c35366625202c,0x61090a3b36376625,0x09203233662e6464\n"
".quad 0x6625202c39376625,0x37376625202c3537,0x662e646461090a3b,0x3038662509203233\n"
".quad 0x202c38376625202c,0x6d090a3b39376625,0x09203233662e6461,0x6625202c31386625\n"
".quad 0x35316625202c3531,0x0a3b30386625202c,0x3233662e64646109,0x202c323866250920\n"
".quad 0x6625202c39366625,0x766f6d090a3b3138,0x662509203233662e,0x32386625202c3338\n"
".quad 0x662e627573090a3b,0x3438662509203233,0x202c32386625202c,0x73090a3b39366625\n"
".quad 0x09203233662e6275,0x6625202c35386625,0x34386625202c3138,0x662e766f6d090a3b\n"
".quad 0x3638662509203233,0x303030306630202c,0x2020203b30303030,0x090a30202f2f0920\n"
".quad 0x203233662e766f6d,0x30202c3738662509,0x3030303030303066,0x2f09202020203b30\n"
".quad 0x617262090a30202f,0x4c240920696e752e,0x373731315f305f74,0x305f744c240a3b38\n"
".quad 0x0a3a34333032315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c35323120,0x6c6562616c206461,0x305f744c24206465\n"
".quad 0x090a30313031315f,0x09363109636f6c2e,0x6d090a3009353632,0x09203233662e766f\n"
".quad 0x6625202c30336625,0x6f6c2e090a3b3331,0x3636320936310963,0x2e766f6d090a3009\n"
".quad 0x3866250920323366,0x3b35316625202c37,0x3109636f6c2e090a,0x0a30093736320936\n"
".quad 0x3233662e766f6d09,0x202c313366250920,0x2e090a3b37326625,0x3209363109636f6c\n"
".quad 0x6f6d090a30093836,0x2509203233662e76,0x326625202c363866,0x636f6c2e090a3b39\n"
".quad 0x0936373209363109,0x662e766f6d090a30,0x3538662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3338662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x30306630202c3036,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c38356625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c35336625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x2e766f6d090a3020,0x3366250920323366,0x3030306630202c34,0x20203b3030303030\n"
".quad 0x0a30202f2f092020,0x3233662e766f6d09,0x202c333366250920,0x3030303030306630\n"
".quad 0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c323366\n"
".quad 0x3b30303030303030,0x202f2f0920202020,0x5f305f744c240a30,0x200a3a3837373131\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c353231,0x656c6562616c2064,0x5f305f744c242064,0x2e090a3031303131\n"
".quad 0x3209363109636f6c,0x646c090a30093038,0x732e6d617261702e,0x3533722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x72635f6269696969\n"
".quad 0x090a3b5d68636e75,0x203233732e627573,0x25202c3633722509,0x0a3b31202c353372\n"
".quad 0x3233752e766f6d09,0x202c373372250920,0x70746573090a3b31,0x203233732e71652e\n"
".quad 0x7225202c37702509,0x37337225202c3533,0x2037702540090a3b,0x744c240920617262\n"
".quad 0x38333334315f305f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c35323120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313031315f305f,0x33662e646461090a,0x2c38386625092032,0x25202c3338662520\n"
".quad 0x7573090a3b383566,0x2509203233662e62,0x386625202c393866,0x3b33386625202c38\n"
".quad 0x33662e627573090a,0x2c30396625092032,0x25202c3838662520,0x7573090a3b393866\n"
".quad 0x2509203233662e62,0x356625202c313966,0x3b39386625202c38,0x33662e627573090a\n"
".quad 0x2c32396625092032,0x25202c3338662520,0x6461090a3b303966,0x2509203233662e64\n"
".quad 0x396625202c333966,0x3b32396625202c31,0x33662e646461090a,0x2c34396625092032\n"
".quad 0x25202c3339662520,0x6461090a3b353866,0x2509203233662e64,0x396625202c353966\n"
".quad 0x3b30366625202c34,0x33662e646461090a,0x2c36396625092032,0x25202c3838662520\n"
".quad 0x7573090a3b353966,0x2509203233662e62,0x396625202c373966,0x3b38386625202c36\n"
".quad 0x33662e627573090a,0x2c38396625092032,0x25202c3539662520,0x6461090a3b373966\n"
".quad 0x2509203233662e64,0x396625202c393966,0x3b38396625202c36,0x33662e766f6d090a\n"
".quad 0x3030316625092032,0x303830346630202c,0x2020203b30303030,0x73090a34202f2f09\n"
".quad 0x662e746c2e707465,0x2c38702509203233,0x25202c3939662520,0x40090a3b30303166\n"
".quad 0x6172622038702521,0x5f305f744c240920,0x200a3b3833333431,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c353231\n"
".quad 0x656c6562616c2064,0x5f305f744c242064,0x6d090a3031303131,0x09203233662e766f\n"
".quad 0x30202c3130316625,0x3034303030363466,0x2f2f092020203b30,0x6d090a3339313820\n"
".quad 0x09203233662e6c75,0x25202c3230316625,0x316625202c343366,0x766f6d090a3b3130\n"
".quad 0x662509203233662e,0x346630202c333031,0x3b30303430303036,0x38202f2f09202020\n"
".quad 0x6c756d090a333931,0x662509203233662e,0x336625202c343031,0x3330316625202c32\n"
".quad 0x662e627573090a3b,0x3031662509203233,0x3230316625202c35,0x0a3b34336625202c\n"
".quad 0x3233662e62757309,0x2c36303166250920,0x202c343031662520,0x73090a3b32336625\n"
".quad 0x09203233662e6275,0x25202c3730316625,0x6625202c32303166,0x7573090a3b353031\n"
".quad 0x2509203233662e62,0x6625202c38303166,0x316625202c343031,0x627573090a3b3630\n"
".quad 0x662509203233662e,0x336625202c393031,0x3730316625202c34,0x662e627573090a3b\n"
".quad 0x3131662509203233,0x2c32336625202c30,0x0a3b383031662520,0x3639385f305f4c24\n"
".quad 0x6c3c2f2f200a3a32,0x6f6f4c203e706f6f,0x6c2079646f622070,0x0a31383220656e69\n"
".quad 0x363109636f6c2e09,0x090a300931383209,0x203233662e6c756d,0x202c313131662509\n"
".quad 0x6625202c35336625,0x6c756d090a3b3233,0x662509203233662e,0x336625202c323131\n"
".quad 0x3b32336625202c34,0x33662e64616d090a,0x3331316625092032,0x202c34336625202c\n"
".quad 0x6625202c33336625,0x6461090a3b313131,0x2509203233662e64,0x6625202c34313166\n"
".quad 0x316625202c323131,0x627573090a3b3331,0x662509203233662e,0x316625202c353131\n"
".quad 0x31316625202c3431,0x2e6c756d090a3b32,0x3166250920323366,0x30316625202c3631\n"
".quad 0x3830316625202c37,0x662e627573090a3b,0x3131662509203233,0x3631316625202c37\n"
".quad 0x3b3231316625202c,0x33662e627573090a,0x3831316625092032,0x2c3331316625202c\n"
".quad 0x0a3b353131662520,0x3233662e62757309,0x2c39313166250920,0x202c343131662520\n"
".quad 0x090a3b3531316625,0x203233662e64616d,0x202c303231662509,0x25202c3730316625\n"
".quad 0x6625202c30313166,0x7573090a3b373131,0x2509203233662e62,0x6625202c31323166\n"
".quad 0x316625202c323131,0x64616d090a3b3931,0x662509203233662e,0x316625202c323231\n"
".quad 0x30316625202c3830,0x3032316625202c39,0x662e646461090a3b,0x3231662509203233\n"
".quad 0x3831316625202c33,0x3b3132316625202c,0x33662e64616d090a,0x3432316625092032\n"
".quad 0x2c3930316625202c,0x202c303131662520,0x090a3b3232316625,0x203233662e646461\n"
".quad 0x202c353231662509,0x25202c3332316625,0x6d090a3b34323166,0x09203233662e6461\n"
".quad 0x25202c3632316625,0x336625202c353366,0x3532316625202c33,0x662e646461090a3b\n"
".quad 0x3231662509203233,0x3431316625202c37,0x3b3632316625202c,0x33662e627573090a\n"
".quad 0x3832316625092032,0x2c3732316625202c,0x0a3b343131662520,0x3233662e62757309\n"
".quad 0x2c39323166250920,0x202c363231662520,0x090a3b3832316625,0x09363109636f6c2e\n"
".quad 0x61090a3009323832,0x09203233662e6464,0x25202c3033316625,0x6625202c37323166\n"
".quad 0x7573090a3b373231,0x2509203233662e62,0x6625202c31333166,0x316625202c303331\n"
".quad 0x627573090a3b3732,0x662509203233662e,0x316625202c323331,0x33316625202c3732\n"
".quad 0x2e627573090a3b31,0x3166250920323366,0x33316625202c3333,0x3133316625202c30\n"
".quad 0x662e627573090a3b,0x3331662509203233,0x3732316625202c34,0x3b3333316625202c\n"
".quad 0x33662e646461090a,0x3533316625092032,0x2c3233316625202c,0x0a3b343331662520\n"
".quad 0x3233662e64646109,0x2c36333166250920,0x202c353331662520,0x090a3b3932316625\n"
".quad 0x203233662e646461,0x202c373331662509,0x25202c3633316625,0x61090a3b39323166\n"
".quad 0x09203233662e6464,0x25202c3833316625,0x6625202c30333166,0x7573090a3b373331\n"
".quad 0x2509203233662e62,0x6625202c39333166,0x316625202c383331,0x627573090a3b3033\n"
".quad 0x662509203233662e,0x316625202c303431,0x33316625202c3733,0x636f6c2e090a3b39\n"
".quad 0x0933383209363109,0x662e646461090a30,0x3431662509203233,0x3833316625202c31\n"
".quad 0x0a3b31336625202c,0x3233662e62757309,0x2c32343166250920,0x202c313431662520\n"
".quad 0x090a3b3833316625,0x203233662e627573,0x202c333431662509,0x25202c3134316625\n"
".quad 0x73090a3b32343166,0x09203233662e6275,0x25202c3434316625,0x316625202c313366\n"
".quad 0x627573090a3b3234,0x662509203233662e,0x316625202c353431,0x34316625202c3833\n"
".quad 0x2e646461090a3b33,0x3166250920323366,0x34316625202c3634,0x3534316625202c34\n"
".quad 0x662e646461090a3b,0x3431662509203233,0x3634316625202c37,0x3b3034316625202c\n"
".quad 0x33662e646461090a,0x3834316625092032,0x2c3734316625202c,0x090a3b3638662520\n"
".quad 0x203233662e646461,0x202c393431662509,0x25202c3134316625,0x6d090a3b38343166\n"
".quad 0x09203233662e766f,0x6625202c32336625,0x7573090a3b393431,0x2509203233662e62\n"
".quad 0x6625202c30353166,0x316625202c393431,0x627573090a3b3134,0x662509203233662e\n"
".quad 0x34316625202c3333,0x3035316625202c38,0x09636f6c2e090a3b,0x3009363832093631\n"
".quad 0x33662e627573090a,0x3135316625092032,0x202c33386625202c,0x73090a3b38356625\n"
".quad 0x09203233662e6275,0x25202c3235316625,0x6625202c31353166,0x627573090a3b3338\n"
".quad 0x662509203233662e,0x316625202c333531,0x35316625202c3135,0x2e646461090a3b32\n"
".quad 0x3166250920323366,0x35316625202c3435,0x3b38356625202c32,0x33662e627573090a\n"
".quad 0x3535316625092032,0x202c33386625202c,0x090a3b3335316625,0x203233662e627573\n"
".quad 0x202c363531662509,0x25202c3535316625,0x61090a3b34353166,0x09203233662e6464\n"
".quad 0x25202c3735316625,0x6625202c36353166,0x627573090a3b3538,0x662509203233662e\n"
".quad 0x316625202c383531,0x30366625202c3735,0x662e646461090a3b,0x3531662509203233\n"
".quad 0x3135316625202c39,0x3b3835316625202c,0x33662e646461090a,0x3036316625092032\n"
".quad 0x2c3935316625202c,0x090a3b3033662520,0x203233662e627573,0x202c313631662509\n"
".quad 0x25202c3036316625,0x73090a3b39353166,0x09203233662e6275,0x25202c3236316625\n"
".quad 0x6625202c30363166,0x7573090a3b313631,0x2509203233662e62,0x6625202c33363166\n"
".quad 0x316625202c393531,0x627573090a3b3236,0x662509203233662e,0x336625202c343631\n"
".quad 0x3136316625202c30,0x662e646461090a3b,0x3631662509203233,0x3336316625202c35\n"
".quad 0x3b3436316625202c,0x33662e627573090a,0x3636316625092032,0x2c3935316625202c\n"
".quad 0x0a3b313531662520,0x3233662e62757309,0x2c37363166250920,0x202c383531662520\n"
".quad 0x090a3b3636316625,0x203233662e646461,0x202c383631662509,0x25202c3536316625\n"
".quad 0x61090a3b37363166,0x09203233662e6464,0x25202c3936316625,0x316625202c373866\n"
".quad 0x646461090a3b3836,0x662509203233662e,0x316625202c303731,0x36316625202c3036\n"
".quad 0x2e766f6d090a3b39,0x3366250920323366,0x3037316625202c34,0x662e627573090a3b\n"
".quad 0x3731662509203233,0x3037316625202c31,0x3b3036316625202c,0x33662e627573090a\n"
".quad 0x2c35336625092032,0x202c393631662520,0x090a3b3137316625,0x09363109636f6c2e\n"
".quad 0x6d090a3009383832,0x09203233662e766f,0x30202c3237316625,0x3034303030363466\n"
".quad 0x2f2f092020203b30,0x6d090a3339313820,0x09203233662e6c75,0x25202c3337316625\n"
".quad 0x6625202c39343166,0x756d090a3b323731,0x2509203233662e6c,0x6625202c34373166\n"
".quad 0x336625202c393431,0x2e6c756d090a3b33,0x3166250920323366,0x34316625202c3537\n"
".quad 0x3934316625202c39,0x662e627573090a3b,0x3731662509203233,0x3337316625202c36\n"
".quad 0x3b3934316625202c,0x33662e64616d090a,0x3737316625092032,0x2c3934316625202c\n"
".quad 0x25202c3333662520,0x73090a3b34373166,0x09203233662e6275,0x25202c3830316625\n"
".quad 0x6625202c33373166,0x6461090a3b363731,0x2509203233662e64,0x6625202c38373166\n"
".quad 0x316625202c353731,0x627573090a3b3737,0x662509203233662e,0x316625202c303131\n"
".quad 0x30316625202c3934,0x2e6c756d090a3b38,0x3166250920323366,0x30316625202c3937\n"
".quad 0x3830316625202c38,0x662e627573090a3b,0x3831662509203233,0x3937316625202c30\n"
".quad 0x3b3537316625202c,0x33662e627573090a,0x3138316625092032,0x2c3837316625202c\n"
".quad 0x0a3b353731662520,0x3233662e64616d09,0x2c32383166250920,0x202c383031662520\n"
".quad 0x25202c3031316625,0x73090a3b30383166,0x09203233662e6275,0x25202c3338316625\n"
".quad 0x6625202c37373166,0x7573090a3b313831,0x2509203233662e62,0x6625202c34383166\n"
".quad 0x316625202c383731,0x64616d090a3b3138,0x662509203233662e,0x316625202c353831\n"
".quad 0x31316625202c3830,0x3238316625202c30,0x662e627573090a3b,0x3831662509203233\n"
".quad 0x3537316625202c36,0x3b3438316625202c,0x33662e64616d090a,0x3738316625092032\n"
".quad 0x2c3031316625202c,0x202c303131662520,0x090a3b3538316625,0x203233662e646461\n"
".quad 0x202c383831662509,0x25202c3338316625,0x61090a3b36383166,0x09203233662e6464\n"
".quad 0x25202c3938316625,0x6625202c37383166,0x616d090a3b383831,0x2509203233662e64\n"
".quad 0x6625202c30393166,0x33336625202c3333,0x3b3938316625202c,0x33662e646461090a\n"
".quad 0x3139316625092032,0x2c3837316625202c,0x0a3b303931662520,0x3233662e766f6d09\n"
".quad 0x202c383566250920,0x090a3b3139316625,0x203233662e627573,0x202c323931662509\n"
".quad 0x25202c3139316625,0x73090a3b38373166,0x09203233662e6275,0x6625202c30366625\n"
".quad 0x316625202c303931,0x6f6c2e090a3b3239,0x3938320936310963,0x2e766f6d090a3009\n"
".quad 0x3166250920323366,0x36346630202c3339,0x203b303034303030,0x3138202f2f092020\n"
".quad 0x2e6c756d090a3339,0x3166250920323366,0x37316625202c3439,0x3339316625202c30\n"
".quad 0x662e6c756d090a3b,0x3931662509203233,0x3037316625202c35,0x0a3b35336625202c\n"
".quad 0x3233662e6c756d09,0x2c36393166250920,0x202c303731662520,0x090a3b3037316625\n"
".quad 0x203233662e627573,0x202c373931662509,0x25202c3439316625,0x6d090a3b30373166\n"
".quad 0x09203233662e6461,0x25202c3839316625,0x6625202c30373166,0x39316625202c3533\n"
".quad 0x2e627573090a3b35,0x3166250920323366,0x39316625202c3730,0x3739316625202c34\n"
".quad 0x662e646461090a3b,0x3931662509203233,0x3639316625202c39,0x3b3839316625202c\n"
".quad 0x33662e627573090a,0x3930316625092032,0x2c3037316625202c,0x0a3b373031662520\n"
".quad 0x3233662e6c756d09,0x2c30303266250920,0x202c373031662520,0x090a3b3730316625\n"
".quad 0x203233662e627573,0x202c313032662509,0x25202c3030326625,0x73090a3b36393166\n"
".quad 0x09203233662e6275,0x25202c3230326625,0x6625202c39393166,0x616d090a3b363931\n"
".quad 0x2509203233662e64,0x6625202c33303266,0x316625202c373031,0x30326625202c3930\n"
".quad 0x2e627573090a3b31,0x3266250920323366,0x39316625202c3430,0x3230326625202c38\n"
".quad 0x662e627573090a3b,0x3032662509203233,0x3939316625202c35,0x3b3230326625202c\n"
".quad 0x33662e64616d090a,0x3630326625092032,0x2c3730316625202c,0x202c393031662520\n"
".quad 0x090a3b3330326625,0x203233662e627573,0x202c373032662509,0x25202c3639316625\n"
".quad 0x6d090a3b35303266,0x09203233662e6461,0x25202c3830326625,0x6625202c39303166\n"
".quad 0x326625202c393031,0x646461090a3b3630,0x662509203233662e,0x326625202c393032\n"
".quad 0x30326625202c3430,0x2e646461090a3b37,0x3266250920323366,0x30326625202c3031\n"
".quad 0x3930326625202c38,0x662e64616d090a3b,0x3132662509203233,0x2c35336625202c31\n"
".quad 0x25202c3533662520,0x61090a3b30313266,0x09203233662e6464,0x25202c3231326625\n"
".quad 0x6625202c39393166,0x6f6d090a3b313132,0x2509203233662e76,0x326625202c333866\n"
".quad 0x627573090a3b3231,0x662509203233662e,0x326625202c333132,0x39316625202c3231\n"
".quad 0x2e627573090a3b39,0x3866250920323366,0x3131326625202c35,0x3b3331326625202c\n"
".quad 0x3109636f6c2e090a,0x0a30093039320936,0x3233662e64646109,0x2c34313266250920\n"
".quad 0x202c313931662520,0x090a3b3231326625,0x203233662e627573,0x202c353132662509\n"
".quad 0x25202c3431326625,0x73090a3b32313266,0x09203233662e6275,0x25202c3631326625\n"
".quad 0x6625202c31393166,0x7573090a3b353132,0x2509203233662e62,0x6625202c37313266\n"
".quad 0x326625202c343132,0x627573090a3b3531,0x662509203233662e,0x326625202c383132\n"
".quad 0x31326625202c3231,0x2e646461090a3b37,0x3266250920323366,0x31326625202c3931\n"
".quad 0x3831326625202c36,0x662e646461090a3b,0x3232662509203233,0x2c35386625202c30\n"
".quad 0x0a3b393132662520,0x3233662e64646109,0x2c31323266250920,0x25202c3036662520\n"
".quad 0x61090a3b30323266,0x09203233662e6464,0x25202c3232326625,0x6625202c34313266\n"
".quad 0x7573090a3b313232,0x2509203233662e62,0x6625202c33323266,0x326625202c323232\n"
".quad 0x627573090a3b3431,0x662509203233662e,0x326625202c343232,0x32326625202c3132\n"
".quad 0x636f6c2e090a3b33,0x0930383209363109,0x732e627573090a30,0x3633722509203233\n"
".quad 0x202c36337225202c,0x2e766f6d090a3b31,0x3372250920323375,0x73090a3b30202c38\n"
".quad 0x732e71652e707465,0x2c39702509203233,0x25202c3633722520,0x2540090a3b383372\n"
".quad 0x0920617262203970,0x34315f305f744c24,0x2f2f200a3b383333,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x383220656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x3639385f305f4c24,0x662e646461090a32,0x3232662509203233\n"
".quad 0x3432326625202c35,0x3b3232326625202c,0x33662e766f6d090a,0x3632326625092032\n"
".quad 0x303830346630202c,0x2020203b30303030,0x73090a34202f2f09,0x662e746c2e707465\n"
".quad 0x3031702509203233,0x2c3532326625202c,0x0a3b363232662520,0x6220303170254009\n"
".quad 0x305f4c2409206172,0x240a3b323639385f,0x3334315f305f744c,0x305f4c240a3a3833\n"
".quad 0x200a3a383132395f,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x616568202c353231,0x656c6562616c2064,0x5f305f744c242064\n"
".quad 0x2e090a3031303131,0x3109373109636f6c,0x6f6d090a30093434,0x2509203233732e76\n"
".quad 0x0a3b30202c393372,0x74672e7074657309,0x702509203233732e,0x36337225202c3131\n"
".quad 0x0a3b39337225202c,0x363109636f6c2e09,0x090a300930383209,0x6d617261702e646c\n"
".quad 0x722509203233732e,0x635f5f5b202c3533,0x5f6d726170616475,0x646e614d38315a5f\n"
".quad 0x5344746f72626c65,0x365033316d735f30,0x6969347261686375,0x6666666666666669\n"
".quad 0x5f62696969695f53,0x3b5d68636e757263,0x3109636f6c2e090a,0x0a30093434310937\n"
".quad 0x3233732e62757309,0x202c303472250920,0x7225202c35337225,0x766f6d090a3b3633\n"
".quad 0x722509203233732e,0x090a3b30202c3134,0x3233732e706c6573,0x202c323472250920\n"
".quad 0x7225202c30347225,0x31317025202c3134,0x752e766f6d090a3b,0x3334722509203233\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x2c32317025092032,0x25202c3234722520\n"
".quad 0x2540090a3b333472,0x2061726220323170,0x315f305f744c2409,0x2f200a3b36343532\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079\n"
".quad 0x64616568202c3532,0x64656c6562616c20,0x315f305f744c2420,0x6c2e090a30313031\n"
".quad 0x353109373109636f,0x2e646c090a300931,0x33732e6d61726170,0x2c34347225092032\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72\n"
".quad 0x686375365033316d,0x6666696969347261,0x695f536666666666,0x696e615f62696969\n"
".quad 0x72466e6f6974616d,0x61090a3b5d656d61,0x09203233732e6464,0x7225202c35347225\n"
".quad 0x32347225202c3434,0x61702e646c090a3b,0x092038752e6d6172,0x5f5b202c36347225\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f305344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x73726f6c6f635f62\n"
".quad 0x756d090a3b5d302b,0x3233732e6f6c2e6c,0x202c373472250920,0x7225202c35347225\n"
".quad 0x747663090a3b3634,0x203233752e38752e,0x25202c3834722509,0x6c2e090a3b373472\n"
".quad 0x353109373109636f,0x2e646c090a300932,0x38752e6d61726170,0x202c393472250920\n"
".quad 0x70616475635f5f5b,0x38315a5f5f6d7261,0x72626c65646e614d,0x6d735f305344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x6f6c6f635f626969\n"
".quad 0x090a3b5d312b7372,0x732e6f6c2e6c756d,0x3035722509203233,0x202c35347225202c\n"
".quad 0x63090a3b39347225,0x33752e38752e7476,0x2c31357225092032,0x090a3b3035722520\n"
".quad 0x09373109636f6c2e,0x6c090a3009333531,0x2e6d617261702e64,0x3235722509203875\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f305344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x6f635f6269696969\n"
".quad 0x3b5d322b73726f6c,0x6f6c2e6c756d090a,0x722509203233732e,0x35347225202c3335\n"
".quad 0x0a3b32357225202c,0x2e38752e74766309,0x3572250920323375,0x3b33357225202c34\n"
".quad 0x6e752e617262090a,0x305f744c24092069,0x0a3b30393232315f,0x32315f305f744c24\n"
".quad 0x2f2f200a3a363435,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x323120656e696c20,0x2064616568202c35,0x2064656c6562616c,0x31315f305f744c24\n"
".quad 0x6f6c2e090a303130,0x3735310937310963,0x2e766f6d090a3009,0x3572250920323375\n"
".quad 0x6d090a3b30202c34,0x09203233752e766f,0x3b30202c31357225,0x33752e766f6d090a\n"
".quad 0x2c38347225092032,0x5f744c240a3b3020,0x3a30393232315f30,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3532312065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a30313031315f30,0x617261702e646c09\n"
".quad 0x2509203436752e6d,0x5f5f5b202c326472,0x6d72617061647563,0x6e614d38315a5f5f\n"
".quad 0x44746f72626c6564,0x5033316d735f3053,0x6934726168637536,0x6666666666666969\n"
".quad 0x62696969695f5366,0x090a3b5d7473645f,0x732e6f6c2e6c756d,0x3535722509203233\n"
".quad 0x202c38317225202c,0x61090a3b36327225,0x09203233732e6464,0x7225202c36357225\n"
".quad 0x35357225202c3532,0x732e747663090a3b,0x09203233732e3436,0x7225202c33647225\n"
".quad 0x6c756d090a3b3635,0x33732e656469772e,0x2c34647225092032,0x34202c3635722520\n"
".quad 0x752e646461090a3b,0x3564722509203436,0x202c32647225202c,0x6c090a3b34647225\n"
".quad 0x2e6d617261702e64,0x3572250920323373,0x75635f5f5b202c37,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x665f62696969695f,0x090a3b5d656d6172,0x203233752e766f6d\n"
".quad 0x30202c3835722509,0x2e70746573090a3b,0x09203233732e656e,0x7225202c33317025\n"
".quad 0x38357225202c3735,0x3331702540090a3b,0x4c24092061726220,0x353033315f305f74\n"
".quad 0x6c3c2f2f200a3b38,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c35323120656e69,0x616c206461656820,0x4c242064656c6562,0x313031315f305f74\n"
".quad 0x09636f6c2e090a30,0x3009343631093731,0x33752e766f6d090a,0x2c39357225092032\n"
".quad 0x2e7473090a3b3020,0x762e6c61626f6c67,0x255b092038752e34,0x202c5d302b356472\n"
".quad 0x72252c383472257b,0x2c343572252c3135,0x090a3b7d39357225,0x20696e752e617262\n"
".quad 0x315f305f744c2409,0x4c240a3b32303832,0x353033315f305f74,0x6c3c2f2f200a3a38\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c35323120656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x313031315f305f74,0x09636f6c2e090a30\n"
".quad 0x3009373531093731,0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c37357225\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f305344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x5d656d6172665f62\n"
".quad 0x09636f6c2e090a3b,0x3009383631093731,0x33732e646461090a,0x2c30367225092032\n"
".quad 0x31202c3735722520,0x732e726873090a3b,0x3136722509203233,0x202c30367225202c\n"
".quad 0x766f6d090a3b3133,0x722509203233732e,0x090a3b31202c3236,0x203233622e646e61\n"
".quad 0x25202c3336722509,0x367225202c313672,0x2e646461090a3b32,0x3672250920323373\n"
".quad 0x2c33367225202c34,0x090a3b3036722520,0x203233732e726873,0x25202c3536722509\n"
".quad 0x0a3b31202c343672,0x626f6c672e646c09,0x38752e34762e6c61,0x2c363672257b0920\n"
".quad 0x3672252c37367225,0x255b202c7d5f2c38,0x0a3b5d302b356472,0x2e6f6c2e6c756d09\n"
".quad 0x3672250920323373,0x2c37357225202c39,0x090a3b3636722520,0x203233732e646461\n"
".quad 0x25202c3037722509,0x367225202c383472,0x2e646461090a3b39,0x3772250920323373\n"
".quad 0x2c35367225202c31,0x090a3b3037722520,0x203233732e766964,0x25202c3237722509\n"
".quad 0x367225202c313772,0x636f6c2e090a3b30,0x0939363109373109,0x6c2e6c756d090a30\n"
".quad 0x2509203233732e6f,0x357225202c333772,0x3b37367225202c37,0x33732e646461090a\n"
".quad 0x2c34377225092032,0x25202c3135722520,0x6461090a3b333772,0x2509203233732e64\n"
".quad 0x367225202c353772,0x3b34377225202c35,0x33732e766964090a,0x2c36377225092032\n"
".quad 0x25202c3537722520,0x7473090a3b303672,0x2e6c61626f6c672e,0x5b092038752e3276\n"
".quad 0x2c5d302b35647225,0x252c323772257b20,0x2e090a3b7d363772,0x3109373109636f6c\n"
".quad 0x756d090a30093037,0x3233732e6f6c2e6c,0x202c373772250920,0x7225202c37357225\n"
".quad 0x646461090a3b3836,0x722509203233732e,0x34357225202c3837,0x0a3b37377225202c\n"
".quad 0x3233732e64646109,0x202c393772250920,0x7225202c35367225,0x766964090a3b3837\n"
".quad 0x722509203233732e,0x39377225202c3038,0x0a3b30367225202c,0x626f6c672e747309\n"
".quad 0x5b092038752e6c61,0x2c5d322b35647225,0x240a3b3038722520,0x3832315f305f744c\n"
".quad 0x5f744c240a3a3230,0x3a36363231315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3532312065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a30313031315f30,0x373109636f6c2e09,0x090a300933373109\n"
".quad 0x636e79732e726162,0x6f6d090a3b300920,0x2509203233752e76,0x0a3b30202c313872\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c377225202c3431,0x090a3b3138722520\n"
".quad 0x7262203431702540,0x305f744c24092061,0x0a3b34313333315f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c35323120\n"
".quad 0x6c6562616c206461,0x305f744c24206465,0x090a30313031315f,0x09373109636f6c2e\n"
".quad 0x6d090a3009363731,0x09203436752e766f,0x6c62202c36647225,0x746e756f436b636f\n"
".quad 0x766f6d090a3b7265,0x722509203233752e,0x090a3b31202c3238,0x6f6c672e6d6f7461\n"
".quad 0x2e6464612e6c6162,0x3872250920323375,0x366472255b202c33,0x3b32387225202c5d\n"
".quad 0x33732e766f6d090a,0x2c34387225092032,0x090a3b3338722520,0x65726168732e7473\n"
".quad 0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f,0x345f30333536325f\n"
".quad 0x496b636f6c625f32,0x25202c5d7865646e,0x6c2e090a3b343872,0x373109373109636f\n"
".quad 0x2e646c090a300937,0x33752e6d61726170,0x2c35387225092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x6972675f62696969,0x3b5d687464695764\n"
".quad 0x33752e6d6572090a,0x2c36387225092032,0x25202c3438722520,0x7473090a3b353872\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f32345f31333536,0x2c5d586b636f6c62,0x090a3b3638722520,0x09373109636f6c2e\n"
".quad 0x64090a3009383731,0x09203233752e7669,0x7225202c37387225,0x35387225202c3438\n"
".quad 0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61\n"
".quad 0x333536325f726176,0x6f6c625f30355f31,0x7225202c5d596b63,0x5f744c240a3b3738\n"
".quad 0x3a34313333315f30,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3532312065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a30313031315f30,0x373109636f6c2e09,0x090a300930383109,0x636e79732e726162\n"
".quad 0x646c090a3b300920,0x2e6465726168732e,0x3872250920323375,0x75635f5f5b202c38\n"
".quad 0x6c61636f6c5f6164,0x3536325f7261765f,0x6c625f32345f3033,0x7865646e496b636f\n"
".quad 0x70746573090a3b5d,0x203233752e746c2e,0x25202c3531702509,0x317225202c383872\n"
".quad 0x31702540090a3b35,0x2409206172622035,0x3031315f305f744c,0x5f744c240a3b3031\n"
".quad 0x3a38393430315f30,0x3109636f6c2e090a,0x0a30093338310937,0x240a3b7469786509\n"
".quad 0x5f5f646e6557444c,0x65646e614d38315a,0x305344746f72626c,0x75365033316d735f\n"
".quad 0x6969693472616863,0x5366666666666666,0x0a3a62696969695f,0x5a5f202f2f207d09\n"
".quad 0x6c65646e614d3831,0x5f305344746f7262,0x6375365033316d73,0x6669696934726168\n"
".quad 0x5f53666666666666,0x090a0a6269696969,0x5f207972746e652e,0x65646e614d38315a\n"
".quad 0x315344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x282062696969695f,0x617261702e09090a,0x5f203436752e206d,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344,0x3472616863753650\n"
".quad 0x6666666666696969,0x696969695f536666,0x090a2c7473645f62,0x206d617261702e09\n"
".quad 0x635f5f203233732e,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f31,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x0a2c576567616d69,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5033316d735f3153,0x6934726168637536\n"
".quad 0x6666666666666969,0x62696969695f5366,0x2c486567616d695f,0x617261702e09090a\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x33316d735f315344,0x3472616863753650,0x6666666666696969,0x696969695f536666\n"
".quad 0x68636e7572635f62,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x3066664f785f6269,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x316d735f31534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x3166664f785f6269,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x3066664f795f6269,0x7261702e09090a2c\n"
".quad 0x203233662e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x316d735f31534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x3166664f795f6269,0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x0a2c504a785f6269,0x6d617261702e0909\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5033316d735f3153,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x09090a2c504a795f,0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164\n"
".quad 0x65646e614d38315a,0x315344746f72626c,0x75365033316d735f,0x6969693472616863\n"
".quad 0x5366666666666666,0x735f62696969695f,0x09090a2c656c6163,0x2e206d617261702e\n"
".quad 0x2034206e67696c61,0x75635f5f2038622e,0x5f5f6d7261706164,0x65646e614d38315a\n"
".quad 0x315344746f72626c,0x75365033316d735f,0x6969693472616863,0x5366666666666666\n"
".quad 0x635f62696969695f,0x5d345b73726f6c6f,0x7261702e09090a2c,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474\n"
".quad 0x7261686375365033,0x6666666669696934,0x6969695f53666666,0x656d6172665f6269\n"
".quad 0x7261702e09090a2c,0x203233732e206d61,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x616d696e615f6269,0x6d6172466e6f6974,0x61702e09090a2c65\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x38315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x6d735f315344746f,0x6168637536503331,0x6666666969693472,0x69695f5366666666\n"
".quad 0x646972675f626969,0x090a2c6874646957,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x6b636f6c426d756e\n"
".quad 0x61702e09090a2c73,0x2038732e206d6172,0x6170616475635f5f,0x4d38315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033,0x6666666669696934\n"
".quad 0x6969695f53666666,0x0a294a73695f6269,0x6765722e090a7b09,0x7225203233752e20\n"
".quad 0x65722e090a3b3176,0x25203233752e2067,0x0a3b3e3537313c72,0x752e206765722e09\n"
".quad 0x313c647225203436,0x65722e090a3b3e34,0x25203233662e2067,0x0a3b3e3832323c66\n"
".quad 0x702e206765722e09,0x323c702520646572,0x68732e090a3b3e31,0x33752e2064657261\n"
".quad 0x616475635f5f2032,0x765f6c61636f6c5f,0x39383636325f7261,0x636f6c625f32345f\n"
".quad 0x0a3b7865646e496b,0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f32345f30393636,0x0a3b586b636f6c62,0x6465726168732e09\n"
".quad 0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30355f30393636\n"
".quad 0x0a3b596b636f6c62,0x373109636f6c2e09,0x240a300933373209,0x6e6967656257444c\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5033316d735f3153,0x6934726168637536\n"
".quad 0x6666666666666969,0x62696969695f5366,0x752e747663090a3a,0x09203631752e3233\n"
".quad 0x697425202c317225,0x6f6d090a3b782e64,0x2509203233752e76,0x090a3b30202c3272\n"
".quad 0x2e71652e70746573,0x3170250920323375,0x25202c317225202c,0x747663090a3b3272\n"
".quad 0x3631752e3233752e,0x25202c3372250920,0x090a3b792e646974,0x203233752e766f6d\n"
".quad 0x3b30202c34722509,0x652e70746573090a,0x2509203233752e71,0x2c337225202c3270\n"
".quad 0x73090a3b34722520,0x203233732e706c65,0x2c31202c35722509,0x3b317025202c3020\n"
".quad 0x732e706c6573090a,0x2c36722509203233,0x25202c30202c3120,0x646e61090a3b3270\n"
".quad 0x722509203233622e,0x202c357225202c37,0x6f6d090a3b367225,0x2509203233752e76\n"
".quad 0x090a3b30202c3872,0x2e71652e70746573,0x3370250920323373,0x25202c377225202c\n"
".quad 0x702540090a3b3872,0x2409206172622033,0x3637315f315f744c,0x6f6c2e090a3b3636\n"
".quad 0x3138320937310963,0x2e766f6d090a3009,0x6472250920343675,0x6b636f6c62202c31\n"
".quad 0x3b7265746e756f43,0x33752e766f6d090a,0x202c397225092032,0x6d6f7461090a3b31\n"
".quad 0x2e6c61626f6c672e,0x203233752e646461,0x5b202c3031722509,0x25202c5d31647225\n"
".quad 0x766f6d090a3b3972,0x722509203233732e,0x30317225202c3131,0x68732e7473090a3b\n"
".quad 0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x383636325f726176\n"
".quad 0x6f6c625f32345f39,0x5d7865646e496b63,0x0a3b31317225202c,0x373109636f6c2e09\n"
".quad 0x090a300932383209,0x6d617261702e646c,0x722509203233752e,0x635f5f5b202c3231\n"
".quad 0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31\n"
".quad 0x6969347261686375,0x6666666666666669,0x5f62696969695f53,0x7464695764697267\n"
".quad 0x6d6572090a3b5d68,0x722509203233752e,0x31317225202c3331,0x0a3b32317225202c\n"
".quad 0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b,0x61765f6c61636f6c\n"
".quad 0x5f30393636325f72,0x6b636f6c625f3234,0x33317225202c5d58,0x09636f6c2e090a3b\n"
".quad 0x3009333832093731,0x33752e766964090a,0x2c34317225092032,0x25202c3131722520\n"
".quad 0x7473090a3b323172,0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30355f30393636,0x2c5d596b636f6c62,0x240a3b3431722520\n"
".quad 0x3637315f315f744c,0x6f6c2e090a3a3636,0x3638320937310963,0x2e726162090a3009\n"
".quad 0x3b300920636e7973,0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c35317225\n"
".quad 0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x6f6c426d756e5f62\n"
".quad 0x6c090a3b5d736b63,0x6465726168732e64,0x722509203233752e,0x635f5f5b202c3631\n"
".quad 0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f393836,0x65646e496b636f6c\n"
".quad 0x746573090a3b5d78,0x3233752e65672e70,0x25202c3470250920,0x317225202c363172\n"
".quad 0x34702540090a3b35,0x4c24092061726220,0x373138315f315f74,0x702e646c090a3b38\n"
".quad 0x3233732e6d617261,0x202c373172250920,0x70616475635f5f5b,0x38315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x67616d695f626969,0x646c090a3b5d4865,0x732e6d617261702e\n"
".quad 0x3831722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f315344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x6d695f6269696969,0x090a3b5d57656761,0x2e3233752e747663,0x3172250920363175\n"
".quad 0x6469746e25202c39,0x747663090a3b792e,0x3631752e3233752e,0x202c303272250920\n"
".quad 0x3b782e6469746e25,0x315f315f744c240a,0x2f200a3a30393638,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3220656e696c2079,0x732e646c090a3638,0x33752e6465726168\n"
".quad 0x2c31327225092032,0x616475635f5f5b20,0x765f6c61636f6c5f,0x30393636325f7261\n"
".quad 0x636f6c625f32345f,0x756d090a3b5d586b,0x3233752e6f6c2e6c,0x202c323272250920\n"
".quad 0x7225202c31327225,0x2e646c090a3b3032,0x752e646572616873,0x3332722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x393636325f726176,0x6f6c625f30355f30\n"
".quad 0x6d090a3b5d596b63,0x33752e6f6c2e6c75,0x2c34327225092032,0x25202c3332722520\n"
".quad 0x6461090a3b393172,0x2509203233752e64,0x327225202c353272,0x0a3b317225202c32\n"
".quad 0x3233752e64646109,0x202c363272250920,0x7225202c34327225,0x2e746573090a3b33\n"
".quad 0x732e3233752e7467,0x3732722509203233,0x202c37317225202c,0x6e090a3b36327225\n"
".quad 0x09203233732e6765,0x7225202c38327225,0x746573090a3b3732,0x2e3233752e74672e\n"
".quad 0x3272250920323373,0x2c38317225202c39,0x090a3b3532722520,0x203233732e67656e\n"
".quad 0x25202c3033722509,0x6e61090a3b393272,0x2509203233622e64,0x327225202c313372\n"
".quad 0x3b30337225202c38,0x33752e766f6d090a,0x2c32337225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x25202c3570250920,0x337225202c313372,0x35702540090a3b32\n"
".quad 0x4c24092061726220,0x303531325f315f74,0x6c3c2f2f200a3b36,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c36383220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x393638315f315f74,0x09636f6c2e090a30,0x3009303033093731\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x38317225202c3333,0x0a3b36327225202c\n"
".quad 0x3233732e64646109,0x202c343372250920,0x7225202c35327225,0x2e646c090a3b3333\n"
".quad 0x36752e6d61726170,0x2c32647225092034,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x7473645f62696969,0x2e747663090a3b5d,0x203233732e343673\n"
".quad 0x25202c3364722509,0x756d090a3b343372,0x732e656469772e6c,0x3464722509203233\n"
".quad 0x202c34337225202c,0x2e646461090a3b34,0x6472250920343675,0x2c32647225202c35\n"
".quad 0x090a3b3464722520,0x61626f6c672e646c,0x2038752e34762e6c,0x252c353372257b09\n"
".quad 0x373372252c363372,0x72255b202c7d5f2c,0x090a3b5d302b3564,0x203233752e766f6d\n"
".quad 0x30202c3833722509,0x2e70746573090a3b,0x09203233732e656c,0x327225202c367025\n"
".quad 0x3b38337225202c35,0x622036702540090a,0x5f744c2409206172,0x3b34313739315f31\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3638322065,0x6562616c20646165,0x5f744c242064656c,0x0a30393638315f31\n"
".quad 0x626f6c672e646c09,0x38752e34762e6c61,0x2c393372257b0920,0x3472252c30347225\n"
".quad 0x255b202c7d5f2c31,0x3b5d342d2b356472,0x3109636f6c2e090a,0x0a30093530330937\n"
".quad 0x3233732e62757309,0x202c323472250920,0x7225202c31347225,0x736261090a3b3733\n"
".quad 0x722509203233732e,0x32347225202c3334,0x732e766f6d090a3b,0x3434722509203233\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x347225202c353472\n"
".quad 0x3b34347225202c33,0x33732e67656e090a,0x2c36347225092032,0x090a3b3534722520\n"
".quad 0x203233732e627573,0x25202c3734722509,0x337225202c393372,0x2e736261090a3b35\n"
".quad 0x3472250920323373,0x3b37347225202c38,0x33732e766f6d090a,0x2c39347225092032\n"
".quad 0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e,0x38347225202c3035\n"
".quad 0x0a3b39347225202c,0x3233732e67656e09,0x202c313572250920,0x73090a3b30357225\n"
".quad 0x09203233732e6275,0x7225202c32357225,0x36337225202c3034,0x732e736261090a3b\n"
".quad 0x3335722509203233,0x0a3b32357225202c,0x3233732e766f6d09,0x202c343572250920\n"
".quad 0x746573090a3b3031,0x2e3233752e74672e,0x3572250920323373,0x2c33357225202c35\n"
".quad 0x090a3b3435722520,0x203233732e67656e,0x25202c3635722509,0x726f090a3b353572\n"
".quad 0x722509203233622e,0x31357225202c3735,0x0a3b36357225202c,0x203233622e726f09\n"
".quad 0x25202c3835722509,0x357225202c363472,0x2e617262090a3b37,0x744c240920696e75\n"
".quad 0x38353439315f315f,0x5f315f744c240a3b,0x200a3a3431373931,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x6d090a3039363831,0x09203233732e766f\n"
".quad 0x3b30202c38357225,0x315f315f744c240a,0x2f200a3a38353439,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3638\n"
".quad 0x64656c6562616c20,0x315f315f744c2420,0x6461090a30393638,0x2509203233732e64\n"
".quad 0x327225202c393572,0x73090a3b31202c35,0x732e656c2e707465,0x2c37702509203233\n"
".quad 0x25202c3831722520,0x2540090a3b393572,0x0920617262203770,0x39315f315f744c24\n"
".quad 0x2f2f200a3b303739,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x383220656e696c20,0x2064616568202c36,0x2064656c6562616c,0x38315f315f744c24\n"
".quad 0x2e646c090a303936,0x762e6c61626f6c67,0x257b092038752e34,0x313672252c303672\n"
".quad 0x7d5f2c323672252c,0x2b356472255b202c,0x6f6c2e090a3b5d34,0x3730330937310963\n"
".quad 0x2e627573090a3009,0x3672250920323373,0x2c32367225202c33,0x090a3b3733722520\n"
".quad 0x203233732e736261,0x25202c3436722509,0x6f6d090a3b333672,0x2509203233732e76\n"
".quad 0x3b3031202c353672,0x74672e746573090a,0x3233732e3233752e,0x202c363672250920\n"
".quad 0x7225202c34367225,0x67656e090a3b3536,0x722509203233732e,0x36367225202c3736\n"
".quad 0x732e627573090a3b,0x3836722509203233,0x202c30367225202c,0x61090a3b35337225\n"
".quad 0x09203233732e7362,0x7225202c39367225,0x766f6d090a3b3836,0x722509203233732e\n"
".quad 0x0a3b3031202c3037,0x2e74672e74657309,0x203233732e323375,0x25202c3137722509\n"
".quad 0x377225202c393672,0x2e67656e090a3b30,0x3772250920323373,0x3b31377225202c32\n"
".quad 0x33732e627573090a,0x2c33377225092032,0x25202c3136722520,0x6261090a3b363372\n"
".quad 0x2509203233732e73,0x377225202c343772,0x2e766f6d090a3b33,0x3772250920323373\n"
".quad 0x090a3b3031202c35,0x752e74672e746573,0x09203233732e3233,0x7225202c36377225\n"
".quad 0x35377225202c3437,0x732e67656e090a3b,0x3737722509203233,0x0a3b36377225202c\n"
".quad 0x203233622e726f09,0x25202c3837722509,0x377225202c323772,0x622e726f090a3b37\n"
".quad 0x3937722509203233,0x202c37367225202c,0x61090a3b38377225,0x09203233732e6464\n"
".quad 0x7225202c38357225,0x39377225202c3835,0x5f315f744c240a3b,0x200a3a3037393931\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c363832,0x656c6562616c2064,0x5f315f744c242064,0x6d090a3039363831\n"
".quad 0x09203233752e766f,0x3b30202c30387225,0x6c2e70746573090a,0x2509203233732e65\n"
".quad 0x36327225202c3870,0x0a3b30387225202c,0x7262203870254009,0x315f744c24092061\n"
".quad 0x0a3b32383430325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c36383220,0x6c6562616c206461,0x315f744c24206465\n"
".quad 0x090a30393638315f,0x09373109636f6c2e,0x73090a3009393033,0x09203233732e6275\n"
".quad 0x7225202c31387225,0x38317225202c3433,0x732e747663090a3b,0x09203233732e3436\n"
".quad 0x7225202c36647225,0x6c756d090a3b3138,0x33732e656469772e,0x2c37647225092032\n"
".quad 0x34202c3138722520,0x09636f6c2e090a3b,0x3009303033093731,0x7261702e646c090a\n"
".quad 0x09203436752e6d61,0x5f5b202c32647225,0x726170616475635f,0x614d38315a5f5f6d\n"
".quad 0x746f72626c65646e,0x33316d735f315344,0x3472616863753650,0x6666666666696969\n"
".quad 0x696969695f536666,0x0a3b5d7473645f62,0x373109636f6c2e09,0x090a300939303309\n"
".quad 0x203436752e646461,0x25202c3864722509,0x647225202c326472,0x672e646c090a3b37\n"
".quad 0x34762e6c61626f6c,0x72257b092038752e,0x2c333872252c3238,0x2c7d5f2c34387225\n"
".quad 0x302b386472255b20,0x2e627573090a3b5d,0x3872250920323373,0x2c34387225202c35\n"
".quad 0x090a3b3733722520,0x203233732e736261,0x25202c3638722509,0x6f6d090a3b353872\n"
".quad 0x2509203233732e76,0x3b3031202c373872,0x74672e746573090a,0x3233732e3233752e\n"
".quad 0x202c383872250920,0x7225202c36387225,0x67656e090a3b3738,0x722509203233732e\n"
".quad 0x38387225202c3938,0x732e627573090a3b,0x3039722509203233,0x202c32387225202c\n"
".quad 0x61090a3b35337225,0x09203233732e7362,0x7225202c31397225,0x766f6d090a3b3039\n"
".quad 0x722509203233732e,0x0a3b3031202c3239,0x2e74672e74657309,0x203233732e323375\n"
".quad 0x25202c3339722509,0x397225202c313972,0x2e67656e090a3b32,0x3972250920323373\n"
".quad 0x3b33397225202c34,0x33732e627573090a,0x2c35397225092032,0x25202c3338722520\n"
".quad 0x6261090a3b363372,0x2509203233732e73,0x397225202c363972,0x2e766f6d090a3b35\n"
".quad 0x3972250920323373,0x090a3b3031202c37,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c38397225,0x37397225202c3639,0x732e67656e090a3b,0x3939722509203233\n"
".quad 0x0a3b38397225202c,0x203233622e726f09,0x202c303031722509,0x7225202c34397225\n"
".quad 0x2e726f090a3b3939,0x3172250920323362,0x39387225202c3130,0x3b3030317225202c\n"
".quad 0x33732e646461090a,0x2c38357225092032,0x25202c3835722520,0x4c240a3b31303172\n"
".quad 0x383430325f315f74,0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c36383220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393638315f315f74,0x732e646461090a30,0x3031722509203233,0x2c36327225202c32\n"
".quad 0x746573090a3b3120,0x3233732e656c2e70,0x25202c3970250920,0x317225202c373172\n"
".quad 0x702540090a3b3230,0x2409206172622039,0x3930325f315f744c,0x3c2f2f200a3b3439\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x36383220656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3638315f315f744c,0x636f6c2e090a3039\n"
".quad 0x0931313309373109,0x732e646461090a30,0x3031722509203233,0x2c34337225202c33\n"
".quad 0x090a3b3831722520,0x2e3436732e747663,0x6472250920323373,0x3330317225202c39\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x202c303164722509,0x34202c3330317225\n"
".quad 0x09636f6c2e090a3b,0x3009303033093731,0x7261702e646c090a,0x09203436752e6d61\n"
".quad 0x5f5b202c32647225,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x33316d735f315344,0x3472616863753650,0x6666666666696969,0x696969695f536666\n"
".quad 0x0a3b5d7473645f62,0x373109636f6c2e09,0x090a300931313309,0x203436752e646461\n"
".quad 0x202c313164722509,0x7225202c32647225,0x646c090a3b303164,0x2e6c61626f6c672e\n"
".quad 0x7b092038752e3476,0x72252c3430317225,0x303172252c353031,0x255b202c7d5f2c36\n"
".quad 0x3b5d302b31316472,0x33732e627573090a,0x3730317225092032,0x2c3630317225202c\n"
".quad 0x090a3b3733722520,0x203233732e736261,0x202c383031722509,0x090a3b3730317225\n"
".quad 0x203233732e766f6d,0x202c393031722509,0x746573090a3b3031,0x2e3233752e74672e\n"
".quad 0x3172250920323373,0x30317225202c3031,0x3930317225202c38,0x732e67656e090a3b\n"
".quad 0x3131722509203233,0x3031317225202c31,0x732e627573090a3b,0x3131722509203233\n"
".quad 0x3430317225202c32,0x0a3b35337225202c,0x3233732e73626109,0x2c33313172250920\n"
".quad 0x0a3b323131722520,0x3233732e766f6d09,0x2c34313172250920,0x6573090a3b303120\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x317225202c353131,0x31317225202c3331\n"
".quad 0x2e67656e090a3b34,0x3172250920323373,0x31317225202c3631,0x2e627573090a3b35\n"
".quad 0x3172250920323373,0x30317225202c3731,0x3b36337225202c35,0x33732e736261090a\n"
".quad 0x3831317225092032,0x3b3731317225202c,0x33732e766f6d090a,0x3931317225092032\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x7225202c30323172\n"
".quad 0x317225202c383131,0x67656e090a3b3931,0x722509203233732e,0x317225202c313231\n"
".quad 0x2e726f090a3b3032,0x3172250920323362,0x31317225202c3232,0x3132317225202c36\n"
".quad 0x33622e726f090a3b,0x3332317225092032,0x2c3131317225202c,0x0a3b323231722520\n"
".quad 0x3233732e64646109,0x202c383572250920,0x7225202c38357225,0x744c240a3b333231\n"
".quad 0x34393930325f315f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c36383220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30393638315f315f,0x33752e766f6d090a,0x3432317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c30317025092032,0x25202c3835722520,0x40090a3b34323172\n"
".quad 0x6172622030317025,0x5f315f744c240920,0x200a3b3630353132,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832\n"
".quad 0x656c6562616c2064,0x5f315f744c242064,0x2e090a3039363831,0x3309373109636f6c\n"
".quad 0x7663090a30093831,0x3233662e6e722e74,0x662509203233732e,0x3b35327225202c31\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5f5b202c326625,0x6d72617061647563\n"
".quad 0x6e614d38315a5f5f,0x44746f72626c6564,0x5033316d735f3153,0x6934726168637536\n"
".quad 0x6666666666666969,0x62696969695f5366,0x3b5d656c6163735f,0x33662e6c756d090a\n"
".quad 0x202c336625092032,0x326625202c316625,0x61702e646c090a3b,0x203233662e6d6172\n"
".quad 0x5f5b202c34662509,0x726170616475635f,0x614d38315a5f5f6d,0x746f72626c65646e\n"
".quad 0x33316d735f315344,0x3472616863753650,0x6666666666696969,0x696969695f536666\n"
".quad 0x5d3066664f785f62,0x662e646461090a3b,0x2c35662509203233,0x6625202c33662520\n"
".quad 0x2e627573090a3b34,0x3666250920323366,0x25202c356625202c,0x627573090a3b3366\n"
".quad 0x662509203233662e,0x202c346625202c37,0x7573090a3b366625,0x2509203233662e62\n"
".quad 0x2c356625202c3866,0x73090a3b36662520,0x09203233662e6275,0x336625202c396625\n"
".quad 0x090a3b386625202c,0x203233662e646461,0x25202c3031662509,0x3b396625202c3766\n"
".quad 0x7261702e646c090a,0x09203233662e6d61,0x5f5b202c31316625,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344,0x3472616863753650\n"
".quad 0x6666666666696969,0x696969695f536666,0x5d3166664f785f62,0x662e646461090a3b\n"
".quad 0x3231662509203233,0x202c31316625202c,0x61090a3b30316625,0x09203233662e6464\n"
".quad 0x6625202c33316625,0x3b32316625202c35,0x33662e627573090a,0x2c34316625092032\n"
".quad 0x25202c3331662520,0x627573090a3b3566,0x662509203233662e,0x32316625202c3531\n"
".quad 0x0a3b34316625202c,0x373109636f6c2e09,0x090a300939313309,0x662e6e722e747663\n"
".quad 0x09203233732e3233,0x7225202c36316625,0x6c756d090a3b3632,0x662509203233662e\n"
".quad 0x36316625202c3731,0x090a3b326625202c,0x6d617261702e646c,0x662509203233662e\n"
".quad 0x635f5f5b202c3831,0x5f6d726170616475,0x646e614d38315a5f,0x5344746f72626c65\n"
".quad 0x365033316d735f31,0x6969347261686375,0x6666666666666669,0x5f62696969695f53\n"
".quad 0x0a3b5d3066664f79,0x3233662e64646109,0x202c393166250920,0x6625202c37316625\n"
".quad 0x627573090a3b3831,0x662509203233662e,0x39316625202c3032,0x0a3b37316625202c\n"
".quad 0x3233662e62757309,0x202c313266250920,0x6625202c38316625,0x627573090a3b3032\n"
".quad 0x662509203233662e,0x39316625202c3232,0x0a3b30326625202c,0x3233662e62757309\n"
".quad 0x202c333266250920,0x6625202c37316625,0x646461090a3b3232,0x662509203233662e\n"
".quad 0x31326625202c3432,0x0a3b33326625202c,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x5f5f5b202c353266,0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564\n"
".quad 0x5033316d735f3153,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x3b5d3166664f795f,0x33662e646461090a,0x2c36326625092032,0x25202c3532662520\n"
".quad 0x6461090a3b343266,0x2509203233662e64,0x316625202c373266,0x3b36326625202c39\n"
".quad 0x33662e627573090a,0x2c38326625092032,0x25202c3732662520,0x7573090a3b393166\n"
".quad 0x2509203233662e62,0x326625202c393266,0x3b38326625202c36,0x3109636f6c2e090a\n"
".quad 0x0a30093232330937,0x617261702e646c09,0x7225092038732e6d,0x5f5f5b202c353231\n"
".quad 0x6d72617061647563,0x6e614d38315a5f5f,0x44746f72626c6564,0x5033316d735f3153\n"
".quad 0x6934726168637536,0x6666666666666969,0x62696969695f5366,0x090a3b5d4a73695f\n"
".quad 0x203233752e766f6d,0x202c363231722509,0x70746573090a3b30,0x203233732e71652e\n"
".quad 0x25202c3131702509,0x7225202c35323172,0x2540090a3b363231,0x2061726220313170\n"
".quad 0x325f315f744c2409,0x2f200a3b34373232,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3638,0x64656c6562616c20\n"
".quad 0x315f315f744c2420,0x6c2e090a30393638,0x353209363109636f,0x2e646c090a300933\n"
".quad 0x33662e6d61726170,0x2c30336625092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d38,0x735f315344746f72,0x686375365033316d,0x6666696969347261\n"
".quad 0x695f536666666666,0x504a785f62696969,0x636f6c2e090a3b5d,0x0935353209363109\n"
".quad 0x61702e646c090a30,0x203233662e6d6172,0x5b202c3133662509,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x3b5d504a795f6269,0x3109636f6c2e090a\n"
".quad 0x0a30093735320936,0x3233662e766f6d09,0x202c323366250920,0x2e090a3b37326625\n"
".quad 0x3209363109636f6c,0x6f6d090a30093835,0x2509203233662e76,0x326625202c333366\n"
".quad 0x636f6c2e090a3b39,0x0939353209363109,0x662e766f6d090a30,0x3433662509203233\n"
".quad 0x0a3b33316625202c,0x363109636f6c2e09,0x090a300930363209,0x203233662e766f6d\n"
".quad 0x25202c3533662509,0x6c2e090a3b353166,0x363209363109636f,0x766f6d090a300931\n"
".quad 0x662509203233662e,0x36346630202c3633,0x203b303034303030,0x38202f2f09202020\n"
".quad 0x6c756d090a333931,0x662509203233662e,0x37326625202c3733,0x0a3b36336625202c\n"
".quad 0x3233662e62757309,0x202c383366250920,0x6625202c37336625,0x627573090a3b3732\n"
".quad 0x662509203233662e,0x37336625202c3933,0x0a3b38336625202c,0x3233662e62757309\n"
".quad 0x202c303466250920,0x6625202c37326625,0x6c756d090a3b3933,0x662509203233662e\n"
".quad 0x37326625202c3134,0x0a3b37326625202c,0x3233662e6c756d09,0x202c323466250920\n"
".quad 0x6625202c37326625,0x64616d090a3b3932,0x662509203233662e,0x37326625202c3334\n"
".quad 0x202c39326625202c,0x61090a3b32346625,0x09203233662e6464,0x6625202c34346625\n"
".quad 0x33346625202c3134,0x662e6c756d090a3b,0x3534662509203233,0x202c39336625202c\n"
".quad 0x73090a3b39336625,0x09203233662e6275,0x6625202c36346625,0x31346625202c3534\n"
".quad 0x662e627573090a3b,0x3734662509203233,0x202c34346625202c,0x6d090a3b31346625\n"
".quad 0x09203233662e6461,0x6625202c38346625,0x30346625202c3933,0x0a3b36346625202c\n"
".quad 0x3233662e62757309,0x202c393466250920,0x6625202c34346625,0x627573090a3b3734\n"
".quad 0x662509203233662e,0x33346625202c3035,0x0a3b37346625202c,0x3233662e64616d09\n"
".quad 0x202c313566250920,0x6625202c39336625,0x38346625202c3034,0x662e627573090a3b\n"
".quad 0x3235662509203233,0x202c31346625202c,0x6d090a3b39346625,0x09203233662e6461\n"
".quad 0x6625202c33356625,0x30346625202c3034,0x0a3b31356625202c,0x3233662e64646109\n"
".quad 0x202c343566250920,0x6625202c30356625,0x646461090a3b3235,0x662509203233662e\n"
".quad 0x33356625202c3535,0x0a3b34356625202c,0x3233662e64616d09,0x202c363566250920\n"
".quad 0x6625202c39326625,0x35356625202c3932,0x662e646461090a3b,0x3735662509203233\n"
".quad 0x202c34346625202c,0x6d090a3b36356625,0x09203233662e766f,0x6625202c38356625\n"
".quad 0x627573090a3b3735,0x662509203233662e,0x37356625202c3935,0x0a3b34346625202c\n"
".quad 0x3233662e62757309,0x202c303666250920,0x6625202c36356625,0x6f6c2e090a3b3935\n"
".quad 0x3236320936310963,0x2e766f6d090a3009,0x3666250920323366,0x3036346630202c31\n"
".quad 0x20203b3030343030,0x3138202f2f092020,0x2e6c756d090a3339,0x3666250920323366\n"
".quad 0x2c33316625202c32,0x090a3b3136662520,0x203233662e627573,0x25202c3336662509\n"
".quad 0x316625202c323666,0x2e627573090a3b33,0x3666250920323366,0x2c32366625202c34\n"
".quad 0x090a3b3336662520,0x203233662e627573,0x25202c3536662509,0x366625202c333166\n"
".quad 0x2e6c756d090a3b34,0x3666250920323366,0x2c33316625202c36,0x090a3b3331662520\n"
".quad 0x203233662e6c756d,0x25202c3736662509,0x316625202c333166,0x2e64616d090a3b35\n"
".quad 0x3666250920323366,0x2c33316625202c38,0x25202c3531662520,0x6461090a3b373666\n"
".quad 0x2509203233662e64,0x366625202c393666,0x3b38366625202c36,0x33662e6c756d090a\n"
".quad 0x2c30376625092032,0x25202c3436662520,0x7573090a3b343666,0x2509203233662e62\n"
".quad 0x376625202c313766,0x3b36366625202c30,0x33662e627573090a,0x2c32376625092032\n"
".quad 0x25202c3936662520,0x616d090a3b363666,0x2509203233662e64,0x366625202c333766\n"
".quad 0x2c35366625202c34,0x090a3b3137662520,0x203233662e627573,0x25202c3437662509\n"
".quad 0x376625202c393666,0x2e627573090a3b32,0x3766250920323366,0x2c38366625202c35\n"
".quad 0x090a3b3237662520,0x203233662e64616d,0x25202c3637662509,0x366625202c343666\n"
".quad 0x3b33376625202c35,0x33662e627573090a,0x2c37376625092032,0x25202c3636662520\n"
".quad 0x616d090a3b343766,0x2509203233662e64,0x366625202c383766,0x2c35366625202c35\n"
".quad 0x090a3b3637662520,0x203233662e646461,0x25202c3937662509,0x376625202c353766\n"
".quad 0x2e646461090a3b37,0x3866250920323366,0x2c38376625202c30,0x090a3b3937662520\n"
".quad 0x203233662e64616d,0x25202c3138662509,0x316625202c353166,0x3b30386625202c35\n"
".quad 0x33662e646461090a,0x2c32386625092032,0x25202c3936662520,0x6f6d090a3b313866\n"
".quad 0x2509203233662e76,0x386625202c333866,0x2e627573090a3b32,0x3866250920323366\n"
".quad 0x2c32386625202c34,0x090a3b3936662520,0x203233662e627573,0x25202c3538662509\n"
".quad 0x386625202c313866,0x2e766f6d090a3b34,0x3866250920323366,0x3030306630202c36\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c373866250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x7262090a30202f2f,0x240920696e752e61\n"
".quad 0x3032325f315f744c,0x5f744c240a3b3831,0x3a34373232325f31,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3638322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a30393638315f31,0x363109636f6c2e09\n"
".quad 0x090a300935363209,0x203233662e766f6d,0x25202c3033662509,0x6c2e090a3b333166\n"
".quad 0x363209363109636f,0x766f6d090a300936,0x662509203233662e,0x35316625202c3738\n"
".quad 0x09636f6c2e090a3b,0x3009373632093631,0x33662e766f6d090a,0x2c31336625092032\n"
".quad 0x090a3b3732662520,0x09363109636f6c2e,0x6d090a3009383632,0x09203233662e766f\n"
".quad 0x6625202c36386625,0x6f6c2e090a3b3932,0x3637320936310963,0x2e766f6d090a3009\n"
".quad 0x3866250920323366,0x3030306630202c35,0x20203b3030303030,0x0a30202f2f092020\n"
".quad 0x3233662e766f6d09,0x202c333866250920,0x3030303030306630,0x09202020203b3030\n"
".quad 0x6f6d090a30202f2f,0x2509203233662e76,0x306630202c303666,0x3b30303030303030\n"
".quad 0x202f2f0920202020,0x662e766f6d090a30,0x3835662509203233,0x303030306630202c\n"
".quad 0x2020203b30303030,0x090a30202f2f0920,0x203233662e766f6d,0x30202c3533662509\n"
".quad 0x3030303030303066,0x2f09202020203b30,0x766f6d090a30202f,0x662509203233662e\n"
".quad 0x30306630202c3433,0x203b303030303030,0x30202f2f09202020,0x33662e766f6d090a\n"
".quad 0x2c33336625092032,0x3030303030663020,0x202020203b303030,0x6d090a30202f2f09\n"
".quad 0x09203233662e766f,0x6630202c32336625,0x3030303030303030,0x2f2f09202020203b\n"
".quad 0x315f744c240a3020,0x0a3a38313032325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36383220,0x6c6562616c206461\n"
".quad 0x315f744c24206465,0x090a30393638315f,0x09363109636f6c2e,0x6c090a3009303832\n"
".quad 0x2e6d617261702e64,0x3172250920323373,0x635f5f5b202c3732,0x5f6d726170616475\n"
".quad 0x646e614d38315a5f,0x5344746f72626c65,0x365033316d735f31,0x6969347261686375\n"
".quad 0x6666666666666669,0x5f62696969695f53,0x3b5d68636e757263,0x33732e627573090a\n"
".quad 0x3832317225092032,0x2c3732317225202c,0x766f6d090a3b3120,0x722509203233752e\n"
".quad 0x0a3b31202c393231,0x71652e7074657309,0x702509203233732e,0x32317225202c3231\n"
".quad 0x3932317225202c37,0x3231702540090a3b,0x4c24092061726220,0x363034325f315f74\n"
".quad 0x6c3c2f2f200a3b36,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c36383220656e69,0x616c206461656820,0x4c242064656c6562,0x393638315f315f74\n"
".quad 0x662e646461090a30,0x3838662509203233,0x202c33386625202c,0x73090a3b38356625\n"
".quad 0x09203233662e6275,0x6625202c39386625,0x33386625202c3838,0x662e627573090a3b\n"
".quad 0x3039662509203233,0x202c38386625202c,0x73090a3b39386625,0x09203233662e6275\n"
".quad 0x6625202c31396625,0x39386625202c3835,0x662e627573090a3b,0x3239662509203233\n"
".quad 0x202c33386625202c,0x61090a3b30396625,0x09203233662e6464,0x6625202c33396625\n"
".quad 0x32396625202c3139,0x662e646461090a3b,0x3439662509203233,0x202c33396625202c\n"
".quad 0x61090a3b35386625,0x09203233662e6464,0x6625202c35396625,0x30366625202c3439\n"
".quad 0x662e646461090a3b,0x3639662509203233,0x202c38386625202c,0x73090a3b35396625\n"
".quad 0x09203233662e6275,0x6625202c37396625,0x38386625202c3639,0x662e627573090a3b\n"
".quad 0x3839662509203233,0x202c35396625202c,0x61090a3b37396625,0x09203233662e6464\n"
".quad 0x6625202c39396625,0x38396625202c3639,0x662e766f6d090a3b,0x3031662509203233\n"
".quad 0x3830346630202c30,0x20203b3030303030,0x090a34202f2f0920,0x2e746c2e70746573\n"
".quad 0x3170250920323366,0x2c39396625202c33,0x0a3b303031662520,0x2033317025214009\n"
".quad 0x744c240920617262,0x36363034325f315f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36383220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30393638315f315f,0x33662e766f6d090a,0x3130316625092032\n"
".quad 0x303036346630202c,0x2020203b30303430,0x33393138202f2f09,0x33662e6c756d090a\n"
".quad 0x3230316625092032,0x202c34336625202c,0x090a3b3130316625,0x203233662e766f6d\n"
".quad 0x202c333031662509,0x3430303036346630,0x2f092020203b3030,0x090a33393138202f\n"
".quad 0x203233662e6c756d,0x202c343031662509,0x6625202c32336625,0x7573090a3b333031\n"
".quad 0x2509203233662e62,0x6625202c35303166,0x336625202c323031,0x2e627573090a3b34\n"
".quad 0x3166250920323366,0x30316625202c3630,0x3b32336625202c34,0x33662e627573090a\n"
".quad 0x3730316625092032,0x2c3230316625202c,0x0a3b353031662520,0x3233662e62757309\n"
".quad 0x2c38303166250920,0x202c343031662520,0x090a3b3630316625,0x203233662e627573\n"
".quad 0x202c393031662509,0x6625202c34336625,0x7573090a3b373031,0x2509203233662e62\n"
".quad 0x6625202c30313166,0x30316625202c3233,0x5f315f4c240a3b38,0x200a3a3234363631\n"
".quad 0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964,0x6f6c2e090a313832\n"
".quad 0x3138320936310963,0x2e6c756d090a3009,0x3166250920323366,0x35336625202c3131\n"
".quad 0x0a3b32336625202c,0x3233662e6c756d09,0x2c32313166250920,0x25202c3433662520\n"
".quad 0x616d090a3b323366,0x2509203233662e64,0x6625202c33313166,0x33336625202c3433\n"
".quad 0x3b3131316625202c,0x33662e646461090a,0x3431316625092032,0x2c3231316625202c\n"
".quad 0x0a3b333131662520,0x3233662e62757309,0x2c35313166250920,0x202c343131662520\n"
".quad 0x090a3b3231316625,0x203233662e6c756d,0x202c363131662509,0x25202c3730316625\n"
".quad 0x73090a3b38303166,0x09203233662e6275,0x25202c3731316625,0x6625202c36313166\n"
".quad 0x7573090a3b323131,0x2509203233662e62,0x6625202c38313166,0x316625202c333131\n"
".quad 0x627573090a3b3531,0x662509203233662e,0x316625202c393131,0x31316625202c3431\n"
".quad 0x2e64616d090a3b35,0x3166250920323366,0x30316625202c3032,0x3031316625202c37\n"
".quad 0x3b3731316625202c,0x33662e627573090a,0x3132316625092032,0x2c3231316625202c\n"
".quad 0x0a3b393131662520,0x3233662e64616d09,0x2c32323166250920,0x202c383031662520\n"
".quad 0x25202c3930316625,0x61090a3b30323166,0x09203233662e6464,0x25202c3332316625\n"
".quad 0x6625202c38313166,0x616d090a3b313231,0x2509203233662e64,0x6625202c34323166\n"
".quad 0x316625202c393031,0x32316625202c3031,0x2e646461090a3b32,0x3166250920323366\n"
".quad 0x32316625202c3532,0x3432316625202c33,0x662e64616d090a3b,0x3231662509203233\n"
".quad 0x2c35336625202c36,0x25202c3333662520,0x61090a3b35323166,0x09203233662e6464\n"
".quad 0x25202c3732316625,0x6625202c34313166,0x7573090a3b363231,0x2509203233662e62\n"
".quad 0x6625202c38323166,0x316625202c373231,0x627573090a3b3431,0x662509203233662e\n"
".quad 0x316625202c393231,0x32316625202c3632,0x636f6c2e090a3b38,0x0932383209363109\n"
".quad 0x662e646461090a30,0x3331662509203233,0x3732316625202c30,0x3b3732316625202c\n"
".quad 0x33662e627573090a,0x3133316625092032,0x2c3033316625202c,0x0a3b373231662520\n"
".quad 0x3233662e62757309,0x2c32333166250920,0x202c373231662520,0x090a3b3133316625\n"
".quad 0x203233662e627573,0x202c333331662509,0x25202c3033316625,0x73090a3b31333166\n"
".quad 0x09203233662e6275,0x25202c3433316625,0x6625202c37323166,0x6461090a3b333331\n"
".quad 0x2509203233662e64,0x6625202c35333166,0x316625202c323331,0x646461090a3b3433\n"
".quad 0x662509203233662e,0x316625202c363331,0x32316625202c3533,0x2e646461090a3b39\n"
".quad 0x3166250920323366,0x33316625202c3733,0x3932316625202c36,0x662e646461090a3b\n"
".quad 0x3331662509203233,0x3033316625202c38,0x3b3733316625202c,0x33662e627573090a\n"
".quad 0x3933316625092032,0x2c3833316625202c,0x0a3b303331662520,0x3233662e62757309\n"
".quad 0x2c30343166250920,0x202c373331662520,0x090a3b3933316625,0x09363109636f6c2e\n"
".quad 0x61090a3009333832,0x09203233662e6464,0x25202c3134316625,0x6625202c38333166\n"
".quad 0x627573090a3b3133,0x662509203233662e,0x316625202c323431,0x33316625202c3134\n"
".quad 0x2e627573090a3b38,0x3166250920323366,0x34316625202c3334,0x3234316625202c31\n"
".quad 0x662e627573090a3b,0x3431662509203233,0x2c31336625202c34,0x0a3b323431662520\n"
".quad 0x3233662e62757309,0x2c35343166250920,0x202c383331662520,0x090a3b3334316625\n"
".quad 0x203233662e646461,0x202c363431662509,0x25202c3434316625,0x61090a3b35343166\n"
".quad 0x09203233662e6464,0x25202c3734316625,0x6625202c36343166,0x6461090a3b303431\n"
".quad 0x2509203233662e64,0x6625202c38343166,0x386625202c373431,0x2e646461090a3b36\n"
".quad 0x3166250920323366,0x34316625202c3934,0x3834316625202c31,0x662e766f6d090a3b\n"
".quad 0x3233662509203233,0x3b3934316625202c,0x33662e627573090a,0x3035316625092032\n"
".quad 0x2c3934316625202c,0x0a3b313431662520,0x3233662e62757309,0x202c333366250920\n"
".quad 0x25202c3834316625,0x2e090a3b30353166,0x3209363109636f6c,0x7573090a30093638\n"
".quad 0x2509203233662e62,0x6625202c31353166,0x38356625202c3338,0x662e627573090a3b\n"
".quad 0x3531662509203233,0x3135316625202c32,0x0a3b33386625202c,0x3233662e62757309\n"
".quad 0x2c33353166250920,0x202c313531662520,0x090a3b3235316625,0x203233662e646461\n"
".quad 0x202c343531662509,0x25202c3235316625,0x7573090a3b383566,0x2509203233662e62\n"
".quad 0x6625202c35353166,0x35316625202c3338,0x2e627573090a3b33,0x3166250920323366\n"
".quad 0x35316625202c3635,0x3435316625202c35,0x662e646461090a3b,0x3531662509203233\n"
".quad 0x3635316625202c37,0x0a3b35386625202c,0x3233662e62757309,0x2c38353166250920\n"
".quad 0x202c373531662520,0x61090a3b30366625,0x09203233662e6464,0x25202c3935316625\n"
".quad 0x6625202c31353166,0x6461090a3b383531,0x2509203233662e64,0x6625202c30363166\n"
".quad 0x336625202c393531,0x2e627573090a3b30,0x3166250920323366,0x36316625202c3136\n"
".quad 0x3935316625202c30,0x662e627573090a3b,0x3631662509203233,0x3036316625202c32\n"
".quad 0x3b3136316625202c,0x33662e627573090a,0x3336316625092032,0x2c3935316625202c\n"
".quad 0x0a3b323631662520,0x3233662e62757309,0x2c34363166250920,0x25202c3033662520\n"
".quad 0x61090a3b31363166,0x09203233662e6464,0x25202c3536316625,0x6625202c33363166\n"
".quad 0x7573090a3b343631,0x2509203233662e62,0x6625202c36363166,0x316625202c393531\n"
".quad 0x627573090a3b3135,0x662509203233662e,0x316625202c373631,0x36316625202c3835\n"
".quad 0x2e646461090a3b36,0x3166250920323366,0x36316625202c3836,0x3736316625202c35\n"
".quad 0x662e646461090a3b,0x3631662509203233,0x2c37386625202c39,0x0a3b383631662520\n"
".quad 0x3233662e64646109,0x2c30373166250920,0x202c303631662520,0x090a3b3936316625\n"
".quad 0x203233662e766f6d,0x25202c3433662509,0x73090a3b30373166,0x09203233662e6275\n"
".quad 0x25202c3137316625,0x6625202c30373166,0x7573090a3b303631,0x2509203233662e62\n"
".quad 0x316625202c353366,0x37316625202c3936,0x636f6c2e090a3b31,0x0938383209363109\n"
".quad 0x662e766f6d090a30,0x3731662509203233,0x3036346630202c32,0x20203b3030343030\n"
".quad 0x393138202f2f0920,0x662e6c756d090a33,0x3731662509203233,0x3934316625202c33\n"
".quad 0x3b3237316625202c,0x33662e6c756d090a,0x3437316625092032,0x2c3934316625202c\n"
".quad 0x090a3b3333662520,0x203233662e6c756d,0x202c353731662509,0x25202c3934316625\n"
".quad 0x73090a3b39343166,0x09203233662e6275,0x25202c3637316625,0x6625202c33373166\n"
".quad 0x616d090a3b393431,0x2509203233662e64,0x6625202c37373166,0x336625202c393431\n"
".quad 0x3437316625202c33,0x662e627573090a3b,0x3031662509203233,0x3337316625202c38\n"
".quad 0x3b3637316625202c,0x33662e646461090a,0x3837316625092032,0x2c3537316625202c\n"
".quad 0x0a3b373731662520,0x3233662e62757309,0x2c30313166250920,0x202c393431662520\n"
".quad 0x090a3b3830316625,0x203233662e6c756d,0x202c393731662509,0x25202c3830316625\n"
".quad 0x73090a3b38303166,0x09203233662e6275,0x25202c3038316625,0x6625202c39373166\n"
".quad 0x7573090a3b353731,0x2509203233662e62,0x6625202c31383166,0x316625202c383731\n"
".quad 0x64616d090a3b3537,0x662509203233662e,0x316625202c323831,0x31316625202c3830\n"
".quad 0x3038316625202c30,0x662e627573090a3b,0x3831662509203233,0x3737316625202c33\n"
".quad 0x3b3138316625202c,0x33662e627573090a,0x3438316625092032,0x2c3837316625202c\n"
".quad 0x0a3b313831662520,0x3233662e64616d09,0x2c35383166250920,0x202c383031662520\n"
".quad 0x25202c3031316625,0x73090a3b32383166,0x09203233662e6275,0x25202c3638316625\n"
".quad 0x6625202c35373166,0x616d090a3b343831,0x2509203233662e64,0x6625202c37383166\n"
".quad 0x316625202c303131,0x38316625202c3031,0x2e646461090a3b35,0x3166250920323366\n"
".quad 0x38316625202c3838,0x3638316625202c33,0x662e646461090a3b,0x3831662509203233\n"
".quad 0x3738316625202c39,0x3b3838316625202c,0x33662e64616d090a,0x3039316625092032\n"
".quad 0x202c33336625202c,0x6625202c33336625,0x6461090a3b393831,0x2509203233662e64\n"
".quad 0x6625202c31393166,0x316625202c383731,0x766f6d090a3b3039,0x662509203233662e\n"
".quad 0x39316625202c3835,0x2e627573090a3b31,0x3166250920323366,0x39316625202c3239\n"
".quad 0x3837316625202c31,0x662e627573090a3b,0x3036662509203233,0x2c3039316625202c\n"
".quad 0x0a3b323931662520,0x363109636f6c2e09,0x090a300939383209,0x203233662e766f6d\n"
".quad 0x202c333931662509,0x3430303036346630,0x2f092020203b3030,0x090a33393138202f\n"
".quad 0x203233662e6c756d,0x202c343931662509,0x25202c3037316625,0x6d090a3b33393166\n"
".quad 0x09203233662e6c75,0x25202c3539316625,0x6625202c30373166,0x6c756d090a3b3533\n"
".quad 0x662509203233662e,0x316625202c363931,0x37316625202c3037,0x2e627573090a3b30\n"
".quad 0x3166250920323366,0x39316625202c3739,0x3037316625202c34,0x662e64616d090a3b\n"
".quad 0x3931662509203233,0x3037316625202c38,0x202c35336625202c,0x090a3b3539316625\n"
".quad 0x203233662e627573,0x202c373031662509,0x25202c3439316625,0x61090a3b37393166\n"
".quad 0x09203233662e6464,0x25202c3939316625,0x6625202c36393166,0x7573090a3b383931\n"
".quad 0x2509203233662e62,0x6625202c39303166,0x316625202c303731,0x6c756d090a3b3730\n"
".quad 0x662509203233662e,0x316625202c303032,0x30316625202c3730,0x2e627573090a3b37\n"
".quad 0x3266250920323366,0x30326625202c3130,0x3639316625202c30,0x662e627573090a3b\n"
".quad 0x3032662509203233,0x3939316625202c32,0x3b3639316625202c,0x33662e64616d090a\n"
".quad 0x3330326625092032,0x2c3730316625202c,0x202c393031662520,0x090a3b3130326625\n"
".quad 0x203233662e627573,0x202c343032662509,0x25202c3839316625,0x73090a3b32303266\n"
".quad 0x09203233662e6275,0x25202c3530326625,0x6625202c39393166,0x616d090a3b323032\n"
".quad 0x2509203233662e64,0x6625202c36303266,0x316625202c373031,0x30326625202c3930\n"
".quad 0x2e627573090a3b33,0x3266250920323366,0x39316625202c3730,0x3530326625202c36\n"
".quad 0x662e64616d090a3b,0x3032662509203233,0x3930316625202c38,0x2c3930316625202c\n"
".quad 0x0a3b363032662520,0x3233662e64646109,0x2c39303266250920,0x202c343032662520\n"
".quad 0x090a3b3730326625,0x203233662e646461,0x202c303132662509,0x25202c3830326625\n"
".quad 0x6d090a3b39303266,0x09203233662e6461,0x25202c3131326625,0x336625202c353366\n"
".quad 0x3031326625202c35,0x662e646461090a3b,0x3132662509203233,0x3939316625202c32\n"
".quad 0x3b3131326625202c,0x33662e766f6d090a,0x2c33386625092032,0x0a3b323132662520\n"
".quad 0x3233662e62757309,0x2c33313266250920,0x202c323132662520,0x090a3b3939316625\n"
".quad 0x203233662e627573,0x25202c3538662509,0x6625202c31313266,0x6c2e090a3b333132\n"
".quad 0x393209363109636f,0x646461090a300930,0x662509203233662e,0x316625202c343132\n"
".quad 0x31326625202c3139,0x2e627573090a3b32,0x3266250920323366,0x31326625202c3531\n"
".quad 0x3231326625202c34,0x662e627573090a3b,0x3132662509203233,0x3139316625202c36\n"
".quad 0x3b3531326625202c,0x33662e627573090a,0x3731326625092032,0x2c3431326625202c\n"
".quad 0x0a3b353132662520,0x3233662e62757309,0x2c38313266250920,0x202c323132662520\n"
".quad 0x090a3b3731326625,0x203233662e646461,0x202c393132662509,0x25202c3631326625\n"
".quad 0x61090a3b38313266,0x09203233662e6464,0x25202c3032326625,0x326625202c353866\n"
".quad 0x646461090a3b3931,0x662509203233662e,0x366625202c313232,0x3032326625202c30\n"
".quad 0x662e646461090a3b,0x3232662509203233,0x3431326625202c32,0x3b3132326625202c\n"
".quad 0x33662e627573090a,0x3332326625092032,0x2c3232326625202c,0x0a3b343132662520\n"
".quad 0x3233662e62757309,0x2c34323266250920,0x202c313232662520,0x090a3b3332326625\n"
".quad 0x09363109636f6c2e,0x73090a3009303832,0x09203233732e6275,0x25202c3832317225\n"
".quad 0x3b31202c38323172,0x33752e766f6d090a,0x3033317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c34317025092032,0x202c383231722520,0x090a3b3033317225\n"
".quad 0x7262203431702540,0x315f744c24092061,0x0a3b36363034325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31383220\n"
".quad 0x6c6562616c206461,0x5f315f4c24206465,0x61090a3234363631,0x09203233662e6464\n"
".quad 0x25202c3532326625,0x6625202c34323266,0x6f6d090a3b323232,0x2509203233662e76\n"
".quad 0x6630202c36323266,0x3030303030383034,0x202f2f092020203b,0x2e70746573090a34\n"
".quad 0x09203233662e746c,0x6625202c35317025,0x326625202c353232,0x702540090a3b3632\n"
".quad 0x0920617262203531,0x3636315f315f4c24,0x5f744c240a3b3234,0x3a36363034325f31\n"
".quad 0x36315f315f4c240a,0x2f2f200a3a383938,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x383220656e696c20,0x2064616568202c36,0x2064656c6562616c\n"
".quad 0x38315f315f744c24,0x6f6c2e090a303936,0x3232330937310963,0x2e766f6d090a3009\n"
".quad 0x3172250920323373,0x090a3b30202c3133,0x2e74672e70746573,0x3170250920323373\n"
".quad 0x3832317225202c36,0x3b3133317225202c,0x3109636f6c2e090a,0x0a30093038320936\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5b202c37323172,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344,0x3472616863753650\n"
".quad 0x6666666666696969,0x696969695f536666,0x68636e7572635f62,0x636f6c2e090a3b5d\n"
".quad 0x0932323309373109,0x732e627573090a30,0x3331722509203233,0x3732317225202c32\n"
".quad 0x3b3832317225202c,0x33732e766f6d090a,0x3333317225092032,0x6573090a3b30202c\n"
".quad 0x09203233732e706c,0x25202c3433317225,0x7225202c32333172,0x317025202c333331\n"
".quad 0x2e766f6d090a3b36,0x3172250920323375,0x090a3b30202c3533,0x2e71652e70746573\n"
".quad 0x3170250920323373,0x3433317225202c37,0x3b3533317225202c,0x203731702540090a\n"
".quad 0x744c240920617262,0x36383732325f315f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c36383220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x30393638315f315f,0x3109636f6c2e090a,0x0a30093932330937\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5b202c36333172,0x726170616475635f\n"
".quad 0x614d38315a5f5f6d,0x746f72626c65646e,0x33316d735f315344,0x3472616863753650\n"
".quad 0x6666666666696969,0x696969695f536666,0x74616d696e615f62,0x656d6172466e6f69\n"
".quad 0x2e646461090a3b5d,0x3172250920323373,0x33317225202c3733,0x3433317225202c36\n"
".quad 0x61702e646c090a3b,0x092038752e6d6172,0x5b202c3833317225,0x6170616475635f5f\n"
".quad 0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x726f6c6f635f6269,0x6d090a3b5d302b73\n"
".quad 0x33732e6f6c2e6c75,0x3933317225092032,0x2c3733317225202c,0x0a3b383331722520\n"
".quad 0x2e38752e74766309,0x3172250920323375,0x33317225202c3034,0x636f6c2e090a3b39\n"
".quad 0x0930333309373109,0x61702e646c090a30,0x092038752e6d6172,0x5b202c3134317225\n"
".quad 0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61,0x316d735f31534474\n"
".quad 0x7261686375365033,0x6666666669696934,0x6969695f53666666,0x726f6c6f635f6269\n"
".quad 0x6d090a3b5d312b73,0x33732e6f6c2e6c75,0x3234317225092032,0x2c3733317225202c\n"
".quad 0x0a3b313431722520,0x2e38752e74766309,0x3172250920323375,0x34317225202c3334\n"
".quad 0x636f6c2e090a3b32,0x0931333309373109,0x61702e646c090a30,0x092038752e6d6172\n"
".quad 0x5b202c3434317225,0x6170616475635f5f,0x4d38315a5f5f6d72,0x6f72626c65646e61\n"
".quad 0x316d735f31534474,0x7261686375365033,0x6666666669696934,0x6969695f53666666\n"
".quad 0x726f6c6f635f6269,0x6d090a3b5d322b73,0x33732e6f6c2e6c75,0x3534317225092032\n"
".quad 0x2c3733317225202c,0x0a3b343431722520,0x2e38752e74766309,0x3172250920323375\n"
".quad 0x34317225202c3634,0x2e617262090a3b35,0x744c240920696e75,0x30333532325f315f\n"
".quad 0x5f315f744c240a3b,0x200a3a3638373232,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x2e090a3039363831,0x3309373109636f6c,0x6f6d090a30093533\n"
".quad 0x2509203233752e76,0x3b30202c36343172,0x33752e766f6d090a,0x3334317225092032\n"
".quad 0x6f6d090a3b30202c,0x2509203233752e76,0x3b30202c30343172,0x325f315f744c240a\n"
".quad 0x2f200a3a30333532,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3638,0x64656c6562616c20,0x315f315f744c2420\n"
".quad 0x6c2e090a30393638,0x343309373109636f,0x2e646c090a300931,0x33732e6d61726170\n"
".quad 0x3734317225092032,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831\n"
".quad 0x5f315344746f7262,0x6375365033316d73,0x6669696934726168,0x5f53666666666666\n"
".quad 0x72665f6269696969,0x61090a3b5d656d61,0x09203233732e6464,0x25202c3834317225\n"
".quad 0x3b31202c37343172,0x33732e726873090a,0x3934317225092032,0x2c3834317225202c\n"
".quad 0x6f6d090a3b313320,0x2509203233732e76,0x3b31202c30353172,0x33622e646e61090a\n"
".quad 0x3135317225092032,0x2c3934317225202c,0x0a3b303531722520,0x3233732e64646109\n"
".quad 0x2c32353172250920,0x202c313531722520,0x090a3b3834317225,0x203233732e726873\n"
".quad 0x202c333531722509,0x31202c3235317225,0x6c2e6c756d090a3b,0x2509203233732e6f\n"
".quad 0x7225202c34353172,0x337225202c373431,0x2e646461090a3b35,0x3172250920323373\n"
".quad 0x34317225202c3535,0x3435317225202c30,0x732e646461090a3b,0x3531722509203233\n"
".quad 0x3335317225202c36,0x3b3535317225202c,0x33732e766964090a,0x3735317225092032\n"
".quad 0x2c3635317225202c,0x0a3b383431722520,0x373109636f6c2e09,0x090a300932343309\n"
".quad 0x732e6f6c2e6c756d,0x3531722509203233,0x3734317225202c38,0x0a3b36337225202c\n"
".quad 0x3233732e64646109,0x2c39353172250920,0x202c333431722520,0x090a3b3835317225\n"
".quad 0x203233732e646461,0x202c303631722509,0x25202c3335317225,0x64090a3b39353172\n"
".quad 0x09203233732e7669,0x25202c3136317225,0x7225202c30363172,0x7473090a3b383431\n"
".quad 0x2e6c61626f6c672e,0x5b092038752e3276,0x2c5d302b35647225,0x2c37353172257b20\n"
".quad 0x0a3b7d3136317225,0x373109636f6c2e09,0x090a300933343309,0x732e6f6c2e6c756d\n"
".quad 0x3631722509203233,0x3734317225202c32,0x0a3b37337225202c,0x3233732e64646109\n"
".quad 0x2c33363172250920,0x202c363431722520,0x090a3b3236317225,0x203233732e646461\n"
".quad 0x202c343631722509,0x25202c3335317225,0x64090a3b33363172,0x09203233732e7669\n"
".quad 0x25202c3536317225,0x7225202c34363172,0x7473090a3b383431,0x2e6c61626f6c672e\n"
".quad 0x6472255b09203875,0x7225202c5d322b35,0x744c240a3b353631,0x36303531325f315f\n"
".quad 0x5f315f744c240a3a,0x200a3a3634393831,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c363832,0x656c6562616c2064\n"
".quad 0x5f315f744c242064,0x2e090a3039363831,0x3309373109636f6c,0x6162090a30093734\n"
".quad 0x0920636e79732e72,0x2e766f6d090a3b30,0x3172250920323375,0x090a3b30202c3636\n"
".quad 0x2e71652e70746573,0x3170250920323373,0x202c377225202c38,0x090a3b3636317225\n"
".quad 0x7262203831702540,0x315f744c24092061,0x0a3b32343033325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c36383220\n"
".quad 0x6c6562616c206461,0x315f744c24206465,0x090a30393638315f,0x09373109636f6c2e\n"
".quad 0x6d090a3009313533,0x09203436752e766f,0x62202c3231647225,0x6e756f436b636f6c\n"
".quad 0x6f6d090a3b726574,0x2509203233752e76,0x3b31202c37363172,0x672e6d6f7461090a\n"
".quad 0x64612e6c61626f6c,0x2509203233752e64,0x255b202c38363172,0x25202c5d32316472\n"
".quad 0x6d090a3b37363172,0x09203233732e766f,0x25202c3936317225,0x73090a3b38363172\n"
".quad 0x6465726168732e74,0x5f5b09203233752e,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32345f3938363632,0x6e496b636f6c625f,0x7225202c5d786564,0x6c2e090a3b393631\n"
".quad 0x353309373109636f,0x2e646c090a300932,0x33752e6d61726170,0x3037317225092032\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3831,0x5f315344746f7262\n"
".quad 0x6375365033316d73,0x6669696934726168,0x5f53666666666666,0x72675f6269696969\n"
".quad 0x5d68746469576469,0x752e6d6572090a3b,0x3731722509203233,0x3936317225202c31\n"
".quad 0x3b3037317225202c,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x30393636325f7261,0x636f6c625f32345f,0x317225202c5d586b\n"
".quad 0x6f6c2e090a3b3137,0x3335330937310963,0x2e766964090a3009,0x3172250920323375\n"
".quad 0x36317225202c3237,0x3037317225202c39,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x393636325f726176,0x6f6c625f30355f30\n"
".quad 0x7225202c5d596b63,0x744c240a3b323731,0x32343033325f315f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c36383220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x30393638315f315f,0x3109636f6c2e090a\n"
".quad 0x0a30093635330937,0x6e79732e72616209,0x6c090a3b30092063,0x6465726168732e64\n"
".quad 0x722509203233752e,0x5f5f5b202c333731,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f32345f39383636,0x646e496b636f6c62,0x6573090a3b5d7865,0x33752e746c2e7074\n"
".quad 0x2c39317025092032,0x202c333731722520,0x40090a3b35317225,0x6172622039317025\n"
".quad 0x5f315f744c240920,0x240a3b3039363831,0x3138315f315f744c,0x6f6c2e090a3a3837\n"
".quad 0x3935330937310963,0x74697865090a3009,0x6e6557444c240a3b,0x614d38315a5f5f64\n"
".quad 0x746f72626c65646e,0x33316d735f315344,0x3472616863753650,0x6666666666696969\n"
".quad 0x696969695f536666,0x2f2f207d090a3a62,0x6e614d38315a5f20,0x44746f72626c6564\n"
".quad 0x5033316d735f3153,0x6934726168637536,0x6666666666666969,0x62696969695f5366\n"
".quad 0x72746e652e090a0a,0x614d36315a5f2079,0x746f72626c65646e,0x664933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x61702e09090a2820,0x3436752e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x0a2c7473645f6269,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x0a2c576567616d69,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x0a2c486567616d69,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x0a2c68636e757263,0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x09090a2c66664f78,0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x31694c664933316d,0x6375365076454536\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x4f795f6269696969\n"
".quad 0x702e09090a2c6666,0x33662e206d617261,0x616475635f5f2032,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f30746f72,0x453631694c664933,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x2c504a785f626969\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x09090a2c504a795f\n"
".quad 0x2e206d617261702e,0x75635f5f20323366,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x31694c664933316d,0x6375365076454536,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x63735f6269696969,0x2e09090a2c656c61\n"
".quad 0x612e206d61726170,0x2e2034206e67696c,0x6475635f5f203862,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x6c6f635f62696969\n"
".quad 0x0a2c5d345b73726f,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x090a2c656d617266,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x615f62696969695f\n"
".quad 0x6e6f6974616d696e,0x090a2c656d617246,0x206d617261702e09,0x635f5f203233732e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x675f62696969695f,0x6874646957646972,0x7261702e09090a2c,0x203233732e206d61\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c66,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x6f6c426d756e5f62,0x2e09090a2c736b63,0x732e206d61726170\n"
".quad 0x616475635f5f2038,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72\n"
".quad 0x453631694c664933,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x294a73695f626969,0x65722e090a7b090a,0x25203233752e2067\n"
".quad 0x722e090a3b317672,0x203233752e206765,0x3b3e3630313c7225,0x2e206765722e090a\n"
".quad 0x3c64722520343675,0x722e090a3b3e3831,0x203233662e206765,0x0a3b3e32323c6625\n"
".quad 0x702e206765722e09,0x323c702520646572,0x68732e090a3b3e31,0x33752e2064657261\n"
".quad 0x616475635f5f2032,0x765f6c61636f6c5f,0x34343436325f7261,0x636f6c625f32345f\n"
".quad 0x0a3b7865646e496b,0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f32345f35343436,0x0a3b586b636f6c62,0x6465726168732e09\n"
".quad 0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30355f35343436\n"
".quad 0x0a3b596b636f6c62,0x206c61636f6c2e09,0x34206e67696c612e,0x635f5f2038622e20\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3436325f7261765f,0x5f6d5f31315f3936\n"
".quad 0x34365b3830323631,0x636f6c2e090a3b5d,0x67696c612e206c61,0x2038622e2034206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x5f365f3836343632\n"
".quad 0x3230385f736f5078,0x0a3b5d34365b3237,0x373109636f6c2e09,0x4c240a3009383209\n"
".quad 0x5f6e696765625744,0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x0a3a62696969695f,0x3233752e74766309,0x722509203631752e,0x2e64697425202c31\n"
".quad 0x2e766f6d090a3b78,0x3272250920323375,0x6573090a3b30202c,0x33752e71652e7074\n"
".quad 0x202c317025092032,0x327225202c317225,0x752e747663090a3b,0x09203631752e3233\n"
".quad 0x697425202c337225,0x6f6d090a3b792e64,0x2509203233752e76,0x090a3b30202c3472\n"
".quad 0x2e71652e70746573,0x3270250920323375,0x25202c337225202c,0x6c6573090a3b3472\n"
".quad 0x2509203233732e70,0x30202c31202c3572,0x090a3b317025202c,0x3233732e706c6573\n"
".quad 0x31202c3672250920,0x327025202c30202c,0x622e646e61090a3b,0x2c37722509203233\n"
".quad 0x7225202c35722520,0x2e766f6d090a3b36,0x3872250920323375,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x202c337025092032,0x387225202c377225,0x2033702540090a3b\n"
".quad 0x744c240920617262,0x30373533315f325f,0x09636f6c2e090a3b,0x0a30093533093731\n"
".quad 0x3436752e766f6d09,0x202c316472250920,0x756f436b636f6c62,0x6d090a3b7265746e\n"
".quad 0x09203233752e766f,0x0a3b31202c397225,0x6c672e6d6f746109,0x6464612e6c61626f\n"
".quad 0x722509203233752e,0x6472255b202c3031,0x3b397225202c5d31,0x33732e766f6d090a\n"
".quad 0x2c31317225092032,0x090a3b3031722520,0x65726168732e7473,0x5b09203233752e64\n"
".quad 0x6c5f616475635f5f,0x7261765f6c61636f,0x345f34343436325f,0x496b636f6c625f32\n"
".quad 0x25202c5d7865646e,0x6c2e090a3b313172,0x363309373109636f,0x702e646c090a3009\n"
".quad 0x3233752e6d617261,0x202c323172250920,0x70616475635f5f5b,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x57646972675f6269\n"
".quad 0x090a3b5d68746469,0x203233752e6d6572,0x25202c3331722509,0x317225202c313172\n"
".quad 0x732e7473090a3b32,0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164\n"
".quad 0x3436325f7261765f,0x6c625f32345f3534,0x25202c5d586b636f,0x6c2e090a3b333172\n"
".quad 0x373309373109636f,0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34\n"
".quad 0x090a3b3231722520,0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x355f35343436325f,0x596b636f6c625f30,0x3b34317225202c5d\n"
".quad 0x315f325f744c240a,0x2e090a3a30373533,0x3309373109636f6c,0x726162090a300939\n"
".quad 0x300920636e79732e,0x61702e646c090a3b,0x203233752e6d6172,0x5b202c3531722509\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c66,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x6f6c426d756e5f62,0x6c090a3b5d736b63,0x6465726168732e64\n"
".quad 0x722509203233752e,0x635f5f5b202c3631,0x61636f6c5f616475,0x36325f7261765f6c\n"
".quad 0x625f32345f343434,0x65646e496b636f6c,0x746573090a3b5d78,0x3233752e65672e70\n"
".quad 0x25202c3470250920,0x317225202c363172,0x34702540090a3b35,0x4c24092061726220\n"
".quad 0x383034315f325f74,0x702e646c090a3b32,0x3233732e6d617261,0x202c373172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6567616d695f6269,0x2e646c090a3b5d48,0x33732e6d61726170\n"
".quad 0x2c38317225092032,0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c664933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x67616d695f626969,0x7663090a3b5d5765\n"
".quad 0x31752e3233752e74,0x2c39317225092036,0x792e6469746e2520,0x752e747663090a3b\n"
".quad 0x09203631752e3233,0x6e25202c30327225,0x090a3b782e646974,0x203436752e766f6d\n"
".quad 0x5f202c3264722509,0x5f5f5f616475635f,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f31315f39363436,0x3b38303236315f6d,0x36752e766f6d090a,0x2c33647225092034\n"
".quad 0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f,0x365f38363436325f\n"
".quad 0x30385f736f50785f,0x744c240a3b323732,0x34393534315f325f,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x6c090a393320656e,0x6465726168732e64\n"
".quad 0x722509203233752e,0x635f5f5b202c3132,0x61636f6c5f616475,0x36325f7261765f6c\n"
".quad 0x625f32345f353434,0x0a3b5d586b636f6c,0x2e6f6c2e6c756d09,0x3272250920323375\n"
".quad 0x2c31327225202c32,0x090a3b3032722520,0x65726168732e646c,0x2509203233752e64\n"
".quad 0x5f5f5b202c333272,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30355f35343436\n"
".quad 0x3b5d596b636f6c62,0x6f6c2e6c756d090a,0x722509203233752e,0x33327225202c3432\n"
".quad 0x0a3b39317225202c,0x3233752e64646109,0x202c353272250920,0x7225202c32327225\n"
".quad 0x2e646461090a3b31,0x3272250920323375,0x2c34327225202c36,0x6d090a3b33722520\n"
".quad 0x33752e6f6c2e6c75,0x2c37327225092032,0x31202c3532722520,0x2e646461090a3b36\n"
".quad 0x3272250920323373,0x2c37327225202c38,0x696d090a3b363120,0x2509203233732e6e\n"
".quad 0x317225202c393272,0x3b37327225202c38,0x33732e6e696d090a,0x2c30337225092032\n"
".quad 0x25202c3832722520,0x7573090a3b383172,0x2509203233732e62,0x337225202c313372\n"
".quad 0x3b39327225202c30,0x33732e766f6d090a,0x2c32337225092032,0x746573090a3b3020\n"
".quad 0x3233732e74672e70,0x25202c3570250920,0x337225202c313372,0x706c6573090a3b32\n"
".quad 0x722509203233732e,0x30202c31202c3333,0x090a3b357025202c,0x752e74672e746573\n"
".quad 0x09203233732e3233,0x7225202c34337225,0x36327225202c3731,0x732e67656e090a3b\n"
".quad 0x3533722509203233,0x0a3b34337225202c,0x3233622e646e6109,0x202c363372250920\n"
".quad 0x7225202c33337225,0x766f6d090a3b3533,0x722509203233752e,0x090a3b30202c3733\n"
".quad 0x2e71652e70746573,0x3670250920323373,0x202c36337225202c,0x40090a3b37337225\n"
".quad 0x2061726220367025,0x315f325f744c2409,0x2f200a3b34333438,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x34315f325f744c24,0x252140090a343935,0x0920617262203570\n"
".quad 0x32325f325f744c24,0x2f2f200a3b383130,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f325f744c,0x2e766f6d090a3439,0x3372250920323373,0x3b31337225202c38\n"
".quad 0x2e34326c756d090a,0x09203233752e6f6c,0x7225202c39337225,0x090a3b3631202c31\n"
".quad 0x752e6f6c2e6c756d,0x3034722509203233,0x202c32327225202c,0x646461090a3b3631\n"
".quad 0x722509203233732e,0x39337225202c3134,0x0a3b30347225202c,0x3436752e766f6d09\n"
".quad 0x202c346472250920,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x5f365f3836343632,0x3230385f736f5078,0x766f6d090a3b3237,0x722509203233732e\n"
".quad 0x31347225202c3234,0x732e646461090a3b,0x3334722509203233,0x202c31347225202c\n"
".quad 0x6c090a3b31337225,0x2e6d617261702e64,0x3166250920323366,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c66493331\n"
".quad 0x6863753650764545,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x664f785f62696969,0x2e646c090a3b5d66,0x33662e6d61726170,0x202c326625092032\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x656c6163735f6269,0x6c3c2f2f200a3b5d,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34393534315f325f,0x33732e766f6d090a,0x2c34347225092032\n"
".quad 0x240a3b3833722520,0x3835315f325f744c,0x3c2f2f200a3a3437,0x6f4c203e706f6f6c\n"
".quad 0x2079646f6220706f,0x2c393320656e696c,0x676e697473656e20,0x203a687470656420\n"
".quad 0x6d69747365202c31,0x6574692064657461,0x3a736e6f69746172,0x6e776f6e6b6e7520\n"
".quad 0x3109636f6c2e090a,0x090a300938350937,0x662e6e722e747663,0x09203233732e3233\n"
".quad 0x347225202c336625,0x636f6c2e090a3b32,0x3009393309373109,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5f5b202c326625,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x0a3b5d656c616373\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x635f5f5b202c3166,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x785f62696969695f\n"
".quad 0x2e090a3b5d66664f,0x3509373109636f6c,0x64616d090a300938,0x662509203233662e\n"
".quad 0x202c336625202c34,0x316625202c326625,0x6f6c2e7473090a3b,0x203233662e6c6163\n"
".quad 0x302b346472255b09,0x0a3b346625202c5d,0x3233732e64646109,0x202c323472250920\n"
".quad 0x3b31202c32347225,0x36752e646461090a,0x2c34647225092034,0x34202c3464722520\n"
".quad 0x2e70746573090a3b,0x09203233732e656e,0x347225202c377025,0x3b33347225202c32\n"
".quad 0x622037702540090a,0x5f744c2409206172,0x3b34373835315f32,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x6568202c39332065\n"
".quad 0x6c6562616c206461,0x325f744c24206465,0x090a34393534315f,0x20696e752e617262\n"
".quad 0x315f325f744c2409,0x4c240a3b32363335,0x313032325f325f74,0x6c3c2f2f200a3a38\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x34393534315f325f,0x7261702e646c090a\n"
".quad 0x09203233662e6d61,0x5f5f5b202c326625,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x0a3b5d656c616373\n"
".quad 0x35315f325f744c24,0x2f2f200a3a323633,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f325f744c,0x636f6c2e090a3439,0x0938333109363109,0x61702e646c090a30\n"
".quad 0x203233732e6d6172,0x5b202c3534722509,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c66,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x68636e7572635f62\n"
".quad 0x2e766f6d090a3b5d,0x3472250920323373,0x3b35347225202c36,0x7261702e646c090a\n"
".quad 0x25092038732e6d61,0x5f5f5b202c373472,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x6d090a3b5d4a7369\n"
".quad 0x09203233732e766f,0x3b30202c38347225,0x6e2e70746573090a,0x2509203233732e65\n"
".quad 0x37347225202c3870,0x0a3b38347225202c,0x2e6e722e74766309,0x203233732e323366\n"
".quad 0x7225202c35662509,0x2e646c090a3b3632,0x33662e6d61726170,0x202c366625092032\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6649,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x5d66664f795f6269,0x662e64616d090a3b,0x2c37662509203233\n"
".quad 0x6625202c35662520,0x0a3b366625202c32,0x61636f6c2e646c09,0x2509203233662e6c\n"
".quad 0x635f5f5b202c3866,0x75635f5f5f616475,0x6c61636f6c5f6164,0x3436325f7261765f\n"
".quad 0x6f50785f365f3836,0x2b32373230385f73,0x252140090a3b5d30,0x0920617262203870\n"
".quad 0x36315f325f744c24,0x2f2f200a3b323436,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f325f744c,0x636f6c2e090a3439,0x0934343109363109,0x61702e646c090a30\n"
".quad 0x203233662e6d6172,0x5f5b202c39662509,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f30,0x507645453631694c,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x090a3b5d504a785f\n"
".quad 0x09363109636f6c2e,0x6c090a3009353431,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x75635f5f5b202c30,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c664933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x4a795f6269696969,0x6f6c2e090a3b5d50,0x3634310936310963\n"
".quad 0x2e766f6d090a3009,0x3166250920323366,0x0a3b376625202c31,0x363109636f6c2e09\n"
".quad 0x090a300937343109,0x203233662e766f6d,0x25202c3231662509,0x6f6c2e090a3b3866\n"
".quad 0x3834310936310963,0x2e6c756d090a3009,0x3166250920323366,0x202c376625202c33\n"
".quad 0x6c2e090a3b376625,0x343109363109636f,0x6c756d090a300939,0x662509203233662e\n"
".quad 0x2c386625202c3431,0x62090a3b38662520,0x0920696e752e6172,0x36315f325f744c24\n"
".quad 0x744c240a3b363833,0x32343636315f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393320656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34393534315f32,0x363109636f6c2e09,0x090a300933353109\n"
".quad 0x203233662e766f6d,0x6625202c39662509,0x636f6c2e090a3b38,0x0934353109363109\n"
".quad 0x662e766f6d090a30,0x3031662509203233,0x090a3b376625202c,0x09363109636f6c2e\n"
".quad 0x6d090a3009383531,0x09203233662e766f,0x6630202c34316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c33\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c323166250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x6f6d090a30202f2f,0x2509203233662e76\n"
".quad 0x306630202c313166,0x3b30303030303030,0x202f2f0920202020,0x5f325f744c240a30\n"
".quad 0x200a3a3638333631,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20,0x315f325f744c2420\n"
".quad 0x6f6d090a34393534,0x2509203233752e76,0x0a3b30202c393472,0x71652e7074657309\n"
".quad 0x702509203233732e,0x2c31337225202c39,0x090a3b3934722520,0x6172622039702540\n"
".quad 0x5f325f744c240920,0x200a3b3839383631,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20\n"
".quad 0x315f325f744c2420,0x6f6d090a34393534,0x2509203233732e76,0x0a3b30202c303572\n"
".quad 0x37315f325f744c24,0x2f2f200a3a303134,0x4c203e706f6f6c3c,0x79646f6220706f6f\n"
".quad 0x353120656e696c20,0x697473656e202c38,0x687470656420676e,0x747365202c32203a\n"
".quad 0x6920646574616d69,0x6e6f697461726574,0x6f6e6b6e75203a73,0x636f6c2e090a6e77\n"
".quad 0x0932363109363109,0x732e627573090a30,0x3634722509203233,0x202c36347225202c\n"
".quad 0x2e766f6d090a3b31,0x3572250920323375,0x73090a3b30202c31,0x732e656c2e707465\n"
".quad 0x3031702509203233,0x202c36347225202c,0x40090a3b31357225,0x6172622030317025\n"
".quad 0x315f325f4c240920,0x2f200a3b34313333,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3835,0x64656c6562616c20\n"
".quad 0x315f325f744c2420,0x6461090a30313437,0x2509203233662e64,0x316625202c353166\n"
".quad 0x3b33316625202c34,0x33662e766f6d090a,0x2c36316625092032,0x3030383034663020\n"
".quad 0x202020203b303030,0x73090a34202f2f09,0x662e74672e707465,0x3131702509203233\n"
".quad 0x202c35316625202c,0x40090a3b36316625,0x7262203131702521,0x5f325f4c24092061\n"
".quad 0x240a3b3835303331,0x313333315f325f4c,0x6c3c2f2f200a3a34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x313437315f325f74,0x09636f6c2e090a30,0x3009333631093631\n"
".quad 0x36732e747663090a,0x2509203233732e34,0x357225202c356472,0x2e6c756d090a3b30\n"
".quad 0x3233732e65646977,0x202c366472250920,0x3b34202c30357225,0x36752e646461090a\n"
".quad 0x2c37647225092034,0x25202c3264722520,0x7473090a3b366472,0x732e6c61636f6c2e\n"
".quad 0x6472255b09203233,0x7225202c5d302b37,0x6f6c2e090a3b3634,0x3536310936310963\n"
".quad 0x2e646461090a3009,0x3572250920323373,0x2c30357225202c30,0x746573090a3b3120\n"
".quad 0x3233732e71652e70,0x202c323170250920,0x7225202c31337225,0x702540090a3b3035\n"
".quad 0x0920617262203231,0x36315f325f744c24,0x2f2f200a3b383938,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x353120656e696c20,0x2064616568202c38\n"
".quad 0x2064656c6562616c,0x37315f325f744c24,0x747663090a303134,0x3233732e3436732e\n"
".quad 0x202c386472250920,0x6d090a3b30357225,0x2e656469772e6c75,0x6472250920323373\n"
".quad 0x2c30357225202c39,0x646461090a3b3420,0x722509203436752e,0x647225202c303164\n"
".quad 0x3b39647225202c33,0x636f6c2e646c090a,0x09203233662e6c61,0x255b202c37316625\n"
".quad 0x3b5d302b30316472,0x203870252140090a,0x744c240920617262,0x32323937315f325f\n"
".quad 0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c38353120656e,0x62616c2064616568,0x744c242064656c65,0x30313437315f325f\n"
".quad 0x3109636f6c2e090a,0x0a30093736310936,0x617261702e646c09,0x2509203233662e6d\n"
".quad 0x635f5f5b202c3966,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x694c664933316d73,0x7536507645453631,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x785f62696969695f,0x6c2e090a3b5d504a,0x363109363109636f\n"
".quad 0x2e646c090a300938,0x33662e6d61726170,0x2c30316625092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c664933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x5d504a795f626969,0x09636f6c2e090a3b,0x3009393631093631,0x33662e766f6d090a\n"
".quad 0x2c31316625092032,0x2e090a3b37662520,0x3109363109636f6c,0x6f6d090a30093037\n"
".quad 0x2509203233662e76,0x316625202c323166,0x636f6c2e090a3b37,0x0931373109363109\n"
".quad 0x662e6c756d090a30,0x3331662509203233,0x25202c376625202c,0x6f6c2e090a3b3766\n"
".quad 0x3237310936310963,0x2e6c756d090a3009,0x3166250920323366,0x2c37316625202c34\n"
".quad 0x090a3b3731662520,0x20696e752e617262,0x315f325f744c2409,0x4c240a3b36363637\n"
".quad 0x323937315f325f74,0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313437315f325f74,0x09636f6c2e090a30,0x3009353731093631,0x33662e766f6d090a\n"
".quad 0x202c396625092032,0x2e090a3b37316625,0x3109363109636f6c,0x6f6d090a30093637\n"
".quad 0x2509203233662e76,0x376625202c303166,0x09636f6c2e090a3b,0x3009303831093631\n"
".quad 0x33662e766f6d090a,0x2c34316625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6630202c33316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c32\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x3233662e766f6d09,0x202c313166250920\n"
".quad 0x3030303030306630,0x09202020203b3030,0x744c240a30202f2f,0x36363637315f325f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c38353120656e,0x62616c2064616568,0x744c242064656c65,0x30313437315f325f\n"
".quad 0x3109636f6c2e090a,0x0a30093833310936,0x617261702e646c09,0x2509203233732e6d\n"
".quad 0x5f5f5b202c353472,0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564\n"
".quad 0x4c664933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x3b5d68636e757263,0x3109636f6c2e090a\n"
".quad 0x0a30093338310936,0x3233732e766f6d09,0x202c363472250920,0x4c240a3b35347225\n"
".quad 0x38353033315f325f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c38353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313437315f325f,0x3109636f6c2e090a,0x0a30093538310936,0x3233662e6c756d09\n"
".quad 0x202c383166250920,0x6625202c32316625,0x646461090a3b3131,0x662509203233662e\n"
".quad 0x38316625202c3931,0x0a3b38316625202c,0x3233662e64646109,0x202c313166250920\n"
".quad 0x6625202c30316625,0x6f6c2e090a3b3931,0x3638310936310963,0x2e627573090a3009\n"
".quad 0x3266250920323366,0x2c34316625202c30,0x090a3b3331662520,0x203233662e646461\n"
".quad 0x25202c3231662509,0x30326625202c3966,0x09636f6c2e090a3b,0x3009373831093631\n"
".quad 0x33662e6c756d090a,0x2c33316625092032,0x25202c3131662520,0x6c2e090a3b313166\n"
".quad 0x383109363109636f,0x6c756d090a300938,0x662509203233662e,0x32316625202c3431\n"
".quad 0x0a3b32316625202c,0x656e2e7074657309,0x702509203233732e,0x31337225202c3331\n"
".quad 0x0a3b30357225202c,0x6220333170254009,0x5f744c2409206172,0x3b30313437315f32\n"
".quad 0x315f325f744c240a,0x4c240a3a38393836,0x5f5f69646e655744,0x4d636c614334315a\n"
".quad 0x6f72626c65646e61,0x5069507645664974,0x31535f31535f544b,0x5f6962695f31535f\n"
".quad 0x200a3a315f323132,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20,0x315f325f744c2420\n"
".quad 0x6c2e090a34393534,0x323609373109636f,0x70252140090a3009,0x2409206172622035\n"
".quad 0x3438315f325f744c,0x3c2f2f200a3b3433,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393320656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393534315f325f74,0x732e766f6d090a34,0x3235722509203233,0x0a3b31337225202c\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5f5b202c333572,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x0a3b5d656d617266,0x3233732e766f6d09,0x202c343572250920,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3431702509,0x357225202c333572,0x2e766f6d090a3b34\n"
".quad 0x6472250920343675,0x75635f5f202c3131,0x6475635f5f5f6164,0x5f6c61636f6c5f61\n"
".quad 0x363436325f726176,0x315f6d5f31315f39,0x6d090a3b38303236,0x33732e6f6c2e6c75\n"
".quad 0x2c35357225092032,0x25202c3831722520,0x6461090a3b363272,0x2509203233732e64\n"
".quad 0x327225202c363572,0x3b35357225202c37,0x33732e766f6d090a,0x2c37357225092032\n"
".quad 0x090a3b3635722520,0x203233732e646461,0x25202c3835722509,0x337225202c363572\n"
".quad 0x702e646c090a3b31,0x3436752e6d617261,0x2c32316472250920,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c664933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x5d7473645f626969,0x732e747663090a3b,0x09203233732e3436,0x25202c3331647225\n"
".quad 0x756d090a3b363572,0x732e656469772e6c,0x3164722509203233,0x2c36357225202c34\n"
".quad 0x646461090a3b3420,0x722509203436752e,0x647225202c353164,0x31647225202c3231\n"
".quad 0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x202c393320656e69,0x62616c2064616568,0x744c242064656c65,0x34393534315f325f\n"
".quad 0x33732e766f6d090a,0x2c39357225092032,0x240a3b3235722520,0x3938315f325f744c\n"
".quad 0x3c2f2f200a3a3634,0x6f4c203e706f6f6c,0x2079646f6220706f,0x2c323620656e696c\n"
".quad 0x676e697473656e20,0x203a687470656420,0x6d69747365202c31,0x6574692064657461\n"
".quad 0x3a736e6f69746172,0x6e776f6e6b6e7520,0x636f6c2e646c090a,0x09203233732e6c61\n"
".quad 0x255b202c30367225,0x3b5d302b31316472,0x33752e766f6d090a,0x2c31367225092032\n"
".quad 0x746573090a3b3020,0x3233732e656c2e70,0x202c353170250920,0x7225202c30367225\n"
".quad 0x702540090a3b3136,0x0920617262203531,0x39315f325f744c24,0x2f2f200a3b383534\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x323620656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3938315f325f744c,0x636f6c2e090a3634\n"
".quad 0x0938333109363109,0x61702e646c090a30,0x203233732e6d6172,0x5b202c3534722509\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074\n"
".quad 0x7645453631694c66,0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253\n"
".quad 0x696969695f30535f,0x68636e7572635f62,0x636f6c2e090a3b5d,0x3009353609373109\n"
".quad 0x33732e627573090a,0x2c32367225092032,0x25202c3534722520,0x7262090a3b303672\n"
".quad 0x240920696e752e61,0x3239315f325f744c,0x5f744c240a3b3230,0x3a38353439315f32\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c32362065,0x6c6562616c206461,0x325f744c24206465,0x090a36343938315f\n"
".quad 0x203233732e766f6d,0x30202c3236722509,0x5f325f744c240a3b,0x200a3a3230323931\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x64616568202c3236,0x64656c6562616c20,0x315f325f744c2420,0x7473090a36343938\n"
".quad 0x732e6c61636f6c2e,0x6472255b09203233,0x25202c5d302b3131,0x6f6d090a3b323672\n"
".quad 0x2509203233752e76,0x0a3b30202c333672,0x71652e7074657309,0x702509203233732e\n"
".quad 0x32367225202c3631,0x0a3b33367225202c,0x6220363170254009,0x5f744c2409206172\n"
".quad 0x3b30373939315f32,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c32362065,0x6c6562616c206461,0x325f744c24206465\n"
".quad 0x090a36343938315f,0x09373109636f6c2e,0x646c090a30093037,0x732e6d617261702e\n"
".quad 0x3436722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x696e615f62696969,0x72466e6f6974616d\n"
".quad 0x61090a3b5d656d61,0x09203233732e6464,0x7225202c35367225,0x32367225202c3436\n"
".quad 0x6f6c2e7473090a3b,0x203233732e6c6163,0x2b31316472255b09,0x35367225202c5d30\n"
".quad 0x09636f6c2e090a3b,0x0a30093137093731,0x617261702e646c09,0x7225092038752e6d\n"
".quad 0x635f5f5b202c3636,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x694c664933316d73,0x7536507645453631,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x635f62696969695f,0x5d302b73726f6c6f,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x367225202c373672,0x3b36367225202c35,0x38752e747663090a\n"
".quad 0x722509203233752e,0x37367225202c3836,0x09636f6c2e090a3b,0x0a30093237093731\n"
".quad 0x617261702e646c09,0x7225092038752e6d,0x635f5f5b202c3936,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x635f62696969695f\n"
".quad 0x5d312b73726f6c6f,0x6c2e6c756d090a3b,0x2509203233732e6f,0x367225202c303772\n"
".quad 0x3b39367225202c35,0x38752e747663090a,0x722509203233752e,0x30377225202c3137\n"
".quad 0x09636f6c2e090a3b,0x0a30093337093731,0x617261702e646c09,0x7225092038752e6d\n"
".quad 0x635f5f5b202c3237,0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65\n"
".quad 0x694c664933316d73,0x7536507645453631,0x6969693472616863,0x5f32535f32535f54\n"
".quad 0x30535f32535f3253,0x635f62696969695f,0x5d322b73726f6c6f,0x6c2e6c756d090a3b\n"
".quad 0x2509203233732e6f,0x367225202c333772,0x3b32377225202c35,0x38752e747663090a\n"
".quad 0x722509203233752e,0x33377225202c3437,0x752e617262090a3b,0x5f744c240920696e\n"
".quad 0x3b34313739315f32,0x315f325f744c240a,0x2f200a3a30373939,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3620656e696c2079,0x2064616568202c32\n"
".quad 0x2064656c6562616c,0x38315f325f744c24,0x6f6c2e090a363439,0x0937370937310963\n"
".quad 0x752e766f6d090a30,0x3437722509203233,0x6f6d090a3b30202c,0x2509203233752e76\n"
".quad 0x0a3b30202c313772,0x3233752e766f6d09,0x202c383672250920,0x325f744c240a3b30\n"
".quad 0x0a3a34313739315f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c323620,0x656c6562616c2064,0x5f325f744c242064\n"
".quad 0x40090a3634393831,0x7262203431702521,0x325f744c24092061,0x0a3b32383430325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c323620,0x656c6562616c2064,0x5f325f744c242064,0x2e090a3634393831\n"
".quad 0x3809373109636f6c,0x766f6d090a300934,0x722509203233752e,0x090a3b30202c3537\n"
".quad 0x61626f6c672e7473,0x2038752e34762e6c,0x2b35316472255b09,0x3672257b202c5d30\n"
".quad 0x252c313772252c38,0x353772252c343772,0x2e617262090a3b7d,0x744c240920696e75\n"
".quad 0x36323230325f325f,0x5f325f744c240a3b,0x200a3a3238343032,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3236\n"
".quad 0x64656c6562616c20,0x315f325f744c2420,0x6c2e090a36343938,0x323609373109636f\n"
".quad 0x702e646c090a3009,0x3233732e6d617261,0x202c333572250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6649\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x656d6172665f6269,0x636f6c2e090a3b5d,0x3009383809373109,0x33732e646461090a\n"
".quad 0x2c36377225092032,0x31202c3335722520,0x732e726873090a3b,0x3737722509203233\n"
".quad 0x202c36377225202c,0x766f6d090a3b3133,0x722509203233732e,0x090a3b31202c3837\n"
".quad 0x203233622e646e61,0x25202c3937722509,0x377225202c373772,0x2e646461090a3b38\n"
".quad 0x3872250920323373,0x2c39377225202c30,0x090a3b3637722520,0x203233732e726873\n"
".quad 0x25202c3138722509,0x0a3b31202c303872,0x626f6c672e646c09,0x38752e34762e6c61\n"
".quad 0x2c323872257b0920,0x3872252c33387225,0x255b202c7d5f2c34,0x3b5d302b35316472\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x33357225202c3538,0x0a3b32387225202c\n"
".quad 0x3233732e64646109,0x202c363872250920,0x7225202c38367225,0x646461090a3b3538\n"
".quad 0x722509203233732e,0x31387225202c3738,0x0a3b36387225202c,0x3233732e76696409\n"
".quad 0x202c383872250920,0x7225202c37387225,0x6f6c2e090a3b3637,0x0939380937310963\n"
".quad 0x6c2e6c756d090a30,0x2509203233732e6f,0x357225202c393872,0x3b33387225202c33\n"
".quad 0x33732e646461090a,0x2c30397225092032,0x25202c3137722520,0x6461090a3b393872\n"
".quad 0x2509203233732e64,0x387225202c313972,0x3b30397225202c31,0x33732e766964090a\n"
".quad 0x2c32397225092032,0x25202c3139722520,0x7473090a3b363772,0x2e6c61626f6c672e\n"
".quad 0x5b092038752e3276,0x5d302b3531647225,0x2c383872257b202c,0x090a3b7d32397225\n"
".quad 0x09373109636f6c2e,0x756d090a30093039,0x3233732e6f6c2e6c,0x202c333972250920\n"
".quad 0x7225202c33357225,0x646461090a3b3438,0x722509203233732e,0x34377225202c3439\n"
".quad 0x0a3b33397225202c,0x3233732e64646109,0x202c353972250920,0x7225202c31387225\n"
".quad 0x766964090a3b3439,0x722509203233732e,0x35397225202c3639,0x0a3b36377225202c\n"
".quad 0x626f6c672e747309,0x5b092038752e6c61,0x5d322b3531647225,0x0a3b36397225202c\n"
".quad 0x30325f325f744c24,0x2f2f200a3a363232,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x323620656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3938315f325f744c,0x2e646461090a3634,0x3572250920323373,0x2c37357225202c37\n"
".quad 0x646461090a3b3120,0x722509203436752e,0x647225202c353164,0x090a3b34202c3531\n"
".quad 0x203436752e646461,0x202c313164722509,0x34202c3131647225,0x2e70746573090a3b\n"
".quad 0x09203233732e656e,0x7225202c37317025,0x38357225202c3735,0x3731702540090a3b\n"
".quad 0x4c24092061726220,0x343938315f325f74,0x325f744c240a3b36,0x0a3a34333438315f\n"
".quad 0x34315f325f744c24,0x2f2f200a3a303538,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f325f744c,0x636f6c2e090a3439,0x3009353909373109,0x79732e726162090a\n"
".quad 0x090a3b300920636e,0x203233752e766f6d,0x30202c3739722509,0x2e70746573090a3b\n"
".quad 0x09203233732e7165,0x7225202c38317025,0x3b37397225202c37,0x203831702540090a\n"
".quad 0x744c240920617262,0x34393930325f325f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x68202c393320656e,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a34393534315f32,0x373109636f6c2e09,0x6d090a3009383909\n"
".quad 0x09203436752e766f,0x62202c3631647225,0x6e756f436b636f6c,0x6f6d090a3b726574\n"
".quad 0x2509203233752e76,0x0a3b31202c383972,0x6c672e6d6f746109,0x6464612e6c61626f\n"
".quad 0x722509203233752e,0x6472255b202c3939,0x397225202c5d3631,0x2e766f6d090a3b38\n"
".quad 0x3172250920323373,0x39397225202c3030,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x343436325f726176,0x6f6c625f32345f34\n"
".quad 0x5d7865646e496b63,0x3b3030317225202c,0x3109636f6c2e090a,0x090a300939390937\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x5f5f5b202c313031,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x7464695764697267,0x6d6572090a3b5d68,0x722509203233752e,0x317225202c323031\n"
".quad 0x30317225202c3030,0x732e7473090a3b31,0x33752e6465726168,0x75635f5f5b092032\n"
".quad 0x6c61636f6c5f6164,0x3436325f7261765f,0x6c625f32345f3534,0x25202c5d586b636f\n"
".quad 0x2e090a3b32303172,0x3109373109636f6c,0x6964090a30093030,0x2509203233752e76\n"
".quad 0x7225202c33303172,0x317225202c303031,0x2e7473090a3b3130,0x752e646572616873\n"
".quad 0x635f5f5b09203233,0x61636f6c5f616475,0x36325f7261765f6c,0x625f30355f353434\n"
".quad 0x202c5d596b636f6c,0x240a3b3330317225,0x3930325f325f744c,0x3c2f2f200a3a3439\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c393320656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x393534315f325f74,0x09636f6c2e090a34\n"
".quad 0x3009323031093731,0x79732e726162090a,0x090a3b300920636e,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5b202c34303172,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x32345f3434343632,0x6e496b636f6c625f,0x73090a3b5d786564,0x752e746c2e707465\n"
".quad 0x3931702509203233,0x2c3430317225202c,0x090a3b3531722520,0x7262203931702540\n"
".quad 0x325f744c24092061,0x0a3b34393534315f,0x34315f325f744c24,0x6c2e090a3a323830\n"
".quad 0x303109373109636f,0x697865090a300937,0x6557444c240a3b74,0x4d36315a5f5f646e\n"
".quad 0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c66,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x2f2f207d090a3a62\n"
".quad 0x6e614d36315a5f20,0x30746f72626c6564,0x4c664933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x0a62696969695f30\n"
".quad 0x7972746e652e090a,0x6e614d36315a5f20,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x2062696969695f30,0x7261702e09090a28,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3074,0x7645453631694c64\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x090a2c7473645f62,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f\n"
".quad 0x090a2c576567616d,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x695f62696969695f\n"
".quad 0x090a2c486567616d,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x635f62696969695f\n"
".quad 0x090a2c68636e7572,0x206d617261702e09,0x635f5f203436662e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x785f62696969695f\n"
".quad 0x2e09090a2c66664f,0x662e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x664f795f62696969\n"
".quad 0x61702e09090a2c66,0x3436662e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6449,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x0a2c504a785f6269\n"
".quad 0x6d617261702e0909,0x5f5f203436662e20,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x4c644933316d735f,0x3650764545363169,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x2e09090a2c504a79\n"
".quad 0x662e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3631694c64493331,0x6863753650764545,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x6163735f62696969,0x702e09090a2c656c\n"
".quad 0x6c612e206d617261,0x622e2034206e6769,0x616475635f5f2038,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x6f6c6f635f626969\n"
".quad 0x090a2c5d345b7372,0x206d617261702e09,0x635f5f203233732e,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x665f62696969695f\n"
".quad 0x09090a2c656d6172,0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d,0x6375365076454536\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6e615f6269696969\n"
".quad 0x466e6f6974616d69,0x09090a2c656d6172,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d\n"
".quad 0x6375365076454536,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x72675f6269696969,0x2c68746469576469,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x636f6c426d756e5f,0x702e09090a2c736b,0x38732e206d617261\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6449,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x0a294a73695f6269,0x6765722e090a7b09,0x7225203233752e20\n"
".quad 0x65722e090a3b3176,0x25203233752e2067,0x0a3b3e3630313c72,0x752e206765722e09\n"
".quad 0x313c647225203436,0x65722e090a3b3e38,0x25203436662e2067,0x0a3b3e32323c6466\n"
".quad 0x702e206765722e09,0x323c702520646572,0x68732e090a3b3e31,0x33752e2064657261\n"
".quad 0x616475635f5f2032,0x765f6c61636f6c5f,0x34343436325f7261,0x636f6c625f32345f\n"
".quad 0x0a3b7865646e496b,0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f32345f35343436,0x0a3b586b636f6c62,0x6465726168732e09\n"
".quad 0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30355f35343436\n"
".quad 0x0a3b596b636f6c62,0x206c61636f6c2e09,0x34206e67696c612e,0x635f5f2038622e20\n"
".quad 0x75635f5f5f616475,0x6c61636f6c5f6164,0x3436325f7261765f,0x5f6d5f31315f3936\n"
".quad 0x34365b3432343631,0x636f6c2e090a3b5d,0x67696c612e206c61,0x2038622e2038206e\n"
".quad 0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163,0x5f365f3836343632\n"
".quad 0x3430385f736f5078,0x3b5d3832315b3838,0x3109636f6c2e090a,0x240a300938320937\n"
".quad 0x6e6967656257444c,0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f\n"
".quad 0x3650764545363169,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x3a62696969695f30,0x33752e747663090a,0x2509203631752e32,0x64697425202c3172\n"
".quad 0x766f6d090a3b782e,0x722509203233752e,0x73090a3b30202c32,0x752e71652e707465\n"
".quad 0x2c31702509203233,0x7225202c31722520,0x2e747663090a3b32,0x203631752e323375\n"
".quad 0x7425202c33722509,0x6d090a3b792e6469,0x09203233752e766f,0x0a3b30202c347225\n"
".quad 0x71652e7074657309,0x702509203233752e,0x202c337225202c32,0x6573090a3b347225\n"
".quad 0x09203233732e706c,0x202c31202c357225,0x0a3b317025202c30,0x33732e706c657309\n"
".quad 0x202c367225092032,0x7025202c30202c31,0x2e646e61090a3b32,0x3772250920323362\n"
".quad 0x25202c357225202c,0x766f6d090a3b3672,0x722509203233752e,0x73090a3b30202c38\n"
".quad 0x732e71652e707465,0x2c33702509203233,0x7225202c37722520,0x33702540090a3b38\n"
".quad 0x4c24092061726220,0x373533315f335f74,0x636f6c2e090a3b30,0x3009353309373109\n"
".quad 0x36752e766f6d090a,0x2c31647225092034,0x6f436b636f6c6220,0x090a3b7265746e75\n"
".quad 0x203233752e766f6d,0x3b31202c39722509,0x672e6d6f7461090a,0x64612e6c61626f6c\n"
".quad 0x2509203233752e64,0x72255b202c303172,0x397225202c5d3164,0x732e766f6d090a3b\n"
".quad 0x3131722509203233,0x0a3b30317225202c,0x726168732e747309,0x09203233752e6465\n"
".quad 0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f34343436325f72,0x6b636f6c625f3234\n"
".quad 0x202c5d7865646e49,0x2e090a3b31317225,0x3309373109636f6c,0x2e646c090a300936\n"
".quad 0x33752e6d61726170,0x2c32317225092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x646972675f626969\n"
".quad 0x0a3b5d6874646957,0x3233752e6d657209,0x202c333172250920,0x7225202c31317225\n"
".quad 0x2e7473090a3b3231,0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x625f32345f353434,0x202c5d586b636f6c,0x2e090a3b33317225\n"
".quad 0x3309373109636f6c,0x766964090a300937,0x722509203233752e,0x31317225202c3431\n"
".quad 0x0a3b32317225202c,0x726168732e747309,0x09203233752e6465,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f35343436325f72,0x6b636f6c625f3035,0x34317225202c5d59\n"
".quad 0x5f335f744c240a3b,0x090a3a3037353331,0x09373109636f6c2e,0x6162090a30093933\n"
".quad 0x0920636e79732e72,0x702e646c090a3b30,0x3233752e6d617261,0x202c353172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6449,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x6c426d756e5f6269,0x090a3b5d736b636f,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5f5b202c363172,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f32345f34343436,0x646e496b636f6c62,0x6573090a3b5d7865,0x33752e65672e7074\n"
".quad 0x202c347025092032,0x7225202c36317225,0x702540090a3b3531,0x2409206172622034\n"
".quad 0x3034315f335f744c,0x2e646c090a3b3238,0x33732e6d61726170,0x2c37317225092032\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72\n"
".quad 0x453631694c644933,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x67616d695f626969,0x646c090a3b5d4865,0x732e6d617261702e\n"
".quad 0x3831722509203233,0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3631694c64493331,0x6863753650764545,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x616d695f62696969,0x63090a3b5d576567\n"
".quad 0x752e3233752e7476,0x3931722509203631,0x2e6469746e25202c,0x2e747663090a3b79\n"
".quad 0x203631752e323375,0x25202c3032722509,0x0a3b782e6469746e,0x3436752e766f6d09\n"
".quad 0x202c326472250920,0x5f5f616475635f5f,0x6f6c5f616475635f,0x5f7261765f6c6163\n"
".quad 0x31315f3936343632,0x34323436315f6d5f,0x752e766f6d090a3b,0x3364722509203436\n"
".quad 0x616475635f5f202c,0x5f616475635f5f5f,0x61765f6c61636f6c,0x5f38363436325f72\n"
".quad 0x385f736f50785f36,0x4c240a3b38383430,0x393534315f335f74,0x6c3c2f2f200a3a34\n"
".quad 0x6f6f4c203e706f6f,0x6c2079646f622070,0x090a393320656e69,0x65726168732e646c\n"
".quad 0x2509203233752e64,0x5f5f5b202c313272,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f32345f35343436,0x3b5d586b636f6c62,0x6f6c2e6c756d090a,0x722509203233752e\n"
".quad 0x31327225202c3232,0x0a3b30327225202c,0x726168732e646c09,0x09203233752e6465\n"
".quad 0x5f5b202c33327225,0x6f6c5f616475635f,0x5f7261765f6c6163,0x30355f3534343632\n"
".quad 0x5d596b636f6c625f,0x6c2e6c756d090a3b,0x2509203233752e6f,0x327225202c343272\n"
".quad 0x3b39317225202c33,0x33752e646461090a,0x2c35327225092032,0x25202c3232722520\n"
".quad 0x646461090a3b3172,0x722509203233752e,0x34327225202c3632,0x090a3b337225202c\n"
".quad 0x752e6f6c2e6c756d,0x3732722509203233,0x202c35327225202c,0x646461090a3b3631\n"
".quad 0x722509203233732e,0x37327225202c3832,0x6d090a3b3631202c,0x09203233732e6e69\n"
".quad 0x7225202c39327225,0x37327225202c3831,0x732e6e696d090a3b,0x3033722509203233\n"
".quad 0x202c38327225202c,0x73090a3b38317225,0x09203233732e6275,0x7225202c31337225\n"
".quad 0x39327225202c3033,0x732e766f6d090a3b,0x3233722509203233,0x6573090a3b30202c\n"
".quad 0x33732e74672e7074,0x202c357025092032,0x7225202c31337225,0x6c6573090a3b3233\n"
".quad 0x2509203233732e70,0x202c31202c333372,0x0a3b357025202c30,0x2e74672e74657309\n"
".quad 0x203233732e323375,0x25202c3433722509,0x327225202c373172,0x2e67656e090a3b36\n"
".quad 0x3372250920323373,0x3b34337225202c35,0x33622e646e61090a,0x2c36337225092032\n"
".quad 0x25202c3333722520,0x6f6d090a3b353372,0x2509203233752e76,0x0a3b30202c373372\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c36337225202c36,0x090a3b3733722520\n"
".quad 0x6172622036702540,0x5f335f744c240920,0x200a3b3433343831,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3933\n"
".quad 0x64656c6562616c20,0x315f335f744c2420,0x2140090a34393534,0x2061726220357025\n"
".quad 0x325f335f744c2409,0x2f200a3b38313032,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3320656e696c2079,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x34315f335f744c24,0x766f6d090a343935,0x722509203233732e,0x31337225202c3833\n"
".quad 0x34326c756d090a3b,0x203233752e6f6c2e,0x25202c3933722509,0x0a3b3631202c3172\n"
".quad 0x2e6f6c2e6c756d09,0x3472250920323375,0x2c32327225202c30,0x6461090a3b363120\n"
".quad 0x2509203233732e64,0x337225202c313472,0x3b30347225202c39,0x36752e766f6d090a\n"
".quad 0x2c34647225092034,0x5f616475635f5f20,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x365f38363436325f,0x30385f736f50785f,0x6f6d090a3b383834,0x2509203233732e76\n"
".quad 0x347225202c323472,0x2e646461090a3b31,0x3472250920323373,0x2c31347225202c33\n"
".quad 0x090a3b3133722520,0x6d617261702e646c,0x662509203436662e,0x635f5f5b202c3164\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x785f62696969695f,0x6c090a3b5d66664f,0x2e6d617261702e64,0x6466250920343666\n"
".quad 0x75635f5f5b202c32,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c644933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x63735f6269696969,0x2f200a3b5d656c61,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3320656e696c2079,0x2064616568202c39\n"
".quad 0x2064656c6562616c,0x34315f335f744c24,0x766f6d090a343935,0x722509203233732e\n"
".quad 0x38337225202c3434,0x5f335f744c240a3b,0x200a3a3437383531,0x3e706f6f6c3c2f2f\n"
".quad 0x6f6220706f6f4c20,0x20656e696c207964,0x7473656e202c3933,0x7470656420676e69\n"
".quad 0x7365202c31203a68,0x20646574616d6974,0x6f69746172657469,0x6e6b6e75203a736e\n"
".quad 0x6f6c2e090a6e776f,0x0938350937310963,0x722e747663090a30,0x33732e3436662e6e\n"
".quad 0x2c33646625092032,0x090a3b3234722520,0x09373109636f6c2e,0x646c090a30093933\n"
".quad 0x662e6d617261702e,0x3264662509203436,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331,0x6863753650764545\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x6163735f62696969\n"
".quad 0x646c090a3b5d656c,0x662e6d617261702e,0x3164662509203436,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331\n"
".quad 0x6863753650764545,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x664f785f62696969,0x6f6c2e090a3b5d66,0x0938350937310963,0x722e64616d090a30\n"
".quad 0x2509203436662e6e,0x646625202c346466,0x2c32646625202c33,0x090a3b3164662520\n"
".quad 0x6c61636f6c2e7473,0x255b09203436662e,0x202c5d302b346472,0x61090a3b34646625\n"
".quad 0x09203233732e6464,0x7225202c32347225,0x090a3b31202c3234,0x203436752e646461\n"
".quad 0x25202c3464722509,0x0a3b38202c346472,0x656e2e7074657309,0x702509203233732e\n"
".quad 0x2c32347225202c37,0x090a3b3334722520,0x6172622037702540,0x5f335f744c240920\n"
".quad 0x200a3b3437383531,0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20\n"
".quad 0x20656e696c207964,0x64616568202c3933,0x64656c6562616c20,0x315f335f744c2420\n"
".quad 0x7262090a34393534,0x240920696e752e61,0x3335315f335f744c,0x5f744c240a3b3236\n"
".quad 0x3a38313032325f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c39332065,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a34393534315f,0x6d617261702e646c,0x662509203436662e,0x635f5f5b202c3264\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x735f62696969695f,0x240a3b5d656c6163,0x3335315f335f744c,0x3c2f2f200a3a3236\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x2c393320656e696c\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x393534315f335f74,0x09636f6c2e090a34\n"
".quad 0x3009383331093631,0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c35347225\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x5d68636e7572635f,0x732e766f6d090a3b,0x3634722509203233\n"
".quad 0x0a3b35347225202c,0x617261702e646c09,0x7225092038732e6d,0x635f5f5b202c3734\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x695f62696969695f,0x6f6d090a3b5d4a73,0x2509203233732e76,0x0a3b30202c383472\n"
".quad 0x656e2e7074657309,0x702509203233732e,0x2c37347225202c38,0x090a3b3834722520\n"
".quad 0x6d617261702e646c,0x662509203436662e,0x635f5f5b202c3564,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73,0x7536507645453631\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x795f62696969695f\n"
".quad 0x63090a3b5d66664f,0x36662e6e722e7476,0x2509203233732e34,0x327225202c366466\n"
".quad 0x2e64616d090a3b36,0x09203436662e6e72,0x6625202c37646625,0x32646625202c3664\n"
".quad 0x0a3b35646625202c,0x61636f6c2e646c09,0x2509203436662e6c,0x5f5f5b202c386466\n"
".quad 0x635f5f5f61647563,0x61636f6c5f616475,0x36325f7261765f6c,0x50785f365f383634\n"
".quad 0x38383430385f736f,0x2140090a3b5d302b,0x2061726220387025,0x315f335f744c2409\n"
".quad 0x2f200a3b32343636,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3320656e696c2079,0x2064616568202c39,0x2064656c6562616c,0x34315f335f744c24\n"
".quad 0x6f6c2e090a343935,0x3434310936310963,0x702e646c090a3009,0x3436662e6d617261\n"
".quad 0x202c396466250920,0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x33316d735f30746f,0x45453631694c6449,0x7261686375365076,0x32535f5469696934\n"
".quad 0x535f32535f32535f,0x6969695f30535f32,0x3b5d504a785f6269,0x3109636f6c2e090a\n"
".quad 0x0a30093534310936,0x617261702e646c09,0x2509203436662e6d,0x5f5b202c30316466\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x090a3b5d504a795f,0x09363109636f6c2e,0x6d090a3009363431\n"
".quad 0x09203436662e766f,0x25202c3131646625,0x6c2e090a3b376466,0x343109363109636f\n"
".quad 0x766f6d090a300937,0x662509203436662e,0x646625202c323164,0x636f6c2e090a3b38\n"
".quad 0x0938343109363109,0x662e6c756d090a30,0x3164662509203436,0x2c37646625202c33\n"
".quad 0x090a3b3764662520,0x09363109636f6c2e,0x6d090a3009393431,0x09203436662e6c75\n"
".quad 0x25202c3431646625,0x646625202c386466,0x2e617262090a3b38,0x744c240920696e75\n"
".quad 0x36383336315f335f,0x5f335f744c240a3b,0x200a3a3234363631,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3933\n"
".quad 0x64656c6562616c20,0x315f335f744c2420,0x6c2e090a34393534,0x353109363109636f\n"
".quad 0x766f6d090a300933,0x662509203436662e,0x38646625202c3964,0x09636f6c2e090a3b\n"
".quad 0x3009343531093631,0x36662e766f6d090a,0x3031646625092034,0x0a3b37646625202c\n"
".quad 0x363109636f6c2e09,0x090a300938353109,0x203436662e766f6d,0x202c343164662509\n"
".quad 0x3030303030306430,0x3030303030303030,0x30202f2f093b3030,0x36662e766f6d090a\n"
".quad 0x3331646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e766f6d090a3020,0x6466250920343666,0x30306430202c3231,0x3030303030303030\n"
".quad 0x093b303030303030,0x6f6d090a30202f2f,0x2509203436662e76,0x6430202c31316466\n"
".quad 0x3030303030303030,0x3030303030303030,0x240a30202f2f093b,0x3336315f335f744c\n"
".quad 0x3c2f2f200a3a3638,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c393320656e696c,0x616c206461656820,0x4c242064656c6562,0x393534315f335f74\n"
".quad 0x752e766f6d090a34,0x3934722509203233,0x6573090a3b30202c,0x33732e71652e7074\n"
".quad 0x202c397025092032,0x7225202c31337225,0x702540090a3b3934,0x2409206172622039\n"
".quad 0x3836315f335f744c,0x3c2f2f200a3b3839,0x6150203e706f6f6c,0x6f6c20666f207472\n"
".quad 0x2079646f6220706f,0x2c393320656e696c,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x393534315f335f74,0x732e766f6d090a34,0x3035722509203233,0x744c240a3b30202c\n"
".quad 0x30313437315f335f,0x6f6c3c2f2f200a3a,0x706f6f4c203e706f,0x696c2079646f6220\n"
".quad 0x202c38353120656e,0x20676e697473656e,0x32203a6874706564,0x616d69747365202c\n"
".quad 0x7265746920646574,0x203a736e6f697461,0x0a6e776f6e6b6e75,0x363109636f6c2e09\n"
".quad 0x090a300932363109,0x203233732e627573,0x25202c3634722509,0x0a3b31202c363472\n"
".quad 0x3233752e766f6d09,0x202c313572250920,0x70746573090a3b30,0x203233732e656c2e\n"
".quad 0x25202c3031702509,0x357225202c363472,0x31702540090a3b31,0x2409206172622030\n"
".quad 0x313333315f335f4c,0x6c3c2f2f200a3b34,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c38353120656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x313437315f335f74,0x662e646461090a30,0x3164662509203436,0x3431646625202c35\n"
".quad 0x3b3331646625202c,0x36662e766f6d090a,0x3631646625092034,0x303130346430202c\n"
".quad 0x3030303030303030,0x2f2f093b30303030,0x70746573090a3420,0x203436662e74672e\n"
".quad 0x25202c3131702509,0x6625202c35316466,0x2140090a3b363164,0x6172622031317025\n"
".quad 0x315f335f4c240920,0x4c240a3b38353033,0x34313333315f335f,0x6f6c3c2f2f200a3a\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c38353120656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x30313437315f335f,0x3109636f6c2e090a\n"
".quad 0x0a30093336310936,0x3436732e74766309,0x722509203233732e,0x30357225202c3564\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x25202c3664722509,0x0a3b34202c303572\n"
".quad 0x3436752e64646109,0x202c376472250920,0x7225202c32647225,0x2e7473090a3b3664\n"
".quad 0x33732e6c61636f6c,0x376472255b092032,0x347225202c5d302b,0x636f6c2e090a3b36\n"
".quad 0x0935363109363109,0x732e646461090a30,0x3035722509203233,0x202c30357225202c\n"
".quad 0x70746573090a3b31,0x203233732e71652e,0x25202c3231702509,0x357225202c313372\n"
".quad 0x31702540090a3b30,0x2409206172622032,0x3836315f335f744c,0x3c2f2f200a3b3839\n"
".quad 0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f,0x38353120656e696c\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3437315f335f744c,0x2e747663090a3031\n"
".quad 0x203233732e343673,0x25202c3864722509,0x756d090a3b303572,0x732e656469772e6c\n"
".quad 0x3964722509203233,0x202c30357225202c,0x2e646461090a3b38,0x6472250920343675\n"
".quad 0x33647225202c3031,0x0a3b39647225202c,0x61636f6c2e646c09,0x2509203436662e6c\n"
".quad 0x255b202c37316466,0x3b5d302b30316472,0x203870252140090a,0x744c240920617262\n"
".quad 0x32323937315f335f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c38353120656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x30313437315f335f,0x3109636f6c2e090a,0x0a30093736310936,0x617261702e646c09\n"
".quad 0x2509203436662e6d,0x5f5f5b202c396466,0x6d72617061647563,0x6e614d36315a5f5f\n"
".quad 0x30746f72626c6564,0x4c644933316d735f,0x3650764545363169,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x2e090a3b5d504a78\n"
".quad 0x3109363109636f6c,0x646c090a30093836,0x662e6d617261702e,0x3164662509203436\n"
".quad 0x75635f5f5b202c30,0x5f5f6d7261706164,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c644933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x4a795f6269696969,0x6f6c2e090a3b5d50,0x3936310936310963\n"
".quad 0x2e766f6d090a3009,0x6466250920343666,0x37646625202c3131,0x09636f6c2e090a3b\n"
".quad 0x3009303731093631,0x36662e766f6d090a,0x3231646625092034,0x3b3731646625202c\n"
".quad 0x3109636f6c2e090a,0x0a30093137310936,0x3436662e6c756d09,0x2c33316466250920\n"
".quad 0x25202c3764662520,0x6c2e090a3b376466,0x373109363109636f,0x6c756d090a300932\n"
".quad 0x662509203436662e,0x646625202c343164,0x31646625202c3731,0x2e617262090a3b37\n"
".quad 0x744c240920696e75,0x36363637315f335f,0x5f335f744c240a3b,0x200a3a3232393731\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c383531,0x656c6562616c2064,0x5f335f744c242064,0x2e090a3031343731\n"
".quad 0x3109363109636f6c,0x6f6d090a30093537,0x2509203436662e76,0x646625202c396466\n"
".quad 0x6f6c2e090a3b3731,0x3637310936310963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x37646625202c3031,0x09636f6c2e090a3b,0x3009303831093631,0x36662e766f6d090a\n"
".quad 0x3431646625092034,0x303030306430202c,0x3030303030303030,0x2f2f093b30303030\n"
".quad 0x2e766f6d090a3020,0x6466250920343666,0x30306430202c3331,0x3030303030303030\n"
".quad 0x093b303030303030,0x6f6d090a30202f2f,0x2509203436662e76,0x6430202c32316466\n"
".quad 0x3030303030303030,0x3030303030303030,0x090a30202f2f093b,0x203436662e766f6d\n"
".quad 0x202c313164662509,0x3030303030306430,0x3030303030303030,0x30202f2f093b3030\n"
".quad 0x315f335f744c240a,0x2f200a3a36363637,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3835,0x64656c6562616c20\n"
".quad 0x315f335f744c2420,0x6c2e090a30313437,0x333109363109636f,0x2e646c090a300938\n"
".quad 0x33732e6d61726170,0x2c35347225092032,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x6e7572635f626969\n"
".quad 0x6c2e090a3b5d6863,0x383109363109636f,0x766f6d090a300933,0x722509203233732e\n"
".quad 0x35347225202c3634,0x315f335f4c240a3b,0x2f200a3a38353033,0x203e706f6f6c3c2f\n"
".quad 0x20666f2074726150,0x646f6220706f6f6c,0x3120656e696c2079,0x64616568202c3835\n"
".quad 0x64656c6562616c20,0x315f335f744c2420,0x6c2e090a30313437,0x383109363109636f\n"
".quad 0x6c756d090a300935,0x662509203436662e,0x646625202c383164,0x31646625202c3231\n"
".quad 0x2e646461090a3b31,0x6466250920343666,0x31646625202c3931,0x3831646625202c38\n"
".quad 0x662e646461090a3b,0x3164662509203436,0x3031646625202c31,0x3b3931646625202c\n"
".quad 0x3109636f6c2e090a,0x0a30093638310936,0x3436662e62757309,0x2c30326466250920\n"
".quad 0x202c343164662520,0x090a3b3331646625,0x203436662e646461,0x202c323164662509\n"
".quad 0x6625202c39646625,0x6c2e090a3b303264,0x383109363109636f,0x6c756d090a300937\n"
".quad 0x662509203436662e,0x646625202c333164,0x31646625202c3131,0x636f6c2e090a3b31\n"
".quad 0x0938383109363109,0x662e6c756d090a30,0x3164662509203436,0x3231646625202c34\n"
".quad 0x3b3231646625202c,0x6e2e70746573090a,0x2509203233732e65,0x337225202c333170\n"
".quad 0x3b30357225202c31,0x203331702540090a,0x744c240920617262,0x30313437315f335f\n"
".quad 0x5f335f744c240a3b,0x240a3a3839383631,0x5f69646e6557444c,0x636c614334315a5f\n"
".quad 0x72626c65646e614d,0x695076456449746f,0x535f31535f544b50,0x6962695f31535f31\n"
".quad 0x0a3a315f3331325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x616568202c393320,0x656c6562616c2064,0x5f335f744c242064\n"
".quad 0x2e090a3439353431,0x3609373109636f6c,0x252140090a300932,0x0920617262203570\n"
".quad 0x38315f335f744c24,0x2f2f200a3b343334,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x393320656e696c20,0x6c2064616568202c,0x242064656c656261\n"
".quad 0x3534315f335f744c,0x2e766f6d090a3439,0x3572250920323373,0x3b31337225202c32\n"
".quad 0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c33357225,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x3b5d656d6172665f,0x33732e766f6d090a,0x2c34357225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x202c343170250920,0x7225202c33357225,0x766f6d090a3b3435\n"
".quad 0x722509203436752e,0x635f5f202c313164,0x75635f5f5f616475,0x6c61636f6c5f6164\n"
".quad 0x3436325f7261765f,0x5f6d5f31315f3936,0x090a3b3432343631,0x732e6f6c2e6c756d\n"
".quad 0x3535722509203233,0x202c38317225202c,0x61090a3b36327225,0x09203233732e6464\n"
".quad 0x7225202c36357225,0x35357225202c3732,0x732e766f6d090a3b,0x3735722509203233\n"
".quad 0x0a3b36357225202c,0x3233732e64646109,0x202c383572250920,0x7225202c36357225\n"
".quad 0x2e646c090a3b3133,0x36752e6d61726170,0x3231647225092034,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f30746f7262,0x3631694c64493331\n"
".quad 0x6863753650764545,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x7473645f62696969,0x2e747663090a3b5d,0x203233732e343673,0x202c333164722509\n"
".quad 0x6d090a3b36357225,0x2e656469772e6c75,0x6472250920323373,0x36357225202c3431\n"
".quad 0x6461090a3b34202c,0x2509203436752e64,0x7225202c35316472,0x647225202c323164\n"
".quad 0x3c2f2f200a3b3431,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x2c393320656e696c,0x616c206461656820,0x4c242064656c6562,0x393534315f335f74\n"
".quad 0x732e766f6d090a34,0x3935722509203233,0x0a3b32357225202c,0x38315f335f744c24\n"
".quad 0x2f2f200a3a363439,0x4c203e706f6f6c3c,0x79646f6220706f6f,0x323620656e696c20\n"
".quad 0x6e697473656e202c,0x3a68747065642067,0x69747365202c3120,0x746920646574616d\n"
".quad 0x736e6f6974617265,0x776f6e6b6e75203a,0x6f6c2e646c090a6e,0x203233732e6c6163\n"
".quad 0x5b202c3036722509,0x5d302b3131647225,0x752e766f6d090a3b,0x3136722509203233\n"
".quad 0x6573090a3b30202c,0x33732e656c2e7074,0x2c35317025092032,0x25202c3036722520\n"
".quad 0x2540090a3b313672,0x2061726220353170,0x315f335f744c2409,0x2f200a3b38353439\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3620656e696c2079\n"
".quad 0x2064616568202c32,0x2064656c6562616c,0x38315f335f744c24,0x6f6c2e090a363439\n"
".quad 0x3833310936310963,0x702e646c090a3009,0x3233732e6d617261,0x202c353472250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f30746f\n"
".quad 0x45453631694c6449,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x636e7572635f6269,0x6f6c2e090a3b5d68,0x0935360937310963\n"
".quad 0x732e627573090a30,0x3236722509203233,0x202c35347225202c,0x62090a3b30367225\n"
".quad 0x0920696e752e6172,0x39315f335f744c24,0x744c240a3b323032,0x38353439315f335f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x68202c323620656e,0x6562616c20646165,0x5f744c242064656c,0x0a36343938315f33\n"
".quad 0x3233732e766f6d09,0x202c323672250920,0x335f744c240a3b30,0x0a3a32303239315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x616568202c323620,0x656c6562616c2064,0x5f335f744c242064,0x73090a3634393831\n"
".quad 0x2e6c61636f6c2e74,0x72255b0920323373,0x202c5d302b313164,0x6d090a3b32367225\n"
".quad 0x09203233752e766f,0x3b30202c33367225,0x652e70746573090a,0x2509203233732e71\n"
".quad 0x367225202c363170,0x3b33367225202c32,0x203631702540090a,0x744c240920617262\n"
".quad 0x30373939315f335f,0x6f6c3c2f2f200a3b,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x68202c323620656e,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a36343938315f33,0x373109636f6c2e09,0x6c090a3009303709,0x2e6d617261702e64\n"
".quad 0x3672250920323373,0x75635f5f5b202c34,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x31694c644933316d,0x6375365076454536,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6e615f6269696969,0x466e6f6974616d69\n"
".quad 0x090a3b5d656d6172,0x203233732e646461,0x25202c3536722509,0x367225202c343672\n"
".quad 0x6c2e7473090a3b32,0x3233732e6c61636f,0x31316472255b0920,0x367225202c5d302b\n"
".quad 0x636f6c2e090a3b35,0x3009313709373109,0x7261702e646c090a,0x25092038752e6d61\n"
".quad 0x5f5f5b202c363672,0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564\n"
".quad 0x4c644933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x302b73726f6c6f63,0x2e6c756d090a3b5d\n"
".quad 0x09203233732e6f6c,0x7225202c37367225,0x36367225202c3536,0x752e747663090a3b\n"
".quad 0x2509203233752e38,0x367225202c383672,0x636f6c2e090a3b37,0x3009323709373109\n"
".quad 0x7261702e646c090a,0x25092038752e6d61,0x5f5f5b202c393672,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x30746f72626c6564,0x4c644933316d735f,0x3650764545363169\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x312b73726f6c6f63,0x2e6c756d090a3b5d,0x09203233732e6f6c,0x7225202c30377225\n"
".quad 0x39367225202c3536,0x752e747663090a3b,0x2509203233752e38,0x377225202c313772\n"
".quad 0x636f6c2e090a3b30,0x3009333709373109,0x7261702e646c090a,0x25092038752e6d61\n"
".quad 0x5f5f5b202c323772,0x6d72617061647563,0x6e614d36315a5f5f,0x30746f72626c6564\n"
".quad 0x4c644933316d735f,0x3650764545363169,0x6969347261686375,0x32535f32535f5469\n"
".quad 0x535f32535f32535f,0x5f62696969695f30,0x322b73726f6c6f63,0x2e6c756d090a3b5d\n"
".quad 0x09203233732e6f6c,0x7225202c33377225,0x32377225202c3536,0x752e747663090a3b\n"
".quad 0x2509203233752e38,0x377225202c343772,0x2e617262090a3b33,0x744c240920696e75\n"
".quad 0x34313739315f335f,0x5f335f744c240a3b,0x200a3a3037393931,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x64616568202c3236\n"
".quad 0x64656c6562616c20,0x315f335f744c2420,0x6c2e090a36343938,0x373709373109636f\n"
".quad 0x2e766f6d090a3009,0x3772250920323375,0x6d090a3b30202c34,0x09203233752e766f\n"
".quad 0x3b30202c31377225,0x33752e766f6d090a,0x2c38367225092032,0x5f744c240a3b3020\n"
".quad 0x3a34313739315f33,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x6568202c32362065,0x6c6562616c206461,0x335f744c24206465\n"
".quad 0x090a36343938315f,0x6220343170252140,0x5f744c2409206172,0x3b32383430325f33\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x6568202c32362065,0x6c6562616c206461,0x335f744c24206465,0x090a36343938315f\n"
".quad 0x09373109636f6c2e,0x6f6d090a30093438,0x2509203233752e76,0x0a3b30202c353772\n"
".quad 0x626f6c672e747309,0x38752e34762e6c61,0x35316472255b0920,0x72257b202c5d302b\n"
".quad 0x2c313772252c3836,0x3772252c34377225,0x617262090a3b7d35,0x4c240920696e752e\n"
".quad 0x323230325f335f74,0x335f744c240a3b36,0x0a3a32383430325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x616568202c323620\n"
".quad 0x656c6562616c2064,0x5f335f744c242064,0x2e090a3634393831,0x3609373109636f6c\n"
".quad 0x2e646c090a300932,0x33732e6d61726170,0x2c33357225092032,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f30746f72,0x453631694c644933\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x6d6172665f626969,0x6f6c2e090a3b5d65,0x0938380937310963,0x732e646461090a30\n"
".quad 0x3637722509203233,0x202c33357225202c,0x2e726873090a3b31,0x3772250920323373\n"
".quad 0x2c36377225202c37,0x6f6d090a3b313320,0x2509203233732e76,0x0a3b31202c383772\n"
".quad 0x3233622e646e6109,0x202c393772250920,0x7225202c37377225,0x646461090a3b3837\n"
".quad 0x722509203233732e,0x39377225202c3038,0x0a3b36377225202c,0x3233732e72687309\n"
".quad 0x202c313872250920,0x3b31202c30387225,0x6f6c672e646c090a,0x752e34762e6c6162\n"
".quad 0x323872257b092038,0x72252c333872252c,0x5b202c7d5f2c3438,0x5d302b3531647225\n"
".quad 0x6c2e6c756d090a3b,0x2509203233732e6f,0x357225202c353872,0x3b32387225202c33\n"
".quad 0x33732e646461090a,0x2c36387225092032,0x25202c3836722520,0x6461090a3b353872\n"
".quad 0x2509203233732e64,0x387225202c373872,0x3b36387225202c31,0x33732e766964090a\n"
".quad 0x2c38387225092032,0x25202c3738722520,0x6c2e090a3b363772,0x393809373109636f\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c39387225,0x33387225202c3335\n"
".quad 0x732e646461090a3b,0x3039722509203233,0x202c31377225202c,0x61090a3b39387225\n"
".quad 0x09203233732e6464,0x7225202c31397225,0x30397225202c3138,0x732e766964090a3b\n"
".quad 0x3239722509203233,0x202c31397225202c,0x73090a3b36377225,0x6c61626f6c672e74\n"
".quad 0x092038752e32762e,0x302b35316472255b,0x383872257b202c5d,0x0a3b7d323972252c\n"
".quad 0x373109636f6c2e09,0x6d090a3009303909,0x33732e6f6c2e6c75,0x2c33397225092032\n"
".quad 0x25202c3335722520,0x6461090a3b343872,0x2509203233732e64,0x377225202c343972\n"
".quad 0x3b33397225202c34,0x33732e646461090a,0x2c35397225092032,0x25202c3138722520\n"
".quad 0x6964090a3b343972,0x2509203233732e76,0x397225202c363972,0x3b36377225202c35\n"
".quad 0x6f6c672e7473090a,0x092038752e6c6162,0x322b35316472255b,0x3b36397225202c5d\n"
".quad 0x325f335f744c240a,0x2f200a3a36323230,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3620656e696c2079,0x2064616568202c32,0x2064656c6562616c\n"
".quad 0x38315f335f744c24,0x646461090a363439,0x722509203233732e,0x37357225202c3735\n"
".quad 0x6461090a3b31202c,0x2509203436752e64,0x7225202c35316472,0x0a3b34202c353164\n"
".quad 0x3436752e64646109,0x2c31316472250920,0x202c313164722520,0x70746573090a3b34\n"
".quad 0x203233732e656e2e,0x25202c3731702509,0x357225202c373572,0x31702540090a3b38\n"
".quad 0x2409206172622037,0x3938315f335f744c,0x5f744c240a3b3634,0x3a34333438315f33\n"
".quad 0x315f335f744c240a,0x2f200a3a30353834,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3320656e696c2079,0x2064616568202c39,0x2064656c6562616c\n"
".quad 0x34315f335f744c24,0x6f6c2e090a343935,0x0935390937310963,0x732e726162090a30\n"
".quad 0x0a3b300920636e79,0x3233752e766f6d09,0x202c373972250920,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3831702509,0x37397225202c3772,0x3831702540090a3b\n"
".quad 0x4c24092061726220,0x393930325f335f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x202c393320656e69,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x34393534315f335f,0x3109636f6c2e090a,0x090a300938390937\n"
".quad 0x203436752e766f6d,0x202c363164722509,0x756f436b636f6c62,0x6d090a3b7265746e\n"
".quad 0x09203233752e766f,0x3b31202c38397225,0x672e6d6f7461090a,0x64612e6c61626f6c\n"
".quad 0x2509203233752e64,0x72255b202c393972,0x7225202c5d363164,0x766f6d090a3b3839\n"
".quad 0x722509203233732e,0x397225202c303031,0x732e7473090a3b39,0x33752e6465726168\n"
".quad 0x75635f5f5b092032,0x6c61636f6c5f6164,0x3436325f7261765f,0x6c625f32345f3434\n"
".quad 0x7865646e496b636f,0x3030317225202c5d,0x09636f6c2e090a3b,0x0a30093939093731\n"
".quad 0x617261702e646c09,0x2509203233752e6d,0x5f5b202c31303172,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x646957646972675f,0x6572090a3b5d6874,0x2509203233752e6d,0x7225202c32303172\n"
".quad 0x317225202c303031,0x2e7473090a3b3130,0x752e646572616873,0x635f5f5b09203233\n"
".quad 0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f353434,0x202c5d586b636f6c\n"
".quad 0x090a3b3230317225,0x09373109636f6c2e,0x64090a3009303031,0x09203233752e7669\n"
".quad 0x25202c3330317225,0x7225202c30303172,0x7473090a3b313031,0x2e6465726168732e\n"
".quad 0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61,0x5f30355f35343436\n"
".quad 0x2c5d596b636f6c62,0x0a3b333031722520,0x30325f335f744c24,0x2f2f200a3a343939\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x393320656e696c20\n"
".quad 0x6c2064616568202c,0x242064656c656261,0x3534315f335f744c,0x636f6c2e090a3439\n"
".quad 0x0932303109373109,0x732e726162090a30,0x0a3b300920636e79,0x726168732e646c09\n"
".quad 0x09203233752e6465,0x5b202c3430317225,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f34343436325f,0x496b636f6c625f32,0x090a3b5d7865646e,0x2e746c2e70746573\n"
".quad 0x3170250920323375,0x3430317225202c39,0x0a3b35317225202c,0x6220393170254009\n"
".quad 0x5f744c2409206172,0x3b34393534315f33,0x315f335f744c240a,0x2e090a3a32383034\n"
".quad 0x3109373109636f6c,0x7865090a30093730,0x57444c240a3b7469,0x36315a5f5f646e65\n"
".quad 0x72626c65646e614d,0x33316d735f30746f,0x45453631694c6449,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x2f207d090a3a6269\n"
".quad 0x614d36315a5f202f,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x72746e652e090a0a,0x614d36315a5f2079,0x746f72626c65646e,0x664933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x09090a2820626969,0x2e206d617261702e,0x75635f5f20343675,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x09090a2c7473645f\n"
".quad 0x2e206d617261702e,0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f31746f72626c,0x507645664933316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x62696969695f3053,0x2c576567616d695f,0x617261702e09090a\n"
".quad 0x5f203233732e206d,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x664933316d735f31,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x67616d695f626969,0x702e09090a2c4865,0x33732e206d617261\n"
".quad 0x616475635f5f2032,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x635f62696969695f,0x090a2c68636e7572,0x206d617261702e09,0x635f5f203233662e\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645664933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x0a2c66664f785f62,0x6d617261702e0909,0x5f5f203233662e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x31746f72626c6564,0x45664933316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x2c66664f795f6269\n"
".quad 0x617261702e09090a,0x5f203233662e206d,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x2c504a785f626969,0x617261702e09090a\n"
".quad 0x5f203233662e206d,0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e\n"
".quad 0x664933316d735f31,0x6168637536507645,0x535f546969693472,0x5f32535f32535f32\n"
".quad 0x69695f30535f3253,0x2c504a795f626969,0x617261702e09090a,0x5f203233662e206d\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x6c6163735f626969,0x61702e09090a2c65,0x696c612e206d6172,0x38622e2034206e67\n"
".quad 0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f\n"
".quad 0x6375365076456649,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x6f635f6269696969,0x2c5d345b73726f6c,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x6d6172665f626969,0x61702e09090a2c65,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6e615f6269696969\n"
".quad 0x466e6f6974616d69,0x09090a2c656d6172,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x646957646972675f,0x702e09090a2c6874,0x33732e206d617261,0x616475635f5f2032\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x6e5f62696969695f\n"
".quad 0x736b636f6c426d75,0x7261702e09090a2c,0x5f2038732e206d61,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x294a73695f626969\n"
".quad 0x65722e090a7b090a,0x25203233752e2067,0x722e090a3b317672,0x203233752e206765\n"
".quad 0x3b3e3537313c7225,0x2e206765722e090a,0x3c64722520343675,0x722e090a3b3e3431\n"
".quad 0x203233662e206765,0x0a3b3e34323c6625,0x702e206765722e09,0x323c702520646572\n"
".quad 0x68732e090a3b3e31,0x33752e2064657261,0x616475635f5f2032,0x765f6c61636f6c5f\n"
".quad 0x35303636325f7261,0x636f6c625f32345f,0x0a3b7865646e496b,0x6465726168732e09\n"
".quad 0x5f5f203233752e20,0x636f6c5f61647563,0x325f7261765f6c61,0x5f32345f36303636\n"
".quad 0x0a3b586b636f6c62,0x6465726168732e09,0x5f5f203233752e20,0x636f6c5f61647563\n"
".quad 0x325f7261765f6c61,0x5f30355f36303636,0x0a3b596b636f6c62,0x373109636f6c2e09\n"
".quad 0x240a300939383109,0x6e6967656257444c,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45664933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x747663090a3a6269,0x3631752e3233752e,0x25202c3172250920\n"
".quad 0x090a3b782e646974,0x203233752e766f6d,0x3b30202c32722509,0x652e70746573090a\n"
".quad 0x2509203233752e71,0x2c317225202c3170,0x63090a3b32722520,0x752e3233752e7476\n"
".quad 0x2c33722509203631,0x3b792e6469742520,0x33752e766f6d090a,0x202c347225092032\n"
".quad 0x70746573090a3b30,0x203233752e71652e,0x7225202c32702509,0x0a3b347225202c33\n"
".quad 0x33732e706c657309,0x202c357225092032,0x7025202c30202c31,0x706c6573090a3b31\n"
".quad 0x722509203233732e,0x2c30202c31202c36,0x61090a3b32702520,0x09203233622e646e\n"
".quad 0x357225202c377225,0x090a3b367225202c,0x203233752e766f6d,0x3b30202c38722509\n"
".quad 0x652e70746573090a,0x2509203233732e71,0x2c377225202c3370,0x40090a3b38722520\n"
".quad 0x2061726220337025,0x315f345f744c2409,0x2e090a3b34353137,0x3109373109636f6c\n"
".quad 0x6f6d090a30093639,0x2509203436752e76,0x6f6c62202c316472,0x65746e756f436b63\n"
".quad 0x2e766f6d090a3b72,0x3972250920323375,0x7461090a3b31202c,0x61626f6c672e6d6f\n"
".quad 0x33752e6464612e6c,0x2c30317225092032,0x2c5d316472255b20,0x6d090a3b39722520\n"
".quad 0x09203233732e766f,0x7225202c31317225,0x2e7473090a3b3031,0x752e646572616873\n"
".quad 0x635f5f5b09203233,0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f353036\n"
".quad 0x65646e496b636f6c,0x31317225202c5d78,0x09636f6c2e090a3b,0x3009373931093731\n"
".quad 0x7261702e646c090a,0x09203233752e6d61,0x5f5b202c32317225,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x646972675f626969\n"
".quad 0x0a3b5d6874646957,0x3233752e6d657209,0x202c333172250920,0x7225202c31317225\n"
".quad 0x2e7473090a3b3231,0x752e646572616873,0x635f5f5b09203233,0x61636f6c5f616475\n"
".quad 0x36325f7261765f6c,0x625f32345f363036,0x202c5d586b636f6c,0x2e090a3b33317225\n"
".quad 0x3109373109636f6c,0x6964090a30093839,0x2509203233752e76,0x317225202c343172\n"
".quad 0x3b32317225202c31,0x6168732e7473090a,0x203233752e646572,0x616475635f5f5b09\n"
".quad 0x765f6c61636f6c5f,0x36303636325f7261,0x636f6c625f30355f,0x317225202c5d596b\n"
".quad 0x345f744c240a3b34,0x0a3a34353137315f,0x373109636f6c2e09,0x090a300931303209\n"
".quad 0x636e79732e726162,0x646c090a3b300920,0x752e6d617261702e,0x3531722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764566493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x6b636f6c426d756e,0x2e646c090a3b5d73,0x752e646572616873\n"
".quad 0x3631722509203233,0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x303636325f726176\n"
".quad 0x6f6c625f32345f35,0x5d7865646e496b63,0x2e70746573090a3b,0x09203233752e6567\n"
".quad 0x317225202c347025,0x3b35317225202c36,0x622034702540090a,0x5f744c2409206172\n"
".quad 0x3b36363637315f34,0x7261702e646c090a,0x09203233732e6d61,0x5f5b202c37317225\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x67616d695f626969,0x646c090a3b5d4865,0x732e6d617261702e,0x3831722509203233\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764566493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x3b5d576567616d69,0x33752e747663090a,0x2509203631752e32\n"
".quad 0x746e25202c393172,0x63090a3b792e6469,0x752e3233752e7476,0x3032722509203631\n"
".quad 0x2e6469746e25202c,0x345f744c240a3b78,0x0a3a38373138315f,0x706f6f6c3c2f2f20\n"
".quad 0x6220706f6f4c203e,0x656e696c2079646f,0x646c090a31303220,0x2e6465726168732e\n"
".quad 0x3272250920323375,0x75635f5f5b202c31,0x6c61636f6c5f6164,0x3636325f7261765f\n"
".quad 0x6c625f32345f3630,0x090a3b5d586b636f,0x752e6f6c2e6c756d,0x3232722509203233\n"
".quad 0x202c31327225202c,0x6c090a3b30327225,0x6465726168732e64,0x722509203233752e\n"
".quad 0x635f5f5b202c3332,0x61636f6c5f616475,0x36325f7261765f6c,0x625f30355f363036\n"
".quad 0x0a3b5d596b636f6c,0x2e6f6c2e6c756d09,0x3272250920323375,0x2c33327225202c34\n"
".quad 0x090a3b3931722520,0x203233752e646461,0x25202c3532722509,0x317225202c323272\n"
".quad 0x752e646461090a3b,0x3632722509203233,0x202c34327225202c,0x6573090a3b337225\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x37317225202c3732,0x0a3b36327225202c\n"
".quad 0x3233732e67656e09,0x202c383272250920,0x73090a3b37327225,0x33752e74672e7465\n"
".quad 0x2509203233732e32,0x317225202c393272,0x3b35327225202c38,0x33732e67656e090a\n"
".quad 0x2c30337225092032,0x090a3b3932722520,0x203233622e646e61,0x25202c3133722509\n"
".quad 0x337225202c383272,0x2e766f6d090a3b30,0x3372250920323375,0x73090a3b30202c32\n"
".quad 0x732e71652e707465,0x2c35702509203233,0x25202c3133722520,0x2540090a3b323372\n"
".quad 0x0920617262203570,0x30325f345f744c24,0x2f2f200a3b343939,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x38315f345f744c24,0x6f6c2e090a383731,0x3331320937310963\n"
".quad 0x2e6c756d090a3009,0x09203233732e6f6c,0x7225202c33337225,0x36327225202c3831\n"
".quad 0x732e646461090a3b,0x3433722509203233,0x202c35327225202c,0x6c090a3b33337225\n"
".quad 0x2e6d617261702e64,0x6472250920343675,0x75635f5f5b202c32,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x090a3b5d7473645f\n"
".quad 0x2e3436732e747663,0x6472250920323373,0x3b34337225202c33,0x69772e6c756d090a\n"
".quad 0x09203233732e6564,0x7225202c34647225,0x090a3b34202c3433,0x203436752e646461\n"
".quad 0x25202c3564722509,0x647225202c326472,0x672e646c090a3b34,0x34762e6c61626f6c\n"
".quad 0x72257b092038752e,0x2c363372252c3533,0x2c7d5f2c37337225,0x302b356472255b20\n"
".quad 0x2e766f6d090a3b5d,0x3372250920323375,0x73090a3b30202c38,0x732e656c2e707465\n"
".quad 0x2c36702509203233,0x25202c3532722520,0x2540090a3b383372,0x0920617262203670\n"
".quad 0x39315f345f744c24,0x2f2f200a3b323032,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31,0x2064656c6562616c\n"
".quad 0x38315f345f744c24,0x2e646c090a383731,0x762e6c61626f6c67,0x257b092038752e34\n"
".quad 0x303472252c393372,0x7d5f2c313472252c,0x2b356472255b202c,0x6c2e090a3b5d342d\n"
".quad 0x313209373109636f,0x627573090a300938,0x722509203233732e,0x31347225202c3234\n"
".quad 0x0a3b37337225202c,0x3233732e73626109,0x202c333472250920,0x6d090a3b32347225\n"
".quad 0x09203233732e766f,0x3031202c34347225,0x672e746573090a3b,0x33732e3233752e74\n"
".quad 0x2c35347225092032,0x25202c3334722520,0x656e090a3b343472,0x2509203233732e67\n"
".quad 0x347225202c363472,0x2e627573090a3b35,0x3472250920323373,0x2c39337225202c37\n"
".quad 0x090a3b3533722520,0x203233732e736261,0x25202c3834722509,0x6f6d090a3b373472\n"
".quad 0x2509203233732e76,0x3b3031202c393472,0x74672e746573090a,0x3233732e3233752e\n"
".quad 0x202c303572250920,0x7225202c38347225,0x67656e090a3b3934,0x722509203233732e\n"
".quad 0x30357225202c3135,0x732e627573090a3b,0x3235722509203233,0x202c30347225202c\n"
".quad 0x61090a3b36337225,0x09203233732e7362,0x7225202c33357225,0x766f6d090a3b3235\n"
".quad 0x722509203233732e,0x0a3b3031202c3435,0x2e74672e74657309,0x203233732e323375\n"
".quad 0x25202c3535722509,0x357225202c333572,0x2e67656e090a3b34,0x3572250920323373\n"
".quad 0x3b35357225202c36,0x3233622e726f090a,0x202c373572250920,0x7225202c31357225\n"
".quad 0x2e726f090a3b3635,0x3572250920323362,0x2c36347225202c38,0x090a3b3735722520\n"
".quad 0x20696e752e617262,0x315f345f744c2409,0x4c240a3b36343938,0x303239315f345f74\n"
".quad 0x6c3c2f2f200a3a32,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562,0x373138315f345f74\n"
".quad 0x732e766f6d090a38,0x3835722509203233,0x744c240a3b30202c,0x36343938315f345f\n"
".quad 0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220\n"
".quad 0x202c31303220656e,0x62616c2064616568,0x744c242064656c65,0x38373138315f345f\n"
".quad 0x33732e646461090a,0x2c39357225092032,0x31202c3532722520,0x2e70746573090a3b\n"
".quad 0x09203233732e656c,0x317225202c377025,0x3b39357225202c38,0x622037702540090a\n"
".quad 0x5f744c2409206172,0x3b38353439315f34,0x6f6f6c3c2f2f200a,0x2074726150203e70\n"
".quad 0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3130322065,0x6562616c20646165\n"
".quad 0x5f744c242064656c,0x0a38373138315f34,0x626f6c672e646c09,0x38752e34762e6c61\n"
".quad 0x2c303672257b0920,0x3672252c31367225,0x255b202c7d5f2c32,0x0a3b5d342b356472\n"
".quad 0x373109636f6c2e09,0x090a300930323209,0x203233732e627573,0x25202c3336722509\n"
".quad 0x337225202c323672,0x2e736261090a3b37,0x3672250920323373,0x3b33367225202c34\n"
".quad 0x33732e766f6d090a,0x2c35367225092032,0x6573090a3b303120,0x3233752e74672e74\n"
".quad 0x722509203233732e,0x34367225202c3636,0x0a3b35367225202c,0x3233732e67656e09\n"
".quad 0x202c373672250920,0x73090a3b36367225,0x09203233732e6275,0x7225202c38367225\n"
".quad 0x35337225202c3036,0x732e736261090a3b,0x3936722509203233,0x0a3b38367225202c\n"
".quad 0x3233732e766f6d09,0x202c303772250920,0x746573090a3b3031,0x2e3233752e74672e\n"
".quad 0x3772250920323373,0x2c39367225202c31,0x090a3b3037722520,0x203233732e67656e\n"
".quad 0x25202c3237722509,0x7573090a3b313772,0x2509203233732e62,0x367225202c333772\n"
".quad 0x3b36337225202c31,0x33732e736261090a,0x2c34377225092032,0x090a3b3337722520\n"
".quad 0x203233732e766f6d,0x31202c3537722509,0x2e746573090a3b30,0x732e3233752e7467\n"
".quad 0x3637722509203233,0x202c34377225202c,0x6e090a3b35377225,0x09203233732e6765\n"
".quad 0x7225202c37377225,0x2e726f090a3b3637,0x3772250920323362,0x2c32377225202c38\n"
".quad 0x090a3b3737722520,0x09203233622e726f,0x7225202c39377225,0x38377225202c3736\n"
".quad 0x732e646461090a3b,0x3835722509203233,0x202c38357225202c,0x4c240a3b39377225\n"
".quad 0x353439315f345f74,0x6c3c2f2f200a3a38,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x373138315f345f74,0x752e766f6d090a38,0x3038722509203233,0x6573090a3b30202c\n"
".quad 0x33732e656c2e7074,0x202c387025092032,0x7225202c36327225,0x702540090a3b3038\n"
".quad 0x2409206172622038,0x3939315f345f744c,0x3c2f2f200a3b3037,0x6150203e706f6f6c\n"
".quad 0x6f6c20666f207472,0x2079646f6220706f,0x31303220656e696c,0x6c2064616568202c\n"
".quad 0x242064656c656261,0x3138315f345f744c,0x636f6c2e090a3837,0x0932323209373109\n"
".quad 0x732e627573090a30,0x3138722509203233,0x202c34337225202c,0x63090a3b38317225\n"
".quad 0x732e3436732e7476,0x3664722509203233,0x0a3b31387225202c,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x387225202c376472,0x2e090a3b34202c31,0x3209373109636f6c\n"
".quad 0x646c090a30093331,0x752e6d617261702e,0x3264722509203436,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x2e090a3b5d747364,0x3209373109636f6c,0x6461090a30093232,0x2509203436752e64\n"
".quad 0x647225202c386472,0x3b37647225202c32,0x6f6c672e646c090a,0x752e34762e6c6162\n"
".quad 0x323872257b092038,0x72252c333872252c,0x5b202c7d5f2c3438,0x3b5d302b38647225\n"
".quad 0x33732e627573090a,0x2c35387225092032,0x25202c3438722520,0x6261090a3b373372\n"
".quad 0x2509203233732e73,0x387225202c363872,0x2e766f6d090a3b35,0x3872250920323373\n"
".quad 0x090a3b3031202c37,0x752e74672e746573,0x09203233732e3233,0x7225202c38387225\n"
".quad 0x37387225202c3638,0x732e67656e090a3b,0x3938722509203233,0x0a3b38387225202c\n"
".quad 0x3233732e62757309,0x202c303972250920,0x7225202c32387225,0x736261090a3b3533\n"
".quad 0x722509203233732e,0x30397225202c3139,0x732e766f6d090a3b,0x3239722509203233\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x397225202c333972\n"
".quad 0x3b32397225202c31,0x33732e67656e090a,0x2c34397225092032,0x090a3b3339722520\n"
".quad 0x203233732e627573,0x25202c3539722509,0x337225202c333872,0x2e736261090a3b36\n"
".quad 0x3972250920323373,0x3b35397225202c36,0x33732e766f6d090a,0x2c37397225092032\n"
".quad 0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e,0x36397225202c3839\n"
".quad 0x0a3b37397225202c,0x3233732e67656e09,0x202c393972250920,0x6f090a3b38397225\n"
".quad 0x2509203233622e72,0x7225202c30303172,0x39397225202c3439,0x33622e726f090a3b\n"
".quad 0x3130317225092032,0x202c39387225202c,0x090a3b3030317225,0x203233732e646461\n"
".quad 0x25202c3835722509,0x317225202c383572,0x5f744c240a3b3130,0x3a30373939315f34\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f34\n"
".quad 0x3233732e64646109,0x2c32303172250920,0x31202c3632722520,0x2e70746573090a3b\n"
".quad 0x09203233732e656c,0x317225202c397025,0x3230317225202c37,0x2039702540090a3b\n"
".quad 0x744c240920617262,0x32383430325f345f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373138315f345f,0x3109636f6c2e090a,0x0a30093432320937\n"
".quad 0x3233732e64646109,0x2c33303172250920,0x25202c3433722520,0x7663090a3b383172\n"
".quad 0x33732e3436732e74,0x2c39647225092032,0x0a3b333031722520,0x6469772e6c756d09\n"
".quad 0x2509203233732e65,0x7225202c30316472,0x0a3b34202c333031,0x373109636f6c2e09\n"
".quad 0x090a300933313209,0x6d617261702e646c,0x722509203436752e,0x635f5f5b202c3264\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645664933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x0a3b5d7473645f62,0x373109636f6c2e09,0x090a300934323209,0x203436752e646461\n"
".quad 0x202c313164722509,0x7225202c32647225,0x646c090a3b303164,0x2e6c61626f6c672e\n"
".quad 0x7b092038752e3476,0x72252c3430317225,0x303172252c353031,0x255b202c7d5f2c36\n"
".quad 0x3b5d302b31316472,0x33732e627573090a,0x3730317225092032,0x2c3630317225202c\n"
".quad 0x090a3b3733722520,0x203233732e736261,0x202c383031722509,0x090a3b3730317225\n"
".quad 0x203233732e766f6d,0x202c393031722509,0x746573090a3b3031,0x2e3233752e74672e\n"
".quad 0x3172250920323373,0x30317225202c3031,0x3930317225202c38,0x732e67656e090a3b\n"
".quad 0x3131722509203233,0x3031317225202c31,0x732e627573090a3b,0x3131722509203233\n"
".quad 0x3430317225202c32,0x0a3b35337225202c,0x3233732e73626109,0x2c33313172250920\n"
".quad 0x0a3b323131722520,0x3233732e766f6d09,0x2c34313172250920,0x6573090a3b303120\n"
".quad 0x3233752e74672e74,0x722509203233732e,0x317225202c353131,0x31317225202c3331\n"
".quad 0x2e67656e090a3b34,0x3172250920323373,0x31317225202c3631,0x2e627573090a3b35\n"
".quad 0x3172250920323373,0x30317225202c3731,0x3b36337225202c35,0x33732e736261090a\n"
".quad 0x3831317225092032,0x3b3731317225202c,0x33732e766f6d090a,0x3931317225092032\n"
".quad 0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32,0x7225202c30323172\n"
".quad 0x317225202c383131,0x67656e090a3b3931,0x722509203233732e,0x317225202c313231\n"
".quad 0x2e726f090a3b3032,0x3172250920323362,0x31317225202c3232,0x3132317225202c36\n"
".quad 0x33622e726f090a3b,0x3332317225092032,0x2c3131317225202c,0x0a3b323231722520\n"
".quad 0x3233732e64646109,0x202c383572250920,0x7225202c38357225,0x744c240a3b333231\n"
".quad 0x32383430325f345f,0x6f6c3c2f2f200a3a,0x74726150203e706f,0x706f6f6c20666f20\n"
".quad 0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568,0x744c242064656c65\n"
".quad 0x38373138315f345f,0x33752e766f6d090a,0x3432317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c30317025092032,0x25202c3835722520,0x40090a3b34323172\n"
".quad 0x6172622030317025,0x5f345f744c240920,0x200a3b3439393032,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032\n"
".quad 0x656c6562616c2064,0x5f345f744c242064,0x2e090a3837313831,0x3209373109636f6c\n"
".quad 0x7663090a30093133,0x3233662e6e722e74,0x662509203233732e,0x3b35327225202c31\n"
".quad 0x6e722e747663090a,0x3233732e3233662e,0x25202c3266250920,0x646c090a3b363272\n"
".quad 0x662e6d617261702e,0x2c33662509203233,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x735f62696969695f,0x090a3b5d656c6163\n"
".quad 0x6d617261702e646c,0x662509203233662e,0x75635f5f5b202c34,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x0a3b5d66664f785f\n"
".quad 0x3233662e64616d09,0x25202c3566250920,0x2c336625202c3166,0x6c090a3b34662520\n"
".quad 0x2e6d617261702e64,0x3666250920323366,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x090a3b5d66664f79\n"
".quad 0x203233662e64616d,0x6625202c37662509,0x202c336625202c32,0x646c090a3b366625\n"
".quad 0x732e6d617261702e,0x3532317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x6d090a3b5d4a7369\n"
".quad 0x09203233752e766f,0x30202c3632317225,0x2e70746573090a3b,0x09203233732e7165\n"
".quad 0x7225202c31317025,0x317225202c353231,0x702540090a3b3632,0x0920617262203131\n"
".quad 0x31325f345f744c24,0x2f2f200a3b323637,0x50203e706f6f6c3c,0x6c20666f20747261\n"
".quad 0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31,0x2064656c6562616c\n"
".quad 0x38315f345f744c24,0x6f6c2e090a383731,0x3530320936310963,0x702e646c090a3009\n"
".quad 0x3233662e6d617261,0x5b202c3866250920,0x6170616475635f5f,0x4d36315a5f5f6d72\n"
".quad 0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764566,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x504a785f62696969,0x636f6c2e090a3b5d\n"
".quad 0x0936303209363109,0x61702e646c090a30,0x203233662e6d6172,0x5f5b202c39662509\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x664933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x5d504a795f626969,0x09636f6c2e090a3b,0x3009373032093631,0x33662e766f6d090a\n"
".quad 0x2c30316625092032,0x2e090a3b37662520,0x3209363109636f6c,0x6f6d090a30093830\n"
".quad 0x2509203233662e76,0x356625202c313166,0x09636f6c2e090a3b,0x3009393032093631\n"
".quad 0x33662e6c756d090a,0x2c32316625092032,0x6625202c37662520,0x636f6c2e090a3b37\n"
".quad 0x0930313209363109,0x662e6c756d090a30,0x3331662509203233,0x25202c356625202c\n"
".quad 0x617262090a3b3566,0x4c240920696e752e,0x303531325f345f74,0x345f744c240a3b36\n"
".quad 0x0a3a32363731325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461,0x345f744c24206465\n"
".quad 0x090a38373138315f,0x09363109636f6c2e,0x6d090a3009343132,0x09203233662e766f\n"
".quad 0x356625202c386625,0x09636f6c2e090a3b,0x3009353132093631,0x33662e766f6d090a\n"
".quad 0x202c396625092032,0x6c2e090a3b376625,0x313209363109636f,0x766f6d090a300939\n"
".quad 0x662509203233662e,0x30306630202c3331,0x203b303030303030,0x30202f2f09202020\n"
".quad 0x33662e766f6d090a,0x2c32316625092032,0x3030303030663020,0x202020203b303030\n"
".quad 0x6d090a30202f2f09,0x09203233662e766f,0x6630202c31316625,0x3030303030303030\n"
".quad 0x2f2f09202020203b,0x2e766f6d090a3020,0x3166250920323366,0x3030306630202c30\n"
".quad 0x20203b3030303030,0x0a30202f2f092020,0x31325f345f744c24,0x2f2f200a3a363035\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x303220656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x38315f345f744c24,0x6f6c2e090a383731\n"
".quad 0x3332320936310963,0x702e646c090a3009,0x3233732e6d617261,0x2c37323172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x635f62696969695f,0x0a3b5d68636e7572,0x3233732e62757309,0x2c38323172250920\n"
".quad 0x202c373231722520,0x2e766f6d090a3b31,0x3172250920323375,0x090a3b31202c3932\n"
".quad 0x2e71652e70746573,0x3170250920323373,0x3732317225202c32,0x3b3932317225202c\n"
".quad 0x203231702540090a,0x744c240920617262,0x34353533325f345f,0x6f6c3c2f2f200a3b\n"
".quad 0x74726150203e706f,0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e\n"
".quad 0x62616c2064616568,0x744c242064656c65,0x38373138315f345f,0x33662e646461090a\n"
".quad 0x2c34316625092032,0x25202c3331662520,0x6f6d090a3b323166,0x2509203233662e76\n"
".quad 0x346630202c353166,0x3b30303030303830,0x202f2f0920202020,0x2e70746573090a34\n"
".quad 0x09203233662e746c,0x6625202c33317025,0x35316625202c3431,0x3170252140090a3b\n"
".quad 0x2409206172622033,0x3533325f345f744c,0x345f4c240a3b3435,0x0a3a30333136315f\n"
".quad 0x706f6f6c3c2f2f20,0x6220706f6f4c203e,0x656e696c2079646f,0x6c2e090a34323220\n"
".quad 0x323209363109636f,0x6c756d090a300934,0x662509203233662e,0x31316625202c3631\n"
".quad 0x0a3b30316625202c,0x3233662e64646109,0x202c373166250920,0x6625202c36316625\n"
".quad 0x646461090a3b3631,0x662509203233662e,0x2c396625202c3031,0x090a3b3731662520\n"
".quad 0x09363109636f6c2e,0x73090a3009353232,0x09203233662e6275,0x6625202c38316625\n"
".quad 0x32316625202c3331,0x662e646461090a3b,0x3131662509203233,0x25202c386625202c\n"
".quad 0x6c2e090a3b383166,0x323209363109636f,0x6c756d090a300936,0x662509203233662e\n"
".quad 0x30316625202c3931,0x0a3b30316625202c,0x3233662e766f6d09,0x202c323166250920\n"
".quad 0x2e090a3b39316625,0x3209363109636f6c,0x756d090a30093732,0x2509203233662e6c\n"
".quad 0x316625202c303266,0x3b31316625202c31,0x33662e766f6d090a,0x2c33316625092032\n"
".quad 0x090a3b3032662520,0x09363109636f6c2e,0x73090a3009333232,0x09203233732e6275\n"
".quad 0x25202c3832317225,0x3b31202c38323172,0x33752e766f6d090a,0x3033317225092032\n"
".quad 0x6573090a3b30202c,0x33732e71652e7074,0x2c34317025092032,0x202c383231722520\n"
".quad 0x090a3b3033317225,0x7262203431702540,0x345f744c24092061,0x0a3b34353533325f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c34323220,0x6c6562616c206461,0x5f345f4c24206465,0x61090a3033313631\n"
".quad 0x09203233662e6464,0x6625202c31326625,0x30326625202c3931,0x662e766f6d090a3b\n"
".quad 0x3232662509203233,0x303830346630202c,0x2020203b30303030,0x090a34202f2f0920\n"
".quad 0x2e746c2e70746573,0x3170250920323366,0x2c31326625202c35,0x090a3b3232662520\n"
".quad 0x7262203531702540,0x5f345f4c24092061,0x240a3b3033313631,0x3533325f345f744c\n"
".quad 0x345f4c240a3a3435,0x0a3a36383336315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461\n"
".quad 0x345f744c24206465,0x090a38373138315f,0x09373109636f6c2e,0x6d090a3009313332\n"
".quad 0x09203233732e766f,0x30202c3133317225,0x2e70746573090a3b,0x09203233732e7467\n"
".quad 0x7225202c36317025,0x317225202c383231,0x6f6c2e090a3b3133,0x3332320936310963\n"
".quad 0x702e646c090a3009,0x3233732e6d617261,0x2c37323172250920,0x616475635f5f5b20\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x635f62696969695f\n"
".quad 0x0a3b5d68636e7572,0x373109636f6c2e09,0x090a300931333209,0x203233732e627573\n"
".quad 0x202c323331722509,0x25202c3732317225,0x6d090a3b38323172,0x09203233732e766f\n"
".quad 0x30202c3333317225,0x2e706c6573090a3b,0x3172250920323373,0x33317225202c3433\n"
".quad 0x3333317225202c32,0x0a3b36317025202c,0x3233752e766f6d09,0x2c35333172250920\n"
".quad 0x746573090a3b3020,0x3233732e71652e70,0x202c373170250920,0x25202c3433317225\n"
".quad 0x40090a3b35333172,0x6172622037317025,0x5f345f744c240920,0x200a3b3437323232\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313032,0x656c6562616c2064,0x5f345f744c242064,0x2e090a3837313831\n"
".quad 0x3209373109636f6c,0x646c090a30093833,0x732e6d617261702e,0x3331722509203233\n"
".quad 0x75635f5f5b202c36,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645664933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x6974616d696e615f,0x5d656d6172466e6f,0x732e646461090a3b\n"
".quad 0x3331722509203233,0x3633317225202c37,0x3b3433317225202c,0x7261702e646c090a\n"
".quad 0x25092038752e6d61,0x5f5b202c38333172,0x726170616475635f,0x614d36315a5f5f6d\n"
".quad 0x746f72626c65646e,0x664933316d735f31,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x6f6c6f635f626969,0x090a3b5d302b7372\n"
".quad 0x732e6f6c2e6c756d,0x3331722509203233,0x3733317225202c39,0x3b3833317225202c\n"
".quad 0x38752e747663090a,0x722509203233752e,0x317225202c303431,0x6f6c2e090a3b3933\n"
".quad 0x3933320937310963,0x702e646c090a3009,0x2038752e6d617261,0x202c313431722509\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f\n"
".quad 0x6375365076456649,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x6f635f6269696969,0x3b5d312b73726f6c,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x317225202c323431,0x34317225202c3733,0x2e747663090a3b31,0x09203233752e3875\n"
".quad 0x25202c3334317225,0x2e090a3b32343172,0x3209373109636f6c,0x646c090a30093034\n"
".quad 0x752e6d617261702e,0x3434317225092038,0x6475635f5f5b202c,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x322b73726f6c6f63\n"
".quad 0x2e6c756d090a3b5d,0x09203233732e6f6c,0x25202c3534317225,0x7225202c37333172\n"
".quad 0x7663090a3b343431,0x3233752e38752e74,0x2c36343172250920,0x0a3b353431722520\n"
".quad 0x696e752e61726209,0x5f345f744c240920,0x240a3b3831303232,0x3232325f345f744c\n"
".quad 0x3c2f2f200a3a3437,0x6150203e706f6f6c,0x6f6c20666f207472,0x2079646f6220706f\n"
".quad 0x31303220656e696c,0x6c2064616568202c,0x242064656c656261,0x3138315f345f744c\n"
".quad 0x636f6c2e090a3837,0x0934343209373109,0x752e766f6d090a30,0x3431722509203233\n"
".quad 0x6d090a3b30202c36,0x09203233752e766f,0x30202c3334317225,0x752e766f6d090a3b\n"
".quad 0x3431722509203233,0x4c240a3b30202c30,0x313032325f345f74,0x6c3c2f2f200a3a38\n"
".quad 0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31303220656e69\n"
".quad 0x616c206461656820,0x4c242064656c6562,0x373138315f345f74,0x09636f6c2e090a38\n"
".quad 0x3009303532093731,0x7261702e646c090a,0x09203233732e6d61,0x5b202c3734317225\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174\n"
".quad 0x6863753650764566,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x6172665f62696969,0x6461090a3b5d656d,0x2509203233732e64,0x7225202c38343172\n"
".quad 0x0a3b31202c373431,0x3233732e72687309,0x2c39343172250920,0x202c383431722520\n"
".quad 0x766f6d090a3b3133,0x722509203233732e,0x0a3b31202c303531,0x3233622e646e6109\n"
".quad 0x2c31353172250920,0x202c393431722520,0x090a3b3035317225,0x203233732e646461\n"
".quad 0x202c323531722509,0x25202c3135317225,0x73090a3b38343172,0x09203233732e7268\n"
".quad 0x25202c3335317225,0x3b31202c32353172,0x6f6c2e6c756d090a,0x722509203233732e\n"
".quad 0x317225202c343531,0x35337225202c3734,0x732e646461090a3b,0x3531722509203233\n"
".quad 0x3034317225202c35,0x3b3435317225202c,0x33732e646461090a,0x3635317225092032\n"
".quad 0x2c3335317225202c,0x0a3b353531722520,0x3233732e76696409,0x2c37353172250920\n"
".quad 0x202c363531722520,0x090a3b3834317225,0x09373109636f6c2e,0x6d090a3009313532\n"
".quad 0x33732e6f6c2e6c75,0x3835317225092032,0x2c3734317225202c,0x090a3b3633722520\n"
".quad 0x203233732e646461,0x202c393531722509,0x25202c3334317225,0x61090a3b38353172\n"
".quad 0x09203233732e6464,0x25202c3036317225,0x7225202c33353172,0x6964090a3b393531\n"
".quad 0x2509203233732e76,0x7225202c31363172,0x317225202c303631,0x2e7473090a3b3834\n"
".quad 0x762e6c61626f6c67,0x255b092038752e32,0x202c5d302b356472,0x252c37353172257b\n"
".quad 0x090a3b7d31363172,0x09373109636f6c2e,0x6d090a3009323532,0x33732e6f6c2e6c75\n"
".quad 0x3236317225092032,0x2c3734317225202c,0x090a3b3733722520,0x203233732e646461\n"
".quad 0x202c333631722509,0x25202c3634317225,0x61090a3b32363172,0x09203233732e6464\n"
".quad 0x25202c3436317225,0x7225202c33353172,0x6964090a3b333631,0x2509203233732e76\n"
".quad 0x7225202c35363172,0x317225202c343631,0x2e7473090a3b3834,0x752e6c61626f6c67\n"
".quad 0x356472255b092038,0x317225202c5d322b,0x5f744c240a3b3536,0x3a34393930325f34\n"
".quad 0x315f345f744c240a,0x2f200a3a34333438,0x203e706f6f6c3c2f,0x20666f2074726150\n"
".quad 0x646f6220706f6f6c,0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20\n"
".quad 0x315f345f744c2420,0x6c2e090a38373138,0x353209373109636f,0x726162090a300935\n"
".quad 0x300920636e79732e,0x752e766f6d090a3b,0x3631722509203233,0x73090a3b30202c36\n"
".quad 0x732e71652e707465,0x3831702509203233,0x25202c377225202c,0x40090a3b36363172\n"
".quad 0x6172622038317025,0x5f345f744c240920,0x200a3b3033353232,0x3e706f6f6c3c2f2f\n"
".quad 0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032\n"
".quad 0x656c6562616c2064,0x5f345f744c242064,0x2e090a3837313831,0x3209373109636f6c\n"
".quad 0x6f6d090a30093935,0x2509203436752e76,0x6c62202c32316472,0x746e756f436b636f\n"
".quad 0x766f6d090a3b7265,0x722509203233752e,0x0a3b31202c373631,0x6c672e6d6f746109\n"
".quad 0x6464612e6c61626f,0x722509203233752e,0x72255b202c383631,0x7225202c5d323164\n"
".quad 0x6f6d090a3b373631,0x2509203233732e76,0x7225202c39363172,0x7473090a3b383631\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f32345f35303636,0x646e496b636f6c62,0x317225202c5d7865,0x6f6c2e090a3b3936\n"
".quad 0x3036320937310963,0x702e646c090a3009,0x3233752e6d617261,0x2c30373172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645664933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x675f62696969695f,0x6874646957646972,0x2e6d6572090a3b5d,0x3172250920323375\n"
".quad 0x36317225202c3137,0x3037317225202c39,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x303636325f726176,0x6f6c625f32345f36\n"
".quad 0x7225202c5d586b63,0x6c2e090a3b313731,0x363209373109636f,0x766964090a300931\n"
".quad 0x722509203233752e,0x317225202c323731,0x37317225202c3936,0x732e7473090a3b30\n"
".quad 0x33752e6465726168,0x75635f5f5b092032,0x6c61636f6c5f6164,0x3636325f7261765f\n"
".quad 0x6c625f30355f3630,0x25202c5d596b636f,0x4c240a3b32373172,0x333532325f345f74\n"
".quad 0x6c3c2f2f200a3a30,0x726150203e706f6f,0x6f6f6c20666f2074,0x6c2079646f622070\n"
".quad 0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562,0x373138315f345f74\n"
".quad 0x09636f6c2e090a38,0x3009343632093731,0x79732e726162090a,0x090a3b300920636e\n"
".quad 0x65726168732e646c,0x2509203233752e64,0x5f5b202c33373172,0x6f6c5f616475635f\n"
".quad 0x5f7261765f6c6163,0x32345f3530363632,0x6e496b636f6c625f,0x73090a3b5d786564\n"
".quad 0x752e746c2e707465,0x3931702509203233,0x2c3337317225202c,0x090a3b3531722520\n"
".quad 0x7262203931702540,0x345f744c24092061,0x0a3b38373138315f,0x37315f345f744c24\n"
".quad 0x6c2e090a3a363636,0x363209373109636f,0x697865090a300937,0x6557444c240a3b74\n"
".quad 0x4d36315a5f5f646e,0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764566\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x7d090a3a62696969\n"
".quad 0x36315a5f202f2f20,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456649\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x090a0a6269696969\n"
".quad 0x5f207972746e652e,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x61702e09090a2820,0x3436752e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x73645f6269696969,0x61702e09090a2c74\n"
".quad 0x3233732e206d6172,0x70616475635f5f20,0x36315a5f5f6d7261,0x72626c65646e614d\n"
".quad 0x33316d735f31746f,0x6375365076456449,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x6d695f6269696969,0x09090a2c57656761,0x2e206d617261702e\n"
".quad 0x75635f5f20323373,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x2c486567616d695f,0x617261702e09090a,0x5f203233732e206d\n"
".quad 0x726170616475635f,0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f31\n"
".quad 0x6168637536507645,0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253\n"
".quad 0x6e7572635f626969,0x702e09090a2c6863,0x36662e206d617261,0x616475635f5f2034\n"
".quad 0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x785f62696969695f\n"
".quad 0x2e09090a2c66664f,0x662e206d61726170,0x6475635f5f203436,0x5a5f5f6d72617061\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30,0x09090a2c66664f79\n"
".quad 0x2e206d617261702e,0x75635f5f20343666,0x5f5f6d7261706164,0x65646e614d36315a\n"
".quad 0x735f31746f72626c,0x507645644933316d,0x6934726168637536,0x535f32535f546969\n"
".quad 0x5f32535f32535f32,0x62696969695f3053,0x09090a2c504a785f,0x2e206d617261702e\n"
".quad 0x75635f5f20343666,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x09090a2c504a795f,0x2e206d617261702e,0x75635f5f20343666\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x0a2c656c6163735f,0x6d617261702e0909,0x206e67696c612e20,0x5f5f2038622e2034\n"
".quad 0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564,0x45644933316d735f\n"
".quad 0x7261686375365076,0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32\n"
".quad 0x726f6c6f635f6269,0x09090a2c5d345b73,0x2e206d617261702e,0x75635f5f20323373\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x0a2c656d6172665f,0x6d617261702e0909,0x5f5f203233732e20,0x6d72617061647563\n"
".quad 0x6e614d36315a5f5f,0x31746f72626c6564,0x45644933316d735f,0x7261686375365076\n"
".quad 0x32535f5469696934,0x535f32535f32535f,0x6969695f30535f32,0x616d696e615f6269\n"
".quad 0x6d6172466e6f6974,0x61702e09090a2c65,0x3233732e206d6172,0x70616475635f5f20\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x72675f6269696969\n"
".quad 0x2c68746469576469,0x617261702e09090a,0x5f203233732e206d,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x426d756e5f626969\n"
".quad 0x090a2c736b636f6c,0x206d617261702e09,0x75635f5f2038732e,0x5f5f6d7261706164\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x7b090a294a73695f\n"
".quad 0x2e206765722e090a,0x3176722520323375,0x206765722e090a3b,0x3c7225203233752e\n"
".quad 0x2e090a3b3e353731,0x3436752e20676572,0x3e34313c64722520,0x206765722e090a3b\n"
".quad 0x646625203436662e,0x2e090a3b3e34323c,0x6572702e20676572,0x3e31323c70252064\n"
".quad 0x726168732e090a3b,0x203233752e206465,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f35303636325f,0x496b636f6c625f32,0x2e090a3b7865646e,0x2e20646572616873\n"
".quad 0x75635f5f20323375,0x6c61636f6c5f6164,0x3636325f7261765f,0x6c625f32345f3630\n"
".quad 0x2e090a3b586b636f,0x2e20646572616873,0x75635f5f20323375,0x6c61636f6c5f6164\n"
".quad 0x3636325f7261765f,0x6c625f30355f3630,0x2e090a3b596b636f,0x3109373109636f6c\n"
".quad 0x444c240a30093938,0x5f5f6e6967656257,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x752e747663090a3a,0x09203631752e3233,0x697425202c317225\n"
".quad 0x6f6d090a3b782e64,0x2509203233752e76,0x090a3b30202c3272,0x2e71652e70746573\n"
".quad 0x3170250920323375,0x25202c317225202c,0x747663090a3b3272,0x3631752e3233752e\n"
".quad 0x25202c3372250920,0x090a3b792e646974,0x203233752e766f6d,0x3b30202c34722509\n"
".quad 0x652e70746573090a,0x2509203233752e71,0x2c337225202c3270,0x73090a3b34722520\n"
".quad 0x203233732e706c65,0x2c31202c35722509,0x3b317025202c3020,0x732e706c6573090a\n"
".quad 0x2c36722509203233,0x25202c30202c3120,0x646e61090a3b3270,0x722509203233622e\n"
".quad 0x202c357225202c37,0x6f6d090a3b367225,0x2509203233752e76,0x090a3b30202c3872\n"
".quad 0x2e71652e70746573,0x3370250920323373,0x25202c377225202c,0x702540090a3b3872\n"
".quad 0x2409206172622033,0x3137315f355f744c,0x6f6c2e090a3b3435,0x3639310937310963\n"
".quad 0x2e766f6d090a3009,0x6472250920343675,0x6b636f6c62202c31,0x3b7265746e756f43\n"
".quad 0x33752e766f6d090a,0x202c397225092032,0x6d6f7461090a3b31,0x2e6c61626f6c672e\n"
".quad 0x203233752e646461,0x5b202c3031722509,0x25202c5d31647225,0x766f6d090a3b3972\n"
".quad 0x722509203233732e,0x30317225202c3131,0x68732e7473090a3b,0x3233752e64657261\n"
".quad 0x6475635f5f5b0920,0x5f6c61636f6c5f61,0x303636325f726176,0x6f6c625f32345f35\n"
".quad 0x5d7865646e496b63,0x0a3b31317225202c,0x373109636f6c2e09,0x090a300937393109\n"
".quad 0x6d617261702e646c,0x722509203233752e,0x635f5f5b202c3231,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x6957646972675f62\n"
".quad 0x72090a3b5d687464,0x09203233752e6d65,0x7225202c33317225,0x32317225202c3131\n"
".quad 0x68732e7473090a3b,0x3233752e64657261,0x6475635f5f5b0920,0x5f6c61636f6c5f61\n"
".quad 0x303636325f726176,0x6f6c625f32345f36,0x7225202c5d586b63,0x6f6c2e090a3b3331\n"
".quad 0x3839310937310963,0x2e766964090a3009,0x3172250920323375,0x2c31317225202c34\n"
".quad 0x090a3b3231722520,0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f\n"
".quad 0x7261765f6c61636f,0x355f36303636325f,0x596b636f6c625f30,0x3b34317225202c5d\n"
".quad 0x315f355f744c240a,0x2e090a3a34353137,0x3209373109636f6c,0x6162090a30093130\n"
".quad 0x0920636e79732e72,0x702e646c090a3b30,0x3233752e6d617261,0x202c353172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x756e5f6269696969,0x5d736b636f6c426d,0x68732e646c090a3b,0x3233752e64657261\n"
".quad 0x202c363172250920,0x5f616475635f5f5b,0x61765f6c61636f6c,0x5f35303636325f72\n"
".quad 0x6b636f6c625f3234,0x0a3b5d7865646e49,0x65672e7074657309,0x702509203233752e\n"
".quad 0x2c36317225202c34,0x090a3b3531722520,0x6172622034702540,0x5f355f744c240920\n"
".quad 0x090a3b3636363731,0x6d617261702e646c,0x722509203233732e,0x635f5f5b202c3731\n"
".quad 0x5f6d726170616475,0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73\n"
".quad 0x3472616863753650,0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f\n"
".quad 0x486567616d695f62,0x702e646c090a3b5d,0x3233732e6d617261,0x202c383172250920\n"
".quad 0x70616475635f5f5b,0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f\n"
".quad 0x6375365076456449,0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32\n"
".quad 0x6d695f6269696969,0x090a3b5d57656761,0x2e3233752e747663,0x3172250920363175\n"
".quad 0x6469746e25202c39,0x747663090a3b792e,0x3631752e3233752e,0x202c303272250920\n"
".quad 0x3b782e6469746e25,0x315f355f744c240a,0x2f200a3a38373138,0x203e706f6f6c3c2f\n"
".quad 0x646f6220706f6f4c,0x3220656e696c2079,0x732e646c090a3130,0x33752e6465726168\n"
".quad 0x2c31327225092032,0x616475635f5f5b20,0x765f6c61636f6c5f,0x36303636325f7261\n"
".quad 0x636f6c625f32345f,0x756d090a3b5d586b,0x3233752e6f6c2e6c,0x202c323272250920\n"
".quad 0x7225202c31327225,0x2e646c090a3b3032,0x752e646572616873,0x3332722509203233\n"
".quad 0x6475635f5f5b202c,0x5f6c61636f6c5f61,0x303636325f726176,0x6f6c625f30355f36\n"
".quad 0x6d090a3b5d596b63,0x33752e6f6c2e6c75,0x2c34327225092032,0x25202c3332722520\n"
".quad 0x6461090a3b393172,0x2509203233752e64,0x327225202c353272,0x0a3b317225202c32\n"
".quad 0x3233752e64646109,0x202c363272250920,0x7225202c34327225,0x2e746573090a3b33\n"
".quad 0x732e3233752e7467,0x3732722509203233,0x202c37317225202c,0x6e090a3b36327225\n"
".quad 0x09203233732e6765,0x7225202c38327225,0x746573090a3b3732,0x2e3233752e74672e\n"
".quad 0x3272250920323373,0x2c38317225202c39,0x090a3b3532722520,0x203233732e67656e\n"
".quad 0x25202c3033722509,0x6e61090a3b393272,0x2509203233622e64,0x327225202c313372\n"
".quad 0x3b30337225202c38,0x33752e766f6d090a,0x2c32337225092032,0x746573090a3b3020\n"
".quad 0x3233732e71652e70,0x25202c3570250920,0x337225202c313372,0x35702540090a3b32\n"
".quad 0x4c24092061726220,0x393930325f355f74,0x6c3c2f2f200a3b34,0x726150203e706f6f\n"
".quad 0x6f6f6c20666f2074,0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820\n"
".quad 0x4c242064656c6562,0x373138315f355f74,0x09636f6c2e090a38,0x3009333132093731\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x38317225202c3333,0x0a3b36327225202c\n"
".quad 0x3233732e64646109,0x202c343372250920,0x7225202c35327225,0x2e646c090a3b3333\n"
".quad 0x36752e6d61726170,0x2c32647225092034,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x645f62696969695f,0x7663090a3b5d7473\n"
".quad 0x33732e3436732e74,0x2c33647225092032,0x090a3b3433722520,0x656469772e6c756d\n"
".quad 0x722509203233732e,0x34337225202c3464,0x6461090a3b34202c,0x2509203436752e64\n"
".quad 0x647225202c356472,0x3b34647225202c32,0x6f6c672e646c090a,0x752e34762e6c6162\n"
".quad 0x353372257b092038,0x72252c363372252c,0x5b202c7d5f2c3733,0x3b5d302b35647225\n"
".quad 0x33752e766f6d090a,0x2c38337225092032,0x746573090a3b3020,0x3233732e656c2e70\n"
".quad 0x25202c3670250920,0x337225202c353272,0x36702540090a3b38,0x4c24092061726220\n"
".quad 0x303239315f355f74,0x6c3c2f2f200a3b32,0x726150203e706f6f,0x6f6f6c20666f2074\n"
".quad 0x6c2079646f622070,0x2c31303220656e69,0x616c206461656820,0x4c242064656c6562\n"
".quad 0x373138315f355f74,0x6c672e646c090a38,0x2e34762e6c61626f,0x3372257b09203875\n"
".quad 0x252c303472252c39,0x202c7d5f2c313472,0x342d2b356472255b,0x636f6c2e090a3b5d\n"
".quad 0x0938313209373109,0x732e627573090a30,0x3234722509203233,0x202c31347225202c\n"
".quad 0x61090a3b37337225,0x09203233732e7362,0x7225202c33347225,0x766f6d090a3b3234\n"
".quad 0x722509203233732e,0x0a3b3031202c3434,0x2e74672e74657309,0x203233732e323375\n"
".quad 0x25202c3534722509,0x347225202c333472,0x2e67656e090a3b34,0x3472250920323373\n"
".quad 0x3b35347225202c36,0x33732e627573090a,0x2c37347225092032,0x25202c3933722520\n"
".quad 0x6261090a3b353372,0x2509203233732e73,0x347225202c383472,0x2e766f6d090a3b37\n"
".quad 0x3472250920323373,0x090a3b3031202c39,0x752e74672e746573,0x09203233732e3233\n"
".quad 0x7225202c30357225,0x39347225202c3834,0x732e67656e090a3b,0x3135722509203233\n"
".quad 0x0a3b30357225202c,0x3233732e62757309,0x202c323572250920,0x7225202c30347225\n"
".quad 0x736261090a3b3633,0x722509203233732e,0x32357225202c3335,0x732e766f6d090a3b\n"
".quad 0x3435722509203233,0x73090a3b3031202c,0x33752e74672e7465,0x2509203233732e32\n"
".quad 0x357225202c353572,0x3b34357225202c33,0x33732e67656e090a,0x2c36357225092032\n"
".quad 0x090a3b3535722520,0x09203233622e726f,0x7225202c37357225,0x36357225202c3135\n"
".quad 0x33622e726f090a3b,0x2c38357225092032,0x25202c3634722520,0x7262090a3b373572\n"
".quad 0x240920696e752e61,0x3938315f355f744c,0x5f744c240a3b3634,0x3a32303239315f35\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f35\n"
".quad 0x3233732e766f6d09,0x202c383572250920,0x355f744c240a3b30,0x0a3a36343938315f\n"
".quad 0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f\n"
".quad 0x6568202c31303220,0x6c6562616c206461,0x355f744c24206465,0x090a38373138315f\n"
".quad 0x203233732e646461,0x25202c3935722509,0x0a3b31202c353272,0x656c2e7074657309\n"
".quad 0x702509203233732e,0x2c38317225202c37,0x090a3b3935722520,0x6172622037702540\n"
".quad 0x5f355f744c240920,0x200a3b3835343931,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032,0x656c6562616c2064\n"
".quad 0x5f355f744c242064,0x6c090a3837313831,0x6c61626f6c672e64,0x092038752e34762e\n"
".quad 0x72252c303672257b,0x2c323672252c3136,0x6472255b202c7d5f,0x2e090a3b5d342b35\n"
".quad 0x3209373109636f6c,0x7573090a30093032,0x2509203233732e62,0x367225202c333672\n"
".quad 0x3b37337225202c32,0x33732e736261090a,0x2c34367225092032,0x090a3b3336722520\n"
".quad 0x203233732e766f6d,0x31202c3536722509,0x2e746573090a3b30,0x732e3233752e7467\n"
".quad 0x3636722509203233,0x202c34367225202c,0x6e090a3b35367225,0x09203233732e6765\n"
".quad 0x7225202c37367225,0x627573090a3b3636,0x722509203233732e,0x30367225202c3836\n"
".quad 0x0a3b35337225202c,0x3233732e73626109,0x202c393672250920,0x6d090a3b38367225\n"
".quad 0x09203233732e766f,0x3031202c30377225,0x672e746573090a3b,0x33732e3233752e74\n"
".quad 0x2c31377225092032,0x25202c3936722520,0x656e090a3b303772,0x2509203233732e67\n"
".quad 0x377225202c323772,0x2e627573090a3b31,0x3772250920323373,0x2c31367225202c33\n"
".quad 0x090a3b3633722520,0x203233732e736261,0x25202c3437722509,0x6f6d090a3b333772\n"
".quad 0x2509203233732e76,0x3b3031202c353772,0x74672e746573090a,0x3233732e3233752e\n"
".quad 0x202c363772250920,0x7225202c34377225,0x67656e090a3b3537,0x722509203233732e\n"
".quad 0x36377225202c3737,0x33622e726f090a3b,0x2c38377225092032,0x25202c3237722520\n"
".quad 0x726f090a3b373772,0x722509203233622e,0x37367225202c3937,0x0a3b38377225202c\n"
".quad 0x3233732e64646109,0x202c383572250920,0x7225202c38357225,0x5f744c240a3b3937\n"
".quad 0x3a38353439315f35,0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f\n"
".quad 0x6e696c2079646f62,0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c\n"
".quad 0x0a38373138315f35,0x3233752e766f6d09,0x202c303872250920,0x70746573090a3b30\n"
".quad 0x203233732e656c2e,0x7225202c38702509,0x30387225202c3632,0x2038702540090a3b\n"
".quad 0x744c240920617262,0x30373939315f355f,0x6f6c3c2f2f200a3b,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373138315f355f,0x3109636f6c2e090a,0x0a30093232320937\n"
".quad 0x3233732e62757309,0x202c313872250920,0x7225202c34337225,0x747663090a3b3831\n"
".quad 0x3233732e3436732e,0x202c366472250920,0x6d090a3b31387225,0x2e656469772e6c75\n"
".quad 0x6472250920323373,0x2c31387225202c37,0x6f6c2e090a3b3420,0x3331320937310963\n"
".quad 0x702e646c090a3009,0x3436752e6d617261,0x202c326472250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x73645f6269696969\n"
".quad 0x6f6c2e090a3b5d74,0x3232320937310963,0x2e646461090a3009,0x6472250920343675\n"
".quad 0x2c32647225202c38,0x090a3b3764722520,0x61626f6c672e646c,0x2038752e34762e6c\n"
".quad 0x252c323872257b09,0x343872252c333872,0x72255b202c7d5f2c,0x090a3b5d302b3864\n"
".quad 0x203233732e627573,0x25202c3538722509,0x337225202c343872,0x2e736261090a3b37\n"
".quad 0x3872250920323373,0x3b35387225202c36,0x33732e766f6d090a,0x2c37387225092032\n"
".quad 0x6573090a3b303120,0x3233752e74672e74,0x722509203233732e,0x36387225202c3838\n"
".quad 0x0a3b37387225202c,0x3233732e67656e09,0x202c393872250920,0x73090a3b38387225\n"
".quad 0x09203233732e6275,0x7225202c30397225,0x35337225202c3238,0x732e736261090a3b\n"
".quad 0x3139722509203233,0x0a3b30397225202c,0x3233732e766f6d09,0x202c323972250920\n"
".quad 0x746573090a3b3031,0x2e3233752e74672e,0x3972250920323373,0x2c31397225202c33\n"
".quad 0x090a3b3239722520,0x203233732e67656e,0x25202c3439722509,0x7573090a3b333972\n"
".quad 0x2509203233732e62,0x387225202c353972,0x3b36337225202c33,0x33732e736261090a\n"
".quad 0x2c36397225092032,0x090a3b3539722520,0x203233732e766f6d,0x31202c3739722509\n"
".quad 0x2e746573090a3b30,0x732e3233752e7467,0x3839722509203233,0x202c36397225202c\n"
".quad 0x6e090a3b37397225,0x09203233732e6765,0x7225202c39397225,0x2e726f090a3b3839\n"
".quad 0x3172250920323362,0x34397225202c3030,0x0a3b39397225202c,0x203233622e726f09\n"
".quad 0x202c313031722509,0x7225202c39387225,0x6461090a3b303031,0x2509203233732e64\n"
".quad 0x357225202c383572,0x3130317225202c38,0x5f355f744c240a3b,0x200a3a3037393931\n"
".quad 0x3e706f6f6c3c2f2f,0x666f207472615020,0x6f6220706f6f6c20,0x20656e696c207964\n"
".quad 0x616568202c313032,0x656c6562616c2064,0x5f355f744c242064,0x61090a3837313831\n"
".quad 0x09203233732e6464,0x25202c3230317225,0x0a3b31202c363272,0x656c2e7074657309\n"
".quad 0x702509203233732e,0x2c37317225202c39,0x0a3b323031722520,0x7262203970254009\n"
".quad 0x355f744c24092061,0x0a3b32383430325f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461\n"
".quad 0x355f744c24206465,0x090a38373138315f,0x09373109636f6c2e,0x61090a3009343232\n"
".quad 0x09203233732e6464,0x25202c3330317225,0x317225202c343372,0x2e747663090a3b38\n"
".quad 0x203233732e343673,0x25202c3964722509,0x6d090a3b33303172,0x2e656469772e6c75\n"
".quad 0x6472250920323373,0x30317225202c3031,0x2e090a3b34202c33,0x3209373109636f6c\n"
".quad 0x646c090a30093331,0x752e6d617261702e,0x3264722509203436,0x6475635f5f5b202c\n"
".quad 0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493331\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x5f62696969695f30\n"
".quad 0x2e090a3b5d747364,0x3209373109636f6c,0x6461090a30093432,0x2509203436752e64\n"
".quad 0x7225202c31316472,0x31647225202c3264,0x672e646c090a3b30,0x34762e6c61626f6c\n"
".quad 0x72257b092038752e,0x303172252c343031,0x2c36303172252c35,0x6472255b202c7d5f\n"
".quad 0x090a3b5d302b3131,0x203233732e627573,0x202c373031722509,0x25202c3630317225\n"
".quad 0x6261090a3b373372,0x2509203233732e73,0x7225202c38303172,0x6f6d090a3b373031\n"
".quad 0x2509203233732e76,0x3031202c39303172,0x672e746573090a3b,0x33732e3233752e74\n"
".quad 0x3031317225092032,0x2c3830317225202c,0x0a3b393031722520,0x3233732e67656e09\n"
".quad 0x2c31313172250920,0x0a3b303131722520,0x3233732e62757309,0x2c32313172250920\n"
".quad 0x202c343031722520,0x61090a3b35337225,0x09203233732e7362,0x25202c3331317225\n"
".quad 0x6d090a3b32313172,0x09203233732e766f,0x31202c3431317225,0x2e746573090a3b30\n"
".quad 0x732e3233752e7467,0x3131722509203233,0x3331317225202c35,0x3b3431317225202c\n"
".quad 0x33732e67656e090a,0x3631317225092032,0x3b3531317225202c,0x33732e627573090a\n"
".quad 0x3731317225092032,0x2c3530317225202c,0x090a3b3633722520,0x203233732e736261\n"
".quad 0x202c383131722509,0x090a3b3731317225,0x203233732e766f6d,0x202c393131722509\n"
".quad 0x746573090a3b3031,0x2e3233752e74672e,0x3172250920323373,0x31317225202c3032\n"
".quad 0x3931317225202c38,0x732e67656e090a3b,0x3231722509203233,0x3032317225202c31\n"
".quad 0x33622e726f090a3b,0x3232317225092032,0x2c3631317225202c,0x0a3b313231722520\n"
".quad 0x203233622e726f09,0x202c333231722509,0x25202c3131317225,0x61090a3b32323172\n"
".quad 0x09203233732e6464,0x7225202c38357225,0x32317225202c3835,0x355f744c240a3b33\n"
".quad 0x0a3a32383430325f,0x706f6f6c3c2f2f20,0x6f2074726150203e,0x6220706f6f6c2066\n"
".quad 0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461,0x355f744c24206465\n"
".quad 0x090a38373138315f,0x203233752e766f6d,0x202c343231722509,0x70746573090a3b30\n"
".quad 0x203233732e71652e,0x25202c3031702509,0x317225202c383572,0x702540090a3b3432\n"
".quad 0x0920617262203031,0x30325f355f744c24,0x2f2f200a3b343939,0x50203e706f6f6c3c\n"
".quad 0x6c20666f20747261,0x79646f6220706f6f,0x303220656e696c20,0x2064616568202c31\n"
".quad 0x2064656c6562616c,0x38315f355f744c24,0x6f6c2e090a383731,0x3133320937310963\n"
".quad 0x702e646c090a3009,0x3436662e6d617261,0x202c316466250920,0x70616475635f5f5b\n"
".quad 0x36315a5f5f6d7261,0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x63735f6269696969\n"
".quad 0x6c090a3b5d656c61,0x2e6d617261702e64,0x6466250920343666,0x75635f5f5b202c32\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x0a3b5d66664f785f,0x2e6e722e74766309,0x203233732e343666,0x25202c3364662509\n"
".quad 0x616d090a3b353272,0x3436662e6e722e64,0x202c346466250920,0x6625202c33646625\n"
".quad 0x32646625202c3164,0x61702e646c090a3b,0x203436662e6d6172,0x5b202c3564662509\n"
".quad 0x6170616475635f5f,0x4d36315a5f5f6d72,0x6f72626c65646e61,0x4933316d735f3174\n"
".quad 0x6863753650764564,0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f\n"
".quad 0x664f795f62696969,0x747663090a3b5d66,0x2e3436662e6e722e,0x6466250920323373\n"
".quad 0x3b36327225202c36,0x6e722e64616d090a,0x662509203436662e,0x36646625202c3764\n"
".quad 0x202c31646625202c,0x6c090a3b35646625,0x2e6d617261702e64,0x3231722509203873\n"
".quad 0x75635f5f5b202c35,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x090a3b5d4a73695f,0x203233752e766f6d,0x202c363231722509\n"
".quad 0x70746573090a3b30,0x203233732e71652e,0x25202c3131702509,0x7225202c35323172\n"
".quad 0x2540090a3b363231,0x2061726220313170,0x325f355f744c2409,0x2f200a3b32363731\n"
".quad 0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c,0x3220656e696c2079\n"
".quad 0x64616568202c3130,0x64656c6562616c20,0x315f355f744c2420,0x6c2e090a38373138\n"
".quad 0x303209363109636f,0x2e646c090a300935,0x36662e6d61726170,0x2c38646625092034\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x785f62696969695f,0x6c2e090a3b5d504a,0x303209363109636f,0x2e646c090a300936\n"
".quad 0x36662e6d61726170,0x2c39646625092034,0x616475635f5f5b20,0x315a5f5f6d726170\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x795f62696969695f,0x6c2e090a3b5d504a\n"
".quad 0x303209363109636f,0x766f6d090a300937,0x662509203436662e,0x646625202c303164\n"
".quad 0x636f6c2e090a3b37,0x0938303209363109,0x662e766f6d090a30,0x3164662509203436\n"
".quad 0x3b34646625202c31,0x3109636f6c2e090a,0x0a30093930320936,0x3436662e6c756d09\n"
".quad 0x2c32316466250920,0x25202c3764662520,0x6c2e090a3b376466,0x313209363109636f\n"
".quad 0x6c756d090a300930,0x662509203436662e,0x646625202c333164,0x3b34646625202c34\n"
".quad 0x6e752e617262090a,0x355f744c24092069,0x0a3b36303531325f,0x31325f355f744c24\n"
".quad 0x2f2f200a3a323637,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x303220656e696c20,0x2064616568202c31,0x2064656c6562616c,0x38315f355f744c24\n"
".quad 0x6f6c2e090a383731,0x3431320936310963,0x2e766f6d090a3009,0x6466250920343666\n"
".quad 0x3b34646625202c38,0x3109636f6c2e090a,0x0a30093531320936,0x3436662e766f6d09\n"
".quad 0x202c396466250920,0x2e090a3b37646625,0x3209363109636f6c,0x6f6d090a30093931\n"
".quad 0x2509203436662e76,0x6430202c33316466,0x3030303030303030,0x3030303030303030\n"
".quad 0x090a30202f2f093b,0x203436662e766f6d,0x202c323164662509,0x3030303030306430\n"
".quad 0x3030303030303030,0x30202f2f093b3030,0x36662e766f6d090a,0x3131646625092034\n"
".quad 0x303030306430202c,0x3030303030303030,0x2f2f093b30303030,0x2e766f6d090a3020\n"
".quad 0x6466250920343666,0x30306430202c3031,0x3030303030303030,0x093b303030303030\n"
".quad 0x744c240a30202f2f,0x36303531325f355f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373138315f355f,0x3109636f6c2e090a,0x0a30093332320936\n"
".quad 0x617261702e646c09,0x2509203233732e6d,0x5f5b202c37323172,0x726170616475635f\n"
".quad 0x614d36315a5f5f6d,0x746f72626c65646e,0x644933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x6e7572635f626969\n"
".quad 0x7573090a3b5d6863,0x2509203233732e62,0x7225202c38323172,0x0a3b31202c373231\n"
".quad 0x3233752e766f6d09,0x2c39323172250920,0x746573090a3b3120,0x3233732e71652e70\n"
".quad 0x202c323170250920,0x25202c3732317225,0x40090a3b39323172,0x6172622032317025\n"
".quad 0x5f355f744c240920,0x200a3b3435353332,0x3e706f6f6c3c2f2f,0x666f207472615020\n"
".quad 0x6f6220706f6f6c20,0x20656e696c207964,0x616568202c313032,0x656c6562616c2064\n"
".quad 0x5f355f744c242064,0x61090a3837313831,0x09203436662e6464,0x25202c3431646625\n"
".quad 0x6625202c33316466,0x6f6d090a3b323164,0x2509203436662e76,0x6430202c35316466\n"
".quad 0x3030303030313034,0x3030303030303030,0x090a34202f2f093b,0x2e746c2e70746573\n"
".quad 0x3170250920343666,0x3431646625202c33,0x3b3531646625202c,0x333170252140090a\n"
".quad 0x4c24092061726220,0x353533325f355f74,0x5f355f4c240a3b34,0x200a3a3033313631\n"
".quad 0x3e706f6f6c3c2f2f,0x6f6220706f6f4c20,0x20656e696c207964,0x6f6c2e090a343232\n"
".quad 0x3432320936310963,0x2e6c756d090a3009,0x6466250920343666,0x31646625202c3631\n"
".quad 0x3031646625202c31,0x662e646461090a3b,0x3164662509203436,0x3631646625202c37\n"
".quad 0x3b3631646625202c,0x36662e646461090a,0x3031646625092034,0x202c39646625202c\n"
".quad 0x090a3b3731646625,0x09363109636f6c2e,0x73090a3009353232,0x09203436662e6275\n"
".quad 0x25202c3831646625,0x6625202c33316466,0x6461090a3b323164,0x2509203436662e64\n"
".quad 0x6625202c31316466,0x31646625202c3864,0x636f6c2e090a3b38,0x0936323209363109\n"
".quad 0x662e6c756d090a30,0x3164662509203436,0x3031646625202c39,0x3b3031646625202c\n"
".quad 0x36662e766f6d090a,0x3231646625092034,0x3b3931646625202c,0x3109636f6c2e090a\n"
".quad 0x0a30093732320936,0x3436662e6c756d09,0x2c30326466250920,0x202c313164662520\n"
".quad 0x090a3b3131646625,0x203436662e766f6d,0x202c333164662509,0x090a3b3032646625\n"
".quad 0x09363109636f6c2e,0x73090a3009333232,0x09203233732e6275,0x25202c3832317225\n"
".quad 0x3b31202c38323172,0x33752e766f6d090a,0x3033317225092032,0x6573090a3b30202c\n"
".quad 0x33732e71652e7074,0x2c34317025092032,0x202c383231722520,0x090a3b3033317225\n"
".quad 0x7262203431702540,0x355f744c24092061,0x0a3b34353533325f,0x706f6f6c3c2f2f20\n"
".quad 0x6f2074726150203e,0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c34323220\n"
".quad 0x6c6562616c206461,0x5f355f4c24206465,0x61090a3033313631,0x09203436662e6464\n"
".quad 0x25202c3132646625,0x6625202c39316466,0x6f6d090a3b303264,0x2509203436662e76\n"
".quad 0x6430202c32326466,0x3030303030313034,0x3030303030303030,0x090a34202f2f093b\n"
".quad 0x2e746c2e70746573,0x3170250920343666,0x3132646625202c35,0x3b3232646625202c\n"
".quad 0x203531702540090a,0x5f4c240920617262,0x3b30333136315f35,0x325f355f744c240a\n"
".quad 0x4c240a3a34353533,0x36383336315f355f,0x6f6c3c2f2f200a3a,0x74726150203e706f\n"
".quad 0x706f6f6c20666f20,0x696c2079646f6220,0x202c31303220656e,0x62616c2064616568\n"
".quad 0x744c242064656c65,0x38373138315f355f,0x3109636f6c2e090a,0x0a30093133320937\n"
".quad 0x3233732e766f6d09,0x2c31333172250920,0x746573090a3b3020,0x3233732e74672e70\n"
".quad 0x202c363170250920,0x25202c3832317225,0x2e090a3b31333172,0x3209363109636f6c\n"
".quad 0x646c090a30093332,0x732e6d617261702e,0x3231722509203233,0x75635f5f5b202c37\n"
".quad 0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x5d68636e7572635f,0x09636f6c2e090a3b,0x3009313332093731,0x33732e627573090a\n"
".quad 0x3233317225092032,0x2c3732317225202c,0x0a3b383231722520,0x3233732e766f6d09\n"
".quad 0x2c33333172250920,0x6c6573090a3b3020,0x2509203233732e70,0x7225202c34333172\n"
".quad 0x317225202c323331,0x36317025202c3333,0x752e766f6d090a3b,0x3331722509203233\n"
".quad 0x73090a3b30202c35,0x732e71652e707465,0x3731702509203233,0x2c3433317225202c\n"
".quad 0x0a3b353331722520,0x6220373170254009,0x5f744c2409206172,0x3b34373232325f35\n"
".quad 0x6f6f6c3c2f2f200a,0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62\n"
".quad 0x68202c3130322065,0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f35\n"
".quad 0x373109636f6c2e09,0x090a300938333209,0x6d617261702e646c,0x722509203233732e\n"
".quad 0x5f5f5b202c363331,0x6d72617061647563,0x6e614d36315a5f5f,0x31746f72626c6564\n"
".quad 0x45644933316d735f,0x7261686375365076,0x32535f5469696934,0x535f32535f32535f\n"
".quad 0x6969695f30535f32,0x616d696e615f6269,0x6d6172466e6f6974,0x646461090a3b5d65\n"
".quad 0x722509203233732e,0x317225202c373331,0x33317225202c3633,0x702e646c090a3b34\n"
".quad 0x2038752e6d617261,0x202c383331722509,0x70616475635f5f5b,0x36315a5f5f6d7261\n"
".quad 0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6f635f6269696969,0x3b5d302b73726f6c\n"
".quad 0x6f6c2e6c756d090a,0x722509203233732e,0x317225202c393331,0x33317225202c3733\n"
".quad 0x2e747663090a3b38,0x09203233752e3875,0x25202c3034317225,0x2e090a3b39333172\n"
".quad 0x3209373109636f6c,0x646c090a30093933,0x752e6d617261702e,0x3134317225092038\n"
".quad 0x6475635f5f5b202c,0x5a5f5f6d72617061,0x6c65646e614d3631,0x6d735f31746f7262\n"
".quad 0x3650764564493331,0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f\n"
".quad 0x5f62696969695f30,0x312b73726f6c6f63,0x2e6c756d090a3b5d,0x09203233732e6f6c\n"
".quad 0x25202c3234317225,0x7225202c37333172,0x7663090a3b313431,0x3233752e38752e74\n"
".quad 0x2c33343172250920,0x0a3b323431722520,0x373109636f6c2e09,0x090a300930343209\n"
".quad 0x6d617261702e646c,0x317225092038752e,0x635f5f5b202c3434,0x5f6d726170616475\n"
".quad 0x646e614d36315a5f,0x5f31746f72626c65,0x7645644933316d73,0x3472616863753650\n"
".quad 0x5f32535f54696969,0x32535f32535f3253,0x696969695f30535f,0x73726f6c6f635f62\n"
".quad 0x756d090a3b5d322b,0x3233732e6f6c2e6c,0x2c35343172250920,0x202c373331722520\n"
".quad 0x090a3b3434317225,0x752e38752e747663,0x3431722509203233,0x3534317225202c36\n"
".quad 0x752e617262090a3b,0x5f744c240920696e,0x3b38313032325f35,0x325f355f744c240a\n"
".quad 0x2f200a3a34373232,0x203e706f6f6c3c2f,0x20666f2074726150,0x646f6220706f6f6c\n"
".quad 0x3220656e696c2079,0x64616568202c3130,0x64656c6562616c20,0x315f355f744c2420\n"
".quad 0x6c2e090a38373138,0x343209373109636f,0x766f6d090a300934,0x722509203233752e\n"
".quad 0x0a3b30202c363431,0x3233752e766f6d09,0x2c33343172250920,0x766f6d090a3b3020\n"
".quad 0x722509203233752e,0x0a3b30202c303431,0x32325f355f744c24,0x2f2f200a3a383130\n"
".quad 0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f,0x303220656e696c20\n"
".quad 0x2064616568202c31,0x2064656c6562616c,0x38315f355f744c24,0x6f6c2e090a383731\n"
".quad 0x3035320937310963,0x702e646c090a3009,0x3233732e6d617261,0x2c37343172250920\n"
".quad 0x616475635f5f5b20,0x315a5f5f6d726170,0x626c65646e614d36,0x316d735f31746f72\n"
".quad 0x7536507645644933,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x665f62696969695f,0x090a3b5d656d6172,0x203233732e646461,0x202c383431722509\n"
".quad 0x31202c3734317225,0x732e726873090a3b,0x3431722509203233,0x3834317225202c39\n"
".quad 0x6d090a3b3133202c,0x09203233732e766f,0x31202c3035317225,0x622e646e61090a3b\n"
".quad 0x3531722509203233,0x3934317225202c31,0x3b3035317225202c,0x33732e646461090a\n"
".quad 0x3235317225092032,0x2c3135317225202c,0x0a3b383431722520,0x3233732e72687309\n"
".quad 0x2c33353172250920,0x202c323531722520,0x2e6c756d090a3b31,0x09203233732e6f6c\n"
".quad 0x25202c3435317225,0x7225202c37343172,0x646461090a3b3533,0x722509203233732e\n"
".quad 0x317225202c353531,0x35317225202c3034,0x2e646461090a3b34,0x3172250920323373\n"
".quad 0x35317225202c3635,0x3535317225202c33,0x732e766964090a3b,0x3531722509203233\n"
".quad 0x3635317225202c37,0x3b3834317225202c,0x3109636f6c2e090a,0x0a30093135320937\n"
".quad 0x2e6f6c2e6c756d09,0x3172250920323373,0x34317225202c3835,0x3b36337225202c37\n"
".quad 0x33732e646461090a,0x3935317225092032,0x2c3334317225202c,0x0a3b383531722520\n"
".quad 0x3233732e64646109,0x2c30363172250920,0x202c333531722520,0x090a3b3935317225\n"
".quad 0x203233732e766964,0x202c313631722509,0x25202c3036317225,0x73090a3b38343172\n"
".quad 0x6c61626f6c672e74,0x092038752e32762e,0x5d302b356472255b,0x37353172257b202c\n"
".quad 0x3b7d31363172252c,0x3109636f6c2e090a,0x0a30093235320937,0x2e6f6c2e6c756d09\n"
".quad 0x3172250920323373,0x34317225202c3236,0x3b37337225202c37,0x33732e646461090a\n"
".quad 0x3336317225092032,0x2c3634317225202c,0x0a3b323631722520,0x3233732e64646109\n"
".quad 0x2c34363172250920,0x202c333531722520,0x090a3b3336317225,0x203233732e766964\n"
".quad 0x202c353631722509,0x25202c3436317225,0x73090a3b38343172,0x6c61626f6c672e74\n"
".quad 0x72255b092038752e,0x25202c5d322b3564,0x4c240a3b35363172,0x393930325f355f74\n"
".quad 0x355f744c240a3a34,0x0a3a34333438315f,0x706f6f6c3c2f2f20,0x6f2074726150203e\n"
".quad 0x6220706f6f6c2066,0x656e696c2079646f,0x6568202c31303220,0x6c6562616c206461\n"
".quad 0x355f744c24206465,0x090a38373138315f,0x09373109636f6c2e,0x62090a3009353532\n"
".quad 0x20636e79732e7261,0x766f6d090a3b3009,0x722509203233752e,0x0a3b30202c363631\n"
".quad 0x71652e7074657309,0x702509203233732e,0x2c377225202c3831,0x0a3b363631722520\n"
".quad 0x6220383170254009,0x5f744c2409206172,0x3b30333532325f35,0x6f6f6c3c2f2f200a\n"
".quad 0x2074726150203e70,0x20706f6f6c20666f,0x6e696c2079646f62,0x68202c3130322065\n"
".quad 0x6562616c20646165,0x5f744c242064656c,0x0a38373138315f35,0x373109636f6c2e09\n"
".quad 0x090a300939353209,0x203436752e766f6d,0x202c323164722509,0x756f436b636f6c62\n"
".quad 0x6d090a3b7265746e,0x09203233752e766f,0x31202c3736317225,0x2e6d6f7461090a3b\n"
".quad 0x612e6c61626f6c67,0x09203233752e6464,0x5b202c3836317225,0x202c5d3231647225\n"
".quad 0x090a3b3736317225,0x203233732e766f6d,0x202c393631722509,0x090a3b3836317225\n"
".quad 0x65726168732e7473,0x5b09203233752e64,0x6c5f616475635f5f,0x7261765f6c61636f\n"
".quad 0x345f35303636325f,0x496b636f6c625f32,0x25202c5d7865646e,0x2e090a3b39363172\n"
".quad 0x3209373109636f6c,0x646c090a30093036,0x752e6d617261702e,0x3731722509203233\n"
".quad 0x75635f5f5b202c30,0x5f5f6d7261706164,0x65646e614d36315a,0x735f31746f72626c\n"
".quad 0x507645644933316d,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x646957646972675f,0x6572090a3b5d6874,0x2509203233752e6d\n"
".quad 0x7225202c31373172,0x317225202c393631,0x2e7473090a3b3037,0x752e646572616873\n"
".quad 0x635f5f5b09203233,0x61636f6c5f616475,0x36325f7261765f6c,0x625f32345f363036\n"
".quad 0x202c5d586b636f6c,0x090a3b3137317225,0x09373109636f6c2e,0x64090a3009313632\n"
".quad 0x09203233752e7669,0x25202c3237317225,0x7225202c39363172,0x7473090a3b303731\n"
".quad 0x2e6465726168732e,0x5f5f5b0920323375,0x636f6c5f61647563,0x325f7261765f6c61\n"
".quad 0x5f30355f36303636,0x2c5d596b636f6c62,0x0a3b323731722520,0x32325f355f744c24\n"
".quad 0x2f2f200a3a303335,0x50203e706f6f6c3c,0x6c20666f20747261,0x79646f6220706f6f\n"
".quad 0x303220656e696c20,0x2064616568202c31,0x2064656c6562616c,0x38315f355f744c24\n"
".quad 0x6f6c2e090a383731,0x3436320937310963,0x2e726162090a3009,0x3b300920636e7973\n"
".quad 0x6168732e646c090a,0x203233752e646572,0x202c333731722509,0x5f616475635f5f5b\n"
".quad 0x61765f6c61636f6c,0x5f35303636325f72,0x6b636f6c625f3234,0x0a3b5d7865646e49\n"
".quad 0x746c2e7074657309,0x702509203233752e,0x37317225202c3931,0x3b35317225202c33\n"
".quad 0x203931702540090a,0x744c240920617262,0x38373138315f355f,0x5f355f744c240a3b\n"
".quad 0x090a3a3636363731,0x09373109636f6c2e,0x65090a3009373632,0x444c240a3b746978\n"
".quad 0x315a5f5f646e6557,0x626c65646e614d36,0x316d735f31746f72,0x7536507645644933\n"
".quad 0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253,0x0a3a62696969695f\n"
".quad 0x5a5f202f2f207d09,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764564493331\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x0a62696969695f30\n"
".quad 0x000000000000000a\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_13$[11981];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_13$:\n"
".quad 0x33010102464c457f,0x0000000000000002,0x0000000100be0002,0x0000000000000000\n"
".quad 0x0000000000006048,0x0000000000000040,0x00380040000d000d,0x000100210040000f\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000880\n"
".quad 0x0000000000000722,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x0000000000000fa2\n"
".quad 0x0000000000000160,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x0000000000001102\n"
".quad 0x00000000000003d8,0x0000002200000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x00000001000002c5,0x0000000000100006,0x0000000000000000,0x00000000000014da\n"
".quad 0x0000000000000cb8,0x1b00001000000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000635,0x0000000000000002,0x0000000000000000,0x0000000000002192\n"
".quad 0x0000000000000018,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000002fb,0x0000000000000002,0x0000000000000000,0x00000000000021aa\n"
".quad 0x0000000000000054,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000005fa,0x0000000000000003,0x0000000000000000,0x00000000000021fe\n"
".quad 0x0000000000000064,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000256,0x0000000000100006,0x0000000000000000,0x00000000000021fe\n"
".quad 0x0000000000000f70,0x1d00000e00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000005bc,0x0000000000000002,0x0000000000000000,0x000000000000316e\n"
".quad 0x0000000000000018,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000028c,0x0000000000000002,0x0000000000000000,0x0000000000003186\n"
".quad 0x0000000000000054,0x0000000800000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000581,0x0000000000000003,0x0000000000000000,0x00000000000031da\n"
".quad 0x0000000000000064,0x0000000800000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000001c9,0x0000000000100006,0x0000000000000000,0x00000000000031da\n"
".quad 0x0000000000000a98,0x1600000c00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000003c7,0x0000000000000002,0x0000000000000000,0x0000000000003c72\n"
".quad 0x0000000000000010,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000020e,0x0000000000000002,0x0000000000000000,0x0000000000003c82\n"
".quad 0x000000000000004c,0x0000000c00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000334,0x0000000000000003,0x0000000000000000,0x0000000000003cce\n"
".quad 0x000000000000005c,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000080000037e,0x0000000000000003,0x0000000000000000,0x0000000000003cce\n"
".quad 0x0000000000000080,0x0000000c00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000013c,0x0000000000100006,0x0000000000000000,0x0000000000003cce\n"
".quad 0x0000000000000b28,0x1d00000a00000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000004a7,0x0000000000000002,0x0000000000000000,0x00000000000047f6\n"
".quad 0x000000000000000c,0x0000001100000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000181,0x0000000000000002,0x0000000000000000,0x0000000000004802\n"
".quad 0x000000000000004c,0x0000001100000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000414,0x0000000000000003,0x0000000000000000,0x000000000000484e\n"
".quad 0x0000000000000074,0x0000001100000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000080000045e,0x0000000000000003,0x0000000000000000,0x000000000000484e\n"
".quad 0x00000000000000c0,0x0000001100000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000b9,0x0000000000100006,0x0000000000000000,0x000000000000484e\n"
".quad 0x0000000000000b58,0x1400000800000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000006b8,0x0000000000000002,0x0000000000000000,0x00000000000053a6\n"
".quad 0x0000000000000014,0x0000001600000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x00000001000000f9,0x0000000000000002,0x0000000000000000,0x00000000000053ba\n"
".quad 0x000000000000004c,0x0000001600000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000800000673,0x0000000000000003,0x0000000000000000,0x0000000000005406\n"
".quad 0x000000000000005c,0x0000001600000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000036,0x0000000000100006,0x0000000000000000,0x0000000000005406\n"
".quad 0x0000000000000bd0,0x1a00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000539,0x0000000000000002,0x0000000000000000,0x0000000000005fd6\n"
".quad 0x0000000000000010,0x0000001a00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000076,0x0000000000000002,0x0000000000000000,0x0000000000005fe6\n"
".quad 0x000000000000004c,0x0000001a00000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x00000008000004f4,0x0000000000000003,0x0000000000000000,0x0000000000006032\n"
".quad 0x0000000000000074,0x0000001a00000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0000000100000700,0x0000000000000002,0x0000000000000000,0x0000000000006032\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000000000008,0x0000000000000000\n"
".quad 0x000000090000070f,0x0000000000000000,0x0000000000000000,0x0000000000006036\n"
".quad 0x0000000000000010,0x0000001e00000003,0x0000000000000004,0x0000000000000010\n"
".quad 0x000000080000002b,0x0000000000000003,0x0000000000000000,0x0000000000006046\n"
".quad 0x0000000000000004,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x36315a5f2e747865\n"
".quad 0x72626c65646e614d,0x33316d735f31746f,0x6375365076456449,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x6e2e006269696969,0x5f2e6f666e692e76\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x5f2e747865742e00\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645664933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x666e692e766e2e00\n"
".quad 0x614d36315a5f2e6f,0x746f72626c65646e,0x664933316d735f31,0x6168637536507645\n"
".quad 0x535f546969693472,0x5f32535f32535f32,0x69695f30535f3253,0x7865742e00626969\n"
".quad 0x614d36315a5f2e74,0x746f72626c65646e,0x644933316d735f30,0x507645453631694c\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x666e692e766e2e00,0x614d36315a5f2e6f,0x746f72626c65646e,0x644933316d735f30\n"
".quad 0x507645453631694c,0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32\n"
".quad 0x62696969695f3053,0x5f2e747865742e00,0x65646e614d36315a,0x735f30746f72626c\n"
".quad 0x31694c664933316d,0x6375365076454536,0x5469696934726168,0x535f32535f32535f\n"
".quad 0x5f30535f32535f32,0x6e2e006269696969,0x5f2e6f666e692e76,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x31694c664933316d,0x6375365076454536,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x742e006269696969,0x38315a5f2e747865\n"
".quad 0x72626c65646e614d,0x6d735f315344746f,0x6168637536503331,0x6666666969693472\n"
".quad 0x69695f5366666666,0x2e766e2e00626969,0x315a5f2e6f666e69,0x626c65646e614d38\n"
".quad 0x735f315344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x65742e0062696969,0x4d38315a5f2e7478,0x6f72626c65646e61,0x316d735f30534474\n"
".quad 0x7261686375365033,0x6666666669696934,0x6969695f53666666,0x692e766e2e006269\n"
".quad 0x38315a5f2e6f666e,0x72626c65646e614d,0x6d735f305344746f,0x6168637536503331\n"
".quad 0x6666666969693472,0x69695f5366666666,0x2e766e2e00626969,0x5f2e646572616873\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x31694c664933316d,0x6375365076454536\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6e2e006269696969\n"
".quad 0x2e6c61636f6c2e76,0x646e614d36315a5f,0x5f30746f72626c65,0x694c664933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x2e0062696969695f,0x74736e6f632e766e,0x315a5f2e31746e61,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c664933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x2e766e2e00626969,0x5f2e646572616873\n"
".quad 0x65646e614d36315a,0x735f30746f72626c,0x31694c644933316d,0x6375365076454536\n"
".quad 0x5469696934726168,0x535f32535f32535f,0x5f30535f32535f32,0x6e2e006269696969\n"
".quad 0x2e6c61636f6c2e76,0x646e614d36315a5f,0x5f30746f72626c65,0x694c644933316d73\n"
".quad 0x7536507645453631,0x6969693472616863,0x5f32535f32535f54,0x30535f32535f3253\n"
".quad 0x2e0062696969695f,0x74736e6f632e766e,0x315a5f2e31746e61,0x626c65646e614d36\n"
".quad 0x316d735f30746f72,0x453631694c644933,0x6168637536507645,0x535f546969693472\n"
".quad 0x5f32535f32535f32,0x69695f30535f3253,0x2e766e2e00626969,0x5f2e646572616873\n"
".quad 0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d,0x6934726168637536\n"
".quad 0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053,0x6e6f632e766e2e00\n"
".quad 0x5f2e31746e617473,0x65646e614d36315a,0x735f31746f72626c,0x507645644933316d\n"
".quad 0x6934726168637536,0x535f32535f546969,0x5f32535f32535f32,0x62696969695f3053\n"
".quad 0x6168732e766e2e00,0x38315a5f2e646572,0x72626c65646e614d,0x6d735f315344746f\n"
".quad 0x6168637536503331,0x6666666969693472,0x69695f5366666666,0x2e766e2e00626969\n"
".quad 0x746e6174736e6f63,0x614d38315a5f2e31,0x746f72626c65646e,0x33316d735f315344\n"
".quad 0x3472616863753650,0x6666666666696969,0x696969695f536666,0x68732e766e2e0062\n"
".quad 0x315a5f2e64657261,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x766e2e0062696969,0x6e6174736e6f632e\n"
".quad 0x4d38315a5f2e3174,0x6f72626c65646e61,0x316d735f30534474,0x7261686375365033\n"
".quad 0x6666666669696934,0x6969695f53666666,0x732e766e2e006269,0x5a5f2e6465726168\n"
".quad 0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331,0x6969347261686375\n"
".quad 0x32535f32535f5469,0x535f32535f32535f,0x0062696969695f30,0x736e6f632e766e2e\n"
".quad 0x5a5f2e31746e6174,0x6c65646e614d3631,0x6d735f31746f7262,0x3650764566493331\n"
".quad 0x6969347261686375,0x32535f32535f5469,0x535f32535f32535f,0x0062696969695f30\n"
".quad 0x736e6f632e766e2e,0x2e003431746e6174,0x632e766e2e6c6572,0x31746e6174736e6f\n"
".quad 0x4d36315a5f000034,0x6f72626c65646e61,0x4933316d735f3174,0x6863753650764564\n"
".quad 0x5f54696969347261,0x32535f32535f3253,0x695f30535f32535f,0x315a5f0062696969\n"
".quad 0x626c65646e614d36,0x316d735f31746f72,0x7536507645664933,0x6969693472616863\n"
".quad 0x5f32535f32535f54,0x30535f32535f3253,0x5f0062696969695f,0x65646e614d36315a\n"
".quad 0x735f30746f72626c,0x31694c644933316d,0x6375365076454536,0x5469696934726168\n"
".quad 0x535f32535f32535f,0x5f30535f32535f32,0x5a5f006269696969,0x6c65646e614d3631\n"
".quad 0x6d735f30746f7262,0x3631694c66493331,0x6863753650764545,0x5f54696969347261\n"
".quad 0x32535f32535f3253,0x695f30535f32535f,0x315a5f0062696969,0x626c65646e614d38\n"
".quad 0x735f315344746f72,0x686375365033316d,0x6666696969347261,0x695f536666666666\n"
".quad 0x315a5f0062696969,0x626c65646e614d38,0x735f305344746f72,0x686375365033316d\n"
".quad 0x6666696969347261,0x695f536666666666,0x6f6c620062696969,0x65746e756f436b63\n"
".quad 0x0000000000000072,0x0000000000000000,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000001,0x0000000000000000,0x0003000000000000,0x0000000000000002\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000003,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000000,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000020,0x0000000000000000,0x0003000000000000,0x000000000000001a\n"
".quad 0x000000000bd00000,0x0003000000000000,0x000000000000001c,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000016,0x000000000b580000,0x0003000000000000\n"
".quad 0x0000000000000018,0x0000000000000000,0x0003000000000000,0x0000000000000011\n"
".quad 0x000000000b280000,0x0003000000000000,0x0000000000000013,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000000c,0x000000000a980000,0x0003000000000000\n"
".quad 0x000000000000000e,0x0000000000000000,0x0003000000000000,0x0000000000000008\n"
".quad 0x000000000f700000,0x0003000000000000,0x000000000000000a,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000004,0x000000000cb80000,0x0003000000000000\n"
".quad 0x0000000000000006,0x0000000000000000,0x0003000000000000,0x000000000000000f\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000010,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000000d,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000014,0x0000000000000000,0x0003000000000000,0x0000000000000015\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000012,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000001d,0x0000000000000000,0x0003000000000000\n"
".quad 0x000000000000001b,0x0000000000000000,0x0003000000000000,0x000000000000000b\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000009,0x0000000000000000\n"
".quad 0x0003000000000000,0x0000000000000007,0x0000000000000000,0x0003000000000000\n"
".quad 0x0000000000000005,0x0000000000000000,0x0003000000000000,0x0000000000000019\n"
".quad 0x0000000000000000,0x0003000000000000,0x0000000000000017,0x0000000000000000\n"
".quad 0x0003000000000000,0x000000000000001e,0x0000000000000000,0x0003000000000000\n"
".quad 0x000000000000001f,0x0000000000000000,0x1012000000010000,0x000000000000001a\n"
".quad 0x0000000000000000,0x10120000003b0000,0x0000000000000016,0x0000000000000000\n"
".quad 0x1012000000750000,0x0000000000000011,0x0000000000000000,0x1012000000b40000\n"
".quad 0x000000000000000c,0x0000000000000000,0x1012000000f30000,0x0000000000000008\n"
".quad 0x0000000000000000,0x1012000001230000,0x0000000000000004,0x0000000000000000\n"
".quad 0x0011000001530000,0x0000000000000020,0x0000000000040000,0x0780d08002050000\n"
".quad 0xc7801000f8050040,0xc7801000f8090603,0x07c0a000003d0403,0x07d0a00002410400\n"
".quad 0xc100100002050400,0xd100100002092440,0x07c0d00202452440,0x0000a00170030400\n"
".quad 0x0100100170030000,0xc780100000010000,0x0003100180052780,0x0780d70100090000\n"
".quad 0xc78010002605e0c0,0xc780100004014400,0x07802013d0030603,0xc7801000000d0000\n"
".quad 0xc780100026050403,0x878000002c014400,0xc78010000401e420,0x07802015c0030603\n"
".quad 0xc78000002e010000,0x078000003001e420,0x0002f0000001e420,0x0000861ffe03e000\n"
".quad 0xc780100028010000,0x87c83000edfd4400,0x0280300000036421,0x0780a00044290000\n"
".quad 0x0780a00042250420,0xc780100030050420,0xc78010002e014400,0x00084015040c4400\n"
".quad 0xc7806014060d4013,0x8780601202090000,0x07803010060d0000,0x078030100409c410\n"
".quad 0xc78060140405c410,0x8780601200010000,0x8048201082340000,0x07c8300dcffd200f\n"
".quad 0x02c83012cdfd6c21,0x0000a01250036c21,0x0100101250030000,0x4780a00024090000\n"
".quad 0xc780100012014401,0x4780a0001a114400,0xc780100016054401,0x0780e002de014400\n"
".quad 0x4780e004de150020,0x0780e002de050020,0x4780e004de190420,0x0a1cb041000c0421\n"
".quad 0xc780e002de09b046,0xc780e004de110820,0x760cb14172040821,0x0608b0020204b146\n"
".quad 0x7808b1017404b004,0x0a30b0010038b102,0x0780d000a805b002,0x180cb0401c002000\n"
".quad 0x87c8a40001fdb045,0x0420b040022c0c21,0x010010067003b043,0x0780e08218010000\n"
".quad 0x0043e04018010843,0x1808c00c180c0460,0xc780e0000011b040,0x0780c00818050800\n"
".quad 0x0780e00004110000,0x4780e008181d0001,0x8780e0821c050000,0x0780c00b1c190843\n"
".quad 0x0780e00004150000,0xc780e00c18110001,0x4780e0821c010001,0x8780e00b1c510840\n"
".quad 0x0854c00e1c4c0001,0x0780b0001c19b043,0x0780e00e1c050800,0xc780e00000590005\n"
".quad 0x0854b0550e1c0804,0xc780b000025db055,0x8780e0000c590804,0x0260b055060c0005\n"
".quad 0x8780e0000c55b057,0x264cb05728500005,0x4780e0020401b058,0xc780b0000e090001\n"
".quad 0x4780e0060c0d0000,0x0000b01328140005,0x4780b0000609b002,0x0780e00810010001\n"
".quad 0x8780e00b160d0000,0x0258b000084c0000,0x2c04b0442608b003,0x0654b0420050b041\n"
".quad 0xfc041100fa00b041,0xc7801000f8111100,0xc7801000f8150403,0x98081000900c0603\n"
".quad 0x9c181000961c1002,0x0780100710031002,0xc7801000f8550000,0xc7801000f8590403\n"
".quad 0xc7801000f8510603,0xc7801000f84d0403,0xc7801000f81d0603,0xc7801000f8190403\n"
".quad 0xc7801000f80d0603,0xc7801000f8090403,0x9010100098040603,0x961410009c001002\n"
".quad 0x87c83081d1fd1002,0xffff213ff0316c60,0x0280100d40030fff,0x102cb0132c200000\n"
".quad 0x262cb04b1038b056,0x162cb04e2c38b04b,0x162cb015162cb00e,0x1c20b00b1038b014\n"
".quad 0x1c20b0481620b048,0x47c8b08311fdb008,0x0000a00d30036040,0x0100100d30030000\n"
".quad 0x8780e0820c2d0000,0x8780e08204210841,0x0043e0400c2d0840,0x0043e04004210460\n"
".quad 0x0000400d30030460,0x9038b00696640000,0x0780c007045db002,0xc780e0030c610000\n"
".quad 0x0780e0020c5d0005,0x0780c0020c690006,0xc780e0020c190000,0x8780e00b10090405\n"
".quad 0x8780e00b1c090806,0x2e18b046302c0000,0x8780b0003419b046,0x8780e00832090801\n"
".quad 0x8780e00e32210000,0x0408b00616080000,0x8780e007060db008,0x0c08b0032e180000\n"
".quad 0x0420b046041cb006,0x0c1cb0570c2cb047,0x0620b0480c18b047,0x060cb0060e0cb04b\n"
".quad 0x042cb008061cb008,0x160cb0532c18b007,0x0620b0560c38b001,0x2660b04e0c5cb04b\n"
".quad 0x2c58b0480638b00e,0x162cb042164cb057,0x2c20b0480208b04e,0x0408b0530e1cb058\n"
".quad 0x0408b0151020b00b,0x0420b054102cb007,0x0608b00b0c38b004,0x040cb0001c1cb008\n"
".quad 0x100cb04e0e4cb043,0x0450b0530e20b043,0x1c38b0461c58c003,0x8780e0820421b048\n"
".quad 0x0780e00304190840,0x044cb05300540005,0x0043e0400421c002,0x8780e00204510460\n"
".quad 0x1c2cb05616580001,0xc780e0081055b015,0x0438b053285c0804,0x2860b016162cb048\n"
".quad 0x4780e00e1055b057,0x0c58b00b0a2c0005,0x0780b000265db057,0x4780e00e104d0806\n"
".quad 0x2c54b00b0e180005,0xc780e00e1c4db017,0x264cb0470c1c0004,0xc780b000161db015\n"
".quad 0xc780e003062d0801,0x284cc0070c540004,0x4780e0070c5db00b,0x2650c0060c580005\n"
".quad 0xc780e0060c55b054,0x2a2cb05416500005,0x2a2cb04b2e5cb056,0x2e5cb04b2c2cb04b\n"
".quad 0x8780e0820c2db00b,0x0043e0400c2d0841,0x8780e00b16590460,0xc780b0000c650805\n"
".quad 0x8780e01916590802,0x8780e01916590005,0x8780e01932590005,0xc780b0002c590005\n"
".quad 0x8780e0070e5d0005,0x2c54b0172a580005,0x265cb0552e54b055,0x2e68b017ac60b016\n"
".quad 0x2c68b0582660b058,0x2a60b01a3060b05a,0x2e60b0182868b018,0x345cb057305cb01a\n"
".quad 0x07c021001831b057,0x0100500000030441,0x0780b0002e5d0000,0x47c8b0832ffd0006\n"
".quad 0x0280100830036040,0x0780500000030000,0x0002f00000010000,0x0780307c1805e000\n"
".quad 0x07802040d0016c01,0x0780d00100010423,0x87c8307c01fd0400,0x0000a00ee0036c00\n"
".quad 0x0280100eb0030000,0x0780d00080050000,0x07802000e4012000,0x8780a40000090420\n"
".quad 0x8780a40002190020,0x8780a400041d0020,0x0210400202080020,0x0780400702154006\n"
".quad 0x0780301004090000,0x078030100811c410,0x078030100a15c410,0x878060020005c410\n"
".quad 0x0780600600090000,0x4780600700010001,0xc780a000020d0001,0xc780a00004150400\n"
".quad 0xc780a00000110400,0x0780100ee0030400,0xc7801000f8110000,0xc7801000f8150403\n"
".quad 0xc7801000f80d0603,0xc78210000c010403,0x0780401b00054400,0x4780601a02050000\n"
".quad 0x0780301002050000,0x4780601a0001c410,0x8780200000010000,0x0780300200010404\n"
".quad 0x47c8307ce3fdc410,0x07802000c81d6c21,0x0280101010030420,0x0003100000050000\n"
".quad 0x14001002100c0000,0xc78010000c091000,0x0780d08500090203,0x0780d08502010440\n"
".quad 0x0780300804050440,0x4780d0010001c410,0x0780d00e0e010400,0x078010125003a0c0\n"
".quad 0x0780d00e0e190000,0xc7801000220580c0,0x8780a00018594400,0x47802100e2090000\n"
".quad 0x0780401606210460,0x0780301f04010000,0x078030101031ec10,0x0780d0810021c410\n"
".quad 0x078030080c010440,0x07806016042de410,0x8780200010210003,0x8780a00000310400\n"
".quad 0xc780200016010000,0x0780300110210400,0x840c400c062cec10,0x0780200010011000\n"
".quad 0x07803010164d0400,0x078020176003c410,0x8780a0001a590000,0xc780600c040d0000\n"
".quad 0x0630100280180004,0x840c200586004016,0x0780301018151000,0x078020001001c410\n"
".quad 0x4780601604050400,0x0780201760030001,0x80042004820c0000,0xc780a0000c0d1002\n"
".quad 0xc780200010010000,0x0780300804090400,0xc7801000040dc010,0x0780201760030403\n"
".quad 0x4780d00206090000,0x0780d00e0e050000,0x000320028e05a040,0x0780d00e02010000\n"
".quad 0x0002f0000001a000,0x0000861ffe03e000,0x87c8307c23fd0000,0x0000a01370036c00\n"
".quad 0x0280101370030000,0xc780100000010000,0x0003100180052780,0x0780d70100090000\n"
".quad 0xc78010002605e0c0,0xc780100004014400,0x07802013d0030603,0xc7801000000d0000\n"
".quad 0xc780100026050403,0x878000002c014400,0xc78010000401e420,0x07802015c0030403\n"
".quad 0xc78000002e010000,0x078000003001e420,0x0002f0000001e420,0x0000861ffe03e000\n"
".quad 0xc780100028010000,0x47c83000edfd4400,0x02801001e0036420,0x0780300000030000\n"
".quad 0x4780a000020d0000,0x0780900006114400,0x4780a000000d0000,0xffff203e88114406\n"
".quad 0xc7c0c004060d0fff,0x4780a000060d0000,0x078040030c158406,0x478060020e150000\n"
".quad 0x078030100a150001,0x478060020c15c410,0x4780204000150001,0x4780a0000a150401\n"
".quad 0xc7c0c0040a114406,0x4780a00008110000,0x07802000060d8406,0x078040030c110401\n"
".quad 0x078060020e110000,0x0780301008110001,0x078060020c11c410,0x0780300008110001\n"
".quad 0xc780300402110400,0xc7803000080d6400,0x078040030c110400,0x078060020e110000\n"
".quad 0x0780301008110001,0x078060020c0dc410,0x0780300006010001,0x47c8307c03fd0400\n"
".quad 0xc500d00100016401,0x0780300000030402,0x0000f00000010000,0x4780a0000209e000\n"
".quad 0x0780900004114400,0x4780a00000090000,0xffff203e88114406,0xc7c0c00404090fff\n"
".quad 0x4780a00004090000,0x0780400308158406,0x478060020a150000,0x078030100a150001\n"
".quad 0x478060020815c410,0x4780204000150001,0x4780a0000a150401,0xc7c0c0040a114406\n"
".quad 0x4780a00008110000,0x0780200004098406,0x0780400308110401,0x078060020a110000\n"
".quad 0x0780301008110001,0x078060020811c410,0x0780300008010001,0xc780300002010400\n"
".quad 0x8780300000016400,0x47c8307c03fd0400,0xc500d00100016401,0x0780300000030402\n"
".quad 0x0000f00000010000,0x4780a000062de000,0x4780a00016310411,0x4780a00000354400\n"
".quad 0x0780900018390411,0x4780a0001a310000,0xffff203e9c394406,0xc7c0c00e18310fff\n"
".quad 0x4780a00018310000,0x078040192c498406,0x878060182e490000,0x0780301024490004\n"
".quad 0x878060182c49c410,0x878020401a490004,0x4780a00024490404,0xc7c0c00e24394406\n"
".quad 0x4780a0001c390000,0x8780200018318406,0x0780401632390403,0x8780601730390000\n"
".quad 0x078030101c390003,0x878060163039c410,0x478030001c350003,0xc780300d162d0403\n"
".quad 0x8780d00006016400,0x0780301f00010400,0x078030001631e410,0x4780a000002d0403\n"
".quad 0x8780d00c162d2c01,0x47c8307c07fd0400,0xc780200000016c01,0xc500d00300010402\n"
".quad 0x0780300000030402,0x0001f00000010000,0x0001000003ffe000,0x0000460004000000\n"
".quad 0x00ffffffffff4080,0x000000440b0400ff,0x000c000000080000,0x0014000000100000\n"
".quad 0x001c000000180000,0x0024000000200000,0x002c000000280000,0x0034000000300000\n"
".quad 0x003c000000380000,0x0044000000400000,0x011800080d040000,0x0205000000200023\n"
".quad 0xf80500400780d080,0xf8090603c7801000,0x00450403c7801000,0x0249040007c0a000\n"
".quad 0x0205040007d0a000,0x02092440c1001000,0x024d2440d1001000,0x7003040007c0d002\n"
".quad 0x700300000000a001,0x0001000001001001,0x80052780c7801000,0x0009000000031001\n"
".quad 0x2605e0c00780d701,0x04014400c7801000,0x40030603c7801000,0x000d000007802019\n"
".quad 0x26050403c7801000,0x2c014400c7801000,0x0401e42087800000,0x30030603c7801000\n"
".quad 0x2e0100000780201b,0x3001e420c7800000,0x0001e42007800000,0xfe03e0000002f000\n"
".quad 0x280100000000861f,0xedfd4400c7801000,0x0003642187c83000,0x4431000002803000\n"
".quad 0x422d04200780a000,0x300504200780a000,0x2e014400c7801000,0x040c4400c7801000\n"
".quad 0x060d401700084019,0x02090000c7806018,0x060d000087806016,0x0409c41007803010\n"
".quad 0x0405c41007803010,0x00010000c7806018,0x8204000087806016,0xcffd201180082012\n"
".quad 0xcdfd6c2107c83001,0xc0036c2102c83002,0xc00300000000a017,0x0c01000001001017\n"
".quad 0x000d4400c7801000,0x020d000007804003,0x060d0000c7806002,0x0001c41007803010\n"
".quad 0x00010000c7806002,0x000d040087802000,0xc851c41007803002,0x280d0420c7802000\n"
".quad 0x061180c00780d00e,0x05fde41007803008,0xf0036c00c7c8307c,0x0c3900000000a004\n"
".quad 0x0e3504008780a000,0x103d04008780a000,0xe00304008780a000,0xa80d000002801004\n"
".quad 0x060d0fffffff203c,0x061180c00780d00e,0x0c15e41007803008,0x101104008780a000\n"
".quad 0x8a1404008780a000,0x0e0d204f8818204e,0x0a1104008780a000,0x0c1504114780a000\n"
".quad 0x060d04114780a000,0x0811040347802040,0x0a156c4107803082,0x060d6c4107803082\n"
".quad 0x081104114780a000,0x060d04004780d005,0x060d6c4107803082,0x061104004780d004\n"
".quad 0xf0032c014780a000,0xf811000007801004,0x00010403c7801000,0x6003e0000002f000\n"
".quad 0x840d00000000a006,0xcdfd000000032001,0x60036c20c7c83003,0xa80d000002801006\n"
".quad 0x060d000000032004,0x061580c00780d00e,0x0c19e41007803008,0x141504008780a000\n"
".quad 0x8c1804008780a000,0x0e0d204f8a1c204e,0x0c1504008780a000,0x0e1904114780a000\n"
".quad 0x060d04114780a000,0x0a15040347802040,0x0c196c4107803082,0x060d6c4107803082\n"
".quad 0x0a1504114780a000,0x060d04004780d006,0x060d6c4107803082,0x060d04004780d005\n"
".quad 0x08112c014780a000,0x03fd0400c7802000,0xd0036c00c7ca307c,0xd00300000000a007\n"
".quad 0xcc0d000002801007,0x060d042007803000,0xc80dc41007803002,0x060d0420c7802000\n"
".quad 0x061980c00780d00e,0x0c15e41007803008,0x181904008780a000,0x8a1404008780a000\n"
".quad 0x0e0d204f8c18204e,0x0a1504008780a000,0x0c1904114780a000,0x060d04114780a000\n"
".quad 0x0a15040347802040,0x0c196c4107803082,0x060d6c4107803082,0x0a1504114780a000\n"
".quad 0x060d04004780d006,0x060d6c4107803082,0x060d04004780d005,0x08112c014780a000\n"
".quad 0x00010400c7802000,0x6003e0000002f000,0x820d00000000a009,0xcffd000000032001\n"
".quad 0x60036c20c7c83003,0xcc01000002801009,0x0001042007802000,0xc801c41007803002\n"
".quad 0x0001042007802000,0x001580c00780d00e,0x000de41007803008,0x141504008780a000\n"
".quad 0x860c04008780a000,0x0201204f8a14204e,0x060d04008780a000,0x0a1504114780a000\n"
".quad 0x000104114780a000,0x060d040347802040,0x0a156c4107803082,0x00016c4107803082\n"
".quad 0x060d04114780a000,0x000104004780d005,0x00016c4107803082,0x000104004780d003\n"
".quad 0x08112c014780a000,0x09fd040007802000,0xc0036c0087ca307c,0x0409000002801017\n"
".quad 0x021144014780a000,0xf20044014780a000,0xde011100f6041100,0xde1500200780e002\n"
".quad 0xde0500204780e004,0xde1904200780e002,0x000c04214780e004,0xde09b0460a1cb041\n"
".quad 0xde110820c780e002,0x72040821c780e004,0x0204b146760cb141,0x7404b0040608b002\n"
".quad 0x0028b1027808b101,0xa805b0020a24b001,0x140020000780d000,0x01fdb045120cb040\n"
".quad 0x02200c2187c8a400,0x3003b0430440b040,0x120100000100100d,0x121408424780e083\n"
".quad 0x1409c0101210c009,0x140d08428780e083,0x120500000780c00a,0x141908400780e083\n"
".quad 0x125900000780c008,0x140100010780e010,0x121d08408780e083,0x021108004780b000\n"
".quad 0x145508014780e001,0x120900018780e008,0x141900058780e009,0x0e5d08000780b000\n"
".quad 0x141100010780e001,0x046100054780e00a,0x006508014780b000,0x0e050800c780e000\n"
".quad 0x08680005c780e001,0x0c65b058045cb043,0x2c5800064780e000,0x0a15b05a0860b058\n"
".quad 0x0c5d0805c780b000,0x2a5400064780e000,0x0e01b0580660b05a,0x2c0500004780e007\n"
".quad 0x0c0d00014780b000,0x2a140005c780e006,0x0605b0010000b018,0x200100014780b000\n"
".quad 0x100d00000780e010,0x045800004780e008,0x2c04b0030854b000,0x005cb0442a08b042\n"
".quad 0xfa00b0420660b041,0xf8151100fc041100,0xf8190603c7801000,0xa00c0403c7801000\n"
".quad 0x901c100092081002,0xd003100094101002,0xf86100000780100d,0xf8550603c7801000\n"
".quad 0xf85d0403c7801000,0xf8590603c7801000,0xf81d0403c7801000,0xf8110603c7801000\n"
".quad 0xf80d0403c7801000,0xf8090603c7801000,0x92040403c7801000,0x94001000a0141002\n"
".quad 0xd1fd100090181002,0xf0296c6087c83081,0x00030fffffff213f,0x2a20000002801014\n"
".quad 0x1040b0551024b016,0x2a40b0492c24b049,0x1224b0101224b050,0x1040b0171224b018\n"
".quad 0x1220b0482020b009,0x11fdb0082020b048,0xf003604047c8b084,0xf00300000000a013\n"
".quad 0x0821000001001013,0x042508410780e083,0x082108408780e083,0x042504600043e040\n"
".quad 0xf00304600043e040,0x9064000000004013,0x0469b0029240b004,0x087100000780c007\n"
".quad 0x086900068780e003,0x086d00070780e002,0x080900000780c002,0x121104068780e002\n"
".quad 0x20210806c780e008,0x381000010780e008,0x3221b0423408b042,0x360900020780e009\n"
".quad 0x322108008780b000,0x080800020780e010,0x0611b0080408b002,0x340c00008780e007\n"
".quad 0x041cb0030608b004,0x0624b0470420b043,0x0620b047061cb05a,0x0824b0562a0cb048\n"
".quad 0x0620b0080e10b049,0x0640b0090810b055,0x2c20b009081cb048,0x0440b0502a10b008\n"
".quad 0x2010b0480820b007,0x0854b0181020b001,0x0858b0571020b050,0x205cb0080624b055\n"
".quad 0x0208b0562058b042,0x0e1cb0001240b055,0x2054b0160408b057,0x201cb0070408b049\n"
".quad 0x040cb0431258b055,0x0024b047121cb005,0x1020b0030808b055,0x0410b0090e1cb056\n"
".quad 0x060cb0080e1cb044,0x0420b0070c1cb044,0x0459b0072010c003,0x042500020780e003\n"
".quad 0x084008408780e083,0x0455c0020420b050,0x042500058780e002,0x0e1c04600043e040\n"
".quad 0x125db0482a60b050,0x044008020780e009,0x2a68c007086cb049,0x1261b0582c64b058\n"
".quad 0x08590005c780e010,0x10680006c780e007,0x1221c004085cb05a,0x086100060780e010\n"
".quad 0x326900058780e004,0x206500068780b000,0x306d00020780e010,0x08210805c780b000\n"
".quad 0x326808410780e083,0x0821b05b3064b01a,0x2c6c04600043e040,0x1059b0592e70b05b\n"
".quad 0x08650805c780e008,0x105908020780b000,0x105900058780e019,0x366d00058780e019\n"
".quad 0x325900070780b000,0x065d00058780e019,0x2c6800068780e003,0x0e6db0172a58b01b\n"
".quad 0x2c6800068780e007,0x2e5cb01b3054b055,0x2c68b0582a60b05a,0xaa6cb0583660b015\n"
".quad 0x2c6cb05b3470b01a,0x366cb05c2a70b05b,0x2e70b01b306cb01c,0x3668b01c346cb01b\n"
".quad 0x1429b05a3868b05a,0x0003044147c02100,0x3469000001005000,0x35fd0006c780b000\n"
".quad 0xf003604047c8b084,0x000300000280100e,0x0001000007805000,0x1405e0000002f000\n"
".quad 0xd0016c010780307c,0x0001042287802040,0x01fd04000780d001,0xa0036c0087c8307c\n"
".quad 0x700300000000a015,0x8005000002801015,0xe40120000780d000,0x0009042007802000\n"
".quad 0x021900208780a400,0x041d00208780a400,0x020800208780a400,0x0215400602104002\n"
".quad 0x0409000007804007,0x0811c41007803010,0x0a15c41007803010,0x0005c41007803010\n"
".quad 0x0009000087806002,0x000d000107806006,0x0201000147806007,0x04150400c780a000\n"
".quad 0x06190400c780a000,0xa0030400c780a000,0xf819000007801015,0xf8150603c7801000\n"
".quad 0xf8010403c7801000,0x22050603c7801000,0x040d4400c7821000,0xe20900000780401d\n"
".quad 0x0611046047802100,0x040d0000c780601c,0x0811ec100780301f,0x060dc41007803010\n"
".quad 0x041104400780d081,0x860c00010780601c,0x0801401f04202002,0x061d040007802000\n"
".quad 0x0611ec1007803001,0x840c00020780601e,0x081120008e001000,0xd003c41007803010\n"
".quad 0x042100000780201c,0x040d00000780401b,0x001100010780601e,0x06210603c7801000\n"
".quad 0x860000020780601a,0x10151000840c2005,0x0e01c41007803010,0x0405040007802000\n"
".quad 0xd00300014780601a,0x820c00000780201c,0x080d100280042006,0x0e010000c780a000\n"
".quad 0x04090400c7802000,0x040dc01007803008,0xd0030403c7801000,0x060900000780201c\n"
".quad 0x280500004780d002,0xa805a0400780d00e,0x0201000000032002,0x0001a0000780d00e\n"
".quad 0xfe03e0000002f000,0x27fd00000000861f,0xe0036c0087c8307c,0xe00300000000a018\n"
".quad 0x0001000002801018,0x80052780c7801000,0x0009000000031001,0x2605e0c00780d701\n"
".quad 0x04014400c7801000,0x40030603c7801000,0x000d000007802019,0x26050403c7801000\n"
".quad 0x2c014400c7801000,0x0401e42087800000,0x30030403c7801000,0x2e0100000780201b\n"
".quad 0x3001e420c7800000,0x0001e42007800000,0xfe03e0000002f000,0x280100000000861f\n"
".quad 0xedfd4400c7801000,0xe003642047c83000,0x0003000002801001,0x020d000007803000\n"
".quad 0x061144004780a000,0x000d000007809000,0x881144064780a000,0x060d0fffffff203e\n"
".quad 0x060d0000c7c0c004,0x0c1584064780a000,0x0e15000007804003,0x0a15000147806002\n"
".quad 0x0c15c41007803010,0x0015000147806002,0x0a15040147802040,0x0a1144064780a000\n"
".quad 0x08110000c7c0c004,0x060d84064780a000,0x0c11040107802000,0x0e11000007804003\n"
".quad 0x0811000107806002,0x0c11c41007803010,0x0811000107806002,0x0211040007803000\n"
".quad 0x080d6400c7803004,0x0c110400c7803000,0x0e11000007804003,0x0811000107806002\n"
".quad 0x0c0dc41007803010,0x0601000107806002,0x03fd040007803000,0x0001640147c8307c\n"
".quad 0x00030402c500d001,0x0001000007803000,0x0209e0000000f000,0x041144004780a000\n"
".quad 0x0009000007809000,0x881144064780a000,0x04090fffffff203e,0x04090000c7c0c004\n"
".quad 0x081584064780a000,0x0a15000007804003,0x0a15000147806002,0x0815c41007803010\n"
".quad 0x0015000147806002,0x0a15040147802040,0x0a1144064780a000,0x08110000c7c0c004\n"
".quad 0x040984064780a000,0x0811040107802000,0x0a11000007804003,0x0811000107806002\n"
".quad 0x0811c41007803010,0x0801000107806002,0x0201040007803000,0x00016400c7803000\n"
".quad 0x03fd040087803000,0x0001640147c8307c,0x00030402c500d001,0x0001000007803000\n"
".quad 0x0621e0000000f000,0x102504114780a000,0x002944004780a000,0x123904114780a000\n"
".quad 0x1425000007809000,0x9c3944064780a000,0x12250fffffff203e,0x12250000c7c0c00e\n"
".quad 0x204184064780a000,0x2241000007804013,0x2041000407806012,0x2041c41007803010\n"
".quad 0x1441000407806012,0x2041040407802040,0x203944064780a000,0x1c390000c7c0c00e\n"
".quad 0x122584064780a000,0x2639040387802000,0x2439000007804010,0x1c39000387806011\n"
".quad 0x2439c41007803010,0x1c29000387806010,0x1021040287803000,0x06016400c780300a\n"
".quad 0x000104008780d000,0x1025e4100780301f,0x0021040247803000,0x10212c014780a000\n"
".quad 0x07fd04008780d009,0x00016c0147c8307c,0x0001040207802000,0x00030402c500d003\n"
".quad 0x0001000007803000,0x03ffe0000001f000,0x000a000000010000,0x0000460004000000\n"
".quad 0x0b04ffffffff4080,0x0008000000000044,0x00100000000c0000,0x0018000000140000\n"
".quad 0x00200000001c0000,0x0028000000240000,0x00300000002c0000,0x0038000000340000\n"
".quad 0x00400000003c0000,0x0d04000000440000,0x0020002301180008,0x0780d08002050000\n"
".quad 0xc7801000f8050040,0xc7801000f8090603,0x07c0a00000250403,0x07d0a00002290400\n"
".quad 0xc100100002050400,0xd100100002092440,0x07c0d002022d2440,0x0000a00170030400\n"
".quad 0x0100100170030000,0xc780100000010000,0x0003100180052780,0x0780d70100090000\n"
".quad 0xc78010002205e0c0,0xc780100004014400,0x0780200f90030603,0xc7801000000d0000\n"
".quad 0xc780100022050403,0x8780000028014400,0xc78010000401e420,0x0780201180030603\n"
".quad 0xc78000002a010000,0x078000002c01e420,0x0002f0000001e420,0x0000861ffe03e000\n"
".quad 0xc780100024010000,0x87c83000e9fd4400,0x0280300000036421,0x0780a00044150000\n"
".quad 0x0780a00042110420,0xc78010002a050420,0x0780400904014400,0x0780600806010000\n"
".quad 0x0780301000090000,0xc78010002c01c410,0x8780600804054400,0x820c400b00080000\n"
".quad 0x8780600a02092009,0x0780300406390000,0x078030100409c410,0x000320109c0dc410\n"
".quad 0x8780600a00010000,0x0780300ecc190000,0x07803003cc09ac20,0x8434200a801cac20\n"
".quad 0x07803007ce092046,0x07c0307c1a016c21,0x4780a00004096c01,0x0780d08100012c01\n"
".quad 0x07d8d00201fd0440,0x0000a00e10030400,0x1100100e10030000,0x0000a00440030000\n"
".quad 0x0100100440030000,0x0780300402090000,0x078030041205c410,0x000710008001c410\n"
".quad 0x8780200002050000,0x0780000000050400,0x478020000209c000,0x4780a000020d0403\n"
".quad 0xc780100012014401,0x0780e003da014400,0x0003200182050020,0x0780d40000010000\n"
".quad 0x47d8300203fd60c0,0x0780d40008056c01,0x12801003c0032000,0x0782d00080210000\n"
".quad 0x0780d000980540c0,0x4780a0000e092000,0x87e0a40000054401,0xc780100014010c21\n"
".quad 0x47d8307c03fd4400,0x0780e002da016c01,0xc780100010190020,0x2500100510034400\n"
".quad 0xf8081100f6040000,0x103c100080301100,0x900cc0000040c008,0x0780100570031002\n"
".quad 0xc780100000090000,0xc7801000f83d0403,0xc7801000f8410603,0xc7801000f80d0403\n"
".quad 0xc7801000f8310603,0xc780100010050403,0x87e8307c1bfd0603,0x0000a00830036c00\n"
".quad 0x2280100830030000,0xc7801000f8210000,0xc7801000f8450403,0x00004007a0030603\n"
".quad 0xffff203f8c190000,0xc7e8307c0dfd0fff,0x0000a00640036c00,0x2280100640030000\n"
".quad 0x0780b0001e490000,0x07e8b08225fd0004,0x2100500000036041,0x0782000222050000\n"
".quad 0x00032001a245c000,0x87e830111bfd0000,0x0780d40000196c00,0x22801007800360c0\n"
".quad 0x0780000222050000,0x0780d4008019c000,0x11001007000340c0,0xf8081100f6040000\n"
".quad 0x0c3c100080301100,0x8c0cc0000040c006,0x0780100760031002,0xc780100000090000\n"
".quad 0xc7801000f83d0403,0xc7801000f8410603,0xc7801000f80d0403,0xc7801000f8310603\n"
".quad 0xc78010000c050403,0xc780100010190603,0x0780500000034400,0x0003100180210000\n"
".quad 0x0780500000030000,0x47e8307c11fd0000,0x2280100830036c01,0x1e3cc00c060c0000\n"
".quad 0x020cb0030630b050,0x0780b0000431b00f,0x47e830111bfd0003,0x1840c003063c6c01\n"
".quad 0x250010078003c00c,0x07801005c0030000,0x0002f00000010000,0x0100100e1003e000\n"
".quad 0xc78010000c010000,0x0780400f00054400,0x4780600e02050000,0x0780301002050000\n"
".quad 0x4780600e0001c410,0x8780200000310000,0x0780300218010403,0x07800000f805c410\n"
".quad 0x87c8307cdffdc000,0xe834200d98386c20,0x0780d40000012100,0xc7d8307c01fd40c0\n"
".quad 0x15002040d0016c00,0xd2801000f8010420,0x87d8307c01fd0403,0x0000a00ac0036c00\n"
".quad 0x0780d40000010000,0x1280100a900360c0,0x0780d00070090000,0x07802000e0012000\n"
".quad 0x8780a80000090420,0x8780a80002190020,0x8780a800041d0020,0x0218400202080020\n"
".quad 0x07804007021d4006,0x0780301004090000,0x078030100c19c410,0x078030100e1dc410\n"
".quad 0x878060020005c410,0x8780600600090000,0xc7806007000d0001,0x0780d40000010001\n"
".quad 0xc780a000020160c0,0xc780a000041d0400,0xc780a00006190400,0x0780100ac0030400\n"
".quad 0xc7801000f8190000,0xc7801000f81d0603,0xc7801000f8010403,0x0002f00000010603\n"
".quad 0x0100100b7003e000,0xc780100018050000,0x00031000000d0003,0xc78010001c090000\n"
".quad 0x0780d08302050203,0x0780d08300010440,0x0780300802050440,0x4780d0010001c410\n"
".quad 0x0780d00e1a010400,0x0780100dc003a0c0,0x0780d00e1a210000,0xc78010001e0580c0\n"
".quad 0x8780a00020814400,0x00032101fe090000,0x07803008100d0000,0x078040200645e410\n"
".quad 0x0780301f043d0000,0x8780a0000c19ec10,0x0780301022450000,0x0780d0811e3dc410\n"
".quad 0x0780400606490440,0x4780602004410000,0x878020001e3d0004,0x0780301024450400\n"
".quad 0x078020002001c410,0x078030011e3d0400,0x478060060441ec10,0x9e001000840c0004\n"
".quad 0xc780200020552000,0x0780201320030401,0x840c1002801c0000,0x478020001e011000\n"
".quad 0xc780a0000e390405,0x0780201320030000,0x8780a00022190000,0x0780400606210000\n"
".quad 0x0780301010210000,0x078060060405c410,0x80042006820c0002,0xc78020001e011002\n"
".quad 0x0780300804090400,0xc7801000040dc010,0x0780201320030403,0x4780d0021c090000\n"
".quad 0x0780d00e1a050000,0x000320029a05a040,0x0780d00e02010000,0x000320019831a000\n"
".quad 0x47d8300e19fd0000,0x0780d40008056c01,0x000320049a352000,0x12801008f0030000\n"
".quad 0x0002f00000010000,0x0000861ffe03e000,0x87c8307c17fd0000,0x0000a00f30036c00\n"
".quad 0x0280100f30030000,0xc780100000010000,0x0003100180052780,0x0780d70100090000\n"
".quad 0xc78010002205e0c0,0xc780100004014400,0x0780200f90030603,0xc7801000000d0000\n"
".quad 0xc780100022050403,0x8780000028014400,0xc78010000401e420,0x0780201180030403\n"
".quad 0xc78000002a010000,0x078000002c01e420,0x0002f0000001e420,0x0000861ffe03e000\n"
".quad 0xc780100024010000,0x47c83000e9fd4400,0x02801001e0036420,0x0780300000030000\n"
".quad 0x4780a000020d0000,0x0780900006194400,0x4780a000000d0000,0xffff203e8c194406\n"
".quad 0xc7c0c006060d0fff,0x4780a000060d0000,0x078040030c1d8406,0xc78060020e1d0000\n"
".quad 0x078030100e1d0001,0xc78060020c1dc410,0xc7802040001d0001,0x4780a0000e1d0401\n"
".quad 0xc7c0c0060e194406,0x4780a0000c190000,0x87802000060d8406,0x078040030c190401\n"
".quad 0x878060020e190000,0x078030100c190001,0x878060020c19c410,0x078030000c190001\n"
".quad 0xc780300602190400,0xc78030000c0d6400,0x078040030c190400,0x878060020e190000\n"
".quad 0x078030100c190001,0x878060020c0dc410,0x0780300006010001,0x47c8307c03fd0400\n"
".quad 0xc500d00100016401,0x0780300000030402,0x0000f00000010000,0x4780a0000209e000\n"
".quad 0x0780900004194400,0x4780a00000090000,0xffff203e8c194406,0xc7c0c00604090fff\n"
".quad 0x4780a00004090000,0x07804003081d8406,0xc78060020a1d0000,0x078030100e1d0001\n"
".quad 0xc7806002081dc410,0xc7802040001d0001,0x4780a0000e1d0401,0xc7c0c0060e194406\n"
".quad 0x4780a0000c190000,0x8780200004098406,0x0780400308190401,0x878060020a190000\n"
".quad 0x078030100c190001,0x878060020819c410,0x078030000c010001,0xc780300002010400\n"
".quad 0x8780300000016400,0x47c8307c03fd0400,0xc500d00100016401,0x0780300000030402\n"
".quad 0x0000f00000010000,0x4780a0000641e000,0x4780a00020450411,0x4780a00000494400\n"
".quad 0x07809000224d0411,0x4780a00024450000,0xffff203ea64d4406,0xc7d0c01322450fff\n"
".quad 0x4780a00022450000,0x0780402340518406,0x0780602242510000,0x0780301028510005\n"
".quad 0x078060224051c410,0x0780204024510005,0x4780a00028510405,0xc7d0c013284d4406\n"
".quad 0x4780a000264d0000,0xc780200022458406,0x07804020464d0404,0xc7806021444d0000\n"
".quad 0x07803010264d0004,0xc7806020444dc410,0x8780300026490004,0xc780301220410404\n"
".quad 0x8780d00006016400,0x0780301f00010400,0x478030002045e410,0x4780a00000410404\n"
".quad 0x8780d01120412c01,0x47d8307c07fd0400,0x0780200000016c01,0xd500d00300010404\n"
".quad 0x1780300000030402,0x0001f00000010000,0x0001000003ffe000,0x00ff408000000000\n"
".quad 0x0000003c0b0400ff,0x000c000000080000,0x0014000000100000,0x001c000000180000\n"
".quad 0x0024000000200000,0x002c000000280000,0x0034000000300000,0x003c000000380000\n"
".quad 0x012000080d040000,0x0205000000200024,0xf80500400780d080,0xf8090603c7801000\n"
".quad 0x003d0403c7801000,0x0259040007c0a000,0x0205040007d0a000,0x02092440c1001000\n"
".quad 0x025d2440d1001000,0x7003040007c0d002,0x700300000000a001,0x0001000001001001\n"
".quad 0x80052780c7801000,0x0009000000031001,0x2e05e0c00780d701,0x04014400c7801000\n"
".quad 0xb0030603c7801000,0x000d000007802010,0x2e050403c7801000,0x34014400c7801000\n"
".quad 0x0401e42087800000,0xa0030603c7801000,0x3601000007802012,0x3801e420c7800000\n"
".quad 0x0001e42007800000,0xfe03e0000002f000,0x300100000000861f,0xf5fd4400c7801000\n"
".quad 0x0003642187c83000,0x4435000002803000,0x423104200780a000,0x360104200780a000\n"
".quad 0x00054400c7801000,0x0205000007804019,0x0209000047806018,0x3805c41007803010\n"
".quad 0x00014400c7801000,0x0408000087806018,0x0609200f800c401b,0x066100008780601a\n"
".quad 0x0409c41007803004,0xb00dc41007803010,0x0405000000032010,0xcc1100008780601a\n"
".quad 0xcc09ac2007803018,0x8238ac2007803003,0xce09204484642016,0x32056c210780300e\n"
".quad 0x04096c0107c0307c,0x02052c014780a000,0x03fd04400780d081,0x3003040007d8d002\n"
".quad 0x300300000000a00f,0x900300001100100f,0x700300000000a004,0x0009000001001004\n"
".quad 0x1e05c41007803004,0x8001c41007803004,0x0211000000071000,0x0005040087802000\n"
".quad 0x0815c00007800000,0x0819040647802000,0x240144410780a000,0x26054400c7801000\n"
".quad 0xf4084400c7801000,0x00091100f60c1100,0x881140008780e006,0x0009000000032001\n"
".quad 0x09fd60800780d400,0x10056c0147d83005,0xc00320000780d400,0x9003000012801003\n"
".quad 0x2401000007801004,0x26054400c7801000,0x80494400c7801000,0xc80540800782d000\n"
".quad 0x1c1920000780d000,0x001144410780a000,0xf8080c2187e0a400,0x09fd1100fa0c1100\n"
".quad 0x0c016c0147d8307c,0x106940008780e000,0xa0034400c7801000,0xfc08000025001005\n"
".quad 0x20111100fe0c1100,0x22154400c7801000,0x80184400c7801000,0x24411002821c1000\n"
".quad 0x002980000780e012,0xa42080000780e000,0x10031002a6241000,0x8019000007801006\n"
".quad 0x801d000000031000,0x8010000000031000,0x8c40100282141000,0x8c2810028e441000\n"
".quad 0x8c2010028e2c1000,0xa40810028e241000,0x33fd1002a60c1000,0x70036c0087e8307c\n"
".quad 0x700300000000a009,0xf86d000022801009,0xf8710403c7801000,0xb0030603c7801000\n"
".quad 0xb469000000004008,0x35fd0fffffff203f,0x00036c00c7e8307c,0x000300000000a007\n"
".quad 0x2049000022801007,0x805160028780e000,0x8055000000031000,0x25fd040100031000\n"
".quad 0x0003e00107e8e014,0x3805000021005000,0xb871c00007820002,0x33fd000000032001\n"
".quad 0x00696c0087e8301c,0x900360c00780d400,0x3805000022801008,0x8049c00007800003\n"
".quad 0x000340800780d400,0xfc08000011001008,0x20111100fe0c1100,0x22154400c7801000\n"
".quad 0x80184400c7801000,0x24411002821c1000,0x002980000780e012,0xa42080000780e000\n"
".quad 0x70031002a6241000,0x8019000007801008,0x801d000000031000,0x8010000000031000\n"
".quad 0x8c40100282141000,0x8c2810028e441000,0x8c2010028e2c1000,0xa40810028e241000\n"
".quad 0x10691002a60c1000,0x00034400c7801000,0x806d000007805000,0x0003000000031001\n"
".quad 0x37fd000007805000,0x70036c0147e8307c,0x1019000022801009,0x202180000780e006\n"
".quad 0x0c1968028780e000,0x042160018780e000,0x081960020780e000,0x33fd60018780e000\n"
".quad 0x10416c0147e8301c,0x0c2980000780e008,0x900380000780e006,0x6003000025001008\n"
".quad 0x0001000007801006,0x3003e0000002f000,0x0c0100000100100f,0x00054400c7801000\n"
".quad 0x020500000780401d,0x020500004780601c,0x0001c41007803010,0x001d00004780601c\n"
".quad 0x0e01040607802000,0xf805c41007803002,0xebfdc00007800000,0x8e206c2087c8307c\n"
".quad 0x00012100e8242019,0x01fd40c00780d400,0xd0016c00c7d8307c,0xf801042015002040\n"
".quad 0x01fd0403d2801000,0x00036c0087d8307c,0x000100000000a00c,0xd00360c00780d400\n"
".quad 0xa00900001280100b,0xec0120000780d000,0x0009042007802000,0x021900208780a800\n"
".quad 0x041d00208780a800,0x020800208780a800,0x0215400602104002,0x0409000007804007\n"
".quad 0x0811c41007803010,0x0a15c41007803010,0x0005c41007803010,0x0009000087806002\n"
".quad 0x000d000107806006,0x0001000147806007,0x020160c00780d400,0x04190400c780a000\n"
".quad 0x06150400c780a000,0x00030400c780a000,0xf81500000780100c,0xf8190603c7801000\n"
".quad 0xf8010403c7801000,0x00010603c7801000,0xa003e0000002f000,0x000d00000100100c\n"
".quad 0x1404000000031000,0x0205100218081000,0x000104400780d082,0x020504400780d082\n"
".quad 0x0001c41007803008,0x120104004780d001,0xe003a0c00780d00e,0x121100000780100e\n"
".quad 0x2a0580c00780d00e,0x10594400c7801000,0xea0900008780a000,0x0629046047802100\n"
".quad 0x040d000007804016,0x1439ec100780301f,0x0629c41007803010,0x080d04400780d081\n"
".quad 0x042de41007803008,0x1429000387806016,0x0c21040087802000,0x160100008780a000\n"
".quad 0x1429040007802000,0x062cec1007803001,0x14011000840c4008,0x164d040007802000\n"
".quad 0x4003c41007803010,0x1259000007802014,0x040d00008780a000,0x80100004c7806008\n"
".quad 0x8600401606381002,0x1c191000840c2006,0x1401c41007803010,0x0405040007802000\n"
".quad 0x4003000187806016,0x820c000007802014,0x080d100280042005,0x14010000c780a000\n"
".quad 0x04090400c7802000,0x040dc01007803008,0x40030403c7801000,0x0609000007802014\n"
".quad 0x120500004780d002,0x9205a0400780d00e,0x0201000000032002,0x8e1da0000780d00e\n"
".quad 0x0ffd000000032001,0x08056c0147d83008,0x922520000780d400,0x3003000000032004\n"
".quad 0x000100001280100a,0xfe03e0000002f000,0x2ffd00000000861f,0x50036c0087c8307c\n"
".quad 0x500300000000a010,0x0001000002801010,0x80052780c7801000,0x0009000000031001\n"
".quad 0x2e05e0c00780d701,0x04014400c7801000,0xb0030603c7801000,0x000d000007802010\n"
".quad 0x2e050403c7801000,0x34014400c7801000,0x0401e42087800000,0xa0030403c7801000\n"
".quad 0x3601000007802012,0x3801e420c7800000,0x0001e42007800000,0xfe03e0000002f000\n"
".quad 0x300100000000861f,0xf5fd4400c7801000,0xe003642047c83000,0x0003000002801001\n"
".quad 0x020d000007803000,0x061144004780a000,0x000d000007809000,0x881144064780a000\n"
".quad 0x060d0fffffff203e,0x060d0000c7c0c004,0x0c1584064780a000,0x0e15000007804003\n"
".quad 0x0a15000147806002,0x0c15c41007803010,0x0015000147806002,0x0a15040147802040\n"
".quad 0x0a1144064780a000,0x08110000c7c0c004,0x060d84064780a000,0x0c11040107802000\n"
".quad 0x0e11000007804003,0x0811000107806002,0x0c11c41007803010,0x0811000107806002\n"
".quad 0x0211040007803000,0x080d6400c7803004,0x0c110400c7803000,0x0e11000007804003\n"
".quad 0x0811000107806002,0x0c0dc41007803010,0x0601000107806002,0x03fd040007803000\n"
".quad 0x0001640147c8307c,0x00030402c500d001,0x0001000007803000,0x0209e0000000f000\n"
".quad 0x041144004780a000,0x0009000007809000,0x881144064780a000,0x04090fffffff203e\n"
".quad 0x04090000c7c0c004,0x081584064780a000,0x0a15000007804003,0x0a15000147806002\n"
".quad 0x0815c41007803010,0x0015000147806002,0x0a15040147802040,0x0a1144064780a000\n"
".quad 0x08110000c7c0c004,0x040984064780a000,0x0811040107802000,0x0a11000007804003\n"
".quad 0x0811000107806002,0x0811c41007803010,0x0801000107806002,0x0201040007803000\n"
".quad 0x00016400c7803000,0x03fd040087803000,0x0001640147c8307c,0x00030402c500d001\n"
".quad 0x0001000007803000,0x062de0000000f000,0x163904114780a000,0x004144004780a000\n"
".quad 0x1c4504114780a000,0x2039000007809000,0xa24544064780a000,0x1c390fffffff203e\n"
".quad 0x1c390000c7d0c011,0x2c4984064780a000,0x2e4900000780401d,0x244900048780601c\n"
".quad 0x2c49c41007803010,0x204900048780601c,0x2449040487802040,0x244544064780a000\n"
".quad 0x22450000c7d0c011,0x1c3984064780a000,0x3a45040447802000,0x3845000007804016\n"
".quad 0x2245000447806017,0x3845c41007803010,0x2241000447806016,0x162d040407803000\n"
".quad 0x06016400c7803010,0x000104008780d000,0x1639e4100780301f,0x002d040387803000\n"
".quad 0x162d2c014780a000,0x07fd04008780d00e,0x00016c0147d8307c,0x00010402c7802000\n"
".quad 0x00030402d500d003,0x0001000017803000,0x03ffe0000001f000,0x00ff000000010000\n"
".quad 0x0000003c0b0400ff,0x000c000000080000,0x0018000000100000,0x0028000000200000\n"
".quad 0x0038000000300000,0x0044000000400000,0x004c000000480000,0x0054000000500000\n"
".quad 0x012000080d040000,0x0205000000200024,0xf80500400780d080,0xf8090603c7801000\n"
".quad 0x00190403c7801000,0x021d040007c0a000,0x0205040007d0a000,0x02092440c1001000\n"
".quad 0x02292440d1001000,0x7003040007c0d002,0x700300000000a001,0x0001000001001001\n"
".quad 0x80052780c7801000,0x0005000000031001,0x220de0c00780d701,0x02014400c7801000\n"
".quad 0x10030603c7801000,0x0009000007802011,0x220d0403c7801000,0x28014400c7801000\n"
".quad 0x0201e42047800000,0x00030603c7801000,0x2a01000007802013,0x2c01e42087800000\n"
".quad 0x0001e42007800000,0xfe03e0000002f000,0x240100000000861f,0xe9fd4400c7801000\n"
".quad 0x0003642187c83000,0x4409000002803000,0x420504200780a000,0x2c0d04200780a000\n"
".quad 0x2a014400c7801000,0x0c144400c7801000,0x0e15400300104005,0x0211000147806004\n"
".quad 0x0a15000107806002,0x0811c41007803010,0x0c15c41007803010,0x000d000147806004\n"
".quad 0x8a00000107806002,0xcffd200686302007,0xcdfd6c2107c83000,0x90036c2102c8300c\n"
".quad 0x900300000000a00f,0x0c0d00000100100f,0x0c114400c7801000,0x0e11000007804001\n"
".quad 0x0811000107806000,0x0c0dc41007803010,0x0635000107806000,0x1a0d040307802000\n"
".quad 0xc82dc41007803002,0x160d0420c7802000,0x061580c00780d00e,0x19fde41007803008\n"
".quad 0x0c116c00c7c8307c,0x0e0d04008780a000,0x141504008780a000,0xf00304008780a000\n"
".quad 0xe00300000000a004,0x9621000002801004,0x10210fffffff203c,0x102580c00780d00e\n"
".quad 0x2039e41007803008,0x242504008780a000,0x9c3804008780a000,0x22212045923c2044\n"
".quad 0x1c2504008780a000,0x1e3904114780a000,0x102104114780a000,0x12250400c7802040\n"
".quad 0x1c396c4107803082,0x10216c4107803082,0x122504114780a000,0x102104004780d00e\n"
".quad 0x10216c4107803082,0x103904004780d009,0xf0032c014780a000,0xf839000007801004\n"
".quad 0x00010403c7801000,0x6003e0000002f000,0x982100000000a006,0xcdfd000000032001\n"
".quad 0x60036c20c7c83008,0x9621000002801006,0x1021000000032004,0x102580c00780d00e\n"
".quad 0x203de41007803008,0x242504008780a000,0x9e3c04008780a000,0x2221204592402044\n"
".quad 0x1e2504008780a000,0x203d04114780a000,0x102104114780a000,0x12250400c7802040\n"
".quad 0x1e3d6c4107803082,0x10216c4107803082,0x122504114780a000,0x102104004780d00f\n"
".quad 0x10216c4107803082,0x102104004780d009,0x1c392c014780a000,0x01fd040207802000\n"
".quad 0xd0036c00c7ca307c,0xd00300000000a007,0xcc21000002801007,0x1021042347803000\n"
".quad 0xc821c41007803002,0x1021042207802000,0x102580c00780d00e,0x203de41007803008\n"
".quad 0x242504008780a000,0x9e3c04008780a000,0x2221204592402044,0x1e2504008780a000\n"
".quad 0x203d04114780a000,0x102104114780a000,0x12250400c7802040,0x1e3d6c4107803082\n"
".quad 0x10216c4107803082,0x122504114780a000,0x102104004780d00f,0x10216c4107803082\n"
".quad 0x102104004780d009,0x1c392c014780a000,0x0001040207802000,0x6003e0000002f000\n"
".quad 0x802100000000a009,0xcffd000000032001,0x60036c20c7c83008,0xcc21000002801009\n"
".quad 0x1021042347802000,0xc821c41007803002,0x1021042207802000,0x102580c00780d00e\n"
".quad 0x2035e41007803008,0x242504008780a000,0x9a3404008780a000,0x22212045923c2044\n"
".quad 0x1a2504008780a000,0x1e3504114780a000,0x102104114780a000,0x12250400c7802040\n"
".quad 0x1a356c4107803082,0x10216c4107803082,0x122504114780a000,0x102104004780d00d\n"
".quad 0x10216c4107803082,0x102104004780d009,0x1c392c014780a000,0x1dfd040207802000\n"
".quad 0x90036c0087ca307c,0x980500000280100f,0x182520000780d000,0x003144014780a000\n"
".quad 0xf20044014780a000,0x01fd1100f4201100,0xda3d0c2187c8a400,0xda4100200780e009\n"
".quad 0x400300220780e00c,0xf60000000100100a,0x20301100f8201100,0xa038c00f1e24c010\n"
".quad 0x900310009e341002,0xf82500000780100a,0xf8310603c7801000,0xf8350403c7801000\n"
".quad 0xf8390603c7801000,0x9e000403c7801000,0xd1fd1000a0201002,0xf03d6c6087c83081\n"
".quad 0xc0030fffffff213f,0x124100000280100b,0x21fd00030780b000,0xb003604047c8b083\n"
".quad 0xb00300000000a00b,0xb00300000100100b,0x1a3400000000400b,0x1a24b04c1230c00e\n"
".quad 0x1038b00c0034b00d,0x1c31c00d1a24b009,0x1e3d00000780c00e,0x0003044107c02100\n"
".quad 0x1841000001005000,0x21fd00024780b000,0x1003604047c8b083,0x000300000280100b\n"
".quad 0x0001000007805000,0x1e21e0000002f000,0xd0016c010780307c,0x00010423c7802040\n"
".quad 0x01fd04000780d008,0x60036c0087c8307c,0x300300000000a00d,0x700500000280100d\n"
".quad 0xe00120000780d000,0x0045042007802000,0x026100208780a400,0x044100208780a400\n"
".quad 0x022400208780a400,0x0239401802344011,0x1225000007804010,0x1a35c41007803010\n"
".quad 0x1c39c41007803010,0x0025c41007803010,0x0031000247806011,0x0021000347806018\n"
".quad 0x1201000387806010,0x18390400c780a000,0x10310400c780a000,0x60030400c780a000\n"
".quad 0xf83100000780100d,0xf8390603c7801000,0xf8010403c7801000,0x1e210603c7801000\n"
".quad 0x20354400c7821000,0xfe25000007804009,0x223d000000032101,0x1235000347806008\n"
".quad 0x2041ec100780301f,0x1e3d00000780400b,0x1a35c41007803010,0x224104400780d081\n"
".quad 0x203d00040780600a,0x1a110003c7806008,0x2041040247802000,0x1e01c41007803010\n"
".quad 0x0835040007802000,0x2015ec1007803001,0x921000040780600a,0x0a3920009a001000\n"
".quad 0xa003040387802000,0x8014000007802014,0x1a01100092101002,0x0a29040387802000\n"
".quad 0xa0030000c780a000,0x2011000007802014,0x2211000007804007,0x0811000107806006\n"
".quad 0x200dc41007803010,0x8610000107806006,0x1a011002800c200c,0x0c19040107802000\n"
".quad 0x1211c01007803008,0xa0030403c7801000,0x1419000007802014,0x160d00004780d006\n"
".quad 0x960da0400780d00e,0x0601000000032002,0x0001a0000780d00e,0xfe03e0000002f000\n"
".quad 0x15fd00000000861f,0xb0036c0087c8307c,0xb00300000000a010,0x0001000002801010\n"
".quad 0x800d2780c7801000,0x0011000000031001,0x220de0c00780d703,0x08014400c7801000\n"
".quad 0x10030603c7801000,0x0015000007802011,0x220d0403c7801000,0x28014400c7801000\n"
".quad 0x0801e42107800000,0x00030403c7801000,0x2a01000007802013,0x2c01e42147800000\n"
".quad 0x0001e42007800000,0xfe03e0000002f000,0x240100000000861f,0xe9fd4400c7801000\n"
".quad 0xe003642047c83000,0x0003000002801001,0x0615000007803000,0x0a2144004780a000\n"
".quad 0x0015000007809000,0x902144064780a000,0x0a150fffffff203e,0x0a150000c7c0c008\n"
".quad 0x142584064780a000,0x1625000007804007,0x1225000247806006,0x1425c41007803010\n"
".quad 0x0025000247806006,0x1225040247802040,0x122144064780a000,0x10210000c7c0c008\n"
".quad 0x0a1584064780a000,0x1421040207802000,0x1621000007804007,0x1021000207806006\n"
".quad 0x1421c41007803010,0x1021000207806006,0x0621040007803000,0x10156400c7803008\n"
".quad 0x1421040147803000,0x1621000007804007,0x1021000207806006,0x1415c41007803010\n"
".quad 0x0a01000207806006,0x07fd040007803000,0x0001640147c8307c,0x00030402c500d003\n"
".quad 0x0001000007803000,0x0611e0000000f000,0x082144004780a000,0x0011000007809000\n"
".quad 0x902144064780a000,0x08110fffffff203e,0x08110000c7c0c008,0x102584064780a000\n"
".quad 0x1225000007804007,0x1225000247806006,0x1025c41007803010,0x0025000247806006\n"
".quad 0x1225040247802040,0x122144064780a000,0x10210000c7c0c008,0x081184064780a000\n"
".quad 0x1021040207802000,0x1221000007804007,0x1021000207806006,0x1021c41007803010\n"
".quad 0x1001000207806006,0x0601040007803000,0x00016400c7803000,0x07fd040107803000\n"
".quad 0x0001640147c8307c,0x00030402c500d003,0x0001000007803000,0x083de0000000f000\n"
".quad 0x1e4104114780a000,0x004544004780a000,0x204904114780a000,0x2241000007809000\n"
".quad 0xa44944064780a000,0x20410fffffff203e,0x20410000c7c0c012,0x3c4d84064780a000\n"
".quad 0x3e4d000007804021,0x264d0004c7806020,0x3c4dc41007803010,0x224d0004c7806020\n"
".quad 0x264d0404c7802040,0x264944064780a000,0x24490000c7c0c012,0x204184064780a000\n"
".quad 0x4249040487802000,0x404900000780401e,0x244900048780601f,0x4049c41007803010\n"
".quad 0x244500048780601e,0x1e3d040447803000,0x08016400c7803011,0x000104008780d000\n"
".quad 0x1e41e4100780301f,0x003d040407803000,0x1e3d2c014780a000,0x09fd04008780d010\n"
".quad 0x00016c0147c8307c,0x00010403c7802000,0x00030402c500d004,0x0001000007803000\n"
".quad 0x03ffe0000001f000,0x000a000000010000,0xffff408000000000,0x0000003c0b04ffff\n"
".quad 0x000c000000080000,0x0014000000100000,0x001c000000180000,0x0024000000200000\n"
".quad 0x002c000000280000,0x0034000000300000,0x003c000000380000,0x011800080d040000\n"
".quad 0x0205000000200023,0xf80500400780d080,0xf8090603c7801000,0x00350403c7801000\n"
".quad 0x0259040007c0a000,0x0205040007d0a000,0x02092440c1001000,0x025d2440d1001000\n"
".quad 0x7003040007c0d002,0x700300000000a001,0x0001000001001001,0x80052780c7801000\n"
".quad 0x0009000000031001,0x2e05e0c00780d701,0x04014400c7801000,0x00030603c7801000\n"
".quad 0x000d000007802012,0x2e050403c7801000,0x34014400c7801000,0x0401e42087800000\n"
".quad 0xf0030603c7801000,0x3601000007802013,0x3801e420c7800000,0x0001e42007800000\n"
".quad 0xfe03e0000002f000,0x300100000000861f,0xf5fd4400c7801000,0x0003642187c83000\n"
".quad 0x4425000002803000,0x422104200780a000,0x380504200780a000,0x36014400c7801000\n"
".quad 0x040c4400c7801000,0x060d401100084013,0x02090000c7806012,0x060d000087806010\n"
".quad 0x0409c41007803010,0x040dc41007803010,0x00050000c7806012,0x8600000087806010\n"
".quad 0xcffd200d820c2016,0xcdfd6c2107c83000,0x80036c2102c83003,0x800300000000a010\n"
".quad 0x0c05000001001010,0x04094400c7801000,0x0609000007804001,0x0409000087806000\n"
".quad 0x0405c41007803010,0x0211000087806000,0x08050400c7802000,0xc861c41007803002\n"
".quad 0x3005042047802000,0x020980c00780d00e,0x07fde41007803008,0xf0036c00c7c8307c\n"
".quad 0x042900000000a004,0x063104008780a000,0x082d04008780a000,0xe00304008780a000\n"
".quad 0xb005000002801004,0x02050fffffff203c,0x020980c00780d00e,0x0415e41007803008\n"
".quad 0x080904008780a000,0x8a1404008780a000,0x0605204b8418204a,0x0a0904008780a000\n"
".quad 0x0c1504114780a000,0x020504114780a000,0x0409040307802040,0x0a156c4107803082\n"
".quad 0x02056c4107803082,0x040904114780a000,0x020504004780d005,0x02056c4107803082\n"
".quad 0x021504004780d002,0xf0032c014780a000,0xf815000007801004,0x00010403c7801000\n"
".quad 0x6003e0000002f000,0x860500000000a006,0xcdfd000000032001,0x60036c20c7c83001\n"
".quad 0xb005000002801006,0x0205000000032004,0x020980c00780d00e,0x0419e41007803008\n"
".quad 0x080904008780a000,0x8c1804008780a000,0x0605204b841c204a,0x0c0904008780a000\n"
".quad 0x0e1904114780a000,0x020504114780a000,0x0409040307802040,0x0c196c4107803082\n"
".quad 0x02056c4107803082,0x040904114780a000,0x020504004780d006,0x02056c4107803082\n"
".quad 0x020504004780d002,0x0a152c014780a000,0x01fd040047802000,0xd0036c00c7ca307c\n"
".quad 0xd00300000000a007,0xcc05000002801007,0x0205042107803000,0xc805c41007803002\n"
".quad 0x0205042047802000,0x020980c00780d00e,0x0419e41007803008,0x080904008780a000\n"
".quad 0x8c1804008780a000,0x0605204b841c204a,0x0c0904008780a000,0x0e1904114780a000\n"
".quad 0x020504114780a000,0x0409040307802040,0x0c196c4107803082,0x02056c4107803082\n"
".quad 0x040904114780a000,0x020504004780d006,0x02056c4107803082,0x020504004780d002\n"
".quad 0x0a152c014780a000,0x0001040047802000,0x6003e0000002f000,0x800500000000a009\n"
".quad 0xcffd000000032001,0x60036c20c7c83001,0xcc05000002801009,0x0205042107802000\n"
".quad 0xc805c41007803002,0x0205042047802000,0x021180c00780d00e,0x0409e41007803008\n"
".quad 0x101104008780a000,0x840804008780a000,0x0605204b8810204a,0x040904008780a000\n"
".quad 0x081104114780a000,0x020504114780a000,0x0409040307802040,0x08116c4107803082\n"
".quad 0x02056c4107803082,0x040904114780a000,0x020504004780d004,0x02056c4107803082\n"
".quad 0x020504004780d002,0x0a152c014780a000,0x0bfd040047802000,0x80036c0087ca307c\n"
".quad 0xc805000002801010,0x063920000780d000,0x240944410780a000,0x260d4400c7801000\n"
".quad 0xf4184400c7801000,0x00111100f61c1100,0xf80044410780a000,0x01fd1100fa041100\n"
".quad 0x1c390c2187c8a400,0x041940018780e002,0xb00340000780e004,0xfc0800000100100a\n"
".quad 0x20111100fe0c1100,0x22154400c7801000,0x0c494400c7801000,0x1c5180000780e006\n"
".quad 0x8c0080000780e00e,0x9c4010008e041002,0x200310009e441002,0x800100000780100b\n"
".quad 0x8005000000031000,0x8050000000031000,0x8048100082541002,0x80401000824c1002\n"
".quad 0x9c08100082441002,0x8c1010009e0c1002,0xd1fd10008e141002,0xf0656c6087c83081\n"
".quad 0xc0030fffffff213f,0x281900000280100c,0x803960048780e000,0x803d000000031000\n"
".quad 0x0dfd040100031000,0xb003e00047c8e00e,0xb00300000000a00c,0xb00300000100100c\n"
".quad 0x200100000000400c,0x281980000780e000,0x000168048780e000,0x044160000780e000\n"
".quad 0x080160018780e000,0x205160000780e000,0x004980000780e010,0x326580000780e000\n"
".quad 0x00030440c7c02100,0x2419000001005000,0x803960050780e000,0x803d000000031000\n"
".quad 0x0dfd040100031000,0xc003e00047c8e00e,0x000300000280100b,0x0001000007805000\n"
".quad 0x3205e0000002f000,0xd0016c010780307c,0x0001042647802040,0x01fd04000780d001\n"
".quad 0x60036c0087c8307c,0x300300000000a00e,0xa00500000280100e,0xec0120000780d000\n"
".quad 0x0009042007802000,0x021900208780a400,0x041d00208780a400,0x020800208780a400\n"
".quad 0x0215400602104002,0x0409000007804007,0x0811c41007803010,0x0a15c41007803010\n"
".quad 0x0005c41007803010,0x0009000087806002,0x000d000107806006,0x0201000147806007\n"
".quad 0x04150400c780a000,0x06190400c780a000,0x60030400c780a000,0xf81900000780100e\n"
".quad 0xf8150603c7801000,0xf8010403c7801000,0x2a050603c7801000,0x040d4400c7821000\n"
".quad 0xea09000007804015,0x0611046047802100,0x040d0000c7806014,0x0811ec100780301f\n"
".quad 0x060dc41007803010,0x041104400780d081,0x860c000107806014,0x0801401704282002\n"
".quad 0x061d040007802000,0x0611ec1007803001,0x840c000287806016,0x081120008e001000\n"
".quad 0x9003c41007803010,0x0429000007802015,0x040d000007804019,0x0011000107806016\n"
".quad 0x06290603c7801000,0x8600000287806018,0x14151000840c2005,0x0e01c41007803010\n"
".quad 0x0405040007802000,0x9003000147806018,0x820c000007802015,0x080d100280042006\n"
".quad 0x0e010000c780a000,0x04090400c7802000,0x040dc01007803008,0x90030403c7801000\n"
".quad 0x0609000007802015,0x300500004780d002,0xb005a0400780d00e,0x0201000000032002\n"
".quad 0x0001a0000780d00e,0xfe03e0000002f000,0x2ffd00000000861f,0xa0036c0087c8307c\n"
".quad 0xa00300000000a011,0x0001000002801011,0x80052780c7801000,0x0009000000031001\n"
".quad 0x2e05e0c00780d701,0x04014400c7801000,0x00030603c7801000,0x000d000007802012\n"
".quad 0x2e050403c7801000,0x34014400c7801000,0x0401e42087800000,0xf0030403c7801000\n"
".quad 0x3601000007802013,0x3801e420c7800000,0x0001e42007800000,0xfe03e0000002f000\n"
".quad 0x300100000000861f,0xf5fd4400c7801000,0xe003642047c83000,0x0003000002801001\n"
".quad 0x020d000007803000,0x061144004780a000,0x000d000007809000,0x881144064780a000\n"
".quad 0x060d0fffffff203e,0x060d0000c7c0c004,0x0c1584064780a000,0x0e15000007804003\n"
".quad 0x0a15000147806002,0x0c15c41007803010,0x0015000147806002,0x0a15040147802040\n"
".quad 0x0a1144064780a000,0x08110000c7c0c004,0x060d84064780a000,0x0c11040107802000\n"
".quad 0x0e11000007804003,0x0811000107806002,0x0c11c41007803010,0x0811000107806002\n"
".quad 0x0211040007803000,0x080d6400c7803004,0x0c110400c7803000,0x0e11000007804003\n"
".quad 0x0811000107806002,0x0c0dc41007803010,0x0601000107806002,0x03fd040007803000\n"
".quad 0x0001640147c8307c,0x00030402c500d001,0x0001000007803000,0x0209e0000000f000\n"
".quad 0x041144004780a000,0x0009000007809000,0x881144064780a000,0x04090fffffff203e\n"
".quad 0x04090000c7c0c004,0x081584064780a000,0x0a15000007804003,0x0a15000147806002\n"
".quad 0x0815c41007803010,0x0015000147806002,0x0a15040147802040,0x0a1144064780a000\n"
".quad 0x08110000c7c0c004,0x040984064780a000,0x0811040107802000,0x0a11000007804003\n"
".quad 0x0811000107806002,0x0811c41007803010,0x0801000107806002,0x0201040007803000\n"
".quad 0x00016400c7803000,0x03fd040087803000,0x0001640147c8307c,0x00030402c500d001\n"
".quad 0x0001000007803000,0x0629e0000000f000,0x143904114780a000,0x003d44004780a000\n"
".quad 0x1c4104114780a000,0x1e39000007809000,0xa04144064780a000,0x1c390fffffff203e\n"
".quad 0x1c390000c7c0c010,0x284584064780a000,0x2a4500000780401d,0x224500044780601c\n"
".quad 0x2845c41007803010,0x1e4500044780601c,0x2245040447802040,0x224144064780a000\n"
".quad 0x20410000c7c0c010,0x1c3984064780a000,0x3a41040407802000,0x3841000007804014\n"
".quad 0x2041000407806015,0x3841c41007803010,0x203d000407806014,0x14290403c7803000\n"
".quad 0x06016400c780300f,0x000104008780d000,0x1439e4100780301f,0x0029040387803000\n"
".quad 0x14292c014780a000,0x07fd04008780d00e,0x00016c0147c8307c,0x0001040287802000\n"
".quad 0x00030402c500d003,0x0001000007803000,0x03ffe0000001f000,0x000a000000010000\n"
".quad 0x0b04ffffffff0000,0x000800000000003c,0x00100000000c0000,0x0020000000180000\n"
".quad 0x0030000000280000,0x0040000000380000,0x0048000000440000,0x00500000004c0000\n"
".quad 0x0d04000000540000,0x0020002301180008,0x0000000000000000,0x0001000000000000\n"
".quad 0x0000000000280000,0x0000000500000006,0x0000000000006048,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000348,0x0000000000000348,0x0000000000000004\n"
".quad 0x0000270560000000,0x00000000000014da,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000d24,0x0000000000000d24,0x0000000000000004,0x0000270660000000\n"
".quad 0x00000000000021fe,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000064,0x0000000000000004,0x0000260560000000,0x00000000000021fe\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000fdc,0x0000000000000fdc\n"
".quad 0x0000000000000004,0x0000260660000000,0x00000000000031da,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000064,0x0000000000000004\n"
".quad 0x0000250560000000,0x00000000000031da,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000af4,0x0000000000000af4,0x0000000000000004,0x0000250660000000\n"
".quad 0x0000000000003cce,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x00000000000000dc,0x0000000000000004,0x0000240560000000,0x0000000000003cce\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000b80,0x0000000000000b80\n"
".quad 0x0000000000000004,0x0000240660000000,0x000000000000484e,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000134,0x0000000000000004\n"
".quad 0x0000230560000000,0x000000000000484e,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000bb8,0x0000000000000bb8,0x0000000000000004,0x0000230660000000\n"
".quad 0x0000000000005406,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x000000000000005c,0x0000000000000004,0x0000220560000000,0x0000000000005406\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000c2c,0x0000000000000c2c\n"
".quad 0x0000000000000004,0x0000220660000000,0x0000000000006032,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000074,0x0000000000000004\n"
".quad 0x0000000500000001,0x0000000000006032,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000014,0x0000000000000014,0x0000000000000004,0x0000000600000001\n"
".quad 0x0000000000006046,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000004,0x0000000000000004,0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_13$[3187];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_13",(char*)__deviceText_$compute_13$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_13", (char*)__deviceText_$sm_13$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_13$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"0868d08e1fa820ff",(char*)"Mandelbrot_sm13.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xa5a9be29,&__elfEntries1};
# 2 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2
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
# 3 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2
struct __T20 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;int __par14;int __par15;char __par16;int __dummy_field;};
struct __T21 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;float __par9;float __par10;uchar4 __par11;int __par12;int __par13;int __par14;int __par15;char __par16;int __dummy_field;};
struct __T22 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;int __par12;int __par13;char __par14;int __dummy_field;};
struct __T23 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;int __par12;int __par13;char __par14;int __dummy_field;};
struct __T24 {uchar4 *__par0;int __par1;int __par2;int __par3;float __par4;float __par5;float __par6;float __par7;float __par8;uchar4 __par9;int __par10;int __par11;int __par12;int __par13;char __par14;int __dummy_field;};
struct __T25 {uchar4 *__par0;int __par1;int __par2;int __par3;double __par4;double __par5;double __par6;double __par7;double __par8;uchar4 __par9;int __par10;int __par11;int __par12;int __par13;char __par14;int __dummy_field;};
extern void __device_stub__Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const int, const int, const bool);
extern void __device_stub__Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4&, const int, const int, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4&, const int, const int, const int, const int, const bool);
static void __device_stub__Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4&, const int, const int, const int, const int, const bool);
static void __sti____cudaRegisterAll_50_tmpxft_0000241e_00000000_4_Mandelbrot_sm13_cpp1_ii_35da923b(void) __attribute__((__constructor__));
void __device_stub__Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib(uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const int __par14, const int __par15, const bool __par16){ struct __T20 *__T2124;
*(void**)(void*)&__T2124 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2124->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2124->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2124->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2124->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2124->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2124->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2124->__par6) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2124->__par7) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2124->__par8) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2124->__par9) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2124->__par10) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2124->__par11) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2124->__par12) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2124->__par13) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2124->__par14) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T2124->__par15) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T2124->__par16) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13))); };}
void MandelbrotDS0_sm13( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const int __cuda_14,const int __cuda_15,const bool __cuda_16)
# 115 "Mandelbrot_sm13.cu"
{__device_stub__Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16);
# 183 "Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
void __device_stub__Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const float __par9, const float __par10, const uchar4&__par11, const int __par12, const int __par13, const int __par14, const int __par15, const bool __par16) { struct __T21 *__T2125;
*(void**)(void*)&__T2125 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2125->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2125->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2125->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2125->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2125->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2125->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2125->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2125->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2125->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2125->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2125->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2125->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2125->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2125->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2125->__par14) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par15, sizeof(__par15), (size_t)&__T2125->__par15) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par16, sizeof(__par16), (size_t)&__T2125->__par16) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13)); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13))); }; }
void MandelbrotDS1_sm13( uchar4 *__cuda_0,const int __cuda_1,const int __cuda_2,const int __cuda_3,const float __cuda_4,const float __cuda_5,const float __cuda_6,const float __cuda_7,const float __cuda_8,const float __cuda_9,const float __cuda_10,const uchar4 __cuda_11,const int __cuda_12,const int __cuda_13,const int __cuda_14,const int __cuda_15,const bool __cuda_16)
# 274 "Mandelbrot_sm13.cu"
{__device_stub__Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14,__cuda_15,__cuda_16);
# 359 "Mandelbrot_sm13.cu"
}
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c"
static void __device_stub__Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T22 *__T2141;
*(void**)(void*)&__T2141 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2141->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2141->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2141->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2141->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2141->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2141->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2141->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2141->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2141->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2141->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2141->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2141->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2141->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2141->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2141->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm13<float,16>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T23 *__T2142;
*(void**)(void*)&__T2142 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2142->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2142->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2142->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2142->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2142->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2142->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2142->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2142->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2142->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2142->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2142->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2142->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2142->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2142->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2142->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot0_sm13<double,16>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const float __par4, const float __par5, const float __par6, const float __par7, const float __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T24 *__T2157;
*(void**)(void*)&__T2157 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2157->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2157->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2157->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2157->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2157->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2157->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2157->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2157->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2157->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2157->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2157->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2157->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2157->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2157->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2157->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm13<float>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const float &__cuda_4,const float &__cuda_5,const float &__cuda_6,const float &__cuda_7,const float &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __device_stub__Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( uchar4 *__par0, const int __par1, const int __par2, const int __par3, const double __par4, const double __par5, const double __par6, const double __par7, const double __par8, const uchar4&__par9, const int __par10, const int __par11, const int __par12, const int __par13, const bool __par14) { struct __T25 *__T2158;
*(void**)(void*)&__T2158 = (void*)0; if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T2158->__par0) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T2158->__par1) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T2158->__par2) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T2158->__par3) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T2158->__par4) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T2158->__par5) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T2158->__par6) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par7, sizeof(__par7), (size_t)&__T2158->__par7) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par8, sizeof(__par8), (size_t)&__T2158->__par8) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par9, sizeof(__par9), (size_t)&__T2158->__par9) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par10, sizeof(__par10), (size_t)&__T2158->__par10) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par11, sizeof(__par11), (size_t)&__T2158->__par11) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par12, sizeof(__par12), (size_t)&__T2158->__par12) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par13, sizeof(__par13), (size_t)&__T2158->__par13) != cudaSuccess) return; if (cudaSetupArgument((void*)(char*)&__par14, sizeof(__par14), (size_t)&__T2158->__par14) != cudaSuccess) return; { volatile static char *__f; __f = ((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> )); (void)cudaLaunch(((char *)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> ))); }; }
template<> void __wrapper__device_stub_Mandelbrot1_sm13<double>( uchar4 *&__cuda_0,const int &__cuda_1,const int &__cuda_2,const int &__cuda_3,const double &__cuda_4,const double &__cuda_5,const double &__cuda_6,const double &__cuda_7,const double &__cuda_8,const uchar4 &__cuda_9,const int &__cuda_10,const int &__cuda_11,const int &__cuda_12,const int &__cuda_13,const bool &__cuda_14){__device_stub__Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7,__cuda_8,__cuda_9,__cuda_10,__cuda_11,__cuda_12,__cuda_13,__cuda_14);}
static void __sti____cudaRegisterAll_50_tmpxft_0000241e_00000000_4_Mandelbrot_sm13_cpp1_ii_35da923b(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<double> ), (char*)"_Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot1_sm13IdEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot1_sm13<float> ), (char*)"_Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot1_sm13IfEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const double, const double, const double, const double, const double, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<double, (int)16> ), (char*)"_Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot0_sm13IdLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))Mandelbrot0_sm13<float, (int)16> ), (char*)"_Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", "_Z16Mandelbrot0_sm13IfLi16EEvP6uchar4iiiT_S2_S2_S2_S2_S0_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS1_sm13), (char*)"_Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib", "_Z18MandelbrotDS1_sm13P6uchar4iiifffffffS_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(uchar4 *, const int, const int, const int, const float, const float, const float, const float, const float, const float, const float, const uchar4, const int, const int, const int, const int, const bool))MandelbrotDS0_sm13), (char*)"_Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib", "_Z18MandelbrotDS0_sm13P6uchar4iiifffffffS_iiiib", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); __cudaRegisterVar(__cudaFatCubinHandle, (char*)&blockCounter, (char*)"blockCounter", "blockCounter", 0, 4, 0, 0); }
# 1 "/tmp/tmpxft_0000241e_00000000-1_Mandelbrot_sm13.cudafe1.stub.c" 2

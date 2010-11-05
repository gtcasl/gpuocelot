# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.cpp"
# 1 "ComputeBound.cu"
# 46 "/usr/local/cuda3.1/cuda/bin/../include/device_types.h"
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3
typedef long ptrdiff_t;
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/device_types.h" 1 3
# 46 "/usr/local/cuda3.1/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h" 1 3
# 94 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h" 3
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
# 426 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct CUuuid_st cudaUUID_t;
# 44 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/surface_types.h" 1 3
# 54 "/usr/local/cuda3.1/cuda/bin/../include/surface_types.h" 3
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
# 45 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h" 1 3
# 54 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h" 3
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
# 46 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 1 3
# 45 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 1 3
# 46 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 1 3
# 46 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 46 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/host_defines.h" 1 3
# 47 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 2 3
# 75 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 3
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
# 229 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 3
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
# 366 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 3
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
# 469 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/usr/local/cuda3.1/cuda/bin/../include/builtin_types.h" 2 3
# 70 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 2 3
# 213 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 2 3
# 94 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 156 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 168 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 181 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 187 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 200 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 213 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 225 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 236 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 254 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 260 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 269 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 280 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 293 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 319 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 330 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 341 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 351 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 426 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 432 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 438 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 444 "/usr/local/cuda3.1/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda3.1/cuda/bin/../include/surface_types.h"
# 62 "/usr/local/cuda3.1/cuda/bin/../include/surface_types.h"
# 69 "/usr/local/cuda3.1/cuda/bin/../include/surface_types.h"
# 54 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h"
# 62 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h"
# 69 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h"
# 76 "/usr/local/cuda3.1/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 81 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 87 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 93 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 99 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 105 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 111 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 123 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 129 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 135 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 141 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 147 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 153 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 162 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 165 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 171 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 177 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 189 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 195 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 201 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 207 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 229 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 235 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 243 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 249 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 255 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 261 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 267 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 273 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 276 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 282 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 288 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 294 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 300 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 312 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 318 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 324 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 336 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 342 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 348 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 354 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 366 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 368 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 370 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 372 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 374 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 376 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 378 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 380 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 382 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 384 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 386 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 388 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 390 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 392 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 394 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 396 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 398 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 400 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 402 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 404 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 406 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 408 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 410 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 412 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 414 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 416 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 418 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 420 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 424 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 426 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 428 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 430 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 432 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 434 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 436 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 438 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 440 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 442 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 444 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 446 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 448 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 450 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 452 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 454 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 456 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 458 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 460 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 469 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda3.1/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 90 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0));
# 91 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 92 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 93 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0);
# 101 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 102 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 103 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 104 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0));
# 105 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 106 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 107 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 109 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 110 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 111 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 119 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 120 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 121 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 122 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 123 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 124 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 125 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 126 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 127 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 128 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 129 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 137 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 138 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 139 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 140 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 141 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 142 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 143 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 144 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 152 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 153 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 161 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 162 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 170 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 171 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 172 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 173 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 174 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 175 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 176 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 184 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 185 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 186 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 187 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 188 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 189 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 197 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 198 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceAlignmentOffset(size_t *, const surfaceReference *);
# 199 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 207 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 208 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 216 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 217 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 218 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 226 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 227 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 228 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache);
# 229 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 230 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 238 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 239 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 240 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 241 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 249 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 250 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
# 251 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0);
# 252 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 253 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 254 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 255 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 263 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 264 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 272 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 273 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 274 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t);
# 275 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit);
# 283 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 284 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 285 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *);
# 294 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource *);
# 295 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource *, unsigned);
# 296 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource **, cudaStream_t = 0);
# 297 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource **, cudaStream_t = 0);
# 298 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource *);
# 299 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource *, unsigned, unsigned);
# 93 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 94 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 95 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 96 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 98 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 99 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 100 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 102 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 103 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 105 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 106 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 107 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 109 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 110 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 113 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 120 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 127 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 133 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 135 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 138 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 141 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 142 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 145 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 148 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 149 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 152 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 159 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 166 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 173 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 180 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 187 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 194 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 197 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 201 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 204 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 208 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 215 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 222 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 229 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 236 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 243 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 250 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 253 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 257 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 260 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 264 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 271 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 278 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 285 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 292 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 299 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 365 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 366 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 367 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 369 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 370 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 372 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 373 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 374 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 376 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 377 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 380 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 387 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda3.1/cuda/bin/../include/channel_descriptor.h"
}
# 55 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 56 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
{
# 57 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 59 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 60 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 61 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 62 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 64 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
return s;
# 65 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
}
# 67 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 68 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
{
# 69 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 71 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 72 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 73 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 75 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
return p;
# 76 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
}
# 78 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 79 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
{
# 80 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 82 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 83 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 84 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 86 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
return e;
# 87 "/usr/local/cuda3.1/cuda/bin/../include/driver_functions.h"
}
# 55 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 56 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 57 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 58 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 60 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 61 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 62 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 63 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 65 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 66 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 67 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 68 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 70 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 71 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 72 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 73 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 75 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 76 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 77 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 78 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 80 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 81 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 82 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 83 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 85 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 86 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 87 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 88 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 90 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 91 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 92 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 93 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 95 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 96 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 97 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 98 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 100 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 101 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 102 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 103 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 105 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 106 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 107 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 108 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 110 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 111 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 112 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 113 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 115 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 116 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 117 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 118 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 120 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 121 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 122 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 123 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 125 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 126 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 127 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 128 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 130 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 131 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 132 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 133 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 135 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 136 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 137 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 138 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 140 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 141 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 142 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 143 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 145 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 146 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 147 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 148 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 150 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 151 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 152 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 153 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 155 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 156 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 157 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 158 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 160 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 161 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 162 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 163 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 165 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 166 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 167 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 168 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 170 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 171 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 172 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 173 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 175 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 176 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 177 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 178 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 180 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 181 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 182 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 183 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 185 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 186 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 187 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 188 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 190 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 191 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 192 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 193 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 195 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 196 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 197 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 198 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 200 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 201 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 202 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 203 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 205 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 206 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 207 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 208 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 210 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 211 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 212 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 213 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 215 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 216 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 217 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 218 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 220 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 221 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 222 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 223 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 225 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 226 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 227 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 228 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 230 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 231 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 232 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 233 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 235 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 236 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 237 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 238 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 240 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 241 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 242 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 243 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 245 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 246 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 247 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 248 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 250 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 251 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 252 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 253 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 255 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 256 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 257 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 258 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 260 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 261 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 262 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 263 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 265 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 266 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 267 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 268 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 270 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 271 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 272 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 273 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 275 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 276 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 277 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 278 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 280 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 281 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 282 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 283 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 285 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 286 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 287 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 288 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
}
# 290 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 291 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
{
# 292 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 293 "/usr/local/cuda3.1/cuda/bin/../include/vector_functions.h"
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
# 57 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) clock_t clock() throw();
# 59 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1)));
# 61 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memcpy(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2)));
# 66 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int abs(int) throw() __attribute__((__const__));
# 68 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long labs(long) throw() __attribute__((__const__));
# 70 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__));
# 72 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fabs(double) throw() __attribute__((__const__));
# 74 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__));
# 77 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int min(int, int);
# 79 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umin(unsigned, unsigned);
# 81 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmin(long long, long long);
# 83 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 85 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fminf(float, float) throw();
# 87 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmin(double, double) throw();
# 90 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int max(int, int);
# 92 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umax(unsigned, unsigned);
# 94 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmax(long long, long long);
# 96 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 98 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaxf(float, float) throw();
# 100 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmax(double, double) throw();
# 103 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sin(double) throw();
# 105 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinf(float) throw();
# 108 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cos(double) throw();
# 110 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cosf(float) throw();
# 113 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincos(double, double *, double *) throw();
# 115 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincosf(float, float *, float *) throw();
# 118 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tan(double) throw();
# 120 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanf(float) throw();
# 123 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sqrt(double) throw();
# 125 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sqrtf(float) throw();
# 128 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rsqrt(double);
# 130 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rsqrtf(float);
# 133 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp2(double) throw();
# 135 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp2f(float) throw();
# 138 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp10(double) throw();
# 140 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp10f(float) throw();
# 143 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double expm1(double) throw();
# 145 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expm1f(float) throw();
# 148 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log2(double) throw();
# 150 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log2f(float) throw();
# 153 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log10(double) throw();
# 155 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log10f(float) throw();
# 158 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log(double) throw();
# 160 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logf(float) throw();
# 163 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log1p(double) throw();
# 165 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log1pf(float) throw();
# 168 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double floor(double) throw() __attribute__((__const__));
# 170 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float floorf(float) throw() __attribute__((__const__));
# 173 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp(double) throw();
# 175 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expf(float) throw();
# 178 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cosh(double) throw();
# 180 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float coshf(float) throw();
# 183 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinh(double) throw();
# 185 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinhf(float) throw();
# 188 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tanh(double) throw();
# 190 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanhf(float) throw();
# 193 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acosh(double) throw();
# 195 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acoshf(float) throw();
# 198 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asinh(double) throw();
# 200 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinhf(float) throw();
# 203 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atanh(double) throw();
# 205 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanhf(float) throw();
# 208 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ldexp(double, int) throw();
# 210 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ldexpf(float, int) throw();
# 213 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double logb(double) throw();
# 215 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logbf(float) throw();
# 218 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogb(double) throw();
# 220 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogbf(float) throw();
# 223 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbn(double, int) throw();
# 225 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalbnf(float, int) throw();
# 228 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbln(double, long) throw();
# 230 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalblnf(float, long) throw();
# 233 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double frexp(double, int *) throw();
# 235 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float frexpf(float, int *) throw();
# 238 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double round(double) throw() __attribute__((__const__));
# 240 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float roundf(float) throw() __attribute__((__const__));
# 243 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lround(double) throw();
# 245 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lroundf(float) throw();
# 248 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llround(double) throw();
# 250 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llroundf(float) throw();
# 253 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rint(double) throw();
# 255 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rintf(float) throw();
# 258 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrint(double) throw();
# 260 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrintf(float) throw();
# 263 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrint(double) throw();
# 265 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrintf(float) throw();
# 268 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nearbyint(double) throw();
# 270 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nearbyintf(float) throw();
# 273 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ceil(double) throw() __attribute__((__const__));
# 275 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__));
# 278 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double trunc(double) throw() __attribute__((__const__));
# 280 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float truncf(float) throw() __attribute__((__const__));
# 283 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fdim(double, double) throw();
# 285 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fdimf(float, float) throw();
# 288 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan2(double, double) throw();
# 290 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atan2f(float, float) throw();
# 293 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan(double) throw();
# 295 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanf(float) throw();
# 298 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asin(double) throw();
# 300 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinf(float) throw();
# 303 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acos(double) throw();
# 305 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acosf(float) throw();
# 308 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double hypot(double, double) throw();
# 310 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float hypotf(float, float) throw();
# 313 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cbrt(double) throw();
# 315 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cbrtf(float) throw();
# 318 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rcbrt(double);
# 320 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rcbrtf(float);
# 323 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinpi(double);
# 325 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinpif(float);
# 328 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double pow(double, double) throw();
# 330 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float powf(float, float) throw();
# 333 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double modf(double, double *) throw();
# 335 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float modff(float, float *) throw();
# 338 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmod(double, double) throw();
# 340 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmodf(float, float) throw();
# 343 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remainder(double, double) throw();
# 345 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remainderf(float, float) throw();
# 348 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remquo(double, double, int *) throw();
# 350 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remquof(float, float, int *) throw();
# 353 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erf(double) throw();
# 355 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erff(float) throw();
# 358 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfinv(double);
# 360 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfinvf(float);
# 363 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfc(double) throw();
# 365 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcf(float) throw();
# 368 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfcinv(double);
# 370 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcinvf(float);
# 373 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double lgamma(double) throw();
# 375 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float lgammaf(float) throw();
# 378 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tgamma(double) throw();
# 380 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tgammaf(float) throw();
# 383 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__));
# 385 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__));
# 388 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__));
# 390 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__));
# 393 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__));
# 395 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__));
# 398 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__));
# 400 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__));
# 403 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__));
# 405 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__));
# 419 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finite(double) throw() __attribute__((__const__));
# 421 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__));
# 423 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__));
# 428 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__));
# 431 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fma(double, double, double) throw();
# 433 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaf(float, float, float) throw();
# 441 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__));
# 443 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__));
# 445 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__));
# 455 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
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
# 497 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 499 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long) __attribute__((visibility("default")));
# 500 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 502 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
namespace std {
# 504 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __pow_helper(T, int);
# 505 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
template<class T> extern inline T __cmath_power(T, unsigned);
# 506 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 508 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::abs;
# 509 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::fabs;
# 510 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::ceil;
# 511 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::floor;
# 512 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 513 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::pow;
# 514 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::log;
# 515 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::log10;
# 516 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::fmod;
# 517 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::modf;
# 518 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::exp;
# 519 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::frexp;
# 520 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 521 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::asin;
# 522 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::sin;
# 523 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::sinh;
# 524 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::acos;
# 525 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::cos;
# 526 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::cosh;
# 527 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::atan;
# 528 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::atan2;
# 529 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::tan;
# 530 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
using std::tanh;
# 584 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
namespace std {
# 587 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline long abs(long) __attribute__((visibility("default")));
# 588 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float abs(float) __attribute__((visibility("default")));
# 589 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline double abs(double) __attribute__((visibility("default")));
# 590 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float fabs(float) __attribute__((visibility("default")));
# 591 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float ceil(float) __attribute__((visibility("default")));
# 592 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float floor(float) __attribute__((visibility("default")));
# 593 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float) __attribute__((visibility("default")));
# 594 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float) __attribute__((visibility("default")));
# 595 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int) __attribute__((visibility("default")));
# 596 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int) __attribute__((visibility("default")));
# 597 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float log(float) __attribute__((visibility("default")));
# 598 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float log10(float) __attribute__((visibility("default")));
# 599 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float) __attribute__((visibility("default")));
# 600 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *) __attribute__((visibility("default")));
# 601 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float exp(float) __attribute__((visibility("default")));
# 602 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *) __attribute__((visibility("default")));
# 603 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int) __attribute__((visibility("default")));
# 604 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float asin(float) __attribute__((visibility("default")));
# 605 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float sin(float) __attribute__((visibility("default")));
# 606 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float sinh(float) __attribute__((visibility("default")));
# 607 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float acos(float) __attribute__((visibility("default")));
# 608 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float cos(float) __attribute__((visibility("default")));
# 609 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float cosh(float) __attribute__((visibility("default")));
# 610 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float atan(float) __attribute__((visibility("default")));
# 611 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float) __attribute__((visibility("default")));
# 612 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float tan(float) __attribute__((visibility("default")));
# 613 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
extern inline float tanh(float) __attribute__((visibility("default")));
# 616 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 619 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 620 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 621 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return logbf(a);
# 622 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 624 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 625 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 626 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 627 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 629 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 630 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 631 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 632 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 634 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 635 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 636 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 637 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 639 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 640 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 641 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 642 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 644 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 645 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 646 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 647 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 649 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 650 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 651 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 652 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 654 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 655 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 656 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return log2f(a);
# 657 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 659 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 660 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 661 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 662 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 664 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 665 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 666 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 667 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 669 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 670 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 671 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 672 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 674 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 675 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 676 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 677 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 679 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 680 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 681 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 682 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 684 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 685 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 686 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 687 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 689 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 690 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 691 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 692 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 694 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 695 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 696 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 697 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 699 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 700 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 701 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 702 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 704 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 705 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 706 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 707 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 709 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 710 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 711 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return erff(a);
# 712 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 714 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 715 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 716 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 717 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 719 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 720 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 721 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 722 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 724 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 725 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 726 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 727 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 729 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 730 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 731 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 732 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 734 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 735 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 736 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 737 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 739 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 740 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 741 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 742 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 744 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 745 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 746 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 747 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 749 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 750 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 751 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 752 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 754 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 755 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 756 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 757 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 759 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 760 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 761 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 762 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 764 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 765 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 766 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 767 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 769 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 770 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 771 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return roundf(a);
# 772 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 774 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 775 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 776 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 777 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 779 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 780 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 781 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 782 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 784 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 785 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 786 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return truncf(a);
# 787 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 789 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 790 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 791 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return rintf(a);
# 792 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 794 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 795 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 796 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 797 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 799 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 800 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 801 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 802 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 804 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 805 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 806 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 807 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 809 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 810 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 811 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 812 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 814 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 815 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 816 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 817 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 819 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 820 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 821 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 822 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 824 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 825 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 826 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 827 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 829 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 830 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 831 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 832 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 834 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 835 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 836 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 837 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 839 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 840 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 841 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 842 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 844 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 845 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 846 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 847 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 849 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 850 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 851 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 852 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 854 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 855 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 856 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 857 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 859 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 860 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 861 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 862 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 864 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 865 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 866 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 867 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 869 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 870 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 871 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 872 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 874 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 875 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 876 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 877 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 879 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 880 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 881 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 882 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 884 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 885 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 886 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 887 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 889 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 890 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 891 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 892 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 894 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 895 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 896 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 897 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 899 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 900 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 901 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 902 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 904 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 905 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 906 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 907 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 909 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 910 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 911 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 912 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 914 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 915 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 916 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 917 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 919 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 920 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 921 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 922 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 924 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 925 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 926 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 927 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 929 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 930 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 931 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 932 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 934 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 935 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
{
# 936 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 937 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h"
}
# 60 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
template<class T, int dim = 1>
# 61 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 63 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
surface()
# 64 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
{
# 65 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 66 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
}
# 68 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 69 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
{
# 70 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 71 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
}
# 72 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
};
# 75 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
template<int dim>
# 76 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 78 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
surface()
# 79 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
{
# 80 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 81 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
}
# 82 "/usr/local/cuda3.1/cuda/bin/../include/cuda_surface_types.h"
};
# 60 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 61 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 63 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 64 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 65 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 66 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
{
# 67 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 68 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 69 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 70 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 71 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 72 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 73 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
}
# 75 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 76 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 77 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 78 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
desc)
# 79 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
{
# 80 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 81 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 82 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 83 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 84 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 85 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 86 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
}
# 87 "/usr/local/cuda3.1/cuda/bin/../include/cuda_texture_types.h"
};
# 329 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mulhi(int a, int b)
# 330 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 332 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 334 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, unsigned b)
# 335 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 337 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 339 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(int a, unsigned b)
# 340 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 344 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, int b)
# 345 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 347 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 349 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline long long mul64hi(long long a, long long b)
# 350 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 352 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 354 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 355 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 357 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 359 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(long long a, unsigned long long b)
# 360 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 364 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, long long b)
# 365 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 367 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 369 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float_as_int(float a)
# 370 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 374 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int_as_float(int a)
# 375 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 377 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 379 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float saturate(float a)
# 380 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 382 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 384 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mul24(int a, int b)
# 385 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 389 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned umul24(unsigned a, unsigned b)
# 390 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 392 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 394 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void trap()
# 395 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 397 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 399 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void brkpt(int c)
# 400 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 404 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void syncthreads()
# 405 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 407 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 409 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void prof_trigger(int e)
# 410 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 429 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void threadfence(bool global)
# 430 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 432 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 434 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float2int(float a, cudaRoundMode mode)
# 435 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 440 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 442 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned float2uint(float a, cudaRoundMode mode)
# 443 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 448 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 450 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int2float(int a, cudaRoundMode mode)
# 451 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 456 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 458 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float uint2float(unsigned a, cudaRoundMode mode)
# 459 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 464 "/usr/local/cuda3.1/cuda/bin/../include/device_functions.h"
exit(___);}
# 102 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAdd(int *address, int val)
# 103 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 105 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 107 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAdd(unsigned *address, unsigned val)
# 108 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 112 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicSub(int *address, int val)
# 113 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 115 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 117 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicSub(unsigned *address, unsigned val)
# 118 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 120 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 122 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicExch(int *address, int val)
# 123 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 125 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 127 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicExch(unsigned *address, unsigned val)
# 128 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 130 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 132 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline float atomicExch(float *address, float val)
# 133 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 135 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 137 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMin(int *address, int val)
# 138 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 142 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMin(unsigned *address, unsigned val)
# 143 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 147 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMax(int *address, int val)
# 148 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 150 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 152 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMax(unsigned *address, unsigned val)
# 153 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 155 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 157 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicInc(unsigned *address, unsigned val)
# 158 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 162 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicDec(unsigned *address, unsigned val)
# 163 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 167 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAnd(int *address, int val)
# 168 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 170 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 172 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAnd(unsigned *address, unsigned val)
# 173 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 175 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 177 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicOr(int *address, int val)
# 178 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 182 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicOr(unsigned *address, unsigned val)
# 183 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 185 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 187 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicXor(int *address, int val)
# 188 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 190 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 192 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicXor(unsigned *address, unsigned val)
# 193 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 195 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 197 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicCAS(int *address, int compare, int val)
# 198 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 203 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 205 "/usr/local/cuda3.1/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 75 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 76 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 78 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 80 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 81 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 83 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 85 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 86 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 88 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 90 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool any(bool cond)
# 91 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 93 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 95 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool all(bool cond)
# 96 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 98 "/usr/local/cuda3.1/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 170 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double fma(double a, double b, double c, cudaRoundMode mode)
# 171 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 176 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 178 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dmul(double a, double b, cudaRoundMode mode)
# 179 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 184 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 186 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dadd(double a, double b, cudaRoundMode mode)
# 187 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 194 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline int double2int(double a, cudaRoundMode mode)
# 195 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned double2uint(double a, cudaRoundMode mode)
# 203 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 208 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 210 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline long long double2ll(double a, cudaRoundMode mode)
# 211 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 216 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 218 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned long long double2ull(double a, cudaRoundMode mode)
# 219 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 224 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 226 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ll2double(long long a, cudaRoundMode mode)
# 227 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 234 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ull2double(unsigned long long a, cudaRoundMode mode)
# 235 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 240 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 242 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double int2double(int a, cudaRoundMode mode)
# 243 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 245 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 247 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double uint2double(unsigned a, cudaRoundMode mode)
# 248 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 252 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double float2double(float a, cudaRoundMode mode)
# 253 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda3.1/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 66 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_atomic_functions.h"
static __attribute__((unused)) inline float atomicAdd(float *address, float val)
# 67 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;
# 69 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 124 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline unsigned ballot(bool pred)
# 125 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 127 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 129 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline int syncthreads_count(bool pred)
# 130 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 132 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 134 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_and(bool pred)
# 135 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 137 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 139 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_or(bool pred)
# 140 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 142 "/usr/local/cuda3.1/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 97 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 98 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode)
# 99 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 106 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 108 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T
# 109 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 110 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 116 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 118 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 119 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 120 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 122 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 125 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 126 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 128 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 131 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 132 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 134 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 137 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 138 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 143 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 144 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 146 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 149 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 150 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 152 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 155 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 156 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 166 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 174 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 189 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 190 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 195 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 196 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 198 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 201 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 202 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 204 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 207 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 208 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 212 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 218 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 226 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 238 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 241 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 242 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 244 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 247 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 248 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 253 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 254 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 256 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 259 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 260 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 264 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 270 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 278 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 290 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 293 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 294 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 296 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 299 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 300 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 302 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 305 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 306 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 308 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 311 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 312 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 316 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 322 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 385 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 386 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 388 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 391 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 392 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 394 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 397 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 398 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 410 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 457 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 458 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode)
# 459 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 466 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T
# 469 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 470 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 476 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 478 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 479 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 480 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 482 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 485 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 486 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 488 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 491 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 492 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 494 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 497 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 498 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 500 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 503 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 504 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 506 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 509 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 510 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 512 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 515 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 516 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 520 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 526 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 534 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 540 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 546 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 549 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 550 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 555 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 556 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 558 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 561 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 562 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 564 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 567 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 568 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 572 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 578 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 586 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 592 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 598 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 601 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 602 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 604 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 607 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 608 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 610 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 613 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 614 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 616 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 619 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 620 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 624 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 630 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 638 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 644 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 650 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 653 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 654 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 659 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 660 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 662 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 665 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 666 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 668 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 671 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 672 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 682 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 745 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 746 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 748 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 751 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 752 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 754 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 757 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 758 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 762 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<> inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 770 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 817 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 818 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode)
# 819 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 837 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 839 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 840 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 841 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 843 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 846 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 847 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 849 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 851 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 852 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 854 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 856 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 857 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 859 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 862 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 864 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 866 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 867 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 869 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 871 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 872 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 876 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 877 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 879 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 882 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 884 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 886 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 887 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 889 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 891 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 892 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 894 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 896 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 897 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 899 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 901 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 902 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 904 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 906 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 907 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 909 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 911 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 912 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 914 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 916 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 917 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 919 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 921 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 922 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 924 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 926 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 927 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 929 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 931 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 932 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 934 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 936 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 937 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 939 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 941 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 942 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 946 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 947 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 949 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 952 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 954 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 956 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 957 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 959 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 961 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 962 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 964 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 966 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 967 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 969 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 972 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 974 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 976 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 977 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 979 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 981 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 982 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 984 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 986 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 987 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 989 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 992 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 994 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 996 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 997 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 999 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1045 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1046 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1048 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1050 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1051 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1053 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1055 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1056 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1058 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1060 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 1061 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1063 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1110 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 1111 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode)
# 1112 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1130 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1132 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void
# 1133 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1134 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1136 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1139 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1140 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1142 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1144 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1145 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1147 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1149 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1150 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1155 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1157 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1159 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1160 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1162 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1165 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1167 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1169 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1170 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1172 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1174 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1175 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1177 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1179 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1180 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1184 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1185 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1187 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1190 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1192 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1194 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1195 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1197 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1199 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1200 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1204 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1205 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1207 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1210 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1212 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1214 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1215 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1217 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1219 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1220 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1222 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1224 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1225 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1227 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1230 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1232 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1234 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1235 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1239 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1240 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1242 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1244 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1245 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1247 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1249 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1250 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1254 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1255 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1257 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1259 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1260 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1262 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1264 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1265 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1267 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1269 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1270 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1272 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1274 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1275 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1277 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1279 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1280 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1282 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1284 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1285 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1287 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1289 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1290 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1292 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1338 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1339 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1341 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1343 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1344 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1346 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1348 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1349 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1351 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1353 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 1354 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1356 "/usr/local/cuda3.1/cuda/bin/../include/surface_functions.h"
exit(___);}
# 61 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 63 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 65 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 68 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetch(texture< T, dim, readMode> , float4, int);
# 70 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetch(texture< T, dim, readMode> , float4, int);
# 72 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetch(texture< T, dim, readMode> , float4, int);
# 80 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 81 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 89 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 91 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 92 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 96 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 98 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 99 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 103 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 105 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 106 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 117 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 124 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 131 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 138 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 153 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 154 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 158 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 160 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 161 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 167 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 168 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 172 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 179 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 193 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 207 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 215 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 216 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 220 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 222 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 223 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 227 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 229 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 230 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 234 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 241 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 248 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 262 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 269 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 343 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 344 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 350 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 351 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 355 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 357 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 358 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 369 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 377 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 378 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 389 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 390 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 395 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 397 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 398 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 403 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 411 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 419 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 459 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 460 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 465 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 467 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 468 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 473 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 481 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 489 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 497 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 505 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 513 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 521 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 529 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 530 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 538 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 540 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 541 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 545 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 547 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 548 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 554 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 555 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 559 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 566 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 573 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 580 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 587 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 594 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 602 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 603 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 607 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 609 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 610 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 614 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 616 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 617 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 621 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 628 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 635 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 642 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 649 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 664 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 665 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 669 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 671 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 672 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 678 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 679 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 683 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 697 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 704 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 711 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 718 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 798 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 799 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 803 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 805 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 806 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 810 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 812 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 813 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 817 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 824 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 832 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 833 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 842 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 844 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 845 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 850 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 852 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 853 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 858 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 866 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 882 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 890 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 898 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 906 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 914 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 915 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 920 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 922 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 923 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 928 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 936 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 952 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 960 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 968 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 976 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 984 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 985 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 993 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 995 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 996 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1000 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1002 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1003 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1007 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1009 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1010 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1014 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1028 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1035 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1042 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1049 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1057 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1058 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1062 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1064 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1065 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1069 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1071 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1072 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1076 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1083 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1090 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1097 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1104 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1111 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1119 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1120 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1124 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1126 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1127 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1131 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1133 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1134 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1138 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1145 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1159 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1166 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1173 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1247 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1248 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1254 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1255 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1259 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1261 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1262 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1266 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1273 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1281 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1282 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1291 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1293 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1294 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1301 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1302 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1307 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1315 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1323 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1331 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1339 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1347 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1355 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1363 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1364 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1369 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1371 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1372 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1377 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1385 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1393 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1401 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1409 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1417 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1425 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1433 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1434 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1442 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1444 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1445 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1449 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1451 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1452 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1456 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1458 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1459 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1463 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1466 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1470 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1473 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1477 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1480 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1484 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1487 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1491 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1494 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1498 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1506 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1507 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1511 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1513 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1514 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1518 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1520 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1521 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1525 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1528 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1532 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1535 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1539 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1542 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1546 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1549 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1553 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1556 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1560 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1568 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1569 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1573 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1575 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1576 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1580 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1582 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1583 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1587 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1590 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1594 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1597 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1601 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1604 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1608 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1611 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1615 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1618 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1622 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1696 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1697 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1701 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1703 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1704 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1708 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1710 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1711 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1715 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1718 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1722 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1730 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1731 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1740 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1742 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1743 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1748 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1750 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1751 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1756 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1759 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1764 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1767 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1772 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1775 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1780 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1783 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1788 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1791 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1796 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1799 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1804 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1812 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1813 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1818 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1820 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1821 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1826 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1829 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1834 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1837 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1842 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1845 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1850 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1853 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1858 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1861 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1866 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1869 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1874 "/usr/local/cuda3.1/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 53 "/usr/local/cuda3.1/cuda/bin/../include/device_launch_parameters.h"
# 55 "/usr/local/cuda3.1/cuda/bin/../include/device_launch_parameters.h"
# 57 "/usr/local/cuda3.1/cuda/bin/../include/device_launch_parameters.h"
# 59 "/usr/local/cuda3.1/cuda/bin/../include/device_launch_parameters.h"
# 61 "/usr/local/cuda3.1/cuda/bin/../include/device_launch_parameters.h"
# 102 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 103 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 104 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 105 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset)
# 107 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 108 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 109 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 111 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 112 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 113 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 114 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 115 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
flags)
# 117 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 118 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 119 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 121 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 122 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 123 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 124 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 125 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
flags)
# 127 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 128 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 129 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 131 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 132 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 133 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 134 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size)
# 136 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 137 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 138 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 140 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 141 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 142 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 143 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size)
# 145 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 146 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size);
# 147 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 149 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 150 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 151 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 152 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 153 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 154 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
height)
# 156 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 157 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 158 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 173 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 174 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 175 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 176 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 177 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 178 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 180 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 181 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 182 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 184 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 185 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 186 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 187 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 188 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 189 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 190 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 192 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 193 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 194 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 196 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 197 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 198 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 199 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 200 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 201 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 202 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 204 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 205 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 206 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 209 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 210 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 211 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 212 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 213 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 214 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 215 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 217 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 218 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 219 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 228 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 229 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 230 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 231 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 232 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 234 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 235 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 236 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 238 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 239 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 240 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 241 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 242 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 243 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 244 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 246 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 247 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 248 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 250 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 251 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 252 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 253 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 254 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 255 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 256 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 258 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 259 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 260 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 262 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 263 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 264 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 265 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 266 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 267 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 268 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 269 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 271 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 272 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 273 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 276 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 277 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol)
# 279 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 280 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 281 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 308 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 309 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 310 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 311 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol)
# 313 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 314 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 315 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 323 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 324 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size, char *
# 325 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol)
# 327 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 328 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 329 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 356 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 357 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 358 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 359 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
symbol)
# 361 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 362 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 363 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 412 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 413 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 414 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 415 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 416 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 417 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 418 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 420 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 421 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 422 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 456 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 457 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 458 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 459 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 460 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 461 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 463 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 464 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.texture< T, dim, readMode> ::channelDesc), size);
# 465 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 511 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 512 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 513 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 514 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 515 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 516 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 517 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 518 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 519 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
pitch)
# 521 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 522 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 523 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 553 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 554 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 555 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 556 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 557 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
desc)
# 559 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 560 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 561 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 590 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 591 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 592 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 593 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
array)
# 595 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 596 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 597 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 599 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 600 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 628 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 629 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 630 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex)
# 632 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 633 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 634 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 667 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 668 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 669 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 670 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
tex)
# 672 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 673 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 674 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 724 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 725 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 726 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 727 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 729 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 730 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 731 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 768 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 769 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 770 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
entry)
# 772 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 773 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 774 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 805 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
# 806 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 807 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 808 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
entry)
# 810 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 811 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 812 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 835 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 836 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 837 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 838 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 839 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
desc)
# 841 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 842 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 843 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 865 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim> inline cudaError_t
# 866 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 867 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 868 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
array)
# 870 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
{
# 871 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 872 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 874 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 875 "/usr/local/cuda3.1/cuda/bin/../include/cuda_runtime.h"
}
# 57 "/usr/include/sys/time.h" 3
extern "C" { struct timezone {
# 59 "/usr/include/sys/time.h" 3
int tz_minuteswest;
# 60 "/usr/include/sys/time.h" 3
int tz_dsttime;
# 61 "/usr/include/sys/time.h" 3
}; }
# 63 "/usr/include/sys/time.h" 3
extern "C" { typedef struct timezone *__restrict__ __timezone_ptr_t; }
# 73 "/usr/include/sys/time.h" 3
extern "C" int gettimeofday(timeval *__restrict__, __timezone_ptr_t) throw() __attribute__((nonnull(1)));
# 79 "/usr/include/sys/time.h" 3
extern "C" int settimeofday(const timeval *, const struct timezone *) throw() __attribute__((nonnull(1)));
# 87 "/usr/include/sys/time.h" 3
extern "C" int adjtime(const timeval *, timeval *) throw();
# 93 "/usr/include/sys/time.h" 3
enum __itimer_which {
# 96 "/usr/include/sys/time.h" 3
ITIMER_REAL,
# 99 "/usr/include/sys/time.h" 3
ITIMER_VIRTUAL,
# 103 "/usr/include/sys/time.h" 3
ITIMER_PROF
# 105 "/usr/include/sys/time.h" 3
};
# 109 "/usr/include/sys/time.h" 3
extern "C" { struct itimerval {
# 112 "/usr/include/sys/time.h" 3
timeval it_interval;
# 114 "/usr/include/sys/time.h" 3
timeval it_value;
# 115 "/usr/include/sys/time.h" 3
}; }
# 122 "/usr/include/sys/time.h" 3
extern "C" { typedef int __itimer_which_t; }
# 127 "/usr/include/sys/time.h" 3
extern "C" int getitimer(__itimer_which_t, itimerval *) throw();
# 133 "/usr/include/sys/time.h" 3
extern "C" int setitimer(__itimer_which_t, const itimerval *__restrict__, itimerval *__restrict__) throw();
# 140 "/usr/include/sys/time.h" 3
extern "C" int utimes(const char *, const timeval [2]) throw() __attribute__((nonnull(1)));
# 145 "/usr/include/sys/time.h" 3
extern "C" int lutimes(const char *, const timeval [2]) throw() __attribute__((nonnull(1)));
# 149 "/usr/include/sys/time.h" 3
extern "C" int futimes(int, const timeval [2]) throw();
# 156 "/usr/include/sys/time.h" 3
extern "C" int futimesat(int, const char *, const timeval [2]) throw();
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
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stdarg.h" 3
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
# 30 "ComputeBound.cu"
extern "C" void FloatComputeBound(float *
# 31 "ComputeBound.cu"
A, const float
# 32 "ComputeBound.cu"
a, const float b, const float c, const float d, const float e, bool store) ;
# 56 "ComputeBound.cu"
void run(const int M) {
# 58 "ComputeBound.cu"
float *A_gpu, *A_cpu;
# 59 "ComputeBound.cu"
const int N = 576;
# 61 "ComputeBound.cu"
const int K = (M * N);
# 62 "ComputeBound.cu"
size_t bytes = (sizeof(float) * K);
# 64 "ComputeBound.cu"
cudaMalloc((void **)(&A_gpu), bytes);
# 65 "ComputeBound.cu"
A_cpu = ((float *)malloc(bytes));
# 66 "ComputeBound.cu"
for (int i = 0; i < K; i++) {
# 67 "ComputeBound.cu"
(A_cpu[i]) = (((float)i) / ((float)(K - 1)));
# 68 "ComputeBound.cu"
}
# 69 "ComputeBound.cu"
cudaMemcpy(A_gpu, A_cpu, bytes, cudaMemcpyHostToDevice);
# 71 "ComputeBound.cu"
timeval startTime, endTime;
# 73 "ComputeBound.cu"
cudaThreadSynchronize();
# 74 "ComputeBound.cu"
gettimeofday(&startTime, 0);
# 75 "ComputeBound.cu"
cudaConfigureCall(dim3(M, 1), dim3(N, 1)) ? ((void)0) : FloatComputeBound(A_gpu, (1.125F), (0.125F), (0.5F), (1.25F), (1.25F), false);
# 76 "ComputeBound.cu"
cudaThreadSynchronize();
# 77 "ComputeBound.cu"
gettimeofday(&endTime, 0);
# 79 "ComputeBound.cu"
double ms = (((((double)(endTime.tv_sec)) - ((double)(startTime.tv_sec))) * (1000.0)) + ((((double)(endTime.tv_usec)) - ((double)(startTime.tv_usec))) / (1000.0)));
# 82 "ComputeBound.cu"
double s = (ms / (1000.0));
# 83 "ComputeBound.cu"
double GFLOPs = (((((((2 * 0) + 2048) + 2048) / (1000000.0)) * (1024)) * K) / (1000.0));
# 84 "ComputeBound.cu"
double GFLOPsPerSec = (GFLOPs / s);
# 87 "ComputeBound.cu"
printf("%d, %f\n", M, GFLOPsPerSec);
# 89 "ComputeBound.cu"
free(A_cpu);
# 90 "ComputeBound.cu"
cudaFree(A_gpu);
# 91 "ComputeBound.cu"
}
# 93 "ComputeBound.cu"
int main() {
# 94 "ComputeBound.cu"
for (int i = 1; i < 50; i++) {
# 95 "ComputeBound.cu"
run(i);
# 96 "ComputeBound.cu"
}
# 97 "ComputeBound.cu"
return 0;
# 98 "ComputeBound.cu"
}
# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c"
# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c" 1
# 1 "/tmp/tmpxft_0000092c_00000000-3_ComputeBound.fatbin.c" 1
# 1 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
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
# 152 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 166 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
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
# 203 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode,
        __cudaFatForcePTX
    } __cudaFatCompilationPolicy;
# 227 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 240 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
unsigned char fatCheckJitForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *ptx );
# 250 "/usr/local/cuda3.1/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );





void __cudaFatFreePTX( char* ptx );


}
# 2 "/tmp/tmpxft_0000092c_00000000-3_ComputeBound.fatbin.c" 2



asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$sm_10$:\n"
".quad 0x33010102464c457f,0x0000000000000002,0x0000000100be0002,0x0000000000000000\n"
".quad 0x00000000000044f8,0x0000000000000040,0x00380040000a000a,0x0001000800400003\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0000000300000001,0x0000000000000000,0x0000000000000000,0x0000000000000240\n"
".quad 0x00000000000000a6,0x0000000000000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000030000000b,0x0000000000000000,0x0000000000000000,0x00000000000002e6\n"
".quad 0x0000000000000013,0x0000000000000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x0000000200000013,0x0000000000000000,0x0000000000000000,0x00000000000002f9\n"
".quad 0x0000000000000108,0x0000000a00000002,0x0000000000000001,0x0000000000000018\n"
".quad 0x0000000100000036,0x0000000000000006,0x0000000000000000,0x0000000000000401\n"
".quad 0x00000000000040d0,0x0a00000600000003,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000006b,0x0000000000000002,0x0000000000000000,0x00000000000044d1\n"
".quad 0x0000000000000004,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x000000010000008b,0x0000000000000002,0x0000000000000000,0x00000000000044d5\n"
".quad 0x0000000000000020,0x0000000400000000,0x0000000000000001,0x0000000000000000\n"
".quad 0x000000080000004e,0x0000000000000003,0x0000000000000000,0x00000000000044f5\n"
".quad 0x000000000000002d,0x0000000400000000,0x0000000000000004,0x0000000000000000\n"
".quad 0x7472747368732e00,0x747274732e006261,0x746d79732e006261,0x672e766e2e006261\n"
".quad 0x6e692e6c61626f6c,0x672e766e2e007469,0x742e006c61626f6c,0x616f6c462e747865\n"
".quad 0x657475706d6f4374,0x6e2e00646e756f42,0x6465726168732e76,0x6f4374616f6c462e\n"
".quad 0x756f42657475706d,0x632e766e2e00646e,0x31746e6174736e6f,0x6f4374616f6c462e\n"
".quad 0x756f42657475706d,0x692e766e2e00646e,0x616f6c462e6f666e,0x657475706d6f4374\n"
".quad 0x460000646e756f42,0x706d6f4374616f6c,0x646e756f42657475,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0100030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0200030000000000,0x0000000000000000,0x0000000000000000\n"
".quad 0x0300030000000000,0x0000000000000000,0x0000000000000000,0x0000030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0000030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0400030000000000,0x0000000000000000,0x000000000040d000\n"
".quad 0x0700030000000000,0x0000000000000000,0x0000000000000000,0x0500030000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x0600030000000000,0x0000000000000000\n"
".quad 0x0000000000000000,0x0410120000000100,0x0000000000000000,0x0000000000000000\n"
".quad 0x23c7801000420500,0x000780a000000500,0x20478060014c0104,0x1007803002000100\n"
".quad 0x2007802000c81dc4,0xc00780d00e0e0904,0x03c7801000f81980,0xf80003b000040504\n"
".quad 0xf40003c00004110b,0xe80003c000042503,0xf00003c000040103,0xfa0003c000042103\n"
".quad 0x0088141000820803,0x03c7801000000d10,0x056e14c1086e2004,0x097024c1047010b1\n"
".quad 0x200780c000d201b1,0x00000320018c1900,0x016c04b103720c00,0x208780b000cc09c1\n"
".quad 0x4147c830800dfd00,0x056e14c1086e206c,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x056e14c1086e20b1,0x097024c1047010b1,0x03720cc1007200b1\n"
".quad 0x026c08c1016c04b1,0x0002801000e003b1,0x000780d000580500,0x2187c8a40001fd20\n"
".quad 0x000100300000030c,0x011004b042020400,0x010804b0450204b0,0x010000b0490204b0\n"
".quad 0x00c780b0000001b0,0xc00781d00e0e0108,0x1c0b0400000400a0,0x0000080000000000\n"
".quad 0x0000100000000c00,0x0000180000001400,0x0000000000001c00,0x0000000500000006\n"
".quad 0x00000000000044f8,0x0000000000000000,0x0000000000000000,0x00000000000000a8\n"
".quad 0x00000000000000a8,0x0000000000000004,0x00000a0560000000,0x0000000000000401\n"
".quad 0x0000000000000000,0x0000000000000000,0x00000000000040f4,0x00000000000040f4\n"
".quad 0x0000000000000004,0x00000a0660000000,0x00000000000044f5,0x0000000000000000\n"
".quad 0x0000000000000000,0x0000000000000000,0x000000000000002d,0x0000000000000004\n"
".quad 0x0000000000000000\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$sm_10$[2229];

}

asm(
".section .rodata\n"
".align 32\n"
"__deviceText_$compute_10$:\n"
".quad 0x6f69737265762e09,0x2e090a342e31206e,0x7320746567726174,0x616d202c30315f6d\n"
".quad 0x6f745f3436665f70,0x2f2f090a3233665f,0x656c69706d6f6320,0x2f20687469772064\n"
".quad 0x61636f6c2f727375,0x2e33616475632f6c,0x6f2f616475632f31,0x696c2f34366e6570\n"
".quad 0x2f090a65622f2f62,0x6e65706f766e202f,0x6220312e33206363,0x206e6f20746c6975\n"
".quad 0x2d36302d30313032,0x2d2f2f090a0a3730,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x43202f2f090a2d2d,0x676e696c69706d6f,0x6d742f706d742f20\n"
".quad 0x3030305f74667870,0x30305f6332393030,0x372d303030303030,0x657475706d6f435f\n"
".quad 0x70632e646e756f42,0x742f2820692e3370,0x23494263632f706d,0x294a4156434b522e\n"
".quad 0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2f2f090a,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d\n"
".quad 0x6974704f202f2f09,0x2f2f090a3a736e6f,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x202f2f090a2d2d2d,0x3a74656772615420,0x415349202c787470\n"
".quad 0x202c30315f6d733a,0x6c3a6e6169646e45,0x50202c656c747469,0x53207265746e696f\n"
".quad 0x090a34363a657a69,0x09334f2d20202f2f,0x7a696d6974704f28,0x656c206e6f697461\n"
".quad 0x2f2f090a296c6576,0x44280930672d2020,0x76656c2067756265,0x202f2f090a296c65\n"
".quad 0x65522809326d2d20,0x7664612074726f70,0x29736569726f7369,0x2d2d2d2d2f2f090a\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d\n"
".quad 0x2d2d2d2d2d2d2d2d,0x2d2d2d2d2d2d2d2d,0x0a2d2d2d2d2d2d2d,0x09656c69662e090a\n"
".quad 0x6d6d6f633c220931,0x656e696c2d646e61,0x6c69662e090a223e,0x6d742f2209320965\n"
".quad 0x746678706d742f70,0x323930303030305f,0x3030303030305f63,0x6d6f435f362d3030\n"
".quad 0x6e756f4265747570,0x6566616475632e64,0x090a227570672e32,0x093309656c69662e\n"
".quad 0x696c2f7273752f22,0x38782f6363672f62,0x6e696c2d34365f36,0x342f756e672d7875\n"
".quad 0x636e692f332e342e,0x6474732f6564756c,0x090a22682e666564,0x093409656c69662e\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f312e33,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x697665642f747263,0x69746e75725f6563,0x2e090a22682e656d\n"
".quad 0x22093509656c6966,0x636f6c2f7273752f,0x33616475632f6c61,0x2f616475632f312e\n"
".quad 0x692f2e2e2f6e6962,0x682f6564756c636e,0x696665645f74736f,0x090a22682e73656e\n"
".quad 0x093609656c69662e,0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f312e33\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x5f6e69746c697562,0x22682e7365707974\n"
".quad 0x09656c69662e090a,0x2f7273752f220937,0x75632f6c61636f6c,0x75632f312e336164\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65,0x682e73657079745f\n"
".quad 0x656c69662e090a22,0x7273752f22093809,0x632f6c61636f6c2f,0x632f312e33616475\n"
".quad 0x2f6e69622f616475,0x756c636e692f2e2e,0x65766972642f6564,0x2e73657079745f72\n"
".quad 0x6c69662e090a2268,0x73752f2209390965,0x2f6c61636f6c2f72,0x2f312e3361647563\n"
".quad 0x6e69622f61647563,0x6c636e692f2e2e2f,0x667275732f656475,0x657079745f656361\n"
".quad 0x662e090a22682e73,0x2209303109656c69,0x636f6c2f7273752f,0x33616475632f6c61\n"
".quad 0x2f616475632f312e,0x692f2e2e2f6e6962,0x742f6564756c636e,0x745f657275747865\n"
".quad 0x0a22682e73657079,0x3109656c69662e09,0x2f7273752f220931,0x75632f6c61636f6c\n"
".quad 0x75632f312e336164,0x2e2f6e69622f6164,0x64756c636e692f2e,0x726f746365762f65\n"
".quad 0x682e73657079745f,0x656c69662e090a22,0x73752f2209323109,0x2f6c61636f6c2f72\n"
".quad 0x2f312e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f,0x697665642f656475\n"
".quad 0x636e75616c5f6563,0x656d617261705f68,0x0a22682e73726574,0x3109656c69662e09\n"
".quad 0x2f7273752f220933,0x75632f6c61636f6c,0x75632f312e336164,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x74732f7472632f65,0x6c635f656761726f,0x090a22682e737361\n"
".quad 0x343109656c69662e,0x692f7273752f2209,0x622f6564756c636e,0x657079742f737469\n"
".quad 0x662e090a22682e73,0x2209353109656c69,0x636e692f7273752f,0x6d69742f6564756c\n"
".quad 0x662e090a22682e65,0x2209363109656c69,0x636f6c2f7273752f,0x33616475632f6c61\n"
".quad 0x2f616475632f312e,0x692f2e2e2f6e6962,0x742f6564756c636e,0x665f657275747865\n"
".quad 0x6e75665f68637465,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209373109\n"
".quad 0x2f6c61636f6c2f72,0x2f312e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x6d6d6f632f656475,0x74636e75665f6e6f,0x0a22682e736e6f69,0x3109656c69662e09\n"
".quad 0x2f7273752f220938,0x75632f6c61636f6c,0x75632f312e336164,0x2e2f6e69622f6164\n"
".quad 0x64756c636e692f2e,0x665f6874616d2f65,0x736e6f6974636e75,0x69662e090a22682e\n"
".quad 0x2f2209393109656c,0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f31\n"
".quad 0x6e692f2e2e2f6e69,0x616d2f6564756c63,0x74736e6f635f6874,0x0a22682e73746e61\n"
".quad 0x3209656c69662e09,0x2f7273752f220930,0x75632f6c61636f6c,0x75632f312e336164\n"
".quad 0x2e2f6e69622f6164,0x64756c636e692f2e,0x6563697665642f65,0x6f6974636e75665f\n"
".quad 0x2e090a22682e736e,0x09313209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163\n"
".quad 0x616475632f312e33,0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x74615f31315f6d73\n"
".quad 0x6e75665f63696d6f,0x682e736e6f697463,0x656c69662e090a22,0x73752f2209323209\n"
".quad 0x2f6c61636f6c2f72,0x2f312e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f\n"
".quad 0x315f6d732f656475,0x63696d6f74615f32,0x6f6974636e75665f,0x2e090a22682e736e\n"
".quad 0x09333209656c6966,0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f312e33\n"
".quad 0x2f2e2e2f6e69622f,0x2f6564756c636e69,0x6f645f33315f6d73,0x6e75665f656c6275\n"
".quad 0x682e736e6f697463,0x656c69662e090a22,0x73752f2209343209,0x2f6c61636f6c2f72\n"
".quad 0x2f312e3361647563,0x6e69622f61647563,0x6c636e692f2e2e2f,0x325f6d732f656475\n"
".quad 0x63696d6f74615f30,0x6f6974636e75665f,0x2e090a22682e736e,0x09353209656c6966\n"
".quad 0x6f6c2f7273752f22,0x616475632f6c6163,0x616475632f312e33,0x2f2e2e2f6e69622f\n"
".quad 0x2f6564756c636e69,0x6e695f30325f6d73,0x736369736e697274,0x69662e090a22682e\n"
".quad 0x2f2209363209656c,0x61636f6c2f727375,0x2e33616475632f6c,0x622f616475632f31\n"
".quad 0x6e692f2e2e2f6e69,0x75732f6564756c63,0x75665f6563616672,0x2e736e6f6974636e\n"
".quad 0x6c69662e090a2268,0x752f220937320965,0x6c61636f6c2f7273,0x312e33616475632f\n"
".quad 0x69622f616475632f,0x636e692f2e2e2f6e,0x74616d2f6564756c,0x6974636e75665f68\n"
".quad 0x5f6c62645f736e6f,0x0a22682e31787470,0x3209656c69662e09,0x75706d6f43220938\n"
".quad 0x2e646e756f426574,0x2e090a0a0a227563,0x6c46207972746e65,0x75706d6f4374616f\n"
".quad 0x20646e756f426574,0x7261702e09090a28,0x203436752e206d61,0x6170616475635f5f\n"
".quad 0x74616f6c465f6d72,0x42657475706d6f43,0x0a2c415f646e756f,0x6d617261702e0909\n"
".quad 0x5f5f203233662e20,0x6d72617061647563,0x6f4374616f6c465f,0x756f42657475706d\n"
".quad 0x09090a2c615f646e,0x2e206d617261702e,0x75635f5f20323366,0x465f6d7261706164\n"
".quad 0x706d6f4374616f6c,0x646e756f42657475,0x702e09090a2c625f,0x33662e206d617261\n"
".quad 0x616475635f5f2032,0x6f6c465f6d726170,0x7475706d6f437461,0x635f646e756f4265\n"
".quad 0x7261702e09090a2c,0x203233662e206d61,0x6170616475635f5f,0x74616f6c465f6d72\n"
".quad 0x42657475706d6f43,0x0a2c645f646e756f,0x6d617261702e0909,0x5f5f203233662e20\n"
".quad 0x6d72617061647563,0x6f4374616f6c465f,0x756f42657475706d,0x09090a2c655f646e\n"
".quad 0x2e206d617261702e,0x6475635f5f203873,0x6c465f6d72617061,0x75706d6f4374616f\n"
".quad 0x5f646e756f426574,0x090a2965726f7473,0x206765722e090a7b,0x687225203631752e\n"
".quad 0x722e090a3b3e343c,0x203233752e206765,0x090a3b3e393c7225,0x36752e206765722e\n"
".quad 0x3e363c6472252034,0x206765722e090a3b,0x3c6625203233662e,0x090a3b3e38313134\n"
".quad 0x72702e206765722e,0x3e343c7025206465,0x09636f6c2e090a3b,0x0a30093233093832\n"
".quad 0x6967656257444c24,0x4374616f6c465f6e,0x6f42657475706d6f,0x6c2e090a3a646e75\n"
".quad 0x363309383209636f,0x702e646c090a3009,0x3436752e6d617261,0x202c316472250920\n"
".quad 0x70616475635f5f5b,0x616f6c465f6d7261,0x657475706d6f4374,0x5d415f646e756f42\n"
".quad 0x752e747663090a3b,0x09203631752e3233,0x697425202c317225,0x6f6d090a3b782e64\n"
".quad 0x2509203631752e76,0x746325202c316872,0x090a3b782e646961,0x203631752e766f6d\n"
".quad 0x25202c3268722509,0x0a3b782e6469746e,0x6469772e6c756d09,0x2509203631752e65\n"
".quad 0x31687225202c3272,0x0a3b32687225202c,0x3233752e64646109,0x25202c3372250920\n"
".quad 0x3b327225202c3172,0x36732e747663090a,0x2509203233732e34,0x337225202c326472\n"
".quad 0x772e6c756d090a3b,0x203233732e656469,0x25202c3364722509,0x090a3b34202c3372\n"
".quad 0x203436752e646461,0x25202c3464722509,0x647225202c316472,0x672e646c090a3b33\n"
".quad 0x33662e6c61626f6c,0x202c316625092032,0x5d302b346472255b,0x662e766f6d090a3b\n"
".quad 0x2c32662509203233,0x3030386662663020,0x202020203b303030,0x0a312d202f2f0920\n"
".quad 0x3233662e64646109,0x25202c3366250920,0x3b326625202c3166,0x33662e766f6d090a\n"
".quad 0x202c346625092032,0x6c2e090a3b336625,0x373309383209636f,0x2e766f6d090a3009\n"
".quad 0x3566250920323366,0x303466336630202c,0x2020203b30303030,0x2e30202f2f092020\n"
".quad 0x2e6c756d090a3537,0x3666250920323366,0x25202c316625202c,0x766f6d090a3b3566\n"
".quad 0x662509203233662e,0x0a3b366625202c37,0x383209636f6c2e09,0x6d090a3009383309\n"
".quad 0x09203233662e766f,0x336630202c386625,0x3b30303030303865,0x2f2f092020202020\n"
".quad 0x6d090a35322e3020,0x09203233662e6c75,0x316625202c396625,0x090a3b386625202c\n"
".quad 0x09383209636f6c2e,0x6f6d090a30093933,0x2509203233662e76,0x336630202c303166\n"
".quad 0x3b30303030303066,0x202f2f0920202020,0x6c756d090a352e30,0x662509203233662e\n"
".quad 0x2c316625202c3131,0x090a3b3031662520,0x203233662e766f6d,0x25202c3231662509\n"
".quad 0x6c2e090a3b313166,0x313409383209636f,0x2e766f6d090a3009,0x3166250920323366\n"
".quad 0x0a3b336625202c33,0x383209636f6c2e09,0x6d090a3009323409,0x09203233662e766f\n"
".quad 0x6630202c34316625,0x3030303030616633,0x2f2f09202020203b,0x6d090a35322e3120\n"
".quad 0x09203233662e6c75,0x6625202c35316625,0x3b34316625202c31,0x3209636f6c2e090a\n"
".quad 0x090a300933340938,0x203233662e766f6d,0x25202c3631662509,0x6f6c2e090a3b3666\n"
".quad 0x0934340938320963,0x662e766f6d090a30,0x3731662509203233,0x0a3b31316625202c\n"
".quad 0x617261702e646c09,0x2509203233662e6d,0x5f5f5b202c383166,0x6d72617061647563\n"
".quad 0x6f4374616f6c465f,0x756f42657475706d,0x090a3b5d645f646e,0x6d617261702e646c\n"
".quad 0x662509203233662e,0x635f5f5b202c3931,0x5f6d726170616475,0x6d6f4374616f6c46\n"
".quad 0x6e756f4265747570,0x6c090a3b5d635f64,0x2e6d617261702e64,0x3266250920323366\n"
".quad 0x75635f5f5b202c30,0x465f6d7261706164,0x706d6f4374616f6c,0x646e756f42657475\n"
".quad 0x646c090a3b5d625f,0x662e6d617261702e,0x3132662509203233,0x6475635f5f5b202c\n"
".quad 0x6c465f6d72617061,0x75706d6f4374616f,0x5f646e756f426574,0x766f6d090a3b5d61\n"
".quad 0x722509203233732e,0x4c240a3b30202c34,0x323635325f305f74,0x6f6c3c2f2f200a3a\n"
".quad 0x706f6f4c203e706f,0x696c2079646f6220,0x6e202c343420656e,0x6420676e69747365\n"
".quad 0x2c31203a68747065,0x6974617265746920,0x323031203a736e6f,0x61702e646c090a34\n"
".quad 0x203233662e6d6172,0x5b202c3132662509,0x6170616475635f5f,0x74616f6c465f6d72\n"
".quad 0x42657475706d6f43,0x3b5d615f646e756f,0x3209636f6c2e090a,0x090a300937340938\n"
".quad 0x203233662e6c756d,0x25202c3232662509,0x326625202c333166,0x2e646461090a3b31\n"
".quad 0x3266250920323366,0x202c346625202c33,0x2e090a3b31326625,0x3409383209636f6c\n"
".quad 0x2e646c090a300934,0x33662e6d61726170,0x2c30326625092032,0x616475635f5f5b20\n"
".quad 0x6f6c465f6d726170,0x7475706d6f437461,0x625f646e756f4265,0x636f6c2e090a3b5d\n"
".quad 0x3009373409383209,0x33662e6c756d090a,0x2c34326625092032,0x25202c3531662520\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x376625202c353266,0x0a3b30326625202c\n"
".quad 0x383209636f6c2e09,0x6c090a3009343409,0x2e6d617261702e64,0x3166250920323366\n"
".quad 0x75635f5f5b202c39,0x465f6d7261706164,0x706d6f4374616f6c,0x646e756f42657475\n"
".quad 0x6c2e090a3b5d635f,0x373409383209636f,0x2e6c756d090a3009,0x3266250920323366\n"
".quad 0x2c36316625202c36,0x090a3b3931662520,0x203233662e646461,0x25202c3732662509\n"
".quad 0x39316625202c3966,0x09636f6c2e090a3b,0x0a30093434093832,0x617261702e646c09\n"
".quad 0x2509203233662e6d,0x5f5f5b202c383166,0x6d72617061647563,0x6f4374616f6c465f\n"
".quad 0x756f42657475706d,0x090a3b5d645f646e,0x09383209636f6c2e,0x756d090a30093734\n"
".quad 0x2509203233662e6c,0x316625202c383266,0x3b38316625202c37,0x33662e646461090a\n"
".quad 0x2c39326625092032,0x25202c3231662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x326625202c303366,0x3b31326625202c32,0x33662e646461090a,0x2c31336625092032\n"
".quad 0x25202c3332662520,0x756d090a3b313266,0x2509203233662e6c,0x326625202c323366\n"
".quad 0x3b30326625202c34,0x33662e646461090a,0x2c33336625092032,0x25202c3532662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x326625202c343366,0x3b39316625202c36\n"
".quad 0x33662e646461090a,0x2c35336625092032,0x25202c3732662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x326625202c363366,0x3b38316625202c38,0x33662e646461090a\n"
".quad 0x2c37336625092032,0x25202c3932662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x336625202c383366,0x3b31326625202c30,0x33662e646461090a,0x2c39336625092032\n"
".quad 0x25202c3133662520,0x756d090a3b313266,0x2509203233662e6c,0x336625202c303466\n"
".quad 0x3b30326625202c32,0x33662e646461090a,0x2c31346625092032,0x25202c3333662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x336625202c323466,0x3b39316625202c34\n"
".quad 0x33662e646461090a,0x2c33346625092032,0x25202c3533662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x336625202c343466,0x3b38316625202c36,0x33662e646461090a\n"
".quad 0x2c35346625092032,0x25202c3733662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x336625202c363466,0x3b31326625202c38,0x33662e646461090a,0x2c37346625092032\n"
".quad 0x25202c3933662520,0x756d090a3b313266,0x2509203233662e6c,0x346625202c383466\n"
".quad 0x3b30326625202c30,0x33662e646461090a,0x2c39346625092032,0x25202c3134662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x346625202c303566,0x3b39316625202c32\n"
".quad 0x33662e646461090a,0x2c31356625092032,0x25202c3334662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x346625202c323566,0x3b38316625202c34,0x33662e646461090a\n"
".quad 0x2c33356625092032,0x25202c3534662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x346625202c343566,0x3b31326625202c36,0x33662e646461090a,0x2c35356625092032\n"
".quad 0x25202c3734662520,0x756d090a3b313266,0x2509203233662e6c,0x346625202c363566\n"
".quad 0x3b30326625202c38,0x33662e646461090a,0x2c37356625092032,0x25202c3934662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x356625202c383566,0x3b39316625202c30\n"
".quad 0x33662e646461090a,0x2c39356625092032,0x25202c3135662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x356625202c303666,0x3b38316625202c32,0x33662e646461090a\n"
".quad 0x2c31366625092032,0x25202c3335662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x356625202c323666,0x3b31326625202c34,0x33662e646461090a,0x2c33366625092032\n"
".quad 0x25202c3535662520,0x756d090a3b313266,0x2509203233662e6c,0x356625202c343666\n"
".quad 0x3b30326625202c36,0x33662e646461090a,0x2c35366625092032,0x25202c3735662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x356625202c363666,0x3b39316625202c38\n"
".quad 0x33662e646461090a,0x2c37366625092032,0x25202c3935662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x366625202c383666,0x3b38316625202c30,0x33662e646461090a\n"
".quad 0x2c39366625092032,0x25202c3136662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x366625202c303766,0x3b31326625202c32,0x33662e646461090a,0x2c31376625092032\n"
".quad 0x25202c3336662520,0x756d090a3b313266,0x2509203233662e6c,0x366625202c323766\n"
".quad 0x3b30326625202c34,0x33662e646461090a,0x2c33376625092032,0x25202c3536662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x366625202c343766,0x3b39316625202c36\n"
".quad 0x33662e646461090a,0x2c35376625092032,0x25202c3736662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x366625202c363766,0x3b38316625202c38,0x33662e646461090a\n"
".quad 0x2c37376625092032,0x25202c3936662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x376625202c383766,0x3b31326625202c30,0x33662e646461090a,0x2c39376625092032\n"
".quad 0x25202c3137662520,0x756d090a3b313266,0x2509203233662e6c,0x376625202c303866\n"
".quad 0x3b30326625202c32,0x33662e646461090a,0x2c31386625092032,0x25202c3337662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x376625202c323866,0x3b39316625202c34\n"
".quad 0x33662e646461090a,0x2c33386625092032,0x25202c3537662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x376625202c343866,0x3b38316625202c36,0x33662e646461090a\n"
".quad 0x2c35386625092032,0x25202c3737662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x376625202c363866,0x3b31326625202c38,0x33662e646461090a,0x2c37386625092032\n"
".quad 0x25202c3937662520,0x756d090a3b313266,0x2509203233662e6c,0x386625202c383866\n"
".quad 0x3b30326625202c30,0x33662e646461090a,0x2c39386625092032,0x25202c3138662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x386625202c303966,0x3b39316625202c32\n"
".quad 0x33662e646461090a,0x2c31396625092032,0x25202c3338662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x386625202c323966,0x3b38316625202c34,0x33662e646461090a\n"
".quad 0x2c33396625092032,0x25202c3538662520,0x756d090a3b383166,0x2509203233662e6c\n"
".quad 0x386625202c343966,0x3b31326625202c36,0x33662e646461090a,0x2c35396625092032\n"
".quad 0x25202c3738662520,0x756d090a3b313266,0x2509203233662e6c,0x386625202c363966\n"
".quad 0x3b30326625202c38,0x33662e646461090a,0x2c37396625092032,0x25202c3938662520\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x396625202c383966,0x3b39316625202c30\n"
".quad 0x33662e646461090a,0x2c39396625092032,0x25202c3139662520,0x756d090a3b393166\n"
".quad 0x2509203233662e6c,0x6625202c30303166,0x38316625202c3239,0x662e646461090a3b\n"
".quad 0x3031662509203233,0x2c33396625202c31,0x090a3b3831662520,0x203233662e6c756d\n"
".quad 0x202c323031662509,0x6625202c34396625,0x646461090a3b3132,0x662509203233662e\n"
".quad 0x396625202c333031,0x3b31326625202c35,0x33662e6c756d090a,0x3430316625092032\n"
".quad 0x202c36396625202c,0x61090a3b30326625,0x09203233662e6464,0x25202c3530316625\n"
".quad 0x326625202c373966,0x2e6c756d090a3b30,0x3166250920323366,0x38396625202c3630\n"
".quad 0x0a3b39316625202c,0x3233662e64646109,0x2c37303166250920,0x25202c3939662520\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38303166,0x316625202c303031\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x30316625202c3930,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3031316625092032,0x2c3230316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313131662509,0x25202c3330316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32313166,0x326625202c343031,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x30316625202c3331,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3431316625092032,0x2c3630316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353131662509,0x25202c3730316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36313166,0x316625202c383031,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x30316625202c3731,0x3b38316625202c39,0x33662e6c756d090a,0x3831316625092032\n"
".quad 0x2c3031316625202c,0x090a3b3132662520,0x203233662e646461,0x202c393131662509\n"
".quad 0x25202c3131316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30323166\n"
".quad 0x326625202c323131,0x2e646461090a3b30,0x3166250920323366,0x31316625202c3132\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3232316625092032,0x2c3431316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333231662509,0x25202c3531316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34323166,0x316625202c363131\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x31316625202c3532,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3632316625092032,0x2c3831316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373231662509,0x25202c3931316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38323166,0x326625202c303231,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x32316625202c3932,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3033316625092032,0x2c3232316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313331662509,0x25202c3332316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32333166,0x316625202c343231,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x32316625202c3333,0x3b38316625202c35,0x33662e6c756d090a,0x3433316625092032\n"
".quad 0x2c3632316625202c,0x090a3b3132662520,0x203233662e646461,0x202c353331662509\n"
".quad 0x25202c3732316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36333166\n"
".quad 0x326625202c383231,0x2e646461090a3b30,0x3166250920323366,0x32316625202c3733\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3833316625092032,0x2c3033316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393331662509,0x25202c3133316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30343166,0x316625202c323331\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x33316625202c3134,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3234316625092032,0x2c3433316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333431662509,0x25202c3533316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34343166,0x326625202c363331,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x33316625202c3534,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3634316625092032,0x2c3833316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373431662509,0x25202c3933316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38343166,0x316625202c303431,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x34316625202c3934,0x3b38316625202c31,0x33662e6c756d090a,0x3035316625092032\n"
".quad 0x2c3234316625202c,0x090a3b3132662520,0x203233662e646461,0x202c313531662509\n"
".quad 0x25202c3334316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32353166\n"
".quad 0x326625202c343431,0x2e646461090a3b30,0x3166250920323366,0x34316625202c3335\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3435316625092032,0x2c3634316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353531662509,0x25202c3734316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36353166,0x316625202c383431\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x34316625202c3735,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3835316625092032,0x2c3035316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393531662509,0x25202c3135316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30363166,0x326625202c323531,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x35316625202c3136,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3236316625092032,0x2c3435316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333631662509,0x25202c3535316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34363166,0x316625202c363531,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x35316625202c3536,0x3b38316625202c37,0x33662e6c756d090a,0x3636316625092032\n"
".quad 0x2c3835316625202c,0x090a3b3132662520,0x203233662e646461,0x202c373631662509\n"
".quad 0x25202c3935316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38363166\n"
".quad 0x326625202c303631,0x2e646461090a3b30,0x3166250920323366,0x36316625202c3936\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3037316625092032,0x2c3236316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313731662509,0x25202c3336316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32373166,0x316625202c343631\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x36316625202c3337,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3437316625092032,0x2c3636316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353731662509,0x25202c3736316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36373166,0x326625202c383631,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x36316625202c3737,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3837316625092032,0x2c3037316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393731662509,0x25202c3137316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30383166,0x316625202c323731,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x37316625202c3138,0x3b38316625202c33,0x33662e6c756d090a,0x3238316625092032\n"
".quad 0x2c3437316625202c,0x090a3b3132662520,0x203233662e646461,0x202c333831662509\n"
".quad 0x25202c3537316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34383166\n"
".quad 0x326625202c363731,0x2e646461090a3b30,0x3166250920323366,0x37316625202c3538\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3638316625092032,0x2c3837316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373831662509,0x25202c3937316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38383166,0x316625202c303831\n"
".quad 0x2e646461090a3b38,0x3166250920323366,0x38316625202c3938,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3039316625092032,0x2c3238316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313931662509,0x25202c3338316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32393166,0x326625202c343831,0x2e646461090a3b30\n"
".quad 0x3166250920323366,0x38316625202c3339,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3439316625092032,0x2c3638316625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353931662509,0x25202c3738316625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36393166,0x316625202c383831,0x2e646461090a3b38,0x3166250920323366\n"
".quad 0x38316625202c3739,0x3b38316625202c39,0x33662e6c756d090a,0x3839316625092032\n"
".quad 0x2c3039316625202c,0x090a3b3132662520,0x203233662e646461,0x202c393931662509\n"
".quad 0x25202c3139316625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30303266\n"
".quad 0x326625202c323931,0x2e646461090a3b30,0x3266250920323366,0x39316625202c3130\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3230326625092032,0x2c3439316625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333032662509,0x25202c3539316625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34303266,0x316625202c363931\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x39316625202c3530,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3630326625092032,0x2c3839316625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373032662509,0x25202c3939316625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38303266,0x326625202c303032,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x30326625202c3930,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3031326625092032,0x2c3230326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313132662509,0x25202c3330326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32313266,0x316625202c343032,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x30326625202c3331,0x3b38316625202c35,0x33662e6c756d090a,0x3431326625092032\n"
".quad 0x2c3630326625202c,0x090a3b3132662520,0x203233662e646461,0x202c353132662509\n"
".quad 0x25202c3730326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36313266\n"
".quad 0x326625202c383032,0x2e646461090a3b30,0x3266250920323366,0x30326625202c3731\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3831326625092032,0x2c3031326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393132662509,0x25202c3131326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30323266,0x316625202c323132\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x31326625202c3132,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3232326625092032,0x2c3431326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333232662509,0x25202c3531326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34323266,0x326625202c363132,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x31326625202c3532,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3632326625092032,0x2c3831326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373232662509,0x25202c3931326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38323266,0x316625202c303232,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x32326625202c3932,0x3b38316625202c31,0x33662e6c756d090a,0x3033326625092032\n"
".quad 0x2c3232326625202c,0x090a3b3132662520,0x203233662e646461,0x202c313332662509\n"
".quad 0x25202c3332326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32333266\n"
".quad 0x326625202c343232,0x2e646461090a3b30,0x3266250920323366,0x32326625202c3333\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3433326625092032,0x2c3632326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353332662509,0x25202c3732326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36333266,0x316625202c383232\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x32326625202c3733,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3833326625092032,0x2c3033326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393332662509,0x25202c3133326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30343266,0x326625202c323332,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x33326625202c3134,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3234326625092032,0x2c3433326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333432662509,0x25202c3533326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34343266,0x316625202c363332,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x33326625202c3534,0x3b38316625202c37,0x33662e6c756d090a,0x3634326625092032\n"
".quad 0x2c3833326625202c,0x090a3b3132662520,0x203233662e646461,0x202c373432662509\n"
".quad 0x25202c3933326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38343266\n"
".quad 0x326625202c303432,0x2e646461090a3b30,0x3266250920323366,0x34326625202c3934\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3035326625092032,0x2c3234326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313532662509,0x25202c3334326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32353266,0x316625202c343432\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x34326625202c3335,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3435326625092032,0x2c3634326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353532662509,0x25202c3734326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36353266,0x326625202c383432,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x34326625202c3735,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3835326625092032,0x2c3035326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393532662509,0x25202c3135326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30363266,0x316625202c323532,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x35326625202c3136,0x3b38316625202c33,0x33662e6c756d090a,0x3236326625092032\n"
".quad 0x2c3435326625202c,0x090a3b3132662520,0x203233662e646461,0x202c333632662509\n"
".quad 0x25202c3535326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34363266\n"
".quad 0x326625202c363532,0x2e646461090a3b30,0x3266250920323366,0x35326625202c3536\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3636326625092032,0x2c3835326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373632662509,0x25202c3935326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38363266,0x316625202c303632\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x36326625202c3936,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3037326625092032,0x2c3236326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313732662509,0x25202c3336326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32373266,0x326625202c343632,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x36326625202c3337,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3437326625092032,0x2c3636326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353732662509,0x25202c3736326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36373266,0x316625202c383632,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x36326625202c3737,0x3b38316625202c39,0x33662e6c756d090a,0x3837326625092032\n"
".quad 0x2c3037326625202c,0x090a3b3132662520,0x203233662e646461,0x202c393732662509\n"
".quad 0x25202c3137326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30383266\n"
".quad 0x326625202c323732,0x2e646461090a3b30,0x3266250920323366,0x37326625202c3138\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3238326625092032,0x2c3437326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333832662509,0x25202c3537326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34383266,0x316625202c363732\n"
".quad 0x2e646461090a3b38,0x3266250920323366,0x37326625202c3538,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3638326625092032,0x2c3837326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373832662509,0x25202c3937326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38383266,0x326625202c303832,0x2e646461090a3b30\n"
".quad 0x3266250920323366,0x38326625202c3938,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3039326625092032,0x2c3238326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313932662509,0x25202c3338326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32393266,0x316625202c343832,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x38326625202c3339,0x3b38316625202c35,0x33662e6c756d090a,0x3439326625092032\n"
".quad 0x2c3638326625202c,0x090a3b3132662520,0x203233662e646461,0x202c353932662509\n"
".quad 0x25202c3738326625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36393266\n"
".quad 0x326625202c383832,0x2e646461090a3b30,0x3266250920323366,0x38326625202c3739\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3839326625092032,0x2c3039326625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393932662509,0x25202c3139326625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30303366,0x316625202c323932\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x39326625202c3130,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3230336625092032,0x2c3439326625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333033662509,0x25202c3539326625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34303366,0x326625202c363932,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x39326625202c3530,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3630336625092032,0x2c3839326625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373033662509,0x25202c3939326625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38303366,0x316625202c303033,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x30336625202c3930,0x3b38316625202c31,0x33662e6c756d090a,0x3031336625092032\n"
".quad 0x2c3230336625202c,0x090a3b3132662520,0x203233662e646461,0x202c313133662509\n"
".quad 0x25202c3330336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32313366\n"
".quad 0x326625202c343033,0x2e646461090a3b30,0x3366250920323366,0x30336625202c3331\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3431336625092032,0x2c3630336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353133662509,0x25202c3730336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36313366,0x316625202c383033\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x30336625202c3731,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3831336625092032,0x2c3031336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393133662509,0x25202c3131336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30323366,0x326625202c323133,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x31336625202c3132,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3232336625092032,0x2c3431336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333233662509,0x25202c3531336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34323366,0x316625202c363133,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x31336625202c3532,0x3b38316625202c37,0x33662e6c756d090a,0x3632336625092032\n"
".quad 0x2c3831336625202c,0x090a3b3132662520,0x203233662e646461,0x202c373233662509\n"
".quad 0x25202c3931336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38323366\n"
".quad 0x326625202c303233,0x2e646461090a3b30,0x3366250920323366,0x32336625202c3932\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3033336625092032,0x2c3232336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313333662509,0x25202c3332336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32333366,0x316625202c343233\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x32336625202c3333,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3433336625092032,0x2c3632336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353333662509,0x25202c3732336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36333366,0x326625202c383233,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x32336625202c3733,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3833336625092032,0x2c3033336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393333662509,0x25202c3133336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30343366,0x316625202c323333,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x33336625202c3134,0x3b38316625202c33,0x33662e6c756d090a,0x3234336625092032\n"
".quad 0x2c3433336625202c,0x090a3b3132662520,0x203233662e646461,0x202c333433662509\n"
".quad 0x25202c3533336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34343366\n"
".quad 0x326625202c363333,0x2e646461090a3b30,0x3366250920323366,0x33336625202c3534\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3634336625092032,0x2c3833336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373433662509,0x25202c3933336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38343366,0x316625202c303433\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x34336625202c3934,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3035336625092032,0x2c3234336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313533662509,0x25202c3334336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32353366,0x326625202c343433,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x34336625202c3335,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3435336625092032,0x2c3634336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353533662509,0x25202c3734336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36353366,0x316625202c383433,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x34336625202c3735,0x3b38316625202c39,0x33662e6c756d090a,0x3835336625092032\n"
".quad 0x2c3035336625202c,0x090a3b3132662520,0x203233662e646461,0x202c393533662509\n"
".quad 0x25202c3135336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30363366\n"
".quad 0x326625202c323533,0x2e646461090a3b30,0x3366250920323366,0x35336625202c3136\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3236336625092032,0x2c3435336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333633662509,0x25202c3535336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34363366,0x316625202c363533\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x35336625202c3536,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3636336625092032,0x2c3835336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373633662509,0x25202c3935336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38363366,0x326625202c303633,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x36336625202c3936,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3037336625092032,0x2c3236336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313733662509,0x25202c3336336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32373366,0x316625202c343633,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x36336625202c3337,0x3b38316625202c35,0x33662e6c756d090a,0x3437336625092032\n"
".quad 0x2c3636336625202c,0x090a3b3132662520,0x203233662e646461,0x202c353733662509\n"
".quad 0x25202c3736336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36373366\n"
".quad 0x326625202c383633,0x2e646461090a3b30,0x3366250920323366,0x36336625202c3737\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3837336625092032,0x2c3037336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393733662509,0x25202c3137336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30383366,0x316625202c323733\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x37336625202c3138,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3238336625092032,0x2c3437336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333833662509,0x25202c3537336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34383366,0x326625202c363733,0x2e646461090a3b30\n"
".quad 0x3366250920323366,0x37336625202c3538,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3638336625092032,0x2c3837336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373833662509,0x25202c3937336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38383366,0x316625202c303833,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x38336625202c3938,0x3b38316625202c31,0x33662e6c756d090a,0x3039336625092032\n"
".quad 0x2c3238336625202c,0x090a3b3132662520,0x203233662e646461,0x202c313933662509\n"
".quad 0x25202c3338336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32393366\n"
".quad 0x326625202c343833,0x2e646461090a3b30,0x3366250920323366,0x38336625202c3339\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3439336625092032,0x2c3638336625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353933662509,0x25202c3738336625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36393366,0x316625202c383833\n"
".quad 0x2e646461090a3b38,0x3366250920323366,0x38336625202c3739,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3839336625092032,0x2c3039336625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393933662509,0x25202c3139336625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30303466,0x326625202c323933,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x39336625202c3130,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3230346625092032,0x2c3439336625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333034662509,0x25202c3539336625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34303466,0x316625202c363933,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x39336625202c3530,0x3b38316625202c37,0x33662e6c756d090a,0x3630346625092032\n"
".quad 0x2c3839336625202c,0x090a3b3132662520,0x203233662e646461,0x202c373034662509\n"
".quad 0x25202c3939336625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38303466\n"
".quad 0x326625202c303034,0x2e646461090a3b30,0x3466250920323366,0x30346625202c3930\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3031346625092032,0x2c3230346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313134662509,0x25202c3330346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32313466,0x316625202c343034\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x30346625202c3331,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3431346625092032,0x2c3630346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353134662509,0x25202c3730346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36313466,0x326625202c383034,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x30346625202c3731,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3831346625092032,0x2c3031346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393134662509,0x25202c3131346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30323466,0x316625202c323134,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x31346625202c3132,0x3b38316625202c33,0x33662e6c756d090a,0x3232346625092032\n"
".quad 0x2c3431346625202c,0x090a3b3132662520,0x203233662e646461,0x202c333234662509\n"
".quad 0x25202c3531346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34323466\n"
".quad 0x326625202c363134,0x2e646461090a3b30,0x3466250920323366,0x31346625202c3532\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3632346625092032,0x2c3831346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373234662509,0x25202c3931346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38323466,0x316625202c303234\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x32346625202c3932,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3033346625092032,0x2c3232346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313334662509,0x25202c3332346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32333466,0x326625202c343234,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x32346625202c3333,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3433346625092032,0x2c3632346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353334662509,0x25202c3732346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36333466,0x316625202c383234,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x32346625202c3733,0x3b38316625202c39,0x33662e6c756d090a,0x3833346625092032\n"
".quad 0x2c3033346625202c,0x090a3b3132662520,0x203233662e646461,0x202c393334662509\n"
".quad 0x25202c3133346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30343466\n"
".quad 0x326625202c323334,0x2e646461090a3b30,0x3466250920323366,0x33346625202c3134\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3234346625092032,0x2c3433346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333434662509,0x25202c3533346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34343466,0x316625202c363334\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x33346625202c3534,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3634346625092032,0x2c3833346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373434662509,0x25202c3933346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38343466,0x326625202c303434,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x34346625202c3934,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3035346625092032,0x2c3234346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313534662509,0x25202c3334346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32353466,0x316625202c343434,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x34346625202c3335,0x3b38316625202c35,0x33662e6c756d090a,0x3435346625092032\n"
".quad 0x2c3634346625202c,0x090a3b3132662520,0x203233662e646461,0x202c353534662509\n"
".quad 0x25202c3734346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36353466\n"
".quad 0x326625202c383434,0x2e646461090a3b30,0x3466250920323366,0x34346625202c3735\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3835346625092032,0x2c3035346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393534662509,0x25202c3135346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30363466,0x316625202c323534\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x35346625202c3136,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3236346625092032,0x2c3435346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333634662509,0x25202c3535346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34363466,0x326625202c363534,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x35346625202c3536,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3636346625092032,0x2c3835346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373634662509,0x25202c3935346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38363466,0x316625202c303634,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x36346625202c3936,0x3b38316625202c31,0x33662e6c756d090a,0x3037346625092032\n"
".quad 0x2c3236346625202c,0x090a3b3132662520,0x203233662e646461,0x202c313734662509\n"
".quad 0x25202c3336346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32373466\n"
".quad 0x326625202c343634,0x2e646461090a3b30,0x3466250920323366,0x36346625202c3337\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3437346625092032,0x2c3636346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353734662509,0x25202c3736346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36373466,0x316625202c383634\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x36346625202c3737,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3837346625092032,0x2c3037346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393734662509,0x25202c3137346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30383466,0x326625202c323734,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x37346625202c3138,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3238346625092032,0x2c3437346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333834662509,0x25202c3537346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34383466,0x316625202c363734,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x37346625202c3538,0x3b38316625202c37,0x33662e6c756d090a,0x3638346625092032\n"
".quad 0x2c3837346625202c,0x090a3b3132662520,0x203233662e646461,0x202c373834662509\n"
".quad 0x25202c3937346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38383466\n"
".quad 0x326625202c303834,0x2e646461090a3b30,0x3466250920323366,0x38346625202c3938\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3039346625092032,0x2c3238346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313934662509,0x25202c3338346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32393466,0x316625202c343834\n"
".quad 0x2e646461090a3b38,0x3466250920323366,0x38346625202c3339,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3439346625092032,0x2c3638346625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353934662509,0x25202c3738346625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36393466,0x326625202c383834,0x2e646461090a3b30\n"
".quad 0x3466250920323366,0x38346625202c3739,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3839346625092032,0x2c3039346625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393934662509,0x25202c3139346625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30303566,0x316625202c323934,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x39346625202c3130,0x3b38316625202c33,0x33662e6c756d090a,0x3230356625092032\n"
".quad 0x2c3439346625202c,0x090a3b3132662520,0x203233662e646461,0x202c333035662509\n"
".quad 0x25202c3539346625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34303566\n"
".quad 0x326625202c363934,0x2e646461090a3b30,0x3566250920323366,0x39346625202c3530\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3630356625092032,0x2c3839346625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373035662509,0x25202c3939346625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38303566,0x316625202c303035\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x30356625202c3930,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3031356625092032,0x2c3230356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313135662509,0x25202c3330356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32313566,0x326625202c343035,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x30356625202c3331,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3431356625092032,0x2c3630356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353135662509,0x25202c3730356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36313566,0x316625202c383035,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x30356625202c3731,0x3b38316625202c39,0x33662e6c756d090a,0x3831356625092032\n"
".quad 0x2c3031356625202c,0x090a3b3132662520,0x203233662e646461,0x202c393135662509\n"
".quad 0x25202c3131356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30323566\n"
".quad 0x326625202c323135,0x2e646461090a3b30,0x3566250920323366,0x31356625202c3132\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3232356625092032,0x2c3431356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333235662509,0x25202c3531356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34323566,0x316625202c363135\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x31356625202c3532,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3632356625092032,0x2c3831356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373235662509,0x25202c3931356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38323566,0x326625202c303235,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x32356625202c3932,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3033356625092032,0x2c3232356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313335662509,0x25202c3332356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32333566,0x316625202c343235,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x32356625202c3333,0x3b38316625202c35,0x33662e6c756d090a,0x3433356625092032\n"
".quad 0x2c3632356625202c,0x090a3b3132662520,0x203233662e646461,0x202c353335662509\n"
".quad 0x25202c3732356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36333566\n"
".quad 0x326625202c383235,0x2e646461090a3b30,0x3566250920323366,0x32356625202c3733\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3833356625092032,0x2c3033356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393335662509,0x25202c3133356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30343566,0x316625202c323335\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x33356625202c3134,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3234356625092032,0x2c3433356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333435662509,0x25202c3533356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34343566,0x326625202c363335,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x33356625202c3534,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3634356625092032,0x2c3833356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373435662509,0x25202c3933356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38343566,0x316625202c303435,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x34356625202c3934,0x3b38316625202c31,0x33662e6c756d090a,0x3035356625092032\n"
".quad 0x2c3234356625202c,0x090a3b3132662520,0x203233662e646461,0x202c313535662509\n"
".quad 0x25202c3334356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32353566\n"
".quad 0x326625202c343435,0x2e646461090a3b30,0x3566250920323366,0x34356625202c3335\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3435356625092032,0x2c3634356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353535662509,0x25202c3734356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36353566,0x316625202c383435\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x34356625202c3735,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3835356625092032,0x2c3035356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393535662509,0x25202c3135356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30363566,0x326625202c323535,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x35356625202c3136,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3236356625092032,0x2c3435356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333635662509,0x25202c3535356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34363566,0x316625202c363535,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x35356625202c3536,0x3b38316625202c37,0x33662e6c756d090a,0x3636356625092032\n"
".quad 0x2c3835356625202c,0x090a3b3132662520,0x203233662e646461,0x202c373635662509\n"
".quad 0x25202c3935356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38363566\n"
".quad 0x326625202c303635,0x2e646461090a3b30,0x3566250920323366,0x36356625202c3936\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3037356625092032,0x2c3236356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313735662509,0x25202c3336356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32373566,0x316625202c343635\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x36356625202c3337,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3437356625092032,0x2c3636356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353735662509,0x25202c3736356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36373566,0x326625202c383635,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x36356625202c3737,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3837356625092032,0x2c3037356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393735662509,0x25202c3137356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30383566,0x316625202c323735,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x37356625202c3138,0x3b38316625202c33,0x33662e6c756d090a,0x3238356625092032\n"
".quad 0x2c3437356625202c,0x090a3b3132662520,0x203233662e646461,0x202c333835662509\n"
".quad 0x25202c3537356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34383566\n"
".quad 0x326625202c363735,0x2e646461090a3b30,0x3566250920323366,0x37356625202c3538\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3638356625092032,0x2c3837356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373835662509,0x25202c3937356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38383566,0x316625202c303835\n"
".quad 0x2e646461090a3b38,0x3566250920323366,0x38356625202c3938,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3039356625092032,0x2c3238356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313935662509,0x25202c3338356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32393566,0x326625202c343835,0x2e646461090a3b30\n"
".quad 0x3566250920323366,0x38356625202c3339,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3439356625092032,0x2c3638356625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353935662509,0x25202c3738356625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36393566,0x316625202c383835,0x2e646461090a3b38,0x3566250920323366\n"
".quad 0x38356625202c3739,0x3b38316625202c39,0x33662e6c756d090a,0x3839356625092032\n"
".quad 0x2c3039356625202c,0x090a3b3132662520,0x203233662e646461,0x202c393935662509\n"
".quad 0x25202c3139356625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30303666\n"
".quad 0x326625202c323935,0x2e646461090a3b30,0x3666250920323366,0x39356625202c3130\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3230366625092032,0x2c3439356625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333036662509,0x25202c3539356625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34303666,0x316625202c363935\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x39356625202c3530,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3630366625092032,0x2c3839356625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373036662509,0x25202c3939356625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38303666,0x326625202c303036,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x30366625202c3930,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3031366625092032,0x2c3230366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313136662509,0x25202c3330366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32313666,0x316625202c343036,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x30366625202c3331,0x3b38316625202c35,0x33662e6c756d090a,0x3431366625092032\n"
".quad 0x2c3630366625202c,0x090a3b3132662520,0x203233662e646461,0x202c353136662509\n"
".quad 0x25202c3730366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36313666\n"
".quad 0x326625202c383036,0x2e646461090a3b30,0x3666250920323366,0x30366625202c3731\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3831366625092032,0x2c3031366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393136662509,0x25202c3131366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30323666,0x316625202c323136\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x31366625202c3132,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3232366625092032,0x2c3431366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333236662509,0x25202c3531366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34323666,0x326625202c363136,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x31366625202c3532,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3632366625092032,0x2c3831366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373236662509,0x25202c3931366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38323666,0x316625202c303236,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x32366625202c3932,0x3b38316625202c31,0x33662e6c756d090a,0x3033366625092032\n"
".quad 0x2c3232366625202c,0x090a3b3132662520,0x203233662e646461,0x202c313336662509\n"
".quad 0x25202c3332366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32333666\n"
".quad 0x326625202c343236,0x2e646461090a3b30,0x3666250920323366,0x32366625202c3333\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3433366625092032,0x2c3632366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353336662509,0x25202c3732366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36333666,0x316625202c383236\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x32366625202c3733,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3833366625092032,0x2c3033366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393336662509,0x25202c3133366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30343666,0x326625202c323336,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x33366625202c3134,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3234366625092032,0x2c3433366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333436662509,0x25202c3533366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34343666,0x316625202c363336,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x33366625202c3534,0x3b38316625202c37,0x33662e6c756d090a,0x3634366625092032\n"
".quad 0x2c3833366625202c,0x090a3b3132662520,0x203233662e646461,0x202c373436662509\n"
".quad 0x25202c3933366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38343666\n"
".quad 0x326625202c303436,0x2e646461090a3b30,0x3666250920323366,0x34366625202c3934\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3035366625092032,0x2c3234366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313536662509,0x25202c3334366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32353666,0x316625202c343436\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x34366625202c3335,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3435366625092032,0x2c3634366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353536662509,0x25202c3734366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36353666,0x326625202c383436,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x34366625202c3735,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3835366625092032,0x2c3035366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393536662509,0x25202c3135366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30363666,0x316625202c323536,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x35366625202c3136,0x3b38316625202c33,0x33662e6c756d090a,0x3236366625092032\n"
".quad 0x2c3435366625202c,0x090a3b3132662520,0x203233662e646461,0x202c333636662509\n"
".quad 0x25202c3535366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34363666\n"
".quad 0x326625202c363536,0x2e646461090a3b30,0x3666250920323366,0x35366625202c3536\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3636366625092032,0x2c3835366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373636662509,0x25202c3935366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38363666,0x316625202c303636\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x36366625202c3936,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3037366625092032,0x2c3236366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313736662509,0x25202c3336366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32373666,0x326625202c343636,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x36366625202c3337,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3437366625092032,0x2c3636366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353736662509,0x25202c3736366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36373666,0x316625202c383636,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x36366625202c3737,0x3b38316625202c39,0x33662e6c756d090a,0x3837366625092032\n"
".quad 0x2c3037366625202c,0x090a3b3132662520,0x203233662e646461,0x202c393736662509\n"
".quad 0x25202c3137366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30383666\n"
".quad 0x326625202c323736,0x2e646461090a3b30,0x3666250920323366,0x37366625202c3138\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3238366625092032,0x2c3437366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333836662509,0x25202c3537366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34383666,0x316625202c363736\n"
".quad 0x2e646461090a3b38,0x3666250920323366,0x37366625202c3538,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3638366625092032,0x2c3837366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373836662509,0x25202c3937366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38383666,0x326625202c303836,0x2e646461090a3b30\n"
".quad 0x3666250920323366,0x38366625202c3938,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3039366625092032,0x2c3238366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313936662509,0x25202c3338366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32393666,0x316625202c343836,0x2e646461090a3b38,0x3666250920323366\n"
".quad 0x38366625202c3339,0x3b38316625202c35,0x33662e6c756d090a,0x3439366625092032\n"
".quad 0x2c3638366625202c,0x090a3b3132662520,0x203233662e646461,0x202c353936662509\n"
".quad 0x25202c3738366625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36393666\n"
".quad 0x326625202c383836,0x2e646461090a3b30,0x3666250920323366,0x38366625202c3739\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3839366625092032,0x2c3039366625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393936662509,0x25202c3139366625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30303766,0x316625202c323936\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x39366625202c3130,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3230376625092032,0x2c3439366625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333037662509,0x25202c3539366625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34303766,0x326625202c363936,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x39366625202c3530,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3630376625092032,0x2c3839366625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373037662509,0x25202c3939366625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38303766,0x316625202c303037,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x30376625202c3930,0x3b38316625202c31,0x33662e6c756d090a,0x3031376625092032\n"
".quad 0x2c3230376625202c,0x090a3b3132662520,0x203233662e646461,0x202c313137662509\n"
".quad 0x25202c3330376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32313766\n"
".quad 0x326625202c343037,0x2e646461090a3b30,0x3766250920323366,0x30376625202c3331\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3431376625092032,0x2c3630376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353137662509,0x25202c3730376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36313766,0x316625202c383037\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x30376625202c3731,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3831376625092032,0x2c3031376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393137662509,0x25202c3131376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30323766,0x326625202c323137,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x31376625202c3132,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3232376625092032,0x2c3431376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333237662509,0x25202c3531376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34323766,0x316625202c363137,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x31376625202c3532,0x3b38316625202c37,0x33662e6c756d090a,0x3632376625092032\n"
".quad 0x2c3831376625202c,0x090a3b3132662520,0x203233662e646461,0x202c373237662509\n"
".quad 0x25202c3931376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38323766\n"
".quad 0x326625202c303237,0x2e646461090a3b30,0x3766250920323366,0x32376625202c3932\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3033376625092032,0x2c3232376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313337662509,0x25202c3332376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32333766,0x316625202c343237\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x32376625202c3333,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3433376625092032,0x2c3632376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353337662509,0x25202c3732376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36333766,0x326625202c383237,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x32376625202c3733,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3833376625092032,0x2c3033376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393337662509,0x25202c3133376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30343766,0x316625202c323337,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x33376625202c3134,0x3b38316625202c33,0x33662e6c756d090a,0x3234376625092032\n"
".quad 0x2c3433376625202c,0x090a3b3132662520,0x203233662e646461,0x202c333437662509\n"
".quad 0x25202c3533376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34343766\n"
".quad 0x326625202c363337,0x2e646461090a3b30,0x3766250920323366,0x33376625202c3534\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3634376625092032,0x2c3833376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373437662509,0x25202c3933376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38343766,0x316625202c303437\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x34376625202c3934,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3035376625092032,0x2c3234376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313537662509,0x25202c3334376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32353766,0x326625202c343437,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x34376625202c3335,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3435376625092032,0x2c3634376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353537662509,0x25202c3734376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36353766,0x316625202c383437,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x34376625202c3735,0x3b38316625202c39,0x33662e6c756d090a,0x3835376625092032\n"
".quad 0x2c3035376625202c,0x090a3b3132662520,0x203233662e646461,0x202c393537662509\n"
".quad 0x25202c3135376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30363766\n"
".quad 0x326625202c323537,0x2e646461090a3b30,0x3766250920323366,0x35376625202c3136\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3236376625092032,0x2c3435376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333637662509,0x25202c3535376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34363766,0x316625202c363537\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x35376625202c3536,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3636376625092032,0x2c3835376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373637662509,0x25202c3935376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38363766,0x326625202c303637,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x36376625202c3936,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3037376625092032,0x2c3236376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313737662509,0x25202c3336376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32373766,0x316625202c343637,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x36376625202c3337,0x3b38316625202c35,0x33662e6c756d090a,0x3437376625092032\n"
".quad 0x2c3636376625202c,0x090a3b3132662520,0x203233662e646461,0x202c353737662509\n"
".quad 0x25202c3736376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36373766\n"
".quad 0x326625202c383637,0x2e646461090a3b30,0x3766250920323366,0x36376625202c3737\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3837376625092032,0x2c3037376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393737662509,0x25202c3137376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30383766,0x316625202c323737\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x37376625202c3138,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3238376625092032,0x2c3437376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333837662509,0x25202c3537376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34383766,0x326625202c363737,0x2e646461090a3b30\n"
".quad 0x3766250920323366,0x37376625202c3538,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3638376625092032,0x2c3837376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373837662509,0x25202c3937376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38383766,0x316625202c303837,0x2e646461090a3b38,0x3766250920323366\n"
".quad 0x38376625202c3938,0x3b38316625202c31,0x33662e6c756d090a,0x3039376625092032\n"
".quad 0x2c3238376625202c,0x090a3b3132662520,0x203233662e646461,0x202c313937662509\n"
".quad 0x25202c3338376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32393766\n"
".quad 0x326625202c343837,0x2e646461090a3b30,0x3766250920323366,0x38376625202c3339\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3439376625092032,0x2c3638376625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353937662509,0x25202c3738376625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36393766,0x316625202c383837\n"
".quad 0x2e646461090a3b38,0x3766250920323366,0x38376625202c3739,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3839376625092032,0x2c3039376625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393937662509,0x25202c3139376625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30303866,0x326625202c323937,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x39376625202c3130,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3230386625092032,0x2c3439376625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333038662509,0x25202c3539376625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34303866,0x316625202c363937,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x39376625202c3530,0x3b38316625202c37,0x33662e6c756d090a,0x3630386625092032\n"
".quad 0x2c3839376625202c,0x090a3b3132662520,0x203233662e646461,0x202c373038662509\n"
".quad 0x25202c3939376625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38303866\n"
".quad 0x326625202c303038,0x2e646461090a3b30,0x3866250920323366,0x30386625202c3930\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3031386625092032,0x2c3230386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313138662509,0x25202c3330386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32313866,0x316625202c343038\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x30386625202c3331,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3431386625092032,0x2c3630386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353138662509,0x25202c3730386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36313866,0x326625202c383038,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x30386625202c3731,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3831386625092032,0x2c3031386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393138662509,0x25202c3131386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30323866,0x316625202c323138,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x31386625202c3132,0x3b38316625202c33,0x33662e6c756d090a,0x3232386625092032\n"
".quad 0x2c3431386625202c,0x090a3b3132662520,0x203233662e646461,0x202c333238662509\n"
".quad 0x25202c3531386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34323866\n"
".quad 0x326625202c363138,0x2e646461090a3b30,0x3866250920323366,0x31386625202c3532\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3632386625092032,0x2c3831386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373238662509,0x25202c3931386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38323866,0x316625202c303238\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x32386625202c3932,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3033386625092032,0x2c3232386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313338662509,0x25202c3332386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32333866,0x326625202c343238,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x32386625202c3333,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3433386625092032,0x2c3632386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353338662509,0x25202c3732386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36333866,0x316625202c383238,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x32386625202c3733,0x3b38316625202c39,0x33662e6c756d090a,0x3833386625092032\n"
".quad 0x2c3033386625202c,0x090a3b3132662520,0x203233662e646461,0x202c393338662509\n"
".quad 0x25202c3133386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30343866\n"
".quad 0x326625202c323338,0x2e646461090a3b30,0x3866250920323366,0x33386625202c3134\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3234386625092032,0x2c3433386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333438662509,0x25202c3533386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34343866,0x316625202c363338\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x33386625202c3534,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3634386625092032,0x2c3833386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373438662509,0x25202c3933386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38343866,0x326625202c303438,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x34386625202c3934,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3035386625092032,0x2c3234386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313538662509,0x25202c3334386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32353866,0x316625202c343438,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x34386625202c3335,0x3b38316625202c35,0x33662e6c756d090a,0x3435386625092032\n"
".quad 0x2c3634386625202c,0x090a3b3132662520,0x203233662e646461,0x202c353538662509\n"
".quad 0x25202c3734386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36353866\n"
".quad 0x326625202c383438,0x2e646461090a3b30,0x3866250920323366,0x34386625202c3735\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3835386625092032,0x2c3035386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393538662509,0x25202c3135386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30363866,0x316625202c323538\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x35386625202c3136,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3236386625092032,0x2c3435386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333638662509,0x25202c3535386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34363866,0x326625202c363538,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x35386625202c3536,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3636386625092032,0x2c3835386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373638662509,0x25202c3935386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38363866,0x316625202c303638,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x36386625202c3936,0x3b38316625202c31,0x33662e6c756d090a,0x3037386625092032\n"
".quad 0x2c3236386625202c,0x090a3b3132662520,0x203233662e646461,0x202c313738662509\n"
".quad 0x25202c3336386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32373866\n"
".quad 0x326625202c343638,0x2e646461090a3b30,0x3866250920323366,0x36386625202c3337\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3437386625092032,0x2c3636386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353738662509,0x25202c3736386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36373866,0x316625202c383638\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x36386625202c3737,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3837386625092032,0x2c3037386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393738662509,0x25202c3137386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30383866,0x326625202c323738,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x37386625202c3138,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3238386625092032,0x2c3437386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333838662509,0x25202c3537386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34383866,0x316625202c363738,0x2e646461090a3b38,0x3866250920323366\n"
".quad 0x37386625202c3538,0x3b38316625202c37,0x33662e6c756d090a,0x3638386625092032\n"
".quad 0x2c3837386625202c,0x090a3b3132662520,0x203233662e646461,0x202c373838662509\n"
".quad 0x25202c3937386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38383866\n"
".quad 0x326625202c303838,0x2e646461090a3b30,0x3866250920323366,0x38386625202c3938\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3039386625092032,0x2c3238386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313938662509,0x25202c3338386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32393866,0x316625202c343838\n"
".quad 0x2e646461090a3b38,0x3866250920323366,0x38386625202c3339,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3439386625092032,0x2c3638386625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353938662509,0x25202c3738386625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36393866,0x326625202c383838,0x2e646461090a3b30\n"
".quad 0x3866250920323366,0x38386625202c3739,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3839386625092032,0x2c3039386625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393938662509,0x25202c3139386625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30303966,0x316625202c323938,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x39386625202c3130,0x3b38316625202c33,0x33662e6c756d090a,0x3230396625092032\n"
".quad 0x2c3439386625202c,0x090a3b3132662520,0x203233662e646461,0x202c333039662509\n"
".quad 0x25202c3539386625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34303966\n"
".quad 0x326625202c363938,0x2e646461090a3b30,0x3966250920323366,0x39386625202c3530\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3630396625092032,0x2c3839386625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373039662509,0x25202c3939386625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38303966,0x316625202c303039\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x30396625202c3930,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3031396625092032,0x2c3230396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313139662509,0x25202c3330396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32313966,0x326625202c343039,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x30396625202c3331,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3431396625092032,0x2c3630396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353139662509,0x25202c3730396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36313966,0x316625202c383039,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x30396625202c3731,0x3b38316625202c39,0x33662e6c756d090a,0x3831396625092032\n"
".quad 0x2c3031396625202c,0x090a3b3132662520,0x203233662e646461,0x202c393139662509\n"
".quad 0x25202c3131396625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c30323966\n"
".quad 0x326625202c323139,0x2e646461090a3b30,0x3966250920323366,0x31396625202c3132\n"
".quad 0x3b30326625202c33,0x33662e6c756d090a,0x3232396625092032,0x2c3431396625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c333239662509,0x25202c3531396625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c34323966,0x316625202c363139\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x31396625202c3532,0x3b38316625202c37\n"
".quad 0x33662e6c756d090a,0x3632396625092032,0x2c3831396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c373239662509,0x25202c3931396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c38323966,0x326625202c303239,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x32396625202c3932,0x3b30326625202c31,0x33662e6c756d090a\n"
".quad 0x3033396625092032,0x2c3232396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c313339662509,0x25202c3332396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c32333966,0x316625202c343239,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x32396625202c3333,0x3b38316625202c35,0x33662e6c756d090a,0x3433396625092032\n"
".quad 0x2c3632396625202c,0x090a3b3132662520,0x203233662e646461,0x202c353339662509\n"
".quad 0x25202c3732396625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c36333966\n"
".quad 0x326625202c383239,0x2e646461090a3b30,0x3966250920323366,0x32396625202c3733\n"
".quad 0x3b30326625202c39,0x33662e6c756d090a,0x3833396625092032,0x2c3033396625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c393339662509,0x25202c3133396625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c30343966,0x316625202c323339\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x33396625202c3134,0x3b38316625202c33\n"
".quad 0x33662e6c756d090a,0x3234396625092032,0x2c3433396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c333439662509,0x25202c3533396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c34343966,0x326625202c363339,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x33396625202c3534,0x3b30326625202c37,0x33662e6c756d090a\n"
".quad 0x3634396625092032,0x2c3833396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c373439662509,0x25202c3933396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c38343966,0x316625202c303439,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x34396625202c3934,0x3b38316625202c31,0x33662e6c756d090a,0x3035396625092032\n"
".quad 0x2c3234396625202c,0x090a3b3132662520,0x203233662e646461,0x202c313539662509\n"
".quad 0x25202c3334396625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c32353966\n"
".quad 0x326625202c343439,0x2e646461090a3b30,0x3966250920323366,0x34396625202c3335\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x3435396625092032,0x2c3634396625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c353539662509,0x25202c3734396625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c36353966,0x316625202c383439\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x34396625202c3735,0x3b38316625202c39\n"
".quad 0x33662e6c756d090a,0x3835396625092032,0x2c3035396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c393539662509,0x25202c3135396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c30363966,0x326625202c323539,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x35396625202c3136,0x3b30326625202c33,0x33662e6c756d090a\n"
".quad 0x3236396625092032,0x2c3435396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c333639662509,0x25202c3535396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c34363966,0x316625202c363539,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x35396625202c3536,0x3b38316625202c37,0x33662e6c756d090a,0x3636396625092032\n"
".quad 0x2c3835396625202c,0x090a3b3132662520,0x203233662e646461,0x202c373639662509\n"
".quad 0x25202c3935396625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c38363966\n"
".quad 0x326625202c303639,0x2e646461090a3b30,0x3966250920323366,0x36396625202c3936\n"
".quad 0x3b30326625202c31,0x33662e6c756d090a,0x3037396625092032,0x2c3236396625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c313739662509,0x25202c3336396625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c32373966,0x316625202c343639\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x36396625202c3337,0x3b38316625202c35\n"
".quad 0x33662e6c756d090a,0x3437396625092032,0x2c3636396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c353739662509,0x25202c3736396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c36373966,0x326625202c383639,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x36396625202c3737,0x3b30326625202c39,0x33662e6c756d090a\n"
".quad 0x3837396625092032,0x2c3037396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c393739662509,0x25202c3137396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c30383966,0x316625202c323739,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x37396625202c3138,0x3b38316625202c33,0x33662e6c756d090a,0x3238396625092032\n"
".quad 0x2c3437396625202c,0x090a3b3132662520,0x203233662e646461,0x202c333839662509\n"
".quad 0x25202c3537396625,0x756d090a3b313266,0x2509203233662e6c,0x6625202c34383966\n"
".quad 0x326625202c363739,0x2e646461090a3b30,0x3966250920323366,0x37396625202c3538\n"
".quad 0x3b30326625202c37,0x33662e6c756d090a,0x3638396625092032,0x2c3837396625202c\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x202c373839662509,0x25202c3937396625\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x6625202c38383966,0x316625202c303839\n"
".quad 0x2e646461090a3b38,0x3966250920323366,0x38396625202c3938,0x3b38316625202c31\n"
".quad 0x33662e6c756d090a,0x3039396625092032,0x2c3238396625202c,0x090a3b3132662520\n"
".quad 0x203233662e646461,0x202c313939662509,0x25202c3338396625,0x756d090a3b313266\n"
".quad 0x2509203233662e6c,0x6625202c32393966,0x326625202c343839,0x2e646461090a3b30\n"
".quad 0x3966250920323366,0x38396625202c3339,0x3b30326625202c35,0x33662e6c756d090a\n"
".quad 0x3439396625092032,0x2c3638396625202c,0x090a3b3931662520,0x203233662e646461\n"
".quad 0x202c353939662509,0x25202c3738396625,0x756d090a3b393166,0x2509203233662e6c\n"
".quad 0x6625202c36393966,0x316625202c383839,0x2e646461090a3b38,0x3966250920323366\n"
".quad 0x38396625202c3739,0x3b38316625202c39,0x33662e6c756d090a,0x3839396625092032\n"
".quad 0x2c3039396625202c,0x090a3b3132662520,0x203233662e646461,0x202c393939662509\n"
".quad 0x25202c3139396625,0x756d090a3b313266,0x2509203233662e6c,0x25202c3030303166\n"
".quad 0x6625202c32393966,0x646461090a3b3032,0x662509203233662e,0x6625202c31303031\n"
".quad 0x326625202c333939,0x2e6c756d090a3b30,0x3166250920323366,0x396625202c323030\n"
".quad 0x39316625202c3439,0x662e646461090a3b,0x3031662509203233,0x39396625202c3330\n"
".quad 0x3b39316625202c35,0x33662e6c756d090a,0x3030316625092032,0x3639396625202c34\n"
".quad 0x0a3b38316625202c,0x3233662e64646109,0x3530303166250920,0x2c3739396625202c\n"
".quad 0x090a3b3831662520,0x203233662e6c756d,0x2c36303031662509,0x202c383939662520\n"
".quad 0x61090a3b31326625,0x09203233662e6464,0x202c373030316625,0x25202c3939396625\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830303166,0x25202c3030303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930303166,0x25202c3130303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031303166,0x25202c3230303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131303166,0x25202c3330303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231303166,0x25202c3430303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331303166,0x25202c3530303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431303166,0x25202c3630303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531303166,0x25202c3730303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631303166,0x25202c3830303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731303166,0x25202c3930303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831303166,0x25202c3031303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931303166,0x25202c3131303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032303166,0x25202c3231303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132303166,0x25202c3331303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232303166,0x25202c3431303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332303166,0x25202c3531303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432303166,0x25202c3631303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532303166,0x25202c3731303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632303166,0x25202c3831303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732303166,0x25202c3931303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832303166,0x25202c3032303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932303166,0x25202c3132303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033303166,0x25202c3232303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133303166,0x25202c3332303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233303166,0x25202c3432303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333303166,0x25202c3532303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433303166,0x25202c3632303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533303166,0x25202c3732303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633303166,0x25202c3832303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733303166,0x25202c3932303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833303166,0x25202c3033303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933303166,0x25202c3133303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034303166,0x25202c3233303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134303166,0x25202c3333303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234303166,0x25202c3433303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334303166,0x25202c3533303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434303166,0x25202c3633303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534303166,0x25202c3733303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634303166,0x25202c3833303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734303166,0x25202c3933303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834303166,0x25202c3034303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934303166,0x25202c3134303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035303166,0x25202c3234303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135303166,0x25202c3334303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235303166,0x25202c3434303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335303166,0x25202c3534303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435303166,0x25202c3634303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535303166,0x25202c3734303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635303166,0x25202c3834303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735303166,0x25202c3934303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835303166,0x25202c3035303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935303166,0x25202c3135303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036303166,0x25202c3235303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136303166,0x25202c3335303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236303166,0x25202c3435303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336303166,0x25202c3535303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436303166,0x25202c3635303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536303166,0x25202c3735303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636303166,0x25202c3835303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736303166,0x25202c3935303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836303166,0x25202c3036303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936303166,0x25202c3136303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3037303166,0x25202c3236303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3137303166,0x25202c3336303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3237303166,0x25202c3436303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3337303166,0x25202c3536303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3437303166,0x25202c3636303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3537303166,0x25202c3736303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3637303166,0x25202c3836303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3737303166,0x25202c3936303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3837303166,0x25202c3037303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3937303166,0x25202c3137303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3038303166,0x25202c3237303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3138303166,0x25202c3337303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3238303166,0x25202c3437303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3338303166,0x25202c3537303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3438303166,0x25202c3637303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3538303166,0x25202c3737303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3638303166,0x25202c3837303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3738303166,0x25202c3937303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3838303166,0x25202c3038303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3938303166,0x25202c3138303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3039303166,0x25202c3238303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3139303166,0x25202c3338303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3239303166,0x25202c3438303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3339303166,0x25202c3538303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3439303166,0x25202c3638303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3539303166,0x25202c3738303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3639303166,0x25202c3838303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3739303166,0x25202c3938303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3839303166,0x25202c3039303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3939303166,0x25202c3139303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3030313166,0x25202c3239303166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3130313166,0x25202c3339303166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3230313166,0x25202c3439303166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3330313166,0x25202c3539303166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3430313166,0x25202c3639303166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3530313166,0x25202c3739303166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3630313166,0x25202c3839303166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3730313166,0x25202c3939303166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3830313166,0x25202c3030313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3930313166,0x25202c3130313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3031313166,0x25202c3230313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3131313166,0x25202c3330313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3231313166,0x25202c3430313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3331313166,0x25202c3530313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3431313166,0x25202c3630313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3531313166,0x25202c3730313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3631313166,0x25202c3830313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3731313166,0x25202c3930313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3831313166,0x25202c3031313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3931313166,0x25202c3131313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3032313166,0x25202c3231313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3132313166,0x25202c3331313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3232313166,0x25202c3431313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3332313166,0x25202c3531313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3432313166,0x25202c3631313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3532313166,0x25202c3731313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3632313166,0x25202c3831313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3732313166,0x25202c3931313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3832313166,0x25202c3032313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3932313166,0x25202c3132313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3033313166,0x25202c3232313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3133313166,0x25202c3332313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3233313166,0x25202c3432313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3333313166,0x25202c3532313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3433313166,0x25202c3632313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3533313166,0x25202c3732313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3633313166,0x25202c3832313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3733313166,0x25202c3932313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3833313166,0x25202c3033313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3933313166,0x25202c3133313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3034313166,0x25202c3233313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3134313166,0x25202c3333313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3234313166,0x25202c3433313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3334313166,0x25202c3533313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3434313166,0x25202c3633313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3534313166,0x25202c3733313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3634313166,0x25202c3833313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3734313166,0x25202c3933313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3834313166,0x25202c3034313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3934313166,0x25202c3134313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3035313166,0x25202c3234313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3135313166,0x25202c3334313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3235313166,0x25202c3434313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3335313166,0x25202c3534313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3435313166,0x25202c3634313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3535313166,0x25202c3734313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3635313166,0x25202c3834313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3735313166,0x25202c3934313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3835313166,0x25202c3035313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3935313166,0x25202c3135313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3036313166,0x25202c3235313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3136313166,0x25202c3335313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3236313166,0x25202c3435313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3336313166,0x25202c3535313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3436313166,0x25202c3635313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3536313166,0x25202c3735313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3636313166,0x25202c3835313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3736313166,0x25202c3935313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3836313166,0x25202c3036313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3936313166,0x25202c3136313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3037313166,0x25202c3236313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3137313166,0x25202c3336313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3237313166,0x25202c3436313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3337313166,0x25202c3536313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3437313166,0x25202c3636313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3537313166,0x25202c3736313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3637313166,0x25202c3836313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3737313166,0x25202c3936313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3837313166,0x25202c3037313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3937313166,0x25202c3137313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3038313166,0x25202c3237313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3138313166,0x25202c3337313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3238313166,0x25202c3437313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3338313166,0x25202c3537313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3438313166,0x25202c3637313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3538313166,0x25202c3737313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3638313166,0x25202c3837313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3738313166,0x25202c3937313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3838313166,0x25202c3038313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3938313166,0x25202c3138313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3039313166,0x25202c3238313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3139313166,0x25202c3338313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3239313166,0x25202c3438313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3339313166,0x25202c3538313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3439313166,0x25202c3638313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3539313166,0x25202c3738313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3639313166,0x25202c3838313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3739313166,0x25202c3938313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3839313166,0x25202c3039313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3939313166,0x25202c3139313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3030323166,0x25202c3239313166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3130323166,0x25202c3339313166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3230323166,0x25202c3439313166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3330323166,0x25202c3539313166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3430323166,0x25202c3639313166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3530323166,0x25202c3739313166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3630323166,0x25202c3839313166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3730323166,0x25202c3939313166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830323166,0x25202c3030323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930323166,0x25202c3130323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031323166,0x25202c3230323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131323166,0x25202c3330323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231323166,0x25202c3430323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331323166,0x25202c3530323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431323166,0x25202c3630323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531323166,0x25202c3730323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631323166,0x25202c3830323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731323166,0x25202c3930323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831323166,0x25202c3031323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931323166,0x25202c3131323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032323166,0x25202c3231323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132323166,0x25202c3331323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232323166,0x25202c3431323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332323166,0x25202c3531323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432323166,0x25202c3631323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532323166,0x25202c3731323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632323166,0x25202c3831323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732323166,0x25202c3931323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832323166,0x25202c3032323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932323166,0x25202c3132323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033323166,0x25202c3232323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133323166,0x25202c3332323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233323166,0x25202c3432323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333323166,0x25202c3532323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433323166,0x25202c3632323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533323166,0x25202c3732323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633323166,0x25202c3832323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733323166,0x25202c3932323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833323166,0x25202c3033323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933323166,0x25202c3133323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034323166,0x25202c3233323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134323166,0x25202c3333323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234323166,0x25202c3433323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334323166,0x25202c3533323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434323166,0x25202c3633323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534323166,0x25202c3733323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634323166,0x25202c3833323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734323166,0x25202c3933323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834323166,0x25202c3034323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934323166,0x25202c3134323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035323166,0x25202c3234323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135323166,0x25202c3334323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235323166,0x25202c3434323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335323166,0x25202c3534323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435323166,0x25202c3634323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535323166,0x25202c3734323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635323166,0x25202c3834323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735323166,0x25202c3934323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835323166,0x25202c3035323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935323166,0x25202c3135323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036323166,0x25202c3235323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136323166,0x25202c3335323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236323166,0x25202c3435323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336323166,0x25202c3535323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436323166,0x25202c3635323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536323166,0x25202c3735323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636323166,0x25202c3835323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736323166,0x25202c3935323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836323166,0x25202c3036323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936323166,0x25202c3136323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3037323166,0x25202c3236323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3137323166,0x25202c3336323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3237323166,0x25202c3436323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3337323166,0x25202c3536323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3437323166,0x25202c3636323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3537323166,0x25202c3736323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3637323166,0x25202c3836323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3737323166,0x25202c3936323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3837323166,0x25202c3037323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3937323166,0x25202c3137323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3038323166,0x25202c3237323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3138323166,0x25202c3337323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3238323166,0x25202c3437323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3338323166,0x25202c3537323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3438323166,0x25202c3637323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3538323166,0x25202c3737323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3638323166,0x25202c3837323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3738323166,0x25202c3937323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3838323166,0x25202c3038323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3938323166,0x25202c3138323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3039323166,0x25202c3238323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3139323166,0x25202c3338323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3239323166,0x25202c3438323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3339323166,0x25202c3538323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3439323166,0x25202c3638323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3539323166,0x25202c3738323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3639323166,0x25202c3838323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3739323166,0x25202c3938323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3839323166,0x25202c3039323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3939323166,0x25202c3139323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3030333166,0x25202c3239323166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3130333166,0x25202c3339323166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3230333166,0x25202c3439323166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3330333166,0x25202c3539323166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3430333166,0x25202c3639323166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3530333166,0x25202c3739323166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3630333166,0x25202c3839323166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3730333166,0x25202c3939323166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3830333166,0x25202c3030333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3930333166,0x25202c3130333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3031333166,0x25202c3230333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3131333166,0x25202c3330333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3231333166,0x25202c3430333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3331333166,0x25202c3530333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3431333166,0x25202c3630333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3531333166,0x25202c3730333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3631333166,0x25202c3830333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3731333166,0x25202c3930333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3831333166,0x25202c3031333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3931333166,0x25202c3131333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3032333166,0x25202c3231333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3132333166,0x25202c3331333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3232333166,0x25202c3431333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3332333166,0x25202c3531333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3432333166,0x25202c3631333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3532333166,0x25202c3731333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3632333166,0x25202c3831333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3732333166,0x25202c3931333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3832333166,0x25202c3032333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3932333166,0x25202c3132333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3033333166,0x25202c3232333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3133333166,0x25202c3332333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3233333166,0x25202c3432333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3333333166,0x25202c3532333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3433333166,0x25202c3632333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3533333166,0x25202c3732333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3633333166,0x25202c3832333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3733333166,0x25202c3932333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3833333166,0x25202c3033333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3933333166,0x25202c3133333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3034333166,0x25202c3233333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3134333166,0x25202c3333333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3234333166,0x25202c3433333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3334333166,0x25202c3533333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3434333166,0x25202c3633333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3534333166,0x25202c3733333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3634333166,0x25202c3833333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3734333166,0x25202c3933333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3834333166,0x25202c3034333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3934333166,0x25202c3134333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3035333166,0x25202c3234333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3135333166,0x25202c3334333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3235333166,0x25202c3434333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3335333166,0x25202c3534333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3435333166,0x25202c3634333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3535333166,0x25202c3734333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3635333166,0x25202c3834333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3735333166,0x25202c3934333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3835333166,0x25202c3035333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3935333166,0x25202c3135333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3036333166,0x25202c3235333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3136333166,0x25202c3335333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3236333166,0x25202c3435333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3336333166,0x25202c3535333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3436333166,0x25202c3635333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3536333166,0x25202c3735333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3636333166,0x25202c3835333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3736333166,0x25202c3935333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3836333166,0x25202c3036333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3936333166,0x25202c3136333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3037333166,0x25202c3236333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3137333166,0x25202c3336333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3237333166,0x25202c3436333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3337333166,0x25202c3536333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3437333166,0x25202c3636333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3537333166,0x25202c3736333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3637333166,0x25202c3836333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3737333166,0x25202c3936333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3837333166,0x25202c3037333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3937333166,0x25202c3137333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3038333166,0x25202c3237333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3138333166,0x25202c3337333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3238333166,0x25202c3437333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3338333166,0x25202c3537333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3438333166,0x25202c3637333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3538333166,0x25202c3737333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3638333166,0x25202c3837333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3738333166,0x25202c3937333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3838333166,0x25202c3038333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3938333166,0x25202c3138333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3039333166,0x25202c3238333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3139333166,0x25202c3338333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3239333166,0x25202c3438333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3339333166,0x25202c3538333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3439333166,0x25202c3638333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3539333166,0x25202c3738333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3639333166,0x25202c3838333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3739333166,0x25202c3938333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3839333166,0x25202c3039333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3939333166,0x25202c3139333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3030343166,0x25202c3239333166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3130343166,0x25202c3339333166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3230343166,0x25202c3439333166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3330343166,0x25202c3539333166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3430343166,0x25202c3639333166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3530343166,0x25202c3739333166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3630343166,0x25202c3839333166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3730343166,0x25202c3939333166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830343166,0x25202c3030343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930343166,0x25202c3130343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031343166,0x25202c3230343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131343166,0x25202c3330343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231343166,0x25202c3430343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331343166,0x25202c3530343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431343166,0x25202c3630343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531343166,0x25202c3730343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631343166,0x25202c3830343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731343166,0x25202c3930343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831343166,0x25202c3031343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931343166,0x25202c3131343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032343166,0x25202c3231343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132343166,0x25202c3331343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232343166,0x25202c3431343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332343166,0x25202c3531343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432343166,0x25202c3631343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532343166,0x25202c3731343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632343166,0x25202c3831343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732343166,0x25202c3931343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832343166,0x25202c3032343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932343166,0x25202c3132343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033343166,0x25202c3232343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133343166,0x25202c3332343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233343166,0x25202c3432343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333343166,0x25202c3532343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433343166,0x25202c3632343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533343166,0x25202c3732343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633343166,0x25202c3832343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733343166,0x25202c3932343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833343166,0x25202c3033343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933343166,0x25202c3133343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034343166,0x25202c3233343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134343166,0x25202c3333343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234343166,0x25202c3433343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334343166,0x25202c3533343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434343166,0x25202c3633343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534343166,0x25202c3733343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634343166,0x25202c3833343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734343166,0x25202c3933343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834343166,0x25202c3034343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934343166,0x25202c3134343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035343166,0x25202c3234343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135343166,0x25202c3334343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235343166,0x25202c3434343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335343166,0x25202c3534343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435343166,0x25202c3634343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535343166,0x25202c3734343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635343166,0x25202c3834343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735343166,0x25202c3934343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835343166,0x25202c3035343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935343166,0x25202c3135343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036343166,0x25202c3235343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136343166,0x25202c3335343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236343166,0x25202c3435343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336343166,0x25202c3535343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436343166,0x25202c3635343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536343166,0x25202c3735343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636343166,0x25202c3835343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736343166,0x25202c3935343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836343166,0x25202c3036343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936343166,0x25202c3136343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3037343166,0x25202c3236343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3137343166,0x25202c3336343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3237343166,0x25202c3436343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3337343166,0x25202c3536343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3437343166,0x25202c3636343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3537343166,0x25202c3736343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3637343166,0x25202c3836343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3737343166,0x25202c3936343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3837343166,0x25202c3037343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3937343166,0x25202c3137343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3038343166,0x25202c3237343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3138343166,0x25202c3337343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3238343166,0x25202c3437343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3338343166,0x25202c3537343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3438343166,0x25202c3637343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3538343166,0x25202c3737343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3638343166,0x25202c3837343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3738343166,0x25202c3937343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3838343166,0x25202c3038343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3938343166,0x25202c3138343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3039343166,0x25202c3238343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3139343166,0x25202c3338343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3239343166,0x25202c3438343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3339343166,0x25202c3538343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3439343166,0x25202c3638343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3539343166,0x25202c3738343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3639343166,0x25202c3838343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3739343166,0x25202c3938343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3839343166,0x25202c3039343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3939343166,0x25202c3139343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3030353166,0x25202c3239343166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3130353166,0x25202c3339343166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3230353166,0x25202c3439343166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3330353166,0x25202c3539343166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3430353166,0x25202c3639343166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3530353166,0x25202c3739343166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3630353166,0x25202c3839343166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3730353166,0x25202c3939343166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3830353166,0x25202c3030353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3930353166,0x25202c3130353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3031353166,0x25202c3230353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3131353166,0x25202c3330353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3231353166,0x25202c3430353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3331353166,0x25202c3530353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3431353166,0x25202c3630353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3531353166,0x25202c3730353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3631353166,0x25202c3830353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3731353166,0x25202c3930353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3831353166,0x25202c3031353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3931353166,0x25202c3131353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3032353166,0x25202c3231353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3132353166,0x25202c3331353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3232353166,0x25202c3431353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3332353166,0x25202c3531353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3432353166,0x25202c3631353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3532353166,0x25202c3731353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3632353166,0x25202c3831353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3732353166,0x25202c3931353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3832353166,0x25202c3032353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3932353166,0x25202c3132353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3033353166,0x25202c3232353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3133353166,0x25202c3332353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3233353166,0x25202c3432353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3333353166,0x25202c3532353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3433353166,0x25202c3632353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3533353166,0x25202c3732353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3633353166,0x25202c3832353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3733353166,0x25202c3932353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3833353166,0x25202c3033353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3933353166,0x25202c3133353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3034353166,0x25202c3233353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3134353166,0x25202c3333353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3234353166,0x25202c3433353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3334353166,0x25202c3533353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3434353166,0x25202c3633353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3534353166,0x25202c3733353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3634353166,0x25202c3833353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3734353166,0x25202c3933353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3834353166,0x25202c3034353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3934353166,0x25202c3134353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3035353166,0x25202c3234353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3135353166,0x25202c3334353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3235353166,0x25202c3434353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3335353166,0x25202c3534353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3435353166,0x25202c3634353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3535353166,0x25202c3734353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3635353166,0x25202c3834353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3735353166,0x25202c3934353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3835353166,0x25202c3035353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3935353166,0x25202c3135353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3036353166,0x25202c3235353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3136353166,0x25202c3335353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3236353166,0x25202c3435353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3336353166,0x25202c3535353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3436353166,0x25202c3635353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3536353166,0x25202c3735353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3636353166,0x25202c3835353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3736353166,0x25202c3935353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3836353166,0x25202c3036353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3936353166,0x25202c3136353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3037353166,0x25202c3236353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3137353166,0x25202c3336353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3237353166,0x25202c3436353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3337353166,0x25202c3536353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3437353166,0x25202c3636353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3537353166,0x25202c3736353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3637353166,0x25202c3836353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3737353166,0x25202c3936353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3837353166,0x25202c3037353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3937353166,0x25202c3137353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3038353166,0x25202c3237353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3138353166,0x25202c3337353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3238353166,0x25202c3437353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3338353166,0x25202c3537353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3438353166,0x25202c3637353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3538353166,0x25202c3737353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3638353166,0x25202c3837353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3738353166,0x25202c3937353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3838353166,0x25202c3038353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3938353166,0x25202c3138353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3039353166,0x25202c3238353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3139353166,0x25202c3338353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3239353166,0x25202c3438353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3339353166,0x25202c3538353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3439353166,0x25202c3638353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3539353166,0x25202c3738353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3639353166,0x25202c3838353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3739353166,0x25202c3938353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3839353166,0x25202c3039353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3939353166,0x25202c3139353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3030363166,0x25202c3239353166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3130363166,0x25202c3339353166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3230363166,0x25202c3439353166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3330363166,0x25202c3539353166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3430363166,0x25202c3639353166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3530363166,0x25202c3739353166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3630363166,0x25202c3839353166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3730363166,0x25202c3939353166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830363166,0x25202c3030363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930363166,0x25202c3130363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031363166,0x25202c3230363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131363166,0x25202c3330363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231363166,0x25202c3430363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331363166,0x25202c3530363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431363166,0x25202c3630363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531363166,0x25202c3730363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631363166,0x25202c3830363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731363166,0x25202c3930363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831363166,0x25202c3031363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931363166,0x25202c3131363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032363166,0x25202c3231363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132363166,0x25202c3331363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232363166,0x25202c3431363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332363166,0x25202c3531363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432363166,0x25202c3631363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532363166,0x25202c3731363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632363166,0x25202c3831363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732363166,0x25202c3931363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832363166,0x25202c3032363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932363166,0x25202c3132363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033363166,0x25202c3232363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133363166,0x25202c3332363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233363166,0x25202c3432363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333363166,0x25202c3532363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433363166,0x25202c3632363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533363166,0x25202c3732363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633363166,0x25202c3832363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733363166,0x25202c3932363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833363166,0x25202c3033363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933363166,0x25202c3133363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034363166,0x25202c3233363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134363166,0x25202c3333363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234363166,0x25202c3433363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334363166,0x25202c3533363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434363166,0x25202c3633363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534363166,0x25202c3733363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634363166,0x25202c3833363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734363166,0x25202c3933363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834363166,0x25202c3034363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934363166,0x25202c3134363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035363166,0x25202c3234363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135363166,0x25202c3334363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235363166,0x25202c3434363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335363166,0x25202c3534363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435363166,0x25202c3634363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535363166,0x25202c3734363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635363166,0x25202c3834363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735363166,0x25202c3934363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835363166,0x25202c3035363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935363166,0x25202c3135363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036363166,0x25202c3235363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136363166,0x25202c3335363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236363166,0x25202c3435363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336363166,0x25202c3535363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436363166,0x25202c3635363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536363166,0x25202c3735363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636363166,0x25202c3835363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736363166,0x25202c3935363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836363166,0x25202c3036363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936363166,0x25202c3136363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3037363166,0x25202c3236363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3137363166,0x25202c3336363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3237363166,0x25202c3436363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3337363166,0x25202c3536363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3437363166,0x25202c3636363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3537363166,0x25202c3736363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3637363166,0x25202c3836363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3737363166,0x25202c3936363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3837363166,0x25202c3037363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3937363166,0x25202c3137363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3038363166,0x25202c3237363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3138363166,0x25202c3337363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3238363166,0x25202c3437363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3338363166,0x25202c3537363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3438363166,0x25202c3637363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3538363166,0x25202c3737363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3638363166,0x25202c3837363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3738363166,0x25202c3937363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3838363166,0x25202c3038363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3938363166,0x25202c3138363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3039363166,0x25202c3238363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3139363166,0x25202c3338363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3239363166,0x25202c3438363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3339363166,0x25202c3538363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3439363166,0x25202c3638363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3539363166,0x25202c3738363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3639363166,0x25202c3838363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3739363166,0x25202c3938363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3839363166,0x25202c3039363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3939363166,0x25202c3139363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3030373166,0x25202c3239363166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3130373166,0x25202c3339363166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3230373166,0x25202c3439363166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3330373166,0x25202c3539363166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3430373166,0x25202c3639363166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3530373166,0x25202c3739363166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3630373166,0x25202c3839363166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3730373166,0x25202c3939363166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3830373166,0x25202c3030373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3930373166,0x25202c3130373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3031373166,0x25202c3230373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3131373166,0x25202c3330373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3231373166,0x25202c3430373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3331373166,0x25202c3530373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3431373166,0x25202c3630373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3531373166,0x25202c3730373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3631373166,0x25202c3830373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3731373166,0x25202c3930373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3831373166,0x25202c3031373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3931373166,0x25202c3131373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3032373166,0x25202c3231373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3132373166,0x25202c3331373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3232373166,0x25202c3431373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3332373166,0x25202c3531373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3432373166,0x25202c3631373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3532373166,0x25202c3731373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3632373166,0x25202c3831373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3732373166,0x25202c3931373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3832373166,0x25202c3032373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3932373166,0x25202c3132373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3033373166,0x25202c3232373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3133373166,0x25202c3332373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3233373166,0x25202c3432373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3333373166,0x25202c3532373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3433373166,0x25202c3632373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3533373166,0x25202c3732373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3633373166,0x25202c3832373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3733373166,0x25202c3932373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3833373166,0x25202c3033373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3933373166,0x25202c3133373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3034373166,0x25202c3233373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3134373166,0x25202c3333373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3234373166,0x25202c3433373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3334373166,0x25202c3533373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3434373166,0x25202c3633373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3534373166,0x25202c3733373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3634373166,0x25202c3833373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3734373166,0x25202c3933373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3834373166,0x25202c3034373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3934373166,0x25202c3134373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3035373166,0x25202c3234373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3135373166,0x25202c3334373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3235373166,0x25202c3434373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3335373166,0x25202c3534373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3435373166,0x25202c3634373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3535373166,0x25202c3734373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3635373166,0x25202c3834373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3735373166,0x25202c3934373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3835373166,0x25202c3035373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3935373166,0x25202c3135373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3036373166,0x25202c3235373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3136373166,0x25202c3335373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3236373166,0x25202c3435373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3336373166,0x25202c3535373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3436373166,0x25202c3635373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3536373166,0x25202c3735373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3636373166,0x25202c3835373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3736373166,0x25202c3935373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3836373166,0x25202c3036373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3936373166,0x25202c3136373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3037373166,0x25202c3236373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3137373166,0x25202c3336373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3237373166,0x25202c3436373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3337373166,0x25202c3536373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3437373166,0x25202c3636373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3537373166,0x25202c3736373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3637373166,0x25202c3836373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3737373166,0x25202c3936373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3837373166,0x25202c3037373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3937373166,0x25202c3137373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3038373166,0x25202c3237373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3138373166,0x25202c3337373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3238373166,0x25202c3437373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3338373166,0x25202c3537373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3438373166,0x25202c3637373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3538373166,0x25202c3737373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3638373166,0x25202c3837373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3738373166,0x25202c3937373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3838373166,0x25202c3038373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3938373166,0x25202c3138373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3039373166,0x25202c3238373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3139373166,0x25202c3338373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3239373166,0x25202c3438373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3339373166,0x25202c3538373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3439373166,0x25202c3638373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3539373166,0x25202c3738373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3639373166,0x25202c3838373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3739373166,0x25202c3938373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3839373166,0x25202c3039373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3939373166,0x25202c3139373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3030383166,0x25202c3239373166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3130383166,0x25202c3339373166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3230383166,0x25202c3439373166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3330383166,0x25202c3539373166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3430383166,0x25202c3639373166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3530383166,0x25202c3739373166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3630383166,0x25202c3839373166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3730383166,0x25202c3939373166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830383166,0x25202c3030383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930383166,0x25202c3130383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031383166,0x25202c3230383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131383166,0x25202c3330383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231383166,0x25202c3430383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331383166,0x25202c3530383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431383166,0x25202c3630383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531383166,0x25202c3730383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631383166,0x25202c3830383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731383166,0x25202c3930383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831383166,0x25202c3031383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931383166,0x25202c3131383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032383166,0x25202c3231383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132383166,0x25202c3331383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232383166,0x25202c3431383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332383166,0x25202c3531383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432383166,0x25202c3631383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532383166,0x25202c3731383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632383166,0x25202c3831383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732383166,0x25202c3931383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832383166,0x25202c3032383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932383166,0x25202c3132383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033383166,0x25202c3232383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133383166,0x25202c3332383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233383166,0x25202c3432383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333383166,0x25202c3532383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433383166,0x25202c3632383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533383166,0x25202c3732383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633383166,0x25202c3832383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733383166,0x25202c3932383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833383166,0x25202c3033383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933383166,0x25202c3133383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034383166,0x25202c3233383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134383166,0x25202c3333383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234383166,0x25202c3433383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334383166,0x25202c3533383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434383166,0x25202c3633383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534383166,0x25202c3733383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634383166,0x25202c3833383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734383166,0x25202c3933383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834383166,0x25202c3034383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934383166,0x25202c3134383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035383166,0x25202c3234383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135383166,0x25202c3334383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235383166,0x25202c3434383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335383166,0x25202c3534383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435383166,0x25202c3634383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535383166,0x25202c3734383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635383166,0x25202c3834383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735383166,0x25202c3934383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835383166,0x25202c3035383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935383166,0x25202c3135383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036383166,0x25202c3235383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136383166,0x25202c3335383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236383166,0x25202c3435383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336383166,0x25202c3535383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436383166,0x25202c3635383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536383166,0x25202c3735383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636383166,0x25202c3835383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736383166,0x25202c3935383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836383166,0x25202c3036383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936383166,0x25202c3136383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3037383166,0x25202c3236383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3137383166,0x25202c3336383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3237383166,0x25202c3436383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3337383166,0x25202c3536383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3437383166,0x25202c3636383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3537383166,0x25202c3736383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3637383166,0x25202c3836383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3737383166,0x25202c3936383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3837383166,0x25202c3037383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3937383166,0x25202c3137383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3038383166,0x25202c3237383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3138383166,0x25202c3337383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3238383166,0x25202c3437383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3338383166,0x25202c3537383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3438383166,0x25202c3637383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3538383166,0x25202c3737383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3638383166,0x25202c3837383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3738383166,0x25202c3937383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3838383166,0x25202c3038383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3938383166,0x25202c3138383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3039383166,0x25202c3238383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3139383166,0x25202c3338383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3239383166,0x25202c3438383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3339383166,0x25202c3538383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3439383166,0x25202c3638383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3539383166,0x25202c3738383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3639383166,0x25202c3838383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3739383166,0x25202c3938383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3839383166,0x25202c3039383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3939383166,0x25202c3139383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3030393166,0x25202c3239383166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3130393166,0x25202c3339383166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3230393166,0x25202c3439383166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3330393166,0x25202c3539383166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3430393166,0x25202c3639383166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3530393166,0x25202c3739383166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3630393166,0x25202c3839383166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3730393166,0x25202c3939383166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3830393166,0x25202c3030393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3930393166,0x25202c3130393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3031393166,0x25202c3230393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3131393166,0x25202c3330393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3231393166,0x25202c3430393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3331393166,0x25202c3530393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3431393166,0x25202c3630393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3531393166,0x25202c3730393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3631393166,0x25202c3830393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3731393166,0x25202c3930393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3831393166,0x25202c3031393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3931393166,0x25202c3131393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3032393166,0x25202c3231393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3132393166,0x25202c3331393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3232393166,0x25202c3431393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3332393166,0x25202c3531393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3432393166,0x25202c3631393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3532393166,0x25202c3731393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3632393166,0x25202c3831393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3732393166,0x25202c3931393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3832393166,0x25202c3032393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3932393166,0x25202c3132393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3033393166,0x25202c3232393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3133393166,0x25202c3332393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3233393166,0x25202c3432393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3333393166,0x25202c3532393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3433393166,0x25202c3632393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3533393166,0x25202c3732393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3633393166,0x25202c3832393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3733393166,0x25202c3932393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3833393166,0x25202c3033393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3933393166,0x25202c3133393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3034393166,0x25202c3233393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3134393166,0x25202c3333393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3234393166,0x25202c3433393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3334393166,0x25202c3533393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3434393166,0x25202c3633393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3534393166,0x25202c3733393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3634393166,0x25202c3833393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3734393166,0x25202c3933393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3834393166,0x25202c3034393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3934393166,0x25202c3134393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3035393166,0x25202c3234393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3135393166,0x25202c3334393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3235393166,0x25202c3434393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3335393166,0x25202c3534393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3435393166,0x25202c3634393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3535393166,0x25202c3734393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3635393166,0x25202c3834393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3735393166,0x25202c3934393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3835393166,0x25202c3035393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3935393166,0x25202c3135393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3036393166,0x25202c3235393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3136393166,0x25202c3335393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3236393166,0x25202c3435393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3336393166,0x25202c3535393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3436393166,0x25202c3635393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3536393166,0x25202c3735393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3636393166,0x25202c3835393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3736393166,0x25202c3935393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3836393166,0x25202c3036393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3936393166,0x25202c3136393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3037393166,0x25202c3236393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3137393166,0x25202c3336393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3237393166,0x25202c3436393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3337393166,0x25202c3536393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3437393166,0x25202c3636393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3537393166,0x25202c3736393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3637393166,0x25202c3836393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3737393166,0x25202c3936393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3837393166,0x25202c3037393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3937393166,0x25202c3137393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3038393166,0x25202c3237393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3138393166,0x25202c3337393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3238393166,0x25202c3437393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3338393166,0x25202c3537393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3438393166,0x25202c3637393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3538393166,0x25202c3737393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3638393166,0x25202c3837393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3738393166,0x25202c3937393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3838393166,0x25202c3038393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3938393166,0x25202c3138393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3039393166,0x25202c3238393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3139393166,0x25202c3338393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3239393166,0x25202c3438393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3339393166,0x25202c3538393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3439393166,0x25202c3638393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3539393166,0x25202c3738393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3639393166,0x25202c3838393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3739393166,0x25202c3938393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3839393166,0x25202c3039393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3939393166,0x25202c3139393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3030303266,0x25202c3239393166\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3130303266,0x25202c3339393166\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3230303266,0x25202c3439393166\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3330303266,0x25202c3539393166\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3430303266,0x25202c3639393166\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3530303266,0x25202c3739393166\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3630303266,0x25202c3839393166\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3730303266,0x25202c3939393166\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3830303266,0x25202c3030303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3930303266,0x25202c3130303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3031303266,0x25202c3230303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3131303266,0x25202c3330303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3231303266,0x25202c3430303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3331303266,0x25202c3530303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3431303266,0x25202c3630303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3531303266,0x25202c3730303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3631303266,0x25202c3830303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3731303266,0x25202c3930303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3831303266,0x25202c3031303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3931303266,0x25202c3131303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3032303266,0x25202c3231303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3132303266,0x25202c3331303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3232303266,0x25202c3431303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3332303266,0x25202c3531303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3432303266,0x25202c3631303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3532303266,0x25202c3731303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3632303266,0x25202c3831303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3732303266,0x25202c3931303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3832303266,0x25202c3032303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3932303266,0x25202c3132303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3033303266,0x25202c3232303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3133303266,0x25202c3332303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3233303266,0x25202c3432303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3333303266,0x25202c3532303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3433303266,0x25202c3632303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3533303266,0x25202c3732303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3633303266,0x25202c3832303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3733303266,0x25202c3932303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3833303266,0x25202c3033303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3933303266,0x25202c3133303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3034303266,0x25202c3233303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3134303266,0x25202c3333303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3234303266,0x25202c3433303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3334303266,0x25202c3533303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3434303266,0x25202c3633303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3534303266,0x25202c3733303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3634303266,0x25202c3833303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3734303266,0x25202c3933303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3834303266,0x25202c3034303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3934303266,0x25202c3134303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3035303266,0x25202c3234303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3135303266,0x25202c3334303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3235303266,0x25202c3434303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3335303266,0x25202c3534303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3435303266,0x25202c3634303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3535303266,0x25202c3734303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3635303266,0x25202c3834303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3735303266,0x25202c3934303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3835303266,0x25202c3035303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3935303266,0x25202c3135303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3036303266,0x25202c3235303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3136303266,0x25202c3335303266\n"
".quad 0x756d090a3b383166,0x2509203233662e6c,0x25202c3236303266,0x25202c3435303266\n"
".quad 0x6461090a3b313266,0x2509203233662e64,0x25202c3336303266,0x25202c3535303266\n"
".quad 0x756d090a3b313266,0x2509203233662e6c,0x25202c3436303266,0x25202c3635303266\n"
".quad 0x6461090a3b303266,0x2509203233662e64,0x25202c3536303266,0x25202c3735303266\n"
".quad 0x756d090a3b303266,0x2509203233662e6c,0x25202c3636303266,0x25202c3835303266\n"
".quad 0x6461090a3b393166,0x2509203233662e64,0x25202c3736303266,0x25202c3935303266\n"
".quad 0x756d090a3b393166,0x2509203233662e6c,0x25202c3836303266,0x25202c3036303266\n"
".quad 0x6461090a3b383166,0x2509203233662e64,0x25202c3936303266,0x25202c3136303266\n"
".quad 0x6c2e090a3b383166,0x383409383209636f,0x2e6c756d090a3009,0x3266250920323366\n"
".quad 0x326625202c303730,0x326625202c323630,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313730,0x326625202c333630,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323730,0x326625202c343630,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333730,0x326625202c353630,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343730,0x316625202c363630,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353730,0x316625202c373630,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363730,0x316625202c383630,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373730,0x316625202c393630,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383730,0x326625202c303730,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393730,0x326625202c313730,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303830,0x326625202c323730,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313830,0x326625202c333730,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323830,0x316625202c343730,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333830,0x316625202c353730,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343830,0x316625202c363730,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353830,0x316625202c373730,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363830,0x326625202c383730,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373830,0x326625202c393730,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383830,0x326625202c303830,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393830,0x326625202c313830,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303930,0x316625202c323830,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313930,0x316625202c333830,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323930,0x316625202c343830,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333930,0x316625202c353830,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343930,0x326625202c363830,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353930,0x326625202c373830,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363930,0x326625202c383830,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373930,0x326625202c393830,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383930,0x316625202c303930,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393930,0x316625202c313930,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303031,0x316625202c323930,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313031,0x316625202c333930,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323031,0x326625202c343930,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333031,0x326625202c353930,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343031,0x326625202c363930,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353031,0x326625202c373930,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363031,0x316625202c383930,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373031,0x316625202c393930,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383031,0x316625202c303031,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393031,0x316625202c313031,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303131,0x326625202c323031,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313131,0x326625202c333031,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323131,0x326625202c343031,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333131,0x326625202c353031,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343131,0x316625202c363031,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353131,0x316625202c373031,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363131,0x316625202c383031,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373131,0x316625202c393031,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383131,0x326625202c303131,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393131,0x326625202c313131,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303231,0x326625202c323131,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313231,0x326625202c333131,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323231,0x316625202c343131,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333231,0x316625202c353131,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343231,0x316625202c363131,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353231,0x316625202c373131,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363231,0x326625202c383131,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373231,0x326625202c393131,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383231,0x326625202c303231,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393231,0x326625202c313231,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303331,0x316625202c323231,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313331,0x316625202c333231,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323331,0x316625202c343231,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333331,0x316625202c353231,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343331,0x326625202c363231,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353331,0x326625202c373231,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363331,0x326625202c383231,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373331,0x326625202c393231,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383331,0x316625202c303331,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393331,0x316625202c313331,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303431,0x316625202c323331,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313431,0x316625202c333331,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323431,0x326625202c343331,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333431,0x326625202c353331,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343431,0x326625202c363331,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353431,0x326625202c373331,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363431,0x316625202c383331,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373431,0x316625202c393331,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383431,0x316625202c303431,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393431,0x316625202c313431,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303531,0x326625202c323431,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313531,0x326625202c333431,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323531,0x326625202c343431,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333531,0x326625202c353431,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343531,0x316625202c363431,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353531,0x316625202c373431,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363531,0x316625202c383431,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373531,0x316625202c393431,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383531,0x326625202c303531,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393531,0x326625202c313531,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303631,0x326625202c323531,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313631,0x326625202c333531,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323631,0x316625202c343531,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333631,0x316625202c353531,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343631,0x316625202c363531,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353631,0x316625202c373531,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363631,0x326625202c383531,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373631,0x326625202c393531,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383631,0x326625202c303631,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393631,0x326625202c313631,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303731,0x316625202c323631,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313731,0x316625202c333631,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323731,0x316625202c343631,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333731,0x316625202c353631,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343731,0x326625202c363631,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353731,0x326625202c373631,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363731,0x326625202c383631,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373731,0x326625202c393631,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383731,0x316625202c303731,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393731,0x316625202c313731,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303831,0x316625202c323731,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313831,0x316625202c333731,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323831,0x326625202c343731,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333831,0x326625202c353731,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343831,0x326625202c363731,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353831,0x326625202c373731,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363831,0x316625202c383731,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373831,0x316625202c393731,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383831,0x316625202c303831,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393831,0x316625202c313831,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303931,0x326625202c323831,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313931,0x326625202c333831,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323931,0x326625202c343831,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333931,0x326625202c353831,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343931,0x316625202c363831,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353931,0x316625202c373831,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363931,0x316625202c383831,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373931,0x316625202c393831,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383931,0x326625202c303931,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393931,0x326625202c313931,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303032,0x326625202c323931,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313032,0x326625202c333931,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323032,0x316625202c343931,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333032,0x316625202c353931,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343032,0x316625202c363931,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353032,0x316625202c373931,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363032,0x326625202c383931,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373032,0x326625202c393931,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383032,0x326625202c303032,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393032,0x326625202c313032,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303132,0x316625202c323032,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313132,0x316625202c333032,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323132,0x316625202c343032,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333132,0x316625202c353032,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343132,0x326625202c363032,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353132,0x326625202c373032,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363132,0x326625202c383032,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373132,0x326625202c393032,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383132,0x316625202c303132,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393132,0x316625202c313132,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303232,0x316625202c323132,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313232,0x316625202c333132,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323232,0x326625202c343132,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333232,0x326625202c353132,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343232,0x326625202c363132,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353232,0x326625202c373132,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363232,0x316625202c383132,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373232,0x316625202c393132,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383232,0x316625202c303232,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393232,0x316625202c313232,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303332,0x326625202c323232,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313332,0x326625202c333232,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323332,0x326625202c343232,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333332,0x326625202c353232,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343332,0x316625202c363232,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353332,0x316625202c373232,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363332,0x316625202c383232,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373332,0x316625202c393232,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383332,0x326625202c303332,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393332,0x326625202c313332,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303432,0x326625202c323332,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313432,0x326625202c333332,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323432,0x316625202c343332,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333432,0x316625202c353332,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343432,0x316625202c363332,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353432,0x316625202c373332,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363432,0x326625202c383332,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373432,0x326625202c393332,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383432,0x326625202c303432,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393432,0x326625202c313432,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303532,0x316625202c323432,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313532,0x316625202c333432,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323532,0x316625202c343432,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333532,0x316625202c353432,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343532,0x326625202c363432,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353532,0x326625202c373432,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363532,0x326625202c383432,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373532,0x326625202c393432,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383532,0x316625202c303532,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393532,0x316625202c313532,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303632,0x316625202c323532,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313632,0x316625202c333532,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323632,0x326625202c343532,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333632,0x326625202c353532,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343632,0x326625202c363532,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353632,0x326625202c373532,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363632,0x316625202c383532,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373632,0x316625202c393532,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383632,0x316625202c303632,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393632,0x316625202c313632,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303732,0x326625202c323632,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313732,0x326625202c333632,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323732,0x326625202c343632,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333732,0x326625202c353632,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343732,0x316625202c363632,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353732,0x316625202c373632,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363732,0x316625202c383632,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373732,0x316625202c393632,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383732,0x326625202c303732,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393732,0x326625202c313732,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303832,0x326625202c323732,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313832,0x326625202c333732,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323832,0x316625202c343732,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333832,0x316625202c353732,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343832,0x316625202c363732,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353832,0x316625202c373732,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363832,0x326625202c383732,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373832,0x326625202c393732,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383832,0x326625202c303832,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393832,0x326625202c313832,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303932,0x316625202c323832,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313932,0x316625202c333832,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323932,0x316625202c343832,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333932,0x316625202c353832,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343932,0x326625202c363832,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353932,0x326625202c373832,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363932,0x326625202c383832,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373932,0x326625202c393832,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383932,0x316625202c303932,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393932,0x316625202c313932,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303033,0x316625202c323932,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313033,0x316625202c333932,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323033,0x326625202c343932,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333033,0x326625202c353932,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343033,0x326625202c363932,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353033,0x326625202c373932,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363033,0x316625202c383932,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373033,0x316625202c393932,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383033,0x316625202c303033,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393033,0x316625202c313033,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303133,0x326625202c323033,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313133,0x326625202c333033,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323133,0x326625202c343033,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333133,0x326625202c353033,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343133,0x316625202c363033,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353133,0x316625202c373033,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363133,0x316625202c383033,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373133,0x316625202c393033,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383133,0x326625202c303133,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393133,0x326625202c313133,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303233,0x326625202c323133,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313233,0x326625202c333133,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323233,0x316625202c343133,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333233,0x316625202c353133,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343233,0x316625202c363133,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353233,0x316625202c373133,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363233,0x326625202c383133,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373233,0x326625202c393133,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383233,0x326625202c303233,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393233,0x326625202c313233,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303333,0x316625202c323233,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313333,0x316625202c333233,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323333,0x316625202c343233,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333333,0x316625202c353233,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343333,0x326625202c363233,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353333,0x326625202c373233,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363333,0x326625202c383233,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373333,0x326625202c393233,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383333,0x316625202c303333,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393333,0x316625202c313333,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303433,0x316625202c323333,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313433,0x316625202c333333,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323433,0x326625202c343333,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333433,0x326625202c353333,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343433,0x326625202c363333,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353433,0x326625202c373333,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363433,0x316625202c383333,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373433,0x316625202c393333,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383433,0x316625202c303433,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393433,0x316625202c313433,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303533,0x326625202c323433,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313533,0x326625202c333433,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323533,0x326625202c343433,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333533,0x326625202c353433,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343533,0x316625202c363433,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353533,0x316625202c373433,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363533,0x316625202c383433,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373533,0x316625202c393433,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383533,0x326625202c303533,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393533,0x326625202c313533,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303633,0x326625202c323533,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313633,0x326625202c333533,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323633,0x316625202c343533,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333633,0x316625202c353533,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343633,0x316625202c363533,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353633,0x316625202c373533,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363633,0x326625202c383533,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373633,0x326625202c393533,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383633,0x326625202c303633,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393633,0x326625202c313633,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303733,0x316625202c323633,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313733,0x316625202c333633,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323733,0x316625202c343633,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333733,0x316625202c353633,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343733,0x326625202c363633,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353733,0x326625202c373633,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363733,0x326625202c383633,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373733,0x326625202c393633,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383733,0x316625202c303733,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393733,0x316625202c313733,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303833,0x316625202c323733,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313833,0x316625202c333733,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323833,0x326625202c343733,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333833,0x326625202c353733,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343833,0x326625202c363733,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353833,0x326625202c373733,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363833,0x316625202c383733,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373833,0x316625202c393733,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383833,0x316625202c303833,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393833,0x316625202c313833,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303933,0x326625202c323833,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313933,0x326625202c333833,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323933,0x326625202c343833,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333933,0x326625202c353833,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343933,0x316625202c363833,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353933,0x316625202c373833,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363933,0x316625202c383833,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373933,0x316625202c393833,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383933,0x326625202c303933,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393933,0x326625202c313933,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303034,0x326625202c323933,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313034,0x326625202c333933,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323034,0x316625202c343933,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333034,0x316625202c353933,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343034,0x316625202c363933,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353034,0x316625202c373933,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363034,0x326625202c383933,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373034,0x326625202c393933,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383034,0x326625202c303034,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393034,0x326625202c313034,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303134,0x316625202c323034,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313134,0x316625202c333034,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323134,0x316625202c343034,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333134,0x316625202c353034,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343134,0x326625202c363034,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353134,0x326625202c373034,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363134,0x326625202c383034,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373134,0x326625202c393034,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383134,0x316625202c303134,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393134,0x316625202c313134,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303234,0x316625202c323134,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313234,0x316625202c333134,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323234,0x326625202c343134,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333234,0x326625202c353134,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343234,0x326625202c363134,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353234,0x326625202c373134,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363234,0x316625202c383134,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373234,0x316625202c393134,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383234,0x316625202c303234,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393234,0x316625202c313234,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303334,0x326625202c323234,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313334,0x326625202c333234,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323334,0x326625202c343234,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333334,0x326625202c353234,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343334,0x316625202c363234,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353334,0x316625202c373234,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363334,0x316625202c383234,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373334,0x316625202c393234,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383334,0x326625202c303334,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393334,0x326625202c313334,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303434,0x326625202c323334,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313434,0x326625202c333334,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323434,0x316625202c343334,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333434,0x316625202c353334,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343434,0x316625202c363334,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353434,0x316625202c373334,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363434,0x326625202c383334,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373434,0x326625202c393334,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383434,0x326625202c303434,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393434,0x326625202c313434,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303534,0x316625202c323434,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313534,0x316625202c333434,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323534,0x316625202c343434,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333534,0x316625202c353434,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343534,0x326625202c363434,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353534,0x326625202c373434,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363534,0x326625202c383434,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373534,0x326625202c393434,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383534,0x316625202c303534,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393534,0x316625202c313534,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303634,0x316625202c323534,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313634,0x316625202c333534,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323634,0x326625202c343534,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333634,0x326625202c353534,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343634,0x326625202c363534,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353634,0x326625202c373534,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363634,0x316625202c383534,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373634,0x316625202c393534,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383634,0x316625202c303634,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393634,0x316625202c313634,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303734,0x326625202c323634,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313734,0x326625202c333634,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323734,0x326625202c343634,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333734,0x326625202c353634,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343734,0x316625202c363634,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353734,0x316625202c373634,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363734,0x316625202c383634,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373734,0x316625202c393634,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383734,0x326625202c303734,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393734,0x326625202c313734,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303834,0x326625202c323734,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313834,0x326625202c333734,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323834,0x316625202c343734,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333834,0x316625202c353734,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343834,0x316625202c363734,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353834,0x316625202c373734,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363834,0x326625202c383734,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373834,0x326625202c393734,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383834,0x326625202c303834,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393834,0x326625202c313834,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303934,0x316625202c323834,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313934,0x316625202c333834,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323934,0x316625202c343834,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333934,0x316625202c353834,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343934,0x326625202c363834,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353934,0x326625202c373834,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363934,0x326625202c383834,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373934,0x326625202c393834,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383934,0x316625202c303934,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393934,0x316625202c313934,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303035,0x316625202c323934,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313035,0x316625202c333934,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323035,0x326625202c343934,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333035,0x326625202c353934,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343035,0x326625202c363934,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353035,0x326625202c373934,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363035,0x316625202c383934,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373035,0x316625202c393934,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383035,0x316625202c303035,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393035,0x316625202c313035,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303135,0x326625202c323035,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313135,0x326625202c333035,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323135,0x326625202c343035,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333135,0x326625202c353035,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343135,0x316625202c363035,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353135,0x316625202c373035,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363135,0x316625202c383035,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373135,0x316625202c393035,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383135,0x326625202c303135,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393135,0x326625202c313135,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303235,0x326625202c323135,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313235,0x326625202c333135,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323235,0x316625202c343135,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333235,0x316625202c353135,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343235,0x316625202c363135,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353235,0x316625202c373135,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363235,0x326625202c383135,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373235,0x326625202c393135,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383235,0x326625202c303235,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393235,0x326625202c313235,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303335,0x316625202c323235,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313335,0x316625202c333235,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323335,0x316625202c343235,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333335,0x316625202c353235,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343335,0x326625202c363235,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353335,0x326625202c373235,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363335,0x326625202c383235,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373335,0x326625202c393235,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383335,0x316625202c303335,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393335,0x316625202c313335,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303435,0x316625202c323335,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313435,0x316625202c333335,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323435,0x326625202c343335,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333435,0x326625202c353335,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343435,0x326625202c363335,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353435,0x326625202c373335,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363435,0x316625202c383335,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373435,0x316625202c393335,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383435,0x316625202c303435,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393435,0x316625202c313435,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303535,0x326625202c323435,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313535,0x326625202c333435,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323535,0x326625202c343435,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333535,0x326625202c353435,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343535,0x316625202c363435,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353535,0x316625202c373435,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363535,0x316625202c383435,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373535,0x316625202c393435,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383535,0x326625202c303535,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393535,0x326625202c313535,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303635,0x326625202c323535,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313635,0x326625202c333535,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323635,0x316625202c343535,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333635,0x316625202c353535,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343635,0x316625202c363535,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353635,0x316625202c373535,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363635,0x326625202c383535,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373635,0x326625202c393535,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383635,0x326625202c303635,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393635,0x326625202c313635,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303735,0x316625202c323635,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313735,0x316625202c333635,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323735,0x316625202c343635,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333735,0x316625202c353635,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343735,0x326625202c363635,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353735,0x326625202c373635,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363735,0x326625202c383635,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373735,0x326625202c393635,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383735,0x316625202c303735,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393735,0x316625202c313735,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303835,0x316625202c323735,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313835,0x316625202c333735,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323835,0x326625202c343735,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333835,0x326625202c353735,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343835,0x326625202c363735,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353835,0x326625202c373735,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363835,0x316625202c383735,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373835,0x316625202c393735,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383835,0x316625202c303835,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393835,0x316625202c313835,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303935,0x326625202c323835,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313935,0x326625202c333835,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323935,0x326625202c343835,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333935,0x326625202c353835,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343935,0x316625202c363835,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353935,0x316625202c373835,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363935,0x316625202c383835,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373935,0x316625202c393835,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383935,0x326625202c303935,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393935,0x326625202c313935,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303036,0x326625202c323935,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313036,0x326625202c333935,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323036,0x316625202c343935,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333036,0x316625202c353935,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343036,0x316625202c363935,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353036,0x316625202c373935,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363036,0x326625202c383935,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373036,0x326625202c393935,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383036,0x326625202c303036,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393036,0x326625202c313036,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303136,0x316625202c323036,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313136,0x316625202c333036,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323136,0x316625202c343036,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333136,0x316625202c353036,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343136,0x326625202c363036,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353136,0x326625202c373036,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363136,0x326625202c383036,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373136,0x326625202c393036,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383136,0x316625202c303136,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393136,0x316625202c313136,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303236,0x316625202c323136,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313236,0x316625202c333136,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323236,0x326625202c343136,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333236,0x326625202c353136,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343236,0x326625202c363136,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353236,0x326625202c373136,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363236,0x316625202c383136,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373236,0x316625202c393136,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383236,0x316625202c303236,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393236,0x316625202c313236,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303336,0x326625202c323236,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313336,0x326625202c333236,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323336,0x326625202c343236,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333336,0x326625202c353236,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343336,0x316625202c363236,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353336,0x316625202c373236,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363336,0x316625202c383236,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373336,0x316625202c393236,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383336,0x326625202c303336,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393336,0x326625202c313336,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303436,0x326625202c323336,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313436,0x326625202c333336,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323436,0x316625202c343336,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333436,0x316625202c353336,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343436,0x316625202c363336,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353436,0x316625202c373336,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363436,0x326625202c383336,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373436,0x326625202c393336,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383436,0x326625202c303436,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393436,0x326625202c313436,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303536,0x316625202c323436,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313536,0x316625202c333436,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323536,0x316625202c343436,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333536,0x316625202c353436,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343536,0x326625202c363436,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353536,0x326625202c373436,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363536,0x326625202c383436,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373536,0x326625202c393436,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383536,0x316625202c303536,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393536,0x316625202c313536,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303636,0x316625202c323536,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313636,0x316625202c333536,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323636,0x326625202c343536,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333636,0x326625202c353536,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343636,0x326625202c363536,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353636,0x326625202c373536,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363636,0x316625202c383536,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373636,0x316625202c393536,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383636,0x316625202c303636,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393636,0x316625202c313636,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303736,0x326625202c323636,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313736,0x326625202c333636,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323736,0x326625202c343636,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333736,0x326625202c353636,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343736,0x316625202c363636,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353736,0x316625202c373636,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363736,0x316625202c383636,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373736,0x316625202c393636,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383736,0x326625202c303736,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393736,0x326625202c313736,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303836,0x326625202c323736,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313836,0x326625202c333736,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323836,0x316625202c343736,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333836,0x316625202c353736,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343836,0x316625202c363736,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353836,0x316625202c373736,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363836,0x326625202c383736,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373836,0x326625202c393736,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383836,0x326625202c303836,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393836,0x326625202c313836,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303936,0x316625202c323836,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313936,0x316625202c333836,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323936,0x316625202c343836,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333936,0x316625202c353836,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343936,0x326625202c363836,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353936,0x326625202c373836,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363936,0x326625202c383836,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373936,0x326625202c393836,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383936,0x316625202c303936,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393936,0x316625202c313936,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303037,0x316625202c323936,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313037,0x316625202c333936,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323037,0x326625202c343936,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333037,0x326625202c353936,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343037,0x326625202c363936,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353037,0x326625202c373936,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363037,0x316625202c383936,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373037,0x316625202c393936,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383037,0x316625202c303037,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393037,0x316625202c313037,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303137,0x326625202c323037,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313137,0x326625202c333037,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323137,0x326625202c343037,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333137,0x326625202c353037,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343137,0x316625202c363037,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353137,0x316625202c373037,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363137,0x316625202c383037,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373137,0x316625202c393037,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383137,0x326625202c303137,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393137,0x326625202c313137,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303237,0x326625202c323137,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313237,0x326625202c333137,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323237,0x316625202c343137,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333237,0x316625202c353137,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343237,0x316625202c363137,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353237,0x316625202c373137,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363237,0x326625202c383137,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373237,0x326625202c393137,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383237,0x326625202c303237,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393237,0x326625202c313237,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303337,0x316625202c323237,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313337,0x316625202c333237,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323337,0x316625202c343237,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333337,0x316625202c353237,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343337,0x326625202c363237,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353337,0x326625202c373237,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363337,0x326625202c383237,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373337,0x326625202c393237,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383337,0x316625202c303337,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393337,0x316625202c313337,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303437,0x316625202c323337,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313437,0x316625202c333337,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323437,0x326625202c343337,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333437,0x326625202c353337,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343437,0x326625202c363337,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353437,0x326625202c373337,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363437,0x316625202c383337,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373437,0x316625202c393337,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383437,0x316625202c303437,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393437,0x316625202c313437,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303537,0x326625202c323437,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313537,0x326625202c333437,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323537,0x326625202c343437,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333537,0x326625202c353437,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343537,0x316625202c363437,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353537,0x316625202c373437,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363537,0x316625202c383437,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373537,0x316625202c393437,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383537,0x326625202c303537,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393537,0x326625202c313537,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303637,0x326625202c323537,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313637,0x326625202c333537,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323637,0x316625202c343537,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333637,0x316625202c353537,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343637,0x316625202c363537,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353637,0x316625202c373537,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363637,0x326625202c383537,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373637,0x326625202c393537,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383637,0x326625202c303637,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393637,0x326625202c313637,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303737,0x316625202c323637,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313737,0x316625202c333637,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323737,0x316625202c343637,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333737,0x316625202c353637,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343737,0x326625202c363637,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353737,0x326625202c373637,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363737,0x326625202c383637,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373737,0x326625202c393637,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383737,0x316625202c303737,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393737,0x316625202c313737,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303837,0x316625202c323737,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313837,0x316625202c333737,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323837,0x326625202c343737,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333837,0x326625202c353737,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343837,0x326625202c363737,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353837,0x326625202c373737,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363837,0x316625202c383737,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373837,0x316625202c393737,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383837,0x316625202c303837,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393837,0x316625202c313837,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303937,0x326625202c323837,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313937,0x326625202c333837,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323937,0x326625202c343837,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333937,0x326625202c353837,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343937,0x316625202c363837,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353937,0x316625202c373837,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363937,0x316625202c383837,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373937,0x316625202c393837,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383937,0x326625202c303937,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393937,0x326625202c313937,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303038,0x326625202c323937,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313038,0x326625202c333937,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323038,0x316625202c343937,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333038,0x316625202c353937,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343038,0x316625202c363937,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353038,0x316625202c373937,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363038,0x326625202c383937,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373038,0x326625202c393937,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383038,0x326625202c303038,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393038,0x326625202c313038,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303138,0x316625202c323038,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313138,0x316625202c333038,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323138,0x316625202c343038,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333138,0x316625202c353038,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343138,0x326625202c363038,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353138,0x326625202c373038,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363138,0x326625202c383038,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373138,0x326625202c393038,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383138,0x316625202c303138,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393138,0x316625202c313138,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303238,0x316625202c323138,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313238,0x316625202c333138,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323238,0x326625202c343138,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333238,0x326625202c353138,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343238,0x326625202c363138,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353238,0x326625202c373138,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363238,0x316625202c383138,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373238,0x316625202c393138,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383238,0x316625202c303238,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393238,0x316625202c313238,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303338,0x326625202c323238,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313338,0x326625202c333238,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323338,0x326625202c343238,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333338,0x326625202c353238,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343338,0x316625202c363238,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353338,0x316625202c373238,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363338,0x316625202c383238,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373338,0x316625202c393238,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383338,0x326625202c303338,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393338,0x326625202c313338,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303438,0x326625202c323338,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313438,0x326625202c333338,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323438,0x316625202c343338,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333438,0x316625202c353338,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343438,0x316625202c363338,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353438,0x316625202c373338,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363438,0x326625202c383338,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373438,0x326625202c393338,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383438,0x326625202c303438,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393438,0x326625202c313438,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303538,0x316625202c323438,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313538,0x316625202c333438,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323538,0x316625202c343438,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333538,0x316625202c353438,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343538,0x326625202c363438,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353538,0x326625202c373438,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363538,0x326625202c383438,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373538,0x326625202c393438,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383538,0x316625202c303538,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393538,0x316625202c313538,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303638,0x316625202c323538,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313638,0x316625202c333538,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323638,0x326625202c343538,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333638,0x326625202c353538,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343638,0x326625202c363538,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353638,0x326625202c373538,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363638,0x316625202c383538,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373638,0x316625202c393538,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383638,0x316625202c303638,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393638,0x316625202c313638,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303738,0x326625202c323638,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313738,0x326625202c333638,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323738,0x326625202c343638,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333738,0x326625202c353638,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343738,0x316625202c363638,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353738,0x316625202c373638,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363738,0x316625202c383638,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373738,0x316625202c393638,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383738,0x326625202c303738,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393738,0x326625202c313738,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303838,0x326625202c323738,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313838,0x326625202c333738,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323838,0x316625202c343738,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333838,0x316625202c353738,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343838,0x316625202c363738,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353838,0x316625202c373738,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363838,0x326625202c383738,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373838,0x326625202c393738,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383838,0x326625202c303838,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393838,0x326625202c313838,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303938,0x316625202c323838,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313938,0x316625202c333838,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323938,0x316625202c343838,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333938,0x316625202c353838,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343938,0x326625202c363838,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353938,0x326625202c373838,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363938,0x326625202c383838,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373938,0x326625202c393838,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383938,0x316625202c303938,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393938,0x316625202c313938,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303039,0x316625202c323938,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313039,0x316625202c333938,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323039,0x326625202c343938,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333039,0x326625202c353938,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343039,0x326625202c363938,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353039,0x326625202c373938,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363039,0x316625202c383938,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373039,0x316625202c393938,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383039,0x316625202c303039,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393039,0x316625202c313039,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303139,0x326625202c323039,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313139,0x326625202c333039,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323139,0x326625202c343039,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333139,0x326625202c353039,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343139,0x316625202c363039,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353139,0x316625202c373039,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363139,0x316625202c383039,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373139,0x316625202c393039,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383139,0x326625202c303139,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393139,0x326625202c313139,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303239,0x326625202c323139,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313239,0x326625202c333139,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323239,0x316625202c343139,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333239,0x316625202c353139,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343239,0x316625202c363139,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353239,0x316625202c373139,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363239,0x326625202c383139,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373239,0x326625202c393139,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383239,0x326625202c303239,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393239,0x326625202c313239,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303339,0x316625202c323239,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313339,0x316625202c333239,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323339,0x316625202c343239,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333339,0x316625202c353239,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343339,0x326625202c363239,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353339,0x326625202c373239,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363339,0x326625202c383239,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373339,0x326625202c393239,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383339,0x316625202c303339,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393339,0x316625202c313339,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303439,0x316625202c323339,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313439,0x316625202c333339,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323439,0x326625202c343339,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333439,0x326625202c353339,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343439,0x326625202c363339,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353439,0x326625202c373339,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363439,0x316625202c383339,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373439,0x316625202c393339,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383439,0x316625202c303439,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393439,0x316625202c313439,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303539,0x326625202c323439,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313539,0x326625202c333439,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323539,0x326625202c343439,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333539,0x326625202c353439,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343539,0x316625202c363439,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353539,0x316625202c373439,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363539,0x316625202c383439,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373539,0x316625202c393439,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383539,0x326625202c303539,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393539,0x326625202c313539,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c303639,0x326625202c323539,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c313639,0x326625202c333539,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c323639,0x316625202c343539,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c333639,0x316625202c353539,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c343639,0x316625202c363539,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c353639,0x316625202c373539,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c363639,0x326625202c383539,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c373639,0x326625202c393539,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c383639,0x326625202c303639,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c393639,0x326625202c313639,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c303739,0x316625202c323639,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c313739,0x316625202c333639,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c323739,0x316625202c343639,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c333739,0x316625202c353639,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c343739,0x326625202c363639,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c353739,0x326625202c373639,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c363739,0x326625202c383639,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c373739,0x326625202c393639,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c383739,0x316625202c303739,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c393739,0x316625202c313739,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c303839,0x316625202c323739,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c313839,0x316625202c333739,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c323839,0x326625202c343739,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c333839,0x326625202c353739,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c343839,0x326625202c363739,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c353839,0x326625202c373739,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c363839,0x316625202c383739,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c373839,0x316625202c393739,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c383839,0x316625202c303839,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c393839,0x316625202c313839,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c303939,0x326625202c323839,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c313939,0x326625202c333839,0x2e6c756d090a3b31,0x3266250920323366\n"
".quad 0x326625202c323939,0x326625202c343839,0x2e646461090a3b30,0x3266250920323366\n"
".quad 0x326625202c333939,0x326625202c353839,0x2e6c756d090a3b30,0x3266250920323366\n"
".quad 0x326625202c343939,0x316625202c363839,0x2e646461090a3b39,0x3266250920323366\n"
".quad 0x326625202c353939,0x316625202c373839,0x2e6c756d090a3b39,0x3266250920323366\n"
".quad 0x326625202c363939,0x316625202c383839,0x2e646461090a3b38,0x3266250920323366\n"
".quad 0x326625202c373939,0x316625202c393839,0x2e6c756d090a3b38,0x3266250920323366\n"
".quad 0x326625202c383939,0x326625202c303939,0x2e646461090a3b31,0x3266250920323366\n"
".quad 0x326625202c393939,0x326625202c313939,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x326625202c303030,0x326625202c323939,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x326625202c313030,0x326625202c333939,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x326625202c323030,0x316625202c343939,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x326625202c333030,0x316625202c353939,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x326625202c343030,0x316625202c363939,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x326625202c353030,0x316625202c373939,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x326625202c363030,0x326625202c383939,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x326625202c373030,0x326625202c393939,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383030,0x326625202c303030,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393030,0x326625202c313030,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303130,0x316625202c323030,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313130,0x316625202c333030,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323130,0x316625202c343030,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333130,0x316625202c353030,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343130,0x326625202c363030,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353130,0x326625202c373030,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363130,0x326625202c383030,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373130,0x326625202c393030,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383130,0x316625202c303130,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393130,0x316625202c313130,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303230,0x316625202c323130,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313230,0x316625202c333130,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323230,0x326625202c343130,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333230,0x326625202c353130,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343230,0x326625202c363130,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353230,0x326625202c373130,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363230,0x316625202c383130,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373230,0x316625202c393130,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383230,0x316625202c303230,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393230,0x316625202c313230,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303330,0x326625202c323230,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313330,0x326625202c333230,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323330,0x326625202c343230,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333330,0x326625202c353230,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343330,0x316625202c363230,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353330,0x316625202c373230,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363330,0x316625202c383230,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373330,0x316625202c393230,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383330,0x326625202c303330,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393330,0x326625202c313330,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303430,0x326625202c323330,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313430,0x326625202c333330,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323430,0x316625202c343330,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333430,0x316625202c353330,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343430,0x316625202c363330,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353430,0x316625202c373330,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363430,0x326625202c383330,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373430,0x326625202c393330,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383430,0x326625202c303430,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393430,0x326625202c313430,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303530,0x316625202c323430,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313530,0x316625202c333430,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323530,0x316625202c343430,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333530,0x316625202c353430,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343530,0x326625202c363430,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353530,0x326625202c373430,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363530,0x326625202c383430,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373530,0x326625202c393430,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383530,0x316625202c303530,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393530,0x316625202c313530,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303630,0x316625202c323530,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313630,0x316625202c333530,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323630,0x326625202c343530,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333630,0x326625202c353530,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343630,0x326625202c363530,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353630,0x326625202c373530,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363630,0x316625202c383530,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373630,0x316625202c393530,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383630,0x316625202c303630,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393630,0x316625202c313630,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303730,0x326625202c323630,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313730,0x326625202c333630,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323730,0x326625202c343630,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333730,0x326625202c353630,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343730,0x316625202c363630,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353730,0x316625202c373630,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363730,0x316625202c383630,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373730,0x316625202c393630,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383730,0x326625202c303730,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393730,0x326625202c313730,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303830,0x326625202c323730,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313830,0x326625202c333730,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323830,0x316625202c343730,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333830,0x316625202c353730,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343830,0x316625202c363730,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353830,0x316625202c373730,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363830,0x326625202c383730,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373830,0x326625202c393730,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383830,0x326625202c303830,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393830,0x326625202c313830,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303930,0x316625202c323830,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313930,0x316625202c333830,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323930,0x316625202c343830,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333930,0x316625202c353830,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343930,0x326625202c363830,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353930,0x326625202c373830,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363930,0x326625202c383830,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373930,0x326625202c393830,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383930,0x316625202c303930,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393930,0x316625202c313930,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303031,0x316625202c323930,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313031,0x316625202c333930,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323031,0x326625202c343930,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333031,0x326625202c353930,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343031,0x326625202c363930,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353031,0x326625202c373930,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363031,0x316625202c383930,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373031,0x316625202c393930,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383031,0x316625202c303031,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393031,0x316625202c313031,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303131,0x326625202c323031,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313131,0x326625202c333031,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323131,0x326625202c343031,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333131,0x326625202c353031,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343131,0x316625202c363031,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353131,0x316625202c373031,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363131,0x316625202c383031,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373131,0x316625202c393031,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383131,0x326625202c303131,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393131,0x326625202c313131,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303231,0x326625202c323131,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313231,0x326625202c333131,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323231,0x316625202c343131,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333231,0x316625202c353131,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343231,0x316625202c363131,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353231,0x316625202c373131,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363231,0x326625202c383131,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373231,0x326625202c393131,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383231,0x326625202c303231,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393231,0x326625202c313231,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303331,0x316625202c323231,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313331,0x316625202c333231,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323331,0x316625202c343231,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333331,0x316625202c353231,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343331,0x326625202c363231,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353331,0x326625202c373231,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363331,0x326625202c383231,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373331,0x326625202c393231,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383331,0x316625202c303331,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393331,0x316625202c313331,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303431,0x316625202c323331,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313431,0x316625202c333331,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323431,0x326625202c343331,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333431,0x326625202c353331,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343431,0x326625202c363331,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353431,0x326625202c373331,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363431,0x316625202c383331,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373431,0x316625202c393331,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383431,0x316625202c303431,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393431,0x316625202c313431,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303531,0x326625202c323431,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313531,0x326625202c333431,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323531,0x326625202c343431,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333531,0x326625202c353431,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343531,0x316625202c363431,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353531,0x316625202c373431,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363531,0x316625202c383431,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373531,0x316625202c393431,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383531,0x326625202c303531,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393531,0x326625202c313531,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303631,0x326625202c323531,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313631,0x326625202c333531,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323631,0x316625202c343531,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333631,0x316625202c353531,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343631,0x316625202c363531,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353631,0x316625202c373531,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363631,0x326625202c383531,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373631,0x326625202c393531,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383631,0x326625202c303631,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393631,0x326625202c313631,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303731,0x316625202c323631,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313731,0x316625202c333631,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323731,0x316625202c343631,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333731,0x316625202c353631,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343731,0x326625202c363631,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353731,0x326625202c373631,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363731,0x326625202c383631,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373731,0x326625202c393631,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383731,0x316625202c303731,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393731,0x316625202c313731,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303831,0x316625202c323731,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313831,0x316625202c333731,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323831,0x326625202c343731,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333831,0x326625202c353731,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343831,0x326625202c363731,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353831,0x326625202c373731,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363831,0x316625202c383731,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373831,0x316625202c393731,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383831,0x316625202c303831,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393831,0x316625202c313831,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303931,0x326625202c323831,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313931,0x326625202c333831,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323931,0x326625202c343831,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333931,0x326625202c353831,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343931,0x316625202c363831,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353931,0x316625202c373831,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363931,0x316625202c383831,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373931,0x316625202c393831,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383931,0x326625202c303931,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393931,0x326625202c313931,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303032,0x326625202c323931,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313032,0x326625202c333931,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323032,0x316625202c343931,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333032,0x316625202c353931,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343032,0x316625202c363931,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353032,0x316625202c373931,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363032,0x326625202c383931,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373032,0x326625202c393931,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383032,0x326625202c303032,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393032,0x326625202c313032,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303132,0x316625202c323032,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313132,0x316625202c333032,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323132,0x316625202c343032,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333132,0x316625202c353032,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343132,0x326625202c363032,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353132,0x326625202c373032,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363132,0x326625202c383032,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373132,0x326625202c393032,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383132,0x316625202c303132,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393132,0x316625202c313132,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303232,0x316625202c323132,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313232,0x316625202c333132,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323232,0x326625202c343132,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333232,0x326625202c353132,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343232,0x326625202c363132,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353232,0x326625202c373132,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363232,0x316625202c383132,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373232,0x316625202c393132,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383232,0x316625202c303232,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393232,0x316625202c313232,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303332,0x326625202c323232,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313332,0x326625202c333232,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323332,0x326625202c343232,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333332,0x326625202c353232,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343332,0x316625202c363232,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353332,0x316625202c373232,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363332,0x316625202c383232,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373332,0x316625202c393232,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383332,0x326625202c303332,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393332,0x326625202c313332,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303432,0x326625202c323332,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313432,0x326625202c333332,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323432,0x316625202c343332,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333432,0x316625202c353332,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343432,0x316625202c363332,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353432,0x316625202c373332,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363432,0x326625202c383332,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373432,0x326625202c393332,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383432,0x326625202c303432,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393432,0x326625202c313432,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303532,0x316625202c323432,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313532,0x316625202c333432,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323532,0x316625202c343432,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333532,0x316625202c353432,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343532,0x326625202c363432,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353532,0x326625202c373432,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363532,0x326625202c383432,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373532,0x326625202c393432,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383532,0x316625202c303532,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393532,0x316625202c313532,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303632,0x316625202c323532,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313632,0x316625202c333532,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323632,0x326625202c343532,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333632,0x326625202c353532,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343632,0x326625202c363532,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353632,0x326625202c373532,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363632,0x316625202c383532,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373632,0x316625202c393532,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383632,0x316625202c303632,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393632,0x316625202c313632,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303732,0x326625202c323632,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313732,0x326625202c333632,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323732,0x326625202c343632,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333732,0x326625202c353632,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343732,0x316625202c363632,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353732,0x316625202c373632,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363732,0x316625202c383632,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373732,0x316625202c393632,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383732,0x326625202c303732,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393732,0x326625202c313732,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303832,0x326625202c323732,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313832,0x326625202c333732,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323832,0x316625202c343732,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333832,0x316625202c353732,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343832,0x316625202c363732,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353832,0x316625202c373732,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363832,0x326625202c383732,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373832,0x326625202c393732,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383832,0x326625202c303832,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393832,0x326625202c313832,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303932,0x316625202c323832,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313932,0x316625202c333832,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323932,0x316625202c343832,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333932,0x316625202c353832,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343932,0x326625202c363832,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353932,0x326625202c373832,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363932,0x326625202c383832,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373932,0x326625202c393832,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383932,0x316625202c303932,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393932,0x316625202c313932,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303033,0x316625202c323932,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313033,0x316625202c333932,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323033,0x326625202c343932,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333033,0x326625202c353932,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343033,0x326625202c363932,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353033,0x326625202c373932,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363033,0x316625202c383932,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373033,0x316625202c393932,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383033,0x316625202c303033,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393033,0x316625202c313033,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303133,0x326625202c323033,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313133,0x326625202c333033,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323133,0x326625202c343033,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333133,0x326625202c353033,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343133,0x316625202c363033,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353133,0x316625202c373033,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363133,0x316625202c383033,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373133,0x316625202c393033,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383133,0x326625202c303133,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393133,0x326625202c313133,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303233,0x326625202c323133,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313233,0x326625202c333133,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323233,0x316625202c343133,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333233,0x316625202c353133,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343233,0x316625202c363133,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353233,0x316625202c373133,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363233,0x326625202c383133,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373233,0x326625202c393133,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383233,0x326625202c303233,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393233,0x326625202c313233,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303333,0x316625202c323233,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313333,0x316625202c333233,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323333,0x316625202c343233,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333333,0x316625202c353233,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343333,0x326625202c363233,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353333,0x326625202c373233,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363333,0x326625202c383233,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373333,0x326625202c393233,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383333,0x316625202c303333,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393333,0x316625202c313333,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303433,0x316625202c323333,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313433,0x316625202c333333,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323433,0x326625202c343333,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333433,0x326625202c353333,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343433,0x326625202c363333,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353433,0x326625202c373333,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363433,0x316625202c383333,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373433,0x316625202c393333,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383433,0x316625202c303433,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393433,0x316625202c313433,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303533,0x326625202c323433,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313533,0x326625202c333433,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323533,0x326625202c343433,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333533,0x326625202c353433,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343533,0x316625202c363433,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353533,0x316625202c373433,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363533,0x316625202c383433,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373533,0x316625202c393433,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383533,0x326625202c303533,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393533,0x326625202c313533,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303633,0x326625202c323533,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313633,0x326625202c333533,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323633,0x316625202c343533,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333633,0x316625202c353533,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343633,0x316625202c363533,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353633,0x316625202c373533,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363633,0x326625202c383533,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373633,0x326625202c393533,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383633,0x326625202c303633,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393633,0x326625202c313633,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303733,0x316625202c323633,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313733,0x316625202c333633,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323733,0x316625202c343633,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333733,0x316625202c353633,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343733,0x326625202c363633,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353733,0x326625202c373633,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363733,0x326625202c383633,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373733,0x326625202c393633,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383733,0x316625202c303733,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393733,0x316625202c313733,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303833,0x316625202c323733,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313833,0x316625202c333733,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323833,0x326625202c343733,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333833,0x326625202c353733,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343833,0x326625202c363733,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353833,0x326625202c373733,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363833,0x316625202c383733,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373833,0x316625202c393733,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383833,0x316625202c303833,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393833,0x316625202c313833,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303933,0x326625202c323833,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313933,0x326625202c333833,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323933,0x326625202c343833,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333933,0x326625202c353833,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343933,0x316625202c363833,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353933,0x316625202c373833,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363933,0x316625202c383833,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373933,0x316625202c393833,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383933,0x326625202c303933,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393933,0x326625202c313933,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303034,0x326625202c323933,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313034,0x326625202c333933,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323034,0x316625202c343933,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333034,0x316625202c353933,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343034,0x316625202c363933,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353034,0x316625202c373933,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363034,0x326625202c383933,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373034,0x326625202c393933,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383034,0x326625202c303034,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393034,0x326625202c313034,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303134,0x316625202c323034,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313134,0x316625202c333034,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323134,0x316625202c343034,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333134,0x316625202c353034,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343134,0x326625202c363034,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353134,0x326625202c373034,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363134,0x326625202c383034,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373134,0x326625202c393034,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383134,0x316625202c303134,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393134,0x316625202c313134,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303234,0x316625202c323134,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313234,0x316625202c333134,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323234,0x326625202c343134,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333234,0x326625202c353134,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343234,0x326625202c363134,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353234,0x326625202c373134,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363234,0x316625202c383134,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373234,0x316625202c393134,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383234,0x316625202c303234,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393234,0x316625202c313234,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303334,0x326625202c323234,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313334,0x326625202c333234,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323334,0x326625202c343234,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333334,0x326625202c353234,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343334,0x316625202c363234,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353334,0x316625202c373234,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363334,0x316625202c383234,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373334,0x316625202c393234,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383334,0x326625202c303334,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393334,0x326625202c313334,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303434,0x326625202c323334,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313434,0x326625202c333334,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323434,0x316625202c343334,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333434,0x316625202c353334,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343434,0x316625202c363334,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353434,0x316625202c373334,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363434,0x326625202c383334,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373434,0x326625202c393334,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383434,0x326625202c303434,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393434,0x326625202c313434,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303534,0x316625202c323434,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313534,0x316625202c333434,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323534,0x316625202c343434,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333534,0x316625202c353434,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343534,0x326625202c363434,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353534,0x326625202c373434,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363534,0x326625202c383434,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373534,0x326625202c393434,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383534,0x316625202c303534,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393534,0x316625202c313534,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303634,0x316625202c323534,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313634,0x316625202c333534,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323634,0x326625202c343534,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333634,0x326625202c353534,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343634,0x326625202c363534,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353634,0x326625202c373534,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363634,0x316625202c383534,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373634,0x316625202c393534,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383634,0x316625202c303634,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393634,0x316625202c313634,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303734,0x326625202c323634,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313734,0x326625202c333634,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323734,0x326625202c343634,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333734,0x326625202c353634,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343734,0x316625202c363634,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353734,0x316625202c373634,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363734,0x316625202c383634,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373734,0x316625202c393634,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383734,0x326625202c303734,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393734,0x326625202c313734,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303834,0x326625202c323734,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313834,0x326625202c333734,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323834,0x316625202c343734,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333834,0x316625202c353734,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343834,0x316625202c363734,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353834,0x316625202c373734,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363834,0x326625202c383734,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373834,0x326625202c393734,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383834,0x326625202c303834,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393834,0x326625202c313834,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303934,0x316625202c323834,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313934,0x316625202c333834,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323934,0x316625202c343834,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333934,0x316625202c353834,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343934,0x326625202c363834,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353934,0x326625202c373834,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363934,0x326625202c383834,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373934,0x326625202c393834,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383934,0x316625202c303934,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393934,0x316625202c313934,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303035,0x316625202c323934,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313035,0x316625202c333934,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323035,0x326625202c343934,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333035,0x326625202c353934,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343035,0x326625202c363934,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353035,0x326625202c373934,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363035,0x316625202c383934,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373035,0x316625202c393934,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383035,0x316625202c303035,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393035,0x316625202c313035,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303135,0x326625202c323035,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313135,0x326625202c333035,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323135,0x326625202c343035,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333135,0x326625202c353035,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343135,0x316625202c363035,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353135,0x316625202c373035,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363135,0x316625202c383035,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373135,0x316625202c393035,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383135,0x326625202c303135,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393135,0x326625202c313135,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303235,0x326625202c323135,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313235,0x326625202c333135,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323235,0x316625202c343135,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333235,0x316625202c353135,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343235,0x316625202c363135,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353235,0x316625202c373135,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363235,0x326625202c383135,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373235,0x326625202c393135,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383235,0x326625202c303235,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393235,0x326625202c313235,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303335,0x316625202c323235,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313335,0x316625202c333235,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323335,0x316625202c343235,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333335,0x316625202c353235,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343335,0x326625202c363235,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353335,0x326625202c373235,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363335,0x326625202c383235,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373335,0x326625202c393235,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383335,0x316625202c303335,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393335,0x316625202c313335,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303435,0x316625202c323335,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313435,0x316625202c333335,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323435,0x326625202c343335,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333435,0x326625202c353335,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343435,0x326625202c363335,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353435,0x326625202c373335,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363435,0x316625202c383335,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373435,0x316625202c393335,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383435,0x316625202c303435,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393435,0x316625202c313435,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303535,0x326625202c323435,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313535,0x326625202c333435,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323535,0x326625202c343435,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333535,0x326625202c353435,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343535,0x316625202c363435,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353535,0x316625202c373435,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363535,0x316625202c383435,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373535,0x316625202c393435,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383535,0x326625202c303535,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393535,0x326625202c313535,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303635,0x326625202c323535,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313635,0x326625202c333535,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323635,0x316625202c343535,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333635,0x316625202c353535,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343635,0x316625202c363535,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353635,0x316625202c373535,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363635,0x326625202c383535,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373635,0x326625202c393535,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383635,0x326625202c303635,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393635,0x326625202c313635,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303735,0x316625202c323635,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313735,0x316625202c333635,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323735,0x316625202c343635,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333735,0x316625202c353635,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343735,0x326625202c363635,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353735,0x326625202c373635,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363735,0x326625202c383635,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373735,0x326625202c393635,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383735,0x316625202c303735,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393735,0x316625202c313735,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303835,0x316625202c323735,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313835,0x316625202c333735,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323835,0x326625202c343735,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333835,0x326625202c353735,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343835,0x326625202c363735,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353835,0x326625202c373735,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363835,0x316625202c383735,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373835,0x316625202c393735,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383835,0x316625202c303835,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393835,0x316625202c313835,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303935,0x326625202c323835,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313935,0x326625202c333835,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323935,0x326625202c343835,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333935,0x326625202c353835,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343935,0x316625202c363835,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353935,0x316625202c373835,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363935,0x316625202c383835,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373935,0x316625202c393835,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383935,0x326625202c303935,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393935,0x326625202c313935,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303036,0x326625202c323935,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313036,0x326625202c333935,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323036,0x316625202c343935,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333036,0x316625202c353935,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343036,0x316625202c363935,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353036,0x316625202c373935,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363036,0x326625202c383935,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373036,0x326625202c393935,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383036,0x326625202c303036,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393036,0x326625202c313036,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303136,0x316625202c323036,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313136,0x316625202c333036,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323136,0x316625202c343036,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333136,0x316625202c353036,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343136,0x326625202c363036,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353136,0x326625202c373036,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363136,0x326625202c383036,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373136,0x326625202c393036,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383136,0x316625202c303136,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393136,0x316625202c313136,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303236,0x316625202c323136,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313236,0x316625202c333136,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323236,0x326625202c343136,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333236,0x326625202c353136,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343236,0x326625202c363136,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353236,0x326625202c373136,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363236,0x316625202c383136,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373236,0x316625202c393136,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383236,0x316625202c303236,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393236,0x316625202c313236,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303336,0x326625202c323236,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313336,0x326625202c333236,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323336,0x326625202c343236,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333336,0x326625202c353236,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343336,0x316625202c363236,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353336,0x316625202c373236,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363336,0x316625202c383236,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373336,0x316625202c393236,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383336,0x326625202c303336,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393336,0x326625202c313336,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303436,0x326625202c323336,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313436,0x326625202c333336,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323436,0x316625202c343336,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333436,0x316625202c353336,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343436,0x316625202c363336,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353436,0x316625202c373336,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363436,0x326625202c383336,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373436,0x326625202c393336,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383436,0x326625202c303436,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393436,0x326625202c313436,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303536,0x316625202c323436,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313536,0x316625202c333436,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323536,0x316625202c343436,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333536,0x316625202c353436,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343536,0x326625202c363436,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353536,0x326625202c373436,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363536,0x326625202c383436,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373536,0x326625202c393436,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383536,0x316625202c303536,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393536,0x316625202c313536,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303636,0x316625202c323536,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313636,0x316625202c333536,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323636,0x326625202c343536,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333636,0x326625202c353536,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343636,0x326625202c363536,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353636,0x326625202c373536,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363636,0x316625202c383536,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373636,0x316625202c393536,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383636,0x316625202c303636,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393636,0x316625202c313636,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303736,0x326625202c323636,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313736,0x326625202c333636,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323736,0x326625202c343636,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333736,0x326625202c353636,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343736,0x316625202c363636,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353736,0x316625202c373636,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363736,0x316625202c383636,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373736,0x316625202c393636,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383736,0x326625202c303736,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393736,0x326625202c313736,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303836,0x326625202c323736,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313836,0x326625202c333736,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323836,0x316625202c343736,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333836,0x316625202c353736,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343836,0x316625202c363736,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353836,0x316625202c373736,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363836,0x326625202c383736,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373836,0x326625202c393736,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383836,0x326625202c303836,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393836,0x326625202c313836,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303936,0x316625202c323836,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313936,0x316625202c333836,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323936,0x316625202c343836,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333936,0x316625202c353836,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343936,0x326625202c363836,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353936,0x326625202c373836,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363936,0x326625202c383836,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373936,0x326625202c393836,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383936,0x316625202c303936,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393936,0x316625202c313936,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303037,0x316625202c323936,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313037,0x316625202c333936,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323037,0x326625202c343936,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333037,0x326625202c353936,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343037,0x326625202c363936,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353037,0x326625202c373936,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363037,0x316625202c383936,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373037,0x316625202c393936,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383037,0x316625202c303037,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393037,0x316625202c313037,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303137,0x326625202c323037,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313137,0x326625202c333037,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323137,0x326625202c343037,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333137,0x326625202c353037,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343137,0x316625202c363037,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353137,0x316625202c373037,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363137,0x316625202c383037,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373137,0x316625202c393037,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383137,0x326625202c303137,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393137,0x326625202c313137,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303237,0x326625202c323137,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313237,0x326625202c333137,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323237,0x316625202c343137,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333237,0x316625202c353137,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343237,0x316625202c363137,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353237,0x316625202c373137,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363237,0x326625202c383137,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373237,0x326625202c393137,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383237,0x326625202c303237,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393237,0x326625202c313237,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303337,0x316625202c323237,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313337,0x316625202c333237,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323337,0x316625202c343237,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333337,0x316625202c353237,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343337,0x326625202c363237,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353337,0x326625202c373237,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363337,0x326625202c383237,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373337,0x326625202c393237,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383337,0x316625202c303337,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393337,0x316625202c313337,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303437,0x316625202c323337,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313437,0x316625202c333337,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323437,0x326625202c343337,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333437,0x326625202c353337,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343437,0x326625202c363337,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353437,0x326625202c373337,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363437,0x316625202c383337,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373437,0x316625202c393337,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383437,0x316625202c303437,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393437,0x316625202c313437,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303537,0x326625202c323437,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313537,0x326625202c333437,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323537,0x326625202c343437,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333537,0x326625202c353437,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343537,0x316625202c363437,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353537,0x316625202c373437,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363537,0x316625202c383437,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373537,0x316625202c393437,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383537,0x326625202c303537,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393537,0x326625202c313537,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303637,0x326625202c323537,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313637,0x326625202c333537,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323637,0x316625202c343537,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333637,0x316625202c353537,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343637,0x316625202c363537,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353637,0x316625202c373537,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363637,0x326625202c383537,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373637,0x326625202c393537,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383637,0x326625202c303637,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393637,0x326625202c313637,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303737,0x316625202c323637,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313737,0x316625202c333637,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323737,0x316625202c343637,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333737,0x316625202c353637,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343737,0x326625202c363637,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353737,0x326625202c373637,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363737,0x326625202c383637,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373737,0x326625202c393637,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383737,0x316625202c303737,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393737,0x316625202c313737,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303837,0x316625202c323737,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313837,0x316625202c333737,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323837,0x326625202c343737,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333837,0x326625202c353737,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343837,0x326625202c363737,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353837,0x326625202c373737,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363837,0x316625202c383737,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373837,0x316625202c393737,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383837,0x316625202c303837,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393837,0x316625202c313837,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303937,0x326625202c323837,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313937,0x326625202c333837,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323937,0x326625202c343837,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333937,0x326625202c353837,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343937,0x316625202c363837,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353937,0x316625202c373837,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363937,0x316625202c383837,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373937,0x316625202c393837,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383937,0x326625202c303937,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393937,0x326625202c313937,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303038,0x326625202c323937,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313038,0x326625202c333937,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323038,0x316625202c343937,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333038,0x316625202c353937,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343038,0x316625202c363937,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353038,0x316625202c373937,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363038,0x326625202c383937,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373038,0x326625202c393937,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383038,0x326625202c303038,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393038,0x326625202c313038,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303138,0x316625202c323038,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313138,0x316625202c333038,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323138,0x316625202c343038,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333138,0x316625202c353038,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343138,0x326625202c363038,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353138,0x326625202c373038,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363138,0x326625202c383038,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373138,0x326625202c393038,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383138,0x316625202c303138,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393138,0x316625202c313138,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303238,0x316625202c323138,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313238,0x316625202c333138,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323238,0x326625202c343138,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333238,0x326625202c353138,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343238,0x326625202c363138,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353238,0x326625202c373138,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363238,0x316625202c383138,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373238,0x316625202c393138,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383238,0x316625202c303238,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393238,0x316625202c313238,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303338,0x326625202c323238,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313338,0x326625202c333238,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323338,0x326625202c343238,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333338,0x326625202c353238,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343338,0x316625202c363238,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353338,0x316625202c373238,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363338,0x316625202c383238,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373338,0x316625202c393238,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383338,0x326625202c303338,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393338,0x326625202c313338,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303438,0x326625202c323338,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313438,0x326625202c333338,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323438,0x316625202c343338,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333438,0x316625202c353338,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343438,0x316625202c363338,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353438,0x316625202c373338,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363438,0x326625202c383338,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373438,0x326625202c393338,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383438,0x326625202c303438,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393438,0x326625202c313438,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303538,0x316625202c323438,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313538,0x316625202c333438,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323538,0x316625202c343438,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333538,0x316625202c353438,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343538,0x326625202c363438,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353538,0x326625202c373438,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363538,0x326625202c383438,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373538,0x326625202c393438,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383538,0x316625202c303538,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393538,0x316625202c313538,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303638,0x316625202c323538,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313638,0x316625202c333538,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323638,0x326625202c343538,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333638,0x326625202c353538,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343638,0x326625202c363538,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353638,0x326625202c373538,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363638,0x316625202c383538,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373638,0x316625202c393538,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383638,0x316625202c303638,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393638,0x316625202c313638,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303738,0x326625202c323638,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313738,0x326625202c333638,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323738,0x326625202c343638,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333738,0x326625202c353638,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343738,0x316625202c363638,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353738,0x316625202c373638,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363738,0x316625202c383638,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373738,0x316625202c393638,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383738,0x326625202c303738,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393738,0x326625202c313738,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303838,0x326625202c323738,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313838,0x326625202c333738,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323838,0x316625202c343738,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333838,0x316625202c353738,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343838,0x316625202c363738,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353838,0x316625202c373738,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363838,0x326625202c383738,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373838,0x326625202c393738,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383838,0x326625202c303838,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393838,0x326625202c313838,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303938,0x316625202c323838,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313938,0x316625202c333838,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323938,0x316625202c343838,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333938,0x316625202c353838,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343938,0x326625202c363838,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353938,0x326625202c373838,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363938,0x326625202c383838,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373938,0x326625202c393838,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383938,0x316625202c303938,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393938,0x316625202c313938,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303039,0x316625202c323938,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313039,0x316625202c333938,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323039,0x326625202c343938,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333039,0x326625202c353938,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343039,0x326625202c363938,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353039,0x326625202c373938,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363039,0x316625202c383938,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373039,0x316625202c393938,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383039,0x316625202c303039,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393039,0x316625202c313039,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303139,0x326625202c323039,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313139,0x326625202c333039,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323139,0x326625202c343039,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333139,0x326625202c353039,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343139,0x316625202c363039,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353139,0x316625202c373039,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363139,0x316625202c383039,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373139,0x316625202c393039,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383139,0x326625202c303139,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393139,0x326625202c313139,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303239,0x326625202c323139,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313239,0x326625202c333139,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323239,0x316625202c343139,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333239,0x316625202c353139,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343239,0x316625202c363139,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353239,0x316625202c373139,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363239,0x326625202c383139,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373239,0x326625202c393139,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383239,0x326625202c303239,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393239,0x326625202c313239,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303339,0x316625202c323239,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313339,0x316625202c333239,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323339,0x316625202c343239,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333339,0x316625202c353239,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343339,0x326625202c363239,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353339,0x326625202c373239,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363339,0x326625202c383239,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373339,0x326625202c393239,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383339,0x316625202c303339,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393339,0x316625202c313339,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303439,0x316625202c323339,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313439,0x316625202c333339,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323439,0x326625202c343339,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333439,0x326625202c353339,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343439,0x326625202c363339,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353439,0x326625202c373339,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363439,0x316625202c383339,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373439,0x316625202c393339,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383439,0x316625202c303439,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393439,0x316625202c313439,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303539,0x326625202c323439,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313539,0x326625202c333439,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323539,0x326625202c343439,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333539,0x326625202c353439,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343539,0x316625202c363439,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353539,0x316625202c373439,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363539,0x316625202c383439,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373539,0x316625202c393439,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383539,0x326625202c303539,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393539,0x326625202c313539,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c303639,0x326625202c323539,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c313639,0x326625202c333539,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c323639,0x316625202c343539,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c333639,0x316625202c353539,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c343639,0x316625202c363539,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c353639,0x316625202c373539,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c363639,0x326625202c383539,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c373639,0x326625202c393539,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c383639,0x326625202c303639,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c393639,0x326625202c313639,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c303739,0x316625202c323639,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c313739,0x316625202c333639,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c323739,0x316625202c343639,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c333739,0x316625202c353639,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c343739,0x326625202c363639,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c353739,0x326625202c373639,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c363739,0x326625202c383639,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c373739,0x326625202c393639,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c383739,0x316625202c303739,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c393739,0x316625202c313739,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c303839,0x316625202c323739,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c313839,0x316625202c333739,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c323839,0x326625202c343739,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c333839,0x326625202c353739,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c343839,0x326625202c363739,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c353839,0x326625202c373739,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c363839,0x316625202c383739,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c373839,0x316625202c393739,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c383839,0x316625202c303839,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c393839,0x316625202c313839,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c303939,0x326625202c323839,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c313939,0x326625202c333839,0x2e6c756d090a3b31,0x3366250920323366\n"
".quad 0x336625202c323939,0x326625202c343839,0x2e646461090a3b30,0x3366250920323366\n"
".quad 0x336625202c333939,0x326625202c353839,0x2e6c756d090a3b30,0x3366250920323366\n"
".quad 0x336625202c343939,0x316625202c363839,0x2e646461090a3b39,0x3366250920323366\n"
".quad 0x336625202c353939,0x316625202c373839,0x2e6c756d090a3b39,0x3366250920323366\n"
".quad 0x336625202c363939,0x316625202c383839,0x2e646461090a3b38,0x3366250920323366\n"
".quad 0x336625202c373939,0x316625202c393839,0x2e6c756d090a3b38,0x3366250920323366\n"
".quad 0x336625202c383939,0x326625202c303939,0x2e646461090a3b31,0x3366250920323366\n"
".quad 0x336625202c393939,0x326625202c313939,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x336625202c303030,0x326625202c323939,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x336625202c313030,0x326625202c333939,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x336625202c323030,0x316625202c343939,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x336625202c333030,0x316625202c353939,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x336625202c343030,0x316625202c363939,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x336625202c353030,0x316625202c373939,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x336625202c363030,0x326625202c383939,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x336625202c373030,0x326625202c393939,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c383030,0x326625202c303030,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c393030,0x326625202c313030,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c303130,0x316625202c323030,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c313130,0x316625202c333030,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c323130,0x316625202c343030,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c333130,0x316625202c353030,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c343130,0x326625202c363030,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c353130,0x326625202c373030,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c363130,0x326625202c383030,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c373130,0x326625202c393030,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c383130,0x316625202c303130,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c393130,0x316625202c313130,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c303230,0x316625202c323130,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c313230,0x316625202c333130,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c323230,0x326625202c343130,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c333230,0x326625202c353130,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c343230,0x326625202c363130,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c353230,0x326625202c373130,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c363230,0x316625202c383130,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c373230,0x316625202c393130,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c383230,0x316625202c303230,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c393230,0x316625202c313230,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c303330,0x326625202c323230,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c313330,0x326625202c333230,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c323330,0x326625202c343230,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c333330,0x326625202c353230,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c343330,0x316625202c363230,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c353330,0x316625202c373230,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c363330,0x316625202c383230,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c373330,0x316625202c393230,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c383330,0x326625202c303330,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c393330,0x326625202c313330,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c303430,0x326625202c323330,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c313430,0x326625202c333330,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c323430,0x316625202c343330,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c333430,0x316625202c353330,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c343430,0x316625202c363330,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c353430,0x316625202c373330,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c363430,0x326625202c383330,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c373430,0x326625202c393330,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c383430,0x326625202c303430,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c393430,0x326625202c313430,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c303530,0x316625202c323430,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c313530,0x316625202c333430,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c323530,0x316625202c343430,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c333530,0x316625202c353430,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c343530,0x326625202c363430,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c353530,0x326625202c373430,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c363530,0x326625202c383430,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c373530,0x326625202c393430,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c383530,0x316625202c303530,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c393530,0x316625202c313530,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c303630,0x316625202c323530,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c313630,0x316625202c333530,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c323630,0x326625202c343530,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c333630,0x326625202c353530,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c343630,0x326625202c363530,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c353630,0x326625202c373530,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c363630,0x316625202c383530,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c373630,0x316625202c393530,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c383630,0x316625202c303630,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c393630,0x316625202c313630,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c303730,0x326625202c323630,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c313730,0x326625202c333630,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c323730,0x326625202c343630,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c333730,0x326625202c353630,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c343730,0x316625202c363630,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c353730,0x316625202c373630,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c363730,0x316625202c383630,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c373730,0x316625202c393630,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c383730,0x326625202c303730,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c393730,0x326625202c313730,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c303830,0x326625202c323730,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c313830,0x326625202c333730,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c323830,0x316625202c343730,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c333830,0x316625202c353730,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c343830,0x316625202c363730,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c353830,0x316625202c373730,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c363830,0x326625202c383730,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c373830,0x326625202c393730,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c383830,0x326625202c303830,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c393830,0x326625202c313830,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c303930,0x316625202c323830,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c313930,0x316625202c333830,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c323930,0x316625202c343830,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c333930,0x316625202c353830,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c343930,0x326625202c363830,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c353930,0x326625202c373830,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c363930,0x326625202c383830,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c373930,0x326625202c393830,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c383930,0x316625202c303930,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c393930,0x316625202c313930,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c303031,0x316625202c323930,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c313031,0x316625202c333930,0x2e6c756d090a3b38,0x3466250920323366\n"
".quad 0x346625202c323031,0x326625202c343930,0x2e646461090a3b31,0x3466250920323366\n"
".quad 0x346625202c333031,0x326625202c353930,0x2e6c756d090a3b31,0x3466250920323366\n"
".quad 0x346625202c343031,0x326625202c363930,0x2e646461090a3b30,0x3466250920323366\n"
".quad 0x346625202c353031,0x326625202c373930,0x2e6c756d090a3b30,0x3466250920323366\n"
".quad 0x346625202c363031,0x316625202c383930,0x2e646461090a3b39,0x3466250920323366\n"
".quad 0x346625202c373031,0x316625202c393930,0x2e6c756d090a3b39,0x3466250920323366\n"
".quad 0x346625202c383031,0x316625202c303031,0x2e646461090a3b38,0x3466250920323366\n"
".quad 0x346625202c393031,0x316625202c313031,0x2e6c756d090a3b38,0x3166250920323366\n"
".quad 0x3031346625202c33,0x3b31326625202c32,0x33662e646461090a,0x202c346625092032\n"
".quad 0x202c333031346625,0x6d090a3b31326625,0x09203233662e6c75,0x6625202c35316625\n"
".quad 0x6625202c34303134,0x646461090a3b3032,0x662509203233662e,0x3031346625202c37\n"
".quad 0x3b30326625202c35,0x33662e6c756d090a,0x2c36316625092032,0x2c36303134662520\n"
".quad 0x090a3b3931662520,0x203233662e646461,0x6625202c39662509,0x6625202c37303134\n"
".quad 0x6c756d090a3b3931,0x662509203233662e,0x31346625202c3731,0x38316625202c3830\n"
".quad 0x662e646461090a3b,0x3231662509203233,0x393031346625202c,0x0a3b38316625202c\n"
".quad 0x3233732e64646109,0x25202c3472250920,0x090a3b31202c3472,0x203233752e766f6d\n"
".quad 0x3031202c35722509,0x746573090a3b3432,0x3233732e656e2e70,0x25202c3170250920\n"
".quad 0x3b357225202c3472,0x622031702540090a,0x5f744c2409206172,0x0a3b323635325f30\n"
".quad 0x617261702e646c09,0x7225092038732e6d,0x75635f5f5b202c36,0x465f6d7261706164\n"
".quad 0x706d6f4374616f6c,0x646e756f42657475,0x3b5d65726f74735f,0x33752e766f6d090a\n"
".quad 0x202c377225092032,0x70746573090a3b30,0x203233732e71652e,0x7225202c32702509\n"
".quad 0x0a3b377225202c36,0x7262203270254009,0x305f744c24092061,0x090a3b343730335f\n"
".quad 0x09383209636f6c2e,0x7573090a30093235,0x2509203233662e62,0x25202c3031313466\n"
".quad 0x346625202c333166,0x662e646461090a3b,0x3134662509203233,0x35316625202c3131\n"
".quad 0x303131346625202c,0x662e627573090a3b,0x3134662509203233,0x31346625202c3231\n"
".quad 0x3b376625202c3131,0x33662e646461090a,0x3131346625092032,0x2c36316625202c33\n"
".quad 0x3b32313134662520,0x33662e627573090a,0x3131346625092032,0x3131346625202c34\n"
".quad 0x0a3b396625202c33,0x3233662e64646109,0x3531313466250920,0x202c37316625202c\n"
".quad 0x0a3b343131346625,0x3233662e62757309,0x3631313466250920,0x353131346625202c\n"
".quad 0x0a3b32316625202c,0x626f6c672e747309,0x09203233662e6c61,0x5d302b346472255b\n"
".quad 0x363131346625202c,0x5f305f744c240a3b,0x2e090a3a34373033,0x3509383209636f6c\n"
".quad 0x697865090a300934,0x6557444c240a3b74,0x74616f6c465f646e,0x42657475706d6f43\n"
".quad 0x7d090a3a646e756f,0x616f6c46202f2f20,0x657475706d6f4374,0x000a0a646e756f42\n"
".text");

extern "C" {

extern const unsigned long long __deviceText_$compute_10$[16752];

}

static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_10",(char*)__deviceText_$compute_10$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries1 = {(char*)"sm_10", (char*)__deviceText_$sm_10$, &__elfEntries0, (unsigned int)sizeof(__deviceText_$sm_10$)};



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"4df47a52efc98f98",(char*)"ComputeBound.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x7b6f7648,&__elfEntries1};
# 2 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c" 2
# 1 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 1
# 93 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h"
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

# 1 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h" 1
# 87 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 1 3
# 948 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/math_constants.h" 1 3
# 949 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 2 3
# 2969 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/crt/func_macro.h" 1 3
# 2970 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 2 3
# 4679 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 3
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
# 4996 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda3.1/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 4997 "/usr/local/cuda3.1/cuda/bin/../include/math_functions.h" 2 3
# 88 "/usr/local/cuda3.1/cuda/bin/../include/common_functions.h" 2
# 166 "/usr/local/cuda3.1/cuda/bin/../include/crt/host_runtime.h" 2
# 3 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c" 2
struct __T20 {float *__par0;float __par1;float __par2;float __par3;float __par4;float __par5;char __par6;int __dummy_field;};
extern void __device_stub__Z17FloatComputeBoundPffffffb(float *, const float, const float, const float, const float, const float, bool);
static void __sti____cudaRegisterAll_47_tmpxft_0000092c_00000000_4_ComputeBound_cpp1_ii_86ff985c(void) __attribute__((__constructor__));
void __device_stub__Z17FloatComputeBoundPffffffb(float *__par0, const float __par1, const float __par2, const float __par3, const float __par4, const float __par5, bool __par6){ struct __T20 *__T21;
*(void**)(void*)&__T21 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T21->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T21->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T21->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T21->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T21->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T21->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T21->__par6) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(float *, const float, const float, const float, const float, const float, bool))FloatComputeBound)); (void)cudaLaunch(((char *)((void ( *)(float *, const float, const float, const float, const float, const float, bool))FloatComputeBound))); };}
void FloatComputeBound( float *__cuda_0,const float __cuda_1,const float __cuda_2,const float __cuda_3,const float __cuda_4,const float __cuda_5,bool __cuda_6)
# 32 "ComputeBound.cu"
{__device_stub__Z17FloatComputeBoundPffffffb( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);
# 54 "ComputeBound.cu"
}
# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c"
static void __sti____cudaRegisterAll_47_tmpxft_0000092c_00000000_4_ComputeBound_cpp1_ii_86ff985c(void) { __cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil); __cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(float *, const float, const float, const float, const float, const float, bool))FloatComputeBound), (char*)"FloatComputeBound", "FloatComputeBound", -1, (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0); }
# 1 "/tmp/tmpxft_0000092c_00000000-1_ComputeBound.cudafe1.stub.c" 2
